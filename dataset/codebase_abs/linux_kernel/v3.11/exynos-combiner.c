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
V_17 = V_13 -> V_23 + F_13 ( V_18 ) ;
V_16 = F_14 ( V_24 , V_17 ) ;
if ( F_15 ( ! V_16 ) )
F_16 ( V_10 , V_12 ) ;
else
F_17 ( V_16 ) ;
V_22:
F_18 ( V_15 , V_12 ) ;
}
static int F_19 ( struct V_1 * V_25 ,
const struct V_26 * V_27 , bool V_28 )
{
struct V_3 * V_13 = F_2 ( V_25 ) ;
struct V_14 * V_15 = F_8 ( V_13 -> V_29 ) ;
struct V_1 * V_2 = F_20 ( V_13 -> V_29 ) ;
if ( V_15 && V_15 -> V_30 )
return V_15 -> V_30 ( V_2 , V_27 , V_28 ) ;
else
return - V_31 ;
}
static void T_3 F_21 ( struct V_3 * V_4 ,
unsigned int V_10 )
{
if ( F_22 ( V_10 , V_4 ) != 0 )
F_23 () ;
F_24 ( V_10 , F_6 ) ;
}
static void T_3 F_25 ( struct V_3 * V_4 ,
unsigned int V_32 ,
void T_1 * V_5 , unsigned int V_10 )
{
V_4 -> V_5 = V_5 ;
V_4 -> V_23 = ( V_32 & ~ 3 ) * V_33 ;
V_4 -> V_21 = 0xff << ( ( V_32 % 4 ) << 3 ) ;
V_4 -> V_29 = V_10 ;
F_4 ( V_4 -> V_21 , V_5 + V_8 ) ;
}
static int F_26 ( struct V_34 * V_25 ,
struct V_35 * V_36 ,
const T_2 * V_37 , unsigned int V_38 ,
unsigned long * V_39 ,
unsigned int * V_40 )
{
if ( V_25 -> V_41 != V_36 )
return - V_31 ;
if ( V_38 < 2 )
return - V_31 ;
* V_39 = V_37 [ 0 ] * V_33 + V_37 [ 1 ] ;
* V_40 = 0 ;
return 0 ;
}
static int F_26 ( struct V_34 * V_25 ,
struct V_35 * V_36 ,
const T_2 * V_37 , unsigned int V_38 ,
unsigned long * V_39 ,
unsigned int * V_40 )
{
return - V_31 ;
}
static int F_27 ( struct V_34 * V_25 , unsigned int V_10 ,
T_4 V_42 )
{
struct V_3 * V_4 = V_25 -> V_43 ;
F_28 ( V_10 , & V_44 , V_45 ) ;
F_29 ( V_10 , & V_4 [ V_42 >> 3 ] ) ;
F_30 ( V_10 , V_46 | V_47 ) ;
return 0 ;
}
static unsigned int F_31 ( int V_48 )
{
#ifdef F_32
if ( V_48 < V_49 || F_33 () )
return F_34 ( V_48 ) ;
switch ( V_48 ) {
case 16 :
return F_34 ( 107 ) ;
case 17 :
return F_34 ( 108 ) ;
case 18 :
return F_34 ( 48 ) ;
case 19 :
return F_34 ( 42 ) ;
}
#endif
return 0 ;
}
static void T_3 F_35 ( void T_1 * F_1 ,
struct V_35 * V_50 ,
unsigned int V_51 ,
int V_52 )
{
int V_53 , V_10 ;
unsigned int V_54 ;
struct V_3 * V_4 ;
V_54 = V_51 * V_33 ;
V_4 = F_36 ( V_51 , sizeof ( * V_4 ) , V_55 ) ;
if ( ! V_4 ) {
F_37 ( L_1 , V_56 ) ;
return;
}
V_24 = F_38 ( V_50 , V_54 , V_52 ,
& V_57 , V_4 ) ;
if ( F_39 ( ! V_24 ) ) {
F_37 ( L_2 , V_56 ) ;
return;
}
for ( V_53 = 0 ; V_53 < V_51 ; V_53 ++ ) {
#ifdef F_40
if ( V_50 )
V_10 = F_41 ( V_50 , V_53 ) ;
else
#endif
V_10 = F_31 ( V_53 ) ;
F_25 ( & V_4 [ V_53 ] , V_53 ,
F_1 + ( V_53 >> 2 ) * 0x10 , V_10 ) ;
F_21 ( & V_4 [ V_53 ] , V_10 ) ;
}
}
static int T_3 F_42 ( struct V_35 * V_50 ,
struct V_35 * V_58 )
{
void T_1 * F_1 ;
unsigned int V_51 = 20 ;
int V_52 = - 1 ;
F_1 = F_43 ( V_50 , 0 ) ;
if ( ! F_1 ) {
F_44 ( L_3 , V_56 ) ;
return - V_59 ;
}
if ( F_45 ( V_50 , L_4 , & V_51 ) ) {
F_46 ( L_5
L_6 ,
V_56 , V_51 ) ;
}
V_52 = 160 ;
F_35 ( F_1 , V_50 , V_51 , V_52 ) ;
return 0 ;
}
