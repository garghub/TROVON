static inline struct V_1 *
V_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) F_1 ( V_3 ) -> V_4 ;
}
static inline void F_2 ( struct V_1 * V_5 ,
struct V_6 * V_7 )
{
F_3 ( & V_7 -> V_8 , & V_5 -> V_9 ) ;
F_4 ( & V_5 -> V_10 ) ;
}
static inline bool F_5 ( struct V_1 * V_5 ,
struct V_6 * V_7 )
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
static inline struct V_6 *
F_17 ( struct V_1 * V_5 , struct V_17 * V_14 )
{
struct V_6 * V_7 ;
F_14 (peer, &dev->peers, list) {
if ( V_7 -> V_14 == V_14 )
return V_7 ;
}
return NULL ;
}
static inline struct V_6 *
F_18 ( struct V_1 * V_5 , struct V_18 * V_19 )
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
struct V_1 * V_5 ;
struct V_6 * V_7 ;
V_5 = V_1 ( V_3 ) ;
F_13 () ;
V_7 = F_17 ( V_5 , V_14 ) ;
F_16 () ;
if ( ! V_7 )
return - V_37 ;
V_36 = V_7 -> V_38 ;
V_21 = V_5 -> V_3 -> V_39 ;
return F_32 ( V_23 , V_3 , V_21 , V_36 ) ;
}
static int F_33 ( struct V_22 * V_23 , struct V_2 * V_5 ,
struct V_17 * V_14 )
{
struct V_22 * V_40 ;
int V_41 ;
if ( ! F_34 ( V_5 ) )
goto V_42;
if ( V_5 -> type != V_43 || ! V_23 -> V_44 )
goto V_42;
F_35 ( V_23 ) ;
V_23 = F_36 ( V_23 , V_34 ) ;
if ( ! V_23 )
goto V_42;
if ( F_37 ( * F_38 ( V_23 ) ) ) {
F_39 ( V_23 , 1 ) ;
V_40 = F_40 ( V_23 , V_45 - 1 ,
F_41 ( V_23 ) , V_34 ) ;
if ( ! V_40 )
goto V_42;
V_40 -> V_46 = F_42 ( V_47 ) ;
V_40 -> V_48 = V_49 ;
V_40 -> V_5 = V_5 ;
F_43 ( V_40 , sizeof( struct V_50 ) ) ;
if ( F_28 ( V_40 , V_5 ) != V_51 ) {
F_44 ( V_40 ) ;
goto V_42;
}
V_5 -> V_52 . V_53 += V_23 -> V_44 ;
V_5 -> V_52 . V_54 ++ ;
F_45 ( V_40 ) ;
F_45 ( V_23 ) ;
} else if ( F_46 ( * F_38 ( V_23 ) ) ) {
V_40 = F_47 ( V_23 , V_34 ) ;
if ( ! V_40 )
goto V_42;
V_40 -> V_5 = V_5 ;
V_41 = F_31 ( V_40 , V_5 , V_14 ) ;
if ( V_41 < 0 ) {
F_44 ( V_40 ) ;
goto V_42;
}
V_40 -> V_46 = F_42 ( V_47 ) ;
V_40 -> V_48 = V_49 ;
if ( F_28 ( V_40 , V_5 )
!= V_51 ) {
F_44 ( V_40 ) ;
goto V_42;
}
V_5 -> V_52 . V_53 += V_23 -> V_44 ;
V_5 -> V_52 . V_54 ++ ;
F_45 ( V_40 ) ;
F_45 ( V_23 ) ;
} else {
goto V_42;
}
return V_51 ;
V_42:
V_5 -> V_52 . V_55 ++ ;
return V_35 ;
}
static int F_48 ( struct V_17 * V_14 , struct V_22 * V_23 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
int V_56 ;
V_7 = F_26 ( V_14 -> V_19 ) ;
if ( ! V_7 )
return - V_57 ;
V_5 = F_27 ( V_14 -> V_19 ) ;
if ( ! V_5 || ! V_5 -> V_3 )
return - V_57 ;
V_56 = F_33 ( V_23 , V_5 -> V_3 , V_14 ) ;
if ( V_56 ) {
F_10 ( L_7 , V_56 ) ;
V_56 = - V_58 ;
}
return V_56 ;
}
static T_3 F_49 ( T_3 V_59 )
{
return ( ( V_59 & 0x02 ) ? V_60 : V_61 ) ;
}
static void F_50 ( struct V_20 * V_62 , T_1 * V_63 )
{
T_3 * V_64 = V_62 -> V_65 + 8 ;
V_63 -> V_66 [ 0 ] = V_64 [ 7 ] ;
V_63 -> V_66 [ 1 ] = V_64 [ 6 ] ;
V_63 -> V_66 [ 2 ] = V_64 [ 5 ] ;
V_63 -> V_66 [ 3 ] = V_64 [ 2 ] ;
V_63 -> V_66 [ 4 ] = V_64 [ 1 ] ;
V_63 -> V_66 [ 5 ] = V_64 [ 0 ] ;
}
static void F_51 ( struct V_20 * V_62 ,
T_1 * V_63 , T_3 * V_67 )
{
F_50 ( V_62 , V_63 ) ;
V_63 -> V_66 [ 5 ] ^= 0x02 ;
* V_67 = F_49 ( V_63 -> V_66 [ 5 ] ) ;
}
static int F_52 ( struct V_22 * V_23 , struct V_2 * V_3 ,
T_1 * V_29 , T_3 * V_68 )
{
struct V_20 V_69 ;
struct V_50 * V_70 ;
struct V_1 * V_5 ;
struct V_6 * V_7 ;
T_1 V_63 , * V_71 = V_72 ;
T_3 * V_21 = V_71 -> V_66 ;
int V_56 , V_73 = 0 ;
V_70 = F_53 ( V_23 ) ;
V_5 = V_1 ( V_3 ) ;
memcpy ( & V_69 , & V_70 -> V_21 , sizeof( V_69 ) ) ;
if ( F_54 ( & V_69 ) ) {
F_22 ( V_23 ) -> V_14 = NULL ;
} else {
T_3 V_67 ;
F_51 ( & V_69 , & V_63 , & V_67 ) ;
F_10 ( L_8 , & V_63 ,
V_67 , & V_69 ) ;
V_7 = F_11 ( V_5 , & V_63 , V_67 ) ;
if ( ! V_7 ) {
V_7 = F_19 ( V_5 , & V_69 , V_23 ) ;
if ( ! V_7 ) {
F_10 ( L_9 , & V_63 ) ;
return - V_57 ;
}
}
V_21 = V_7 -> V_38 ;
* V_29 = V_63 ;
* V_68 = V_67 ;
F_22 ( V_23 ) -> V_14 = V_7 -> V_14 ;
V_73 = 1 ;
}
F_55 ( V_23 , V_3 , V_21 , V_5 -> V_3 -> V_39 ) ;
V_56 = F_56 ( V_23 , V_3 , V_47 , NULL , NULL , 0 ) ;
if ( V_56 < 0 )
return V_56 ;
return V_73 ;
}
static int F_57 ( struct V_22 * V_23 , struct V_2 * V_3 ,
unsigned short type , const void * V_74 ,
const void * V_75 , unsigned int V_44 )
{
if ( type != V_47 )
return - V_37 ;
return 0 ;
}
static int F_58 ( struct V_17 * V_14 , struct V_22 * V_23 ,
struct V_2 * V_3 )
{
struct V_76 V_77 ;
struct V_78 V_79 ;
int V_56 ;
V_14 -> V_80 = V_23 ;
V_79 . V_81 = V_23 -> V_80 ;
V_79 . V_82 = V_23 -> V_44 ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
F_59 ( & V_77 . V_83 , V_84 | V_85 , & V_79 , 1 , V_23 -> V_44 ) ;
V_56 = F_60 ( V_14 , & V_77 , V_23 -> V_44 ) ;
if ( V_56 > 0 ) {
V_3 -> V_52 . V_86 += V_56 ;
V_3 -> V_52 . V_87 ++ ;
return 0 ;
}
if ( ! V_56 )
V_56 = F_22 ( V_23 ) -> V_73 ;
if ( V_56 < 0 ) {
if ( V_56 == - V_58 )
V_3 -> V_52 . V_88 ++ ;
else
V_3 -> V_52 . V_89 ++ ;
}
return V_56 ;
}
static int F_61 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
struct V_22 * V_40 ;
struct V_1 * V_30 ;
int V_56 = 0 ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
struct V_6 * V_90 ;
struct V_1 * V_5 ;
if ( V_30 -> V_3 != V_3 )
continue;
V_5 = V_1 ( V_30 -> V_3 ) ;
F_14 (pentry, &dev->peers, list) {
int V_41 ;
V_40 = F_47 ( V_23 , V_34 ) ;
F_10 ( L_10 ,
V_3 -> V_91 ,
& V_90 -> V_14 -> V_15 , V_90 -> V_14 -> V_16 ,
& V_90 -> V_29 , V_90 -> V_14 ) ;
V_41 = F_58 ( V_90 -> V_14 , V_40 , V_3 ) ;
if ( V_41 < 0 )
V_56 = V_41 ;
F_44 ( V_40 ) ;
}
}
F_16 () ;
return V_56 ;
}
static T_4 F_62 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
int V_56 = 0 ;
T_1 V_63 ;
T_3 V_67 ;
V_23 = F_63 ( V_23 , V_34 ) ;
if ( ! V_23 )
return V_92 ;
V_56 = F_52 ( V_23 , V_3 , & V_63 , & V_67 ) ;
if ( V_56 < 0 ) {
F_44 ( V_23 ) ;
return V_92 ;
}
if ( V_56 ) {
if ( F_22 ( V_23 ) -> V_14 ) {
F_10 ( L_10 ,
V_3 -> V_91 , & V_63 , V_67 ,
& F_22 ( V_23 ) -> V_63 , F_22 ( V_23 ) -> V_14 ) ;
V_56 = F_58 ( F_22 ( V_23 ) -> V_14 , V_23 , V_3 ) ;
} else {
V_56 = - V_57 ;
}
} else {
V_56 = F_61 ( V_23 , V_3 ) ;
}
F_64 ( V_23 ) ;
if ( V_56 )
F_10 ( L_11 , V_56 ) ;
return V_56 < 0 ? V_92 : V_56 ;
}
static int F_65 ( struct V_2 * V_5 )
{
F_66 ( V_5 ) ;
return 0 ;
}
static void F_67 ( struct V_2 * V_5 )
{
V_5 -> V_93 = 0 ;
V_5 -> V_94 = 0 ;
V_5 -> V_95 = V_96 | V_97 |
V_98 ;
V_5 -> V_99 = 0 ;
V_5 -> V_100 = & V_100 ;
V_5 -> V_101 = & V_101 ;
V_5 -> V_102 = V_103 ;
}
static void F_68 ( T_3 * V_104 , T_3 * V_63 , T_3 V_67 )
{
V_104 [ 0 ] = V_63 [ 5 ] ;
V_104 [ 1 ] = V_63 [ 4 ] ;
V_104 [ 2 ] = V_63 [ 3 ] ;
V_104 [ 3 ] = 0xFF ;
V_104 [ 4 ] = 0xFE ;
V_104 [ 5 ] = V_63 [ 2 ] ;
V_104 [ 6 ] = V_63 [ 1 ] ;
V_104 [ 7 ] = V_63 [ 0 ] ;
if ( V_67 == V_61 )
V_104 [ 0 ] &= ~ 0x02 ;
else
V_104 [ 0 ] |= 0x02 ;
F_10 ( L_12 , V_67 , 8 , V_104 ) ;
}
static void F_69 ( struct V_2 * V_3 , T_1 * V_63 ,
T_3 V_67 )
{
V_3 -> V_105 = V_106 ;
F_68 ( V_3 -> V_39 , V_63 -> V_66 , V_67 ) ;
}
static void F_70 ( struct V_2 * V_3 )
{
int V_56 ;
F_71 () ;
V_56 = F_72 ( V_3 ) ;
if ( V_56 < 0 )
F_73 ( L_13 , V_3 -> V_91 , V_56 ) ;
F_74 () ;
}
static void F_75 ( struct V_2 * V_3 )
{
int V_56 ;
F_71 () ;
V_56 = F_76 ( V_3 ) ;
if ( V_56 < 0 )
F_73 ( L_14 , V_3 -> V_91 , V_56 ) ;
F_74 () ;
}
static void F_77 ( struct V_107 * V_108 )
{
struct V_1 * V_5 = F_78 ( V_108 , struct V_1 ,
V_109 . V_108 ) ;
F_79 ( V_5 -> V_3 ) ;
}
static bool F_80 ( struct V_110 * V_31 )
{
if ( V_31 -> type != V_111 )
return false ;
if ( ! V_112 )
return false ;
return true ;
}
static struct V_17 * F_81 ( void )
{
struct V_17 * V_14 ;
V_14 = F_82 () ;
if ( ! V_14 )
return NULL ;
F_83 ( V_14 ) ;
V_14 -> V_113 = V_114 ;
V_14 -> V_115 = V_116 ;
V_14 -> V_117 = 1280 ;
return V_14 ;
}
static void F_84 ( T_3 V_67 , T_3 * V_63 )
{
if ( V_67 == V_61 )
* V_63 |= 0x02 ;
else
* V_63 &= ~ 0x02 ;
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
V_7 -> V_29 . V_65 [ 0 ] = 0xFE ;
V_7 -> V_29 . V_65 [ 1 ] = 0x80 ;
F_68 ( ( T_3 * ) & V_7 -> V_29 . V_65 + 8 , V_14 -> V_15 . V_66 ,
V_14 -> V_16 ) ;
memcpy ( & V_7 -> V_38 , ( T_3 * ) & V_7 -> V_29 . V_65 + 8 ,
V_118 ) ;
F_84 ( V_14 -> V_16 , ( T_3 * ) & V_7 -> V_29 . V_65 + 8 ) ;
F_87 ( & V_119 ) ;
F_88 ( & V_7 -> V_8 ) ;
F_2 ( V_5 , V_7 ) ;
F_89 ( & V_119 ) ;
F_90 ( & V_5 -> V_109 , F_77 ) ;
F_91 ( & V_5 -> V_109 , F_92 ( 100 ) ) ;
return V_7 -> V_14 ;
}
static int F_93 ( struct V_17 * V_14 , struct V_1 * * V_5 )
{
struct V_2 * V_3 ;
int V_56 = 0 ;
V_3 = F_94 ( F_95 ( sizeof( struct V_1 ) ) ,
V_120 , V_121 ,
F_67 ) ;
if ( ! V_3 )
return - V_122 ;
F_69 ( V_3 , & V_14 -> V_123 , V_14 -> V_124 ) ;
V_3 -> V_100 = & V_100 ;
F_96 ( V_3 , & V_14 -> V_19 -> V_31 -> V_32 -> V_5 ) ;
F_97 ( V_3 , & V_125 ) ;
* V_5 = V_1 ( V_3 ) ;
( * V_5 ) -> V_3 = V_3 ;
( * V_5 ) -> V_32 = V_14 -> V_19 -> V_31 -> V_32 ;
F_88 ( & ( * V_5 ) -> V_9 ) ;
F_87 ( & V_119 ) ;
F_88 ( & ( * V_5 ) -> V_8 ) ;
F_3 ( & ( * V_5 ) -> V_8 , & V_126 ) ;
F_89 ( & V_119 ) ;
V_56 = F_98 ( V_3 , V_127 ) ;
if ( V_56 < 0 ) {
F_73 ( L_15 , V_56 ) ;
F_87 ( & V_119 ) ;
F_6 ( & ( * V_5 ) -> V_8 ) ;
F_89 ( & V_119 ) ;
V_103 ( V_3 ) ;
goto V_128;
}
F_10 ( L_16 ,
V_3 -> V_129 , & V_14 -> V_15 , V_14 -> V_16 ,
& V_14 -> V_123 , V_14 -> V_124 ) ;
F_99 ( V_130 , & V_3 -> V_131 ) ;
return 0 ;
V_128:
return V_56 ;
}
static inline void F_100 ( struct V_17 * V_14 )
{
struct V_1 * V_5 ;
V_5 = F_27 ( V_14 -> V_19 ) ;
F_10 ( L_17 , V_14 , V_14 -> V_19 , V_5 ) ;
if ( ! V_5 ) {
if ( F_93 ( V_14 , & V_5 ) < 0 ) {
F_101 ( V_14 , - V_57 ) ;
return;
}
}
if ( ! F_102 ( V_12 ) )
return;
F_85 ( V_14 , V_5 ) ;
F_70 ( V_5 -> V_3 ) ;
}
static inline struct V_17 * F_103 ( struct V_17 * V_132 )
{
struct V_17 * V_14 ;
V_14 = F_81 () ;
if ( ! V_14 )
return NULL ;
V_14 -> V_133 = V_132 -> V_133 ;
F_10 ( L_18 , V_14 , V_132 ) ;
return V_14 ;
}
static void F_104 ( struct V_107 * V_108 )
{
struct V_1 * V_30 = F_78 ( V_108 ,
struct V_1 ,
F_104 ) ;
F_105 ( V_30 -> V_3 ) ;
}
static void F_106 ( struct V_17 * V_14 )
{
struct V_1 * V_30 ;
struct V_1 * V_5 = NULL ;
struct V_6 * V_7 ;
int V_56 = - V_57 ;
bool V_134 = false , remove = true ;
F_10 ( L_19 , V_14 , V_14 -> V_19 ) ;
if ( V_14 -> V_19 && V_14 -> V_19 -> V_31 ) {
if ( ! F_80 ( V_14 -> V_19 -> V_31 ) )
return;
remove = false ;
}
F_87 ( & V_119 ) ;
F_14 (entry, &bt_6lowpan_devices, list) {
V_5 = V_1 ( V_30 -> V_3 ) ;
V_7 = F_17 ( V_5 , V_14 ) ;
if ( V_7 ) {
V_134 = F_5 ( V_5 , V_7 ) ;
V_56 = 0 ;
F_10 ( L_20 , V_5 ,
V_134 ? L_21 : L_22 , V_7 ) ;
F_10 ( L_23 , V_14 ,
F_12 ( & V_14 -> V_135 . V_136 ) ) ;
F_107 ( V_14 ) ;
break;
}
}
if ( ! V_56 && V_134 && V_5 && ! F_12 ( & V_5 -> V_10 ) ) {
F_89 ( & V_119 ) ;
F_108 ( & V_5 -> V_109 ) ;
F_75 ( V_5 -> V_3 ) ;
if ( remove ) {
F_109 ( & V_30 -> F_104 , F_104 ) ;
F_110 ( & V_30 -> F_104 ) ;
}
} else {
F_89 ( & V_119 ) ;
}
return;
}
static void F_111 ( struct V_17 * V_14 , int V_131 , int V_56 )
{
F_10 ( L_24 , V_14 , V_14 -> V_19 ,
F_112 ( V_131 ) , V_56 ) ;
}
static struct V_22 * F_113 ( struct V_17 * V_14 ,
unsigned long V_137 ,
unsigned long V_44 , int V_138 )
{
return F_114 ( V_137 + V_44 , V_34 ) ;
}
static void F_115 ( struct V_17 * V_14 )
{
struct V_22 * V_23 = V_14 -> V_80 ;
F_10 ( L_25 , V_14 , V_14 -> V_19 , V_23 ) ;
if ( ! V_23 )
return;
F_22 ( V_23 ) -> V_73 = - V_58 ;
}
static void F_116 ( struct V_17 * V_14 )
{
struct V_22 * V_23 = V_14 -> V_80 ;
F_10 ( L_25 , V_14 , V_14 -> V_19 , V_23 ) ;
if ( ! V_23 )
return;
F_22 ( V_23 ) -> V_73 = 0 ;
}
static long F_117 ( struct V_17 * V_14 )
{
return V_139 ;
}
static inline T_2 F_118 ( T_2 type )
{
if ( type == V_140 )
return V_61 ;
else
return V_60 ;
}
static int F_119 ( T_1 * V_63 , T_3 V_16 )
{
struct V_17 * V_14 ;
int V_56 ;
V_14 = F_81 () ;
if ( ! V_14 )
return - V_37 ;
V_14 -> V_133 = & V_141 ;
V_56 = F_120 ( V_14 , F_121 ( V_142 ) , 0 ,
V_63 , V_16 ) ;
F_10 ( L_26 , V_14 , V_56 ) ;
if ( V_56 < 0 )
F_107 ( V_14 ) ;
return V_56 ;
}
static int F_122 ( struct V_18 * V_19 , T_3 V_16 )
{
struct V_6 * V_7 ;
F_10 ( L_27 , V_19 , V_16 ) ;
V_7 = F_26 ( V_19 ) ;
if ( ! V_7 )
return - V_57 ;
F_10 ( L_28 , V_7 , V_7 -> V_14 ) ;
F_123 ( V_7 -> V_14 , V_57 ) ;
return 0 ;
}
static struct V_17 * F_124 ( void )
{
T_1 * V_63 = V_72 ;
struct V_17 * V_14 ;
int V_56 ;
if ( ! V_112 )
return NULL ;
V_14 = F_81 () ;
if ( ! V_14 )
return NULL ;
V_14 -> V_133 = & V_141 ;
V_14 -> V_131 = V_143 ;
V_14 -> V_124 = V_61 ;
F_125 ( & V_14 -> V_144 , V_145 ) ;
F_10 ( L_29 , V_14 , V_14 -> V_124 ) ;
V_56 = F_126 ( V_14 , V_63 , F_121 ( V_142 ) ) ;
if ( V_56 ) {
F_107 ( V_14 ) ;
F_127 ( L_30 , V_56 ) ;
return NULL ;
}
return V_14 ;
}
static int F_128 ( char * V_146 , T_1 * V_63 , T_3 * V_67 ,
struct V_18 * * V_19 )
{
struct V_110 * V_31 ;
struct V_147 * V_32 ;
T_1 * V_123 = V_72 ;
int V_148 ;
V_148 = sscanf ( V_146 , L_31 ,
& V_63 -> V_66 [ 5 ] , & V_63 -> V_66 [ 4 ] , & V_63 -> V_66 [ 3 ] ,
& V_63 -> V_66 [ 2 ] , & V_63 -> V_66 [ 1 ] , & V_63 -> V_66 [ 0 ] ,
V_67 ) ;
if ( V_148 < 7 )
return - V_37 ;
V_32 = F_129 ( V_63 , V_123 ) ;
if ( ! V_32 )
return - V_57 ;
F_130 ( V_32 ) ;
V_31 = F_131 ( V_32 , V_63 , * V_67 ) ;
F_132 ( V_32 ) ;
if ( ! V_31 )
return - V_57 ;
* V_19 = (struct V_18 * ) V_31 -> V_149 ;
F_10 ( L_32 , * V_19 , & V_31 -> V_15 , V_31 -> V_16 ) ;
return 0 ;
}
static void F_133 ( void )
{
struct V_1 * V_30 ;
struct V_6 * V_7 , * V_150 , * V_151 ;
struct V_152 V_9 ;
F_88 ( & V_9 ) ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
F_14 (peer, &entry->peers, list) {
V_151 = F_134 ( sizeof( * V_151 ) , V_34 ) ;
if ( ! V_151 )
break;
V_151 -> V_14 = V_7 -> V_14 ;
F_88 ( & V_151 -> V_8 ) ;
F_135 ( & V_151 -> V_8 , & V_9 ) ;
}
}
F_16 () ;
F_87 ( & V_119 ) ;
F_136 (peer, tmp_peer, &peers, list) {
F_123 ( V_7 -> V_14 , V_57 ) ;
F_6 ( & V_7 -> V_8 ) ;
F_7 ( V_7 , V_11 ) ;
}
F_89 ( & V_119 ) ;
}
static void F_137 ( struct V_107 * V_108 )
{
struct V_153 * V_153 = F_78 ( V_108 ,
struct V_153 , V_108 ) ;
if ( ! V_153 -> V_154 || V_112 != V_153 -> V_154 )
F_133 () ;
V_112 = V_153 -> V_154 ;
if ( V_155 ) {
F_123 ( V_155 , 0 ) ;
F_107 ( V_155 ) ;
}
V_155 = F_124 () ;
F_138 ( V_153 ) ;
}
static int F_139 ( void * V_80 , T_5 V_156 )
{
struct V_153 * V_153 ;
V_153 = F_86 ( sizeof( * V_153 ) , V_157 ) ;
if ( ! V_153 )
return - V_122 ;
V_153 -> V_154 = ! ! V_156 ;
F_109 ( & V_153 -> V_108 , F_137 ) ;
F_110 ( & V_153 -> V_108 ) ;
return 0 ;
}
static int F_140 ( void * V_80 , T_5 * V_156 )
{
* V_156 = V_112 ;
return 0 ;
}
static T_6 F_141 ( struct V_158 * V_159 ,
const char T_7 * V_160 ,
T_8 V_27 ,
T_9 * V_161 )
{
char V_146 [ 32 ] ;
T_8 V_162 = F_142 ( V_27 , sizeof( V_146 ) - 1 ) ;
int V_41 ;
T_1 V_63 ;
T_3 V_67 ;
struct V_18 * V_19 = NULL ;
if ( F_143 ( V_146 , V_160 , V_162 ) )
return - V_163 ;
V_146 [ V_162 ] = '\0' ;
if ( memcmp ( V_146 , L_33 , 8 ) == 0 ) {
V_41 = F_128 ( & V_146 [ 8 ] , & V_63 , & V_67 , & V_19 ) ;
if ( V_41 == - V_37 )
return V_41 ;
if ( V_155 ) {
F_123 ( V_155 , 0 ) ;
F_107 ( V_155 ) ;
V_155 = NULL ;
}
if ( V_19 ) {
struct V_6 * V_7 ;
if ( ! F_80 ( V_19 -> V_31 ) )
return - V_37 ;
V_7 = F_26 ( V_19 ) ;
if ( V_7 ) {
F_10 ( L_34 ) ;
return - V_164 ;
}
F_10 ( L_35 , V_19 ,
& V_19 -> V_31 -> V_15 , V_19 -> V_31 -> V_16 ,
V_67 ) ;
}
V_41 = F_119 ( & V_63 , V_67 ) ;
if ( V_41 < 0 )
return V_41 ;
return V_27 ;
}
if ( memcmp ( V_146 , L_36 , 11 ) == 0 ) {
V_41 = F_128 ( & V_146 [ 11 ] , & V_63 , & V_67 , & V_19 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_122 ( V_19 , V_67 ) ;
if ( V_41 < 0 )
return V_41 ;
return V_27 ;
}
return V_27 ;
}
static int F_144 ( struct V_165 * V_166 , void * V_167 )
{
struct V_1 * V_30 ;
struct V_6 * V_7 ;
F_87 ( & V_119 ) ;
F_145 (entry, &bt_6lowpan_devices, list) {
F_145 (peer, &entry->peers, list)
F_146 ( V_166 , L_37 ,
& V_7 -> V_14 -> V_15 , V_7 -> V_14 -> V_16 ) ;
}
F_89 ( & V_119 ) ;
return 0 ;
}
static int F_147 ( struct V_168 * V_168 , struct V_158 * V_158 )
{
return F_148 ( V_158 , F_144 , V_168 -> V_169 ) ;
}
static void F_149 ( void )
{
struct V_1 * V_30 , * V_170 , * V_171 ;
struct V_152 V_172 ;
F_88 ( & V_172 ) ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
V_171 = F_134 ( sizeof( * V_171 ) , V_34 ) ;
if ( ! V_171 )
break;
V_171 -> V_3 = V_30 -> V_3 ;
F_88 ( & V_171 -> V_8 ) ;
F_3 ( & V_171 -> V_8 , & V_172 ) ;
}
F_16 () ;
F_136 (entry, tmp, &devices, list) {
F_75 ( V_30 -> V_3 ) ;
F_10 ( L_38 ,
V_30 -> V_3 -> V_91 , V_30 -> V_3 ) ;
F_105 ( V_30 -> V_3 ) ;
F_138 ( V_30 ) ;
}
}
static int F_150 ( struct V_173 * V_174 ,
unsigned long V_175 , void * V_167 )
{
struct V_2 * V_3 = F_151 ( V_167 ) ;
struct V_1 * V_30 ;
if ( V_3 -> type != V_43 )
return V_176 ;
switch ( V_175 ) {
case V_177 :
F_87 ( & V_119 ) ;
F_145 (entry, &bt_6lowpan_devices, list) {
if ( V_30 -> V_3 == V_3 ) {
F_10 ( L_39 ,
V_3 -> V_91 , V_3 ) ;
F_152 ( & V_30 -> V_8 ) ;
break;
}
}
F_89 ( & V_119 ) ;
break;
}
return V_176 ;
}
static int T_10 F_153 ( void )
{
V_178 = F_154 ( L_40 , 0644 ,
V_179 , NULL ,
& V_180 ) ;
V_181 = F_154 ( L_41 , 0644 ,
V_179 , NULL ,
& V_182 ) ;
return F_155 ( & V_183 ) ;
}
static void T_11 F_156 ( void )
{
F_157 ( V_178 ) ;
F_157 ( V_181 ) ;
if ( V_155 ) {
F_123 ( V_155 , 0 ) ;
F_107 ( V_155 ) ;
}
F_149 () ;
F_158 ( & V_183 ) ;
}
