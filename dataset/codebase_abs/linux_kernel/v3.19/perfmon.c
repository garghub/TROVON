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
static char * F_133 ( struct V_8 * V_8 , char * V_167 , int V_168 )
{
return F_134 ( V_8 , V_167 , V_168 , L_68 ,
V_8 -> V_169 -> V_170 ) ;
}
static struct V_125 *
F_135 ( T_1 * V_27 )
{
struct V_125 * V_125 ;
struct V_158 * V_158 ;
struct V_171 V_171 ;
struct V_172 V_173 = { . V_174 = L_69 } ;
V_158 = F_136 ( V_124 -> V_175 ) ;
if ( ! V_158 )
return F_137 ( - V_176 ) ;
F_40 ( ( L_70 , V_158 -> V_170 , V_158 ) ) ;
V_158 -> V_177 = V_178 | V_179 ;
V_158 -> V_180 = F_138 () ;
V_158 -> V_181 = F_139 () ;
V_171 . V_8 = F_140 ( V_124 -> V_182 , & V_173 ) ;
if ( ! V_171 . V_8 ) {
F_141 ( V_158 ) ;
return F_137 ( - V_176 ) ;
}
V_171 . V_183 = F_142 ( V_124 ) ;
F_143 ( V_171 . V_8 , V_158 ) ;
V_125 = F_144 ( & V_171 , V_184 , & V_185 ) ;
if ( F_98 ( V_125 ) ) {
F_145 ( & V_171 ) ;
return V_125 ;
}
V_125 -> V_132 = V_186 ;
V_125 -> V_129 = V_27 ;
return V_125 ;
}
static int
F_146 ( struct V_187 * V_188 , unsigned long V_85 , unsigned long V_42 , unsigned long V_40 )
{
F_40 ( ( L_71 , F_87 () , V_85 , V_42 , V_40 ) ) ;
while ( V_40 > 0 ) {
unsigned long V_189 = F_147 ( V_85 ) >> V_190 ;
if ( F_148 ( V_188 , V_42 , V_189 , V_43 , V_191 ) )
return - V_176 ;
V_42 += V_43 ;
V_85 += V_43 ;
V_40 -= V_43 ;
}
return 0 ;
}
static int
F_149 ( struct V_1 * V_2 , struct V_125 * V_126 , T_1 * V_27 , unsigned long V_192 , void * * V_193 )
{
struct V_194 * V_121 = V_2 -> V_121 ;
struct V_187 * V_188 = NULL ;
unsigned long V_40 ;
void * V_195 ;
V_40 = F_45 ( V_192 ) ;
F_40 ( ( L_72 , V_192 , V_40 ) ) ;
if ( V_40 > F_150 ( V_2 , V_196 ) )
return - V_176 ;
V_195 = F_44 ( V_40 ) ;
if ( V_195 == NULL ) {
F_40 ( ( L_73 ) ) ;
return - V_176 ;
}
F_40 ( ( L_74 , V_195 ) ) ;
V_188 = F_151 ( V_197 , V_45 ) ;
if ( ! V_188 ) {
F_40 ( ( L_75 ) ) ;
goto V_198;
}
F_152 ( & V_188 -> V_199 ) ;
V_188 -> V_200 = V_121 ;
V_188 -> V_201 = F_153 ( V_126 ) ;
V_188 -> V_202 = V_203 | V_204 | V_205 | V_206 ;
V_188 -> V_207 = V_191 ;
V_27 -> V_164 = V_195 ;
V_27 -> V_157 = V_40 ;
F_154 ( & V_2 -> V_121 -> V_208 ) ;
V_188 -> V_209 = F_155 ( NULL , 0 , V_40 , 0 , V_210 | V_211 ) ;
if ( F_156 ( V_188 -> V_209 ) ) {
F_40 ( ( L_76 , V_40 ) ) ;
F_157 ( & V_2 -> V_121 -> V_208 ) ;
goto error;
}
V_188 -> V_212 = V_188 -> V_209 + V_40 ;
V_188 -> V_213 = V_188 -> V_209 >> V_190 ;
F_40 ( ( L_77 , V_40 , V_27 -> V_164 , V_188 -> V_209 ) ) ;
if ( F_146 ( V_188 , ( unsigned long ) V_195 , V_188 -> V_209 , V_40 ) ) {
F_40 ( ( L_78 ) ) ;
F_157 ( & V_2 -> V_121 -> V_208 ) ;
goto error;
}
F_158 ( V_121 , V_188 ) ;
F_159 ( V_188 -> V_200 , V_188 -> V_202 , V_188 -> V_201 ,
F_160 ( V_188 ) ) ;
F_157 ( & V_2 -> V_121 -> V_208 ) ;
V_27 -> V_156 = ( void * ) V_188 -> V_209 ;
* ( unsigned long * ) V_193 = V_188 -> V_209 ;
return 0 ;
error:
F_161 ( V_197 , V_188 ) ;
V_198:
F_47 ( V_195 , V_40 ) ;
return - V_176 ;
}
static int
F_162 ( struct V_1 * V_2 )
{
const struct V_214 * V_215 ;
T_13 V_216 = F_163 () ;
T_14 V_217 = F_164 () ;
int V_88 ;
F_165 () ;
V_215 = F_166 ( V_2 ) ;
F_40 ( ( L_79 ,
F_167 ( & V_218 , V_216 ) ,
F_168 ( & V_218 , V_217 ) ,
F_167 ( & V_218 , V_215 -> V_219 ) ,
F_167 ( & V_218 , V_215 -> V_220 ) ,
F_167 ( & V_218 , V_215 -> V_216 ) ,
F_168 ( & V_218 , V_215 -> V_221 ) ,
F_168 ( & V_218 , V_215 -> V_222 ) ) ) ;
V_88 = ( ( ! F_169 ( V_216 , V_215 -> V_219 ) )
|| ( ! F_169 ( V_216 , V_215 -> V_220 ) )
|| ( ! F_169 ( V_216 , V_215 -> V_216 ) )
|| ( ! F_170 ( V_217 , V_215 -> V_221 ) )
|| ( ! F_170 ( V_217 , V_215 -> V_222 ) )
|| ( ! F_170 ( V_217 , V_215 -> V_217 ) ) ) && ! F_171 ( V_223 ) ;
F_172 () ;
return V_88 ;
}
static int
F_173 ( struct V_1 * V_2 , T_15 * V_224 )
{
int V_44 ;
V_44 = V_224 -> V_44 ;
if ( V_44 & V_51 ) {
if ( V_44 & V_49 ) {
F_40 ( ( L_80 ) ) ;
return - V_106 ;
}
} else {
}
return 0 ;
}
static int
F_174 ( struct V_1 * V_2 , struct V_125 * V_126 , T_1 * V_27 , unsigned int V_44 ,
unsigned int V_90 , T_15 * V_91 )
{
T_4 * V_84 = NULL ;
unsigned long V_40 = 0UL ;
void * V_225 = NULL ;
void * V_226 = NULL ;
int V_88 = 0 ;
#define F_175 ( V_4 ) (pfm_buffer_fmt_t *)(a+1)
V_84 = F_80 ( V_91 -> V_227 ) ;
if ( V_84 == NULL ) {
F_40 ( ( L_81 , F_60 ( V_2 ) ) ) ;
return - V_106 ;
}
if ( V_84 -> V_228 ) V_226 = F_175 ( V_91 ) ;
V_88 = F_73 ( V_84 , V_2 , V_44 , V_90 , V_226 ) ;
F_40 ( ( L_82 , F_60 ( V_2 ) , V_44 , V_90 , V_226 , V_88 ) ) ;
if ( V_88 ) goto error;
V_27 -> V_166 = V_84 ;
V_27 -> V_165 = 1 ;
V_88 = F_72 ( V_84 , V_2 , V_44 , V_90 , V_226 , & V_40 ) ;
if ( V_88 ) goto error;
if ( V_40 ) {
V_88 = F_149 ( V_3 , V_126 , V_27 , V_40 , & V_225 ) ;
if ( V_88 ) goto error;
V_91 -> V_156 = V_225 ;
}
V_88 = F_74 ( V_84 , V_2 , V_27 -> V_164 , V_44 , V_90 , V_226 ) ;
error:
return V_88 ;
}
static void
F_176 ( T_1 * V_27 )
{
int V_24 ;
for ( V_24 = 1 ; F_177 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_178 ( V_24 ) == 0 ) continue;
V_27 -> V_72 [ V_24 ] = F_179 ( V_24 ) ;
F_40 ( ( L_12 , V_24 , V_27 -> V_72 [ V_24 ] ) ) ;
}
V_27 -> V_81 [ 0 ] = V_29 -> V_229 [ 0 ] & ~ 0x1 ;
V_27 -> V_79 [ 0 ] = V_29 -> V_230 [ 0 ] ;
F_40 ( ( L_83 , V_27 -> V_140 , V_27 -> V_81 [ 0 ] , V_27 -> V_79 [ 0 ] ) ) ;
V_27 -> V_231 [ 0 ] = 0UL ;
V_27 -> V_232 [ 0 ] = 0UL ;
}
static int
F_180 ( void * V_91 , T_9 * V_233 )
{
T_15 * V_234 = ( T_15 * ) V_91 ;
T_4 * V_84 ;
* V_233 = 0 ;
if ( ! F_70 ( V_234 -> V_227 , V_235 ) ) return 0 ;
V_84 = F_80 ( V_234 -> V_227 ) ;
if ( V_84 == NULL ) {
F_40 ( ( L_84 ) ) ;
return - V_106 ;
}
* V_233 = V_84 -> V_228 ;
F_40 ( ( L_85 , * V_233 ) ) ;
return 0 ;
}
static int
F_181 ( T_1 * V_27 , struct V_1 * V_2 )
{
if ( V_2 -> V_121 == NULL ) {
F_40 ( ( L_86 , F_60 ( V_2 ) ) ) ;
return - V_236 ;
}
if ( F_162 ( V_2 ) ) {
F_40 ( ( L_87 , F_60 ( V_2 ) ) ) ;
return - V_236 ;
}
if ( F_131 ( V_27 ) == 0 && V_2 == V_3 ) {
F_40 ( ( L_88 , F_60 ( V_2 ) ) ) ;
return - V_106 ;
}
if ( V_2 -> V_237 == V_238 ) {
F_40 ( ( L_89 , F_60 ( V_2 ) ) ) ;
return - V_108 ;
}
if ( V_2 == V_3 ) return 0 ;
if ( ! F_182 ( V_2 ) ) {
F_40 ( ( L_90 , F_60 ( V_2 ) , V_2 -> V_155 ) ) ;
return - V_108 ;
}
F_183 ( V_2 , 0 ) ;
return 0 ;
}
static int
F_184 ( T_1 * V_27 , T_16 V_239 , struct V_1 * * V_2 )
{
struct V_1 * V_240 = V_3 ;
int V_88 ;
if ( V_239 < 2 ) return - V_236 ;
if ( V_239 != F_185 ( V_3 ) ) {
F_186 ( & V_241 ) ;
V_240 = F_187 ( V_239 ) ;
if ( V_240 ) F_188 ( V_240 ) ;
F_189 ( & V_241 ) ;
if ( V_240 == NULL ) return - V_242 ;
}
V_88 = F_181 ( V_27 , V_240 ) ;
if ( V_88 == 0 ) {
* V_2 = V_240 ;
} else if ( V_240 != V_3 ) {
F_1 ( V_240 ) ;
}
return V_88 ;
}
static int
F_190 ( T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 )
{
T_15 * V_234 = ( T_15 * ) V_91 ;
struct V_125 * V_126 ;
struct V_171 V_171 ;
int V_44 ;
int V_144 ;
int V_88 ;
V_88 = F_173 ( V_3 , V_234 ) ;
if ( V_88 < 0 )
return V_88 ;
V_44 = V_234 -> V_44 ;
V_88 = - V_176 ;
V_144 = F_191 ( 0 ) ;
if ( V_144 < 0 )
return V_144 ;
V_27 = F_49 ( V_44 ) ;
if ( ! V_27 )
goto error;
V_126 = F_135 ( V_27 ) ;
if ( F_98 ( V_126 ) ) {
V_88 = F_97 ( V_126 ) ;
goto V_244;
}
V_234 -> V_140 = V_27 -> V_140 = V_144 ;
if ( F_70 ( V_234 -> V_227 , V_235 ) ) {
V_88 = F_174 ( V_3 , V_126 , V_27 , V_44 , 0 , V_234 ) ;
if ( V_88 )
goto V_245;
}
F_40 ( ( L_91 ,
V_27 ,
V_44 ,
V_27 -> V_50 ,
V_27 -> V_48 ,
V_27 -> V_246 ,
V_27 -> V_52 ,
V_27 -> V_140 ) ) ;
F_176 ( V_27 ) ;
F_192 ( V_144 , V_126 ) ;
return 0 ;
V_245:
V_171 = V_126 -> V_247 ;
F_193 ( V_126 ) ;
F_145 ( & V_171 ) ;
if ( V_27 -> V_166 ) {
F_71 ( V_27 -> V_166 , V_3 , NULL , V_87 ) ;
}
V_244:
F_55 ( V_27 ) ;
error:
F_194 ( V_144 ) ;
return V_88 ;
}
static inline unsigned long
F_195 ( T_17 * V_248 , int V_249 )
{
unsigned long V_20 = V_249 ? V_248 -> V_250 : V_248 -> V_251 ;
unsigned long V_252 , V_253 = V_248 -> V_254 , V_59 = V_248 -> V_59 ;
extern unsigned long V_255 ( unsigned long V_254 ) ;
if ( V_248 -> V_11 & V_256 ) {
V_252 = V_255 ( V_253 ) ;
V_20 -= ( V_253 & V_59 ) ;
if ( ( V_59 >> 32 ) != 0 )
V_252 |= V_255 ( V_253 >> 32 ) << 32 ;
V_248 -> V_254 = V_252 ;
}
V_248 -> V_257 = V_20 ;
return V_20 ;
}
static void
F_196 ( T_1 * V_27 , unsigned long * V_258 , int V_249 )
{
unsigned long V_59 = V_258 [ 0 ] ;
unsigned long V_259 = 0UL ;
unsigned long V_20 ;
int V_24 ;
V_59 >>= V_63 ;
for( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1UL ) == 0UL ) continue;
V_27 -> V_28 [ V_24 ] . V_20 = V_20 = F_195 ( V_27 -> V_28 + V_24 , V_249 ) ;
V_259 |= V_27 -> V_28 [ V_24 ] . V_260 [ 0 ] ;
F_59 ( ( L_92 , V_249 ? L_93 : L_94 , V_24 , V_20 ) ) ;
}
for( V_24 = 0 ; V_259 ; V_24 ++ , V_259 >>= 1 ) {
if ( ( V_259 & 0x1 ) == 0 ) continue;
V_27 -> V_28 [ V_24 ] . V_20 = V_20 = F_195 ( V_27 -> V_28 + V_24 , V_249 ) ;
F_59 ( ( L_95 ,
V_249 ? L_93 : L_94 , V_24 , V_20 ) ) ;
}
}
static void
F_197 ( T_1 * V_27 , unsigned long * V_258 , int V_249 )
{
unsigned long V_59 = V_258 [ 0 ] ;
unsigned long V_259 = 0UL ;
unsigned long V_20 ;
int V_24 ;
F_59 ( ( L_96 , V_258 [ 0 ] , V_249 ) ) ;
if ( V_27 -> V_46 == V_68 ) {
F_196 ( V_27 , V_258 , V_249 ) ;
return;
}
V_59 >>= V_63 ;
for( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1UL ) == 0UL ) continue;
V_20 = F_195 ( V_27 -> V_28 + V_24 , V_249 ) ;
V_259 |= V_27 -> V_28 [ V_24 ] . V_260 [ 0 ] ;
F_59 ( ( L_92 , V_249 ? L_93 : L_94 , V_24 , V_20 ) ) ;
F_37 ( V_27 , V_24 , V_20 ) ;
}
for( V_24 = 0 ; V_259 ; V_24 ++ , V_259 >>= 1 ) {
if ( ( V_259 & 0x1 ) == 0 ) continue;
V_20 = F_195 ( V_27 -> V_28 + V_24 , V_249 ) ;
if ( F_61 ( V_24 ) ) {
F_37 ( V_27 , V_24 , V_20 ) ;
} else {
F_38 ( V_24 , V_20 ) ;
}
F_59 ( ( L_95 ,
V_249 ? L_93 : L_94 , V_24 , V_20 ) ) ;
}
F_27 () ;
}
static int
F_198 ( T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_18 * V_234 = ( T_18 * ) V_91 ;
unsigned long V_261 , V_262 ;
unsigned long V_263 , V_260 , V_230 ;
unsigned int V_264 , V_265 , V_11 , V_266 ;
int V_24 , V_267 = 0 , V_268 , V_66 , V_269 ;
int V_270 , V_271 , V_155 ;
int V_88 = - V_106 ;
T_19 V_272 ;
#define F_199 ( V_5 , T_20 , T_21 ) ((x)->ctx_fl_system ^ PMC_PM(y, z))
V_155 = V_27 -> V_46 ;
V_268 = V_155 == V_273 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_2 = V_27 -> V_151 ;
V_230 = V_29 -> V_230 [ 0 ] ;
if ( V_155 == V_163 ) return - V_106 ;
if ( V_268 ) {
if ( V_66 && V_27 -> V_150 != F_87 () ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_267 = F_120 () == V_2 || V_66 ? 1 : 0 ;
}
V_269 = V_274 . V_269 ;
for ( V_24 = 0 ; V_24 < V_243 ; V_24 ++ , V_234 ++ ) {
V_264 = V_234 -> V_275 ;
V_265 = V_234 -> V_265 ;
V_261 = V_234 -> V_276 ;
V_263 = V_234 -> V_277 [ 0 ] ;
V_260 = V_234 -> V_278 [ 0 ] ;
V_11 = 0 ;
if ( V_264 >= V_279 ) {
F_40 ( ( L_97 , V_264 ) ) ;
goto error;
}
V_266 = V_29 -> V_280 [ V_264 ] . type ;
V_262 = ( V_261 >> V_29 -> V_280 [ V_264 ] . V_281 ) & 0x1 ;
V_271 = ( V_266 & V_282 ) == V_282 ? 1 : 0 ;
V_270 = ( V_266 & V_283 ) == V_283 ? 1 : 0 ;
if ( ( V_266 & V_284 ) == 0 || ( V_266 & V_285 ) == V_285 ) {
F_40 ( ( L_98 , V_264 , V_266 ) ) ;
goto error;
}
V_272 = V_29 -> V_280 [ V_264 ] . V_286 ;
if ( V_270 && V_261 != F_179 ( V_264 ) && V_66 ^ V_262 ) {
F_40 ( ( L_99 ,
V_264 ,
V_262 ,
V_66 ) ) ;
goto error;
}
if ( V_271 ) {
V_261 |= 1 << V_287 ;
if ( V_265 & V_288 ) {
V_11 |= V_288 ;
}
if ( V_265 & V_256 ) V_11 |= V_256 ;
if ( ( V_263 & V_230 ) != V_263 ) {
F_40 ( ( L_100 , V_263 , V_264 ) ) ;
goto error;
}
if ( ( V_260 & V_230 ) != V_260 ) {
F_40 ( ( L_101 , V_260 , V_264 ) ) ;
goto error;
}
} else {
if ( V_265 & ( V_288 | V_256 ) ) {
F_40 ( ( L_102 , V_264 ) ) ;
goto error;
}
}
if ( F_200 ( V_269 == 0 && V_272 ) ) {
V_88 = (* V_272)( V_2 , V_27 , V_264 , & V_261 , V_87 ) ;
if ( V_88 ) goto error;
V_88 = - V_106 ;
}
F_201 ( V_234 -> V_265 , 0 ) ;
if ( V_271 ) {
V_27 -> V_28 [ V_264 ] . V_11 = V_11 ;
V_27 -> V_28 [ V_264 ] . V_260 [ 0 ] = V_260 ;
V_27 -> V_28 [ V_264 ] . V_263 [ 0 ] = V_263 ;
V_27 -> V_28 [ V_264 ] . V_289 = V_234 -> V_290 ;
F_202 ( V_27 , V_260 ) ;
F_202 ( V_27 , V_263 ) ;
if ( V_155 == V_68 ) V_27 -> V_291 [ 0 ] &= ~ 1UL << V_264 ;
}
F_202 ( V_27 , V_29 -> V_280 [ V_264 ] . V_292 [ 0 ] ) ;
if ( V_270 ) F_203 ( V_27 , 1UL << V_264 ) ;
V_27 -> V_72 [ V_264 ] = V_261 ;
if ( V_268 ) {
if ( V_66 == 0 ) V_27 -> V_64 [ V_264 ] = V_261 ;
if ( V_267 ) {
F_26 ( V_264 , V_261 ) ;
}
#ifdef F_129
else {
V_27 -> V_293 [ 0 ] |= 1UL << V_264 ;
}
#endif
}
F_40 ( ( L_103 ,
V_264 ,
V_261 ,
V_268 ,
V_267 ,
V_11 ,
V_27 -> V_81 [ 0 ] ,
V_27 -> V_61 [ 0 ] ,
V_27 -> V_28 [ V_264 ] . V_289 ,
V_263 ,
V_260 ,
V_27 -> V_293 [ 0 ] ,
V_27 -> V_62 [ 0 ] ,
V_27 -> V_291 [ 0 ] ) ) ;
}
if ( V_267 ) F_27 () ;
return 0 ;
error:
F_201 ( V_234 -> V_265 , V_294 ) ;
return V_88 ;
}
static int
F_204 ( T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_18 * V_234 = ( T_18 * ) V_91 ;
unsigned long V_261 , V_295 , V_60 ;
unsigned int V_264 ;
int V_24 , V_267 = 0 , V_155 ;
int V_271 , V_268 , V_66 , V_269 ;
int V_88 = - V_106 ;
T_19 V_272 ;
V_155 = V_27 -> V_46 ;
V_268 = V_155 == V_273 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_60 = V_29 -> V_30 ;
V_2 = V_27 -> V_151 ;
if ( F_205 ( V_155 == V_163 ) ) return - V_106 ;
if ( F_200 ( V_268 ) ) {
if ( F_205 ( V_66 && V_27 -> V_150 != F_87 () ) ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_267 = F_120 () == V_2 || V_66 ? 1 : 0 ;
}
V_269 = V_274 . V_269 ;
for ( V_24 = 0 ; V_24 < V_243 ; V_24 ++ , V_234 ++ ) {
V_264 = V_234 -> V_275 ;
V_261 = V_234 -> V_276 ;
if ( ! F_206 ( V_264 ) ) {
F_40 ( ( L_104 , V_264 ) ) ;
goto V_296;
}
V_271 = F_61 ( V_264 ) ;
V_272 = V_29 -> V_297 [ V_264 ] . V_286 ;
if ( F_205 ( V_269 == 0 && V_272 ) ) {
unsigned long V_298 = V_261 ;
V_88 = (* V_272)( V_2 , V_27 , V_264 , & V_298 , V_87 ) ;
if ( V_88 ) goto V_296;
V_261 = V_298 ;
V_88 = - V_106 ;
}
F_201 ( V_234 -> V_265 , 0 ) ;
V_295 = V_261 ;
if ( V_271 ) {
V_27 -> V_28 [ V_264 ] . V_257 = V_261 ;
if ( V_268 ) {
V_295 = V_261 & V_60 ;
V_261 = V_261 & ~ V_60 ;
}
}
V_27 -> V_28 [ V_264 ] . V_250 = V_234 -> V_299 ;
V_27 -> V_28 [ V_264 ] . V_251 = V_234 -> V_300 ;
V_27 -> V_28 [ V_264 ] . V_254 = V_234 -> V_301 ;
V_27 -> V_28 [ V_264 ] . V_59 = V_234 -> V_302 ;
V_27 -> V_28 [ V_264 ] . V_20 = V_261 ;
F_202 ( V_27 , F_207 ( V_264 ) ) ;
F_202 ( V_27 , F_208 ( V_264 ) ) ;
if ( V_271 && V_155 == V_68 ) {
V_27 -> V_291 [ 0 ] &= ~ 1UL << V_264 ;
}
if ( V_268 ) {
if ( V_66 == 0 ) V_27 -> V_80 [ V_264 ] = V_295 ;
if ( V_267 ) {
F_38 ( V_264 , V_295 ) ;
} else {
#ifdef F_129
V_27 -> V_303 [ 0 ] |= 1UL << V_264 ;
#endif
}
}
F_40 ( ( L_105
L_106 ,
V_264 ,
V_261 ,
V_268 ,
V_267 ,
V_295 ,
V_27 -> V_28 [ V_264 ] . V_20 ,
V_27 -> V_28 [ V_264 ] . V_251 ,
V_27 -> V_28 [ V_264 ] . V_250 ,
F_209 ( V_27 , V_264 ) ? 'Y' : 'N' ,
V_27 -> V_28 [ V_264 ] . V_254 ,
V_27 -> V_28 [ V_264 ] . V_59 ,
V_27 -> V_61 [ 0 ] ,
V_27 -> V_28 [ V_264 ] . V_260 [ 0 ] ,
V_27 -> V_303 [ 0 ] ,
V_27 -> V_79 [ 0 ] ,
V_27 -> V_291 [ 0 ] ) ) ;
}
if ( V_267 ) F_27 () ;
return 0 ;
V_296:
F_201 ( V_234 -> V_265 , V_294 ) ;
return V_88 ;
}
static int
F_210 ( T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
unsigned long V_20 = 0UL , V_257 , V_60 , V_304 ;
T_18 * V_234 = ( T_18 * ) V_91 ;
unsigned int V_264 , V_265 = 0 ;
int V_24 , V_267 = 0 , V_155 ;
int V_268 , V_66 , V_271 , V_269 ;
int V_88 = - V_106 ;
T_19 V_305 ;
V_155 = V_27 -> V_46 ;
V_268 = V_155 == V_273 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_60 = V_29 -> V_30 ;
V_2 = V_27 -> V_151 ;
if ( V_155 == V_163 ) return - V_106 ;
if ( F_200 ( V_268 ) ) {
if ( F_205 ( V_66 && V_27 -> V_150 != F_87 () ) ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_267 = F_120 () == V_2 || V_66 ? 1 : 0 ;
if ( V_267 ) F_27 () ;
}
V_269 = V_274 . V_269 ;
F_40 ( ( L_107 ,
V_268 ,
V_267 ,
V_155 ) ) ;
for ( V_24 = 0 ; V_24 < V_243 ; V_24 ++ , V_234 ++ ) {
V_264 = V_234 -> V_275 ;
V_265 = V_234 -> V_265 ;
if ( F_205 ( ! F_206 ( V_264 ) ) ) goto error;
if ( F_205 ( ! F_211 ( V_27 , V_264 ) ) ) goto error;
V_304 = V_27 -> V_28 [ V_264 ] . V_20 ;
V_257 = V_27 -> V_28 [ V_264 ] . V_257 ;
V_271 = F_61 ( V_264 ) ;
if ( V_267 ) {
V_20 = F_36 ( V_264 ) ;
} else {
V_20 = V_268 ? V_27 -> V_80 [ V_264 ] : 0UL ;
}
V_305 = V_29 -> V_297 [ V_264 ] . V_306 ;
if ( V_271 ) {
V_20 &= V_60 ;
V_20 += V_304 ;
}
if ( F_205 ( V_269 == 0 && V_305 ) ) {
unsigned long V_298 = V_20 ;
V_88 = (* V_305)( V_27 -> V_151 , V_27 , V_264 , & V_298 , V_87 ) ;
if ( V_88 ) goto error;
V_20 = V_298 ;
V_88 = - V_106 ;
}
F_201 ( V_265 , 0 ) ;
F_40 ( ( L_108 , V_264 , V_20 ) ) ;
V_234 -> V_276 = V_20 ;
V_234 -> V_265 = V_265 ;
V_234 -> V_307 = V_257 ;
}
return 0 ;
error:
F_201 ( V_234 -> V_265 , V_294 ) ;
return V_88 ;
}
int
F_212 ( struct V_1 * V_2 , void * V_234 , unsigned int V_308 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_234 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_198 ( V_27 , V_234 , V_308 , V_87 ) ;
}
int
F_213 ( struct V_1 * V_2 , void * V_234 , unsigned int V_308 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_234 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_210 ( V_27 , V_234 , V_308 , V_87 ) ;
}
int
F_214 ( struct V_1 * V_2 )
{
T_1 * V_27 = V_2 -> V_309 . V_310 ;
unsigned long V_11 ;
int V_88 = 0 ;
if ( V_29 -> V_311 == 0 ) return 0 ;
F_40 ( ( L_109 , F_60 ( V_2 ) ) ) ;
if ( V_2 -> V_309 . V_11 & V_312 ) return 0 ;
if ( V_27 && V_27 -> V_73 == 1 ) return - 1 ;
F_86 ( V_11 ) ;
if ( V_113 . V_116 > 0 )
V_88 = - 1 ;
else
V_113 . V_313 ++ ;
F_40 ( ( L_110 ,
V_113 . V_313 ,
V_113 . V_116 ,
F_60 ( V_2 ) , V_88 ) ) ;
F_89 ( V_11 ) ;
return V_88 ;
}
int
F_215 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
int V_88 ;
if ( V_29 -> V_311 == 0 ) return 0 ;
F_86 ( V_11 ) ;
if ( V_113 . V_313 == 0 ) {
F_63 ( V_67 L_111 , F_60 ( V_2 ) ) ;
V_88 = - 1 ;
} else {
V_113 . V_313 -- ;
V_88 = 0 ;
}
F_89 ( V_11 ) ;
return V_88 ;
}
static int
F_216 ( T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_4 * V_84 ;
T_5 V_314 ;
int V_155 , V_66 ;
int V_88 = 0 ;
V_155 = V_27 -> V_46 ;
V_84 = V_27 -> V_166 ;
V_66 = V_27 -> V_50 ;
V_2 = F_128 ( V_27 ) ;
switch( V_155 ) {
case V_68 :
break;
case V_273 :
if ( F_217 ( V_27 ) && V_84 -> V_97 ) break;
case V_47 :
case V_163 :
F_40 ( ( L_112 , V_155 ) ) ;
return - V_108 ;
default:
F_40 ( ( L_113 , V_155 ) ) ;
return - V_106 ;
}
if ( V_66 && V_27 -> V_150 != F_87 () ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
if ( F_205 ( V_2 == NULL ) ) {
F_63 ( V_67 L_114 , F_60 ( V_3 ) ) ;
return - V_106 ;
}
if ( V_2 == V_3 || V_66 ) {
V_84 = V_27 -> V_166 ;
F_40 ( ( L_115 ,
F_60 ( V_2 ) ,
V_27 -> V_291 [ 0 ] ) ) ;
if ( F_217 ( V_27 ) ) {
F_218 ( V_27 -> V_164 ) ;
V_314 . V_315 . V_316 = 0 ;
V_314 . V_315 . V_317 = 0 ;
if ( V_155 == V_273 )
V_88 = F_76 ( V_84 , V_2 , & V_314 , V_27 -> V_164 , V_87 ) ;
else
V_88 = F_75 ( V_84 , V_2 , & V_314 , V_27 -> V_164 , V_87 ) ;
} else {
V_314 . V_315 . V_316 = 0 ;
V_314 . V_315 . V_317 = 1 ;
}
if ( V_88 == 0 ) {
if ( V_314 . V_315 . V_317 )
F_197 ( V_27 , V_27 -> V_291 , V_318 ) ;
if ( V_314 . V_315 . V_316 == 0 ) {
F_40 ( ( L_116 , F_60 ( V_2 ) ) ) ;
if ( V_155 == V_68 ) F_62 ( V_2 ) ;
} else {
F_40 ( ( L_117 , F_60 ( V_2 ) ) ) ;
}
}
V_27 -> V_291 [ 0 ] = 0UL ;
V_27 -> V_46 = V_273 ;
V_27 -> V_319 = 0 ;
return 0 ;
}
if ( V_155 == V_68 ) {
if ( V_27 -> V_319 == 0 ) return - V_106 ;
V_27 -> V_319 = 0 ;
}
if ( F_131 ( V_27 ) == 0 && V_155 == V_68 ) {
F_40 ( ( L_118 , F_60 ( V_2 ) ) ) ;
F_132 ( & V_27 -> V_54 ) ;
} else {
F_40 ( ( L_119 , F_60 ( V_2 ) ) ) ;
V_27 -> V_320 = V_321 ;
F_219 ( V_2 , 1 ) ;
F_220 ( V_2 ) ;
}
return 0 ;
}
static int
F_221 ( T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 )
{
unsigned int V_322 = * ( unsigned int * ) V_91 ;
V_274 . V_323 = V_322 == 0 ? 0 : 1 ;
F_63 ( V_111 L_120 , V_274 . V_323 ? L_121 : L_122 ) ;
if ( V_322 == 0 ) {
memset ( V_324 , 0 , sizeof( V_324 ) ) ;
for( V_322 = 0 ; V_322 < V_325 ; V_322 ++ ) V_324 [ V_322 ] . V_326 = ~ 0UL ;
}
return 0 ;
}
static int
F_222 ( int V_327 , T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 )
{
struct V_328 * V_309 = NULL ;
struct V_1 * V_2 ;
T_22 * V_234 = ( T_22 * ) V_91 ;
unsigned long V_11 ;
T_23 V_329 ;
unsigned int V_330 ;
int V_331 ;
int V_88 = 0 , V_155 ;
int V_24 , V_267 = 0 ;
int V_66 , V_268 ;
if ( V_29 -> V_311 == 0 ) return - V_106 ;
V_155 = V_27 -> V_46 ;
V_268 = V_155 == V_273 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_2 = V_27 -> V_151 ;
if ( V_155 == V_163 ) return - V_106 ;
if ( V_268 ) {
V_309 = & V_2 -> V_309 ;
if ( F_205 ( V_66 && V_27 -> V_150 != F_87 () ) ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_267 = F_120 () == V_2 || V_66 ? 1 : 0 ;
}
V_331 = V_27 -> V_73 == 0 ;
if ( V_268 && ( V_309 -> V_11 & V_312 ) != 0 ) {
F_40 ( ( L_123 , F_60 ( V_2 ) ) ) ;
return - V_108 ;
}
if ( V_268 ) {
F_86 ( V_11 ) ;
if ( V_331 && V_66 ) {
if ( V_113 . V_313 )
V_88 = - V_108 ;
else
V_113 . V_116 ++ ;
}
F_89 ( V_11 ) ;
}
if ( V_88 != 0 ) return V_88 ;
V_27 -> V_73 = 1 ;
if ( V_331 && V_267 ) {
F_40 ( ( L_124 , F_60 ( V_2 ) ) ) ;
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
for ( V_24 = 0 ; V_24 < V_243 ; V_24 ++ , V_234 ++ ) {
V_330 = V_234 -> V_332 ;
V_329 . V_20 = V_234 -> V_333 ;
V_88 = - V_106 ;
if ( ( V_327 == V_334 && V_330 >= V_335 ) || ( ( V_327 == V_336 ) && V_330 >= V_337 ) ) {
F_40 ( ( L_125 ,
V_330 , V_329 . V_20 , V_327 , V_24 , V_243 ) ) ;
goto V_296;
}
if ( V_330 & 0x1 ) {
if ( V_327 == V_334 )
V_329 . V_338 . V_339 = 0 ;
else
V_329 . V_340 . V_341 = V_329 . V_340 . V_342 = 0 ;
}
F_201 ( V_234 -> V_343 , 0 ) ;
if ( V_327 == V_334 ) {
F_223 ( V_27 , V_330 ) ;
if ( V_267 ) {
F_30 ( V_330 , V_329 . V_20 ) ;
F_31 () ;
}
V_27 -> V_74 [ V_330 ] = V_329 . V_20 ;
F_40 ( ( L_126 ,
V_330 , V_329 . V_20 , V_27 -> V_231 [ 0 ] , V_268 , V_267 ) ) ;
} else {
F_224 ( V_27 , V_330 ) ;
if ( V_267 ) {
F_33 ( V_330 , V_329 . V_20 ) ;
F_34 () ;
}
V_27 -> V_76 [ V_330 ] = V_329 . V_20 ;
F_40 ( ( L_127 ,
V_330 , V_329 . V_20 , V_27 -> V_232 [ 0 ] , V_268 , V_267 ) ) ;
}
}
return 0 ;
V_296:
if ( V_331 ) {
F_86 ( V_11 ) ;
if ( V_27 -> V_50 ) {
V_113 . V_116 -- ;
}
F_89 ( V_11 ) ;
V_27 -> V_73 = 0 ;
}
F_201 ( V_234 -> V_343 , V_294 ) ;
return V_88 ;
}
static int
F_225 ( T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 )
{
return F_222 ( V_334 , V_27 , V_91 , V_243 , V_87 ) ;
}
static int
F_226 ( T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 )
{
return F_222 ( V_336 , V_27 , V_91 , V_243 , V_87 ) ;
}
int
F_227 ( struct V_1 * V_2 , void * V_234 , unsigned int V_308 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_234 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_225 ( V_27 , V_234 , V_308 , V_87 ) ;
}
int
F_228 ( struct V_1 * V_2 , void * V_234 , unsigned int V_308 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_234 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_226 ( V_27 , V_234 , V_308 , V_87 ) ;
}
static int
F_229 ( T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 )
{
T_24 * V_234 = ( T_24 * ) V_91 ;
V_234 -> V_344 = V_345 ;
return 0 ;
}
static int
F_230 ( T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 )
{
struct V_86 * V_346 ;
struct V_1 * V_2 = F_128 ( V_27 ) ;
int V_155 , V_66 ;
V_155 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_155 == V_47 ) return - V_106 ;
if ( V_66 && V_27 -> V_150 != F_87 () ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
F_40 ( ( L_128 ,
F_60 ( F_128 ( V_27 ) ) ,
V_155 ,
V_66 ) ) ;
if ( V_66 ) {
F_24 ( V_70 , F_22 ( V_70 ) & ~ V_71 ) ;
F_16 () ;
F_231 ( V_69 ) ;
F_14 () ;
F_232 ( V_87 ) -> V_347 = 0 ;
return 0 ;
}
if ( V_2 == V_3 ) {
F_19 () ;
F_232 ( V_87 ) -> V_348 = 0 ;
} else {
V_346 = F_119 ( V_2 ) ;
F_232 ( V_346 ) -> V_348 = 0 ;
V_27 -> V_349 = 0 ;
F_40 ( ( L_129 , F_60 ( V_2 ) ) ) ;
}
return 0 ;
}
static int
F_233 ( T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 )
{
struct V_86 * V_346 ;
int V_155 , V_66 ;
V_155 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_155 != V_273 ) return - V_106 ;
if ( V_66 && V_27 -> V_150 != F_87 () ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
if ( V_66 ) {
F_232 ( V_87 ) -> V_347 = 1 ;
F_234 ( V_69 ) ;
F_17 () ;
F_24 ( V_70 , F_22 ( V_70 ) | V_71 ) ;
F_16 () ;
return 0 ;
}
if ( V_27 -> V_151 == V_3 ) {
F_20 () ;
F_232 ( V_87 ) -> V_348 = 1 ;
} else {
V_346 = F_119 ( V_27 -> V_151 ) ;
V_27 -> V_349 = V_17 ;
F_232 ( V_346 ) -> V_348 = 1 ;
}
return 0 ;
}
static int
F_235 ( T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 )
{
T_18 * V_234 = ( T_18 * ) V_91 ;
unsigned int V_264 ;
int V_24 ;
int V_88 = - V_106 ;
for ( V_24 = 0 ; V_24 < V_243 ; V_24 ++ , V_234 ++ ) {
V_264 = V_234 -> V_275 ;
if ( ! F_178 ( V_264 ) ) goto V_296;
V_234 -> V_276 = F_179 ( V_264 ) ;
F_201 ( V_234 -> V_265 , 0 ) ;
F_40 ( ( L_130 , V_264 , V_234 -> V_276 ) ) ;
}
return 0 ;
V_296:
F_201 ( V_234 -> V_265 , V_294 ) ;
return V_88 ;
}
static int
F_236 ( T_1 * V_27 )
{
struct V_1 * V_350 , * V_351 ;
int V_88 = - V_242 ;
F_186 ( & V_241 ) ;
F_237 (g, t) {
if ( V_351 -> V_309 . V_310 == V_27 ) {
V_88 = 0 ;
goto V_109;
}
} F_238 ( V_350 , V_351 ) ;
V_109:
F_189 ( & V_241 ) ;
F_40 ( ( L_131 , V_88 , V_27 ) ) ;
return V_88 ;
}
static int
F_239 ( T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
struct V_328 * V_309 ;
struct T_1 * V_352 ;
unsigned long V_11 ;
#ifndef F_129
struct V_1 * V_353 = NULL ;
#endif
T_25 * V_234 = ( T_25 * ) V_91 ;
unsigned long * V_354 , * V_355 ;
int V_356 ;
int V_88 = 0 ;
int V_155 , V_66 , V_357 = 0 ;
V_155 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_155 != V_47 ) {
F_40 ( ( L_132 ,
V_234 -> V_358 ,
V_27 -> V_46 ) ) ;
return - V_108 ;
}
F_40 ( ( L_133 , V_234 -> V_358 , V_27 -> V_73 ) ) ;
if ( F_131 ( V_27 ) == 0 && V_234 -> V_358 == V_3 -> V_239 ) {
F_40 ( ( L_134 ) ) ;
return - V_106 ;
}
V_88 = F_184 ( V_27 , V_234 -> V_358 , & V_2 ) ;
if ( V_88 ) {
F_40 ( ( L_135 , V_234 -> V_358 , V_88 ) ) ;
return V_88 ;
}
V_88 = - V_106 ;
if ( V_66 && V_2 != V_3 ) {
F_40 ( ( L_136 ,
V_234 -> V_358 ) ) ;
goto error;
}
V_309 = & V_2 -> V_309 ;
V_88 = 0 ;
if ( V_27 -> V_73 ) {
if ( V_309 -> V_11 & V_312 ) {
V_88 = - V_108 ;
F_40 ( ( L_137 , V_234 -> V_358 ) ) ;
goto error;
}
F_86 ( V_11 ) ;
if ( V_66 ) {
if ( V_113 . V_313 ) {
F_40 ( ( L_138 ,
F_60 ( V_2 ) ) ) ;
V_88 = - V_108 ;
} else {
V_113 . V_116 ++ ;
F_40 ( ( L_139 , F_60 ( V_2 ) , V_113 . V_116 ) ) ;
V_357 = 1 ;
}
}
F_89 ( V_11 ) ;
if ( V_88 ) goto error;
}
V_356 = V_27 -> V_150 = F_87 () ;
V_88 = - V_108 ;
V_88 = F_85 ( V_3 , V_66 , V_356 ) ;
if ( V_88 ) goto error;
F_40 ( ( L_140 ,
V_309 -> V_310 , V_27 ) ) ;
V_88 = - V_108 ;
V_352 = F_240 ( V_359 , & V_309 -> V_310 , NULL , V_27 , sizeof( T_1 * ) ) ;
if ( V_352 != NULL ) {
F_40 ( ( L_141 , V_234 -> V_358 ) ) ;
goto V_360;
}
F_43 ( V_27 ) ;
V_27 -> V_46 = V_273 ;
V_27 -> V_151 = V_2 ;
if ( V_66 ) {
F_234 ( V_361 ) ;
F_231 ( V_69 ) ;
if ( V_27 -> V_246 ) F_234 ( V_362 ) ;
} else {
V_309 -> V_11 |= V_363 ;
}
F_67 ( V_2 , V_27 ) ;
F_68 ( V_2 , V_27 ) ;
V_354 = V_27 -> V_64 ;
V_355 = V_27 -> V_80 ;
if ( V_2 == V_3 ) {
if ( V_66 == 0 ) {
F_232 ( V_87 ) -> V_364 = 0 ;
F_40 ( ( L_142 , F_60 ( V_2 ) ) ) ;
F_53 ( V_27 , F_87 () ) ;
F_241 () ;
F_242 ( V_27 ) ;
#ifndef F_129
V_353 = F_120 () ;
if ( V_353 ) F_243 ( V_353 ) ;
#endif
}
F_66 ( V_355 , V_27 -> V_79 [ 0 ] ) ;
F_69 ( V_354 , V_27 -> V_81 [ 0 ] ) ;
V_27 -> V_293 [ 0 ] = 0UL ;
V_27 -> V_303 [ 0 ] = 0UL ;
if ( V_27 -> V_73 ) {
F_29 ( V_27 -> V_74 , V_29 -> V_75 ) ;
F_32 ( V_27 -> V_76 , V_29 -> V_77 ) ;
}
F_244 ( V_2 , V_27 ) ;
F_40 ( ( L_143 , F_60 ( V_2 ) ) ) ;
} else {
V_87 = F_119 ( V_2 ) ;
V_27 -> V_55 = V_56 ;
F_53 ( V_27 , - 1 ) ;
V_27 -> V_349 = 0UL ;
F_232 ( V_87 ) -> V_348 = F_232 ( V_87 ) -> V_347 = 0 ;
}
V_88 = 0 ;
V_360:
if ( V_88 ) F_90 ( V_27 , V_27 -> V_50 , V_356 ) ;
error:
if ( V_88 && V_357 ) {
F_86 ( V_11 ) ;
V_113 . V_116 -- ;
F_89 ( V_11 ) ;
}
if ( V_66 == 0 && V_2 != V_3 ) {
F_1 ( V_2 ) ;
if ( V_88 == 0 ) {
V_88 = F_236 ( V_27 ) ;
if ( V_88 ) {
V_27 -> V_46 = V_47 ;
V_27 -> V_151 = NULL ;
}
}
}
return V_88 ;
}
static int
F_123 ( T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 )
{
struct V_1 * V_2 = F_128 ( V_27 ) ;
struct V_86 * V_346 ;
int V_365 , V_66 ;
int V_88 ;
F_40 ( ( L_144 , V_27 -> V_46 , V_2 ? F_60 ( V_2 ) : - 1 ) ) ;
V_365 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_365 == V_47 ) {
F_40 ( ( L_145 , V_365 ) ) ;
return 0 ;
}
V_88 = F_230 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) return V_88 ;
V_27 -> V_46 = V_47 ;
if ( V_66 ) {
F_231 ( V_361 ) ;
F_231 ( V_362 ) ;
F_245 ( V_3 , V_27 ) ;
if ( V_365 != V_163 )
F_90 ( V_27 , 1 , V_27 -> V_150 ) ;
V_2 -> V_309 . V_310 = NULL ;
V_27 -> V_151 = NULL ;
return 0 ;
}
V_346 = V_2 == V_3 ? V_87 : F_119 ( V_2 ) ;
if ( V_2 == V_3 ) {
F_232 ( V_87 ) -> V_364 = 1 ;
F_40 ( ( L_146 , F_60 ( V_2 ) ) ) ;
}
F_245 ( V_2 , V_27 ) ;
if ( V_365 != V_163 )
F_90 ( V_27 , 0 , V_27 -> V_150 ) ;
V_27 -> V_55 = V_56 ;
F_53 ( V_27 , - 1 ) ;
V_2 -> V_309 . V_11 &= ~ V_363 ;
V_2 -> V_309 . V_310 = NULL ;
V_27 -> V_151 = NULL ;
F_219 ( V_2 , 0 ) ;
V_27 -> V_320 = V_366 ;
V_27 -> V_319 = 0 ;
V_27 -> V_162 = 0 ;
F_40 ( ( L_147 , F_60 ( V_2 ) ) ) ;
return 0 ;
}
void
F_246 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
unsigned long V_11 ;
struct V_86 * V_87 = F_119 ( V_2 ) ;
int V_88 , V_155 ;
int V_367 = 0 ;
V_27 = F_58 ( V_2 ) ;
F_103 ( V_27 , V_11 ) ;
F_40 ( ( L_148 , V_27 -> V_46 , F_60 ( V_2 ) ) ) ;
V_155 = V_27 -> V_46 ;
switch( V_155 ) {
case V_47 :
F_63 ( V_67 L_149 , F_60 ( V_2 ) ) ;
break;
case V_273 :
case V_68 :
V_88 = F_123 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) {
F_63 ( V_67 L_150 , F_60 ( V_2 ) , V_155 , V_88 ) ;
}
F_40 ( ( L_151 , V_155 ) ) ;
F_247 ( V_27 ) ;
break;
case V_163 :
V_88 = F_123 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) {
F_63 ( V_67 L_150 , F_60 ( V_2 ) , V_155 , V_88 ) ;
}
V_367 = 1 ;
break;
default:
F_63 ( V_67 L_152 , F_60 ( V_2 ) , V_155 ) ;
break;
}
F_106 ( V_27 , V_11 ) ;
{ T_26 V_65 = F_21 () ;
F_248 ( V_65 & ( V_17 | V_16 ) ) ;
F_248 ( F_120 () ) ;
F_248 ( F_232 ( V_87 ) -> V_348 ) ;
F_248 ( F_232 ( V_87 ) -> V_347 ) ;
}
if ( V_367 ) F_55 ( V_27 ) ;
}
static int
F_249 ( T_1 * V_27 , int V_143 , unsigned long V_11 )
{
struct V_1 * V_2 ;
int V_155 , V_368 ;
V_369:
V_155 = V_27 -> V_46 ;
V_2 = V_27 -> V_151 ;
if ( V_2 == NULL ) {
F_40 ( ( L_153 , V_27 -> V_140 , V_155 ) ) ;
return 0 ;
}
F_40 ( ( L_154 ,
V_27 -> V_140 ,
V_155 ,
F_60 ( V_2 ) ,
V_2 -> V_155 , F_250 ( V_143 ) ) ) ;
if ( V_2 == V_3 || V_27 -> V_50 ) return 0 ;
switch( V_155 ) {
case V_47 :
return 0 ;
case V_163 :
F_40 ( ( L_155 , V_143 ) ) ;
return - V_106 ;
case V_68 :
if ( V_143 != V_370 ) return 0 ;
}
if ( F_250 ( V_143 ) ) {
if ( ! F_182 ( V_2 ) ) {
F_40 ( ( L_156 , F_60 ( V_2 ) ) ) ;
return - V_108 ;
}
V_368 = V_155 ;
F_106 ( V_27 , V_11 ) ;
F_183 ( V_2 , 0 ) ;
F_103 ( V_27 , V_11 ) ;
if ( V_27 -> V_46 != V_368 ) {
F_40 ( ( L_157 , V_368 , V_27 -> V_46 ) ) ;
goto V_369;
}
}
return 0 ;
}
T_27 long
F_251 ( int V_144 , int V_143 , void T_8 * V_91 , int V_243 )
{
struct V_144 V_7 = { NULL , 0 } ;
T_1 * V_27 = NULL ;
unsigned long V_11 = 0UL ;
void * V_371 = NULL ;
long V_88 ;
T_9 V_372 , V_233 , V_373 = 0 ;
int V_374 , V_375 = 0 , V_376 = 0 , V_377 ;
int (* F_252)( T_1 * V_27 , void * V_91 , int V_243 , struct V_86 * V_87 );
int (* F_253)( void * V_91 , T_9 * V_233 );
#define F_254 4096
if ( F_205 ( V_29 == NULL ) ) return - V_378 ;
if ( F_205 ( V_143 < 0 || V_143 >= V_379 ) ) {
F_40 ( ( L_158 , V_143 ) ) ;
return - V_106 ;
}
F_252 = V_380 [ V_143 ] . V_381 ;
V_374 = V_380 [ V_143 ] . V_382 ;
V_372 = V_380 [ V_143 ] . V_383 ;
F_253 = V_380 [ V_143 ] . V_384 ;
V_377 = V_380 [ V_143 ] . V_377 ;
if ( F_205 ( F_252 == NULL ) ) {
F_40 ( ( L_158 , V_143 ) ) ;
return - V_106 ;
}
F_40 ( ( L_159 ,
F_255 ( V_143 ) ,
V_143 ,
V_374 ,
V_372 ,
V_243 ) ) ;
if ( F_205 ( ( V_374 == V_385 && V_243 <= 0 ) || ( V_374 > 0 && V_374 != V_243 ) ) )
return - V_106 ;
V_386:
V_233 = V_373 + V_372 * V_243 ;
if ( F_205 ( V_233 > F_254 ) ) {
F_63 ( V_67 L_160 , F_60 ( V_3 ) , V_233 ) ;
return - V_387 ;
}
if ( F_200 ( V_243 && V_371 == NULL ) ) {
V_371 = F_256 ( F_254 , V_45 ) ;
if ( V_371 == NULL ) return - V_176 ;
}
V_88 = - V_138 ;
if ( V_233 && F_257 ( V_371 , V_91 , V_233 ) ) {
F_40 ( ( L_161 , V_233 , V_91 ) ) ;
goto V_388;
}
if ( V_375 == 0 && F_253 ) {
V_88 = (* F_253)( V_371 , & V_373 ) ;
if ( V_88 ) goto V_388;
V_375 = 1 ;
F_40 ( ( L_162 , V_233 , V_373 ) ) ;
if ( F_200 ( V_373 ) ) goto V_386;
}
if ( F_205 ( ( V_377 & V_389 ) == 0 ) ) goto V_390;
V_88 = - V_147 ;
V_7 = F_258 ( V_144 ) ;
if ( F_205 ( V_7 . V_125 == NULL ) ) {
F_40 ( ( L_163 , V_144 ) ) ;
goto V_388;
}
if ( F_205 ( F_102 ( V_7 . V_125 ) == 0 ) ) {
F_40 ( ( L_164 , V_144 ) ) ;
goto V_388;
}
V_27 = V_7 . V_125 -> V_129 ;
if ( F_205 ( V_27 == NULL ) ) {
F_40 ( ( L_165 , V_144 ) ) ;
goto V_388;
}
F_218 ( & V_27 -> V_46 ) ;
F_103 ( V_27 , V_11 ) ;
V_88 = F_249 ( V_27 , V_143 , V_11 ) ;
if ( F_205 ( V_88 ) ) goto V_136;
V_390:
V_88 = (* F_252)( V_27 , V_371 , V_243 , F_119 ( V_3 ) ) ;
V_376 = 1 ;
V_136:
if ( F_200 ( V_27 ) ) {
F_40 ( ( L_166 ) ) ;
F_106 ( V_27 , V_11 ) ;
}
if ( V_376 && F_259 ( V_143 ) && F_110 ( V_91 , V_371 , V_372 * V_243 ) ) V_88 = - V_138 ;
V_388:
if ( V_7 . V_125 )
F_260 ( V_7 ) ;
F_56 ( V_371 ) ;
F_40 ( ( L_167 , F_255 ( V_143 ) , V_88 ) ) ;
return V_88 ;
}
static void
F_261 ( T_1 * V_27 , unsigned long V_258 , struct V_86 * V_87 )
{
T_4 * V_84 = V_27 -> V_166 ;
T_5 V_314 ;
int V_155 ;
int V_88 = 0 ;
V_155 = V_27 -> V_46 ;
if ( F_217 ( V_27 ) ) {
V_314 . V_315 . V_316 = 0 ;
V_314 . V_315 . V_317 = 0 ;
if ( V_155 == V_273 )
V_88 = F_76 ( V_84 , V_3 , & V_314 , V_27 -> V_164 , V_87 ) ;
else
V_88 = F_75 ( V_84 , V_3 , & V_314 , V_27 -> V_164 , V_87 ) ;
} else {
V_314 . V_315 . V_316 = 0 ;
V_314 . V_315 . V_317 = 1 ;
}
if ( V_88 == 0 ) {
if ( V_314 . V_315 . V_317 ) {
F_197 ( V_27 , & V_258 , V_318 ) ;
}
if ( V_314 . V_315 . V_316 == 0 ) {
F_40 ( ( L_168 ) ) ;
if ( V_27 -> V_46 == V_68 ) F_62 ( V_3 ) ;
} else {
F_40 ( ( L_169 ) ) ;
}
V_27 -> V_46 = V_273 ;
}
}
static void
F_262 ( T_1 * V_27 , struct V_86 * V_87 )
{
int V_88 ;
F_40 ( ( L_170 , F_60 ( V_3 ) ) ) ;
V_88 = F_123 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) {
F_63 ( V_67 L_171 , F_60 ( V_3 ) , V_88 ) ;
}
F_263 ( & V_27 -> V_58 ) ;
}
void
F_264 ( void )
{
T_1 * V_27 ;
struct V_86 * V_87 ;
unsigned long V_11 , V_391 ;
unsigned long V_258 ;
unsigned int V_392 ;
int V_88 ;
V_27 = F_58 ( V_3 ) ;
if ( V_27 == NULL ) {
F_63 ( V_67 L_172 ,
F_60 ( V_3 ) ) ;
return;
}
F_103 ( V_27 , V_11 ) ;
F_219 ( V_3 , 0 ) ;
V_87 = F_119 ( V_3 ) ;
V_392 = V_27 -> V_320 ;
V_27 -> V_320 = V_366 ;
V_258 = V_27 -> V_291 [ 0 ] ;
F_40 ( ( L_173 , V_392 , V_27 -> V_46 ) ) ;
if ( V_27 -> V_162 || V_27 -> V_46 == V_163 )
goto V_393;
if ( V_392 == V_321 )
goto V_394;
F_106 ( V_27 , V_11 ) ;
F_265 () ;
F_40 ( ( L_174 ) ) ;
V_88 = F_266 ( & V_27 -> V_54 ) ;
F_40 ( ( L_175 , V_88 ) ) ;
F_103 ( V_27 , V_391 ) ;
V_258 = V_27 -> V_291 [ 0 ] ;
if ( V_27 -> V_162 ) {
V_393:
F_40 ( ( L_176 ) ) ;
F_262 ( V_27 , V_87 ) ;
goto V_395;
}
if ( V_88 < 0 )
goto V_395;
V_394:
F_261 ( V_27 , V_258 , V_87 ) ;
V_27 -> V_291 [ 0 ] = 0UL ;
V_395:
F_106 ( V_27 , V_11 ) ;
}
static int
F_267 ( T_1 * V_27 , T_2 * V_37 )
{
if ( V_27 -> V_46 == V_163 ) {
F_40 ( ( L_177 ) ) ;
return 0 ;
}
F_40 ( ( L_178 ) ) ;
if ( V_37 ) F_263 ( & V_27 -> V_57 ) ;
F_268 ( & V_27 -> V_146 , V_396 , V_397 ) ;
return 0 ;
}
static int
F_269 ( T_1 * V_27 , unsigned long V_398 )
{
T_2 * V_37 = NULL ;
if ( V_27 -> V_52 == 0 ) {
V_37 = F_39 ( V_27 ) ;
if ( V_37 == NULL ) {
F_63 ( V_67 L_179 ) ;
return - 1 ;
}
V_37 -> V_399 . V_39 = V_400 ;
V_37 -> V_399 . V_137 = V_27 -> V_140 ;
V_37 -> V_399 . V_401 = 0 ;
V_37 -> V_399 . V_402 [ 0 ] = V_398 ;
V_37 -> V_399 . V_402 [ 1 ] = 0UL ;
V_37 -> V_399 . V_402 [ 2 ] = 0UL ;
V_37 -> V_399 . V_402 [ 3 ] = 0UL ;
V_37 -> V_399 . V_403 = 0UL ;
}
F_40 ( ( L_180 ,
V_37 ,
V_27 -> V_52 ,
V_27 -> V_140 ,
V_398 ) ) ;
return F_267 ( V_27 , V_37 ) ;
}
static int
F_247 ( T_1 * V_27 )
{
T_2 * V_37 ;
V_37 = F_39 ( V_27 ) ;
if ( V_37 == NULL ) {
F_63 ( V_67 L_181 ) ;
return - 1 ;
}
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_404 . V_39 = V_405 ;
V_37 -> V_404 . V_137 = V_27 -> V_140 ;
V_37 -> V_399 . V_403 = 0UL ;
F_40 ( ( L_182 ,
V_37 ,
V_27 -> V_52 ,
V_27 -> V_140 ) ) ;
return F_267 ( V_27 , V_37 ) ;
}
static void F_270 ( struct V_1 * V_2 , T_1 * V_27 ,
unsigned long V_406 , struct V_86 * V_87 )
{
T_28 * V_407 ;
unsigned long V_59 ;
unsigned long V_408 , V_30 , V_409 ;
unsigned long V_410 = 0UL , V_398 = 0UL , V_263 = 0UL , V_260 ;
unsigned long V_411 ;
T_5 V_412 ;
unsigned int V_24 , V_413 ;
int V_414 = 0 ;
if ( F_205 ( V_27 -> V_46 == V_163 ) ) goto V_415;
if ( F_205 ( ( V_406 & 0x1 ) == 0 ) ) goto V_416;
V_411 = F_271 () ;
V_59 = V_406 >> V_63 ;
V_30 = V_29 -> V_30 ;
V_413 = F_217 ( V_27 ) ;
F_59 ( ( L_183
L_184 ,
V_406 ,
V_2 ? F_60 ( V_2 ) : - 1 ,
( V_87 ? V_87 -> V_417 : 0 ) ,
F_131 ( V_27 ) ? L_185 : L_186 ,
V_27 -> V_61 [ 0 ] ) ) ;
for ( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1 ) == 0 ) continue;
V_408 = V_409 = V_27 -> V_28 [ V_24 ] . V_20 ;
V_409 += 1 + V_30 ;
V_27 -> V_28 [ V_24 ] . V_20 = V_409 ;
if ( F_200 ( V_408 > V_409 ) ) {
V_398 |= 1UL << V_24 ;
if ( F_209 ( V_27 , V_24 ) ) V_410 |= 1UL << V_24 ;
}
F_59 ( ( L_187 ,
V_24 ,
V_409 ,
V_408 ,
F_36 ( V_24 ) & V_30 ,
V_398 ,
V_410 ) ) ;
}
if ( V_398 == 0UL ) return;
V_412 . V_20 = 0 ;
V_260 = 0UL ;
if ( V_413 ) {
unsigned long V_418 , V_419 ;
unsigned long V_420 ;
int V_421 , V_422 , V_88 = 0 ;
int V_423 = F_87 () ;
V_420 = V_398 >> V_63 ;
V_407 = & V_27 -> V_424 ;
F_218 ( V_27 -> V_164 ) ;
for( V_24 = V_63 ; V_420 && V_88 == 0 ; V_24 ++ , V_420 >>= 1 ) {
V_59 = 1UL << V_24 ;
if ( ( V_420 & 0x1 ) == 0 ) continue;
V_407 -> V_425 = ( unsigned char ) V_24 ;
V_407 -> V_410 = V_410 & V_59 ? 1 : 0 ;
V_407 -> V_426 = 0 ;
V_407 -> V_412 . V_20 = 0 ;
V_407 -> V_263 [ 0 ] = V_263 = V_27 -> V_28 [ V_24 ] . V_263 [ 0 ] ;
V_407 -> V_427 = V_27 -> V_28 [ V_24 ] . V_20 ;
V_407 -> V_428 = V_27 -> V_28 [ V_24 ] . V_257 ;
V_407 -> V_429 = V_27 -> V_28 [ V_24 ] . V_289 ;
if ( V_263 ) {
for( V_421 = 0 , V_422 = 0 ; V_263 ; V_421 ++ , V_263 >>= 1 ) {
if ( ( V_263 & 0x1 ) == 0 ) continue;
V_407 -> V_430 [ V_422 ++ ] = F_61 ( V_421 ) ? F_35 ( V_27 , V_421 ) : F_36 ( V_421 ) ;
F_59 ( ( L_188 , V_422 - 1 , V_421 , V_407 -> V_430 [ V_422 - 1 ] ) ) ;
}
}
V_324 [ V_423 ] . V_431 ++ ;
V_418 = F_271 () ;
V_88 = (* V_27 -> V_166 -> V_107 )( V_2 , V_27 -> V_164 , V_407 , V_87 , V_411 ) ;
V_419 = F_271 () ;
V_412 . V_315 . V_432 |= V_407 -> V_412 . V_315 . V_432 ;
V_412 . V_315 . V_433 |= V_407 -> V_412 . V_315 . V_433 ;
V_412 . V_315 . V_316 |= V_407 -> V_412 . V_315 . V_316 ;
if ( V_407 -> V_412 . V_315 . V_317 ) V_260 |= V_59 ;
V_324 [ V_423 ] . V_434 += V_419 - V_418 ;
}
if ( V_88 && V_420 ) {
F_40 ( ( L_189 ,
V_420 << V_63 ) ) ;
}
V_398 &= ~ V_260 ;
} else {
V_412 . V_315 . V_432 = V_410 ? 1 : 0 ;
V_412 . V_315 . V_433 = V_410 ? 1 : 0 ;
V_412 . V_315 . V_316 = V_410 ? 1 : 0 ;
V_412 . V_315 . V_317 = V_410 ? 0 : 1 ;
if ( V_410 == 0 ) V_260 = V_398 ;
}
F_59 ( ( L_190 , V_398 , V_260 ) ) ;
if ( V_260 ) {
unsigned long V_435 = V_260 ;
F_197 ( V_27 , & V_435 , V_436 ) ;
}
if ( V_410 && V_412 . V_315 . V_432 ) {
V_27 -> V_291 [ 0 ] = V_398 ;
if ( F_131 ( V_27 ) == 0 && V_412 . V_315 . V_433 ) {
V_27 -> V_320 = V_437 ;
F_219 ( V_2 , 1 ) ;
F_220 ( V_2 ) ;
}
V_414 = 1 ;
}
F_59 ( ( L_191 ,
F_120 () ? F_60 ( F_120 () ) : - 1 ,
F_272 ( V_2 ) ,
V_27 -> V_320 ,
V_398 ,
V_410 ,
V_412 . V_315 . V_316 ? 1 : 0 ) ) ;
if ( V_412 . V_315 . V_316 ) {
F_57 ( V_2 ) ;
V_27 -> V_46 = V_68 ;
V_27 -> V_319 = 1 ;
}
if ( V_414 ) F_269 ( V_27 , V_410 ) ;
return;
V_416:
F_63 ( V_67 L_192 ,
F_87 () ,
V_2 ? F_60 ( V_2 ) : - 1 ,
V_406 ) ;
return;
V_415:
F_40 ( ( L_193 , V_2 ? F_60 ( V_2 ) : - 1 ) ) ;
F_19 () ;
F_232 ( V_87 ) -> V_348 = 0 ;
F_232 ( V_87 ) -> V_364 = 1 ;
return;
}
static int
F_273 ( void * V_91 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_1 * V_27 ;
unsigned long V_11 ;
T_26 V_406 ;
int V_423 = F_87 () ;
int V_438 = 0 ;
V_324 [ V_423 ] . V_439 ++ ;
V_406 = F_274 ( 0 ) ;
V_2 = F_120 () ;
V_27 = F_121 () ;
if ( F_275 ( V_406 ) && V_2 ) {
if ( ! V_27 ) goto V_440;
if ( V_27 -> V_50 == 0 && ( V_2 -> V_309 . V_11 & V_363 ) == 0 )
goto V_441;
F_276 ( V_27 , V_11 ) ;
F_270 ( V_2 , V_27 , V_406 , V_87 ) ;
F_277 ( V_27 , V_11 ) ;
} else {
V_324 [ V_423 ] . V_442 ++ ;
V_438 = - 1 ;
}
F_28 () ;
return V_438 ;
V_440:
F_63 ( V_111 L_194 ,
V_423 , F_60 ( V_2 ) ) ;
F_28 () ;
return - 1 ;
V_441:
F_63 ( V_111 L_195 ,
V_423 ,
F_60 ( V_2 ) ) ;
F_28 () ;
return - 1 ;
}
static T_29
F_278 ( int V_443 , void * V_91 )
{
unsigned long V_418 , V_444 ;
unsigned long V_445 , V_446 ;
int V_423 ;
int V_88 ;
struct V_86 * V_87 = F_279 () ;
V_423 = F_280 () ;
if ( F_200 ( ! V_447 ) ) {
V_445 = V_324 [ V_423 ] . V_326 ;
V_446 = V_324 [ V_423 ] . V_448 ;
V_418 = F_271 () ;
V_88 = F_273 ( V_91 , V_87 ) ;
V_444 = F_271 () ;
if ( F_200 ( V_88 == 0 ) ) {
V_444 -= V_418 ;
if ( V_444 < V_445 ) V_324 [ V_423 ] . V_326 = V_444 ;
if ( V_444 > V_446 ) V_324 [ V_423 ] . V_448 = V_444 ;
V_324 [ V_423 ] . V_449 += V_444 ;
}
}
else {
(* V_447 -> V_450 )( V_443 , V_91 , V_87 ) ;
}
F_281 () ;
return V_451 ;
}
static void *
F_282 ( struct V_452 * V_322 , T_10 * V_100 )
{
if ( * V_100 == 0 ) {
return V_453 ;
}
while ( * V_100 <= V_454 ) {
if ( F_283 ( * V_100 - 1 ) ) {
return ( void * ) * V_100 ;
}
++ * V_100 ;
}
return NULL ;
}
static void *
F_284 ( struct V_452 * V_322 , void * V_298 , T_10 * V_100 )
{
++ * V_100 ;
return F_282 ( V_322 , V_100 ) ;
}
static void
F_285 ( struct V_452 * V_322 , void * V_298 )
{
}
static void
F_286 ( struct V_452 * V_322 )
{
struct V_99 * V_100 ;
T_4 * V_101 ;
unsigned long V_11 ;
F_287 ( V_322 ,
L_196
L_197
L_198
L_199
L_200
L_201 ,
V_455 , V_456 ,
V_29 -> V_457 ,
V_274 . V_458 > 0 ? L_202 : L_203 ,
V_274 . V_269 > 0 ? L_202 : L_203 ,
V_29 -> V_30 ,
V_29 -> V_11 ) ;
F_86 ( V_11 ) ;
F_287 ( V_322 ,
L_204
L_205
L_206
L_207 ,
V_113 . V_115 ,
V_113 . V_114 ,
V_113 . V_116 ,
V_113 . V_313 ) ;
F_89 ( V_11 ) ;
F_9 ( & V_104 ) ;
F_78 (pos, &pfm_buffer_fmt_list) {
V_101 = F_79 ( V_100 , T_4 , V_102 ) ;
F_287 ( V_322 , L_208 ,
V_101 -> V_103 , V_101 -> V_105 ) ;
}
F_11 ( & V_104 ) ;
}
static int
F_288 ( struct V_452 * V_322 , void * V_298 )
{
unsigned long V_65 ;
unsigned int V_24 ;
int V_90 ;
if ( V_298 == V_453 ) {
F_286 ( V_322 ) ;
return 0 ;
}
V_90 = ( long ) V_298 - 1 ;
F_287 ( V_322 ,
L_209
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
L_222 ,
V_90 , V_324 [ V_90 ] . V_439 ,
V_90 , V_324 [ V_90 ] . V_449 ,
V_90 , V_324 [ V_90 ] . V_326 ,
V_90 , V_324 [ V_90 ] . V_448 ,
V_90 , V_324 [ V_90 ] . V_431 ,
V_90 , V_324 [ V_90 ] . V_434 ,
V_90 , V_324 [ V_90 ] . V_442 ,
V_90 , V_324 [ V_90 ] . V_459 ,
V_90 , F_289 ( V_460 , V_90 ) & V_361 ? 1 : 0 ,
V_90 , F_289 ( V_460 , V_90 ) & V_69 ? 1 : 0 ,
V_90 , F_289 ( V_460 , V_90 ) & V_362 ? 1 : 0 ,
V_90 , F_289 ( V_461 , V_90 ) ? F_289 ( V_461 , V_90 ) -> V_239 : - 1 ,
V_90 , F_289 ( V_462 , V_90 ) ,
V_90 , F_289 ( V_463 , V_90 ) ) ;
if ( F_290 () == 1 && V_274 . V_323 > 0 ) {
V_65 = F_21 () ;
F_27 () ;
F_287 ( V_322 ,
L_223
L_224 ,
V_90 , V_65 ,
V_90 , F_274 ( 0 ) ) ;
for ( V_24 = 0 ; F_177 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_291 ( V_24 ) == 0 ) continue;
F_287 ( V_322 ,
L_225
L_226 ,
V_90 , V_24 , F_274 ( V_24 ) ,
V_90 , V_24 , F_36 ( V_24 ) ) ;
}
}
return 0 ;
}
static int
F_292 ( struct V_158 * V_158 , struct V_125 * V_125 )
{
return F_293 ( V_125 , & V_464 ) ;
}
void
F_294 ( struct V_1 * V_2 , unsigned long V_148 , int V_465 )
{
struct V_86 * V_87 ;
unsigned long V_466 ;
unsigned long V_467 ;
V_467 = V_148 & V_69 ? 1 : 0 ;
if ( ( V_148 & V_362 ) == 0 || V_2 -> V_239 ) {
V_87 = F_119 ( V_2 ) ;
F_232 ( V_87 ) -> V_347 = V_465 ? V_467 : 0 ;
return;
}
if ( V_467 ) {
V_466 = F_22 ( V_70 ) ;
if ( V_465 ) {
F_24 ( V_70 , V_466 & ~ V_71 ) ;
F_14 () ;
F_16 () ;
return;
}
F_24 ( V_70 , V_466 | V_71 ) ;
F_17 () ;
F_16 () ;
}
}
static void
F_295 ( T_1 * V_27 , struct V_86 * V_87 )
{
struct V_1 * V_2 = V_27 -> V_151 ;
F_232 ( V_87 ) -> V_348 = 0 ;
F_232 ( V_87 ) -> V_364 = 1 ;
if ( F_120 () == V_2 ) {
F_40 ( ( L_227 ,
F_60 ( V_27 -> V_151 ) ) ) ;
F_244 ( NULL , NULL ) ;
}
F_219 ( V_2 , 0 ) ;
V_2 -> V_309 . V_310 = NULL ;
V_2 -> V_309 . V_11 &= ~ V_363 ;
F_40 ( ( L_228 , F_60 ( V_2 ) ) ) ;
}
void
F_296 ( struct V_1 * V_2 )
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
F_295 ( V_27 , V_87 ) ;
F_248 ( V_27 -> V_164 ) ;
F_10 ( V_27 , V_11 ) ;
F_55 ( V_27 ) ;
return;
}
F_27 () ;
V_65 = F_21 () ;
F_248 ( V_65 & ( V_468 ) ) ;
F_19 () ;
V_27 -> V_349 = V_65 & V_17 ;
F_244 ( NULL , NULL ) ;
F_65 ( V_27 -> V_80 , V_27 -> V_61 [ 0 ] ) ;
V_27 -> V_64 [ 0 ] = F_274 ( 0 ) ;
if ( V_27 -> V_64 [ 0 ] & ~ 0x1UL ) F_28 () ;
F_10 ( V_27 , V_11 ) ;
}
void
F_296 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
T_26 V_65 ;
V_27 = F_58 ( V_2 ) ;
if ( V_27 == NULL ) return;
V_65 = F_21 () ;
F_248 ( V_65 & ( V_468 ) ) ;
F_19 () ;
V_27 -> V_349 = V_65 & V_17 ;
}
static void
F_243 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
unsigned long V_11 ;
{ T_26 V_65 = F_21 () ;
F_248 ( V_65 & V_17 ) ;
}
V_27 = F_58 ( V_2 ) ;
F_103 ( V_27 , V_11 ) ;
F_244 ( NULL , NULL ) ;
F_65 ( V_27 -> V_80 , V_27 -> V_61 [ 0 ] ) ;
V_27 -> V_64 [ 0 ] = F_274 ( 0 ) ;
if ( V_27 -> V_64 [ 0 ] & ~ 0x1UL ) F_28 () ;
F_106 ( V_27 , V_11 ) ;
}
void
F_297 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
unsigned long V_469 = 0UL , V_420 = 0UL ;
unsigned long V_11 ;
T_26 V_65 , V_470 ;
int V_471 ;
V_27 = F_58 ( V_2 ) ;
if ( F_205 ( V_27 == NULL ) ) return;
F_248 ( F_120 () ) ;
if ( F_205 ( ( V_2 -> V_309 . V_11 & V_363 ) == 0 ) ) return;
V_11 = F_8 ( V_27 ) ;
V_65 = F_21 () ;
V_471 = V_29 -> V_11 & V_472 ;
F_248 ( V_65 & ( V_17 | V_16 ) ) ;
F_248 ( V_65 & V_468 ) ;
if ( F_205 ( V_27 -> V_46 == V_163 ) ) {
struct V_86 * V_87 = F_119 ( V_2 ) ;
F_248 ( V_27 -> V_164 ) ;
F_295 ( V_27 , V_87 ) ;
F_10 ( V_27 , V_11 ) ;
F_55 ( V_27 ) ;
return;
}
if ( V_27 -> V_73 ) {
F_29 ( V_27 -> V_74 , V_29 -> V_75 ) ;
F_32 ( V_27 -> V_76 , V_29 -> V_77 ) ;
}
V_470 = V_27 -> V_349 ;
if ( F_298 ( V_27 ) == F_87 () && V_27 -> V_55 == F_299 () ) {
V_469 = V_27 -> V_293 [ 0 ] ;
V_420 = V_27 -> V_303 [ 0 ] ;
} else {
V_420 = V_274 . V_458 ? V_27 -> V_61 [ 0 ] : V_27 -> V_79 [ 0 ] ;
V_469 = V_27 -> V_81 [ 0 ] ;
}
if ( V_420 ) F_66 ( V_27 -> V_80 , V_420 ) ;
if ( V_469 ) F_69 ( V_27 -> V_64 , V_469 ) ;
if ( F_205 ( F_275 ( V_27 -> V_64 [ 0 ] ) ) ) {
F_26 ( 0 , V_27 -> V_64 [ 0 ] ) ;
F_27 () ;
V_27 -> V_64 [ 0 ] = 0UL ;
if ( V_471 ) F_300 ( V_473 ) ;
V_324 [ F_87 () ] . V_459 ++ ;
}
V_27 -> V_293 [ 0 ] = 0UL ;
V_27 -> V_303 [ 0 ] = 0UL ;
F_53 ( V_27 , F_87 () ) ;
F_241 () ;
F_242 ( V_27 ) ;
F_244 ( V_2 , V_27 ) ;
if ( F_200 ( V_470 ) ) F_20 () ;
F_10 ( V_27 , V_11 ) ;
}
void
F_297 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
struct V_1 * V_149 ;
unsigned long V_420 , V_469 ;
T_26 V_65 , V_470 ;
int V_471 ;
V_149 = F_120 () ;
V_27 = F_58 ( V_2 ) ;
V_65 = F_21 () ;
F_248 ( V_65 & ( V_17 | V_16 ) ) ;
F_248 ( V_65 & V_468 ) ;
if ( V_27 -> V_73 ) {
F_29 ( V_27 -> V_74 , V_29 -> V_75 ) ;
F_32 ( V_27 -> V_76 , V_29 -> V_77 ) ;
}
V_470 = V_27 -> V_349 ;
V_471 = V_29 -> V_11 & V_472 ;
if ( F_200 ( V_149 == V_2 ) ) {
if ( F_200 ( V_470 ) ) F_20 () ;
return;
}
if ( V_149 ) F_243 ( V_149 ) ;
V_420 = V_274 . V_458 ? V_27 -> V_61 [ 0 ] : V_27 -> V_79 [ 0 ] ;
V_469 = V_27 -> V_81 [ 0 ] ;
F_66 ( V_27 -> V_80 , V_420 ) ;
F_69 ( V_27 -> V_64 , V_469 ) ;
if ( F_205 ( F_275 ( V_27 -> V_64 [ 0 ] ) ) ) {
F_26 ( 0 , V_27 -> V_64 [ 0 ] ) ;
F_27 () ;
V_27 -> V_64 [ 0 ] = 0UL ;
if ( V_471 ) F_300 ( V_473 ) ;
V_324 [ F_87 () ] . V_459 ++ ;
}
F_244 ( V_2 , V_27 ) ;
if ( F_200 ( V_470 ) ) F_20 () ;
}
static void
F_245 ( struct V_1 * V_2 , T_1 * V_27 )
{
T_26 V_406 ;
unsigned long V_474 , V_20 , V_475 , V_30 ;
int V_24 , V_267 = 0 ;
int V_476 ;
V_476 = V_27 -> V_151 == V_2 ? 1 : 0 ;
V_267 = ( F_120 () == V_2 ) || ( V_27 -> V_50 && V_27 -> V_150 == F_87 () ) ;
if ( V_267 ) {
F_244 ( NULL , NULL ) ;
F_40 ( ( L_229 ) ) ;
F_27 () ;
V_406 = F_274 ( 0 ) ;
F_28 () ;
} else {
V_406 = V_27 -> V_64 [ 0 ] ;
V_27 -> V_64 [ 0 ] = 0 ;
}
V_30 = V_29 -> V_30 ;
V_474 = V_27 -> V_61 [ 0 ] ;
F_40 ( ( L_230 , V_476 , V_30 , V_474 ) ) ;
for ( V_24 = 0 ; V_474 ; V_24 ++ , V_474 >>= 1 ) {
if ( ( V_474 & 0x1 ) == 0 ) continue;
V_20 = V_475 = V_267 ? F_36 ( V_24 ) : V_27 -> V_80 [ V_24 ] ;
if ( F_61 ( V_24 ) ) {
F_40 ( ( L_231 ,
F_60 ( V_2 ) ,
V_24 ,
V_27 -> V_28 [ V_24 ] . V_20 ,
V_20 & V_30 ) ) ;
V_20 = V_27 -> V_28 [ V_24 ] . V_20 + ( V_20 & V_30 ) ;
V_475 = 0UL ;
if ( V_406 & ( 1UL << V_24 ) ) {
V_20 += 1 + V_30 ;
F_40 ( ( L_232 , F_60 ( V_2 ) , V_24 ) ) ;
}
}
F_40 ( ( L_233 , F_60 ( V_2 ) , V_24 , V_20 , V_475 ) ) ;
if ( V_476 ) V_27 -> V_80 [ V_24 ] = V_475 ;
V_27 -> V_28 [ V_24 ] . V_20 = V_20 ;
}
}
static void
F_301 ( void * V_13 )
{
struct V_86 * V_87 ;
V_87 = F_119 ( V_3 ) ;
F_40 ( ( L_234 ) ) ;
F_19 () ;
F_14 () ;
F_232 ( V_87 ) -> V_347 = 0 ;
F_25 () ;
F_27 () ;
}
void
F_302 ( void * V_13 )
{
struct V_86 * V_87 ;
V_87 = F_119 ( V_3 ) ;
F_40 ( ( L_234 ) ) ;
F_19 () ;
F_14 () ;
F_232 ( V_87 ) -> V_347 = 0 ;
F_28 () ;
F_27 () ;
}
int
F_303 ( T_30 * V_477 )
{
int V_88 , V_24 ;
int V_478 ;
if ( V_477 == NULL || V_477 -> V_450 == NULL ) return - V_106 ;
if ( V_447 ) return - V_108 ;
if ( ! F_304 ( & V_479 ) ) {
return - V_108 ;
}
F_305 (reserve_cpu) {
V_88 = F_85 ( NULL , 1 , V_478 ) ;
if ( V_88 ) goto V_480;
}
V_88 = F_306 ( F_301 , NULL , 1 ) ;
if ( V_88 ) {
F_40 ( ( L_235 , V_88 ) ) ;
goto V_480;
}
V_447 = V_477 ;
F_11 ( & V_479 ) ;
return 0 ;
V_480:
F_305 (i) {
if ( V_24 >= V_478 ) break;
F_90 ( NULL , 1 , V_24 ) ;
}
F_11 ( & V_479 ) ;
return V_88 ;
}
int
F_307 ( T_30 * V_477 )
{
int V_24 ;
int V_88 ;
if ( V_477 == NULL ) return - V_106 ;
if ( V_447 != V_477 ) return - V_106 ;
if ( ! F_304 ( & V_479 ) ) {
return - V_108 ;
}
V_447 = NULL ;
V_88 = F_306 ( F_302 , NULL , 1 ) ;
if ( V_88 ) {
F_40 ( ( L_235 , V_88 ) ) ;
}
F_305 (i) {
F_90 ( NULL , 1 , V_24 ) ;
}
F_11 ( & V_479 ) ;
return 0 ;
}
static int T_6
F_308 ( void )
{
T_31 * * V_240 ;
int V_481 ;
V_481 = V_482 -> V_481 ;
V_240 = V_483 ;
while( * V_240 ) {
if ( ( * V_240 ) -> V_484 ) {
if ( ( * V_240 ) -> V_484 () == 0 ) goto V_485;
} else if ( ( * V_240 ) -> V_486 == V_481 || ( * V_240 ) -> V_486 == 0xff ) {
goto V_485;
}
V_240 ++ ;
}
return - 1 ;
V_485:
V_29 = * V_240 ;
return 0 ;
}
int T_6
F_309 ( void )
{
unsigned int V_487 , V_488 , V_24 ;
F_63 ( L_236 ,
V_455 ,
V_456 ,
V_473 ) ;
if ( F_308 () ) {
F_63 ( V_111 L_237 ,
V_482 -> V_481 ) ;
return - V_489 ;
}
V_487 = 0 ;
for ( V_24 = 0 ; F_177 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_178 ( V_24 ) == 0 ) continue;
V_29 -> V_229 [ V_24 >> 6 ] |= 1UL << ( V_24 & 63 ) ;
V_487 ++ ;
}
V_29 -> V_490 = V_487 ;
V_487 = 0 ; V_488 = 0 ;
for ( V_24 = 0 ; F_310 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_206 ( V_24 ) == 0 ) continue;
V_29 -> V_230 [ V_24 >> 6 ] |= 1UL << ( V_24 & 63 ) ;
V_487 ++ ;
if ( F_61 ( V_24 ) ) V_488 ++ ;
}
V_29 -> V_491 = V_487 ;
V_29 -> V_492 = V_488 ;
if ( V_29 -> V_311 ) {
if ( V_29 -> V_75 > V_493 ) {
F_63 ( V_111 L_238 , V_29 -> V_75 ) ;
V_29 = NULL ;
return - 1 ;
}
if ( V_29 -> V_77 > V_493 ) {
F_63 ( V_111 L_239 , V_29 -> V_75 ) ;
V_29 = NULL ;
return - 1 ;
}
}
F_63 ( L_240 ,
V_29 -> V_457 ,
V_29 -> V_490 ,
V_29 -> V_491 ,
V_29 -> V_492 ,
F_311 ( V_29 -> V_30 ) ) ;
if ( V_29 -> V_491 >= V_494 || V_29 -> V_490 >= V_495 ) {
F_63 ( V_67 L_241 ) ;
V_29 = NULL ;
return - 1 ;
}
V_496 = F_312 ( L_242 , V_179 , NULL , & V_497 ) ;
if ( V_496 == NULL ) {
F_63 ( V_67 L_243 ) ;
V_29 = NULL ;
return - 1 ;
}
V_498 = F_313 ( V_499 ) ;
F_51 ( & V_113 . V_500 ) ;
F_51 ( & V_104 ) ;
F_94 () ;
for( V_24 = 0 ; V_24 < V_325 ; V_24 ++ ) V_324 [ V_24 ] . V_326 = ~ 0UL ;
return 0 ;
}
void
F_314 ( void )
{
static int V_331 = 1 ;
F_14 () ;
F_19 () ;
F_28 () ;
if ( V_331 ) {
F_315 ( V_473 , & V_501 ) ;
V_331 = 0 ;
}
F_24 ( V_502 , V_473 ) ;
F_27 () ;
}
void
F_316 ( const char * V_503 )
{
struct V_1 * V_2 ;
struct V_86 * V_87 ;
T_1 * V_27 ;
unsigned long V_65 , V_466 , V_148 , V_11 ;
int V_24 , V_423 ;
F_122 ( V_11 ) ;
V_423 = F_87 () ;
V_87 = F_119 ( V_3 ) ;
V_148 = F_64 () ;
V_466 = F_22 ( V_70 ) ;
if ( V_148 == 0 && F_232 ( V_87 ) -> V_347 == 0 && ( V_466 & V_71 ) == 0 ) {
F_124 ( V_11 ) ;
return;
}
F_63 ( L_244 ,
V_423 ,
V_503 ,
F_60 ( V_3 ) ,
V_87 -> V_417 ,
V_3 -> V_504 ) ;
V_2 = F_120 () ;
V_27 = F_121 () ;
F_63 ( L_245 , V_423 , V_2 ? F_60 ( V_2 ) : - 1 , V_27 ) ;
V_65 = F_21 () ;
F_63 ( L_246 ,
V_423 ,
F_274 ( 0 ) ,
V_65 & V_16 ? 1 : 0 ,
V_65 & V_17 ? 1 : 0 ,
V_466 & V_71 ? 1 : 0 ,
V_148 ,
F_232 ( V_87 ) -> V_348 ,
F_232 ( V_87 ) -> V_347 ) ;
F_232 ( V_87 ) -> V_348 = 0 ;
F_232 ( V_87 ) -> V_347 = 0 ;
for ( V_24 = 1 ; F_177 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_178 ( V_24 ) == 0 ) continue;
F_63 ( L_247 , V_423 , V_24 , F_274 ( V_24 ) , V_24 , V_27 -> V_64 [ V_24 ] ) ;
}
for ( V_24 = 1 ; F_310 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_206 ( V_24 ) == 0 ) continue;
F_63 ( L_248 , V_423 , V_24 , F_36 ( V_24 ) , V_24 , V_27 -> V_80 [ V_24 ] ) ;
}
if ( V_27 ) {
F_63 ( L_249 ,
V_423 ,
V_27 -> V_46 ,
V_27 -> V_156 ,
V_27 -> V_164 ,
V_27 -> V_35 ,
V_27 -> V_33 ,
V_27 -> V_349 ) ;
}
F_124 ( V_11 ) ;
}
void
F_317 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_328 * V_309 ;
F_40 ( ( L_250 , F_60 ( V_2 ) ) ) ;
V_309 = & V_2 -> V_309 ;
V_309 -> V_310 = NULL ;
F_219 ( V_2 , 0 ) ;
}
T_27 long
F_251 ( int V_144 , int V_143 , void * V_91 , int V_243 )
{
return - V_378 ;
}
