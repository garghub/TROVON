static int T_1 F_1 ( void )
{
int V_1 ;
V_1 = F_2 ( & V_2 ) ;
if ( V_1 )
goto V_3;
V_1 = F_2 ( & V_4 ) ;
if ( V_1 )
goto V_5;
V_1 = F_2 ( & V_6 ) ;
if ( V_1 )
goto V_7;
V_1 = F_2 ( & V_8 ) ;
if ( V_1 )
goto V_9;
V_1 = F_3 ( & V_10 ) ;
if ( V_1 )
goto V_11;
F_4 (KERN_INFO KBUILD_MODNAME L_1 DRIVER_VERSION L_2
DRIVER_DESC L_3 ) ;
return 0 ;
V_11:
F_5 ( & V_8 ) ;
V_9:
F_5 ( & V_6 ) ;
V_7:
F_5 ( & V_4 ) ;
V_5:
F_5 ( & V_2 ) ;
V_3:
return V_1 ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_10 ) ;
F_5 ( & V_2 ) ;
F_5 ( & V_4 ) ;
F_5 ( & V_6 ) ;
F_5 ( & V_8 ) ;
}
static void F_8 ( struct V_12 * V_13 , int V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_18 * V_19 ;
F_9 ( L_4 , V_20 ) ;
V_19 = F_10 ( V_16 ) ;
if ( V_14 == - 1 )
V_19 -> V_21 = 1 ;
else
V_19 -> V_21 = 0 ;
F_11 ( V_16 , 0 ) ;
}
static void F_12 ( struct V_12 * V_13 ,
struct V_15 * V_16 , struct V_22 * V_23 )
{
int V_24 , V_25 ;
struct V_18 * V_19 ;
const struct V_26 * V_27 ;
unsigned int V_28 ;
F_9 ( L_4 , V_20 ) ;
V_19 = F_10 ( V_16 ) ;
V_27 = V_19 -> V_29 ;
V_28 = V_13 -> V_30 -> V_31 ;
V_25 = V_16 -> V_32 - V_16 -> V_33 -> V_34 ;
V_24 = F_13 ( V_13 ) ;
if ( V_27 -> V_35 ( V_24 , V_27 -> V_36 ,
NULL , NULL , NULL , V_25 ) == V_37 ) {
V_19 -> V_38 = V_24 ;
} else
V_24 = F_14 ( V_23 ) ;
F_15 ( V_13 , V_24 , V_24 ) ;
V_19 -> V_28 = V_28 ;
V_19 -> V_39 = ( V_28 & V_40 ) ? V_41 : V_42 ;
V_13 -> V_30 -> V_31 &= ~ V_43 ;
F_11 ( V_16 , 0 ) ;
}
static int F_16 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_18 * V_19 = F_10 ( V_16 ) ;
unsigned int V_44 ;
V_44 = ( ( V_19 -> V_45 ) ? V_46 : 0 ) |
( ( V_19 -> V_47 ) ? V_48 : 0 ) |
( ( V_19 -> V_49 ) ? V_50 : 0 ) |
( ( V_19 -> V_51 ) ? V_52 : 0 ) |
( ( V_19 -> V_53 ) ? V_54 : 0 ) |
( ( V_19 -> V_55 ) ? V_56 : 0 ) ;
return V_44 ;
}
static int F_17 ( struct V_12 * V_13 ,
unsigned int V_57 , unsigned int V_58 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_18 * V_19 = F_10 ( V_16 ) ;
if ( V_57 & V_46 )
V_19 -> V_45 = 1 ;
if ( V_57 & V_48 )
V_19 -> V_47 = 1 ;
if ( V_58 & V_46 )
V_19 -> V_45 = 0 ;
if ( V_58 & V_48 )
V_19 -> V_47 = 0 ;
F_11 ( V_16 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 ,
struct V_15 * V_16 , const unsigned char * V_59 , int V_60 )
{
struct V_18 * V_19 ;
const struct V_26 * V_27 ;
int V_61 ;
int V_62 , V_63 ;
struct V_64 * V_65 ;
int V_66 , V_67 , V_68 ;
V_19 = F_10 ( V_16 ) ;
V_27 = V_19 -> V_29 ;
if ( V_27 -> V_69 == V_70 ) {
V_67 = 64 ;
V_68 = 0 ;
} else {
V_67 = 63 ;
V_68 = 1 ;
}
F_9 ( L_5 ,
V_20 , V_16 -> V_32 , V_60 , V_19 -> V_71 ) ;
for ( V_62 = V_60 ; V_62 > 0 ; V_62 -= V_63 ) {
V_63 = V_62 ;
if ( V_63 > V_67 )
V_63 = V_67 ;
V_61 = V_19 -> V_71 ;
V_65 = V_19 -> V_72 [ V_61 ] ;
if ( V_65 == NULL ) {
F_9 ( L_6 , V_20 ) ;
return V_60 ;
}
F_9 ( L_7 ,
V_20 , F_19 ( V_65 -> V_73 ) , V_61 ) ;
if ( V_65 -> V_74 == - V_75 ) {
if ( F_20 ( V_76 ,
V_19 -> V_77 [ V_61 ] + 10 * V_78 ) )
break;
F_21 ( V_65 ) ;
break;
}
( ( char * ) V_65 -> V_79 ) [ 0 ] = 0 ;
memcpy ( V_65 -> V_79 + V_68 , V_59 , V_63 ) ;
V_59 += V_63 ;
V_65 -> V_80 = V_63 + V_68 ;
V_65 -> V_81 = V_16 -> V_33 -> V_81 ;
V_66 = F_22 ( V_65 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_8 , V_66 ) ;
V_19 -> V_77 [ V_61 ] = V_76 ;
V_19 -> V_71 = ( V_61 + 1 ) & V_27 -> V_83 ;
}
return V_60 - V_62 ;
}
static void F_23 ( struct V_64 * V_64 )
{
int V_84 , V_66 ;
int V_85 ;
struct V_15 * V_16 ;
struct V_12 * V_13 ;
unsigned char * V_86 = V_64 -> V_79 ;
int V_74 = V_64 -> V_74 ;
F_9 ( L_4 , V_20 ) ;
V_85 = F_19 ( V_64 -> V_73 ) ;
if ( V_74 ) {
F_9 ( L_9 ,
V_20 , V_74 , V_85 ) ;
return;
}
V_16 = V_64 -> V_87 ;
V_13 = F_24 ( & V_16 -> V_16 ) ;
if ( V_13 && V_64 -> V_88 ) {
if ( ( V_86 [ 0 ] & 0x80 ) == 0 ) {
if ( V_86 [ 0 ] & V_89 )
V_66 = V_90 ;
else
V_66 = 0 ;
for ( V_84 = 1 ; V_84 < V_64 -> V_88 ; ++ V_84 )
F_25 ( V_13 , V_86 [ V_84 ] , V_66 ) ;
} else {
F_9 ( L_10 , V_20 ) ;
for ( V_84 = 0 ; V_84 + 1 < V_64 -> V_88 ; V_84 += 2 ) {
int V_91 = V_86 [ V_84 ] , V_92 = 0 ;
if ( V_91 & V_89 )
V_92 |= V_90 ;
if ( V_91 & V_93 )
V_92 |= V_94 ;
if ( V_91 & V_95 )
V_92 |= V_96 ;
F_25 ( V_13 , V_86 [ V_84 + 1 ] , V_92 ) ;
}
}
F_26 ( V_13 ) ;
}
F_27 ( V_13 ) ;
V_64 -> V_81 = V_16 -> V_33 -> V_81 ;
V_66 = F_22 ( V_64 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_11 , V_20 , V_66 ) ;
}
static void F_28 ( struct V_64 * V_64 )
{
struct V_15 * V_16 ;
struct V_18 * V_19 ;
V_16 = V_64 -> V_87 ;
V_19 = F_10 ( V_16 ) ;
F_9 ( L_12 , V_20 , V_64 == V_19 -> V_72 [ 1 ] ) ;
F_29 ( V_16 ) ;
}
static void F_30 ( struct V_64 * V_64 )
{
F_9 ( L_4 , V_20 ) ;
}
static void F_31 ( struct V_64 * V_64 )
{
struct V_15 * V_16 ;
struct V_18 * V_19 ;
V_16 = V_64 -> V_87 ;
V_19 = F_10 ( V_16 ) ;
if ( V_19 -> V_97 ) {
F_9 ( L_13 , V_20 ) ;
F_32 ( V_16 -> V_33 , V_16 ,
V_19 -> V_97 - 1 ) ;
}
}
static void F_33 ( struct V_64 * V_64 )
{
unsigned char * V_86 = V_64 -> V_79 ;
struct V_98 * V_99 ;
struct V_100 * V_33 ;
struct V_15 * V_16 ;
struct V_18 * V_19 ;
struct V_12 * V_13 ;
int V_101 , V_66 ;
int V_74 = V_64 -> V_74 ;
V_33 = V_64 -> V_87 ;
if ( V_74 ) {
F_9 ( L_14 , V_20 , V_74 ) ;
return;
}
if ( V_64 -> V_88 != 9 ) {
F_9 ( L_15 , V_20 , V_64 -> V_88 ) ;
goto exit;
}
V_99 = (struct V_98 * ) V_86 ;
#if 0
dbg("%s - port status: port %d cts %d dcd %d dsr %d ri %d toff %d txoff %d rxen %d cr %d",
__func__, msg->port, msg->hskia_cts, msg->gpia_dcd, msg->dsr, msg->ri, msg->_txOff,
msg->_txXoff, msg->rxEnabled, msg->controlResponse);
#endif
if ( V_99 -> V_16 >= V_33 -> V_102 ) {
F_9 ( L_16 , V_20 , V_99 -> V_16 ) ;
goto exit;
}
V_16 = V_33 -> V_16 [ V_99 -> V_16 ] ;
V_19 = F_10 ( V_16 ) ;
V_101 = V_19 -> V_53 ;
V_19 -> V_49 = ( ( V_99 -> V_103 ) ? 1 : 0 ) ;
V_19 -> V_51 = ( ( V_99 -> V_104 ) ? 1 : 0 ) ;
V_19 -> V_53 = ( ( V_99 -> V_105 ) ? 1 : 0 ) ;
V_19 -> V_55 = ( ( V_99 -> V_106 ) ? 1 : 0 ) ;
if ( V_101 != V_19 -> V_53 ) {
V_13 = F_24 ( & V_16 -> V_16 ) ;
if ( V_13 && ! F_34 ( V_13 ) )
F_35 ( V_13 ) ;
F_27 ( V_13 ) ;
}
V_64 -> V_81 = V_33 -> V_81 ;
V_66 = F_22 ( V_64 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_11 , V_20 , V_66 ) ;
exit: ;
}
static void F_36 ( struct V_64 * V_64 )
{
F_9 ( L_4 , V_20 ) ;
}
static void F_37 ( struct V_64 * V_64 )
{
int V_66 ;
struct V_15 * V_16 ;
struct V_12 * V_13 ;
unsigned char * V_86 ;
struct V_18 * V_19 ;
int V_74 = V_64 -> V_74 ;
F_9 ( L_4 , V_20 ) ;
V_16 = V_64 -> V_87 ;
V_19 = F_10 ( V_16 ) ;
V_86 = V_64 -> V_79 ;
if ( V_64 != V_19 -> V_107 [ V_19 -> V_108 ] )
return;
do {
if ( V_74 ) {
F_9 ( L_9 ,
V_20 , V_74 , F_19 ( V_64 -> V_73 ) ) ;
return;
}
V_16 = V_64 -> V_87 ;
V_19 = F_10 ( V_16 ) ;
V_86 = V_64 -> V_79 ;
V_13 = F_24 ( & V_16 -> V_16 ) ;
if ( V_13 && V_64 -> V_88 ) {
F_38 ( V_13 , V_86 , V_64 -> V_88 ) ;
F_26 ( V_13 ) ;
}
F_27 ( V_13 ) ;
V_64 -> V_81 = V_16 -> V_33 -> V_81 ;
V_66 = F_22 ( V_64 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_11 ,
V_20 , V_66 ) ;
V_19 -> V_108 ^= 1 ;
V_64 = V_19 -> V_107 [ V_19 -> V_108 ] ;
} while ( V_64 -> V_74 != - V_75 );
}
static void F_39 ( struct V_64 * V_64 )
{
F_9 ( L_4 , V_20 ) ;
}
static void F_40 ( struct V_64 * V_64 )
{
struct V_15 * V_16 ;
struct V_18 * V_19 ;
V_16 = V_64 -> V_87 ;
V_19 = F_10 ( V_16 ) ;
if ( V_19 -> V_97 ) {
F_9 ( L_13 , V_20 ) ;
F_41 ( V_16 -> V_33 , V_16 ,
V_19 -> V_97 - 1 ) ;
}
}
static void F_42 ( struct V_64 * V_64 )
{
int V_66 ;
unsigned char * V_86 = V_64 -> V_79 ;
struct V_109 * V_99 ;
struct V_100 * V_33 ;
struct V_15 * V_16 ;
struct V_18 * V_19 ;
struct V_12 * V_13 ;
int V_101 ;
int V_74 = V_64 -> V_74 ;
V_33 = V_64 -> V_87 ;
if ( V_74 ) {
F_9 ( L_14 , V_20 , V_74 ) ;
return;
}
if ( V_64 -> V_88 != sizeof( struct V_109 ) ) {
F_9 ( L_17 , V_20 , V_64 -> V_88 ) ;
goto exit;
}
V_99 = (struct V_109 * ) V_86 ;
if ( V_99 -> V_16 >= V_33 -> V_102 ) {
F_9 ( L_16 , V_20 , V_99 -> V_16 ) ;
goto exit;
}
V_16 = V_33 -> V_16 [ V_99 -> V_16 ] ;
V_19 = F_10 ( V_16 ) ;
V_101 = V_19 -> V_53 ;
V_19 -> V_49 = ( ( V_99 -> V_110 ) ? 1 : 0 ) ;
V_19 -> V_51 = ( ( V_99 -> V_104 ) ? 1 : 0 ) ;
V_19 -> V_53 = ( ( V_99 -> V_111 ) ? 1 : 0 ) ;
V_19 -> V_55 = ( ( V_99 -> V_106 ) ? 1 : 0 ) ;
if( V_101 != V_19 -> V_53 && V_101 ) {
V_13 = F_24 ( & V_16 -> V_16 ) ;
if ( V_13 && ! F_34 ( V_13 ) )
F_35 ( V_13 ) ;
F_27 ( V_13 ) ;
}
V_64 -> V_81 = V_33 -> V_81 ;
V_66 = F_22 ( V_64 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_11 , V_20 , V_66 ) ;
exit: ;
}
static void F_43 ( struct V_64 * V_64 )
{
F_9 ( L_4 , V_20 ) ;
}
static void F_44 ( struct V_64 * V_64 )
{
struct V_100 * V_33 ;
struct V_15 * V_16 ;
struct V_18 * V_19 ;
int V_84 ;
F_9 ( L_4 , V_20 ) ;
V_33 = V_64 -> V_87 ;
for ( V_84 = 0 ; V_84 < V_33 -> V_102 ; ++ V_84 ) {
V_16 = V_33 -> V_16 [ V_84 ] ;
V_19 = F_10 ( V_16 ) ;
if ( V_19 -> V_97 ) {
F_9 ( L_13 , V_20 ) ;
F_45 ( V_33 , V_16 ,
V_19 -> V_97 - 1 ) ;
break;
}
}
}
static void F_46 ( struct V_64 * V_64 )
{
int V_66 ;
unsigned char * V_86 = V_64 -> V_79 ;
struct V_112 * V_99 ;
struct V_100 * V_33 ;
struct V_15 * V_16 ;
struct V_18 * V_19 ;
int V_101 ;
int V_74 = V_64 -> V_74 ;
F_9 ( L_4 , V_20 ) ;
V_33 = V_64 -> V_87 ;
if ( V_74 ) {
F_9 ( L_14 , V_20 , V_74 ) ;
return;
}
if ( V_64 -> V_88 !=
sizeof( struct V_112 ) ) {
F_9 ( L_17 , V_20 , V_64 -> V_88 ) ;
goto exit;
}
V_99 = (struct V_112 * ) V_86 ;
if ( V_99 -> V_113 >= V_33 -> V_102 ) {
F_9 ( L_16 ,
V_20 , V_99 -> V_113 ) ;
goto exit;
}
V_16 = V_33 -> V_16 [ V_99 -> V_113 ] ;
V_19 = F_10 ( V_16 ) ;
V_101 = V_19 -> V_53 ;
V_19 -> V_49 = ( ( V_99 -> V_110 ) ? 1 : 0 ) ;
V_19 -> V_51 = ( ( V_99 -> V_104 ) ? 1 : 0 ) ;
V_19 -> V_53 = ( ( V_99 -> V_111 ) ? 1 : 0 ) ;
V_19 -> V_55 = ( ( V_99 -> V_106 ) ? 1 : 0 ) ;
if ( V_101 != V_19 -> V_53 && V_101 ) {
struct V_12 * V_13 = F_24 ( & V_16 -> V_16 ) ;
if ( V_13 && ! F_34 ( V_13 ) )
F_35 ( V_13 ) ;
F_27 ( V_13 ) ;
}
V_64 -> V_81 = V_33 -> V_81 ;
V_66 = F_22 ( V_64 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_11 , V_20 , V_66 ) ;
exit: ;
}
static void F_47 ( struct V_64 * V_64 )
{
F_9 ( L_4 , V_20 ) ;
}
static void F_48 ( struct V_64 * V_64 )
{
int V_84 , V_66 ;
int V_85 ;
struct V_15 * V_16 ;
struct V_12 * V_13 ;
unsigned char * V_86 = V_64 -> V_79 ;
int V_74 = V_64 -> V_74 ;
F_9 ( L_4 , V_20 ) ;
V_85 = F_19 ( V_64 -> V_73 ) ;
if ( V_74 ) {
F_9 ( L_9 , V_20 ,
V_74 , V_85 ) ;
return;
}
V_16 = V_64 -> V_87 ;
V_13 = F_24 ( & V_16 -> V_16 ) ;
if ( V_13 && V_64 -> V_88 ) {
if ( ( V_86 [ 0 ] & 0x80 ) == 0 ) {
F_38 ( V_13 , V_86 + 1 ,
V_64 -> V_88 - 1 ) ;
} else {
for ( V_84 = 0 ; V_84 + 1 < V_64 -> V_88 ; V_84 += 2 ) {
int V_91 = V_86 [ V_84 ] , V_92 = 0 ;
if ( V_91 & V_89 )
V_92 |= V_90 ;
if ( V_91 & V_93 )
V_92 |= V_94 ;
if ( V_91 & V_95 )
V_92 |= V_96 ;
F_25 ( V_13 , V_86 [ V_84 + 1 ] , V_92 ) ;
}
}
F_26 ( V_13 ) ;
}
F_27 ( V_13 ) ;
V_64 -> V_81 = V_16 -> V_33 -> V_81 ;
V_66 = F_22 ( V_64 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_11 , V_20 , V_66 ) ;
}
static void F_49 ( struct V_64 * V_64 )
{
int V_84 , V_114 , V_115 , V_66 ;
struct V_100 * V_33 ;
struct V_15 * V_16 ;
struct V_12 * V_13 ;
unsigned char * V_86 = V_64 -> V_79 ;
int V_74 = V_64 -> V_74 ;
F_9 ( L_4 , V_20 ) ;
V_33 = V_64 -> V_87 ;
if ( V_74 ) {
F_9 ( L_14 , V_20 , V_74 ) ;
return;
}
V_84 = 0 ;
V_114 = 0 ;
if ( V_64 -> V_88 ) {
while ( V_84 < V_64 -> V_88 ) {
if ( V_86 [ V_84 ] >= V_33 -> V_102 ) {
F_9 ( L_16 ,
V_20 , V_86 [ V_84 ] ) ;
return;
}
V_16 = V_33 -> V_16 [ V_86 [ V_84 ++ ] ] ;
V_13 = F_24 ( & V_16 -> V_16 ) ;
V_114 = V_86 [ V_84 ++ ] ;
if ( ( V_86 [ V_84 ] & 0x80 ) == 0 ) {
V_84 ++ ;
for ( V_115 = 1 ; V_115 < V_114 ; ++ V_115 )
F_25 ( V_13 , V_86 [ V_84 ++ ] , 0 ) ;
} else {
for ( V_115 = 0 ; V_115 + 1 < V_114 ; V_115 += 2 ) {
int V_91 = V_86 [ V_84 ] , V_92 = 0 ;
if ( V_91 & V_89 )
V_92 |= V_90 ;
if ( V_91 & V_93 )
V_92 |= V_94 ;
if ( V_91 & V_95 )
V_92 |= V_96 ;
F_25 ( V_13 ,
V_86 [ V_84 + 1 ] , V_92 ) ;
V_84 += 2 ;
}
}
F_26 ( V_13 ) ;
F_27 ( V_13 ) ;
}
}
V_64 -> V_81 = V_33 -> V_81 ;
V_66 = F_22 ( V_64 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_11 , V_20 , V_66 ) ;
}
static void F_50 ( struct V_64 * V_64 )
{
F_9 ( L_4 , V_20 ) ;
}
static void F_51 ( struct V_64 * V_64 )
{
int V_84 , V_66 ;
int V_85 ;
struct V_15 * V_16 ;
struct V_18 * V_19 ;
struct V_12 * V_13 ;
unsigned char * V_86 = V_64 -> V_79 ;
int V_74 = V_64 -> V_74 ;
F_9 ( L_4 , V_20 ) ;
V_85 = F_19 ( V_64 -> V_73 ) ;
if ( V_74 ) {
F_9 ( L_9 ,
V_20 , V_74 , V_85 ) ;
return;
}
V_16 = V_64 -> V_87 ;
V_19 = F_10 ( V_16 ) ;
if ( V_64 -> V_88 ) {
V_13 = F_24 ( & V_16 -> V_16 ) ;
if ( V_19 -> V_38 > 57600 )
F_38 ( V_13 , V_86 , V_64 -> V_88 ) ;
else {
if ( ( V_86 [ 0 ] & 0x80 ) == 0 ) {
if ( V_86 [ 0 ] & V_89 )
V_66 = V_90 ;
else
V_66 = 0 ;
for ( V_84 = 1 ; V_84 < V_64 -> V_88 ; ++ V_84 )
F_25 ( V_13 , V_86 [ V_84 ] ,
V_66 ) ;
} else {
F_9 ( L_10 , V_20 ) ;
for ( V_84 = 0 ; V_84 + 1 < V_64 -> V_88 ; V_84 += 2 ) {
int V_91 = V_86 [ V_84 ] , V_92 = 0 ;
if ( V_91 & V_89 )
V_92 |= V_90 ;
if ( V_91 & V_93 )
V_92 |= V_94 ;
if ( V_91 & V_95 )
V_92 |= V_96 ;
F_25 ( V_13 , V_86 [ V_84 + 1 ] ,
V_92 ) ;
}
}
}
F_26 ( V_13 ) ;
F_27 ( V_13 ) ;
}
V_64 -> V_81 = V_16 -> V_33 -> V_81 ;
V_66 = F_22 ( V_64 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_11 , V_20 , V_66 ) ;
}
static void F_52 ( struct V_64 * V_64 )
{
unsigned char * V_86 = V_64 -> V_79 ;
struct V_116 * V_99 ;
struct V_100 * V_33 ;
struct V_15 * V_16 ;
struct V_18 * V_19 ;
struct V_12 * V_13 ;
int V_101 , V_66 ;
int V_74 = V_64 -> V_74 ;
V_33 = V_64 -> V_87 ;
if ( V_74 ) {
F_9 ( L_14 , V_20 , V_74 ) ;
return;
}
if ( V_64 -> V_88 < 14 ) {
F_9 ( L_15 , V_20 , V_64 -> V_88 ) ;
goto exit;
}
V_99 = (struct V_116 * ) V_86 ;
V_16 = V_33 -> V_16 [ 0 ] ;
V_19 = F_10 ( V_16 ) ;
V_101 = V_19 -> V_53 ;
V_19 -> V_49 = ( ( V_99 -> V_110 ) ? 1 : 0 ) ;
V_19 -> V_51 = ( ( V_99 -> V_104 ) ? 1 : 0 ) ;
V_19 -> V_53 = ( ( V_99 -> V_111 ) ? 1 : 0 ) ;
V_19 -> V_55 = ( ( V_99 -> V_106 ) ? 1 : 0 ) ;
if ( V_101 != V_19 -> V_53 && V_101 ) {
V_13 = F_24 ( & V_16 -> V_16 ) ;
if ( V_13 && ! F_34 ( V_13 ) )
F_35 ( V_13 ) ;
F_27 ( V_13 ) ;
}
V_64 -> V_81 = V_33 -> V_81 ;
V_66 = F_22 ( V_64 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_11 , V_20 , V_66 ) ;
exit:
;
}
static void F_53 ( struct V_64 * V_64 )
{
struct V_15 * V_16 ;
struct V_18 * V_19 ;
V_16 = V_64 -> V_87 ;
V_19 = F_10 ( V_16 ) ;
if ( V_19 -> V_97 ) {
F_9 ( L_13 , V_20 ) ;
F_54 ( V_16 -> V_33 , V_16 ,
V_19 -> V_97 - 1 ) ;
}
}
static void F_55 ( struct V_64 * V_64 )
{
int V_66 ;
unsigned char * V_86 = V_64 -> V_79 ;
struct V_117 * V_99 ;
struct V_100 * V_33 ;
struct V_15 * V_16 ;
struct V_18 * V_19 ;
int V_101 ;
int V_74 = V_64 -> V_74 ;
F_9 ( L_4 , V_20 ) ;
V_33 = V_64 -> V_87 ;
if ( V_74 ) {
F_9 ( L_14 , V_20 , V_74 ) ;
return;
}
if ( V_64 -> V_88 !=
sizeof( struct V_117 ) ) {
F_9 ( L_17 , V_20 , V_64 -> V_88 ) ;
return;
}
V_99 = (struct V_117 * ) V_86 ;
if ( V_99 -> V_16 >= V_33 -> V_102 ) {
F_9 ( L_16 , V_20 , V_99 -> V_16 ) ;
return;
}
V_16 = V_33 -> V_16 [ V_99 -> V_16 ] ;
V_19 = F_10 ( V_16 ) ;
V_101 = V_19 -> V_53 ;
V_19 -> V_49 = ( ( V_99 -> V_103 ) ? 1 : 0 ) ;
V_19 -> V_53 = ( ( V_99 -> V_105 ) ? 1 : 0 ) ;
if ( V_101 != V_19 -> V_53 && V_101 ) {
struct V_12 * V_13 = F_24 ( & V_16 -> V_16 ) ;
if ( V_13 && ! F_34 ( V_13 ) )
F_35 ( V_13 ) ;
F_27 ( V_13 ) ;
}
V_64 -> V_81 = V_33 -> V_81 ;
V_66 = F_22 ( V_64 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_11 , V_20 , V_66 ) ;
}
static void F_56 ( struct V_64 * V_64 )
{
struct V_100 * V_33 ;
struct V_15 * V_16 ;
struct V_18 * V_19 ;
int V_84 ;
F_9 ( L_4 , V_20 ) ;
V_33 = V_64 -> V_87 ;
for ( V_84 = 0 ; V_84 < V_33 -> V_102 ; ++ V_84 ) {
V_16 = V_33 -> V_16 [ V_84 ] ;
V_19 = F_10 ( V_16 ) ;
if ( V_19 -> V_97 ) {
F_9 ( L_13 , V_20 ) ;
F_57 ( V_33 , V_16 ,
V_19 -> V_97 - 1 ) ;
break;
}
}
}
static int F_58 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_18 * V_19 ;
const struct V_26 * V_27 ;
int V_61 ;
int V_118 ;
struct V_64 * V_65 ;
F_9 ( L_4 , V_20 ) ;
V_19 = F_10 ( V_16 ) ;
V_27 = V_19 -> V_29 ;
if ( V_27 -> V_69 == V_70 )
V_118 = 64 ;
else
V_118 = 63 ;
V_61 = V_19 -> V_71 ;
V_65 = V_19 -> V_72 [ V_61 ] ;
if ( V_65 != NULL ) {
if ( V_65 -> V_74 != - V_75 )
return V_118 ;
V_61 = ( V_61 + 1 ) & V_27 -> V_83 ;
V_65 = V_19 -> V_72 [ V_61 ] ;
if ( V_65 != NULL ) {
if ( V_65 -> V_74 != - V_75 )
return V_118 ;
}
}
return 0 ;
}
static int F_59 ( struct V_12 * V_13 , struct V_15 * V_16 )
{
struct V_18 * V_19 ;
struct V_119 * V_120 ;
struct V_100 * V_33 = V_16 -> V_33 ;
const struct V_26 * V_27 ;
int V_84 , V_66 ;
int V_24 , V_25 ;
struct V_64 * V_64 ;
unsigned int V_28 = 0 ;
V_120 = F_60 ( V_33 ) ;
V_19 = F_10 ( V_16 ) ;
V_27 = V_19 -> V_29 ;
F_9 ( L_18 , V_20 , V_16 -> V_32 ) ;
V_19 -> V_45 = 1 ;
V_19 -> V_47 = 1 ;
V_19 -> V_38 = 9600 ;
V_19 -> V_121 = 0 ;
V_19 -> V_122 = 0 ;
V_19 -> V_71 = 0 ;
V_19 -> V_108 = 0 ;
for ( V_84 = 0 ; V_84 < 2 ; V_84 ++ ) {
V_64 = V_19 -> V_107 [ V_84 ] ;
if ( V_64 == NULL )
continue;
V_64 -> V_81 = V_33 -> V_81 ;
F_61 ( V_64 -> V_81 , V_64 -> V_73 ) ;
V_66 = F_22 ( V_64 , V_123 ) ;
if ( V_66 != 0 )
F_9 ( L_19 ,
V_20 , V_84 , V_66 ) ;
}
for ( V_84 = 0 ; V_84 < 2 ; V_84 ++ ) {
V_64 = V_19 -> V_72 [ V_84 ] ;
if ( V_64 == NULL )
continue;
V_64 -> V_81 = V_33 -> V_81 ;
}
V_25 = V_16 -> V_32 - V_16 -> V_33 -> V_34 ;
if ( V_13 ) {
V_28 = V_13 -> V_30 -> V_31 ;
V_24 = F_13 ( V_13 ) ;
if ( V_24 >= 0
&& V_27 -> V_35 ( V_24 , V_27 -> V_36 ,
NULL , NULL , NULL , V_25 ) == V_37 ) {
V_19 -> V_38 = V_24 ;
}
}
V_19 -> V_28 = V_28 ;
V_19 -> V_39 = ( V_28 & V_40 ) ? V_41 : V_42 ;
F_11 ( V_16 , 1 ) ;
return 0 ;
}
static inline void F_62 ( struct V_64 * V_64 )
{
if ( V_64 && V_64 -> V_74 == - V_75 )
F_63 ( V_64 ) ;
}
static void F_64 ( struct V_15 * V_16 , int V_124 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
V_19 -> V_45 = V_124 ;
V_19 -> V_47 = V_124 ;
F_11 ( V_16 , 0 ) ;
}
static void F_65 ( struct V_15 * V_16 )
{
int V_84 ;
struct V_100 * V_33 = V_16 -> V_33 ;
struct V_119 * V_120 ;
struct V_18 * V_19 ;
F_9 ( L_4 , V_20 ) ;
V_120 = F_60 ( V_33 ) ;
V_19 = F_10 ( V_16 ) ;
V_19 -> V_45 = 0 ;
V_19 -> V_47 = 0 ;
if ( V_33 -> V_81 ) {
F_11 ( V_16 , 2 ) ;
F_66 ( 100 ) ;
}
V_19 -> V_71 = 0 ;
V_19 -> V_108 = 0 ;
if ( V_33 -> V_81 ) {
F_62 ( V_19 -> V_125 ) ;
for ( V_84 = 0 ; V_84 < 2 ; V_84 ++ ) {
F_62 ( V_19 -> V_107 [ V_84 ] ) ;
F_62 ( V_19 -> V_72 [ V_84 ] ) ;
}
}
}
static int F_67 ( struct V_100 * V_33 )
{
int V_126 ;
const struct V_127 * V_128 ;
char * V_129 ;
const struct V_130 * V_131 ;
F_9 ( L_20 ,
F_68 ( V_33 -> V_81 -> V_132 . V_133 ) ,
F_68 ( V_33 -> V_81 -> V_132 . V_134 ) ) ;
if ( ( F_68 ( V_33 -> V_81 -> V_132 . V_133 ) & 0x8000 )
!= 0x8000 ) {
F_9 ( L_21 ) ;
return 1 ;
}
switch ( F_68 ( V_33 -> V_81 -> V_132 . V_134 ) ) {
case V_135 :
V_129 = L_22 ;
break;
case V_136 :
V_129 = L_23 ;
break;
case V_137 :
V_129 = L_24 ;
break;
case V_138 :
V_129 = L_25 ;
break;
case V_139 :
V_129 = L_26 ;
break;
case V_140 :
V_129 = L_27 ;
break;
case V_141 :
V_129 = L_28 ;
break;
case V_142 :
V_129 = L_29 ;
break;
case V_143 :
V_129 = L_30 ;
break;
case V_144 :
V_129 = L_31 ;
break;
case V_145 :
V_129 = L_32 ;
break;
case V_146 :
V_129 = L_33 ;
break;
default:
F_69 ( & V_33 -> V_81 -> V_81 , L_34 ,
F_68 ( V_33 -> V_81 -> V_132 . V_134 ) ) ;
return 1 ;
}
if ( F_70 ( & V_131 , V_129 , & V_33 -> V_81 -> V_81 ) ) {
F_69 ( & V_33 -> V_81 -> V_81 , L_35 , V_129 ) ;
return ( 1 ) ;
}
F_9 ( L_36 , V_129 ) ;
V_126 = F_71 ( V_33 , 1 ) ;
V_128 = ( const struct V_127 * ) V_131 -> V_86 ;
while ( V_128 ) {
V_126 = F_72 ( V_33 , F_73 ( V_128 -> V_147 ) ,
( unsigned char * ) V_128 -> V_86 ,
F_74 ( V_128 -> V_114 ) , 0xa0 ) ;
if ( V_126 < 0 ) {
F_69 ( & V_33 -> V_81 -> V_81 , L_37 ,
V_126 , F_73 ( V_128 -> V_147 ) ,
V_128 -> V_86 , F_74 ( V_128 -> V_114 ) ) ;
break;
}
V_128 = F_75 ( V_128 ) ;
}
F_76 ( V_131 ) ;
V_126 = F_71 ( V_33 , 0 ) ;
return 1 ;
}
static struct V_148 const * F_77 ( struct V_100 const * V_33 ,
int V_85 )
{
struct V_149 * V_150 ;
struct V_148 * V_151 ;
int V_84 ;
V_150 = V_33 -> V_152 -> V_153 ;
for ( V_84 = 0 ; V_84 < V_150 -> V_154 . V_155 ; ++ V_84 ) {
V_151 = & V_150 -> V_85 [ V_84 ] . V_154 ;
if ( V_151 -> V_156 == V_85 )
return V_151 ;
}
F_78 ( & V_33 -> V_152 -> V_81 , L_38
L_39 , V_85 ) ;
return NULL ;
}
static struct V_64 * F_79 ( struct V_100 * V_33 , int V_85 ,
int V_157 , void * V_158 , char * V_59 , int V_114 ,
void (* F_80)( struct V_64 * ) )
{
struct V_64 * V_64 ;
struct V_148 const * V_159 ;
char const * V_160 ;
if ( V_85 == - 1 )
return NULL ;
F_9 ( L_40 , V_20 , V_85 ) ;
V_64 = F_81 ( 0 , V_123 ) ;
if ( V_64 == NULL ) {
F_9 ( L_41 , V_20 , V_85 ) ;
return NULL ;
}
if ( V_85 == 0 ) {
return V_64 ;
}
V_159 = F_77 ( V_33 , V_85 ) ;
if ( ! V_159 ) {
return V_64 ;
}
if ( F_82 ( V_159 ) ) {
V_160 = L_42 ;
F_83 ( V_64 , V_33 -> V_81 ,
F_84 ( V_33 -> V_81 , V_85 ) | V_157 ,
V_59 , V_114 , F_80 , V_158 ,
V_159 -> V_161 ) ;
} else if ( F_85 ( V_159 ) ) {
V_160 = L_43 ;
F_86 ( V_64 , V_33 -> V_81 ,
F_87 ( V_33 -> V_81 , V_85 ) | V_157 ,
V_59 , V_114 , F_80 , V_158 ) ;
} else {
F_78 ( & V_33 -> V_152 -> V_81 ,
L_44 ,
F_88 ( V_159 ) ) ;
F_89 ( V_64 ) ;
return NULL ;
}
F_9 ( L_45 ,
V_20 , V_64 , V_160 , V_85 ) ;
return V_64 ;
}
static void F_90 ( struct V_100 * V_33 )
{
int V_84 , V_162 ;
struct V_119 * V_120 ;
const struct V_26 * V_27 ;
struct V_15 * V_16 ;
struct V_18 * V_19 ;
struct V_163 * V_164 ;
int V_165 ;
F_9 ( L_4 , V_20 ) ;
V_120 = F_60 ( V_33 ) ;
V_27 = V_120 -> V_29 ;
V_164 = & V_166 [ V_27 -> V_69 ] ;
V_120 -> V_167 = F_79
( V_33 , V_27 -> V_168 , V_169 ,
V_33 , V_120 -> V_170 , V_171 ,
V_164 -> V_172 ) ;
V_120 -> V_173 = F_79
( V_33 , V_27 -> V_174 , V_169 ,
V_33 , V_120 -> V_175 , V_176 ,
F_49 ) ;
V_120 -> V_177 = F_79
( V_33 , V_27 -> V_178 , V_179 ,
V_33 , V_120 -> V_180 , V_181 ,
V_164 -> V_182 ) ;
for ( V_84 = 0 ; V_84 < V_27 -> V_102 ; V_84 ++ ) {
V_16 = V_33 -> V_16 [ V_84 ] ;
V_19 = F_10 ( V_16 ) ;
V_165 = V_27 -> V_183 [ V_84 ] ;
for ( V_162 = 0 ; V_162 <= V_27 -> V_184 ; ++ V_162 , ++ V_165 ) {
V_19 -> V_107 [ V_162 ] = F_79
( V_33 , V_165 , V_169 , V_16 ,
V_19 -> V_185 [ V_162 ] , 64 ,
V_164 -> V_186 ) ;
}
for (; V_162 < 2 ; ++ V_162 )
V_19 -> V_107 [ V_162 ] = NULL ;
V_165 = V_27 -> V_187 [ V_84 ] ;
for ( V_162 = 0 ; V_162 <= V_27 -> V_83 ; ++ V_162 , ++ V_165 ) {
V_19 -> V_72 [ V_162 ] = F_79
( V_33 , V_165 , V_179 , V_16 ,
V_19 -> V_188 [ V_162 ] , 64 ,
V_164 -> V_189 ) ;
}
for (; V_162 < 2 ; ++ V_162 )
V_19 -> V_72 [ V_162 ] = NULL ;
V_19 -> V_125 = F_79
( V_33 , V_27 -> V_190 [ V_84 ] , V_169 ,
V_16 , V_19 -> V_191 , 1 , V_164 -> V_192 ) ;
V_19 -> V_193 = F_79
( V_33 , V_27 -> V_194 [ V_84 ] , V_179 ,
V_16 , V_19 -> V_195 , 64 ,
V_164 -> V_196 ) ;
}
}
static int F_91 ( T_3 V_24 , T_3 V_36 , T_4 * V_197 ,
T_4 * V_198 , T_4 * V_199 , int V_200 )
{
T_3 V_201 ,
div ,
V_202 ;
F_9 ( L_46 , V_20 , V_24 ) ;
V_201 = V_24 * 16L ;
if ( V_201 == 0 )
return V_203 ;
if ( V_24 > 57600 )
return V_203 ;
div = V_36 / V_201 ;
if ( div == 0 )
return V_203 ;
else
V_202 = 0 - div ;
if ( div > 0xffff )
return V_203 ;
if ( V_198 )
* V_198 = ( T_4 ) ( V_202 & 0xff ) ;
if ( V_197 )
* V_197 = ( T_4 ) ( ( V_202 >> 8 ) & 0xff ) ;
if ( V_198 && V_197 )
F_9 ( L_47 ,
V_20 , V_24 , * V_197 , * V_198 ) ;
return V_37 ;
}
static int F_92 ( T_3 V_24 , T_3 V_36 , T_4 * V_197 ,
T_4 * V_198 , T_4 * V_199 , int V_200 )
{
T_3 V_201 ,
div ;
F_9 ( L_46 , V_20 , V_24 ) ;
V_201 = V_24 * 16L ;
if ( V_201 == 0 )
return V_203 ;
div = V_36 / V_201 ;
if ( div == 0 )
return V_203 ;
if ( div > 0xffff )
return V_203 ;
if ( V_198 )
* V_198 = ( T_4 ) ( div & 0xff ) ;
if ( V_197 )
* V_197 = ( T_4 ) ( ( div >> 8 ) & 0xff ) ;
if ( V_198 && V_197 )
F_9 ( L_47 ,
V_20 , V_24 , * V_197 , * V_198 ) ;
return V_37 ;
}
static int F_93 ( T_3 V_24 , T_3 V_36 , T_4 * V_197 ,
T_4 * V_198 , T_4 * V_199 , int V_200 )
{
T_3 V_201 ,
V_204 ,
div ,
V_205 ,
V_206 ,
V_207 ;
T_4 V_208 ;
int V_84 ;
F_9 ( L_46 , V_20 , V_24 ) ;
V_201 = V_24 * 16L ;
if ( V_201 == 0 )
return V_203 ;
V_207 = 0xffffffff ;
V_208 = 0 ;
for ( V_84 = 8 ; V_84 <= 0xff ; ++ V_84 ) {
V_204 = ( V_36 * 8 ) / ( T_3 ) V_84 ;
div = V_204 / V_201 ;
if ( div == 0 )
continue;
V_205 = V_204 / div ;
V_206 = ( V_205 > V_201 ) ? ( V_205 - V_201 ) : ( V_201 - V_205 ) ;
if ( V_206 < V_207 ) {
V_208 = V_84 ;
V_207 = V_206 ;
}
}
if ( V_208 == 0 )
return V_203 ;
V_204 = ( V_36 * 8 ) / ( T_3 ) V_208 ;
div = V_204 / V_201 ;
if ( V_198 )
* V_198 = ( T_4 ) ( div & 0xff ) ;
if ( V_197 )
* V_197 = ( T_4 ) ( ( div >> 8 ) & 0xff ) ;
if ( V_199 ) {
* V_199 = V_208 ;
}
return V_37 ;
}
static int F_94 ( T_3 V_24 , T_3 V_36 , T_4 * V_197 ,
T_4 * V_198 , T_4 * V_199 , int V_200 )
{
T_3 V_201 ,
div ,
V_202 ;
F_9 ( L_46 , V_20 , V_24 ) ;
V_201 = V_24 * 16L ;
if ( V_201 == 0 )
return V_203 ;
div = V_209 / V_201 ;
if ( div == 0 )
return V_203 ;
else
V_202 = 0 - div ;
if ( V_200 == 0 ) {
if ( div > 0xffff )
return V_203 ;
} else {
if ( V_200 == 1 ) {
if ( div > 0xff )
return V_203 ;
} else
return V_203 ;
}
if ( V_198 )
* V_198 = ( T_4 ) ( V_202 & 0xff ) ;
if ( V_197 )
* V_197 = ( T_4 ) ( ( V_202 >> 8 ) & 0xff ) ;
F_9 ( L_48 , V_20 , V_24 ) ;
return V_37 ;
}
static int F_32 ( struct V_100 * V_33 ,
struct V_15 * V_16 ,
int V_210 )
{
struct V_211 V_99 ;
struct V_119 * V_120 ;
struct V_18 * V_19 ;
const struct V_26 * V_27 ;
int V_193 ;
struct V_64 * V_65 ;
int V_25 , V_66 ;
F_9 ( L_49 , V_20 , V_210 ) ;
V_120 = F_60 ( V_33 ) ;
V_19 = F_10 ( V_16 ) ;
V_27 = V_120 -> V_29 ;
V_25 = V_16 -> V_32 - V_16 -> V_33 -> V_34 ;
V_193 = V_27 -> V_194 [ V_16 -> V_32 ] ;
V_65 = V_19 -> V_193 ;
F_9 ( L_50 , V_20 , F_19 ( V_65 -> V_73 ) ) ;
if ( V_65 == NULL ) {
F_9 ( L_51 , V_20 ) ;
return - 1 ;
}
if ( ( V_210 + 1 ) > V_19 -> V_97 )
V_19 -> V_97 = V_210 + 1 ;
if ( V_65 -> V_74 == - V_75 ) {
F_66 ( 5 ) ;
return - 1 ;
}
memset ( & V_99 , 0 , sizeof( struct V_211 ) ) ;
if ( V_19 -> V_121 != V_19 -> V_38 ) {
V_19 -> V_121 = V_19 -> V_38 ;
V_99 . V_212 = 0xff ;
if ( V_27 -> V_35
( V_19 -> V_38 , V_27 -> V_36 , & V_99 . V_213 ,
& V_99 . V_214 , & V_99 . V_199 , V_25 ) == V_203 ) {
F_9 ( L_52 ,
V_20 , V_19 -> V_38 ) ;
V_99 . V_214 = 0 ;
V_99 . V_213 = 125 ;
V_99 . V_199 = 10 ;
}
V_99 . V_215 = 0xff ;
}
V_99 . V_216 = ( V_19 -> V_28 & V_217 ) ? V_218 : V_219 ;
switch ( V_19 -> V_28 & V_220 ) {
case V_221 :
V_99 . V_216 |= V_222 ;
break;
case V_223 :
V_99 . V_216 |= V_224 ;
break;
case V_225 :
V_99 . V_216 |= V_226 ;
break;
case V_227 :
V_99 . V_216 |= V_228 ;
break;
}
if ( V_19 -> V_28 & V_229 ) {
V_99 . V_216 |= ( V_19 -> V_28 & V_230 ) ?
V_231 : V_232 ;
}
V_99 . V_233 = 0xff ;
V_99 . V_234 = ( V_19 -> V_39 == V_41 ) ;
V_99 . V_235 = 0 ;
V_99 . V_236 = 0xff ;
V_99 . V_237 = 16 ;
V_99 . V_238 = 17 ;
V_99 . V_239 = 19 ;
if ( V_210 == 1 ) {
V_99 . V_240 = 1 ;
V_99 . V_241 = 0 ;
V_99 . V_242 = 0 ;
V_99 . V_243 = 0 ;
V_99 . V_244 = 1 ;
V_99 . V_245 = 0 ;
V_99 . V_246 = 1 ;
V_99 . V_247 = 0 ;
V_99 . V_248 = 0 ;
V_99 . V_249 = 0xff ;
}
else if ( V_210 == 2 ) {
V_99 . V_240 = 0 ;
V_99 . V_241 = 1 ;
V_99 . V_242 = 0 ;
V_99 . V_243 = 0 ;
V_99 . V_244 = 0 ;
V_99 . V_245 = 1 ;
V_99 . V_246 = 1 ;
V_99 . V_247 = 0 ;
V_99 . V_248 = 0 ;
V_99 . V_249 = 0 ;
}
else {
V_99 . V_240 = ( ! V_19 -> V_21 ) ;
V_99 . V_241 = 0 ;
V_99 . V_242 = 0 ;
V_99 . V_243 = ( V_19 -> V_21 ) ;
V_99 . V_244 = 0 ;
V_99 . V_245 = 0 ;
V_99 . V_246 = 0 ;
V_99 . V_247 = 0 ;
V_99 . V_248 = 0 ;
V_99 . V_249 = 0x0 ;
}
V_99 . V_250 = 0xff ;
V_99 . V_251 = V_19 -> V_45 ;
V_99 . V_252 = 0xff ;
V_99 . V_253 = V_19 -> V_47 ;
V_19 -> V_97 = 0 ;
memcpy ( V_65 -> V_79 , & V_99 , sizeof( V_99 ) ) ;
V_65 -> V_80 = sizeof( V_99 ) ;
V_65 -> V_81 = V_33 -> V_81 ;
V_66 = F_22 ( V_65 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_53 , V_20 , V_66 ) ;
#if 0
else {
dbg("%s - usb_submit_urb(%d) OK %d bytes (end %d)", __func__
outcont_urb, this_urb->transfer_buffer_length,
usb_pipeendpoint(this_urb->pipe));
}
#endif
return 0 ;
}
static int F_41 ( struct V_100 * V_33 ,
struct V_15 * V_16 ,
int V_210 )
{
struct V_254 V_99 ;
struct V_119 * V_120 ;
struct V_18 * V_19 ;
const struct V_26 * V_27 ;
struct V_64 * V_65 ;
int V_25 , V_66 ;
F_9 ( L_4 , V_20 ) ;
V_120 = F_60 ( V_33 ) ;
V_19 = F_10 ( V_16 ) ;
V_27 = V_120 -> V_29 ;
V_25 = V_16 -> V_32 - V_16 -> V_33 -> V_34 ;
V_65 = V_19 -> V_193 ;
if ( V_65 == NULL ) {
F_9 ( L_51 , V_20 ) ;
return - 1 ;
}
if ( ( V_210 + 1 ) > V_19 -> V_97 )
V_19 -> V_97 = V_210 + 1 ;
if ( V_65 -> V_74 == - V_75 ) {
F_9 ( L_54 , V_20 ) ;
F_66 ( 5 ) ;
return - 1 ;
}
memset ( & V_99 , 0 , sizeof( struct V_254 ) ) ;
V_99 . V_255 = 1 ;
if ( V_27 -> V_35 ( V_19 -> V_38 , V_27 -> V_36 ,
& V_99 . V_213 , & V_99 . V_214 , NULL , V_25 ) == V_203 ) {
F_9 ( L_55 ,
V_20 , V_19 -> V_38 ) ;
V_99 . V_214 = 0xff ;
V_99 . V_213 = 0xb2 ;
}
V_99 . V_256 = 0 ;
V_99 . V_234 = ( V_19 -> V_39 == V_41 ) ;
V_99 . V_235 = 0 ;
V_99 . V_257 = V_19 -> V_45 ;
V_99 . V_258 = V_19 -> V_47 ;
V_99 . V_237 = 16 ;
V_99 . V_259 = 10 ;
V_99 . V_260 = 45 ;
V_99 . V_238 = 17 ;
V_99 . V_239 = 19 ;
if ( V_210 == 1 ) {
V_99 . V_240 = 1 ;
V_99 . V_241 = 0 ;
V_99 . V_242 = 0 ;
V_99 . V_261 = 0 ;
V_99 . V_243 = 0 ;
V_99 . V_244 = 1 ;
V_99 . V_245 = 0 ;
V_99 . V_246 = 1 ;
V_99 . V_247 = 0 ;
V_99 . V_248 = 0 ;
V_99 . V_249 = 0xff ;
}
else if ( V_210 == 2 ) {
V_99 . V_240 = 0 ;
V_99 . V_241 = 1 ;
V_99 . V_242 = 0 ;
V_99 . V_261 = 0 ;
V_99 . V_243 = 0 ;
V_99 . V_244 = 0 ;
V_99 . V_245 = 1 ;
V_99 . V_246 = 1 ;
V_99 . V_247 = 0 ;
V_99 . V_248 = 0 ;
V_99 . V_249 = 0 ;
}
else {
V_99 . V_240 = ( ! V_19 -> V_21 ) ;
V_99 . V_241 = 0 ;
V_99 . V_242 = 0 ;
V_99 . V_261 = 0 ;
V_99 . V_243 = ( V_19 -> V_21 ) ;
V_99 . V_244 = 0 ;
V_99 . V_245 = 0 ;
V_99 . V_246 = 0 ;
V_99 . V_247 = 0 ;
V_99 . V_248 = 0 ;
V_99 . V_249 = 0x0 ;
}
V_19 -> V_97 = 0 ;
memcpy ( V_65 -> V_79 , & V_99 , sizeof( V_99 ) ) ;
V_65 -> V_80 = sizeof( V_99 ) ;
V_65 -> V_81 = V_33 -> V_81 ;
V_66 = F_22 ( V_65 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_56 , V_20 ) ;
#if 0
else {
dbg("%s - usb_submit_urb(setup) OK %d bytes", __func__,
this_urb->transfer_buffer_length);
}
#endif
return 0 ;
}
static int F_45 ( struct V_100 * V_33 ,
struct V_15 * V_16 ,
int V_210 )
{
struct V_262 V_99 ;
struct V_263 * V_264 = NULL ;
struct V_119 * V_120 ;
struct V_18 * V_19 ;
const struct V_26 * V_27 ;
struct V_64 * V_65 ;
int V_66 , V_25 ;
F_9 ( L_4 , V_20 ) ;
V_120 = F_60 ( V_33 ) ;
V_19 = F_10 ( V_16 ) ;
V_27 = V_120 -> V_29 ;
V_65 = V_120 -> V_177 ;
V_25 = V_16 -> V_32 - V_16 -> V_33 -> V_34 ;
if ( V_65 == NULL ) {
F_9 ( L_57 , V_20 , V_16 -> V_32 ) ;
return - 1 ;
}
F_9 ( L_58 ,
V_20 , F_19 ( V_65 -> V_73 ) ,
V_16 -> V_32 , V_25 ) ;
if ( ( V_210 + 1 ) > V_19 -> V_97 )
V_19 -> V_97 = V_210 + 1 ;
if ( V_65 -> V_74 == - V_75 ) {
F_66 ( 5 ) ;
return - 1 ;
}
memset ( & V_99 , 0 , sizeof( struct V_262 ) ) ;
V_99 . V_113 = V_25 ;
if ( V_19 -> V_121 != V_19 -> V_38 ) {
V_19 -> V_121 = V_19 -> V_38 ;
V_99 . V_212 = 0xff ;
if ( V_27 -> V_35
( V_19 -> V_38 , V_27 -> V_36 , & V_99 . V_213 ,
& V_99 . V_214 , & V_99 . V_199 , V_25 ) == V_203 ) {
F_9 ( L_52 ,
V_20 , V_19 -> V_38 ) ;
V_99 . V_214 = 0 ;
V_99 . V_213 = 125 ;
V_99 . V_199 = 10 ;
}
}
V_99 . V_216 = ( V_19 -> V_28 & V_217 ) ? V_218 : V_219 ;
switch ( V_19 -> V_28 & V_220 ) {
case V_221 :
V_99 . V_216 |= V_222 ;
break;
case V_223 :
V_99 . V_216 |= V_224 ;
break;
case V_225 :
V_99 . V_216 |= V_226 ;
break;
case V_227 :
V_99 . V_216 |= V_228 ;
break;
}
if ( V_19 -> V_28 & V_229 ) {
V_99 . V_216 |= ( V_19 -> V_28 & V_230 ) ?
V_231 : V_232 ;
}
V_99 . V_233 = 0xff ;
V_99 . V_234 = ( V_19 -> V_39 == V_41 ) ;
V_99 . V_235 = 0 ;
V_99 . V_236 = 0xff ;
V_99 . V_237 = 16 ;
V_99 . V_238 = 17 ;
V_99 . V_239 = 19 ;
if ( V_210 == 1 ) {
V_99 . V_240 = 1 ;
V_99 . V_241 = 0 ;
V_99 . V_242 = 0 ;
V_99 . V_243 = 0 ;
V_99 . V_244 = 1 ;
V_99 . V_245 = 0 ;
V_99 . V_246 = 1 ;
V_99 . V_247 = 0 ;
V_99 . V_248 = 0 ;
V_99 . V_249 = 0xff ;
V_99 . V_265 = 1 ;
V_99 . V_266 = 0 ;
}
else if ( V_210 == 2 ) {
V_99 . V_240 = 0 ;
V_99 . V_241 = 1 ;
V_99 . V_242 = 0 ;
V_99 . V_243 = 0 ;
V_99 . V_244 = 0 ;
V_99 . V_245 = 1 ;
V_99 . V_246 = 1 ;
V_99 . V_247 = 0 ;
V_99 . V_248 = 0 ;
V_99 . V_249 = 0 ;
V_99 . V_265 = 0 ;
V_99 . V_266 = 1 ;
}
else {
V_99 . V_240 = ( ! V_19 -> V_21 ) ;
V_99 . V_241 = 0 ;
V_99 . V_242 = 0 ;
V_99 . V_243 = ( V_19 -> V_21 ) ;
V_99 . V_244 = 0 ;
V_99 . V_245 = 0 ;
V_99 . V_246 = 0 ;
V_99 . V_247 = 0 ;
V_99 . V_248 = 0 ;
V_99 . V_249 = 0x0 ;
V_99 . V_265 = 0 ;
V_99 . V_266 = 0 ;
}
V_99 . V_267 = 0xff ;
V_99 . V_257 = V_19 -> V_45 ;
V_99 . V_268 = 0xff ;
V_99 . V_258 = V_19 -> V_47 ;
V_19 -> V_97 = 0 ;
if ( V_27 -> V_269 == V_270 ) {
V_264 = ( void * ) ( V_120 -> V_271 ) ;
V_264 -> V_272 = V_273 | V_179 ;
V_264 -> V_274 = 0xB0 ; ;
V_264 -> V_275 = 0 ;
V_264 -> V_276 = 0 ;
V_264 -> V_277 = F_95 ( sizeof( V_99 ) ) ;
memcpy ( V_120 -> V_180 , & V_99 , sizeof( V_99 ) ) ;
F_96 ( V_65 , V_33 -> V_81 ,
F_97 ( V_33 -> V_81 , 0 ) ,
( unsigned char * ) V_264 , V_120 -> V_180 ,
sizeof( V_99 ) , F_44 , V_33 ) ;
} else {
memcpy ( V_65 -> V_79 , & V_99 , sizeof( V_99 ) ) ;
V_65 -> V_80 = sizeof( V_99 ) ;
V_65 -> V_81 = V_33 -> V_81 ;
}
V_66 = F_22 ( V_65 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_53 , V_20 , V_66 ) ;
#if 0
else {
dbg("%s - usb_submit_urb(%d) OK %d bytes (end %d)", __func__,
outcont_urb, this_urb->transfer_buffer_length,
usb_pipeendpoint(this_urb->pipe));
}
#endif
return 0 ;
}
static int F_54 ( struct V_100 * V_33 ,
struct V_15 * V_16 ,
int V_210 )
{
struct V_278 V_99 ;
struct V_119 * V_120 ;
struct V_18 * V_19 ;
const struct V_26 * V_27 ;
struct V_64 * V_65 ;
int V_66 ;
T_4 V_199 ;
F_9 ( L_4 , V_20 ) ;
V_120 = F_60 ( V_33 ) ;
V_19 = F_10 ( V_16 ) ;
V_27 = V_120 -> V_29 ;
V_65 = V_19 -> V_193 ;
if ( V_65 == NULL ) {
F_9 ( L_51 , V_20 ) ;
return - 1 ;
}
if ( ( V_210 + 1 ) > V_19 -> V_97 )
V_19 -> V_97 = V_210 + 1 ;
if ( V_65 -> V_74 == - V_75 ) {
F_9 ( L_54 , V_20 ) ;
F_66 ( 5 ) ;
return - 1 ;
}
memset ( & V_99 , 0 , sizeof( struct V_278 ) ) ;
if ( V_19 -> V_121 != V_19 -> V_38 ) {
V_19 -> V_121 = V_19 -> V_38 ;
V_99 . V_212 = 0x01 ;
if ( V_27 -> V_35
( V_19 -> V_38 , V_27 -> V_36 , & V_99 . V_213 ,
& V_99 . V_214 , & V_199 , 0 ) == V_203 ) {
F_9 ( L_52 ,
V_20 , V_19 -> V_38 ) ;
V_19 -> V_38 = 9600 ;
V_27 -> V_35 ( V_19 -> V_38 , V_27 -> V_36 ,
& V_99 . V_213 , & V_99 . V_214 , & V_199 , 0 ) ;
}
V_99 . V_279 = 1 ;
V_99 . V_280 = 1 ;
}
if ( V_19 -> V_38 > 57600 ) {
V_99 . V_281 = V_282 ;
V_99 . V_283 = V_284 ;
} else {
V_99 . V_281 = V_285 ;
V_99 . V_283 = V_286 ;
}
V_99 . V_216 = ( V_19 -> V_28 & V_217 ) ? V_218 : V_219 ;
switch ( V_19 -> V_28 & V_220 ) {
case V_221 :
V_99 . V_216 |= V_222 ;
break;
case V_223 :
V_99 . V_216 |= V_224 ;
break;
case V_225 :
V_99 . V_216 |= V_226 ;
break;
case V_227 :
V_99 . V_216 |= V_228 ;
break;
}
if ( V_19 -> V_28 & V_229 ) {
V_99 . V_216 |= ( V_19 -> V_28 & V_230 ) ?
V_231 : V_232 ;
}
if ( V_19 -> V_122 != V_19 -> V_28 ) {
V_19 -> V_122 = V_19 -> V_28 ;
V_99 . V_233 = 0x01 ;
}
if ( V_19 -> V_39 == V_41 )
V_99 . V_287 = V_288 ;
V_99 . V_289 = 0x01 ;
V_99 . V_290 = 0x01 ;
V_99 . V_291 = 16 ;
V_99 . V_292 = 16 ;
V_99 . V_293 = 0 ;
V_99 . V_238 = 17 ;
V_99 . V_239 = 19 ;
if ( V_210 == 1 ) {
V_99 . V_294 = 1 ;
V_99 . V_246 = 1 ;
V_99 . V_243 = ( V_19 -> V_21 ) ;
}
else if ( V_210 == 2 )
V_99 . V_294 = 0 ;
else {
V_99 . V_294 = 1 ;
V_99 . V_243 = ( V_19 -> V_21 ) ;
}
V_99 . V_267 = 0x01 ;
V_99 . V_257 = V_19 -> V_45 ;
V_99 . V_268 = 0x01 ;
V_99 . V_258 = V_19 -> V_47 ;
V_19 -> V_97 = 0 ;
memcpy ( V_65 -> V_79 , & V_99 , sizeof( V_99 ) ) ;
V_65 -> V_80 = sizeof( V_99 ) ;
V_65 -> V_81 = V_33 -> V_81 ;
V_66 = F_22 ( V_65 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_53 , V_20 , V_66 ) ;
return 0 ;
}
static int F_57 ( struct V_100 * V_33 ,
struct V_15 * V_16 ,
int V_210 )
{
struct V_295 V_99 ;
struct V_119 * V_120 ;
struct V_18 * V_19 ;
const struct V_26 * V_27 ;
struct V_64 * V_65 ;
int V_66 , V_25 ;
F_9 ( L_4 , V_20 ) ;
V_120 = F_60 ( V_33 ) ;
V_19 = F_10 ( V_16 ) ;
V_27 = V_120 -> V_29 ;
V_65 = V_120 -> V_177 ;
V_25 = V_16 -> V_32 - V_16 -> V_33 -> V_34 ;
if ( V_65 == NULL ) {
F_9 ( L_57 , V_20 ,
V_16 -> V_32 ) ;
return - 1 ;
}
if ( ( V_210 + 1 ) > V_19 -> V_97 )
V_19 -> V_97 = V_210 + 1 ;
if ( V_65 -> V_74 == - V_75 ) {
F_66 ( 5 ) ;
return - 1 ;
}
memset ( & V_99 , 0 , sizeof( struct V_295 ) ) ;
V_99 . V_16 = V_25 ;
if ( V_19 -> V_121 != V_19 -> V_38 ) {
V_19 -> V_121 = V_19 -> V_38 ;
V_99 . V_212 = 0xff ;
if ( V_27 -> V_35
( V_19 -> V_38 , V_27 -> V_36 , & V_99 . V_213 ,
& V_99 . V_214 , & V_99 . V_199 , V_25 ) == V_203 ) {
F_9 ( L_52 ,
V_20 , V_19 -> V_38 ) ;
V_99 . V_214 = 0 ;
V_99 . V_213 = 125 ;
V_99 . V_199 = 10 ;
}
V_99 . V_215 = 0xff ;
}
V_99 . V_216 = ( V_19 -> V_28 & V_217 ) ? V_218 : V_219 ;
switch ( V_19 -> V_28 & V_220 ) {
case V_221 :
V_99 . V_216 |= V_222 ;
break;
case V_223 :
V_99 . V_216 |= V_224 ;
break;
case V_225 :
V_99 . V_216 |= V_226 ;
break;
case V_227 :
V_99 . V_216 |= V_228 ;
break;
}
if ( V_19 -> V_28 & V_229 ) {
V_99 . V_216 |= ( V_19 -> V_28 & V_230 ) ?
V_231 : V_232 ;
}
V_99 . V_233 = 0xff ;
V_99 . V_234 = ( V_19 -> V_39 == V_41 ) ;
V_99 . V_235 = 0 ;
V_99 . V_236 = 0xff ;
V_99 . V_237 = 16 ;
V_99 . V_238 = 17 ;
V_99 . V_239 = 19 ;
if ( V_210 == 1 ) {
V_99 . V_240 = 1 ;
V_99 . V_241 = 0 ;
V_99 . V_242 = 0 ;
V_99 . V_243 = 0 ;
V_99 . V_244 = 1 ;
V_99 . V_245 = 0 ;
V_99 . V_246 = 1 ;
V_99 . V_247 = 0 ;
V_99 . V_248 = 0 ;
V_99 . V_249 = 0xff ;
} else if ( V_210 == 2 ) {
V_99 . V_240 = 0 ;
V_99 . V_241 = 1 ;
V_99 . V_242 = 0 ;
V_99 . V_243 = 0 ;
V_99 . V_244 = 0 ;
V_99 . V_245 = 1 ;
V_99 . V_246 = 1 ;
V_99 . V_247 = 0 ;
V_99 . V_248 = 0 ;
V_99 . V_249 = 0 ;
} else {
V_99 . V_240 = ( ! V_19 -> V_21 ) ;
V_99 . V_241 = 0 ;
V_99 . V_242 = 0 ;
V_99 . V_243 = ( V_19 -> V_21 ) ;
V_99 . V_244 = 0 ;
V_99 . V_245 = 0 ;
V_99 . V_246 = 0 ;
V_99 . V_247 = 0 ;
V_99 . V_248 = 0 ;
V_99 . V_249 = 0x0 ;
}
V_99 . V_250 = 0xff ;
V_99 . V_251 = V_19 -> V_45 ;
V_99 . V_252 = 0xff ;
V_99 . V_253 = V_19 -> V_47 ;
V_19 -> V_97 = 0 ;
memcpy ( V_65 -> V_79 , & V_99 , sizeof( V_99 ) ) ;
V_65 -> V_80 = sizeof( V_99 ) ;
V_65 -> V_81 = V_33 -> V_81 ;
V_66 = F_22 ( V_65 , V_82 ) ;
if ( V_66 != 0 )
F_9 ( L_53 , V_20 ,
V_66 ) ;
return 0 ;
}
static void F_11 ( struct V_15 * V_16 , int V_210 )
{
struct V_100 * V_33 = V_16 -> V_33 ;
struct V_119 * V_120 ;
const struct V_26 * V_27 ;
F_9 ( L_4 , V_20 ) ;
V_120 = F_60 ( V_33 ) ;
V_27 = V_120 -> V_29 ;
switch ( V_27 -> V_69 ) {
case V_296 :
F_32 ( V_33 , V_16 , V_210 ) ;
break;
case V_297 :
F_41 ( V_33 , V_16 , V_210 ) ;
break;
case V_298 :
F_45 ( V_33 , V_16 , V_210 ) ;
break;
case V_70 :
F_54 ( V_33 , V_16 , V_210 ) ;
break;
case V_299 :
F_57 ( V_33 , V_16 , V_210 ) ;
break;
}
}
static int F_98 ( struct V_100 * V_33 )
{
int V_84 , V_66 ;
struct V_15 * V_16 ;
struct V_119 * V_120 ;
struct V_18 * V_19 ;
const struct V_26 * V_27 ;
F_9 ( L_4 , V_20 ) ;
for ( V_84 = 0 ; ( V_27 = V_300 [ V_84 ] ) != NULL ; ++ V_84 )
if ( V_27 -> V_269 ==
F_68 ( V_33 -> V_81 -> V_132 . V_134 ) )
break;
if ( V_27 == NULL ) {
F_69 ( & V_33 -> V_81 -> V_81 , L_59 ,
V_20 , F_68 ( V_33 -> V_81 -> V_132 . V_134 ) ) ;
return 1 ;
}
V_120 = F_99 ( sizeof( struct V_119 ) , V_123 ) ;
if ( ! V_120 ) {
F_9 ( L_60 ,
V_20 ) ;
return - V_301 ;
}
V_120 -> V_29 = V_27 ;
F_100 ( V_33 , V_120 ) ;
for ( V_84 = 0 ; V_84 < V_33 -> V_102 ; V_84 ++ ) {
V_16 = V_33 -> V_16 [ V_84 ] ;
V_19 = F_99 ( sizeof( struct V_18 ) ,
V_123 ) ;
if ( ! V_19 ) {
F_9 ( L_61 , V_20 , V_84 ) ;
return 1 ;
}
V_19 -> V_29 = V_27 ;
F_101 ( V_16 , V_19 ) ;
}
F_90 ( V_33 ) ;
if ( V_120 -> V_167 != NULL ) {
V_120 -> V_167 -> V_81 = V_33 -> V_81 ;
V_66 = F_22 ( V_120 -> V_167 , V_123 ) ;
if ( V_66 != 0 )
F_9 ( L_62 , V_20 ,
V_66 ) ;
}
if ( V_120 -> V_173 != NULL ) {
V_120 -> V_173 -> V_81 = V_33 -> V_81 ;
V_66 = F_22 ( V_120 -> V_173 , V_123 ) ;
if ( V_66 != 0 )
F_9 ( L_63 , V_20 ,
V_66 ) ;
}
return 0 ;
}
static void F_102 ( struct V_100 * V_33 )
{
int V_84 , V_162 ;
struct V_15 * V_16 ;
struct V_119 * V_120 ;
struct V_18 * V_19 ;
F_9 ( L_4 , V_20 ) ;
V_120 = F_60 ( V_33 ) ;
F_62 ( V_120 -> V_167 ) ;
F_62 ( V_120 -> V_177 ) ;
F_62 ( V_120 -> V_173 ) ;
for ( V_84 = 0 ; V_84 < V_33 -> V_102 ; ++ V_84 ) {
V_16 = V_33 -> V_16 [ V_84 ] ;
V_19 = F_10 ( V_16 ) ;
F_62 ( V_19 -> V_125 ) ;
F_62 ( V_19 -> V_193 ) ;
for ( V_162 = 0 ; V_162 < 2 ; V_162 ++ ) {
F_62 ( V_19 -> V_107 [ V_162 ] ) ;
F_62 ( V_19 -> V_72 [ V_162 ] ) ;
}
}
F_89 ( V_120 -> V_167 ) ;
F_89 ( V_120 -> V_173 ) ;
F_89 ( V_120 -> V_177 ) ;
for ( V_84 = 0 ; V_84 < V_33 -> V_102 ; ++ V_84 ) {
V_16 = V_33 -> V_16 [ V_84 ] ;
V_19 = F_10 ( V_16 ) ;
F_89 ( V_19 -> V_125 ) ;
F_89 ( V_19 -> V_193 ) ;
for ( V_162 = 0 ; V_162 < 2 ; V_162 ++ ) {
F_89 ( V_19 -> V_107 [ V_162 ] ) ;
F_89 ( V_19 -> V_72 [ V_162 ] ) ;
}
}
}
static void F_103 ( struct V_100 * V_33 )
{
int V_84 ;
struct V_15 * V_16 ;
struct V_119 * V_120 ;
F_9 ( L_4 , V_20 ) ;
V_120 = F_60 ( V_33 ) ;
F_104 ( V_120 ) ;
for ( V_84 = 0 ; V_84 < V_33 -> V_102 ; V_84 ++ ) {
V_16 = V_33 -> V_16 [ V_84 ] ;
F_104 ( F_10 ( V_16 ) ) ;
}
}
