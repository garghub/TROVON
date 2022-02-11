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
return F_4 ( V_10 , L_14 ) ;
}
static int F_5 ( struct V_13 * V_14 , struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_25 , V_26 = V_14 -> V_27 -> V_28 , V_29 , V_30 ;
int V_31 ;
F_6 ( V_14 ) ;
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
V_31 = F_4 ( V_10 , L_18 ) ;
else if ( V_14 -> V_22 == - 1 )
V_31 = F_3 ( V_10 , L_19 ,
V_14 -> V_35 ) ;
else
V_31 = F_3 ( V_10 , L_20 ,
V_14 -> V_22 ) ;
if ( V_31 )
goto V_33;
if ( V_14 -> V_36 ) {
F_4 ( V_10 , L_21 ) ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
if ( V_25 == V_26 / 2 )
F_4 ( V_10 , L_22 ) ;
F_3 ( V_10 , L_23 ,
( unsigned char ) V_14 -> V_36 [ V_25 ] ) ;
}
if ( F_7 ( V_14 , V_37 ) )
F_4 ( V_10 , L_24 ) ;
V_31 = F_4 ( V_10 , L_14 ) ;
if ( V_31 )
goto V_33;
}
V_30 = ! F_8 ( & V_14 -> V_38 ) ;
V_29 = ! F_8 ( & V_14 -> V_39 ) ;
if ( V_30 || V_29 ) {
V_31 = F_3 ( V_10 , L_25
L_26 , V_30 , V_29 ,
V_14 -> V_40 , V_14 -> V_41 ) ;
if ( V_31 )
goto V_33;
}
F_4 ( V_10 , L_27 ) ;
F_9 (lkb, &res->res_grantqueue, lkb_statequeue) {
V_31 = F_2 ( V_10 , V_12 , V_14 ) ;
if ( V_31 )
goto V_33;
}
F_4 ( V_10 , L_28 ) ;
F_9 (lkb, &res->res_convertqueue, lkb_statequeue) {
V_31 = F_2 ( V_10 , V_12 , V_14 ) ;
if ( V_31 )
goto V_33;
}
F_4 ( V_10 , L_29 ) ;
F_9 (lkb, &res->res_waitqueue, lkb_statequeue) {
V_31 = F_2 ( V_10 , V_12 , V_14 ) ;
if ( V_31 )
goto V_33;
}
if ( F_8 ( & V_14 -> V_42 ) )
goto V_33;
F_4 ( V_10 , L_30 ) ;
F_9 (lkb, &res->res_lookup, lkb_rsb_lookup) {
V_31 = F_3 ( V_10 , L_9 , V_12 -> V_15 ,
F_1 ( V_12 -> V_20 ) ) ;
if ( V_12 -> V_24 )
F_3 ( V_10 , L_13 , V_12 -> V_24 ) ;
V_31 = F_4 ( V_10 , L_14 ) ;
}
V_33:
F_10 ( V_14 ) ;
return V_31 ;
}
static int F_11 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_13 * V_43 )
{
T_1 V_44 = 0 ;
T_1 V_45 ;
int V_31 ;
if ( V_12 -> V_46 & V_47 ) {
if ( V_12 -> V_48 )
V_44 = V_12 -> V_48 -> V_44 ;
}
V_45 = F_12 ( F_13 ( F_14 () , V_12 -> V_49 ) ) ;
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
static int F_15 ( struct V_13 * V_43 , struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_31 = 0 ;
F_6 ( V_43 ) ;
F_9 (lkb, &r->res_grantqueue, lkb_statequeue) {
V_31 = F_11 ( V_10 , V_12 , V_43 ) ;
if ( V_31 )
goto V_33;
}
F_9 (lkb, &r->res_convertqueue, lkb_statequeue) {
V_31 = F_11 ( V_10 , V_12 , V_43 ) ;
if ( V_31 )
goto V_33;
}
F_9 (lkb, &r->res_waitqueue, lkb_statequeue) {
V_31 = F_11 ( V_10 , V_12 , V_43 ) ;
if ( V_31 )
goto V_33;
}
V_33:
F_10 ( V_43 ) ;
return V_31 ;
}
static int F_16 ( struct V_9 * V_10 , struct V_11 * V_12 ,
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
( unsigned long long ) F_17 ( V_12 -> V_49 ) ,
( unsigned long long ) F_17 ( V_12 -> V_55 ) ) ;
return V_31 ;
}
static int F_18 ( struct V_13 * V_43 , struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_25 , V_26 = V_43 -> V_27 -> V_28 ;
int V_56 = 1 ;
int V_31 ;
F_6 ( V_43 ) ;
V_31 = F_3 ( V_10 , L_33 ,
V_43 ,
V_43 -> V_22 ,
V_43 -> V_35 ,
V_43 -> V_40 ,
! F_8 ( & V_43 -> V_38 ) ,
! F_8 ( & V_43 -> V_39 ) ,
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
V_31 = F_4 ( V_10 , L_14 ) ;
if ( V_31 )
goto V_33;
if ( ! V_43 -> V_36 )
goto V_57;
F_3 ( V_10 , L_38 , V_43 -> V_58 , V_26 ) ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ )
F_3 ( V_10 , L_37 , ( unsigned char ) V_43 -> V_36 [ V_25 ] ) ;
V_31 = F_4 ( V_10 , L_14 ) ;
if ( V_31 )
goto V_33;
V_57:
F_9 (lkb, &r->res_grantqueue, lkb_statequeue) {
V_31 = F_16 ( V_10 , V_12 , 0 ) ;
if ( V_31 )
goto V_33;
}
F_9 (lkb, &r->res_convertqueue, lkb_statequeue) {
V_31 = F_16 ( V_10 , V_12 , 0 ) ;
if ( V_31 )
goto V_33;
}
F_9 (lkb, &r->res_waitqueue, lkb_statequeue) {
V_31 = F_16 ( V_10 , V_12 , 0 ) ;
if ( V_31 )
goto V_33;
}
F_9 (lkb, &r->res_lookup, lkb_rsb_lookup) {
V_31 = F_16 ( V_10 , V_12 , 1 ) ;
if ( V_31 )
goto V_33;
}
V_33:
F_10 ( V_43 ) ;
return V_31 ;
}
static int F_19 ( struct V_13 * V_43 , struct V_9 * V_10 )
{
int V_59 = F_20 () ;
int V_56 = 1 ;
int V_25 , V_31 ;
F_6 ( V_43 ) ;
V_31 = F_3 ( V_10 , L_39 ,
V_43 ,
V_43 -> V_22 ,
V_43 -> V_60 ,
V_43 -> V_61 ,
V_59 ,
V_43 -> V_62 ,
V_43 -> V_40 ,
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
V_31 = F_4 ( V_10 , L_14 ) ;
V_33:
F_10 ( V_43 ) ;
return V_31 ;
}
static int F_21 ( struct V_9 * V_63 , void * V_64 )
{
struct V_65 * V_66 = V_64 ;
int V_31 = 0 ;
switch ( V_66 -> V_67 ) {
case 1 :
V_31 = F_5 ( V_66 -> V_68 , V_63 ) ;
break;
case 2 :
if ( V_66 -> V_69 ) {
F_3 ( V_63 , L_40
L_41
L_42 ) ;
V_66 -> V_69 = 0 ;
}
V_31 = F_15 ( V_66 -> V_68 , V_63 ) ;
break;
case 3 :
if ( V_66 -> V_69 ) {
F_3 ( V_63 , L_43 ) ;
V_66 -> V_69 = 0 ;
}
V_31 = F_18 ( V_66 -> V_68 , V_63 ) ;
break;
case 4 :
if ( V_66 -> V_69 ) {
F_3 ( V_63 , L_44 ) ;
V_66 -> V_69 = 0 ;
}
V_31 = F_19 ( V_66 -> V_68 , V_63 ) ;
break;
}
return V_31 ;
}
static void * F_22 ( struct V_9 * V_63 , T_2 * V_70 )
{
struct V_71 * V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_76 = V_63 -> V_77 ;
struct V_65 * V_66 ;
struct V_13 * V_43 ;
T_2 V_78 = * V_70 ;
unsigned V_79 , V_80 ;
int V_81 = ( V_63 -> V_82 == & V_83 ) ;
V_79 = V_78 >> 32 ;
V_80 = V_78 & ( ( 1LL << 32 ) - 1 ) ;
if ( V_79 >= V_76 -> V_84 )
return NULL ;
V_66 = F_23 ( sizeof( struct V_65 ) , V_85 ) ;
if ( ! V_66 )
return NULL ;
if ( V_78 == 0 )
V_66 -> V_69 = 1 ;
if ( V_63 -> V_82 == & V_86 )
V_66 -> V_67 = 1 ;
if ( V_63 -> V_82 == & V_87 )
V_66 -> V_67 = 2 ;
if ( V_63 -> V_82 == & V_88 )
V_66 -> V_67 = 3 ;
if ( V_63 -> V_82 == & V_83 )
V_66 -> V_67 = 4 ;
V_72 = V_81 ? & V_76 -> V_89 [ V_79 ] . V_81 : & V_76 -> V_89 [ V_79 ] . V_90 ;
F_24 ( & V_76 -> V_89 [ V_79 ] . V_91 ) ;
if ( ! F_25 ( V_72 ) ) {
for ( V_74 = F_26 ( V_72 ) ; V_74 ; V_74 = F_27 ( V_74 ) ) {
V_43 = F_28 ( V_74 , struct V_13 , V_92 ) ;
if ( ! V_80 -- ) {
F_29 ( V_43 ) ;
V_66 -> V_68 = V_43 ;
V_66 -> V_79 = V_79 ;
F_30 ( & V_76 -> V_89 [ V_79 ] . V_91 ) ;
return V_66 ;
}
}
}
F_30 ( & V_76 -> V_89 [ V_79 ] . V_91 ) ;
V_78 &= ~ ( ( 1LL << 32 ) - 1 ) ;
while ( 1 ) {
V_79 ++ ;
V_78 += 1LL << 32 ;
if ( V_79 >= V_76 -> V_84 ) {
F_31 ( V_66 ) ;
return NULL ;
}
V_72 = V_81 ? & V_76 -> V_89 [ V_79 ] . V_81 : & V_76 -> V_89 [ V_79 ] . V_90 ;
F_24 ( & V_76 -> V_89 [ V_79 ] . V_91 ) ;
if ( ! F_25 ( V_72 ) ) {
V_74 = F_26 ( V_72 ) ;
V_43 = F_28 ( V_74 , struct V_13 , V_92 ) ;
F_29 ( V_43 ) ;
V_66 -> V_68 = V_43 ;
V_66 -> V_79 = V_79 ;
F_30 ( & V_76 -> V_89 [ V_79 ] . V_91 ) ;
* V_70 = V_78 ;
return V_66 ;
}
F_30 ( & V_76 -> V_89 [ V_79 ] . V_91 ) ;
}
}
static void * F_32 ( struct V_9 * V_63 , void * V_64 , T_2 * V_70 )
{
struct V_75 * V_76 = V_63 -> V_77 ;
struct V_65 * V_66 = V_64 ;
struct V_71 * V_72 ;
struct V_73 * V_93 ;
struct V_13 * V_43 , * V_94 ;
T_2 V_78 = * V_70 ;
unsigned V_79 ;
int V_81 = ( V_63 -> V_82 == & V_83 ) ;
V_79 = V_78 >> 32 ;
F_24 ( & V_76 -> V_89 [ V_79 ] . V_91 ) ;
V_94 = V_66 -> V_68 ;
V_93 = F_27 ( & V_94 -> V_92 ) ;
if ( V_93 ) {
V_43 = F_28 ( V_93 , struct V_13 , V_92 ) ;
F_29 ( V_43 ) ;
V_66 -> V_68 = V_43 ;
F_30 ( & V_76 -> V_89 [ V_79 ] . V_91 ) ;
F_33 ( V_94 ) ;
++ * V_70 ;
return V_66 ;
}
F_30 ( & V_76 -> V_89 [ V_79 ] . V_91 ) ;
F_33 ( V_94 ) ;
V_78 &= ~ ( ( 1LL << 32 ) - 1 ) ;
while ( 1 ) {
V_79 ++ ;
V_78 += 1LL << 32 ;
if ( V_79 >= V_76 -> V_84 ) {
F_31 ( V_66 ) ;
return NULL ;
}
V_72 = V_81 ? & V_76 -> V_89 [ V_79 ] . V_81 : & V_76 -> V_89 [ V_79 ] . V_90 ;
F_24 ( & V_76 -> V_89 [ V_79 ] . V_91 ) ;
if ( ! F_25 ( V_72 ) ) {
V_93 = F_26 ( V_72 ) ;
V_43 = F_28 ( V_93 , struct V_13 , V_92 ) ;
F_29 ( V_43 ) ;
V_66 -> V_68 = V_43 ;
V_66 -> V_79 = V_79 ;
F_30 ( & V_76 -> V_89 [ V_79 ] . V_91 ) ;
* V_70 = V_78 ;
return V_66 ;
}
F_30 ( & V_76 -> V_89 [ V_79 ] . V_91 ) ;
}
}
static void F_34 ( struct V_9 * V_63 , void * V_64 )
{
struct V_65 * V_66 = V_64 ;
if ( V_66 ) {
F_33 ( V_66 -> V_68 ) ;
F_31 ( V_66 ) ;
}
}
static int F_35 ( struct V_95 * V_95 , struct V_96 * V_96 )
{
struct V_9 * V_63 ;
int V_97 = - 1 ;
if ( V_96 -> V_98 == & V_99 )
V_97 = F_36 ( V_96 , & V_86 ) ;
else if ( V_96 -> V_98 == & V_100 )
V_97 = F_36 ( V_96 , & V_87 ) ;
else if ( V_96 -> V_98 == & V_101 )
V_97 = F_36 ( V_96 , & V_88 ) ;
else if ( V_96 -> V_98 == & V_102 )
V_97 = F_36 ( V_96 , & V_83 ) ;
if ( V_97 )
return V_97 ;
V_63 = V_96 -> V_103 ;
V_63 -> V_77 = V_95 -> V_104 ;
return 0 ;
}
static T_3 F_37 ( struct V_96 * V_96 , char T_4 * V_105 ,
T_5 V_106 , T_2 * V_107 )
{
struct V_75 * V_76 = V_96 -> V_103 ;
struct V_11 * V_12 ;
T_5 V_108 = V_109 , V_70 = 0 , V_97 , V_31 ;
F_38 ( & V_110 ) ;
F_38 ( & V_76 -> V_111 ) ;
memset ( V_112 , 0 , sizeof( V_112 ) ) ;
F_9 (lkb, &ls->ls_waiters, lkb_wait_reply) {
V_97 = snprintf ( V_112 + V_70 , V_108 - V_70 , L_45 ,
V_12 -> V_15 , V_12 -> V_24 ,
V_12 -> V_21 , V_12 -> V_113 -> V_34 ) ;
if ( V_97 >= V_108 - V_70 )
break;
V_70 += V_97 ;
}
F_39 ( & V_76 -> V_111 ) ;
V_31 = F_40 ( V_105 , V_106 , V_107 , V_112 , V_70 ) ;
F_39 ( & V_110 ) ;
return V_31 ;
}
void F_41 ( struct V_75 * V_76 )
{
F_42 ( V_76 -> V_114 ) ;
F_42 ( V_76 -> V_115 ) ;
F_42 ( V_76 -> V_116 ) ;
F_42 ( V_76 -> V_117 ) ;
F_42 ( V_76 -> V_118 ) ;
}
int F_43 ( struct V_75 * V_76 )
{
char V_119 [ V_120 + 8 ] ;
V_76 -> V_114 = F_44 ( V_76 -> V_121 ,
V_122 | V_123 ,
V_124 ,
V_76 ,
& V_99 ) ;
if ( ! V_76 -> V_114 )
goto V_125;
memset ( V_119 , 0 , sizeof( V_119 ) ) ;
snprintf ( V_119 , V_120 + 8 , L_46 , V_76 -> V_121 ) ;
V_76 -> V_116 = F_44 ( V_119 ,
V_122 | V_123 ,
V_124 ,
V_76 ,
& V_100 ) ;
if ( ! V_76 -> V_116 )
goto V_125;
memset ( V_119 , 0 , sizeof( V_119 ) ) ;
snprintf ( V_119 , V_120 + 8 , L_47 , V_76 -> V_121 ) ;
V_76 -> V_117 = F_44 ( V_119 ,
V_122 | V_123 ,
V_124 ,
V_76 ,
& V_101 ) ;
if ( ! V_76 -> V_117 )
goto V_125;
memset ( V_119 , 0 , sizeof( V_119 ) ) ;
snprintf ( V_119 , V_120 + 8 , L_48 , V_76 -> V_121 ) ;
V_76 -> V_118 = F_44 ( V_119 ,
V_122 | V_123 ,
V_124 ,
V_76 ,
& V_102 ) ;
if ( ! V_76 -> V_118 )
goto V_125;
memset ( V_119 , 0 , sizeof( V_119 ) ) ;
snprintf ( V_119 , V_120 + 8 , L_49 , V_76 -> V_121 ) ;
V_76 -> V_115 = F_44 ( V_119 ,
V_122 | V_123 ,
V_124 ,
V_76 ,
& V_126 ) ;
if ( ! V_76 -> V_115 )
goto V_125;
return 0 ;
V_125:
F_41 ( V_76 ) ;
return - V_127 ;
}
int T_6 F_45 ( void )
{
F_46 ( & V_110 ) ;
V_124 = F_47 ( L_50 , NULL ) ;
return V_124 ? 0 : - V_127 ;
}
void F_48 ( void )
{
F_42 ( V_124 ) ;
}
