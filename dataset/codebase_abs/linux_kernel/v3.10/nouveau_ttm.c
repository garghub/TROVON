static int
F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_7 * V_8 = V_7 ( V_5 -> V_9 ) ;
V_2 -> V_10 = V_8 ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_2 )
{
V_2 -> V_10 = NULL ;
return 0 ;
}
static inline void
F_4 ( struct V_11 * V_12 )
{
if ( V_12 -> V_13 [ 0 ] . V_12 ) {
F_5 ( & V_12 -> V_13 [ 0 ] ) ;
F_6 ( & V_12 -> V_13 [ 0 ] ) ;
}
if ( V_12 -> V_13 [ 1 ] . V_12 ) {
F_5 ( & V_12 -> V_13 [ 1 ] ) ;
F_6 ( & V_12 -> V_13 [ 1 ] ) ;
}
}
static void
F_7 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_7 * V_8 = V_7 ( V_5 -> V_9 ) ;
F_4 ( V_15 -> V_16 ) ;
V_8 -> V_17 . V_18 ( V_8 , (struct V_11 * * ) & V_15 -> V_16 ) ;
}
static int
F_8 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_7 * V_8 = V_7 ( V_5 -> V_9 ) ;
struct V_23 * V_24 = V_23 ( V_20 ) ;
struct V_11 * V_12 ;
T_1 V_25 = 0 ;
int V_26 ;
if ( V_24 -> V_27 & V_28 )
V_25 = 1 << V_24 -> V_29 ;
V_26 = V_8 -> V_17 . V_30 ( V_8 , V_15 -> V_31 << V_32 ,
V_15 -> V_33 << V_32 , V_25 ,
( V_24 -> V_27 >> 8 ) & 0x3ff , & V_12 ) ;
if ( V_26 ) {
V_15 -> V_16 = NULL ;
return ( V_26 == - V_34 ) ? 0 : V_26 ;
}
V_12 -> V_29 = V_24 -> V_29 ;
V_15 -> V_16 = V_12 ;
V_15 -> V_35 = V_12 -> V_36 >> V_32 ;
return 0 ;
}
static void
F_9 ( struct V_1 * V_2 , const char * V_37 )
{
struct V_7 * V_8 = V_2 -> V_10 ;
struct V_38 * V_39 = & V_8 -> V_40 ;
struct V_41 * V_42 ;
T_1 V_43 = 0 , free = 0 ;
F_10 ( & V_39 -> V_44 ) ;
F_11 (r, &mm->nodes, nl_entry) {
F_12 ( V_45 L_1 ,
V_37 , V_42 -> type , ( ( V_46 ) V_42 -> V_36 << 12 ) ,
( ( ( V_46 ) V_42 -> V_36 + V_42 -> V_47 ) << 12 ) ) ;
V_43 += V_42 -> V_47 ;
if ( ! V_42 -> type )
free += V_42 -> V_47 ;
}
F_13 ( & V_39 -> V_44 ) ;
F_12 ( V_45 L_2 ,
V_37 , ( V_46 ) V_43 << 12 , ( V_46 ) free << 12 ) ;
F_12 ( V_45 L_3 ,
V_37 , V_39 -> V_48 << 12 ) ;
}
static int
F_14 ( struct V_1 * V_2 , unsigned long V_3 )
{
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 )
{
return 0 ;
}
static void
F_16 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
F_4 ( V_15 -> V_16 ) ;
F_17 ( V_15 -> V_16 ) ;
V_15 -> V_16 = NULL ;
}
static int
F_18 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = F_2 ( V_20 -> V_6 ) ;
struct V_23 * V_24 = V_23 ( V_20 ) ;
struct V_11 * V_12 ;
if ( F_19 ( ( V_15 -> V_31 << V_32 ) >= 512 * 1024 * 1024 ) )
return - V_49 ;
V_12 = F_20 ( sizeof( * V_12 ) , V_50 ) ;
if ( ! V_12 )
return - V_49 ;
V_12 -> V_29 = 12 ;
switch ( F_21 ( V_5 -> V_9 ) -> V_51 ) {
case V_52 :
if ( F_21 ( V_5 -> V_9 ) -> V_53 != 0x50 )
V_12 -> V_54 = ( V_24 -> V_27 & 0x7f00 ) >> 8 ;
break;
case V_55 :
case V_56 :
case V_57 :
V_12 -> V_54 = ( V_24 -> V_27 & 0xff00 ) >> 8 ;
break;
default:
break;
}
V_15 -> V_16 = V_12 ;
V_15 -> V_35 = 0 ;
return 0 ;
}
static void
F_22 ( struct V_1 * V_2 , const char * V_37 )
{
}
static int
F_23 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_58 * V_59 = V_58 ( V_5 -> V_9 ) ;
struct V_60 * V_10 = ( void * ) V_59 ;
struct V_61 * V_62 = NULL ;
F_24 ( V_10 -> V_62 , & V_62 , NULL ) ;
V_2 -> V_10 = V_62 ;
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_10 ;
F_24 ( NULL , & V_62 , NULL ) ;
V_2 -> V_10 = NULL ;
return 0 ;
}
static void
F_26 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_11 * V_12 = V_15 -> V_16 ;
if ( V_12 -> V_13 [ 0 ] . V_12 )
F_6 ( & V_12 -> V_13 [ 0 ] ) ;
F_17 ( V_15 -> V_16 ) ;
V_15 -> V_16 = NULL ;
}
static int
F_27 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_14 * V_15 )
{
struct V_11 * V_12 ;
int V_26 ;
V_12 = F_20 ( sizeof( * V_12 ) , V_50 ) ;
if ( ! V_12 )
return - V_49 ;
V_12 -> V_29 = 12 ;
V_26 = F_28 ( V_2 -> V_10 , V_15 -> V_31 << 12 , V_12 -> V_29 ,
V_63 , & V_12 -> V_13 [ 0 ] ) ;
if ( V_26 ) {
F_17 ( V_12 ) ;
return V_26 ;
}
V_15 -> V_16 = V_12 ;
V_15 -> V_35 = V_12 -> V_13 [ 0 ] . V_36 >> V_32 ;
return 0 ;
}
static void
F_29 ( struct V_1 * V_2 , const char * V_37 )
{
}
int
F_30 ( struct V_64 * V_65 , struct V_66 * V_13 )
{
struct V_67 * V_68 = V_65 -> V_69 ;
struct V_4 * V_5 = V_4 ( V_68 -> V_70 -> V_71 ) ;
if ( F_19 ( V_13 -> V_72 < V_73 ) )
return F_31 ( V_65 , V_13 ) ;
return F_32 ( V_65 , V_13 , & V_5 -> V_74 . V_6 ) ;
}
static int
F_33 ( struct V_75 * V_76 )
{
return F_34 ( V_76 -> V_77 ) ;
}
static void
F_35 ( struct V_75 * V_76 )
{
F_36 ( V_76 -> V_77 ) ;
}
int
F_37 ( struct V_4 * V_5 )
{
struct V_75 * V_78 ;
int V_26 ;
V_78 = & V_5 -> V_74 . V_79 ;
V_78 -> V_80 = V_81 ;
V_78 -> V_82 = sizeof( struct V_83 ) ;
V_78 -> V_84 = & F_33 ;
V_78 -> V_85 = & F_35 ;
V_26 = F_38 ( V_78 ) ;
if ( F_19 ( V_26 != 0 ) ) {
F_39 ( L_4 ) ;
V_5 -> V_74 . V_79 . V_85 = NULL ;
return V_26 ;
}
V_5 -> V_74 . V_86 . V_87 = V_78 -> V_77 ;
V_78 = & V_5 -> V_74 . V_86 . V_76 ;
V_78 -> V_80 = V_88 ;
V_78 -> V_82 = sizeof( struct V_89 ) ;
V_78 -> V_84 = & V_90 ;
V_78 -> V_85 = & V_91 ;
V_26 = F_38 ( V_78 ) ;
if ( F_19 ( V_26 != 0 ) ) {
F_39 ( L_5 ) ;
F_40 ( & V_5 -> V_74 . V_79 ) ;
V_5 -> V_74 . V_79 . V_85 = NULL ;
return V_26 ;
}
return 0 ;
}
void
F_41 ( struct V_4 * V_5 )
{
if ( V_5 -> V_74 . V_79 . V_85 == NULL )
return;
F_40 ( & V_5 -> V_74 . V_86 . V_76 ) ;
F_40 ( & V_5 -> V_74 . V_79 ) ;
V_5 -> V_74 . V_79 . V_85 = NULL ;
}
int
F_42 ( struct V_4 * V_5 )
{
struct V_92 * V_71 = V_5 -> V_71 ;
T_1 V_93 ;
int V_26 ;
V_93 = V_58 ( V_5 -> V_9 ) -> V_94 ;
if ( V_5 -> V_95 . V_96 == V_97 ||
! F_43 ( V_71 -> V_98 , F_44 ( V_93 ) ) )
V_93 = 32 ;
V_26 = F_45 ( V_71 -> V_98 , F_44 ( V_93 ) ) ;
if ( V_26 )
return V_26 ;
V_26 = F_46 ( V_71 -> V_98 , F_44 ( V_93 ) ) ;
if ( V_26 )
F_46 ( V_71 -> V_98 , F_44 ( 32 ) ) ;
V_26 = F_37 ( V_5 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_47 ( & V_5 -> V_74 . V_6 ,
V_5 -> V_74 . V_86 . V_76 . V_77 ,
& V_99 , V_73 ,
V_93 <= 32 ? true : false ) ;
if ( V_26 ) {
F_48 ( V_5 , L_6 , V_26 ) ;
return V_26 ;
}
V_5 -> V_100 . V_101 = V_7 ( V_5 -> V_9 ) -> V_17 . V_82 ;
V_5 -> V_100 . V_101 -= F_49 ( V_5 -> V_9 ) -> V_102 ;
V_26 = F_50 ( & V_5 -> V_74 . V_6 , V_103 ,
V_5 -> V_100 . V_101 >> V_32 ) ;
if ( V_26 ) {
F_48 ( V_5 , L_7 , V_26 ) ;
return V_26 ;
}
V_5 -> V_74 . V_104 = F_51 ( F_52 ( V_71 -> V_98 , 1 ) ,
F_53 ( V_71 -> V_98 , 1 ) ,
V_105 ) ;
if ( V_5 -> V_95 . V_96 != V_97 ) {
V_5 -> V_100 . V_106 = V_58 ( V_5 -> V_9 ) -> V_107 ;
if ( V_5 -> V_100 . V_106 > 512 * 1024 * 1024 )
V_5 -> V_100 . V_106 = 512 * 1024 * 1024 ;
} else {
V_5 -> V_100 . V_106 = V_5 -> V_95 . V_82 ;
}
V_26 = F_50 ( & V_5 -> V_74 . V_6 , V_108 ,
V_5 -> V_100 . V_106 >> V_32 ) ;
if ( V_26 ) {
F_48 ( V_5 , L_8 , V_26 ) ;
return V_26 ;
}
F_54 ( V_5 , L_9 , ( T_1 ) ( V_5 -> V_100 . V_101 >> 20 ) ) ;
F_54 ( V_5 , L_10 , ( T_1 ) ( V_5 -> V_100 . V_106 >> 20 ) ) ;
return 0 ;
}
void
F_55 ( struct V_4 * V_5 )
{
F_10 ( & V_5 -> V_71 -> V_109 ) ;
F_56 ( & V_5 -> V_74 . V_6 , V_103 ) ;
F_56 ( & V_5 -> V_74 . V_6 , V_108 ) ;
F_13 ( & V_5 -> V_71 -> V_109 ) ;
F_57 ( & V_5 -> V_74 . V_6 ) ;
F_41 ( V_5 ) ;
if ( V_5 -> V_74 . V_104 >= 0 ) {
F_58 ( V_5 -> V_74 . V_104 ,
F_52 ( V_5 -> V_71 -> V_98 , 1 ) ,
F_53 ( V_5 -> V_71 -> V_98 , 1 ) , V_105 ) ;
V_5 -> V_74 . V_104 = - 1 ;
}
}
