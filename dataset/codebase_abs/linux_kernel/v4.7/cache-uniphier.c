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
unsigned int V_34 ;
V_2 -> V_16 = V_33 & V_2 -> V_35 ;
F_18 (cpu)
F_2 ( ~ V_2 -> V_16 & V_2 -> V_35 ,
V_2 -> V_36 + 4 * V_34 ) ;
}
static void F_19 ( unsigned long V_6 , unsigned long V_22 ,
T_1 V_8 )
{
struct V_1 * V_2 ;
F_20 (data, &uniphier_cache_list, list)
F_13 ( V_2 , V_6 , V_22 , V_8 ) ;
}
static void F_21 ( T_1 V_8 )
{
struct V_1 * V_2 ;
F_20 (data, &uniphier_cache_list, list)
F_12 ( V_2 , V_8 ) ;
}
static void F_22 ( unsigned long V_6 , unsigned long V_22 )
{
F_19 ( V_6 , V_22 , V_37 ) ;
}
static void F_23 ( unsigned long V_6 , unsigned long V_22 )
{
F_19 ( V_6 , V_22 , V_38 ) ;
}
static void F_24 ( unsigned long V_6 , unsigned long V_22 )
{
F_19 ( V_6 , V_22 , V_39 ) ;
}
static void T_2 F_25 ( void )
{
F_21 ( V_37 ) ;
}
static void F_26 ( void )
{
F_21 ( V_39 ) ;
}
static void F_27 ( void )
{
struct V_1 * V_2 ;
F_28 (data, &uniphier_cache_list, list)
F_16 ( V_2 , false ) ;
F_26 () ;
}
static void T_2 F_29 ( void )
{
struct V_1 * V_2 ;
F_25 () ;
F_20 (data, &uniphier_cache_list, list) {
F_16 ( V_2 , true ) ;
F_17 ( V_2 , 0 ) ;
}
}
static void F_30 ( void )
{
struct V_1 * V_2 ;
F_20 (data, &uniphier_cache_list, list)
F_1 ( V_2 ) ;
}
int T_2 F_31 ( void )
{
struct V_1 * V_2 ;
V_2 = F_32 ( & V_40 ,
struct V_1 , V_41 ) ;
if ( ! V_2 )
return 0 ;
return ! ! ( F_3 ( V_2 -> V_31 + V_32 ) &
V_30 ) ;
}
void T_2 F_33 ( unsigned long V_6 ,
unsigned long V_22 )
{
struct V_1 * V_2 ;
V_2 = F_32 ( & V_40 ,
struct V_1 , V_41 ) ;
if ( V_2 )
F_13 ( V_2 , V_6 , V_22 ,
V_42 |
V_43 ) ;
}
void T_2 F_34 ( T_1 V_33 )
{
struct V_1 * V_2 ;
V_2 = F_32 ( & V_40 ,
struct V_1 , V_41 ) ;
if ( V_2 )
F_17 ( V_2 , V_33 ) ;
}
static int T_2 F_35 ( struct V_44 * V_45 ,
unsigned int * V_46 )
{
struct V_1 * V_2 ;
T_1 V_47 , V_48 ;
struct V_44 * V_49 ;
int V_50 = 0 ;
if ( ! F_36 ( V_51 , V_45 ) ) {
F_37 ( L_1 ,
* V_46 ) ;
return - V_52 ;
}
if ( F_38 ( V_45 , L_2 , & V_47 ) ) {
F_37 ( L_3 , * V_46 ) ;
return - V_52 ;
}
if ( V_47 != * V_46 ) {
F_37 ( L_4 ,
* V_46 , V_47 ) ;
return - V_52 ;
}
if ( ! F_39 ( V_45 , L_5 ) ) {
F_37 ( L_6 , * V_46 ) ;
return - V_52 ;
}
V_2 = F_40 ( sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
if ( F_38 ( V_45 , L_7 , & V_2 -> V_23 ) ||
! F_41 ( V_2 -> V_23 ) ) {
F_37 ( L_8 ,
* V_46 ) ;
V_50 = - V_52 ;
goto V_55;
}
if ( F_38 ( V_45 , L_9 , & V_2 -> V_56 ) ||
! F_41 ( V_2 -> V_56 ) ) {
F_37 ( L_10 ,
* V_46 ) ;
V_50 = - V_52 ;
goto V_55;
}
if ( F_38 ( V_45 , L_11 , & V_48 ) ||
V_48 == 0 || V_48 % ( V_2 -> V_56 * V_2 -> V_23 ) ) {
F_37 ( L_12 ,
* V_46 ) ;
V_50 = - V_52 ;
goto V_55;
}
V_2 -> V_35 =
( ( T_1 ) 1 << V_48 / V_2 -> V_56 / V_2 -> V_23 ) - 1 ;
V_2 -> V_31 = F_42 ( V_45 , 0 ) ;
if ( ! V_2 -> V_31 ) {
F_37 ( L_13 , * V_46 ) ;
V_50 = - V_54 ;
goto V_55;
}
V_2 -> V_57 = F_42 ( V_45 , 1 ) ;
if ( ! V_2 -> V_57 ) {
F_37 ( L_14 , * V_46 ) ;
V_50 = - V_54 ;
goto V_55;
}
V_2 -> V_4 = F_42 ( V_45 , 2 ) ;
if ( ! V_2 -> V_4 ) {
F_37 ( L_15 , * V_46 ) ;
V_50 = - V_54 ;
goto V_55;
}
V_2 -> V_36 = V_2 -> V_31 + 0xc00 ;
if ( * V_46 == 2 ) {
T_1 V_58 = F_43 ( V_2 -> V_57 + V_59 ) ;
if ( V_58 <= 0x16 )
V_2 -> V_60 = ( T_1 ) 1 << 22 ;
switch ( V_58 ) {
case 0x11 :
V_2 -> V_36 = V_2 -> V_31 + 0x870 ;
break;
case 0x12 :
case 0x16 :
V_2 -> V_36 = V_2 -> V_31 + 0x840 ;
break;
default:
break;
}
}
V_2 -> V_60 -= V_2 -> V_23 ;
F_44 ( & V_2 -> V_41 ) ;
F_45 ( & V_2 -> V_41 , & V_40 ) ;
V_49 = F_46 ( V_45 ) ;
if ( V_49 ) {
( * V_46 ) ++ ;
V_50 = F_35 ( V_49 , V_46 ) ;
}
F_47 ( V_49 ) ;
return V_50 ;
V_55:
F_48 ( V_2 -> V_4 ) ;
F_48 ( V_2 -> V_57 ) ;
F_48 ( V_2 -> V_31 ) ;
F_49 ( V_2 ) ;
return V_50 ;
}
int T_2 F_50 ( void )
{
struct V_44 * V_45 = NULL ;
unsigned int V_46 ;
int V_50 = 0 ;
while ( ( V_45 = F_51 ( V_45 , V_51 ) ) )
if ( ! F_38 ( V_45 , L_2 , & V_46 ) &&
V_46 == 2 )
break;
if ( ! V_45 )
return - V_61 ;
V_50 = F_35 ( V_45 , & V_46 ) ;
F_47 ( V_45 ) ;
if ( V_50 ) {
if ( V_46 == 2 ) {
F_37 ( L_16 ) ;
return V_50 ;
}
V_46 -- ;
V_50 = 0 ;
}
V_62 . V_63 = F_22 ;
V_62 . V_64 = F_23 ;
V_62 . V_65 = F_24 ;
V_62 . V_66 = F_26 ;
V_62 . V_67 = F_27 ;
V_62 . V_68 = F_30 ;
F_29 () ;
F_52 ( L_17 , V_46 ) ;
return V_50 ;
}
