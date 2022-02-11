static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 ( & V_7 ) ;
F_3 (ops, &opslist, list) {
F_4 ( V_4 , L_1 ,
V_6 -> V_8 ,
V_6 -> V_9 & V_10 ? L_2 : ( V_6 -> V_9 == V_11 ? L_3 : L_4 ) ,
V_6 -> V_9 & V_12 ? L_5 : L_4 ,
V_6 -> V_9 & V_13 ? L_6 : L_4 ,
V_6 -> V_14 ) ;
}
F_5 ( & V_7 ) ;
}
void F_6 ( void )
{
V_15 ++ ;
}
void F_7 ( void )
{
V_15 -- ;
}
void F_8 ( void )
{
#ifdef F_9
struct V_5 * V_6 ;
if ( V_15 )
return;
F_2 ( & V_7 ) ;
F_3 (ops, &opslist, list) {
if ( ! ( V_6 -> V_9 & V_10 ) &&
! ( V_6 -> V_9 & V_12 ) ) {
V_6 -> V_16 ++ ;
F_5 ( & V_7 ) ;
V_6 -> V_9 |= V_12 ;
F_10 ( L_7 , V_6 -> V_8 ) ;
F_2 ( & V_7 ) ;
V_6 -> V_16 -- ;
}
}
F_5 ( & V_7 ) ;
#endif
}
int F_11 ( struct V_17 * V_18 , int V_19 , char * V_8 , int V_20 ,
struct V_21 * * V_22 )
{
struct V_21 * V_23 ;
struct V_5 * V_6 ;
int V_24 ;
static struct V_25 V_26 = {
. V_27 = V_28 ,
. V_29 = V_30 ,
. V_31 = V_32 ,
} ;
if ( V_22 )
* V_22 = NULL ;
if ( F_12 ( ! V_8 ) )
return - V_33 ;
V_6 = F_13 ( V_8 , 1 ) ;
if ( V_6 == NULL )
return - V_34 ;
V_23 = F_14 ( sizeof( * V_23 ) * 2 + V_20 , V_35 ) ;
if ( V_23 == NULL ) {
F_15 ( V_6 ) ;
return - V_34 ;
}
V_23 -> V_18 = V_18 ;
V_23 -> V_19 = V_19 ;
F_16 ( V_23 -> V_8 , V_8 , sizeof( V_23 -> V_8 ) ) ;
V_23 -> V_20 = V_20 ;
V_23 -> V_36 = V_37 ;
F_2 ( & V_6 -> V_38 ) ;
F_17 ( & V_23 -> V_39 , & V_6 -> V_40 ) ;
V_6 -> V_14 ++ ;
F_5 ( & V_6 -> V_38 ) ;
F_15 ( V_6 ) ;
if ( ( V_24 = F_18 ( V_18 , V_41 , V_23 , & V_26 ) ) < 0 ) {
F_19 ( V_23 ) ;
return V_24 ;
}
if ( V_22 )
* V_22 = V_23 ;
return 0 ;
}
static int F_19 ( struct V_21 * V_23 )
{
struct V_5 * V_6 ;
if ( F_12 ( ! V_23 ) )
return - V_33 ;
V_6 = F_13 ( V_23 -> V_8 , 0 ) ;
if ( V_6 == NULL )
return - V_42 ;
F_2 ( & V_6 -> V_38 ) ;
F_20 ( & V_23 -> V_39 ) ;
V_6 -> V_14 -- ;
F_5 ( & V_6 -> V_38 ) ;
F_21 ( V_23 , V_6 ) ;
if ( V_23 -> V_43 )
V_23 -> V_43 ( V_23 ) ;
F_22 ( V_23 ) ;
F_15 ( V_6 ) ;
return 0 ;
}
static int V_28 ( struct V_44 * V_19 )
{
struct V_21 * V_23 = V_19 -> V_45 ;
return F_19 ( V_23 ) ;
}
static int V_30 ( struct V_44 * V_19 )
{
struct V_21 * V_23 = V_19 -> V_45 ;
struct V_5 * V_6 ;
V_6 = F_13 ( V_23 -> V_8 , 0 ) ;
if ( V_6 == NULL )
return - V_46 ;
if ( V_6 -> V_9 & V_10 )
F_23 ( V_23 , V_6 ) ;
F_15 ( V_6 ) ;
return 0 ;
}
static int V_32 ( struct V_44 * V_19 )
{
struct V_21 * V_23 = V_19 -> V_45 ;
struct V_5 * V_6 ;
V_6 = F_13 ( V_23 -> V_8 , 0 ) ;
if ( V_6 == NULL )
return - V_46 ;
F_21 ( V_23 , V_6 ) ;
F_15 ( V_6 ) ;
return 0 ;
}
int F_24 ( char * V_8 , struct V_47 * V_2 ,
int V_20 )
{
struct V_5 * V_6 ;
struct V_21 * V_23 ;
if ( V_8 == NULL || V_2 == NULL ||
V_2 -> F_23 == NULL || V_2 -> F_21 == NULL )
return - V_33 ;
F_6 () ;
V_6 = F_13 ( V_8 , 1 ) ;
if ( V_6 == NULL ) {
F_7 () ;
return - V_34 ;
}
if ( V_6 -> V_9 & V_10 ) {
F_25 ( L_8 , V_8 ) ;
F_15 ( V_6 ) ;
F_7 () ;
return - V_48 ;
}
F_2 ( & V_6 -> V_38 ) ;
V_6 -> V_6 = * V_2 ;
V_6 -> V_9 |= V_10 ;
V_6 -> V_20 = V_20 ;
F_3 (dev, &ops->dev_list, list) {
F_23 ( V_23 , V_6 ) ;
}
F_5 ( & V_6 -> V_38 ) ;
F_15 ( V_6 ) ;
F_7 () ;
return 0 ;
}
static struct V_5 * F_26 ( char * V_8 )
{
struct V_5 * V_6 ;
V_6 = F_14 ( sizeof( * V_6 ) , V_35 ) ;
if ( V_6 == NULL )
return V_6 ;
F_16 ( V_6 -> V_8 , V_8 , sizeof( V_6 -> V_8 ) ) ;
F_27 ( & V_6 -> V_38 ) ;
F_28 ( & V_6 -> V_38 , (struct V_49 * ) V_8 ) ;
V_6 -> V_9 = V_11 ;
F_29 ( & V_6 -> V_40 ) ;
V_6 -> V_16 = 1 ;
F_2 ( & V_7 ) ;
F_17 ( & V_6 -> V_39 , & V_50 ) ;
V_51 ++ ;
F_5 ( & V_7 ) ;
return V_6 ;
}
int F_30 ( char * V_8 )
{
struct V_5 * V_6 ;
struct V_21 * V_23 ;
V_6 = F_13 ( V_8 , 0 ) ;
if ( V_6 == NULL )
return - V_42 ;
if ( ! ( V_6 -> V_9 & V_10 ) ||
( V_6 -> V_9 & V_13 ) ) {
F_31 ( L_9 ,
V_8 , V_6 -> V_9 ) ;
F_15 ( V_6 ) ;
return - V_48 ;
}
F_2 ( & V_6 -> V_38 ) ;
V_6 -> V_9 |= V_13 ;
F_3 (dev, &ops->dev_list, list) {
F_21 ( V_23 , V_6 ) ;
}
V_6 -> V_9 = 0 ;
if ( V_6 -> V_52 > 0 )
F_31 ( L_10 ,
V_6 -> V_52 ) ;
F_5 ( & V_6 -> V_38 ) ;
F_15 ( V_6 ) ;
F_32 () ;
return 0 ;
}
static void F_32 ( void )
{
struct V_53 * V_54 ;
F_2 ( & V_7 ) ;
V_54 = V_50 . V_55 ;
while ( V_54 != & V_50 ) {
struct V_5 * V_6 = F_33 ( V_54 , struct V_5 , V_39 ) ;
if ( ! ( V_6 -> V_9 & V_10 ) &&
V_6 -> V_16 == 0 && V_6 -> V_14 == 0 ) {
V_54 = V_54 -> V_55 ;
F_20 ( & V_6 -> V_39 ) ;
F_22 ( V_6 ) ;
V_51 -- ;
} else
V_54 = V_54 -> V_55 ;
}
F_5 ( & V_7 ) ;
}
static int F_23 ( struct V_21 * V_23 , struct V_5 * V_6 )
{
if ( ! ( V_6 -> V_9 & V_10 ) )
return 0 ;
if ( V_23 -> V_36 != V_37 )
return 0 ;
if ( V_6 -> V_20 != V_23 -> V_20 ) {
F_31 ( L_11 ,
V_23 -> V_56 , V_6 -> V_8 , V_6 -> V_20 , V_23 -> V_20 ) ;
return - V_33 ;
}
if ( V_6 -> V_6 . F_23 ( V_23 ) >= 0 ) {
V_23 -> V_36 = V_57 ;
V_6 -> V_52 ++ ;
} else {
F_31 ( L_12 ,
V_23 -> V_56 , V_23 -> V_8 ) ;
}
return 0 ;
}
static int F_21 ( struct V_21 * V_23 , struct V_5 * V_6 )
{
int V_22 ;
if ( ! ( V_6 -> V_9 & V_10 ) )
return 0 ;
if ( V_23 -> V_36 != V_57 )
return 0 ;
if ( V_6 -> V_20 != V_23 -> V_20 ) {
F_31 ( L_11 ,
V_23 -> V_56 , V_6 -> V_8 , V_6 -> V_20 , V_23 -> V_20 ) ;
return - V_33 ;
}
if ( ( V_22 = V_6 -> V_6 . F_21 ( V_23 ) ) >= 0 || V_22 == - V_42 ) {
V_23 -> V_36 = V_37 ;
V_23 -> V_58 = NULL ;
V_6 -> V_52 -- ;
} else {
F_31 ( L_13 ,
V_23 -> V_56 , V_23 -> V_8 ) ;
}
return 0 ;
}
static struct V_5 * F_13 ( char * V_8 , int V_59 )
{
struct V_5 * V_6 ;
F_2 ( & V_7 ) ;
F_3 (ops, &opslist, list) {
if ( strcmp ( V_6 -> V_8 , V_8 ) == 0 ) {
V_6 -> V_16 ++ ;
F_5 ( & V_7 ) ;
return V_6 ;
}
}
F_5 ( & V_7 ) ;
if ( V_59 )
return F_26 ( V_8 ) ;
return NULL ;
}
static void F_15 ( struct V_5 * V_6 )
{
F_2 ( & V_7 ) ;
V_6 -> V_16 -- ;
F_5 ( & V_7 ) ;
}
static int T_1 F_34 ( void )
{
#ifdef F_35
V_60 = F_36 ( V_61 , L_14 ,
V_62 ) ;
if ( V_60 == NULL )
return - V_34 ;
V_60 -> V_63 = V_64 ;
V_60 -> V_65 . V_66 . V_67 = F_1 ;
if ( F_37 ( V_60 ) < 0 ) {
F_38 ( V_60 ) ;
return - V_34 ;
}
#endif
return 0 ;
}
static void T_2 F_39 ( void )
{
F_32 () ;
#ifdef F_35
F_38 ( V_60 ) ;
#endif
if ( V_51 )
F_31 ( L_15 , V_51 ) ;
}
