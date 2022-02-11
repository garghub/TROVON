static struct V_1 * F_1 ( struct V_2 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 ,
const T_1 * V_7 ,
const T_1 * V_8 ,
T_2 V_9 )
{
struct V_10 * V_11 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_8 = V_8 -> V_12 ;
V_4 -> V_13 = V_5 ;
V_4 -> V_14 = F_2 ( V_2 , V_6 ) ;
V_4 -> V_15 = V_9 ;
if ( V_7 )
V_4 -> V_7 = V_7 -> V_12 ;
V_4 -> V_16 = V_17 ;
V_11 = F_3 ( V_2 , V_4 ) ;
if ( ! F_4 ( V_11 ) )
return & V_11 -> V_18 ;
return F_5 ( V_11 ) ;
}
static struct V_1 * F_6 ( struct V_2 * V_2 , int V_5 , int V_6 ,
const T_1 * V_7 ,
const T_1 * V_8 ,
T_2 V_9 )
{
struct V_3 V_4 ;
return F_1 ( V_2 , & V_4 , V_5 , V_6 , V_7 , V_8 , V_9 ) ;
}
static int F_7 ( struct V_2 * V_2 , int V_6 ,
T_1 * V_7 , T_1 * V_8 ,
T_2 V_9 )
{
struct V_1 * V_18 ;
struct V_3 V_4 ;
V_18 = F_1 ( V_2 , & V_4 , 0 , V_6 , NULL , V_8 , V_9 ) ;
if ( F_4 ( V_18 ) )
return - V_19 ;
V_7 -> V_12 = V_4 . V_7 ;
F_8 ( V_18 ) ;
return 0 ;
}
static int F_9 ( const struct V_20 * V_21 )
{
return V_22 & V_21 -> V_23 . V_24 . V_13 ;
}
static int F_10 ( struct V_25 * V_26 , struct V_1 * V_18 ,
int V_27 )
{
return 0 ;
}
static int F_11 ( struct V_25 * V_28 , struct V_29 * V_30 ,
const struct V_20 * V_21 )
{
struct V_10 * V_11 = (struct V_10 * ) V_28 -> V_31 ;
const struct V_3 * V_4 = & V_21 -> V_23 . V_24 ;
V_28 -> V_23 . V_11 . V_32 = V_4 -> V_33 ;
V_28 -> V_23 . V_18 . V_30 = V_30 ;
F_12 ( V_30 ) ;
V_28 -> V_23 . V_11 . V_34 = V_11 -> V_34 ;
V_28 -> V_23 . V_11 . V_35 = V_11 -> V_35 & ( V_36 | V_37 |
V_38 ) ;
V_28 -> V_23 . V_11 . V_39 = V_11 -> V_39 ;
V_28 -> V_23 . V_11 . V_40 = V_11 -> V_40 ;
V_28 -> V_23 . V_11 . V_41 = V_11 -> V_41 ;
V_28 -> V_23 . V_11 . V_42 = V_11 -> V_42 ;
V_28 -> V_23 . V_11 . V_43 = V_11 -> V_43 ;
F_13 ( & V_28 -> V_23 . V_11 . V_44 ) ;
return 0 ;
}
static void
F_14 ( struct V_45 * V_46 , struct V_20 * V_21 , int V_47 )
{
const struct V_48 * V_49 = F_15 ( V_46 ) ;
T_3 * V_50 = F_16 ( V_46 ) + V_49 -> V_51 * 4 ;
struct V_3 * V_4 = & V_21 -> V_23 . V_24 ;
int V_6 = 0 ;
if ( F_17 ( V_46 ) )
V_6 = F_17 ( V_46 ) -> V_30 -> V_52 ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_15 = V_46 -> V_9 ;
V_4 -> V_14 = V_47 ? V_46 -> V_53 : V_6 ;
if ( ! F_18 ( V_49 ) ) {
switch ( V_49 -> V_54 ) {
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
if ( V_50 + 4 < V_46 -> V_60 ||
F_19 ( V_46 , V_50 + 4 - V_46 -> V_60 ) ) {
T_4 * V_61 ;
V_50 = F_16 ( V_46 ) + V_49 -> V_51 * 4 ;
V_61 = ( T_4 * ) V_50 ;
V_4 -> V_62 = V_61 [ ! ! V_47 ] ;
V_4 -> V_63 = V_61 [ ! V_47 ] ;
}
break;
case V_64 :
if ( V_50 + 2 < V_46 -> V_60 ||
F_19 ( V_46 , V_50 + 2 - V_46 -> V_60 ) ) {
T_3 * V_65 ;
V_50 = F_16 ( V_46 ) + V_49 -> V_51 * 4 ;
V_65 = V_50 ;
V_4 -> V_66 = V_65 [ 0 ] ;
V_4 -> V_67 = V_65 [ 1 ] ;
}
break;
case V_68 :
if ( V_50 + 4 < V_46 -> V_60 ||
F_19 ( V_46 , V_50 + 4 - V_46 -> V_60 ) ) {
T_5 * V_69 ;
V_50 = F_16 ( V_46 ) + V_49 -> V_51 * 4 ;
V_69 = ( T_5 * ) V_50 ;
V_4 -> V_70 = V_69 [ 0 ] ;
}
break;
case V_71 :
if ( V_50 + 8 < V_46 -> V_60 ||
F_19 ( V_46 , V_50 + 8 - V_46 -> V_60 ) ) {
T_5 * V_72 ;
V_50 = F_16 ( V_46 ) + V_49 -> V_51 * 4 ;
V_72 = ( T_5 * ) V_50 ;
V_4 -> V_70 = V_72 [ 1 ] ;
}
break;
case V_73 :
if ( V_50 + 4 < V_46 -> V_60 ||
F_19 ( V_46 , V_50 + 4 - V_46 -> V_60 ) ) {
T_4 * V_74 ;
V_50 = F_16 ( V_46 ) + V_49 -> V_51 * 4 ;
V_74 = ( T_4 * ) V_50 ;
V_4 -> V_70 = F_20 ( F_21 ( V_74 [ 1 ] ) ) ;
}
break;
case V_75 :
if ( V_50 + 12 < V_46 -> V_60 ||
F_19 ( V_46 , V_50 + 12 - V_46 -> V_60 ) ) {
T_4 * V_76 ;
T_5 * V_77 ;
V_50 = F_16 ( V_46 ) + V_49 -> V_51 * 4 ;
V_76 = ( T_4 * ) V_50 ;
V_77 = ( T_5 * ) V_50 ;
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
V_4 -> V_81 = V_49 -> V_54 ;
V_4 -> V_8 = V_47 ? V_49 -> V_7 : V_49 -> V_8 ;
V_4 -> V_7 = V_47 ? V_49 -> V_8 : V_49 -> V_7 ;
V_4 -> V_13 = V_49 -> V_5 ;
}
static void F_22 ( struct V_1 * V_18 , struct V_82 * V_83 ,
struct V_45 * V_46 , T_2 V_84 )
{
struct V_25 * V_28 = (struct V_25 * ) V_18 ;
struct V_1 * V_26 = V_28 -> V_31 ;
V_26 -> V_85 -> V_86 ( V_26 , V_83 , V_46 , V_84 ) ;
}
static void F_23 ( struct V_1 * V_18 , struct V_82 * V_83 ,
struct V_45 * V_46 )
{
struct V_25 * V_28 = (struct V_25 * ) V_18 ;
struct V_1 * V_26 = V_28 -> V_31 ;
V_26 -> V_85 -> V_87 ( V_26 , V_83 , V_46 ) ;
}
static void F_24 ( struct V_1 * V_18 )
{
struct V_25 * V_28 = (struct V_25 * ) V_18 ;
F_25 ( V_18 ) ;
F_26 ( V_28 ) ;
}
static void F_27 ( struct V_1 * V_18 , struct V_29 * V_30 ,
int V_88 )
{
if ( ! V_88 )
return;
F_28 ( V_18 , V_30 ) ;
}
static T_6 int F_29 ( struct V_2 * V_2 )
{
struct V_89 * V_90 ;
struct V_91 * V_92 ;
V_90 = V_93 ;
if ( ! F_30 ( V_2 , & V_94 ) ) {
V_90 = F_31 ( V_90 , sizeof( V_93 ) , V_95 ) ;
if ( ! V_90 )
goto V_96;
V_90 [ 0 ] . V_60 = & V_2 -> V_97 . V_98 . V_99 ;
}
V_92 = F_32 ( V_2 , L_1 , V_90 ) ;
if ( ! V_92 )
goto V_100;
V_2 -> V_101 . V_102 = V_92 ;
return 0 ;
V_100:
if ( ! F_30 ( V_2 , & V_94 ) )
F_33 ( V_90 ) ;
V_96:
return - V_103 ;
}
static T_7 void F_34 ( struct V_2 * V_2 )
{
struct V_89 * V_90 ;
if ( ! V_2 -> V_101 . V_102 )
return;
V_90 = V_2 -> V_101 . V_102 -> V_104 ;
F_35 ( V_2 -> V_101 . V_102 ) ;
if ( ! F_30 ( V_2 , & V_94 ) )
F_33 ( V_90 ) ;
}
static inline int F_29 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline void F_34 ( struct V_2 * V_2 )
{
}
static int T_6 F_36 ( struct V_2 * V_2 )
{
int V_105 ;
memcpy ( & V_2 -> V_97 . V_98 , & V_106 ,
sizeof( V_106 ) ) ;
V_105 = F_37 ( & V_2 -> V_97 . V_98 ) ;
if ( V_105 )
return V_105 ;
V_105 = F_29 ( V_2 ) ;
if ( V_105 )
F_38 ( & V_2 -> V_97 . V_98 ) ;
return V_105 ;
}
static void T_7 F_39 ( struct V_2 * V_2 )
{
F_34 ( V_2 ) ;
F_38 ( & V_2 -> V_97 . V_98 ) ;
}
static void T_8 F_40 ( void )
{
F_41 ( & V_107 , V_108 ) ;
}
void T_8 F_42 ( void )
{
F_43 () ;
F_40 () ;
F_44 () ;
F_45 ( & V_109 ) ;
}
