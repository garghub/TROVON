static int F_1 ( int V_1 )
{
#ifdef F_2
return F_3 ( V_1 ) ;
#else
return F_4 () ;
#endif
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_6 ( V_3 ) ;
unsigned int V_6 = V_5 -> V_6 ;
F_7 ( 0x100 << V_6 ) ;
if ( V_6 < 2 )
F_8 ( 0x100 << V_6 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_6 ( V_3 ) ;
F_10 ( 0x100 << V_5 -> V_6 ) ;
}
static void F_11 ( void * V_7 )
{
struct V_2 * V_3 = V_7 ;
struct V_4 * V_5 = F_6 ( V_3 ) ;
unsigned int V_8 = 0x100 << V_5 -> V_6 ;
if ( V_5 -> V_9 )
F_10 ( V_8 ) ;
else
F_7 ( V_8 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_6 ( V_3 ) ;
V_5 -> V_9 = false ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_6 ( V_3 ) ;
V_5 -> V_9 = true ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_6 ( V_3 ) ;
F_15 ( & V_5 -> V_10 ) ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_6 ( V_3 ) ;
if ( V_5 -> V_9 != V_5 -> V_11 ) {
F_17 ( F_11 , V_3 , 1 ) ;
V_5 -> V_11 = V_5 -> V_9 ;
}
F_18 ( & V_5 -> V_10 ) ;
}
static void T_1 F_19 ( void )
{
int V_12 ;
int V_13 ;
struct V_4 * V_5 ;
F_7 ( V_14 ) ;
F_8 ( V_15 | V_16 ) ;
for ( V_12 = 0 ; V_12 < F_20 ( V_17 ) ; V_12 ++ ) {
V_5 = V_17 + V_12 ;
V_5 -> V_11 = false ;
V_5 -> V_9 = false ;
V_5 -> V_6 = V_12 ;
F_21 ( & V_5 -> V_10 ) ;
V_13 = V_18 + V_12 ;
switch ( V_12 ) {
case 0 :
case 1 :
case 5 :
case 6 :
case 7 :
F_22 ( V_13 , V_5 ) ;
F_23 ( V_13 , & V_19 ,
V_20 ) ;
break;
default:
break;
}
}
}
static void F_24 ( struct V_2 * V_3 )
{
T_2 V_8 = 1u << V_3 -> V_13 ;
F_25 ( V_8 , V_21 + V_22 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
T_2 V_8 = 1u << V_3 -> V_13 ;
F_25 ( V_8 , V_21 + V_23 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
}
static void F_28 ( struct V_2 * V_3 )
{
T_2 V_8 = 1u << V_3 -> V_13 ;
F_25 ( V_8 , V_21 + V_23 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
T_2 V_8 = 1u << V_3 -> V_13 ;
F_25 ( V_8 , V_21 + V_22 ) ;
}
static void F_30 ( struct V_2 * V_3 , void T_3 * V_24 )
{
int V_1 ;
unsigned int V_25 = V_3 -> V_13 - V_26 ;
T_2 V_8 ;
F_31 ( V_25 >= V_27 ) ;
F_32 (cpu) {
unsigned int V_28 = F_1 ( V_1 ) ;
V_8 = 1 << ( V_28 * V_27 + V_25 ) ;
F_25 ( V_8 , V_24 + ( V_28 * V_29 ) ) ;
}
}
static void F_33 ( struct V_2 * V_3 )
{
F_30 ( V_3 , V_21 + V_22 + sizeof( T_2 ) ) ;
}
static void F_34 ( struct V_2 * V_3 )
{
F_30 ( V_3 , V_21 + V_23 + sizeof( T_2 ) ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
T_2 V_8 ;
unsigned int V_25 = V_3 -> V_13 - V_26 ;
F_31 ( V_25 >= V_27 ) ;
V_8 = 1 << ( F_4 () * V_27 + V_25 ) ;
F_25 ( V_8 , V_21 + V_30 + sizeof( T_2 ) ) ;
}
void F_36 ( int V_1 , unsigned int V_31 )
{
unsigned int V_28 = F_1 ( V_1 ) ;
T_2 V_8 ;
F_31 ( V_31 >= ( 1 << V_27 ) ) ;
V_8 = V_31 << ( V_28 * V_27 ) ;
F_25 ( V_8 , V_21 + V_32 + sizeof( T_2 ) ) ;
}
static void F_37 ( struct V_2 * V_3 , void T_3 * V_24 )
{
unsigned int V_25 = V_3 -> V_13 - V_26 ;
unsigned int V_28 = F_4 () ;
T_2 V_8 ;
F_31 ( V_25 >= V_27 ) ;
V_8 = 1 << ( V_28 * V_27 + V_25 ) ;
F_25 ( V_8 , V_24 + ( V_28 * V_29 ) ) ;
}
static void F_38 ( struct V_2 * V_3 )
{
F_37 ( V_3 , V_21 + V_22 + sizeof( T_2 ) ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
F_37 ( V_3 , V_21 + V_23 + sizeof( T_2 ) ) ;
}
static void T_1 F_40 ( void )
{
int V_12 , V_33 ;
T_2 V_34 ;
V_21 = F_41 ( 0x1e010000 , 4096 ) ;
V_34 = F_42 ( V_21 + V_35 ) ;
V_33 = 8 * ( 1 + ( ( V_34 - 1 ) / 64 ) ) ;
F_43 ( L_1 , V_34 , V_33 ) ;
V_36 = V_37 + 0 * V_33 ;
V_32 = V_37 + 1 * V_33 ;
V_30 = V_37 + 2 * V_33 ;
V_38 = V_37 + 3 * V_33 ;
V_39 = V_37 + 4 * V_33 ;
V_22 = V_37 + 5 * V_33 ;
V_23 = V_37 + 6 * V_33 ;
V_29 = V_33 * 4 ;
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ )
F_23 ( V_12 + V_40 , & V_41 , V_42 ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ )
F_23 ( V_12 + V_26 , & V_43 , V_20 ) ;
F_10 ( V_44 ) ;
}
static void F_44 ( void )
{
unsigned int V_28 = F_4 () ;
T_2 V_45 ;
V_45 = F_42 ( V_21 + V_38 +
( V_28 * V_29 ) ) ;
if ( ! V_45 ) {
V_45 = F_42 ( V_21 + V_38 + ( V_28 * V_29 ) + sizeof( T_2 ) ) ;
V_45 = ( V_45 >> ( 2 * V_28 ) ) & 3 ;
if ( ! V_45 )
F_45 () ;
else
F_46 ( F_47 ( V_45 ) + V_26 ) ;
} else {
F_46 ( F_47 ( V_45 ) ) ;
}
}
void T_1 F_48 ( void )
{
F_19 () ;
F_40 () ;
}
T_4 void F_49 ( void )
{
unsigned int V_46 = F_50 () & F_51 () & V_14 ;
int V_47 ;
if ( F_52 ( ! V_46 ) ) {
F_45 () ;
return;
}
V_47 = F_53 ( V_46 ) - 1 - V_48 ;
if ( V_47 == 2 )
F_44 () ;
else
F_46 ( V_18 + V_47 ) ;
}
