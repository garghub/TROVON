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
static void F_20 ( void )
{
F_13 ( V_8 . V_26 , V_8 . V_27 - 1 ) ;
F_18 ( V_8 . V_26 , true ) ;
F_13 ( V_8 . V_28 , V_8 . V_29 ) ;
F_18 ( V_8 . V_28 , true ) ;
}
static void F_21 ( enum V_30 V_31 ,
struct V_24 * V_25 )
{
F_9 ( V_8 . V_26 ) ;
switch ( V_31 ) {
case V_32 :
F_13 ( V_8 . V_26 , V_8 . V_27 - 1 ) ;
F_18 ( V_8 . V_26 , true ) ;
break;
case V_33 :
break;
case V_34 :
case V_35 :
break;
case V_36 :
F_20 () ;
break;
}
}
static T_4 F_22 ( int V_37 , void * V_38 )
{
struct V_24 * V_25 = V_38 ;
if ( V_8 . V_14 . V_39 ) {
T_3 V_40 = ( 1 << V_8 . V_26 ) ;
F_4 ( V_40 | ( V_40 << 5 ) , V_8 . V_9 + V_41 ) ;
}
V_25 -> V_42 ( V_25 ) ;
return V_43 ;
}
static void T_5 F_23 ( void )
{
unsigned long V_44 ;
unsigned long V_45 ;
unsigned int V_46 ;
V_44 = F_24 ( V_8 . V_47 ) ;
F_1 ( V_8 . V_26 , V_8 . V_48 ) ;
F_6 ( V_8 . V_26 , V_8 . V_49 ) ;
V_45 = V_44 / ( V_8 . V_48 * V_8 . V_49 ) ;
V_8 . V_27 = V_45 / V_50 ;
V_51 . V_52 = F_25 ( 0 ) ;
F_26 ( & V_51 ,
V_45 , 1 , V_8 . V_29 ) ;
V_46 = V_8 . V_37 [ V_8 . V_26 ] ;
F_27 ( V_46 , & V_53 ) ;
if ( V_8 . V_14 . V_39 ) {
T_3 V_40 = ( 1 << V_8 . V_26 ) ;
F_4 ( V_40 | ( V_40 << 5 ) , V_8 . V_9 + V_41 ) ;
}
}
static void T_6 * F_28 ( void )
{
switch ( V_8 . V_28 ) {
case 0 :
case 1 :
case 2 :
case 3 :
return V_8 . V_9 + V_8 . V_28 * 0x0c + 0x14 ;
case 4 :
return V_8 . V_9 + 0x40 ;
default:
F_29 () ;
}
}
static T_3 T_7 F_30 ( void )
{
void T_6 * V_5 = F_28 () ;
if ( ! V_5 )
return 0 ;
return ~ F_10 ( V_5 ) ;
}
static void T_5 F_31 ( void )
{
void T_6 * V_5 = F_28 () ;
unsigned long V_44 ;
unsigned long V_45 ;
int V_54 ;
V_44 = F_24 ( V_8 . V_47 ) ;
F_1 ( V_8 . V_28 , V_8 . V_48 ) ;
F_6 ( V_8 . V_28 , V_8 . V_49 ) ;
V_45 = V_44 / ( V_8 . V_48 * V_8 . V_49 ) ;
F_13 ( V_8 . V_28 , V_8 . V_29 ) ;
F_18 ( V_8 . V_28 , true ) ;
F_32 ( F_30 ,
V_8 . V_14 . V_13 , V_45 ) ;
V_54 = F_33 ( V_5 , L_1 ,
V_45 , 250 , V_8 . V_14 . V_13 ,
V_55 ) ;
if ( V_54 )
F_34 ( L_2 ) ;
}
static void T_5 F_35 ( void )
{
V_8 . V_47 = F_36 ( NULL , L_3 ) ;
if ( F_37 ( V_8 . V_47 ) )
F_34 ( L_4 ) ;
F_38 ( V_8 . V_47 ) ;
V_8 . V_29 = ( 1UL << V_8 . V_14 . V_13 ) - 1 ;
if ( V_8 . V_14 . V_13 == 16 ) {
V_8 . V_48 = 25 ;
V_8 . V_49 = 2 ;
} else {
V_8 . V_48 = 2 ;
V_8 . V_49 = 1 ;
}
}
static void T_5 F_39 ( void )
{
T_2 V_40 ;
int V_1 ;
V_40 = ~ V_8 . V_14 . V_56 & ( ( 1 << V_57 ) - 1 ) ;
V_1 = F_8 ( V_40 ) - 1 ;
if ( V_1 < 0 )
F_34 ( L_5 ) ;
V_8 . V_28 = V_1 ;
V_40 &= ~ ( 1 << V_1 ) ;
V_1 = F_8 ( V_40 ) - 1 ;
if ( V_1 < 0 )
F_34 ( L_6 ) ;
V_8 . V_26 = V_1 ;
F_35 () ;
F_23 () ;
F_31 () ;
}
void T_5 F_40 ( void T_6 * V_9 ,
unsigned int * V_58 , struct V_59 * V_14 )
{
V_8 . V_9 = V_9 ;
memcpy ( & V_8 . V_14 , V_14 , sizeof( V_8 . V_14 ) ) ;
memcpy ( V_8 . V_37 , V_58 , V_57 * sizeof( * V_58 ) ) ;
F_39 () ;
}
static void T_5 F_41 ( struct V_60 * V_61 ,
const struct V_59 * V_14 )
{
struct V_62 V_63 ;
struct V_64 * V_65 ;
const T_8 * V_66 ;
T_3 V_67 ;
int V_68 ;
memcpy ( & V_8 . V_14 , V_14 , sizeof( V_8 . V_14 ) ) ;
for ( V_68 = 0 ; V_68 < V_57 ; ++ V_68 )
V_8 . V_37 [ V_68 ] = F_42 ( V_61 , V_68 ) ;
F_43 (np, L_7 , prop, cur, val) {
if ( V_67 >= V_57 ) {
F_44 ( L_8 ,
V_69 ) ;
continue;
}
V_8 . V_14 . V_56 |= 1 << V_67 ;
}
F_45 ( V_61 , 0 , & V_63 ) ;
if ( ! F_46 ( V_63 . V_70 ,
F_47 ( & V_63 ) , L_9 ) ) {
F_48 ( L_10 , V_69 ) ;
return;
}
V_8 . V_9 = F_49 ( V_63 . V_70 , F_47 ( & V_63 ) ) ;
if ( ! V_8 . V_9 ) {
F_48 ( L_11 , V_69 ) ;
F_50 ( V_63 . V_70 , F_47 ( & V_63 ) ) ;
return;
}
F_39 () ;
}
static void T_5 F_51 ( struct V_60 * V_61 )
{
F_41 ( V_61 , & V_71 ) ;
}
static void T_5 F_52 ( struct V_60 * V_61 )
{
F_41 ( V_61 , & V_72 ) ;
}
static void T_5 F_53 ( struct V_60 * V_61 )
{
F_41 ( V_61 , & V_73 ) ;
}
static void T_5 F_54 ( struct V_60 * V_61 )
{
F_41 ( V_61 , & V_74 ) ;
}
