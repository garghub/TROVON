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
if ( V_6 -> V_36 == V_37 ) {
V_4 = F_1 ( V_38 , V_10 -> V_14 ) ;
if ( V_4 ) {
F_4 ( V_8 , V_10 -> type , V_4 -> V_28 , V_11 ) ;
return 1 ;
}
}
}
if ( V_39 ) {
V_4 = F_1 ( V_40 , V_10 -> V_14 ) ;
if ( V_4 ) {
F_4 ( V_8 , V_10 -> type , V_4 -> V_28 , V_11 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_8 ( struct V_5 * V_41 , struct V_42 * V_43 ,
struct V_9 * V_10 , T_2 V_11 )
{
struct V_12 * V_13 = F_3 ( V_41 ) ;
if ( ! ( V_41 -> V_44 & V_45 ) || ! V_43 -> V_46 ||
! V_10 -> type )
return 0 ;
if ( ( V_13 -> V_29 & V_47 ) &&
V_10 -> V_14 == V_48 ) {
F_4 ( V_43 -> V_46 -> V_8 , V_10 -> type , V_10 -> V_14 ,
- V_11 ) ;
return 1 ;
}
if ( ( V_13 -> V_29 & V_49 ) &&
F_2 ( V_41 , V_43 -> V_46 -> V_8 ,
V_10 , V_11 ) )
return 1 ;
return 0 ;
}
static T_3 * F_9 ( struct V_5 * V_41 , T_3 * V_50 ,
unsigned int * V_51 )
{
struct V_12 * V_13 = F_3 ( V_41 ) ;
if ( ( V_13 -> V_29 & V_52 ) && * V_51 >= 60 &&
V_50 [ 53 ] == 0x65 && V_50 [ 59 ] == 0x65 ) {
F_10 ( V_41 ,
L_1 ) ;
V_50 [ 53 ] = V_50 [ 59 ] = 0xe7 ;
}
return V_50 ;
}
static void F_11 ( struct V_7 * V_8 )
{
const struct V_1 * V_4 ;
F_6 ( V_53 , V_8 -> V_54 ) ;
for ( V_4 = V_24 ; V_4 -> V_3 ; V_4 ++ )
F_6 ( V_4 -> V_28 , V_8 -> V_54 ) ;
for ( V_4 = V_23 ; V_4 -> V_3 ; V_4 ++ )
F_6 ( V_4 -> V_28 , V_8 -> V_54 ) ;
for ( V_4 = V_34 ; V_4 -> V_3 ; V_4 ++ )
F_6 ( V_4 -> V_28 , V_8 -> V_54 ) ;
for ( V_4 = V_38 ; V_4 -> V_3 ; V_4 ++ )
F_6 ( V_4 -> V_28 , V_8 -> V_54 ) ;
}
static int F_12 ( struct V_5 * V_41 , struct V_55 * V_56 ,
struct V_42 * V_43 , struct V_9 * V_10 ,
unsigned long * * V_57 , int * V_58 )
{
if ( V_10 -> V_6 == ( V_59 | 0x0003 ) ) {
F_6 ( V_60 , V_56 -> V_8 -> V_61 ) ;
F_13 ( V_56 , V_10 , V_57 , V_58 , V_62 , V_15 ) ;
F_11 ( V_56 -> V_8 ) ;
return 1 ;
}
return 0 ;
}
static int F_14 ( struct V_5 * V_41 , struct V_55 * V_56 ,
struct V_42 * V_43 , struct V_9 * V_10 ,
unsigned long * * V_57 , int * V_58 )
{
struct V_12 * V_13 = F_3 ( V_41 ) ;
if ( V_13 -> V_29 & V_63 ) {
if ( V_10 -> V_6 == V_64 )
F_15 ( V_56 , V_10 , V_57 , V_58 , V_65 , V_48 ) ;
else if ( V_10 -> V_14 == V_66 )
F_15 ( V_56 , V_10 , V_57 , V_58 , V_62 , V_67 ) ;
else if ( V_10 -> V_14 == V_67 )
F_15 ( V_56 , V_10 , V_57 , V_58 , V_62 , V_66 ) ;
}
return 0 ;
}
static int F_16 ( struct V_5 * V_41 ,
const struct V_68 * V_69 )
{
unsigned long V_29 = V_69 -> V_70 ;
struct V_12 * V_13 ;
unsigned int V_71 = V_72 ;
int V_73 ;
V_13 = F_17 ( & V_41 -> V_74 , sizeof( * V_13 ) , V_75 ) ;
if ( V_13 == NULL ) {
F_18 ( V_41 , L_2 ) ;
return - V_76 ;
}
V_13 -> V_29 = V_29 ;
F_19 ( V_41 , V_13 ) ;
V_73 = F_20 ( V_41 ) ;
if ( V_73 ) {
F_18 ( V_41 , L_3 ) ;
return V_73 ;
}
if ( V_29 & V_77 )
V_71 |= V_78 ;
if ( V_29 & V_79 )
V_71 &= ~ V_80 ;
V_73 = F_21 ( V_41 , V_71 ) ;
if ( V_73 ) {
F_18 ( V_41 , L_4 ) ;
return V_73 ;
}
return 0 ;
}
