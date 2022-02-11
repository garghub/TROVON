static struct V_1 * F_1 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
struct V_1 * V_7 = F_2 ( & V_6 -> V_8 ) ;
if ( V_7 )
V_6 -> V_9 . V_10 -= F_3 ( V_7 ) ;
F_4 ( & V_7 -> V_11 ) ;
return V_7 ;
}
static void F_5 ( struct V_1 * V_7 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
F_6 ( V_7 , V_6 ) ;
}
static struct V_1 * F_7 ( struct V_5 * V_6 )
{
struct V_12 * V_8 = F_8 ( V_6 ) ;
struct V_1 * V_7 ;
V_7 = F_9 ( V_6 , & V_6 -> V_9 . V_10 , & V_8 -> V_13 , & V_8 -> V_3 ,
& V_8 -> V_14 , F_3 , V_15 ,
F_5 , F_1 ) ;
if ( V_8 -> V_14 . V_16 && V_6 -> V_8 . V_17 ) {
F_10 ( V_6 , V_8 -> V_14 . V_16 , V_8 -> V_14 . V_18 ) ;
V_8 -> V_14 . V_16 = 0 ;
V_8 -> V_14 . V_18 = 0 ;
}
if ( V_7 )
F_11 ( V_6 , V_7 ) ;
return V_7 ;
}
static int F_12 ( struct V_1 * V_7 , struct V_5 * V_6 )
{
struct V_12 * V_8 ;
if ( F_13 ( F_14 ( V_6 ) < V_6 -> V_19 ) ) {
F_15 ( V_7 ) ;
return F_16 ( V_7 , V_6 ) ;
}
V_8 = F_8 ( V_6 ) ;
V_8 -> V_20 ++ ;
return F_6 ( V_7 , V_6 ) ;
}
static int F_17 ( struct V_5 * V_6 , struct V_21 * V_22 )
{
struct V_12 * V_8 = F_8 ( V_6 ) ;
struct V_21 * V_23 [ V_24 + 1 ] ;
unsigned int V_17 , V_25 = 0 ;
int V_26 ;
if ( ! V_22 )
return - V_27 ;
V_26 = F_18 ( V_23 , V_24 , V_22 , V_28 ) ;
if ( V_26 < 0 )
return V_26 ;
F_19 ( V_6 ) ;
if ( V_23 [ V_29 ] ) {
T_1 V_30 = F_20 ( V_23 [ V_29 ] ) ;
V_8 -> V_13 . V_30 = ( ( V_31 ) V_30 * V_32 ) >> V_33 ;
}
if ( V_23 [ V_34 ] ) {
V_31 V_35 = F_20 ( V_23 [ V_34 ] ) ;
V_8 -> V_13 . V_36 = ( V_35 * V_32 ) >> V_33 ;
}
if ( V_23 [ V_37 ] ) {
T_1 V_38 = F_20 ( V_23 [ V_37 ] ) ;
V_8 -> V_13 . V_38 = ( ( V_31 ) V_38 * V_32 ) >> V_33 ;
}
if ( V_23 [ V_39 ] )
V_6 -> V_19 = F_20 ( V_23 [ V_39 ] ) ;
if ( V_23 [ V_40 ] )
V_8 -> V_13 . V_41 = ! ! F_20 ( V_23 [ V_40 ] ) ;
V_17 = V_6 -> V_8 . V_17 ;
while ( V_6 -> V_8 . V_17 > V_6 -> V_19 ) {
struct V_1 * V_7 = F_2 ( & V_6 -> V_8 ) ;
V_25 += F_3 ( V_7 ) ;
F_21 ( V_6 , V_7 ) ;
F_6 ( V_7 , V_6 ) ;
}
F_10 ( V_6 , V_17 - V_6 -> V_8 . V_17 , V_25 ) ;
F_22 ( V_6 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 , struct V_21 * V_22 )
{
struct V_12 * V_8 = F_8 ( V_6 ) ;
V_6 -> V_19 = V_42 ;
F_24 ( & V_8 -> V_13 ) ;
F_25 ( & V_8 -> V_3 ) ;
F_26 ( & V_8 -> V_14 ) ;
V_8 -> V_13 . V_43 = F_27 ( F_28 ( V_6 ) ) ;
if ( V_22 ) {
int V_26 = F_17 ( V_6 , V_22 ) ;
if ( V_26 )
return V_26 ;
}
if ( V_6 -> V_19 >= 1 )
V_6 -> V_44 |= V_45 ;
else
V_6 -> V_44 &= ~ V_45 ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_12 * V_8 = F_8 ( V_6 ) ;
struct V_21 * V_46 ;
V_46 = F_30 ( V_7 , V_47 ) ;
if ( V_46 == NULL )
goto V_48;
if ( F_31 ( V_7 , V_29 ,
F_32 ( V_8 -> V_13 . V_30 ) ) ||
F_31 ( V_7 , V_39 ,
V_6 -> V_19 ) ||
F_31 ( V_7 , V_37 ,
F_32 ( V_8 -> V_13 . V_38 ) ) ||
F_31 ( V_7 , V_40 ,
V_8 -> V_13 . V_41 ) )
goto V_48;
if ( V_8 -> V_13 . V_36 != V_49 &&
F_31 ( V_7 , V_34 ,
F_32 ( V_8 -> V_13 . V_36 ) ) )
goto V_48;
return F_33 ( V_7 , V_46 ) ;
V_48:
F_34 ( V_7 , V_46 ) ;
return - 1 ;
}
static int F_35 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
const struct V_12 * V_8 = F_8 ( V_6 ) ;
struct V_52 V_53 = {
. V_54 = V_8 -> V_14 . V_54 ,
. V_55 = V_8 -> V_3 . V_55 ,
. V_56 = V_8 -> V_3 . V_56 ,
. V_20 = V_8 -> V_20 ,
. V_57 = F_32 ( V_8 -> V_3 . V_57 ) ,
. V_58 = V_8 -> V_3 . V_58 ,
. V_59 = V_8 -> V_14 . V_59 ,
. V_60 = V_8 -> V_14 . V_60 ,
} ;
if ( V_8 -> V_3 . V_58 ) {
T_2 V_61 = V_8 -> V_3 . V_62 - F_36 () ;
if ( V_61 >= 0 )
V_53 . V_62 = F_32 ( V_61 ) ;
else
V_53 . V_62 = - F_32 ( - V_61 ) ;
}
return F_37 ( V_51 , & V_53 , sizeof( V_53 ) ) ;
}
static void F_38 ( struct V_5 * V_6 )
{
struct V_12 * V_8 = F_8 ( V_6 ) ;
F_39 ( V_6 ) ;
F_25 ( & V_8 -> V_3 ) ;
}
static int T_3 F_40 ( void )
{
return F_41 ( & V_63 ) ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_63 ) ;
}
