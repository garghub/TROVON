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
static int F_3 ( struct V_1 * V_2 , int V_16 )
{
switch ( ( F_2 ( V_2 ) [ V_16 ] & 0xC0 ) >> 6 ) {
case 0 :
return 1 ;
case 1 :
break;
case 3 :
if ( F_4 ( & F_5 ( V_2 ) -> V_17 ) )
break;
case 2 :
F_6 ( V_2 , V_18 , V_16 ) ;
return 0 ;
}
F_7 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
struct V_19 * V_21 ;
const unsigned char * V_4 = F_2 ( V_2 ) ;
int V_22 = F_9 ( V_2 ) ;
int V_10 = ( F_10 ( V_2 ) [ 1 ] + 1 ) << 3 ;
if ( F_11 ( V_2 ) + V_10 > F_12 ( V_2 ) )
goto V_11;
V_22 += 2 ;
V_10 -= 2 ;
while ( V_10 > 0 ) {
int V_14 = V_4 [ V_22 + 1 ] + 2 ;
switch ( V_4 [ V_22 ] ) {
case V_15 :
V_14 = 1 ;
break;
case V_23 :
break;
default:
if ( V_14 > V_10 )
goto V_11;
for ( V_21 = V_20 ; V_21 -> type >= 0 ; V_21 ++ ) {
if ( V_21 -> type == V_4 [ V_22 ] ) {
if ( V_21 -> V_24 ( V_2 , V_22 ) == 0 )
return 0 ;
break;
}
}
if ( V_21 -> type < 0 ) {
if ( F_3 ( V_2 , V_22 ) == 0 )
return 0 ;
}
break;
}
V_22 += V_14 ;
V_10 -= V_14 ;
}
if ( V_10 == 0 )
return 1 ;
V_11:
F_7 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_16 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 = F_14 ( V_2 ) ;
struct V_29 * V_30 = F_5 ( V_2 ) ;
struct V_31 V_32 ;
int V_33 ;
if ( V_28 -> V_34 ) {
F_15 ( V_35 L_1 ) ;
goto V_36;
}
V_28 -> V_34 = V_28 -> V_37 ;
V_28 -> V_37 = 0 ;
V_26 = (struct V_25 * ) ( F_2 ( V_2 ) + V_16 ) ;
if ( V_26 -> V_38 != 16 ) {
F_15 (
V_35 L_2 , V_26 -> V_38 ) ;
goto V_36;
}
if ( ! ( F_16 ( & V_26 -> V_39 ) & V_40 ) ) {
F_15 (
V_35 L_3 , & V_26 -> V_39 ) ;
goto V_36;
}
V_33 = F_17 ( V_2 , ( V_41 * ) & V_30 -> V_17 ,
( V_41 * ) & V_26 -> V_39 , V_42 ) ;
if ( F_18 ( V_33 < 0 ) )
goto V_36;
if ( F_19 ( V_2 ) ) {
if ( F_20 ( V_2 , 0 , 0 , V_43 ) )
goto V_36;
V_26 = (struct V_25 * ) ( F_2 ( V_2 ) +
V_16 ) ;
V_30 = F_5 ( V_2 ) ;
}
if ( V_2 -> V_44 == V_45 )
V_2 -> V_44 = V_46 ;
V_32 = V_30 -> V_47 ;
V_30 -> V_47 = V_26 -> V_39 ;
V_26 -> V_39 = V_32 ;
if ( V_2 -> V_48 . V_49 == 0 )
F_21 ( V_2 ) ;
return 1 ;
V_36:
F_7 ( V_2 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_14 ( V_2 ) ;
#if F_23 ( V_50 ) || F_23 ( V_51 )
T_1 V_52 ;
#endif
struct V_53 * V_54 = F_24 ( V_2 ) ;
if ( ! F_25 ( V_2 , F_11 ( V_2 ) + 8 ) ||
! F_25 ( V_2 , ( F_11 ( V_2 ) +
( ( F_10 ( V_2 ) [ 1 ] + 1 ) << 3 ) ) ) ) {
F_26 ( F_27 ( V_54 -> V_55 ) , F_28 ( V_54 ) ,
V_56 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
V_28 -> V_57 = V_28 -> V_37 = F_9 ( V_2 ) ;
#if F_23 ( V_50 ) || F_23 ( V_51 )
V_52 = V_28 -> V_37 ;
#endif
if ( F_8 ( V_58 , V_2 ) ) {
V_2 -> V_59 += ( F_10 ( V_2 ) [ 1 ] + 1 ) << 3 ;
V_28 = F_14 ( V_2 ) ;
#if F_23 ( V_50 ) || F_23 ( V_51 )
V_28 -> V_60 = V_52 ;
#else
V_28 -> V_60 = V_28 -> V_37 ;
#endif
return 1 ;
}
F_26 ( F_27 ( V_54 -> V_55 ) ,
F_28 ( V_54 ) , V_56 ) ;
return - 1 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_14 ( V_2 ) ;
struct V_31 * V_39 = NULL ;
struct V_31 V_17 ;
struct V_61 * V_62 ;
int V_63 , V_64 ;
struct V_65 * V_9 ;
struct V_66 * V_67 ;
struct V_68 * V_68 = F_27 ( V_2 -> V_55 ) ;
int V_69 = V_68 -> V_70 . V_71 -> V_69 ;
V_62 = F_30 ( V_2 -> V_55 ) ;
if ( V_62 && V_69 > V_62 -> V_72 . V_69 )
V_69 = V_62 -> V_72 . V_69 ;
if ( ! F_25 ( V_2 , F_11 ( V_2 ) + 8 ) ||
! F_25 ( V_2 , ( F_11 ( V_2 ) +
( ( F_10 ( V_2 ) [ 1 ] + 1 ) << 3 ) ) ) ) {
F_26 ( V_68 , F_28 ( F_24 ( V_2 ) ) ,
V_56 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
V_9 = (struct V_65 * ) F_10 ( V_2 ) ;
if ( F_4 ( & F_5 ( V_2 ) -> V_17 ) ||
V_2 -> V_73 != V_74 ) {
F_26 ( V_68 , F_28 ( F_24 ( V_2 ) ) ,
V_75 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
V_76:
if ( V_9 -> V_77 == 0 ) {
switch ( V_9 -> type ) {
#if F_23 ( V_50 ) || F_23 ( V_51 )
case V_78 :
if ( ! V_39 ) {
F_26 ( V_68 , F_28 ( F_24 ( V_2 ) ) ,
V_75 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
break;
#endif
default:
break;
}
V_28 -> V_57 = V_28 -> V_79 = F_9 ( V_2 ) ;
V_2 -> V_59 += ( V_9 -> V_12 + 1 ) << 3 ;
V_28 -> V_80 = V_28 -> V_37 ;
V_28 -> V_37 = 0 ;
V_28 -> V_60 = ( & V_9 -> V_81 ) - F_2 ( V_2 ) ;
return 1 ;
}
switch ( V_9 -> type ) {
#if F_23 ( V_50 ) || F_23 ( V_51 )
case V_78 :
if ( V_69 < 0 )
goto V_82;
if ( V_9 -> V_12 != 2 || V_9 -> V_77 != 1 ) {
F_26 ( V_68 , F_28 ( F_24 ( V_2 ) ) ,
V_56 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
break;
#endif
default:
goto V_82;
}
V_63 = V_9 -> V_12 >> 1 ;
if ( V_9 -> V_77 > V_63 ) {
F_26 ( V_68 , F_28 ( F_24 ( V_2 ) ) ,
V_56 ) ;
F_6 ( V_2 , V_83 ,
( ( & V_9 -> V_77 ) -
F_2 ( V_2 ) ) ) ;
return - 1 ;
}
if ( F_19 ( V_2 ) ) {
if ( F_20 ( V_2 , 0 , 0 , V_43 ) ) {
F_26 ( V_68 , F_28 ( F_24 ( V_2 ) ) ,
V_84 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
V_9 = (struct V_65 * ) F_10 ( V_2 ) ;
}
if ( V_2 -> V_44 == V_45 )
V_2 -> V_44 = V_46 ;
V_64 = V_63 - -- V_9 -> V_77 ;
V_67 = (struct V_66 * ) V_9 ;
V_39 = V_67 -> V_39 ;
V_39 += V_64 - 1 ;
switch ( V_9 -> type ) {
#if F_23 ( V_50 ) || F_23 ( V_51 )
case V_78 :
if ( F_17 ( V_2 , ( V_41 * ) V_39 ,
( V_41 * ) & F_5 ( V_2 ) -> V_47 ,
V_85 ) < 0 ) {
F_26 ( V_68 , F_28 ( F_24 ( V_2 ) ) ,
V_75 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
if ( ! F_31 ( F_27 ( F_24 ( V_2 ) -> V_55 ) , V_39 ) ) {
F_26 ( V_68 , F_28 ( F_24 ( V_2 ) ) ,
V_75 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
break;
#endif
default:
break;
}
if ( F_4 ( V_39 ) ) {
F_26 ( V_68 , F_28 ( F_24 ( V_2 ) ) ,
V_75 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
V_17 = * V_39 ;
* V_39 = F_5 ( V_2 ) -> V_17 ;
F_5 ( V_2 ) -> V_17 = V_17 ;
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
if ( F_24 ( V_2 ) -> error ) {
F_34 ( V_2 , V_2 -> V_86 - F_2 ( V_2 ) ) ;
F_35 ( V_2 ) ;
return - 1 ;
}
if ( F_24 ( V_2 ) -> V_55 -> V_87 & V_88 ) {
if ( F_5 ( V_2 ) -> V_89 <= 1 ) {
F_26 ( V_68 , F_28 ( F_24 ( V_2 ) ) ,
V_56 ) ;
F_36 ( V_2 , V_90 , V_91 ,
0 ) ;
F_7 ( V_2 ) ;
return - 1 ;
}
F_5 ( V_2 ) -> V_89 -- ;
goto V_76;
}
F_34 ( V_2 , V_2 -> V_86 - F_2 ( V_2 ) ) ;
F_35 ( V_2 ) ;
return - 1 ;
V_82:
F_26 ( V_68 , F_28 ( F_24 ( V_2 ) ) , V_56 ) ;
F_6 ( V_2 , V_83 ,
( & V_9 -> type ) - F_2 ( V_2 ) ) ;
return - 1 ;
}
int T_2 F_37 ( void )
{
int V_33 ;
V_33 = F_38 ( & V_92 , V_85 ) ;
if ( V_33 )
goto V_93;
V_33 = F_38 ( & V_94 , V_42 ) ;
if ( V_33 )
goto V_95;
V_33 = F_38 ( & V_96 , V_97 ) ;
if ( V_33 )
goto V_98;
V_93:
return V_33 ;
V_95:
F_39 ( & V_92 , V_85 ) ;
V_98:
F_39 ( & V_94 , V_42 ) ;
goto V_93;
}
void F_40 ( void )
{
F_39 ( & V_96 , V_97 ) ;
F_39 ( & V_94 , V_42 ) ;
F_39 ( & V_92 , V_85 ) ;
}
static inline struct V_61 * F_41 ( struct V_1 * V_2 )
{
return F_24 ( V_2 ) ? F_28 ( F_24 ( V_2 ) ) : F_30 ( V_2 -> V_55 ) ;
}
static inline struct V_68 * F_42 ( struct V_1 * V_2 )
{
return F_24 ( V_2 ) ? F_27 ( F_24 ( V_2 ) -> V_55 ) : F_27 ( V_2 -> V_55 ) ;
}
static int F_43 ( struct V_1 * V_2 , int V_16 )
{
const unsigned char * V_4 = F_2 ( V_2 ) ;
if ( V_4 [ V_16 + 1 ] == 2 ) {
F_14 ( V_2 ) -> V_99 = V_16 ;
return 1 ;
}
F_15 ( V_35 L_4 ,
V_4 [ V_16 + 1 ] ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_16 )
{
const unsigned char * V_4 = F_2 ( V_2 ) ;
struct V_68 * V_68 = F_42 ( V_2 ) ;
T_3 V_100 ;
if ( V_4 [ V_16 + 1 ] != 4 || ( V_16 & 3 ) != 2 ) {
F_15 ( V_35 L_5 ,
V_4 [ V_16 + 1 ] ) ;
F_26 ( V_68 , F_41 ( V_2 ) ,
V_56 ) ;
goto V_101;
}
V_100 = F_45 ( * ( V_102 * ) ( V_4 + V_16 + 2 ) ) ;
if ( V_100 <= V_103 ) {
F_26 ( V_68 , F_41 ( V_2 ) ,
V_56 ) ;
F_6 ( V_2 , V_83 , V_16 + 2 ) ;
return 0 ;
}
if ( F_5 ( V_2 ) -> V_104 ) {
F_26 ( V_68 , F_41 ( V_2 ) ,
V_56 ) ;
F_6 ( V_2 , V_83 , V_16 ) ;
return 0 ;
}
if ( V_100 > V_2 -> V_10 - sizeof( struct V_29 ) ) {
F_26 ( V_68 , F_41 ( V_2 ) ,
V_105 ) ;
goto V_101;
}
if ( F_46 ( V_2 , V_100 + sizeof( struct V_29 ) ) )
goto V_101;
return 1 ;
V_101:
F_7 ( V_2 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_14 ( V_2 ) ;
if ( ! F_25 ( V_2 , sizeof( struct V_29 ) + 8 ) ||
! F_25 ( V_2 , ( sizeof( struct V_29 ) +
( ( F_10 ( V_2 ) [ 1 ] + 1 ) << 3 ) ) ) ) {
F_7 ( V_2 ) ;
return - 1 ;
}
V_28 -> V_106 = sizeof( struct V_29 ) ;
if ( F_8 ( V_107 , V_2 ) ) {
V_2 -> V_59 += ( F_10 ( V_2 ) [ 1 ] + 1 ) << 3 ;
V_28 = F_14 ( V_2 ) ;
V_28 -> V_60 = sizeof( struct V_29 ) ;
return 1 ;
}
return - 1 ;
}
static void F_48 ( struct V_1 * V_2 , T_4 * V_108 ,
struct V_65 * V_28 ,
struct V_31 * * V_109 )
{
struct V_66 * V_110 , * V_111 ;
int V_112 ;
V_111 = (struct V_66 * ) V_28 ;
V_110 = (struct V_66 * ) F_34 ( V_2 , ( V_111 -> V_113 . V_12 + 1 ) << 3 ) ;
memcpy ( V_110 , V_111 , sizeof( struct V_66 ) ) ;
V_112 = V_111 -> V_113 . V_12 >> 1 ;
if ( V_112 > 1 )
memcpy ( V_110 -> V_39 , V_111 -> V_39 + 1 ,
( V_112 - 1 ) * sizeof( struct V_31 ) ) ;
V_110 -> V_39 [ V_112 - 1 ] = * * V_109 ;
* V_109 = V_111 -> V_39 ;
V_110 -> V_113 . V_81 = * V_108 ;
* V_108 = V_114 ;
}
static void F_49 ( struct V_1 * V_2 , T_4 * V_108 , T_4 type , struct V_8 * V_28 )
{
struct V_8 * V_115 = (struct V_8 * ) F_34 ( V_2 , F_50 ( V_28 ) ) ;
memcpy ( V_115 , V_28 , F_50 ( V_28 ) ) ;
V_115 -> V_81 = * V_108 ;
* V_108 = type ;
}
void F_51 ( struct V_1 * V_2 , struct V_116 * V_28 ,
T_4 * V_108 ,
struct V_31 * * V_17 )
{
if ( V_28 -> V_79 ) {
F_48 ( V_2 , V_108 , V_28 -> V_79 , V_17 ) ;
if ( V_28 -> V_117 )
F_49 ( V_2 , V_108 , V_118 , V_28 -> V_117 ) ;
}
if ( V_28 -> V_119 )
F_49 ( V_2 , V_108 , V_120 , V_28 -> V_119 ) ;
}
void F_52 ( struct V_1 * V_2 , struct V_116 * V_28 , T_4 * V_108 )
{
if ( V_28 -> V_121 )
F_49 ( V_2 , V_108 , V_118 , V_28 -> V_121 ) ;
}
struct V_116 *
F_53 ( struct V_122 * V_123 , struct V_116 * V_28 )
{
struct V_116 * V_124 ;
V_124 = F_54 ( V_123 , V_28 -> V_125 , V_43 ) ;
if ( V_124 ) {
long V_126 = ( char * ) V_124 - ( char * ) V_28 ;
memcpy ( V_124 , V_28 , V_28 -> V_125 ) ;
if ( V_124 -> V_119 )
* ( ( char * * ) & V_124 -> V_119 ) += V_126 ;
if ( V_124 -> V_117 )
* ( ( char * * ) & V_124 -> V_117 ) += V_126 ;
if ( V_124 -> V_121 )
* ( ( char * * ) & V_124 -> V_121 ) += V_126 ;
if ( V_124 -> V_79 )
* ( ( char * * ) & V_124 -> V_79 ) += V_126 ;
}
return V_124 ;
}
static int F_55 ( void * V_127 ,
struct V_8 T_5 * V_128 , int V_129 ,
int V_130 ,
struct V_8 * * V_9 ,
char * * V_131 )
{
if ( V_130 ) {
if ( V_127 ) {
memcpy ( * V_131 , V_127 , F_50 ( (struct V_8 * ) V_127 ) ) ;
* V_9 = (struct V_8 * ) * V_131 ;
* V_131 += F_56 ( F_50 ( * (struct V_8 * * ) V_9 ) ) ;
}
} else {
if ( V_128 ) {
if ( F_57 ( * V_131 , V_128 , V_129 ) )
return - V_132 ;
* V_9 = (struct V_8 * ) * V_131 ;
if ( F_50 ( * (struct V_8 * * ) V_9 ) > V_129 )
return - V_133 ;
* V_131 += F_56 ( V_129 ) ;
}
}
return 0 ;
}
struct V_116 *
F_58 ( struct V_122 * V_123 , struct V_116 * V_28 ,
int V_134 ,
struct V_8 T_5 * V_128 , int V_129 )
{
int V_125 = 0 ;
char * V_131 ;
struct V_116 * V_124 ;
int V_135 ;
if ( V_28 ) {
if ( V_134 != V_136 && V_28 -> V_119 )
V_125 += F_56 ( F_50 ( V_28 -> V_119 ) ) ;
if ( V_134 != V_137 && V_28 -> V_117 )
V_125 += F_56 ( F_50 ( V_28 -> V_117 ) ) ;
if ( V_134 != V_138 && V_28 -> V_79 )
V_125 += F_56 ( F_50 ( V_28 -> V_79 ) ) ;
if ( V_134 != V_139 && V_28 -> V_121 )
V_125 += F_56 ( F_50 ( V_28 -> V_121 ) ) ;
}
if ( V_128 && V_129 )
V_125 += F_56 ( V_129 ) ;
if ( ! V_125 )
return NULL ;
V_125 += sizeof( * V_124 ) ;
V_124 = F_54 ( V_123 , V_125 , V_43 ) ;
if ( ! V_124 )
return F_59 ( - V_140 ) ;
memset ( V_124 , 0 , V_125 ) ;
V_124 -> V_125 = V_125 ;
V_131 = ( char * ) ( V_124 + 1 ) ;
V_135 = F_55 ( V_28 ? V_28 -> V_119 : NULL , V_128 , V_129 ,
V_134 != V_136 ,
& V_124 -> V_119 , & V_131 ) ;
if ( V_135 )
goto V_93;
V_135 = F_55 ( V_28 ? V_28 -> V_117 : NULL , V_128 , V_129 ,
V_134 != V_137 ,
& V_124 -> V_117 , & V_131 ) ;
if ( V_135 )
goto V_93;
V_135 = F_55 ( V_28 ? V_28 -> V_79 : NULL , V_128 , V_129 ,
V_134 != V_138 ,
(struct V_8 * * ) & V_124 -> V_79 , & V_131 ) ;
if ( V_135 )
goto V_93;
V_135 = F_55 ( V_28 ? V_28 -> V_121 : NULL , V_128 , V_129 ,
V_134 != V_139 ,
& V_124 -> V_121 , & V_131 ) ;
if ( V_135 )
goto V_93;
V_124 -> V_141 = ( V_124 -> V_119 ? F_50 ( V_124 -> V_119 ) : 0 ) +
( V_124 -> V_117 ? F_50 ( V_124 -> V_117 ) : 0 ) +
( V_124 -> V_79 ? F_50 ( V_124 -> V_79 ) : 0 ) ;
V_124 -> V_142 = ( V_124 -> V_121 ? F_50 ( V_124 -> V_121 ) : 0 ) ;
return V_124 ;
V_93:
F_60 ( V_123 , V_124 , V_124 -> V_125 ) ;
return F_59 ( V_135 ) ;
}
struct V_116 * F_61 ( struct V_116 * V_143 ,
struct V_116 * V_28 )
{
if ( V_28 && V_28 -> V_117 && ! V_28 -> V_79 ) {
if ( V_143 != V_28 ) {
memcpy ( V_143 , V_28 , sizeof( * V_143 ) ) ;
V_28 = V_143 ;
}
V_28 -> V_141 -= F_50 ( V_28 -> V_117 ) ;
V_28 -> V_117 = NULL ;
}
return V_28 ;
}
struct V_31 * F_62 ( struct V_144 * V_145 ,
const struct V_116 * V_28 ,
struct V_31 * V_146 )
{
if ( ! V_28 || ! V_28 -> V_79 )
return NULL ;
* V_146 = V_145 -> V_17 ;
V_145 -> V_17 = * ( (struct V_66 * ) V_28 -> V_79 ) -> V_39 ;
return V_146 ;
}
