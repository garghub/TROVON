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
* V_3 &= ~ ( ( 0xff << 0 ) | ( 0xff << 8 ) | ( 0x3 << 24 ) ) ;
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
switch ( V_16 -> type ) {
case V_20 :
break;
case V_21 :
V_17 += snprintf ( V_10 + V_17 , V_13 - V_17 ,
L_6 ) ;
if ( V_16 -> V_16 == V_22 )
V_17 += snprintf ( V_10 + V_17 , V_13 - V_17 ,
L_7 ) ;
break;
default:
V_17 += snprintf ( V_10 + V_17 , V_13 - V_17 , L_8 ) ;
break;
}
V_17 += snprintf ( V_10 + V_17 , V_13 - V_17 , L_9 ) ;
return V_17 ;
}
static T_4 F_7 ( struct V_23 * V_24 ,
struct V_25 * V_9 , int V_26 )
{
struct V_6 * V_7 = F_8 ( V_24 ) ;
struct V_27 * V_28 = F_9 ( F_10 ( V_7 ) ) ;
struct V_8 * V_29 = F_5 ( V_9 ,
struct V_8 , V_9 ) ;
struct V_15 * V_16 = F_5 ( V_29 ,
struct V_15 , V_9 ) ;
if ( V_16 -> type == V_30 && ! V_28 -> V_31 )
return 0 ;
if ( V_16 -> type == V_32 && ! V_28 -> V_33 )
return 0 ;
return V_9 -> V_34 ;
}
static T_1 * F_11 ( struct V_27 * V_28 , const char * V_35 )
{
unsigned long V_36 ;
if ( F_12 ( ! V_35 || ! V_35 [ 0 ] || ! isxdigit ( V_35 [ 0 ] ) || ! V_35 [ 1 ] ) )
return NULL ;
V_36 = isdigit ( V_35 [ 0 ] ) ? V_35 [ 0 ] - '0' : 0xa + tolower ( V_35 [ 0 ] ) - 'a' ;
switch ( V_35 [ 1 ] ) {
case 'l' :
return & V_28 -> V_37 . V_38 [ V_36 ] . V_39 ;
case 'h' :
return & V_28 -> V_37 . V_38 [ V_36 ] . V_40 ;
default:
return NULL ;
}
}
static T_3 F_13 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_27 * V_28 = F_9 ( F_10 ( V_7 ) ) ;
T_1 * V_19 = F_11 ( V_28 , V_9 -> V_9 . V_35 ) ;
return V_19 ? snprintf ( V_10 , V_13 , L_10 , * V_19 ) : - V_41 ;
}
static T_3 F_14 ( struct V_6 * V_7 ,
struct V_8 * V_9 , const char * V_10 , T_5 V_42 )
{
struct V_27 * V_28 = F_9 ( F_10 ( V_7 ) ) ;
T_1 * V_19 = F_11 ( V_28 , V_9 -> V_9 . V_35 ) ;
int V_43 = - V_41 ;
if ( V_19 )
V_43 = F_15 ( V_10 , 0 , V_19 ) ;
return V_43 ? V_43 : V_42 ;
}
static T_3 F_16 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_27 * V_28 = F_9 ( F_10 ( V_7 ) ) ;
return F_17 ( true , V_10 , & V_28 -> V_37 . V_44 ) ;
}
static T_6 F_18 ( void )
{
return F_19 ( ( T_1 ) V_45 * 1000 ) ;
}
static int F_20 ( unsigned long * V_46 , unsigned long V_47 )
{
int V_48 ;
do {
V_48 = F_21 ( V_46 , V_47 ) ;
if ( V_48 >= V_47 )
return - V_49 ;
} while ( F_22 ( V_48 , V_46 ) );
return V_48 ;
}
static int F_23 ( T_2 V_50 , T_2 V_51 )
{
if ( V_50 == V_51 )
return 1 ;
switch ( V_50 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
switch ( V_51 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
return 1 ;
}
break;
}
return 0 ;
}
static int F_24 ( struct V_58 * V_16 )
{
struct V_27 * V_28 = F_9 ( V_16 -> V_59 ) ;
struct V_60 * V_61 = & V_16 -> V_61 ;
T_2 V_4 , type , V_62 ;
struct V_63 * V_64 ;
int V_48 ;
V_4 = F_25 ( V_16 -> V_9 . V_3 ) ;
type = F_26 ( V_16 -> V_9 . V_3 ) ;
V_62 = F_27 ( V_16 -> V_9 . V_3 ) ;
if ( type == V_20 ) {
if ( F_22 ( V_65 ,
V_28 -> V_37 . V_66 ) )
return - V_49 ;
V_61 -> V_67 = V_65 ;
V_28 -> V_37 . V_68 [ V_65 ] . V_16 = V_16 ;
return 0 ;
}
V_61 -> V_67 = F_20 ( V_28 -> V_37 . V_66 ,
V_69 ) ;
if ( V_61 -> V_67 < 0 ) {
F_28 ( V_28 -> V_7 , L_11 ) ;
return - V_49 ;
}
if ( type == V_21 )
V_64 = & V_28 -> V_70 [ V_4 ] ;
else
V_64 = & V_28 -> V_1 [ V_4 ] ;
V_28 -> V_37 . V_68 [ V_61 -> V_67 ] . V_64 = V_64 ;
if ( type == V_21 && V_62 == V_22 )
V_48 = F_20 ( V_64 -> V_70 . V_71 ,
V_72 ) ;
else
V_48 = F_20 ( V_64 -> V_73 ,
V_74 ) ;
if ( V_48 < 0 ) {
F_28 ( V_28 -> V_7 , L_12 ,
V_4 ) ;
F_29 ( V_61 -> V_67 , V_28 -> V_37 . V_66 ) ;
return - V_49 ;
}
V_61 -> V_75 = V_48 ;
V_28 -> V_37 . V_68 [ V_61 -> V_67 ] . V_16 = V_16 ;
return 0 ;
}
static void F_30 ( struct V_58 * V_16 )
{
struct V_27 * V_28 = F_9 ( V_16 -> V_59 ) ;
struct V_60 * V_61 = & V_16 -> V_61 ;
if ( V_61 -> V_67 == V_65 ) {
F_29 ( V_65 , V_28 -> V_37 . V_66 ) ;
} else {
struct V_63 * V_64 =
V_28 -> V_37 . V_68 [ V_61 -> V_67 ] . V_64 ;
if ( F_26 ( V_16 -> V_9 . V_3 ) == V_21 &&
F_27 ( V_16 -> V_9 . V_3 ) ==
V_22 )
F_29 ( V_61 -> V_75 , V_64 -> V_70 . V_71 ) ;
else
F_29 ( V_61 -> V_75 , V_64 -> V_73 ) ;
F_29 ( V_61 -> V_67 , V_28 -> V_37 . V_66 ) ;
}
V_28 -> V_37 . V_68 [ V_61 -> V_67 ] . V_64 = NULL ;
V_28 -> V_37 . V_68 [ V_61 -> V_67 ] . V_16 = NULL ;
}
static int F_31 ( struct V_58 * V_16 )
{
struct V_27 * V_28 ;
struct V_60 * V_61 = & V_16 -> V_61 ;
T_2 V_4 , type , V_62 ;
int V_76 ;
int V_36 ;
struct V_58 * V_77 ;
if ( V_16 -> V_9 . type != V_16 -> V_59 -> type )
return - V_78 ;
V_28 = F_9 ( V_16 -> V_59 ) ;
if ( V_61 -> V_79 ) {
F_32 ( V_28 -> V_7 , L_13 ) ;
return - V_80 ;
}
if ( F_33 ( V_16 ) || V_16 -> V_9 . V_81 ||
V_16 -> V_9 . V_82 || V_16 -> V_9 . V_83 ||
V_16 -> V_9 . V_84 ) {
F_32 ( V_28 -> V_7 , L_14 ) ;
return - V_80 ;
}
if ( V_16 -> V_44 < 0 ) {
F_32 ( V_28 -> V_7 , L_15 ) ;
return - V_80 ;
}
V_16 -> V_44 = F_34 ( & V_28 -> V_37 . V_44 ) ;
V_4 = F_25 ( V_16 -> V_9 . V_3 ) ;
type = F_26 ( V_16 -> V_9 . V_3 ) ;
V_62 = F_27 ( V_16 -> V_9 . V_3 ) ;
switch ( type ) {
case V_21 :
if ( V_4 >= V_28 -> V_85 ) {
F_32 ( V_28 -> V_7 , L_16 , V_4 ) ;
return - V_41 ;
}
break;
case V_20 :
break;
default:
if ( V_4 >= V_28 -> V_86 ) {
F_32 ( V_28 -> V_7 , L_17 , V_4 ) ;
return - V_41 ;
}
if ( ! F_23 ( type , V_28 -> V_1 [ V_4 ] . type ) ) {
F_32 ( V_28 -> V_7 , L_18 ,
type , V_4 ) ;
return - V_41 ;
}
break;
}
for ( V_36 = 0 , V_76 = 0 ; V_36 < F_35 ( V_87 ) && ! V_76 ;
V_36 ++ ) {
struct V_15 * V_88 = & V_87 [ V_36 ] ;
T_2 V_5 = F_36 ( V_16 -> V_9 . V_3 ) ;
T_2 V_89 = F_37 ( V_16 -> V_9 . V_3 ) ;
if ( ! F_23 ( type , V_88 -> type ) )
continue;
if ( V_62 != V_88 -> V_16 )
continue;
if ( V_88 -> V_90 && V_5 >= V_88 -> V_90 ) {
F_32 ( V_28 -> V_7 , L_19 ,
V_5 , V_4 ) ;
return - V_41 ;
}
if ( V_88 -> V_91 && V_89 >= V_88 -> V_91 ) {
F_32 ( V_28 -> V_7 , L_20 ,
V_89 , V_4 ) ;
return - V_41 ;
}
V_76 = 1 ;
}
if ( ! V_76 ) {
F_32 ( V_28 -> V_7 , L_21 ,
V_62 , V_4 ) ;
return - V_41 ;
}
if ( V_62 == V_22 && type != V_21 ) {
T_2 V_5 ;
type = V_21 ;
V_5 = F_2 ( V_4 ) ;
V_4 = F_1 ( V_4 ) ;
F_3 ( & V_16 -> V_9 . V_3 ,
V_4 , type , V_5 ) ;
}
if ( V_16 -> V_92 -> V_59 != V_16 -> V_59 &&
! F_38 ( V_16 -> V_92 ) )
return - V_41 ;
F_39 (sibling, &event->group_leader->sibling_list,
group_entry)
if ( V_77 -> V_59 != V_16 -> V_59 &&
! F_38 ( V_77 ) )
return - V_41 ;
return 0 ;
}
static T_1 F_40 ( struct V_27 * V_28 , int V_67 )
{
T_1 V_17 ;
if ( V_67 == V_65 ) {
#ifdef F_41
V_17 = F_41 ( V_28 -> V_37 . V_93 + V_94 ) ;
#else
F_42 ( 0x1 , V_28 -> V_37 . V_93 + V_95 ) ;
while ( ! ( F_43 ( V_28 -> V_37 . V_93 + V_96 ) & 0x1 ) )
;
F_42 ( 0x1 , V_28 -> V_37 . V_93 + V_97 ) ;
V_17 = F_43 ( V_28 -> V_37 . V_93 + V_98 + 4 ) & 0xff ;
V_17 <<= 32 ;
V_17 |= F_43 ( V_28 -> V_37 . V_93 + V_98 ) ;
#endif
} else {
V_17 = F_43 ( V_28 -> V_37 . V_93 + F_44 ( V_67 ) ) ;
}
return V_17 ;
}
static void F_45 ( struct V_58 * V_16 )
{
struct V_27 * V_28 = F_9 ( V_16 -> V_59 ) ;
struct V_60 * V_61 = & V_16 -> V_61 ;
T_1 V_99 , V_100 , V_19 ;
do {
V_99 = F_46 ( & V_61 -> V_99 ) ;
V_100 = F_40 ( V_28 , V_61 -> V_67 ) ;
} while ( F_47 ( & V_61 -> V_99 , V_100 ) != V_99 );
V_19 = ( 1LLU << ( V_61 -> V_67 == V_65 ? 40 : 32 ) ) - 1 ;
F_48 ( ( V_100 - V_99 ) & V_19 , & V_16 -> V_42 ) ;
}
static void F_49 ( struct V_58 * V_16 , int V_101 )
{
struct V_27 * V_28 = F_9 ( V_16 -> V_59 ) ;
struct V_60 * V_61 = & V_16 -> V_61 ;
struct V_63 * V_70 ;
T_2 V_102 , V_103 ;
if ( F_26 ( V_16 -> V_9 . V_3 ) == V_21 )
V_70 = & V_28 -> V_70 [ F_50 ( V_16 -> V_9 . V_3 ) ] ;
else
V_70 = & V_28 -> V_70 [ F_1 (
F_25 ( V_16 -> V_9 . V_3 ) ) ] ;
if ( V_101 )
V_103 = V_61 -> V_104 ;
else
V_103 = V_105 ;
F_51 ( & V_28 -> V_37 . V_106 ) ;
V_102 = F_43 ( V_70 -> V_93 + V_107 ) ;
V_102 &= ~ ( V_108 <<
F_52 ( V_61 -> V_67 ) ) ;
V_102 |= V_103 << F_52 ( V_61 -> V_67 ) ;
F_42 ( V_102 , V_70 -> V_93 + V_107 ) ;
F_53 ( & V_28 -> V_37 . V_106 ) ;
}
static void F_54 ( struct V_58 * V_16 , int V_109 )
{
struct V_27 * V_28 = F_9 ( V_16 -> V_59 ) ;
struct V_60 * V_61 = & V_16 -> V_61 ;
F_55 ( & V_16 -> V_61 . V_99 ,
F_40 ( V_28 , V_61 -> V_67 ) ) ;
V_61 -> V_110 = 0 ;
if ( ! V_28 -> V_111 )
F_56 ( & V_28 -> V_37 . V_112 , F_18 () ,
V_113 ) ;
F_49 ( V_16 , 1 ) ;
}
static void F_57 ( struct V_58 * V_16 , int V_109 )
{
struct V_27 * V_28 = F_9 ( V_16 -> V_59 ) ;
struct V_60 * V_61 = & V_16 -> V_61 ;
T_1 V_114 ;
F_49 ( V_16 , 0 ) ;
if ( ! V_28 -> V_111 )
F_58 ( & V_28 -> V_37 . V_112 ) ;
V_114 = F_40 ( V_28 , V_65 ) +
V_28 -> V_85 ;
while ( F_40 ( V_28 , V_65 ) <
V_114 )
F_59 () ;
if ( V_109 & V_115 )
F_45 ( V_16 ) ;
V_61 -> V_110 |= V_116 ;
}
static void F_60 ( struct V_58 * V_16 )
{
struct V_27 * V_28 = F_9 ( V_16 -> V_59 ) ;
struct V_60 * V_61 = & V_16 -> V_61 ;
struct V_63 * V_64 =
V_28 -> V_37 . V_68 [ V_61 -> V_67 ] . V_64 ;
unsigned long V_117 = V_61 -> V_75 ;
T_2 V_102 ;
T_1 V_118 = V_16 -> V_9 . V_119 ;
T_1 V_120 = V_16 -> V_9 . V_121 ;
T_1 V_122 = V_28 -> V_37 . V_38 [ F_61 ( V_16 -> V_9 . V_3 ) ] . V_39 ;
T_1 V_123 = V_28 -> V_37 . V_38 [ F_61 ( V_16 -> V_9 . V_3 ) ] . V_40 ;
V_61 -> V_104 = F_62 ( V_117 ) ;
V_102 = F_43 ( V_64 -> V_93 + V_124 ) ;
V_102 &= ~ ( V_125 <<
F_63 ( V_117 ) ) ;
V_102 |= F_64 ( V_16 -> V_9 . V_3 ) <<
F_63 ( V_117 ) ;
V_102 &= ~ ( V_126 <<
F_65 ( V_117 ) ) ;
V_102 |= F_36 ( V_16 -> V_9 . V_3 ) <<
F_65 ( V_117 ) ;
V_102 &= ~ ( V_127 <<
F_66 ( V_117 ) ) ;
V_102 |= F_37 ( V_16 -> V_9 . V_3 ) <<
F_66 ( V_117 ) ;
F_42 ( V_102 , V_64 -> V_93 + V_124 ) ;
F_42 ( V_118 & 0xffffffff , V_64 -> V_93 + F_67 ( V_117 ) ) ;
F_42 ( ( V_118 >> 32 ) & 0xefffffff ,
V_64 -> V_93 + F_67 ( V_117 ) + 4 ) ;
F_42 ( V_120 & 0xffffffff , V_64 -> V_93 + F_68 ( V_117 ) ) ;
F_42 ( ( V_120 >> 32 ) & 0x0fffffff ,
V_64 -> V_93 + F_68 ( V_117 ) + 4 ) ;
F_42 ( V_122 & 0xffffffff , V_64 -> V_93 + F_69 ( V_117 ) ) ;
F_42 ( ( V_122 >> 32 ) & 0xefffffff ,
V_64 -> V_93 + F_69 ( V_117 ) + 4 ) ;
F_42 ( V_123 & 0xffffffff , V_64 -> V_93 + F_70 ( V_117 ) ) ;
F_42 ( ( V_123 >> 32 ) & 0x0fffffff ,
V_64 -> V_93 + F_70 ( V_117 ) + 4 ) ;
}
static void F_71 ( struct V_58 * V_16 )
{
struct V_27 * V_28 = F_9 ( V_16 -> V_59 ) ;
struct V_60 * V_61 = & V_16 -> V_61 ;
struct V_63 * V_64 =
V_28 -> V_37 . V_68 [ V_61 -> V_67 ] . V_64 ;
T_2 V_102 , V_128 ;
V_61 -> V_104 = F_72 ( V_61 -> V_75 ) ;
V_128 = ( F_37 ( V_16 -> V_9 . V_3 ) << 4 ) |
( F_36 ( V_16 -> V_9 . V_3 ) << 3 ) |
( F_27 ( V_16 -> V_9 . V_3 ) << 0 ) ;
V_102 = F_43 ( V_64 -> V_93 + V_129 ) ;
V_102 &= ~ ( V_130 <<
F_73 ( V_61 -> V_75 ) ) ;
V_102 |= V_128 << F_73 ( V_61 -> V_75 ) ;
F_42 ( V_102 , V_64 -> V_93 + V_129 ) ;
}
static void F_74 ( struct V_58 * V_16 )
{
struct V_27 * V_28 = F_9 ( V_16 -> V_59 ) ;
struct V_60 * V_61 = & V_16 -> V_61 ;
struct V_63 * V_64 =
V_28 -> V_37 . V_68 [ V_61 -> V_67 ] . V_64 ;
T_2 type = F_26 ( V_16 -> V_9 . V_3 ) ;
T_2 V_102 , V_5 ;
V_5 = F_2 ( F_25 ( V_16 -> V_9 . V_3 ) ) ;
V_61 -> V_104 = F_75 ( V_5 ,
V_61 -> V_75 ) ;
F_76 ( V_131 != V_132 ) ;
F_76 ( V_132 != V_133 ) ;
F_76 ( F_77 ( 1 ) !=
F_78 ( 1 ) ) ;
F_76 ( F_78 ( 1 ) !=
F_79 ( 1 ) ) ;
F_76 ( V_134 !=
V_135 ) ;
F_76 ( V_135 !=
V_136 ) ;
if ( F_12 ( type != V_137 && type != V_30 &&
! F_23 ( type , V_54 ) ) )
return;
V_102 = F_43 ( V_64 -> V_93 + V_131 ) ;
V_102 &= ~ ( V_134 <<
F_77 ( V_61 -> V_75 ) ) ;
V_102 |= F_27 ( V_16 -> V_9 . V_3 ) <<
F_77 ( V_61 -> V_75 ) ;
F_42 ( V_102 , V_64 -> V_93 + V_131 ) ;
}
static void F_80 ( struct V_58 * V_16 )
{
struct V_27 * V_28 = F_9 ( V_16 -> V_59 ) ;
struct V_60 * V_61 = & V_16 -> V_61 ;
T_2 V_70 , V_138 , V_102 ;
if ( V_61 -> V_67 == V_65 )
return;
if ( F_26 ( V_16 -> V_9 . V_3 ) == V_21 )
V_70 = F_50 ( V_16 -> V_9 . V_3 ) ;
else
V_70 = F_1 ( F_25 ( V_16 -> V_9 . V_3 ) ) ;
F_51 ( & V_28 -> V_37 . V_106 ) ;
V_138 = ( V_61 -> V_67 / 4 ) * 4 ;
V_102 = F_43 ( V_28 -> V_37 . V_93 + V_139 + V_138 ) ;
V_102 &= ~ ( V_140 <<
F_81 ( V_61 -> V_67 % 4 ) ) ;
V_102 |= V_70 << F_81 ( V_61 -> V_67 % 4 ) ;
F_42 ( V_102 , V_28 -> V_37 . V_93 + V_139 + V_138 ) ;
if ( F_26 ( V_16 -> V_9 . V_3 ) == V_21 ) {
if ( F_27 ( V_16 -> V_9 . V_3 ) ==
V_22 )
F_60 ( V_16 ) ;
else
F_71 ( V_16 ) ;
} else {
F_74 ( V_16 ) ;
}
F_53 ( & V_28 -> V_37 . V_106 ) ;
}
static int F_82 ( struct V_58 * V_16 , int V_109 )
{
int V_43 ;
struct V_60 * V_61 = & V_16 -> V_61 ;
V_43 = F_24 ( V_16 ) ;
if ( V_43 )
return V_43 ;
F_80 ( V_16 ) ;
V_61 -> V_110 = V_116 ;
if ( V_109 & V_141 )
F_54 ( V_16 , V_115 ) ;
return 0 ;
}
static void F_83 ( struct V_58 * V_16 , int V_109 )
{
F_57 ( V_16 , V_115 ) ;
F_30 ( V_16 ) ;
}
static void F_84 ( struct V_58 * V_16 )
{
F_45 ( V_16 ) ;
}
static T_7 F_85 ( struct V_142 * V_37 )
{
T_2 V_143 = F_43 ( V_37 -> V_93 + V_144 ) ;
int V_67 ;
if ( ! V_143 )
return V_145 ;
F_42 ( V_143 , V_37 -> V_93 + V_146 ) ;
F_76 ( V_65 != V_69 ) ;
for ( V_67 = 0 ; V_67 < V_69 + 1 ; V_67 ++ ) {
struct V_58 * V_16 = V_37 -> V_68 [ V_67 ] . V_16 ;
int V_147 = V_143 & F_86 ( V_67 ) ;
F_87 ( V_147 && ! V_16 &&
V_67 != V_65 ) ;
if ( ! V_16 || ! V_147 )
continue;
F_45 ( V_16 ) ;
}
return V_148 ;
}
static enum V_149 F_88 ( struct V_112 * V_112 )
{
struct V_142 * V_37 = F_5 ( V_112 , struct V_142 ,
V_112 ) ;
unsigned long V_109 ;
F_89 ( V_109 ) ;
F_85 ( V_37 ) ;
F_90 ( V_109 ) ;
F_91 ( V_112 , F_18 () ) ;
return V_150 ;
}
static int F_92 ( struct V_151 * V_152 ,
unsigned long V_153 , void * V_154 )
{
struct V_142 * V_37 = F_5 ( V_152 , struct V_142 , V_155 ) ;
struct V_27 * V_28 = F_5 ( V_37 , struct V_27 , V_37 ) ;
unsigned int V_44 = ( long ) V_154 ;
unsigned int V_156 ;
switch ( V_153 & ~ V_157 ) {
case V_158 :
if ( ! F_93 ( V_44 , & V_37 -> V_44 ) )
break;
V_156 = F_94 ( V_159 , V_44 ) ;
if ( V_156 < 0 )
break;
F_95 ( & V_37 -> V_59 , V_44 , V_156 ) ;
F_96 ( V_156 , & V_37 -> V_44 ) ;
F_12 ( F_97 ( V_28 -> V_111 , & V_37 -> V_44 ) != 0 ) ;
default:
break;
}
return V_160 ;
}
static int F_98 ( struct V_27 * V_28 )
{
int V_36 ;
char * V_35 ;
int V_43 ;
V_28 -> V_37 . V_93 = V_28 -> V_93 + V_161 ;
F_99 ( & V_28 -> V_37 . V_106 ) ;
F_42 ( V_162 , V_28 -> V_37 . V_93 + V_146 ) ;
F_42 ( V_163 , V_28 -> V_37 . V_93 + V_164 ) ;
F_42 ( V_165 | V_166 ,
V_28 -> V_37 . V_93 + V_167 ) ;
F_42 ( 0x1 , V_28 -> V_37 . V_93 + V_97 ) ;
for ( V_36 = 0 ; V_36 < V_28 -> V_85 ; V_36 ++ ) {
F_42 ( 0 , V_28 -> V_70 [ V_36 ] . V_93 + V_107 ) ;
F_42 ( ( V_168 <<
F_100 ( 0 ) ) |
( V_168 <<
F_100 ( 1 ) ) |
V_169 ,
V_28 -> V_70 [ V_36 ] . V_93 + V_170 ) ;
}
V_28 -> V_37 . V_38 [ V_171 ] . V_39 = ~ 0 ;
V_28 -> V_37 . V_38 [ V_171 ] . V_40 = ~ 0 ;
V_28 -> V_37 . V_38 [ V_172 ] . V_39 = 0 ;
V_28 -> V_37 . V_38 [ V_172 ] . V_40 = 0 ;
V_28 -> V_37 . V_38 [ V_173 ] . V_39 = ~ 0 ;
V_28 -> V_37 . V_38 [ V_173 ] . V_40 = ~ ( 0x1 << 15 ) ;
V_28 -> V_37 . V_38 [ V_174 ] . V_39 = ~ 0 ;
V_28 -> V_37 . V_38 [ V_174 ] . V_40 = ~ ( 0x1f << 9 ) ;
V_28 -> V_37 . V_128 = F_101 ( & V_175 , 0 , 0 , V_176 ) ;
if ( V_28 -> V_37 . V_128 == 0 ) {
V_35 = L_22 ;
} else {
int V_177 = snprintf ( NULL , 0 , L_23 , V_28 -> V_37 . V_128 ) ;
V_35 = F_102 ( V_28 -> V_7 , V_177 + 1 , V_176 ) ;
snprintf ( V_35 , V_177 + 1 , L_23 , V_28 -> V_37 . V_128 ) ;
}
V_28 -> V_37 . V_59 = (struct V_59 ) {
. V_178 = V_179 ,
. V_180 = V_181 ,
. V_182 = F_31 ,
. V_183 = F_82 ,
. V_184 = F_83 ,
. V_185 = F_54 ,
. V_186 = F_57 ,
. V_187 = F_84 ,
} ;
if ( ! V_28 -> V_111 ) {
F_103 ( V_28 -> V_7 , L_24 ) ;
F_104 ( & V_28 -> V_37 . V_112 , V_188 ,
V_189 ) ;
V_28 -> V_37 . V_112 . V_190 = F_88 ;
}
F_96 ( F_105 () , & V_28 -> V_37 . V_44 ) ;
V_28 -> V_37 . V_155 . V_191 = F_92 ;
V_28 -> V_37 . V_155 . V_192 = V_193 + 1 ,
V_43 = F_106 ( & V_28 -> V_37 . V_155 ) ;
if ( V_43 )
goto V_194;
if ( V_28 -> V_111 ) {
V_43 = F_97 ( V_28 -> V_111 , & V_28 -> V_37 . V_44 ) ;
if ( V_43 ) {
F_107 ( V_28 -> V_7 , L_25 ) ;
goto V_195;
}
}
V_43 = F_108 ( & V_28 -> V_37 . V_59 , V_35 , - 1 ) ;
if ( V_43 )
goto V_196;
return 0 ;
V_196:
V_195:
F_109 ( & V_28 -> V_37 . V_155 ) ;
V_194:
F_110 ( & V_175 , V_28 -> V_37 . V_128 ) ;
for ( V_36 = 0 ; V_36 < V_28 -> V_85 ; V_36 ++ )
F_42 ( 0 , V_28 -> V_70 [ V_36 ] . V_93 + V_170 ) ;
F_42 ( 0 , V_28 -> V_37 . V_93 + V_167 ) ;
return V_43 ;
}
static void F_111 ( struct V_27 * V_28 )
{
int V_36 ;
F_97 ( V_28 -> V_111 , V_197 ) ;
F_109 ( & V_28 -> V_37 . V_155 ) ;
for ( V_36 = 0 ; V_36 < V_28 -> V_85 ; V_36 ++ )
F_42 ( 0 , V_28 -> V_70 [ V_36 ] . V_93 + V_170 ) ;
F_42 ( 0 , V_28 -> V_37 . V_93 + V_167 ) ;
F_112 ( & V_28 -> V_37 . V_59 ) ;
F_110 ( & V_175 , V_28 -> V_37 . V_128 ) ;
}
static int F_113 ( struct V_27 * V_28 ,
int (* F_114)( struct V_27 * V_28 , int V_198 ,
void T_8 * V_93 , T_2 type , T_2 V_128 ) )
{
int V_198 ;
for ( V_198 = 0 ; V_198 < V_199 ; V_198 ++ ) {
T_2 V_102 , type , V_128 ;
void T_8 * V_93 ;
int V_43 ;
V_102 = F_43 ( V_28 -> V_93 + V_200 +
4 * ( V_198 / 32 ) ) ;
if ( ! ( V_102 & ( 1 << ( V_198 % 32 ) ) ) )
continue;
V_93 = V_28 -> V_93 + V_198 * V_161 ;
V_102 = F_43 ( V_93 + V_201 ) ;
type = ( V_102 >> V_202 ) &
V_203 ;
V_128 = ( V_102 >> V_204 ) &
V_205 ;
V_43 = F_114 ( V_28 , V_198 , V_93 , type , V_128 ) ;
if ( V_43 )
return V_43 ;
}
return 0 ;
}
static int F_115 ( struct V_27 * V_28 , int V_198 ,
void T_8 * V_93 , T_2 type , T_2 V_128 )
{
if ( type == V_21 && V_128 >= V_28 -> V_85 )
V_28 -> V_85 = V_128 + 1 ;
else if ( V_128 >= V_28 -> V_86 )
V_28 -> V_86 = V_128 + 1 ;
return 0 ;
}
static int F_116 ( struct V_27 * V_28 , int V_198 ,
void T_8 * V_93 , T_2 type , T_2 V_128 )
{
struct V_63 * V_206 ;
F_28 ( V_28 -> V_7 , L_26 , V_198 , V_128 , type ) ;
switch ( type ) {
case V_207 :
case V_208 :
return 0 ;
case V_21 :
V_206 = & V_28 -> V_70 [ V_128 ] ;
break;
case V_32 :
V_28 -> V_33 = 1 ;
V_206 = & V_28 -> V_1 [ V_128 ] ;
break;
case V_30 :
V_28 -> V_31 = 1 ;
default:
V_206 = & V_28 -> V_1 [ V_128 ] ;
break;
}
V_206 -> V_93 = V_93 ;
V_206 -> type = type ;
return 0 ;
}
static T_7 F_117 ( struct V_27 * V_28 ,
const T_2 * V_209 )
{
F_107 ( V_28 -> V_7 , L_27 ,
V_209 [ 5 ] , V_209 [ 4 ] , V_209 [ 3 ] ,
V_209 [ 2 ] , V_209 [ 1 ] , V_209 [ 0 ] ) ;
F_107 ( V_28 -> V_7 , L_28 ) ;
F_42 ( V_210 ,
V_28 -> V_93 + V_211 ) ;
return V_148 ;
}
static T_7 F_118 ( int V_111 , void * V_212 )
{
T_7 V_17 = V_145 ;
struct V_27 * V_28 = V_212 ;
T_2 V_209 [ 6 ] ;
T_2 V_213 ;
int V_36 ;
V_213 = V_209 [ 0 ] = F_43 ( V_28 -> V_93 + V_214 ) ;
if ( V_213 & V_215 ) {
V_213 &= ~ V_215 ;
V_17 = F_85 ( & V_28 -> V_37 ) ;
}
for ( V_36 = 1 ; V_36 < F_35 ( V_209 ) ; V_36 ++ ) {
V_209 [ V_36 ] = F_43 ( V_28 -> V_93 +
V_214 + V_36 * 4 ) ;
V_213 |= V_209 [ V_36 ] ;
}
if ( V_213 )
V_17 |= F_117 ( V_28 , V_209 ) ;
if ( V_17 != V_145 )
F_42 ( V_216 ,
V_28 -> V_93 + V_211 ) ;
return V_17 ;
}
static int F_119 ( struct V_217 * V_218 )
{
struct V_27 * V_28 ;
struct V_219 * V_17 ;
unsigned int V_111 ;
int V_43 ;
V_28 = F_102 ( & V_218 -> V_7 , sizeof( * V_28 ) , V_176 ) ;
if ( ! V_28 )
return - V_220 ;
V_28 -> V_7 = & V_218 -> V_7 ;
F_120 ( V_218 , V_28 ) ;
V_17 = F_121 ( V_218 , V_221 , 0 ) ;
if ( ! V_17 )
return - V_41 ;
if ( ! F_122 ( V_28 -> V_7 , V_17 -> V_185 ,
F_123 ( V_17 ) , V_218 -> V_35 ) )
return - V_222 ;
V_28 -> V_93 = F_124 ( V_28 -> V_7 , V_17 -> V_185 ,
F_123 ( V_17 ) ) ;
if ( ! V_28 -> V_93 )
return - V_223 ;
V_17 = F_121 ( V_218 , V_224 , 0 ) ;
if ( ! V_17 )
return - V_41 ;
V_111 = V_17 -> V_185 ;
F_42 ( V_225 ,
V_28 -> V_93 + V_211 ) ;
if ( F_43 ( V_28 -> V_93 + V_211 ) &
V_226 ) {
F_42 ( V_227 ,
V_28 -> V_93 + V_211 ) ;
V_43 = F_125 ( V_28 -> V_7 , V_111 , F_118 , 0 ,
F_126 ( V_28 -> V_7 ) , V_28 ) ;
if ( V_43 )
return V_43 ;
V_28 -> V_111 = V_111 ;
}
V_43 = F_113 ( V_28 , F_115 ) ;
if ( V_43 )
return V_43 ;
V_28 -> V_1 = F_102 ( V_28 -> V_7 , sizeof( * V_28 -> V_1 ) * V_28 -> V_86 ,
V_176 ) ;
V_28 -> V_70 = F_102 ( V_28 -> V_7 , sizeof( * V_28 -> V_1 ) * V_28 -> V_85 ,
V_176 ) ;
if ( ! V_28 -> V_1 || ! V_28 -> V_70 )
return - V_220 ;
V_43 = F_113 ( V_28 , F_116 ) ;
if ( V_43 )
return V_43 ;
return F_98 ( V_28 ) ;
}
static int F_127 ( struct V_217 * V_218 )
{
struct V_27 * V_28 = F_128 ( V_218 ) ;
F_111 ( V_28 ) ;
return 0 ;
}
static int T_9 F_129 ( void )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < F_35 ( V_87 ) ; V_36 ++ )
V_228 [ V_36 ] = & V_87 [ V_36 ] . V_9 . V_9 ;
return F_130 ( & V_229 ) ;
}
static void T_10 F_131 ( void )
{
F_132 ( & V_229 ) ;
}
