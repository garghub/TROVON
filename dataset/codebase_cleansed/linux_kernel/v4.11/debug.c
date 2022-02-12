const char *sctp_cname(const sctp_subtype_t cid)
{
if (cid.chunk <= SCTP_CID_BASE_MAX)
return sctp_cid_tbl[cid.chunk];
switch (cid.chunk) {
case SCTP_CID_ASCONF:
return "ASCONF";
case SCTP_CID_ASCONF_ACK:
return "ASCONF_ACK";
case SCTP_CID_FWD_TSN:
return "FWD_TSN";
case SCTP_CID_AUTH:
return "AUTH";
default:
break;
}
return "unknown chunk";
}
const char *sctp_pname(const sctp_subtype_t id)
{
if (id.primitive <= SCTP_EVENT_PRIMITIVE_MAX)
return sctp_primitive_tbl[id.primitive];
return "unknown_primitive";
}
const char *sctp_oname(const sctp_subtype_t id)
{
if (id.other <= SCTP_EVENT_OTHER_MAX)
return sctp_other_tbl[id.other];
return "unknown 'other' event";
}
const char *sctp_tname(const sctp_subtype_t id)
{
BUILD_BUG_ON(SCTP_EVENT_TIMEOUT_MAX + 1 != ARRAY_SIZE(sctp_timer_tbl));
if (id.timeout < ARRAY_SIZE(sctp_timer_tbl))
return sctp_timer_tbl[id.timeout];
return "unknown_timer";
}
