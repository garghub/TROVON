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
struct V_6 * V_7 )
{
const T_3 * V_36 ;
V_36 = V_7 -> V_37 ;
return F_32 ( V_23 , V_3 , V_3 -> V_38 , V_36 ) ;
}
static int F_33 ( struct V_22 * V_23 , struct V_2 * V_5 ,
struct V_6 * V_7 )
{
struct V_22 * V_39 ;
int V_40 ;
if ( ! F_34 ( V_5 ) )
goto V_41;
if ( V_5 -> type != V_42 || ! V_23 -> V_43 )
goto V_41;
F_35 ( V_23 ) ;
V_23 = F_36 ( V_23 , V_34 ) ;
if ( ! V_23 )
goto V_41;
if ( F_37 ( * F_38 ( V_23 ) ) ) {
F_39 ( V_23 , 1 ) ;
V_39 = F_40 ( V_23 , V_44 - 1 ,
F_41 ( V_23 ) , V_34 ) ;
if ( ! V_39 )
goto V_41;
V_39 -> V_45 = F_42 ( V_46 ) ;
V_39 -> V_47 = V_48 ;
V_39 -> V_5 = V_5 ;
F_43 ( V_39 , sizeof( struct V_49 ) ) ;
if ( F_28 ( V_39 , V_5 ) != V_50 ) {
F_44 ( V_39 ) ;
goto V_41;
}
V_5 -> V_51 . V_52 += V_23 -> V_43 ;
V_5 -> V_51 . V_53 ++ ;
F_45 ( V_39 ) ;
F_45 ( V_23 ) ;
} else if ( F_46 ( * F_38 ( V_23 ) ) ) {
V_39 = F_47 ( V_23 , V_34 ) ;
if ( ! V_39 )
goto V_41;
V_39 -> V_5 = V_5 ;
V_40 = F_31 ( V_39 , V_5 , V_7 ) ;
if ( V_40 < 0 ) {
F_10 ( L_7 , V_40 ) ;
F_44 ( V_39 ) ;
goto V_41;
}
V_39 -> V_45 = F_42 ( V_46 ) ;
V_39 -> V_47 = V_48 ;
if ( F_28 ( V_39 , V_5 )
!= V_50 ) {
F_44 ( V_39 ) ;
goto V_41;
}
V_5 -> V_51 . V_52 += V_23 -> V_43 ;
V_5 -> V_51 . V_53 ++ ;
F_45 ( V_39 ) ;
F_45 ( V_23 ) ;
} else {
F_10 ( L_8 ) ;
goto V_41;
}
return V_50 ;
V_41:
V_5 -> V_51 . V_54 ++ ;
return V_35 ;
}
static int F_48 ( struct V_17 * V_14 , struct V_22 * V_23 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
int V_55 ;
V_7 = F_26 ( V_14 -> V_19 ) ;
if ( ! V_7 )
return - V_56 ;
V_5 = F_27 ( V_14 -> V_19 ) ;
if ( ! V_5 || ! V_5 -> V_3 )
return - V_56 ;
V_55 = F_33 ( V_23 , V_5 -> V_3 , V_7 ) ;
if ( V_55 ) {
F_10 ( L_9 , V_55 ) ;
V_55 = - V_57 ;
}
return V_55 ;
}
static int F_49 ( struct V_22 * V_23 , struct V_2 * V_3 ,
T_1 * V_29 , T_3 * V_58 )
{
struct V_20 V_59 ;
struct V_49 * V_60 ;
struct V_1 * V_5 ;
struct V_6 * V_7 ;
T_3 * V_21 ;
int V_55 , V_61 = 0 ;
V_60 = F_50 ( V_23 ) ;
V_5 = V_1 ( V_3 ) ;
memcpy ( & V_59 , & V_60 -> V_21 , sizeof( V_59 ) ) ;
if ( F_51 ( & V_59 ) ) {
F_22 ( V_23 ) -> V_14 = NULL ;
V_21 = NULL ;
} else {
F_10 ( L_10 , & V_59 ) ;
V_7 = F_19 ( V_5 , & V_59 , V_23 ) ;
if ( ! V_7 ) {
F_10 ( L_11 ) ;
return - V_56 ;
}
V_21 = V_7 -> V_37 ;
* V_29 = V_7 -> V_14 -> V_15 ;
* V_58 = V_7 -> V_14 -> V_16 ;
F_22 ( V_23 ) -> V_14 = V_7 -> V_14 ;
V_61 = 1 ;
}
F_52 ( V_23 , V_3 , V_21 , V_5 -> V_3 -> V_38 ) ;
V_55 = F_53 ( V_23 , V_3 , V_46 , NULL , NULL , 0 ) ;
if ( V_55 < 0 )
return V_55 ;
return V_61 ;
}
static int F_54 ( struct V_22 * V_23 , struct V_2 * V_3 ,
unsigned short type , const void * V_62 ,
const void * V_63 , unsigned int V_43 )
{
if ( type != V_46 )
return - V_64 ;
return 0 ;
}
static int F_55 ( struct V_17 * V_14 , struct V_22 * V_23 ,
struct V_2 * V_3 )
{
struct V_65 V_66 ;
struct V_67 V_68 ;
int V_55 ;
V_14 -> V_69 = V_23 ;
V_68 . V_70 = V_23 -> V_69 ;
V_68 . V_71 = V_23 -> V_43 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
F_56 ( & V_66 . V_72 , V_73 | V_74 , & V_68 , 1 , V_23 -> V_43 ) ;
V_55 = F_57 ( V_14 , & V_66 , V_23 -> V_43 ) ;
if ( V_55 > 0 ) {
V_3 -> V_51 . V_75 += V_55 ;
V_3 -> V_51 . V_76 ++ ;
return 0 ;
}
if ( V_55 < 0 )
V_3 -> V_51 . V_77 ++ ;
return V_55 ;
}
static int F_58 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
struct V_22 * V_39 ;
struct V_1 * V_30 ;
int V_55 = 0 ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
struct V_6 * V_78 ;
struct V_1 * V_5 ;
if ( V_30 -> V_3 != V_3 )
continue;
V_5 = V_1 ( V_30 -> V_3 ) ;
F_14 (pentry, &dev->peers, list) {
int V_40 ;
V_39 = F_47 ( V_23 , V_34 ) ;
F_10 ( L_12 ,
V_3 -> V_79 ,
& V_78 -> V_14 -> V_15 , V_78 -> V_14 -> V_16 ,
& V_78 -> V_29 , V_78 -> V_14 ) ;
V_40 = F_55 ( V_78 -> V_14 , V_39 , V_3 ) ;
if ( V_40 < 0 )
V_55 = V_40 ;
F_44 ( V_39 ) ;
}
}
F_16 () ;
return V_55 ;
}
static T_4 F_59 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
int V_55 = 0 ;
T_1 V_80 ;
T_3 V_81 ;
V_23 = F_60 ( V_23 , V_34 ) ;
if ( ! V_23 )
return V_82 ;
V_55 = F_49 ( V_23 , V_3 , & V_80 , & V_81 ) ;
if ( V_55 < 0 ) {
F_44 ( V_23 ) ;
return V_82 ;
}
if ( V_55 ) {
if ( F_22 ( V_23 ) -> V_14 ) {
F_10 ( L_12 ,
V_3 -> V_79 , & V_80 , V_81 ,
& F_22 ( V_23 ) -> V_80 , F_22 ( V_23 ) -> V_14 ) ;
V_55 = F_55 ( F_22 ( V_23 ) -> V_14 , V_23 , V_3 ) ;
} else {
V_55 = - V_56 ;
}
} else {
V_55 = F_58 ( V_23 , V_3 ) ;
}
F_61 ( V_23 ) ;
if ( V_55 )
F_10 ( L_13 , V_55 ) ;
return V_55 < 0 ? V_82 : V_55 ;
}
static int F_62 ( struct V_2 * V_5 )
{
F_63 ( V_5 ) ;
return 0 ;
}
static void F_64 ( struct V_2 * V_5 )
{
V_5 -> V_83 = 0 ;
V_5 -> V_84 = 0 ;
V_5 -> V_85 = V_86 | V_87 ;
V_5 -> V_88 = 0 ;
V_5 -> V_89 = V_90 ;
V_5 -> V_91 = & V_91 ;
V_5 -> V_92 = & V_92 ;
V_5 -> V_93 = true ;
}
static void F_65 ( struct V_2 * V_3 )
{
int V_55 ;
F_66 () ;
V_55 = F_67 ( V_3 ) ;
if ( V_55 < 0 )
F_68 ( L_14 , V_3 -> V_79 , V_55 ) ;
F_69 () ;
}
static void F_70 ( struct V_2 * V_3 )
{
F_66 () ;
F_71 ( V_3 ) ;
F_69 () ;
}
static void F_72 ( struct V_94 * V_95 )
{
struct V_1 * V_5 = F_73 ( V_95 , struct V_1 ,
V_96 . V_95 ) ;
F_74 ( V_5 -> V_3 ) ;
}
static bool F_75 ( struct V_97 * V_31 )
{
if ( V_31 -> type != V_98 )
return false ;
if ( ! V_99 )
return false ;
return true ;
}
static struct V_17 * F_76 ( void )
{
struct V_17 * V_14 ;
V_14 = F_77 () ;
if ( ! V_14 )
return NULL ;
F_78 ( V_14 ) ;
V_14 -> V_100 = V_101 ;
V_14 -> V_102 = V_103 ;
V_14 -> V_104 = 1280 ;
return V_14 ;
}
static struct V_17 * F_79 ( struct V_17 * V_14 ,
struct V_1 * V_5 ,
bool V_105 )
{
struct V_6 * V_7 ;
V_7 = F_80 ( sizeof( * V_7 ) , V_34 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_14 = V_14 ;
memset ( & V_7 -> V_29 , 0 , sizeof( struct V_20 ) ) ;
F_81 ( ( void * ) V_7 -> V_37 , & V_14 -> V_15 ) ;
F_82 ( & V_7 -> V_29 , V_7 -> V_37 ) ;
F_83 ( & V_106 ) ;
F_84 ( & V_7 -> V_8 ) ;
F_2 ( V_5 , V_7 ) ;
F_85 ( & V_106 ) ;
if ( V_105 )
F_86 ( & V_5 -> V_96 , F_72 ) ;
F_87 ( & V_5 -> V_96 , F_88 ( 100 ) ) ;
return V_7 -> V_14 ;
}
static int F_89 ( struct V_17 * V_14 , struct V_1 * * V_5 )
{
struct V_2 * V_3 ;
int V_55 = 0 ;
V_3 = F_90 ( F_91 ( sizeof( struct V_1 ) ) ,
V_107 , V_108 ,
F_64 ) ;
if ( ! V_3 )
return - V_109 ;
V_3 -> V_110 = V_111 ;
F_81 ( ( void * ) V_3 -> V_38 , & V_14 -> V_112 ) ;
V_3 -> V_91 = & V_91 ;
F_92 ( V_3 , & V_14 -> V_19 -> V_31 -> V_32 -> V_5 ) ;
F_93 ( V_3 , & V_113 ) ;
* V_5 = V_1 ( V_3 ) ;
( * V_5 ) -> V_3 = V_3 ;
( * V_5 ) -> V_32 = V_14 -> V_19 -> V_31 -> V_32 ;
F_84 ( & ( * V_5 ) -> V_9 ) ;
F_83 ( & V_106 ) ;
F_84 ( & ( * V_5 ) -> V_8 ) ;
F_3 ( & ( * V_5 ) -> V_8 , & V_114 ) ;
F_85 ( & V_106 ) ;
V_55 = F_94 ( V_3 , V_115 ) ;
if ( V_55 < 0 ) {
F_68 ( L_15 , V_55 ) ;
F_83 ( & V_106 ) ;
F_6 ( & ( * V_5 ) -> V_8 ) ;
F_85 ( & V_106 ) ;
F_95 ( V_3 ) ;
goto V_116;
}
F_10 ( L_16 ,
V_3 -> V_117 , & V_14 -> V_15 , V_14 -> V_16 ,
& V_14 -> V_112 , V_14 -> V_118 ) ;
F_96 ( V_119 , & V_3 -> V_120 ) ;
return 0 ;
V_116:
return V_55 ;
}
static inline void F_97 ( struct V_17 * V_14 )
{
struct V_1 * V_5 ;
bool V_105 = false ;
V_5 = F_27 ( V_14 -> V_19 ) ;
F_10 ( L_17 , V_14 , V_14 -> V_19 , V_5 ) ;
if ( ! V_5 ) {
if ( F_89 ( V_14 , & V_5 ) < 0 ) {
F_98 ( V_14 , - V_56 ) ;
return;
}
V_105 = true ;
}
if ( ! F_99 ( V_12 ) )
return;
F_79 ( V_14 , V_5 , V_105 ) ;
F_65 ( V_5 -> V_3 ) ;
}
static inline struct V_17 * F_100 ( struct V_17 * V_121 )
{
struct V_17 * V_14 ;
V_14 = F_76 () ;
if ( ! V_14 )
return NULL ;
V_14 -> V_122 = V_121 -> V_122 ;
F_10 ( L_18 , V_14 , V_121 ) ;
return V_14 ;
}
static void F_101 ( struct V_94 * V_95 )
{
struct V_1 * V_30 = F_73 ( V_95 ,
struct V_1 ,
F_101 ) ;
F_102 ( V_30 -> V_3 ) ;
}
static void F_103 ( struct V_17 * V_14 )
{
struct V_1 * V_30 ;
struct V_1 * V_5 = NULL ;
struct V_6 * V_7 ;
int V_55 = - V_56 ;
bool V_123 = false , remove = true ;
F_10 ( L_19 , V_14 , V_14 -> V_19 ) ;
if ( V_14 -> V_19 && V_14 -> V_19 -> V_31 ) {
if ( ! F_75 ( V_14 -> V_19 -> V_31 ) )
return;
remove = false ;
}
F_83 ( & V_106 ) ;
F_14 (entry, &bt_6lowpan_devices, list) {
V_5 = V_1 ( V_30 -> V_3 ) ;
V_7 = F_17 ( V_5 , V_14 ) ;
if ( V_7 ) {
V_123 = F_5 ( V_5 , V_7 ) ;
V_55 = 0 ;
F_10 ( L_20 , V_5 ,
V_123 ? L_21 : L_22 , V_7 ) ;
F_10 ( L_23 , V_14 ,
F_104 ( & V_14 -> V_124 ) ) ;
F_105 ( V_14 ) ;
break;
}
}
if ( ! V_55 && V_123 && V_5 && ! F_12 ( & V_5 -> V_10 ) ) {
F_85 ( & V_106 ) ;
F_106 ( & V_5 -> V_96 ) ;
F_70 ( V_5 -> V_3 ) ;
if ( remove ) {
F_107 ( & V_30 -> F_101 , F_101 ) ;
F_108 ( & V_30 -> F_101 ) ;
}
} else {
F_85 ( & V_106 ) ;
}
return;
}
static void F_109 ( struct V_17 * V_14 , int V_120 , int V_55 )
{
F_10 ( L_24 , V_14 , V_14 -> V_19 ,
F_110 ( V_120 ) , V_55 ) ;
}
static struct V_22 * F_111 ( struct V_17 * V_14 ,
unsigned long V_125 ,
unsigned long V_43 , int V_126 )
{
return F_112 ( V_125 + V_43 , V_34 ) ;
}
static void F_113 ( struct V_17 * V_14 )
{
struct V_1 * V_5 ;
F_10 ( L_25 , V_14 ) ;
V_5 = F_27 ( V_14 -> V_19 ) ;
if ( ! V_5 || ! V_5 -> V_3 )
return;
F_114 ( V_5 -> V_3 ) ;
}
static void F_115 ( struct V_17 * V_14 )
{
struct V_1 * V_5 ;
F_10 ( L_26 , V_14 ) ;
V_5 = F_27 ( V_14 -> V_19 ) ;
if ( ! V_5 || ! V_5 -> V_3 )
return;
F_116 ( V_5 -> V_3 ) ;
}
static long F_117 ( struct V_17 * V_14 )
{
return V_127 ;
}
static inline T_2 F_118 ( T_2 type )
{
if ( type == V_128 )
return V_129 ;
else
return V_130 ;
}
static int F_119 ( T_1 * V_80 , T_3 V_16 )
{
struct V_17 * V_14 ;
int V_55 ;
V_14 = F_76 () ;
if ( ! V_14 )
return - V_64 ;
V_14 -> V_122 = & V_131 ;
V_55 = F_120 ( V_14 , F_121 ( V_132 ) , 0 ,
V_80 , V_16 ) ;
F_10 ( L_27 , V_14 , V_55 ) ;
if ( V_55 < 0 )
F_105 ( V_14 ) ;
return V_55 ;
}
static int F_122 ( struct V_18 * V_19 , T_3 V_16 )
{
struct V_6 * V_7 ;
F_10 ( L_28 , V_19 , V_16 ) ;
V_7 = F_26 ( V_19 ) ;
if ( ! V_7 )
return - V_56 ;
F_10 ( L_29 , V_7 , V_7 -> V_14 ) ;
F_123 ( V_7 -> V_14 , V_56 ) ;
return 0 ;
}
static struct V_17 * F_124 ( void )
{
T_1 * V_80 = V_133 ;
struct V_17 * V_14 ;
int V_55 ;
if ( ! V_99 )
return NULL ;
V_14 = F_76 () ;
if ( ! V_14 )
return NULL ;
V_14 -> V_122 = & V_131 ;
V_14 -> V_120 = V_134 ;
V_14 -> V_118 = V_129 ;
F_125 ( & V_14 -> V_135 , V_136 ) ;
F_10 ( L_30 , V_14 , V_14 -> V_118 ) ;
V_55 = F_126 ( V_14 , V_80 , F_121 ( V_132 ) ) ;
if ( V_55 ) {
F_105 ( V_14 ) ;
F_127 ( L_31 , V_55 ) ;
return NULL ;
}
return V_14 ;
}
static int F_128 ( char * V_137 , T_1 * V_80 , T_3 * V_81 ,
struct V_18 * * V_19 )
{
struct V_97 * V_31 ;
struct V_138 * V_32 ;
int V_139 ;
V_139 = sscanf ( V_137 , L_32 ,
& V_80 -> V_140 [ 5 ] , & V_80 -> V_140 [ 4 ] , & V_80 -> V_140 [ 3 ] ,
& V_80 -> V_140 [ 2 ] , & V_80 -> V_140 [ 1 ] , & V_80 -> V_140 [ 0 ] ,
V_81 ) ;
if ( V_139 < 7 )
return - V_64 ;
V_32 = F_129 ( V_80 , V_133 , V_129 ) ;
if ( ! V_32 )
return - V_56 ;
F_130 ( V_32 ) ;
V_31 = F_131 ( V_32 , V_80 , * V_81 ) ;
F_132 ( V_32 ) ;
if ( ! V_31 )
return - V_56 ;
* V_19 = (struct V_18 * ) V_31 -> V_141 ;
F_10 ( L_33 , * V_19 , & V_31 -> V_15 , V_31 -> V_16 ) ;
return 0 ;
}
static void F_133 ( void )
{
struct V_1 * V_30 ;
struct V_6 * V_7 , * V_142 , * V_143 ;
struct V_144 V_9 ;
F_84 ( & V_9 ) ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
F_14 (peer, &entry->peers, list) {
V_143 = F_134 ( sizeof( * V_143 ) , V_34 ) ;
if ( ! V_143 )
break;
V_143 -> V_14 = V_7 -> V_14 ;
F_84 ( & V_143 -> V_8 ) ;
F_135 ( & V_143 -> V_8 , & V_9 ) ;
}
}
F_16 () ;
F_83 ( & V_106 ) ;
F_136 (peer, tmp_peer, &peers, list) {
F_123 ( V_7 -> V_14 , V_56 ) ;
F_6 ( & V_7 -> V_8 ) ;
F_7 ( V_7 , V_11 ) ;
}
F_85 ( & V_106 ) ;
}
static void F_137 ( struct V_94 * V_95 )
{
struct V_145 * V_145 = F_73 ( V_95 ,
struct V_145 , V_95 ) ;
if ( ! V_145 -> V_146 || V_99 != V_145 -> V_146 )
F_133 () ;
V_99 = V_145 -> V_146 ;
if ( V_147 ) {
F_123 ( V_147 , 0 ) ;
F_105 ( V_147 ) ;
}
V_147 = F_124 () ;
F_138 ( V_145 ) ;
}
static int F_139 ( void * V_69 , T_5 V_148 )
{
struct V_145 * V_145 ;
V_145 = F_80 ( sizeof( * V_145 ) , V_149 ) ;
if ( ! V_145 )
return - V_109 ;
V_145 -> V_146 = ! ! V_148 ;
F_107 ( & V_145 -> V_95 , F_137 ) ;
F_108 ( & V_145 -> V_95 ) ;
return 0 ;
}
static int F_140 ( void * V_69 , T_5 * V_148 )
{
* V_148 = V_99 ;
return 0 ;
}
static T_6 F_141 ( struct V_150 * V_151 ,
const char T_7 * V_152 ,
T_8 V_27 ,
T_9 * V_153 )
{
char V_137 [ 32 ] ;
T_8 V_154 = F_142 ( V_27 , sizeof( V_137 ) - 1 ) ;
int V_40 ;
T_1 V_80 ;
T_3 V_81 ;
struct V_18 * V_19 = NULL ;
if ( F_143 ( V_137 , V_152 , V_154 ) )
return - V_155 ;
V_137 [ V_154 ] = '\0' ;
if ( memcmp ( V_137 , L_34 , 8 ) == 0 ) {
V_40 = F_128 ( & V_137 [ 8 ] , & V_80 , & V_81 , & V_19 ) ;
if ( V_40 == - V_64 )
return V_40 ;
if ( V_147 ) {
F_123 ( V_147 , 0 ) ;
F_105 ( V_147 ) ;
V_147 = NULL ;
}
if ( V_19 ) {
struct V_6 * V_7 ;
if ( ! F_75 ( V_19 -> V_31 ) )
return - V_64 ;
V_7 = F_26 ( V_19 ) ;
if ( V_7 ) {
F_10 ( L_35 ) ;
return - V_156 ;
}
F_10 ( L_36 , V_19 ,
& V_19 -> V_31 -> V_15 , V_19 -> V_31 -> V_16 ,
V_81 ) ;
}
V_40 = F_119 ( & V_80 , V_81 ) ;
if ( V_40 < 0 )
return V_40 ;
return V_27 ;
}
if ( memcmp ( V_137 , L_37 , 11 ) == 0 ) {
V_40 = F_128 ( & V_137 [ 11 ] , & V_80 , & V_81 , & V_19 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_122 ( V_19 , V_81 ) ;
if ( V_40 < 0 )
return V_40 ;
return V_27 ;
}
return V_27 ;
}
static int F_144 ( struct V_157 * V_158 , void * V_159 )
{
struct V_1 * V_30 ;
struct V_6 * V_7 ;
F_83 ( & V_106 ) ;
F_145 (entry, &bt_6lowpan_devices, list) {
F_145 (peer, &entry->peers, list)
F_146 ( V_158 , L_38 ,
& V_7 -> V_14 -> V_15 , V_7 -> V_14 -> V_16 ) ;
}
F_85 ( & V_106 ) ;
return 0 ;
}
static int F_147 ( struct V_160 * V_160 , struct V_150 * V_150 )
{
return F_148 ( V_150 , F_144 , V_160 -> V_161 ) ;
}
static void F_149 ( void )
{
struct V_1 * V_30 , * V_162 , * V_163 ;
struct V_144 V_164 ;
F_84 ( & V_164 ) ;
F_13 () ;
F_14 (entry, &bt_6lowpan_devices, list) {
V_163 = F_134 ( sizeof( * V_163 ) , V_34 ) ;
if ( ! V_163 )
break;
V_163 -> V_3 = V_30 -> V_3 ;
F_84 ( & V_163 -> V_8 ) ;
F_3 ( & V_163 -> V_8 , & V_164 ) ;
}
F_16 () ;
F_136 (entry, tmp, &devices, list) {
F_70 ( V_30 -> V_3 ) ;
F_10 ( L_39 ,
V_30 -> V_3 -> V_79 , V_30 -> V_3 ) ;
F_102 ( V_30 -> V_3 ) ;
F_138 ( V_30 ) ;
}
}
static int F_150 ( struct V_165 * V_166 ,
unsigned long V_167 , void * V_159 )
{
struct V_2 * V_3 = F_151 ( V_159 ) ;
struct V_1 * V_30 ;
if ( V_3 -> type != V_42 )
return V_168 ;
switch ( V_167 ) {
case V_169 :
F_83 ( & V_106 ) ;
F_145 (entry, &bt_6lowpan_devices, list) {
if ( V_30 -> V_3 == V_3 ) {
F_10 ( L_40 ,
V_3 -> V_79 , V_3 ) ;
F_152 ( & V_30 -> V_8 ) ;
break;
}
}
F_85 ( & V_106 ) ;
break;
}
return V_168 ;
}
static int T_10 F_153 ( void )
{
V_170 = F_154 ( L_41 , 0644 ,
V_171 , NULL ,
& V_172 ) ;
V_173 = F_154 ( L_42 , 0644 ,
V_171 , NULL ,
& V_174 ) ;
return F_155 ( & V_175 ) ;
}
static void T_11 F_156 ( void )
{
F_157 ( V_170 ) ;
F_157 ( V_173 ) ;
if ( V_147 ) {
F_123 ( V_147 , 0 ) ;
F_105 ( V_147 ) ;
}
F_149 () ;
F_158 ( & V_175 ) ;
}
