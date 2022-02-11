static inline void T_1 * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_2 V_6 = 1 << ( V_2 -> V_7 % 32 ) ;
F_4 ( V_6 , F_1 ( V_2 ) + V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_2 V_6 = 1 << ( V_2 -> V_7 % 32 ) ;
F_4 ( V_6 , F_1 ( V_2 ) + V_9 ) ;
}
static void F_6 ( unsigned int V_10 , struct V_11 * V_12 )
{
struct V_3 * V_13 = F_7 ( V_10 ) ;
struct V_14 * V_15 = F_8 ( V_10 ) ;
unsigned int V_16 , V_17 ;
unsigned long V_18 ;
F_9 ( V_15 , V_12 ) ;
F_10 ( & V_19 ) ;
V_18 = F_11 ( V_13 -> V_5 + V_20 ) ;
F_12 ( & V_19 ) ;
V_18 &= V_13 -> V_21 ;
if ( V_18 == 0 )
goto V_22;
V_17 = F_13 ( V_18 ) ;
V_16 = V_17 + ( V_13 -> V_23 & ~ 31 ) ;
if ( F_14 ( V_16 >= V_24 ) )
F_15 ( V_16 , V_12 ) ;
else
F_16 ( V_16 ) ;
V_22:
F_17 ( V_15 , V_12 ) ;
}
static void T_3 F_18 ( unsigned int V_25 , unsigned int V_10 )
{
unsigned int V_26 ;
if ( F_19 () )
V_26 = V_27 ;
else
V_26 = V_28 ;
if ( V_25 >= V_26 )
F_20 () ;
if ( F_21 ( V_10 , & V_4 [ V_25 ] ) != 0 )
F_20 () ;
F_22 ( V_10 , F_6 ) ;
}
static void T_3 F_23 ( unsigned int V_25 ,
void T_1 * V_5 )
{
V_4 [ V_25 ] . V_5 = V_5 ;
V_4 [ V_25 ] . V_23 = F_24 (
V_29 , V_25 * V_30 ) ;
V_4 [ V_25 ] . V_21 = 0xff << ( ( V_25 % 4 ) << 3 ) ;
F_4 ( V_4 [ V_25 ] . V_21 ,
V_5 + V_8 ) ;
}
static int F_25 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
const T_2 * V_35 , unsigned int V_36 ,
unsigned long * V_37 ,
unsigned int * V_38 )
{
if ( V_32 -> V_39 != V_34 )
return - V_40 ;
if ( V_36 < 2 )
return - V_40 ;
* V_37 = V_35 [ 0 ] * V_30 + V_35 [ 1 ] ;
* V_38 = 0 ;
return 0 ;
}
static int F_25 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
const T_2 * V_35 , unsigned int V_36 ,
unsigned long * V_37 ,
unsigned int * V_38 )
{
return - V_40 ;
}
static int F_26 ( struct V_31 * V_32 , unsigned int V_10 ,
T_4 V_41 )
{
F_27 ( V_10 , & V_42 , V_43 ) ;
F_28 ( V_10 , & V_4 [ V_41 >> 3 ] ) ;
F_29 ( V_10 , V_44 | V_45 ) ;
return 0 ;
}
void T_3 F_30 ( void T_1 * F_1 ,
struct V_33 * V_46 )
{
int V_47 , V_10 , V_48 ;
unsigned int V_26 , V_49 ;
if ( V_46 ) {
if ( F_31 ( V_46 , L_1 , & V_26 ) ) {
F_32 ( L_2
L_3 ,
V_50 , V_28 ) ;
V_26 = V_28 ;
}
} else {
V_26 = F_19 () ? V_27 :
V_28 ;
}
V_49 = V_26 * V_30 ;
V_48 = F_33 ( F_34 ( 0 , 0 ) , 1 , V_49 , 0 ) ;
if ( F_35 ( V_48 ) ) {
V_48 = F_34 ( 0 , 0 ) ;
F_32 ( L_4 , V_50 , V_48 ) ;
}
V_29 = F_36 ( V_46 , V_49 , V_48 , 0 ,
& V_51 , & V_4 ) ;
if ( F_37 ( ! V_29 ) ) {
F_32 ( L_5 , V_50 ) ;
return;
}
for ( V_47 = 0 ; V_47 < V_26 ; V_47 ++ ) {
F_23 ( V_47 , F_1 + ( V_47 >> 2 ) * 0x10 ) ;
V_10 = F_38 ( V_47 ) ;
#ifdef F_39
if ( V_46 )
V_10 = F_40 ( V_46 , V_47 ) ;
#endif
F_18 ( V_47 , V_10 ) ;
}
}
static int T_3 F_41 ( struct V_33 * V_46 ,
struct V_33 * V_52 )
{
void T_1 * F_1 ;
F_1 = F_42 ( V_46 , 0 ) ;
if ( ! F_1 ) {
F_43 ( L_6 , V_50 ) ;
return - V_53 ;
}
F_30 ( F_1 , V_46 ) ;
return 0 ;
}
