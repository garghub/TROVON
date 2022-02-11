static int
F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_7 * V_8 = F_3 ( & V_5 -> V_9 ) ;
V_2 -> V_10 = V_8 ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 )
{
V_2 -> V_10 = NULL ;
return 0 ;
}
static inline void
F_5 ( struct V_11 * V_12 )
{
if ( V_12 -> V_13 [ 0 ] . V_12 ) {
F_6 ( & V_12 -> V_13 [ 0 ] ) ;
F_7 ( & V_12 -> V_13 [ 0 ] ) ;
}
if ( V_12 -> V_13 [ 1 ] . V_12 ) {
F_6 ( & V_12 -> V_13 [ 1 ] ) ;
F_7 ( & V_12 -> V_13 [ 1 ] ) ;
}
}
static void
F_8 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_16 * V_17 = F_3 ( & V_5 -> V_9 ) -> V_17 ;
F_5 ( V_15 -> V_18 ) ;
V_17 -> V_19 -> V_20 ( V_17 , (struct V_11 * * ) & V_15 -> V_18 ) ;
}
static int
F_9 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
const struct V_23 * V_24 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_16 * V_17 = F_3 ( & V_5 -> V_9 ) -> V_17 ;
struct V_25 * V_26 = V_25 ( V_22 ) ;
struct V_11 * V_12 ;
T_1 V_27 = 0 ;
int V_28 ;
if ( V_5 -> V_9 . V_29 . V_30 == 0 )
return - V_31 ;
if ( V_26 -> V_32 & V_33 )
V_27 = 1 << V_26 -> V_34 ;
V_28 = V_17 -> V_19 -> V_35 ( V_17 , V_15 -> V_36 << V_37 ,
V_15 -> V_38 << V_37 , V_27 ,
( V_26 -> V_32 >> 8 ) & 0x3ff , & V_12 ) ;
if ( V_28 ) {
V_15 -> V_18 = NULL ;
return ( V_28 == - V_39 ) ? 0 : V_28 ;
}
V_12 -> V_34 = V_26 -> V_34 ;
V_15 -> V_18 = V_12 ;
V_15 -> V_40 = V_12 -> V_41 >> V_37 ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 , unsigned long V_3 )
{
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 )
{
return 0 ;
}
static void
F_12 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
F_5 ( V_15 -> V_18 ) ;
F_13 ( V_15 -> V_18 ) ;
V_15 -> V_18 = NULL ;
}
static int
F_14 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
const struct V_23 * V_24 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = F_2 ( V_22 -> V_6 ) ;
struct V_25 * V_26 = V_25 ( V_22 ) ;
struct V_11 * V_12 ;
V_12 = F_15 ( sizeof( * V_12 ) , V_42 ) ;
if ( ! V_12 )
return - V_31 ;
V_12 -> V_34 = 12 ;
switch ( V_5 -> V_9 . V_29 . V_43 ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
break;
case V_49 :
if ( V_5 -> V_9 . V_29 . V_50 != 0x50 )
V_12 -> V_51 = ( V_26 -> V_32 & 0x7f00 ) >> 8 ;
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
V_12 -> V_51 = ( V_26 -> V_32 & 0xff00 ) >> 8 ;
break;
default:
F_16 ( V_5 , L_1 , V_56 ,
V_5 -> V_9 . V_29 . V_43 ) ;
break;
}
V_15 -> V_18 = V_12 ;
V_15 -> V_40 = 0 ;
return 0 ;
}
static void
F_17 ( struct V_1 * V_2 , const char * V_57 )
{
}
static int
F_18 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_58 * V_59 = F_19 ( & V_5 -> V_9 ) ;
struct V_60 * V_10 = ( void * ) V_59 ;
struct V_61 * V_62 = NULL ;
F_20 ( V_10 -> V_62 , & V_62 , NULL ) ;
V_2 -> V_10 = V_62 ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_10 ;
F_20 ( NULL , & V_62 , NULL ) ;
V_2 -> V_10 = NULL ;
return 0 ;
}
static void
F_22 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_11 * V_12 = V_15 -> V_18 ;
if ( V_12 -> V_13 [ 0 ] . V_12 )
F_7 ( & V_12 -> V_13 [ 0 ] ) ;
F_13 ( V_15 -> V_18 ) ;
V_15 -> V_18 = NULL ;
}
static int
F_23 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
const struct V_23 * V_24 ,
struct V_14 * V_15 )
{
struct V_11 * V_12 ;
int V_28 ;
V_12 = F_15 ( sizeof( * V_12 ) , V_42 ) ;
if ( ! V_12 )
return - V_31 ;
V_12 -> V_34 = 12 ;
V_28 = F_24 ( V_2 -> V_10 , V_15 -> V_36 << 12 , V_12 -> V_34 ,
V_63 , & V_12 -> V_13 [ 0 ] ) ;
if ( V_28 ) {
F_13 ( V_12 ) ;
return V_28 ;
}
V_15 -> V_18 = V_12 ;
V_15 -> V_40 = V_12 -> V_13 [ 0 ] . V_41 >> V_37 ;
return 0 ;
}
static void
F_25 ( struct V_1 * V_2 , const char * V_57 )
{
}
int
F_26 ( struct V_64 * V_65 , struct V_66 * V_13 )
{
struct V_67 * V_68 = V_65 -> V_69 ;
struct V_4 * V_5 = V_4 ( V_68 -> V_70 -> V_71 ) ;
if ( F_27 ( V_13 -> V_72 < V_73 ) )
return F_28 ( V_65 , V_13 ) ;
return F_29 ( V_65 , V_13 , & V_5 -> V_74 . V_6 ) ;
}
static int
F_30 ( struct V_75 * V_76 )
{
return F_31 ( V_76 -> V_77 ) ;
}
static void
F_32 ( struct V_75 * V_76 )
{
F_33 ( V_76 -> V_77 ) ;
}
int
F_34 ( struct V_4 * V_5 )
{
struct V_75 * V_78 ;
int V_28 ;
V_78 = & V_5 -> V_74 . V_79 ;
V_78 -> V_80 = V_81 ;
V_78 -> V_82 = sizeof( struct V_83 ) ;
V_78 -> V_84 = & F_30 ;
V_78 -> V_85 = & F_32 ;
V_28 = F_35 ( V_78 ) ;
if ( F_27 ( V_28 != 0 ) ) {
F_36 ( L_2 ) ;
V_5 -> V_74 . V_79 . V_85 = NULL ;
return V_28 ;
}
V_5 -> V_74 . V_86 . V_87 = V_78 -> V_77 ;
V_78 = & V_5 -> V_74 . V_86 . V_76 ;
V_78 -> V_80 = V_88 ;
V_78 -> V_82 = sizeof( struct V_89 ) ;
V_78 -> V_84 = & V_90 ;
V_78 -> V_85 = & V_91 ;
V_28 = F_35 ( V_78 ) ;
if ( F_27 ( V_28 != 0 ) ) {
F_36 ( L_3 ) ;
F_37 ( & V_5 -> V_74 . V_79 ) ;
V_5 -> V_74 . V_79 . V_85 = NULL ;
return V_28 ;
}
return 0 ;
}
void
F_38 ( struct V_4 * V_5 )
{
if ( V_5 -> V_74 . V_79 . V_85 == NULL )
return;
F_37 ( & V_5 -> V_74 . V_86 . V_76 ) ;
F_37 ( & V_5 -> V_74 . V_79 ) ;
V_5 -> V_74 . V_79 . V_85 = NULL ;
}
int
F_39 ( struct V_4 * V_5 )
{
struct V_92 * V_9 = F_40 ( & V_5 -> V_9 ) ;
struct V_93 * V_94 = V_9 -> V_94 ;
struct V_95 * V_71 = V_5 -> V_71 ;
T_2 V_96 ;
int V_28 ;
if ( V_94 && V_94 -> V_97 . V_98 ) {
V_5 -> V_97 . V_98 = V_94 -> V_97 . V_98 ;
V_5 -> V_97 . V_99 = V_94 -> V_97 . V_99 ;
V_5 -> V_97 . V_82 = V_94 -> V_97 . V_82 ;
V_5 -> V_97 . V_100 = V_94 -> V_97 . V_100 ;
}
V_96 = F_19 ( & V_5 -> V_9 ) -> V_101 ;
if ( F_40 ( & V_5 -> V_9 ) -> V_19 -> V_94 ) {
if ( V_5 -> V_97 . V_98 )
V_96 = 32 ;
} else if ( V_9 -> V_19 -> V_102 ) {
struct V_103 * V_102 = V_9 -> V_19 -> V_102 ( V_9 ) ;
if ( V_102 -> V_19 -> V_104 )
V_96 = F_41 ( V_96 , V_102 -> V_19 -> V_104 ) ;
}
V_28 = F_42 ( V_71 -> V_71 , F_43 ( V_96 ) ) ;
if ( V_28 && V_96 != 32 ) {
V_96 = 32 ;
V_28 = F_42 ( V_71 -> V_71 , F_43 ( V_96 ) ) ;
}
if ( V_28 )
return V_28 ;
V_28 = F_44 ( V_71 -> V_71 , F_43 ( V_96 ) ) ;
if ( V_28 )
F_44 ( V_71 -> V_71 , F_43 ( 32 ) ) ;
V_28 = F_34 ( V_5 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_45 ( & V_5 -> V_74 . V_6 ,
V_5 -> V_74 . V_86 . V_76 . V_77 ,
& V_105 ,
V_71 -> V_106 -> V_107 ,
V_73 ,
V_96 <= 32 ? true : false ) ;
if ( V_28 ) {
F_46 ( V_5 , L_4 , V_28 ) ;
return V_28 ;
}
V_5 -> V_108 . V_109 = V_5 -> V_9 . V_29 . V_110 ;
V_28 = F_47 ( & V_5 -> V_74 . V_6 , V_111 ,
V_5 -> V_108 . V_109 >> V_37 ) ;
if ( V_28 ) {
F_46 ( V_5 , L_5 , V_28 ) ;
return V_28 ;
}
V_5 -> V_74 . V_112 = F_48 ( V_9 -> V_19 -> V_113 ( V_9 , 1 ) ,
V_9 -> V_19 -> V_114 ( V_9 , 1 ) ) ;
if ( ! V_5 -> V_97 . V_98 ) {
V_5 -> V_108 . V_115 = F_19 ( & V_5 -> V_9 ) -> V_116 ;
} else {
V_5 -> V_108 . V_115 = V_5 -> V_97 . V_82 ;
}
V_28 = F_47 ( & V_5 -> V_74 . V_6 , V_117 ,
V_5 -> V_108 . V_115 >> V_37 ) ;
if ( V_28 ) {
F_46 ( V_5 , L_6 , V_28 ) ;
return V_28 ;
}
F_49 ( V_5 , L_7 , ( T_1 ) ( V_5 -> V_108 . V_109 >> 20 ) ) ;
F_49 ( V_5 , L_8 , ( T_1 ) ( V_5 -> V_108 . V_115 >> 20 ) ) ;
return 0 ;
}
void
F_50 ( struct V_4 * V_5 )
{
F_51 ( & V_5 -> V_74 . V_6 , V_111 ) ;
F_51 ( & V_5 -> V_74 . V_6 , V_117 ) ;
F_52 ( & V_5 -> V_74 . V_6 ) ;
F_38 ( V_5 ) ;
F_53 ( V_5 -> V_74 . V_112 ) ;
V_5 -> V_74 . V_112 = 0 ;
}
