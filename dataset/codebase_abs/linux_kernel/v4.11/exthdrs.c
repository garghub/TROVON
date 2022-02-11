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
V_22 -> V_75 |= V_108 ;
if ( F_7 ( V_109 , V_2 ) ) {
V_2 -> V_50 += ( F_9 ( V_2 ) [ 1 ] + 1 ) << 3 ;
V_22 = F_13 ( V_2 ) ;
V_22 -> V_51 = sizeof( struct V_23 ) ;
return 1 ;
}
return - 1 ;
}
static void F_62 ( struct V_1 * V_2 , T_5 * V_110 ,
struct V_81 * V_22 ,
struct V_25 * * V_111 , struct V_25 * V_40 )
{
struct V_82 * V_112 , * V_113 ;
int V_114 ;
V_113 = (struct V_82 * ) V_22 ;
V_112 = (struct V_82 * ) F_41 ( V_2 , ( V_113 -> V_115 . V_70 + 1 ) << 3 ) ;
memcpy ( V_112 , V_113 , sizeof( struct V_82 ) ) ;
V_114 = V_113 -> V_115 . V_70 >> 1 ;
if ( V_114 > 1 )
memcpy ( V_112 -> V_32 , V_113 -> V_32 + 1 ,
( V_114 - 1 ) * sizeof( struct V_25 ) ) ;
V_112 -> V_32 [ V_114 - 1 ] = * * V_111 ;
* V_111 = V_113 -> V_32 ;
V_112 -> V_115 . V_67 = * V_110 ;
* V_110 = V_116 ;
}
static void F_63 ( struct V_1 * V_2 , T_5 * V_110 ,
struct V_81 * V_22 ,
struct V_25 * * V_111 , struct V_25 * V_40 )
{
struct V_52 * V_117 , * V_118 ;
int V_119 , V_114 ;
V_118 = (struct V_52 * ) V_22 ;
V_119 = ( V_118 -> V_70 + 1 ) << 3 ;
V_117 = (struct V_52 * ) F_41 ( V_2 , V_119 ) ;
memcpy ( V_117 , V_118 , sizeof( struct V_52 ) ) ;
V_114 = V_118 -> V_120 + 1 ;
memcpy ( V_117 -> V_56 + 1 , V_118 -> V_56 + 1 ,
( V_114 - 1 ) * sizeof( struct V_25 ) ) ;
V_117 -> V_56 [ 0 ] = * * V_111 ;
* V_111 = & V_118 -> V_56 [ V_114 - 1 ] ;
#ifdef F_33
if ( F_64 ( V_117 ) ) {
struct V_58 * V_58 = NULL ;
if ( V_2 -> V_46 )
V_58 = F_26 ( V_2 -> V_46 ) ;
else if ( V_2 -> V_121 )
V_58 = F_65 ( V_2 -> V_121 ) ;
F_66 ( ! V_58 ) ;
if ( V_58 )
F_67 ( V_58 , V_40 , V_117 ) ;
}
#endif
V_117 -> V_67 = * V_110 ;
* V_110 = V_116 ;
}
static void F_68 ( struct V_1 * V_2 , T_5 * V_110 ,
struct V_81 * V_22 ,
struct V_25 * * V_111 , struct V_25 * V_40 )
{
switch ( V_22 -> type ) {
case V_122 :
case V_123 :
case V_89 :
F_62 ( V_2 , V_110 , V_22 , V_111 , V_40 ) ;
break;
case V_88 :
F_63 ( V_2 , V_110 , V_22 , V_111 , V_40 ) ;
break;
default:
break;
}
}
static void F_69 ( struct V_1 * V_2 , T_5 * V_110 , T_5 type , struct V_124 * V_22 )
{
struct V_124 * V_125 = (struct V_124 * ) F_41 ( V_2 , F_70 ( V_22 ) ) ;
memcpy ( V_125 , V_22 , F_70 ( V_22 ) ) ;
V_125 -> V_67 = * V_110 ;
* V_110 = type ;
}
void F_71 ( struct V_1 * V_2 , struct V_126 * V_22 ,
T_5 * V_110 ,
struct V_25 * * V_4 , struct V_25 * V_40 )
{
if ( V_22 -> V_72 ) {
F_68 ( V_2 , V_110 , V_22 -> V_72 , V_4 , V_40 ) ;
if ( V_22 -> V_127 )
F_69 ( V_2 , V_110 , V_128 , V_22 -> V_127 ) ;
}
if ( V_22 -> V_129 )
F_69 ( V_2 , V_110 , V_130 , V_22 -> V_129 ) ;
}
void F_72 ( struct V_1 * V_2 , struct V_126 * V_22 , T_5 * V_110 )
{
if ( V_22 -> V_131 )
F_69 ( V_2 , V_110 , V_128 , V_22 -> V_131 ) ;
}
struct V_126 *
F_73 ( struct V_132 * V_121 , struct V_126 * V_22 )
{
struct V_126 * V_133 ;
V_133 = F_74 ( V_121 , V_22 -> V_134 , V_36 ) ;
if ( V_133 ) {
long V_135 = ( char * ) V_133 - ( char * ) V_22 ;
memcpy ( V_133 , V_22 , V_22 -> V_134 ) ;
if ( V_133 -> V_129 )
* ( ( char * * ) & V_133 -> V_129 ) += V_135 ;
if ( V_133 -> V_127 )
* ( ( char * * ) & V_133 -> V_127 ) += V_135 ;
if ( V_133 -> V_131 )
* ( ( char * * ) & V_133 -> V_131 ) += V_135 ;
if ( V_133 -> V_72 )
* ( ( char * * ) & V_133 -> V_72 ) += V_135 ;
F_75 ( & V_133 -> V_136 , 1 ) ;
}
return V_133 ;
}
static int F_76 ( void * V_137 ,
struct V_124 T_6 * V_138 , int V_139 ,
int V_140 ,
struct V_124 * * V_53 ,
char * * V_141 )
{
if ( V_140 ) {
if ( V_137 ) {
memcpy ( * V_141 , V_137 , F_70 ( (struct V_124 * ) V_137 ) ) ;
* V_53 = (struct V_124 * ) * V_141 ;
* V_141 += F_77 ( F_70 ( * V_53 ) ) ;
}
} else {
if ( V_138 ) {
if ( F_78 ( * V_141 , V_138 , V_139 ) )
return - V_142 ;
* V_53 = (struct V_124 * ) * V_141 ;
if ( F_70 ( * V_53 ) > V_139 )
return - V_143 ;
* V_141 += F_77 ( V_139 ) ;
}
}
return 0 ;
}
struct V_126 *
F_79 ( struct V_132 * V_121 , struct V_126 * V_22 ,
int V_144 ,
struct V_124 T_6 * V_138 , int V_139 )
{
int V_134 = 0 ;
char * V_141 ;
struct V_126 * V_133 ;
int V_145 ;
if ( V_22 ) {
if ( V_144 != V_146 && V_22 -> V_129 )
V_134 += F_77 ( F_70 ( V_22 -> V_129 ) ) ;
if ( V_144 != V_147 && V_22 -> V_127 )
V_134 += F_77 ( F_70 ( V_22 -> V_127 ) ) ;
if ( V_144 != V_148 && V_22 -> V_72 )
V_134 += F_77 ( F_70 ( V_22 -> V_72 ) ) ;
if ( V_144 != V_149 && V_22 -> V_131 )
V_134 += F_77 ( F_70 ( V_22 -> V_131 ) ) ;
}
if ( V_138 && V_139 )
V_134 += F_77 ( V_139 ) ;
if ( ! V_134 )
return NULL ;
V_134 += sizeof( * V_133 ) ;
V_133 = F_74 ( V_121 , V_134 , V_36 ) ;
if ( ! V_133 )
return F_80 ( - V_150 ) ;
memset ( V_133 , 0 , V_134 ) ;
F_75 ( & V_133 -> V_136 , 1 ) ;
V_133 -> V_134 = V_134 ;
V_141 = ( char * ) ( V_133 + 1 ) ;
V_145 = F_76 ( V_22 ? V_22 -> V_129 : NULL , V_138 , V_139 ,
V_144 != V_146 ,
& V_133 -> V_129 , & V_141 ) ;
if ( V_145 )
goto V_95;
V_145 = F_76 ( V_22 ? V_22 -> V_127 : NULL , V_138 , V_139 ,
V_144 != V_147 ,
& V_133 -> V_127 , & V_141 ) ;
if ( V_145 )
goto V_95;
V_145 = F_76 ( V_22 ? V_22 -> V_72 : NULL , V_138 , V_139 ,
V_144 != V_148 ,
(struct V_124 * * ) & V_133 -> V_72 , & V_141 ) ;
if ( V_145 )
goto V_95;
V_145 = F_76 ( V_22 ? V_22 -> V_131 : NULL , V_138 , V_139 ,
V_144 != V_149 ,
& V_133 -> V_131 , & V_141 ) ;
if ( V_145 )
goto V_95;
V_133 -> V_151 = ( V_133 -> V_129 ? F_70 ( V_133 -> V_129 ) : 0 ) +
( V_133 -> V_127 ? F_70 ( V_133 -> V_127 ) : 0 ) +
( V_133 -> V_72 ? F_70 ( V_133 -> V_72 ) : 0 ) ;
V_133 -> V_152 = ( V_133 -> V_131 ? F_70 ( V_133 -> V_131 ) : 0 ) ;
return V_133 ;
V_95:
F_81 ( V_121 , V_133 , V_133 -> V_134 ) ;
return F_80 ( V_145 ) ;
}
struct V_126 *
F_82 ( struct V_132 * V_121 , struct V_126 * V_22 ,
int V_144 , struct V_124 * V_138 ,
int V_139 )
{
struct V_126 * V_153 ;
const T_7 V_154 = F_83 () ;
F_84 ( V_155 ) ;
V_153 = F_79 ( V_121 , V_22 , V_144 ,
(struct V_124 T_6 * ) V_138 ,
V_139 ) ;
F_84 ( V_154 ) ;
return V_153 ;
}
struct V_126 * F_85 ( struct V_126 * V_156 ,
struct V_126 * V_22 )
{
if ( V_22 && V_22 -> V_127 && ! V_22 -> V_72 ) {
if ( V_156 != V_22 ) {
memcpy ( V_156 , V_22 , sizeof( * V_156 ) ) ;
V_22 = V_156 ;
}
V_22 -> V_151 -= F_70 ( V_22 -> V_127 ) ;
V_22 -> V_127 = NULL ;
}
return V_22 ;
}
struct V_25 * F_86 ( struct V_157 * V_158 ,
const struct V_126 * V_22 ,
struct V_25 * V_159 )
{
if ( ! V_22 || ! V_22 -> V_72 )
return NULL ;
* V_159 = V_158 -> V_4 ;
switch ( V_22 -> V_72 -> type ) {
case V_122 :
case V_123 :
case V_89 :
V_158 -> V_4 = * ( (struct V_82 * ) V_22 -> V_72 ) -> V_32 ;
break;
case V_88 :
{
struct V_52 * V_160 = (struct V_52 * ) V_22 -> V_72 ;
V_158 -> V_4 = V_160 -> V_56 [ V_160 -> V_120 ] ;
break;
}
default:
return NULL ;
}
return V_159 ;
}
