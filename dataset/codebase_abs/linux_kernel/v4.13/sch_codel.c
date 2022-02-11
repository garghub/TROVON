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
F_6 ( V_7 ) ;
F_7 ( V_6 ) ;
}
static struct V_1 * F_8 ( struct V_5 * V_6 )
{
struct V_12 * V_8 = F_9 ( V_6 ) ;
struct V_1 * V_7 ;
V_7 = F_10 ( V_6 , & V_6 -> V_9 . V_10 , & V_8 -> V_13 , & V_8 -> V_3 ,
& V_8 -> V_14 , F_3 , V_15 ,
F_5 , F_1 ) ;
if ( V_8 -> V_14 . V_16 && V_6 -> V_8 . V_17 ) {
F_11 ( V_6 , V_8 -> V_14 . V_16 , V_8 -> V_14 . V_18 ) ;
V_8 -> V_14 . V_16 = 0 ;
V_8 -> V_14 . V_18 = 0 ;
}
if ( V_7 )
F_12 ( V_6 , V_7 ) ;
return V_7 ;
}
static int F_13 ( struct V_1 * V_7 , struct V_5 * V_6 ,
struct V_1 * * V_19 )
{
struct V_12 * V_8 ;
if ( F_14 ( F_15 ( V_6 ) < V_6 -> V_20 ) ) {
F_16 ( V_7 ) ;
return F_17 ( V_7 , V_6 ) ;
}
V_8 = F_9 ( V_6 ) ;
V_8 -> V_21 ++ ;
return F_18 ( V_7 , V_6 , V_19 ) ;
}
static int F_19 ( struct V_5 * V_6 , struct V_22 * V_23 )
{
struct V_12 * V_8 = F_9 ( V_6 ) ;
struct V_22 * V_24 [ V_25 + 1 ] ;
unsigned int V_17 , V_26 = 0 ;
int V_27 ;
if ( ! V_23 )
return - V_28 ;
V_27 = F_20 ( V_24 , V_25 , V_23 , V_29 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
F_21 ( V_6 ) ;
if ( V_24 [ V_30 ] ) {
T_1 V_31 = F_22 ( V_24 [ V_30 ] ) ;
V_8 -> V_13 . V_31 = ( ( V_32 ) V_31 * V_33 ) >> V_34 ;
}
if ( V_24 [ V_35 ] ) {
V_32 V_36 = F_22 ( V_24 [ V_35 ] ) ;
V_8 -> V_13 . V_37 = ( V_36 * V_33 ) >> V_34 ;
}
if ( V_24 [ V_38 ] ) {
T_1 V_39 = F_22 ( V_24 [ V_38 ] ) ;
V_8 -> V_13 . V_39 = ( ( V_32 ) V_39 * V_33 ) >> V_34 ;
}
if ( V_24 [ V_40 ] )
V_6 -> V_20 = F_22 ( V_24 [ V_40 ] ) ;
if ( V_24 [ V_41 ] )
V_8 -> V_13 . V_42 = ! ! F_22 ( V_24 [ V_41 ] ) ;
V_17 = V_6 -> V_8 . V_17 ;
while ( V_6 -> V_8 . V_17 > V_6 -> V_20 ) {
struct V_1 * V_7 = F_2 ( & V_6 -> V_8 ) ;
V_26 += F_3 ( V_7 ) ;
F_23 ( V_6 , V_7 ) ;
F_24 ( V_7 , V_6 ) ;
}
F_11 ( V_6 , V_17 - V_6 -> V_8 . V_17 , V_26 ) ;
F_25 ( V_6 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 , struct V_22 * V_23 )
{
struct V_12 * V_8 = F_9 ( V_6 ) ;
V_6 -> V_20 = V_43 ;
F_27 ( & V_8 -> V_13 ) ;
F_28 ( & V_8 -> V_3 ) ;
F_29 ( & V_8 -> V_14 ) ;
V_8 -> V_13 . V_44 = F_30 ( F_31 ( V_6 ) ) ;
if ( V_23 ) {
int V_27 = F_19 ( V_6 , V_23 ) ;
if ( V_27 )
return V_27 ;
}
if ( V_6 -> V_20 >= 1 )
V_6 -> V_45 |= V_46 ;
else
V_6 -> V_45 &= ~ V_46 ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_12 * V_8 = F_9 ( V_6 ) ;
struct V_22 * V_47 ;
V_47 = F_33 ( V_7 , V_48 ) ;
if ( V_47 == NULL )
goto V_49;
if ( F_34 ( V_7 , V_30 ,
F_35 ( V_8 -> V_13 . V_31 ) ) ||
F_34 ( V_7 , V_40 ,
V_6 -> V_20 ) ||
F_34 ( V_7 , V_38 ,
F_35 ( V_8 -> V_13 . V_39 ) ) ||
F_34 ( V_7 , V_41 ,
V_8 -> V_13 . V_42 ) )
goto V_49;
if ( V_8 -> V_13 . V_37 != V_50 &&
F_34 ( V_7 , V_35 ,
F_35 ( V_8 -> V_13 . V_37 ) ) )
goto V_49;
return F_36 ( V_7 , V_47 ) ;
V_49:
F_37 ( V_7 , V_47 ) ;
return - 1 ;
}
static int F_38 ( struct V_5 * V_6 , struct V_51 * V_52 )
{
const struct V_12 * V_8 = F_9 ( V_6 ) ;
struct V_53 V_54 = {
. V_55 = V_8 -> V_14 . V_55 ,
. V_56 = V_8 -> V_3 . V_56 ,
. V_57 = V_8 -> V_3 . V_57 ,
. V_21 = V_8 -> V_21 ,
. V_58 = F_35 ( V_8 -> V_3 . V_58 ) ,
. V_59 = V_8 -> V_3 . V_59 ,
. V_60 = V_8 -> V_14 . V_60 ,
. V_61 = V_8 -> V_14 . V_61 ,
} ;
if ( V_8 -> V_3 . V_59 ) {
T_2 V_62 = V_8 -> V_3 . V_63 - F_39 () ;
if ( V_62 >= 0 )
V_54 . V_63 = F_35 ( V_62 ) ;
else
V_54 . V_63 = - F_35 ( - V_62 ) ;
}
return F_40 ( V_52 , & V_54 , sizeof( V_54 ) ) ;
}
static void F_41 ( struct V_5 * V_6 )
{
struct V_12 * V_8 = F_9 ( V_6 ) ;
F_42 ( V_6 ) ;
F_28 ( & V_8 -> V_3 ) ;
}
static int T_3 F_43 ( void )
{
return F_44 ( & V_64 ) ;
}
static void T_4 F_45 ( void )
{
F_46 ( & V_64 ) ;
}
