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
} while ( F_8 ( F_3 ( V_2 -> V_4 + V_16 ) &
( V_17 | V_18 ) ) );
while ( F_6 ( F_3 ( V_2 -> V_4 + V_11 ) !=
V_10 ) )
F_9 () ;
F_10 ( V_9 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
T_1 V_8 )
{
F_4 ( V_2 , 0 , 0 ,
V_19 | V_8 ) ;
F_1 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned long V_6 , unsigned long V_20 ,
T_1 V_8 )
{
unsigned long V_7 ;
V_6 = V_6 & ~ ( V_2 -> V_21 - 1 ) ;
V_7 = V_20 - V_6 ;
if ( F_8 ( V_7 >= ( unsigned long ) ( - V_2 -> V_21 ) ) ) {
F_11 ( V_2 , V_8 ) ;
return;
}
V_7 = F_13 ( V_7 , V_2 -> V_21 ) ;
while ( V_7 ) {
unsigned long V_22 = F_14 (unsigned long, size,
data->range_op_max_size) ;
F_4 ( V_2 , V_6 , V_22 ,
V_23 | V_8 ) ;
V_6 += V_22 ;
V_7 -= V_22 ;
}
F_1 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 , bool V_24 )
{
T_1 V_25 = 0 ;
if ( V_24 )
V_25 = V_26 | V_27 | V_28 ;
F_2 ( V_25 , V_2 -> V_29 + V_30 ) ;
}
static void T_2 F_16 (
struct V_1 * V_2 ,
T_1 V_31 )
{
unsigned int V_32 ;
V_2 -> V_33 = V_31 & V_2 -> V_34 ;
F_17 (cpu)
F_2 ( ~ V_2 -> V_33 & V_2 -> V_34 ,
V_2 -> V_35 + 4 * V_32 ) ;
}
static void F_18 ( unsigned long V_6 , unsigned long V_20 ,
T_1 V_8 )
{
struct V_1 * V_2 ;
F_19 (data, &uniphier_cache_list, list)
F_12 ( V_2 , V_6 , V_20 , V_8 ) ;
}
static void F_20 ( T_1 V_8 )
{
struct V_1 * V_2 ;
F_19 (data, &uniphier_cache_list, list)
F_11 ( V_2 , V_8 ) ;
}
static void F_21 ( unsigned long V_6 , unsigned long V_20 )
{
F_18 ( V_6 , V_20 , V_36 ) ;
}
static void F_22 ( unsigned long V_6 , unsigned long V_20 )
{
F_18 ( V_6 , V_20 , V_37 ) ;
}
static void F_23 ( unsigned long V_6 , unsigned long V_20 )
{
F_18 ( V_6 , V_20 , V_38 ) ;
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
F_15 ( V_2 , false ) ;
F_25 () ;
}
static void T_2 F_28 ( void )
{
struct V_1 * V_2 ;
F_24 () ;
F_19 (data, &uniphier_cache_list, list) {
F_15 ( V_2 , true ) ;
F_16 ( V_2 , 0 ) ;
}
}
static void F_29 ( void )
{
struct V_1 * V_2 ;
F_19 (data, &uniphier_cache_list, list)
F_1 ( V_2 ) ;
}
static int T_2 F_30 ( struct V_39 * V_40 ,
unsigned int * V_41 )
{
struct V_1 * V_2 ;
T_1 V_42 , V_43 ;
struct V_39 * V_44 ;
int V_45 = 0 ;
if ( ! F_31 ( V_46 , V_40 ) ) {
F_32 ( L_1 ,
* V_41 ) ;
return - V_47 ;
}
if ( F_33 ( V_40 , L_2 , & V_42 ) ) {
F_32 ( L_3 , * V_41 ) ;
return - V_47 ;
}
if ( V_42 != * V_41 ) {
F_32 ( L_4 ,
* V_41 , V_42 ) ;
return - V_47 ;
}
if ( ! F_34 ( V_40 , L_5 ) ) {
F_32 ( L_6 , * V_41 ) ;
return - V_47 ;
}
V_2 = F_35 ( sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 )
return - V_49 ;
if ( F_33 ( V_40 , L_7 , & V_2 -> V_21 ) ||
! F_36 ( V_2 -> V_21 ) ) {
F_32 ( L_8 ,
* V_41 ) ;
V_45 = - V_47 ;
goto V_50;
}
if ( F_33 ( V_40 , L_9 , & V_2 -> V_51 ) ||
! F_36 ( V_2 -> V_51 ) ) {
F_32 ( L_10 ,
* V_41 ) ;
V_45 = - V_47 ;
goto V_50;
}
if ( F_33 ( V_40 , L_11 , & V_43 ) ||
V_43 == 0 || V_43 % ( V_2 -> V_51 * V_2 -> V_21 ) ) {
F_32 ( L_12 ,
* V_41 ) ;
V_45 = - V_47 ;
goto V_50;
}
V_2 -> V_34 =
( ( T_1 ) 1 << V_43 / V_2 -> V_51 / V_2 -> V_21 ) - 1 ;
V_2 -> V_29 = F_37 ( V_40 , 0 ) ;
if ( ! V_2 -> V_29 ) {
F_32 ( L_13 , * V_41 ) ;
V_45 = - V_49 ;
goto V_50;
}
V_2 -> V_52 = F_37 ( V_40 , 1 ) ;
if ( ! V_2 -> V_52 ) {
F_32 ( L_14 , * V_41 ) ;
V_45 = - V_49 ;
goto V_50;
}
V_2 -> V_4 = F_37 ( V_40 , 2 ) ;
if ( ! V_2 -> V_4 ) {
F_32 ( L_15 , * V_41 ) ;
V_45 = - V_49 ;
goto V_50;
}
V_2 -> V_35 = V_2 -> V_29 + 0xc00 ;
if ( * V_41 == 2 ) {
T_1 V_53 = F_38 ( V_2 -> V_52 + V_54 ) ;
if ( V_53 <= 0x16 )
V_2 -> V_55 = ( T_1 ) 1 << 22 ;
switch ( V_53 ) {
case 0x11 :
V_2 -> V_35 = V_2 -> V_29 + 0x870 ;
break;
case 0x12 :
case 0x16 :
V_2 -> V_35 = V_2 -> V_29 + 0x840 ;
break;
default:
break;
}
}
V_2 -> V_55 -= V_2 -> V_21 ;
F_39 ( & V_2 -> V_56 ) ;
F_40 ( & V_2 -> V_56 , & V_57 ) ;
V_44 = F_41 ( V_40 ) ;
if ( V_44 ) {
( * V_41 ) ++ ;
V_45 = F_30 ( V_44 , V_41 ) ;
}
F_42 ( V_44 ) ;
return V_45 ;
V_50:
F_43 ( V_2 -> V_4 ) ;
F_43 ( V_2 -> V_52 ) ;
F_43 ( V_2 -> V_29 ) ;
F_44 ( V_2 ) ;
return V_45 ;
}
int T_2 F_45 ( void )
{
struct V_39 * V_40 = NULL ;
unsigned int V_41 ;
int V_45 = 0 ;
while ( ( V_40 = F_46 ( V_40 , V_46 ) ) )
if ( ! F_33 ( V_40 , L_2 , & V_41 ) &&
V_41 == 2 )
break;
if ( ! V_40 )
return - V_58 ;
V_45 = F_30 ( V_40 , & V_41 ) ;
F_42 ( V_40 ) ;
if ( V_45 ) {
if ( V_41 == 2 ) {
F_32 ( L_16 ) ;
return V_45 ;
}
V_41 -- ;
V_45 = 0 ;
}
V_59 . V_60 = F_21 ;
V_59 . V_61 = F_22 ;
V_59 . V_62 = F_23 ;
V_59 . V_63 = F_25 ;
V_59 . V_64 = F_26 ;
V_59 . V_65 = F_29 ;
F_28 () ;
F_47 ( L_17 , V_41 ) ;
return V_45 ;
}
