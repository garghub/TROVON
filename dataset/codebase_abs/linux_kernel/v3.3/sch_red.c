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
V_9 -> V_16 . V_20 ++ ;
if ( ! F_1 ( V_2 ) || ! F_9 ( V_7 ) ) {
V_2 -> V_21 . V_22 ++ ;
goto V_23;
}
V_2 -> V_21 . V_24 ++ ;
break;
case V_25 :
V_9 -> V_16 . V_20 ++ ;
if ( F_2 ( V_2 ) || ! F_1 ( V_2 ) ||
! F_9 ( V_7 ) ) {
V_2 -> V_21 . V_26 ++ ;
goto V_23;
}
V_2 -> V_21 . V_27 ++ ;
break;
}
V_12 = F_10 ( V_7 , V_10 ) ;
if ( F_11 ( V_12 == V_28 ) ) {
V_9 -> V_2 . V_29 ++ ;
} else if ( F_12 ( V_12 ) ) {
V_2 -> V_21 . V_30 ++ ;
V_9 -> V_16 . V_31 ++ ;
}
return V_12 ;
V_23:
F_13 ( V_7 , V_9 ) ;
return V_32 ;
}
static struct V_6 * F_14 ( struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_8 * V_10 = V_2 -> V_11 ;
V_7 = V_10 -> V_33 ( V_10 ) ;
if ( V_7 ) {
F_15 ( V_9 , V_7 ) ;
V_9 -> V_2 . V_29 -- ;
} else {
if ( ! F_6 ( & V_2 -> V_13 ) )
F_16 ( & V_2 -> V_13 ) ;
}
return V_7 ;
}
static struct V_6 * F_17 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_8 * V_10 = V_2 -> V_11 ;
return V_10 -> V_34 -> V_35 ( V_10 ) ;
}
static unsigned int F_18 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_8 * V_10 = V_2 -> V_11 ;
unsigned int V_36 ;
if ( V_10 -> V_34 -> V_37 && ( V_36 = V_10 -> V_34 -> V_37 ( V_10 ) ) > 0 ) {
V_2 -> V_21 . V_38 ++ ;
V_9 -> V_16 . V_31 ++ ;
V_9 -> V_2 . V_29 -- ;
return V_36 ;
}
if ( ! F_6 ( & V_2 -> V_13 ) )
F_16 ( & V_2 -> V_13 ) ;
return 0 ;
}
static void F_19 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
F_20 ( V_2 -> V_11 ) ;
V_9 -> V_2 . V_29 = 0 ;
F_21 ( & V_2 -> V_13 ) ;
}
static void F_22 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
F_23 ( & V_2 -> V_39 ) ;
F_24 ( V_2 -> V_11 ) ;
}
static int F_25 ( struct V_8 * V_9 , struct V_40 * V_41 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_40 * V_42 [ V_43 + 1 ] ;
struct V_44 * V_45 ;
struct V_8 * V_10 = NULL ;
int V_46 ;
T_1 V_47 ;
if ( V_41 == NULL )
return - V_48 ;
V_46 = F_26 ( V_42 , V_43 , V_41 , V_49 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_42 [ V_50 ] == NULL ||
V_42 [ V_51 ] == NULL )
return - V_48 ;
V_47 = V_42 [ V_52 ] ? F_27 ( V_42 [ V_52 ] ) : 0 ;
V_45 = F_28 ( V_42 [ V_50 ] ) ;
if ( V_45 -> V_53 > 0 ) {
V_10 = F_29 ( V_9 , & V_54 , V_45 -> V_53 ) ;
if ( F_30 ( V_10 ) )
return F_31 ( V_10 ) ;
}
F_32 ( V_9 ) ;
V_2 -> V_3 = V_45 -> V_3 ;
V_2 -> V_53 = V_45 -> V_53 ;
if ( V_10 ) {
F_33 ( V_2 -> V_11 , V_2 -> V_11 -> V_2 . V_29 ) ;
F_24 ( V_2 -> V_11 ) ;
V_2 -> V_11 = V_10 ;
}
F_34 ( & V_2 -> V_15 ,
V_45 -> V_55 , V_45 -> V_56 , V_45 -> V_57 ,
V_45 -> V_58 , V_45 -> V_59 ,
F_28 ( V_42 [ V_51 ] ) ,
V_47 ) ;
F_35 ( & V_2 -> V_13 ) ;
F_36 ( & V_2 -> V_39 ) ;
if ( V_45 -> V_3 & V_60 )
F_37 ( & V_2 -> V_39 , V_61 + V_62 / 2 ) ;
if ( ! V_2 -> V_11 -> V_2 . V_29 )
F_16 ( & V_2 -> V_13 ) ;
F_38 ( V_9 ) ;
return 0 ;
}
static inline void F_39 ( unsigned long V_63 )
{
struct V_8 * V_9 = (struct V_8 * ) V_63 ;
struct V_1 * V_2 = F_4 ( V_9 ) ;
T_2 * V_64 = F_40 ( F_41 ( V_9 ) ) ;
F_42 ( V_64 ) ;
F_43 ( & V_2 -> V_15 , & V_2 -> V_13 ) ;
F_37 ( & V_2 -> V_39 , V_61 + V_62 / 2 ) ;
F_44 ( V_64 ) ;
}
static int F_45 ( struct V_8 * V_9 , struct V_40 * V_41 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
V_2 -> V_11 = & V_65 ;
F_46 ( & V_2 -> V_39 , F_39 , ( unsigned long ) V_9 ) ;
return F_25 ( V_9 , V_41 ) ;
}
static int F_47 ( struct V_8 * V_9 , struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_40 * V_66 = NULL ;
struct V_44 V_41 = {
. V_53 = V_2 -> V_53 ,
. V_3 = V_2 -> V_3 ,
. V_55 = V_2 -> V_15 . V_55 >> V_2 -> V_15 . V_57 ,
. V_56 = V_2 -> V_15 . V_56 >> V_2 -> V_15 . V_57 ,
. V_57 = V_2 -> V_15 . V_57 ,
. V_58 = V_2 -> V_15 . V_58 ,
. V_59 = V_2 -> V_15 . V_59 ,
} ;
V_9 -> V_16 . V_17 = V_2 -> V_11 -> V_16 . V_17 ;
V_66 = F_48 ( V_7 , V_67 ) ;
if ( V_66 == NULL )
goto V_68;
F_49 ( V_7 , V_50 , sizeof( V_41 ) , & V_41 ) ;
F_50 ( V_7 , V_52 , V_2 -> V_15 . V_47 ) ;
return F_51 ( V_7 , V_66 ) ;
V_68:
F_52 ( V_7 , V_66 ) ;
return - V_69 ;
}
static int F_53 ( struct V_8 * V_9 , struct V_70 * V_71 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_72 V_73 = {
. V_74 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_26 ,
. V_30 = V_2 -> V_21 . V_30 ,
. V_38 = V_2 -> V_21 . V_38 ,
. V_75 = V_2 -> V_21 . V_24 + V_2 -> V_21 . V_27 ,
} ;
return F_54 ( V_71 , & V_73 , sizeof( V_73 ) ) ;
}
static int F_55 ( struct V_8 * V_9 , unsigned long V_76 ,
struct V_6 * V_7 , struct V_77 * V_78 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
V_78 -> V_79 |= F_56 ( 1 ) ;
V_78 -> V_80 = V_2 -> V_11 -> V_81 ;
return 0 ;
}
static int F_57 ( struct V_8 * V_9 , unsigned long V_63 , struct V_8 * V_82 ,
struct V_8 * * V_83 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
if ( V_82 == NULL )
V_82 = & V_65 ;
F_32 ( V_9 ) ;
* V_83 = V_2 -> V_11 ;
V_2 -> V_11 = V_82 ;
F_33 ( * V_83 , ( * V_83 ) -> V_2 . V_29 ) ;
F_20 ( * V_83 ) ;
F_38 ( V_9 ) ;
return 0 ;
}
static struct V_8 * F_58 ( struct V_8 * V_9 , unsigned long V_63 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
return V_2 -> V_11 ;
}
static unsigned long F_59 ( struct V_8 * V_9 , T_1 V_84 )
{
return 1 ;
}
static void F_60 ( struct V_8 * V_9 , unsigned long V_63 )
{
}
static void F_61 ( struct V_8 * V_9 , struct V_85 * V_86 )
{
if ( ! V_86 -> V_87 ) {
if ( V_86 -> V_88 >= V_86 -> V_89 )
if ( V_86 -> V_90 ( V_9 , 1 , V_86 ) < 0 ) {
V_86 -> V_87 = 1 ;
return;
}
V_86 -> V_88 ++ ;
}
}
static int T_3 F_62 ( void )
{
return F_63 ( & V_91 ) ;
}
static void T_4 F_64 ( void )
{
F_65 ( & V_91 ) ;
}
