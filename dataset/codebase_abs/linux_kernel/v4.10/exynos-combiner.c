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
if ( F_26 ( V_24 ) != V_36 )
return - V_30 ;
if ( V_38 < 2 )
return - V_30 ;
* V_39 = V_37 [ 0 ] * V_33 + V_37 [ 1 ] ;
* V_40 = 0 ;
return 0 ;
}
static int F_27 ( struct V_34 * V_24 , unsigned int V_31 ,
T_4 V_41 )
{
struct V_3 * V_4 = V_24 -> V_42 ;
F_28 ( V_31 , & V_43 , V_44 ) ;
F_29 ( V_31 , & V_4 [ V_41 >> 3 ] ) ;
F_30 ( V_31 ) ;
return 0 ;
}
static void T_3 F_31 ( void T_1 * F_1 ,
struct V_35 * V_45 )
{
int V_46 , V_31 ;
unsigned int V_47 ;
V_47 = V_48 * V_33 ;
V_4 = F_32 ( V_48 , sizeof ( * V_4 ) , V_49 ) ;
if ( ! V_4 ) {
F_33 ( L_1 , V_50 ) ;
return;
}
V_23 = F_34 ( V_45 , V_47 ,
& V_51 , V_4 ) ;
if ( F_35 ( ! V_23 ) ) {
F_33 ( L_2 , V_50 ) ;
return;
}
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
V_31 = F_36 ( V_45 , V_46 ) ;
F_24 ( & V_4 [ V_46 ] , V_46 ,
F_1 + ( V_46 >> 2 ) * 0x10 , V_31 ) ;
F_22 ( & V_4 [ V_46 ] , V_31 ) ;
}
}
static int F_37 ( void )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ )
V_4 [ V_46 ] . V_52 =
F_11 ( V_4 [ V_46 ] . V_5 + V_9 ) ;
return 0 ;
}
static void F_38 ( void )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
F_4 ( V_4 [ V_46 ] . V_20 ,
V_4 [ V_46 ] . V_5 + V_8 ) ;
F_4 ( V_4 [ V_46 ] . V_52 ,
V_4 [ V_46 ] . V_5 + V_9 ) ;
}
}
static int T_3 F_39 ( struct V_35 * V_45 ,
struct V_35 * V_53 )
{
void T_1 * F_1 ;
F_1 = F_40 ( V_45 , 0 ) ;
if ( ! F_1 ) {
F_41 ( L_3 , V_50 ) ;
return - V_54 ;
}
if ( F_42 ( V_45 , L_4 , & V_48 ) ) {
F_43 ( L_5
L_6 ,
V_50 , V_48 ) ;
}
F_31 ( F_1 , V_45 ) ;
F_44 ( & V_55 ) ;
return 0 ;
}
