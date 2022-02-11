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
F_5 ( & V_5 -> V_13 ) ;
F_6 ( & V_5 -> V_14 ) ;
F_6 ( & V_5 -> V_15 ) ;
return V_5 ;
}
int F_7 ( void )
{
struct V_16 * V_17 ;
struct V_1 * V_5 ;
int V_18 ;
V_5 = F_1 ( NULL , 1 ) ;
if ( ! V_5 ) {
F_3 ( L_1 ) ;
return - 1 ;
}
V_18 = F_8 (
& V_19 -> V_20 ,
NULL , & V_5 -> V_21 , ( void * ) V_5 ,
V_22 ) ;
if ( V_18 < 0 ) {
F_9 ( V_5 ) ;
return - 1 ;
}
V_5 -> V_23 = 1 ;
F_10 ( V_5 ) ;
if ( F_11 ( & V_5 -> V_24 ) < 0 )
goto V_25;
V_17 = F_12 ( V_26 , V_5 -> V_24 ) ;
if ( ! V_17 )
goto V_25;
if ( F_13 ( V_17 , L_2 ) < 0 )
goto V_25;
V_5 -> V_27 . V_28 = 0 ;
F_14 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_29 ;
F_15 ( & V_5 -> V_14 ) ;
V_30 -> V_31 = V_5 ;
F_16 ( L_3 ) ;
return 0 ;
V_25:
if ( V_5 -> V_23 == 1 )
F_17 ( & V_5 -> V_21 ) ;
F_9 ( V_5 ) ;
return - 1 ;
}
void F_18 ( void )
{
struct V_1 * V_5 = V_30 -> V_31 ;
if ( ! V_5 )
return;
F_17 ( & V_5 -> V_21 ) ;
F_9 ( V_5 ) ;
V_30 -> V_31 = NULL ;
}
struct V_1 * F_19 (
struct V_2 * V_3 ,
struct V_32 * V_33 )
{
struct V_1 * V_5 = NULL ;
struct V_34 * V_35 ;
F_14 ( & V_3 -> V_36 ) ;
F_20 (tpg, &tiqn->tiqn_tpg_list, tpg_list) {
F_14 ( & V_5 -> V_14 ) ;
if ( V_5 -> V_7 == V_8 ) {
F_15 ( & V_5 -> V_14 ) ;
continue;
}
F_15 ( & V_5 -> V_14 ) ;
F_14 ( & V_5 -> V_15 ) ;
F_20 (tpg_np, &tpg->tpg_gnp_list, tpg_np_list) {
if ( V_35 -> V_35 == V_33 ) {
F_15 ( & V_5 -> V_15 ) ;
F_15 ( & V_3 -> V_36 ) ;
return V_5 ;
}
}
F_15 ( & V_5 -> V_15 ) ;
}
F_15 ( & V_3 -> V_36 ) ;
return NULL ;
}
int F_21 (
struct V_1 * V_5 )
{
int V_18 ;
V_18 = F_22 ( & V_5 -> V_12 ) ;
return ( ( V_18 != 0 ) || F_23 ( V_37 ) ) ? - 1 : 0 ;
}
void F_24 ( struct V_1 * V_5 )
{
F_25 ( & V_5 -> V_12 ) ;
}
static void F_26 (
struct V_34 * V_35 ,
struct V_1 * V_5 )
{
if ( ! V_35 -> V_35 ) {
F_3 ( L_4 ) ;
return;
}
F_27 ( V_35 -> V_35 , V_35 , V_5 ) ;
}
void F_28 (
struct V_1 * V_5 )
{
struct V_34 * V_35 ;
F_14 ( & V_5 -> V_15 ) ;
F_20 (tpg_np, &tpg->tpg_gnp_list, tpg_np_list) {
if ( ! V_35 -> V_35 ) {
F_3 ( L_4 ) ;
continue;
}
F_15 ( & V_5 -> V_15 ) ;
F_26 ( V_35 , V_5 ) ;
F_14 ( & V_5 -> V_15 ) ;
}
F_15 ( & V_5 -> V_15 ) ;
}
void F_29 ( struct V_1 * V_5 )
{
F_30 ( V_5 -> V_24 ) ;
}
static void F_10 ( struct V_1 * V_5 )
{
struct V_38 * V_39 = & V_5 -> V_27 ;
V_39 -> V_28 = V_40 ;
V_39 -> V_41 = V_42 ;
V_39 -> V_43 = V_44 ;
V_39 -> V_45 = V_46 ;
V_39 -> V_47 = V_48 ;
V_39 -> V_49 = V_50 ;
V_39 -> V_51 = V_52 ;
V_39 -> V_53 = V_54 ;
}
int F_31 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
if ( V_5 -> V_7 != V_8 ) {
F_3 ( L_5
L_6 , V_5 -> V_4 ) ;
return - V_55 ;
}
F_10 ( V_5 ) ;
if ( F_11 ( & V_5 -> V_24 ) < 0 )
goto V_56;
F_32 ( V_5 ) -> V_5 = V_5 ;
F_14 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_57 ;
F_15 ( & V_5 -> V_14 ) ;
F_14 ( & V_3 -> V_36 ) ;
F_33 ( & V_5 -> V_11 , & V_3 -> V_58 ) ;
V_3 -> V_59 ++ ;
F_16 ( L_7 ,
V_3 -> V_3 , V_5 -> V_4 ) ;
F_15 ( & V_3 -> V_36 ) ;
return 0 ;
V_56:
if ( V_5 -> V_24 ) {
F_34 ( V_5 -> V_24 ) ;
V_5 -> V_24 = NULL ;
}
F_9 ( V_5 ) ;
return - V_60 ;
}
int F_35 (
struct V_2 * V_3 ,
struct V_1 * V_5 ,
int V_61 )
{
T_2 V_62 = V_5 -> V_7 ;
F_14 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_57 ;
F_15 ( & V_5 -> V_14 ) ;
if ( F_36 ( V_5 , V_61 ) < 0 ) {
F_3 ( L_8
L_9 ,
V_5 -> V_4 ) ;
V_5 -> V_7 = V_62 ;
return - V_63 ;
}
F_37 ( & V_5 -> V_21 ) ;
if ( V_5 -> V_24 ) {
F_34 ( V_5 -> V_24 ) ;
V_5 -> V_24 = NULL ;
}
F_17 ( & V_5 -> V_21 ) ;
F_14 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_8 ;
F_15 ( & V_5 -> V_14 ) ;
F_14 ( & V_3 -> V_36 ) ;
V_3 -> V_59 -- ;
F_38 ( & V_5 -> V_11 ) ;
F_15 ( & V_3 -> V_36 ) ;
F_16 ( L_10 ,
V_3 -> V_3 , V_5 -> V_4 ) ;
F_9 ( V_5 ) ;
return 0 ;
}
int F_39 ( struct V_1 * V_5 )
{
struct V_16 * V_17 ;
struct V_2 * V_3 = V_5 -> V_9 ;
F_14 ( & V_5 -> V_14 ) ;
if ( V_5 -> V_7 == V_29 ) {
F_3 ( L_11
L_12 , V_5 -> V_4 ) ;
F_15 ( & V_5 -> V_14 ) ;
return - V_64 ;
}
V_17 = F_12 ( V_26 , V_5 -> V_24 ) ;
if ( ! V_17 ) {
F_15 ( & V_5 -> V_14 ) ;
return - V_60 ;
}
if ( F_32 ( V_5 ) -> V_28 ) {
if ( ! strcmp ( V_17 -> V_65 , V_66 ) )
if ( F_13 ( V_17 , V_67 ) < 0 ) {
F_15 ( & V_5 -> V_14 ) ;
return - V_60 ;
}
if ( F_40 ( V_5 , 1 ) < 0 ) {
F_15 ( & V_5 -> V_14 ) ;
return - V_60 ;
}
}
V_5 -> V_7 = V_29 ;
F_15 ( & V_5 -> V_14 ) ;
F_14 ( & V_3 -> V_36 ) ;
V_3 -> V_68 ++ ;
F_16 ( L_13 ,
V_5 -> V_4 ) ;
F_15 ( & V_3 -> V_36 ) ;
return 0 ;
}
int F_41 ( struct V_1 * V_5 , int V_61 )
{
struct V_2 * V_3 ;
T_2 V_62 = V_5 -> V_7 ;
F_14 ( & V_5 -> V_14 ) ;
if ( V_5 -> V_7 == V_57 ) {
F_3 ( L_14
L_15 , V_5 -> V_4 ) ;
F_15 ( & V_5 -> V_14 ) ;
return - V_64 ;
}
V_5 -> V_7 = V_57 ;
F_15 ( & V_5 -> V_14 ) ;
F_28 ( V_5 ) ;
if ( F_36 ( V_5 , V_61 ) < 0 ) {
F_14 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = V_62 ;
F_15 ( & V_5 -> V_14 ) ;
F_3 ( L_16
L_9 ,
V_5 -> V_4 ) ;
return - V_63 ;
}
V_3 = V_5 -> V_9 ;
if ( ! V_3 || ( V_5 == V_30 -> V_31 ) )
return 0 ;
F_14 ( & V_3 -> V_36 ) ;
V_3 -> V_68 -- ;
F_16 ( L_17 ,
V_5 -> V_4 ) ;
F_15 ( & V_3 -> V_36 ) ;
return 0 ;
}
struct V_69 * F_42 (
struct V_70 * V_71 )
{
struct V_72 * V_73 = V_71 -> V_73 ;
struct V_74 * V_75 = V_73 -> V_74 ;
struct V_76 * V_77 = F_43 ( V_75 , struct V_76 ,
V_74 ) ;
return & V_77 -> V_78 ;
}
struct V_34 * F_44 (
struct V_34 * V_35 ,
int V_79 )
{
struct V_34 * V_80 , * V_81 ;
F_14 ( & V_35 -> V_82 ) ;
F_45 (tpg_np_child, tpg_np_child_tmp,
&tpg_np->tpg_np_parent_list, tpg_np_child_list) {
if ( V_80 -> V_35 -> V_83 ==
V_79 ) {
F_15 ( & V_35 -> V_82 ) ;
return V_80 ;
}
}
F_15 ( & V_35 -> V_82 ) ;
return NULL ;
}
struct V_34 * F_46 (
struct V_1 * V_5 ,
struct V_84 * V_85 ,
char * V_86 ,
struct V_34 * V_87 ,
int V_79 )
{
struct V_32 * V_33 ;
struct V_34 * V_35 ;
V_35 = F_2 ( sizeof( struct V_34 ) , V_6 ) ;
if ( ! V_35 ) {
F_3 ( L_18
L_19 ) ;
return F_47 ( - V_60 ) ;
}
V_33 = F_48 ( V_85 , V_86 , V_79 ) ;
if ( F_49 ( V_33 ) ) {
F_9 ( V_35 ) ;
return F_50 ( V_33 ) ;
}
F_4 ( & V_35 -> V_88 ) ;
F_4 ( & V_35 -> V_89 ) ;
F_4 ( & V_35 -> V_90 ) ;
F_6 ( & V_35 -> V_82 ) ;
V_35 -> V_35 = V_33 ;
V_35 -> V_5 = V_5 ;
F_14 ( & V_5 -> V_15 ) ;
F_33 ( & V_35 -> V_88 , & V_5 -> V_10 ) ;
V_5 -> V_91 ++ ;
if ( V_5 -> V_9 )
V_5 -> V_9 -> V_92 ++ ;
F_15 ( & V_5 -> V_15 ) ;
if ( V_87 ) {
V_35 -> V_87 = V_87 ;
F_14 ( & V_87 -> V_82 ) ;
F_33 ( & V_35 -> V_89 ,
& V_87 -> V_90 ) ;
F_15 ( & V_87 -> V_82 ) ;
}
F_16 ( L_20 ,
V_5 -> V_9 -> V_3 , V_33 -> V_93 , V_33 -> V_94 , V_5 -> V_4 ,
( V_33 -> V_83 == V_95 ) ? L_21 : L_22 ) ;
return V_35 ;
}
static int F_51 (
struct V_34 * V_35 ,
struct V_1 * V_5 ,
struct V_32 * V_33 )
{
F_26 ( V_35 , V_5 ) ;
F_16 ( L_23 ,
V_5 -> V_9 -> V_3 , V_33 -> V_93 , V_33 -> V_94 , V_5 -> V_4 ,
( V_33 -> V_83 == V_95 ) ? L_21 : L_22 ) ;
V_35 -> V_35 = NULL ;
V_35 -> V_5 = NULL ;
F_9 ( V_35 ) ;
return F_52 ( V_33 ) ;
}
int F_53 (
struct V_1 * V_5 ,
struct V_34 * V_35 )
{
struct V_32 * V_33 ;
struct V_34 * V_80 , * V_81 ;
int V_18 = 0 ;
V_33 = V_35 -> V_35 ;
if ( ! V_33 ) {
F_3 ( L_24
L_25 ) ;
return - V_64 ;
}
if ( ! V_35 -> V_87 ) {
F_45 (tpg_np_child, tpg_np_child_tmp,
&tpg_np->tpg_np_parent_list,
tpg_np_child_list) {
V_18 = F_53 ( V_5 , V_80 ) ;
if ( V_18 < 0 )
F_3 ( L_26
L_27 , V_18 ) ;
}
} else {
F_14 ( & V_35 -> V_87 -> V_82 ) ;
F_38 ( & V_35 -> V_89 ) ;
F_15 ( & V_35 -> V_87 -> V_82 ) ;
}
F_14 ( & V_5 -> V_15 ) ;
F_38 ( & V_35 -> V_88 ) ;
V_5 -> V_91 -- ;
if ( V_5 -> V_9 )
V_5 -> V_9 -> V_92 -- ;
F_15 ( & V_5 -> V_15 ) ;
return F_51 ( V_35 , V_5 , V_33 ) ;
}
int F_54 (
struct V_1 * V_5 ,
unsigned char * V_96 ,
T_3 V_97 ,
int V_61 )
{
return F_55 ( & V_5 -> V_21 ,
V_96 , V_97 , V_61 ) ;
}
int F_40 ( struct V_1 * V_5 , T_3 V_28 )
{
unsigned char V_98 [ 256 ] , V_99 [ 256 ] , * V_100 = NULL ;
int V_101 ;
struct V_16 * V_17 ;
struct V_38 * V_39 = & V_5 -> V_27 ;
if ( ( V_28 != 1 ) && ( V_28 != 0 ) ) {
F_3 ( L_28
L_29 , V_28 ) ;
return - 1 ;
}
memset ( V_98 , 0 , sizeof( V_98 ) ) ;
memset ( V_99 , 0 , sizeof( V_99 ) ) ;
V_17 = F_12 ( V_26 , V_5 -> V_24 ) ;
if ( ! V_17 )
return - V_64 ;
if ( V_28 ) {
snprintf ( V_98 , sizeof( V_98 ) , L_30 , V_17 -> V_65 ) ;
V_100 = strstr ( V_98 , V_66 ) ;
if ( ! V_100 )
goto V_25;
if ( ! strncmp ( V_100 + 4 , L_31 , 1 ) ) {
if ( ! strcmp ( V_98 , V_100 ) )
sprintf ( V_99 , L_30 , V_100 + 5 ) ;
else {
V_100 -- ;
* V_100 = '\0' ;
V_101 = sprintf ( V_99 , L_30 , V_98 ) ;
V_100 += 5 ;
sprintf ( V_99 + V_101 , L_30 , V_100 ) ;
}
} else {
V_100 -- ;
* V_100 = '\0' ;
sprintf ( V_99 , L_30 , V_98 ) ;
}
if ( F_13 ( V_17 , V_99 ) < 0 )
return - V_64 ;
} else {
snprintf ( V_98 , sizeof( V_98 ) , L_30 , V_17 -> V_65 ) ;
V_100 = strstr ( V_98 , V_66 ) ;
if ( ( V_100 ) )
goto V_25;
strncat ( V_98 , L_31 , strlen ( L_31 ) ) ;
strncat ( V_98 , V_66 , strlen ( V_66 ) ) ;
if ( F_13 ( V_17 , V_98 ) < 0 )
return - V_64 ;
}
V_25:
V_39 -> V_28 = V_28 ;
F_16 ( L_32 ,
V_39 -> V_28 ? L_33 : L_34 , V_5 -> V_4 ) ;
return 0 ;
}
int F_56 (
struct V_1 * V_5 ,
T_3 V_41 )
{
struct V_38 * V_39 = & V_5 -> V_27 ;
if ( V_41 > V_102 ) {
F_3 ( L_35
L_36 , V_41 , V_102 ) ;
return - V_64 ;
} else if ( V_41 < V_103 ) {
F_3 ( L_37
L_38 , V_41 , V_103 ) ;
return - V_64 ;
}
V_39 -> V_41 = V_41 ;
F_16 ( L_39
L_40 , V_39 -> V_41 , V_5 -> V_4 ) ;
return 0 ;
}
int F_57 (
struct V_1 * V_5 ,
T_3 V_43 )
{
struct V_38 * V_39 = & V_5 -> V_27 ;
if ( V_43 > V_104 ) {
F_3 ( L_41
L_42 , V_43 ,
V_104 ) ;
return - V_64 ;
} else if ( V_43 < V_105 ) {
F_3 ( L_43
L_44 , V_43 ,
V_105 ) ;
return - V_64 ;
}
V_39 -> V_43 = V_43 ;
F_16 ( L_45
L_46 , V_39 -> V_43 , V_5 -> V_4 ) ;
return 0 ;
}
int F_58 (
struct V_1 * V_5 ,
T_3 V_106 )
{
struct V_38 * V_39 = & V_5 -> V_27 ;
if ( ( V_106 != 0 ) && ( V_106 != 1 ) ) {
F_3 ( L_47 , V_106 ) ;
return - V_64 ;
}
V_39 -> V_47 = V_106 ;
F_16 ( L_48 ,
V_5 -> V_4 , ( V_39 -> V_47 ) ? L_49 : L_50 ) ;
return 0 ;
}
int F_59 (
struct V_1 * V_5 ,
T_3 V_107 )
{
struct V_38 * V_39 = & V_5 -> V_27 ;
if ( V_107 > V_108 ) {
F_3 ( L_51
L_42 , V_107 ,
V_108 ) ;
return - V_64 ;
} else if ( V_107 < V_109 ) {
F_3 ( L_52
L_44 , V_107 ,
V_109 ) ;
return - V_64 ;
}
V_39 -> V_45 = V_107 ;
F_16 ( L_53 ,
V_5 -> V_4 , V_39 -> V_45 ) ;
return 0 ;
}
int F_60 (
struct V_1 * V_5 ,
T_3 V_106 )
{
struct V_38 * V_39 = & V_5 -> V_27 ;
if ( ( V_106 != 0 ) && ( V_106 != 1 ) ) {
F_3 ( L_47 , V_106 ) ;
return - V_64 ;
}
V_39 -> V_49 = V_106 ;
F_16 ( L_54
L_55 , V_5 -> V_4 , ( V_39 -> V_49 ) ?
L_49 : L_50 ) ;
return 0 ;
}
int F_61 (
struct V_1 * V_5 ,
T_3 V_106 )
{
struct V_38 * V_39 = & V_5 -> V_27 ;
if ( ( V_106 != 0 ) && ( V_106 != 1 ) ) {
F_3 ( L_47 , V_106 ) ;
return - V_64 ;
}
V_39 -> V_51 = V_106 ;
F_16 ( L_56 ,
V_5 -> V_4 , ( V_39 -> V_51 ) ? L_57 : L_58 ) ;
return 0 ;
}
int F_62 (
struct V_1 * V_5 ,
T_3 V_106 )
{
struct V_38 * V_39 = & V_5 -> V_27 ;
if ( ( V_106 != 0 ) && ( V_106 != 1 ) ) {
F_3 ( L_47 , V_106 ) ;
return - V_64 ;
}
V_39 -> V_53 = V_106 ;
F_16 ( L_59
L_60 , V_5 -> V_4 , ( V_39 -> V_53 ) ?
L_57 : L_58 ) ;
return 0 ;
}
