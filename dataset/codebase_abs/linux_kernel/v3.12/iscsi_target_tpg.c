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
}
int F_33 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
if ( V_5 -> V_7 != V_8 ) {
F_3 ( L_5
L_6 , V_5 -> V_4 ) ;
return - V_58 ;
}
F_11 ( V_5 ) ;
if ( F_12 ( & V_5 -> V_24 ) < 0 )
goto V_59;
F_34 ( V_5 ) -> V_5 = V_5 ;
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_60 ;
F_16 ( & V_5 -> V_14 ) ;
F_15 ( & V_3 -> V_37 ) ;
F_35 ( & V_5 -> V_11 , & V_3 -> V_61 ) ;
V_3 -> V_62 ++ ;
F_17 ( L_7 ,
V_3 -> V_3 , V_5 -> V_4 ) ;
F_16 ( & V_3 -> V_37 ) ;
return 0 ;
V_59:
if ( V_5 -> V_24 ) {
F_36 ( V_5 -> V_24 ) ;
V_5 -> V_24 = NULL ;
}
F_10 ( V_5 ) ;
return - V_63 ;
}
int F_37 (
struct V_2 * V_3 ,
struct V_1 * V_5 ,
int V_64 )
{
T_2 V_65 = V_5 -> V_7 ;
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_60 ;
F_16 ( & V_5 -> V_14 ) ;
F_30 ( V_5 , true ) ;
if ( F_38 ( V_5 , V_64 ) < 0 ) {
F_3 ( L_8
L_9 ,
V_5 -> V_4 ) ;
V_5 -> V_7 = V_65 ;
return - V_66 ;
}
F_39 ( & V_5 -> V_21 ) ;
if ( V_5 -> V_24 ) {
F_36 ( V_5 -> V_24 ) ;
V_5 -> V_24 = NULL ;
}
F_18 ( & V_5 -> V_21 ) ;
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_8 ;
F_16 ( & V_5 -> V_14 ) ;
F_15 ( & V_3 -> V_37 ) ;
V_3 -> V_62 -- ;
F_40 ( & V_5 -> V_11 ) ;
F_16 ( & V_3 -> V_37 ) ;
F_17 ( L_10 ,
V_3 -> V_3 , V_5 -> V_4 ) ;
F_10 ( V_5 ) ;
return 0 ;
}
int F_41 ( struct V_1 * V_5 )
{
struct V_16 * V_17 ;
struct V_2 * V_3 = V_5 -> V_9 ;
int V_18 ;
F_15 ( & V_5 -> V_14 ) ;
if ( V_5 -> V_7 == V_29 ) {
F_3 ( L_11
L_12 , V_5 -> V_4 ) ;
F_16 ( & V_5 -> V_14 ) ;
return - V_67 ;
}
V_17 = F_13 ( V_26 , V_5 -> V_24 ) ;
if ( ! V_17 ) {
F_16 ( & V_5 -> V_14 ) ;
return - V_67 ;
}
if ( F_34 ( V_5 ) -> V_28 ) {
if ( ! strcmp ( V_17 -> V_68 , V_69 ) ) {
V_18 = F_14 ( V_17 , V_70 ) ;
if ( V_18 )
goto V_71;
}
V_18 = F_42 ( V_5 , 1 ) ;
if ( V_18 < 0 )
goto V_71;
}
V_5 -> V_7 = V_29 ;
F_16 ( & V_5 -> V_14 ) ;
F_15 ( & V_3 -> V_37 ) ;
V_3 -> V_72 ++ ;
F_17 ( L_13 ,
V_5 -> V_4 ) ;
F_16 ( & V_3 -> V_37 ) ;
return 0 ;
V_71:
F_16 ( & V_5 -> V_14 ) ;
return V_18 ;
}
int F_43 ( struct V_1 * V_5 , int V_64 )
{
struct V_2 * V_3 ;
T_2 V_65 = V_5 -> V_7 ;
F_15 ( & V_5 -> V_14 ) ;
if ( V_5 -> V_7 == V_60 ) {
F_3 ( L_14
L_15 , V_5 -> V_4 ) ;
F_16 ( & V_5 -> V_14 ) ;
return - V_67 ;
}
V_5 -> V_7 = V_60 ;
F_16 ( & V_5 -> V_14 ) ;
F_30 ( V_5 , false ) ;
if ( F_38 ( V_5 , V_64 ) < 0 ) {
F_15 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_65 ;
F_16 ( & V_5 -> V_14 ) ;
F_3 ( L_16
L_9 ,
V_5 -> V_4 ) ;
return - V_66 ;
}
V_3 = V_5 -> V_9 ;
if ( ! V_3 || ( V_5 == V_30 -> V_31 ) )
return 0 ;
F_15 ( & V_3 -> V_37 ) ;
V_3 -> V_72 -- ;
F_17 ( L_17 ,
V_5 -> V_4 ) ;
F_16 ( & V_3 -> V_37 ) ;
return 0 ;
}
struct V_73 * F_44 (
struct V_74 * V_75 )
{
struct V_76 * V_77 = V_75 -> V_77 ;
struct V_78 * V_79 = V_77 -> V_78 ;
struct V_80 * V_81 = F_45 ( V_79 , struct V_80 ,
V_78 ) ;
return & V_81 -> V_82 ;
}
struct V_34 * F_46 (
struct V_34 * V_36 ,
int V_83 )
{
struct V_34 * V_84 , * V_85 ;
F_15 ( & V_36 -> V_86 ) ;
F_47 (tpg_np_child, tpg_np_child_tmp,
&tpg_np->tpg_np_parent_list, tpg_np_child_list) {
if ( V_84 -> V_36 -> V_87 ==
V_83 ) {
F_16 ( & V_36 -> V_86 ) ;
return V_84 ;
}
}
F_16 ( & V_36 -> V_86 ) ;
return NULL ;
}
static bool F_48 (
struct V_2 * V_3 ,
struct V_88 * V_89 ,
int V_83 )
{
struct V_1 * V_5 ;
struct V_34 * V_36 ;
struct V_32 * V_33 ;
bool V_90 = false ;
F_15 ( & V_3 -> V_37 ) ;
F_21 (tpg, &tiqn->tiqn_tpg_list, tpg_list) {
F_15 ( & V_5 -> V_15 ) ;
F_21 (tpg_np, &tpg->tpg_gnp_list, tpg_np_list) {
V_33 = V_36 -> V_36 ;
V_90 = F_49 ( V_89 , V_33 ,
V_83 ) ;
if ( V_90 == true )
break;
}
F_16 ( & V_5 -> V_15 ) ;
}
F_16 ( & V_3 -> V_37 ) ;
return V_90 ;
}
struct V_34 * F_50 (
struct V_1 * V_5 ,
struct V_88 * V_89 ,
char * V_91 ,
struct V_34 * V_92 ,
int V_83 )
{
struct V_32 * V_33 ;
struct V_34 * V_36 ;
if ( ! V_92 ) {
if ( F_48 ( V_5 -> V_9 , V_89 ,
V_83 ) == true ) {
F_3 ( L_18
L_19 , V_91 ,
V_5 -> V_9 -> V_3 ) ;
return F_51 ( - V_58 ) ;
}
}
V_36 = F_2 ( sizeof( struct V_34 ) , V_6 ) ;
if ( ! V_36 ) {
F_3 ( L_20
L_21 ) ;
return F_51 ( - V_63 ) ;
}
V_33 = F_52 ( V_89 , V_91 , V_83 ) ;
if ( F_53 ( V_33 ) ) {
F_10 ( V_36 ) ;
return F_54 ( V_33 ) ;
}
F_4 ( & V_36 -> V_93 ) ;
F_4 ( & V_36 -> V_94 ) ;
F_4 ( & V_36 -> V_95 ) ;
F_7 ( & V_36 -> V_86 ) ;
F_55 ( & V_36 -> V_96 ) ;
F_56 ( & V_36 -> V_38 ) ;
V_36 -> V_36 = V_33 ;
V_36 -> V_5 = V_5 ;
F_15 ( & V_5 -> V_15 ) ;
F_35 ( & V_36 -> V_93 , & V_5 -> V_10 ) ;
V_5 -> V_97 ++ ;
if ( V_5 -> V_9 )
V_5 -> V_9 -> V_98 ++ ;
F_16 ( & V_5 -> V_15 ) ;
if ( V_92 ) {
V_36 -> V_92 = V_92 ;
F_15 ( & V_92 -> V_86 ) ;
F_35 ( & V_36 -> V_94 ,
& V_92 -> V_95 ) ;
F_16 ( & V_92 -> V_86 ) ;
}
F_17 ( L_22 ,
V_5 -> V_9 -> V_3 , V_33 -> V_99 , V_33 -> V_100 , V_5 -> V_4 ,
V_33 -> V_101 -> V_102 ) ;
return V_36 ;
}
static int F_57 (
struct V_34 * V_36 ,
struct V_1 * V_5 ,
struct V_32 * V_33 )
{
F_28 ( V_36 , V_5 , true ) ;
F_17 ( L_23 ,
V_5 -> V_9 -> V_3 , V_33 -> V_99 , V_33 -> V_100 , V_5 -> V_4 ,
V_33 -> V_101 -> V_102 ) ;
V_36 -> V_36 = NULL ;
V_36 -> V_5 = NULL ;
F_10 ( V_36 ) ;
return F_58 ( V_33 ) ;
}
int F_59 (
struct V_1 * V_5 ,
struct V_34 * V_36 )
{
struct V_32 * V_33 ;
struct V_34 * V_84 , * V_85 ;
int V_18 = 0 ;
V_33 = V_36 -> V_36 ;
if ( ! V_33 ) {
F_3 ( L_24
L_25 ) ;
return - V_67 ;
}
if ( ! V_36 -> V_92 ) {
F_47 (tpg_np_child, tpg_np_child_tmp,
&tpg_np->tpg_np_parent_list,
tpg_np_child_list) {
V_18 = F_59 ( V_5 , V_84 ) ;
if ( V_18 < 0 )
F_3 ( L_26
L_27 , V_18 ) ;
}
} else {
F_15 ( & V_36 -> V_92 -> V_86 ) ;
F_40 ( & V_36 -> V_94 ) ;
F_16 ( & V_36 -> V_92 -> V_86 ) ;
}
F_15 ( & V_5 -> V_15 ) ;
F_40 ( & V_36 -> V_93 ) ;
V_5 -> V_97 -- ;
if ( V_5 -> V_9 )
V_5 -> V_9 -> V_98 -- ;
F_16 ( & V_5 -> V_15 ) ;
return F_57 ( V_36 , V_5 , V_33 ) ;
}
int F_60 (
struct V_1 * V_5 ,
unsigned char * V_103 ,
T_3 V_104 ,
int V_64 )
{
return F_61 ( & V_5 -> V_21 ,
V_103 , V_104 , V_64 ) ;
}
int F_42 ( struct V_1 * V_5 , T_3 V_28 )
{
unsigned char V_105 [ 256 ] , V_106 [ 256 ] , * V_107 = NULL ;
int V_108 ;
struct V_16 * V_17 ;
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( ( V_28 != 1 ) && ( V_28 != 0 ) ) {
F_3 ( L_28
L_29 , V_28 ) ;
return - V_67 ;
}
memset ( V_105 , 0 , sizeof( V_105 ) ) ;
memset ( V_106 , 0 , sizeof( V_106 ) ) ;
V_17 = F_13 ( V_26 , V_5 -> V_24 ) ;
if ( ! V_17 )
return - V_67 ;
if ( V_28 ) {
snprintf ( V_105 , sizeof( V_105 ) , L_30 , V_17 -> V_68 ) ;
V_107 = strstr ( V_105 , V_69 ) ;
if ( ! V_107 )
goto V_25;
if ( ! strncmp ( V_107 + 4 , L_31 , 1 ) ) {
if ( ! strcmp ( V_105 , V_107 ) )
sprintf ( V_106 , L_30 , V_107 + 5 ) ;
else {
V_107 -- ;
* V_107 = '\0' ;
V_108 = sprintf ( V_106 , L_30 , V_105 ) ;
V_107 += 5 ;
sprintf ( V_106 + V_108 , L_30 , V_107 ) ;
}
} else {
V_107 -- ;
* V_107 = '\0' ;
sprintf ( V_106 , L_30 , V_105 ) ;
}
if ( F_14 ( V_17 , V_106 ) < 0 )
return - V_67 ;
} else {
snprintf ( V_105 , sizeof( V_105 ) , L_30 , V_17 -> V_68 ) ;
V_107 = strstr ( V_105 , V_69 ) ;
if ( V_107 )
goto V_25;
strncat ( V_105 , L_31 , strlen ( L_31 ) ) ;
strncat ( V_105 , V_69 , strlen ( V_69 ) ) ;
if ( F_14 ( V_17 , V_105 ) < 0 )
return - V_67 ;
}
V_25:
V_42 -> V_28 = V_28 ;
F_17 ( L_32 ,
V_42 -> V_28 ? L_33 : L_34 , V_5 -> V_4 ) ;
return 0 ;
}
int F_62 (
struct V_1 * V_5 ,
T_3 V_44 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( V_44 > V_109 ) {
F_3 ( L_35
L_36 , V_44 , V_109 ) ;
return - V_67 ;
} else if ( V_44 < V_110 ) {
F_3 ( L_37
L_38 , V_44 , V_110 ) ;
return - V_67 ;
}
V_42 -> V_44 = V_44 ;
F_17 ( L_39
L_40 , V_42 -> V_44 , V_5 -> V_4 ) ;
return 0 ;
}
int F_63 (
struct V_1 * V_5 ,
T_3 V_46 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( V_46 > V_111 ) {
F_3 ( L_41
L_42 , V_46 ,
V_111 ) ;
return - V_67 ;
} else if ( V_46 < V_112 ) {
F_3 ( L_43
L_44 , V_46 ,
V_112 ) ;
return - V_67 ;
}
V_42 -> V_46 = V_46 ;
F_17 ( L_45
L_46 , V_42 -> V_46 , V_5 -> V_4 ) ;
return 0 ;
}
int F_64 (
struct V_1 * V_5 ,
T_3 V_113 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( ( V_113 != 0 ) && ( V_113 != 1 ) ) {
F_3 ( L_47 , V_113 ) ;
return - V_67 ;
}
V_42 -> V_50 = V_113 ;
F_17 ( L_48 ,
V_5 -> V_4 , ( V_42 -> V_50 ) ? L_49 : L_50 ) ;
if ( V_113 == 1 && V_42 -> V_52 == 0 ) {
F_17 ( L_51
L_52 ) ;
V_42 -> V_52 = 1 ;
}
return 0 ;
}
int F_65 (
struct V_1 * V_5 ,
T_3 V_114 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( V_114 > V_115 ) {
F_3 ( L_53
L_42 , V_114 ,
V_115 ) ;
return - V_67 ;
} else if ( V_114 < V_116 ) {
F_3 ( L_54
L_44 , V_114 ,
V_116 ) ;
return - V_67 ;
}
V_42 -> V_48 = V_114 ;
F_17 ( L_55 ,
V_5 -> V_4 , V_42 -> V_48 ) ;
return 0 ;
}
int F_66 (
struct V_1 * V_5 ,
T_3 V_113 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( ( V_113 != 0 ) && ( V_113 != 1 ) ) {
F_3 ( L_47 , V_113 ) ;
return - V_67 ;
}
if ( V_42 -> V_50 == 1 && V_113 == 0 ) {
F_17 ( L_56
L_57 ) ;
return 0 ;
}
V_42 -> V_52 = V_113 ;
F_17 ( L_58
L_59 , V_5 -> V_4 , ( V_42 -> V_52 ) ?
L_49 : L_50 ) ;
return 0 ;
}
int F_67 (
struct V_1 * V_5 ,
T_3 V_113 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( ( V_113 != 0 ) && ( V_113 != 1 ) ) {
F_3 ( L_47 , V_113 ) ;
return - V_67 ;
}
V_42 -> V_54 = V_113 ;
F_17 ( L_60 ,
V_5 -> V_4 , ( V_42 -> V_54 ) ? L_61 : L_62 ) ;
return 0 ;
}
int F_68 (
struct V_1 * V_5 ,
T_3 V_113 )
{
struct V_41 * V_42 = & V_5 -> V_27 ;
if ( ( V_113 != 0 ) && ( V_113 != 1 ) ) {
F_3 ( L_47 , V_113 ) ;
return - V_67 ;
}
V_42 -> V_56 = V_113 ;
F_17 ( L_63
L_64 , V_5 -> V_4 , ( V_42 -> V_56 ) ?
L_61 : L_62 ) ;
return 0 ;
}
