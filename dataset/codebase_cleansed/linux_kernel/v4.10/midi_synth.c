void
do_midi_msg(int synthno, unsigned char *msg, int mlen)
{
switch (msg[0] & 0xf0)
{
case 0x90:
if (msg[2] != 0)
{
STORE(SEQ_START_NOTE(synthno, msg[0] & 0x0f, msg[1], msg[2]));
break;
}
msg[2] = 64;
case 0x80:
STORE(SEQ_STOP_NOTE(synthno, msg[0] & 0x0f, msg[1], msg[2]));
break;
case 0xA0:
STORE(SEQ_KEY_PRESSURE(synthno, msg[0] & 0x0f, msg[1], msg[2]));
break;
case 0xB0:
STORE(SEQ_CONTROL(synthno, msg[0] & 0x0f,
msg[1], msg[2]));
break;
case 0xC0:
STORE(SEQ_SET_PATCH(synthno, msg[0] & 0x0f, msg[1]));
break;
case 0xD0:
STORE(SEQ_CHN_PRESSURE(synthno, msg[0] & 0x0f, msg[1]));
break;
case 0xE0:
STORE(SEQ_BENDER(synthno, msg[0] & 0x0f,
(msg[1] & 0x7f) | ((msg[2] & 0x7f) << 7)));
break;
default:
;
}
}
static void
midi_outc(int midi_dev, int data)
{
int timeout;
for (timeout = 0; timeout < 3200; timeout++)
if (midi_devs[midi_dev]->outputc(midi_dev, (unsigned char) (data & 0xff)))
{
if (data & 0x80)
prev_out_status[midi_dev] =
(unsigned char) (data & 0xff);
return;
}
printk("Midi send timed out\n");
}
static int
prefix_cmd(int midi_dev, unsigned char status)
{
if ((char *) midi_devs[midi_dev]->prefix_cmd == NULL)
return 1;
return midi_devs[midi_dev]->prefix_cmd(midi_dev, status);
}
static void
midi_synth_input(int orig_dev, unsigned char data)
{
int dev;
struct midi_input_info *inc;
static unsigned char len_tab[] =
{
2,
2,
2,
2,
1,
1,
2,
0
};
if (orig_dev < 0 || orig_dev > num_midis || midi_devs[orig_dev] == NULL)
return;
if (data == 0xfe)
return;
dev = midi2synth[orig_dev];
inc = &midi_devs[orig_dev]->in_info;
switch (inc->m_state)
{
case MST_INIT:
if (data & 0x80)
{
if ((data & 0xf0) == 0xf0)
{
switch (data)
{
case 0xf0:
inc->m_state = MST_SYSEX;
break;
case 0xf1:
case 0xf3:
inc->m_state = MST_DATA;
inc->m_ptr = 1;
inc->m_left = 1;
inc->m_buf[0] = data;
break;
case 0xf2:
inc->m_state = MST_DATA;
inc->m_ptr = 1;
inc->m_left = 2;
inc->m_buf[0] = data;
break;
default:
inc->m_buf[0] = data;
inc->m_ptr = 1;
do_midi_msg(dev, inc->m_buf, inc->m_ptr);
inc->m_ptr = 0;
inc->m_left = 0;
}
} else
{
inc->m_state = MST_DATA;
inc->m_ptr = 1;
inc->m_left = len_tab[(data >> 4) - 8];
inc->m_buf[0] = inc->m_prev_status = data;
}
} else if (inc->m_prev_status & 0x80) {
inc->m_ptr = 2;
inc->m_buf[1] = data;
inc->m_buf[0] = inc->m_prev_status;
inc->m_left = len_tab[(inc->m_buf[0] >> 4) - 8] - 1;
if (inc->m_left > 0)
inc->m_state = MST_DATA;
else {
inc->m_state = MST_INIT;
do_midi_msg(dev, inc->m_buf, inc->m_ptr);
inc->m_ptr = 0;
}
}
break;
case MST_DATA:
inc->m_buf[inc->m_ptr++] = data;
if (--inc->m_left <= 0)
{
inc->m_state = MST_INIT;
do_midi_msg(dev, inc->m_buf, inc->m_ptr);
inc->m_ptr = 0;
}
break;
case MST_SYSEX:
if (data == 0xf7)
{
inc->m_state = MST_INIT;
inc->m_left = 0;
inc->m_ptr = 0;
}
break;
default:
printk("MIDI%d: Unexpected state %d (%02x)\n", orig_dev, inc->m_state, (int) data);
inc->m_state = MST_INIT;
}
}
static void
leave_sysex(int dev)
{
int orig_dev = synth_devs[dev]->midi_dev;
int timeout = 0;
if (!sysex_state[dev])
return;
sysex_state[dev] = 0;
while (!midi_devs[orig_dev]->outputc(orig_dev, 0xf7) &&
timeout < 1000)
timeout++;
sysex_state[dev] = 0;
}
static void
midi_synth_output(int dev)
{
}
int midi_synth_ioctl(int dev, unsigned int cmd, void __user *arg)
{
switch (cmd) {
case SNDCTL_SYNTH_INFO:
if (__copy_to_user(arg, synth_devs[dev]->info, sizeof(struct synth_info)))
return -EFAULT;
return 0;
case SNDCTL_SYNTH_MEMAVL:
return 0x7fffffff;
default:
return -EINVAL;
}
}
int
midi_synth_kill_note(int dev, int channel, int note, int velocity)
{
int orig_dev = synth_devs[dev]->midi_dev;
int msg, chn;
if (note < 0 || note > 127)
return 0;
if (channel < 0 || channel > 15)
return 0;
if (velocity < 0)
velocity = 0;
if (velocity > 127)
velocity = 127;
leave_sysex(dev);
msg = prev_out_status[orig_dev] & 0xf0;
chn = prev_out_status[orig_dev] & 0x0f;
if (chn == channel && ((msg == 0x90 && velocity == 64) || msg == 0x80))
{
if (!prefix_cmd(orig_dev, note))
return 0;
midi_outc(orig_dev, note);
if (msg == 0x90)
midi_outc(orig_dev, 0);
else
midi_outc(orig_dev, velocity);
} else
{
if (velocity == 64)
{
if (!prefix_cmd(orig_dev, 0x90 | (channel & 0x0f)))
return 0;
midi_outc(orig_dev, 0x90 | (channel & 0x0f));
midi_outc(orig_dev, note);
midi_outc(orig_dev, 0);
} else
{
if (!prefix_cmd(orig_dev, 0x80 | (channel & 0x0f)))
return 0;
midi_outc(orig_dev, 0x80 | (channel & 0x0f));
midi_outc(orig_dev, note);
midi_outc(orig_dev, velocity);
}
}
return 0;
}
int
midi_synth_set_instr(int dev, int channel, int instr_no)
{
int orig_dev = synth_devs[dev]->midi_dev;
if (instr_no < 0 || instr_no > 127)
instr_no = 0;
if (channel < 0 || channel > 15)
return 0;
leave_sysex(dev);
if (!prefix_cmd(orig_dev, 0xc0 | (channel & 0x0f)))
return 0;
midi_outc(orig_dev, 0xc0 | (channel & 0x0f));
midi_outc(orig_dev, instr_no);
return 0;
}
int
midi_synth_start_note(int dev, int channel, int note, int velocity)
{
int orig_dev = synth_devs[dev]->midi_dev;
int msg, chn;
if (note < 0 || note > 127)
return 0;
if (channel < 0 || channel > 15)
return 0;
if (velocity < 0)
velocity = 0;
if (velocity > 127)
velocity = 127;
leave_sysex(dev);
msg = prev_out_status[orig_dev] & 0xf0;
chn = prev_out_status[orig_dev] & 0x0f;
if (chn == channel && msg == 0x90)
{
if (!prefix_cmd(orig_dev, note))
return 0;
midi_outc(orig_dev, note);
midi_outc(orig_dev, velocity);
} else
{
if (!prefix_cmd(orig_dev, 0x90 | (channel & 0x0f)))
return 0;
midi_outc(orig_dev, 0x90 | (channel & 0x0f));
midi_outc(orig_dev, note);
midi_outc(orig_dev, velocity);
}
return 0;
}
void
midi_synth_reset(int dev)
{
leave_sysex(dev);
}
int
midi_synth_open(int dev, int mode)
{
int orig_dev = synth_devs[dev]->midi_dev;
int err;
struct midi_input_info *inc;
if (orig_dev < 0 || orig_dev >= num_midis || midi_devs[orig_dev] == NULL)
return -ENXIO;
midi2synth[orig_dev] = dev;
sysex_state[dev] = 0;
prev_out_status[orig_dev] = 0;
if ((err = midi_devs[orig_dev]->open(orig_dev, mode,
midi_synth_input, midi_synth_output)) < 0)
return err;
inc = &midi_devs[orig_dev]->in_info;
inc->m_busy = 0;
inc->m_state = MST_INIT;
inc->m_ptr = 0;
inc->m_left = 0;
inc->m_prev_status = 0x00;
return 1;
}
void
midi_synth_close(int dev)
{
int orig_dev = synth_devs[dev]->midi_dev;
leave_sysex(dev);
midi_devs[orig_dev]->outputc(orig_dev, 0xfe);
midi_devs[orig_dev]->close(orig_dev);
}
void
midi_synth_hw_control(int dev, unsigned char *event)
{
}
int
midi_synth_load_patch(int dev, int format, const char __user *addr,
int count, int pmgr_flag)
{
int orig_dev = synth_devs[dev]->midi_dev;
struct sysex_info sysex;
int i;
unsigned long left, src_offs, eox_seen = 0;
int first_byte = 1;
int hdr_size = (unsigned long) &sysex.data[0] - (unsigned long) &sysex;
leave_sysex(dev);
if (!prefix_cmd(orig_dev, 0xf0))
return 0;
if (format != SYSEX_PATCH)
return -EINVAL;
if (count < hdr_size)
return -EINVAL;
count -= hdr_size;
if (copy_from_user(&sysex, addr, hdr_size))
return -EFAULT;
if ((unsigned)count < (unsigned)sysex.len)
sysex.len = count;
left = sysex.len;
src_offs = 0;
for (i = 0; i < left && !signal_pending(current); i++)
{
unsigned char data;
if (get_user(data,
(unsigned char __user *)(addr + hdr_size + i)))
return -EFAULT;
eox_seen = (i > 0 && data & 0x80);
if (eox_seen && data != 0xf7)
data = 0xf7;
if (i == 0)
{
if (data != 0xf0)
{
printk(KERN_WARNING "midi_synth: Sysex start missing\n");
return -EINVAL;
}
}
while (!midi_devs[orig_dev]->outputc(orig_dev, (unsigned char) (data & 0xff)) &&
!signal_pending(current))
schedule();
if (!first_byte && data & 0x80)
return 0;
first_byte = 0;
}
if (!eox_seen)
midi_outc(orig_dev, 0xf7);
return 0;
}
void midi_synth_panning(int dev, int channel, int pressure)
{
}
void midi_synth_aftertouch(int dev, int channel, int pressure)
{
int orig_dev = synth_devs[dev]->midi_dev;
int msg, chn;
if (pressure < 0 || pressure > 127)
return;
if (channel < 0 || channel > 15)
return;
leave_sysex(dev);
msg = prev_out_status[orig_dev] & 0xf0;
chn = prev_out_status[orig_dev] & 0x0f;
if (msg != 0xd0 || chn != channel)
{
if (!prefix_cmd(orig_dev, 0xd0 | (channel & 0x0f)))
return;
midi_outc(orig_dev, 0xd0 | (channel & 0x0f));
} else if (!prefix_cmd(orig_dev, pressure))
return;
midi_outc(orig_dev, pressure);
}
void
midi_synth_controller(int dev, int channel, int ctrl_num, int value)
{
int orig_dev = synth_devs[dev]->midi_dev;
int chn, msg;
if (ctrl_num < 0 || ctrl_num > 127)
return;
if (channel < 0 || channel > 15)
return;
leave_sysex(dev);
msg = prev_out_status[orig_dev] & 0xf0;
chn = prev_out_status[orig_dev] & 0x0f;
if (msg != 0xb0 || chn != channel)
{
if (!prefix_cmd(orig_dev, 0xb0 | (channel & 0x0f)))
return;
midi_outc(orig_dev, 0xb0 | (channel & 0x0f));
} else if (!prefix_cmd(orig_dev, ctrl_num))
return;
midi_outc(orig_dev, ctrl_num);
midi_outc(orig_dev, value & 0x7f);
}
void
midi_synth_bender(int dev, int channel, int value)
{
int orig_dev = synth_devs[dev]->midi_dev;
int msg, prev_chn;
if (channel < 0 || channel > 15)
return;
if (value < 0 || value > 16383)
return;
leave_sysex(dev);
msg = prev_out_status[orig_dev] & 0xf0;
prev_chn = prev_out_status[orig_dev] & 0x0f;
if (msg != 0xd0 || prev_chn != channel)
{
if (!prefix_cmd(orig_dev, 0xe0 | (channel & 0x0f)))
return;
midi_outc(orig_dev, 0xe0 | (channel & 0x0f));
} else if (!prefix_cmd(orig_dev, value & 0x7f))
return;
midi_outc(orig_dev, value & 0x7f);
midi_outc(orig_dev, (value >> 7) & 0x7f);
}
void
midi_synth_setup_voice(int dev, int voice, int channel)
{
}
int
midi_synth_send_sysex(int dev, unsigned char *bytes, int len)
{
int orig_dev = synth_devs[dev]->midi_dev;
int i;
for (i = 0; i < len; i++)
{
switch (bytes[i])
{
case 0xf0:
if (!prefix_cmd(orig_dev, 0xf0))
return 0;
sysex_state[dev] = 1;
break;
case 0xf7:
if (!sysex_state[dev])
return 0;
sysex_state[dev] = 0;
break;
default:
if (!sysex_state[dev])
return 0;
if (bytes[i] & 0x80)
{
bytes[i] = 0xf7;
sysex_state[dev] = 0;
}
}
if (!midi_devs[orig_dev]->outputc(orig_dev, bytes[i]))
{
int timeout = 0;
bytes[i] = 0xf7;
sysex_state[dev] = 0;
while (!midi_devs[orig_dev]->outputc(orig_dev, bytes[i]) &&
timeout < 1000)
timeout++;
}
if (!sysex_state[dev])
return 0;
}
return 0;
}
