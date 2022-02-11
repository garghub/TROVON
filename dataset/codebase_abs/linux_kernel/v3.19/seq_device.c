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
F_7 ( & V_15 ) ;
}
void F_8 ( void )
{
F_9 ( & V_15 ) ;
}
static void F_10 ( void )
{
if ( F_11 ( & V_15 ) == 1 ) {
struct V_5 * V_6 ;
F_2 ( & V_7 ) ;
F_3 (ops, &opslist, list) {
if ( ( V_6 -> V_9 & V_16 ) &&
! ( V_6 -> V_9 & V_12 ) ) {
V_6 -> V_17 ++ ;
F_5 ( & V_7 ) ;
V_6 -> V_9 |= V_12 ;
F_12 ( L_7 , V_6 -> V_8 ) ;
F_2 ( & V_7 ) ;
V_6 -> V_17 -- ;
}
}
F_5 ( & V_7 ) ;
}
F_9 ( & V_15 ) ;
}
static void F_13 ( struct V_18 * V_19 )
{
F_10 () ;
}
static void F_14 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_9 ) {
V_6 -> V_9 |= V_16 ;
F_15 ( & V_20 ) ;
}
}
static void F_16 ( void )
{
struct V_5 * V_6 ;
F_2 ( & V_7 ) ;
F_3 (ops, &opslist, list)
F_14 ( V_6 ) ;
F_5 ( & V_7 ) ;
}
void F_17 ( void )
{
F_9 ( & V_15 ) ;
#ifdef F_18
F_16 () ;
#endif
}
void F_19 ( void )
{
#ifdef F_20
F_16 () ;
F_21 ( & V_20 ) ;
#endif
}
int F_22 ( struct V_21 * V_22 , int V_23 , char * V_8 , int V_24 ,
struct V_25 * * V_26 )
{
struct V_25 * V_27 ;
struct V_5 * V_6 ;
int V_28 ;
static struct V_29 V_30 = {
. V_31 = V_32 ,
. V_33 = V_34 ,
. V_35 = V_36 ,
} ;
if ( V_26 )
* V_26 = NULL ;
if ( F_23 ( ! V_8 ) )
return - V_37 ;
V_6 = F_24 ( V_8 , 1 ) ;
if ( V_6 == NULL )
return - V_38 ;
V_27 = F_25 ( sizeof( * V_27 ) * 2 + V_24 , V_39 ) ;
if ( V_27 == NULL ) {
F_26 ( V_6 ) ;
return - V_38 ;
}
V_27 -> V_22 = V_22 ;
V_27 -> V_23 = V_23 ;
F_27 ( V_27 -> V_8 , V_8 , sizeof( V_27 -> V_8 ) ) ;
V_27 -> V_24 = V_24 ;
V_27 -> V_40 = V_41 ;
F_2 ( & V_6 -> V_42 ) ;
F_28 ( & V_27 -> V_43 , & V_6 -> V_44 ) ;
V_6 -> V_14 ++ ;
F_5 ( & V_6 -> V_42 ) ;
if ( ( V_28 = F_29 ( V_22 , V_45 , V_27 , & V_30 ) ) < 0 ) {
F_30 ( V_27 ) ;
return V_28 ;
}
F_14 ( V_6 ) ;
F_26 ( V_6 ) ;
if ( V_26 )
* V_26 = V_27 ;
return 0 ;
}
static int F_30 ( struct V_25 * V_27 )
{
struct V_5 * V_6 ;
if ( F_23 ( ! V_27 ) )
return - V_37 ;
V_6 = F_24 ( V_27 -> V_8 , 0 ) ;
if ( V_6 == NULL )
return - V_46 ;
F_2 ( & V_6 -> V_42 ) ;
F_31 ( & V_27 -> V_43 ) ;
V_6 -> V_14 -- ;
F_5 ( & V_6 -> V_42 ) ;
F_32 ( V_27 , V_6 ) ;
if ( V_27 -> V_47 )
V_27 -> V_47 ( V_27 ) ;
F_33 ( V_27 ) ;
F_26 ( V_6 ) ;
return 0 ;
}
static int V_32 ( struct V_48 * V_23 )
{
struct V_25 * V_27 = V_23 -> V_49 ;
return F_30 ( V_27 ) ;
}
static int V_34 ( struct V_48 * V_23 )
{
struct V_25 * V_27 = V_23 -> V_49 ;
struct V_5 * V_6 ;
V_6 = F_24 ( V_27 -> V_8 , 0 ) ;
if ( V_6 == NULL )
return - V_50 ;
if ( V_6 -> V_9 & V_10 )
F_34 ( V_27 , V_6 ) ;
F_26 ( V_6 ) ;
return 0 ;
}
static int V_36 ( struct V_48 * V_23 )
{
struct V_25 * V_27 = V_23 -> V_49 ;
struct V_5 * V_6 ;
V_6 = F_24 ( V_27 -> V_8 , 0 ) ;
if ( V_6 == NULL )
return - V_50 ;
F_32 ( V_27 , V_6 ) ;
F_26 ( V_6 ) ;
return 0 ;
}
int F_35 ( char * V_8 , struct V_51 * V_2 ,
int V_24 )
{
struct V_5 * V_6 ;
struct V_25 * V_27 ;
if ( V_8 == NULL || V_2 == NULL ||
V_2 -> F_34 == NULL || V_2 -> F_32 == NULL )
return - V_37 ;
V_6 = F_24 ( V_8 , 1 ) ;
if ( V_6 == NULL )
return - V_38 ;
if ( V_6 -> V_9 & V_10 ) {
F_36 ( L_8 , V_8 ) ;
F_26 ( V_6 ) ;
return - V_52 ;
}
F_2 ( & V_6 -> V_42 ) ;
V_6 -> V_6 = * V_2 ;
V_6 -> V_9 |= V_10 ;
V_6 -> V_24 = V_24 ;
F_3 (dev, &ops->dev_list, list) {
F_34 ( V_27 , V_6 ) ;
}
F_5 ( & V_6 -> V_42 ) ;
F_26 ( V_6 ) ;
return 0 ;
}
static struct V_5 * F_37 ( char * V_8 )
{
struct V_5 * V_6 ;
V_6 = F_25 ( sizeof( * V_6 ) , V_39 ) ;
if ( V_6 == NULL )
return V_6 ;
F_27 ( V_6 -> V_8 , V_8 , sizeof( V_6 -> V_8 ) ) ;
F_38 ( & V_6 -> V_42 ) ;
F_39 ( & V_6 -> V_42 , (struct V_53 * ) V_8 ) ;
V_6 -> V_9 = V_11 ;
F_40 ( & V_6 -> V_44 ) ;
V_6 -> V_17 = 1 ;
F_2 ( & V_7 ) ;
F_28 ( & V_6 -> V_43 , & V_54 ) ;
V_55 ++ ;
F_5 ( & V_7 ) ;
return V_6 ;
}
int F_41 ( char * V_8 )
{
struct V_5 * V_6 ;
struct V_25 * V_27 ;
V_6 = F_24 ( V_8 , 0 ) ;
if ( V_6 == NULL )
return - V_46 ;
if ( ! ( V_6 -> V_9 & V_10 ) ||
( V_6 -> V_9 & V_13 ) ) {
F_42 ( L_9 ,
V_8 , V_6 -> V_9 ) ;
F_26 ( V_6 ) ;
return - V_52 ;
}
F_2 ( & V_6 -> V_42 ) ;
V_6 -> V_9 |= V_13 ;
F_3 (dev, &ops->dev_list, list) {
F_32 ( V_27 , V_6 ) ;
}
V_6 -> V_9 = 0 ;
if ( V_6 -> V_56 > 0 )
F_42 ( L_10 ,
V_6 -> V_56 ) ;
F_5 ( & V_6 -> V_42 ) ;
F_26 ( V_6 ) ;
F_43 () ;
return 0 ;
}
static void F_43 ( void )
{
struct V_57 * V_58 ;
F_2 ( & V_7 ) ;
V_58 = V_54 . V_59 ;
while ( V_58 != & V_54 ) {
struct V_5 * V_6 = F_44 ( V_58 , struct V_5 , V_43 ) ;
if ( ! ( V_6 -> V_9 & V_10 ) &&
V_6 -> V_17 == 0 && V_6 -> V_14 == 0 ) {
V_58 = V_58 -> V_59 ;
F_31 ( & V_6 -> V_43 ) ;
F_33 ( V_6 ) ;
V_55 -- ;
} else
V_58 = V_58 -> V_59 ;
}
F_5 ( & V_7 ) ;
}
static int F_34 ( struct V_25 * V_27 , struct V_5 * V_6 )
{
if ( ! ( V_6 -> V_9 & V_10 ) )
return 0 ;
if ( V_27 -> V_40 != V_41 )
return 0 ;
if ( V_6 -> V_24 != V_27 -> V_24 ) {
F_42 ( L_11 ,
V_27 -> V_60 , V_6 -> V_8 , V_6 -> V_24 , V_27 -> V_24 ) ;
return - V_37 ;
}
if ( V_6 -> V_6 . F_34 ( V_27 ) >= 0 ) {
V_27 -> V_40 = V_61 ;
V_6 -> V_56 ++ ;
} else {
F_42 ( L_12 ,
V_27 -> V_60 , V_27 -> V_8 ) ;
}
return 0 ;
}
static int F_32 ( struct V_25 * V_27 , struct V_5 * V_6 )
{
int V_26 ;
if ( ! ( V_6 -> V_9 & V_10 ) )
return 0 ;
if ( V_27 -> V_40 != V_61 )
return 0 ;
if ( V_6 -> V_24 != V_27 -> V_24 ) {
F_42 ( L_11 ,
V_27 -> V_60 , V_6 -> V_8 , V_6 -> V_24 , V_27 -> V_24 ) ;
return - V_37 ;
}
if ( ( V_26 = V_6 -> V_6 . F_32 ( V_27 ) ) >= 0 || V_26 == - V_46 ) {
V_27 -> V_40 = V_41 ;
V_27 -> V_62 = NULL ;
V_6 -> V_56 -- ;
} else {
F_42 ( L_13 ,
V_27 -> V_60 , V_27 -> V_8 ) ;
}
return 0 ;
}
static struct V_5 * F_24 ( char * V_8 , int V_63 )
{
struct V_5 * V_6 ;
F_2 ( & V_7 ) ;
F_3 (ops, &opslist, list) {
if ( strcmp ( V_6 -> V_8 , V_8 ) == 0 ) {
V_6 -> V_17 ++ ;
F_5 ( & V_7 ) ;
return V_6 ;
}
}
F_5 ( & V_7 ) ;
if ( V_63 )
return F_37 ( V_8 ) ;
return NULL ;
}
static void F_26 ( struct V_5 * V_6 )
{
F_2 ( & V_7 ) ;
V_6 -> V_17 -- ;
F_5 ( & V_7 ) ;
}
static int T_1 F_45 ( void )
{
#ifdef F_46
V_64 = F_47 ( V_65 , L_14 ,
V_66 ) ;
if ( V_64 == NULL )
return - V_38 ;
V_64 -> V_67 = V_68 ;
V_64 -> V_69 . V_70 . V_71 = F_1 ;
if ( F_48 ( V_64 ) < 0 ) {
F_49 ( V_64 ) ;
return - V_38 ;
}
#endif
return 0 ;
}
static void T_2 F_50 ( void )
{
#ifdef F_20
F_51 ( & V_20 ) ;
#endif
F_43 () ;
#ifdef F_46
F_49 ( V_64 ) ;
#endif
if ( V_55 )
F_42 ( L_15 , V_55 ) ;
}
