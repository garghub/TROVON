static void F_1 ( struct V_1 * V_2 , unsigned char * V_3 ,
unsigned int V_4 )
{
if ( V_4 == 1 ) {
if ( V_3 [ 0 ] != ( unsigned char ) 0xff && V_3 [ 0 ] != 0x00 )
F_2 ( V_2 , L_1 , V_3 [ 0 ] ) ;
} else if ( V_4 == 4 )
F_2 ( V_2 , L_2 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] ) ;
else
F_2 ( V_2 , L_3 ,
V_4 , V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] , V_3 [ 4 ] , V_3 [ 5 ] ) ;
}
static int F_3 ( struct V_5 * V_5 )
{
int V_6 = 0 ;
F_4 ( & V_5 -> V_7 ) ;
if ( V_5 -> V_8 ++ != 0 )
goto V_9;
V_5 -> V_10 -> V_2 = V_5 -> V_11 ;
if ( F_5 ( V_5 -> V_10 , V_12 ) ) {
F_6 ( & V_5 -> V_13 -> V_2 ,
L_4 , V_14 ) ;
V_6 = - V_15 ;
}
V_9: F_7 ( & V_5 -> V_7 ) ;
return V_6 ;
}
static void F_8 ( struct V_5 * V_5 )
{
F_4 ( & V_5 -> V_7 ) ;
if ( -- V_5 -> V_8 == 0 )
F_9 ( V_5 -> V_10 ) ;
F_7 ( & V_5 -> V_7 ) ;
}
static int F_10 ( struct V_16 * V_17 )
{
struct V_5 * V_5 = F_11 ( V_17 ) ;
return F_3 ( V_5 ) ;
}
static void F_12 ( struct V_16 * V_17 )
{
struct V_5 * V_5 = F_11 ( V_17 ) ;
F_8 ( V_5 ) ;
}
static int F_13 ( struct V_18 * V_19 )
{
struct V_5 * V_5 = V_19 -> V_20 ;
return F_3 ( V_5 ) ;
}
static void F_14 ( struct V_18 * V_19 )
{
struct V_5 * V_5 = V_19 -> V_20 ;
F_8 ( V_5 ) ;
}
static void F_15 ( struct V_21 * V_21 )
{
struct V_5 * V_5 = V_21 -> V_22 ;
if ( V_21 -> V_23 ) {
F_16 ( & V_5 -> V_13 -> V_2 , L_5 ,
V_14 , V_21 -> V_23 ) ;
return;
}
V_5 -> V_24 |= V_25 ;
F_17 () ;
F_18 ( & V_5 -> V_26 ) ;
}
static int F_19 ( struct V_5 * V_5 , T_1 V_27 , unsigned char * V_3 )
{
int V_28 = 0 ;
memcpy ( V_5 -> V_29 -> V_30 + 1 , V_3 , F_20 ( V_27 ) ) ;
( ( char * ) V_5 -> V_29 -> V_30 ) [ 0 ] = F_21 ( V_27 ) ;
V_5 -> V_29 -> V_31 = F_20 ( V_27 ) + 1 ;
V_5 -> V_29 -> V_2 = V_5 -> V_11 ;
V_5 -> V_24 = V_32 ;
V_28 = F_5 ( V_5 -> V_29 , V_33 ) ;
if ( V_28 ) {
F_16 ( & V_5 -> V_13 -> V_2 ,
L_6 , V_28 ) ;
return V_28 ;
}
F_22 ( V_5 -> V_26 ,
( ( V_5 -> V_29 -> V_23 != - V_34 ) ||
( V_5 -> V_24 & V_25 ) ) ,
V_35 ) ;
F_9 ( V_5 -> V_29 ) ;
return V_28 ;
}
static int F_23 ( struct V_5 * V_5 )
{
static const char V_36 [] = { 1 , 2 , 4 , 6 , 9 , 13 , 20 } ;
unsigned long V_37 = V_38 ;
int V_39 ;
if ( F_24 ( V_37 , V_5 -> V_40 + F_25 ( 250 ) ) ) {
V_39 = 1 ;
V_5 -> V_41 = V_37 ;
}
else if ( F_26 ( V_37 , V_5 -> V_41 + F_25 ( 125 ) ) )
V_39 = V_36 [ 0 ] ;
else if ( F_26 ( V_37 , V_5 -> V_41 + F_25 ( 250 ) ) )
V_39 = V_36 [ 1 ] ;
else if ( F_26 ( V_37 , V_5 -> V_41 + F_25 ( 500 ) ) )
V_39 = V_36 [ 2 ] ;
else if ( F_26 ( V_37 , V_5 -> V_41 + F_25 ( 1000 ) ) )
V_39 = V_36 [ 3 ] ;
else if ( F_26 ( V_37 , V_5 -> V_41 + F_25 ( 1500 ) ) )
V_39 = V_36 [ 4 ] ;
else if ( F_26 ( V_37 , V_5 -> V_41 + F_25 ( 2000 ) ) )
V_39 = V_36 [ 5 ] ;
else
V_39 = V_36 [ 6 ] ;
return V_39 ;
}
static void F_27 ( struct V_21 * V_21 )
{
struct V_5 * V_5 = V_21 -> V_22 ;
unsigned char * V_3 = V_5 -> V_42 ;
struct V_16 * V_2 = V_5 -> V_43 ;
int V_44 = - 1 ;
int V_39 ;
int V_45 ;
unsigned char V_46 ;
int V_47 ;
if ( ( V_21 -> V_48 != 4 ) || ( V_3 [ 0 ] != 0x14 ) ||
( ( V_3 [ 3 ] & 0x0f ) != 0x00 ) ) {
F_1 ( & V_21 -> V_2 -> V_2 , V_3 , V_21 -> V_48 ) ;
return;
}
if ( V_3 [ 1 ] != ( ( V_3 [ 2 ] + V_3 [ 3 ] + 0xd5 ) & 0xff ) ) {
F_28 ( & V_5 -> V_13 -> V_2 ,
L_7 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] ) ;
return;
}
V_45 = ( V_3 [ 3 ] >> 4 ) & 0x0f ;
if ( V_49 & ( 1 << ( V_45 + 1 ) ) ) {
F_28 ( & V_5 -> V_13 -> V_2 ,
L_8 ,
V_45 , V_3 [ 1 ] , V_3 [ 2 ] , V_49 ) ;
return;
}
V_46 = V_3 [ 2 ] & 0x7f ;
for ( V_47 = 0 ; V_50 [ V_47 ] . V_51 != V_52 ; V_47 ++ ) {
if ( V_46 == V_50 [ V_47 ] . V_3 ) {
V_44 = V_47 ;
break;
}
}
if ( V_44 >= 0 ) {
F_28 ( & V_5 -> V_13 -> V_2 ,
L_9 ,
V_45 , V_3 [ 2 ] , V_44 , V_50 [ V_44 ] . V_53 ) ;
if ( ! V_2 )
return;
} else
F_28 ( & V_5 -> V_13 -> V_2 ,
L_10 ,
V_45 , V_3 [ 2 ] , V_46 ) ;
if ( V_44 >= 0 && V_50 [ V_44 ] . V_51 == V_54 ) {
F_29 ( V_2 , V_50 [ V_44 ] . type ,
V_50 [ V_44 ] . V_53 ,
V_50 [ V_44 ] . V_55 ) ;
F_30 ( V_2 ) ;
V_5 -> V_40 = V_38 ;
return;
}
if ( V_44 < 0 || V_50 [ V_44 ] . V_51 == V_56 ) {
unsigned long V_37 = V_38 ;
if ( V_5 -> V_57 == V_3 [ 2 ] &&
F_26 ( V_37 , V_5 -> V_40 +
F_25 ( V_58 ) ) ) {
V_5 -> V_59 ++ ;
} else {
V_5 -> V_59 = 0 ;
V_5 -> V_60 = V_37 ;
}
V_5 -> V_57 = V_3 [ 2 ] ;
V_5 -> V_40 = V_37 ;
if ( V_5 -> V_59 > 0 &&
( V_5 -> V_59 < 5 ||
F_26 ( V_37 , V_5 -> V_60 +
F_25 ( V_61 ) ) ) )
return;
if ( V_44 < 0 ) {
F_31 ( V_5 -> V_19 , V_46 ,
V_3 [ 2 ] ) ;
F_32 ( V_5 -> V_19 ) ;
return;
}
F_29 ( V_2 , V_50 [ V_44 ] . type ,
V_50 [ V_44 ] . V_53 , 1 ) ;
F_30 ( V_2 ) ;
F_29 ( V_2 , V_50 [ V_44 ] . type ,
V_50 [ V_44 ] . V_53 , 0 ) ;
F_30 ( V_2 ) ;
} else {
V_39 = F_23 ( V_5 ) ;
switch ( V_50 [ V_44 ] . V_51 ) {
case V_62 :
F_29 ( V_2 , V_50 [ V_44 ] . type ,
V_50 [ V_44 ] . V_53 ,
V_50 [ V_44 ] . V_55 * V_39 ) ;
break;
case V_63 :
F_33 ( V_2 , V_64 , - V_39 ) ;
F_33 ( V_2 , V_65 , - V_39 ) ;
break;
case V_66 :
F_33 ( V_2 , V_64 , V_39 ) ;
F_33 ( V_2 , V_65 , - V_39 ) ;
break;
case V_67 :
F_33 ( V_2 , V_64 , - V_39 ) ;
F_33 ( V_2 , V_65 , V_39 ) ;
break;
case V_68 :
F_33 ( V_2 , V_64 , V_39 ) ;
F_33 ( V_2 , V_65 , V_39 ) ;
break;
default:
F_16 ( & V_5 -> V_13 -> V_2 , L_11 ,
V_50 [ V_44 ] . V_51 ) ;
}
F_30 ( V_2 ) ;
V_5 -> V_40 = V_38 ;
V_5 -> V_57 = V_3 [ 2 ] ;
}
}
static void F_34 ( struct V_21 * V_21 )
{
struct V_5 * V_5 = V_21 -> V_22 ;
int V_28 ;
switch ( V_21 -> V_23 ) {
case 0 :
F_27 ( V_21 ) ;
break;
case - V_69 :
case - V_70 :
case - V_71 :
F_16 ( & V_5 -> V_13 -> V_2 , L_12 ,
V_14 ) ;
return;
default:
F_16 ( & V_5 -> V_13 -> V_2 , L_13 ,
V_14 , V_21 -> V_23 ) ;
}
V_28 = F_5 ( V_21 , V_33 ) ;
if ( V_28 )
F_6 ( & V_5 -> V_13 -> V_2 , L_14 ,
V_14 , V_28 ) ;
}
static int F_35 ( struct V_72 * V_11 ,
struct V_5 * V_5 )
{
V_5 -> V_42 = F_36 ( V_11 , V_73 , V_33 ,
& V_5 -> V_74 ) ;
if ( ! V_5 -> V_42 )
return - 1 ;
V_5 -> V_75 = F_36 ( V_11 , V_73 , V_33 ,
& V_5 -> V_76 ) ;
if ( ! V_5 -> V_75 )
return - 1 ;
V_5 -> V_10 = F_37 ( 0 , V_12 ) ;
if ( ! V_5 -> V_10 )
return - 1 ;
V_5 -> V_29 = F_37 ( 0 , V_12 ) ;
if ( ! V_5 -> V_29 )
return - 1 ;
return 0 ;
}
static void F_38 ( struct V_5 * V_5 )
{
F_39 ( V_5 -> V_10 ) ;
F_39 ( V_5 -> V_29 ) ;
F_40 ( V_5 -> V_11 , V_73 ,
V_5 -> V_42 , V_5 -> V_74 ) ;
F_40 ( V_5 -> V_11 , V_73 ,
V_5 -> V_75 , V_5 -> V_76 ) ;
}
static void F_41 ( struct V_5 * V_5 )
{
struct V_16 * V_43 = V_5 -> V_43 ;
int V_47 ;
V_43 -> V_77 [ 0 ] = F_42 ( V_78 ) | F_42 ( V_79 ) ;
V_43 -> V_80 [ F_43 ( V_81 ) ] = F_42 ( V_82 ) |
F_42 ( V_83 ) | F_42 ( V_84 ) | F_42 ( V_85 ) ;
V_43 -> V_86 [ 0 ] = F_42 ( V_64 ) | F_42 ( V_65 ) ;
for ( V_47 = 0 ; V_50 [ V_47 ] . V_51 != V_52 ; V_47 ++ )
if ( V_50 [ V_47 ] . type == V_78 )
F_44 ( V_50 [ V_47 ] . V_53 , V_43 -> V_80 ) ;
F_45 ( V_43 , V_5 ) ;
V_43 -> V_87 = F_10 ;
V_43 -> V_88 = F_12 ;
V_43 -> V_89 = V_5 -> V_90 ;
V_43 -> V_91 = V_5 -> V_92 ;
F_46 ( V_5 -> V_11 , & V_43 -> V_93 ) ;
V_43 -> V_2 . V_94 = & V_5 -> V_13 -> V_2 ;
}
static void F_47 ( struct V_5 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_19 ;
V_19 -> V_20 = V_5 ;
V_19 -> V_95 = V_96 ;
V_19 -> V_97 = V_98 ;
V_19 -> V_99 = L_15 ;
V_19 -> V_87 = F_13 ;
V_19 -> V_88 = F_14 ;
V_19 -> V_100 = V_5 -> V_101 ;
V_19 -> V_102 = V_5 -> V_103 ;
F_46 ( V_5 -> V_11 , & V_19 -> V_104 ) ;
V_19 -> V_2 . V_94 = & V_5 -> V_13 -> V_2 ;
}
static int F_48 ( struct V_5 * V_5 )
{
struct V_72 * V_11 = V_5 -> V_11 ;
int V_105 , V_106 ;
F_49 ( & V_5 -> V_26 ) ;
V_105 = F_50 ( V_11 , V_5 -> V_107 -> V_108 ) ;
V_106 = F_51 ( V_11 , V_105 , F_52 ( V_105 ) ) ;
V_106 = ( V_106 > V_73 ) ? V_73 : V_106 ;
F_53 ( V_5 -> V_10 , V_11 , V_105 , V_5 -> V_42 ,
V_106 , F_34 , V_5 ,
V_5 -> V_107 -> V_109 ) ;
V_5 -> V_10 -> V_110 = V_5 -> V_74 ;
V_5 -> V_10 -> V_111 |= V_112 ;
V_105 = F_54 ( V_11 , V_5 -> V_113 -> V_108 ) ;
V_106 = F_51 ( V_11 , V_105 , F_52 ( V_105 ) ) ;
V_106 = ( V_106 > V_73 ) ? V_73 : V_106 ;
F_53 ( V_5 -> V_29 , V_11 , V_105 , V_5 -> V_75 ,
V_106 , F_15 , V_5 ,
V_5 -> V_113 -> V_109 ) ;
V_5 -> V_29 -> V_110 = V_5 -> V_76 ;
V_5 -> V_29 -> V_111 |= V_112 ;
if ( ( F_19 ( V_5 , 0x8004 , V_114 ) ) ||
( F_19 ( V_5 , 0x8007 , V_115 ) ) ) {
F_6 ( & V_5 -> V_13 -> V_2 ,
L_16 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_55 ( struct V_116 * V_13 , const struct V_117 * V_93 )
{
struct V_72 * V_11 = F_56 ( V_13 ) ;
struct V_118 * V_119 = V_13 -> V_120 ;
struct V_121 * V_107 , * V_113 ;
struct V_5 * V_5 ;
struct V_16 * V_16 ;
struct V_18 * V_18 ;
int V_6 = - V_122 ;
if ( V_119 -> V_123 . V_124 != 2 ) {
V_6 ( L_17 , V_14 ) ;
return - V_125 ;
}
V_107 = & V_119 -> V_126 [ 0 ] . V_123 ;
V_113 = & V_119 -> V_126 [ 1 ] . V_123 ;
if ( ! F_57 ( V_107 ) ) {
V_6 ( L_18 , V_14 ) ;
return - V_125 ;
}
if ( F_58 ( V_107 -> V_127 ) == 0 ) {
V_6 ( L_19 , V_14 ) ;
return - V_125 ;
}
V_5 = F_59 ( sizeof ( struct V_5 ) , V_12 ) ;
V_18 = F_60 () ;
if ( ! V_5 || ! V_18 )
goto V_128;
if ( F_35 ( V_11 , V_5 ) )
goto V_129;
V_5 -> V_107 = V_107 ;
V_5 -> V_113 = V_113 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_19 = V_18 ;
V_5 -> V_13 = V_13 ;
F_61 ( V_11 , V_5 -> V_103 , sizeof( V_5 -> V_103 ) ) ;
F_62 ( V_5 -> V_92 , V_5 -> V_103 ,
sizeof( V_5 -> V_92 ) ) ;
F_63 ( V_5 -> V_103 , L_20 , sizeof( V_5 -> V_103 ) ) ;
F_63 ( V_5 -> V_92 , L_21 , sizeof( V_5 -> V_92 ) ) ;
if ( V_11 -> V_130 )
F_62 ( V_5 -> V_101 , V_11 -> V_130 ,
sizeof( V_5 -> V_101 ) ) ;
if ( V_11 -> V_131 )
snprintf ( V_5 -> V_101 , sizeof( V_5 -> V_101 ) ,
L_22 , V_5 -> V_101 , V_11 -> V_131 ) ;
if ( ! strlen ( V_5 -> V_101 ) )
snprintf ( V_5 -> V_101 , sizeof( V_5 -> V_101 ) ,
V_132 L_23 ,
F_58 ( V_5 -> V_11 -> V_133 . V_134 ) ,
F_58 ( V_5 -> V_11 -> V_133 . V_135 ) ) ;
snprintf ( V_5 -> V_90 , sizeof( V_5 -> V_90 ) ,
L_24 , V_5 -> V_101 ) ;
if ( V_93 -> V_136 )
V_18 -> V_137 = ( const char * ) V_93 -> V_136 ;
else
V_18 -> V_137 = V_138 ;
F_47 ( V_5 ) ;
F_64 ( & V_5 -> V_7 ) ;
V_6 = F_48 ( V_5 ) ;
if ( V_6 )
goto V_139;
V_6 = F_65 ( V_5 -> V_19 ) ;
if ( V_6 )
goto V_139;
V_5 -> V_19 -> V_16 -> V_140 [ V_141 ] = V_61 ;
if ( V_142 ) {
V_16 = F_66 () ;
if ( ! V_16 )
goto V_143;
V_5 -> V_43 = V_16 ;
F_41 ( V_5 ) ;
V_6 = F_67 ( V_16 ) ;
if ( V_6 )
goto V_144;
}
F_68 ( V_13 , V_5 ) ;
return 0 ;
V_144: F_69 ( V_16 ) ;
V_143: F_70 ( V_18 ) ;
V_18 = NULL ;
V_139: F_9 ( V_5 -> V_10 ) ;
F_9 ( V_5 -> V_29 ) ;
V_129: F_38 ( V_5 ) ;
V_128: F_71 ( V_18 ) ;
F_72 ( V_5 ) ;
return V_6 ;
}
static void F_73 ( struct V_116 * V_13 )
{
struct V_5 * V_5 ;
V_5 = F_74 ( V_13 ) ;
F_68 ( V_13 , NULL ) ;
if ( ! V_5 ) {
F_2 ( & V_13 -> V_2 , L_25 , V_14 ) ;
return;
}
F_9 ( V_5 -> V_10 ) ;
F_9 ( V_5 -> V_29 ) ;
if ( V_5 -> V_43 )
F_75 ( V_5 -> V_43 ) ;
F_70 ( V_5 -> V_19 ) ;
F_38 ( V_5 ) ;
F_72 ( V_5 ) ;
}
