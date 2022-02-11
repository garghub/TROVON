static T_1 F_1 ( T_2 V_1 )
{
T_2 V_2 = V_1 & V_3 ;
switch( V_1 & V_4 )
{
case V_5 : return ( T_1 ) V_2 * 1000000000 ;
case V_6 : return ( T_1 ) V_2 * 1000000 ;
case V_7 : return ( T_1 ) V_2 * 1000 ;
case V_8 : return V_2 ;
}
return V_1 ;
}
int F_2 ( T_3 * V_9 , int * V_10 , T_4 * * V_11 )
{
T_4 * V_12 ;
T_5 V_13 ;
T_6 V_14 ;
T_7 * V_15 ;
int V_16 ;
V_17 = V_18 ;
if ( ( V_13 = F_3 ( V_9 , V_10 ) ) == - 1 )
return 0 ;
V_12 = ( T_4 * ) F_4 ( V_19 ) ;
V_14 = F_5 ( V_13 ) ;
switch ( ( V_9 -> V_20 = F_6 ( V_9 , V_12 , V_14 ) ) )
{
case V_21 :
V_9 -> V_22 = V_23 ;
break;
case V_24 :
V_9 -> V_22 = V_25 ;
break;
case V_26 :
V_9 -> V_22 = V_27 ;
F_7 ( V_12 ) ;
V_12 = ( T_4 * ) F_4 ( V_28 ) ;
V_14 = F_8 ( V_13 ) ;
break;
default:
* V_10 = V_29 ;
* V_11 = F_9 ( L_1 , V_9 -> V_20 ) ;
F_7 ( V_12 ) ;
return 0 ;
}
if ( ( F_10 ( V_9 -> V_30 , 0 , V_31 , V_10 ) ) == - 1 )
{
* V_10 = F_11 ( V_9 -> V_30 , V_11 ) ;
F_7 ( V_12 ) ;
return 0 ;
}
V_16 = F_12 ( V_12 , V_14 , V_9 -> V_30 ) ;
if ( V_16 != V_14 )
{
* V_10 = F_11 ( V_9 -> V_30 , V_11 ) ;
F_7 ( V_12 ) ;
if ( * V_10 != 0 && * V_10 != V_32 )
return - 1 ;
return 0 ;
}
switch ( V_9 -> V_20 )
{
case V_21 :
V_9 -> V_33 = V_34 ;
V_9 -> V_35 = V_36 ;
break;
case V_24 :
V_9 -> V_33 = V_37 ;
V_9 -> V_35 = V_38 ;
break;
case V_26 :
V_9 -> V_33 = V_39 ;
V_9 -> V_35 = V_40 ;
break;
}
V_9 -> V_41 = V_42 ;
V_15 = ( T_7 * ) F_4 ( sizeof( T_7 ) ) ;
V_9 -> V_43 = ( void * ) V_15 ;
V_15 -> V_44 = V_12 ;
V_15 -> V_45 = 0 ;
V_15 -> V_46 = V_14 ;
V_15 -> V_47 = 0 ;
V_15 -> V_48 = 0 ;
V_15 -> V_49 = 0 ;
V_15 -> V_50 = 0 ;
V_15 -> V_51 = 0 ;
V_15 -> V_13 = V_13 ;
if ( ( F_13 ( V_9 ) ) == FALSE )
{
if ( ( F_10 ( V_9 -> V_30 , 0 , V_31 , V_10 ) ) == - 1 )
{
* V_10 = F_11 ( V_9 -> V_30 , V_11 ) ;
F_7 ( V_15 -> V_44 ) ;
F_7 ( V_15 ) ;
return 0 ;
}
V_16 = F_12 ( V_12 , V_14 , V_9 -> V_30 ) ;
if ( V_16 != V_14 )
{
* V_10 = F_11 ( V_9 -> V_30 , V_11 ) ;
F_7 ( V_15 -> V_44 ) ;
F_7 ( V_15 ) ;
return 0 ;
}
V_15 -> V_47 = 0 ;
}
V_9 -> V_52 = V_53 ;
V_9 -> V_54 . V_55 . V_56 = V_15 -> V_48 ;
V_9 -> V_54 . V_55 . V_57 = 0 ;
* V_10 = 0 ;
return 1 ;
}
static T_2
F_6 ( T_3 * V_9 , T_4 * V_12 , T_6 V_58 )
{
T_4 * V_59 = V_12 ;
int V_16 ;
V_16 = F_12 ( V_59 , V_58 , V_9 -> V_30 ) ;
if ( V_16 == V_58 ) {
for ( ; V_58 > ( T_6 ) ( F_14 ( sizeof( V_60 ) , sizeof( V_61 ) ) ) ; V_59 ++ , V_58 -- )
{
#define F_15 ((nspr_signature_v10_t*)dp)
if ( ( F_16 ( & F_15 -> V_62 ) == V_63 ) &&
( F_16 ( & F_15 -> V_64 ) <= V_58 ) &&
( ( T_6 ) sizeof( V_60 ) <= V_58 ) &&
( ! F_17 ( F_15 -> V_65 ) ) )
return V_21 ;
#undef F_15
#define F_18 ((nspr_signature_v20_t*)dp)
if ( ( F_18 -> V_66 == V_67 ) &&
( F_18 -> V_68 <= V_58 ) &&
( ( T_6 ) sizeof( V_61 ) <= V_58 ) )
{
if ( ! F_19 ( F_18 -> V_65 ) )
return V_24 ;
else if ( ! F_20 ( F_18 -> V_65 ) )
return V_26 ;
}
#undef F_18
}
}
return 0 ;
}
static T_8 F_13 ( T_3 * V_9 )
{
if ( V_9 -> V_20 == V_21 )
return F_21 ( V_9 ) ;
else if ( V_9 -> V_20 == V_24 )
return F_22 ( V_9 ) ;
else if ( V_9 -> V_20 == V_26 )
return F_22 ( V_9 ) ;
return FALSE ;
}
static T_8 V_34 ( T_3 * V_9 , int * V_10 , T_4 * * V_11 , T_5 * V_69 )
{
T_7 * V_15 = ( T_7 * ) V_9 -> V_43 ;
T_1 V_51 = V_15 -> V_51 ;
T_4 * V_12 = V_15 -> V_44 ;
T_6 V_47 = V_15 -> V_47 ;
T_6 V_46 = V_15 -> V_46 ;
T_9 * V_70 ;
T_10 * V_71 ;
int V_16 ;
* V_10 = 0 ;
* V_11 = NULL ;
do
{
while ( ( V_47 < V_46 ) &&
( ( V_46 - V_47 ) >= ( ( T_6 ) sizeof( V_70 -> V_62 ) ) ) )
{
#define F_23 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
fp = (nspr_pktracefull_v10_t *) &nstrace_buf[nstrace_buf_offset];\
\
(phdr)->rec_type = REC_TYPE_PACKET;\
(phdr)->presence_flags = WTAP_HAS_TS;\
nsg_creltime += ns_hrtime2nsec(pletoh32(&fp->fp_RelTimeHr));\
(phdr)->ts.secs = nstrace->nspm_curtime + (guint32) (nsg_creltime / 1000000000);\
(phdr)->ts.nsecs = (guint32) (nsg_creltime % 1000000000);\
TRACE_FULL_V##type##_REC_LEN_OFF(phdr,v##type##_full,fp,pktracefull_v##type);\
buffer_assure_space(wth->frame_buffer, (phdr)->caplen);\
memcpy(buffer_start_ptr(wth->frame_buffer), fp, (phdr)->caplen);\
*data_offset = nstrace->xxx_offset + nstrace_buf_offset;\
nstrace->nstrace_buf_offset = nstrace_buf_offset + (phdr)->len;\
nstrace->nstrace_buflen = nstrace_buflen;\
nstrace->nsg_creltime = nsg_creltime;\
return TRUE;
#define F_24 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
pp = (nspr_pktracepart_v10_t *) &nstrace_buf[nstrace_buf_offset];\
\
(phdr)->rec_type = REC_TYPE_PACKET;\
(phdr)->presence_flags = WTAP_HAS_TS;\
nsg_creltime += ns_hrtime2nsec(pletoh32(&pp->pp_RelTimeHr));\
(phdr)->ts.secs = nstrace->nspm_curtime + (guint32) (nsg_creltime / 1000000000);\
(phdr)->ts.nsecs = (guint32) (nsg_creltime % 1000000000);\
TRACE_PART_V##type##_REC_LEN_OFF(phdr,v##type##_part,pp,pktracepart_v##type);\
buffer_assure_space(wth->frame_buffer, (phdr)->caplen);\
memcpy(buffer_start_ptr(wth->frame_buffer), pp, (phdr)->caplen);\
*data_offset = nstrace->xxx_offset + nstrace_buf_offset;\
nstrace->nstrace_buf_offset = nstrace_buf_offset + (phdr)->caplen;\
nstrace->nsg_creltime = nsg_creltime;\
nstrace->nstrace_buflen = nstrace_buflen;\
return TRUE;\
switch (pletoh16(&(( nspr_header_v10_t*)&nstrace_buf[nstrace_buf_offset])->ph_RecordType))
{
F_23 (&wth->phdr, 10 , 100 )
F_24 (&wth->phdr, 10 , 100 )
#undef F_23
#undef F_24
case V_72 :
V_70 = ( T_9 * ) & V_12 [ V_47 ] ;
F_25 ( V_15 , F_26 ( ( ( V_73 * ) V_70 ) -> V_74 ) , F_26 ( & ( ( V_73 * ) V_70 ) -> V_75 ) ) ;
V_47 += F_16 ( & V_70 -> V_64 ) ;
break;
case V_76 :
V_70 = ( T_9 * ) & V_12 [ V_47 ] ;
F_27 ( V_15 , F_26 ( ( ( V_73 * ) V_70 ) -> V_75 ) ) ;
V_47 += F_16 ( & V_70 -> V_64 ) ;
break;
case V_77 :
V_47 = V_46 ;
break;
default:
V_70 = ( T_9 * ) & V_12 [ V_47 ] ;
V_47 += F_16 ( & V_70 -> V_64 ) ;
break;
}
}
V_47 = 0 ;
V_15 -> V_45 += V_46 ;
V_46 = F_5 ( ( V_15 -> V_13 - V_15 -> V_45 ) ) ;
}while( ( V_46 > 0 ) && ( V_16 = F_12 ( V_12 , V_46 , V_9 -> V_30 ) ) && ( V_16 == V_46 ) );
return FALSE ;
}
static T_8 V_37 ( T_3 * V_9 , int * V_10 , T_4 * * V_11 , T_5 * V_69 )
{
T_7 * V_15 = ( T_7 * ) V_9 -> V_43 ;
T_1 V_51 = V_15 -> V_51 ;
T_4 * V_12 = V_15 -> V_44 ;
T_6 V_47 = V_15 -> V_47 ;
T_6 V_46 = V_15 -> V_46 ;
int V_16 ;
* V_10 = 0 ;
* V_11 = NULL ;
do
{
while ( ( V_47 < V_46 ) &&
( ( V_46 - V_47 ) >= ( ( T_6 ) sizeof( ( ( V_78 * ) & V_12 [ V_47 ] ) -> V_79 ) ) ) )
{
switch ( ( ( V_78 * ) & V_12 [ V_47 ] ) -> V_79 )
{
#define F_23 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
#define F_28 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
case NSPR_PDPKTRACEFULLNEWRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
#define F_24 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,PPSIZEDEFV,type,v##type##_part,pp,pktracepart_v##type,acttype);
#define F_29 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
case NSPR_PDPKTRACEPARTNEWRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,PPSIZEDEFV,type,v##type##_part,pp,pktracepart_v##type,acttype);
F_23 ( & V_9 -> V_54 , 20 , 200 ) ;
F_24 ( & V_9 -> V_54 , 20 , 200 ) ;
F_23 ( & V_9 -> V_54 , 21 , 201 ) ;
F_24 ( & V_9 -> V_54 , 21 , 201 ) ;
F_23 ( & V_9 -> V_54 , 22 , 202 ) ;
F_24 ( & V_9 -> V_54 , 22 , 202 ) ;
F_23 ( & V_9 -> V_54 , 23 , 203 ) ;
F_24 ( & V_9 -> V_54 , 23 , 203 ) ;
F_28 ( & V_9 -> V_54 , 24 , 204 ) ;
F_29 ( & V_9 -> V_54 , 24 , 204 ) ;
F_28 ( & V_9 -> V_54 , 25 , 205 ) ;
F_29 ( & V_9 -> V_54 , 25 , 205 ) ;
F_28 ( & V_9 -> V_54 , 26 , 206 ) ;
F_29 ( & V_9 -> V_54 , 26 , 206 ) ;
#undef F_23
#undef F_28
#undef F_24
#undef F_29
case V_80 :
{
T_12 * V_81 = ( T_12 * ) & V_12 [ V_47 ] ;
V_47 += F_30 ( ( V_78 * ) V_81 ) ;
F_25 ( V_15 , F_26 ( & ( ( V_82 * ) V_81 ) -> V_74 ) , F_16 ( & ( ( V_82 * ) V_81 ) -> V_75 ) ) ;
break;
}
case V_83 :
{
T_12 * V_81 = ( T_12 * ) & V_12 [ V_47 ] ;
F_27 ( V_15 , F_16 ( & ( ( V_82 * ) V_81 ) -> V_75 ) ) ;
V_47 += F_30 ( ( V_78 * ) V_81 ) ;
break;
}
case V_84 :
{
if ( V_47 >= V_19 / 2 )
V_47 = V_46 ;
else
V_47 = V_19 / 2 ;
break;
}
default:
{
T_12 * V_81 = ( T_12 * ) & V_12 [ V_47 ] ;
V_47 += F_30 ( ( V_78 * ) V_81 ) ;
break;
}
}
}
V_47 = 0 ;
V_15 -> V_45 += V_46 ;
V_46 = F_5 ( ( V_15 -> V_13 - V_15 -> V_45 ) ) ;
}while( ( V_46 > 0 ) && ( V_16 = F_12 ( V_12 , V_46 , V_9 -> V_30 ) ) && ( V_16 == V_46 ) );
return FALSE ;
}
static T_8 V_39 ( T_3 * V_9 , int * V_10 , T_4 * * V_11 , T_5 * V_69 )
{
T_7 * V_15 = ( T_7 * ) V_9 -> V_43 ;
T_1 V_51 = V_15 -> V_51 ;
T_4 * V_12 = V_15 -> V_44 ;
T_6 V_47 = V_15 -> V_47 ;
T_6 V_46 = V_15 -> V_46 ;
T_13 V_85 [ 65536 ] ;
T_2 V_86 = 0 , V_87 = 0 , V_88 = 0 , V_89 = 0 ;
V_78 * V_90 ;
int V_16 ;
* V_10 = 0 ;
* V_11 = NULL ;
do
{
while ( ( V_47 < V_28 ) &&
V_12 [ V_47 ] )
{
V_90 = ( V_78 * ) & V_12 [ V_47 ] ;
switch ( V_90 -> V_79 )
{
#define F_31 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
case NSPR_PDPKTRACEFULLNEWRX_V##type:\
PACKET_DESCRIBE(phdr, TIMEDEF, FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
F_31 ( & V_9 -> V_54 , 30 , 300 ) ;
#undef F_31
case V_80 :
{
V_47 += F_30 ( V_90 ) ;
F_25 ( V_15 , F_26 ( & ( ( V_82 * ) & V_12 [ V_47 ] ) -> V_74 ) , F_16 ( & ( ( V_82 * ) & V_12 [ V_47 ] ) -> V_75 ) ) ;
break;
}
case V_83 :
{
F_27 ( V_15 , F_16 ( & ( ( V_82 * ) & V_12 [ V_47 ] ) -> V_75 ) ) ;
V_47 += F_30 ( V_90 ) ;
break;
}
default:
{
V_47 += F_30 ( V_90 ) ;
break;
}
}
}
V_47 = 0 ;
V_15 -> V_45 += V_46 ;
V_46 = V_28 ;
} while( ( V_46 > 0 ) && ( V_16 = F_12 ( V_12 , V_46 , V_9 -> V_30 ) ) && ( V_16 == V_46 ) );
return FALSE ;
}
static T_8 V_36 ( T_3 * V_9 , T_5 V_91 ,
struct V_92 * V_54 , T_14 * V_93 , int * V_10 , T_4 * * V_11 )
{
T_15 V_94 ;
int V_16 ;
T_16 V_95 ;
T_13 * V_96 ;
unsigned int V_97 ;
T_9 * V_70 ;
T_10 * V_71 ;
* V_10 = 0 ;
if ( F_10 ( V_9 -> V_98 , V_91 , V_31 , V_10 ) == - 1 )
return FALSE ;
V_16 = F_12 ( ( void * ) & V_94 , sizeof V_94 , V_9 -> V_98 ) ;
if ( V_16 != sizeof V_94 ) {
* V_10 = F_11 ( V_9 -> V_98 , V_11 ) ;
if ( * V_10 == 0 )
* V_10 = V_32 ;
return FALSE ;
}
V_95 = F_32 ( & V_94 ) ;
F_33 ( V_93 , V_95 ) ;
V_96 = F_34 ( V_93 ) ;
memcpy ( V_96 , ( void * ) & V_94 , sizeof V_94 ) ;
if ( V_95 > sizeof V_94 ) {
V_97 = ( unsigned int ) ( V_95 - sizeof V_94 ) ;
V_16 = F_12 ( V_96 + sizeof V_94 , V_97 , V_9 -> V_98 ) ;
if ( V_16 < 0 || ( unsigned int ) V_16 != V_97 ) {
* V_10 = F_11 ( V_9 -> V_98 , V_11 ) ;
if ( * V_10 == 0 )
* V_10 = V_32 ;
return FALSE ;
}
}
#define F_23 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
fp = (nspr_pktracefull_v10_t *) pd;\
TRACE_FULL_V##type##_REC_LEN_OFF(phdr,v##type##_full,fp,pktracefull_v##type);\
(phdr)->pseudo_header.nstr.rec_type = NSPR_HEADER_VERSION##acttype;\
break;
#define F_24 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
pp = (nspr_pktracepart_v10_t *) pd;\
TRACE_PART_V##type##_REC_LEN_OFF(phdr,v##type##_part,pp,pktracepart_v##type);\
(phdr)->pseudo_header.nstr.rec_type = NSPR_HEADER_VERSION##acttype;\
break;
switch ( F_16 ( & ( ( V_99 * ) V_96 ) -> V_100 ) )
{
F_23 (phdr, 10 , 100 )
F_24 (phdr, 10 , 100 )
}
#undef F_23
#undef F_24
return TRUE ;
}
static T_8 V_38 ( T_3 * V_9 , T_5 V_91 ,
struct V_92 * V_54 , T_14 * V_93 , int * V_10 , T_4 * * V_11 )
{
V_78 V_94 ;
int V_16 ;
T_16 V_95 ;
T_16 V_101 ;
T_13 * V_96 ;
unsigned int V_97 ;
* V_10 = 0 ;
if ( F_10 ( V_9 -> V_98 , V_91 , V_31 , V_10 ) == - 1 )
return FALSE ;
V_16 = F_12 ( ( void * ) & V_94 , 2 , V_9 -> V_98 ) ;
if ( V_16 != 2 ) {
* V_10 = F_11 ( V_9 -> V_98 , V_11 ) ;
if ( * V_10 == 0 )
* V_10 = V_32 ;
return FALSE ;
}
V_101 = 2 ;
if ( V_94 . V_102 & V_103 ) {
V_16 = F_12 ( ( void * ) & V_94 . V_104 , 1 , V_9 -> V_98 ) ;
if ( V_16 != 1 ) {
* V_10 = F_11 ( V_9 -> V_98 , V_11 ) ;
if ( * V_10 == 0 )
* V_10 = V_32 ;
return FALSE ;
}
V_101 = 3 ;
}
V_95 = F_30 ( & V_94 ) ;
F_33 ( V_93 , V_95 ) ;
V_96 = F_34 ( V_93 ) ;
memcpy ( V_96 , ( void * ) & V_94 , V_101 ) ;
if ( V_95 > V_101 ) {
V_97 = ( unsigned int ) ( V_95 - V_101 ) ;
V_16 = F_12 ( V_96 + V_101 , V_97 , V_9 -> V_98 ) ;
if ( V_16 < 0 || ( unsigned int ) V_16 != V_97 ) {
* V_10 = F_11 ( V_9 -> V_98 , V_11 ) ;
if ( * V_10 == 0 )
* V_10 = V_32 ;
return FALSE ;
}
}
#define F_23 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
#define F_28 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
case NSPR_PDPKTRACEFULLNEWRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
#define F_24 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,PPSIZEDEFV,type,v##type##_part,pp,pktracepart_v##type,acttype);
#define F_29 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
case NSPR_PDPKTRACEPARTNEWRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,PPSIZEDEFV,type,v##type##_part,pp,pktracepart_v##type,acttype);
switch ( ( ( V_78 * ) V_96 ) -> V_79 )
{
F_23 (phdr, 20 , 200 )
F_24 (phdr, 20 , 200 )
F_23 (phdr, 21 , 201 )
F_24 (phdr, 21 , 201 )
F_23 (phdr, 22 , 202 )
F_24 (phdr, 22 , 202 )
F_23 (phdr, 23 , 203 )
F_24 (phdr, 23 , 203 )
F_28 (phdr, 24 , 204 )
F_29 (phdr, 24 , 204 )
F_28 (phdr, 25 , 205 )
F_29 (phdr, 25 , 205 )
F_28 (phdr, 26 , 206 )
F_29 (phdr, 26 , 206 )
}
#undef F_23
#undef F_28
#undef F_24
#undef F_29
return TRUE ;
}
static T_8 V_40 ( T_3 * V_9 , T_5 V_91 ,
struct V_92 * V_54 , T_14 * V_93 , int * V_10 , T_4 * * V_11 )
{
V_78 V_94 ;
int V_16 ;
T_16 V_95 ;
T_16 V_101 ;
T_13 * V_96 ;
unsigned int V_97 ;
* V_10 = 0 ;
if ( F_10 ( V_9 -> V_98 , V_91 , V_31 , V_10 ) == - 1 )
return FALSE ;
V_16 = F_12 ( ( void * ) & V_94 , 2 , V_9 -> V_98 ) ;
if ( V_16 != 2 ) {
* V_10 = F_11 ( V_9 -> V_98 , V_11 ) ;
if ( * V_10 == 0 )
* V_10 = V_32 ;
return FALSE ;
}
V_101 = 2 ;
if ( V_94 . V_102 & V_103 ) {
V_16 = F_12 ( ( void * ) & V_94 . V_104 , 1 , V_9 -> V_98 ) ;
if ( V_16 != 1 ) {
* V_10 = F_11 ( V_9 -> V_98 , V_11 ) ;
if ( * V_10 == 0 )
* V_10 = V_32 ;
return FALSE ;
}
V_101 = 3 ;
}
V_95 = F_30 ( & V_94 ) ;
F_33 ( V_93 , V_95 ) ;
V_96 = F_34 ( V_93 ) ;
memcpy ( V_96 , ( void * ) & V_94 , V_101 ) ;
if ( V_95 > V_101 ) {
V_97 = ( unsigned int ) ( V_95 - V_101 ) ;
V_16 = F_12 ( V_96 + V_101 , V_97 , V_9 -> V_98 ) ;
if ( V_16 < 0 || ( unsigned int ) V_16 != V_97 ) {
* V_10 = F_11 ( V_9 -> V_98 , V_11 ) ;
if ( * V_10 == 0 )
* V_10 = V_32 ;
return FALSE ;
}
}
#define F_31 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
case NSPR_PDPKTRACEFULLNEWRX_V##type:\
TRACE_V##type##_REC_LEN_OFF((phdr),v##type##_full,fp,pktracefull_v##type);\
(phdr)->pseudo_header.nstr.rec_type = NSPR_HEADER_VERSION##acttype;\
break;
switch ( ( ( V_78 * ) V_96 ) -> V_79 )
{
F_31 ( V_54 , 30 , 300 ) ;
}
return TRUE ;
}
static void V_42 ( T_3 * V_9 )
{
T_7 * V_15 = ( T_7 * ) V_9 -> V_43 ;
F_7 ( V_15 -> V_44 ) ;
}
int F_35 ( int V_105 )
{
if ( V_105 == V_23 )
return 0 ;
return V_106 ;
}
int F_36 ( int V_105 )
{
if ( V_105 == V_25 )
return 0 ;
return V_106 ;
}
int F_37 ( int V_105 )
{
if ( V_105 == V_27 )
return 0 ;
return V_106 ;
}
T_8 F_38 ( T_17 * V_107 , int * V_10 V_108 )
{
T_18 * V_15 ;
V_107 -> V_109 = V_110 ;
V_15 = ( T_18 * ) F_4 ( sizeof( T_18 ) ) ;
V_107 -> V_43 = ( void * ) V_15 ;
V_15 -> V_111 = 0 ;
V_15 -> V_112 = V_19 ;
V_15 -> V_113 = 0 ;
return TRUE ;
}
static T_8 F_39 ( T_17 * V_107 , int * V_10 )
{
T_18 * V_15 = ( T_18 * ) V_107 -> V_43 ;
if ( V_107 -> V_20 == V_21 )
{
T_19 V_114 ;
T_20 V_115 ;
V_114 = F_40 ( V_63 ) ;
memcpy ( V_115 . V_116 . V_100 , & V_114 , sizeof V_115 . V_116 . V_100 ) ;
V_114 = F_40 ( V_117 ) ;
memcpy ( V_115 . V_116 . V_118 , & V_114 , sizeof V_115 . V_116 . V_118 ) ;
memset ( V_115 . V_65 , 0 , V_119 ) ;
F_41 ( V_115 . V_65 , V_60 , V_119 ) ;
if ( ! F_42 ( V_107 , & V_115 , V_117 ,
V_10 ) )
return FALSE ;
V_15 -> V_111 += ( T_19 ) V_117 ;
} else if ( V_107 -> V_20 == V_24 )
{
T_21 V_120 ;
V_120 . V_66 = V_67 ;
V_120 . V_68 = V_121 ;
memcpy ( V_120 . V_65 , V_61 , sizeof( V_61 ) ) ;
if ( ! F_42 ( V_107 , & V_120 , V_120 . V_68 ,
V_10 ) )
return FALSE ;
V_15 -> V_111 += ( T_19 ) V_120 . V_68 ;
} else if ( V_107 -> V_20 == V_26 )
{
T_22 V_122 ;
V_122 . V_66 = V_123 ;
V_122 . V_68 = V_124 ;
memcpy ( V_122 . V_65 , V_125 , sizeof( V_125 ) ) ;
if ( ! F_42 ( V_107 , & V_122 , V_122 . V_68 ,
V_10 ) )
return FALSE ;
V_15 -> V_111 += ( T_19 ) V_122 . V_68 ;
} else
{
F_43 () ;
return FALSE ;
}
return TRUE ;
}
static T_8
F_44 ( T_17 * V_107 , const struct V_92 * V_54 ,
const T_13 * V_96 , int * V_10 )
{
T_18 * V_15 = ( T_18 * ) V_107 -> V_43 ;
T_1 V_51 ;
if ( V_107 -> V_20 == V_21 )
{
T_19 V_126 ;
T_2 V_127 ;
T_1 V_128 ;
V_73 V_129 ;
V_126 = F_40 ( V_72 ) ;
memcpy ( V_129 . V_116 . V_100 , & V_126 , sizeof V_129 . V_116 . V_100 ) ;
V_126 = F_40 ( V_130 ) ;
memcpy ( V_129 . V_116 . V_118 , & V_126 , sizeof V_129 . V_116 . V_118 ) ;
memcpy ( & V_127 , ( ( const T_9 * ) V_96 ) -> V_131 , sizeof V_127 ) ;
V_51 = F_1 ( V_127 ) ;
memset ( V_129 . V_75 , 0 , sizeof V_129 . V_75 ) ;
V_128 = F_45 ( ( T_2 ) V_54 -> V_55 . V_56 - ( T_2 ) ( V_51 / 1000000000 ) ) ;
memcpy ( V_129 . V_74 , & V_128 , sizeof V_129 . V_74 ) ;
if ( ! F_42 ( V_107 , & V_129 , V_130 , V_10 ) )
return FALSE ;
V_15 -> V_111 += V_130 ;
} else if ( ( V_107 -> V_20 == V_24 ) ||
( V_107 -> V_20 == V_26 ) ) {
T_2 V_127 ;
T_1 V_128 ;
V_82 V_132 ;
V_132 . V_133 = V_80 ;
V_132 . V_134 = V_135 ;
memcpy ( & V_127 , ( ( const T_12 * ) V_96 ) -> V_131 , sizeof V_127 ) ;
V_51 = F_1 ( V_127 ) ;
memset ( V_132 . V_75 , 0 , sizeof V_132 . V_75 ) ;
V_128 = F_45 ( ( T_2 ) V_54 -> V_55 . V_56 - ( T_2 ) ( V_51 / 1000000000 ) ) ;
memcpy ( V_132 . V_75 , & V_128 , sizeof V_132 . V_75 ) ;
if ( ! F_42 ( V_107 , & V_132 , V_135 , V_10 ) )
return FALSE ;
V_15 -> V_111 += V_135 ;
} else
{
F_43 () ;
return FALSE ;
}
return TRUE ;
}
static T_8 V_110 ( T_17 * V_107 , const struct V_92 * V_54 ,
const T_13 * V_96 , int * V_10 )
{
T_18 * V_15 = ( T_18 * ) V_107 -> V_43 ;
if ( V_54 -> V_136 != V_137 ) {
* V_10 = V_138 ;
return FALSE ;
}
if ( V_15 -> V_111 == 0 )
{
if ( V_107 -> V_20 == V_21 )
{
if ( ! F_39 ( V_107 , V_10 ) ||
! F_44 ( V_107 , V_54 , V_96 , V_10 ) )
return FALSE ;
} else if ( V_107 -> V_20 == V_24 )
{
if ( ! F_39 ( V_107 , V_10 ) ||
! F_44 ( V_107 , V_54 , V_96 , V_10 ) )
return FALSE ;
} else if ( V_107 -> V_20 == V_26 )
{
if ( ! F_39 ( V_107 , V_10 ) ||
! F_44 ( V_107 , V_54 , V_96 , V_10 ) )
return FALSE ;
} else
{
F_43 () ;
return FALSE ;
}
}
switch ( V_54 -> V_139 . V_140 . V_136 )
{
case V_141 :
if ( V_107 -> V_20 == V_21 )
{
if ( V_15 -> V_111 + V_54 -> V_142 >= V_15 -> V_112 )
{
if ( F_46 ( V_107 , ( V_15 -> V_112 - V_15 -> V_111 ) , V_143 , V_10 ) == - 1 )
return FALSE ;
V_15 -> V_111 = 0 ;
if ( ! F_39 ( V_107 , V_10 ) )
return FALSE ;
}
if ( ! F_42 ( V_107 , V_96 , V_54 -> V_142 , V_10 ) )
return FALSE ;
V_15 -> V_111 += ( T_19 ) V_54 -> V_142 ;
} else if ( V_107 -> V_20 == V_24 )
{
* V_10 = V_144 ;
return FALSE ;
}
break;
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
if ( V_107 -> V_20 == V_21 )
{
* V_10 = V_144 ;
return FALSE ;
} else if ( V_107 -> V_20 == V_24 )
{
if ( V_15 -> V_111 + V_54 -> V_142 >= V_15 -> V_112 )
{
if ( F_46 ( V_107 , ( V_15 -> V_112 - V_15 -> V_111 ) , V_143 , V_10 ) == - 1 )
return FALSE ;
V_15 -> V_111 = 0 ;
if ( ! F_39 ( V_107 , V_10 ) )
return FALSE ;
}
if ( ! F_42 ( V_107 , V_96 , V_54 -> V_142 , V_10 ) )
return FALSE ;
V_15 -> V_111 += ( T_19 ) V_54 -> V_142 ;
}
break;
case V_152 :
if ( V_107 -> V_20 == V_21 )
{
* V_10 = V_144 ;
return FALSE ;
} else if ( V_107 -> V_20 == V_24 )
{
* V_10 = V_144 ;
return FALSE ;
} else if ( V_107 -> V_20 == V_26 )
{
if ( V_15 -> V_111 + V_54 -> V_142 >= V_15 -> V_112 )
{
if ( F_46 ( V_107 , ( V_15 -> V_112 - V_15 -> V_111 ) , V_143 , V_10 ) == - 1 )
return FALSE ;
V_15 -> V_111 = 0 ;
if ( ! F_39 ( V_107 , V_10 ) )
return FALSE ;
}
if ( ! F_42 ( V_107 , V_96 , V_54 -> V_142 , V_10 ) )
return FALSE ;
V_15 -> V_111 += ( T_19 ) V_54 -> V_142 ;
} else
{
F_43 () ;
return FALSE ;
}
break;
default:
F_43 () ;
return FALSE ;
}
return TRUE ;
}
