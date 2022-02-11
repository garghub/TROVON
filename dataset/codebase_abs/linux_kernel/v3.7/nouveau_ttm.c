static int
F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
return 0 ;
}
static int
F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void
F_3 ( struct V_4 * V_5 )
{
if ( V_5 -> V_6 [ 0 ] . V_5 ) {
F_4 ( & V_5 -> V_6 [ 0 ] ) ;
F_5 ( & V_5 -> V_6 [ 0 ] ) ;
}
if ( V_5 -> V_6 [ 1 ] . V_5 ) {
F_4 ( & V_5 -> V_6 [ 1 ] ) ;
F_5 ( & V_5 -> V_6 [ 1 ] ) ;
}
}
static void
F_6 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_7 ( V_2 -> V_11 ) ;
struct V_12 * V_13 = V_12 ( V_10 -> V_14 ) ;
F_3 ( V_8 -> V_15 ) ;
V_13 -> V_16 . V_17 ( V_13 , (struct V_4 * * ) & V_8 -> V_15 ) ;
}
static int
F_8 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_7 ( V_2 -> V_11 ) ;
struct V_12 * V_13 = V_12 ( V_10 -> V_14 ) ;
struct V_22 * V_23 = V_22 ( V_19 ) ;
struct V_4 * V_5 ;
T_1 V_24 = 0 ;
int V_25 ;
if ( V_23 -> V_26 & V_27 )
V_24 = 1 << V_23 -> V_28 ;
V_25 = V_13 -> V_16 . V_29 ( V_13 , V_8 -> V_30 << V_31 ,
V_8 -> V_32 << V_31 , V_24 ,
( V_23 -> V_26 >> 8 ) & 0x3ff , & V_5 ) ;
if ( V_25 ) {
V_8 -> V_15 = NULL ;
return ( V_25 == - V_33 ) ? 0 : V_25 ;
}
V_5 -> V_28 = V_23 -> V_28 ;
V_8 -> V_15 = V_5 ;
V_8 -> V_34 = V_5 -> V_35 >> V_31 ;
return 0 ;
}
static void
F_9 ( struct V_1 * V_2 , const char * V_36 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_40 * V_41 ;
T_1 V_42 = 0 , free = 0 ;
F_10 ( & V_38 -> V_43 ) ;
F_11 (r, &mm->nodes, nl_entry) {
F_12 ( V_44 L_1 ,
V_36 , V_41 -> type , ( ( V_45 ) V_41 -> V_35 << 12 ) ,
( ( ( V_45 ) V_41 -> V_35 + V_41 -> V_46 ) << 12 ) ) ;
V_42 += V_41 -> V_46 ;
if ( ! V_41 -> type )
free += V_41 -> V_46 ;
}
F_13 ( & V_38 -> V_43 ) ;
F_12 ( V_44 L_2 ,
V_36 , ( V_45 ) V_42 << 12 , ( V_45 ) free << 12 ) ;
F_12 ( V_44 L_3 ,
V_36 , V_38 -> V_47 << 12 ) ;
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
struct V_7 * V_8 )
{
F_3 ( V_8 -> V_15 ) ;
F_17 ( V_8 -> V_15 ) ;
V_8 -> V_15 = NULL ;
}
static int
F_18 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_4 * V_5 ;
if ( F_19 ( ( V_8 -> V_30 << V_31 ) >= 512 * 1024 * 1024 ) )
return - V_48 ;
V_5 = F_20 ( sizeof( * V_5 ) , V_49 ) ;
if ( ! V_5 )
return - V_48 ;
V_5 -> V_28 = 12 ;
V_8 -> V_15 = V_5 ;
V_8 -> V_34 = 0 ;
return 0 ;
}
static void
F_21 ( struct V_1 * V_2 , const char * V_36 )
{
}
static int
F_22 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_9 * V_10 = F_7 ( V_2 -> V_11 ) ;
struct V_50 * V_51 = V_50 ( V_10 -> V_14 ) ;
struct V_52 * V_39 = ( void * ) V_51 ;
struct V_53 * V_54 = NULL ;
F_23 ( V_39 -> V_54 , & V_54 , NULL ) ;
V_2 -> V_39 = V_54 ;
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_39 ;
F_23 ( NULL , & V_54 , NULL ) ;
V_2 -> V_39 = NULL ;
return 0 ;
}
static void
F_25 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_15 ;
if ( V_5 -> V_6 [ 0 ] . V_5 )
F_5 ( & V_5 -> V_6 [ 0 ] ) ;
F_17 ( V_8 -> V_15 ) ;
V_8 -> V_15 = NULL ;
}
static int
F_26 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_4 * V_5 ;
int V_25 ;
V_5 = F_20 ( sizeof( * V_5 ) , V_49 ) ;
if ( ! V_5 )
return - V_48 ;
V_5 -> V_28 = 12 ;
V_25 = F_27 ( V_2 -> V_39 , V_8 -> V_30 << 12 , V_5 -> V_28 ,
V_55 , & V_5 -> V_6 [ 0 ] ) ;
if ( V_25 ) {
F_17 ( V_5 ) ;
return V_25 ;
}
V_8 -> V_15 = V_5 ;
V_8 -> V_34 = V_5 -> V_6 [ 0 ] . V_35 >> V_31 ;
return 0 ;
}
static void
F_28 ( struct V_1 * V_2 , const char * V_36 )
{
}
int
F_29 ( struct V_56 * V_57 , struct V_58 * V_6 )
{
struct V_59 * V_60 = V_57 -> V_61 ;
struct V_9 * V_10 = V_9 ( V_60 -> V_62 -> V_63 ) ;
if ( F_19 ( V_6 -> V_64 < V_65 ) )
return F_30 ( V_57 , V_6 ) ;
return F_31 ( V_57 , V_6 , & V_10 -> V_66 . V_11 ) ;
}
static int
F_32 ( struct V_67 * V_68 )
{
return F_33 ( V_68 -> V_69 ) ;
}
static void
F_34 ( struct V_67 * V_68 )
{
F_35 ( V_68 -> V_69 ) ;
}
int
F_36 ( struct V_9 * V_10 )
{
struct V_67 * V_70 ;
int V_25 ;
V_70 = & V_10 -> V_66 . V_71 ;
V_70 -> V_72 = V_73 ;
V_70 -> V_74 = sizeof( struct V_75 ) ;
V_70 -> V_76 = & F_32 ;
V_70 -> V_77 = & F_34 ;
V_25 = F_37 ( V_70 ) ;
if ( F_19 ( V_25 != 0 ) ) {
F_38 ( L_4 ) ;
V_10 -> V_66 . V_71 . V_77 = NULL ;
return V_25 ;
}
V_10 -> V_66 . V_78 . V_79 = V_70 -> V_69 ;
V_70 = & V_10 -> V_66 . V_78 . V_68 ;
V_70 -> V_72 = V_80 ;
V_70 -> V_74 = sizeof( struct V_81 ) ;
V_70 -> V_76 = & V_82 ;
V_70 -> V_77 = & V_83 ;
V_25 = F_37 ( V_70 ) ;
if ( F_19 ( V_25 != 0 ) ) {
F_38 ( L_5 ) ;
F_39 ( & V_10 -> V_66 . V_71 ) ;
V_10 -> V_66 . V_71 . V_77 = NULL ;
return V_25 ;
}
return 0 ;
}
void
F_40 ( struct V_9 * V_10 )
{
if ( V_10 -> V_66 . V_71 . V_77 == NULL )
return;
F_39 ( & V_10 -> V_66 . V_78 . V_68 ) ;
F_39 ( & V_10 -> V_66 . V_71 ) ;
V_10 -> V_66 . V_71 . V_77 = NULL ;
}
int
F_41 ( struct V_9 * V_10 )
{
struct V_84 * V_63 = V_10 -> V_63 ;
T_1 V_85 ;
int V_25 ;
V_85 = V_50 ( V_10 -> V_14 ) -> V_86 ;
if ( V_10 -> V_87 . V_88 == V_89 ||
! F_42 ( V_63 -> V_90 , F_43 ( V_85 ) ) )
V_85 = 32 ;
V_25 = F_44 ( V_63 -> V_90 , F_43 ( V_85 ) ) ;
if ( V_25 )
return V_25 ;
V_25 = F_45 ( V_63 -> V_90 , F_43 ( V_85 ) ) ;
if ( V_25 )
F_45 ( V_63 -> V_90 , F_43 ( 32 ) ) ;
V_25 = F_36 ( V_10 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_46 ( & V_10 -> V_66 . V_11 ,
V_10 -> V_66 . V_78 . V_68 . V_69 ,
& V_91 , V_65 ,
V_85 <= 32 ? true : false ) ;
if ( V_25 ) {
F_47 ( V_10 , L_6 , V_25 ) ;
return V_25 ;
}
V_10 -> V_92 . V_93 = V_12 ( V_10 -> V_14 ) -> V_16 . V_74 ;
V_10 -> V_92 . V_93 -= F_48 ( V_10 -> V_14 ) -> V_94 ;
V_25 = F_49 ( & V_10 -> V_66 . V_11 , V_95 ,
V_10 -> V_92 . V_93 >> V_31 ) ;
if ( V_25 ) {
F_47 ( V_10 , L_7 , V_25 ) ;
return V_25 ;
}
V_10 -> V_66 . V_96 = F_50 ( F_51 ( V_63 -> V_90 , 1 ) ,
F_52 ( V_63 -> V_90 , 1 ) ,
V_97 ) ;
if ( V_10 -> V_87 . V_88 != V_89 ) {
V_10 -> V_92 . V_98 = V_50 ( V_10 -> V_14 ) -> V_99 ;
if ( V_10 -> V_92 . V_98 > 512 * 1024 * 1024 )
V_10 -> V_92 . V_98 = 512 * 1024 * 1024 ;
} else {
V_10 -> V_92 . V_98 = V_10 -> V_87 . V_74 ;
}
V_25 = F_49 ( & V_10 -> V_66 . V_11 , V_100 ,
V_10 -> V_92 . V_98 >> V_31 ) ;
if ( V_25 ) {
F_47 ( V_10 , L_8 , V_25 ) ;
return V_25 ;
}
F_53 ( V_10 , L_9 , ( T_1 ) ( V_10 -> V_92 . V_93 >> 20 ) ) ;
F_53 ( V_10 , L_10 , ( T_1 ) ( V_10 -> V_92 . V_98 >> 20 ) ) ;
return 0 ;
}
void
F_54 ( struct V_9 * V_10 )
{
F_10 ( & V_10 -> V_63 -> V_101 ) ;
F_55 ( & V_10 -> V_66 . V_11 , V_95 ) ;
F_55 ( & V_10 -> V_66 . V_11 , V_100 ) ;
F_13 ( & V_10 -> V_63 -> V_101 ) ;
F_56 ( & V_10 -> V_66 . V_11 ) ;
F_40 ( V_10 ) ;
if ( V_10 -> V_66 . V_96 >= 0 ) {
F_57 ( V_10 -> V_66 . V_96 ,
F_51 ( V_10 -> V_63 -> V_90 , 1 ) ,
F_52 ( V_10 -> V_63 -> V_90 , 1 ) , V_97 ) ;
V_10 -> V_66 . V_96 = - 1 ;
}
}
