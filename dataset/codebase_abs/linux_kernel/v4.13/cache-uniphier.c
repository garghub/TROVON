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
struct V_1 * V_2 )
{
unsigned int V_31 ;
F_17 (cpu)
F_2 ( V_2 -> V_32 , V_2 -> V_33 + 4 * V_31 ) ;
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
F_18 ( V_6 , V_20 , V_34 ) ;
}
static void F_22 ( unsigned long V_6 , unsigned long V_20 )
{
F_18 ( V_6 , V_20 , V_35 ) ;
}
static void F_23 ( unsigned long V_6 , unsigned long V_20 )
{
F_18 ( V_6 , V_20 , V_36 ) ;
}
static void T_2 F_24 ( void )
{
F_20 ( V_34 ) ;
}
static void F_25 ( void )
{
F_20 ( V_36 ) ;
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
F_16 ( V_2 ) ;
}
}
static void F_29 ( void )
{
struct V_1 * V_2 ;
F_19 (data, &uniphier_cache_list, list)
F_1 ( V_2 ) ;
}
static int T_2 F_30 ( struct V_37 * V_38 ,
unsigned int * V_39 )
{
struct V_1 * V_2 ;
T_1 V_40 , V_41 ;
struct V_37 * V_42 ;
int V_43 = 0 ;
if ( ! F_31 ( V_44 , V_38 ) ) {
F_32 ( L_1 ,
* V_39 ) ;
return - V_45 ;
}
if ( F_33 ( V_38 , L_2 , & V_40 ) ) {
F_32 ( L_3 , * V_39 ) ;
return - V_45 ;
}
if ( V_40 != * V_39 ) {
F_32 ( L_4 ,
* V_39 , V_40 ) ;
return - V_45 ;
}
if ( ! F_34 ( V_38 , L_5 ) ) {
F_32 ( L_6 , * V_39 ) ;
return - V_45 ;
}
V_2 = F_35 ( sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
if ( F_33 ( V_38 , L_7 , & V_2 -> V_21 ) ||
! F_36 ( V_2 -> V_21 ) ) {
F_32 ( L_8 ,
* V_39 ) ;
V_43 = - V_45 ;
goto V_48;
}
if ( F_33 ( V_38 , L_9 , & V_2 -> V_49 ) ||
! F_36 ( V_2 -> V_49 ) ) {
F_32 ( L_10 ,
* V_39 ) ;
V_43 = - V_45 ;
goto V_48;
}
if ( F_33 ( V_38 , L_11 , & V_41 ) ||
V_41 == 0 || V_41 % ( V_2 -> V_49 * V_2 -> V_21 ) ) {
F_32 ( L_12 ,
* V_39 ) ;
V_43 = - V_45 ;
goto V_48;
}
V_2 -> V_32 = F_37 ( V_41 / V_2 -> V_49 / V_2 -> V_21 - 1 ,
0 ) ;
V_2 -> V_29 = F_38 ( V_38 , 0 ) ;
if ( ! V_2 -> V_29 ) {
F_32 ( L_13 , * V_39 ) ;
V_43 = - V_47 ;
goto V_48;
}
V_2 -> V_50 = F_38 ( V_38 , 1 ) ;
if ( ! V_2 -> V_50 ) {
F_32 ( L_14 , * V_39 ) ;
V_43 = - V_47 ;
goto V_48;
}
V_2 -> V_4 = F_38 ( V_38 , 2 ) ;
if ( ! V_2 -> V_4 ) {
F_32 ( L_15 , * V_39 ) ;
V_43 = - V_47 ;
goto V_48;
}
V_2 -> V_33 = V_2 -> V_29 + 0xc00 ;
if ( * V_39 == 2 ) {
T_1 V_51 = F_39 ( V_2 -> V_50 + V_52 ) ;
if ( V_51 <= 0x16 )
V_2 -> V_53 = ( T_1 ) 1 << 22 ;
switch ( V_51 ) {
case 0x11 :
V_2 -> V_33 = V_2 -> V_29 + 0x870 ;
break;
case 0x12 :
case 0x16 :
V_2 -> V_33 = V_2 -> V_29 + 0x840 ;
break;
default:
break;
}
}
V_2 -> V_53 -= V_2 -> V_21 ;
F_40 ( & V_2 -> V_54 ) ;
F_41 ( & V_2 -> V_54 , & V_55 ) ;
V_42 = F_42 ( V_38 ) ;
if ( V_42 ) {
( * V_39 ) ++ ;
V_43 = F_30 ( V_42 , V_39 ) ;
}
F_43 ( V_42 ) ;
return V_43 ;
V_48:
F_44 ( V_2 -> V_4 ) ;
F_44 ( V_2 -> V_50 ) ;
F_44 ( V_2 -> V_29 ) ;
F_45 ( V_2 ) ;
return V_43 ;
}
int T_2 F_46 ( void )
{
struct V_37 * V_38 = NULL ;
unsigned int V_39 ;
int V_43 = 0 ;
while ( ( V_38 = F_47 ( V_38 , V_44 ) ) )
if ( ! F_33 ( V_38 , L_2 , & V_39 ) &&
V_39 == 2 )
break;
if ( ! V_38 )
return - V_56 ;
V_43 = F_30 ( V_38 , & V_39 ) ;
F_43 ( V_38 ) ;
if ( V_43 ) {
if ( V_39 == 2 ) {
F_32 ( L_16 ) ;
return V_43 ;
}
V_39 -- ;
V_43 = 0 ;
}
V_57 . V_58 = F_21 ;
V_57 . V_59 = F_22 ;
V_57 . V_60 = F_23 ;
V_57 . V_61 = F_25 ;
V_57 . V_62 = F_26 ;
V_57 . V_63 = F_29 ;
F_28 () ;
F_48 ( L_17 , V_39 ) ;
return V_43 ;
}
