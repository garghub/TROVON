static int F_1 ( int V_1 )
{
return V_1 / V_2 ;
}
static int F_2 ( int V_1 )
{
return V_1 % V_2 ;
}
static void F_3 ( T_1 * V_3 , T_2 V_4 , T_2 type , T_2 V_5 )
{
* V_3 &= ~ ( ( 0xff << 0 ) | ( 0xff << 8 ) | ( 0xff << 24 ) ) ;
* V_3 |= ( V_4 << 0 ) | ( type << 8 ) | ( V_5 << 24 ) ;
}
static T_3 F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_5 ( V_9 ,
struct V_11 , V_9 ) ;
return snprintf ( V_10 , V_13 , L_1 , ( char * ) V_12 -> V_14 ) ;
}
static T_3 F_6 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_15 * V_16 = F_5 ( V_9 ,
struct V_15 , V_9 ) ;
T_3 V_17 ;
V_17 = snprintf ( V_10 , V_13 , L_2 , V_16 -> type ) ;
if ( V_16 -> V_16 )
V_17 += snprintf ( V_10 + V_17 , V_13 - V_17 , L_3 ,
V_16 -> V_16 ) ;
if ( V_16 -> V_18 )
V_17 += snprintf ( V_10 + V_17 , V_13 - V_17 , L_4 ,
V_16 -> V_18 ) ;
if ( V_16 -> V_19 )
V_17 += snprintf ( V_10 + V_17 , V_13 - V_17 , L_5 ,
V_16 -> V_19 ) ;
V_17 += snprintf ( V_10 + V_17 , V_13 - V_17 , L_6 ) ;
return V_17 ;
}
static T_4 F_7 ( struct V_20 * V_21 ,
struct V_22 * V_9 , int V_23 )
{
struct V_6 * V_7 = F_8 ( V_21 ) ;
struct V_24 * V_25 = F_9 ( F_10 ( V_7 ) ) ;
struct V_8 * V_26 = F_5 ( V_9 ,
struct V_8 , V_9 ) ;
struct V_15 * V_16 = F_5 ( V_26 ,
struct V_15 , V_9 ) ;
if ( V_16 -> type == V_27 && ! V_25 -> V_28 )
return 0 ;
if ( V_16 -> type == V_29 && ! V_25 -> V_30 )
return 0 ;
return V_9 -> V_31 ;
}
static T_1 * F_11 ( struct V_24 * V_25 , const char * V_32 )
{
unsigned long V_33 ;
if ( F_12 ( ! V_32 || ! V_32 [ 0 ] || ! isxdigit ( V_32 [ 0 ] ) || ! V_32 [ 1 ] ) )
return NULL ;
V_33 = isdigit ( V_32 [ 0 ] ) ? V_32 [ 0 ] - '0' : 0xa + tolower ( V_32 [ 0 ] ) - 'a' ;
switch ( V_32 [ 1 ] ) {
case 'l' :
return & V_25 -> V_34 . V_35 [ V_33 ] . V_36 ;
case 'h' :
return & V_25 -> V_34 . V_35 [ V_33 ] . V_37 ;
default:
return NULL ;
}
}
static T_3 F_13 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_24 * V_25 = F_9 ( F_10 ( V_7 ) ) ;
T_1 * V_19 = F_11 ( V_25 , V_9 -> V_9 . V_32 ) ;
return V_19 ? snprintf ( V_10 , V_13 , L_7 , * V_19 ) : - V_38 ;
}
static T_3 F_14 ( struct V_6 * V_7 ,
struct V_8 * V_9 , const char * V_10 , T_5 V_39 )
{
struct V_24 * V_25 = F_9 ( F_10 ( V_7 ) ) ;
T_1 * V_19 = F_11 ( V_25 , V_9 -> V_9 . V_32 ) ;
int V_40 = - V_38 ;
if ( V_19 )
V_40 = F_15 ( V_10 , 0 , V_19 ) ;
return V_40 ? V_40 : V_39 ;
}
static T_6 F_16 ( void )
{
return F_17 ( ( T_1 ) V_41 * 1000 ) ;
}
static int F_18 ( unsigned long * V_42 , unsigned long V_43 )
{
int V_44 ;
do {
V_44 = F_19 ( V_42 , V_43 ) ;
if ( V_44 >= V_43 )
return - V_45 ;
} while ( F_20 ( V_44 , V_42 ) );
return V_44 ;
}
static int F_21 ( T_2 V_46 , T_2 V_47 )
{
if ( V_46 == V_47 )
return 1 ;
switch ( V_46 ) {
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
switch ( V_47 ) {
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
return 1 ;
}
break;
}
return 0 ;
}
static void F_22 ( struct V_54 * V_16 )
{
struct V_24 * V_25 = F_9 ( V_16 -> V_55 ) ;
struct V_56 * V_57 = & V_16 -> V_57 ;
if ( V_57 -> V_58 == V_59 ) {
F_23 ( V_59 , V_25 -> V_34 . V_60 ) ;
} else {
struct V_61 * V_62 =
V_25 -> V_34 . V_63 [ V_57 -> V_58 ] . V_62 ;
if ( F_24 ( V_16 -> V_9 . V_3 ) == V_64 &&
F_25 ( V_16 -> V_9 . V_3 ) ==
V_65 )
F_23 ( V_57 -> V_66 , V_62 -> V_67 . V_68 ) ;
else
F_23 ( V_57 -> V_66 , V_62 -> V_69 ) ;
F_23 ( V_57 -> V_58 , V_25 -> V_34 . V_60 ) ;
}
V_25 -> V_34 . V_63 [ V_57 -> V_58 ] . V_62 = NULL ;
V_25 -> V_34 . V_63 [ V_57 -> V_58 ] . V_16 = NULL ;
}
static int F_26 ( struct V_54 * V_16 )
{
struct V_24 * V_25 ;
struct V_56 * V_57 = & V_16 -> V_57 ;
T_2 V_4 , type , V_70 ;
int V_71 , V_44 ;
struct V_61 * V_62 ;
int V_33 ;
if ( V_16 -> V_9 . type != V_16 -> V_55 -> type )
return - V_72 ;
V_25 = F_9 ( V_16 -> V_55 ) ;
V_16 -> V_73 = F_22 ;
if ( V_57 -> V_74 ) {
F_27 ( V_25 -> V_7 , L_8 ) ;
return - V_75 ;
}
if ( F_28 ( V_16 ) || V_16 -> V_9 . V_76 ||
V_16 -> V_9 . V_77 || V_16 -> V_9 . V_78 ||
V_16 -> V_9 . V_79 ) {
F_27 ( V_25 -> V_7 , L_9 ) ;
return - V_75 ;
}
if ( V_16 -> V_80 < 0 ) {
F_27 ( V_25 -> V_7 , L_10 ) ;
return - V_75 ;
}
V_4 = F_29 ( V_16 -> V_9 . V_3 ) ;
type = F_24 ( V_16 -> V_9 . V_3 ) ;
V_70 = F_25 ( V_16 -> V_9 . V_3 ) ;
switch ( type ) {
case V_64 :
if ( V_4 >= V_25 -> V_81 ) {
F_27 ( V_25 -> V_7 , L_11 , V_4 ) ;
return - V_38 ;
}
break;
case V_82 :
break;
default:
if ( V_4 >= V_25 -> V_83 ) {
F_27 ( V_25 -> V_7 , L_12 , V_4 ) ;
return - V_38 ;
}
if ( ! F_21 ( type , V_25 -> V_1 [ V_4 ] . type ) ) {
F_27 ( V_25 -> V_7 , L_13 ,
type , V_4 ) ;
return - V_38 ;
}
break;
}
for ( V_33 = 0 , V_71 = 0 ; V_33 < F_30 ( V_84 ) && ! V_71 ;
V_33 ++ ) {
struct V_15 * V_85 = & V_84 [ V_33 ] ;
T_2 V_5 = F_31 ( V_16 -> V_9 . V_3 ) ;
T_2 V_86 = F_32 ( V_16 -> V_9 . V_3 ) ;
if ( ! F_21 ( type , V_85 -> type ) )
continue;
if ( V_70 != V_85 -> V_16 )
continue;
if ( V_85 -> V_87 && V_5 >= V_85 -> V_87 ) {
F_27 ( V_25 -> V_7 , L_14 ,
V_5 , V_4 ) ;
return - V_38 ;
}
if ( V_85 -> V_88 && V_86 >= V_85 -> V_88 ) {
F_27 ( V_25 -> V_7 , L_15 ,
V_86 , V_4 ) ;
return - V_38 ;
}
V_71 = 1 ;
}
if ( ! V_71 ) {
F_27 ( V_25 -> V_7 , L_16 ,
V_70 , V_4 ) ;
return - V_38 ;
}
if ( V_70 == V_65 && type != V_64 ) {
T_2 V_5 ;
type = V_64 ;
V_5 = F_2 ( V_4 ) ;
V_4 = F_1 ( V_4 ) ;
F_3 ( & V_16 -> V_9 . V_3 ,
V_4 , type , V_5 ) ;
}
if ( type == V_82 ) {
if ( F_20 ( V_59 ,
V_25 -> V_34 . V_60 ) )
return - V_45 ;
V_57 -> V_58 = V_59 ;
V_25 -> V_34 . V_63 [ V_59 ] . V_16 = V_16 ;
return 0 ;
}
V_57 -> V_58 = F_18 ( V_25 -> V_34 . V_60 ,
V_89 ) ;
if ( V_57 -> V_58 < 0 ) {
F_27 ( V_25 -> V_7 , L_17 ) ;
return - V_45 ;
}
if ( type == V_64 )
V_62 = & V_25 -> V_67 [ V_4 ] ;
else
V_62 = & V_25 -> V_1 [ V_4 ] ;
V_25 -> V_34 . V_63 [ V_57 -> V_58 ] . V_62 = V_62 ;
if ( type == V_64 && V_70 == V_65 )
V_44 = F_18 ( V_62 -> V_67 . V_68 ,
V_90 ) ;
else
V_44 = F_18 ( V_62 -> V_69 ,
V_91 ) ;
if ( V_44 < 0 ) {
F_27 ( V_25 -> V_7 , L_18 ,
V_4 ) ;
F_23 ( V_57 -> V_58 , V_25 -> V_34 . V_60 ) ;
return - V_45 ;
}
V_57 -> V_66 = V_44 ;
V_25 -> V_34 . V_63 [ V_57 -> V_58 ] . V_16 = V_16 ;
return 0 ;
}
static T_1 F_33 ( struct V_24 * V_25 , int V_58 )
{
T_1 V_17 ;
if ( V_58 == V_59 ) {
#ifdef F_34
V_17 = F_34 ( V_25 -> V_34 . V_92 + V_93 ) ;
#else
F_35 ( 0x1 , V_25 -> V_34 . V_92 + V_94 ) ;
while ( ! ( F_36 ( V_25 -> V_34 . V_92 + V_95 ) & 0x1 ) )
;
F_35 ( 0x1 , V_25 -> V_34 . V_92 + V_96 ) ;
V_17 = F_36 ( V_25 -> V_34 . V_92 + V_97 + 4 ) & 0xff ;
V_17 <<= 32 ;
V_17 |= F_36 ( V_25 -> V_34 . V_92 + V_97 ) ;
#endif
} else {
V_17 = F_36 ( V_25 -> V_34 . V_92 + F_37 ( V_58 ) ) ;
}
return V_17 ;
}
static void F_38 ( struct V_54 * V_16 )
{
struct V_24 * V_25 = F_9 ( V_16 -> V_55 ) ;
struct V_56 * V_57 = & V_16 -> V_57 ;
T_1 V_98 , V_99 , V_19 ;
do {
V_98 = F_39 ( & V_57 -> V_98 ) ;
V_99 = F_33 ( V_25 , V_57 -> V_58 ) ;
} while ( F_40 ( & V_57 -> V_98 , V_99 ) != V_98 );
V_19 = ( 1LLU << ( V_57 -> V_58 == V_59 ? 40 : 32 ) ) - 1 ;
F_41 ( ( V_99 - V_98 ) & V_19 , & V_16 -> V_39 ) ;
}
static void F_42 ( struct V_54 * V_16 , int V_100 )
{
struct V_24 * V_25 = F_9 ( V_16 -> V_55 ) ;
struct V_56 * V_57 = & V_16 -> V_57 ;
struct V_61 * V_67 ;
T_2 V_101 , V_102 ;
if ( F_24 ( V_16 -> V_9 . V_3 ) == V_64 )
V_67 = & V_25 -> V_67 [ F_43 ( V_16 -> V_9 . V_3 ) ] ;
else
V_67 = & V_25 -> V_67 [ F_1 (
F_29 ( V_16 -> V_9 . V_3 ) ) ] ;
if ( V_100 )
V_102 = V_57 -> V_103 ;
else
V_102 = V_104 ;
F_44 ( & V_25 -> V_34 . V_105 ) ;
V_101 = F_36 ( V_67 -> V_92 + V_106 ) ;
V_101 &= ~ ( V_107 <<
F_45 ( V_57 -> V_58 ) ) ;
V_101 |= V_102 << F_45 ( V_57 -> V_58 ) ;
F_35 ( V_101 , V_67 -> V_92 + V_106 ) ;
F_46 ( & V_25 -> V_34 . V_105 ) ;
}
static void F_47 ( struct V_54 * V_16 , int V_108 )
{
struct V_24 * V_25 = F_9 ( V_16 -> V_55 ) ;
struct V_56 * V_57 = & V_16 -> V_57 ;
F_48 ( & V_16 -> V_57 . V_98 ,
F_33 ( V_25 , V_57 -> V_58 ) ) ;
V_57 -> V_109 = 0 ;
if ( ! V_25 -> V_110 )
F_49 ( & V_25 -> V_34 . V_111 , F_16 () ,
V_112 ) ;
F_42 ( V_16 , 1 ) ;
}
static void F_50 ( struct V_54 * V_16 , int V_108 )
{
struct V_24 * V_25 = F_9 ( V_16 -> V_55 ) ;
struct V_56 * V_57 = & V_16 -> V_57 ;
T_1 V_113 ;
F_42 ( V_16 , 0 ) ;
if ( ! V_25 -> V_110 )
F_51 ( & V_25 -> V_34 . V_111 ) ;
V_113 = F_33 ( V_25 , V_59 ) +
V_25 -> V_81 ;
while ( F_33 ( V_25 , V_59 ) <
V_113 )
F_52 () ;
if ( V_108 & V_114 )
F_38 ( V_16 ) ;
V_57 -> V_109 |= V_115 ;
}
static void F_53 ( struct V_54 * V_16 )
{
struct V_24 * V_25 = F_9 ( V_16 -> V_55 ) ;
struct V_56 * V_57 = & V_16 -> V_57 ;
struct V_61 * V_62 =
V_25 -> V_34 . V_63 [ V_57 -> V_58 ] . V_62 ;
unsigned long V_116 = V_57 -> V_66 ;
T_2 V_101 ;
T_1 V_117 = V_16 -> V_9 . V_118 ;
T_1 V_119 = V_16 -> V_9 . V_120 ;
T_1 V_121 = V_25 -> V_34 . V_35 [ F_54 ( V_16 -> V_9 . V_3 ) ] . V_36 ;
T_1 V_122 = V_25 -> V_34 . V_35 [ F_54 ( V_16 -> V_9 . V_3 ) ] . V_37 ;
V_57 -> V_103 = F_55 ( V_116 ) ;
V_101 = F_36 ( V_62 -> V_92 + V_123 ) ;
V_101 &= ~ ( V_124 <<
F_56 ( V_116 ) ) ;
V_101 |= F_57 ( V_16 -> V_9 . V_3 ) <<
F_56 ( V_116 ) ;
V_101 &= ~ ( V_125 <<
F_58 ( V_116 ) ) ;
V_101 |= F_31 ( V_16 -> V_9 . V_3 ) <<
F_58 ( V_116 ) ;
V_101 &= ~ ( V_126 <<
F_59 ( V_116 ) ) ;
V_101 |= F_32 ( V_16 -> V_9 . V_3 ) <<
F_59 ( V_116 ) ;
F_35 ( V_101 , V_62 -> V_92 + V_123 ) ;
F_35 ( V_117 & 0xffffffff , V_62 -> V_92 + F_60 ( V_116 ) ) ;
F_35 ( ( V_117 >> 32 ) & 0xefffffff ,
V_62 -> V_92 + F_60 ( V_116 ) + 4 ) ;
F_35 ( V_119 & 0xffffffff , V_62 -> V_92 + F_61 ( V_116 ) ) ;
F_35 ( ( V_119 >> 32 ) & 0x0fffffff ,
V_62 -> V_92 + F_61 ( V_116 ) + 4 ) ;
F_35 ( V_121 & 0xffffffff , V_62 -> V_92 + F_62 ( V_116 ) ) ;
F_35 ( ( V_121 >> 32 ) & 0xefffffff ,
V_62 -> V_92 + F_62 ( V_116 ) + 4 ) ;
F_35 ( V_122 & 0xffffffff , V_62 -> V_92 + F_63 ( V_116 ) ) ;
F_35 ( ( V_122 >> 32 ) & 0x0fffffff ,
V_62 -> V_92 + F_63 ( V_116 ) + 4 ) ;
}
static void F_64 ( struct V_54 * V_16 )
{
struct V_24 * V_25 = F_9 ( V_16 -> V_55 ) ;
struct V_56 * V_57 = & V_16 -> V_57 ;
struct V_61 * V_62 =
V_25 -> V_34 . V_63 [ V_57 -> V_58 ] . V_62 ;
T_2 V_101 , V_127 ;
V_57 -> V_103 = F_65 ( V_57 -> V_66 ) ;
V_127 = ( F_32 ( V_16 -> V_9 . V_3 ) << 4 ) |
( F_31 ( V_16 -> V_9 . V_3 ) << 3 ) |
( F_25 ( V_16 -> V_9 . V_3 ) << 0 ) ;
V_101 = F_36 ( V_62 -> V_92 + V_128 ) ;
V_101 &= ~ ( V_129 <<
F_66 ( V_57 -> V_66 ) ) ;
V_101 |= V_127 << F_66 ( V_57 -> V_66 ) ;
F_35 ( V_101 , V_62 -> V_92 + V_128 ) ;
}
static void F_67 ( struct V_54 * V_16 )
{
struct V_24 * V_25 = F_9 ( V_16 -> V_55 ) ;
struct V_56 * V_57 = & V_16 -> V_57 ;
struct V_61 * V_62 =
V_25 -> V_34 . V_63 [ V_57 -> V_58 ] . V_62 ;
T_2 type = F_24 ( V_16 -> V_9 . V_3 ) ;
T_2 V_101 , V_5 ;
V_5 = F_2 ( F_29 ( V_16 -> V_9 . V_3 ) ) ;
V_57 -> V_103 = F_68 ( V_5 ,
V_57 -> V_66 ) ;
F_69 ( V_130 != V_131 ) ;
F_69 ( V_131 != V_132 ) ;
F_69 ( F_70 ( 1 ) !=
F_71 ( 1 ) ) ;
F_69 ( F_71 ( 1 ) !=
F_72 ( 1 ) ) ;
F_69 ( V_133 !=
V_134 ) ;
F_69 ( V_134 !=
V_135 ) ;
if ( F_12 ( type != V_136 && type != V_27 &&
! F_21 ( type , V_50 ) ) )
return;
V_101 = F_36 ( V_62 -> V_92 + V_130 ) ;
V_101 &= ~ ( V_133 <<
F_70 ( V_57 -> V_66 ) ) ;
V_101 |= F_25 ( V_16 -> V_9 . V_3 ) <<
F_70 ( V_57 -> V_66 ) ;
F_35 ( V_101 , V_62 -> V_92 + V_130 ) ;
}
static void F_73 ( struct V_54 * V_16 )
{
struct V_24 * V_25 = F_9 ( V_16 -> V_55 ) ;
struct V_56 * V_57 = & V_16 -> V_57 ;
T_2 V_67 , V_137 , V_101 ;
if ( V_57 -> V_58 == V_59 )
return;
if ( F_24 ( V_16 -> V_9 . V_3 ) == V_64 )
V_67 = F_43 ( V_16 -> V_9 . V_3 ) ;
else
V_67 = F_1 ( F_29 ( V_16 -> V_9 . V_3 ) ) ;
F_44 ( & V_25 -> V_34 . V_105 ) ;
V_137 = ( V_57 -> V_58 / 4 ) * 4 ;
V_101 = F_36 ( V_25 -> V_34 . V_92 + V_138 + V_137 ) ;
V_101 &= ~ ( V_139 <<
F_74 ( V_57 -> V_58 % 4 ) ) ;
V_101 |= V_67 << F_74 ( V_57 -> V_58 % 4 ) ;
F_35 ( V_101 , V_25 -> V_34 . V_92 + V_138 + V_137 ) ;
if ( F_24 ( V_16 -> V_9 . V_3 ) == V_64 ) {
if ( F_25 ( V_16 -> V_9 . V_3 ) ==
V_65 )
F_53 ( V_16 ) ;
else
F_64 ( V_16 ) ;
} else {
F_67 ( V_16 ) ;
}
F_46 ( & V_25 -> V_34 . V_105 ) ;
}
static int F_75 ( struct V_54 * V_16 , int V_108 )
{
struct V_56 * V_57 = & V_16 -> V_57 ;
F_73 ( V_16 ) ;
V_57 -> V_109 = V_115 ;
if ( V_108 & V_140 )
F_47 ( V_16 , V_114 ) ;
return 0 ;
}
static void F_76 ( struct V_54 * V_16 , int V_108 )
{
F_50 ( V_16 , V_114 ) ;
}
static void F_77 ( struct V_54 * V_16 )
{
F_38 ( V_16 ) ;
}
static T_7 F_78 ( struct V_141 * V_34 )
{
T_2 V_142 = F_36 ( V_34 -> V_92 + V_143 ) ;
int V_58 ;
if ( ! V_142 )
return V_144 ;
F_35 ( V_142 , V_34 -> V_92 + V_145 ) ;
F_69 ( V_59 != V_89 ) ;
for ( V_58 = 0 ; V_58 < V_89 + 1 ; V_58 ++ ) {
struct V_54 * V_16 = V_34 -> V_63 [ V_58 ] . V_16 ;
int V_146 = V_142 & F_79 ( V_58 ) ;
F_80 ( V_146 && ! V_16 ) ;
if ( ! V_16 || ! V_146 )
continue;
F_38 ( V_16 ) ;
}
return V_147 ;
}
static enum V_148 F_81 ( struct V_111 * V_111 )
{
struct V_141 * V_34 = F_5 ( V_111 , struct V_141 ,
V_111 ) ;
unsigned long V_108 ;
F_82 ( V_108 ) ;
F_78 ( V_34 ) ;
F_83 ( V_108 ) ;
F_84 ( V_111 , F_16 () ) ;
return V_149 ;
}
static int F_85 ( struct V_24 * V_25 )
{
int V_33 ;
char * V_32 ;
V_25 -> V_34 . V_92 = V_25 -> V_92 + V_150 ;
F_86 ( & V_25 -> V_34 . V_105 ) ;
F_35 ( V_151 , V_25 -> V_34 . V_92 + V_152 ) ;
F_35 ( V_153 | V_154 ,
V_25 -> V_34 . V_92 + V_155 ) ;
F_35 ( 0x1 , V_25 -> V_34 . V_92 + V_96 ) ;
for ( V_33 = 0 ; V_33 < V_25 -> V_81 ; V_33 ++ ) {
F_35 ( 0 , V_25 -> V_67 [ V_33 ] . V_92 + V_106 ) ;
F_35 ( ( V_156 <<
F_87 ( 0 ) ) |
( V_156 <<
F_87 ( 1 ) ) |
V_157 ,
V_25 -> V_67 [ V_33 ] . V_92 + V_158 ) ;
}
V_25 -> V_34 . V_35 [ V_159 ] . V_36 = ~ 0 ;
V_25 -> V_34 . V_35 [ V_159 ] . V_37 = ~ 0 ;
V_25 -> V_34 . V_35 [ V_160 ] . V_36 = 0 ;
V_25 -> V_34 . V_35 [ V_160 ] . V_37 = 0 ;
V_25 -> V_34 . V_35 [ V_161 ] . V_36 = ~ 0 ;
V_25 -> V_34 . V_35 [ V_161 ] . V_37 = ~ ( 0x1 << 15 ) ;
V_25 -> V_34 . V_35 [ V_162 ] . V_36 = ~ 0 ;
V_25 -> V_34 . V_35 [ V_162 ] . V_37 = ~ ( 0x1f << 9 ) ;
V_25 -> V_34 . V_127 = F_88 ( & V_163 , 0 , 0 , V_164 ) ;
if ( V_25 -> V_34 . V_127 == 0 ) {
V_32 = L_19 ;
} else {
int V_165 = snprintf ( NULL , 0 , L_20 , V_25 -> V_34 . V_127 ) ;
V_32 = F_89 ( V_25 -> V_7 , V_165 + 1 , V_164 ) ;
snprintf ( V_32 , V_165 + 1 , L_20 , V_25 -> V_34 . V_127 ) ;
}
V_25 -> V_34 . V_55 = (struct V_55 ) {
. V_166 = V_167 ,
. V_168 = V_169 ,
. V_170 = F_26 ,
. V_171 = F_75 ,
. V_172 = F_76 ,
. V_173 = F_47 ,
. V_174 = F_50 ,
. V_175 = F_77 ,
} ;
if ( ! V_25 -> V_110 ) {
F_90 ( V_25 -> V_7 , L_21 ) ;
F_91 ( & V_25 -> V_34 . V_111 , V_176 ,
V_112 ) ;
V_25 -> V_34 . V_111 . V_177 = F_81 ;
}
return F_92 ( & V_25 -> V_34 . V_55 , V_32 , - 1 ) ;
}
static void F_93 ( struct V_24 * V_25 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_25 -> V_81 ; V_33 ++ )
F_35 ( 0 , V_25 -> V_67 [ V_33 ] . V_92 + V_158 ) ;
F_35 ( 0 , V_25 -> V_34 . V_92 + V_155 ) ;
F_94 ( & V_25 -> V_34 . V_55 ) ;
F_95 ( & V_163 , V_25 -> V_34 . V_127 ) ;
}
static int F_96 ( struct V_24 * V_25 ,
int (* F_97)( struct V_24 * V_25 , int V_178 ,
void T_8 * V_92 , T_2 type , T_2 V_127 ) )
{
int V_178 ;
for ( V_178 = 0 ; V_178 < V_179 ; V_178 ++ ) {
T_2 V_101 , type , V_127 ;
void T_8 * V_92 ;
int V_40 ;
V_101 = F_36 ( V_25 -> V_92 + V_180 +
4 * ( V_178 / 32 ) ) ;
if ( ! ( V_101 & ( 1 << ( V_178 % 32 ) ) ) )
continue;
V_92 = V_25 -> V_92 + V_178 * V_150 ;
V_101 = F_36 ( V_92 + V_181 ) ;
type = ( V_101 >> V_182 ) &
V_183 ;
V_127 = ( V_101 >> V_184 ) &
V_185 ;
V_40 = F_97 ( V_25 , V_178 , V_92 , type , V_127 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_98 ( struct V_24 * V_25 , int V_178 ,
void T_8 * V_92 , T_2 type , T_2 V_127 )
{
if ( type == V_64 && V_127 >= V_25 -> V_81 )
V_25 -> V_81 = V_127 + 1 ;
else if ( V_127 >= V_25 -> V_83 )
V_25 -> V_83 = V_127 + 1 ;
return 0 ;
}
static int F_99 ( struct V_24 * V_25 , int V_178 ,
void T_8 * V_92 , T_2 type , T_2 V_127 )
{
struct V_61 * V_186 ;
F_100 ( V_25 -> V_7 , L_22 , V_178 , V_127 , type ) ;
switch ( type ) {
case V_187 :
case V_188 :
return 0 ;
case V_64 :
V_186 = & V_25 -> V_67 [ V_127 ] ;
break;
case V_29 :
V_25 -> V_30 = 1 ;
V_186 = & V_25 -> V_1 [ V_127 ] ;
break;
case V_27 :
V_25 -> V_28 = 1 ;
default:
V_186 = & V_25 -> V_1 [ V_127 ] ;
break;
}
V_186 -> V_92 = V_92 ;
V_186 -> type = type ;
return 0 ;
}
static T_7 F_101 ( struct V_24 * V_25 ,
const T_2 * V_189 )
{
F_102 ( V_25 -> V_7 , L_23 ,
V_189 [ 5 ] , V_189 [ 4 ] , V_189 [ 3 ] ,
V_189 [ 2 ] , V_189 [ 1 ] , V_189 [ 0 ] ) ;
F_102 ( V_25 -> V_7 , L_24 ) ;
F_35 ( V_190 ,
V_25 -> V_92 + V_191 ) ;
return V_147 ;
}
static T_7 F_103 ( int V_192 , void * V_193 )
{
T_7 V_17 = V_144 ;
struct V_24 * V_25 = V_193 ;
T_2 V_189 [ 6 ] ;
T_2 V_194 ;
int V_33 ;
V_194 = V_189 [ 0 ] = F_36 ( V_25 -> V_92 + V_195 ) ;
if ( V_194 & V_196 ) {
V_194 &= ~ V_196 ;
V_17 = F_78 ( & V_25 -> V_34 ) ;
}
for ( V_33 = 1 ; V_33 < F_30 ( V_189 ) ; V_33 ++ ) {
V_189 [ V_33 ] = F_36 ( V_25 -> V_92 +
V_195 + V_33 * 4 ) ;
V_194 |= V_189 [ V_33 ] ;
}
if ( V_194 )
V_17 |= F_101 ( V_25 , V_189 ) ;
if ( V_17 != V_144 )
F_35 ( V_197 ,
V_25 -> V_92 + V_191 ) ;
return V_17 ;
}
static int F_104 ( struct V_198 * V_199 )
{
struct V_24 * V_25 ;
struct V_200 * V_17 ;
int V_40 ;
V_25 = F_89 ( & V_199 -> V_7 , sizeof( * V_25 ) , V_164 ) ;
if ( ! V_25 )
return - V_201 ;
V_25 -> V_7 = & V_199 -> V_7 ;
F_105 ( V_199 , V_25 ) ;
V_17 = F_106 ( V_199 , V_202 , 0 ) ;
if ( ! V_17 )
return - V_38 ;
if ( ! F_107 ( V_25 -> V_7 , V_17 -> V_173 ,
F_108 ( V_17 ) , V_199 -> V_32 ) )
return - V_203 ;
V_25 -> V_92 = F_109 ( V_25 -> V_7 , V_17 -> V_173 ,
F_108 ( V_17 ) ) ;
if ( ! V_25 -> V_92 )
return - V_204 ;
V_17 = F_106 ( V_199 , V_205 , 0 ) ;
if ( ! V_17 )
return - V_38 ;
F_35 ( V_206 ,
V_25 -> V_92 + V_191 ) ;
if ( F_36 ( V_25 -> V_92 + V_191 ) &
V_207 ) {
F_35 ( V_208 ,
V_25 -> V_92 + V_191 ) ;
V_40 = F_110 ( V_25 -> V_7 , V_17 -> V_173 ,
F_103 , 0 , F_111 ( V_25 -> V_7 ) ,
V_25 ) ;
if ( V_40 )
return V_40 ;
V_25 -> V_110 = 1 ;
}
V_40 = F_96 ( V_25 , F_98 ) ;
if ( V_40 )
return V_40 ;
V_25 -> V_1 = F_89 ( V_25 -> V_7 , sizeof( * V_25 -> V_1 ) * V_25 -> V_83 ,
V_164 ) ;
V_25 -> V_67 = F_89 ( V_25 -> V_7 , sizeof( * V_25 -> V_1 ) * V_25 -> V_81 ,
V_164 ) ;
if ( ! V_25 -> V_1 || ! V_25 -> V_67 )
return - V_201 ;
V_40 = F_96 ( V_25 , F_99 ) ;
if ( V_40 )
return V_40 ;
return F_85 ( V_25 ) ;
}
static int F_112 ( struct V_198 * V_199 )
{
struct V_24 * V_25 = F_113 ( V_199 ) ;
F_93 ( V_25 ) ;
return 0 ;
}
static int T_9 F_114 ( void )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < F_30 ( V_84 ) ; V_33 ++ )
V_209 [ V_33 ] = & V_84 [ V_33 ] . V_9 . V_9 ;
return F_115 ( & V_210 ) ;
}
static void T_10 F_116 ( void )
{
F_117 ( & V_210 ) ;
}
