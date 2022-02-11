static T_1
F_1 ( struct V_1 * V_2 , void * V_3 , void * V_4 )
{
return V_5 ;
}
static T_1
F_2 ( T_1 V_6 , struct V_7 * V_4 )
{
if ( V_6 ) return V_6 ;
return F_3 ( & V_4 -> V_8 , & V_4 -> V_9 ) ;
}
static T_1
F_4 ( T_1 V_6 , struct V_10 * V_4 )
{
if ( V_6 ) return V_6 ;
return F_3 ( & V_4 -> V_8 , & V_4 -> V_9 ) ;
}
static T_1
F_5 ( struct V_1 * V_2 , struct V_11 * V_3 ,
struct V_7 * V_4 )
{
T_1 V_12 ;
F_6 ( L_1 , F_7 ( & V_3 -> V_8 ) ) ;
F_8 ( & V_4 -> V_8 , & V_3 -> V_8 ) ;
V_12 = F_9 ( V_2 , & V_4 -> V_8 , 0 ,
V_13 | V_14 ) ;
return F_2 ( V_12 , V_4 ) ;
}
static T_1
F_10 ( struct V_1 * V_2 , struct V_15 * V_3 ,
struct V_7 * V_4 )
{
struct V_16 * V_17 = & V_3 -> V_18 ;
struct V_19 * V_20 ;
T_1 V_12 ;
F_6 ( L_2 ,
F_7 ( & V_3 -> V_8 ) ,
V_3 -> V_18 . V_21 , ( long ) V_3 -> V_18 . V_22 ) ;
V_20 = F_8 ( & V_4 -> V_8 , & V_3 -> V_8 ) ;
#define F_11 (ATTR_ATIME_SET | ATTR_MTIME_SET)
#define F_12 (30*60)
if ( ( V_17 -> V_21 & F_11 ) == F_11 &&
V_17 -> V_23 . V_24 == V_17 -> V_25 . V_24 ) {
T_2 V_26 = V_17 -> V_25 . V_24 - F_13 () ;
V_12 = F_9 ( V_2 , V_20 , 0 , V_13 ) ;
if ( V_12 )
goto V_27;
if ( V_26 < 0 )
V_26 = - V_26 ;
if ( V_26 < F_12 &&
F_14 ( V_20 -> V_28 , V_17 ) != 0 ) {
V_17 -> V_21 &= ~ F_11 ;
}
}
V_12 = F_15 ( V_2 , V_20 , V_17 , 0 , ( T_2 ) 0 ) ;
V_27:
return F_2 ( V_12 , V_4 ) ;
}
static T_1
F_16 ( struct V_1 * V_2 , struct V_29 * V_3 ,
struct V_10 * V_4 )
{
T_1 V_12 ;
F_6 ( L_3 ,
F_7 ( & V_3 -> V_8 ) , V_3 -> V_30 , V_3 -> V_31 ) ;
F_17 ( & V_4 -> V_8 , V_32 ) ;
V_12 = F_18 ( V_2 , & V_3 -> V_8 , V_3 -> V_31 , V_3 -> V_30 ,
& V_4 -> V_8 ) ;
F_19 ( & V_3 -> V_8 ) ;
return F_4 ( V_12 , V_4 ) ;
}
static T_1
F_20 ( struct V_1 * V_2 , struct V_33 * V_3 ,
struct V_34 * V_4 )
{
T_1 V_12 ;
F_6 ( L_4 , F_7 ( & V_3 -> V_8 ) ) ;
V_4 -> V_30 = V_35 ;
V_12 = F_21 ( V_2 , & V_3 -> V_8 , V_3 -> V_36 , & V_4 -> V_30 ) ;
F_19 ( & V_3 -> V_8 ) ;
return V_12 ;
}
static T_1
F_22 ( struct V_1 * V_2 , struct V_37 * V_3 ,
struct V_38 * V_4 )
{
T_1 V_12 ;
F_6 ( L_5 ,
F_7 ( & V_3 -> V_8 ) ,
V_3 -> V_39 , V_3 -> V_40 ) ;
if ( V_41 < V_3 -> V_39 ) {
char V_42 [ V_43 ] ;
F_23 ( V_44
L_6 ,
F_24 ( V_2 , V_42 , sizeof( V_42 ) ) ,
V_3 -> V_39 ) ;
V_3 -> V_39 = V_41 ;
}
F_25 ( V_2 , ( 19 << 2 ) + V_3 -> V_39 + 4 ) ;
V_4 -> V_39 = V_3 -> V_39 ;
V_12 = F_26 ( V_2 , F_8 ( & V_4 -> V_8 , & V_3 -> V_8 ) ,
V_3 -> V_40 ,
V_2 -> V_45 , V_3 -> V_46 ,
& V_4 -> V_39 ) ;
if ( V_12 ) return V_12 ;
return F_3 ( & V_4 -> V_8 , & V_4 -> V_9 ) ;
}
static T_1
F_27 ( struct V_1 * V_2 , struct V_47 * V_3 ,
struct V_7 * V_4 )
{
T_1 V_12 ;
unsigned long V_48 = V_3 -> V_30 ;
F_6 ( L_7 ,
F_7 ( & V_3 -> V_8 ) ,
V_3 -> V_30 , V_3 -> V_40 ) ;
V_12 = F_28 ( V_2 , F_8 ( & V_4 -> V_8 , & V_3 -> V_8 ) , V_3 -> V_40 ,
V_2 -> V_45 , V_3 -> V_46 , & V_48 , V_49 ) ;
return F_2 ( V_12 , V_4 ) ;
}
static T_1
F_29 ( struct V_1 * V_2 , struct V_50 * V_3 ,
struct V_10 * V_4 )
{
V_19 * V_51 = & V_3 -> V_8 ;
V_19 * V_52 = & V_4 -> V_8 ;
struct V_16 * V_53 = & V_3 -> V_18 ;
struct V_54 * V_54 ;
struct V_55 * V_56 ;
int type , V_57 ;
T_1 V_12 ;
int V_58 ;
T_3 V_59 = 0 , V_60 = F_30 ( V_53 -> V_22 ) ;
F_6 ( L_8 ,
F_7 ( V_51 ) , V_3 -> V_30 , V_3 -> V_31 ) ;
V_12 = F_9 ( V_2 , V_51 , V_61 , V_62 ) ;
if ( V_12 )
goto V_27;
V_12 = V_63 ;
if ( F_31 ( V_3 -> V_31 , V_3 -> V_30 ) )
goto V_27;
V_58 = F_32 ( V_51 ) ;
if ( V_58 ) {
V_12 = F_33 ( V_58 ) ;
goto V_27;
}
F_34 ( V_51 , V_64 ) ;
V_56 = F_35 ( V_3 -> V_31 , V_51 -> V_28 , V_3 -> V_30 ) ;
if ( F_36 ( V_56 ) ) {
V_12 = F_33 ( F_37 ( V_56 ) ) ;
goto V_65;
}
F_17 ( V_52 , V_32 ) ;
V_12 = F_38 ( V_52 , V_51 -> V_66 , V_56 , V_51 ) ;
if ( ! V_12 && F_39 ( V_56 ) )
V_12 = V_67 ;
F_40 ( V_56 ) ;
if ( V_12 ) {
if ( V_12 != V_67 )
goto V_65;
V_12 = V_68 ;
if ( ! V_52 -> V_28 ) {
F_23 ( V_69
L_9 ) ;
goto V_65;
}
}
V_54 = F_41 ( V_52 -> V_28 ) ;
if ( V_53 -> V_21 & V_70 ) {
type = V_53 -> V_71 & V_72 ;
V_57 = V_53 -> V_71 & ~ V_72 ;
if ( ! type ) {
if ( V_54 ) {
type = V_54 -> V_73 & V_72 ;
switch( type ) {
case V_74 :
case V_75 :
V_59 = V_54 -> V_76 ;
V_53 -> V_21 |= V_77 ;
case V_78 :
V_12 = F_42 ( V_2 ,
V_52 -> V_66 ,
V_52 -> V_28 ,
V_79 | V_80 ) ;
if ( V_12 && V_12 != V_81 )
goto V_65;
}
} else
type = V_82 ;
}
} else if ( V_54 ) {
type = V_54 -> V_73 & V_72 ;
V_57 = V_54 -> V_73 & ~ V_72 ;
} else {
type = V_82 ;
V_57 = 0 ;
}
V_53 -> V_21 |= V_70 ;
V_53 -> V_71 = V_57 ;
if ( type != V_82 ) {
if ( type != V_75 && type != V_74 ) {
V_59 = 0 ;
} else if ( type == V_74 && ! ( V_53 -> V_21 & V_77 ) ) {
type = V_78 ;
} else {
if ( ! V_59 )
V_59 = V_60 ;
}
V_53 -> V_21 &= ~ V_77 ;
V_12 = V_63 ;
if ( V_54 && type != ( V_54 -> V_73 & V_72 ) )
goto V_65;
}
V_12 = 0 ;
if ( ! V_54 ) {
V_12 = F_43 ( V_2 , V_51 , V_3 -> V_31 ,
V_3 -> V_30 , V_53 , type , V_59 , V_52 ) ;
} else if ( type == V_82 ) {
F_6 ( L_10 ,
V_3 -> V_31 , V_53 -> V_21 , ( long ) V_53 -> V_22 ) ;
V_53 -> V_21 &= V_77 ;
if ( V_53 -> V_21 )
V_12 = F_15 ( V_2 , V_52 , V_53 , 0 , ( T_2 ) 0 ) ;
}
V_65:
F_44 ( V_51 ) ;
F_45 ( V_51 ) ;
V_27:
F_19 ( V_51 ) ;
return F_4 ( V_12 , V_4 ) ;
}
static T_1
F_46 ( struct V_1 * V_2 , struct V_29 * V_3 ,
void * V_4 )
{
T_1 V_12 ;
F_6 ( L_11 , F_7 ( & V_3 -> V_8 ) ,
V_3 -> V_30 , V_3 -> V_31 ) ;
V_12 = F_47 ( V_2 , & V_3 -> V_8 , - V_61 , V_3 -> V_31 , V_3 -> V_30 ) ;
F_19 ( & V_3 -> V_8 ) ;
return V_12 ;
}
static T_1
F_48 ( struct V_1 * V_2 , struct V_83 * V_3 ,
void * V_4 )
{
T_1 V_12 ;
F_6 ( L_12 ,
F_7 ( & V_3 -> V_84 ) , V_3 -> V_85 , V_3 -> V_86 ) ;
F_6 ( L_13 ,
F_7 ( & V_3 -> V_87 ) , V_3 -> V_88 , V_3 -> V_89 ) ;
V_12 = F_49 ( V_2 , & V_3 -> V_84 , V_3 -> V_86 , V_3 -> V_85 ,
& V_3 -> V_87 , V_3 -> V_89 , V_3 -> V_88 ) ;
F_19 ( & V_3 -> V_84 ) ;
F_19 ( & V_3 -> V_87 ) ;
return V_12 ;
}
static T_1
F_50 ( struct V_1 * V_2 , struct V_90 * V_3 ,
void * V_4 )
{
T_1 V_12 ;
F_6 ( L_14 ,
F_7 ( & V_3 -> V_84 ) ) ;
F_6 ( L_15 ,
F_7 ( & V_3 -> V_87 ) ,
V_3 -> V_88 ,
V_3 -> V_89 ) ;
V_12 = F_51 ( V_2 , & V_3 -> V_87 , V_3 -> V_89 , V_3 -> V_88 ,
& V_3 -> V_84 ) ;
F_19 ( & V_3 -> V_84 ) ;
F_19 ( & V_3 -> V_87 ) ;
return V_12 ;
}
static T_1
F_52 ( struct V_1 * V_2 , struct V_91 * V_3 ,
void * V_4 )
{
struct V_19 V_92 ;
T_1 V_12 ;
F_6 ( L_16 ,
F_7 ( & V_3 -> V_84 ) , V_3 -> V_85 , V_3 -> V_86 ,
V_3 -> V_88 , V_3 -> V_89 ) ;
F_17 ( & V_92 , V_32 ) ;
V_3 -> V_89 [ V_3 -> V_88 ] = '\0' ;
V_12 = F_53 ( V_2 , & V_3 -> V_84 , V_3 -> V_86 , V_3 -> V_85 ,
V_3 -> V_89 , & V_92 ) ;
F_19 ( & V_3 -> V_84 ) ;
F_19 ( & V_92 ) ;
return V_12 ;
}
static T_1
F_54 ( struct V_1 * V_2 , struct V_50 * V_3 ,
struct V_10 * V_4 )
{
T_1 V_12 ;
F_6 ( L_17 , F_7 ( & V_3 -> V_8 ) , V_3 -> V_30 , V_3 -> V_31 ) ;
if ( V_4 -> V_8 . V_28 ) {
F_23 ( V_69
L_18 ) ;
}
V_3 -> V_18 . V_21 &= ~ V_77 ;
F_17 ( & V_4 -> V_8 , V_32 ) ;
V_12 = F_55 ( V_2 , & V_3 -> V_8 , V_3 -> V_31 , V_3 -> V_30 ,
& V_3 -> V_18 , V_61 , 0 , & V_4 -> V_8 ) ;
F_19 ( & V_3 -> V_8 ) ;
return F_4 ( V_12 , V_4 ) ;
}
static T_1
F_56 ( struct V_1 * V_2 , struct V_29 * V_3 ,
void * V_4 )
{
T_1 V_12 ;
F_6 ( L_19 , F_7 ( & V_3 -> V_8 ) , V_3 -> V_30 , V_3 -> V_31 ) ;
V_12 = F_47 ( V_2 , & V_3 -> V_8 , V_61 , V_3 -> V_31 , V_3 -> V_30 ) ;
F_19 ( & V_3 -> V_8 ) ;
return V_12 ;
}
static T_1
F_57 ( struct V_1 * V_2 , struct V_93 * V_3 ,
struct V_94 * V_4 )
{
int V_39 ;
T_1 V_12 ;
T_4 V_40 ;
F_6 ( L_20 ,
F_7 ( & V_3 -> V_8 ) ,
V_3 -> V_39 , V_3 -> V_95 ) ;
V_39 = ( V_3 -> V_39 >> 2 ) - 2 ;
V_39 -= 2 ;
if ( V_39 < 0 )
V_39 = 0 ;
V_4 -> V_36 = V_3 -> V_36 ;
V_4 -> V_40 = NULL ;
V_4 -> V_96 = V_39 ;
V_4 -> V_97 . V_6 = V_5 ;
V_40 = V_3 -> V_95 ;
V_12 = F_58 ( V_2 , & V_3 -> V_8 , & V_40 ,
& V_4 -> V_97 , V_98 ) ;
V_4 -> V_39 = V_4 -> V_36 - V_3 -> V_36 ;
if ( V_4 -> V_40 )
* V_4 -> V_40 = F_59 ( V_40 ) ;
F_19 ( & V_3 -> V_8 ) ;
return V_12 ;
}
static T_1
F_60 ( struct V_1 * V_2 , struct V_11 * V_3 ,
struct V_99 * V_4 )
{
T_1 V_12 ;
F_6 ( L_21 , F_7 ( & V_3 -> V_8 ) ) ;
V_12 = F_61 ( V_2 , & V_3 -> V_8 , & V_4 -> V_100 ,
V_14 ) ;
F_19 ( & V_3 -> V_8 ) ;
return V_12 ;
}
T_1
F_33 ( int V_101 )
{
static struct {
T_1 V_12 ;
int V_102 ;
} V_103 [] = {
{ V_5 , 0 } ,
{ V_104 , - V_105 } ,
{ V_67 , - V_106 } ,
{ V_107 , - V_108 } ,
{ V_109 , - V_110 } ,
{ V_111 , - V_112 } ,
{ V_68 , - V_113 } ,
{ V_63 , - V_114 } ,
{ V_115 , - V_116 } ,
{ V_117 , - V_118 } ,
{ V_119 , - V_120 } ,
{ V_121 , - V_122 } ,
{ V_123 , - V_124 } ,
{ V_125 , - V_126 } ,
{ V_111 , - V_127 } ,
{ V_128 , - V_129 } ,
{ V_81 , - V_130 } ,
{ V_117 , - V_118 } ,
{ V_131 , - V_132 } ,
{ V_133 , - V_134 } ,
#ifdef F_62
{ V_135 , - F_62 } ,
#endif
{ V_136 , - V_137 } ,
{ V_138 , - V_139 } ,
{ V_138 , - V_140 } ,
{ V_138 , - V_141 } ,
{ V_138 , - V_142 } ,
{ V_138 , - V_143 } ,
{ V_107 , - V_144 } ,
{ V_145 , - V_146 } ,
{ V_147 , - V_148 } ,
{ V_149 , - V_150 } ,
{ V_149 , - V_151 } ,
{ V_107 , - V_152 } ,
{ V_104 , - V_153 } ,
} ;
int V_154 ;
for ( V_154 = 0 ; V_154 < F_63 ( V_103 ) ; V_154 ++ ) {
if ( V_103 [ V_154 ] . V_102 == V_101 )
return V_103 [ V_154 ] . V_12 ;
}
F_64 ( 1 , L_22 , V_101 ) ;
return V_107 ;
}
