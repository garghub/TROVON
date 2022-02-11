static char * F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
return L_4 ;
case V_6 :
return L_5 ;
case V_7 :
return L_6 ;
case V_8 :
return L_7 ;
default:
return L_8 ;
}
}
static int F_2 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_13 * V_14 )
{
F_3 ( V_10 , L_9 , V_12 -> V_15 , F_1 ( V_12 -> V_16 ) ) ;
if ( V_12 -> V_17 == V_18 ||
V_12 -> V_17 == V_19 )
F_3 ( V_10 , L_10 , F_1 ( V_12 -> V_20 ) ) ;
if ( V_12 -> V_21 ) {
if ( V_12 -> V_21 != V_14 -> V_22 )
F_3 ( V_10 , L_11 , V_12 -> V_21 ,
V_12 -> V_23 ) ;
else
F_3 ( V_10 , L_12 , V_12 -> V_23 ) ;
}
if ( V_12 -> V_24 )
F_3 ( V_10 , L_13 , V_12 -> V_24 ) ;
return F_3 ( V_10 , L_14 ) ;
}
static int F_4 ( struct V_13 * V_14 , struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_25 , V_26 = V_14 -> V_27 -> V_28 , V_29 , V_30 ;
int V_31 ;
F_5 ( V_14 ) ;
V_31 = F_3 ( V_10 , L_15 ,
V_14 , V_14 -> V_32 ) ;
if ( V_31 )
goto V_33;
for ( V_25 = 0 ; V_25 < V_14 -> V_32 ; V_25 ++ ) {
if ( isprint ( V_14 -> V_34 [ V_25 ] ) )
F_3 ( V_10 , L_16 , V_14 -> V_34 [ V_25 ] ) ;
else
F_3 ( V_10 , L_16 , '.' ) ;
}
if ( V_14 -> V_22 > 0 )
V_31 = F_3 ( V_10 , L_17 ,
V_14 -> V_22 ) ;
else if ( V_14 -> V_22 == 0 )
V_31 = F_3 ( V_10 , L_18 ) ;
else if ( V_14 -> V_22 == - 1 )
V_31 = F_3 ( V_10 , L_19 ,
V_14 -> V_35 ) ;
else
V_31 = F_3 ( V_10 , L_20 ,
V_14 -> V_22 ) ;
if ( V_31 )
goto V_33;
if ( V_14 -> V_36 ) {
F_3 ( V_10 , L_21 ) ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
if ( V_25 == V_26 / 2 )
F_3 ( V_10 , L_22 ) ;
F_3 ( V_10 , L_23 ,
( unsigned char ) V_14 -> V_36 [ V_25 ] ) ;
}
if ( F_6 ( V_14 , V_37 ) )
F_3 ( V_10 , L_24 ) ;
V_31 = F_3 ( V_10 , L_14 ) ;
if ( V_31 )
goto V_33;
}
V_30 = ! F_7 ( & V_14 -> V_38 ) ;
V_29 = ! F_7 ( & V_14 -> V_39 ) ;
if ( V_30 || V_29 ) {
V_31 = F_3 ( V_10 , L_25
L_26 , V_30 , V_29 ,
V_14 -> V_40 , V_14 -> V_41 ) ;
if ( V_31 )
goto V_33;
}
F_3 ( V_10 , L_27 ) ;
F_8 (lkb, &res->res_grantqueue, lkb_statequeue) {
V_31 = F_2 ( V_10 , V_12 , V_14 ) ;
if ( V_31 )
goto V_33;
}
F_3 ( V_10 , L_28 ) ;
F_8 (lkb, &res->res_convertqueue, lkb_statequeue) {
V_31 = F_2 ( V_10 , V_12 , V_14 ) ;
if ( V_31 )
goto V_33;
}
F_3 ( V_10 , L_29 ) ;
F_8 (lkb, &res->res_waitqueue, lkb_statequeue) {
V_31 = F_2 ( V_10 , V_12 , V_14 ) ;
if ( V_31 )
goto V_33;
}
if ( F_7 ( & V_14 -> V_42 ) )
goto V_33;
F_3 ( V_10 , L_30 ) ;
F_8 (lkb, &res->res_lookup, lkb_rsb_lookup) {
V_31 = F_3 ( V_10 , L_9 , V_12 -> V_15 ,
F_1 ( V_12 -> V_20 ) ) ;
if ( V_12 -> V_24 )
F_3 ( V_10 , L_13 , V_12 -> V_24 ) ;
V_31 = F_3 ( V_10 , L_14 ) ;
}
V_33:
F_9 ( V_14 ) ;
return V_31 ;
}
static int F_10 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_13 * V_43 )
{
T_1 V_44 = 0 ;
T_1 V_45 ;
int V_31 ;
if ( V_12 -> V_46 & V_47 ) {
if ( V_12 -> V_48 )
V_44 = V_12 -> V_48 -> V_44 ;
}
V_45 = F_11 ( F_12 ( F_13 () , V_12 -> V_49 ) ) ;
V_31 = F_3 ( V_10 , L_31 ,
V_12 -> V_15 ,
V_12 -> V_21 ,
V_12 -> V_23 ,
V_12 -> V_50 ,
( unsigned long long ) V_44 ,
V_12 -> V_51 ,
V_12 -> V_46 ,
V_12 -> V_17 ,
V_12 -> V_16 ,
V_12 -> V_20 ,
( unsigned long long ) V_45 ,
V_43 -> V_22 ,
V_43 -> V_32 ,
V_43 -> V_34 ) ;
return V_31 ;
}
static int F_14 ( struct V_13 * V_43 , struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_31 = 0 ;
F_5 ( V_43 ) ;
F_8 (lkb, &r->res_grantqueue, lkb_statequeue) {
V_31 = F_10 ( V_10 , V_12 , V_43 ) ;
if ( V_31 )
goto V_33;
}
F_8 (lkb, &r->res_convertqueue, lkb_statequeue) {
V_31 = F_10 ( V_10 , V_12 , V_43 ) ;
if ( V_31 )
goto V_33;
}
F_8 (lkb, &r->res_waitqueue, lkb_statequeue) {
V_31 = F_10 ( V_10 , V_12 , V_43 ) ;
if ( V_31 )
goto V_33;
}
V_33:
F_9 ( V_43 ) ;
return V_31 ;
}
static int F_15 ( struct V_9 * V_10 , struct V_11 * V_12 ,
int V_52 )
{
T_1 V_44 = 0 ;
int V_31 ;
if ( V_12 -> V_46 & V_47 ) {
if ( V_12 -> V_48 )
V_44 = V_12 -> V_48 -> V_44 ;
}
V_31 = F_3 ( V_10 , L_32 ,
V_12 -> V_15 ,
V_12 -> V_21 ,
V_12 -> V_23 ,
V_12 -> V_50 ,
( unsigned long long ) V_44 ,
V_12 -> V_51 ,
V_12 -> V_46 ,
V_12 -> V_17 ,
V_12 -> V_16 ,
V_12 -> V_20 ,
V_12 -> V_53 . V_1 ,
V_52 ,
V_12 -> V_24 ,
V_12 -> V_54 ,
( unsigned long long ) F_16 ( V_12 -> V_49 ) ,
( unsigned long long ) F_16 ( V_12 -> V_55 ) ) ;
return V_31 ;
}
static int F_17 ( struct V_13 * V_43 , struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_25 , V_26 = V_43 -> V_27 -> V_28 ;
int V_56 = 1 ;
int V_31 ;
F_5 ( V_43 ) ;
V_31 = F_3 ( V_10 , L_33 ,
V_43 ,
V_43 -> V_22 ,
V_43 -> V_35 ,
V_43 -> V_40 ,
! F_7 ( & V_43 -> V_38 ) ,
! F_7 ( & V_43 -> V_39 ) ,
V_43 -> V_41 ,
V_43 -> V_32 ) ;
if ( V_31 )
goto V_33;
for ( V_25 = 0 ; V_25 < V_43 -> V_32 ; V_25 ++ ) {
if ( ! isascii ( V_43 -> V_34 [ V_25 ] ) || ! isprint ( V_43 -> V_34 [ V_25 ] ) )
V_56 = 0 ;
}
F_3 ( V_10 , L_34 , V_56 ? L_35 : L_36 ) ;
for ( V_25 = 0 ; V_25 < V_43 -> V_32 ; V_25 ++ ) {
if ( V_56 )
F_3 ( V_10 , L_16 , V_43 -> V_34 [ V_25 ] ) ;
else
F_3 ( V_10 , L_37 , ( unsigned char ) V_43 -> V_34 [ V_25 ] ) ;
}
V_31 = F_3 ( V_10 , L_14 ) ;
if ( V_31 )
goto V_33;
if ( ! V_43 -> V_36 )
goto V_57;
F_3 ( V_10 , L_38 , V_43 -> V_58 , V_26 ) ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ )
F_3 ( V_10 , L_37 , ( unsigned char ) V_43 -> V_36 [ V_25 ] ) ;
V_31 = F_3 ( V_10 , L_14 ) ;
if ( V_31 )
goto V_33;
V_57:
F_8 (lkb, &r->res_grantqueue, lkb_statequeue) {
V_31 = F_15 ( V_10 , V_12 , 0 ) ;
if ( V_31 )
goto V_33;
}
F_8 (lkb, &r->res_convertqueue, lkb_statequeue) {
V_31 = F_15 ( V_10 , V_12 , 0 ) ;
if ( V_31 )
goto V_33;
}
F_8 (lkb, &r->res_waitqueue, lkb_statequeue) {
V_31 = F_15 ( V_10 , V_12 , 0 ) ;
if ( V_31 )
goto V_33;
}
F_8 (lkb, &r->res_lookup, lkb_rsb_lookup) {
V_31 = F_15 ( V_10 , V_12 , 1 ) ;
if ( V_31 )
goto V_33;
}
V_33:
F_9 ( V_43 ) ;
return V_31 ;
}
static int F_18 ( struct V_9 * V_59 , void * V_60 )
{
struct V_61 * V_62 = V_60 ;
int V_31 = 0 ;
switch ( V_62 -> V_63 ) {
case 1 :
V_31 = F_4 ( V_62 -> V_64 , V_59 ) ;
break;
case 2 :
if ( V_62 -> V_65 ) {
F_3 ( V_59 , L_39
L_40
L_41 ) ;
V_62 -> V_65 = 0 ;
}
V_31 = F_14 ( V_62 -> V_64 , V_59 ) ;
break;
case 3 :
if ( V_62 -> V_65 ) {
F_3 ( V_59 , L_42 ) ;
V_62 -> V_65 = 0 ;
}
V_31 = F_17 ( V_62 -> V_64 , V_59 ) ;
break;
}
return V_31 ;
}
static void * F_19 ( struct V_9 * V_59 , T_2 * V_66 )
{
struct V_67 * V_68 = V_59 -> V_69 ;
struct V_61 * V_62 ;
struct V_13 * V_43 ;
T_2 V_70 = * V_66 ;
unsigned V_71 , V_72 ;
V_71 = V_70 >> 32 ;
V_72 = V_70 & ( ( 1LL << 32 ) - 1 ) ;
if ( V_71 >= V_68 -> V_73 )
return NULL ;
V_62 = F_20 ( sizeof( struct V_61 ) , V_74 ) ;
if ( ! V_62 )
return NULL ;
if ( V_70 == 0 )
V_62 -> V_65 = 1 ;
if ( V_59 -> V_75 == & V_76 )
V_62 -> V_63 = 1 ;
if ( V_59 -> V_75 == & V_77 )
V_62 -> V_63 = 2 ;
if ( V_59 -> V_75 == & V_78 )
V_62 -> V_63 = 3 ;
F_21 ( & V_68 -> V_79 [ V_71 ] . V_80 ) ;
if ( ! F_7 ( & V_68 -> V_79 [ V_71 ] . V_81 ) ) {
F_8 (r, &ls->ls_rsbtbl[bucket].list,
res_hashchain) {
if ( ! V_72 -- ) {
F_22 ( V_43 ) ;
V_62 -> V_64 = V_43 ;
V_62 -> V_71 = V_71 ;
F_23 ( & V_68 -> V_79 [ V_71 ] . V_80 ) ;
return V_62 ;
}
}
}
F_23 ( & V_68 -> V_79 [ V_71 ] . V_80 ) ;
V_70 &= ~ ( ( 1LL << 32 ) - 1 ) ;
while ( 1 ) {
V_71 ++ ;
V_70 += 1LL << 32 ;
if ( V_71 >= V_68 -> V_73 ) {
F_24 ( V_62 ) ;
return NULL ;
}
F_21 ( & V_68 -> V_79 [ V_71 ] . V_80 ) ;
if ( ! F_7 ( & V_68 -> V_79 [ V_71 ] . V_81 ) ) {
V_43 = F_25 ( & V_68 -> V_79 [ V_71 ] . V_81 ,
struct V_13 , V_82 ) ;
F_22 ( V_43 ) ;
V_62 -> V_64 = V_43 ;
V_62 -> V_71 = V_71 ;
F_23 ( & V_68 -> V_79 [ V_71 ] . V_80 ) ;
* V_66 = V_70 ;
return V_62 ;
}
F_23 ( & V_68 -> V_79 [ V_71 ] . V_80 ) ;
}
}
static void * F_26 ( struct V_9 * V_59 , void * V_60 , T_2 * V_66 )
{
struct V_67 * V_68 = V_59 -> V_69 ;
struct V_61 * V_62 = V_60 ;
struct V_83 * V_84 ;
struct V_13 * V_43 , * V_85 ;
T_2 V_70 = * V_66 ;
unsigned V_71 ;
V_71 = V_70 >> 32 ;
F_21 ( & V_68 -> V_79 [ V_71 ] . V_80 ) ;
V_85 = V_62 -> V_64 ;
V_84 = V_85 -> V_82 . V_84 ;
if ( V_84 != & V_68 -> V_79 [ V_71 ] . V_81 ) {
V_43 = F_27 ( V_84 , struct V_13 , V_82 ) ;
F_22 ( V_43 ) ;
V_62 -> V_64 = V_43 ;
F_23 ( & V_68 -> V_79 [ V_71 ] . V_80 ) ;
F_28 ( V_85 ) ;
++ * V_66 ;
return V_62 ;
}
F_23 ( & V_68 -> V_79 [ V_71 ] . V_80 ) ;
F_28 ( V_85 ) ;
V_70 &= ~ ( ( 1LL << 32 ) - 1 ) ;
while ( 1 ) {
V_71 ++ ;
V_70 += 1LL << 32 ;
if ( V_71 >= V_68 -> V_73 ) {
F_24 ( V_62 ) ;
return NULL ;
}
F_21 ( & V_68 -> V_79 [ V_71 ] . V_80 ) ;
if ( ! F_7 ( & V_68 -> V_79 [ V_71 ] . V_81 ) ) {
V_43 = F_25 ( & V_68 -> V_79 [ V_71 ] . V_81 ,
struct V_13 , V_82 ) ;
F_22 ( V_43 ) ;
V_62 -> V_64 = V_43 ;
V_62 -> V_71 = V_71 ;
F_23 ( & V_68 -> V_79 [ V_71 ] . V_80 ) ;
* V_66 = V_70 ;
return V_62 ;
}
F_23 ( & V_68 -> V_79 [ V_71 ] . V_80 ) ;
}
}
static void F_29 ( struct V_9 * V_59 , void * V_60 )
{
struct V_61 * V_62 = V_60 ;
if ( V_62 ) {
F_28 ( V_62 -> V_64 ) ;
F_24 ( V_62 ) ;
}
}
static int F_30 ( struct V_86 * V_86 , struct V_87 * V_87 )
{
struct V_9 * V_59 ;
int V_88 = - 1 ;
if ( V_87 -> V_89 == & V_90 )
V_88 = F_31 ( V_87 , & V_76 ) ;
else if ( V_87 -> V_89 == & V_91 )
V_88 = F_31 ( V_87 , & V_77 ) ;
else if ( V_87 -> V_89 == & V_92 )
V_88 = F_31 ( V_87 , & V_78 ) ;
if ( V_88 )
return V_88 ;
V_59 = V_87 -> V_93 ;
V_59 -> V_69 = V_86 -> V_94 ;
return 0 ;
}
static int F_32 ( struct V_86 * V_86 , struct V_87 * V_87 )
{
V_87 -> V_93 = V_86 -> V_94 ;
return 0 ;
}
static T_3 F_33 ( struct V_87 * V_87 , char T_4 * V_95 ,
T_5 V_96 , T_2 * V_97 )
{
struct V_67 * V_68 = V_87 -> V_93 ;
struct V_11 * V_12 ;
T_5 V_98 = V_99 , V_66 = 0 , V_88 , V_31 ;
F_34 ( & V_100 ) ;
F_34 ( & V_68 -> V_101 ) ;
memset ( V_102 , 0 , sizeof( V_102 ) ) ;
F_8 (lkb, &ls->ls_waiters, lkb_wait_reply) {
V_88 = snprintf ( V_102 + V_66 , V_98 - V_66 , L_43 ,
V_12 -> V_15 , V_12 -> V_24 ,
V_12 -> V_21 , V_12 -> V_103 -> V_34 ) ;
if ( V_88 >= V_98 - V_66 )
break;
V_66 += V_88 ;
}
F_35 ( & V_68 -> V_101 ) ;
V_31 = F_36 ( V_95 , V_96 , V_97 , V_102 , V_66 ) ;
F_35 ( & V_100 ) ;
return V_31 ;
}
void F_37 ( struct V_67 * V_68 )
{
if ( V_68 -> V_104 )
F_38 ( V_68 -> V_104 ) ;
if ( V_68 -> V_105 )
F_38 ( V_68 -> V_105 ) ;
if ( V_68 -> V_106 )
F_38 ( V_68 -> V_106 ) ;
if ( V_68 -> V_107 )
F_38 ( V_68 -> V_107 ) ;
}
int F_39 ( struct V_67 * V_68 )
{
char V_108 [ V_109 + 8 ] ;
V_68 -> V_104 = F_40 ( V_68 -> V_110 ,
V_111 | V_112 ,
V_113 ,
V_68 ,
& V_90 ) ;
if ( ! V_68 -> V_104 )
goto V_114;
memset ( V_108 , 0 , sizeof( V_108 ) ) ;
snprintf ( V_108 , V_109 + 8 , L_44 , V_68 -> V_110 ) ;
V_68 -> V_106 = F_40 ( V_108 ,
V_111 | V_112 ,
V_113 ,
V_68 ,
& V_91 ) ;
if ( ! V_68 -> V_106 )
goto V_114;
memset ( V_108 , 0 , sizeof( V_108 ) ) ;
snprintf ( V_108 , V_109 + 8 , L_45 , V_68 -> V_110 ) ;
V_68 -> V_107 = F_40 ( V_108 ,
V_111 | V_112 ,
V_113 ,
V_68 ,
& V_92 ) ;
if ( ! V_68 -> V_107 )
goto V_114;
memset ( V_108 , 0 , sizeof( V_108 ) ) ;
snprintf ( V_108 , V_109 + 8 , L_46 , V_68 -> V_110 ) ;
V_68 -> V_105 = F_40 ( V_108 ,
V_111 | V_112 ,
V_113 ,
V_68 ,
& V_115 ) ;
if ( ! V_68 -> V_105 )
goto V_114;
return 0 ;
V_114:
F_37 ( V_68 ) ;
return - V_116 ;
}
int T_6 F_41 ( void )
{
F_42 ( & V_100 ) ;
V_113 = F_43 ( L_47 , NULL ) ;
return V_113 ? 0 : - V_116 ;
}
void F_44 ( void )
{
F_38 ( V_113 ) ;
}
