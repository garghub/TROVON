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
struct V_7 * V_8 = F_3 ( & V_5 -> V_9 ) ;
F_5 ( V_15 -> V_16 ) ;
V_8 -> V_17 -> V_18 ( V_8 , (struct V_11 * * ) & V_15 -> V_16 ) ;
}
static int
F_9 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const struct V_21 * V_22 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_7 * V_8 = F_3 ( & V_5 -> V_9 ) ;
struct V_23 * V_24 = V_23 ( V_20 ) ;
struct V_11 * V_12 ;
T_1 V_25 = 0 ;
int V_26 ;
if ( V_5 -> V_9 . V_27 . V_28 == 0 )
return - V_29 ;
if ( V_24 -> V_30 & V_31 )
V_25 = 1 << V_24 -> V_32 ;
V_26 = V_8 -> V_17 -> V_33 ( V_8 , V_15 -> V_34 << V_35 ,
V_15 -> V_36 << V_35 , V_25 ,
( V_24 -> V_30 >> 8 ) & 0x3ff , & V_12 ) ;
if ( V_26 ) {
V_15 -> V_16 = NULL ;
return ( V_26 == - V_37 ) ? 0 : V_26 ;
}
V_12 -> V_32 = V_24 -> V_32 ;
V_15 -> V_16 = V_12 ;
V_15 -> V_38 = V_12 -> V_39 >> V_35 ;
return 0 ;
}
static void
F_10 ( struct V_1 * V_2 , const char * V_40 )
{
struct V_7 * V_8 = V_2 -> V_10 ;
struct V_41 * V_42 = & V_8 -> V_43 ;
struct V_44 * V_45 ;
T_1 V_46 = 0 , free = 0 ;
F_11 ( & F_12 ( V_8 ) -> V_47 ) ;
F_13 (r, &mm->nodes, nl_entry) {
F_14 ( V_48 L_1 ,
V_40 , V_45 -> type , ( ( V_49 ) V_45 -> V_39 << 12 ) ,
( ( ( V_49 ) V_45 -> V_39 + V_45 -> V_50 ) << 12 ) ) ;
V_46 += V_45 -> V_50 ;
if ( ! V_45 -> type )
free += V_45 -> V_50 ;
}
F_15 ( & F_12 ( V_8 ) -> V_47 ) ;
F_14 ( V_48 L_2 ,
V_40 , ( V_49 ) V_46 << 12 , ( V_49 ) free << 12 ) ;
F_14 ( V_48 L_3 ,
V_40 , V_42 -> V_51 << 12 ) ;
}
static int
F_16 ( struct V_1 * V_2 , unsigned long V_3 )
{
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
return 0 ;
}
static void
F_18 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
F_5 ( V_15 -> V_16 ) ;
F_19 ( V_15 -> V_16 ) ;
V_15 -> V_16 = NULL ;
}
static int
F_20 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const struct V_21 * V_22 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = F_2 ( V_20 -> V_6 ) ;
struct V_23 * V_24 = V_23 ( V_20 ) ;
struct V_11 * V_12 ;
V_12 = F_21 ( sizeof( * V_12 ) , V_52 ) ;
if ( ! V_12 )
return - V_29 ;
V_12 -> V_32 = 12 ;
switch ( V_5 -> V_9 . V_27 . V_53 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
break;
case V_59 :
if ( V_5 -> V_9 . V_27 . V_60 != 0x50 )
V_12 -> V_61 = ( V_24 -> V_30 & 0x7f00 ) >> 8 ;
break;
case V_62 :
case V_63 :
case V_64 :
V_12 -> V_61 = ( V_24 -> V_30 & 0xff00 ) >> 8 ;
break;
default:
F_22 ( V_5 , L_4 , V_65 ,
V_5 -> V_9 . V_27 . V_53 ) ;
break;
}
V_15 -> V_16 = V_12 ;
V_15 -> V_38 = 0 ;
return 0 ;
}
static void
F_23 ( struct V_1 * V_2 , const char * V_40 )
{
}
static int
F_24 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_66 * V_67 = F_25 ( & V_5 -> V_9 ) ;
struct V_68 * V_10 = ( void * ) V_67 ;
struct V_69 * V_70 = NULL ;
F_26 ( V_10 -> V_70 , & V_70 , NULL ) ;
V_2 -> V_10 = V_70 ;
return 0 ;
}
static int
F_27 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = V_2 -> V_10 ;
F_26 ( NULL , & V_70 , NULL ) ;
V_2 -> V_10 = NULL ;
return 0 ;
}
static void
F_28 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_11 * V_12 = V_15 -> V_16 ;
if ( V_12 -> V_13 [ 0 ] . V_12 )
F_7 ( & V_12 -> V_13 [ 0 ] ) ;
F_19 ( V_15 -> V_16 ) ;
V_15 -> V_16 = NULL ;
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const struct V_21 * V_22 ,
struct V_14 * V_15 )
{
struct V_11 * V_12 ;
int V_26 ;
V_12 = F_21 ( sizeof( * V_12 ) , V_52 ) ;
if ( ! V_12 )
return - V_29 ;
V_12 -> V_32 = 12 ;
V_26 = F_30 ( V_2 -> V_10 , V_15 -> V_34 << 12 , V_12 -> V_32 ,
V_71 , & V_12 -> V_13 [ 0 ] ) ;
if ( V_26 ) {
F_19 ( V_12 ) ;
return V_26 ;
}
V_15 -> V_16 = V_12 ;
V_15 -> V_38 = V_12 -> V_13 [ 0 ] . V_39 >> V_35 ;
return 0 ;
}
static void
F_31 ( struct V_1 * V_2 , const char * V_40 )
{
}
int
F_32 ( struct V_72 * V_73 , struct V_74 * V_13 )
{
struct V_75 * V_76 = V_73 -> V_77 ;
struct V_4 * V_5 = V_4 ( V_76 -> V_78 -> V_79 ) ;
if ( F_33 ( V_13 -> V_80 < V_81 ) )
return F_34 ( V_73 , V_13 ) ;
return F_35 ( V_73 , V_13 , & V_5 -> V_82 . V_6 ) ;
}
static int
F_36 ( struct V_83 * V_84 )
{
return F_37 ( V_84 -> V_85 ) ;
}
static void
F_38 ( struct V_83 * V_84 )
{
F_39 ( V_84 -> V_85 ) ;
}
int
F_40 ( struct V_4 * V_5 )
{
struct V_83 * V_86 ;
int V_26 ;
V_86 = & V_5 -> V_82 . V_87 ;
V_86 -> V_88 = V_89 ;
V_86 -> V_90 = sizeof( struct V_91 ) ;
V_86 -> V_92 = & F_36 ;
V_86 -> V_93 = & F_38 ;
V_26 = F_41 ( V_86 ) ;
if ( F_33 ( V_26 != 0 ) ) {
F_42 ( L_5 ) ;
V_5 -> V_82 . V_87 . V_93 = NULL ;
return V_26 ;
}
V_5 -> V_82 . V_94 . V_95 = V_86 -> V_85 ;
V_86 = & V_5 -> V_82 . V_94 . V_84 ;
V_86 -> V_88 = V_96 ;
V_86 -> V_90 = sizeof( struct V_97 ) ;
V_86 -> V_92 = & V_98 ;
V_86 -> V_93 = & V_99 ;
V_26 = F_41 ( V_86 ) ;
if ( F_33 ( V_26 != 0 ) ) {
F_42 ( L_6 ) ;
F_43 ( & V_5 -> V_82 . V_87 ) ;
V_5 -> V_82 . V_87 . V_93 = NULL ;
return V_26 ;
}
return 0 ;
}
void
F_44 ( struct V_4 * V_5 )
{
if ( V_5 -> V_82 . V_87 . V_93 == NULL )
return;
F_43 ( & V_5 -> V_82 . V_94 . V_84 ) ;
F_43 ( & V_5 -> V_82 . V_87 ) ;
V_5 -> V_82 . V_87 . V_93 = NULL ;
}
int
F_45 ( struct V_4 * V_5 )
{
struct V_100 * V_79 = V_5 -> V_79 ;
T_1 V_101 ;
int V_26 ;
V_101 = F_25 ( & V_5 -> V_9 ) -> V_102 ;
if ( F_46 ( F_47 ( & V_5 -> V_9 ) ) ) {
if ( V_5 -> V_103 . V_104 == V_105 ||
! F_48 ( V_79 -> V_106 , F_49 ( V_101 ) ) )
V_101 = 32 ;
V_26 = F_50 ( V_79 -> V_106 , F_49 ( V_101 ) ) ;
if ( V_26 )
return V_26 ;
V_26 = F_51 ( V_79 -> V_106 ,
F_49 ( V_101 ) ) ;
if ( V_26 )
F_51 ( V_79 -> V_106 ,
F_49 ( 32 ) ) ;
}
V_26 = F_40 ( V_5 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_52 ( & V_5 -> V_82 . V_6 ,
V_5 -> V_82 . V_94 . V_84 . V_85 ,
& V_107 ,
V_79 -> V_108 -> V_109 ,
V_81 ,
V_101 <= 32 ? true : false ) ;
if ( V_26 ) {
F_53 ( V_5 , L_7 , V_26 ) ;
return V_26 ;
}
V_5 -> V_110 . V_111 = V_5 -> V_9 . V_27 . V_112 ;
V_26 = F_54 ( & V_5 -> V_82 . V_6 , V_113 ,
V_5 -> V_110 . V_111 >> V_35 ) ;
if ( V_26 ) {
F_53 ( V_5 , L_8 , V_26 ) ;
return V_26 ;
}
V_5 -> V_82 . V_114 = F_55 ( F_56 ( F_47 ( & V_5 -> V_9 ) , 1 ) ,
F_57 ( F_47 ( & V_5 -> V_9 ) , 1 ) ) ;
if ( V_5 -> V_103 . V_104 != V_105 ) {
V_5 -> V_110 . V_115 = F_25 ( & V_5 -> V_9 ) -> V_116 ;
} else {
V_5 -> V_110 . V_115 = V_5 -> V_103 . V_90 ;
}
V_26 = F_54 ( & V_5 -> V_82 . V_6 , V_117 ,
V_5 -> V_110 . V_115 >> V_35 ) ;
if ( V_26 ) {
F_53 ( V_5 , L_9 , V_26 ) ;
return V_26 ;
}
F_58 ( V_5 , L_10 , ( T_1 ) ( V_5 -> V_110 . V_111 >> 20 ) ) ;
F_58 ( V_5 , L_11 , ( T_1 ) ( V_5 -> V_110 . V_115 >> 20 ) ) ;
return 0 ;
}
void
F_59 ( struct V_4 * V_5 )
{
F_11 ( & V_5 -> V_79 -> V_118 ) ;
F_60 ( & V_5 -> V_82 . V_6 , V_113 ) ;
F_60 ( & V_5 -> V_82 . V_6 , V_117 ) ;
F_15 ( & V_5 -> V_79 -> V_118 ) ;
F_61 ( & V_5 -> V_82 . V_6 ) ;
F_44 ( V_5 ) ;
F_62 ( V_5 -> V_82 . V_114 ) ;
V_5 -> V_82 . V_114 = 0 ;
}
