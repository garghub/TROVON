static struct V_1 * F_1 ( struct V_2 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 ,
const T_1 * V_7 ,
const T_1 * V_8 )
{
struct V_9 * V_10 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_8 = V_8 -> V_11 ;
V_4 -> V_12 = V_5 ;
V_4 -> V_13 = F_2 ( V_2 , V_6 ) ;
if ( V_7 )
V_4 -> V_7 = V_7 -> V_11 ;
V_4 -> V_14 = V_15 ;
V_10 = F_3 ( V_2 , V_4 ) ;
if ( ! F_4 ( V_10 ) )
return & V_10 -> V_16 ;
return F_5 ( V_10 ) ;
}
static struct V_1 * F_6 ( struct V_2 * V_2 , int V_5 , int V_6 ,
const T_1 * V_7 ,
const T_1 * V_8 )
{
struct V_3 V_4 ;
return F_1 ( V_2 , & V_4 , V_5 , V_6 , V_7 , V_8 ) ;
}
static int F_7 ( struct V_2 * V_2 , int V_6 ,
T_1 * V_7 , T_1 * V_8 )
{
struct V_1 * V_16 ;
struct V_3 V_4 ;
V_16 = F_1 ( V_2 , & V_4 , 0 , V_6 , NULL , V_8 ) ;
if ( F_4 ( V_16 ) )
return - V_17 ;
V_7 -> V_11 = V_4 . V_7 ;
F_8 ( V_16 ) ;
return 0 ;
}
static int F_9 ( const struct V_18 * V_19 )
{
return V_20 & V_19 -> V_21 . V_22 . V_12 ;
}
static int F_10 ( struct V_23 * V_24 , struct V_1 * V_16 ,
int V_25 )
{
return 0 ;
}
static int F_11 ( struct V_23 * V_26 , struct V_27 * V_28 ,
const struct V_18 * V_19 )
{
struct V_9 * V_10 = (struct V_9 * ) V_26 -> V_29 ;
const struct V_3 * V_4 = & V_19 -> V_21 . V_22 ;
V_26 -> V_21 . V_10 . V_30 = V_4 -> V_31 ;
V_26 -> V_21 . V_16 . V_28 = V_28 ;
F_12 ( V_28 ) ;
V_26 -> V_21 . V_10 . V_32 = V_10 -> V_32 ;
V_26 -> V_21 . V_10 . V_33 = V_10 -> V_33 & ( V_34 | V_35 |
V_36 ) ;
V_26 -> V_21 . V_10 . V_37 = V_10 -> V_37 ;
V_26 -> V_21 . V_10 . V_38 = V_10 -> V_38 ;
V_26 -> V_21 . V_10 . V_39 = V_10 -> V_39 ;
V_26 -> V_21 . V_10 . V_40 = V_10 -> V_40 ;
V_26 -> V_21 . V_10 . V_41 = V_10 -> V_41 ;
F_13 ( & V_26 -> V_21 . V_10 . V_42 ) ;
return 0 ;
}
static void
F_14 ( struct V_43 * V_44 , struct V_18 * V_19 , int V_45 )
{
const struct V_46 * V_47 = F_15 ( V_44 ) ;
T_2 * V_48 = F_16 ( V_44 ) + V_47 -> V_49 * 4 ;
struct V_3 * V_4 = & V_19 -> V_21 . V_22 ;
int V_6 = 0 ;
if ( F_17 ( V_44 ) )
V_6 = F_17 ( V_44 ) -> V_28 -> V_50 ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_51 = V_44 -> V_52 ;
V_4 -> V_13 = V_45 ? V_44 -> V_53 : V_6 ;
if ( ! F_18 ( V_47 ) ) {
switch ( V_47 -> V_54 ) {
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
if ( V_48 + 4 < V_44 -> V_60 ||
F_19 ( V_44 , V_48 + 4 - V_44 -> V_60 ) ) {
T_3 * V_61 ;
V_48 = F_16 ( V_44 ) + V_47 -> V_49 * 4 ;
V_61 = ( T_3 * ) V_48 ;
V_4 -> V_62 = V_61 [ ! ! V_45 ] ;
V_4 -> V_63 = V_61 [ ! V_45 ] ;
}
break;
case V_64 :
if ( V_48 + 2 < V_44 -> V_60 ||
F_19 ( V_44 , V_48 + 2 - V_44 -> V_60 ) ) {
T_2 * V_65 ;
V_48 = F_16 ( V_44 ) + V_47 -> V_49 * 4 ;
V_65 = V_48 ;
V_4 -> V_66 = V_65 [ 0 ] ;
V_4 -> V_67 = V_65 [ 1 ] ;
}
break;
case V_68 :
if ( V_48 + 4 < V_44 -> V_60 ||
F_19 ( V_44 , V_48 + 4 - V_44 -> V_60 ) ) {
T_4 * V_69 ;
V_48 = F_16 ( V_44 ) + V_47 -> V_49 * 4 ;
V_69 = ( T_4 * ) V_48 ;
V_4 -> V_70 = V_69 [ 0 ] ;
}
break;
case V_71 :
if ( V_48 + 8 < V_44 -> V_60 ||
F_19 ( V_44 , V_48 + 8 - V_44 -> V_60 ) ) {
T_4 * V_72 ;
V_48 = F_16 ( V_44 ) + V_47 -> V_49 * 4 ;
V_72 = ( T_4 * ) V_48 ;
V_4 -> V_70 = V_72 [ 1 ] ;
}
break;
case V_73 :
if ( V_48 + 4 < V_44 -> V_60 ||
F_19 ( V_44 , V_48 + 4 - V_44 -> V_60 ) ) {
T_3 * V_74 ;
V_48 = F_16 ( V_44 ) + V_47 -> V_49 * 4 ;
V_74 = ( T_3 * ) V_48 ;
V_4 -> V_70 = F_20 ( F_21 ( V_74 [ 1 ] ) ) ;
}
break;
case V_75 :
if ( V_48 + 12 < V_44 -> V_60 ||
F_19 ( V_44 , V_48 + 12 - V_44 -> V_60 ) ) {
T_3 * V_76 ;
T_4 * V_77 ;
V_48 = F_16 ( V_44 ) + V_47 -> V_49 * 4 ;
V_76 = ( T_3 * ) V_48 ;
V_77 = ( T_4 * ) V_48 ;
if ( V_76 [ 0 ] & V_78 ) {
if ( V_76 [ 0 ] & V_79 )
V_77 ++ ;
V_4 -> V_80 = V_77 [ 1 ] ;
}
}
break;
default:
V_4 -> V_70 = 0 ;
break;
}
}
V_4 -> V_81 = V_47 -> V_54 ;
V_4 -> V_8 = V_45 ? V_47 -> V_7 : V_47 -> V_8 ;
V_4 -> V_7 = V_45 ? V_47 -> V_8 : V_47 -> V_7 ;
V_4 -> V_12 = V_47 -> V_5 ;
}
static inline int F_22 ( struct V_82 * V_83 )
{
struct V_2 * V_2 = F_23 ( V_83 , struct V_2 , V_84 . V_85 ) ;
V_86 . V_87 ( V_2 ) ;
return ( F_24 ( V_83 ) > V_83 -> V_88 * 2 ) ;
}
static void F_25 ( struct V_1 * V_16 , struct V_89 * V_90 ,
struct V_43 * V_44 , T_5 V_91 )
{
struct V_23 * V_26 = (struct V_23 * ) V_16 ;
struct V_1 * V_24 = V_26 -> V_29 ;
V_24 -> V_83 -> V_92 ( V_24 , V_90 , V_44 , V_91 ) ;
}
static void F_26 ( struct V_1 * V_16 , struct V_89 * V_90 ,
struct V_43 * V_44 )
{
struct V_23 * V_26 = (struct V_23 * ) V_16 ;
struct V_1 * V_24 = V_26 -> V_29 ;
V_24 -> V_83 -> V_93 ( V_24 , V_90 , V_44 ) ;
}
static void F_27 ( struct V_1 * V_16 )
{
struct V_23 * V_26 = (struct V_23 * ) V_16 ;
F_28 ( V_16 ) ;
F_29 ( V_26 ) ;
}
static void F_30 ( struct V_1 * V_16 , struct V_27 * V_28 ,
int V_94 )
{
if ( ! V_94 )
return;
F_31 ( V_16 , V_28 ) ;
}
static T_6 int F_32 ( struct V_2 * V_2 )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
V_96 = V_99 ;
if ( ! F_33 ( V_2 , & V_100 ) ) {
V_96 = F_34 ( V_96 , sizeof( V_99 ) , V_101 ) ;
if ( ! V_96 )
goto V_102;
V_96 [ 0 ] . V_60 = & V_2 -> V_84 . V_85 . V_88 ;
}
V_98 = F_35 ( V_2 , L_1 , V_96 ) ;
if ( ! V_98 )
goto V_103;
V_2 -> V_104 . V_105 = V_98 ;
return 0 ;
V_103:
if ( ! F_33 ( V_2 , & V_100 ) )
F_36 ( V_96 ) ;
V_102:
return - V_106 ;
}
static T_7 void F_37 ( struct V_2 * V_2 )
{
struct V_95 * V_96 ;
if ( ! V_2 -> V_104 . V_105 )
return;
V_96 = V_2 -> V_104 . V_105 -> V_107 ;
F_38 ( V_2 -> V_104 . V_105 ) ;
if ( ! F_33 ( V_2 , & V_100 ) )
F_36 ( V_96 ) ;
}
static inline int F_32 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline void F_37 ( struct V_2 * V_2 )
{
}
static int T_6 F_39 ( struct V_2 * V_2 )
{
int V_108 ;
memcpy ( & V_2 -> V_84 . V_85 , & V_109 ,
sizeof( V_109 ) ) ;
V_108 = F_40 ( & V_2 -> V_84 . V_85 ) ;
if ( V_108 )
return V_108 ;
V_108 = F_32 ( V_2 ) ;
if ( V_108 )
F_41 ( & V_2 -> V_84 . V_85 ) ;
return V_108 ;
}
static void T_7 F_42 ( struct V_2 * V_2 )
{
F_37 ( V_2 ) ;
F_41 ( & V_2 -> V_84 . V_85 ) ;
}
static void T_8 F_43 ( void )
{
F_44 ( & V_86 ) ;
}
void T_8 F_45 ( void )
{
F_46 () ;
F_43 () ;
F_47 () ;
F_48 ( & V_110 ) ;
}
