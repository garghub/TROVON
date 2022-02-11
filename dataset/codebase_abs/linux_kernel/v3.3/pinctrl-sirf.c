static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( V_3 >= F_2 ( V_4 ) )
return - V_5 ;
return 0 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_3 )
{
if ( V_3 >= F_2 ( V_4 ) )
return NULL ;
return V_4 [ V_3 ] . V_6 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 ,
const unsigned * * V_7 ,
unsigned * V_8 )
{
if ( V_3 >= F_2 ( V_4 ) )
return - V_5 ;
* V_7 = V_4 [ V_3 ] . V_7 ;
* V_8 = V_4 [ V_3 ] . V_8 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_9 * V_10 ,
unsigned V_11 )
{
F_6 ( V_10 , L_1 V_12 ) ;
}
static void F_7 ( struct V_13 * V_14 , unsigned V_3 ,
bool V_15 )
{
int V_16 ;
const struct V_17 * V_18 = V_19 [ V_3 ] . V_20 ;
const struct V_21 * V_22 = V_18 -> V_23 ;
for ( V_16 = 0 ; V_16 < V_18 -> V_24 ; V_16 ++ ) {
T_1 V_25 ;
V_25 = F_8 ( V_14 -> V_26 + F_9 ( V_22 [ V_16 ] . V_27 ) ) ;
if ( V_15 )
V_25 = V_25 & ~ V_22 [ V_16 ] . V_22 ;
else
V_25 = V_25 | V_22 [ V_16 ] . V_22 ;
F_10 ( V_25 , V_14 -> V_26 + F_9 ( V_22 [ V_16 ] . V_27 ) ) ;
}
if ( V_18 -> V_28 && V_15 ) {
T_1 V_29 ;
V_29 =
F_8 ( V_14 -> V_30 + V_31 ) ;
V_29 =
( V_29 & ~ V_18 -> V_28 ) | ( V_18 ->
V_32 ) ;
F_10 ( V_29 , V_14 -> V_30 + V_31 ) ;
}
}
static int F_11 ( struct V_1 * V_33 , unsigned V_3 ,
unsigned V_27 )
{
struct V_13 * V_14 ;
V_14 = F_12 ( V_33 ) ;
F_7 ( V_14 , V_3 , true ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_33 , unsigned V_3 ,
unsigned V_27 )
{
struct V_13 * V_14 ;
V_14 = F_12 ( V_33 ) ;
F_7 ( V_14 , V_3 , false ) ;
}
static int F_14 ( struct V_1 * V_33 , unsigned V_3 )
{
if ( V_3 >= F_2 ( V_19 ) )
return - V_5 ;
return 0 ;
}
static const char * F_15 ( struct V_1 * V_2 ,
unsigned V_3 )
{
return V_19 [ V_3 ] . V_6 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned V_3 ,
const char * const * * V_34 ,
unsigned * const V_35 )
{
* V_34 = V_19 [ V_3 ] . V_34 ;
* V_35 = V_19 [ V_3 ] . V_35 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_33 ,
struct V_36 * V_37 , unsigned V_11 )
{
struct V_13 * V_14 ;
int V_27 = V_37 -> V_38 ;
T_1 V_25 ;
V_14 = F_12 ( V_33 ) ;
V_25 = F_8 ( V_14 -> V_26 + F_9 ( V_27 ) ) ;
V_25 = V_25 | ( 1 << ( V_11 - V_37 -> V_39 ) ) ;
F_10 ( V_25 , V_14 -> V_26 + F_9 ( V_27 ) ) ;
return 0 ;
}
static void T_2 * F_18 ( void )
{
const struct V_40 V_41 [] = {
{ . V_42 = L_2 } ,
{}
} ;
struct V_43 * V_44 ;
V_44 = F_19 ( NULL , V_41 ) ;
if ( ! V_44 )
F_20 ( L_3 ) ;
return F_21 ( V_44 , 0 ) ;
}
static int T_3 F_22 ( struct V_45 * V_46 )
{
int V_47 ;
struct V_13 * V_14 ;
struct V_43 * V_44 = V_46 -> V_48 . V_49 ;
int V_16 ;
V_14 = F_23 ( & V_46 -> V_48 , sizeof( * V_14 ) , V_50 ) ;
if ( ! V_14 )
return - V_51 ;
V_14 -> V_48 = & V_46 -> V_48 ;
F_24 ( V_46 , V_14 ) ;
V_14 -> V_26 = F_21 ( V_44 , 0 ) ;
if ( ! V_14 -> V_26 ) {
V_47 = - V_51 ;
F_25 ( & V_46 -> V_48 , L_4 ) ;
goto V_52;
}
V_14 -> V_30 = F_18 () ;
if ( ! V_14 -> V_30 ) {
V_47 = - V_51 ;
F_25 ( & V_46 -> V_48 , L_5 ) ;
goto V_53;
}
V_14 -> V_54 = F_26 ( & V_55 , & V_46 -> V_48 , V_14 ) ;
if ( ! V_14 -> V_54 ) {
F_25 ( & V_46 -> V_48 , L_6 ) ;
V_47 = - V_5 ;
goto V_56;
}
for ( V_16 = 0 ; V_16 < F_2 ( V_57 ) ; V_16 ++ )
F_27 ( V_14 -> V_54 , & V_57 [ V_16 ] ) ;
F_28 ( & V_46 -> V_48 , L_7 ) ;
return 0 ;
V_56:
F_29 ( V_14 -> V_30 ) ;
V_53:
F_29 ( V_14 -> V_26 ) ;
V_52:
F_24 ( V_46 , NULL ) ;
F_30 ( & V_46 -> V_48 , V_14 ) ;
return V_47 ;
}
static int T_4 F_31 ( void )
{
return F_32 ( & V_58 ) ;
}
