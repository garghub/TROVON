static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 = - 1 , V_10 = 0 ;
int V_11 ;
V_8 = ( V_4 -> V_12 == V_13 ) ? V_4 -> V_14 : V_4 -> V_15 ;
for ( V_11 = 0 ; V_11 < F_2 ( V_16 ) ; V_11 ++ ) {
V_6 = & V_16 [ V_11 ] ;
if ( V_9 != V_6 -> V_17 ) {
V_9 = V_6 -> V_17 ;
V_10 = F_3 ( V_8 , V_6 -> V_17 ) ;
}
if ( V_10 & V_6 -> V_18 )
F_4 ( V_4 -> V_19 + V_11 ) ;
}
return V_20 ;
}
static void F_5 ( struct V_6 * V_2 )
{
struct V_3 * V_4 = F_6 ( V_2 ) ;
F_7 ( & V_4 -> V_21 ) ;
}
static void F_8 ( struct V_6 * V_2 )
{
struct V_3 * V_4 = F_6 ( V_2 ) ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
static unsigned char V_22 [ 3 ] = { 0x0 , 0x0 , 0x0 } ;
unsigned char V_23 [ 3 ] ;
int V_11 ;
V_8 = ( V_4 -> V_12 == V_13 ) ? V_4 -> V_14 : V_4 -> V_15 ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ )
V_23 [ V_11 ] = V_22 [ V_11 ] ;
for ( V_11 = 0 ; V_11 < F_2 ( V_16 ) ; V_11 ++ ) {
V_6 = & V_16 [ V_11 ] ;
switch ( V_6 -> V_24 ) {
case V_25 :
V_23 [ 0 ] &= ~ V_6 -> V_26 ;
V_23 [ 0 ] |= V_6 -> V_18 ;
break;
case V_27 :
V_23 [ 1 ] &= ~ V_6 -> V_26 ;
V_23 [ 1 ] |= V_6 -> V_18 ;
break;
case V_28 :
V_23 [ 2 ] &= ~ V_6 -> V_26 ;
V_23 [ 2 ] |= V_6 -> V_18 ;
break;
default:
F_9 ( V_4 -> V_29 , L_1 ) ;
break;
}
}
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
if ( V_23 [ V_11 ] != V_22 [ V_11 ] ) {
V_22 [ V_11 ] = V_23 [ V_11 ] ;
F_10 ( V_8 , V_25 + V_11 , V_23 [ V_11 ] ) ;
}
}
F_11 ( & V_4 -> V_21 ) ;
}
static void F_12 ( struct V_6 * V_2 )
{
struct V_3 * V_4 = F_6 ( V_2 ) ;
V_16 [ V_2 -> V_1 - V_4 -> V_19 ] . V_18
= V_16 [ V_2 -> V_1 - V_4 -> V_19 ] . V_26 ;
}
static void F_13 ( struct V_6 * V_2 )
{
struct V_3 * V_4 = F_6 ( V_2 ) ;
V_16 [ V_2 -> V_1 - V_4 -> V_19 ] . V_18 = 0 ;
}
static int T_2 F_14 ( struct V_3 * V_4 ,
struct V_30 * V_31 )
{
struct V_7 * V_8 = ( V_4 -> V_12 == V_13 ) ? V_4 -> V_14 \
: V_4 -> V_15 ;
int V_2 ;
int V_32 ;
if ( ! V_31 || ! V_31 -> V_33 )
return - V_34 ;
V_2 = 0 ;
V_2 |= ( V_31 -> V_33 -> V_35 << 1 ) & V_36 ;
V_2 |= ( V_31 -> V_33 -> V_37 << 3 ) & V_38 ;
V_2 |= ( V_31 -> V_33 -> V_39 << 5 ) & V_40 ;
V_2 |= ( V_31 -> V_33 -> V_41 << 7 ) & V_42 ;
if ( V_2 ) {
V_32 = F_10 ( V_8 , V_43 , V_2 ) ;
if ( V_32 < 0 )
goto V_44;
}
if ( V_31 -> V_33 -> V_45 ) {
V_2 = V_31 -> V_33 -> V_45 ;
V_32 = F_10 ( V_8 , V_46 , V_2 ) ;
if ( V_32 < 0 )
goto V_44;
}
V_2 = 0 ;
V_2 |= V_31 -> V_33 -> V_47 & V_48 ;
V_2 |= ( V_31 -> V_33 -> V_49 << 5 ) & V_50 ;
if ( V_2 ) {
V_32 = F_10 ( V_8 , V_51 , V_2 ) ;
if ( V_32 < 0 )
goto V_44;
}
V_32 = F_15 ( V_8 , V_43 ,
V_52 , V_52 ) ;
V_44:
return V_32 ;
}
static int T_2 F_16 ( struct V_3 * V_4 ,
struct V_30 * V_31 )
{
struct V_7 * V_8 = ( V_4 -> V_12 == V_13 ) ? V_4 -> V_14 \
: V_4 -> V_15 ;
unsigned char V_53 [ V_54 ] ;
unsigned long V_55 = V_56 | V_57 ;
int V_11 , V_2 , V_23 , V_32 = - V_34 ;
int V_58 ;
if ( ! V_31 || ! V_31 -> V_19 ) {
F_17 ( V_4 -> V_29 , L_2 ) ;
return - V_34 ;
}
V_23 = V_59 | V_60
| V_61 ;
V_2 = 0 ;
V_4 -> V_62 = 0 ;
if ( V_31 && V_31 -> V_62 ) {
V_2 |= V_60 ;
V_4 -> V_62 = 1 ;
}
V_32 = F_15 ( V_8 , V_63 , V_23 , V_2 ) ;
if ( V_32 < 0 )
goto V_44;
memset ( V_53 , 0 , V_54 ) ;
V_32 = F_18 ( V_8 , V_25 ,
V_54 , V_53 ) ;
if ( V_32 < 0 )
goto V_44;
if ( V_4 -> V_62 ) {
memset ( V_53 , 0xFF , V_54 ) ;
V_32 = F_18 ( V_8 , V_64 ,
V_54 , V_53 ) ;
} else {
V_32 = F_19 ( V_8 , V_64 ,
V_54 , V_53 ) ;
}
if ( V_32 < 0 )
goto V_44;
F_20 ( & V_4 -> V_21 ) ;
V_4 -> V_19 = V_31 -> V_19 ;
V_4 -> V_65 = V_8 -> V_1 ;
if ( ! V_4 -> V_65 )
goto V_44;
for ( V_11 = 0 ; V_11 < F_2 ( V_16 ) ; V_11 ++ ) {
V_58 = V_11 + V_4 -> V_19 ;
F_21 ( V_58 , V_4 ) ;
F_22 ( V_58 , & V_66 ,
V_67 ) ;
F_23 ( V_58 , 1 ) ;
#ifdef F_24
F_25 ( V_58 , V_68 ) ;
#else
F_26 ( V_58 ) ;
#endif
}
V_32 = F_27 ( V_4 -> V_65 , NULL , F_1 , V_55 ,
L_3 , V_4 ) ;
if ( V_32 ) {
F_9 ( V_4 -> V_29 , L_4 , V_32 ) ;
V_4 -> V_65 = 0 ;
}
return 0 ;
V_44:
V_4 -> V_65 = 0 ;
return V_32 ;
}
static void F_28 ( struct V_3 * V_4 )
{
if ( V_4 -> V_65 )
F_29 ( V_4 -> V_65 , V_4 ) ;
}
static void T_2 F_30 ( struct V_3 * V_4 ,
struct V_30 * V_31 )
{
int V_32 ;
int V_11 , V_69 , V_12 ;
if ( ( V_31 == NULL ) || ( V_31 -> V_70 == NULL ) )
return;
if ( V_31 -> V_71 > F_2 ( V_72 ) )
V_31 -> V_71 = F_2 ( V_72 ) ;
for ( V_11 = 0 ; V_11 < V_31 -> V_71 ; V_11 ++ ) {
V_72 [ V_11 ] . V_73 = & V_31 -> V_70 [ V_11 ] ;
V_72 [ V_11 ] . V_74 = sizeof( struct V_75 ) ;
for ( V_69 = 0 ; V_69 < F_2 ( V_72 ) ; V_69 ++ ) {
V_12 = V_76 [ V_69 ] . V_77 ;
if ( V_31 -> V_70 [ V_11 ] . V_55 != V_12 )
continue;
V_72 [ V_11 ] . V_78 = 1 ;
V_72 [ V_11 ] . V_79 = & V_76 [ V_69 ] ;
V_32 = F_31 ( V_4 -> V_29 , 0 ,
& V_72 [ V_11 ] , 1 ,
& V_76 [ V_69 ] , 0 ) ;
if ( V_32 < 0 ) {
F_9 ( V_4 -> V_29 , L_5
L_6 ) ;
return;
}
}
}
}
static void T_2 F_32 ( struct V_3 * V_4 ,
struct V_30 * V_31 )
{
int V_32 ;
int V_11 , V_69 , V_12 ;
if ( ( V_31 == NULL ) || ( V_31 -> V_80 == NULL ) )
return;
if ( V_31 -> V_81 > F_2 ( V_82 ) )
V_31 -> V_81 = F_2 ( V_82 ) ;
for ( V_11 = 0 ; V_11 < V_31 -> V_81 ; V_11 ++ ) {
V_82 [ V_11 ] . V_73 = & V_31 -> V_80 [ V_11 ] ;
V_82 [ V_11 ] . V_74 = sizeof( struct V_83 ) ;
for ( V_69 = 0 ; V_69 < F_2 ( V_82 ) ; V_69 ++ ) {
V_12 = V_84 [ V_69 ] . V_77 ;
if ( V_31 -> V_80 [ V_11 ] . V_55 != V_12 )
continue;
V_82 [ V_11 ] . V_78 = 1 ;
V_82 [ V_11 ] . V_79 = & V_84 [ V_69 ] ,
V_32 = F_31 ( V_4 -> V_29 , 0 ,
& V_82 [ V_11 ] , 1 ,
& V_84 [ V_69 ] , 0 ) ;
if ( V_32 < 0 ) {
F_9 ( V_4 -> V_29 , L_5
L_7 ) ;
return;
}
}
}
}
static void T_2 F_33 ( struct V_3 * V_4 ,
struct V_30 * V_31 )
{
struct V_85 * V_86 ;
int V_32 ;
int V_11 , V_87 ;
if ( ( V_31 == NULL ) || ( V_31 -> V_88 == NULL ) )
return;
if ( V_31 -> V_89 > F_2 ( V_90 ) )
V_31 -> V_89 = F_2 ( V_90 ) ;
for ( V_11 = 0 , V_87 = - 1 ; V_11 < V_31 -> V_89 ; V_11 ++ ) {
V_86 = & V_31 -> V_88 [ V_11 ] ;
V_87 = * ( unsigned int * ) V_86 -> V_91 ;
if ( ( V_87 < 0 ) || ( V_87 > V_92 ) ) {
F_9 ( V_4 -> V_29 , L_8 ,
V_87 , V_86 -> V_93 . V_94 ) ;
goto V_44;
}
V_90 [ V_11 ] . V_73 = & V_31 -> V_88 [ V_11 ] ;
V_90 [ V_11 ] . V_74 = sizeof( struct V_85 ) ;
V_90 [ V_11 ] . V_78 = 1 ;
V_90 [ V_11 ] . V_79 = & V_95 [ V_87 ] ;
V_32 = F_31 ( V_4 -> V_29 , 0 , & V_90 [ V_11 ] , 1 ,
& V_95 [ V_87 ] , 0 ) ;
if ( V_32 < 0 ) {
F_9 ( V_4 -> V_29 , L_9 ) ;
goto V_44;
}
}
V_44:
return;
}
static void T_2 F_34 ( struct V_3 * V_4 ,
struct V_30 * V_31 )
{
int V_32 ;
if ( ( V_31 == NULL ) )
return;
V_96 [ 0 ] . V_73 = V_31 -> V_97 ;
V_96 [ 0 ] . V_74 = sizeof( struct V_98 ) ;
V_96 [ 0 ] . V_78 = F_2 ( V_99 ) ;
V_96 [ 0 ] . V_79 = & V_99 [ 0 ] ;
V_32 = F_31 ( V_4 -> V_29 , 0 , & V_96 [ 0 ] ,
F_2 ( V_96 ) , & V_99 [ 0 ] ,
V_4 -> V_19 ) ;
if ( V_32 < 0 )
F_9 ( V_4 -> V_29 , L_10 ) ;
}
static void T_2 F_35 ( struct V_3 * V_4 ,
struct V_30 * V_31 )
{
int V_32 ;
if ( V_31 == NULL )
return;
V_100 [ 0 ] . V_73 = V_31 -> V_33 ;
V_100 [ 0 ] . V_74 = sizeof( struct V_101 ) ;
V_100 [ 0 ] . V_78 = F_2 ( V_102 ) ;
V_100 [ 0 ] . V_79 = & V_102 [ 0 ] ;
V_32 = F_31 ( V_4 -> V_29 , 0 , & V_100 [ 0 ] ,
F_2 ( V_100 ) , & V_102 [ 0 ] ,
V_4 -> V_19 ) ;
if ( V_32 < 0 )
F_9 ( V_4 -> V_29 , L_11 ) ;
}
static void T_2 F_36 ( struct V_3 * V_4 ,
struct V_30 * V_31 )
{
int V_32 ;
if ( V_31 == NULL )
return;
V_103 [ 0 ] . V_73 = V_31 -> V_104 ;
V_103 [ 0 ] . V_74 = sizeof( struct V_105 ) ;
V_103 [ 0 ] . V_78 = F_2 ( V_106 ) ;
V_103 [ 0 ] . V_79 = & V_106 [ 0 ] ,
V_32 = F_31 ( V_4 -> V_29 , 0 , & V_103 [ 0 ] , 1 ,
& V_106 [ 0 ] , V_4 -> V_19 ) ;
if ( V_32 < 0 )
F_9 ( V_4 -> V_29 , L_12 ) ;
V_103 [ 1 ] . V_73 = V_31 -> V_104 ;
V_103 [ 1 ] . V_74 = sizeof( struct V_105 ) ;
V_103 [ 1 ] . V_78 = F_2 ( V_107 ) ;
V_103 [ 1 ] . V_79 = & V_107 [ 0 ] ,
V_32 = F_31 ( V_4 -> V_29 , 0 , & V_103 [ 1 ] , 1 ,
& V_107 [ 0 ] , V_4 -> V_19 ) ;
if ( V_32 < 0 )
F_9 ( V_4 -> V_29 , L_13 ) ;
}
static void T_2 F_37 ( struct V_3 * V_4 ,
struct V_30 * V_31 )
{
int V_32 ;
V_108 [ 0 ] . V_78 = F_2 ( V_109 ) ;
V_108 [ 0 ] . V_79 = & V_109 [ 0 ] ,
V_32 = F_31 ( V_4 -> V_29 , 0 , & V_108 [ 0 ] ,
F_2 ( V_108 ) , & V_109 [ 0 ] ,
V_4 -> V_19 ) ;
if ( V_32 < 0 )
F_9 ( V_4 -> V_29 , L_14 ) ;
}
static void T_2 F_38 ( struct V_3 * V_4 ,
struct V_30 * V_31 )
{
int V_32 ;
V_110 [ 0 ] . V_78 = F_2 ( V_111 ) ;
V_110 [ 0 ] . V_79 = & V_111 [ 0 ] ,
V_32 = F_31 ( V_4 -> V_29 , 0 , & V_110 [ 0 ] ,
F_2 ( V_110 ) , & V_111 [ 0 ] , 0 ) ;
if ( V_32 < 0 )
F_9 ( V_4 -> V_29 , L_15 ) ;
}
static void T_2 F_39 ( struct V_3 * V_4 ,
struct V_7 * V_8 ,
struct V_30 * V_31 )
{
int V_2 , V_32 ;
V_32 = F_3 ( V_8 , V_112 ) ;
if ( V_32 < 0 ) {
F_9 ( V_4 -> V_29 , L_16 , V_32 ) ;
goto V_44;
}
switch ( V_32 & V_113 ) {
case 0x40 :
case 0x50 :
F_40 ( V_4 -> V_29 , L_17 ,
V_32 ) ;
break;
default:
F_9 ( V_4 -> V_29 , L_18
L_19 , V_32 ) ;
goto V_44;
}
V_32 = F_3 ( V_8 , V_114 ) ;
if ( V_32 < 0 ) {
F_9 ( V_4 -> V_29 , L_20 , V_32 ) ;
goto V_44;
}
if ( V_32 & V_115 )
V_4 -> V_116 = 1 ;
V_32 = F_3 ( V_8 , V_63 ) ;
if ( V_32 < 0 ) {
F_9 ( V_4 -> V_29 , L_21 , V_32 ) ;
goto V_44;
}
if ( V_31 && ( V_31 -> V_117 == V_118 ) )
V_2 = V_119 ;
else
V_2 = 0 ;
V_32 = F_15 ( V_8 , V_63 , V_119 , V_2 ) ;
if ( V_32 < 0 ) {
F_9 ( V_4 -> V_29 , L_22 , V_32 ) ;
goto V_44;
}
V_32 = F_14 ( V_4 , V_31 ) ;
if ( V_32 < 0 )
goto V_44;
V_32 = F_16 ( V_4 , V_31 ) ;
if ( V_32 < 0 )
goto V_44;
F_33 ( V_4 , V_31 ) ;
F_34 ( V_4 , V_31 ) ;
F_37 ( V_4 , V_31 ) ;
F_35 ( V_4 , V_31 ) ;
F_36 ( V_4 , V_31 ) ;
F_38 ( V_4 , V_31 ) ;
V_44:
return;
}
int T_2 F_41 ( struct V_3 * V_4 ,
struct V_30 * V_31 )
{
V_4 -> V_65 = 0 ;
switch ( V_4 -> V_12 ) {
case V_120 :
F_30 ( V_4 , V_31 ) ;
F_32 ( V_4 , V_31 ) ;
break;
case V_13 :
F_39 ( V_4 , V_4 -> V_14 , V_31 ) ;
break;
}
if ( V_4 -> V_15 ) {
switch ( V_4 -> V_12 ) {
case V_13 :
F_30 ( V_4 , V_31 ) ;
F_32 ( V_4 , V_31 ) ;
break;
case V_120 :
F_39 ( V_4 , V_4 -> V_15 , V_31 ) ;
break;
}
}
return 0 ;
}
void T_3 F_42 ( struct V_3 * V_4 )
{
F_28 ( V_4 ) ;
F_43 ( V_4 -> V_29 ) ;
}
