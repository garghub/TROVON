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
static void F_6 ( struct V_10 * V_11 )
{
struct V_3 * V_12 = F_7 ( V_11 ) ;
struct V_13 * V_14 = F_8 ( V_11 ) ;
unsigned int V_15 , V_16 ;
unsigned long V_17 ;
F_9 ( V_14 , V_11 ) ;
F_10 ( & V_18 ) ;
V_17 = F_11 ( V_12 -> V_5 + V_19 ) ;
F_12 ( & V_18 ) ;
V_17 &= V_12 -> V_20 ;
if ( V_17 == 0 )
goto V_21;
V_16 = V_12 -> V_22 + F_13 ( V_17 ) ;
V_15 = F_14 ( V_23 , V_16 ) ;
if ( F_15 ( ! V_15 ) )
F_16 ( V_11 ) ;
else
F_17 ( V_15 ) ;
V_21:
F_18 ( V_14 , V_11 ) ;
}
static int F_19 ( struct V_1 * V_24 ,
const struct V_25 * V_26 , bool V_27 )
{
struct V_3 * V_12 = F_2 ( V_24 ) ;
struct V_13 * V_14 = F_20 ( V_12 -> V_28 ) ;
struct V_1 * V_2 = F_21 ( V_12 -> V_28 ) ;
if ( V_14 && V_14 -> V_29 )
return V_14 -> V_29 ( V_2 , V_26 , V_27 ) ;
else
return - V_30 ;
}
static void T_3 F_22 ( struct V_3 * V_4 ,
unsigned int V_31 )
{
F_23 ( V_31 , F_6 ,
V_4 ) ;
}
static void T_3 F_24 ( struct V_3 * V_4 ,
unsigned int V_32 ,
void T_1 * V_5 , unsigned int V_31 )
{
V_4 -> V_5 = V_5 ;
V_4 -> V_22 = ( V_32 & ~ 3 ) * V_33 ;
V_4 -> V_20 = 0xff << ( ( V_32 % 4 ) << 3 ) ;
V_4 -> V_28 = V_31 ;
F_4 ( V_4 -> V_20 , V_5 + V_8 ) ;
}
static int F_25 ( struct V_34 * V_24 ,
struct V_35 * V_36 ,
const T_2 * V_37 , unsigned int V_38 ,
unsigned long * V_39 ,
unsigned int * V_40 )
{
if ( V_24 -> V_41 != V_36 )
return - V_30 ;
if ( V_38 < 2 )
return - V_30 ;
* V_39 = V_37 [ 0 ] * V_33 + V_37 [ 1 ] ;
* V_40 = 0 ;
return 0 ;
}
static int F_26 ( struct V_34 * V_24 , unsigned int V_31 ,
T_4 V_42 )
{
struct V_3 * V_4 = V_24 -> V_43 ;
F_27 ( V_31 , & V_44 , V_45 ) ;
F_28 ( V_31 , & V_4 [ V_42 >> 3 ] ) ;
F_29 ( V_31 ) ;
return 0 ;
}
static void T_3 F_30 ( void T_1 * F_1 ,
struct V_35 * V_46 )
{
int V_47 , V_31 ;
unsigned int V_48 ;
V_48 = V_49 * V_33 ;
V_4 = F_31 ( V_49 , sizeof ( * V_4 ) , V_50 ) ;
if ( ! V_4 ) {
F_32 ( L_1 , V_51 ) ;
return;
}
V_23 = F_33 ( V_46 , V_48 ,
& V_52 , V_4 ) ;
if ( F_34 ( ! V_23 ) ) {
F_32 ( L_2 , V_51 ) ;
return;
}
for ( V_47 = 0 ; V_47 < V_49 ; V_47 ++ ) {
V_31 = F_35 ( V_46 , V_47 ) ;
F_24 ( & V_4 [ V_47 ] , V_47 ,
F_1 + ( V_47 >> 2 ) * 0x10 , V_31 ) ;
F_22 ( & V_4 [ V_47 ] , V_31 ) ;
}
}
static int F_36 ( void )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_49 ; V_47 ++ )
V_4 [ V_47 ] . V_53 =
F_11 ( V_4 [ V_47 ] . V_5 + V_9 ) ;
return 0 ;
}
static void F_37 ( void )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_49 ; V_47 ++ ) {
F_4 ( V_4 [ V_47 ] . V_20 ,
V_4 [ V_47 ] . V_5 + V_8 ) ;
F_4 ( V_4 [ V_47 ] . V_53 ,
V_4 [ V_47 ] . V_5 + V_9 ) ;
}
}
static int T_3 F_38 ( struct V_35 * V_46 ,
struct V_35 * V_54 )
{
void T_1 * F_1 ;
F_1 = F_39 ( V_46 , 0 ) ;
if ( ! F_1 ) {
F_40 ( L_3 , V_51 ) ;
return - V_55 ;
}
if ( F_41 ( V_46 , L_4 , & V_49 ) ) {
F_42 ( L_5
L_6 ,
V_51 , V_49 ) ;
}
F_30 ( F_1 , V_46 ) ;
F_43 ( & V_56 ) ;
return 0 ;
}
