int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 -> V_5 )
return - V_6 ;
F_2 ( & V_7 ) ;
F_3 (alg, &rate_ctrl_algs, list) {
if ( ! strcmp ( V_4 -> V_2 -> V_5 , V_2 -> V_5 ) ) {
F_4 ( 1 ) ;
F_5 ( & V_7 ) ;
return - V_8 ;
}
}
V_4 = F_6 ( sizeof( * V_4 ) , V_9 ) ;
if ( V_4 == NULL ) {
F_5 ( & V_7 ) ;
return - V_10 ;
}
V_4 -> V_2 = V_2 ;
F_7 ( & V_4 -> V_11 , & V_12 ) ;
F_5 ( & V_7 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_7 ) ;
F_3 (alg, &rate_ctrl_algs, list) {
if ( V_4 -> V_2 == V_2 ) {
F_9 ( & V_4 -> V_11 ) ;
F_10 ( V_4 ) ;
break;
}
}
F_5 ( & V_7 ) ;
}
static struct V_1 *
F_11 ( const char * V_5 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 = NULL ;
if ( ! V_5 )
return NULL ;
F_2 ( & V_7 ) ;
F_3 (alg, &rate_ctrl_algs, list) {
if ( ! strcmp ( V_4 -> V_2 -> V_5 , V_5 ) )
if ( F_12 ( V_4 -> V_2 -> V_13 ) ) {
V_2 = V_4 -> V_2 ;
break;
}
}
F_5 ( & V_7 ) ;
return V_2 ;
}
static struct V_1 *
F_13 ( const char * V_5 )
{
struct V_1 * V_2 ;
const char * V_14 ;
F_14 ( V_15 ) ;
if ( ! V_5 )
V_14 = V_15 ;
else
V_14 = V_5 ;
V_2 = F_11 ( V_14 ) ;
if ( ! V_2 ) {
F_15 ( L_1 , V_14 ) ;
V_2 = F_11 ( V_14 ) ;
}
if ( ! V_2 && V_5 )
V_2 = F_11 ( V_15 ) ;
if ( ! V_2 && strlen ( V_16 ) )
V_2 = F_11 ( V_16 ) ;
F_16 ( V_15 ) ;
return V_2 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 -> V_13 ) ;
}
static T_1 F_19 ( struct V_17 * V_17 , char T_2 * V_18 ,
T_3 V_19 , T_4 * V_20 )
{
struct V_21 * V_22 = V_17 -> V_23 ;
int V_24 = strlen ( V_22 -> V_2 -> V_5 ) ;
return F_20 ( V_18 , V_19 , V_20 ,
V_22 -> V_2 -> V_5 , V_24 ) ;
}
static struct V_21 * F_21 ( const char * V_5 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 = NULL ;
struct V_21 * V_22 ;
V_22 = F_22 ( sizeof( struct V_21 ) , V_9 ) ;
if ( ! V_22 )
goto V_29;
F_23 ( & V_22 -> V_30 ) ;
V_22 -> V_26 = V_26 ;
V_22 -> V_2 = F_13 ( V_5 ) ;
if ( ! V_22 -> V_2 )
goto V_31;
#ifdef F_24
V_28 = F_25 ( L_2 , V_26 -> V_32 . V_33 -> V_28 ) ;
V_26 -> V_34 . V_35 = V_28 ;
F_26 ( L_3 , 0400 , V_28 , V_22 , & V_36 ) ;
#endif
V_22 -> V_37 = V_22 -> V_2 -> V_38 ( & V_26 -> V_32 , V_28 ) ;
if ( ! V_22 -> V_37 )
goto V_39;
return V_22 ;
V_39:
F_17 ( V_22 -> V_2 ) ;
V_31:
F_10 ( V_22 ) ;
V_29:
return NULL ;
}
static void F_27 ( struct V_30 * V_30 )
{
struct V_21 * V_40 ;
V_40 = F_28 ( V_30 , struct V_21 , V_30 ) ;
V_40 -> V_2 -> free ( V_40 -> V_37 ) ;
#ifdef F_24
F_29 ( V_40 -> V_26 -> V_34 . V_35 ) ;
V_40 -> V_26 -> V_34 . V_35 = NULL ;
#endif
F_17 ( V_40 -> V_2 ) ;
F_10 ( V_40 ) ;
}
static bool F_30 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_44 ;
struct V_45 * V_46 = (struct V_45 * ) V_44 -> V_47 ;
struct V_48 * V_49 = F_31 ( V_44 ) ;
T_5 V_50 ;
V_50 = V_46 -> V_51 ;
return ( V_49 -> V_52 & V_53 ) || ! F_32 ( V_50 ) ;
}
static void F_33 ( T_6 * V_54 , T_7 V_55 ,
struct V_56 * V_57 )
{
T_8 V_58 ;
if ( V_55 == 0 )
return;
if ( * V_54 < 0 )
return;
if ( V_55 & ( 1 << * V_54 ) )
return;
for ( V_58 = * V_54 + 1 ; V_58 <= V_57 -> V_59 ; V_58 ++ ) {
if ( V_55 & ( 1 << V_58 ) ) {
* V_54 = V_58 ;
return;
}
}
}
bool F_34 ( struct V_60 * V_61 ,
void * V_62 ,
struct V_41 * V_42 )
{
struct V_48 * V_49 = F_31 ( V_42 -> V_44 ) ;
struct V_56 * V_57 = V_42 -> V_57 ;
int V_63 ;
if ( ! V_61 || ! V_62 || F_30 ( V_42 ) ) {
V_49 -> V_64 . V_65 [ 0 ] . V_54 = F_35 ( V_42 -> V_57 , V_61 ) ;
V_49 -> V_64 . V_65 [ 0 ] . V_19 =
( V_49 -> V_52 & V_53 ) ?
1 : V_42 -> V_32 -> V_66 ;
if ( ! V_61 && V_42 -> V_67 ) {
V_63 = V_42 -> V_68 -> V_63 [ V_57 -> V_69 ] ;
if ( V_63 > 0 ) {
V_49 -> V_64 . V_65 [ 0 ] . V_54 = V_63 - 1 ;
return true ;
}
F_33 ( & V_49 -> V_64 . V_65 [ 0 ] . V_54 ,
V_42 -> V_68 -> V_55 ,
V_57 ) ;
}
return true ;
}
return false ;
}
static void F_36 ( struct V_70 * V_71 ,
int V_59 , T_7 V_72 )
{
int V_73 ;
for ( V_73 = V_71 -> V_54 ; V_73 >= 0 ; V_73 -- ) {
if ( V_72 & ( 1 << V_73 ) ) {
V_71 -> V_54 = V_73 ;
return;
}
}
for ( V_73 = V_71 -> V_54 + 1 ; V_73 < V_59 ; V_73 ++ ) {
if ( V_72 & ( 1 << V_73 ) ) {
V_71 -> V_54 = V_73 ;
return;
}
}
}
void F_37 ( struct V_74 * V_75 ,
struct V_76 * V_61 ,
struct V_41 * V_42 )
{
struct V_21 * V_22 = V_75 -> V_26 -> V_77 ;
void * V_62 = NULL ;
struct V_60 * V_78 = NULL ;
struct V_48 * V_49 = F_31 ( V_42 -> V_44 ) ;
int V_58 ;
T_7 V_72 ;
if ( V_61 ) {
V_78 = & V_61 -> V_61 ;
V_62 = V_61 -> V_79 ;
}
for ( V_58 = 0 ; V_58 < V_80 ; V_58 ++ ) {
V_49 -> V_64 . V_65 [ V_58 ] . V_54 = - 1 ;
V_49 -> V_64 . V_65 [ V_58 ] . V_52 = 0 ;
V_49 -> V_64 . V_65 [ V_58 ] . V_19 = 1 ;
}
if ( V_75 -> V_26 -> V_32 . V_52 & V_81 )
return;
V_22 -> V_2 -> V_82 ( V_22 -> V_37 , V_78 , V_62 , V_42 ) ;
V_72 = V_75 -> V_83 [ V_49 -> V_69 ] ;
if ( V_72 != ( 1 << V_42 -> V_57 -> V_59 ) - 1 ) {
if ( V_61 ) {
V_72 &= V_61 -> V_61 . V_84 [ V_49 -> V_69 ] ;
}
for ( V_58 = 0 ; V_58 < V_80 ; V_58 ++ ) {
if ( V_49 -> V_64 . V_65 [ V_58 ] . V_54 < 0 )
break;
if ( V_49 -> V_64 . V_65 [ V_58 ] . V_52 & V_85 )
continue;
F_36 ( & V_49 -> V_64 . V_65 [ V_58 ] ,
V_42 -> V_57 -> V_59 , V_72 ) ;
}
}
F_38 ( V_49 -> V_64 . V_65 [ 0 ] . V_54 < 0 ) ;
}
struct V_21 * F_39 ( struct V_21 * V_22 )
{
F_40 ( & V_22 -> V_30 ) ;
return V_22 ;
}
void F_41 ( struct V_21 * V_22 )
{
F_42 ( & V_22 -> V_30 , F_27 ) ;
}
int F_43 ( struct V_25 * V_26 ,
const char * V_5 )
{
struct V_21 * V_22 , * V_86 ;
F_44 () ;
if ( V_26 -> V_87 )
return - V_88 ;
if ( V_26 -> V_32 . V_52 & V_81 ) {
if ( F_4 ( ! V_26 -> V_2 -> V_89 ) )
return - V_6 ;
return 0 ;
}
V_22 = F_21 ( V_5 , V_26 ) ;
if ( ! V_22 ) {
F_45 ( V_26 -> V_32 . V_33 ,
L_4 ) ;
return - V_90 ;
}
V_86 = V_26 -> V_77 ;
V_26 -> V_77 = V_22 ;
if ( V_86 ) {
F_41 ( V_86 ) ;
F_46 ( V_26 , NULL ) ;
}
F_47 ( V_26 -> V_32 . V_33 , L_5 ,
V_22 -> V_2 -> V_5 ) ;
return 0 ;
}
void F_48 ( struct V_25 * V_26 )
{
struct V_21 * V_22 ;
V_22 = V_26 -> V_77 ;
if ( ! V_22 )
return;
V_26 -> V_77 = NULL ;
F_41 ( V_22 ) ;
}
