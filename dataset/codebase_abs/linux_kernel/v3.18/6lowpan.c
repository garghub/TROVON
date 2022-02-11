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
static inline struct V_5 * F_16 ( struct V_1 * V_4 ,
struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_5 * V_6 , * V_12 ;
struct V_19 * V_23 ;
struct V_24 * V_25 = (struct V_24 * ) F_17 ( V_22 ) ;
int V_26 = F_11 ( & V_4 -> V_9 ) ;
F_9 ( L_4 , V_26 , V_20 , V_25 ) ;
if ( V_26 == 1 )
return F_18 ( & V_4 -> V_8 , struct V_5 ,
V_7 ) ;
if ( ! V_25 ) {
V_23 = & F_19 ( V_22 ) -> V_27 ;
if ( F_20 ( V_23 ) )
return NULL ;
} else {
V_23 = F_21 ( V_25 ) ;
memcpy ( & F_19 ( V_22 ) -> V_27 , V_23 , sizeof( struct V_19 ) ) ;
}
F_9 ( L_5 , V_23 ) ;
F_12 (peer, tmp, &dev->peers, list) {
F_9 ( L_6 ,
& V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_15 ,
& V_6 -> V_28 ) ;
if ( ! F_22 ( & V_6 -> V_28 , V_23 ) )
return V_6 ;
}
return NULL ;
}
static struct V_5 * F_23 ( struct V_17 * V_18 )
{
struct V_1 * V_29 , * V_12 ;
struct V_5 * V_6 = NULL ;
unsigned long V_30 ;
F_24 ( & V_31 , V_30 ) ;
F_12 (entry, tmp, &bt_6lowpan_devices, list) {
V_6 = F_15 ( V_29 , V_18 ) ;
if ( V_6 )
break;
}
F_25 ( & V_31 , V_30 ) ;
return V_6 ;
}
static struct V_1 * F_26 ( struct V_17 * V_18 )
{
struct V_1 * V_29 , * V_12 ;
struct V_1 * V_4 = NULL ;
unsigned long V_30 ;
F_24 ( & V_31 , V_30 ) ;
F_12 (entry, tmp, &bt_6lowpan_devices, list) {
if ( V_18 -> V_32 -> V_33 == V_29 -> V_33 ) {
V_4 = V_29 ;
break;
}
}
F_25 ( & V_31 , V_30 ) ;
return V_4 ;
}
static int F_27 ( struct V_21 * V_22 , struct V_2 * V_4 )
{
struct V_21 * V_34 ;
int V_35 ;
V_34 = F_28 ( V_22 , V_36 ) ;
if ( ! V_34 )
return - V_37 ;
V_35 = F_29 ( V_34 ) ;
if ( V_35 < 0 ) {
F_9 ( L_7 , V_35 ) ;
return V_38 ;
}
return V_35 ;
}
static int F_30 ( struct V_21 * V_22 , struct V_2 * V_3 ,
struct V_16 * V_13 )
{
const T_3 * V_39 , * V_20 ;
T_3 V_40 , V_41 ;
struct V_1 * V_4 ;
struct V_5 * V_6 ;
unsigned long V_30 ;
V_4 = V_1 ( V_3 ) ;
F_24 ( & V_31 , V_30 ) ;
V_6 = F_14 ( V_4 , V_13 ) ;
F_25 ( & V_31 , V_30 ) ;
if ( ! V_6 )
goto V_42;
V_39 = V_6 -> V_43 ;
V_20 = V_4 -> V_3 -> V_44 ;
if ( V_22 -> V_45 < 2 )
goto V_42;
if ( F_31 ( V_22 , & V_40 ) )
goto V_42;
if ( F_31 ( V_22 , & V_41 ) )
goto V_42;
return F_32 ( V_22 , V_3 ,
V_39 , V_46 , V_47 ,
V_20 , V_46 , V_47 ,
V_40 , V_41 , F_27 ) ;
V_42:
F_33 ( V_22 ) ;
return - V_48 ;
}
static int F_34 ( struct V_21 * V_22 , struct V_2 * V_4 ,
struct V_16 * V_13 )
{
struct V_21 * V_49 ;
int V_35 ;
if ( ! F_35 ( V_4 ) )
goto V_42;
if ( V_4 -> type != V_50 )
goto V_42;
if ( V_22 -> V_51 [ 0 ] == V_52 ) {
V_49 = F_36 ( V_22 , V_53 - 1 ,
F_37 ( V_22 ) , V_36 ) ;
if ( ! V_49 )
goto V_42;
V_49 -> V_54 = F_38 ( V_55 ) ;
V_49 -> V_56 = V_57 ;
F_39 ( V_49 ) ;
F_40 ( V_49 , sizeof( struct V_58 ) ) ;
if ( F_27 ( V_49 , V_4 ) != V_59 ) {
F_33 ( V_49 ) ;
goto V_42;
}
V_4 -> V_60 . V_61 += V_22 -> V_45 ;
V_4 -> V_60 . V_62 ++ ;
F_33 ( V_49 ) ;
F_33 ( V_22 ) ;
} else {
switch ( V_22 -> V_51 [ 0 ] & 0xe0 ) {
case V_63 :
V_49 = F_41 ( V_22 , V_36 ) ;
if ( ! V_49 )
goto V_42;
V_35 = F_30 ( V_49 , V_4 , V_13 ) ;
if ( V_35 != V_59 )
goto V_42;
V_4 -> V_60 . V_61 += V_22 -> V_45 ;
V_4 -> V_60 . V_62 ++ ;
F_33 ( V_22 ) ;
break;
default:
break;
}
}
return V_59 ;
V_42:
V_4 -> V_60 . V_64 ++ ;
F_33 ( V_22 ) ;
return V_38 ;
}
static int F_42 ( struct V_16 * V_13 , struct V_21 * V_22 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 ;
int V_65 ;
V_6 = F_23 ( V_13 -> V_18 ) ;
if ( ! V_6 )
return - V_66 ;
V_4 = F_26 ( V_13 -> V_18 ) ;
if ( ! V_4 || ! V_4 -> V_3 )
return - V_66 ;
V_65 = F_34 ( V_22 , V_4 -> V_3 , V_13 ) ;
if ( V_65 ) {
F_9 ( L_8 , V_65 ) ;
V_65 = - V_67 ;
}
return V_65 ;
}
static T_3 F_43 ( T_3 V_68 )
{
return ( ( V_68 & 0x02 ) ? V_69 : V_70 ) ;
}
static void F_44 ( struct V_19 * V_71 , T_1 * V_72 )
{
T_3 * V_73 = V_71 -> V_74 + 8 ;
V_72 -> V_75 [ 0 ] = V_73 [ 7 ] ;
V_72 -> V_75 [ 1 ] = V_73 [ 6 ] ;
V_72 -> V_75 [ 2 ] = V_73 [ 5 ] ;
V_72 -> V_75 [ 3 ] = V_73 [ 2 ] ;
V_72 -> V_75 [ 4 ] = V_73 [ 1 ] ;
V_72 -> V_75 [ 5 ] = V_73 [ 0 ] ;
}
static void F_45 ( struct V_19 * V_71 ,
T_1 * V_72 , T_3 * V_76 )
{
F_44 ( V_71 , V_72 ) ;
V_72 -> V_75 [ 5 ] ^= 0x02 ;
* V_76 = F_43 ( V_72 -> V_75 [ 5 ] ) ;
}
static int F_46 ( struct V_21 * V_22 , struct V_2 * V_3 ,
T_1 * V_28 , T_3 * V_77 )
{
struct V_19 V_78 ;
struct V_1 * V_4 ;
struct V_5 * V_6 ;
T_1 V_72 , * V_79 = V_80 ;
T_3 * V_20 = V_79 -> V_75 ;
int V_65 , V_81 = 0 ;
V_4 = V_1 ( V_3 ) ;
memcpy ( & V_78 , & F_19 ( V_22 ) -> V_72 , sizeof( V_78 ) ) ;
if ( F_47 ( & V_78 ) ) {
F_19 ( V_22 ) -> V_13 = NULL ;
} else {
unsigned long V_30 ;
T_3 V_76 ;
F_45 ( & V_78 , & V_72 , & V_76 ) ;
F_9 ( L_9 , & V_72 ,
V_76 , & V_78 ) ;
F_24 ( & V_31 , V_30 ) ;
V_6 = F_10 ( V_4 , & V_72 , V_76 ) ;
F_25 ( & V_31 , V_30 ) ;
if ( ! V_6 ) {
F_24 ( & V_31 , V_30 ) ;
V_6 = F_16 ( V_4 , & V_78 , V_22 ) ;
F_25 ( & V_31 , V_30 ) ;
if ( ! V_6 ) {
F_9 ( L_10 , & V_72 ) ;
return - V_66 ;
}
}
V_20 = V_6 -> V_43 ;
* V_28 = V_72 ;
* V_77 = V_76 ;
F_19 ( V_22 ) -> V_13 = V_6 -> V_13 ;
V_81 = 1 ;
}
F_48 ( V_22 , V_3 , V_55 , V_20 ,
V_4 -> V_3 -> V_44 , V_22 -> V_45 ) ;
V_65 = F_49 ( V_22 , V_3 , V_55 , NULL , NULL , 0 ) ;
if ( V_65 < 0 )
return V_65 ;
return V_81 ;
}
static int F_50 ( struct V_21 * V_22 , struct V_2 * V_3 ,
unsigned short type , const void * V_82 ,
const void * V_83 , unsigned int V_45 )
{
struct V_58 * V_84 ;
if ( type != V_55 )
return - V_48 ;
V_84 = F_51 ( V_22 ) ;
memcpy ( & F_19 ( V_22 ) -> V_72 , & V_84 -> V_20 , sizeof( struct V_19 ) ) ;
return 0 ;
}
static int F_52 ( struct V_16 * V_13 , struct V_21 * V_22 ,
struct V_2 * V_3 )
{
struct V_85 V_86 ;
struct V_87 V_88 ;
int V_65 ;
V_13 -> V_51 = V_22 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_89 = (struct V_90 * ) & V_88 ;
V_86 . V_91 = 1 ;
V_88 . V_92 = V_22 -> V_51 ;
V_88 . V_93 = V_22 -> V_45 ;
V_65 = F_53 ( V_13 , & V_86 , V_22 -> V_45 ) ;
if ( V_65 > 0 ) {
V_3 -> V_60 . V_94 += V_65 ;
V_3 -> V_60 . V_95 ++ ;
return 0 ;
}
if ( ! V_65 )
V_65 = F_19 ( V_22 ) -> V_81 ;
if ( V_65 < 0 ) {
if ( V_65 == - V_67 )
V_3 -> V_60 . V_96 ++ ;
else
V_3 -> V_60 . V_97 ++ ;
}
return V_65 ;
}
static int F_54 ( struct V_21 * V_22 , struct V_2 * V_3 )
{
struct V_21 * V_49 ;
struct V_1 * V_29 , * V_12 ;
unsigned long V_30 ;
int V_65 = 0 ;
F_24 ( & V_31 , V_30 ) ;
F_12 (entry, tmp, &bt_6lowpan_devices, list) {
struct V_5 * V_98 , * V_99 ;
struct V_1 * V_4 ;
if ( V_29 -> V_3 != V_3 )
continue;
V_4 = V_1 ( V_29 -> V_3 ) ;
F_12 (pentry, ptmp, &dev->peers, list) {
int V_35 ;
V_49 = F_41 ( V_22 , V_36 ) ;
F_9 ( L_11 ,
V_3 -> V_100 ,
& V_98 -> V_13 -> V_14 , V_98 -> V_13 -> V_15 ,
& V_98 -> V_28 , V_98 -> V_13 ) ;
V_35 = F_52 ( V_98 -> V_13 , V_49 , V_3 ) ;
if ( V_35 < 0 )
V_65 = V_35 ;
F_33 ( V_49 ) ;
}
}
F_25 ( & V_31 , V_30 ) ;
return V_65 ;
}
static T_4 F_55 ( struct V_21 * V_22 , struct V_2 * V_3 )
{
int V_65 = 0 ;
T_1 V_72 ;
T_3 V_76 ;
struct V_21 * V_101 ;
V_101 = F_56 ( V_22 , V_36 ) ;
if ( ! V_101 ) {
F_33 ( V_22 ) ;
return V_102 ;
}
V_22 = V_101 ;
V_65 = F_46 ( V_22 , V_3 , & V_72 , & V_76 ) ;
if ( V_65 < 0 ) {
F_33 ( V_22 ) ;
return V_102 ;
}
if ( V_65 ) {
if ( F_19 ( V_22 ) -> V_13 ) {
F_9 ( L_11 ,
V_3 -> V_100 , & V_72 , V_76 ,
& F_19 ( V_22 ) -> V_72 , F_19 ( V_22 ) -> V_13 ) ;
V_65 = F_52 ( F_19 ( V_22 ) -> V_13 , V_22 , V_3 ) ;
} else {
V_65 = - V_66 ;
}
} else {
V_65 = F_54 ( V_22 , V_3 ) ;
}
F_57 ( V_22 ) ;
if ( V_65 )
F_9 ( L_12 , V_65 ) ;
return V_65 < 0 ? V_102 : V_65 ;
}
static void F_58 ( struct V_2 * V_4 )
{
V_4 -> V_103 = V_47 ;
V_4 -> type = V_50 ;
V_4 -> V_104 = 0 ;
V_4 -> V_105 = 0 ;
V_4 -> V_106 = V_107 ;
V_4 -> V_108 = 0 ;
V_4 -> V_30 = V_109 | V_110 |
V_111 ;
V_4 -> V_112 = 0 ;
V_4 -> V_113 = & V_113 ;
V_4 -> V_114 = & V_114 ;
V_4 -> V_115 = V_116 ;
}
static void F_59 ( T_3 * V_117 , T_3 * V_72 , T_3 V_76 )
{
V_117 [ 0 ] = V_72 [ 5 ] ;
V_117 [ 1 ] = V_72 [ 4 ] ;
V_117 [ 2 ] = V_72 [ 3 ] ;
V_117 [ 3 ] = 0xFF ;
V_117 [ 4 ] = 0xFE ;
V_117 [ 5 ] = V_72 [ 2 ] ;
V_117 [ 6 ] = V_72 [ 1 ] ;
V_117 [ 7 ] = V_72 [ 0 ] ;
if ( V_76 == V_70 )
V_117 [ 0 ] &= ~ 0x02 ;
else
V_117 [ 0 ] |= 0x02 ;
F_9 ( L_13 , V_76 , 8 , V_117 ) ;
}
static void F_60 ( struct V_2 * V_3 , T_1 * V_72 ,
T_3 V_76 )
{
V_3 -> V_118 = V_119 ;
F_59 ( V_3 -> V_44 , V_72 -> V_75 , V_76 ) ;
}
static void F_61 ( struct V_2 * V_3 )
{
int V_65 ;
F_62 () ;
V_65 = F_63 ( V_3 ) ;
if ( V_65 < 0 )
F_64 ( L_14 , V_3 -> V_100 , V_65 ) ;
F_65 () ;
}
static void F_66 ( struct V_2 * V_3 )
{
int V_65 ;
F_62 () ;
V_65 = F_67 ( V_3 ) ;
if ( V_65 < 0 )
F_64 ( L_15 , V_3 -> V_100 , V_65 ) ;
F_65 () ;
}
static void F_68 ( struct V_120 * V_121 )
{
struct V_1 * V_4 = F_69 ( V_121 , struct V_1 ,
V_122 . V_121 ) ;
F_70 ( V_4 -> V_3 ) ;
}
static bool F_71 ( struct V_123 * V_32 )
{
if ( V_32 -> type != V_124 )
return false ;
if ( ! V_125 )
return false ;
return true ;
}
static struct V_16 * F_72 ( void )
{
struct V_16 * V_13 ;
V_13 = F_73 () ;
if ( ! V_13 )
return NULL ;
F_74 ( V_13 ) ;
V_13 -> V_126 = V_127 ;
V_13 -> V_128 = V_129 ;
V_13 -> V_130 = 65535 ;
V_13 -> V_131 = V_13 -> V_130 ;
return V_13 ;
}
static struct V_16 * F_75 ( struct V_16 * V_132 )
{
struct V_16 * V_13 ;
V_13 = F_72 () ;
if ( ! V_13 )
return NULL ;
V_13 -> V_133 = V_13 -> V_130 ;
V_13 -> V_134 = V_13 -> V_130 ;
V_13 -> V_135 = V_136 ;
return V_13 ;
}
static void F_76 ( T_3 V_76 , T_3 * V_72 )
{
if ( V_76 == V_70 )
* V_72 |= 0x02 ;
else
* V_72 &= ~ 0x02 ;
}
static struct V_16 * F_77 ( struct V_16 * V_13 ,
struct V_1 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_30 ;
V_6 = F_78 ( sizeof( * V_6 ) , V_36 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_13 = V_13 ;
memset ( & V_6 -> V_28 , 0 , sizeof( struct V_19 ) ) ;
V_6 -> V_28 . V_74 [ 0 ] = 0xFE ;
V_6 -> V_28 . V_74 [ 1 ] = 0x80 ;
F_59 ( ( T_3 * ) & V_6 -> V_28 . V_74 + 8 , V_13 -> V_14 . V_75 ,
V_13 -> V_15 ) ;
memcpy ( & V_6 -> V_43 , ( T_3 * ) & V_6 -> V_28 . V_74 + 8 ,
V_47 ) ;
F_76 ( V_13 -> V_15 , ( T_3 * ) & V_6 -> V_28 . V_74 + 8 ) ;
F_79 ( & V_31 , V_30 ) ;
F_80 ( & V_6 -> V_7 ) ;
F_2 ( V_4 , V_6 ) ;
F_81 ( & V_31 , V_30 ) ;
F_82 ( & V_4 -> V_122 , F_68 ) ;
F_83 ( & V_4 -> V_122 , F_84 ( 100 ) ) ;
return V_6 -> V_13 ;
}
static int F_85 ( struct V_16 * V_13 , struct V_1 * * V_4 )
{
struct V_2 * V_3 ;
int V_65 = 0 ;
unsigned long V_30 ;
V_3 = F_86 ( sizeof( struct V_1 ) , V_137 ,
V_138 , F_58 ) ;
if ( ! V_3 )
return - V_37 ;
F_60 ( V_3 , & V_13 -> V_139 , V_13 -> V_140 ) ;
V_3 -> V_113 = & V_113 ;
F_87 ( V_3 , & V_13 -> V_18 -> V_32 -> V_4 ) ;
F_88 ( V_3 , & V_141 ) ;
V_65 = F_89 ( V_3 ) ;
if ( V_65 < 0 ) {
F_64 ( L_16 , V_65 ) ;
V_116 ( V_3 ) ;
goto V_142;
}
F_9 ( L_17 ,
V_3 -> V_143 , & V_13 -> V_14 , V_13 -> V_15 ,
& V_13 -> V_139 , V_13 -> V_140 ) ;
F_90 ( V_144 , & V_3 -> V_135 ) ;
* V_4 = F_1 ( V_3 ) ;
( * V_4 ) -> V_3 = V_3 ;
( * V_4 ) -> V_33 = V_13 -> V_18 -> V_32 -> V_33 ;
F_80 ( & ( * V_4 ) -> V_8 ) ;
F_79 ( & V_31 , V_30 ) ;
F_80 ( & ( * V_4 ) -> V_7 ) ;
F_3 ( & ( * V_4 ) -> V_7 , & V_145 ) ;
F_81 ( & V_31 , V_30 ) ;
return 0 ;
V_142:
return V_65 ;
}
static inline void F_91 ( struct V_16 * V_13 )
{
struct V_1 * V_4 ;
V_4 = F_26 ( V_13 -> V_18 ) ;
F_9 ( L_18 , V_13 , V_13 -> V_18 , V_4 ) ;
if ( ! V_4 ) {
if ( F_85 ( V_13 , & V_4 ) < 0 ) {
F_92 ( V_13 , - V_66 ) ;
return;
}
}
if ( ! F_93 ( V_10 ) )
return;
F_77 ( V_13 , V_4 ) ;
F_61 ( V_4 -> V_3 ) ;
}
static inline struct V_16 * F_94 ( struct V_16 * V_132 )
{
struct V_16 * V_13 ;
V_13 = F_75 ( V_132 ) ;
V_13 -> V_146 = V_132 -> V_146 ;
F_9 ( L_19 , V_13 , V_132 ) ;
return V_13 ;
}
static void F_95 ( struct V_120 * V_121 )
{
struct V_1 * V_29 = F_69 ( V_121 , struct V_1 ,
F_95 ) ;
F_96 ( V_29 -> V_3 ) ;
}
static void F_97 ( struct V_16 * V_13 )
{
struct V_1 * V_29 , * V_12 ;
struct V_1 * V_4 = NULL ;
struct V_5 * V_6 ;
int V_65 = - V_66 ;
unsigned long V_30 ;
bool V_147 = false , V_148 = true ;
F_9 ( L_20 , V_13 , V_13 -> V_18 ) ;
if ( V_13 -> V_18 && V_13 -> V_18 -> V_32 ) {
if ( ! F_71 ( V_13 -> V_18 -> V_32 ) )
return;
V_148 = false ;
}
F_79 ( & V_31 , V_30 ) ;
F_12 (entry, tmp, &bt_6lowpan_devices, list) {
V_4 = V_1 ( V_29 -> V_3 ) ;
V_6 = F_14 ( V_4 , V_13 ) ;
if ( V_6 ) {
V_147 = F_5 ( V_4 , V_6 ) ;
V_65 = 0 ;
F_9 ( L_21 , V_4 ,
V_147 ? L_22 : L_23 , V_6 ) ;
F_9 ( L_24 , V_13 ,
F_11 ( & V_13 -> V_149 . V_150 ) ) ;
F_98 ( V_13 ) ;
F_99 ( V_6 ) ;
break;
}
}
if ( ! V_65 && V_147 && V_4 && ! F_11 ( & V_4 -> V_9 ) ) {
F_81 ( & V_31 , V_30 ) ;
F_100 ( & V_4 -> V_122 ) ;
F_66 ( V_4 -> V_3 ) ;
if ( ! V_148 ) {
F_101 ( & V_29 -> F_95 , F_95 ) ;
F_102 ( & V_29 -> F_95 ) ;
}
} else {
F_81 ( & V_31 , V_30 ) ;
}
return;
}
static void F_103 ( struct V_16 * V_13 , int V_135 , int V_65 )
{
F_9 ( L_25 , V_13 , V_13 -> V_18 ,
F_104 ( V_135 ) , V_65 ) ;
}
static struct V_21 * F_105 ( struct V_16 * V_13 ,
unsigned long V_151 ,
unsigned long V_45 , int V_152 )
{
return F_106 ( V_151 + V_45 , V_36 ) ;
}
static void F_107 ( struct V_16 * V_13 )
{
struct V_21 * V_22 = V_13 -> V_51 ;
F_9 ( L_26 , V_13 , V_13 -> V_18 , V_22 ) ;
if ( ! V_22 )
return;
F_19 ( V_22 ) -> V_81 = - V_67 ;
}
static void F_108 ( struct V_16 * V_13 )
{
struct V_21 * V_22 = V_13 -> V_51 ;
F_9 ( L_26 , V_13 , V_13 -> V_18 , V_22 ) ;
if ( ! V_22 )
return;
F_19 ( V_22 ) -> V_81 = 0 ;
}
static long F_109 ( struct V_16 * V_13 )
{
return V_153 ;
}
static inline T_2 F_110 ( T_2 type )
{
if ( type == V_154 )
return V_70 ;
else
return V_69 ;
}
static struct V_16 * F_111 ( void )
{
struct V_16 * V_132 ;
V_132 = F_72 () ;
if ( ! V_132 )
return NULL ;
V_132 -> V_146 = & V_155 ;
return V_132 ;
}
static int F_112 ( T_1 * V_72 , T_3 V_15 )
{
struct V_16 * V_132 ;
int V_65 ;
V_132 = F_111 () ;
if ( ! V_132 )
return - V_48 ;
V_65 = F_113 ( V_132 , F_114 ( V_125 ) , 0 ,
V_72 , V_15 ) ;
F_9 ( L_27 , V_132 , V_65 ) ;
if ( V_65 < 0 )
F_98 ( V_132 ) ;
return V_65 ;
}
static int F_115 ( struct V_17 * V_18 , T_3 V_15 )
{
struct V_5 * V_6 ;
F_9 ( L_28 , V_18 , V_15 ) ;
V_6 = F_23 ( V_18 ) ;
if ( ! V_6 )
return - V_66 ;
F_9 ( L_29 , V_6 , V_6 -> V_13 ) ;
F_116 ( V_6 -> V_13 , V_66 ) ;
return 0 ;
}
static struct V_16 * F_117 ( void )
{
T_1 * V_72 = V_80 ;
struct V_16 * V_132 ;
int V_65 ;
if ( V_125 == 0 )
return NULL ;
V_132 = F_111 () ;
if ( ! V_132 )
return NULL ;
V_132 -> V_135 = V_156 ;
V_132 -> V_140 = V_70 ;
F_9 ( L_30 , V_125 , V_132 ,
V_132 -> V_140 ) ;
V_65 = F_118 ( V_132 , V_72 , F_114 ( V_125 ) ) ;
if ( V_65 ) {
F_98 ( V_132 ) ;
F_119 ( L_31 , V_65 ) ;
return NULL ;
}
return V_132 ;
}
static int F_120 ( char * V_157 , T_1 * V_72 , T_3 * V_76 ,
struct V_17 * * V_18 )
{
struct V_123 * V_32 ;
struct V_158 * V_33 ;
T_1 * V_139 = V_80 ;
int V_159 ;
V_159 = sscanf ( V_157 , L_32 ,
& V_72 -> V_75 [ 5 ] , & V_72 -> V_75 [ 4 ] , & V_72 -> V_75 [ 3 ] ,
& V_72 -> V_75 [ 2 ] , & V_72 -> V_75 [ 1 ] , & V_72 -> V_75 [ 0 ] ,
V_76 ) ;
if ( V_159 < 7 )
return - V_48 ;
V_33 = F_121 ( V_72 , V_139 ) ;
if ( ! V_33 )
return - V_66 ;
F_122 ( V_33 ) ;
V_32 = F_123 ( V_33 , V_124 , V_72 ) ;
F_124 ( V_33 ) ;
if ( ! V_32 )
return - V_66 ;
* V_18 = (struct V_17 * ) V_32 -> V_160 ;
F_9 ( L_33 , * V_18 , & V_32 -> V_14 , V_32 -> V_15 ) ;
return 0 ;
}
static void F_125 ( void )
{
struct V_1 * V_29 , * V_161 ;
struct V_5 * V_6 , * V_162 , * V_163 ;
struct V_164 V_8 ;
unsigned long V_30 ;
F_80 ( & V_8 ) ;
F_24 ( & V_31 , V_30 ) ;
F_12 (entry, tmp_dev, &bt_6lowpan_devices, list) {
F_12 (peer, tmp_peer, &entry->peers, list) {
V_163 = F_126 ( sizeof( * V_163 ) , V_36 ) ;
if ( ! V_163 )
break;
V_163 -> V_13 = V_6 -> V_13 ;
F_80 ( & V_163 -> V_7 ) ;
F_3 ( & V_163 -> V_7 , & V_8 ) ;
}
}
F_25 ( & V_31 , V_30 ) ;
F_12 (peer, tmp_peer, &peers, list) {
F_116 ( V_6 -> V_13 , V_66 ) ;
F_99 ( V_6 ) ;
}
}
static int F_127 ( void * V_51 , T_5 V_165 )
{
T_6 V_166 ;
V_166 = V_165 ;
if ( V_166 == 0 || V_125 != V_166 )
F_125 () ;
V_125 = V_166 ;
if ( V_167 ) {
F_116 ( V_167 , 0 ) ;
F_98 ( V_167 ) ;
}
V_167 = F_117 () ;
return 0 ;
}
static int F_128 ( void * V_51 , T_5 * V_165 )
{
* V_165 = V_125 ;
return 0 ;
}
static T_7 F_129 ( struct V_168 * V_169 ,
const char T_8 * V_170 ,
T_9 V_26 ,
T_10 * V_171 )
{
char V_157 [ 32 ] ;
T_9 V_172 = F_130 ( V_26 , sizeof( V_157 ) - 1 ) ;
int V_35 ;
T_1 V_72 ;
T_3 V_76 ;
struct V_17 * V_18 = NULL ;
if ( F_131 ( V_157 , V_170 , V_172 ) )
return - V_173 ;
V_157 [ V_172 ] = '\0' ;
if ( memcmp ( V_157 , L_34 , 8 ) == 0 ) {
V_35 = F_120 ( & V_157 [ 8 ] , & V_72 , & V_76 , & V_18 ) ;
if ( V_35 == - V_48 )
return V_35 ;
if ( V_167 ) {
F_116 ( V_167 , 0 ) ;
F_98 ( V_167 ) ;
V_167 = NULL ;
}
if ( V_18 ) {
struct V_5 * V_6 ;
if ( ! F_71 ( V_18 -> V_32 ) )
return - V_48 ;
V_6 = F_23 ( V_18 ) ;
if ( V_6 ) {
F_9 ( L_35 ) ;
return - V_174 ;
}
F_9 ( L_36 , V_18 ,
& V_18 -> V_32 -> V_14 , V_18 -> V_32 -> V_15 ,
V_76 ) ;
}
V_35 = F_112 ( & V_72 , V_76 ) ;
if ( V_35 < 0 )
return V_35 ;
return V_26 ;
}
if ( memcmp ( V_157 , L_37 , 11 ) == 0 ) {
V_35 = F_120 ( & V_157 [ 11 ] , & V_72 , & V_76 , & V_18 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_115 ( V_18 , V_76 ) ;
if ( V_35 < 0 )
return V_35 ;
return V_26 ;
}
return V_26 ;
}
static int F_132 ( struct V_175 * V_176 , void * V_177 )
{
struct V_1 * V_29 , * V_161 ;
struct V_5 * V_6 , * V_162 ;
unsigned long V_30 ;
F_24 ( & V_31 , V_30 ) ;
F_12 (entry, tmp_dev, &bt_6lowpan_devices, list) {
F_12 (peer, tmp_peer, &entry->peers, list)
F_133 ( V_176 , L_38 ,
& V_6 -> V_13 -> V_14 , V_6 -> V_13 -> V_15 ) ;
}
F_25 ( & V_31 , V_30 ) ;
return 0 ;
}
static int F_134 ( struct V_178 * V_178 , struct V_168 * V_168 )
{
return F_135 ( V_168 , F_132 , V_178 -> V_179 ) ;
}
static void F_136 ( void )
{
struct V_1 * V_29 , * V_12 , * V_180 ;
struct V_164 V_181 ;
unsigned long V_30 ;
F_80 ( & V_181 ) ;
F_24 ( & V_31 , V_30 ) ;
F_12 (entry, tmp, &bt_6lowpan_devices, list) {
V_180 = F_126 ( sizeof( * V_180 ) , V_36 ) ;
if ( ! V_180 )
break;
V_180 -> V_3 = V_29 -> V_3 ;
F_80 ( & V_180 -> V_7 ) ;
F_3 ( & V_180 -> V_7 , & V_181 ) ;
}
F_25 ( & V_31 , V_30 ) ;
F_12 (entry, tmp, &devices, list) {
F_66 ( V_29 -> V_3 ) ;
F_9 ( L_39 ,
V_29 -> V_3 -> V_100 , V_29 -> V_3 ) ;
F_96 ( V_29 -> V_3 ) ;
F_99 ( V_29 ) ;
}
}
static int F_137 ( struct V_182 * V_183 ,
unsigned long V_184 , void * V_177 )
{
struct V_2 * V_3 = F_138 ( V_177 ) ;
struct V_1 * V_29 , * V_12 ;
unsigned long V_30 ;
if ( V_3 -> type != V_50 )
return V_185 ;
switch ( V_184 ) {
case V_186 :
F_79 ( & V_31 , V_30 ) ;
F_12 (entry, tmp, &bt_6lowpan_devices,
list) {
if ( V_29 -> V_3 == V_3 ) {
F_9 ( L_40 ,
V_3 -> V_100 , V_3 ) ;
F_6 ( & V_29 -> V_7 ) ;
F_99 ( V_29 ) ;
break;
}
}
F_81 ( & V_31 , V_30 ) ;
break;
}
return V_185 ;
}
static int T_11 F_139 ( void )
{
V_187 = F_140 ( L_41 , 0644 ,
V_188 , NULL ,
& V_189 ) ;
V_190 = F_140 ( L_42 , 0644 ,
V_188 , NULL ,
& V_191 ) ;
return F_141 ( & V_192 ) ;
}
static void T_12 F_142 ( void )
{
F_143 ( V_187 ) ;
F_143 ( V_190 ) ;
if ( V_167 ) {
F_116 ( V_167 , 0 ) ;
F_98 ( V_167 ) ;
}
F_136 () ;
F_144 ( & V_192 ) ;
}
