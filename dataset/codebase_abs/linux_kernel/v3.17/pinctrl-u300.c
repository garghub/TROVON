static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 ) ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_3 [ V_4 ] . V_5 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_4 ,
const unsigned * * V_6 ,
unsigned * V_7 )
{
* V_6 = V_3 [ V_4 ] . V_6 ;
* V_7 = V_3 [ V_4 ] . V_7 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_8 * V_9 ,
unsigned V_10 )
{
F_6 ( V_9 , L_1 V_11 ) ;
}
static void F_7 ( struct V_12 * V_13 , unsigned V_4 ,
bool V_14 )
{
T_1 V_15 , V_16 , V_17 ;
int V_18 ;
const struct V_19 * V_20 ;
V_20 = V_21 [ V_4 ] . V_17 ;
for ( V_18 = 0 ; V_18 < F_2 ( V_22 ) ; V_18 ++ ) {
if ( V_14 )
V_16 = V_20 -> V_23 ;
else
V_16 = 0 ;
V_17 = V_20 -> V_17 ;
if ( V_17 != 0 ) {
V_15 = F_8 ( V_13 -> V_24 + V_22 [ V_18 ] ) ;
V_15 &= ~ V_17 ;
V_15 |= V_16 ;
F_9 ( V_15 , V_13 -> V_24 + V_22 [ V_18 ] ) ;
}
V_20 ++ ;
}
}
static int F_10 ( struct V_1 * V_2 , unsigned V_4 ,
unsigned V_25 )
{
struct V_12 * V_13 ;
if ( V_4 == 0 )
return 0 ;
V_13 = F_11 ( V_2 ) ;
F_7 ( V_13 , V_4 , true ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_2 ( V_21 ) ;
}
static const char * F_13 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_21 [ V_4 ] . V_5 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned V_4 ,
const char * const * * V_26 ,
unsigned * const V_27 )
{
* V_26 = V_21 [ V_4 ] . V_26 ;
* V_27 = V_21 [ V_4 ] . V_27 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_28 ,
unsigned long * V_29 )
{
struct V_30 * V_31 =
F_16 ( V_2 , V_28 ) ;
if ( ! V_31 )
return - V_32 ;
return F_17 ( V_31 -> V_33 ,
( V_28 - V_31 -> V_34 + V_31 -> V_35 ) ,
V_29 ) ;
}
static int F_18 ( struct V_1 * V_2 , unsigned V_28 ,
unsigned long * V_36 , unsigned V_37 )
{
struct V_30 * V_31 =
F_16 ( V_2 , V_28 ) ;
int V_38 , V_18 ;
if ( ! V_31 )
return - V_39 ;
for ( V_18 = 0 ; V_18 < V_37 ; V_18 ++ ) {
V_38 = F_19 ( V_31 -> V_33 ,
( V_28 - V_31 -> V_34 + V_31 -> V_35 ) ,
F_20 ( V_36 [ V_18 ] ) ) ;
if ( V_38 )
return V_38 ;
}
return 0 ;
}
static int F_21 ( struct V_40 * V_41 )
{
struct V_12 * V_13 ;
struct V_42 * V_43 ;
V_13 = F_22 ( & V_41 -> V_44 , sizeof( * V_13 ) , V_45 ) ;
if ( ! V_13 )
return - V_46 ;
V_13 -> V_44 = & V_41 -> V_44 ;
V_43 = F_23 ( V_41 , V_47 , 0 ) ;
V_13 -> V_24 = F_24 ( & V_41 -> V_44 , V_43 ) ;
if ( F_25 ( V_13 -> V_24 ) )
return F_26 ( V_13 -> V_24 ) ;
V_13 -> V_48 = F_27 ( & V_49 , & V_41 -> V_44 , V_13 ) ;
if ( ! V_13 -> V_48 ) {
F_28 ( & V_41 -> V_44 , L_2 ) ;
return - V_39 ;
}
F_29 ( V_41 , V_13 ) ;
F_30 ( & V_41 -> V_44 , L_3 ) ;
return 0 ;
}
static int F_31 ( struct V_40 * V_41 )
{
struct V_12 * V_13 = F_32 ( V_41 ) ;
F_33 ( V_13 -> V_48 ) ;
return 0 ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_50 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_50 ) ;
}
