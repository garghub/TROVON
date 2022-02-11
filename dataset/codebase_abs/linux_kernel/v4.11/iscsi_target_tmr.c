T_1 F_1 (
struct V_1 * V_2 ,
unsigned char * V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 . V_9 ;
struct V_12 * V_13 = (struct V_12 * ) V_3 ;
V_4 = F_2 ( V_6 , V_13 -> V_14 ) ;
if ( ! V_4 ) {
F_3 ( L_1
L_2 , V_13 -> V_14 , V_6 -> V_15 ) ;
return ( F_4 ( F_5 ( V_13 -> V_16 ) , V_6 -> V_17 -> V_18 ) &&
F_6 ( F_5 ( V_13 -> V_16 ) , ( V_19 ) F_7 ( & V_6 -> V_17 -> V_20 ) ) ) ?
V_21 : V_22 ;
}
if ( V_4 -> V_23 != F_5 ( V_13 -> V_16 ) ) {
F_3 ( L_3
L_4 ,
V_13 -> V_16 , V_4 -> V_23 ) ;
return V_24 ;
}
V_10 -> V_25 = ( V_26 V_19 ) V_13 -> V_14 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_27 = F_5 ( V_13 -> V_28 ) ;
return V_21 ;
}
int F_8 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned char * V_3 )
{
struct V_29 * V_17 = V_6 -> V_17 ;
struct V_30 * V_31 = F_9 ( V_17 ) ;
if ( ! V_31 -> V_32 ) {
F_3 ( L_5
L_6 ,
V_17 -> V_33 -> V_34 -> V_35 ) ;
return - 1 ;
}
return 0 ;
}
int F_10 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned char * V_3 )
{
struct V_29 * V_17 = V_6 -> V_17 ;
struct V_30 * V_31 = F_9 ( V_17 ) ;
if ( ! V_31 -> V_36 ) {
F_3 ( L_7
L_6 ,
V_17 -> V_33 -> V_34 -> V_35 ) ;
return - 1 ;
}
return 0 ;
}
T_1 F_11 (
struct V_1 * V_2 ,
unsigned char * V_3 )
{
struct V_1 * V_4 = NULL ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_37 * V_38 = NULL ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 . V_9 ;
struct V_12 * V_13 = (struct V_12 * ) V_3 ;
T_2 V_39 , V_40 ;
F_12 ( L_8
L_9 ,
V_13 -> V_41 , V_13 -> V_14 , V_13 -> V_28 , V_6 -> V_15 ) ;
if ( V_6 -> V_17 -> V_42 -> V_43 != 2 ) {
F_3 ( L_10
L_11 ) ;
return V_44 ;
}
V_39 = F_13 ( V_6 -> V_17 , & V_4 , & V_38 , V_13 -> V_14 ) ;
if ( V_39 == - 2 ) {
F_3 ( L_12
L_13 , V_4 -> V_45 , V_38 -> V_15 ) ;
return V_46 ;
} else if ( V_39 == - 1 ) {
F_3 ( L_14
L_15 , V_13 -> V_14 ) ;
return V_22 ;
}
if ( V_38 -> V_47 !=
V_6 -> V_48 -> V_49 ) {
F_3 ( L_16
L_17
L_18 ) ;
return V_24 ;
}
if ( V_38 -> V_50 !=
V_6 -> V_48 -> V_51 ) {
F_3 ( L_16
L_19
L_18 ) ;
return V_24 ;
}
V_40 = F_14 ( & V_13 -> V_52 ) ;
if ( V_40 != V_4 -> V_11 . V_53 ) {
F_3 ( L_16
L_20 ,
V_40 , V_4 -> V_11 . V_53 ) ;
return V_24 ;
}
V_10 -> V_25 = ( V_26 V_19 ) V_13 -> V_14 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_27 = F_5 ( V_13 -> V_28 ) ;
V_8 -> V_54 = V_38 ;
V_8 -> V_55 = 1 ;
return V_21 ;
}
static void F_15 (
struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_29 * V_17 )
{
int V_39 ;
F_16 ( & V_38 -> V_56 ) ;
V_39 = F_17 ( V_2 , V_17 ) ;
F_18 ( & V_38 -> V_56 ) ;
if ( ! V_39 ) {
F_12 ( L_21
L_22 , V_38 -> V_15 , V_17 -> V_57 ) ;
F_19 ( V_38 , V_17 ) ;
}
}
static int F_20 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = V_8 -> V_4 ;
struct V_37 * V_38 ;
if ( ! V_2 -> V_38 ) {
F_3 ( L_23
L_24 , V_2 -> V_45 ) ;
return - 1 ;
}
V_38 = V_2 -> V_38 ;
V_2 -> V_58 = V_2 -> V_59 = 0 ;
F_15 ( V_2 , V_38 , V_6 -> V_17 ) ;
F_21 ( & V_6 -> V_60 ) ;
F_22 ( & V_2 -> V_61 , & V_6 -> V_62 ) ;
F_23 ( & V_6 -> V_60 ) ;
V_2 -> V_63 = V_64 ;
F_24 ( V_2 , V_6 , V_2 -> V_63 ) ;
return 0 ;
}
static int F_25 (
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
int V_65 = 0 ;
V_19 V_66 = 0 , V_67 = 0 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_11 * V_11 = & V_2 -> V_11 ;
if ( ! V_8 -> V_27 ) {
V_2 -> V_68 &= ~ V_69 ;
V_2 -> V_70 = 0 ;
} else {
V_2 -> V_68 |= V_69 ;
V_2 -> V_70 = ( V_8 -> V_27 - 1 ) ;
}
if ( V_2 -> V_68 & V_71 ) {
if ( ! ( V_2 -> V_11 . V_72 & V_73 ) ) {
F_12 ( L_25
L_26 ,
V_2 -> V_45 , V_2 -> V_11 . V_74 ) ;
F_26 ( V_11 ) ;
return 0 ;
}
V_2 -> V_63 = V_75 ;
F_24 ( V_2 , V_6 , V_2 -> V_63 ) ;
return 0 ;
}
if ( V_2 -> V_76 ) {
V_2 -> V_76 = 0 ;
V_67 = V_2 -> V_77 = V_2 -> V_78 ;
if ( ( V_6 -> V_17 -> V_42 -> V_79 - V_67 ) >=
V_2 -> V_11 . V_80 ) {
V_65 = 1 ;
V_66 = ( V_2 -> V_11 . V_80 - V_67 ) ;
} else
V_66 = ( V_6 -> V_17 -> V_42 -> V_79 - V_67 ) ;
F_21 ( & V_2 -> V_81 ) ;
if ( F_27 ( V_2 , V_67 , V_66 , 0 , 0 ) < 0 ) {
F_23 ( & V_2 -> V_81 ) ;
return - 1 ;
}
V_2 -> V_82 ++ ;
F_23 ( & V_2 -> V_81 ) ;
if ( V_65 )
return 0 ;
}
return V_6 -> V_83 -> V_84 ( V_6 , V_2 , true ) ;
}
static int F_28 (
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_85 * V_86 ;
struct V_11 * V_11 = & V_2 -> V_11 ;
if ( ! V_8 -> V_27 ) {
V_2 -> V_68 &= ~ V_69 ;
V_2 -> V_70 = 0 ;
} else {
V_2 -> V_68 |= V_69 ;
V_2 -> V_70 = ( V_8 -> V_27 - 1 ) ;
}
if ( ! ( V_2 -> V_11 . V_72 & V_73 ) ) {
F_12 ( L_27
L_28 , V_2 -> V_45 ,
V_2 -> V_11 . V_74 ) ;
F_29 ( V_11 ) ;
return 0 ;
}
if ( ! ( V_11 -> V_72 & V_87 ) ) {
F_3 ( L_29
L_30 , V_2 -> V_45 ,
V_2 -> V_11 . V_74 ) ;
return - 1 ;
}
V_86 = F_30 () ;
if ( ! V_86 )
return - 1 ;
V_86 -> V_88 = V_86 -> V_89 = V_8 -> V_27 ;
V_86 -> V_90 = 0 ;
V_86 -> V_91 = 1 ;
V_86 -> V_92 = V_93 ;
F_31 ( V_2 , V_86 ) ;
V_2 -> V_63 = V_94 ;
F_24 ( V_2 , V_6 , V_2 -> V_63 ) ;
return 0 ;
}
static int F_32 (
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
V_2 -> V_63 = V_75 ;
F_24 ( V_2 , V_6 , V_2 -> V_63 ) ;
return 0 ;
}
static int F_33 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = V_8 -> V_4 ;
struct V_37 * V_38 ;
if ( ! V_2 -> V_38 ) {
F_3 ( L_23
L_24 , V_2 -> V_45 ) ;
return - 1 ;
}
V_38 = V_2 -> V_38 ;
V_2 -> V_58 = V_2 -> V_59 = 0 ;
F_15 ( V_2 , V_38 , V_6 -> V_17 ) ;
F_21 ( & V_6 -> V_60 ) ;
F_22 ( & V_2 -> V_61 , & V_6 -> V_62 ) ;
F_23 ( & V_6 -> V_60 ) ;
if ( V_2 -> V_11 . V_95 & V_96 ) {
V_2 -> V_63 = V_75 ;
F_24 ( V_2 , V_6 , V_2 -> V_63 ) ;
return 0 ;
}
switch ( V_2 -> V_97 ) {
case V_98 :
return F_25 ( V_2 , V_8 ) ;
case V_99 :
return F_28 ( V_2 , V_8 ) ;
case V_100 :
return F_32 ( V_2 , V_8 ) ;
default:
F_3 ( L_31 ,
V_2 -> V_97 ) ;
return - 1 ;
}
return 0 ;
}
static int F_34 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 ;
int V_39 = 0 ;
if ( ! V_8 -> V_4 ) {
F_3 ( L_32 ) ;
return - 1 ;
}
V_2 = V_8 -> V_4 ;
V_2 -> V_6 = V_6 ;
switch ( V_2 -> V_101 ) {
case V_102 :
V_39 = F_20 ( V_8 , V_6 ) ;
break;
case V_103 :
V_39 = F_33 ( V_8 , V_6 ) ;
break;
default:
F_3 ( L_33
L_34 , V_2 -> V_101 ) ;
return - 1 ;
}
if ( V_39 != 0 )
return V_39 ;
F_12 ( L_35
L_36 , V_2 -> V_101 ,
V_2 -> V_45 , V_6 -> V_15 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 . V_9 ;
if ( V_8 -> V_55 &&
( V_10 -> V_104 == V_21 ) )
return F_34 ( V_8 , V_6 ) ;
return 0 ;
}
static int F_36 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
return 0 ;
}
static void F_37 (
struct V_1 * V_2 ,
struct V_5 * V_6 )
{
int V_105 , V_106 ;
struct V_107 * V_108 = NULL ;
struct V_109 * V_110 = NULL ;
if ( V_6 -> V_17 -> V_42 -> V_111 ) {
V_2 -> V_88 = 0 ;
if ( V_2 -> V_112 )
V_2 -> V_113 += ( V_2 -> V_114 -
V_2 -> V_115 ) ;
if ( V_6 -> V_17 -> V_42 -> V_116 ) {
V_2 -> V_78 -= ( V_2 -> V_112 ) ?
( V_2 -> V_114 -
V_2 -> V_115 ) :
V_2 -> V_114 ;
V_2 -> V_114 = 0 ;
return;
}
for ( V_105 = 0 ; V_105 < V_2 -> V_117 ; V_105 ++ ) {
V_108 = & V_2 -> V_118 [ V_105 ] ;
if ( V_108 -> V_119 != V_120 )
continue;
if ( ( V_108 -> V_67 >= V_2 -> V_115 ) &&
( ( V_108 -> V_67 + V_108 -> V_66 ) <=
V_2 -> V_121 ) ) {
V_2 -> V_114 -= V_108 -> V_66 ;
V_2 -> V_78 -= V_108 -> V_66 ;
V_108 -> V_119 = V_122 ;
}
}
} else {
for ( V_105 = 0 ; V_105 < V_2 -> V_123 ; V_105 ++ ) {
V_110 = & V_2 -> V_124 [ V_105 ] ;
if ( V_110 -> type != V_125 )
continue;
V_2 -> V_78 -=
( V_110 -> V_67 - V_110 -> V_126 ) ;
V_2 -> V_114 = 0 ;
V_110 -> V_88 = 0 ;
V_110 -> V_67 = V_110 -> V_126 ;
V_110 -> V_77 = 0 ;
V_110 -> V_119 = V_127 ;
if ( V_6 -> V_17 -> V_42 -> V_116 )
continue;
for ( V_106 = 0 ; V_106 < V_110 -> V_117 ; V_106 ++ ) {
V_108 = & V_2 -> V_118 [ V_106 + V_110 -> V_128 ] ;
if ( V_108 -> V_119 != V_120 )
continue;
V_108 -> V_119 = V_122 ;
}
}
}
}
static int F_38 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = V_8 -> V_4 ;
struct V_107 * V_108 = NULL ;
struct V_129 * V_130 = NULL , * V_131 ;
int V_132 = 1 , V_105 = 0 ;
if ( V_2 -> V_76 )
F_37 ( V_2 , V_6 ) ;
if ( ! V_8 -> V_27 )
goto V_133;
F_21 ( & V_2 -> V_81 ) ;
if ( F_39 ( & V_2 -> V_134 ) ) {
F_23 ( & V_2 -> V_81 ) ;
return - 1 ;
}
F_40 (r2t, &cmd->cmd_r2t_list, r2t_list) {
if ( V_130 -> V_135 >= V_8 -> V_27 )
continue;
if ( V_130 -> V_136 )
continue;
if ( V_130 -> V_137 )
continue;
if ( V_6 -> V_17 -> V_42 -> V_111 ) {
if ( ! V_132 ) {
V_2 -> V_113 -= V_130 -> V_138 ;
goto V_139;
}
if ( V_6 -> V_17 -> V_42 -> V_116 ) {
V_2 -> V_88 = 0 ;
V_2 -> V_113 -= ( V_130 -> V_138 -
V_2 -> V_77 ) ;
V_132 = 0 ;
goto V_139;
}
V_2 -> V_88 = 0 ;
V_2 -> V_113 -= V_130 -> V_138 ;
for ( V_105 = 0 ; V_105 < V_2 -> V_117 ; V_105 ++ ) {
V_108 = & V_2 -> V_118 [ V_105 ] ;
if ( V_108 -> V_119 != V_120 )
continue;
if ( ( V_108 -> V_67 >= V_130 -> V_67 ) &&
( V_108 -> V_67 < ( V_130 -> V_67 +
V_130 -> V_138 ) ) ) {
V_2 -> V_77 -= V_108 -> V_66 ;
V_2 -> V_78 -= V_108 -> V_66 ;
V_108 -> V_119 = V_122 ;
}
}
V_132 = 0 ;
} else {
struct V_109 * V_110 ;
V_110 = F_41 ( V_2 , V_130 -> V_67 ,
V_130 -> V_138 ) ;
if ( ! V_110 ) {
F_23 ( & V_2 -> V_81 ) ;
return - 1 ;
}
V_2 -> V_78 -=
( V_110 -> V_67 - V_110 -> V_126 ) ;
V_110 -> V_88 = 0 ;
V_110 -> V_67 = V_110 -> V_126 ;
V_110 -> V_77 = 0 ;
V_110 -> V_119 = V_127 ;
V_2 -> V_140 -- ;
if ( V_6 -> V_17 -> V_42 -> V_116 )
goto V_139;
for ( V_105 = 0 ; V_105 < V_110 -> V_117 ; V_105 ++ ) {
V_108 = & V_2 -> V_118 [ V_105 + V_110 -> V_128 ] ;
if ( V_108 -> V_119 != V_120 )
continue;
V_108 -> V_119 = V_122 ;
}
}
V_139:
V_2 -> V_82 -- ;
}
F_23 ( & V_2 -> V_81 ) ;
V_133:
V_2 -> V_68 &= ~ V_141 ;
V_2 -> V_135 = V_8 -> V_27 ;
F_21 ( & V_2 -> V_81 ) ;
F_42 (r2t, r2t_tmp, &cmd->cmd_r2t_list, r2t_list) {
if ( V_130 -> V_135 < V_8 -> V_27 )
continue;
if ( V_130 -> V_136 ) {
F_3 ( L_37
L_38
L_39
L_40 ,
V_8 -> V_27 , V_130 -> V_135 ,
V_130 -> V_67 , V_130 -> V_138 ) ;
F_23 ( & V_2 -> V_81 ) ;
return - 1 ;
}
if ( V_130 -> V_137 ) {
F_43 ( V_130 , V_2 ) ;
continue;
}
if ( V_6 -> V_17 -> V_42 -> V_111 )
V_2 -> V_113 -= V_130 -> V_138 ;
else
V_2 -> V_140 -- ;
V_2 -> V_82 -- ;
F_43 ( V_130 , V_2 ) ;
}
F_23 ( & V_2 -> V_81 ) ;
return 0 ;
}
int F_44 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_1 * V_4 = V_8 -> V_4 ;
if ( V_4 -> V_101 != V_103 )
return 0 ;
if ( V_4 -> V_11 . V_95 & V_96 )
return 0 ;
if ( V_4 -> V_97 == V_100 )
return 0 ;
if ( V_4 -> V_97 == V_99 ) {
if ( V_8 -> V_27 > V_4 -> V_88 ) {
F_3 ( L_41
L_42
L_43 , V_8 -> V_27 ,
V_4 -> V_88 ) ;
return - 1 ;
}
if ( ( V_4 -> V_68 & V_69 ) &&
( V_8 -> V_27 <= V_4 -> V_70 ) ) {
F_3 ( L_41
L_44
L_45
L_46 , V_8 -> V_27 ,
V_4 -> V_70 ) ;
return - 1 ;
}
return F_36 ( V_8 , V_6 ) ;
}
if ( V_4 -> V_97 == V_98 ) {
if ( V_8 -> V_27 > V_4 -> V_135 ) {
F_3 ( L_47
L_42
L_48 , V_8 -> V_27 ,
V_4 -> V_135 ) ;
return - 1 ;
}
return F_38 ( V_8 , V_6 ) ;
}
F_3 ( L_49 ,
V_4 -> V_97 ) ;
return - 1 ;
}
