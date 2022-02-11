static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = sizeof( struct V_4 ) + V_2 -> V_5 . V_6 ;
int V_7 ;
V_2 -> V_8 = F_2 ( V_3 * V_2 -> V_5 . V_9 ) ;
if ( ! V_2 -> V_8 )
return - V_10 ;
V_7 = F_3 ( & V_2 -> V_11 ) ;
if ( V_7 )
goto V_12;
F_4 ( & V_2 -> V_11 , V_2 -> V_8 , V_3 ,
V_2 -> V_5 . V_9 ) ;
return 0 ;
V_12:
F_5 ( V_2 -> V_8 ) ;
return V_7 ;
}
static struct V_13 * F_6 ( union V_14 * V_15 )
{
T_1 V_6 = V_15 -> V_6 ;
struct V_1 * V_2 ;
T_2 V_16 , V_17 ;
int V_7 ;
if ( ! F_7 ( V_18 ) )
return F_8 ( - V_19 ) ;
if ( V_15 -> V_20 )
return F_8 ( - V_21 ) ;
if ( V_15 -> V_9 == 0 || V_15 -> V_22 != 4 ||
V_6 < 8 || V_6 % 8 ||
V_6 / 8 > V_23 )
return F_8 ( - V_21 ) ;
V_17 = F_9 ( V_15 -> V_9 ) ;
V_16 = V_17 * sizeof( struct V_4 * ) + sizeof( * V_2 ) ;
if ( V_16 >= V_24 - V_25 )
return F_8 ( - V_26 ) ;
V_2 = F_10 ( V_16 , V_27 | V_28 ) ;
if ( ! V_2 ) {
V_2 = F_2 ( V_16 ) ;
if ( ! V_2 )
return F_8 ( - V_10 ) ;
}
V_7 = - V_26 ;
V_16 += V_17 * ( V_6 + sizeof( struct V_4 ) ) ;
if ( V_16 >= V_24 - V_25 )
goto V_29;
V_2 -> V_5 . V_30 = V_15 -> V_30 ;
V_2 -> V_5 . V_22 = V_15 -> V_22 ;
V_2 -> V_5 . V_6 = V_6 ;
V_2 -> V_5 . V_9 = V_15 -> V_9 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_5 . V_31 = F_11 ( V_16 , V_25 ) >> V_32 ;
V_7 = F_12 ( V_2 -> V_5 . V_31 ) ;
if ( V_7 )
goto V_29;
V_7 = F_13 () ;
if ( V_7 )
goto V_29;
V_7 = F_1 ( V_2 ) ;
if ( V_7 )
goto V_33;
return & V_2 -> V_5 ;
V_33:
F_14 () ;
V_29:
F_15 ( V_2 ) ;
return F_8 ( V_7 ) ;
}
T_2 F_16 ( T_2 V_34 , T_2 V_35 , T_2 V_36 , T_2 V_37 , T_2 V_38 )
{
struct V_39 * V_40 = (struct V_39 * ) ( long ) V_34 ;
struct V_13 * V_5 = (struct V_13 * ) ( long ) V_35 ;
struct V_1 * V_2 = F_17 ( V_5 , struct V_1 , V_5 ) ;
struct V_41 * V_42 ;
struct V_4 * V_43 , * V_44 , * V_45 ;
T_1 V_46 = V_5 -> V_6 / 8 ;
T_1 V_47 = V_23 - V_46 ;
T_1 V_48 = V_36 & V_49 ;
T_1 V_50 , V_51 , V_52 , V_53 ;
bool V_54 = V_36 & V_55 ;
bool V_56 = ! V_54 ;
T_2 * V_57 ;
if ( F_18 ( V_36 & ~ ( V_49 | V_55 |
V_58 | V_59 ) ) )
return - V_21 ;
V_42 = F_19 ( V_40 , V_47 , V_56 , V_54 ,
V_23 , false , false ) ;
if ( F_18 ( ! V_42 ) )
return - V_60 ;
V_52 = V_42 -> V_61 - V_47 ;
if ( V_52 <= V_48 )
return - V_60 ;
V_52 -= V_48 ;
V_53 = V_52 * sizeof( T_2 ) ;
V_57 = V_42 -> V_62 + V_48 + V_47 ;
V_50 = F_20 ( ( T_1 * ) V_57 , V_53 / sizeof( T_1 ) , 0 ) ;
V_51 = V_50 & ( V_2 -> V_17 - 1 ) ;
V_43 = F_21 ( V_2 -> V_63 [ V_51 ] ) ;
if ( V_43 && V_43 -> V_50 == V_50 ) {
if ( V_36 & V_58 )
return V_51 ;
if ( V_43 -> V_61 == V_52 &&
memcmp ( V_43 -> V_62 , V_57 , V_53 ) == 0 )
return V_51 ;
}
if ( V_43 && ! ( V_36 & V_59 ) )
return - V_64 ;
V_44 = (struct V_4 * )
F_22 ( & V_2 -> V_11 ) ;
if ( F_18 ( ! V_44 ) )
return - V_10 ;
memcpy ( V_44 -> V_62 , V_57 , V_53 ) ;
V_44 -> V_50 = V_50 ;
V_44 -> V_61 = V_52 ;
V_45 = F_23 ( & V_2 -> V_63 [ V_51 ] , V_44 ) ;
if ( V_45 )
F_24 ( & V_2 -> V_11 , & V_45 -> V_65 ) ;
return V_51 ;
}
static void * F_25 ( struct V_13 * V_5 , void * V_66 )
{
return NULL ;
}
int F_26 ( struct V_13 * V_5 , void * V_66 , void * V_67 )
{
struct V_1 * V_2 = F_17 ( V_5 , struct V_1 , V_5 ) ;
struct V_4 * V_43 , * V_45 ;
T_1 V_51 = * ( T_1 * ) V_66 , V_53 ;
if ( F_18 ( V_51 >= V_2 -> V_17 ) )
return - V_68 ;
V_43 = F_23 ( & V_2 -> V_63 [ V_51 ] , NULL ) ;
if ( ! V_43 )
return - V_68 ;
V_53 = V_43 -> V_61 * sizeof( T_2 ) ;
memcpy ( V_67 , V_43 -> V_62 , V_53 ) ;
memset ( V_67 + V_53 , 0 , V_5 -> V_6 - V_53 ) ;
V_45 = F_23 ( & V_2 -> V_63 [ V_51 ] , V_43 ) ;
if ( V_45 )
F_24 ( & V_2 -> V_11 , & V_45 -> V_65 ) ;
return 0 ;
}
static int F_27 ( struct V_13 * V_5 , void * V_66 , void * V_69 )
{
return - V_21 ;
}
static int F_28 ( struct V_13 * V_5 , void * V_66 , void * V_67 ,
T_2 V_20 )
{
return - V_21 ;
}
static int F_29 ( struct V_13 * V_5 , void * V_66 )
{
struct V_1 * V_2 = F_17 ( V_5 , struct V_1 , V_5 ) ;
struct V_4 * V_45 ;
T_1 V_51 = * ( T_1 * ) V_66 ;
if ( F_18 ( V_51 >= V_2 -> V_17 ) )
return - V_26 ;
V_45 = F_23 ( & V_2 -> V_63 [ V_51 ] , NULL ) ;
if ( V_45 ) {
F_24 ( & V_2 -> V_11 , & V_45 -> V_65 ) ;
return 0 ;
} else {
return - V_68 ;
}
}
static void F_30 ( struct V_13 * V_5 )
{
struct V_1 * V_2 = F_17 ( V_5 , struct V_1 , V_5 ) ;
F_31 () ;
F_5 ( V_2 -> V_8 ) ;
F_32 ( & V_2 -> V_11 ) ;
F_15 ( V_2 ) ;
F_14 () ;
}
static int T_3 F_33 ( void )
{
F_34 ( & V_70 ) ;
return 0 ;
}
