gint init_tlv_info(tlv_info_t *info, tvbuff_t *tvb, gint offset)
{
guint tlv_len;
info->type = (guint8)tvb_get_guint8( tvb, offset );
tlv_len = (guint)tvb_get_guint8( tvb, (offset + 1) );
info->value_offset = 2;
if((tlv_len & WIMAX_TLV_EXTENDED_LENGTH_MASK) != 0)
{
info->length_type = 1;
tlv_len = (tlv_len & WIMAX_TLV_LENGTH_MASK);
info->size_of_length = tlv_len;
info->value_offset += tlv_len;
switch (tlv_len)
{
case 0:
info->length = 0;
break;
case 1:
info->length = (gint32)tvb_get_guint8( tvb, (offset + 2) );
break;
case 2:
info->length = (gint32)tvb_get_ntohs( tvb, (offset + 2) );
break;
case 3:
info->length = (gint32)tvb_get_ntoh24( tvb, (offset + 2) );
break;
case 4:
info->length = (gint32)tvb_get_ntohl( tvb, (offset + 2) );
break;
default:
info->valid = 0;
return (gint)tlv_len;
break;
}
}
else
{
info->length_type = 0;
info->size_of_length = 0;
info->length = (gint32)tlv_len;
}
info->valid = 1;
return 0;
}
gint get_tlv_type(tlv_info_t *info)
{
if(info->valid)
return (gint)info->type;
return -1;
}
gint get_tlv_size_of_length(tlv_info_t *info)
{
if(info->valid)
return (gint)info->size_of_length;
return -1;
}
gint32 get_tlv_length(tlv_info_t *info)
{
if(info->valid)
return (gint32)info->length;
return -1;
}
gint get_tlv_value_offset(tlv_info_t *info)
{
if(info->valid)
return (gint)info->value_offset;
return -1;
}
gint get_tlv_length_type(tlv_info_t *info)
{
if(info->valid)
return (gint)info->length_type;
return -1;
}
