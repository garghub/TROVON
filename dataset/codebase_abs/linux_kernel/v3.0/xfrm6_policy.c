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
static int F_11 ( struct V_17 * V_18 , struct V_1 * V_8 ,
int V_19 )
{
if ( V_8 -> V_20 -> V_21 == V_22 ) {
struct V_23 * V_24 = (struct V_23 * ) V_8 ;
if ( V_24 -> V_25 )
V_18 -> V_26 = V_24 -> V_25 -> V_27 ;
}
V_18 -> V_28 . V_29 . V_30 = V_19 ;
return 0 ;
}
static int F_12 ( struct V_17 * V_31 , struct V_10 * V_11 ,
const struct V_15 * V_16 )
{
struct V_23 * V_24 = (struct V_23 * ) V_31 -> V_32 ;
V_31 -> V_28 . V_8 . V_11 = V_11 ;
F_13 ( V_11 ) ;
V_31 -> V_28 . V_29 . V_33 = F_14 ( V_11 ) ;
if ( ! V_31 -> V_28 . V_29 . V_33 )
return - V_34 ;
V_31 -> V_28 . V_29 . V_35 = V_24 -> V_35 ;
if ( V_24 -> V_35 )
F_15 ( & V_24 -> V_35 -> V_36 ) ;
V_31 -> V_28 . V_29 . V_37 = V_24 -> V_37 & ( V_38 |
V_39 ) ;
V_31 -> V_28 . V_29 . V_40 = V_24 -> V_40 ;
V_31 -> V_28 . V_29 . V_25 = V_24 -> V_25 ;
if ( V_24 -> V_25 )
V_31 -> V_41 = V_24 -> V_25 -> V_27 ;
V_31 -> V_28 . V_29 . V_42 = V_24 -> V_42 ;
V_31 -> V_28 . V_29 . V_43 = V_24 -> V_43 ;
V_31 -> V_28 . V_29 . V_44 = V_24 -> V_44 ;
return 0 ;
}
static inline void
F_16 ( struct V_45 * V_46 , struct V_15 * V_16 , int V_47 )
{
struct V_6 * V_7 = & V_16 -> V_28 . V_48 ;
int V_49 = 0 ;
T_2 V_50 = F_17 ( V_46 ) ;
const struct V_51 * V_52 = F_18 ( V_46 ) ;
struct V_53 * V_54 ;
const unsigned char * V_55 = F_19 ( V_46 ) ;
T_3 V_56 = V_55 [ F_20 ( V_46 ) -> V_57 ] ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
V_7 -> V_58 = V_46 -> V_59 ;
F_21 ( & V_7 -> V_5 , V_47 ? & V_52 -> V_4 : & V_52 -> V_5 ) ;
F_21 ( & V_7 -> V_4 , V_47 ? & V_52 -> V_5 : & V_52 -> V_4 ) ;
while ( V_55 + V_50 + 1 < V_46 -> V_60 ||
F_22 ( V_46 , V_55 + V_50 + 1 - V_46 -> V_60 ) ) {
V_55 = F_19 ( V_46 ) ;
V_54 = (struct V_53 * ) ( V_55 + V_50 ) ;
switch ( V_56 ) {
case V_61 :
V_49 = 1 ;
case V_62 :
case V_63 :
case V_64 :
V_50 += F_23 ( V_54 ) ;
V_56 = V_54 -> V_56 ;
V_54 = (struct V_53 * ) ( V_55 + V_50 ) ;
break;
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
if ( ! V_49 && ( V_55 + V_50 + 4 < V_46 -> V_60 ||
F_22 ( V_46 , V_55 + V_50 + 4 - V_46 -> V_60 ) ) ) {
T_4 * V_70 = ( T_4 * ) V_54 ;
V_7 -> V_71 = V_70 [ ! ! V_47 ] ;
V_7 -> V_72 = V_70 [ ! V_47 ] ;
}
V_7 -> V_73 = V_56 ;
return;
case V_74 :
if ( ! V_49 && F_22 ( V_46 , V_55 + V_50 + 2 - V_46 -> V_60 ) ) {
T_3 * V_75 = ( T_3 * ) V_54 ;
V_7 -> V_76 = V_75 [ 0 ] ;
V_7 -> V_77 = V_75 [ 1 ] ;
}
V_7 -> V_73 = V_56 ;
return;
#if F_24 ( V_78 ) || F_24 ( V_79 )
case V_80 :
if ( ! V_49 && F_22 ( V_46 , V_55 + V_50 + 3 - V_46 -> V_60 ) ) {
struct V_81 * V_82 ;
V_82 = (struct V_81 * ) V_54 ;
V_7 -> V_83 = V_82 -> V_84 ;
}
V_7 -> V_73 = V_56 ;
return;
#endif
case V_85 :
case V_86 :
case V_87 :
default:
V_7 -> V_88 = 0 ;
V_7 -> V_73 = V_56 ;
return;
}
}
}
static inline int F_25 ( struct V_89 * V_20 )
{
struct V_2 * V_2 = F_26 ( V_20 , struct V_2 , V_90 . V_91 ) ;
V_92 . V_93 ( V_2 ) ;
return F_27 ( V_20 ) > V_20 -> V_94 * 2 ;
}
static void F_28 ( struct V_1 * V_8 , T_5 V_95 )
{
struct V_17 * V_31 = (struct V_17 * ) V_8 ;
struct V_1 * V_18 = V_31 -> V_32 ;
V_18 -> V_20 -> V_96 ( V_18 , V_95 ) ;
}
static void F_29 ( struct V_1 * V_8 )
{
struct V_17 * V_31 = (struct V_17 * ) V_8 ;
if ( F_30 ( V_31 -> V_28 . V_29 . V_33 ) )
F_31 ( V_31 -> V_28 . V_29 . V_33 ) ;
F_32 ( V_8 ) ;
if ( F_30 ( V_31 -> V_28 . V_29 . V_35 ) )
F_33 ( V_31 -> V_28 . V_29 . V_35 ) ;
F_34 ( V_31 ) ;
}
static void F_35 ( struct V_1 * V_8 , struct V_10 * V_11 ,
int V_97 )
{
struct V_17 * V_31 ;
if ( ! V_97 )
return;
V_31 = (struct V_17 * ) V_8 ;
if ( V_31 -> V_28 . V_29 . V_33 -> V_11 == V_11 ) {
struct V_98 * V_99 =
F_14 ( F_9 ( V_11 ) -> V_100 ) ;
F_36 ( ! V_99 ) ;
do {
F_31 ( V_31 -> V_28 . V_29 . V_33 ) ;
V_31 -> V_28 . V_29 . V_33 = V_99 ;
F_37 ( V_99 ) ;
V_31 = (struct V_17 * ) V_31 -> V_28 . V_8 . V_101 ;
} while ( V_31 -> V_28 . V_8 . V_90 );
F_38 ( V_99 ) ;
}
F_39 ( V_8 , V_11 ) ;
}
static int T_6 F_40 ( void )
{
return F_41 ( & V_92 ) ;
}
static void F_42 ( void )
{
F_43 ( & V_92 ) ;
}
int T_6 F_44 ( void )
{
int V_102 ;
unsigned int V_94 ;
V_94 = V_103 * 8 ;
V_91 . V_94 = ( V_94 < 1024 ) ? 1024 : V_94 ;
F_45 ( & V_91 ) ;
V_102 = F_40 () ;
if ( V_102 ) {
F_46 ( & V_91 ) ;
goto V_104;
}
V_102 = F_47 () ;
if ( V_102 )
goto V_105;
#ifdef F_48
V_106 = F_49 ( & V_107 , V_108 ,
V_109 ) ;
#endif
V_104:
return V_102 ;
V_105:
F_42 () ;
goto V_104;
}
void F_50 ( void )
{
#ifdef F_48
if ( V_106 )
F_51 ( V_106 ) ;
#endif
F_42 () ;
F_52 () ;
F_46 ( & V_91 ) ;
}
