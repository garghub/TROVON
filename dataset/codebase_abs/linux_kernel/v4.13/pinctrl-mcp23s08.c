static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int * V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 << V_2 -> V_6 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 )
{
return F_4 ( V_2 -> V_5 , V_3 << V_2 -> V_6 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_7 , bool V_8 )
{
T_1 V_4 = V_8 ? 0xffff : 0x0000 ;
return F_6 ( V_2 -> V_5 , V_3 << V_2 -> V_6 ,
V_7 , V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_9 , bool V_8 )
{
T_1 V_7 = F_8 ( V_9 ) ;
return F_5 ( V_2 , V_3 , V_7 , V_8 ) ;
}
static int F_9 ( struct V_10 * V_11 )
{
return 0 ;
}
static const char * F_10 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
return NULL ;
}
static int F_11 ( struct V_10 * V_11 ,
unsigned int V_12 ,
const unsigned int * * V_13 ,
unsigned int * V_14 )
{
return - V_15 ;
}
static int F_12 ( struct V_10 * V_11 , unsigned int V_9 ,
unsigned long * V_16 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
enum V_17 V_18 = F_14 ( * V_16 ) ;
unsigned int V_19 , V_20 ;
int V_21 ;
switch ( V_18 ) {
case V_22 :
V_21 = F_1 ( V_2 , V_23 , & V_19 ) ;
if ( V_21 < 0 )
return V_21 ;
V_20 = ( V_19 & F_8 ( V_9 ) ) ? 1 : 0 ;
break;
default:
F_15 ( V_2 -> V_24 , L_1 , V_18 ) ;
return - V_15 ;
}
* V_16 = 0 ;
return V_20 ? 0 : - V_25 ;
}
static int F_16 ( struct V_10 * V_11 , unsigned int V_9 ,
unsigned long * V_26 , unsigned int V_27 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
enum V_17 V_18 ;
T_2 V_28 , V_7 ;
T_1 V_4 ;
int V_21 = 0 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_27 ; V_29 ++ ) {
V_18 = F_14 ( V_26 [ V_29 ] ) ;
V_28 = F_17 ( V_26 [ V_29 ] ) ;
switch ( V_18 ) {
case V_22 :
V_4 = V_28 ? 0xFFFF : 0x0000 ;
V_7 = F_8 ( V_9 ) ;
V_21 = F_7 ( V_2 , V_23 , V_9 , V_28 ) ;
break;
default:
F_15 ( V_2 -> V_24 , L_1 , V_18 ) ;
return - V_15 ;
}
}
return V_21 ;
}
static int F_18 ( void * V_30 , const void * V_19 , T_3 V_31 )
{
struct V_1 * V_2 = V_30 ;
struct V_32 * V_33 = F_19 ( V_2 -> V_24 ) ;
struct V_34 V_35 ;
struct V_36 V_37 [ 2 ] = { { . V_38 = & V_2 -> V_39 , . V_40 = 1 , } ,
{ . V_38 = V_19 , . V_40 = V_31 , } , } ;
F_20 ( & V_35 ) ;
F_21 ( & V_37 [ 0 ] , & V_35 ) ;
F_21 ( & V_37 [ 1 ] , & V_35 ) ;
return F_22 ( V_33 , & V_35 ) ;
}
static int F_23 ( void * V_30 ,
const void * V_3 , T_3 V_41 ,
const void * V_4 , T_3 V_42 )
{
struct V_1 * V_2 = V_30 ;
struct V_32 * V_33 = F_19 ( V_2 -> V_24 ) ;
struct V_34 V_35 ;
struct V_36 V_37 [ 3 ] = { { . V_38 = & V_2 -> V_39 , . V_40 = 1 , } ,
{ . V_38 = V_3 , . V_40 = V_41 , } ,
{ . V_38 = V_4 , . V_40 = V_42 , } , } ;
F_20 ( & V_35 ) ;
F_21 ( & V_37 [ 0 ] , & V_35 ) ;
F_21 ( & V_37 [ 1 ] , & V_35 ) ;
F_21 ( & V_37 [ 2 ] , & V_35 ) ;
return F_22 ( V_33 , & V_35 ) ;
}
static int F_24 ( void * V_30 , const void * V_3 , T_3 V_41 ,
void * V_4 , T_3 V_42 )
{
struct V_1 * V_2 = V_30 ;
struct V_32 * V_33 = F_19 ( V_2 -> V_24 ) ;
T_4 V_43 [ 2 ] ;
if ( V_41 != 1 )
return - V_25 ;
V_43 [ 0 ] = V_2 -> V_39 | 0x01 ;
V_43 [ 1 ] = * ( ( T_4 * ) V_3 ) ;
return F_25 ( V_33 , V_43 , sizeof( V_43 ) , V_4 , V_42 ) ;
}
static int F_26 ( struct V_44 * V_45 , unsigned V_46 )
{
struct V_1 * V_2 = F_27 ( V_45 ) ;
int V_20 ;
F_28 ( & V_2 -> V_47 ) ;
V_20 = F_7 ( V_2 , V_48 , V_46 , true ) ;
F_29 ( & V_2 -> V_47 ) ;
return V_20 ;
}
static int F_30 ( struct V_44 * V_45 , unsigned V_46 )
{
struct V_1 * V_2 = F_27 ( V_45 ) ;
int V_20 , V_21 ;
F_28 ( & V_2 -> V_47 ) ;
V_21 = F_1 ( V_2 , V_49 , & V_20 ) ;
if ( V_21 < 0 )
V_20 = 0 ;
else
V_20 = ! ! ( V_20 & ( 1 << V_46 ) ) ;
V_2 -> V_50 = V_20 ;
F_29 ( & V_2 -> V_47 ) ;
return V_20 ;
}
static int F_31 ( struct V_1 * V_2 , unsigned V_7 , bool V_51 )
{
return F_5 ( V_2 , V_52 , V_7 , V_51 ) ;
}
static void F_32 ( struct V_44 * V_45 , unsigned V_46 , int V_51 )
{
struct V_1 * V_2 = F_27 ( V_45 ) ;
unsigned V_7 = F_8 ( V_46 ) ;
F_28 ( & V_2 -> V_47 ) ;
F_31 ( V_2 , V_7 , ! ! V_51 ) ;
F_29 ( & V_2 -> V_47 ) ;
}
static int
F_33 ( struct V_44 * V_45 , unsigned V_46 , int V_51 )
{
struct V_1 * V_2 = F_27 ( V_45 ) ;
unsigned V_7 = F_8 ( V_46 ) ;
int V_20 ;
F_28 ( & V_2 -> V_47 ) ;
V_20 = F_31 ( V_2 , V_7 , V_51 ) ;
if ( V_20 == 0 ) {
V_20 = F_5 ( V_2 , V_48 , V_7 , false ) ;
}
F_29 ( & V_2 -> V_47 ) ;
return V_20 ;
}
static T_5 F_34 ( int V_53 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
int V_54 , V_55 , V_56 , V_29 , V_57 , V_58 , V_59 , V_60 ;
unsigned int V_61 ;
bool V_62 , V_63 , V_64 ,
V_65 , V_66 ;
F_28 ( & V_2 -> V_47 ) ;
if ( F_1 ( V_2 , V_67 , & V_56 ) < 0 ) {
F_29 ( & V_2 -> V_47 ) ;
return V_68 ;
}
if ( F_1 ( V_2 , V_69 , & V_54 ) < 0 ) {
F_29 ( & V_2 -> V_47 ) ;
return V_68 ;
}
if ( F_1 ( V_2 , V_70 , & V_55 ) < 0 ) {
F_29 ( & V_2 -> V_47 ) ;
return V_68 ;
}
if ( F_1 ( V_2 , V_71 , & V_60 ) < 0 ) {
F_29 ( & V_2 -> V_47 ) ;
return V_68 ;
}
if ( F_1 ( V_2 , V_49 , & V_57 ) < 0 ) {
F_29 ( & V_2 -> V_47 ) ;
return V_68 ;
}
V_58 = V_2 -> V_50 ;
V_2 -> V_50 = V_57 ;
F_29 ( & V_2 -> V_47 ) ;
if ( V_56 == 0 ) {
return V_68 ;
}
F_35 ( V_2 -> V_45 . V_72 ,
L_2 ,
V_54 , V_56 , V_58 , V_57 ) ;
for ( V_29 = 0 ; V_29 < V_2 -> V_45 . V_73 ; V_29 ++ ) {
V_62 = V_56 & F_8 ( V_29 ) ;
if ( V_29 < 8 && V_62 )
V_59 = 0x00FF ;
else if ( V_29 >= 8 && V_62 )
V_59 = 0xFF00 ;
else
V_59 = 0x00 ;
V_63 = ( V_59 &
( V_54 & F_8 ( V_29 ) ) ) !=
( V_59 & ( F_8 ( V_29 ) & V_58 ) ) ;
V_66 = F_8 ( V_29 ) & V_57 ;
V_64 = ( F_8 ( V_29 ) & V_58 ) !=
( F_8 ( V_29 ) & V_57 ) ;
V_65 = ( F_8 ( V_29 ) & V_55 ) &&
( ( F_8 ( V_29 ) & V_57 ) !=
( F_8 ( V_29 ) & V_60 ) ) ;
if ( ( ( V_64 || V_63 ) &&
( F_8 ( V_29 ) & V_2 -> V_74 ) && V_66 ) ||
( ( V_64 || V_63 ) &&
( F_8 ( V_29 ) & V_2 -> V_75 ) && ! V_66 ) ||
V_65 ) {
V_61 = F_36 ( V_2 -> V_45 . V_76 , V_29 ) ;
F_37 ( V_61 ) ;
}
}
return V_68 ;
}
static void F_38 ( struct V_77 * V_19 )
{
struct V_44 * V_78 = F_39 ( V_19 ) ;
struct V_1 * V_2 = F_27 ( V_78 ) ;
unsigned int V_79 = V_19 -> V_80 ;
F_7 ( V_2 , V_81 , V_79 , false ) ;
}
static void F_40 ( struct V_77 * V_19 )
{
struct V_44 * V_78 = F_39 ( V_19 ) ;
struct V_1 * V_2 = F_27 ( V_78 ) ;
unsigned int V_79 = V_19 -> V_80 ;
F_7 ( V_2 , V_81 , V_79 , true ) ;
}
static int F_41 ( struct V_77 * V_19 , unsigned int type )
{
struct V_44 * V_78 = F_39 ( V_19 ) ;
struct V_1 * V_2 = F_27 ( V_78 ) ;
unsigned int V_79 = V_19 -> V_80 ;
int V_20 = 0 ;
if ( ( type & V_82 ) == V_82 ) {
F_7 ( V_2 , V_70 , V_79 , false ) ;
V_2 -> V_74 |= F_8 ( V_79 ) ;
V_2 -> V_75 |= F_8 ( V_79 ) ;
} else if ( type & V_83 ) {
F_7 ( V_2 , V_70 , V_79 , false ) ;
V_2 -> V_74 |= F_8 ( V_79 ) ;
V_2 -> V_75 &= ~ F_8 ( V_79 ) ;
} else if ( type & V_84 ) {
F_7 ( V_2 , V_70 , V_79 , false ) ;
V_2 -> V_74 &= ~ F_8 ( V_79 ) ;
V_2 -> V_75 |= F_8 ( V_79 ) ;
} else if ( type & V_85 ) {
F_7 ( V_2 , V_70 , V_79 , true ) ;
F_7 ( V_2 , V_71 , V_79 , false ) ;
} else if ( type & V_86 ) {
F_7 ( V_2 , V_70 , V_79 , true ) ;
F_7 ( V_2 , V_71 , V_79 , true ) ;
} else
return - V_25 ;
return V_20 ;
}
static void F_42 ( struct V_77 * V_19 )
{
struct V_44 * V_78 = F_39 ( V_19 ) ;
struct V_1 * V_2 = F_27 ( V_78 ) ;
F_28 ( & V_2 -> V_47 ) ;
F_43 ( V_2 -> V_5 , true ) ;
}
static void F_44 ( struct V_77 * V_19 )
{
struct V_44 * V_78 = F_39 ( V_19 ) ;
struct V_1 * V_2 = F_27 ( V_78 ) ;
F_43 ( V_2 -> V_5 , false ) ;
F_45 ( V_2 -> V_5 ) ;
F_29 ( & V_2 -> V_47 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = & V_2 -> V_45 ;
int V_87 ;
unsigned long V_88 = V_89 | V_90 ;
if ( V_2 -> V_91 )
V_88 |= V_92 ;
else
V_88 |= V_93 ;
V_87 = F_47 ( V_45 -> V_72 , V_2 -> V_53 , NULL ,
F_34 ,
V_88 , F_48 ( V_45 -> V_72 ) , V_2 ) ;
if ( V_87 != 0 ) {
F_15 ( V_45 -> V_72 , L_3 ,
V_2 -> V_53 , V_87 ) ;
return V_87 ;
}
V_87 = F_49 ( V_45 ,
& V_94 ,
0 ,
V_95 ,
V_96 ) ;
if ( V_87 ) {
F_15 ( V_45 -> V_72 ,
L_4 , V_87 ) ;
return V_87 ;
}
F_50 ( V_45 ,
& V_94 ,
V_2 -> V_53 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_97 [ V_98 ] ;
int V_87 = 0 , V_29 ;
for ( V_29 = 0 ; V_29 < V_98 ; V_29 ++ ) {
V_87 = F_1 ( V_2 , V_29 , & V_97 [ V_29 ] ) ;
if ( V_87 )
goto V_99;
}
F_52 ( V_2 -> V_5 , true ) ;
for ( V_29 = 0 ; V_29 < V_98 ; V_29 ++ ) {
int V_100 ;
V_87 = F_1 ( V_2 , V_29 , & V_100 ) ;
if ( V_87 )
goto V_99;
if ( V_100 != V_97 [ V_29 ] ) {
F_15 ( V_2 -> V_24 , L_5 ,
V_29 , V_100 , V_97 [ V_29 ] ) ;
F_3 ( V_2 , V_29 , V_97 [ V_29 ] ) ;
}
}
V_99:
if ( V_87 )
F_15 ( V_2 -> V_24 , L_6 , V_29 , V_87 ) ;
F_52 ( V_2 -> V_5 , false ) ;
return V_87 ;
}
static void F_53 ( struct V_101 * V_102 , struct V_44 * V_45 )
{
struct V_1 * V_2 ;
char V_103 ;
int V_37 ;
unsigned V_7 ;
int V_104 , V_57 , V_105 ;
V_2 = F_27 ( V_45 ) ;
V_103 = '0' + ( ( V_2 -> V_39 >> 1 ) & 0x7 ) ;
F_28 ( & V_2 -> V_47 ) ;
V_37 = F_51 ( V_2 ) ;
if ( V_37 ) {
F_54 ( V_102 , L_7 ) ;
goto V_106;
}
V_37 = F_1 ( V_2 , V_48 , & V_104 ) ;
if ( V_37 ) {
F_54 ( V_102 , L_7 ) ;
goto V_106;
}
V_37 = F_1 ( V_2 , V_49 , & V_57 ) ;
if ( V_37 ) {
F_54 ( V_102 , L_7 ) ;
goto V_106;
}
V_37 = F_1 ( V_2 , V_23 , & V_105 ) ;
if ( V_37 ) {
F_54 ( V_102 , L_7 ) ;
goto V_106;
}
for ( V_37 = 0 , V_7 = F_8 ( 0 ) ; V_37 < V_45 -> V_73 ; V_37 ++ , V_7 <<= 1 ) {
const char * V_107 ;
V_107 = F_55 ( V_45 , V_37 ) ;
if ( ! V_107 )
continue;
F_54 ( V_102 , L_8 ,
V_45 -> V_108 + V_37 , V_103 , V_37 , V_107 ,
( V_104 & V_7 ) ? L_9 : L_10 ,
( V_57 & V_7 ) ? L_11 : L_12 ,
( V_105 & V_7 ) ? L_13 : L_14 ) ;
F_56 ( V_102 , L_15 ) ;
}
V_106:
F_29 ( & V_2 -> V_47 ) ;
}
static int F_57 ( struct V_1 * V_2 , struct V_109 * V_24 ,
void * V_19 , unsigned V_39 , unsigned type ,
unsigned int V_108 , int V_110 )
{
int V_20 , V_21 ;
bool V_111 = false ;
F_58 ( & V_2 -> V_47 ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_91 = false ;
V_2 -> V_45 . V_112 = F_26 ;
V_2 -> V_45 . V_113 = F_30 ;
V_2 -> V_45 . V_114 = F_33 ;
V_2 -> V_45 . V_115 = F_32 ;
V_2 -> V_45 . V_116 = F_53 ;
#ifdef F_59
V_2 -> V_45 . V_117 = 2 ;
V_2 -> V_45 . V_118 = V_24 -> V_118 ;
#endif
switch ( type ) {
#ifdef F_60
case V_119 :
V_2 -> V_5 = F_61 ( V_24 , & V_120 , V_2 ,
& V_121 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_45 . V_73 = 8 ;
V_2 -> V_45 . V_107 = L_16 ;
break;
case V_122 :
V_2 -> V_5 = F_61 ( V_24 , & V_120 , V_2 ,
& V_123 ) ;
V_2 -> V_6 = 1 ;
V_2 -> V_45 . V_73 = 16 ;
V_2 -> V_45 . V_107 = L_17 ;
break;
case V_124 :
V_2 -> V_5 = F_61 ( V_24 , & V_120 , V_2 ,
& V_123 ) ;
V_2 -> V_6 = 1 ;
V_2 -> V_45 . V_73 = 16 ;
V_2 -> V_45 . V_107 = L_18 ;
break;
#endif
#if F_62 ( V_125 )
case V_126 :
V_2 -> V_5 = F_63 ( V_19 , & V_121 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_45 . V_73 = 8 ;
V_2 -> V_45 . V_107 = L_19 ;
break;
case V_127 :
V_2 -> V_5 = F_63 ( V_19 , & V_123 ) ;
V_2 -> V_6 = 1 ;
V_2 -> V_45 . V_73 = 16 ;
V_2 -> V_45 . V_107 = L_20 ;
break;
#endif
default:
F_15 ( V_24 , L_21 , type ) ;
return - V_25 ;
}
if ( F_64 ( V_2 -> V_5 ) )
return F_65 ( V_2 -> V_5 ) ;
V_2 -> V_45 . V_108 = V_108 ;
V_2 -> V_45 . V_128 = true ;
V_2 -> V_45 . V_72 = V_24 ;
V_2 -> V_45 . V_129 = V_130 ;
V_21 = F_1 ( V_2 , V_131 , & V_20 ) ;
if ( V_21 < 0 )
goto V_132;
V_2 -> V_133 =
F_66 ( V_24 , L_22 ) ;
if ( V_2 -> V_53 && V_2 -> V_133 ) {
V_2 -> V_91 =
F_66 ( V_24 ,
L_23 ) ;
V_111 = F_66 ( V_24 , L_24 ) ;
}
if ( ( V_20 & V_134 ) || ! ( V_20 & V_135 ) || V_111 ||
V_2 -> V_91 ) {
V_20 &= ~ ( V_134 | ( V_134 << 8 ) ) ;
V_20 |= V_135 | ( V_135 << 8 ) ;
if ( V_2 -> V_91 )
V_20 |= V_136 | ( V_136 << 8 ) ;
else
V_20 &= ~ ( V_136 | ( V_136 << 8 ) ) ;
if ( V_111 )
V_20 |= V_137 | ( V_137 << 8 ) ;
if ( type == V_124 )
V_20 |= V_138 | ( V_138 << 8 ) ;
V_21 = F_3 ( V_2 , V_131 , V_20 ) ;
if ( V_21 < 0 )
goto V_132;
}
V_21 = F_67 ( V_24 , & V_2 -> V_45 , V_2 ) ;
if ( V_21 < 0 )
goto V_132;
if ( V_2 -> V_53 && V_2 -> V_133 ) {
V_21 = F_46 ( V_2 ) ;
if ( V_21 )
goto V_132;
}
V_2 -> V_139 . V_140 = L_25 ;
V_2 -> V_139 . V_141 = & V_142 ;
V_2 -> V_139 . V_143 = & V_144 ;
V_2 -> V_139 . V_145 = V_2 -> V_45 . V_73 ;
if ( V_2 -> V_139 . V_145 == 8 )
V_2 -> V_139 . V_13 = V_146 ;
else if ( V_2 -> V_139 . V_145 == 16 )
V_2 -> V_139 . V_13 = V_147 ;
V_2 -> V_139 . V_129 = V_130 ;
V_2 -> V_11 = F_68 ( V_24 , & V_2 -> V_139 , V_2 ) ;
if ( F_64 ( V_2 -> V_11 ) ) {
V_21 = F_65 ( V_2 -> V_11 ) ;
goto V_132;
}
V_132:
if ( V_21 < 0 )
F_35 ( V_24 , L_26 , V_39 , V_21 ) ;
return V_21 ;
}
static int F_69 ( struct V_148 * V_149 ,
const struct V_150 * V_151 )
{
struct V_152 * V_153 , V_154 ;
struct V_1 * V_2 ;
int V_20 ;
V_153 = F_70 ( & V_149 -> V_24 ) ;
if ( ! V_153 ) {
V_153 = & V_154 ;
V_153 -> V_108 = - 1 ;
}
V_2 = F_71 ( & V_149 -> V_24 , sizeof( * V_2 ) , V_155 ) ;
if ( ! V_2 )
return - V_156 ;
V_2 -> V_53 = V_149 -> V_53 ;
V_20 = F_57 ( V_2 , & V_149 -> V_24 , V_149 , V_149 -> V_39 ,
V_151 -> V_157 , V_153 -> V_108 , 0 ) ;
if ( V_20 )
return V_20 ;
F_72 ( V_149 , V_2 ) ;
return 0 ;
}
static int T_6 F_73 ( void )
{
return F_74 ( & V_158 ) ;
}
static void F_75 ( void )
{
F_76 ( & V_158 ) ;
}
static int T_6 F_73 ( void ) { return 0 ; }
static void F_75 ( void ) { }
static int F_77 ( struct V_32 * V_33 )
{
struct V_152 * V_153 , V_154 ;
unsigned V_39 ;
int V_159 = 0 ;
struct V_160 * V_19 ;
int V_20 , type ;
unsigned V_73 = 0 ;
const struct V_161 * V_162 ;
V_162 = F_78 ( F_79 ( V_163 ) , & V_33 -> V_24 ) ;
if ( V_162 )
type = ( int ) ( V_164 ) V_162 -> V_19 ;
else
type = F_80 ( V_33 ) -> V_157 ;
V_153 = F_70 ( & V_33 -> V_24 ) ;
if ( ! V_153 ) {
V_153 = & V_154 ;
V_153 -> V_108 = - 1 ;
V_20 = F_81 ( & V_33 -> V_24 ,
L_27 , & V_153 -> V_165 ) ;
if ( V_20 ) {
V_20 = F_81 ( & V_33 -> V_24 ,
L_28 ,
& V_153 -> V_165 ) ;
if ( V_20 ) {
F_15 ( & V_33 -> V_24 , L_29 ) ;
return - V_166 ;
}
}
}
if ( ! V_153 -> V_165 || V_153 -> V_165 > 0xff ) {
F_15 ( & V_33 -> V_24 , L_30 ) ;
return - V_166 ;
}
for ( V_39 = 0 ; V_39 < V_167 ; V_39 ++ ) {
if ( V_153 -> V_165 & F_8 ( V_39 ) )
V_159 ++ ;
}
if ( ! V_159 )
return - V_166 ;
V_19 = F_71 ( & V_33 -> V_24 ,
sizeof( * V_19 ) + V_159 * sizeof( struct V_1 ) ,
V_155 ) ;
if ( ! V_19 )
return - V_156 ;
F_82 ( V_33 , V_19 ) ;
for ( V_39 = 0 ; V_39 < V_167 ; V_39 ++ ) {
if ( ! ( V_153 -> V_165 & F_8 ( V_39 ) ) )
continue;
V_159 -- ;
V_19 -> V_2 [ V_39 ] = & V_19 -> V_45 [ V_159 ] ;
V_19 -> V_2 [ V_39 ] -> V_53 = V_33 -> V_53 ;
V_20 = F_57 ( V_19 -> V_2 [ V_39 ] , & V_33 -> V_24 , V_33 ,
0x40 | ( V_39 << 1 ) , type ,
V_153 -> V_108 , V_39 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_153 -> V_108 != - 1 )
V_153 -> V_108 += V_19 -> V_2 [ V_39 ] -> V_45 . V_73 ;
V_73 += V_19 -> V_2 [ V_39 ] -> V_45 . V_73 ;
}
V_19 -> V_73 = V_73 ;
return 0 ;
}
static int T_6 F_83 ( void )
{
return F_84 ( & V_168 ) ;
}
static void F_85 ( void )
{
F_86 ( & V_168 ) ;
}
static int T_6 F_83 ( void ) { return 0 ; }
static void F_85 ( void ) { }
static int T_6 F_87 ( void )
{
int V_21 ;
V_21 = F_83 () ;
if ( V_21 )
goto V_169;
V_21 = F_73 () ;
if ( V_21 )
goto V_170;
return 0 ;
V_170:
F_85 () ;
V_169:
return V_21 ;
}
static void T_7 F_88 ( void )
{
F_85 () ;
F_75 () ;
}
