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
F_12 ( & V_22 -> V_17 . V_9 . V_36 ) ;
return 0 ;
}
static void
F_13 ( struct V_37 * V_38 , struct V_14 * V_15 , int V_39 )
{
const struct V_40 * V_41 = F_14 ( V_38 ) ;
T_2 * V_42 = F_15 ( V_38 ) + V_41 -> V_43 * 4 ;
struct V_3 * V_4 = & V_15 -> V_17 . V_18 ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_44 = V_38 -> V_45 ;
if ( ! F_16 ( V_41 ) ) {
switch ( V_41 -> V_46 ) {
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
if ( V_42 + 4 < V_38 -> V_52 ||
F_17 ( V_38 , V_42 + 4 - V_38 -> V_52 ) ) {
T_3 * V_53 = ( T_3 * ) V_42 ;
V_4 -> V_54 = V_53 [ ! ! V_39 ] ;
V_4 -> V_55 = V_53 [ ! V_39 ] ;
}
break;
case V_56 :
if ( F_17 ( V_38 , V_42 + 2 - V_38 -> V_52 ) ) {
T_2 * V_57 = V_42 ;
V_4 -> V_58 = V_57 [ 0 ] ;
V_4 -> V_59 = V_57 [ 1 ] ;
}
break;
case V_60 :
if ( F_17 ( V_38 , V_42 + 4 - V_38 -> V_52 ) ) {
T_4 * V_61 = ( T_4 * ) V_42 ;
V_4 -> V_62 = V_61 [ 0 ] ;
}
break;
case V_63 :
if ( F_17 ( V_38 , V_42 + 8 - V_38 -> V_52 ) ) {
T_4 * V_64 = ( T_4 * ) V_42 ;
V_4 -> V_62 = V_64 [ 1 ] ;
}
break;
case V_65 :
if ( F_17 ( V_38 , V_42 + 4 - V_38 -> V_52 ) ) {
T_3 * V_66 = ( T_3 * ) V_42 ;
V_4 -> V_62 = F_18 ( F_19 ( V_66 [ 1 ] ) ) ;
}
break;
case V_67 :
if ( F_17 ( V_38 , V_42 + 12 - V_38 -> V_52 ) ) {
T_3 * V_68 = ( T_3 * ) V_42 ;
T_4 * V_69 = ( T_4 * ) V_42 ;
if ( V_68 [ 0 ] & V_70 ) {
if ( V_68 [ 0 ] & V_71 )
V_69 ++ ;
V_4 -> V_72 = V_69 [ 1 ] ;
}
}
break;
default:
V_4 -> V_62 = 0 ;
break;
}
}
V_4 -> V_73 = V_41 -> V_46 ;
V_4 -> V_7 = V_39 ? V_41 -> V_6 : V_41 -> V_7 ;
V_4 -> V_6 = V_39 ? V_41 -> V_7 : V_41 -> V_6 ;
V_4 -> V_11 = V_41 -> V_5 ;
}
static inline int F_20 ( struct V_74 * V_75 )
{
struct V_2 * V_2 = F_21 ( V_75 , struct V_2 , V_76 . V_77 ) ;
V_78 . V_79 ( V_2 ) ;
return ( F_22 ( V_75 ) > V_75 -> V_80 * 2 ) ;
}
static void F_23 ( struct V_1 * V_12 , struct V_81 * V_82 ,
struct V_37 * V_38 , T_5 V_83 )
{
struct V_19 * V_22 = (struct V_19 * ) V_12 ;
struct V_1 * V_20 = V_22 -> V_25 ;
V_20 -> V_75 -> V_84 ( V_20 , V_82 , V_38 , V_83 ) ;
}
static void F_24 ( struct V_1 * V_12 , struct V_81 * V_82 ,
struct V_37 * V_38 )
{
struct V_19 * V_22 = (struct V_19 * ) V_12 ;
struct V_1 * V_20 = V_22 -> V_25 ;
V_20 -> V_75 -> V_85 ( V_20 , V_82 , V_38 ) ;
}
static void F_25 ( struct V_1 * V_12 )
{
struct V_19 * V_22 = (struct V_19 * ) V_12 ;
F_26 ( V_12 ) ;
F_27 ( V_22 ) ;
}
static void F_28 ( struct V_1 * V_12 , struct V_23 * V_24 ,
int V_86 )
{
if ( ! V_86 )
return;
F_29 ( V_12 , V_24 ) ;
}
static void T_6 F_30 ( void )
{
F_31 ( & V_78 ) ;
}
static void T_7 F_32 ( void )
{
#ifdef F_33
if ( V_87 )
F_34 ( V_87 ) ;
#endif
F_35 ( & V_78 ) ;
}
void T_6 F_36 ( int V_88 )
{
V_77 . V_80 = V_88 / 2 ;
F_37 ( & V_77 ) ;
F_38 () ;
F_30 () ;
#ifdef F_33
V_87 = F_39 ( & V_89 , L_1 ,
V_90 ) ;
#endif
}
