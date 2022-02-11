static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 = 0 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
if ( V_4 -> V_7 ) {
F_4 ( & V_4 -> V_6 , V_5 ) ;
F_5 ( V_8 , L_1
L_2 ) ;
return;
}
F_4 ( & V_4 -> V_6 , V_5 ) ;
F_5 ( V_8 , L_3 , V_9 ) ;
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
F_5 ( V_8 , L_4
L_2 ) ;
F_10 ( V_4 -> V_16 -> V_17 ,
& V_4 -> V_16 -> V_18 , F_11 ( 10 ) ) ;
return;
}
F_4 ( & V_4 -> V_6 , V_5 ) ;
F_5 ( V_19 , L_5 , V_9 ) ;
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
F_14 ( V_25 L_6 ,
time - V_23 , F_11 ( V_24 ) ) ;
return;
}
if ( ( time - V_23 ) > F_11 ( V_26 ) ) {
F_14 ( V_25 L_7 ,
time - V_23 , F_11 ( V_26 ) ) ;
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
struct V_27 * V_28 = (struct V_27 * )
& ( V_4 -> V_16 -> V_29 ) ;
F_5 ( V_19 , L_8 ) ;
V_28 -> V_30 = true ;
F_5 ( V_19 , L_9 ,
V_28 -> V_31 == V_32 ? L_10 : L_11 ) ;
F_6 ( V_2 , V_28 -> V_31 , V_33 ,
false ) ;
V_28 -> V_30 = false ;
F_5 ( V_19 , L_12 ) ;
}
void F_16 ( struct V_1 * V_2 )
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
F_5 ( V_19 , L_13 ) ;
V_28 -> V_31 = V_32 ;
V_4 -> V_42 = true ;
V_4 -> V_43 = true ;
F_15 ( V_2 ) ;
}
}
}
void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = (struct V_27 * )
& ( V_4 -> V_16 -> V_29 ) ;
enum V_34 V_35 ;
if ( V_28 -> V_36 ) {
V_35 = V_4 -> V_16 -> V_37 ;
if ( V_35 != V_20 && ! V_28 -> V_30 &&
V_4 -> V_16 -> V_44 <= V_33 ) {
F_5 ( V_19 , L_14 ) ;
V_28 -> V_31 = V_20 ;
V_4 -> V_43 = false ;
F_15 ( V_2 ) ;
}
}
}
void F_18 ( void * V_12 )
{
struct V_13 * V_14 = F_19 ( V_12 ,
struct V_13 , V_45 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
F_20 ( & V_4 -> V_16 -> V_46 ) ;
F_17 ( V_2 ) ;
F_21 ( & V_4 -> V_16 -> V_46 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
enum V_34 V_35 ;
V_35 = V_4 -> V_16 -> V_37 ;
if ( V_4 -> V_16 -> V_29 . V_36 ) {
if ( V_35 == V_32 ) {
if ( V_4 -> V_16 -> V_44 > V_33 ) {
F_5 ( V_47 , L_15 ,
V_9 ) ;
return;
} else {
F_14 ( V_25 L_16 ,
V_9 ) ;
F_23 ( V_4 -> V_16 -> V_17 ,
& V_4 -> V_16 -> V_45 ) ;
}
}
}
}
void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
F_20 ( & V_4 -> V_16 -> V_46 ) ;
F_17 ( V_2 ) ;
F_21 ( & V_4 -> V_16 -> V_46 ) ;
}
static bool F_25 ( struct V_1 * V_2 ,
T_3 V_48 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_16 -> V_40 == V_49 )
return false ;
F_5 ( V_50 , L_17 , V_9 , V_48 ) ;
if ( ! V_4 -> V_51 )
V_4 -> V_16 -> V_52 = V_48 ;
if ( V_4 -> V_16 -> V_53 != V_54 &&
V_48 == V_55 ) {
unsigned long V_5 ;
F_9 ( V_2 ) ;
V_4 -> V_16 -> V_53 = V_54 ;
F_3 ( & ( V_4 -> V_16 -> V_56 ) , V_5 ) ;
F_5 ( V_8 , L_18
L_19 ) ;
F_26 ( V_4 -> V_16 , 0 ) ;
F_4 ( & ( V_4 -> V_16 -> V_56 ) , V_5 ) ;
}
return true ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = (struct V_27 * )
& ( V_4 -> V_16 -> V_29 ) ;
F_5 ( V_19 , L_20 ) ;
F_5 ( V_19 , L_21
L_22 ,
V_28 -> V_57 , V_4 -> V_16 -> V_52 , V_28 -> V_58 ,
V_59 ) ;
if ( ! ( ( V_4 -> V_16 -> V_40 == V_60 ) &&
( V_4 -> V_16 -> V_38 == V_39 ) )
|| ( V_4 -> V_16 -> V_40 == V_49 ) ||
( V_4 -> V_16 -> V_40 == V_41 ) )
return;
if ( V_28 -> V_57 ) {
if ( V_28 -> V_58 >= V_59 ) {
if ( V_4 -> V_16 -> V_52 == V_55 ) {
F_5 ( V_50 , L_23
L_24 ) ;
if ( ! V_28 -> V_61 ) {
if ( V_4 -> V_16 -> V_62 )
V_4 -> V_16 -> V_62 (
V_2 , V_63 ) ;
}
F_25 ( V_2 ,
V_64 |
V_65 ) ;
}
} else
V_28 -> V_58 ++ ;
}
}
void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = (struct V_27 * )
& ( V_4 -> V_16 -> V_29 ) ;
F_5 ( V_19 , L_25 ) ;
F_5 ( V_19 , L_26 ,
V_28 -> V_57 , V_4 -> V_16 -> V_52 ) ;
if ( V_28 -> V_57 ) {
if ( V_4 -> V_16 -> V_52 != V_55 ) {
F_5 ( V_50 , L_27
L_28 ) ;
F_25 ( V_2 ,
V_55 ) ;
if ( ! V_28 -> V_61 ) {
if ( V_4 -> V_16 -> V_62 )
V_4 -> V_16 -> V_62 ( V_2 ,
V_66 ) ;
}
}
}
}
