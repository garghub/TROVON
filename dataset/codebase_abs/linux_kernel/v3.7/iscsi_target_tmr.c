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
return ( F_4 ( V_13 -> V_16 ) >= V_6 -> V_17 -> V_18 &&
F_4 ( V_13 -> V_16 ) <= V_6 -> V_17 -> V_19 ) ?
V_20 : V_21 ;
}
if ( V_4 -> V_22 != F_4 ( V_13 -> V_16 ) ) {
F_3 ( L_3
L_4 ,
V_13 -> V_16 , V_4 -> V_22 ) ;
return V_23 ;
}
V_10 -> V_24 = ( V_25 V_26 ) V_13 -> V_14 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_27 = F_4 ( V_13 -> V_28 ) ;
return V_20 ;
}
int F_5 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned char * V_3 )
{
struct V_29 * V_17 = V_6 -> V_17 ;
struct V_30 * V_31 = F_6 ( V_17 ) ;
if ( ! V_31 -> V_32 ) {
F_3 ( L_5
L_6 ,
V_17 -> V_33 -> V_34 -> V_35 ) ;
return - 1 ;
}
return 0 ;
}
int F_7 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned char * V_3 )
{
struct V_29 * V_17 = V_6 -> V_17 ;
struct V_30 * V_31 = F_6 ( V_17 ) ;
if ( ! V_31 -> V_36 ) {
F_3 ( L_7
L_6 ,
V_17 -> V_33 -> V_34 -> V_35 ) ;
return - 1 ;
}
return 0 ;
}
T_1 F_8 (
struct V_1 * V_2 ,
unsigned char * V_3 )
{
struct V_1 * V_4 = NULL ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_37 * V_38 = NULL ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 . V_9 ;
struct V_12 * V_13 = (struct V_12 * ) V_3 ;
int V_39 , V_40 ;
F_9 ( L_8
L_9 ,
V_13 -> V_41 , V_13 -> V_14 , V_13 -> V_28 , V_6 -> V_15 ) ;
if ( V_6 -> V_17 -> V_42 -> V_43 != 2 ) {
F_3 ( L_10
L_11 ) ;
return V_44 ;
}
V_39 = F_10 ( V_6 -> V_17 , & V_4 , & V_38 , V_13 -> V_14 ) ;
if ( V_39 == - 2 ) {
F_3 ( L_12
L_13 , V_4 -> V_45 , V_38 -> V_15 ) ;
return V_46 ;
} else if ( V_39 == - 1 ) {
F_3 ( L_14
L_15 , V_13 -> V_14 ) ;
return V_21 ;
}
if ( V_38 -> V_47 !=
V_6 -> V_48 -> V_49 ) {
F_3 ( L_16
L_17
L_18 ) ;
return V_23 ;
}
if ( V_38 -> V_50 !=
V_6 -> V_48 -> V_51 ) {
F_3 ( L_16
L_19
L_18 ) ;
return V_23 ;
}
V_40 = F_11 ( & V_13 -> V_52 ) ;
if ( V_40 != V_4 -> V_11 . V_53 ) {
F_3 ( L_16
L_20 ,
V_40 , V_4 -> V_11 . V_53 ) ;
return V_23 ;
}
V_10 -> V_24 = ( V_25 V_26 ) V_13 -> V_14 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_27 = F_4 ( V_13 -> V_28 ) ;
V_8 -> V_54 = V_38 ;
V_8 -> V_55 = 1 ;
return V_20 ;
}
static void F_12 (
struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_29 * V_17 )
{
int V_39 ;
F_13 ( & V_38 -> V_56 ) ;
V_39 = F_14 ( V_2 , V_17 ) ;
F_15 ( & V_38 -> V_56 ) ;
if ( ! V_39 ) {
F_9 ( L_21
L_22 , V_38 -> V_15 , V_17 -> V_57 ) ;
F_16 ( V_38 , V_17 ) ;
}
}
static int F_17 (
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
F_12 ( V_2 , V_38 , V_6 -> V_17 ) ;
F_18 ( & V_6 -> V_60 ) ;
F_19 ( & V_2 -> V_61 , & V_6 -> V_62 ) ;
F_20 ( & V_6 -> V_60 ) ;
V_2 -> V_63 = V_64 ;
F_21 ( V_2 , V_6 , V_2 -> V_63 ) ;
return 0 ;
}
static int F_22 (
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
int V_65 = 0 ;
V_26 V_66 = 0 , V_67 = 0 ;
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
F_9 ( L_25
L_26 ,
V_2 -> V_45 , V_2 -> V_11 . V_74 ) ;
F_23 ( V_11 ) ;
return 0 ;
}
V_2 -> V_63 = V_75 ;
F_21 ( V_2 , V_6 , V_2 -> V_63 ) ;
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
F_18 ( & V_2 -> V_81 ) ;
if ( F_24 ( V_2 , V_67 , V_66 , 0 , 0 ) < 0 ) {
F_20 ( & V_2 -> V_81 ) ;
return - 1 ;
}
V_2 -> V_82 ++ ;
F_20 ( & V_2 -> V_81 ) ;
if ( V_65 )
return 0 ;
}
return F_25 ( V_2 , V_6 , true ) ;
}
static int F_26 (
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_83 * V_84 ;
struct V_11 * V_11 = & V_2 -> V_11 ;
if ( ! V_8 -> V_27 ) {
V_2 -> V_68 &= ~ V_69 ;
V_2 -> V_70 = 0 ;
} else {
V_2 -> V_68 |= V_69 ;
V_2 -> V_70 = ( V_8 -> V_27 - 1 ) ;
}
if ( ! ( V_2 -> V_11 . V_72 & V_73 ) ) {
F_9 ( L_27
L_28 , V_2 -> V_45 ,
V_2 -> V_11 . V_74 ) ;
F_27 ( V_11 ) ;
return 0 ;
}
if ( ! ( V_11 -> V_72 & V_85 ) ) {
F_3 ( L_29
L_30 , V_2 -> V_45 ,
V_2 -> V_11 . V_74 ) ;
return - 1 ;
}
V_84 = F_28 () ;
if ( ! V_84 )
return - 1 ;
V_84 -> V_86 = V_84 -> V_87 = V_8 -> V_27 ;
V_84 -> V_88 = 0 ;
V_84 -> V_89 = 1 ;
V_84 -> V_90 = V_91 ;
F_29 ( V_2 , V_84 ) ;
V_2 -> V_63 = V_92 ;
F_21 ( V_2 , V_6 , V_2 -> V_63 ) ;
return 0 ;
}
static int F_30 (
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
V_2 -> V_63 = V_75 ;
F_21 ( V_2 , V_6 , V_2 -> V_63 ) ;
return 0 ;
}
static int F_31 (
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
F_12 ( V_2 , V_38 , V_6 -> V_17 ) ;
F_18 ( & V_6 -> V_60 ) ;
F_19 ( & V_2 -> V_61 , & V_6 -> V_62 ) ;
F_20 ( & V_6 -> V_60 ) ;
if ( V_2 -> V_11 . V_93 & V_94 ) {
V_2 -> V_63 = V_75 ;
F_21 ( V_2 , V_6 , V_2 -> V_63 ) ;
return 0 ;
}
switch ( V_2 -> V_95 ) {
case V_96 :
return F_22 ( V_2 , V_8 ) ;
case V_97 :
return F_26 ( V_2 , V_8 ) ;
case V_98 :
return F_30 ( V_2 , V_8 ) ;
default:
F_3 ( L_31 ,
V_2 -> V_95 ) ;
return - 1 ;
}
return 0 ;
}
static int F_32 (
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
switch ( V_2 -> V_99 ) {
case V_100 :
V_39 = F_17 ( V_8 , V_6 ) ;
break;
case V_101 :
V_39 = F_31 ( V_8 , V_6 ) ;
break;
default:
F_3 ( L_33
L_34 , V_2 -> V_99 ) ;
return - 1 ;
}
if ( V_39 != 0 )
return V_39 ;
F_9 ( L_35
L_36 , V_2 -> V_99 ,
V_2 -> V_45 , V_6 -> V_15 ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 . V_9 ;
if ( V_8 -> V_55 &&
( V_10 -> V_102 == V_20 ) )
return F_32 ( V_8 , V_6 ) ;
return 0 ;
}
static int F_34 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
return 0 ;
}
static void F_35 (
struct V_1 * V_2 ,
struct V_5 * V_6 )
{
int V_103 , V_104 ;
struct V_105 * V_106 = NULL ;
struct V_107 * V_108 = NULL ;
if ( V_6 -> V_17 -> V_42 -> V_109 ) {
V_2 -> V_86 = 0 ;
if ( V_2 -> V_110 )
V_2 -> V_111 += ( V_2 -> V_112 -
V_2 -> V_113 ) ;
if ( V_6 -> V_17 -> V_42 -> V_114 ) {
V_2 -> V_78 -= ( V_2 -> V_110 ) ?
( V_2 -> V_112 -
V_2 -> V_113 ) :
V_2 -> V_112 ;
V_2 -> V_112 = 0 ;
return;
}
for ( V_103 = 0 ; V_103 < V_2 -> V_115 ; V_103 ++ ) {
V_106 = & V_2 -> V_116 [ V_103 ] ;
if ( V_106 -> V_117 != V_118 )
continue;
if ( ( V_106 -> V_67 >= V_2 -> V_113 ) &&
( ( V_106 -> V_67 + V_106 -> V_66 ) <=
V_2 -> V_119 ) ) {
V_2 -> V_112 -= V_106 -> V_66 ;
V_2 -> V_78 -= V_106 -> V_66 ;
V_106 -> V_117 = V_120 ;
}
}
} else {
for ( V_103 = 0 ; V_103 < V_2 -> V_121 ; V_103 ++ ) {
V_108 = & V_2 -> V_122 [ V_103 ] ;
if ( V_108 -> type != V_123 )
continue;
V_2 -> V_78 -=
( V_108 -> V_67 - V_108 -> V_124 ) ;
V_2 -> V_112 = 0 ;
V_108 -> V_86 = 0 ;
V_108 -> V_67 = V_108 -> V_124 ;
V_108 -> V_77 = 0 ;
V_108 -> V_117 = V_125 ;
if ( V_6 -> V_17 -> V_42 -> V_114 )
continue;
for ( V_104 = 0 ; V_104 < V_108 -> V_115 ; V_104 ++ ) {
V_106 = & V_2 -> V_116 [ V_104 + V_108 -> V_126 ] ;
if ( V_106 -> V_117 != V_118 )
continue;
V_106 -> V_117 = V_120 ;
}
}
}
}
static int F_36 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = V_8 -> V_4 ;
struct V_105 * V_106 = NULL ;
struct V_127 * V_128 = NULL , * V_129 ;
int V_130 = 1 , V_103 = 0 ;
if ( V_2 -> V_76 )
F_35 ( V_2 , V_6 ) ;
if ( ! V_8 -> V_27 )
goto V_131;
F_18 ( & V_2 -> V_81 ) ;
if ( F_37 ( & V_2 -> V_132 ) ) {
F_20 ( & V_2 -> V_81 ) ;
return - 1 ;
}
F_38 (r2t, &cmd->cmd_r2t_list, r2t_list) {
if ( V_128 -> V_133 >= V_8 -> V_27 )
continue;
if ( V_128 -> V_134 )
continue;
if ( V_128 -> V_135 )
continue;
if ( V_6 -> V_17 -> V_42 -> V_109 ) {
if ( ! V_130 ) {
V_2 -> V_111 -= V_128 -> V_136 ;
goto V_137;
}
if ( V_6 -> V_17 -> V_42 -> V_114 ) {
V_2 -> V_86 = 0 ;
V_2 -> V_111 -= ( V_128 -> V_136 -
V_2 -> V_77 ) ;
V_130 = 0 ;
goto V_137;
}
V_2 -> V_86 = 0 ;
V_2 -> V_111 -= V_128 -> V_136 ;
for ( V_103 = 0 ; V_103 < V_2 -> V_115 ; V_103 ++ ) {
V_106 = & V_2 -> V_116 [ V_103 ] ;
if ( V_106 -> V_117 != V_118 )
continue;
if ( ( V_106 -> V_67 >= V_128 -> V_67 ) &&
( V_106 -> V_67 < ( V_128 -> V_67 +
V_128 -> V_136 ) ) ) {
V_2 -> V_77 -= V_106 -> V_66 ;
V_2 -> V_78 -= V_106 -> V_66 ;
V_106 -> V_117 = V_120 ;
}
}
V_130 = 0 ;
} else {
struct V_107 * V_108 ;
V_108 = F_39 ( V_2 , V_128 -> V_67 ,
V_128 -> V_136 ) ;
if ( ! V_108 ) {
F_20 ( & V_2 -> V_81 ) ;
return - 1 ;
}
V_2 -> V_78 -=
( V_108 -> V_67 - V_108 -> V_124 ) ;
V_108 -> V_86 = 0 ;
V_108 -> V_67 = V_108 -> V_124 ;
V_108 -> V_77 = 0 ;
V_108 -> V_117 = V_125 ;
V_2 -> V_138 -- ;
if ( V_6 -> V_17 -> V_42 -> V_114 )
goto V_137;
for ( V_103 = 0 ; V_103 < V_108 -> V_115 ; V_103 ++ ) {
V_106 = & V_2 -> V_116 [ V_103 + V_108 -> V_126 ] ;
if ( V_106 -> V_117 != V_118 )
continue;
V_106 -> V_117 = V_120 ;
}
}
V_137:
V_2 -> V_82 -- ;
}
F_20 ( & V_2 -> V_81 ) ;
V_131:
V_2 -> V_68 &= ~ V_139 ;
V_2 -> V_133 = V_8 -> V_27 ;
F_18 ( & V_2 -> V_81 ) ;
F_40 (r2t, r2t_tmp, &cmd->cmd_r2t_list, r2t_list) {
if ( V_128 -> V_133 < V_8 -> V_27 )
continue;
if ( V_128 -> V_134 ) {
F_3 ( L_37
L_38
L_39
L_40 ,
V_8 -> V_27 , V_128 -> V_133 ,
V_128 -> V_67 , V_128 -> V_136 ) ;
F_20 ( & V_2 -> V_81 ) ;
return - 1 ;
}
if ( V_128 -> V_135 ) {
F_41 ( V_128 , V_2 ) ;
continue;
}
if ( V_6 -> V_17 -> V_42 -> V_109 )
V_2 -> V_111 -= V_128 -> V_136 ;
else
V_2 -> V_138 -- ;
V_2 -> V_82 -- ;
F_41 ( V_128 , V_2 ) ;
}
F_20 ( & V_2 -> V_81 ) ;
return 0 ;
}
int F_42 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_1 * V_4 = V_8 -> V_4 ;
if ( V_4 -> V_99 != V_101 )
return 0 ;
if ( V_4 -> V_11 . V_93 & V_94 )
return 0 ;
if ( V_4 -> V_95 == V_98 )
return 0 ;
if ( V_4 -> V_95 == V_97 ) {
if ( V_8 -> V_27 > V_4 -> V_86 ) {
F_3 ( L_41
L_42
L_43 , V_8 -> V_27 ,
V_4 -> V_86 ) ;
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
return F_34 ( V_8 , V_6 ) ;
}
if ( V_4 -> V_95 == V_96 ) {
if ( V_8 -> V_27 > V_4 -> V_133 ) {
F_3 ( L_47
L_42
L_48 , V_8 -> V_27 ,
V_4 -> V_133 ) ;
return - 1 ;
}
return F_36 ( V_8 , V_6 ) ;
}
F_3 ( L_49 ,
V_4 -> V_95 ) ;
return - 1 ;
}
