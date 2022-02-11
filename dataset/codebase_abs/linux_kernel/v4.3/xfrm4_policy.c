static struct V_1 * F_1 ( struct V_2 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 ,
const T_1 * V_7 ,
const T_1 * V_8 )
{
struct V_9 * V_10 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_8 = V_8 -> V_11 ;
V_4 -> V_12 = V_5 ;
V_4 -> V_13 = V_6 ;
if ( V_7 )
V_4 -> V_7 = V_7 -> V_11 ;
V_4 -> V_14 = V_15 ;
V_10 = F_2 ( V_2 , V_4 ) ;
if ( ! F_3 ( V_10 ) )
return & V_10 -> V_16 ;
return F_4 ( V_10 ) ;
}
static struct V_1 * F_5 ( struct V_2 * V_2 , int V_5 , int V_6 ,
const T_1 * V_7 ,
const T_1 * V_8 )
{
struct V_3 V_4 ;
return F_1 ( V_2 , & V_4 , V_5 , V_6 , V_7 , V_8 ) ;
}
static int F_6 ( struct V_2 * V_2 , int V_6 ,
T_1 * V_7 , T_1 * V_8 )
{
struct V_1 * V_16 ;
struct V_3 V_4 ;
V_16 = F_1 ( V_2 , & V_4 , 0 , V_6 , NULL , V_8 ) ;
if ( F_3 ( V_16 ) )
return - V_17 ;
V_7 -> V_11 = V_4 . V_7 ;
F_7 ( V_16 ) ;
return 0 ;
}
static int F_8 ( const struct V_18 * V_19 )
{
return V_20 & V_19 -> V_21 . V_22 . V_12 ;
}
static int F_9 ( struct V_23 * V_24 , struct V_1 * V_16 ,
int V_25 )
{
return 0 ;
}
static int F_10 ( struct V_23 * V_26 , struct V_27 * V_28 ,
const struct V_18 * V_19 )
{
struct V_9 * V_10 = (struct V_9 * ) V_26 -> V_29 ;
const struct V_3 * V_4 = & V_19 -> V_21 . V_22 ;
V_26 -> V_21 . V_10 . V_30 = V_4 -> V_31 ;
V_26 -> V_21 . V_16 . V_28 = V_28 ;
F_11 ( V_28 ) ;
V_26 -> V_21 . V_10 . V_32 = V_10 -> V_32 ;
V_26 -> V_21 . V_10 . V_33 = V_10 -> V_33 & ( V_34 | V_35 |
V_36 ) ;
V_26 -> V_21 . V_10 . V_37 = V_10 -> V_37 ;
V_26 -> V_21 . V_10 . V_38 = V_10 -> V_38 ;
V_26 -> V_21 . V_10 . V_39 = V_10 -> V_39 ;
V_26 -> V_21 . V_10 . V_40 = V_10 -> V_40 ;
F_12 ( & V_26 -> V_21 . V_10 . V_41 ) ;
return 0 ;
}
static void
F_13 ( struct V_42 * V_43 , struct V_18 * V_19 , int V_44 )
{
const struct V_45 * V_46 = F_14 ( V_43 ) ;
T_2 * V_47 = F_15 ( V_43 ) + V_46 -> V_48 * 4 ;
struct V_3 * V_4 = & V_19 -> V_21 . V_22 ;
int V_6 = 0 ;
if ( F_16 ( V_43 ) ) {
V_6 = F_17 ( F_16 ( V_43 ) -> V_28 ) ?
: F_16 ( V_43 ) -> V_28 -> V_49 ;
}
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_50 = V_43 -> V_51 ;
V_4 -> V_13 = V_44 ? V_43 -> V_52 : V_6 ;
if ( ! F_18 ( V_46 ) ) {
switch ( V_46 -> V_53 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
if ( V_47 + 4 < V_43 -> V_59 ||
F_19 ( V_43 , V_47 + 4 - V_43 -> V_59 ) ) {
T_3 * V_60 = ( T_3 * ) V_47 ;
V_4 -> V_61 = V_60 [ ! ! V_44 ] ;
V_4 -> V_62 = V_60 [ ! V_44 ] ;
}
break;
case V_63 :
if ( F_19 ( V_43 , V_47 + 2 - V_43 -> V_59 ) ) {
T_2 * V_64 = V_47 ;
V_4 -> V_65 = V_64 [ 0 ] ;
V_4 -> V_66 = V_64 [ 1 ] ;
}
break;
case V_67 :
if ( F_19 ( V_43 , V_47 + 4 - V_43 -> V_59 ) ) {
T_4 * V_68 = ( T_4 * ) V_47 ;
V_4 -> V_69 = V_68 [ 0 ] ;
}
break;
case V_70 :
if ( F_19 ( V_43 , V_47 + 8 - V_43 -> V_59 ) ) {
T_4 * V_71 = ( T_4 * ) V_47 ;
V_4 -> V_69 = V_71 [ 1 ] ;
}
break;
case V_72 :
if ( F_19 ( V_43 , V_47 + 4 - V_43 -> V_59 ) ) {
T_3 * V_73 = ( T_3 * ) V_47 ;
V_4 -> V_69 = F_20 ( F_21 ( V_73 [ 1 ] ) ) ;
}
break;
case V_74 :
if ( F_19 ( V_43 , V_47 + 12 - V_43 -> V_59 ) ) {
T_3 * V_75 = ( T_3 * ) V_47 ;
T_4 * V_76 = ( T_4 * ) V_47 ;
if ( V_75 [ 0 ] & V_77 ) {
if ( V_75 [ 0 ] & V_78 )
V_76 ++ ;
V_4 -> V_79 = V_76 [ 1 ] ;
}
}
break;
default:
V_4 -> V_69 = 0 ;
break;
}
}
V_4 -> V_80 = V_46 -> V_53 ;
V_4 -> V_8 = V_44 ? V_46 -> V_7 : V_46 -> V_8 ;
V_4 -> V_7 = V_44 ? V_46 -> V_8 : V_46 -> V_7 ;
V_4 -> V_12 = V_46 -> V_5 ;
}
static inline int F_22 ( struct V_81 * V_82 )
{
struct V_2 * V_2 = F_23 ( V_82 , struct V_2 , V_83 . V_84 ) ;
V_85 . V_86 ( V_2 ) ;
return ( F_24 ( V_82 ) > V_82 -> V_87 * 2 ) ;
}
static void F_25 ( struct V_1 * V_16 , struct V_88 * V_89 ,
struct V_42 * V_43 , T_5 V_90 )
{
struct V_23 * V_26 = (struct V_23 * ) V_16 ;
struct V_1 * V_24 = V_26 -> V_29 ;
V_24 -> V_82 -> V_91 ( V_24 , V_89 , V_43 , V_90 ) ;
}
static void F_26 ( struct V_1 * V_16 , struct V_88 * V_89 ,
struct V_42 * V_43 )
{
struct V_23 * V_26 = (struct V_23 * ) V_16 ;
struct V_1 * V_24 = V_26 -> V_29 ;
V_24 -> V_82 -> V_92 ( V_24 , V_89 , V_43 ) ;
}
static void F_27 ( struct V_1 * V_16 )
{
struct V_23 * V_26 = (struct V_23 * ) V_16 ;
F_28 ( V_16 ) ;
F_29 ( V_26 ) ;
}
static void F_30 ( struct V_1 * V_16 , struct V_27 * V_28 ,
int V_93 )
{
if ( ! V_93 )
return;
F_31 ( V_16 , V_28 ) ;
}
static int T_6 F_32 ( struct V_2 * V_2 )
{
struct V_94 * V_95 ;
struct V_96 * V_97 ;
V_95 = V_98 ;
if ( ! F_33 ( V_2 , & V_99 ) ) {
V_95 = F_34 ( V_95 , sizeof( V_98 ) , V_100 ) ;
if ( ! V_95 )
goto V_101;
V_95 [ 0 ] . V_59 = & V_2 -> V_83 . V_84 . V_87 ;
}
V_97 = F_35 ( V_2 , L_1 , V_95 ) ;
if ( ! V_97 )
goto V_102;
V_2 -> V_103 . V_104 = V_97 ;
return 0 ;
V_102:
if ( ! F_33 ( V_2 , & V_99 ) )
F_36 ( V_95 ) ;
V_101:
return - V_105 ;
}
static void T_7 F_37 ( struct V_2 * V_2 )
{
struct V_94 * V_95 ;
if ( ! V_2 -> V_103 . V_104 )
return;
V_95 = V_2 -> V_103 . V_104 -> V_106 ;
F_38 ( V_2 -> V_103 . V_104 ) ;
if ( ! F_33 ( V_2 , & V_99 ) )
F_36 ( V_95 ) ;
}
static void T_8 F_39 ( void )
{
F_40 ( & V_85 ) ;
}
void T_8 F_41 ( void )
{
F_42 ( & V_84 ) ;
F_43 () ;
F_39 () ;
F_44 () ;
#ifdef F_45
F_46 ( & V_107 ) ;
#endif
}
