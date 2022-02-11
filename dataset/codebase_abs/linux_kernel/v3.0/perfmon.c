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
static inline unsigned int
F_12 ( struct V_8 * V_9 , unsigned long V_10 , T_2 V_11 , int V_12 )
{
return F_13 ( V_9 , V_10 , V_11 ) ;
}
static inline unsigned long
F_14 ( struct V_13 * V_13 , unsigned long V_10 , unsigned long V_11 , unsigned long V_14 , unsigned long V_15 , unsigned long V_16 )
{
return F_15 ( V_13 , V_10 , V_11 , V_14 , V_15 ) ;
}
static struct V_17 *
F_16 ( struct V_18 * V_19 , int V_15 , const char * V_20 , void * V_21 )
{
return F_17 ( V_19 , L_1 , NULL , & V_22 ,
V_23 ) ;
}
static inline void
F_18 ( void )
{
F_19 ( V_24 ) ;
F_20 () ;
}
static inline void
F_21 ( void )
{
F_22 ( V_24 ) ;
F_20 () ;
}
static inline void
F_23 ( void )
{
F_19 ( V_25 ) ;
F_20 () ;
}
static inline void
F_24 ( void )
{
F_22 ( V_25 ) ;
F_20 () ;
}
static inline unsigned long
F_25 ( void )
{
unsigned long V_26 ;
V_26 = F_26 ( V_27 ) ;
F_20 () ;
return V_26 ;
}
static inline void
F_27 ( unsigned long V_28 )
{
F_28 ( V_29 , V_28 ) ;
F_20 () ;
}
static inline void
F_29 ( void )
{
F_30 ( 0 , 1UL ) ;
F_31 () ;
}
static inline void
F_32 ( void )
{
F_30 ( 0 , 0UL ) ;
F_31 () ;
}
static inline void
F_33 ( unsigned long * V_30 , unsigned int V_31 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
F_34 ( V_32 , V_30 [ V_32 ] ) ;
F_35 () ;
}
F_20 () ;
}
static inline void
F_36 ( unsigned long * V_33 , unsigned int V_34 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_34 ; V_32 ++ ) {
F_37 ( V_32 , V_33 [ V_32 ] ) ;
F_38 () ;
}
F_31 () ;
}
static inline unsigned long
F_39 ( T_1 * V_35 , int V_32 )
{
return V_35 -> V_36 [ V_32 ] . V_28 + ( F_40 ( V_32 ) & V_37 -> V_38 ) ;
}
static inline void
F_41 ( T_1 * V_35 , int V_32 , unsigned long V_28 )
{
unsigned long V_38 = V_37 -> V_38 ;
V_35 -> V_36 [ V_32 ] . V_28 = V_28 & ~ V_38 ;
F_42 ( V_32 , V_28 & V_38 ) ;
}
static T_3 *
F_43 ( T_1 * V_35 )
{
int V_39 , V_40 ;
V_40 = ( V_35 -> V_41 + 1 ) % V_42 ;
F_44 ( ( L_2 , V_35 , V_35 -> V_43 , V_35 -> V_41 ) ) ;
if ( V_40 == V_35 -> V_43 ) return NULL ;
V_39 = V_35 -> V_41 ;
V_35 -> V_41 = V_40 ;
F_44 ( ( L_3 , V_35 , V_35 -> V_43 , V_35 -> V_41 , V_39 ) ) ;
return V_35 -> V_44 + V_39 ;
}
static T_3 *
F_45 ( T_1 * V_35 )
{
T_3 * V_45 ;
F_44 ( ( L_4 , V_35 , V_35 -> V_43 , V_35 -> V_41 ) ) ;
if ( F_46 ( V_35 ) ) return NULL ;
V_45 = V_35 -> V_44 + V_35 -> V_43 ;
V_35 -> V_43 = ( V_35 -> V_43 + 1 ) % V_42 ;
F_44 ( ( L_5 , V_35 , V_35 -> V_43 , V_35 -> V_41 , V_45 -> V_46 . V_47 ) ) ;
return V_45 ;
}
static void
F_47 ( T_1 * V_35 )
{
V_35 -> V_43 = V_35 -> V_41 = 0 ;
F_44 ( ( L_6 , V_35 ) ) ;
}
static void *
F_48 ( unsigned long V_48 )
{
void * V_49 ;
unsigned long V_10 ;
V_48 = F_49 ( V_48 ) ;
V_49 = F_50 ( V_48 ) ;
if ( V_49 ) {
V_10 = ( unsigned long ) V_49 ;
while ( V_48 > 0 ) {
F_3 ( V_10 ) ;
V_10 += V_50 ;
V_48 -= V_50 ;
}
}
return V_49 ;
}
static void
F_51 ( void * V_49 , unsigned long V_48 )
{
unsigned long V_10 ;
if ( V_49 ) {
F_44 ( ( L_7 , V_49 , V_48 ) ) ;
V_10 = ( unsigned long ) V_49 ;
while ( ( long ) V_48 > 0 ) {
F_6 ( V_10 ) ;
V_10 += V_50 ;
V_48 -= V_50 ;
}
F_52 ( V_49 ) ;
}
return;
}
static T_1 *
F_53 ( int V_51 )
{
T_1 * V_35 ;
V_35 = F_54 ( sizeof( T_1 ) , V_52 ) ;
if ( V_35 ) {
F_44 ( ( L_8 , V_35 ) ) ;
F_55 ( & V_35 -> V_6 ) ;
V_35 -> V_53 = V_54 ;
V_35 -> V_55 = ( V_51 & V_56 ) ? 1 : 0 ;
V_35 -> V_57 = ( V_51 & V_58 ) ? 1 : 0 ;
V_35 -> V_59 = ( V_51 & V_60 ) ? 1 : 0 ;
F_56 ( & V_35 -> V_61 ) ;
V_35 -> V_62 = V_63 ;
F_57 ( V_35 , - 1 ) ;
V_35 -> V_43 = V_35 -> V_41 = 0 ;
F_58 ( & V_35 -> V_64 ) ;
F_58 ( & V_35 -> V_65 ) ;
}
return V_35 ;
}
static void
F_59 ( T_1 * V_35 )
{
if ( V_35 ) {
F_44 ( ( L_9 , V_35 ) ) ;
F_60 ( V_35 ) ;
}
}
static void
F_61 ( struct V_1 * V_2 )
{
T_1 * V_35 = F_62 ( V_2 ) ;
unsigned long V_66 , V_28 , V_67 ;
int V_32 ;
F_63 ( ( L_10 , F_64 ( V_2 ) ) ) ;
V_67 = V_37 -> V_38 ;
V_66 = V_35 -> V_68 [ 0 ] ;
for ( V_32 = 0 ; V_66 ; V_32 ++ , V_66 >>= 1 ) {
if ( ( V_66 & 0x1 ) == 0 ) continue;
V_28 = F_40 ( V_32 ) ;
if ( F_65 ( V_32 ) ) {
V_35 -> V_36 [ V_32 ] . V_28 += ( V_28 & V_67 ) ;
} else {
V_35 -> V_36 [ V_32 ] . V_28 = V_28 ;
}
F_63 ( ( L_11 ,
V_32 ,
V_35 -> V_36 [ V_32 ] . V_28 ,
V_28 & V_67 ) ) ;
}
V_66 = V_35 -> V_69 [ 0 ] >> V_70 ;
for( V_32 = V_70 ; V_66 ; V_32 ++ , V_66 >>= 1 ) {
if ( ( V_66 & 0x1 ) == 0UL ) continue;
F_30 ( V_32 , V_35 -> V_71 [ V_32 ] & ~ 0xfUL ) ;
V_35 -> V_71 [ V_32 ] &= ~ 0xfUL ;
F_63 ( ( L_12 , V_32 , V_35 -> V_71 [ V_32 ] ) ) ;
}
F_31 () ;
}
static void
F_66 ( struct V_1 * V_2 )
{
T_1 * V_35 = F_62 ( V_2 ) ;
unsigned long V_66 , V_67 ;
unsigned long V_72 , V_28 ;
int V_32 , V_73 ;
V_73 = V_35 -> V_57 ;
V_67 = V_37 -> V_38 ;
if ( V_2 != V_3 ) {
F_67 ( V_74 L_13 , __LINE__ , F_64 ( V_2 ) , F_64 ( V_3 ) ) ;
return;
}
if ( V_35 -> V_53 != V_75 ) {
F_67 ( V_74 L_14 , __LINE__ ,
F_64 ( V_2 ) , F_64 ( V_3 ) , V_35 -> V_53 ) ;
return;
}
V_72 = F_25 () ;
if ( V_73 && ( F_68 () & V_76 ) ) {
F_28 ( V_77 , F_26 ( V_77 ) & ~ V_78 ) ;
F_18 () ;
} else {
F_23 () ;
}
V_66 = V_35 -> V_68 [ 0 ] ;
for ( V_32 = 0 ; V_66 ; V_32 ++ , V_66 >>= 1 ) {
if ( ( V_66 & 0x1 ) == 0 ) continue;
if ( F_65 ( V_32 ) ) {
V_28 = V_35 -> V_36 [ V_32 ] . V_28 & V_67 ;
V_35 -> V_36 [ V_32 ] . V_28 &= ~ V_67 ;
} else {
V_28 = V_35 -> V_36 [ V_32 ] . V_28 ;
}
F_42 ( V_32 , V_28 ) ;
F_44 ( ( L_11 ,
V_32 ,
V_35 -> V_36 [ V_32 ] . V_28 ,
V_28 ) ) ;
}
V_66 = V_35 -> V_69 [ 0 ] >> V_70 ;
for( V_32 = V_70 ; V_66 ; V_32 ++ , V_66 >>= 1 ) {
if ( ( V_66 & 0x1 ) == 0UL ) continue;
V_35 -> V_71 [ V_32 ] = V_35 -> V_79 [ V_32 ] ;
F_30 ( V_32 , V_35 -> V_71 [ V_32 ] ) ;
F_44 ( ( L_15 ,
F_64 ( V_2 ) , V_32 , V_35 -> V_71 [ V_32 ] ) ) ;
}
F_31 () ;
if ( V_35 -> V_80 ) {
F_33 ( V_35 -> V_81 , V_37 -> V_82 ) ;
F_36 ( V_35 -> V_83 , V_37 -> V_84 ) ;
}
if ( V_73 && ( F_68 () & V_76 ) ) {
F_28 ( V_77 , F_26 ( V_77 ) | V_78 ) ;
F_20 () ;
}
F_27 ( V_72 ) ;
}
static inline void
F_69 ( unsigned long * V_85 , unsigned long V_66 )
{
int V_32 ;
F_31 () ;
for ( V_32 = 0 ; V_66 ; V_32 ++ , V_66 >>= 1 ) {
if ( V_66 & 0x1 ) V_85 [ V_32 ] = F_40 ( V_32 ) ;
}
}
static inline void
F_70 ( unsigned long * V_85 , unsigned long V_66 )
{
int V_32 ;
unsigned long V_28 , V_38 = V_37 -> V_38 ;
for ( V_32 = 0 ; V_66 ; V_32 ++ , V_66 >>= 1 ) {
if ( ( V_66 & 0x1 ) == 0 ) continue;
V_28 = F_65 ( V_32 ) ? V_85 [ V_32 ] & V_38 : V_85 [ V_32 ] ;
F_42 ( V_32 , V_28 ) ;
}
F_31 () ;
}
static inline void
F_71 ( struct V_1 * V_2 , T_1 * V_35 )
{
unsigned long V_38 = V_37 -> V_38 ;
unsigned long V_66 = V_35 -> V_86 [ 0 ] ;
unsigned long V_28 ;
int V_32 ;
F_44 ( ( L_16 , V_66 ) ) ;
for ( V_32 = 0 ; V_66 ; V_32 ++ , V_66 >>= 1 ) {
V_28 = V_35 -> V_36 [ V_32 ] . V_28 ;
if ( F_65 ( V_32 ) ) {
V_35 -> V_36 [ V_32 ] . V_28 = V_28 & ~ V_38 ;
V_28 &= V_38 ;
}
V_35 -> V_87 [ V_32 ] = V_28 ;
F_44 ( ( L_17 ,
V_32 ,
V_35 -> V_87 [ V_32 ] ,
V_35 -> V_36 [ V_32 ] . V_28 ) ) ;
}
}
static inline void
F_72 ( struct V_1 * V_2 , T_1 * V_35 )
{
unsigned long V_66 = V_35 -> V_88 [ 0 ] ;
int V_32 ;
F_44 ( ( L_16 , V_66 ) ) ;
for ( V_32 = 0 ; V_66 ; V_32 ++ , V_66 >>= 1 ) {
V_35 -> V_71 [ V_32 ] = V_35 -> V_79 [ V_32 ] ;
F_44 ( ( L_12 , V_32 , V_35 -> V_71 [ V_32 ] ) ) ;
}
}
static inline void
F_73 ( unsigned long * V_89 , unsigned long V_66 )
{
int V_32 ;
for ( V_32 = 0 ; V_66 ; V_32 ++ , V_66 >>= 1 ) {
if ( ( V_66 & 0x1 ) == 0 ) continue;
F_30 ( V_32 , V_89 [ V_32 ] ) ;
}
F_31 () ;
}
static inline int
F_74 ( T_4 V_4 , T_4 V_90 )
{
return memcmp ( V_4 , V_90 , sizeof( T_4 ) ) ;
}
static inline int
F_75 ( T_5 * V_91 , struct V_1 * V_2 , void * V_92 , struct V_93 * V_94 )
{
int V_95 = 0 ;
if ( V_91 -> V_96 ) V_95 = (* V_91 -> V_96 )( V_2 , V_92 , V_94 ) ;
return V_95 ;
}
static inline int
F_76 ( T_5 * V_91 , struct V_1 * V_2 , unsigned int V_15 , int V_97 , void * V_98 , unsigned long * V_48 )
{
int V_95 = 0 ;
if ( V_91 -> V_99 ) V_95 = (* V_91 -> V_99 )( V_2 , V_15 , V_97 , V_98 , V_48 ) ;
return V_95 ;
}
static inline int
F_77 ( T_5 * V_91 , struct V_1 * V_2 , unsigned int V_15 ,
int V_97 , void * V_98 )
{
int V_95 = 0 ;
if ( V_91 -> V_100 ) V_95 = (* V_91 -> V_100 )( V_2 , V_15 , V_97 , V_98 ) ;
return V_95 ;
}
static inline int
F_78 ( T_5 * V_91 , struct V_1 * V_2 , void * V_92 , unsigned int V_15 ,
int V_97 , void * V_98 )
{
int V_95 = 0 ;
if ( V_91 -> V_101 ) V_95 = (* V_91 -> V_101 )( V_2 , V_92 , V_15 , V_97 , V_98 ) ;
return V_95 ;
}
static inline int
F_79 ( T_5 * V_91 , struct V_1 * V_2 , T_6 * V_102 , void * V_92 , struct V_93 * V_94 )
{
int V_95 = 0 ;
if ( V_91 -> V_103 ) V_95 = (* V_91 -> V_103 )( V_2 , V_102 , V_92 , V_94 ) ;
return V_95 ;
}
static inline int
F_80 ( T_5 * V_91 , struct V_1 * V_2 , T_6 * V_102 , void * V_92 , struct V_93 * V_94 )
{
int V_95 = 0 ;
if ( V_91 -> V_104 ) V_95 = (* V_91 -> V_104 )( V_2 , V_102 , V_92 , V_94 ) ;
return V_95 ;
}
static T_5 *
F_81 ( T_4 V_105 )
{
struct V_106 * V_107 ;
T_5 * V_108 ;
F_82 (pos, &pfm_buffer_fmt_list) {
V_108 = F_83 ( V_107 , T_5 , V_109 ) ;
if ( F_74 ( V_105 , V_108 -> V_110 ) == 0 )
return V_108 ;
}
return NULL ;
}
static T_5 *
F_84 ( T_4 V_105 )
{
T_5 * V_91 ;
F_9 ( & V_111 ) ;
V_91 = F_81 ( V_105 ) ;
F_11 ( & V_111 ) ;
return V_91 ;
}
int
F_85 ( T_5 * V_91 )
{
int V_95 = 0 ;
if ( V_91 == NULL || V_91 -> V_112 == NULL ) return - V_113 ;
if ( V_91 -> V_114 == NULL ) return - V_113 ;
F_9 ( & V_111 ) ;
if ( F_81 ( V_91 -> V_110 ) ) {
F_67 ( V_74 L_18 , V_91 -> V_112 ) ;
V_95 = - V_115 ;
goto V_116;
}
F_86 ( & V_91 -> V_109 , & V_117 ) ;
F_67 ( V_118 L_19 , V_91 -> V_112 ) ;
V_116:
F_11 ( & V_111 ) ;
return V_95 ;
}
int
F_87 ( T_4 V_105 )
{
T_5 * V_91 ;
int V_95 = 0 ;
F_9 ( & V_111 ) ;
V_91 = F_81 ( V_105 ) ;
if ( ! V_91 ) {
F_67 ( V_74 L_20 ) ;
V_95 = - V_113 ;
goto V_116;
}
F_88 ( & V_91 -> V_109 ) ;
F_67 ( V_118 L_21 , V_91 -> V_112 ) ;
V_116:
F_11 ( & V_111 ) ;
return V_95 ;
}
static int
F_89 ( struct V_1 * V_2 , int V_119 , unsigned int V_97 )
{
unsigned long V_15 ;
F_90 ( V_15 ) ;
F_44 ( ( L_22 ,
V_120 . V_121 ,
V_120 . V_122 ,
V_120 . V_123 ,
V_119 ,
V_97 ) ) ;
if ( V_119 ) {
if ( V_120 . V_122 > 0UL ) {
F_44 ( ( L_23 ,
V_120 . V_122 ) ) ;
goto abort;
}
if ( V_120 . V_124 [ V_97 ] ) goto V_125;
F_44 ( ( L_24 , V_97 , F_91 () ) ) ;
V_120 . V_124 [ V_97 ] = V_2 ;
V_120 . V_121 ++ ;
} else {
if ( V_120 . V_121 ) goto abort;
V_120 . V_122 ++ ;
}
F_44 ( ( L_25 ,
V_120 . V_121 ,
V_120 . V_122 ,
V_120 . V_123 ,
V_119 ,
V_97 ) ) ;
F_92 ( 0 ) ;
F_93 ( V_15 ) ;
return 0 ;
V_125:
F_44 ( ( L_26 ,
F_64 ( V_120 . V_124 [ V_97 ] ) ,
V_97 ) ) ;
abort:
F_93 ( V_15 ) ;
return - V_115 ;
}
static int
F_94 ( T_1 * V_35 , int V_119 , unsigned int V_97 )
{
unsigned long V_15 ;
F_90 ( V_15 ) ;
F_44 ( ( L_22 ,
V_120 . V_121 ,
V_120 . V_122 ,
V_120 . V_123 ,
V_119 ,
V_97 ) ) ;
if ( V_119 ) {
V_120 . V_124 [ V_97 ] = NULL ;
if ( V_35 && V_35 -> V_80 ) {
if ( V_120 . V_123 == 0 ) {
F_67 ( V_74 L_27 , V_35 ) ;
} else {
V_120 . V_123 -- ;
}
}
V_120 . V_121 -- ;
} else {
V_120 . V_122 -- ;
}
F_44 ( ( L_25 ,
V_120 . V_121 ,
V_120 . V_122 ,
V_120 . V_123 ,
V_119 ,
V_97 ) ) ;
if ( V_120 . V_122 == 0 && V_120 . V_121 == 0 )
F_92 ( 1 ) ;
F_93 ( V_15 ) ;
return 0 ;
}
static int
F_95 ( struct V_1 * V_2 , void * V_126 , unsigned long V_48 )
{
int V_127 ;
if ( V_2 -> V_9 == NULL || V_48 == 0UL || V_126 == NULL ) {
F_67 ( V_74 L_28 , F_64 ( V_2 ) , V_2 -> V_9 ) ;
return - V_113 ;
}
F_44 ( ( L_29 , V_126 , V_48 ) ) ;
F_96 ( & V_2 -> V_9 -> V_128 ) ;
F_44 ( ( L_30 , V_126 , V_48 ) ) ;
V_127 = F_12 ( V_2 -> V_9 , ( unsigned long ) V_126 , V_48 , 0 ) ;
F_97 ( & V_2 -> V_9 -> V_128 ) ;
if ( V_127 != 0 ) {
F_67 ( V_74 L_31 , F_64 ( V_2 ) , V_126 , V_48 ) ;
}
F_44 ( ( L_32 , V_126 , V_48 , V_127 ) ) ;
return 0 ;
}
static inline void
F_98 ( T_5 * V_91 )
{
if ( V_91 == NULL ) return;
F_75 ( V_91 , V_3 , NULL , NULL ) ;
}
static int T_7
F_99 ( void )
{
int V_129 = F_100 ( & V_130 ) ;
if ( ! V_129 ) {
V_131 = F_101 ( & V_130 ) ;
V_129 = F_102 ( V_131 ) ;
if ( F_103 ( V_131 ) )
F_104 ( & V_130 ) ;
else
V_129 = 0 ;
}
return V_129 ;
}
static T_8
F_105 ( struct V_13 * V_132 , char T_9 * V_92 , T_2 V_48 , T_10 * V_133 )
{
T_1 * V_35 ;
T_3 * V_45 ;
T_8 V_95 ;
unsigned long V_15 ;
F_106 ( V_134 , V_3 ) ;
if ( F_107 ( V_132 ) == 0 ) {
F_67 ( V_74 L_33 , F_64 ( V_3 ) ) ;
return - V_113 ;
}
V_35 = V_132 -> V_135 ;
if ( V_35 == NULL ) {
F_67 ( V_74 L_34 , F_64 ( V_3 ) ) ;
return - V_113 ;
}
if ( V_48 < sizeof( T_3 ) ) {
F_44 ( ( L_35 , V_35 , sizeof( T_3 ) ) ) ;
return - V_113 ;
}
F_108 ( V_35 , V_15 ) ;
F_109 ( & V_35 -> V_64 , & V_134 ) ;
for(; ; ) {
F_110 ( V_136 ) ;
F_44 ( ( L_36 , V_35 -> V_43 , V_35 -> V_41 ) ) ;
V_95 = 0 ;
if( F_46 ( V_35 ) == 0 ) break;
F_111 ( V_35 , V_15 ) ;
V_95 = - V_137 ;
if( V_132 -> V_138 & V_139 ) break;
if( F_112 ( V_3 ) ) {
V_95 = - V_140 ;
break;
}
F_113 () ;
F_108 ( V_35 , V_15 ) ;
}
F_44 ( ( L_37 , F_64 ( V_3 ) , V_95 ) ) ;
F_110 ( V_141 ) ;
F_114 ( & V_35 -> V_64 , & V_134 ) ;
if ( V_95 < 0 ) goto abort;
V_95 = - V_113 ;
V_45 = F_45 ( V_35 ) ;
if ( V_45 == NULL ) {
F_67 ( V_74 L_38 , V_35 , F_64 ( V_3 ) ) ;
goto V_142;
}
F_44 ( ( L_39 , V_45 -> V_46 . V_143 , V_45 -> V_46 . V_47 ) ) ;
V_95 = - V_144 ;
if( F_115 ( V_92 , V_45 , sizeof( T_3 ) ) == 0 ) V_95 = sizeof( T_3 ) ;
V_142:
F_111 ( V_35 , V_15 ) ;
abort:
return V_95 ;
}
static T_8
F_116 ( struct V_13 * V_13 , const char T_9 * V_145 ,
T_2 V_48 , T_10 * V_133 )
{
F_44 ( ( L_40 ) ) ;
return - V_113 ;
}
static unsigned int
F_117 ( struct V_13 * V_132 , T_11 * V_134 )
{
T_1 * V_35 ;
unsigned long V_15 ;
unsigned int V_66 = 0 ;
if ( F_107 ( V_132 ) == 0 ) {
F_67 ( V_74 L_33 , F_64 ( V_3 ) ) ;
return 0 ;
}
V_35 = V_132 -> V_135 ;
if ( V_35 == NULL ) {
F_67 ( V_74 L_41 , F_64 ( V_3 ) ) ;
return 0 ;
}
F_44 ( ( L_42 , V_35 -> V_146 ) ) ;
F_118 ( V_132 , & V_35 -> V_64 , V_134 ) ;
F_108 ( V_35 , V_15 ) ;
if ( F_46 ( V_35 ) == 0 )
V_66 = V_147 | V_148 ;
F_111 ( V_35 , V_15 ) ;
F_44 ( ( L_43 , V_35 -> V_146 , V_66 ) ) ;
return V_66 ;
}
static long
F_119 ( struct V_13 * V_13 , unsigned int V_149 , unsigned long V_98 )
{
F_44 ( ( L_44 ) ) ;
return - V_113 ;
}
static inline int
F_120 ( int V_150 , struct V_13 * V_132 , T_1 * V_35 , int V_151 )
{
int V_95 ;
V_95 = F_121 ( V_150 , V_132 , V_151 , & V_35 -> V_152 ) ;
F_44 ( ( L_45 ,
F_64 ( V_3 ) ,
V_150 ,
V_151 ,
V_35 -> V_152 , V_95 ) ) ;
return V_95 ;
}
static int
F_122 ( int V_150 , struct V_13 * V_132 , int V_151 )
{
T_1 * V_35 ;
int V_95 ;
if ( F_107 ( V_132 ) == 0 ) {
F_67 ( V_74 L_46 , F_64 ( V_3 ) ) ;
return - V_153 ;
}
V_35 = V_132 -> V_135 ;
if ( V_35 == NULL ) {
F_67 ( V_74 L_47 , F_64 ( V_3 ) ) ;
return - V_153 ;
}
V_95 = F_120 ( V_150 , V_132 , V_35 , V_151 ) ;
F_44 ( ( L_48 ,
V_150 ,
V_151 ,
V_35 -> V_152 , V_95 ) ) ;
return V_95 ;
}
static void
F_123 ( void * V_154 )
{
T_1 * V_35 = ( T_1 * ) V_154 ;
struct V_93 * V_94 = F_124 ( V_3 ) ;
struct V_1 * V_155 ;
unsigned long V_15 ;
int V_95 ;
if ( V_35 -> V_156 != F_91 () ) {
F_67 ( V_74 L_49 ,
V_35 -> V_156 ,
F_91 () ) ;
return;
}
V_155 = F_125 () ;
if ( V_155 != V_35 -> V_157 ) {
F_67 ( V_74 L_50 ,
F_91 () ,
F_64 ( V_155 ) , F_64 ( V_35 -> V_157 ) ) ;
return;
}
if ( F_126 () != V_35 ) {
F_67 ( V_74 L_51 ,
F_91 () ,
F_126 () , V_35 ) ;
return;
}
F_44 ( ( L_52 , F_91 () , F_64 ( V_35 -> V_157 ) ) ) ;
F_127 ( V_15 ) ;
V_95 = F_128 ( V_35 , NULL , 0 , V_94 ) ;
if ( V_95 ) {
F_44 ( ( L_53 , V_95 ) ) ;
}
F_129 ( V_15 ) ;
}
static void
F_130 ( T_1 * V_35 )
{
int V_95 ;
F_44 ( ( L_54 , V_35 -> V_156 ) ) ;
V_95 = F_131 ( V_35 -> V_156 , F_123 , V_35 , 1 ) ;
F_44 ( ( L_55 , V_35 -> V_156 , V_95 ) ) ;
}
static int
F_132 ( struct V_13 * V_132 , T_12 V_158 )
{
T_1 * V_35 ;
struct V_1 * V_2 ;
struct V_93 * V_94 ;
unsigned long V_15 ;
unsigned long V_159 = 0UL ;
void * V_160 = NULL ;
int V_161 , V_73 ;
if ( F_107 ( V_132 ) == 0 ) {
F_44 ( ( L_56 ) ) ;
return - V_153 ;
}
V_35 = V_132 -> V_135 ;
if ( V_35 == NULL ) {
F_67 ( V_74 L_57 , F_64 ( V_3 ) ) ;
return - V_153 ;
}
F_108 ( V_35 , V_15 ) ;
V_161 = V_35 -> V_53 ;
V_73 = V_35 -> V_57 ;
V_2 = F_133 ( V_35 ) ;
V_94 = F_124 ( V_2 ) ;
F_44 ( ( L_58 ,
V_161 ,
V_2 == V_3 ? 1 : 0 ) ) ;
if ( V_2 == V_3 ) {
#ifdef F_134
if ( V_73 && V_35 -> V_156 != F_91 () ) {
F_44 ( ( L_59 , V_35 -> V_156 ) ) ;
F_129 ( V_15 ) ;
F_130 ( V_35 ) ;
F_127 ( V_15 ) ;
} else
#endif
{
F_44 ( ( L_60 ) ) ;
F_128 ( V_35 , NULL , 0 , V_94 ) ;
F_44 ( ( L_61 , V_35 -> V_53 ) ) ;
}
}
if ( V_35 -> V_162 && V_3 -> V_9 ) {
V_160 = V_35 -> V_162 ;
V_159 = V_35 -> V_163 ;
}
F_111 ( V_35 , V_15 ) ;
if ( V_160 ) F_95 ( V_3 , V_160 , V_159 ) ;
return 0 ;
}
static int
F_135 ( struct V_164 * V_164 , struct V_13 * V_132 )
{
T_1 * V_35 ;
struct V_1 * V_2 ;
struct V_93 * V_94 ;
F_106 ( V_134 , V_3 ) ;
unsigned long V_15 ;
unsigned long V_159 = 0UL ;
void * V_165 = NULL ;
int V_166 = 1 ;
int V_161 , V_73 ;
F_44 ( ( L_62 , V_132 -> V_135 ) ) ;
if ( F_107 ( V_132 ) == 0 ) {
F_44 ( ( L_63 ) ) ;
return - V_153 ;
}
V_35 = V_132 -> V_135 ;
if ( V_35 == NULL ) {
F_67 ( V_74 L_64 , F_64 ( V_3 ) ) ;
return - V_153 ;
}
F_108 ( V_35 , V_15 ) ;
V_161 = V_35 -> V_53 ;
V_73 = V_35 -> V_57 ;
V_2 = F_133 ( V_35 ) ;
V_94 = F_124 ( V_2 ) ;
F_44 ( ( L_58 ,
V_161 ,
V_2 == V_3 ? 1 : 0 ) ) ;
if ( V_161 == V_54 ) goto V_167;
if ( V_161 == V_75 && F_136 ( V_35 ) == 0 ) {
V_35 -> V_168 = 1 ;
F_137 ( & V_35 -> V_61 ) ;
F_44 ( ( L_65 , V_161 ) ) ;
F_110 ( V_136 ) ;
F_109 ( & V_35 -> V_65 , & V_134 ) ;
F_111 ( V_35 , V_15 ) ;
F_113 () ;
F_108 ( V_35 , V_15 ) ;
F_114 ( & V_35 -> V_65 , & V_134 ) ;
F_110 ( V_141 ) ;
F_44 ( ( L_66 , V_161 ) ) ;
}
else if ( V_2 != V_3 ) {
#ifdef F_134
V_35 -> V_53 = V_169 ;
F_44 ( ( L_67 , F_64 ( V_2 ) ) ) ;
V_166 = 0 ;
#else
F_128 ( V_35 , NULL , 0 , V_94 ) ;
#endif
}
V_167:
V_161 = V_35 -> V_53 ;
if ( V_35 -> V_170 ) {
V_165 = V_35 -> V_170 ;
V_159 = V_35 -> V_163 ;
V_35 -> V_170 = NULL ;
V_35 -> V_171 = 0 ;
}
F_44 ( ( L_68 ,
V_161 ,
V_166 ,
V_165 ,
V_159 ) ) ;
if ( V_165 ) F_98 ( V_35 -> V_172 ) ;
if ( V_161 == V_169 ) {
F_94 ( V_35 , V_35 -> V_57 , V_35 -> V_156 ) ;
}
V_132 -> V_135 = NULL ;
F_111 ( V_35 , V_15 ) ;
if ( V_165 ) F_51 ( V_165 , V_159 ) ;
if ( V_166 ) F_59 ( V_35 ) ;
return 0 ;
}
static int
F_138 ( struct V_164 * V_173 , struct V_13 * V_174 )
{
F_44 ( ( L_69 ) ) ;
return - V_175 ;
}
static int
F_139 ( const struct V_17 * V_17 )
{
return 1 ;
}
static char * F_140 ( struct V_17 * V_17 , char * V_176 , int V_177 )
{
return F_141 ( V_17 , V_176 , V_177 , L_70 ,
V_17 -> V_178 -> V_179 ) ;
}
static struct V_13 *
F_142 ( T_1 * V_35 )
{
struct V_13 * V_13 ;
struct V_164 * V_164 ;
struct V_180 V_180 ;
struct V_181 V_182 = { . V_183 = L_71 } ;
V_164 = F_143 ( V_131 -> V_184 ) ;
if ( ! V_164 )
return F_144 ( - V_185 ) ;
F_44 ( ( L_72 , V_164 -> V_179 , V_164 ) ) ;
V_164 -> V_186 = V_187 | V_188 ;
V_164 -> V_189 = F_145 () ;
V_164 -> V_190 = F_146 () ;
V_180 . V_17 = F_147 ( V_131 -> V_184 -> V_191 , & V_182 ) ;
if ( ! V_180 . V_17 ) {
F_148 ( V_164 ) ;
return F_144 ( - V_185 ) ;
}
V_180 . V_192 = F_149 ( V_131 ) ;
F_150 ( V_180 . V_17 , V_164 ) ;
V_13 = F_151 ( & V_180 , V_193 , & V_194 ) ;
if ( ! V_13 ) {
F_152 ( & V_180 ) ;
return F_144 ( - V_195 ) ;
}
V_13 -> V_138 = V_196 ;
V_13 -> V_135 = V_35 ;
return V_13 ;
}
static int
F_153 ( struct V_197 * V_198 , unsigned long V_92 , unsigned long V_10 , unsigned long V_48 )
{
F_44 ( ( L_73 , F_91 () , V_92 , V_10 , V_48 ) ) ;
while ( V_48 > 0 ) {
unsigned long V_199 = F_154 ( V_92 ) >> V_200 ;
if ( F_155 ( V_198 , V_10 , V_199 , V_50 , V_201 ) )
return - V_185 ;
V_10 += V_50 ;
V_92 += V_50 ;
V_48 -= V_50 ;
}
return 0 ;
}
static int
F_156 ( struct V_1 * V_2 , struct V_13 * V_132 , T_1 * V_35 , unsigned long V_202 , void * * V_203 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_197 * V_198 = NULL ;
unsigned long V_48 ;
void * V_204 ;
V_48 = F_49 ( V_202 ) ;
F_44 ( ( L_74 , V_202 , V_48 ) ) ;
if ( V_48 > F_157 ( V_2 , V_205 ) )
return - V_185 ;
V_204 = F_48 ( V_48 ) ;
if ( V_204 == NULL ) {
F_44 ( ( L_75 ) ) ;
return - V_185 ;
}
F_44 ( ( L_76 , V_204 ) ) ;
V_198 = F_158 ( V_206 , V_52 ) ;
if ( ! V_198 ) {
F_44 ( ( L_77 ) ) ;
goto V_207;
}
F_159 ( & V_198 -> V_208 ) ;
V_198 -> V_209 = V_9 ;
V_198 -> V_210 = V_132 ;
V_198 -> V_211 = V_212 | V_213 | V_214 ;
V_198 -> V_215 = V_201 ;
V_35 -> V_170 = V_204 ;
V_35 -> V_163 = V_48 ;
F_96 ( & V_2 -> V_9 -> V_128 ) ;
V_198 -> V_216 = F_14 ( NULL , 0 , V_48 , 0 , V_217 | V_218 , 0 ) ;
if ( V_198 -> V_216 == 0UL ) {
F_44 ( ( L_78 , V_48 ) ) ;
F_97 ( & V_2 -> V_9 -> V_128 ) ;
goto error;
}
V_198 -> V_219 = V_198 -> V_216 + V_48 ;
V_198 -> V_220 = V_198 -> V_216 >> V_200 ;
F_44 ( ( L_79 , V_48 , V_35 -> V_170 , V_198 -> V_216 ) ) ;
if ( F_153 ( V_198 , ( unsigned long ) V_204 , V_198 -> V_216 , V_48 ) ) {
F_44 ( ( L_80 ) ) ;
F_97 ( & V_2 -> V_9 -> V_128 ) ;
goto error;
}
F_160 ( V_132 ) ;
F_161 ( V_9 , V_198 ) ;
V_9 -> V_221 += V_48 >> V_200 ;
F_162 ( V_198 -> V_209 , V_198 -> V_211 , V_198 -> V_210 ,
F_163 ( V_198 ) ) ;
F_97 ( & V_2 -> V_9 -> V_128 ) ;
V_35 -> V_162 = ( void * ) V_198 -> V_216 ;
* ( unsigned long * ) V_203 = V_198 -> V_216 ;
return 0 ;
error:
F_164 ( V_206 , V_198 ) ;
V_207:
F_51 ( V_204 , V_48 ) ;
return - V_185 ;
}
static int
F_165 ( struct V_1 * V_2 )
{
const struct V_222 * V_223 ;
T_13 V_224 = F_166 () ;
T_14 V_225 = F_167 () ;
int V_95 ;
F_168 () ;
V_223 = F_169 ( V_2 ) ;
F_44 ( ( L_81 ,
V_224 ,
V_225 ,
V_223 -> V_226 ,
V_223 -> V_227 ,
V_223 -> V_224 ,
V_223 -> V_228 ,
V_223 -> V_229 ) ) ;
V_95 = ( ( V_224 != V_223 -> V_226 )
|| ( V_224 != V_223 -> V_227 )
|| ( V_224 != V_223 -> V_224 )
|| ( V_225 != V_223 -> V_228 )
|| ( V_225 != V_223 -> V_229 )
|| ( V_225 != V_223 -> V_225 ) ) && ! F_170 ( V_230 ) ;
F_171 () ;
return V_95 ;
}
static int
F_172 ( struct V_1 * V_2 , T_15 * V_231 )
{
int V_51 ;
V_51 = V_231 -> V_51 ;
if ( V_51 & V_58 ) {
if ( V_51 & V_56 ) {
F_44 ( ( L_82 ) ) ;
return - V_113 ;
}
} else {
}
return 0 ;
}
static int
F_173 ( struct V_1 * V_2 , struct V_13 * V_132 , T_1 * V_35 , unsigned int V_51 ,
unsigned int V_97 , T_15 * V_98 )
{
T_5 * V_91 = NULL ;
unsigned long V_48 = 0UL ;
void * V_232 = NULL ;
void * V_233 = NULL ;
int V_95 = 0 ;
#define F_174 ( V_4 ) (pfm_buffer_fmt_t *)(a+1)
V_91 = F_84 ( V_98 -> V_234 ) ;
if ( V_91 == NULL ) {
F_44 ( ( L_83 , F_64 ( V_2 ) ) ) ;
return - V_113 ;
}
if ( V_91 -> V_235 ) V_233 = F_174 ( V_98 ) ;
V_95 = F_77 ( V_91 , V_2 , V_51 , V_97 , V_233 ) ;
F_44 ( ( L_84 , F_64 ( V_2 ) , V_51 , V_97 , V_233 , V_95 ) ) ;
if ( V_95 ) goto error;
V_35 -> V_172 = V_91 ;
V_35 -> V_171 = 1 ;
V_95 = F_76 ( V_91 , V_2 , V_51 , V_97 , V_233 , & V_48 ) ;
if ( V_95 ) goto error;
if ( V_48 ) {
V_95 = F_156 ( V_3 , V_132 , V_35 , V_48 , & V_232 ) ;
if ( V_95 ) goto error;
V_98 -> V_162 = V_232 ;
}
V_95 = F_78 ( V_91 , V_2 , V_35 -> V_170 , V_51 , V_97 , V_233 ) ;
error:
return V_95 ;
}
static void
F_175 ( T_1 * V_35 )
{
int V_32 ;
for ( V_32 = 1 ; F_176 ( V_32 ) == 0 ; V_32 ++ ) {
if ( F_177 ( V_32 ) == 0 ) continue;
V_35 -> V_79 [ V_32 ] = F_178 ( V_32 ) ;
F_44 ( ( L_12 , V_32 , V_35 -> V_79 [ V_32 ] ) ) ;
}
V_35 -> V_88 [ 0 ] = V_37 -> V_236 [ 0 ] & ~ 0x1 ;
V_35 -> V_86 [ 0 ] = V_37 -> V_237 [ 0 ] ;
F_44 ( ( L_85 , V_35 -> V_146 , V_35 -> V_88 [ 0 ] , V_35 -> V_86 [ 0 ] ) ) ;
V_35 -> V_238 [ 0 ] = 0UL ;
V_35 -> V_239 [ 0 ] = 0UL ;
}
static int
F_179 ( void * V_98 , T_2 * V_240 )
{
T_15 * V_241 = ( T_15 * ) V_98 ;
T_5 * V_91 ;
* V_240 = 0 ;
if ( ! F_74 ( V_241 -> V_234 , V_242 ) ) return 0 ;
V_91 = F_84 ( V_241 -> V_234 ) ;
if ( V_91 == NULL ) {
F_44 ( ( L_86 ) ) ;
return - V_113 ;
}
* V_240 = V_91 -> V_235 ;
F_44 ( ( L_87 , * V_240 ) ) ;
return 0 ;
}
static int
F_180 ( T_1 * V_35 , struct V_1 * V_2 )
{
if ( V_2 -> V_9 == NULL ) {
F_44 ( ( L_88 , F_64 ( V_2 ) ) ) ;
return - V_243 ;
}
if ( F_165 ( V_2 ) ) {
F_44 ( ( L_89 , F_64 ( V_2 ) ) ) ;
return - V_243 ;
}
if ( F_136 ( V_35 ) == 0 && V_2 == V_3 ) {
F_44 ( ( L_90 , F_64 ( V_2 ) ) ) ;
return - V_113 ;
}
if ( V_2 -> V_244 == V_245 ) {
F_44 ( ( L_91 , F_64 ( V_2 ) ) ) ;
return - V_115 ;
}
if ( V_2 == V_3 ) return 0 ;
if ( ! F_181 ( V_2 ) ) {
F_44 ( ( L_92 , F_64 ( V_2 ) , V_2 -> V_161 ) ) ;
return - V_115 ;
}
F_182 ( V_2 , 0 ) ;
return 0 ;
}
static int
F_183 ( T_1 * V_35 , T_16 V_246 , struct V_1 * * V_2 )
{
struct V_1 * V_247 = V_3 ;
int V_95 ;
if ( V_246 < 2 ) return - V_243 ;
if ( V_246 != F_184 ( V_3 ) ) {
F_185 ( & V_248 ) ;
V_247 = F_186 ( V_246 ) ;
if ( V_247 ) F_187 ( V_247 ) ;
F_188 ( & V_248 ) ;
if ( V_247 == NULL ) return - V_249 ;
}
V_95 = F_180 ( V_35 , V_247 ) ;
if ( V_95 == 0 ) {
* V_2 = V_247 ;
} else if ( V_247 != V_3 ) {
F_1 ( V_247 ) ;
}
return V_95 ;
}
static int
F_189 ( T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 )
{
T_15 * V_241 = ( T_15 * ) V_98 ;
struct V_13 * V_132 ;
struct V_180 V_180 ;
int V_51 ;
int V_150 ;
int V_95 ;
V_95 = F_172 ( V_3 , V_241 ) ;
if ( V_95 < 0 )
return V_95 ;
V_51 = V_241 -> V_51 ;
V_95 = - V_185 ;
V_150 = F_190 () ;
if ( V_150 < 0 )
return V_150 ;
V_35 = F_53 ( V_51 ) ;
if ( ! V_35 )
goto error;
V_132 = F_142 ( V_35 ) ;
if ( F_103 ( V_132 ) ) {
V_95 = F_102 ( V_132 ) ;
goto V_251;
}
V_241 -> V_146 = V_35 -> V_146 = V_150 ;
if ( F_74 ( V_241 -> V_234 , V_242 ) ) {
V_95 = F_173 ( V_3 , V_132 , V_35 , V_51 , 0 , V_241 ) ;
if ( V_95 )
goto V_252;
}
F_44 ( ( L_93 ,
V_35 ,
V_51 ,
V_35 -> V_57 ,
V_35 -> V_55 ,
V_35 -> V_253 ,
V_35 -> V_59 ,
V_35 -> V_146 ) ) ;
F_175 ( V_35 ) ;
F_191 ( V_150 , V_132 ) ;
return 0 ;
V_252:
V_180 = V_132 -> V_254 ;
F_192 ( V_132 ) ;
F_152 ( & V_180 ) ;
if ( V_35 -> V_172 ) {
F_75 ( V_35 -> V_172 , V_3 , NULL , V_94 ) ;
}
V_251:
F_59 ( V_35 ) ;
error:
F_193 ( V_150 ) ;
return V_95 ;
}
static inline unsigned long
F_194 ( T_17 * V_255 , int V_256 )
{
unsigned long V_28 = V_256 ? V_255 -> V_257 : V_255 -> V_258 ;
unsigned long V_259 , V_260 = V_255 -> V_261 , V_66 = V_255 -> V_66 ;
extern unsigned long V_262 ( unsigned long V_261 ) ;
if ( V_255 -> V_15 & V_263 ) {
V_259 = V_262 ( V_260 ) ;
V_28 -= ( V_260 & V_66 ) ;
if ( ( V_66 >> 32 ) != 0 )
V_259 |= V_262 ( V_260 >> 32 ) << 32 ;
V_255 -> V_261 = V_259 ;
}
V_255 -> V_264 = V_28 ;
return V_28 ;
}
static void
F_195 ( T_1 * V_35 , unsigned long * V_265 , int V_256 )
{
unsigned long V_66 = V_265 [ 0 ] ;
unsigned long V_266 = 0UL ;
unsigned long V_28 ;
int V_32 ;
V_66 >>= V_70 ;
for( V_32 = V_70 ; V_66 ; V_32 ++ , V_66 >>= 1 ) {
if ( ( V_66 & 0x1UL ) == 0UL ) continue;
V_35 -> V_36 [ V_32 ] . V_28 = V_28 = F_194 ( V_35 -> V_36 + V_32 , V_256 ) ;
V_266 |= V_35 -> V_36 [ V_32 ] . V_267 [ 0 ] ;
F_63 ( ( L_94 , V_256 ? L_95 : L_96 , V_32 , V_28 ) ) ;
}
for( V_32 = 0 ; V_266 ; V_32 ++ , V_266 >>= 1 ) {
if ( ( V_266 & 0x1 ) == 0 ) continue;
V_35 -> V_36 [ V_32 ] . V_28 = V_28 = F_194 ( V_35 -> V_36 + V_32 , V_256 ) ;
F_63 ( ( L_97 ,
V_256 ? L_95 : L_96 , V_32 , V_28 ) ) ;
}
}
static void
F_196 ( T_1 * V_35 , unsigned long * V_265 , int V_256 )
{
unsigned long V_66 = V_265 [ 0 ] ;
unsigned long V_266 = 0UL ;
unsigned long V_28 ;
int V_32 ;
F_63 ( ( L_98 , V_265 [ 0 ] , V_256 ) ) ;
if ( V_35 -> V_53 == V_75 ) {
F_195 ( V_35 , V_265 , V_256 ) ;
return;
}
V_66 >>= V_70 ;
for( V_32 = V_70 ; V_66 ; V_32 ++ , V_66 >>= 1 ) {
if ( ( V_66 & 0x1UL ) == 0UL ) continue;
V_28 = F_194 ( V_35 -> V_36 + V_32 , V_256 ) ;
V_266 |= V_35 -> V_36 [ V_32 ] . V_267 [ 0 ] ;
F_63 ( ( L_94 , V_256 ? L_95 : L_96 , V_32 , V_28 ) ) ;
F_41 ( V_35 , V_32 , V_28 ) ;
}
for( V_32 = 0 ; V_266 ; V_32 ++ , V_266 >>= 1 ) {
if ( ( V_266 & 0x1 ) == 0 ) continue;
V_28 = F_194 ( V_35 -> V_36 + V_32 , V_256 ) ;
if ( F_65 ( V_32 ) ) {
F_41 ( V_35 , V_32 , V_28 ) ;
} else {
F_42 ( V_32 , V_28 ) ;
}
F_63 ( ( L_97 ,
V_256 ? L_95 : L_96 , V_32 , V_28 ) ) ;
}
F_31 () ;
}
static int
F_197 ( T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 )
{
struct V_1 * V_2 ;
T_18 * V_241 = ( T_18 * ) V_98 ;
unsigned long V_268 , V_269 ;
unsigned long V_270 , V_267 , V_237 ;
unsigned int V_271 , V_272 , V_15 , V_273 ;
int V_32 , V_274 = 0 , V_275 , V_73 , V_276 ;
int V_277 , V_278 , V_161 ;
int V_95 = - V_113 ;
T_19 V_279 ;
#define F_198 ( V_5 , T_20 , T_21 ) ((x)->ctx_fl_system ^ PMC_PM(y, z))
V_161 = V_35 -> V_53 ;
V_275 = V_161 == V_280 ? 1 : 0 ;
V_73 = V_35 -> V_57 ;
V_2 = V_35 -> V_157 ;
V_237 = V_37 -> V_237 [ 0 ] ;
if ( V_161 == V_169 ) return - V_113 ;
if ( V_275 ) {
if ( V_73 && V_35 -> V_156 != F_91 () ) {
F_44 ( ( L_59 , V_35 -> V_156 ) ) ;
return - V_115 ;
}
V_274 = F_125 () == V_2 || V_73 ? 1 : 0 ;
}
V_276 = V_281 . V_276 ;
for ( V_32 = 0 ; V_32 < V_250 ; V_32 ++ , V_241 ++ ) {
V_271 = V_241 -> V_282 ;
V_272 = V_241 -> V_272 ;
V_268 = V_241 -> V_283 ;
V_270 = V_241 -> V_284 [ 0 ] ;
V_267 = V_241 -> V_285 [ 0 ] ;
V_15 = 0 ;
if ( V_271 >= V_286 ) {
F_44 ( ( L_99 , V_271 ) ) ;
goto error;
}
V_273 = V_37 -> V_287 [ V_271 ] . type ;
V_269 = ( V_268 >> V_37 -> V_287 [ V_271 ] . V_288 ) & 0x1 ;
V_278 = ( V_273 & V_289 ) == V_289 ? 1 : 0 ;
V_277 = ( V_273 & V_290 ) == V_290 ? 1 : 0 ;
if ( ( V_273 & V_291 ) == 0 || ( V_273 & V_292 ) == V_292 ) {
F_44 ( ( L_100 , V_271 , V_273 ) ) ;
goto error;
}
V_279 = V_37 -> V_287 [ V_271 ] . V_293 ;
if ( V_277 && V_268 != F_178 ( V_271 ) && V_73 ^ V_269 ) {
F_44 ( ( L_101 ,
V_271 ,
V_269 ,
V_73 ) ) ;
goto error;
}
if ( V_278 ) {
V_268 |= 1 << V_294 ;
if ( V_272 & V_295 ) {
V_15 |= V_295 ;
}
if ( V_272 & V_263 ) V_15 |= V_263 ;
if ( ( V_270 & V_237 ) != V_270 ) {
F_44 ( ( L_102 , V_270 , V_271 ) ) ;
goto error;
}
if ( ( V_267 & V_237 ) != V_267 ) {
F_44 ( ( L_103 , V_267 , V_271 ) ) ;
goto error;
}
} else {
if ( V_272 & ( V_295 | V_263 ) ) {
F_44 ( ( L_104 , V_271 ) ) ;
goto error;
}
}
if ( F_199 ( V_276 == 0 && V_279 ) ) {
V_95 = (* V_279)( V_2 , V_35 , V_271 , & V_268 , V_94 ) ;
if ( V_95 ) goto error;
V_95 = - V_113 ;
}
F_200 ( V_241 -> V_272 , 0 ) ;
if ( V_278 ) {
V_35 -> V_36 [ V_271 ] . V_15 = V_15 ;
V_35 -> V_36 [ V_271 ] . V_267 [ 0 ] = V_267 ;
V_35 -> V_36 [ V_271 ] . V_270 [ 0 ] = V_270 ;
V_35 -> V_36 [ V_271 ] . V_296 = V_241 -> V_297 ;
F_201 ( V_35 , V_267 ) ;
F_201 ( V_35 , V_270 ) ;
if ( V_161 == V_75 ) V_35 -> V_298 [ 0 ] &= ~ 1UL << V_271 ;
}
F_201 ( V_35 , V_37 -> V_287 [ V_271 ] . V_299 [ 0 ] ) ;
if ( V_277 ) F_202 ( V_35 , 1UL << V_271 ) ;
V_35 -> V_79 [ V_271 ] = V_268 ;
if ( V_275 ) {
if ( V_73 == 0 ) V_35 -> V_71 [ V_271 ] = V_268 ;
if ( V_274 ) {
F_30 ( V_271 , V_268 ) ;
}
#ifdef F_134
else {
V_35 -> V_300 [ 0 ] |= 1UL << V_271 ;
}
#endif
}
F_44 ( ( L_105 ,
V_271 ,
V_268 ,
V_275 ,
V_274 ,
V_15 ,
V_35 -> V_88 [ 0 ] ,
V_35 -> V_68 [ 0 ] ,
V_35 -> V_36 [ V_271 ] . V_296 ,
V_270 ,
V_267 ,
V_35 -> V_300 [ 0 ] ,
V_35 -> V_69 [ 0 ] ,
V_35 -> V_298 [ 0 ] ) ) ;
}
if ( V_274 ) F_31 () ;
return 0 ;
error:
F_200 ( V_241 -> V_272 , V_301 ) ;
return V_95 ;
}
static int
F_203 ( T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 )
{
struct V_1 * V_2 ;
T_18 * V_241 = ( T_18 * ) V_98 ;
unsigned long V_268 , V_302 , V_67 ;
unsigned int V_271 ;
int V_32 , V_274 = 0 , V_161 ;
int V_278 , V_275 , V_73 , V_276 ;
int V_95 = - V_113 ;
T_19 V_279 ;
V_161 = V_35 -> V_53 ;
V_275 = V_161 == V_280 ? 1 : 0 ;
V_73 = V_35 -> V_57 ;
V_67 = V_37 -> V_38 ;
V_2 = V_35 -> V_157 ;
if ( F_204 ( V_161 == V_169 ) ) return - V_113 ;
if ( F_199 ( V_275 ) ) {
if ( F_204 ( V_73 && V_35 -> V_156 != F_91 () ) ) {
F_44 ( ( L_59 , V_35 -> V_156 ) ) ;
return - V_115 ;
}
V_274 = F_125 () == V_2 || V_73 ? 1 : 0 ;
}
V_276 = V_281 . V_276 ;
for ( V_32 = 0 ; V_32 < V_250 ; V_32 ++ , V_241 ++ ) {
V_271 = V_241 -> V_282 ;
V_268 = V_241 -> V_283 ;
if ( ! F_205 ( V_271 ) ) {
F_44 ( ( L_106 , V_271 ) ) ;
goto V_303;
}
V_278 = F_65 ( V_271 ) ;
V_279 = V_37 -> V_304 [ V_271 ] . V_293 ;
if ( F_204 ( V_276 == 0 && V_279 ) ) {
unsigned long V_305 = V_268 ;
V_95 = (* V_279)( V_2 , V_35 , V_271 , & V_305 , V_94 ) ;
if ( V_95 ) goto V_303;
V_268 = V_305 ;
V_95 = - V_113 ;
}
F_200 ( V_241 -> V_272 , 0 ) ;
V_302 = V_268 ;
if ( V_278 ) {
V_35 -> V_36 [ V_271 ] . V_264 = V_268 ;
if ( V_275 ) {
V_302 = V_268 & V_67 ;
V_268 = V_268 & ~ V_67 ;
}
}
V_35 -> V_36 [ V_271 ] . V_257 = V_241 -> V_306 ;
V_35 -> V_36 [ V_271 ] . V_258 = V_241 -> V_307 ;
V_35 -> V_36 [ V_271 ] . V_261 = V_241 -> V_308 ;
V_35 -> V_36 [ V_271 ] . V_66 = V_241 -> V_309 ;
V_35 -> V_36 [ V_271 ] . V_28 = V_268 ;
F_201 ( V_35 , F_206 ( V_271 ) ) ;
F_201 ( V_35 , F_207 ( V_271 ) ) ;
if ( V_278 && V_161 == V_75 ) {
V_35 -> V_298 [ 0 ] &= ~ 1UL << V_271 ;
}
if ( V_275 ) {
if ( V_73 == 0 ) V_35 -> V_87 [ V_271 ] = V_302 ;
if ( V_274 ) {
F_42 ( V_271 , V_302 ) ;
} else {
#ifdef F_134
V_35 -> V_310 [ 0 ] |= 1UL << V_271 ;
#endif
}
}
F_44 ( ( L_107
L_108 ,
V_271 ,
V_268 ,
V_275 ,
V_274 ,
V_302 ,
V_35 -> V_36 [ V_271 ] . V_28 ,
V_35 -> V_36 [ V_271 ] . V_258 ,
V_35 -> V_36 [ V_271 ] . V_257 ,
F_208 ( V_35 , V_271 ) ? 'Y' : 'N' ,
V_35 -> V_36 [ V_271 ] . V_261 ,
V_35 -> V_36 [ V_271 ] . V_66 ,
V_35 -> V_68 [ 0 ] ,
V_35 -> V_36 [ V_271 ] . V_267 [ 0 ] ,
V_35 -> V_310 [ 0 ] ,
V_35 -> V_86 [ 0 ] ,
V_35 -> V_298 [ 0 ] ) ) ;
}
if ( V_274 ) F_31 () ;
return 0 ;
V_303:
F_200 ( V_241 -> V_272 , V_301 ) ;
return V_95 ;
}
static int
F_209 ( T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 )
{
struct V_1 * V_2 ;
unsigned long V_28 = 0UL , V_264 , V_67 , V_311 ;
T_18 * V_241 = ( T_18 * ) V_98 ;
unsigned int V_271 , V_272 = 0 ;
int V_32 , V_274 = 0 , V_161 ;
int V_275 , V_73 , V_278 , V_276 ;
int V_95 = - V_113 ;
T_19 V_312 ;
V_161 = V_35 -> V_53 ;
V_275 = V_161 == V_280 ? 1 : 0 ;
V_73 = V_35 -> V_57 ;
V_67 = V_37 -> V_38 ;
V_2 = V_35 -> V_157 ;
if ( V_161 == V_169 ) return - V_113 ;
if ( F_199 ( V_275 ) ) {
if ( F_204 ( V_73 && V_35 -> V_156 != F_91 () ) ) {
F_44 ( ( L_59 , V_35 -> V_156 ) ) ;
return - V_115 ;
}
V_274 = F_125 () == V_2 || V_73 ? 1 : 0 ;
if ( V_274 ) F_31 () ;
}
V_276 = V_281 . V_276 ;
F_44 ( ( L_109 ,
V_275 ,
V_274 ,
V_161 ) ) ;
for ( V_32 = 0 ; V_32 < V_250 ; V_32 ++ , V_241 ++ ) {
V_271 = V_241 -> V_282 ;
V_272 = V_241 -> V_272 ;
if ( F_204 ( ! F_205 ( V_271 ) ) ) goto error;
if ( F_204 ( ! F_210 ( V_35 , V_271 ) ) ) goto error;
V_311 = V_35 -> V_36 [ V_271 ] . V_28 ;
V_264 = V_35 -> V_36 [ V_271 ] . V_264 ;
V_278 = F_65 ( V_271 ) ;
if ( V_274 ) {
V_28 = F_40 ( V_271 ) ;
} else {
V_28 = V_275 ? V_35 -> V_87 [ V_271 ] : 0UL ;
}
V_312 = V_37 -> V_304 [ V_271 ] . V_313 ;
if ( V_278 ) {
V_28 &= V_67 ;
V_28 += V_311 ;
}
if ( F_204 ( V_276 == 0 && V_312 ) ) {
unsigned long V_305 = V_28 ;
V_95 = (* V_312)( V_35 -> V_157 , V_35 , V_271 , & V_305 , V_94 ) ;
if ( V_95 ) goto error;
V_28 = V_305 ;
V_95 = - V_113 ;
}
F_200 ( V_272 , 0 ) ;
F_44 ( ( L_110 , V_271 , V_28 ) ) ;
V_241 -> V_283 = V_28 ;
V_241 -> V_272 = V_272 ;
V_241 -> V_314 = V_264 ;
}
return 0 ;
error:
F_200 ( V_241 -> V_272 , V_301 ) ;
return V_95 ;
}
int
F_211 ( struct V_1 * V_2 , void * V_241 , unsigned int V_315 , struct V_93 * V_94 )
{
T_1 * V_35 ;
if ( V_241 == NULL ) return - V_113 ;
V_35 = F_126 () ;
if ( V_35 == NULL ) return - V_113 ;
if ( V_2 != V_3 && V_35 -> V_57 == 0 ) return - V_115 ;
return F_197 ( V_35 , V_241 , V_315 , V_94 ) ;
}
int
F_212 ( struct V_1 * V_2 , void * V_241 , unsigned int V_315 , struct V_93 * V_94 )
{
T_1 * V_35 ;
if ( V_241 == NULL ) return - V_113 ;
V_35 = F_126 () ;
if ( V_35 == NULL ) return - V_113 ;
if ( V_2 != V_3 && V_35 -> V_57 == 0 ) return - V_115 ;
return F_209 ( V_35 , V_241 , V_315 , V_94 ) ;
}
int
F_213 ( struct V_1 * V_2 )
{
T_1 * V_35 = V_2 -> V_316 . V_317 ;
unsigned long V_15 ;
int V_95 = 0 ;
if ( V_37 -> V_318 == 0 ) return 0 ;
F_44 ( ( L_111 , F_64 ( V_2 ) ) ) ;
if ( V_2 -> V_316 . V_15 & V_319 ) return 0 ;
if ( V_35 && V_35 -> V_80 == 1 ) return - 1 ;
F_90 ( V_15 ) ;
if ( V_120 . V_123 > 0 )
V_95 = - 1 ;
else
V_120 . V_320 ++ ;
F_44 ( ( L_112 ,
V_120 . V_320 ,
V_120 . V_123 ,
F_64 ( V_2 ) , V_95 ) ) ;
F_93 ( V_15 ) ;
return V_95 ;
}
int
F_214 ( struct V_1 * V_2 )
{
unsigned long V_15 ;
int V_95 ;
if ( V_37 -> V_318 == 0 ) return 0 ;
F_90 ( V_15 ) ;
if ( V_120 . V_320 == 0 ) {
F_67 ( V_74 L_113 , F_64 ( V_2 ) ) ;
V_95 = - 1 ;
} else {
V_120 . V_320 -- ;
V_95 = 0 ;
}
F_93 ( V_15 ) ;
return V_95 ;
}
static int
F_215 ( T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 )
{
struct V_1 * V_2 ;
T_5 * V_91 ;
T_6 V_321 ;
int V_161 , V_73 ;
int V_95 = 0 ;
V_161 = V_35 -> V_53 ;
V_91 = V_35 -> V_172 ;
V_73 = V_35 -> V_57 ;
V_2 = F_133 ( V_35 ) ;
switch( V_161 ) {
case V_75 :
break;
case V_280 :
if ( F_216 ( V_35 ) && V_91 -> V_104 ) break;
case V_54 :
case V_169 :
F_44 ( ( L_114 , V_161 ) ) ;
return - V_115 ;
default:
F_44 ( ( L_115 , V_161 ) ) ;
return - V_113 ;
}
if ( V_73 && V_35 -> V_156 != F_91 () ) {
F_44 ( ( L_59 , V_35 -> V_156 ) ) ;
return - V_115 ;
}
if ( F_204 ( V_2 == NULL ) ) {
F_67 ( V_74 L_116 , F_64 ( V_3 ) ) ;
return - V_113 ;
}
if ( V_2 == V_3 || V_73 ) {
V_91 = V_35 -> V_172 ;
F_44 ( ( L_117 ,
F_64 ( V_2 ) ,
V_35 -> V_298 [ 0 ] ) ) ;
if ( F_216 ( V_35 ) ) {
F_217 ( V_35 -> V_170 ) ;
V_321 . V_322 . V_323 = 0 ;
V_321 . V_322 . V_324 = 0 ;
if ( V_161 == V_280 )
V_95 = F_80 ( V_91 , V_2 , & V_321 , V_35 -> V_170 , V_94 ) ;
else
V_95 = F_79 ( V_91 , V_2 , & V_321 , V_35 -> V_170 , V_94 ) ;
} else {
V_321 . V_322 . V_323 = 0 ;
V_321 . V_322 . V_324 = 1 ;
}
if ( V_95 == 0 ) {
if ( V_321 . V_322 . V_324 )
F_196 ( V_35 , V_35 -> V_298 , V_325 ) ;
if ( V_321 . V_322 . V_323 == 0 ) {
F_44 ( ( L_118 , F_64 ( V_2 ) ) ) ;
if ( V_161 == V_75 ) F_66 ( V_2 ) ;
} else {
F_44 ( ( L_119 , F_64 ( V_2 ) ) ) ;
}
}
V_35 -> V_298 [ 0 ] = 0UL ;
V_35 -> V_53 = V_280 ;
V_35 -> V_326 = 0 ;
return 0 ;
}
if ( V_161 == V_75 ) {
if ( V_35 -> V_326 == 0 ) return - V_113 ;
V_35 -> V_326 = 0 ;
}
if ( F_136 ( V_35 ) == 0 && V_161 == V_75 ) {
F_44 ( ( L_120 , F_64 ( V_2 ) ) ) ;
F_137 ( & V_35 -> V_61 ) ;
} else {
F_44 ( ( L_121 , F_64 ( V_2 ) ) ) ;
V_35 -> V_327 = V_328 ;
F_218 ( V_2 , 1 ) ;
F_219 ( V_2 ) ;
}
return 0 ;
}
static int
F_220 ( T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 )
{
unsigned int V_329 = * ( unsigned int * ) V_98 ;
V_281 . V_330 = V_329 == 0 ? 0 : 1 ;
F_67 ( V_118 L_122 , V_281 . V_330 ? L_123 : L_124 ) ;
if ( V_329 == 0 ) {
memset ( V_331 , 0 , sizeof( V_331 ) ) ;
for( V_329 = 0 ; V_329 < V_332 ; V_329 ++ ) V_331 [ V_329 ] . V_333 = ~ 0UL ;
}
return 0 ;
}
static int
F_221 ( int V_334 , T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 )
{
struct V_335 * V_316 = NULL ;
struct V_1 * V_2 ;
T_22 * V_241 = ( T_22 * ) V_98 ;
unsigned long V_15 ;
T_23 V_336 ;
unsigned int V_337 ;
int V_338 ;
int V_95 = 0 , V_161 ;
int V_32 , V_274 = 0 ;
int V_73 , V_275 ;
if ( V_37 -> V_318 == 0 ) return - V_113 ;
V_161 = V_35 -> V_53 ;
V_275 = V_161 == V_280 ? 1 : 0 ;
V_73 = V_35 -> V_57 ;
V_2 = V_35 -> V_157 ;
if ( V_161 == V_169 ) return - V_113 ;
if ( V_275 ) {
V_316 = & V_2 -> V_316 ;
if ( F_204 ( V_73 && V_35 -> V_156 != F_91 () ) ) {
F_44 ( ( L_59 , V_35 -> V_156 ) ) ;
return - V_115 ;
}
V_274 = F_125 () == V_2 || V_73 ? 1 : 0 ;
}
V_338 = V_35 -> V_80 == 0 ;
if ( V_275 && ( V_316 -> V_15 & V_319 ) != 0 ) {
F_44 ( ( L_125 , F_64 ( V_2 ) ) ) ;
return - V_115 ;
}
if ( V_275 ) {
F_90 ( V_15 ) ;
if ( V_338 && V_73 ) {
if ( V_120 . V_320 )
V_95 = - V_115 ;
else
V_120 . V_123 ++ ;
}
F_93 ( V_15 ) ;
}
if ( V_95 != 0 ) return V_95 ;
V_35 -> V_80 = 1 ;
if ( V_338 && V_274 ) {
F_44 ( ( L_126 , F_64 ( V_2 ) ) ) ;
for ( V_32 = 0 ; V_32 < V_37 -> V_82 ; V_32 ++ ) {
F_34 ( V_32 , 0UL ) ;
F_35 () ;
}
F_20 () ;
for ( V_32 = 0 ; V_32 < V_37 -> V_84 ; V_32 ++ ) {
F_37 ( V_32 , 0UL ) ;
F_38 () ;
}
F_31 () ;
}
for ( V_32 = 0 ; V_32 < V_250 ; V_32 ++ , V_241 ++ ) {
V_337 = V_241 -> V_339 ;
V_336 . V_28 = V_241 -> V_340 ;
V_95 = - V_113 ;
if ( ( V_334 == V_341 && V_337 >= V_342 ) || ( ( V_334 == V_343 ) && V_337 >= V_344 ) ) {
F_44 ( ( L_127 ,
V_337 , V_336 . V_28 , V_334 , V_32 , V_250 ) ) ;
goto V_303;
}
if ( V_337 & 0x1 ) {
if ( V_334 == V_341 )
V_336 . V_345 . V_346 = 0 ;
else
V_336 . V_347 . V_348 = V_336 . V_347 . V_349 = 0 ;
}
F_200 ( V_241 -> V_350 , 0 ) ;
if ( V_334 == V_341 ) {
F_222 ( V_35 , V_337 ) ;
if ( V_274 ) {
F_34 ( V_337 , V_336 . V_28 ) ;
F_35 () ;
}
V_35 -> V_81 [ V_337 ] = V_336 . V_28 ;
F_44 ( ( L_128 ,
V_337 , V_336 . V_28 , V_35 -> V_238 [ 0 ] , V_275 , V_274 ) ) ;
} else {
F_223 ( V_35 , V_337 ) ;
if ( V_274 ) {
F_37 ( V_337 , V_336 . V_28 ) ;
F_38 () ;
}
V_35 -> V_83 [ V_337 ] = V_336 . V_28 ;
F_44 ( ( L_129 ,
V_337 , V_336 . V_28 , V_35 -> V_239 [ 0 ] , V_275 , V_274 ) ) ;
}
}
return 0 ;
V_303:
if ( V_338 ) {
F_90 ( V_15 ) ;
if ( V_35 -> V_57 ) {
V_120 . V_123 -- ;
}
F_93 ( V_15 ) ;
V_35 -> V_80 = 0 ;
}
F_200 ( V_241 -> V_350 , V_301 ) ;
return V_95 ;
}
static int
F_224 ( T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 )
{
return F_221 ( V_341 , V_35 , V_98 , V_250 , V_94 ) ;
}
static int
F_225 ( T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 )
{
return F_221 ( V_343 , V_35 , V_98 , V_250 , V_94 ) ;
}
int
F_226 ( struct V_1 * V_2 , void * V_241 , unsigned int V_315 , struct V_93 * V_94 )
{
T_1 * V_35 ;
if ( V_241 == NULL ) return - V_113 ;
V_35 = F_126 () ;
if ( V_35 == NULL ) return - V_113 ;
if ( V_2 != V_3 && V_35 -> V_57 == 0 ) return - V_115 ;
return F_224 ( V_35 , V_241 , V_315 , V_94 ) ;
}
int
F_227 ( struct V_1 * V_2 , void * V_241 , unsigned int V_315 , struct V_93 * V_94 )
{
T_1 * V_35 ;
if ( V_241 == NULL ) return - V_113 ;
V_35 = F_126 () ;
if ( V_35 == NULL ) return - V_113 ;
if ( V_2 != V_3 && V_35 -> V_57 == 0 ) return - V_115 ;
return F_225 ( V_35 , V_241 , V_315 , V_94 ) ;
}
static int
F_228 ( T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 )
{
T_24 * V_241 = ( T_24 * ) V_98 ;
V_241 -> V_351 = V_352 ;
return 0 ;
}
static int
F_229 ( T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 )
{
struct V_93 * V_353 ;
struct V_1 * V_2 = F_133 ( V_35 ) ;
int V_161 , V_73 ;
V_161 = V_35 -> V_53 ;
V_73 = V_35 -> V_57 ;
if ( V_161 == V_54 ) return - V_113 ;
if ( V_73 && V_35 -> V_156 != F_91 () ) {
F_44 ( ( L_59 , V_35 -> V_156 ) ) ;
return - V_115 ;
}
F_44 ( ( L_130 ,
F_64 ( F_133 ( V_35 ) ) ,
V_161 ,
V_73 ) ) ;
if ( V_73 ) {
F_28 ( V_77 , F_26 ( V_77 ) & ~ V_78 ) ;
F_20 () ;
F_230 ( V_76 ) ;
F_18 () ;
F_231 ( V_94 ) -> V_354 = 0 ;
return 0 ;
}
if ( V_2 == V_3 ) {
F_23 () ;
F_231 ( V_94 ) -> V_355 = 0 ;
} else {
V_353 = F_124 ( V_2 ) ;
F_231 ( V_353 ) -> V_355 = 0 ;
V_35 -> V_356 = 0 ;
F_44 ( ( L_131 , F_64 ( V_2 ) ) ) ;
}
return 0 ;
}
static int
F_232 ( T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 )
{
struct V_93 * V_353 ;
int V_161 , V_73 ;
V_161 = V_35 -> V_53 ;
V_73 = V_35 -> V_57 ;
if ( V_161 != V_280 ) return - V_113 ;
if ( V_73 && V_35 -> V_156 != F_91 () ) {
F_44 ( ( L_59 , V_35 -> V_156 ) ) ;
return - V_115 ;
}
if ( V_73 ) {
F_231 ( V_94 ) -> V_354 = 1 ;
F_233 ( V_76 ) ;
F_21 () ;
F_28 ( V_77 , F_26 ( V_77 ) | V_78 ) ;
F_20 () ;
return 0 ;
}
if ( V_35 -> V_157 == V_3 ) {
F_24 () ;
F_231 ( V_94 ) -> V_355 = 1 ;
} else {
V_353 = F_124 ( V_35 -> V_157 ) ;
V_35 -> V_356 = V_25 ;
F_231 ( V_353 ) -> V_355 = 1 ;
}
return 0 ;
}
static int
F_234 ( T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 )
{
T_18 * V_241 = ( T_18 * ) V_98 ;
unsigned int V_271 ;
int V_32 ;
int V_95 = - V_113 ;
for ( V_32 = 0 ; V_32 < V_250 ; V_32 ++ , V_241 ++ ) {
V_271 = V_241 -> V_282 ;
if ( ! F_177 ( V_271 ) ) goto V_303;
V_241 -> V_283 = F_178 ( V_271 ) ;
F_200 ( V_241 -> V_272 , 0 ) ;
F_44 ( ( L_132 , V_271 , V_241 -> V_283 ) ) ;
}
return 0 ;
V_303:
F_200 ( V_241 -> V_272 , V_301 ) ;
return V_95 ;
}
static int
F_235 ( T_1 * V_35 )
{
struct V_1 * V_357 , * V_358 ;
int V_95 = - V_249 ;
F_185 ( & V_248 ) ;
F_236 (g, t) {
if ( V_358 -> V_316 . V_317 == V_35 ) {
V_95 = 0 ;
goto V_116;
}
} F_237 ( V_357 , V_358 ) ;
V_116:
F_188 ( & V_248 ) ;
F_44 ( ( L_133 , V_95 , V_35 ) ) ;
return V_95 ;
}
static int
F_238 ( T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 )
{
struct V_1 * V_2 ;
struct V_335 * V_316 ;
struct T_1 * V_359 ;
unsigned long V_15 ;
#ifndef F_134
struct V_1 * V_360 = NULL ;
#endif
T_25 * V_241 = ( T_25 * ) V_98 ;
unsigned long * V_361 , * V_362 ;
int V_363 ;
int V_95 = 0 ;
int V_161 , V_73 , V_364 = 0 ;
V_161 = V_35 -> V_53 ;
V_73 = V_35 -> V_57 ;
if ( V_161 != V_54 ) {
F_44 ( ( L_134 ,
V_241 -> V_365 ,
V_35 -> V_53 ) ) ;
return - V_115 ;
}
F_44 ( ( L_135 , V_241 -> V_365 , V_35 -> V_80 ) ) ;
if ( F_136 ( V_35 ) == 0 && V_241 -> V_365 == V_3 -> V_246 ) {
F_44 ( ( L_136 ) ) ;
return - V_113 ;
}
V_95 = F_183 ( V_35 , V_241 -> V_365 , & V_2 ) ;
if ( V_95 ) {
F_44 ( ( L_137 , V_241 -> V_365 , V_95 ) ) ;
return V_95 ;
}
V_95 = - V_113 ;
if ( V_73 && V_2 != V_3 ) {
F_44 ( ( L_138 ,
V_241 -> V_365 ) ) ;
goto error;
}
V_316 = & V_2 -> V_316 ;
V_95 = 0 ;
if ( V_35 -> V_80 ) {
if ( V_316 -> V_15 & V_319 ) {
V_95 = - V_115 ;
F_44 ( ( L_139 , V_241 -> V_365 ) ) ;
goto error;
}
F_90 ( V_15 ) ;
if ( V_73 ) {
if ( V_120 . V_320 ) {
F_44 ( ( L_140 ,
F_64 ( V_2 ) ) ) ;
V_95 = - V_115 ;
} else {
V_120 . V_123 ++ ;
F_44 ( ( L_141 , F_64 ( V_2 ) , V_120 . V_123 ) ) ;
V_364 = 1 ;
}
}
F_93 ( V_15 ) ;
if ( V_95 ) goto error;
}
V_363 = V_35 -> V_156 = F_91 () ;
V_95 = - V_115 ;
V_95 = F_89 ( V_3 , V_73 , V_363 ) ;
if ( V_95 ) goto error;
F_44 ( ( L_142 ,
V_316 -> V_317 , V_35 ) ) ;
V_95 = - V_115 ;
V_359 = F_239 ( V_366 , & V_316 -> V_317 , NULL , V_35 , sizeof( T_1 * ) ) ;
if ( V_359 != NULL ) {
F_44 ( ( L_143 , V_241 -> V_365 ) ) ;
goto V_367;
}
F_47 ( V_35 ) ;
V_35 -> V_53 = V_280 ;
V_35 -> V_157 = V_2 ;
if ( V_73 ) {
F_233 ( V_368 ) ;
F_230 ( V_76 ) ;
if ( V_35 -> V_253 ) F_233 ( V_369 ) ;
} else {
V_316 -> V_15 |= V_370 ;
}
F_71 ( V_2 , V_35 ) ;
F_72 ( V_2 , V_35 ) ;
V_361 = V_35 -> V_71 ;
V_362 = V_35 -> V_87 ;
if ( V_2 == V_3 ) {
if ( V_73 == 0 ) {
F_231 ( V_94 ) -> V_371 = 0 ;
F_44 ( ( L_144 , F_64 ( V_2 ) ) ) ;
F_57 ( V_35 , F_91 () ) ;
F_240 () ;
F_241 ( V_35 ) ;
#ifndef F_134
V_360 = F_125 () ;
if ( V_360 ) F_242 ( V_360 ) ;
#endif
}
F_70 ( V_362 , V_35 -> V_86 [ 0 ] ) ;
F_73 ( V_361 , V_35 -> V_88 [ 0 ] ) ;
V_35 -> V_300 [ 0 ] = 0UL ;
V_35 -> V_310 [ 0 ] = 0UL ;
if ( V_35 -> V_80 ) {
F_33 ( V_35 -> V_81 , V_37 -> V_82 ) ;
F_36 ( V_35 -> V_83 , V_37 -> V_84 ) ;
}
F_243 ( V_2 , V_35 ) ;
F_44 ( ( L_145 , F_64 ( V_2 ) ) ) ;
} else {
V_94 = F_124 ( V_2 ) ;
V_35 -> V_62 = V_63 ;
F_57 ( V_35 , - 1 ) ;
V_35 -> V_356 = 0UL ;
F_231 ( V_94 ) -> V_355 = F_231 ( V_94 ) -> V_354 = 0 ;
}
V_95 = 0 ;
V_367:
if ( V_95 ) F_94 ( V_35 , V_35 -> V_57 , V_363 ) ;
error:
if ( V_95 && V_364 ) {
F_90 ( V_15 ) ;
V_120 . V_123 -- ;
F_93 ( V_15 ) ;
}
if ( V_73 == 0 && V_2 != V_3 ) {
F_1 ( V_2 ) ;
if ( V_95 == 0 ) {
V_95 = F_235 ( V_35 ) ;
if ( V_95 ) {
V_35 -> V_53 = V_54 ;
V_35 -> V_157 = NULL ;
}
}
}
return V_95 ;
}
static int
F_128 ( T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 )
{
struct V_1 * V_2 = F_133 ( V_35 ) ;
struct V_93 * V_353 ;
int V_372 , V_73 ;
int V_95 ;
F_44 ( ( L_146 , V_35 -> V_53 , V_2 ? F_64 ( V_2 ) : - 1 ) ) ;
V_372 = V_35 -> V_53 ;
V_73 = V_35 -> V_57 ;
if ( V_372 == V_54 ) {
F_44 ( ( L_147 , V_372 ) ) ;
return 0 ;
}
V_95 = F_229 ( V_35 , NULL , 0 , V_94 ) ;
if ( V_95 ) return V_95 ;
V_35 -> V_53 = V_54 ;
if ( V_73 ) {
F_230 ( V_368 ) ;
F_230 ( V_369 ) ;
F_244 ( V_3 , V_35 ) ;
if ( V_372 != V_169 )
F_94 ( V_35 , 1 , V_35 -> V_156 ) ;
V_2 -> V_316 . V_317 = NULL ;
V_35 -> V_157 = NULL ;
return 0 ;
}
V_353 = V_2 == V_3 ? V_94 : F_124 ( V_2 ) ;
if ( V_2 == V_3 ) {
F_231 ( V_94 ) -> V_371 = 1 ;
F_44 ( ( L_148 , F_64 ( V_2 ) ) ) ;
}
F_244 ( V_2 , V_35 ) ;
if ( V_372 != V_169 )
F_94 ( V_35 , 0 , V_35 -> V_156 ) ;
V_35 -> V_62 = V_63 ;
F_57 ( V_35 , - 1 ) ;
V_2 -> V_316 . V_15 &= ~ V_370 ;
V_2 -> V_316 . V_317 = NULL ;
V_35 -> V_157 = NULL ;
F_218 ( V_2 , 0 ) ;
V_35 -> V_327 = V_373 ;
V_35 -> V_326 = 0 ;
V_35 -> V_168 = 0 ;
F_44 ( ( L_149 , F_64 ( V_2 ) ) ) ;
return 0 ;
}
void
F_245 ( struct V_1 * V_2 )
{
T_1 * V_35 ;
unsigned long V_15 ;
struct V_93 * V_94 = F_124 ( V_2 ) ;
int V_95 , V_161 ;
int V_374 = 0 ;
V_35 = F_62 ( V_2 ) ;
F_108 ( V_35 , V_15 ) ;
F_44 ( ( L_150 , V_35 -> V_53 , F_64 ( V_2 ) ) ) ;
V_161 = V_35 -> V_53 ;
switch( V_161 ) {
case V_54 :
F_67 ( V_74 L_151 , F_64 ( V_2 ) ) ;
break;
case V_280 :
case V_75 :
V_95 = F_128 ( V_35 , NULL , 0 , V_94 ) ;
if ( V_95 ) {
F_67 ( V_74 L_152 , F_64 ( V_2 ) , V_161 , V_95 ) ;
}
F_44 ( ( L_153 , V_161 ) ) ;
F_246 ( V_35 ) ;
break;
case V_169 :
V_95 = F_128 ( V_35 , NULL , 0 , V_94 ) ;
if ( V_95 ) {
F_67 ( V_74 L_152 , F_64 ( V_2 ) , V_161 , V_95 ) ;
}
V_374 = 1 ;
break;
default:
F_67 ( V_74 L_154 , F_64 ( V_2 ) , V_161 ) ;
break;
}
F_111 ( V_35 , V_15 ) ;
{ T_26 V_72 = F_25 () ;
F_247 ( V_72 & ( V_25 | V_24 ) ) ;
F_247 ( F_125 () ) ;
F_247 ( F_231 ( V_94 ) -> V_355 ) ;
F_247 ( F_231 ( V_94 ) -> V_354 ) ;
}
if ( V_374 ) F_59 ( V_35 ) ;
}
static int
F_248 ( T_1 * V_35 , int V_149 , unsigned long V_15 )
{
struct V_1 * V_2 ;
int V_161 , V_375 ;
V_376:
V_161 = V_35 -> V_53 ;
V_2 = V_35 -> V_157 ;
if ( V_2 == NULL ) {
F_44 ( ( L_155 , V_35 -> V_146 , V_161 ) ) ;
return 0 ;
}
F_44 ( ( L_156 ,
V_35 -> V_146 ,
V_161 ,
F_64 ( V_2 ) ,
V_2 -> V_161 , F_249 ( V_149 ) ) ) ;
if ( V_2 == V_3 || V_35 -> V_57 ) return 0 ;
switch( V_161 ) {
case V_54 :
return 0 ;
case V_169 :
F_44 ( ( L_157 , V_149 ) ) ;
return - V_113 ;
case V_75 :
if ( V_149 != V_377 ) return 0 ;
}
if ( F_249 ( V_149 ) ) {
if ( ! F_181 ( V_2 ) ) {
F_44 ( ( L_158 , F_64 ( V_2 ) ) ) ;
return - V_115 ;
}
V_375 = V_161 ;
F_111 ( V_35 , V_15 ) ;
F_182 ( V_2 , 0 ) ;
F_108 ( V_35 , V_15 ) ;
if ( V_35 -> V_53 != V_375 ) {
F_44 ( ( L_159 , V_375 , V_35 -> V_53 ) ) ;
goto V_376;
}
}
return 0 ;
}
T_27 long
F_250 ( int V_150 , int V_149 , void T_9 * V_98 , int V_250 )
{
struct V_13 * V_13 = NULL ;
T_1 * V_35 = NULL ;
unsigned long V_15 = 0UL ;
void * V_378 = NULL ;
long V_95 ;
T_2 V_379 , V_240 , V_380 = 0 ;
int V_381 , V_382 = 0 , V_383 = 0 , V_384 ;
int (* F_251)( T_1 * V_35 , void * V_98 , int V_250 , struct V_93 * V_94 );
int (* F_252)( void * V_98 , T_2 * V_240 );
#define F_253 4096
if ( F_204 ( V_37 == NULL ) ) return - V_385 ;
if ( F_204 ( V_149 < 0 || V_149 >= V_386 ) ) {
F_44 ( ( L_160 , V_149 ) ) ;
return - V_113 ;
}
F_251 = V_387 [ V_149 ] . V_388 ;
V_381 = V_387 [ V_149 ] . V_389 ;
V_379 = V_387 [ V_149 ] . V_390 ;
F_252 = V_387 [ V_149 ] . V_391 ;
V_384 = V_387 [ V_149 ] . V_384 ;
if ( F_204 ( F_251 == NULL ) ) {
F_44 ( ( L_160 , V_149 ) ) ;
return - V_113 ;
}
F_44 ( ( L_161 ,
F_254 ( V_149 ) ,
V_149 ,
V_381 ,
V_379 ,
V_250 ) ) ;
if ( F_204 ( ( V_381 == V_392 && V_250 <= 0 ) || ( V_381 > 0 && V_381 != V_250 ) ) )
return - V_113 ;
V_393:
V_240 = V_380 + V_379 * V_250 ;
if ( F_204 ( V_240 > F_253 ) ) {
F_67 ( V_74 L_162 , F_64 ( V_3 ) , V_240 ) ;
return - V_394 ;
}
if ( F_199 ( V_250 && V_378 == NULL ) ) {
V_378 = F_255 ( F_253 , V_52 ) ;
if ( V_378 == NULL ) return - V_185 ;
}
V_95 = - V_144 ;
if ( V_240 && F_256 ( V_378 , V_98 , V_240 ) ) {
F_44 ( ( L_163 , V_240 , V_98 ) ) ;
goto V_395;
}
if ( V_382 == 0 && F_252 ) {
V_95 = (* F_252)( V_378 , & V_380 ) ;
if ( V_95 ) goto V_395;
V_382 = 1 ;
F_44 ( ( L_164 , V_240 , V_380 ) ) ;
if ( F_199 ( V_380 ) ) goto V_393;
}
if ( F_204 ( ( V_384 & V_396 ) == 0 ) ) goto V_397;
V_95 = - V_153 ;
V_13 = F_257 ( V_150 ) ;
if ( F_204 ( V_13 == NULL ) ) {
F_44 ( ( L_165 , V_150 ) ) ;
goto V_395;
}
if ( F_204 ( F_107 ( V_13 ) == 0 ) ) {
F_44 ( ( L_166 , V_150 ) ) ;
goto V_395;
}
V_35 = V_13 -> V_135 ;
if ( F_204 ( V_35 == NULL ) ) {
F_44 ( ( L_167 , V_150 ) ) ;
goto V_395;
}
F_217 ( & V_35 -> V_53 ) ;
F_108 ( V_35 , V_15 ) ;
V_95 = F_248 ( V_35 , V_149 , V_15 ) ;
if ( F_204 ( V_95 ) ) goto V_142;
V_397:
V_95 = (* F_251)( V_35 , V_378 , V_250 , F_124 ( V_3 ) ) ;
V_383 = 1 ;
V_142:
if ( F_199 ( V_35 ) ) {
F_44 ( ( L_168 ) ) ;
F_111 ( V_35 , V_15 ) ;
}
if ( V_383 && F_258 ( V_149 ) && F_115 ( V_98 , V_378 , V_379 * V_250 ) ) V_95 = - V_144 ;
V_395:
if ( V_13 )
F_259 ( V_13 ) ;
F_60 ( V_378 ) ;
F_44 ( ( L_169 , F_254 ( V_149 ) , V_95 ) ) ;
return V_95 ;
}
static void
F_260 ( T_1 * V_35 , unsigned long V_265 , struct V_93 * V_94 )
{
T_5 * V_91 = V_35 -> V_172 ;
T_6 V_321 ;
int V_161 ;
int V_95 = 0 ;
V_161 = V_35 -> V_53 ;
if ( F_216 ( V_35 ) ) {
V_321 . V_322 . V_323 = 0 ;
V_321 . V_322 . V_324 = 0 ;
if ( V_161 == V_280 )
V_95 = F_80 ( V_91 , V_3 , & V_321 , V_35 -> V_170 , V_94 ) ;
else
V_95 = F_79 ( V_91 , V_3 , & V_321 , V_35 -> V_170 , V_94 ) ;
} else {
V_321 . V_322 . V_323 = 0 ;
V_321 . V_322 . V_324 = 1 ;
}
if ( V_95 == 0 ) {
if ( V_321 . V_322 . V_324 ) {
F_196 ( V_35 , & V_265 , V_325 ) ;
}
if ( V_321 . V_322 . V_323 == 0 ) {
F_44 ( ( L_170 ) ) ;
if ( V_35 -> V_53 == V_75 ) F_66 ( V_3 ) ;
} else {
F_44 ( ( L_171 ) ) ;
}
V_35 -> V_53 = V_280 ;
}
}
static void
F_261 ( T_1 * V_35 , struct V_93 * V_94 )
{
int V_95 ;
F_44 ( ( L_172 , F_64 ( V_3 ) ) ) ;
V_95 = F_128 ( V_35 , NULL , 0 , V_94 ) ;
if ( V_95 ) {
F_67 ( V_74 L_173 , F_64 ( V_3 ) , V_95 ) ;
}
F_262 ( & V_35 -> V_65 ) ;
}
void
F_263 ( void )
{
T_1 * V_35 ;
struct V_93 * V_94 ;
unsigned long V_15 , V_398 ;
unsigned long V_265 ;
unsigned int V_399 ;
int V_95 ;
V_35 = F_62 ( V_3 ) ;
if ( V_35 == NULL ) {
F_67 ( V_74 L_174 ,
F_64 ( V_3 ) ) ;
return;
}
F_108 ( V_35 , V_15 ) ;
F_218 ( V_3 , 0 ) ;
V_94 = F_124 ( V_3 ) ;
V_399 = V_35 -> V_327 ;
V_35 -> V_327 = V_373 ;
V_265 = V_35 -> V_298 [ 0 ] ;
F_44 ( ( L_175 , V_399 , V_35 -> V_53 ) ) ;
if ( V_35 -> V_168 || V_35 -> V_53 == V_169 )
goto V_400;
if ( V_399 == V_328 )
goto V_401;
F_111 ( V_35 , V_15 ) ;
F_264 () ;
F_44 ( ( L_176 ) ) ;
V_95 = F_265 ( & V_35 -> V_61 ) ;
F_44 ( ( L_177 , V_95 ) ) ;
F_108 ( V_35 , V_398 ) ;
V_265 = V_35 -> V_298 [ 0 ] ;
if ( V_35 -> V_168 ) {
V_400:
F_44 ( ( L_178 ) ) ;
F_261 ( V_35 , V_94 ) ;
goto V_402;
}
if ( V_95 < 0 )
goto V_402;
V_401:
F_260 ( V_35 , V_265 , V_94 ) ;
V_35 -> V_298 [ 0 ] = 0UL ;
V_402:
F_111 ( V_35 , V_15 ) ;
}
static int
F_266 ( T_1 * V_35 , T_3 * V_45 )
{
if ( V_35 -> V_53 == V_169 ) {
F_44 ( ( L_179 ) ) ;
return 0 ;
}
F_44 ( ( L_180 ) ) ;
if ( V_45 ) F_262 ( & V_35 -> V_64 ) ;
F_267 ( & V_35 -> V_152 , V_403 , V_404 ) ;
return 0 ;
}
static int
F_268 ( T_1 * V_35 , unsigned long V_405 )
{
T_3 * V_45 = NULL ;
if ( V_35 -> V_59 == 0 ) {
V_45 = F_43 ( V_35 ) ;
if ( V_45 == NULL ) {
F_67 ( V_74 L_181 ) ;
return - 1 ;
}
V_45 -> V_406 . V_47 = V_407 ;
V_45 -> V_406 . V_143 = V_35 -> V_146 ;
V_45 -> V_406 . V_408 = 0 ;
V_45 -> V_406 . V_409 [ 0 ] = V_405 ;
V_45 -> V_406 . V_409 [ 1 ] = 0UL ;
V_45 -> V_406 . V_409 [ 2 ] = 0UL ;
V_45 -> V_406 . V_409 [ 3 ] = 0UL ;
V_45 -> V_406 . V_410 = 0UL ;
}
F_44 ( ( L_182 ,
V_45 ,
V_35 -> V_59 ,
V_35 -> V_146 ,
V_405 ) ) ;
return F_266 ( V_35 , V_45 ) ;
}
static int
F_246 ( T_1 * V_35 )
{
T_3 * V_45 ;
V_45 = F_43 ( V_35 ) ;
if ( V_45 == NULL ) {
F_67 ( V_74 L_183 ) ;
return - 1 ;
}
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_411 . V_47 = V_412 ;
V_45 -> V_411 . V_143 = V_35 -> V_146 ;
V_45 -> V_406 . V_410 = 0UL ;
F_44 ( ( L_184 ,
V_45 ,
V_35 -> V_59 ,
V_35 -> V_146 ) ) ;
return F_266 ( V_35 , V_45 ) ;
}
static void F_269 ( struct V_1 * V_2 , T_1 * V_35 ,
unsigned long V_413 , struct V_93 * V_94 )
{
T_28 * V_414 ;
unsigned long V_66 ;
unsigned long V_415 , V_38 , V_416 ;
unsigned long V_417 = 0UL , V_405 = 0UL , V_270 = 0UL , V_267 ;
unsigned long V_418 ;
T_6 V_419 ;
unsigned int V_32 , V_420 ;
int V_421 = 0 ;
if ( F_204 ( V_35 -> V_53 == V_169 ) ) goto V_422;
if ( F_204 ( ( V_413 & 0x1 ) == 0 ) ) goto V_423;
V_418 = F_270 () ;
V_66 = V_413 >> V_70 ;
V_38 = V_37 -> V_38 ;
V_420 = F_216 ( V_35 ) ;
F_63 ( ( L_185
L_186 ,
V_413 ,
V_2 ? F_64 ( V_2 ) : - 1 ,
( V_94 ? V_94 -> V_424 : 0 ) ,
F_136 ( V_35 ) ? L_187 : L_188 ,
V_35 -> V_68 [ 0 ] ) ) ;
for ( V_32 = V_70 ; V_66 ; V_32 ++ , V_66 >>= 1 ) {
if ( ( V_66 & 0x1 ) == 0 ) continue;
V_415 = V_416 = V_35 -> V_36 [ V_32 ] . V_28 ;
V_416 += 1 + V_38 ;
V_35 -> V_36 [ V_32 ] . V_28 = V_416 ;
if ( F_199 ( V_415 > V_416 ) ) {
V_405 |= 1UL << V_32 ;
if ( F_208 ( V_35 , V_32 ) ) V_417 |= 1UL << V_32 ;
}
F_63 ( ( L_189 ,
V_32 ,
V_416 ,
V_415 ,
F_40 ( V_32 ) & V_38 ,
V_405 ,
V_417 ) ) ;
}
if ( V_405 == 0UL ) return;
V_419 . V_28 = 0 ;
V_267 = 0UL ;
if ( V_420 ) {
unsigned long V_425 , V_426 ;
unsigned long V_427 ;
int V_428 , V_429 , V_95 = 0 ;
int V_430 = F_91 () ;
V_427 = V_405 >> V_70 ;
V_414 = & V_35 -> V_431 ;
F_217 ( V_35 -> V_170 ) ;
for( V_32 = V_70 ; V_427 && V_95 == 0 ; V_32 ++ , V_427 >>= 1 ) {
V_66 = 1UL << V_32 ;
if ( ( V_427 & 0x1 ) == 0 ) continue;
V_414 -> V_432 = ( unsigned char ) V_32 ;
V_414 -> V_417 = V_417 & V_66 ? 1 : 0 ;
V_414 -> V_433 = 0 ;
V_414 -> V_419 . V_28 = 0 ;
V_414 -> V_270 [ 0 ] = V_270 = V_35 -> V_36 [ V_32 ] . V_270 [ 0 ] ;
V_414 -> V_434 = V_35 -> V_36 [ V_32 ] . V_28 ;
V_414 -> V_435 = V_35 -> V_36 [ V_32 ] . V_264 ;
V_414 -> V_436 = V_35 -> V_36 [ V_32 ] . V_296 ;
if ( V_270 ) {
for( V_428 = 0 , V_429 = 0 ; V_270 ; V_428 ++ , V_270 >>= 1 ) {
if ( ( V_270 & 0x1 ) == 0 ) continue;
V_414 -> V_437 [ V_429 ++ ] = F_65 ( V_428 ) ? F_39 ( V_35 , V_428 ) : F_40 ( V_428 ) ;
F_63 ( ( L_190 , V_429 - 1 , V_428 , V_414 -> V_437 [ V_429 - 1 ] ) ) ;
}
}
V_331 [ V_430 ] . V_438 ++ ;
V_425 = F_270 () ;
V_95 = (* V_35 -> V_172 -> V_114 )( V_2 , V_35 -> V_170 , V_414 , V_94 , V_418 ) ;
V_426 = F_270 () ;
V_419 . V_322 . V_439 |= V_414 -> V_419 . V_322 . V_439 ;
V_419 . V_322 . V_440 |= V_414 -> V_419 . V_322 . V_440 ;
V_419 . V_322 . V_323 |= V_414 -> V_419 . V_322 . V_323 ;
if ( V_414 -> V_419 . V_322 . V_324 ) V_267 |= V_66 ;
V_331 [ V_430 ] . V_441 += V_426 - V_425 ;
}
if ( V_95 && V_427 ) {
F_44 ( ( L_191 ,
V_427 << V_70 ) ) ;
}
V_405 &= ~ V_267 ;
} else {
V_419 . V_322 . V_439 = V_417 ? 1 : 0 ;
V_419 . V_322 . V_440 = V_417 ? 1 : 0 ;
V_419 . V_322 . V_323 = V_417 ? 1 : 0 ;
V_419 . V_322 . V_324 = V_417 ? 0 : 1 ;
if ( V_417 == 0 ) V_267 = V_405 ;
}
F_63 ( ( L_192 , V_405 , V_267 ) ) ;
if ( V_267 ) {
unsigned long V_442 = V_267 ;
F_196 ( V_35 , & V_442 , V_443 ) ;
}
if ( V_417 && V_419 . V_322 . V_439 ) {
V_35 -> V_298 [ 0 ] = V_405 ;
if ( F_136 ( V_35 ) == 0 && V_419 . V_322 . V_440 ) {
V_35 -> V_327 = V_444 ;
F_218 ( V_2 , 1 ) ;
F_219 ( V_2 ) ;
}
V_421 = 1 ;
}
F_63 ( ( L_193 ,
F_125 () ? F_64 ( F_125 () ) : - 1 ,
F_271 ( V_2 ) ,
V_35 -> V_327 ,
V_405 ,
V_417 ,
V_419 . V_322 . V_323 ? 1 : 0 ) ) ;
if ( V_419 . V_322 . V_323 ) {
F_61 ( V_2 ) ;
V_35 -> V_53 = V_75 ;
V_35 -> V_326 = 1 ;
}
if ( V_421 ) F_268 ( V_35 , V_417 ) ;
return;
V_423:
F_67 ( V_74 L_194 ,
F_91 () ,
V_2 ? F_64 ( V_2 ) : - 1 ,
V_413 ) ;
return;
V_422:
F_44 ( ( L_195 , V_2 ? F_64 ( V_2 ) : - 1 ) ) ;
F_23 () ;
F_231 ( V_94 ) -> V_355 = 0 ;
F_231 ( V_94 ) -> V_371 = 1 ;
return;
}
static int
F_272 ( void * V_98 , struct V_93 * V_94 )
{
struct V_1 * V_2 ;
T_1 * V_35 ;
unsigned long V_15 ;
T_26 V_413 ;
int V_430 = F_91 () ;
int V_445 = 0 ;
V_331 [ V_430 ] . V_446 ++ ;
V_413 = F_273 ( 0 ) ;
V_2 = F_125 () ;
V_35 = F_126 () ;
if ( F_274 ( V_413 ) && V_2 ) {
if ( ! V_35 ) goto V_447;
if ( V_35 -> V_57 == 0 && ( V_2 -> V_316 . V_15 & V_370 ) == 0 )
goto V_448;
F_275 ( V_35 , V_15 ) ;
F_269 ( V_2 , V_35 , V_413 , V_94 ) ;
F_276 ( V_35 , V_15 ) ;
} else {
V_331 [ V_430 ] . V_449 ++ ;
V_445 = - 1 ;
}
F_32 () ;
return V_445 ;
V_447:
F_67 ( V_118 L_196 ,
V_430 , F_64 ( V_2 ) ) ;
F_32 () ;
return - 1 ;
V_448:
F_67 ( V_118 L_197 ,
V_430 ,
F_64 ( V_2 ) ) ;
F_32 () ;
return - 1 ;
}
static T_29
F_277 ( int V_450 , void * V_98 )
{
unsigned long V_425 , V_451 ;
unsigned long V_452 , V_453 ;
int V_430 ;
int V_95 ;
struct V_93 * V_94 = F_278 () ;
V_430 = F_279 () ;
if ( F_199 ( ! V_454 ) ) {
V_452 = V_331 [ V_430 ] . V_333 ;
V_453 = V_331 [ V_430 ] . V_455 ;
V_425 = F_270 () ;
V_95 = F_272 ( V_98 , V_94 ) ;
V_451 = F_270 () ;
if ( F_199 ( V_95 == 0 ) ) {
V_451 -= V_425 ;
if ( V_451 < V_452 ) V_331 [ V_430 ] . V_333 = V_451 ;
if ( V_451 > V_453 ) V_331 [ V_430 ] . V_455 = V_451 ;
V_331 [ V_430 ] . V_456 += V_451 ;
}
}
else {
(* V_454 -> V_457 )( V_450 , V_98 , V_94 ) ;
}
F_280 () ;
return V_458 ;
}
static void *
F_281 ( struct V_459 * V_329 , T_10 * V_107 )
{
if ( * V_107 == 0 ) {
return V_460 ;
}
while ( * V_107 <= V_461 ) {
if ( F_282 ( * V_107 - 1 ) ) {
return ( void * ) * V_107 ;
}
++ * V_107 ;
}
return NULL ;
}
static void *
F_283 ( struct V_459 * V_329 , void * V_305 , T_10 * V_107 )
{
++ * V_107 ;
return F_281 ( V_329 , V_107 ) ;
}
static void
F_284 ( struct V_459 * V_329 , void * V_305 )
{
}
static void
F_285 ( struct V_459 * V_329 )
{
struct V_106 * V_107 ;
T_5 * V_108 ;
unsigned long V_15 ;
F_286 ( V_329 ,
L_198
L_199
L_200
L_201
L_202
L_203 ,
V_462 , V_463 ,
V_37 -> V_464 ,
V_281 . V_465 > 0 ? L_204 : L_205 ,
V_281 . V_276 > 0 ? L_204 : L_205 ,
V_37 -> V_38 ,
V_37 -> V_15 ) ;
F_90 ( V_15 ) ;
F_286 ( V_329 ,
L_206
L_207
L_208
L_209 ,
V_120 . V_122 ,
V_120 . V_121 ,
V_120 . V_123 ,
V_120 . V_320 ) ;
F_93 ( V_15 ) ;
F_9 ( & V_111 ) ;
F_82 (pos, &pfm_buffer_fmt_list) {
V_108 = F_83 ( V_107 , T_5 , V_109 ) ;
F_286 ( V_329 , L_210 ,
V_108 -> V_110 [ 0 ] ,
V_108 -> V_110 [ 1 ] ,
V_108 -> V_110 [ 2 ] ,
V_108 -> V_110 [ 3 ] ,
V_108 -> V_110 [ 4 ] ,
V_108 -> V_110 [ 5 ] ,
V_108 -> V_110 [ 6 ] ,
V_108 -> V_110 [ 7 ] ,
V_108 -> V_110 [ 8 ] ,
V_108 -> V_110 [ 9 ] ,
V_108 -> V_110 [ 10 ] ,
V_108 -> V_110 [ 11 ] ,
V_108 -> V_110 [ 12 ] ,
V_108 -> V_110 [ 13 ] ,
V_108 -> V_110 [ 14 ] ,
V_108 -> V_110 [ 15 ] ,
V_108 -> V_112 ) ;
}
F_11 ( & V_111 ) ;
}
static int
F_287 ( struct V_459 * V_329 , void * V_305 )
{
unsigned long V_72 ;
unsigned int V_32 ;
int V_97 ;
if ( V_305 == V_460 ) {
F_285 ( V_329 ) ;
return 0 ;
}
V_97 = ( long ) V_305 - 1 ;
F_286 ( V_329 ,
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
L_223
L_224 ,
V_97 , V_331 [ V_97 ] . V_446 ,
V_97 , V_331 [ V_97 ] . V_456 ,
V_97 , V_331 [ V_97 ] . V_333 ,
V_97 , V_331 [ V_97 ] . V_455 ,
V_97 , V_331 [ V_97 ] . V_438 ,
V_97 , V_331 [ V_97 ] . V_441 ,
V_97 , V_331 [ V_97 ] . V_449 ,
V_97 , V_331 [ V_97 ] . V_466 ,
V_97 , F_288 ( V_467 , V_97 ) & V_368 ? 1 : 0 ,
V_97 , F_288 ( V_467 , V_97 ) & V_76 ? 1 : 0 ,
V_97 , F_288 ( V_467 , V_97 ) & V_369 ? 1 : 0 ,
V_97 , F_288 ( V_468 , V_97 ) ? F_288 ( V_468 , V_97 ) -> V_246 : - 1 ,
V_97 , F_288 ( V_469 , V_97 ) ,
V_97 , F_288 ( V_470 , V_97 ) ) ;
if ( F_289 () == 1 && V_281 . V_330 > 0 ) {
V_72 = F_25 () ;
F_31 () ;
F_286 ( V_329 ,
L_225
L_226 ,
V_97 , V_72 ,
V_97 , F_273 ( 0 ) ) ;
for ( V_32 = 0 ; F_176 ( V_32 ) == 0 ; V_32 ++ ) {
if ( F_290 ( V_32 ) == 0 ) continue;
F_286 ( V_329 ,
L_227
L_228 ,
V_97 , V_32 , F_273 ( V_32 ) ,
V_97 , V_32 , F_40 ( V_32 ) ) ;
}
}
return 0 ;
}
static int
F_291 ( struct V_164 * V_164 , struct V_13 * V_13 )
{
return F_292 ( V_13 , & V_471 ) ;
}
void
F_293 ( struct V_1 * V_2 , unsigned long V_154 , int V_472 )
{
struct V_93 * V_94 ;
unsigned long V_473 ;
unsigned long V_474 ;
V_474 = V_154 & V_76 ? 1 : 0 ;
if ( ( V_154 & V_369 ) == 0 || V_2 -> V_246 ) {
V_94 = F_124 ( V_2 ) ;
F_231 ( V_94 ) -> V_354 = V_472 ? V_474 : 0 ;
return;
}
if ( V_474 ) {
V_473 = F_26 ( V_77 ) ;
if ( V_472 ) {
F_28 ( V_77 , V_473 & ~ V_78 ) ;
F_18 () ;
F_20 () ;
return;
}
F_28 ( V_77 , V_473 | V_78 ) ;
F_21 () ;
F_20 () ;
}
}
static void
F_294 ( T_1 * V_35 , struct V_93 * V_94 )
{
struct V_1 * V_2 = V_35 -> V_157 ;
F_231 ( V_94 ) -> V_355 = 0 ;
F_231 ( V_94 ) -> V_371 = 1 ;
if ( F_125 () == V_2 ) {
F_44 ( ( L_229 ,
F_64 ( V_35 -> V_157 ) ) ) ;
F_243 ( NULL , NULL ) ;
}
F_218 ( V_2 , 0 ) ;
V_2 -> V_316 . V_317 = NULL ;
V_2 -> V_316 . V_15 &= ~ V_370 ;
F_44 ( ( L_230 , F_64 ( V_2 ) ) ) ;
}
void
F_295 ( struct V_1 * V_2 )
{
T_1 * V_35 ;
unsigned long V_15 ;
T_26 V_72 ;
V_35 = F_62 ( V_2 ) ;
if ( V_35 == NULL ) return;
V_15 = F_8 ( V_35 ) ;
if ( V_35 -> V_53 == V_169 ) {
struct V_93 * V_94 = F_124 ( V_2 ) ;
F_23 () ;
F_294 ( V_35 , V_94 ) ;
F_247 ( V_35 -> V_170 ) ;
F_10 ( V_35 , V_15 ) ;
F_59 ( V_35 ) ;
return;
}
F_31 () ;
V_72 = F_25 () ;
F_247 ( V_72 & ( V_475 ) ) ;
F_23 () ;
V_35 -> V_356 = V_72 & V_25 ;
F_243 ( NULL , NULL ) ;
F_69 ( V_35 -> V_87 , V_35 -> V_68 [ 0 ] ) ;
V_35 -> V_71 [ 0 ] = F_273 ( 0 ) ;
if ( V_35 -> V_71 [ 0 ] & ~ 0x1UL ) F_32 () ;
F_10 ( V_35 , V_15 ) ;
}
void
F_295 ( struct V_1 * V_2 )
{
T_1 * V_35 ;
T_26 V_72 ;
V_35 = F_62 ( V_2 ) ;
if ( V_35 == NULL ) return;
V_72 = F_25 () ;
F_247 ( V_72 & ( V_475 ) ) ;
F_23 () ;
V_35 -> V_356 = V_72 & V_25 ;
}
static void
F_242 ( struct V_1 * V_2 )
{
T_1 * V_35 ;
unsigned long V_15 ;
{ T_26 V_72 = F_25 () ;
F_247 ( V_72 & V_25 ) ;
}
V_35 = F_62 ( V_2 ) ;
F_108 ( V_35 , V_15 ) ;
F_243 ( NULL , NULL ) ;
F_69 ( V_35 -> V_87 , V_35 -> V_68 [ 0 ] ) ;
V_35 -> V_71 [ 0 ] = F_273 ( 0 ) ;
if ( V_35 -> V_71 [ 0 ] & ~ 0x1UL ) F_32 () ;
F_111 ( V_35 , V_15 ) ;
}
void
F_296 ( struct V_1 * V_2 )
{
T_1 * V_35 ;
unsigned long V_476 = 0UL , V_427 = 0UL ;
unsigned long V_15 ;
T_26 V_72 , V_477 ;
int V_478 ;
V_35 = F_62 ( V_2 ) ;
if ( F_204 ( V_35 == NULL ) ) return;
F_247 ( F_125 () ) ;
if ( F_204 ( ( V_2 -> V_316 . V_15 & V_370 ) == 0 ) ) return;
V_15 = F_8 ( V_35 ) ;
V_72 = F_25 () ;
V_478 = V_37 -> V_15 & V_479 ;
F_247 ( V_72 & ( V_25 | V_24 ) ) ;
F_247 ( V_72 & V_475 ) ;
if ( F_204 ( V_35 -> V_53 == V_169 ) ) {
struct V_93 * V_94 = F_124 ( V_2 ) ;
F_247 ( V_35 -> V_170 ) ;
F_294 ( V_35 , V_94 ) ;
F_10 ( V_35 , V_15 ) ;
F_59 ( V_35 ) ;
return;
}
if ( V_35 -> V_80 ) {
F_33 ( V_35 -> V_81 , V_37 -> V_82 ) ;
F_36 ( V_35 -> V_83 , V_37 -> V_84 ) ;
}
V_477 = V_35 -> V_356 ;
if ( F_297 ( V_35 ) == F_91 () && V_35 -> V_62 == F_298 () ) {
V_476 = V_35 -> V_300 [ 0 ] ;
V_427 = V_35 -> V_310 [ 0 ] ;
} else {
V_427 = V_281 . V_465 ? V_35 -> V_68 [ 0 ] : V_35 -> V_86 [ 0 ] ;
V_476 = V_35 -> V_88 [ 0 ] ;
}
if ( V_427 ) F_70 ( V_35 -> V_87 , V_427 ) ;
if ( V_476 ) F_73 ( V_35 -> V_71 , V_476 ) ;
if ( F_204 ( F_274 ( V_35 -> V_71 [ 0 ] ) ) ) {
F_30 ( 0 , V_35 -> V_71 [ 0 ] ) ;
F_31 () ;
V_35 -> V_71 [ 0 ] = 0UL ;
if ( V_478 ) F_299 ( V_480 ) ;
V_331 [ F_91 () ] . V_466 ++ ;
}
V_35 -> V_300 [ 0 ] = 0UL ;
V_35 -> V_310 [ 0 ] = 0UL ;
F_57 ( V_35 , F_91 () ) ;
F_240 () ;
F_241 ( V_35 ) ;
F_243 ( V_2 , V_35 ) ;
if ( F_199 ( V_477 ) ) F_24 () ;
F_10 ( V_35 , V_15 ) ;
}
void
F_296 ( struct V_1 * V_2 )
{
T_1 * V_35 ;
struct V_1 * V_155 ;
unsigned long V_427 , V_476 ;
T_26 V_72 , V_477 ;
int V_478 ;
V_155 = F_125 () ;
V_35 = F_62 ( V_2 ) ;
V_72 = F_25 () ;
F_247 ( V_72 & ( V_25 | V_24 ) ) ;
F_247 ( V_72 & V_475 ) ;
if ( V_35 -> V_80 ) {
F_33 ( V_35 -> V_81 , V_37 -> V_82 ) ;
F_36 ( V_35 -> V_83 , V_37 -> V_84 ) ;
}
V_477 = V_35 -> V_356 ;
V_478 = V_37 -> V_15 & V_479 ;
if ( F_199 ( V_155 == V_2 ) ) {
if ( F_199 ( V_477 ) ) F_24 () ;
return;
}
if ( V_155 ) F_242 ( V_155 ) ;
V_427 = V_281 . V_465 ? V_35 -> V_68 [ 0 ] : V_35 -> V_86 [ 0 ] ;
V_476 = V_35 -> V_88 [ 0 ] ;
F_70 ( V_35 -> V_87 , V_427 ) ;
F_73 ( V_35 -> V_71 , V_476 ) ;
if ( F_204 ( F_274 ( V_35 -> V_71 [ 0 ] ) ) ) {
F_30 ( 0 , V_35 -> V_71 [ 0 ] ) ;
F_31 () ;
V_35 -> V_71 [ 0 ] = 0UL ;
if ( V_478 ) F_299 ( V_480 ) ;
V_331 [ F_91 () ] . V_466 ++ ;
}
F_243 ( V_2 , V_35 ) ;
if ( F_199 ( V_477 ) ) F_24 () ;
}
static void
F_244 ( struct V_1 * V_2 , T_1 * V_35 )
{
T_26 V_413 ;
unsigned long V_481 , V_28 , V_482 , V_38 ;
int V_32 , V_274 = 0 ;
int V_483 ;
V_483 = V_35 -> V_157 == V_2 ? 1 : 0 ;
V_274 = ( F_125 () == V_2 ) || ( V_35 -> V_57 && V_35 -> V_156 == F_91 () ) ;
if ( V_274 ) {
F_243 ( NULL , NULL ) ;
F_44 ( ( L_231 ) ) ;
F_31 () ;
V_413 = F_273 ( 0 ) ;
F_32 () ;
} else {
V_413 = V_35 -> V_71 [ 0 ] ;
V_35 -> V_71 [ 0 ] = 0 ;
}
V_38 = V_37 -> V_38 ;
V_481 = V_35 -> V_68 [ 0 ] ;
F_44 ( ( L_232 , V_483 , V_38 , V_481 ) ) ;
for ( V_32 = 0 ; V_481 ; V_32 ++ , V_481 >>= 1 ) {
if ( ( V_481 & 0x1 ) == 0 ) continue;
V_28 = V_482 = V_274 ? F_40 ( V_32 ) : V_35 -> V_87 [ V_32 ] ;
if ( F_65 ( V_32 ) ) {
F_44 ( ( L_233 ,
F_64 ( V_2 ) ,
V_32 ,
V_35 -> V_36 [ V_32 ] . V_28 ,
V_28 & V_38 ) ) ;
V_28 = V_35 -> V_36 [ V_32 ] . V_28 + ( V_28 & V_38 ) ;
V_482 = 0UL ;
if ( V_413 & ( 1UL << V_32 ) ) {
V_28 += 1 + V_38 ;
F_44 ( ( L_234 , F_64 ( V_2 ) , V_32 ) ) ;
}
}
F_44 ( ( L_235 , F_64 ( V_2 ) , V_32 , V_28 , V_482 ) ) ;
if ( V_483 ) V_35 -> V_87 [ V_32 ] = V_482 ;
V_35 -> V_36 [ V_32 ] . V_28 = V_28 ;
}
}
static void
F_300 ( void * V_21 )
{
struct V_93 * V_94 ;
V_94 = F_124 ( V_3 ) ;
F_44 ( ( L_236 ) ) ;
F_23 () ;
F_18 () ;
F_231 ( V_94 ) -> V_354 = 0 ;
F_29 () ;
F_31 () ;
}
void
F_301 ( void * V_21 )
{
struct V_93 * V_94 ;
V_94 = F_124 ( V_3 ) ;
F_44 ( ( L_236 ) ) ;
F_23 () ;
F_18 () ;
F_231 ( V_94 ) -> V_354 = 0 ;
F_32 () ;
F_31 () ;
}
int
F_302 ( T_30 * V_484 )
{
int V_95 , V_32 ;
int V_485 ;
if ( V_484 == NULL || V_484 -> V_457 == NULL ) return - V_113 ;
if ( V_454 ) return - V_115 ;
if ( ! F_303 ( & V_486 ) ) {
return - V_115 ;
}
F_304 (reserve_cpu) {
V_95 = F_89 ( NULL , 1 , V_485 ) ;
if ( V_95 ) goto V_487;
}
V_95 = F_305 ( F_300 , NULL , 1 ) ;
if ( V_95 ) {
F_44 ( ( L_237 , V_95 ) ) ;
goto V_487;
}
V_454 = V_484 ;
F_11 ( & V_486 ) ;
return 0 ;
V_487:
F_304 (i) {
if ( V_32 >= V_485 ) break;
F_94 ( NULL , 1 , V_32 ) ;
}
F_11 ( & V_486 ) ;
return V_95 ;
}
int
F_306 ( T_30 * V_484 )
{
int V_32 ;
int V_95 ;
if ( V_484 == NULL ) return - V_113 ;
if ( V_454 != V_484 ) return - V_113 ;
if ( ! F_303 ( & V_486 ) ) {
return - V_115 ;
}
V_454 = NULL ;
V_95 = F_305 ( F_301 , NULL , 1 ) ;
if ( V_95 ) {
F_44 ( ( L_237 , V_95 ) ) ;
}
F_304 (i) {
F_94 ( NULL , 1 , V_32 ) ;
}
F_11 ( & V_486 ) ;
return 0 ;
}
static int T_7
F_307 ( void )
{
T_31 * * V_247 ;
int V_488 ;
V_488 = V_489 -> V_488 ;
V_247 = V_490 ;
while( * V_247 ) {
if ( ( * V_247 ) -> V_491 ) {
if ( ( * V_247 ) -> V_491 () == 0 ) goto V_492;
} else if ( ( * V_247 ) -> V_493 == V_488 || ( * V_247 ) -> V_493 == 0xff ) {
goto V_492;
}
V_247 ++ ;
}
return - 1 ;
V_492:
V_37 = * V_247 ;
return 0 ;
}
int T_7
F_308 ( void )
{
unsigned int V_494 , V_495 , V_32 ;
F_67 ( L_238 ,
V_462 ,
V_463 ,
V_480 ) ;
if ( F_307 () ) {
F_67 ( V_118 L_239 ,
V_489 -> V_488 ) ;
return - V_496 ;
}
V_494 = 0 ;
for ( V_32 = 0 ; F_176 ( V_32 ) == 0 ; V_32 ++ ) {
if ( F_177 ( V_32 ) == 0 ) continue;
V_37 -> V_236 [ V_32 >> 6 ] |= 1UL << ( V_32 & 63 ) ;
V_494 ++ ;
}
V_37 -> V_497 = V_494 ;
V_494 = 0 ; V_495 = 0 ;
for ( V_32 = 0 ; F_309 ( V_32 ) == 0 ; V_32 ++ ) {
if ( F_205 ( V_32 ) == 0 ) continue;
V_37 -> V_237 [ V_32 >> 6 ] |= 1UL << ( V_32 & 63 ) ;
V_494 ++ ;
if ( F_65 ( V_32 ) ) V_495 ++ ;
}
V_37 -> V_498 = V_494 ;
V_37 -> V_499 = V_495 ;
if ( V_37 -> V_318 ) {
if ( V_37 -> V_82 > V_500 ) {
F_67 ( V_118 L_240 , V_37 -> V_82 ) ;
V_37 = NULL ;
return - 1 ;
}
if ( V_37 -> V_84 > V_500 ) {
F_67 ( V_118 L_241 , V_37 -> V_82 ) ;
V_37 = NULL ;
return - 1 ;
}
}
F_67 ( L_242 ,
V_37 -> V_464 ,
V_37 -> V_497 ,
V_37 -> V_498 ,
V_37 -> V_499 ,
F_310 ( V_37 -> V_38 ) ) ;
if ( V_37 -> V_498 >= V_501 || V_37 -> V_497 >= V_502 ) {
F_67 ( V_74 L_243 ) ;
V_37 = NULL ;
return - 1 ;
}
V_503 = F_311 ( L_244 , V_188 , NULL , & V_504 ) ;
if ( V_503 == NULL ) {
F_67 ( V_74 L_245 ) ;
V_37 = NULL ;
return - 1 ;
}
V_505 = F_312 ( V_506 ) ;
F_55 ( & V_120 . V_507 ) ;
F_55 ( & V_111 ) ;
F_99 () ;
for( V_32 = 0 ; V_32 < V_332 ; V_32 ++ ) V_331 [ V_32 ] . V_333 = ~ 0UL ;
return 0 ;
}
void
F_313 ( void )
{
static int V_338 = 1 ;
F_18 () ;
F_23 () ;
F_32 () ;
if ( V_338 ) {
F_314 ( V_480 , & V_508 ) ;
V_338 = 0 ;
}
F_28 ( V_509 , V_480 ) ;
F_31 () ;
}
void
F_315 ( const char * V_510 )
{
struct V_1 * V_2 ;
struct V_93 * V_94 ;
T_1 * V_35 ;
unsigned long V_72 , V_473 , V_154 , V_15 ;
int V_32 , V_430 ;
F_127 ( V_15 ) ;
V_430 = F_91 () ;
V_94 = F_124 ( V_3 ) ;
V_154 = F_68 () ;
V_473 = F_26 ( V_77 ) ;
if ( V_154 == 0 && F_231 ( V_94 ) -> V_354 == 0 && ( V_473 & V_78 ) == 0 ) {
F_129 ( V_15 ) ;
return;
}
F_67 ( L_246 ,
V_430 ,
V_510 ,
F_64 ( V_3 ) ,
V_94 -> V_424 ,
V_3 -> V_511 ) ;
V_2 = F_125 () ;
V_35 = F_126 () ;
F_67 ( L_247 , V_430 , V_2 ? F_64 ( V_2 ) : - 1 , V_35 ) ;
V_72 = F_25 () ;
F_67 ( L_248 ,
V_430 ,
F_273 ( 0 ) ,
V_72 & V_24 ? 1 : 0 ,
V_72 & V_25 ? 1 : 0 ,
V_473 & V_78 ? 1 : 0 ,
V_154 ,
F_231 ( V_94 ) -> V_355 ,
F_231 ( V_94 ) -> V_354 ) ;
F_231 ( V_94 ) -> V_355 = 0 ;
F_231 ( V_94 ) -> V_354 = 0 ;
for ( V_32 = 1 ; F_176 ( V_32 ) == 0 ; V_32 ++ ) {
if ( F_177 ( V_32 ) == 0 ) continue;
F_67 ( L_249 , V_430 , V_32 , F_273 ( V_32 ) , V_32 , V_35 -> V_71 [ V_32 ] ) ;
}
for ( V_32 = 1 ; F_309 ( V_32 ) == 0 ; V_32 ++ ) {
if ( F_205 ( V_32 ) == 0 ) continue;
F_67 ( L_250 , V_430 , V_32 , F_40 ( V_32 ) , V_32 , V_35 -> V_87 [ V_32 ] ) ;
}
if ( V_35 ) {
F_67 ( L_251 ,
V_430 ,
V_35 -> V_53 ,
V_35 -> V_162 ,
V_35 -> V_170 ,
V_35 -> V_43 ,
V_35 -> V_41 ,
V_35 -> V_356 ) ;
}
F_129 ( V_15 ) ;
}
void
F_316 ( struct V_1 * V_2 , struct V_93 * V_94 )
{
struct V_335 * V_316 ;
F_44 ( ( L_252 , F_64 ( V_2 ) ) ) ;
V_316 = & V_2 -> V_316 ;
V_316 -> V_317 = NULL ;
F_218 ( V_2 , 0 ) ;
}
T_27 long
F_250 ( int V_150 , int V_149 , void * V_98 , int V_250 )
{
return - V_385 ;
}
