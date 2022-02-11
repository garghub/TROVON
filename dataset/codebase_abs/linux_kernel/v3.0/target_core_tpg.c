static void F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 , * V_12 ;
F_2 ( & V_2 -> V_13 ) ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
V_7 = & V_2 -> V_15 [ V_5 ] ;
if ( ! ( V_7 -> V_16 & V_17 ) )
continue;
if ( ! V_7 -> V_8 ) {
F_3 ( V_18 L_1
L_2 ,
F_4 ( V_4 ) -> F_5 () ) ;
continue;
}
V_9 = V_7 -> V_8 ;
F_6 ( & V_2 -> V_13 ) ;
F_7 ( V_9 , NULL , V_7 -> V_19 ,
V_20 , V_2 , V_4 , 0 ) ;
F_8 ( & V_9 -> V_21 ) ;
F_9 (acl, acl_tmp,
&lun->lun_acl_list, lacl_list) {
if ( ! ( strcmp ( V_11 -> V_22 ,
V_2 -> V_22 ) ) &&
( V_11 -> V_19 == V_7 -> V_19 ) )
break;
}
if ( ! V_11 ) {
F_3 ( V_18 L_3
L_4 , V_2 -> V_22 ,
V_7 -> V_19 ) ;
F_10 ( & V_9 -> V_21 ) ;
F_2 ( & V_2 -> V_13 ) ;
continue;
}
F_11 ( & V_11 -> V_23 ) ;
F_10 ( & V_9 -> V_21 ) ;
F_2 ( & V_2 -> V_13 ) ;
F_12 ( V_11 ) ;
}
F_6 ( & V_2 -> V_13 ) ;
}
struct V_1 * F_13 (
struct V_3 * V_4 ,
const char * V_22 )
{
struct V_1 * V_11 ;
F_14 (acl, &tpg->acl_node_list, acl_list) {
if ( ! ( strcmp ( V_11 -> V_22 , V_22 ) ) )
return V_11 ;
}
return NULL ;
}
struct V_1 * F_15 (
struct V_3 * V_4 ,
unsigned char * V_22 )
{
struct V_1 * V_11 ;
F_16 ( & V_4 -> V_24 ) ;
F_14 (acl, &tpg->acl_node_list, acl_list) {
if ( ! ( strcmp ( V_11 -> V_22 , V_22 ) ) &&
( ! ( V_11 -> V_25 ) ) ) {
F_17 ( & V_4 -> V_24 ) ;
return V_11 ;
}
}
F_17 ( & V_4 -> V_24 ) ;
return NULL ;
}
void F_18 (
struct V_1 * V_11 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
T_1 V_26 = 0 ;
struct V_8 * V_9 ;
struct V_27 * V_28 ;
F_8 ( & V_4 -> V_29 ) ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
V_9 = & V_4 -> V_30 [ V_5 ] ;
if ( V_9 -> V_31 != V_32 )
continue;
F_10 ( & V_4 -> V_29 ) ;
V_28 = V_9 -> V_33 ;
if ( ! ( F_4 ( V_4 ) -> F_19 ( V_4 ) ) ) {
if ( V_28 -> V_34 & V_35 )
V_26 = V_36 ;
else
V_26 = V_37 ;
} else {
if ( F_20 ( V_28 ) -> F_21 ( V_28 ) == V_38 )
V_26 = V_36 ;
else
V_26 = V_37 ;
}
F_3 ( V_39 L_5
L_6 ,
F_4 ( V_4 ) -> F_5 () ,
F_4 ( V_4 ) -> F_22 ( V_4 ) , V_9 -> V_40 ,
( V_26 == V_37 ) ?
L_7 : L_8 ) ;
F_7 ( V_9 , NULL , V_9 -> V_40 ,
V_26 , V_11 , V_4 , 1 ) ;
F_8 ( & V_4 -> V_29 ) ;
}
F_10 ( & V_4 -> V_29 ) ;
}
static int F_23 (
struct V_3 * V_4 ,
struct V_1 * V_11 )
{
if ( ! V_11 -> V_41 ) {
F_3 ( V_18 L_9
L_10 , F_4 ( V_4 ) -> F_5 () ,
V_11 -> V_22 ) ;
V_11 -> V_41 = 1 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
int V_5 ;
V_2 -> V_15 = F_25 ( sizeof( struct V_6 ) *
V_14 , V_42 ) ;
if ( ! ( V_2 -> V_15 ) ) {
F_3 ( V_18 L_11
L_12 ) ;
return - 1 ;
}
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
V_7 = & V_2 -> V_15 [ V_5 ] ;
F_26 ( & V_7 -> V_43 , 0 ) ;
F_26 ( & V_7 -> V_44 , 0 ) ;
F_27 ( & V_7 -> V_45 ) ;
F_28 ( & V_7 -> V_46 ) ;
F_28 ( & V_7 -> V_47 ) ;
}
return 0 ;
}
struct V_1 * F_29 (
struct V_3 * V_4 ,
unsigned char * V_22 )
{
struct V_1 * V_11 ;
V_11 = F_15 ( V_4 , V_22 ) ;
if ( ( V_11 ) )
return V_11 ;
if ( ! ( F_4 ( V_4 ) -> F_30 ( V_4 ) ) )
return NULL ;
V_11 = F_4 ( V_4 ) -> F_31 ( V_4 ) ;
if ( ! ( V_11 ) )
return NULL ;
F_28 ( & V_11 -> V_48 ) ;
F_28 ( & V_11 -> V_49 ) ;
F_27 ( & V_11 -> V_13 ) ;
F_27 ( & V_11 -> V_50 ) ;
F_26 ( & V_11 -> V_51 , 0 ) ;
V_11 -> V_41 = F_4 ( V_4 ) -> F_32 ( V_4 ) ;
snprintf ( V_11 -> V_22 , V_52 , L_13 , V_22 ) ;
V_11 -> V_53 = V_4 ;
V_11 -> V_54 = F_33 ( V_55 ) ;
F_27 ( & V_11 -> V_56 ) ;
V_11 -> V_25 = 1 ;
F_4 ( V_4 ) -> F_34 ( V_11 ) ;
if ( F_24 ( V_11 ) < 0 ) {
F_4 ( V_4 ) -> F_35 ( V_4 , V_11 ) ;
return NULL ;
}
if ( F_23 ( V_4 , V_11 ) < 0 ) {
F_36 ( V_11 , V_4 ) ;
F_4 ( V_4 ) -> F_35 ( V_4 , V_11 ) ;
return NULL ;
}
F_18 ( V_11 , V_4 ) ;
F_16 ( & V_4 -> V_24 ) ;
F_37 ( & V_11 -> V_48 , & V_4 -> V_57 ) ;
V_4 -> V_58 ++ ;
F_17 ( & V_4 -> V_24 ) ;
F_3 ( L_14
L_15 , F_4 ( V_4 ) -> F_5 () ,
F_4 ( V_4 ) -> F_22 ( V_4 ) , V_11 -> V_41 ,
F_4 ( V_4 ) -> F_5 () , V_22 ) ;
return V_11 ;
}
void F_38 ( struct V_1 * V_2 )
{
while ( F_39 ( & V_2 -> V_51 ) != 0 )
F_40 () ;
}
void F_41 ( struct V_3 * V_4 )
{
int V_5 , V_59 ;
struct V_8 * V_9 ;
F_8 ( & V_4 -> V_29 ) ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
V_9 = & V_4 -> V_30 [ V_5 ] ;
if ( ( V_9 -> V_31 != V_32 ) ||
( V_9 -> V_33 == NULL ) )
continue;
F_10 ( & V_4 -> V_29 ) ;
V_59 = F_42 ( V_4 , V_9 -> V_40 ) ;
F_8 ( & V_4 -> V_29 ) ;
}
F_10 ( & V_4 -> V_29 ) ;
}
struct V_1 * F_43 (
struct V_3 * V_4 ,
struct V_1 * V_60 ,
const char * V_22 ,
T_1 V_41 )
{
struct V_1 * V_11 = NULL ;
F_16 ( & V_4 -> V_24 ) ;
V_11 = F_13 ( V_4 , V_22 ) ;
if ( ( V_11 ) ) {
if ( V_11 -> V_25 ) {
V_11 -> V_25 = 0 ;
F_3 ( V_39 L_16
L_17 , F_4 ( V_4 ) -> F_5 () ,
F_4 ( V_4 ) -> F_22 ( V_4 ) , V_22 ) ;
F_17 ( & V_4 -> V_24 ) ;
if ( V_60 )
F_4 ( V_4 ) -> F_35 ( V_4 ,
V_60 ) ;
goto V_61;
}
F_3 ( V_18 L_18
L_19
L_20 , F_4 ( V_4 ) -> F_5 () ,
V_22 , F_4 ( V_4 ) -> F_22 ( V_4 ) ) ;
F_17 ( & V_4 -> V_24 ) ;
return F_44 ( - V_62 ) ;
}
F_17 ( & V_4 -> V_24 ) ;
if ( ! ( V_60 ) ) {
F_3 ( L_21 ) ;
return F_44 ( - V_63 ) ;
}
V_11 = V_60 ;
F_28 ( & V_11 -> V_48 ) ;
F_28 ( & V_11 -> V_49 ) ;
F_27 ( & V_11 -> V_13 ) ;
F_27 ( & V_11 -> V_50 ) ;
F_26 ( & V_11 -> V_51 , 0 ) ;
V_11 -> V_41 = V_41 ;
snprintf ( V_11 -> V_22 , V_52 , L_13 , V_22 ) ;
V_11 -> V_53 = V_4 ;
V_11 -> V_54 = F_33 ( V_55 ) ;
F_27 ( & V_11 -> V_56 ) ;
F_4 ( V_4 ) -> F_34 ( V_11 ) ;
if ( F_24 ( V_11 ) < 0 ) {
F_4 ( V_4 ) -> F_35 ( V_4 , V_11 ) ;
return F_44 ( - V_64 ) ;
}
if ( F_23 ( V_4 , V_11 ) < 0 ) {
F_36 ( V_11 , V_4 ) ;
F_4 ( V_4 ) -> F_35 ( V_4 , V_11 ) ;
return F_44 ( - V_63 ) ;
}
F_16 ( & V_4 -> V_24 ) ;
F_37 ( & V_11 -> V_48 , & V_4 -> V_57 ) ;
V_4 -> V_58 ++ ;
F_17 ( & V_4 -> V_24 ) ;
V_61:
F_3 ( V_39 L_22
L_15 , F_4 ( V_4 ) -> F_5 () ,
F_4 ( V_4 ) -> F_22 ( V_4 ) , V_11 -> V_41 ,
F_4 ( V_4 ) -> F_5 () , V_22 ) ;
return V_11 ;
}
int F_45 (
struct V_3 * V_4 ,
struct V_1 * V_11 ,
int V_65 )
{
struct V_66 * V_67 , * V_68 ;
int V_69 = 0 ;
F_16 ( & V_4 -> V_24 ) ;
if ( V_11 -> V_25 ) {
V_11 -> V_25 = 0 ;
V_69 = 1 ;
}
F_11 ( & V_11 -> V_48 ) ;
V_4 -> V_58 -- ;
F_17 ( & V_4 -> V_24 ) ;
F_16 ( & V_4 -> V_70 ) ;
F_9 (sess, sess_tmp,
&tpg->tpg_sess_list, sess_list) {
if ( V_67 -> V_1 != V_11 )
continue;
if ( ! ( F_4 ( V_4 ) -> F_46 ( V_67 ) ) )
continue;
F_17 ( & V_4 -> V_70 ) ;
F_4 ( V_4 ) -> F_47 ( V_67 ) ;
F_16 ( & V_4 -> V_70 ) ;
}
F_17 ( & V_4 -> V_70 ) ;
F_38 ( V_11 ) ;
F_1 ( V_11 , V_4 ) ;
F_36 ( V_11 , V_4 ) ;
F_3 ( V_39 L_23
L_15 , F_4 ( V_4 ) -> F_5 () ,
F_4 ( V_4 ) -> F_22 ( V_4 ) , V_11 -> V_41 ,
F_4 ( V_4 ) -> F_5 () , V_11 -> V_22 ) ;
return 0 ;
}
int F_48 (
struct V_3 * V_4 ,
unsigned char * V_22 ,
T_1 V_41 ,
int V_65 )
{
struct V_66 * V_67 , * V_71 = NULL ;
struct V_1 * V_11 ;
int V_69 = 0 ;
F_16 ( & V_4 -> V_24 ) ;
V_11 = F_13 ( V_4 , V_22 ) ;
if ( ! ( V_11 ) ) {
F_3 ( V_18 L_24
L_25
L_20 , F_4 ( V_4 ) -> F_5 () ,
V_22 , F_4 ( V_4 ) -> F_22 ( V_4 ) ) ;
F_17 ( & V_4 -> V_24 ) ;
return - V_72 ;
}
if ( V_11 -> V_25 ) {
V_11 -> V_25 = 0 ;
V_69 = 1 ;
}
F_17 ( & V_4 -> V_24 ) ;
F_16 ( & V_4 -> V_70 ) ;
F_14 (sess, &tpg->tpg_sess_list, sess_list) {
if ( V_67 -> V_1 != V_11 )
continue;
if ( ! V_65 ) {
F_3 ( V_18 L_26
L_27
L_28
L_29
L_30 ,
F_4 ( V_4 ) -> F_5 () , V_22 ) ;
F_17 ( & V_4 -> V_70 ) ;
F_16 ( & V_4 -> V_24 ) ;
if ( V_69 )
V_11 -> V_25 = 1 ;
F_17 ( & V_4 -> V_24 ) ;
return - V_62 ;
}
if ( ! ( F_4 ( V_4 ) -> F_46 ( V_67 ) ) )
continue;
V_71 = V_67 ;
break;
}
V_11 -> V_41 = V_41 ;
if ( F_23 ( V_4 , V_11 ) < 0 ) {
F_17 ( & V_4 -> V_70 ) ;
if ( V_71 )
F_4 ( V_4 ) -> F_47 ( V_71 ) ;
F_16 ( & V_4 -> V_24 ) ;
if ( V_69 )
V_11 -> V_25 = 1 ;
F_17 ( & V_4 -> V_24 ) ;
return - V_63 ;
}
F_17 ( & V_4 -> V_70 ) ;
if ( V_71 )
F_4 ( V_4 ) -> F_47 ( V_71 ) ;
F_3 ( V_39 L_31
L_32 , V_41 ,
V_22 , F_4 ( V_4 ) -> F_5 () ,
F_4 ( V_4 ) -> F_22 ( V_4 ) ) ;
F_16 ( & V_4 -> V_24 ) ;
if ( V_69 )
V_11 -> V_25 = 1 ;
F_17 ( & V_4 -> V_24 ) ;
return 0 ;
}
static int F_49 ( struct V_3 * V_53 )
{
struct V_27 * V_28 = V_73 -> V_74 ;
struct V_8 * V_9 = & V_53 -> V_75 ;
T_1 V_26 = V_36 ;
int V_59 ;
V_9 -> V_40 = 0 ;
V_9 -> V_31 = V_76 ;
F_26 ( & V_9 -> V_77 , 0 ) ;
F_50 ( & V_9 -> V_78 ) ;
F_28 ( & V_9 -> V_79 ) ;
F_28 ( & V_9 -> V_80 ) ;
F_27 ( & V_9 -> V_21 ) ;
F_27 ( & V_9 -> V_81 ) ;
F_27 ( & V_9 -> V_82 ) ;
V_59 = F_51 ( V_53 , V_9 , V_26 , V_28 ) ;
if ( V_59 < 0 )
return - 1 ;
return 0 ;
}
static void F_52 ( struct V_3 * V_53 )
{
struct V_8 * V_9 = & V_53 -> V_75 ;
F_53 ( V_53 , V_9 ) ;
}
int F_54 (
struct V_83 * V_84 ,
struct V_85 * V_85 ,
struct V_3 * V_53 ,
void * V_86 ,
int V_87 )
{
struct V_8 * V_9 ;
T_1 V_5 ;
V_53 -> V_30 = F_25 ( ( sizeof( struct V_8 ) *
V_14 ) , V_42 ) ;
if ( ! ( V_53 -> V_30 ) ) {
F_3 ( V_18 L_33
L_34 ) ;
return - V_64 ;
}
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
V_9 = & V_53 -> V_30 [ V_5 ] ;
V_9 -> V_40 = V_5 ;
V_9 -> V_31 = V_76 ;
F_26 ( & V_9 -> V_77 , 0 ) ;
F_50 ( & V_9 -> V_78 ) ;
F_28 ( & V_9 -> V_79 ) ;
F_28 ( & V_9 -> V_80 ) ;
F_27 ( & V_9 -> V_21 ) ;
F_27 ( & V_9 -> V_81 ) ;
F_27 ( & V_9 -> V_82 ) ;
}
V_53 -> V_87 = V_87 ;
V_53 -> V_88 = V_86 ;
V_53 -> V_89 = V_84 ;
V_53 -> V_90 = V_85 ;
F_26 ( & V_53 -> V_91 , 0 ) ;
F_28 ( & V_53 -> V_57 ) ;
F_28 ( & V_53 -> V_92 ) ;
F_28 ( & V_53 -> V_93 ) ;
F_27 ( & V_53 -> V_24 ) ;
F_27 ( & V_53 -> V_70 ) ;
F_27 ( & V_53 -> V_29 ) ;
if ( V_53 -> V_87 == V_94 ) {
if ( F_49 ( V_53 ) < 0 ) {
F_12 ( V_53 ) ;
return - V_64 ;
}
}
F_16 ( & V_73 -> V_95 ) ;
F_37 ( & V_53 -> V_92 , & V_73 -> V_96 ) ;
F_17 ( & V_73 -> V_95 ) ;
F_3 ( V_39 L_35
L_36 , V_84 -> F_5 () ,
( V_53 -> V_87 == V_94 ) ?
L_37 : L_38 , ( V_84 -> V_97 ( V_53 ) == NULL ) ?
L_39 : V_84 -> V_97 ( V_53 ) , V_84 -> F_22 ( V_53 ) ) ;
return 0 ;
}
int F_55 ( struct V_3 * V_53 )
{
struct V_1 * V_2 , * V_98 ;
F_3 ( V_39 L_40
L_41 ,
( V_53 -> V_87 == V_94 ) ?
L_37 : L_38 , F_4 ( V_53 ) -> F_5 () ,
F_4 ( V_53 ) -> V_97 ( V_53 ) ,
F_4 ( V_53 ) -> F_22 ( V_53 ) ) ;
F_16 ( & V_73 -> V_95 ) ;
F_11 ( & V_53 -> V_92 ) ;
F_17 ( & V_73 -> V_95 ) ;
while ( F_39 ( & V_53 -> V_91 ) != 0 )
F_40 () ;
F_16 ( & V_53 -> V_24 ) ;
F_9 (nacl, nacl_tmp, &se_tpg->acl_node_list,
acl_list) {
F_11 ( & V_2 -> V_48 ) ;
V_53 -> V_58 -- ;
F_17 ( & V_53 -> V_24 ) ;
F_38 ( V_2 ) ;
F_36 ( V_2 , V_53 ) ;
F_4 ( V_53 ) -> F_35 ( V_53 , V_2 ) ;
F_16 ( & V_53 -> V_24 ) ;
}
F_17 ( & V_53 -> V_24 ) ;
if ( V_53 -> V_87 == V_94 )
F_52 ( V_53 ) ;
V_53 -> V_88 = NULL ;
F_12 ( V_53 -> V_30 ) ;
return 0 ;
}
struct V_8 * F_56 (
struct V_3 * V_4 ,
T_1 V_40 )
{
struct V_8 * V_9 ;
if ( V_40 > ( V_14 - 1 ) ) {
F_3 ( V_18 L_42
L_43 ,
F_4 ( V_4 ) -> F_5 () ,
V_40 , V_14 - 1 ,
F_4 ( V_4 ) -> F_22 ( V_4 ) ) ;
return F_44 ( - V_99 ) ;
}
F_8 ( & V_4 -> V_29 ) ;
V_9 = & V_4 -> V_30 [ V_40 ] ;
if ( V_9 -> V_31 == V_32 ) {
F_3 ( V_18 L_44
L_45 ,
V_40 , F_4 ( V_4 ) -> F_5 () ,
F_4 ( V_4 ) -> F_22 ( V_4 ) ) ;
F_10 ( & V_4 -> V_29 ) ;
return F_44 ( - V_63 ) ;
}
F_10 ( & V_4 -> V_29 ) ;
return V_9 ;
}
int F_51 (
struct V_3 * V_4 ,
struct V_8 * V_9 ,
T_1 V_26 ,
void * V_100 )
{
if ( F_57 ( V_100 , V_4 , V_9 ) < 0 )
return - 1 ;
F_8 ( & V_4 -> V_29 ) ;
V_9 -> V_26 = V_26 ;
V_9 -> V_31 = V_32 ;
F_10 ( & V_4 -> V_29 ) ;
return 0 ;
}
static void F_58 (
struct V_3 * V_4 ,
struct V_8 * V_9 )
{
F_59 ( V_9 , V_4 ) ;
F_60 ( V_9 ) ;
}
struct V_8 * F_61 (
struct V_3 * V_4 ,
T_1 V_40 ,
int * V_59 )
{
struct V_8 * V_9 ;
if ( V_40 > ( V_14 - 1 ) ) {
F_3 ( V_18 L_42
L_43 ,
F_4 ( V_4 ) -> F_5 () , V_40 ,
V_14 - 1 ,
F_4 ( V_4 ) -> F_22 ( V_4 ) ) ;
return F_44 ( - V_99 ) ;
}
F_8 ( & V_4 -> V_29 ) ;
V_9 = & V_4 -> V_30 [ V_40 ] ;
if ( V_9 -> V_31 != V_32 ) {
F_3 ( V_18 L_46
L_47 ,
F_4 ( V_4 ) -> F_5 () , V_40 ,
F_4 ( V_4 ) -> F_22 ( V_4 ) ) ;
F_10 ( & V_4 -> V_29 ) ;
return F_44 ( - V_72 ) ;
}
F_10 ( & V_4 -> V_29 ) ;
return V_9 ;
}
int F_53 (
struct V_3 * V_4 ,
struct V_8 * V_9 )
{
F_58 ( V_4 , V_9 ) ;
F_62 ( V_9 -> V_33 , V_4 , V_9 ) ;
F_8 ( & V_4 -> V_29 ) ;
V_9 -> V_31 = V_76 ;
F_10 ( & V_4 -> V_29 ) ;
return 0 ;
}
