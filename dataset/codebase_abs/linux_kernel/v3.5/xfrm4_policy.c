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
V_22 -> V_17 . V_9 . V_26 = V_4 -> V_7 ;
V_22 -> V_17 . V_9 . V_27 = V_4 -> V_6 ;
V_22 -> V_17 . V_9 . V_28 = V_4 -> V_11 ;
V_22 -> V_17 . V_9 . V_29 = V_4 -> V_30 ;
V_22 -> V_17 . V_9 . V_31 = V_4 -> V_30 ;
V_22 -> V_17 . V_9 . V_32 = V_4 -> V_33 ;
V_22 -> V_17 . V_9 . V_34 = V_4 -> V_35 ;
V_22 -> V_17 . V_12 . V_24 = V_24 ;
F_11 ( V_24 ) ;
V_22 -> V_17 . V_9 . V_36 = V_9 -> V_36 ;
if ( V_9 -> V_36 )
F_12 ( & V_9 -> V_36 -> V_37 ) ;
V_22 -> V_17 . V_9 . V_38 = V_9 -> V_38 & ( V_39 | V_40 |
V_41 ) ;
V_22 -> V_17 . V_9 . V_42 = V_9 -> V_42 ;
V_22 -> V_17 . V_9 . V_43 = V_9 -> V_43 ;
V_22 -> V_17 . V_9 . V_44 = V_9 -> V_44 ;
V_22 -> V_17 . V_9 . V_45 = V_9 -> V_45 ;
V_22 -> V_17 . V_9 . V_46 = V_9 -> V_46 ;
return 0 ;
}
static void
F_13 ( struct V_47 * V_48 , struct V_14 * V_15 , int V_49 )
{
const struct V_50 * V_51 = F_14 ( V_48 ) ;
T_2 * V_52 = F_15 ( V_48 ) + V_51 -> V_53 * 4 ;
struct V_3 * V_4 = & V_15 -> V_17 . V_18 ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_35 = V_48 -> V_54 ;
if ( ! F_16 ( V_51 ) ) {
switch ( V_51 -> V_55 ) {
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
if ( V_52 + 4 < V_48 -> V_61 ||
F_17 ( V_48 , V_52 + 4 - V_48 -> V_61 ) ) {
T_3 * V_62 = ( T_3 * ) V_52 ;
V_4 -> V_63 = V_62 [ ! ! V_49 ] ;
V_4 -> V_64 = V_62 [ ! V_49 ] ;
}
break;
case V_65 :
if ( F_17 ( V_48 , V_52 + 2 - V_48 -> V_61 ) ) {
T_2 * V_66 = V_52 ;
V_4 -> V_67 = V_66 [ 0 ] ;
V_4 -> V_68 = V_66 [ 1 ] ;
}
break;
case V_69 :
if ( F_17 ( V_48 , V_52 + 4 - V_48 -> V_61 ) ) {
T_4 * V_70 = ( T_4 * ) V_52 ;
V_4 -> V_71 = V_70 [ 0 ] ;
}
break;
case V_72 :
if ( F_17 ( V_48 , V_52 + 8 - V_48 -> V_61 ) ) {
T_4 * V_73 = ( T_4 * ) V_52 ;
V_4 -> V_71 = V_73 [ 1 ] ;
}
break;
case V_74 :
if ( F_17 ( V_48 , V_52 + 4 - V_48 -> V_61 ) ) {
T_3 * V_75 = ( T_3 * ) V_52 ;
V_4 -> V_71 = F_18 ( F_19 ( V_75 [ 1 ] ) ) ;
}
break;
case V_76 :
if ( F_17 ( V_48 , V_52 + 12 - V_48 -> V_61 ) ) {
T_3 * V_77 = ( T_3 * ) V_52 ;
T_4 * V_78 = ( T_4 * ) V_52 ;
if ( V_77 [ 0 ] & V_79 ) {
if ( V_77 [ 0 ] & V_80 )
V_78 ++ ;
V_4 -> V_81 = V_78 [ 1 ] ;
}
}
break;
default:
V_4 -> V_71 = 0 ;
break;
}
}
V_4 -> V_82 = V_51 -> V_55 ;
V_4 -> V_7 = V_49 ? V_51 -> V_6 : V_51 -> V_7 ;
V_4 -> V_6 = V_49 ? V_51 -> V_7 : V_51 -> V_6 ;
V_4 -> V_11 = V_51 -> V_5 ;
}
static inline int F_20 ( struct V_83 * V_84 )
{
struct V_2 * V_2 = F_21 ( V_84 , struct V_2 , V_85 . V_86 ) ;
V_87 . V_88 ( V_2 ) ;
return ( F_22 ( V_84 ) > V_84 -> V_89 * 2 ) ;
}
static void F_23 ( struct V_1 * V_12 , T_5 V_90 )
{
struct V_19 * V_22 = (struct V_19 * ) V_12 ;
struct V_1 * V_20 = V_22 -> V_25 ;
V_20 -> V_84 -> V_91 ( V_20 , V_90 ) ;
}
static void F_24 ( struct V_1 * V_12 )
{
struct V_19 * V_22 = (struct V_19 * ) V_12 ;
F_25 ( V_12 ) ;
if ( F_26 ( V_22 -> V_17 . V_9 . V_36 ) )
F_27 ( V_22 -> V_17 . V_9 . V_36 ) ;
F_28 ( V_22 ) ;
}
static void F_29 ( struct V_1 * V_12 , struct V_23 * V_24 ,
int V_92 )
{
if ( ! V_92 )
return;
F_30 ( V_12 , V_24 ) ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_87 ) ;
}
static void T_7 F_33 ( void )
{
#ifdef F_34
if ( V_93 )
F_35 ( V_93 ) ;
#endif
F_36 ( & V_87 ) ;
}
void T_6 F_37 ( int V_94 )
{
V_86 . V_89 = V_94 / 2 ;
F_38 ( & V_86 ) ;
F_39 () ;
F_31 () ;
#ifdef F_34
V_93 = F_40 ( & V_95 , L_1 ,
V_96 ) ;
#endif
}
