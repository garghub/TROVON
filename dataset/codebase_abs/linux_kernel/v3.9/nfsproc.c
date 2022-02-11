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
T_1 V_12 ;
F_6 ( L_2 ,
F_7 ( & V_3 -> V_8 ) ,
V_3 -> V_16 . V_17 , ( long ) V_3 -> V_16 . V_18 ) ;
F_8 ( & V_4 -> V_8 , & V_3 -> V_8 ) ;
V_12 = F_11 ( V_2 , & V_4 -> V_8 , & V_3 -> V_16 , 0 , ( V_19 ) 0 ) ;
return F_2 ( V_12 , V_4 ) ;
}
static T_1
F_12 ( struct V_1 * V_2 , struct V_20 * V_3 ,
struct V_10 * V_4 )
{
T_1 V_12 ;
F_6 ( L_3 ,
F_7 ( & V_3 -> V_8 ) , V_3 -> V_21 , V_3 -> V_22 ) ;
F_13 ( & V_4 -> V_8 , V_23 ) ;
V_12 = F_14 ( V_2 , & V_3 -> V_8 , V_3 -> V_22 , V_3 -> V_21 ,
& V_4 -> V_8 ) ;
F_15 ( & V_3 -> V_8 ) ;
return F_4 ( V_12 , V_4 ) ;
}
static T_1
F_16 ( struct V_1 * V_2 , struct V_24 * V_3 ,
struct V_25 * V_4 )
{
T_1 V_12 ;
F_6 ( L_4 , F_7 ( & V_3 -> V_8 ) ) ;
V_4 -> V_21 = V_26 ;
V_12 = F_17 ( V_2 , & V_3 -> V_8 , V_3 -> V_27 , & V_4 -> V_21 ) ;
F_15 ( & V_3 -> V_8 ) ;
return V_12 ;
}
static T_1
F_18 ( struct V_1 * V_2 , struct V_28 * V_3 ,
struct V_29 * V_4 )
{
T_1 V_12 ;
F_6 ( L_5 ,
F_7 ( & V_3 -> V_8 ) ,
V_3 -> V_30 , V_3 -> V_31 ) ;
if ( V_32 < V_3 -> V_30 ) {
char V_33 [ V_34 ] ;
F_19 ( V_35
L_6 ,
F_20 ( V_2 , V_33 , sizeof( V_33 ) ) ,
V_3 -> V_30 ) ;
V_3 -> V_30 = V_32 ;
}
F_21 ( V_2 , ( 19 << 2 ) + V_3 -> V_30 + 4 ) ;
V_4 -> V_30 = V_3 -> V_30 ;
V_12 = F_22 ( V_2 , F_8 ( & V_4 -> V_8 , & V_3 -> V_8 ) ,
V_3 -> V_31 ,
V_2 -> V_36 , V_3 -> V_37 ,
& V_4 -> V_30 ) ;
if ( V_12 ) return V_12 ;
return F_3 ( & V_4 -> V_8 , & V_4 -> V_9 ) ;
}
static T_1
F_23 ( struct V_1 * V_2 , struct V_38 * V_3 ,
struct V_7 * V_4 )
{
T_1 V_12 ;
int V_39 = 1 ;
unsigned long V_40 = V_3 -> V_21 ;
F_6 ( L_7 ,
F_7 ( & V_3 -> V_8 ) ,
V_3 -> V_21 , V_3 -> V_31 ) ;
V_12 = F_24 ( V_2 , F_8 ( & V_4 -> V_8 , & V_3 -> V_8 ) , NULL ,
V_3 -> V_31 ,
V_2 -> V_36 , V_3 -> V_37 ,
& V_40 ,
& V_39 ) ;
return F_2 ( V_12 , V_4 ) ;
}
static T_1
F_25 ( struct V_1 * V_2 , struct V_41 * V_3 ,
struct V_10 * V_4 )
{
T_2 * V_42 = & V_3 -> V_8 ;
T_2 * V_43 = & V_4 -> V_8 ;
struct V_44 * V_45 = & V_3 -> V_16 ;
struct V_46 * V_46 ;
struct V_47 * V_48 ;
int type , V_49 ;
T_1 V_12 ;
int V_50 ;
T_3 V_51 = 0 , V_52 = F_26 ( V_45 -> V_18 ) ;
F_6 ( L_8 ,
F_7 ( V_42 ) , V_3 -> V_21 , V_3 -> V_22 ) ;
V_12 = F_9 ( V_2 , V_42 , V_53 , V_54 ) ;
if ( V_12 )
goto V_55;
V_12 = V_56 ;
if ( ! V_3 -> V_21 )
goto V_55;
V_12 = V_57 ;
if ( F_27 ( V_3 -> V_22 , V_3 -> V_21 ) )
goto V_55;
V_50 = F_28 ( V_42 ) ;
if ( V_50 ) {
V_12 = F_29 ( V_50 ) ;
goto V_55;
}
F_30 ( V_42 , V_58 ) ;
V_48 = F_31 ( V_3 -> V_22 , V_42 -> V_59 , V_3 -> V_21 ) ;
if ( F_32 ( V_48 ) ) {
V_12 = F_29 ( F_33 ( V_48 ) ) ;
goto V_60;
}
F_13 ( V_43 , V_23 ) ;
V_12 = F_34 ( V_43 , V_42 -> V_61 , V_48 , V_42 ) ;
if ( ! V_12 && ! V_48 -> V_62 )
V_12 = V_63 ;
F_35 ( V_48 ) ;
if ( V_12 ) {
if ( V_12 != V_63 )
goto V_60;
V_12 = V_56 ;
if ( ! V_43 -> V_59 ) {
F_19 ( V_64
L_9 ) ;
goto V_60;
}
}
V_46 = V_43 -> V_59 -> V_62 ;
if ( V_45 -> V_17 & V_65 ) {
type = V_45 -> V_66 & V_67 ;
V_49 = V_45 -> V_66 & ~ V_67 ;
if ( ! type ) {
if ( V_46 ) {
type = V_46 -> V_68 & V_67 ;
switch( type ) {
case V_69 :
case V_70 :
V_51 = V_46 -> V_71 ;
V_45 -> V_17 |= V_72 ;
case V_73 :
V_12 = F_36 ( V_2 ,
V_43 -> V_61 ,
V_43 -> V_59 ,
V_74 | V_75 ) ;
if ( V_12 && V_12 != V_76 )
goto V_60;
}
} else
type = V_77 ;
}
} else if ( V_46 ) {
type = V_46 -> V_68 & V_67 ;
V_49 = V_46 -> V_68 & ~ V_67 ;
} else {
type = V_77 ;
V_49 = 0 ;
}
V_45 -> V_17 |= V_65 ;
V_45 -> V_66 = V_49 ;
if ( type != V_77 ) {
if ( type != V_70 && type != V_69 ) {
V_51 = 0 ;
} else if ( type == V_69 && ! ( V_45 -> V_17 & V_72 ) ) {
type = V_73 ;
} else {
if ( ! V_51 )
V_51 = V_52 ;
}
V_45 -> V_17 &= ~ V_72 ;
V_12 = V_57 ;
if ( V_46 && type != ( V_46 -> V_68 & V_67 ) )
goto V_60;
}
V_12 = 0 ;
if ( ! V_46 ) {
V_12 = F_37 ( V_2 , V_42 , V_3 -> V_22 , V_3 -> V_21 ,
V_45 , type , V_51 , V_43 ) ;
} else if ( type == V_77 ) {
F_6 ( L_10 ,
V_3 -> V_22 , V_45 -> V_17 , ( long ) V_45 -> V_18 ) ;
V_45 -> V_17 &= V_72 ;
if ( V_45 -> V_17 )
V_12 = F_11 ( V_2 , V_43 , V_45 , 0 , ( V_19 ) 0 ) ;
}
V_60:
F_38 ( V_42 ) ;
F_39 ( V_42 ) ;
V_55:
F_15 ( V_42 ) ;
return F_4 ( V_12 , V_4 ) ;
}
static T_1
F_40 ( struct V_1 * V_2 , struct V_20 * V_3 ,
void * V_4 )
{
T_1 V_12 ;
F_6 ( L_11 , F_7 ( & V_3 -> V_8 ) ,
V_3 -> V_21 , V_3 -> V_22 ) ;
V_12 = F_41 ( V_2 , & V_3 -> V_8 , - V_53 , V_3 -> V_22 , V_3 -> V_21 ) ;
F_15 ( & V_3 -> V_8 ) ;
return V_12 ;
}
static T_1
F_42 ( struct V_1 * V_2 , struct V_78 * V_3 ,
void * V_4 )
{
T_1 V_12 ;
F_6 ( L_12 ,
F_7 ( & V_3 -> V_79 ) , V_3 -> V_80 , V_3 -> V_81 ) ;
F_6 ( L_13 ,
F_7 ( & V_3 -> V_82 ) , V_3 -> V_83 , V_3 -> V_84 ) ;
V_12 = F_43 ( V_2 , & V_3 -> V_79 , V_3 -> V_81 , V_3 -> V_80 ,
& V_3 -> V_82 , V_3 -> V_84 , V_3 -> V_83 ) ;
F_15 ( & V_3 -> V_79 ) ;
F_15 ( & V_3 -> V_82 ) ;
return V_12 ;
}
static T_1
F_44 ( struct V_1 * V_2 , struct V_85 * V_3 ,
void * V_4 )
{
T_1 V_12 ;
F_6 ( L_14 ,
F_7 ( & V_3 -> V_79 ) ) ;
F_6 ( L_15 ,
F_7 ( & V_3 -> V_82 ) ,
V_3 -> V_83 ,
V_3 -> V_84 ) ;
V_12 = F_45 ( V_2 , & V_3 -> V_82 , V_3 -> V_84 , V_3 -> V_83 ,
& V_3 -> V_79 ) ;
F_15 ( & V_3 -> V_79 ) ;
F_15 ( & V_3 -> V_82 ) ;
return V_12 ;
}
static T_1
F_46 ( struct V_1 * V_2 , struct V_86 * V_3 ,
void * V_4 )
{
struct T_2 V_87 ;
T_1 V_12 ;
F_6 ( L_16 ,
F_7 ( & V_3 -> V_79 ) , V_3 -> V_80 , V_3 -> V_81 ,
V_3 -> V_83 , V_3 -> V_84 ) ;
F_13 ( & V_87 , V_23 ) ;
V_12 = F_47 ( V_2 , & V_3 -> V_79 , V_3 -> V_81 , V_3 -> V_80 ,
V_3 -> V_84 , V_3 -> V_83 ,
& V_87 , & V_3 -> V_16 ) ;
F_15 ( & V_3 -> V_79 ) ;
F_15 ( & V_87 ) ;
return V_12 ;
}
static T_1
F_48 ( struct V_1 * V_2 , struct V_41 * V_3 ,
struct V_10 * V_4 )
{
T_1 V_12 ;
F_6 ( L_17 , F_7 ( & V_3 -> V_8 ) , V_3 -> V_21 , V_3 -> V_22 ) ;
if ( V_4 -> V_8 . V_59 ) {
F_19 ( V_64
L_18 ) ;
}
V_3 -> V_16 . V_17 &= ~ V_72 ;
F_13 ( & V_4 -> V_8 , V_23 ) ;
V_12 = F_37 ( V_2 , & V_3 -> V_8 , V_3 -> V_22 , V_3 -> V_21 ,
& V_3 -> V_16 , V_53 , 0 , & V_4 -> V_8 ) ;
F_15 ( & V_3 -> V_8 ) ;
return F_4 ( V_12 , V_4 ) ;
}
static T_1
F_49 ( struct V_1 * V_2 , struct V_20 * V_3 ,
void * V_4 )
{
T_1 V_12 ;
F_6 ( L_19 , F_7 ( & V_3 -> V_8 ) , V_3 -> V_21 , V_3 -> V_22 ) ;
V_12 = F_41 ( V_2 , & V_3 -> V_8 , V_53 , V_3 -> V_22 , V_3 -> V_21 ) ;
F_15 ( & V_3 -> V_8 ) ;
return V_12 ;
}
static T_1
F_50 ( struct V_1 * V_2 , struct V_88 * V_3 ,
struct V_89 * V_4 )
{
int V_30 ;
T_1 V_12 ;
T_4 V_31 ;
F_6 ( L_20 ,
F_7 ( & V_3 -> V_8 ) ,
V_3 -> V_30 , V_3 -> V_90 ) ;
V_30 = ( V_3 -> V_30 >> 2 ) - 2 ;
V_30 -= 2 ;
if ( V_30 < 0 )
V_30 = 0 ;
V_4 -> V_27 = V_3 -> V_27 ;
V_4 -> V_31 = NULL ;
V_4 -> V_91 = V_30 ;
V_4 -> V_92 . V_6 = V_5 ;
V_31 = V_3 -> V_90 ;
V_12 = F_51 ( V_2 , & V_3 -> V_8 , & V_31 ,
& V_4 -> V_92 , V_93 ) ;
V_4 -> V_30 = V_4 -> V_27 - V_3 -> V_27 ;
if ( V_4 -> V_31 )
* V_4 -> V_31 = F_52 ( V_31 ) ;
F_15 ( & V_3 -> V_8 ) ;
return V_12 ;
}
static T_1
F_53 ( struct V_1 * V_2 , struct V_11 * V_3 ,
struct V_94 * V_4 )
{
T_1 V_12 ;
F_6 ( L_21 , F_7 ( & V_3 -> V_8 ) ) ;
V_12 = F_54 ( V_2 , & V_3 -> V_8 , & V_4 -> V_95 ,
V_14 ) ;
F_15 ( & V_3 -> V_8 ) ;
return V_12 ;
}
T_1
F_29 ( int V_96 )
{
static struct {
T_1 V_12 ;
int V_97 ;
} V_98 [] = {
{ V_5 , 0 } ,
{ V_99 , - V_100 } ,
{ V_63 , - V_101 } ,
{ V_102 , - V_103 } ,
{ V_104 , - V_105 } ,
{ V_56 , - V_106 } ,
{ V_57 , - V_107 } ,
{ V_108 , - V_109 } ,
{ V_110 , - V_111 } ,
{ V_112 , - V_113 } ,
{ V_114 , - V_115 } ,
{ V_116 , - V_117 } ,
{ V_118 , - V_119 } ,
{ V_120 , - V_121 } ,
{ V_122 , - V_123 } ,
{ V_76 , - V_124 } ,
{ V_110 , - V_111 } ,
{ V_125 , - V_126 } ,
{ V_127 , - V_128 } ,
#ifdef F_55
{ V_129 , - F_55 } ,
#endif
{ V_130 , - V_131 } ,
{ V_132 , - V_133 } ,
{ V_132 , - V_134 } ,
{ V_132 , - V_135 } ,
{ V_132 , - V_136 } ,
{ V_132 , - V_137 } ,
{ V_102 , - V_138 } ,
{ V_139 , - V_140 } ,
{ V_141 , - V_142 } ,
{ V_143 , - V_144 } ,
} ;
int V_145 ;
for ( V_145 = 0 ; V_145 < F_56 ( V_98 ) ; V_145 ++ ) {
if ( V_98 [ V_145 ] . V_97 == V_96 )
return V_98 [ V_145 ] . V_12 ;
}
F_19 ( V_146 L_22 , V_96 ) ;
return V_102 ;
}
