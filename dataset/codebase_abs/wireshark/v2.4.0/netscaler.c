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
static T_3
F_2 ( T_4 V_9 , void * V_10 , T_2 V_11 , int * V_12 ,
T_5 * * V_13 )
{
int V_14 ;
V_14 = F_3 ( V_10 , V_11 , V_9 ) ;
if ( V_14 < 0 ) {
* V_12 = F_4 ( V_9 , V_13 ) ;
return FALSE ;
}
if ( ( T_2 ) V_14 != V_11 ) {
* V_12 = 0 ;
return FALSE ;
}
return TRUE ;
}
T_6 F_5 ( T_7 * V_15 , int * V_12 , T_5 * * V_13 )
{
T_5 * V_16 ;
T_8 V_17 ;
T_9 V_18 ;
T_10 * V_19 ;
if ( ( V_17 = F_6 ( V_15 , V_12 ) ) == - 1 )
return V_20 ;
V_16 = ( T_5 * ) F_7 ( V_21 ) ;
V_18 = F_8 ( V_17 ) ;
switch ( ( V_15 -> V_22 = F_9 ( V_15 , V_16 , V_18 ) ) )
{
case V_23 :
V_15 -> V_24 = V_25 ;
break;
case V_26 :
V_15 -> V_24 = V_27 ;
break;
case V_28 :
V_15 -> V_24 = V_29 ;
F_10 ( V_16 ) ;
V_16 = ( T_5 * ) F_7 ( V_30 ) ;
V_18 = F_11 ( V_17 ) ;
break;
case V_31 :
V_15 -> V_24 = V_32 ;
F_10 ( V_16 ) ;
V_16 = ( T_5 * ) F_7 ( V_30 ) ;
V_18 = F_11 ( V_17 ) ;
break;
default:
F_10 ( V_16 ) ;
return V_20 ;
}
if ( ( F_12 ( V_15 -> V_9 , 0 , V_33 , V_12 ) ) == - 1 )
{
F_10 ( V_16 ) ;
return V_34 ;
}
if ( ! F_13 ( V_15 -> V_9 , V_16 , V_18 , V_12 , V_13 ) )
{
F_10 ( V_16 ) ;
if ( * V_12 != V_35 )
return V_34 ;
return V_20 ;
}
switch ( V_15 -> V_22 )
{
case V_23 :
V_15 -> V_36 = V_37 ;
V_15 -> V_38 = V_39 ;
break;
case V_26 :
V_15 -> V_36 = V_40 ;
V_15 -> V_38 = V_41 ;
break;
case V_28 :
V_15 -> V_36 = V_42 ;
V_15 -> V_38 = V_43 ;
break;
case V_31 :
V_15 -> V_36 = V_42 ;
V_15 -> V_38 = V_43 ;
break;
}
V_15 -> V_44 = V_45 ;
V_19 = ( T_10 * ) F_7 ( sizeof( T_10 ) ) ;
V_15 -> V_46 = ( void * ) V_19 ;
V_19 -> V_47 = V_16 ;
V_19 -> V_48 = 0 ;
V_19 -> V_49 = V_18 ;
V_19 -> V_50 = 0 ;
V_19 -> V_51 = 0 ;
V_19 -> V_52 = 0 ;
V_19 -> V_53 = 0 ;
V_19 -> V_54 = 0 ;
V_19 -> V_17 = V_17 ;
if ( ( F_14 ( V_15 , V_12 , V_13 ) ) == FALSE )
{
if ( * V_12 != 0 )
{
return V_34 ;
}
if ( ( F_12 ( V_15 -> V_9 , 0 , V_33 , V_12 ) ) == - 1 )
{
return V_34 ;
}
if ( ! F_13 ( V_15 -> V_9 , V_16 , V_18 , V_12 , V_13 ) )
{
return V_34 ;
}
V_19 -> V_50 = 0 ;
}
V_15 -> V_55 = V_56 ;
V_15 -> V_57 . V_58 . V_59 = V_19 -> V_51 ;
V_15 -> V_57 . V_58 . V_60 = 0 ;
* V_12 = 0 ;
return V_61 ;
}
static T_2
F_9 ( T_7 * V_15 , T_5 * V_16 , T_9 V_62 )
{
T_5 * V_63 = V_16 ;
int V_14 ;
V_14 = F_3 ( V_63 , V_62 , V_15 -> V_9 ) ;
if ( V_14 == V_62 ) {
for ( ; V_62 > ( T_9 ) ( F_15 ( sizeof( V_64 ) , sizeof( V_65 ) ) ) ; V_63 ++ , V_62 -- )
{
#define F_16 ((nspr_signature_v10_t*)dp)
if ( ( F_17 ( & F_16 -> V_66 ) == V_67 ) &&
( F_17 ( & F_16 -> V_68 ) <= V_62 ) &&
( ( T_9 ) sizeof( V_64 ) <= V_62 ) &&
( ! F_18 ( F_16 -> V_69 ) ) )
return V_23 ;
#undef F_16
#define F_19 ((nspr_signature_v20_t*)dp)
if ( ( F_19 -> V_70 == V_71 ) &&
( F_19 -> V_72 <= V_62 ) &&
( ( T_9 ) sizeof( V_65 ) <= V_62 ) )
{
if ( ! F_20 ( F_19 -> V_69 ) ) {
return V_26 ;
} else if ( ! F_21 ( F_19 -> V_69 ) ) {
return V_28 ;
} else if ( ! F_22 ( F_19 -> V_69 ) ) {
return V_31 ;
}
}
#undef F_19
}
}
return V_73 ;
}
static T_3 F_14 ( T_7 * V_15 , int * V_12 , T_5 * * V_13 )
{
if ( V_15 -> V_22 == V_23 )
return F_23 ( V_15 , V_12 , V_13 ) ;
else if ( V_15 -> V_22 == V_26 )
return F_24 ( V_15 , V_12 , V_13 ) ;
else if ( V_15 -> V_22 == V_28 )
return F_24 ( V_15 , V_12 , V_13 ) ;
return FALSE ;
}
static T_3 V_37 ( T_7 * V_15 , int * V_12 , T_5 * * V_13 , T_8 * V_74 )
{
T_10 * V_19 = ( T_10 * ) V_15 -> V_46 ;
T_1 V_54 = V_19 -> V_54 ;
T_5 * V_16 = V_19 -> V_47 ;
T_2 V_50 = V_19 -> V_50 ;
T_2 V_49 = V_19 -> V_49 ;
* V_12 = 0 ;
* V_13 = NULL ;
do
{
while ( ( V_50 < V_49 ) &&
( ( V_49 - V_50 ) >= ( ( T_9 ) sizeof( ( ( V_75 * ) & V_16 [ V_50 ] ) -> V_76 ) ) ) )
{
#define F_25 ( V_57 , T_11 , T_12 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,full,ver,fp,HEADERVER);
#define F_26 ( V_57 , T_11 , T_12 ) \
case NSPR_PDPKTRACEPARTTX_V##ver:\
case NSPR_PDPKTRACEPARTTXB_V##ver:\
case NSPR_PDPKTRACEPARTRX_V##ver:\
PACKET_DESCRIBE(phdr,PART,part,ver,pp,HEADERVER);
switch ( F_17 ( & ( ( V_75 * ) & V_16 [ V_50 ] ) -> V_76 ) )
{
F_25 (&wth->phdr, 10 , 100 )
F_26 (&wth->phdr, 10 , 100 )
#undef F_25
#undef F_26
case V_77 :
{
T_13 * V_78 = ( T_13 * ) & V_16 [ V_50 ] ;
if ( F_17 ( & V_78 -> V_68 ) == 0 ) {
* V_12 = V_79 ;
* V_13 = F_27 ( L_1 ) ;
return FALSE ;
}
F_28 ( V_19 , F_29 ( ( ( V_80 * ) V_78 ) -> V_81 ) , F_29 ( & ( ( V_80 * ) V_78 ) -> V_82 ) ) ;
V_50 += F_17 ( & V_78 -> V_68 ) ;
break;
}
case V_83 :
{
T_13 * V_78 = ( T_13 * ) & V_16 [ V_50 ] ;
if ( F_17 ( & V_78 -> V_68 ) == 0 ) {
* V_12 = V_79 ;
* V_13 = F_27 ( L_1 ) ;
return FALSE ;
}
F_30 ( V_19 , F_29 ( ( ( V_80 * ) V_78 ) -> V_82 ) ) ;
V_50 += F_17 ( & V_78 -> V_68 ) ;
break;
}
case V_84 :
V_50 = V_49 ;
break;
default:
{
T_13 * V_78 = ( T_13 * ) & V_16 [ V_50 ] ;
if ( F_17 ( & V_78 -> V_68 ) == 0 ) {
* V_12 = V_79 ;
* V_13 = F_27 ( L_1 ) ;
return FALSE ;
}
V_50 += F_17 ( & V_78 -> V_68 ) ;
break;
}
}
}
V_50 = 0 ;
V_19 -> V_48 += V_49 ;
V_49 = F_8 ( ( V_19 -> V_17 - V_19 -> V_48 ) ) ;
}while( ( V_49 > 0 ) && ( F_2 ( V_15 -> V_9 , V_16 , V_49 , V_12 , V_13 ) ) );
return FALSE ;
}
static T_3 V_40 ( T_7 * V_15 , int * V_12 , T_5 * * V_13 , T_8 * V_74 )
{
T_10 * V_19 = ( T_10 * ) V_15 -> V_46 ;
T_1 V_54 = V_19 -> V_54 ;
T_5 * V_16 = V_19 -> V_47 ;
T_2 V_50 = V_19 -> V_50 ;
T_2 V_49 = V_19 -> V_49 ;
* V_12 = 0 ;
* V_13 = NULL ;
do
{
while ( ( V_50 < V_49 ) &&
( ( V_49 - V_50 ) >= ( ( T_9 ) sizeof( ( ( V_85 * ) & V_16 [ V_50 ] ) -> V_86 ) ) ) )
{
switch ( ( ( V_85 * ) & V_16 [ V_50 ] ) -> V_86 )
{
#define F_25 ( V_57 , T_11 , T_12 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
#define F_31 ( V_57 , T_11 , T_12 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
case NSPR_PDPKTRACEFULLNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
#define F_26 ( V_57 , T_11 , T_12 ) \
case NSPR_PDPKTRACEPARTTX_V##ver:\
case NSPR_PDPKTRACEPARTTXB_V##ver:\
case NSPR_PDPKTRACEPARTRX_V##ver:\
PACKET_DESCRIBE(phdr,PART,ver,v##ver##_part,pp,pktracepart_v##ver,HEADERVER);
#define F_32 ( V_57 , T_11 , T_12 ) \
case NSPR_PDPKTRACEPARTTX_V##ver:\
case NSPR_PDPKTRACEPARTTXB_V##ver:\
case NSPR_PDPKTRACEPARTRX_V##ver:\
case NSPR_PDPKTRACEPARTNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,PART,ver,v##ver##_part,pp,pktracepart_v##ver,HEADERVER);
F_25 ( & V_15 -> V_57 , 20 , 200 ) ;
F_26 ( & V_15 -> V_57 , 20 , 200 ) ;
F_25 ( & V_15 -> V_57 , 21 , 201 ) ;
F_26 ( & V_15 -> V_57 , 21 , 201 ) ;
F_25 ( & V_15 -> V_57 , 22 , 202 ) ;
F_26 ( & V_15 -> V_57 , 22 , 202 ) ;
F_25 ( & V_15 -> V_57 , 23 , 203 ) ;
F_26 ( & V_15 -> V_57 , 23 , 203 ) ;
F_31 ( & V_15 -> V_57 , 24 , 204 ) ;
F_32 ( & V_15 -> V_57 , 24 , 204 ) ;
F_31 ( & V_15 -> V_57 , 25 , 205 ) ;
F_32 ( & V_15 -> V_57 , 25 , 205 ) ;
F_31 ( & V_15 -> V_57 , 26 , 206 ) ;
F_32 ( & V_15 -> V_57 , 26 , 206 ) ;
#undef F_25
#undef F_31
#undef F_26
#undef F_32
case V_87 :
{
T_14 * V_88 = ( T_14 * ) & V_16 [ V_50 ] ;
if ( F_33 ( ( V_85 * ) V_88 ) == 0 ) {
* V_12 = V_79 ;
* V_13 = F_27 ( L_1 ) ;
return FALSE ;
}
V_50 += F_33 ( ( V_85 * ) V_88 ) ;
F_28 ( V_19 , F_29 ( & ( ( V_89 * ) V_88 ) -> V_81 ) , F_17 ( & ( ( V_89 * ) V_88 ) -> V_82 ) ) ;
break;
}
case V_90 :
{
T_14 * V_88 = ( T_14 * ) & V_16 [ V_50 ] ;
if ( F_33 ( ( V_85 * ) V_88 ) == 0 ) {
* V_12 = V_79 ;
* V_13 = F_27 ( L_1 ) ;
return FALSE ;
}
F_30 ( V_19 , F_17 ( & ( ( V_89 * ) V_88 ) -> V_82 ) ) ;
V_50 += F_33 ( ( V_85 * ) V_88 ) ;
break;
}
case V_91 :
{
if ( V_50 >= V_21 / 2 )
V_50 = V_49 ;
else
V_50 = V_21 / 2 ;
break;
}
default:
{
T_14 * V_88 = ( T_14 * ) & V_16 [ V_50 ] ;
if ( F_33 ( ( V_85 * ) V_88 ) == 0 ) {
* V_12 = V_79 ;
* V_13 = F_27 ( L_1 ) ;
return FALSE ;
}
V_50 += F_33 ( ( V_85 * ) V_88 ) ;
break;
}
}
}
V_50 = 0 ;
V_19 -> V_48 += V_49 ;
V_49 = F_8 ( ( V_19 -> V_17 - V_19 -> V_48 ) ) ;
}while( ( V_49 > 0 ) && ( F_2 ( V_15 -> V_9 , V_16 , V_49 , V_12 , V_13 ) ) );
return FALSE ;
}
static T_3 V_42 ( T_7 * V_15 , int * V_12 , T_5 * * V_13 , T_8 * V_74 )
{
T_10 * V_19 = ( T_10 * ) V_15 -> V_46 ;
T_1 V_54 ;
T_5 * V_16 = V_19 -> V_47 ;
T_2 V_50 = V_19 -> V_50 ;
T_2 V_49 = V_19 -> V_49 ;
T_15 * V_92 ;
T_2 V_93 = 0 , V_94 = 0 , V_95 = 0 , V_96 = 0 ;
V_85 * V_97 ;
int V_14 = 0 ;
* V_12 = 0 ;
* V_13 = NULL ;
if( V_49 == 0 ) {
return FALSE ;
}
V_92 = ( T_15 * ) F_7 ( 65536 ) ;
do
{
if ( ! V_16 [ V_50 ] && V_50 <= V_30 ) {
V_50 = V_30 ;
}
if ( F_34 ( V_15 -> V_9 ) && V_14 > 0 && V_14 < V_30 ) {
memset ( & V_16 [ V_14 ] , 0 , V_30 - V_14 ) ;
}
while ( ( V_50 < V_30 ) &&
V_16 [ V_50 ] )
{
V_97 = ( V_85 * ) & V_16 [ V_50 ] ;
if ( F_33 ( V_97 ) == 0 ) {
* V_12 = V_79 ;
* V_13 = F_27 ( L_1 ) ;
F_10 ( V_92 ) ;
return FALSE ;
}
switch ( V_97 -> V_86 )
{
#define F_35 ( V_57 , T_11 , T_12 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
case NSPR_PDPKTRACEFULLNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
F_35 ( & V_15 -> V_57 , 30 , 300 ) ;
#undef F_35
#define F_36 ( V_57 , T_11 , T_12 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
case NSPR_PDPKTRACEFULLNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
F_36 ( & V_15 -> V_57 , 35 , 350 ) ;
#undef F_36
case V_87 :
{
V_50 += F_33 ( V_97 ) ;
F_28 ( V_19 , F_29 ( & ( ( V_89 * ) & V_16 [ V_50 ] ) -> V_81 ) , F_17 ( & ( ( V_89 * ) & V_16 [ V_50 ] ) -> V_82 ) ) ;
break;
}
case V_90 :
{
F_30 ( V_19 , F_17 ( & ( ( V_89 * ) & V_16 [ V_50 ] ) -> V_82 ) ) ;
V_50 += F_33 ( V_97 ) ;
break;
}
default:
{
V_50 += F_33 ( V_97 ) ;
break;
}
}
}
V_50 = 0 ;
V_19 -> V_48 += V_49 ;
V_49 = V_30 ;
} while( ( V_49 > 0 ) && ( V_14 = F_3 ( V_16 , V_49 , V_15 -> V_9 ) ) > 0 && ( F_34 ( V_15 -> V_9 ) || ( T_2 ) V_14 == V_49 ) );
if ( V_14 < 0 )
* V_12 = F_4 ( V_15 -> V_9 , V_13 ) ;
else
* V_12 = 0 ;
F_10 ( V_92 ) ;
return FALSE ;
}
static T_3 V_39 ( T_7 * V_15 , T_8 V_98 ,
struct V_99 * V_57 , T_16 * V_10 , int * V_12 , T_5 * * V_13 )
{
T_17 V_100 ;
T_18 V_101 ;
T_15 * V_102 ;
unsigned int V_103 ;
* V_12 = 0 ;
if ( F_12 ( V_15 -> V_104 , V_98 , V_33 , V_12 ) == - 1 )
return FALSE ;
if ( ! F_13 ( V_15 -> V_104 , ( void * ) & V_100 , sizeof V_100 ,
V_12 , V_13 ) )
return FALSE ;
V_101 = F_37 ( & V_100 ) ;
F_38 ( V_10 , V_101 ) ;
V_102 = F_39 ( V_10 ) ;
memcpy ( V_102 , ( void * ) & V_100 , sizeof V_100 ) ;
if ( V_101 > sizeof V_100 ) {
V_103 = ( unsigned int ) ( V_101 - sizeof V_100 ) ;
if ( ! F_13 ( V_15 -> V_104 , V_102 + sizeof V_100 , V_103 ,
V_12 , V_13 ) )
return FALSE ;
}
#define F_25 ( V_57 , type , T_12 ) \
case NSPR_PDPKTRACEFULLTX_V##type:\
case NSPR_PDPKTRACEFULLTXB_V##type:\
case NSPR_PDPKTRACEFULLRX_V##type:\
PACKET_DESCRIBE(phdr,FULL,full,type,fp,HEADERVER);\
break;
#define F_26 ( V_57 , type , T_12 ) \
case NSPR_PDPKTRACEPARTTX_V##type:\
case NSPR_PDPKTRACEPARTTXB_V##type:\
case NSPR_PDPKTRACEPARTRX_V##type:\
PACKET_DESCRIBE(phdr,PART,part,type,pp,HEADERVER);\
break;
switch ( F_17 ( & ( ( V_75 * ) V_102 ) -> V_76 ) )
{
F_25 (phdr, 10 , 100 )
F_26 (phdr, 10 , 100 )
}
#undef F_25
#undef F_26
return TRUE ;
}
static T_3 V_41 ( T_7 * V_15 , T_8 V_98 ,
struct V_99 * V_57 , T_16 * V_10 , int * V_12 , T_5 * * V_13 )
{
V_85 V_100 ;
T_18 V_101 ;
T_18 V_105 ;
T_15 * V_102 ;
unsigned int V_103 ;
T_1 V_54 ;
* V_12 = 0 ;
if ( F_12 ( V_15 -> V_104 , V_98 , V_33 , V_12 ) == - 1 )
return FALSE ;
if ( ! F_13 ( V_15 -> V_104 , ( void * ) & V_100 , 2 , V_12 , V_13 ) )
return FALSE ;
V_105 = 2 ;
if ( V_100 . V_106 & V_107 ) {
if ( ! F_13 ( V_15 -> V_104 , ( void * ) & V_100 . V_108 , 1 ,
V_12 , V_13 ) )
return FALSE ;
V_105 = 3 ;
}
V_101 = F_33 ( & V_100 ) ;
F_38 ( V_10 , V_101 ) ;
V_102 = F_39 ( V_10 ) ;
memcpy ( V_102 , ( void * ) & V_100 , V_105 ) ;
if ( V_101 > V_105 ) {
V_103 = ( unsigned int ) ( V_101 - V_105 ) ;
if ( ! F_13 ( V_15 -> V_104 , V_102 + V_105 , V_103 ,
V_12 , V_13 ) )
return FALSE ;
}
#define F_25 ( V_57 , T_11 , T_12 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
#define F_31 ( V_57 , T_11 , T_12 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
case NSPR_PDPKTRACEFULLNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
#define F_26 ( V_57 , T_11 , T_12 ) \
case NSPR_PDPKTRACEPARTTX_V##ver:\
case NSPR_PDPKTRACEPARTTXB_V##ver:\
case NSPR_PDPKTRACEPARTRX_V##ver:\
PACKET_DESCRIBE(phdr,PART,ver,v##ver##_part,pp,pktracepart_v##ver,HEADERVER);
#define F_32 ( V_57 , T_11 , T_12 ) \
case NSPR_PDPKTRACEPARTTX_V##ver:\
case NSPR_PDPKTRACEPARTTXB_V##ver:\
case NSPR_PDPKTRACEPARTRX_V##ver:\
case NSPR_PDPKTRACEPARTNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,PART,ver,v##ver##_part,pp,pktracepart_v##ver,HEADERVER);
switch ( ( ( V_85 * ) V_102 ) -> V_86 )
{
F_25 (phdr, 20 , 200 )
F_26 (phdr, 20 , 200 )
F_25 (phdr, 21 , 201 )
F_26 (phdr, 21 , 201 )
F_25 (phdr, 22 , 202 )
F_26 (phdr, 22 , 202 )
F_25 (phdr, 23 , 203 )
F_26 (phdr, 23 , 203 )
F_31 (phdr, 24 , 204 )
F_32 (phdr, 24 , 204 )
F_31 (phdr, 25 , 205 )
F_32 (phdr, 25 , 205 )
F_31 (phdr, 26 , 206 )
F_32 (phdr, 26 , 206 )
}
#undef F_25
#undef F_31
#undef F_26
#undef F_32
return TRUE ;
}
static T_3 V_43 ( T_7 * V_15 , T_8 V_98 ,
struct V_99 * V_57 , T_16 * V_10 , int * V_12 , T_5 * * V_13 )
{
V_85 V_100 ;
T_18 V_101 ;
T_18 V_105 ;
T_15 * V_102 ;
unsigned int V_103 ;
T_1 V_54 ;
* V_12 = 0 ;
if ( F_12 ( V_15 -> V_104 , V_98 , V_33 , V_12 ) == - 1 )
return FALSE ;
if ( ! F_13 ( V_15 -> V_104 , ( void * ) & V_100 , 2 , V_12 , V_13 ) )
return FALSE ;
V_105 = 2 ;
if ( V_100 . V_106 & V_107 ) {
if ( ! F_13 ( V_15 -> V_104 , ( void * ) & V_100 . V_108 , 1 ,
V_12 , V_13 ) )
return FALSE ;
V_105 = 3 ;
}
V_101 = F_33 ( & V_100 ) ;
F_38 ( V_10 , V_101 ) ;
V_102 = F_39 ( V_10 ) ;
memcpy ( V_102 , ( void * ) & V_100 , V_105 ) ;
if ( V_101 > V_105 ) {
V_103 = ( unsigned int ) ( V_101 - V_105 ) ;
if ( ! F_13 ( V_15 -> V_104 , V_102 + V_105 , V_103 ,
V_12 , V_13 ) )
return FALSE ;
}
( V_57 ) -> V_109 = ( V_57 ) -> V_62 = V_101 ;
#define F_40 ( V_57 , T_11 , T_12 ) \
case NSPR_PDPKTRACEFULLTX_V##ver:\
case NSPR_PDPKTRACEFULLTXB_V##ver:\
case NSPR_PDPKTRACEFULLRX_V##ver:\
case NSPR_PDPKTRACEFULLNEWRX_V##ver:\
PACKET_DESCRIBE(phdr,FULL,ver,v##ver##_full,fp,pktracefull_v##ver,HEADERVER);
switch ( ( ( V_85 * ) V_102 ) -> V_86 )
{
F_40 ( V_57 , 30 , 300 ) ;
F_40 ( V_57 , 35 , 350 ) ;
}
return TRUE ;
}
static void V_45 ( T_7 * V_15 )
{
T_10 * V_19 = ( T_10 * ) V_15 -> V_46 ;
F_10 ( V_19 -> V_47 ) ;
}
int F_41 ( int V_110 )
{
if ( V_110 == V_25 )
return 0 ;
return V_111 ;
}
int F_42 ( int V_110 )
{
if ( V_110 == V_27 )
return 0 ;
return V_111 ;
}
int F_43 ( int V_110 )
{
if ( V_110 == V_29 )
return 0 ;
return V_111 ;
}
int F_44 ( int V_110 )
{
if ( V_110 == V_32 )
return 0 ;
return V_111 ;
}
T_3 F_45 ( T_19 * V_112 , int * V_12 V_113 )
{
T_20 * V_19 ;
V_112 -> V_114 = V_115 ;
V_19 = ( T_20 * ) F_7 ( sizeof( T_20 ) ) ;
V_112 -> V_46 = ( void * ) V_19 ;
V_19 -> V_116 = 0 ;
if ( ( V_112 -> V_22 == V_28 ) ||
( V_112 -> V_22 == V_31 ) )
V_19 -> V_117 = V_30 ;
else
V_19 -> V_117 = V_21 ;
V_19 -> V_118 = 0 ;
V_19 -> V_119 = TRUE ;
return TRUE ;
}
static T_3 F_46 ( T_19 * V_112 , int * V_12 )
{
T_20 * V_19 = ( T_20 * ) V_112 -> V_46 ;
if ( V_112 -> V_22 == V_23 )
{
T_21 V_120 ;
T_22 V_121 ;
V_120 = F_47 ( V_67 ) ;
memcpy ( V_121 . V_122 . V_76 , & V_120 , sizeof V_121 . V_122 . V_76 ) ;
V_120 = F_47 ( V_123 ) ;
memcpy ( V_121 . V_122 . V_124 , & V_120 , sizeof V_121 . V_122 . V_124 ) ;
memset ( V_121 . V_69 , 0 , V_125 ) ;
F_48 ( V_121 . V_69 , V_64 , V_125 ) ;
if ( ! F_49 ( V_112 , & V_121 , V_123 ,
V_12 ) )
return FALSE ;
V_19 -> V_116 += ( T_21 ) V_123 ;
} else if ( V_112 -> V_22 == V_26 )
{
T_23 V_126 ;
V_126 . V_70 = V_71 ;
V_126 . V_72 = V_127 ;
memcpy ( V_126 . V_69 , V_65 , sizeof( V_65 ) ) ;
if ( ! F_49 ( V_112 , & V_126 , V_126 . V_72 ,
V_12 ) )
return FALSE ;
V_19 -> V_116 += ( T_21 ) V_126 . V_72 ;
} else if ( V_112 -> V_22 == V_28 )
{
T_24 V_128 ;
V_128 . V_70 = V_129 ;
V_128 . V_72 = V_130 ;
memcpy ( V_128 . V_69 , V_131 , sizeof( V_131 ) ) ;
if ( ! F_49 ( V_112 , & V_128 , V_128 . V_72 ,
V_12 ) )
return FALSE ;
V_19 -> V_116 += ( T_21 ) V_128 . V_72 ;
} else if ( V_112 -> V_22 == V_31 )
{
T_25 V_132 ;
V_132 . V_70 = V_133 ;
V_132 . V_72 = V_134 ;
memcpy ( V_132 . V_69 , V_135 , sizeof( V_135 ) ) ;
if ( ! F_49 ( V_112 , & V_132 , V_132 . V_72 ,
V_12 ) )
return FALSE ;
V_19 -> V_116 += ( T_21 ) V_132 . V_72 ;
} else
{
F_50 () ;
return FALSE ;
}
return TRUE ;
}
static T_3
F_51 ( T_19 * V_112 , const struct V_99 * V_57 ,
const T_15 * V_102 , int * V_12 )
{
T_20 * V_19 = ( T_20 * ) V_112 -> V_46 ;
T_1 V_54 ;
if ( V_112 -> V_22 == V_23 )
{
T_21 V_136 ;
T_2 V_137 ;
T_1 V_138 ;
V_80 V_139 ;
V_136 = F_47 ( V_77 ) ;
memcpy ( V_139 . V_122 . V_76 , & V_136 , sizeof V_139 . V_122 . V_76 ) ;
V_136 = F_47 ( V_140 ) ;
memcpy ( V_139 . V_122 . V_124 , & V_136 , sizeof V_139 . V_122 . V_124 ) ;
memcpy ( & V_137 , ( ( const T_13 * ) V_102 ) -> V_141 , sizeof V_137 ) ;
V_54 = F_1 ( V_137 ) ;
memset ( V_139 . V_82 , 0 , sizeof V_139 . V_82 ) ;
V_138 = F_52 ( ( T_2 ) V_57 -> V_58 . V_59 - ( T_2 ) ( V_54 / 1000000000 ) ) ;
memcpy ( V_139 . V_81 , & V_138 , sizeof V_139 . V_81 ) ;
if ( ! F_49 ( V_112 , & V_139 , V_140 , V_12 ) )
return FALSE ;
V_19 -> V_116 += V_140 ;
} else if ( ( V_112 -> V_22 == V_26 ) ||
( V_112 -> V_22 == V_28 ) ||
( V_112 -> V_22 == V_31 ) ) {
T_2 V_137 ;
T_1 V_138 ;
V_89 V_142 ;
V_142 . V_143 = V_87 ;
V_142 . V_144 = V_145 ;
memcpy ( & V_137 , ( ( const T_14 * ) V_102 ) -> V_141 , sizeof V_137 ) ;
V_54 = F_1 ( V_137 ) ;
memset ( V_142 . V_82 , 0 , sizeof V_142 . V_82 ) ;
V_138 = F_52 ( ( T_2 ) V_57 -> V_58 . V_59 - ( T_2 ) ( V_54 / 1000000000 ) ) ;
memcpy ( V_142 . V_82 , & V_138 , sizeof V_142 . V_82 ) ;
if ( ! F_49 ( V_112 , & V_142 , V_145 , V_12 ) )
return FALSE ;
V_19 -> V_116 += V_145 ;
} else
{
F_50 () ;
return FALSE ;
}
return TRUE ;
}
static T_3 V_115 ( T_19 * V_112 , const struct V_99 * V_57 ,
const T_15 * V_102 , int * V_12 , T_5 * * V_13 V_113 )
{
T_20 * V_19 = ( T_20 * ) V_112 -> V_46 ;
if ( V_57 -> V_146 != V_147 ) {
* V_12 = V_148 ;
return FALSE ;
}
if ( V_19 -> V_119 == TRUE )
{
V_19 -> V_119 = FALSE ;
if ( V_112 -> V_22 == V_23 )
{
if ( ! F_46 ( V_112 , V_12 ) ||
! F_51 ( V_112 , V_57 , V_102 , V_12 ) )
return FALSE ;
} else if ( V_112 -> V_22 == V_26 )
{
if ( ! F_46 ( V_112 , V_12 ) ||
! F_51 ( V_112 , V_57 , V_102 , V_12 ) )
return FALSE ;
} else if ( V_112 -> V_22 == V_28 ||
V_112 -> V_22 == V_31 )
{
if ( ! F_46 ( V_112 , V_12 ) ||
! F_51 ( V_112 , V_57 , V_102 , V_12 ) )
return FALSE ;
} else
{
F_50 () ;
return FALSE ;
}
}
switch ( V_57 -> V_149 . V_150 . V_146 )
{
case V_151 :
if ( V_112 -> V_22 == V_23 )
{
if ( V_19 -> V_116 + V_57 -> V_109 >= V_19 -> V_117 )
{
if ( F_53 ( V_112 , ( V_19 -> V_117 - V_19 -> V_116 ) , V_152 , V_12 ) == - 1 )
return FALSE ;
V_19 -> V_116 = 0 ;
if ( ! F_46 ( V_112 , V_12 ) )
return FALSE ;
}
if ( ! F_49 ( V_112 , V_102 , V_57 -> V_109 , V_12 ) )
return FALSE ;
V_19 -> V_116 += ( T_21 ) V_57 -> V_109 ;
} else if ( V_112 -> V_22 == V_26 )
{
* V_12 = V_153 ;
return FALSE ;
}
break;
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
if ( V_112 -> V_22 == V_23 )
{
* V_12 = V_153 ;
return FALSE ;
} else if ( V_112 -> V_22 == V_26 )
{
if ( V_19 -> V_116 + V_57 -> V_109 >= V_19 -> V_117 )
{
if ( F_53 ( V_112 , ( V_19 -> V_117 - V_19 -> V_116 ) , V_152 , V_12 ) == - 1 )
return FALSE ;
V_19 -> V_116 = 0 ;
if ( ! F_46 ( V_112 , V_12 ) )
return FALSE ;
}
if ( ! F_49 ( V_112 , V_102 , V_57 -> V_109 , V_12 ) )
return FALSE ;
V_19 -> V_116 += ( T_21 ) V_57 -> V_109 ;
}
break;
case V_161 :
case V_162 :
if ( V_112 -> V_22 == V_23 )
{
* V_12 = V_153 ;
return FALSE ;
} else if ( V_112 -> V_22 == V_26 )
{
* V_12 = V_153 ;
return FALSE ;
} else if ( V_112 -> V_22 == V_28 || V_112 -> V_22 == V_31 )
{
if ( V_19 -> V_116 + V_57 -> V_109 >= V_19 -> V_117 )
{
if ( F_53 ( V_112 , ( V_19 -> V_117 - V_19 -> V_116 ) , V_152 , V_12 ) == - 1 )
return FALSE ;
V_19 -> V_116 = 0 ;
if ( ! F_46 ( V_112 , V_12 ) )
return FALSE ;
}
if ( ! F_49 ( V_112 , V_102 , V_57 -> V_109 , V_12 ) )
return FALSE ;
V_19 -> V_116 += ( T_21 ) V_57 -> V_109 ;
} else
{
F_50 () ;
return FALSE ;
}
break;
default:
F_50 () ;
return FALSE ;
}
return TRUE ;
}
