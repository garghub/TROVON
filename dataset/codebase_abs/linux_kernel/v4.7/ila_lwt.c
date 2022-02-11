static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static int F_2 ( struct V_5 * V_5 , struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_10 * V_11 = F_3 ( V_9 ) ;
if ( V_9 -> V_12 != F_4 ( V_13 ) )
goto V_14;
F_5 ( V_9 , F_1 ( V_11 -> V_15 ) ) ;
return V_11 -> V_15 -> V_16 ( V_5 , V_7 , V_9 ) ;
V_14:
F_6 ( V_9 ) ;
return - V_17 ;
}
static int F_7 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_3 ( V_9 ) ;
if ( V_9 -> V_12 != F_4 ( V_13 ) )
goto V_14;
F_5 ( V_9 , F_1 ( V_11 -> V_15 ) ) ;
return V_11 -> V_15 -> V_18 ( V_9 ) ;
V_14:
F_6 ( V_9 ) ;
return - V_17 ;
}
static int F_8 ( struct V_19 * V_20 , struct V_21 * V_22 ,
unsigned int V_23 , const void * V_24 ,
struct V_2 * * V_25 )
{
struct V_1 * V_26 ;
struct V_21 * V_27 [ V_28 + 1 ] ;
T_1 V_29 = sizeof( * V_26 ) ;
struct V_2 * V_30 ;
const struct V_31 * V_32 = V_24 ;
struct V_33 * V_34 ;
int V_35 ;
if ( V_23 != V_36 )
return - V_17 ;
if ( V_32 -> V_37 < sizeof( struct V_38 ) + 1 ) {
return - V_17 ;
}
V_34 = (struct V_33 * ) & V_32 -> V_39 ;
if ( ! F_9 ( V_34 ) || F_10 ( V_34 -> V_40 ) ) {
return - V_17 ;
}
V_35 = F_11 ( V_27 , V_28 , V_22 ,
V_41 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( ! V_27 [ V_42 ] )
return - V_17 ;
V_30 = F_12 ( V_29 ) ;
if ( ! V_30 )
return - V_43 ;
V_30 -> V_44 = V_29 ;
V_26 = F_1 ( V_30 ) ;
V_26 -> V_45 . V_46 = ( V_47 V_48 ) F_13 ( V_27 [ V_42 ] ) ;
V_26 -> V_49 = V_34 -> V_50 ;
V_26 -> V_51 = F_14 (
( V_52 * ) & V_26 -> V_49 , ( V_52 * ) & V_26 -> V_45 ) ;
if ( V_27 [ V_53 ] )
V_26 -> V_54 = F_15 ( V_27 [ V_53 ] ) ;
F_16 ( V_26 ) ;
V_30 -> type = V_55 ;
V_30 -> V_56 |= V_57 |
V_58 ;
* V_25 = V_30 ;
return 0 ;
}
static int F_17 ( struct V_8 * V_9 ,
struct V_2 * V_15 )
{
struct V_1 * V_26 = F_1 ( V_15 ) ;
if ( F_18 ( V_9 , V_42 , ( V_47 V_59 ) V_26 -> V_45 . V_46 ,
V_60 ) )
goto V_61;
if ( F_19 ( V_9 , V_53 , ( V_47 V_62 ) V_26 -> V_54 ) )
goto V_61;
return 0 ;
V_61:
return - V_63 ;
}
static int F_20 ( struct V_2 * V_15 )
{
return F_21 ( sizeof( V_59 ) ) +
F_22 ( sizeof( V_62 ) ) +
0 ;
}
static int F_23 ( struct V_2 * V_64 , struct V_2 * V_65 )
{
struct V_1 * V_66 = F_1 ( V_64 ) ;
struct V_1 * V_67 = F_1 ( V_65 ) ;
return ( V_66 -> V_45 . V_46 != V_67 -> V_45 . V_46 ) ;
}
int F_24 ( void )
{
return F_25 ( & V_68 , V_55 ) ;
}
void F_26 ( void )
{
F_27 ( & V_68 , V_55 ) ;
}
