int
mpa_version(const struct mpa *mpa)
{
return mpa_versions[mpa->version];
}
int
mpa_layer(const struct mpa *mpa)
{
return mpa_layers[mpa->layer];
}
unsigned
mpa_samples(const struct mpa *mpa)
{
return mpa_samples_data[mpa_versions[mpa->version]][mpa_layer(mpa)];
}
unsigned
mpa_bitrate(const struct mpa *mpa)
{
return (1000 * (mpa_bitrates[mpa_versions[mpa->version]][mpa_layers[mpa->layer]][mpa->bitrate]));
}
unsigned
mpa_frequency(const struct mpa *mpa)
{
return(mpa_frequencies[mpa_versions[mpa->version]][mpa->frequency]);
}
unsigned
mpa_padding(const struct mpa *mpa)
{
return(mpa->padding ? mpa_padding_data[mpa_layers[mpa->layer]] : 0);
}
