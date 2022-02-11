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
V_9 -> V_26 = V_4 -> V_7 ;
V_9 -> V_27 = V_4 -> V_6 ;
V_9 -> V_28 = V_4 -> V_11 ;
V_9 -> V_29 = V_4 -> V_30 ;
V_9 -> V_31 = V_4 -> V_30 ;
V_9 -> V_32 = V_4 -> V_33 ;
V_9 -> V_34 = V_4 -> V_35 ;
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
if ( ! ( V_51 -> V_55 & F_16 ( V_56 | V_57 ) ) ) {
switch ( V_51 -> V_58 ) {
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
if ( V_52 + 4 < V_48 -> V_64 ||
F_17 ( V_48 , V_52 + 4 - V_48 -> V_64 ) ) {
T_3 * V_65 = ( T_3 * ) V_52 ;
V_4 -> V_66 = V_65 [ ! ! V_49 ] ;
V_4 -> V_67 = V_65 [ ! V_49 ] ;
}
break;
case V_68 :
if ( F_17 ( V_48 , V_52 + 2 - V_48 -> V_64 ) ) {
T_2 * V_69 = V_52 ;
V_4 -> V_70 = V_69 [ 0 ] ;
V_4 -> V_71 = V_69 [ 1 ] ;
}
break;
case V_72 :
if ( F_17 ( V_48 , V_52 + 4 - V_48 -> V_64 ) ) {
T_4 * V_73 = ( T_4 * ) V_52 ;
V_4 -> V_74 = V_73 [ 0 ] ;
}
break;
case V_75 :
if ( F_17 ( V_48 , V_52 + 8 - V_48 -> V_64 ) ) {
T_4 * V_76 = ( T_4 * ) V_52 ;
V_4 -> V_74 = V_76 [ 1 ] ;
}
break;
case V_77 :
if ( F_17 ( V_48 , V_52 + 4 - V_48 -> V_64 ) ) {
T_3 * V_78 = ( T_3 * ) V_52 ;
V_4 -> V_74 = F_18 ( F_19 ( V_78 [ 1 ] ) ) ;
}
break;
case V_79 :
if ( F_17 ( V_48 , V_52 + 12 - V_48 -> V_64 ) ) {
T_3 * V_80 = ( T_3 * ) V_52 ;
T_4 * V_81 = ( T_4 * ) V_52 ;
if ( V_80 [ 0 ] & V_82 ) {
if ( V_80 [ 0 ] & V_83 )
V_81 ++ ;
V_4 -> V_84 = V_81 [ 1 ] ;
}
}
break;
default:
V_4 -> V_74 = 0 ;
break;
}
}
V_4 -> V_85 = V_51 -> V_58 ;
V_4 -> V_7 = V_49 ? V_51 -> V_6 : V_51 -> V_7 ;
V_4 -> V_6 = V_49 ? V_51 -> V_7 : V_51 -> V_6 ;
V_4 -> V_11 = V_51 -> V_5 ;
}
static inline int F_20 ( struct V_86 * V_87 )
{
struct V_2 * V_2 = F_21 ( V_87 , struct V_2 , V_88 . V_89 ) ;
V_90 . V_91 ( V_2 ) ;
return ( F_22 ( V_87 ) > V_87 -> V_92 * 2 ) ;
}
static void F_23 ( struct V_1 * V_12 , T_5 V_93 )
{
struct V_19 * V_22 = (struct V_19 * ) V_12 ;
struct V_1 * V_20 = V_22 -> V_25 ;
V_20 -> V_87 -> V_94 ( V_20 , V_93 ) ;
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
int V_95 )
{
if ( ! V_95 )
return;
F_30 ( V_12 , V_24 ) ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_90 ) ;
}
static void T_7 F_33 ( void )
{
#ifdef F_34
if ( V_96 )
F_35 ( V_96 ) ;
#endif
F_36 ( & V_90 ) ;
}
void T_6 F_37 ( int V_97 )
{
V_89 . V_92 = V_97 / 2 ;
F_38 ( & V_89 ) ;
F_39 () ;
F_31 () ;
#ifdef F_34
V_96 = F_40 ( & V_98 , V_99 ,
V_100 ) ;
#endif
}
