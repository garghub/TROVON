static inline T_1 * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_5 * V_9 = V_8 -> V_9 ;
return F_5 ( ( T_1 * ) ( V_4 + 1 ) + F_6 ( V_9 ) ,
F_7 ( V_6 ) + 1 ) ;
}
static int F_8 ( struct V_5 * V_10 , const T_1 * V_11 ,
unsigned int V_12 )
{
struct V_7 * V_8 = F_4 ( V_10 ) ;
struct V_5 * V_9 = V_8 -> V_9 ;
int V_13 ;
F_9 ( V_9 , V_14 ) ;
F_10 ( V_9 , F_11 ( V_10 ) &
V_14 ) ;
V_13 = F_12 ( V_9 , V_11 , V_12 ) ;
F_10 ( V_10 , F_11 ( V_9 ) &
V_15 ) ;
return V_13 ;
}
static void F_13 ( struct V_16 * V_17 , int V_13 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
if ( V_13 == - V_19 )
return;
F_14 ( V_2 , V_13 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_1 * V_20 = & V_4 -> V_20 ;
int V_21 = F_16 ( V_6 ) ;
T_1 V_22 [ V_21 * 2 ] V_23 ( F_17 ( V_24 ) ) ;
struct V_25 * V_26 ;
unsigned int V_27 ;
int V_28 ;
V_27 = V_4 -> V_27 ;
V_28 = V_2 -> V_29 - V_27 ;
V_26 = F_18 ( V_4 -> V_26 , V_2 -> V_30 , V_27 - V_21 ) ;
F_19 ( V_22 + V_21 , V_26 , 0 , V_21 , 0 ) ;
memset ( V_22 , 0 , V_21 ) ;
F_19 ( V_22 , V_2 -> V_31 , V_27 , V_28 , 0 ) ;
F_19 ( V_22 , V_26 , 0 , V_21 + V_28 , 1 ) ;
F_20 ( V_22 , sizeof( V_22 ) ) ;
F_21 ( V_20 , V_2 -> V_32 . V_33 &
V_34 ,
F_13 , V_2 ) ;
F_22 ( V_20 , V_26 , V_26 , V_21 , V_2 -> V_35 ) ;
return F_23 ( V_20 ) ;
}
static void F_24 ( struct V_16 * V_17 , int V_13 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
if ( V_13 )
goto V_36;
V_13 = F_15 ( V_2 ) ;
if ( V_13 == - V_19 ||
( V_13 == - V_37 && V_2 -> V_32 . V_33 & V_34 ) )
return;
V_36:
F_14 ( V_2 , V_13 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_1 * V_20 = & V_4 -> V_20 ;
int V_21 = F_16 ( V_6 ) ;
unsigned int V_38 = V_2 -> V_29 ;
int V_39 = ( V_38 + V_21 - 1 ) / V_21 - 1 ;
unsigned int V_27 ;
F_26 ( V_20 , V_8 -> V_9 ) ;
if ( V_39 <= 0 ) {
F_21 ( V_20 , V_2 -> V_32 . V_33 ,
V_2 -> V_32 . V_40 ,
V_2 -> V_32 . V_18 ) ;
F_22 ( V_20 , V_2 -> V_31 , V_2 -> V_30 , V_38 ,
V_2 -> V_35 ) ;
return F_23 ( V_20 ) ;
}
V_27 = V_39 * V_21 ;
V_4 -> V_27 = V_27 ;
F_21 ( V_20 , V_2 -> V_32 . V_33 ,
F_24 , V_2 ) ;
F_22 ( V_20 , V_2 -> V_31 , V_2 -> V_30 ,
V_27 , V_2 -> V_35 ) ;
return F_23 ( V_20 ) ? :
F_15 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_1 * V_20 = & V_4 -> V_20 ;
int V_21 = F_16 ( V_6 ) ;
T_1 V_22 [ V_21 * 2 ] V_23 ( F_17 ( V_24 ) ) ;
struct V_25 * V_26 ;
unsigned int V_27 ;
T_1 * V_41 ;
int V_28 ;
V_27 = V_4 -> V_27 ;
V_28 = V_2 -> V_29 - V_27 ;
V_26 = F_18 ( V_4 -> V_26 , V_2 -> V_30 , V_27 - V_21 ) ;
F_19 ( V_22 + V_21 , V_26 , 0 , V_21 , 0 ) ;
V_41 = F_1 ( V_2 ) ;
F_28 ( V_22 + V_21 , V_41 , V_21 ) ;
memset ( V_22 , 0 , V_21 ) ;
F_19 ( V_22 , V_2 -> V_31 , V_27 , V_28 , 0 ) ;
F_28 ( V_22 + V_21 , V_22 , V_28 ) ;
memcpy ( V_22 + V_28 , V_22 + V_21 + V_28 , V_21 - V_28 ) ;
F_19 ( V_22 , V_26 , 0 , V_21 + V_28 , 1 ) ;
F_20 ( V_22 , sizeof( V_22 ) ) ;
F_21 ( V_20 , V_2 -> V_32 . V_33 &
V_34 ,
F_13 , V_2 ) ;
F_22 ( V_20 , V_26 , V_26 , V_21 , V_41 ) ;
return F_29 ( V_20 ) ;
}
static void F_30 ( struct V_16 * V_17 , int V_13 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
if ( V_13 )
goto V_36;
V_13 = F_27 ( V_2 ) ;
if ( V_13 == - V_19 ||
( V_13 == - V_37 && V_2 -> V_32 . V_33 & V_34 ) )
return;
V_36:
F_14 ( V_2 , V_13 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_1 * V_20 = & V_4 -> V_20 ;
int V_21 = F_16 ( V_6 ) ;
unsigned int V_38 = V_2 -> V_29 ;
int V_39 = ( V_38 + V_21 - 1 ) / V_21 - 1 ;
unsigned int V_27 ;
T_1 * V_41 ;
F_26 ( V_20 , V_8 -> V_9 ) ;
if ( V_39 <= 0 ) {
F_21 ( V_20 , V_2 -> V_32 . V_33 ,
V_2 -> V_32 . V_40 ,
V_2 -> V_32 . V_18 ) ;
F_22 ( V_20 , V_2 -> V_31 , V_2 -> V_30 , V_38 ,
V_2 -> V_35 ) ;
return F_29 ( V_20 ) ;
}
F_21 ( V_20 , V_2 -> V_32 . V_33 ,
F_30 , V_2 ) ;
V_41 = F_1 ( V_2 ) ;
V_27 = V_39 * V_21 ;
V_4 -> V_27 = V_27 ;
if ( V_39 <= 1 )
memcpy ( V_41 , V_2 -> V_35 , V_21 ) ;
else
F_19 ( V_41 , V_2 -> V_31 , V_27 - 2 * V_21 ,
V_21 , 0 ) ;
F_22 ( V_20 , V_2 -> V_31 , V_2 -> V_30 ,
V_27 , V_2 -> V_35 ) ;
return F_29 ( V_20 ) ? :
F_27 ( V_2 ) ;
}
static int F_32 ( struct V_5 * V_6 )
{
struct V_42 * V_43 = F_33 ( V_6 ) ;
struct V_44 * V_45 = F_34 ( V_43 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_5 * V_46 ;
unsigned V_47 ;
unsigned V_21 ;
unsigned V_48 ;
V_46 = F_35 ( V_45 ) ;
if ( F_36 ( V_46 ) )
return F_37 ( V_46 ) ;
V_8 -> V_9 = V_46 ;
V_48 = F_7 ( V_6 ) ;
V_21 = F_16 ( V_46 ) ;
V_47 = F_38 ( sizeof( struct V_3 ) +
F_6 ( V_46 ) ,
F_39 () ) +
( V_48 & ~ ( F_39 () - 1 ) ) + V_21 ;
F_40 ( V_6 , V_47 ) ;
return 0 ;
}
static void F_41 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
F_42 ( V_8 -> V_9 ) ;
}
static void F_43 ( struct V_42 * V_43 )
{
F_44 ( F_34 ( V_43 ) ) ;
F_45 ( V_43 ) ;
}
static int F_46 ( struct V_49 * V_50 , struct V_51 * * V_52 )
{
struct V_44 * V_45 ;
struct V_42 * V_43 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
const char * V_57 ;
int V_13 ;
V_54 = F_47 ( V_52 ) ;
if ( F_36 ( V_54 ) )
return F_37 ( V_54 ) ;
if ( ( V_54 -> type ^ V_58 ) & V_54 -> V_59 )
return - V_60 ;
V_57 = F_48 ( V_52 [ 1 ] ) ;
if ( F_36 ( V_57 ) )
return F_37 ( V_57 ) ;
V_43 = F_49 ( sizeof( * V_43 ) + sizeof( * V_45 ) , V_61 ) ;
if ( ! V_43 )
return - V_62 ;
V_45 = F_34 ( V_43 ) ;
F_50 ( V_45 , F_51 ( V_43 ) ) ;
V_13 = F_52 ( V_45 , V_57 , 0 ,
F_53 ( V_54 -> type ,
V_54 -> V_59 ) ) ;
if ( V_13 )
goto V_63;
V_56 = F_54 ( V_45 ) ;
V_13 = - V_60 ;
if ( F_55 ( V_56 ) != V_56 -> V_32 . V_64 )
goto V_65;
if ( strncmp ( V_56 -> V_32 . V_66 , L_1 , 4 ) )
goto V_65;
V_13 = F_56 ( F_51 ( V_43 ) , L_2 ,
& V_56 -> V_32 ) ;
if ( V_13 )
goto V_65;
V_43 -> V_56 . V_32 . V_67 = V_56 -> V_32 . V_67 & V_68 ;
V_43 -> V_56 . V_32 . V_69 = V_56 -> V_32 . V_69 ;
V_43 -> V_56 . V_32 . V_64 = V_56 -> V_32 . V_64 ;
V_43 -> V_56 . V_32 . V_70 = V_56 -> V_32 . V_70 ;
V_43 -> V_56 . V_71 = V_56 -> V_32 . V_64 ;
V_43 -> V_56 . V_72 = F_57 ( V_56 ) ;
V_43 -> V_56 . V_73 = F_58 ( V_56 ) ;
V_43 -> V_56 . V_74 = F_59 ( V_56 ) ;
V_43 -> V_56 . V_32 . V_75 = sizeof( struct V_7 ) ;
V_43 -> V_56 . V_76 = F_32 ;
V_43 -> V_56 . exit = F_41 ;
V_43 -> V_56 . V_77 = F_8 ;
V_43 -> V_56 . V_78 = F_25 ;
V_43 -> V_56 . V_79 = F_31 ;
V_43 -> free = F_43 ;
V_13 = F_60 ( V_50 , V_43 ) ;
if ( V_13 )
goto V_65;
V_36:
return V_13 ;
V_65:
F_44 ( V_45 ) ;
V_63:
F_45 ( V_43 ) ;
goto V_36;
}
static int T_2 F_61 ( void )
{
return F_62 ( & V_80 ) ;
}
static void T_3 F_63 ( void )
{
F_64 ( & V_80 ) ;
}
