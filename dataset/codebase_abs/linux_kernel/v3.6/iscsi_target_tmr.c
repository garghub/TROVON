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
return ( ( V_13 -> V_16 >= V_6 -> V_17 -> V_18 ) &&
( V_13 -> V_16 <= V_6 -> V_17 -> V_19 ) ) ?
V_20 : V_21 ;
}
if ( V_4 -> V_22 != V_13 -> V_16 ) {
F_3 ( L_3
L_4 ,
V_13 -> V_16 , V_4 -> V_22 ) ;
return V_23 ;
}
V_10 -> V_24 = V_13 -> V_14 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_25 = V_13 -> V_16 ;
V_8 -> V_26 = V_13 -> V_27 ;
return V_20 ;
}
int F_4 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned char * V_3 )
{
struct V_28 * V_17 = V_6 -> V_17 ;
struct V_29 * V_30 = F_5 ( V_17 ) ;
if ( ! V_30 -> V_31 ) {
F_3 ( L_5
L_6 ,
V_17 -> V_32 -> V_33 -> V_34 ) ;
return - 1 ;
}
return 0 ;
}
int F_6 (
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned char * V_3 )
{
struct V_28 * V_17 = V_6 -> V_17 ;
struct V_29 * V_30 = F_5 ( V_17 ) ;
if ( ! V_30 -> V_35 ) {
F_3 ( L_7
L_6 ,
V_17 -> V_32 -> V_33 -> V_34 ) ;
return - 1 ;
}
return 0 ;
}
T_1 F_7 (
struct V_1 * V_2 ,
unsigned char * V_3 )
{
struct V_1 * V_4 = NULL ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_36 * V_37 = NULL ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 . V_9 ;
struct V_12 * V_13 = (struct V_12 * ) V_3 ;
int V_38 , V_39 ;
F_8 ( L_8
L_9 ,
V_13 -> V_40 , V_13 -> V_14 , V_13 -> V_27 , V_6 -> V_15 ) ;
if ( V_6 -> V_17 -> V_41 -> V_42 != 2 ) {
F_3 ( L_10
L_11 ) ;
return V_43 ;
}
V_38 = F_9 ( V_6 -> V_17 , & V_4 , & V_37 , V_13 -> V_14 ) ;
if ( V_38 == - 2 ) {
F_3 ( L_12
L_13 , V_4 -> V_44 , V_37 -> V_15 ) ;
return V_45 ;
} else if ( V_38 == - 1 ) {
F_3 ( L_14
L_15 , V_13 -> V_14 ) ;
return V_21 ;
}
if ( V_37 -> V_46 !=
V_6 -> V_47 -> V_48 ) {
F_3 ( L_16
L_17
L_18 ) ;
return V_23 ;
}
V_39 = F_10 ( & V_13 -> V_49 ) ;
if ( V_39 != V_4 -> V_11 . V_50 ) {
F_3 ( L_16
L_19 ,
V_39 , V_4 -> V_11 . V_50 ) ;
return V_23 ;
}
V_10 -> V_24 = V_13 -> V_14 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_25 = V_13 -> V_16 ;
V_8 -> V_26 = V_13 -> V_27 ;
V_8 -> V_51 = V_37 ;
V_8 -> V_52 = 1 ;
return V_20 ;
}
static void F_11 (
struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_28 * V_17 )
{
int V_38 ;
F_12 ( & V_37 -> V_53 ) ;
V_38 = F_13 ( V_2 , V_17 ) ;
F_14 ( & V_37 -> V_53 ) ;
if ( ! V_38 ) {
F_8 ( L_20
L_21 , V_37 -> V_15 , V_17 -> V_54 ) ;
F_15 ( V_37 , V_17 ) ;
}
}
static int F_16 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = V_8 -> V_4 ;
struct V_36 * V_37 ;
if ( ! V_2 -> V_37 ) {
F_3 ( L_22
L_23 , V_2 -> V_44 ) ;
return - 1 ;
}
V_37 = V_2 -> V_37 ;
V_2 -> V_55 = V_2 -> V_56 = 0 ;
F_11 ( V_2 , V_37 , V_6 -> V_17 ) ;
F_17 ( & V_6 -> V_57 ) ;
F_18 ( & V_2 -> V_58 , & V_6 -> V_59 ) ;
F_19 ( & V_6 -> V_57 ) ;
V_2 -> V_60 = V_61 ;
F_20 ( V_2 , V_6 , V_2 -> V_60 ) ;
return 0 ;
}
static int F_21 (
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
int V_62 = 0 ;
T_2 V_63 = 0 , V_64 = 0 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_11 * V_11 = & V_2 -> V_11 ;
if ( ! V_8 -> V_26 ) {
V_2 -> V_65 &= ~ V_66 ;
V_2 -> V_67 = 0 ;
} else {
V_2 -> V_65 |= V_66 ;
V_2 -> V_67 = ( V_8 -> V_26 - 1 ) ;
}
if ( V_2 -> V_65 & V_68 ) {
if ( ! ( V_2 -> V_11 . V_69 & V_70 ) ) {
F_8 ( L_24
L_25 ,
V_2 -> V_44 , V_2 -> V_11 . V_71 ) ;
F_22 ( V_11 ) ;
return 0 ;
}
V_2 -> V_60 = V_72 ;
F_20 ( V_2 , V_6 , V_2 -> V_60 ) ;
return 0 ;
}
if ( V_2 -> V_73 ) {
V_2 -> V_73 = 0 ;
V_64 = V_2 -> V_74 = V_2 -> V_75 ;
if ( ( V_6 -> V_17 -> V_41 -> V_76 - V_64 ) >=
V_2 -> V_11 . V_77 ) {
V_62 = 1 ;
V_63 = ( V_2 -> V_11 . V_77 - V_64 ) ;
} else
V_63 = ( V_6 -> V_17 -> V_41 -> V_76 - V_64 ) ;
F_17 ( & V_2 -> V_78 ) ;
if ( F_23 ( V_2 , V_64 , V_63 , 0 , 0 ) < 0 ) {
F_19 ( & V_2 -> V_78 ) ;
return - 1 ;
}
V_2 -> V_79 ++ ;
F_19 ( & V_2 -> V_78 ) ;
if ( V_62 )
return 0 ;
}
return F_24 ( V_2 , V_6 , true ) ;
}
static int F_25 (
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_80 * V_81 ;
struct V_11 * V_11 = & V_2 -> V_11 ;
if ( ! V_8 -> V_26 ) {
V_2 -> V_65 &= ~ V_66 ;
V_2 -> V_67 = 0 ;
} else {
V_2 -> V_65 |= V_66 ;
V_2 -> V_67 = ( V_8 -> V_26 - 1 ) ;
}
if ( ! ( V_2 -> V_11 . V_69 & V_70 ) ) {
F_8 ( L_26
L_27 , V_2 -> V_44 ,
V_2 -> V_11 . V_71 ) ;
F_26 ( V_11 ) ;
return 0 ;
}
if ( ! ( V_11 -> V_69 & V_82 ) ) {
F_3 ( L_28
L_29 , V_2 -> V_44 ,
V_2 -> V_11 . V_71 ) ;
return - 1 ;
}
V_81 = F_27 () ;
if ( ! V_81 )
return - 1 ;
V_81 -> V_83 = V_81 -> V_84 = V_8 -> V_26 ;
V_81 -> V_85 = 0 ;
V_81 -> V_86 = 1 ;
V_81 -> V_87 = V_88 ;
F_28 ( V_2 , V_81 ) ;
V_2 -> V_60 = V_89 ;
F_20 ( V_2 , V_6 , V_2 -> V_60 ) ;
return 0 ;
}
static int F_29 (
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
V_2 -> V_60 = V_72 ;
F_20 ( V_2 , V_6 , V_2 -> V_60 ) ;
return 0 ;
}
static int F_30 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = V_8 -> V_4 ;
struct V_36 * V_37 ;
if ( ! V_2 -> V_37 ) {
F_3 ( L_22
L_23 , V_2 -> V_44 ) ;
return - 1 ;
}
V_37 = V_2 -> V_37 ;
V_2 -> V_55 = V_2 -> V_56 = 0 ;
F_11 ( V_2 , V_37 , V_6 -> V_17 ) ;
F_17 ( & V_6 -> V_57 ) ;
F_18 ( & V_2 -> V_58 , & V_6 -> V_59 ) ;
F_19 ( & V_6 -> V_57 ) ;
if ( V_2 -> V_11 . V_90 & V_91 ) {
V_2 -> V_60 = V_72 ;
F_20 ( V_2 , V_6 , V_2 -> V_60 ) ;
return 0 ;
}
switch ( V_2 -> V_92 ) {
case V_93 :
return F_21 ( V_2 , V_8 ) ;
case V_94 :
return F_25 ( V_2 , V_8 ) ;
case V_95 :
return F_29 ( V_2 , V_8 ) ;
default:
F_3 ( L_30 ,
V_2 -> V_92 ) ;
return - 1 ;
}
return 0 ;
}
static int F_31 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 ;
int V_38 = 0 ;
if ( ! V_8 -> V_4 ) {
F_3 ( L_31 ) ;
return - 1 ;
}
V_2 = V_8 -> V_4 ;
V_2 -> V_6 = V_6 ;
switch ( V_2 -> V_96 ) {
case V_97 :
V_38 = F_16 ( V_8 , V_6 ) ;
break;
case V_98 :
V_38 = F_30 ( V_8 , V_6 ) ;
break;
default:
F_3 ( L_32
L_33 , V_2 -> V_96 ) ;
return - 1 ;
}
if ( V_38 != 0 )
return V_38 ;
F_8 ( L_34
L_35 , V_2 -> V_96 ,
V_2 -> V_44 , V_6 -> V_15 ) ;
return 0 ;
}
extern int F_32 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 . V_9 ;
if ( V_8 -> V_52 &&
( V_10 -> V_99 == V_20 ) )
return F_31 ( V_8 , V_6 ) ;
return 0 ;
}
int F_33 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
return 0 ;
}
static void F_34 (
struct V_1 * V_2 ,
struct V_5 * V_6 )
{
int V_100 , V_101 ;
struct V_102 * V_103 = NULL ;
struct V_104 * V_105 = NULL ;
if ( V_6 -> V_17 -> V_41 -> V_106 ) {
V_2 -> V_83 = 0 ;
if ( V_2 -> V_107 )
V_2 -> V_108 += ( V_2 -> V_109 -
V_2 -> V_110 ) ;
if ( V_6 -> V_17 -> V_41 -> V_111 ) {
V_2 -> V_75 -= ( V_2 -> V_107 ) ?
( V_2 -> V_109 -
V_2 -> V_110 ) :
V_2 -> V_109 ;
V_2 -> V_109 = 0 ;
return;
}
for ( V_100 = 0 ; V_100 < V_2 -> V_112 ; V_100 ++ ) {
V_103 = & V_2 -> V_113 [ V_100 ] ;
if ( V_103 -> V_114 != V_115 )
continue;
if ( ( V_103 -> V_64 >= V_2 -> V_110 ) &&
( ( V_103 -> V_64 + V_103 -> V_63 ) <=
V_2 -> V_116 ) ) {
V_2 -> V_109 -= V_103 -> V_63 ;
V_2 -> V_75 -= V_103 -> V_63 ;
V_103 -> V_114 = V_117 ;
}
}
} else {
for ( V_100 = 0 ; V_100 < V_2 -> V_118 ; V_100 ++ ) {
V_105 = & V_2 -> V_119 [ V_100 ] ;
if ( V_105 -> type != V_120 )
continue;
V_2 -> V_75 -=
( V_105 -> V_64 - V_105 -> V_121 ) ;
V_2 -> V_109 = 0 ;
V_105 -> V_83 = 0 ;
V_105 -> V_64 = V_105 -> V_121 ;
V_105 -> V_74 = 0 ;
V_105 -> V_114 = V_122 ;
if ( V_6 -> V_17 -> V_41 -> V_111 )
continue;
for ( V_101 = 0 ; V_101 < V_105 -> V_112 ; V_101 ++ ) {
V_103 = & V_2 -> V_113 [ V_101 + V_105 -> V_123 ] ;
if ( V_103 -> V_114 != V_115 )
continue;
V_103 -> V_114 = V_117 ;
}
}
}
}
int F_35 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = V_8 -> V_4 ;
struct V_102 * V_103 = NULL ;
struct V_124 * V_125 = NULL , * V_126 ;
int V_127 = 1 , V_100 = 0 ;
if ( V_2 -> V_73 )
F_34 ( V_2 , V_6 ) ;
if ( ! V_8 -> V_26 )
goto V_128;
F_17 ( & V_2 -> V_78 ) ;
if ( F_36 ( & V_2 -> V_129 ) ) {
F_19 ( & V_2 -> V_78 ) ;
return - 1 ;
}
F_37 (r2t, &cmd->cmd_r2t_list, r2t_list) {
if ( V_125 -> V_130 >= V_8 -> V_26 )
continue;
if ( V_125 -> V_131 )
continue;
if ( V_125 -> V_132 )
continue;
if ( V_6 -> V_17 -> V_41 -> V_106 ) {
if ( ! V_127 ) {
V_2 -> V_108 -= V_125 -> V_133 ;
goto V_134;
}
if ( V_6 -> V_17 -> V_41 -> V_111 ) {
V_2 -> V_83 = 0 ;
V_2 -> V_108 -= ( V_125 -> V_133 -
V_2 -> V_74 ) ;
V_127 = 0 ;
goto V_134;
}
V_2 -> V_83 = 0 ;
V_2 -> V_108 -= V_125 -> V_133 ;
for ( V_100 = 0 ; V_100 < V_2 -> V_112 ; V_100 ++ ) {
V_103 = & V_2 -> V_113 [ V_100 ] ;
if ( V_103 -> V_114 != V_115 )
continue;
if ( ( V_103 -> V_64 >= V_125 -> V_64 ) &&
( V_103 -> V_64 < ( V_125 -> V_64 +
V_125 -> V_133 ) ) ) {
V_2 -> V_74 -= V_103 -> V_63 ;
V_2 -> V_75 -= V_103 -> V_63 ;
V_103 -> V_114 = V_117 ;
}
}
V_127 = 0 ;
} else {
struct V_104 * V_105 ;
V_105 = F_38 ( V_2 , V_125 -> V_64 ,
V_125 -> V_133 ) ;
if ( ! V_105 ) {
F_19 ( & V_2 -> V_78 ) ;
return - 1 ;
}
V_2 -> V_75 -=
( V_105 -> V_64 - V_105 -> V_121 ) ;
V_105 -> V_83 = 0 ;
V_105 -> V_64 = V_105 -> V_121 ;
V_105 -> V_74 = 0 ;
V_105 -> V_114 = V_122 ;
V_2 -> V_135 -- ;
if ( V_6 -> V_17 -> V_41 -> V_111 )
goto V_134;
for ( V_100 = 0 ; V_100 < V_105 -> V_112 ; V_100 ++ ) {
V_103 = & V_2 -> V_113 [ V_100 + V_105 -> V_123 ] ;
if ( V_103 -> V_114 != V_115 )
continue;
V_103 -> V_114 = V_117 ;
}
}
V_134:
V_2 -> V_79 -- ;
}
F_19 ( & V_2 -> V_78 ) ;
V_128:
V_2 -> V_65 &= ~ V_136 ;
V_2 -> V_130 = V_8 -> V_26 ;
F_17 ( & V_2 -> V_78 ) ;
F_39 (r2t, r2t_tmp, &cmd->cmd_r2t_list, r2t_list) {
if ( V_125 -> V_130 < V_8 -> V_26 )
continue;
if ( V_125 -> V_131 ) {
F_3 ( L_36
L_37
L_38
L_39 ,
V_8 -> V_26 , V_125 -> V_130 ,
V_125 -> V_64 , V_125 -> V_133 ) ;
F_19 ( & V_2 -> V_78 ) ;
return - 1 ;
}
if ( V_125 -> V_132 ) {
F_40 ( V_125 , V_2 ) ;
continue;
}
if ( V_6 -> V_17 -> V_41 -> V_106 )
V_2 -> V_108 -= V_125 -> V_133 ;
else
V_2 -> V_135 -- ;
V_2 -> V_79 -- ;
F_40 ( V_125 , V_2 ) ;
}
F_19 ( & V_2 -> V_78 ) ;
return 0 ;
}
int F_41 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_1 * V_4 = V_8 -> V_4 ;
if ( V_4 -> V_96 != V_98 )
return 0 ;
if ( V_4 -> V_11 . V_90 & V_91 )
return 0 ;
if ( V_4 -> V_92 == V_95 )
return 0 ;
if ( V_4 -> V_92 == V_94 ) {
if ( V_8 -> V_26 > V_4 -> V_83 ) {
F_3 ( L_40
L_41
L_42 , V_8 -> V_26 ,
V_4 -> V_83 ) ;
return - 1 ;
}
if ( ( V_4 -> V_65 & V_66 ) &&
( V_8 -> V_26 <= V_4 -> V_67 ) ) {
F_3 ( L_40
L_43
L_44
L_45 , V_8 -> V_26 ,
V_4 -> V_67 ) ;
return - 1 ;
}
return F_33 ( V_8 , V_6 ) ;
}
if ( V_4 -> V_92 == V_93 ) {
if ( V_8 -> V_26 > V_4 -> V_130 ) {
F_3 ( L_46
L_41
L_47 , V_8 -> V_26 ,
V_4 -> V_130 ) ;
return - 1 ;
}
return F_35 ( V_8 , V_6 ) ;
}
F_3 ( L_48 ,
V_4 -> V_92 ) ;
return - 1 ;
}
