static struct V_1 * F_1 ( struct V_2 * V_2 , struct V_3 * V_4 ,
int V_5 ,
const T_1 * V_6 ,
const T_1 * V_7 )
{
struct V_8 * V_9 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_7 = V_7 -> V_10 ;
V_4 -> V_11 = V_5 ;
if ( V_6 )
V_4 -> V_6 = V_6 -> V_10 ;
V_9 = F_2 ( V_2 , V_4 ) ;
if ( ! F_3 ( V_9 ) )
return & V_9 -> V_12 ;
return F_4 ( V_9 ) ;
}
static struct V_1 * F_5 ( struct V_2 * V_2 , int V_5 ,
const T_1 * V_6 ,
const T_1 * V_7 )
{
struct V_3 V_4 ;
return F_1 ( V_2 , & V_4 , V_5 , V_6 , V_7 ) ;
}
static int F_6 ( struct V_2 * V_2 ,
T_1 * V_6 , T_1 * V_7 )
{
struct V_1 * V_12 ;
struct V_3 V_4 ;
V_12 = F_1 ( V_2 , & V_4 , 0 , NULL , V_7 ) ;
if ( F_3 ( V_12 ) )
return - V_13 ;
V_6 -> V_10 = V_4 . V_6 ;
F_7 ( V_12 ) ;
return 0 ;
}
static int F_8 ( const struct V_14 * V_15 )
{
return V_16 & V_15 -> V_17 . V_18 . V_11 ;
}
static int F_9 ( struct V_19 * V_20 , struct V_1 * V_12 ,
int V_21 )
{
return 0 ;
}
static int F_10 ( struct V_19 * V_22 , struct V_23 * V_24 ,
const struct V_14 * V_15 )
{
struct V_8 * V_9 = (struct V_8 * ) V_22 -> V_25 ;
const struct V_3 * V_4 = & V_15 -> V_17 . V_18 ;
V_22 -> V_17 . V_9 . V_26 = V_4 -> V_27 ;
V_22 -> V_17 . V_12 . V_24 = V_24 ;
F_11 ( V_24 ) ;
V_22 -> V_17 . V_9 . V_28 = V_9 -> V_28 ;
V_22 -> V_17 . V_9 . V_29 = V_9 -> V_29 & ( V_30 | V_31 |
V_32 ) ;
V_22 -> V_17 . V_9 . V_33 = V_9 -> V_33 ;
V_22 -> V_17 . V_9 . V_34 = V_9 -> V_34 ;
V_22 -> V_17 . V_9 . V_35 = V_9 -> V_35 ;
V_22 -> V_17 . V_9 . V_36 = V_9 -> V_36 ;
F_12 ( & V_22 -> V_17 . V_9 . V_37 ) ;
return 0 ;
}
static void
F_13 ( struct V_38 * V_39 , struct V_14 * V_15 , int V_40 )
{
const struct V_41 * V_42 = F_14 ( V_39 ) ;
T_2 * V_43 = F_15 ( V_39 ) + V_42 -> V_44 * 4 ;
struct V_3 * V_4 = & V_15 -> V_17 . V_18 ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_45 = V_39 -> V_46 ;
V_4 -> V_47 = F_16 ( V_39 ) -> V_24 -> V_48 ;
if ( ! F_17 ( V_42 ) ) {
switch ( V_42 -> V_49 ) {
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
if ( V_43 + 4 < V_39 -> V_55 ||
F_18 ( V_39 , V_43 + 4 - V_39 -> V_55 ) ) {
T_3 * V_56 = ( T_3 * ) V_43 ;
V_4 -> V_57 = V_56 [ ! ! V_40 ] ;
V_4 -> V_58 = V_56 [ ! V_40 ] ;
}
break;
case V_59 :
if ( F_18 ( V_39 , V_43 + 2 - V_39 -> V_55 ) ) {
T_2 * V_60 = V_43 ;
V_4 -> V_61 = V_60 [ 0 ] ;
V_4 -> V_62 = V_60 [ 1 ] ;
}
break;
case V_63 :
if ( F_18 ( V_39 , V_43 + 4 - V_39 -> V_55 ) ) {
T_4 * V_64 = ( T_4 * ) V_43 ;
V_4 -> V_65 = V_64 [ 0 ] ;
}
break;
case V_66 :
if ( F_18 ( V_39 , V_43 + 8 - V_39 -> V_55 ) ) {
T_4 * V_67 = ( T_4 * ) V_43 ;
V_4 -> V_65 = V_67 [ 1 ] ;
}
break;
case V_68 :
if ( F_18 ( V_39 , V_43 + 4 - V_39 -> V_55 ) ) {
T_3 * V_69 = ( T_3 * ) V_43 ;
V_4 -> V_65 = F_19 ( F_20 ( V_69 [ 1 ] ) ) ;
}
break;
case V_70 :
if ( F_18 ( V_39 , V_43 + 12 - V_39 -> V_55 ) ) {
T_3 * V_71 = ( T_3 * ) V_43 ;
T_4 * V_72 = ( T_4 * ) V_43 ;
if ( V_71 [ 0 ] & V_73 ) {
if ( V_71 [ 0 ] & V_74 )
V_72 ++ ;
V_4 -> V_75 = V_72 [ 1 ] ;
}
}
break;
default:
V_4 -> V_65 = 0 ;
break;
}
}
V_4 -> V_76 = V_42 -> V_49 ;
V_4 -> V_7 = V_40 ? V_42 -> V_6 : V_42 -> V_7 ;
V_4 -> V_6 = V_40 ? V_42 -> V_7 : V_42 -> V_6 ;
V_4 -> V_11 = V_42 -> V_5 ;
}
static inline int F_21 ( struct V_77 * V_78 )
{
struct V_2 * V_2 = F_22 ( V_78 , struct V_2 , V_79 . V_80 ) ;
V_81 . V_82 ( V_2 ) ;
return ( F_23 ( V_78 ) > V_78 -> V_83 * 2 ) ;
}
static void F_24 ( struct V_1 * V_12 , struct V_84 * V_85 ,
struct V_38 * V_39 , T_5 V_86 )
{
struct V_19 * V_22 = (struct V_19 * ) V_12 ;
struct V_1 * V_20 = V_22 -> V_25 ;
V_20 -> V_78 -> V_87 ( V_20 , V_85 , V_39 , V_86 ) ;
}
static void F_25 ( struct V_1 * V_12 , struct V_84 * V_85 ,
struct V_38 * V_39 )
{
struct V_19 * V_22 = (struct V_19 * ) V_12 ;
struct V_1 * V_20 = V_22 -> V_25 ;
V_20 -> V_78 -> V_88 ( V_20 , V_85 , V_39 ) ;
}
static void F_26 ( struct V_1 * V_12 )
{
struct V_19 * V_22 = (struct V_19 * ) V_12 ;
F_27 ( V_12 ) ;
F_28 ( V_22 ) ;
}
static void F_29 ( struct V_1 * V_12 , struct V_23 * V_24 ,
int V_89 )
{
if ( ! V_89 )
return;
F_30 ( V_12 , V_24 ) ;
}
static int T_6 F_31 ( struct V_2 * V_2 )
{
struct V_90 * V_91 ;
struct V_92 * V_93 ;
V_91 = V_94 ;
if ( ! F_32 ( V_2 , & V_95 ) ) {
V_91 = F_33 ( V_91 , sizeof( V_94 ) , V_96 ) ;
if ( ! V_91 )
goto V_97;
V_91 [ 0 ] . V_55 = & V_2 -> V_79 . V_80 . V_83 ;
}
V_93 = F_34 ( V_2 , L_1 , V_91 ) ;
if ( ! V_93 )
goto V_98;
V_2 -> V_99 . V_100 = V_93 ;
return 0 ;
V_98:
if ( ! F_32 ( V_2 , & V_95 ) )
F_35 ( V_91 ) ;
V_97:
return - V_101 ;
}
static void T_7 F_36 ( struct V_2 * V_2 )
{
struct V_90 * V_91 ;
if ( V_2 -> V_99 . V_100 == NULL )
return;
V_91 = V_2 -> V_99 . V_100 -> V_102 ;
F_37 ( V_2 -> V_99 . V_100 ) ;
if ( ! F_32 ( V_2 , & V_95 ) )
F_35 ( V_91 ) ;
}
static void T_8 F_38 ( void )
{
F_39 ( & V_81 ) ;
}
void T_8 F_40 ( void )
{
F_41 ( & V_80 ) ;
F_42 () ;
F_38 () ;
#ifdef F_43
F_44 ( & V_103 ) ;
#endif
}
