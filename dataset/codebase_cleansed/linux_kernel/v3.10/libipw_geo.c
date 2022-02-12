int libipw_is_valid_channel(struct libipw_device *ieee, u8 channel)
{
int i;
if (ieee->geo.bg_channels == 0 && ieee->geo.a_channels == 0)
return 0;
if (ieee->freq_band & LIBIPW_24GHZ_BAND)
for (i = 0; i < ieee->geo.bg_channels; i++)
if ((ieee->geo.bg[i].channel == channel) &&
!(ieee->geo.bg[i].flags & LIBIPW_CH_INVALID) &&
(!(ieee->mode & IEEE_G) ||
!(ieee->geo.bg[i].flags & LIBIPW_CH_B_ONLY)))
return LIBIPW_24GHZ_BAND;
if (ieee->freq_band & LIBIPW_52GHZ_BAND)
for (i = 0; i < ieee->geo.a_channels; i++)
if ((ieee->geo.a[i].channel == channel) &&
!(ieee->geo.a[i].flags & LIBIPW_CH_INVALID))
return LIBIPW_52GHZ_BAND;
return 0;
}
int libipw_channel_to_index(struct libipw_device *ieee, u8 channel)
{
int i;
if (ieee->geo.bg_channels == 0 && ieee->geo.a_channels == 0)
return -1;
if (ieee->freq_band & LIBIPW_24GHZ_BAND)
for (i = 0; i < ieee->geo.bg_channels; i++)
if (ieee->geo.bg[i].channel == channel)
return i;
if (ieee->freq_band & LIBIPW_52GHZ_BAND)
for (i = 0; i < ieee->geo.a_channels; i++)
if (ieee->geo.a[i].channel == channel)
return i;
return -1;
}
u32 libipw_channel_to_freq(struct libipw_device * ieee, u8 channel)
{
const struct libipw_channel * ch;
if (ieee->geo.bg_channels == 0 && ieee->geo.a_channels == 0)
return 0;
ch = libipw_get_channel(ieee, channel);
if (!ch->channel)
return 0;
return ch->freq;
}
u8 libipw_freq_to_channel(struct libipw_device * ieee, u32 freq)
{
int i;
if (ieee->geo.bg_channels == 0 && ieee->geo.a_channels == 0)
return 0;
freq /= 100000;
if (ieee->freq_band & LIBIPW_24GHZ_BAND)
for (i = 0; i < ieee->geo.bg_channels; i++)
if (ieee->geo.bg[i].freq == freq)
return ieee->geo.bg[i].channel;
if (ieee->freq_band & LIBIPW_52GHZ_BAND)
for (i = 0; i < ieee->geo.a_channels; i++)
if (ieee->geo.a[i].freq == freq)
return ieee->geo.a[i].channel;
return 0;
}
void libipw_set_geo(struct libipw_device *ieee,
const struct libipw_geo *geo)
{
memcpy(ieee->geo.name, geo->name, 3);
ieee->geo.name[3] = '\0';
ieee->geo.bg_channels = geo->bg_channels;
ieee->geo.a_channels = geo->a_channels;
memcpy(ieee->geo.bg, geo->bg, geo->bg_channels *
sizeof(struct libipw_channel));
memcpy(ieee->geo.a, geo->a, ieee->geo.a_channels *
sizeof(struct libipw_channel));
}
const struct libipw_geo *libipw_get_geo(struct libipw_device *ieee)
{
return &ieee->geo;
}
u8 libipw_get_channel_flags(struct libipw_device * ieee, u8 channel)
{
int index = libipw_channel_to_index(ieee, channel);
if (index == -1)
return LIBIPW_CH_INVALID;
if (channel <= LIBIPW_24GHZ_CHANNELS)
return ieee->geo.bg[index].flags;
return ieee->geo.a[index].flags;
}
const struct libipw_channel *libipw_get_channel(struct libipw_device
*ieee, u8 channel)
{
int index = libipw_channel_to_index(ieee, channel);
if (index == -1)
return &bad_channel;
if (channel <= LIBIPW_24GHZ_CHANNELS)
return &ieee->geo.bg[index];
return &ieee->geo.a[index];
}
