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
static void F_20 ( enum V_27 V_28 ,
struct V_24 * V_25 )
{
F_9 ( V_8 . V_26 ) ;
switch ( V_28 ) {
case V_29 :
F_13 ( V_8 . V_26 , V_8 . V_30 - 1 ) ;
F_18 ( V_8 . V_26 , true ) ;
break;
case V_31 :
break;
case V_32 :
case V_33 :
case V_34 :
break;
}
}
static void F_21 ( struct V_24 * V_35 )
{
F_1 ( V_8 . V_26 , V_8 . V_36 ) ;
F_6 ( V_8 . V_26 , V_8 . V_37 ) ;
if ( V_8 . V_14 . V_38 ) {
T_3 V_39 = ( 1 << V_8 . V_26 ) ;
F_4 ( V_39 | ( V_39 << 5 ) , V_8 . V_9 + V_40 ) ;
}
}
static T_4 F_22 ( int V_41 , void * V_42 )
{
struct V_24 * V_25 = V_42 ;
if ( V_8 . V_14 . V_38 ) {
T_3 V_39 = ( 1 << V_8 . V_26 ) ;
F_4 ( V_39 | ( V_39 << 5 ) , V_8 . V_9 + V_40 ) ;
}
V_25 -> V_43 ( V_25 ) ;
return V_44 ;
}
static void T_5 F_23 ( void )
{
unsigned long V_45 ;
unsigned long V_46 ;
unsigned int V_47 ;
V_45 = F_24 ( V_8 . V_48 ) ;
F_1 ( V_8 . V_26 , V_8 . V_36 ) ;
F_6 ( V_8 . V_26 , V_8 . V_37 ) ;
V_46 = V_45 / ( V_8 . V_36 * V_8 . V_37 ) ;
V_8 . V_30 = V_46 / V_49 ;
V_50 . V_51 = F_25 ( 0 ) ;
F_26 ( & V_50 ,
V_46 , 1 , V_8 . V_52 ) ;
V_47 = V_8 . V_41 [ V_8 . V_26 ] ;
F_27 ( V_47 , & V_53 ) ;
if ( V_8 . V_14 . V_38 ) {
T_3 V_39 = ( 1 << V_8 . V_26 ) ;
F_4 ( V_39 | ( V_39 << 5 ) , V_8 . V_9 + V_40 ) ;
}
}
static void F_28 ( struct V_54 * V_55 )
{
F_9 ( V_8 . V_56 ) ;
}
static void F_29 ( struct V_54 * V_55 )
{
F_1 ( V_8 . V_56 , V_8 . V_36 ) ;
F_6 ( V_8 . V_56 , V_8 . V_37 ) ;
F_13 ( V_8 . V_56 , V_8 . V_52 ) ;
F_18 ( V_8 . V_56 , true ) ;
}
static T_6 F_30 ( struct V_54 * V_57 )
{
return ~ F_31 ( V_8 . V_58 ) ;
}
static T_3 T_7 F_32 ( void )
{
return F_30 ( NULL ) ;
}
static void T_5 F_33 ( void )
{
unsigned long V_45 ;
unsigned long V_46 ;
int V_59 ;
V_45 = F_24 ( V_8 . V_48 ) ;
F_1 ( V_8 . V_56 , V_8 . V_36 ) ;
F_6 ( V_8 . V_56 , V_8 . V_37 ) ;
V_46 = V_45 / ( V_8 . V_36 * V_8 . V_37 ) ;
F_13 ( V_8 . V_56 , V_8 . V_52 ) ;
F_18 ( V_8 . V_56 , true ) ;
if ( V_8 . V_56 == 4 )
V_8 . V_58 = V_8 . V_9 + 0x40 ;
else
V_8 . V_58 = V_8 . V_9 + V_8 . V_56 * 0x0c + 0x14 ;
F_34 ( F_32 ,
V_8 . V_14 . V_13 , V_46 ) ;
V_60 . V_39 = F_35 ( V_8 . V_14 . V_13 ) ;
V_59 = F_36 ( & V_60 , V_46 ) ;
if ( V_59 )
F_37 ( L_1 ) ;
}
static void T_5 F_38 ( void )
{
F_39 ( V_8 . V_48 ) ;
V_8 . V_52 = ( 1UL << V_8 . V_14 . V_13 ) - 1 ;
if ( V_8 . V_14 . V_13 == 16 ) {
V_8 . V_36 = 25 ;
V_8 . V_37 = 2 ;
} else {
V_8 . V_36 = 2 ;
V_8 . V_37 = 1 ;
}
}
static void T_5 F_40 ( void )
{
T_2 V_39 ;
int V_1 ;
V_39 = ~ V_8 . V_14 . V_61 & ( ( 1 << V_62 ) - 1 ) ;
V_1 = F_8 ( V_39 ) - 1 ;
if ( V_1 < 0 )
F_37 ( L_2 ) ;
V_8 . V_56 = V_1 ;
V_39 &= ~ ( 1 << V_1 ) ;
V_1 = F_8 ( V_39 ) - 1 ;
if ( V_1 < 0 )
F_37 ( L_3 ) ;
V_8 . V_26 = V_1 ;
F_38 () ;
F_23 () ;
F_33 () ;
}
void T_5 F_41 ( void T_8 * V_9 ,
unsigned int * V_63 , struct V_64 * V_14 )
{
V_8 . V_9 = V_9 ;
memcpy ( & V_8 . V_14 , V_14 , sizeof( V_8 . V_14 ) ) ;
memcpy ( V_8 . V_41 , V_63 , V_62 * sizeof( * V_63 ) ) ;
V_8 . V_48 = F_42 ( NULL , L_4 ) ;
if ( F_43 ( V_8 . V_48 ) )
F_37 ( L_5 ) ;
F_40 () ;
}
static void T_5 F_44 ( struct V_65 * V_66 ,
const struct V_64 * V_14 )
{
struct V_67 * V_68 ;
const T_9 * V_69 ;
T_3 V_70 ;
int V_71 ;
memcpy ( & V_8 . V_14 , V_14 , sizeof( V_8 . V_14 ) ) ;
for ( V_71 = 0 ; V_71 < V_62 ; ++ V_71 )
V_8 . V_41 [ V_71 ] = F_45 ( V_66 , V_71 ) ;
F_46 (np, L_6 , prop, cur, val) {
if ( V_70 >= V_62 ) {
F_47 ( L_7 ,
V_72 ) ;
continue;
}
V_8 . V_14 . V_61 |= 1 << V_70 ;
}
V_8 . V_9 = F_48 ( V_66 , 0 ) ;
if ( ! V_8 . V_9 ) {
F_49 ( L_8 , V_72 ) ;
return;
}
V_8 . V_48 = F_50 ( V_66 , L_4 ) ;
if ( F_43 ( V_8 . V_48 ) )
F_37 ( L_5 ) ;
F_40 () ;
}
static void T_5 F_51 ( struct V_65 * V_66 )
{
F_44 ( V_66 , & V_73 ) ;
}
static void T_5 F_52 ( struct V_65 * V_66 )
{
F_44 ( V_66 , & V_74 ) ;
}
static void T_5 F_53 ( struct V_65 * V_66 )
{
F_44 ( V_66 , & V_75 ) ;
}
static void T_5 F_54 ( struct V_65 * V_66 )
{
F_44 ( V_66 , & V_76 ) ;
}
