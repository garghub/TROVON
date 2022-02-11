static struct V_1 * * F_1 ( struct V_1 * * V_2 ,
struct V_1 * V_3 )
{
int V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 V_9 ;
T_1 V_10 ;
int V_11 ;
F_3 ( V_3 , V_4 ) ;
if ( ( V_11 = F_4 ( V_3 , V_12 , & V_10 , & V_9 ) ) != 0 )
goto V_13;
V_6 = V_5 ( V_3 ) ;
if ( ! V_6 || ! ( V_6 -> V_14 & V_15 ) ) {
V_11 = F_5 ( V_3 ) ;
if ( V_11 )
goto V_13;
if ( V_3 -> V_16 -> V_17 == V_18 )
goto V_13;
V_8 = F_6 ( F_7 ( V_3 -> V_19 ) , V_3 -> V_20 ,
( V_21 * ) & F_8 ( V_3 ) -> V_22 ,
V_10 , V_12 , V_23 ) ;
if ( ! V_8 )
goto V_13;
V_3 -> V_16 -> V_24 [ V_3 -> V_16 -> V_17 ++ ] = V_8 ;
V_3 -> V_16 -> V_25 ++ ;
V_6 = V_5 ( V_3 ) ;
if ( ! V_6 ) {
F_9 ( V_8 ) ;
goto V_13;
}
}
V_6 -> V_14 |= V_26 ;
F_10 ( V_3 ) -> V_27 . V_28 = NULL ;
F_11 ( V_3 ) -> V_29 = V_23 ;
F_11 ( V_3 ) -> V_30 = F_12 ( struct V_31 , V_22 ) ;
F_11 ( V_3 ) -> V_9 = V_9 ;
F_13 ( V_3 , V_12 , V_10 , - 2 ) ;
return F_14 ( - V_32 ) ;
V_13:
F_15 ( V_3 , V_4 ) ;
F_16 ( V_3 ) -> V_33 = 0 ;
F_16 ( V_3 ) -> V_34 = 1 ;
return NULL ;
}
static void F_17 ( struct V_7 * V_8 , struct V_1 * V_3 )
{
struct V_35 * V_36 ;
struct V_31 * V_37 = F_8 ( V_3 ) ;
struct V_5 * V_6 = V_5 ( V_3 ) ;
int V_38 = V_37 -> V_39 ;
F_15 ( V_3 , - F_18 ( V_3 ) ) ;
V_36 = V_35 ( V_3 ) ;
* F_19 ( V_3 ) = V_12 ;
V_36 -> V_10 = V_8 -> V_40 . V_10 ;
V_36 -> V_41 = F_20 ( F_21 ( V_3 ) -> V_9 . V_42 . V_43 ) ;
V_6 -> V_38 = V_38 ;
}
static struct V_1 * F_22 ( struct V_1 * V_3 ,
T_2 V_44 )
{
T_3 V_9 ;
int V_11 = 0 ;
struct V_1 * V_45 ;
struct V_7 * V_8 ;
struct V_35 * V_36 ;
struct V_46 * V_47 ;
struct V_1 * V_48 = F_14 ( - V_49 ) ;
T_2 V_50 = V_44 ;
struct V_5 * V_6 = V_5 ( V_3 ) ;
if ( ! V_6 )
goto V_13;
V_9 = V_6 -> V_9 . V_43 ;
V_8 = V_3 -> V_16 -> V_24 [ V_3 -> V_16 -> V_17 - 1 ] ;
V_47 = V_8 -> V_51 ;
V_36 = V_35 ( V_3 ) ;
if ( V_36 -> V_10 != V_8 -> V_40 . V_10 )
goto V_13;
if ( ! F_23 ( V_3 , sizeof( * V_36 ) + F_24 ( V_47 ) ) )
goto V_13;
F_25 ( V_3 , sizeof( * V_36 ) + F_24 ( V_47 ) ) ;
V_3 -> V_52 = 1 ;
if ( ! ( V_44 & V_53 ) )
V_50 = V_44 & ~ ( V_54 | V_55 ) ;
V_48 = V_8 -> V_56 -> V_57 ( V_8 , V_3 , V_50 ) ;
if ( F_26 ( V_48 ) )
goto V_13;
F_25 ( V_3 , V_3 -> V_51 - F_19 ( V_3 ) ) ;
V_45 = V_48 ;
do {
struct V_1 * V_58 = V_45 -> V_59 ;
V_6 = V_5 ( V_45 ) ;
V_6 -> V_14 |= V_60 ;
V_6 -> V_9 . V_43 = V_9 ;
V_6 -> V_9 . V_61 = F_27 ( V_8 , V_9 ) ;
if( ! ( V_44 & V_53 ) )
V_6 -> V_14 |= V_62 ;
V_8 -> V_56 -> V_63 ( V_8 , V_45 ) ;
V_11 = V_8 -> V_64 -> V_63 ( V_8 , V_45 , V_50 ) ;
if ( V_11 ) {
F_28 ( V_48 ) ;
return F_14 ( V_11 ) ;
}
if ( ! F_29 ( V_45 ) )
V_9 ++ ;
else
V_9 += F_30 ( V_45 ) -> V_65 ;
F_15 ( V_45 , V_45 -> V_66 ) ;
V_45 = V_58 ;
} while ( V_45 );
V_13:
return V_48 ;
}
static int F_31 ( struct V_7 * V_8 , struct V_1 * V_3 )
{
struct V_46 * V_47 = V_8 -> V_51 ;
if ( ! F_23 ( V_3 , sizeof( struct V_35 ) + F_24 ( V_47 ) ) )
return - V_49 ;
V_3 -> V_67 = V_68 ;
return F_32 ( V_3 , 0 ) ;
}
static int F_33 ( struct V_7 * V_8 , struct V_1 * V_3 , T_2 V_44 )
{
int V_11 ;
int V_69 ;
int V_70 ;
struct V_5 * V_6 ;
struct V_35 * V_36 ;
struct V_46 * V_47 ;
struct V_71 V_72 ;
bool V_73 = true ;
V_72 . V_74 = true ;
V_6 = V_5 ( V_3 ) ;
if ( ! V_6 )
return - V_49 ;
if ( ! ( V_44 & V_53 ) || ! V_8 -> V_75 . V_76 ||
( V_8 -> V_75 . V_19 != V_3 -> V_19 ) ) {
V_6 -> V_14 |= V_62 ;
V_73 = false ;
}
V_72 . V_38 = V_6 -> V_38 ;
V_47 = V_8 -> V_51 ;
V_69 = F_34 ( V_47 ) ;
V_72 . V_77 = 0 ;
V_70 = F_35 ( F_36 ( V_47 ) , 4 ) ;
V_72 . V_78 = F_35 ( V_3 -> V_17 + 2 + V_72 . V_77 , V_70 ) ;
V_72 . V_79 = V_72 . V_78 - V_3 -> V_17 - V_72 . V_77 ;
V_72 . V_80 = V_72 . V_77 + V_72 . V_79 + V_69 ;
V_72 . V_36 = V_35 ( V_3 ) ;
if ( ! V_73 || ( V_73 && ! F_29 ( V_3 ) ) ) {
V_72 . V_81 = F_37 ( V_8 , V_3 , & V_72 ) ;
if ( V_72 . V_81 < 0 )
return V_72 . V_81 ;
}
V_36 = V_72 . V_36 ;
V_36 -> V_10 = V_8 -> V_40 . V_10 ;
F_15 ( V_3 , - F_18 ( V_3 ) ) ;
if ( V_6 -> V_14 & V_60 ) {
V_36 -> V_41 = F_20 ( V_6 -> V_9 . V_43 ) ;
} else {
F_8 ( V_3 ) -> V_82 = F_38 ( V_3 -> V_17 ) ;
F_39 ( F_8 ( V_3 ) ) ;
}
if ( V_73 )
return 0 ;
V_72 . V_83 = F_40 ( V_6 -> V_9 . V_43 + ( ( V_84 ) V_6 -> V_9 . V_61 << 32 ) ) ;
V_11 = F_41 ( V_8 , V_3 , & V_72 ) ;
if ( V_11 )
return V_11 ;
F_42 ( V_3 ) ;
return 0 ;
}
static int T_4 F_43 ( void )
{
if ( F_44 ( & V_85 , V_23 ) < 0 ) {
F_45 ( L_1 , V_86 ) ;
return - V_87 ;
}
return F_46 ( & V_88 , V_12 ) ;
}
static void T_5 F_47 ( void )
{
if ( F_48 ( & V_85 , V_23 ) < 0 )
F_45 ( L_2 , V_86 ) ;
F_49 ( & V_88 , V_12 ) ;
}
