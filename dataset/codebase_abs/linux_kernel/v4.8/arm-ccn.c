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
struct V_15 * V_16 = F_7 ( F_8 ( V_7 ) ) ;
struct V_17 * V_18 = F_5 ( V_9 ,
struct V_17 , V_9 ) ;
T_3 V_19 ;
V_19 = snprintf ( V_10 , V_13 , L_2 , V_18 -> type ) ;
if ( V_18 -> V_18 )
V_19 += snprintf ( V_10 + V_19 , V_13 - V_19 , L_3 ,
V_18 -> V_18 ) ;
if ( V_18 -> V_20 )
V_19 += snprintf ( V_10 + V_19 , V_13 - V_19 , L_4 ,
V_18 -> V_20 ) ;
if ( V_18 -> V_21 )
V_19 += snprintf ( V_10 + V_19 , V_13 - V_19 , L_5 ,
V_18 -> V_21 ) ;
switch ( V_18 -> type ) {
case V_22 :
break;
case V_23 :
V_19 += snprintf ( V_10 + V_19 , V_13 - V_19 ,
L_6 ) ;
if ( V_18 -> V_18 == V_24 )
V_19 += snprintf ( V_10 + V_19 , V_13 - V_19 ,
L_7 ) ;
else
V_19 += snprintf ( V_10 + V_19 , V_13 - V_19 ,
L_8 ) ;
break;
case V_25 :
V_19 += snprintf ( V_10 + V_19 , V_13 - V_19 , L_9 , V_16 -> V_26 ) ;
break;
default:
V_19 += snprintf ( V_10 + V_19 , V_13 - V_19 , L_10 ) ;
break;
}
V_19 += snprintf ( V_10 + V_19 , V_13 - V_19 , L_11 ) ;
return V_19 ;
}
static T_4 F_9 ( struct V_27 * V_28 ,
struct V_29 * V_9 , int V_30 )
{
struct V_6 * V_7 = F_10 ( V_28 ) ;
struct V_15 * V_16 = F_7 ( F_8 ( V_7 ) ) ;
struct V_8 * V_31 = F_5 ( V_9 ,
struct V_8 , V_9 ) ;
struct V_17 * V_18 = F_5 ( V_31 ,
struct V_17 , V_9 ) ;
if ( V_18 -> type == V_32 && ! V_16 -> V_33 )
return 0 ;
if ( V_18 -> type == V_34 && ! V_16 -> V_35 )
return 0 ;
return V_9 -> V_36 ;
}
static T_1 * F_11 ( struct V_15 * V_16 , const char * V_37 )
{
unsigned long V_38 ;
if ( F_12 ( ! V_37 || ! V_37 [ 0 ] || ! isxdigit ( V_37 [ 0 ] ) || ! V_37 [ 1 ] ) )
return NULL ;
V_38 = isdigit ( V_37 [ 0 ] ) ? V_37 [ 0 ] - '0' : 0xa + tolower ( V_37 [ 0 ] ) - 'a' ;
switch ( V_37 [ 1 ] ) {
case 'l' :
return & V_16 -> V_39 . V_40 [ V_38 ] . V_41 ;
case 'h' :
return & V_16 -> V_39 . V_40 [ V_38 ] . V_42 ;
default:
return NULL ;
}
}
static T_3 F_13 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_15 * V_16 = F_7 ( F_8 ( V_7 ) ) ;
T_1 * V_21 = F_11 ( V_16 , V_9 -> V_9 . V_37 ) ;
return V_21 ? snprintf ( V_10 , V_13 , L_12 , * V_21 ) : - V_43 ;
}
static T_3 F_14 ( struct V_6 * V_7 ,
struct V_8 * V_9 , const char * V_10 , T_5 V_44 )
{
struct V_15 * V_16 = F_7 ( F_8 ( V_7 ) ) ;
T_1 * V_21 = F_11 ( V_16 , V_9 -> V_9 . V_37 ) ;
int V_45 = - V_43 ;
if ( V_21 )
V_45 = F_15 ( V_10 , 0 , V_21 ) ;
return V_45 ? V_45 : V_44 ;
}
static T_3 F_16 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_15 * V_16 = F_7 ( F_8 ( V_7 ) ) ;
return F_17 ( true , V_10 , & V_16 -> V_39 . V_46 ) ;
}
static T_6 F_18 ( void )
{
return F_19 ( ( T_1 ) V_47 * 1000 ) ;
}
static int F_20 ( unsigned long * V_48 , unsigned long V_49 )
{
int V_50 ;
do {
V_50 = F_21 ( V_48 , V_49 ) ;
if ( V_50 >= V_49 )
return - V_51 ;
} while ( F_22 ( V_50 , V_48 ) );
return V_50 ;
}
static int F_23 ( T_2 V_52 , T_2 V_53 )
{
if ( V_52 == V_53 )
return 1 ;
switch ( V_52 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
switch ( V_53 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
return 1 ;
}
break;
}
return 0 ;
}
static int F_24 ( struct V_60 * V_18 )
{
struct V_15 * V_16 = F_7 ( V_18 -> V_61 ) ;
struct V_62 * V_63 = & V_18 -> V_63 ;
T_2 V_4 , type , V_64 ;
struct V_65 * V_66 ;
int V_50 ;
V_4 = F_25 ( V_18 -> V_9 . V_3 ) ;
type = F_26 ( V_18 -> V_9 . V_3 ) ;
V_64 = F_27 ( V_18 -> V_9 . V_3 ) ;
if ( type == V_22 ) {
if ( F_22 ( V_67 ,
V_16 -> V_39 . V_68 ) )
return - V_51 ;
V_63 -> V_69 = V_67 ;
V_16 -> V_39 . V_70 [ V_67 ] . V_18 = V_18 ;
return 0 ;
}
V_63 -> V_69 = F_20 ( V_16 -> V_39 . V_68 ,
V_71 ) ;
if ( V_63 -> V_69 < 0 ) {
F_28 ( V_16 -> V_7 , L_13 ) ;
return - V_51 ;
}
if ( type == V_23 )
V_66 = & V_16 -> V_72 [ V_4 ] ;
else
V_66 = & V_16 -> V_1 [ V_4 ] ;
V_16 -> V_39 . V_70 [ V_63 -> V_69 ] . V_66 = V_66 ;
if ( type == V_23 && V_64 == V_24 )
V_50 = F_20 ( V_66 -> V_72 . V_73 ,
V_74 ) ;
else
V_50 = F_20 ( V_66 -> V_75 ,
V_76 ) ;
if ( V_50 < 0 ) {
F_28 ( V_16 -> V_7 , L_14 ,
V_4 ) ;
F_29 ( V_63 -> V_69 , V_16 -> V_39 . V_68 ) ;
return - V_51 ;
}
V_63 -> V_77 = V_50 ;
V_16 -> V_39 . V_70 [ V_63 -> V_69 ] . V_18 = V_18 ;
return 0 ;
}
static void F_30 ( struct V_60 * V_18 )
{
struct V_15 * V_16 = F_7 ( V_18 -> V_61 ) ;
struct V_62 * V_63 = & V_18 -> V_63 ;
if ( V_63 -> V_69 == V_67 ) {
F_29 ( V_67 , V_16 -> V_39 . V_68 ) ;
} else {
struct V_65 * V_66 =
V_16 -> V_39 . V_70 [ V_63 -> V_69 ] . V_66 ;
if ( F_26 ( V_18 -> V_9 . V_3 ) == V_23 &&
F_27 ( V_18 -> V_9 . V_3 ) ==
V_24 )
F_29 ( V_63 -> V_77 , V_66 -> V_72 . V_73 ) ;
else
F_29 ( V_63 -> V_77 , V_66 -> V_75 ) ;
F_29 ( V_63 -> V_69 , V_16 -> V_39 . V_68 ) ;
}
V_16 -> V_39 . V_70 [ V_63 -> V_69 ] . V_66 = NULL ;
V_16 -> V_39 . V_70 [ V_63 -> V_69 ] . V_18 = NULL ;
}
static int F_31 ( struct V_60 * V_18 )
{
struct V_15 * V_16 ;
struct V_62 * V_63 = & V_18 -> V_63 ;
T_2 V_4 , type , V_64 ;
int V_78 ;
int V_38 ;
struct V_60 * V_79 ;
if ( V_18 -> V_9 . type != V_18 -> V_61 -> type )
return - V_80 ;
V_16 = F_7 ( V_18 -> V_61 ) ;
if ( V_63 -> V_81 ) {
F_32 ( V_16 -> V_7 , L_15 ) ;
return - V_82 ;
}
if ( F_33 ( V_18 ) || V_18 -> V_9 . V_83 ||
V_18 -> V_9 . V_84 || V_18 -> V_9 . V_85 ||
V_18 -> V_9 . V_86 || V_18 -> V_9 . V_87 ||
V_18 -> V_9 . V_88 ) {
F_32 ( V_16 -> V_7 , L_16 ) ;
return - V_43 ;
}
if ( V_18 -> V_46 < 0 ) {
F_32 ( V_16 -> V_7 , L_17 ) ;
return - V_82 ;
}
V_18 -> V_46 = F_34 ( & V_16 -> V_39 . V_46 ) ;
V_4 = F_25 ( V_18 -> V_9 . V_3 ) ;
type = F_26 ( V_18 -> V_9 . V_3 ) ;
V_64 = F_27 ( V_18 -> V_9 . V_3 ) ;
switch ( type ) {
case V_25 :
if ( V_4 != V_16 -> V_26 ) {
F_32 ( V_16 -> V_7 , L_18 , V_4 ) ;
return - V_43 ;
}
break;
case V_23 :
if ( V_4 >= V_16 -> V_89 ) {
F_32 ( V_16 -> V_7 , L_19 , V_4 ) ;
return - V_43 ;
}
break;
case V_22 :
break;
default:
if ( V_4 >= V_16 -> V_90 ) {
F_32 ( V_16 -> V_7 , L_20 , V_4 ) ;
return - V_43 ;
}
if ( ! F_23 ( type , V_16 -> V_1 [ V_4 ] . type ) ) {
F_32 ( V_16 -> V_7 , L_21 ,
type , V_4 ) ;
return - V_43 ;
}
break;
}
for ( V_38 = 0 , V_78 = 0 ; V_38 < F_35 ( V_91 ) && ! V_78 ;
V_38 ++ ) {
struct V_17 * V_92 = & V_91 [ V_38 ] ;
T_2 V_5 = F_36 ( V_18 -> V_9 . V_3 ) ;
T_2 V_93 = F_37 ( V_18 -> V_9 . V_3 ) ;
if ( ! F_23 ( type , V_92 -> type ) )
continue;
if ( V_64 != V_92 -> V_18 )
continue;
if ( V_92 -> V_94 && V_5 >= V_92 -> V_94 ) {
F_32 ( V_16 -> V_7 , L_22 ,
V_5 , V_4 ) ;
return - V_43 ;
}
if ( V_92 -> V_95 && V_93 >= V_92 -> V_95 ) {
F_32 ( V_16 -> V_7 , L_23 ,
V_93 , V_4 ) ;
return - V_43 ;
}
V_78 = 1 ;
}
if ( ! V_78 ) {
F_32 ( V_16 -> V_7 , L_24 ,
V_64 , V_4 ) ;
return - V_43 ;
}
if ( V_64 == V_24 && type != V_23 ) {
T_2 V_5 ;
type = V_23 ;
V_5 = F_2 ( V_4 ) ;
V_4 = F_1 ( V_4 ) ;
F_3 ( & V_18 -> V_9 . V_3 ,
V_4 , type , V_5 ) ;
}
if ( V_18 -> V_96 -> V_61 != V_18 -> V_61 &&
! F_38 ( V_18 -> V_96 ) )
return - V_43 ;
F_39 (sibling, &event->group_leader->sibling_list,
group_entry)
if ( V_79 -> V_61 != V_18 -> V_61 &&
! F_38 ( V_79 ) )
return - V_43 ;
return 0 ;
}
static T_1 F_40 ( struct V_15 * V_16 , int V_69 )
{
T_1 V_19 ;
if ( V_69 == V_67 ) {
#ifdef F_41
V_19 = F_41 ( V_16 -> V_39 . V_97 + V_98 ) ;
#else
F_42 ( 0x1 , V_16 -> V_39 . V_97 + V_99 ) ;
while ( ! ( F_43 ( V_16 -> V_39 . V_97 + V_100 ) & 0x1 ) )
;
F_42 ( 0x1 , V_16 -> V_39 . V_97 + V_101 ) ;
V_19 = F_43 ( V_16 -> V_39 . V_97 + V_102 + 4 ) & 0xff ;
V_19 <<= 32 ;
V_19 |= F_43 ( V_16 -> V_39 . V_97 + V_102 ) ;
#endif
} else {
V_19 = F_43 ( V_16 -> V_39 . V_97 + F_44 ( V_69 ) ) ;
}
return V_19 ;
}
static void F_45 ( struct V_60 * V_18 )
{
struct V_15 * V_16 = F_7 ( V_18 -> V_61 ) ;
struct V_62 * V_63 = & V_18 -> V_63 ;
T_1 V_103 , V_104 , V_21 ;
do {
V_103 = F_46 ( & V_63 -> V_103 ) ;
V_104 = F_40 ( V_16 , V_63 -> V_69 ) ;
} while ( F_47 ( & V_63 -> V_103 , V_104 ) != V_103 );
V_21 = ( 1LLU << ( V_63 -> V_69 == V_67 ? 40 : 32 ) ) - 1 ;
F_48 ( ( V_104 - V_103 ) & V_21 , & V_18 -> V_44 ) ;
}
static void F_49 ( struct V_60 * V_18 , int V_105 )
{
struct V_15 * V_16 = F_7 ( V_18 -> V_61 ) ;
struct V_62 * V_63 = & V_18 -> V_63 ;
struct V_65 * V_72 ;
T_2 V_106 , V_107 ;
if ( V_63 -> V_69 == V_67 )
return;
if ( F_26 ( V_18 -> V_9 . V_3 ) == V_23 )
V_72 = & V_16 -> V_72 [ F_50 ( V_18 -> V_9 . V_3 ) ] ;
else
V_72 = & V_16 -> V_72 [ F_1 (
F_25 ( V_18 -> V_9 . V_3 ) ) ] ;
if ( V_105 )
V_107 = V_63 -> V_108 ;
else
V_107 = V_109 ;
F_51 ( & V_16 -> V_39 . V_110 ) ;
V_106 = F_43 ( V_72 -> V_97 + V_111 ) ;
V_106 &= ~ ( V_112 <<
F_52 ( V_63 -> V_69 ) ) ;
V_106 |= V_107 << F_52 ( V_63 -> V_69 ) ;
F_42 ( V_106 , V_72 -> V_97 + V_111 ) ;
F_53 ( & V_16 -> V_39 . V_110 ) ;
}
static void F_54 ( struct V_60 * V_18 , int V_113 )
{
struct V_15 * V_16 = F_7 ( V_18 -> V_61 ) ;
struct V_62 * V_63 = & V_18 -> V_63 ;
F_55 ( & V_18 -> V_63 . V_103 ,
F_40 ( V_16 , V_63 -> V_69 ) ) ;
V_63 -> V_114 = 0 ;
F_49 ( V_18 , 1 ) ;
}
static void F_56 ( struct V_60 * V_18 , int V_113 )
{
struct V_62 * V_63 = & V_18 -> V_63 ;
F_49 ( V_18 , 0 ) ;
if ( V_113 & V_115 )
F_45 ( V_18 ) ;
V_63 -> V_114 |= V_116 ;
}
static void F_57 ( struct V_60 * V_18 )
{
struct V_15 * V_16 = F_7 ( V_18 -> V_61 ) ;
struct V_62 * V_63 = & V_18 -> V_63 ;
struct V_65 * V_66 =
V_16 -> V_39 . V_70 [ V_63 -> V_69 ] . V_66 ;
unsigned long V_117 = V_63 -> V_77 ;
T_2 V_106 ;
T_1 V_118 = V_18 -> V_9 . V_119 ;
T_1 V_120 = V_18 -> V_9 . V_121 ;
T_1 V_122 = V_16 -> V_39 . V_40 [ F_58 ( V_18 -> V_9 . V_3 ) ] . V_41 ;
T_1 V_123 = V_16 -> V_39 . V_40 [ F_58 ( V_18 -> V_9 . V_3 ) ] . V_42 ;
V_63 -> V_108 = F_59 ( V_117 ) ;
V_106 = F_43 ( V_66 -> V_97 + V_124 ) ;
V_106 &= ~ ( V_125 <<
F_60 ( V_117 ) ) ;
V_106 |= F_61 ( V_18 -> V_9 . V_3 ) <<
F_60 ( V_117 ) ;
V_106 &= ~ ( V_126 <<
F_62 ( V_117 ) ) ;
V_106 |= F_36 ( V_18 -> V_9 . V_3 ) <<
F_62 ( V_117 ) ;
V_106 &= ~ ( V_127 <<
F_63 ( V_117 ) ) ;
V_106 |= F_37 ( V_18 -> V_9 . V_3 ) <<
F_63 ( V_117 ) ;
F_42 ( V_106 , V_66 -> V_97 + V_124 ) ;
F_42 ( V_118 & 0xffffffff , V_66 -> V_97 + F_64 ( V_117 ) ) ;
F_42 ( ( V_118 >> 32 ) & 0x7fffffff ,
V_66 -> V_97 + F_64 ( V_117 ) + 4 ) ;
F_42 ( V_120 & 0xffffffff , V_66 -> V_97 + F_65 ( V_117 ) ) ;
F_42 ( ( V_120 >> 32 ) & 0x0fffffff ,
V_66 -> V_97 + F_65 ( V_117 ) + 4 ) ;
F_42 ( V_122 & 0xffffffff , V_66 -> V_97 + F_66 ( V_117 ) ) ;
F_42 ( ( V_122 >> 32 ) & 0x7fffffff ,
V_66 -> V_97 + F_66 ( V_117 ) + 4 ) ;
F_42 ( V_123 & 0xffffffff , V_66 -> V_97 + F_67 ( V_117 ) ) ;
F_42 ( ( V_123 >> 32 ) & 0x0fffffff ,
V_66 -> V_97 + F_67 ( V_117 ) + 4 ) ;
}
static void F_68 ( struct V_60 * V_18 )
{
struct V_15 * V_16 = F_7 ( V_18 -> V_61 ) ;
struct V_62 * V_63 = & V_18 -> V_63 ;
struct V_65 * V_66 =
V_16 -> V_39 . V_70 [ V_63 -> V_69 ] . V_66 ;
T_2 V_106 , V_128 ;
V_63 -> V_108 = F_69 ( V_63 -> V_77 ) ;
V_128 = ( F_37 ( V_18 -> V_9 . V_3 ) << 4 ) |
( F_70 ( V_18 -> V_9 . V_3 ) << 3 ) |
( F_27 ( V_18 -> V_9 . V_3 ) << 0 ) ;
V_106 = F_43 ( V_66 -> V_97 + V_129 ) ;
V_106 &= ~ ( V_130 <<
F_71 ( V_63 -> V_77 ) ) ;
V_106 |= V_128 << F_71 ( V_63 -> V_77 ) ;
F_42 ( V_106 , V_66 -> V_97 + V_129 ) ;
}
static void F_72 ( struct V_60 * V_18 )
{
struct V_15 * V_16 = F_7 ( V_18 -> V_61 ) ;
struct V_62 * V_63 = & V_18 -> V_63 ;
struct V_65 * V_66 =
V_16 -> V_39 . V_70 [ V_63 -> V_69 ] . V_66 ;
T_2 type = F_26 ( V_18 -> V_9 . V_3 ) ;
T_2 V_106 , V_5 ;
V_5 = F_2 ( F_25 ( V_18 -> V_9 . V_3 ) ) ;
V_63 -> V_108 = F_73 ( V_5 ,
V_63 -> V_77 ) ;
F_74 ( V_131 != V_132 ) ;
F_74 ( V_132 != V_133 ) ;
F_74 ( F_75 ( 1 ) !=
F_76 ( 1 ) ) ;
F_74 ( F_76 ( 1 ) !=
F_77 ( 1 ) ) ;
F_74 ( V_134 !=
V_135 ) ;
F_74 ( V_135 !=
V_136 ) ;
if ( F_12 ( type != V_137 && type != V_32 &&
! F_23 ( type , V_56 ) ) )
return;
V_106 = F_43 ( V_66 -> V_97 + V_131 ) ;
V_106 &= ~ ( V_134 <<
F_75 ( V_63 -> V_77 ) ) ;
V_106 |= F_27 ( V_18 -> V_9 . V_3 ) <<
F_75 ( V_63 -> V_77 ) ;
F_42 ( V_106 , V_66 -> V_97 + V_131 ) ;
}
static void F_78 ( struct V_60 * V_18 )
{
struct V_15 * V_16 = F_7 ( V_18 -> V_61 ) ;
struct V_62 * V_63 = & V_18 -> V_63 ;
T_2 V_72 , V_138 , V_106 ;
if ( V_63 -> V_69 == V_67 )
return;
if ( F_26 ( V_18 -> V_9 . V_3 ) == V_23 )
V_72 = F_50 ( V_18 -> V_9 . V_3 ) ;
else
V_72 = F_1 ( F_25 ( V_18 -> V_9 . V_3 ) ) ;
F_51 ( & V_16 -> V_39 . V_110 ) ;
V_138 = ( V_63 -> V_69 / 4 ) * 4 ;
V_106 = F_43 ( V_16 -> V_39 . V_97 + V_139 + V_138 ) ;
V_106 &= ~ ( V_140 <<
F_79 ( V_63 -> V_69 % 4 ) ) ;
V_106 |= V_72 << F_79 ( V_63 -> V_69 % 4 ) ;
F_42 ( V_106 , V_16 -> V_39 . V_97 + V_139 + V_138 ) ;
if ( F_26 ( V_18 -> V_9 . V_3 ) == V_23 ) {
if ( F_27 ( V_18 -> V_9 . V_3 ) ==
V_24 )
F_57 ( V_18 ) ;
else
F_68 ( V_18 ) ;
} else {
F_72 ( V_18 ) ;
}
F_53 ( & V_16 -> V_39 . V_110 ) ;
}
static int F_80 ( struct V_15 * V_16 )
{
return F_81 ( V_16 -> V_39 . V_68 ,
V_71 + 1 ) ;
}
static int F_82 ( struct V_60 * V_18 , int V_113 )
{
int V_45 ;
struct V_62 * V_63 = & V_18 -> V_63 ;
struct V_15 * V_16 = F_7 ( V_18 -> V_61 ) ;
V_45 = F_24 ( V_18 ) ;
if ( V_45 )
return V_45 ;
if ( ! V_16 -> V_141 && F_80 ( V_16 ) == 1 )
F_83 ( & V_16 -> V_39 . V_142 , F_18 () ,
V_143 ) ;
F_78 ( V_18 ) ;
V_63 -> V_114 = V_116 ;
if ( V_113 & V_144 )
F_54 ( V_18 , V_115 ) ;
return 0 ;
}
static void F_84 ( struct V_60 * V_18 , int V_113 )
{
struct V_15 * V_16 = F_7 ( V_18 -> V_61 ) ;
F_56 ( V_18 , V_115 ) ;
F_30 ( V_18 ) ;
if ( ! V_16 -> V_141 && F_80 ( V_16 ) == 0 )
F_85 ( & V_16 -> V_39 . V_142 ) ;
}
static void F_86 ( struct V_60 * V_18 )
{
F_45 ( V_18 ) ;
}
static void F_87 ( struct V_61 * V_61 )
{
struct V_15 * V_16 = F_7 ( V_61 ) ;
T_2 V_106 = F_43 ( V_16 -> V_39 . V_97 + V_145 ) ;
V_106 |= V_146 ;
F_42 ( V_106 , V_16 -> V_39 . V_97 + V_145 ) ;
}
static void F_88 ( struct V_61 * V_61 )
{
struct V_15 * V_16 = F_7 ( V_61 ) ;
T_2 V_106 = F_43 ( V_16 -> V_39 . V_97 + V_145 ) ;
V_106 &= ~ V_146 ;
F_42 ( V_106 , V_16 -> V_39 . V_97 + V_145 ) ;
}
static T_7 F_89 ( struct V_147 * V_39 )
{
T_2 V_148 = F_43 ( V_39 -> V_97 + V_149 ) ;
int V_69 ;
if ( ! V_148 )
return V_150 ;
F_42 ( V_148 , V_39 -> V_97 + V_151 ) ;
F_74 ( V_67 != V_71 ) ;
for ( V_69 = 0 ; V_69 < V_71 + 1 ; V_69 ++ ) {
struct V_60 * V_18 = V_39 -> V_70 [ V_69 ] . V_18 ;
int V_152 = V_148 & F_90 ( V_69 ) ;
F_91 ( V_152 && ! V_18 &&
V_69 != V_67 ) ;
if ( ! V_18 || ! V_152 )
continue;
F_45 ( V_18 ) ;
}
return V_153 ;
}
static enum V_154 F_92 ( struct V_142 * V_142 )
{
struct V_147 * V_39 = F_5 ( V_142 , struct V_147 ,
V_142 ) ;
unsigned long V_113 ;
F_93 ( V_113 ) ;
F_89 ( V_39 ) ;
F_94 ( V_113 ) ;
F_95 ( V_142 , F_18 () ) ;
return V_155 ;
}
static int F_96 ( unsigned int V_46 )
{
struct V_147 * V_39 ;
unsigned int V_156 ;
F_97 ( & V_157 ) ;
F_39 (dt, &arm_ccn_list, entry) {
struct V_15 * V_16 = F_5 ( V_39 , struct V_15 , V_39 ) ;
if ( ! F_98 ( V_46 , & V_39 -> V_46 ) )
continue;
V_156 = F_99 ( V_158 , V_46 ) ;
if ( V_156 >= V_159 )
continue;
F_100 ( & V_39 -> V_61 , V_46 , V_156 ) ;
F_101 ( V_156 , & V_39 -> V_46 ) ;
if ( V_16 -> V_141 )
F_12 ( F_102 ( V_16 -> V_141 , & V_39 -> V_46 ) != 0 ) ;
}
F_103 ( & V_157 ) ;
return 0 ;
}
static int F_104 ( struct V_15 * V_16 )
{
int V_38 ;
char * V_37 ;
int V_45 ;
V_16 -> V_39 . V_97 = V_16 -> V_97 + V_160 ;
F_105 ( & V_16 -> V_39 . V_110 ) ;
F_42 ( V_161 , V_16 -> V_39 . V_97 + V_151 ) ;
F_42 ( V_162 , V_16 -> V_39 . V_97 + V_163 ) ;
F_42 ( V_164 | V_146 ,
V_16 -> V_39 . V_97 + V_145 ) ;
F_42 ( 0x1 , V_16 -> V_39 . V_97 + V_101 ) ;
for ( V_38 = 0 ; V_38 < V_16 -> V_89 ; V_38 ++ ) {
F_42 ( 0 , V_16 -> V_72 [ V_38 ] . V_97 + V_111 ) ;
F_42 ( ( V_165 <<
F_106 ( 0 ) ) |
( V_165 <<
F_106 ( 1 ) ) |
V_166 ,
V_16 -> V_72 [ V_38 ] . V_97 + V_167 ) ;
}
V_16 -> V_39 . V_40 [ V_168 ] . V_41 = ~ 0 ;
V_16 -> V_39 . V_40 [ V_168 ] . V_42 = ~ 0 ;
V_16 -> V_39 . V_40 [ V_169 ] . V_41 = 0 ;
V_16 -> V_39 . V_40 [ V_169 ] . V_42 = 0 ;
V_16 -> V_39 . V_40 [ V_170 ] . V_41 = ~ 0 ;
V_16 -> V_39 . V_40 [ V_170 ] . V_42 = ~ ( 0x1 << 15 ) ;
V_16 -> V_39 . V_40 [ V_171 ] . V_41 = ~ 0 ;
V_16 -> V_39 . V_40 [ V_171 ] . V_42 = ~ ( 0x1f << 9 ) ;
V_16 -> V_39 . V_128 = F_107 ( & V_172 , 0 , 0 , V_173 ) ;
if ( V_16 -> V_39 . V_128 == 0 ) {
V_37 = L_25 ;
} else {
int V_174 = snprintf ( NULL , 0 , L_26 , V_16 -> V_39 . V_128 ) ;
V_37 = F_108 ( V_16 -> V_7 , V_174 + 1 , V_173 ) ;
snprintf ( V_37 , V_174 + 1 , L_26 , V_16 -> V_39 . V_128 ) ;
}
V_16 -> V_39 . V_61 = (struct V_61 ) {
. V_175 = V_176 ,
. V_177 = V_178 ,
. V_179 = F_31 ,
. V_180 = F_82 ,
. V_181 = F_84 ,
. V_182 = F_54 ,
. V_183 = F_56 ,
. V_184 = F_86 ,
. V_185 = F_87 ,
. V_186 = F_88 ,
} ;
if ( ! V_16 -> V_141 ) {
F_109 ( V_16 -> V_7 , L_27 ) ;
F_110 ( & V_16 -> V_39 . V_142 , V_187 ,
V_188 ) ;
V_16 -> V_39 . V_142 . V_189 = F_92 ;
}
F_101 ( F_111 () , & V_16 -> V_39 . V_46 ) ;
if ( V_16 -> V_141 ) {
V_45 = F_102 ( V_16 -> V_141 , & V_16 -> V_39 . V_46 ) ;
if ( V_45 ) {
F_112 ( V_16 -> V_7 , L_28 ) ;
goto V_190;
}
}
V_45 = F_113 ( & V_16 -> V_39 . V_61 , V_37 , - 1 ) ;
if ( V_45 )
goto V_191;
F_97 ( & V_157 ) ;
F_114 ( & V_16 -> V_39 . V_192 , & V_193 ) ;
F_103 ( & V_157 ) ;
return 0 ;
V_191:
V_190:
F_115 ( & V_172 , V_16 -> V_39 . V_128 ) ;
for ( V_38 = 0 ; V_38 < V_16 -> V_89 ; V_38 ++ )
F_42 ( 0 , V_16 -> V_72 [ V_38 ] . V_97 + V_167 ) ;
F_42 ( 0 , V_16 -> V_39 . V_97 + V_145 ) ;
return V_45 ;
}
static void F_116 ( struct V_15 * V_16 )
{
int V_38 ;
F_97 ( & V_157 ) ;
F_117 ( & V_16 -> V_39 . V_192 ) ;
F_103 ( & V_157 ) ;
if ( V_16 -> V_141 )
F_102 ( V_16 -> V_141 , NULL ) ;
for ( V_38 = 0 ; V_38 < V_16 -> V_89 ; V_38 ++ )
F_42 ( 0 , V_16 -> V_72 [ V_38 ] . V_97 + V_167 ) ;
F_42 ( 0 , V_16 -> V_39 . V_97 + V_145 ) ;
F_118 ( & V_16 -> V_39 . V_61 ) ;
F_115 ( & V_172 , V_16 -> V_39 . V_128 ) ;
}
static int F_119 ( struct V_15 * V_16 ,
int (* F_120)( struct V_15 * V_16 , int V_194 ,
void T_8 * V_97 , T_2 type , T_2 V_128 ) )
{
int V_194 ;
for ( V_194 = 0 ; V_194 < V_195 ; V_194 ++ ) {
T_2 V_106 , type , V_128 ;
void T_8 * V_97 ;
int V_45 ;
V_106 = F_43 ( V_16 -> V_97 + V_196 +
4 * ( V_194 / 32 ) ) ;
if ( ! ( V_106 & ( 1 << ( V_194 % 32 ) ) ) )
continue;
V_97 = V_16 -> V_97 + V_194 * V_160 ;
V_106 = F_43 ( V_97 + V_197 ) ;
type = ( V_106 >> V_198 ) &
V_199 ;
V_128 = ( V_106 >> V_200 ) &
V_201 ;
V_45 = F_120 ( V_16 , V_194 , V_97 , type , V_128 ) ;
if ( V_45 )
return V_45 ;
}
return 0 ;
}
static int F_121 ( struct V_15 * V_16 , int V_194 ,
void T_8 * V_97 , T_2 type , T_2 V_128 )
{
if ( type == V_23 && V_128 >= V_16 -> V_89 )
V_16 -> V_89 = V_128 + 1 ;
else if ( V_128 >= V_16 -> V_90 )
V_16 -> V_90 = V_128 + 1 ;
return 0 ;
}
static int F_122 ( struct V_15 * V_16 , int V_194 ,
void T_8 * V_97 , T_2 type , T_2 V_128 )
{
struct V_65 * V_202 ;
F_28 ( V_16 -> V_7 , L_29 , V_194 , V_128 , type ) ;
switch ( type ) {
case V_25 :
V_16 -> V_26 = V_128 ;
return 0 ;
case V_203 :
return 0 ;
case V_23 :
V_202 = & V_16 -> V_72 [ V_128 ] ;
break;
case V_34 :
V_16 -> V_35 = 1 ;
V_202 = & V_16 -> V_1 [ V_128 ] ;
break;
case V_32 :
V_16 -> V_33 = 1 ;
default:
V_202 = & V_16 -> V_1 [ V_128 ] ;
break;
}
V_202 -> V_97 = V_97 ;
V_202 -> type = type ;
return 0 ;
}
static T_7 F_123 ( struct V_15 * V_16 ,
const T_2 * V_204 )
{
F_112 ( V_16 -> V_7 , L_30 ,
V_204 [ 5 ] , V_204 [ 4 ] , V_204 [ 3 ] ,
V_204 [ 2 ] , V_204 [ 1 ] , V_204 [ 0 ] ) ;
F_112 ( V_16 -> V_7 , L_31 ) ;
F_42 ( V_205 ,
V_16 -> V_97 + V_206 ) ;
return V_153 ;
}
static T_7 F_124 ( int V_141 , void * V_207 )
{
T_7 V_19 = V_150 ;
struct V_15 * V_16 = V_207 ;
T_2 V_204 [ 6 ] ;
T_2 V_208 ;
int V_38 ;
V_208 = V_204 [ 0 ] = F_43 ( V_16 -> V_97 + V_209 ) ;
if ( V_208 & V_210 ) {
V_208 &= ~ V_210 ;
V_19 = F_89 ( & V_16 -> V_39 ) ;
}
for ( V_38 = 1 ; V_38 < F_35 ( V_204 ) ; V_38 ++ ) {
V_204 [ V_38 ] = F_43 ( V_16 -> V_97 +
V_209 + V_38 * 4 ) ;
V_208 |= V_204 [ V_38 ] ;
}
if ( V_208 )
V_19 |= F_123 ( V_16 , V_204 ) ;
if ( V_19 != V_150 )
F_42 ( V_211 ,
V_16 -> V_97 + V_206 ) ;
return V_19 ;
}
static int F_125 ( struct V_212 * V_213 )
{
struct V_15 * V_16 ;
struct V_214 * V_19 ;
unsigned int V_141 ;
int V_45 ;
V_16 = F_108 ( & V_213 -> V_7 , sizeof( * V_16 ) , V_173 ) ;
if ( ! V_16 )
return - V_215 ;
V_16 -> V_7 = & V_213 -> V_7 ;
F_126 ( V_213 , V_16 ) ;
V_19 = F_127 ( V_213 , V_216 , 0 ) ;
if ( ! V_19 )
return - V_43 ;
if ( ! F_128 ( V_16 -> V_7 , V_19 -> V_182 ,
F_129 ( V_19 ) , V_213 -> V_37 ) )
return - V_217 ;
V_16 -> V_97 = F_130 ( V_16 -> V_7 , V_19 -> V_182 ,
F_129 ( V_19 ) ) ;
if ( ! V_16 -> V_97 )
return - V_218 ;
V_19 = F_127 ( V_213 , V_219 , 0 ) ;
if ( ! V_19 )
return - V_43 ;
V_141 = V_19 -> V_182 ;
F_42 ( V_220 ,
V_16 -> V_97 + V_206 ) ;
if ( F_43 ( V_16 -> V_97 + V_206 ) &
V_221 ) {
F_42 ( V_222 ,
V_16 -> V_97 + V_206 ) ;
V_45 = F_131 ( V_16 -> V_7 , V_141 , F_124 ,
V_223 | V_224 ,
F_132 ( V_16 -> V_7 ) , V_16 ) ;
if ( V_45 )
return V_45 ;
V_16 -> V_141 = V_141 ;
}
V_45 = F_119 ( V_16 , F_121 ) ;
if ( V_45 )
return V_45 ;
V_16 -> V_1 = F_108 ( V_16 -> V_7 , sizeof( * V_16 -> V_1 ) * V_16 -> V_90 ,
V_173 ) ;
V_16 -> V_72 = F_108 ( V_16 -> V_7 , sizeof( * V_16 -> V_1 ) * V_16 -> V_89 ,
V_173 ) ;
if ( ! V_16 -> V_1 || ! V_16 -> V_72 )
return - V_215 ;
V_45 = F_119 ( V_16 , F_122 ) ;
if ( V_45 )
return V_45 ;
return F_104 ( V_16 ) ;
}
static int F_133 ( struct V_212 * V_213 )
{
struct V_15 * V_16 = F_134 ( V_213 ) ;
F_116 ( V_16 ) ;
return 0 ;
}
static int T_9 F_135 ( void )
{
int V_38 , V_225 ;
V_225 = F_136 ( V_226 ,
L_32 , NULL ,
F_96 ) ;
if ( V_225 )
return V_225 ;
for ( V_38 = 0 ; V_38 < F_35 ( V_91 ) ; V_38 ++ )
V_227 [ V_38 ] = & V_91 [ V_38 ] . V_9 . V_9 ;
return F_137 ( & V_228 ) ;
}
static void T_10 F_138 ( void )
{
F_139 ( V_226 ) ;
F_140 ( & V_228 ) ;
}
