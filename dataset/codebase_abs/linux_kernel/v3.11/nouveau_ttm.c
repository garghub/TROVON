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
V_8 -> V_17 -> V_18 ( V_8 , (struct V_11 * * ) & V_15 -> V_16 ) ;
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
V_26 = V_8 -> V_17 -> V_30 ( V_8 , V_15 -> V_31 << V_32 ,
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
F_10 ( & F_11 ( V_8 ) -> V_44 ) ;
F_12 (r, &mm->nodes, nl_entry) {
F_13 ( V_45 L_1 ,
V_37 , V_42 -> type , ( ( V_46 ) V_42 -> V_36 << 12 ) ,
( ( ( V_46 ) V_42 -> V_36 + V_42 -> V_47 ) << 12 ) ) ;
V_43 += V_42 -> V_47 ;
if ( ! V_42 -> type )
free += V_42 -> V_47 ;
}
F_14 ( & F_11 ( V_8 ) -> V_44 ) ;
F_13 ( V_45 L_2 ,
V_37 , ( V_46 ) V_43 << 12 , ( V_46 ) free << 12 ) ;
F_13 ( V_45 L_3 ,
V_37 , V_39 -> V_48 << 12 ) ;
}
static int
F_15 ( struct V_1 * V_2 , unsigned long V_3 )
{
return 0 ;
}
static int
F_16 ( struct V_1 * V_2 )
{
return 0 ;
}
static void
F_17 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
F_4 ( V_15 -> V_16 ) ;
F_18 ( V_15 -> V_16 ) ;
V_15 -> V_16 = NULL ;
}
static int
F_19 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = F_2 ( V_20 -> V_6 ) ;
struct V_23 * V_24 = V_23 ( V_20 ) ;
struct V_11 * V_12 ;
V_12 = F_20 ( sizeof( * V_12 ) , V_49 ) ;
if ( ! V_12 )
return - V_50 ;
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
F_18 ( V_15 -> V_16 ) ;
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
V_12 = F_20 ( sizeof( * V_12 ) , V_49 ) ;
if ( ! V_12 )
return - V_50 ;
V_12 -> V_29 = 12 ;
V_26 = F_28 ( V_2 -> V_10 , V_15 -> V_31 << 12 , V_12 -> V_29 ,
V_63 , & V_12 -> V_13 [ 0 ] ) ;
if ( V_26 ) {
F_18 ( V_12 ) ;
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
if ( F_31 ( V_13 -> V_72 < V_73 ) )
return F_32 ( V_65 , V_13 ) ;
return F_33 ( V_65 , V_13 , & V_5 -> V_74 . V_6 ) ;
}
static int
F_34 ( struct V_75 * V_76 )
{
return F_35 ( V_76 -> V_77 ) ;
}
static void
F_36 ( struct V_75 * V_76 )
{
F_37 ( V_76 -> V_77 ) ;
}
int
F_38 ( struct V_4 * V_5 )
{
struct V_75 * V_78 ;
int V_26 ;
V_78 = & V_5 -> V_74 . V_79 ;
V_78 -> V_80 = V_81 ;
V_78 -> V_82 = sizeof( struct V_83 ) ;
V_78 -> V_84 = & F_34 ;
V_78 -> V_85 = & F_36 ;
V_26 = F_39 ( V_78 ) ;
if ( F_31 ( V_26 != 0 ) ) {
F_40 ( L_4 ) ;
V_5 -> V_74 . V_79 . V_85 = NULL ;
return V_26 ;
}
V_5 -> V_74 . V_86 . V_87 = V_78 -> V_77 ;
V_78 = & V_5 -> V_74 . V_86 . V_76 ;
V_78 -> V_80 = V_88 ;
V_78 -> V_82 = sizeof( struct V_89 ) ;
V_78 -> V_84 = & V_90 ;
V_78 -> V_85 = & V_91 ;
V_26 = F_39 ( V_78 ) ;
if ( F_31 ( V_26 != 0 ) ) {
F_40 ( L_5 ) ;
F_41 ( & V_5 -> V_74 . V_79 ) ;
V_5 -> V_74 . V_79 . V_85 = NULL ;
return V_26 ;
}
return 0 ;
}
void
F_42 ( struct V_4 * V_5 )
{
if ( V_5 -> V_74 . V_79 . V_85 == NULL )
return;
F_41 ( & V_5 -> V_74 . V_86 . V_76 ) ;
F_41 ( & V_5 -> V_74 . V_79 ) ;
V_5 -> V_74 . V_79 . V_85 = NULL ;
}
int
F_43 ( struct V_4 * V_5 )
{
struct V_92 * V_71 = V_5 -> V_71 ;
T_1 V_93 ;
int V_26 ;
V_93 = V_58 ( V_5 -> V_9 ) -> V_94 ;
if ( V_5 -> V_95 . V_96 == V_97 ||
! F_44 ( V_71 -> V_98 , F_45 ( V_93 ) ) )
V_93 = 32 ;
V_26 = F_46 ( V_71 -> V_98 , F_45 ( V_93 ) ) ;
if ( V_26 )
return V_26 ;
V_26 = F_47 ( V_71 -> V_98 , F_45 ( V_93 ) ) ;
if ( V_26 )
F_47 ( V_71 -> V_98 , F_45 ( 32 ) ) ;
V_26 = F_38 ( V_5 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_48 ( & V_5 -> V_74 . V_6 ,
V_5 -> V_74 . V_86 . V_76 . V_77 ,
& V_99 , V_73 ,
V_93 <= 32 ? true : false ) ;
if ( V_26 ) {
F_49 ( V_5 , L_6 , V_26 ) ;
return V_26 ;
}
V_5 -> V_100 . V_101 = V_7 ( V_5 -> V_9 ) -> V_17 -> V_82 ;
V_5 -> V_100 . V_101 -= F_50 ( V_5 -> V_9 ) -> V_102 ;
V_26 = F_51 ( & V_5 -> V_74 . V_6 , V_103 ,
V_5 -> V_100 . V_101 >> V_32 ) ;
if ( V_26 ) {
F_49 ( V_5 , L_7 , V_26 ) ;
return V_26 ;
}
V_5 -> V_74 . V_104 = F_52 ( F_53 ( V_71 -> V_98 , 1 ) ,
F_54 ( V_71 -> V_98 , 1 ) ) ;
if ( V_5 -> V_95 . V_96 != V_97 ) {
V_5 -> V_100 . V_105 = V_58 ( V_5 -> V_9 ) -> V_106 ;
} else {
V_5 -> V_100 . V_105 = V_5 -> V_95 . V_82 ;
}
V_26 = F_51 ( & V_5 -> V_74 . V_6 , V_107 ,
V_5 -> V_100 . V_105 >> V_32 ) ;
if ( V_26 ) {
F_49 ( V_5 , L_8 , V_26 ) ;
return V_26 ;
}
F_55 ( V_5 , L_9 , ( T_1 ) ( V_5 -> V_100 . V_101 >> 20 ) ) ;
F_55 ( V_5 , L_10 , ( T_1 ) ( V_5 -> V_100 . V_105 >> 20 ) ) ;
return 0 ;
}
void
F_56 ( struct V_4 * V_5 )
{
F_10 ( & V_5 -> V_71 -> V_108 ) ;
F_57 ( & V_5 -> V_74 . V_6 , V_103 ) ;
F_57 ( & V_5 -> V_74 . V_6 , V_107 ) ;
F_14 ( & V_5 -> V_71 -> V_108 ) ;
F_58 ( & V_5 -> V_74 . V_6 ) ;
F_42 ( V_5 ) ;
F_59 ( V_5 -> V_74 . V_104 ) ;
V_5 -> V_74 . V_104 = 0 ;
}
