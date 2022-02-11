int F_1 ( struct V_1 * V_2 , int V_3 , int type )
{
const unsigned char * V_4 = F_2 ( V_2 ) ;
int V_5 = V_2 -> V_6 - V_2 -> V_7 ;
struct V_8 * V_9 ;
int V_10 ;
if ( V_3 + 2 > V_5 )
goto V_11;
V_9 = (struct V_8 * ) ( V_4 + V_3 ) ;
V_10 = ( ( V_9 -> V_12 + 1 ) << 3 ) ;
if ( V_3 + V_10 > V_5 )
goto V_11;
V_3 += 2 ;
V_10 -= 2 ;
while ( V_10 > 0 ) {
int V_13 = V_4 [ V_3 ] ;
int V_14 ;
if ( V_13 == type )
return V_3 ;
switch ( V_13 ) {
case V_15 :
V_14 = 1 ;
break;
default:
V_14 = V_4 [ V_3 + 1 ] + 2 ;
if ( V_14 > V_10 )
goto V_11;
break;
}
V_3 += V_14 ;
V_10 -= V_14 ;
}
V_11:
return - 1 ;
}
static bool F_3 ( struct V_1 * V_2 , int V_16 )
{
switch ( ( F_2 ( V_2 ) [ V_16 ] & 0xC0 ) >> 6 ) {
case 0 :
return true ;
case 1 :
break;
case 3 :
if ( F_4 ( & F_5 ( V_2 ) -> V_17 ) )
break;
case 2 :
F_6 ( V_2 , V_18 , V_16 ) ;
return false ;
}
F_7 ( V_2 ) ;
return false ;
}
static bool F_8 ( const struct V_19 * V_20 , struct V_1 * V_2 )
{
const struct V_19 * V_21 ;
const unsigned char * V_4 = F_2 ( V_2 ) ;
int V_22 = F_9 ( V_2 ) ;
int V_10 = ( F_10 ( V_2 ) [ 1 ] + 1 ) << 3 ;
int V_23 = 0 ;
if ( F_11 ( V_2 ) + V_10 > F_12 ( V_2 ) )
goto V_11;
V_22 += 2 ;
V_10 -= 2 ;
while ( V_10 > 0 ) {
int V_14 = V_4 [ V_22 + 1 ] + 2 ;
int V_24 ;
switch ( V_4 [ V_22 ] ) {
case V_15 :
V_14 = 1 ;
V_23 ++ ;
if ( V_23 > 7 )
goto V_11;
break;
case V_25 :
V_23 += V_14 ;
if ( V_23 > 7 )
goto V_11;
for ( V_24 = 2 ; V_24 < V_14 ; V_24 ++ ) {
if ( V_4 [ V_22 + V_24 ] != 0 )
goto V_11;
}
break;
default:
if ( V_14 > V_10 )
goto V_11;
for ( V_21 = V_20 ; V_21 -> type >= 0 ; V_21 ++ ) {
if ( V_21 -> type == V_4 [ V_22 ] ) {
if ( V_21 -> V_26 ( V_2 , V_22 ) == false )
return false ;
break;
}
}
if ( V_21 -> type < 0 ) {
if ( F_3 ( V_2 , V_22 ) == 0 )
return false ;
}
V_23 = 0 ;
break;
}
V_22 += V_14 ;
V_10 -= V_14 ;
}
if ( ( V_23 == 6 ) && ( ( V_22 - F_9 ( V_2 ) ) == 8 ) )
goto V_11;
if ( V_10 == 0 )
return true ;
V_11:
F_7 ( V_2 ) ;
return false ;
}
static bool F_13 ( struct V_1 * V_2 , int V_16 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 = F_14 ( V_2 ) ;
struct V_31 * V_32 = F_5 ( V_2 ) ;
struct V_33 V_34 ;
int V_35 ;
if ( V_30 -> V_36 ) {
F_15 ( V_37 L_1 ) ;
goto V_38;
}
V_30 -> V_36 = V_30 -> V_39 ;
V_30 -> V_39 = 0 ;
V_28 = (struct V_27 * ) ( F_2 ( V_2 ) + V_16 ) ;
if ( V_28 -> V_40 != 16 ) {
F_15 (
V_37 L_2 , V_28 -> V_40 ) ;
goto V_38;
}
if ( ! ( F_16 ( & V_28 -> V_41 ) & V_42 ) ) {
F_15 (
V_37 L_3 , & V_28 -> V_41 ) ;
goto V_38;
}
V_35 = F_17 ( V_2 , ( V_43 * ) & V_32 -> V_17 ,
( V_43 * ) & V_28 -> V_41 , V_44 ) ;
if ( F_18 ( V_35 < 0 ) )
goto V_38;
if ( F_19 ( V_2 ) ) {
if ( F_20 ( V_2 , 0 , 0 , V_45 ) )
goto V_38;
V_28 = (struct V_27 * ) ( F_2 ( V_2 ) +
V_16 ) ;
V_32 = F_5 ( V_2 ) ;
}
if ( V_2 -> V_46 == V_47 )
V_2 -> V_46 = V_48 ;
V_34 = V_32 -> V_49 ;
V_32 -> V_49 = V_28 -> V_41 ;
V_28 -> V_41 = V_34 ;
if ( V_2 -> V_50 . V_51 == 0 )
F_21 ( V_2 ) ;
return true ;
V_38:
F_7 ( V_2 ) ;
return false ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_14 ( V_2 ) ;
#if F_23 ( V_52 ) || F_23 ( V_53 )
T_1 V_54 ;
#endif
struct V_55 * V_56 = F_24 ( V_2 ) ;
if ( ! F_25 ( V_2 , F_11 ( V_2 ) + 8 ) ||
! F_25 ( V_2 , ( F_11 ( V_2 ) +
( ( F_10 ( V_2 ) [ 1 ] + 1 ) << 3 ) ) ) ) {
F_26 ( F_27 ( V_56 -> V_57 ) , F_28 ( V_56 ) ,
V_58 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
V_30 -> V_59 = V_30 -> V_39 = F_9 ( V_2 ) ;
#if F_23 ( V_52 ) || F_23 ( V_53 )
V_54 = V_30 -> V_39 ;
#endif
if ( F_8 ( V_60 , V_2 ) ) {
V_2 -> V_61 += ( F_10 ( V_2 ) [ 1 ] + 1 ) << 3 ;
V_30 = F_14 ( V_2 ) ;
#if F_23 ( V_52 ) || F_23 ( V_53 )
V_30 -> V_62 = V_54 ;
#else
V_30 -> V_62 = V_30 -> V_39 ;
#endif
return 1 ;
}
F_26 ( F_27 ( V_56 -> V_57 ) ,
F_28 ( V_56 ) , V_58 ) ;
return - 1 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_14 ( V_2 ) ;
struct V_33 * V_41 = NULL ;
struct V_33 V_17 ;
struct V_63 * V_64 ;
int V_65 , V_24 ;
struct V_66 * V_9 ;
struct V_67 * V_68 ;
struct V_69 * V_69 = F_27 ( V_2 -> V_57 ) ;
int V_70 = V_69 -> V_71 . V_72 -> V_70 ;
V_64 = F_30 ( V_2 -> V_57 ) ;
if ( V_64 && V_70 > V_64 -> V_73 . V_70 )
V_70 = V_64 -> V_73 . V_70 ;
if ( ! F_25 ( V_2 , F_11 ( V_2 ) + 8 ) ||
! F_25 ( V_2 , ( F_11 ( V_2 ) +
( ( F_10 ( V_2 ) [ 1 ] + 1 ) << 3 ) ) ) ) {
F_26 ( V_69 , F_28 ( F_24 ( V_2 ) ) ,
V_58 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
V_9 = (struct V_66 * ) F_10 ( V_2 ) ;
if ( F_4 ( & F_5 ( V_2 ) -> V_17 ) ||
V_2 -> V_74 != V_75 ) {
F_26 ( V_69 , F_28 ( F_24 ( V_2 ) ) ,
V_76 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
V_77:
if ( V_9 -> V_78 == 0 ) {
switch ( V_9 -> type ) {
#if F_23 ( V_52 ) || F_23 ( V_53 )
case V_79 :
if ( ! V_41 ) {
F_26 ( V_69 , F_28 ( F_24 ( V_2 ) ) ,
V_76 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
break;
#endif
default:
break;
}
V_30 -> V_59 = V_30 -> V_80 = F_9 ( V_2 ) ;
V_2 -> V_61 += ( V_9 -> V_12 + 1 ) << 3 ;
V_30 -> V_81 = V_30 -> V_39 ;
V_30 -> V_39 = 0 ;
V_30 -> V_62 = ( & V_9 -> V_82 ) - F_2 ( V_2 ) ;
return 1 ;
}
switch ( V_9 -> type ) {
#if F_23 ( V_52 ) || F_23 ( V_53 )
case V_79 :
if ( V_70 < 0 )
goto V_83;
if ( V_9 -> V_12 != 2 || V_9 -> V_78 != 1 ) {
F_26 ( V_69 , F_28 ( F_24 ( V_2 ) ) ,
V_58 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
break;
#endif
default:
goto V_83;
}
V_65 = V_9 -> V_12 >> 1 ;
if ( V_9 -> V_78 > V_65 ) {
F_26 ( V_69 , F_28 ( F_24 ( V_2 ) ) ,
V_58 ) ;
F_6 ( V_2 , V_84 ,
( ( & V_9 -> V_78 ) -
F_2 ( V_2 ) ) ) ;
return - 1 ;
}
if ( F_19 ( V_2 ) ) {
if ( F_20 ( V_2 , 0 , 0 , V_45 ) ) {
F_26 ( V_69 , F_28 ( F_24 ( V_2 ) ) ,
V_85 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
V_9 = (struct V_66 * ) F_10 ( V_2 ) ;
}
if ( V_2 -> V_46 == V_47 )
V_2 -> V_46 = V_48 ;
V_24 = V_65 - -- V_9 -> V_78 ;
V_68 = (struct V_67 * ) V_9 ;
V_41 = V_68 -> V_41 ;
V_41 += V_24 - 1 ;
switch ( V_9 -> type ) {
#if F_23 ( V_52 ) || F_23 ( V_53 )
case V_79 :
if ( F_17 ( V_2 , ( V_43 * ) V_41 ,
( V_43 * ) & F_5 ( V_2 ) -> V_49 ,
V_86 ) < 0 ) {
F_26 ( V_69 , F_28 ( F_24 ( V_2 ) ) ,
V_76 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
if ( ! F_31 ( F_27 ( F_24 ( V_2 ) -> V_57 ) , V_41 ) ) {
F_26 ( V_69 , F_28 ( F_24 ( V_2 ) ) ,
V_76 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
break;
#endif
default:
break;
}
if ( F_4 ( V_41 ) ) {
F_26 ( V_69 , F_28 ( F_24 ( V_2 ) ) ,
V_76 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
V_17 = * V_41 ;
* V_41 = F_5 ( V_2 ) -> V_17 ;
F_5 ( V_2 ) -> V_17 = V_17 ;
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
if ( F_24 ( V_2 ) -> error ) {
F_34 ( V_2 , V_2 -> V_87 - F_2 ( V_2 ) ) ;
F_35 ( V_2 ) ;
return - 1 ;
}
if ( F_24 ( V_2 ) -> V_57 -> V_88 & V_89 ) {
if ( F_5 ( V_2 ) -> V_90 <= 1 ) {
F_26 ( V_69 , F_28 ( F_24 ( V_2 ) ) ,
V_58 ) ;
F_36 ( V_2 , V_91 , V_92 ,
0 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
F_5 ( V_2 ) -> V_90 -- ;
goto V_77;
}
F_34 ( V_2 , V_2 -> V_87 - F_2 ( V_2 ) ) ;
F_35 ( V_2 ) ;
return - 1 ;
V_83:
F_26 ( V_69 , F_28 ( F_24 ( V_2 ) ) , V_58 ) ;
F_6 ( V_2 , V_84 ,
( & V_9 -> type ) - F_2 ( V_2 ) ) ;
return - 1 ;
}
int T_2 F_37 ( void )
{
int V_35 ;
V_35 = F_38 ( & V_93 , V_86 ) ;
if ( V_35 )
goto V_94;
V_35 = F_38 ( & V_95 , V_44 ) ;
if ( V_35 )
goto V_96;
V_35 = F_38 ( & V_97 , V_98 ) ;
if ( V_35 )
goto V_99;
V_94:
return V_35 ;
V_96:
F_39 ( & V_93 , V_86 ) ;
V_99:
F_39 ( & V_95 , V_44 ) ;
goto V_94;
}
void F_40 ( void )
{
F_39 ( & V_97 , V_98 ) ;
F_39 ( & V_95 , V_44 ) ;
F_39 ( & V_93 , V_86 ) ;
}
static inline struct V_63 * F_41 ( struct V_1 * V_2 )
{
return F_24 ( V_2 ) ? F_28 ( F_24 ( V_2 ) ) : F_30 ( V_2 -> V_57 ) ;
}
static inline struct V_69 * F_42 ( struct V_1 * V_2 )
{
return F_24 ( V_2 ) ? F_27 ( F_24 ( V_2 ) -> V_57 ) : F_27 ( V_2 -> V_57 ) ;
}
static bool F_43 ( struct V_1 * V_2 , int V_16 )
{
const unsigned char * V_4 = F_2 ( V_2 ) ;
if ( V_4 [ V_16 + 1 ] == 2 ) {
F_14 ( V_2 ) -> V_100 = V_16 ;
return true ;
}
F_15 ( V_37 L_4 ,
V_4 [ V_16 + 1 ] ) ;
F_7 ( V_2 ) ;
return false ;
}
static bool F_44 ( struct V_1 * V_2 , int V_16 )
{
const unsigned char * V_4 = F_2 ( V_2 ) ;
struct V_69 * V_69 = F_42 ( V_2 ) ;
T_3 V_101 ;
if ( V_4 [ V_16 + 1 ] != 4 || ( V_16 & 3 ) != 2 ) {
F_15 ( V_37 L_5 ,
V_4 [ V_16 + 1 ] ) ;
F_26 ( V_69 , F_41 ( V_2 ) ,
V_58 ) ;
goto V_102;
}
V_101 = F_45 ( * ( V_103 * ) ( V_4 + V_16 + 2 ) ) ;
if ( V_101 <= V_104 ) {
F_26 ( V_69 , F_41 ( V_2 ) ,
V_58 ) ;
F_6 ( V_2 , V_84 , V_16 + 2 ) ;
return false ;
}
if ( F_5 ( V_2 ) -> V_105 ) {
F_26 ( V_69 , F_41 ( V_2 ) ,
V_58 ) ;
F_6 ( V_2 , V_84 , V_16 ) ;
return false ;
}
if ( V_101 > V_2 -> V_10 - sizeof( struct V_31 ) ) {
F_26 ( V_69 , F_41 ( V_2 ) ,
V_106 ) ;
goto V_102;
}
if ( F_46 ( V_2 , V_101 + sizeof( struct V_31 ) ) )
goto V_102;
return true ;
V_102:
F_7 ( V_2 ) ;
return false ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_14 ( V_2 ) ;
if ( ! F_25 ( V_2 , sizeof( struct V_31 ) + 8 ) ||
! F_25 ( V_2 , ( sizeof( struct V_31 ) +
( ( F_10 ( V_2 ) [ 1 ] + 1 ) << 3 ) ) ) ) {
F_7 ( V_2 ) ;
return - 1 ;
}
V_30 -> V_107 = sizeof( struct V_31 ) ;
if ( F_8 ( V_108 , V_2 ) ) {
V_2 -> V_61 += ( F_10 ( V_2 ) [ 1 ] + 1 ) << 3 ;
V_30 = F_14 ( V_2 ) ;
V_30 -> V_62 = sizeof( struct V_31 ) ;
return 1 ;
}
return - 1 ;
}
static void F_48 ( struct V_1 * V_2 , T_4 * V_109 ,
struct V_66 * V_30 ,
struct V_33 * * V_110 )
{
struct V_67 * V_111 , * V_112 ;
int V_113 ;
V_112 = (struct V_67 * ) V_30 ;
V_111 = (struct V_67 * ) F_34 ( V_2 , ( V_112 -> V_114 . V_12 + 1 ) << 3 ) ;
memcpy ( V_111 , V_112 , sizeof( struct V_67 ) ) ;
V_113 = V_112 -> V_114 . V_12 >> 1 ;
if ( V_113 > 1 )
memcpy ( V_111 -> V_41 , V_112 -> V_41 + 1 ,
( V_113 - 1 ) * sizeof( struct V_33 ) ) ;
V_111 -> V_41 [ V_113 - 1 ] = * * V_110 ;
* V_110 = V_112 -> V_41 ;
V_111 -> V_114 . V_82 = * V_109 ;
* V_109 = V_115 ;
}
static void F_49 ( struct V_1 * V_2 , T_4 * V_109 , T_4 type , struct V_8 * V_30 )
{
struct V_8 * V_116 = (struct V_8 * ) F_34 ( V_2 , F_50 ( V_30 ) ) ;
memcpy ( V_116 , V_30 , F_50 ( V_30 ) ) ;
V_116 -> V_82 = * V_109 ;
* V_109 = type ;
}
void F_51 ( struct V_1 * V_2 , struct V_117 * V_30 ,
T_4 * V_109 ,
struct V_33 * * V_17 )
{
if ( V_30 -> V_80 ) {
F_48 ( V_2 , V_109 , V_30 -> V_80 , V_17 ) ;
if ( V_30 -> V_118 )
F_49 ( V_2 , V_109 , V_119 , V_30 -> V_118 ) ;
}
if ( V_30 -> V_120 )
F_49 ( V_2 , V_109 , V_121 , V_30 -> V_120 ) ;
}
void F_52 ( struct V_1 * V_2 , struct V_117 * V_30 , T_4 * V_109 )
{
if ( V_30 -> V_122 )
F_49 ( V_2 , V_109 , V_119 , V_30 -> V_122 ) ;
}
struct V_117 *
F_53 ( struct V_123 * V_124 , struct V_117 * V_30 )
{
struct V_117 * V_125 ;
V_125 = F_54 ( V_124 , V_30 -> V_126 , V_45 ) ;
if ( V_125 ) {
long V_127 = ( char * ) V_125 - ( char * ) V_30 ;
memcpy ( V_125 , V_30 , V_30 -> V_126 ) ;
if ( V_125 -> V_120 )
* ( ( char * * ) & V_125 -> V_120 ) += V_127 ;
if ( V_125 -> V_118 )
* ( ( char * * ) & V_125 -> V_118 ) += V_127 ;
if ( V_125 -> V_122 )
* ( ( char * * ) & V_125 -> V_122 ) += V_127 ;
if ( V_125 -> V_80 )
* ( ( char * * ) & V_125 -> V_80 ) += V_127 ;
}
return V_125 ;
}
static int F_55 ( void * V_128 ,
struct V_8 T_5 * V_129 , int V_130 ,
int V_131 ,
struct V_8 * * V_9 ,
char * * V_132 )
{
if ( V_131 ) {
if ( V_128 ) {
memcpy ( * V_132 , V_128 , F_50 ( (struct V_8 * ) V_128 ) ) ;
* V_9 = (struct V_8 * ) * V_132 ;
* V_132 += F_56 ( F_50 ( * V_9 ) ) ;
}
} else {
if ( V_129 ) {
if ( F_57 ( * V_132 , V_129 , V_130 ) )
return - V_133 ;
* V_9 = (struct V_8 * ) * V_132 ;
if ( F_50 ( * V_9 ) > V_130 )
return - V_134 ;
* V_132 += F_56 ( V_130 ) ;
}
}
return 0 ;
}
struct V_117 *
F_58 ( struct V_123 * V_124 , struct V_117 * V_30 ,
int V_135 ,
struct V_8 T_5 * V_129 , int V_130 )
{
int V_126 = 0 ;
char * V_132 ;
struct V_117 * V_125 ;
int V_136 ;
if ( V_30 ) {
if ( V_135 != V_137 && V_30 -> V_120 )
V_126 += F_56 ( F_50 ( V_30 -> V_120 ) ) ;
if ( V_135 != V_138 && V_30 -> V_118 )
V_126 += F_56 ( F_50 ( V_30 -> V_118 ) ) ;
if ( V_135 != V_139 && V_30 -> V_80 )
V_126 += F_56 ( F_50 ( V_30 -> V_80 ) ) ;
if ( V_135 != V_140 && V_30 -> V_122 )
V_126 += F_56 ( F_50 ( V_30 -> V_122 ) ) ;
}
if ( V_129 && V_130 )
V_126 += F_56 ( V_130 ) ;
if ( ! V_126 )
return NULL ;
V_126 += sizeof( * V_125 ) ;
V_125 = F_54 ( V_124 , V_126 , V_45 ) ;
if ( ! V_125 )
return F_59 ( - V_141 ) ;
memset ( V_125 , 0 , V_126 ) ;
V_125 -> V_126 = V_126 ;
V_132 = ( char * ) ( V_125 + 1 ) ;
V_136 = F_55 ( V_30 ? V_30 -> V_120 : NULL , V_129 , V_130 ,
V_135 != V_137 ,
& V_125 -> V_120 , & V_132 ) ;
if ( V_136 )
goto V_94;
V_136 = F_55 ( V_30 ? V_30 -> V_118 : NULL , V_129 , V_130 ,
V_135 != V_138 ,
& V_125 -> V_118 , & V_132 ) ;
if ( V_136 )
goto V_94;
V_136 = F_55 ( V_30 ? V_30 -> V_80 : NULL , V_129 , V_130 ,
V_135 != V_139 ,
(struct V_8 * * ) & V_125 -> V_80 , & V_132 ) ;
if ( V_136 )
goto V_94;
V_136 = F_55 ( V_30 ? V_30 -> V_122 : NULL , V_129 , V_130 ,
V_135 != V_140 ,
& V_125 -> V_122 , & V_132 ) ;
if ( V_136 )
goto V_94;
V_125 -> V_142 = ( V_125 -> V_120 ? F_50 ( V_125 -> V_120 ) : 0 ) +
( V_125 -> V_118 ? F_50 ( V_125 -> V_118 ) : 0 ) +
( V_125 -> V_80 ? F_50 ( V_125 -> V_80 ) : 0 ) ;
V_125 -> V_143 = ( V_125 -> V_122 ? F_50 ( V_125 -> V_122 ) : 0 ) ;
return V_125 ;
V_94:
F_60 ( V_124 , V_125 , V_125 -> V_126 ) ;
return F_59 ( V_136 ) ;
}
struct V_117 * F_61 ( struct V_117 * V_144 ,
struct V_117 * V_30 )
{
if ( V_30 && V_30 -> V_118 && ! V_30 -> V_80 ) {
if ( V_144 != V_30 ) {
memcpy ( V_144 , V_30 , sizeof( * V_144 ) ) ;
V_30 = V_144 ;
}
V_30 -> V_142 -= F_50 ( V_30 -> V_118 ) ;
V_30 -> V_118 = NULL ;
}
return V_30 ;
}
struct V_33 * F_62 ( struct V_145 * V_146 ,
const struct V_117 * V_30 ,
struct V_33 * V_147 )
{
if ( ! V_30 || ! V_30 -> V_80 )
return NULL ;
* V_147 = V_146 -> V_17 ;
V_146 -> V_17 = * ( (struct V_67 * ) V_30 -> V_80 ) -> V_41 ;
return V_147 ;
}
