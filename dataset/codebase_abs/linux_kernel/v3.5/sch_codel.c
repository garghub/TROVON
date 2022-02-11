static struct V_1 * F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_2 ( & V_5 -> V_7 ) ;
F_3 ( & V_6 -> V_8 ) ;
return V_6 ;
}
static struct V_1 * F_4 ( struct V_4 * V_5 )
{
struct V_9 * V_7 = F_5 ( V_5 ) ;
struct V_1 * V_6 ;
V_6 = F_6 ( V_5 , & V_7 -> V_10 , & V_7 -> V_3 , & V_7 -> V_11 , F_1 ) ;
if ( V_7 -> V_11 . V_12 && V_5 -> V_7 . V_13 ) {
F_7 ( V_5 , V_7 -> V_11 . V_12 ) ;
V_7 -> V_11 . V_12 = 0 ;
}
if ( V_6 )
F_8 ( V_5 , V_6 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_6 , struct V_4 * V_5 )
{
struct V_9 * V_7 ;
if ( F_10 ( F_11 ( V_5 ) < V_5 -> V_14 ) ) {
F_12 ( V_6 ) ;
return F_13 ( V_6 , V_5 ) ;
}
V_7 = F_5 ( V_5 ) ;
V_7 -> V_15 ++ ;
return F_14 ( V_6 , V_5 ) ;
}
static int F_15 ( struct V_4 * V_5 , struct V_16 * V_17 )
{
struct V_9 * V_7 = F_5 ( V_5 ) ;
struct V_16 * V_18 [ V_19 + 1 ] ;
unsigned int V_13 ;
int V_20 ;
if ( ! V_17 )
return - V_21 ;
V_20 = F_16 ( V_18 , V_19 , V_17 , V_22 ) ;
if ( V_20 < 0 )
return V_20 ;
F_17 ( V_5 ) ;
if ( V_18 [ V_23 ] ) {
T_1 V_24 = F_18 ( V_18 [ V_23 ] ) ;
V_7 -> V_10 . V_24 = ( ( V_25 ) V_24 * V_26 ) >> V_27 ;
}
if ( V_18 [ V_28 ] ) {
T_1 V_29 = F_18 ( V_18 [ V_28 ] ) ;
V_7 -> V_10 . V_29 = ( ( V_25 ) V_29 * V_26 ) >> V_27 ;
}
if ( V_18 [ V_30 ] )
V_5 -> V_14 = F_18 ( V_18 [ V_30 ] ) ;
if ( V_18 [ V_31 ] )
V_7 -> V_10 . V_32 = ! ! F_18 ( V_18 [ V_31 ] ) ;
V_13 = V_5 -> V_7 . V_13 ;
while ( V_5 -> V_7 . V_13 > V_5 -> V_14 ) {
struct V_1 * V_6 = F_2 ( & V_5 -> V_7 ) ;
V_5 -> V_33 . V_34 -= F_19 ( V_6 ) ;
F_14 ( V_6 , V_5 ) ;
}
F_7 ( V_5 , V_13 - V_5 -> V_7 . V_13 ) ;
F_20 ( V_5 ) ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 , struct V_16 * V_17 )
{
struct V_9 * V_7 = F_5 ( V_5 ) ;
V_5 -> V_14 = V_35 ;
F_22 ( & V_7 -> V_10 ) ;
F_23 ( & V_7 -> V_3 ) ;
F_24 ( & V_7 -> V_11 ) ;
if ( V_17 ) {
int V_20 = F_15 ( V_5 , V_17 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_5 -> V_14 >= 1 )
V_5 -> V_36 |= V_37 ;
else
V_5 -> V_36 &= ~ V_37 ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 , struct V_1 * V_6 )
{
struct V_9 * V_7 = F_5 ( V_5 ) ;
struct V_16 * V_38 ;
V_38 = F_26 ( V_6 , V_39 ) ;
if ( V_38 == NULL )
goto V_40;
if ( F_27 ( V_6 , V_23 ,
F_28 ( V_7 -> V_10 . V_24 ) ) ||
F_27 ( V_6 , V_30 ,
V_5 -> V_14 ) ||
F_27 ( V_6 , V_28 ,
F_28 ( V_7 -> V_10 . V_29 ) ) ||
F_27 ( V_6 , V_31 ,
V_7 -> V_10 . V_32 ) )
goto V_40;
return F_29 ( V_6 , V_38 ) ;
V_40:
F_30 ( V_6 , V_38 ) ;
return - 1 ;
}
static int F_31 ( struct V_4 * V_5 , struct V_41 * V_42 )
{
const struct V_9 * V_7 = F_5 ( V_5 ) ;
struct V_43 V_44 = {
. V_45 = V_7 -> V_11 . V_45 ,
. V_46 = V_7 -> V_3 . V_46 ,
. V_47 = V_7 -> V_3 . V_47 ,
. V_15 = V_7 -> V_15 ,
. V_48 = F_28 ( V_7 -> V_3 . V_48 ) ,
. V_49 = V_7 -> V_3 . V_49 ,
. V_50 = V_7 -> V_11 . V_50 ,
} ;
if ( V_7 -> V_3 . V_49 ) {
T_2 V_51 = V_7 -> V_3 . V_52 - F_32 () ;
if ( V_51 >= 0 )
V_44 . V_52 = F_28 ( V_51 ) ;
else
V_44 . V_52 = - F_28 ( - V_51 ) ;
}
return F_33 ( V_42 , & V_44 , sizeof( V_44 ) ) ;
}
static void F_34 ( struct V_4 * V_5 )
{
struct V_9 * V_7 = F_5 ( V_5 ) ;
F_35 ( V_5 ) ;
F_23 ( & V_7 -> V_3 ) ;
}
static int T_3 F_36 ( void )
{
return F_37 ( & V_53 ) ;
}
static void T_4 F_38 ( void )
{
F_39 ( & V_53 ) ;
}
