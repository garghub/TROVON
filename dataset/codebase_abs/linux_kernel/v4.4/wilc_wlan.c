static void F_1 ( T_1 V_1 , char * V_2 , ... )
{
char V_3 [ 256 ] ;
T_2 args ;
if ( V_1 & V_4 ) {
va_start ( args , V_2 ) ;
vsprintf ( V_3 , V_2 , args ) ;
va_end ( args ) ;
F_2 ( V_3 ) ;
}
}
static inline void F_3 ( T_3 V_5 )
{
F_4 ( & V_6 -> V_7 ) ;
#ifndef F_5
if ( V_8 != V_9 )
#endif
{
if ( V_5 == V_10 )
F_6 () ;
}
}
static inline void F_7 ( T_4 V_11 )
{
#ifdef F_5
if ( V_11 == V_12 )
F_8 () ;
#endif
F_9 ( & V_6 -> V_7 ) ;
}
static void F_10 ( struct V_13 * V_14 )
{
T_5 * V_15 = & V_16 ;
if ( V_14 == V_15 -> V_17 ) {
V_15 -> V_17 = V_14 -> V_18 ;
if ( V_15 -> V_17 )
V_15 -> V_17 -> V_19 = NULL ;
} else if ( V_14 == V_15 -> V_20 ) {
V_15 -> V_20 = ( V_14 -> V_19 ) ;
if ( V_15 -> V_20 )
V_15 -> V_20 -> V_18 = NULL ;
} else {
V_14 -> V_19 -> V_18 = V_14 -> V_18 ;
V_14 -> V_18 -> V_19 = V_14 -> V_19 ;
}
V_15 -> V_21 -= 1 ;
}
static struct V_13 * F_11 ( void )
{
struct V_13 * V_14 ;
T_5 * V_15 = & V_16 ;
unsigned long V_22 ;
F_12 ( & V_6 -> V_23 , V_22 ) ;
if ( V_15 -> V_17 ) {
V_14 = V_15 -> V_17 ;
V_15 -> V_17 = V_14 -> V_18 ;
if ( V_15 -> V_17 )
V_15 -> V_17 -> V_19 = NULL ;
V_15 -> V_21 -= 1 ;
} else {
V_14 = NULL ;
}
F_13 ( & V_6 -> V_23 , V_22 ) ;
return V_14 ;
}
static void F_14 ( struct V_13 * V_14 )
{
T_5 * V_15 = & V_16 ;
unsigned long V_22 ;
F_12 ( & V_6 -> V_23 , V_22 ) ;
if ( V_15 -> V_17 == NULL ) {
V_14 -> V_18 = NULL ;
V_14 -> V_19 = NULL ;
V_15 -> V_17 = V_14 ;
V_15 -> V_20 = V_14 ;
} else {
V_14 -> V_18 = NULL ;
V_14 -> V_19 = V_15 -> V_20 ;
V_15 -> V_20 -> V_18 = V_14 ;
V_15 -> V_20 = V_14 ;
}
V_15 -> V_21 += 1 ;
F_15 ( V_24 , L_1 , V_15 -> V_21 ) ;
F_13 ( & V_6 -> V_23 , V_22 ) ;
F_15 ( V_24 , L_2 ) ;
F_16 ( & V_6 -> V_25 ) ;
}
static int F_17 ( struct V_13 * V_14 )
{
T_5 * V_15 = & V_16 ;
unsigned long V_22 ;
if ( F_18 ( & V_6 -> V_26 ,
V_27 ) )
return - 1 ;
F_12 ( & V_6 -> V_23 , V_22 ) ;
if ( V_15 -> V_17 == NULL ) {
V_14 -> V_18 = NULL ;
V_14 -> V_19 = NULL ;
V_15 -> V_17 = V_14 ;
V_15 -> V_20 = V_14 ;
} else {
V_14 -> V_18 = V_15 -> V_17 ;
V_14 -> V_19 = NULL ;
V_15 -> V_17 -> V_19 = V_14 ;
V_15 -> V_17 = V_14 ;
}
V_15 -> V_21 += 1 ;
F_15 ( V_24 , L_1 , V_15 -> V_21 ) ;
F_13 ( & V_6 -> V_23 , V_22 ) ;
F_16 ( & V_6 -> V_26 ) ;
F_16 ( & V_6 -> V_25 ) ;
F_15 ( V_24 , L_3 ) ;
return 0 ;
}
static inline int F_19 ( void )
{
return 0 ;
}
static inline int F_20 ( T_1 V_28 , T_1 V_29 , T_1 V_30 )
{
V_31 [ V_32 ] . V_33 = V_30 ;
V_31 [ V_32 ] . V_34 = 0 ;
V_31 [ V_32 ] . V_35 = V_28 ;
V_31 [ V_32 ] . V_36 = V_29 ;
V_32 ++ ;
F_15 ( V_37 , L_4 , V_32 , V_30 ) ;
return 0 ;
}
static inline int F_21 ( T_1 V_38 , T_1 V_39 )
{
if ( V_39 > V_31 [ V_38 ] . V_34 )
V_31 [ V_38 ] . V_34 = V_39 ;
return 0 ;
}
static inline int F_22 ( T_1 V_39 , T_1 V_40 , struct V_13 * V_41 )
{
V_42 ++ ;
if ( V_43 < V_44 ) {
V_45 [ V_46 + V_43 ] . V_47 = V_39 ;
V_45 [ V_46 + V_43 ] . V_41 = V_41 ;
V_45 [ V_46 + V_43 ] . V_40 = V_40 ;
V_41 -> V_48 = V_46 + V_43 ;
V_43 ++ ;
} else {
}
return 0 ;
}
static inline int F_23 ( void )
{
T_5 * V_15 = & V_16 ;
unsigned long V_22 ;
F_12 ( & V_6 -> V_23 , V_22 ) ;
F_13 ( & V_6 -> V_23 , V_22 ) ;
return 0 ;
}
static inline int F_24 ( struct V_49 * V_50 , struct V_13 * V_14 )
{
int V_51 ;
T_6 * V_52 ;
T_6 * V_53 = V_14 -> V_53 ;
unsigned short V_54 ;
int V_55 ;
T_5 * V_15 = & V_16 ;
unsigned long V_22 ;
T_7 * V_56 ;
struct V_57 * V_57 ;
V_56 = F_25 ( V_50 ) ;
V_57 = V_56 -> V_57 ;
F_12 ( & V_57 -> V_23 , V_22 ) ;
V_52 = & V_53 [ 0 ] ;
V_54 = F_26 ( * ( ( unsigned short * ) & V_52 [ 12 ] ) ) ;
if ( V_54 == 0x0800 ) {
T_6 * V_58 ;
T_6 V_59 ;
V_58 = & V_53 [ V_60 ] ;
V_59 = V_58 [ 9 ] ;
if ( V_59 == 0x06 ) {
T_6 * V_61 ;
T_1 V_62 , V_63 , V_64 ;
V_61 = & V_58 [ V_65 ] ;
V_62 = ( V_58 [ 0 ] & 0xf ) << 2 ;
V_63 = ( ( ( T_1 ) V_58 [ 2 ] ) << 8 ) + ( ( T_1 ) V_58 [ 3 ] ) ;
V_64 = ( ( ( T_1 ) V_61 [ 12 ] & 0xf0 ) >> 2 ) ;
if ( V_63 == ( V_62 + V_64 ) ) {
T_1 V_66 , V_67 ;
V_66 = ( ( ( T_1 ) V_61 [ 4 ] ) << 24 ) + ( ( ( T_1 ) V_61 [ 5 ] ) << 16 ) + ( ( ( T_1 ) V_61 [ 6 ] ) << 8 ) + ( ( T_1 ) V_61 [ 7 ] ) ;
V_67 = ( ( ( T_1 ) V_61 [ 8 ] ) << 24 ) + ( ( ( T_1 ) V_61 [ 9 ] ) << 16 ) + ( ( ( T_1 ) V_61 [ 10 ] ) << 8 ) + ( ( T_1 ) V_61 [ 11 ] ) ;
for ( V_55 = 0 ; V_55 < V_32 ; V_55 ++ ) {
if ( V_31 [ V_55 ] . V_33 == V_66 ) {
F_21 ( V_55 , V_67 ) ;
break;
}
}
if ( V_55 == V_32 )
F_20 ( 0 , 0 , V_66 ) ;
F_22 ( V_67 , V_55 , V_14 ) ;
}
} else {
V_51 = 0 ;
}
} else {
V_51 = 0 ;
}
F_13 ( & V_57 -> V_23 , V_22 ) ;
return V_51 ;
}
static int F_27 ( struct V_49 * V_50 )
{
T_7 * V_56 ;
struct V_57 * V_57 ;
T_1 V_55 = 0 ;
T_1 V_68 = 0 ;
T_5 * V_15 = & V_16 ;
V_56 = F_25 ( V_50 ) ;
V_57 = V_56 -> V_57 ;
F_12 ( & V_57 -> V_23 , V_15 -> V_69 ) ;
for ( V_55 = V_46 ; V_55 < ( V_46 + V_43 ) ; V_55 ++ ) {
if ( V_45 [ V_55 ] . V_47 < V_31 [ V_45 [ V_55 ] . V_40 ] . V_34 ) {
struct V_13 * V_14 ;
F_15 ( V_37 , L_5 , V_45 [ V_55 ] . V_47 ) ;
V_14 = V_45 [ V_55 ] . V_41 ;
if ( V_14 ) {
F_10 ( V_14 ) ;
V_70 ++ ;
V_14 -> V_71 = 1 ;
if ( V_14 -> V_72 )
V_14 -> V_72 ( V_14 -> V_73 , V_14 -> V_71 ) ;
F_28 ( V_14 ) ;
V_68 ++ ;
}
}
}
V_43 = 0 ;
V_32 = 0 ;
if ( V_46 == 0 )
V_46 = V_74 ;
else
V_46 = 0 ;
F_13 ( & V_57 -> V_23 , V_15 -> V_69 ) ;
while ( V_68 > 0 ) {
F_18 ( & V_57 -> V_25 , 1 ) ;
V_68 -- ;
}
return 1 ;
}
void F_29 ( bool V_75 )
{
V_76 = V_75 ;
}
bool F_30 ( void )
{
return V_76 ;
}
static int F_31 ( T_6 * V_53 , T_1 V_77 )
{
T_5 * V_15 = & V_16 ;
struct V_13 * V_14 ;
F_15 ( V_24 , L_6 ) ;
if ( V_15 -> V_78 ) {
F_15 ( V_24 , L_7 ) ;
F_16 ( & V_6 -> V_79 ) ;
return 0 ;
}
V_14 = F_32 ( sizeof( struct V_13 ) , V_80 ) ;
if ( V_14 == NULL ) {
F_33 ( L_8 ) ;
return 0 ;
}
V_14 -> type = V_81 ;
V_14 -> V_53 = V_53 ;
V_14 -> V_77 = V_77 ;
V_14 -> V_72 = NULL ;
V_14 -> V_73 = NULL ;
#ifdef F_34
V_14 -> V_48 = V_82 ;
#endif
F_15 ( V_24 , L_9 ) ;
if ( F_17 ( V_14 ) )
return 0 ;
return 1 ;
}
int F_35 ( struct V_49 * V_50 , void * V_73 , T_6 * V_53 ,
T_1 V_77 , T_8 V_83 )
{
T_5 * V_15 = & V_16 ;
struct V_13 * V_14 ;
if ( V_15 -> V_78 )
return 0 ;
V_14 = F_32 ( sizeof( struct V_13 ) , V_80 ) ;
if ( V_14 == NULL )
return 0 ;
V_14 -> type = V_84 ;
V_14 -> V_53 = V_53 ;
V_14 -> V_77 = V_77 ;
V_14 -> V_72 = V_83 ;
V_14 -> V_73 = V_73 ;
F_15 ( V_24 , L_10 ) ;
#ifdef F_34
V_14 -> V_48 = V_82 ;
if ( F_30 () )
F_24 ( V_50 , V_14 ) ;
#endif
F_14 ( V_14 ) ;
return V_15 -> V_21 ;
}
int F_36 ( void * V_73 , T_6 * V_53 , T_1 V_77 , T_8 V_83 )
{
T_5 * V_15 = & V_16 ;
struct V_13 * V_14 ;
if ( V_15 -> V_78 )
return 0 ;
V_14 = F_32 ( sizeof( struct V_13 ) , V_85 ) ;
if ( V_14 == NULL )
return 0 ;
V_14 -> type = V_86 ;
V_14 -> V_53 = V_53 ;
V_14 -> V_77 = V_77 ;
V_14 -> V_72 = V_83 ;
V_14 -> V_73 = V_73 ;
#ifdef F_34
V_14 -> V_48 = V_82 ;
#endif
F_15 ( V_24 , L_11 ) ;
F_14 ( V_14 ) ;
return 1 ;
}
static struct V_13 * F_37 ( void )
{
T_5 * V_15 = & V_16 ;
struct V_13 * V_14 ;
unsigned long V_22 ;
F_12 ( & V_6 -> V_23 , V_22 ) ;
V_14 = V_15 -> V_17 ;
F_13 ( & V_6 -> V_23 , V_22 ) ;
return V_14 ;
}
static struct V_13 * F_38 ( struct V_57 * V_57 ,
struct V_13 * V_14 )
{
unsigned long V_22 ;
F_12 ( & V_57 -> V_23 , V_22 ) ;
V_14 = V_14 -> V_18 ;
F_13 ( & V_57 -> V_23 , V_22 ) ;
return V_14 ;
}
static int F_39 ( struct V_57 * V_57 , struct V_87 * V_88 )
{
T_5 * V_15 = & V_16 ;
if ( V_15 -> V_78 )
return 0 ;
F_4 ( & V_57 -> V_89 ) ;
if ( V_15 -> V_90 == NULL ) {
F_15 ( V_91 , L_12 ) ;
V_88 -> V_18 = NULL ;
V_15 -> V_90 = V_88 ;
V_15 -> V_92 = V_88 ;
} else {
F_15 ( V_91 , L_13 ) ;
V_15 -> V_92 -> V_18 = V_88 ;
V_88 -> V_18 = NULL ;
V_15 -> V_92 = V_88 ;
}
V_15 -> V_93 += 1 ;
F_15 ( V_91 , L_14 , V_15 -> V_93 ) ;
F_9 ( & V_57 -> V_89 ) ;
return V_15 -> V_93 ;
}
static struct V_87 * F_40 ( struct V_57 * V_57 )
{
T_5 * V_15 = & V_16 ;
F_15 ( V_91 , L_15 ) ;
if ( V_15 -> V_90 ) {
struct V_87 * V_88 ;
F_4 ( & V_57 -> V_89 ) ;
V_88 = V_15 -> V_90 ;
V_15 -> V_90 = V_15 -> V_90 -> V_18 ;
V_15 -> V_93 -= 1 ;
F_15 ( V_91 , L_16 ) ;
F_9 ( & V_57 -> V_89 ) ;
return V_88 ;
}
F_15 ( V_91 , L_17 ) ;
return NULL ;
}
static inline void F_8 ( void )
{
T_1 V_94 = 0 ;
V_16 . V_95 . V_96 ( 0xf0 , & V_94 ) ;
V_16 . V_95 . V_97 ( 0xf0 , V_94 & ~ F_41 ( 0 ) ) ;
}
static inline void F_6 ( void )
{
T_1 V_94 , V_98 , V_99 = 0 ;
T_1 V_100 ;
if ( ( V_16 . V_101 . V_102 & 0x1 ) == V_103 ) {
do {
V_16 . V_95 . V_96 ( 1 , & V_94 ) ;
V_16 . V_95 . V_97 ( 1 , V_94 | F_41 ( 1 ) ) ;
V_16 . V_95 . V_97 ( 1 , V_94 & ~ F_41 ( 1 ) ) ;
do {
F_42 ( 2 * 1000 , 2 * 1000 ) ;
if ( ( F_43 ( true ) == 0 ) )
F_1 ( V_104 , L_18 ) ;
} while ( ( F_43 ( true ) == 0 ) && ( ( ++ V_99 % 3 ) == 0 ) );
} while ( F_43 ( true ) == 0 );
} else if ( ( V_16 . V_101 . V_102 & 0x1 ) == V_105 ) {
V_16 . V_95 . V_96 ( 0xf0 , & V_94 ) ;
do {
V_16 . V_95 . V_97 ( 0xf0 , V_94 | F_41 ( 0 ) ) ;
V_16 . V_95 . V_96 ( 0xf1 , & V_98 ) ;
while ( ( ( V_98 & 0x1 ) == 0 ) && ( ( ( ++ V_99 ) % 3 ) == 0 ) ) {
F_42 ( 2 * 1000 , 2 * 1000 ) ;
V_16 . V_95 . V_96 ( 0xf1 , & V_98 ) ;
if ( ( V_98 & 0x1 ) == 0 )
F_1 ( V_104 , L_19 ) ;
}
if ( ( V_98 & 0x1 ) == 0 ) {
V_16 . V_95 . V_97 ( 0xf0 , V_94 &
( ~ F_41 ( 0 ) ) ) ;
}
} while ( ( V_98 & 0x1 ) == 0 );
}
if ( V_8 == V_106 ) {
V_16 . V_95 . V_96 ( 0x1C0C , & V_94 ) ;
V_94 &= ~ F_41 ( 0 ) ;
V_16 . V_95 . V_97 ( 0x1C0C , V_94 ) ;
if ( F_43 ( false ) >= 0x1002b0 ) {
T_1 V_107 ;
V_16 . V_95 . V_96 ( 0x1e1c , & V_107 ) ;
V_107 |= F_41 ( 6 ) ;
V_16 . V_95 . V_97 ( 0x1e1c , V_107 ) ;
V_16 . V_95 . V_96 ( 0x1e9c , & V_107 ) ;
V_107 |= F_41 ( 6 ) ;
V_16 . V_95 . V_97 ( 0x1e9c , V_107 ) ;
}
}
V_8 = V_9 ;
}
static inline void F_6 ( void )
{
T_1 V_94 , V_99 = 0 ;
do {
if ( ( V_16 . V_101 . V_102 & 0x1 ) == V_103 ) {
V_16 . V_95 . V_96 ( 1 , & V_94 ) ;
V_16 . V_95 . V_97 ( 1 , V_94 & ~ F_41 ( 1 ) ) ;
V_16 . V_95 . V_97 ( 1 , V_94 | F_41 ( 1 ) ) ;
V_16 . V_95 . V_97 ( 1 , V_94 & ~ F_41 ( 1 ) ) ;
} else if ( ( V_16 . V_101 . V_102 & 0x1 ) == V_105 ) {
V_16 . V_95 . V_96 ( 0xf0 , & V_94 ) ;
V_16 . V_95 . V_97 ( 0xf0 , V_94 & ~ F_41 ( 0 ) ) ;
V_16 . V_95 . V_97 ( 0xf0 , V_94 | F_41 ( 0 ) ) ;
V_16 . V_95 . V_97 ( 0xf0 , V_94 & ~ F_41 ( 0 ) ) ;
}
do {
F_44 ( 3 ) ;
if ( ( F_43 ( true ) == 0 ) )
F_1 ( V_104 , L_18 ) ;
} while ( ( F_43 ( true ) == 0 ) && ( ( ++ V_99 % 3 ) == 0 ) );
} while ( F_43 ( true ) == 0 );
if ( V_8 == V_106 ) {
V_16 . V_95 . V_96 ( 0x1C0C , & V_94 ) ;
V_94 &= ~ F_41 ( 0 ) ;
V_16 . V_95 . V_97 ( 0x1C0C , V_94 ) ;
if ( F_43 ( false ) >= 0x1002b0 ) {
T_1 V_107 ;
V_16 . V_95 . V_96 ( 0x1e1c , & V_107 ) ;
V_107 |= F_41 ( 6 ) ;
V_16 . V_95 . V_97 ( 0x1e1c , V_107 ) ;
V_16 . V_95 . V_96 ( 0x1e9c , & V_107 ) ;
V_107 |= F_41 ( 6 ) ;
V_16 . V_95 . V_97 ( 0x1e9c , V_107 ) ;
}
}
V_8 = V_9 ;
}
void F_45 ( T_1 V_108 )
{
if ( V_8 != V_9 ) {
return;
}
F_3 ( V_109 ) ;
#ifdef F_5
F_8 () ;
#endif
V_16 . V_95 . V_97 ( 0x10a8 , 1 ) ;
V_8 = V_106 ;
F_7 ( V_110 ) ;
}
int F_46 ( struct V_49 * V_50 , T_1 * V_111 )
{
T_5 * V_15 = ( T_5 * ) & V_16 ;
int V_55 , V_112 = 0 ;
T_1 V_113 ;
T_1 V_94 ;
T_6 * V_114 = V_15 -> V_115 ;
T_1 V_116 = 0 ;
int V_117 = 0 ;
struct V_13 * V_14 ;
int V_51 = 0 ;
int V_118 ;
int V_119 ;
T_1 V_120 [ V_121 ] ;
T_7 * V_56 ;
struct V_57 * V_57 ;
V_56 = F_25 ( V_50 ) ;
V_57 = V_56 -> V_57 ;
V_15 -> V_122 = 0 ;
do {
if ( V_15 -> V_78 )
break;
F_18 ( & V_57 -> V_26 ,
V_27 ) ;
#ifdef F_34
F_27 ( V_50 ) ;
#endif
F_15 ( V_24 , L_20 ) ;
V_14 = F_37 () ;
V_55 = 0 ;
V_113 = 0 ;
do {
if ( ( V_14 != NULL ) && ( V_55 < ( V_121 - 1 ) ) ) {
if ( V_14 -> type == V_81 )
V_117 = V_123 ;
else if ( V_14 -> type == V_84 )
V_117 = V_124 ;
else
V_117 = V_125 ;
V_117 += V_14 -> V_77 ;
F_15 ( V_24 , L_21 , V_117 ) ;
if ( V_117 & 0x3 ) {
V_117 = ( V_117 + 4 ) & ~ 0x3 ;
}
if ( ( V_113 + V_117 ) > V_126 )
break;
F_15 ( V_24 , L_22 , V_117 ) ;
V_120 [ V_55 ] = V_117 / 4 ;
F_15 ( V_24 , L_23 , V_120 [ V_55 ] ) ;
if ( V_14 -> type == V_81 ) {
V_120 [ V_55 ] |= F_41 ( 10 ) ;
F_15 ( V_24 , L_24 , V_120 [ V_55 ] ) ;
}
#ifdef F_47
V_120 [ V_55 ] = F_48 ( V_120 [ V_55 ] ) ;
#endif
V_55 ++ ;
V_113 += V_117 ;
F_15 ( V_24 , L_25 , V_113 ) ;
V_14 = F_38 ( V_57 , V_14 ) ;
} else {
break;
}
} while ( 1 );
if ( V_55 == 0 ) {
F_15 ( V_24 , L_26 ) ;
break;
} else {
F_15 ( V_24 , L_27 , V_55 ) ;
V_120 [ V_55 ] = 0x0 ;
}
F_3 ( V_10 ) ;
V_118 = 0 ;
do {
V_51 = V_15 -> V_95 . V_96 ( V_127 , & V_94 ) ;
if ( ! V_51 ) {
F_1 ( V_104 , L_28 ) ;
break;
}
if ( ( V_94 & 0x1 ) == 0 ) {
F_15 ( V_24 , L_29 , ( ( V_55 + 1 ) * 4 ) ) ;
break;
} else {
V_118 ++ ;
if ( V_118 > 200 ) {
V_118 = 0 ;
F_15 ( V_24 , L_30 ) ;
V_51 = V_15 -> V_95 . V_97 ( V_127 , 0 ) ;
break;
}
F_49 ( V_128 , L_31 ) ;
F_7 ( V_12 ) ;
F_42 ( 3000 , 3000 ) ;
F_3 ( V_10 ) ;
}
} while ( ! V_15 -> V_78 );
if ( ! V_51 )
goto V_129;
V_119 = 200 ;
do {
V_51 = V_15 -> V_95 . V_130 ( V_131 , ( T_6 * ) V_120 , ( ( V_55 + 1 ) * 4 ) ) ;
if ( ! V_51 ) {
F_1 ( V_104 , L_32 ) ;
break;
}
V_51 = V_15 -> V_95 . V_97 ( V_132 , 0x2 ) ;
if ( ! V_51 ) {
F_1 ( V_104 , L_33 ) ;
break;
}
do {
V_51 = V_15 -> V_95 . V_96 ( V_132 , & V_94 ) ;
if ( ! V_51 ) {
F_1 ( V_104 , L_34 ) ;
break;
}
if ( ( V_94 >> 2 ) & 0x1 ) {
V_112 = ( ( V_94 >> 3 ) & 0x3f ) ;
break;
} else {
F_7 ( V_12 ) ;
F_42 ( 3000 , 3000 ) ;
F_3 ( V_10 ) ;
F_49 ( V_128 , L_35 , V_94 ) ;
}
} while ( -- V_119 );
if ( V_119 <= 0 ) {
V_51 = V_15 -> V_95 . V_97 ( V_132 , 0x0 ) ;
break;
}
if ( ! V_51 )
break;
if ( V_112 == 0 ) {
F_49 ( V_128 , L_36 , V_94 , V_55 , V_120 [ V_55 - 1 ] ) ;
V_51 = V_15 -> V_95 . V_96 ( V_127 , & V_94 ) ;
if ( ! V_51 ) {
F_1 ( V_104 , L_37 ) ;
break;
}
V_94 &= ~ F_41 ( 0 ) ;
V_51 = V_15 -> V_95 . V_97 ( V_127 , V_94 ) ;
if ( ! V_51 ) {
F_1 ( V_104 , L_38 ) ;
break;
}
break;
} else {
break;
}
} while ( 1 );
if ( ! V_51 )
goto V_129;
if ( V_112 == 0 ) {
V_51 = V_133 ;
goto V_129;
}
F_7 ( V_12 ) ;
V_116 = 0 ;
V_55 = 0 ;
do {
V_14 = F_11 () ;
if ( V_14 != NULL && ( V_120 [ V_55 ] != 0 ) ) {
T_1 V_134 , V_135 ;
#ifdef F_47
V_120 [ V_55 ] = F_48 ( V_120 [ V_55 ] ) ;
#endif
V_117 = ( V_120 [ V_55 ] & 0x3ff ) ;
V_117 *= 4 ;
V_134 = ( V_14 -> type << 31 ) | ( V_14 -> V_77 << 15 ) | V_117 ;
if ( V_14 -> type == V_86 )
V_134 |= F_41 ( 30 ) ;
else
V_134 &= ~ F_41 ( 30 ) ;
#ifdef F_47
V_134 = F_48 ( V_134 ) ;
#endif
memcpy ( & V_114 [ V_116 ] , & V_134 , 4 ) ;
if ( V_14 -> type == V_81 ) {
V_135 = V_123 ;
}
else if ( V_14 -> type == V_84 ) {
char * V_136 = ( (struct V_137 * ) ( V_14 -> V_73 ) ) -> V_138 ;
V_135 = V_124 ;
memcpy ( & V_114 [ V_116 + 4 ] , V_136 , 6 ) ;
}
else {
V_135 = V_125 ;
}
memcpy ( & V_114 [ V_116 + V_135 ] , V_14 -> V_53 , V_14 -> V_77 ) ;
V_116 += V_117 ;
V_55 ++ ;
V_14 -> V_71 = 1 ;
if ( V_14 -> V_72 )
V_14 -> V_72 ( V_14 -> V_73 , V_14 -> V_71 ) ;
#ifdef F_34
if ( V_14 -> V_48 != V_82 )
V_45 [ V_14 -> V_48 ] . V_41 = NULL ;
#endif
F_28 ( V_14 ) ;
} else {
break;
}
} while ( -- V_112 );
F_3 ( V_10 ) ;
V_51 = V_15 -> V_95 . V_139 ( V_140 ) ;
if ( ! V_51 ) {
F_1 ( V_104 , L_39 ) ;
goto V_129;
}
V_51 = V_15 -> V_95 . V_141 ( 0 , V_114 , V_116 ) ;
if ( ! V_51 ) {
F_1 ( V_104 , L_40 ) ;
goto V_129;
}
V_129:
F_7 ( V_12 ) ;
if ( V_51 != 1 )
break;
} while ( 0 );
F_16 ( & V_57 -> V_26 ) ;
V_15 -> V_122 = 1 ;
F_15 ( V_24 , L_41 ) ;
* V_111 = V_15 -> V_21 ;
return V_51 ;
}
static void F_50 ( struct V_57 * V_57 )
{
T_5 * V_15 = & V_16 ;
int V_116 = 0 , V_142 , V_143 = 0 ;
T_6 * V_53 ;
struct V_87 * V_88 ;
V_15 -> V_144 = 0 ;
do {
if ( V_15 -> V_78 ) {
F_15 ( V_91 , L_42 ) ;
F_16 ( & V_57 -> V_79 ) ;
break;
}
V_88 = F_40 ( V_57 ) ;
if ( V_88 == NULL ) {
F_15 ( V_91 , L_43 ) ;
break;
}
V_53 = V_88 -> V_53 ;
V_142 = V_88 -> V_77 ;
F_15 ( V_91 , L_44 , V_142 , V_53 ) ;
V_116 = 0 ;
do {
T_1 V_134 ;
T_1 V_145 , V_146 , V_147 ;
int V_148 ;
F_15 ( V_91 , L_45 ) ;
memcpy ( & V_134 , & V_53 [ V_116 ] , 4 ) ;
#ifdef F_47
V_134 = F_48 ( V_134 ) ;
#endif
F_15 ( V_91 , L_46 , V_134 , V_116 ) ;
V_148 = ( V_134 >> 31 ) & 0x1 ;
V_146 = ( V_134 >> 22 ) & 0x1ff ;
V_147 = ( V_134 >> 11 ) & 0x7ff ;
V_145 = V_134 & 0x7ff ;
if ( V_145 == 0 || V_147 == 0 ) {
F_1 ( V_149 , L_47 , V_145 , V_147 ) ;
break;
}
#define F_51 0x100
#define F_52 0x080
#define F_53 0x040
if ( V_146 & F_51 ) {
V_146 &= ~ ( F_51 | F_52 | F_53 ) ;
F_54 ( V_57 , & V_53 [ V_116 + V_125 ] , V_145 ) ;
}
else
{
if ( ! V_148 ) {
if ( V_145 > 0 ) {
F_55 ( V_57 ,
& V_53 [ V_116 ] ,
V_145 ,
V_146 ) ;
V_143 = 1 ;
}
} else {
T_9 V_150 ;
F_56 ( & V_53 [ V_146 + V_116 ] , V_145 , & V_150 ) ;
if ( V_150 . type == V_151 ) {
F_15 ( V_91 , L_48 , V_15 -> V_152 , V_150 . V_66 ) ;
if ( V_15 -> V_152 == V_150 . V_66 )
F_16 ( & V_57 -> V_79 ) ;
} else if ( V_150 . type == V_153 ) {
F_57 ( V_57 , V_154 ) ;
} else if ( V_150 . type == V_155 ) {
F_57 ( V_57 , V_156 ) ;
}
}
}
V_116 += V_147 ;
if ( V_116 >= V_142 )
break;
} while ( 1 );
#ifndef F_58
F_28 ( V_53 ) ;
#endif
F_28 ( V_88 ) ;
if ( V_143 )
F_59 () ;
} while ( 1 );
V_15 -> V_144 = 1 ;
F_15 ( V_91 , L_49 ) ;
}
static void F_60 ( void )
{
V_16 . V_95 . V_139 ( 0 ) ;
}
static void F_61 ( T_1 V_157 )
{
int V_99 = 10 ;
V_16 . V_95 . V_139 ( V_158 ) ;
F_44 ( V_159 ) ;
while ( ! ( F_62 ( F_43 ( true ) ) && -- V_99 ) ) {
F_15 ( V_24 , L_50 ) ;
F_44 ( 1 ) ;
}
}
static void F_63 ( T_1 V_160 )
{
V_16 . V_95 . V_139 ( V_161 ) ;
#ifndef F_5
V_8 = V_162 ;
#endif
}
static void F_64 ( struct V_57 * V_57 , T_1 V_163 )
{
T_5 * V_15 = & V_16 ;
#ifdef F_58
T_1 V_116 = V_15 -> V_164 ;
#endif
T_6 * V_53 = NULL ;
T_1 V_142 ;
T_1 V_165 = 0 ;
int V_51 = 0 ;
struct V_87 * V_88 ;
V_142 = ( ( V_163 & 0x7fff ) << 2 ) ;
while ( ! V_142 && V_165 < 10 ) {
T_1 time = 0 ;
F_1 ( V_104 , L_51 , time ++ ) ;
V_15 -> V_95 . V_166 ( & V_142 ) ;
V_142 = ( ( V_142 & 0x7fff ) << 2 ) ;
V_165 ++ ;
}
if ( V_142 > 0 ) {
#ifdef F_58
if ( V_167 - V_116 < V_142 )
V_116 = 0 ;
if ( V_15 -> V_168 )
V_53 = & V_15 -> V_168 [ V_116 ] ;
else {
F_1 ( V_104 , L_52 , V_142 ) ;
goto V_129;
}
#else
V_53 = F_32 ( V_142 , V_85 ) ;
if ( V_53 == NULL ) {
F_1 ( V_104 , L_53 , V_142 ) ;
F_42 ( 100 * 1000 , 100 * 1000 ) ;
goto V_129;
}
#endif
V_15 -> V_95 . V_139 ( V_169 | V_170 ) ;
V_51 = V_15 -> V_95 . V_171 ( 0 , V_53 , V_142 ) ;
if ( ! V_51 ) {
F_1 ( V_104 , L_54 ) ;
goto V_129;
}
V_129:
if ( V_51 ) {
#ifdef F_58
V_116 += V_142 ;
V_15 -> V_164 = V_116 ;
#endif
V_88 = F_32 ( sizeof( struct V_87 ) , V_85 ) ;
if ( V_88 != NULL ) {
V_88 -> V_53 = V_53 ;
V_88 -> V_77 = V_142 ;
F_15 ( V_91 , L_55 , V_88 -> V_77 , V_88 -> V_53 ) ;
F_39 ( V_57 , V_88 ) ;
}
} else {
#ifndef F_58
F_28 ( V_53 ) ;
#endif
}
}
F_50 ( V_57 ) ;
}
void F_65 ( void * V_57 )
{
T_1 V_163 ;
F_3 ( V_10 ) ;
V_16 . V_95 . V_172 ( & V_163 ) ;
if ( V_163 & V_173 )
F_61 ( V_163 ) ;
if ( V_163 & V_174 ) {
F_64 ( V_57 , V_163 ) ;
#ifndef F_5
V_8 = V_9 ;
#endif
}
if ( V_163 & V_175 )
F_63 ( V_163 ) ;
if ( ! ( V_163 & ( V_176 ) ) ) {
#ifdef F_66
F_15 ( V_24 , L_56 , V_163 ) ;
#endif
F_60 () ;
}
F_7 ( V_12 ) ;
}
int F_67 ( const T_6 * V_53 , T_1 V_77 )
{
T_5 * V_15 = & V_16 ;
T_1 V_116 ;
T_1 V_177 , V_142 , V_178 , V_179 ;
T_6 * V_180 ;
int V_51 = 0 ;
V_179 = F_41 ( 12 ) ;
V_180 = F_32 ( V_179 , V_85 ) ;
if ( V_180 == NULL ) {
V_51 = - 5 ;
F_33 ( L_57 ) ;
goto V_181;
}
F_15 ( V_182 , L_58 , V_77 ) ;
V_116 = 0 ;
do {
memcpy ( & V_177 , & V_53 [ V_116 ] , 4 ) ;
memcpy ( & V_142 , & V_53 [ V_116 + 4 ] , 4 ) ;
#ifdef F_47
V_177 = F_48 ( V_177 ) ;
V_142 = F_48 ( V_142 ) ;
#endif
F_3 ( V_109 ) ;
V_116 += 8 ;
while ( ( ( int ) V_142 ) && ( V_116 < V_77 ) ) {
if ( V_142 <= V_179 )
V_178 = V_142 ;
else
V_178 = V_179 ;
memcpy ( V_180 , & V_53 [ V_116 ] , V_178 ) ;
V_51 = V_15 -> V_95 . V_130 ( V_177 , V_180 , V_178 ) ;
if ( ! V_51 )
break;
V_177 += V_178 ;
V_116 += V_178 ;
V_142 -= V_178 ;
}
F_7 ( V_110 ) ;
if ( ! V_51 ) {
V_51 = - 5 ;
F_33 ( L_59 ) ;
goto V_183;
}
F_15 ( V_182 , L_60 , V_116 ) ;
} while ( V_116 < V_77 );
V_183:
F_28 ( V_180 ) ;
V_181:
return ( V_51 < 0 ) ? V_51 : 0 ;
}
int F_68 ( void )
{
T_5 * V_15 = & V_16 ;
T_1 V_94 = 0 ;
int V_51 ;
T_1 V_184 ;
if ( V_15 -> V_101 . V_102 == V_105 ) {
V_94 = 0 ;
V_94 |= F_41 ( 3 ) ;
} else if ( V_15 -> V_101 . V_102 == V_103 ) {
V_94 = 1 ;
}
F_3 ( V_109 ) ;
V_51 = V_15 -> V_95 . V_97 ( V_185 , V_94 ) ;
if ( ! V_51 ) {
F_1 ( V_104 , L_61 ) ;
F_7 ( V_110 ) ;
V_51 = - 5 ;
return V_51 ;
}
V_94 = 0 ;
#ifdef F_69
V_94 |= V_186 ;
#endif
#ifdef F_70
#else
V_94 |= V_187 ;
#endif
#ifdef F_71
V_94 |= V_188 ;
#elif V_189 V_190
V_94 |= V_191 ;
#endif
#ifdef F_72
V_94 |= V_192 ;
#endif
V_94 |= V_193 ;
#ifdef F_73
V_94 |= V_194 ;
#endif
#ifdef F_74
V_94 |= V_195 ;
#endif
V_51 = V_15 -> V_95 . V_97 ( V_196 , V_94 ) ;
if ( ! V_51 ) {
F_1 ( V_104 , L_62 ) ;
F_7 ( V_110 ) ;
V_51 = - 5 ;
return V_51 ;
}
V_15 -> V_95 . V_197 ( V_198 ) ;
V_51 = V_15 -> V_95 . V_96 ( 0x1000 , & V_184 ) ;
if ( ! V_51 ) {
F_1 ( V_104 , L_63 ) ;
F_7 ( V_110 ) ;
V_51 = - 5 ;
return V_51 ;
}
V_15 -> V_95 . V_96 ( V_199 , & V_94 ) ;
if ( ( V_94 & F_41 ( 10 ) ) == F_41 ( 10 ) ) {
V_94 &= ~ F_41 ( 10 ) ;
V_15 -> V_95 . V_97 ( V_199 , V_94 ) ;
V_15 -> V_95 . V_96 ( V_199 , & V_94 ) ;
}
V_94 |= F_41 ( 10 ) ;
V_51 = V_15 -> V_95 . V_97 ( V_199 , V_94 ) ;
V_15 -> V_95 . V_96 ( V_199 , & V_94 ) ;
F_7 ( V_110 ) ;
return ( V_51 < 0 ) ? V_51 : 0 ;
}
void F_75 ( void )
{
T_5 * V_15 = & V_16 ;
F_3 ( V_10 ) ;
V_15 -> V_95 . V_97 ( V_199 , 0x0 ) ;
F_7 ( V_110 ) ;
}
int F_76 ( void )
{
T_5 * V_15 = & V_16 ;
T_1 V_94 = 0 ;
int V_51 ;
T_6 V_119 = 10 ;
F_3 ( V_10 ) ;
V_51 = V_15 -> V_95 . V_96 ( V_199 , & V_94 ) ;
if ( ! V_51 ) {
F_33 ( L_64 ) ;
F_7 ( V_12 ) ;
return V_51 ;
}
V_94 &= ~ F_41 ( 10 ) ;
V_51 = V_15 -> V_95 . V_97 ( V_199 , V_94 ) ;
if ( ! V_51 ) {
F_33 ( L_65 ) ;
F_7 ( V_12 ) ;
return V_51 ;
}
do {
V_51 = V_15 -> V_95 . V_96 ( V_199 , & V_94 ) ;
if ( ! V_51 ) {
F_33 ( L_64 ) ;
F_7 ( V_12 ) ;
return V_51 ;
}
F_15 ( V_128 , L_66 , V_94 , V_119 ) ;
if ( ( V_94 & F_41 ( 10 ) ) ) {
F_15 ( V_128 , L_67 , V_119 ) ;
V_94 &= ~ F_41 ( 10 ) ;
V_51 = V_15 -> V_95 . V_97 ( V_199 , V_94 ) ;
V_119 -- ;
} else {
F_15 ( V_128 , L_68 , V_119 ) ;
V_51 = V_15 -> V_95 . V_96 ( V_199 , & V_94 ) ;
if ( ! V_51 ) {
F_33 ( L_64 ) ;
F_7 ( V_12 ) ;
return V_51 ;
}
F_15 ( V_128 , L_66 , V_94 , V_119 ) ;
break;
}
} while ( V_119 );
V_94 = ( F_41 ( 0 ) | F_41 ( 1 ) | F_41 ( 2 ) | F_41 ( 3 ) | F_41 ( 8 ) | F_41 ( 9 ) | F_41 ( 26 ) |
F_41 ( 29 ) | F_41 ( 30 ) | F_41 ( 31 ) ) ;
V_15 -> V_95 . V_97 ( V_199 , V_94 ) ;
V_94 = ( T_1 ) ~ F_41 ( 10 ) ;
V_51 = V_15 -> V_95 . V_97 ( V_199 , V_94 ) ;
F_7 ( V_12 ) ;
return V_51 ;
}
void F_77 ( struct V_49 * V_50 )
{
T_5 * V_15 = & V_16 ;
struct V_13 * V_14 ;
struct V_87 * V_88 ;
T_1 V_94 = 0 ;
int V_51 ;
T_7 * V_56 ;
struct V_57 * V_57 ;
V_56 = F_25 ( V_50 ) ;
V_57 = V_56 -> V_57 ;
V_15 -> V_78 = 1 ;
do {
V_14 = F_11 () ;
if ( V_14 == NULL )
break;
if ( V_14 -> V_72 )
V_14 -> V_72 ( V_14 -> V_73 , 0 ) ;
F_28 ( V_14 ) ;
} while ( 1 );
do {
V_88 = F_40 ( V_57 ) ;
if ( V_88 == NULL )
break;
#ifndef F_58
F_28 ( V_88 -> V_53 ) ;
#endif
F_28 ( V_88 ) ;
} while ( 1 );
#ifdef F_58
F_28 ( V_15 -> V_168 ) ;
V_15 -> V_168 = NULL ;
#endif
F_28 ( V_15 -> V_115 ) ;
F_3 ( V_10 ) ;
V_51 = V_15 -> V_95 . V_96 ( V_200 , & V_94 ) ;
if ( ! V_51 ) {
F_33 ( L_64 ) ;
F_7 ( V_12 ) ;
}
F_33 ( L_69 ) ;
V_51 = V_15 -> V_95 . V_97 ( V_200 , ( V_94 | V_201 ) ) ;
if ( ! V_51 ) {
F_33 ( L_65 ) ;
F_7 ( V_12 ) ;
}
F_7 ( V_12 ) ;
V_15 -> V_95 . V_202 ( NULL ) ;
}
static int F_78 ( int type , T_1 V_203 )
{
T_5 * V_15 = & V_16 ;
T_10 * V_204 = & V_15 -> V_205 ;
int V_206 = V_15 -> V_207 + 4 + V_208 ;
int V_66 = V_15 -> V_152 % 256 ;
int V_209 = ( T_1 ) V_203 ;
if ( type == V_210 ) {
V_204 -> V_211 [ 0 ] = 'W' ;
} else {
V_204 -> V_211 [ 0 ] = 'Q' ;
}
V_204 -> V_211 [ 1 ] = V_66 ;
V_204 -> V_211 [ 2 ] = ( T_6 ) V_206 ;
V_204 -> V_211 [ 3 ] = ( T_6 ) ( V_206 >> 8 ) ;
V_204 -> V_211 [ 4 ] = ( T_6 ) V_209 ;
V_204 -> V_211 [ 5 ] = ( T_6 ) ( V_209 >> 8 ) ;
V_204 -> V_211 [ 6 ] = ( T_6 ) ( V_209 >> 16 ) ;
V_204 -> V_211 [ 7 ] = ( T_6 ) ( V_209 >> 24 ) ;
V_15 -> V_152 = V_66 ;
if ( ! F_31 ( & V_204 -> V_211 [ 0 ] , V_206 ) )
return - 1 ;
return 0 ;
}
int F_79 ( int V_212 , T_1 V_213 , T_6 * V_53 , T_1 V_77 ,
int V_214 , T_1 V_203 )
{
T_5 * V_15 = & V_16 ;
T_1 V_116 ;
int V_215 ;
if ( V_15 -> V_216 )
return 0 ;
if ( V_212 )
V_15 -> V_207 = 0 ;
V_116 = V_15 -> V_207 ;
V_215 = F_80 ( V_15 -> V_205 . V_217 , V_116 , ( V_218 ) V_213 ,
V_53 , V_77 ) ;
V_116 += V_215 ;
V_15 -> V_207 = V_116 ;
if ( V_214 ) {
F_15 ( V_24 , L_70 , V_15 -> V_152 ) ;
F_15 ( V_91 , L_71 ) ;
V_15 -> V_216 = 1 ;
if ( F_78 ( V_210 , V_203 ) )
V_215 = 0 ;
if ( F_18 ( & V_6 -> V_79 ,
V_27 ) ) {
F_15 ( V_24 , L_72 ) ;
V_215 = 0 ;
}
V_15 -> V_216 = 0 ;
V_15 -> V_207 = 0 ;
V_15 -> V_152 += 1 ;
}
return V_215 ;
}
int F_81 ( int V_212 , T_1 V_213 , int V_214 , T_1 V_203 )
{
T_5 * V_15 = & V_16 ;
T_1 V_116 ;
int V_215 ;
if ( V_15 -> V_216 )
return 0 ;
if ( V_212 )
V_15 -> V_207 = 0 ;
V_116 = V_15 -> V_207 ;
V_215 = F_82 ( V_15 -> V_205 . V_217 , V_116 , ( V_218 ) V_213 ) ;
V_116 += V_215 ;
V_15 -> V_207 = V_116 ;
if ( V_214 ) {
V_15 -> V_216 = 1 ;
if ( F_78 ( V_219 , V_203 ) )
V_215 = 0 ;
if ( F_18 ( & V_6 -> V_79 ,
V_27 ) ) {
F_15 ( V_24 , L_73 ) ;
V_215 = 0 ;
}
F_15 ( V_128 , L_74 ) ;
V_15 -> V_216 = 0 ;
V_15 -> V_207 = 0 ;
V_15 -> V_152 += 1 ;
}
return V_215 ;
}
int F_83 ( T_1 V_213 , T_6 * V_53 , T_1 V_77 )
{
int V_51 ;
V_51 = F_84 ( ( V_218 ) V_213 , V_53 , V_77 ) ;
return V_51 ;
}
void F_85 ( void )
{
V_16 . V_95 . V_220 () ;
}
void F_86 ( void )
{
V_16 . V_95 . V_221 () ;
}
T_1 F_87 ( void )
{
T_1 V_184 ;
T_1 V_94 , V_51 = 0 ;
F_3 ( V_109 ) ;
V_184 = F_43 ( true ) ;
if ( ( V_184 & 0xfff ) != 0xa0 ) {
V_51 = V_16 . V_95 . V_96 ( 0x1118 , & V_94 ) ;
if ( ! V_51 ) {
F_1 ( V_104 , L_75 ) ;
return V_51 ;
}
V_94 |= F_41 ( 0 ) ;
V_51 = V_16 . V_95 . V_97 ( 0x1118 , V_94 ) ;
if ( ! V_51 ) {
F_1 ( V_104 , L_76 ) ;
return V_51 ;
}
V_51 = V_16 . V_95 . V_97 ( 0xc0000 , 0x71 ) ;
if ( ! V_51 ) {
F_1 ( V_104 , L_77 ) ;
return V_51 ;
}
}
F_7 ( V_110 ) ;
return V_51 ;
}
T_1 F_43 ( T_6 V_222 )
{
static T_1 V_184 ;
T_1 V_223 = 0 ;
T_1 V_224 ;
if ( V_184 == 0 || V_222 != 0 ) {
V_16 . V_95 . V_96 ( 0x1000 , & V_223 ) ;
V_16 . V_95 . V_96 ( 0x13f4 , & V_224 ) ;
if ( ! F_62 ( V_223 ) ) {
V_184 = 0 ;
goto V_183;
}
if ( V_223 == 0x1002a0 ) {
if ( V_224 == 0x1 ) {
} else {
V_223 = 0x1002a1 ;
}
} else if ( V_223 == 0x1002b0 ) {
if ( V_224 == 3 ) {
} else if ( V_224 == 4 ) {
V_223 = 0x1002b1 ;
} else {
V_223 = 0x1002b2 ;
}
} else {
}
V_184 = V_223 ;
}
V_183:
return V_184 ;
}
int F_88 ( T_11 * V_225 )
{
int V_51 = 0 ;
F_15 ( V_182 , L_78 ) ;
memset ( ( void * ) & V_16 , 0 , sizeof( T_5 ) ) ;
memcpy ( ( void * ) & V_16 . V_101 , ( void * ) & V_225 -> V_101 , sizeof( V_226 ) ) ;
if ( ( V_225 -> V_101 . V_102 & 0x1 ) == V_105 ) {
if ( ! V_227 . V_228 ( V_225 , F_1 ) ) {
V_51 = - 5 ;
goto V_183;
}
memcpy ( ( void * ) & V_16 . V_95 , & V_227 , sizeof( V_229 ) ) ;
} else {
if ( ( V_225 -> V_101 . V_102 & 0x1 ) == V_103 ) {
if ( ! V_230 . V_228 ( V_225 , F_1 ) ) {
V_51 = - 5 ;
goto V_183;
}
memcpy ( ( void * ) & V_16 . V_95 , & V_230 , sizeof( V_229 ) ) ;
} else {
V_51 = - 5 ;
goto V_183;
}
}
if ( ! F_89 ( F_1 ) ) {
V_51 = - 105 ;
goto V_183;
}
if ( V_16 . V_115 == NULL )
V_16 . V_115 = F_32 ( V_126 , V_85 ) ;
F_15 ( V_24 , L_79 , V_16 . V_115 ) ;
if ( V_16 . V_115 == NULL ) {
V_51 = - 105 ;
F_33 ( L_80 ) ;
goto V_183;
}
#if V_189 ( F_58 )
if ( V_16 . V_168 == NULL )
V_16 . V_168 = F_32 ( V_167 , V_85 ) ;
F_15 ( V_24 , L_81 , V_16 . V_168 ) ;
if ( V_16 . V_168 == NULL ) {
V_51 = - 105 ;
F_33 ( L_82 ) ;
goto V_183;
}
#endif
if ( ! F_87 () ) {
V_51 = - 5 ;
goto V_183;
}
#ifdef F_34
F_19 () ;
#endif
return 1 ;
V_183:
#ifdef F_58
F_28 ( V_16 . V_168 ) ;
V_16 . V_168 = NULL ;
#endif
F_28 ( V_16 . V_115 ) ;
V_16 . V_115 = NULL ;
return V_51 ;
}
V_218 F_90 ( struct V_49 * V_50 , bool V_231 )
{
V_218 V_51 ;
T_1 V_94 ;
T_7 * V_56 ;
struct V_57 * V_57 ;
V_56 = F_25 ( V_50 ) ;
V_57 = V_56 -> V_57 ;
F_4 ( & V_57 -> V_7 ) ;
V_51 = ( & V_16 ) -> V_95 . V_96 ( V_232 , & V_94 ) ;
if ( ! V_51 )
F_33 ( L_83 ) ;
if ( V_231 )
V_94 |= F_41 ( 31 ) ;
else
V_94 &= ~ F_41 ( 31 ) ;
V_51 = ( & V_16 ) -> V_95 . V_97 ( V_232 , V_94 ) ;
if ( ! V_51 )
F_33 ( L_84 ) ;
F_9 ( & V_57 -> V_7 ) ;
return V_51 ;
}
