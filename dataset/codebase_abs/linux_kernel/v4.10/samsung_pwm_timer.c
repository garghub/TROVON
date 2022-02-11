static void F_1 ( unsigned int V_1 , T_1 V_2 )
{
unsigned long V_3 ;
T_2 V_4 = 0 ;
T_3 V_5 ;
if ( V_1 >= 2 )
V_4 = V_6 ;
F_2 ( & V_7 , V_3 ) ;
V_5 = F_3 ( V_8 . V_9 + V_10 ) ;
V_5 &= ~ ( V_11 << V_4 ) ;
V_5 |= ( V_2 - 1 ) << V_4 ;
F_4 ( V_5 , V_8 . V_9 + V_10 ) ;
F_5 ( & V_7 , V_3 ) ;
}
static void F_6 ( unsigned int V_1 , T_2 V_12 )
{
T_2 V_4 = F_7 ( V_1 ) ;
unsigned long V_3 ;
T_3 V_5 ;
T_2 V_13 ;
V_13 = ( F_8 ( V_12 ) - 1 ) - V_8 . V_14 . V_15 ;
F_2 ( & V_7 , V_3 ) ;
V_5 = F_3 ( V_8 . V_9 + V_16 ) ;
V_5 &= ~ ( V_17 << V_4 ) ;
V_5 |= V_13 << V_4 ;
F_4 ( V_5 , V_8 . V_9 + V_16 ) ;
F_5 ( & V_7 , V_3 ) ;
}
static void F_9 ( unsigned int V_1 )
{
unsigned long V_18 ;
unsigned long V_3 ;
if ( V_1 > 0 )
++ V_1 ;
F_2 ( & V_7 , V_3 ) ;
V_18 = F_10 ( V_8 . V_9 + V_19 ) ;
V_18 &= ~ F_11 ( V_1 ) ;
F_12 ( V_18 , V_8 . V_9 + V_19 ) ;
F_5 ( & V_7 , V_3 ) ;
}
static void F_13 ( unsigned int V_1 , unsigned long V_20 )
{
unsigned long V_18 ;
unsigned long V_3 ;
unsigned int V_21 = V_1 ;
if ( V_21 > 0 )
++ V_21 ;
F_2 ( & V_7 , V_3 ) ;
V_18 = F_10 ( V_8 . V_9 + V_19 ) ;
V_18 &= ~ ( F_11 ( V_21 ) | F_14 ( V_21 ) ) ;
V_18 |= F_15 ( V_21 ) ;
F_12 ( V_20 , V_8 . V_9 + F_16 ( V_1 ) ) ;
F_12 ( V_20 , V_8 . V_9 + F_17 ( V_1 ) ) ;
F_12 ( V_18 , V_8 . V_9 + V_19 ) ;
F_5 ( & V_7 , V_3 ) ;
}
static void F_18 ( unsigned int V_1 , bool V_22 )
{
unsigned long V_18 ;
unsigned long V_3 ;
if ( V_1 > 0 )
++ V_1 ;
F_2 ( & V_7 , V_3 ) ;
V_18 = F_10 ( V_8 . V_9 + V_19 ) ;
V_18 &= ~ F_15 ( V_1 ) ;
V_18 |= F_11 ( V_1 ) ;
if ( V_22 )
V_18 |= F_14 ( V_1 ) ;
else
V_18 &= ~ F_14 ( V_1 ) ;
F_12 ( V_18 , V_8 . V_9 + V_19 ) ;
F_5 ( & V_7 , V_3 ) ;
}
static int F_19 ( unsigned long V_23 ,
struct V_24 * V_25 )
{
if ( ! V_23 )
V_23 = 1 ;
F_13 ( V_8 . V_26 , V_23 ) ;
F_18 ( V_8 . V_26 , false ) ;
return 0 ;
}
static int F_20 ( struct V_24 * V_25 )
{
F_9 ( V_8 . V_26 ) ;
return 0 ;
}
static int F_21 ( struct V_24 * V_25 )
{
F_9 ( V_8 . V_26 ) ;
F_13 ( V_8 . V_26 , V_8 . V_27 - 1 ) ;
F_18 ( V_8 . V_26 , true ) ;
return 0 ;
}
static void F_22 ( struct V_24 * V_28 )
{
F_1 ( V_8 . V_26 , V_8 . V_29 ) ;
F_6 ( V_8 . V_26 , V_8 . V_30 ) ;
if ( V_8 . V_14 . V_31 ) {
T_3 V_32 = ( 1 << V_8 . V_26 ) ;
F_4 ( V_32 | ( V_32 << 5 ) , V_8 . V_9 + V_33 ) ;
}
}
static T_4 F_23 ( int V_34 , void * V_35 )
{
struct V_24 * V_25 = V_35 ;
if ( V_8 . V_14 . V_31 ) {
T_3 V_32 = ( 1 << V_8 . V_26 ) ;
F_4 ( V_32 | ( V_32 << 5 ) , V_8 . V_9 + V_33 ) ;
}
V_25 -> V_36 ( V_25 ) ;
return V_37 ;
}
static void T_5 F_24 ( void )
{
unsigned long V_38 ;
unsigned long V_39 ;
unsigned int V_40 ;
V_38 = F_25 ( V_8 . V_41 ) ;
F_1 ( V_8 . V_26 , V_8 . V_29 ) ;
F_6 ( V_8 . V_26 , V_8 . V_30 ) ;
V_39 = V_38 / ( V_8 . V_29 * V_8 . V_30 ) ;
V_8 . V_27 = V_39 / V_42 ;
V_43 . V_44 = F_26 ( 0 ) ;
F_27 ( & V_43 ,
V_39 , 1 , V_8 . V_45 ) ;
V_40 = V_8 . V_34 [ V_8 . V_26 ] ;
F_28 ( V_40 , & V_46 ) ;
if ( V_8 . V_14 . V_31 ) {
T_3 V_32 = ( 1 << V_8 . V_26 ) ;
F_4 ( V_32 | ( V_32 << 5 ) , V_8 . V_9 + V_33 ) ;
}
}
static void F_29 ( struct V_47 * V_48 )
{
F_9 ( V_8 . V_49 ) ;
}
static void F_30 ( struct V_47 * V_48 )
{
F_1 ( V_8 . V_49 , V_8 . V_29 ) ;
F_6 ( V_8 . V_49 , V_8 . V_30 ) ;
F_13 ( V_8 . V_49 , V_8 . V_45 ) ;
F_18 ( V_8 . V_49 , true ) ;
}
static T_6 T_7 F_31 ( struct V_47 * V_50 )
{
return ~ F_10 ( V_8 . V_51 ) ;
}
static T_6 T_7 F_32 ( void )
{
return F_31 ( NULL ) ;
}
static int T_5 F_33 ( void )
{
unsigned long V_38 ;
unsigned long V_39 ;
V_38 = F_25 ( V_8 . V_41 ) ;
F_1 ( V_8 . V_49 , V_8 . V_29 ) ;
F_6 ( V_8 . V_49 , V_8 . V_30 ) ;
V_39 = V_38 / ( V_8 . V_29 * V_8 . V_30 ) ;
F_13 ( V_8 . V_49 , V_8 . V_45 ) ;
F_18 ( V_8 . V_49 , true ) ;
if ( V_8 . V_49 == 4 )
V_8 . V_51 = V_8 . V_9 + 0x40 ;
else
V_8 . V_51 = V_8 . V_9 + V_8 . V_49 * 0x0c + 0x14 ;
F_34 ( F_32 ,
V_8 . V_14 . V_13 , V_39 ) ;
V_52 . V_32 = F_35 ( V_8 . V_14 . V_13 ) ;
return F_36 ( & V_52 , V_39 ) ;
}
static void T_5 F_37 ( void )
{
F_38 ( V_8 . V_41 ) ;
V_8 . V_45 = ( 1UL << V_8 . V_14 . V_13 ) - 1 ;
if ( V_8 . V_14 . V_13 == 16 ) {
V_8 . V_29 = 25 ;
V_8 . V_30 = 2 ;
} else {
V_8 . V_29 = 2 ;
V_8 . V_30 = 1 ;
}
}
static int T_5 F_39 ( void )
{
T_2 V_32 ;
int V_1 ;
V_32 = ~ V_8 . V_14 . V_53 & ( ( 1 << V_54 ) - 1 ) ;
V_1 = F_8 ( V_32 ) - 1 ;
if ( V_1 < 0 ) {
F_40 ( L_1 ) ;
return - V_55 ;
}
V_8 . V_49 = V_1 ;
V_32 &= ~ ( 1 << V_1 ) ;
V_1 = F_8 ( V_32 ) - 1 ;
if ( V_1 < 0 ) {
F_40 ( L_2 ) ;
return - V_55 ;
}
V_8 . V_26 = V_1 ;
F_37 () ;
F_24 () ;
return F_33 () ;
}
void T_5 F_41 ( void T_8 * V_9 ,
unsigned int * V_56 , struct V_57 * V_14 )
{
V_8 . V_9 = V_9 ;
memcpy ( & V_8 . V_14 , V_14 , sizeof( V_8 . V_14 ) ) ;
memcpy ( V_8 . V_34 , V_56 , V_54 * sizeof( * V_56 ) ) ;
V_8 . V_41 = F_42 ( NULL , L_3 ) ;
if ( F_43 ( V_8 . V_41 ) )
F_44 ( L_4 ) ;
F_39 () ;
}
static int T_5 F_45 ( struct V_58 * V_59 ,
const struct V_57 * V_14 )
{
struct V_60 * V_61 ;
const T_9 * V_62 ;
T_3 V_63 ;
int V_64 ;
memcpy ( & V_8 . V_14 , V_14 , sizeof( V_8 . V_14 ) ) ;
for ( V_64 = 0 ; V_64 < V_54 ; ++ V_64 )
V_8 . V_34 [ V_64 ] = F_46 ( V_59 , V_64 ) ;
F_47 (np, L_5 , prop, cur, val) {
if ( V_63 >= V_54 ) {
F_48 ( L_6 ,
V_65 ) ;
continue;
}
V_8 . V_14 . V_53 |= 1 << V_63 ;
}
V_8 . V_9 = F_49 ( V_59 , 0 ) ;
if ( ! V_8 . V_9 ) {
F_50 ( L_7 , V_65 ) ;
return - V_66 ;
}
V_8 . V_41 = F_51 ( V_59 , L_3 ) ;
if ( F_43 ( V_8 . V_41 ) ) {
F_40 ( L_4 ) ;
return F_52 ( V_8 . V_41 ) ;
}
return F_39 () ;
}
static int T_5 F_53 ( struct V_58 * V_59 )
{
return F_45 ( V_59 , & V_67 ) ;
}
static int T_5 F_54 ( struct V_58 * V_59 )
{
return F_45 ( V_59 , & V_68 ) ;
}
static int T_5 F_55 ( struct V_58 * V_59 )
{
return F_45 ( V_59 , & V_69 ) ;
}
static int T_5 F_56 ( struct V_58 * V_59 )
{
return F_45 ( V_59 , & V_70 ) ;
}
