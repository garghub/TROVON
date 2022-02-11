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
if ( ! F_16 ( V_42 ) ) {
switch ( V_42 -> V_47 ) {
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
if ( V_43 + 4 < V_39 -> V_53 ||
F_17 ( V_39 , V_43 + 4 - V_39 -> V_53 ) ) {
T_3 * V_54 = ( T_3 * ) V_43 ;
V_4 -> V_55 = V_54 [ ! ! V_40 ] ;
V_4 -> V_56 = V_54 [ ! V_40 ] ;
}
break;
case V_57 :
if ( F_17 ( V_39 , V_43 + 2 - V_39 -> V_53 ) ) {
T_2 * V_58 = V_43 ;
V_4 -> V_59 = V_58 [ 0 ] ;
V_4 -> V_60 = V_58 [ 1 ] ;
}
break;
case V_61 :
if ( F_17 ( V_39 , V_43 + 4 - V_39 -> V_53 ) ) {
T_4 * V_62 = ( T_4 * ) V_43 ;
V_4 -> V_63 = V_62 [ 0 ] ;
}
break;
case V_64 :
if ( F_17 ( V_39 , V_43 + 8 - V_39 -> V_53 ) ) {
T_4 * V_65 = ( T_4 * ) V_43 ;
V_4 -> V_63 = V_65 [ 1 ] ;
}
break;
case V_66 :
if ( F_17 ( V_39 , V_43 + 4 - V_39 -> V_53 ) ) {
T_3 * V_67 = ( T_3 * ) V_43 ;
V_4 -> V_63 = F_18 ( F_19 ( V_67 [ 1 ] ) ) ;
}
break;
case V_68 :
if ( F_17 ( V_39 , V_43 + 12 - V_39 -> V_53 ) ) {
T_3 * V_69 = ( T_3 * ) V_43 ;
T_4 * V_70 = ( T_4 * ) V_43 ;
if ( V_69 [ 0 ] & V_71 ) {
if ( V_69 [ 0 ] & V_72 )
V_70 ++ ;
V_4 -> V_73 = V_70 [ 1 ] ;
}
}
break;
default:
V_4 -> V_63 = 0 ;
break;
}
}
V_4 -> V_74 = V_42 -> V_47 ;
V_4 -> V_7 = V_40 ? V_42 -> V_6 : V_42 -> V_7 ;
V_4 -> V_6 = V_40 ? V_42 -> V_7 : V_42 -> V_6 ;
V_4 -> V_11 = V_42 -> V_5 ;
}
static inline int F_20 ( struct V_75 * V_76 )
{
struct V_2 * V_2 = F_21 ( V_76 , struct V_2 , V_77 . V_78 ) ;
V_79 . V_80 ( V_2 ) ;
return ( F_22 ( V_76 ) > V_76 -> V_81 * 2 ) ;
}
static void F_23 ( struct V_1 * V_12 , struct V_82 * V_83 ,
struct V_38 * V_39 , T_5 V_84 )
{
struct V_19 * V_22 = (struct V_19 * ) V_12 ;
struct V_1 * V_20 = V_22 -> V_25 ;
V_20 -> V_76 -> V_85 ( V_20 , V_83 , V_39 , V_84 ) ;
}
static void F_24 ( struct V_1 * V_12 , struct V_82 * V_83 ,
struct V_38 * V_39 )
{
struct V_19 * V_22 = (struct V_19 * ) V_12 ;
struct V_1 * V_20 = V_22 -> V_25 ;
V_20 -> V_76 -> V_86 ( V_20 , V_83 , V_39 ) ;
}
static void F_25 ( struct V_1 * V_12 )
{
struct V_19 * V_22 = (struct V_19 * ) V_12 ;
F_26 ( V_12 ) ;
F_27 ( V_22 ) ;
}
static void F_28 ( struct V_1 * V_12 , struct V_23 * V_24 ,
int V_87 )
{
if ( ! V_87 )
return;
F_29 ( V_12 , V_24 ) ;
}
static void T_6 F_30 ( void )
{
F_31 ( & V_79 ) ;
}
static void T_7 F_32 ( void )
{
#ifdef F_33
if ( V_88 )
F_34 ( V_88 ) ;
#endif
F_35 ( & V_79 ) ;
}
void T_6 F_36 ( void )
{
F_37 ( & V_78 ) ;
F_38 () ;
F_30 () ;
#ifdef F_33
V_88 = F_39 ( & V_89 , L_1 ,
V_90 ) ;
#endif
}
