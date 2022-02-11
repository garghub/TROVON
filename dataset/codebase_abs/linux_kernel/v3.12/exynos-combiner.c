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
static int F_27 ( struct V_34 * V_25 , unsigned int V_10 ,
T_4 V_42 )
{
struct V_3 * V_4 = V_25 -> V_43 ;
F_28 ( V_10 , & V_44 , V_45 ) ;
F_29 ( V_10 , & V_4 [ V_42 >> 3 ] ) ;
F_30 ( V_10 , V_46 | V_47 ) ;
return 0 ;
}
static void T_3 F_31 ( void T_1 * F_1 ,
struct V_35 * V_48 ,
unsigned int V_49 ,
int V_50 )
{
int V_51 , V_10 ;
unsigned int V_52 ;
struct V_3 * V_4 ;
V_52 = V_49 * V_33 ;
V_4 = F_32 ( V_49 , sizeof ( * V_4 ) , V_53 ) ;
if ( ! V_4 ) {
F_33 ( L_1 , V_54 ) ;
return;
}
V_24 = F_34 ( V_48 , V_52 , V_50 ,
& V_55 , V_4 ) ;
if ( F_35 ( ! V_24 ) ) {
F_33 ( L_2 , V_54 ) ;
return;
}
for ( V_51 = 0 ; V_51 < V_49 ; V_51 ++ ) {
V_10 = F_36 ( V_48 , V_51 ) ;
F_25 ( & V_4 [ V_51 ] , V_51 ,
F_1 + ( V_51 >> 2 ) * 0x10 , V_10 ) ;
F_21 ( & V_4 [ V_51 ] , V_10 ) ;
}
}
static int T_3 F_37 ( struct V_35 * V_48 ,
struct V_35 * V_56 )
{
void T_1 * F_1 ;
unsigned int V_49 = 20 ;
int V_50 = - 1 ;
F_1 = F_38 ( V_48 , 0 ) ;
if ( ! F_1 ) {
F_39 ( L_3 , V_54 ) ;
return - V_57 ;
}
if ( F_40 ( V_48 , L_4 , & V_49 ) ) {
F_41 ( L_5
L_6 ,
V_54 , V_49 ) ;
}
V_50 = 160 ;
F_31 ( F_1 , V_48 , V_49 , V_50 ) ;
return 0 ;
}
