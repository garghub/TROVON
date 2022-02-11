static struct V_1 F_1 ( const struct V_2 * V_3 , int V_4 )
{
struct V_1 V_5 ;
T_1 V_6 = V_3 -> V_7 . V_8 . V_9 . V_1 [ V_4 ] ;
V_5 . V_10 = V_6 & V_11 ;
if ( V_5 . V_10 <= 15 )
V_5 . V_12 = ( V_6 >> V_13 ) & 0x7 ;
else
V_5 . V_12 = 0 ;
V_5 . V_14 = 0 ;
if ( V_6 & V_15 )
V_5 . V_14 |= V_16 ;
if ( V_6 & V_17 )
V_5 . V_14 |= V_18 ;
if ( V_6 & V_19 )
V_5 . V_14 |= V_20 ;
if ( V_6 & V_21 ) {
V_5 . V_14 |= V_22 ;
V_5 . V_23 = ( V_6 & V_24 ) >> V_13 ;
}
return V_5 ;
}
static void F_2 ( struct V_2 * V_3 , int V_4 ,
struct V_1 V_5 )
{
T_1 V_25 ;
V_25 = V_5 . V_10 ;
if ( V_5 . V_14 & V_16 )
V_25 |= V_15 ;
if ( V_5 . V_14 & V_18 )
V_25 |= V_17 ;
if ( V_5 . V_14 & V_20 )
V_25 |= V_19 ;
if ( V_5 . V_14 & V_22 ) {
V_25 |= V_21 ;
V_25 |= ( T_1 ) V_5 . V_23 << V_13 ;
}
if ( V_5 . V_10 < V_26 )
V_25 |= ( V_5 . V_12 << V_13 ) ;
V_3 -> V_7 . V_8 . V_9 . V_1 [ V_4 ] = V_25 ;
if ( ! ( V_5 . V_14 & V_27 ) )
V_3 -> V_7 . V_8 . V_9 . V_28 |= ( 1ULL << V_4 ) ;
else
V_3 -> V_7 . V_8 . V_9 . V_28 &= ~ ( 1ULL << V_4 ) ;
}
static T_2 F_3 ( const struct V_2 * V_3 )
{
return V_3 -> V_7 . V_8 . V_9 . V_28 ;
}
static T_2 F_4 ( const struct V_2 * V_3 )
{
return V_3 -> V_7 . V_8 . V_9 . V_29 ;
}
static void F_5 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_29 = 0 ;
}
static T_1 F_6 ( const struct V_2 * V_3 )
{
T_1 V_30 = V_3 -> V_7 . V_8 . V_9 . V_31 ;
T_1 V_32 = 0 ;
if ( V_30 & V_33 )
V_32 |= V_34 ;
if ( V_30 & V_35 )
V_32 |= V_36 ;
return V_32 ;
}
static void F_7 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_37 |= V_38 ;
}
static void F_8 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_37 &= ~ V_38 ;
}
static void F_9 ( struct V_2 * V_3 , struct V_39 * V_40 )
{
T_1 V_41 = V_3 -> V_7 . V_8 . V_9 . V_39 ;
V_40 -> V_42 = ( V_41 & V_43 ) >> V_44 ;
V_40 -> V_45 = ( V_41 & V_46 ) >> V_47 ;
V_40 -> V_48 = ( V_41 & V_49 ) >> V_50 ;
V_40 -> V_51 = ( V_41 & V_52 ) >> V_53 ;
}
static void F_10 ( struct V_2 * V_3 , struct V_39 * V_40 )
{
T_1 V_41 ;
V_41 = ( V_40 -> V_42 << V_44 ) & V_43 ;
V_41 |= ( V_40 -> V_45 << V_47 ) & V_46 ;
V_41 |= ( V_40 -> V_48 << V_50 ) & V_49 ;
V_41 |= ( V_40 -> V_51 << V_53 ) & V_52 ;
V_3 -> V_7 . V_8 . V_9 . V_39 = V_41 ;
}
static void F_11 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_39 = 0 ;
V_3 -> V_7 . V_8 . V_9 . V_28 = ~ 0 ;
V_3 -> V_7 . V_8 . V_9 . V_37 = V_54 ;
}
static void F_12 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_57 -> V_59 ; V_58 ++ )
F_13 ( 0 , V_57 -> V_60 + V_61 + ( V_58 * 4 ) ) ;
}
int F_14 ( const struct V_62 * V_62 ,
const struct V_63 * * V_64 ,
const struct V_56 * * V_55 )
{
int V_32 ;
struct V_56 * V_57 = & V_65 ;
const struct V_66 * V_67 = & V_62 -> V_68 ;
const struct V_66 * V_69 = & V_62 -> V_3 ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
if ( ! V_62 -> V_70 ) {
F_15 ( L_1 ) ;
V_32 = - V_71 ;
goto V_72;
}
V_57 -> V_70 = V_62 -> V_70 ;
if ( ! V_62 -> V_68 . V_73 ) {
F_15 ( L_2 ) ;
V_32 = - V_71 ;
goto V_72;
}
V_57 -> V_60 = F_16 ( V_62 -> V_68 . V_73 ,
F_17 ( & V_62 -> V_68 ) ) ;
if ( ! V_57 -> V_60 ) {
F_15 ( L_3 ) ;
V_32 = - V_74 ;
goto V_72;
}
V_57 -> V_59 = F_18 ( V_57 -> V_60 + V_75 ) ;
V_57 -> V_59 = ( V_57 -> V_59 & 0x3f ) + 1 ;
V_32 = F_19 ( V_57 -> V_60 ,
V_57 -> V_60 + F_17 ( V_67 ) ,
V_67 -> V_73 ) ;
if ( V_32 ) {
F_15 ( L_4 ) ;
goto V_76;
}
if ( ! F_20 ( V_69 -> V_73 ) ) {
F_15 ( L_5 ,
( unsigned long long ) V_69 -> V_73 ) ;
V_32 = - V_71 ;
goto V_76;
}
if ( ! F_20 ( F_17 ( V_69 ) ) ) {
F_15 ( L_6 ,
( unsigned long long ) F_17 ( V_69 ) ,
V_77 ) ;
V_32 = - V_71 ;
goto V_76;
}
V_57 -> V_78 = true ;
F_21 ( & V_79 , V_80 ) ;
V_57 -> V_81 = V_69 -> V_73 ;
F_22 ( L_7 ,
V_62 -> V_68 . V_73 , V_57 -> V_81 , V_57 -> V_70 ) ;
V_57 -> type = V_82 ;
V_57 -> V_83 = V_84 ;
F_23 ( F_12 , V_57 , 1 ) ;
* V_64 = & V_85 ;
* V_55 = V_57 ;
goto V_72;
V_76:
F_24 ( V_57 -> V_60 ) ;
V_72:
return V_32 ;
}
