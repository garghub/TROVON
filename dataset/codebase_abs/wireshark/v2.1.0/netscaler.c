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
T_3 F_2 ( T_4 * V_9 , int * V_10 , T_5 * * V_11 )
{
T_5 * V_12 ;
T_6 V_13 ;
T_7 V_14 ;
T_8 * V_15 ;
if ( ( V_13 = F_3 ( V_9 , V_10 ) ) == - 1 )
return V_16 ;
V_12 = ( T_5 * ) F_4 ( V_17 ) ;
V_14 = F_5 ( V_13 ) ;
switch ( ( V_9 -> V_18 = F_6 ( V_9 , V_12 , V_14 ) ) )
{
case V_19 :
V_9 -> V_20 = V_21 ;
break;
case V_22 :
V_9 -> V_20 = V_23 ;
break;
case V_24 :
V_9 -> V_20 = V_25 ;
F_7 ( V_12 ) ;
V_12 = ( T_5 * ) F_4 ( V_26 ) ;
V_14 = F_8 ( V_13 ) ;
break;
case V_27 :
V_9 -> V_20 = V_28 ;
F_7 ( V_12 ) ;
V_12 = ( T_5 * ) F_4 ( V_26 ) ;
V_14 = F_8 ( V_13 ) ;
break;
default:
F_7 ( V_12 ) ;
return V_16 ;
}
if ( ( F_9 ( V_9 -> V_29 , 0 , V_30 , V_10 ) ) == - 1 )
{
F_7 ( V_12 ) ;
return V_31 ;
}
if ( ! F_10 ( V_9 -> V_29 , V_12 , V_14 , V_10 , V_11 ) )
{
F_7 ( V_12 ) ;
if ( * V_10 != V_32 )
return V_31 ;
return V_16 ;
}
switch ( V_9 -> V_18 )
{
case V_19 :
V_9 -> V_33 = V_34 ;
V_9 -> V_35 = V_36 ;
break;
case V_22 :
V_9 -> V_33 = V_37 ;
V_9 -> V_35 = V_38 ;
break;
case V_24 :
V_9 -> V_33 = V_39 ;
V_9 -> V_35 = V_40 ;
break;
case V_27 :
V_9 -> V_33 = V_39 ;
V_9 -> V_35 = V_40 ;
break;
}
V_9 -> V_41 = V_42 ;
V_15 = ( T_8 * ) F_4 ( sizeof( T_8 ) ) ;
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
if ( ( F_11 ( V_9 ) ) == FALSE )
{
if ( ( F_9 ( V_9 -> V_29 , 0 , V_30 , V_10 ) ) == - 1 )
{
F_7 ( V_15 -> V_44 ) ;
F_7 ( V_15 ) ;
return V_31 ;
}
if ( ! F_10 ( V_9 -> V_29 , V_12 , V_14 , V_10 , V_11 ) )
{
F_7 ( V_15 -> V_44 ) ;
F_7 ( V_15 ) ;
return V_31 ;
}
V_15 -> V_47 = 0 ;
}
V_9 -> V_52 = V_53 ;
V_9 -> V_54 . V_55 . V_56 = V_15 -> V_48 ;
V_9 -> V_54 . V_55 . V_57 = 0 ;
* V_10 = 0 ;
return V_58 ;
}
static T_2
F_6 ( T_4 * V_9 , T_5 * V_12 , T_7 V_59 )
{
T_5 * V_60 = V_12 ;
int V_61 ;
V_61 = F_12 ( V_60 , V_59 , V_9 -> V_29 ) ;
if ( V_61 == V_59 ) {
for ( ; V_59 > ( T_7 ) ( F_13 ( sizeof( V_62 ) , sizeof( V_63 ) ) ) ; V_60 ++ , V_59 -- )
{
#define F_14 ((nspr_signature_v10_t*)dp)
if ( ( F_15 ( & F_14 -> V_64 ) == V_65 ) &&
( F_15 ( & F_14 -> V_66 ) <= V_59 ) &&
( ( T_7 ) sizeof( V_62 ) <= V_59 ) &&
( ! F_16 ( F_14 -> V_67 ) ) )
return V_19 ;
#undef F_14
#define F_17 ((nspr_signature_v20_t*)dp)
if ( ( F_17 -> V_68 == V_69 ) &&
( F_17 -> V_70 <= V_59 ) &&
( ( T_7 ) sizeof( V_63 ) <= V_59 ) )
{
if ( ! F_18 ( F_17 -> V_67 ) ) {
return V_22 ;
} else if ( ! F_19 ( F_17 -> V_67 ) ) {
return V_24 ;
} else if ( ! F_20 ( F_17 -> V_67 ) ) {
return V_27 ;
}
}
#undef F_17
}
}
return V_71 ;
}
static T_9 F_11 ( T_4 * V_9 )
{
if ( V_9 -> V_18 == V_19 )
return F_21 ( V_9 ) ;
else if ( V_9 -> V_18 == V_22 )
return F_22 ( V_9 ) ;
else if ( V_9 -> V_18 == V_24 )
return F_22 ( V_9 ) ;
return FALSE ;
}
static T_9 V_34 ( T_4 * V_9 , int * V_10 , T_5 * * V_11 , T_6 * V_72 )
{
T_8 * V_15 = ( T_8 * ) V_9 -> V_43 ;
T_1 V_51 = V_15 -> V_51 ;
T_5 * V_12 = V_15 -> V_44 ;
T_7 V_47 = V_15 -> V_47 ;
T_7 V_46 = V_15 -> V_46 ;
int V_61 ;
* V_10 = 0 ;
* V_11 = NULL ;
do
{
while ( ( V_47 < V_46 ) &&
( ( V_46 - V_47 ) >= ( ( T_7 ) sizeof( ( ( V_73 * ) & V_12 [ V_47 ] ) -> V_74 ) ) ) )
{
#define F_23 ( V_54 , T_10 , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,full,ver,fp,HEADERVER);
#define F_24 ( V_54 , T_10 , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##ver:\
case NSPR_PDPKTRACEPARTTXB_V##ver:\
case NSPR_PDPKTRACEPARTRX_V##ver:\
PACKET_DESCRIBE(phdr,PART,part,ver,pp,HEADERVER);
switch ( F_15 ( & ( ( V_73 * ) & V_12 [ V_47 ] ) -> V_74 ) )
{
F_23 (&wth->phdr, 10 , 100 )
F_24 (&wth->phdr, 10 , 100 )
#undef F_23
#undef F_24
case V_75 :
{
T_12 * V_76 = ( T_12 * ) & V_12 [ V_47 ] ;
F_25 ( V_15 , F_26 ( ( ( V_77 * ) V_76 ) -> V_78 ) , F_26 ( & ( ( V_77 * ) V_76 ) -> V_79 ) ) ;
V_47 += F_15 ( & V_76 -> V_66 ) ;
break;
}
case V_80 :
{
T_12 * V_76 = ( T_12 * ) & V_12 [ V_47 ] ;
F_27 ( V_15 , F_26 ( ( ( V_77 * ) V_76 ) -> V_79 ) ) ;
V_47 += F_15 ( & V_76 -> V_66 ) ;
break;
}
case V_81 :
V_47 = V_46 ;
break;
default:
{
T_12 * V_76 = ( T_12 * ) & V_12 [ V_47 ] ;
V_47 += F_15 ( & V_76 -> V_66 ) ;
break;
}
}
}
V_47 = 0 ;
V_15 -> V_45 += V_46 ;
V_46 = F_5 ( ( V_15 -> V_13 - V_15 -> V_45 ) ) ;
}while( ( V_46 > 0 ) && ( V_61 = F_12 ( V_12 , V_46 , V_9 -> V_29 ) ) && ( V_61 == V_46 ) );
return FALSE ;
}
static T_9 V_37 ( T_4 * V_9 , int * V_10 , T_5 * * V_11 , T_6 * V_72 )
{
T_8 * V_15 = ( T_8 * ) V_9 -> V_43 ;
T_1 V_51 = V_15 -> V_51 ;
T_5 * V_12 = V_15 -> V_44 ;
T_7 V_47 = V_15 -> V_47 ;
T_7 V_46 = V_15 -> V_46 ;
int V_61 ;
* V_10 = 0 ;
* V_11 = NULL ;
do
{
while ( ( V_47 < V_46 ) &&
( ( V_46 - V_47 ) >= ( ( T_7 ) sizeof( ( ( V_82 * ) & V_12 [ V_47 ] ) -> V_83 ) ) ) )
{
switch ( ( ( V_82 * ) & V_12 [ V_47 ] ) -> V_83 )
{
#define F_23 ( V_54 , T_10 , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
#define F_28 ( V_54 , T_10 , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
case NSPR_PDPKTRACEFULLNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
#define F_24 ( V_54 , T_10 , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##ver:\
case NSPR_PDPKTRACEPARTTXB_V##ver:\
case NSPR_PDPKTRACEPARTRX_V##ver:\
PACKET_DESCRIBE(phdr,PART,ver,v##ver##_part,pp,pktracepart_v##ver,HEADERVER);
#define F_29 ( V_54 , T_10 , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##ver:\
case NSPR_PDPKTRACEPARTTXB_V##ver:\
case NSPR_PDPKTRACEPARTRX_V##ver:\
case NSPR_PDPKTRACEPARTNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,PART,ver,v##ver##_part,pp,pktracepart_v##ver,HEADERVER);
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
case V_84 :
{
T_13 * V_85 = ( T_13 * ) & V_12 [ V_47 ] ;
V_47 += F_30 ( ( V_82 * ) V_85 ) ;
F_25 ( V_15 , F_26 ( & ( ( V_86 * ) V_85 ) -> V_78 ) , F_15 ( & ( ( V_86 * ) V_85 ) -> V_79 ) ) ;
break;
}
case V_87 :
{
T_13 * V_85 = ( T_13 * ) & V_12 [ V_47 ] ;
F_27 ( V_15 , F_15 ( & ( ( V_86 * ) V_85 ) -> V_79 ) ) ;
V_47 += F_30 ( ( V_82 * ) V_85 ) ;
break;
}
case V_88 :
{
if ( V_47 >= V_17 / 2 )
V_47 = V_46 ;
else
V_47 = V_17 / 2 ;
break;
}
default:
{
T_13 * V_85 = ( T_13 * ) & V_12 [ V_47 ] ;
V_47 += F_30 ( ( V_82 * ) V_85 ) ;
break;
}
}
}
V_47 = 0 ;
V_15 -> V_45 += V_46 ;
V_46 = F_5 ( ( V_15 -> V_13 - V_15 -> V_45 ) ) ;
}while( ( V_46 > 0 ) && ( V_61 = F_12 ( V_12 , V_46 , V_9 -> V_29 ) ) && ( V_61 == V_46 ) );
return FALSE ;
}
static T_9 V_39 ( T_4 * V_9 , int * V_10 , T_5 * * V_11 , T_6 * V_72 )
{
T_8 * V_15 = ( T_8 * ) V_9 -> V_43 ;
T_1 V_51 ;
T_5 * V_12 = V_15 -> V_44 ;
T_7 V_47 = V_15 -> V_47 ;
T_7 V_46 = V_15 -> V_46 ;
T_14 V_89 [ 65536 ] ;
T_2 V_90 = 0 , V_91 = 0 , V_92 = 0 , V_93 = 0 ;
V_82 * V_94 ;
int V_61 = 0 ;
* V_10 = 0 ;
* V_11 = NULL ;
if( V_46 == 0 ) {
return FALSE ;
}
do
{
if ( ! V_12 [ V_47 ] && V_47 <= V_26 ) {
V_47 = V_26 ;
}
if( F_31 ( V_9 -> V_29 ) && V_61 > 0 ) {
memset ( & V_12 [ V_61 ] , 0 , V_26 - V_61 ) ;
}
while ( ( V_47 < V_26 ) &&
V_12 [ V_47 ] )
{
V_94 = ( V_82 * ) & V_12 [ V_47 ] ;
if( F_30 ( V_94 ) == 0 ) {
* V_10 = V_95 ;
* V_11 = F_32 ( L_1 ) ;
return FALSE ;
}
switch ( V_94 -> V_83 )
{
#define F_33 ( V_54 , T_10 , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
case NSPR_PDPKTRACEFULLNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
F_33 ( & V_9 -> V_54 , 30 , 300 ) ;
#undef F_33
#define F_34 ( V_54 , T_10 , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
case NSPR_PDPKTRACEFULLNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
F_34 ( & V_9 -> V_54 , 35 , 350 ) ;
#undef F_34
case V_84 :
{
V_47 += F_30 ( V_94 ) ;
F_25 ( V_15 , F_26 ( & ( ( V_86 * ) & V_12 [ V_47 ] ) -> V_78 ) , F_15 ( & ( ( V_86 * ) & V_12 [ V_47 ] ) -> V_79 ) ) ;
break;
}
case V_87 :
{
F_27 ( V_15 , F_15 ( & ( ( V_86 * ) & V_12 [ V_47 ] ) -> V_79 ) ) ;
V_47 += F_30 ( V_94 ) ;
break;
}
default:
{
V_47 += F_30 ( V_94 ) ;
break;
}
}
}
V_47 = 0 ;
V_15 -> V_45 += V_46 ;
V_46 = V_26 ;
} while( ( V_46 > 0 ) && ( V_61 = F_12 ( V_12 , V_46 , V_9 -> V_29 ) ) && ( F_31 ( V_9 -> V_29 ) || V_61 == V_46 ) );
return FALSE ;
}
static T_9 V_36 ( T_4 * V_9 , T_6 V_96 ,
struct V_97 * V_54 , T_15 * V_98 , int * V_10 , T_5 * * V_11 )
{
T_16 V_99 ;
T_17 V_100 ;
T_14 * V_101 ;
unsigned int V_102 ;
* V_10 = 0 ;
if ( F_9 ( V_9 -> V_103 , V_96 , V_30 , V_10 ) == - 1 )
return FALSE ;
if ( ! F_10 ( V_9 -> V_103 , ( void * ) & V_99 , sizeof V_99 ,
V_10 , V_11 ) )
return FALSE ;
V_100 = F_35 ( & V_99 ) ;
F_36 ( V_98 , V_100 ) ;
V_101 = F_37 ( V_98 ) ;
memcpy ( V_101 , ( void * ) & V_99 , sizeof V_99 ) ;
if ( V_100 > sizeof V_99 ) {
V_102 = ( unsigned int ) ( V_100 - sizeof V_99 ) ;
if ( ! F_10 ( V_9 -> V_103 , V_101 + sizeof V_99 , V_102 ,
V_10 , V_11 ) )
return FALSE ;
}
#define F_23 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
PACKET_DESCRIBE(phdr,FULL,full,type,fp,HEADERVER);\
break;
#define F_24 ( V_54 , type , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
PACKET_DESCRIBE(phdr,PART,part,type,pp,HEADERVER);\
break;
switch ( F_15 ( & ( ( V_73 * ) V_101 ) -> V_74 ) )
{
F_23 (phdr, 10 , 100 )
F_24 (phdr, 10 , 100 )
}
#undef F_23
#undef F_24
return TRUE ;
}
static T_9 V_38 ( T_4 * V_9 , T_6 V_96 ,
struct V_97 * V_54 , T_15 * V_98 , int * V_10 , T_5 * * V_11 )
{
V_82 V_99 ;
T_17 V_100 ;
T_17 V_104 ;
T_14 * V_101 ;
unsigned int V_102 ;
T_1 V_51 ;
* V_10 = 0 ;
if ( F_9 ( V_9 -> V_103 , V_96 , V_30 , V_10 ) == - 1 )
return FALSE ;
if ( ! F_10 ( V_9 -> V_103 , ( void * ) & V_99 , 2 , V_10 , V_11 ) )
return FALSE ;
V_104 = 2 ;
if ( V_99 . V_105 & V_106 ) {
if ( ! F_10 ( V_9 -> V_103 , ( void * ) & V_99 . V_107 , 1 ,
V_10 , V_11 ) )
return FALSE ;
V_104 = 3 ;
}
V_100 = F_30 ( & V_99 ) ;
F_36 ( V_98 , V_100 ) ;
V_101 = F_37 ( V_98 ) ;
memcpy ( V_101 , ( void * ) & V_99 , V_104 ) ;
if ( V_100 > V_104 ) {
V_102 = ( unsigned int ) ( V_100 - V_104 ) ;
if ( ! F_10 ( V_9 -> V_103 , V_101 + V_104 , V_102 ,
V_10 , V_11 ) )
return FALSE ;
}
#define F_23 ( V_54 , T_10 , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
#define F_28 ( V_54 , T_10 , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
case NSPR_PDPKTRACEFULLNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
#define F_24 ( V_54 , T_10 , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##ver:\
case NSPR_PDPKTRACEPARTTXB_V##ver:\
case NSPR_PDPKTRACEPARTRX_V##ver:\
PACKET_DESCRIBE(phdr,PART,ver,v##ver##_part,pp,pktracepart_v##ver,HEADERVER);
#define F_29 ( V_54 , T_10 , T_11 ) \
case NSPR_PDPKTRACEPARTTX_V##ver:\
case NSPR_PDPKTRACEPARTTXB_V##ver:\
case NSPR_PDPKTRACEPARTRX_V##ver:\
case NSPR_PDPKTRACEPARTNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,PART,ver,v##ver##_part,pp,pktracepart_v##ver,HEADERVER);
switch ( ( ( V_82 * ) V_101 ) -> V_83 )
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
static T_9 V_40 ( T_4 * V_9 , T_6 V_96 ,
struct V_97 * V_54 , T_15 * V_98 , int * V_10 , T_5 * * V_11 )
{
V_82 V_99 ;
T_17 V_100 ;
T_17 V_104 ;
T_14 * V_101 ;
unsigned int V_102 ;
T_1 V_51 ;
* V_10 = 0 ;
if ( F_9 ( V_9 -> V_103 , V_96 , V_30 , V_10 ) == - 1 )
return FALSE ;
if ( ! F_10 ( V_9 -> V_103 , ( void * ) & V_99 , 2 , V_10 , V_11 ) )
return FALSE ;
V_104 = 2 ;
if ( V_99 . V_105 & V_106 ) {
if ( ! F_10 ( V_9 -> V_103 , ( void * ) & V_99 . V_107 , 1 ,
V_10 , V_11 ) )
return FALSE ;
V_104 = 3 ;
}
V_100 = F_30 ( & V_99 ) ;
F_36 ( V_98 , V_100 ) ;
V_101 = F_37 ( V_98 ) ;
memcpy ( V_101 , ( void * ) & V_99 , V_104 ) ;
if ( V_100 > V_104 ) {
V_102 = ( unsigned int ) ( V_100 - V_104 ) ;
if ( ! F_10 ( V_9 -> V_103 , V_101 + V_104 , V_102 ,
V_10 , V_11 ) )
return FALSE ;
}
( V_54 ) -> V_108 = ( V_54 ) -> V_59 = V_100 ;
#define F_38 ( V_54 , T_10 , T_11 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
case NSPR_PDPKTRACEFULLNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
switch ( ( ( V_82 * ) V_101 ) -> V_83 )
{
F_38 ( V_54 , 30 , 300 ) ;
F_38 ( V_54 , 35 , 350 ) ;
}
return TRUE ;
}
static void V_42 ( T_4 * V_9 )
{
T_8 * V_15 = ( T_8 * ) V_9 -> V_43 ;
F_7 ( V_15 -> V_44 ) ;
}
int F_39 ( int V_109 )
{
if ( V_109 == V_21 )
return 0 ;
return V_110 ;
}
int F_40 ( int V_109 )
{
if ( V_109 == V_23 )
return 0 ;
return V_110 ;
}
int F_41 ( int V_109 )
{
if ( V_109 == V_25 )
return 0 ;
return V_110 ;
}
int F_42 ( int V_109 )
{
if ( V_109 == V_28 )
return 0 ;
return V_110 ;
}
T_9 F_43 ( T_18 * V_111 , int * V_10 V_112 )
{
T_19 * V_15 ;
V_111 -> V_113 = V_114 ;
V_15 = ( T_19 * ) F_4 ( sizeof( T_19 ) ) ;
V_111 -> V_43 = ( void * ) V_15 ;
V_15 -> V_115 = 0 ;
if ( ( V_111 -> V_18 == V_24 ) ||
( V_111 -> V_18 == V_27 ) )
V_15 -> V_116 = V_26 ;
else
V_15 -> V_116 = V_17 ;
V_15 -> V_117 = 0 ;
V_15 -> V_118 = TRUE ;
return TRUE ;
}
static T_9 F_44 ( T_18 * V_111 , int * V_10 )
{
T_19 * V_15 = ( T_19 * ) V_111 -> V_43 ;
if ( V_111 -> V_18 == V_19 )
{
T_20 V_119 ;
T_21 V_120 ;
V_119 = F_45 ( V_65 ) ;
memcpy ( V_120 . V_121 . V_74 , & V_119 , sizeof V_120 . V_121 . V_74 ) ;
V_119 = F_45 ( V_122 ) ;
memcpy ( V_120 . V_121 . V_123 , & V_119 , sizeof V_120 . V_121 . V_123 ) ;
memset ( V_120 . V_67 , 0 , V_124 ) ;
F_46 ( V_120 . V_67 , V_62 , V_124 ) ;
if ( ! F_47 ( V_111 , & V_120 , V_122 ,
V_10 ) )
return FALSE ;
V_15 -> V_115 += ( T_20 ) V_122 ;
} else if ( V_111 -> V_18 == V_22 )
{
T_22 V_125 ;
V_125 . V_68 = V_69 ;
V_125 . V_70 = V_126 ;
memcpy ( V_125 . V_67 , V_63 , sizeof( V_63 ) ) ;
if ( ! F_47 ( V_111 , & V_125 , V_125 . V_70 ,
V_10 ) )
return FALSE ;
V_15 -> V_115 += ( T_20 ) V_125 . V_70 ;
} else if ( V_111 -> V_18 == V_24 )
{
T_23 V_127 ;
V_127 . V_68 = V_128 ;
V_127 . V_70 = V_129 ;
memcpy ( V_127 . V_67 , V_130 , sizeof( V_130 ) ) ;
if ( ! F_47 ( V_111 , & V_127 , V_127 . V_70 ,
V_10 ) )
return FALSE ;
V_15 -> V_115 += ( T_20 ) V_127 . V_70 ;
} else if ( V_111 -> V_18 == V_27 )
{
T_24 V_131 ;
V_131 . V_68 = V_132 ;
V_131 . V_70 = V_133 ;
memcpy ( V_131 . V_67 , V_134 , sizeof( V_134 ) ) ;
if ( ! F_47 ( V_111 , & V_131 , V_131 . V_70 ,
V_10 ) )
return FALSE ;
V_15 -> V_115 += ( T_20 ) V_131 . V_70 ;
} else
{
F_48 () ;
return FALSE ;
}
return TRUE ;
}
static T_9
F_49 ( T_18 * V_111 , const struct V_97 * V_54 ,
const T_14 * V_101 , int * V_10 )
{
T_19 * V_15 = ( T_19 * ) V_111 -> V_43 ;
T_1 V_51 ;
if ( V_111 -> V_18 == V_19 )
{
T_20 V_135 ;
T_2 V_136 ;
T_1 V_137 ;
V_77 V_138 ;
V_135 = F_45 ( V_75 ) ;
memcpy ( V_138 . V_121 . V_74 , & V_135 , sizeof V_138 . V_121 . V_74 ) ;
V_135 = F_45 ( V_139 ) ;
memcpy ( V_138 . V_121 . V_123 , & V_135 , sizeof V_138 . V_121 . V_123 ) ;
memcpy ( & V_136 , ( ( const T_12 * ) V_101 ) -> V_140 , sizeof V_136 ) ;
V_51 = F_1 ( V_136 ) ;
memset ( V_138 . V_79 , 0 , sizeof V_138 . V_79 ) ;
V_137 = F_50 ( ( T_2 ) V_54 -> V_55 . V_56 - ( T_2 ) ( V_51 / 1000000000 ) ) ;
memcpy ( V_138 . V_78 , & V_137 , sizeof V_138 . V_78 ) ;
if ( ! F_47 ( V_111 , & V_138 , V_139 , V_10 ) )
return FALSE ;
V_15 -> V_115 += V_139 ;
} else if ( ( V_111 -> V_18 == V_22 ) ||
( V_111 -> V_18 == V_24 ) ||
( V_111 -> V_18 == V_27 ) ) {
T_2 V_136 ;
T_1 V_137 ;
V_86 V_141 ;
V_141 . V_142 = V_84 ;
V_141 . V_143 = V_144 ;
memcpy ( & V_136 , ( ( const T_13 * ) V_101 ) -> V_140 , sizeof V_136 ) ;
V_51 = F_1 ( V_136 ) ;
memset ( V_141 . V_79 , 0 , sizeof V_141 . V_79 ) ;
V_137 = F_50 ( ( T_2 ) V_54 -> V_55 . V_56 - ( T_2 ) ( V_51 / 1000000000 ) ) ;
memcpy ( V_141 . V_79 , & V_137 , sizeof V_141 . V_79 ) ;
if ( ! F_47 ( V_111 , & V_141 , V_144 , V_10 ) )
return FALSE ;
V_15 -> V_115 += V_144 ;
} else
{
F_48 () ;
return FALSE ;
}
return TRUE ;
}
static T_9 V_114 ( T_18 * V_111 , const struct V_97 * V_54 ,
const T_14 * V_101 , int * V_10 , T_5 * * V_11 V_112 )
{
T_19 * V_15 = ( T_19 * ) V_111 -> V_43 ;
if ( V_54 -> V_145 != V_146 ) {
* V_10 = V_147 ;
return FALSE ;
}
if ( V_15 -> V_118 == TRUE )
{
V_15 -> V_118 = FALSE ;
if ( V_111 -> V_18 == V_19 )
{
if ( ! F_44 ( V_111 , V_10 ) ||
! F_49 ( V_111 , V_54 , V_101 , V_10 ) )
return FALSE ;
} else if ( V_111 -> V_18 == V_22 )
{
if ( ! F_44 ( V_111 , V_10 ) ||
! F_49 ( V_111 , V_54 , V_101 , V_10 ) )
return FALSE ;
} else if ( V_111 -> V_18 == V_24 ||
V_111 -> V_18 == V_27 )
{
if ( ! F_44 ( V_111 , V_10 ) ||
! F_49 ( V_111 , V_54 , V_101 , V_10 ) )
return FALSE ;
} else
{
F_48 () ;
return FALSE ;
}
}
switch ( V_54 -> V_148 . V_149 . V_145 )
{
case V_150 :
if ( V_111 -> V_18 == V_19 )
{
if ( V_15 -> V_115 + V_54 -> V_108 >= V_15 -> V_116 )
{
if ( F_51 ( V_111 , ( V_15 -> V_116 - V_15 -> V_115 ) , V_151 , V_10 ) == - 1 )
return FALSE ;
V_15 -> V_115 = 0 ;
if ( ! F_44 ( V_111 , V_10 ) )
return FALSE ;
}
if ( ! F_47 ( V_111 , V_101 , V_54 -> V_108 , V_10 ) )
return FALSE ;
V_15 -> V_115 += ( T_20 ) V_54 -> V_108 ;
} else if ( V_111 -> V_18 == V_22 )
{
* V_10 = V_152 ;
return FALSE ;
}
break;
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
if ( V_111 -> V_18 == V_19 )
{
* V_10 = V_152 ;
return FALSE ;
} else if ( V_111 -> V_18 == V_22 )
{
if ( V_15 -> V_115 + V_54 -> V_108 >= V_15 -> V_116 )
{
if ( F_51 ( V_111 , ( V_15 -> V_116 - V_15 -> V_115 ) , V_151 , V_10 ) == - 1 )
return FALSE ;
V_15 -> V_115 = 0 ;
if ( ! F_44 ( V_111 , V_10 ) )
return FALSE ;
}
if ( ! F_47 ( V_111 , V_101 , V_54 -> V_108 , V_10 ) )
return FALSE ;
V_15 -> V_115 += ( T_20 ) V_54 -> V_108 ;
}
break;
case V_160 :
case V_161 :
if ( V_111 -> V_18 == V_19 )
{
* V_10 = V_152 ;
return FALSE ;
} else if ( V_111 -> V_18 == V_22 )
{
* V_10 = V_152 ;
return FALSE ;
} else if ( V_111 -> V_18 == V_24 || V_111 -> V_18 == V_27 )
{
if ( V_15 -> V_115 + V_54 -> V_108 >= V_15 -> V_116 )
{
if ( F_51 ( V_111 , ( V_15 -> V_116 - V_15 -> V_115 ) , V_151 , V_10 ) == - 1 )
return FALSE ;
V_15 -> V_115 = 0 ;
if ( ! F_44 ( V_111 , V_10 ) )
return FALSE ;
}
if ( ! F_47 ( V_111 , V_101 , V_54 -> V_108 , V_10 ) )
return FALSE ;
V_15 -> V_115 += ( T_20 ) V_54 -> V_108 ;
} else
{
F_48 () ;
return FALSE ;
}
break;
default:
F_48 () ;
return FALSE ;
}
return TRUE ;
}
