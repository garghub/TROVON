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
V_10 -> V_4 = & V_4 -> V_11 ;
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
#if 0
struct iscsi_init_task_mgt_cmnd *hdr =
(struct iscsi_init_task_mgt_cmnd *) buf;
#endif
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
int V_38 ;
F_8 ( L_8
L_9 ,
V_13 -> V_39 , V_13 -> V_14 , V_13 -> V_27 , V_6 -> V_15 ) ;
if ( V_6 -> V_17 -> V_40 -> V_41 != 2 ) {
F_3 ( L_10
L_11 ) ;
return V_42 ;
}
V_38 = F_9 ( V_6 -> V_17 , & V_4 , & V_37 , V_13 -> V_14 ) ;
if ( V_38 == - 2 ) {
F_3 ( L_12
L_13 , V_4 -> V_43 , V_37 -> V_15 ) ;
return V_44 ;
} else if ( V_38 == - 1 ) {
F_3 ( L_14
L_15 , V_13 -> V_14 ) ;
return V_21 ;
}
if ( V_37 -> V_45 !=
V_6 -> V_46 -> V_47 ) {
F_3 ( L_16
L_17
L_18 ) ;
return V_23 ;
}
V_10 -> V_24 = V_13 -> V_14 ;
V_10 -> V_4 = & V_4 -> V_11 ;
V_10 -> V_48 = F_10 ( & V_13 -> V_49 ) ;
V_8 -> V_25 = V_13 -> V_16 ;
V_8 -> V_26 = V_13 -> V_27 ;
V_8 -> V_50 = V_37 ;
V_8 -> V_51 = 1 ;
return V_20 ;
}
static void F_11 (
struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_28 * V_17 )
{
int V_38 ;
F_12 ( & V_37 -> V_52 ) ;
V_38 = F_13 ( V_2 , V_17 ) ;
F_14 ( & V_37 -> V_52 ) ;
if ( ! V_38 ) {
F_8 ( L_19
L_20 , V_37 -> V_15 , V_17 -> V_53 ) ;
F_15 ( V_37 , V_17 ) ;
}
}
static int F_16 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = V_8 -> V_9 ;
struct V_11 * V_11 = V_10 -> V_4 ;
struct V_1 * V_2 = F_17 ( V_11 , struct V_1 , V_11 ) ;
struct V_36 * V_37 ;
if ( ! V_2 -> V_37 ) {
F_3 ( L_21
L_22 , V_2 -> V_43 ) ;
return - 1 ;
}
V_37 = V_2 -> V_37 ;
V_2 -> V_54 = V_2 -> V_55 = 0 ;
F_11 ( V_2 , V_37 , V_6 -> V_17 ) ;
F_18 ( & V_6 -> V_56 ) ;
F_19 ( & V_2 -> V_57 , & V_6 -> V_58 ) ;
F_20 ( & V_6 -> V_56 ) ;
V_2 -> V_59 = V_60 ;
F_21 ( V_2 , V_6 , V_2 -> V_59 ) ;
return 0 ;
}
static int F_22 (
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
int V_61 = 0 ;
T_2 V_62 = 0 , V_63 = 0 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_11 * V_11 = & V_2 -> V_11 ;
if ( ! V_8 -> V_26 ) {
V_2 -> V_64 &= ~ V_65 ;
V_2 -> V_66 = 0 ;
} else {
V_2 -> V_64 |= V_65 ;
V_2 -> V_66 = ( V_8 -> V_26 - 1 ) ;
}
if ( V_2 -> V_64 & V_67 ) {
if ( ! F_23 ( & V_2 -> V_11 . V_68 ) ) {
F_8 ( L_23
L_24 ,
V_2 -> V_43 , V_2 -> V_11 . V_69 ) ;
return F_24 ( V_11 ) ;
}
V_2 -> V_59 = V_70 ;
F_21 ( V_2 , V_6 , V_2 -> V_59 ) ;
return 0 ;
}
if ( V_2 -> V_71 ) {
V_2 -> V_71 = 0 ;
V_63 = V_2 -> V_72 = V_2 -> V_73 ;
if ( ( V_6 -> V_17 -> V_40 -> V_74 - V_63 ) >=
V_2 -> V_75 ) {
V_61 = 1 ;
V_62 = ( V_2 -> V_75 - V_63 ) ;
} else
V_62 = ( V_6 -> V_17 -> V_40 -> V_74 - V_63 ) ;
F_18 ( & V_2 -> V_76 ) ;
if ( F_25 ( V_2 , V_63 , V_62 , 0 , 0 ) < 0 ) {
F_20 ( & V_2 -> V_76 ) ;
return - 1 ;
}
V_2 -> V_77 ++ ;
F_20 ( & V_2 -> V_76 ) ;
if ( V_61 )
return 0 ;
}
return F_26 ( V_2 , V_6 , 2 ) ;
}
static int F_27 (
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_78 * V_79 ;
struct V_11 * V_11 = & V_2 -> V_11 ;
if ( ! V_8 -> V_26 ) {
V_2 -> V_64 &= ~ V_65 ;
V_2 -> V_66 = 0 ;
} else {
V_2 -> V_64 |= V_65 ;
V_2 -> V_66 = ( V_8 -> V_26 - 1 ) ;
}
if ( ! F_23 ( & V_2 -> V_11 . V_68 ) ) {
F_8 ( L_25
L_26 , V_2 -> V_43 ,
V_2 -> V_11 . V_69 ) ;
F_28 ( V_11 ) ;
return 0 ;
}
if ( ! F_23 ( & V_11 -> V_80 ) ) {
F_3 ( L_27
L_28 , V_2 -> V_43 ,
V_2 -> V_11 . V_69 ) ;
return - 1 ;
}
V_79 = F_29 () ;
if ( ! V_79 )
return - 1 ;
V_79 -> V_81 = V_79 -> V_82 = V_8 -> V_26 ;
V_79 -> V_83 = 0 ;
V_79 -> V_84 = 1 ;
V_79 -> V_85 = V_86 ;
F_30 ( V_2 , V_79 ) ;
V_2 -> V_59 = V_87 ;
F_21 ( V_2 , V_6 , V_2 -> V_59 ) ;
return 0 ;
}
static int F_31 (
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
V_2 -> V_59 = V_70 ;
F_21 ( V_2 , V_6 , V_2 -> V_59 ) ;
return 0 ;
}
static int F_32 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = V_8 -> V_9 ;
struct V_11 * V_11 = V_10 -> V_4 ;
struct V_1 * V_2 = F_17 ( V_11 , struct V_1 , V_11 ) ;
struct V_36 * V_37 ;
if ( ! V_2 -> V_37 ) {
F_3 ( L_21
L_22 , V_2 -> V_43 ) ;
return - 1 ;
}
V_37 = V_2 -> V_37 ;
V_2 -> V_54 = V_2 -> V_55 = 0 ;
F_11 ( V_2 , V_37 , V_6 -> V_17 ) ;
F_18 ( & V_6 -> V_56 ) ;
F_19 ( & V_2 -> V_57 , & V_6 -> V_58 ) ;
F_20 ( & V_6 -> V_56 ) ;
if ( V_11 -> V_88 & V_89 ) {
V_2 -> V_59 = V_70 ;
F_21 ( V_2 , V_6 , V_2 -> V_59 ) ;
return 0 ;
}
switch ( V_2 -> V_90 ) {
case V_91 :
return F_22 ( V_2 , V_8 ) ;
case V_92 :
return F_27 ( V_2 , V_8 ) ;
case V_93 :
return F_31 ( V_2 , V_8 ) ;
default:
F_3 ( L_29 ,
V_2 -> V_90 ) ;
return - 1 ;
}
return 0 ;
}
static int F_33 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = V_8 -> V_9 ;
struct V_11 * V_11 ;
struct V_1 * V_2 ;
int V_38 = 0 ;
if ( ! V_10 -> V_4 ) {
F_3 ( L_30 ) ;
return - 1 ;
}
V_11 = V_10 -> V_4 ;
V_2 = F_17 ( V_11 , struct V_1 , V_11 ) ;
V_2 -> V_6 = V_6 ;
switch ( V_2 -> V_94 ) {
case V_95 :
V_38 = F_16 ( V_8 , V_6 ) ;
break;
case V_96 :
V_38 = F_32 ( V_8 , V_6 ) ;
break;
default:
F_3 ( L_31
L_32 , V_2 -> V_94 ) ;
return - 1 ;
}
if ( V_38 != 0 )
return V_38 ;
F_8 ( L_33
L_34 , V_2 -> V_94 ,
V_2 -> V_43 , V_6 -> V_15 ) ;
return 0 ;
}
extern int F_34 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 . V_9 ;
if ( V_8 -> V_51 &&
( V_10 -> V_97 == V_20 ) )
return F_33 ( V_8 , V_6 ) ;
return 0 ;
}
int F_35 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
return 0 ;
}
static void F_36 (
struct V_1 * V_2 ,
struct V_5 * V_6 )
{
int V_98 , V_99 ;
struct V_100 * V_101 = NULL ;
struct V_102 * V_103 = NULL ;
if ( V_6 -> V_17 -> V_40 -> V_104 ) {
V_2 -> V_81 = 0 ;
if ( V_2 -> V_105 )
V_2 -> V_106 += ( V_2 -> V_107 -
V_2 -> V_108 ) ;
if ( V_6 -> V_17 -> V_40 -> V_109 ) {
V_2 -> V_73 -= ( V_2 -> V_105 ) ?
( V_2 -> V_107 -
V_2 -> V_108 ) :
V_2 -> V_107 ;
V_2 -> V_107 = 0 ;
return;
}
for ( V_98 = 0 ; V_98 < V_2 -> V_110 ; V_98 ++ ) {
V_101 = & V_2 -> V_111 [ V_98 ] ;
if ( V_101 -> V_112 != V_113 )
continue;
if ( ( V_101 -> V_63 >= V_2 -> V_108 ) &&
( ( V_101 -> V_63 + V_101 -> V_62 ) <=
V_2 -> V_114 ) ) {
V_2 -> V_107 -= V_101 -> V_62 ;
V_2 -> V_73 -= V_101 -> V_62 ;
V_101 -> V_112 = V_115 ;
}
}
} else {
for ( V_98 = 0 ; V_98 < V_2 -> V_116 ; V_98 ++ ) {
V_103 = & V_2 -> V_117 [ V_98 ] ;
if ( V_103 -> type != V_118 )
continue;
V_2 -> V_73 -=
( V_103 -> V_63 - V_103 -> V_119 ) ;
V_2 -> V_107 = 0 ;
V_103 -> V_81 = 0 ;
V_103 -> V_63 = V_103 -> V_119 ;
V_103 -> V_72 = 0 ;
V_103 -> V_112 = V_120 ;
if ( V_6 -> V_17 -> V_40 -> V_109 )
continue;
for ( V_99 = 0 ; V_99 < V_103 -> V_110 ; V_99 ++ ) {
V_101 = & V_2 -> V_111 [ V_99 + V_103 -> V_121 ] ;
if ( V_101 -> V_112 != V_113 )
continue;
V_101 -> V_112 = V_115 ;
}
}
}
}
int F_37 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = V_8 -> V_9 ;
struct V_11 * V_11 = V_10 -> V_4 ;
struct V_1 * V_2 = F_17 ( V_11 , struct V_1 , V_11 ) ;
struct V_100 * V_101 = NULL ;
struct V_122 * V_123 = NULL , * V_124 ;
int V_125 = 1 , V_98 = 0 ;
if ( V_2 -> V_71 )
F_36 ( V_2 , V_6 ) ;
if ( ! V_8 -> V_26 )
goto V_126;
F_18 ( & V_2 -> V_76 ) ;
if ( F_38 ( & V_2 -> V_127 ) ) {
F_20 ( & V_2 -> V_76 ) ;
return - 1 ;
}
F_39 (r2t, &cmd->cmd_r2t_list, r2t_list) {
if ( V_123 -> V_128 >= V_8 -> V_26 )
continue;
if ( V_123 -> V_129 )
continue;
if ( V_123 -> V_130 )
continue;
if ( V_6 -> V_17 -> V_40 -> V_104 ) {
if ( ! V_125 ) {
V_2 -> V_106 -= V_123 -> V_131 ;
goto V_132;
}
if ( V_6 -> V_17 -> V_40 -> V_109 ) {
V_2 -> V_81 = 0 ;
V_2 -> V_106 -= ( V_123 -> V_131 -
V_2 -> V_72 ) ;
V_125 = 0 ;
goto V_132;
}
V_2 -> V_81 = 0 ;
V_2 -> V_106 -= V_123 -> V_131 ;
for ( V_98 = 0 ; V_98 < V_2 -> V_110 ; V_98 ++ ) {
V_101 = & V_2 -> V_111 [ V_98 ] ;
if ( V_101 -> V_112 != V_113 )
continue;
if ( ( V_101 -> V_63 >= V_123 -> V_63 ) &&
( V_101 -> V_63 < ( V_123 -> V_63 +
V_123 -> V_131 ) ) ) {
V_2 -> V_72 -= V_101 -> V_62 ;
V_2 -> V_73 -= V_101 -> V_62 ;
V_101 -> V_112 = V_115 ;
}
}
V_125 = 0 ;
} else {
struct V_102 * V_103 ;
V_103 = F_40 ( V_2 , V_123 -> V_63 ,
V_123 -> V_131 ) ;
if ( ! V_103 ) {
F_20 ( & V_2 -> V_76 ) ;
return - 1 ;
}
V_2 -> V_73 -=
( V_103 -> V_63 - V_103 -> V_119 ) ;
V_103 -> V_81 = 0 ;
V_103 -> V_63 = V_103 -> V_119 ;
V_103 -> V_72 = 0 ;
V_103 -> V_112 = V_120 ;
V_2 -> V_133 -- ;
if ( V_6 -> V_17 -> V_40 -> V_109 )
goto V_132;
for ( V_98 = 0 ; V_98 < V_103 -> V_110 ; V_98 ++ ) {
V_101 = & V_2 -> V_111 [ V_98 + V_103 -> V_121 ] ;
if ( V_101 -> V_112 != V_113 )
continue;
V_101 -> V_112 = V_115 ;
}
}
V_132:
V_2 -> V_77 -- ;
}
F_20 ( & V_2 -> V_76 ) ;
V_126:
V_2 -> V_64 &= ~ V_134 ;
V_2 -> V_128 = V_8 -> V_26 ;
F_18 ( & V_2 -> V_76 ) ;
F_41 (r2t, r2t_tmp, &cmd->cmd_r2t_list, r2t_list) {
if ( V_123 -> V_128 < V_8 -> V_26 )
continue;
if ( V_123 -> V_129 ) {
F_3 ( L_35
L_36
L_37
L_38 ,
V_8 -> V_26 , V_123 -> V_128 ,
V_123 -> V_63 , V_123 -> V_131 ) ;
F_20 ( & V_2 -> V_76 ) ;
return - 1 ;
}
if ( V_123 -> V_130 ) {
F_42 ( V_123 , V_2 ) ;
continue;
}
if ( V_6 -> V_17 -> V_40 -> V_104 )
V_2 -> V_106 -= V_123 -> V_131 ;
else
V_2 -> V_133 -- ;
V_2 -> V_77 -- ;
F_42 ( V_123 , V_2 ) ;
}
F_20 ( & V_2 -> V_76 ) ;
return 0 ;
}
int F_43 (
struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = V_8 -> V_9 ;
struct V_11 * V_11 = V_10 -> V_4 ;
struct V_1 * V_4 = F_17 ( V_11 , struct V_1 , V_11 ) ;
if ( V_4 -> V_94 != V_96 )
return 0 ;
if ( V_11 -> V_88 & V_89 )
return 0 ;
if ( V_4 -> V_90 == V_93 )
return 0 ;
if ( V_4 -> V_90 == V_92 ) {
if ( V_8 -> V_26 > V_4 -> V_81 ) {
F_3 ( L_39
L_40
L_41 , V_8 -> V_26 ,
V_4 -> V_81 ) ;
return - 1 ;
}
if ( ( V_4 -> V_64 & V_65 ) &&
( V_8 -> V_26 <= V_4 -> V_66 ) ) {
F_3 ( L_39
L_42
L_43
L_44 , V_8 -> V_26 ,
V_4 -> V_66 ) ;
return - 1 ;
}
return F_35 ( V_8 , V_6 ) ;
}
if ( V_4 -> V_90 == V_91 ) {
if ( V_8 -> V_26 > V_4 -> V_128 ) {
F_3 ( L_45
L_40
L_46 , V_8 -> V_26 ,
V_4 -> V_128 ) ;
return - 1 ;
}
return F_37 ( V_8 , V_6 ) ;
}
F_3 ( L_47 ,
V_4 -> V_90 ) ;
return - 1 ;
}
