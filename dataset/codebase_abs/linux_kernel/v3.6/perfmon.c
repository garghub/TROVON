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
F_88 ( 0 ) ;
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
if ( V_113 . V_115 == 0 && V_113 . V_114 == 0 )
F_88 ( 1 ) ;
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
if ( ! V_125 ) {
F_147 ( & V_174 ) ;
return F_139 ( - V_189 ) ;
}
V_125 -> V_132 = V_190 ;
V_125 -> V_129 = V_27 ;
return V_125 ;
}
static int
F_148 ( struct V_191 * V_192 , unsigned long V_85 , unsigned long V_42 , unsigned long V_40 )
{
F_40 ( ( L_72 , F_87 () , V_85 , V_42 , V_40 ) ) ;
while ( V_40 > 0 ) {
unsigned long V_193 = F_149 ( V_85 ) >> V_194 ;
if ( F_150 ( V_192 , V_42 , V_193 , V_43 , V_195 ) )
return - V_179 ;
V_42 += V_43 ;
V_85 += V_43 ;
V_40 -= V_43 ;
}
return 0 ;
}
static int
F_151 ( struct V_1 * V_2 , struct V_125 * V_126 , T_1 * V_27 , unsigned long V_196 , void * * V_197 )
{
struct V_198 * V_121 = V_2 -> V_121 ;
struct V_191 * V_192 = NULL ;
unsigned long V_40 ;
void * V_199 ;
V_40 = F_45 ( V_196 ) ;
F_40 ( ( L_73 , V_196 , V_40 ) ) ;
if ( V_40 > F_152 ( V_2 , V_200 ) )
return - V_179 ;
V_199 = F_44 ( V_40 ) ;
if ( V_199 == NULL ) {
F_40 ( ( L_74 ) ) ;
return - V_179 ;
}
F_40 ( ( L_75 , V_199 ) ) ;
V_192 = F_153 ( V_201 , V_45 ) ;
if ( ! V_192 ) {
F_40 ( ( L_76 ) ) ;
goto V_202;
}
F_154 ( & V_192 -> V_203 ) ;
V_192 -> V_204 = V_121 ;
V_192 -> V_205 = V_126 ;
V_192 -> V_206 = V_207 | V_208 | V_209 ;
V_192 -> V_210 = V_195 ;
V_27 -> V_164 = V_199 ;
V_27 -> V_157 = V_40 ;
F_155 ( & V_2 -> V_121 -> V_211 ) ;
V_192 -> V_212 = F_156 ( NULL , 0 , V_40 , 0 , V_213 | V_214 ) ;
if ( F_157 ( V_192 -> V_212 ) ) {
F_40 ( ( L_77 , V_40 ) ) ;
F_158 ( & V_2 -> V_121 -> V_211 ) ;
goto error;
}
V_192 -> V_215 = V_192 -> V_212 + V_40 ;
V_192 -> V_216 = V_192 -> V_212 >> V_194 ;
F_40 ( ( L_78 , V_40 , V_27 -> V_164 , V_192 -> V_212 ) ) ;
if ( F_148 ( V_192 , ( unsigned long ) V_199 , V_192 -> V_212 , V_40 ) ) {
F_40 ( ( L_79 ) ) ;
F_158 ( & V_2 -> V_121 -> V_211 ) ;
goto error;
}
F_159 ( V_126 ) ;
F_160 ( V_121 , V_192 ) ;
F_161 ( V_192 -> V_204 , V_192 -> V_206 , V_192 -> V_205 ,
F_162 ( V_192 ) ) ;
F_158 ( & V_2 -> V_121 -> V_211 ) ;
V_27 -> V_156 = ( void * ) V_192 -> V_212 ;
* ( unsigned long * ) V_197 = V_192 -> V_212 ;
return 0 ;
error:
F_163 ( V_201 , V_192 ) ;
V_202:
F_47 ( V_199 , V_40 ) ;
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
V_219 ,
V_220 ,
V_218 -> V_221 ,
V_218 -> V_222 ,
V_218 -> V_219 ,
V_218 -> V_223 ,
V_218 -> V_224 ) ) ;
V_88 = ( ( V_219 != V_218 -> V_221 )
|| ( V_219 != V_218 -> V_222 )
|| ( V_219 != V_218 -> V_219 )
|| ( V_220 != V_218 -> V_223 )
|| ( V_220 != V_218 -> V_224 )
|| ( V_220 != V_218 -> V_220 ) ) && ! F_169 ( V_225 ) ;
F_170 () ;
return V_88 ;
}
static int
F_171 ( struct V_1 * V_2 , T_15 * V_226 )
{
int V_44 ;
V_44 = V_226 -> V_44 ;
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
F_172 ( struct V_1 * V_2 , struct V_125 * V_126 , T_1 * V_27 , unsigned int V_44 ,
unsigned int V_90 , T_15 * V_91 )
{
T_4 * V_84 = NULL ;
unsigned long V_40 = 0UL ;
void * V_227 = NULL ;
void * V_228 = NULL ;
int V_88 = 0 ;
#define F_173 ( V_4 ) (pfm_buffer_fmt_t *)(a+1)
V_84 = F_80 ( V_91 -> V_229 ) ;
if ( V_84 == NULL ) {
F_40 ( ( L_82 , F_60 ( V_2 ) ) ) ;
return - V_106 ;
}
if ( V_84 -> V_230 ) V_228 = F_173 ( V_91 ) ;
V_88 = F_73 ( V_84 , V_2 , V_44 , V_90 , V_228 ) ;
F_40 ( ( L_83 , F_60 ( V_2 ) , V_44 , V_90 , V_228 , V_88 ) ) ;
if ( V_88 ) goto error;
V_27 -> V_166 = V_84 ;
V_27 -> V_165 = 1 ;
V_88 = F_72 ( V_84 , V_2 , V_44 , V_90 , V_228 , & V_40 ) ;
if ( V_88 ) goto error;
if ( V_40 ) {
V_88 = F_151 ( V_3 , V_126 , V_27 , V_40 , & V_227 ) ;
if ( V_88 ) goto error;
V_91 -> V_156 = V_227 ;
}
V_88 = F_74 ( V_84 , V_2 , V_27 -> V_164 , V_44 , V_90 , V_228 ) ;
error:
return V_88 ;
}
static void
F_174 ( T_1 * V_27 )
{
int V_24 ;
for ( V_24 = 1 ; F_175 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_176 ( V_24 ) == 0 ) continue;
V_27 -> V_72 [ V_24 ] = F_177 ( V_24 ) ;
F_40 ( ( L_12 , V_24 , V_27 -> V_72 [ V_24 ] ) ) ;
}
V_27 -> V_81 [ 0 ] = V_29 -> V_231 [ 0 ] & ~ 0x1 ;
V_27 -> V_79 [ 0 ] = V_29 -> V_232 [ 0 ] ;
F_40 ( ( L_84 , V_27 -> V_140 , V_27 -> V_81 [ 0 ] , V_27 -> V_79 [ 0 ] ) ) ;
V_27 -> V_233 [ 0 ] = 0UL ;
V_27 -> V_234 [ 0 ] = 0UL ;
}
static int
F_178 ( void * V_91 , T_9 * V_235 )
{
T_15 * V_236 = ( T_15 * ) V_91 ;
T_4 * V_84 ;
* V_235 = 0 ;
if ( ! F_70 ( V_236 -> V_229 , V_237 ) ) return 0 ;
V_84 = F_80 ( V_236 -> V_229 ) ;
if ( V_84 == NULL ) {
F_40 ( ( L_85 ) ) ;
return - V_106 ;
}
* V_235 = V_84 -> V_230 ;
F_40 ( ( L_86 , * V_235 ) ) ;
return 0 ;
}
static int
F_179 ( T_1 * V_27 , struct V_1 * V_2 )
{
if ( V_2 -> V_121 == NULL ) {
F_40 ( ( L_87 , F_60 ( V_2 ) ) ) ;
return - V_238 ;
}
if ( F_164 ( V_2 ) ) {
F_40 ( ( L_88 , F_60 ( V_2 ) ) ) ;
return - V_238 ;
}
if ( F_131 ( V_27 ) == 0 && V_2 == V_3 ) {
F_40 ( ( L_89 , F_60 ( V_2 ) ) ) ;
return - V_106 ;
}
if ( V_2 -> V_239 == V_240 ) {
F_40 ( ( L_90 , F_60 ( V_2 ) ) ) ;
return - V_108 ;
}
if ( V_2 == V_3 ) return 0 ;
if ( ! F_180 ( V_2 ) ) {
F_40 ( ( L_91 , F_60 ( V_2 ) , V_2 -> V_155 ) ) ;
return - V_108 ;
}
F_181 ( V_2 , 0 ) ;
return 0 ;
}
static int
F_182 ( T_1 * V_27 , T_16 V_241 , struct V_1 * * V_2 )
{
struct V_1 * V_242 = V_3 ;
int V_88 ;
if ( V_241 < 2 ) return - V_238 ;
if ( V_241 != F_183 ( V_3 ) ) {
F_184 ( & V_243 ) ;
V_242 = F_185 ( V_241 ) ;
if ( V_242 ) F_186 ( V_242 ) ;
F_187 ( & V_243 ) ;
if ( V_242 == NULL ) return - V_244 ;
}
V_88 = F_179 ( V_27 , V_242 ) ;
if ( V_88 == 0 ) {
* V_2 = V_242 ;
} else if ( V_242 != V_3 ) {
F_1 ( V_242 ) ;
}
return V_88 ;
}
static int
F_188 ( T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 )
{
T_15 * V_236 = ( T_15 * ) V_91 ;
struct V_125 * V_126 ;
struct V_174 V_174 ;
int V_44 ;
int V_144 ;
int V_88 ;
V_88 = F_171 ( V_3 , V_236 ) ;
if ( V_88 < 0 )
return V_88 ;
V_44 = V_236 -> V_44 ;
V_88 = - V_179 ;
V_144 = F_189 () ;
if ( V_144 < 0 )
return V_144 ;
V_27 = F_49 ( V_44 ) ;
if ( ! V_27 )
goto error;
V_126 = F_137 ( V_27 ) ;
if ( F_98 ( V_126 ) ) {
V_88 = F_97 ( V_126 ) ;
goto V_246;
}
V_236 -> V_140 = V_27 -> V_140 = V_144 ;
if ( F_70 ( V_236 -> V_229 , V_237 ) ) {
V_88 = F_172 ( V_3 , V_126 , V_27 , V_44 , 0 , V_236 ) ;
if ( V_88 )
goto V_247;
}
F_40 ( ( L_92 ,
V_27 ,
V_44 ,
V_27 -> V_50 ,
V_27 -> V_48 ,
V_27 -> V_248 ,
V_27 -> V_52 ,
V_27 -> V_140 ) ) ;
F_174 ( V_27 ) ;
F_190 ( V_144 , V_126 ) ;
return 0 ;
V_247:
V_174 = V_126 -> V_249 ;
F_191 ( V_126 ) ;
F_147 ( & V_174 ) ;
if ( V_27 -> V_166 ) {
F_71 ( V_27 -> V_166 , V_3 , NULL , V_87 ) ;
}
V_246:
F_55 ( V_27 ) ;
error:
F_192 ( V_144 ) ;
return V_88 ;
}
static inline unsigned long
F_193 ( T_17 * V_250 , int V_251 )
{
unsigned long V_20 = V_251 ? V_250 -> V_252 : V_250 -> V_253 ;
unsigned long V_254 , V_255 = V_250 -> V_256 , V_59 = V_250 -> V_59 ;
extern unsigned long V_257 ( unsigned long V_256 ) ;
if ( V_250 -> V_11 & V_258 ) {
V_254 = V_257 ( V_255 ) ;
V_20 -= ( V_255 & V_59 ) ;
if ( ( V_59 >> 32 ) != 0 )
V_254 |= V_257 ( V_255 >> 32 ) << 32 ;
V_250 -> V_256 = V_254 ;
}
V_250 -> V_259 = V_20 ;
return V_20 ;
}
static void
F_194 ( T_1 * V_27 , unsigned long * V_260 , int V_251 )
{
unsigned long V_59 = V_260 [ 0 ] ;
unsigned long V_261 = 0UL ;
unsigned long V_20 ;
int V_24 ;
V_59 >>= V_63 ;
for( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1UL ) == 0UL ) continue;
V_27 -> V_28 [ V_24 ] . V_20 = V_20 = F_193 ( V_27 -> V_28 + V_24 , V_251 ) ;
V_261 |= V_27 -> V_28 [ V_24 ] . V_262 [ 0 ] ;
F_59 ( ( L_93 , V_251 ? L_94 : L_95 , V_24 , V_20 ) ) ;
}
for( V_24 = 0 ; V_261 ; V_24 ++ , V_261 >>= 1 ) {
if ( ( V_261 & 0x1 ) == 0 ) continue;
V_27 -> V_28 [ V_24 ] . V_20 = V_20 = F_193 ( V_27 -> V_28 + V_24 , V_251 ) ;
F_59 ( ( L_96 ,
V_251 ? L_94 : L_95 , V_24 , V_20 ) ) ;
}
}
static void
F_195 ( T_1 * V_27 , unsigned long * V_260 , int V_251 )
{
unsigned long V_59 = V_260 [ 0 ] ;
unsigned long V_261 = 0UL ;
unsigned long V_20 ;
int V_24 ;
F_59 ( ( L_97 , V_260 [ 0 ] , V_251 ) ) ;
if ( V_27 -> V_46 == V_68 ) {
F_194 ( V_27 , V_260 , V_251 ) ;
return;
}
V_59 >>= V_63 ;
for( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1UL ) == 0UL ) continue;
V_20 = F_193 ( V_27 -> V_28 + V_24 , V_251 ) ;
V_261 |= V_27 -> V_28 [ V_24 ] . V_262 [ 0 ] ;
F_59 ( ( L_93 , V_251 ? L_94 : L_95 , V_24 , V_20 ) ) ;
F_37 ( V_27 , V_24 , V_20 ) ;
}
for( V_24 = 0 ; V_261 ; V_24 ++ , V_261 >>= 1 ) {
if ( ( V_261 & 0x1 ) == 0 ) continue;
V_20 = F_193 ( V_27 -> V_28 + V_24 , V_251 ) ;
if ( F_61 ( V_24 ) ) {
F_37 ( V_27 , V_24 , V_20 ) ;
} else {
F_38 ( V_24 , V_20 ) ;
}
F_59 ( ( L_96 ,
V_251 ? L_94 : L_95 , V_24 , V_20 ) ) ;
}
F_27 () ;
}
static int
F_196 ( T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_18 * V_236 = ( T_18 * ) V_91 ;
unsigned long V_263 , V_264 ;
unsigned long V_265 , V_262 , V_232 ;
unsigned int V_266 , V_267 , V_11 , V_268 ;
int V_24 , V_269 = 0 , V_270 , V_66 , V_271 ;
int V_272 , V_273 , V_155 ;
int V_88 = - V_106 ;
T_19 V_274 ;
#define F_197 ( V_5 , T_20 , T_21 ) ((x)->ctx_fl_system ^ PMC_PM(y, z))
V_155 = V_27 -> V_46 ;
V_270 = V_155 == V_275 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_2 = V_27 -> V_151 ;
V_232 = V_29 -> V_232 [ 0 ] ;
if ( V_155 == V_163 ) return - V_106 ;
if ( V_270 ) {
if ( V_66 && V_27 -> V_150 != F_87 () ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_269 = F_120 () == V_2 || V_66 ? 1 : 0 ;
}
V_271 = V_276 . V_271 ;
for ( V_24 = 0 ; V_24 < V_245 ; V_24 ++ , V_236 ++ ) {
V_266 = V_236 -> V_277 ;
V_267 = V_236 -> V_267 ;
V_263 = V_236 -> V_278 ;
V_265 = V_236 -> V_279 [ 0 ] ;
V_262 = V_236 -> V_280 [ 0 ] ;
V_11 = 0 ;
if ( V_266 >= V_281 ) {
F_40 ( ( L_98 , V_266 ) ) ;
goto error;
}
V_268 = V_29 -> V_282 [ V_266 ] . type ;
V_264 = ( V_263 >> V_29 -> V_282 [ V_266 ] . V_283 ) & 0x1 ;
V_273 = ( V_268 & V_284 ) == V_284 ? 1 : 0 ;
V_272 = ( V_268 & V_285 ) == V_285 ? 1 : 0 ;
if ( ( V_268 & V_286 ) == 0 || ( V_268 & V_287 ) == V_287 ) {
F_40 ( ( L_99 , V_266 , V_268 ) ) ;
goto error;
}
V_274 = V_29 -> V_282 [ V_266 ] . V_288 ;
if ( V_272 && V_263 != F_177 ( V_266 ) && V_66 ^ V_264 ) {
F_40 ( ( L_100 ,
V_266 ,
V_264 ,
V_66 ) ) ;
goto error;
}
if ( V_273 ) {
V_263 |= 1 << V_289 ;
if ( V_267 & V_290 ) {
V_11 |= V_290 ;
}
if ( V_267 & V_258 ) V_11 |= V_258 ;
if ( ( V_265 & V_232 ) != V_265 ) {
F_40 ( ( L_101 , V_265 , V_266 ) ) ;
goto error;
}
if ( ( V_262 & V_232 ) != V_262 ) {
F_40 ( ( L_102 , V_262 , V_266 ) ) ;
goto error;
}
} else {
if ( V_267 & ( V_290 | V_258 ) ) {
F_40 ( ( L_103 , V_266 ) ) ;
goto error;
}
}
if ( F_198 ( V_271 == 0 && V_274 ) ) {
V_88 = (* V_274)( V_2 , V_27 , V_266 , & V_263 , V_87 ) ;
if ( V_88 ) goto error;
V_88 = - V_106 ;
}
F_199 ( V_236 -> V_267 , 0 ) ;
if ( V_273 ) {
V_27 -> V_28 [ V_266 ] . V_11 = V_11 ;
V_27 -> V_28 [ V_266 ] . V_262 [ 0 ] = V_262 ;
V_27 -> V_28 [ V_266 ] . V_265 [ 0 ] = V_265 ;
V_27 -> V_28 [ V_266 ] . V_291 = V_236 -> V_292 ;
F_200 ( V_27 , V_262 ) ;
F_200 ( V_27 , V_265 ) ;
if ( V_155 == V_68 ) V_27 -> V_293 [ 0 ] &= ~ 1UL << V_266 ;
}
F_200 ( V_27 , V_29 -> V_282 [ V_266 ] . V_294 [ 0 ] ) ;
if ( V_272 ) F_201 ( V_27 , 1UL << V_266 ) ;
V_27 -> V_72 [ V_266 ] = V_263 ;
if ( V_270 ) {
if ( V_66 == 0 ) V_27 -> V_64 [ V_266 ] = V_263 ;
if ( V_269 ) {
F_26 ( V_266 , V_263 ) ;
}
#ifdef F_129
else {
V_27 -> V_295 [ 0 ] |= 1UL << V_266 ;
}
#endif
}
F_40 ( ( L_104 ,
V_266 ,
V_263 ,
V_270 ,
V_269 ,
V_11 ,
V_27 -> V_81 [ 0 ] ,
V_27 -> V_61 [ 0 ] ,
V_27 -> V_28 [ V_266 ] . V_291 ,
V_265 ,
V_262 ,
V_27 -> V_295 [ 0 ] ,
V_27 -> V_62 [ 0 ] ,
V_27 -> V_293 [ 0 ] ) ) ;
}
if ( V_269 ) F_27 () ;
return 0 ;
error:
F_199 ( V_236 -> V_267 , V_296 ) ;
return V_88 ;
}
static int
F_202 ( T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_18 * V_236 = ( T_18 * ) V_91 ;
unsigned long V_263 , V_297 , V_60 ;
unsigned int V_266 ;
int V_24 , V_269 = 0 , V_155 ;
int V_273 , V_270 , V_66 , V_271 ;
int V_88 = - V_106 ;
T_19 V_274 ;
V_155 = V_27 -> V_46 ;
V_270 = V_155 == V_275 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_60 = V_29 -> V_30 ;
V_2 = V_27 -> V_151 ;
if ( F_203 ( V_155 == V_163 ) ) return - V_106 ;
if ( F_198 ( V_270 ) ) {
if ( F_203 ( V_66 && V_27 -> V_150 != F_87 () ) ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_269 = F_120 () == V_2 || V_66 ? 1 : 0 ;
}
V_271 = V_276 . V_271 ;
for ( V_24 = 0 ; V_24 < V_245 ; V_24 ++ , V_236 ++ ) {
V_266 = V_236 -> V_277 ;
V_263 = V_236 -> V_278 ;
if ( ! F_204 ( V_266 ) ) {
F_40 ( ( L_105 , V_266 ) ) ;
goto V_298;
}
V_273 = F_61 ( V_266 ) ;
V_274 = V_29 -> V_299 [ V_266 ] . V_288 ;
if ( F_203 ( V_271 == 0 && V_274 ) ) {
unsigned long V_300 = V_263 ;
V_88 = (* V_274)( V_2 , V_27 , V_266 , & V_300 , V_87 ) ;
if ( V_88 ) goto V_298;
V_263 = V_300 ;
V_88 = - V_106 ;
}
F_199 ( V_236 -> V_267 , 0 ) ;
V_297 = V_263 ;
if ( V_273 ) {
V_27 -> V_28 [ V_266 ] . V_259 = V_263 ;
if ( V_270 ) {
V_297 = V_263 & V_60 ;
V_263 = V_263 & ~ V_60 ;
}
}
V_27 -> V_28 [ V_266 ] . V_252 = V_236 -> V_301 ;
V_27 -> V_28 [ V_266 ] . V_253 = V_236 -> V_302 ;
V_27 -> V_28 [ V_266 ] . V_256 = V_236 -> V_303 ;
V_27 -> V_28 [ V_266 ] . V_59 = V_236 -> V_304 ;
V_27 -> V_28 [ V_266 ] . V_20 = V_263 ;
F_200 ( V_27 , F_205 ( V_266 ) ) ;
F_200 ( V_27 , F_206 ( V_266 ) ) ;
if ( V_273 && V_155 == V_68 ) {
V_27 -> V_293 [ 0 ] &= ~ 1UL << V_266 ;
}
if ( V_270 ) {
if ( V_66 == 0 ) V_27 -> V_80 [ V_266 ] = V_297 ;
if ( V_269 ) {
F_38 ( V_266 , V_297 ) ;
} else {
#ifdef F_129
V_27 -> V_305 [ 0 ] |= 1UL << V_266 ;
#endif
}
}
F_40 ( ( L_106
L_107 ,
V_266 ,
V_263 ,
V_270 ,
V_269 ,
V_297 ,
V_27 -> V_28 [ V_266 ] . V_20 ,
V_27 -> V_28 [ V_266 ] . V_253 ,
V_27 -> V_28 [ V_266 ] . V_252 ,
F_207 ( V_27 , V_266 ) ? 'Y' : 'N' ,
V_27 -> V_28 [ V_266 ] . V_256 ,
V_27 -> V_28 [ V_266 ] . V_59 ,
V_27 -> V_61 [ 0 ] ,
V_27 -> V_28 [ V_266 ] . V_262 [ 0 ] ,
V_27 -> V_305 [ 0 ] ,
V_27 -> V_79 [ 0 ] ,
V_27 -> V_293 [ 0 ] ) ) ;
}
if ( V_269 ) F_27 () ;
return 0 ;
V_298:
F_199 ( V_236 -> V_267 , V_296 ) ;
return V_88 ;
}
static int
F_208 ( T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
unsigned long V_20 = 0UL , V_259 , V_60 , V_306 ;
T_18 * V_236 = ( T_18 * ) V_91 ;
unsigned int V_266 , V_267 = 0 ;
int V_24 , V_269 = 0 , V_155 ;
int V_270 , V_66 , V_273 , V_271 ;
int V_88 = - V_106 ;
T_19 V_307 ;
V_155 = V_27 -> V_46 ;
V_270 = V_155 == V_275 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_60 = V_29 -> V_30 ;
V_2 = V_27 -> V_151 ;
if ( V_155 == V_163 ) return - V_106 ;
if ( F_198 ( V_270 ) ) {
if ( F_203 ( V_66 && V_27 -> V_150 != F_87 () ) ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_269 = F_120 () == V_2 || V_66 ? 1 : 0 ;
if ( V_269 ) F_27 () ;
}
V_271 = V_276 . V_271 ;
F_40 ( ( L_108 ,
V_270 ,
V_269 ,
V_155 ) ) ;
for ( V_24 = 0 ; V_24 < V_245 ; V_24 ++ , V_236 ++ ) {
V_266 = V_236 -> V_277 ;
V_267 = V_236 -> V_267 ;
if ( F_203 ( ! F_204 ( V_266 ) ) ) goto error;
if ( F_203 ( ! F_209 ( V_27 , V_266 ) ) ) goto error;
V_306 = V_27 -> V_28 [ V_266 ] . V_20 ;
V_259 = V_27 -> V_28 [ V_266 ] . V_259 ;
V_273 = F_61 ( V_266 ) ;
if ( V_269 ) {
V_20 = F_36 ( V_266 ) ;
} else {
V_20 = V_270 ? V_27 -> V_80 [ V_266 ] : 0UL ;
}
V_307 = V_29 -> V_299 [ V_266 ] . V_308 ;
if ( V_273 ) {
V_20 &= V_60 ;
V_20 += V_306 ;
}
if ( F_203 ( V_271 == 0 && V_307 ) ) {
unsigned long V_300 = V_20 ;
V_88 = (* V_307)( V_27 -> V_151 , V_27 , V_266 , & V_300 , V_87 ) ;
if ( V_88 ) goto error;
V_20 = V_300 ;
V_88 = - V_106 ;
}
F_199 ( V_267 , 0 ) ;
F_40 ( ( L_109 , V_266 , V_20 ) ) ;
V_236 -> V_278 = V_20 ;
V_236 -> V_267 = V_267 ;
V_236 -> V_309 = V_259 ;
}
return 0 ;
error:
F_199 ( V_236 -> V_267 , V_296 ) ;
return V_88 ;
}
int
F_210 ( struct V_1 * V_2 , void * V_236 , unsigned int V_310 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_236 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_196 ( V_27 , V_236 , V_310 , V_87 ) ;
}
int
F_211 ( struct V_1 * V_2 , void * V_236 , unsigned int V_310 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_236 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_208 ( V_27 , V_236 , V_310 , V_87 ) ;
}
int
F_212 ( struct V_1 * V_2 )
{
T_1 * V_27 = V_2 -> V_311 . V_312 ;
unsigned long V_11 ;
int V_88 = 0 ;
if ( V_29 -> V_313 == 0 ) return 0 ;
F_40 ( ( L_110 , F_60 ( V_2 ) ) ) ;
if ( V_2 -> V_311 . V_11 & V_314 ) return 0 ;
if ( V_27 && V_27 -> V_73 == 1 ) return - 1 ;
F_86 ( V_11 ) ;
if ( V_113 . V_116 > 0 )
V_88 = - 1 ;
else
V_113 . V_315 ++ ;
F_40 ( ( L_111 ,
V_113 . V_315 ,
V_113 . V_116 ,
F_60 ( V_2 ) , V_88 ) ) ;
F_89 ( V_11 ) ;
return V_88 ;
}
int
F_213 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
int V_88 ;
if ( V_29 -> V_313 == 0 ) return 0 ;
F_86 ( V_11 ) ;
if ( V_113 . V_315 == 0 ) {
F_63 ( V_67 L_112 , F_60 ( V_2 ) ) ;
V_88 = - 1 ;
} else {
V_113 . V_315 -- ;
V_88 = 0 ;
}
F_89 ( V_11 ) ;
return V_88 ;
}
static int
F_214 ( T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_4 * V_84 ;
T_5 V_316 ;
int V_155 , V_66 ;
int V_88 = 0 ;
V_155 = V_27 -> V_46 ;
V_84 = V_27 -> V_166 ;
V_66 = V_27 -> V_50 ;
V_2 = F_128 ( V_27 ) ;
switch( V_155 ) {
case V_68 :
break;
case V_275 :
if ( F_215 ( V_27 ) && V_84 -> V_97 ) break;
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
if ( F_203 ( V_2 == NULL ) ) {
F_63 ( V_67 L_115 , F_60 ( V_3 ) ) ;
return - V_106 ;
}
if ( V_2 == V_3 || V_66 ) {
V_84 = V_27 -> V_166 ;
F_40 ( ( L_116 ,
F_60 ( V_2 ) ,
V_27 -> V_293 [ 0 ] ) ) ;
if ( F_215 ( V_27 ) ) {
F_216 ( V_27 -> V_164 ) ;
V_316 . V_317 . V_318 = 0 ;
V_316 . V_317 . V_319 = 0 ;
if ( V_155 == V_275 )
V_88 = F_76 ( V_84 , V_2 , & V_316 , V_27 -> V_164 , V_87 ) ;
else
V_88 = F_75 ( V_84 , V_2 , & V_316 , V_27 -> V_164 , V_87 ) ;
} else {
V_316 . V_317 . V_318 = 0 ;
V_316 . V_317 . V_319 = 1 ;
}
if ( V_88 == 0 ) {
if ( V_316 . V_317 . V_319 )
F_195 ( V_27 , V_27 -> V_293 , V_320 ) ;
if ( V_316 . V_317 . V_318 == 0 ) {
F_40 ( ( L_117 , F_60 ( V_2 ) ) ) ;
if ( V_155 == V_68 ) F_62 ( V_2 ) ;
} else {
F_40 ( ( L_118 , F_60 ( V_2 ) ) ) ;
}
}
V_27 -> V_293 [ 0 ] = 0UL ;
V_27 -> V_46 = V_275 ;
V_27 -> V_321 = 0 ;
return 0 ;
}
if ( V_155 == V_68 ) {
if ( V_27 -> V_321 == 0 ) return - V_106 ;
V_27 -> V_321 = 0 ;
}
if ( F_131 ( V_27 ) == 0 && V_155 == V_68 ) {
F_40 ( ( L_119 , F_60 ( V_2 ) ) ) ;
F_132 ( & V_27 -> V_54 ) ;
} else {
F_40 ( ( L_120 , F_60 ( V_2 ) ) ) ;
V_27 -> V_322 = V_323 ;
F_217 ( V_2 , 1 ) ;
F_218 ( V_2 ) ;
}
return 0 ;
}
static int
F_219 ( T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 )
{
unsigned int V_324 = * ( unsigned int * ) V_91 ;
V_276 . V_325 = V_324 == 0 ? 0 : 1 ;
F_63 ( V_111 L_121 , V_276 . V_325 ? L_122 : L_123 ) ;
if ( V_324 == 0 ) {
memset ( V_326 , 0 , sizeof( V_326 ) ) ;
for( V_324 = 0 ; V_324 < V_327 ; V_324 ++ ) V_326 [ V_324 ] . V_328 = ~ 0UL ;
}
return 0 ;
}
static int
F_220 ( int V_329 , T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 )
{
struct V_330 * V_311 = NULL ;
struct V_1 * V_2 ;
T_22 * V_236 = ( T_22 * ) V_91 ;
unsigned long V_11 ;
T_23 V_331 ;
unsigned int V_332 ;
int V_333 ;
int V_88 = 0 , V_155 ;
int V_24 , V_269 = 0 ;
int V_66 , V_270 ;
if ( V_29 -> V_313 == 0 ) return - V_106 ;
V_155 = V_27 -> V_46 ;
V_270 = V_155 == V_275 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_2 = V_27 -> V_151 ;
if ( V_155 == V_163 ) return - V_106 ;
if ( V_270 ) {
V_311 = & V_2 -> V_311 ;
if ( F_203 ( V_66 && V_27 -> V_150 != F_87 () ) ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_269 = F_120 () == V_2 || V_66 ? 1 : 0 ;
}
V_333 = V_27 -> V_73 == 0 ;
if ( V_270 && ( V_311 -> V_11 & V_314 ) != 0 ) {
F_40 ( ( L_124 , F_60 ( V_2 ) ) ) ;
return - V_108 ;
}
if ( V_270 ) {
F_86 ( V_11 ) ;
if ( V_333 && V_66 ) {
if ( V_113 . V_315 )
V_88 = - V_108 ;
else
V_113 . V_116 ++ ;
}
F_89 ( V_11 ) ;
}
if ( V_88 != 0 ) return V_88 ;
V_27 -> V_73 = 1 ;
if ( V_333 && V_269 ) {
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
for ( V_24 = 0 ; V_24 < V_245 ; V_24 ++ , V_236 ++ ) {
V_332 = V_236 -> V_334 ;
V_331 . V_20 = V_236 -> V_335 ;
V_88 = - V_106 ;
if ( ( V_329 == V_336 && V_332 >= V_337 ) || ( ( V_329 == V_338 ) && V_332 >= V_339 ) ) {
F_40 ( ( L_126 ,
V_332 , V_331 . V_20 , V_329 , V_24 , V_245 ) ) ;
goto V_298;
}
if ( V_332 & 0x1 ) {
if ( V_329 == V_336 )
V_331 . V_340 . V_341 = 0 ;
else
V_331 . V_342 . V_343 = V_331 . V_342 . V_344 = 0 ;
}
F_199 ( V_236 -> V_345 , 0 ) ;
if ( V_329 == V_336 ) {
F_221 ( V_27 , V_332 ) ;
if ( V_269 ) {
F_30 ( V_332 , V_331 . V_20 ) ;
F_31 () ;
}
V_27 -> V_74 [ V_332 ] = V_331 . V_20 ;
F_40 ( ( L_127 ,
V_332 , V_331 . V_20 , V_27 -> V_233 [ 0 ] , V_270 , V_269 ) ) ;
} else {
F_222 ( V_27 , V_332 ) ;
if ( V_269 ) {
F_33 ( V_332 , V_331 . V_20 ) ;
F_34 () ;
}
V_27 -> V_76 [ V_332 ] = V_331 . V_20 ;
F_40 ( ( L_128 ,
V_332 , V_331 . V_20 , V_27 -> V_234 [ 0 ] , V_270 , V_269 ) ) ;
}
}
return 0 ;
V_298:
if ( V_333 ) {
F_86 ( V_11 ) ;
if ( V_27 -> V_50 ) {
V_113 . V_116 -- ;
}
F_89 ( V_11 ) ;
V_27 -> V_73 = 0 ;
}
F_199 ( V_236 -> V_345 , V_296 ) ;
return V_88 ;
}
static int
F_223 ( T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 )
{
return F_220 ( V_336 , V_27 , V_91 , V_245 , V_87 ) ;
}
static int
F_224 ( T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 )
{
return F_220 ( V_338 , V_27 , V_91 , V_245 , V_87 ) ;
}
int
F_225 ( struct V_1 * V_2 , void * V_236 , unsigned int V_310 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_236 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_223 ( V_27 , V_236 , V_310 , V_87 ) ;
}
int
F_226 ( struct V_1 * V_2 , void * V_236 , unsigned int V_310 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_236 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_224 ( V_27 , V_236 , V_310 , V_87 ) ;
}
static int
F_227 ( T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 )
{
T_24 * V_236 = ( T_24 * ) V_91 ;
V_236 -> V_346 = V_347 ;
return 0 ;
}
static int
F_228 ( T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 )
{
struct V_86 * V_348 ;
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
F_229 ( V_69 ) ;
F_14 () ;
F_230 ( V_87 ) -> V_349 = 0 ;
return 0 ;
}
if ( V_2 == V_3 ) {
F_19 () ;
F_230 ( V_87 ) -> V_350 = 0 ;
} else {
V_348 = F_119 ( V_2 ) ;
F_230 ( V_348 ) -> V_350 = 0 ;
V_27 -> V_351 = 0 ;
F_40 ( ( L_130 , F_60 ( V_2 ) ) ) ;
}
return 0 ;
}
static int
F_231 ( T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 )
{
struct V_86 * V_348 ;
int V_155 , V_66 ;
V_155 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_155 != V_275 ) return - V_106 ;
if ( V_66 && V_27 -> V_150 != F_87 () ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
if ( V_66 ) {
F_230 ( V_87 ) -> V_349 = 1 ;
F_232 ( V_69 ) ;
F_17 () ;
F_24 ( V_70 , F_22 ( V_70 ) | V_71 ) ;
F_16 () ;
return 0 ;
}
if ( V_27 -> V_151 == V_3 ) {
F_20 () ;
F_230 ( V_87 ) -> V_350 = 1 ;
} else {
V_348 = F_119 ( V_27 -> V_151 ) ;
V_27 -> V_351 = V_17 ;
F_230 ( V_348 ) -> V_350 = 1 ;
}
return 0 ;
}
static int
F_233 ( T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 )
{
T_18 * V_236 = ( T_18 * ) V_91 ;
unsigned int V_266 ;
int V_24 ;
int V_88 = - V_106 ;
for ( V_24 = 0 ; V_24 < V_245 ; V_24 ++ , V_236 ++ ) {
V_266 = V_236 -> V_277 ;
if ( ! F_176 ( V_266 ) ) goto V_298;
V_236 -> V_278 = F_177 ( V_266 ) ;
F_199 ( V_236 -> V_267 , 0 ) ;
F_40 ( ( L_131 , V_266 , V_236 -> V_278 ) ) ;
}
return 0 ;
V_298:
F_199 ( V_236 -> V_267 , V_296 ) ;
return V_88 ;
}
static int
F_234 ( T_1 * V_27 )
{
struct V_1 * V_352 , * V_353 ;
int V_88 = - V_244 ;
F_184 ( & V_243 ) ;
F_235 (g, t) {
if ( V_353 -> V_311 . V_312 == V_27 ) {
V_88 = 0 ;
goto V_109;
}
} F_236 ( V_352 , V_353 ) ;
V_109:
F_187 ( & V_243 ) ;
F_40 ( ( L_132 , V_88 , V_27 ) ) ;
return V_88 ;
}
static int
F_237 ( T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
struct V_330 * V_311 ;
struct T_1 * V_354 ;
unsigned long V_11 ;
#ifndef F_129
struct V_1 * V_355 = NULL ;
#endif
T_25 * V_236 = ( T_25 * ) V_91 ;
unsigned long * V_356 , * V_357 ;
int V_358 ;
int V_88 = 0 ;
int V_155 , V_66 , V_359 = 0 ;
V_155 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_155 != V_47 ) {
F_40 ( ( L_133 ,
V_236 -> V_360 ,
V_27 -> V_46 ) ) ;
return - V_108 ;
}
F_40 ( ( L_134 , V_236 -> V_360 , V_27 -> V_73 ) ) ;
if ( F_131 ( V_27 ) == 0 && V_236 -> V_360 == V_3 -> V_241 ) {
F_40 ( ( L_135 ) ) ;
return - V_106 ;
}
V_88 = F_182 ( V_27 , V_236 -> V_360 , & V_2 ) ;
if ( V_88 ) {
F_40 ( ( L_136 , V_236 -> V_360 , V_88 ) ) ;
return V_88 ;
}
V_88 = - V_106 ;
if ( V_66 && V_2 != V_3 ) {
F_40 ( ( L_137 ,
V_236 -> V_360 ) ) ;
goto error;
}
V_311 = & V_2 -> V_311 ;
V_88 = 0 ;
if ( V_27 -> V_73 ) {
if ( V_311 -> V_11 & V_314 ) {
V_88 = - V_108 ;
F_40 ( ( L_138 , V_236 -> V_360 ) ) ;
goto error;
}
F_86 ( V_11 ) ;
if ( V_66 ) {
if ( V_113 . V_315 ) {
F_40 ( ( L_139 ,
F_60 ( V_2 ) ) ) ;
V_88 = - V_108 ;
} else {
V_113 . V_116 ++ ;
F_40 ( ( L_140 , F_60 ( V_2 ) , V_113 . V_116 ) ) ;
V_359 = 1 ;
}
}
F_89 ( V_11 ) ;
if ( V_88 ) goto error;
}
V_358 = V_27 -> V_150 = F_87 () ;
V_88 = - V_108 ;
V_88 = F_85 ( V_3 , V_66 , V_358 ) ;
if ( V_88 ) goto error;
F_40 ( ( L_141 ,
V_311 -> V_312 , V_27 ) ) ;
V_88 = - V_108 ;
V_354 = F_238 ( V_361 , & V_311 -> V_312 , NULL , V_27 , sizeof( T_1 * ) ) ;
if ( V_354 != NULL ) {
F_40 ( ( L_142 , V_236 -> V_360 ) ) ;
goto V_362;
}
F_43 ( V_27 ) ;
V_27 -> V_46 = V_275 ;
V_27 -> V_151 = V_2 ;
if ( V_66 ) {
F_232 ( V_363 ) ;
F_229 ( V_69 ) ;
if ( V_27 -> V_248 ) F_232 ( V_364 ) ;
} else {
V_311 -> V_11 |= V_365 ;
}
F_67 ( V_2 , V_27 ) ;
F_68 ( V_2 , V_27 ) ;
V_356 = V_27 -> V_64 ;
V_357 = V_27 -> V_80 ;
if ( V_2 == V_3 ) {
if ( V_66 == 0 ) {
F_230 ( V_87 ) -> V_366 = 0 ;
F_40 ( ( L_143 , F_60 ( V_2 ) ) ) ;
F_53 ( V_27 , F_87 () ) ;
F_239 () ;
F_240 ( V_27 ) ;
#ifndef F_129
V_355 = F_120 () ;
if ( V_355 ) F_241 ( V_355 ) ;
#endif
}
F_66 ( V_357 , V_27 -> V_79 [ 0 ] ) ;
F_69 ( V_356 , V_27 -> V_81 [ 0 ] ) ;
V_27 -> V_295 [ 0 ] = 0UL ;
V_27 -> V_305 [ 0 ] = 0UL ;
if ( V_27 -> V_73 ) {
F_29 ( V_27 -> V_74 , V_29 -> V_75 ) ;
F_32 ( V_27 -> V_76 , V_29 -> V_77 ) ;
}
F_242 ( V_2 , V_27 ) ;
F_40 ( ( L_144 , F_60 ( V_2 ) ) ) ;
} else {
V_87 = F_119 ( V_2 ) ;
V_27 -> V_55 = V_56 ;
F_53 ( V_27 , - 1 ) ;
V_27 -> V_351 = 0UL ;
F_230 ( V_87 ) -> V_350 = F_230 ( V_87 ) -> V_349 = 0 ;
}
V_88 = 0 ;
V_362:
if ( V_88 ) F_90 ( V_27 , V_27 -> V_50 , V_358 ) ;
error:
if ( V_88 && V_359 ) {
F_86 ( V_11 ) ;
V_113 . V_116 -- ;
F_89 ( V_11 ) ;
}
if ( V_66 == 0 && V_2 != V_3 ) {
F_1 ( V_2 ) ;
if ( V_88 == 0 ) {
V_88 = F_234 ( V_27 ) ;
if ( V_88 ) {
V_27 -> V_46 = V_47 ;
V_27 -> V_151 = NULL ;
}
}
}
return V_88 ;
}
static int
F_123 ( T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 )
{
struct V_1 * V_2 = F_128 ( V_27 ) ;
struct V_86 * V_348 ;
int V_367 , V_66 ;
int V_88 ;
F_40 ( ( L_145 , V_27 -> V_46 , V_2 ? F_60 ( V_2 ) : - 1 ) ) ;
V_367 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_367 == V_47 ) {
F_40 ( ( L_146 , V_367 ) ) ;
return 0 ;
}
V_88 = F_228 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) return V_88 ;
V_27 -> V_46 = V_47 ;
if ( V_66 ) {
F_229 ( V_363 ) ;
F_229 ( V_364 ) ;
F_243 ( V_3 , V_27 ) ;
if ( V_367 != V_163 )
F_90 ( V_27 , 1 , V_27 -> V_150 ) ;
V_2 -> V_311 . V_312 = NULL ;
V_27 -> V_151 = NULL ;
return 0 ;
}
V_348 = V_2 == V_3 ? V_87 : F_119 ( V_2 ) ;
if ( V_2 == V_3 ) {
F_230 ( V_87 ) -> V_366 = 1 ;
F_40 ( ( L_147 , F_60 ( V_2 ) ) ) ;
}
F_243 ( V_2 , V_27 ) ;
if ( V_367 != V_163 )
F_90 ( V_27 , 0 , V_27 -> V_150 ) ;
V_27 -> V_55 = V_56 ;
F_53 ( V_27 , - 1 ) ;
V_2 -> V_311 . V_11 &= ~ V_365 ;
V_2 -> V_311 . V_312 = NULL ;
V_27 -> V_151 = NULL ;
F_217 ( V_2 , 0 ) ;
V_27 -> V_322 = V_368 ;
V_27 -> V_321 = 0 ;
V_27 -> V_162 = 0 ;
F_40 ( ( L_148 , F_60 ( V_2 ) ) ) ;
return 0 ;
}
void
F_244 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
unsigned long V_11 ;
struct V_86 * V_87 = F_119 ( V_2 ) ;
int V_88 , V_155 ;
int V_369 = 0 ;
V_27 = F_58 ( V_2 ) ;
F_103 ( V_27 , V_11 ) ;
F_40 ( ( L_149 , V_27 -> V_46 , F_60 ( V_2 ) ) ) ;
V_155 = V_27 -> V_46 ;
switch( V_155 ) {
case V_47 :
F_63 ( V_67 L_150 , F_60 ( V_2 ) ) ;
break;
case V_275 :
case V_68 :
V_88 = F_123 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) {
F_63 ( V_67 L_151 , F_60 ( V_2 ) , V_155 , V_88 ) ;
}
F_40 ( ( L_152 , V_155 ) ) ;
F_245 ( V_27 ) ;
break;
case V_163 :
V_88 = F_123 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) {
F_63 ( V_67 L_151 , F_60 ( V_2 ) , V_155 , V_88 ) ;
}
V_369 = 1 ;
break;
default:
F_63 ( V_67 L_153 , F_60 ( V_2 ) , V_155 ) ;
break;
}
F_106 ( V_27 , V_11 ) ;
{ T_26 V_65 = F_21 () ;
F_246 ( V_65 & ( V_17 | V_16 ) ) ;
F_246 ( F_120 () ) ;
F_246 ( F_230 ( V_87 ) -> V_350 ) ;
F_246 ( F_230 ( V_87 ) -> V_349 ) ;
}
if ( V_369 ) F_55 ( V_27 ) ;
}
static int
F_247 ( T_1 * V_27 , int V_143 , unsigned long V_11 )
{
struct V_1 * V_2 ;
int V_155 , V_370 ;
V_371:
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
V_2 -> V_155 , F_248 ( V_143 ) ) ) ;
if ( V_2 == V_3 || V_27 -> V_50 ) return 0 ;
switch( V_155 ) {
case V_47 :
return 0 ;
case V_163 :
F_40 ( ( L_156 , V_143 ) ) ;
return - V_106 ;
case V_68 :
if ( V_143 != V_372 ) return 0 ;
}
if ( F_248 ( V_143 ) ) {
if ( ! F_180 ( V_2 ) ) {
F_40 ( ( L_157 , F_60 ( V_2 ) ) ) ;
return - V_108 ;
}
V_370 = V_155 ;
F_106 ( V_27 , V_11 ) ;
F_181 ( V_2 , 0 ) ;
F_103 ( V_27 , V_11 ) ;
if ( V_27 -> V_46 != V_370 ) {
F_40 ( ( L_158 , V_370 , V_27 -> V_46 ) ) ;
goto V_371;
}
}
return 0 ;
}
T_27 long
F_249 ( int V_144 , int V_143 , void T_8 * V_91 , int V_245 )
{
struct V_125 * V_125 = NULL ;
T_1 * V_27 = NULL ;
unsigned long V_11 = 0UL ;
void * V_373 = NULL ;
long V_88 ;
T_9 V_374 , V_235 , V_375 = 0 ;
int V_376 , V_377 = 0 , V_378 = 0 , V_379 ;
int (* F_250)( T_1 * V_27 , void * V_91 , int V_245 , struct V_86 * V_87 );
int (* F_251)( void * V_91 , T_9 * V_235 );
#define F_252 4096
if ( F_203 ( V_29 == NULL ) ) return - V_380 ;
if ( F_203 ( V_143 < 0 || V_143 >= V_381 ) ) {
F_40 ( ( L_159 , V_143 ) ) ;
return - V_106 ;
}
F_250 = V_382 [ V_143 ] . V_383 ;
V_376 = V_382 [ V_143 ] . V_384 ;
V_374 = V_382 [ V_143 ] . V_385 ;
F_251 = V_382 [ V_143 ] . V_386 ;
V_379 = V_382 [ V_143 ] . V_379 ;
if ( F_203 ( F_250 == NULL ) ) {
F_40 ( ( L_159 , V_143 ) ) ;
return - V_106 ;
}
F_40 ( ( L_160 ,
F_253 ( V_143 ) ,
V_143 ,
V_376 ,
V_374 ,
V_245 ) ) ;
if ( F_203 ( ( V_376 == V_387 && V_245 <= 0 ) || ( V_376 > 0 && V_376 != V_245 ) ) )
return - V_106 ;
V_388:
V_235 = V_375 + V_374 * V_245 ;
if ( F_203 ( V_235 > F_252 ) ) {
F_63 ( V_67 L_161 , F_60 ( V_3 ) , V_235 ) ;
return - V_389 ;
}
if ( F_198 ( V_245 && V_373 == NULL ) ) {
V_373 = F_254 ( F_252 , V_45 ) ;
if ( V_373 == NULL ) return - V_179 ;
}
V_88 = - V_138 ;
if ( V_235 && F_255 ( V_373 , V_91 , V_235 ) ) {
F_40 ( ( L_162 , V_235 , V_91 ) ) ;
goto V_390;
}
if ( V_377 == 0 && F_251 ) {
V_88 = (* F_251)( V_373 , & V_375 ) ;
if ( V_88 ) goto V_390;
V_377 = 1 ;
F_40 ( ( L_163 , V_235 , V_375 ) ) ;
if ( F_198 ( V_375 ) ) goto V_388;
}
if ( F_203 ( ( V_379 & V_391 ) == 0 ) ) goto V_392;
V_88 = - V_147 ;
V_125 = F_256 ( V_144 ) ;
if ( F_203 ( V_125 == NULL ) ) {
F_40 ( ( L_164 , V_144 ) ) ;
goto V_390;
}
if ( F_203 ( F_102 ( V_125 ) == 0 ) ) {
F_40 ( ( L_165 , V_144 ) ) ;
goto V_390;
}
V_27 = V_125 -> V_129 ;
if ( F_203 ( V_27 == NULL ) ) {
F_40 ( ( L_166 , V_144 ) ) ;
goto V_390;
}
F_216 ( & V_27 -> V_46 ) ;
F_103 ( V_27 , V_11 ) ;
V_88 = F_247 ( V_27 , V_143 , V_11 ) ;
if ( F_203 ( V_88 ) ) goto V_136;
V_392:
V_88 = (* F_250)( V_27 , V_373 , V_245 , F_119 ( V_3 ) ) ;
V_378 = 1 ;
V_136:
if ( F_198 ( V_27 ) ) {
F_40 ( ( L_167 ) ) ;
F_106 ( V_27 , V_11 ) ;
}
if ( V_378 && F_257 ( V_143 ) && F_110 ( V_91 , V_373 , V_374 * V_245 ) ) V_88 = - V_138 ;
V_390:
if ( V_125 )
F_258 ( V_125 ) ;
F_56 ( V_373 ) ;
F_40 ( ( L_168 , F_253 ( V_143 ) , V_88 ) ) ;
return V_88 ;
}
static void
F_259 ( T_1 * V_27 , unsigned long V_260 , struct V_86 * V_87 )
{
T_4 * V_84 = V_27 -> V_166 ;
T_5 V_316 ;
int V_155 ;
int V_88 = 0 ;
V_155 = V_27 -> V_46 ;
if ( F_215 ( V_27 ) ) {
V_316 . V_317 . V_318 = 0 ;
V_316 . V_317 . V_319 = 0 ;
if ( V_155 == V_275 )
V_88 = F_76 ( V_84 , V_3 , & V_316 , V_27 -> V_164 , V_87 ) ;
else
V_88 = F_75 ( V_84 , V_3 , & V_316 , V_27 -> V_164 , V_87 ) ;
} else {
V_316 . V_317 . V_318 = 0 ;
V_316 . V_317 . V_319 = 1 ;
}
if ( V_88 == 0 ) {
if ( V_316 . V_317 . V_319 ) {
F_195 ( V_27 , & V_260 , V_320 ) ;
}
if ( V_316 . V_317 . V_318 == 0 ) {
F_40 ( ( L_169 ) ) ;
if ( V_27 -> V_46 == V_68 ) F_62 ( V_3 ) ;
} else {
F_40 ( ( L_170 ) ) ;
}
V_27 -> V_46 = V_275 ;
}
}
static void
F_260 ( T_1 * V_27 , struct V_86 * V_87 )
{
int V_88 ;
F_40 ( ( L_171 , F_60 ( V_3 ) ) ) ;
V_88 = F_123 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) {
F_63 ( V_67 L_172 , F_60 ( V_3 ) , V_88 ) ;
}
F_261 ( & V_27 -> V_58 ) ;
}
void
F_262 ( void )
{
T_1 * V_27 ;
struct V_86 * V_87 ;
unsigned long V_11 , V_393 ;
unsigned long V_260 ;
unsigned int V_394 ;
int V_88 ;
V_27 = F_58 ( V_3 ) ;
if ( V_27 == NULL ) {
F_63 ( V_67 L_173 ,
F_60 ( V_3 ) ) ;
return;
}
F_103 ( V_27 , V_11 ) ;
F_217 ( V_3 , 0 ) ;
V_87 = F_119 ( V_3 ) ;
V_394 = V_27 -> V_322 ;
V_27 -> V_322 = V_368 ;
V_260 = V_27 -> V_293 [ 0 ] ;
F_40 ( ( L_174 , V_394 , V_27 -> V_46 ) ) ;
if ( V_27 -> V_162 || V_27 -> V_46 == V_163 )
goto V_395;
if ( V_394 == V_323 )
goto V_396;
F_106 ( V_27 , V_11 ) ;
F_263 () ;
F_40 ( ( L_175 ) ) ;
V_88 = F_264 ( & V_27 -> V_54 ) ;
F_40 ( ( L_176 , V_88 ) ) ;
F_103 ( V_27 , V_393 ) ;
V_260 = V_27 -> V_293 [ 0 ] ;
if ( V_27 -> V_162 ) {
V_395:
F_40 ( ( L_177 ) ) ;
F_260 ( V_27 , V_87 ) ;
goto V_397;
}
if ( V_88 < 0 )
goto V_397;
V_396:
F_259 ( V_27 , V_260 , V_87 ) ;
V_27 -> V_293 [ 0 ] = 0UL ;
V_397:
F_106 ( V_27 , V_11 ) ;
}
static int
F_265 ( T_1 * V_27 , T_2 * V_37 )
{
if ( V_27 -> V_46 == V_163 ) {
F_40 ( ( L_178 ) ) ;
return 0 ;
}
F_40 ( ( L_179 ) ) ;
if ( V_37 ) F_261 ( & V_27 -> V_57 ) ;
F_266 ( & V_27 -> V_146 , V_398 , V_399 ) ;
return 0 ;
}
static int
F_267 ( T_1 * V_27 , unsigned long V_400 )
{
T_2 * V_37 = NULL ;
if ( V_27 -> V_52 == 0 ) {
V_37 = F_39 ( V_27 ) ;
if ( V_37 == NULL ) {
F_63 ( V_67 L_180 ) ;
return - 1 ;
}
V_37 -> V_401 . V_39 = V_402 ;
V_37 -> V_401 . V_137 = V_27 -> V_140 ;
V_37 -> V_401 . V_403 = 0 ;
V_37 -> V_401 . V_404 [ 0 ] = V_400 ;
V_37 -> V_401 . V_404 [ 1 ] = 0UL ;
V_37 -> V_401 . V_404 [ 2 ] = 0UL ;
V_37 -> V_401 . V_404 [ 3 ] = 0UL ;
V_37 -> V_401 . V_405 = 0UL ;
}
F_40 ( ( L_181 ,
V_37 ,
V_27 -> V_52 ,
V_27 -> V_140 ,
V_400 ) ) ;
return F_265 ( V_27 , V_37 ) ;
}
static int
F_245 ( T_1 * V_27 )
{
T_2 * V_37 ;
V_37 = F_39 ( V_27 ) ;
if ( V_37 == NULL ) {
F_63 ( V_67 L_182 ) ;
return - 1 ;
}
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_406 . V_39 = V_407 ;
V_37 -> V_406 . V_137 = V_27 -> V_140 ;
V_37 -> V_401 . V_405 = 0UL ;
F_40 ( ( L_183 ,
V_37 ,
V_27 -> V_52 ,
V_27 -> V_140 ) ) ;
return F_265 ( V_27 , V_37 ) ;
}
static void F_268 ( struct V_1 * V_2 , T_1 * V_27 ,
unsigned long V_408 , struct V_86 * V_87 )
{
T_28 * V_409 ;
unsigned long V_59 ;
unsigned long V_410 , V_30 , V_411 ;
unsigned long V_412 = 0UL , V_400 = 0UL , V_265 = 0UL , V_262 ;
unsigned long V_413 ;
T_5 V_414 ;
unsigned int V_24 , V_415 ;
int V_416 = 0 ;
if ( F_203 ( V_27 -> V_46 == V_163 ) ) goto V_417;
if ( F_203 ( ( V_408 & 0x1 ) == 0 ) ) goto V_418;
V_413 = F_269 () ;
V_59 = V_408 >> V_63 ;
V_30 = V_29 -> V_30 ;
V_415 = F_215 ( V_27 ) ;
F_59 ( ( L_184
L_185 ,
V_408 ,
V_2 ? F_60 ( V_2 ) : - 1 ,
( V_87 ? V_87 -> V_419 : 0 ) ,
F_131 ( V_27 ) ? L_186 : L_187 ,
V_27 -> V_61 [ 0 ] ) ) ;
for ( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1 ) == 0 ) continue;
V_410 = V_411 = V_27 -> V_28 [ V_24 ] . V_20 ;
V_411 += 1 + V_30 ;
V_27 -> V_28 [ V_24 ] . V_20 = V_411 ;
if ( F_198 ( V_410 > V_411 ) ) {
V_400 |= 1UL << V_24 ;
if ( F_207 ( V_27 , V_24 ) ) V_412 |= 1UL << V_24 ;
}
F_59 ( ( L_188 ,
V_24 ,
V_411 ,
V_410 ,
F_36 ( V_24 ) & V_30 ,
V_400 ,
V_412 ) ) ;
}
if ( V_400 == 0UL ) return;
V_414 . V_20 = 0 ;
V_262 = 0UL ;
if ( V_415 ) {
unsigned long V_420 , V_421 ;
unsigned long V_422 ;
int V_423 , V_424 , V_88 = 0 ;
int V_425 = F_87 () ;
V_422 = V_400 >> V_63 ;
V_409 = & V_27 -> V_426 ;
F_216 ( V_27 -> V_164 ) ;
for( V_24 = V_63 ; V_422 && V_88 == 0 ; V_24 ++ , V_422 >>= 1 ) {
V_59 = 1UL << V_24 ;
if ( ( V_422 & 0x1 ) == 0 ) continue;
V_409 -> V_427 = ( unsigned char ) V_24 ;
V_409 -> V_412 = V_412 & V_59 ? 1 : 0 ;
V_409 -> V_428 = 0 ;
V_409 -> V_414 . V_20 = 0 ;
V_409 -> V_265 [ 0 ] = V_265 = V_27 -> V_28 [ V_24 ] . V_265 [ 0 ] ;
V_409 -> V_429 = V_27 -> V_28 [ V_24 ] . V_20 ;
V_409 -> V_430 = V_27 -> V_28 [ V_24 ] . V_259 ;
V_409 -> V_431 = V_27 -> V_28 [ V_24 ] . V_291 ;
if ( V_265 ) {
for( V_423 = 0 , V_424 = 0 ; V_265 ; V_423 ++ , V_265 >>= 1 ) {
if ( ( V_265 & 0x1 ) == 0 ) continue;
V_409 -> V_432 [ V_424 ++ ] = F_61 ( V_423 ) ? F_35 ( V_27 , V_423 ) : F_36 ( V_423 ) ;
F_59 ( ( L_189 , V_424 - 1 , V_423 , V_409 -> V_432 [ V_424 - 1 ] ) ) ;
}
}
V_326 [ V_425 ] . V_433 ++ ;
V_420 = F_269 () ;
V_88 = (* V_27 -> V_166 -> V_107 )( V_2 , V_27 -> V_164 , V_409 , V_87 , V_413 ) ;
V_421 = F_269 () ;
V_414 . V_317 . V_434 |= V_409 -> V_414 . V_317 . V_434 ;
V_414 . V_317 . V_435 |= V_409 -> V_414 . V_317 . V_435 ;
V_414 . V_317 . V_318 |= V_409 -> V_414 . V_317 . V_318 ;
if ( V_409 -> V_414 . V_317 . V_319 ) V_262 |= V_59 ;
V_326 [ V_425 ] . V_436 += V_421 - V_420 ;
}
if ( V_88 && V_422 ) {
F_40 ( ( L_190 ,
V_422 << V_63 ) ) ;
}
V_400 &= ~ V_262 ;
} else {
V_414 . V_317 . V_434 = V_412 ? 1 : 0 ;
V_414 . V_317 . V_435 = V_412 ? 1 : 0 ;
V_414 . V_317 . V_318 = V_412 ? 1 : 0 ;
V_414 . V_317 . V_319 = V_412 ? 0 : 1 ;
if ( V_412 == 0 ) V_262 = V_400 ;
}
F_59 ( ( L_191 , V_400 , V_262 ) ) ;
if ( V_262 ) {
unsigned long V_437 = V_262 ;
F_195 ( V_27 , & V_437 , V_438 ) ;
}
if ( V_412 && V_414 . V_317 . V_434 ) {
V_27 -> V_293 [ 0 ] = V_400 ;
if ( F_131 ( V_27 ) == 0 && V_414 . V_317 . V_435 ) {
V_27 -> V_322 = V_439 ;
F_217 ( V_2 , 1 ) ;
F_218 ( V_2 ) ;
}
V_416 = 1 ;
}
F_59 ( ( L_192 ,
F_120 () ? F_60 ( F_120 () ) : - 1 ,
F_270 ( V_2 ) ,
V_27 -> V_322 ,
V_400 ,
V_412 ,
V_414 . V_317 . V_318 ? 1 : 0 ) ) ;
if ( V_414 . V_317 . V_318 ) {
F_57 ( V_2 ) ;
V_27 -> V_46 = V_68 ;
V_27 -> V_321 = 1 ;
}
if ( V_416 ) F_267 ( V_27 , V_412 ) ;
return;
V_418:
F_63 ( V_67 L_193 ,
F_87 () ,
V_2 ? F_60 ( V_2 ) : - 1 ,
V_408 ) ;
return;
V_417:
F_40 ( ( L_194 , V_2 ? F_60 ( V_2 ) : - 1 ) ) ;
F_19 () ;
F_230 ( V_87 ) -> V_350 = 0 ;
F_230 ( V_87 ) -> V_366 = 1 ;
return;
}
static int
F_271 ( void * V_91 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_1 * V_27 ;
unsigned long V_11 ;
T_26 V_408 ;
int V_425 = F_87 () ;
int V_440 = 0 ;
V_326 [ V_425 ] . V_441 ++ ;
V_408 = F_272 ( 0 ) ;
V_2 = F_120 () ;
V_27 = F_121 () ;
if ( F_273 ( V_408 ) && V_2 ) {
if ( ! V_27 ) goto V_442;
if ( V_27 -> V_50 == 0 && ( V_2 -> V_311 . V_11 & V_365 ) == 0 )
goto V_443;
F_274 ( V_27 , V_11 ) ;
F_268 ( V_2 , V_27 , V_408 , V_87 ) ;
F_275 ( V_27 , V_11 ) ;
} else {
V_326 [ V_425 ] . V_444 ++ ;
V_440 = - 1 ;
}
F_28 () ;
return V_440 ;
V_442:
F_63 ( V_111 L_195 ,
V_425 , F_60 ( V_2 ) ) ;
F_28 () ;
return - 1 ;
V_443:
F_63 ( V_111 L_196 ,
V_425 ,
F_60 ( V_2 ) ) ;
F_28 () ;
return - 1 ;
}
static T_29
F_276 ( int V_445 , void * V_91 )
{
unsigned long V_420 , V_446 ;
unsigned long V_447 , V_448 ;
int V_425 ;
int V_88 ;
struct V_86 * V_87 = F_277 () ;
V_425 = F_278 () ;
if ( F_198 ( ! V_449 ) ) {
V_447 = V_326 [ V_425 ] . V_328 ;
V_448 = V_326 [ V_425 ] . V_450 ;
V_420 = F_269 () ;
V_88 = F_271 ( V_91 , V_87 ) ;
V_446 = F_269 () ;
if ( F_198 ( V_88 == 0 ) ) {
V_446 -= V_420 ;
if ( V_446 < V_447 ) V_326 [ V_425 ] . V_328 = V_446 ;
if ( V_446 > V_448 ) V_326 [ V_425 ] . V_450 = V_446 ;
V_326 [ V_425 ] . V_451 += V_446 ;
}
}
else {
(* V_449 -> V_452 )( V_445 , V_91 , V_87 ) ;
}
F_279 () ;
return V_453 ;
}
static void *
F_280 ( struct V_454 * V_324 , T_10 * V_100 )
{
if ( * V_100 == 0 ) {
return V_455 ;
}
while ( * V_100 <= V_456 ) {
if ( F_281 ( * V_100 - 1 ) ) {
return ( void * ) * V_100 ;
}
++ * V_100 ;
}
return NULL ;
}
static void *
F_282 ( struct V_454 * V_324 , void * V_300 , T_10 * V_100 )
{
++ * V_100 ;
return F_280 ( V_324 , V_100 ) ;
}
static void
F_283 ( struct V_454 * V_324 , void * V_300 )
{
}
static void
F_284 ( struct V_454 * V_324 )
{
struct V_99 * V_100 ;
T_4 * V_101 ;
unsigned long V_11 ;
F_285 ( V_324 ,
L_197
L_198
L_199
L_200
L_201
L_202 ,
V_457 , V_458 ,
V_29 -> V_459 ,
V_276 . V_460 > 0 ? L_203 : L_204 ,
V_276 . V_271 > 0 ? L_203 : L_204 ,
V_29 -> V_30 ,
V_29 -> V_11 ) ;
F_86 ( V_11 ) ;
F_285 ( V_324 ,
L_205
L_206
L_207
L_208 ,
V_113 . V_115 ,
V_113 . V_114 ,
V_113 . V_116 ,
V_113 . V_315 ) ;
F_89 ( V_11 ) ;
F_9 ( & V_104 ) ;
F_78 (pos, &pfm_buffer_fmt_list) {
V_101 = F_79 ( V_100 , T_4 , V_102 ) ;
F_285 ( V_324 , L_209 ,
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
F_286 ( struct V_454 * V_324 , void * V_300 )
{
unsigned long V_65 ;
unsigned int V_24 ;
int V_90 ;
if ( V_300 == V_455 ) {
F_284 ( V_324 ) ;
return 0 ;
}
V_90 = ( long ) V_300 - 1 ;
F_285 ( V_324 ,
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
V_90 , V_326 [ V_90 ] . V_441 ,
V_90 , V_326 [ V_90 ] . V_451 ,
V_90 , V_326 [ V_90 ] . V_328 ,
V_90 , V_326 [ V_90 ] . V_450 ,
V_90 , V_326 [ V_90 ] . V_433 ,
V_90 , V_326 [ V_90 ] . V_436 ,
V_90 , V_326 [ V_90 ] . V_444 ,
V_90 , V_326 [ V_90 ] . V_461 ,
V_90 , F_287 ( V_462 , V_90 ) & V_363 ? 1 : 0 ,
V_90 , F_287 ( V_462 , V_90 ) & V_69 ? 1 : 0 ,
V_90 , F_287 ( V_462 , V_90 ) & V_364 ? 1 : 0 ,
V_90 , F_287 ( V_463 , V_90 ) ? F_287 ( V_463 , V_90 ) -> V_241 : - 1 ,
V_90 , F_287 ( V_464 , V_90 ) ,
V_90 , F_287 ( V_465 , V_90 ) ) ;
if ( F_288 () == 1 && V_276 . V_325 > 0 ) {
V_65 = F_21 () ;
F_27 () ;
F_285 ( V_324 ,
L_224
L_225 ,
V_90 , V_65 ,
V_90 , F_272 ( 0 ) ) ;
for ( V_24 = 0 ; F_175 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_289 ( V_24 ) == 0 ) continue;
F_285 ( V_324 ,
L_226
L_227 ,
V_90 , V_24 , F_272 ( V_24 ) ,
V_90 , V_24 , F_36 ( V_24 ) ) ;
}
}
return 0 ;
}
static int
F_290 ( struct V_158 * V_158 , struct V_125 * V_125 )
{
return F_291 ( V_125 , & V_466 ) ;
}
void
F_292 ( struct V_1 * V_2 , unsigned long V_148 , int V_467 )
{
struct V_86 * V_87 ;
unsigned long V_468 ;
unsigned long V_469 ;
V_469 = V_148 & V_69 ? 1 : 0 ;
if ( ( V_148 & V_364 ) == 0 || V_2 -> V_241 ) {
V_87 = F_119 ( V_2 ) ;
F_230 ( V_87 ) -> V_349 = V_467 ? V_469 : 0 ;
return;
}
if ( V_469 ) {
V_468 = F_22 ( V_70 ) ;
if ( V_467 ) {
F_24 ( V_70 , V_468 & ~ V_71 ) ;
F_14 () ;
F_16 () ;
return;
}
F_24 ( V_70 , V_468 | V_71 ) ;
F_17 () ;
F_16 () ;
}
}
static void
F_293 ( T_1 * V_27 , struct V_86 * V_87 )
{
struct V_1 * V_2 = V_27 -> V_151 ;
F_230 ( V_87 ) -> V_350 = 0 ;
F_230 ( V_87 ) -> V_366 = 1 ;
if ( F_120 () == V_2 ) {
F_40 ( ( L_228 ,
F_60 ( V_27 -> V_151 ) ) ) ;
F_242 ( NULL , NULL ) ;
}
F_217 ( V_2 , 0 ) ;
V_2 -> V_311 . V_312 = NULL ;
V_2 -> V_311 . V_11 &= ~ V_365 ;
F_40 ( ( L_229 , F_60 ( V_2 ) ) ) ;
}
void
F_294 ( struct V_1 * V_2 )
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
F_293 ( V_27 , V_87 ) ;
F_246 ( V_27 -> V_164 ) ;
F_10 ( V_27 , V_11 ) ;
F_55 ( V_27 ) ;
return;
}
F_27 () ;
V_65 = F_21 () ;
F_246 ( V_65 & ( V_470 ) ) ;
F_19 () ;
V_27 -> V_351 = V_65 & V_17 ;
F_242 ( NULL , NULL ) ;
F_65 ( V_27 -> V_80 , V_27 -> V_61 [ 0 ] ) ;
V_27 -> V_64 [ 0 ] = F_272 ( 0 ) ;
if ( V_27 -> V_64 [ 0 ] & ~ 0x1UL ) F_28 () ;
F_10 ( V_27 , V_11 ) ;
}
void
F_294 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
T_26 V_65 ;
V_27 = F_58 ( V_2 ) ;
if ( V_27 == NULL ) return;
V_65 = F_21 () ;
F_246 ( V_65 & ( V_470 ) ) ;
F_19 () ;
V_27 -> V_351 = V_65 & V_17 ;
}
static void
F_241 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
unsigned long V_11 ;
{ T_26 V_65 = F_21 () ;
F_246 ( V_65 & V_17 ) ;
}
V_27 = F_58 ( V_2 ) ;
F_103 ( V_27 , V_11 ) ;
F_242 ( NULL , NULL ) ;
F_65 ( V_27 -> V_80 , V_27 -> V_61 [ 0 ] ) ;
V_27 -> V_64 [ 0 ] = F_272 ( 0 ) ;
if ( V_27 -> V_64 [ 0 ] & ~ 0x1UL ) F_28 () ;
F_106 ( V_27 , V_11 ) ;
}
void
F_295 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
unsigned long V_471 = 0UL , V_422 = 0UL ;
unsigned long V_11 ;
T_26 V_65 , V_472 ;
int V_473 ;
V_27 = F_58 ( V_2 ) ;
if ( F_203 ( V_27 == NULL ) ) return;
F_246 ( F_120 () ) ;
if ( F_203 ( ( V_2 -> V_311 . V_11 & V_365 ) == 0 ) ) return;
V_11 = F_8 ( V_27 ) ;
V_65 = F_21 () ;
V_473 = V_29 -> V_11 & V_474 ;
F_246 ( V_65 & ( V_17 | V_16 ) ) ;
F_246 ( V_65 & V_470 ) ;
if ( F_203 ( V_27 -> V_46 == V_163 ) ) {
struct V_86 * V_87 = F_119 ( V_2 ) ;
F_246 ( V_27 -> V_164 ) ;
F_293 ( V_27 , V_87 ) ;
F_10 ( V_27 , V_11 ) ;
F_55 ( V_27 ) ;
return;
}
if ( V_27 -> V_73 ) {
F_29 ( V_27 -> V_74 , V_29 -> V_75 ) ;
F_32 ( V_27 -> V_76 , V_29 -> V_77 ) ;
}
V_472 = V_27 -> V_351 ;
if ( F_296 ( V_27 ) == F_87 () && V_27 -> V_55 == F_297 () ) {
V_471 = V_27 -> V_295 [ 0 ] ;
V_422 = V_27 -> V_305 [ 0 ] ;
} else {
V_422 = V_276 . V_460 ? V_27 -> V_61 [ 0 ] : V_27 -> V_79 [ 0 ] ;
V_471 = V_27 -> V_81 [ 0 ] ;
}
if ( V_422 ) F_66 ( V_27 -> V_80 , V_422 ) ;
if ( V_471 ) F_69 ( V_27 -> V_64 , V_471 ) ;
if ( F_203 ( F_273 ( V_27 -> V_64 [ 0 ] ) ) ) {
F_26 ( 0 , V_27 -> V_64 [ 0 ] ) ;
F_27 () ;
V_27 -> V_64 [ 0 ] = 0UL ;
if ( V_473 ) F_298 ( V_475 ) ;
V_326 [ F_87 () ] . V_461 ++ ;
}
V_27 -> V_295 [ 0 ] = 0UL ;
V_27 -> V_305 [ 0 ] = 0UL ;
F_53 ( V_27 , F_87 () ) ;
F_239 () ;
F_240 ( V_27 ) ;
F_242 ( V_2 , V_27 ) ;
if ( F_198 ( V_472 ) ) F_20 () ;
F_10 ( V_27 , V_11 ) ;
}
void
F_295 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
struct V_1 * V_149 ;
unsigned long V_422 , V_471 ;
T_26 V_65 , V_472 ;
int V_473 ;
V_149 = F_120 () ;
V_27 = F_58 ( V_2 ) ;
V_65 = F_21 () ;
F_246 ( V_65 & ( V_17 | V_16 ) ) ;
F_246 ( V_65 & V_470 ) ;
if ( V_27 -> V_73 ) {
F_29 ( V_27 -> V_74 , V_29 -> V_75 ) ;
F_32 ( V_27 -> V_76 , V_29 -> V_77 ) ;
}
V_472 = V_27 -> V_351 ;
V_473 = V_29 -> V_11 & V_474 ;
if ( F_198 ( V_149 == V_2 ) ) {
if ( F_198 ( V_472 ) ) F_20 () ;
return;
}
if ( V_149 ) F_241 ( V_149 ) ;
V_422 = V_276 . V_460 ? V_27 -> V_61 [ 0 ] : V_27 -> V_79 [ 0 ] ;
V_471 = V_27 -> V_81 [ 0 ] ;
F_66 ( V_27 -> V_80 , V_422 ) ;
F_69 ( V_27 -> V_64 , V_471 ) ;
if ( F_203 ( F_273 ( V_27 -> V_64 [ 0 ] ) ) ) {
F_26 ( 0 , V_27 -> V_64 [ 0 ] ) ;
F_27 () ;
V_27 -> V_64 [ 0 ] = 0UL ;
if ( V_473 ) F_298 ( V_475 ) ;
V_326 [ F_87 () ] . V_461 ++ ;
}
F_242 ( V_2 , V_27 ) ;
if ( F_198 ( V_472 ) ) F_20 () ;
}
static void
F_243 ( struct V_1 * V_2 , T_1 * V_27 )
{
T_26 V_408 ;
unsigned long V_476 , V_20 , V_477 , V_30 ;
int V_24 , V_269 = 0 ;
int V_478 ;
V_478 = V_27 -> V_151 == V_2 ? 1 : 0 ;
V_269 = ( F_120 () == V_2 ) || ( V_27 -> V_50 && V_27 -> V_150 == F_87 () ) ;
if ( V_269 ) {
F_242 ( NULL , NULL ) ;
F_40 ( ( L_230 ) ) ;
F_27 () ;
V_408 = F_272 ( 0 ) ;
F_28 () ;
} else {
V_408 = V_27 -> V_64 [ 0 ] ;
V_27 -> V_64 [ 0 ] = 0 ;
}
V_30 = V_29 -> V_30 ;
V_476 = V_27 -> V_61 [ 0 ] ;
F_40 ( ( L_231 , V_478 , V_30 , V_476 ) ) ;
for ( V_24 = 0 ; V_476 ; V_24 ++ , V_476 >>= 1 ) {
if ( ( V_476 & 0x1 ) == 0 ) continue;
V_20 = V_477 = V_269 ? F_36 ( V_24 ) : V_27 -> V_80 [ V_24 ] ;
if ( F_61 ( V_24 ) ) {
F_40 ( ( L_232 ,
F_60 ( V_2 ) ,
V_24 ,
V_27 -> V_28 [ V_24 ] . V_20 ,
V_20 & V_30 ) ) ;
V_20 = V_27 -> V_28 [ V_24 ] . V_20 + ( V_20 & V_30 ) ;
V_477 = 0UL ;
if ( V_408 & ( 1UL << V_24 ) ) {
V_20 += 1 + V_30 ;
F_40 ( ( L_233 , F_60 ( V_2 ) , V_24 ) ) ;
}
}
F_40 ( ( L_234 , F_60 ( V_2 ) , V_24 , V_20 , V_477 ) ) ;
if ( V_478 ) V_27 -> V_80 [ V_24 ] = V_477 ;
V_27 -> V_28 [ V_24 ] . V_20 = V_20 ;
}
}
static void
F_299 ( void * V_13 )
{
struct V_86 * V_87 ;
V_87 = F_119 ( V_3 ) ;
F_40 ( ( L_235 ) ) ;
F_19 () ;
F_14 () ;
F_230 ( V_87 ) -> V_349 = 0 ;
F_25 () ;
F_27 () ;
}
void
F_300 ( void * V_13 )
{
struct V_86 * V_87 ;
V_87 = F_119 ( V_3 ) ;
F_40 ( ( L_235 ) ) ;
F_19 () ;
F_14 () ;
F_230 ( V_87 ) -> V_349 = 0 ;
F_28 () ;
F_27 () ;
}
int
F_301 ( T_30 * V_479 )
{
int V_88 , V_24 ;
int V_480 ;
if ( V_479 == NULL || V_479 -> V_452 == NULL ) return - V_106 ;
if ( V_449 ) return - V_108 ;
if ( ! F_302 ( & V_481 ) ) {
return - V_108 ;
}
F_303 (reserve_cpu) {
V_88 = F_85 ( NULL , 1 , V_480 ) ;
if ( V_88 ) goto V_482;
}
V_88 = F_304 ( F_299 , NULL , 1 ) ;
if ( V_88 ) {
F_40 ( ( L_236 , V_88 ) ) ;
goto V_482;
}
V_449 = V_479 ;
F_11 ( & V_481 ) ;
return 0 ;
V_482:
F_303 (i) {
if ( V_24 >= V_480 ) break;
F_90 ( NULL , 1 , V_24 ) ;
}
F_11 ( & V_481 ) ;
return V_88 ;
}
int
F_305 ( T_30 * V_479 )
{
int V_24 ;
int V_88 ;
if ( V_479 == NULL ) return - V_106 ;
if ( V_449 != V_479 ) return - V_106 ;
if ( ! F_302 ( & V_481 ) ) {
return - V_108 ;
}
V_449 = NULL ;
V_88 = F_304 ( F_300 , NULL , 1 ) ;
if ( V_88 ) {
F_40 ( ( L_236 , V_88 ) ) ;
}
F_303 (i) {
F_90 ( NULL , 1 , V_24 ) ;
}
F_11 ( & V_481 ) ;
return 0 ;
}
static int T_6
F_306 ( void )
{
T_31 * * V_242 ;
int V_483 ;
V_483 = V_484 -> V_483 ;
V_242 = V_485 ;
while( * V_242 ) {
if ( ( * V_242 ) -> V_486 ) {
if ( ( * V_242 ) -> V_486 () == 0 ) goto V_487;
} else if ( ( * V_242 ) -> V_488 == V_483 || ( * V_242 ) -> V_488 == 0xff ) {
goto V_487;
}
V_242 ++ ;
}
return - 1 ;
V_487:
V_29 = * V_242 ;
return 0 ;
}
int T_6
F_307 ( void )
{
unsigned int V_489 , V_490 , V_24 ;
F_63 ( L_237 ,
V_457 ,
V_458 ,
V_475 ) ;
if ( F_306 () ) {
F_63 ( V_111 L_238 ,
V_484 -> V_483 ) ;
return - V_491 ;
}
V_489 = 0 ;
for ( V_24 = 0 ; F_175 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_176 ( V_24 ) == 0 ) continue;
V_29 -> V_231 [ V_24 >> 6 ] |= 1UL << ( V_24 & 63 ) ;
V_489 ++ ;
}
V_29 -> V_492 = V_489 ;
V_489 = 0 ; V_490 = 0 ;
for ( V_24 = 0 ; F_308 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_204 ( V_24 ) == 0 ) continue;
V_29 -> V_232 [ V_24 >> 6 ] |= 1UL << ( V_24 & 63 ) ;
V_489 ++ ;
if ( F_61 ( V_24 ) ) V_490 ++ ;
}
V_29 -> V_493 = V_489 ;
V_29 -> V_494 = V_490 ;
if ( V_29 -> V_313 ) {
if ( V_29 -> V_75 > V_495 ) {
F_63 ( V_111 L_239 , V_29 -> V_75 ) ;
V_29 = NULL ;
return - 1 ;
}
if ( V_29 -> V_77 > V_495 ) {
F_63 ( V_111 L_240 , V_29 -> V_75 ) ;
V_29 = NULL ;
return - 1 ;
}
}
F_63 ( L_241 ,
V_29 -> V_459 ,
V_29 -> V_492 ,
V_29 -> V_493 ,
V_29 -> V_494 ,
F_309 ( V_29 -> V_30 ) ) ;
if ( V_29 -> V_493 >= V_496 || V_29 -> V_492 >= V_497 ) {
F_63 ( V_67 L_242 ) ;
V_29 = NULL ;
return - 1 ;
}
V_498 = F_310 ( L_243 , V_182 , NULL , & V_499 ) ;
if ( V_498 == NULL ) {
F_63 ( V_67 L_244 ) ;
V_29 = NULL ;
return - 1 ;
}
V_500 = F_311 ( V_501 ) ;
F_51 ( & V_113 . V_502 ) ;
F_51 ( & V_104 ) ;
F_94 () ;
for( V_24 = 0 ; V_24 < V_327 ; V_24 ++ ) V_326 [ V_24 ] . V_328 = ~ 0UL ;
return 0 ;
}
void
F_312 ( void )
{
static int V_333 = 1 ;
F_14 () ;
F_19 () ;
F_28 () ;
if ( V_333 ) {
F_313 ( V_475 , & V_503 ) ;
V_333 = 0 ;
}
F_24 ( V_504 , V_475 ) ;
F_27 () ;
}
void
F_314 ( const char * V_505 )
{
struct V_1 * V_2 ;
struct V_86 * V_87 ;
T_1 * V_27 ;
unsigned long V_65 , V_468 , V_148 , V_11 ;
int V_24 , V_425 ;
F_122 ( V_11 ) ;
V_425 = F_87 () ;
V_87 = F_119 ( V_3 ) ;
V_148 = F_64 () ;
V_468 = F_22 ( V_70 ) ;
if ( V_148 == 0 && F_230 ( V_87 ) -> V_349 == 0 && ( V_468 & V_71 ) == 0 ) {
F_124 ( V_11 ) ;
return;
}
F_63 ( L_245 ,
V_425 ,
V_505 ,
F_60 ( V_3 ) ,
V_87 -> V_419 ,
V_3 -> V_506 ) ;
V_2 = F_120 () ;
V_27 = F_121 () ;
F_63 ( L_246 , V_425 , V_2 ? F_60 ( V_2 ) : - 1 , V_27 ) ;
V_65 = F_21 () ;
F_63 ( L_247 ,
V_425 ,
F_272 ( 0 ) ,
V_65 & V_16 ? 1 : 0 ,
V_65 & V_17 ? 1 : 0 ,
V_468 & V_71 ? 1 : 0 ,
V_148 ,
F_230 ( V_87 ) -> V_350 ,
F_230 ( V_87 ) -> V_349 ) ;
F_230 ( V_87 ) -> V_350 = 0 ;
F_230 ( V_87 ) -> V_349 = 0 ;
for ( V_24 = 1 ; F_175 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_176 ( V_24 ) == 0 ) continue;
F_63 ( L_248 , V_425 , V_24 , F_272 ( V_24 ) , V_24 , V_27 -> V_64 [ V_24 ] ) ;
}
for ( V_24 = 1 ; F_308 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_204 ( V_24 ) == 0 ) continue;
F_63 ( L_249 , V_425 , V_24 , F_36 ( V_24 ) , V_24 , V_27 -> V_80 [ V_24 ] ) ;
}
if ( V_27 ) {
F_63 ( L_250 ,
V_425 ,
V_27 -> V_46 ,
V_27 -> V_156 ,
V_27 -> V_164 ,
V_27 -> V_35 ,
V_27 -> V_33 ,
V_27 -> V_351 ) ;
}
F_124 ( V_11 ) ;
}
void
F_315 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_330 * V_311 ;
F_40 ( ( L_251 , F_60 ( V_2 ) ) ) ;
V_311 = & V_2 -> V_311 ;
V_311 -> V_312 = NULL ;
F_217 ( V_2 , 0 ) ;
}
T_27 long
F_249 ( int V_144 , int V_143 , void * V_91 , int V_245 )
{
return - V_380 ;
}
