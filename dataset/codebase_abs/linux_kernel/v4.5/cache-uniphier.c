static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ,
V_2 -> V_4 + V_5 ) ;
F_3 ( V_2 -> V_4 + V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned long V_6 ,
unsigned long V_7 ,
T_1 V_8 )
{
unsigned long V_9 ;
F_5 ( V_9 ) ;
F_2 ( V_10 , V_2 -> V_4 + V_11 ) ;
do {
F_2 ( V_12 | V_8 ,
V_2 -> V_4 + V_13 ) ;
if ( F_6 ( F_7 ( V_8 ) ) ) {
F_2 ( V_6 , V_2 -> V_4 + V_14 ) ;
F_2 ( V_7 , V_2 -> V_4 + V_15 ) ;
}
if ( F_8 ( F_9 ( V_8 ) ) )
F_2 ( V_2 -> V_16 ,
V_2 -> V_4 + V_17 ) ;
} while ( F_8 ( F_3 ( V_2 -> V_4 + V_18 ) &
( V_19 | V_20 ) ) );
while ( F_6 ( F_3 ( V_2 -> V_4 + V_11 ) !=
V_10 ) )
F_10 () ;
F_11 ( V_9 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
T_1 V_8 )
{
F_4 ( V_2 , 0 , 0 ,
V_21 | V_8 ) ;
F_1 ( V_2 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
unsigned long V_6 , unsigned long V_22 ,
T_1 V_8 )
{
unsigned long V_7 ;
V_6 = V_6 & ~ ( V_2 -> V_23 - 1 ) ;
V_7 = V_22 - V_6 ;
if ( F_8 ( V_7 >= ( unsigned long ) ( - V_2 -> V_23 ) ) ) {
F_12 ( V_2 , V_8 ) ;
return;
}
V_7 = F_14 ( V_7 , V_2 -> V_23 ) ;
while ( V_7 ) {
unsigned long V_24 = F_15 (unsigned long, size,
data->range_op_max_size) ;
F_4 ( V_2 , V_6 , V_24 ,
V_25 | V_8 ) ;
V_6 += V_24 ;
V_7 -= V_24 ;
}
F_1 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 , bool V_26 )
{
T_1 V_27 = 0 ;
if ( V_26 )
V_27 = V_28 | V_29 | V_30 ;
F_2 ( V_27 , V_2 -> V_31 + V_32 ) ;
}
static void T_2 F_17 (
struct V_1 * V_2 ,
T_1 V_33 )
{
V_2 -> V_16 = V_33 & V_2 -> V_34 ;
F_2 ( ~ V_2 -> V_16 & V_2 -> V_34 ,
V_2 -> V_31 + V_35 ) ;
}
static void F_18 ( unsigned long V_6 , unsigned long V_22 ,
T_1 V_8 )
{
struct V_1 * V_2 ;
F_19 (data, &uniphier_cache_list, list)
F_13 ( V_2 , V_6 , V_22 , V_8 ) ;
}
static void F_20 ( T_1 V_8 )
{
struct V_1 * V_2 ;
F_19 (data, &uniphier_cache_list, list)
F_12 ( V_2 , V_8 ) ;
}
static void F_21 ( unsigned long V_6 , unsigned long V_22 )
{
F_18 ( V_6 , V_22 , V_36 ) ;
}
static void F_22 ( unsigned long V_6 , unsigned long V_22 )
{
F_18 ( V_6 , V_22 , V_37 ) ;
}
static void F_23 ( unsigned long V_6 , unsigned long V_22 )
{
F_18 ( V_6 , V_22 , V_38 ) ;
}
static void T_2 F_24 ( void )
{
F_20 ( V_36 ) ;
}
static void F_25 ( void )
{
F_20 ( V_38 ) ;
}
static void F_26 ( void )
{
struct V_1 * V_2 ;
F_27 (data, &uniphier_cache_list, list)
F_16 ( V_2 , false ) ;
F_25 () ;
}
static void T_2 F_28 ( void )
{
struct V_1 * V_2 ;
F_24 () ;
F_19 (data, &uniphier_cache_list, list) {
F_16 ( V_2 , true ) ;
F_17 ( V_2 , 0 ) ;
}
}
static void F_29 ( void )
{
struct V_1 * V_2 ;
F_19 (data, &uniphier_cache_list, list)
F_1 ( V_2 ) ;
}
int T_2 F_30 ( void )
{
struct V_1 * V_2 ;
V_2 = F_31 ( & V_39 ,
struct V_1 , V_40 ) ;
if ( ! V_2 )
return 0 ;
return ! ! ( F_3 ( V_2 -> V_31 + V_32 ) &
V_30 ) ;
}
void T_2 F_32 ( unsigned long V_6 ,
unsigned long V_22 )
{
struct V_1 * V_2 ;
V_2 = F_31 ( & V_39 ,
struct V_1 , V_40 ) ;
if ( V_2 )
F_13 ( V_2 , V_6 , V_22 ,
V_41 |
V_42 ) ;
}
void T_2 F_33 ( T_1 V_33 )
{
struct V_1 * V_2 ;
V_2 = F_31 ( & V_39 ,
struct V_1 , V_40 ) ;
if ( V_2 )
F_17 ( V_2 , V_33 ) ;
}
static int T_2 F_34 ( struct V_43 * V_44 ,
unsigned int * V_45 )
{
struct V_1 * V_2 ;
T_1 V_46 , V_47 ;
struct V_43 * V_48 ;
int V_49 = 0 ;
if ( ! F_35 ( V_50 , V_44 ) ) {
F_36 ( L_1 ,
* V_45 ) ;
return - V_51 ;
}
if ( F_37 ( V_44 , L_2 , & V_46 ) ) {
F_36 ( L_3 , * V_45 ) ;
return - V_51 ;
}
if ( V_46 != * V_45 ) {
F_36 ( L_4 ,
* V_45 , V_46 ) ;
return - V_51 ;
}
if ( ! F_38 ( V_44 , L_5 ) ) {
F_36 ( L_6 , * V_45 ) ;
return - V_51 ;
}
V_2 = F_39 ( sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
if ( F_37 ( V_44 , L_7 , & V_2 -> V_23 ) ||
! F_40 ( V_2 -> V_23 ) ) {
F_36 ( L_8 ,
* V_45 ) ;
V_49 = - V_51 ;
goto V_54;
}
if ( F_37 ( V_44 , L_9 , & V_2 -> V_55 ) ||
! F_40 ( V_2 -> V_55 ) ) {
F_36 ( L_10 ,
* V_45 ) ;
V_49 = - V_51 ;
goto V_54;
}
if ( F_37 ( V_44 , L_11 , & V_47 ) ||
V_47 == 0 || V_47 % ( V_2 -> V_55 * V_2 -> V_23 ) ) {
F_36 ( L_12 ,
* V_45 ) ;
V_49 = - V_51 ;
goto V_54;
}
V_2 -> V_34 =
( ( T_1 ) 1 << V_47 / V_2 -> V_55 / V_2 -> V_23 ) - 1 ;
V_2 -> V_31 = F_41 ( V_44 , 0 ) ;
if ( ! V_2 -> V_31 ) {
F_36 ( L_13 , * V_45 ) ;
V_49 = - V_53 ;
goto V_54;
}
V_2 -> V_56 = F_41 ( V_44 , 1 ) ;
if ( ! V_2 -> V_56 ) {
F_36 ( L_14 , * V_45 ) ;
V_49 = - V_53 ;
goto V_54;
}
V_2 -> V_4 = F_41 ( V_44 , 2 ) ;
if ( ! V_2 -> V_4 ) {
F_36 ( L_15 , * V_45 ) ;
V_49 = - V_53 ;
goto V_54;
}
if ( * V_45 == 2 ) {
T_1 V_57 = F_42 ( V_2 -> V_56 + V_58 ) ;
if ( V_57 <= 0x16 )
V_2 -> V_59 = ( T_1 ) 1 << 22 ;
}
V_2 -> V_59 -= V_2 -> V_23 ;
F_43 ( & V_2 -> V_40 ) ;
F_44 ( & V_2 -> V_40 , & V_39 ) ;
V_48 = F_45 ( V_44 ) ;
if ( V_48 ) {
( * V_45 ) ++ ;
V_49 = F_34 ( V_48 , V_45 ) ;
}
F_46 ( V_48 ) ;
return V_49 ;
V_54:
F_47 ( V_2 -> V_4 ) ;
F_47 ( V_2 -> V_56 ) ;
F_47 ( V_2 -> V_31 ) ;
F_48 ( V_2 ) ;
return V_49 ;
}
int T_2 F_49 ( void )
{
struct V_43 * V_44 = NULL ;
unsigned int V_45 ;
int V_49 = 0 ;
while ( ( V_44 = F_50 ( V_44 , V_50 ) ) )
if ( ! F_37 ( V_44 , L_2 , & V_45 ) &&
V_45 == 2 )
break;
if ( ! V_44 )
return - V_60 ;
V_49 = F_34 ( V_44 , & V_45 ) ;
F_46 ( V_44 ) ;
if ( V_49 ) {
if ( V_45 == 2 ) {
F_36 ( L_16 ) ;
return V_49 ;
}
V_45 -- ;
V_49 = 0 ;
}
V_61 . V_62 = F_21 ;
V_61 . V_63 = F_22 ;
V_61 . V_64 = F_23 ;
V_61 . V_65 = F_25 ;
V_61 . V_66 = F_26 ;
V_61 . V_67 = F_29 ;
F_28 () ;
F_51 ( L_17 , V_45 ) ;
return V_49 ;
}
