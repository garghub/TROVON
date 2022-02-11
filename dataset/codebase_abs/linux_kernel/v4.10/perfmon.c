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
F_135 ( V_8 ) -> V_169 ) ;
}
static struct V_125 *
F_136 ( T_1 * V_27 )
{
struct V_125 * V_125 ;
struct V_158 * V_158 ;
struct V_170 V_170 ;
struct V_171 V_172 = { . V_173 = L_69 } ;
V_158 = F_137 ( V_124 -> V_174 ) ;
if ( ! V_158 )
return F_138 ( - V_175 ) ;
F_40 ( ( L_70 , V_158 -> V_169 , V_158 ) ) ;
V_158 -> V_176 = V_177 | V_178 ;
V_158 -> V_179 = F_139 () ;
V_158 -> V_180 = F_140 () ;
V_170 . V_8 = F_141 ( V_124 -> V_181 , & V_172 ) ;
if ( ! V_170 . V_8 ) {
F_142 ( V_158 ) ;
return F_138 ( - V_175 ) ;
}
V_170 . V_182 = F_143 ( V_124 ) ;
F_144 ( V_170 . V_8 , V_158 ) ;
V_125 = F_145 ( & V_170 , V_183 , & V_184 ) ;
if ( F_98 ( V_125 ) ) {
F_146 ( & V_170 ) ;
return V_125 ;
}
V_125 -> V_132 = V_185 ;
V_125 -> V_129 = V_27 ;
return V_125 ;
}
static int
F_147 ( struct V_186 * V_187 , unsigned long V_85 , unsigned long V_42 , unsigned long V_40 )
{
F_40 ( ( L_71 , F_87 () , V_85 , V_42 , V_40 ) ) ;
while ( V_40 > 0 ) {
unsigned long V_188 = F_148 ( V_85 ) >> V_189 ;
if ( F_149 ( V_187 , V_42 , V_188 , V_43 , V_190 ) )
return - V_175 ;
V_42 += V_43 ;
V_85 += V_43 ;
V_40 -= V_43 ;
}
return 0 ;
}
static int
F_150 ( struct V_1 * V_2 , struct V_125 * V_126 , T_1 * V_27 , unsigned long V_191 , void * * V_192 )
{
struct V_193 * V_121 = V_2 -> V_121 ;
struct V_186 * V_187 = NULL ;
unsigned long V_40 ;
void * V_194 ;
V_40 = F_45 ( V_191 ) ;
F_40 ( ( L_72 , V_191 , V_40 ) ) ;
if ( V_40 > F_151 ( V_2 , V_195 ) )
return - V_175 ;
V_194 = F_44 ( V_40 ) ;
if ( V_194 == NULL ) {
F_40 ( ( L_73 ) ) ;
return - V_175 ;
}
F_40 ( ( L_74 , V_194 ) ) ;
V_187 = F_152 ( V_196 , V_45 ) ;
if ( ! V_187 ) {
F_40 ( ( L_75 ) ) ;
goto V_197;
}
F_153 ( & V_187 -> V_198 ) ;
V_187 -> V_199 = V_121 ;
V_187 -> V_200 = F_154 ( V_126 ) ;
V_187 -> V_201 = V_202 | V_203 | V_204 | V_205 ;
V_187 -> V_206 = V_190 ;
V_27 -> V_164 = V_194 ;
V_27 -> V_157 = V_40 ;
F_155 ( & V_2 -> V_121 -> V_207 ) ;
V_187 -> V_208 = F_156 ( NULL , 0 , V_40 , 0 , V_209 | V_210 ) ;
if ( F_157 ( V_187 -> V_208 ) ) {
F_40 ( ( L_76 , V_40 ) ) ;
F_158 ( & V_2 -> V_121 -> V_207 ) ;
goto error;
}
V_187 -> V_211 = V_187 -> V_208 + V_40 ;
V_187 -> V_212 = V_187 -> V_208 >> V_189 ;
F_40 ( ( L_77 , V_40 , V_27 -> V_164 , V_187 -> V_208 ) ) ;
if ( F_147 ( V_187 , ( unsigned long ) V_194 , V_187 -> V_208 , V_40 ) ) {
F_40 ( ( L_78 ) ) ;
F_158 ( & V_2 -> V_121 -> V_207 ) ;
goto error;
}
F_159 ( V_121 , V_187 ) ;
F_160 ( V_187 -> V_199 , V_187 -> V_201 , F_161 ( V_187 ) ) ;
F_158 ( & V_2 -> V_121 -> V_207 ) ;
V_27 -> V_156 = ( void * ) V_187 -> V_208 ;
* ( unsigned long * ) V_192 = V_187 -> V_208 ;
return 0 ;
error:
F_162 ( V_196 , V_187 ) ;
V_197:
F_47 ( V_194 , V_40 ) ;
return - V_175 ;
}
static int
F_163 ( struct V_1 * V_2 )
{
const struct V_213 * V_214 ;
T_13 V_215 = F_164 () ;
T_14 V_216 = F_165 () ;
int V_88 ;
F_166 () ;
V_214 = F_167 ( V_2 ) ;
F_40 ( ( L_79 ,
F_168 ( & V_217 , V_215 ) ,
F_169 ( & V_217 , V_216 ) ,
F_168 ( & V_217 , V_214 -> V_218 ) ,
F_168 ( & V_217 , V_214 -> V_219 ) ,
F_168 ( & V_217 , V_214 -> V_215 ) ,
F_169 ( & V_217 , V_214 -> V_220 ) ,
F_169 ( & V_217 , V_214 -> V_221 ) ) ) ;
V_88 = ( ( ! F_170 ( V_215 , V_214 -> V_218 ) )
|| ( ! F_170 ( V_215 , V_214 -> V_219 ) )
|| ( ! F_170 ( V_215 , V_214 -> V_215 ) )
|| ( ! F_171 ( V_216 , V_214 -> V_220 ) )
|| ( ! F_171 ( V_216 , V_214 -> V_221 ) )
|| ( ! F_171 ( V_216 , V_214 -> V_216 ) ) ) && ! F_172 ( V_222 ) ;
F_173 () ;
return V_88 ;
}
static int
F_174 ( struct V_1 * V_2 , T_15 * V_223 )
{
int V_44 ;
V_44 = V_223 -> V_44 ;
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
F_175 ( struct V_1 * V_2 , struct V_125 * V_126 , T_1 * V_27 , unsigned int V_44 ,
unsigned int V_90 , T_15 * V_91 )
{
T_4 * V_84 = NULL ;
unsigned long V_40 = 0UL ;
void * V_224 = NULL ;
void * V_225 = NULL ;
int V_88 = 0 ;
#define F_176 ( V_4 ) (pfm_buffer_fmt_t *)(a+1)
V_84 = F_80 ( V_91 -> V_226 ) ;
if ( V_84 == NULL ) {
F_40 ( ( L_81 , F_60 ( V_2 ) ) ) ;
return - V_106 ;
}
if ( V_84 -> V_227 ) V_225 = F_176 ( V_91 ) ;
V_88 = F_73 ( V_84 , V_2 , V_44 , V_90 , V_225 ) ;
F_40 ( ( L_82 , F_60 ( V_2 ) , V_44 , V_90 , V_225 , V_88 ) ) ;
if ( V_88 ) goto error;
V_27 -> V_166 = V_84 ;
V_27 -> V_165 = 1 ;
V_88 = F_72 ( V_84 , V_2 , V_44 , V_90 , V_225 , & V_40 ) ;
if ( V_88 ) goto error;
if ( V_40 ) {
V_88 = F_150 ( V_3 , V_126 , V_27 , V_40 , & V_224 ) ;
if ( V_88 ) goto error;
V_91 -> V_156 = V_224 ;
}
V_88 = F_74 ( V_84 , V_2 , V_27 -> V_164 , V_44 , V_90 , V_225 ) ;
error:
return V_88 ;
}
static void
F_177 ( T_1 * V_27 )
{
int V_24 ;
for ( V_24 = 1 ; F_178 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_179 ( V_24 ) == 0 ) continue;
V_27 -> V_72 [ V_24 ] = F_180 ( V_24 ) ;
F_40 ( ( L_12 , V_24 , V_27 -> V_72 [ V_24 ] ) ) ;
}
V_27 -> V_81 [ 0 ] = V_29 -> V_228 [ 0 ] & ~ 0x1 ;
V_27 -> V_79 [ 0 ] = V_29 -> V_229 [ 0 ] ;
F_40 ( ( L_83 , V_27 -> V_140 , V_27 -> V_81 [ 0 ] , V_27 -> V_79 [ 0 ] ) ) ;
V_27 -> V_230 [ 0 ] = 0UL ;
V_27 -> V_231 [ 0 ] = 0UL ;
}
static int
F_181 ( void * V_91 , T_9 * V_232 )
{
T_15 * V_233 = ( T_15 * ) V_91 ;
T_4 * V_84 ;
* V_232 = 0 ;
if ( ! F_70 ( V_233 -> V_226 , V_234 ) ) return 0 ;
V_84 = F_80 ( V_233 -> V_226 ) ;
if ( V_84 == NULL ) {
F_40 ( ( L_84 ) ) ;
return - V_106 ;
}
* V_232 = V_84 -> V_227 ;
F_40 ( ( L_85 , * V_232 ) ) ;
return 0 ;
}
static int
F_182 ( T_1 * V_27 , struct V_1 * V_2 )
{
if ( V_2 -> V_121 == NULL ) {
F_40 ( ( L_86 , F_60 ( V_2 ) ) ) ;
return - V_235 ;
}
if ( F_163 ( V_2 ) ) {
F_40 ( ( L_87 , F_60 ( V_2 ) ) ) ;
return - V_235 ;
}
if ( F_131 ( V_27 ) == 0 && V_2 == V_3 ) {
F_40 ( ( L_88 , F_60 ( V_2 ) ) ) ;
return - V_106 ;
}
if ( V_2 -> V_236 == V_237 ) {
F_40 ( ( L_89 , F_60 ( V_2 ) ) ) ;
return - V_108 ;
}
if ( V_2 == V_3 ) return 0 ;
if ( ! F_183 ( V_2 ) ) {
F_40 ( ( L_90 , F_60 ( V_2 ) , V_2 -> V_155 ) ) ;
return - V_108 ;
}
F_184 ( V_2 , 0 ) ;
return 0 ;
}
static int
F_185 ( T_1 * V_27 , T_16 V_238 , struct V_1 * * V_2 )
{
struct V_1 * V_239 = V_3 ;
int V_88 ;
if ( V_238 < 2 ) return - V_235 ;
if ( V_238 != F_186 ( V_3 ) ) {
F_187 ( & V_240 ) ;
V_239 = F_188 ( V_238 ) ;
if ( V_239 ) F_189 ( V_239 ) ;
F_190 ( & V_240 ) ;
if ( V_239 == NULL ) return - V_241 ;
}
V_88 = F_182 ( V_27 , V_239 ) ;
if ( V_88 == 0 ) {
* V_2 = V_239 ;
} else if ( V_239 != V_3 ) {
F_1 ( V_239 ) ;
}
return V_88 ;
}
static int
F_191 ( T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 )
{
T_15 * V_233 = ( T_15 * ) V_91 ;
struct V_125 * V_126 ;
struct V_170 V_170 ;
int V_44 ;
int V_144 ;
int V_88 ;
V_88 = F_174 ( V_3 , V_233 ) ;
if ( V_88 < 0 )
return V_88 ;
V_44 = V_233 -> V_44 ;
V_88 = - V_175 ;
V_144 = F_192 ( 0 ) ;
if ( V_144 < 0 )
return V_144 ;
V_27 = F_49 ( V_44 ) ;
if ( ! V_27 )
goto error;
V_126 = F_136 ( V_27 ) ;
if ( F_98 ( V_126 ) ) {
V_88 = F_97 ( V_126 ) ;
goto V_243;
}
V_233 -> V_140 = V_27 -> V_140 = V_144 ;
if ( F_70 ( V_233 -> V_226 , V_234 ) ) {
V_88 = F_175 ( V_3 , V_126 , V_27 , V_44 , 0 , V_233 ) ;
if ( V_88 )
goto V_244;
}
F_40 ( ( L_91 ,
V_27 ,
V_44 ,
V_27 -> V_50 ,
V_27 -> V_48 ,
V_27 -> V_245 ,
V_27 -> V_52 ,
V_27 -> V_140 ) ) ;
F_177 ( V_27 ) ;
F_193 ( V_144 , V_126 ) ;
return 0 ;
V_244:
V_170 = V_126 -> V_246 ;
F_194 ( V_126 ) ;
F_146 ( & V_170 ) ;
if ( V_27 -> V_166 ) {
F_71 ( V_27 -> V_166 , V_3 , NULL , V_87 ) ;
}
V_243:
F_55 ( V_27 ) ;
error:
F_195 ( V_144 ) ;
return V_88 ;
}
static inline unsigned long
F_196 ( T_17 * V_247 , int V_248 )
{
unsigned long V_20 = V_248 ? V_247 -> V_249 : V_247 -> V_250 ;
unsigned long V_251 , V_252 = V_247 -> V_253 , V_59 = V_247 -> V_59 ;
extern unsigned long V_254 ( unsigned long V_253 ) ;
if ( V_247 -> V_11 & V_255 ) {
V_251 = V_254 ( V_252 ) ;
V_20 -= ( V_252 & V_59 ) ;
if ( ( V_59 >> 32 ) != 0 )
V_251 |= V_254 ( V_252 >> 32 ) << 32 ;
V_247 -> V_253 = V_251 ;
}
V_247 -> V_256 = V_20 ;
return V_20 ;
}
static void
F_197 ( T_1 * V_27 , unsigned long * V_257 , int V_248 )
{
unsigned long V_59 = V_257 [ 0 ] ;
unsigned long V_258 = 0UL ;
unsigned long V_20 ;
int V_24 ;
V_59 >>= V_63 ;
for( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1UL ) == 0UL ) continue;
V_27 -> V_28 [ V_24 ] . V_20 = V_20 = F_196 ( V_27 -> V_28 + V_24 , V_248 ) ;
V_258 |= V_27 -> V_28 [ V_24 ] . V_259 [ 0 ] ;
F_59 ( ( L_92 , V_248 ? L_93 : L_94 , V_24 , V_20 ) ) ;
}
for( V_24 = 0 ; V_258 ; V_24 ++ , V_258 >>= 1 ) {
if ( ( V_258 & 0x1 ) == 0 ) continue;
V_27 -> V_28 [ V_24 ] . V_20 = V_20 = F_196 ( V_27 -> V_28 + V_24 , V_248 ) ;
F_59 ( ( L_95 ,
V_248 ? L_93 : L_94 , V_24 , V_20 ) ) ;
}
}
static void
F_198 ( T_1 * V_27 , unsigned long * V_257 , int V_248 )
{
unsigned long V_59 = V_257 [ 0 ] ;
unsigned long V_258 = 0UL ;
unsigned long V_20 ;
int V_24 ;
F_59 ( ( L_96 , V_257 [ 0 ] , V_248 ) ) ;
if ( V_27 -> V_46 == V_68 ) {
F_197 ( V_27 , V_257 , V_248 ) ;
return;
}
V_59 >>= V_63 ;
for( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1UL ) == 0UL ) continue;
V_20 = F_196 ( V_27 -> V_28 + V_24 , V_248 ) ;
V_258 |= V_27 -> V_28 [ V_24 ] . V_259 [ 0 ] ;
F_59 ( ( L_92 , V_248 ? L_93 : L_94 , V_24 , V_20 ) ) ;
F_37 ( V_27 , V_24 , V_20 ) ;
}
for( V_24 = 0 ; V_258 ; V_24 ++ , V_258 >>= 1 ) {
if ( ( V_258 & 0x1 ) == 0 ) continue;
V_20 = F_196 ( V_27 -> V_28 + V_24 , V_248 ) ;
if ( F_61 ( V_24 ) ) {
F_37 ( V_27 , V_24 , V_20 ) ;
} else {
F_38 ( V_24 , V_20 ) ;
}
F_59 ( ( L_95 ,
V_248 ? L_93 : L_94 , V_24 , V_20 ) ) ;
}
F_27 () ;
}
static int
F_199 ( T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_18 * V_233 = ( T_18 * ) V_91 ;
unsigned long V_260 , V_261 ;
unsigned long V_262 , V_259 , V_229 ;
unsigned int V_263 , V_264 , V_11 , V_265 ;
int V_24 , V_266 = 0 , V_267 , V_66 , V_268 ;
int V_269 , V_270 , V_155 ;
int V_88 = - V_106 ;
T_19 V_271 ;
#define F_200 ( V_5 , T_20 , T_21 ) ((x)->ctx_fl_system ^ PMC_PM(y, z))
V_155 = V_27 -> V_46 ;
V_267 = V_155 == V_272 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_2 = V_27 -> V_151 ;
V_229 = V_29 -> V_229 [ 0 ] ;
if ( V_155 == V_163 ) return - V_106 ;
if ( V_267 ) {
if ( V_66 && V_27 -> V_150 != F_87 () ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_266 = F_120 () == V_2 || V_66 ? 1 : 0 ;
}
V_268 = V_273 . V_268 ;
for ( V_24 = 0 ; V_24 < V_242 ; V_24 ++ , V_233 ++ ) {
V_263 = V_233 -> V_274 ;
V_264 = V_233 -> V_264 ;
V_260 = V_233 -> V_275 ;
V_262 = V_233 -> V_276 [ 0 ] ;
V_259 = V_233 -> V_277 [ 0 ] ;
V_11 = 0 ;
if ( V_263 >= V_278 ) {
F_40 ( ( L_97 , V_263 ) ) ;
goto error;
}
V_265 = V_29 -> V_279 [ V_263 ] . type ;
V_261 = ( V_260 >> V_29 -> V_279 [ V_263 ] . V_280 ) & 0x1 ;
V_270 = ( V_265 & V_281 ) == V_281 ? 1 : 0 ;
V_269 = ( V_265 & V_282 ) == V_282 ? 1 : 0 ;
if ( ( V_265 & V_283 ) == 0 || ( V_265 & V_284 ) == V_284 ) {
F_40 ( ( L_98 , V_263 , V_265 ) ) ;
goto error;
}
V_271 = V_29 -> V_279 [ V_263 ] . V_285 ;
if ( V_269 && V_260 != F_180 ( V_263 ) && V_66 ^ V_261 ) {
F_40 ( ( L_99 ,
V_263 ,
V_261 ,
V_66 ) ) ;
goto error;
}
if ( V_270 ) {
V_260 |= 1 << V_286 ;
if ( V_264 & V_287 ) {
V_11 |= V_287 ;
}
if ( V_264 & V_255 ) V_11 |= V_255 ;
if ( ( V_262 & V_229 ) != V_262 ) {
F_40 ( ( L_100 , V_262 , V_263 ) ) ;
goto error;
}
if ( ( V_259 & V_229 ) != V_259 ) {
F_40 ( ( L_101 , V_259 , V_263 ) ) ;
goto error;
}
} else {
if ( V_264 & ( V_287 | V_255 ) ) {
F_40 ( ( L_102 , V_263 ) ) ;
goto error;
}
}
if ( F_201 ( V_268 == 0 && V_271 ) ) {
V_88 = (* V_271)( V_2 , V_27 , V_263 , & V_260 , V_87 ) ;
if ( V_88 ) goto error;
V_88 = - V_106 ;
}
F_202 ( V_233 -> V_264 , 0 ) ;
if ( V_270 ) {
V_27 -> V_28 [ V_263 ] . V_11 = V_11 ;
V_27 -> V_28 [ V_263 ] . V_259 [ 0 ] = V_259 ;
V_27 -> V_28 [ V_263 ] . V_262 [ 0 ] = V_262 ;
V_27 -> V_28 [ V_263 ] . V_288 = V_233 -> V_289 ;
F_203 ( V_27 , V_259 ) ;
F_203 ( V_27 , V_262 ) ;
if ( V_155 == V_68 ) V_27 -> V_290 [ 0 ] &= ~ 1UL << V_263 ;
}
F_203 ( V_27 , V_29 -> V_279 [ V_263 ] . V_291 [ 0 ] ) ;
if ( V_269 ) F_204 ( V_27 , 1UL << V_263 ) ;
V_27 -> V_72 [ V_263 ] = V_260 ;
if ( V_267 ) {
if ( V_66 == 0 ) V_27 -> V_64 [ V_263 ] = V_260 ;
if ( V_266 ) {
F_26 ( V_263 , V_260 ) ;
}
#ifdef F_129
else {
V_27 -> V_292 [ 0 ] |= 1UL << V_263 ;
}
#endif
}
F_40 ( ( L_103 ,
V_263 ,
V_260 ,
V_267 ,
V_266 ,
V_11 ,
V_27 -> V_81 [ 0 ] ,
V_27 -> V_61 [ 0 ] ,
V_27 -> V_28 [ V_263 ] . V_288 ,
V_262 ,
V_259 ,
V_27 -> V_292 [ 0 ] ,
V_27 -> V_62 [ 0 ] ,
V_27 -> V_290 [ 0 ] ) ) ;
}
if ( V_266 ) F_27 () ;
return 0 ;
error:
F_202 ( V_233 -> V_264 , V_293 ) ;
return V_88 ;
}
static int
F_205 ( T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_18 * V_233 = ( T_18 * ) V_91 ;
unsigned long V_260 , V_294 , V_60 ;
unsigned int V_263 ;
int V_24 , V_266 = 0 , V_155 ;
int V_270 , V_267 , V_66 , V_268 ;
int V_88 = - V_106 ;
T_19 V_271 ;
V_155 = V_27 -> V_46 ;
V_267 = V_155 == V_272 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_60 = V_29 -> V_30 ;
V_2 = V_27 -> V_151 ;
if ( F_206 ( V_155 == V_163 ) ) return - V_106 ;
if ( F_201 ( V_267 ) ) {
if ( F_206 ( V_66 && V_27 -> V_150 != F_87 () ) ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_266 = F_120 () == V_2 || V_66 ? 1 : 0 ;
}
V_268 = V_273 . V_268 ;
for ( V_24 = 0 ; V_24 < V_242 ; V_24 ++ , V_233 ++ ) {
V_263 = V_233 -> V_274 ;
V_260 = V_233 -> V_275 ;
if ( ! F_207 ( V_263 ) ) {
F_40 ( ( L_104 , V_263 ) ) ;
goto V_295;
}
V_270 = F_61 ( V_263 ) ;
V_271 = V_29 -> V_296 [ V_263 ] . V_285 ;
if ( F_206 ( V_268 == 0 && V_271 ) ) {
unsigned long V_297 = V_260 ;
V_88 = (* V_271)( V_2 , V_27 , V_263 , & V_297 , V_87 ) ;
if ( V_88 ) goto V_295;
V_260 = V_297 ;
V_88 = - V_106 ;
}
F_202 ( V_233 -> V_264 , 0 ) ;
V_294 = V_260 ;
if ( V_270 ) {
V_27 -> V_28 [ V_263 ] . V_256 = V_260 ;
if ( V_267 ) {
V_294 = V_260 & V_60 ;
V_260 = V_260 & ~ V_60 ;
}
}
V_27 -> V_28 [ V_263 ] . V_249 = V_233 -> V_298 ;
V_27 -> V_28 [ V_263 ] . V_250 = V_233 -> V_299 ;
V_27 -> V_28 [ V_263 ] . V_253 = V_233 -> V_300 ;
V_27 -> V_28 [ V_263 ] . V_59 = V_233 -> V_301 ;
V_27 -> V_28 [ V_263 ] . V_20 = V_260 ;
F_203 ( V_27 , F_208 ( V_263 ) ) ;
F_203 ( V_27 , F_209 ( V_263 ) ) ;
if ( V_270 && V_155 == V_68 ) {
V_27 -> V_290 [ 0 ] &= ~ 1UL << V_263 ;
}
if ( V_267 ) {
if ( V_66 == 0 ) V_27 -> V_80 [ V_263 ] = V_294 ;
if ( V_266 ) {
F_38 ( V_263 , V_294 ) ;
} else {
#ifdef F_129
V_27 -> V_302 [ 0 ] |= 1UL << V_263 ;
#endif
}
}
F_40 ( ( L_105
L_106 ,
V_263 ,
V_260 ,
V_267 ,
V_266 ,
V_294 ,
V_27 -> V_28 [ V_263 ] . V_20 ,
V_27 -> V_28 [ V_263 ] . V_250 ,
V_27 -> V_28 [ V_263 ] . V_249 ,
F_210 ( V_27 , V_263 ) ? 'Y' : 'N' ,
V_27 -> V_28 [ V_263 ] . V_253 ,
V_27 -> V_28 [ V_263 ] . V_59 ,
V_27 -> V_61 [ 0 ] ,
V_27 -> V_28 [ V_263 ] . V_259 [ 0 ] ,
V_27 -> V_302 [ 0 ] ,
V_27 -> V_79 [ 0 ] ,
V_27 -> V_290 [ 0 ] ) ) ;
}
if ( V_266 ) F_27 () ;
return 0 ;
V_295:
F_202 ( V_233 -> V_264 , V_293 ) ;
return V_88 ;
}
static int
F_211 ( T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
unsigned long V_20 = 0UL , V_256 , V_60 , V_303 ;
T_18 * V_233 = ( T_18 * ) V_91 ;
unsigned int V_263 , V_264 = 0 ;
int V_24 , V_266 = 0 , V_155 ;
int V_267 , V_66 , V_270 , V_268 ;
int V_88 = - V_106 ;
T_19 V_304 ;
V_155 = V_27 -> V_46 ;
V_267 = V_155 == V_272 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_60 = V_29 -> V_30 ;
V_2 = V_27 -> V_151 ;
if ( V_155 == V_163 ) return - V_106 ;
if ( F_201 ( V_267 ) ) {
if ( F_206 ( V_66 && V_27 -> V_150 != F_87 () ) ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_266 = F_120 () == V_2 || V_66 ? 1 : 0 ;
if ( V_266 ) F_27 () ;
}
V_268 = V_273 . V_268 ;
F_40 ( ( L_107 ,
V_267 ,
V_266 ,
V_155 ) ) ;
for ( V_24 = 0 ; V_24 < V_242 ; V_24 ++ , V_233 ++ ) {
V_263 = V_233 -> V_274 ;
V_264 = V_233 -> V_264 ;
if ( F_206 ( ! F_207 ( V_263 ) ) ) goto error;
if ( F_206 ( ! F_212 ( V_27 , V_263 ) ) ) goto error;
V_303 = V_27 -> V_28 [ V_263 ] . V_20 ;
V_256 = V_27 -> V_28 [ V_263 ] . V_256 ;
V_270 = F_61 ( V_263 ) ;
if ( V_266 ) {
V_20 = F_36 ( V_263 ) ;
} else {
V_20 = V_267 ? V_27 -> V_80 [ V_263 ] : 0UL ;
}
V_304 = V_29 -> V_296 [ V_263 ] . V_305 ;
if ( V_270 ) {
V_20 &= V_60 ;
V_20 += V_303 ;
}
if ( F_206 ( V_268 == 0 && V_304 ) ) {
unsigned long V_297 = V_20 ;
V_88 = (* V_304)( V_27 -> V_151 , V_27 , V_263 , & V_297 , V_87 ) ;
if ( V_88 ) goto error;
V_20 = V_297 ;
V_88 = - V_106 ;
}
F_202 ( V_264 , 0 ) ;
F_40 ( ( L_108 , V_263 , V_20 ) ) ;
V_233 -> V_275 = V_20 ;
V_233 -> V_264 = V_264 ;
V_233 -> V_306 = V_256 ;
}
return 0 ;
error:
F_202 ( V_233 -> V_264 , V_293 ) ;
return V_88 ;
}
int
F_213 ( struct V_1 * V_2 , void * V_233 , unsigned int V_307 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_233 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_199 ( V_27 , V_233 , V_307 , V_87 ) ;
}
int
F_214 ( struct V_1 * V_2 , void * V_233 , unsigned int V_307 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_233 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_211 ( V_27 , V_233 , V_307 , V_87 ) ;
}
int
F_215 ( struct V_1 * V_2 )
{
T_1 * V_27 = V_2 -> V_308 . V_309 ;
unsigned long V_11 ;
int V_88 = 0 ;
if ( V_29 -> V_310 == 0 ) return 0 ;
F_40 ( ( L_109 , F_60 ( V_2 ) ) ) ;
if ( V_2 -> V_308 . V_11 & V_311 ) return 0 ;
if ( V_27 && V_27 -> V_73 == 1 ) return - 1 ;
F_86 ( V_11 ) ;
if ( V_113 . V_116 > 0 )
V_88 = - 1 ;
else
V_113 . V_312 ++ ;
F_40 ( ( L_110 ,
V_113 . V_312 ,
V_113 . V_116 ,
F_60 ( V_2 ) , V_88 ) ) ;
F_89 ( V_11 ) ;
return V_88 ;
}
int
F_216 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
int V_88 ;
if ( V_29 -> V_310 == 0 ) return 0 ;
F_86 ( V_11 ) ;
if ( V_113 . V_312 == 0 ) {
F_63 ( V_67 L_111 , F_60 ( V_2 ) ) ;
V_88 = - 1 ;
} else {
V_113 . V_312 -- ;
V_88 = 0 ;
}
F_89 ( V_11 ) ;
return V_88 ;
}
static int
F_217 ( T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_4 * V_84 ;
T_5 V_313 ;
int V_155 , V_66 ;
int V_88 = 0 ;
V_155 = V_27 -> V_46 ;
V_84 = V_27 -> V_166 ;
V_66 = V_27 -> V_50 ;
V_2 = F_128 ( V_27 ) ;
switch( V_155 ) {
case V_68 :
break;
case V_272 :
if ( F_218 ( V_27 ) && V_84 -> V_97 ) break;
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
if ( F_206 ( V_2 == NULL ) ) {
F_63 ( V_67 L_114 , F_60 ( V_3 ) ) ;
return - V_106 ;
}
if ( V_2 == V_3 || V_66 ) {
V_84 = V_27 -> V_166 ;
F_40 ( ( L_115 ,
F_60 ( V_2 ) ,
V_27 -> V_290 [ 0 ] ) ) ;
if ( F_218 ( V_27 ) ) {
F_219 ( V_27 -> V_164 ) ;
V_313 . V_314 . V_315 = 0 ;
V_313 . V_314 . V_316 = 0 ;
if ( V_155 == V_272 )
V_88 = F_76 ( V_84 , V_2 , & V_313 , V_27 -> V_164 , V_87 ) ;
else
V_88 = F_75 ( V_84 , V_2 , & V_313 , V_27 -> V_164 , V_87 ) ;
} else {
V_313 . V_314 . V_315 = 0 ;
V_313 . V_314 . V_316 = 1 ;
}
if ( V_88 == 0 ) {
if ( V_313 . V_314 . V_316 )
F_198 ( V_27 , V_27 -> V_290 , V_317 ) ;
if ( V_313 . V_314 . V_315 == 0 ) {
F_40 ( ( L_116 , F_60 ( V_2 ) ) ) ;
if ( V_155 == V_68 ) F_62 ( V_2 ) ;
} else {
F_40 ( ( L_117 , F_60 ( V_2 ) ) ) ;
}
}
V_27 -> V_290 [ 0 ] = 0UL ;
V_27 -> V_46 = V_272 ;
V_27 -> V_318 = 0 ;
return 0 ;
}
if ( V_155 == V_68 ) {
if ( V_27 -> V_318 == 0 ) return - V_106 ;
V_27 -> V_318 = 0 ;
}
if ( F_131 ( V_27 ) == 0 && V_155 == V_68 ) {
F_40 ( ( L_118 , F_60 ( V_2 ) ) ) ;
F_132 ( & V_27 -> V_54 ) ;
} else {
F_40 ( ( L_119 , F_60 ( V_2 ) ) ) ;
V_27 -> V_319 = V_320 ;
F_220 ( V_2 , 1 ) ;
F_221 ( V_2 ) ;
}
return 0 ;
}
static int
F_222 ( T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 )
{
unsigned int V_321 = * ( unsigned int * ) V_91 ;
V_273 . V_322 = V_321 == 0 ? 0 : 1 ;
F_63 ( V_111 L_120 , V_273 . V_322 ? L_121 : L_122 ) ;
if ( V_321 == 0 ) {
memset ( V_323 , 0 , sizeof( V_323 ) ) ;
for( V_321 = 0 ; V_321 < V_324 ; V_321 ++ ) V_323 [ V_321 ] . V_325 = ~ 0UL ;
}
return 0 ;
}
static int
F_223 ( int V_326 , T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 )
{
struct V_327 * V_308 = NULL ;
struct V_1 * V_2 ;
T_22 * V_233 = ( T_22 * ) V_91 ;
unsigned long V_11 ;
T_23 V_328 ;
unsigned int V_329 ;
int V_330 ;
int V_88 = 0 , V_155 ;
int V_24 , V_266 = 0 ;
int V_66 , V_267 ;
if ( V_29 -> V_310 == 0 ) return - V_106 ;
V_155 = V_27 -> V_46 ;
V_267 = V_155 == V_272 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_2 = V_27 -> V_151 ;
if ( V_155 == V_163 ) return - V_106 ;
if ( V_267 ) {
V_308 = & V_2 -> V_308 ;
if ( F_206 ( V_66 && V_27 -> V_150 != F_87 () ) ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_266 = F_120 () == V_2 || V_66 ? 1 : 0 ;
}
V_330 = V_27 -> V_73 == 0 ;
if ( V_267 && ( V_308 -> V_11 & V_311 ) != 0 ) {
F_40 ( ( L_123 , F_60 ( V_2 ) ) ) ;
return - V_108 ;
}
if ( V_267 ) {
F_86 ( V_11 ) ;
if ( V_330 && V_66 ) {
if ( V_113 . V_312 )
V_88 = - V_108 ;
else
V_113 . V_116 ++ ;
}
F_89 ( V_11 ) ;
}
if ( V_88 != 0 ) return V_88 ;
V_27 -> V_73 = 1 ;
if ( V_330 && V_266 ) {
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
for ( V_24 = 0 ; V_24 < V_242 ; V_24 ++ , V_233 ++ ) {
V_329 = V_233 -> V_331 ;
V_328 . V_20 = V_233 -> V_332 ;
V_88 = - V_106 ;
if ( ( V_326 == V_333 && V_329 >= V_334 ) || ( ( V_326 == V_335 ) && V_329 >= V_336 ) ) {
F_40 ( ( L_125 ,
V_329 , V_328 . V_20 , V_326 , V_24 , V_242 ) ) ;
goto V_295;
}
if ( V_329 & 0x1 ) {
if ( V_326 == V_333 )
V_328 . V_337 . V_338 = 0 ;
else
V_328 . V_339 . V_340 = V_328 . V_339 . V_341 = 0 ;
}
F_202 ( V_233 -> V_342 , 0 ) ;
if ( V_326 == V_333 ) {
F_224 ( V_27 , V_329 ) ;
if ( V_266 ) {
F_30 ( V_329 , V_328 . V_20 ) ;
F_31 () ;
}
V_27 -> V_74 [ V_329 ] = V_328 . V_20 ;
F_40 ( ( L_126 ,
V_329 , V_328 . V_20 , V_27 -> V_230 [ 0 ] , V_267 , V_266 ) ) ;
} else {
F_225 ( V_27 , V_329 ) ;
if ( V_266 ) {
F_33 ( V_329 , V_328 . V_20 ) ;
F_34 () ;
}
V_27 -> V_76 [ V_329 ] = V_328 . V_20 ;
F_40 ( ( L_127 ,
V_329 , V_328 . V_20 , V_27 -> V_231 [ 0 ] , V_267 , V_266 ) ) ;
}
}
return 0 ;
V_295:
if ( V_330 ) {
F_86 ( V_11 ) ;
if ( V_27 -> V_50 ) {
V_113 . V_116 -- ;
}
F_89 ( V_11 ) ;
V_27 -> V_73 = 0 ;
}
F_202 ( V_233 -> V_342 , V_293 ) ;
return V_88 ;
}
static int
F_226 ( T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 )
{
return F_223 ( V_333 , V_27 , V_91 , V_242 , V_87 ) ;
}
static int
F_227 ( T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 )
{
return F_223 ( V_335 , V_27 , V_91 , V_242 , V_87 ) ;
}
int
F_228 ( struct V_1 * V_2 , void * V_233 , unsigned int V_307 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_233 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_226 ( V_27 , V_233 , V_307 , V_87 ) ;
}
int
F_229 ( struct V_1 * V_2 , void * V_233 , unsigned int V_307 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_233 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_227 ( V_27 , V_233 , V_307 , V_87 ) ;
}
static int
F_230 ( T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 )
{
T_24 * V_233 = ( T_24 * ) V_91 ;
V_233 -> V_343 = V_344 ;
return 0 ;
}
static int
F_231 ( T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 )
{
struct V_86 * V_345 ;
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
F_232 ( V_69 ) ;
F_14 () ;
F_233 ( V_87 ) -> V_346 = 0 ;
return 0 ;
}
if ( V_2 == V_3 ) {
F_19 () ;
F_233 ( V_87 ) -> V_347 = 0 ;
} else {
V_345 = F_119 ( V_2 ) ;
F_233 ( V_345 ) -> V_347 = 0 ;
V_27 -> V_348 = 0 ;
F_40 ( ( L_129 , F_60 ( V_2 ) ) ) ;
}
return 0 ;
}
static int
F_234 ( T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 )
{
struct V_86 * V_345 ;
int V_155 , V_66 ;
V_155 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_155 != V_272 ) return - V_106 ;
if ( V_66 && V_27 -> V_150 != F_87 () ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
if ( V_66 ) {
F_233 ( V_87 ) -> V_346 = 1 ;
F_235 ( V_69 ) ;
F_17 () ;
F_24 ( V_70 , F_22 ( V_70 ) | V_71 ) ;
F_16 () ;
return 0 ;
}
if ( V_27 -> V_151 == V_3 ) {
F_20 () ;
F_233 ( V_87 ) -> V_347 = 1 ;
} else {
V_345 = F_119 ( V_27 -> V_151 ) ;
V_27 -> V_348 = V_17 ;
F_233 ( V_345 ) -> V_347 = 1 ;
}
return 0 ;
}
static int
F_236 ( T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 )
{
T_18 * V_233 = ( T_18 * ) V_91 ;
unsigned int V_263 ;
int V_24 ;
int V_88 = - V_106 ;
for ( V_24 = 0 ; V_24 < V_242 ; V_24 ++ , V_233 ++ ) {
V_263 = V_233 -> V_274 ;
if ( ! F_179 ( V_263 ) ) goto V_295;
V_233 -> V_275 = F_180 ( V_263 ) ;
F_202 ( V_233 -> V_264 , 0 ) ;
F_40 ( ( L_130 , V_263 , V_233 -> V_275 ) ) ;
}
return 0 ;
V_295:
F_202 ( V_233 -> V_264 , V_293 ) ;
return V_88 ;
}
static int
F_237 ( T_1 * V_27 )
{
struct V_1 * V_349 , * V_350 ;
int V_88 = - V_241 ;
F_187 ( & V_240 ) ;
F_238 (g, t) {
if ( V_350 -> V_308 . V_309 == V_27 ) {
V_88 = 0 ;
goto V_109;
}
} F_239 ( V_349 , V_350 ) ;
V_109:
F_190 ( & V_240 ) ;
F_40 ( ( L_131 , V_88 , V_27 ) ) ;
return V_88 ;
}
static int
F_240 ( T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
struct V_327 * V_308 ;
struct T_1 * V_351 ;
unsigned long V_11 ;
#ifndef F_129
struct V_1 * V_352 = NULL ;
#endif
T_25 * V_233 = ( T_25 * ) V_91 ;
unsigned long * V_353 , * V_354 ;
int V_355 ;
int V_88 = 0 ;
int V_155 , V_66 , V_356 = 0 ;
V_155 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_155 != V_47 ) {
F_40 ( ( L_132 ,
V_233 -> V_357 ,
V_27 -> V_46 ) ) ;
return - V_108 ;
}
F_40 ( ( L_133 , V_233 -> V_357 , V_27 -> V_73 ) ) ;
if ( F_131 ( V_27 ) == 0 && V_233 -> V_357 == V_3 -> V_238 ) {
F_40 ( ( L_134 ) ) ;
return - V_106 ;
}
V_88 = F_185 ( V_27 , V_233 -> V_357 , & V_2 ) ;
if ( V_88 ) {
F_40 ( ( L_135 , V_233 -> V_357 , V_88 ) ) ;
return V_88 ;
}
V_88 = - V_106 ;
if ( V_66 && V_2 != V_3 ) {
F_40 ( ( L_136 ,
V_233 -> V_357 ) ) ;
goto error;
}
V_308 = & V_2 -> V_308 ;
V_88 = 0 ;
if ( V_27 -> V_73 ) {
if ( V_308 -> V_11 & V_311 ) {
V_88 = - V_108 ;
F_40 ( ( L_137 , V_233 -> V_357 ) ) ;
goto error;
}
F_86 ( V_11 ) ;
if ( V_66 ) {
if ( V_113 . V_312 ) {
F_40 ( ( L_138 ,
F_60 ( V_2 ) ) ) ;
V_88 = - V_108 ;
} else {
V_113 . V_116 ++ ;
F_40 ( ( L_139 , F_60 ( V_2 ) , V_113 . V_116 ) ) ;
V_356 = 1 ;
}
}
F_89 ( V_11 ) ;
if ( V_88 ) goto error;
}
V_355 = V_27 -> V_150 = F_87 () ;
V_88 = - V_108 ;
V_88 = F_85 ( V_3 , V_66 , V_355 ) ;
if ( V_88 ) goto error;
F_40 ( ( L_140 ,
V_308 -> V_309 , V_27 ) ) ;
V_88 = - V_108 ;
V_351 = F_241 ( V_358 , & V_308 -> V_309 , NULL , V_27 , sizeof( T_1 * ) ) ;
if ( V_351 != NULL ) {
F_40 ( ( L_141 , V_233 -> V_357 ) ) ;
goto V_359;
}
F_43 ( V_27 ) ;
V_27 -> V_46 = V_272 ;
V_27 -> V_151 = V_2 ;
if ( V_66 ) {
F_235 ( V_360 ) ;
F_232 ( V_69 ) ;
if ( V_27 -> V_245 ) F_235 ( V_361 ) ;
} else {
V_308 -> V_11 |= V_362 ;
}
F_67 ( V_2 , V_27 ) ;
F_68 ( V_2 , V_27 ) ;
V_353 = V_27 -> V_64 ;
V_354 = V_27 -> V_80 ;
if ( V_2 == V_3 ) {
if ( V_66 == 0 ) {
F_233 ( V_87 ) -> V_363 = 0 ;
F_40 ( ( L_142 , F_60 ( V_2 ) ) ) ;
F_53 ( V_27 , F_87 () ) ;
F_242 () ;
F_243 ( V_27 ) ;
#ifndef F_129
V_352 = F_120 () ;
if ( V_352 ) F_244 ( V_352 ) ;
#endif
}
F_66 ( V_354 , V_27 -> V_79 [ 0 ] ) ;
F_69 ( V_353 , V_27 -> V_81 [ 0 ] ) ;
V_27 -> V_292 [ 0 ] = 0UL ;
V_27 -> V_302 [ 0 ] = 0UL ;
if ( V_27 -> V_73 ) {
F_29 ( V_27 -> V_74 , V_29 -> V_75 ) ;
F_32 ( V_27 -> V_76 , V_29 -> V_77 ) ;
}
F_245 ( V_2 , V_27 ) ;
F_40 ( ( L_143 , F_60 ( V_2 ) ) ) ;
} else {
V_87 = F_119 ( V_2 ) ;
V_27 -> V_55 = V_56 ;
F_53 ( V_27 , - 1 ) ;
V_27 -> V_348 = 0UL ;
F_233 ( V_87 ) -> V_347 = F_233 ( V_87 ) -> V_346 = 0 ;
}
V_88 = 0 ;
V_359:
if ( V_88 ) F_90 ( V_27 , V_27 -> V_50 , V_355 ) ;
error:
if ( V_88 && V_356 ) {
F_86 ( V_11 ) ;
V_113 . V_116 -- ;
F_89 ( V_11 ) ;
}
if ( V_66 == 0 && V_2 != V_3 ) {
F_1 ( V_2 ) ;
if ( V_88 == 0 ) {
V_88 = F_237 ( V_27 ) ;
if ( V_88 ) {
V_27 -> V_46 = V_47 ;
V_27 -> V_151 = NULL ;
}
}
}
return V_88 ;
}
static int
F_123 ( T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 )
{
struct V_1 * V_2 = F_128 ( V_27 ) ;
struct V_86 * V_345 ;
int V_364 , V_66 ;
int V_88 ;
F_40 ( ( L_144 , V_27 -> V_46 , V_2 ? F_60 ( V_2 ) : - 1 ) ) ;
V_364 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_364 == V_47 ) {
F_40 ( ( L_145 , V_364 ) ) ;
return 0 ;
}
V_88 = F_231 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) return V_88 ;
V_27 -> V_46 = V_47 ;
if ( V_66 ) {
F_232 ( V_360 ) ;
F_232 ( V_361 ) ;
F_246 ( V_3 , V_27 ) ;
if ( V_364 != V_163 )
F_90 ( V_27 , 1 , V_27 -> V_150 ) ;
V_2 -> V_308 . V_309 = NULL ;
V_27 -> V_151 = NULL ;
return 0 ;
}
V_345 = V_2 == V_3 ? V_87 : F_119 ( V_2 ) ;
if ( V_2 == V_3 ) {
F_233 ( V_87 ) -> V_363 = 1 ;
F_40 ( ( L_146 , F_60 ( V_2 ) ) ) ;
}
F_246 ( V_2 , V_27 ) ;
if ( V_364 != V_163 )
F_90 ( V_27 , 0 , V_27 -> V_150 ) ;
V_27 -> V_55 = V_56 ;
F_53 ( V_27 , - 1 ) ;
V_2 -> V_308 . V_11 &= ~ V_362 ;
V_2 -> V_308 . V_309 = NULL ;
V_27 -> V_151 = NULL ;
F_220 ( V_2 , 0 ) ;
V_27 -> V_319 = V_365 ;
V_27 -> V_318 = 0 ;
V_27 -> V_162 = 0 ;
F_40 ( ( L_147 , F_60 ( V_2 ) ) ) ;
return 0 ;
}
void
F_247 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
unsigned long V_11 ;
struct V_86 * V_87 = F_119 ( V_2 ) ;
int V_88 , V_155 ;
int V_366 = 0 ;
V_27 = F_58 ( V_2 ) ;
F_103 ( V_27 , V_11 ) ;
F_40 ( ( L_148 , V_27 -> V_46 , F_60 ( V_2 ) ) ) ;
V_155 = V_27 -> V_46 ;
switch( V_155 ) {
case V_47 :
F_63 ( V_67 L_149 , F_60 ( V_2 ) ) ;
break;
case V_272 :
case V_68 :
V_88 = F_123 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) {
F_63 ( V_67 L_150 , F_60 ( V_2 ) , V_155 , V_88 ) ;
}
F_40 ( ( L_151 , V_155 ) ) ;
F_248 ( V_27 ) ;
break;
case V_163 :
V_88 = F_123 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) {
F_63 ( V_67 L_150 , F_60 ( V_2 ) , V_155 , V_88 ) ;
}
V_366 = 1 ;
break;
default:
F_63 ( V_67 L_152 , F_60 ( V_2 ) , V_155 ) ;
break;
}
F_106 ( V_27 , V_11 ) ;
{ T_26 V_65 = F_21 () ;
F_249 ( V_65 & ( V_17 | V_16 ) ) ;
F_249 ( F_120 () ) ;
F_249 ( F_233 ( V_87 ) -> V_347 ) ;
F_249 ( F_233 ( V_87 ) -> V_346 ) ;
}
if ( V_366 ) F_55 ( V_27 ) ;
}
static int
F_250 ( T_1 * V_27 , int V_143 , unsigned long V_11 )
{
struct V_1 * V_2 ;
int V_155 , V_367 ;
V_368:
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
V_2 -> V_155 , F_251 ( V_143 ) ) ) ;
if ( V_2 == V_3 || V_27 -> V_50 ) return 0 ;
switch( V_155 ) {
case V_47 :
return 0 ;
case V_163 :
F_40 ( ( L_155 , V_143 ) ) ;
return - V_106 ;
case V_68 :
if ( V_143 != V_369 ) return 0 ;
}
if ( F_251 ( V_143 ) ) {
if ( ! F_183 ( V_2 ) ) {
F_40 ( ( L_156 , F_60 ( V_2 ) ) ) ;
return - V_108 ;
}
V_367 = V_155 ;
F_106 ( V_27 , V_11 ) ;
F_184 ( V_2 , 0 ) ;
F_103 ( V_27 , V_11 ) ;
if ( V_27 -> V_46 != V_367 ) {
F_40 ( ( L_157 , V_367 , V_27 -> V_46 ) ) ;
goto V_368;
}
}
return 0 ;
}
T_27 long
F_252 ( int V_144 , int V_143 , void T_8 * V_91 , int V_242 )
{
struct V_144 V_7 = { NULL , 0 } ;
T_1 * V_27 = NULL ;
unsigned long V_11 = 0UL ;
void * V_370 = NULL ;
long V_88 ;
T_9 V_371 , V_232 , V_372 = 0 ;
int V_373 , V_374 = 0 , V_375 = 0 , V_376 ;
int (* F_253)( T_1 * V_27 , void * V_91 , int V_242 , struct V_86 * V_87 );
int (* F_254)( void * V_91 , T_9 * V_232 );
#define F_255 4096
if ( F_206 ( V_29 == NULL ) ) return - V_377 ;
if ( F_206 ( V_143 < 0 || V_143 >= V_378 ) ) {
F_40 ( ( L_158 , V_143 ) ) ;
return - V_106 ;
}
F_253 = V_379 [ V_143 ] . V_380 ;
V_373 = V_379 [ V_143 ] . V_381 ;
V_371 = V_379 [ V_143 ] . V_382 ;
F_254 = V_379 [ V_143 ] . V_383 ;
V_376 = V_379 [ V_143 ] . V_376 ;
if ( F_206 ( F_253 == NULL ) ) {
F_40 ( ( L_158 , V_143 ) ) ;
return - V_106 ;
}
F_40 ( ( L_159 ,
F_256 ( V_143 ) ,
V_143 ,
V_373 ,
V_371 ,
V_242 ) ) ;
if ( F_206 ( ( V_373 == V_384 && V_242 <= 0 ) || ( V_373 > 0 && V_373 != V_242 ) ) )
return - V_106 ;
V_385:
V_232 = V_372 + V_371 * V_242 ;
if ( F_206 ( V_232 > F_255 ) ) {
F_63 ( V_67 L_160 , F_60 ( V_3 ) , V_232 ) ;
return - V_386 ;
}
if ( F_201 ( V_242 && V_370 == NULL ) ) {
V_370 = F_257 ( F_255 , V_45 ) ;
if ( V_370 == NULL ) return - V_175 ;
}
V_88 = - V_138 ;
if ( V_232 && F_258 ( V_370 , V_91 , V_232 ) ) {
F_40 ( ( L_161 , V_232 , V_91 ) ) ;
goto V_387;
}
if ( V_374 == 0 && F_254 ) {
V_88 = (* F_254)( V_370 , & V_372 ) ;
if ( V_88 ) goto V_387;
V_374 = 1 ;
F_40 ( ( L_162 , V_232 , V_372 ) ) ;
if ( F_201 ( V_372 ) ) goto V_385;
}
if ( F_206 ( ( V_376 & V_388 ) == 0 ) ) goto V_389;
V_88 = - V_147 ;
V_7 = F_259 ( V_144 ) ;
if ( F_206 ( V_7 . V_125 == NULL ) ) {
F_40 ( ( L_163 , V_144 ) ) ;
goto V_387;
}
if ( F_206 ( F_102 ( V_7 . V_125 ) == 0 ) ) {
F_40 ( ( L_164 , V_144 ) ) ;
goto V_387;
}
V_27 = V_7 . V_125 -> V_129 ;
if ( F_206 ( V_27 == NULL ) ) {
F_40 ( ( L_165 , V_144 ) ) ;
goto V_387;
}
F_219 ( & V_27 -> V_46 ) ;
F_103 ( V_27 , V_11 ) ;
V_88 = F_250 ( V_27 , V_143 , V_11 ) ;
if ( F_206 ( V_88 ) ) goto V_136;
V_389:
V_88 = (* F_253)( V_27 , V_370 , V_242 , F_119 ( V_3 ) ) ;
V_375 = 1 ;
V_136:
if ( F_201 ( V_27 ) ) {
F_40 ( ( L_166 ) ) ;
F_106 ( V_27 , V_11 ) ;
}
if ( V_375 && F_260 ( V_143 ) && F_110 ( V_91 , V_370 , V_371 * V_242 ) ) V_88 = - V_138 ;
V_387:
if ( V_7 . V_125 )
F_261 ( V_7 ) ;
F_56 ( V_370 ) ;
F_40 ( ( L_167 , F_256 ( V_143 ) , V_88 ) ) ;
return V_88 ;
}
static void
F_262 ( T_1 * V_27 , unsigned long V_257 , struct V_86 * V_87 )
{
T_4 * V_84 = V_27 -> V_166 ;
T_5 V_313 ;
int V_155 ;
int V_88 = 0 ;
V_155 = V_27 -> V_46 ;
if ( F_218 ( V_27 ) ) {
V_313 . V_314 . V_315 = 0 ;
V_313 . V_314 . V_316 = 0 ;
if ( V_155 == V_272 )
V_88 = F_76 ( V_84 , V_3 , & V_313 , V_27 -> V_164 , V_87 ) ;
else
V_88 = F_75 ( V_84 , V_3 , & V_313 , V_27 -> V_164 , V_87 ) ;
} else {
V_313 . V_314 . V_315 = 0 ;
V_313 . V_314 . V_316 = 1 ;
}
if ( V_88 == 0 ) {
if ( V_313 . V_314 . V_316 ) {
F_198 ( V_27 , & V_257 , V_317 ) ;
}
if ( V_313 . V_314 . V_315 == 0 ) {
F_40 ( ( L_168 ) ) ;
if ( V_27 -> V_46 == V_68 ) F_62 ( V_3 ) ;
} else {
F_40 ( ( L_169 ) ) ;
}
V_27 -> V_46 = V_272 ;
}
}
static void
F_263 ( T_1 * V_27 , struct V_86 * V_87 )
{
int V_88 ;
F_40 ( ( L_170 , F_60 ( V_3 ) ) ) ;
V_88 = F_123 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) {
F_63 ( V_67 L_171 , F_60 ( V_3 ) , V_88 ) ;
}
F_264 ( & V_27 -> V_58 ) ;
}
void
F_265 ( void )
{
T_1 * V_27 ;
struct V_86 * V_87 ;
unsigned long V_11 , V_390 ;
unsigned long V_257 ;
unsigned int V_391 ;
int V_88 ;
V_27 = F_58 ( V_3 ) ;
if ( V_27 == NULL ) {
F_63 ( V_67 L_172 ,
F_60 ( V_3 ) ) ;
return;
}
F_103 ( V_27 , V_11 ) ;
F_220 ( V_3 , 0 ) ;
V_87 = F_119 ( V_3 ) ;
V_391 = V_27 -> V_319 ;
V_27 -> V_319 = V_365 ;
V_257 = V_27 -> V_290 [ 0 ] ;
F_40 ( ( L_173 , V_391 , V_27 -> V_46 ) ) ;
if ( V_27 -> V_162 || V_27 -> V_46 == V_163 )
goto V_392;
if ( V_391 == V_320 )
goto V_393;
F_106 ( V_27 , V_11 ) ;
F_266 () ;
F_40 ( ( L_174 ) ) ;
V_88 = F_267 ( & V_27 -> V_54 ) ;
F_40 ( ( L_175 , V_88 ) ) ;
F_103 ( V_27 , V_390 ) ;
V_257 = V_27 -> V_290 [ 0 ] ;
if ( V_27 -> V_162 ) {
V_392:
F_40 ( ( L_176 ) ) ;
F_263 ( V_27 , V_87 ) ;
goto V_394;
}
if ( V_88 < 0 )
goto V_394;
V_393:
F_262 ( V_27 , V_257 , V_87 ) ;
V_27 -> V_290 [ 0 ] = 0UL ;
V_394:
F_106 ( V_27 , V_11 ) ;
}
static int
F_268 ( T_1 * V_27 , T_2 * V_37 )
{
if ( V_27 -> V_46 == V_163 ) {
F_40 ( ( L_177 ) ) ;
return 0 ;
}
F_40 ( ( L_178 ) ) ;
if ( V_37 ) F_264 ( & V_27 -> V_57 ) ;
F_269 ( & V_27 -> V_146 , V_395 , V_396 ) ;
return 0 ;
}
static int
F_270 ( T_1 * V_27 , unsigned long V_397 )
{
T_2 * V_37 = NULL ;
if ( V_27 -> V_52 == 0 ) {
V_37 = F_39 ( V_27 ) ;
if ( V_37 == NULL ) {
F_63 ( V_67 L_179 ) ;
return - 1 ;
}
V_37 -> V_398 . V_39 = V_399 ;
V_37 -> V_398 . V_137 = V_27 -> V_140 ;
V_37 -> V_398 . V_400 = 0 ;
V_37 -> V_398 . V_401 [ 0 ] = V_397 ;
V_37 -> V_398 . V_401 [ 1 ] = 0UL ;
V_37 -> V_398 . V_401 [ 2 ] = 0UL ;
V_37 -> V_398 . V_401 [ 3 ] = 0UL ;
V_37 -> V_398 . V_402 = 0UL ;
}
F_40 ( ( L_180 ,
V_37 ,
V_27 -> V_52 ,
V_27 -> V_140 ,
V_397 ) ) ;
return F_268 ( V_27 , V_37 ) ;
}
static int
F_248 ( T_1 * V_27 )
{
T_2 * V_37 ;
V_37 = F_39 ( V_27 ) ;
if ( V_37 == NULL ) {
F_63 ( V_67 L_181 ) ;
return - 1 ;
}
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_403 . V_39 = V_404 ;
V_37 -> V_403 . V_137 = V_27 -> V_140 ;
V_37 -> V_398 . V_402 = 0UL ;
F_40 ( ( L_182 ,
V_37 ,
V_27 -> V_52 ,
V_27 -> V_140 ) ) ;
return F_268 ( V_27 , V_37 ) ;
}
static void F_271 ( struct V_1 * V_2 , T_1 * V_27 ,
unsigned long V_405 , struct V_86 * V_87 )
{
T_28 * V_406 ;
unsigned long V_59 ;
unsigned long V_407 , V_30 , V_408 ;
unsigned long V_409 = 0UL , V_397 = 0UL , V_262 = 0UL , V_259 ;
unsigned long V_410 ;
T_5 V_411 ;
unsigned int V_24 , V_412 ;
int V_413 = 0 ;
if ( F_206 ( V_27 -> V_46 == V_163 ) ) goto V_414;
if ( F_206 ( ( V_405 & 0x1 ) == 0 ) ) goto V_415;
V_410 = F_272 () ;
V_59 = V_405 >> V_63 ;
V_30 = V_29 -> V_30 ;
V_412 = F_218 ( V_27 ) ;
F_59 ( ( L_183
L_184 ,
V_405 ,
V_2 ? F_60 ( V_2 ) : - 1 ,
( V_87 ? V_87 -> V_416 : 0 ) ,
F_131 ( V_27 ) ? L_185 : L_186 ,
V_27 -> V_61 [ 0 ] ) ) ;
for ( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1 ) == 0 ) continue;
V_407 = V_408 = V_27 -> V_28 [ V_24 ] . V_20 ;
V_408 += 1 + V_30 ;
V_27 -> V_28 [ V_24 ] . V_20 = V_408 ;
if ( F_201 ( V_407 > V_408 ) ) {
V_397 |= 1UL << V_24 ;
if ( F_210 ( V_27 , V_24 ) ) V_409 |= 1UL << V_24 ;
}
F_59 ( ( L_187 ,
V_24 ,
V_408 ,
V_407 ,
F_36 ( V_24 ) & V_30 ,
V_397 ,
V_409 ) ) ;
}
if ( V_397 == 0UL ) return;
V_411 . V_20 = 0 ;
V_259 = 0UL ;
if ( V_412 ) {
unsigned long V_417 , V_418 ;
unsigned long V_419 ;
int V_420 , V_421 , V_88 = 0 ;
int V_422 = F_87 () ;
V_419 = V_397 >> V_63 ;
V_406 = & V_27 -> V_423 ;
F_219 ( V_27 -> V_164 ) ;
for( V_24 = V_63 ; V_419 && V_88 == 0 ; V_24 ++ , V_419 >>= 1 ) {
V_59 = 1UL << V_24 ;
if ( ( V_419 & 0x1 ) == 0 ) continue;
V_406 -> V_424 = ( unsigned char ) V_24 ;
V_406 -> V_409 = V_409 & V_59 ? 1 : 0 ;
V_406 -> V_425 = 0 ;
V_406 -> V_411 . V_20 = 0 ;
V_406 -> V_262 [ 0 ] = V_262 = V_27 -> V_28 [ V_24 ] . V_262 [ 0 ] ;
V_406 -> V_426 = V_27 -> V_28 [ V_24 ] . V_20 ;
V_406 -> V_427 = V_27 -> V_28 [ V_24 ] . V_256 ;
V_406 -> V_428 = V_27 -> V_28 [ V_24 ] . V_288 ;
if ( V_262 ) {
for( V_420 = 0 , V_421 = 0 ; V_262 ; V_420 ++ , V_262 >>= 1 ) {
if ( ( V_262 & 0x1 ) == 0 ) continue;
V_406 -> V_429 [ V_421 ++ ] = F_61 ( V_420 ) ? F_35 ( V_27 , V_420 ) : F_36 ( V_420 ) ;
F_59 ( ( L_188 , V_421 - 1 , V_420 , V_406 -> V_429 [ V_421 - 1 ] ) ) ;
}
}
V_323 [ V_422 ] . V_430 ++ ;
V_417 = F_272 () ;
V_88 = (* V_27 -> V_166 -> V_107 )( V_2 , V_27 -> V_164 , V_406 , V_87 , V_410 ) ;
V_418 = F_272 () ;
V_411 . V_314 . V_431 |= V_406 -> V_411 . V_314 . V_431 ;
V_411 . V_314 . V_432 |= V_406 -> V_411 . V_314 . V_432 ;
V_411 . V_314 . V_315 |= V_406 -> V_411 . V_314 . V_315 ;
if ( V_406 -> V_411 . V_314 . V_316 ) V_259 |= V_59 ;
V_323 [ V_422 ] . V_433 += V_418 - V_417 ;
}
if ( V_88 && V_419 ) {
F_40 ( ( L_189 ,
V_419 << V_63 ) ) ;
}
V_397 &= ~ V_259 ;
} else {
V_411 . V_314 . V_431 = V_409 ? 1 : 0 ;
V_411 . V_314 . V_432 = V_409 ? 1 : 0 ;
V_411 . V_314 . V_315 = V_409 ? 1 : 0 ;
V_411 . V_314 . V_316 = V_409 ? 0 : 1 ;
if ( V_409 == 0 ) V_259 = V_397 ;
}
F_59 ( ( L_190 , V_397 , V_259 ) ) ;
if ( V_259 ) {
unsigned long V_434 = V_259 ;
F_198 ( V_27 , & V_434 , V_435 ) ;
}
if ( V_409 && V_411 . V_314 . V_431 ) {
V_27 -> V_290 [ 0 ] = V_397 ;
if ( F_131 ( V_27 ) == 0 && V_411 . V_314 . V_432 ) {
V_27 -> V_319 = V_436 ;
F_220 ( V_2 , 1 ) ;
F_221 ( V_2 ) ;
}
V_413 = 1 ;
}
F_59 ( ( L_191 ,
F_120 () ? F_60 ( F_120 () ) : - 1 ,
F_273 ( V_2 ) ,
V_27 -> V_319 ,
V_397 ,
V_409 ,
V_411 . V_314 . V_315 ? 1 : 0 ) ) ;
if ( V_411 . V_314 . V_315 ) {
F_57 ( V_2 ) ;
V_27 -> V_46 = V_68 ;
V_27 -> V_318 = 1 ;
}
if ( V_413 ) F_270 ( V_27 , V_409 ) ;
return;
V_415:
F_63 ( V_67 L_192 ,
F_87 () ,
V_2 ? F_60 ( V_2 ) : - 1 ,
V_405 ) ;
return;
V_414:
F_40 ( ( L_193 , V_2 ? F_60 ( V_2 ) : - 1 ) ) ;
F_19 () ;
F_233 ( V_87 ) -> V_347 = 0 ;
F_233 ( V_87 ) -> V_363 = 1 ;
return;
}
static int
F_274 ( void * V_91 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_1 * V_27 ;
unsigned long V_11 ;
T_26 V_405 ;
int V_422 = F_87 () ;
int V_437 = 0 ;
V_323 [ V_422 ] . V_438 ++ ;
V_405 = F_275 ( 0 ) ;
V_2 = F_120 () ;
V_27 = F_121 () ;
if ( F_276 ( V_405 ) && V_2 ) {
if ( ! V_27 ) goto V_439;
if ( V_27 -> V_50 == 0 && ( V_2 -> V_308 . V_11 & V_362 ) == 0 )
goto V_440;
F_277 ( V_27 , V_11 ) ;
F_271 ( V_2 , V_27 , V_405 , V_87 ) ;
F_278 ( V_27 , V_11 ) ;
} else {
V_323 [ V_422 ] . V_441 ++ ;
V_437 = - 1 ;
}
F_28 () ;
return V_437 ;
V_439:
F_63 ( V_111 L_194 ,
V_422 , F_60 ( V_2 ) ) ;
F_28 () ;
return - 1 ;
V_440:
F_63 ( V_111 L_195 ,
V_422 ,
F_60 ( V_2 ) ) ;
F_28 () ;
return - 1 ;
}
static T_29
F_279 ( int V_442 , void * V_91 )
{
unsigned long V_417 , V_443 ;
unsigned long V_444 , V_445 ;
int V_422 ;
int V_88 ;
struct V_86 * V_87 = F_280 () ;
V_422 = F_281 () ;
if ( F_201 ( ! V_446 ) ) {
V_444 = V_323 [ V_422 ] . V_325 ;
V_445 = V_323 [ V_422 ] . V_447 ;
V_417 = F_272 () ;
V_88 = F_274 ( V_91 , V_87 ) ;
V_443 = F_272 () ;
if ( F_201 ( V_88 == 0 ) ) {
V_443 -= V_417 ;
if ( V_443 < V_444 ) V_323 [ V_422 ] . V_325 = V_443 ;
if ( V_443 > V_445 ) V_323 [ V_422 ] . V_447 = V_443 ;
V_323 [ V_422 ] . V_448 += V_443 ;
}
}
else {
(* V_446 -> V_449 )( V_442 , V_91 , V_87 ) ;
}
F_282 () ;
return V_450 ;
}
static void *
F_283 ( struct V_451 * V_321 , T_10 * V_100 )
{
if ( * V_100 == 0 ) {
return V_452 ;
}
while ( * V_100 <= V_453 ) {
if ( F_284 ( * V_100 - 1 ) ) {
return ( void * ) * V_100 ;
}
++ * V_100 ;
}
return NULL ;
}
static void *
F_285 ( struct V_451 * V_321 , void * V_297 , T_10 * V_100 )
{
++ * V_100 ;
return F_283 ( V_321 , V_100 ) ;
}
static void
F_286 ( struct V_451 * V_321 , void * V_297 )
{
}
static void
F_287 ( struct V_451 * V_321 )
{
struct V_99 * V_100 ;
T_4 * V_101 ;
unsigned long V_11 ;
F_288 ( V_321 ,
L_196
L_197
L_198
L_199
L_200
L_201 ,
V_454 , V_455 ,
V_29 -> V_456 ,
V_273 . V_457 > 0 ? L_202 : L_203 ,
V_273 . V_268 > 0 ? L_202 : L_203 ,
V_29 -> V_30 ,
V_29 -> V_11 ) ;
F_86 ( V_11 ) ;
F_288 ( V_321 ,
L_204
L_205
L_206
L_207 ,
V_113 . V_115 ,
V_113 . V_114 ,
V_113 . V_116 ,
V_113 . V_312 ) ;
F_89 ( V_11 ) ;
F_9 ( & V_104 ) ;
F_78 (pos, &pfm_buffer_fmt_list) {
V_101 = F_79 ( V_100 , T_4 , V_102 ) ;
F_288 ( V_321 , L_208 ,
V_101 -> V_103 , V_101 -> V_105 ) ;
}
F_11 ( & V_104 ) ;
}
static int
F_289 ( struct V_451 * V_321 , void * V_297 )
{
unsigned long V_65 ;
unsigned int V_24 ;
int V_90 ;
if ( V_297 == V_452 ) {
F_287 ( V_321 ) ;
return 0 ;
}
V_90 = ( long ) V_297 - 1 ;
F_288 ( V_321 ,
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
V_90 , V_323 [ V_90 ] . V_438 ,
V_90 , V_323 [ V_90 ] . V_448 ,
V_90 , V_323 [ V_90 ] . V_325 ,
V_90 , V_323 [ V_90 ] . V_447 ,
V_90 , V_323 [ V_90 ] . V_430 ,
V_90 , V_323 [ V_90 ] . V_433 ,
V_90 , V_323 [ V_90 ] . V_441 ,
V_90 , V_323 [ V_90 ] . V_458 ,
V_90 , F_290 ( V_459 , V_90 ) & V_360 ? 1 : 0 ,
V_90 , F_290 ( V_459 , V_90 ) & V_69 ? 1 : 0 ,
V_90 , F_290 ( V_459 , V_90 ) & V_361 ? 1 : 0 ,
V_90 , F_290 ( V_460 , V_90 ) ? F_290 ( V_460 , V_90 ) -> V_238 : - 1 ,
V_90 , F_290 ( V_461 , V_90 ) ,
V_90 , F_290 ( V_462 , V_90 ) ) ;
if ( F_291 () == 1 && V_273 . V_322 > 0 ) {
V_65 = F_21 () ;
F_27 () ;
F_288 ( V_321 ,
L_223
L_224 ,
V_90 , V_65 ,
V_90 , F_275 ( 0 ) ) ;
for ( V_24 = 0 ; F_178 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_292 ( V_24 ) == 0 ) continue;
F_288 ( V_321 ,
L_225
L_226 ,
V_90 , V_24 , F_275 ( V_24 ) ,
V_90 , V_24 , F_36 ( V_24 ) ) ;
}
}
return 0 ;
}
static int
F_293 ( struct V_158 * V_158 , struct V_125 * V_125 )
{
return F_294 ( V_125 , & V_463 ) ;
}
void
F_295 ( struct V_1 * V_2 , unsigned long V_148 , int V_464 )
{
struct V_86 * V_87 ;
unsigned long V_465 ;
unsigned long V_466 ;
V_466 = V_148 & V_69 ? 1 : 0 ;
if ( ( V_148 & V_361 ) == 0 || V_2 -> V_238 ) {
V_87 = F_119 ( V_2 ) ;
F_233 ( V_87 ) -> V_346 = V_464 ? V_466 : 0 ;
return;
}
if ( V_466 ) {
V_465 = F_22 ( V_70 ) ;
if ( V_464 ) {
F_24 ( V_70 , V_465 & ~ V_71 ) ;
F_14 () ;
F_16 () ;
return;
}
F_24 ( V_70 , V_465 | V_71 ) ;
F_17 () ;
F_16 () ;
}
}
static void
F_296 ( T_1 * V_27 , struct V_86 * V_87 )
{
struct V_1 * V_2 = V_27 -> V_151 ;
F_233 ( V_87 ) -> V_347 = 0 ;
F_233 ( V_87 ) -> V_363 = 1 ;
if ( F_120 () == V_2 ) {
F_40 ( ( L_227 ,
F_60 ( V_27 -> V_151 ) ) ) ;
F_245 ( NULL , NULL ) ;
}
F_220 ( V_2 , 0 ) ;
V_2 -> V_308 . V_309 = NULL ;
V_2 -> V_308 . V_11 &= ~ V_362 ;
F_40 ( ( L_228 , F_60 ( V_2 ) ) ) ;
}
void
F_297 ( struct V_1 * V_2 )
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
F_296 ( V_27 , V_87 ) ;
F_249 ( V_27 -> V_164 ) ;
F_10 ( V_27 , V_11 ) ;
F_55 ( V_27 ) ;
return;
}
F_27 () ;
V_65 = F_21 () ;
F_249 ( V_65 & ( V_467 ) ) ;
F_19 () ;
V_27 -> V_348 = V_65 & V_17 ;
F_245 ( NULL , NULL ) ;
F_65 ( V_27 -> V_80 , V_27 -> V_61 [ 0 ] ) ;
V_27 -> V_64 [ 0 ] = F_275 ( 0 ) ;
if ( V_27 -> V_64 [ 0 ] & ~ 0x1UL ) F_28 () ;
F_10 ( V_27 , V_11 ) ;
}
void
F_297 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
T_26 V_65 ;
V_27 = F_58 ( V_2 ) ;
if ( V_27 == NULL ) return;
V_65 = F_21 () ;
F_249 ( V_65 & ( V_467 ) ) ;
F_19 () ;
V_27 -> V_348 = V_65 & V_17 ;
}
static void
F_244 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
unsigned long V_11 ;
{ T_26 V_65 = F_21 () ;
F_249 ( V_65 & V_17 ) ;
}
V_27 = F_58 ( V_2 ) ;
F_103 ( V_27 , V_11 ) ;
F_245 ( NULL , NULL ) ;
F_65 ( V_27 -> V_80 , V_27 -> V_61 [ 0 ] ) ;
V_27 -> V_64 [ 0 ] = F_275 ( 0 ) ;
if ( V_27 -> V_64 [ 0 ] & ~ 0x1UL ) F_28 () ;
F_106 ( V_27 , V_11 ) ;
}
void
F_298 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
unsigned long V_468 = 0UL , V_419 = 0UL ;
unsigned long V_11 ;
T_26 V_65 , V_469 ;
int V_470 ;
V_27 = F_58 ( V_2 ) ;
if ( F_206 ( V_27 == NULL ) ) return;
F_249 ( F_120 () ) ;
if ( F_206 ( ( V_2 -> V_308 . V_11 & V_362 ) == 0 ) ) return;
V_11 = F_8 ( V_27 ) ;
V_65 = F_21 () ;
V_470 = V_29 -> V_11 & V_471 ;
F_249 ( V_65 & ( V_17 | V_16 ) ) ;
F_249 ( V_65 & V_467 ) ;
if ( F_206 ( V_27 -> V_46 == V_163 ) ) {
struct V_86 * V_87 = F_119 ( V_2 ) ;
F_249 ( V_27 -> V_164 ) ;
F_296 ( V_27 , V_87 ) ;
F_10 ( V_27 , V_11 ) ;
F_55 ( V_27 ) ;
return;
}
if ( V_27 -> V_73 ) {
F_29 ( V_27 -> V_74 , V_29 -> V_75 ) ;
F_32 ( V_27 -> V_76 , V_29 -> V_77 ) ;
}
V_469 = V_27 -> V_348 ;
if ( F_299 ( V_27 ) == F_87 () && V_27 -> V_55 == F_300 () ) {
V_468 = V_27 -> V_292 [ 0 ] ;
V_419 = V_27 -> V_302 [ 0 ] ;
} else {
V_419 = V_273 . V_457 ? V_27 -> V_61 [ 0 ] : V_27 -> V_79 [ 0 ] ;
V_468 = V_27 -> V_81 [ 0 ] ;
}
if ( V_419 ) F_66 ( V_27 -> V_80 , V_419 ) ;
if ( V_468 ) F_69 ( V_27 -> V_64 , V_468 ) ;
if ( F_206 ( F_276 ( V_27 -> V_64 [ 0 ] ) ) ) {
F_26 ( 0 , V_27 -> V_64 [ 0 ] ) ;
F_27 () ;
V_27 -> V_64 [ 0 ] = 0UL ;
if ( V_470 ) F_301 ( V_472 ) ;
V_323 [ F_87 () ] . V_458 ++ ;
}
V_27 -> V_292 [ 0 ] = 0UL ;
V_27 -> V_302 [ 0 ] = 0UL ;
F_53 ( V_27 , F_87 () ) ;
F_242 () ;
F_243 ( V_27 ) ;
F_245 ( V_2 , V_27 ) ;
if ( F_201 ( V_469 ) ) F_20 () ;
F_10 ( V_27 , V_11 ) ;
}
void
F_298 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
struct V_1 * V_149 ;
unsigned long V_419 , V_468 ;
T_26 V_65 , V_469 ;
int V_470 ;
V_149 = F_120 () ;
V_27 = F_58 ( V_2 ) ;
V_65 = F_21 () ;
F_249 ( V_65 & ( V_17 | V_16 ) ) ;
F_249 ( V_65 & V_467 ) ;
if ( V_27 -> V_73 ) {
F_29 ( V_27 -> V_74 , V_29 -> V_75 ) ;
F_32 ( V_27 -> V_76 , V_29 -> V_77 ) ;
}
V_469 = V_27 -> V_348 ;
V_470 = V_29 -> V_11 & V_471 ;
if ( F_201 ( V_149 == V_2 ) ) {
if ( F_201 ( V_469 ) ) F_20 () ;
return;
}
if ( V_149 ) F_244 ( V_149 ) ;
V_419 = V_273 . V_457 ? V_27 -> V_61 [ 0 ] : V_27 -> V_79 [ 0 ] ;
V_468 = V_27 -> V_81 [ 0 ] ;
F_66 ( V_27 -> V_80 , V_419 ) ;
F_69 ( V_27 -> V_64 , V_468 ) ;
if ( F_206 ( F_276 ( V_27 -> V_64 [ 0 ] ) ) ) {
F_26 ( 0 , V_27 -> V_64 [ 0 ] ) ;
F_27 () ;
V_27 -> V_64 [ 0 ] = 0UL ;
if ( V_470 ) F_301 ( V_472 ) ;
V_323 [ F_87 () ] . V_458 ++ ;
}
F_245 ( V_2 , V_27 ) ;
if ( F_201 ( V_469 ) ) F_20 () ;
}
static void
F_246 ( struct V_1 * V_2 , T_1 * V_27 )
{
T_26 V_405 ;
unsigned long V_473 , V_20 , V_474 , V_30 ;
int V_24 , V_266 = 0 ;
int V_475 ;
V_475 = V_27 -> V_151 == V_2 ? 1 : 0 ;
V_266 = ( F_120 () == V_2 ) || ( V_27 -> V_50 && V_27 -> V_150 == F_87 () ) ;
if ( V_266 ) {
F_245 ( NULL , NULL ) ;
F_40 ( ( L_229 ) ) ;
F_27 () ;
V_405 = F_275 ( 0 ) ;
F_28 () ;
} else {
V_405 = V_27 -> V_64 [ 0 ] ;
V_27 -> V_64 [ 0 ] = 0 ;
}
V_30 = V_29 -> V_30 ;
V_473 = V_27 -> V_61 [ 0 ] ;
F_40 ( ( L_230 , V_475 , V_30 , V_473 ) ) ;
for ( V_24 = 0 ; V_473 ; V_24 ++ , V_473 >>= 1 ) {
if ( ( V_473 & 0x1 ) == 0 ) continue;
V_20 = V_474 = V_266 ? F_36 ( V_24 ) : V_27 -> V_80 [ V_24 ] ;
if ( F_61 ( V_24 ) ) {
F_40 ( ( L_231 ,
F_60 ( V_2 ) ,
V_24 ,
V_27 -> V_28 [ V_24 ] . V_20 ,
V_20 & V_30 ) ) ;
V_20 = V_27 -> V_28 [ V_24 ] . V_20 + ( V_20 & V_30 ) ;
V_474 = 0UL ;
if ( V_405 & ( 1UL << V_24 ) ) {
V_20 += 1 + V_30 ;
F_40 ( ( L_232 , F_60 ( V_2 ) , V_24 ) ) ;
}
}
F_40 ( ( L_233 , F_60 ( V_2 ) , V_24 , V_20 , V_474 ) ) ;
if ( V_475 ) V_27 -> V_80 [ V_24 ] = V_474 ;
V_27 -> V_28 [ V_24 ] . V_20 = V_20 ;
}
}
static void
F_302 ( void * V_13 )
{
struct V_86 * V_87 ;
V_87 = F_119 ( V_3 ) ;
F_40 ( ( L_234 ) ) ;
F_19 () ;
F_14 () ;
F_233 ( V_87 ) -> V_346 = 0 ;
F_25 () ;
F_27 () ;
}
void
F_303 ( void * V_13 )
{
struct V_86 * V_87 ;
V_87 = F_119 ( V_3 ) ;
F_40 ( ( L_234 ) ) ;
F_19 () ;
F_14 () ;
F_233 ( V_87 ) -> V_346 = 0 ;
F_28 () ;
F_27 () ;
}
int
F_304 ( T_30 * V_476 )
{
int V_88 , V_24 ;
int V_477 ;
if ( V_476 == NULL || V_476 -> V_449 == NULL ) return - V_106 ;
if ( V_446 ) return - V_108 ;
if ( ! F_305 ( & V_478 ) ) {
return - V_108 ;
}
F_306 (reserve_cpu) {
V_88 = F_85 ( NULL , 1 , V_477 ) ;
if ( V_88 ) goto V_479;
}
V_88 = F_307 ( F_302 , NULL , 1 ) ;
if ( V_88 ) {
F_40 ( ( L_235 , V_88 ) ) ;
goto V_479;
}
V_446 = V_476 ;
F_11 ( & V_478 ) ;
return 0 ;
V_479:
F_306 (i) {
if ( V_24 >= V_477 ) break;
F_90 ( NULL , 1 , V_24 ) ;
}
F_11 ( & V_478 ) ;
return V_88 ;
}
int
F_308 ( T_30 * V_476 )
{
int V_24 ;
int V_88 ;
if ( V_476 == NULL ) return - V_106 ;
if ( V_446 != V_476 ) return - V_106 ;
if ( ! F_305 ( & V_478 ) ) {
return - V_108 ;
}
V_446 = NULL ;
V_88 = F_307 ( F_303 , NULL , 1 ) ;
if ( V_88 ) {
F_40 ( ( L_235 , V_88 ) ) ;
}
F_306 (i) {
F_90 ( NULL , 1 , V_24 ) ;
}
F_11 ( & V_478 ) ;
return 0 ;
}
static int T_6
F_309 ( void )
{
T_31 * * V_239 ;
int V_480 ;
V_480 = V_481 -> V_480 ;
V_239 = V_482 ;
while( * V_239 ) {
if ( ( * V_239 ) -> V_483 ) {
if ( ( * V_239 ) -> V_483 () == 0 ) goto V_484;
} else if ( ( * V_239 ) -> V_485 == V_480 || ( * V_239 ) -> V_485 == 0xff ) {
goto V_484;
}
V_239 ++ ;
}
return - 1 ;
V_484:
V_29 = * V_239 ;
return 0 ;
}
int T_6
F_310 ( void )
{
unsigned int V_486 , V_487 , V_24 ;
F_63 ( L_236 ,
V_454 ,
V_455 ,
V_472 ) ;
if ( F_309 () ) {
F_63 ( V_111 L_237 ,
V_481 -> V_480 ) ;
return - V_488 ;
}
V_486 = 0 ;
for ( V_24 = 0 ; F_178 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_179 ( V_24 ) == 0 ) continue;
V_29 -> V_228 [ V_24 >> 6 ] |= 1UL << ( V_24 & 63 ) ;
V_486 ++ ;
}
V_29 -> V_489 = V_486 ;
V_486 = 0 ; V_487 = 0 ;
for ( V_24 = 0 ; F_311 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_207 ( V_24 ) == 0 ) continue;
V_29 -> V_229 [ V_24 >> 6 ] |= 1UL << ( V_24 & 63 ) ;
V_486 ++ ;
if ( F_61 ( V_24 ) ) V_487 ++ ;
}
V_29 -> V_490 = V_486 ;
V_29 -> V_491 = V_487 ;
if ( V_29 -> V_310 ) {
if ( V_29 -> V_75 > V_492 ) {
F_63 ( V_111 L_238 , V_29 -> V_75 ) ;
V_29 = NULL ;
return - 1 ;
}
if ( V_29 -> V_77 > V_492 ) {
F_63 ( V_111 L_239 , V_29 -> V_75 ) ;
V_29 = NULL ;
return - 1 ;
}
}
F_63 ( L_240 ,
V_29 -> V_456 ,
V_29 -> V_489 ,
V_29 -> V_490 ,
V_29 -> V_491 ,
F_312 ( V_29 -> V_30 ) ) ;
if ( V_29 -> V_490 >= V_493 || V_29 -> V_489 >= V_494 ) {
F_63 ( V_67 L_241 ) ;
V_29 = NULL ;
return - 1 ;
}
V_495 = F_313 ( L_242 , V_178 , NULL , & V_496 ) ;
if ( V_495 == NULL ) {
F_63 ( V_67 L_243 ) ;
V_29 = NULL ;
return - 1 ;
}
V_497 = F_314 ( V_498 ) ;
F_51 ( & V_113 . V_499 ) ;
F_51 ( & V_104 ) ;
F_94 () ;
for( V_24 = 0 ; V_24 < V_324 ; V_24 ++ ) V_323 [ V_24 ] . V_325 = ~ 0UL ;
return 0 ;
}
void
F_315 ( void )
{
static int V_330 = 1 ;
F_14 () ;
F_19 () ;
F_28 () ;
if ( V_330 ) {
F_316 ( V_472 , & V_500 ) ;
V_330 = 0 ;
}
F_24 ( V_501 , V_472 ) ;
F_27 () ;
}
void
F_317 ( const char * V_502 )
{
struct V_1 * V_2 ;
struct V_86 * V_87 ;
T_1 * V_27 ;
unsigned long V_65 , V_465 , V_148 , V_11 ;
int V_24 , V_422 ;
F_122 ( V_11 ) ;
V_422 = F_87 () ;
V_87 = F_119 ( V_3 ) ;
V_148 = F_64 () ;
V_465 = F_22 ( V_70 ) ;
if ( V_148 == 0 && F_233 ( V_87 ) -> V_346 == 0 && ( V_465 & V_71 ) == 0 ) {
F_124 ( V_11 ) ;
return;
}
F_63 ( L_244 ,
V_422 ,
V_502 ,
F_60 ( V_3 ) ,
V_87 -> V_416 ,
V_3 -> V_503 ) ;
V_2 = F_120 () ;
V_27 = F_121 () ;
F_63 ( L_245 , V_422 , V_2 ? F_60 ( V_2 ) : - 1 , V_27 ) ;
V_65 = F_21 () ;
F_63 ( L_246 ,
V_422 ,
F_275 ( 0 ) ,
V_65 & V_16 ? 1 : 0 ,
V_65 & V_17 ? 1 : 0 ,
V_465 & V_71 ? 1 : 0 ,
V_148 ,
F_233 ( V_87 ) -> V_347 ,
F_233 ( V_87 ) -> V_346 ) ;
F_233 ( V_87 ) -> V_347 = 0 ;
F_233 ( V_87 ) -> V_346 = 0 ;
for ( V_24 = 1 ; F_178 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_179 ( V_24 ) == 0 ) continue;
F_63 ( L_247 , V_422 , V_24 , F_275 ( V_24 ) , V_24 , V_27 -> V_64 [ V_24 ] ) ;
}
for ( V_24 = 1 ; F_311 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_207 ( V_24 ) == 0 ) continue;
F_63 ( L_248 , V_422 , V_24 , F_36 ( V_24 ) , V_24 , V_27 -> V_80 [ V_24 ] ) ;
}
if ( V_27 ) {
F_63 ( L_249 ,
V_422 ,
V_27 -> V_46 ,
V_27 -> V_156 ,
V_27 -> V_164 ,
V_27 -> V_35 ,
V_27 -> V_33 ,
V_27 -> V_348 ) ;
}
F_124 ( V_11 ) ;
}
void
F_318 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_327 * V_308 ;
F_40 ( ( L_250 , F_60 ( V_2 ) ) ) ;
V_308 = & V_2 -> V_308 ;
V_308 -> V_309 = NULL ;
F_220 ( V_2 , 0 ) ;
}
T_27 long
F_252 ( int V_144 , int V_143 , void * V_91 , int V_242 )
{
return - V_377 ;
}
