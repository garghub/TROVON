static struct V_1 * F_1 ( struct V_2 * V_2 , int V_3 ,
const T_1 * V_4 ,
const T_1 * V_5 )
{
struct V_6 V_7 ;
struct V_1 * V_8 ;
int V_9 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
memcpy ( & V_7 . V_5 , V_5 , sizeof( V_7 . V_5 ) ) ;
if ( V_4 )
memcpy ( & V_7 . V_4 , V_4 , sizeof( V_7 . V_4 ) ) ;
V_8 = F_2 ( V_2 , NULL , & V_7 ) ;
V_9 = V_8 -> error ;
if ( V_8 -> error ) {
F_3 ( V_8 ) ;
V_8 = F_4 ( V_9 ) ;
}
return V_8 ;
}
static int F_5 ( struct V_2 * V_2 ,
T_1 * V_4 , T_1 * V_5 )
{
struct V_1 * V_8 ;
struct V_10 * V_11 ;
V_8 = F_1 ( V_2 , 0 , NULL , V_5 ) ;
if ( F_6 ( V_8 ) )
return - V_12 ;
V_11 = F_7 ( V_8 ) -> V_11 ;
F_8 ( F_9 ( V_11 ) , V_11 ,
(struct V_13 * ) & V_5 -> V_14 , 0 ,
(struct V_13 * ) & V_4 -> V_14 ) ;
F_3 ( V_8 ) ;
return 0 ;
}
static int F_10 ( const struct V_15 * V_16 )
{
return 0 ;
}
static void F_11 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_19 * V_20 = (struct V_19 * ) V_18 ;
F_12 ( V_20 , V_2 -> V_21 . V_22 ) ;
}
static int F_13 ( struct V_17 * V_23 , struct V_1 * V_8 ,
int V_24 )
{
if ( V_8 -> V_25 -> V_26 == V_27 ) {
struct V_19 * V_20 = (struct V_19 * ) V_8 ;
if ( V_20 -> V_28 )
V_23 -> V_29 = V_20 -> V_28 -> V_30 ;
}
V_23 -> V_31 . V_32 . V_33 = V_24 ;
return 0 ;
}
static int F_14 ( struct V_17 * V_18 , struct V_10 * V_11 ,
const struct V_15 * V_16 )
{
struct V_19 * V_20 = (struct V_19 * ) V_18 -> V_34 ;
V_18 -> V_31 . V_8 . V_11 = V_11 ;
F_15 ( V_11 ) ;
V_18 -> V_31 . V_32 . V_35 = F_16 ( V_11 ) ;
if ( ! V_18 -> V_31 . V_32 . V_35 )
return - V_36 ;
F_17 ( & V_18 -> V_31 . V_32 , V_20 ) ;
V_18 -> V_31 . V_32 . V_37 = F_18 ( V_20 -> V_37 ) ;
V_18 -> V_31 . V_32 . V_38 = V_20 -> V_38 & ( V_39 |
V_40 ) ;
V_18 -> V_31 . V_32 . V_41 = V_20 -> V_41 ;
V_18 -> V_31 . V_32 . V_28 = V_20 -> V_28 ;
if ( V_20 -> V_28 )
V_18 -> V_42 = V_20 -> V_28 -> V_30 ;
V_18 -> V_31 . V_32 . V_43 = V_20 -> V_43 ;
V_18 -> V_31 . V_32 . V_44 = V_20 -> V_44 ;
V_18 -> V_31 . V_32 . V_45 = V_20 -> V_45 ;
return 0 ;
}
static inline void
F_19 ( struct V_46 * V_47 , struct V_15 * V_16 , int V_48 )
{
struct V_6 * V_7 = & V_16 -> V_31 . V_49 ;
int V_50 = 0 ;
T_2 V_51 = F_20 ( V_47 ) ;
const struct V_52 * V_53 = F_21 ( V_47 ) ;
struct V_54 * V_55 ;
const unsigned char * V_56 = F_22 ( V_47 ) ;
T_3 V_57 = V_56 [ F_23 ( V_47 ) -> V_58 ] ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
V_7 -> V_59 = V_47 -> V_60 ;
V_7 -> V_5 = V_48 ? V_53 -> V_4 : V_53 -> V_5 ;
V_7 -> V_4 = V_48 ? V_53 -> V_5 : V_53 -> V_4 ;
while ( V_56 + V_51 + 1 < V_47 -> V_61 ||
F_24 ( V_47 , V_56 + V_51 + 1 - V_47 -> V_61 ) ) {
V_56 = F_22 ( V_47 ) ;
V_55 = (struct V_54 * ) ( V_56 + V_51 ) ;
switch ( V_57 ) {
case V_62 :
V_50 = 1 ;
case V_63 :
case V_64 :
case V_65 :
V_51 += F_25 ( V_55 ) ;
V_57 = V_55 -> V_57 ;
V_55 = (struct V_54 * ) ( V_56 + V_51 ) ;
break;
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
if ( ! V_50 && ( V_56 + V_51 + 4 < V_47 -> V_61 ||
F_24 ( V_47 , V_56 + V_51 + 4 - V_47 -> V_61 ) ) ) {
T_4 * V_71 = ( T_4 * ) V_55 ;
V_7 -> V_72 = V_71 [ ! ! V_48 ] ;
V_7 -> V_73 = V_71 [ ! V_48 ] ;
}
V_7 -> V_74 = V_57 ;
return;
case V_75 :
if ( ! V_50 && F_24 ( V_47 , V_56 + V_51 + 2 - V_47 -> V_61 ) ) {
T_3 * V_76 = ( T_3 * ) V_55 ;
V_7 -> V_77 = V_76 [ 0 ] ;
V_7 -> V_78 = V_76 [ 1 ] ;
}
V_7 -> V_74 = V_57 ;
return;
#if F_26 ( V_79 )
case V_80 :
if ( ! V_50 && F_24 ( V_47 , V_56 + V_51 + 3 - V_47 -> V_61 ) ) {
struct V_81 * V_82 ;
V_82 = (struct V_81 * ) V_55 ;
V_7 -> V_83 = V_82 -> V_84 ;
}
V_7 -> V_74 = V_57 ;
return;
#endif
case V_85 :
case V_86 :
case V_87 :
default:
V_7 -> V_88 = 0 ;
V_7 -> V_74 = V_57 ;
return;
}
}
}
static inline int F_27 ( struct V_89 * V_25 )
{
struct V_2 * V_2 = F_28 ( V_25 , struct V_2 , V_90 . V_91 ) ;
V_92 . V_93 ( V_2 ) ;
return F_29 ( V_25 ) > V_25 -> V_94 * 2 ;
}
static void F_30 ( struct V_1 * V_8 , struct V_95 * V_96 ,
struct V_46 * V_47 , T_5 V_97 )
{
struct V_17 * V_18 = (struct V_17 * ) V_8 ;
struct V_1 * V_23 = V_18 -> V_34 ;
V_23 -> V_25 -> V_98 ( V_23 , V_96 , V_47 , V_97 ) ;
}
static void F_31 ( struct V_1 * V_8 , struct V_95 * V_96 ,
struct V_46 * V_47 )
{
struct V_17 * V_18 = (struct V_17 * ) V_8 ;
struct V_1 * V_23 = V_18 -> V_34 ;
V_23 -> V_25 -> V_99 ( V_23 , V_96 , V_47 ) ;
}
static void F_32 ( struct V_1 * V_8 )
{
struct V_17 * V_18 = (struct V_17 * ) V_8 ;
if ( F_33 ( V_18 -> V_31 . V_32 . V_35 ) )
F_34 ( V_18 -> V_31 . V_32 . V_35 ) ;
F_35 ( V_8 ) ;
if ( F_36 ( & V_18 -> V_31 . V_32 ) ) {
struct V_100 * V_101 = F_37 ( & V_18 -> V_31 . V_32 ) ;
F_38 ( V_101 ) ;
}
F_39 ( V_18 ) ;
}
static void F_40 ( struct V_1 * V_8 , struct V_10 * V_11 ,
int V_102 )
{
struct V_17 * V_18 ;
if ( ! V_102 )
return;
V_18 = (struct V_17 * ) V_8 ;
if ( V_18 -> V_31 . V_32 . V_35 -> V_11 == V_11 ) {
struct V_103 * V_104 =
F_16 ( F_9 ( V_11 ) -> V_105 ) ;
F_41 ( ! V_104 ) ;
do {
F_34 ( V_18 -> V_31 . V_32 . V_35 ) ;
V_18 -> V_31 . V_32 . V_35 = V_104 ;
F_42 ( V_104 ) ;
V_18 = (struct V_17 * ) V_18 -> V_31 . V_8 . V_106 ;
} while ( V_18 -> V_31 . V_8 . V_90 );
F_43 ( V_104 ) ;
}
F_44 ( V_8 , V_11 ) ;
}
static int T_6 F_45 ( void )
{
return F_46 ( & V_92 ) ;
}
static void F_47 ( void )
{
F_48 ( & V_92 ) ;
}
int T_6 F_49 ( void )
{
int V_107 ;
F_50 ( & V_91 ) ;
V_107 = F_45 () ;
if ( V_107 ) {
F_51 ( & V_91 ) ;
goto V_108;
}
V_107 = F_52 () ;
if ( V_107 )
goto V_109;
#ifdef F_53
V_110 = F_54 ( & V_111 , L_1 ,
V_112 ) ;
#endif
V_108:
return V_107 ;
V_109:
F_47 () ;
goto V_108;
}
void F_55 ( void )
{
#ifdef F_53
if ( V_110 )
F_56 ( V_110 ) ;
#endif
F_47 () ;
F_57 () ;
F_51 ( & V_91 ) ;
}
