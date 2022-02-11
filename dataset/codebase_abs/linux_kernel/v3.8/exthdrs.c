static bool F_1 ( struct V_1 * V_2 , int V_3 )
{
switch ( ( F_2 ( V_2 ) [ V_3 ] & 0xC0 ) >> 6 ) {
case 0 :
return true ;
case 1 :
break;
case 3 :
if ( F_3 ( & F_4 ( V_2 ) -> V_4 ) )
break;
case 2 :
F_5 ( V_2 , V_5 , V_3 ) ;
return false ;
}
F_6 ( V_2 ) ;
return false ;
}
static bool F_7 ( const struct V_6 * V_7 , struct V_1 * V_2 )
{
const struct V_6 * V_8 ;
const unsigned char * V_9 = F_2 ( V_2 ) ;
int V_10 = F_8 ( V_2 ) ;
int V_11 = ( F_9 ( V_2 ) [ 1 ] + 1 ) << 3 ;
int V_12 = 0 ;
if ( F_10 ( V_2 ) + V_11 > F_11 ( V_2 ) )
goto V_13;
V_10 += 2 ;
V_11 -= 2 ;
while ( V_11 > 0 ) {
int V_14 = V_9 [ V_10 + 1 ] + 2 ;
int V_15 ;
switch ( V_9 [ V_10 ] ) {
case V_16 :
V_14 = 1 ;
V_12 ++ ;
if ( V_12 > 7 )
goto V_13;
break;
case V_17 :
V_12 += V_14 ;
if ( V_12 > 7 )
goto V_13;
for ( V_15 = 2 ; V_15 < V_14 ; V_15 ++ ) {
if ( V_9 [ V_10 + V_15 ] != 0 )
goto V_13;
}
break;
default:
if ( V_14 > V_11 )
goto V_13;
for ( V_8 = V_7 ; V_8 -> type >= 0 ; V_8 ++ ) {
if ( V_8 -> type == V_9 [ V_10 ] ) {
if ( V_8 -> V_18 ( V_2 , V_10 ) == false )
return false ;
break;
}
}
if ( V_8 -> type < 0 ) {
if ( F_1 ( V_2 , V_10 ) == 0 )
return false ;
}
V_12 = 0 ;
break;
}
V_10 += V_14 ;
V_11 -= V_14 ;
}
if ( ( V_12 == 6 ) && ( ( V_10 - F_8 ( V_2 ) ) == 8 ) )
goto V_13;
if ( V_11 == 0 )
return true ;
V_13:
F_6 ( V_2 ) ;
return false ;
}
static bool F_12 ( struct V_1 * V_2 , int V_3 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 = F_13 ( V_2 ) ;
struct V_23 * V_24 = F_4 ( V_2 ) ;
struct V_25 V_26 ;
int V_27 ;
if ( V_22 -> V_28 ) {
F_14 ( V_29 L_1 ) ;
goto V_30;
}
V_22 -> V_28 = V_22 -> V_31 ;
V_22 -> V_31 = 0 ;
V_20 = (struct V_19 * ) ( F_2 ( V_2 ) + V_3 ) ;
if ( V_20 -> V_32 != 16 ) {
F_14 (
V_29 L_2 , V_20 -> V_32 ) ;
goto V_30;
}
if ( ! ( F_15 ( & V_20 -> V_33 ) & V_34 ) ) {
F_14 (
V_29 L_3 , & V_20 -> V_33 ) ;
goto V_30;
}
V_27 = F_16 ( V_2 , ( V_35 * ) & V_24 -> V_4 ,
( V_35 * ) & V_20 -> V_33 , V_36 ) ;
if ( F_17 ( V_27 < 0 ) )
goto V_30;
if ( F_18 ( V_2 ) ) {
if ( F_19 ( V_2 , 0 , 0 , V_37 ) )
goto V_30;
V_20 = (struct V_19 * ) ( F_2 ( V_2 ) +
V_3 ) ;
V_24 = F_4 ( V_2 ) ;
}
if ( V_2 -> V_38 == V_39 )
V_2 -> V_38 = V_40 ;
V_26 = V_24 -> V_41 ;
V_24 -> V_41 = V_20 -> V_33 ;
V_20 -> V_33 = V_26 ;
if ( V_2 -> V_42 . V_43 == 0 )
F_20 ( V_2 ) ;
return true ;
V_30:
F_6 ( V_2 ) ;
return false ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_13 ( V_2 ) ;
#if F_22 ( V_44 )
T_1 V_45 ;
#endif
struct V_46 * V_47 = F_23 ( V_2 ) ;
if ( ! F_24 ( V_2 , F_10 ( V_2 ) + 8 ) ||
! F_24 ( V_2 , ( F_10 ( V_2 ) +
( ( F_9 ( V_2 ) [ 1 ] + 1 ) << 3 ) ) ) ) {
F_25 ( F_26 ( V_47 -> V_48 ) , F_27 ( V_47 ) ,
V_49 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
V_22 -> V_50 = V_22 -> V_31 = F_8 ( V_2 ) ;
#if F_22 ( V_44 )
V_45 = V_22 -> V_31 ;
#endif
if ( F_7 ( V_51 , V_2 ) ) {
V_2 -> V_52 += ( F_9 ( V_2 ) [ 1 ] + 1 ) << 3 ;
V_22 = F_13 ( V_2 ) ;
#if F_22 ( V_44 )
V_22 -> V_53 = V_45 ;
#else
V_22 -> V_53 = V_22 -> V_31 ;
#endif
return 1 ;
}
F_25 ( F_26 ( V_47 -> V_48 ) ,
F_27 ( V_47 ) , V_49 ) ;
return - 1 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_13 ( V_2 ) ;
struct V_25 * V_33 = NULL ;
struct V_25 V_4 ;
struct V_54 * V_55 ;
int V_56 , V_15 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
struct V_61 * V_61 = F_26 ( V_2 -> V_48 ) ;
int V_62 = V_61 -> V_63 . V_64 -> V_62 ;
V_55 = F_29 ( V_2 -> V_48 ) ;
if ( V_55 && V_62 > V_55 -> V_65 . V_62 )
V_62 = V_55 -> V_65 . V_62 ;
if ( ! F_24 ( V_2 , F_10 ( V_2 ) + 8 ) ||
! F_24 ( V_2 , ( F_10 ( V_2 ) +
( ( F_9 ( V_2 ) [ 1 ] + 1 ) << 3 ) ) ) ) {
F_25 ( V_61 , F_27 ( F_23 ( V_2 ) ) ,
V_49 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
V_58 = (struct V_57 * ) F_9 ( V_2 ) ;
if ( F_3 ( & F_4 ( V_2 ) -> V_4 ) ||
V_2 -> V_66 != V_67 ) {
F_25 ( V_61 , F_27 ( F_23 ( V_2 ) ) ,
V_68 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
V_69:
if ( V_58 -> V_70 == 0 ) {
switch ( V_58 -> type ) {
#if F_22 ( V_44 )
case V_71 :
if ( ! V_33 ) {
F_25 ( V_61 , F_27 ( F_23 ( V_2 ) ) ,
V_68 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
break;
#endif
default:
break;
}
V_22 -> V_50 = V_22 -> V_72 = F_8 ( V_2 ) ;
V_2 -> V_52 += ( V_58 -> V_73 + 1 ) << 3 ;
V_22 -> V_74 = V_22 -> V_31 ;
V_22 -> V_31 = 0 ;
V_22 -> V_53 = ( & V_58 -> V_75 ) - F_2 ( V_2 ) ;
return 1 ;
}
switch ( V_58 -> type ) {
#if F_22 ( V_44 )
case V_71 :
if ( V_62 < 0 )
goto V_76;
if ( V_58 -> V_73 != 2 || V_58 -> V_70 != 1 ) {
F_25 ( V_61 , F_27 ( F_23 ( V_2 ) ) ,
V_49 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
break;
#endif
default:
goto V_76;
}
V_56 = V_58 -> V_73 >> 1 ;
if ( V_58 -> V_70 > V_56 ) {
F_25 ( V_61 , F_27 ( F_23 ( V_2 ) ) ,
V_49 ) ;
F_5 ( V_2 , V_77 ,
( ( & V_58 -> V_70 ) -
F_2 ( V_2 ) ) ) ;
return - 1 ;
}
if ( F_18 ( V_2 ) ) {
if ( F_19 ( V_2 , 0 , 0 , V_37 ) ) {
F_25 ( V_61 , F_27 ( F_23 ( V_2 ) ) ,
V_78 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
V_58 = (struct V_57 * ) F_9 ( V_2 ) ;
}
if ( V_2 -> V_38 == V_39 )
V_2 -> V_38 = V_40 ;
V_15 = V_56 - -- V_58 -> V_70 ;
V_60 = (struct V_59 * ) V_58 ;
V_33 = V_60 -> V_33 ;
V_33 += V_15 - 1 ;
switch ( V_58 -> type ) {
#if F_22 ( V_44 )
case V_71 :
if ( F_16 ( V_2 , ( V_35 * ) V_33 ,
( V_35 * ) & F_4 ( V_2 ) -> V_41 ,
V_79 ) < 0 ) {
F_25 ( V_61 , F_27 ( F_23 ( V_2 ) ) ,
V_68 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
if ( ! F_30 ( F_26 ( F_23 ( V_2 ) -> V_48 ) , V_33 ) ) {
F_25 ( V_61 , F_27 ( F_23 ( V_2 ) ) ,
V_68 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
break;
#endif
default:
break;
}
if ( F_3 ( V_33 ) ) {
F_25 ( V_61 , F_27 ( F_23 ( V_2 ) ) ,
V_68 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
V_4 = * V_33 ;
* V_33 = F_4 ( V_2 ) -> V_4 ;
F_4 ( V_2 ) -> V_4 = V_4 ;
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
if ( F_23 ( V_2 ) -> error ) {
F_33 ( V_2 , V_2 -> V_80 - F_2 ( V_2 ) ) ;
F_34 ( V_2 ) ;
return - 1 ;
}
if ( F_23 ( V_2 ) -> V_48 -> V_81 & V_82 ) {
if ( F_4 ( V_2 ) -> V_83 <= 1 ) {
F_25 ( V_61 , F_27 ( F_23 ( V_2 ) ) ,
V_49 ) ;
F_35 ( V_2 , V_84 , V_85 ,
0 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
F_4 ( V_2 ) -> V_83 -- ;
goto V_69;
}
F_33 ( V_2 , V_2 -> V_80 - F_2 ( V_2 ) ) ;
F_34 ( V_2 ) ;
return - 1 ;
V_76:
F_25 ( V_61 , F_27 ( F_23 ( V_2 ) ) , V_49 ) ;
F_5 ( V_2 , V_77 ,
( & V_58 -> type ) - F_2 ( V_2 ) ) ;
return - 1 ;
}
int T_2 F_36 ( void )
{
int V_27 ;
V_27 = F_37 ( & V_86 , V_79 ) ;
if ( V_27 )
goto V_87;
V_27 = F_37 ( & V_88 , V_36 ) ;
if ( V_27 )
goto V_89;
V_27 = F_37 ( & V_90 , V_91 ) ;
if ( V_27 )
goto V_92;
V_87:
return V_27 ;
V_92:
F_38 ( & V_88 , V_36 ) ;
V_89:
F_38 ( & V_86 , V_79 ) ;
goto V_87;
}
void F_39 ( void )
{
F_38 ( & V_90 , V_91 ) ;
F_38 ( & V_88 , V_36 ) ;
F_38 ( & V_86 , V_79 ) ;
}
static inline struct V_54 * F_40 ( struct V_1 * V_2 )
{
return F_23 ( V_2 ) ? F_27 ( F_23 ( V_2 ) ) : F_29 ( V_2 -> V_48 ) ;
}
static inline struct V_61 * F_41 ( struct V_1 * V_2 )
{
return F_23 ( V_2 ) ? F_26 ( F_23 ( V_2 ) -> V_48 ) : F_26 ( V_2 -> V_48 ) ;
}
static bool F_42 ( struct V_1 * V_2 , int V_3 )
{
const unsigned char * V_9 = F_2 ( V_2 ) ;
if ( V_9 [ V_3 + 1 ] == 2 ) {
F_13 ( V_2 ) -> V_93 = V_3 ;
return true ;
}
F_14 ( V_29 L_4 ,
V_9 [ V_3 + 1 ] ) ;
F_6 ( V_2 ) ;
return false ;
}
static bool F_43 ( struct V_1 * V_2 , int V_3 )
{
const unsigned char * V_9 = F_2 ( V_2 ) ;
struct V_61 * V_61 = F_41 ( V_2 ) ;
T_3 V_94 ;
if ( V_9 [ V_3 + 1 ] != 4 || ( V_3 & 3 ) != 2 ) {
F_14 ( V_29 L_5 ,
V_9 [ V_3 + 1 ] ) ;
F_25 ( V_61 , F_40 ( V_2 ) ,
V_49 ) ;
goto V_95;
}
V_94 = F_44 ( * ( V_96 * ) ( V_9 + V_3 + 2 ) ) ;
if ( V_94 <= V_97 ) {
F_25 ( V_61 , F_40 ( V_2 ) ,
V_49 ) ;
F_5 ( V_2 , V_77 , V_3 + 2 ) ;
return false ;
}
if ( F_4 ( V_2 ) -> V_98 ) {
F_25 ( V_61 , F_40 ( V_2 ) ,
V_49 ) ;
F_5 ( V_2 , V_77 , V_3 ) ;
return false ;
}
if ( V_94 > V_2 -> V_11 - sizeof( struct V_23 ) ) {
F_25 ( V_61 , F_40 ( V_2 ) ,
V_99 ) ;
goto V_95;
}
if ( F_45 ( V_2 , V_94 + sizeof( struct V_23 ) ) )
goto V_95;
return true ;
V_95:
F_6 ( V_2 ) ;
return false ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_13 ( V_2 ) ;
if ( ! F_24 ( V_2 , sizeof( struct V_23 ) + 8 ) ||
! F_24 ( V_2 , ( sizeof( struct V_23 ) +
( ( F_9 ( V_2 ) [ 1 ] + 1 ) << 3 ) ) ) ) {
F_6 ( V_2 ) ;
return - 1 ;
}
V_22 -> V_100 = sizeof( struct V_23 ) ;
if ( F_7 ( V_101 , V_2 ) ) {
V_2 -> V_52 += ( F_9 ( V_2 ) [ 1 ] + 1 ) << 3 ;
V_22 = F_13 ( V_2 ) ;
V_22 -> V_53 = sizeof( struct V_23 ) ;
return 1 ;
}
return - 1 ;
}
static void F_47 ( struct V_1 * V_2 , T_4 * V_102 ,
struct V_57 * V_22 ,
struct V_25 * * V_103 )
{
struct V_59 * V_104 , * V_105 ;
int V_106 ;
V_105 = (struct V_59 * ) V_22 ;
V_104 = (struct V_59 * ) F_33 ( V_2 , ( V_105 -> V_107 . V_73 + 1 ) << 3 ) ;
memcpy ( V_104 , V_105 , sizeof( struct V_59 ) ) ;
V_106 = V_105 -> V_107 . V_73 >> 1 ;
if ( V_106 > 1 )
memcpy ( V_104 -> V_33 , V_105 -> V_33 + 1 ,
( V_106 - 1 ) * sizeof( struct V_25 ) ) ;
V_104 -> V_33 [ V_106 - 1 ] = * * V_103 ;
* V_103 = V_105 -> V_33 ;
V_104 -> V_107 . V_75 = * V_102 ;
* V_102 = V_108 ;
}
static void F_48 ( struct V_1 * V_2 , T_4 * V_102 , T_4 type , struct V_109 * V_22 )
{
struct V_109 * V_110 = (struct V_109 * ) F_33 ( V_2 , F_49 ( V_22 ) ) ;
memcpy ( V_110 , V_22 , F_49 ( V_22 ) ) ;
V_110 -> V_75 = * V_102 ;
* V_102 = type ;
}
void F_50 ( struct V_1 * V_2 , struct V_111 * V_22 ,
T_4 * V_102 ,
struct V_25 * * V_4 )
{
if ( V_22 -> V_72 ) {
F_47 ( V_2 , V_102 , V_22 -> V_72 , V_4 ) ;
if ( V_22 -> V_112 )
F_48 ( V_2 , V_102 , V_113 , V_22 -> V_112 ) ;
}
if ( V_22 -> V_114 )
F_48 ( V_2 , V_102 , V_115 , V_22 -> V_114 ) ;
}
void F_51 ( struct V_1 * V_2 , struct V_111 * V_22 , T_4 * V_102 )
{
if ( V_22 -> V_116 )
F_48 ( V_2 , V_102 , V_113 , V_22 -> V_116 ) ;
}
struct V_111 *
F_52 ( struct V_117 * V_118 , struct V_111 * V_22 )
{
struct V_111 * V_119 ;
V_119 = F_53 ( V_118 , V_22 -> V_120 , V_37 ) ;
if ( V_119 ) {
long V_121 = ( char * ) V_119 - ( char * ) V_22 ;
memcpy ( V_119 , V_22 , V_22 -> V_120 ) ;
if ( V_119 -> V_114 )
* ( ( char * * ) & V_119 -> V_114 ) += V_121 ;
if ( V_119 -> V_112 )
* ( ( char * * ) & V_119 -> V_112 ) += V_121 ;
if ( V_119 -> V_116 )
* ( ( char * * ) & V_119 -> V_116 ) += V_121 ;
if ( V_119 -> V_72 )
* ( ( char * * ) & V_119 -> V_72 ) += V_121 ;
}
return V_119 ;
}
static int F_54 ( void * V_122 ,
struct V_109 T_5 * V_123 , int V_124 ,
int V_125 ,
struct V_109 * * V_58 ,
char * * V_126 )
{
if ( V_125 ) {
if ( V_122 ) {
memcpy ( * V_126 , V_122 , F_49 ( (struct V_109 * ) V_122 ) ) ;
* V_58 = (struct V_109 * ) * V_126 ;
* V_126 += F_55 ( F_49 ( * V_58 ) ) ;
}
} else {
if ( V_123 ) {
if ( F_56 ( * V_126 , V_123 , V_124 ) )
return - V_127 ;
* V_58 = (struct V_109 * ) * V_126 ;
if ( F_49 ( * V_58 ) > V_124 )
return - V_128 ;
* V_126 += F_55 ( V_124 ) ;
}
}
return 0 ;
}
struct V_111 *
F_57 ( struct V_117 * V_118 , struct V_111 * V_22 ,
int V_129 ,
struct V_109 T_5 * V_123 , int V_124 )
{
int V_120 = 0 ;
char * V_126 ;
struct V_111 * V_119 ;
int V_130 ;
if ( V_22 ) {
if ( V_129 != V_131 && V_22 -> V_114 )
V_120 += F_55 ( F_49 ( V_22 -> V_114 ) ) ;
if ( V_129 != V_132 && V_22 -> V_112 )
V_120 += F_55 ( F_49 ( V_22 -> V_112 ) ) ;
if ( V_129 != V_133 && V_22 -> V_72 )
V_120 += F_55 ( F_49 ( V_22 -> V_72 ) ) ;
if ( V_129 != V_134 && V_22 -> V_116 )
V_120 += F_55 ( F_49 ( V_22 -> V_116 ) ) ;
}
if ( V_123 && V_124 )
V_120 += F_55 ( V_124 ) ;
if ( ! V_120 )
return NULL ;
V_120 += sizeof( * V_119 ) ;
V_119 = F_53 ( V_118 , V_120 , V_37 ) ;
if ( ! V_119 )
return F_58 ( - V_135 ) ;
memset ( V_119 , 0 , V_120 ) ;
V_119 -> V_120 = V_120 ;
V_126 = ( char * ) ( V_119 + 1 ) ;
V_130 = F_54 ( V_22 ? V_22 -> V_114 : NULL , V_123 , V_124 ,
V_129 != V_131 ,
& V_119 -> V_114 , & V_126 ) ;
if ( V_130 )
goto V_87;
V_130 = F_54 ( V_22 ? V_22 -> V_112 : NULL , V_123 , V_124 ,
V_129 != V_132 ,
& V_119 -> V_112 , & V_126 ) ;
if ( V_130 )
goto V_87;
V_130 = F_54 ( V_22 ? V_22 -> V_72 : NULL , V_123 , V_124 ,
V_129 != V_133 ,
(struct V_109 * * ) & V_119 -> V_72 , & V_126 ) ;
if ( V_130 )
goto V_87;
V_130 = F_54 ( V_22 ? V_22 -> V_116 : NULL , V_123 , V_124 ,
V_129 != V_134 ,
& V_119 -> V_116 , & V_126 ) ;
if ( V_130 )
goto V_87;
V_119 -> V_136 = ( V_119 -> V_114 ? F_49 ( V_119 -> V_114 ) : 0 ) +
( V_119 -> V_112 ? F_49 ( V_119 -> V_112 ) : 0 ) +
( V_119 -> V_72 ? F_49 ( V_119 -> V_72 ) : 0 ) ;
V_119 -> V_137 = ( V_119 -> V_116 ? F_49 ( V_119 -> V_116 ) : 0 ) ;
return V_119 ;
V_87:
F_59 ( V_118 , V_119 , V_119 -> V_120 ) ;
return F_58 ( V_130 ) ;
}
struct V_111 * F_60 ( struct V_111 * V_138 ,
struct V_111 * V_22 )
{
if ( V_22 && V_22 -> V_112 && ! V_22 -> V_72 ) {
if ( V_138 != V_22 ) {
memcpy ( V_138 , V_22 , sizeof( * V_138 ) ) ;
V_22 = V_138 ;
}
V_22 -> V_136 -= F_49 ( V_22 -> V_112 ) ;
V_22 -> V_112 = NULL ;
}
return V_22 ;
}
struct V_25 * F_61 ( struct V_139 * V_140 ,
const struct V_111 * V_22 ,
struct V_25 * V_141 )
{
if ( ! V_22 || ! V_22 -> V_72 )
return NULL ;
* V_141 = V_140 -> V_4 ;
V_140 -> V_4 = * ( (struct V_59 * ) V_22 -> V_72 ) -> V_33 ;
return V_141 ;
}
