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
F_7 ( V_6 , V_10 ) ;
F_8 ( V_11 ) ;
if ( F_9 ( & V_4 -> V_9 ) ) {
F_10 ( L_1 ) ;
return true ;
}
return false ;
}
static inline struct V_5 * F_11 ( struct V_1 * V_4 ,
T_1 * V_12 , T_2 type )
{
struct V_5 * V_6 ;
F_10 ( L_2 , F_12 ( & V_4 -> V_9 ) ,
V_12 , type ) ;
F_13 () ;
F_14 (peer, &dev->peers, list) {
F_10 ( L_3 ,
& V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_15 ) ;
if ( F_15 ( & V_6 -> V_13 -> V_14 , V_12 ) )
continue;
if ( type == V_6 -> V_13 -> V_15 ) {
F_16 () ;
return V_6 ;
}
}
F_16 () ;
return NULL ;
}
static inline struct V_5 * F_17 ( struct V_1 * V_4 ,
struct V_16 * V_13 )
{
struct V_5 * V_6 ;
F_14 (peer, &dev->peers, list) {
if ( V_6 -> V_13 == V_13 )
return V_6 ;
}
return NULL ;
}
static inline struct V_5 * F_18 ( struct V_1 * V_4 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 ;
F_14 (peer, &dev->peers, list) {
if ( V_6 -> V_13 -> V_18 == V_18 )
return V_6 ;
}
return NULL ;
}
static inline struct V_5 * F_19 ( struct V_1 * V_4 ,
struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_5 * V_6 ;
struct V_19 * V_23 ;
struct V_24 * V_25 = (struct V_24 * ) F_20 ( V_22 ) ;
int V_26 = F_12 ( & V_4 -> V_9 ) ;
F_10 ( L_4 , V_26 , V_20 , V_25 ) ;
if ( V_26 == 1 ) {
F_13 () ;
V_6 = F_21 ( & V_4 -> V_8 , struct V_5 ,
V_7 ) ;
F_16 () ;
return V_6 ;
}
if ( ! V_25 ) {
V_23 = & F_22 ( V_22 ) -> V_27 ;
if ( F_23 ( V_23 ) )
return NULL ;
} else {
V_23 = F_24 ( V_25 , V_20 ) ;
memcpy ( & F_22 ( V_22 ) -> V_27 , V_23 , sizeof( struct V_19 ) ) ;
}
F_10 ( L_5 , V_23 ) ;
F_13 () ;
F_14 (peer, &dev->peers, list) {
F_10 ( L_6 ,
& V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_15 ,
& V_6 -> V_28 ) ;
if ( ! F_25 ( & V_6 -> V_28 , V_23 ) ) {
F_16 () ;
return V_6 ;
}
}
F_16 () ;
return NULL ;
}
static struct V_5 * F_26 ( struct V_17 * V_18 )
{
struct V_1 * V_29 ;
struct V_5 * V_6 = NULL ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
V_6 = F_18 ( V_29 , V_18 ) ;
if ( V_6 )
break;
}
F_16 () ;
return V_6 ;
}
static struct V_1 * F_27 ( struct V_17 * V_18 )
{
struct V_1 * V_29 ;
struct V_1 * V_4 = NULL ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
if ( V_18 -> V_30 -> V_31 == V_29 -> V_31 ) {
V_4 = V_29 ;
break;
}
}
F_16 () ;
return V_4 ;
}
static int F_28 ( struct V_21 * V_22 , struct V_2 * V_4 )
{
struct V_21 * V_32 ;
V_32 = F_29 ( V_22 , V_33 ) ;
if ( ! V_32 )
return V_34 ;
return F_30 ( V_32 ) ;
}
static int F_31 ( struct V_21 * V_22 , struct V_2 * V_3 ,
struct V_16 * V_13 )
{
const T_3 * V_35 , * V_20 ;
T_3 V_36 , V_37 ;
struct V_1 * V_4 ;
struct V_5 * V_6 ;
V_4 = V_1 ( V_3 ) ;
F_13 () ;
V_6 = F_17 ( V_4 , V_13 ) ;
F_16 () ;
if ( ! V_6 )
return - V_38 ;
V_35 = V_6 -> V_39 ;
V_20 = V_4 -> V_3 -> V_40 ;
if ( V_22 -> V_41 < 2 )
return - V_38 ;
if ( F_32 ( V_22 , & V_36 ) )
return - V_38 ;
if ( F_32 ( V_22 , & V_37 ) )
return - V_38 ;
return F_33 ( V_22 , V_3 ,
V_35 , V_42 ,
V_43 , V_20 ,
V_42 , V_43 ,
V_36 , V_37 ) ;
}
static int F_34 ( struct V_21 * V_22 , struct V_2 * V_4 ,
struct V_16 * V_13 )
{
struct V_21 * V_44 ;
int V_45 ;
if ( ! F_35 ( V_4 ) )
goto V_46;
if ( V_4 -> type != V_47 )
goto V_46;
V_22 = F_36 ( V_22 , V_33 ) ;
if ( ! V_22 )
goto V_46;
if ( V_22 -> V_48 [ 0 ] == V_49 ) {
V_44 = F_37 ( V_22 , V_50 - 1 ,
F_38 ( V_22 ) , V_33 ) ;
if ( ! V_44 )
goto V_46;
V_44 -> V_51 = F_39 ( V_52 ) ;
V_44 -> V_53 = V_54 ;
F_40 ( V_44 ) ;
F_41 ( V_44 , sizeof( struct V_55 ) ) ;
if ( F_28 ( V_44 , V_4 ) != V_56 ) {
F_42 ( V_44 ) ;
goto V_46;
}
V_4 -> V_57 . V_58 += V_22 -> V_41 ;
V_4 -> V_57 . V_59 ++ ;
F_43 ( V_44 ) ;
F_43 ( V_22 ) ;
} else {
switch ( V_22 -> V_48 [ 0 ] & 0xe0 ) {
case V_60 :
V_44 = F_44 ( V_22 , V_33 ) ;
if ( ! V_44 )
goto V_46;
V_45 = F_31 ( V_44 , V_4 , V_13 ) ;
if ( V_45 < 0 ) {
F_42 ( V_44 ) ;
goto V_46;
}
V_44 -> V_51 = F_39 ( V_52 ) ;
V_44 -> V_53 = V_54 ;
V_44 -> V_4 = V_4 ;
if ( F_28 ( V_44 , V_4 )
!= V_56 ) {
F_42 ( V_44 ) ;
goto V_46;
}
V_4 -> V_57 . V_58 += V_22 -> V_41 ;
V_4 -> V_57 . V_59 ++ ;
F_43 ( V_44 ) ;
F_43 ( V_22 ) ;
break;
default:
break;
}
}
return V_56 ;
V_46:
V_4 -> V_57 . V_61 ++ ;
return V_34 ;
}
static int F_45 ( struct V_16 * V_13 , struct V_21 * V_22 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 ;
int V_62 ;
V_6 = F_26 ( V_13 -> V_18 ) ;
if ( ! V_6 )
return - V_63 ;
V_4 = F_27 ( V_13 -> V_18 ) ;
if ( ! V_4 || ! V_4 -> V_3 )
return - V_63 ;
V_62 = F_34 ( V_22 , V_4 -> V_3 , V_13 ) ;
if ( V_62 ) {
F_10 ( L_7 , V_62 ) ;
V_62 = - V_64 ;
}
return V_62 ;
}
static T_3 F_46 ( T_3 V_65 )
{
return ( ( V_65 & 0x02 ) ? V_66 : V_67 ) ;
}
static void F_47 ( struct V_19 * V_68 , T_1 * V_69 )
{
T_3 * V_70 = V_68 -> V_71 + 8 ;
V_69 -> V_72 [ 0 ] = V_70 [ 7 ] ;
V_69 -> V_72 [ 1 ] = V_70 [ 6 ] ;
V_69 -> V_72 [ 2 ] = V_70 [ 5 ] ;
V_69 -> V_72 [ 3 ] = V_70 [ 2 ] ;
V_69 -> V_72 [ 4 ] = V_70 [ 1 ] ;
V_69 -> V_72 [ 5 ] = V_70 [ 0 ] ;
}
static void F_48 ( struct V_19 * V_68 ,
T_1 * V_69 , T_3 * V_73 )
{
F_47 ( V_68 , V_69 ) ;
V_69 -> V_72 [ 5 ] ^= 0x02 ;
* V_73 = F_46 ( V_69 -> V_72 [ 5 ] ) ;
}
static int F_49 ( struct V_21 * V_22 , struct V_2 * V_3 ,
T_1 * V_28 , T_3 * V_74 )
{
struct V_19 V_75 ;
struct V_1 * V_4 ;
struct V_5 * V_6 ;
T_1 V_69 , * V_76 = V_77 ;
T_3 * V_20 = V_76 -> V_72 ;
int V_62 , V_78 = 0 ;
V_4 = V_1 ( V_3 ) ;
memcpy ( & V_75 , & F_22 ( V_22 ) -> V_69 , sizeof( V_75 ) ) ;
if ( F_50 ( & V_75 ) ) {
F_22 ( V_22 ) -> V_13 = NULL ;
} else {
T_3 V_73 ;
F_48 ( & V_75 , & V_69 , & V_73 ) ;
F_10 ( L_8 , & V_69 ,
V_73 , & V_75 ) ;
V_6 = F_11 ( V_4 , & V_69 , V_73 ) ;
if ( ! V_6 ) {
V_6 = F_19 ( V_4 , & V_75 , V_22 ) ;
if ( ! V_6 ) {
F_10 ( L_9 , & V_69 ) ;
return - V_63 ;
}
}
V_20 = V_6 -> V_39 ;
* V_28 = V_69 ;
* V_74 = V_73 ;
F_22 ( V_22 ) -> V_13 = V_6 -> V_13 ;
V_78 = 1 ;
}
F_51 ( V_22 , V_3 , V_52 , V_20 ,
V_4 -> V_3 -> V_40 , V_22 -> V_41 ) ;
V_62 = F_52 ( V_22 , V_3 , V_52 , NULL , NULL , 0 ) ;
if ( V_62 < 0 )
return V_62 ;
return V_78 ;
}
static int F_53 ( struct V_21 * V_22 , struct V_2 * V_3 ,
unsigned short type , const void * V_79 ,
const void * V_80 , unsigned int V_41 )
{
struct V_55 * V_81 ;
if ( type != V_52 )
return - V_38 ;
V_81 = F_54 ( V_22 ) ;
memcpy ( & F_22 ( V_22 ) -> V_69 , & V_81 -> V_20 , sizeof( struct V_19 ) ) ;
return 0 ;
}
static int F_55 ( struct V_16 * V_13 , struct V_21 * V_22 ,
struct V_2 * V_3 )
{
struct V_82 V_83 ;
struct V_84 V_85 ;
int V_62 ;
V_13 -> V_48 = V_22 ;
V_85 . V_86 = V_22 -> V_48 ;
V_85 . V_87 = V_22 -> V_41 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
F_56 ( & V_83 . V_88 , V_89 | V_90 , & V_85 , 1 , V_22 -> V_41 ) ;
V_62 = F_57 ( V_13 , & V_83 , V_22 -> V_41 ) ;
if ( V_62 > 0 ) {
V_3 -> V_57 . V_91 += V_62 ;
V_3 -> V_57 . V_92 ++ ;
return 0 ;
}
if ( ! V_62 )
V_62 = F_22 ( V_22 ) -> V_78 ;
if ( V_62 < 0 ) {
if ( V_62 == - V_64 )
V_3 -> V_57 . V_93 ++ ;
else
V_3 -> V_57 . V_94 ++ ;
}
return V_62 ;
}
static int F_58 ( struct V_21 * V_22 , struct V_2 * V_3 )
{
struct V_21 * V_44 ;
struct V_1 * V_29 ;
int V_62 = 0 ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
struct V_5 * V_95 ;
struct V_1 * V_4 ;
if ( V_29 -> V_3 != V_3 )
continue;
V_4 = V_1 ( V_29 -> V_3 ) ;
F_14 (pentry, &dev->peers, list) {
int V_45 ;
V_44 = F_44 ( V_22 , V_33 ) ;
F_10 ( L_10 ,
V_3 -> V_96 ,
& V_95 -> V_13 -> V_14 , V_95 -> V_13 -> V_15 ,
& V_95 -> V_28 , V_95 -> V_13 ) ;
V_45 = F_55 ( V_95 -> V_13 , V_44 , V_3 ) ;
if ( V_45 < 0 )
V_62 = V_45 ;
F_42 ( V_44 ) ;
}
}
F_16 () ;
return V_62 ;
}
static T_4 F_59 ( struct V_21 * V_22 , struct V_2 * V_3 )
{
int V_62 = 0 ;
T_1 V_69 ;
T_3 V_73 ;
V_22 = F_60 ( V_22 , V_33 ) ;
if ( ! V_22 )
return V_97 ;
V_62 = F_49 ( V_22 , V_3 , & V_69 , & V_73 ) ;
if ( V_62 < 0 ) {
F_42 ( V_22 ) ;
return V_97 ;
}
if ( V_62 ) {
if ( F_22 ( V_22 ) -> V_13 ) {
F_10 ( L_10 ,
V_3 -> V_96 , & V_69 , V_73 ,
& F_22 ( V_22 ) -> V_69 , F_22 ( V_22 ) -> V_13 ) ;
V_62 = F_55 ( F_22 ( V_22 ) -> V_13 , V_22 , V_3 ) ;
} else {
V_62 = - V_63 ;
}
} else {
V_62 = F_58 ( V_22 , V_3 ) ;
}
F_61 ( V_22 ) ;
if ( V_62 )
F_10 ( L_11 , V_62 ) ;
return V_62 < 0 ? V_97 : V_62 ;
}
static void F_62 ( struct V_2 * V_4 ,
struct V_98 * V_99 ,
void * V_100 )
{
F_63 ( & V_99 -> V_101 , & V_102 ) ;
}
static int F_64 ( struct V_2 * V_4 )
{
F_65 ( V_4 , F_62 , NULL ) ;
V_4 -> V_103 = & V_104 ;
return 0 ;
}
static void F_66 ( struct V_2 * V_4 )
{
V_4 -> V_105 = V_43 ;
V_4 -> type = V_47 ;
V_4 -> V_106 = 0 ;
V_4 -> V_107 = 0 ;
V_4 -> V_108 = V_109 ;
V_4 -> V_110 = 0 ;
V_4 -> V_111 = V_112 | V_113 |
V_114 ;
V_4 -> V_115 = 0 ;
V_4 -> V_116 = & V_116 ;
V_4 -> V_117 = & V_117 ;
V_4 -> V_118 = V_119 ;
}
static void F_67 ( T_3 * V_120 , T_3 * V_69 , T_3 V_73 )
{
V_120 [ 0 ] = V_69 [ 5 ] ;
V_120 [ 1 ] = V_69 [ 4 ] ;
V_120 [ 2 ] = V_69 [ 3 ] ;
V_120 [ 3 ] = 0xFF ;
V_120 [ 4 ] = 0xFE ;
V_120 [ 5 ] = V_69 [ 2 ] ;
V_120 [ 6 ] = V_69 [ 1 ] ;
V_120 [ 7 ] = V_69 [ 0 ] ;
if ( V_73 == V_67 )
V_120 [ 0 ] &= ~ 0x02 ;
else
V_120 [ 0 ] |= 0x02 ;
F_10 ( L_12 , V_73 , 8 , V_120 ) ;
}
static void F_68 ( struct V_2 * V_3 , T_1 * V_69 ,
T_3 V_73 )
{
V_3 -> V_121 = V_122 ;
F_67 ( V_3 -> V_40 , V_69 -> V_72 , V_73 ) ;
}
static void F_69 ( struct V_2 * V_3 )
{
int V_62 ;
F_70 () ;
V_62 = F_71 ( V_3 ) ;
if ( V_62 < 0 )
F_72 ( L_13 , V_3 -> V_96 , V_62 ) ;
F_73 () ;
}
static void F_74 ( struct V_2 * V_3 )
{
int V_62 ;
F_70 () ;
V_62 = F_75 ( V_3 ) ;
if ( V_62 < 0 )
F_72 ( L_14 , V_3 -> V_96 , V_62 ) ;
F_73 () ;
}
static void F_76 ( struct V_123 * V_124 )
{
struct V_1 * V_4 = F_77 ( V_124 , struct V_1 ,
V_125 . V_124 ) ;
F_78 ( V_4 -> V_3 ) ;
}
static bool F_79 ( struct V_126 * V_30 )
{
if ( V_30 -> type != V_127 )
return false ;
if ( ! V_128 )
return false ;
return true ;
}
static struct V_16 * F_80 ( void )
{
struct V_16 * V_13 ;
V_13 = F_81 () ;
if ( ! V_13 )
return NULL ;
F_82 ( V_13 ) ;
V_13 -> V_129 = V_130 ;
V_13 -> V_131 = V_132 ;
V_13 -> V_133 = 65535 ;
V_13 -> V_134 = V_13 -> V_133 ;
return V_13 ;
}
static struct V_16 * F_83 ( struct V_16 * V_135 )
{
struct V_16 * V_13 ;
V_13 = F_80 () ;
if ( ! V_13 )
return NULL ;
V_13 -> V_136 = V_13 -> V_133 ;
V_13 -> V_137 = V_13 -> V_133 ;
V_13 -> V_138 = V_139 ;
return V_13 ;
}
static void F_84 ( T_3 V_73 , T_3 * V_69 )
{
if ( V_73 == V_67 )
* V_69 |= 0x02 ;
else
* V_69 &= ~ 0x02 ;
}
static struct V_16 * F_85 ( struct V_16 * V_13 ,
struct V_1 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_86 ( sizeof( * V_6 ) , V_33 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_13 = V_13 ;
memset ( & V_6 -> V_28 , 0 , sizeof( struct V_19 ) ) ;
V_6 -> V_28 . V_71 [ 0 ] = 0xFE ;
V_6 -> V_28 . V_71 [ 1 ] = 0x80 ;
F_67 ( ( T_3 * ) & V_6 -> V_28 . V_71 + 8 , V_13 -> V_14 . V_72 ,
V_13 -> V_15 ) ;
memcpy ( & V_6 -> V_39 , ( T_3 * ) & V_6 -> V_28 . V_71 + 8 ,
V_43 ) ;
F_84 ( V_13 -> V_15 , ( T_3 * ) & V_6 -> V_28 . V_71 + 8 ) ;
F_87 ( & V_140 ) ;
F_88 ( & V_6 -> V_7 ) ;
F_2 ( V_4 , V_6 ) ;
F_89 ( & V_140 ) ;
F_90 ( & V_4 -> V_125 , F_76 ) ;
F_91 ( & V_4 -> V_125 , F_92 ( 100 ) ) ;
return V_6 -> V_13 ;
}
static int F_93 ( struct V_16 * V_13 , struct V_1 * * V_4 )
{
struct V_2 * V_3 ;
int V_62 = 0 ;
V_3 = F_94 ( sizeof( struct V_1 ) , V_141 ,
V_142 , F_66 ) ;
if ( ! V_3 )
return - V_143 ;
F_68 ( V_3 , & V_13 -> V_144 , V_13 -> V_145 ) ;
V_3 -> V_116 = & V_116 ;
F_95 ( V_3 , & V_13 -> V_18 -> V_30 -> V_31 -> V_4 ) ;
F_96 ( V_3 , & V_146 ) ;
V_62 = F_97 ( V_3 ) ;
if ( V_62 < 0 ) {
F_72 ( L_15 , V_62 ) ;
V_119 ( V_3 ) ;
goto V_147;
}
F_10 ( L_16 ,
V_3 -> V_148 , & V_13 -> V_14 , V_13 -> V_15 ,
& V_13 -> V_144 , V_13 -> V_145 ) ;
F_98 ( V_149 , & V_3 -> V_138 ) ;
* V_4 = F_1 ( V_3 ) ;
( * V_4 ) -> V_3 = V_3 ;
( * V_4 ) -> V_31 = V_13 -> V_18 -> V_30 -> V_31 ;
F_88 ( & ( * V_4 ) -> V_8 ) ;
F_87 ( & V_140 ) ;
F_88 ( & ( * V_4 ) -> V_7 ) ;
F_3 ( & ( * V_4 ) -> V_7 , & V_150 ) ;
F_89 ( & V_140 ) ;
return 0 ;
V_147:
return V_62 ;
}
static inline void F_99 ( struct V_16 * V_13 )
{
struct V_1 * V_4 ;
V_4 = F_27 ( V_13 -> V_18 ) ;
F_10 ( L_17 , V_13 , V_13 -> V_18 , V_4 ) ;
if ( ! V_4 ) {
if ( F_93 ( V_13 , & V_4 ) < 0 ) {
F_100 ( V_13 , - V_63 ) ;
return;
}
}
if ( ! F_101 ( V_11 ) )
return;
F_85 ( V_13 , V_4 ) ;
F_69 ( V_4 -> V_3 ) ;
}
static inline struct V_16 * F_102 ( struct V_16 * V_135 )
{
struct V_16 * V_13 ;
V_13 = F_83 ( V_135 ) ;
V_13 -> V_151 = V_135 -> V_151 ;
F_10 ( L_18 , V_13 , V_135 ) ;
return V_13 ;
}
static void F_103 ( struct V_123 * V_124 )
{
struct V_1 * V_29 = F_77 ( V_124 , struct V_1 ,
F_103 ) ;
F_104 ( V_29 -> V_3 ) ;
}
static void F_105 ( struct V_16 * V_13 )
{
struct V_1 * V_29 ;
struct V_1 * V_4 = NULL ;
struct V_5 * V_6 ;
int V_62 = - V_63 ;
bool V_152 = false , remove = true ;
F_10 ( L_19 , V_13 , V_13 -> V_18 ) ;
if ( V_13 -> V_18 && V_13 -> V_18 -> V_30 ) {
if ( ! F_79 ( V_13 -> V_18 -> V_30 ) )
return;
remove = false ;
}
F_87 ( & V_140 ) ;
F_14 (entry, &bt_6lowpan_devices, list) {
V_4 = V_1 ( V_29 -> V_3 ) ;
V_6 = F_17 ( V_4 , V_13 ) ;
if ( V_6 ) {
V_152 = F_5 ( V_4 , V_6 ) ;
V_62 = 0 ;
F_10 ( L_20 , V_4 ,
V_152 ? L_21 : L_22 , V_6 ) ;
F_10 ( L_23 , V_13 ,
F_12 ( & V_13 -> V_153 . V_154 ) ) ;
F_106 ( V_13 ) ;
break;
}
}
if ( ! V_62 && V_152 && V_4 && ! F_12 ( & V_4 -> V_9 ) ) {
F_89 ( & V_140 ) ;
F_107 ( & V_4 -> V_125 ) ;
F_74 ( V_4 -> V_3 ) ;
if ( remove ) {
F_108 ( & V_29 -> F_103 , F_103 ) ;
F_109 ( & V_29 -> F_103 ) ;
}
} else {
F_89 ( & V_140 ) ;
}
return;
}
static void F_110 ( struct V_16 * V_13 , int V_138 , int V_62 )
{
F_10 ( L_24 , V_13 , V_13 -> V_18 ,
F_111 ( V_138 ) , V_62 ) ;
}
static struct V_21 * F_112 ( struct V_16 * V_13 ,
unsigned long V_155 ,
unsigned long V_41 , int V_156 )
{
return F_113 ( V_155 + V_41 , V_33 ) ;
}
static void F_114 ( struct V_16 * V_13 )
{
struct V_21 * V_22 = V_13 -> V_48 ;
F_10 ( L_25 , V_13 , V_13 -> V_18 , V_22 ) ;
if ( ! V_22 )
return;
F_22 ( V_22 ) -> V_78 = - V_64 ;
}
static void F_115 ( struct V_16 * V_13 )
{
struct V_21 * V_22 = V_13 -> V_48 ;
F_10 ( L_25 , V_13 , V_13 -> V_18 , V_22 ) ;
if ( ! V_22 )
return;
F_22 ( V_22 ) -> V_78 = 0 ;
}
static long F_116 ( struct V_16 * V_13 )
{
return V_157 ;
}
static inline T_2 F_117 ( T_2 type )
{
if ( type == V_158 )
return V_67 ;
else
return V_66 ;
}
static struct V_16 * F_118 ( void )
{
struct V_16 * V_135 ;
V_135 = F_80 () ;
if ( ! V_135 )
return NULL ;
V_135 -> V_151 = & V_159 ;
return V_135 ;
}
static int F_119 ( T_1 * V_69 , T_3 V_15 )
{
struct V_16 * V_135 ;
int V_62 ;
V_135 = F_118 () ;
if ( ! V_135 )
return - V_38 ;
V_62 = F_120 ( V_135 , F_121 ( V_160 ) , 0 ,
V_69 , V_15 ) ;
F_10 ( L_26 , V_135 , V_62 ) ;
if ( V_62 < 0 )
F_106 ( V_135 ) ;
return V_62 ;
}
static int F_122 ( struct V_17 * V_18 , T_3 V_15 )
{
struct V_5 * V_6 ;
F_10 ( L_27 , V_18 , V_15 ) ;
V_6 = F_26 ( V_18 ) ;
if ( ! V_6 )
return - V_63 ;
F_10 ( L_28 , V_6 , V_6 -> V_13 ) ;
F_123 ( V_6 -> V_13 , V_63 ) ;
return 0 ;
}
static struct V_16 * F_124 ( void )
{
T_1 * V_69 = V_77 ;
struct V_16 * V_135 ;
int V_62 ;
if ( ! V_128 )
return NULL ;
V_135 = F_118 () ;
if ( ! V_135 )
return NULL ;
V_135 -> V_138 = V_161 ;
V_135 -> V_145 = V_67 ;
F_125 ( & V_135 -> V_162 , V_163 ) ;
F_10 ( L_29 , V_135 , V_135 -> V_145 ) ;
V_62 = F_126 ( V_135 , V_69 , F_121 ( V_160 ) ) ;
if ( V_62 ) {
F_106 ( V_135 ) ;
F_127 ( L_30 , V_62 ) ;
return NULL ;
}
return V_135 ;
}
static int F_128 ( char * V_164 , T_1 * V_69 , T_3 * V_73 ,
struct V_17 * * V_18 )
{
struct V_126 * V_30 ;
struct V_165 * V_31 ;
T_1 * V_144 = V_77 ;
int V_166 ;
V_166 = sscanf ( V_164 , L_31 ,
& V_69 -> V_72 [ 5 ] , & V_69 -> V_72 [ 4 ] , & V_69 -> V_72 [ 3 ] ,
& V_69 -> V_72 [ 2 ] , & V_69 -> V_72 [ 1 ] , & V_69 -> V_72 [ 0 ] ,
V_73 ) ;
if ( V_166 < 7 )
return - V_38 ;
V_31 = F_129 ( V_69 , V_144 ) ;
if ( ! V_31 )
return - V_63 ;
F_130 ( V_31 ) ;
V_30 = F_131 ( V_31 , V_127 , V_69 ) ;
F_132 ( V_31 ) ;
if ( ! V_30 )
return - V_63 ;
* V_18 = (struct V_17 * ) V_30 -> V_167 ;
F_10 ( L_32 , * V_18 , & V_30 -> V_14 , V_30 -> V_15 ) ;
return 0 ;
}
static void F_133 ( void )
{
struct V_1 * V_29 ;
struct V_5 * V_6 , * V_168 , * V_169 ;
struct V_170 V_8 ;
F_88 ( & V_8 ) ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
F_14 (peer, &entry->peers, list) {
V_169 = F_134 ( sizeof( * V_169 ) , V_33 ) ;
if ( ! V_169 )
break;
V_169 -> V_13 = V_6 -> V_13 ;
F_88 ( & V_169 -> V_7 ) ;
F_135 ( & V_169 -> V_7 , & V_8 ) ;
}
}
F_16 () ;
F_87 ( & V_140 ) ;
F_136 (peer, tmp_peer, &peers, list) {
F_123 ( V_6 -> V_13 , V_63 ) ;
F_6 ( & V_6 -> V_7 ) ;
F_7 ( V_6 , V_10 ) ;
}
F_89 ( & V_140 ) ;
}
static void F_137 ( struct V_123 * V_124 )
{
struct V_171 * V_171 = F_77 ( V_124 ,
struct V_171 , V_124 ) ;
if ( ! V_171 -> V_172 || V_128 != V_171 -> V_172 )
F_133 () ;
V_128 = V_171 -> V_172 ;
if ( V_173 ) {
F_123 ( V_173 , 0 ) ;
F_106 ( V_173 ) ;
}
V_173 = F_124 () ;
F_138 ( V_171 ) ;
}
static int F_139 ( void * V_48 , T_5 V_174 )
{
struct V_171 * V_171 ;
V_171 = F_86 ( sizeof( * V_171 ) , V_175 ) ;
if ( ! V_171 )
return - V_143 ;
V_171 -> V_172 = ! ! V_174 ;
F_108 ( & V_171 -> V_124 , F_137 ) ;
F_109 ( & V_171 -> V_124 ) ;
return 0 ;
}
static int F_140 ( void * V_48 , T_5 * V_174 )
{
* V_174 = V_128 ;
return 0 ;
}
static T_6 F_141 ( struct V_176 * V_177 ,
const char T_7 * V_178 ,
T_8 V_26 ,
T_9 * V_179 )
{
char V_164 [ 32 ] ;
T_8 V_180 = F_142 ( V_26 , sizeof( V_164 ) - 1 ) ;
int V_45 ;
T_1 V_69 ;
T_3 V_73 ;
struct V_17 * V_18 = NULL ;
if ( F_143 ( V_164 , V_178 , V_180 ) )
return - V_181 ;
V_164 [ V_180 ] = '\0' ;
if ( memcmp ( V_164 , L_33 , 8 ) == 0 ) {
V_45 = F_128 ( & V_164 [ 8 ] , & V_69 , & V_73 , & V_18 ) ;
if ( V_45 == - V_38 )
return V_45 ;
if ( V_173 ) {
F_123 ( V_173 , 0 ) ;
F_106 ( V_173 ) ;
V_173 = NULL ;
}
if ( V_18 ) {
struct V_5 * V_6 ;
if ( ! F_79 ( V_18 -> V_30 ) )
return - V_38 ;
V_6 = F_26 ( V_18 ) ;
if ( V_6 ) {
F_10 ( L_34 ) ;
return - V_182 ;
}
F_10 ( L_35 , V_18 ,
& V_18 -> V_30 -> V_14 , V_18 -> V_30 -> V_15 ,
V_73 ) ;
}
V_45 = F_119 ( & V_69 , V_73 ) ;
if ( V_45 < 0 )
return V_45 ;
return V_26 ;
}
if ( memcmp ( V_164 , L_36 , 11 ) == 0 ) {
V_45 = F_128 ( & V_164 [ 11 ] , & V_69 , & V_73 , & V_18 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_122 ( V_18 , V_73 ) ;
if ( V_45 < 0 )
return V_45 ;
return V_26 ;
}
return V_26 ;
}
static int F_144 ( struct V_183 * V_184 , void * V_185 )
{
struct V_1 * V_29 ;
struct V_5 * V_6 ;
F_87 ( & V_140 ) ;
F_145 (entry, &bt_6lowpan_devices, list) {
F_145 (peer, &entry->peers, list)
F_146 ( V_184 , L_37 ,
& V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_15 ) ;
}
F_89 ( & V_140 ) ;
return 0 ;
}
static int F_147 ( struct V_186 * V_186 , struct V_176 * V_176 )
{
return F_148 ( V_176 , F_144 , V_186 -> V_187 ) ;
}
static void F_149 ( void )
{
struct V_1 * V_29 , * V_188 , * V_189 ;
struct V_170 V_190 ;
F_88 ( & V_190 ) ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
V_189 = F_134 ( sizeof( * V_189 ) , V_33 ) ;
if ( ! V_189 )
break;
V_189 -> V_3 = V_29 -> V_3 ;
F_88 ( & V_189 -> V_7 ) ;
F_3 ( & V_189 -> V_7 , & V_190 ) ;
}
F_16 () ;
F_136 (entry, tmp, &devices, list) {
F_74 ( V_29 -> V_3 ) ;
F_10 ( L_38 ,
V_29 -> V_3 -> V_96 , V_29 -> V_3 ) ;
F_104 ( V_29 -> V_3 ) ;
F_138 ( V_29 ) ;
}
}
static int F_150 ( struct V_191 * V_192 ,
unsigned long V_193 , void * V_185 )
{
struct V_2 * V_3 = F_151 ( V_185 ) ;
struct V_1 * V_29 ;
if ( V_3 -> type != V_47 )
return V_194 ;
switch ( V_193 ) {
case V_195 :
F_87 ( & V_140 ) ;
F_145 (entry, &bt_6lowpan_devices, list) {
if ( V_29 -> V_3 == V_3 ) {
F_10 ( L_39 ,
V_3 -> V_96 , V_3 ) ;
F_152 ( & V_29 -> V_7 ) ;
break;
}
}
F_89 ( & V_140 ) ;
break;
}
return V_194 ;
}
static int T_10 F_153 ( void )
{
V_196 = F_154 ( L_40 , 0644 ,
V_197 , NULL ,
& V_198 ) ;
V_199 = F_154 ( L_41 , 0644 ,
V_197 , NULL ,
& V_200 ) ;
return F_155 ( & V_201 ) ;
}
static void T_11 F_156 ( void )
{
F_157 ( V_196 ) ;
F_157 ( V_199 ) ;
if ( V_173 ) {
F_123 ( V_173 , 0 ) ;
F_106 ( V_173 ) ;
}
F_149 () ;
F_158 ( & V_201 ) ;
}
