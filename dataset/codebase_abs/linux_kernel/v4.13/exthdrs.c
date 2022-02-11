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
F_14 ( L_1 ) ;
goto V_29;
}
V_22 -> V_28 = V_22 -> V_30 ;
V_22 -> V_30 = 0 ;
V_20 = (struct V_19 * ) ( F_2 ( V_2 ) + V_3 ) ;
if ( V_20 -> V_31 != 16 ) {
F_14 ( L_2 ,
V_20 -> V_31 ) ;
goto V_29;
}
if ( ! ( F_15 ( & V_20 -> V_32 ) & V_33 ) ) {
F_14 ( L_3 ,
& V_20 -> V_32 ) ;
goto V_29;
}
V_27 = F_16 ( V_2 , ( V_34 * ) & V_24 -> V_4 ,
( V_34 * ) & V_20 -> V_32 , V_35 ) ;
if ( F_17 ( V_27 < 0 ) )
goto V_29;
if ( F_18 ( V_2 ) ) {
if ( F_19 ( V_2 , 0 , 0 , V_36 ) )
goto V_29;
V_20 = (struct V_19 * ) ( F_2 ( V_2 ) +
V_3 ) ;
V_24 = F_4 ( V_2 ) ;
}
if ( V_2 -> V_37 == V_38 )
V_2 -> V_37 = V_39 ;
V_26 = V_24 -> V_40 ;
V_24 -> V_40 = V_20 -> V_32 ;
V_20 -> V_32 = V_26 ;
if ( V_2 -> V_41 == 0 )
F_20 ( V_2 ) ;
return true ;
V_29:
F_6 ( V_2 ) ;
return false ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_13 ( V_2 ) ;
#if F_22 ( V_42 )
T_1 V_43 ;
#endif
struct V_44 * V_45 = F_23 ( V_2 ) ;
if ( ! F_24 ( V_2 , F_10 ( V_2 ) + 8 ) ||
! F_24 ( V_2 , ( F_10 ( V_2 ) +
( ( F_9 ( V_2 ) [ 1 ] + 1 ) << 3 ) ) ) ) {
F_25 ( F_26 ( V_45 -> V_46 ) , F_27 ( V_45 ) ,
V_47 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
V_22 -> V_48 = V_22 -> V_30 = F_8 ( V_2 ) ;
#if F_22 ( V_42 )
V_43 = V_22 -> V_30 ;
#endif
if ( F_7 ( V_49 , V_2 ) ) {
V_2 -> V_50 += ( F_9 ( V_2 ) [ 1 ] + 1 ) << 3 ;
V_22 = F_13 ( V_2 ) ;
#if F_22 ( V_42 )
V_22 -> V_51 = V_43 ;
#else
V_22 -> V_51 = V_22 -> V_30 ;
#endif
return 1 ;
}
F_25 ( F_26 ( V_45 -> V_46 ) ,
F_27 ( V_45 ) , V_47 ) ;
return - 1 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
struct V_25 * V_32 ;
T_2 V_54 , V_55 ;
V_53 = (struct V_52 * ) F_9 ( V_2 ) ;
V_32 = V_53 -> V_56 + V_53 -> V_57 ;
V_53 -> V_57 ++ ;
V_54 = * ( T_2 * ) V_53 ;
V_53 -> V_57 -- ;
V_55 = * ( T_2 * ) V_53 ;
F_29 ( V_2 , V_54 , V_55 ) ;
F_30 ( V_2 , ( T_2 * ) ( & F_4 ( V_2 ) -> V_4 ) ,
( T_2 * ) V_32 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_13 ( V_2 ) ;
struct V_58 * V_58 = F_26 ( V_2 -> V_46 ) ;
struct V_52 * V_53 ;
struct V_59 * V_60 ;
struct V_25 * V_32 ;
int V_61 ;
V_53 = (struct V_52 * ) F_9 ( V_2 ) ;
V_60 = F_32 ( V_2 -> V_46 ) ;
V_61 = V_58 -> V_62 . V_63 -> V_64 ;
if ( V_61 > V_60 -> V_65 . V_64 )
V_61 = V_60 -> V_65 . V_64 ;
if ( ! V_61 ) {
F_6 ( V_2 ) ;
return - 1 ;
}
#ifdef F_33
if ( ! F_34 ( V_2 ) ) {
F_6 ( V_2 ) ;
return - 1 ;
}
#endif
V_66:
if ( V_53 -> V_57 == 0 ) {
if ( V_53 -> V_67 == V_68 ) {
int V_69 = ( V_53 -> V_70 + 1 ) << 3 ;
F_35 ( V_2 , F_2 ( V_2 ) ,
F_8 ( V_2 ) ) ;
if ( ! F_36 ( V_2 , V_69 ) ) {
F_6 ( V_2 ) ;
return - 1 ;
}
F_35 ( V_2 , F_9 ( V_2 ) ,
V_69 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
V_2 -> V_71 = 0 ;
F_39 ( V_2 , V_2 -> V_46 , V_58 ) ;
F_40 ( V_2 ) ;
return - 1 ;
}
V_22 -> V_72 = F_8 ( V_2 ) ;
V_22 -> V_48 = V_22 -> V_72 ;
V_2 -> V_50 += ( V_53 -> V_70 + 1 ) << 3 ;
V_22 -> V_51 = ( & V_53 -> V_67 ) - F_2 ( V_2 ) ;
return 1 ;
}
if ( V_53 -> V_57 >= ( V_53 -> V_70 >> 1 ) ) {
F_25 ( V_58 , F_27 ( F_23 ( V_2 ) ) ,
V_47 ) ;
F_5 ( V_2 , V_73 ,
( ( & V_53 -> V_57 ) -
F_2 ( V_2 ) ) ) ;
return - 1 ;
}
if ( F_18 ( V_2 ) ) {
if ( F_19 ( V_2 , 0 , 0 , V_36 ) ) {
F_25 ( V_58 , F_27 ( F_23 ( V_2 ) ) ,
V_74 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
}
V_53 = (struct V_52 * ) F_9 ( V_2 ) ;
V_53 -> V_57 -- ;
V_32 = V_53 -> V_56 + V_53 -> V_57 ;
F_41 ( V_2 , sizeof( struct V_23 ) ) ;
if ( V_2 -> V_37 == V_38 )
F_28 ( V_2 ) ;
F_4 ( V_2 ) -> V_4 = * V_32 ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
if ( F_23 ( V_2 ) -> error ) {
F_44 ( V_2 ) ;
return - 1 ;
}
if ( F_23 ( V_2 ) -> V_46 -> V_75 & V_76 ) {
if ( F_4 ( V_2 ) -> V_77 <= 1 ) {
F_25 ( V_58 , F_27 ( F_23 ( V_2 ) ) ,
V_47 ) ;
F_45 ( V_2 , V_78 ,
V_79 , 0 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
F_4 ( V_2 ) -> V_77 -- ;
F_46 ( V_2 , sizeof( struct V_23 ) ) ;
goto V_66;
}
F_44 ( V_2 ) ;
return - 1 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_13 ( V_2 ) ;
struct V_25 * V_32 = NULL ;
struct V_25 V_4 ;
struct V_59 * V_60 ;
int V_80 , V_15 ;
struct V_81 * V_53 ;
struct V_82 * V_83 ;
struct V_58 * V_58 = F_26 ( V_2 -> V_46 ) ;
int V_84 = V_58 -> V_62 . V_63 -> V_84 ;
V_60 = F_32 ( V_2 -> V_46 ) ;
if ( V_60 && V_84 > V_60 -> V_65 . V_84 )
V_84 = V_60 -> V_65 . V_84 ;
if ( ! F_24 ( V_2 , F_10 ( V_2 ) + 8 ) ||
! F_24 ( V_2 , ( F_10 ( V_2 ) +
( ( F_9 ( V_2 ) [ 1 ] + 1 ) << 3 ) ) ) ) {
F_25 ( V_58 , F_27 ( F_23 ( V_2 ) ) ,
V_47 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
V_53 = (struct V_81 * ) F_9 ( V_2 ) ;
if ( F_3 ( & F_4 ( V_2 ) -> V_4 ) ||
V_2 -> V_85 != V_86 ) {
F_25 ( V_58 , F_27 ( F_23 ( V_2 ) ) ,
V_87 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
if ( V_53 -> type == V_88 )
return F_31 ( V_2 ) ;
V_66:
if ( V_53 -> V_57 == 0 ) {
switch ( V_53 -> type ) {
#if F_22 ( V_42 )
case V_89 :
if ( ! V_32 ) {
F_25 ( V_58 , F_27 ( F_23 ( V_2 ) ) ,
V_87 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
break;
#endif
default:
break;
}
V_22 -> V_48 = V_22 -> V_72 = F_8 ( V_2 ) ;
V_2 -> V_50 += ( V_53 -> V_70 + 1 ) << 3 ;
V_22 -> V_90 = V_22 -> V_30 ;
V_22 -> V_30 = 0 ;
V_22 -> V_51 = ( & V_53 -> V_67 ) - F_2 ( V_2 ) ;
return 1 ;
}
switch ( V_53 -> type ) {
#if F_22 ( V_42 )
case V_89 :
if ( V_84 < 0 )
goto V_91;
if ( V_53 -> V_70 != 2 || V_53 -> V_57 != 1 ) {
F_25 ( V_58 , F_27 ( F_23 ( V_2 ) ) ,
V_47 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
break;
#endif
default:
goto V_91;
}
V_80 = V_53 -> V_70 >> 1 ;
if ( V_53 -> V_57 > V_80 ) {
F_25 ( V_58 , F_27 ( F_23 ( V_2 ) ) ,
V_47 ) ;
F_5 ( V_2 , V_73 ,
( ( & V_53 -> V_57 ) -
F_2 ( V_2 ) ) ) ;
return - 1 ;
}
if ( F_18 ( V_2 ) ) {
if ( F_19 ( V_2 , 0 , 0 , V_36 ) ) {
F_25 ( V_58 , F_27 ( F_23 ( V_2 ) ) ,
V_74 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
V_53 = (struct V_81 * ) F_9 ( V_2 ) ;
}
if ( V_2 -> V_37 == V_38 )
V_2 -> V_37 = V_39 ;
V_15 = V_80 - -- V_53 -> V_57 ;
V_83 = (struct V_82 * ) V_53 ;
V_32 = V_83 -> V_32 ;
V_32 += V_15 - 1 ;
switch ( V_53 -> type ) {
#if F_22 ( V_42 )
case V_89 :
if ( F_16 ( V_2 , ( V_34 * ) V_32 ,
( V_34 * ) & F_4 ( V_2 ) -> V_40 ,
V_92 ) < 0 ) {
F_25 ( V_58 , F_27 ( F_23 ( V_2 ) ) ,
V_87 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
if ( ! F_48 ( F_26 ( F_23 ( V_2 ) -> V_46 ) , V_32 ) ) {
F_25 ( V_58 , F_27 ( F_23 ( V_2 ) ) ,
V_87 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
break;
#endif
default:
break;
}
if ( F_3 ( V_32 ) ) {
F_25 ( V_58 , F_27 ( F_23 ( V_2 ) ) ,
V_87 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
V_4 = * V_32 ;
* V_32 = F_4 ( V_2 ) -> V_4 ;
F_4 ( V_2 ) -> V_4 = V_4 ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
if ( F_23 ( V_2 ) -> error ) {
F_41 ( V_2 , V_2 -> V_93 - F_2 ( V_2 ) ) ;
F_44 ( V_2 ) ;
return - 1 ;
}
if ( F_23 ( V_2 ) -> V_46 -> V_75 & V_76 ) {
if ( F_4 ( V_2 ) -> V_77 <= 1 ) {
F_25 ( V_58 , F_27 ( F_23 ( V_2 ) ) ,
V_47 ) ;
F_45 ( V_2 , V_78 , V_79 ,
0 ) ;
F_6 ( V_2 ) ;
return - 1 ;
}
F_4 ( V_2 ) -> V_77 -- ;
goto V_66;
}
F_41 ( V_2 , V_2 -> V_93 - F_2 ( V_2 ) ) ;
F_44 ( V_2 ) ;
return - 1 ;
V_91:
F_25 ( V_58 , F_27 ( F_23 ( V_2 ) ) , V_47 ) ;
F_5 ( V_2 , V_73 ,
( & V_53 -> type ) - F_2 ( V_2 ) ) ;
return - 1 ;
}
int T_3 F_49 ( void )
{
int V_27 ;
V_27 = F_50 ( & V_94 , V_92 ) ;
if ( V_27 )
goto V_95;
V_27 = F_50 ( & V_96 , V_35 ) ;
if ( V_27 )
goto V_97;
V_27 = F_50 ( & V_98 , V_99 ) ;
if ( V_27 )
goto V_100;
V_95:
return V_27 ;
V_100:
F_51 ( & V_96 , V_35 ) ;
V_97:
F_51 ( & V_94 , V_92 ) ;
goto V_95;
}
void F_52 ( void )
{
F_51 ( & V_98 , V_99 ) ;
F_51 ( & V_96 , V_35 ) ;
F_51 ( & V_94 , V_92 ) ;
}
static inline struct V_59 * F_53 ( struct V_1 * V_2 )
{
return F_23 ( V_2 ) ? F_27 ( F_23 ( V_2 ) ) : F_32 ( V_2 -> V_46 ) ;
}
static inline struct V_58 * F_54 ( struct V_1 * V_2 )
{
return F_23 ( V_2 ) ? F_26 ( F_23 ( V_2 ) -> V_46 ) : F_26 ( V_2 -> V_46 ) ;
}
static bool F_55 ( struct V_1 * V_2 , int V_3 )
{
const unsigned char * V_9 = F_2 ( V_2 ) ;
if ( V_9 [ V_3 + 1 ] == 2 ) {
F_13 ( V_2 ) -> V_75 |= V_101 ;
memcpy ( & F_13 ( V_2 ) -> V_102 , V_9 + V_3 + 2 , sizeof( F_13 ( V_2 ) -> V_102 ) ) ;
return true ;
}
F_14 ( L_4 ,
V_9 [ V_3 + 1 ] ) ;
F_6 ( V_2 ) ;
return false ;
}
static bool F_56 ( struct V_1 * V_2 , int V_3 )
{
const unsigned char * V_9 = F_2 ( V_2 ) ;
struct V_58 * V_58 = F_54 ( V_2 ) ;
T_4 V_103 ;
if ( V_9 [ V_3 + 1 ] != 4 || ( V_3 & 3 ) != 2 ) {
F_14 ( L_5 ,
V_9 [ V_3 + 1 ] ) ;
F_25 ( V_58 , F_53 ( V_2 ) ,
V_47 ) ;
goto V_104;
}
V_103 = F_57 ( * ( T_2 * ) ( V_9 + V_3 + 2 ) ) ;
if ( V_103 <= V_105 ) {
F_25 ( V_58 , F_53 ( V_2 ) ,
V_47 ) ;
F_5 ( V_2 , V_73 , V_3 + 2 ) ;
return false ;
}
if ( F_4 ( V_2 ) -> V_106 ) {
F_25 ( V_58 , F_53 ( V_2 ) ,
V_47 ) ;
F_5 ( V_2 , V_73 , V_3 ) ;
return false ;
}
if ( V_103 > V_2 -> V_11 - sizeof( struct V_23 ) ) {
F_25 ( V_58 , F_53 ( V_2 ) ,
V_107 ) ;
goto V_104;
}
if ( F_58 ( V_2 , V_103 + sizeof( struct V_23 ) ) )
goto V_104;
F_13 ( V_2 ) -> V_75 |= V_108 ;
return true ;
V_104:
F_6 ( V_2 ) ;
return false ;
}
static bool F_59 ( struct V_1 * V_2 , int V_3 )
{
const unsigned char * V_9 = F_2 ( V_2 ) ;
if ( V_9 [ V_3 + 1 ] < 8 )
goto V_104;
if ( V_9 [ V_3 + 6 ] * 4 + 8 > V_9 [ V_3 + 1 ] )
goto V_104;
if ( ! F_60 ( V_2 , V_9 + V_3 ) )
goto V_104;
return true ;
V_104:
F_6 ( V_2 ) ;
return false ;
}
int F_61 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_13 ( V_2 ) ;
if ( ! F_24 ( V_2 , sizeof( struct V_23 ) + 8 ) ||
! F_24 ( V_2 , ( sizeof( struct V_23 ) +
( ( F_9 ( V_2 ) [ 1 ] + 1 ) << 3 ) ) ) ) {
F_6 ( V_2 ) ;
return - 1 ;
}
V_22 -> V_75 |= V_109 ;
if ( F_7 ( V_110 , V_2 ) ) {
V_2 -> V_50 += ( F_9 ( V_2 ) [ 1 ] + 1 ) << 3 ;
V_22 = F_13 ( V_2 ) ;
V_22 -> V_51 = sizeof( struct V_23 ) ;
return 1 ;
}
return - 1 ;
}
static void F_62 ( struct V_1 * V_2 , T_5 * V_111 ,
struct V_81 * V_22 ,
struct V_25 * * V_112 , struct V_25 * V_40 )
{
struct V_82 * V_113 , * V_114 ;
int V_115 ;
V_114 = (struct V_82 * ) V_22 ;
V_113 = F_41 ( V_2 , ( V_114 -> V_116 . V_70 + 1 ) << 3 ) ;
memcpy ( V_113 , V_114 , sizeof( struct V_82 ) ) ;
V_115 = V_114 -> V_116 . V_70 >> 1 ;
if ( V_115 > 1 )
memcpy ( V_113 -> V_32 , V_114 -> V_32 + 1 ,
( V_115 - 1 ) * sizeof( struct V_25 ) ) ;
V_113 -> V_32 [ V_115 - 1 ] = * * V_112 ;
* V_112 = V_114 -> V_32 ;
V_113 -> V_116 . V_67 = * V_111 ;
* V_111 = V_117 ;
}
static void F_63 ( struct V_1 * V_2 , T_5 * V_111 ,
struct V_81 * V_22 ,
struct V_25 * * V_112 , struct V_25 * V_40 )
{
struct V_52 * V_118 , * V_119 ;
int V_120 , V_115 ;
V_119 = (struct V_52 * ) V_22 ;
V_120 = ( V_119 -> V_70 + 1 ) << 3 ;
V_118 = F_41 ( V_2 , V_120 ) ;
memcpy ( V_118 , V_119 , sizeof( struct V_52 ) ) ;
V_115 = V_119 -> V_121 + 1 ;
memcpy ( V_118 -> V_56 + 1 , V_119 -> V_56 + 1 ,
( V_115 - 1 ) * sizeof( struct V_25 ) ) ;
V_118 -> V_56 [ 0 ] = * * V_112 ;
* V_112 = & V_119 -> V_56 [ V_115 - 1 ] ;
#ifdef F_33
if ( F_64 ( V_118 ) ) {
struct V_58 * V_58 = NULL ;
if ( V_2 -> V_46 )
V_58 = F_26 ( V_2 -> V_46 ) ;
else if ( V_2 -> V_122 )
V_58 = F_65 ( V_2 -> V_122 ) ;
F_66 ( ! V_58 ) ;
if ( V_58 )
F_67 ( V_58 , V_40 , V_118 ) ;
}
#endif
V_118 -> V_67 = * V_111 ;
* V_111 = V_117 ;
}
static void F_68 ( struct V_1 * V_2 , T_5 * V_111 ,
struct V_81 * V_22 ,
struct V_25 * * V_112 , struct V_25 * V_40 )
{
switch ( V_22 -> type ) {
case V_123 :
case V_124 :
case V_89 :
F_62 ( V_2 , V_111 , V_22 , V_112 , V_40 ) ;
break;
case V_88 :
F_63 ( V_2 , V_111 , V_22 , V_112 , V_40 ) ;
break;
default:
break;
}
}
static void F_69 ( struct V_1 * V_2 , T_5 * V_111 , T_5 type , struct V_125 * V_22 )
{
struct V_125 * V_126 = F_41 ( V_2 , F_70 ( V_22 ) ) ;
memcpy ( V_126 , V_22 , F_70 ( V_22 ) ) ;
V_126 -> V_67 = * V_111 ;
* V_111 = type ;
}
void F_71 ( struct V_1 * V_2 , struct V_127 * V_22 ,
T_5 * V_111 ,
struct V_25 * * V_4 , struct V_25 * V_40 )
{
if ( V_22 -> V_72 ) {
F_68 ( V_2 , V_111 , V_22 -> V_72 , V_4 , V_40 ) ;
if ( V_22 -> V_128 )
F_69 ( V_2 , V_111 , V_129 , V_22 -> V_128 ) ;
}
if ( V_22 -> V_130 )
F_69 ( V_2 , V_111 , V_131 , V_22 -> V_130 ) ;
}
void F_72 ( struct V_1 * V_2 , struct V_127 * V_22 , T_5 * V_111 )
{
if ( V_22 -> V_132 )
F_69 ( V_2 , V_111 , V_129 , V_22 -> V_132 ) ;
}
struct V_127 *
F_73 ( struct V_133 * V_122 , struct V_127 * V_22 )
{
struct V_127 * V_134 ;
V_134 = F_74 ( V_122 , V_22 -> V_135 , V_36 ) ;
if ( V_134 ) {
long V_136 = ( char * ) V_134 - ( char * ) V_22 ;
memcpy ( V_134 , V_22 , V_22 -> V_135 ) ;
if ( V_134 -> V_130 )
* ( ( char * * ) & V_134 -> V_130 ) += V_136 ;
if ( V_134 -> V_128 )
* ( ( char * * ) & V_134 -> V_128 ) += V_136 ;
if ( V_134 -> V_132 )
* ( ( char * * ) & V_134 -> V_132 ) += V_136 ;
if ( V_134 -> V_72 )
* ( ( char * * ) & V_134 -> V_72 ) += V_136 ;
F_75 ( & V_134 -> V_137 , 1 ) ;
}
return V_134 ;
}
static int F_76 ( void * V_138 ,
struct V_125 T_6 * V_139 , int V_140 ,
int V_141 ,
struct V_125 * * V_53 ,
char * * V_142 )
{
if ( V_141 ) {
if ( V_138 ) {
memcpy ( * V_142 , V_138 , F_70 ( (struct V_125 * ) V_138 ) ) ;
* V_53 = (struct V_125 * ) * V_142 ;
* V_142 += F_77 ( F_70 ( * V_53 ) ) ;
}
} else {
if ( V_139 ) {
if ( F_78 ( * V_142 , V_139 , V_140 ) )
return - V_143 ;
* V_53 = (struct V_125 * ) * V_142 ;
if ( F_70 ( * V_53 ) > V_140 )
return - V_144 ;
* V_142 += F_77 ( V_140 ) ;
}
}
return 0 ;
}
struct V_127 *
F_79 ( struct V_133 * V_122 , struct V_127 * V_22 ,
int V_145 ,
struct V_125 T_6 * V_139 , int V_140 )
{
int V_135 = 0 ;
char * V_142 ;
struct V_127 * V_134 ;
int V_146 ;
if ( V_22 ) {
if ( V_145 != V_147 && V_22 -> V_130 )
V_135 += F_77 ( F_70 ( V_22 -> V_130 ) ) ;
if ( V_145 != V_148 && V_22 -> V_128 )
V_135 += F_77 ( F_70 ( V_22 -> V_128 ) ) ;
if ( V_145 != V_149 && V_22 -> V_72 )
V_135 += F_77 ( F_70 ( V_22 -> V_72 ) ) ;
if ( V_145 != V_150 && V_22 -> V_132 )
V_135 += F_77 ( F_70 ( V_22 -> V_132 ) ) ;
}
if ( V_139 && V_140 )
V_135 += F_77 ( V_140 ) ;
if ( ! V_135 )
return NULL ;
V_135 += sizeof( * V_134 ) ;
V_134 = F_74 ( V_122 , V_135 , V_36 ) ;
if ( ! V_134 )
return F_80 ( - V_151 ) ;
memset ( V_134 , 0 , V_135 ) ;
F_75 ( & V_134 -> V_137 , 1 ) ;
V_134 -> V_135 = V_135 ;
V_142 = ( char * ) ( V_134 + 1 ) ;
V_146 = F_76 ( V_22 ? V_22 -> V_130 : NULL , V_139 , V_140 ,
V_145 != V_147 ,
& V_134 -> V_130 , & V_142 ) ;
if ( V_146 )
goto V_95;
V_146 = F_76 ( V_22 ? V_22 -> V_128 : NULL , V_139 , V_140 ,
V_145 != V_148 ,
& V_134 -> V_128 , & V_142 ) ;
if ( V_146 )
goto V_95;
V_146 = F_76 ( V_22 ? V_22 -> V_72 : NULL , V_139 , V_140 ,
V_145 != V_149 ,
(struct V_125 * * ) & V_134 -> V_72 , & V_142 ) ;
if ( V_146 )
goto V_95;
V_146 = F_76 ( V_22 ? V_22 -> V_132 : NULL , V_139 , V_140 ,
V_145 != V_150 ,
& V_134 -> V_132 , & V_142 ) ;
if ( V_146 )
goto V_95;
V_134 -> V_152 = ( V_134 -> V_130 ? F_70 ( V_134 -> V_130 ) : 0 ) +
( V_134 -> V_128 ? F_70 ( V_134 -> V_128 ) : 0 ) +
( V_134 -> V_72 ? F_70 ( V_134 -> V_72 ) : 0 ) ;
V_134 -> V_153 = ( V_134 -> V_132 ? F_70 ( V_134 -> V_132 ) : 0 ) ;
return V_134 ;
V_95:
F_81 ( V_122 , V_134 , V_134 -> V_135 ) ;
return F_80 ( V_146 ) ;
}
struct V_127 *
F_82 ( struct V_133 * V_122 , struct V_127 * V_22 ,
int V_145 , struct V_125 * V_139 ,
int V_140 )
{
struct V_127 * V_154 ;
const T_7 V_155 = F_83 () ;
F_84 ( V_156 ) ;
V_154 = F_79 ( V_122 , V_22 , V_145 ,
(struct V_125 T_6 * ) V_139 ,
V_140 ) ;
F_84 ( V_155 ) ;
return V_154 ;
}
struct V_127 * F_85 ( struct V_127 * V_157 ,
struct V_127 * V_22 )
{
if ( V_22 && V_22 -> V_128 && ! V_22 -> V_72 ) {
if ( V_157 != V_22 ) {
memcpy ( V_157 , V_22 , sizeof( * V_157 ) ) ;
V_22 = V_157 ;
}
V_22 -> V_152 -= F_70 ( V_22 -> V_128 ) ;
V_22 -> V_128 = NULL ;
}
return V_22 ;
}
struct V_25 * F_86 ( struct V_158 * V_159 ,
const struct V_127 * V_22 ,
struct V_25 * V_160 )
{
if ( ! V_22 || ! V_22 -> V_72 )
return NULL ;
* V_160 = V_159 -> V_4 ;
switch ( V_22 -> V_72 -> type ) {
case V_123 :
case V_124 :
case V_89 :
V_159 -> V_4 = * ( (struct V_82 * ) V_22 -> V_72 ) -> V_32 ;
break;
case V_88 :
{
struct V_52 * V_161 = (struct V_52 * ) V_22 -> V_72 ;
V_159 -> V_4 = V_161 -> V_56 [ V_161 -> V_121 ] ;
break;
}
default:
return NULL ;
}
return V_160 ;
}
