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
int V_33 ;
if ( V_23 != V_34 )
return - V_17 ;
V_33 = F_9 ( V_27 , V_28 , V_22 ,
V_35 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( ! V_27 [ V_36 ] )
return - V_17 ;
V_30 = F_10 ( V_29 ) ;
if ( ! V_30 )
return - V_37 ;
V_30 -> V_38 = V_29 ;
V_26 = F_1 ( V_30 ) ;
V_26 -> V_39 = ( V_40 V_41 ) F_11 ( V_27 [ V_36 ] ) ;
if ( V_32 -> V_42 > sizeof( V_41 ) ) {
V_26 -> V_43 = * ( V_41 * ) & V_32 -> V_44 ;
V_26 -> V_45 = F_12 (
( V_46 * ) & V_26 -> V_43 , ( V_46 * ) & V_26 -> V_39 ) ;
}
V_30 -> type = V_47 ;
V_30 -> V_48 |= V_49 |
V_50 ;
* V_25 = V_30 ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 ,
struct V_2 * V_15 )
{
struct V_1 * V_26 = F_1 ( V_15 ) ;
if ( F_14 ( V_9 , V_36 , ( V_40 V_51 ) V_26 -> V_39 ) )
goto V_52;
return 0 ;
V_52:
return - V_53 ;
}
static int F_15 ( struct V_2 * V_15 )
{
return 0 ;
}
static int F_16 ( struct V_2 * V_54 , struct V_2 * V_55 )
{
struct V_1 * V_56 = F_1 ( V_54 ) ;
struct V_1 * V_57 = F_1 ( V_55 ) ;
return ( V_56 -> V_39 != V_57 -> V_39 ) ;
}
int F_17 ( void )
{
return F_18 ( & V_58 , V_47 ) ;
}
void F_19 ( void )
{
F_20 ( & V_58 , V_47 ) ;
}
