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
F_3 ( & V_4 -> V_22 , V_5 ) ;
time -= F_11 ( 8 + 16 + 7 ) ;
if ( ( time - V_23 ) <= F_11 ( V_24 ) ) {
F_4 ( & V_4 -> V_22 , V_5 ) ;
F_14 ( V_2 , L_5 ,
time - V_23 , F_11 ( V_24 ) ) ;
return;
}
if ( ( time - V_23 ) > F_11 ( V_25 ) ) {
F_14 ( V_2 , L_6 ,
time - V_23 , F_11 ( V_25 ) ) ;
F_4 ( & V_4 -> V_22 , V_5 ) ;
return;
}
V_21 = time - V_23 ;
F_10 ( V_4 -> V_16 -> V_17 ,
& V_4 -> V_16 -> V_18 , V_21 ) ;
F_10 ( V_4 -> V_16 -> V_17 ,
( void * ) & V_4 -> V_16 -> V_15 , 0 ) ;
F_4 ( & V_4 -> V_22 , V_5 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_26 * V_27 = (struct V_26 * )
& ( V_4 -> V_16 -> V_28 ) ;
F_5 ( V_19 , L_7 ) ;
V_27 -> V_29 = true ;
F_5 ( V_19 , L_8 ,
V_27 -> V_30 == V_31 ? L_9 : L_10 ) ;
F_6 ( V_2 , V_27 -> V_30 , V_32 ,
false ) ;
V_27 -> V_29 = false ;
F_5 ( V_19 , L_11 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_26 * V_27 = (struct V_26 * )
& ( V_4 -> V_16 -> V_28 ) ;
enum V_33 V_34 ;
if ( V_27 -> V_35 ) {
V_34 = V_4 -> V_16 -> V_36 ;
if ( V_34 == V_20 && ! V_27 -> V_29 &&
( V_4 -> V_16 -> V_37 != V_38 ) &&
( V_4 -> V_16 -> V_39 != V_40 ) ) {
F_5 ( V_19 , L_12 ) ;
V_27 -> V_30 = V_31 ;
V_4 -> V_41 = true ;
V_4 -> V_42 = true ;
F_15 ( V_2 ) ;
}
}
}
void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_26 * V_27 = (struct V_26 * )
& ( V_4 -> V_16 -> V_28 ) ;
enum V_33 V_34 ;
if ( V_27 -> V_35 ) {
V_34 = V_4 -> V_16 -> V_36 ;
if ( V_34 != V_20 && ! V_27 -> V_29 &&
V_4 -> V_16 -> V_43 <= V_32 ) {
F_5 ( V_19 , L_13 ) ;
V_27 -> V_30 = V_20 ;
V_4 -> V_42 = false ;
F_15 ( V_2 ) ;
}
}
}
void F_18 ( void * V_12 )
{
struct V_13 * V_14 = F_19 ( V_12 ,
struct V_13 , V_44 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
F_20 ( & V_4 -> V_16 -> V_45 ) ;
F_17 ( V_2 ) ;
F_21 ( & V_4 -> V_16 -> V_45 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
enum V_33 V_34 ;
V_34 = V_4 -> V_16 -> V_36 ;
if ( V_4 -> V_16 -> V_28 . V_35 ) {
if ( V_34 == V_31 ) {
if ( V_4 -> V_16 -> V_43 > V_32 ) {
F_5 ( V_46 , L_14 ,
V_9 ) ;
return;
}
F_14 ( V_2 , L_15 ,
V_9 ) ;
F_23 ( V_4 -> V_16 -> V_17 ,
& V_4 -> V_16 -> V_44 ) ;
}
}
}
void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
F_20 ( & V_4 -> V_16 -> V_45 ) ;
F_17 ( V_2 ) ;
F_21 ( & V_4 -> V_16 -> V_45 ) ;
}
static bool F_25 ( struct V_1 * V_2 ,
T_3 V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_16 -> V_39 == V_48 )
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
F_26 ( V_4 -> V_16 , 0 ) ;
F_4 ( & ( V_4 -> V_16 -> V_55 ) , V_5 ) ;
}
return true ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_26 * V_27 = (struct V_26 * )
& ( V_4 -> V_16 -> V_28 ) ;
F_5 ( V_19 , L_18 ) ;
F_5 ( V_19 ,
L_19 ,
V_27 -> V_56 , V_4 -> V_16 -> V_51 , V_27 -> V_57 ,
V_58 ) ;
if ( ! ( ( V_4 -> V_16 -> V_39 == V_59 ) &&
( V_4 -> V_16 -> V_37 == V_38 ) )
|| ( V_4 -> V_16 -> V_39 == V_48 ) ||
( V_4 -> V_16 -> V_39 == V_40 ) )
return;
if ( V_27 -> V_56 ) {
if ( V_27 -> V_57 >= V_58 ) {
if ( V_4 -> V_16 -> V_51 == V_54 ) {
F_5 ( V_49 ,
L_20 ) ;
if ( ! V_27 -> V_60 ) {
if ( V_4 -> V_16 -> V_61 )
V_4 -> V_16 -> V_61 (
V_2 , V_62 ) ;
}
F_25 ( V_2 ,
V_63 |
V_64 ) ;
}
} else
V_27 -> V_57 ++ ;
}
}
void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_26 * V_27 = (struct V_26 * )
& ( V_4 -> V_16 -> V_28 ) ;
F_5 ( V_19 , L_21 ) ;
F_5 ( V_19 , L_22 ,
V_27 -> V_56 , V_4 -> V_16 -> V_51 ) ;
if ( V_27 -> V_56 ) {
if ( V_4 -> V_16 -> V_51 != V_54 ) {
F_5 ( V_49 ,
L_23 ) ;
F_25 ( V_2 ,
V_54 ) ;
if ( ! V_27 -> V_60 ) {
if ( V_4 -> V_16 -> V_61 )
V_4 -> V_16 -> V_61 ( V_2 ,
V_65 ) ;
}
}
}
}
