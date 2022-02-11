static const struct V_1 * F_1 (
const struct V_1 * V_2 , T_1 V_3 )
{
const struct V_1 * V_4 ;
for ( V_4 = V_2 ; V_4 -> V_3 ; V_4 ++ )
if ( V_4 -> V_3 == V_3 )
return V_4 ;
return NULL ;
}
static int F_2 ( struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * V_10 , T_2 V_11 )
{
struct V_12 * V_13 = F_3 ( V_6 ) ;
const struct V_1 * V_4 , * V_2 ;
if ( V_10 -> V_14 == V_15 ) {
V_13 -> V_16 = ! ! V_11 ;
F_4 ( V_8 , V_10 -> type , V_10 -> V_14 , V_11 ) ;
return 1 ;
}
if ( V_17 ) {
int V_18 ;
if ( V_6 -> V_19 >= V_20 &&
V_6 -> V_19 <= V_21 )
V_2 = V_22 ;
else if ( V_6 -> V_19 < 0x21d || V_6 -> V_19 >= 0x300 )
V_2 = V_23 ;
else
V_2 = V_24 ;
V_4 = F_1 ( V_2 , V_10 -> V_14 ) ;
if ( V_4 ) {
if ( F_5 ( V_10 -> V_14 , V_13 -> V_25 ) )
V_18 = 1 ;
else if ( V_4 -> V_26 & V_27 )
V_18 = ( V_17 == 2 && V_13 -> V_16 ) ||
( V_17 == 1 && ! V_13 -> V_16 ) ;
else
V_18 = V_13 -> V_16 ;
if ( V_18 ) {
if ( V_11 )
F_6 ( V_10 -> V_14 , V_13 -> V_25 ) ;
else
F_7 ( V_10 -> V_14 , V_13 -> V_25 ) ;
F_4 ( V_8 , V_10 -> type , V_4 -> V_28 ,
V_11 ) ;
return 1 ;
}
}
if ( V_13 -> V_29 & V_30 &&
( F_5 ( V_10 -> V_14 , V_13 -> V_31 ) ||
F_5 ( V_32 , V_8 -> V_33 ) ) ) {
V_4 = F_1 ( V_34 ,
V_10 -> V_14 ) ;
if ( V_4 ) {
if ( V_11 )
F_6 ( V_10 -> V_14 ,
V_13 -> V_31 ) ;
else
F_7 ( V_10 -> V_14 ,
V_13 -> V_31 ) ;
F_4 ( V_8 , V_10 -> type , V_4 -> V_28 ,
V_11 ) ;
}
return 1 ;
}
}
if ( V_35 ) {
if ( V_13 -> V_29 & V_36 ) {
V_4 = F_1 ( V_37 , V_10 -> V_14 ) ;
if ( V_4 ) {
F_4 ( V_8 , V_10 -> type , V_4 -> V_28 , V_11 ) ;
return 1 ;
}
}
}
if ( V_38 ) {
V_4 = F_1 ( V_39 , V_10 -> V_14 ) ;
if ( V_4 ) {
F_4 ( V_8 , V_10 -> type , V_4 -> V_28 , V_11 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_8 ( struct V_5 * V_40 , struct V_41 * V_42 ,
struct V_9 * V_10 , T_2 V_11 )
{
struct V_12 * V_13 = F_3 ( V_40 ) ;
if ( ! ( V_40 -> V_43 & V_44 ) || ! V_42 -> V_45 ||
! V_10 -> type )
return 0 ;
if ( ( V_13 -> V_29 & V_46 ) &&
V_10 -> V_14 == V_47 ) {
F_4 ( V_42 -> V_45 -> V_8 , V_10 -> type , V_10 -> V_14 ,
- V_11 ) ;
return 1 ;
}
if ( ( V_13 -> V_29 & V_48 ) &&
F_2 ( V_40 , V_42 -> V_45 -> V_8 ,
V_10 , V_11 ) )
return 1 ;
return 0 ;
}
static T_3 * F_9 ( struct V_5 * V_40 , T_3 * V_49 ,
unsigned int * V_50 )
{
struct V_12 * V_13 = F_3 ( V_40 ) ;
if ( ( V_13 -> V_29 & V_51 ) && * V_50 >= 60 &&
V_49 [ 53 ] == 0x65 && V_49 [ 59 ] == 0x65 ) {
F_10 ( V_40 ,
L_1 ) ;
V_49 [ 53 ] = V_49 [ 59 ] = 0xe7 ;
}
return V_49 ;
}
static void F_11 ( struct V_7 * V_8 )
{
const struct V_1 * V_4 ;
F_6 ( V_52 , V_8 -> V_53 ) ;
for ( V_4 = V_24 ; V_4 -> V_3 ; V_4 ++ )
F_6 ( V_4 -> V_28 , V_8 -> V_53 ) ;
for ( V_4 = V_23 ; V_4 -> V_3 ; V_4 ++ )
F_6 ( V_4 -> V_28 , V_8 -> V_53 ) ;
for ( V_4 = V_34 ; V_4 -> V_3 ; V_4 ++ )
F_6 ( V_4 -> V_28 , V_8 -> V_53 ) ;
for ( V_4 = V_37 ; V_4 -> V_3 ; V_4 ++ )
F_6 ( V_4 -> V_28 , V_8 -> V_53 ) ;
}
static int F_12 ( struct V_5 * V_40 , struct V_54 * V_55 ,
struct V_41 * V_42 , struct V_9 * V_10 ,
unsigned long * * V_56 , int * V_57 )
{
if ( V_10 -> V_6 == ( V_58 | 0x0003 ) ) {
F_6 ( V_59 , V_55 -> V_8 -> V_60 ) ;
F_13 ( V_55 , V_10 , V_56 , V_57 , V_61 , V_15 ) ;
F_11 ( V_55 -> V_8 ) ;
return 1 ;
}
return 0 ;
}
static int F_14 ( struct V_5 * V_40 , struct V_54 * V_55 ,
struct V_41 * V_42 , struct V_9 * V_10 ,
unsigned long * * V_56 , int * V_57 )
{
struct V_12 * V_13 = F_3 ( V_40 ) ;
if ( V_13 -> V_29 & V_62 ) {
if ( V_10 -> V_6 == V_63 )
F_15 ( V_55 , V_10 , V_56 , V_57 , V_64 , V_47 ) ;
else if ( V_10 -> V_14 == V_65 )
F_15 ( V_55 , V_10 , V_56 , V_57 , V_61 , V_66 ) ;
else if ( V_10 -> V_14 == V_66 )
F_15 ( V_55 , V_10 , V_56 , V_57 , V_61 , V_65 ) ;
}
return 0 ;
}
static int F_16 ( struct V_5 * V_40 ,
const struct V_67 * V_68 )
{
unsigned long V_29 = V_68 -> V_69 ;
struct V_12 * V_13 ;
unsigned int V_70 = V_71 ;
int V_72 ;
V_13 = F_17 ( & V_40 -> V_73 , sizeof( * V_13 ) , V_74 ) ;
if ( V_13 == NULL ) {
F_18 ( V_40 , L_2 ) ;
return - V_75 ;
}
V_13 -> V_29 = V_29 ;
F_19 ( V_40 , V_13 ) ;
V_72 = F_20 ( V_40 ) ;
if ( V_72 ) {
F_18 ( V_40 , L_3 ) ;
return V_72 ;
}
if ( V_29 & V_76 )
V_70 |= V_77 ;
if ( V_29 & V_78 )
V_70 &= ~ V_79 ;
V_72 = F_21 ( V_40 , V_70 ) ;
if ( V_72 ) {
F_18 ( V_40 , L_4 ) ;
return V_72 ;
}
return 0 ;
}
