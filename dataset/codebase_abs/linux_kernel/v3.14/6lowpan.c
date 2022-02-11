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
static void F_47 ( struct V_76 * V_77 ,
T_1 * V_78 , T_3 * V_79 )
{
T_3 * V_80 ;
V_80 = V_77 -> V_81 + 8 ;
V_78 -> V_82 [ 0 ] = V_80 [ 7 ] ;
V_78 -> V_82 [ 1 ] = V_80 [ 6 ] ;
V_78 -> V_82 [ 2 ] = V_80 [ 5 ] ;
V_78 -> V_82 [ 3 ] = V_80 [ 2 ] ;
V_78 -> V_82 [ 4 ] = V_80 [ 1 ] ;
V_78 -> V_82 [ 5 ] = V_80 [ 0 ] ;
V_78 -> V_82 [ 5 ] ^= 2 ;
if ( V_78 -> V_82 [ 5 ] & 1 ) {
V_78 -> V_82 [ 5 ] &= ~ 1 ;
* V_79 = V_83 ;
} else {
* V_79 = V_84 ;
}
}
static int F_48 ( struct V_21 * V_22 , struct V_2 * V_3 ,
unsigned short type , const void * V_85 ,
const void * V_86 , unsigned int V_35 )
{
struct V_48 * V_87 ;
struct V_1 * V_4 ;
struct V_5 * V_6 ;
T_1 V_78 , * V_88 = V_89 ;
T_3 * V_28 , * V_29 = V_88 -> V_82 ;
T_3 V_79 ;
if ( type != V_45 )
return - V_38 ;
V_87 = F_49 ( V_22 ) ;
V_4 = V_1 ( V_3 ) ;
if ( F_50 ( & V_87 -> V_29 ) ) {
memcpy ( & F_51 ( V_22 ) -> V_78 , & V_87 -> V_29 ,
sizeof( struct V_76 ) ) ;
F_51 ( V_22 ) -> V_12 = NULL ;
} else {
unsigned long V_18 ;
F_47 ( & V_87 -> V_29 , & V_78 , & V_79 ) ;
F_8 ( L_11 , & V_78 , V_79 ) ;
F_15 ( & V_19 , V_18 ) ;
V_6 = F_9 ( V_4 , & V_78 , V_79 ) ;
F_16 ( & V_19 , V_18 ) ;
if ( ! V_6 ) {
F_8 ( L_12 , & V_78 ) ;
return - V_55 ;
}
V_29 = V_6 -> V_33 ;
memcpy ( & F_51 ( V_22 ) -> V_78 , & V_87 -> V_29 ,
sizeof( struct V_76 ) ) ;
F_51 ( V_22 ) -> V_12 = V_6 -> V_12 ;
}
V_28 = V_4 -> V_3 -> V_34 ;
return F_52 ( V_22 , V_3 , type , V_29 , V_28 , V_35 ) ;
}
static int F_53 ( struct V_16 * V_12 , const void * V_28 ,
const void * V_29 , struct V_21 * V_22 ,
struct V_2 * V_3 )
{
F_36 ( V_63 , L_13 ,
V_22 -> V_41 , V_22 -> V_35 ) ;
return F_44 ( V_12 , V_22 -> V_41 , V_22 -> V_35 , 0 , V_3 ) ;
}
static void F_54 ( struct V_21 * V_22 , struct V_2 * V_3 )
{
struct V_21 * V_39 ;
struct V_1 * V_17 , * V_11 ;
unsigned long V_18 ;
F_15 ( & V_19 , V_18 ) ;
F_11 (entry, tmp, &bt_6lowpan_devices, list) {
struct V_5 * V_90 , * V_91 ;
struct V_1 * V_4 ;
if ( V_17 -> V_3 != V_3 )
continue;
V_4 = V_1 ( V_17 -> V_3 ) ;
F_11 (pentry, ptmp, &dev->peers, list) {
V_39 = F_32 ( V_22 , V_25 ) ;
F_53 ( V_90 -> V_12 , V_3 -> V_34 ,
V_90 -> V_33 , V_39 , V_3 ) ;
F_24 ( V_39 ) ;
}
}
F_16 ( & V_19 , V_18 ) ;
}
static T_6 F_55 ( struct V_21 * V_22 , struct V_2 * V_3 )
{
int V_54 = 0 ;
unsigned char * V_33 ;
struct V_1 * V_4 ;
struct V_5 * V_6 ;
T_1 V_78 ;
T_3 V_79 ;
if ( F_50 ( & F_51 ( V_22 ) -> V_78 ) ) {
F_54 ( V_22 , V_3 ) ;
} else {
unsigned long V_18 ;
F_47 ( & F_51 ( V_22 ) -> V_78 , & V_78 , & V_79 ) ;
V_33 = F_51 ( V_22 ) -> V_78 . V_81 + 8 ;
V_4 = V_1 ( V_3 ) ;
F_15 ( & V_19 , V_18 ) ;
V_6 = F_9 ( V_4 , & V_78 , V_79 ) ;
F_16 ( & V_19 , V_18 ) ;
F_8 ( L_14 , V_3 -> V_92 ,
& V_78 , & F_51 ( V_22 ) -> V_78 , V_6 ) ;
if ( V_6 && V_6 -> V_12 )
V_54 = F_53 ( V_6 -> V_12 , V_3 -> V_34 ,
V_33 , V_22 , V_3 ) ;
}
F_56 ( V_22 ) ;
if ( V_54 )
F_8 ( L_15 , V_54 ) ;
return ( V_54 < 0 ) ? V_93 : V_54 ;
}
static void F_57 ( struct V_2 * V_4 )
{
V_4 -> V_94 = V_37 ;
V_4 -> type = V_40 ;
V_4 -> V_95 = 0 ;
V_4 -> V_96 = 0 ;
V_4 -> V_58 = V_97 ;
V_4 -> V_98 = 0 ;
V_4 -> V_18 = V_99 | V_100 ;
V_4 -> V_101 = 0 ;
V_4 -> V_102 = & V_102 ;
V_4 -> V_103 = & V_103 ;
V_4 -> V_104 = V_105 ;
}
static void F_58 ( T_3 * V_106 , T_3 * V_78 , T_3 V_79 )
{
V_106 [ 0 ] = V_78 [ 5 ] ;
V_106 [ 1 ] = V_78 [ 4 ] ;
V_106 [ 2 ] = V_78 [ 3 ] ;
V_106 [ 3 ] = 0xFF ;
V_106 [ 4 ] = 0xFE ;
V_106 [ 5 ] = V_78 [ 2 ] ;
V_106 [ 6 ] = V_78 [ 1 ] ;
V_106 [ 7 ] = V_78 [ 0 ] ;
V_106 [ 0 ] ^= 2 ;
if ( V_79 == V_83 )
V_106 [ 0 ] |= 1 ;
else
V_106 [ 0 ] &= ~ 1 ;
}
static void F_59 ( struct V_2 * V_3 , T_1 * V_78 ,
T_3 V_79 )
{
V_3 -> V_107 = V_108 ;
F_58 ( V_3 -> V_34 , V_78 -> V_82 , V_79 ) ;
V_3 -> V_34 [ 0 ] ^= 2 ;
}
static void F_60 ( struct V_2 * V_3 )
{
int V_54 ;
F_61 () ;
V_54 = F_62 ( V_3 ) ;
if ( V_54 < 0 )
F_63 ( L_16 , V_3 -> V_92 , V_54 ) ;
F_64 () ;
}
static void F_65 ( struct V_109 * V_110 )
{
struct V_1 * V_4 = F_66 ( V_110 , struct V_1 ,
V_111 . V_110 ) ;
F_67 ( V_4 -> V_3 ) ;
}
static bool F_68 ( struct V_112 * V_13 )
{
if ( V_13 -> type != V_113 )
return false ;
return F_69 ( V_114 , & V_13 -> V_18 ) ;
}
static int F_70 ( struct V_16 * V_12 , struct V_1 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_18 ;
V_6 = F_71 ( sizeof( * V_6 ) , V_25 ) ;
if ( ! V_6 )
return - V_26 ;
V_6 -> V_12 = V_12 ;
memset ( & V_6 -> V_115 , 0 , sizeof( struct V_76 ) ) ;
V_6 -> V_115 . V_81 [ 0 ] = 0xFE ;
V_6 -> V_115 . V_81 [ 1 ] = 0x80 ;
F_58 ( ( T_3 * ) & V_6 -> V_115 . V_81 + 8 , V_12 -> V_13 -> V_14 . V_82 ,
V_12 -> V_13 -> V_15 ) ;
memcpy ( & V_6 -> V_33 , ( T_3 * ) & V_6 -> V_115 . V_81 + 8 ,
V_37 ) ;
V_6 -> V_33 [ 0 ] ^= 2 ;
F_72 ( V_63 , L_17 ,
( unsigned char * ) & V_6 -> V_115 , 16 ) ;
F_72 ( V_63 , L_18 , V_6 -> V_33 , 8 ) ;
F_73 ( & V_19 , V_18 ) ;
F_74 ( & V_6 -> V_7 ) ;
F_2 ( V_4 , V_6 ) ;
F_75 ( & V_19 , V_18 ) ;
F_76 ( & V_4 -> V_111 , F_65 ) ;
F_77 ( & V_4 -> V_111 , F_78 ( 100 ) ) ;
return 0 ;
}
int F_79 ( struct V_16 * V_12 )
{
struct V_5 * V_6 = NULL ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
int V_54 = 0 ;
unsigned long V_18 ;
if ( ! F_68 ( V_12 -> V_13 ) )
return 0 ;
V_6 = F_14 ( V_12 ) ;
if ( V_6 )
return - V_116 ;
V_4 = F_17 ( V_12 ) ;
if ( V_4 )
return F_70 ( V_12 , V_4 ) ;
V_3 = F_80 ( sizeof( * V_4 ) , V_117 , F_57 ) ;
if ( ! V_3 )
return - V_26 ;
F_59 ( V_3 , & V_12 -> V_13 -> V_118 , V_12 -> V_13 -> V_119 ) ;
V_3 -> V_102 = & V_102 ;
F_81 ( V_3 , & V_12 -> V_13 -> V_4 ) ;
F_82 ( V_3 , & V_120 ) ;
V_54 = F_83 ( V_3 ) ;
if ( V_54 < 0 ) {
F_63 ( L_19 , V_54 ) ;
V_105 ( V_3 ) ;
goto V_121;
}
F_8 ( L_20 ,
V_3 -> V_122 , & V_12 -> V_13 -> V_14 , & V_12 -> V_13 -> V_118 ) ;
F_84 ( V_123 , & V_3 -> V_124 ) ;
V_4 = F_1 ( V_3 ) ;
V_4 -> V_3 = V_3 ;
V_4 -> V_20 = V_12 -> V_13 -> V_20 ;
F_74 ( & V_4 -> V_8 ) ;
F_73 ( & V_19 , V_18 ) ;
F_74 ( & V_4 -> V_7 ) ;
F_3 ( & V_4 -> V_7 , & V_125 ) ;
F_75 ( & V_19 , V_18 ) ;
F_60 ( V_3 ) ;
return F_70 ( V_12 , V_4 ) ;
V_121:
return V_54 ;
}
static void F_85 ( struct V_109 * V_110 )
{
struct V_1 * V_17 = F_66 ( V_110 , struct V_1 ,
F_85 ) ;
F_86 ( V_17 -> V_3 ) ;
}
int F_87 ( struct V_16 * V_12 )
{
struct V_1 * V_17 , * V_11 ;
struct V_1 * V_4 = NULL ;
struct V_5 * V_6 ;
int V_54 = - V_55 ;
unsigned long V_18 ;
bool V_126 = false ;
if ( ! V_12 || ! F_68 ( V_12 -> V_13 ) )
return 0 ;
F_73 ( & V_19 , V_18 ) ;
F_11 (entry, tmp, &bt_6lowpan_devices, list) {
V_4 = V_1 ( V_17 -> V_3 ) ;
V_6 = F_13 ( V_4 , V_12 ) ;
if ( V_6 ) {
V_126 = F_5 ( V_4 , V_6 ) ;
V_54 = 0 ;
break;
}
}
if ( ! V_54 && V_126 && V_4 && ! F_10 ( & V_4 -> V_9 ) ) {
F_75 ( & V_19 , V_18 ) ;
F_88 ( & V_4 -> V_111 ) ;
F_89 ( & V_17 -> F_85 , F_85 ) ;
F_90 ( & V_17 -> F_85 ) ;
} else {
F_75 ( & V_19 , V_18 ) ;
}
return V_54 ;
}
static int F_91 ( struct V_127 * V_128 ,
unsigned long V_129 , void * V_130 )
{
struct V_2 * V_3 = F_92 ( V_130 ) ;
struct V_1 * V_17 , * V_11 ;
unsigned long V_18 ;
if ( V_3 -> type != V_40 )
return V_131 ;
switch ( V_129 ) {
case V_132 :
F_73 ( & V_19 , V_18 ) ;
F_11 (entry, tmp, &bt_6lowpan_devices,
list) {
if ( V_17 -> V_3 == V_3 ) {
F_6 ( & V_17 -> V_7 ) ;
F_93 ( V_17 ) ;
break;
}
}
F_75 ( & V_19 , V_18 ) ;
break;
}
return V_131 ;
}
int F_94 ( void )
{
return F_95 ( & V_133 ) ;
}
void F_96 ( void )
{
F_97 ( & V_133 ) ;
}
