static struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
F_2 (dst, &dsa_switch_trees, list)
if ( V_3 -> V_2 == V_2 ) {
F_3 ( & V_3 -> V_4 ) ;
return V_3 ;
}
return NULL ;
}
static void F_4 ( struct V_5 * V_6 )
{
struct V_1 * V_3 = F_5 ( V_6 , struct V_1 ,
V_4 ) ;
F_6 ( & V_3 -> V_7 ) ;
F_7 ( V_3 ) ;
}
static void F_8 ( struct V_1 * V_3 )
{
F_9 ( & V_3 -> V_4 , F_4 ) ;
}
static struct V_1 * F_10 ( T_1 V_2 )
{
struct V_1 * V_3 ;
V_3 = F_11 ( sizeof( * V_3 ) , V_8 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_2 = V_2 ;
V_3 -> V_9 = - 1 ;
F_12 ( & V_3 -> V_7 ) ;
F_13 ( & V_10 , & V_3 -> V_7 ) ;
F_14 ( & V_3 -> V_4 ) ;
return V_3 ;
}
static void F_15 ( struct V_1 * V_3 ,
struct V_11 * V_12 , T_1 V_13 )
{
F_3 ( & V_3 -> V_4 ) ;
V_3 -> V_12 [ V_13 ] = V_12 ;
}
static void F_16 ( struct V_1 * V_3 ,
struct V_11 * V_12 , T_1 V_13 )
{
V_3 -> V_12 [ V_13 ] = NULL ;
F_9 ( & V_3 -> V_4 , F_4 ) ;
}
static bool F_17 ( struct V_14 * V_15 )
{
const char * V_16 ;
V_16 = F_18 ( V_15 , L_1 , NULL ) ;
if ( ! V_16 )
return false ;
if ( ! strcmp ( V_16 , L_2 ) )
return true ;
return false ;
}
static bool F_19 ( struct V_14 * V_15 )
{
const char * V_16 ;
V_16 = F_18 ( V_15 , L_1 , NULL ) ;
if ( ! V_16 )
return false ;
if ( ! strcmp ( V_16 , L_3 ) )
return true ;
return false ;
}
static bool F_20 ( struct V_11 * V_12 ,
struct V_14 * V_15 )
{
T_1 V_13 ;
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ )
if ( V_12 -> V_18 [ V_13 ] . V_19 == V_15 )
return true ;
return false ;
}
static struct V_11 * F_21 ( struct V_1 * V_3 ,
struct V_14 * V_15 )
{
struct V_11 * V_12 ;
T_1 V_13 ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ ) {
V_12 = V_3 -> V_12 [ V_13 ] ;
if ( ! V_12 )
continue;
if ( F_20 ( V_12 , V_15 ) )
return V_12 ;
}
return NULL ;
}
static int F_22 ( struct V_1 * V_3 ,
struct V_11 * V_21 ,
struct V_14 * V_15 ,
T_1 V_22 )
{
struct V_14 * V_23 ;
int V_13 ;
struct V_11 * V_24 ;
for ( V_13 = 0 ; ; V_13 ++ ) {
V_23 = F_23 ( V_15 , L_4 , V_13 ) ;
if ( ! V_23 )
break;
V_24 = F_21 ( V_3 , V_23 ) ;
F_24 ( V_23 ) ;
if ( ! V_24 )
return 1 ;
V_21 -> V_25 [ V_24 -> V_13 ] = V_22 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_3 , struct V_11 * V_12 )
{
struct V_14 * V_15 ;
T_1 V_13 ;
int V_26 ;
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ ) {
V_15 = V_12 -> V_18 [ V_13 ] . V_19 ;
if ( ! V_15 )
continue;
if ( ! F_17 ( V_15 ) )
continue;
V_26 = F_22 ( V_3 , V_12 , V_15 , V_13 ) ;
if ( V_26 != 0 )
return V_26 ;
V_12 -> V_27 |= F_26 ( V_13 ) ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_3 )
{
struct V_11 * V_12 ;
T_1 V_13 ;
int V_26 ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ ) {
V_12 = V_3 -> V_12 [ V_13 ] ;
if ( ! V_12 )
continue;
V_26 = F_25 ( V_3 , V_12 ) ;
if ( V_26 != 0 )
return V_26 ;
}
return 0 ;
}
static int F_28 ( struct V_14 * V_15 , T_1 V_13 ,
struct V_11 * V_12 )
{
int V_26 ;
V_26 = F_29 ( V_12 , V_12 -> V_28 , V_15 , V_13 ) ;
if ( V_26 ) {
F_30 ( V_12 -> V_28 , L_5 ,
V_13 , V_26 ) ;
return V_26 ;
}
return 0 ;
}
static void F_31 ( struct V_14 * V_15 , T_1 V_13 ,
struct V_11 * V_12 )
{
F_32 ( V_15 ) ;
}
static int F_33 ( struct V_14 * V_15 , T_1 V_13 ,
struct V_11 * V_12 )
{
int V_26 ;
V_26 = F_29 ( V_12 , V_12 -> V_28 , V_15 , V_13 ) ;
if ( V_26 ) {
F_30 ( V_12 -> V_28 , L_6 ,
V_13 , V_26 ) ;
return V_26 ;
}
V_12 -> V_29 |= F_26 ( V_13 ) ;
return 0 ;
}
static void F_34 ( struct V_14 * V_15 , T_1 V_13 ,
struct V_11 * V_12 )
{
F_32 ( V_15 ) ;
V_12 -> V_29 &= ~ F_26 ( V_13 ) ;
}
static int F_35 ( struct V_14 * V_15 , T_1 V_13 ,
struct V_11 * V_12 )
{
const char * V_16 ;
int V_26 ;
V_16 = F_18 ( V_15 , L_1 , NULL ) ;
V_26 = F_36 ( V_12 , V_12 -> V_28 , V_13 , V_16 ) ;
if ( V_26 ) {
F_30 ( V_12 -> V_28 , L_7 ,
V_13 , V_26 ) ;
V_12 -> V_18 [ V_13 ] . V_30 = NULL ;
return V_26 ;
}
return 0 ;
}
static void F_37 ( struct V_14 * V_15 , T_1 V_13 ,
struct V_11 * V_12 )
{
if ( V_12 -> V_18 [ V_13 ] . V_30 ) {
F_38 ( V_12 -> V_18 [ V_13 ] . V_30 ) ;
V_12 -> V_18 [ V_13 ] . V_30 = NULL ;
V_12 -> V_31 &= ~ ( 1 << V_13 ) ;
}
}
static int F_39 ( struct V_1 * V_3 , struct V_11 * V_12 )
{
struct V_14 * V_15 ;
T_1 V_13 ;
int V_26 ;
V_12 -> V_32 = V_12 -> V_31 ;
V_26 = V_12 -> V_33 -> V_34 ( V_12 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_12 -> V_33 -> V_35 ) {
V_26 = V_12 -> V_33 -> V_35 ( V_12 , V_3 -> V_36 -> V_37 ) ;
if ( V_26 < 0 )
return V_26 ;
}
if ( ! V_12 -> V_38 && V_12 -> V_33 -> V_39 ) {
V_12 -> V_38 = F_40 ( V_12 -> V_28 ) ;
if ( ! V_12 -> V_38 )
return - V_40 ;
F_41 ( V_12 ) ;
V_26 = F_42 ( V_12 -> V_38 ) ;
if ( V_26 < 0 )
return V_26 ;
}
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ ) {
V_15 = V_12 -> V_18 [ V_13 ] . V_19 ;
if ( ! V_15 )
continue;
if ( F_17 ( V_15 ) ) {
V_26 = F_28 ( V_15 , V_13 , V_12 ) ;
if ( V_26 )
return V_26 ;
continue;
}
if ( F_19 ( V_15 ) ) {
V_26 = F_33 ( V_15 , V_13 , V_12 ) ;
if ( V_26 )
return V_26 ;
continue;
}
V_26 = F_35 ( V_15 , V_13 , V_12 ) ;
if ( V_26 )
continue;
}
return 0 ;
}
static void F_43 ( struct V_1 * V_3 , struct V_11 * V_12 )
{
struct V_14 * V_15 ;
T_1 V_13 ;
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ ) {
V_15 = V_12 -> V_18 [ V_13 ] . V_19 ;
if ( ! V_15 )
continue;
if ( F_17 ( V_15 ) ) {
F_31 ( V_15 , V_13 , V_12 ) ;
continue;
}
if ( F_19 ( V_15 ) ) {
F_34 ( V_15 , V_13 , V_12 ) ;
continue;
}
F_37 ( V_15 , V_13 , V_12 ) ;
}
if ( V_12 -> V_38 && V_12 -> V_33 -> V_39 )
F_44 ( V_12 -> V_38 ) ;
}
static int F_45 ( struct V_1 * V_3 )
{
struct V_11 * V_12 ;
T_1 V_13 ;
int V_26 ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ ) {
V_12 = V_3 -> V_12 [ V_13 ] ;
if ( ! V_12 )
continue;
V_26 = F_39 ( V_3 , V_12 ) ;
if ( V_26 )
return V_26 ;
}
if ( V_3 -> V_12 [ 0 ] ) {
V_26 = F_46 ( V_3 -> V_12 [ 0 ] ) ;
if ( V_26 )
return V_26 ;
}
F_47 () ;
V_3 -> V_36 -> V_41 = ( void * ) V_3 ;
V_3 -> V_42 = true ;
return 0 ;
}
static void F_48 ( struct V_1 * V_3 )
{
struct V_11 * V_12 ;
T_1 V_13 ;
if ( ! V_3 -> V_42 )
return;
V_3 -> V_36 -> V_41 = NULL ;
F_47 () ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ ) {
V_12 = V_3 -> V_12 [ V_13 ] ;
if ( ! V_12 )
continue;
F_43 ( V_3 , V_12 ) ;
}
if ( V_3 -> V_12 [ 0 ] )
F_49 ( V_3 -> V_12 [ 0 ] ) ;
F_50 ( L_8 , V_3 -> V_2 ) ;
V_3 -> V_42 = false ;
}
static int F_51 ( struct V_14 * V_15 , T_1 V_13 ,
struct V_1 * V_3 ,
struct V_11 * V_12 )
{
enum V_43 V_44 ;
struct V_45 * V_46 ;
struct V_14 * V_47 ;
V_47 = F_23 ( V_15 , L_9 , 0 ) ;
if ( ! V_47 )
return - V_48 ;
V_46 = F_52 ( V_47 ) ;
if ( ! V_46 )
return - V_49 ;
if ( ! V_12 -> V_36 )
V_12 -> V_36 = V_46 ;
if ( ! V_3 -> V_36 )
V_3 -> V_36 = V_46 ;
if ( V_3 -> V_9 == - 1 ) {
V_3 -> V_9 = V_12 -> V_13 ;
V_3 -> V_50 = V_13 ;
}
V_44 = V_12 -> V_33 -> V_51 ( V_12 ) ;
V_3 -> V_52 = F_53 ( V_44 ) ;
if ( F_54 ( V_3 -> V_52 ) ) {
F_30 ( V_12 -> V_28 , L_10 ) ;
return F_55 ( V_3 -> V_52 ) ;
}
V_3 -> V_53 = V_3 -> V_52 -> V_53 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_3 , struct V_11 * V_12 )
{
struct V_14 * V_15 ;
T_1 V_13 ;
int V_26 ;
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ ) {
V_15 = V_12 -> V_18 [ V_13 ] . V_19 ;
if ( ! V_15 )
continue;
if ( F_19 ( V_15 ) ) {
V_26 = F_51 ( V_15 , V_13 , V_3 , V_12 ) ;
if ( V_26 )
return V_26 ;
}
}
F_50 ( L_11 , V_3 -> V_2 , V_12 -> V_13 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_3 )
{
struct V_11 * V_12 ;
T_1 V_13 ;
int V_26 ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ ) {
V_12 = V_3 -> V_12 [ V_13 ] ;
if ( ! V_12 )
continue;
V_26 = F_56 ( V_3 , V_12 ) ;
if ( V_26 )
return V_26 ;
}
if ( ! V_3 -> V_36 ) {
F_58 ( L_12 ) ;
return - V_48 ;
}
F_50 ( L_13 , V_3 -> V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_14 * V_18 , struct V_11 * V_12 )
{
struct V_14 * V_15 ;
int V_26 ;
T_1 V_54 ;
F_60 (ports, port) {
V_26 = F_61 ( V_15 , L_14 , & V_54 ) ;
if ( V_26 )
return V_26 ;
if ( V_54 >= V_17 )
return - V_48 ;
V_12 -> V_18 [ V_54 ] . V_19 = V_15 ;
if ( ! F_19 ( V_15 ) )
V_12 -> V_31 |= 1 << V_54 ;
}
return 0 ;
}
static int F_62 ( struct V_14 * V_55 , T_1 * V_2 , T_1 * V_13 )
{
int V_26 ;
* V_2 = * V_13 = 0 ;
V_26 = F_63 ( V_55 , L_15 , 0 , V_2 ) ;
if ( V_26 ) {
if ( V_26 == - V_48 )
return 0 ;
return V_26 ;
}
V_26 = F_63 ( V_55 , L_15 , 1 , V_13 ) ;
if ( V_26 )
return V_26 ;
if ( * V_13 >= V_20 )
return - V_48 ;
return 0 ;
}
static struct V_14 * F_64 ( struct V_11 * V_12 ,
struct V_14 * V_55 )
{
struct V_14 * V_18 ;
V_18 = F_65 ( V_55 , L_16 ) ;
if ( ! V_18 ) {
F_66 ( V_12 -> V_28 , L_17 ) ;
return F_67 ( - V_48 ) ;
}
return V_18 ;
}
static int F_68 ( struct V_11 * V_12 , struct V_14 * V_55 )
{
struct V_14 * V_18 = F_64 ( V_12 , V_55 ) ;
struct V_1 * V_3 ;
T_1 V_2 , V_13 ;
int V_56 , V_26 ;
V_26 = F_62 ( V_55 , & V_2 , & V_13 ) ;
if ( V_26 )
return V_26 ;
if ( F_54 ( V_18 ) )
return F_55 ( V_18 ) ;
V_26 = F_59 ( V_18 , V_12 ) ;
if ( V_26 )
return V_26 ;
V_3 = F_1 ( V_2 ) ;
if ( ! V_3 ) {
V_3 = F_10 ( V_2 ) ;
if ( ! V_3 )
return - V_40 ;
}
if ( V_3 -> V_12 [ V_13 ] ) {
V_26 = - V_57 ;
goto V_58;
}
V_12 -> V_3 = V_3 ;
V_12 -> V_13 = V_13 ;
for ( V_56 = 0 ; V_56 < V_20 ; ++ V_56 )
V_12 -> V_25 [ V_56 ] = V_59 ;
F_15 ( V_3 , V_12 , V_13 ) ;
V_26 = F_27 ( V_3 ) ;
if ( V_26 < 0 )
goto V_60;
if ( V_26 == 1 ) {
V_26 = 0 ;
goto V_58;
}
if ( V_3 -> V_42 ) {
F_50 ( L_18 ) ;
return - V_48 ;
}
V_26 = F_57 ( V_3 ) ;
if ( V_26 )
goto V_60;
V_26 = F_45 ( V_3 ) ;
if ( V_26 ) {
F_48 ( V_3 ) ;
goto V_60;
}
F_8 ( V_3 ) ;
return 0 ;
V_60:
F_16 ( V_3 , V_12 , V_12 -> V_13 ) ;
V_58:
F_8 ( V_3 ) ;
return V_26 ;
}
int F_69 ( struct V_11 * V_12 , struct V_14 * V_55 )
{
int V_26 ;
F_70 ( & V_61 ) ;
V_26 = F_68 ( V_12 , V_55 ) ;
F_71 ( & V_61 ) ;
return V_26 ;
}
static void F_72 ( struct V_11 * V_12 )
{
struct V_1 * V_3 = V_12 -> V_3 ;
F_48 ( V_3 ) ;
F_16 ( V_3 , V_12 , V_12 -> V_13 ) ;
}
void F_73 ( struct V_11 * V_12 )
{
F_70 ( & V_61 ) ;
F_72 ( V_12 ) ;
F_71 ( & V_61 ) ;
}
