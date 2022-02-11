static inline unsigned long
F_1 ( unsigned long V_1 , unsigned long V_2 )
{
return ( V_2 + ( V_1 << 4 ) + ( V_1 >> 4 ) ) * 11 ;
}
static inline unsigned int
F_2 ( const unsigned char * V_3 )
{
unsigned long V_4 = 0 ;
unsigned int V_5 = strlen ( ( const char * ) V_3 ) ;
while ( V_5 -- )
V_4 = F_1 ( * V_3 ++ , V_4 ) ;
return ( unsigned int ) V_4 ;
}
static T_1 F_3 ( T_1 * V_6 , T_1 V_3 , T_1 args , int V_7 , bool * V_8 )
{
T_1 type ;
* V_8 = true ;
if ( F_4 ( * V_6 ) == V_9 ) {
error ( L_1 , V_3 , * V_6 ) ;
return V_10 ;
}
if ( F_4 ( * V_6 ) == V_11 ) {
error ( L_2 , V_3 , * V_6 ) ;
return V_10 ;
}
if ( F_4 ( * V_6 ) == V_12 ) {
error ( L_3 , V_3 , * V_6 ) ;
return V_10 ;
}
if ( F_5 ( * V_6 ) ) {
type = * V_6 ;
} else {
F_6 ( F_4 ( * V_6 ) == V_13 ) ;
type = F_7 ( * V_6 ) ;
}
if ( F_4 ( type ) != V_14 ) {
error ( L_4 , V_3 , type ) ;
return V_10 ;
}
if ( F_8 ( F_9 ( V_3 ) , F_10 ( type ) ) ) {
error ( L_5 , V_3 , type ) ;
return V_10 ;
}
* V_8 = false ;
return V_10 ;
}
static T_1 F_11 ( T_1 * V_6 , T_1 V_3 , T_1 args , int V_7 , bool * V_8 )
{
* V_8 = false ;
return V_10 ;
}
static T_1 F_12 ( T_1 * V_6 , T_1 V_3 , T_1 args , int V_7 , bool * V_8 )
{
* V_8 = false ;
return V_10 ;
}
static T_2 F_13 ( T_3 * V_15 ) {
T_2 V_16 = V_15 -> V_17 - F_14 ( V_15 -> V_18 , 7 ) ;
V_15 -> V_17 = V_15 -> V_18 ^ F_14 ( V_15 -> V_1 , 13 ) ;
V_15 -> V_18 = V_15 -> V_1 + F_14 ( V_15 -> V_19 , 37 ) ;
V_15 -> V_1 = V_15 -> V_19 + V_16 ;
V_15 -> V_19 = V_16 + V_15 -> V_17 ;
return V_15 -> V_19 ;
}
static void F_15 ( T_3 * V_15 , T_2 * V_20 ) {
int V_21 ;
V_15 -> V_17 = V_20 [ 0 ] ;
V_15 -> V_18 = V_20 [ 1 ] ;
V_15 -> V_1 = V_20 [ 2 ] ;
V_15 -> V_19 = V_20 [ 3 ] ;
for ( V_21 = 0 ; V_21 < 30 ; ++ V_21 )
( void ) F_13 ( V_15 ) ;
}
static void F_16 ( T_1 * V_22 , unsigned long V_23 , struct V_24 * V_25 , unsigned long * V_26 )
{
unsigned long V_21 ;
unsigned long V_27 = 0 ;
unsigned long V_28 = 0 ;
unsigned long V_29 = 0 ;
F_6 ( V_23 < V_30 ) ;
memset ( V_25 , 0 , sizeof( struct V_24 ) * V_23 ) ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
if ( V_25 [ V_29 ] . V_31 == V_10 ) {
V_25 [ V_29 ] . V_31 = V_22 [ V_21 ] ;
V_25 [ V_29 ] . V_32 = V_21 ;
V_28 = 0 ;
V_27 = 0 ;
}
V_27 += ( unsigned long ) F_17 ( F_7 ( V_22 [ V_21 ] ) ) ;
V_28 ++ ;
if ( V_27 >= 64 ) {
V_25 [ V_29 ] . V_23 = V_28 ;
V_28 = 0 ;
V_29 ++ ;
}
}
if ( V_25 [ V_29 ] . V_31 != V_10 &&
! V_25 [ V_29 ] . V_23 ) {
V_25 [ V_29 ] . V_23 = V_28 ;
V_29 ++ ;
}
* V_26 = V_29 ;
}
static void F_18 ( T_1 * V_33 , unsigned long V_23 , T_3 * V_34 )
{
unsigned long V_21 , V_15 ;
struct V_24 V_35 [ V_23 ] ;
unsigned long V_26 = 0 ;
unsigned long V_36 ;
F_16 ( V_33 , V_23 , (struct V_24 * ) & V_35 , & V_26 ) ;
for ( V_21 = V_26 - 1 ; V_21 > 0 ; V_21 -- ) {
struct V_24 V_37 ;
V_36 = F_13 ( V_34 ) % ( V_21 + 1 ) ;
V_37 = V_35 [ V_21 ] ;
V_35 [ V_21 ] = V_35 [ V_36 ] ;
V_35 [ V_36 ] = V_37 ;
}
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ ) {
for ( V_21 = V_35 [ V_15 ] . V_32 + V_35 [ V_15 ] . V_23 - 1 ; V_21 > V_35 [ V_15 ] . V_32 ; V_21 -- ) {
T_1 V_37 ;
if ( F_19 ( V_33 [ V_21 ] ) )
continue;
V_36 = F_13 ( V_34 ) % ( V_21 + 1 ) ;
if ( F_19 ( V_33 [ V_36 ] ) )
continue;
V_37 = V_33 [ V_21 ] ;
V_33 [ V_21 ] = V_33 [ V_36 ] ;
V_33 [ V_36 ] = V_37 ;
}
}
}
static void F_20 ( T_1 * V_33 , unsigned long V_23 , T_3 * V_34 )
{
unsigned long V_21 , V_36 ;
for ( V_21 = V_23 - 1 ; V_21 > 0 ; V_21 -- ) {
T_1 V_37 ;
V_36 = F_13 ( V_34 ) % ( V_21 + 1 ) ;
V_37 = V_33 [ V_21 ] ;
V_33 [ V_21 ] = V_33 [ V_36 ] ;
V_33 [ V_36 ] = V_37 ;
}
}
static void F_21 ( T_4 type , T_1 * V_33 , unsigned long V_23 )
{
unsigned long V_21 ;
T_2 V_20 [ 4 ] ;
T_3 V_34 ;
const unsigned char * V_38 ;
if ( V_23 == 0 )
return;
F_6 ( F_4 ( type ) == V_14 ) ;
V_38 = F_22 ( type ) ;
#ifdef F_23
fprintf ( V_39 , L_6 , ( const char * ) V_38 , type ) ;
#ifdef F_24
F_25 ( ( T_1 ) type ) ;
#endif
#endif
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ ) {
V_20 [ V_21 ] = V_40 [ V_21 ] ;
V_20 [ V_21 ] ^= F_2 ( V_38 ) ;
}
F_15 ( & V_34 , ( T_2 * ) & V_20 ) ;
if ( V_41 )
F_18 ( V_33 , V_23 , & V_34 ) ;
else
F_20 ( V_33 , V_23 , & V_34 ) ;
}
static bool F_26 ( T_4 V_42 )
{
T_4 V_43 ;
T_4 V_44 ;
T_4 V_45 ;
T_4 V_46 ;
V_43 = F_7 ( V_42 ) ;
V_44 = F_27 ( V_43 ) ;
if ( F_4 ( V_43 ) != V_47 )
return false ;
V_45 = F_7 ( V_43 ) ;
V_46 = F_27 ( V_45 ) ;
if ( V_44 == V_10 && F_28 ( V_43 ) != V_10 &&
F_29 ( F_28 ( V_43 ) ) == V_10 )
return true ;
if ( V_44 != V_10 &&
( F_30 ( V_44 ) && ( ! F_31 ( V_44 ) ||
F_31 ( V_44 ) == F_31 ( V_46 ) ) ) )
return true ;
return false ;
}
static int F_32 ( T_1 type )
{
unsigned long V_48 = ( unsigned long ) F_33 ( F_34 ( type ) ) ;
unsigned long V_49 = V_48 ;
T_1 V_42 ;
T_1 V_33 [ V_48 ] ;
unsigned long V_21 ;
T_1 V_50 ;
T_1 V_51 ;
T_1 V_52 ;
T_5 V_53 ;
bool V_54 = false ;
if ( F_34 ( type ) == V_10 )
return 0 ;
if ( V_48 < 2 )
return 0 ;
F_6 ( F_4 ( type ) == V_14 ) ;
F_6 ( V_48 < V_30 ) ;
if ( F_8 ( L_7 , F_10 ( type ) ) ||
F_8 ( L_8 , F_10 ( F_35 ( type ) ) ) )
return 0 ;
if ( ! strcmp ( ( const char * ) F_22 ( type ) , L_9 ) ||
! strcmp ( ( const char * ) F_22 ( type ) , L_10 ) )
return 0 ;
V_53 = F_36 ( F_37 ( F_34 ( type ) ) ) ;
if ( strstr ( V_53 . V_55 , L_11 ) )
error ( F_38 ( L_12 ) , F_22 ( type ) ) ;
for ( V_42 = F_34 ( type ) , V_21 = 0 ; V_42 ; V_42 = F_39 ( V_42 ) , V_21 ++ ) {
F_6 ( F_4 ( V_42 ) == V_56 ) ;
V_33 [ V_21 ] = V_42 ;
}
if ( F_26 ( V_33 [ V_48 - 1 ] ) ) {
V_54 = true ;
V_49 -- ;
}
F_21 ( type , ( T_1 * ) V_33 , V_49 ) ;
V_50 = F_40 ( V_56 ) ;
F_39 ( V_50 ) = V_33 [ 0 ] ;
F_7 ( V_50 ) = V_57 ;
F_41 ( V_50 ) = V_58 ;
F_42 ( V_50 ) = 1 ;
F_43 ( V_50 ) = V_58 ;
F_44 ( V_50 ) = V_59 ;
F_45 ( V_50 ) = V_59 ;
F_46 ( V_50 ) = type ;
F_47 ( V_50 ) = 1 ;
for ( V_21 = 0 ; V_21 < V_48 - 1 ; V_21 ++ )
F_39 ( V_33 [ V_21 ] ) = V_33 [ V_21 + 1 ] ;
F_39 ( V_33 [ V_48 - 1 ] ) = V_10 ;
V_52 = F_35 ( type ) ;
for ( V_51 = V_52 ; V_51 ; V_51 = F_48 ( V_51 ) ) {
F_34 ( V_51 ) = V_50 ;
F_10 ( V_51 ) = F_49 ( F_10 ( V_51 ) ) ;
F_10 ( V_51 ) = F_50 ( F_51 ( L_7 ) , V_10 , F_10 ( V_51 ) ) ;
F_10 ( V_51 ) = F_50 ( F_51 ( L_13 ) , V_10 , F_10 ( V_51 ) ) ;
if ( V_54 )
F_10 ( type ) = F_50 ( F_51 ( L_14 ) , V_10 , F_10 ( type ) ) ;
}
F_27 ( V_52 ) = V_10 ;
F_52 ( V_52 ) ;
F_6 ( F_27 ( V_52 ) != V_10 ) ;
return 1 ;
}
static T_4 F_53 ( T_4 V_42 )
{
return F_54 ( F_7 ( V_42 ) ) ;
}
static bool F_55 ( T_4 V_43 )
{
if ( F_4 ( V_43 ) != V_60 )
return false ;
return F_4 ( F_7 ( V_43 ) ) == V_61 ;
}
static int F_56 ( T_4 V_6 )
{
T_4 V_42 ;
F_6 ( F_4 ( V_6 ) == V_14 || F_4 ( V_6 ) == V_62 ) ;
for ( V_42 = F_34 ( V_6 ) ; V_42 ; V_42 = F_39 ( V_42 ) ) {
T_4 V_43 = F_53 ( V_42 ) ;
enum V_63 V_64 = F_4 ( V_43 ) ;
if ( V_6 == V_43 )
continue;
if ( ! F_55 ( V_43 ) )
return 0 ;
if ( V_64 != V_14 && V_64 != V_62 )
continue;
if ( ! F_56 ( V_43 ) )
return 0 ;
}
return 1 ;
}
static void F_57 ( T_1 type )
{
T_1 V_51 ;
F_6 ( F_4 ( type ) == V_14 ) ;
if ( F_8 ( L_15 , F_10 ( type ) ) )
return;
if ( F_8 ( L_16 , F_10 ( F_35 ( type ) ) ) || F_56 ( type ) )
F_32 ( type ) ;
for ( V_51 = F_35 ( type ) ; V_51 ; V_51 = F_48 ( V_51 ) ) {
F_10 ( type ) = F_49 ( F_10 ( type ) ) ;
F_10 ( type ) = F_50 ( F_51 ( L_15 ) , V_10 , F_10 ( type ) ) ;
}
#ifdef F_23
fprintf ( V_39 , L_17 , F_22 ( type ) ) ;
#ifdef F_24
F_25 ( type ) ;
#endif
#endif
}
static void F_58 ( T_1 V_65 )
{
T_1 V_66 , V_67 , V_42 , V_68 , type , V_69 ;
unsigned T_6 V_5 ;
type = F_7 ( V_65 ) ;
if ( ! F_8 ( L_14 , F_10 ( type ) ) )
return;
V_68 = F_59 ( V_65 ) ;
if ( V_68 == V_10 || V_68 == V_70 )
return;
if ( F_4 ( V_68 ) != V_71 )
return;
V_5 = F_60 ( V_68 ) ;
if ( ! V_5 )
return;
V_66 = F_61 ( V_68 , F_60 ( V_68 ) - 1 ) -> V_72 ;
V_67 = F_61 ( V_68 , F_60 ( V_68 ) - 1 ) -> V_73 ;
for ( V_42 = F_34 ( F_7 ( V_65 ) ) ; F_39 ( V_42 ) ; V_42 = F_39 ( V_42 ) )
;
if ( V_67 != V_42 )
return;
if ( F_4 ( V_66 ) != V_74 ) {
error ( L_18
L_19 ) ;
return;
}
V_69 = F_62 ( F_63 ( V_66 ) *
F_31 ( F_27 ( F_7 ( F_7 ( V_66 ) ) ) ) ) ;
F_41 ( V_65 ) = F_64 ( V_75 , F_27 ( type ) , V_69 ) ;
return;
}
static void F_65 ( void * V_76 , void * V_77 )
{
T_1 V_65 = ( T_1 ) V_76 ;
T_1 type ;
if ( V_65 == V_10 || V_65 == V_70 )
return;
type = F_7 ( V_65 ) ;
if ( F_4 ( V_65 ) != V_12 )
return;
if ( F_4 ( type ) != V_14 && F_4 ( type ) != V_62 )
return;
if ( ! F_8 ( L_7 , F_10 ( type ) ) )
return;
F_41 ( V_65 ) = 0 ;
F_44 ( V_65 ) = 0 ;
F_66 ( V_65 , 0 ) ;
F_67 ( V_65 , V_78 ) ;
F_68 ( V_65 , 0 ) ;
F_58 ( V_65 ) ;
F_69 ( V_65 , 0 ) ;
}
static void F_70 ( void * V_76 , void * V_77 )
{
T_1 type = ( T_1 ) V_76 ;
if ( type == V_10 || type == V_70 )
return;
if ( F_4 ( type ) != V_14 )
return;
if ( F_34 ( type ) == V_10 )
return;
if ( F_8 ( L_15 , F_10 ( type ) ) )
return;
#ifdef F_23
fprintf ( V_39 , L_20 , F_22 ( type ) ) ;
#endif
#ifdef F_24
F_25 ( type ) ;
#endif
F_57 ( type ) ;
return;
}
static void F_71 ( void * V_76 , void * V_77 )
{
F_72 ( & V_79 ) ;
F_72 ( & V_80 ) ;
F_72 ( & V_81 ) ;
F_72 ( & V_82 ) ;
}
static void F_73 ( T_1 V_83 , T_1 V_68 )
{
unsigned T_6 V_84 ;
T_1 V_42 , V_85 ;
T_1 V_86 , V_87 ;
F_74 (CONSTRUCTOR_ELTS(init), idx, field, val) {
if ( F_4 ( V_85 ) == V_71 ) {
F_73 ( V_83 , V_85 ) ;
continue;
}
if ( V_42 == V_10 )
continue;
V_86 = F_7 ( V_42 ) ;
V_87 = F_7 ( V_85 ) ;
if ( F_4 ( V_86 ) != V_60 || F_4 ( V_87 ) != V_60 )
continue;
if ( V_86 == V_87 )
continue;
V_86 = F_35 ( F_54 ( F_35 ( F_7 ( V_86 ) ) ) ) ;
V_87 = F_35 ( F_54 ( F_35 ( F_7 ( V_87 ) ) ) ) ;
if ( V_86 == V_57 )
continue;
if ( V_86 == V_87 )
continue;
if ( F_4 ( V_87 ) != V_14 )
continue;
if ( ! F_8 ( L_7 , F_10 ( V_87 ) ) )
continue;
F_75 ( F_37 ( V_83 ) , L_21 , F_35 ( V_86 ) , F_35 ( V_87 ) ) ;
}
}
static void F_76 ( void * V_76 , void * V_77 )
{
struct V_88 * V_6 ;
T_1 V_68 ;
F_77 (node) {
T_1 V_83 = F_78 ( V_6 ) ;
V_68 = F_59 ( V_83 ) ;
if ( V_68 == V_10 )
continue;
if ( F_4 ( V_68 ) != V_71 )
continue;
F_73 ( V_83 , V_68 ) ;
}
}
static bool F_79 ( T_4 V_89 , T_7 V_90 )
{
T_7 V_91 ;
T_8 V_92 ;
T_8 V_93 ;
T_4 V_94 ;
T_4 V_95 ;
T_4 V_96 ;
T_4 V_97 ;
V_91 = F_80 ( V_98 , V_90 ) ;
if ( ! V_91 )
return false ;
V_92 = F_81 ( V_91 ) ;
if ( ! V_92 )
return false ;
if ( F_82 ( V_92 ) != V_99 )
return false ;
if ( F_83 ( V_92 ) != V_100 )
return false ;
if ( ! F_84 ( F_85 ( V_92 ) ) )
return false ;
V_95 = F_86 ( V_92 ) ;
if ( F_4 ( V_95 ) != V_101 )
return false ;
V_93 = F_87 ( V_95 ) ;
if ( F_82 ( V_93 ) != V_102 )
return false ;
V_94 = F_88 ( V_93 ) ;
V_96 = F_89 ( V_93 ) ;
if ( ! V_96 )
return false ;
if ( V_94 != V_95 )
return false ;
if ( strcmp ( F_90 ( V_96 ) , L_22 ) )
return false ;
V_97 = F_91 ( V_93 , 0 ) ;
if ( ! V_97 )
return false ;
if ( V_97 != V_89 )
return false ;
return true ;
}
static void F_92 ( void )
{
T_1 V_83 ;
unsigned int V_21 ;
F_93 (cfun, i, var) {
T_1 V_68 = F_59 ( V_83 ) ;
if ( ! V_68 )
continue;
if ( F_4 ( V_68 ) != V_71 )
continue;
F_73 ( V_83 , V_68 ) ;
}
}
static bool F_94 ( T_8 V_103 , T_4 V_104 , const char * V_105 )
{
const char * V_106 ;
if ( V_104 == V_10 )
return false ;
switch ( F_4 ( V_104 ) ) {
case V_14 :
V_106 = F_95 ( V_104 ) ;
break;
case V_107 :
if ( F_96 ( V_104 ) == V_108 )
V_106 = L_23 ;
else {
F_97 ( F_98 ( V_103 ) , L_24 , V_104 ) ;
F_25 ( V_104 ) ;
return false ;
}
break;
case V_60 :
if ( F_4 ( F_7 ( V_104 ) ) == V_109 ) {
V_106 = L_25 ;
break;
} else {
F_97 ( F_98 ( V_103 ) , L_26 , V_104 ) ;
F_25 ( V_104 ) ;
return false ;
}
default:
F_97 ( F_98 ( V_103 ) , L_27 , V_104 ) ;
F_25 ( V_104 ) ;
return false ;
}
return strcmp ( V_106 , V_105 ) == 0 ;
}
static bool F_99 ( T_8 V_103 , T_4 V_110 , T_4 V_111 )
{
const struct V_112 * V_113 ;
T_5 V_53 = F_36 ( F_98 ( V_103 ) ) ;
for ( V_113 = V_114 ; V_113 -> V_115 ; V_113 ++ ) {
if ( ! strstr ( V_53 . V_55 , V_113 -> V_115 ) )
continue;
if ( F_94 ( V_103 , V_110 , V_113 -> V_116 ) && F_94 ( V_103 , V_111 , V_113 -> V_89 ) )
return true ;
}
return false ;
}
static unsigned int F_100 ( void )
{
T_7 V_90 ;
F_92 () ;
F_101 (bb, cfun) {
T_9 V_117 ;
for ( V_117 = F_102 ( V_90 ) ; ! F_103 ( V_117 ) ; F_104 ( & V_117 ) ) {
T_8 V_103 ;
T_4 V_116 ;
T_4 V_118 ;
T_4 V_119 ;
T_4 V_120 ;
T_4 V_121 ;
T_4 V_122 ;
T_4 V_123 ;
T_4 V_124 ;
enum V_63 V_125 ;
V_103 = F_105 ( V_117 ) ;
#ifdef F_23
#ifdef F_24
F_106 ( V_103 ) ;
F_25 ( F_88 ( V_103 ) ) ;
#endif
#endif
if ( F_82 ( V_103 ) != V_126 )
continue;
#ifdef F_23
#ifdef F_24
F_25 ( F_107 ( V_103 ) ) ;
#endif
#endif
V_125 = F_108 ( V_103 ) ;
if ( V_125 != V_127 && V_125 != V_101 )
continue;
V_116 = F_88 ( V_103 ) ;
V_118 = F_7 ( V_116 ) ;
V_119 = F_107 ( V_103 ) ;
V_120 = F_7 ( V_119 ) ;
if ( F_4 ( V_120 ) != V_60 ||
F_4 ( V_118 ) != V_60 )
continue;
V_121 = F_35 ( F_54 ( F_35 ( F_7 ( V_118 ) ) ) ) ;
V_122 = F_35 ( F_54 ( F_35 ( F_7 ( V_120 ) ) ) ) ;
if ( V_122 == V_57 )
continue;
if ( V_121 == V_57 )
continue;
if ( F_79 ( V_119 , V_90 ) )
continue;
if ( F_4 ( V_122 ) != V_14 ) {
#ifndef F_23
if ( F_8 ( L_7 , F_10 ( V_121 ) ) )
#endif
{
if ( ! F_99 ( V_103 , V_121 , V_122 ) )
F_75 ( F_98 ( V_103 ) , L_28 , V_121 , V_122 ) ;
}
continue;
}
if ( V_125 == V_101 && V_121 == V_122 )
continue;
if ( V_125 == V_127 ) {
V_123 = F_109 ( V_119 , 0 ) ;
if ( V_123 == V_10 )
continue;
if ( F_4 ( V_123 ) != V_12 )
continue;
V_124 = F_35 ( F_54 ( F_35 ( F_7 ( V_123 ) ) ) ) ;
if ( V_124 == V_121 )
continue;
#ifndef F_23
if ( F_8 ( L_7 , F_10 ( V_124 ) ) )
#endif
{
if ( ! F_99 ( V_103 , V_121 , V_124 ) )
F_75 ( F_98 ( V_103 ) , L_29 , V_121 , V_124 ) ;
}
} else {
T_4 V_128 = F_110 ( V_119 ) ;
if ( V_128 != V_10 && F_111 ( V_128 ) &&
! strcmp ( ( const char * ) F_90 ( V_128 ) , L_30 ) )
continue;
#ifndef F_23
if ( F_8 ( L_7 , F_10 ( V_122 ) ) )
#endif
{
if ( ! F_99 ( V_103 , V_121 , V_122 ) )
F_75 ( F_98 ( V_103 ) , L_31 , V_121 , V_122 ) ;
}
}
}
}
return 0 ;
}
T_10 int F_112 ( struct V_129 * V_130 , struct V_131 * V_132 )
{
int V_21 ;
const char * const V_133 = V_130 -> V_134 ;
const int V_135 = V_130 -> V_135 ;
const struct V_136 * const V_137 = V_130 -> V_137 ;
bool V_138 = true ;
int V_139 = 0 ;
struct V_140 V_141 ;
V_141 . V_142 = F_113 () ;
V_141 . V_143 = L_31 ;
V_141 . V_144 = 1 ;
V_141 . V_145 = V_146 ;
if ( ! F_114 ( V_132 , & V_147 ) ) {
error ( F_38 ( L_32 ) ) ;
return 1 ;
}
if ( strncmp ( V_148 . V_3 , L_33 , 5 ) && ! strncmp ( V_148 . V_3 , L_34 , 6 ) ) {
F_115 ( V_149 , F_38 ( L_35 ) , V_133 , V_148 . V_3 ) ;
V_138 = false ;
}
for ( V_21 = 0 ; V_21 < V_135 ; ++ V_21 ) {
if ( ! strcmp ( V_137 [ V_21 ] . V_150 , L_36 ) ) {
V_138 = false ;
continue;
}
if ( ! strcmp ( V_137 [ V_21 ] . V_150 , L_37 ) ) {
V_41 = 1 ;
continue;
}
error ( F_38 ( L_38 ) , V_133 , V_137 [ V_21 ] . V_150 ) ;
}
if ( strlen ( V_151 ) != 64 ) {
error ( F_38 ( L_39 ) , V_133 ) ;
return 1 ;
}
V_139 = sscanf ( V_151 , L_40 ,
& V_40 [ 0 ] , & V_40 [ 1 ] , & V_40 [ 2 ] , & V_40 [ 3 ] ) ;
if ( V_139 != 4 ) {
error ( F_38 ( L_41 ) , V_133 ) ;
return 1 ;
}
F_116 ( V_133 , V_152 , NULL , & V_153 ) ;
if ( V_138 ) {
F_116 ( V_133 , V_154 , F_76 , NULL ) ;
F_116 ( V_133 , V_155 , NULL , & V_141 ) ;
F_116 ( V_133 , V_156 , F_70 , NULL ) ;
F_116 ( V_133 , V_157 , F_65 , NULL ) ;
}
F_116 ( V_133 , V_158 , F_71 , NULL ) ;
return 0 ;
}
