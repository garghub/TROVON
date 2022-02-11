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
T_1 V_16 , V_17 , V_18 ;
int V_19 ;
const struct V_20 * V_21 ;
V_21 = V_22 [ V_3 ] . V_18 ;
for ( V_19 = 0 ; V_19 < F_2 ( V_23 ) ; V_19 ++ ) {
if ( V_15 )
V_17 = V_21 -> V_24 ;
else
V_17 = 0 ;
V_18 = V_21 -> V_18 ;
if ( V_18 != 0 ) {
V_16 = F_8 ( V_14 -> V_25 + V_23 [ V_19 ] ) ;
V_16 &= ~ V_18 ;
V_16 |= V_17 ;
F_9 ( V_16 , V_14 -> V_25 + V_23 [ V_19 ] ) ;
}
V_21 ++ ;
}
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_26 )
{
struct V_13 * V_14 ;
if ( V_3 == 0 )
return 0 ;
V_14 = F_11 ( V_2 ) ;
F_7 ( V_14 , V_3 , true ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_26 )
{
struct V_13 * V_14 ;
if ( V_3 == 0 )
return;
V_14 = F_11 ( V_2 ) ;
F_7 ( V_14 , V_3 , false ) ;
}
static int F_13 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( V_3 >= F_2 ( V_22 ) )
return - V_5 ;
return 0 ;
}
static const char * F_14 ( struct V_1 * V_2 ,
unsigned V_3 )
{
return V_22 [ V_3 ] . V_6 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_3 ,
const char * const * * V_27 ,
unsigned * const V_28 )
{
* V_27 = V_22 [ V_3 ] . V_27 ;
* V_28 = V_22 [ V_3 ] . V_28 ;
return 0 ;
}
static int T_2 F_16 ( struct V_29 * V_30 )
{
struct V_13 * V_14 ;
struct V_31 * V_32 ;
int V_33 ;
int V_19 ;
V_14 = F_17 ( & V_30 -> V_34 , sizeof( * V_14 ) , V_35 ) ;
if ( ! V_14 )
return - V_36 ;
V_14 -> V_34 = & V_30 -> V_34 ;
V_32 = F_18 ( V_30 , V_37 , 0 ) ;
if ( ! V_32 ) {
V_33 = - V_38 ;
goto V_39;
}
V_14 -> V_40 = V_32 -> V_41 ;
V_14 -> V_42 = F_19 ( V_32 ) ;
if ( F_20 ( V_14 -> V_40 , V_14 -> V_42 ,
V_12 ) == NULL ) {
V_33 = - V_36 ;
goto V_43;
}
V_14 -> V_25 = F_21 ( V_14 -> V_40 , V_14 -> V_42 ) ;
if ( ! V_14 -> V_25 ) {
V_33 = - V_36 ;
goto V_44;
}
V_14 -> V_45 = F_22 ( & V_46 , & V_30 -> V_34 , V_14 ) ;
if ( ! V_14 -> V_45 ) {
F_23 ( & V_30 -> V_34 , L_2 ) ;
V_33 = - V_5 ;
goto V_47;
}
for ( V_19 = 0 ; V_19 < F_2 ( V_48 ) ; V_19 ++ )
F_24 ( V_14 -> V_45 , & V_48 [ V_19 ] ) ;
F_25 ( V_30 , V_14 ) ;
F_26 ( & V_30 -> V_34 , L_3 ) ;
return 0 ;
V_47:
F_27 ( V_14 -> V_25 ) ;
V_44:
F_25 ( V_30 , NULL ) ;
V_43:
F_28 ( V_14 -> V_40 , V_14 -> V_42 ) ;
V_39:
F_29 ( & V_30 -> V_34 , V_14 ) ;
return V_33 ;
}
static int T_3 F_30 ( struct V_29 * V_30 )
{
struct V_13 * V_14 = F_31 ( V_30 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_2 ( V_48 ) ; V_19 ++ )
F_32 ( V_14 -> V_45 , & V_48 [ V_19 ] ) ;
F_33 ( V_14 -> V_45 ) ;
F_27 ( V_14 -> V_25 ) ;
F_28 ( V_14 -> V_40 , V_14 -> V_42 ) ;
F_25 ( V_30 , NULL ) ;
F_29 ( & V_30 -> V_34 , V_14 ) ;
return 0 ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_49 , F_16 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_49 ) ;
}
