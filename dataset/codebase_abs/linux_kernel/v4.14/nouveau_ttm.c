static int
F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_7 * V_8 = F_3 ( & V_5 -> V_9 . V_10 ) ;
V_2 -> V_11 = V_8 ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 )
{
V_2 -> V_11 = NULL ;
return 0 ;
}
static inline void
F_5 ( struct V_12 * V_13 )
{
if ( V_13 -> V_14 [ 0 ] . V_13 ) {
F_6 ( & V_13 -> V_14 [ 0 ] ) ;
F_7 ( & V_13 -> V_14 [ 0 ] ) ;
}
if ( V_13 -> V_14 [ 1 ] . V_13 ) {
F_6 ( & V_13 -> V_14 [ 1 ] ) ;
F_7 ( & V_13 -> V_14 [ 1 ] ) ;
}
}
static void
F_8 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_17 * V_18 = F_3 ( & V_5 -> V_9 . V_10 ) -> V_18 ;
F_5 ( V_16 -> V_19 ) ;
V_18 -> V_20 -> V_21 ( V_18 , (struct V_12 * * ) & V_16 -> V_19 ) ;
}
static int
F_9 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
const struct V_24 * V_25 ,
struct V_15 * V_16 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_17 * V_18 = F_3 ( & V_5 -> V_9 . V_10 ) -> V_18 ;
struct V_26 * V_27 = V_26 ( V_23 ) ;
struct V_12 * V_13 ;
T_1 V_28 = 0 ;
int V_29 ;
if ( V_5 -> V_9 . V_10 . V_30 . V_31 == 0 )
return - V_32 ;
if ( V_27 -> V_33 & V_34 )
V_28 = 1 << V_27 -> V_35 ;
V_29 = V_18 -> V_20 -> V_36 ( V_18 , V_16 -> V_37 << V_38 ,
V_16 -> V_39 << V_38 , V_28 ,
( V_27 -> V_33 >> 8 ) & 0x3ff , & V_13 ) ;
if ( V_29 ) {
V_16 -> V_19 = NULL ;
return ( V_29 == - V_40 ) ? 0 : V_29 ;
}
V_13 -> V_35 = V_27 -> V_35 ;
V_16 -> V_19 = V_13 ;
V_16 -> V_41 = V_13 -> V_42 >> V_38 ;
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
struct V_15 * V_16 )
{
F_5 ( V_16 -> V_19 ) ;
F_13 ( V_16 -> V_19 ) ;
V_16 -> V_19 = NULL ;
}
static int
F_14 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
const struct V_24 * V_25 ,
struct V_15 * V_16 )
{
struct V_4 * V_5 = F_2 ( V_23 -> V_6 ) ;
struct V_26 * V_27 = V_26 ( V_23 ) ;
struct V_12 * V_13 ;
V_13 = F_15 ( sizeof( * V_13 ) , V_43 ) ;
if ( ! V_13 )
return - V_32 ;
V_13 -> V_35 = 12 ;
switch ( V_5 -> V_9 . V_10 . V_30 . V_44 ) {
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
break;
case V_50 :
if ( V_5 -> V_9 . V_10 . V_30 . V_51 != 0x50 )
V_13 -> V_52 = ( V_27 -> V_33 & 0x7f00 ) >> 8 ;
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_13 -> V_52 = ( V_27 -> V_33 & 0xff00 ) >> 8 ;
break;
default:
F_16 ( V_5 , L_1 , V_57 ,
V_5 -> V_9 . V_10 . V_30 . V_44 ) ;
break;
}
V_16 -> V_19 = V_13 ;
V_16 -> V_41 = 0 ;
return 0 ;
}
static void
F_17 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
}
static int
F_18 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_60 * V_61 = F_19 ( & V_5 -> V_9 . V_10 ) ;
struct V_62 * V_11 = ( void * ) V_61 ;
struct V_63 * V_64 = NULL ;
F_20 ( V_11 -> V_64 , & V_64 , NULL ) ;
V_2 -> V_11 = V_64 ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = V_2 -> V_11 ;
F_20 ( NULL , & V_64 , NULL ) ;
V_2 -> V_11 = NULL ;
return 0 ;
}
static void
F_22 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_12 * V_13 = V_16 -> V_19 ;
if ( V_13 -> V_14 [ 0 ] . V_13 )
F_7 ( & V_13 -> V_14 [ 0 ] ) ;
F_13 ( V_16 -> V_19 ) ;
V_16 -> V_19 = NULL ;
}
static int
F_23 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
const struct V_24 * V_25 ,
struct V_15 * V_16 )
{
struct V_12 * V_13 ;
int V_29 ;
V_13 = F_15 ( sizeof( * V_13 ) , V_43 ) ;
if ( ! V_13 )
return - V_32 ;
V_13 -> V_35 = 12 ;
V_29 = F_24 ( V_2 -> V_11 , V_16 -> V_37 << 12 , V_13 -> V_35 ,
V_65 , & V_13 -> V_14 [ 0 ] ) ;
if ( V_29 ) {
F_13 ( V_13 ) ;
return V_29 ;
}
V_16 -> V_19 = V_13 ;
V_16 -> V_41 = V_13 -> V_14 [ 0 ] . V_42 >> V_38 ;
return 0 ;
}
static void
F_25 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
}
int
F_26 ( struct V_66 * V_67 , struct V_68 * V_14 )
{
struct V_69 * V_70 = V_67 -> V_71 ;
struct V_4 * V_5 = V_4 ( V_70 -> V_72 -> V_73 ) ;
if ( F_27 ( V_14 -> V_74 < V_75 ) )
return F_28 ( V_67 , V_14 ) ;
return F_29 ( V_67 , V_14 , & V_5 -> V_76 . V_6 ) ;
}
static int
F_30 ( struct V_77 * V_78 )
{
return F_31 ( V_78 -> V_79 ) ;
}
static void
F_32 ( struct V_77 * V_78 )
{
F_33 ( V_78 -> V_79 ) ;
}
int
F_34 ( struct V_4 * V_5 )
{
struct V_77 * V_80 ;
int V_29 ;
V_80 = & V_5 -> V_76 . V_81 ;
V_80 -> V_82 = V_83 ;
V_80 -> V_84 = sizeof( struct V_85 ) ;
V_80 -> V_86 = & F_30 ;
V_80 -> V_87 = & F_32 ;
V_29 = F_35 ( V_80 ) ;
if ( F_27 ( V_29 != 0 ) ) {
F_36 ( L_2 ) ;
V_5 -> V_76 . V_81 . V_87 = NULL ;
return V_29 ;
}
V_5 -> V_76 . V_88 . V_89 = V_80 -> V_79 ;
V_80 = & V_5 -> V_76 . V_88 . V_78 ;
V_80 -> V_82 = V_90 ;
V_80 -> V_84 = sizeof( struct V_91 ) ;
V_80 -> V_86 = & V_92 ;
V_80 -> V_87 = & V_93 ;
V_29 = F_35 ( V_80 ) ;
if ( F_27 ( V_29 != 0 ) ) {
F_36 ( L_3 ) ;
F_37 ( & V_5 -> V_76 . V_81 ) ;
V_5 -> V_76 . V_81 . V_87 = NULL ;
return V_29 ;
}
return 0 ;
}
void
F_38 ( struct V_4 * V_5 )
{
if ( V_5 -> V_76 . V_81 . V_87 == NULL )
return;
F_37 ( & V_5 -> V_76 . V_88 . V_78 ) ;
F_37 ( & V_5 -> V_76 . V_81 ) ;
V_5 -> V_76 . V_81 . V_87 = NULL ;
}
int
F_39 ( struct V_4 * V_5 )
{
struct V_94 * V_10 = F_40 ( & V_5 -> V_9 . V_10 ) ;
struct V_95 * V_96 = V_10 -> V_96 ;
struct V_97 * V_73 = V_5 -> V_73 ;
T_2 V_98 ;
int V_29 ;
if ( V_96 && V_96 -> V_99 . V_100 ) {
V_5 -> V_99 . V_100 = V_96 -> V_99 . V_100 ;
V_5 -> V_99 . V_101 = V_96 -> V_99 . V_101 ;
V_5 -> V_99 . V_84 = V_96 -> V_99 . V_84 ;
V_5 -> V_99 . V_102 = V_96 -> V_99 . V_102 ;
}
V_98 = F_19 ( & V_5 -> V_9 . V_10 ) -> V_103 ;
if ( F_40 ( & V_5 -> V_9 . V_10 ) -> V_20 -> V_96 ) {
if ( V_5 -> V_99 . V_100 )
V_98 = 32 ;
} else if ( V_10 -> V_20 -> V_104 ) {
struct V_105 * V_104 = V_10 -> V_20 -> V_104 ( V_10 ) ;
if ( V_104 -> V_20 -> V_106 )
V_98 = F_41 ( V_98 , V_104 -> V_20 -> V_106 ) ;
}
V_29 = F_42 ( V_73 -> V_73 , F_43 ( V_98 ) ) ;
if ( V_29 && V_98 != 32 ) {
V_98 = 32 ;
V_29 = F_42 ( V_73 -> V_73 , F_43 ( V_98 ) ) ;
}
if ( V_29 )
return V_29 ;
V_29 = F_44 ( V_73 -> V_73 , F_43 ( V_98 ) ) ;
if ( V_29 )
F_44 ( V_73 -> V_73 , F_43 ( 32 ) ) ;
V_29 = F_34 ( V_5 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_45 ( & V_5 -> V_76 . V_6 ,
V_5 -> V_76 . V_88 . V_78 . V_79 ,
& V_107 ,
V_73 -> V_108 -> V_109 ,
V_75 ,
V_98 <= 32 ? true : false ) ;
if ( V_29 ) {
F_46 ( V_5 , L_4 , V_29 ) ;
return V_29 ;
}
V_5 -> V_110 . V_111 = V_5 -> V_9 . V_10 . V_30 . V_112 ;
F_47 ( V_10 -> V_20 -> V_113 ( V_10 , 1 ) ,
V_10 -> V_20 -> V_114 ( V_10 , 1 ) ) ;
V_29 = F_48 ( & V_5 -> V_76 . V_6 , V_115 ,
V_5 -> V_110 . V_111 >> V_38 ) ;
if ( V_29 ) {
F_46 ( V_5 , L_5 , V_29 ) ;
return V_29 ;
}
V_5 -> V_76 . V_116 = F_49 ( V_10 -> V_20 -> V_113 ( V_10 , 1 ) ,
V_10 -> V_20 -> V_114 ( V_10 , 1 ) ) ;
if ( ! V_5 -> V_99 . V_100 ) {
V_5 -> V_110 . V_117 = F_19 ( & V_5 -> V_9 . V_10 ) -> V_118 ;
} else {
V_5 -> V_110 . V_117 = V_5 -> V_99 . V_84 ;
}
V_29 = F_48 ( & V_5 -> V_76 . V_6 , V_119 ,
V_5 -> V_110 . V_117 >> V_38 ) ;
if ( V_29 ) {
F_46 ( V_5 , L_6 , V_29 ) ;
return V_29 ;
}
F_50 ( V_5 , L_7 , ( T_1 ) ( V_5 -> V_110 . V_111 >> 20 ) ) ;
F_50 ( V_5 , L_8 , ( T_1 ) ( V_5 -> V_110 . V_117 >> 20 ) ) ;
return 0 ;
}
void
F_51 ( struct V_4 * V_5 )
{
struct V_94 * V_10 = F_40 ( & V_5 -> V_9 . V_10 ) ;
F_52 ( & V_5 -> V_76 . V_6 , V_115 ) ;
F_52 ( & V_5 -> V_76 . V_6 , V_119 ) ;
F_53 ( & V_5 -> V_76 . V_6 ) ;
F_38 ( V_5 ) ;
F_54 ( V_5 -> V_76 . V_116 ) ;
V_5 -> V_76 . V_116 = 0 ;
F_55 ( V_10 -> V_20 -> V_113 ( V_10 , 1 ) ,
V_10 -> V_20 -> V_114 ( V_10 , 1 ) ) ;
}
