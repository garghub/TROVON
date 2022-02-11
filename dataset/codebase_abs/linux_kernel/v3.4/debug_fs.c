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
struct V_67 * V_68 ;
struct V_69 * V_70 = V_59 -> V_71 ;
struct V_61 * V_62 ;
struct V_13 * V_43 ;
T_2 V_72 = * V_66 ;
unsigned V_73 , V_74 ;
V_73 = V_72 >> 32 ;
V_74 = V_72 & ( ( 1LL << 32 ) - 1 ) ;
if ( V_73 >= V_70 -> V_75 )
return NULL ;
V_62 = F_20 ( sizeof( struct V_61 ) , V_76 ) ;
if ( ! V_62 )
return NULL ;
if ( V_72 == 0 )
V_62 -> V_65 = 1 ;
if ( V_59 -> V_77 == & V_78 )
V_62 -> V_63 = 1 ;
if ( V_59 -> V_77 == & V_79 )
V_62 -> V_63 = 2 ;
if ( V_59 -> V_77 == & V_80 )
V_62 -> V_63 = 3 ;
F_21 ( & V_70 -> V_81 [ V_73 ] . V_82 ) ;
if ( ! F_22 ( & V_70 -> V_81 [ V_73 ] . V_83 ) ) {
for ( V_68 = F_23 ( & V_70 -> V_81 [ V_73 ] . V_83 ) ; V_68 ;
V_68 = F_24 ( V_68 ) ) {
V_43 = F_25 ( V_68 , struct V_13 , V_84 ) ;
if ( ! V_74 -- ) {
F_26 ( V_43 ) ;
V_62 -> V_64 = V_43 ;
V_62 -> V_73 = V_73 ;
F_27 ( & V_70 -> V_81 [ V_73 ] . V_82 ) ;
return V_62 ;
}
}
}
F_27 ( & V_70 -> V_81 [ V_73 ] . V_82 ) ;
V_72 &= ~ ( ( 1LL << 32 ) - 1 ) ;
while ( 1 ) {
V_73 ++ ;
V_72 += 1LL << 32 ;
if ( V_73 >= V_70 -> V_75 ) {
F_28 ( V_62 ) ;
return NULL ;
}
F_21 ( & V_70 -> V_81 [ V_73 ] . V_82 ) ;
if ( ! F_22 ( & V_70 -> V_81 [ V_73 ] . V_83 ) ) {
V_68 = F_23 ( & V_70 -> V_81 [ V_73 ] . V_83 ) ;
V_43 = F_25 ( V_68 , struct V_13 , V_84 ) ;
F_26 ( V_43 ) ;
V_62 -> V_64 = V_43 ;
V_62 -> V_73 = V_73 ;
F_27 ( & V_70 -> V_81 [ V_73 ] . V_82 ) ;
* V_66 = V_72 ;
return V_62 ;
}
F_27 ( & V_70 -> V_81 [ V_73 ] . V_82 ) ;
}
}
static void * F_29 ( struct V_9 * V_59 , void * V_60 , T_2 * V_66 )
{
struct V_69 * V_70 = V_59 -> V_71 ;
struct V_61 * V_62 = V_60 ;
struct V_67 * V_85 ;
struct V_13 * V_43 , * V_86 ;
T_2 V_72 = * V_66 ;
unsigned V_73 ;
V_73 = V_72 >> 32 ;
F_21 ( & V_70 -> V_81 [ V_73 ] . V_82 ) ;
V_86 = V_62 -> V_64 ;
V_85 = F_24 ( & V_86 -> V_84 ) ;
if ( V_85 ) {
V_43 = F_25 ( V_85 , struct V_13 , V_84 ) ;
F_26 ( V_43 ) ;
V_62 -> V_64 = V_43 ;
F_27 ( & V_70 -> V_81 [ V_73 ] . V_82 ) ;
F_30 ( V_86 ) ;
++ * V_66 ;
return V_62 ;
}
F_27 ( & V_70 -> V_81 [ V_73 ] . V_82 ) ;
F_30 ( V_86 ) ;
V_72 &= ~ ( ( 1LL << 32 ) - 1 ) ;
while ( 1 ) {
V_73 ++ ;
V_72 += 1LL << 32 ;
if ( V_73 >= V_70 -> V_75 ) {
F_28 ( V_62 ) ;
return NULL ;
}
F_21 ( & V_70 -> V_81 [ V_73 ] . V_82 ) ;
if ( ! F_22 ( & V_70 -> V_81 [ V_73 ] . V_83 ) ) {
V_85 = F_23 ( & V_70 -> V_81 [ V_73 ] . V_83 ) ;
V_43 = F_25 ( V_85 , struct V_13 , V_84 ) ;
F_26 ( V_43 ) ;
V_62 -> V_64 = V_43 ;
V_62 -> V_73 = V_73 ;
F_27 ( & V_70 -> V_81 [ V_73 ] . V_82 ) ;
* V_66 = V_72 ;
return V_62 ;
}
F_27 ( & V_70 -> V_81 [ V_73 ] . V_82 ) ;
}
}
static void F_31 ( struct V_9 * V_59 , void * V_60 )
{
struct V_61 * V_62 = V_60 ;
if ( V_62 ) {
F_30 ( V_62 -> V_64 ) ;
F_28 ( V_62 ) ;
}
}
static int F_32 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
struct V_9 * V_59 ;
int V_89 = - 1 ;
if ( V_88 -> V_90 == & V_91 )
V_89 = F_33 ( V_88 , & V_78 ) ;
else if ( V_88 -> V_90 == & V_92 )
V_89 = F_33 ( V_88 , & V_79 ) ;
else if ( V_88 -> V_90 == & V_93 )
V_89 = F_33 ( V_88 , & V_80 ) ;
if ( V_89 )
return V_89 ;
V_59 = V_88 -> V_94 ;
V_59 -> V_71 = V_87 -> V_95 ;
return 0 ;
}
static T_3 F_34 ( struct V_88 * V_88 , char T_4 * V_96 ,
T_5 V_97 , T_2 * V_98 )
{
struct V_69 * V_70 = V_88 -> V_94 ;
struct V_11 * V_12 ;
T_5 V_99 = V_100 , V_66 = 0 , V_89 , V_31 ;
F_35 ( & V_101 ) ;
F_35 ( & V_70 -> V_102 ) ;
memset ( V_103 , 0 , sizeof( V_103 ) ) ;
F_8 (lkb, &ls->ls_waiters, lkb_wait_reply) {
V_89 = snprintf ( V_103 + V_66 , V_99 - V_66 , L_43 ,
V_12 -> V_15 , V_12 -> V_24 ,
V_12 -> V_21 , V_12 -> V_104 -> V_34 ) ;
if ( V_89 >= V_99 - V_66 )
break;
V_66 += V_89 ;
}
F_36 ( & V_70 -> V_102 ) ;
V_31 = F_37 ( V_96 , V_97 , V_98 , V_103 , V_66 ) ;
F_36 ( & V_101 ) ;
return V_31 ;
}
void F_38 ( struct V_69 * V_70 )
{
if ( V_70 -> V_105 )
F_39 ( V_70 -> V_105 ) ;
if ( V_70 -> V_106 )
F_39 ( V_70 -> V_106 ) ;
if ( V_70 -> V_107 )
F_39 ( V_70 -> V_107 ) ;
if ( V_70 -> V_108 )
F_39 ( V_70 -> V_108 ) ;
}
int F_40 ( struct V_69 * V_70 )
{
char V_109 [ V_110 + 8 ] ;
V_70 -> V_105 = F_41 ( V_70 -> V_111 ,
V_112 | V_113 ,
V_114 ,
V_70 ,
& V_91 ) ;
if ( ! V_70 -> V_105 )
goto V_115;
memset ( V_109 , 0 , sizeof( V_109 ) ) ;
snprintf ( V_109 , V_110 + 8 , L_44 , V_70 -> V_111 ) ;
V_70 -> V_107 = F_41 ( V_109 ,
V_112 | V_113 ,
V_114 ,
V_70 ,
& V_92 ) ;
if ( ! V_70 -> V_107 )
goto V_115;
memset ( V_109 , 0 , sizeof( V_109 ) ) ;
snprintf ( V_109 , V_110 + 8 , L_45 , V_70 -> V_111 ) ;
V_70 -> V_108 = F_41 ( V_109 ,
V_112 | V_113 ,
V_114 ,
V_70 ,
& V_93 ) ;
if ( ! V_70 -> V_108 )
goto V_115;
memset ( V_109 , 0 , sizeof( V_109 ) ) ;
snprintf ( V_109 , V_110 + 8 , L_46 , V_70 -> V_111 ) ;
V_70 -> V_106 = F_41 ( V_109 ,
V_112 | V_113 ,
V_114 ,
V_70 ,
& V_116 ) ;
if ( ! V_70 -> V_106 )
goto V_115;
return 0 ;
V_115:
F_38 ( V_70 ) ;
return - V_117 ;
}
int T_6 F_42 ( void )
{
F_43 ( & V_101 ) ;
V_114 = F_44 ( L_47 , NULL ) ;
return V_114 ? 0 : - V_117 ;
}
void F_45 ( void )
{
F_39 ( V_114 ) ;
}
