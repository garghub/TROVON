static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static inline struct V_5 * F_2 (
struct V_2 * V_3 )
{
return & F_1 ( V_3 ) -> V_6 ;
}
static int F_3 ( struct V_7 * V_7 , struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_12 * V_13 = F_4 ( V_11 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 ;
struct V_1 * V_16 = F_1 ( V_13 -> V_17 ) ;
struct V_12 * V_18 ;
int V_19 = - V_20 ;
if ( V_11 -> V_21 != F_5 ( V_22 ) )
goto V_23;
F_6 ( V_11 , F_2 ( V_13 -> V_17 ) ,
true ) ;
if ( V_15 -> V_24 & ( V_25 | V_26 ) ) {
return V_13 -> V_17 -> V_27 ( V_7 , V_9 , V_11 ) ;
}
V_18 = F_7 ( & V_16 -> V_28 ) ;
if ( F_8 ( ! V_18 ) ) {
struct V_29 * V_30 = F_9 ( V_11 ) ;
struct V_31 V_32 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_33 = V_13 -> V_34 -> V_35 ;
V_32 . V_36 = V_37 ;
V_32 . V_38 = * F_10 ( (struct V_14 * ) V_13 ,
& V_30 -> V_38 ) ;
V_18 = F_11 ( V_7 , NULL , & V_32 ) ;
if ( V_18 -> error ) {
V_19 = - V_39 ;
F_12 ( V_18 ) ;
goto V_23;
}
V_18 = F_13 ( V_7 , V_18 , F_14 ( & V_32 ) , NULL , 0 ) ;
if ( F_15 ( V_18 ) ) {
V_19 = F_16 ( V_18 ) ;
goto V_23;
}
if ( V_16 -> V_40 )
F_17 ( & V_16 -> V_28 , V_18 , & V_32 . V_41 ) ;
}
F_18 ( V_11 , V_18 ) ;
return F_19 ( V_7 , V_9 , V_11 ) ;
V_23:
F_20 ( V_11 ) ;
return V_19 ;
}
static int F_21 ( struct V_10 * V_11 )
{
struct V_12 * V_18 = F_4 ( V_11 ) ;
if ( V_11 -> V_21 != F_5 ( V_22 ) )
goto V_23;
F_6 ( V_11 , F_2 ( V_18 -> V_17 ) , false ) ;
return V_18 -> V_17 -> V_42 ( V_11 ) ;
V_23:
F_20 ( V_11 ) ;
return - V_20 ;
}
static int F_22 ( struct V_43 * V_44 ,
unsigned int V_45 , const void * V_46 ,
struct V_2 * * V_47 ,
struct V_48 * V_49 )
{
struct V_1 * V_16 ;
struct V_5 * V_6 ;
struct V_43 * V_50 [ V_51 + 1 ] ;
struct V_2 * V_52 ;
const struct V_53 * V_54 = V_46 ;
struct V_55 * V_56 ;
int V_57 ;
if ( V_45 != V_58 )
return - V_20 ;
if ( V_54 -> V_59 < 8 * sizeof( struct V_60 ) + 3 ) {
return - V_20 ;
}
V_56 = (struct V_55 * ) & V_54 -> V_61 ;
if ( ! F_23 ( V_56 ) || F_24 ( V_56 -> V_62 ) ) {
return - V_20 ;
}
V_57 = F_25 ( V_50 , V_51 , V_44 , V_63 , V_49 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ! V_50 [ V_64 ] )
return - V_20 ;
V_52 = F_26 ( sizeof( * V_16 ) ) ;
if ( ! V_52 )
return - V_65 ;
V_16 = F_1 ( V_52 ) ;
V_57 = F_27 ( & V_16 -> V_28 , V_66 ) ;
if ( V_57 ) {
F_28 ( V_52 ) ;
return V_57 ;
}
V_6 = F_2 ( V_52 ) ;
V_6 -> V_67 . V_68 = ( V_69 V_70 ) F_29 ( V_50 [ V_64 ] ) ;
V_6 -> V_71 = V_56 -> V_72 ;
V_6 -> V_73 = F_30 (
( V_74 * ) & V_6 -> V_71 , ( V_74 * ) & V_6 -> V_67 ) ;
if ( V_50 [ V_75 ] )
V_6 -> V_76 = F_31 ( V_50 [ V_75 ] ) ;
F_32 ( V_6 ) ;
V_52 -> type = V_77 ;
V_52 -> V_78 |= V_79 |
V_80 ;
if ( V_54 -> V_59 == 8 * sizeof( struct V_81 ) )
V_16 -> V_40 = 1 ;
* V_47 = V_52 ;
return 0 ;
}
static void F_33 ( struct V_2 * V_3 )
{
F_34 ( & F_1 ( V_3 ) -> V_28 ) ;
}
static int F_35 ( struct V_10 * V_11 ,
struct V_2 * V_17 )
{
struct V_5 * V_6 = F_2 ( V_17 ) ;
if ( F_36 ( V_11 , V_64 , ( V_69 V_82 ) V_6 -> V_67 . V_68 ,
V_83 ) )
goto V_84;
if ( F_37 ( V_11 , V_75 , ( V_69 V_85 ) V_6 -> V_76 ) )
goto V_84;
return 0 ;
V_84:
return - V_86 ;
}
static int F_38 ( struct V_2 * V_17 )
{
return F_39 ( sizeof( V_82 ) ) +
F_40 ( sizeof( V_85 ) ) +
0 ;
}
static int F_41 ( struct V_2 * V_87 , struct V_2 * V_88 )
{
struct V_5 * V_89 = F_2 ( V_87 ) ;
struct V_5 * V_90 = F_2 ( V_88 ) ;
return ( V_89 -> V_67 . V_68 != V_90 -> V_67 . V_68 ) ;
}
int F_42 ( void )
{
return F_43 ( & V_91 , V_77 ) ;
}
void F_44 ( void )
{
F_45 ( & V_91 , V_77 ) ;
}
