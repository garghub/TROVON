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
V_18 = F_9 (
& V_19 -> V_20 ,
NULL , & V_5 -> V_21 , V_5 ,
V_22 ) ;
if ( V_18 < 0 ) {
F_10 ( V_5 ) ;
return - 1 ;
}
V_5 -> V_23 = 1 ;
F_11 ( V_5 ) ;
if ( F_12 ( & V_5 -> V_24 ) < 0 )
goto V_25;
V_17 = F_13 ( V_26 , V_5 -> V_24 ) ;
if ( ! V_17 )
goto V_25;
if ( F_14 ( V_17 , L_2 ) < 0 )
goto V_25;
V_5 -> V_27 . V_28 = 0 ;
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_29 ;
F_16 ( & V_5 -> V_14 ) ;
V_30 -> V_31 = V_5 ;
F_17 ( L_3 ) ;
return 0 ;
V_25:
if ( V_5 -> V_23 == 1 )
F_18 ( & V_5 -> V_21 ) ;
F_10 ( V_5 ) ;
return - 1 ;
}
void F_19 ( void )
{
struct V_1 * V_5 = V_30 -> V_31 ;
if ( ! V_5 )
return;
F_18 ( & V_5 -> V_21 ) ;
F_10 ( V_5 ) ;
V_30 -> V_31 = NULL ;
}
struct V_1 * F_20 (
struct V_2 * V_3 ,
struct V_32 * V_33 ,
struct V_34 * * V_35 )
{
struct V_1 * V_5 = NULL ;
struct V_34 * V_36 ;
F_15 ( & V_3 -> V_37 ) ;
F_21 (tpg, &tiqn->tiqn_tpg_list, tpg_list) {
F_15 ( & V_5 -> V_14 ) ;
if ( V_5 -> V_7 == V_8 ) {
F_16 ( & V_5 -> V_14 ) ;
continue;
}
F_16 ( & V_5 -> V_14 ) ;
F_15 ( & V_5 -> V_15 ) ;
F_21 (tpg_np, &tpg->tpg_gnp_list, tpg_np_list) {
if ( V_36 -> V_36 == V_33 ) {
* V_35 = V_36 ;
F_22 ( & V_36 -> V_38 ) ;
F_16 ( & V_5 -> V_15 ) ;
F_16 ( & V_3 -> V_37 ) ;
return V_5 ;
}
}
F_16 ( & V_5 -> V_15 ) ;
}
F_16 ( & V_3 -> V_37 ) ;
return NULL ;
}
int F_23 (
struct V_1 * V_5 )
{
int V_18 ;
V_18 = F_24 ( & V_5 -> V_12 ) ;
return ( ( V_18 != 0 ) || F_25 ( V_39 ) ) ? - 1 : 0 ;
}
void F_26 ( struct V_1 * V_5 )
{
F_27 ( & V_5 -> V_12 ) ;
}
static void F_28 (
struct V_34 * V_36 ,
struct V_1 * V_5 ,
bool V_40 )
{
if ( ! V_36 -> V_36 ) {
F_3 ( L_4 ) ;
return;
}
F_29 ( V_36 -> V_36 , V_36 , V_5 , V_40 ) ;
}
void F_30 (
struct V_1 * V_5 ,
bool V_40 )
{
struct V_34 * V_36 ;
F_15 ( & V_5 -> V_15 ) ;
F_21 (tpg_np, &tpg->tpg_gnp_list, tpg_np_list) {
if ( ! V_36 -> V_36 ) {
F_3 ( L_4 ) ;
continue;
}
F_16 ( & V_5 -> V_15 ) ;
F_28 ( V_36 , V_5 , V_40 ) ;
F_15 ( & V_5 -> V_15 ) ;
}
F_16 ( & V_5 -> V_15 ) ;
}
void F_31 ( struct V_1 * V_5 )
{
F_32 ( V_5 -> V_24 ) ;
}
static void F_11 ( struct V_1 * V_5 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
V_42 -> V_28 = V_43 ;
V_42 -> V_44 = V_45 ;
V_42 -> V_46 = V_47 ;
V_42 -> V_48 = V_49 ;
V_42 -> V_50 = V_51 ;
V_42 -> V_52 = V_53 ;
V_42 -> V_54 = V_55 ;
V_42 -> V_56 = V_57 ;
V_42 -> V_58 = V_59 ;
V_42 -> V_60 = V_61 ;
}
int F_33 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
if ( V_5 -> V_7 != V_8 ) {
F_3 ( L_5
L_6 , V_5 -> V_4 ) ;
return - V_62 ;
}
F_11 ( V_5 ) ;
if ( F_12 ( & V_5 -> V_24 ) < 0 )
goto V_63;
V_5 -> V_27 . V_5 = V_5 ;
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_64 ;
F_16 ( & V_5 -> V_14 ) ;
F_15 ( & V_3 -> V_37 ) ;
F_34 ( & V_5 -> V_11 , & V_3 -> V_65 ) ;
V_3 -> V_66 ++ ;
F_17 ( L_7 ,
V_3 -> V_3 , V_5 -> V_4 ) ;
F_16 ( & V_3 -> V_37 ) ;
return 0 ;
V_63:
if ( V_5 -> V_24 ) {
F_35 ( V_5 -> V_24 ) ;
V_5 -> V_24 = NULL ;
}
F_10 ( V_5 ) ;
return - V_67 ;
}
int F_36 (
struct V_2 * V_3 ,
struct V_1 * V_5 ,
int V_68 )
{
T_2 V_69 = V_5 -> V_7 ;
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_64 ;
F_16 ( & V_5 -> V_14 ) ;
F_30 ( V_5 , true ) ;
if ( F_37 ( V_5 , V_68 ) < 0 ) {
F_3 ( L_8
L_9 ,
V_5 -> V_4 ) ;
V_5 -> V_7 = V_69 ;
return - V_70 ;
}
F_38 ( & V_5 -> V_21 ) ;
if ( V_5 -> V_24 ) {
F_35 ( V_5 -> V_24 ) ;
V_5 -> V_24 = NULL ;
}
F_18 ( & V_5 -> V_21 ) ;
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_8 ;
F_16 ( & V_5 -> V_14 ) ;
F_15 ( & V_3 -> V_37 ) ;
V_3 -> V_66 -- ;
F_39 ( & V_5 -> V_11 ) ;
F_16 ( & V_3 -> V_37 ) ;
F_17 ( L_10 ,
V_3 -> V_3 , V_5 -> V_4 ) ;
F_10 ( V_5 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_5 )
{
struct V_16 * V_17 ;
struct V_2 * V_3 = V_5 -> V_9 ;
int V_18 ;
F_15 ( & V_5 -> V_14 ) ;
if ( V_5 -> V_7 == V_29 ) {
F_3 ( L_11
L_12 , V_5 -> V_4 ) ;
F_16 ( & V_5 -> V_14 ) ;
return - V_71 ;
}
V_17 = F_13 ( V_26 , V_5 -> V_24 ) ;
if ( ! V_17 ) {
F_16 ( & V_5 -> V_14 ) ;
return - V_71 ;
}
if ( V_5 -> V_27 . V_28 ) {
if ( ! strcmp ( V_17 -> V_72 , V_73 ) ) {
V_18 = F_14 ( V_17 , V_74 ) ;
if ( V_18 )
goto V_75;
}
V_18 = F_41 ( V_5 , 1 ) ;
if ( V_18 < 0 )
goto V_75;
}
V_5 -> V_7 = V_29 ;
F_16 ( & V_5 -> V_14 ) ;
F_15 ( & V_3 -> V_37 ) ;
V_3 -> V_76 ++ ;
F_17 ( L_13 ,
V_5 -> V_4 ) ;
F_16 ( & V_3 -> V_37 ) ;
return 0 ;
V_75:
F_16 ( & V_5 -> V_14 ) ;
return V_18 ;
}
int F_42 ( struct V_1 * V_5 , int V_68 )
{
struct V_2 * V_3 ;
T_2 V_69 = V_5 -> V_7 ;
F_15 ( & V_5 -> V_14 ) ;
if ( V_5 -> V_7 == V_64 ) {
F_3 ( L_14
L_15 , V_5 -> V_4 ) ;
F_16 ( & V_5 -> V_14 ) ;
return - V_71 ;
}
V_5 -> V_7 = V_64 ;
F_16 ( & V_5 -> V_14 ) ;
F_30 ( V_5 , false ) ;
if ( F_37 ( V_5 , V_68 ) < 0 ) {
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_69 ;
F_16 ( & V_5 -> V_14 ) ;
F_3 ( L_16
L_9 ,
V_5 -> V_4 ) ;
return - V_70 ;
}
V_3 = V_5 -> V_9 ;
if ( ! V_3 || ( V_5 == V_30 -> V_31 ) )
return 0 ;
F_15 ( & V_3 -> V_37 ) ;
V_3 -> V_76 -- ;
F_17 ( L_17 ,
V_5 -> V_4 ) ;
F_16 ( & V_3 -> V_37 ) ;
return 0 ;
}
struct V_77 * F_43 (
struct V_78 * V_79 )
{
struct V_80 * V_81 = V_79 -> V_81 ;
struct V_82 * V_83 = V_81 -> V_82 ;
struct V_84 * V_85 = F_44 ( V_83 , struct V_84 ,
V_82 ) ;
return & V_85 -> V_86 ;
}
struct V_34 * F_45 (
struct V_34 * V_36 ,
int V_87 )
{
struct V_34 * V_88 , * V_89 ;
F_15 ( & V_36 -> V_90 ) ;
F_46 (tpg_np_child, tpg_np_child_tmp,
&tpg_np->tpg_np_parent_list, tpg_np_child_list) {
if ( V_88 -> V_36 -> V_91 ==
V_87 ) {
F_16 ( & V_36 -> V_90 ) ;
return V_88 ;
}
}
F_16 ( & V_36 -> V_90 ) ;
return NULL ;
}
static bool F_47 (
struct V_2 * V_3 ,
struct V_92 * V_93 ,
int V_87 )
{
struct V_1 * V_5 ;
struct V_34 * V_36 ;
struct V_32 * V_33 ;
bool V_94 = false ;
F_15 ( & V_3 -> V_37 ) ;
F_21 (tpg, &tiqn->tiqn_tpg_list, tpg_list) {
F_15 ( & V_5 -> V_15 ) ;
F_21 (tpg_np, &tpg->tpg_gnp_list, tpg_np_list) {
V_33 = V_36 -> V_36 ;
V_94 = F_48 ( V_93 , V_33 ,
V_87 ) ;
if ( V_94 == true )
break;
}
F_16 ( & V_5 -> V_15 ) ;
}
F_16 ( & V_3 -> V_37 ) ;
return V_94 ;
}
struct V_34 * F_49 (
struct V_1 * V_5 ,
struct V_92 * V_93 ,
char * V_95 ,
struct V_34 * V_96 ,
int V_87 )
{
struct V_32 * V_33 ;
struct V_34 * V_36 ;
if ( ! V_96 ) {
if ( F_47 ( V_5 -> V_9 , V_93 ,
V_87 ) == true ) {
F_3 ( L_18
L_19 , V_95 ,
V_5 -> V_9 -> V_3 ) ;
return F_50 ( - V_62 ) ;
}
}
V_36 = F_2 ( sizeof( struct V_34 ) , V_6 ) ;
if ( ! V_36 ) {
F_3 ( L_20
L_21 ) ;
return F_50 ( - V_67 ) ;
}
V_33 = F_51 ( V_93 , V_95 , V_87 ) ;
if ( F_52 ( V_33 ) ) {
F_10 ( V_36 ) ;
return F_53 ( V_33 ) ;
}
F_4 ( & V_36 -> V_97 ) ;
F_4 ( & V_36 -> V_98 ) ;
F_4 ( & V_36 -> V_99 ) ;
F_7 ( & V_36 -> V_90 ) ;
F_54 ( & V_36 -> V_100 ) ;
F_55 ( & V_36 -> V_38 ) ;
V_36 -> V_36 = V_33 ;
V_36 -> V_5 = V_5 ;
F_15 ( & V_5 -> V_15 ) ;
F_34 ( & V_36 -> V_97 , & V_5 -> V_10 ) ;
V_5 -> V_101 ++ ;
if ( V_5 -> V_9 )
V_5 -> V_9 -> V_102 ++ ;
F_16 ( & V_5 -> V_15 ) ;
if ( V_96 ) {
V_36 -> V_96 = V_96 ;
F_15 ( & V_96 -> V_90 ) ;
F_34 ( & V_36 -> V_98 ,
& V_96 -> V_99 ) ;
F_16 ( & V_96 -> V_90 ) ;
}
F_17 ( L_22 ,
V_5 -> V_9 -> V_3 , V_33 -> V_103 , V_33 -> V_104 , V_5 -> V_4 ,
V_33 -> V_105 -> V_106 ) ;
return V_36 ;
}
static int F_56 (
struct V_34 * V_36 ,
struct V_1 * V_5 ,
struct V_32 * V_33 )
{
F_28 ( V_36 , V_5 , true ) ;
F_17 ( L_23 ,
V_5 -> V_9 -> V_3 , V_33 -> V_103 , V_33 -> V_104 , V_5 -> V_4 ,
V_33 -> V_105 -> V_106 ) ;
V_36 -> V_36 = NULL ;
V_36 -> V_5 = NULL ;
F_10 ( V_36 ) ;
return F_57 ( V_33 ) ;
}
int F_58 (
struct V_1 * V_5 ,
struct V_34 * V_36 )
{
struct V_32 * V_33 ;
struct V_34 * V_88 , * V_89 ;
int V_18 = 0 ;
V_33 = V_36 -> V_36 ;
if ( ! V_33 ) {
F_3 ( L_24
L_25 ) ;
return - V_71 ;
}
if ( ! V_36 -> V_96 ) {
F_46 (tpg_np_child, tpg_np_child_tmp,
&tpg_np->tpg_np_parent_list,
tpg_np_child_list) {
V_18 = F_58 ( V_5 , V_88 ) ;
if ( V_18 < 0 )
F_3 ( L_26
L_27 , V_18 ) ;
}
} else {
F_15 ( & V_36 -> V_96 -> V_90 ) ;
F_39 ( & V_36 -> V_98 ) ;
F_16 ( & V_36 -> V_96 -> V_90 ) ;
}
F_15 ( & V_5 -> V_15 ) ;
F_39 ( & V_36 -> V_97 ) ;
V_5 -> V_101 -- ;
if ( V_5 -> V_9 )
V_5 -> V_9 -> V_102 -- ;
F_16 ( & V_5 -> V_15 ) ;
return F_56 ( V_36 , V_5 , V_33 ) ;
}
int F_59 (
struct V_1 * V_5 ,
unsigned char * V_107 ,
T_3 V_108 ,
int V_68 )
{
return F_60 ( & V_5 -> V_21 ,
V_107 , V_108 , V_68 ) ;
}
int F_41 ( struct V_1 * V_5 , T_3 V_28 )
{
unsigned char V_109 [ 256 ] , V_110 [ 256 ] , * V_111 = NULL ;
int V_112 ;
struct V_16 * V_17 ;
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( ( V_28 != 1 ) && ( V_28 != 0 ) ) {
F_3 ( L_28
L_29 , V_28 ) ;
return - V_71 ;
}
memset ( V_109 , 0 , sizeof( V_109 ) ) ;
memset ( V_110 , 0 , sizeof( V_110 ) ) ;
V_17 = F_13 ( V_26 , V_5 -> V_24 ) ;
if ( ! V_17 )
return - V_71 ;
if ( V_28 ) {
snprintf ( V_109 , sizeof( V_109 ) , L_30 , V_17 -> V_72 ) ;
V_111 = strstr ( V_109 , V_73 ) ;
if ( ! V_111 )
goto V_25;
if ( ! strncmp ( V_111 + 4 , L_31 , 1 ) ) {
if ( ! strcmp ( V_109 , V_111 ) )
sprintf ( V_110 , L_30 , V_111 + 5 ) ;
else {
V_111 -- ;
* V_111 = '\0' ;
V_112 = sprintf ( V_110 , L_30 , V_109 ) ;
V_111 += 5 ;
sprintf ( V_110 + V_112 , L_30 , V_111 ) ;
}
} else {
V_111 -- ;
* V_111 = '\0' ;
sprintf ( V_110 , L_30 , V_109 ) ;
}
if ( F_14 ( V_17 , V_110 ) < 0 )
return - V_71 ;
} else {
snprintf ( V_109 , sizeof( V_109 ) , L_30 , V_17 -> V_72 ) ;
V_111 = strstr ( V_109 , V_73 ) ;
if ( V_111 )
goto V_25;
strncat ( V_109 , L_31 , strlen ( L_31 ) ) ;
strncat ( V_109 , V_73 , strlen ( V_73 ) ) ;
if ( F_14 ( V_17 , V_109 ) < 0 )
return - V_71 ;
}
V_25:
V_42 -> V_28 = V_28 ;
F_17 ( L_32 ,
V_42 -> V_28 ? L_33 : L_34 , V_5 -> V_4 ) ;
return 0 ;
}
int F_61 (
struct V_1 * V_5 ,
T_3 V_44 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( V_44 > V_113 ) {
F_3 ( L_35
L_36 , V_44 , V_113 ) ;
return - V_71 ;
} else if ( V_44 < V_114 ) {
F_3 ( L_37
L_38 , V_44 , V_114 ) ;
return - V_71 ;
}
V_42 -> V_44 = V_44 ;
F_17 ( L_39
L_40 , V_42 -> V_44 , V_5 -> V_4 ) ;
return 0 ;
}
int F_62 (
struct V_1 * V_5 ,
T_3 V_46 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( V_46 > V_115 ) {
F_3 ( L_41
L_42 , V_46 ,
V_115 ) ;
return - V_71 ;
} else if ( V_46 < V_116 ) {
F_3 ( L_43
L_44 , V_46 ,
V_116 ) ;
return - V_71 ;
}
V_42 -> V_46 = V_46 ;
F_17 ( L_45
L_46 , V_42 -> V_46 , V_5 -> V_4 ) ;
return 0 ;
}
int F_63 (
struct V_1 * V_5 ,
T_3 V_117 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( ( V_117 != 0 ) && ( V_117 != 1 ) ) {
F_3 ( L_47 , V_117 ) ;
return - V_71 ;
}
V_42 -> V_50 = V_117 ;
F_17 ( L_48 ,
V_5 -> V_4 , ( V_42 -> V_50 ) ? L_49 : L_50 ) ;
if ( V_117 == 1 && V_42 -> V_52 == 0 ) {
F_17 ( L_51
L_52 ) ;
V_42 -> V_52 = 1 ;
}
return 0 ;
}
int F_64 (
struct V_1 * V_5 ,
T_3 V_118 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( V_118 > V_119 ) {
F_3 ( L_53
L_42 , V_118 ,
V_119 ) ;
return - V_71 ;
} else if ( V_118 < V_120 ) {
F_3 ( L_54
L_44 , V_118 ,
V_120 ) ;
return - V_71 ;
}
V_42 -> V_48 = V_118 ;
F_17 ( L_55 ,
V_5 -> V_4 , V_42 -> V_48 ) ;
return 0 ;
}
int F_65 (
struct V_1 * V_5 ,
T_3 V_117 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( ( V_117 != 0 ) && ( V_117 != 1 ) ) {
F_3 ( L_47 , V_117 ) ;
return - V_71 ;
}
if ( V_42 -> V_50 == 1 && V_117 == 0 ) {
F_17 ( L_56
L_57 ) ;
return 0 ;
}
V_42 -> V_52 = V_117 ;
F_17 ( L_58
L_59 , V_5 -> V_4 , ( V_42 -> V_52 ) ?
L_49 : L_50 ) ;
return 0 ;
}
int F_66 (
struct V_1 * V_5 ,
T_3 V_117 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( ( V_117 != 0 ) && ( V_117 != 1 ) ) {
F_3 ( L_47 , V_117 ) ;
return - V_71 ;
}
V_42 -> V_54 = V_117 ;
F_17 ( L_60 ,
V_5 -> V_4 , ( V_42 -> V_54 ) ? L_61 : L_62 ) ;
return 0 ;
}
int F_67 (
struct V_1 * V_5 ,
T_3 V_117 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( ( V_117 != 0 ) && ( V_117 != 1 ) ) {
F_3 ( L_47 , V_117 ) ;
return - V_71 ;
}
V_42 -> V_56 = V_117 ;
F_17 ( L_63
L_64 , V_5 -> V_4 , ( V_42 -> V_56 ) ?
L_61 : L_62 ) ;
return 0 ;
}
int F_68 (
struct V_1 * V_5 ,
T_3 V_117 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( ( V_117 != 0 ) && ( V_117 != 1 ) ) {
F_3 ( L_47 , V_117 ) ;
return - V_71 ;
}
V_42 -> V_58 = V_117 ;
F_17 ( L_65
L_64 , V_5 -> V_4 , ( V_42 -> V_58 ) ?
L_61 : L_62 ) ;
return 0 ;
}
int F_69 (
struct V_1 * V_5 ,
T_3 V_60 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( ( V_60 != 0 ) && ( V_60 != 1 ) && ( V_60 != 2 ) ) {
F_3 ( L_66 , V_60 ) ;
return - V_71 ;
}
V_42 -> V_60 = V_60 ;
F_17 ( L_67 , V_5 -> V_4 , V_42 -> V_60 ) ;
return 0 ;
}
