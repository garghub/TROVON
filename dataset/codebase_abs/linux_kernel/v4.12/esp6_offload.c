static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = sizeof( struct V_1 ) ;
struct V_5 * V_6 ;
if ( F_2 ( V_2 -> V_7 == V_8 ) )
return F_3 ( struct V_1 , V_7 ) ;
while ( V_4 < V_3 ) {
V_6 = ( void * ) V_2 + V_4 ;
if ( V_6 -> V_7 == V_8 )
return V_4 ;
V_4 += F_4 ( V_6 ) ;
}
return 0 ;
}
static struct V_9 * * F_5 ( struct V_9 * * V_10 ,
struct V_9 * V_11 )
{
int V_12 = F_6 ( V_11 ) ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
T_2 V_17 ;
T_2 V_18 ;
int V_19 ;
int V_20 ;
F_7 ( V_11 , V_12 ) ;
if ( ( V_20 = F_8 ( V_11 , V_21 , & V_18 , & V_17 ) ) != 0 )
goto V_22;
V_14 = V_13 ( V_11 ) ;
if ( ! V_14 || ! ( V_14 -> V_23 & V_24 ) ) {
V_20 = F_9 ( V_11 ) ;
if ( V_20 )
goto V_22;
if ( V_11 -> V_25 -> V_26 == V_27 )
goto V_22;
V_16 = F_10 ( F_11 ( V_11 -> V_28 ) , V_11 -> V_29 ,
( V_30 * ) & V_2 ( V_11 ) -> V_31 ,
V_18 , V_21 , V_32 ) ;
if ( ! V_16 )
goto V_22;
V_11 -> V_25 -> V_33 [ V_11 -> V_25 -> V_26 ++ ] = V_16 ;
V_11 -> V_25 -> V_34 ++ ;
V_14 = V_13 ( V_11 ) ;
if ( ! V_14 ) {
F_12 ( V_16 ) ;
goto V_22;
}
}
V_14 -> V_23 |= V_35 ;
V_19 = F_1 ( V_2 ( V_11 ) , V_12 ) ;
if ( ! V_19 )
goto V_22;
F_13 ( V_11 ) -> V_19 = V_19 ;
F_14 ( V_11 ) -> V_36 . V_37 = NULL ;
F_15 ( V_11 ) -> V_38 = V_32 ;
F_15 ( V_11 ) -> V_39 = F_3 ( struct V_1 , V_31 ) ;
F_15 ( V_11 ) -> V_17 = V_17 ;
F_16 ( V_11 , V_21 , V_18 , - 2 ) ;
return F_17 ( - V_40 ) ;
V_22:
F_18 ( V_11 , V_12 ) ;
F_19 ( V_11 ) -> V_41 = 0 ;
F_19 ( V_11 ) -> V_42 = 1 ;
return NULL ;
}
static void F_20 ( struct V_15 * V_16 , struct V_9 * V_11 )
{
struct V_43 * V_44 ;
struct V_1 * V_45 = V_2 ( V_11 ) ;
struct V_13 * V_14 = V_13 ( V_11 ) ;
int V_46 = V_45 -> V_7 ;
F_18 ( V_11 , - F_21 ( V_11 ) ) ;
V_44 = V_43 ( V_11 ) ;
* F_22 ( V_11 ) = V_21 ;
V_44 -> V_18 = V_16 -> V_47 . V_18 ;
V_44 -> V_48 = F_23 ( F_24 ( V_11 ) -> V_17 . V_49 . V_50 ) ;
V_14 -> V_46 = V_46 ;
}
static struct V_9 * F_25 ( struct V_9 * V_11 ,
T_3 V_51 )
{
T_4 V_17 ;
int V_20 = 0 ;
struct V_9 * V_52 ;
struct V_15 * V_16 ;
struct V_43 * V_44 ;
struct V_53 * V_54 ;
struct V_9 * V_55 = F_17 ( - V_56 ) ;
T_3 V_57 = V_51 ;
struct V_13 * V_14 = V_13 ( V_11 ) ;
if ( ! V_14 )
goto V_22;
V_17 = V_14 -> V_17 . V_50 ;
V_16 = V_11 -> V_25 -> V_33 [ V_11 -> V_25 -> V_26 - 1 ] ;
V_54 = V_16 -> V_58 ;
V_44 = V_43 ( V_11 ) ;
if ( V_44 -> V_18 != V_16 -> V_47 . V_18 )
goto V_22;
if ( ! F_26 ( V_11 , sizeof( * V_44 ) + F_27 ( V_54 ) ) )
goto V_22;
F_28 ( V_11 , sizeof( * V_44 ) + F_27 ( V_54 ) ) ;
V_11 -> V_59 = 1 ;
if ( ! ( V_51 & V_60 ) )
V_57 = V_51 & ~ ( V_61 | V_62 ) ;
V_55 = V_16 -> V_63 -> V_64 ( V_16 , V_11 , V_57 ) ;
if ( F_29 ( V_55 ) )
goto V_22;
F_28 ( V_11 , V_11 -> V_58 - F_22 ( V_11 ) ) ;
V_52 = V_55 ;
do {
struct V_9 * V_65 = V_52 -> V_66 ;
V_14 = V_13 ( V_52 ) ;
V_14 -> V_23 |= V_67 ;
V_14 -> V_17 . V_50 = V_17 ;
V_14 -> V_17 . V_68 = F_30 ( V_16 , V_17 ) ;
if( ! ( V_51 & V_60 ) )
V_14 -> V_23 |= V_69 ;
V_16 -> V_63 -> V_70 ( V_16 , V_52 ) ;
V_20 = V_16 -> V_71 -> V_70 ( V_16 , V_52 , V_57 ) ;
if ( V_20 ) {
F_31 ( V_55 ) ;
return F_17 ( V_20 ) ;
}
if ( ! F_32 ( V_52 ) )
V_17 ++ ;
else
V_17 += F_33 ( V_52 ) -> V_72 ;
F_18 ( V_52 , V_52 -> V_73 ) ;
V_52 = V_65 ;
} while ( V_52 );
V_22:
return V_55 ;
}
static int F_34 ( struct V_15 * V_16 , struct V_9 * V_11 )
{
struct V_53 * V_54 = V_16 -> V_58 ;
if ( ! F_26 ( V_11 , sizeof( struct V_43 ) + F_27 ( V_54 ) ) )
return - V_56 ;
V_11 -> V_74 = V_75 ;
return F_35 ( V_11 , 0 ) ;
}
static int F_36 ( struct V_15 * V_16 , struct V_9 * V_11 , T_3 V_51 )
{
int V_20 ;
int V_76 ;
int V_77 ;
struct V_13 * V_14 ;
struct V_43 * V_44 ;
struct V_53 * V_54 ;
struct V_78 V_79 ;
bool V_80 = true ;
V_79 . V_81 = true ;
V_14 = V_13 ( V_11 ) ;
if ( ! V_14 )
return - V_56 ;
if ( ! ( V_51 & V_60 ) || ! V_16 -> V_82 . V_83 ||
( V_16 -> V_82 . V_28 != V_11 -> V_28 ) ) {
V_14 -> V_23 |= V_69 ;
V_80 = false ;
}
V_79 . V_46 = V_14 -> V_46 ;
V_54 = V_16 -> V_58 ;
V_76 = F_37 ( V_54 ) ;
V_79 . V_84 = 0 ;
V_77 = F_38 ( F_39 ( V_54 ) , 4 ) ;
V_79 . V_85 = F_38 ( V_11 -> V_26 + 2 + V_79 . V_84 , V_77 ) ;
V_79 . V_86 = V_79 . V_85 - V_11 -> V_26 - V_79 . V_84 ;
V_79 . V_87 = V_79 . V_84 + V_79 . V_86 + V_76 ;
if ( ! V_80 || ( V_80 && ! F_32 ( V_11 ) ) ) {
V_79 . V_88 = F_40 ( V_16 , V_11 , & V_79 ) ;
if ( V_79 . V_88 < 0 )
return V_79 . V_88 ;
}
V_44 = V_43 ( V_11 ) ;
V_44 -> V_18 = V_16 -> V_47 . V_18 ;
F_18 ( V_11 , - F_21 ( V_11 ) ) ;
if ( V_14 -> V_23 & V_67 ) {
V_44 -> V_48 = F_23 ( V_14 -> V_17 . V_50 ) ;
} else {
int V_26 ;
V_26 = V_11 -> V_26 - sizeof( struct V_1 ) ;
if ( V_26 > V_89 )
V_26 = 0 ;
V_2 ( V_11 ) -> V_90 = F_41 ( V_26 ) ;
}
if ( V_80 )
return 0 ;
V_79 . V_91 = F_42 ( V_14 -> V_17 . V_50 + ( ( V_92 ) V_14 -> V_17 . V_68 << 32 ) ) ;
V_20 = F_43 ( V_16 , V_11 , & V_79 ) ;
if ( V_20 < 0 )
return V_20 ;
F_44 ( V_11 ) ;
return 0 ;
}
static int T_5 F_45 ( void )
{
if ( F_46 ( & V_93 , V_32 ) < 0 ) {
F_47 ( L_1 , V_94 ) ;
return - V_95 ;
}
return F_48 ( & V_96 , V_21 ) ;
}
static void T_6 F_49 ( void )
{
if ( F_50 ( & V_93 , V_32 ) < 0 )
F_47 ( L_2 , V_94 ) ;
F_51 ( & V_96 , V_21 ) ;
}
