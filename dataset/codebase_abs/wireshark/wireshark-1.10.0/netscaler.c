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
default:
* V_10 = V_26 ;
* V_11 = F_7 ( L_1 , V_9 -> V_20 ) ;
F_8 ( V_12 ) ;
return 0 ;
}
if ( ( F_9 ( V_9 -> V_27 , 0 , V_28 , V_10 ) ) == - 1 )
{
* V_10 = F_10 ( V_9 -> V_27 , V_11 ) ;
F_8 ( V_12 ) ;
return 0 ;
}
V_16 = F_11 ( V_12 , V_14 , V_9 -> V_27 ) ;
if ( V_16 != V_14 )
{
* V_10 = F_10 ( V_9 -> V_27 , V_11 ) ;
F_8 ( V_12 ) ;
if ( * V_10 != 0 && * V_10 != V_29 )
return - 1 ;
return 0 ;
}
switch ( V_9 -> V_20 )
{
case V_21 :
V_9 -> V_30 = V_31 ;
V_9 -> V_32 = V_33 ;
break;
case V_24 :
V_9 -> V_30 = V_34 ;
V_9 -> V_32 = V_35 ;
break;
}
V_9 -> V_36 = V_37 ;
V_15 = ( T_7 * ) F_4 ( sizeof( T_7 ) ) ;
V_9 -> V_38 = ( void * ) V_15 ;
V_15 -> V_39 = V_12 ;
V_15 -> V_40 = 0 ;
V_15 -> V_41 = V_14 ;
V_15 -> V_42 = 0 ;
V_15 -> V_43 = 0 ;
V_15 -> V_44 = 0 ;
V_15 -> V_45 = 0 ;
V_15 -> V_46 = 0 ;
V_15 -> V_13 = V_13 ;
if ( ( F_12 ( V_9 ) ) == FALSE )
{
if ( ( F_9 ( V_9 -> V_27 , 0 , V_28 , V_10 ) ) == - 1 )
{
* V_10 = F_10 ( V_9 -> V_27 , V_11 ) ;
F_8 ( V_15 -> V_39 ) ;
F_8 ( V_15 ) ;
return 0 ;
}
V_16 = F_11 ( V_12 , V_14 , V_9 -> V_27 ) ;
if ( V_16 != V_14 )
{
* V_10 = F_10 ( V_9 -> V_27 , V_11 ) ;
F_8 ( V_15 -> V_39 ) ;
F_8 ( V_15 ) ;
return 0 ;
}
V_15 -> V_42 = 0 ;
}
V_9 -> V_47 = V_48 ;
V_9 -> V_49 . V_50 . V_51 = V_15 -> V_43 ;
V_9 -> V_49 . V_50 . V_52 = 0 ;
* V_10 = 0 ;
return 1 ;
}
static T_2
F_6 ( T_3 * V_9 , T_4 * V_12 , T_6 V_53 )
{
T_4 * V_54 = V_12 ;
int V_16 ;
V_16 = F_11 ( V_54 , V_53 , V_9 -> V_27 ) ;
if ( V_16 == V_53 ) {
for ( ; V_53 > ( T_6 ) ( F_13 ( sizeof( V_55 ) , sizeof( V_56 ) ) ) ; V_54 ++ , V_53 -- )
{
#define F_14 ((nspr_signature_v10_t*)dp)
if ( ( F_15 ( & F_14 -> V_57 ) == V_58 ) &&
( F_15 ( & F_14 -> V_59 ) <= V_53 ) &&
( ( T_6 ) sizeof( V_55 ) <= V_53 ) &&
( ! F_16 ( F_14 -> V_60 ) ) )
return V_21 ;
#undef F_14
#define F_17 ((nspr_signature_v20_t*)dp)
if ( ( F_17 -> V_61 == V_62 ) &&
( F_17 -> V_63 <= V_53 ) &&
( ( T_6 ) sizeof( V_56 ) <= V_53 ) &&
( ! F_18 ( F_17 -> V_60 ) ) )
return V_24 ;
#undef F_17
}
}
return 0 ;
}
static T_8 F_12 ( T_3 * V_9 )
{
if ( V_9 -> V_20 == V_21 )
return F_19 ( V_9 ) ;
else if ( V_9 -> V_20 == V_24 )
return F_20 ( V_9 ) ;
return FALSE ;
}
static T_8 V_31 ( T_3 * V_9 , int * V_10 , T_4 * * V_11 , T_5 * V_64 )
{
T_7 * V_15 = ( T_7 * ) V_9 -> V_38 ;
T_1 V_46 = V_15 -> V_46 ;
T_4 * V_12 = V_15 -> V_39 ;
T_6 V_42 = V_15 -> V_42 ;
T_6 V_41 = V_15 -> V_41 ;
T_9 * V_65 ;
T_10 * V_66 ;
int V_16 ;
* V_10 = 0 ;
* V_11 = NULL ;
do
{
while ( ( V_42 < V_41 ) &&
( ( V_41 - V_42 ) >= ( ( T_6 ) sizeof( V_65 -> V_57 ) ) ) )
{
#define F_21 ( V_49 , type , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
fp = (nspr_pktracefull_v10_t *) &nstrace_buf[nstrace_buf_offset];\
\
(phdr)->presence_flags = WTAP_HAS_TS;\
nsg_creltime += ns_hrtime2nsec(pletohl(&fp->fp_RelTimeHr));\
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
#define F_22 ( V_49 , type , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
pp = (nspr_pktracepart_v10_t *) &nstrace_buf[nstrace_buf_offset];\
\
(phdr)->presence_flags = WTAP_HAS_TS;\
nsg_creltime += ns_hrtime2nsec(pletohl(&pp->pp_RelTimeHr));\
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
switch (pletohs(&(( nspr_header_v10_t*)&nstrace_buf[nstrace_buf_offset])->ph_RecordType))
{
F_21 (&wth->phdr, 10 , 100 )
F_22 (&wth->phdr, 10 , 100 )
#undef F_21
#undef F_22
case V_67 :
V_65 = ( T_9 * ) & V_12 [ V_42 ] ;
F_23 ( V_15 , F_24 ( ( ( V_68 * ) V_65 ) -> V_69 ) , F_24 ( & ( ( V_68 * ) V_65 ) -> V_70 ) ) ;
V_42 += F_15 ( & V_65 -> V_59 ) ;
break;
case V_71 :
V_65 = ( T_9 * ) & V_12 [ V_42 ] ;
F_25 ( V_15 , F_24 ( ( ( V_68 * ) V_65 ) -> V_70 ) ) ;
V_42 += F_15 ( & V_65 -> V_59 ) ;
break;
case V_72 :
V_42 = V_41 ;
break;
default:
V_65 = ( T_9 * ) & V_12 [ V_42 ] ;
V_42 += F_15 ( & V_65 -> V_59 ) ;
break;
}
}
V_42 = 0 ;
V_15 -> V_40 += V_41 ;
V_41 = F_5 ( ( V_15 -> V_13 - V_15 -> V_40 ) ) ;
}while( ( V_41 > 0 ) && ( V_16 = F_11 ( V_12 , V_41 , V_9 -> V_27 ) ) && ( V_16 == V_41 ) );
return FALSE ;
}
static T_8 V_34 ( T_3 * V_9 , int * V_10 , T_4 * * V_11 , T_5 * V_64 )
{
T_7 * V_15 = ( T_7 * ) V_9 -> V_38 ;
T_1 V_46 = V_15 -> V_46 ;
T_4 * V_12 = V_15 -> V_39 ;
T_6 V_42 = V_15 -> V_42 ;
T_6 V_41 = V_15 -> V_41 ;
int V_16 ;
* V_10 = 0 ;
* V_11 = NULL ;
do
{
while ( ( V_42 < V_41 ) &&
( ( V_41 - V_42 ) >= ( ( T_6 ) sizeof( ( ( V_73 * ) & V_12 [ V_42 ] ) -> V_74 ) ) ) )
{
switch ( ( ( V_73 * ) & V_12 [ V_42 ] ) -> V_74 )
{
#define F_21 ( V_49 , type , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
#define F_26 ( V_49 , type , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
case NSPR_PDPKTRACEFULLNEWRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
#define F_22 ( V_49 , type , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,PPSIZEDEFV,type,v##type##_part,pp,pktracepart_v##type,acttype);
#define F_27 ( V_49 , type , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
case NSPR_PDPKTRACEPARTNEWRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,PPSIZEDEFV,type,v##type##_part,pp,pktracepart_v##type,acttype);
F_21 ( & V_9 -> V_49 , 20 , 200 ) ;
F_22 ( & V_9 -> V_49 , 20 , 200 ) ;
F_21 ( & V_9 -> V_49 , 21 , 201 ) ;
F_22 ( & V_9 -> V_49 , 21 , 201 ) ;
F_21 ( & V_9 -> V_49 , 22 , 202 ) ;
F_22 ( & V_9 -> V_49 , 22 , 202 ) ;
F_21 ( & V_9 -> V_49 , 23 , 203 ) ;
F_22 ( & V_9 -> V_49 , 23 , 203 ) ;
F_26 ( & V_9 -> V_49 , 24 , 204 ) ;
F_27 ( & V_9 -> V_49 , 24 , 204 ) ;
F_26 ( & V_9 -> V_49 , 25 , 205 ) ;
F_27 ( & V_9 -> V_49 , 25 , 205 ) ;
#undef F_21
#undef F_26
#undef F_22
#undef F_27
case V_75 :
{
T_12 * V_76 = ( T_12 * ) & V_12 [ V_42 ] ;
V_42 += F_28 ( ( V_73 * ) V_76 ) ;
F_23 ( V_15 , F_24 ( & ( ( V_77 * ) V_76 ) -> V_69 ) , F_15 ( & ( ( V_77 * ) V_76 ) -> V_70 ) ) ;
break;
}
case V_78 :
{
T_12 * V_76 = ( T_12 * ) & V_12 [ V_42 ] ;
F_25 ( V_15 , F_15 ( & ( ( V_77 * ) V_76 ) -> V_70 ) ) ;
V_42 += F_28 ( ( V_73 * ) V_76 ) ;
break;
}
case V_79 :
{
if ( V_42 >= V_19 / 2 )
V_42 = V_41 ;
else
V_42 = V_19 / 2 ;
break;
}
default:
{
T_12 * V_76 = ( T_12 * ) & V_12 [ V_42 ] ;
V_42 += F_28 ( ( V_73 * ) V_76 ) ;
break;
}
}
}
V_42 = 0 ;
V_15 -> V_40 += V_41 ;
V_41 = F_5 ( ( V_15 -> V_13 - V_15 -> V_40 ) ) ;
}while( ( V_41 > 0 ) && ( V_16 = F_11 ( V_12 , V_41 , V_9 -> V_27 ) ) && ( V_16 == V_41 ) );
return FALSE ;
}
static T_8 V_33 ( T_3 * V_9 , T_5 V_80 ,
struct V_81 * V_49 , T_13 * V_82 , int V_83 ,
int * V_10 , T_4 * * V_11 )
{
int V_16 ;
T_9 * V_65 ;
T_10 * V_66 ;
* V_10 = 0 ;
if ( F_9 ( V_9 -> V_84 , V_80 , V_28 , V_10 ) == - 1 )
return FALSE ;
V_16 = F_11 ( V_82 , V_83 , V_9 -> V_84 ) ;
if ( V_16 != V_83 ) {
* V_10 = F_10 ( V_9 -> V_84 , V_11 ) ;
if ( * V_10 == 0 )
* V_10 = V_29 ;
return FALSE ;
}
#define F_21 ( V_49 , type , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
fp = (nspr_pktracefull_v10_t *) pd;\
TRACE_FULL_V##type##_REC_LEN_OFF(phdr,v##type##_full,fp,pktracefull_v##type);\
(phdr)->pseudo_header.nstr.rec_type = NSPR_HEADER_VERSION##acttype;\
break;
#define F_22 ( V_49 , type , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
pp = (nspr_pktracepart_v10_t *) pd;\
TRACE_PART_V##type##_REC_LEN_OFF(phdr,v##type##_part,pp,pktracepart_v##type);\
(phdr)->pseudo_header.nstr.rec_type = NSPR_HEADER_VERSION##acttype;\
break;
switch ( F_15 ( & ( ( V_85 * ) V_82 ) -> V_86 ) )
{
F_21 (phdr, 10 , 100 )
F_22 (phdr, 10 , 100 )
}
#undef F_21
#undef F_22
return TRUE ;
}
static T_8 V_35 ( T_3 * V_9 , T_5 V_80 ,
struct V_81 * V_49 , T_13 * V_82 , int V_83 ,
int * V_10 , T_4 * * V_11 )
{
int V_16 ;
* V_10 = 0 ;
if ( F_9 ( V_9 -> V_84 , V_80 , V_28 , V_10 ) == - 1 )
return FALSE ;
V_16 = F_11 ( V_82 , V_83 , V_9 -> V_84 ) ;
if ( V_16 != V_83 ) {
* V_10 = F_10 ( V_9 -> V_84 , V_11 ) ;
if ( * V_10 == 0 )
* V_10 = V_29 ;
return FALSE ;
}
#define F_21 ( V_49 , type , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
#define F_26 ( V_49 , type , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
case NSPR_PDPKTRACEFULLNEWRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
#define F_22 ( V_49 , type , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,PPSIZEDEFV,type,v##type##_part,pp,pktracepart_v##type,acttype);
#define F_27 ( V_49 , type , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
case NSPR_PDPKTRACEPARTNEWRX_V##type:\
PACKET_DESCRIBE(phdr,TIMEDEF,PPSIZEDEFV,type,v##type##_part,pp,pktracepart_v##type,acttype);
switch ( ( ( V_73 * ) V_82 ) -> V_74 )
{
F_21 (phdr, 20 , 200 )
F_22 (phdr, 20 , 200 )
F_21 (phdr, 21 , 201 )
F_22 (phdr, 21 , 201 )
F_21 (phdr, 22 , 202 )
F_22 (phdr, 22 , 202 )
F_21 (phdr, 23 , 203 )
F_22 (phdr, 23 , 203 )
F_26 (phdr, 24 , 204 )
F_27 (phdr, 24 , 204 )
F_26 (phdr, 25 , 205 )
F_27 (phdr, 25 , 205 )
}
#undef F_21
#undef F_26
#undef F_22
#undef F_27
return TRUE ;
}
static void V_37 ( T_3 * V_9 )
{
T_7 * V_15 = ( T_7 * ) V_9 -> V_38 ;
F_8 ( V_15 -> V_39 ) ;
}
int F_29 ( int V_87 )
{
if ( V_87 == V_23 )
return 0 ;
return V_88 ;
}
int F_30 ( int V_87 )
{
if ( V_87 == V_25 )
return 0 ;
return V_88 ;
}
T_8 F_31 ( T_14 * V_89 , int * V_10 V_90 )
{
T_15 * V_15 ;
V_89 -> V_91 = V_92 ;
V_15 = ( T_15 * ) F_4 ( sizeof( T_15 ) ) ;
V_89 -> V_38 = ( void * ) V_15 ;
V_15 -> V_93 = 0 ;
V_15 -> V_94 = V_19 ;
V_15 -> V_95 = 0 ;
return TRUE ;
}
static T_8 F_32 ( T_14 * V_89 , int * V_10 )
{
T_15 * V_15 = ( T_15 * ) V_89 -> V_38 ;
if ( V_89 -> V_20 == V_21 )
{
T_16 V_96 ;
T_17 V_97 ;
V_96 = F_33 ( V_58 ) ;
memcpy ( V_97 . V_98 . V_86 , & V_96 , sizeof V_97 . V_98 . V_86 ) ;
V_96 = F_33 ( V_99 ) ;
memcpy ( V_97 . V_98 . V_100 , & V_96 , sizeof V_97 . V_98 . V_100 ) ;
memset ( V_97 . V_60 , 0 , V_101 ) ;
F_34 ( V_97 . V_60 , V_55 , V_101 ) ;
if ( ! F_35 ( V_89 , & V_97 , V_99 ,
V_10 ) )
return FALSE ;
V_15 -> V_93 += ( T_16 ) V_99 ;
} else if ( V_89 -> V_20 == V_24 )
{
T_18 V_102 ;
V_102 . V_61 = V_62 ;
V_102 . V_63 = V_103 ;
memcpy ( V_102 . V_60 , V_56 , sizeof( V_56 ) ) ;
if ( ! F_35 ( V_89 , & V_102 , V_102 . V_63 ,
V_10 ) )
return FALSE ;
V_15 -> V_93 += ( T_16 ) V_102 . V_63 ;
} else
{
F_36 () ;
return FALSE ;
}
return TRUE ;
}
static T_8
F_37 ( T_14 * V_89 , const struct V_81 * V_49 ,
const T_13 * V_82 , int * V_10 )
{
T_15 * V_15 = ( T_15 * ) V_89 -> V_38 ;
T_1 V_46 ;
if ( V_89 -> V_20 == V_21 )
{
T_16 V_104 ;
T_2 V_105 ;
T_1 V_106 ;
V_68 V_107 ;
V_104 = F_33 ( V_67 ) ;
memcpy ( V_107 . V_98 . V_86 , & V_104 , sizeof V_107 . V_98 . V_86 ) ;
V_104 = F_33 ( V_108 ) ;
memcpy ( V_107 . V_98 . V_100 , & V_104 , sizeof V_107 . V_98 . V_100 ) ;
memcpy ( & V_105 , ( ( const T_9 * ) V_82 ) -> V_109 , sizeof V_105 ) ;
V_46 = F_1 ( V_105 ) ;
memset ( V_107 . V_70 , 0 , sizeof V_107 . V_70 ) ;
V_106 = F_38 ( ( T_2 ) V_49 -> V_50 . V_51 - ( T_2 ) ( V_46 / 1000000000 ) ) ;
memcpy ( V_107 . V_69 , & V_106 , sizeof V_107 . V_69 ) ;
if ( ! F_35 ( V_89 , & V_107 , V_108 , V_10 ) )
return FALSE ;
V_15 -> V_93 += V_108 ;
} else if ( V_89 -> V_20 == V_24 )
{
T_2 V_105 ;
T_1 V_106 ;
V_77 V_110 ;
V_110 . V_111 = V_75 ;
V_110 . V_112 = V_113 ;
memcpy ( & V_105 , ( ( const T_12 * ) V_82 ) -> V_109 , sizeof V_105 ) ;
V_46 = F_1 ( V_105 ) ;
memset ( V_110 . V_70 , 0 , sizeof V_110 . V_70 ) ;
V_106 = F_38 ( ( T_2 ) V_49 -> V_50 . V_51 - ( T_2 ) ( V_46 / 1000000000 ) ) ;
memcpy ( V_110 . V_70 , & V_106 , sizeof V_110 . V_70 ) ;
if ( ! F_35 ( V_89 , & V_110 , V_113 , V_10 ) )
return FALSE ;
V_15 -> V_93 += V_113 ;
} else
{
F_36 () ;
return FALSE ;
}
return TRUE ;
}
static T_8 V_92 ( T_14 * V_89 , const struct V_81 * V_49 ,
const T_13 * V_82 , int * V_10 )
{
T_15 * V_15 = ( T_15 * ) V_89 -> V_38 ;
if ( V_15 -> V_93 == 0 )
{
if ( V_89 -> V_20 == V_21 )
{
if ( ! F_32 ( V_89 , V_10 ) ||
! F_37 ( V_89 , V_49 , V_82 , V_10 ) )
return FALSE ;
} else if ( V_89 -> V_20 == V_24 )
{
if ( ! F_32 ( V_89 , V_10 ) ||
! F_37 ( V_89 , V_49 , V_82 , V_10 ) )
return FALSE ;
} else
{
F_36 () ;
return FALSE ;
}
}
switch ( V_49 -> V_114 . V_115 . V_116 )
{
case V_117 :
if ( V_89 -> V_20 == V_21 )
{
if ( V_15 -> V_93 + V_49 -> V_118 >= V_15 -> V_94 )
{
if ( F_39 ( V_89 , ( V_15 -> V_94 - V_15 -> V_93 ) , V_119 , V_10 ) == - 1 )
return FALSE ;
V_15 -> V_93 = 0 ;
if ( ! F_32 ( V_89 , V_10 ) )
return FALSE ;
}
if ( ! F_35 ( V_89 , V_82 , V_49 -> V_118 , V_10 ) )
return FALSE ;
V_15 -> V_93 += ( T_16 ) V_49 -> V_118 ;
} else if ( V_89 -> V_20 == V_24 )
{
* V_10 = V_120 ;
return FALSE ;
}
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
if ( V_89 -> V_20 == V_21 )
{
* V_10 = V_120 ;
return FALSE ;
} else if ( V_89 -> V_20 == V_24 )
{
if ( V_15 -> V_93 + V_49 -> V_118 >= V_15 -> V_94 )
{
if ( F_39 ( V_89 , ( V_15 -> V_94 - V_15 -> V_93 ) , V_119 , V_10 ) == - 1 )
return FALSE ;
V_15 -> V_93 = 0 ;
if ( ! F_32 ( V_89 , V_10 ) )
return FALSE ;
}
if ( ! F_35 ( V_89 , V_82 , V_49 -> V_118 , V_10 ) )
return FALSE ;
V_15 -> V_93 += ( T_16 ) V_49 -> V_118 ;
}
break;
default:
F_36 () ;
return FALSE ;
}
return TRUE ;
}
