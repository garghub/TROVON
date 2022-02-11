static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 -> V_3 [ 0 ] ;
if ( V_2 -> V_5 -> V_6 & V_7 )
return - 1 ;
else {
switch ( V_3 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
return 0 ;
default:
return - 1 ;
}
}
}
static int F_2 ( struct V_14 * V_15 ,
unsigned int V_16 , T_2 * V_17 )
{
if ( V_16 > V_18 )
return - V_19 ;
* V_17 = F_3 ( V_15 -> V_5 -> V_20 . V_21 + ( V_16 * 4 ) ) ;
return 0 ;
}
static int F_4 ( struct V_14 * V_15 ,
unsigned int V_16 , T_2 V_17 )
{
if ( V_16 > V_18 )
return - V_19 ;
F_5 ( V_17 , V_15 -> V_5 -> V_20 . V_21 + ( V_16 * 4 ) ) ;
return 0 ;
}
static void F_6 ( struct V_22 * V_5 , const struct V_23 * V_24 )
{
struct V_25 * V_20 = & V_5 -> V_20 ;
unsigned int V_26 = V_24 -> V_6 & V_27 ;
if ( V_24 -> V_28 != V_5 -> V_29 ) {
F_7 ( V_24 -> V_28 , V_20 -> V_30 ) ;
V_5 -> V_29 = V_24 -> V_28 ;
F_8 ( V_5 ) ;
}
if ( V_26 && ( V_24 -> V_6 & V_31 ) ) {
F_9 ( V_24 -> V_32 | ( ( ( V_33 ) V_24 -> V_34 ) << 8 ) ,
V_20 -> V_35 ) ;
F_9 ( V_24 -> V_36 | ( ( ( V_33 ) V_24 -> V_37 ) << 8 ) ,
V_20 -> V_38 ) ;
F_9 ( V_24 -> V_39 | ( ( ( V_33 ) V_24 -> V_40 ) << 8 ) ,
V_20 -> V_41 ) ;
F_9 ( V_24 -> V_42 | ( ( ( V_33 ) V_24 -> V_43 ) << 8 ) ,
V_20 -> V_44 ) ;
F_9 ( V_24 -> V_45 | ( ( ( V_33 ) V_24 -> V_46 ) << 8 ) ,
V_20 -> V_47 ) ;
} else if ( V_26 ) {
F_9 ( V_24 -> V_32 , V_20 -> V_35 ) ;
F_9 ( V_24 -> V_36 , V_20 -> V_38 ) ;
F_9 ( V_24 -> V_39 , V_20 -> V_41 ) ;
F_9 ( V_24 -> V_42 , V_20 -> V_44 ) ;
F_9 ( V_24 -> V_45 , V_20 -> V_47 ) ;
}
if ( V_24 -> V_6 & V_48 )
F_7 ( V_24 -> V_49 , V_20 -> V_50 ) ;
F_8 ( V_5 ) ;
}
static void F_10 ( struct V_22 * V_5 , struct V_23 * V_24 )
{
struct V_25 * V_20 = & V_5 -> V_20 ;
V_33 V_36 , V_39 , V_42 , V_45 , V_32 ;
V_24 -> V_51 = F_11 ( V_5 ) ;
V_24 -> V_49 = F_12 ( V_20 -> V_50 ) ;
V_32 = F_12 ( V_20 -> V_52 ) ;
V_36 = F_12 ( V_20 -> V_38 ) ;
V_39 = F_12 ( V_20 -> V_41 ) ;
V_42 = F_12 ( V_20 -> V_44 ) ;
V_45 = F_12 ( V_20 -> V_47 ) ;
V_24 -> V_32 = V_32 ;
V_24 -> V_36 = V_36 ;
V_24 -> V_39 = V_39 ;
V_24 -> V_42 = V_42 ;
V_24 -> V_45 = V_45 ;
if ( V_24 -> V_6 & V_31 ) {
V_24 -> V_34 = V_32 >> 8 ;
V_24 -> V_37 = V_36 >> 8 ;
V_24 -> V_40 = V_39 >> 8 ;
V_24 -> V_43 = V_42 >> 8 ;
V_24 -> V_46 = V_45 >> 8 ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_22 * V_5 = V_2 -> V_5 ;
unsigned int V_53 = ( V_2 -> V_24 . V_6 & V_54 ) ;
T_1 V_55 ;
void T_3 * V_56 = V_5 -> V_20 . V_57 ;
F_14 () ;
F_5 ( V_5 -> V_58 , V_56 + V_59 ) ;
V_55 = F_15 ( V_56 + V_60 ) ;
V_55 &= ~ ( V_61 | V_62 ) ;
if ( ! V_53 )
V_55 |= V_61 ;
F_7 ( V_55 , V_56 + V_60 ) ;
if ( V_2 -> V_24 . V_63 != V_64 )
V_5 -> V_65 -> V_66 ( V_5 , & V_2 -> V_24 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_22 * V_5 = V_2 -> V_5 ;
void T_3 * V_56 = V_5 -> V_20 . V_57 ;
T_1 V_55 ;
V_55 = F_15 ( V_56 + V_60 ) ;
F_7 ( V_55 | V_62 , V_56 + V_60 ) ;
if ( V_2 -> V_24 . V_63 == V_64 )
V_5 -> V_65 -> V_66 ( V_5 , & V_2 -> V_24 ) ;
}
static T_1 F_11 ( struct V_22 * V_5 )
{
return F_3 ( V_5 -> V_20 . V_67 ) ;
}
static int F_17 ( struct V_68 * V_69 , char * V_70 , char * * V_71 ,
T_4 V_72 , int V_73 , int V_74 )
{
struct V_22 * V_5 ;
struct V_75 * V_76 ;
int V_77 , V_78 ;
V_5 = F_18 ( V_69 ) ;
if ( V_5 == NULL )
return 0 ;
V_76 = F_19 ( F_20 ( V_5 -> V_79 -> V_80 ) ) ;
if ( V_76 == NULL )
return 0 ;
V_78 = ( V_5 == V_5 -> V_79 -> V_81 [ 0 ] ) ? 0 : 1 ;
for ( V_76 = V_76 -> V_82 ; V_76 != NULL ; V_76 = V_76 -> V_83 ) {
const T_2 * V_84 = F_21 ( V_76 , L_1 , NULL ) ;
if ( ! V_84 )
continue;
if ( V_78 == * V_84 )
break;
}
if ( V_76 == NULL )
return 0 ;
V_77 = sprintf ( V_70 , L_2 , V_76 -> V_85 ) ;
return V_77 ;
}
static void F_22 ( struct V_25 * V_86 , void T_3 * V_87 )
{
V_86 -> V_88 = V_87 + V_89 ;
V_86 -> V_90 = V_87 + V_91 ;
V_86 -> V_35 =
V_86 -> V_52 = V_87 + V_92 ;
V_86 -> V_38 = V_87 + V_93 ;
V_86 -> V_41 = V_87 + V_94 ;
V_86 -> V_44 = V_87 + V_95 ;
V_86 -> V_47 = V_87 + V_96 ;
V_86 -> V_50 = V_87 + V_97 ;
V_86 -> V_98 =
V_86 -> V_67 = V_87 + V_99 ;
V_86 -> V_100 =
V_86 -> V_30 = V_87 + V_101 ;
V_86 -> V_57 = V_87 + V_102 ;
V_86 -> V_21 = V_87 + V_103 ;
}
static int F_23 ( struct V_104 * V_105 , const struct V_106 * V_107 )
{
const struct V_108 * V_109 [] =
{ & V_110 [ V_107 -> V_111 ] , NULL } ;
struct V_112 * V_79 ;
void T_3 * V_113 ;
int V_114 , V_115 , V_116 , V_117 ;
F_24 ( & V_105 -> V_80 , V_118 ) ;
V_114 = 4 ;
if ( V_109 [ 0 ] -> V_6 & V_119 )
V_114 = 8 ;
V_79 = F_25 ( & V_105 -> V_80 , V_109 , V_114 ) ;
if ( ! V_79 )
return - V_120 ;
V_117 = 5 ;
if ( V_109 [ 0 ] -> V_6 & V_121 )
V_117 = 3 ;
V_116 = F_26 ( V_105 ) ;
if ( V_116 )
return V_116 ;
if ( F_27 ( V_105 , V_117 ) == 0 ) {
F_28 ( V_105 ) ;
return - V_122 ;
}
V_116 = F_29 ( V_105 , 1 << V_117 , V_123 ) ;
if ( V_116 == - V_124 )
F_28 ( V_105 ) ;
if ( V_116 )
return V_116 ;
V_79 -> V_125 = F_30 ( V_105 ) ;
V_113 = V_79 -> V_125 [ V_117 ] ;
for ( V_115 = 0 ; V_115 < V_79 -> V_114 ; V_115 ++ ) {
struct V_22 * V_5 = V_79 -> V_81 [ V_115 ] ;
unsigned int V_72 = V_115 * V_126 ;
F_22 ( & V_5 -> V_20 , V_113 + V_72 ) ;
F_31 ( V_5 , 5 , - 1 , L_3 ) ;
F_31 ( V_5 , 5 , V_72 , L_4 ) ;
}
V_116 = F_32 ( V_105 , V_127 ) ;
if ( V_116 )
return V_116 ;
V_116 = F_33 ( V_105 , V_127 ) ;
if ( V_116 )
return V_116 ;
F_5 ( F_3 ( V_113 + V_128 ) & ~ 0x00040000 ,
V_113 + V_128 ) ;
F_5 ( 0xffffffff , V_113 + V_129 ) ;
F_5 ( 0x0 , V_113 + V_130 ) ;
F_34 ( V_105 ) ;
return F_35 ( V_79 , V_105 -> V_131 , V_132 ,
V_133 , & V_134 ) ;
}
