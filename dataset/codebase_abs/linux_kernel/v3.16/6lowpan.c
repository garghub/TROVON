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
if ( F_7 ( & V_4 -> V_9 ) ) {
F_8 ( L_1 ) ;
return true ;
}
return false ;
}
static inline struct V_5 * F_9 ( struct V_1 * V_4 ,
T_1 * V_10 , T_2 type )
{
struct V_5 * V_6 , * V_11 ;
F_8 ( L_2 , F_10 ( & V_4 -> V_9 ) ,
V_10 , type ) ;
F_11 (peer, tmp, &dev->peers, list) {
F_8 ( L_3 ,
& V_6 -> V_12 -> V_13 -> V_14 , V_6 -> V_12 -> V_13 -> V_15 ) ;
if ( F_12 ( & V_6 -> V_12 -> V_13 -> V_14 , V_10 ) )
continue;
if ( type == V_6 -> V_12 -> V_13 -> V_15 )
return V_6 ;
}
return NULL ;
}
static inline struct V_5 * F_13 ( struct V_1 * V_4 ,
struct V_16 * V_12 )
{
struct V_5 * V_6 , * V_11 ;
F_11 (peer, tmp, &dev->peers, list) {
if ( V_6 -> V_12 == V_12 )
return V_6 ;
}
return NULL ;
}
static struct V_5 * F_14 ( struct V_16 * V_12 )
{
struct V_1 * V_17 , * V_11 ;
struct V_5 * V_6 = NULL ;
unsigned long V_18 ;
F_15 ( & V_19 , V_18 ) ;
F_11 (entry, tmp, &bt_6lowpan_devices, list) {
V_6 = F_13 ( V_17 , V_12 ) ;
if ( V_6 )
break;
}
F_16 ( & V_19 , V_18 ) ;
return V_6 ;
}
static struct V_1 * F_17 ( struct V_16 * V_12 )
{
struct V_1 * V_17 , * V_11 ;
struct V_1 * V_4 = NULL ;
unsigned long V_18 ;
F_15 ( & V_19 , V_18 ) ;
F_11 (entry, tmp, &bt_6lowpan_devices, list) {
if ( V_12 -> V_13 -> V_20 == V_17 -> V_20 ) {
V_4 = V_17 ;
break;
}
}
F_16 ( & V_19 , V_18 ) ;
return V_4 ;
}
static int F_18 ( struct V_21 * V_22 , struct V_2 * V_4 )
{
struct V_21 * V_23 ;
int V_24 ;
V_23 = F_19 ( V_22 , V_25 ) ;
if ( ! V_23 )
return - V_26 ;
V_24 = F_20 ( V_23 ) ;
F_8 ( L_4 , V_24 ) ;
if ( V_24 < 0 )
return V_27 ;
return V_24 ;
}
static int F_21 ( struct V_21 * V_22 , struct V_2 * V_3 ,
struct V_16 * V_12 )
{
const T_3 * V_28 , * V_29 ;
T_3 V_30 , V_31 ;
struct V_1 * V_4 ;
struct V_5 * V_6 ;
unsigned long V_18 ;
V_4 = V_1 ( V_3 ) ;
F_15 ( & V_19 , V_18 ) ;
V_6 = F_13 ( V_4 , V_12 ) ;
F_16 ( & V_19 , V_18 ) ;
if ( ! V_6 )
goto V_32;
V_28 = V_6 -> V_33 ;
V_29 = V_4 -> V_3 -> V_34 ;
if ( V_22 -> V_35 < 2 )
goto V_32;
if ( F_22 ( V_22 , & V_30 ) )
goto V_32;
if ( F_22 ( V_22 , & V_31 ) )
goto V_32;
return F_23 ( V_22 , V_3 ,
V_28 , V_36 , V_37 ,
V_29 , V_36 , V_37 ,
V_30 , V_31 , F_18 ) ;
V_32:
F_24 ( V_22 ) ;
return - V_38 ;
}
static int F_25 ( struct V_21 * V_22 , struct V_2 * V_4 ,
struct V_16 * V_12 )
{
struct V_21 * V_39 ;
int V_24 ;
if ( ! F_26 ( V_4 ) )
goto V_32;
if ( V_4 -> type != V_40 )
goto V_32;
if ( V_22 -> V_41 [ 0 ] == V_42 ) {
V_39 = F_27 ( V_22 , V_43 - 1 ,
F_28 ( V_22 ) , V_25 ) ;
if ( ! V_39 )
goto V_32;
V_39 -> V_44 = F_29 ( V_45 ) ;
V_39 -> V_46 = V_47 ;
F_30 ( V_39 ) ;
F_31 ( V_39 , sizeof( struct V_48 ) ) ;
if ( F_18 ( V_39 , V_4 ) != V_49 ) {
F_24 ( V_39 ) ;
goto V_32;
}
V_4 -> V_50 . V_51 += V_22 -> V_35 ;
V_4 -> V_50 . V_52 ++ ;
F_24 ( V_39 ) ;
F_24 ( V_22 ) ;
} else {
switch ( V_22 -> V_41 [ 0 ] & 0xe0 ) {
case V_53 :
V_39 = F_32 ( V_22 , V_25 ) ;
if ( ! V_39 )
goto V_32;
V_24 = F_21 ( V_39 , V_4 , V_12 ) ;
if ( V_24 != V_49 )
goto V_32;
V_4 -> V_50 . V_51 += V_22 -> V_35 ;
V_4 -> V_50 . V_52 ++ ;
F_24 ( V_22 ) ;
break;
default:
break;
}
}
return V_49 ;
V_32:
F_24 ( V_22 ) ;
return V_27 ;
}
int F_33 ( struct V_16 * V_12 , struct V_21 * V_22 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 ;
int V_54 ;
V_6 = F_14 ( V_12 ) ;
if ( ! V_6 )
return - V_55 ;
V_4 = F_17 ( V_12 ) ;
if ( ! V_4 || ! V_4 -> V_3 )
return - V_55 ;
V_54 = F_25 ( V_22 , V_4 -> V_3 , V_12 ) ;
F_8 ( L_5 , V_54 ) ;
return V_54 ;
}
static inline int F_34 ( void * V_56 , int V_35 , int V_57 , int V_58 ,
struct V_21 * V_22 , struct V_2 * V_4 )
{
struct V_21 * * V_59 ;
int V_60 = 0 ;
memcpy ( F_35 ( V_22 , V_57 ) , V_56 , V_57 ) ;
V_60 += V_57 ;
V_56 += V_57 ;
V_35 -= V_57 ;
V_4 -> V_50 . V_61 += V_57 ;
V_4 -> V_50 . V_62 ++ ;
F_36 ( V_63 , L_6 , V_22 -> V_41 , V_22 -> V_35 ) ;
V_59 = & F_37 ( V_22 ) -> V_64 ;
while ( V_35 > 0 ) {
struct V_21 * V_11 ;
V_57 = F_38 (unsigned int, mtu, len) ;
V_11 = F_39 ( V_57 , V_25 ) ;
if ( ! V_11 )
return - V_26 ;
* V_59 = V_11 ;
memcpy ( F_35 ( * V_59 , V_57 ) , V_56 , V_57 ) ;
F_36 ( V_63 , L_7 ,
( * V_59 ) -> V_41 , V_57 ) ;
( * V_59 ) -> V_65 = V_22 -> V_65 ;
V_60 += V_57 ;
V_56 += V_57 ;
V_35 -= V_57 ;
V_22 -> V_35 += ( * V_59 ) -> V_35 ;
V_22 -> V_66 += ( * V_59 ) -> V_35 ;
V_59 = & ( * V_59 ) -> V_67 ;
V_4 -> V_50 . V_61 += V_57 ;
V_4 -> V_50 . V_62 ++ ;
}
return V_60 ;
}
static struct V_21 * F_40 ( struct V_16 * V_12 , void * V_56 ,
T_4 V_35 , T_5 V_65 ,
struct V_2 * V_4 )
{
struct V_21 * V_22 ;
int V_54 , V_57 ;
struct V_68 * V_69 ;
if ( V_12 -> V_58 > ( V_70 + V_71 ) )
V_12 -> V_58 = V_70 + V_71 ;
V_57 = F_38 (unsigned int, (conn->mtu - L2CAP_HDR_SIZE), len) ;
F_8 ( L_8 , V_12 , V_35 , V_12 -> V_58 , V_57 ) ;
V_22 = F_39 ( V_57 + V_71 , V_25 ) ;
if ( ! V_22 )
return F_41 ( - V_26 ) ;
V_22 -> V_65 = V_65 ;
V_69 = (struct V_68 * ) F_35 ( V_22 , V_71 ) ;
V_69 -> V_72 = F_42 ( V_73 ) ;
V_69 -> V_35 = F_42 ( V_35 ) ;
V_54 = F_34 ( V_56 , V_35 , V_57 , V_12 -> V_58 , V_22 , V_4 ) ;
if ( F_43 ( V_54 < 0 ) ) {
F_24 ( V_22 ) ;
F_8 ( L_9 , V_54 ) ;
return F_41 ( V_54 ) ;
}
return V_22 ;
}
static int F_44 ( struct V_16 * V_12 ,
void * V_56 , T_4 V_35 , T_5 V_65 ,
struct V_2 * V_4 )
{
struct V_21 * V_22 ;
V_22 = F_40 ( V_12 , V_56 , V_35 , V_65 , V_4 ) ;
if ( F_45 ( V_22 ) )
return - V_38 ;
F_8 ( L_10 , V_12 , V_22 , V_22 -> V_35 ,
V_22 -> V_65 ) ;
F_46 ( V_12 -> V_74 , V_22 , V_75 ) ;
return 0 ;
}
static T_3 F_47 ( T_3 V_76 )
{
if ( V_76 & 0x02 )
return V_77 ;
return V_78 ;
}
static void F_48 ( struct V_79 * V_80 , T_1 * V_81 )
{
T_3 * V_82 = V_80 -> V_83 + 8 ;
V_81 -> V_84 [ 0 ] = V_82 [ 7 ] ;
V_81 -> V_84 [ 1 ] = V_82 [ 6 ] ;
V_81 -> V_84 [ 2 ] = V_82 [ 5 ] ;
V_81 -> V_84 [ 3 ] = V_82 [ 2 ] ;
V_81 -> V_84 [ 4 ] = V_82 [ 1 ] ;
V_81 -> V_84 [ 5 ] = V_82 [ 0 ] ;
}
static void F_49 ( struct V_79 * V_80 ,
T_1 * V_81 , T_3 * V_85 )
{
F_48 ( V_80 , V_81 ) ;
V_81 -> V_84 [ 5 ] ^= 0x02 ;
* V_85 = F_47 ( V_81 -> V_84 [ 5 ] ) ;
}
static int F_50 ( struct V_21 * V_22 , struct V_2 * V_3 ,
unsigned short type , const void * V_86 ,
const void * V_87 , unsigned int V_35 )
{
struct V_48 * V_88 ;
struct V_1 * V_4 ;
struct V_5 * V_6 ;
T_1 V_81 , * V_89 = V_90 ;
T_3 * V_28 , * V_29 = V_89 -> V_84 ;
T_3 V_85 ;
if ( type != V_45 )
return - V_38 ;
V_88 = F_51 ( V_22 ) ;
V_4 = V_1 ( V_3 ) ;
if ( F_52 ( & V_88 -> V_29 ) ) {
memcpy ( & F_53 ( V_22 ) -> V_81 , & V_88 -> V_29 ,
sizeof( struct V_79 ) ) ;
F_53 ( V_22 ) -> V_12 = NULL ;
} else {
unsigned long V_18 ;
F_49 ( & V_88 -> V_29 , & V_81 , & V_85 ) ;
F_8 ( L_11 , & V_81 ,
V_85 == V_78 ? L_12 : L_13 ,
& V_88 -> V_29 ) ;
F_15 ( & V_19 , V_18 ) ;
V_6 = F_9 ( V_4 , & V_81 , V_85 ) ;
F_16 ( & V_19 , V_18 ) ;
if ( ! V_6 ) {
F_8 ( L_14 , & V_81 ) ;
return - V_55 ;
}
V_29 = V_6 -> V_33 ;
memcpy ( & F_53 ( V_22 ) -> V_81 , & V_88 -> V_29 ,
sizeof( struct V_79 ) ) ;
F_53 ( V_22 ) -> V_12 = V_6 -> V_12 ;
}
V_28 = V_4 -> V_3 -> V_34 ;
return F_54 ( V_22 , V_3 , type , V_29 , V_28 , V_35 ) ;
}
static int F_55 ( struct V_16 * V_12 , const void * V_28 ,
const void * V_29 , struct V_21 * V_22 ,
struct V_2 * V_3 )
{
F_36 ( V_63 , L_15 ,
V_22 -> V_41 , V_22 -> V_35 ) ;
return F_44 ( V_12 , V_22 -> V_41 , V_22 -> V_35 , 0 , V_3 ) ;
}
static void F_56 ( struct V_21 * V_22 , struct V_2 * V_3 )
{
struct V_21 * V_39 ;
struct V_1 * V_17 , * V_11 ;
unsigned long V_18 ;
F_15 ( & V_19 , V_18 ) ;
F_11 (entry, tmp, &bt_6lowpan_devices, list) {
struct V_5 * V_91 , * V_92 ;
struct V_1 * V_4 ;
if ( V_17 -> V_3 != V_3 )
continue;
V_4 = V_1 ( V_17 -> V_3 ) ;
F_11 (pentry, ptmp, &dev->peers, list) {
V_39 = F_32 ( V_22 , V_25 ) ;
F_55 ( V_91 -> V_12 , V_3 -> V_34 ,
V_91 -> V_33 , V_39 , V_3 ) ;
F_24 ( V_39 ) ;
}
}
F_16 ( & V_19 , V_18 ) ;
}
static T_6 F_57 ( struct V_21 * V_22 , struct V_2 * V_3 )
{
int V_54 = 0 ;
unsigned char * V_33 ;
struct V_1 * V_4 ;
struct V_5 * V_6 ;
T_1 V_81 ;
T_3 V_85 ;
if ( F_52 ( & F_53 ( V_22 ) -> V_81 ) ) {
F_56 ( V_22 , V_3 ) ;
} else {
unsigned long V_18 ;
F_49 ( & F_53 ( V_22 ) -> V_81 , & V_81 , & V_85 ) ;
V_33 = F_53 ( V_22 ) -> V_81 . V_83 + 8 ;
V_4 = V_1 ( V_3 ) ;
F_15 ( & V_19 , V_18 ) ;
V_6 = F_9 ( V_4 , & V_81 , V_85 ) ;
F_16 ( & V_19 , V_18 ) ;
F_8 ( L_16 ,
V_3 -> V_93 , & V_81 ,
V_85 == V_78 ? L_12 : L_13 ,
& F_53 ( V_22 ) -> V_81 , V_6 ) ;
if ( V_6 && V_6 -> V_12 )
V_54 = F_55 ( V_6 -> V_12 , V_3 -> V_34 ,
V_33 , V_22 , V_3 ) ;
}
F_58 ( V_22 ) ;
if ( V_54 )
F_8 ( L_17 , V_54 ) ;
return ( V_54 < 0 ) ? V_94 : V_54 ;
}
static void F_59 ( struct V_2 * V_4 )
{
V_4 -> V_95 = V_37 ;
V_4 -> type = V_40 ;
V_4 -> V_96 = 0 ;
V_4 -> V_97 = 0 ;
V_4 -> V_58 = V_98 ;
V_4 -> V_99 = 0 ;
V_4 -> V_18 = V_100 | V_101 ;
V_4 -> V_102 = 0 ;
V_4 -> V_103 = & V_103 ;
V_4 -> V_104 = & V_104 ;
V_4 -> V_105 = V_106 ;
}
static void F_60 ( T_3 * V_107 , T_3 * V_81 , T_3 V_85 )
{
V_107 [ 0 ] = V_81 [ 5 ] ;
V_107 [ 1 ] = V_81 [ 4 ] ;
V_107 [ 2 ] = V_81 [ 3 ] ;
V_107 [ 3 ] = 0xFF ;
V_107 [ 4 ] = 0xFE ;
V_107 [ 5 ] = V_81 [ 2 ] ;
V_107 [ 6 ] = V_81 [ 1 ] ;
V_107 [ 7 ] = V_81 [ 0 ] ;
if ( V_85 == V_78 )
V_107 [ 0 ] &= ~ 0x02 ;
else
V_107 [ 0 ] |= 0x02 ;
F_8 ( L_18 , V_85 , 8 , V_107 ) ;
}
static void F_61 ( struct V_2 * V_3 , T_1 * V_81 ,
T_3 V_85 )
{
V_3 -> V_108 = V_109 ;
F_60 ( V_3 -> V_34 , V_81 -> V_84 , V_85 ) ;
}
static void F_62 ( struct V_2 * V_3 )
{
int V_54 ;
F_63 () ;
V_54 = F_64 ( V_3 ) ;
if ( V_54 < 0 )
F_65 ( L_19 , V_3 -> V_93 , V_54 ) ;
F_66 () ;
}
static void F_67 ( struct V_110 * V_111 )
{
struct V_1 * V_4 = F_68 ( V_111 , struct V_1 ,
V_112 . V_111 ) ;
F_69 ( V_4 -> V_3 ) ;
}
static bool F_70 ( struct V_113 * V_13 )
{
if ( V_13 -> type != V_114 )
return false ;
return F_71 ( V_115 , & V_13 -> V_18 ) ;
}
static int F_72 ( struct V_16 * V_12 , struct V_1 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_18 ;
V_6 = F_73 ( sizeof( * V_6 ) , V_25 ) ;
if ( ! V_6 )
return - V_26 ;
V_6 -> V_12 = V_12 ;
memset ( & V_6 -> V_116 , 0 , sizeof( struct V_79 ) ) ;
V_6 -> V_116 . V_83 [ 0 ] = 0xFE ;
V_6 -> V_116 . V_83 [ 1 ] = 0x80 ;
F_60 ( ( T_3 * ) & V_6 -> V_116 . V_83 + 8 , V_12 -> V_13 -> V_14 . V_84 ,
V_12 -> V_13 -> V_15 ) ;
memcpy ( & V_6 -> V_33 , ( T_3 * ) & V_6 -> V_116 . V_83 + 8 ,
V_37 ) ;
F_74 ( & V_19 , V_18 ) ;
F_75 ( & V_6 -> V_7 ) ;
F_2 ( V_4 , V_6 ) ;
F_76 ( & V_19 , V_18 ) ;
F_77 ( & V_4 -> V_112 , F_67 ) ;
F_78 ( & V_4 -> V_112 , F_79 ( 100 ) ) ;
return 0 ;
}
int F_80 ( struct V_16 * V_12 )
{
struct V_5 * V_6 = NULL ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
int V_54 = 0 ;
unsigned long V_18 ;
if ( ! F_70 ( V_12 -> V_13 ) )
return 0 ;
V_6 = F_14 ( V_12 ) ;
if ( V_6 )
return - V_117 ;
V_4 = F_17 ( V_12 ) ;
if ( V_4 )
return F_72 ( V_12 , V_4 ) ;
V_3 = F_81 ( sizeof( * V_4 ) , V_118 , F_59 ) ;
if ( ! V_3 )
return - V_26 ;
F_61 ( V_3 , & V_12 -> V_13 -> V_119 , V_12 -> V_13 -> V_120 ) ;
V_3 -> V_103 = & V_103 ;
F_82 ( V_3 , & V_12 -> V_13 -> V_4 ) ;
F_83 ( V_3 , & V_121 ) ;
V_54 = F_84 ( V_3 ) ;
if ( V_54 < 0 ) {
F_65 ( L_20 , V_54 ) ;
V_106 ( V_3 ) ;
goto V_122;
}
F_8 ( L_21 ,
V_3 -> V_123 , & V_12 -> V_13 -> V_14 , & V_12 -> V_13 -> V_119 ) ;
F_85 ( V_124 , & V_3 -> V_125 ) ;
V_4 = F_1 ( V_3 ) ;
V_4 -> V_3 = V_3 ;
V_4 -> V_20 = V_12 -> V_13 -> V_20 ;
F_75 ( & V_4 -> V_8 ) ;
F_74 ( & V_19 , V_18 ) ;
F_75 ( & V_4 -> V_7 ) ;
F_3 ( & V_4 -> V_7 , & V_126 ) ;
F_76 ( & V_19 , V_18 ) ;
F_62 ( V_3 ) ;
return F_72 ( V_12 , V_4 ) ;
V_122:
return V_54 ;
}
static void F_86 ( struct V_110 * V_111 )
{
struct V_1 * V_17 = F_68 ( V_111 , struct V_1 ,
F_86 ) ;
F_87 ( V_17 -> V_3 ) ;
}
int F_88 ( struct V_16 * V_12 )
{
struct V_1 * V_17 , * V_11 ;
struct V_1 * V_4 = NULL ;
struct V_5 * V_6 ;
int V_54 = - V_55 ;
unsigned long V_18 ;
bool V_127 = false ;
if ( ! V_12 || ! F_70 ( V_12 -> V_13 ) )
return 0 ;
F_74 ( & V_19 , V_18 ) ;
F_11 (entry, tmp, &bt_6lowpan_devices, list) {
V_4 = V_1 ( V_17 -> V_3 ) ;
V_6 = F_13 ( V_4 , V_12 ) ;
if ( V_6 ) {
V_127 = F_5 ( V_4 , V_6 ) ;
V_54 = 0 ;
break;
}
}
if ( ! V_54 && V_127 && V_4 && ! F_10 ( & V_4 -> V_9 ) ) {
F_76 ( & V_19 , V_18 ) ;
F_89 ( & V_4 -> V_112 ) ;
F_90 ( & V_17 -> F_86 , F_86 ) ;
F_91 ( & V_17 -> F_86 ) ;
} else {
F_76 ( & V_19 , V_18 ) ;
}
return V_54 ;
}
static int F_92 ( struct V_128 * V_129 ,
unsigned long V_130 , void * V_131 )
{
struct V_2 * V_3 = F_93 ( V_131 ) ;
struct V_1 * V_17 , * V_11 ;
unsigned long V_18 ;
if ( V_3 -> type != V_40 )
return V_132 ;
switch ( V_130 ) {
case V_133 :
F_74 ( & V_19 , V_18 ) ;
F_11 (entry, tmp, &bt_6lowpan_devices,
list) {
if ( V_17 -> V_3 == V_3 ) {
F_6 ( & V_17 -> V_7 ) ;
F_94 ( V_17 ) ;
break;
}
}
F_76 ( & V_19 , V_18 ) ;
break;
}
return V_132 ;
}
int F_95 ( void )
{
return F_96 ( & V_134 ) ;
}
void F_97 ( void )
{
F_98 ( & V_134 ) ;
}
