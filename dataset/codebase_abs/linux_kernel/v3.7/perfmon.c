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
V_192 -> V_205 = F_155 ( V_126 ) ;
V_192 -> V_206 = V_207 | V_208 | V_209 | V_210 ;
V_192 -> V_211 = V_195 ;
V_27 -> V_164 = V_199 ;
V_27 -> V_157 = V_40 ;
F_156 ( & V_2 -> V_121 -> V_212 ) ;
V_192 -> V_213 = F_157 ( NULL , 0 , V_40 , 0 , V_214 | V_215 ) ;
if ( F_158 ( V_192 -> V_213 ) ) {
F_40 ( ( L_77 , V_40 ) ) ;
F_159 ( & V_2 -> V_121 -> V_212 ) ;
goto error;
}
V_192 -> V_216 = V_192 -> V_213 + V_40 ;
V_192 -> V_217 = V_192 -> V_213 >> V_194 ;
F_40 ( ( L_78 , V_40 , V_27 -> V_164 , V_192 -> V_213 ) ) ;
if ( F_148 ( V_192 , ( unsigned long ) V_199 , V_192 -> V_213 , V_40 ) ) {
F_40 ( ( L_79 ) ) ;
F_159 ( & V_2 -> V_121 -> V_212 ) ;
goto error;
}
F_160 ( V_121 , V_192 ) ;
F_161 ( V_192 -> V_204 , V_192 -> V_206 , V_192 -> V_205 ,
F_162 ( V_192 ) ) ;
F_159 ( & V_2 -> V_121 -> V_212 ) ;
V_27 -> V_156 = ( void * ) V_192 -> V_213 ;
* ( unsigned long * ) V_197 = V_192 -> V_213 ;
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
const struct V_218 * V_219 ;
T_13 V_220 = F_165 () ;
T_14 V_221 = F_166 () ;
int V_88 ;
F_167 () ;
V_219 = F_168 ( V_2 ) ;
F_40 ( ( L_80 ,
F_169 ( & V_222 , V_220 ) ,
F_170 ( & V_222 , V_221 ) ,
F_169 ( & V_222 , V_219 -> V_223 ) ,
F_169 ( & V_222 , V_219 -> V_224 ) ,
F_169 ( & V_222 , V_219 -> V_220 ) ,
F_170 ( & V_222 , V_219 -> V_225 ) ,
F_170 ( & V_222 , V_219 -> V_226 ) ) ) ;
V_88 = ( ( ! F_171 ( V_220 , V_219 -> V_223 ) )
|| ( ! F_171 ( V_220 , V_219 -> V_224 ) )
|| ( ! F_171 ( V_220 , V_219 -> V_220 ) )
|| ( ! F_172 ( V_221 , V_219 -> V_225 ) )
|| ( ! F_172 ( V_221 , V_219 -> V_226 ) )
|| ( ! F_172 ( V_221 , V_219 -> V_221 ) ) ) && ! F_173 ( V_227 ) ;
F_174 () ;
return V_88 ;
}
static int
F_175 ( struct V_1 * V_2 , T_15 * V_228 )
{
int V_44 ;
V_44 = V_228 -> V_44 ;
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
void * V_229 = NULL ;
void * V_230 = NULL ;
int V_88 = 0 ;
#define F_177 ( V_4 ) (pfm_buffer_fmt_t *)(a+1)
V_84 = F_80 ( V_91 -> V_231 ) ;
if ( V_84 == NULL ) {
F_40 ( ( L_82 , F_60 ( V_2 ) ) ) ;
return - V_106 ;
}
if ( V_84 -> V_232 ) V_230 = F_177 ( V_91 ) ;
V_88 = F_73 ( V_84 , V_2 , V_44 , V_90 , V_230 ) ;
F_40 ( ( L_83 , F_60 ( V_2 ) , V_44 , V_90 , V_230 , V_88 ) ) ;
if ( V_88 ) goto error;
V_27 -> V_166 = V_84 ;
V_27 -> V_165 = 1 ;
V_88 = F_72 ( V_84 , V_2 , V_44 , V_90 , V_230 , & V_40 ) ;
if ( V_88 ) goto error;
if ( V_40 ) {
V_88 = F_151 ( V_3 , V_126 , V_27 , V_40 , & V_229 ) ;
if ( V_88 ) goto error;
V_91 -> V_156 = V_229 ;
}
V_88 = F_74 ( V_84 , V_2 , V_27 -> V_164 , V_44 , V_90 , V_230 ) ;
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
V_27 -> V_81 [ 0 ] = V_29 -> V_233 [ 0 ] & ~ 0x1 ;
V_27 -> V_79 [ 0 ] = V_29 -> V_234 [ 0 ] ;
F_40 ( ( L_84 , V_27 -> V_140 , V_27 -> V_81 [ 0 ] , V_27 -> V_79 [ 0 ] ) ) ;
V_27 -> V_235 [ 0 ] = 0UL ;
V_27 -> V_236 [ 0 ] = 0UL ;
}
static int
F_182 ( void * V_91 , T_9 * V_237 )
{
T_15 * V_238 = ( T_15 * ) V_91 ;
T_4 * V_84 ;
* V_237 = 0 ;
if ( ! F_70 ( V_238 -> V_231 , V_239 ) ) return 0 ;
V_84 = F_80 ( V_238 -> V_231 ) ;
if ( V_84 == NULL ) {
F_40 ( ( L_85 ) ) ;
return - V_106 ;
}
* V_237 = V_84 -> V_232 ;
F_40 ( ( L_86 , * V_237 ) ) ;
return 0 ;
}
static int
F_183 ( T_1 * V_27 , struct V_1 * V_2 )
{
if ( V_2 -> V_121 == NULL ) {
F_40 ( ( L_87 , F_60 ( V_2 ) ) ) ;
return - V_240 ;
}
if ( F_164 ( V_2 ) ) {
F_40 ( ( L_88 , F_60 ( V_2 ) ) ) ;
return - V_240 ;
}
if ( F_131 ( V_27 ) == 0 && V_2 == V_3 ) {
F_40 ( ( L_89 , F_60 ( V_2 ) ) ) ;
return - V_106 ;
}
if ( V_2 -> V_241 == V_242 ) {
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
F_186 ( T_1 * V_27 , T_16 V_243 , struct V_1 * * V_2 )
{
struct V_1 * V_244 = V_3 ;
int V_88 ;
if ( V_243 < 2 ) return - V_240 ;
if ( V_243 != F_187 ( V_3 ) ) {
F_188 ( & V_245 ) ;
V_244 = F_189 ( V_243 ) ;
if ( V_244 ) F_190 ( V_244 ) ;
F_191 ( & V_245 ) ;
if ( V_244 == NULL ) return - V_246 ;
}
V_88 = F_183 ( V_27 , V_244 ) ;
if ( V_88 == 0 ) {
* V_2 = V_244 ;
} else if ( V_244 != V_3 ) {
F_1 ( V_244 ) ;
}
return V_88 ;
}
static int
F_192 ( T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 )
{
T_15 * V_238 = ( T_15 * ) V_91 ;
struct V_125 * V_126 ;
struct V_174 V_174 ;
int V_44 ;
int V_144 ;
int V_88 ;
V_88 = F_175 ( V_3 , V_238 ) ;
if ( V_88 < 0 )
return V_88 ;
V_44 = V_238 -> V_44 ;
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
goto V_248;
}
V_238 -> V_140 = V_27 -> V_140 = V_144 ;
if ( F_70 ( V_238 -> V_231 , V_239 ) ) {
V_88 = F_176 ( V_3 , V_126 , V_27 , V_44 , 0 , V_238 ) ;
if ( V_88 )
goto V_249;
}
F_40 ( ( L_92 ,
V_27 ,
V_44 ,
V_27 -> V_50 ,
V_27 -> V_48 ,
V_27 -> V_250 ,
V_27 -> V_52 ,
V_27 -> V_140 ) ) ;
F_178 ( V_27 ) ;
F_194 ( V_144 , V_126 ) ;
return 0 ;
V_249:
V_174 = V_126 -> V_251 ;
F_195 ( V_126 ) ;
F_147 ( & V_174 ) ;
if ( V_27 -> V_166 ) {
F_71 ( V_27 -> V_166 , V_3 , NULL , V_87 ) ;
}
V_248:
F_55 ( V_27 ) ;
error:
F_196 ( V_144 ) ;
return V_88 ;
}
static inline unsigned long
F_197 ( T_17 * V_252 , int V_253 )
{
unsigned long V_20 = V_253 ? V_252 -> V_254 : V_252 -> V_255 ;
unsigned long V_256 , V_257 = V_252 -> V_258 , V_59 = V_252 -> V_59 ;
extern unsigned long V_259 ( unsigned long V_258 ) ;
if ( V_252 -> V_11 & V_260 ) {
V_256 = V_259 ( V_257 ) ;
V_20 -= ( V_257 & V_59 ) ;
if ( ( V_59 >> 32 ) != 0 )
V_256 |= V_259 ( V_257 >> 32 ) << 32 ;
V_252 -> V_258 = V_256 ;
}
V_252 -> V_261 = V_20 ;
return V_20 ;
}
static void
F_198 ( T_1 * V_27 , unsigned long * V_262 , int V_253 )
{
unsigned long V_59 = V_262 [ 0 ] ;
unsigned long V_263 = 0UL ;
unsigned long V_20 ;
int V_24 ;
V_59 >>= V_63 ;
for( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1UL ) == 0UL ) continue;
V_27 -> V_28 [ V_24 ] . V_20 = V_20 = F_197 ( V_27 -> V_28 + V_24 , V_253 ) ;
V_263 |= V_27 -> V_28 [ V_24 ] . V_264 [ 0 ] ;
F_59 ( ( L_93 , V_253 ? L_94 : L_95 , V_24 , V_20 ) ) ;
}
for( V_24 = 0 ; V_263 ; V_24 ++ , V_263 >>= 1 ) {
if ( ( V_263 & 0x1 ) == 0 ) continue;
V_27 -> V_28 [ V_24 ] . V_20 = V_20 = F_197 ( V_27 -> V_28 + V_24 , V_253 ) ;
F_59 ( ( L_96 ,
V_253 ? L_94 : L_95 , V_24 , V_20 ) ) ;
}
}
static void
F_199 ( T_1 * V_27 , unsigned long * V_262 , int V_253 )
{
unsigned long V_59 = V_262 [ 0 ] ;
unsigned long V_263 = 0UL ;
unsigned long V_20 ;
int V_24 ;
F_59 ( ( L_97 , V_262 [ 0 ] , V_253 ) ) ;
if ( V_27 -> V_46 == V_68 ) {
F_198 ( V_27 , V_262 , V_253 ) ;
return;
}
V_59 >>= V_63 ;
for( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1UL ) == 0UL ) continue;
V_20 = F_197 ( V_27 -> V_28 + V_24 , V_253 ) ;
V_263 |= V_27 -> V_28 [ V_24 ] . V_264 [ 0 ] ;
F_59 ( ( L_93 , V_253 ? L_94 : L_95 , V_24 , V_20 ) ) ;
F_37 ( V_27 , V_24 , V_20 ) ;
}
for( V_24 = 0 ; V_263 ; V_24 ++ , V_263 >>= 1 ) {
if ( ( V_263 & 0x1 ) == 0 ) continue;
V_20 = F_197 ( V_27 -> V_28 + V_24 , V_253 ) ;
if ( F_61 ( V_24 ) ) {
F_37 ( V_27 , V_24 , V_20 ) ;
} else {
F_38 ( V_24 , V_20 ) ;
}
F_59 ( ( L_96 ,
V_253 ? L_94 : L_95 , V_24 , V_20 ) ) ;
}
F_27 () ;
}
static int
F_200 ( T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_18 * V_238 = ( T_18 * ) V_91 ;
unsigned long V_265 , V_266 ;
unsigned long V_267 , V_264 , V_234 ;
unsigned int V_268 , V_269 , V_11 , V_270 ;
int V_24 , V_271 = 0 , V_272 , V_66 , V_273 ;
int V_274 , V_275 , V_155 ;
int V_88 = - V_106 ;
T_19 V_276 ;
#define F_201 ( V_5 , T_20 , T_21 ) ((x)->ctx_fl_system ^ PMC_PM(y, z))
V_155 = V_27 -> V_46 ;
V_272 = V_155 == V_277 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_2 = V_27 -> V_151 ;
V_234 = V_29 -> V_234 [ 0 ] ;
if ( V_155 == V_163 ) return - V_106 ;
if ( V_272 ) {
if ( V_66 && V_27 -> V_150 != F_87 () ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_271 = F_120 () == V_2 || V_66 ? 1 : 0 ;
}
V_273 = V_278 . V_273 ;
for ( V_24 = 0 ; V_24 < V_247 ; V_24 ++ , V_238 ++ ) {
V_268 = V_238 -> V_279 ;
V_269 = V_238 -> V_269 ;
V_265 = V_238 -> V_280 ;
V_267 = V_238 -> V_281 [ 0 ] ;
V_264 = V_238 -> V_282 [ 0 ] ;
V_11 = 0 ;
if ( V_268 >= V_283 ) {
F_40 ( ( L_98 , V_268 ) ) ;
goto error;
}
V_270 = V_29 -> V_284 [ V_268 ] . type ;
V_266 = ( V_265 >> V_29 -> V_284 [ V_268 ] . V_285 ) & 0x1 ;
V_275 = ( V_270 & V_286 ) == V_286 ? 1 : 0 ;
V_274 = ( V_270 & V_287 ) == V_287 ? 1 : 0 ;
if ( ( V_270 & V_288 ) == 0 || ( V_270 & V_289 ) == V_289 ) {
F_40 ( ( L_99 , V_268 , V_270 ) ) ;
goto error;
}
V_276 = V_29 -> V_284 [ V_268 ] . V_290 ;
if ( V_274 && V_265 != F_181 ( V_268 ) && V_66 ^ V_266 ) {
F_40 ( ( L_100 ,
V_268 ,
V_266 ,
V_66 ) ) ;
goto error;
}
if ( V_275 ) {
V_265 |= 1 << V_291 ;
if ( V_269 & V_292 ) {
V_11 |= V_292 ;
}
if ( V_269 & V_260 ) V_11 |= V_260 ;
if ( ( V_267 & V_234 ) != V_267 ) {
F_40 ( ( L_101 , V_267 , V_268 ) ) ;
goto error;
}
if ( ( V_264 & V_234 ) != V_264 ) {
F_40 ( ( L_102 , V_264 , V_268 ) ) ;
goto error;
}
} else {
if ( V_269 & ( V_292 | V_260 ) ) {
F_40 ( ( L_103 , V_268 ) ) ;
goto error;
}
}
if ( F_202 ( V_273 == 0 && V_276 ) ) {
V_88 = (* V_276)( V_2 , V_27 , V_268 , & V_265 , V_87 ) ;
if ( V_88 ) goto error;
V_88 = - V_106 ;
}
F_203 ( V_238 -> V_269 , 0 ) ;
if ( V_275 ) {
V_27 -> V_28 [ V_268 ] . V_11 = V_11 ;
V_27 -> V_28 [ V_268 ] . V_264 [ 0 ] = V_264 ;
V_27 -> V_28 [ V_268 ] . V_267 [ 0 ] = V_267 ;
V_27 -> V_28 [ V_268 ] . V_293 = V_238 -> V_294 ;
F_204 ( V_27 , V_264 ) ;
F_204 ( V_27 , V_267 ) ;
if ( V_155 == V_68 ) V_27 -> V_295 [ 0 ] &= ~ 1UL << V_268 ;
}
F_204 ( V_27 , V_29 -> V_284 [ V_268 ] . V_296 [ 0 ] ) ;
if ( V_274 ) F_205 ( V_27 , 1UL << V_268 ) ;
V_27 -> V_72 [ V_268 ] = V_265 ;
if ( V_272 ) {
if ( V_66 == 0 ) V_27 -> V_64 [ V_268 ] = V_265 ;
if ( V_271 ) {
F_26 ( V_268 , V_265 ) ;
}
#ifdef F_129
else {
V_27 -> V_297 [ 0 ] |= 1UL << V_268 ;
}
#endif
}
F_40 ( ( L_104 ,
V_268 ,
V_265 ,
V_272 ,
V_271 ,
V_11 ,
V_27 -> V_81 [ 0 ] ,
V_27 -> V_61 [ 0 ] ,
V_27 -> V_28 [ V_268 ] . V_293 ,
V_267 ,
V_264 ,
V_27 -> V_297 [ 0 ] ,
V_27 -> V_62 [ 0 ] ,
V_27 -> V_295 [ 0 ] ) ) ;
}
if ( V_271 ) F_27 () ;
return 0 ;
error:
F_203 ( V_238 -> V_269 , V_298 ) ;
return V_88 ;
}
static int
F_206 ( T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_18 * V_238 = ( T_18 * ) V_91 ;
unsigned long V_265 , V_299 , V_60 ;
unsigned int V_268 ;
int V_24 , V_271 = 0 , V_155 ;
int V_275 , V_272 , V_66 , V_273 ;
int V_88 = - V_106 ;
T_19 V_276 ;
V_155 = V_27 -> V_46 ;
V_272 = V_155 == V_277 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_60 = V_29 -> V_30 ;
V_2 = V_27 -> V_151 ;
if ( F_207 ( V_155 == V_163 ) ) return - V_106 ;
if ( F_202 ( V_272 ) ) {
if ( F_207 ( V_66 && V_27 -> V_150 != F_87 () ) ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_271 = F_120 () == V_2 || V_66 ? 1 : 0 ;
}
V_273 = V_278 . V_273 ;
for ( V_24 = 0 ; V_24 < V_247 ; V_24 ++ , V_238 ++ ) {
V_268 = V_238 -> V_279 ;
V_265 = V_238 -> V_280 ;
if ( ! F_208 ( V_268 ) ) {
F_40 ( ( L_105 , V_268 ) ) ;
goto V_300;
}
V_275 = F_61 ( V_268 ) ;
V_276 = V_29 -> V_301 [ V_268 ] . V_290 ;
if ( F_207 ( V_273 == 0 && V_276 ) ) {
unsigned long V_302 = V_265 ;
V_88 = (* V_276)( V_2 , V_27 , V_268 , & V_302 , V_87 ) ;
if ( V_88 ) goto V_300;
V_265 = V_302 ;
V_88 = - V_106 ;
}
F_203 ( V_238 -> V_269 , 0 ) ;
V_299 = V_265 ;
if ( V_275 ) {
V_27 -> V_28 [ V_268 ] . V_261 = V_265 ;
if ( V_272 ) {
V_299 = V_265 & V_60 ;
V_265 = V_265 & ~ V_60 ;
}
}
V_27 -> V_28 [ V_268 ] . V_254 = V_238 -> V_303 ;
V_27 -> V_28 [ V_268 ] . V_255 = V_238 -> V_304 ;
V_27 -> V_28 [ V_268 ] . V_258 = V_238 -> V_305 ;
V_27 -> V_28 [ V_268 ] . V_59 = V_238 -> V_306 ;
V_27 -> V_28 [ V_268 ] . V_20 = V_265 ;
F_204 ( V_27 , F_209 ( V_268 ) ) ;
F_204 ( V_27 , F_210 ( V_268 ) ) ;
if ( V_275 && V_155 == V_68 ) {
V_27 -> V_295 [ 0 ] &= ~ 1UL << V_268 ;
}
if ( V_272 ) {
if ( V_66 == 0 ) V_27 -> V_80 [ V_268 ] = V_299 ;
if ( V_271 ) {
F_38 ( V_268 , V_299 ) ;
} else {
#ifdef F_129
V_27 -> V_307 [ 0 ] |= 1UL << V_268 ;
#endif
}
}
F_40 ( ( L_106
L_107 ,
V_268 ,
V_265 ,
V_272 ,
V_271 ,
V_299 ,
V_27 -> V_28 [ V_268 ] . V_20 ,
V_27 -> V_28 [ V_268 ] . V_255 ,
V_27 -> V_28 [ V_268 ] . V_254 ,
F_211 ( V_27 , V_268 ) ? 'Y' : 'N' ,
V_27 -> V_28 [ V_268 ] . V_258 ,
V_27 -> V_28 [ V_268 ] . V_59 ,
V_27 -> V_61 [ 0 ] ,
V_27 -> V_28 [ V_268 ] . V_264 [ 0 ] ,
V_27 -> V_307 [ 0 ] ,
V_27 -> V_79 [ 0 ] ,
V_27 -> V_295 [ 0 ] ) ) ;
}
if ( V_271 ) F_27 () ;
return 0 ;
V_300:
F_203 ( V_238 -> V_269 , V_298 ) ;
return V_88 ;
}
static int
F_212 ( T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
unsigned long V_20 = 0UL , V_261 , V_60 , V_308 ;
T_18 * V_238 = ( T_18 * ) V_91 ;
unsigned int V_268 , V_269 = 0 ;
int V_24 , V_271 = 0 , V_155 ;
int V_272 , V_66 , V_275 , V_273 ;
int V_88 = - V_106 ;
T_19 V_309 ;
V_155 = V_27 -> V_46 ;
V_272 = V_155 == V_277 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_60 = V_29 -> V_30 ;
V_2 = V_27 -> V_151 ;
if ( V_155 == V_163 ) return - V_106 ;
if ( F_202 ( V_272 ) ) {
if ( F_207 ( V_66 && V_27 -> V_150 != F_87 () ) ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_271 = F_120 () == V_2 || V_66 ? 1 : 0 ;
if ( V_271 ) F_27 () ;
}
V_273 = V_278 . V_273 ;
F_40 ( ( L_108 ,
V_272 ,
V_271 ,
V_155 ) ) ;
for ( V_24 = 0 ; V_24 < V_247 ; V_24 ++ , V_238 ++ ) {
V_268 = V_238 -> V_279 ;
V_269 = V_238 -> V_269 ;
if ( F_207 ( ! F_208 ( V_268 ) ) ) goto error;
if ( F_207 ( ! F_213 ( V_27 , V_268 ) ) ) goto error;
V_308 = V_27 -> V_28 [ V_268 ] . V_20 ;
V_261 = V_27 -> V_28 [ V_268 ] . V_261 ;
V_275 = F_61 ( V_268 ) ;
if ( V_271 ) {
V_20 = F_36 ( V_268 ) ;
} else {
V_20 = V_272 ? V_27 -> V_80 [ V_268 ] : 0UL ;
}
V_309 = V_29 -> V_301 [ V_268 ] . V_310 ;
if ( V_275 ) {
V_20 &= V_60 ;
V_20 += V_308 ;
}
if ( F_207 ( V_273 == 0 && V_309 ) ) {
unsigned long V_302 = V_20 ;
V_88 = (* V_309)( V_27 -> V_151 , V_27 , V_268 , & V_302 , V_87 ) ;
if ( V_88 ) goto error;
V_20 = V_302 ;
V_88 = - V_106 ;
}
F_203 ( V_269 , 0 ) ;
F_40 ( ( L_109 , V_268 , V_20 ) ) ;
V_238 -> V_280 = V_20 ;
V_238 -> V_269 = V_269 ;
V_238 -> V_311 = V_261 ;
}
return 0 ;
error:
F_203 ( V_238 -> V_269 , V_298 ) ;
return V_88 ;
}
int
F_214 ( struct V_1 * V_2 , void * V_238 , unsigned int V_312 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_238 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_200 ( V_27 , V_238 , V_312 , V_87 ) ;
}
int
F_215 ( struct V_1 * V_2 , void * V_238 , unsigned int V_312 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_238 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_212 ( V_27 , V_238 , V_312 , V_87 ) ;
}
int
F_216 ( struct V_1 * V_2 )
{
T_1 * V_27 = V_2 -> V_313 . V_314 ;
unsigned long V_11 ;
int V_88 = 0 ;
if ( V_29 -> V_315 == 0 ) return 0 ;
F_40 ( ( L_110 , F_60 ( V_2 ) ) ) ;
if ( V_2 -> V_313 . V_11 & V_316 ) return 0 ;
if ( V_27 && V_27 -> V_73 == 1 ) return - 1 ;
F_86 ( V_11 ) ;
if ( V_113 . V_116 > 0 )
V_88 = - 1 ;
else
V_113 . V_317 ++ ;
F_40 ( ( L_111 ,
V_113 . V_317 ,
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
if ( V_29 -> V_315 == 0 ) return 0 ;
F_86 ( V_11 ) ;
if ( V_113 . V_317 == 0 ) {
F_63 ( V_67 L_112 , F_60 ( V_2 ) ) ;
V_88 = - 1 ;
} else {
V_113 . V_317 -- ;
V_88 = 0 ;
}
F_89 ( V_11 ) ;
return V_88 ;
}
static int
F_218 ( T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_4 * V_84 ;
T_5 V_318 ;
int V_155 , V_66 ;
int V_88 = 0 ;
V_155 = V_27 -> V_46 ;
V_84 = V_27 -> V_166 ;
V_66 = V_27 -> V_50 ;
V_2 = F_128 ( V_27 ) ;
switch( V_155 ) {
case V_68 :
break;
case V_277 :
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
V_27 -> V_295 [ 0 ] ) ) ;
if ( F_219 ( V_27 ) ) {
F_220 ( V_27 -> V_164 ) ;
V_318 . V_319 . V_320 = 0 ;
V_318 . V_319 . V_321 = 0 ;
if ( V_155 == V_277 )
V_88 = F_76 ( V_84 , V_2 , & V_318 , V_27 -> V_164 , V_87 ) ;
else
V_88 = F_75 ( V_84 , V_2 , & V_318 , V_27 -> V_164 , V_87 ) ;
} else {
V_318 . V_319 . V_320 = 0 ;
V_318 . V_319 . V_321 = 1 ;
}
if ( V_88 == 0 ) {
if ( V_318 . V_319 . V_321 )
F_199 ( V_27 , V_27 -> V_295 , V_322 ) ;
if ( V_318 . V_319 . V_320 == 0 ) {
F_40 ( ( L_117 , F_60 ( V_2 ) ) ) ;
if ( V_155 == V_68 ) F_62 ( V_2 ) ;
} else {
F_40 ( ( L_118 , F_60 ( V_2 ) ) ) ;
}
}
V_27 -> V_295 [ 0 ] = 0UL ;
V_27 -> V_46 = V_277 ;
V_27 -> V_323 = 0 ;
return 0 ;
}
if ( V_155 == V_68 ) {
if ( V_27 -> V_323 == 0 ) return - V_106 ;
V_27 -> V_323 = 0 ;
}
if ( F_131 ( V_27 ) == 0 && V_155 == V_68 ) {
F_40 ( ( L_119 , F_60 ( V_2 ) ) ) ;
F_132 ( & V_27 -> V_54 ) ;
} else {
F_40 ( ( L_120 , F_60 ( V_2 ) ) ) ;
V_27 -> V_324 = V_325 ;
F_221 ( V_2 , 1 ) ;
F_222 ( V_2 ) ;
}
return 0 ;
}
static int
F_223 ( T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 )
{
unsigned int V_326 = * ( unsigned int * ) V_91 ;
V_278 . V_327 = V_326 == 0 ? 0 : 1 ;
F_63 ( V_111 L_121 , V_278 . V_327 ? L_122 : L_123 ) ;
if ( V_326 == 0 ) {
memset ( V_328 , 0 , sizeof( V_328 ) ) ;
for( V_326 = 0 ; V_326 < V_329 ; V_326 ++ ) V_328 [ V_326 ] . V_330 = ~ 0UL ;
}
return 0 ;
}
static int
F_224 ( int V_331 , T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 )
{
struct V_332 * V_313 = NULL ;
struct V_1 * V_2 ;
T_22 * V_238 = ( T_22 * ) V_91 ;
unsigned long V_11 ;
T_23 V_333 ;
unsigned int V_334 ;
int V_335 ;
int V_88 = 0 , V_155 ;
int V_24 , V_271 = 0 ;
int V_66 , V_272 ;
if ( V_29 -> V_315 == 0 ) return - V_106 ;
V_155 = V_27 -> V_46 ;
V_272 = V_155 == V_277 ? 1 : 0 ;
V_66 = V_27 -> V_50 ;
V_2 = V_27 -> V_151 ;
if ( V_155 == V_163 ) return - V_106 ;
if ( V_272 ) {
V_313 = & V_2 -> V_313 ;
if ( F_207 ( V_66 && V_27 -> V_150 != F_87 () ) ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
V_271 = F_120 () == V_2 || V_66 ? 1 : 0 ;
}
V_335 = V_27 -> V_73 == 0 ;
if ( V_272 && ( V_313 -> V_11 & V_316 ) != 0 ) {
F_40 ( ( L_124 , F_60 ( V_2 ) ) ) ;
return - V_108 ;
}
if ( V_272 ) {
F_86 ( V_11 ) ;
if ( V_335 && V_66 ) {
if ( V_113 . V_317 )
V_88 = - V_108 ;
else
V_113 . V_116 ++ ;
}
F_89 ( V_11 ) ;
}
if ( V_88 != 0 ) return V_88 ;
V_27 -> V_73 = 1 ;
if ( V_335 && V_271 ) {
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
for ( V_24 = 0 ; V_24 < V_247 ; V_24 ++ , V_238 ++ ) {
V_334 = V_238 -> V_336 ;
V_333 . V_20 = V_238 -> V_337 ;
V_88 = - V_106 ;
if ( ( V_331 == V_338 && V_334 >= V_339 ) || ( ( V_331 == V_340 ) && V_334 >= V_341 ) ) {
F_40 ( ( L_126 ,
V_334 , V_333 . V_20 , V_331 , V_24 , V_247 ) ) ;
goto V_300;
}
if ( V_334 & 0x1 ) {
if ( V_331 == V_338 )
V_333 . V_342 . V_343 = 0 ;
else
V_333 . V_344 . V_345 = V_333 . V_344 . V_346 = 0 ;
}
F_203 ( V_238 -> V_347 , 0 ) ;
if ( V_331 == V_338 ) {
F_225 ( V_27 , V_334 ) ;
if ( V_271 ) {
F_30 ( V_334 , V_333 . V_20 ) ;
F_31 () ;
}
V_27 -> V_74 [ V_334 ] = V_333 . V_20 ;
F_40 ( ( L_127 ,
V_334 , V_333 . V_20 , V_27 -> V_235 [ 0 ] , V_272 , V_271 ) ) ;
} else {
F_226 ( V_27 , V_334 ) ;
if ( V_271 ) {
F_33 ( V_334 , V_333 . V_20 ) ;
F_34 () ;
}
V_27 -> V_76 [ V_334 ] = V_333 . V_20 ;
F_40 ( ( L_128 ,
V_334 , V_333 . V_20 , V_27 -> V_236 [ 0 ] , V_272 , V_271 ) ) ;
}
}
return 0 ;
V_300:
if ( V_335 ) {
F_86 ( V_11 ) ;
if ( V_27 -> V_50 ) {
V_113 . V_116 -- ;
}
F_89 ( V_11 ) ;
V_27 -> V_73 = 0 ;
}
F_203 ( V_238 -> V_347 , V_298 ) ;
return V_88 ;
}
static int
F_227 ( T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 )
{
return F_224 ( V_338 , V_27 , V_91 , V_247 , V_87 ) ;
}
static int
F_228 ( T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 )
{
return F_224 ( V_340 , V_27 , V_91 , V_247 , V_87 ) ;
}
int
F_229 ( struct V_1 * V_2 , void * V_238 , unsigned int V_312 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_238 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_227 ( V_27 , V_238 , V_312 , V_87 ) ;
}
int
F_230 ( struct V_1 * V_2 , void * V_238 , unsigned int V_312 , struct V_86 * V_87 )
{
T_1 * V_27 ;
if ( V_238 == NULL ) return - V_106 ;
V_27 = F_121 () ;
if ( V_27 == NULL ) return - V_106 ;
if ( V_2 != V_3 && V_27 -> V_50 == 0 ) return - V_108 ;
return F_228 ( V_27 , V_238 , V_312 , V_87 ) ;
}
static int
F_231 ( T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 )
{
T_24 * V_238 = ( T_24 * ) V_91 ;
V_238 -> V_348 = V_349 ;
return 0 ;
}
static int
F_232 ( T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 )
{
struct V_86 * V_350 ;
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
F_234 ( V_87 ) -> V_351 = 0 ;
return 0 ;
}
if ( V_2 == V_3 ) {
F_19 () ;
F_234 ( V_87 ) -> V_352 = 0 ;
} else {
V_350 = F_119 ( V_2 ) ;
F_234 ( V_350 ) -> V_352 = 0 ;
V_27 -> V_353 = 0 ;
F_40 ( ( L_130 , F_60 ( V_2 ) ) ) ;
}
return 0 ;
}
static int
F_235 ( T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 )
{
struct V_86 * V_350 ;
int V_155 , V_66 ;
V_155 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_155 != V_277 ) return - V_106 ;
if ( V_66 && V_27 -> V_150 != F_87 () ) {
F_40 ( ( L_58 , V_27 -> V_150 ) ) ;
return - V_108 ;
}
if ( V_66 ) {
F_234 ( V_87 ) -> V_351 = 1 ;
F_236 ( V_69 ) ;
F_17 () ;
F_24 ( V_70 , F_22 ( V_70 ) | V_71 ) ;
F_16 () ;
return 0 ;
}
if ( V_27 -> V_151 == V_3 ) {
F_20 () ;
F_234 ( V_87 ) -> V_352 = 1 ;
} else {
V_350 = F_119 ( V_27 -> V_151 ) ;
V_27 -> V_353 = V_17 ;
F_234 ( V_350 ) -> V_352 = 1 ;
}
return 0 ;
}
static int
F_237 ( T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 )
{
T_18 * V_238 = ( T_18 * ) V_91 ;
unsigned int V_268 ;
int V_24 ;
int V_88 = - V_106 ;
for ( V_24 = 0 ; V_24 < V_247 ; V_24 ++ , V_238 ++ ) {
V_268 = V_238 -> V_279 ;
if ( ! F_180 ( V_268 ) ) goto V_300;
V_238 -> V_280 = F_181 ( V_268 ) ;
F_203 ( V_238 -> V_269 , 0 ) ;
F_40 ( ( L_131 , V_268 , V_238 -> V_280 ) ) ;
}
return 0 ;
V_300:
F_203 ( V_238 -> V_269 , V_298 ) ;
return V_88 ;
}
static int
F_238 ( T_1 * V_27 )
{
struct V_1 * V_354 , * V_355 ;
int V_88 = - V_246 ;
F_188 ( & V_245 ) ;
F_239 (g, t) {
if ( V_355 -> V_313 . V_314 == V_27 ) {
V_88 = 0 ;
goto V_109;
}
} F_240 ( V_354 , V_355 ) ;
V_109:
F_191 ( & V_245 ) ;
F_40 ( ( L_132 , V_88 , V_27 ) ) ;
return V_88 ;
}
static int
F_241 ( T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
struct V_332 * V_313 ;
struct T_1 * V_356 ;
unsigned long V_11 ;
#ifndef F_129
struct V_1 * V_357 = NULL ;
#endif
T_25 * V_238 = ( T_25 * ) V_91 ;
unsigned long * V_358 , * V_359 ;
int V_360 ;
int V_88 = 0 ;
int V_155 , V_66 , V_361 = 0 ;
V_155 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_155 != V_47 ) {
F_40 ( ( L_133 ,
V_238 -> V_362 ,
V_27 -> V_46 ) ) ;
return - V_108 ;
}
F_40 ( ( L_134 , V_238 -> V_362 , V_27 -> V_73 ) ) ;
if ( F_131 ( V_27 ) == 0 && V_238 -> V_362 == V_3 -> V_243 ) {
F_40 ( ( L_135 ) ) ;
return - V_106 ;
}
V_88 = F_186 ( V_27 , V_238 -> V_362 , & V_2 ) ;
if ( V_88 ) {
F_40 ( ( L_136 , V_238 -> V_362 , V_88 ) ) ;
return V_88 ;
}
V_88 = - V_106 ;
if ( V_66 && V_2 != V_3 ) {
F_40 ( ( L_137 ,
V_238 -> V_362 ) ) ;
goto error;
}
V_313 = & V_2 -> V_313 ;
V_88 = 0 ;
if ( V_27 -> V_73 ) {
if ( V_313 -> V_11 & V_316 ) {
V_88 = - V_108 ;
F_40 ( ( L_138 , V_238 -> V_362 ) ) ;
goto error;
}
F_86 ( V_11 ) ;
if ( V_66 ) {
if ( V_113 . V_317 ) {
F_40 ( ( L_139 ,
F_60 ( V_2 ) ) ) ;
V_88 = - V_108 ;
} else {
V_113 . V_116 ++ ;
F_40 ( ( L_140 , F_60 ( V_2 ) , V_113 . V_116 ) ) ;
V_361 = 1 ;
}
}
F_89 ( V_11 ) ;
if ( V_88 ) goto error;
}
V_360 = V_27 -> V_150 = F_87 () ;
V_88 = - V_108 ;
V_88 = F_85 ( V_3 , V_66 , V_360 ) ;
if ( V_88 ) goto error;
F_40 ( ( L_141 ,
V_313 -> V_314 , V_27 ) ) ;
V_88 = - V_108 ;
V_356 = F_242 ( V_363 , & V_313 -> V_314 , NULL , V_27 , sizeof( T_1 * ) ) ;
if ( V_356 != NULL ) {
F_40 ( ( L_142 , V_238 -> V_362 ) ) ;
goto V_364;
}
F_43 ( V_27 ) ;
V_27 -> V_46 = V_277 ;
V_27 -> V_151 = V_2 ;
if ( V_66 ) {
F_236 ( V_365 ) ;
F_233 ( V_69 ) ;
if ( V_27 -> V_250 ) F_236 ( V_366 ) ;
} else {
V_313 -> V_11 |= V_367 ;
}
F_67 ( V_2 , V_27 ) ;
F_68 ( V_2 , V_27 ) ;
V_358 = V_27 -> V_64 ;
V_359 = V_27 -> V_80 ;
if ( V_2 == V_3 ) {
if ( V_66 == 0 ) {
F_234 ( V_87 ) -> V_368 = 0 ;
F_40 ( ( L_143 , F_60 ( V_2 ) ) ) ;
F_53 ( V_27 , F_87 () ) ;
F_243 () ;
F_244 ( V_27 ) ;
#ifndef F_129
V_357 = F_120 () ;
if ( V_357 ) F_245 ( V_357 ) ;
#endif
}
F_66 ( V_359 , V_27 -> V_79 [ 0 ] ) ;
F_69 ( V_358 , V_27 -> V_81 [ 0 ] ) ;
V_27 -> V_297 [ 0 ] = 0UL ;
V_27 -> V_307 [ 0 ] = 0UL ;
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
V_27 -> V_353 = 0UL ;
F_234 ( V_87 ) -> V_352 = F_234 ( V_87 ) -> V_351 = 0 ;
}
V_88 = 0 ;
V_364:
if ( V_88 ) F_90 ( V_27 , V_27 -> V_50 , V_360 ) ;
error:
if ( V_88 && V_361 ) {
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
F_123 ( T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 )
{
struct V_1 * V_2 = F_128 ( V_27 ) ;
struct V_86 * V_350 ;
int V_369 , V_66 ;
int V_88 ;
F_40 ( ( L_145 , V_27 -> V_46 , V_2 ? F_60 ( V_2 ) : - 1 ) ) ;
V_369 = V_27 -> V_46 ;
V_66 = V_27 -> V_50 ;
if ( V_369 == V_47 ) {
F_40 ( ( L_146 , V_369 ) ) ;
return 0 ;
}
V_88 = F_232 ( V_27 , NULL , 0 , V_87 ) ;
if ( V_88 ) return V_88 ;
V_27 -> V_46 = V_47 ;
if ( V_66 ) {
F_233 ( V_365 ) ;
F_233 ( V_366 ) ;
F_247 ( V_3 , V_27 ) ;
if ( V_369 != V_163 )
F_90 ( V_27 , 1 , V_27 -> V_150 ) ;
V_2 -> V_313 . V_314 = NULL ;
V_27 -> V_151 = NULL ;
return 0 ;
}
V_350 = V_2 == V_3 ? V_87 : F_119 ( V_2 ) ;
if ( V_2 == V_3 ) {
F_234 ( V_87 ) -> V_368 = 1 ;
F_40 ( ( L_147 , F_60 ( V_2 ) ) ) ;
}
F_247 ( V_2 , V_27 ) ;
if ( V_369 != V_163 )
F_90 ( V_27 , 0 , V_27 -> V_150 ) ;
V_27 -> V_55 = V_56 ;
F_53 ( V_27 , - 1 ) ;
V_2 -> V_313 . V_11 &= ~ V_367 ;
V_2 -> V_313 . V_314 = NULL ;
V_27 -> V_151 = NULL ;
F_221 ( V_2 , 0 ) ;
V_27 -> V_324 = V_370 ;
V_27 -> V_323 = 0 ;
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
int V_371 = 0 ;
V_27 = F_58 ( V_2 ) ;
F_103 ( V_27 , V_11 ) ;
F_40 ( ( L_149 , V_27 -> V_46 , F_60 ( V_2 ) ) ) ;
V_155 = V_27 -> V_46 ;
switch( V_155 ) {
case V_47 :
F_63 ( V_67 L_150 , F_60 ( V_2 ) ) ;
break;
case V_277 :
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
V_371 = 1 ;
break;
default:
F_63 ( V_67 L_153 , F_60 ( V_2 ) , V_155 ) ;
break;
}
F_106 ( V_27 , V_11 ) ;
{ T_26 V_65 = F_21 () ;
F_250 ( V_65 & ( V_17 | V_16 ) ) ;
F_250 ( F_120 () ) ;
F_250 ( F_234 ( V_87 ) -> V_352 ) ;
F_250 ( F_234 ( V_87 ) -> V_351 ) ;
}
if ( V_371 ) F_55 ( V_27 ) ;
}
static int
F_251 ( T_1 * V_27 , int V_143 , unsigned long V_11 )
{
struct V_1 * V_2 ;
int V_155 , V_372 ;
V_373:
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
if ( V_143 != V_374 ) return 0 ;
}
if ( F_252 ( V_143 ) ) {
if ( ! F_184 ( V_2 ) ) {
F_40 ( ( L_157 , F_60 ( V_2 ) ) ) ;
return - V_108 ;
}
V_372 = V_155 ;
F_106 ( V_27 , V_11 ) ;
F_185 ( V_2 , 0 ) ;
F_103 ( V_27 , V_11 ) ;
if ( V_27 -> V_46 != V_372 ) {
F_40 ( ( L_158 , V_372 , V_27 -> V_46 ) ) ;
goto V_373;
}
}
return 0 ;
}
T_27 long
F_253 ( int V_144 , int V_143 , void T_8 * V_91 , int V_247 )
{
struct V_144 V_7 = { NULL , 0 } ;
T_1 * V_27 = NULL ;
unsigned long V_11 = 0UL ;
void * V_375 = NULL ;
long V_88 ;
T_9 V_376 , V_237 , V_377 = 0 ;
int V_378 , V_379 = 0 , V_380 = 0 , V_381 ;
int (* F_254)( T_1 * V_27 , void * V_91 , int V_247 , struct V_86 * V_87 );
int (* F_255)( void * V_91 , T_9 * V_237 );
#define F_256 4096
if ( F_207 ( V_29 == NULL ) ) return - V_382 ;
if ( F_207 ( V_143 < 0 || V_143 >= V_383 ) ) {
F_40 ( ( L_159 , V_143 ) ) ;
return - V_106 ;
}
F_254 = V_384 [ V_143 ] . V_385 ;
V_378 = V_384 [ V_143 ] . V_386 ;
V_376 = V_384 [ V_143 ] . V_387 ;
F_255 = V_384 [ V_143 ] . V_388 ;
V_381 = V_384 [ V_143 ] . V_381 ;
if ( F_207 ( F_254 == NULL ) ) {
F_40 ( ( L_159 , V_143 ) ) ;
return - V_106 ;
}
F_40 ( ( L_160 ,
F_257 ( V_143 ) ,
V_143 ,
V_378 ,
V_376 ,
V_247 ) ) ;
if ( F_207 ( ( V_378 == V_389 && V_247 <= 0 ) || ( V_378 > 0 && V_378 != V_247 ) ) )
return - V_106 ;
V_390:
V_237 = V_377 + V_376 * V_247 ;
if ( F_207 ( V_237 > F_256 ) ) {
F_63 ( V_67 L_161 , F_60 ( V_3 ) , V_237 ) ;
return - V_391 ;
}
if ( F_202 ( V_247 && V_375 == NULL ) ) {
V_375 = F_258 ( F_256 , V_45 ) ;
if ( V_375 == NULL ) return - V_179 ;
}
V_88 = - V_138 ;
if ( V_237 && F_259 ( V_375 , V_91 , V_237 ) ) {
F_40 ( ( L_162 , V_237 , V_91 ) ) ;
goto V_392;
}
if ( V_379 == 0 && F_255 ) {
V_88 = (* F_255)( V_375 , & V_377 ) ;
if ( V_88 ) goto V_392;
V_379 = 1 ;
F_40 ( ( L_163 , V_237 , V_377 ) ) ;
if ( F_202 ( V_377 ) ) goto V_390;
}
if ( F_207 ( ( V_381 & V_393 ) == 0 ) ) goto V_394;
V_88 = - V_147 ;
V_7 = F_260 ( V_144 ) ;
if ( F_207 ( V_7 . V_125 == NULL ) ) {
F_40 ( ( L_164 , V_144 ) ) ;
goto V_392;
}
if ( F_207 ( F_102 ( V_7 . V_125 ) == 0 ) ) {
F_40 ( ( L_165 , V_144 ) ) ;
goto V_392;
}
V_27 = V_7 . V_125 -> V_129 ;
if ( F_207 ( V_27 == NULL ) ) {
F_40 ( ( L_166 , V_144 ) ) ;
goto V_392;
}
F_220 ( & V_27 -> V_46 ) ;
F_103 ( V_27 , V_11 ) ;
V_88 = F_251 ( V_27 , V_143 , V_11 ) ;
if ( F_207 ( V_88 ) ) goto V_136;
V_394:
V_88 = (* F_254)( V_27 , V_375 , V_247 , F_119 ( V_3 ) ) ;
V_380 = 1 ;
V_136:
if ( F_202 ( V_27 ) ) {
F_40 ( ( L_167 ) ) ;
F_106 ( V_27 , V_11 ) ;
}
if ( V_380 && F_261 ( V_143 ) && F_110 ( V_91 , V_375 , V_376 * V_247 ) ) V_88 = - V_138 ;
V_392:
if ( V_7 . V_125 )
F_262 ( V_7 ) ;
F_56 ( V_375 ) ;
F_40 ( ( L_168 , F_257 ( V_143 ) , V_88 ) ) ;
return V_88 ;
}
static void
F_263 ( T_1 * V_27 , unsigned long V_262 , struct V_86 * V_87 )
{
T_4 * V_84 = V_27 -> V_166 ;
T_5 V_318 ;
int V_155 ;
int V_88 = 0 ;
V_155 = V_27 -> V_46 ;
if ( F_219 ( V_27 ) ) {
V_318 . V_319 . V_320 = 0 ;
V_318 . V_319 . V_321 = 0 ;
if ( V_155 == V_277 )
V_88 = F_76 ( V_84 , V_3 , & V_318 , V_27 -> V_164 , V_87 ) ;
else
V_88 = F_75 ( V_84 , V_3 , & V_318 , V_27 -> V_164 , V_87 ) ;
} else {
V_318 . V_319 . V_320 = 0 ;
V_318 . V_319 . V_321 = 1 ;
}
if ( V_88 == 0 ) {
if ( V_318 . V_319 . V_321 ) {
F_199 ( V_27 , & V_262 , V_322 ) ;
}
if ( V_318 . V_319 . V_320 == 0 ) {
F_40 ( ( L_169 ) ) ;
if ( V_27 -> V_46 == V_68 ) F_62 ( V_3 ) ;
} else {
F_40 ( ( L_170 ) ) ;
}
V_27 -> V_46 = V_277 ;
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
unsigned long V_11 , V_395 ;
unsigned long V_262 ;
unsigned int V_396 ;
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
V_396 = V_27 -> V_324 ;
V_27 -> V_324 = V_370 ;
V_262 = V_27 -> V_295 [ 0 ] ;
F_40 ( ( L_174 , V_396 , V_27 -> V_46 ) ) ;
if ( V_27 -> V_162 || V_27 -> V_46 == V_163 )
goto V_397;
if ( V_396 == V_325 )
goto V_398;
F_106 ( V_27 , V_11 ) ;
F_267 () ;
F_40 ( ( L_175 ) ) ;
V_88 = F_268 ( & V_27 -> V_54 ) ;
F_40 ( ( L_176 , V_88 ) ) ;
F_103 ( V_27 , V_395 ) ;
V_262 = V_27 -> V_295 [ 0 ] ;
if ( V_27 -> V_162 ) {
V_397:
F_40 ( ( L_177 ) ) ;
F_264 ( V_27 , V_87 ) ;
goto V_399;
}
if ( V_88 < 0 )
goto V_399;
V_398:
F_263 ( V_27 , V_262 , V_87 ) ;
V_27 -> V_295 [ 0 ] = 0UL ;
V_399:
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
F_270 ( & V_27 -> V_146 , V_400 , V_401 ) ;
return 0 ;
}
static int
F_271 ( T_1 * V_27 , unsigned long V_402 )
{
T_2 * V_37 = NULL ;
if ( V_27 -> V_52 == 0 ) {
V_37 = F_39 ( V_27 ) ;
if ( V_37 == NULL ) {
F_63 ( V_67 L_180 ) ;
return - 1 ;
}
V_37 -> V_403 . V_39 = V_404 ;
V_37 -> V_403 . V_137 = V_27 -> V_140 ;
V_37 -> V_403 . V_405 = 0 ;
V_37 -> V_403 . V_406 [ 0 ] = V_402 ;
V_37 -> V_403 . V_406 [ 1 ] = 0UL ;
V_37 -> V_403 . V_406 [ 2 ] = 0UL ;
V_37 -> V_403 . V_406 [ 3 ] = 0UL ;
V_37 -> V_403 . V_407 = 0UL ;
}
F_40 ( ( L_181 ,
V_37 ,
V_27 -> V_52 ,
V_27 -> V_140 ,
V_402 ) ) ;
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
V_37 -> V_408 . V_39 = V_409 ;
V_37 -> V_408 . V_137 = V_27 -> V_140 ;
V_37 -> V_403 . V_407 = 0UL ;
F_40 ( ( L_183 ,
V_37 ,
V_27 -> V_52 ,
V_27 -> V_140 ) ) ;
return F_269 ( V_27 , V_37 ) ;
}
static void F_272 ( struct V_1 * V_2 , T_1 * V_27 ,
unsigned long V_410 , struct V_86 * V_87 )
{
T_28 * V_411 ;
unsigned long V_59 ;
unsigned long V_412 , V_30 , V_413 ;
unsigned long V_414 = 0UL , V_402 = 0UL , V_267 = 0UL , V_264 ;
unsigned long V_415 ;
T_5 V_416 ;
unsigned int V_24 , V_417 ;
int V_418 = 0 ;
if ( F_207 ( V_27 -> V_46 == V_163 ) ) goto V_419;
if ( F_207 ( ( V_410 & 0x1 ) == 0 ) ) goto V_420;
V_415 = F_273 () ;
V_59 = V_410 >> V_63 ;
V_30 = V_29 -> V_30 ;
V_417 = F_219 ( V_27 ) ;
F_59 ( ( L_184
L_185 ,
V_410 ,
V_2 ? F_60 ( V_2 ) : - 1 ,
( V_87 ? V_87 -> V_421 : 0 ) ,
F_131 ( V_27 ) ? L_186 : L_187 ,
V_27 -> V_61 [ 0 ] ) ) ;
for ( V_24 = V_63 ; V_59 ; V_24 ++ , V_59 >>= 1 ) {
if ( ( V_59 & 0x1 ) == 0 ) continue;
V_412 = V_413 = V_27 -> V_28 [ V_24 ] . V_20 ;
V_413 += 1 + V_30 ;
V_27 -> V_28 [ V_24 ] . V_20 = V_413 ;
if ( F_202 ( V_412 > V_413 ) ) {
V_402 |= 1UL << V_24 ;
if ( F_211 ( V_27 , V_24 ) ) V_414 |= 1UL << V_24 ;
}
F_59 ( ( L_188 ,
V_24 ,
V_413 ,
V_412 ,
F_36 ( V_24 ) & V_30 ,
V_402 ,
V_414 ) ) ;
}
if ( V_402 == 0UL ) return;
V_416 . V_20 = 0 ;
V_264 = 0UL ;
if ( V_417 ) {
unsigned long V_422 , V_423 ;
unsigned long V_424 ;
int V_425 , V_426 , V_88 = 0 ;
int V_427 = F_87 () ;
V_424 = V_402 >> V_63 ;
V_411 = & V_27 -> V_428 ;
F_220 ( V_27 -> V_164 ) ;
for( V_24 = V_63 ; V_424 && V_88 == 0 ; V_24 ++ , V_424 >>= 1 ) {
V_59 = 1UL << V_24 ;
if ( ( V_424 & 0x1 ) == 0 ) continue;
V_411 -> V_429 = ( unsigned char ) V_24 ;
V_411 -> V_414 = V_414 & V_59 ? 1 : 0 ;
V_411 -> V_430 = 0 ;
V_411 -> V_416 . V_20 = 0 ;
V_411 -> V_267 [ 0 ] = V_267 = V_27 -> V_28 [ V_24 ] . V_267 [ 0 ] ;
V_411 -> V_431 = V_27 -> V_28 [ V_24 ] . V_20 ;
V_411 -> V_432 = V_27 -> V_28 [ V_24 ] . V_261 ;
V_411 -> V_433 = V_27 -> V_28 [ V_24 ] . V_293 ;
if ( V_267 ) {
for( V_425 = 0 , V_426 = 0 ; V_267 ; V_425 ++ , V_267 >>= 1 ) {
if ( ( V_267 & 0x1 ) == 0 ) continue;
V_411 -> V_434 [ V_426 ++ ] = F_61 ( V_425 ) ? F_35 ( V_27 , V_425 ) : F_36 ( V_425 ) ;
F_59 ( ( L_189 , V_426 - 1 , V_425 , V_411 -> V_434 [ V_426 - 1 ] ) ) ;
}
}
V_328 [ V_427 ] . V_435 ++ ;
V_422 = F_273 () ;
V_88 = (* V_27 -> V_166 -> V_107 )( V_2 , V_27 -> V_164 , V_411 , V_87 , V_415 ) ;
V_423 = F_273 () ;
V_416 . V_319 . V_436 |= V_411 -> V_416 . V_319 . V_436 ;
V_416 . V_319 . V_437 |= V_411 -> V_416 . V_319 . V_437 ;
V_416 . V_319 . V_320 |= V_411 -> V_416 . V_319 . V_320 ;
if ( V_411 -> V_416 . V_319 . V_321 ) V_264 |= V_59 ;
V_328 [ V_427 ] . V_438 += V_423 - V_422 ;
}
if ( V_88 && V_424 ) {
F_40 ( ( L_190 ,
V_424 << V_63 ) ) ;
}
V_402 &= ~ V_264 ;
} else {
V_416 . V_319 . V_436 = V_414 ? 1 : 0 ;
V_416 . V_319 . V_437 = V_414 ? 1 : 0 ;
V_416 . V_319 . V_320 = V_414 ? 1 : 0 ;
V_416 . V_319 . V_321 = V_414 ? 0 : 1 ;
if ( V_414 == 0 ) V_264 = V_402 ;
}
F_59 ( ( L_191 , V_402 , V_264 ) ) ;
if ( V_264 ) {
unsigned long V_439 = V_264 ;
F_199 ( V_27 , & V_439 , V_440 ) ;
}
if ( V_414 && V_416 . V_319 . V_436 ) {
V_27 -> V_295 [ 0 ] = V_402 ;
if ( F_131 ( V_27 ) == 0 && V_416 . V_319 . V_437 ) {
V_27 -> V_324 = V_441 ;
F_221 ( V_2 , 1 ) ;
F_222 ( V_2 ) ;
}
V_418 = 1 ;
}
F_59 ( ( L_192 ,
F_120 () ? F_60 ( F_120 () ) : - 1 ,
F_274 ( V_2 ) ,
V_27 -> V_324 ,
V_402 ,
V_414 ,
V_416 . V_319 . V_320 ? 1 : 0 ) ) ;
if ( V_416 . V_319 . V_320 ) {
F_57 ( V_2 ) ;
V_27 -> V_46 = V_68 ;
V_27 -> V_323 = 1 ;
}
if ( V_418 ) F_271 ( V_27 , V_414 ) ;
return;
V_420:
F_63 ( V_67 L_193 ,
F_87 () ,
V_2 ? F_60 ( V_2 ) : - 1 ,
V_410 ) ;
return;
V_419:
F_40 ( ( L_194 , V_2 ? F_60 ( V_2 ) : - 1 ) ) ;
F_19 () ;
F_234 ( V_87 ) -> V_352 = 0 ;
F_234 ( V_87 ) -> V_368 = 1 ;
return;
}
static int
F_275 ( void * V_91 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
T_1 * V_27 ;
unsigned long V_11 ;
T_26 V_410 ;
int V_427 = F_87 () ;
int V_442 = 0 ;
V_328 [ V_427 ] . V_443 ++ ;
V_410 = F_276 ( 0 ) ;
V_2 = F_120 () ;
V_27 = F_121 () ;
if ( F_277 ( V_410 ) && V_2 ) {
if ( ! V_27 ) goto V_444;
if ( V_27 -> V_50 == 0 && ( V_2 -> V_313 . V_11 & V_367 ) == 0 )
goto V_445;
F_278 ( V_27 , V_11 ) ;
F_272 ( V_2 , V_27 , V_410 , V_87 ) ;
F_279 ( V_27 , V_11 ) ;
} else {
V_328 [ V_427 ] . V_446 ++ ;
V_442 = - 1 ;
}
F_28 () ;
return V_442 ;
V_444:
F_63 ( V_111 L_195 ,
V_427 , F_60 ( V_2 ) ) ;
F_28 () ;
return - 1 ;
V_445:
F_63 ( V_111 L_196 ,
V_427 ,
F_60 ( V_2 ) ) ;
F_28 () ;
return - 1 ;
}
static T_29
F_280 ( int V_447 , void * V_91 )
{
unsigned long V_422 , V_448 ;
unsigned long V_449 , V_450 ;
int V_427 ;
int V_88 ;
struct V_86 * V_87 = F_281 () ;
V_427 = F_282 () ;
if ( F_202 ( ! V_451 ) ) {
V_449 = V_328 [ V_427 ] . V_330 ;
V_450 = V_328 [ V_427 ] . V_452 ;
V_422 = F_273 () ;
V_88 = F_275 ( V_91 , V_87 ) ;
V_448 = F_273 () ;
if ( F_202 ( V_88 == 0 ) ) {
V_448 -= V_422 ;
if ( V_448 < V_449 ) V_328 [ V_427 ] . V_330 = V_448 ;
if ( V_448 > V_450 ) V_328 [ V_427 ] . V_452 = V_448 ;
V_328 [ V_427 ] . V_453 += V_448 ;
}
}
else {
(* V_451 -> V_454 )( V_447 , V_91 , V_87 ) ;
}
F_283 () ;
return V_455 ;
}
static void *
F_284 ( struct V_456 * V_326 , T_10 * V_100 )
{
if ( * V_100 == 0 ) {
return V_457 ;
}
while ( * V_100 <= V_458 ) {
if ( F_285 ( * V_100 - 1 ) ) {
return ( void * ) * V_100 ;
}
++ * V_100 ;
}
return NULL ;
}
static void *
F_286 ( struct V_456 * V_326 , void * V_302 , T_10 * V_100 )
{
++ * V_100 ;
return F_284 ( V_326 , V_100 ) ;
}
static void
F_287 ( struct V_456 * V_326 , void * V_302 )
{
}
static void
F_288 ( struct V_456 * V_326 )
{
struct V_99 * V_100 ;
T_4 * V_101 ;
unsigned long V_11 ;
F_289 ( V_326 ,
L_197
L_198
L_199
L_200
L_201
L_202 ,
V_459 , V_460 ,
V_29 -> V_461 ,
V_278 . V_462 > 0 ? L_203 : L_204 ,
V_278 . V_273 > 0 ? L_203 : L_204 ,
V_29 -> V_30 ,
V_29 -> V_11 ) ;
F_86 ( V_11 ) ;
F_289 ( V_326 ,
L_205
L_206
L_207
L_208 ,
V_113 . V_115 ,
V_113 . V_114 ,
V_113 . V_116 ,
V_113 . V_317 ) ;
F_89 ( V_11 ) ;
F_9 ( & V_104 ) ;
F_78 (pos, &pfm_buffer_fmt_list) {
V_101 = F_79 ( V_100 , T_4 , V_102 ) ;
F_289 ( V_326 , L_209 ,
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
F_290 ( struct V_456 * V_326 , void * V_302 )
{
unsigned long V_65 ;
unsigned int V_24 ;
int V_90 ;
if ( V_302 == V_457 ) {
F_288 ( V_326 ) ;
return 0 ;
}
V_90 = ( long ) V_302 - 1 ;
F_289 ( V_326 ,
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
V_90 , V_328 [ V_90 ] . V_443 ,
V_90 , V_328 [ V_90 ] . V_453 ,
V_90 , V_328 [ V_90 ] . V_330 ,
V_90 , V_328 [ V_90 ] . V_452 ,
V_90 , V_328 [ V_90 ] . V_435 ,
V_90 , V_328 [ V_90 ] . V_438 ,
V_90 , V_328 [ V_90 ] . V_446 ,
V_90 , V_328 [ V_90 ] . V_463 ,
V_90 , F_291 ( V_464 , V_90 ) & V_365 ? 1 : 0 ,
V_90 , F_291 ( V_464 , V_90 ) & V_69 ? 1 : 0 ,
V_90 , F_291 ( V_464 , V_90 ) & V_366 ? 1 : 0 ,
V_90 , F_291 ( V_465 , V_90 ) ? F_291 ( V_465 , V_90 ) -> V_243 : - 1 ,
V_90 , F_291 ( V_466 , V_90 ) ,
V_90 , F_291 ( V_467 , V_90 ) ) ;
if ( F_292 () == 1 && V_278 . V_327 > 0 ) {
V_65 = F_21 () ;
F_27 () ;
F_289 ( V_326 ,
L_224
L_225 ,
V_90 , V_65 ,
V_90 , F_276 ( 0 ) ) ;
for ( V_24 = 0 ; F_179 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_293 ( V_24 ) == 0 ) continue;
F_289 ( V_326 ,
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
return F_295 ( V_125 , & V_468 ) ;
}
void
F_296 ( struct V_1 * V_2 , unsigned long V_148 , int V_469 )
{
struct V_86 * V_87 ;
unsigned long V_470 ;
unsigned long V_471 ;
V_471 = V_148 & V_69 ? 1 : 0 ;
if ( ( V_148 & V_366 ) == 0 || V_2 -> V_243 ) {
V_87 = F_119 ( V_2 ) ;
F_234 ( V_87 ) -> V_351 = V_469 ? V_471 : 0 ;
return;
}
if ( V_471 ) {
V_470 = F_22 ( V_70 ) ;
if ( V_469 ) {
F_24 ( V_70 , V_470 & ~ V_71 ) ;
F_14 () ;
F_16 () ;
return;
}
F_24 ( V_70 , V_470 | V_71 ) ;
F_17 () ;
F_16 () ;
}
}
static void
F_297 ( T_1 * V_27 , struct V_86 * V_87 )
{
struct V_1 * V_2 = V_27 -> V_151 ;
F_234 ( V_87 ) -> V_352 = 0 ;
F_234 ( V_87 ) -> V_368 = 1 ;
if ( F_120 () == V_2 ) {
F_40 ( ( L_228 ,
F_60 ( V_27 -> V_151 ) ) ) ;
F_246 ( NULL , NULL ) ;
}
F_221 ( V_2 , 0 ) ;
V_2 -> V_313 . V_314 = NULL ;
V_2 -> V_313 . V_11 &= ~ V_367 ;
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
F_250 ( V_65 & ( V_472 ) ) ;
F_19 () ;
V_27 -> V_353 = V_65 & V_17 ;
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
F_250 ( V_65 & ( V_472 ) ) ;
F_19 () ;
V_27 -> V_353 = V_65 & V_17 ;
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
unsigned long V_473 = 0UL , V_424 = 0UL ;
unsigned long V_11 ;
T_26 V_65 , V_474 ;
int V_475 ;
V_27 = F_58 ( V_2 ) ;
if ( F_207 ( V_27 == NULL ) ) return;
F_250 ( F_120 () ) ;
if ( F_207 ( ( V_2 -> V_313 . V_11 & V_367 ) == 0 ) ) return;
V_11 = F_8 ( V_27 ) ;
V_65 = F_21 () ;
V_475 = V_29 -> V_11 & V_476 ;
F_250 ( V_65 & ( V_17 | V_16 ) ) ;
F_250 ( V_65 & V_472 ) ;
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
V_474 = V_27 -> V_353 ;
if ( F_300 ( V_27 ) == F_87 () && V_27 -> V_55 == F_301 () ) {
V_473 = V_27 -> V_297 [ 0 ] ;
V_424 = V_27 -> V_307 [ 0 ] ;
} else {
V_424 = V_278 . V_462 ? V_27 -> V_61 [ 0 ] : V_27 -> V_79 [ 0 ] ;
V_473 = V_27 -> V_81 [ 0 ] ;
}
if ( V_424 ) F_66 ( V_27 -> V_80 , V_424 ) ;
if ( V_473 ) F_69 ( V_27 -> V_64 , V_473 ) ;
if ( F_207 ( F_277 ( V_27 -> V_64 [ 0 ] ) ) ) {
F_26 ( 0 , V_27 -> V_64 [ 0 ] ) ;
F_27 () ;
V_27 -> V_64 [ 0 ] = 0UL ;
if ( V_475 ) F_302 ( V_477 ) ;
V_328 [ F_87 () ] . V_463 ++ ;
}
V_27 -> V_297 [ 0 ] = 0UL ;
V_27 -> V_307 [ 0 ] = 0UL ;
F_53 ( V_27 , F_87 () ) ;
F_243 () ;
F_244 ( V_27 ) ;
F_246 ( V_2 , V_27 ) ;
if ( F_202 ( V_474 ) ) F_20 () ;
F_10 ( V_27 , V_11 ) ;
}
void
F_299 ( struct V_1 * V_2 )
{
T_1 * V_27 ;
struct V_1 * V_149 ;
unsigned long V_424 , V_473 ;
T_26 V_65 , V_474 ;
int V_475 ;
V_149 = F_120 () ;
V_27 = F_58 ( V_2 ) ;
V_65 = F_21 () ;
F_250 ( V_65 & ( V_17 | V_16 ) ) ;
F_250 ( V_65 & V_472 ) ;
if ( V_27 -> V_73 ) {
F_29 ( V_27 -> V_74 , V_29 -> V_75 ) ;
F_32 ( V_27 -> V_76 , V_29 -> V_77 ) ;
}
V_474 = V_27 -> V_353 ;
V_475 = V_29 -> V_11 & V_476 ;
if ( F_202 ( V_149 == V_2 ) ) {
if ( F_202 ( V_474 ) ) F_20 () ;
return;
}
if ( V_149 ) F_245 ( V_149 ) ;
V_424 = V_278 . V_462 ? V_27 -> V_61 [ 0 ] : V_27 -> V_79 [ 0 ] ;
V_473 = V_27 -> V_81 [ 0 ] ;
F_66 ( V_27 -> V_80 , V_424 ) ;
F_69 ( V_27 -> V_64 , V_473 ) ;
if ( F_207 ( F_277 ( V_27 -> V_64 [ 0 ] ) ) ) {
F_26 ( 0 , V_27 -> V_64 [ 0 ] ) ;
F_27 () ;
V_27 -> V_64 [ 0 ] = 0UL ;
if ( V_475 ) F_302 ( V_477 ) ;
V_328 [ F_87 () ] . V_463 ++ ;
}
F_246 ( V_2 , V_27 ) ;
if ( F_202 ( V_474 ) ) F_20 () ;
}
static void
F_247 ( struct V_1 * V_2 , T_1 * V_27 )
{
T_26 V_410 ;
unsigned long V_478 , V_20 , V_479 , V_30 ;
int V_24 , V_271 = 0 ;
int V_480 ;
V_480 = V_27 -> V_151 == V_2 ? 1 : 0 ;
V_271 = ( F_120 () == V_2 ) || ( V_27 -> V_50 && V_27 -> V_150 == F_87 () ) ;
if ( V_271 ) {
F_246 ( NULL , NULL ) ;
F_40 ( ( L_230 ) ) ;
F_27 () ;
V_410 = F_276 ( 0 ) ;
F_28 () ;
} else {
V_410 = V_27 -> V_64 [ 0 ] ;
V_27 -> V_64 [ 0 ] = 0 ;
}
V_30 = V_29 -> V_30 ;
V_478 = V_27 -> V_61 [ 0 ] ;
F_40 ( ( L_231 , V_480 , V_30 , V_478 ) ) ;
for ( V_24 = 0 ; V_478 ; V_24 ++ , V_478 >>= 1 ) {
if ( ( V_478 & 0x1 ) == 0 ) continue;
V_20 = V_479 = V_271 ? F_36 ( V_24 ) : V_27 -> V_80 [ V_24 ] ;
if ( F_61 ( V_24 ) ) {
F_40 ( ( L_232 ,
F_60 ( V_2 ) ,
V_24 ,
V_27 -> V_28 [ V_24 ] . V_20 ,
V_20 & V_30 ) ) ;
V_20 = V_27 -> V_28 [ V_24 ] . V_20 + ( V_20 & V_30 ) ;
V_479 = 0UL ;
if ( V_410 & ( 1UL << V_24 ) ) {
V_20 += 1 + V_30 ;
F_40 ( ( L_233 , F_60 ( V_2 ) , V_24 ) ) ;
}
}
F_40 ( ( L_234 , F_60 ( V_2 ) , V_24 , V_20 , V_479 ) ) ;
if ( V_480 ) V_27 -> V_80 [ V_24 ] = V_479 ;
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
F_234 ( V_87 ) -> V_351 = 0 ;
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
F_234 ( V_87 ) -> V_351 = 0 ;
F_28 () ;
F_27 () ;
}
int
F_305 ( T_30 * V_481 )
{
int V_88 , V_24 ;
int V_482 ;
if ( V_481 == NULL || V_481 -> V_454 == NULL ) return - V_106 ;
if ( V_451 ) return - V_108 ;
if ( ! F_306 ( & V_483 ) ) {
return - V_108 ;
}
F_307 (reserve_cpu) {
V_88 = F_85 ( NULL , 1 , V_482 ) ;
if ( V_88 ) goto V_484;
}
V_88 = F_308 ( F_303 , NULL , 1 ) ;
if ( V_88 ) {
F_40 ( ( L_236 , V_88 ) ) ;
goto V_484;
}
V_451 = V_481 ;
F_11 ( & V_483 ) ;
return 0 ;
V_484:
F_307 (i) {
if ( V_24 >= V_482 ) break;
F_90 ( NULL , 1 , V_24 ) ;
}
F_11 ( & V_483 ) ;
return V_88 ;
}
int
F_309 ( T_30 * V_481 )
{
int V_24 ;
int V_88 ;
if ( V_481 == NULL ) return - V_106 ;
if ( V_451 != V_481 ) return - V_106 ;
if ( ! F_306 ( & V_483 ) ) {
return - V_108 ;
}
V_451 = NULL ;
V_88 = F_308 ( F_304 , NULL , 1 ) ;
if ( V_88 ) {
F_40 ( ( L_236 , V_88 ) ) ;
}
F_307 (i) {
F_90 ( NULL , 1 , V_24 ) ;
}
F_11 ( & V_483 ) ;
return 0 ;
}
static int T_6
F_310 ( void )
{
T_31 * * V_244 ;
int V_485 ;
V_485 = V_486 -> V_485 ;
V_244 = V_487 ;
while( * V_244 ) {
if ( ( * V_244 ) -> V_488 ) {
if ( ( * V_244 ) -> V_488 () == 0 ) goto V_489;
} else if ( ( * V_244 ) -> V_490 == V_485 || ( * V_244 ) -> V_490 == 0xff ) {
goto V_489;
}
V_244 ++ ;
}
return - 1 ;
V_489:
V_29 = * V_244 ;
return 0 ;
}
int T_6
F_311 ( void )
{
unsigned int V_491 , V_492 , V_24 ;
F_63 ( L_237 ,
V_459 ,
V_460 ,
V_477 ) ;
if ( F_310 () ) {
F_63 ( V_111 L_238 ,
V_486 -> V_485 ) ;
return - V_493 ;
}
V_491 = 0 ;
for ( V_24 = 0 ; F_179 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_180 ( V_24 ) == 0 ) continue;
V_29 -> V_233 [ V_24 >> 6 ] |= 1UL << ( V_24 & 63 ) ;
V_491 ++ ;
}
V_29 -> V_494 = V_491 ;
V_491 = 0 ; V_492 = 0 ;
for ( V_24 = 0 ; F_312 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_208 ( V_24 ) == 0 ) continue;
V_29 -> V_234 [ V_24 >> 6 ] |= 1UL << ( V_24 & 63 ) ;
V_491 ++ ;
if ( F_61 ( V_24 ) ) V_492 ++ ;
}
V_29 -> V_495 = V_491 ;
V_29 -> V_496 = V_492 ;
if ( V_29 -> V_315 ) {
if ( V_29 -> V_75 > V_497 ) {
F_63 ( V_111 L_239 , V_29 -> V_75 ) ;
V_29 = NULL ;
return - 1 ;
}
if ( V_29 -> V_77 > V_497 ) {
F_63 ( V_111 L_240 , V_29 -> V_75 ) ;
V_29 = NULL ;
return - 1 ;
}
}
F_63 ( L_241 ,
V_29 -> V_461 ,
V_29 -> V_494 ,
V_29 -> V_495 ,
V_29 -> V_496 ,
F_313 ( V_29 -> V_30 ) ) ;
if ( V_29 -> V_495 >= V_498 || V_29 -> V_494 >= V_499 ) {
F_63 ( V_67 L_242 ) ;
V_29 = NULL ;
return - 1 ;
}
V_500 = F_314 ( L_243 , V_182 , NULL , & V_501 ) ;
if ( V_500 == NULL ) {
F_63 ( V_67 L_244 ) ;
V_29 = NULL ;
return - 1 ;
}
V_502 = F_315 ( V_503 ) ;
F_51 ( & V_113 . V_504 ) ;
F_51 ( & V_104 ) ;
F_94 () ;
for( V_24 = 0 ; V_24 < V_329 ; V_24 ++ ) V_328 [ V_24 ] . V_330 = ~ 0UL ;
return 0 ;
}
void
F_316 ( void )
{
static int V_335 = 1 ;
F_14 () ;
F_19 () ;
F_28 () ;
if ( V_335 ) {
F_317 ( V_477 , & V_505 ) ;
V_335 = 0 ;
}
F_24 ( V_506 , V_477 ) ;
F_27 () ;
}
void
F_318 ( const char * V_507 )
{
struct V_1 * V_2 ;
struct V_86 * V_87 ;
T_1 * V_27 ;
unsigned long V_65 , V_470 , V_148 , V_11 ;
int V_24 , V_427 ;
F_122 ( V_11 ) ;
V_427 = F_87 () ;
V_87 = F_119 ( V_3 ) ;
V_148 = F_64 () ;
V_470 = F_22 ( V_70 ) ;
if ( V_148 == 0 && F_234 ( V_87 ) -> V_351 == 0 && ( V_470 & V_71 ) == 0 ) {
F_124 ( V_11 ) ;
return;
}
F_63 ( L_245 ,
V_427 ,
V_507 ,
F_60 ( V_3 ) ,
V_87 -> V_421 ,
V_3 -> V_508 ) ;
V_2 = F_120 () ;
V_27 = F_121 () ;
F_63 ( L_246 , V_427 , V_2 ? F_60 ( V_2 ) : - 1 , V_27 ) ;
V_65 = F_21 () ;
F_63 ( L_247 ,
V_427 ,
F_276 ( 0 ) ,
V_65 & V_16 ? 1 : 0 ,
V_65 & V_17 ? 1 : 0 ,
V_470 & V_71 ? 1 : 0 ,
V_148 ,
F_234 ( V_87 ) -> V_352 ,
F_234 ( V_87 ) -> V_351 ) ;
F_234 ( V_87 ) -> V_352 = 0 ;
F_234 ( V_87 ) -> V_351 = 0 ;
for ( V_24 = 1 ; F_179 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_180 ( V_24 ) == 0 ) continue;
F_63 ( L_248 , V_427 , V_24 , F_276 ( V_24 ) , V_24 , V_27 -> V_64 [ V_24 ] ) ;
}
for ( V_24 = 1 ; F_312 ( V_24 ) == 0 ; V_24 ++ ) {
if ( F_208 ( V_24 ) == 0 ) continue;
F_63 ( L_249 , V_427 , V_24 , F_36 ( V_24 ) , V_24 , V_27 -> V_80 [ V_24 ] ) ;
}
if ( V_27 ) {
F_63 ( L_250 ,
V_427 ,
V_27 -> V_46 ,
V_27 -> V_156 ,
V_27 -> V_164 ,
V_27 -> V_35 ,
V_27 -> V_33 ,
V_27 -> V_353 ) ;
}
F_124 ( V_11 ) ;
}
void
F_319 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_332 * V_313 ;
F_40 ( ( L_251 , F_60 ( V_2 ) ) ) ;
V_313 = & V_2 -> V_313 ;
V_313 -> V_314 = NULL ;
F_221 ( V_2 , 0 ) ;
}
T_27 long
F_253 ( int V_144 , int V_143 , void * V_91 , int V_247 )
{
return - V_382 ;
}
