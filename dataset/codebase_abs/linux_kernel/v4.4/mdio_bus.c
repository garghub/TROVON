struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
T_1 V_4 = F_2 ( sizeof( * V_3 ) , V_5 ) ;
T_1 V_6 ;
if ( V_2 )
V_6 = V_4 + V_2 ;
else
V_6 = sizeof( * V_3 ) ;
V_3 = F_3 ( V_6 , V_7 ) ;
if ( V_3 ) {
V_3 -> V_8 = V_9 ;
if ( V_2 )
V_3 -> V_10 = ( void * ) V_3 + V_4 ;
}
return V_3 ;
}
static void F_4 ( struct V_11 * V_12 , void * V_13 )
{
F_5 ( * (struct V_1 * * ) V_13 ) ;
}
static int F_6 ( struct V_11 * V_12 , void * V_13 , void * V_14 )
{
struct V_1 * * V_15 = V_13 ;
if ( F_7 ( ! V_15 || ! * V_15 ) )
return 0 ;
return * V_15 == V_14 ;
}
struct V_1 * F_8 ( struct V_11 * V_12 , int V_16 )
{
struct V_1 * * V_17 , * V_3 ;
V_17 = F_9 ( F_4 , sizeof( * V_17 ) , V_7 ) ;
if ( ! V_17 )
return NULL ;
V_3 = F_1 ( V_16 ) ;
if ( V_3 ) {
* V_17 = V_3 ;
F_10 ( V_12 , V_17 ) ;
} else {
F_11 ( V_17 ) ;
}
return V_3 ;
}
void F_12 ( struct V_11 * V_12 , struct V_1 * V_3 )
{
int V_18 ;
V_18 = F_13 ( V_12 , F_4 ,
F_6 , V_3 ) ;
F_7 ( V_18 ) ;
}
static void F_14 ( struct V_11 * V_19 )
{
struct V_1 * V_3 = F_15 ( V_19 ) ;
F_16 ( V_3 -> V_8 != V_20 &&
V_3 -> V_8 != V_9 ) ;
F_17 ( V_3 ) ;
}
static int F_18 ( struct V_11 * V_12 , const void * V_21 )
{
return V_12 -> V_22 == V_21 ;
}
struct V_1 * F_19 ( struct V_23 * V_21 )
{
struct V_11 * V_19 ;
if ( ! V_21 )
return NULL ;
V_19 = F_20 ( & V_24 , NULL , V_21 ,
F_18 ) ;
return V_19 ? F_15 ( V_19 ) : NULL ;
}
static void F_21 ( struct V_1 * V_25 ,
struct V_26 * V_27 )
{
struct V_11 * V_12 = & V_27 -> V_12 ;
struct V_23 * V_28 ;
if ( V_12 -> V_22 || ! V_25 -> V_12 . V_22 )
return;
F_22 (mdio->dev.of_node, child) {
int V_29 ;
int V_30 ;
V_30 = F_23 ( V_28 , L_1 , & V_29 ) ;
if ( V_30 < 0 ) {
F_24 ( V_12 , L_2 ,
V_28 -> V_31 ) ;
continue;
}
if ( V_29 >= V_32 ) {
F_24 ( V_12 , L_3 ,
V_28 -> V_31 , V_29 ) ;
continue;
}
if ( V_29 == V_27 -> V_29 ) {
V_12 -> V_22 = V_28 ;
return;
}
}
}
static inline void F_21 ( struct V_1 * V_25 ,
struct V_26 * V_27 )
{
}
int F_25 ( struct V_1 * V_3 , struct V_33 * V_34 )
{
int V_35 , V_36 ;
if ( NULL == V_3 || NULL == V_3 -> V_37 ||
NULL == V_3 -> V_38 || NULL == V_3 -> V_39 )
return - V_40 ;
F_16 ( V_3 -> V_8 != V_9 &&
V_3 -> V_8 != V_41 ) ;
V_3 -> V_34 = V_34 ;
V_3 -> V_12 . V_42 = V_3 -> V_42 ;
V_3 -> V_12 . V_43 = & V_24 ;
V_3 -> V_12 . V_44 = NULL ;
F_26 ( & V_3 -> V_12 , L_4 , V_3 -> V_45 ) ;
V_36 = F_27 ( & V_3 -> V_12 ) ;
if ( V_36 ) {
F_28 ( L_5 , V_3 -> V_45 ) ;
F_29 ( & V_3 -> V_12 ) ;
return - V_40 ;
}
F_30 ( & V_3 -> V_46 ) ;
if ( V_3 -> V_47 )
V_3 -> V_47 ( V_3 ) ;
for ( V_35 = 0 ; V_35 < V_32 ; V_35 ++ ) {
if ( ( V_3 -> V_48 & ( 1 << V_35 ) ) == 0 ) {
struct V_26 * V_27 ;
V_27 = F_31 ( V_3 , V_35 ) ;
if ( F_32 ( V_27 ) ) {
V_36 = F_33 ( V_27 ) ;
goto error;
}
}
}
V_3 -> V_8 = V_49 ;
F_34 ( L_6 , V_3 -> V_37 ) ;
return 0 ;
error:
while ( -- V_35 >= 0 ) {
struct V_26 * V_27 = V_3 -> V_50 [ V_35 ] ;
if ( V_27 ) {
F_35 ( V_27 ) ;
F_36 ( V_27 ) ;
}
}
F_37 ( & V_3 -> V_12 ) ;
return V_36 ;
}
void F_38 ( struct V_1 * V_3 )
{
int V_35 ;
F_16 ( V_3 -> V_8 != V_49 ) ;
V_3 -> V_8 = V_41 ;
for ( V_35 = 0 ; V_35 < V_32 ; V_35 ++ ) {
struct V_26 * V_27 = V_3 -> V_50 [ V_35 ] ;
if ( V_27 ) {
F_35 ( V_27 ) ;
F_36 ( V_27 ) ;
}
}
F_37 ( & V_3 -> V_12 ) ;
}
void F_5 ( struct V_1 * V_3 )
{
if ( V_3 -> V_8 == V_9 ) {
F_17 ( V_3 ) ;
return;
}
F_16 ( V_3 -> V_8 != V_41 ) ;
V_3 -> V_8 = V_20 ;
F_29 ( & V_3 -> V_12 ) ;
}
struct V_26 * F_31 ( struct V_1 * V_3 , int V_29 )
{
struct V_26 * V_27 ;
int V_36 ;
V_27 = F_39 ( V_3 , V_29 , false ) ;
if ( F_32 ( V_27 ) || V_27 == NULL )
return V_27 ;
F_21 ( V_3 , V_27 ) ;
V_36 = F_40 ( V_27 ) ;
if ( V_36 ) {
F_36 ( V_27 ) ;
return NULL ;
}
return V_27 ;
}
int F_41 ( struct V_1 * V_3 , int V_29 , T_2 V_51 )
{
int V_52 ;
F_16 ( F_42 () ) ;
F_43 ( & V_3 -> V_46 , V_53 ) ;
V_52 = V_3 -> V_38 ( V_3 , V_29 , V_51 ) ;
F_44 ( & V_3 -> V_46 ) ;
return V_52 ;
}
int F_45 ( struct V_1 * V_3 , int V_29 , T_2 V_51 )
{
int V_52 ;
F_16 ( F_42 () ) ;
F_46 ( & V_3 -> V_46 ) ;
V_52 = V_3 -> V_38 ( V_3 , V_29 , V_51 ) ;
F_44 ( & V_3 -> V_46 ) ;
return V_52 ;
}
int F_47 ( struct V_1 * V_3 , int V_29 , T_2 V_51 , T_3 V_54 )
{
int V_36 ;
F_16 ( F_42 () ) ;
F_43 ( & V_3 -> V_46 , V_53 ) ;
V_36 = V_3 -> V_39 ( V_3 , V_29 , V_51 , V_54 ) ;
F_44 ( & V_3 -> V_46 ) ;
return V_36 ;
}
int F_48 ( struct V_1 * V_3 , int V_29 , T_2 V_51 , T_3 V_54 )
{
int V_36 ;
F_16 ( F_42 () ) ;
F_46 ( & V_3 -> V_46 ) ;
V_36 = V_3 -> V_39 ( V_3 , V_29 , V_51 , V_54 ) ;
F_44 ( & V_3 -> V_46 ) ;
return V_36 ;
}
static int F_49 ( struct V_11 * V_12 , struct V_55 * V_56 )
{
struct V_26 * V_27 = F_50 ( V_12 ) ;
struct V_57 * V_58 = F_51 ( V_56 ) ;
const int V_59 = F_52 ( V_27 -> V_60 . V_61 ) ;
int V_35 ;
if ( F_53 ( V_12 , V_56 ) )
return 1 ;
if ( V_58 -> V_62 )
return V_58 -> V_62 ( V_27 ) ;
if ( V_27 -> V_63 ) {
for ( V_35 = 1 ; V_35 < V_59 ; V_35 ++ ) {
if ( ! ( V_27 -> V_60 . V_64 & ( 1 << V_35 ) ) )
continue;
if ( ( V_58 -> V_65 & V_58 -> V_66 ) ==
( V_27 -> V_60 . V_61 [ V_35 ] &
V_58 -> V_66 ) )
return 1 ;
}
return 0 ;
} else {
return ( V_58 -> V_65 & V_58 -> V_66 ) ==
( V_27 -> V_65 & V_58 -> V_66 ) ;
}
}
static bool F_54 ( struct V_26 * V_27 )
{
struct V_55 * V_56 = V_27 -> V_12 . V_67 ;
struct V_57 * V_58 = F_51 ( V_56 ) ;
struct V_68 * V_69 = V_27 -> V_70 ;
if ( ! V_56 || ! V_58 -> V_71 )
return false ;
if ( ! V_69 )
return ! V_27 -> V_72 ;
if ( V_69 -> V_12 . V_42 && F_55 ( V_69 -> V_12 . V_42 ) )
return false ;
if ( F_55 ( & V_69 -> V_12 ) )
return false ;
return true ;
}
static int F_56 ( struct V_11 * V_12 )
{
struct V_26 * V_27 = F_50 ( V_12 ) ;
if ( V_27 -> V_70 && V_27 -> V_73 )
F_57 ( V_27 ) ;
if ( ! F_54 ( V_27 ) )
return 0 ;
return F_58 ( V_27 ) ;
}
static int F_59 ( struct V_11 * V_12 )
{
struct V_26 * V_27 = F_50 ( V_12 ) ;
int V_30 ;
if ( ! F_54 ( V_27 ) )
goto V_74;
V_30 = F_60 ( V_27 ) ;
if ( V_30 < 0 )
return V_30 ;
V_74:
if ( V_27 -> V_70 && V_27 -> V_73 )
F_61 ( V_27 ) ;
return 0 ;
}
static int F_62 ( struct V_11 * V_12 )
{
struct V_26 * V_27 = F_50 ( V_12 ) ;
struct V_68 * V_69 = V_27 -> V_70 ;
int V_30 ;
if ( ! V_69 )
return 0 ;
V_30 = F_63 ( V_27 ) ;
if ( V_30 < 0 )
return V_30 ;
V_27 -> V_75 = 0 ;
V_27 -> V_8 = V_76 ;
F_61 ( V_27 ) ;
return 0 ;
}
static T_4
F_64 ( struct V_11 * V_12 , struct V_77 * V_78 , char * V_79 )
{
struct V_26 * V_27 = F_50 ( V_12 ) ;
return sprintf ( V_79 , L_7 , ( unsigned long ) V_27 -> V_65 ) ;
}
static T_4
F_65 ( struct V_11 * V_12 , struct V_77 * V_78 , char * V_79 )
{
struct V_26 * V_27 = F_50 ( V_12 ) ;
const char * V_80 = NULL ;
if ( F_66 ( V_27 ) )
V_80 = L_8 ;
else
V_80 = F_67 ( V_27 -> V_81 ) ;
return sprintf ( V_79 , L_9 , V_80 ) ;
}
static T_4
F_68 ( struct V_11 * V_12 , struct V_77 * V_78 , char * V_79 )
{
struct V_26 * V_27 = F_50 ( V_12 ) ;
return sprintf ( V_79 , L_10 , V_27 -> V_82 ) ;
}
int T_5 F_69 ( void )
{
int V_30 ;
V_30 = F_70 ( & V_24 ) ;
if ( ! V_30 ) {
V_30 = F_71 ( & V_83 ) ;
if ( V_30 )
F_72 ( & V_24 ) ;
}
return V_30 ;
}
void F_73 ( void )
{
F_72 ( & V_24 ) ;
F_74 ( & V_83 ) ;
}
