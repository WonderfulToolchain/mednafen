
#ifndef _RENDER_H_
#define _RENDER_H_

namespace MDFN_IEN_SMS
{

/* Used for blanking a line in whole or in part */
#define BACKDROP_COLOR      (0x10 | (vdp.reg[7] & 0x0F))

MDFN_HIDE extern void (*render_bg)(int line);
MDFN_HIDE extern void (*render_obj)(int line);
MDFN_HIDE extern uint8 *linebuf;
MDFN_HIDE extern uint8 internal_buffer[0x100];
MDFN_HIDE extern uint32 pixel[];
MDFN_HIDE extern uint8 bg_name_dirty[0x200];     
MDFN_HIDE extern uint16 bg_name_list[0x200];     
MDFN_HIDE extern uint16 bg_list_index;           
MDFN_HIDE extern uint8 bg_pattern_cache[0x20000];
MDFN_HIDE extern uint8 tms_lookup[16][256][2];
MDFN_HIDE extern uint8 mc_lookup[16][256][8];
MDFN_HIDE extern uint8 txt_lookup[256][2];
MDFN_HIDE extern uint8 bp_expand[256][8];
MDFN_HIDE extern uint8 lut[0x10000];
MDFN_HIDE extern uint32 bp_lut[0x10000];

void render_shutdown(void);
void render_init(void);
void render_reset(void);
void render_line(int line, int skip);
void render_bg_sms(int line);
void render_obj_sms(int line);
void update_bg_pattern_cache(void);
void palette_sync(int index, int force);

}

#endif /* _RENDER_H_ */
