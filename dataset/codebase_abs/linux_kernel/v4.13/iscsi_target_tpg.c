struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_5 ) {
F_3 ( L_1 ) ;
return NULL ;
}
V_5 -> V_4 = V_4 ;
V_5 -> V_7 = V_8 ;
V_5 -> V_9 = V_3 ;
F_4 ( & V_5 -> V_10 ) ;
F_4 ( & V_5 -> V_11 ) ;
F_5 ( & V_5 -> V_12 ) ;
F_6 ( & V_5 -> V_13 , 1 ) ;
F_7 ( & V_5 -> V_14 ) ;
F_7 ( & V_5 -> V_15 ) ;
return V_5 ;
}
int F_8 ( void )
{
struct V_16 * V_17 ;
struct V_1 * V_5 ;
int V_18 ;
V_5 = F_1 ( NULL , 1 ) ;
if ( ! V_5 ) {
F_3 ( L_1 ) ;
return - 1 ;
}
V_5 -> V_19 . V_20 = & V_21 ;
V_18 = F_9 ( NULL , & V_5 -> V_19 , - 1 ) ;
if ( V_18 < 0 ) {
F_10 ( V_5 ) ;
return - 1 ;
}
V_5 -> V_22 = 1 ;
F_11 ( V_5 ) ;
if ( F_12 ( & V_5 -> V_23 ) < 0 )
goto V_24;
V_17 = F_13 ( V_25 , V_5 -> V_23 ) ;
if ( ! V_17 )
goto V_24;
if ( F_14 ( V_17 , L_2 ) < 0 )
goto V_24;
V_5 -> V_26 . V_27 = 0 ;
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_28 ;
F_16 ( & V_5 -> V_14 ) ;
V_29 -> V_30 = V_5 ;
F_17 ( L_3 ) ;
return 0 ;
V_24:
if ( V_5 -> V_22 == 1 )
F_18 ( & V_5 -> V_19 ) ;
F_10 ( V_5 ) ;
return - 1 ;
}
void F_19 ( void )
{
struct V_1 * V_5 = V_29 -> V_30 ;
if ( ! V_5 )
return;
F_18 ( & V_5 -> V_19 ) ;
F_10 ( V_5 ) ;
V_29 -> V_30 = NULL ;
}
struct V_1 * F_20 (
struct V_2 * V_3 ,
struct V_31 * V_32 ,
struct V_33 * * V_34 )
{
struct V_1 * V_5 = NULL ;
struct V_33 * V_35 ;
F_15 ( & V_3 -> V_36 ) ;
F_21 (tpg, &tiqn->tiqn_tpg_list, tpg_list) {
F_15 ( & V_5 -> V_14 ) ;
if ( V_5 -> V_7 != V_28 ) {
F_16 ( & V_5 -> V_14 ) ;
continue;
}
F_16 ( & V_5 -> V_14 ) ;
F_15 ( & V_5 -> V_15 ) ;
F_21 (tpg_np, &tpg->tpg_gnp_list, tpg_np_list) {
if ( V_35 -> V_35 == V_32 ) {
* V_34 = V_35 ;
F_22 ( & V_35 -> V_37 ) ;
F_16 ( & V_5 -> V_15 ) ;
F_16 ( & V_3 -> V_36 ) ;
return V_5 ;
}
}
F_16 ( & V_5 -> V_15 ) ;
}
F_16 ( & V_3 -> V_36 ) ;
return NULL ;
}
int F_23 (
struct V_1 * V_5 )
{
return F_24 ( & V_5 -> V_12 ) ;
}
void F_25 ( struct V_1 * V_5 )
{
F_26 ( & V_5 -> V_12 ) ;
}
static void F_27 (
struct V_33 * V_35 ,
struct V_1 * V_5 ,
bool V_38 )
{
if ( ! V_35 -> V_35 ) {
F_3 ( L_4 ) ;
return;
}
if ( V_38 )
V_35 -> V_35 -> V_39 = false ;
F_28 ( V_35 -> V_35 , V_35 , V_5 , V_38 ) ;
}
static void F_29 (
struct V_1 * V_5 ,
bool V_38 )
{
struct V_33 * V_35 ;
F_15 ( & V_5 -> V_15 ) ;
F_21 (tpg_np, &tpg->tpg_gnp_list, tpg_np_list) {
if ( ! V_35 -> V_35 ) {
F_3 ( L_4 ) ;
continue;
}
F_16 ( & V_5 -> V_15 ) ;
F_27 ( V_35 , V_5 , V_38 ) ;
F_15 ( & V_5 -> V_15 ) ;
}
F_16 ( & V_5 -> V_15 ) ;
}
void F_30 ( struct V_1 * V_5 )
{
F_31 ( V_5 -> V_23 ) ;
}
static void F_11 ( struct V_1 * V_5 )
{
struct V_40 * V_41 = & V_5 -> V_26 ;
V_41 -> V_27 = V_42 ;
V_41 -> V_43 = V_44 ;
V_41 -> V_45 = V_46 ;
V_41 -> V_47 = V_48 ;
V_41 -> V_49 = V_50 ;
V_41 -> V_51 = V_52 ;
V_41 -> V_53 = V_54 ;
V_41 -> V_55 = V_56 ;
V_41 -> V_57 = V_58 ;
V_41 -> V_59 = V_60 ;
V_41 -> V_61 = V_62 ;
V_41 -> V_63 = V_64 ;
V_41 -> V_65 = V_66 ;
V_41 -> V_67 = V_68 ;
}
int F_32 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
if ( V_5 -> V_7 != V_8 ) {
F_3 ( L_5
L_6 , V_5 -> V_4 ) ;
return - V_69 ;
}
F_11 ( V_5 ) ;
if ( F_12 ( & V_5 -> V_23 ) < 0 )
goto V_70;
V_5 -> V_26 . V_5 = V_5 ;
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_71 ;
F_16 ( & V_5 -> V_14 ) ;
F_15 ( & V_3 -> V_36 ) ;
F_33 ( & V_5 -> V_11 , & V_3 -> V_72 ) ;
V_3 -> V_73 ++ ;
F_17 ( L_7 ,
V_3 -> V_3 , V_5 -> V_4 ) ;
F_16 ( & V_3 -> V_36 ) ;
return 0 ;
V_70:
if ( V_5 -> V_23 ) {
F_34 ( V_5 -> V_23 ) ;
V_5 -> V_23 = NULL ;
}
return - V_74 ;
}
int F_35 (
struct V_2 * V_3 ,
struct V_1 * V_5 ,
int V_75 )
{
T_2 V_76 = V_5 -> V_7 ;
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_71 ;
F_16 ( & V_5 -> V_14 ) ;
if ( F_36 ( V_5 , V_75 ) < 0 ) {
F_3 ( L_8
L_9 ,
V_5 -> V_4 ) ;
V_5 -> V_7 = V_76 ;
return - V_77 ;
}
if ( V_5 -> V_23 ) {
F_34 ( V_5 -> V_23 ) ;
V_5 -> V_23 = NULL ;
}
F_18 ( & V_5 -> V_19 ) ;
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_8 ;
F_16 ( & V_5 -> V_14 ) ;
F_15 ( & V_3 -> V_36 ) ;
V_3 -> V_73 -- ;
F_37 ( & V_5 -> V_11 ) ;
F_16 ( & V_3 -> V_36 ) ;
F_17 ( L_10 ,
V_3 -> V_3 , V_5 -> V_4 ) ;
F_10 ( V_5 ) ;
return 0 ;
}
int F_38 ( struct V_1 * V_5 )
{
struct V_16 * V_17 ;
struct V_2 * V_3 = V_5 -> V_9 ;
int V_18 ;
if ( V_5 -> V_7 == V_28 ) {
F_3 ( L_11
L_12 , V_5 -> V_4 ) ;
return - V_78 ;
}
V_17 = F_13 ( V_25 , V_5 -> V_23 ) ;
if ( ! V_17 )
return - V_78 ;
if ( V_5 -> V_26 . V_27 ) {
if ( ! strcmp ( V_17 -> V_79 , V_80 ) ) {
V_18 = F_14 ( V_17 , V_81 ) ;
if ( V_18 )
goto V_82;
}
V_18 = F_39 ( V_5 , 1 ) ;
if ( V_18 < 0 )
goto V_82;
}
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_28 ;
F_16 ( & V_5 -> V_14 ) ;
F_15 ( & V_3 -> V_36 ) ;
V_3 -> V_83 ++ ;
F_17 ( L_13 ,
V_5 -> V_4 ) ;
F_16 ( & V_3 -> V_36 ) ;
return 0 ;
V_82:
return V_18 ;
}
int F_40 ( struct V_1 * V_5 , int V_75 )
{
struct V_2 * V_3 ;
T_2 V_76 = V_5 -> V_7 ;
F_15 ( & V_5 -> V_14 ) ;
if ( V_5 -> V_7 == V_71 ) {
F_3 ( L_14
L_15 , V_5 -> V_4 ) ;
F_16 ( & V_5 -> V_14 ) ;
return - V_78 ;
}
V_5 -> V_7 = V_71 ;
F_16 ( & V_5 -> V_14 ) ;
F_29 ( V_5 , false ) ;
if ( F_36 ( V_5 , V_75 ) < 0 ) {
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_76 ;
F_16 ( & V_5 -> V_14 ) ;
F_3 ( L_16
L_9 ,
V_5 -> V_4 ) ;
return - V_77 ;
}
V_3 = V_5 -> V_9 ;
if ( ! V_3 || ( V_5 == V_29 -> V_30 ) )
return 0 ;
F_15 ( & V_3 -> V_36 ) ;
V_3 -> V_83 -- ;
F_17 ( L_17 ,
V_5 -> V_4 ) ;
F_16 ( & V_3 -> V_36 ) ;
return 0 ;
}
struct V_84 * F_41 (
struct V_85 * V_86 )
{
struct V_87 * V_88 = V_86 -> V_88 ;
struct V_89 * V_90 = V_88 -> V_89 ;
struct V_91 * V_92 = F_42 ( V_90 , struct V_91 ,
V_89 ) ;
return & V_92 -> V_93 ;
}
struct V_33 * F_43 (
struct V_33 * V_35 ,
int V_94 )
{
struct V_33 * V_95 , * V_96 ;
F_15 ( & V_35 -> V_97 ) ;
F_44 (tpg_np_child, tpg_np_child_tmp,
&tpg_np->tpg_np_parent_list, tpg_np_child_list) {
if ( V_95 -> V_35 -> V_98 ==
V_94 ) {
F_16 ( & V_35 -> V_97 ) ;
return V_95 ;
}
}
F_16 ( & V_35 -> V_97 ) ;
return NULL ;
}
static bool F_45 (
struct V_2 * V_3 ,
struct V_99 * V_100 ,
int V_94 )
{
struct V_1 * V_5 ;
struct V_33 * V_35 ;
struct V_31 * V_32 ;
bool V_101 = false ;
F_15 ( & V_3 -> V_36 ) ;
F_21 (tpg, &tiqn->tiqn_tpg_list, tpg_list) {
F_15 ( & V_5 -> V_15 ) ;
F_21 (tpg_np, &tpg->tpg_gnp_list, tpg_np_list) {
V_32 = V_35 -> V_35 ;
V_101 = F_46 ( V_100 , V_32 ,
V_94 ) ;
if ( V_101 )
break;
}
F_16 ( & V_5 -> V_15 ) ;
}
F_16 ( & V_3 -> V_36 ) ;
return V_101 ;
}
struct V_33 * F_47 (
struct V_1 * V_5 ,
struct V_99 * V_100 ,
struct V_33 * V_102 ,
int V_94 )
{
struct V_31 * V_32 ;
struct V_33 * V_35 ;
if ( ! V_102 ) {
if ( F_45 ( V_5 -> V_9 , V_100 ,
V_94 ) ) {
F_3 ( L_18
L_19 , V_100 ,
V_5 -> V_9 -> V_3 ) ;
return F_48 ( - V_69 ) ;
}
}
V_35 = F_2 ( sizeof( struct V_33 ) , V_6 ) ;
if ( ! V_35 ) {
F_3 ( L_20
L_21 ) ;
return F_48 ( - V_74 ) ;
}
V_32 = F_49 ( V_100 , V_94 ) ;
if ( F_50 ( V_32 ) ) {
F_10 ( V_35 ) ;
return F_51 ( V_32 ) ;
}
F_4 ( & V_35 -> V_103 ) ;
F_4 ( & V_35 -> V_104 ) ;
F_4 ( & V_35 -> V_105 ) ;
F_7 ( & V_35 -> V_97 ) ;
F_52 ( & V_35 -> V_106 ) ;
F_53 ( & V_35 -> V_37 ) ;
V_35 -> V_35 = V_32 ;
V_35 -> V_5 = V_5 ;
F_15 ( & V_5 -> V_15 ) ;
F_33 ( & V_35 -> V_103 , & V_5 -> V_10 ) ;
V_5 -> V_107 ++ ;
if ( V_5 -> V_9 )
V_5 -> V_9 -> V_108 ++ ;
F_16 ( & V_5 -> V_15 ) ;
if ( V_102 ) {
V_35 -> V_102 = V_102 ;
F_15 ( & V_102 -> V_97 ) ;
F_33 ( & V_35 -> V_104 ,
& V_102 -> V_105 ) ;
F_16 ( & V_102 -> V_97 ) ;
}
F_17 ( L_22 ,
V_5 -> V_9 -> V_3 , & V_32 -> V_109 , V_5 -> V_4 ,
V_32 -> V_110 -> V_111 ) ;
return V_35 ;
}
static int F_54 (
struct V_33 * V_35 ,
struct V_1 * V_5 ,
struct V_31 * V_32 )
{
F_27 ( V_35 , V_5 , true ) ;
F_17 ( L_23 ,
V_5 -> V_9 -> V_3 , & V_32 -> V_109 , V_5 -> V_4 ,
V_32 -> V_110 -> V_111 ) ;
V_35 -> V_35 = NULL ;
V_35 -> V_5 = NULL ;
F_10 ( V_35 ) ;
return F_55 ( V_32 ) ;
}
int F_56 (
struct V_1 * V_5 ,
struct V_33 * V_35 )
{
struct V_31 * V_32 ;
struct V_33 * V_95 , * V_96 ;
int V_18 = 0 ;
V_32 = V_35 -> V_35 ;
if ( ! V_32 ) {
F_3 ( L_24
L_25 ) ;
return - V_78 ;
}
if ( ! V_35 -> V_102 ) {
F_44 (tpg_np_child, tpg_np_child_tmp,
&tpg_np->tpg_np_parent_list,
tpg_np_child_list) {
V_18 = F_56 ( V_5 , V_95 ) ;
if ( V_18 < 0 )
F_3 ( L_26
L_27 , V_18 ) ;
}
} else {
F_15 ( & V_35 -> V_102 -> V_97 ) ;
F_37 ( & V_35 -> V_104 ) ;
F_16 ( & V_35 -> V_102 -> V_97 ) ;
}
F_15 ( & V_5 -> V_15 ) ;
F_37 ( & V_35 -> V_103 ) ;
V_5 -> V_107 -- ;
if ( V_5 -> V_9 )
V_5 -> V_9 -> V_108 -- ;
F_16 ( & V_5 -> V_15 ) ;
return F_54 ( V_35 , V_5 , V_32 ) ;
}
int F_39 ( struct V_1 * V_5 , T_3 V_27 )
{
unsigned char V_112 [ 256 ] , V_113 [ 256 ] , * V_114 = NULL ;
int V_115 ;
struct V_16 * V_17 ;
struct V_40 * V_41 = & V_5 -> V_26 ;
if ( ( V_27 != 1 ) && ( V_27 != 0 ) ) {
F_3 ( L_28
L_29 , V_27 ) ;
return - V_78 ;
}
memset ( V_112 , 0 , sizeof( V_112 ) ) ;
memset ( V_113 , 0 , sizeof( V_113 ) ) ;
V_17 = F_13 ( V_25 , V_5 -> V_23 ) ;
if ( ! V_17 )
return - V_78 ;
if ( V_27 ) {
snprintf ( V_112 , sizeof( V_112 ) , L_30 , V_17 -> V_79 ) ;
V_114 = strstr ( V_112 , V_80 ) ;
if ( ! V_114 )
goto V_24;
if ( ! strncmp ( V_114 + 4 , L_31 , 1 ) ) {
if ( ! strcmp ( V_112 , V_114 ) )
sprintf ( V_113 , L_30 , V_114 + 5 ) ;
else {
V_114 -- ;
* V_114 = '\0' ;
V_115 = sprintf ( V_113 , L_30 , V_112 ) ;
V_114 += 5 ;
sprintf ( V_113 + V_115 , L_30 , V_114 ) ;
}
} else {
V_114 -- ;
* V_114 = '\0' ;
sprintf ( V_113 , L_30 , V_112 ) ;
}
if ( F_14 ( V_17 , V_113 ) < 0 )
return - V_78 ;
} else {
snprintf ( V_112 , sizeof( V_112 ) , L_30 , V_17 -> V_79 ) ;
V_114 = strstr ( V_112 , V_80 ) ;
if ( V_114 )
goto V_24;
strncat ( V_112 , L_31 , strlen ( L_31 ) ) ;
strncat ( V_112 , V_80 , strlen ( V_80 ) ) ;
if ( F_14 ( V_17 , V_112 ) < 0 )
return - V_78 ;
}
V_24:
V_41 -> V_27 = V_27 ;
F_17 ( L_32 ,
V_41 -> V_27 ? L_33 : L_34 , V_5 -> V_4 ) ;
return 0 ;
}
int F_57 (
struct V_1 * V_5 ,
T_3 V_43 )
{
struct V_40 * V_41 = & V_5 -> V_26 ;
if ( V_43 > V_116 ) {
F_3 ( L_35
L_36 , V_43 , V_116 ) ;
return - V_78 ;
} else if ( V_43 < V_117 ) {
F_3 ( L_37
L_38 , V_43 , V_117 ) ;
return - V_78 ;
}
V_41 -> V_43 = V_43 ;
F_17 ( L_39
L_40 , V_41 -> V_43 , V_5 -> V_4 ) ;
return 0 ;
}
int F_58 (
struct V_1 * V_5 ,
T_3 V_45 )
{
struct V_40 * V_41 = & V_5 -> V_26 ;
if ( V_45 > V_118 ) {
F_3 ( L_41
L_42 , V_45 ,
V_118 ) ;
return - V_78 ;
} else if ( V_45 < V_119 ) {
F_3 ( L_43
L_44 , V_45 ,
V_119 ) ;
return - V_78 ;
}
V_41 -> V_45 = V_45 ;
F_17 ( L_45
L_46 , V_41 -> V_45 , V_5 -> V_4 ) ;
return 0 ;
}
int F_59 (
struct V_1 * V_5 ,
T_3 V_120 )
{
struct V_40 * V_41 = & V_5 -> V_26 ;
if ( ( V_120 != 0 ) && ( V_120 != 1 ) ) {
F_3 ( L_47 , V_120 ) ;
return - V_78 ;
}
V_41 -> V_49 = V_120 ;
F_17 ( L_48 ,
V_5 -> V_4 , ( V_41 -> V_49 ) ? L_49 : L_50 ) ;
if ( V_120 == 1 && V_41 -> V_51 == 0 ) {
F_17 ( L_51
L_52 ) ;
V_41 -> V_51 = 1 ;
}
return 0 ;
}
int F_60 (
struct V_1 * V_5 ,
T_3 V_121 )
{
struct V_40 * V_41 = & V_5 -> V_26 ;
if ( V_121 > V_122 ) {
F_3 ( L_53
L_42 , V_121 ,
V_122 ) ;
return - V_78 ;
} else if ( V_121 < V_123 ) {
F_3 ( L_54
L_44 , V_121 ,
V_123 ) ;
return - V_78 ;
}
V_41 -> V_47 = V_121 ;
F_17 ( L_55 ,
V_5 -> V_4 , V_41 -> V_47 ) ;
return 0 ;
}
int F_61 (
struct V_1 * V_5 ,
T_3 V_120 )
{
struct V_40 * V_41 = & V_5 -> V_26 ;
if ( ( V_120 != 0 ) && ( V_120 != 1 ) ) {
F_3 ( L_47 , V_120 ) ;
return - V_78 ;
}
if ( V_41 -> V_49 == 1 && V_120 == 0 ) {
F_17 ( L_56
L_57 ) ;
return 0 ;
}
V_41 -> V_51 = V_120 ;
F_17 ( L_58
L_59 , V_5 -> V_4 , ( V_41 -> V_51 ) ?
L_49 : L_50 ) ;
return 0 ;
}
int F_62 (
struct V_1 * V_5 ,
T_3 V_120 )
{
struct V_40 * V_41 = & V_5 -> V_26 ;
if ( ( V_120 != 0 ) && ( V_120 != 1 ) ) {
F_3 ( L_47 , V_120 ) ;
return - V_78 ;
}
V_41 -> V_53 = V_120 ;
F_17 ( L_60 ,
V_5 -> V_4 , ( V_41 -> V_53 ) ? L_61 : L_62 ) ;
return 0 ;
}
int F_63 (
struct V_1 * V_5 ,
T_3 V_120 )
{
struct V_40 * V_41 = & V_5 -> V_26 ;
if ( ( V_120 != 0 ) && ( V_120 != 1 ) ) {
F_3 ( L_47 , V_120 ) ;
return - V_78 ;
}
V_41 -> V_55 = V_120 ;
F_17 ( L_63
L_64 , V_5 -> V_4 , ( V_41 -> V_55 ) ?
L_61 : L_62 ) ;
return 0 ;
}
int F_64 (
struct V_1 * V_5 ,
T_3 V_120 )
{
struct V_40 * V_41 = & V_5 -> V_26 ;
if ( ( V_120 != 0 ) && ( V_120 != 1 ) ) {
F_3 ( L_47 , V_120 ) ;
return - V_78 ;
}
V_41 -> V_57 = V_120 ;
F_17 ( L_65
L_64 , V_5 -> V_4 , ( V_41 -> V_57 ) ?
L_61 : L_62 ) ;
return 0 ;
}
int F_65 (
struct V_1 * V_5 ,
T_3 V_59 )
{
struct V_40 * V_41 = & V_5 -> V_26 ;
if ( ( V_59 != 0 ) && ( V_59 != 1 ) && ( V_59 != 2 ) ) {
F_3 ( L_66 , V_59 ) ;
return - V_78 ;
}
V_41 -> V_59 = V_59 ;
F_17 ( L_67 , V_5 -> V_4 , V_41 -> V_59 ) ;
return 0 ;
}
int F_66 (
struct V_1 * V_5 ,
T_3 V_120 )
{
struct V_40 * V_41 = & V_5 -> V_26 ;
if ( ( V_120 != 0 ) && ( V_120 != 1 ) ) {
F_3 ( L_47 , V_120 ) ;
return - V_78 ;
}
V_41 -> V_61 = V_120 ;
F_17 ( L_68
L_64 , V_5 -> V_4 , ( V_41 -> V_61 ) ?
L_61 : L_62 ) ;
return 0 ;
}
int F_67 (
struct V_1 * V_5 ,
T_3 V_124 )
{
struct V_40 * V_41 = & V_5 -> V_26 ;
if ( ( V_124 != 0 ) && ( V_124 != 1 ) && ( V_124 != 3 ) ) {
F_3 ( L_69 , V_124 ) ;
return - V_78 ;
}
V_41 -> V_63 = V_124 ;
F_17 ( L_70 ,
V_5 -> V_4 , V_124 ) ;
return 0 ;
}
int F_68 (
struct V_1 * V_5 ,
T_3 V_120 )
{
struct V_40 * V_41 = & V_5 -> V_26 ;
if ( ( V_120 != 0 ) && ( V_120 != 1 ) ) {
F_3 ( L_47 , V_120 ) ;
return - V_78 ;
}
V_41 -> V_65 = V_120 ;
F_17 ( L_71
L_64 , V_5 -> V_4 , ( V_41 -> V_65 ) ? L_61 : L_62 ) ;
return 0 ;
}
int F_69 (
struct V_1 * V_5 ,
T_3 V_120 )
{
struct V_40 * V_41 = & V_5 -> V_26 ;
if ( ( V_120 != 0 ) && ( V_120 != 1 ) ) {
F_3 ( L_47 , V_120 ) ;
return - V_78 ;
}
V_41 -> V_67 = V_120 ;
F_17 ( L_72 ,
V_5 -> V_4 , ( V_41 -> V_67 ) ? L_61 : L_62 ) ;
return 0 ;
}
