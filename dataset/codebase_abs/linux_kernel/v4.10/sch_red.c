static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & V_5 ;
}
static int F_3 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_6 * * V_10 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_8 * V_11 = V_2 -> V_12 ;
int V_13 ;
V_2 -> V_14 . V_15 = F_5 ( & V_2 -> V_16 ,
& V_2 -> V_14 ,
V_11 -> V_17 . V_18 ) ;
if ( F_6 ( & V_2 -> V_14 ) )
F_7 ( & V_2 -> V_14 ) ;
switch ( F_8 ( & V_2 -> V_16 , & V_2 -> V_14 , V_2 -> V_14 . V_15 ) ) {
case V_19 :
break;
case V_20 :
F_9 ( V_9 ) ;
if ( ! F_1 ( V_2 ) || ! F_10 ( V_7 ) ) {
V_2 -> V_21 . V_22 ++ ;
goto V_23;
}
V_2 -> V_21 . V_24 ++ ;
break;
case V_25 :
F_9 ( V_9 ) ;
if ( F_2 ( V_2 ) || ! F_1 ( V_2 ) ||
! F_10 ( V_7 ) ) {
V_2 -> V_21 . V_26 ++ ;
goto V_23;
}
V_2 -> V_21 . V_27 ++ ;
break;
}
V_13 = F_11 ( V_7 , V_11 , V_10 ) ;
if ( F_12 ( V_13 == V_28 ) ) {
F_13 ( V_9 , V_7 ) ;
V_9 -> V_2 . V_29 ++ ;
} else if ( F_14 ( V_13 ) ) {
V_2 -> V_21 . V_30 ++ ;
F_15 ( V_9 ) ;
}
return V_13 ;
V_23:
F_16 ( V_7 , V_9 , V_10 ) ;
return V_31 ;
}
static struct V_6 * F_17 ( struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_8 * V_11 = V_2 -> V_12 ;
V_7 = V_11 -> V_32 ( V_11 ) ;
if ( V_7 ) {
F_18 ( V_9 , V_7 ) ;
F_19 ( V_9 , V_7 ) ;
V_9 -> V_2 . V_29 -- ;
} else {
if ( ! F_6 ( & V_2 -> V_14 ) )
F_20 ( & V_2 -> V_14 ) ;
}
return V_7 ;
}
static struct V_6 * F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_8 * V_11 = V_2 -> V_12 ;
return V_11 -> V_33 -> V_34 ( V_11 ) ;
}
static void F_22 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
F_23 ( V_2 -> V_12 ) ;
V_9 -> V_17 . V_18 = 0 ;
V_9 -> V_2 . V_29 = 0 ;
F_24 ( & V_2 -> V_14 ) ;
}
static void F_25 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
F_26 ( & V_2 -> V_35 ) ;
F_27 ( V_2 -> V_12 ) ;
}
static int F_28 ( struct V_8 * V_9 , struct V_36 * V_37 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_36 * V_38 [ V_39 + 1 ] ;
struct V_40 * V_41 ;
struct V_8 * V_11 = NULL ;
int V_42 ;
T_1 V_43 ;
if ( V_37 == NULL )
return - V_44 ;
V_42 = F_29 ( V_38 , V_39 , V_37 , V_45 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_38 [ V_46 ] == NULL ||
V_38 [ V_47 ] == NULL )
return - V_44 ;
V_43 = V_38 [ V_48 ] ? F_30 ( V_38 [ V_48 ] ) : 0 ;
V_41 = F_31 ( V_38 [ V_46 ] ) ;
if ( V_41 -> V_49 > 0 ) {
V_11 = F_32 ( V_9 , & V_50 , V_41 -> V_49 ) ;
if ( F_33 ( V_11 ) )
return F_34 ( V_11 ) ;
}
F_35 ( V_9 ) ;
V_2 -> V_3 = V_41 -> V_3 ;
V_2 -> V_49 = V_41 -> V_49 ;
if ( V_11 ) {
F_36 ( V_2 -> V_12 , V_2 -> V_12 -> V_2 . V_29 ,
V_2 -> V_12 -> V_17 . V_18 ) ;
F_27 ( V_2 -> V_12 ) ;
V_2 -> V_12 = V_11 ;
}
F_37 ( & V_2 -> V_16 ,
V_41 -> V_51 , V_41 -> V_52 , V_41 -> V_53 ,
V_41 -> V_54 , V_41 -> V_55 ,
F_31 ( V_38 [ V_47 ] ) ,
V_43 ) ;
F_38 ( & V_2 -> V_14 ) ;
F_39 ( & V_2 -> V_35 ) ;
if ( V_41 -> V_3 & V_56 )
F_40 ( & V_2 -> V_35 , V_57 + V_58 / 2 ) ;
if ( ! V_2 -> V_12 -> V_2 . V_29 )
F_20 ( & V_2 -> V_14 ) ;
F_41 ( V_9 ) ;
return 0 ;
}
static inline void F_42 ( unsigned long V_59 )
{
struct V_8 * V_9 = (struct V_8 * ) V_59 ;
struct V_1 * V_2 = F_4 ( V_9 ) ;
T_2 * V_60 = F_43 ( F_44 ( V_9 ) ) ;
F_45 ( V_60 ) ;
F_46 ( & V_2 -> V_16 , & V_2 -> V_14 ) ;
F_40 ( & V_2 -> V_35 , V_57 + V_58 / 2 ) ;
F_47 ( V_60 ) ;
}
static int F_48 ( struct V_8 * V_9 , struct V_36 * V_37 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
V_2 -> V_12 = & V_61 ;
F_49 ( & V_2 -> V_35 , F_42 , ( unsigned long ) V_9 ) ;
return F_28 ( V_9 , V_37 ) ;
}
static int F_50 ( struct V_8 * V_9 , struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_36 * V_62 = NULL ;
struct V_40 V_37 = {
. V_49 = V_2 -> V_49 ,
. V_3 = V_2 -> V_3 ,
. V_51 = V_2 -> V_16 . V_51 >> V_2 -> V_16 . V_53 ,
. V_52 = V_2 -> V_16 . V_52 >> V_2 -> V_16 . V_53 ,
. V_53 = V_2 -> V_16 . V_53 ,
. V_54 = V_2 -> V_16 . V_54 ,
. V_55 = V_2 -> V_16 . V_55 ,
} ;
V_9 -> V_17 . V_18 = V_2 -> V_12 -> V_17 . V_18 ;
V_62 = F_51 ( V_7 , V_63 ) ;
if ( V_62 == NULL )
goto V_64;
if ( F_52 ( V_7 , V_46 , sizeof( V_37 ) , & V_37 ) ||
F_53 ( V_7 , V_48 , V_2 -> V_16 . V_43 ) )
goto V_64;
return F_54 ( V_7 , V_62 ) ;
V_64:
F_55 ( V_7 , V_62 ) ;
return - V_65 ;
}
static int F_56 ( struct V_8 * V_9 , struct V_66 * V_67 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_68 V_69 = {
. V_70 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_26 ,
. V_30 = V_2 -> V_21 . V_30 ,
. V_71 = V_2 -> V_21 . V_71 ,
. V_72 = V_2 -> V_21 . V_24 + V_2 -> V_21 . V_27 ,
} ;
return F_57 ( V_67 , & V_69 , sizeof( V_69 ) ) ;
}
static int F_58 ( struct V_8 * V_9 , unsigned long V_73 ,
struct V_6 * V_7 , struct V_74 * V_75 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
V_75 -> V_76 |= F_59 ( 1 ) ;
V_75 -> V_77 = V_2 -> V_12 -> V_78 ;
return 0 ;
}
static int F_60 ( struct V_8 * V_9 , unsigned long V_59 , struct V_8 * V_79 ,
struct V_8 * * V_80 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
if ( V_79 == NULL )
V_79 = & V_61 ;
* V_80 = F_61 ( V_9 , V_79 , & V_2 -> V_12 ) ;
return 0 ;
}
static struct V_8 * F_62 ( struct V_8 * V_9 , unsigned long V_59 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
return V_2 -> V_12 ;
}
static unsigned long F_63 ( struct V_8 * V_9 , T_1 V_81 )
{
return 1 ;
}
static void F_64 ( struct V_8 * V_9 , unsigned long V_59 )
{
}
static void F_65 ( struct V_8 * V_9 , struct V_82 * V_83 )
{
if ( ! V_83 -> V_84 ) {
if ( V_83 -> V_85 >= V_83 -> V_86 )
if ( V_83 -> V_87 ( V_9 , 1 , V_83 ) < 0 ) {
V_83 -> V_84 = 1 ;
return;
}
V_83 -> V_85 ++ ;
}
}
static int T_3 F_66 ( void )
{
return F_67 ( & V_88 ) ;
}
static void T_4 F_68 ( void )
{
F_69 ( & V_88 ) ;
}
