static inline void F_1 ( void )
{
F_2 ( 5 ) ;
#ifdef F_3
F_2 ( 8 ) ;
#endif
}
static inline void F_4 ( void )
{
F_2 ( 0 ) ;
}
static inline void F_5 ( void )
{
F_2 ( 8 ) ;
}
static void F_6 ( void )
{
char * V_1 ;
V_1 = F_7 ( V_2 , V_3 ) ;
if ( V_1 != 0 ) {
V_1 [ V_3 - 1 ] = 0 ;
F_8 ( L_1 , V_1 ) ;
}
}
static void F_9 ( void )
{
F_10 ( L_2 ) ;
F_6 () ;
for (; ; )
;
}
T_1 F_11 ( enum V_4 V_5 )
{
return F_12 ( V_6 . V_7 + V_5 * 4 ) ;
}
static int F_13 ( void )
{
if ( F_11 ( V_8 ) & V_9 ) {
F_9 () ;
return - 1 ;
}
return 0 ;
}
static int F_14 ( struct V_10 * V_11 )
{
return ( V_11 -> V_12 -> V_13 - V_11 -> V_12 -> V_14 ) & V_11 -> V_15 ;
}
static int F_15 ( struct V_10 * V_11 )
{
return V_11 -> V_15 -
( ( V_11 -> V_16 -> V_13 - V_11 -> V_16 -> V_14 ) & V_11 -> V_15 ) ;
}
static int F_16 ( struct V_10 * V_11 )
{
if ( V_11 -> V_17 ) {
int V_18 = F_14 ( V_11 ) ;
if ( V_18 > V_11 -> V_17 )
V_18 = V_11 -> V_17 ;
return V_18 ;
} else {
return 0 ;
}
}
static int F_17 ( struct V_10 * V_11 )
{
int V_18 = F_15 ( V_11 ) ;
return V_18 > V_19 ? V_18 - V_19 : 0 ;
}
static int F_18 ( struct V_10 * V_11 )
{
return ( V_11 -> V_12 -> V_7 == V_20 ) &&
( V_11 -> V_16 -> V_7 == V_20 ) ;
}
static unsigned F_19 ( struct V_10 * V_11 , void * * V_21 )
{
unsigned V_13 = V_11 -> V_12 -> V_13 ;
unsigned V_14 = V_11 -> V_12 -> V_14 ;
* V_21 = ( void * ) ( V_11 -> V_22 + V_14 ) ;
if ( V_14 <= V_13 )
return V_13 - V_14 ;
else
return V_11 -> V_23 - V_14 ;
}
static void F_20 ( struct V_10 * V_11 , unsigned V_24 )
{
F_21 ( V_24 > F_14 ( V_11 ) ) ;
V_11 -> V_12 -> V_14 = ( V_11 -> V_12 -> V_14 + V_24 ) & V_11 -> V_15 ;
V_11 -> V_16 -> V_25 = 1 ;
}
static int F_22 ( struct V_10 * V_11 , void * V_26 , int V_27 )
{
void * V_21 ;
unsigned V_18 ;
unsigned char * V_28 = V_26 ;
int V_29 = V_27 ;
while ( V_27 > 0 ) {
V_18 = F_19 ( V_11 , & V_21 ) ;
if ( V_18 == 0 )
break;
if ( V_18 > V_27 )
V_18 = V_27 ;
if ( V_26 )
memcpy ( V_28 , V_21 , V_18 ) ;
V_28 += V_18 ;
V_27 -= V_18 ;
F_20 ( V_11 , V_18 ) ;
}
return V_29 - V_27 ;
}
static void F_23 ( struct V_10 * V_11 )
{
}
static void F_24 ( struct V_10 * V_11 )
{
unsigned V_30 [ 5 ] ;
int V_31 ;
if ( V_11 -> V_17 != 0 )
return;
if ( F_14 ( V_11 ) < V_19 )
return;
V_31 = F_22 ( V_11 , V_30 , V_19 ) ;
F_21 ( V_31 != V_19 ) ;
V_11 -> V_17 = V_30 [ 0 ] ;
}
static unsigned F_25 ( struct V_10 * V_11 , void * * V_21 )
{
unsigned V_13 = V_11 -> V_16 -> V_13 ;
unsigned V_14 = V_11 -> V_16 -> V_14 ;
* V_21 = ( void * ) ( V_11 -> V_32 + V_13 ) ;
if ( V_13 < V_14 ) {
return V_14 - V_13 - 1 ;
} else {
if ( V_14 == 0 )
return V_11 -> V_23 - V_13 - 1 ;
else
return V_11 -> V_23 - V_13 ;
}
}
static void F_26 ( struct V_10 * V_11 , unsigned V_24 )
{
F_21 ( V_24 > F_15 ( V_11 ) ) ;
V_11 -> V_16 -> V_13 = ( V_11 -> V_16 -> V_13 + V_24 ) & V_11 -> V_15 ;
V_11 -> V_16 -> V_33 = 1 ;
}
static void F_27 ( struct V_10 * V_11 , unsigned V_18 )
{
if ( V_18 == V_20 ) {
V_11 -> V_16 -> V_34 = 1 ;
V_11 -> V_16 -> V_35 = 1 ;
V_11 -> V_16 -> V_36 = 1 ;
} else {
V_11 -> V_16 -> V_34 = 0 ;
V_11 -> V_16 -> V_35 = 0 ;
V_11 -> V_16 -> V_36 = 0 ;
}
V_11 -> V_16 -> V_7 = V_18 ;
V_11 -> V_16 -> V_37 = 1 ;
V_11 -> V_38 () ;
}
static void F_28 ( void )
{
struct V_39 * V_40 = ( void * ) V_41 ;
if ( V_40 -> V_42 . V_43 != V_44 ) {
V_44 = V_40 -> V_42 . V_43 ;
F_29 ( & V_45 ) ;
}
}
static void F_30 ( struct V_10 * V_11 ,
unsigned V_46 , unsigned V_47 )
{
V_11 -> V_48 = V_47 ;
F_8 ( L_3 , V_11 -> V_18 , V_46 , V_47 ) ;
switch ( V_47 ) {
case V_49 :
V_11 -> V_12 -> V_14 = 0 ;
case V_20 :
if ( V_11 -> V_16 -> V_7 != V_20 )
F_27 ( V_11 , V_20 ) ;
V_11 -> V_50 ( V_11 -> V_51 , V_52 ) ;
break;
case V_53 :
case V_54 :
default:
V_11 -> V_50 ( V_11 -> V_51 , V_55 ) ;
}
}
static void F_31 ( struct V_56 * V_57 , void (* V_50)( void ) )
{
unsigned long V_58 ;
struct V_10 * V_11 ;
int V_59 = 0 ;
unsigned V_60 ;
unsigned V_61 ;
F_32 ( & V_62 , V_58 ) ;
F_33 (ch, list, ch_list) {
V_60 = 0 ;
if ( F_18 ( V_11 ) ) {
if ( V_11 -> V_12 -> V_33 ) {
V_11 -> V_12 -> V_33 = 0 ;
V_60 |= 1 ;
V_59 |= 1 ;
}
if ( V_11 -> V_12 -> V_25 ) {
V_11 -> V_12 -> V_25 = 0 ;
V_60 |= 2 ;
V_59 |= 1 ;
}
if ( V_11 -> V_12 -> V_37 ) {
V_11 -> V_12 -> V_37 = 0 ;
V_60 |= 4 ;
V_59 |= 1 ;
}
}
V_61 = V_11 -> V_12 -> V_7 ;
if ( V_61 != V_11 -> V_48 )
F_30 ( V_11 , V_11 -> V_48 , V_61 ) ;
if ( V_60 ) {
V_11 -> V_63 ( V_11 ) ;
V_11 -> V_50 ( V_11 -> V_51 , V_64 ) ;
}
}
if ( V_59 )
V_50 () ;
F_34 ( & V_62 , V_58 ) ;
F_28 () ;
}
static T_2 F_35 ( int V_65 , void * V_28 )
{
F_31 ( & V_66 , F_4 ) ;
return V_67 ;
}
static T_2 F_36 ( int V_65 , void * V_28 )
{
F_31 ( & V_68 , F_5 ) ;
return V_67 ;
}
static void F_37 ( unsigned long V_69 )
{
F_31 ( & V_66 , F_4 ) ;
F_31 ( & V_68 , F_5 ) ;
}
static inline int F_38 ( struct V_10 * V_11 )
{
if ( F_18 ( V_11 ) ) {
if ( V_11 -> V_12 -> V_33 || V_11 -> V_12 -> V_25 || V_11 -> V_12 -> V_37 )
return 1 ;
if ( V_11 -> V_12 -> V_7 != V_11 -> V_48 )
return 1 ;
}
return 0 ;
}
void F_39 ( void )
{
unsigned long V_58 ;
struct V_10 * V_11 ;
int V_70 = 0 ;
F_32 ( & V_62 , V_58 ) ;
F_33 (ch, &smd_ch_list_modem, ch_list) {
if ( F_38 ( V_11 ) ) {
V_70 = 1 ;
break;
}
}
F_33 (ch, &smd_ch_list_dsp, ch_list) {
if ( F_38 ( V_11 ) ) {
V_70 = 1 ;
break;
}
}
F_34 ( & V_62 , V_58 ) ;
F_28 () ;
if ( V_70 ) {
if ( V_71 & V_72 )
F_40 ( L_4 ) ;
F_41 ( & V_73 ) ;
}
}
void F_42 ( T_3 * V_11 )
{
unsigned long V_58 ;
unsigned V_61 ;
F_32 ( & V_62 , V_58 ) ;
V_11 -> V_63 ( V_11 ) ;
V_61 = V_11 -> V_12 -> V_7 ;
if ( V_61 != V_11 -> V_48 ) {
V_11 -> V_48 = V_61 ;
if ( V_61 == V_20 )
V_11 -> V_50 ( V_11 -> V_51 , V_52 ) ;
else
V_11 -> V_50 ( V_11 -> V_51 , V_55 ) ;
}
V_11 -> V_50 ( V_11 -> V_51 , V_64 ) ;
V_11 -> V_38 () ;
F_34 ( & V_62 , V_58 ) ;
}
static int F_43 ( int V_74 , unsigned type )
{
type &= V_75 ;
if ( type == V_76 )
return 1 ;
if ( type == V_77 )
return 0 ;
if ( ( V_74 > 4 ) || ( V_74 == 1 ) )
return 1 ;
else
return 0 ;
}
static int F_44 ( T_3 * V_11 , const void * V_26 , int V_27 )
{
void * V_21 ;
const unsigned char * V_78 = V_26 ;
unsigned V_79 ;
int V_29 = V_27 ;
if ( V_27 < 0 )
return - V_80 ;
while ( ( V_79 = F_25 ( V_11 , & V_21 ) ) != 0 ) {
if ( ! F_18 ( V_11 ) )
break;
if ( V_79 > V_27 )
V_79 = V_27 ;
memcpy ( V_21 , V_78 , V_79 ) ;
F_26 ( V_11 , V_79 ) ;
V_27 -= V_79 ;
V_78 += V_79 ;
if ( V_27 == 0 )
break;
}
V_11 -> V_38 () ;
return V_29 - V_27 ;
}
static int F_45 ( T_3 * V_11 , const void * V_26 , int V_27 )
{
unsigned V_30 [ 5 ] ;
if ( V_27 < 0 )
return - V_80 ;
if ( F_15 ( V_11 ) < ( V_27 + V_19 ) )
return - V_81 ;
V_30 [ 0 ] = V_27 ;
V_30 [ 1 ] = V_30 [ 2 ] = V_30 [ 3 ] = V_30 [ 4 ] = 0 ;
F_44 ( V_11 , V_30 , sizeof( V_30 ) ) ;
F_44 ( V_11 , V_26 , V_27 ) ;
return V_27 ;
}
static int F_46 ( T_3 * V_11 , void * V_28 , int V_27 )
{
int V_31 ;
if ( V_27 < 0 )
return - V_80 ;
V_31 = F_22 ( V_11 , V_28 , V_27 ) ;
if ( V_31 > 0 )
V_11 -> V_38 () ;
return V_31 ;
}
static int F_47 ( T_3 * V_11 , void * V_28 , int V_27 )
{
unsigned long V_58 ;
int V_31 ;
if ( V_27 < 0 )
return - V_80 ;
if ( V_27 > V_11 -> V_17 )
V_27 = V_11 -> V_17 ;
V_31 = F_22 ( V_11 , V_28 , V_27 ) ;
if ( V_31 > 0 )
V_11 -> V_38 () ;
F_32 ( & V_62 , V_58 ) ;
V_11 -> V_17 -= V_31 ;
F_24 ( V_11 ) ;
F_34 ( & V_62 , V_58 ) ;
return V_31 ;
}
static int F_48 ( const char * V_82 , T_1 V_83 , T_1 type )
{
struct V_10 * V_11 ;
V_11 = F_49 ( sizeof( struct V_10 ) , V_84 ) ;
if ( V_11 == 0 ) {
F_10 ( L_5 ) ;
return - 1 ;
}
V_11 -> V_18 = V_83 ;
if ( F_50 ( V_11 ) ) {
F_51 ( V_11 ) ;
return - 1 ;
}
V_11 -> V_15 = V_11 -> V_23 - 1 ;
V_11 -> type = type ;
if ( ( type & V_85 ) == V_86 )
V_11 -> V_38 = F_4 ;
else
V_11 -> V_38 = F_5 ;
if ( F_43 ( V_83 , type ) ) {
V_11 -> V_87 = F_47 ;
V_11 -> V_88 = F_45 ;
V_11 -> V_89 = F_16 ;
V_11 -> V_90 = F_17 ;
V_11 -> V_63 = F_24 ;
} else {
V_11 -> V_87 = F_46 ;
V_11 -> V_88 = F_44 ;
V_11 -> V_89 = F_14 ;
V_11 -> V_90 = F_15 ;
V_11 -> V_63 = F_23 ;
}
if ( ( type & 0xff ) == 0 )
memcpy ( V_11 -> V_82 , L_6 , 4 ) ;
else
memcpy ( V_11 -> V_82 , L_7 , 4 ) ;
memcpy ( V_11 -> V_82 + 4 , V_82 , 20 ) ;
V_11 -> V_82 [ 23 ] = 0 ;
V_11 -> V_91 . V_82 = V_11 -> V_82 ;
V_11 -> V_91 . V_92 = - 1 ;
F_8 ( L_8 ,
V_11 -> V_18 , V_11 -> V_23 , V_11 -> V_82 ) ;
F_52 ( & V_93 ) ;
F_53 ( & V_11 -> V_94 , & V_95 ) ;
F_54 ( & V_93 ) ;
F_55 ( & V_11 -> V_91 ) ;
return 0 ;
}
static void F_56 ( struct V_96 * V_97 )
{
struct V_98 * V_40 ;
unsigned V_99 ;
unsigned type ;
unsigned V_18 ;
V_40 = F_7 ( V_100 , sizeof( * V_40 ) * 64 ) ;
if ( ! V_40 ) {
F_10 ( L_9 ) ;
return;
}
for ( V_18 = 0 ; V_18 < 64 ; V_18 ++ ) {
if ( V_101 [ V_18 ] )
continue;
if ( ! V_40 [ V_18 ] . V_102 )
continue;
if ( ! V_40 [ V_18 ] . V_82 [ 0 ] )
continue;
V_99 = V_40 [ V_18 ] . V_99 ;
type = V_99 & V_85 ;
if ( ! memcmp ( V_40 [ V_18 ] . V_82 , L_10 , 3 ) )
V_99 = ( V_99 & ( ~ V_75 ) ) | V_77 ;
type = V_40 [ V_18 ] . V_99 & V_85 ;
if ( ( type == V_86 ) ||
( type == V_103 ) )
if ( ! F_48 ( V_40 [ V_18 ] . V_82 , V_40 [ V_18 ] . V_83 , V_99 ) )
V_101 [ V_18 ] = 1 ;
}
}
static void F_57 ( void * V_51 , unsigned V_58 )
{
}
struct V_10 * F_58 ( const char * V_82 )
{
struct V_10 * V_11 ;
F_52 ( & V_93 ) ;
F_33 (ch, &smd_ch_closed_list, ch_list) {
if ( ! strcmp ( V_82 , V_11 -> V_82 ) ) {
F_59 ( & V_11 -> V_94 ) ;
F_54 ( & V_93 ) ;
return V_11 ;
}
}
F_54 ( & V_93 ) ;
return NULL ;
}
int F_60 ( const char * V_82 , T_3 * * V_104 ,
void * V_51 , void (* V_50)( void * , unsigned ) )
{
struct V_10 * V_11 ;
unsigned long V_58 ;
if ( V_105 == 0 ) {
F_40 ( L_11 ) ;
return - V_106 ;
}
V_11 = F_58 ( V_82 ) ;
if ( ! V_11 )
return - V_106 ;
if ( V_50 == 0 )
V_50 = F_57 ;
V_11 -> V_50 = V_50 ;
V_11 -> V_17 = 0 ;
V_11 -> V_48 = V_107 ;
V_11 -> V_51 = V_51 ;
* V_104 = V_11 ;
F_32 ( & V_62 , V_58 ) ;
if ( ( V_11 -> type & V_85 ) == V_86 )
F_53 ( & V_11 -> V_94 , & V_66 ) ;
else
F_53 ( & V_11 -> V_94 , & V_68 ) ;
if ( V_11 -> V_12 -> V_7 == V_108 ) {
V_11 -> V_16 -> V_13 = 0 ;
F_27 ( V_11 , V_49 ) ;
} else {
F_27 ( V_11 , V_20 ) ;
}
F_34 ( & V_62 , V_58 ) ;
F_42 ( V_11 ) ;
return 0 ;
}
int F_61 ( T_3 * V_11 )
{
unsigned long V_58 ;
if ( V_11 == 0 )
return - 1 ;
F_32 ( & V_62 , V_58 ) ;
V_11 -> V_50 = F_57 ;
F_59 ( & V_11 -> V_94 ) ;
F_27 ( V_11 , V_107 ) ;
F_34 ( & V_62 , V_58 ) ;
F_52 ( & V_93 ) ;
F_53 ( & V_11 -> V_94 , & V_95 ) ;
F_54 ( & V_93 ) ;
return 0 ;
}
int F_62 ( T_3 * V_11 , void * V_28 , int V_27 )
{
return V_11 -> V_87 ( V_11 , V_28 , V_27 ) ;
}
int F_63 ( T_3 * V_11 , const void * V_28 , int V_27 )
{
return V_11 -> V_88 ( V_11 , V_28 , V_27 ) ;
}
int F_64 ( T_3 * V_11 , const void * V_28 , int V_27 )
{
unsigned long V_58 ;
int V_109 ;
F_32 ( & V_62 , V_58 ) ;
V_109 = V_11 -> V_88 ( V_11 , V_28 , V_27 ) ;
F_34 ( & V_62 , V_58 ) ;
return V_109 ;
}
int F_65 ( T_3 * V_11 )
{
return V_11 -> V_89 ( V_11 ) ;
}
int F_66 ( T_3 * V_11 )
{
return V_11 -> V_90 ( V_11 ) ;
}
int F_67 ( T_3 * V_11 , int V_110 )
{
return - 1 ;
}
int F_68 ( T_3 * V_11 , int V_110 )
{
return - 1 ;
}
int F_69 ( T_3 * V_11 )
{
return V_11 -> V_17 ;
}
void * F_70 ( unsigned V_92 , unsigned V_111 )
{
return F_7 ( V_92 , V_111 ) ;
}
void T_4 * F_71 ( unsigned V_92 , unsigned * V_111 )
{
struct V_39 * V_40 = ( void * ) V_41 ;
struct V_112 * V_113 = V_40 -> V_114 ;
if ( V_92 >= V_115 )
return NULL ;
if ( V_113 [ V_92 ] . V_116 ) {
* V_111 = V_113 [ V_92 ] . V_111 ;
return ( V_41 + V_113 [ V_92 ] . V_117 ) ;
} else {
* V_111 = 0 ;
}
return NULL ;
}
void * F_7 ( unsigned V_92 , unsigned V_118 )
{
unsigned V_111 ;
void * V_21 ;
V_21 = F_71 ( V_92 , & V_111 ) ;
if ( ! V_21 )
return 0 ;
V_118 = F_72 ( V_118 , 8 ) ;
if ( V_118 != V_111 ) {
F_10 ( L_12 ,
V_92 , V_118 , V_111 ) ;
return 0 ;
}
return V_21 ;
}
static T_2 F_73 ( int V_65 , void * V_28 )
{
unsigned long V_58 ;
unsigned V_119 , V_120 ;
F_32 ( & V_121 , V_58 ) ;
V_119 = F_11 ( V_122 ) ;
V_120 = F_11 ( V_8 ) ;
if ( V_71 & V_123 )
F_40 ( L_13 , V_119 , V_120 ) ;
if ( V_120 & V_9 )
F_9 () ;
F_28 () ;
F_34 ( & V_121 , V_58 ) ;
return V_67 ;
}
int F_74 ( enum V_4 V_5 ,
T_1 V_124 , T_1 V_125 )
{
void T_4 * V_126 = V_6 . V_7 + V_5 * 4 ;
unsigned long V_58 ;
unsigned V_7 ;
if ( ! V_6 . V_127 )
return - V_128 ;
F_32 ( & V_121 , V_58 ) ;
if ( F_11 ( V_8 ) & V_9 )
F_9 () ;
V_7 = ( F_12 ( V_126 ) & ~ V_124 ) | V_125 ;
F_75 ( V_7 , V_126 ) ;
if ( V_71 & V_123 )
F_40 ( L_14 , V_5 , V_7 ) ;
F_1 () ;
F_34 ( & V_121 , V_58 ) ;
return 0 ;
}
T_1 F_76 ( enum V_4 V_5 )
{
unsigned long V_58 ;
T_1 V_129 ;
F_32 ( & V_121 , V_58 ) ;
V_129 = F_12 ( V_6 . V_7 + V_5 * 4 ) ;
if ( V_5 == V_8 && ( V_129 & V_9 ) )
F_9 () ;
F_34 ( & V_121 , V_58 ) ;
return V_129 ;
}
int F_77 ( T_1 V_130 )
{
struct V_131 * V_21 ;
V_21 = F_7 ( V_132 , sizeof( * V_21 ) ) ;
if ( V_21 == NULL ) {
F_10 ( L_15 ) ;
return - V_128 ;
}
if ( V_71 & V_123 )
F_40 ( L_16 ,
V_21 -> V_133 , V_130 ) ;
V_21 -> V_133 = V_130 ;
return 0 ;
}
int F_77 ( T_1 V_130 )
{
T_1 * V_21 ;
V_21 = F_7 ( V_134 , sizeof( * V_21 ) ) ;
if ( V_21 == NULL ) {
F_10 ( L_17 ) ;
return - V_128 ;
}
if ( V_71 & V_123 )
F_40 ( L_16 ,
* V_21 , V_130 ) ;
* V_21 = V_130 ;
return 0 ;
}
int F_78 ( void )
{
int V_31 ;
for (; ; ) {
unsigned V_111 ;
void T_4 * V_7 ;
V_7 = F_71 ( V_135 , & V_111 ) ;
if ( V_111 == V_136 || V_111 == V_137 ) {
V_6 . V_7 = V_7 ;
break;
}
}
V_6 . V_127 = 1 ;
V_31 = F_79 ( V_138 , F_35 ,
V_139 , L_18 , 0 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_80 ( V_138 ) ;
if ( V_31 < 0 )
F_10 ( L_19 ) ;
V_31 = F_79 ( V_140 , F_73 ,
V_139 , L_20 , 0 ) ;
if ( V_31 < 0 ) {
F_81 ( V_138 , 0 ) ;
return V_31 ;
}
V_31 = F_80 ( V_140 ) ;
if ( V_31 < 0 )
F_10 ( L_21 ) ;
#if F_82 ( F_3 )
V_31 = F_79 ( V_141 , F_36 ,
V_139 , L_22 , 0 ) ;
if ( V_31 < 0 ) {
F_81 ( V_138 , 0 ) ;
F_81 ( V_140 , 0 ) ;
return V_31 ;
}
#endif
F_28 () ;
F_74 ( V_122 ,
~ 0 , V_142 | V_143 | V_144 | V_145 ) ;
#ifdef F_83
F_74 ( V_146 , ~ 0 , 0 ) ;
#endif
return 0 ;
}
static int T_5 F_84 ( struct V_147 * V_91 )
{
F_85 () ;
F_86 ( & V_45 , F_56 ) ;
if ( F_78 () ) {
F_10 ( L_23 ) ;
return - 1 ;
}
F_28 () ;
V_148 = F_13 ;
F_87 ( V_149 ) ;
V_105 = 1 ;
return 0 ;
}
static int T_6 F_88 ( void )
{
return F_89 ( & V_150 ) ;
}
