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
static struct V_8 *
F_12 ( struct V_9 * V_10 , int V_11 , const char * V_12 , void * V_13 )
{
return F_13 ( V_10 , L_1 , NULL , & V_14 ,
V_15 ) ;
}
static inline void
F_14 ( void )
{
F_15 ( V_16 ) ;
F_16 () ;
}
static inline void
F_17 ( void )
{
F_18 ( V_16 ) ;
F_16 () ;
}
static inline void
F_19 ( void )
{
F_15 ( V_17 ) ;
F_16 () ;
}
static inline void
F_20 ( void )
{
F_18 ( V_17 ) ;
F_16 () ;
}
static inline unsigned long
F_21 ( void )
{
unsigned long V_18 ;
V_18 = F_22 ( V_19 ) ;
F_16 () ;
return V_18 ;
}
static inline void
F_23 ( unsigned long V_20 )
{
F_24 ( V_21 , V_20 ) ;
F_16 () ;
}
static inline void
F_25 ( void )
{
F_26 ( 0 , 1UL ) ;
F_27 () ;
}
static inline void
F_28 ( void )
{
F_26 ( 0 , 0UL ) ;
F_27 () ;
}
static inline void
F_29 ( unsigned long * V_22 , unsigned int V_23 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
F_30 ( V_24 , V_22 [ V_24 ] ) ;
F_31 () ;
}
F_16 () ;
}
static inline void
F_32 ( unsigned long * V_25 , unsigned int V_26 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
F_33 ( V_24 , V_25 [ V_24 ] ) ;
F_34 () ;
}
F_27 () ;
}
static inline unsigned long
F_35 ( T_1 * V_27 , int V_24 )
{
return V_27 -> V_28 [ V_24 ] . V_20 + ( F_36 ( V_24 ) & V_29 -> V_30 ) ;
}
static inline void
F_37 ( T_1 * V_27 , int V_24 , unsigned long V_20 )
{
unsigned long V_30 = V_29 -> V_30 ;
V_27 -> V_28 [ V_24 ] . V_20 = V_20 & ~ V_30 ;
F_38 ( V_24 , V_20 & V_30 ) ;
}
static T_2 *
F_39 ( T_1 * V_27 )
{
int V_31 , V_32 ;
V_32 = ( V_27 -> V_33 + 1 ) % V_34 ;
F_40 ( ( L_2 , V_27 , V_27 -> V_35 , V_27 -> V_33 ) ) ;
if ( V_32 == V_27 -> V_35 ) return NULL ;
V_31 = V_27 -> V_33 ;
V_27 -> V_33 = V_32 ;
F_40 ( ( L_3 , V_27 , V_27 -> V_35 , V_27 -> V_33 , V_31 ) ) ;
return V_27 -> V_36 + V_31 ;
}
static T_2 *
F_41 ( T_1 * V_27 )
{
T_2 * V_37 ;
F_40 ( ( L_4 , V_27 , V_27 -> V_35 , V_27 -> V_33 ) ) ;
if ( F_42 ( V_27 ) ) return NULL ;
V_37 = V_27 -> V_36 + V_27 -> V_35 ;
V_27 -> V_35 = ( V_27 -> V_35 + 1 ) % V_34 ;
F_40 ( ( L_5 , V_27 , V_27 -> V_35 , V_27 -> V_33 , V_37 -> V_38 . V_39 ) ) ;
return V_37 ;
}
static void
F_43 ( T_1 * V_27 )
{
V_27 -> V_35 = V_27 -> V_33 = 0 ;
F_40 ( ( L_6 , V_27 ) ) ;
}
static void *
F_44 ( unsigned long V_40 )
{
void * V_41 ;
unsigned long V_42 ;
V_40 = F_45 ( V_40 ) ;
V_41 = F_46 ( V_40 ) ;
if ( V_41 ) {
V_42 = ( unsigned long ) V_41 ;
while ( V_40 > 0 ) {
F_3 ( V_42 ) ;
V_42 += V_43 ;
V_40 -= V_43 ;
}
}
return V_41 ;
}
static void
F_47 ( void * V_41 , unsigned long V_40 )
{
unsigned long V_42 ;
if ( V_41 ) {
F_40 ( ( L_7 , V_41 , V_40 ) ) ;
V_42 = ( unsigned long ) V_41 ;
while ( ( long ) V_40 > 0 ) {
F_6 ( V_42 ) ;
V_42 += V_43 ;
V_40 -= V_43 ;
}
F_48 ( V_41 ) ;
}
return;
}
static T_1 *
F_49 ( int V_44 )
{
T_1 * V_27 ;
V_27 = F_50 ( sizeof( T_1 ) , V_45 ) ;
if ( V_27 ) {
F_40 ( ( L_8 , V_27 ) ) ;
F_51 ( & V_27 -> V_6 ) ;
V_27 -> V_46 = V_47 ;
V_27 -> V_48 = ( V_44 & V_49 ) ? 1 : 0 ;
V_27 -> V_50 = ( V_44 & V_51 ) ? 1 : 0 ;
V_27 -> V_52 = ( V_44 & V_53 ) ? 1 : 0 ;
F_52 ( & V_27 -> V_54 ) ;
V_27 -> V_55 = V_56 ;
F_53 ( V_27 , - 1 ) ;
V_27 -> V_35 = V_27 -> V_33 = 0 ;
F_54 ( & V_27 -> V_57 ) ;
F_54 ( & V_27 -> V_58 ) ;
}
return V_27 ;
}
static void
F_55 ( T_1 * V_27 )
{
if ( V_27 ) {
F_40 ( ( L_9 , V_27 ) ) ;
F_56 ( V_27 ) ;
}
}
static void
F_57 ( struct V_1 * V_2 )
{
T_1 * V_27 = F_58 ( V_2 ) ;
unsigned long V_59 , V_20 , V_60 ;
int V_24 ;
F_59 ( ( L_10 , F_60 ( V_2 ) ) ) ;
V_60 = V_29 -> V_30 ;
V_59 = V_27 -> V_61 [ 0 ] ;
for ( V_24 = 0 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1 ) == 0 ) continue;
V_20 = F_36 ( V_24 ) ;
if ( F_61 ( V_24 ) ) {
V_27 -> V_28 [ V_24 ] . V_20 += ( V_20 & V_60 ) ;
} else {
V_27 -> V_28 [ V_24 ] . V_20 = V_20 ;
}
F_59 ( ( L_11 ,
V_24 ,
V_27 -> V_28 [ V_24 ] . V_20 ,
V_20 & V_60 ) ) ;
}
V_59 = V_27 -> V_62 [ 0 ] >> V_63 ;
for( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1 ) == 0UL ) continue;
F_26 ( V_24 , V_27 -> V_64 [ V_24 ] & ~ 0xfUL ) ;
V_27 -> V_64 [ V_24 ] &= ~ 0xfUL ;
F_59 ( ( L_12 , V_24 , V_27 -> V_64 [ V_24 ] ) ) ;
}
F_27 () ;
}
static void
F_62 ( struct V_1 * V_2 )
{
T_1 * V_27 = F_58 ( V_2 ) ;
unsigned long V_59 , V_60 ;
unsigned long V_65 , V_20 ;
int V_24 , V_66 ;
V_66 = V_27 -> V_50 ;
V_60 = V_29 -> V_30 ;
if ( V_2 != V_3 ) {
F_63 ( V_67 L_13 , __LINE__ , F_60 ( V_2 ) , F_60 ( V_3 ) ) ;
return;
}
if ( V_27 -> V_46 != V_68 ) {
F_63 ( V_67 L_14 , __LINE__ ,
F_60 ( V_2 ) , F_60 ( V_3 ) , V_27 -> V_46 ) ;
return;
}
V_65 = F_21 () ;
if ( V_66 && ( F_64 () & V_69 ) ) {
F_24 ( V_70 , F_22 ( V_70 ) & ~ V_71 ) ;
F_14 () ;
} else {
F_19 () ;
}
V_59 = V_27 -> V_61 [ 0 ] ;
for ( V_24 = 0 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1 ) == 0 ) continue;
if ( F_61 ( V_24 ) ) {
V_20 = V_27 -> V_28 [ V_24 ] . V_20 & V_60 ;
V_27 -> V_28 [ V_24 ] . V_20 &= ~ V_60 ;
} else {
V_20 = V_27 -> V_28 [ V_24 ] . V_20 ;
}
F_38 ( V_24 , V_20 ) ;
F_40 ( ( L_11 ,
V_24 ,
V_27 -> V_28 [ V_24 ] . V_20 ,
V_20 ) ) ;
}
V_59 = V_27 -> V_62 [ 0 ] >> V_63 ;
for( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1 ) == 0UL ) continue;
V_27 -> V_64 [ V_24 ] = V_27 -> V_72 [ V_24 ] ;
F_26 ( V_24 , V_27 -> V_64 [ V_24 ] ) ;
F_40 ( ( L_15 ,
F_60 ( V_2 ) , V_24 , V_27 -> V_64 [ V_24 ] ) ) ;
}
F_27 () ;
if ( V_27 -> V_73 ) {
F_29 ( V_27 -> V_74 , V_29 -> V_75 ) ;
F_32 ( V_27 -> V_76 , V_29 -> V_77 ) ;
}
if ( V_66 && ( F_64 () & V_69 ) ) {
F_24 ( V_70 , F_22 ( V_70 ) | V_71 ) ;
F_16 () ;
}
F_23 ( V_65 ) ;
}
static inline void
F_65 ( unsigned long * V_78 , unsigned long V_59 )
{
int V_24 ;
F_27 () ;
for ( V_24 = 0 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( V_59 & 0x1 ) V_78 [ V_24 ] = F_36 ( V_24 ) ;
}
}
static inline void
F_66 ( unsigned long * V_78 , unsigned long V_59 )
{
int V_24 ;
unsigned long V_20 , V_30 = V_29 -> V_30 ;
for ( V_24 = 0 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1 ) == 0 ) continue;
V_20 = F_61 ( V_24 ) ? V_78 [ V_24 ] & V_30 : V_78 [ V_24 ] ;
F_38 ( V_24 , V_20 ) ;
}
F_27 () ;
}
static inline void
F_67 ( struct V_1 * V_2 , T_1 * V_27 )
{
unsigned long V_30 = V_29 -> V_30 ;
unsigned long V_59 = V_27 -> V_79 [ 0 ] ;
unsigned long V_20 ;
int V_24 ;
F_40 ( ( L_16 , V_59 ) ) ;
for ( V_24 = 0 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
V_20 = V_27 -> V_28 [ V_24 ] . V_20 ;
if ( F_61 ( V_24 ) ) {
V_27 -> V_28 [ V_24 ] . V_20 = V_20 & ~ V_30 ;
V_20 &= V_30 ;
}
V_27 -> V_80 [ V_24 ] = V_20 ;
F_40 ( ( L_17 ,
V_24 ,
V_27 -> V_80 [ V_24 ] ,
V_27 -> V_28 [ V_24 ] . V_20 ) ) ;
}
}
static inline void
F_68 ( struct V_1 * V_2 , T_1 * V_27 )
{
unsigned long V_59 = V_27 -> V_81 [ 0 ] ;
int V_24 ;
F_40 ( ( L_16 , V_59 ) ) ;
for ( V_24 = 0 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
V_27 -> V_64 [ V_24 ] = V_27 -> V_72 [ V_24 ] ;
F_40 ( ( L_12 , V_24 , V_27 -> V_64 [ V_24 ] ) ) ;
}
}
static inline void
F_69 ( unsigned long * V_82 , unsigned long V_59 )
{
int V_24 ;
for ( V_24 = 0 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1 ) == 0 ) continue;
F_26 ( V_24 , V_82 [ V_24 ] ) ;
}
F_27 () ;
}
static inline int
F_70 ( T_3 V_4 , T_3 V_83 )
{
return memcmp ( V_4 , V_83 , sizeof( T_3 ) ) ;
}
static inline int
F_71 ( T_4 * V_84 , struct V_1 * V_2 , void * V_85 , struct V_86 * V_87 )
{
int V_88 = 0 ;
if ( V_84 -> V_89 ) V_88 = (* V_84 -> V_89 )( V_2 , V_85 , V_87 ) ;
return V_88 ;
}
static inline int
F_72 ( T_4 * V_84 , struct V_1 * V_2 , unsigned int V_11 , int V_90 , void * V_91 , unsigned long * V_40 )
{
int V_88 = 0 ;
if ( V_84 -> V_92 ) V_88 = (* V_84 -> V_92 )( V_2 , V_11 , V_90 , V_91 , V_40 ) ;
return V_88 ;
}
static inline int
F_73 ( T_4 * V_84 , struct V_1 * V_2 , unsigned int V_11 ,
int V_90 , void * V_91 )
{
int V_88 = 0 ;
if ( V_84 -> V_93 ) V_88 = (* V_84 -> V_93 )( V_2 , V_11 , V_90 , V_91 ) ;
return V_88 ;
}
static inline int
F_74 ( T_4 * V_84 , struct V_1 * V_2 , void * V_85 , unsigned int V_11 ,
int V_90 , void * V_91 )
{
int V_88 = 0 ;
if ( V_84 -> V_94 ) V_88 = (* V_84 -> V_94 )( V_2 , V_85 , V_11 , V_90 , V_91 ) ;
return V_88 ;
}
static inline int
F_75 ( T_4 * V_84 , struct V_1 * V_2 , T_5 * V_95 , void * V_85 , struct V_86 * V_87 )
{
int V_88 = 0 ;
if ( V_84 -> V_96 ) V_88 = (* V_84 -> V_96 )( V_2 , V_95 , V_85 , V_87 ) ;
return V_88 ;
}
static inline int
F_76 ( T_4 * V_84 , struct V_1 * V_2 , T_5 * V_95 , void * V_85 , struct V_86 * V_87 )
{
int V_88 = 0 ;
if ( V_84 -> V_97 ) V_88 = (* V_84 -> V_97 )( V_2 , V_95 , V_85 , V_87 ) ;
return V_88 ;
}
static T_4 *
F_77 ( T_3 V_98 )
{
struct V_99 * V_100 ;
T_4 * V_101 ;
F_78 (pos, &pfm_buffer_fmt_list) {
V_101 = F_79 ( V_100 , T_4 , V_102 ) ;
if ( F_70 ( V_98 , V_101 -> V_103 ) == 0 )
return V_101 ;
}
return NULL ;
}
static T_4 *
F_80 ( T_3 V_98 )
{
T_4 * V_84 ;
F_9 ( & V_104 ) ;
V_84 = F_77 ( V_98 ) ;
F_11 ( & V_104 ) ;
return V_84 ;
}
int
F_81 ( T_4 * V_84 )
{
int V_88 = 0 ;
if ( V_84 == NULL || V_84 -> V_105 == NULL ) return - V_106 ;
if ( V_84 -> V_107 == NULL ) return - V_106 ;
F_9 ( & V_104 ) ;
if ( F_77 ( V_84 -> V_103 ) ) {
F_63 ( V_67 L_18 , V_84 -> V_105 ) ;
V_88 = - V_108 ;
goto V_109;
}
F_82 ( & V_84 -> V_102 , & V_110 ) ;
F_63 ( V_111 L_19 , V_84 -> V_105 ) ;
V_109:
F_11 ( & V_104 ) ;
return V_88 ;
}
int
F_83 ( T_3 V_98 )
{
T_4 * V_84 ;
int V_88 = 0 ;
F_9 ( & V_104 ) ;
V_84 = F_77 ( V_98 ) ;
if ( ! V_84 ) {
F_63 ( V_67 L_20 ) ;
V_88 = - V_106 ;
goto V_109;
}
F_84 ( & V_84 -> V_102 ) ;
F_63 ( V_111 L_21 , V_84 -> V_105 ) ;
V_109:
F_11 ( & V_104 ) ;
return V_88 ;
}
static int
F_85 ( struct V_1 * V_2 , int V_112 , unsigned int V_90 )
{
unsigned long V_11 ;
F_86 ( V_11 ) ;
F_40 ( ( L_22 ,
V_113 . V_114 ,
V_113 . V_115 ,
V_113 . V_116 ,
V_112 ,
V_90 ) ) ;
if ( V_112 ) {
if ( V_113 . V_115 > 0UL ) {
F_40 ( ( L_23 ,
V_113 . V_115 ) ) ;
goto abort;
}
if ( V_113 . V_117 [ V_90 ] ) goto V_118;
F_40 ( ( L_24 , V_90 , F_87 () ) ) ;
V_113 . V_117 [ V_90 ] = V_2 ;
V_113 . V_114 ++ ;
} else {
if ( V_113 . V_114 ) goto abort;
V_113 . V_115 ++ ;
}
F_40 ( ( L_25 ,
V_113 . V_114 ,
V_113 . V_115 ,
V_113 . V_116 ,
V_112 ,
V_90 ) ) ;
F_88 ( true ) ;
F_89 ( V_11 ) ;
return 0 ;
V_118:
F_40 ( ( L_26 ,
F_60 ( V_113 . V_117 [ V_90 ] ) ,
V_90 ) ) ;
abort:
F_89 ( V_11 ) ;
return - V_108 ;
}
static int
F_90 ( T_1 * V_27 , int V_112 , unsigned int V_90 )
{
unsigned long V_11 ;
F_86 ( V_11 ) ;
F_40 ( ( L_22 ,
V_113 . V_114 ,
V_113 . V_115 ,
V_113 . V_116 ,
V_112 ,
V_90 ) ) ;
if ( V_112 ) {
V_113 . V_117 [ V_90 ] = NULL ;
if ( V_27 && V_27 -> V_73 ) {
if ( V_113 . V_116 == 0 ) {
F_63 ( V_67 L_27 , V_27 ) ;
} else {
V_113 . V_116 -- ;
}
}
V_113 . V_114 -- ;
} else {
V_113 . V_115 -- ;
}
F_40 ( ( L_25 ,
V_113 . V_114 ,
V_113 . V_115 ,
V_113 . V_116 ,
V_112 ,
V_90 ) ) ;
F_88 ( false ) ;
F_89 ( V_11 ) ;
return 0 ;
}
static int
F_91 ( void * V_119 , unsigned long V_40 )
{
struct V_1 * V_2 = V_3 ;
int V_120 ;
if ( V_2 -> V_121 == NULL || V_40 == 0UL || V_119 == NULL ) {
F_63 ( V_67 L_28 , F_60 ( V_2 ) , V_2 -> V_121 ) ;
return - V_106 ;
}
F_40 ( ( L_29 , V_119 , V_40 ) ) ;
V_120 = F_92 ( ( unsigned long ) V_119 , V_40 ) ;
if ( V_120 != 0 ) {
F_63 ( V_67 L_30 , F_60 ( V_2 ) , V_119 , V_40 ) ;
}
F_40 ( ( L_31 , V_119 , V_40 , V_120 ) ) ;
return 0 ;
}
static inline void
F_93 ( T_4 * V_84 )
{
if ( V_84 == NULL ) return;
F_71 ( V_84 , V_3 , NULL , NULL ) ;
}
static int T_6
F_94 ( void )
{
int V_122 = F_95 ( & V_123 ) ;
if ( ! V_122 ) {
V_124 = F_96 ( & V_123 ) ;
V_122 = F_97 ( V_124 ) ;
if ( F_98 ( V_124 ) )
F_99 ( & V_123 ) ;
else
V_122 = 0 ;
}
return V_122 ;
}
static T_7
F_100 ( struct V_125 * V_126 , char T_8 * V_85 , T_9 V_40 , T_10 * V_127 )
{
T_1 * V_27 ;
T_2 * V_37 ;
T_7 V_88 ;
unsigned long V_11 ;
F_101 ( V_128 , V_3 ) ;
if ( F_102 ( V_126 ) == 0 ) {
F_63 ( V_67 L_32 , F_60 ( V_3 ) ) ;
return - V_106 ;
}
V_27 = V_126 -> V_129 ;
if ( V_27 == NULL ) {
F_63 ( V_67 L_33 , F_60 ( V_3 ) ) ;
return - V_106 ;
}
if ( V_40 < sizeof( T_2 ) ) {
F_40 ( ( L_34 , V_27 , sizeof( T_2 ) ) ) ;
return - V_106 ;
}
F_103 ( V_27 , V_11 ) ;
F_104 ( & V_27 -> V_57 , & V_128 ) ;
for(; ; ) {
F_105 ( V_130 ) ;
F_40 ( ( L_35 , V_27 -> V_35 , V_27 -> V_33 ) ) ;
V_88 = 0 ;
if( F_42 ( V_27 ) == 0 ) break;
F_106 ( V_27 , V_11 ) ;
V_88 = - V_131 ;
if( V_126 -> V_132 & V_133 ) break;
if( F_107 ( V_3 ) ) {
V_88 = - V_134 ;
break;
}
F_108 () ;
F_103 ( V_27 , V_11 ) ;
}
F_40 ( ( L_36 , F_60 ( V_3 ) , V_88 ) ) ;
F_105 ( V_135 ) ;
F_109 ( & V_27 -> V_57 , & V_128 ) ;
if ( V_88 < 0 ) goto abort;
V_88 = - V_106 ;
V_37 = F_41 ( V_27 ) ;
if ( V_37 == NULL ) {
F_63 ( V_67 L_37 , V_27 , F_60 ( V_3 ) ) ;
goto V_136;
}
F_40 ( ( L_38 , V_37 -> V_38 . V_137 , V_37 -> V_38 . V_39 ) ) ;
V_88 = - V_138 ;
if( F_110 ( V_85 , V_37 , sizeof( T_2 ) ) == 0 ) V_88 = sizeof( T_2 ) ;
V_136:
F_106 ( V_27 , V_11 ) ;
abort:
return V_88 ;
}
static T_7
F_111 ( struct V_125 * V_125 , const char T_8 * V_139 ,
T_9 V_40 , T_10 * V_127 )
{
F_40 ( ( L_39 ) ) ;
return - V_106 ;
}
static unsigned int
F_112 ( struct V_125 * V_126 , T_11 * V_128 )
{
T_1 * V_27 ;
unsigned long V_11 ;
unsigned int V_59 = 0 ;
if ( F_102 ( V_126 ) == 0 ) {
F_63 ( V_67 L_32 , F_60 ( V_3 ) ) ;
return 0 ;
}
V_27 = V_126 -> V_129 ;
if ( V_27 == NULL ) {
F_63 ( V_67 L_40 , F_60 ( V_3 ) ) ;
return 0 ;
}
F_40 ( ( L_41 , V_27 -> V_140 ) ) ;
F_113 ( V_126 , & V_27 -> V_57 , V_128 ) ;
F_103 ( V_27 , V_11 ) ;
if ( F_42 ( V_27 ) == 0 )
V_59 = V_141 | V_142 ;
F_106 ( V_27 , V_11 ) ;
F_40 ( ( L_42 , V_27 -> V_140 , V_59 ) ) ;
return V_59 ;
}
static long
F_114 ( struct V_125 * V_125 , unsigned int V_143 , unsigned long V_91 )
{
F_40 ( ( L_43 ) ) ;
return - V_106 ;
}
static inline int
F_115 ( int V_144 , struct V_125 * V_126 , T_1 * V_27 , int V_145 )
{
int V_88 ;
V_88 = F_116 ( V_144 , V_126 , V_145 , & V_27 -> V_146 ) ;
F_40 ( ( L_44 ,
F_60 ( V_3 ) ,
V_144 ,
V_145 ,
V_27 -> V_146 , V_88 ) ) ;
return V_88 ;
}
static int
F_117 ( int V_144 , struct V_125 * V_126 , int V_145 )
{
T_1 * V_27 ;
int V_88 ;
if ( F_102 ( V_126 ) == 0 ) {
F_63 ( V_67 L_45 , F_60 ( V_3 ) ) ;
return - V_147 ;
}
V_27 = V_126 -> V_129 ;
if ( V_27 == NULL ) {
F_63 ( V_67 L_46 , F_60 ( V_3 ) ) ;
return - V_147 ;
}
V_88 = F_115 ( V_144 , V_126 , V_27 , V_145 ) ;
F_40 ( ( L_47 ,
V_144 ,
V_145 ,
V_27 -> V_146 , V_88 ) ) ;
return V_88 ;
}
static void
F_118 ( void * V_148 )
{
T_1 * V_27 = ( T_1 * ) V_148 ;
struct V_86 * V_87 = F_119 ( V_3 ) ;
struct V_1 * V_149 ;
unsigned long V_11 ;
int V_88 ;
if ( V_27 -> V_150 != F_87 () ) {
F_63 ( V_67 L_48 ,
V_27 -> V_150 ,
F_87 () ) ;
return;
}
V_149 = F_120 () ;
if ( V_149 != V_27 -> V_151 ) {
F_63 ( V_67 L_49 ,
F_87 () ,
F_60 ( V_149 ) , F_60 ( V_27 -> V_151 ) ) ;
return;
}
if ( F_121 () != V_27 ) {
F_63 ( V_67 L_50 ,
F_87 () ,
F_121 () , V_27 ) ;
return;
}
F_40 ( ( L_51 , F_87 () , F_60 ( V_27 -> V_151 ) ) ) ;
F_122 ( V_11 ) ;
V_88 = F_123 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) {
F_40 ( ( L_52 , V_88 ) ) ;
}
F_124 ( V_11 ) ;
}
static void
F_125 ( T_1 * V_27 )
{
int V_88 ;
F_40 ( ( L_53 , V_27 -> V_150 ) ) ;
V_88 = F_126 ( V_27 -> V_150 , F_118 , V_27 , 1 ) ;
F_40 ( ( L_54 , V_27 -> V_150 , V_88 ) ) ;
}
static int
F_127 ( struct V_125 * V_126 , T_12 V_152 )
{
T_1 * V_27 ;
struct V_1 * V_2 ;
struct V_86 * V_87 ;
unsigned long V_11 ;
unsigned long V_153 = 0UL ;
void * V_154 = NULL ;
int V_155 , V_66 ;
if ( F_102 ( V_126 ) == 0 ) {
F_40 ( ( L_55 ) ) ;
return - V_147 ;
}
V_27 = V_126 -> V_129 ;
if ( V_27 == NULL ) {
F_63 ( V_67 L_56 , F_60 ( V_3 ) ) ;
return - V_147 ;
}
F_103 ( V_27 , V_11 ) ;
V_155 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
V_2 = F_128 ( V_27 ) ;
V_87 = F_119 ( V_2 ) ;
F_40 ( ( L_57 ,
V_155 ,
V_2 == V_3 ? 1 : 0 ) ) ;
if ( V_2 == V_3 ) {
#ifdef F_129
if ( V_66 && V_27 -> V_150 != F_87 () ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
F_124 ( V_11 ) ;
F_125 ( V_27 ) ;
F_122 ( V_11 ) ;
} else
#endif
{
F_40 ( ( L_59 ) ) ;
F_123 ( V_27 , NULL , 0 , V_87 ) ;
F_40 ( ( L_60 , V_27 -> V_46 ) ) ;
}
}
if ( V_27 -> V_156 && V_3 -> V_121 ) {
V_154 = V_27 -> V_156 ;
V_153 = V_27 -> V_157 ;
}
F_106 ( V_27 , V_11 ) ;
if ( V_154 ) F_91 ( V_154 , V_153 ) ;
return 0 ;
}
static int
F_130 ( struct V_158 * V_158 , struct V_125 * V_126 )
{
T_1 * V_27 ;
struct V_1 * V_2 ;
struct V_86 * V_87 ;
F_101 ( V_128 , V_3 ) ;
unsigned long V_11 ;
unsigned long V_153 = 0UL ;
void * V_159 = NULL ;
int V_160 = 1 ;
int V_155 , V_66 ;
F_40 ( ( L_61 , V_126 -> V_129 ) ) ;
if ( F_102 ( V_126 ) == 0 ) {
F_40 ( ( L_62 ) ) ;
return - V_147 ;
}
V_27 = V_126 -> V_129 ;
if ( V_27 == NULL ) {
F_63 ( V_67 L_63 , F_60 ( V_3 ) ) ;
return - V_147 ;
}
F_103 ( V_27 , V_11 ) ;
V_155 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
V_2 = F_128 ( V_27 ) ;
V_87 = F_119 ( V_2 ) ;
F_40 ( ( L_57 ,
V_155 ,
V_2 == V_3 ? 1 : 0 ) ) ;
if ( V_155 == V_47 ) goto V_161;
if ( V_155 == V_68 && F_131 ( V_27 ) == 0 ) {
V_27 -> V_162 = 1 ;
F_132 ( & V_27 -> V_54 ) ;
F_40 ( ( L_64 , V_155 ) ) ;
F_105 ( V_130 ) ;
F_104 ( & V_27 -> V_58 , & V_128 ) ;
F_106 ( V_27 , V_11 ) ;
F_108 () ;
F_103 ( V_27 , V_11 ) ;
F_109 ( & V_27 -> V_58 , & V_128 ) ;
F_105 ( V_135 ) ;
F_40 ( ( L_65 , V_155 ) ) ;
}
else if ( V_2 != V_3 ) {
#ifdef F_129
V_27 -> V_46 = V_163 ;
F_40 ( ( L_66 , F_60 ( V_2 ) ) ) ;
V_160 = 0 ;
#else
F_123 ( V_27 , NULL , 0 , V_87 ) ;
#endif
}
V_161:
V_155 = V_27 -> V_46 ;
if ( V_27 -> V_164 ) {
V_159 = V_27 -> V_164 ;
V_153 = V_27 -> V_157 ;
V_27 -> V_164 = NULL ;
V_27 -> V_165 = 0 ;
}
F_40 ( ( L_67 ,
V_155 ,
V_160 ,
V_159 ,
V_153 ) ) ;
if ( V_159 ) F_93 ( V_27 -> V_166 ) ;
if ( V_155 == V_163 ) {
F_90 ( V_27 , V_27 -> V_50 , V_27 -> V_150 ) ;
}
V_126 -> V_129 = NULL ;
F_106 ( V_27 , V_11 ) ;
if ( V_159 ) F_47 ( V_159 , V_153 ) ;
if ( V_160 ) F_55 ( V_27 ) ;
return 0 ;
}
static int
F_133 ( struct V_158 * V_167 , struct V_125 * V_168 )
{
F_40 ( ( L_68 ) ) ;
return - V_169 ;
}
static int
F_134 ( const struct V_8 * V_8 )
{
return 1 ;
}
static char * F_135 ( struct V_8 * V_8 , char * V_170 , int V_171 )
{
return F_136 ( V_8 , V_170 , V_171 , L_69 ,
V_8 -> V_172 -> V_173 ) ;
}
static struct V_125 *
F_137 ( T_1 * V_27 )
{
struct V_125 * V_125 ;
struct V_158 * V_158 ;
struct V_174 V_174 ;
struct V_175 V_176 = { . V_177 = L_70 } ;
V_158 = F_138 ( V_124 -> V_178 ) ;
if ( ! V_158 )
return F_139 ( - V_179 ) ;
F_40 ( ( L_71 , V_158 -> V_173 , V_158 ) ) ;
V_158 -> V_180 = V_181 | V_182 ;
V_158 -> V_183 = F_140 () ;
V_158 -> V_184 = F_141 () ;
V_174 . V_8 = F_142 ( V_124 -> V_185 , & V_176 ) ;
if ( ! V_174 . V_8 ) {
F_143 ( V_158 ) ;
return F_139 ( - V_179 ) ;
}
V_174 . V_186 = F_144 ( V_124 ) ;
F_145 ( V_174 . V_8 , V_158 ) ;
V_125 = F_146 ( & V_174 , V_187 , & V_188 ) ;
if ( F_98 ( V_125 ) ) {
F_147 ( & V_174 ) ;
return V_125 ;
}
V_125 -> V_132 = V_189 ;
V_125 -> V_129 = V_27 ;
return V_125 ;
}
static int
F_148 ( struct V_190 * V_191 , unsigned long V_85 , unsigned long V_42 , unsigned long V_40 )
{
F_40 ( ( L_72 , F_87 () , V_85 , V_42 , V_40 ) ) ;
while ( V_40 > 0 ) {
unsigned long V_192 = F_149 ( V_85 ) >> V_193 ;
if ( F_150 ( V_191 , V_42 , V_192 , V_43 , V_194 ) )
return - V_179 ;
V_42 += V_43 ;
V_85 += V_43 ;
V_40 -= V_43 ;
}
return 0 ;
}
static int
F_151 ( struct V_1 * V_2 , struct V_125 * V_126 , T_1 * V_27 , unsigned long V_195 , void * * V_196 )
{
struct V_197 * V_121 = V_2 -> V_121 ;
struct V_190 * V_191 = NULL ;
unsigned long V_40 ;
void * V_198 ;
V_40 = F_45 ( V_195 ) ;
F_40 ( ( L_73 , V_195 , V_40 ) ) ;
if ( V_40 > F_152 ( V_2 , V_199 ) )
return - V_179 ;
V_198 = F_44 ( V_40 ) ;
if ( V_198 == NULL ) {
F_40 ( ( L_74 ) ) ;
return - V_179 ;
}
F_40 ( ( L_75 , V_198 ) ) ;
V_191 = F_153 ( V_200 , V_45 ) ;
if ( ! V_191 ) {
F_40 ( ( L_76 ) ) ;
goto V_201;
}
F_154 ( & V_191 -> V_202 ) ;
V_191 -> V_203 = V_121 ;
V_191 -> V_204 = F_155 ( V_126 ) ;
V_191 -> V_205 = V_206 | V_207 | V_208 | V_209 ;
V_191 -> V_210 = V_194 ;
V_27 -> V_164 = V_198 ;
V_27 -> V_157 = V_40 ;
F_156 ( & V_2 -> V_121 -> V_211 ) ;
V_191 -> V_212 = F_157 ( NULL , 0 , V_40 , 0 , V_213 | V_214 ) ;
if ( F_158 ( V_191 -> V_212 ) ) {
F_40 ( ( L_77 , V_40 ) ) ;
F_159 ( & V_2 -> V_121 -> V_211 ) ;
goto error;
}
V_191 -> V_215 = V_191 -> V_212 + V_40 ;
V_191 -> V_216 = V_191 -> V_212 >> V_193 ;
F_40 ( ( L_78 , V_40 , V_27 -> V_164 , V_191 -> V_212 ) ) ;
if ( F_148 ( V_191 , ( unsigned long ) V_198 , V_191 -> V_212 , V_40 ) ) {
F_40 ( ( L_79 ) ) ;
F_159 ( & V_2 -> V_121 -> V_211 ) ;
goto error;
}
F_160 ( V_121 , V_191 ) ;
F_161 ( V_191 -> V_203 , V_191 -> V_205 , V_191 -> V_204 ,
F_162 ( V_191 ) ) ;
F_159 ( & V_2 -> V_121 -> V_211 ) ;
V_27 -> V_156 = ( void * ) V_191 -> V_212 ;
* ( unsigned long * ) V_196 = V_191 -> V_212 ;
return 0 ;
error:
F_163 ( V_200 , V_191 ) ;
V_201:
F_47 ( V_198 , V_40 ) ;
return - V_179 ;
}
static int
F_164 ( struct V_1 * V_2 )
{
const struct V_217 * V_218 ;
T_13 V_219 = F_165 () ;
T_14 V_220 = F_166 () ;
int V_88 ;
F_167 () ;
V_218 = F_168 ( V_2 ) ;
F_40 ( ( L_80 ,
F_169 ( & V_221 , V_219 ) ,
F_170 ( & V_221 , V_220 ) ,
F_169 ( & V_221 , V_218 -> V_222 ) ,
F_169 ( & V_221 , V_218 -> V_223 ) ,
F_169 ( & V_221 , V_218 -> V_219 ) ,
F_170 ( & V_221 , V_218 -> V_224 ) ,
F_170 ( & V_221 , V_218 -> V_225 ) ) ) ;
V_88 = ( ( ! F_171 ( V_219 , V_218 -> V_222 ) )
|| ( ! F_171 ( V_219 , V_218 -> V_223 ) )
|| ( ! F_171 ( V_219 , V_218 -> V_219 ) )
|| ( ! F_172 ( V_220 , V_218 -> V_224 ) )
|| ( ! F_172 ( V_220 , V_218 -> V_225 ) )
|| ( ! F_172 ( V_220 , V_218 -> V_220 ) ) ) && ! F_173 ( V_226 ) ;
F_174 () ;
return V_88 ;
}
static int
F_175 ( struct V_1 * V_2 , T_15 * V_227 )
{
int V_44 ;
V_44 = V_227 -> V_44 ;
if ( V_44 & V_51 ) {
if ( V_44 & V_49 ) {
F_40 ( ( L_81 ) ) ;
return - V_106 ;
}
} else {
}
return 0 ;
}
static int
F_176 ( struct V_1 * V_2 , struct V_125 * V_126 , T_1 * V_27 , unsigned int V_44 ,
unsigned int V_90 , T_15 * V_91 )
{
T_4 * V_84 = NULL ;
unsigned long V_40 = 0UL ;
void * V_228 = NULL ;
void * V_229 = NULL ;
int V_88 = 0 ;
#define F_177 ( V_4 ) (pfm_buffer_fmt_t *)(a+1)
V_84 = F_80 ( V_91 -> V_230 ) ;
if ( V_84 == NULL ) {
F_40 ( ( L_82 , F_60 ( V_2 ) ) ) ;
return - V_106 ;
}
if ( V_84 -> V_231 ) V_229 = F_177 ( V_91 ) ;
V_88 = F_73 ( V_84 , V_2 , V_44 , V_90 , V_229 ) ;
F_40 ( ( L_83 , F_60 ( V_2 ) , V_44 , V_90 , V_229 , V_88 ) ) ;
if ( V_88 ) goto error;
V_27 -> V_166 = V_84 ;
V_27 -> V_165 = 1 ;
V_88 = F_72 ( V_84 , V_2 , V_44 , V_90 , V_229 , & V_40 ) ;
if ( V_88 ) goto error;
if ( V_40 ) {
V_88 = F_151 ( V_3 , V_126 , V_27 , V_40 , & V_228 ) ;
if ( V_88 ) goto error;
V_91 -> V_156 = V_228 ;
}
V_88 = F_74 ( V_84 , V_2 , V_27 -> V_164 , V_44 , V_90 , V_229 ) ;
error:
return V_88 ;
}
static void
F_178 ( T_1 * V_27 )
{
int V_24 ;
for ( V_24 = 1 ; F_179 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_180 ( V_24 ) == 0 ) continue;
V_27 -> V_72 [ V_24 ] = F_181 ( V_24 ) ;
F_40 ( ( L_12 , V_24 , V_27 -> V_72 [ V_24 ] ) ) ;
}
V_27 -> V_81 [ 0 ] = V_29 -> V_232 [ 0 ] & ~ 0x1 ;
V_27 -> V_79 [ 0 ] = V_29 -> V_233 [ 0 ] ;
F_40 ( ( L_84 , V_27 -> V_140 , V_27 -> V_81 [ 0 ] , V_27 -> V_79 [ 0 ] ) ) ;
V_27 -> V_234 [ 0 ] = 0UL ;
V_27 -> V_235 [ 0 ] = 0UL ;
}
static int
F_182 ( void * V_91 , T_9 * V_236 )
{
T_15 * V_237 = ( T_15 * ) V_91 ;
T_4 * V_84 ;
* V_236 = 0 ;
if ( ! F_70 ( V_237 -> V_230 , V_238 ) ) return 0 ;
V_84 = F_80 ( V_237 -> V_230 ) ;
if ( V_84 == NULL ) {
F_40 ( ( L_85 ) ) ;
return - V_106 ;
}
* V_236 = V_84 -> V_231 ;
F_40 ( ( L_86 , * V_236 ) ) ;
return 0 ;
}
static int
F_183 ( T_1 * V_27 , struct V_1 * V_2 )
{
if ( V_2 -> V_121 == NULL ) {
F_40 ( ( L_87 , F_60 ( V_2 ) ) ) ;
return - V_239 ;
}
if ( F_164 ( V_2 ) ) {
F_40 ( ( L_88 , F_60 ( V_2 ) ) ) ;
return - V_239 ;
}
if ( F_131 ( V_27 ) == 0 && V_2 == V_3 ) {
F_40 ( ( L_89 , F_60 ( V_2 ) ) ) ;
return - V_106 ;
}
if ( V_2 -> V_240 == V_241 ) {
F_40 ( ( L_90 , F_60 ( V_2 ) ) ) ;
return - V_108 ;
}
if ( V_2 == V_3 ) return 0 ;
if ( ! F_184 ( V_2 ) ) {
F_40 ( ( L_91 , F_60 ( V_2 ) , V_2 -> V_155 ) ) ;
return - V_108 ;
}
F_185 ( V_2 , 0 ) ;
return 0 ;
}
static int
F_186 ( T_1 * V_27 , T_16 V_242 , struct V_1 * * V_2 )
{
struct V_1 * V_243 = V_3 ;
int V_88 ;
if ( V_242 < 2 ) return - V_239 ;
if ( V_242 != F_187 ( V_3 ) ) {
F_188 ( & V_244 ) ;
V_243 = F_189 ( V_242 ) ;
if ( V_243 ) F_190 ( V_243 ) ;
F_191 ( & V_244 ) ;
if ( V_243 == NULL ) return - V_245 ;
}
V_88 = F_183 ( V_27 , V_243 ) ;
if ( V_88 == 0 ) {
* V_2 = V_243 ;
} else if ( V_243 != V_3 ) {
F_1 ( V_243 ) ;
}
return V_88 ;
}
static int
F_192 ( T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 )
{
T_15 * V_237 = ( T_15 * ) V_91 ;
struct V_125 * V_126 ;
struct V_174 V_174 ;
int V_44 ;
int V_144 ;
int V_88 ;
V_88 = F_175 ( V_3 , V_237 ) ;
if ( V_88 < 0 )
return V_88 ;
V_44 = V_237 -> V_44 ;
V_88 = - V_179 ;
V_144 = F_193 () ;
if ( V_144 < 0 )
return V_144 ;
V_27 = F_49 ( V_44 ) ;
if ( ! V_27 )
goto error;
V_126 = F_137 ( V_27 ) ;
if ( F_98 ( V_126 ) ) {
V_88 = F_97 ( V_126 ) ;
goto V_247;
}
V_237 -> V_140 = V_27 -> V_140 = V_144 ;
if ( F_70 ( V_237 -> V_230 , V_238 ) ) {
V_88 = F_176 ( V_3 , V_126 , V_27 , V_44 , 0 , V_237 ) ;
if ( V_88 )
goto V_248;
}
F_40 ( ( L_92 ,
V_27 ,
V_44 ,
V_27 -> V_50 ,
V_27 -> V_48 ,
V_27 -> V_249 ,
V_27 -> V_52 ,
V_27 -> V_140 ) ) ;
F_178 ( V_27 ) ;
F_194 ( V_144 , V_126 ) ;
return 0 ;
V_248:
V_174 = V_126 -> V_250 ;
F_195 ( V_126 ) ;
F_147 ( & V_174 ) ;
if ( V_27 -> V_166 ) {
F_71 ( V_27 -> V_166 , V_3 , NULL , V_87 ) ;
}
V_247:
F_55 ( V_27 ) ;
error:
F_196 ( V_144 ) ;
return V_88 ;
}
static inline unsigned long
F_197 ( T_17 * V_251 , int V_252 )
{
unsigned long V_20 = V_252 ? V_251 -> V_253 : V_251 -> V_254 ;
unsigned long V_255 , V_256 = V_251 -> V_257 , V_59 = V_251 -> V_59 ;
extern unsigned long V_258 ( unsigned long V_257 ) ;
if ( V_251 -> V_11 & V_259 ) {
V_255 = V_258 ( V_256 ) ;
V_20 -= ( V_256 & V_59 ) ;
if ( ( V_59 >> 32 ) != 0 )
V_255 |= V_258 ( V_256 >> 32 ) << 32 ;
V_251 -> V_257 = V_255 ;
}
V_251 -> V_260 = V_20 ;
return V_20 ;
}
static void
F_198 ( T_1 * V_27 , unsigned long * V_261 , int V_252 )
{
unsigned long V_59 = V_261 [ 0 ] ;
unsigned long V_262 = 0UL ;
unsigned long V_20 ;
int V_24 ;
V_59 >>= V_63 ;
for( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1UL ) == 0UL ) continue;
V_27 -> V_28 [ V_24 ] . V_20 = V_20 = F_197 ( V_27 -> V_28 + V_24 , V_252 ) ;
V_262 |= V_27 -> V_28 [ V_24 ] . V_263 [ 0 ] ;
F_59 ( ( L_93 , V_252 ? L_94 : L_95 , V_24 , V_20 ) ) ;
}
for( V_24 = 0 ; V_262 ; V_24 ++ , V_262 >>= 1 ) {
if ( ( V_262 & 0x1 ) == 0 ) continue;
V_27 -> V_28 [ V_24 ] . V_20 = V_20 = F_197 ( V_27 -> V_28 + V_24 , V_252 ) ;
F_59 ( ( L_96 ,
V_252 ? L_94 : L_95 , V_24 , V_20 ) ) ;
}
}
static void
F_199 ( T_1 * V_27 , unsigned long * V_261 , int V_252 )
{
unsigned long V_59 = V_261 [ 0 ] ;
unsigned long V_262 = 0UL ;
unsigned long V_20 ;
int V_24 ;
F_59 ( ( L_97 , V_261 [ 0 ] , V_252 ) ) ;
if ( V_27 -> V_46 == V_68 ) {
F_198 ( V_27 , V_261 , V_252 ) ;
return;
}
V_59 >>= V_63 ;
for( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1UL ) == 0UL ) continue;
V_20 = F_197 ( V_27 -> V_28 + V_24 , V_252 ) ;
V_262 |= V_27 -> V_28 [ V_24 ] . V_263 [ 0 ] ;
F_59 ( ( L_93 , V_252 ? L_94 : L_95 , V_24 , V_20 ) ) ;
F_37 ( V_27 , V_24 , V_20 ) ;
}
for( V_24 = 0 ; V_262 ; V_24 ++ , V_262 >>= 1 ) {
if ( ( V_262 & 0x1 ) == 0 ) continue;
V_20 = F_197 ( V_27 -> V_28 + V_24 , V_252 ) ;
if ( F_61 ( V_24 ) ) {
F_37 ( V_27 , V_24 , V_20 ) ;
} else {
F_38 ( V_24 , V_20 ) ;
}
F_59 ( ( L_96 ,
V_252 ? L_94 : L_95 , V_24 , V_20 ) ) ;
}
F_27 () ;
}
static int
F_200 ( T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_18 * V_237 = ( T_18 * ) V_91 ;
unsigned long V_264 , V_265 ;
unsigned long V_266 , V_263 , V_233 ;
unsigned int V_267 , V_268 , V_11 , V_269 ;
int V_24 , V_270 = 0 , V_271 , V_66 , V_272 ;
int V_273 , V_274 , V_155 ;
int V_88 = - V_106 ;
T_19 V_275 ;
#define F_201 ( V_5 , T_20 , T_21 ) ((x)->ctx_fl_system ^ PMC_PM(y, z))
V_155 = V_27 -> V_46 ;
V_271 = V_155 == V_276 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_2 = V_27 -> V_151 ;
V_233 = V_29 -> V_233 [ 0 ] ;
if ( V_155 == V_163 ) return - V_106 ;
if ( V_271 ) {
if ( V_66 && V_27 -> V_150 != F_87 () ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_270 = F_120 () == V_2 || V_66 ? 1 : 0 ;
}
V_272 = V_277 . V_272 ;
for ( V_24 = 0 ; V_24 < V_246 ; V_24 ++ , V_237 ++ ) {
V_267 = V_237 -> V_278 ;
V_268 = V_237 -> V_268 ;
V_264 = V_237 -> V_279 ;
V_266 = V_237 -> V_280 [ 0 ] ;
V_263 = V_237 -> V_281 [ 0 ] ;
V_11 = 0 ;
if ( V_267 >= V_282 ) {
F_40 ( ( L_98 , V_267 ) ) ;
goto error;
}
V_269 = V_29 -> V_283 [ V_267 ] . type ;
V_265 = ( V_264 >> V_29 -> V_283 [ V_267 ] . V_284 ) & 0x1 ;
V_274 = ( V_269 & V_285 ) == V_285 ? 1 : 0 ;
V_273 = ( V_269 & V_286 ) == V_286 ? 1 : 0 ;
if ( ( V_269 & V_287 ) == 0 || ( V_269 & V_288 ) == V_288 ) {
F_40 ( ( L_99 , V_267 , V_269 ) ) ;
goto error;
}
V_275 = V_29 -> V_283 [ V_267 ] . V_289 ;
if ( V_273 && V_264 != F_181 ( V_267 ) && V_66 ^ V_265 ) {
F_40 ( ( L_100 ,
V_267 ,
V_265 ,
V_66 ) ) ;
goto error;
}
if ( V_274 ) {
V_264 |= 1 << V_290 ;
if ( V_268 & V_291 ) {
V_11 |= V_291 ;
}
if ( V_268 & V_259 ) V_11 |= V_259 ;
if ( ( V_266 & V_233 ) != V_266 ) {
F_40 ( ( L_101 , V_266 , V_267 ) ) ;
goto error;
}
if ( ( V_263 & V_233 ) != V_263 ) {
F_40 ( ( L_102 , V_263 , V_267 ) ) ;
goto error;
}
} else {
if ( V_268 & ( V_291 | V_259 ) ) {
F_40 ( ( L_103 , V_267 ) ) ;
goto error;
}
}
if ( F_202 ( V_272 == 0 && V_275 ) ) {
V_88 = (* V_275)( V_2 , V_27 , V_267 , & V_264 , V_87 ) ;
if ( V_88 ) goto error;
V_88 = - V_106 ;
}
F_203 ( V_237 -> V_268 , 0 ) ;
if ( V_274 ) {
V_27 -> V_28 [ V_267 ] . V_11 = V_11 ;
V_27 -> V_28 [ V_267 ] . V_263 [ 0 ] = V_263 ;
V_27 -> V_28 [ V_267 ] . V_266 [ 0 ] = V_266 ;
V_27 -> V_28 [ V_267 ] . V_292 = V_237 -> V_293 ;
F_204 ( V_27 , V_263 ) ;
F_204 ( V_27 , V_266 ) ;
if ( V_155 == V_68 ) V_27 -> V_294 [ 0 ] &= ~ 1UL << V_267 ;
}
F_204 ( V_27 , V_29 -> V_283 [ V_267 ] . V_295 [ 0 ] ) ;
if ( V_273 ) F_205 ( V_27 , 1UL << V_267 ) ;
V_27 -> V_72 [ V_267 ] = V_264 ;
if ( V_271 ) {
if ( V_66 == 0 ) V_27 -> V_64 [ V_267 ] = V_264 ;
if ( V_270 ) {
F_26 ( V_267 , V_264 ) ;
}
#ifdef F_129
else {
V_27 -> V_296 [ 0 ] |= 1UL << V_267 ;
}
#endif
}
F_40 ( ( L_104 ,
V_267 ,
V_264 ,
V_271 ,
V_270 ,
V_11 ,
V_27 -> V_81 [ 0 ] ,
V_27 -> V_61 [ 0 ] ,
V_27 -> V_28 [ V_267 ] . V_292 ,
V_266 ,
V_263 ,
V_27 -> V_296 [ 0 ] ,
V_27 -> V_62 [ 0 ] ,
V_27 -> V_294 [ 0 ] ) ) ;
}
if ( V_270 ) F_27 () ;
return 0 ;
error:
F_203 ( V_237 -> V_268 , V_297 ) ;
return V_88 ;
}
static int
F_206 ( T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_18 * V_237 = ( T_18 * ) V_91 ;
unsigned long V_264 , V_298 , V_60 ;
unsigned int V_267 ;
int V_24 , V_270 = 0 , V_155 ;
int V_274 , V_271 , V_66 , V_272 ;
int V_88 = - V_106 ;
T_19 V_275 ;
V_155 = V_27 -> V_46 ;
V_271 = V_155 == V_276 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_60 = V_29 -> V_30 ;
V_2 = V_27 -> V_151 ;
if ( F_207 ( V_155 == V_163 ) ) return - V_106 ;
if ( F_202 ( V_271 ) ) {
if ( F_207 ( V_66 && V_27 -> V_150 != F_87 () ) ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_270 = F_120 () == V_2 || V_66 ? 1 : 0 ;
}
V_272 = V_277 . V_272 ;
for ( V_24 = 0 ; V_24 < V_246 ; V_24 ++ , V_237 ++ ) {
V_267 = V_237 -> V_278 ;
V_264 = V_237 -> V_279 ;
if ( ! F_208 ( V_267 ) ) {
F_40 ( ( L_105 , V_267 ) ) ;
goto V_299;
}
V_274 = F_61 ( V_267 ) ;
V_275 = V_29 -> V_300 [ V_267 ] . V_289 ;
if ( F_207 ( V_272 == 0 && V_275 ) ) {
unsigned long V_301 = V_264 ;
V_88 = (* V_275)( V_2 , V_27 , V_267 , & V_301 , V_87 ) ;
if ( V_88 ) goto V_299;
V_264 = V_301 ;
V_88 = - V_106 ;
}
F_203 ( V_237 -> V_268 , 0 ) ;
V_298 = V_264 ;
if ( V_274 ) {
V_27 -> V_28 [ V_267 ] . V_260 = V_264 ;
if ( V_271 ) {
V_298 = V_264 & V_60 ;
V_264 = V_264 & ~ V_60 ;
}
}
V_27 -> V_28 [ V_267 ] . V_253 = V_237 -> V_302 ;
V_27 -> V_28 [ V_267 ] . V_254 = V_237 -> V_303 ;
V_27 -> V_28 [ V_267 ] . V_257 = V_237 -> V_304 ;
V_27 -> V_28 [ V_267 ] . V_59 = V_237 -> V_305 ;
V_27 -> V_28 [ V_267 ] . V_20 = V_264 ;
F_204 ( V_27 , F_209 ( V_267 ) ) ;
F_204 ( V_27 , F_210 ( V_267 ) ) ;
if ( V_274 && V_155 == V_68 ) {
V_27 -> V_294 [ 0 ] &= ~ 1UL << V_267 ;
}
if ( V_271 ) {
if ( V_66 == 0 ) V_27 -> V_80 [ V_267 ] = V_298 ;
if ( V_270 ) {
F_38 ( V_267 , V_298 ) ;
} else {
#ifdef F_129
V_27 -> V_306 [ 0 ] |= 1UL << V_267 ;
#endif
}
}
F_40 ( ( L_106
L_107 ,
V_267 ,
V_264 ,
V_271 ,
V_270 ,
V_298 ,
V_27 -> V_28 [ V_267 ] . V_20 ,
V_27 -> V_28 [ V_267 ] . V_254 ,
V_27 -> V_28 [ V_267 ] . V_253 ,
F_211 ( V_27 , V_267 ) ? 'Y' : 'N' ,
V_27 -> V_28 [ V_267 ] . V_257 ,
V_27 -> V_28 [ V_267 ] . V_59 ,
V_27 -> V_61 [ 0 ] ,
V_27 -> V_28 [ V_267 ] . V_263 [ 0 ] ,
V_27 -> V_306 [ 0 ] ,
V_27 -> V_79 [ 0 ] ,
V_27 -> V_294 [ 0 ] ) ) ;
}
if ( V_270 ) F_27 () ;
return 0 ;
V_299:
F_203 ( V_237 -> V_268 , V_297 ) ;
return V_88 ;
}
static int
F_212 ( T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
unsigned long V_20 = 0UL , V_260 , V_60 , V_307 ;
T_18 * V_237 = ( T_18 * ) V_91 ;
unsigned int V_267 , V_268 = 0 ;
int V_24 , V_270 = 0 , V_155 ;
int V_271 , V_66 , V_274 , V_272 ;
int V_88 = - V_106 ;
T_19 V_308 ;
V_155 = V_27 -> V_46 ;
V_271 = V_155 == V_276 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_60 = V_29 -> V_30 ;
V_2 = V_27 -> V_151 ;
if ( V_155 == V_163 ) return - V_106 ;
if ( F_202 ( V_271 ) ) {
if ( F_207 ( V_66 && V_27 -> V_150 != F_87 () ) ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_270 = F_120 () == V_2 || V_66 ? 1 : 0 ;
if ( V_270 ) F_27 () ;
}
V_272 = V_277 . V_272 ;
F_40 ( ( L_108 ,
V_271 ,
V_270 ,
V_155 ) ) ;
for ( V_24 = 0 ; V_24 < V_246 ; V_24 ++ , V_237 ++ ) {
V_267 = V_237 -> V_278 ;
V_268 = V_237 -> V_268 ;
if ( F_207 ( ! F_208 ( V_267 ) ) ) goto error;
if ( F_207 ( ! F_213 ( V_27 , V_267 ) ) ) goto error;
V_307 = V_27 -> V_28 [ V_267 ] . V_20 ;
V_260 = V_27 -> V_28 [ V_267 ] . V_260 ;
V_274 = F_61 ( V_267 ) ;
if ( V_270 ) {
V_20 = F_36 ( V_267 ) ;
} else {
V_20 = V_271 ? V_27 -> V_80 [ V_267 ] : 0UL ;
}
V_308 = V_29 -> V_300 [ V_267 ] . V_309 ;
if ( V_274 ) {
V_20 &= V_60 ;
V_20 += V_307 ;
}
if ( F_207 ( V_272 == 0 && V_308 ) ) {
unsigned long V_301 = V_20 ;
V_88 = (* V_308)( V_27 -> V_151 , V_27 , V_267 , & V_301 , V_87 ) ;
if ( V_88 ) goto error;
V_20 = V_301 ;
V_88 = - V_106 ;
}
F_203 ( V_268 , 0 ) ;
F_40 ( ( L_109 , V_267 , V_20 ) ) ;
V_237 -> V_279 = V_20 ;
V_237 -> V_268 = V_268 ;
V_237 -> V_310 = V_260 ;
}
return 0 ;
error:
F_203 ( V_237 -> V_268 , V_297 ) ;
return V_88 ;
}
int
F_214 ( struct V_1 * V_2 , void * V_237 , unsigned int V_311 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_237 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_200 ( V_27 , V_237 , V_311 , V_87 ) ;
}
int
F_215 ( struct V_1 * V_2 , void * V_237 , unsigned int V_311 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_237 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_212 ( V_27 , V_237 , V_311 , V_87 ) ;
}
int
F_216 ( struct V_1 * V_2 )
{
T_1 * V_27 = V_2 -> V_312 . V_313 ;
unsigned long V_11 ;
int V_88 = 0 ;
if ( V_29 -> V_314 == 0 ) return 0 ;
F_40 ( ( L_110 , F_60 ( V_2 ) ) ) ;
if ( V_2 -> V_312 . V_11 & V_315 ) return 0 ;
if ( V_27 && V_27 -> V_73 == 1 ) return - 1 ;
F_86 ( V_11 ) ;
if ( V_113 . V_116 > 0 )
V_88 = - 1 ;
else
V_113 . V_316 ++ ;
F_40 ( ( L_111 ,
V_113 . V_316 ,
V_113 . V_116 ,
F_60 ( V_2 ) , V_88 ) ) ;
F_89 ( V_11 ) ;
return V_88 ;
}
int
F_217 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
int V_88 ;
if ( V_29 -> V_314 == 0 ) return 0 ;
F_86 ( V_11 ) ;
if ( V_113 . V_316 == 0 ) {
F_63 ( V_67 L_112 , F_60 ( V_2 ) ) ;
V_88 = - 1 ;
} else {
V_113 . V_316 -- ;
V_88 = 0 ;
}
F_89 ( V_11 ) ;
return V_88 ;
}
static int
F_218 ( T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_4 * V_84 ;
T_5 V_317 ;
int V_155 , V_66 ;
int V_88 = 0 ;
V_155 = V_27 -> V_46 ;
V_84 = V_27 -> V_166 ;
V_66 = V_27 -> V_50 ;
V_2 = F_128 ( V_27 ) ;
switch( V_155 ) {
case V_68 :
break;
case V_276 :
if ( F_219 ( V_27 ) && V_84 -> V_97 ) break;
case V_47 :
case V_163 :
F_40 ( ( L_113 , V_155 ) ) ;
return - V_108 ;
default:
F_40 ( ( L_114 , V_155 ) ) ;
return - V_106 ;
}
if ( V_66 && V_27 -> V_150 != F_87 () ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
if ( F_207 ( V_2 == NULL ) ) {
F_63 ( V_67 L_115 , F_60 ( V_3 ) ) ;
return - V_106 ;
}
if ( V_2 == V_3 || V_66 ) {
V_84 = V_27 -> V_166 ;
F_40 ( ( L_116 ,
F_60 ( V_2 ) ,
V_27 -> V_294 [ 0 ] ) ) ;
if ( F_219 ( V_27 ) ) {
F_220 ( V_27 -> V_164 ) ;
V_317 . V_318 . V_319 = 0 ;
V_317 . V_318 . V_320 = 0 ;
if ( V_155 == V_276 )
V_88 = F_76 ( V_84 , V_2 , & V_317 , V_27 -> V_164 , V_87 ) ;
else
V_88 = F_75 ( V_84 , V_2 , & V_317 , V_27 -> V_164 , V_87 ) ;
} else {
V_317 . V_318 . V_319 = 0 ;
V_317 . V_318 . V_320 = 1 ;
}
if ( V_88 == 0 ) {
if ( V_317 . V_318 . V_320 )
F_199 ( V_27 , V_27 -> V_294 , V_321 ) ;
if ( V_317 . V_318 . V_319 == 0 ) {
F_40 ( ( L_117 , F_60 ( V_2 ) ) ) ;
if ( V_155 == V_68 ) F_62 ( V_2 ) ;
} else {
F_40 ( ( L_118 , F_60 ( V_2 ) ) ) ;
}
}
V_27 -> V_294 [ 0 ] = 0UL ;
V_27 -> V_46 = V_276 ;
V_27 -> V_322 = 0 ;
return 0 ;
}
if ( V_155 == V_68 ) {
if ( V_27 -> V_322 == 0 ) return - V_106 ;
V_27 -> V_322 = 0 ;
}
if ( F_131 ( V_27 ) == 0 && V_155 == V_68 ) {
F_40 ( ( L_119 , F_60 ( V_2 ) ) ) ;
F_132 ( & V_27 -> V_54 ) ;
} else {
F_40 ( ( L_120 , F_60 ( V_2 ) ) ) ;
V_27 -> V_323 = V_324 ;
F_221 ( V_2 , 1 ) ;
F_222 ( V_2 ) ;
}
return 0 ;
}
static int
F_223 ( T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 )
{
unsigned int V_325 = * ( unsigned int * ) V_91 ;
V_277 . V_326 = V_325 == 0 ? 0 : 1 ;
F_63 ( V_111 L_121 , V_277 . V_326 ? L_122 : L_123 ) ;
if ( V_325 == 0 ) {
memset ( V_327 , 0 , sizeof( V_327 ) ) ;
for( V_325 = 0 ; V_325 < V_328 ; V_325 ++ ) V_327 [ V_325 ] . V_329 = ~ 0UL ;
}
return 0 ;
}
static int
F_224 ( int V_330 , T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 )
{
struct V_331 * V_312 = NULL ;
struct V_1 * V_2 ;
T_22 * V_237 = ( T_22 * ) V_91 ;
unsigned long V_11 ;
T_23 V_332 ;
unsigned int V_333 ;
int V_334 ;
int V_88 = 0 , V_155 ;
int V_24 , V_270 = 0 ;
int V_66 , V_271 ;
if ( V_29 -> V_314 == 0 ) return - V_106 ;
V_155 = V_27 -> V_46 ;
V_271 = V_155 == V_276 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_2 = V_27 -> V_151 ;
if ( V_155 == V_163 ) return - V_106 ;
if ( V_271 ) {
V_312 = & V_2 -> V_312 ;
if ( F_207 ( V_66 && V_27 -> V_150 != F_87 () ) ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_270 = F_120 () == V_2 || V_66 ? 1 : 0 ;
}
V_334 = V_27 -> V_73 == 0 ;
if ( V_271 && ( V_312 -> V_11 & V_315 ) != 0 ) {
F_40 ( ( L_124 , F_60 ( V_2 ) ) ) ;
return - V_108 ;
}
if ( V_271 ) {
F_86 ( V_11 ) ;
if ( V_334 && V_66 ) {
if ( V_113 . V_316 )
V_88 = - V_108 ;
else
V_113 . V_116 ++ ;
}
F_89 ( V_11 ) ;
}
if ( V_88 != 0 ) return V_88 ;
V_27 -> V_73 = 1 ;
if ( V_334 && V_270 ) {
F_40 ( ( L_125 , F_60 ( V_2 ) ) ) ;
for ( V_24 = 0 ; V_24 < V_29 -> V_75 ; V_24 ++ ) {
F_30 ( V_24 , 0UL ) ;
F_31 () ;
}
F_16 () ;
for ( V_24 = 0 ; V_24 < V_29 -> V_77 ; V_24 ++ ) {
F_33 ( V_24 , 0UL ) ;
F_34 () ;
}
F_27 () ;
}
for ( V_24 = 0 ; V_24 < V_246 ; V_24 ++ , V_237 ++ ) {
V_333 = V_237 -> V_335 ;
V_332 . V_20 = V_237 -> V_336 ;
V_88 = - V_106 ;
if ( ( V_330 == V_337 && V_333 >= V_338 ) || ( ( V_330 == V_339 ) && V_333 >= V_340 ) ) {
F_40 ( ( L_126 ,
V_333 , V_332 . V_20 , V_330 , V_24 , V_246 ) ) ;
goto V_299;
}
if ( V_333 & 0x1 ) {
if ( V_330 == V_337 )
V_332 . V_341 . V_342 = 0 ;
else
V_332 . V_343 . V_344 = V_332 . V_343 . V_345 = 0 ;
}
F_203 ( V_237 -> V_346 , 0 ) ;
if ( V_330 == V_337 ) {
F_225 ( V_27 , V_333 ) ;
if ( V_270 ) {
F_30 ( V_333 , V_332 . V_20 ) ;
F_31 () ;
}
V_27 -> V_74 [ V_333 ] = V_332 . V_20 ;
F_40 ( ( L_127 ,
V_333 , V_332 . V_20 , V_27 -> V_234 [ 0 ] , V_271 , V_270 ) ) ;
} else {
F_226 ( V_27 , V_333 ) ;
if ( V_270 ) {
F_33 ( V_333 , V_332 . V_20 ) ;
F_34 () ;
}
V_27 -> V_76 [ V_333 ] = V_332 . V_20 ;
F_40 ( ( L_128 ,
V_333 , V_332 . V_20 , V_27 -> V_235 [ 0 ] , V_271 , V_270 ) ) ;
}
}
return 0 ;
V_299:
if ( V_334 ) {
F_86 ( V_11 ) ;
if ( V_27 -> V_50 ) {
V_113 . V_116 -- ;
}
F_89 ( V_11 ) ;
V_27 -> V_73 = 0 ;
}
F_203 ( V_237 -> V_346 , V_297 ) ;
return V_88 ;
}
static int
F_227 ( T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 )
{
return F_224 ( V_337 , V_27 , V_91 , V_246 , V_87 ) ;
}
static int
F_228 ( T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 )
{
return F_224 ( V_339 , V_27 , V_91 , V_246 , V_87 ) ;
}
int
F_229 ( struct V_1 * V_2 , void * V_237 , unsigned int V_311 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_237 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_227 ( V_27 , V_237 , V_311 , V_87 ) ;
}
int
F_230 ( struct V_1 * V_2 , void * V_237 , unsigned int V_311 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_237 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_228 ( V_27 , V_237 , V_311 , V_87 ) ;
}
static int
F_231 ( T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 )
{
T_24 * V_237 = ( T_24 * ) V_91 ;
V_237 -> V_347 = V_348 ;
return 0 ;
}
static int
F_232 ( T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 )
{
struct V_86 * V_349 ;
struct V_1 * V_2 = F_128 ( V_27 ) ;
int V_155 , V_66 ;
V_155 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_155 == V_47 ) return - V_106 ;
if ( V_66 && V_27 -> V_150 != F_87 () ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
F_40 ( ( L_129 ,
F_60 ( F_128 ( V_27 ) ) ,
V_155 ,
V_66 ) ) ;
if ( V_66 ) {
F_24 ( V_70 , F_22 ( V_70 ) & ~ V_71 ) ;
F_16 () ;
F_233 ( V_69 ) ;
F_14 () ;
F_234 ( V_87 ) -> V_350 = 0 ;
return 0 ;
}
if ( V_2 == V_3 ) {
F_19 () ;
F_234 ( V_87 ) -> V_351 = 0 ;
} else {
V_349 = F_119 ( V_2 ) ;
F_234 ( V_349 ) -> V_351 = 0 ;
V_27 -> V_352 = 0 ;
F_40 ( ( L_130 , F_60 ( V_2 ) ) ) ;
}
return 0 ;
}
static int
F_235 ( T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 )
{
struct V_86 * V_349 ;
int V_155 , V_66 ;
V_155 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_155 != V_276 ) return - V_106 ;
if ( V_66 && V_27 -> V_150 != F_87 () ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
if ( V_66 ) {
F_234 ( V_87 ) -> V_350 = 1 ;
F_236 ( V_69 ) ;
F_17 () ;
F_24 ( V_70 , F_22 ( V_70 ) | V_71 ) ;
F_16 () ;
return 0 ;
}
if ( V_27 -> V_151 == V_3 ) {
F_20 () ;
F_234 ( V_87 ) -> V_351 = 1 ;
} else {
V_349 = F_119 ( V_27 -> V_151 ) ;
V_27 -> V_352 = V_17 ;
F_234 ( V_349 ) -> V_351 = 1 ;
}
return 0 ;
}
static int
F_237 ( T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 )
{
T_18 * V_237 = ( T_18 * ) V_91 ;
unsigned int V_267 ;
int V_24 ;
int V_88 = - V_106 ;
for ( V_24 = 0 ; V_24 < V_246 ; V_24 ++ , V_237 ++ ) {
V_267 = V_237 -> V_278 ;
if ( ! F_180 ( V_267 ) ) goto V_299;
V_237 -> V_279 = F_181 ( V_267 ) ;
F_203 ( V_237 -> V_268 , 0 ) ;
F_40 ( ( L_131 , V_267 , V_237 -> V_279 ) ) ;
}
return 0 ;
V_299:
F_203 ( V_237 -> V_268 , V_297 ) ;
return V_88 ;
}
static int
F_238 ( T_1 * V_27 )
{
struct V_1 * V_353 , * V_354 ;
int V_88 = - V_245 ;
F_188 ( & V_244 ) ;
F_239 (g, t) {
if ( V_354 -> V_312 . V_313 == V_27 ) {
V_88 = 0 ;
goto V_109;
}
} F_240 ( V_353 , V_354 ) ;
V_109:
F_191 ( & V_244 ) ;
F_40 ( ( L_132 , V_88 , V_27 ) ) ;
return V_88 ;
}
static int
F_241 ( T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
struct V_331 * V_312 ;
struct T_1 * V_355 ;
unsigned long V_11 ;
#ifndef F_129
struct V_1 * V_356 = NULL ;
#endif
T_25 * V_237 = ( T_25 * ) V_91 ;
unsigned long * V_357 , * V_358 ;
int V_359 ;
int V_88 = 0 ;
int V_155 , V_66 , V_360 = 0 ;
V_155 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_155 != V_47 ) {
F_40 ( ( L_133 ,
V_237 -> V_361 ,
V_27 -> V_46 ) ) ;
return - V_108 ;
}
F_40 ( ( L_134 , V_237 -> V_361 , V_27 -> V_73 ) ) ;
if ( F_131 ( V_27 ) == 0 && V_237 -> V_361 == V_3 -> V_242 ) {
F_40 ( ( L_135 ) ) ;
return - V_106 ;
}
V_88 = F_186 ( V_27 , V_237 -> V_361 , & V_2 ) ;
if ( V_88 ) {
F_40 ( ( L_136 , V_237 -> V_361 , V_88 ) ) ;
return V_88 ;
}
V_88 = - V_106 ;
if ( V_66 && V_2 != V_3 ) {
F_40 ( ( L_137 ,
V_237 -> V_361 ) ) ;
goto error;
}
V_312 = & V_2 -> V_312 ;
V_88 = 0 ;
if ( V_27 -> V_73 ) {
if ( V_312 -> V_11 & V_315 ) {
V_88 = - V_108 ;
F_40 ( ( L_138 , V_237 -> V_361 ) ) ;
goto error;
}
F_86 ( V_11 ) ;
if ( V_66 ) {
if ( V_113 . V_316 ) {
F_40 ( ( L_139 ,
F_60 ( V_2 ) ) ) ;
V_88 = - V_108 ;
} else {
V_113 . V_116 ++ ;
F_40 ( ( L_140 , F_60 ( V_2 ) , V_113 . V_116 ) ) ;
V_360 = 1 ;
}
}
F_89 ( V_11 ) ;
if ( V_88 ) goto error;
}
V_359 = V_27 -> V_150 = F_87 () ;
V_88 = - V_108 ;
V_88 = F_85 ( V_3 , V_66 , V_359 ) ;
if ( V_88 ) goto error;
F_40 ( ( L_141 ,
V_312 -> V_313 , V_27 ) ) ;
V_88 = - V_108 ;
V_355 = F_242 ( V_362 , & V_312 -> V_313 , NULL , V_27 , sizeof( T_1 * ) ) ;
if ( V_355 != NULL ) {
F_40 ( ( L_142 , V_237 -> V_361 ) ) ;
goto V_363;
}
F_43 ( V_27 ) ;
V_27 -> V_46 = V_276 ;
V_27 -> V_151 = V_2 ;
if ( V_66 ) {
F_236 ( V_364 ) ;
F_233 ( V_69 ) ;
if ( V_27 -> V_249 ) F_236 ( V_365 ) ;
} else {
V_312 -> V_11 |= V_366 ;
}
F_67 ( V_2 , V_27 ) ;
F_68 ( V_2 , V_27 ) ;
V_357 = V_27 -> V_64 ;
V_358 = V_27 -> V_80 ;
if ( V_2 == V_3 ) {
if ( V_66 == 0 ) {
F_234 ( V_87 ) -> V_367 = 0 ;
F_40 ( ( L_143 , F_60 ( V_2 ) ) ) ;
F_53 ( V_27 , F_87 () ) ;
F_243 () ;
F_244 ( V_27 ) ;
#ifndef F_129
V_356 = F_120 () ;
if ( V_356 ) F_245 ( V_356 ) ;
#endif
}
F_66 ( V_358 , V_27 -> V_79 [ 0 ] ) ;
F_69 ( V_357 , V_27 -> V_81 [ 0 ] ) ;
V_27 -> V_296 [ 0 ] = 0UL ;
V_27 -> V_306 [ 0 ] = 0UL ;
if ( V_27 -> V_73 ) {
F_29 ( V_27 -> V_74 , V_29 -> V_75 ) ;
F_32 ( V_27 -> V_76 , V_29 -> V_77 ) ;
}
F_246 ( V_2 , V_27 ) ;
F_40 ( ( L_144 , F_60 ( V_2 ) ) ) ;
} else {
V_87 = F_119 ( V_2 ) ;
V_27 -> V_55 = V_56 ;
F_53 ( V_27 , - 1 ) ;
V_27 -> V_352 = 0UL ;
F_234 ( V_87 ) -> V_351 = F_234 ( V_87 ) -> V_350 = 0 ;
}
V_88 = 0 ;
V_363:
if ( V_88 ) F_90 ( V_27 , V_27 -> V_50 , V_359 ) ;
error:
if ( V_88 && V_360 ) {
F_86 ( V_11 ) ;
V_113 . V_116 -- ;
F_89 ( V_11 ) ;
}
if ( V_66 == 0 && V_2 != V_3 ) {
F_1 ( V_2 ) ;
if ( V_88 == 0 ) {
V_88 = F_238 ( V_27 ) ;
if ( V_88 ) {
V_27 -> V_46 = V_47 ;
V_27 -> V_151 = NULL ;
}
}
}
return V_88 ;
}
static int
F_123 ( T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 )
{
struct V_1 * V_2 = F_128 ( V_27 ) ;
struct V_86 * V_349 ;
int V_368 , V_66 ;
int V_88 ;
F_40 ( ( L_145 , V_27 -> V_46 , V_2 ? F_60 ( V_2 ) : - 1 ) ) ;
V_368 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_368 == V_47 ) {
F_40 ( ( L_146 , V_368 ) ) ;
return 0 ;
}
V_88 = F_232 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) return V_88 ;
V_27 -> V_46 = V_47 ;
if ( V_66 ) {
F_233 ( V_364 ) ;
F_233 ( V_365 ) ;
F_247 ( V_3 , V_27 ) ;
if ( V_368 != V_163 )
F_90 ( V_27 , 1 , V_27 -> V_150 ) ;
V_2 -> V_312 . V_313 = NULL ;
V_27 -> V_151 = NULL ;
return 0 ;
}
V_349 = V_2 == V_3 ? V_87 : F_119 ( V_2 ) ;
if ( V_2 == V_3 ) {
F_234 ( V_87 ) -> V_367 = 1 ;
F_40 ( ( L_147 , F_60 ( V_2 ) ) ) ;
}
F_247 ( V_2 , V_27 ) ;
if ( V_368 != V_163 )
F_90 ( V_27 , 0 , V_27 -> V_150 ) ;
V_27 -> V_55 = V_56 ;
F_53 ( V_27 , - 1 ) ;
V_2 -> V_312 . V_11 &= ~ V_366 ;
V_2 -> V_312 . V_313 = NULL ;
V_27 -> V_151 = NULL ;
F_221 ( V_2 , 0 ) ;
V_27 -> V_323 = V_369 ;
V_27 -> V_322 = 0 ;
V_27 -> V_162 = 0 ;
F_40 ( ( L_148 , F_60 ( V_2 ) ) ) ;
return 0 ;
}
void
F_248 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
unsigned long V_11 ;
struct V_86 * V_87 = F_119 ( V_2 ) ;
int V_88 , V_155 ;
int V_370 = 0 ;
V_27 = F_58 ( V_2 ) ;
F_103 ( V_27 , V_11 ) ;
F_40 ( ( L_149 , V_27 -> V_46 , F_60 ( V_2 ) ) ) ;
V_155 = V_27 -> V_46 ;
switch( V_155 ) {
case V_47 :
F_63 ( V_67 L_150 , F_60 ( V_2 ) ) ;
break;
case V_276 :
case V_68 :
V_88 = F_123 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) {
F_63 ( V_67 L_151 , F_60 ( V_2 ) , V_155 , V_88 ) ;
}
F_40 ( ( L_152 , V_155 ) ) ;
F_249 ( V_27 ) ;
break;
case V_163 :
V_88 = F_123 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) {
F_63 ( V_67 L_151 , F_60 ( V_2 ) , V_155 , V_88 ) ;
}
V_370 = 1 ;
break;
default:
F_63 ( V_67 L_153 , F_60 ( V_2 ) , V_155 ) ;
break;
}
F_106 ( V_27 , V_11 ) ;
{ T_26 V_65 = F_21 () ;
F_250 ( V_65 & ( V_17 | V_16 ) ) ;
F_250 ( F_120 () ) ;
F_250 ( F_234 ( V_87 ) -> V_351 ) ;
F_250 ( F_234 ( V_87 ) -> V_350 ) ;
}
if ( V_370 ) F_55 ( V_27 ) ;
}
static int
F_251 ( T_1 * V_27 , int V_143 , unsigned long V_11 )
{
struct V_1 * V_2 ;
int V_155 , V_371 ;
V_372:
V_155 = V_27 -> V_46 ;
V_2 = V_27 -> V_151 ;
if ( V_2 == NULL ) {
F_40 ( ( L_154 , V_27 -> V_140 , V_155 ) ) ;
return 0 ;
}
F_40 ( ( L_155 ,
V_27 -> V_140 ,
V_155 ,
F_60 ( V_2 ) ,
V_2 -> V_155 , F_252 ( V_143 ) ) ) ;
if ( V_2 == V_3 || V_27 -> V_50 ) return 0 ;
switch( V_155 ) {
case V_47 :
return 0 ;
case V_163 :
F_40 ( ( L_156 , V_143 ) ) ;
return - V_106 ;
case V_68 :
if ( V_143 != V_373 ) return 0 ;
}
if ( F_252 ( V_143 ) ) {
if ( ! F_184 ( V_2 ) ) {
F_40 ( ( L_157 , F_60 ( V_2 ) ) ) ;
return - V_108 ;
}
V_371 = V_155 ;
F_106 ( V_27 , V_11 ) ;
F_185 ( V_2 , 0 ) ;
F_103 ( V_27 , V_11 ) ;
if ( V_27 -> V_46 != V_371 ) {
F_40 ( ( L_158 , V_371 , V_27 -> V_46 ) ) ;
goto V_372;
}
}
return 0 ;
}
T_27 long
F_253 ( int V_144 , int V_143 , void T_8 * V_91 , int V_246 )
{
struct V_144 V_7 = { NULL , 0 } ;
T_1 * V_27 = NULL ;
unsigned long V_11 = 0UL ;
void * V_374 = NULL ;
long V_88 ;
T_9 V_375 , V_236 , V_376 = 0 ;
int V_377 , V_378 = 0 , V_379 = 0 , V_380 ;
int (* F_254)( T_1 * V_27 , void * V_91 , int V_246 , struct V_86 * V_87 );
int (* F_255)( void * V_91 , T_9 * V_236 );
#define F_256 4096
if ( F_207 ( V_29 == NULL ) ) return - V_381 ;
if ( F_207 ( V_143 < 0 || V_143 >= V_382 ) ) {
F_40 ( ( L_159 , V_143 ) ) ;
return - V_106 ;
}
F_254 = V_383 [ V_143 ] . V_384 ;
V_377 = V_383 [ V_143 ] . V_385 ;
V_375 = V_383 [ V_143 ] . V_386 ;
F_255 = V_383 [ V_143 ] . V_387 ;
V_380 = V_383 [ V_143 ] . V_380 ;
if ( F_207 ( F_254 == NULL ) ) {
F_40 ( ( L_159 , V_143 ) ) ;
return - V_106 ;
}
F_40 ( ( L_160 ,
F_257 ( V_143 ) ,
V_143 ,
V_377 ,
V_375 ,
V_246 ) ) ;
if ( F_207 ( ( V_377 == V_388 && V_246 <= 0 ) || ( V_377 > 0 && V_377 != V_246 ) ) )
return - V_106 ;
V_389:
V_236 = V_376 + V_375 * V_246 ;
if ( F_207 ( V_236 > F_256 ) ) {
F_63 ( V_67 L_161 , F_60 ( V_3 ) , V_236 ) ;
return - V_390 ;
}
if ( F_202 ( V_246 && V_374 == NULL ) ) {
V_374 = F_258 ( F_256 , V_45 ) ;
if ( V_374 == NULL ) return - V_179 ;
}
V_88 = - V_138 ;
if ( V_236 && F_259 ( V_374 , V_91 , V_236 ) ) {
F_40 ( ( L_162 , V_236 , V_91 ) ) ;
goto V_391;
}
if ( V_378 == 0 && F_255 ) {
V_88 = (* F_255)( V_374 , & V_376 ) ;
if ( V_88 ) goto V_391;
V_378 = 1 ;
F_40 ( ( L_163 , V_236 , V_376 ) ) ;
if ( F_202 ( V_376 ) ) goto V_389;
}
if ( F_207 ( ( V_380 & V_392 ) == 0 ) ) goto V_393;
V_88 = - V_147 ;
V_7 = F_260 ( V_144 ) ;
if ( F_207 ( V_7 . V_125 == NULL ) ) {
F_40 ( ( L_164 , V_144 ) ) ;
goto V_391;
}
if ( F_207 ( F_102 ( V_7 . V_125 ) == 0 ) ) {
F_40 ( ( L_165 , V_144 ) ) ;
goto V_391;
}
V_27 = V_7 . V_125 -> V_129 ;
if ( F_207 ( V_27 == NULL ) ) {
F_40 ( ( L_166 , V_144 ) ) ;
goto V_391;
}
F_220 ( & V_27 -> V_46 ) ;
F_103 ( V_27 , V_11 ) ;
V_88 = F_251 ( V_27 , V_143 , V_11 ) ;
if ( F_207 ( V_88 ) ) goto V_136;
V_393:
V_88 = (* F_254)( V_27 , V_374 , V_246 , F_119 ( V_3 ) ) ;
V_379 = 1 ;
V_136:
if ( F_202 ( V_27 ) ) {
F_40 ( ( L_167 ) ) ;
F_106 ( V_27 , V_11 ) ;
}
if ( V_379 && F_261 ( V_143 ) && F_110 ( V_91 , V_374 , V_375 * V_246 ) ) V_88 = - V_138 ;
V_391:
if ( V_7 . V_125 )
F_262 ( V_7 ) ;
F_56 ( V_374 ) ;
F_40 ( ( L_168 , F_257 ( V_143 ) , V_88 ) ) ;
return V_88 ;
}
static void
F_263 ( T_1 * V_27 , unsigned long V_261 , struct V_86 * V_87 )
{
T_4 * V_84 = V_27 -> V_166 ;
T_5 V_317 ;
int V_155 ;
int V_88 = 0 ;
V_155 = V_27 -> V_46 ;
if ( F_219 ( V_27 ) ) {
V_317 . V_318 . V_319 = 0 ;
V_317 . V_318 . V_320 = 0 ;
if ( V_155 == V_276 )
V_88 = F_76 ( V_84 , V_3 , & V_317 , V_27 -> V_164 , V_87 ) ;
else
V_88 = F_75 ( V_84 , V_3 , & V_317 , V_27 -> V_164 , V_87 ) ;
} else {
V_317 . V_318 . V_319 = 0 ;
V_317 . V_318 . V_320 = 1 ;
}
if ( V_88 == 0 ) {
if ( V_317 . V_318 . V_320 ) {
F_199 ( V_27 , & V_261 , V_321 ) ;
}
if ( V_317 . V_318 . V_319 == 0 ) {
F_40 ( ( L_169 ) ) ;
if ( V_27 -> V_46 == V_68 ) F_62 ( V_3 ) ;
} else {
F_40 ( ( L_170 ) ) ;
}
V_27 -> V_46 = V_276 ;
}
}
static void
F_264 ( T_1 * V_27 , struct V_86 * V_87 )
{
int V_88 ;
F_40 ( ( L_171 , F_60 ( V_3 ) ) ) ;
V_88 = F_123 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) {
F_63 ( V_67 L_172 , F_60 ( V_3 ) , V_88 ) ;
}
F_265 ( & V_27 -> V_58 ) ;
}
void
F_266 ( void )
{
T_1 * V_27 ;
struct V_86 * V_87 ;
unsigned long V_11 , V_394 ;
unsigned long V_261 ;
unsigned int V_395 ;
int V_88 ;
V_27 = F_58 ( V_3 ) ;
if ( V_27 == NULL ) {
F_63 ( V_67 L_173 ,
F_60 ( V_3 ) ) ;
return;
}
F_103 ( V_27 , V_11 ) ;
F_221 ( V_3 , 0 ) ;
V_87 = F_119 ( V_3 ) ;
V_395 = V_27 -> V_323 ;
V_27 -> V_323 = V_369 ;
V_261 = V_27 -> V_294 [ 0 ] ;
F_40 ( ( L_174 , V_395 , V_27 -> V_46 ) ) ;
if ( V_27 -> V_162 || V_27 -> V_46 == V_163 )
goto V_396;
if ( V_395 == V_324 )
goto V_397;
F_106 ( V_27 , V_11 ) ;
F_267 () ;
F_40 ( ( L_175 ) ) ;
V_88 = F_268 ( & V_27 -> V_54 ) ;
F_40 ( ( L_176 , V_88 ) ) ;
F_103 ( V_27 , V_394 ) ;
V_261 = V_27 -> V_294 [ 0 ] ;
if ( V_27 -> V_162 ) {
V_396:
F_40 ( ( L_177 ) ) ;
F_264 ( V_27 , V_87 ) ;
goto V_398;
}
if ( V_88 < 0 )
goto V_398;
V_397:
F_263 ( V_27 , V_261 , V_87 ) ;
V_27 -> V_294 [ 0 ] = 0UL ;
V_398:
F_106 ( V_27 , V_11 ) ;
}
static int
F_269 ( T_1 * V_27 , T_2 * V_37 )
{
if ( V_27 -> V_46 == V_163 ) {
F_40 ( ( L_178 ) ) ;
return 0 ;
}
F_40 ( ( L_179 ) ) ;
if ( V_37 ) F_265 ( & V_27 -> V_57 ) ;
F_270 ( & V_27 -> V_146 , V_399 , V_400 ) ;
return 0 ;
}
static int
F_271 ( T_1 * V_27 , unsigned long V_401 )
{
T_2 * V_37 = NULL ;
if ( V_27 -> V_52 == 0 ) {
V_37 = F_39 ( V_27 ) ;
if ( V_37 == NULL ) {
F_63 ( V_67 L_180 ) ;
return - 1 ;
}
V_37 -> V_402 . V_39 = V_403 ;
V_37 -> V_402 . V_137 = V_27 -> V_140 ;
V_37 -> V_402 . V_404 = 0 ;
V_37 -> V_402 . V_405 [ 0 ] = V_401 ;
V_37 -> V_402 . V_405 [ 1 ] = 0UL ;
V_37 -> V_402 . V_405 [ 2 ] = 0UL ;
V_37 -> V_402 . V_405 [ 3 ] = 0UL ;
V_37 -> V_402 . V_406 = 0UL ;
}
F_40 ( ( L_181 ,
V_37 ,
V_27 -> V_52 ,
V_27 -> V_140 ,
V_401 ) ) ;
return F_269 ( V_27 , V_37 ) ;
}
static int
F_249 ( T_1 * V_27 )
{
T_2 * V_37 ;
V_37 = F_39 ( V_27 ) ;
if ( V_37 == NULL ) {
F_63 ( V_67 L_182 ) ;
return - 1 ;
}
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_407 . V_39 = V_408 ;
V_37 -> V_407 . V_137 = V_27 -> V_140 ;
V_37 -> V_402 . V_406 = 0UL ;
F_40 ( ( L_183 ,
V_37 ,
V_27 -> V_52 ,
V_27 -> V_140 ) ) ;
return F_269 ( V_27 , V_37 ) ;
}
static void F_272 ( struct V_1 * V_2 , T_1 * V_27 ,
unsigned long V_409 , struct V_86 * V_87 )
{
T_28 * V_410 ;
unsigned long V_59 ;
unsigned long V_411 , V_30 , V_412 ;
unsigned long V_413 = 0UL , V_401 = 0UL , V_266 = 0UL , V_263 ;
unsigned long V_414 ;
T_5 V_415 ;
unsigned int V_24 , V_416 ;
int V_417 = 0 ;
if ( F_207 ( V_27 -> V_46 == V_163 ) ) goto V_418;
if ( F_207 ( ( V_409 & 0x1 ) == 0 ) ) goto V_419;
V_414 = F_273 () ;
V_59 = V_409 >> V_63 ;
V_30 = V_29 -> V_30 ;
V_416 = F_219 ( V_27 ) ;
F_59 ( ( L_184
L_185 ,
V_409 ,
V_2 ? F_60 ( V_2 ) : - 1 ,
( V_87 ? V_87 -> V_420 : 0 ) ,
F_131 ( V_27 ) ? L_186 : L_187 ,
V_27 -> V_61 [ 0 ] ) ) ;
for ( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1 ) == 0 ) continue;
V_411 = V_412 = V_27 -> V_28 [ V_24 ] . V_20 ;
V_412 += 1 + V_30 ;
V_27 -> V_28 [ V_24 ] . V_20 = V_412 ;
if ( F_202 ( V_411 > V_412 ) ) {
V_401 |= 1UL << V_24 ;
if ( F_211 ( V_27 , V_24 ) ) V_413 |= 1UL << V_24 ;
}
F_59 ( ( L_188 ,
V_24 ,
V_412 ,
V_411 ,
F_36 ( V_24 ) & V_30 ,
V_401 ,
V_413 ) ) ;
}
if ( V_401 == 0UL ) return;
V_415 . V_20 = 0 ;
V_263 = 0UL ;
if ( V_416 ) {
unsigned long V_421 , V_422 ;
unsigned long V_423 ;
int V_424 , V_425 , V_88 = 0 ;
int V_426 = F_87 () ;
V_423 = V_401 >> V_63 ;
V_410 = & V_27 -> V_427 ;
F_220 ( V_27 -> V_164 ) ;
for( V_24 = V_63 ; V_423 && V_88 == 0 ; V_24 ++ , V_423 >>= 1 ) {
V_59 = 1UL << V_24 ;
if ( ( V_423 & 0x1 ) == 0 ) continue;
V_410 -> V_428 = ( unsigned char ) V_24 ;
V_410 -> V_413 = V_413 & V_59 ? 1 : 0 ;
V_410 -> V_429 = 0 ;
V_410 -> V_415 . V_20 = 0 ;
V_410 -> V_266 [ 0 ] = V_266 = V_27 -> V_28 [ V_24 ] . V_266 [ 0 ] ;
V_410 -> V_430 = V_27 -> V_28 [ V_24 ] . V_20 ;
V_410 -> V_431 = V_27 -> V_28 [ V_24 ] . V_260 ;
V_410 -> V_432 = V_27 -> V_28 [ V_24 ] . V_292 ;
if ( V_266 ) {
for( V_424 = 0 , V_425 = 0 ; V_266 ; V_424 ++ , V_266 >>= 1 ) {
if ( ( V_266 & 0x1 ) == 0 ) continue;
V_410 -> V_433 [ V_425 ++ ] = F_61 ( V_424 ) ? F_35 ( V_27 , V_424 ) : F_36 ( V_424 ) ;
F_59 ( ( L_189 , V_425 - 1 , V_424 , V_410 -> V_433 [ V_425 - 1 ] ) ) ;
}
}
V_327 [ V_426 ] . V_434 ++ ;
V_421 = F_273 () ;
V_88 = (* V_27 -> V_166 -> V_107 )( V_2 , V_27 -> V_164 , V_410 , V_87 , V_414 ) ;
V_422 = F_273 () ;
V_415 . V_318 . V_435 |= V_410 -> V_415 . V_318 . V_435 ;
V_415 . V_318 . V_436 |= V_410 -> V_415 . V_318 . V_436 ;
V_415 . V_318 . V_319 |= V_410 -> V_415 . V_318 . V_319 ;
if ( V_410 -> V_415 . V_318 . V_320 ) V_263 |= V_59 ;
V_327 [ V_426 ] . V_437 += V_422 - V_421 ;
}
if ( V_88 && V_423 ) {
F_40 ( ( L_190 ,
V_423 << V_63 ) ) ;
}
V_401 &= ~ V_263 ;
} else {
V_415 . V_318 . V_435 = V_413 ? 1 : 0 ;
V_415 . V_318 . V_436 = V_413 ? 1 : 0 ;
V_415 . V_318 . V_319 = V_413 ? 1 : 0 ;
V_415 . V_318 . V_320 = V_413 ? 0 : 1 ;
if ( V_413 == 0 ) V_263 = V_401 ;
}
F_59 ( ( L_191 , V_401 , V_263 ) ) ;
if ( V_263 ) {
unsigned long V_438 = V_263 ;
F_199 ( V_27 , & V_438 , V_439 ) ;
}
if ( V_413 && V_415 . V_318 . V_435 ) {
V_27 -> V_294 [ 0 ] = V_401 ;
if ( F_131 ( V_27 ) == 0 && V_415 . V_318 . V_436 ) {
V_27 -> V_323 = V_440 ;
F_221 ( V_2 , 1 ) ;
F_222 ( V_2 ) ;
}
V_417 = 1 ;
}
F_59 ( ( L_192 ,
F_120 () ? F_60 ( F_120 () ) : - 1 ,
F_274 ( V_2 ) ,
V_27 -> V_323 ,
V_401 ,
V_413 ,
V_415 . V_318 . V_319 ? 1 : 0 ) ) ;
if ( V_415 . V_318 . V_319 ) {
F_57 ( V_2 ) ;
V_27 -> V_46 = V_68 ;
V_27 -> V_322 = 1 ;
}
if ( V_417 ) F_271 ( V_27 , V_413 ) ;
return;
V_419:
F_63 ( V_67 L_193 ,
F_87 () ,
V_2 ? F_60 ( V_2 ) : - 1 ,
V_409 ) ;
return;
V_418:
F_40 ( ( L_194 , V_2 ? F_60 ( V_2 ) : - 1 ) ) ;
F_19 () ;
F_234 ( V_87 ) -> V_351 = 0 ;
F_234 ( V_87 ) -> V_367 = 1 ;
return;
}
static int
F_275 ( void * V_91 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_1 * V_27 ;
unsigned long V_11 ;
T_26 V_409 ;
int V_426 = F_87 () ;
int V_441 = 0 ;
V_327 [ V_426 ] . V_442 ++ ;
V_409 = F_276 ( 0 ) ;
V_2 = F_120 () ;
V_27 = F_121 () ;
if ( F_277 ( V_409 ) && V_2 ) {
if ( ! V_27 ) goto V_443;
if ( V_27 -> V_50 == 0 && ( V_2 -> V_312 . V_11 & V_366 ) == 0 )
goto V_444;
F_278 ( V_27 , V_11 ) ;
F_272 ( V_2 , V_27 , V_409 , V_87 ) ;
F_279 ( V_27 , V_11 ) ;
} else {
V_327 [ V_426 ] . V_445 ++ ;
V_441 = - 1 ;
}
F_28 () ;
return V_441 ;
V_443:
F_63 ( V_111 L_195 ,
V_426 , F_60 ( V_2 ) ) ;
F_28 () ;
return - 1 ;
V_444:
F_63 ( V_111 L_196 ,
V_426 ,
F_60 ( V_2 ) ) ;
F_28 () ;
return - 1 ;
}
static T_29
F_280 ( int V_446 , void * V_91 )
{
unsigned long V_421 , V_447 ;
unsigned long V_448 , V_449 ;
int V_426 ;
int V_88 ;
struct V_86 * V_87 = F_281 () ;
V_426 = F_282 () ;
if ( F_202 ( ! V_450 ) ) {
V_448 = V_327 [ V_426 ] . V_329 ;
V_449 = V_327 [ V_426 ] . V_451 ;
V_421 = F_273 () ;
V_88 = F_275 ( V_91 , V_87 ) ;
V_447 = F_273 () ;
if ( F_202 ( V_88 == 0 ) ) {
V_447 -= V_421 ;
if ( V_447 < V_448 ) V_327 [ V_426 ] . V_329 = V_447 ;
if ( V_447 > V_449 ) V_327 [ V_426 ] . V_451 = V_447 ;
V_327 [ V_426 ] . V_452 += V_447 ;
}
}
else {
(* V_450 -> V_453 )( V_446 , V_91 , V_87 ) ;
}
F_283 () ;
return V_454 ;
}
static void *
F_284 ( struct V_455 * V_325 , T_10 * V_100 )
{
if ( * V_100 == 0 ) {
return V_456 ;
}
while ( * V_100 <= V_457 ) {
if ( F_285 ( * V_100 - 1 ) ) {
return ( void * ) * V_100 ;
}
++ * V_100 ;
}
return NULL ;
}
static void *
F_286 ( struct V_455 * V_325 , void * V_301 , T_10 * V_100 )
{
++ * V_100 ;
return F_284 ( V_325 , V_100 ) ;
}
static void
F_287 ( struct V_455 * V_325 , void * V_301 )
{
}
static void
F_288 ( struct V_455 * V_325 )
{
struct V_99 * V_100 ;
T_4 * V_101 ;
unsigned long V_11 ;
F_289 ( V_325 ,
L_197
L_198
L_199
L_200
L_201
L_202 ,
V_458 , V_459 ,
V_29 -> V_460 ,
V_277 . V_461 > 0 ? L_203 : L_204 ,
V_277 . V_272 > 0 ? L_203 : L_204 ,
V_29 -> V_30 ,
V_29 -> V_11 ) ;
F_86 ( V_11 ) ;
F_289 ( V_325 ,
L_205
L_206
L_207
L_208 ,
V_113 . V_115 ,
V_113 . V_114 ,
V_113 . V_116 ,
V_113 . V_316 ) ;
F_89 ( V_11 ) ;
F_9 ( & V_104 ) ;
F_78 (pos, &pfm_buffer_fmt_list) {
V_101 = F_79 ( V_100 , T_4 , V_102 ) ;
F_289 ( V_325 , L_209 ,
V_101 -> V_103 [ 0 ] ,
V_101 -> V_103 [ 1 ] ,
V_101 -> V_103 [ 2 ] ,
V_101 -> V_103 [ 3 ] ,
V_101 -> V_103 [ 4 ] ,
V_101 -> V_103 [ 5 ] ,
V_101 -> V_103 [ 6 ] ,
V_101 -> V_103 [ 7 ] ,
V_101 -> V_103 [ 8 ] ,
V_101 -> V_103 [ 9 ] ,
V_101 -> V_103 [ 10 ] ,
V_101 -> V_103 [ 11 ] ,
V_101 -> V_103 [ 12 ] ,
V_101 -> V_103 [ 13 ] ,
V_101 -> V_103 [ 14 ] ,
V_101 -> V_103 [ 15 ] ,
V_101 -> V_105 ) ;
}
F_11 ( & V_104 ) ;
}
static int
F_290 ( struct V_455 * V_325 , void * V_301 )
{
unsigned long V_65 ;
unsigned int V_24 ;
int V_90 ;
if ( V_301 == V_456 ) {
F_288 ( V_325 ) ;
return 0 ;
}
V_90 = ( long ) V_301 - 1 ;
F_289 ( V_325 ,
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
V_90 , V_327 [ V_90 ] . V_442 ,
V_90 , V_327 [ V_90 ] . V_452 ,
V_90 , V_327 [ V_90 ] . V_329 ,
V_90 , V_327 [ V_90 ] . V_451 ,
V_90 , V_327 [ V_90 ] . V_434 ,
V_90 , V_327 [ V_90 ] . V_437 ,
V_90 , V_327 [ V_90 ] . V_445 ,
V_90 , V_327 [ V_90 ] . V_462 ,
V_90 , F_291 ( V_463 , V_90 ) & V_364 ? 1 : 0 ,
V_90 , F_291 ( V_463 , V_90 ) & V_69 ? 1 : 0 ,
V_90 , F_291 ( V_463 , V_90 ) & V_365 ? 1 : 0 ,
V_90 , F_291 ( V_464 , V_90 ) ? F_291 ( V_464 , V_90 ) -> V_242 : - 1 ,
V_90 , F_291 ( V_465 , V_90 ) ,
V_90 , F_291 ( V_466 , V_90 ) ) ;
if ( F_292 () == 1 && V_277 . V_326 > 0 ) {
V_65 = F_21 () ;
F_27 () ;
F_289 ( V_325 ,
L_224
L_225 ,
V_90 , V_65 ,
V_90 , F_276 ( 0 ) ) ;
for ( V_24 = 0 ; F_179 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_293 ( V_24 ) == 0 ) continue;
F_289 ( V_325 ,
L_226
L_227 ,
V_90 , V_24 , F_276 ( V_24 ) ,
V_90 , V_24 , F_36 ( V_24 ) ) ;
}
}
return 0 ;
}
static int
F_294 ( struct V_158 * V_158 , struct V_125 * V_125 )
{
return F_295 ( V_125 , & V_467 ) ;
}
void
F_296 ( struct V_1 * V_2 , unsigned long V_148 , int V_468 )
{
struct V_86 * V_87 ;
unsigned long V_469 ;
unsigned long V_470 ;
V_470 = V_148 & V_69 ? 1 : 0 ;
if ( ( V_148 & V_365 ) == 0 || V_2 -> V_242 ) {
V_87 = F_119 ( V_2 ) ;
F_234 ( V_87 ) -> V_350 = V_468 ? V_470 : 0 ;
return;
}
if ( V_470 ) {
V_469 = F_22 ( V_70 ) ;
if ( V_468 ) {
F_24 ( V_70 , V_469 & ~ V_71 ) ;
F_14 () ;
F_16 () ;
return;
}
F_24 ( V_70 , V_469 | V_71 ) ;
F_17 () ;
F_16 () ;
}
}
static void
F_297 ( T_1 * V_27 , struct V_86 * V_87 )
{
struct V_1 * V_2 = V_27 -> V_151 ;
F_234 ( V_87 ) -> V_351 = 0 ;
F_234 ( V_87 ) -> V_367 = 1 ;
if ( F_120 () == V_2 ) {
F_40 ( ( L_228 ,
F_60 ( V_27 -> V_151 ) ) ) ;
F_246 ( NULL , NULL ) ;
}
F_221 ( V_2 , 0 ) ;
V_2 -> V_312 . V_313 = NULL ;
V_2 -> V_312 . V_11 &= ~ V_366 ;
F_40 ( ( L_229 , F_60 ( V_2 ) ) ) ;
}
void
F_298 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
unsigned long V_11 ;
T_26 V_65 ;
V_27 = F_58 ( V_2 ) ;
if ( V_27 == NULL ) return;
V_11 = F_8 ( V_27 ) ;
if ( V_27 -> V_46 == V_163 ) {
struct V_86 * V_87 = F_119 ( V_2 ) ;
F_19 () ;
F_297 ( V_27 , V_87 ) ;
F_250 ( V_27 -> V_164 ) ;
F_10 ( V_27 , V_11 ) ;
F_55 ( V_27 ) ;
return;
}
F_27 () ;
V_65 = F_21 () ;
F_250 ( V_65 & ( V_471 ) ) ;
F_19 () ;
V_27 -> V_352 = V_65 & V_17 ;
F_246 ( NULL , NULL ) ;
F_65 ( V_27 -> V_80 , V_27 -> V_61 [ 0 ] ) ;
V_27 -> V_64 [ 0 ] = F_276 ( 0 ) ;
if ( V_27 -> V_64 [ 0 ] & ~ 0x1UL ) F_28 () ;
F_10 ( V_27 , V_11 ) ;
}
void
F_298 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
T_26 V_65 ;
V_27 = F_58 ( V_2 ) ;
if ( V_27 == NULL ) return;
V_65 = F_21 () ;
F_250 ( V_65 & ( V_471 ) ) ;
F_19 () ;
V_27 -> V_352 = V_65 & V_17 ;
}
static void
F_245 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
unsigned long V_11 ;
{ T_26 V_65 = F_21 () ;
F_250 ( V_65 & V_17 ) ;
}
V_27 = F_58 ( V_2 ) ;
F_103 ( V_27 , V_11 ) ;
F_246 ( NULL , NULL ) ;
F_65 ( V_27 -> V_80 , V_27 -> V_61 [ 0 ] ) ;
V_27 -> V_64 [ 0 ] = F_276 ( 0 ) ;
if ( V_27 -> V_64 [ 0 ] & ~ 0x1UL ) F_28 () ;
F_106 ( V_27 , V_11 ) ;
}
void
F_299 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
unsigned long V_472 = 0UL , V_423 = 0UL ;
unsigned long V_11 ;
T_26 V_65 , V_473 ;
int V_474 ;
V_27 = F_58 ( V_2 ) ;
if ( F_207 ( V_27 == NULL ) ) return;
F_250 ( F_120 () ) ;
if ( F_207 ( ( V_2 -> V_312 . V_11 & V_366 ) == 0 ) ) return;
V_11 = F_8 ( V_27 ) ;
V_65 = F_21 () ;
V_474 = V_29 -> V_11 & V_475 ;
F_250 ( V_65 & ( V_17 | V_16 ) ) ;
F_250 ( V_65 & V_471 ) ;
if ( F_207 ( V_27 -> V_46 == V_163 ) ) {
struct V_86 * V_87 = F_119 ( V_2 ) ;
F_250 ( V_27 -> V_164 ) ;
F_297 ( V_27 , V_87 ) ;
F_10 ( V_27 , V_11 ) ;
F_55 ( V_27 ) ;
return;
}
if ( V_27 -> V_73 ) {
F_29 ( V_27 -> V_74 , V_29 -> V_75 ) ;
F_32 ( V_27 -> V_76 , V_29 -> V_77 ) ;
}
V_473 = V_27 -> V_352 ;
if ( F_300 ( V_27 ) == F_87 () && V_27 -> V_55 == F_301 () ) {
V_472 = V_27 -> V_296 [ 0 ] ;
V_423 = V_27 -> V_306 [ 0 ] ;
} else {
V_423 = V_277 . V_461 ? V_27 -> V_61 [ 0 ] : V_27 -> V_79 [ 0 ] ;
V_472 = V_27 -> V_81 [ 0 ] ;
}
if ( V_423 ) F_66 ( V_27 -> V_80 , V_423 ) ;
if ( V_472 ) F_69 ( V_27 -> V_64 , V_472 ) ;
if ( F_207 ( F_277 ( V_27 -> V_64 [ 0 ] ) ) ) {
F_26 ( 0 , V_27 -> V_64 [ 0 ] ) ;
F_27 () ;
V_27 -> V_64 [ 0 ] = 0UL ;
if ( V_474 ) F_302 ( V_476 ) ;
V_327 [ F_87 () ] . V_462 ++ ;
}
V_27 -> V_296 [ 0 ] = 0UL ;
V_27 -> V_306 [ 0 ] = 0UL ;
F_53 ( V_27 , F_87 () ) ;
F_243 () ;
F_244 ( V_27 ) ;
F_246 ( V_2 , V_27 ) ;
if ( F_202 ( V_473 ) ) F_20 () ;
F_10 ( V_27 , V_11 ) ;
}
void
F_299 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
struct V_1 * V_149 ;
unsigned long V_423 , V_472 ;
T_26 V_65 , V_473 ;
int V_474 ;
V_149 = F_120 () ;
V_27 = F_58 ( V_2 ) ;
V_65 = F_21 () ;
F_250 ( V_65 & ( V_17 | V_16 ) ) ;
F_250 ( V_65 & V_471 ) ;
if ( V_27 -> V_73 ) {
F_29 ( V_27 -> V_74 , V_29 -> V_75 ) ;
F_32 ( V_27 -> V_76 , V_29 -> V_77 ) ;
}
V_473 = V_27 -> V_352 ;
V_474 = V_29 -> V_11 & V_475 ;
if ( F_202 ( V_149 == V_2 ) ) {
if ( F_202 ( V_473 ) ) F_20 () ;
return;
}
if ( V_149 ) F_245 ( V_149 ) ;
V_423 = V_277 . V_461 ? V_27 -> V_61 [ 0 ] : V_27 -> V_79 [ 0 ] ;
V_472 = V_27 -> V_81 [ 0 ] ;
F_66 ( V_27 -> V_80 , V_423 ) ;
F_69 ( V_27 -> V_64 , V_472 ) ;
if ( F_207 ( F_277 ( V_27 -> V_64 [ 0 ] ) ) ) {
F_26 ( 0 , V_27 -> V_64 [ 0 ] ) ;
F_27 () ;
V_27 -> V_64 [ 0 ] = 0UL ;
if ( V_474 ) F_302 ( V_476 ) ;
V_327 [ F_87 () ] . V_462 ++ ;
}
F_246 ( V_2 , V_27 ) ;
if ( F_202 ( V_473 ) ) F_20 () ;
}
static void
F_247 ( struct V_1 * V_2 , T_1 * V_27 )
{
T_26 V_409 ;
unsigned long V_477 , V_20 , V_478 , V_30 ;
int V_24 , V_270 = 0 ;
int V_479 ;
V_479 = V_27 -> V_151 == V_2 ? 1 : 0 ;
V_270 = ( F_120 () == V_2 ) || ( V_27 -> V_50 && V_27 -> V_150 == F_87 () ) ;
if ( V_270 ) {
F_246 ( NULL , NULL ) ;
F_40 ( ( L_230 ) ) ;
F_27 () ;
V_409 = F_276 ( 0 ) ;
F_28 () ;
} else {
V_409 = V_27 -> V_64 [ 0 ] ;
V_27 -> V_64 [ 0 ] = 0 ;
}
V_30 = V_29 -> V_30 ;
V_477 = V_27 -> V_61 [ 0 ] ;
F_40 ( ( L_231 , V_479 , V_30 , V_477 ) ) ;
for ( V_24 = 0 ; V_477 ; V_24 ++ , V_477 >>= 1 ) {
if ( ( V_477 & 0x1 ) == 0 ) continue;
V_20 = V_478 = V_270 ? F_36 ( V_24 ) : V_27 -> V_80 [ V_24 ] ;
if ( F_61 ( V_24 ) ) {
F_40 ( ( L_232 ,
F_60 ( V_2 ) ,
V_24 ,
V_27 -> V_28 [ V_24 ] . V_20 ,
V_20 & V_30 ) ) ;
V_20 = V_27 -> V_28 [ V_24 ] . V_20 + ( V_20 & V_30 ) ;
V_478 = 0UL ;
if ( V_409 & ( 1UL << V_24 ) ) {
V_20 += 1 + V_30 ;
F_40 ( ( L_233 , F_60 ( V_2 ) , V_24 ) ) ;
}
}
F_40 ( ( L_234 , F_60 ( V_2 ) , V_24 , V_20 , V_478 ) ) ;
if ( V_479 ) V_27 -> V_80 [ V_24 ] = V_478 ;
V_27 -> V_28 [ V_24 ] . V_20 = V_20 ;
}
}
static void
F_303 ( void * V_13 )
{
struct V_86 * V_87 ;
V_87 = F_119 ( V_3 ) ;
F_40 ( ( L_235 ) ) ;
F_19 () ;
F_14 () ;
F_234 ( V_87 ) -> V_350 = 0 ;
F_25 () ;
F_27 () ;
}
void
F_304 ( void * V_13 )
{
struct V_86 * V_87 ;
V_87 = F_119 ( V_3 ) ;
F_40 ( ( L_235 ) ) ;
F_19 () ;
F_14 () ;
F_234 ( V_87 ) -> V_350 = 0 ;
F_28 () ;
F_27 () ;
}
int
F_305 ( T_30 * V_480 )
{
int V_88 , V_24 ;
int V_481 ;
if ( V_480 == NULL || V_480 -> V_453 == NULL ) return - V_106 ;
if ( V_450 ) return - V_108 ;
if ( ! F_306 ( & V_482 ) ) {
return - V_108 ;
}
F_307 (reserve_cpu) {
V_88 = F_85 ( NULL , 1 , V_481 ) ;
if ( V_88 ) goto V_483;
}
V_88 = F_308 ( F_303 , NULL , 1 ) ;
if ( V_88 ) {
F_40 ( ( L_236 , V_88 ) ) ;
goto V_483;
}
V_450 = V_480 ;
F_11 ( & V_482 ) ;
return 0 ;
V_483:
F_307 (i) {
if ( V_24 >= V_481 ) break;
F_90 ( NULL , 1 , V_24 ) ;
}
F_11 ( & V_482 ) ;
return V_88 ;
}
int
F_309 ( T_30 * V_480 )
{
int V_24 ;
int V_88 ;
if ( V_480 == NULL ) return - V_106 ;
if ( V_450 != V_480 ) return - V_106 ;
if ( ! F_306 ( & V_482 ) ) {
return - V_108 ;
}
V_450 = NULL ;
V_88 = F_308 ( F_304 , NULL , 1 ) ;
if ( V_88 ) {
F_40 ( ( L_236 , V_88 ) ) ;
}
F_307 (i) {
F_90 ( NULL , 1 , V_24 ) ;
}
F_11 ( & V_482 ) ;
return 0 ;
}
static int T_6
F_310 ( void )
{
T_31 * * V_243 ;
int V_484 ;
V_484 = V_485 -> V_484 ;
V_243 = V_486 ;
while( * V_243 ) {
if ( ( * V_243 ) -> V_487 ) {
if ( ( * V_243 ) -> V_487 () == 0 ) goto V_488;
} else if ( ( * V_243 ) -> V_489 == V_484 || ( * V_243 ) -> V_489 == 0xff ) {
goto V_488;
}
V_243 ++ ;
}
return - 1 ;
V_488:
V_29 = * V_243 ;
return 0 ;
}
int T_6
F_311 ( void )
{
unsigned int V_490 , V_491 , V_24 ;
F_63 ( L_237 ,
V_458 ,
V_459 ,
V_476 ) ;
if ( F_310 () ) {
F_63 ( V_111 L_238 ,
V_485 -> V_484 ) ;
return - V_492 ;
}
V_490 = 0 ;
for ( V_24 = 0 ; F_179 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_180 ( V_24 ) == 0 ) continue;
V_29 -> V_232 [ V_24 >> 6 ] |= 1UL << ( V_24 & 63 ) ;
V_490 ++ ;
}
V_29 -> V_493 = V_490 ;
V_490 = 0 ; V_491 = 0 ;
for ( V_24 = 0 ; F_312 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_208 ( V_24 ) == 0 ) continue;
V_29 -> V_233 [ V_24 >> 6 ] |= 1UL << ( V_24 & 63 ) ;
V_490 ++ ;
if ( F_61 ( V_24 ) ) V_491 ++ ;
}
V_29 -> V_494 = V_490 ;
V_29 -> V_495 = V_491 ;
if ( V_29 -> V_314 ) {
if ( V_29 -> V_75 > V_496 ) {
F_63 ( V_111 L_239 , V_29 -> V_75 ) ;
V_29 = NULL ;
return - 1 ;
}
if ( V_29 -> V_77 > V_496 ) {
F_63 ( V_111 L_240 , V_29 -> V_75 ) ;
V_29 = NULL ;
return - 1 ;
}
}
F_63 ( L_241 ,
V_29 -> V_460 ,
V_29 -> V_493 ,
V_29 -> V_494 ,
V_29 -> V_495 ,
F_313 ( V_29 -> V_30 ) ) ;
if ( V_29 -> V_494 >= V_497 || V_29 -> V_493 >= V_498 ) {
F_63 ( V_67 L_242 ) ;
V_29 = NULL ;
return - 1 ;
}
V_499 = F_314 ( L_243 , V_182 , NULL , & V_500 ) ;
if ( V_499 == NULL ) {
F_63 ( V_67 L_244 ) ;
V_29 = NULL ;
return - 1 ;
}
V_501 = F_315 ( V_502 ) ;
F_51 ( & V_113 . V_503 ) ;
F_51 ( & V_104 ) ;
F_94 () ;
for( V_24 = 0 ; V_24 < V_328 ; V_24 ++ ) V_327 [ V_24 ] . V_329 = ~ 0UL ;
return 0 ;
}
void
F_316 ( void )
{
static int V_334 = 1 ;
F_14 () ;
F_19 () ;
F_28 () ;
if ( V_334 ) {
F_317 ( V_476 , & V_504 ) ;
V_334 = 0 ;
}
F_24 ( V_505 , V_476 ) ;
F_27 () ;
}
void
F_318 ( const char * V_506 )
{
struct V_1 * V_2 ;
struct V_86 * V_87 ;
T_1 * V_27 ;
unsigned long V_65 , V_469 , V_148 , V_11 ;
int V_24 , V_426 ;
F_122 ( V_11 ) ;
V_426 = F_87 () ;
V_87 = F_119 ( V_3 ) ;
V_148 = F_64 () ;
V_469 = F_22 ( V_70 ) ;
if ( V_148 == 0 && F_234 ( V_87 ) -> V_350 == 0 && ( V_469 & V_71 ) == 0 ) {
F_124 ( V_11 ) ;
return;
}
F_63 ( L_245 ,
V_426 ,
V_506 ,
F_60 ( V_3 ) ,
V_87 -> V_420 ,
V_3 -> V_507 ) ;
V_2 = F_120 () ;
V_27 = F_121 () ;
F_63 ( L_246 , V_426 , V_2 ? F_60 ( V_2 ) : - 1 , V_27 ) ;
V_65 = F_21 () ;
F_63 ( L_247 ,
V_426 ,
F_276 ( 0 ) ,
V_65 & V_16 ? 1 : 0 ,
V_65 & V_17 ? 1 : 0 ,
V_469 & V_71 ? 1 : 0 ,
V_148 ,
F_234 ( V_87 ) -> V_351 ,
F_234 ( V_87 ) -> V_350 ) ;
F_234 ( V_87 ) -> V_351 = 0 ;
F_234 ( V_87 ) -> V_350 = 0 ;
for ( V_24 = 1 ; F_179 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_180 ( V_24 ) == 0 ) continue;
F_63 ( L_248 , V_426 , V_24 , F_276 ( V_24 ) , V_24 , V_27 -> V_64 [ V_24 ] ) ;
}
for ( V_24 = 1 ; F_312 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_208 ( V_24 ) == 0 ) continue;
F_63 ( L_249 , V_426 , V_24 , F_36 ( V_24 ) , V_24 , V_27 -> V_80 [ V_24 ] ) ;
}
if ( V_27 ) {
F_63 ( L_250 ,
V_426 ,
V_27 -> V_46 ,
V_27 -> V_156 ,
V_27 -> V_164 ,
V_27 -> V_35 ,
V_27 -> V_33 ,
V_27 -> V_352 ) ;
}
F_124 ( V_11 ) ;
}
void
F_319 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_331 * V_312 ;
F_40 ( ( L_251 , F_60 ( V_2 ) ) ) ;
V_312 = & V_2 -> V_312 ;
V_312 -> V_313 = NULL ;
F_221 ( V_2 , 0 ) ;
}
T_27 long
F_253 ( int V_144 , int V_143 , void * V_91 , int V_246 )
{
return - V_381 ;
}
