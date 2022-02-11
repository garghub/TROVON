static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 = 0 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
if ( V_4 -> V_7 ) {
F_4 ( & V_4 -> V_6 , V_5 ) ;
F_5 ( V_8 ,
L_1 ) ;
return;
}
F_4 ( & V_4 -> V_6 , V_5 ) ;
F_5 ( V_8 , L_2 , V_9 ) ;
F_6 ( V_2 , V_10 , V_11 , false ) ;
}
void F_7 ( void * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ,
struct V_13 , V_15 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
F_1 ( V_2 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 = 0 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
if ( V_4 -> V_7 ) {
F_4 ( & V_4 -> V_6 , V_5 ) ;
F_5 ( V_8 ,
L_3 ) ;
F_10 ( V_4 -> V_16 -> V_17 ,
& V_4 -> V_16 -> V_18 ,
F_11 ( 10 ) ) ;
return;
}
F_4 ( & V_4 -> V_6 , V_5 ) ;
F_5 ( V_19 , L_4 , V_9 ) ;
F_6 ( V_2 , V_20 , V_11 , false ) ;
}
void F_12 ( void * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ,
struct V_13 , V_18 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
F_9 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 , T_1 time )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_21 ;
unsigned long V_5 ;
unsigned long V_22 ;
F_3 ( & V_4 -> V_23 , V_5 ) ;
time -= F_11 ( 8 + 16 + 7 ) ;
V_22 = V_24 + F_11 ( V_25 ) ;
if ( F_14 ( ( unsigned long ) time , V_22 ) ) {
F_4 ( & V_4 -> V_23 , V_5 ) ;
F_15 ( V_2 , L_5 ,
time - V_24 , F_11 ( V_25 ) ) ;
return;
}
V_22 = V_24 + F_11 ( V_26 ) ;
if ( F_16 ( ( unsigned long ) time , V_22 ) ) {
F_15 ( V_2 , L_6 ,
time - V_24 , F_11 ( V_26 ) ) ;
F_4 ( & V_4 -> V_23 , V_5 ) ;
return;
}
V_21 = time - V_24 ;
F_10 ( V_4 -> V_16 -> V_17 ,
& V_4 -> V_16 -> V_18 , V_21 ) ;
F_10 ( V_4 -> V_16 -> V_17 ,
( void * ) & V_4 -> V_16 -> V_15 , 0 ) ;
F_4 ( & V_4 -> V_23 , V_5 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = (struct V_27 * )
& ( V_4 -> V_16 -> V_29 ) ;
F_5 ( V_19 , L_7 ) ;
V_28 -> V_30 = true ;
F_5 ( V_19 , L_8 ,
V_28 -> V_31 == V_32 ? L_9 : L_10 ) ;
F_6 ( V_2 , V_28 -> V_31 , V_33 ,
false ) ;
V_28 -> V_30 = false ;
F_5 ( V_19 , L_11 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = (struct V_27 * )
& ( V_4 -> V_16 -> V_29 ) ;
enum V_34 V_35 ;
if ( V_28 -> V_36 ) {
V_35 = V_4 -> V_16 -> V_37 ;
if ( V_35 == V_20 && ! V_28 -> V_30 &&
( V_4 -> V_16 -> V_38 != V_39 ) &&
( V_4 -> V_16 -> V_40 != V_41 ) ) {
F_5 ( V_19 , L_12 ) ;
V_28 -> V_31 = V_32 ;
V_4 -> V_42 = true ;
V_4 -> V_43 = true ;
F_17 ( V_2 ) ;
}
}
}
void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = (struct V_27 * )
& ( V_4 -> V_16 -> V_29 ) ;
enum V_34 V_35 ;
if ( V_28 -> V_36 ) {
V_35 = V_4 -> V_16 -> V_37 ;
if ( V_35 != V_20 && ! V_28 -> V_30 &&
V_4 -> V_16 -> V_44 <= V_33 ) {
F_5 ( V_19 , L_13 ) ;
V_28 -> V_31 = V_20 ;
V_4 -> V_43 = false ;
F_17 ( V_2 ) ;
}
}
}
void F_20 ( void * V_12 )
{
struct V_13 * V_14 = F_21 ( V_12 ,
struct V_13 , V_45 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
F_22 ( & V_4 -> V_16 -> V_46 ) ;
F_19 ( V_2 ) ;
F_23 ( & V_4 -> V_16 -> V_46 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
enum V_34 V_35 ;
V_35 = V_4 -> V_16 -> V_37 ;
if ( V_4 -> V_16 -> V_29 . V_36 ) {
if ( V_35 == V_32 ) {
if ( V_4 -> V_16 -> V_44 > V_33 ) {
F_25 ( V_2 , L_14 ,
V_9 ) ;
return;
}
F_15 ( V_2 , L_15 ,
V_9 ) ;
F_26 ( V_4 -> V_16 -> V_17 ,
& V_4 -> V_16 -> V_45 ) ;
}
}
}
void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
F_22 ( & V_4 -> V_16 -> V_46 ) ;
F_19 ( V_2 ) ;
F_23 ( & V_4 -> V_16 -> V_46 ) ;
}
static bool F_28 ( struct V_1 * V_2 ,
T_3 V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_16 -> V_40 == V_48 )
return false ;
F_5 ( V_49 , L_16 , V_9 , V_47 ) ;
if ( ! V_4 -> V_50 )
V_4 -> V_16 -> V_51 = V_47 ;
if ( V_4 -> V_16 -> V_52 != V_53 &&
V_47 == V_54 ) {
unsigned long V_5 ;
F_9 ( V_2 ) ;
V_4 -> V_16 -> V_52 = V_53 ;
F_3 ( & ( V_4 -> V_16 -> V_55 ) , V_5 ) ;
F_5 ( V_8 ,
L_17 ) ;
F_29 ( V_4 -> V_16 , 0 ) ;
F_4 ( & ( V_4 -> V_16 -> V_55 ) , V_5 ) ;
}
return true ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = (struct V_27 * )
& ( V_4 -> V_16 -> V_29 ) ;
F_5 ( V_19 , L_18 ) ;
F_5 ( V_19 ,
L_19 ,
V_28 -> V_56 , V_4 -> V_16 -> V_51 , V_28 -> V_57 ,
V_58 ) ;
if ( ! ( ( V_4 -> V_16 -> V_40 == V_59 ) &&
( V_4 -> V_16 -> V_38 == V_39 ) )
|| ( V_4 -> V_16 -> V_40 == V_48 ) ||
( V_4 -> V_16 -> V_40 == V_41 ) )
return;
if ( V_28 -> V_56 ) {
if ( V_28 -> V_57 >= V_58 ) {
if ( V_4 -> V_16 -> V_51 == V_54 ) {
F_5 ( V_49 ,
L_20 ) ;
if ( ! V_28 -> V_60 ) {
if ( V_4 -> V_16 -> V_61 )
V_4 -> V_16 -> V_61 (
V_2 , V_62 ) ;
}
F_28 ( V_2 ,
V_63 |
V_64 ) ;
}
} else
V_28 -> V_57 ++ ;
}
}
void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = (struct V_27 * )
& ( V_4 -> V_16 -> V_29 ) ;
F_5 ( V_19 , L_21 ) ;
F_5 ( V_19 , L_22 ,
V_28 -> V_56 , V_4 -> V_16 -> V_51 ) ;
if ( V_28 -> V_56 ) {
if ( V_4 -> V_16 -> V_51 != V_54 ) {
F_5 ( V_49 ,
L_23 ) ;
F_28 ( V_2 ,
V_54 ) ;
if ( ! V_28 -> V_60 ) {
if ( V_4 -> V_16 -> V_61 )
V_4 -> V_16 -> V_61 ( V_2 ,
V_65 ) ;
}
}
}
}
