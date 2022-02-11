static bool F_1 ( T_1 V_1 )
{
if ( ( V_1 & ~ V_2 ) == ( V_3 | V_4 | V_5 ) )
return false ;
if ( ( V_1 & ~ V_6 ) == ( V_3 | V_4 | V_7 ) )
return false ;
return true ;
}
static void F_2 ( struct V_8 * V_9 )
{
T_1 V_1 ;
char * V_10 ;
int V_11 , V_12 ;
V_12 = V_9 -> V_13 / 4 ;
V_1 = V_9 -> V_14 [ V_12 - 1 ] ;
switch ( V_1 & V_15 ) {
case V_16 :
V_10 = V_9 -> V_17 ;
break;
case V_18 :
V_10 = V_9 -> V_19 ;
break;
case V_20 :
V_10 = V_9 -> V_21 ;
break;
case V_22 :
V_9 -> V_23 [ V_24 ] = 0 ;
V_10 = V_9 -> V_23 ;
break;
default:
if ( V_1 != ( V_3 | V_4 ) ) {
F_3 (KERN_WARNING PREFIX L_1 , p) ;
}
goto V_25;
}
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
V_10 [ V_11 ] = V_9 -> V_14 [ V_11 ] & V_15 ;
for (; V_11 < V_24 ; V_11 ++ )
V_10 [ V_11 ] = 0 ;
V_25:
F_4 ( & V_9 -> V_26 ) ;
}
static void F_5 ( struct V_8 * V_27 )
{
struct V_28 * V_9 = V_27 -> V_9 ;
int V_12 = V_27 -> V_13 / 4 ;
int V_11 ;
switch ( V_27 -> V_14 [ 0 ] & V_29 ) {
case V_30 :
return;
case V_31 :
for ( V_11 = 1 ; V_11 < V_12 - 1 ; V_11 ++ )
F_6 ( V_9 , V_27 -> V_14 [ V_11 ] & 0x7f , 1 ) ;
break;
case V_32 :
case V_33 :
case V_34 :
for ( V_11 = 1 ; V_11 < V_12 - 1 ; V_11 ++ )
F_6 ( V_9 , V_27 -> V_14 [ V_11 ] , 1 ) ;
break;
case V_35 :
for ( V_11 = 1 ; V_11 < V_12 - 1 ; V_11 ++ ) {
unsigned int V_36 = V_27 -> V_14 [ V_11 ] ;
int V_37 = V_36 & V_38 ;
V_36 &= ( ~ V_38 & 0xff ) ;
V_36 = V_39 [ V_36 >> V_40 ] ;
F_6 ( V_9 , V_36 , ! V_37 ) ;
}
break;
case V_41 :
for ( V_11 = 1 ; V_11 < V_12 - 1 ; V_11 ++ ) {
unsigned int V_36 = V_27 -> V_14 [ V_11 ] ;
int V_37 = V_36 & V_42 ;
V_36 &= ( ~ V_38 & 0xff ) ;
V_36 = V_36 >> V_43 ;
F_6 ( V_9 , V_36 , ! V_37 ) ;
}
break;
case V_44 :
for ( V_11 = 1 ; V_11 < V_12 - 1 ; V_11 ++ ) {
unsigned int V_36 = V_27 -> V_14 [ V_11 ] ;
int V_37 = V_36 & V_45 ;
V_36 &= ( ~ V_38 & 0xff ) ;
V_36 = V_46 [ V_36 >> V_47 ] ;
F_6 ( V_9 , V_36 , ! V_37 ) ;
}
break;
}
F_7 ( V_9 ) ;
}
static void F_8 ( struct V_8 * V_48 )
{
struct V_28 * V_9 = V_48 -> V_9 ;
int V_12 = V_48 -> V_13 / 4 ;
T_1 V_1 = V_48 -> V_14 [ V_12 - 1 ] ;
int V_11 , V_49 , V_50 ;
bool V_51 , V_52 ;
if ( ( V_1 & V_2 ) != V_12 - 1 ) {
F_3 (KERN_WARNING PREFIX
L_2 , p, idx) ;
return;
}
V_11 = ( V_1 & V_53 ) ? 3 : 0 ;
V_50 = ( V_1 & V_54 ) + V_11 ;
V_52 = V_48 -> V_17 [ 1 ] & V_55 ;
V_51 = V_48 -> V_17 [ 1 ] & V_56 ;
for ( V_49 = 1 ; V_11 < V_50 ; V_11 ++ ) {
unsigned int V_57 , V_58 , V_59 ;
V_57 = V_48 -> V_14 [ V_49 ++ ] & V_15 ;
V_58 = V_52 ? ( V_48 -> V_14 [ V_49 ++ ] & V_15 ) : 0 ;
if ( V_51 ) {
V_59 = V_57 + ( V_58 << 8 ) ;
#ifdef F_9
if ( V_59 < F_10 ( V_9 , V_60 + V_11 ) )
F_11 ( V_9 , V_60 + V_11 , V_59 ) ;
if ( V_59 > F_12 ( V_9 , V_60 + V_11 ) )
F_13 ( V_9 , V_60 + V_11 , V_59 ) ;
#endif
if ( V_11 % 3 )
V_59 = F_12 ( V_9 , V_60 + V_11 ) - V_59 ;
F_14 ( V_9 , V_60 + V_11 , V_59 ) ;
} else {
V_59 = ( int ) ( ( ( V_61 ) V_57 ) | ( ( V_61 ) V_58 << 8 ) ) ;
if ( V_11 % 3 )
V_59 *= - 1 ;
F_15 ( V_9 , V_62 + V_11 , V_59 ) ;
}
}
while ( V_49 < V_12 - 1 ) {
unsigned int V_63 = V_48 -> V_14 [ V_49 ++ ] ;
int V_37 = V_63 & 1 ;
V_63 &= 0xfe ;
if ( V_63 == 0x8e )
continue;
if ( V_63 > 0x8c || V_63 < 0x80 )
continue;
V_63 = ( V_63 - 0x80 ) >> 1 ;
V_63 = V_48 -> V_64 [ V_63 ] ;
F_6 ( V_9 , V_63 , ! V_37 ) ;
}
F_7 ( V_9 ) ;
}
static void F_16 ( struct V_8 * V_9 )
{
F_3 (KERN_WARNING PREFIX L_3 ) ;
V_9 -> V_13 = 0 ;
F_4 ( & V_9 -> V_26 ) ;
}
static T_2 F_17 ( struct V_65 * V_65 ,
unsigned char V_14 , unsigned int V_66 )
{
struct V_8 * V_9 ;
T_1 V_67 ;
int V_12 ;
V_9 = F_18 ( V_65 ) ;
F_19 ( V_9 == NULL ) ;
if ( V_9 -> V_13 >= V_24 * sizeof( T_1 ) ) {
F_16 ( V_9 ) ;
goto V_25;
}
V_12 = V_9 -> V_13 / 4 ;
if ( ! ( V_9 -> V_13 % 4 ) )
V_9 -> V_14 [ V_12 ] = 0 ;
V_67 = V_9 -> V_14 [ V_12 ] ;
V_67 |= ( ( T_1 ) V_14 ) << ( ( 3 - ( V_9 -> V_13 % 4 ) ) * 8 ) ;
V_9 -> V_14 [ V_12 ] = V_67 ;
if ( ( ++ V_9 -> V_13 % 4 ) == 0 ) {
if ( ( V_67 & 0xffff0000 ) != V_3 ) {
F_16 ( V_9 ) ;
} else if ( V_67 & V_4 ) {
if ( F_1 ( V_67 ) )
F_2 ( V_9 ) ;
else if ( V_9 -> V_68 )
F_8 ( V_9 ) ;
else
F_5 ( V_9 ) ;
V_9 -> V_13 = 0 ;
}
}
V_25:
return V_69 ;
}
static void F_20 ( struct V_65 * V_65 )
{
struct V_8 * V_9 = F_18 ( V_65 ) ;
F_19 ( V_9 == NULL ) ;
F_21 ( V_65 ) ;
F_22 ( V_9 -> V_9 ) ;
F_23 ( V_65 , NULL ) ;
F_24 ( V_9 ) ;
}
static void F_25 ( struct V_8 * V_27 )
{
struct V_28 * V_28 = V_27 -> V_9 ;
T_3 V_70 = V_27 -> V_17 [ 0 ] ;
int V_11 ;
V_28 -> V_71 [ 0 ] = F_26 ( V_72 ) | F_26 ( V_73 ) ;
V_28 -> V_74 [ 0 ] = F_26 ( V_75 ) | F_26 ( V_76 ) |
F_26 ( V_77 ) ;
for ( V_11 = 0 ; V_11 < 128 ; V_11 ++ ) {
F_27 ( V_39 [ V_11 ] , V_28 -> V_78 ) ;
F_27 ( V_46 [ V_11 ] , V_28 -> V_78 ) ;
}
F_28 ( V_79 , V_28 -> V_78 ) ;
V_28 -> V_80 = V_81 ;
V_28 -> V_82 = sizeof( V_39 [ 0 ] ) ;
V_28 -> V_83 = V_39 ;
V_28 -> V_84 = strlen ( V_27 -> V_23 ) ? V_27 -> V_23 : L_4 ;
V_28 -> V_85 = L_5 ;
F_3 (KERN_INFO PREFIX L_6 ,
did, hil_language[did & HIL_IDD_DID_TYPE_KB_LANG_MASK]) ;
}
static void F_29 ( struct V_8 * V_48 )
{
struct V_28 * V_28 = V_48 -> V_9 ;
T_3 V_70 = V_48 -> V_17 [ 0 ] ;
T_3 * V_17 = V_48 -> V_17 + 1 ;
unsigned int V_86 = F_30 ( * V_17 ) ;
unsigned int V_11 , V_87 ;
const char * V_88 ;
V_48 -> V_89 = F_31 ( * V_17 ) ;
switch ( V_70 & V_90 ) {
case V_91 :
V_28 -> V_71 [ 0 ] = F_26 ( V_92 ) ;
for ( V_11 = 0 ; V_11 < V_48 -> V_89 ; V_11 ++ )
F_27 ( V_62 + V_11 , V_28 -> V_93 ) ;
for ( V_11 = 3 ; V_86 > 1 && V_11 < V_48 -> V_89 + 3 ; V_11 ++ )
F_27 ( V_62 + V_11 , V_28 -> V_93 ) ;
V_88 = L_7 ;
break;
case V_94 :
V_28 -> V_71 [ 0 ] = F_26 ( V_95 ) ;
for ( V_11 = 0 ; V_11 < V_48 -> V_89 ; V_11 ++ )
F_32 ( V_28 , V_60 + V_11 ,
0 , F_33 ( V_17 , V_11 ) , 0 , 0 ) ;
for ( V_11 = 3 ; V_86 > 1 && V_11 < V_48 -> V_89 + 3 ; V_11 ++ )
F_32 ( V_28 , V_60 + V_11 ,
0 , F_33 ( V_17 , V_11 - 3 ) , 0 , 0 ) ;
#ifdef F_9
for ( V_11 = 0 ; V_11 < V_96 ; V_11 ++ ) {
int V_97 = F_12 ( V_28 , V_60 + V_11 ) / 10 ;
F_11 ( V_28 , V_60 + V_11 ,
F_10 ( V_28 , V_60 + V_11 ) + V_97 ) ;
F_13 ( V_28 , V_60 + V_11 ,
F_12 ( V_28 , V_60 + V_11 ) - V_97 ) ;
}
#endif
V_88 = L_8 ;
break;
default:
F_34 () ;
}
V_48 -> V_98 = F_35 ( V_17 ) ;
if ( V_48 -> V_98 )
V_28 -> V_71 [ 0 ] |= F_26 ( V_72 ) ;
V_87 = V_99 ;
if ( ( V_70 & V_100 ) == V_101 )
#ifdef F_36
V_87 = V_102 ;
#else
V_87 = V_103 ;
#endif
if ( ( V_70 & V_104 ) == V_105 )
V_87 = V_102 ;
if ( ( V_70 & V_106 ) == V_107 )
V_87 = V_108 ;
for ( V_11 = 0 ; V_11 < V_48 -> V_98 ; V_11 ++ ) {
F_27 ( V_87 | V_11 , V_28 -> V_78 ) ;
V_48 -> V_64 [ V_11 ] = V_87 | V_11 ;
}
if ( V_87 == V_108 ) {
V_48 -> V_64 [ 1 ] = V_109 ;
V_48 -> V_64 [ 2 ] = V_110 ;
}
V_28 -> V_84 = strlen ( V_48 -> V_23 ) ? V_48 -> V_23 : L_9 ;
F_3 (KERN_INFO PREFIX
L_10 ,
did, txt) ;
F_3 (KERN_INFO PREFIX
L_11 ,
ptr->nbtn, naxsets, ptr->naxes) ;
}
static int F_37 ( struct V_65 * V_65 , struct V_111 * V_112 )
{
struct V_8 * V_9 ;
struct V_28 * V_28 ;
T_3 V_70 , * V_17 ;
int error ;
V_9 = F_38 ( sizeof( * V_9 ) , V_113 ) ;
V_28 = F_39 () ;
if ( ! V_9 || ! V_28 ) {
error = - V_114 ;
goto V_115;
}
V_9 -> V_65 = V_65 ;
V_9 -> V_9 = V_28 ;
error = F_40 ( V_65 , V_112 ) ;
if ( error )
goto V_115;
F_23 ( V_65 , V_9 ) ;
F_41 ( & V_9 -> V_26 ) ;
F_42 ( V_65 , 0 ) ;
F_42 ( V_65 , 0 ) ;
F_42 ( V_65 , V_4 >> 8 ) ;
F_42 ( V_65 , V_16 ) ;
error = F_43 ( & V_9 -> V_26 ) ;
if ( error )
goto V_116;
F_41 ( & V_9 -> V_26 ) ;
F_42 ( V_65 , 0 ) ;
F_42 ( V_65 , 0 ) ;
F_42 ( V_65 , V_4 >> 8 ) ;
F_42 ( V_65 , V_18 ) ;
error = F_43 ( & V_9 -> V_26 ) ;
if ( error )
goto V_116;
F_41 ( & V_9 -> V_26 ) ;
F_42 ( V_65 , 0 ) ;
F_42 ( V_65 , 0 ) ;
F_42 ( V_65 , V_4 >> 8 ) ;
F_42 ( V_65 , V_22 ) ;
error = F_43 ( & V_9 -> V_26 ) ;
if ( error )
goto V_116;
F_41 ( & V_9 -> V_26 ) ;
F_42 ( V_65 , 0 ) ;
F_42 ( V_65 , 0 ) ;
F_42 ( V_65 , V_4 >> 8 ) ;
F_42 ( V_65 , V_20 ) ;
error = F_43 ( & V_9 -> V_26 ) ;
if ( error )
goto V_116;
V_70 = V_9 -> V_17 [ 0 ] ;
V_17 = V_9 -> V_17 + 1 ;
switch ( V_70 & V_90 ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
if ( F_35 ( V_17 ) ||
F_31 ( * V_17 ) ) {
F_3 (KERN_INFO PREFIX
L_12 ) ;
goto V_116;
}
V_9 -> V_68 = false ;
F_25 ( V_9 ) ;
break;
case V_91 :
case V_94 :
V_9 -> V_68 = true ;
F_29 ( V_9 ) ;
break;
default:
goto V_116;
}
V_28 -> V_121 . V_122 = V_123 ;
V_28 -> V_121 . V_124 = V_125 ;
V_28 -> V_121 . V_126 = 0x0001 ;
V_28 -> V_121 . V_127 = 0x0100 ;
V_28 -> V_9 . V_128 = & V_65 -> V_9 ;
if ( ! V_9 -> V_68 ) {
F_42 ( V_65 , 0 ) ;
F_42 ( V_65 , 0 ) ;
F_42 ( V_65 , V_4 >> 8 ) ;
F_42 ( V_65 , V_129 ) ;
}
error = F_44 ( V_28 ) ;
if ( error )
goto V_116;
return 0 ;
V_116:
F_21 ( V_65 ) ;
F_23 ( V_65 , NULL ) ;
V_115:
F_45 ( V_28 ) ;
F_24 ( V_9 ) ;
return error ;
}
