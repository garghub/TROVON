gint init_tlv_info(tlv_info_t *this, tvbuff_t *tvb, gint offset)
{
guint tlv_len;
this->type = (guint8)tvb_get_guint8( tvb, offset );
tlv_len = (guint)tvb_get_guint8( tvb, (offset + 1) );
this->value_offset = 2;
if((tlv_len & WIMAX_TLV_EXTENDED_LENGTH_MASK) != 0)
{
this->length_type = 1;
tlv_len = (tlv_len & WIMAX_TLV_LENGTH_MASK);
this->size_of_length = tlv_len;
this->value_offset += tlv_len;
switch (tlv_len)
{
case 0:
this->length = 0;
break;
case 1:
this->length = (gint32)tvb_get_guint8( tvb, (offset + 2) );
break;
case 2:
this->length = (gint32)tvb_get_ntohs( tvb, (offset + 2) );
break;
case 3:
this->length = (gint32)tvb_get_ntoh24( tvb, (offset + 2) );
break;
case 4:
this->length = (gint32)tvb_get_ntohl( tvb, (offset + 2) );
break;
default:
this->valid = 0;
return (gint)tlv_len;
break;
}
}
else
{
this->length_type = 0;
this->size_of_length = 0;
this->length = (gint32)tlv_len;
}
this->valid = 1;
return 0;
}
gint get_tlv_type(tlv_info_t *this)
{
if(this->valid)
return (gint)this->type;
return -1;
}
gint get_tlv_size_of_length(tlv_info_t *this)
{
if(this->valid)
return (gint)this->size_of_length;
return -1;
}
gint32 get_tlv_length(tlv_info_t *this)
{
if(this->valid)
return (gint32)this->length;
return -1;
}
gint get_tlv_value_offset(tlv_info_t *this)
{
if(this->valid)
return (gint)this->value_offset;
return -1;
}
gint get_tlv_length_type(tlv_info_t *this)
{
if(this->valid)
return (gint)this->length_type;
return -1;
}
