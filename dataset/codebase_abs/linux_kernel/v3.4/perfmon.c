static inline void
F_1 ( struct V_1 * V_2 )
{
if ( V_2 != V_3 ) F_2 ( V_2 ) ;
}
static inline void
F_3 ( unsigned long V_4 )
{
F_4 ( F_5 ( ( void * ) V_4 ) ) ;
}
static inline void
F_6 ( unsigned long V_4 )
{
F_7 ( F_5 ( ( void * ) V_4 ) ) ;
}
static inline unsigned long
F_8 ( T_1 * V_5 )
{
F_9 ( & ( V_5 ) -> V_6 ) ;
return 0UL ;
}
static inline void
F_10 ( T_1 * V_5 , unsigned long V_7 )
{
F_11 ( & ( V_5 ) -> V_6 ) ;
}
static inline unsigned long
F_12 ( struct V_8 * V_8 , unsigned long V_9 , unsigned long V_10 , unsigned long V_11 , unsigned long V_12 , unsigned long V_13 )
{
return F_13 ( V_8 , V_9 , V_10 , V_11 , V_12 ) ;
}
static struct V_14 *
F_14 ( struct V_15 * V_16 , int V_12 , const char * V_17 , void * V_18 )
{
return F_15 ( V_16 , L_1 , NULL , & V_19 ,
V_20 ) ;
}
static inline void
F_16 ( void )
{
F_17 ( V_21 ) ;
F_18 () ;
}
static inline void
F_19 ( void )
{
F_20 ( V_21 ) ;
F_18 () ;
}
static inline void
F_21 ( void )
{
F_17 ( V_22 ) ;
F_18 () ;
}
static inline void
F_22 ( void )
{
F_20 ( V_22 ) ;
F_18 () ;
}
static inline unsigned long
F_23 ( void )
{
unsigned long V_23 ;
V_23 = F_24 ( V_24 ) ;
F_18 () ;
return V_23 ;
}
static inline void
F_25 ( unsigned long V_25 )
{
F_26 ( V_26 , V_25 ) ;
F_18 () ;
}
static inline void
F_27 ( void )
{
F_28 ( 0 , 1UL ) ;
F_29 () ;
}
static inline void
F_30 ( void )
{
F_28 ( 0 , 0UL ) ;
F_29 () ;
}
static inline void
F_31 ( unsigned long * V_27 , unsigned int V_28 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
F_32 ( V_29 , V_27 [ V_29 ] ) ;
F_33 () ;
}
F_18 () ;
}
static inline void
F_34 ( unsigned long * V_30 , unsigned int V_31 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
F_35 ( V_29 , V_30 [ V_29 ] ) ;
F_36 () ;
}
F_29 () ;
}
static inline unsigned long
F_37 ( T_1 * V_32 , int V_29 )
{
return V_32 -> V_33 [ V_29 ] . V_25 + ( F_38 ( V_29 ) & V_34 -> V_35 ) ;
}
static inline void
F_39 ( T_1 * V_32 , int V_29 , unsigned long V_25 )
{
unsigned long V_35 = V_34 -> V_35 ;
V_32 -> V_33 [ V_29 ] . V_25 = V_25 & ~ V_35 ;
F_40 ( V_29 , V_25 & V_35 ) ;
}
static T_2 *
F_41 ( T_1 * V_32 )
{
int V_36 , V_37 ;
V_37 = ( V_32 -> V_38 + 1 ) % V_39 ;
F_42 ( ( L_2 , V_32 , V_32 -> V_40 , V_32 -> V_38 ) ) ;
if ( V_37 == V_32 -> V_40 ) return NULL ;
V_36 = V_32 -> V_38 ;
V_32 -> V_38 = V_37 ;
F_42 ( ( L_3 , V_32 , V_32 -> V_40 , V_32 -> V_38 , V_36 ) ) ;
return V_32 -> V_41 + V_36 ;
}
static T_2 *
F_43 ( T_1 * V_32 )
{
T_2 * V_42 ;
F_42 ( ( L_4 , V_32 , V_32 -> V_40 , V_32 -> V_38 ) ) ;
if ( F_44 ( V_32 ) ) return NULL ;
V_42 = V_32 -> V_41 + V_32 -> V_40 ;
V_32 -> V_40 = ( V_32 -> V_40 + 1 ) % V_39 ;
F_42 ( ( L_5 , V_32 , V_32 -> V_40 , V_32 -> V_38 , V_42 -> V_43 . V_44 ) ) ;
return V_42 ;
}
static void
F_45 ( T_1 * V_32 )
{
V_32 -> V_40 = V_32 -> V_38 = 0 ;
F_42 ( ( L_6 , V_32 ) ) ;
}
static void *
F_46 ( unsigned long V_45 )
{
void * V_46 ;
unsigned long V_9 ;
V_45 = F_47 ( V_45 ) ;
V_46 = F_48 ( V_45 ) ;
if ( V_46 ) {
V_9 = ( unsigned long ) V_46 ;
while ( V_45 > 0 ) {
F_3 ( V_9 ) ;
V_9 += V_47 ;
V_45 -= V_47 ;
}
}
return V_46 ;
}
static void
F_49 ( void * V_46 , unsigned long V_45 )
{
unsigned long V_9 ;
if ( V_46 ) {
F_42 ( ( L_7 , V_46 , V_45 ) ) ;
V_9 = ( unsigned long ) V_46 ;
while ( ( long ) V_45 > 0 ) {
F_6 ( V_9 ) ;
V_9 += V_47 ;
V_45 -= V_47 ;
}
F_50 ( V_46 ) ;
}
return;
}
static T_1 *
F_51 ( int V_48 )
{
T_1 * V_32 ;
V_32 = F_52 ( sizeof( T_1 ) , V_49 ) ;
if ( V_32 ) {
F_42 ( ( L_8 , V_32 ) ) ;
F_53 ( & V_32 -> V_6 ) ;
V_32 -> V_50 = V_51 ;
V_32 -> V_52 = ( V_48 & V_53 ) ? 1 : 0 ;
V_32 -> V_54 = ( V_48 & V_55 ) ? 1 : 0 ;
V_32 -> V_56 = ( V_48 & V_57 ) ? 1 : 0 ;
F_54 ( & V_32 -> V_58 ) ;
V_32 -> V_59 = V_60 ;
F_55 ( V_32 , - 1 ) ;
V_32 -> V_40 = V_32 -> V_38 = 0 ;
F_56 ( & V_32 -> V_61 ) ;
F_56 ( & V_32 -> V_62 ) ;
}
return V_32 ;
}
static void
F_57 ( T_1 * V_32 )
{
if ( V_32 ) {
F_42 ( ( L_9 , V_32 ) ) ;
F_58 ( V_32 ) ;
}
}
static void
F_59 ( struct V_1 * V_2 )
{
T_1 * V_32 = F_60 ( V_2 ) ;
unsigned long V_63 , V_25 , V_64 ;
int V_29 ;
F_61 ( ( L_10 , F_62 ( V_2 ) ) ) ;
V_64 = V_34 -> V_35 ;
V_63 = V_32 -> V_65 [ 0 ] ;
for ( V_29 = 0 ; V_63 ; V_29 ++ , V_63 >>= 1 ) {
if ( ( V_63 & 0x1 ) == 0 ) continue;
V_25 = F_38 ( V_29 ) ;
if ( F_63 ( V_29 ) ) {
V_32 -> V_33 [ V_29 ] . V_25 += ( V_25 & V_64 ) ;
} else {
V_32 -> V_33 [ V_29 ] . V_25 = V_25 ;
}
F_61 ( ( L_11 ,
V_29 ,
V_32 -> V_33 [ V_29 ] . V_25 ,
V_25 & V_64 ) ) ;
}
V_63 = V_32 -> V_66 [ 0 ] >> V_67 ;
for( V_29 = V_67 ; V_63 ; V_29 ++ , V_63 >>= 1 ) {
if ( ( V_63 & 0x1 ) == 0UL ) continue;
F_28 ( V_29 , V_32 -> V_68 [ V_29 ] & ~ 0xfUL ) ;
V_32 -> V_68 [ V_29 ] &= ~ 0xfUL ;
F_61 ( ( L_12 , V_29 , V_32 -> V_68 [ V_29 ] ) ) ;
}
F_29 () ;
}
static void
F_64 ( struct V_1 * V_2 )
{
T_1 * V_32 = F_60 ( V_2 ) ;
unsigned long V_63 , V_64 ;
unsigned long V_69 , V_25 ;
int V_29 , V_70 ;
V_70 = V_32 -> V_54 ;
V_64 = V_34 -> V_35 ;
if ( V_2 != V_3 ) {
F_65 ( V_71 L_13 , __LINE__ , F_62 ( V_2 ) , F_62 ( V_3 ) ) ;
return;
}
if ( V_32 -> V_50 != V_72 ) {
F_65 ( V_71 L_14 , __LINE__ ,
F_62 ( V_2 ) , F_62 ( V_3 ) , V_32 -> V_50 ) ;
return;
}
V_69 = F_23 () ;
if ( V_70 && ( F_66 () & V_73 ) ) {
F_26 ( V_74 , F_24 ( V_74 ) & ~ V_75 ) ;
F_16 () ;
} else {
F_21 () ;
}
V_63 = V_32 -> V_65 [ 0 ] ;
for ( V_29 = 0 ; V_63 ; V_29 ++ , V_63 >>= 1 ) {
if ( ( V_63 & 0x1 ) == 0 ) continue;
if ( F_63 ( V_29 ) ) {
V_25 = V_32 -> V_33 [ V_29 ] . V_25 & V_64 ;
V_32 -> V_33 [ V_29 ] . V_25 &= ~ V_64 ;
} else {
V_25 = V_32 -> V_33 [ V_29 ] . V_25 ;
}
F_40 ( V_29 , V_25 ) ;
F_42 ( ( L_11 ,
V_29 ,
V_32 -> V_33 [ V_29 ] . V_25 ,
V_25 ) ) ;
}
V_63 = V_32 -> V_66 [ 0 ] >> V_67 ;
for( V_29 = V_67 ; V_63 ; V_29 ++ , V_63 >>= 1 ) {
if ( ( V_63 & 0x1 ) == 0UL ) continue;
V_32 -> V_68 [ V_29 ] = V_32 -> V_76 [ V_29 ] ;
F_28 ( V_29 , V_32 -> V_68 [ V_29 ] ) ;
F_42 ( ( L_15 ,
F_62 ( V_2 ) , V_29 , V_32 -> V_68 [ V_29 ] ) ) ;
}
F_29 () ;
if ( V_32 -> V_77 ) {
F_31 ( V_32 -> V_78 , V_34 -> V_79 ) ;
F_34 ( V_32 -> V_80 , V_34 -> V_81 ) ;
}
if ( V_70 && ( F_66 () & V_73 ) ) {
F_26 ( V_74 , F_24 ( V_74 ) | V_75 ) ;
F_18 () ;
}
F_25 ( V_69 ) ;
}
static inline void
F_67 ( unsigned long * V_82 , unsigned long V_63 )
{
int V_29 ;
F_29 () ;
for ( V_29 = 0 ; V_63 ; V_29 ++ , V_63 >>= 1 ) {
if ( V_63 & 0x1 ) V_82 [ V_29 ] = F_38 ( V_29 ) ;
}
}
static inline void
F_68 ( unsigned long * V_82 , unsigned long V_63 )
{
int V_29 ;
unsigned long V_25 , V_35 = V_34 -> V_35 ;
for ( V_29 = 0 ; V_63 ; V_29 ++ , V_63 >>= 1 ) {
if ( ( V_63 & 0x1 ) == 0 ) continue;
V_25 = F_63 ( V_29 ) ? V_82 [ V_29 ] & V_35 : V_82 [ V_29 ] ;
F_40 ( V_29 , V_25 ) ;
}
F_29 () ;
}
static inline void
F_69 ( struct V_1 * V_2 , T_1 * V_32 )
{
unsigned long V_35 = V_34 -> V_35 ;
unsigned long V_63 = V_32 -> V_83 [ 0 ] ;
unsigned long V_25 ;
int V_29 ;
F_42 ( ( L_16 , V_63 ) ) ;
for ( V_29 = 0 ; V_63 ; V_29 ++ , V_63 >>= 1 ) {
V_25 = V_32 -> V_33 [ V_29 ] . V_25 ;
if ( F_63 ( V_29 ) ) {
V_32 -> V_33 [ V_29 ] . V_25 = V_25 & ~ V_35 ;
V_25 &= V_35 ;
}
V_32 -> V_84 [ V_29 ] = V_25 ;
F_42 ( ( L_17 ,
V_29 ,
V_32 -> V_84 [ V_29 ] ,
V_32 -> V_33 [ V_29 ] . V_25 ) ) ;
}
}
static inline void
F_70 ( struct V_1 * V_2 , T_1 * V_32 )
{
unsigned long V_63 = V_32 -> V_85 [ 0 ] ;
int V_29 ;
F_42 ( ( L_16 , V_63 ) ) ;
for ( V_29 = 0 ; V_63 ; V_29 ++ , V_63 >>= 1 ) {
V_32 -> V_68 [ V_29 ] = V_32 -> V_76 [ V_29 ] ;
F_42 ( ( L_12 , V_29 , V_32 -> V_68 [ V_29 ] ) ) ;
}
}
static inline void
F_71 ( unsigned long * V_86 , unsigned long V_63 )
{
int V_29 ;
for ( V_29 = 0 ; V_63 ; V_29 ++ , V_63 >>= 1 ) {
if ( ( V_63 & 0x1 ) == 0 ) continue;
F_28 ( V_29 , V_86 [ V_29 ] ) ;
}
F_29 () ;
}
static inline int
F_72 ( T_3 V_4 , T_3 V_87 )
{
return memcmp ( V_4 , V_87 , sizeof( T_3 ) ) ;
}
static inline int
F_73 ( T_4 * V_88 , struct V_1 * V_2 , void * V_89 , struct V_90 * V_91 )
{
int V_92 = 0 ;
if ( V_88 -> V_93 ) V_92 = (* V_88 -> V_93 )( V_2 , V_89 , V_91 ) ;
return V_92 ;
}
static inline int
F_74 ( T_4 * V_88 , struct V_1 * V_2 , unsigned int V_12 , int V_94 , void * V_95 , unsigned long * V_45 )
{
int V_92 = 0 ;
if ( V_88 -> V_96 ) V_92 = (* V_88 -> V_96 )( V_2 , V_12 , V_94 , V_95 , V_45 ) ;
return V_92 ;
}
static inline int
F_75 ( T_4 * V_88 , struct V_1 * V_2 , unsigned int V_12 ,
int V_94 , void * V_95 )
{
int V_92 = 0 ;
if ( V_88 -> V_97 ) V_92 = (* V_88 -> V_97 )( V_2 , V_12 , V_94 , V_95 ) ;
return V_92 ;
}
static inline int
F_76 ( T_4 * V_88 , struct V_1 * V_2 , void * V_89 , unsigned int V_12 ,
int V_94 , void * V_95 )
{
int V_92 = 0 ;
if ( V_88 -> V_98 ) V_92 = (* V_88 -> V_98 )( V_2 , V_89 , V_12 , V_94 , V_95 ) ;
return V_92 ;
}
static inline int
F_77 ( T_4 * V_88 , struct V_1 * V_2 , T_5 * V_99 , void * V_89 , struct V_90 * V_91 )
{
int V_92 = 0 ;
if ( V_88 -> V_100 ) V_92 = (* V_88 -> V_100 )( V_2 , V_99 , V_89 , V_91 ) ;
return V_92 ;
}
static inline int
F_78 ( T_4 * V_88 , struct V_1 * V_2 , T_5 * V_99 , void * V_89 , struct V_90 * V_91 )
{
int V_92 = 0 ;
if ( V_88 -> V_101 ) V_92 = (* V_88 -> V_101 )( V_2 , V_99 , V_89 , V_91 ) ;
return V_92 ;
}
static T_4 *
F_79 ( T_3 V_102 )
{
struct V_103 * V_104 ;
T_4 * V_105 ;
F_80 (pos, &pfm_buffer_fmt_list) {
V_105 = F_81 ( V_104 , T_4 , V_106 ) ;
if ( F_72 ( V_102 , V_105 -> V_107 ) == 0 )
return V_105 ;
}
return NULL ;
}
static T_4 *
F_82 ( T_3 V_102 )
{
T_4 * V_88 ;
F_9 ( & V_108 ) ;
V_88 = F_79 ( V_102 ) ;
F_11 ( & V_108 ) ;
return V_88 ;
}
int
F_83 ( T_4 * V_88 )
{
int V_92 = 0 ;
if ( V_88 == NULL || V_88 -> V_109 == NULL ) return - V_110 ;
if ( V_88 -> V_111 == NULL ) return - V_110 ;
F_9 ( & V_108 ) ;
if ( F_79 ( V_88 -> V_107 ) ) {
F_65 ( V_71 L_18 , V_88 -> V_109 ) ;
V_92 = - V_112 ;
goto V_113;
}
F_84 ( & V_88 -> V_106 , & V_114 ) ;
F_65 ( V_115 L_19 , V_88 -> V_109 ) ;
V_113:
F_11 ( & V_108 ) ;
return V_92 ;
}
int
F_85 ( T_3 V_102 )
{
T_4 * V_88 ;
int V_92 = 0 ;
F_9 ( & V_108 ) ;
V_88 = F_79 ( V_102 ) ;
if ( ! V_88 ) {
F_65 ( V_71 L_20 ) ;
V_92 = - V_110 ;
goto V_113;
}
F_86 ( & V_88 -> V_106 ) ;
F_65 ( V_115 L_21 , V_88 -> V_109 ) ;
V_113:
F_11 ( & V_108 ) ;
return V_92 ;
}
static int
F_87 ( struct V_1 * V_2 , int V_116 , unsigned int V_94 )
{
unsigned long V_12 ;
F_88 ( V_12 ) ;
F_42 ( ( L_22 ,
V_117 . V_118 ,
V_117 . V_119 ,
V_117 . V_120 ,
V_116 ,
V_94 ) ) ;
if ( V_116 ) {
if ( V_117 . V_119 > 0UL ) {
F_42 ( ( L_23 ,
V_117 . V_119 ) ) ;
goto abort;
}
if ( V_117 . V_121 [ V_94 ] ) goto V_122;
F_42 ( ( L_24 , V_94 , F_89 () ) ) ;
V_117 . V_121 [ V_94 ] = V_2 ;
V_117 . V_118 ++ ;
} else {
if ( V_117 . V_118 ) goto abort;
V_117 . V_119 ++ ;
}
F_42 ( ( L_25 ,
V_117 . V_118 ,
V_117 . V_119 ,
V_117 . V_120 ,
V_116 ,
V_94 ) ) ;
F_90 ( 0 ) ;
F_91 ( V_12 ) ;
return 0 ;
V_122:
F_42 ( ( L_26 ,
F_62 ( V_117 . V_121 [ V_94 ] ) ,
V_94 ) ) ;
abort:
F_91 ( V_12 ) ;
return - V_112 ;
}
static int
F_92 ( T_1 * V_32 , int V_116 , unsigned int V_94 )
{
unsigned long V_12 ;
F_88 ( V_12 ) ;
F_42 ( ( L_22 ,
V_117 . V_118 ,
V_117 . V_119 ,
V_117 . V_120 ,
V_116 ,
V_94 ) ) ;
if ( V_116 ) {
V_117 . V_121 [ V_94 ] = NULL ;
if ( V_32 && V_32 -> V_77 ) {
if ( V_117 . V_120 == 0 ) {
F_65 ( V_71 L_27 , V_32 ) ;
} else {
V_117 . V_120 -- ;
}
}
V_117 . V_118 -- ;
} else {
V_117 . V_119 -- ;
}
F_42 ( ( L_25 ,
V_117 . V_118 ,
V_117 . V_119 ,
V_117 . V_120 ,
V_116 ,
V_94 ) ) ;
if ( V_117 . V_119 == 0 && V_117 . V_118 == 0 )
F_90 ( 1 ) ;
F_91 ( V_12 ) ;
return 0 ;
}
static int
F_93 ( void * V_123 , unsigned long V_45 )
{
struct V_1 * V_2 = V_3 ;
int V_124 ;
if ( V_2 -> V_125 == NULL || V_45 == 0UL || V_123 == NULL ) {
F_65 ( V_71 L_28 , F_62 ( V_2 ) , V_2 -> V_125 ) ;
return - V_110 ;
}
F_42 ( ( L_29 , V_123 , V_45 ) ) ;
V_124 = F_94 ( ( unsigned long ) V_123 , V_45 ) ;
if ( V_124 != 0 ) {
F_65 ( V_71 L_30 , F_62 ( V_2 ) , V_123 , V_45 ) ;
}
F_42 ( ( L_31 , V_123 , V_45 , V_124 ) ) ;
return 0 ;
}
static inline void
F_95 ( T_4 * V_88 )
{
if ( V_88 == NULL ) return;
F_73 ( V_88 , V_3 , NULL , NULL ) ;
}
static int T_6
F_96 ( void )
{
int V_126 = F_97 ( & V_127 ) ;
if ( ! V_126 ) {
V_128 = F_98 ( & V_127 ) ;
V_126 = F_99 ( V_128 ) ;
if ( F_100 ( V_128 ) )
F_101 ( & V_127 ) ;
else
V_126 = 0 ;
}
return V_126 ;
}
static T_7
F_102 ( struct V_8 * V_129 , char T_8 * V_89 , T_9 V_45 , T_10 * V_130 )
{
T_1 * V_32 ;
T_2 * V_42 ;
T_7 V_92 ;
unsigned long V_12 ;
F_103 ( V_131 , V_3 ) ;
if ( F_104 ( V_129 ) == 0 ) {
F_65 ( V_71 L_32 , F_62 ( V_3 ) ) ;
return - V_110 ;
}
V_32 = V_129 -> V_132 ;
if ( V_32 == NULL ) {
F_65 ( V_71 L_33 , F_62 ( V_3 ) ) ;
return - V_110 ;
}
if ( V_45 < sizeof( T_2 ) ) {
F_42 ( ( L_34 , V_32 , sizeof( T_2 ) ) ) ;
return - V_110 ;
}
F_105 ( V_32 , V_12 ) ;
F_106 ( & V_32 -> V_61 , & V_131 ) ;
for(; ; ) {
F_107 ( V_133 ) ;
F_42 ( ( L_35 , V_32 -> V_40 , V_32 -> V_38 ) ) ;
V_92 = 0 ;
if( F_44 ( V_32 ) == 0 ) break;
F_108 ( V_32 , V_12 ) ;
V_92 = - V_134 ;
if( V_129 -> V_135 & V_136 ) break;
if( F_109 ( V_3 ) ) {
V_92 = - V_137 ;
break;
}
F_110 () ;
F_105 ( V_32 , V_12 ) ;
}
F_42 ( ( L_36 , F_62 ( V_3 ) , V_92 ) ) ;
F_107 ( V_138 ) ;
F_111 ( & V_32 -> V_61 , & V_131 ) ;
if ( V_92 < 0 ) goto abort;
V_92 = - V_110 ;
V_42 = F_43 ( V_32 ) ;
if ( V_42 == NULL ) {
F_65 ( V_71 L_37 , V_32 , F_62 ( V_3 ) ) ;
goto V_139;
}
F_42 ( ( L_38 , V_42 -> V_43 . V_140 , V_42 -> V_43 . V_44 ) ) ;
V_92 = - V_141 ;
if( F_112 ( V_89 , V_42 , sizeof( T_2 ) ) == 0 ) V_92 = sizeof( T_2 ) ;
V_139:
F_108 ( V_32 , V_12 ) ;
abort:
return V_92 ;
}
static T_7
F_113 ( struct V_8 * V_8 , const char T_8 * V_142 ,
T_9 V_45 , T_10 * V_130 )
{
F_42 ( ( L_39 ) ) ;
return - V_110 ;
}
static unsigned int
F_114 ( struct V_8 * V_129 , T_11 * V_131 )
{
T_1 * V_32 ;
unsigned long V_12 ;
unsigned int V_63 = 0 ;
if ( F_104 ( V_129 ) == 0 ) {
F_65 ( V_71 L_32 , F_62 ( V_3 ) ) ;
return 0 ;
}
V_32 = V_129 -> V_132 ;
if ( V_32 == NULL ) {
F_65 ( V_71 L_40 , F_62 ( V_3 ) ) ;
return 0 ;
}
F_42 ( ( L_41 , V_32 -> V_143 ) ) ;
F_115 ( V_129 , & V_32 -> V_61 , V_131 ) ;
F_105 ( V_32 , V_12 ) ;
if ( F_44 ( V_32 ) == 0 )
V_63 = V_144 | V_145 ;
F_108 ( V_32 , V_12 ) ;
F_42 ( ( L_42 , V_32 -> V_143 , V_63 ) ) ;
return V_63 ;
}
static long
F_116 ( struct V_8 * V_8 , unsigned int V_146 , unsigned long V_95 )
{
F_42 ( ( L_43 ) ) ;
return - V_110 ;
}
static inline int
F_117 ( int V_147 , struct V_8 * V_129 , T_1 * V_32 , int V_148 )
{
int V_92 ;
V_92 = F_118 ( V_147 , V_129 , V_148 , & V_32 -> V_149 ) ;
F_42 ( ( L_44 ,
F_62 ( V_3 ) ,
V_147 ,
V_148 ,
V_32 -> V_149 , V_92 ) ) ;
return V_92 ;
}
static int
F_119 ( int V_147 , struct V_8 * V_129 , int V_148 )
{
T_1 * V_32 ;
int V_92 ;
if ( F_104 ( V_129 ) == 0 ) {
F_65 ( V_71 L_45 , F_62 ( V_3 ) ) ;
return - V_150 ;
}
V_32 = V_129 -> V_132 ;
if ( V_32 == NULL ) {
F_65 ( V_71 L_46 , F_62 ( V_3 ) ) ;
return - V_150 ;
}
V_92 = F_117 ( V_147 , V_129 , V_32 , V_148 ) ;
F_42 ( ( L_47 ,
V_147 ,
V_148 ,
V_32 -> V_149 , V_92 ) ) ;
return V_92 ;
}
static void
F_120 ( void * V_151 )
{
T_1 * V_32 = ( T_1 * ) V_151 ;
struct V_90 * V_91 = F_121 ( V_3 ) ;
struct V_1 * V_152 ;
unsigned long V_12 ;
int V_92 ;
if ( V_32 -> V_153 != F_89 () ) {
F_65 ( V_71 L_48 ,
V_32 -> V_153 ,
F_89 () ) ;
return;
}
V_152 = F_122 () ;
if ( V_152 != V_32 -> V_154 ) {
F_65 ( V_71 L_49 ,
F_89 () ,
F_62 ( V_152 ) , F_62 ( V_32 -> V_154 ) ) ;
return;
}
if ( F_123 () != V_32 ) {
F_65 ( V_71 L_50 ,
F_89 () ,
F_123 () , V_32 ) ;
return;
}
F_42 ( ( L_51 , F_89 () , F_62 ( V_32 -> V_154 ) ) ) ;
F_124 ( V_12 ) ;
V_92 = F_125 ( V_32 , NULL , 0 , V_91 ) ;
if ( V_92 ) {
F_42 ( ( L_52 , V_92 ) ) ;
}
F_126 ( V_12 ) ;
}
static void
F_127 ( T_1 * V_32 )
{
int V_92 ;
F_42 ( ( L_53 , V_32 -> V_153 ) ) ;
V_92 = F_128 ( V_32 -> V_153 , F_120 , V_32 , 1 ) ;
F_42 ( ( L_54 , V_32 -> V_153 , V_92 ) ) ;
}
static int
F_129 ( struct V_8 * V_129 , T_12 V_155 )
{
T_1 * V_32 ;
struct V_1 * V_2 ;
struct V_90 * V_91 ;
unsigned long V_12 ;
unsigned long V_156 = 0UL ;
void * V_157 = NULL ;
int V_158 , V_70 ;
if ( F_104 ( V_129 ) == 0 ) {
F_42 ( ( L_55 ) ) ;
return - V_150 ;
}
V_32 = V_129 -> V_132 ;
if ( V_32 == NULL ) {
F_65 ( V_71 L_56 , F_62 ( V_3 ) ) ;
return - V_150 ;
}
F_105 ( V_32 , V_12 ) ;
V_158 = V_32 -> V_50 ;
V_70 = V_32 -> V_54 ;
V_2 = F_130 ( V_32 ) ;
V_91 = F_121 ( V_2 ) ;
F_42 ( ( L_57 ,
V_158 ,
V_2 == V_3 ? 1 : 0 ) ) ;
if ( V_2 == V_3 ) {
#ifdef F_131
if ( V_70 && V_32 -> V_153 != F_89 () ) {
F_42 ( ( L_58 , V_32 -> V_153 ) ) ;
F_126 ( V_12 ) ;
F_127 ( V_32 ) ;
F_124 ( V_12 ) ;
} else
#endif
{
F_42 ( ( L_59 ) ) ;
F_125 ( V_32 , NULL , 0 , V_91 ) ;
F_42 ( ( L_60 , V_32 -> V_50 ) ) ;
}
}
if ( V_32 -> V_159 && V_3 -> V_125 ) {
V_157 = V_32 -> V_159 ;
V_156 = V_32 -> V_160 ;
}
F_108 ( V_32 , V_12 ) ;
if ( V_157 ) F_93 ( V_157 , V_156 ) ;
return 0 ;
}
static int
F_132 ( struct V_161 * V_161 , struct V_8 * V_129 )
{
T_1 * V_32 ;
struct V_1 * V_2 ;
struct V_90 * V_91 ;
F_103 ( V_131 , V_3 ) ;
unsigned long V_12 ;
unsigned long V_156 = 0UL ;
void * V_162 = NULL ;
int V_163 = 1 ;
int V_158 , V_70 ;
F_42 ( ( L_61 , V_129 -> V_132 ) ) ;
if ( F_104 ( V_129 ) == 0 ) {
F_42 ( ( L_62 ) ) ;
return - V_150 ;
}
V_32 = V_129 -> V_132 ;
if ( V_32 == NULL ) {
F_65 ( V_71 L_63 , F_62 ( V_3 ) ) ;
return - V_150 ;
}
F_105 ( V_32 , V_12 ) ;
V_158 = V_32 -> V_50 ;
V_70 = V_32 -> V_54 ;
V_2 = F_130 ( V_32 ) ;
V_91 = F_121 ( V_2 ) ;
F_42 ( ( L_57 ,
V_158 ,
V_2 == V_3 ? 1 : 0 ) ) ;
if ( V_158 == V_51 ) goto V_164;
if ( V_158 == V_72 && F_133 ( V_32 ) == 0 ) {
V_32 -> V_165 = 1 ;
F_134 ( & V_32 -> V_58 ) ;
F_42 ( ( L_64 , V_158 ) ) ;
F_107 ( V_133 ) ;
F_106 ( & V_32 -> V_62 , & V_131 ) ;
F_108 ( V_32 , V_12 ) ;
F_110 () ;
F_105 ( V_32 , V_12 ) ;
F_111 ( & V_32 -> V_62 , & V_131 ) ;
F_107 ( V_138 ) ;
F_42 ( ( L_65 , V_158 ) ) ;
}
else if ( V_2 != V_3 ) {
#ifdef F_131
V_32 -> V_50 = V_166 ;
F_42 ( ( L_66 , F_62 ( V_2 ) ) ) ;
V_163 = 0 ;
#else
F_125 ( V_32 , NULL , 0 , V_91 ) ;
#endif
}
V_164:
V_158 = V_32 -> V_50 ;
if ( V_32 -> V_167 ) {
V_162 = V_32 -> V_167 ;
V_156 = V_32 -> V_160 ;
V_32 -> V_167 = NULL ;
V_32 -> V_168 = 0 ;
}
F_42 ( ( L_67 ,
V_158 ,
V_163 ,
V_162 ,
V_156 ) ) ;
if ( V_162 ) F_95 ( V_32 -> V_169 ) ;
if ( V_158 == V_166 ) {
F_92 ( V_32 , V_32 -> V_54 , V_32 -> V_153 ) ;
}
V_129 -> V_132 = NULL ;
F_108 ( V_32 , V_12 ) ;
if ( V_162 ) F_49 ( V_162 , V_156 ) ;
if ( V_163 ) F_57 ( V_32 ) ;
return 0 ;
}
static int
F_135 ( struct V_161 * V_170 , struct V_8 * V_171 )
{
F_42 ( ( L_68 ) ) ;
return - V_172 ;
}
static int
F_136 ( const struct V_14 * V_14 )
{
return 1 ;
}
static char * F_137 ( struct V_14 * V_14 , char * V_173 , int V_174 )
{
return F_138 ( V_14 , V_173 , V_174 , L_69 ,
V_14 -> V_175 -> V_176 ) ;
}
static struct V_8 *
F_139 ( T_1 * V_32 )
{
struct V_8 * V_8 ;
struct V_161 * V_161 ;
struct V_177 V_177 ;
struct V_178 V_179 = { . V_180 = L_70 } ;
V_161 = F_140 ( V_128 -> V_181 ) ;
if ( ! V_161 )
return F_141 ( - V_182 ) ;
F_42 ( ( L_71 , V_161 -> V_176 , V_161 ) ) ;
V_161 -> V_183 = V_184 | V_185 ;
V_161 -> V_186 = F_142 () ;
V_161 -> V_187 = F_143 () ;
V_177 . V_14 = F_144 ( V_128 -> V_188 , & V_179 ) ;
if ( ! V_177 . V_14 ) {
F_145 ( V_161 ) ;
return F_141 ( - V_182 ) ;
}
V_177 . V_189 = F_146 ( V_128 ) ;
F_147 ( V_177 . V_14 , V_161 ) ;
V_8 = F_148 ( & V_177 , V_190 , & V_191 ) ;
if ( ! V_8 ) {
F_149 ( & V_177 ) ;
return F_141 ( - V_192 ) ;
}
V_8 -> V_135 = V_193 ;
V_8 -> V_132 = V_32 ;
return V_8 ;
}
static int
F_150 ( struct V_194 * V_195 , unsigned long V_89 , unsigned long V_9 , unsigned long V_45 )
{
F_42 ( ( L_72 , F_89 () , V_89 , V_9 , V_45 ) ) ;
while ( V_45 > 0 ) {
unsigned long V_196 = F_151 ( V_89 ) >> V_197 ;
if ( F_152 ( V_195 , V_9 , V_196 , V_47 , V_198 ) )
return - V_182 ;
V_9 += V_47 ;
V_89 += V_47 ;
V_45 -= V_47 ;
}
return 0 ;
}
static int
F_153 ( struct V_1 * V_2 , struct V_8 * V_129 , T_1 * V_32 , unsigned long V_199 , void * * V_200 )
{
struct V_201 * V_125 = V_2 -> V_125 ;
struct V_194 * V_195 = NULL ;
unsigned long V_45 ;
void * V_202 ;
V_45 = F_47 ( V_199 ) ;
F_42 ( ( L_73 , V_199 , V_45 ) ) ;
if ( V_45 > F_154 ( V_2 , V_203 ) )
return - V_182 ;
V_202 = F_46 ( V_45 ) ;
if ( V_202 == NULL ) {
F_42 ( ( L_74 ) ) ;
return - V_182 ;
}
F_42 ( ( L_75 , V_202 ) ) ;
V_195 = F_155 ( V_204 , V_49 ) ;
if ( ! V_195 ) {
F_42 ( ( L_76 ) ) ;
goto V_205;
}
F_156 ( & V_195 -> V_206 ) ;
V_195 -> V_207 = V_125 ;
V_195 -> V_208 = V_129 ;
V_195 -> V_209 = V_210 | V_211 | V_212 ;
V_195 -> V_213 = V_198 ;
V_32 -> V_167 = V_202 ;
V_32 -> V_160 = V_45 ;
F_157 ( & V_2 -> V_125 -> V_214 ) ;
V_195 -> V_215 = F_12 ( NULL , 0 , V_45 , 0 , V_216 | V_217 , 0 ) ;
if ( V_195 -> V_215 == 0UL ) {
F_42 ( ( L_77 , V_45 ) ) ;
F_158 ( & V_2 -> V_125 -> V_214 ) ;
goto error;
}
V_195 -> V_218 = V_195 -> V_215 + V_45 ;
V_195 -> V_219 = V_195 -> V_215 >> V_197 ;
F_42 ( ( L_78 , V_45 , V_32 -> V_167 , V_195 -> V_215 ) ) ;
if ( F_150 ( V_195 , ( unsigned long ) V_202 , V_195 -> V_215 , V_45 ) ) {
F_42 ( ( L_79 ) ) ;
F_158 ( & V_2 -> V_125 -> V_214 ) ;
goto error;
}
F_159 ( V_129 ) ;
F_160 ( V_125 , V_195 ) ;
V_125 -> V_220 += V_45 >> V_197 ;
F_161 ( V_195 -> V_207 , V_195 -> V_209 , V_195 -> V_208 ,
F_162 ( V_195 ) ) ;
F_158 ( & V_2 -> V_125 -> V_214 ) ;
V_32 -> V_159 = ( void * ) V_195 -> V_215 ;
* ( unsigned long * ) V_200 = V_195 -> V_215 ;
return 0 ;
error:
F_163 ( V_204 , V_195 ) ;
V_205:
F_49 ( V_202 , V_45 ) ;
return - V_182 ;
}
static int
F_164 ( struct V_1 * V_2 )
{
const struct V_221 * V_222 ;
T_13 V_223 = F_165 () ;
T_14 V_224 = F_166 () ;
int V_92 ;
F_167 () ;
V_222 = F_168 ( V_2 ) ;
F_42 ( ( L_80 ,
V_223 ,
V_224 ,
V_222 -> V_225 ,
V_222 -> V_226 ,
V_222 -> V_223 ,
V_222 -> V_227 ,
V_222 -> V_228 ) ) ;
V_92 = ( ( V_223 != V_222 -> V_225 )
|| ( V_223 != V_222 -> V_226 )
|| ( V_223 != V_222 -> V_223 )
|| ( V_224 != V_222 -> V_227 )
|| ( V_224 != V_222 -> V_228 )
|| ( V_224 != V_222 -> V_224 ) ) && ! F_169 ( V_229 ) ;
F_170 () ;
return V_92 ;
}
static int
F_171 ( struct V_1 * V_2 , T_15 * V_230 )
{
int V_48 ;
V_48 = V_230 -> V_48 ;
if ( V_48 & V_55 ) {
if ( V_48 & V_53 ) {
F_42 ( ( L_81 ) ) ;
return - V_110 ;
}
} else {
}
return 0 ;
}
static int
F_172 ( struct V_1 * V_2 , struct V_8 * V_129 , T_1 * V_32 , unsigned int V_48 ,
unsigned int V_94 , T_15 * V_95 )
{
T_4 * V_88 = NULL ;
unsigned long V_45 = 0UL ;
void * V_231 = NULL ;
void * V_232 = NULL ;
int V_92 = 0 ;
#define F_173 ( V_4 ) (pfm_buffer_fmt_t *)(a+1)
V_88 = F_82 ( V_95 -> V_233 ) ;
if ( V_88 == NULL ) {
F_42 ( ( L_82 , F_62 ( V_2 ) ) ) ;
return - V_110 ;
}
if ( V_88 -> V_234 ) V_232 = F_173 ( V_95 ) ;
V_92 = F_75 ( V_88 , V_2 , V_48 , V_94 , V_232 ) ;
F_42 ( ( L_83 , F_62 ( V_2 ) , V_48 , V_94 , V_232 , V_92 ) ) ;
if ( V_92 ) goto error;
V_32 -> V_169 = V_88 ;
V_32 -> V_168 = 1 ;
V_92 = F_74 ( V_88 , V_2 , V_48 , V_94 , V_232 , & V_45 ) ;
if ( V_92 ) goto error;
if ( V_45 ) {
V_92 = F_153 ( V_3 , V_129 , V_32 , V_45 , & V_231 ) ;
if ( V_92 ) goto error;
V_95 -> V_159 = V_231 ;
}
V_92 = F_76 ( V_88 , V_2 , V_32 -> V_167 , V_48 , V_94 , V_232 ) ;
error:
return V_92 ;
}
static void
F_174 ( T_1 * V_32 )
{
int V_29 ;
for ( V_29 = 1 ; F_175 ( V_29 ) == 0 ; V_29 ++ ) {
if ( F_176 ( V_29 ) == 0 ) continue;
V_32 -> V_76 [ V_29 ] = F_177 ( V_29 ) ;
F_42 ( ( L_12 , V_29 , V_32 -> V_76 [ V_29 ] ) ) ;
}
V_32 -> V_85 [ 0 ] = V_34 -> V_235 [ 0 ] & ~ 0x1 ;
V_32 -> V_83 [ 0 ] = V_34 -> V_236 [ 0 ] ;
F_42 ( ( L_84 , V_32 -> V_143 , V_32 -> V_85 [ 0 ] , V_32 -> V_83 [ 0 ] ) ) ;
V_32 -> V_237 [ 0 ] = 0UL ;
V_32 -> V_238 [ 0 ] = 0UL ;
}
static int
F_178 ( void * V_95 , T_9 * V_239 )
{
T_15 * V_240 = ( T_15 * ) V_95 ;
T_4 * V_88 ;
* V_239 = 0 ;
if ( ! F_72 ( V_240 -> V_233 , V_241 ) ) return 0 ;
V_88 = F_82 ( V_240 -> V_233 ) ;
if ( V_88 == NULL ) {
F_42 ( ( L_85 ) ) ;
return - V_110 ;
}
* V_239 = V_88 -> V_234 ;
F_42 ( ( L_86 , * V_239 ) ) ;
return 0 ;
}
static int
F_179 ( T_1 * V_32 , struct V_1 * V_2 )
{
if ( V_2 -> V_125 == NULL ) {
F_42 ( ( L_87 , F_62 ( V_2 ) ) ) ;
return - V_242 ;
}
if ( F_164 ( V_2 ) ) {
F_42 ( ( L_88 , F_62 ( V_2 ) ) ) ;
return - V_242 ;
}
if ( F_133 ( V_32 ) == 0 && V_2 == V_3 ) {
F_42 ( ( L_89 , F_62 ( V_2 ) ) ) ;
return - V_110 ;
}
if ( V_2 -> V_243 == V_244 ) {
F_42 ( ( L_90 , F_62 ( V_2 ) ) ) ;
return - V_112 ;
}
if ( V_2 == V_3 ) return 0 ;
if ( ! F_180 ( V_2 ) ) {
F_42 ( ( L_91 , F_62 ( V_2 ) , V_2 -> V_158 ) ) ;
return - V_112 ;
}
F_181 ( V_2 , 0 ) ;
return 0 ;
}
static int
F_182 ( T_1 * V_32 , T_16 V_245 , struct V_1 * * V_2 )
{
struct V_1 * V_246 = V_3 ;
int V_92 ;
if ( V_245 < 2 ) return - V_242 ;
if ( V_245 != F_183 ( V_3 ) ) {
F_184 ( & V_247 ) ;
V_246 = F_185 ( V_245 ) ;
if ( V_246 ) F_186 ( V_246 ) ;
F_187 ( & V_247 ) ;
if ( V_246 == NULL ) return - V_248 ;
}
V_92 = F_179 ( V_32 , V_246 ) ;
if ( V_92 == 0 ) {
* V_2 = V_246 ;
} else if ( V_246 != V_3 ) {
F_1 ( V_246 ) ;
}
return V_92 ;
}
static int
F_188 ( T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 )
{
T_15 * V_240 = ( T_15 * ) V_95 ;
struct V_8 * V_129 ;
struct V_177 V_177 ;
int V_48 ;
int V_147 ;
int V_92 ;
V_92 = F_171 ( V_3 , V_240 ) ;
if ( V_92 < 0 )
return V_92 ;
V_48 = V_240 -> V_48 ;
V_92 = - V_182 ;
V_147 = F_189 () ;
if ( V_147 < 0 )
return V_147 ;
V_32 = F_51 ( V_48 ) ;
if ( ! V_32 )
goto error;
V_129 = F_139 ( V_32 ) ;
if ( F_100 ( V_129 ) ) {
V_92 = F_99 ( V_129 ) ;
goto V_250;
}
V_240 -> V_143 = V_32 -> V_143 = V_147 ;
if ( F_72 ( V_240 -> V_233 , V_241 ) ) {
V_92 = F_172 ( V_3 , V_129 , V_32 , V_48 , 0 , V_240 ) ;
if ( V_92 )
goto V_251;
}
F_42 ( ( L_92 ,
V_32 ,
V_48 ,
V_32 -> V_54 ,
V_32 -> V_52 ,
V_32 -> V_252 ,
V_32 -> V_56 ,
V_32 -> V_143 ) ) ;
F_174 ( V_32 ) ;
F_190 ( V_147 , V_129 ) ;
return 0 ;
V_251:
V_177 = V_129 -> V_253 ;
F_191 ( V_129 ) ;
F_149 ( & V_177 ) ;
if ( V_32 -> V_169 ) {
F_73 ( V_32 -> V_169 , V_3 , NULL , V_91 ) ;
}
V_250:
F_57 ( V_32 ) ;
error:
F_192 ( V_147 ) ;
return V_92 ;
}
static inline unsigned long
F_193 ( T_17 * V_254 , int V_255 )
{
unsigned long V_25 = V_255 ? V_254 -> V_256 : V_254 -> V_257 ;
unsigned long V_258 , V_259 = V_254 -> V_260 , V_63 = V_254 -> V_63 ;
extern unsigned long V_261 ( unsigned long V_260 ) ;
if ( V_254 -> V_12 & V_262 ) {
V_258 = V_261 ( V_259 ) ;
V_25 -= ( V_259 & V_63 ) ;
if ( ( V_63 >> 32 ) != 0 )
V_258 |= V_261 ( V_259 >> 32 ) << 32 ;
V_254 -> V_260 = V_258 ;
}
V_254 -> V_263 = V_25 ;
return V_25 ;
}
static void
F_194 ( T_1 * V_32 , unsigned long * V_264 , int V_255 )
{
unsigned long V_63 = V_264 [ 0 ] ;
unsigned long V_265 = 0UL ;
unsigned long V_25 ;
int V_29 ;
V_63 >>= V_67 ;
for( V_29 = V_67 ; V_63 ; V_29 ++ , V_63 >>= 1 ) {
if ( ( V_63 & 0x1UL ) == 0UL ) continue;
V_32 -> V_33 [ V_29 ] . V_25 = V_25 = F_193 ( V_32 -> V_33 + V_29 , V_255 ) ;
V_265 |= V_32 -> V_33 [ V_29 ] . V_266 [ 0 ] ;
F_61 ( ( L_93 , V_255 ? L_94 : L_95 , V_29 , V_25 ) ) ;
}
for( V_29 = 0 ; V_265 ; V_29 ++ , V_265 >>= 1 ) {
if ( ( V_265 & 0x1 ) == 0 ) continue;
V_32 -> V_33 [ V_29 ] . V_25 = V_25 = F_193 ( V_32 -> V_33 + V_29 , V_255 ) ;
F_61 ( ( L_96 ,
V_255 ? L_94 : L_95 , V_29 , V_25 ) ) ;
}
}
static void
F_195 ( T_1 * V_32 , unsigned long * V_264 , int V_255 )
{
unsigned long V_63 = V_264 [ 0 ] ;
unsigned long V_265 = 0UL ;
unsigned long V_25 ;
int V_29 ;
F_61 ( ( L_97 , V_264 [ 0 ] , V_255 ) ) ;
if ( V_32 -> V_50 == V_72 ) {
F_194 ( V_32 , V_264 , V_255 ) ;
return;
}
V_63 >>= V_67 ;
for( V_29 = V_67 ; V_63 ; V_29 ++ , V_63 >>= 1 ) {
if ( ( V_63 & 0x1UL ) == 0UL ) continue;
V_25 = F_193 ( V_32 -> V_33 + V_29 , V_255 ) ;
V_265 |= V_32 -> V_33 [ V_29 ] . V_266 [ 0 ] ;
F_61 ( ( L_93 , V_255 ? L_94 : L_95 , V_29 , V_25 ) ) ;
F_39 ( V_32 , V_29 , V_25 ) ;
}
for( V_29 = 0 ; V_265 ; V_29 ++ , V_265 >>= 1 ) {
if ( ( V_265 & 0x1 ) == 0 ) continue;
V_25 = F_193 ( V_32 -> V_33 + V_29 , V_255 ) ;
if ( F_63 ( V_29 ) ) {
F_39 ( V_32 , V_29 , V_25 ) ;
} else {
F_40 ( V_29 , V_25 ) ;
}
F_61 ( ( L_96 ,
V_255 ? L_94 : L_95 , V_29 , V_25 ) ) ;
}
F_29 () ;
}
static int
F_196 ( T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 )
{
struct V_1 * V_2 ;
T_18 * V_240 = ( T_18 * ) V_95 ;
unsigned long V_267 , V_268 ;
unsigned long V_269 , V_266 , V_236 ;
unsigned int V_270 , V_271 , V_12 , V_272 ;
int V_29 , V_273 = 0 , V_274 , V_70 , V_275 ;
int V_276 , V_277 , V_158 ;
int V_92 = - V_110 ;
T_19 V_278 ;
#define F_197 ( V_5 , T_20 , T_21 ) ((x)->ctx_fl_system ^ PMC_PM(y, z))
V_158 = V_32 -> V_50 ;
V_274 = V_158 == V_279 ? 1 : 0 ;
V_70 = V_32 -> V_54 ;
V_2 = V_32 -> V_154 ;
V_236 = V_34 -> V_236 [ 0 ] ;
if ( V_158 == V_166 ) return - V_110 ;
if ( V_274 ) {
if ( V_70 && V_32 -> V_153 != F_89 () ) {
F_42 ( ( L_58 , V_32 -> V_153 ) ) ;
return - V_112 ;
}
V_273 = F_122 () == V_2 || V_70 ? 1 : 0 ;
}
V_275 = V_280 . V_275 ;
for ( V_29 = 0 ; V_29 < V_249 ; V_29 ++ , V_240 ++ ) {
V_270 = V_240 -> V_281 ;
V_271 = V_240 -> V_271 ;
V_267 = V_240 -> V_282 ;
V_269 = V_240 -> V_283 [ 0 ] ;
V_266 = V_240 -> V_284 [ 0 ] ;
V_12 = 0 ;
if ( V_270 >= V_285 ) {
F_42 ( ( L_98 , V_270 ) ) ;
goto error;
}
V_272 = V_34 -> V_286 [ V_270 ] . type ;
V_268 = ( V_267 >> V_34 -> V_286 [ V_270 ] . V_287 ) & 0x1 ;
V_277 = ( V_272 & V_288 ) == V_288 ? 1 : 0 ;
V_276 = ( V_272 & V_289 ) == V_289 ? 1 : 0 ;
if ( ( V_272 & V_290 ) == 0 || ( V_272 & V_291 ) == V_291 ) {
F_42 ( ( L_99 , V_270 , V_272 ) ) ;
goto error;
}
V_278 = V_34 -> V_286 [ V_270 ] . V_292 ;
if ( V_276 && V_267 != F_177 ( V_270 ) && V_70 ^ V_268 ) {
F_42 ( ( L_100 ,
V_270 ,
V_268 ,
V_70 ) ) ;
goto error;
}
if ( V_277 ) {
V_267 |= 1 << V_293 ;
if ( V_271 & V_294 ) {
V_12 |= V_294 ;
}
if ( V_271 & V_262 ) V_12 |= V_262 ;
if ( ( V_269 & V_236 ) != V_269 ) {
F_42 ( ( L_101 , V_269 , V_270 ) ) ;
goto error;
}
if ( ( V_266 & V_236 ) != V_266 ) {
F_42 ( ( L_102 , V_266 , V_270 ) ) ;
goto error;
}
} else {
if ( V_271 & ( V_294 | V_262 ) ) {
F_42 ( ( L_103 , V_270 ) ) ;
goto error;
}
}
if ( F_198 ( V_275 == 0 && V_278 ) ) {
V_92 = (* V_278)( V_2 , V_32 , V_270 , & V_267 , V_91 ) ;
if ( V_92 ) goto error;
V_92 = - V_110 ;
}
F_199 ( V_240 -> V_271 , 0 ) ;
if ( V_277 ) {
V_32 -> V_33 [ V_270 ] . V_12 = V_12 ;
V_32 -> V_33 [ V_270 ] . V_266 [ 0 ] = V_266 ;
V_32 -> V_33 [ V_270 ] . V_269 [ 0 ] = V_269 ;
V_32 -> V_33 [ V_270 ] . V_295 = V_240 -> V_296 ;
F_200 ( V_32 , V_266 ) ;
F_200 ( V_32 , V_269 ) ;
if ( V_158 == V_72 ) V_32 -> V_297 [ 0 ] &= ~ 1UL << V_270 ;
}
F_200 ( V_32 , V_34 -> V_286 [ V_270 ] . V_298 [ 0 ] ) ;
if ( V_276 ) F_201 ( V_32 , 1UL << V_270 ) ;
V_32 -> V_76 [ V_270 ] = V_267 ;
if ( V_274 ) {
if ( V_70 == 0 ) V_32 -> V_68 [ V_270 ] = V_267 ;
if ( V_273 ) {
F_28 ( V_270 , V_267 ) ;
}
#ifdef F_131
else {
V_32 -> V_299 [ 0 ] |= 1UL << V_270 ;
}
#endif
}
F_42 ( ( L_104 ,
V_270 ,
V_267 ,
V_274 ,
V_273 ,
V_12 ,
V_32 -> V_85 [ 0 ] ,
V_32 -> V_65 [ 0 ] ,
V_32 -> V_33 [ V_270 ] . V_295 ,
V_269 ,
V_266 ,
V_32 -> V_299 [ 0 ] ,
V_32 -> V_66 [ 0 ] ,
V_32 -> V_297 [ 0 ] ) ) ;
}
if ( V_273 ) F_29 () ;
return 0 ;
error:
F_199 ( V_240 -> V_271 , V_300 ) ;
return V_92 ;
}
static int
F_202 ( T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 )
{
struct V_1 * V_2 ;
T_18 * V_240 = ( T_18 * ) V_95 ;
unsigned long V_267 , V_301 , V_64 ;
unsigned int V_270 ;
int V_29 , V_273 = 0 , V_158 ;
int V_277 , V_274 , V_70 , V_275 ;
int V_92 = - V_110 ;
T_19 V_278 ;
V_158 = V_32 -> V_50 ;
V_274 = V_158 == V_279 ? 1 : 0 ;
V_70 = V_32 -> V_54 ;
V_64 = V_34 -> V_35 ;
V_2 = V_32 -> V_154 ;
if ( F_203 ( V_158 == V_166 ) ) return - V_110 ;
if ( F_198 ( V_274 ) ) {
if ( F_203 ( V_70 && V_32 -> V_153 != F_89 () ) ) {
F_42 ( ( L_58 , V_32 -> V_153 ) ) ;
return - V_112 ;
}
V_273 = F_122 () == V_2 || V_70 ? 1 : 0 ;
}
V_275 = V_280 . V_275 ;
for ( V_29 = 0 ; V_29 < V_249 ; V_29 ++ , V_240 ++ ) {
V_270 = V_240 -> V_281 ;
V_267 = V_240 -> V_282 ;
if ( ! F_204 ( V_270 ) ) {
F_42 ( ( L_105 , V_270 ) ) ;
goto V_302;
}
V_277 = F_63 ( V_270 ) ;
V_278 = V_34 -> V_303 [ V_270 ] . V_292 ;
if ( F_203 ( V_275 == 0 && V_278 ) ) {
unsigned long V_304 = V_267 ;
V_92 = (* V_278)( V_2 , V_32 , V_270 , & V_304 , V_91 ) ;
if ( V_92 ) goto V_302;
V_267 = V_304 ;
V_92 = - V_110 ;
}
F_199 ( V_240 -> V_271 , 0 ) ;
V_301 = V_267 ;
if ( V_277 ) {
V_32 -> V_33 [ V_270 ] . V_263 = V_267 ;
if ( V_274 ) {
V_301 = V_267 & V_64 ;
V_267 = V_267 & ~ V_64 ;
}
}
V_32 -> V_33 [ V_270 ] . V_256 = V_240 -> V_305 ;
V_32 -> V_33 [ V_270 ] . V_257 = V_240 -> V_306 ;
V_32 -> V_33 [ V_270 ] . V_260 = V_240 -> V_307 ;
V_32 -> V_33 [ V_270 ] . V_63 = V_240 -> V_308 ;
V_32 -> V_33 [ V_270 ] . V_25 = V_267 ;
F_200 ( V_32 , F_205 ( V_270 ) ) ;
F_200 ( V_32 , F_206 ( V_270 ) ) ;
if ( V_277 && V_158 == V_72 ) {
V_32 -> V_297 [ 0 ] &= ~ 1UL << V_270 ;
}
if ( V_274 ) {
if ( V_70 == 0 ) V_32 -> V_84 [ V_270 ] = V_301 ;
if ( V_273 ) {
F_40 ( V_270 , V_301 ) ;
} else {
#ifdef F_131
V_32 -> V_309 [ 0 ] |= 1UL << V_270 ;
#endif
}
}
F_42 ( ( L_106
L_107 ,
V_270 ,
V_267 ,
V_274 ,
V_273 ,
V_301 ,
V_32 -> V_33 [ V_270 ] . V_25 ,
V_32 -> V_33 [ V_270 ] . V_257 ,
V_32 -> V_33 [ V_270 ] . V_256 ,
F_207 ( V_32 , V_270 ) ? 'Y' : 'N' ,
V_32 -> V_33 [ V_270 ] . V_260 ,
V_32 -> V_33 [ V_270 ] . V_63 ,
V_32 -> V_65 [ 0 ] ,
V_32 -> V_33 [ V_270 ] . V_266 [ 0 ] ,
V_32 -> V_309 [ 0 ] ,
V_32 -> V_83 [ 0 ] ,
V_32 -> V_297 [ 0 ] ) ) ;
}
if ( V_273 ) F_29 () ;
return 0 ;
V_302:
F_199 ( V_240 -> V_271 , V_300 ) ;
return V_92 ;
}
static int
F_208 ( T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 )
{
struct V_1 * V_2 ;
unsigned long V_25 = 0UL , V_263 , V_64 , V_310 ;
T_18 * V_240 = ( T_18 * ) V_95 ;
unsigned int V_270 , V_271 = 0 ;
int V_29 , V_273 = 0 , V_158 ;
int V_274 , V_70 , V_277 , V_275 ;
int V_92 = - V_110 ;
T_19 V_311 ;
V_158 = V_32 -> V_50 ;
V_274 = V_158 == V_279 ? 1 : 0 ;
V_70 = V_32 -> V_54 ;
V_64 = V_34 -> V_35 ;
V_2 = V_32 -> V_154 ;
if ( V_158 == V_166 ) return - V_110 ;
if ( F_198 ( V_274 ) ) {
if ( F_203 ( V_70 && V_32 -> V_153 != F_89 () ) ) {
F_42 ( ( L_58 , V_32 -> V_153 ) ) ;
return - V_112 ;
}
V_273 = F_122 () == V_2 || V_70 ? 1 : 0 ;
if ( V_273 ) F_29 () ;
}
V_275 = V_280 . V_275 ;
F_42 ( ( L_108 ,
V_274 ,
V_273 ,
V_158 ) ) ;
for ( V_29 = 0 ; V_29 < V_249 ; V_29 ++ , V_240 ++ ) {
V_270 = V_240 -> V_281 ;
V_271 = V_240 -> V_271 ;
if ( F_203 ( ! F_204 ( V_270 ) ) ) goto error;
if ( F_203 ( ! F_209 ( V_32 , V_270 ) ) ) goto error;
V_310 = V_32 -> V_33 [ V_270 ] . V_25 ;
V_263 = V_32 -> V_33 [ V_270 ] . V_263 ;
V_277 = F_63 ( V_270 ) ;
if ( V_273 ) {
V_25 = F_38 ( V_270 ) ;
} else {
V_25 = V_274 ? V_32 -> V_84 [ V_270 ] : 0UL ;
}
V_311 = V_34 -> V_303 [ V_270 ] . V_312 ;
if ( V_277 ) {
V_25 &= V_64 ;
V_25 += V_310 ;
}
if ( F_203 ( V_275 == 0 && V_311 ) ) {
unsigned long V_304 = V_25 ;
V_92 = (* V_311)( V_32 -> V_154 , V_32 , V_270 , & V_304 , V_91 ) ;
if ( V_92 ) goto error;
V_25 = V_304 ;
V_92 = - V_110 ;
}
F_199 ( V_271 , 0 ) ;
F_42 ( ( L_109 , V_270 , V_25 ) ) ;
V_240 -> V_282 = V_25 ;
V_240 -> V_271 = V_271 ;
V_240 -> V_313 = V_263 ;
}
return 0 ;
error:
F_199 ( V_240 -> V_271 , V_300 ) ;
return V_92 ;
}
int
F_210 ( struct V_1 * V_2 , void * V_240 , unsigned int V_314 , struct V_90 * V_91 )
{
T_1 * V_32 ;
if ( V_240 == NULL ) return - V_110 ;
V_32 = F_123 () ;
if ( V_32 == NULL ) return - V_110 ;
if ( V_2 != V_3 && V_32 -> V_54 == 0 ) return - V_112 ;
return F_196 ( V_32 , V_240 , V_314 , V_91 ) ;
}
int
F_211 ( struct V_1 * V_2 , void * V_240 , unsigned int V_314 , struct V_90 * V_91 )
{
T_1 * V_32 ;
if ( V_240 == NULL ) return - V_110 ;
V_32 = F_123 () ;
if ( V_32 == NULL ) return - V_110 ;
if ( V_2 != V_3 && V_32 -> V_54 == 0 ) return - V_112 ;
return F_208 ( V_32 , V_240 , V_314 , V_91 ) ;
}
int
F_212 ( struct V_1 * V_2 )
{
T_1 * V_32 = V_2 -> V_315 . V_316 ;
unsigned long V_12 ;
int V_92 = 0 ;
if ( V_34 -> V_317 == 0 ) return 0 ;
F_42 ( ( L_110 , F_62 ( V_2 ) ) ) ;
if ( V_2 -> V_315 . V_12 & V_318 ) return 0 ;
if ( V_32 && V_32 -> V_77 == 1 ) return - 1 ;
F_88 ( V_12 ) ;
if ( V_117 . V_120 > 0 )
V_92 = - 1 ;
else
V_117 . V_319 ++ ;
F_42 ( ( L_111 ,
V_117 . V_319 ,
V_117 . V_120 ,
F_62 ( V_2 ) , V_92 ) ) ;
F_91 ( V_12 ) ;
return V_92 ;
}
int
F_213 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
int V_92 ;
if ( V_34 -> V_317 == 0 ) return 0 ;
F_88 ( V_12 ) ;
if ( V_117 . V_319 == 0 ) {
F_65 ( V_71 L_112 , F_62 ( V_2 ) ) ;
V_92 = - 1 ;
} else {
V_117 . V_319 -- ;
V_92 = 0 ;
}
F_91 ( V_12 ) ;
return V_92 ;
}
static int
F_214 ( T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 )
{
struct V_1 * V_2 ;
T_4 * V_88 ;
T_5 V_320 ;
int V_158 , V_70 ;
int V_92 = 0 ;
V_158 = V_32 -> V_50 ;
V_88 = V_32 -> V_169 ;
V_70 = V_32 -> V_54 ;
V_2 = F_130 ( V_32 ) ;
switch( V_158 ) {
case V_72 :
break;
case V_279 :
if ( F_215 ( V_32 ) && V_88 -> V_101 ) break;
case V_51 :
case V_166 :
F_42 ( ( L_113 , V_158 ) ) ;
return - V_112 ;
default:
F_42 ( ( L_114 , V_158 ) ) ;
return - V_110 ;
}
if ( V_70 && V_32 -> V_153 != F_89 () ) {
F_42 ( ( L_58 , V_32 -> V_153 ) ) ;
return - V_112 ;
}
if ( F_203 ( V_2 == NULL ) ) {
F_65 ( V_71 L_115 , F_62 ( V_3 ) ) ;
return - V_110 ;
}
if ( V_2 == V_3 || V_70 ) {
V_88 = V_32 -> V_169 ;
F_42 ( ( L_116 ,
F_62 ( V_2 ) ,
V_32 -> V_297 [ 0 ] ) ) ;
if ( F_215 ( V_32 ) ) {
F_216 ( V_32 -> V_167 ) ;
V_320 . V_321 . V_322 = 0 ;
V_320 . V_321 . V_323 = 0 ;
if ( V_158 == V_279 )
V_92 = F_78 ( V_88 , V_2 , & V_320 , V_32 -> V_167 , V_91 ) ;
else
V_92 = F_77 ( V_88 , V_2 , & V_320 , V_32 -> V_167 , V_91 ) ;
} else {
V_320 . V_321 . V_322 = 0 ;
V_320 . V_321 . V_323 = 1 ;
}
if ( V_92 == 0 ) {
if ( V_320 . V_321 . V_323 )
F_195 ( V_32 , V_32 -> V_297 , V_324 ) ;
if ( V_320 . V_321 . V_322 == 0 ) {
F_42 ( ( L_117 , F_62 ( V_2 ) ) ) ;
if ( V_158 == V_72 ) F_64 ( V_2 ) ;
} else {
F_42 ( ( L_118 , F_62 ( V_2 ) ) ) ;
}
}
V_32 -> V_297 [ 0 ] = 0UL ;
V_32 -> V_50 = V_279 ;
V_32 -> V_325 = 0 ;
return 0 ;
}
if ( V_158 == V_72 ) {
if ( V_32 -> V_325 == 0 ) return - V_110 ;
V_32 -> V_325 = 0 ;
}
if ( F_133 ( V_32 ) == 0 && V_158 == V_72 ) {
F_42 ( ( L_119 , F_62 ( V_2 ) ) ) ;
F_134 ( & V_32 -> V_58 ) ;
} else {
F_42 ( ( L_120 , F_62 ( V_2 ) ) ) ;
V_32 -> V_326 = V_327 ;
F_217 ( V_2 , 1 ) ;
F_218 ( V_2 ) ;
}
return 0 ;
}
static int
F_219 ( T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 )
{
unsigned int V_328 = * ( unsigned int * ) V_95 ;
V_280 . V_329 = V_328 == 0 ? 0 : 1 ;
F_65 ( V_115 L_121 , V_280 . V_329 ? L_122 : L_123 ) ;
if ( V_328 == 0 ) {
memset ( V_330 , 0 , sizeof( V_330 ) ) ;
for( V_328 = 0 ; V_328 < V_331 ; V_328 ++ ) V_330 [ V_328 ] . V_332 = ~ 0UL ;
}
return 0 ;
}
static int
F_220 ( int V_333 , T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 )
{
struct V_334 * V_315 = NULL ;
struct V_1 * V_2 ;
T_22 * V_240 = ( T_22 * ) V_95 ;
unsigned long V_12 ;
T_23 V_335 ;
unsigned int V_336 ;
int V_337 ;
int V_92 = 0 , V_158 ;
int V_29 , V_273 = 0 ;
int V_70 , V_274 ;
if ( V_34 -> V_317 == 0 ) return - V_110 ;
V_158 = V_32 -> V_50 ;
V_274 = V_158 == V_279 ? 1 : 0 ;
V_70 = V_32 -> V_54 ;
V_2 = V_32 -> V_154 ;
if ( V_158 == V_166 ) return - V_110 ;
if ( V_274 ) {
V_315 = & V_2 -> V_315 ;
if ( F_203 ( V_70 && V_32 -> V_153 != F_89 () ) ) {
F_42 ( ( L_58 , V_32 -> V_153 ) ) ;
return - V_112 ;
}
V_273 = F_122 () == V_2 || V_70 ? 1 : 0 ;
}
V_337 = V_32 -> V_77 == 0 ;
if ( V_274 && ( V_315 -> V_12 & V_318 ) != 0 ) {
F_42 ( ( L_124 , F_62 ( V_2 ) ) ) ;
return - V_112 ;
}
if ( V_274 ) {
F_88 ( V_12 ) ;
if ( V_337 && V_70 ) {
if ( V_117 . V_319 )
V_92 = - V_112 ;
else
V_117 . V_120 ++ ;
}
F_91 ( V_12 ) ;
}
if ( V_92 != 0 ) return V_92 ;
V_32 -> V_77 = 1 ;
if ( V_337 && V_273 ) {
F_42 ( ( L_125 , F_62 ( V_2 ) ) ) ;
for ( V_29 = 0 ; V_29 < V_34 -> V_79 ; V_29 ++ ) {
F_32 ( V_29 , 0UL ) ;
F_33 () ;
}
F_18 () ;
for ( V_29 = 0 ; V_29 < V_34 -> V_81 ; V_29 ++ ) {
F_35 ( V_29 , 0UL ) ;
F_36 () ;
}
F_29 () ;
}
for ( V_29 = 0 ; V_29 < V_249 ; V_29 ++ , V_240 ++ ) {
V_336 = V_240 -> V_338 ;
V_335 . V_25 = V_240 -> V_339 ;
V_92 = - V_110 ;
if ( ( V_333 == V_340 && V_336 >= V_341 ) || ( ( V_333 == V_342 ) && V_336 >= V_343 ) ) {
F_42 ( ( L_126 ,
V_336 , V_335 . V_25 , V_333 , V_29 , V_249 ) ) ;
goto V_302;
}
if ( V_336 & 0x1 ) {
if ( V_333 == V_340 )
V_335 . V_344 . V_345 = 0 ;
else
V_335 . V_346 . V_347 = V_335 . V_346 . V_348 = 0 ;
}
F_199 ( V_240 -> V_349 , 0 ) ;
if ( V_333 == V_340 ) {
F_221 ( V_32 , V_336 ) ;
if ( V_273 ) {
F_32 ( V_336 , V_335 . V_25 ) ;
F_33 () ;
}
V_32 -> V_78 [ V_336 ] = V_335 . V_25 ;
F_42 ( ( L_127 ,
V_336 , V_335 . V_25 , V_32 -> V_237 [ 0 ] , V_274 , V_273 ) ) ;
} else {
F_222 ( V_32 , V_336 ) ;
if ( V_273 ) {
F_35 ( V_336 , V_335 . V_25 ) ;
F_36 () ;
}
V_32 -> V_80 [ V_336 ] = V_335 . V_25 ;
F_42 ( ( L_128 ,
V_336 , V_335 . V_25 , V_32 -> V_238 [ 0 ] , V_274 , V_273 ) ) ;
}
}
return 0 ;
V_302:
if ( V_337 ) {
F_88 ( V_12 ) ;
if ( V_32 -> V_54 ) {
V_117 . V_120 -- ;
}
F_91 ( V_12 ) ;
V_32 -> V_77 = 0 ;
}
F_199 ( V_240 -> V_349 , V_300 ) ;
return V_92 ;
}
static int
F_223 ( T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 )
{
return F_220 ( V_340 , V_32 , V_95 , V_249 , V_91 ) ;
}
static int
F_224 ( T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 )
{
return F_220 ( V_342 , V_32 , V_95 , V_249 , V_91 ) ;
}
int
F_225 ( struct V_1 * V_2 , void * V_240 , unsigned int V_314 , struct V_90 * V_91 )
{
T_1 * V_32 ;
if ( V_240 == NULL ) return - V_110 ;
V_32 = F_123 () ;
if ( V_32 == NULL ) return - V_110 ;
if ( V_2 != V_3 && V_32 -> V_54 == 0 ) return - V_112 ;
return F_223 ( V_32 , V_240 , V_314 , V_91 ) ;
}
int
F_226 ( struct V_1 * V_2 , void * V_240 , unsigned int V_314 , struct V_90 * V_91 )
{
T_1 * V_32 ;
if ( V_240 == NULL ) return - V_110 ;
V_32 = F_123 () ;
if ( V_32 == NULL ) return - V_110 ;
if ( V_2 != V_3 && V_32 -> V_54 == 0 ) return - V_112 ;
return F_224 ( V_32 , V_240 , V_314 , V_91 ) ;
}
static int
F_227 ( T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 )
{
T_24 * V_240 = ( T_24 * ) V_95 ;
V_240 -> V_350 = V_351 ;
return 0 ;
}
static int
F_228 ( T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 )
{
struct V_90 * V_352 ;
struct V_1 * V_2 = F_130 ( V_32 ) ;
int V_158 , V_70 ;
V_158 = V_32 -> V_50 ;
V_70 = V_32 -> V_54 ;
if ( V_158 == V_51 ) return - V_110 ;
if ( V_70 && V_32 -> V_153 != F_89 () ) {
F_42 ( ( L_58 , V_32 -> V_153 ) ) ;
return - V_112 ;
}
F_42 ( ( L_129 ,
F_62 ( F_130 ( V_32 ) ) ,
V_158 ,
V_70 ) ) ;
if ( V_70 ) {
F_26 ( V_74 , F_24 ( V_74 ) & ~ V_75 ) ;
F_18 () ;
F_229 ( V_73 ) ;
F_16 () ;
F_230 ( V_91 ) -> V_353 = 0 ;
return 0 ;
}
if ( V_2 == V_3 ) {
F_21 () ;
F_230 ( V_91 ) -> V_354 = 0 ;
} else {
V_352 = F_121 ( V_2 ) ;
F_230 ( V_352 ) -> V_354 = 0 ;
V_32 -> V_355 = 0 ;
F_42 ( ( L_130 , F_62 ( V_2 ) ) ) ;
}
return 0 ;
}
static int
F_231 ( T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 )
{
struct V_90 * V_352 ;
int V_158 , V_70 ;
V_158 = V_32 -> V_50 ;
V_70 = V_32 -> V_54 ;
if ( V_158 != V_279 ) return - V_110 ;
if ( V_70 && V_32 -> V_153 != F_89 () ) {
F_42 ( ( L_58 , V_32 -> V_153 ) ) ;
return - V_112 ;
}
if ( V_70 ) {
F_230 ( V_91 ) -> V_353 = 1 ;
F_232 ( V_73 ) ;
F_19 () ;
F_26 ( V_74 , F_24 ( V_74 ) | V_75 ) ;
F_18 () ;
return 0 ;
}
if ( V_32 -> V_154 == V_3 ) {
F_22 () ;
F_230 ( V_91 ) -> V_354 = 1 ;
} else {
V_352 = F_121 ( V_32 -> V_154 ) ;
V_32 -> V_355 = V_22 ;
F_230 ( V_352 ) -> V_354 = 1 ;
}
return 0 ;
}
static int
F_233 ( T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 )
{
T_18 * V_240 = ( T_18 * ) V_95 ;
unsigned int V_270 ;
int V_29 ;
int V_92 = - V_110 ;
for ( V_29 = 0 ; V_29 < V_249 ; V_29 ++ , V_240 ++ ) {
V_270 = V_240 -> V_281 ;
if ( ! F_176 ( V_270 ) ) goto V_302;
V_240 -> V_282 = F_177 ( V_270 ) ;
F_199 ( V_240 -> V_271 , 0 ) ;
F_42 ( ( L_131 , V_270 , V_240 -> V_282 ) ) ;
}
return 0 ;
V_302:
F_199 ( V_240 -> V_271 , V_300 ) ;
return V_92 ;
}
static int
F_234 ( T_1 * V_32 )
{
struct V_1 * V_356 , * V_357 ;
int V_92 = - V_248 ;
F_184 ( & V_247 ) ;
F_235 (g, t) {
if ( V_357 -> V_315 . V_316 == V_32 ) {
V_92 = 0 ;
goto V_113;
}
} F_236 ( V_356 , V_357 ) ;
V_113:
F_187 ( & V_247 ) ;
F_42 ( ( L_132 , V_92 , V_32 ) ) ;
return V_92 ;
}
static int
F_237 ( T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 )
{
struct V_1 * V_2 ;
struct V_334 * V_315 ;
struct T_1 * V_358 ;
unsigned long V_12 ;
#ifndef F_131
struct V_1 * V_359 = NULL ;
#endif
T_25 * V_240 = ( T_25 * ) V_95 ;
unsigned long * V_360 , * V_361 ;
int V_362 ;
int V_92 = 0 ;
int V_158 , V_70 , V_363 = 0 ;
V_158 = V_32 -> V_50 ;
V_70 = V_32 -> V_54 ;
if ( V_158 != V_51 ) {
F_42 ( ( L_133 ,
V_240 -> V_364 ,
V_32 -> V_50 ) ) ;
return - V_112 ;
}
F_42 ( ( L_134 , V_240 -> V_364 , V_32 -> V_77 ) ) ;
if ( F_133 ( V_32 ) == 0 && V_240 -> V_364 == V_3 -> V_245 ) {
F_42 ( ( L_135 ) ) ;
return - V_110 ;
}
V_92 = F_182 ( V_32 , V_240 -> V_364 , & V_2 ) ;
if ( V_92 ) {
F_42 ( ( L_136 , V_240 -> V_364 , V_92 ) ) ;
return V_92 ;
}
V_92 = - V_110 ;
if ( V_70 && V_2 != V_3 ) {
F_42 ( ( L_137 ,
V_240 -> V_364 ) ) ;
goto error;
}
V_315 = & V_2 -> V_315 ;
V_92 = 0 ;
if ( V_32 -> V_77 ) {
if ( V_315 -> V_12 & V_318 ) {
V_92 = - V_112 ;
F_42 ( ( L_138 , V_240 -> V_364 ) ) ;
goto error;
}
F_88 ( V_12 ) ;
if ( V_70 ) {
if ( V_117 . V_319 ) {
F_42 ( ( L_139 ,
F_62 ( V_2 ) ) ) ;
V_92 = - V_112 ;
} else {
V_117 . V_120 ++ ;
F_42 ( ( L_140 , F_62 ( V_2 ) , V_117 . V_120 ) ) ;
V_363 = 1 ;
}
}
F_91 ( V_12 ) ;
if ( V_92 ) goto error;
}
V_362 = V_32 -> V_153 = F_89 () ;
V_92 = - V_112 ;
V_92 = F_87 ( V_3 , V_70 , V_362 ) ;
if ( V_92 ) goto error;
F_42 ( ( L_141 ,
V_315 -> V_316 , V_32 ) ) ;
V_92 = - V_112 ;
V_358 = F_238 ( V_365 , & V_315 -> V_316 , NULL , V_32 , sizeof( T_1 * ) ) ;
if ( V_358 != NULL ) {
F_42 ( ( L_142 , V_240 -> V_364 ) ) ;
goto V_366;
}
F_45 ( V_32 ) ;
V_32 -> V_50 = V_279 ;
V_32 -> V_154 = V_2 ;
if ( V_70 ) {
F_232 ( V_367 ) ;
F_229 ( V_73 ) ;
if ( V_32 -> V_252 ) F_232 ( V_368 ) ;
} else {
V_315 -> V_12 |= V_369 ;
}
F_69 ( V_2 , V_32 ) ;
F_70 ( V_2 , V_32 ) ;
V_360 = V_32 -> V_68 ;
V_361 = V_32 -> V_84 ;
if ( V_2 == V_3 ) {
if ( V_70 == 0 ) {
F_230 ( V_91 ) -> V_370 = 0 ;
F_42 ( ( L_143 , F_62 ( V_2 ) ) ) ;
F_55 ( V_32 , F_89 () ) ;
F_239 () ;
F_240 ( V_32 ) ;
#ifndef F_131
V_359 = F_122 () ;
if ( V_359 ) F_241 ( V_359 ) ;
#endif
}
F_68 ( V_361 , V_32 -> V_83 [ 0 ] ) ;
F_71 ( V_360 , V_32 -> V_85 [ 0 ] ) ;
V_32 -> V_299 [ 0 ] = 0UL ;
V_32 -> V_309 [ 0 ] = 0UL ;
if ( V_32 -> V_77 ) {
F_31 ( V_32 -> V_78 , V_34 -> V_79 ) ;
F_34 ( V_32 -> V_80 , V_34 -> V_81 ) ;
}
F_242 ( V_2 , V_32 ) ;
F_42 ( ( L_144 , F_62 ( V_2 ) ) ) ;
} else {
V_91 = F_121 ( V_2 ) ;
V_32 -> V_59 = V_60 ;
F_55 ( V_32 , - 1 ) ;
V_32 -> V_355 = 0UL ;
F_230 ( V_91 ) -> V_354 = F_230 ( V_91 ) -> V_353 = 0 ;
}
V_92 = 0 ;
V_366:
if ( V_92 ) F_92 ( V_32 , V_32 -> V_54 , V_362 ) ;
error:
if ( V_92 && V_363 ) {
F_88 ( V_12 ) ;
V_117 . V_120 -- ;
F_91 ( V_12 ) ;
}
if ( V_70 == 0 && V_2 != V_3 ) {
F_1 ( V_2 ) ;
if ( V_92 == 0 ) {
V_92 = F_234 ( V_32 ) ;
if ( V_92 ) {
V_32 -> V_50 = V_51 ;
V_32 -> V_154 = NULL ;
}
}
}
return V_92 ;
}
static int
F_125 ( T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_130 ( V_32 ) ;
struct V_90 * V_352 ;
int V_371 , V_70 ;
int V_92 ;
F_42 ( ( L_145 , V_32 -> V_50 , V_2 ? F_62 ( V_2 ) : - 1 ) ) ;
V_371 = V_32 -> V_50 ;
V_70 = V_32 -> V_54 ;
if ( V_371 == V_51 ) {
F_42 ( ( L_146 , V_371 ) ) ;
return 0 ;
}
V_92 = F_228 ( V_32 , NULL , 0 , V_91 ) ;
if ( V_92 ) return V_92 ;
V_32 -> V_50 = V_51 ;
if ( V_70 ) {
F_229 ( V_367 ) ;
F_229 ( V_368 ) ;
F_243 ( V_3 , V_32 ) ;
if ( V_371 != V_166 )
F_92 ( V_32 , 1 , V_32 -> V_153 ) ;
V_2 -> V_315 . V_316 = NULL ;
V_32 -> V_154 = NULL ;
return 0 ;
}
V_352 = V_2 == V_3 ? V_91 : F_121 ( V_2 ) ;
if ( V_2 == V_3 ) {
F_230 ( V_91 ) -> V_370 = 1 ;
F_42 ( ( L_147 , F_62 ( V_2 ) ) ) ;
}
F_243 ( V_2 , V_32 ) ;
if ( V_371 != V_166 )
F_92 ( V_32 , 0 , V_32 -> V_153 ) ;
V_32 -> V_59 = V_60 ;
F_55 ( V_32 , - 1 ) ;
V_2 -> V_315 . V_12 &= ~ V_369 ;
V_2 -> V_315 . V_316 = NULL ;
V_32 -> V_154 = NULL ;
F_217 ( V_2 , 0 ) ;
V_32 -> V_326 = V_372 ;
V_32 -> V_325 = 0 ;
V_32 -> V_165 = 0 ;
F_42 ( ( L_148 , F_62 ( V_2 ) ) ) ;
return 0 ;
}
void
F_244 ( struct V_1 * V_2 )
{
T_1 * V_32 ;
unsigned long V_12 ;
struct V_90 * V_91 = F_121 ( V_2 ) ;
int V_92 , V_158 ;
int V_373 = 0 ;
V_32 = F_60 ( V_2 ) ;
F_105 ( V_32 , V_12 ) ;
F_42 ( ( L_149 , V_32 -> V_50 , F_62 ( V_2 ) ) ) ;
V_158 = V_32 -> V_50 ;
switch( V_158 ) {
case V_51 :
F_65 ( V_71 L_150 , F_62 ( V_2 ) ) ;
break;
case V_279 :
case V_72 :
V_92 = F_125 ( V_32 , NULL , 0 , V_91 ) ;
if ( V_92 ) {
F_65 ( V_71 L_151 , F_62 ( V_2 ) , V_158 , V_92 ) ;
}
F_42 ( ( L_152 , V_158 ) ) ;
F_245 ( V_32 ) ;
break;
case V_166 :
V_92 = F_125 ( V_32 , NULL , 0 , V_91 ) ;
if ( V_92 ) {
F_65 ( V_71 L_151 , F_62 ( V_2 ) , V_158 , V_92 ) ;
}
V_373 = 1 ;
break;
default:
F_65 ( V_71 L_153 , F_62 ( V_2 ) , V_158 ) ;
break;
}
F_108 ( V_32 , V_12 ) ;
{ T_26 V_69 = F_23 () ;
F_246 ( V_69 & ( V_22 | V_21 ) ) ;
F_246 ( F_122 () ) ;
F_246 ( F_230 ( V_91 ) -> V_354 ) ;
F_246 ( F_230 ( V_91 ) -> V_353 ) ;
}
if ( V_373 ) F_57 ( V_32 ) ;
}
static int
F_247 ( T_1 * V_32 , int V_146 , unsigned long V_12 )
{
struct V_1 * V_2 ;
int V_158 , V_374 ;
V_375:
V_158 = V_32 -> V_50 ;
V_2 = V_32 -> V_154 ;
if ( V_2 == NULL ) {
F_42 ( ( L_154 , V_32 -> V_143 , V_158 ) ) ;
return 0 ;
}
F_42 ( ( L_155 ,
V_32 -> V_143 ,
V_158 ,
F_62 ( V_2 ) ,
V_2 -> V_158 , F_248 ( V_146 ) ) ) ;
if ( V_2 == V_3 || V_32 -> V_54 ) return 0 ;
switch( V_158 ) {
case V_51 :
return 0 ;
case V_166 :
F_42 ( ( L_156 , V_146 ) ) ;
return - V_110 ;
case V_72 :
if ( V_146 != V_376 ) return 0 ;
}
if ( F_248 ( V_146 ) ) {
if ( ! F_180 ( V_2 ) ) {
F_42 ( ( L_157 , F_62 ( V_2 ) ) ) ;
return - V_112 ;
}
V_374 = V_158 ;
F_108 ( V_32 , V_12 ) ;
F_181 ( V_2 , 0 ) ;
F_105 ( V_32 , V_12 ) ;
if ( V_32 -> V_50 != V_374 ) {
F_42 ( ( L_158 , V_374 , V_32 -> V_50 ) ) ;
goto V_375;
}
}
return 0 ;
}
T_27 long
F_249 ( int V_147 , int V_146 , void T_8 * V_95 , int V_249 )
{
struct V_8 * V_8 = NULL ;
T_1 * V_32 = NULL ;
unsigned long V_12 = 0UL ;
void * V_377 = NULL ;
long V_92 ;
T_9 V_378 , V_239 , V_379 = 0 ;
int V_380 , V_381 = 0 , V_382 = 0 , V_383 ;
int (* F_250)( T_1 * V_32 , void * V_95 , int V_249 , struct V_90 * V_91 );
int (* F_251)( void * V_95 , T_9 * V_239 );
#define F_252 4096
if ( F_203 ( V_34 == NULL ) ) return - V_384 ;
if ( F_203 ( V_146 < 0 || V_146 >= V_385 ) ) {
F_42 ( ( L_159 , V_146 ) ) ;
return - V_110 ;
}
F_250 = V_386 [ V_146 ] . V_387 ;
V_380 = V_386 [ V_146 ] . V_388 ;
V_378 = V_386 [ V_146 ] . V_389 ;
F_251 = V_386 [ V_146 ] . V_390 ;
V_383 = V_386 [ V_146 ] . V_383 ;
if ( F_203 ( F_250 == NULL ) ) {
F_42 ( ( L_159 , V_146 ) ) ;
return - V_110 ;
}
F_42 ( ( L_160 ,
F_253 ( V_146 ) ,
V_146 ,
V_380 ,
V_378 ,
V_249 ) ) ;
if ( F_203 ( ( V_380 == V_391 && V_249 <= 0 ) || ( V_380 > 0 && V_380 != V_249 ) ) )
return - V_110 ;
V_392:
V_239 = V_379 + V_378 * V_249 ;
if ( F_203 ( V_239 > F_252 ) ) {
F_65 ( V_71 L_161 , F_62 ( V_3 ) , V_239 ) ;
return - V_393 ;
}
if ( F_198 ( V_249 && V_377 == NULL ) ) {
V_377 = F_254 ( F_252 , V_49 ) ;
if ( V_377 == NULL ) return - V_182 ;
}
V_92 = - V_141 ;
if ( V_239 && F_255 ( V_377 , V_95 , V_239 ) ) {
F_42 ( ( L_162 , V_239 , V_95 ) ) ;
goto V_394;
}
if ( V_381 == 0 && F_251 ) {
V_92 = (* F_251)( V_377 , & V_379 ) ;
if ( V_92 ) goto V_394;
V_381 = 1 ;
F_42 ( ( L_163 , V_239 , V_379 ) ) ;
if ( F_198 ( V_379 ) ) goto V_392;
}
if ( F_203 ( ( V_383 & V_395 ) == 0 ) ) goto V_396;
V_92 = - V_150 ;
V_8 = F_256 ( V_147 ) ;
if ( F_203 ( V_8 == NULL ) ) {
F_42 ( ( L_164 , V_147 ) ) ;
goto V_394;
}
if ( F_203 ( F_104 ( V_8 ) == 0 ) ) {
F_42 ( ( L_165 , V_147 ) ) ;
goto V_394;
}
V_32 = V_8 -> V_132 ;
if ( F_203 ( V_32 == NULL ) ) {
F_42 ( ( L_166 , V_147 ) ) ;
goto V_394;
}
F_216 ( & V_32 -> V_50 ) ;
F_105 ( V_32 , V_12 ) ;
V_92 = F_247 ( V_32 , V_146 , V_12 ) ;
if ( F_203 ( V_92 ) ) goto V_139;
V_396:
V_92 = (* F_250)( V_32 , V_377 , V_249 , F_121 ( V_3 ) ) ;
V_382 = 1 ;
V_139:
if ( F_198 ( V_32 ) ) {
F_42 ( ( L_167 ) ) ;
F_108 ( V_32 , V_12 ) ;
}
if ( V_382 && F_257 ( V_146 ) && F_112 ( V_95 , V_377 , V_378 * V_249 ) ) V_92 = - V_141 ;
V_394:
if ( V_8 )
F_258 ( V_8 ) ;
F_58 ( V_377 ) ;
F_42 ( ( L_168 , F_253 ( V_146 ) , V_92 ) ) ;
return V_92 ;
}
static void
F_259 ( T_1 * V_32 , unsigned long V_264 , struct V_90 * V_91 )
{
T_4 * V_88 = V_32 -> V_169 ;
T_5 V_320 ;
int V_158 ;
int V_92 = 0 ;
V_158 = V_32 -> V_50 ;
if ( F_215 ( V_32 ) ) {
V_320 . V_321 . V_322 = 0 ;
V_320 . V_321 . V_323 = 0 ;
if ( V_158 == V_279 )
V_92 = F_78 ( V_88 , V_3 , & V_320 , V_32 -> V_167 , V_91 ) ;
else
V_92 = F_77 ( V_88 , V_3 , & V_320 , V_32 -> V_167 , V_91 ) ;
} else {
V_320 . V_321 . V_322 = 0 ;
V_320 . V_321 . V_323 = 1 ;
}
if ( V_92 == 0 ) {
if ( V_320 . V_321 . V_323 ) {
F_195 ( V_32 , & V_264 , V_324 ) ;
}
if ( V_320 . V_321 . V_322 == 0 ) {
F_42 ( ( L_169 ) ) ;
if ( V_32 -> V_50 == V_72 ) F_64 ( V_3 ) ;
} else {
F_42 ( ( L_170 ) ) ;
}
V_32 -> V_50 = V_279 ;
}
}
static void
F_260 ( T_1 * V_32 , struct V_90 * V_91 )
{
int V_92 ;
F_42 ( ( L_171 , F_62 ( V_3 ) ) ) ;
V_92 = F_125 ( V_32 , NULL , 0 , V_91 ) ;
if ( V_92 ) {
F_65 ( V_71 L_172 , F_62 ( V_3 ) , V_92 ) ;
}
F_261 ( & V_32 -> V_62 ) ;
}
void
F_262 ( void )
{
T_1 * V_32 ;
struct V_90 * V_91 ;
unsigned long V_12 , V_397 ;
unsigned long V_264 ;
unsigned int V_398 ;
int V_92 ;
V_32 = F_60 ( V_3 ) ;
if ( V_32 == NULL ) {
F_65 ( V_71 L_173 ,
F_62 ( V_3 ) ) ;
return;
}
F_105 ( V_32 , V_12 ) ;
F_217 ( V_3 , 0 ) ;
V_91 = F_121 ( V_3 ) ;
V_398 = V_32 -> V_326 ;
V_32 -> V_326 = V_372 ;
V_264 = V_32 -> V_297 [ 0 ] ;
F_42 ( ( L_174 , V_398 , V_32 -> V_50 ) ) ;
if ( V_32 -> V_165 || V_32 -> V_50 == V_166 )
goto V_399;
if ( V_398 == V_327 )
goto V_400;
F_108 ( V_32 , V_12 ) ;
F_263 () ;
F_42 ( ( L_175 ) ) ;
V_92 = F_264 ( & V_32 -> V_58 ) ;
F_42 ( ( L_176 , V_92 ) ) ;
F_105 ( V_32 , V_397 ) ;
V_264 = V_32 -> V_297 [ 0 ] ;
if ( V_32 -> V_165 ) {
V_399:
F_42 ( ( L_177 ) ) ;
F_260 ( V_32 , V_91 ) ;
goto V_401;
}
if ( V_92 < 0 )
goto V_401;
V_400:
F_259 ( V_32 , V_264 , V_91 ) ;
V_32 -> V_297 [ 0 ] = 0UL ;
V_401:
F_108 ( V_32 , V_12 ) ;
}
static int
F_265 ( T_1 * V_32 , T_2 * V_42 )
{
if ( V_32 -> V_50 == V_166 ) {
F_42 ( ( L_178 ) ) ;
return 0 ;
}
F_42 ( ( L_179 ) ) ;
if ( V_42 ) F_261 ( & V_32 -> V_61 ) ;
F_266 ( & V_32 -> V_149 , V_402 , V_403 ) ;
return 0 ;
}
static int
F_267 ( T_1 * V_32 , unsigned long V_404 )
{
T_2 * V_42 = NULL ;
if ( V_32 -> V_56 == 0 ) {
V_42 = F_41 ( V_32 ) ;
if ( V_42 == NULL ) {
F_65 ( V_71 L_180 ) ;
return - 1 ;
}
V_42 -> V_405 . V_44 = V_406 ;
V_42 -> V_405 . V_140 = V_32 -> V_143 ;
V_42 -> V_405 . V_407 = 0 ;
V_42 -> V_405 . V_408 [ 0 ] = V_404 ;
V_42 -> V_405 . V_408 [ 1 ] = 0UL ;
V_42 -> V_405 . V_408 [ 2 ] = 0UL ;
V_42 -> V_405 . V_408 [ 3 ] = 0UL ;
V_42 -> V_405 . V_409 = 0UL ;
}
F_42 ( ( L_181 ,
V_42 ,
V_32 -> V_56 ,
V_32 -> V_143 ,
V_404 ) ) ;
return F_265 ( V_32 , V_42 ) ;
}
static int
F_245 ( T_1 * V_32 )
{
T_2 * V_42 ;
V_42 = F_41 ( V_32 ) ;
if ( V_42 == NULL ) {
F_65 ( V_71 L_182 ) ;
return - 1 ;
}
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_410 . V_44 = V_411 ;
V_42 -> V_410 . V_140 = V_32 -> V_143 ;
V_42 -> V_405 . V_409 = 0UL ;
F_42 ( ( L_183 ,
V_42 ,
V_32 -> V_56 ,
V_32 -> V_143 ) ) ;
return F_265 ( V_32 , V_42 ) ;
}
static void F_268 ( struct V_1 * V_2 , T_1 * V_32 ,
unsigned long V_412 , struct V_90 * V_91 )
{
T_28 * V_413 ;
unsigned long V_63 ;
unsigned long V_414 , V_35 , V_415 ;
unsigned long V_416 = 0UL , V_404 = 0UL , V_269 = 0UL , V_266 ;
unsigned long V_417 ;
T_5 V_418 ;
unsigned int V_29 , V_419 ;
int V_420 = 0 ;
if ( F_203 ( V_32 -> V_50 == V_166 ) ) goto V_421;
if ( F_203 ( ( V_412 & 0x1 ) == 0 ) ) goto V_422;
V_417 = F_269 () ;
V_63 = V_412 >> V_67 ;
V_35 = V_34 -> V_35 ;
V_419 = F_215 ( V_32 ) ;
F_61 ( ( L_184
L_185 ,
V_412 ,
V_2 ? F_62 ( V_2 ) : - 1 ,
( V_91 ? V_91 -> V_423 : 0 ) ,
F_133 ( V_32 ) ? L_186 : L_187 ,
V_32 -> V_65 [ 0 ] ) ) ;
for ( V_29 = V_67 ; V_63 ; V_29 ++ , V_63 >>= 1 ) {
if ( ( V_63 & 0x1 ) == 0 ) continue;
V_414 = V_415 = V_32 -> V_33 [ V_29 ] . V_25 ;
V_415 += 1 + V_35 ;
V_32 -> V_33 [ V_29 ] . V_25 = V_415 ;
if ( F_198 ( V_414 > V_415 ) ) {
V_404 |= 1UL << V_29 ;
if ( F_207 ( V_32 , V_29 ) ) V_416 |= 1UL << V_29 ;
}
F_61 ( ( L_188 ,
V_29 ,
V_415 ,
V_414 ,
F_38 ( V_29 ) & V_35 ,
V_404 ,
V_416 ) ) ;
}
if ( V_404 == 0UL ) return;
V_418 . V_25 = 0 ;
V_266 = 0UL ;
if ( V_419 ) {
unsigned long V_424 , V_425 ;
unsigned long V_426 ;
int V_427 , V_428 , V_92 = 0 ;
int V_429 = F_89 () ;
V_426 = V_404 >> V_67 ;
V_413 = & V_32 -> V_430 ;
F_216 ( V_32 -> V_167 ) ;
for( V_29 = V_67 ; V_426 && V_92 == 0 ; V_29 ++ , V_426 >>= 1 ) {
V_63 = 1UL << V_29 ;
if ( ( V_426 & 0x1 ) == 0 ) continue;
V_413 -> V_431 = ( unsigned char ) V_29 ;
V_413 -> V_416 = V_416 & V_63 ? 1 : 0 ;
V_413 -> V_432 = 0 ;
V_413 -> V_418 . V_25 = 0 ;
V_413 -> V_269 [ 0 ] = V_269 = V_32 -> V_33 [ V_29 ] . V_269 [ 0 ] ;
V_413 -> V_433 = V_32 -> V_33 [ V_29 ] . V_25 ;
V_413 -> V_434 = V_32 -> V_33 [ V_29 ] . V_263 ;
V_413 -> V_435 = V_32 -> V_33 [ V_29 ] . V_295 ;
if ( V_269 ) {
for( V_427 = 0 , V_428 = 0 ; V_269 ; V_427 ++ , V_269 >>= 1 ) {
if ( ( V_269 & 0x1 ) == 0 ) continue;
V_413 -> V_436 [ V_428 ++ ] = F_63 ( V_427 ) ? F_37 ( V_32 , V_427 ) : F_38 ( V_427 ) ;
F_61 ( ( L_189 , V_428 - 1 , V_427 , V_413 -> V_436 [ V_428 - 1 ] ) ) ;
}
}
V_330 [ V_429 ] . V_437 ++ ;
V_424 = F_269 () ;
V_92 = (* V_32 -> V_169 -> V_111 )( V_2 , V_32 -> V_167 , V_413 , V_91 , V_417 ) ;
V_425 = F_269 () ;
V_418 . V_321 . V_438 |= V_413 -> V_418 . V_321 . V_438 ;
V_418 . V_321 . V_439 |= V_413 -> V_418 . V_321 . V_439 ;
V_418 . V_321 . V_322 |= V_413 -> V_418 . V_321 . V_322 ;
if ( V_413 -> V_418 . V_321 . V_323 ) V_266 |= V_63 ;
V_330 [ V_429 ] . V_440 += V_425 - V_424 ;
}
if ( V_92 && V_426 ) {
F_42 ( ( L_190 ,
V_426 << V_67 ) ) ;
}
V_404 &= ~ V_266 ;
} else {
V_418 . V_321 . V_438 = V_416 ? 1 : 0 ;
V_418 . V_321 . V_439 = V_416 ? 1 : 0 ;
V_418 . V_321 . V_322 = V_416 ? 1 : 0 ;
V_418 . V_321 . V_323 = V_416 ? 0 : 1 ;
if ( V_416 == 0 ) V_266 = V_404 ;
}
F_61 ( ( L_191 , V_404 , V_266 ) ) ;
if ( V_266 ) {
unsigned long V_441 = V_266 ;
F_195 ( V_32 , & V_441 , V_442 ) ;
}
if ( V_416 && V_418 . V_321 . V_438 ) {
V_32 -> V_297 [ 0 ] = V_404 ;
if ( F_133 ( V_32 ) == 0 && V_418 . V_321 . V_439 ) {
V_32 -> V_326 = V_443 ;
F_217 ( V_2 , 1 ) ;
F_218 ( V_2 ) ;
}
V_420 = 1 ;
}
F_61 ( ( L_192 ,
F_122 () ? F_62 ( F_122 () ) : - 1 ,
F_270 ( V_2 ) ,
V_32 -> V_326 ,
V_404 ,
V_416 ,
V_418 . V_321 . V_322 ? 1 : 0 ) ) ;
if ( V_418 . V_321 . V_322 ) {
F_59 ( V_2 ) ;
V_32 -> V_50 = V_72 ;
V_32 -> V_325 = 1 ;
}
if ( V_420 ) F_267 ( V_32 , V_416 ) ;
return;
V_422:
F_65 ( V_71 L_193 ,
F_89 () ,
V_2 ? F_62 ( V_2 ) : - 1 ,
V_412 ) ;
return;
V_421:
F_42 ( ( L_194 , V_2 ? F_62 ( V_2 ) : - 1 ) ) ;
F_21 () ;
F_230 ( V_91 ) -> V_354 = 0 ;
F_230 ( V_91 ) -> V_370 = 1 ;
return;
}
static int
F_271 ( void * V_95 , struct V_90 * V_91 )
{
struct V_1 * V_2 ;
T_1 * V_32 ;
unsigned long V_12 ;
T_26 V_412 ;
int V_429 = F_89 () ;
int V_444 = 0 ;
V_330 [ V_429 ] . V_445 ++ ;
V_412 = F_272 ( 0 ) ;
V_2 = F_122 () ;
V_32 = F_123 () ;
if ( F_273 ( V_412 ) && V_2 ) {
if ( ! V_32 ) goto V_446;
if ( V_32 -> V_54 == 0 && ( V_2 -> V_315 . V_12 & V_369 ) == 0 )
goto V_447;
F_274 ( V_32 , V_12 ) ;
F_268 ( V_2 , V_32 , V_412 , V_91 ) ;
F_275 ( V_32 , V_12 ) ;
} else {
V_330 [ V_429 ] . V_448 ++ ;
V_444 = - 1 ;
}
F_30 () ;
return V_444 ;
V_446:
F_65 ( V_115 L_195 ,
V_429 , F_62 ( V_2 ) ) ;
F_30 () ;
return - 1 ;
V_447:
F_65 ( V_115 L_196 ,
V_429 ,
F_62 ( V_2 ) ) ;
F_30 () ;
return - 1 ;
}
static T_29
F_276 ( int V_449 , void * V_95 )
{
unsigned long V_424 , V_450 ;
unsigned long V_451 , V_452 ;
int V_429 ;
int V_92 ;
struct V_90 * V_91 = F_277 () ;
V_429 = F_278 () ;
if ( F_198 ( ! V_453 ) ) {
V_451 = V_330 [ V_429 ] . V_332 ;
V_452 = V_330 [ V_429 ] . V_454 ;
V_424 = F_269 () ;
V_92 = F_271 ( V_95 , V_91 ) ;
V_450 = F_269 () ;
if ( F_198 ( V_92 == 0 ) ) {
V_450 -= V_424 ;
if ( V_450 < V_451 ) V_330 [ V_429 ] . V_332 = V_450 ;
if ( V_450 > V_452 ) V_330 [ V_429 ] . V_454 = V_450 ;
V_330 [ V_429 ] . V_455 += V_450 ;
}
}
else {
(* V_453 -> V_456 )( V_449 , V_95 , V_91 ) ;
}
F_279 () ;
return V_457 ;
}
static void *
F_280 ( struct V_458 * V_328 , T_10 * V_104 )
{
if ( * V_104 == 0 ) {
return V_459 ;
}
while ( * V_104 <= V_460 ) {
if ( F_281 ( * V_104 - 1 ) ) {
return ( void * ) * V_104 ;
}
++ * V_104 ;
}
return NULL ;
}
static void *
F_282 ( struct V_458 * V_328 , void * V_304 , T_10 * V_104 )
{
++ * V_104 ;
return F_280 ( V_328 , V_104 ) ;
}
static void
F_283 ( struct V_458 * V_328 , void * V_304 )
{
}
static void
F_284 ( struct V_458 * V_328 )
{
struct V_103 * V_104 ;
T_4 * V_105 ;
unsigned long V_12 ;
F_285 ( V_328 ,
L_197
L_198
L_199
L_200
L_201
L_202 ,
V_461 , V_462 ,
V_34 -> V_463 ,
V_280 . V_464 > 0 ? L_203 : L_204 ,
V_280 . V_275 > 0 ? L_203 : L_204 ,
V_34 -> V_35 ,
V_34 -> V_12 ) ;
F_88 ( V_12 ) ;
F_285 ( V_328 ,
L_205
L_206
L_207
L_208 ,
V_117 . V_119 ,
V_117 . V_118 ,
V_117 . V_120 ,
V_117 . V_319 ) ;
F_91 ( V_12 ) ;
F_9 ( & V_108 ) ;
F_80 (pos, &pfm_buffer_fmt_list) {
V_105 = F_81 ( V_104 , T_4 , V_106 ) ;
F_285 ( V_328 , L_209 ,
V_105 -> V_107 [ 0 ] ,
V_105 -> V_107 [ 1 ] ,
V_105 -> V_107 [ 2 ] ,
V_105 -> V_107 [ 3 ] ,
V_105 -> V_107 [ 4 ] ,
V_105 -> V_107 [ 5 ] ,
V_105 -> V_107 [ 6 ] ,
V_105 -> V_107 [ 7 ] ,
V_105 -> V_107 [ 8 ] ,
V_105 -> V_107 [ 9 ] ,
V_105 -> V_107 [ 10 ] ,
V_105 -> V_107 [ 11 ] ,
V_105 -> V_107 [ 12 ] ,
V_105 -> V_107 [ 13 ] ,
V_105 -> V_107 [ 14 ] ,
V_105 -> V_107 [ 15 ] ,
V_105 -> V_109 ) ;
}
F_11 ( & V_108 ) ;
}
static int
F_286 ( struct V_458 * V_328 , void * V_304 )
{
unsigned long V_69 ;
unsigned int V_29 ;
int V_94 ;
if ( V_304 == V_459 ) {
F_284 ( V_328 ) ;
return 0 ;
}
V_94 = ( long ) V_304 - 1 ;
F_285 ( V_328 ,
L_210
L_211
L_212
L_213
L_214
L_215
L_216
L_217
L_218
L_219
L_220
L_221
L_222
L_223 ,
V_94 , V_330 [ V_94 ] . V_445 ,
V_94 , V_330 [ V_94 ] . V_455 ,
V_94 , V_330 [ V_94 ] . V_332 ,
V_94 , V_330 [ V_94 ] . V_454 ,
V_94 , V_330 [ V_94 ] . V_437 ,
V_94 , V_330 [ V_94 ] . V_440 ,
V_94 , V_330 [ V_94 ] . V_448 ,
V_94 , V_330 [ V_94 ] . V_465 ,
V_94 , F_287 ( V_466 , V_94 ) & V_367 ? 1 : 0 ,
V_94 , F_287 ( V_466 , V_94 ) & V_73 ? 1 : 0 ,
V_94 , F_287 ( V_466 , V_94 ) & V_368 ? 1 : 0 ,
V_94 , F_287 ( V_467 , V_94 ) ? F_287 ( V_467 , V_94 ) -> V_245 : - 1 ,
V_94 , F_287 ( V_468 , V_94 ) ,
V_94 , F_287 ( V_469 , V_94 ) ) ;
if ( F_288 () == 1 && V_280 . V_329 > 0 ) {
V_69 = F_23 () ;
F_29 () ;
F_285 ( V_328 ,
L_224
L_225 ,
V_94 , V_69 ,
V_94 , F_272 ( 0 ) ) ;
for ( V_29 = 0 ; F_175 ( V_29 ) == 0 ; V_29 ++ ) {
if ( F_289 ( V_29 ) == 0 ) continue;
F_285 ( V_328 ,
L_226
L_227 ,
V_94 , V_29 , F_272 ( V_29 ) ,
V_94 , V_29 , F_38 ( V_29 ) ) ;
}
}
return 0 ;
}
static int
F_290 ( struct V_161 * V_161 , struct V_8 * V_8 )
{
return F_291 ( V_8 , & V_470 ) ;
}
void
F_292 ( struct V_1 * V_2 , unsigned long V_151 , int V_471 )
{
struct V_90 * V_91 ;
unsigned long V_472 ;
unsigned long V_473 ;
V_473 = V_151 & V_73 ? 1 : 0 ;
if ( ( V_151 & V_368 ) == 0 || V_2 -> V_245 ) {
V_91 = F_121 ( V_2 ) ;
F_230 ( V_91 ) -> V_353 = V_471 ? V_473 : 0 ;
return;
}
if ( V_473 ) {
V_472 = F_24 ( V_74 ) ;
if ( V_471 ) {
F_26 ( V_74 , V_472 & ~ V_75 ) ;
F_16 () ;
F_18 () ;
return;
}
F_26 ( V_74 , V_472 | V_75 ) ;
F_19 () ;
F_18 () ;
}
}
static void
F_293 ( T_1 * V_32 , struct V_90 * V_91 )
{
struct V_1 * V_2 = V_32 -> V_154 ;
F_230 ( V_91 ) -> V_354 = 0 ;
F_230 ( V_91 ) -> V_370 = 1 ;
if ( F_122 () == V_2 ) {
F_42 ( ( L_228 ,
F_62 ( V_32 -> V_154 ) ) ) ;
F_242 ( NULL , NULL ) ;
}
F_217 ( V_2 , 0 ) ;
V_2 -> V_315 . V_316 = NULL ;
V_2 -> V_315 . V_12 &= ~ V_369 ;
F_42 ( ( L_229 , F_62 ( V_2 ) ) ) ;
}
void
F_294 ( struct V_1 * V_2 )
{
T_1 * V_32 ;
unsigned long V_12 ;
T_26 V_69 ;
V_32 = F_60 ( V_2 ) ;
if ( V_32 == NULL ) return;
V_12 = F_8 ( V_32 ) ;
if ( V_32 -> V_50 == V_166 ) {
struct V_90 * V_91 = F_121 ( V_2 ) ;
F_21 () ;
F_293 ( V_32 , V_91 ) ;
F_246 ( V_32 -> V_167 ) ;
F_10 ( V_32 , V_12 ) ;
F_57 ( V_32 ) ;
return;
}
F_29 () ;
V_69 = F_23 () ;
F_246 ( V_69 & ( V_474 ) ) ;
F_21 () ;
V_32 -> V_355 = V_69 & V_22 ;
F_242 ( NULL , NULL ) ;
F_67 ( V_32 -> V_84 , V_32 -> V_65 [ 0 ] ) ;
V_32 -> V_68 [ 0 ] = F_272 ( 0 ) ;
if ( V_32 -> V_68 [ 0 ] & ~ 0x1UL ) F_30 () ;
F_10 ( V_32 , V_12 ) ;
}
void
F_294 ( struct V_1 * V_2 )
{
T_1 * V_32 ;
T_26 V_69 ;
V_32 = F_60 ( V_2 ) ;
if ( V_32 == NULL ) return;
V_69 = F_23 () ;
F_246 ( V_69 & ( V_474 ) ) ;
F_21 () ;
V_32 -> V_355 = V_69 & V_22 ;
}
static void
F_241 ( struct V_1 * V_2 )
{
T_1 * V_32 ;
unsigned long V_12 ;
{ T_26 V_69 = F_23 () ;
F_246 ( V_69 & V_22 ) ;
}
V_32 = F_60 ( V_2 ) ;
F_105 ( V_32 , V_12 ) ;
F_242 ( NULL , NULL ) ;
F_67 ( V_32 -> V_84 , V_32 -> V_65 [ 0 ] ) ;
V_32 -> V_68 [ 0 ] = F_272 ( 0 ) ;
if ( V_32 -> V_68 [ 0 ] & ~ 0x1UL ) F_30 () ;
F_108 ( V_32 , V_12 ) ;
}
void
F_295 ( struct V_1 * V_2 )
{
T_1 * V_32 ;
unsigned long V_475 = 0UL , V_426 = 0UL ;
unsigned long V_12 ;
T_26 V_69 , V_476 ;
int V_477 ;
V_32 = F_60 ( V_2 ) ;
if ( F_203 ( V_32 == NULL ) ) return;
F_246 ( F_122 () ) ;
if ( F_203 ( ( V_2 -> V_315 . V_12 & V_369 ) == 0 ) ) return;
V_12 = F_8 ( V_32 ) ;
V_69 = F_23 () ;
V_477 = V_34 -> V_12 & V_478 ;
F_246 ( V_69 & ( V_22 | V_21 ) ) ;
F_246 ( V_69 & V_474 ) ;
if ( F_203 ( V_32 -> V_50 == V_166 ) ) {
struct V_90 * V_91 = F_121 ( V_2 ) ;
F_246 ( V_32 -> V_167 ) ;
F_293 ( V_32 , V_91 ) ;
F_10 ( V_32 , V_12 ) ;
F_57 ( V_32 ) ;
return;
}
if ( V_32 -> V_77 ) {
F_31 ( V_32 -> V_78 , V_34 -> V_79 ) ;
F_34 ( V_32 -> V_80 , V_34 -> V_81 ) ;
}
V_476 = V_32 -> V_355 ;
if ( F_296 ( V_32 ) == F_89 () && V_32 -> V_59 == F_297 () ) {
V_475 = V_32 -> V_299 [ 0 ] ;
V_426 = V_32 -> V_309 [ 0 ] ;
} else {
V_426 = V_280 . V_464 ? V_32 -> V_65 [ 0 ] : V_32 -> V_83 [ 0 ] ;
V_475 = V_32 -> V_85 [ 0 ] ;
}
if ( V_426 ) F_68 ( V_32 -> V_84 , V_426 ) ;
if ( V_475 ) F_71 ( V_32 -> V_68 , V_475 ) ;
if ( F_203 ( F_273 ( V_32 -> V_68 [ 0 ] ) ) ) {
F_28 ( 0 , V_32 -> V_68 [ 0 ] ) ;
F_29 () ;
V_32 -> V_68 [ 0 ] = 0UL ;
if ( V_477 ) F_298 ( V_479 ) ;
V_330 [ F_89 () ] . V_465 ++ ;
}
V_32 -> V_299 [ 0 ] = 0UL ;
V_32 -> V_309 [ 0 ] = 0UL ;
F_55 ( V_32 , F_89 () ) ;
F_239 () ;
F_240 ( V_32 ) ;
F_242 ( V_2 , V_32 ) ;
if ( F_198 ( V_476 ) ) F_22 () ;
F_10 ( V_32 , V_12 ) ;
}
void
F_295 ( struct V_1 * V_2 )
{
T_1 * V_32 ;
struct V_1 * V_152 ;
unsigned long V_426 , V_475 ;
T_26 V_69 , V_476 ;
int V_477 ;
V_152 = F_122 () ;
V_32 = F_60 ( V_2 ) ;
V_69 = F_23 () ;
F_246 ( V_69 & ( V_22 | V_21 ) ) ;
F_246 ( V_69 & V_474 ) ;
if ( V_32 -> V_77 ) {
F_31 ( V_32 -> V_78 , V_34 -> V_79 ) ;
F_34 ( V_32 -> V_80 , V_34 -> V_81 ) ;
}
V_476 = V_32 -> V_355 ;
V_477 = V_34 -> V_12 & V_478 ;
if ( F_198 ( V_152 == V_2 ) ) {
if ( F_198 ( V_476 ) ) F_22 () ;
return;
}
if ( V_152 ) F_241 ( V_152 ) ;
V_426 = V_280 . V_464 ? V_32 -> V_65 [ 0 ] : V_32 -> V_83 [ 0 ] ;
V_475 = V_32 -> V_85 [ 0 ] ;
F_68 ( V_32 -> V_84 , V_426 ) ;
F_71 ( V_32 -> V_68 , V_475 ) ;
if ( F_203 ( F_273 ( V_32 -> V_68 [ 0 ] ) ) ) {
F_28 ( 0 , V_32 -> V_68 [ 0 ] ) ;
F_29 () ;
V_32 -> V_68 [ 0 ] = 0UL ;
if ( V_477 ) F_298 ( V_479 ) ;
V_330 [ F_89 () ] . V_465 ++ ;
}
F_242 ( V_2 , V_32 ) ;
if ( F_198 ( V_476 ) ) F_22 () ;
}
static void
F_243 ( struct V_1 * V_2 , T_1 * V_32 )
{
T_26 V_412 ;
unsigned long V_480 , V_25 , V_481 , V_35 ;
int V_29 , V_273 = 0 ;
int V_482 ;
V_482 = V_32 -> V_154 == V_2 ? 1 : 0 ;
V_273 = ( F_122 () == V_2 ) || ( V_32 -> V_54 && V_32 -> V_153 == F_89 () ) ;
if ( V_273 ) {
F_242 ( NULL , NULL ) ;
F_42 ( ( L_230 ) ) ;
F_29 () ;
V_412 = F_272 ( 0 ) ;
F_30 () ;
} else {
V_412 = V_32 -> V_68 [ 0 ] ;
V_32 -> V_68 [ 0 ] = 0 ;
}
V_35 = V_34 -> V_35 ;
V_480 = V_32 -> V_65 [ 0 ] ;
F_42 ( ( L_231 , V_482 , V_35 , V_480 ) ) ;
for ( V_29 = 0 ; V_480 ; V_29 ++ , V_480 >>= 1 ) {
if ( ( V_480 & 0x1 ) == 0 ) continue;
V_25 = V_481 = V_273 ? F_38 ( V_29 ) : V_32 -> V_84 [ V_29 ] ;
if ( F_63 ( V_29 ) ) {
F_42 ( ( L_232 ,
F_62 ( V_2 ) ,
V_29 ,
V_32 -> V_33 [ V_29 ] . V_25 ,
V_25 & V_35 ) ) ;
V_25 = V_32 -> V_33 [ V_29 ] . V_25 + ( V_25 & V_35 ) ;
V_481 = 0UL ;
if ( V_412 & ( 1UL << V_29 ) ) {
V_25 += 1 + V_35 ;
F_42 ( ( L_233 , F_62 ( V_2 ) , V_29 ) ) ;
}
}
F_42 ( ( L_234 , F_62 ( V_2 ) , V_29 , V_25 , V_481 ) ) ;
if ( V_482 ) V_32 -> V_84 [ V_29 ] = V_481 ;
V_32 -> V_33 [ V_29 ] . V_25 = V_25 ;
}
}
static void
F_299 ( void * V_18 )
{
struct V_90 * V_91 ;
V_91 = F_121 ( V_3 ) ;
F_42 ( ( L_235 ) ) ;
F_21 () ;
F_16 () ;
F_230 ( V_91 ) -> V_353 = 0 ;
F_27 () ;
F_29 () ;
}
void
F_300 ( void * V_18 )
{
struct V_90 * V_91 ;
V_91 = F_121 ( V_3 ) ;
F_42 ( ( L_235 ) ) ;
F_21 () ;
F_16 () ;
F_230 ( V_91 ) -> V_353 = 0 ;
F_30 () ;
F_29 () ;
}
int
F_301 ( T_30 * V_483 )
{
int V_92 , V_29 ;
int V_484 ;
if ( V_483 == NULL || V_483 -> V_456 == NULL ) return - V_110 ;
if ( V_453 ) return - V_112 ;
if ( ! F_302 ( & V_485 ) ) {
return - V_112 ;
}
F_303 (reserve_cpu) {
V_92 = F_87 ( NULL , 1 , V_484 ) ;
if ( V_92 ) goto V_486;
}
V_92 = F_304 ( F_299 , NULL , 1 ) ;
if ( V_92 ) {
F_42 ( ( L_236 , V_92 ) ) ;
goto V_486;
}
V_453 = V_483 ;
F_11 ( & V_485 ) ;
return 0 ;
V_486:
F_303 (i) {
if ( V_29 >= V_484 ) break;
F_92 ( NULL , 1 , V_29 ) ;
}
F_11 ( & V_485 ) ;
return V_92 ;
}
int
F_305 ( T_30 * V_483 )
{
int V_29 ;
int V_92 ;
if ( V_483 == NULL ) return - V_110 ;
if ( V_453 != V_483 ) return - V_110 ;
if ( ! F_302 ( & V_485 ) ) {
return - V_112 ;
}
V_453 = NULL ;
V_92 = F_304 ( F_300 , NULL , 1 ) ;
if ( V_92 ) {
F_42 ( ( L_236 , V_92 ) ) ;
}
F_303 (i) {
F_92 ( NULL , 1 , V_29 ) ;
}
F_11 ( & V_485 ) ;
return 0 ;
}
static int T_6
F_306 ( void )
{
T_31 * * V_246 ;
int V_487 ;
V_487 = V_488 -> V_487 ;
V_246 = V_489 ;
while( * V_246 ) {
if ( ( * V_246 ) -> V_490 ) {
if ( ( * V_246 ) -> V_490 () == 0 ) goto V_491;
} else if ( ( * V_246 ) -> V_492 == V_487 || ( * V_246 ) -> V_492 == 0xff ) {
goto V_491;
}
V_246 ++ ;
}
return - 1 ;
V_491:
V_34 = * V_246 ;
return 0 ;
}
int T_6
F_307 ( void )
{
unsigned int V_493 , V_494 , V_29 ;
F_65 ( L_237 ,
V_461 ,
V_462 ,
V_479 ) ;
if ( F_306 () ) {
F_65 ( V_115 L_238 ,
V_488 -> V_487 ) ;
return - V_495 ;
}
V_493 = 0 ;
for ( V_29 = 0 ; F_175 ( V_29 ) == 0 ; V_29 ++ ) {
if ( F_176 ( V_29 ) == 0 ) continue;
V_34 -> V_235 [ V_29 >> 6 ] |= 1UL << ( V_29 & 63 ) ;
V_493 ++ ;
}
V_34 -> V_496 = V_493 ;
V_493 = 0 ; V_494 = 0 ;
for ( V_29 = 0 ; F_308 ( V_29 ) == 0 ; V_29 ++ ) {
if ( F_204 ( V_29 ) == 0 ) continue;
V_34 -> V_236 [ V_29 >> 6 ] |= 1UL << ( V_29 & 63 ) ;
V_493 ++ ;
if ( F_63 ( V_29 ) ) V_494 ++ ;
}
V_34 -> V_497 = V_493 ;
V_34 -> V_498 = V_494 ;
if ( V_34 -> V_317 ) {
if ( V_34 -> V_79 > V_499 ) {
F_65 ( V_115 L_239 , V_34 -> V_79 ) ;
V_34 = NULL ;
return - 1 ;
}
if ( V_34 -> V_81 > V_499 ) {
F_65 ( V_115 L_240 , V_34 -> V_79 ) ;
V_34 = NULL ;
return - 1 ;
}
}
F_65 ( L_241 ,
V_34 -> V_463 ,
V_34 -> V_496 ,
V_34 -> V_497 ,
V_34 -> V_498 ,
F_309 ( V_34 -> V_35 ) ) ;
if ( V_34 -> V_497 >= V_500 || V_34 -> V_496 >= V_501 ) {
F_65 ( V_71 L_242 ) ;
V_34 = NULL ;
return - 1 ;
}
V_502 = F_310 ( L_243 , V_185 , NULL , & V_503 ) ;
if ( V_502 == NULL ) {
F_65 ( V_71 L_244 ) ;
V_34 = NULL ;
return - 1 ;
}
V_504 = F_311 ( V_505 ) ;
F_53 ( & V_117 . V_506 ) ;
F_53 ( & V_108 ) ;
F_96 () ;
for( V_29 = 0 ; V_29 < V_331 ; V_29 ++ ) V_330 [ V_29 ] . V_332 = ~ 0UL ;
return 0 ;
}
void
F_312 ( void )
{
static int V_337 = 1 ;
F_16 () ;
F_21 () ;
F_30 () ;
if ( V_337 ) {
F_313 ( V_479 , & V_507 ) ;
V_337 = 0 ;
}
F_26 ( V_508 , V_479 ) ;
F_29 () ;
}
void
F_314 ( const char * V_509 )
{
struct V_1 * V_2 ;
struct V_90 * V_91 ;
T_1 * V_32 ;
unsigned long V_69 , V_472 , V_151 , V_12 ;
int V_29 , V_429 ;
F_124 ( V_12 ) ;
V_429 = F_89 () ;
V_91 = F_121 ( V_3 ) ;
V_151 = F_66 () ;
V_472 = F_24 ( V_74 ) ;
if ( V_151 == 0 && F_230 ( V_91 ) -> V_353 == 0 && ( V_472 & V_75 ) == 0 ) {
F_126 ( V_12 ) ;
return;
}
F_65 ( L_245 ,
V_429 ,
V_509 ,
F_62 ( V_3 ) ,
V_91 -> V_423 ,
V_3 -> V_510 ) ;
V_2 = F_122 () ;
V_32 = F_123 () ;
F_65 ( L_246 , V_429 , V_2 ? F_62 ( V_2 ) : - 1 , V_32 ) ;
V_69 = F_23 () ;
F_65 ( L_247 ,
V_429 ,
F_272 ( 0 ) ,
V_69 & V_21 ? 1 : 0 ,
V_69 & V_22 ? 1 : 0 ,
V_472 & V_75 ? 1 : 0 ,
V_151 ,
F_230 ( V_91 ) -> V_354 ,
F_230 ( V_91 ) -> V_353 ) ;
F_230 ( V_91 ) -> V_354 = 0 ;
F_230 ( V_91 ) -> V_353 = 0 ;
for ( V_29 = 1 ; F_175 ( V_29 ) == 0 ; V_29 ++ ) {
if ( F_176 ( V_29 ) == 0 ) continue;
F_65 ( L_248 , V_429 , V_29 , F_272 ( V_29 ) , V_29 , V_32 -> V_68 [ V_29 ] ) ;
}
for ( V_29 = 1 ; F_308 ( V_29 ) == 0 ; V_29 ++ ) {
if ( F_204 ( V_29 ) == 0 ) continue;
F_65 ( L_249 , V_429 , V_29 , F_38 ( V_29 ) , V_29 , V_32 -> V_84 [ V_29 ] ) ;
}
if ( V_32 ) {
F_65 ( L_250 ,
V_429 ,
V_32 -> V_50 ,
V_32 -> V_159 ,
V_32 -> V_167 ,
V_32 -> V_40 ,
V_32 -> V_38 ,
V_32 -> V_355 ) ;
}
F_126 ( V_12 ) ;
}
void
F_315 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
struct V_334 * V_315 ;
F_42 ( ( L_251 , F_62 ( V_2 ) ) ) ;
V_315 = & V_2 -> V_315 ;
V_315 -> V_316 = NULL ;
F_217 ( V_2 , 0 ) ;
}
T_27 long
F_249 ( int V_147 , int V_146 , void * V_95 , int V_249 )
{
return - V_384 ;
}
