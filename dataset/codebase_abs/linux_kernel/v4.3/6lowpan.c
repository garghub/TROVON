static inline struct V_1 * V_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) F_1 ( V_3 ) -> V_4 ;
}
static inline void F_2 ( struct V_1 * V_5 , struct V_6 * V_7 )
{
F_3 ( & V_7 -> V_8 , & V_5 -> V_9 ) ;
F_4 ( & V_5 -> V_10 ) ;
}
static inline bool F_5 ( struct V_1 * V_5 , struct V_6 * V_7 )
{
F_6 ( & V_7 -> V_8 ) ;
F_7 ( V_7 , V_11 ) ;
F_8 ( V_12 ) ;
if ( F_9 ( & V_5 -> V_10 ) ) {
F_10 ( L_1 ) ;
return true ;
}
return false ;
}
static inline struct V_6 * F_11 ( struct V_1 * V_5 ,
T_1 * V_13 , T_2 type )
{
struct V_6 * V_7 ;
F_10 ( L_2 , F_12 ( & V_5 -> V_10 ) ,
V_13 , type ) ;
F_13 () ;
F_14 (peer, &dev->peers, list) {
F_10 ( L_3 ,
& V_7 -> V_14 -> V_15 , V_7 -> V_14 -> V_16 ) ;
if ( F_15 ( & V_7 -> V_14 -> V_15 , V_13 ) )
continue;
if ( type == V_7 -> V_14 -> V_16 ) {
F_16 () ;
return V_7 ;
}
}
F_16 () ;
return NULL ;
}
static inline struct V_6 * F_17 ( struct V_1 * V_5 ,
struct V_17 * V_14 )
{
struct V_6 * V_7 ;
F_14 (peer, &dev->peers, list) {
if ( V_7 -> V_14 == V_14 )
return V_7 ;
}
return NULL ;
}
static inline struct V_6 * F_18 ( struct V_1 * V_5 ,
struct V_18 * V_19 )
{
struct V_6 * V_7 ;
F_14 (peer, &dev->peers, list) {
if ( V_7 -> V_14 -> V_19 == V_19 )
return V_7 ;
}
return NULL ;
}
static inline struct V_6 * F_19 ( struct V_1 * V_5 ,
struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 ;
struct V_20 * V_24 ;
struct V_25 * V_26 = (struct V_25 * ) F_20 ( V_23 ) ;
int V_27 = F_12 ( & V_5 -> V_10 ) ;
F_10 ( L_4 , V_27 , V_21 , V_26 ) ;
if ( V_27 == 1 ) {
F_13 () ;
V_7 = F_21 ( & V_5 -> V_9 , struct V_6 ,
V_8 ) ;
F_16 () ;
return V_7 ;
}
if ( ! V_26 ) {
V_24 = & F_22 ( V_23 ) -> V_28 ;
if ( F_23 ( V_24 ) )
return NULL ;
} else {
V_24 = F_24 ( V_26 , V_21 ) ;
memcpy ( & F_22 ( V_23 ) -> V_28 , V_24 , sizeof( struct V_20 ) ) ;
}
F_10 ( L_5 , V_24 ) ;
F_13 () ;
F_14 (peer, &dev->peers, list) {
F_10 ( L_6 ,
& V_7 -> V_14 -> V_15 , V_7 -> V_14 -> V_16 ,
& V_7 -> V_29 ) ;
if ( ! F_25 ( & V_7 -> V_29 , V_24 ) ) {
F_16 () ;
return V_7 ;
}
}
F_16 () ;
return NULL ;
}
static struct V_6 * F_26 ( struct V_18 * V_19 )
{
struct V_1 * V_30 ;
struct V_6 * V_7 = NULL ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
V_7 = F_18 ( V_30 , V_19 ) ;
if ( V_7 )
break;
}
F_16 () ;
return V_7 ;
}
static struct V_1 * F_27 ( struct V_18 * V_19 )
{
struct V_1 * V_30 ;
struct V_1 * V_5 = NULL ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
if ( V_19 -> V_31 -> V_32 == V_30 -> V_32 ) {
V_5 = V_30 ;
break;
}
}
F_16 () ;
return V_5 ;
}
static int F_28 ( struct V_22 * V_23 , struct V_2 * V_5 )
{
struct V_22 * V_33 ;
V_33 = F_29 ( V_23 , V_34 ) ;
if ( ! V_33 )
return V_35 ;
return F_30 ( V_33 ) ;
}
static int F_31 ( struct V_22 * V_23 , struct V_2 * V_3 ,
struct V_17 * V_14 )
{
const T_3 * V_36 , * V_21 ;
T_3 V_37 , V_38 ;
struct V_1 * V_5 ;
struct V_6 * V_7 ;
V_5 = V_1 ( V_3 ) ;
F_13 () ;
V_7 = F_17 ( V_5 , V_14 ) ;
F_16 () ;
if ( ! V_7 )
return - V_39 ;
V_36 = V_7 -> V_40 ;
V_21 = V_5 -> V_3 -> V_41 ;
if ( V_23 -> V_42 < 2 )
return - V_39 ;
if ( F_32 ( V_23 , & V_37 ) )
return - V_39 ;
if ( F_32 ( V_23 , & V_38 ) )
return - V_39 ;
return F_33 ( V_23 , V_3 ,
V_36 , V_43 ,
V_44 , V_21 ,
V_43 , V_44 ,
V_37 , V_38 ) ;
}
static int F_34 ( struct V_22 * V_23 , struct V_2 * V_5 ,
struct V_17 * V_14 )
{
struct V_22 * V_45 ;
int V_46 ;
if ( ! F_35 ( V_5 ) )
goto V_47;
if ( V_5 -> type != V_48 )
goto V_47;
V_23 = F_36 ( V_23 , V_34 ) ;
if ( ! V_23 )
goto V_47;
if ( V_23 -> V_49 [ 0 ] == V_50 ) {
V_45 = F_37 ( V_23 , V_51 - 1 ,
F_38 ( V_23 ) , V_34 ) ;
if ( ! V_45 )
goto V_47;
V_45 -> V_52 = F_39 ( V_53 ) ;
V_45 -> V_54 = V_55 ;
F_40 ( V_45 ) ;
F_41 ( V_45 , sizeof( struct V_56 ) ) ;
if ( F_28 ( V_45 , V_5 ) != V_57 ) {
F_42 ( V_45 ) ;
goto V_47;
}
V_5 -> V_58 . V_59 += V_23 -> V_42 ;
V_5 -> V_58 . V_60 ++ ;
F_43 ( V_45 ) ;
F_43 ( V_23 ) ;
} else {
switch ( V_23 -> V_49 [ 0 ] & 0xe0 ) {
case V_61 :
V_45 = F_44 ( V_23 , V_34 ) ;
if ( ! V_45 )
goto V_47;
V_46 = F_31 ( V_45 , V_5 , V_14 ) ;
if ( V_46 < 0 ) {
F_42 ( V_45 ) ;
goto V_47;
}
V_45 -> V_52 = F_39 ( V_53 ) ;
V_45 -> V_54 = V_55 ;
V_45 -> V_5 = V_5 ;
if ( F_28 ( V_45 , V_5 )
!= V_57 ) {
F_42 ( V_45 ) ;
goto V_47;
}
V_5 -> V_58 . V_59 += V_23 -> V_42 ;
V_5 -> V_58 . V_60 ++ ;
F_43 ( V_45 ) ;
F_43 ( V_23 ) ;
break;
default:
break;
}
}
return V_57 ;
V_47:
V_5 -> V_58 . V_62 ++ ;
return V_35 ;
}
static int F_45 ( struct V_17 * V_14 , struct V_22 * V_23 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
int V_63 ;
V_7 = F_26 ( V_14 -> V_19 ) ;
if ( ! V_7 )
return - V_64 ;
V_5 = F_27 ( V_14 -> V_19 ) ;
if ( ! V_5 || ! V_5 -> V_3 )
return - V_64 ;
V_63 = F_34 ( V_23 , V_5 -> V_3 , V_14 ) ;
if ( V_63 ) {
F_10 ( L_7 , V_63 ) ;
V_63 = - V_65 ;
}
return V_63 ;
}
static T_3 F_46 ( T_3 V_66 )
{
return ( ( V_66 & 0x02 ) ? V_67 : V_68 ) ;
}
static void F_47 ( struct V_20 * V_69 , T_1 * V_70 )
{
T_3 * V_71 = V_69 -> V_72 + 8 ;
V_70 -> V_73 [ 0 ] = V_71 [ 7 ] ;
V_70 -> V_73 [ 1 ] = V_71 [ 6 ] ;
V_70 -> V_73 [ 2 ] = V_71 [ 5 ] ;
V_70 -> V_73 [ 3 ] = V_71 [ 2 ] ;
V_70 -> V_73 [ 4 ] = V_71 [ 1 ] ;
V_70 -> V_73 [ 5 ] = V_71 [ 0 ] ;
}
static void F_48 ( struct V_20 * V_69 ,
T_1 * V_70 , T_3 * V_74 )
{
F_47 ( V_69 , V_70 ) ;
V_70 -> V_73 [ 5 ] ^= 0x02 ;
* V_74 = F_46 ( V_70 -> V_73 [ 5 ] ) ;
}
static int F_49 ( struct V_22 * V_23 , struct V_2 * V_3 ,
T_1 * V_29 , T_3 * V_75 )
{
struct V_20 V_76 ;
struct V_1 * V_5 ;
struct V_6 * V_7 ;
T_1 V_70 , * V_77 = V_78 ;
T_3 * V_21 = V_77 -> V_73 ;
int V_63 , V_79 = 0 ;
V_5 = V_1 ( V_3 ) ;
memcpy ( & V_76 , & F_22 ( V_23 ) -> V_70 , sizeof( V_76 ) ) ;
if ( F_50 ( & V_76 ) ) {
F_22 ( V_23 ) -> V_14 = NULL ;
} else {
T_3 V_74 ;
F_48 ( & V_76 , & V_70 , & V_74 ) ;
F_10 ( L_8 , & V_70 ,
V_74 , & V_76 ) ;
V_7 = F_11 ( V_5 , & V_70 , V_74 ) ;
if ( ! V_7 ) {
V_7 = F_19 ( V_5 , & V_76 , V_23 ) ;
if ( ! V_7 ) {
F_10 ( L_9 , & V_70 ) ;
return - V_64 ;
}
}
V_21 = V_7 -> V_40 ;
* V_29 = V_70 ;
* V_75 = V_74 ;
F_22 ( V_23 ) -> V_14 = V_7 -> V_14 ;
V_79 = 1 ;
}
F_51 ( V_23 , V_3 , V_53 , V_21 ,
V_5 -> V_3 -> V_41 , V_23 -> V_42 ) ;
V_63 = F_52 ( V_23 , V_3 , V_53 , NULL , NULL , 0 ) ;
if ( V_63 < 0 )
return V_63 ;
return V_79 ;
}
static int F_53 ( struct V_22 * V_23 , struct V_2 * V_3 ,
unsigned short type , const void * V_80 ,
const void * V_81 , unsigned int V_42 )
{
struct V_56 * V_82 ;
if ( type != V_53 )
return - V_39 ;
V_82 = F_54 ( V_23 ) ;
memcpy ( & F_22 ( V_23 ) -> V_70 , & V_82 -> V_21 , sizeof( struct V_20 ) ) ;
return 0 ;
}
static int F_55 ( struct V_17 * V_14 , struct V_22 * V_23 ,
struct V_2 * V_3 )
{
struct V_83 V_84 ;
struct V_85 V_86 ;
int V_63 ;
V_14 -> V_49 = V_23 ;
V_86 . V_87 = V_23 -> V_49 ;
V_86 . V_88 = V_23 -> V_42 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
F_56 ( & V_84 . V_89 , V_90 | V_91 , & V_86 , 1 , V_23 -> V_42 ) ;
V_63 = F_57 ( V_14 , & V_84 , V_23 -> V_42 ) ;
if ( V_63 > 0 ) {
V_3 -> V_58 . V_92 += V_63 ;
V_3 -> V_58 . V_93 ++ ;
return 0 ;
}
if ( ! V_63 )
V_63 = F_22 ( V_23 ) -> V_79 ;
if ( V_63 < 0 ) {
if ( V_63 == - V_65 )
V_3 -> V_58 . V_94 ++ ;
else
V_3 -> V_58 . V_95 ++ ;
}
return V_63 ;
}
static int F_58 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
struct V_22 * V_45 ;
struct V_1 * V_30 ;
int V_63 = 0 ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
struct V_6 * V_96 ;
struct V_1 * V_5 ;
if ( V_30 -> V_3 != V_3 )
continue;
V_5 = V_1 ( V_30 -> V_3 ) ;
F_14 (pentry, &dev->peers, list) {
int V_46 ;
V_45 = F_44 ( V_23 , V_34 ) ;
F_10 ( L_10 ,
V_3 -> V_97 ,
& V_96 -> V_14 -> V_15 , V_96 -> V_14 -> V_16 ,
& V_96 -> V_29 , V_96 -> V_14 ) ;
V_46 = F_55 ( V_96 -> V_14 , V_45 , V_3 ) ;
if ( V_46 < 0 )
V_63 = V_46 ;
F_42 ( V_45 ) ;
}
}
F_16 () ;
return V_63 ;
}
static T_4 F_59 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
int V_63 = 0 ;
T_1 V_70 ;
T_3 V_74 ;
V_23 = F_60 ( V_23 , V_34 ) ;
if ( ! V_23 )
return V_98 ;
V_63 = F_49 ( V_23 , V_3 , & V_70 , & V_74 ) ;
if ( V_63 < 0 ) {
F_42 ( V_23 ) ;
return V_98 ;
}
if ( V_63 ) {
if ( F_22 ( V_23 ) -> V_14 ) {
F_10 ( L_10 ,
V_3 -> V_97 , & V_70 , V_74 ,
& F_22 ( V_23 ) -> V_70 , F_22 ( V_23 ) -> V_14 ) ;
V_63 = F_55 ( F_22 ( V_23 ) -> V_14 , V_23 , V_3 ) ;
} else {
V_63 = - V_64 ;
}
} else {
V_63 = F_58 ( V_23 , V_3 ) ;
}
F_61 ( V_23 ) ;
if ( V_63 )
F_10 ( L_11 , V_63 ) ;
return V_63 < 0 ? V_98 : V_63 ;
}
static void F_62 ( struct V_2 * V_5 ,
struct V_99 * V_100 ,
void * V_101 )
{
F_63 ( & V_100 -> V_102 , & V_103 ) ;
}
static int F_64 ( struct V_2 * V_5 )
{
F_65 ( V_5 , F_62 , NULL ) ;
V_5 -> V_104 = & V_105 ;
return 0 ;
}
static void F_66 ( struct V_2 * V_5 )
{
V_5 -> V_106 = V_44 ;
V_5 -> type = V_48 ;
V_5 -> V_107 = 0 ;
V_5 -> V_108 = 0 ;
V_5 -> V_109 = V_110 ;
V_5 -> V_111 = 0 ;
V_5 -> V_112 = V_113 | V_114 |
V_115 ;
V_5 -> V_116 = 0 ;
V_5 -> V_117 = & V_117 ;
V_5 -> V_118 = & V_118 ;
V_5 -> V_119 = V_120 ;
}
static void F_67 ( T_3 * V_121 , T_3 * V_70 , T_3 V_74 )
{
V_121 [ 0 ] = V_70 [ 5 ] ;
V_121 [ 1 ] = V_70 [ 4 ] ;
V_121 [ 2 ] = V_70 [ 3 ] ;
V_121 [ 3 ] = 0xFF ;
V_121 [ 4 ] = 0xFE ;
V_121 [ 5 ] = V_70 [ 2 ] ;
V_121 [ 6 ] = V_70 [ 1 ] ;
V_121 [ 7 ] = V_70 [ 0 ] ;
if ( V_74 == V_68 )
V_121 [ 0 ] &= ~ 0x02 ;
else
V_121 [ 0 ] |= 0x02 ;
F_10 ( L_12 , V_74 , 8 , V_121 ) ;
}
static void F_68 ( struct V_2 * V_3 , T_1 * V_70 ,
T_3 V_74 )
{
V_3 -> V_122 = V_123 ;
F_67 ( V_3 -> V_41 , V_70 -> V_73 , V_74 ) ;
}
static void F_69 ( struct V_2 * V_3 )
{
int V_63 ;
F_70 () ;
V_63 = F_71 ( V_3 ) ;
if ( V_63 < 0 )
F_72 ( L_13 , V_3 -> V_97 , V_63 ) ;
F_73 () ;
}
static void F_74 ( struct V_2 * V_3 )
{
int V_63 ;
F_70 () ;
V_63 = F_75 ( V_3 ) ;
if ( V_63 < 0 )
F_72 ( L_14 , V_3 -> V_97 , V_63 ) ;
F_73 () ;
}
static void F_76 ( struct V_124 * V_125 )
{
struct V_1 * V_5 = F_77 ( V_125 , struct V_1 ,
V_126 . V_125 ) ;
F_78 ( V_5 -> V_3 ) ;
}
static bool F_79 ( struct V_127 * V_31 )
{
if ( V_31 -> type != V_128 )
return false ;
if ( ! V_129 )
return false ;
return true ;
}
static struct V_17 * F_80 ( void )
{
struct V_17 * V_14 ;
V_14 = F_81 () ;
if ( ! V_14 )
return NULL ;
F_82 ( V_14 ) ;
V_14 -> V_130 = V_131 ;
V_14 -> V_132 = V_133 ;
V_14 -> V_134 = 65535 ;
V_14 -> V_135 = V_14 -> V_134 ;
return V_14 ;
}
static struct V_17 * F_83 ( struct V_17 * V_136 )
{
struct V_17 * V_14 ;
V_14 = F_80 () ;
if ( ! V_14 )
return NULL ;
V_14 -> V_137 = V_14 -> V_134 ;
V_14 -> V_138 = V_14 -> V_134 ;
V_14 -> V_139 = V_140 ;
return V_14 ;
}
static void F_84 ( T_3 V_74 , T_3 * V_70 )
{
if ( V_74 == V_68 )
* V_70 |= 0x02 ;
else
* V_70 &= ~ 0x02 ;
}
static struct V_17 * F_85 ( struct V_17 * V_14 ,
struct V_1 * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_86 ( sizeof( * V_7 ) , V_34 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_14 = V_14 ;
memset ( & V_7 -> V_29 , 0 , sizeof( struct V_20 ) ) ;
V_7 -> V_29 . V_72 [ 0 ] = 0xFE ;
V_7 -> V_29 . V_72 [ 1 ] = 0x80 ;
F_67 ( ( T_3 * ) & V_7 -> V_29 . V_72 + 8 , V_14 -> V_15 . V_73 ,
V_14 -> V_16 ) ;
memcpy ( & V_7 -> V_40 , ( T_3 * ) & V_7 -> V_29 . V_72 + 8 ,
V_44 ) ;
F_84 ( V_14 -> V_16 , ( T_3 * ) & V_7 -> V_29 . V_72 + 8 ) ;
F_87 ( & V_141 ) ;
F_88 ( & V_7 -> V_8 ) ;
F_2 ( V_5 , V_7 ) ;
F_89 ( & V_141 ) ;
F_90 ( & V_5 -> V_126 , F_76 ) ;
F_91 ( & V_5 -> V_126 , F_92 ( 100 ) ) ;
return V_7 -> V_14 ;
}
static int F_93 ( struct V_17 * V_14 , struct V_1 * * V_5 )
{
struct V_2 * V_3 ;
int V_63 = 0 ;
V_3 = F_94 ( F_95 ( sizeof( struct V_1 ) ) ,
V_142 , V_143 ,
F_66 ) ;
if ( ! V_3 )
return - V_144 ;
F_68 ( V_3 , & V_14 -> V_145 , V_14 -> V_146 ) ;
V_3 -> V_117 = & V_117 ;
F_96 ( V_3 , & V_14 -> V_19 -> V_31 -> V_32 -> V_5 ) ;
F_97 ( V_3 , & V_147 ) ;
* V_5 = V_1 ( V_3 ) ;
( * V_5 ) -> V_3 = V_3 ;
( * V_5 ) -> V_32 = V_14 -> V_19 -> V_31 -> V_32 ;
F_88 ( & ( * V_5 ) -> V_9 ) ;
F_87 ( & V_141 ) ;
F_88 ( & ( * V_5 ) -> V_8 ) ;
F_3 ( & ( * V_5 ) -> V_8 , & V_148 ) ;
F_89 ( & V_141 ) ;
F_98 ( V_3 , V_149 ) ;
V_63 = F_99 ( V_3 ) ;
if ( V_63 < 0 ) {
F_72 ( L_15 , V_63 ) ;
F_87 ( & V_141 ) ;
F_6 ( & ( * V_5 ) -> V_8 ) ;
F_89 ( & V_141 ) ;
V_120 ( V_3 ) ;
goto V_150;
}
F_10 ( L_16 ,
V_3 -> V_151 , & V_14 -> V_15 , V_14 -> V_16 ,
& V_14 -> V_145 , V_14 -> V_146 ) ;
F_100 ( V_152 , & V_3 -> V_139 ) ;
return 0 ;
V_150:
return V_63 ;
}
static inline void F_101 ( struct V_17 * V_14 )
{
struct V_1 * V_5 ;
V_5 = F_27 ( V_14 -> V_19 ) ;
F_10 ( L_17 , V_14 , V_14 -> V_19 , V_5 ) ;
if ( ! V_5 ) {
if ( F_93 ( V_14 , & V_5 ) < 0 ) {
F_102 ( V_14 , - V_64 ) ;
return;
}
}
if ( ! F_103 ( V_12 ) )
return;
F_85 ( V_14 , V_5 ) ;
F_69 ( V_5 -> V_3 ) ;
}
static inline struct V_17 * F_104 ( struct V_17 * V_136 )
{
struct V_17 * V_14 ;
V_14 = F_83 ( V_136 ) ;
V_14 -> V_153 = V_136 -> V_153 ;
F_10 ( L_18 , V_14 , V_136 ) ;
return V_14 ;
}
static void F_105 ( struct V_124 * V_125 )
{
struct V_1 * V_30 = F_77 ( V_125 , struct V_1 ,
F_105 ) ;
F_106 ( V_30 -> V_3 ) ;
}
static void F_107 ( struct V_17 * V_14 )
{
struct V_1 * V_30 ;
struct V_1 * V_5 = NULL ;
struct V_6 * V_7 ;
int V_63 = - V_64 ;
bool V_154 = false , remove = true ;
F_10 ( L_19 , V_14 , V_14 -> V_19 ) ;
if ( V_14 -> V_19 && V_14 -> V_19 -> V_31 ) {
if ( ! F_79 ( V_14 -> V_19 -> V_31 ) )
return;
remove = false ;
}
F_87 ( & V_141 ) ;
F_14 (entry, &bt_6lowpan_devices, list) {
V_5 = V_1 ( V_30 -> V_3 ) ;
V_7 = F_17 ( V_5 , V_14 ) ;
if ( V_7 ) {
V_154 = F_5 ( V_5 , V_7 ) ;
V_63 = 0 ;
F_10 ( L_20 , V_5 ,
V_154 ? L_21 : L_22 , V_7 ) ;
F_10 ( L_23 , V_14 ,
F_12 ( & V_14 -> V_155 . V_156 ) ) ;
F_108 ( V_14 ) ;
break;
}
}
if ( ! V_63 && V_154 && V_5 && ! F_12 ( & V_5 -> V_10 ) ) {
F_89 ( & V_141 ) ;
F_109 ( & V_5 -> V_126 ) ;
F_74 ( V_5 -> V_3 ) ;
if ( remove ) {
F_110 ( & V_30 -> F_105 , F_105 ) ;
F_111 ( & V_30 -> F_105 ) ;
}
} else {
F_89 ( & V_141 ) ;
}
return;
}
static void F_112 ( struct V_17 * V_14 , int V_139 , int V_63 )
{
F_10 ( L_24 , V_14 , V_14 -> V_19 ,
F_113 ( V_139 ) , V_63 ) ;
}
static struct V_22 * F_114 ( struct V_17 * V_14 ,
unsigned long V_157 ,
unsigned long V_42 , int V_158 )
{
return F_115 ( V_157 + V_42 , V_34 ) ;
}
static void F_116 ( struct V_17 * V_14 )
{
struct V_22 * V_23 = V_14 -> V_49 ;
F_10 ( L_25 , V_14 , V_14 -> V_19 , V_23 ) ;
if ( ! V_23 )
return;
F_22 ( V_23 ) -> V_79 = - V_65 ;
}
static void F_117 ( struct V_17 * V_14 )
{
struct V_22 * V_23 = V_14 -> V_49 ;
F_10 ( L_25 , V_14 , V_14 -> V_19 , V_23 ) ;
if ( ! V_23 )
return;
F_22 ( V_23 ) -> V_79 = 0 ;
}
static long F_118 ( struct V_17 * V_14 )
{
return V_159 ;
}
static inline T_2 F_119 ( T_2 type )
{
if ( type == V_160 )
return V_68 ;
else
return V_67 ;
}
static struct V_17 * F_120 ( void )
{
struct V_17 * V_136 ;
V_136 = F_80 () ;
if ( ! V_136 )
return NULL ;
V_136 -> V_153 = & V_161 ;
return V_136 ;
}
static int F_121 ( T_1 * V_70 , T_3 V_16 )
{
struct V_17 * V_136 ;
int V_63 ;
V_136 = F_120 () ;
if ( ! V_136 )
return - V_39 ;
V_63 = F_122 ( V_136 , F_123 ( V_162 ) , 0 ,
V_70 , V_16 ) ;
F_10 ( L_26 , V_136 , V_63 ) ;
if ( V_63 < 0 )
F_108 ( V_136 ) ;
return V_63 ;
}
static int F_124 ( struct V_18 * V_19 , T_3 V_16 )
{
struct V_6 * V_7 ;
F_10 ( L_27 , V_19 , V_16 ) ;
V_7 = F_26 ( V_19 ) ;
if ( ! V_7 )
return - V_64 ;
F_10 ( L_28 , V_7 , V_7 -> V_14 ) ;
F_125 ( V_7 -> V_14 , V_64 ) ;
return 0 ;
}
static struct V_17 * F_126 ( void )
{
T_1 * V_70 = V_78 ;
struct V_17 * V_136 ;
int V_63 ;
if ( ! V_129 )
return NULL ;
V_136 = F_120 () ;
if ( ! V_136 )
return NULL ;
V_136 -> V_139 = V_163 ;
V_136 -> V_146 = V_68 ;
F_127 ( & V_136 -> V_164 , V_165 ) ;
F_10 ( L_29 , V_136 , V_136 -> V_146 ) ;
V_63 = F_128 ( V_136 , V_70 , F_123 ( V_162 ) ) ;
if ( V_63 ) {
F_108 ( V_136 ) ;
F_129 ( L_30 , V_63 ) ;
return NULL ;
}
return V_136 ;
}
static int F_130 ( char * V_166 , T_1 * V_70 , T_3 * V_74 ,
struct V_18 * * V_19 )
{
struct V_127 * V_31 ;
struct V_167 * V_32 ;
T_1 * V_145 = V_78 ;
int V_168 ;
V_168 = sscanf ( V_166 , L_31 ,
& V_70 -> V_73 [ 5 ] , & V_70 -> V_73 [ 4 ] , & V_70 -> V_73 [ 3 ] ,
& V_70 -> V_73 [ 2 ] , & V_70 -> V_73 [ 1 ] , & V_70 -> V_73 [ 0 ] ,
V_74 ) ;
if ( V_168 < 7 )
return - V_39 ;
V_32 = F_131 ( V_70 , V_145 ) ;
if ( ! V_32 )
return - V_64 ;
F_132 ( V_32 ) ;
V_31 = F_133 ( V_32 , V_128 , V_70 ) ;
F_134 ( V_32 ) ;
if ( ! V_31 )
return - V_64 ;
* V_19 = (struct V_18 * ) V_31 -> V_169 ;
F_10 ( L_32 , * V_19 , & V_31 -> V_15 , V_31 -> V_16 ) ;
return 0 ;
}
static void F_135 ( void )
{
struct V_1 * V_30 ;
struct V_6 * V_7 , * V_170 , * V_171 ;
struct V_172 V_9 ;
F_88 ( & V_9 ) ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
F_14 (peer, &entry->peers, list) {
V_171 = F_136 ( sizeof( * V_171 ) , V_34 ) ;
if ( ! V_171 )
break;
V_171 -> V_14 = V_7 -> V_14 ;
F_88 ( & V_171 -> V_8 ) ;
F_137 ( & V_171 -> V_8 , & V_9 ) ;
}
}
F_16 () ;
F_87 ( & V_141 ) ;
F_138 (peer, tmp_peer, &peers, list) {
F_125 ( V_7 -> V_14 , V_64 ) ;
F_6 ( & V_7 -> V_8 ) ;
F_7 ( V_7 , V_11 ) ;
}
F_89 ( & V_141 ) ;
}
static void F_139 ( struct V_124 * V_125 )
{
struct V_173 * V_173 = F_77 ( V_125 ,
struct V_173 , V_125 ) ;
if ( ! V_173 -> V_174 || V_129 != V_173 -> V_174 )
F_135 () ;
V_129 = V_173 -> V_174 ;
if ( V_175 ) {
F_125 ( V_175 , 0 ) ;
F_108 ( V_175 ) ;
}
V_175 = F_126 () ;
F_140 ( V_173 ) ;
}
static int F_141 ( void * V_49 , T_5 V_176 )
{
struct V_173 * V_173 ;
V_173 = F_86 ( sizeof( * V_173 ) , V_177 ) ;
if ( ! V_173 )
return - V_144 ;
V_173 -> V_174 = ! ! V_176 ;
F_110 ( & V_173 -> V_125 , F_139 ) ;
F_111 ( & V_173 -> V_125 ) ;
return 0 ;
}
static int F_142 ( void * V_49 , T_5 * V_176 )
{
* V_176 = V_129 ;
return 0 ;
}
static T_6 F_143 ( struct V_178 * V_179 ,
const char T_7 * V_180 ,
T_8 V_27 ,
T_9 * V_181 )
{
char V_166 [ 32 ] ;
T_8 V_182 = F_144 ( V_27 , sizeof( V_166 ) - 1 ) ;
int V_46 ;
T_1 V_70 ;
T_3 V_74 ;
struct V_18 * V_19 = NULL ;
if ( F_145 ( V_166 , V_180 , V_182 ) )
return - V_183 ;
V_166 [ V_182 ] = '\0' ;
if ( memcmp ( V_166 , L_33 , 8 ) == 0 ) {
V_46 = F_130 ( & V_166 [ 8 ] , & V_70 , & V_74 , & V_19 ) ;
if ( V_46 == - V_39 )
return V_46 ;
if ( V_175 ) {
F_125 ( V_175 , 0 ) ;
F_108 ( V_175 ) ;
V_175 = NULL ;
}
if ( V_19 ) {
struct V_6 * V_7 ;
if ( ! F_79 ( V_19 -> V_31 ) )
return - V_39 ;
V_7 = F_26 ( V_19 ) ;
if ( V_7 ) {
F_10 ( L_34 ) ;
return - V_184 ;
}
F_10 ( L_35 , V_19 ,
& V_19 -> V_31 -> V_15 , V_19 -> V_31 -> V_16 ,
V_74 ) ;
}
V_46 = F_121 ( & V_70 , V_74 ) ;
if ( V_46 < 0 )
return V_46 ;
return V_27 ;
}
if ( memcmp ( V_166 , L_36 , 11 ) == 0 ) {
V_46 = F_130 ( & V_166 [ 11 ] , & V_70 , & V_74 , & V_19 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_124 ( V_19 , V_74 ) ;
if ( V_46 < 0 )
return V_46 ;
return V_27 ;
}
return V_27 ;
}
static int F_146 ( struct V_185 * V_186 , void * V_187 )
{
struct V_1 * V_30 ;
struct V_6 * V_7 ;
F_87 ( & V_141 ) ;
F_147 (entry, &bt_6lowpan_devices, list) {
F_147 (peer, &entry->peers, list)
F_148 ( V_186 , L_37 ,
& V_7 -> V_14 -> V_15 , V_7 -> V_14 -> V_16 ) ;
}
F_89 ( & V_141 ) ;
return 0 ;
}
static int F_149 ( struct V_188 * V_188 , struct V_178 * V_178 )
{
return F_150 ( V_178 , F_146 , V_188 -> V_189 ) ;
}
static void F_151 ( void )
{
struct V_1 * V_30 , * V_190 , * V_191 ;
struct V_172 V_192 ;
F_88 ( & V_192 ) ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
V_191 = F_136 ( sizeof( * V_191 ) , V_34 ) ;
if ( ! V_191 )
break;
V_191 -> V_3 = V_30 -> V_3 ;
F_88 ( & V_191 -> V_8 ) ;
F_3 ( & V_191 -> V_8 , & V_192 ) ;
}
F_16 () ;
F_138 (entry, tmp, &devices, list) {
F_74 ( V_30 -> V_3 ) ;
F_10 ( L_38 ,
V_30 -> V_3 -> V_97 , V_30 -> V_3 ) ;
F_106 ( V_30 -> V_3 ) ;
F_140 ( V_30 ) ;
}
}
static int F_152 ( struct V_193 * V_194 ,
unsigned long V_195 , void * V_187 )
{
struct V_2 * V_3 = F_153 ( V_187 ) ;
struct V_1 * V_30 ;
if ( V_3 -> type != V_48 )
return V_196 ;
switch ( V_195 ) {
case V_197 :
F_87 ( & V_141 ) ;
F_147 (entry, &bt_6lowpan_devices, list) {
if ( V_30 -> V_3 == V_3 ) {
F_10 ( L_39 ,
V_3 -> V_97 , V_3 ) ;
F_154 ( & V_30 -> V_8 ) ;
break;
}
}
F_89 ( & V_141 ) ;
break;
}
return V_196 ;
}
static int T_10 F_155 ( void )
{
V_198 = F_156 ( L_40 , 0644 ,
V_199 , NULL ,
& V_200 ) ;
V_201 = F_156 ( L_41 , 0644 ,
V_199 , NULL ,
& V_202 ) ;
return F_157 ( & V_203 ) ;
}
static void T_11 F_158 ( void )
{
F_159 ( V_198 ) ;
F_159 ( V_201 ) ;
if ( V_175 ) {
F_125 ( V_175 , 0 ) ;
F_108 ( V_175 ) ;
}
F_151 () ;
F_160 ( & V_203 ) ;
}
