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
struct V_21 * V_22 ,
T_1 V_23 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_7 * V_8 = F_3 ( & V_5 -> V_9 ) ;
struct V_24 * V_25 = V_24 ( V_20 ) ;
struct V_11 * V_12 ;
T_2 V_26 = 0 ;
int V_27 ;
if ( V_25 -> V_28 & V_29 )
V_26 = 1 << V_25 -> V_30 ;
V_27 = V_8 -> V_17 -> V_31 ( V_8 , V_15 -> V_32 << V_33 ,
V_15 -> V_34 << V_33 , V_26 ,
( V_25 -> V_28 >> 8 ) & 0x3ff , & V_12 ) ;
if ( V_27 ) {
V_15 -> V_16 = NULL ;
return ( V_27 == - V_35 ) ? 0 : V_27 ;
}
V_12 -> V_30 = V_25 -> V_30 ;
V_15 -> V_16 = V_12 ;
V_15 -> V_36 = V_12 -> V_37 >> V_33 ;
return 0 ;
}
static void
F_10 ( struct V_1 * V_2 , const char * V_38 )
{
struct V_7 * V_8 = V_2 -> V_10 ;
struct V_39 * V_40 = & V_8 -> V_41 ;
struct V_42 * V_43 ;
T_2 V_44 = 0 , free = 0 ;
F_11 ( & F_12 ( V_8 ) -> V_45 ) ;
F_13 (r, &mm->nodes, nl_entry) {
F_14 ( V_46 L_1 ,
V_38 , V_43 -> type , ( ( V_47 ) V_43 -> V_37 << 12 ) ,
( ( ( V_47 ) V_43 -> V_37 + V_43 -> V_48 ) << 12 ) ) ;
V_44 += V_43 -> V_48 ;
if ( ! V_43 -> type )
free += V_43 -> V_48 ;
}
F_15 ( & F_12 ( V_8 ) -> V_45 ) ;
F_14 ( V_46 L_2 ,
V_38 , ( V_47 ) V_44 << 12 , ( V_47 ) free << 12 ) ;
F_14 ( V_46 L_3 ,
V_38 , V_40 -> V_49 << 12 ) ;
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
struct V_21 * V_22 ,
T_1 V_23 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = F_2 ( V_20 -> V_6 ) ;
struct V_24 * V_25 = V_24 ( V_20 ) ;
struct V_11 * V_12 ;
V_12 = F_21 ( sizeof( * V_12 ) , V_50 ) ;
if ( ! V_12 )
return - V_51 ;
V_12 -> V_30 = 12 ;
switch ( V_5 -> V_9 . V_52 . V_53 ) {
case V_54 :
if ( V_5 -> V_9 . V_52 . V_55 != 0x50 )
V_12 -> V_56 = ( V_25 -> V_28 & 0x7f00 ) >> 8 ;
break;
case V_57 :
case V_58 :
V_12 -> V_56 = ( V_25 -> V_28 & 0xff00 ) >> 8 ;
break;
default:
break;
}
V_15 -> V_16 = V_12 ;
V_15 -> V_36 = 0 ;
return 0 ;
}
static void
F_22 ( struct V_1 * V_2 , const char * V_38 )
{
}
static int
F_23 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_59 * V_60 = F_24 ( & V_5 -> V_9 ) ;
struct V_61 * V_10 = ( void * ) V_60 ;
struct V_62 * V_63 = NULL ;
F_25 ( V_10 -> V_63 , & V_63 , NULL ) ;
V_2 -> V_10 = V_63 ;
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = V_2 -> V_10 ;
F_25 ( NULL , & V_63 , NULL ) ;
V_2 -> V_10 = NULL ;
return 0 ;
}
static void
F_27 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_11 * V_12 = V_15 -> V_16 ;
if ( V_12 -> V_13 [ 0 ] . V_12 )
F_7 ( & V_12 -> V_13 [ 0 ] ) ;
F_19 ( V_15 -> V_16 ) ;
V_15 -> V_16 = NULL ;
}
static int
F_28 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_21 * V_22 ,
T_1 V_23 ,
struct V_14 * V_15 )
{
struct V_11 * V_12 ;
int V_27 ;
V_12 = F_21 ( sizeof( * V_12 ) , V_50 ) ;
if ( ! V_12 )
return - V_51 ;
V_12 -> V_30 = 12 ;
V_27 = F_29 ( V_2 -> V_10 , V_15 -> V_32 << 12 , V_12 -> V_30 ,
V_64 , & V_12 -> V_13 [ 0 ] ) ;
if ( V_27 ) {
F_19 ( V_12 ) ;
return V_27 ;
}
V_15 -> V_16 = V_12 ;
V_15 -> V_36 = V_12 -> V_13 [ 0 ] . V_37 >> V_33 ;
return 0 ;
}
static void
F_30 ( struct V_1 * V_2 , const char * V_38 )
{
}
int
F_31 ( struct V_65 * V_66 , struct V_67 * V_13 )
{
struct V_68 * V_69 = V_66 -> V_70 ;
struct V_4 * V_5 = V_4 ( V_69 -> V_71 -> V_72 ) ;
if ( F_32 ( V_13 -> V_73 < V_74 ) )
return F_33 ( V_66 , V_13 ) ;
return F_34 ( V_66 , V_13 , & V_5 -> V_75 . V_6 ) ;
}
static int
F_35 ( struct V_76 * V_77 )
{
return F_36 ( V_77 -> V_78 ) ;
}
static void
F_37 ( struct V_76 * V_77 )
{
F_38 ( V_77 -> V_78 ) ;
}
int
F_39 ( struct V_4 * V_5 )
{
struct V_76 * V_79 ;
int V_27 ;
V_79 = & V_5 -> V_75 . V_80 ;
V_79 -> V_81 = V_82 ;
V_79 -> V_83 = sizeof( struct V_84 ) ;
V_79 -> V_85 = & F_35 ;
V_79 -> V_86 = & F_37 ;
V_27 = F_40 ( V_79 ) ;
if ( F_32 ( V_27 != 0 ) ) {
F_41 ( L_4 ) ;
V_5 -> V_75 . V_80 . V_86 = NULL ;
return V_27 ;
}
V_5 -> V_75 . V_87 . V_88 = V_79 -> V_78 ;
V_79 = & V_5 -> V_75 . V_87 . V_77 ;
V_79 -> V_81 = V_89 ;
V_79 -> V_83 = sizeof( struct V_90 ) ;
V_79 -> V_85 = & V_91 ;
V_79 -> V_86 = & V_92 ;
V_27 = F_40 ( V_79 ) ;
if ( F_32 ( V_27 != 0 ) ) {
F_41 ( L_5 ) ;
F_42 ( & V_5 -> V_75 . V_80 ) ;
V_5 -> V_75 . V_80 . V_86 = NULL ;
return V_27 ;
}
return 0 ;
}
void
F_43 ( struct V_4 * V_5 )
{
if ( V_5 -> V_75 . V_80 . V_86 == NULL )
return;
F_42 ( & V_5 -> V_75 . V_87 . V_77 ) ;
F_42 ( & V_5 -> V_75 . V_80 ) ;
V_5 -> V_75 . V_80 . V_86 = NULL ;
}
int
F_44 ( struct V_4 * V_5 )
{
struct V_93 * V_72 = V_5 -> V_72 ;
T_2 V_94 ;
int V_27 ;
V_94 = F_24 ( & V_5 -> V_9 ) -> V_95 ;
if ( F_45 ( F_46 ( & V_5 -> V_9 ) ) ) {
if ( V_5 -> V_96 . V_97 == V_98 ||
! F_47 ( V_72 -> V_99 , F_48 ( V_94 ) ) )
V_94 = 32 ;
V_27 = F_49 ( V_72 -> V_99 , F_48 ( V_94 ) ) ;
if ( V_27 )
return V_27 ;
V_27 = F_50 ( V_72 -> V_99 ,
F_48 ( V_94 ) ) ;
if ( V_27 )
F_50 ( V_72 -> V_99 ,
F_48 ( 32 ) ) ;
}
V_27 = F_39 ( V_5 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_51 ( & V_5 -> V_75 . V_6 ,
V_5 -> V_75 . V_87 . V_77 . V_78 ,
& V_100 ,
V_72 -> V_101 -> V_102 ,
V_74 ,
V_94 <= 32 ? true : false ) ;
if ( V_27 ) {
F_52 ( V_5 , L_6 , V_27 ) ;
return V_27 ;
}
V_5 -> V_103 . V_104 = V_5 -> V_9 . V_52 . V_105 ;
V_27 = F_53 ( & V_5 -> V_75 . V_6 , V_106 ,
V_5 -> V_103 . V_104 >> V_33 ) ;
if ( V_27 ) {
F_52 ( V_5 , L_7 , V_27 ) ;
return V_27 ;
}
V_5 -> V_75 . V_107 = F_54 ( F_55 ( F_46 ( & V_5 -> V_9 ) , 1 ) ,
F_56 ( F_46 ( & V_5 -> V_9 ) , 1 ) ) ;
if ( V_5 -> V_96 . V_97 != V_98 ) {
V_5 -> V_103 . V_108 = F_24 ( & V_5 -> V_9 ) -> V_109 ;
} else {
V_5 -> V_103 . V_108 = V_5 -> V_96 . V_83 ;
}
V_27 = F_53 ( & V_5 -> V_75 . V_6 , V_110 ,
V_5 -> V_103 . V_108 >> V_33 ) ;
if ( V_27 ) {
F_52 ( V_5 , L_8 , V_27 ) ;
return V_27 ;
}
F_57 ( V_5 , L_9 , ( T_2 ) ( V_5 -> V_103 . V_104 >> 20 ) ) ;
F_57 ( V_5 , L_10 , ( T_2 ) ( V_5 -> V_103 . V_108 >> 20 ) ) ;
return 0 ;
}
void
F_58 ( struct V_4 * V_5 )
{
F_11 ( & V_5 -> V_72 -> V_111 ) ;
F_59 ( & V_5 -> V_75 . V_6 , V_106 ) ;
F_59 ( & V_5 -> V_75 . V_6 , V_110 ) ;
F_15 ( & V_5 -> V_72 -> V_111 ) ;
F_60 ( & V_5 -> V_75 . V_6 ) ;
F_43 ( V_5 ) ;
F_61 ( V_5 -> V_75 . V_107 ) ;
V_5 -> V_75 . V_107 = 0 ;
}
