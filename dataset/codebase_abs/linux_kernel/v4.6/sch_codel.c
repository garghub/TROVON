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
F_7 ( V_5 , V_7 -> V_11 . V_12 , V_7 -> V_11 . V_14 ) ;
V_7 -> V_11 . V_12 = 0 ;
V_7 -> V_11 . V_14 = 0 ;
}
if ( V_6 )
F_8 ( V_5 , V_6 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_6 , struct V_4 * V_5 )
{
struct V_9 * V_7 ;
if ( F_10 ( F_11 ( V_5 ) < V_5 -> V_15 ) ) {
F_12 ( V_6 ) ;
return F_13 ( V_6 , V_5 ) ;
}
V_7 = F_5 ( V_5 ) ;
V_7 -> V_16 ++ ;
return F_14 ( V_6 , V_5 ) ;
}
static int F_15 ( struct V_4 * V_5 , struct V_17 * V_18 )
{
struct V_9 * V_7 = F_5 ( V_5 ) ;
struct V_17 * V_19 [ V_20 + 1 ] ;
unsigned int V_13 , V_21 = 0 ;
int V_22 ;
if ( ! V_18 )
return - V_23 ;
V_22 = F_16 ( V_19 , V_20 , V_18 , V_24 ) ;
if ( V_22 < 0 )
return V_22 ;
F_17 ( V_5 ) ;
if ( V_19 [ V_25 ] ) {
T_1 V_26 = F_18 ( V_19 [ V_25 ] ) ;
V_7 -> V_10 . V_26 = ( ( V_27 ) V_26 * V_28 ) >> V_29 ;
}
if ( V_19 [ V_30 ] ) {
V_27 V_31 = F_18 ( V_19 [ V_30 ] ) ;
V_7 -> V_10 . V_32 = ( V_31 * V_28 ) >> V_29 ;
}
if ( V_19 [ V_33 ] ) {
T_1 V_34 = F_18 ( V_19 [ V_33 ] ) ;
V_7 -> V_10 . V_34 = ( ( V_27 ) V_34 * V_28 ) >> V_29 ;
}
if ( V_19 [ V_35 ] )
V_5 -> V_15 = F_18 ( V_19 [ V_35 ] ) ;
if ( V_19 [ V_36 ] )
V_7 -> V_10 . V_37 = ! ! F_18 ( V_19 [ V_36 ] ) ;
V_13 = V_5 -> V_7 . V_13 ;
while ( V_5 -> V_7 . V_13 > V_5 -> V_15 ) {
struct V_1 * V_6 = F_2 ( & V_5 -> V_7 ) ;
V_21 += F_19 ( V_6 ) ;
F_20 ( V_5 , V_6 ) ;
F_14 ( V_6 , V_5 ) ;
}
F_7 ( V_5 , V_13 - V_5 -> V_7 . V_13 , V_21 ) ;
F_21 ( V_5 ) ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 , struct V_17 * V_18 )
{
struct V_9 * V_7 = F_5 ( V_5 ) ;
V_5 -> V_15 = V_38 ;
F_23 ( & V_7 -> V_10 , V_5 ) ;
F_24 ( & V_7 -> V_3 ) ;
F_25 ( & V_7 -> V_11 ) ;
if ( V_18 ) {
int V_22 = F_15 ( V_5 , V_18 ) ;
if ( V_22 )
return V_22 ;
}
if ( V_5 -> V_15 >= 1 )
V_5 -> V_39 |= V_40 ;
else
V_5 -> V_39 &= ~ V_40 ;
return 0 ;
}
static int F_26 ( struct V_4 * V_5 , struct V_1 * V_6 )
{
struct V_9 * V_7 = F_5 ( V_5 ) ;
struct V_17 * V_41 ;
V_41 = F_27 ( V_6 , V_42 ) ;
if ( V_41 == NULL )
goto V_43;
if ( F_28 ( V_6 , V_25 ,
F_29 ( V_7 -> V_10 . V_26 ) ) ||
F_28 ( V_6 , V_35 ,
V_5 -> V_15 ) ||
F_28 ( V_6 , V_33 ,
F_29 ( V_7 -> V_10 . V_34 ) ) ||
F_28 ( V_6 , V_36 ,
V_7 -> V_10 . V_37 ) )
goto V_43;
if ( V_7 -> V_10 . V_32 != V_44 &&
F_28 ( V_6 , V_30 ,
F_29 ( V_7 -> V_10 . V_32 ) ) )
goto V_43;
return F_30 ( V_6 , V_41 ) ;
V_43:
F_31 ( V_6 , V_41 ) ;
return - 1 ;
}
static int F_32 ( struct V_4 * V_5 , struct V_45 * V_46 )
{
const struct V_9 * V_7 = F_5 ( V_5 ) ;
struct V_47 V_48 = {
. V_49 = V_7 -> V_11 . V_49 ,
. V_50 = V_7 -> V_3 . V_50 ,
. V_51 = V_7 -> V_3 . V_51 ,
. V_16 = V_7 -> V_16 ,
. V_52 = F_29 ( V_7 -> V_3 . V_52 ) ,
. V_53 = V_7 -> V_3 . V_53 ,
. V_54 = V_7 -> V_11 . V_54 ,
. V_55 = V_7 -> V_11 . V_55 ,
} ;
if ( V_7 -> V_3 . V_53 ) {
T_2 V_56 = V_7 -> V_3 . V_57 - F_33 () ;
if ( V_56 >= 0 )
V_48 . V_57 = F_29 ( V_56 ) ;
else
V_48 . V_57 = - F_29 ( - V_56 ) ;
}
return F_34 ( V_46 , & V_48 , sizeof( V_48 ) ) ;
}
static void F_35 ( struct V_4 * V_5 )
{
struct V_9 * V_7 = F_5 ( V_5 ) ;
F_36 ( V_5 ) ;
F_24 ( & V_7 -> V_3 ) ;
}
static int T_3 F_37 ( void )
{
return F_38 ( & V_58 ) ;
}
static void T_4 F_39 ( void )
{
F_40 ( & V_58 ) ;
}
