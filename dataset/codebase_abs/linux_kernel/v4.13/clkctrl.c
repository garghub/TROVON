static T_1 F_1 ( T_1 V_1 )
{
V_1 &= V_2 ;
V_1 >>= V_3 ;
return V_1 ;
}
static bool F_2 ( T_1 V_1 )
{
V_1 = F_1 ( V_1 ) ;
return V_1 == V_4 ;
}
static bool F_3 ( T_1 V_1 )
{
V_1 = F_1 ( V_1 ) ;
return V_1 == V_5 ||
V_1 == V_6 ;
}
static bool F_4 ( union V_7 * time , T_1 V_8 )
{
if ( F_5 ( V_9 ) ) {
if ( time -> V_10 ++ < V_8 ) {
F_6 ( 1 ) ;
return false ;
}
} else {
if ( ! F_7 ( time -> V_11 ) ) {
time -> V_11 = F_8 () ;
return false ;
}
if ( F_9 ( F_8 () , time -> V_11 ) < V_8 ) {
F_10 () ;
return false ;
}
}
return true ;
}
static int T_2 F_11 ( void )
{
V_9 = false ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_13 ( V_13 ) ;
T_1 V_1 ;
int V_16 ;
union V_7 V_8 = { 0 } ;
if ( ! V_15 -> V_17 )
return 0 ;
if ( V_15 -> V_18 ) {
V_16 = V_19 -> V_20 ( V_15 -> V_18 , V_13 -> V_15 ) ;
if ( V_16 ) {
F_14 ( 1 ,
L_1 ,
V_21 , F_15 ( V_13 ) ,
V_15 -> V_22 , V_16 ) ;
return V_16 ;
}
}
V_1 = V_19 -> V_23 ( & V_15 -> V_24 ) ;
V_1 &= ~ V_25 ;
V_1 |= V_15 -> V_17 ;
V_19 -> V_26 ( V_1 , & V_15 -> V_24 ) ;
if ( V_15 -> V_27 & V_28 )
return 0 ;
while ( ! F_3 ( V_19 -> V_23 ( & V_15 -> V_24 ) ) ) {
if ( F_4 ( & V_8 , V_29 ) ) {
F_16 ( L_2 , F_15 ( V_13 ) ) ;
return - V_30 ;
}
}
return 0 ;
}
static void F_17 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_13 ( V_13 ) ;
T_1 V_1 ;
union V_7 V_8 = { 0 } ;
if ( ! V_15 -> V_17 )
return;
V_1 = V_19 -> V_23 ( & V_15 -> V_24 ) ;
V_1 &= ~ V_25 ;
V_19 -> V_26 ( V_1 , & V_15 -> V_24 ) ;
if ( V_15 -> V_27 & V_28 )
goto exit;
while ( ! F_2 ( V_19 -> V_23 ( & V_15 -> V_24 ) ) ) {
if ( F_4 ( & V_8 ,
V_31 ) ) {
F_16 ( L_3 , F_15 ( V_13 ) ) ;
break;
}
}
exit:
if ( V_15 -> V_18 )
V_19 -> V_32 ( V_15 -> V_18 , V_13 -> V_15 ) ;
}
static int F_18 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_13 ( V_13 ) ;
T_1 V_1 ;
V_1 = V_19 -> V_23 ( & V_15 -> V_24 ) ;
if ( V_1 & V_15 -> V_17 )
return 1 ;
return 0 ;
}
static struct V_12 * F_19 ( struct V_33 * V_34 ,
void * V_35 )
{
struct V_36 * V_37 = V_35 ;
struct V_38 * V_39 ;
if ( V_34 -> V_40 != 2 )
return F_20 ( - V_41 ) ;
F_21 ( L_4 , V_21 ,
V_34 -> args [ 0 ] , V_34 -> args [ 1 ] ) ;
F_22 (entry, &provider->clocks, node) {
if ( V_39 -> V_42 == V_34 -> args [ 0 ] &&
V_39 -> V_43 == V_34 -> args [ 1 ] )
break;
}
if ( ! V_39 )
return F_20 ( - V_41 ) ;
return V_39 -> V_15 ;
}
static int T_2
F_23 ( struct V_36 * V_37 ,
struct V_44 * V_45 , struct V_12 * V_12 ,
T_3 V_46 , T_4 V_47 , const char * const * V_48 ,
int V_49 , const struct V_50 * V_51 )
{
struct V_52 V_53 = { NULL } ;
struct V_15 * V_15 ;
struct V_38 * V_54 ;
int V_16 = 0 ;
V_53 . V_55 = F_24 ( V_56 , L_5 , V_45 -> V_57 -> V_55 ,
V_45 -> V_55 , V_46 , V_47 ) ;
V_54 = F_25 ( sizeof( * V_54 ) , V_56 ) ;
if ( ! V_53 . V_55 || ! V_54 ) {
V_16 = - V_58 ;
goto V_59;
}
V_12 -> V_53 = & V_53 ;
V_53 . V_60 = V_48 ;
V_53 . V_49 = V_49 ;
V_53 . V_51 = V_51 ;
V_53 . V_27 = V_61 ;
V_15 = F_26 ( NULL , V_12 , V_53 . V_55 ) ;
if ( F_27 ( V_15 ) ) {
V_16 = - V_41 ;
goto V_59;
}
V_54 -> V_42 = V_46 ;
V_54 -> V_43 = V_47 ;
V_54 -> V_15 = V_12 ;
F_28 ( & V_54 -> V_45 , & V_37 -> V_62 ) ;
return 0 ;
V_59:
F_29 ( V_53 . V_55 ) ;
F_29 ( V_54 ) ;
return V_16 ;
}
static void T_2
F_30 ( struct V_36 * V_37 ,
struct V_44 * V_45 , T_3 V_46 ,
const struct V_63 * V_35 ,
void T_5 * V_64 )
{
struct V_14 * V_12 ;
V_12 = F_25 ( sizeof( * V_12 ) , V_56 ) ;
if ( ! V_12 )
return;
V_12 -> V_17 = V_35 -> V_47 ;
V_12 -> V_24 . V_65 = V_64 ;
if ( F_23 ( V_37 , V_45 , & V_12 -> V_13 , V_46 ,
V_35 -> V_47 , V_35 -> V_48 , 1 ,
& V_66 ) )
F_29 ( V_12 ) ;
}
static void T_2
F_31 ( struct V_36 * V_37 ,
struct V_44 * V_45 , T_3 V_46 ,
const struct V_63 * V_35 ,
void T_5 * V_64 )
{
struct V_67 * V_68 ;
int V_49 = 0 ;
const char * const * V_69 ;
V_68 = F_25 ( sizeof( * V_68 ) , V_56 ) ;
if ( ! V_68 )
return;
V_69 = V_35 -> V_48 ;
while ( * V_69 ) {
V_49 ++ ;
V_69 ++ ;
}
V_68 -> V_70 = V_49 ;
V_68 -> V_70 = ( 1 << F_32 ( V_68 -> V_70 ) ) - 1 ;
V_68 -> V_71 = V_35 -> V_47 ;
V_68 -> V_64 . V_65 = V_64 ;
if ( F_23 ( V_37 , V_45 , & V_68 -> V_13 , V_46 ,
V_35 -> V_47 , V_35 -> V_48 , V_49 ,
& V_72 ) )
F_29 ( V_68 ) ;
}
static void T_2
F_33 ( struct V_36 * V_37 ,
struct V_44 * V_45 , T_3 V_46 ,
const struct V_63 * V_35 ,
void T_5 * V_64 )
{
struct V_73 * div ;
const struct V_74 * V_75 = V_35 -> V_35 ;
div = F_25 ( sizeof( * div ) , V_56 ) ;
if ( ! div )
return;
div -> V_64 . V_65 = V_64 ;
div -> V_71 = V_35 -> V_47 ;
if ( F_34 ( ( int * ) V_75 -> V_76 ,
V_75 -> V_77 , 0 , 0 ,
& div -> V_78 , & div -> V_79 ) ) {
F_16 ( L_6 , V_21 ,
V_45 -> V_55 , V_46 , V_35 -> V_47 ) ;
F_29 ( div ) ;
return;
}
if ( F_23 ( V_37 , V_45 , & div -> V_13 , V_46 ,
V_35 -> V_47 , V_35 -> V_48 , 1 ,
& V_80 ) )
F_29 ( div ) ;
}
static void T_2
F_35 ( struct V_36 * V_37 ,
struct V_44 * V_45 ,
const struct V_81 * V_35 ,
void T_5 * V_64 )
{
const struct V_63 * V_82 = V_35 -> V_83 ;
if ( ! V_82 )
return;
while ( V_82 -> V_47 ) {
switch ( V_82 -> type ) {
case V_84 :
F_30 ( V_37 , V_45 , V_35 -> V_46 ,
V_82 , V_64 ) ;
break;
case V_85 :
F_33 ( V_37 , V_45 , V_35 -> V_46 ,
V_82 , V_64 ) ;
break;
case V_86 :
F_31 ( V_37 , V_45 , V_35 -> V_46 ,
V_82 , V_64 ) ;
break;
default:
F_16 ( L_7 , V_21 ,
V_82 -> type ) ;
return;
}
V_82 ++ ;
}
}
static void T_2 F_36 ( struct V_44 * V_45 )
{
struct V_36 * V_37 ;
const struct V_87 * V_35 = V_88 ;
const struct V_81 * V_89 ;
struct V_52 V_53 = { NULL } ;
struct V_14 * V_13 ;
struct V_15 * V_15 ;
struct V_38 * V_54 ;
const T_6 * V_90 ;
T_1 V_91 ;
V_90 = F_37 ( V_45 , 0 , NULL , NULL ) ;
V_91 = ( T_1 ) F_38 ( V_45 , V_90 ) ;
#ifdef F_39
if ( F_40 ( L_8 ) )
V_35 = V_92 ;
#endif
while ( V_35 -> V_91 ) {
if ( V_91 == V_35 -> V_91 )
break;
V_35 ++ ;
}
if ( ! V_35 -> V_91 ) {
F_16 ( L_9 , V_45 -> V_55 ) ;
return;
}
V_37 = F_25 ( sizeof( * V_37 ) , V_56 ) ;
if ( ! V_37 )
return;
V_37 -> V_93 = F_41 ( V_45 , 0 ) ;
F_42 ( & V_37 -> V_62 ) ;
V_89 = V_35 -> V_94 ;
while ( V_89 -> V_57 ) {
V_13 = F_25 ( sizeof( * V_13 ) , V_56 ) ;
if ( ! V_13 )
return;
V_13 -> V_24 . V_65 = V_37 -> V_93 + V_89 -> V_46 ;
F_35 ( V_37 , V_45 , V_89 ,
V_13 -> V_24 . V_65 ) ;
if ( V_89 -> V_27 & V_95 )
V_13 -> V_17 = V_96 ;
if ( V_89 -> V_27 & V_97 )
V_13 -> V_17 = V_98 ;
if ( V_89 -> V_27 & V_99 )
V_13 -> V_27 |= V_28 ;
V_53 . V_60 = & V_89 -> V_57 ;
V_53 . V_49 = 1 ;
V_53 . V_27 = 0 ;
V_53 . V_55 = F_24 ( V_56 , L_5 ,
V_45 -> V_57 -> V_55 , V_45 -> V_55 ,
V_89 -> V_46 , 0 ) ;
V_54 = F_25 ( sizeof( * V_54 ) , V_56 ) ;
if ( ! V_53 . V_55 || ! V_54 )
goto V_59;
V_53 . V_51 = & V_100 ;
V_13 -> V_13 . V_53 = & V_53 ;
V_15 = F_26 ( NULL , & V_13 -> V_13 , V_53 . V_55 ) ;
if ( F_27 ( V_15 ) )
goto V_59;
V_54 -> V_42 = V_89 -> V_46 ;
V_54 -> V_15 = & V_13 -> V_13 ;
F_28 ( & V_54 -> V_45 , & V_37 -> V_62 ) ;
V_89 ++ ;
}
F_43 ( V_45 , F_19 , V_37 ) ;
return;
V_59:
F_29 ( V_13 ) ;
F_29 ( V_53 . V_55 ) ;
F_29 ( V_54 ) ;
}
