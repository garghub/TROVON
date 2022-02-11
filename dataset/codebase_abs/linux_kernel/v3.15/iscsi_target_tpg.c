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
if ( V_5 -> V_7 != V_29 ) {
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
if ( V_40 )
V_36 -> V_36 -> V_41 = false ;
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
struct V_42 * V_43 = & V_5 -> V_27 ;
V_43 -> V_28 = V_44 ;
V_43 -> V_45 = V_46 ;
V_43 -> V_47 = V_48 ;
V_43 -> V_49 = V_50 ;
V_43 -> V_51 = V_52 ;
V_43 -> V_53 = V_54 ;
V_43 -> V_55 = V_56 ;
V_43 -> V_57 = V_58 ;
V_43 -> V_59 = V_60 ;
V_43 -> V_61 = V_62 ;
V_43 -> V_63 = V_64 ;
}
int F_33 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
if ( V_5 -> V_7 != V_8 ) {
F_3 ( L_5
L_6 , V_5 -> V_4 ) ;
return - V_65 ;
}
F_11 ( V_5 ) ;
if ( F_12 ( & V_5 -> V_24 ) < 0 )
goto V_66;
V_5 -> V_27 . V_5 = V_5 ;
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_67 ;
F_16 ( & V_5 -> V_14 ) ;
F_15 ( & V_3 -> V_37 ) ;
F_34 ( & V_5 -> V_11 , & V_3 -> V_68 ) ;
V_3 -> V_69 ++ ;
F_17 ( L_7 ,
V_3 -> V_3 , V_5 -> V_4 ) ;
F_16 ( & V_3 -> V_37 ) ;
return 0 ;
V_66:
if ( V_5 -> V_24 ) {
F_35 ( V_5 -> V_24 ) ;
V_5 -> V_24 = NULL ;
}
F_10 ( V_5 ) ;
return - V_70 ;
}
int F_36 (
struct V_2 * V_3 ,
struct V_1 * V_5 ,
int V_71 )
{
T_2 V_72 = V_5 -> V_7 ;
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_67 ;
F_16 ( & V_5 -> V_14 ) ;
F_30 ( V_5 , true ) ;
if ( F_37 ( V_5 , V_71 ) < 0 ) {
F_3 ( L_8
L_9 ,
V_5 -> V_4 ) ;
V_5 -> V_7 = V_72 ;
return - V_73 ;
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
V_3 -> V_69 -- ;
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
return - V_74 ;
}
V_17 = F_13 ( V_26 , V_5 -> V_24 ) ;
if ( ! V_17 ) {
F_16 ( & V_5 -> V_14 ) ;
return - V_74 ;
}
if ( V_5 -> V_27 . V_28 ) {
if ( ! strcmp ( V_17 -> V_75 , V_76 ) ) {
V_18 = F_14 ( V_17 , V_77 ) ;
if ( V_18 )
goto V_78;
}
V_18 = F_41 ( V_5 , 1 ) ;
if ( V_18 < 0 )
goto V_78;
}
V_5 -> V_7 = V_29 ;
F_16 ( & V_5 -> V_14 ) ;
F_15 ( & V_3 -> V_37 ) ;
V_3 -> V_79 ++ ;
F_17 ( L_13 ,
V_5 -> V_4 ) ;
F_16 ( & V_3 -> V_37 ) ;
return 0 ;
V_78:
F_16 ( & V_5 -> V_14 ) ;
return V_18 ;
}
int F_42 ( struct V_1 * V_5 , int V_71 )
{
struct V_2 * V_3 ;
T_2 V_72 = V_5 -> V_7 ;
F_15 ( & V_5 -> V_14 ) ;
if ( V_5 -> V_7 == V_67 ) {
F_3 ( L_14
L_15 , V_5 -> V_4 ) ;
F_16 ( & V_5 -> V_14 ) ;
return - V_74 ;
}
V_5 -> V_7 = V_67 ;
F_16 ( & V_5 -> V_14 ) ;
F_30 ( V_5 , false ) ;
if ( F_37 ( V_5 , V_71 ) < 0 ) {
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_72 ;
F_16 ( & V_5 -> V_14 ) ;
F_3 ( L_16
L_9 ,
V_5 -> V_4 ) ;
return - V_73 ;
}
V_3 = V_5 -> V_9 ;
if ( ! V_3 || ( V_5 == V_30 -> V_31 ) )
return 0 ;
F_15 ( & V_3 -> V_37 ) ;
V_3 -> V_79 -- ;
F_17 ( L_17 ,
V_5 -> V_4 ) ;
F_16 ( & V_3 -> V_37 ) ;
return 0 ;
}
struct V_80 * F_43 (
struct V_81 * V_82 )
{
struct V_83 * V_84 = V_82 -> V_84 ;
struct V_85 * V_86 = V_84 -> V_85 ;
struct V_87 * V_88 = F_44 ( V_86 , struct V_87 ,
V_85 ) ;
return & V_88 -> V_89 ;
}
struct V_34 * F_45 (
struct V_34 * V_36 ,
int V_90 )
{
struct V_34 * V_91 , * V_92 ;
F_15 ( & V_36 -> V_93 ) ;
F_46 (tpg_np_child, tpg_np_child_tmp,
&tpg_np->tpg_np_parent_list, tpg_np_child_list) {
if ( V_91 -> V_36 -> V_94 ==
V_90 ) {
F_16 ( & V_36 -> V_93 ) ;
return V_91 ;
}
}
F_16 ( & V_36 -> V_93 ) ;
return NULL ;
}
static bool F_47 (
struct V_2 * V_3 ,
struct V_95 * V_96 ,
int V_90 )
{
struct V_1 * V_5 ;
struct V_34 * V_36 ;
struct V_32 * V_33 ;
bool V_97 = false ;
F_15 ( & V_3 -> V_37 ) ;
F_21 (tpg, &tiqn->tiqn_tpg_list, tpg_list) {
F_15 ( & V_5 -> V_15 ) ;
F_21 (tpg_np, &tpg->tpg_gnp_list, tpg_np_list) {
V_33 = V_36 -> V_36 ;
V_97 = F_48 ( V_96 , V_33 ,
V_90 ) ;
if ( V_97 == true )
break;
}
F_16 ( & V_5 -> V_15 ) ;
}
F_16 ( & V_3 -> V_37 ) ;
return V_97 ;
}
struct V_34 * F_49 (
struct V_1 * V_5 ,
struct V_95 * V_96 ,
char * V_98 ,
struct V_34 * V_99 ,
int V_90 )
{
struct V_32 * V_33 ;
struct V_34 * V_36 ;
if ( ! V_99 ) {
if ( F_47 ( V_5 -> V_9 , V_96 ,
V_90 ) == true ) {
F_3 ( L_18
L_19 , V_98 ,
V_5 -> V_9 -> V_3 ) ;
return F_50 ( - V_65 ) ;
}
}
V_36 = F_2 ( sizeof( struct V_34 ) , V_6 ) ;
if ( ! V_36 ) {
F_3 ( L_20
L_21 ) ;
return F_50 ( - V_70 ) ;
}
V_33 = F_51 ( V_96 , V_98 , V_90 ) ;
if ( F_52 ( V_33 ) ) {
F_10 ( V_36 ) ;
return F_53 ( V_33 ) ;
}
F_4 ( & V_36 -> V_100 ) ;
F_4 ( & V_36 -> V_101 ) ;
F_4 ( & V_36 -> V_102 ) ;
F_7 ( & V_36 -> V_93 ) ;
F_54 ( & V_36 -> V_103 ) ;
F_55 ( & V_36 -> V_38 ) ;
V_36 -> V_36 = V_33 ;
V_33 -> V_36 = V_36 ;
V_36 -> V_5 = V_5 ;
F_15 ( & V_5 -> V_15 ) ;
F_34 ( & V_36 -> V_100 , & V_5 -> V_10 ) ;
V_5 -> V_104 ++ ;
if ( V_5 -> V_9 )
V_5 -> V_9 -> V_105 ++ ;
F_16 ( & V_5 -> V_15 ) ;
if ( V_99 ) {
V_36 -> V_99 = V_99 ;
F_15 ( & V_99 -> V_93 ) ;
F_34 ( & V_36 -> V_101 ,
& V_99 -> V_102 ) ;
F_16 ( & V_99 -> V_93 ) ;
}
F_17 ( L_22 ,
V_5 -> V_9 -> V_3 , V_33 -> V_106 , V_33 -> V_107 , V_5 -> V_4 ,
V_33 -> V_108 -> V_109 ) ;
return V_36 ;
}
static int F_56 (
struct V_34 * V_36 ,
struct V_1 * V_5 ,
struct V_32 * V_33 )
{
F_28 ( V_36 , V_5 , true ) ;
F_17 ( L_23 ,
V_5 -> V_9 -> V_3 , V_33 -> V_106 , V_33 -> V_107 , V_5 -> V_4 ,
V_33 -> V_108 -> V_109 ) ;
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
struct V_34 * V_91 , * V_92 ;
int V_18 = 0 ;
V_33 = V_36 -> V_36 ;
if ( ! V_33 ) {
F_3 ( L_24
L_25 ) ;
return - V_74 ;
}
if ( ! V_36 -> V_99 ) {
F_46 (tpg_np_child, tpg_np_child_tmp,
&tpg_np->tpg_np_parent_list,
tpg_np_child_list) {
V_18 = F_58 ( V_5 , V_91 ) ;
if ( V_18 < 0 )
F_3 ( L_26
L_27 , V_18 ) ;
}
} else {
F_15 ( & V_36 -> V_99 -> V_93 ) ;
F_39 ( & V_36 -> V_101 ) ;
F_16 ( & V_36 -> V_99 -> V_93 ) ;
}
F_15 ( & V_5 -> V_15 ) ;
F_39 ( & V_36 -> V_100 ) ;
V_5 -> V_104 -- ;
if ( V_5 -> V_9 )
V_5 -> V_9 -> V_105 -- ;
F_16 ( & V_5 -> V_15 ) ;
return F_56 ( V_36 , V_5 , V_33 ) ;
}
int F_59 (
struct V_1 * V_5 ,
unsigned char * V_110 ,
T_3 V_111 ,
int V_71 )
{
return F_60 ( & V_5 -> V_21 ,
V_110 , V_111 , V_71 ) ;
}
int F_41 ( struct V_1 * V_5 , T_3 V_28 )
{
unsigned char V_112 [ 256 ] , V_113 [ 256 ] , * V_114 = NULL ;
int V_115 ;
struct V_16 * V_17 ;
struct V_42 * V_43 = & V_5 -> V_27 ;
if ( ( V_28 != 1 ) && ( V_28 != 0 ) ) {
F_3 ( L_28
L_29 , V_28 ) ;
return - V_74 ;
}
memset ( V_112 , 0 , sizeof( V_112 ) ) ;
memset ( V_113 , 0 , sizeof( V_113 ) ) ;
V_17 = F_13 ( V_26 , V_5 -> V_24 ) ;
if ( ! V_17 )
return - V_74 ;
if ( V_28 ) {
snprintf ( V_112 , sizeof( V_112 ) , L_30 , V_17 -> V_75 ) ;
V_114 = strstr ( V_112 , V_76 ) ;
if ( ! V_114 )
goto V_25;
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
return - V_74 ;
} else {
snprintf ( V_112 , sizeof( V_112 ) , L_30 , V_17 -> V_75 ) ;
V_114 = strstr ( V_112 , V_76 ) ;
if ( V_114 )
goto V_25;
strncat ( V_112 , L_31 , strlen ( L_31 ) ) ;
strncat ( V_112 , V_76 , strlen ( V_76 ) ) ;
if ( F_14 ( V_17 , V_112 ) < 0 )
return - V_74 ;
}
V_25:
V_43 -> V_28 = V_28 ;
F_17 ( L_32 ,
V_43 -> V_28 ? L_33 : L_34 , V_5 -> V_4 ) ;
return 0 ;
}
int F_61 (
struct V_1 * V_5 ,
T_3 V_45 )
{
struct V_42 * V_43 = & V_5 -> V_27 ;
if ( V_45 > V_116 ) {
F_3 ( L_35
L_36 , V_45 , V_116 ) ;
return - V_74 ;
} else if ( V_45 < V_117 ) {
F_3 ( L_37
L_38 , V_45 , V_117 ) ;
return - V_74 ;
}
V_43 -> V_45 = V_45 ;
F_17 ( L_39
L_40 , V_43 -> V_45 , V_5 -> V_4 ) ;
return 0 ;
}
int F_62 (
struct V_1 * V_5 ,
T_3 V_47 )
{
struct V_42 * V_43 = & V_5 -> V_27 ;
if ( V_47 > V_118 ) {
F_3 ( L_41
L_42 , V_47 ,
V_118 ) ;
return - V_74 ;
} else if ( V_47 < V_119 ) {
F_3 ( L_43
L_44 , V_47 ,
V_119 ) ;
return - V_74 ;
}
V_43 -> V_47 = V_47 ;
F_17 ( L_45
L_46 , V_43 -> V_47 , V_5 -> V_4 ) ;
return 0 ;
}
int F_63 (
struct V_1 * V_5 ,
T_3 V_120 )
{
struct V_42 * V_43 = & V_5 -> V_27 ;
if ( ( V_120 != 0 ) && ( V_120 != 1 ) ) {
F_3 ( L_47 , V_120 ) ;
return - V_74 ;
}
V_43 -> V_51 = V_120 ;
F_17 ( L_48 ,
V_5 -> V_4 , ( V_43 -> V_51 ) ? L_49 : L_50 ) ;
if ( V_120 == 1 && V_43 -> V_53 == 0 ) {
F_17 ( L_51
L_52 ) ;
V_43 -> V_53 = 1 ;
}
return 0 ;
}
int F_64 (
struct V_1 * V_5 ,
T_3 V_121 )
{
struct V_42 * V_43 = & V_5 -> V_27 ;
if ( V_121 > V_122 ) {
F_3 ( L_53
L_42 , V_121 ,
V_122 ) ;
return - V_74 ;
} else if ( V_121 < V_123 ) {
F_3 ( L_54
L_44 , V_121 ,
V_123 ) ;
return - V_74 ;
}
V_43 -> V_49 = V_121 ;
F_17 ( L_55 ,
V_5 -> V_4 , V_43 -> V_49 ) ;
return 0 ;
}
int F_65 (
struct V_1 * V_5 ,
T_3 V_120 )
{
struct V_42 * V_43 = & V_5 -> V_27 ;
if ( ( V_120 != 0 ) && ( V_120 != 1 ) ) {
F_3 ( L_47 , V_120 ) ;
return - V_74 ;
}
if ( V_43 -> V_51 == 1 && V_120 == 0 ) {
F_17 ( L_56
L_57 ) ;
return 0 ;
}
V_43 -> V_53 = V_120 ;
F_17 ( L_58
L_59 , V_5 -> V_4 , ( V_43 -> V_53 ) ?
L_49 : L_50 ) ;
return 0 ;
}
int F_66 (
struct V_1 * V_5 ,
T_3 V_120 )
{
struct V_42 * V_43 = & V_5 -> V_27 ;
if ( ( V_120 != 0 ) && ( V_120 != 1 ) ) {
F_3 ( L_47 , V_120 ) ;
return - V_74 ;
}
V_43 -> V_55 = V_120 ;
F_17 ( L_60 ,
V_5 -> V_4 , ( V_43 -> V_55 ) ? L_61 : L_62 ) ;
return 0 ;
}
int F_67 (
struct V_1 * V_5 ,
T_3 V_120 )
{
struct V_42 * V_43 = & V_5 -> V_27 ;
if ( ( V_120 != 0 ) && ( V_120 != 1 ) ) {
F_3 ( L_47 , V_120 ) ;
return - V_74 ;
}
V_43 -> V_57 = V_120 ;
F_17 ( L_63
L_64 , V_5 -> V_4 , ( V_43 -> V_57 ) ?
L_61 : L_62 ) ;
return 0 ;
}
int F_68 (
struct V_1 * V_5 ,
T_3 V_120 )
{
struct V_42 * V_43 = & V_5 -> V_27 ;
if ( ( V_120 != 0 ) && ( V_120 != 1 ) ) {
F_3 ( L_47 , V_120 ) ;
return - V_74 ;
}
V_43 -> V_59 = V_120 ;
F_17 ( L_65
L_64 , V_5 -> V_4 , ( V_43 -> V_59 ) ?
L_61 : L_62 ) ;
return 0 ;
}
int F_69 (
struct V_1 * V_5 ,
T_3 V_61 )
{
struct V_42 * V_43 = & V_5 -> V_27 ;
if ( ( V_61 != 0 ) && ( V_61 != 1 ) && ( V_61 != 2 ) ) {
F_3 ( L_66 , V_61 ) ;
return - V_74 ;
}
V_43 -> V_61 = V_61 ;
F_17 ( L_67 , V_5 -> V_4 , V_43 -> V_61 ) ;
return 0 ;
}
int F_70 (
struct V_1 * V_5 ,
T_3 V_120 )
{
struct V_42 * V_43 = & V_5 -> V_27 ;
if ( ( V_120 != 0 ) && ( V_120 != 1 ) ) {
F_3 ( L_47 , V_120 ) ;
return - V_74 ;
}
V_43 -> V_63 = V_120 ;
F_17 ( L_68
L_64 , V_5 -> V_4 , ( V_43 -> V_63 ) ?
L_61 : L_62 ) ;
return 0 ;
}
