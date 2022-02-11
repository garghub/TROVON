static T_1
F_1 ( struct V_1 * V_2 , void * V_3 , void * V_4 )
{
return V_5 ;
}
static T_1
F_2 ( T_1 V_6 , struct V_7 * V_4 )
{
if ( V_6 ) return V_6 ;
return F_3 ( F_4 ( V_4 -> V_8 . V_9 -> V_10 . V_11 ,
V_4 -> V_8 . V_12 ,
& V_4 -> V_13 ) ) ;
}
static T_1
F_5 ( T_1 V_6 , struct V_14 * V_4 )
{
if ( V_6 ) return V_6 ;
return F_3 ( F_4 ( V_4 -> V_8 . V_9 -> V_10 . V_11 ,
V_4 -> V_8 . V_12 ,
& V_4 -> V_13 ) ) ;
}
static T_1
F_6 ( struct V_1 * V_2 , struct V_15 * V_3 ,
struct V_7 * V_4 )
{
T_1 V_16 ;
F_7 ( L_1 , F_8 ( & V_3 -> V_8 ) ) ;
F_9 ( & V_4 -> V_8 , & V_3 -> V_8 ) ;
V_16 = F_10 ( V_2 , & V_4 -> V_8 , 0 ,
V_17 | V_18 ) ;
return F_2 ( V_16 , V_4 ) ;
}
static T_1
F_11 ( struct V_1 * V_2 , struct V_19 * V_3 ,
struct V_7 * V_4 )
{
T_1 V_16 ;
F_7 ( L_2 ,
F_8 ( & V_3 -> V_8 ) ,
V_3 -> V_20 . V_21 , ( long ) V_3 -> V_20 . V_22 ) ;
F_9 ( & V_4 -> V_8 , & V_3 -> V_8 ) ;
V_16 = F_12 ( V_2 , & V_4 -> V_8 , & V_3 -> V_20 , 0 , ( V_23 ) 0 ) ;
return F_2 ( V_16 , V_4 ) ;
}
static T_1
F_13 ( struct V_1 * V_2 , struct V_24 * V_3 ,
struct V_14 * V_4 )
{
T_1 V_16 ;
F_7 ( L_3 ,
F_8 ( & V_3 -> V_8 ) , V_3 -> V_25 , V_3 -> V_26 ) ;
F_14 ( & V_4 -> V_8 , V_27 ) ;
V_16 = F_15 ( V_2 , & V_3 -> V_8 , V_3 -> V_26 , V_3 -> V_25 ,
& V_4 -> V_8 ) ;
F_16 ( & V_3 -> V_8 ) ;
return F_5 ( V_16 , V_4 ) ;
}
static T_1
F_17 ( struct V_1 * V_2 , struct V_28 * V_3 ,
struct V_29 * V_4 )
{
T_1 V_16 ;
F_7 ( L_4 , F_8 ( & V_3 -> V_8 ) ) ;
V_4 -> V_25 = V_30 ;
V_16 = F_18 ( V_2 , & V_3 -> V_8 , V_3 -> V_31 , & V_4 -> V_25 ) ;
F_16 ( & V_3 -> V_8 ) ;
return V_16 ;
}
static T_1
F_19 ( struct V_1 * V_2 , struct V_32 * V_3 ,
struct V_33 * V_4 )
{
T_1 V_16 ;
F_7 ( L_5 ,
F_8 ( & V_3 -> V_8 ) ,
V_3 -> V_34 , V_3 -> V_35 ) ;
if ( V_36 < V_3 -> V_34 ) {
char V_37 [ V_38 ] ;
F_20 ( V_39
L_6 ,
F_21 ( V_2 , V_37 , sizeof( V_37 ) ) ,
V_3 -> V_34 ) ;
V_3 -> V_34 = V_36 ;
}
F_22 ( V_2 , ( 19 << 2 ) + V_3 -> V_34 + 4 ) ;
V_4 -> V_34 = V_3 -> V_34 ;
V_16 = F_23 ( V_2 , F_9 ( & V_4 -> V_8 , & V_3 -> V_8 ) ,
V_3 -> V_35 ,
V_2 -> V_40 , V_3 -> V_41 ,
& V_4 -> V_34 ) ;
if ( V_16 ) return V_16 ;
return F_3 ( F_4 ( V_4 -> V_8 . V_9 -> V_10 . V_11 ,
V_4 -> V_8 . V_12 ,
& V_4 -> V_13 ) ) ;
}
static T_1
F_24 ( struct V_1 * V_2 , struct V_42 * V_3 ,
struct V_7 * V_4 )
{
T_1 V_16 ;
int V_43 = 1 ;
unsigned long V_44 = V_3 -> V_25 ;
F_7 ( L_7 ,
F_8 ( & V_3 -> V_8 ) ,
V_3 -> V_25 , V_3 -> V_35 ) ;
V_16 = F_25 ( V_2 , F_9 ( & V_4 -> V_8 , & V_3 -> V_8 ) , NULL ,
V_3 -> V_35 ,
V_2 -> V_40 , V_3 -> V_41 ,
& V_44 ,
& V_43 ) ;
return F_2 ( V_16 , V_4 ) ;
}
static T_1
F_26 ( struct V_1 * V_2 , struct V_45 * V_3 ,
struct V_14 * V_4 )
{
T_2 * V_46 = & V_3 -> V_8 ;
T_2 * V_47 = & V_4 -> V_8 ;
struct V_48 * V_49 = & V_3 -> V_20 ;
struct V_50 * V_50 ;
struct V_51 * V_52 ;
int type , V_53 ;
T_1 V_16 ;
int V_54 ;
T_3 V_55 = 0 , V_56 = F_27 ( V_49 -> V_22 ) ;
F_7 ( L_8 ,
F_8 ( V_46 ) , V_3 -> V_25 , V_3 -> V_26 ) ;
V_16 = F_10 ( V_2 , V_46 , V_57 , V_58 ) ;
if ( V_16 )
goto V_59;
V_16 = V_60 ;
if ( ! V_3 -> V_25 )
goto V_59;
V_16 = V_61 ;
if ( F_28 ( V_3 -> V_26 , V_3 -> V_25 ) )
goto V_59;
V_54 = F_29 ( V_46 ) ;
if ( V_54 ) {
V_16 = F_3 ( V_54 ) ;
goto V_59;
}
F_30 ( V_46 , V_62 ) ;
V_52 = F_31 ( V_3 -> V_26 , V_46 -> V_12 , V_3 -> V_25 ) ;
if ( F_32 ( V_52 ) ) {
V_16 = F_3 ( F_33 ( V_52 ) ) ;
goto V_63;
}
F_14 ( V_47 , V_27 ) ;
V_16 = F_34 ( V_47 , V_46 -> V_9 , V_52 , V_46 ) ;
if ( ! V_16 && ! V_52 -> V_64 )
V_16 = V_65 ;
F_35 ( V_52 ) ;
if ( V_16 ) {
if ( V_16 != V_65 )
goto V_63;
V_16 = V_60 ;
if ( ! V_47 -> V_12 ) {
F_20 ( V_66
L_9 ) ;
goto V_63;
}
}
V_50 = V_47 -> V_12 -> V_64 ;
if ( V_49 -> V_21 & V_67 ) {
type = V_49 -> V_68 & V_69 ;
V_53 = V_49 -> V_68 & ~ V_69 ;
if ( ! type ) {
if ( V_50 ) {
type = V_50 -> V_70 & V_69 ;
switch( type ) {
case V_71 :
case V_72 :
V_55 = V_50 -> V_73 ;
V_49 -> V_21 |= V_74 ;
case V_75 :
V_16 = F_36 ( V_2 ,
V_47 -> V_9 ,
V_47 -> V_12 ,
V_76 | V_77 ) ;
if ( V_16 && V_16 != V_78 )
goto V_63;
}
} else
type = V_79 ;
}
} else if ( V_50 ) {
type = V_50 -> V_70 & V_69 ;
V_53 = V_50 -> V_70 & ~ V_69 ;
} else {
type = V_79 ;
V_53 = 0 ;
}
V_49 -> V_21 |= V_67 ;
V_49 -> V_68 = V_53 ;
if ( type != V_79 ) {
if ( type != V_72 && type != V_71 ) {
V_55 = 0 ;
} else if ( type == V_71 && ! ( V_49 -> V_21 & V_74 ) ) {
type = V_75 ;
} else {
if ( ! V_55 )
V_55 = V_56 ;
}
V_49 -> V_21 &= ~ V_74 ;
V_16 = V_61 ;
if ( V_50 && type != ( V_50 -> V_70 & V_69 ) )
goto V_63;
}
V_16 = 0 ;
if ( ! V_50 ) {
V_16 = F_37 ( V_2 , V_46 , V_3 -> V_26 , V_3 -> V_25 ,
V_49 , type , V_55 , V_47 ) ;
} else if ( type == V_79 ) {
F_7 ( L_10 ,
V_3 -> V_26 , V_49 -> V_21 , ( long ) V_49 -> V_22 ) ;
V_49 -> V_21 &= V_74 ;
if ( V_49 -> V_21 )
V_16 = F_12 ( V_2 , V_47 , V_49 , 0 , ( V_23 ) 0 ) ;
}
V_63:
F_38 ( V_46 ) ;
F_39 ( V_46 ) ;
V_59:
F_16 ( V_46 ) ;
return F_5 ( V_16 , V_4 ) ;
}
static T_1
F_40 ( struct V_1 * V_2 , struct V_24 * V_3 ,
void * V_4 )
{
T_1 V_16 ;
F_7 ( L_11 , F_8 ( & V_3 -> V_8 ) ,
V_3 -> V_25 , V_3 -> V_26 ) ;
V_16 = F_41 ( V_2 , & V_3 -> V_8 , - V_57 , V_3 -> V_26 , V_3 -> V_25 ) ;
F_16 ( & V_3 -> V_8 ) ;
return V_16 ;
}
static T_1
F_42 ( struct V_1 * V_2 , struct V_80 * V_3 ,
void * V_4 )
{
T_1 V_16 ;
F_7 ( L_12 ,
F_8 ( & V_3 -> V_81 ) , V_3 -> V_82 , V_3 -> V_83 ) ;
F_7 ( L_13 ,
F_8 ( & V_3 -> V_84 ) , V_3 -> V_85 , V_3 -> V_86 ) ;
V_16 = F_43 ( V_2 , & V_3 -> V_81 , V_3 -> V_83 , V_3 -> V_82 ,
& V_3 -> V_84 , V_3 -> V_86 , V_3 -> V_85 ) ;
F_16 ( & V_3 -> V_81 ) ;
F_16 ( & V_3 -> V_84 ) ;
return V_16 ;
}
static T_1
F_44 ( struct V_1 * V_2 , struct V_87 * V_3 ,
void * V_4 )
{
T_1 V_16 ;
F_7 ( L_14 ,
F_8 ( & V_3 -> V_81 ) ) ;
F_7 ( L_15 ,
F_8 ( & V_3 -> V_84 ) ,
V_3 -> V_85 ,
V_3 -> V_86 ) ;
V_16 = F_45 ( V_2 , & V_3 -> V_84 , V_3 -> V_86 , V_3 -> V_85 ,
& V_3 -> V_81 ) ;
F_16 ( & V_3 -> V_81 ) ;
F_16 ( & V_3 -> V_84 ) ;
return V_16 ;
}
static T_1
F_46 ( struct V_1 * V_2 , struct V_88 * V_3 ,
void * V_4 )
{
struct T_2 V_89 ;
T_1 V_16 ;
F_7 ( L_16 ,
F_8 ( & V_3 -> V_81 ) , V_3 -> V_82 , V_3 -> V_83 ,
V_3 -> V_85 , V_3 -> V_86 ) ;
F_14 ( & V_89 , V_27 ) ;
V_16 = F_47 ( V_2 , & V_3 -> V_81 , V_3 -> V_83 , V_3 -> V_82 ,
V_3 -> V_86 , V_3 -> V_85 ,
& V_89 , & V_3 -> V_20 ) ;
F_16 ( & V_3 -> V_81 ) ;
F_16 ( & V_89 ) ;
return V_16 ;
}
static T_1
F_48 ( struct V_1 * V_2 , struct V_45 * V_3 ,
struct V_14 * V_4 )
{
T_1 V_16 ;
F_7 ( L_17 , F_8 ( & V_3 -> V_8 ) , V_3 -> V_25 , V_3 -> V_26 ) ;
if ( V_4 -> V_8 . V_12 ) {
F_20 ( V_66
L_18 ) ;
}
V_3 -> V_20 . V_21 &= ~ V_74 ;
F_14 ( & V_4 -> V_8 , V_27 ) ;
V_16 = F_37 ( V_2 , & V_3 -> V_8 , V_3 -> V_26 , V_3 -> V_25 ,
& V_3 -> V_20 , V_57 , 0 , & V_4 -> V_8 ) ;
F_16 ( & V_3 -> V_8 ) ;
return F_5 ( V_16 , V_4 ) ;
}
static T_1
F_49 ( struct V_1 * V_2 , struct V_24 * V_3 ,
void * V_4 )
{
T_1 V_16 ;
F_7 ( L_19 , F_8 ( & V_3 -> V_8 ) , V_3 -> V_25 , V_3 -> V_26 ) ;
V_16 = F_41 ( V_2 , & V_3 -> V_8 , V_57 , V_3 -> V_26 , V_3 -> V_25 ) ;
F_16 ( & V_3 -> V_8 ) ;
return V_16 ;
}
static T_1
F_50 ( struct V_1 * V_2 , struct V_90 * V_3 ,
struct V_91 * V_4 )
{
int V_34 ;
T_1 V_16 ;
T_4 V_35 ;
F_7 ( L_20 ,
F_8 ( & V_3 -> V_8 ) ,
V_3 -> V_34 , V_3 -> V_92 ) ;
V_34 = ( V_3 -> V_34 >> 2 ) - 2 ;
V_34 -= 2 ;
if ( V_34 < 0 )
V_34 = 0 ;
V_4 -> V_31 = V_3 -> V_31 ;
V_4 -> V_35 = NULL ;
V_4 -> V_93 = V_34 ;
V_4 -> V_94 . V_6 = V_5 ;
V_35 = V_3 -> V_92 ;
V_16 = F_51 ( V_2 , & V_3 -> V_8 , & V_35 ,
& V_4 -> V_94 , V_95 ) ;
V_4 -> V_34 = V_4 -> V_31 - V_3 -> V_31 ;
if ( V_4 -> V_35 )
* V_4 -> V_35 = F_52 ( V_35 ) ;
F_16 ( & V_3 -> V_8 ) ;
return V_16 ;
}
static T_1
F_53 ( struct V_1 * V_2 , struct V_15 * V_3 ,
struct V_96 * V_4 )
{
T_1 V_16 ;
F_7 ( L_21 , F_8 ( & V_3 -> V_8 ) ) ;
V_16 = F_54 ( V_2 , & V_3 -> V_8 , & V_4 -> V_97 ,
V_18 ) ;
F_16 ( & V_3 -> V_8 ) ;
return V_16 ;
}
T_1
F_3 ( int V_98 )
{
static struct {
T_1 V_16 ;
int V_99 ;
} V_100 [] = {
{ V_5 , 0 } ,
{ V_101 , - V_102 } ,
{ V_65 , - V_103 } ,
{ V_104 , - V_105 } ,
{ V_106 , - V_107 } ,
{ V_60 , - V_108 } ,
{ V_61 , - V_109 } ,
{ V_110 , - V_111 } ,
{ V_112 , - V_113 } ,
{ V_114 , - V_115 } ,
{ V_116 , - V_117 } ,
{ V_118 , - V_119 } ,
{ V_120 , - V_121 } ,
{ V_122 , - V_123 } ,
{ V_124 , - V_125 } ,
{ V_78 , - V_126 } ,
{ V_112 , - V_113 } ,
{ V_127 , - V_128 } ,
{ V_129 , - V_130 } ,
#ifdef F_55
{ V_131 , - F_55 } ,
#endif
{ V_132 , - V_133 } ,
{ V_134 , - V_135 } ,
{ V_134 , - V_136 } ,
{ V_134 , - V_137 } ,
{ V_134 , - V_138 } ,
{ V_134 , - V_139 } ,
{ V_104 , - V_140 } ,
{ V_141 , - V_142 } ,
{ V_143 , - V_144 } ,
{ V_145 , - V_146 } ,
} ;
int V_147 ;
for ( V_147 = 0 ; V_147 < F_56 ( V_100 ) ; V_147 ++ ) {
if ( V_100 [ V_147 ] . V_99 == V_98 )
return V_100 [ V_147 ] . V_16 ;
}
F_20 ( V_148 L_22 , V_98 ) ;
return V_104 ;
}
