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
static void F_2 ( struct V_9 * V_10 , struct V_11 * V_12 ,
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
F_4 ( V_10 , '\n' ) ;
}
static void F_5 ( struct V_13 * V_14 , struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_25 , V_26 = V_14 -> V_27 -> V_28 , V_29 , V_30 ;
F_6 ( V_14 ) ;
F_3 ( V_10 , L_14 , V_14 , V_14 -> V_31 ) ;
for ( V_25 = 0 ; V_25 < V_14 -> V_31 ; V_25 ++ ) {
if ( isprint ( V_14 -> V_32 [ V_25 ] ) )
F_3 ( V_10 , L_15 , V_14 -> V_32 [ V_25 ] ) ;
else
F_3 ( V_10 , L_15 , '.' ) ;
}
if ( V_14 -> V_22 > 0 )
F_3 ( V_10 , L_16 ,
V_14 -> V_22 ) ;
else if ( V_14 -> V_22 == 0 )
F_7 ( V_10 , L_17 ) ;
else if ( V_14 -> V_22 == - 1 )
F_3 ( V_10 , L_18 ,
V_14 -> V_33 ) ;
else
F_3 ( V_10 , L_19 , V_14 -> V_22 ) ;
if ( F_8 ( V_10 ) )
goto V_34;
if ( V_14 -> V_35 ) {
F_7 ( V_10 , L_20 ) ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
if ( V_25 == V_26 / 2 )
F_7 ( V_10 , L_21 ) ;
F_3 ( V_10 , L_22 ,
( unsigned char ) V_14 -> V_35 [ V_25 ] ) ;
}
if ( F_9 ( V_14 , V_36 ) )
F_7 ( V_10 , L_23 ) ;
F_4 ( V_10 , '\n' ) ;
if ( F_8 ( V_10 ) )
goto V_34;
}
V_30 = ! F_10 ( & V_14 -> V_37 ) ;
V_29 = ! F_10 ( & V_14 -> V_38 ) ;
if ( V_30 || V_29 ) {
F_3 ( V_10 , L_24 ,
V_30 , V_29 ,
V_14 -> V_39 , V_14 -> V_40 ) ;
}
F_7 ( V_10 , L_25 ) ;
F_11 (lkb, &res->res_grantqueue, lkb_statequeue) {
F_2 ( V_10 , V_12 , V_14 ) ;
if ( F_8 ( V_10 ) )
goto V_34;
}
F_7 ( V_10 , L_26 ) ;
F_11 (lkb, &res->res_convertqueue, lkb_statequeue) {
F_2 ( V_10 , V_12 , V_14 ) ;
if ( F_8 ( V_10 ) )
goto V_34;
}
F_7 ( V_10 , L_27 ) ;
F_11 (lkb, &res->res_waitqueue, lkb_statequeue) {
F_2 ( V_10 , V_12 , V_14 ) ;
if ( F_8 ( V_10 ) )
goto V_34;
}
if ( F_10 ( & V_14 -> V_41 ) )
goto V_34;
F_7 ( V_10 , L_28 ) ;
F_11 (lkb, &res->res_lookup, lkb_rsb_lookup) {
F_3 ( V_10 , L_9 ,
V_12 -> V_15 , F_1 ( V_12 -> V_20 ) ) ;
if ( V_12 -> V_24 )
F_3 ( V_10 , L_13 , V_12 -> V_24 ) ;
F_4 ( V_10 , '\n' ) ;
if ( F_8 ( V_10 ) )
goto V_34;
}
V_34:
F_12 ( V_14 ) ;
}
static void F_13 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_13 * V_42 )
{
T_1 V_43 = 0 ;
T_1 V_44 ;
if ( V_12 -> V_45 & V_46 ) {
if ( V_12 -> V_47 )
V_43 = V_12 -> V_47 -> V_43 ;
}
V_44 = F_14 ( F_15 ( F_16 () , V_12 -> V_48 ) ) ;
F_3 ( V_10 , L_29 ,
V_12 -> V_15 ,
V_12 -> V_21 ,
V_12 -> V_23 ,
V_12 -> V_49 ,
( unsigned long long ) V_43 ,
V_12 -> V_50 ,
V_12 -> V_45 ,
V_12 -> V_17 ,
V_12 -> V_16 ,
V_12 -> V_20 ,
( unsigned long long ) V_44 ,
V_42 -> V_22 ,
V_42 -> V_31 ,
V_42 -> V_32 ) ;
}
static void F_17 ( struct V_13 * V_42 , struct V_9 * V_10 )
{
struct V_11 * V_12 ;
F_6 ( V_42 ) ;
F_11 (lkb, &r->res_grantqueue, lkb_statequeue) {
F_13 ( V_10 , V_12 , V_42 ) ;
if ( F_8 ( V_10 ) )
goto V_34;
}
F_11 (lkb, &r->res_convertqueue, lkb_statequeue) {
F_13 ( V_10 , V_12 , V_42 ) ;
if ( F_8 ( V_10 ) )
goto V_34;
}
F_11 (lkb, &r->res_waitqueue, lkb_statequeue) {
F_13 ( V_10 , V_12 , V_42 ) ;
if ( F_8 ( V_10 ) )
goto V_34;
}
V_34:
F_12 ( V_42 ) ;
}
static void F_18 ( struct V_9 * V_10 , struct V_11 * V_12 ,
int V_51 )
{
T_1 V_43 = 0 ;
if ( V_12 -> V_45 & V_46 ) {
if ( V_12 -> V_47 )
V_43 = V_12 -> V_47 -> V_43 ;
}
F_3 ( V_10 , L_30 ,
V_12 -> V_15 ,
V_12 -> V_21 ,
V_12 -> V_23 ,
V_12 -> V_49 ,
( unsigned long long ) V_43 ,
V_12 -> V_50 ,
V_12 -> V_45 ,
V_12 -> V_17 ,
V_12 -> V_16 ,
V_12 -> V_20 ,
V_12 -> V_52 . V_1 ,
V_51 ,
V_12 -> V_24 ,
V_12 -> V_53 ,
( unsigned long long ) F_19 ( V_12 -> V_48 ) ,
( unsigned long long ) F_19 ( V_12 -> V_54 ) ) ;
}
static void F_20 ( struct V_13 * V_42 , struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_25 , V_26 = V_42 -> V_27 -> V_28 ;
int V_55 = 1 ;
F_6 ( V_42 ) ;
F_3 ( V_10 , L_31 ,
V_42 ,
V_42 -> V_22 ,
V_42 -> V_33 ,
V_42 -> V_39 ,
! F_10 ( & V_42 -> V_37 ) ,
! F_10 ( & V_42 -> V_38 ) ,
V_42 -> V_40 ,
V_42 -> V_31 ) ;
if ( F_8 ( V_10 ) )
goto V_34;
for ( V_25 = 0 ; V_25 < V_42 -> V_31 ; V_25 ++ ) {
if ( ! isascii ( V_42 -> V_32 [ V_25 ] ) || ! isprint ( V_42 -> V_32 [ V_25 ] ) )
V_55 = 0 ;
}
F_7 ( V_10 , V_55 ? L_32 : L_33 ) ;
for ( V_25 = 0 ; V_25 < V_42 -> V_31 ; V_25 ++ ) {
if ( V_55 )
F_3 ( V_10 , L_15 , V_42 -> V_32 [ V_25 ] ) ;
else
F_3 ( V_10 , L_34 , ( unsigned char ) V_42 -> V_32 [ V_25 ] ) ;
}
F_4 ( V_10 , '\n' ) ;
if ( F_8 ( V_10 ) )
goto V_34;
if ( ! V_42 -> V_35 )
goto V_56;
F_3 ( V_10 , L_35 , V_42 -> V_57 , V_26 ) ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ )
F_3 ( V_10 , L_34 , ( unsigned char ) V_42 -> V_35 [ V_25 ] ) ;
F_4 ( V_10 , '\n' ) ;
if ( F_8 ( V_10 ) )
goto V_34;
V_56:
F_11 (lkb, &r->res_grantqueue, lkb_statequeue) {
F_18 ( V_10 , V_12 , 0 ) ;
if ( F_8 ( V_10 ) )
goto V_34;
}
F_11 (lkb, &r->res_convertqueue, lkb_statequeue) {
F_18 ( V_10 , V_12 , 0 ) ;
if ( F_8 ( V_10 ) )
goto V_34;
}
F_11 (lkb, &r->res_waitqueue, lkb_statequeue) {
F_18 ( V_10 , V_12 , 0 ) ;
if ( F_8 ( V_10 ) )
goto V_34;
}
F_11 (lkb, &r->res_lookup, lkb_rsb_lookup) {
F_18 ( V_10 , V_12 , 1 ) ;
if ( F_8 ( V_10 ) )
goto V_34;
}
V_34:
F_12 ( V_42 ) ;
}
static void F_21 ( struct V_13 * V_42 , struct V_9 * V_10 )
{
int V_58 = F_22 () ;
int V_55 = 1 ;
int V_25 ;
F_6 ( V_42 ) ;
F_3 ( V_10 , L_36 ,
V_42 ,
V_42 -> V_22 ,
V_42 -> V_59 ,
V_42 -> V_60 ,
V_58 ,
V_42 -> V_61 ,
V_42 -> V_39 ,
V_42 -> V_31 ) ;
for ( V_25 = 0 ; V_25 < V_42 -> V_31 ; V_25 ++ ) {
if ( ! isascii ( V_42 -> V_32 [ V_25 ] ) || ! isprint ( V_42 -> V_32 [ V_25 ] ) )
V_55 = 0 ;
}
F_7 ( V_10 , V_55 ? L_32 : L_33 ) ;
for ( V_25 = 0 ; V_25 < V_42 -> V_31 ; V_25 ++ ) {
if ( V_55 )
F_3 ( V_10 , L_15 , V_42 -> V_32 [ V_25 ] ) ;
else
F_3 ( V_10 , L_34 , ( unsigned char ) V_42 -> V_32 [ V_25 ] ) ;
}
F_4 ( V_10 , '\n' ) ;
F_12 ( V_42 ) ;
}
static int F_23 ( struct V_9 * V_62 , void * V_63 )
{
struct V_64 * V_65 = V_63 ;
switch ( V_65 -> V_66 ) {
case 1 :
F_5 ( V_65 -> V_67 , V_62 ) ;
break;
case 2 :
if ( V_65 -> V_68 ) {
F_7 ( V_62 , L_37 ) ;
V_65 -> V_68 = 0 ;
}
F_17 ( V_65 -> V_67 , V_62 ) ;
break;
case 3 :
if ( V_65 -> V_68 ) {
F_7 ( V_62 , L_38 ) ;
V_65 -> V_68 = 0 ;
}
F_20 ( V_65 -> V_67 , V_62 ) ;
break;
case 4 :
if ( V_65 -> V_68 ) {
F_7 ( V_62 , L_39 ) ;
V_65 -> V_68 = 0 ;
}
F_21 ( V_65 -> V_67 , V_62 ) ;
break;
}
return 0 ;
}
static void * F_24 ( struct V_9 * V_62 , T_2 * V_69 )
{
struct V_70 * V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 = V_62 -> V_76 ;
struct V_64 * V_65 ;
struct V_13 * V_42 ;
T_2 V_77 = * V_69 ;
unsigned V_78 , V_79 ;
int V_80 = ( V_62 -> V_81 == & V_82 ) ;
V_78 = V_77 >> 32 ;
V_79 = V_77 & ( ( 1LL << 32 ) - 1 ) ;
if ( V_78 >= V_75 -> V_83 )
return NULL ;
V_65 = F_25 ( sizeof( * V_65 ) , V_84 ) ;
if ( ! V_65 )
return NULL ;
if ( V_77 == 0 )
V_65 -> V_68 = 1 ;
if ( V_62 -> V_81 == & V_85 )
V_65 -> V_66 = 1 ;
if ( V_62 -> V_81 == & V_86 )
V_65 -> V_66 = 2 ;
if ( V_62 -> V_81 == & V_87 )
V_65 -> V_66 = 3 ;
if ( V_62 -> V_81 == & V_82 )
V_65 -> V_66 = 4 ;
V_71 = V_80 ? & V_75 -> V_88 [ V_78 ] . V_80 : & V_75 -> V_88 [ V_78 ] . V_89 ;
F_26 ( & V_75 -> V_88 [ V_78 ] . V_90 ) ;
if ( ! F_27 ( V_71 ) ) {
for ( V_73 = F_28 ( V_71 ) ; V_73 ; V_73 = F_29 ( V_73 ) ) {
V_42 = F_30 ( V_73 , struct V_13 , V_91 ) ;
if ( ! V_79 -- ) {
F_31 ( V_42 ) ;
V_65 -> V_67 = V_42 ;
V_65 -> V_78 = V_78 ;
F_32 ( & V_75 -> V_88 [ V_78 ] . V_90 ) ;
return V_65 ;
}
}
}
F_32 ( & V_75 -> V_88 [ V_78 ] . V_90 ) ;
V_77 &= ~ ( ( 1LL << 32 ) - 1 ) ;
while ( 1 ) {
V_78 ++ ;
V_77 += 1LL << 32 ;
if ( V_78 >= V_75 -> V_83 ) {
F_33 ( V_65 ) ;
return NULL ;
}
V_71 = V_80 ? & V_75 -> V_88 [ V_78 ] . V_80 : & V_75 -> V_88 [ V_78 ] . V_89 ;
F_26 ( & V_75 -> V_88 [ V_78 ] . V_90 ) ;
if ( ! F_27 ( V_71 ) ) {
V_73 = F_28 ( V_71 ) ;
V_42 = F_30 ( V_73 , struct V_13 , V_91 ) ;
F_31 ( V_42 ) ;
V_65 -> V_67 = V_42 ;
V_65 -> V_78 = V_78 ;
F_32 ( & V_75 -> V_88 [ V_78 ] . V_90 ) ;
* V_69 = V_77 ;
return V_65 ;
}
F_32 ( & V_75 -> V_88 [ V_78 ] . V_90 ) ;
}
}
static void * F_34 ( struct V_9 * V_62 , void * V_63 , T_2 * V_69 )
{
struct V_74 * V_75 = V_62 -> V_76 ;
struct V_64 * V_65 = V_63 ;
struct V_70 * V_71 ;
struct V_72 * V_92 ;
struct V_13 * V_42 , * V_93 ;
T_2 V_77 = * V_69 ;
unsigned V_78 ;
int V_80 = ( V_62 -> V_81 == & V_82 ) ;
V_78 = V_77 >> 32 ;
F_26 ( & V_75 -> V_88 [ V_78 ] . V_90 ) ;
V_93 = V_65 -> V_67 ;
V_92 = F_29 ( & V_93 -> V_91 ) ;
if ( V_92 ) {
V_42 = F_30 ( V_92 , struct V_13 , V_91 ) ;
F_31 ( V_42 ) ;
V_65 -> V_67 = V_42 ;
F_32 ( & V_75 -> V_88 [ V_78 ] . V_90 ) ;
F_35 ( V_93 ) ;
++ * V_69 ;
return V_65 ;
}
F_32 ( & V_75 -> V_88 [ V_78 ] . V_90 ) ;
F_35 ( V_93 ) ;
V_77 &= ~ ( ( 1LL << 32 ) - 1 ) ;
while ( 1 ) {
V_78 ++ ;
V_77 += 1LL << 32 ;
if ( V_78 >= V_75 -> V_83 ) {
F_33 ( V_65 ) ;
return NULL ;
}
V_71 = V_80 ? & V_75 -> V_88 [ V_78 ] . V_80 : & V_75 -> V_88 [ V_78 ] . V_89 ;
F_26 ( & V_75 -> V_88 [ V_78 ] . V_90 ) ;
if ( ! F_27 ( V_71 ) ) {
V_92 = F_28 ( V_71 ) ;
V_42 = F_30 ( V_92 , struct V_13 , V_91 ) ;
F_31 ( V_42 ) ;
V_65 -> V_67 = V_42 ;
V_65 -> V_78 = V_78 ;
F_32 ( & V_75 -> V_88 [ V_78 ] . V_90 ) ;
* V_69 = V_77 ;
return V_65 ;
}
F_32 ( & V_75 -> V_88 [ V_78 ] . V_90 ) ;
}
}
static void F_36 ( struct V_9 * V_62 , void * V_63 )
{
struct V_64 * V_65 = V_63 ;
if ( V_65 ) {
F_35 ( V_65 -> V_67 ) ;
F_33 ( V_65 ) ;
}
}
static int F_37 ( struct V_94 * V_94 , struct V_95 * V_95 )
{
struct V_9 * V_62 ;
int V_96 ;
V_96 = F_38 ( V_95 , & V_85 ) ;
if ( V_96 )
return V_96 ;
V_62 = V_95 -> V_97 ;
V_62 -> V_76 = V_94 -> V_98 ;
return 0 ;
}
static int F_39 ( struct V_94 * V_94 , struct V_95 * V_95 )
{
struct V_9 * V_62 ;
int V_96 ;
V_96 = F_38 ( V_95 , & V_86 ) ;
if ( V_96 )
return V_96 ;
V_62 = V_95 -> V_97 ;
V_62 -> V_76 = V_94 -> V_98 ;
return 0 ;
}
static int F_40 ( struct V_94 * V_94 , struct V_95 * V_95 )
{
struct V_9 * V_62 ;
int V_96 ;
V_96 = F_38 ( V_95 , & V_87 ) ;
if ( V_96 )
return V_96 ;
V_62 = V_95 -> V_97 ;
V_62 -> V_76 = V_94 -> V_98 ;
return 0 ;
}
static int F_41 ( struct V_94 * V_94 , struct V_95 * V_95 )
{
struct V_9 * V_62 ;
int V_96 ;
V_96 = F_38 ( V_95 , & V_82 ) ;
if ( V_96 )
return V_96 ;
V_62 = V_95 -> V_97 ;
V_62 -> V_76 = V_94 -> V_98 ;
return 0 ;
}
static T_3 F_42 ( struct V_95 * V_95 , char T_4 * V_99 ,
T_5 V_100 , T_2 * V_101 )
{
struct V_74 * V_75 = V_95 -> V_97 ;
struct V_11 * V_12 ;
T_5 V_102 = V_103 , V_69 = 0 , V_96 , V_104 ;
F_43 ( & V_105 ) ;
F_43 ( & V_75 -> V_106 ) ;
memset ( V_107 , 0 , sizeof( V_107 ) ) ;
F_11 (lkb, &ls->ls_waiters, lkb_wait_reply) {
V_96 = snprintf ( V_107 + V_69 , V_102 - V_69 , L_40 ,
V_12 -> V_15 , V_12 -> V_24 ,
V_12 -> V_21 , V_12 -> V_108 -> V_32 ) ;
if ( V_96 >= V_102 - V_69 )
break;
V_69 += V_96 ;
}
F_44 ( & V_75 -> V_106 ) ;
V_104 = F_45 ( V_99 , V_100 , V_101 , V_107 , V_69 ) ;
F_44 ( & V_105 ) ;
return V_104 ;
}
void F_46 ( struct V_74 * V_75 )
{
F_47 ( V_75 -> V_109 ) ;
F_47 ( V_75 -> V_110 ) ;
F_47 ( V_75 -> V_111 ) ;
F_47 ( V_75 -> V_112 ) ;
F_47 ( V_75 -> V_113 ) ;
}
int F_48 ( struct V_74 * V_75 )
{
char V_114 [ V_115 + 8 ] ;
V_75 -> V_109 = F_49 ( V_75 -> V_116 ,
V_117 | V_118 ,
V_119 ,
V_75 ,
& V_120 ) ;
if ( ! V_75 -> V_109 )
goto V_121;
memset ( V_114 , 0 , sizeof( V_114 ) ) ;
snprintf ( V_114 , V_115 + 8 , L_41 , V_75 -> V_116 ) ;
V_75 -> V_111 = F_49 ( V_114 ,
V_117 | V_118 ,
V_119 ,
V_75 ,
& V_122 ) ;
if ( ! V_75 -> V_111 )
goto V_121;
memset ( V_114 , 0 , sizeof( V_114 ) ) ;
snprintf ( V_114 , V_115 + 8 , L_42 , V_75 -> V_116 ) ;
V_75 -> V_112 = F_49 ( V_114 ,
V_117 | V_118 ,
V_119 ,
V_75 ,
& V_123 ) ;
if ( ! V_75 -> V_112 )
goto V_121;
memset ( V_114 , 0 , sizeof( V_114 ) ) ;
snprintf ( V_114 , V_115 + 8 , L_43 , V_75 -> V_116 ) ;
V_75 -> V_113 = F_49 ( V_114 ,
V_117 | V_118 ,
V_119 ,
V_75 ,
& V_124 ) ;
if ( ! V_75 -> V_113 )
goto V_121;
memset ( V_114 , 0 , sizeof( V_114 ) ) ;
snprintf ( V_114 , V_115 + 8 , L_44 , V_75 -> V_116 ) ;
V_75 -> V_110 = F_49 ( V_114 ,
V_117 | V_118 ,
V_119 ,
V_75 ,
& V_125 ) ;
if ( ! V_75 -> V_110 )
goto V_121;
return 0 ;
V_121:
F_46 ( V_75 ) ;
return - V_126 ;
}
int T_6 F_50 ( void )
{
F_51 ( & V_105 ) ;
V_119 = F_52 ( L_45 , NULL ) ;
return V_119 ? 0 : - V_126 ;
}
void F_53 ( void )
{
F_47 ( V_119 ) ;
}
