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
return 0 ;
}
V_9 -> V_29 = V_30 ;
V_9 -> V_31 = V_32 ;
V_9 -> V_33 = V_34 ;
V_15 = ( T_7 * ) F_4 ( sizeof( T_7 ) ) ;
V_9 -> V_35 = ( void * ) V_15 ;
V_15 -> V_36 = V_12 ;
V_15 -> V_37 = 0 ;
V_15 -> V_38 = V_14 ;
V_15 -> V_39 = 0 ;
V_15 -> V_40 = 0 ;
V_15 -> V_41 = 0 ;
V_15 -> V_42 = 0 ;
V_15 -> V_43 = 0 ;
V_15 -> V_13 = V_13 ;
if ( ( F_12 ( V_9 ) ) == FALSE )
{
if ( ( F_9 ( V_9 -> V_27 , 0 , V_28 , V_10 ) ) == - 1 )
{
* V_10 = F_10 ( V_9 -> V_27 , V_11 ) ;
F_8 ( V_15 -> V_36 ) ;
F_8 ( V_15 ) ;
return 0 ;
}
V_16 = F_11 ( V_12 , V_14 , V_9 -> V_27 ) ;
if ( V_16 != V_14 )
{
* V_10 = F_10 ( V_9 -> V_27 , V_11 ) ;
F_8 ( V_15 -> V_36 ) ;
F_8 ( V_15 ) ;
return 0 ;
}
V_15 -> V_39 = 0 ;
}
V_9 -> V_44 = V_45 ;
V_9 -> V_46 . V_47 . V_48 = V_15 -> V_40 ;
V_9 -> V_46 . V_47 . V_49 = 0 ;
* V_10 = 0 ;
return 1 ;
}
static T_2
F_6 ( T_3 * V_9 , T_4 * V_12 , T_6 V_50 )
{
T_4 * V_51 = V_12 ;
int V_16 ;
V_16 = F_11 ( V_51 , V_50 , V_9 -> V_27 ) ;
if ( V_16 == V_50 ) {
for ( ; V_50 > ( T_6 ) ( F_13 ( sizeof( V_52 ) , sizeof( V_53 ) ) ) ; V_51 ++ , V_50 -- )
{
#define F_14 ((nspr_signature_v10_t*)dp)
if ( ( F_15 ( & F_14 -> V_54 ) == V_55 ) &&
( F_15 ( & F_14 -> V_56 ) <= V_50 ) &&
( ( T_6 ) sizeof( V_52 ) <= V_50 ) &&
( ! F_16 ( F_14 -> V_57 ) ) )
return V_21 ;
#undef F_14
#define F_17 ((nspr_signature_v20_t*)dp)
if ( ( F_17 -> V_58 == V_59 ) &&
( F_17 -> V_60 <= V_50 ) &&
( ( T_6 ) sizeof( V_53 ) <= V_50 ) &&
( ! F_18 ( F_17 -> V_57 ) ) )
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
static T_8 F_21 ( T_3 * V_9 , int * V_10 , T_4 * * V_11 , T_5 * V_61 )
{
T_7 * V_15 = ( T_7 * ) V_9 -> V_35 ;
T_1 V_43 = V_15 -> V_43 ;
T_4 * V_12 = V_15 -> V_36 ;
T_6 V_39 = V_15 -> V_39 ;
T_6 V_38 = V_15 -> V_38 ;
T_9 * V_62 ;
T_10 * V_63 ;
int V_16 ;
* V_10 = 0 ;
* V_11 = NULL ;
do
{
while ( ( V_39 < V_38 ) &&
( ( V_38 - V_39 ) >= ( ( T_6 ) sizeof( V_62 -> V_54 ) ) ) )
{
V_62 = ( T_9 * ) & V_12 [ V_39 ] ;
V_63 = ( T_10 * ) V_62 ;
switch ( F_15 ( & V_62 -> V_54 ) )
{
case V_64 :
case V_65 :
case V_66 :
V_9 -> V_46 . V_67 = V_68 ;
V_43 += F_1 ( F_22 ( & V_62 -> V_69 ) ) ;
V_9 -> V_46 . V_47 . V_48 = V_15 -> V_40 + ( T_2 ) ( V_43 / 1000000000 ) ;
V_9 -> V_46 . V_47 . V_49 = ( T_2 ) ( V_43 % 1000000000 ) ;
V_9 -> V_46 . V_50 = F_15 ( & V_62 -> V_56 ) ;
V_9 -> V_46 . V_70 = V_9 -> V_46 . V_50 ;
F_23 ( V_71 , V_62 , V_72 ) ;
F_24 ( V_9 -> V_73 , V_9 -> V_46 . V_70 ) ;
memcpy ( F_25 ( V_9 -> V_73 ) , V_62 , V_9 -> V_46 . V_70 ) ;
* V_61 = V_15 -> V_37 + V_39 ;
V_15 -> V_39 = V_39 + V_9 -> V_46 . V_50 ;
V_15 -> V_38 = V_38 ;
V_15 -> V_43 = V_43 ;
return TRUE ;
case V_74 :
case V_75 :
case V_76 :
V_9 -> V_46 . V_67 = V_68 | V_77 ;
V_43 += F_1 ( F_22 ( & V_63 -> V_78 ) ) ;
V_9 -> V_46 . V_47 . V_48 = V_15 -> V_40 + ( T_2 ) ( V_43 / 1000000000 ) ;
V_9 -> V_46 . V_47 . V_49 = ( T_2 ) ( V_43 % 1000000000 ) ;
V_9 -> V_46 . V_50 = F_15 ( & V_63 -> V_79 ) + V_80 ;
V_9 -> V_46 . V_70 = F_15 ( & V_63 -> V_56 ) ;
F_23 ( V_81 , V_63 , V_82 ) ;
F_24 ( V_9 -> V_73 , V_9 -> V_46 . V_70 ) ;
memcpy ( F_25 ( V_9 -> V_73 ) , V_63 , V_9 -> V_46 . V_70 ) ;
* V_61 = V_15 -> V_37 + V_39 ;
V_15 -> V_39 = V_39 + V_9 -> V_46 . V_70 ;
V_15 -> V_43 = V_43 ;
V_15 -> V_38 = V_38 ;
return TRUE ;
case V_83 :
F_26 ( V_15 , F_22 ( ( ( V_84 * ) V_62 ) -> V_85 ) , F_22 ( & ( ( V_84 * ) V_62 ) -> V_86 ) ) ;
V_39 += F_15 ( & V_62 -> V_56 ) ;
break;
case V_87 :
F_27 ( V_15 , F_22 ( ( ( V_84 * ) V_62 ) -> V_86 ) ) ;
V_39 += F_15 ( & V_62 -> V_56 ) ;
break;
case V_88 :
V_39 = V_38 ;
break;
default:
V_39 += F_15 ( & V_62 -> V_56 ) ;
break;
}
}
V_39 = 0 ;
V_15 -> V_37 += V_38 ;
V_38 = F_5 ( ( V_15 -> V_13 - V_15 -> V_37 ) ) ;
}while( ( V_38 > 0 ) && ( V_16 = F_11 ( V_12 , V_38 , V_9 -> V_27 ) ) && ( V_16 == V_38 ) );
return FALSE ;
}
static T_8 F_28 ( T_3 * V_9 , int * V_10 , T_4 * * V_11 , T_5 * V_61 )
{
T_7 * V_15 = ( T_7 * ) V_9 -> V_35 ;
T_1 V_43 = V_15 -> V_43 ;
T_4 * V_12 = V_15 -> V_36 ;
T_6 V_39 = V_15 -> V_39 ;
T_6 V_38 = V_15 -> V_38 ;
T_11 * V_89 ;
T_12 * V_90 ;
int V_16 ;
* V_10 = 0 ;
* V_11 = NULL ;
do
{
while ( ( V_39 < V_38 ) &&
( ( V_38 - V_39 ) >= ( ( T_6 ) sizeof( V_90 -> V_91 ) ) ) )
{
V_90 = ( T_12 * ) & V_12 [ V_39 ] ;
switch ( V_90 -> V_91 )
{
#define F_29 ( type , T_13 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
PACKET_DESCRIBE(TIMEDEF,FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
#define F_30 ( type , T_13 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
case NSPR_PDPKTRACEFULLNEWRX_V##type:\
PACKET_DESCRIBE(TIMEDEF,FPSIZEDEFV,type,v##type##_full,fp,pktracefull_v##type,acttype);
F_30 ( 24 , 204 ) ;
F_29 ( 23 , 203 ) ;
F_29 ( 22 , 202 ) ;
F_29 ( 21 , 201 ) ;
F_29 ( 20 , 200 ) ;
#undef F_29
#undef F_30
#define F_29 ( type , T_13 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
PACKET_DESCRIBE(TIMEDEF,PPSIZEDEFV,type,v##type##_part,pp,pktracepart_v##type,acttype);
#define F_30 ( type , T_13 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
case NSPR_PDPKTRACEPARTNEWRX_V##type:\
PACKET_DESCRIBE(TIMEDEF,PPSIZEDEFV,type,v##type##_part,pp,pktracepart_v##type,acttype);
F_30 ( 24 , 204 ) ;
F_29 ( 23 , 203 ) ;
F_29 ( 22 , 202 ) ;
F_29 ( 21 , 201 ) ;
F_29 ( 20 , 200 ) ;
#undef F_29
#undef F_30
case V_92 :
{
V_89 = ( T_11 * ) & V_12 [ V_39 ] ;
V_39 += F_31 ( ( V_93 * ) V_89 ) ;
F_26 ( V_15 , F_22 ( & ( ( V_94 * ) V_89 ) -> V_85 ) , F_15 ( & ( ( V_94 * ) V_89 ) -> V_86 ) ) ;
break;
}
case V_95 :
{
V_89 = ( T_11 * ) & V_12 [ V_39 ] ;
F_27 ( V_15 , F_15 ( & ( ( V_94 * ) V_89 ) -> V_86 ) ) ;
V_39 += F_31 ( ( V_93 * ) V_89 ) ;
break;
}
case V_96 :
{
if ( V_39 >= V_19 / 2 )
V_39 = V_38 ;
else
V_39 = V_19 / 2 ;
break;
}
default:
{
V_89 = ( T_11 * ) & V_12 [ V_39 ] ;
V_39 += F_31 ( ( V_93 * ) V_89 ) ;
break;
}
}
}
V_39 = 0 ;
V_15 -> V_37 += V_38 ;
V_38 = F_5 ( ( V_15 -> V_13 - V_15 -> V_37 ) ) ;
}while( ( V_38 > 0 ) && ( V_16 = F_11 ( V_12 , V_38 , V_9 -> V_27 ) ) && ( V_16 == V_38 ) );
return FALSE ;
}
static T_8 V_30 ( T_3 * V_9 , int * V_10 , T_4 * * V_11 , T_5 * V_61 )
{
if ( V_9 -> V_20 == V_21 )
return F_21 ( V_9 , V_10 , V_11 , V_61 ) ;
else if ( V_9 -> V_20 == V_24 )
return F_28 ( V_9 , V_10 , V_11 , V_61 ) ;
return FALSE ;
}
static T_8 V_32 ( T_3 * V_9 , T_5 V_97 ,
union V_98 * V_99 , T_14 * V_100 , int V_101 ,
int * V_10 , T_4 * * V_11 )
{
int V_16 ;
* V_10 = 0 ;
if ( F_9 ( V_9 -> V_102 , V_97 , V_28 , V_10 ) == - 1 )
return FALSE ;
V_16 = F_11 ( V_100 , V_101 , V_9 -> V_102 ) ;
if ( V_16 != V_101 ) {
* V_10 = F_10 ( V_9 -> V_102 , V_11 ) ;
if ( * V_10 == 0 )
* V_10 = V_103 ;
return FALSE ;
}
if ( V_9 -> V_20 == V_21 )
{
#define F_32 ( type , T_13 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
TRACE_V##type##_REC_LEN_OFF(v##type##_full,fp,pktracefull_v##type);\
pseudo_header->nstr.rec_type = NSPR_HEADER_VERSION##acttype;\
break;\
#define GENERATE_CASE_PART(type,acttype) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
TRACE_V##type##_REC_LEN_OFF(v##type##_part,pp,pktracepart_v##type);\
pseudo_header->nstr.rec_type = NSPR_HEADER_VERSION##acttype;\
break;\
switch (pletohs(&(( nspr_header_v10_t*)pd)->ph_RecordType))
{
F_32 ( 10 , 100 )
F_33 ( 10 , 100 )
}
} else if ( V_9 -> V_20 == V_24 )
{
#define F_34 ( type , T_13 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
case NSPR_PDPKTRACEFULLNEWRX_V##type:\
TRACE_V##type##_REC_LEN_OFF(v##type##_full,fp,pktracefull_v##type);\
pseudo_header->nstr.rec_type = NSPR_HEADER_VERSION##acttype;\
break;\
#define GENERATE_CASE_PART_V24(type,acttype) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
case NSPR_PDPKTRACEPARTNEWRX_V##type:\
TRACE_V##type##_REC_LEN_OFF(v##type##_part,pp,pktracepart_v##type);\
pseudo_header->nstr.rec_type = NSPR_HEADER_VERSION##acttype;\
break;\
switch ((( nspr_hd_v20_t*)pd)->phd_RecordType)
{
F_32 ( 20 , 200 )
F_33 ( 20 , 200 )
F_32 ( 21 , 201 )
F_33 ( 21 , 201 )
F_32 ( 22 , 202 )
F_33 ( 22 , 202 )
F_32 ( 23 , 203 )
F_33 ( 23 , 203 )
F_34 ( 24 , 204 )
F_35 ( 24 , 204 )
}
}
return TRUE ;
}
static void V_34 ( T_3 * V_9 )
{
T_7 * V_15 = ( T_7 * ) V_9 -> V_35 ;
F_8 ( V_15 -> V_36 ) ;
}
int F_36 ( int V_104 )
{
if ( V_104 == V_23 )
return 0 ;
return V_105 ;
}
int F_37 ( int V_104 )
{
if ( V_104 == V_25 )
return 0 ;
return V_105 ;
}
T_8 F_38 ( T_15 * V_106 , int * V_10 V_107 )
{
T_16 * V_15 ;
V_106 -> V_108 = V_109 ;
V_15 = ( T_16 * ) F_4 ( sizeof( T_16 ) ) ;
V_106 -> V_35 = ( void * ) V_15 ;
V_15 -> V_110 = 0 ;
V_15 -> V_111 = V_19 ;
V_15 -> V_112 = 0 ;
return TRUE ;
}
static T_8 F_39 ( T_15 * V_106 , int * V_10 )
{
T_16 * V_15 = ( T_16 * ) V_106 -> V_35 ;
if ( V_106 -> V_20 == V_21 )
{
T_17 V_113 ;
T_18 V_114 ;
V_113 = F_40 ( V_55 ) ;
memcpy ( V_114 . V_115 . V_116 , & V_113 , sizeof V_114 . V_115 . V_116 ) ;
V_113 = F_40 ( V_117 ) ;
memcpy ( V_114 . V_115 . V_118 , & V_113 , sizeof V_114 . V_115 . V_118 ) ;
memset ( V_114 . V_57 , 0 , V_119 ) ;
F_41 ( V_114 . V_57 , V_52 , V_119 ) ;
if ( ! F_42 ( V_106 , & V_114 , V_117 ,
V_10 ) )
return FALSE ;
V_15 -> V_110 += ( T_17 ) V_117 ;
} else if ( V_106 -> V_20 == V_24 )
{
T_19 V_120 ;
V_120 . V_58 = V_59 ;
V_120 . V_60 = V_121 ;
memcpy ( V_120 . V_57 , V_53 , sizeof( V_53 ) ) ;
if ( ! F_42 ( V_106 , & V_120 , V_120 . V_60 ,
V_10 ) )
return FALSE ;
V_15 -> V_110 += ( T_17 ) V_120 . V_60 ;
} else
{
F_43 () ;
return FALSE ;
}
return TRUE ;
}
static T_8
F_44 ( T_15 * V_106 , const struct V_122 * V_46 ,
const T_14 * V_100 , int * V_10 )
{
T_16 * V_15 = ( T_16 * ) V_106 -> V_35 ;
T_1 V_43 ;
if ( V_106 -> V_20 == V_21 )
{
T_17 V_123 ;
T_2 V_124 ;
T_1 V_125 ;
V_84 V_126 ;
V_123 = F_40 ( V_83 ) ;
memcpy ( V_126 . V_115 . V_116 , & V_123 , sizeof V_126 . V_115 . V_116 ) ;
V_123 = F_40 ( V_127 ) ;
memcpy ( V_126 . V_115 . V_118 , & V_123 , sizeof V_126 . V_115 . V_118 ) ;
memcpy ( & V_124 , ( ( const T_9 * ) V_100 ) -> V_69 , sizeof V_124 ) ;
V_43 = F_1 ( V_124 ) ;
memset ( V_126 . V_86 , 0 , sizeof V_126 . V_86 ) ;
V_125 = F_45 ( ( T_2 ) V_46 -> V_47 . V_48 - ( T_2 ) ( V_43 / 1000000000 ) ) ;
memcpy ( V_126 . V_85 , & V_125 , sizeof V_126 . V_85 ) ;
if ( ! F_42 ( V_106 , & V_126 , V_127 , V_10 ) )
return FALSE ;
V_15 -> V_110 += V_127 ;
} else if ( V_106 -> V_20 == V_24 )
{
T_2 V_124 ;
T_1 V_125 ;
V_94 V_128 ;
V_128 . V_129 = V_92 ;
V_128 . V_130 = V_131 ;
memcpy ( & V_124 , ( ( const T_11 * ) V_100 ) -> V_69 , sizeof V_124 ) ;
V_43 = F_1 ( V_124 ) ;
memset ( V_128 . V_86 , 0 , sizeof V_128 . V_86 ) ;
V_125 = F_45 ( ( T_2 ) V_46 -> V_47 . V_48 - ( T_2 ) ( V_43 / 1000000000 ) ) ;
memcpy ( V_128 . V_86 , & V_125 , sizeof V_128 . V_86 ) ;
if ( ! F_42 ( V_106 , & V_128 , V_131 , V_10 ) )
return FALSE ;
V_15 -> V_110 += V_131 ;
} else
{
F_43 () ;
return FALSE ;
}
return TRUE ;
}
static T_8 V_109 ( T_15 * V_106 , const struct V_122 * V_46 ,
const union V_98 * V_99 , const T_14 * V_100 , int * V_10 )
{
T_16 * V_15 = ( T_16 * ) V_106 -> V_35 ;
if ( V_15 -> V_110 == 0 )
{
if ( V_106 -> V_20 == V_21 )
{
if ( ! F_39 ( V_106 , V_10 ) ||
! F_44 ( V_106 , V_46 , V_100 , V_10 ) )
return FALSE ;
} else if ( V_106 -> V_20 == V_24 )
{
if ( ! F_39 ( V_106 , V_10 ) ||
! F_44 ( V_106 , V_46 , V_100 , V_10 ) )
return FALSE ;
} else
{
F_43 () ;
return FALSE ;
}
}
switch ( V_99 -> V_132 . V_133 )
{
case V_134 :
if ( V_106 -> V_20 == V_21 )
{
if ( V_15 -> V_110 + V_46 -> V_70 >= V_15 -> V_111 )
{
if ( fseek ( V_106 -> V_27 , ( V_15 -> V_111 - V_15 -> V_110 ) , V_135 ) == - 1 )
{
* V_10 = V_17 ;
return FALSE ;
}
V_15 -> V_110 = 0 ;
if ( ! F_39 ( V_106 , V_10 ) )
return FALSE ;
}
if ( ! F_42 ( V_106 , V_100 , V_46 -> V_70 , V_10 ) )
return FALSE ;
V_15 -> V_110 += ( T_17 ) V_46 -> V_70 ;
} else if ( V_106 -> V_20 == V_24 )
{
* V_10 = V_136 ;
return FALSE ;
}
break;
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
if ( V_106 -> V_20 == V_21 )
{
* V_10 = V_136 ;
return FALSE ;
} else if ( V_106 -> V_20 == V_24 )
{
if ( V_15 -> V_110 + V_46 -> V_70 >= V_15 -> V_111 )
{
if ( fseek ( V_106 -> V_27 , ( V_15 -> V_111 - V_15 -> V_110 ) , V_135 ) == - 1 )
{
* V_10 = V_17 ;
return FALSE ;
}
V_15 -> V_110 = 0 ;
if ( ! F_39 ( V_106 , V_10 ) )
return FALSE ;
}
if ( ! F_42 ( V_106 , V_100 , V_46 -> V_70 , V_10 ) )
return FALSE ;
V_15 -> V_110 += ( T_17 ) V_46 -> V_70 ;
}
break;
default:
F_43 () ;
return FALSE ;
}
return TRUE ;
}
