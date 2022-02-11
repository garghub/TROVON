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
V_2 -> V_13 . V_14 = F_5 ( & V_2 -> V_13 , V_10 -> V_15 . V_16 ) ;
if ( F_6 ( & V_2 -> V_13 ) )
F_7 ( & V_2 -> V_13 ) ;
switch ( F_8 ( & V_2 -> V_13 , V_2 -> V_13 . V_14 ) ) {
case V_17 :
break;
case V_18 :
V_9 -> V_15 . V_19 ++ ;
if ( ! F_1 ( V_2 ) || ! F_9 ( V_7 ) ) {
V_2 -> V_20 . V_21 ++ ;
goto V_22;
}
V_2 -> V_20 . V_23 ++ ;
break;
case V_24 :
V_9 -> V_15 . V_19 ++ ;
if ( F_2 ( V_2 ) || ! F_1 ( V_2 ) ||
! F_9 ( V_7 ) ) {
V_2 -> V_20 . V_25 ++ ;
goto V_22;
}
V_2 -> V_20 . V_26 ++ ;
break;
}
V_12 = F_10 ( V_7 , V_10 ) ;
if ( F_11 ( V_12 == V_27 ) ) {
V_9 -> V_2 . V_28 ++ ;
} else if ( F_12 ( V_12 ) ) {
V_2 -> V_20 . V_29 ++ ;
V_9 -> V_15 . V_30 ++ ;
}
return V_12 ;
V_22:
F_13 ( V_7 , V_9 ) ;
return V_31 ;
}
static struct V_6 * F_14 ( struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_8 * V_10 = V_2 -> V_11 ;
V_7 = V_10 -> V_32 ( V_10 ) ;
if ( V_7 ) {
F_15 ( V_9 , V_7 ) ;
V_9 -> V_2 . V_28 -- ;
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
return V_10 -> V_33 -> V_34 ( V_10 ) ;
}
static unsigned int F_18 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_8 * V_10 = V_2 -> V_11 ;
unsigned int V_35 ;
if ( V_10 -> V_33 -> V_36 && ( V_35 = V_10 -> V_33 -> V_36 ( V_10 ) ) > 0 ) {
V_2 -> V_20 . V_37 ++ ;
V_9 -> V_15 . V_30 ++ ;
V_9 -> V_2 . V_28 -- ;
return V_35 ;
}
if ( ! F_6 ( & V_2 -> V_13 ) )
F_16 ( & V_2 -> V_13 ) ;
return 0 ;
}
static void F_19 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
F_20 ( V_2 -> V_11 ) ;
V_9 -> V_2 . V_28 = 0 ;
F_21 ( & V_2 -> V_13 ) ;
}
static void F_22 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
F_23 ( V_2 -> V_11 ) ;
}
static int F_24 ( struct V_8 * V_9 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_38 * V_40 [ V_41 + 1 ] ;
struct V_42 * V_43 ;
struct V_8 * V_10 = NULL ;
int V_44 ;
if ( V_39 == NULL )
return - V_45 ;
V_44 = F_25 ( V_40 , V_41 , V_39 , V_46 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_40 [ V_47 ] == NULL ||
V_40 [ V_48 ] == NULL )
return - V_45 ;
V_43 = F_26 ( V_40 [ V_47 ] ) ;
if ( V_43 -> V_49 > 0 ) {
V_10 = F_27 ( V_9 , & V_50 , V_43 -> V_49 ) ;
if ( F_28 ( V_10 ) )
return F_29 ( V_10 ) ;
}
F_30 ( V_9 ) ;
V_2 -> V_3 = V_43 -> V_3 ;
V_2 -> V_49 = V_43 -> V_49 ;
if ( V_10 ) {
F_31 ( V_2 -> V_11 , V_2 -> V_11 -> V_2 . V_28 ) ;
F_23 ( V_2 -> V_11 ) ;
V_2 -> V_11 = V_10 ;
}
F_32 ( & V_2 -> V_13 , V_43 -> V_51 , V_43 -> V_52 , V_43 -> V_53 ,
V_43 -> V_54 , V_43 -> V_55 ,
F_26 ( V_40 [ V_48 ] ) ) ;
if ( ! V_2 -> V_11 -> V_2 . V_28 )
F_16 ( & V_2 -> V_13 ) ;
F_33 ( V_9 ) ;
return 0 ;
}
static int F_34 ( struct V_8 * V_9 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
V_2 -> V_11 = & V_56 ;
return F_24 ( V_9 , V_39 ) ;
}
static int F_35 ( struct V_8 * V_9 , struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_38 * V_57 = NULL ;
struct V_42 V_39 = {
. V_49 = V_2 -> V_49 ,
. V_3 = V_2 -> V_3 ,
. V_51 = V_2 -> V_13 . V_51 >> V_2 -> V_13 . V_53 ,
. V_52 = V_2 -> V_13 . V_52 >> V_2 -> V_13 . V_53 ,
. V_53 = V_2 -> V_13 . V_53 ,
. V_54 = V_2 -> V_13 . V_54 ,
. V_55 = V_2 -> V_13 . V_55 ,
} ;
V_9 -> V_15 . V_16 = V_2 -> V_11 -> V_15 . V_16 ;
V_57 = F_36 ( V_7 , V_58 ) ;
if ( V_57 == NULL )
goto V_59;
F_37 ( V_7 , V_47 , sizeof( V_39 ) , & V_39 ) ;
return F_38 ( V_7 , V_57 ) ;
V_59:
F_39 ( V_7 , V_57 ) ;
return - V_60 ;
}
static int F_40 ( struct V_8 * V_9 , struct V_61 * V_62 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
struct V_63 V_64 = {
. V_65 = V_2 -> V_20 . V_21 + V_2 -> V_20 . V_25 ,
. V_29 = V_2 -> V_20 . V_29 ,
. V_37 = V_2 -> V_20 . V_37 ,
. V_66 = V_2 -> V_20 . V_23 + V_2 -> V_20 . V_26 ,
} ;
return F_41 ( V_62 , & V_64 , sizeof( V_64 ) ) ;
}
static int F_42 ( struct V_8 * V_9 , unsigned long V_67 ,
struct V_6 * V_7 , struct V_68 * V_69 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
V_69 -> V_70 |= F_43 ( 1 ) ;
V_69 -> V_71 = V_2 -> V_11 -> V_72 ;
return 0 ;
}
static int F_44 ( struct V_8 * V_9 , unsigned long V_73 , struct V_8 * V_74 ,
struct V_8 * * V_75 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
if ( V_74 == NULL )
V_74 = & V_56 ;
F_30 ( V_9 ) ;
* V_75 = V_2 -> V_11 ;
V_2 -> V_11 = V_74 ;
F_31 ( * V_75 , ( * V_75 ) -> V_2 . V_28 ) ;
F_20 ( * V_75 ) ;
F_33 ( V_9 ) ;
return 0 ;
}
static struct V_8 * F_45 ( struct V_8 * V_9 , unsigned long V_73 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
return V_2 -> V_11 ;
}
static unsigned long F_46 ( struct V_8 * V_9 , T_1 V_76 )
{
return 1 ;
}
static void F_47 ( struct V_8 * V_9 , unsigned long V_73 )
{
}
static void F_48 ( struct V_8 * V_9 , struct V_77 * V_78 )
{
if ( ! V_78 -> V_79 ) {
if ( V_78 -> V_80 >= V_78 -> V_81 )
if ( V_78 -> V_82 ( V_9 , 1 , V_78 ) < 0 ) {
V_78 -> V_79 = 1 ;
return;
}
V_78 -> V_80 ++ ;
}
}
static int T_2 F_49 ( void )
{
return F_50 ( & V_83 ) ;
}
static void T_3 F_51 ( void )
{
F_52 ( & V_83 ) ;
}
