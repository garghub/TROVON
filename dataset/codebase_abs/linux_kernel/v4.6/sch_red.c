static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & V_5 ;
}
static int F_3 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_8 * V_10 = V_2 -> V_11 ;
int V_12 ;
V_2 -> V_13 . V_14 = F_5 ( & V_2 -> V_15 ,
& V_2 -> V_13 ,
V_10 -> V_16 . V_17 ) ;
if ( F_6 ( & V_2 -> V_13 ) )
F_7 ( & V_2 -> V_13 ) ;
switch ( F_8 ( & V_2 -> V_15 , & V_2 -> V_13 , V_2 -> V_13 . V_14 ) ) {
case V_18 :
break;
case V_19 :
F_9 ( V_9 ) ;
if ( ! F_1 ( V_2 ) || ! F_10 ( V_7 ) ) {
V_2 -> V_20 . V_21 ++ ;
goto V_22;
}
V_2 -> V_20 . V_23 ++ ;
break;
case V_24 :
F_9 ( V_9 ) ;
if ( F_2 ( V_2 ) || ! F_1 ( V_2 ) ||
! F_10 ( V_7 ) ) {
V_2 -> V_20 . V_25 ++ ;
goto V_22;
}
V_2 -> V_20 . V_26 ++ ;
break;
}
V_12 = F_11 ( V_7 , V_10 ) ;
if ( F_12 ( V_12 == V_27 ) ) {
V_9 -> V_2 . V_28 ++ ;
} else if ( F_13 ( V_12 ) ) {
V_2 -> V_20 . V_29 ++ ;
F_14 ( V_9 ) ;
}
return V_12 ;
V_22:
F_15 ( V_7 , V_9 ) ;
return V_30 ;
}
static struct V_6 * F_16 ( struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_8 * V_10 = V_2 -> V_11 ;
V_7 = V_10 -> V_31 ( V_10 ) ;
if ( V_7 ) {
F_17 ( V_9 , V_7 ) ;
V_9 -> V_2 . V_28 -- ;
} else {
if ( ! F_6 ( & V_2 -> V_13 ) )
F_18 ( & V_2 -> V_13 ) ;
}
return V_7 ;
}
static struct V_6 * F_19 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_8 * V_10 = V_2 -> V_11 ;
return V_10 -> V_32 -> V_33 ( V_10 ) ;
}
static unsigned int F_20 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_8 * V_10 = V_2 -> V_11 ;
unsigned int V_34 ;
if ( V_10 -> V_32 -> V_35 && ( V_34 = V_10 -> V_32 -> V_35 ( V_10 ) ) > 0 ) {
V_2 -> V_20 . V_36 ++ ;
F_14 ( V_9 ) ;
V_9 -> V_2 . V_28 -- ;
return V_34 ;
}
if ( ! F_6 ( & V_2 -> V_13 ) )
F_18 ( & V_2 -> V_13 ) ;
return 0 ;
}
static void F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
F_22 ( V_2 -> V_11 ) ;
V_9 -> V_2 . V_28 = 0 ;
F_23 ( & V_2 -> V_13 ) ;
}
static void F_24 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
F_25 ( & V_2 -> V_37 ) ;
F_26 ( V_2 -> V_11 ) ;
}
static int F_27 ( struct V_8 * V_9 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_38 * V_40 [ V_41 + 1 ] ;
struct V_42 * V_43 ;
struct V_8 * V_10 = NULL ;
int V_44 ;
T_1 V_45 ;
if ( V_39 == NULL )
return - V_46 ;
V_44 = F_28 ( V_40 , V_41 , V_39 , V_47 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_40 [ V_48 ] == NULL ||
V_40 [ V_49 ] == NULL )
return - V_46 ;
V_45 = V_40 [ V_50 ] ? F_29 ( V_40 [ V_50 ] ) : 0 ;
V_43 = F_30 ( V_40 [ V_48 ] ) ;
if ( V_43 -> V_51 > 0 ) {
V_10 = F_31 ( V_9 , & V_52 , V_43 -> V_51 ) ;
if ( F_32 ( V_10 ) )
return F_33 ( V_10 ) ;
}
F_34 ( V_9 ) ;
V_2 -> V_3 = V_43 -> V_3 ;
V_2 -> V_51 = V_43 -> V_51 ;
if ( V_10 ) {
F_35 ( V_2 -> V_11 , V_2 -> V_11 -> V_2 . V_28 ,
V_2 -> V_11 -> V_16 . V_17 ) ;
F_26 ( V_2 -> V_11 ) ;
V_2 -> V_11 = V_10 ;
}
F_36 ( & V_2 -> V_15 ,
V_43 -> V_53 , V_43 -> V_54 , V_43 -> V_55 ,
V_43 -> V_56 , V_43 -> V_57 ,
F_30 ( V_40 [ V_49 ] ) ,
V_45 ) ;
F_37 ( & V_2 -> V_13 ) ;
F_38 ( & V_2 -> V_37 ) ;
if ( V_43 -> V_3 & V_58 )
F_39 ( & V_2 -> V_37 , V_59 + V_60 / 2 ) ;
if ( ! V_2 -> V_11 -> V_2 . V_28 )
F_18 ( & V_2 -> V_13 ) ;
F_40 ( V_9 ) ;
return 0 ;
}
static inline void F_41 ( unsigned long V_61 )
{
struct V_8 * V_9 = (struct V_8 * ) V_61 ;
struct V_1 * V_2 = F_4 ( V_9 ) ;
T_2 * V_62 = F_42 ( F_43 ( V_9 ) ) ;
F_44 ( V_62 ) ;
F_45 ( & V_2 -> V_15 , & V_2 -> V_13 ) ;
F_39 ( & V_2 -> V_37 , V_59 + V_60 / 2 ) ;
F_46 ( V_62 ) ;
}
static int F_47 ( struct V_8 * V_9 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
V_2 -> V_11 = & V_63 ;
F_48 ( & V_2 -> V_37 , F_41 , ( unsigned long ) V_9 ) ;
return F_27 ( V_9 , V_39 ) ;
}
static int F_49 ( struct V_8 * V_9 , struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_38 * V_64 = NULL ;
struct V_42 V_39 = {
. V_51 = V_2 -> V_51 ,
. V_3 = V_2 -> V_3 ,
. V_53 = V_2 -> V_15 . V_53 >> V_2 -> V_15 . V_55 ,
. V_54 = V_2 -> V_15 . V_54 >> V_2 -> V_15 . V_55 ,
. V_55 = V_2 -> V_15 . V_55 ,
. V_56 = V_2 -> V_15 . V_56 ,
. V_57 = V_2 -> V_15 . V_57 ,
} ;
V_9 -> V_16 . V_17 = V_2 -> V_11 -> V_16 . V_17 ;
V_64 = F_50 ( V_7 , V_65 ) ;
if ( V_64 == NULL )
goto V_66;
if ( F_51 ( V_7 , V_48 , sizeof( V_39 ) , & V_39 ) ||
F_52 ( V_7 , V_50 , V_2 -> V_15 . V_45 ) )
goto V_66;
return F_53 ( V_7 , V_64 ) ;
V_66:
F_54 ( V_7 , V_64 ) ;
return - V_67 ;
}
static int F_55 ( struct V_8 * V_9 , struct V_68 * V_69 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_70 V_71 = {
. V_72 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_25 ,
. V_29 = V_2 -> V_20 . V_29 ,
. V_36 = V_2 -> V_20 . V_36 ,
. V_73 = V_2 -> V_20 . V_23 + V_2 -> V_20 . V_26 ,
} ;
return F_56 ( V_69 , & V_71 , sizeof( V_71 ) ) ;
}
static int F_57 ( struct V_8 * V_9 , unsigned long V_74 ,
struct V_6 * V_7 , struct V_75 * V_76 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
V_76 -> V_77 |= F_58 ( 1 ) ;
V_76 -> V_78 = V_2 -> V_11 -> V_79 ;
return 0 ;
}
static int F_59 ( struct V_8 * V_9 , unsigned long V_61 , struct V_8 * V_80 ,
struct V_8 * * V_81 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
if ( V_80 == NULL )
V_80 = & V_63 ;
* V_81 = F_60 ( V_9 , V_80 , & V_2 -> V_11 ) ;
return 0 ;
}
static struct V_8 * F_61 ( struct V_8 * V_9 , unsigned long V_61 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
return V_2 -> V_11 ;
}
static unsigned long F_62 ( struct V_8 * V_9 , T_1 V_82 )
{
return 1 ;
}
static void F_63 ( struct V_8 * V_9 , unsigned long V_61 )
{
}
static void F_64 ( struct V_8 * V_9 , struct V_83 * V_84 )
{
if ( ! V_84 -> V_85 ) {
if ( V_84 -> V_86 >= V_84 -> V_87 )
if ( V_84 -> V_88 ( V_9 , 1 , V_84 ) < 0 ) {
V_84 -> V_85 = 1 ;
return;
}
V_84 -> V_86 ++ ;
}
}
static int T_3 F_65 ( void )
{
return F_66 ( & V_89 ) ;
}
static void T_4 F_67 ( void )
{
F_68 ( & V_89 ) ;
}
