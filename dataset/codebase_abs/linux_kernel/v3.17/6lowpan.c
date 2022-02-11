static inline struct V_1 * V_1 ( const struct V_2 * V_3 )
{
return F_1 ( V_3 ) ;
}
static inline void F_2 ( struct V_1 * V_4 , struct V_5 * V_6 )
{
F_3 ( & V_6 -> V_7 , & V_4 -> V_8 ) ;
F_4 ( & V_4 -> V_9 ) ;
}
static inline bool F_5 ( struct V_1 * V_4 , struct V_5 * V_6 )
{
F_6 ( & V_6 -> V_7 ) ;
F_7 ( V_10 ) ;
if ( F_8 ( & V_4 -> V_9 ) ) {
F_9 ( L_1 ) ;
return true ;
}
return false ;
}
static inline struct V_5 * F_10 ( struct V_1 * V_4 ,
T_1 * V_11 , T_2 type )
{
struct V_5 * V_6 , * V_12 ;
F_9 ( L_2 , F_11 ( & V_4 -> V_9 ) ,
V_11 , type ) ;
F_12 (peer, tmp, &dev->peers, list) {
F_9 ( L_3 ,
& V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_15 ) ;
if ( F_13 ( & V_6 -> V_13 -> V_14 , V_11 ) )
continue;
if ( type == V_6 -> V_13 -> V_15 )
return V_6 ;
}
return NULL ;
}
static inline struct V_5 * F_14 ( struct V_1 * V_4 ,
struct V_16 * V_13 )
{
struct V_5 * V_6 , * V_12 ;
F_12 (peer, tmp, &dev->peers, list) {
if ( V_6 -> V_13 == V_13 )
return V_6 ;
}
return NULL ;
}
static inline struct V_5 * F_15 ( struct V_1 * V_4 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 , * V_12 ;
F_12 (peer, tmp, &dev->peers, list) {
if ( V_6 -> V_13 -> V_18 == V_18 )
return V_6 ;
}
return NULL ;
}
static struct V_5 * F_16 ( struct V_17 * V_18 )
{
struct V_1 * V_19 , * V_12 ;
struct V_5 * V_6 = NULL ;
unsigned long V_20 ;
F_17 ( & V_21 , V_20 ) ;
F_12 (entry, tmp, &bt_6lowpan_devices, list) {
V_6 = F_15 ( V_19 , V_18 ) ;
if ( V_6 )
break;
}
F_18 ( & V_21 , V_20 ) ;
return V_6 ;
}
static struct V_1 * F_19 ( struct V_17 * V_18 )
{
struct V_1 * V_19 , * V_12 ;
struct V_1 * V_4 = NULL ;
unsigned long V_20 ;
F_17 ( & V_21 , V_20 ) ;
F_12 (entry, tmp, &bt_6lowpan_devices, list) {
if ( V_18 -> V_22 -> V_23 == V_19 -> V_23 ) {
V_4 = V_19 ;
break;
}
}
F_18 ( & V_21 , V_20 ) ;
return V_4 ;
}
static int F_20 ( struct V_24 * V_25 , struct V_2 * V_4 )
{
struct V_24 * V_26 ;
int V_27 ;
V_26 = F_21 ( V_25 , V_28 ) ;
if ( ! V_26 )
return - V_29 ;
V_27 = F_22 ( V_26 ) ;
if ( V_27 < 0 ) {
F_9 ( L_4 , V_27 ) ;
return V_30 ;
}
return V_27 ;
}
static int F_23 ( struct V_24 * V_25 , struct V_2 * V_3 ,
struct V_16 * V_13 )
{
const T_3 * V_31 , * V_32 ;
T_3 V_33 , V_34 ;
struct V_1 * V_4 ;
struct V_5 * V_6 ;
unsigned long V_20 ;
V_4 = V_1 ( V_3 ) ;
F_17 ( & V_21 , V_20 ) ;
V_6 = F_14 ( V_4 , V_13 ) ;
F_18 ( & V_21 , V_20 ) ;
if ( ! V_6 )
goto V_35;
V_31 = V_6 -> V_36 ;
V_32 = V_4 -> V_3 -> V_37 ;
if ( V_25 -> V_38 < 2 )
goto V_35;
if ( F_24 ( V_25 , & V_33 ) )
goto V_35;
if ( F_24 ( V_25 , & V_34 ) )
goto V_35;
return F_25 ( V_25 , V_3 ,
V_31 , V_39 , V_40 ,
V_32 , V_39 , V_40 ,
V_33 , V_34 , F_20 ) ;
V_35:
F_26 ( V_25 ) ;
return - V_41 ;
}
static int F_27 ( struct V_24 * V_25 , struct V_2 * V_4 ,
struct V_16 * V_13 )
{
struct V_24 * V_42 ;
int V_27 ;
if ( ! F_28 ( V_4 ) )
goto V_35;
if ( V_4 -> type != V_43 )
goto V_35;
if ( V_25 -> V_44 [ 0 ] == V_45 ) {
V_42 = F_29 ( V_25 , V_46 - 1 ,
F_30 ( V_25 ) , V_28 ) ;
if ( ! V_42 )
goto V_35;
V_42 -> V_47 = F_31 ( V_48 ) ;
V_42 -> V_49 = V_50 ;
F_32 ( V_42 ) ;
F_33 ( V_42 , sizeof( struct V_51 ) ) ;
if ( F_20 ( V_42 , V_4 ) != V_52 ) {
F_26 ( V_42 ) ;
goto V_35;
}
V_4 -> V_53 . V_54 += V_25 -> V_38 ;
V_4 -> V_53 . V_55 ++ ;
F_26 ( V_42 ) ;
F_26 ( V_25 ) ;
} else {
switch ( V_25 -> V_44 [ 0 ] & 0xe0 ) {
case V_56 :
V_42 = F_34 ( V_25 , V_28 ) ;
if ( ! V_42 )
goto V_35;
V_27 = F_23 ( V_42 , V_4 , V_13 ) ;
if ( V_27 != V_52 )
goto V_35;
V_4 -> V_53 . V_54 += V_25 -> V_38 ;
V_4 -> V_53 . V_55 ++ ;
F_26 ( V_25 ) ;
break;
default:
break;
}
}
return V_52 ;
V_35:
V_4 -> V_53 . V_57 ++ ;
F_26 ( V_25 ) ;
return V_30 ;
}
static int F_35 ( struct V_16 * V_13 , struct V_24 * V_25 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 ;
int V_58 ;
V_6 = F_16 ( V_13 -> V_18 ) ;
if ( ! V_6 )
return - V_59 ;
V_4 = F_19 ( V_13 -> V_18 ) ;
if ( ! V_4 || ! V_4 -> V_3 )
return - V_59 ;
V_58 = F_27 ( V_25 , V_4 -> V_3 , V_13 ) ;
if ( V_58 ) {
F_9 ( L_5 , V_58 ) ;
V_58 = - V_60 ;
}
return V_58 ;
}
static T_3 F_36 ( T_3 V_61 )
{
return ( ( V_61 & 0x02 ) ? V_62 : V_63 ) ;
}
static void F_37 ( struct V_64 * V_65 , T_1 * V_66 )
{
T_3 * V_67 = V_65 -> V_68 + 8 ;
V_66 -> V_69 [ 0 ] = V_67 [ 7 ] ;
V_66 -> V_69 [ 1 ] = V_67 [ 6 ] ;
V_66 -> V_69 [ 2 ] = V_67 [ 5 ] ;
V_66 -> V_69 [ 3 ] = V_67 [ 2 ] ;
V_66 -> V_69 [ 4 ] = V_67 [ 1 ] ;
V_66 -> V_69 [ 5 ] = V_67 [ 0 ] ;
}
static void F_38 ( struct V_64 * V_65 ,
T_1 * V_66 , T_3 * V_70 )
{
F_37 ( V_65 , V_66 ) ;
V_66 -> V_69 [ 5 ] ^= 0x02 ;
* V_70 = F_36 ( V_66 -> V_69 [ 5 ] ) ;
}
static int F_39 ( struct V_24 * V_25 , struct V_2 * V_3 ,
unsigned short type , const void * V_71 ,
const void * V_72 , unsigned int V_38 )
{
struct V_51 * V_73 ;
struct V_1 * V_4 ;
struct V_5 * V_6 ;
T_1 V_66 , * V_74 = V_75 ;
T_3 * V_31 , * V_32 = V_74 -> V_69 ;
T_3 V_70 ;
if ( type != V_48 )
return - V_41 ;
V_73 = F_40 ( V_25 ) ;
V_4 = V_1 ( V_3 ) ;
if ( F_41 ( & V_73 -> V_32 ) ) {
memcpy ( & F_42 ( V_25 ) -> V_66 , & V_73 -> V_32 ,
sizeof( struct V_64 ) ) ;
F_42 ( V_25 ) -> V_13 = NULL ;
} else {
unsigned long V_20 ;
F_38 ( & V_73 -> V_32 , & V_66 , & V_70 ) ;
F_9 ( L_6 , & V_66 ,
V_70 , & V_73 -> V_32 ) ;
F_17 ( & V_21 , V_20 ) ;
V_6 = F_10 ( V_4 , & V_66 , V_70 ) ;
F_18 ( & V_21 , V_20 ) ;
if ( ! V_6 ) {
F_9 ( L_7 , & V_66 ) ;
return - V_59 ;
}
V_32 = V_6 -> V_36 ;
memcpy ( & F_42 ( V_25 ) -> V_66 , & V_73 -> V_32 ,
sizeof( struct V_64 ) ) ;
F_42 ( V_25 ) -> V_13 = V_6 -> V_13 ;
}
V_31 = V_4 -> V_3 -> V_37 ;
return F_43 ( V_25 , V_3 , type , V_32 , V_31 , V_38 ) ;
}
static int F_44 ( struct V_16 * V_13 , struct V_24 * V_25 ,
struct V_2 * V_3 )
{
struct V_76 V_77 ;
struct V_78 V_79 ;
int V_58 ;
V_13 -> V_44 = V_25 ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
V_77 . V_80 = (struct V_81 * ) & V_79 ;
V_77 . V_82 = 1 ;
V_79 . V_83 = V_25 -> V_44 ;
V_79 . V_84 = V_25 -> V_38 ;
V_58 = F_45 ( V_13 , & V_77 , V_25 -> V_38 ) ;
if ( V_58 > 0 ) {
V_3 -> V_53 . V_85 += V_58 ;
V_3 -> V_53 . V_86 ++ ;
return 0 ;
}
if ( ! V_58 )
V_58 = F_42 ( V_25 ) -> V_87 ;
if ( V_58 < 0 ) {
if ( V_58 == - V_60 )
V_3 -> V_53 . V_88 ++ ;
else
V_3 -> V_53 . V_89 ++ ;
}
return V_58 ;
}
static void F_46 ( struct V_24 * V_25 , struct V_2 * V_3 )
{
struct V_24 * V_42 ;
struct V_1 * V_19 , * V_12 ;
unsigned long V_20 ;
F_17 ( & V_21 , V_20 ) ;
F_12 (entry, tmp, &bt_6lowpan_devices, list) {
struct V_5 * V_90 , * V_91 ;
struct V_1 * V_4 ;
if ( V_19 -> V_3 != V_3 )
continue;
V_4 = V_1 ( V_19 -> V_3 ) ;
F_12 (pentry, ptmp, &dev->peers, list) {
V_42 = F_34 ( V_25 , V_28 ) ;
F_44 ( V_90 -> V_13 , V_42 , V_3 ) ;
F_26 ( V_42 ) ;
}
}
F_18 ( & V_21 , V_20 ) ;
}
static T_4 F_47 ( struct V_24 * V_25 , struct V_2 * V_3 )
{
int V_58 = 0 ;
struct V_1 * V_4 ;
struct V_5 * V_6 ;
T_1 V_66 ;
T_3 V_70 ;
if ( F_41 ( & F_42 ( V_25 ) -> V_66 ) ) {
F_46 ( V_25 , V_3 ) ;
} else {
unsigned long V_20 ;
F_38 ( & F_42 ( V_25 ) -> V_66 , & V_66 , & V_70 ) ;
V_4 = V_1 ( V_3 ) ;
F_17 ( & V_21 , V_20 ) ;
V_6 = F_10 ( V_4 , & V_66 , V_70 ) ;
F_18 ( & V_21 , V_20 ) ;
F_9 ( L_8 ,
V_3 -> V_92 , & V_66 , V_70 ,
& F_42 ( V_25 ) -> V_66 , V_6 ) ;
if ( V_6 && V_6 -> V_13 )
V_58 = F_44 ( V_6 -> V_13 , V_25 , V_3 ) ;
else
V_58 = - V_59 ;
}
F_48 ( V_25 ) ;
if ( V_58 )
F_9 ( L_9 , V_58 ) ;
return ( V_58 < 0 ) ? V_93 : V_58 ;
}
static void F_49 ( struct V_2 * V_4 )
{
V_4 -> V_94 = V_40 ;
V_4 -> type = V_43 ;
V_4 -> V_95 = 0 ;
V_4 -> V_96 = 0 ;
V_4 -> V_97 = V_98 ;
V_4 -> V_99 = 0 ;
V_4 -> V_20 = V_100 | V_101 ;
V_4 -> V_102 = 0 ;
V_4 -> V_103 = & V_103 ;
V_4 -> V_104 = & V_104 ;
V_4 -> V_105 = V_106 ;
}
static void F_50 ( T_3 * V_107 , T_3 * V_66 , T_3 V_70 )
{
V_107 [ 0 ] = V_66 [ 5 ] ;
V_107 [ 1 ] = V_66 [ 4 ] ;
V_107 [ 2 ] = V_66 [ 3 ] ;
V_107 [ 3 ] = 0xFF ;
V_107 [ 4 ] = 0xFE ;
V_107 [ 5 ] = V_66 [ 2 ] ;
V_107 [ 6 ] = V_66 [ 1 ] ;
V_107 [ 7 ] = V_66 [ 0 ] ;
if ( V_70 == V_63 )
V_107 [ 0 ] &= ~ 0x02 ;
else
V_107 [ 0 ] |= 0x02 ;
F_9 ( L_10 , V_70 , 8 , V_107 ) ;
}
static void F_51 ( struct V_2 * V_3 , T_1 * V_66 ,
T_3 V_70 )
{
V_3 -> V_108 = V_109 ;
F_50 ( V_3 -> V_37 , V_66 -> V_69 , V_70 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
int V_58 ;
F_53 () ;
V_58 = F_54 ( V_3 ) ;
if ( V_58 < 0 )
F_55 ( L_11 , V_3 -> V_92 , V_58 ) ;
F_56 () ;
}
static void F_57 ( struct V_2 * V_3 )
{
int V_58 ;
F_53 () ;
V_58 = F_58 ( V_3 ) ;
if ( V_58 < 0 )
F_55 ( L_12 , V_3 -> V_92 , V_58 ) ;
F_56 () ;
}
static void F_59 ( struct V_110 * V_111 )
{
struct V_1 * V_4 = F_60 ( V_111 , struct V_1 ,
V_112 . V_111 ) ;
F_61 ( V_4 -> V_3 ) ;
}
static bool F_62 ( struct V_113 * V_22 )
{
if ( V_22 -> type != V_114 )
return false ;
if ( ! V_115 )
return false ;
return true ;
}
static struct V_16 * F_63 ( void )
{
struct V_16 * V_13 ;
V_13 = F_64 () ;
if ( ! V_13 )
return NULL ;
F_65 ( V_13 ) ;
V_13 -> V_116 = V_117 ;
V_13 -> V_118 = V_119 ;
V_13 -> V_120 = 65535 ;
V_13 -> V_121 = V_13 -> V_120 ;
return V_13 ;
}
static struct V_16 * F_66 ( struct V_16 * V_122 )
{
struct V_16 * V_13 ;
V_13 = F_63 () ;
if ( ! V_13 )
return NULL ;
V_13 -> V_123 = V_13 -> V_120 ;
V_13 -> V_124 = V_13 -> V_120 ;
V_13 -> V_125 = V_126 ;
return V_13 ;
}
static struct V_16 * F_67 ( struct V_16 * V_13 ,
struct V_1 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_20 ;
V_6 = F_68 ( sizeof( * V_6 ) , V_28 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_13 = V_13 ;
memset ( & V_6 -> V_127 , 0 , sizeof( struct V_64 ) ) ;
V_6 -> V_127 . V_68 [ 0 ] = 0xFE ;
V_6 -> V_127 . V_68 [ 1 ] = 0x80 ;
F_50 ( ( T_3 * ) & V_6 -> V_127 . V_68 + 8 , V_13 -> V_14 . V_69 ,
V_13 -> V_15 ) ;
memcpy ( & V_6 -> V_36 , ( T_3 * ) & V_6 -> V_127 . V_68 + 8 ,
V_40 ) ;
F_69 ( & V_21 , V_20 ) ;
F_70 ( & V_6 -> V_7 ) ;
F_2 ( V_4 , V_6 ) ;
F_71 ( & V_21 , V_20 ) ;
F_72 ( & V_4 -> V_112 , F_59 ) ;
F_73 ( & V_4 -> V_112 , F_74 ( 100 ) ) ;
return V_6 -> V_13 ;
}
static int F_75 ( struct V_16 * V_13 , struct V_1 * * V_4 )
{
struct V_2 * V_3 ;
int V_58 = 0 ;
unsigned long V_20 ;
V_3 = F_76 ( sizeof( struct V_1 ) , V_128 ,
V_129 , F_49 ) ;
if ( ! V_3 )
return - V_29 ;
F_51 ( V_3 , & V_13 -> V_130 , V_13 -> V_131 ) ;
V_3 -> V_103 = & V_103 ;
F_77 ( V_3 , & V_13 -> V_18 -> V_22 -> V_4 ) ;
F_78 ( V_3 , & V_132 ) ;
V_58 = F_79 ( V_3 ) ;
if ( V_58 < 0 ) {
F_55 ( L_13 , V_58 ) ;
V_106 ( V_3 ) ;
goto V_133;
}
F_9 ( L_14 ,
V_3 -> V_134 , & V_13 -> V_14 , V_13 -> V_15 ,
& V_13 -> V_130 , V_13 -> V_131 ) ;
F_80 ( V_135 , & V_3 -> V_125 ) ;
* V_4 = F_1 ( V_3 ) ;
( * V_4 ) -> V_3 = V_3 ;
( * V_4 ) -> V_23 = V_13 -> V_18 -> V_22 -> V_23 ;
F_70 ( & ( * V_4 ) -> V_8 ) ;
F_69 ( & V_21 , V_20 ) ;
F_70 ( & ( * V_4 ) -> V_7 ) ;
F_3 ( & ( * V_4 ) -> V_7 , & V_136 ) ;
F_71 ( & V_21 , V_20 ) ;
return 0 ;
V_133:
return V_58 ;
}
static inline void F_81 ( struct V_16 * V_13 )
{
struct V_1 * V_4 ;
V_4 = F_19 ( V_13 -> V_18 ) ;
F_9 ( L_15 , V_13 , V_13 -> V_18 , V_4 ) ;
if ( ! V_4 ) {
if ( F_75 ( V_13 , & V_4 ) < 0 ) {
F_82 ( V_13 , - V_59 ) ;
return;
}
}
if ( ! F_83 ( V_10 ) )
return;
F_67 ( V_13 , V_4 ) ;
F_52 ( V_4 -> V_3 ) ;
}
static inline struct V_16 * F_84 ( struct V_16 * V_13 )
{
struct V_16 * V_122 ;
V_122 = F_66 ( V_13 ) ;
V_122 -> V_137 = V_13 -> V_137 ;
F_9 ( L_16 , V_13 , V_122 ) ;
return V_122 ;
}
static void F_85 ( struct V_110 * V_111 )
{
struct V_1 * V_19 = F_60 ( V_111 , struct V_1 ,
F_85 ) ;
F_86 ( V_19 -> V_3 ) ;
}
static void F_87 ( struct V_16 * V_13 )
{
struct V_1 * V_19 , * V_12 ;
struct V_1 * V_4 = NULL ;
struct V_5 * V_6 ;
int V_58 = - V_59 ;
unsigned long V_20 ;
bool V_138 = false , V_139 = true ;
F_9 ( L_17 , V_13 , V_13 -> V_18 ) ;
if ( V_13 -> V_18 && V_13 -> V_18 -> V_22 ) {
if ( ! F_62 ( V_13 -> V_18 -> V_22 ) )
return;
V_139 = false ;
}
F_69 ( & V_21 , V_20 ) ;
F_12 (entry, tmp, &bt_6lowpan_devices, list) {
V_4 = V_1 ( V_19 -> V_3 ) ;
V_6 = F_14 ( V_4 , V_13 ) ;
if ( V_6 ) {
V_138 = F_5 ( V_4 , V_6 ) ;
V_58 = 0 ;
F_9 ( L_18 , V_4 ,
V_138 ? L_19 : L_20 , V_6 ) ;
F_9 ( L_21 , V_13 ,
F_11 ( & V_13 -> V_140 . V_141 ) ) ;
F_88 ( V_13 ) ;
F_89 ( V_6 ) ;
break;
}
}
if ( ! V_58 && V_138 && V_4 && ! F_11 ( & V_4 -> V_9 ) ) {
F_71 ( & V_21 , V_20 ) ;
F_90 ( & V_4 -> V_112 ) ;
F_57 ( V_4 -> V_3 ) ;
if ( ! V_139 ) {
F_91 ( & V_19 -> F_85 , F_85 ) ;
F_92 ( & V_19 -> F_85 ) ;
}
} else {
F_71 ( & V_21 , V_20 ) ;
}
return;
}
static void F_93 ( struct V_16 * V_13 , int V_125 , int V_58 )
{
F_9 ( L_22 , V_13 , V_13 -> V_18 ,
F_94 ( V_125 ) , V_58 ) ;
}
static struct V_24 * F_95 ( struct V_16 * V_13 ,
unsigned long V_142 ,
unsigned long V_38 , int V_143 )
{
return F_96 ( V_142 + V_38 , V_28 ) ;
}
static void F_97 ( struct V_16 * V_13 )
{
struct V_24 * V_25 = V_13 -> V_44 ;
F_9 ( L_23 , V_13 , V_13 -> V_18 , V_25 ) ;
F_42 ( V_25 ) -> V_87 = - V_60 ;
}
static void F_98 ( struct V_16 * V_13 )
{
struct V_24 * V_25 = V_13 -> V_44 ;
F_9 ( L_23 , V_13 , V_13 -> V_18 , V_25 ) ;
F_42 ( V_25 ) -> V_87 = 0 ;
}
static long F_99 ( struct V_16 * V_13 )
{
return F_74 ( 1000 ) ;
}
static inline T_2 F_100 ( T_2 type )
{
if ( type == V_144 )
return V_63 ;
else
return V_62 ;
}
static struct V_16 * F_101 ( void )
{
struct V_16 * V_122 ;
V_122 = F_63 () ;
if ( ! V_122 )
return NULL ;
V_122 -> V_137 = & V_145 ;
return V_122 ;
}
static int F_102 ( T_1 * V_66 , T_3 V_15 )
{
struct V_16 * V_122 ;
int V_58 ;
V_122 = F_101 () ;
if ( ! V_122 )
return - V_41 ;
V_58 = F_103 ( V_122 , F_104 ( V_115 ) , 0 ,
V_66 , V_15 ) ;
F_9 ( L_24 , V_122 , V_58 ) ;
if ( V_58 < 0 )
F_88 ( V_122 ) ;
return V_58 ;
}
static int F_105 ( struct V_17 * V_18 , T_3 V_15 )
{
struct V_5 * V_6 ;
F_9 ( L_25 , V_18 , V_15 ) ;
V_6 = F_16 ( V_18 ) ;
if ( ! V_6 )
return - V_59 ;
F_9 ( L_26 , V_6 , V_6 -> V_13 ) ;
F_106 ( V_6 -> V_13 , V_59 ) ;
return 0 ;
}
static struct V_16 * F_107 ( void )
{
T_1 * V_66 = V_75 ;
struct V_16 * V_122 ;
int V_58 ;
if ( V_115 == 0 )
return NULL ;
V_122 = F_101 () ;
if ( ! V_122 )
return NULL ;
V_122 -> V_125 = V_146 ;
V_122 -> V_131 = V_63 ;
F_9 ( L_27 , V_115 , V_122 ,
V_122 -> V_131 ) ;
V_58 = F_108 ( V_122 , V_66 , F_104 ( V_115 ) ) ;
if ( V_58 ) {
F_88 ( V_122 ) ;
F_109 ( L_28 , V_58 ) ;
return NULL ;
}
return V_122 ;
}
static int F_110 ( char * V_147 , T_1 * V_66 , T_3 * V_70 ,
struct V_17 * * V_18 )
{
struct V_113 * V_22 ;
struct V_148 * V_23 ;
T_1 * V_130 = V_75 ;
int V_149 ;
V_149 = sscanf ( V_147 , L_29 ,
& V_66 -> V_69 [ 5 ] , & V_66 -> V_69 [ 4 ] , & V_66 -> V_69 [ 3 ] ,
& V_66 -> V_69 [ 2 ] , & V_66 -> V_69 [ 1 ] , & V_66 -> V_69 [ 0 ] ,
V_70 ) ;
if ( V_149 < 7 )
return - V_41 ;
V_23 = F_111 ( V_66 , V_130 ) ;
if ( ! V_23 )
return - V_59 ;
F_112 ( V_23 ) ;
V_22 = F_113 ( V_23 , V_114 , V_66 ) ;
F_114 ( V_23 ) ;
if ( ! V_22 )
return - V_59 ;
* V_18 = (struct V_17 * ) V_22 -> V_150 ;
F_9 ( L_30 , * V_18 , & V_22 -> V_14 , V_22 -> V_15 ) ;
return 0 ;
}
static void F_115 ( void )
{
struct V_1 * V_19 , * V_151 ;
struct V_5 * V_6 , * V_152 , * V_153 ;
struct V_154 V_8 ;
unsigned long V_20 ;
F_70 ( & V_8 ) ;
F_17 ( & V_21 , V_20 ) ;
F_12 (entry, tmp_dev, &bt_6lowpan_devices, list) {
F_12 (peer, tmp_peer, &entry->peers, list) {
V_153 = F_116 ( sizeof( * V_153 ) , V_28 ) ;
if ( ! V_153 )
break;
V_153 -> V_13 = V_6 -> V_13 ;
F_70 ( & V_153 -> V_7 ) ;
F_3 ( & V_153 -> V_7 , & V_8 ) ;
}
}
F_18 ( & V_21 , V_20 ) ;
F_12 (peer, tmp_peer, &peers, list) {
F_106 ( V_6 -> V_13 , V_59 ) ;
F_89 ( V_6 ) ;
}
}
static int F_117 ( void * V_44 , T_5 V_155 )
{
T_6 V_156 ;
V_156 = V_155 ;
if ( V_156 == 0 || V_115 != V_156 )
F_115 () ;
V_115 = V_156 ;
if ( V_157 ) {
F_106 ( V_157 , 0 ) ;
F_88 ( V_157 ) ;
}
V_157 = F_107 () ;
return 0 ;
}
static int F_118 ( void * V_44 , T_5 * V_155 )
{
* V_155 = V_115 ;
return 0 ;
}
static T_7 F_119 ( struct V_158 * V_159 ,
const char T_8 * V_160 ,
T_9 V_161 ,
T_10 * V_162 )
{
char V_147 [ 32 ] ;
T_9 V_163 = F_120 ( V_161 , sizeof( V_147 ) - 1 ) ;
int V_27 ;
T_1 V_66 ;
T_3 V_70 ;
struct V_17 * V_18 = NULL ;
if ( F_121 ( V_147 , V_160 , V_163 ) )
return - V_164 ;
V_147 [ V_163 ] = '\0' ;
if ( memcmp ( V_147 , L_31 , 8 ) == 0 ) {
V_27 = F_110 ( & V_147 [ 8 ] , & V_66 , & V_70 , & V_18 ) ;
if ( V_27 == - V_41 )
return V_27 ;
if ( V_157 ) {
F_106 ( V_157 , 0 ) ;
F_88 ( V_157 ) ;
V_157 = NULL ;
}
if ( V_18 ) {
struct V_5 * V_6 ;
if ( ! F_62 ( V_18 -> V_22 ) )
return - V_41 ;
V_6 = F_16 ( V_18 ) ;
if ( V_6 ) {
F_9 ( L_32 ) ;
return - V_165 ;
}
F_9 ( L_33 , V_18 ,
& V_18 -> V_22 -> V_14 , V_18 -> V_22 -> V_15 ,
V_70 ) ;
}
V_27 = F_102 ( & V_66 , V_70 ) ;
if ( V_27 < 0 )
return V_27 ;
return V_161 ;
}
if ( memcmp ( V_147 , L_34 , 11 ) == 0 ) {
V_27 = F_110 ( & V_147 [ 11 ] , & V_66 , & V_70 , & V_18 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_105 ( V_18 , V_70 ) ;
if ( V_27 < 0 )
return V_27 ;
return V_161 ;
}
return V_161 ;
}
static int F_122 ( struct V_166 * V_167 , void * V_168 )
{
struct V_1 * V_19 , * V_151 ;
struct V_5 * V_6 , * V_152 ;
unsigned long V_20 ;
F_17 ( & V_21 , V_20 ) ;
F_12 (entry, tmp_dev, &bt_6lowpan_devices, list) {
F_12 (peer, tmp_peer, &entry->peers, list)
F_123 ( V_167 , L_35 ,
& V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_15 ) ;
}
F_18 ( & V_21 , V_20 ) ;
return 0 ;
}
static int F_124 ( struct V_169 * V_169 , struct V_158 * V_158 )
{
return F_125 ( V_158 , F_122 , V_169 -> V_170 ) ;
}
static void F_126 ( void )
{
struct V_1 * V_19 , * V_12 , * V_171 ;
struct V_154 V_172 ;
unsigned long V_20 ;
F_70 ( & V_172 ) ;
F_17 ( & V_21 , V_20 ) ;
F_12 (entry, tmp, &bt_6lowpan_devices, list) {
V_171 = F_116 ( sizeof( * V_171 ) , V_28 ) ;
if ( ! V_171 )
break;
V_171 -> V_3 = V_19 -> V_3 ;
F_70 ( & V_171 -> V_7 ) ;
F_3 ( & V_171 -> V_7 , & V_172 ) ;
}
F_18 ( & V_21 , V_20 ) ;
F_12 (entry, tmp, &devices, list) {
F_57 ( V_19 -> V_3 ) ;
F_9 ( L_36 ,
V_19 -> V_3 -> V_92 , V_19 -> V_3 ) ;
F_86 ( V_19 -> V_3 ) ;
F_89 ( V_19 ) ;
}
}
static int F_127 ( struct V_173 * V_174 ,
unsigned long V_175 , void * V_168 )
{
struct V_2 * V_3 = F_128 ( V_168 ) ;
struct V_1 * V_19 , * V_12 ;
unsigned long V_20 ;
if ( V_3 -> type != V_43 )
return V_176 ;
switch ( V_175 ) {
case V_177 :
F_69 ( & V_21 , V_20 ) ;
F_12 (entry, tmp, &bt_6lowpan_devices,
list) {
if ( V_19 -> V_3 == V_3 ) {
F_9 ( L_37 ,
V_3 -> V_92 , V_3 ) ;
F_6 ( & V_19 -> V_7 ) ;
F_89 ( V_19 ) ;
break;
}
}
F_71 ( & V_21 , V_20 ) ;
break;
}
return V_176 ;
}
static int T_11 F_129 ( void )
{
V_178 = F_130 ( L_38 , 0644 ,
V_179 , NULL ,
& V_180 ) ;
V_181 = F_130 ( L_39 , 0644 ,
V_179 , NULL ,
& V_182 ) ;
return F_131 ( & V_183 ) ;
}
static void T_12 F_132 ( void )
{
F_133 ( V_178 ) ;
F_133 ( V_181 ) ;
if ( V_157 ) {
F_106 ( V_157 , 0 ) ;
F_88 ( V_157 ) ;
}
F_126 () ;
F_134 ( & V_183 ) ;
}
