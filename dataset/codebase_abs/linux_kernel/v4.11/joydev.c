static int F_1 ( int V_1 , struct V_2 * V_3 )
{
switch ( V_3 -> type ) {
case V_4 :
break;
case V_5 :
V_1 = V_1 > V_3 -> V_6 [ 0 ] ? ( V_1 < V_3 -> V_6 [ 1 ] ? 0 :
( ( V_3 -> V_6 [ 3 ] * ( V_1 - V_3 -> V_6 [ 1 ] ) ) >> 14 ) ) :
( ( V_3 -> V_6 [ 2 ] * ( V_1 - V_3 -> V_6 [ 0 ] ) ) >> 14 ) ;
break;
default:
return 0 ;
}
return F_2 ( V_1 , - 32767 , 32767 ) ;
}
static void F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_11 = V_8 -> V_11 ;
F_4 ( & V_8 -> V_12 ) ;
V_8 -> V_13 [ V_8 -> V_14 ] = * V_10 ;
if ( V_8 -> V_15 == V_11 -> V_16 + V_11 -> V_17 ) {
V_8 -> V_14 ++ ;
V_8 -> V_14 &= V_18 - 1 ;
if ( V_8 -> V_19 == V_8 -> V_14 )
V_8 -> V_15 = 0 ;
}
F_5 ( & V_8 -> V_12 ) ;
F_6 ( & V_8 -> V_20 , V_21 , V_22 ) ;
}
static void F_7 ( struct V_23 * V_24 ,
unsigned int type , unsigned int V_25 , int V_1 )
{
struct V_11 * V_11 = V_24 -> V_26 ;
struct V_7 * V_8 ;
struct V_9 V_10 ;
switch ( type ) {
case V_27 :
if ( V_25 < V_28 || V_1 == 2 )
return;
V_10 . type = V_29 ;
V_10 . V_30 = V_11 -> V_31 [ V_25 - V_28 ] ;
V_10 . V_1 = V_1 ;
break;
case V_32 :
V_10 . type = V_33 ;
V_10 . V_30 = V_11 -> V_34 [ V_25 ] ;
V_10 . V_1 = F_1 ( V_1 ,
& V_11 -> V_3 [ V_10 . V_30 ] ) ;
if ( V_10 . V_1 == V_11 -> abs [ V_10 . V_30 ] )
return;
V_11 -> abs [ V_10 . V_30 ] = V_10 . V_1 ;
break;
default:
return;
}
V_10 . time = F_8 ( V_35 ) ;
F_9 () ;
F_10 (client, &joydev->client_list, node)
F_3 ( V_8 , & V_10 ) ;
F_11 () ;
F_12 ( & V_11 -> V_36 ) ;
}
static int F_13 ( int V_37 , struct V_38 * V_38 , int V_39 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
return F_14 ( V_37 , V_38 , V_39 , & V_8 -> V_20 ) ;
}
static void F_15 ( struct V_41 * V_42 )
{
struct V_11 * V_11 = F_16 ( V_42 , struct V_11 , V_42 ) ;
F_17 ( V_11 -> V_24 . V_42 ) ;
F_18 ( V_11 ) ;
}
static void F_19 ( struct V_11 * V_11 ,
struct V_7 * V_8 )
{
F_4 ( & V_11 -> V_43 ) ;
F_20 ( & V_8 -> V_44 , & V_11 -> V_45 ) ;
F_5 ( & V_11 -> V_43 ) ;
}
static void F_21 ( struct V_11 * V_11 ,
struct V_7 * V_8 )
{
F_4 ( & V_11 -> V_43 ) ;
F_22 ( & V_8 -> V_44 ) ;
F_5 ( & V_11 -> V_43 ) ;
F_23 () ;
}
static void F_24 ( struct V_11 * V_11 )
{
struct V_46 * V_42 = V_11 -> V_24 . V_42 ;
int V_47 , V_48 ;
for ( V_47 = 0 ; V_47 < V_11 -> V_16 ; V_47 ++ ) {
V_48 = F_25 ( V_42 , V_11 -> V_49 [ V_47 ] ) ;
V_11 -> abs [ V_47 ] = F_1 ( V_48 , & V_11 -> V_3 [ V_47 ] ) ;
}
}
static int F_26 ( struct V_11 * V_11 )
{
int V_50 ;
V_50 = F_27 ( & V_11 -> V_51 ) ;
if ( V_50 )
return V_50 ;
if ( ! V_11 -> V_52 )
V_50 = - V_53 ;
else if ( ! V_11 -> V_54 ++ ) {
V_50 = F_28 ( & V_11 -> V_24 ) ;
if ( V_50 )
V_11 -> V_54 -- ;
else
F_24 ( V_11 ) ;
}
F_29 ( & V_11 -> V_51 ) ;
return V_50 ;
}
static void F_30 ( struct V_11 * V_11 )
{
F_31 ( & V_11 -> V_51 ) ;
if ( V_11 -> V_52 && ! -- V_11 -> V_54 )
F_32 ( & V_11 -> V_24 ) ;
F_29 ( & V_11 -> V_51 ) ;
}
static void F_33 ( struct V_11 * V_11 )
{
struct V_7 * V_8 ;
F_4 ( & V_11 -> V_43 ) ;
F_34 (client, &joydev->client_list, node)
F_6 ( & V_8 -> V_20 , V_21 , V_55 ) ;
F_5 ( & V_11 -> V_43 ) ;
F_12 ( & V_11 -> V_36 ) ;
}
static int F_35 ( struct V_56 * V_56 , struct V_38 * V_38 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
struct V_11 * V_11 = V_8 -> V_11 ;
F_21 ( V_11 , V_8 ) ;
F_18 ( V_8 ) ;
F_30 ( V_11 ) ;
return 0 ;
}
static int F_36 ( struct V_56 * V_56 , struct V_38 * V_38 )
{
struct V_11 * V_11 =
F_16 ( V_56 -> V_57 , struct V_11 , V_58 ) ;
struct V_7 * V_8 ;
int error ;
V_8 = F_37 ( sizeof( struct V_7 ) , V_59 ) ;
if ( ! V_8 )
return - V_60 ;
F_38 ( & V_8 -> V_12 ) ;
V_8 -> V_11 = V_11 ;
F_19 ( V_11 , V_8 ) ;
error = F_26 ( V_11 ) ;
if ( error )
goto V_61;
V_38 -> V_40 = V_8 ;
F_39 ( V_56 , V_38 ) ;
return 0 ;
V_61:
F_21 ( V_11 , V_8 ) ;
F_18 ( V_8 ) ;
return error ;
}
static int F_40 ( struct V_7 * V_8 ,
struct V_46 * V_62 ,
struct V_9 * V_10 )
{
struct V_11 * V_11 = V_8 -> V_11 ;
int V_63 ;
F_41 ( & V_8 -> V_12 ) ;
V_63 = V_8 -> V_15 < V_11 -> V_16 + V_11 -> V_17 ;
if ( V_63 ) {
V_10 -> time = F_8 ( V_35 ) ;
if ( V_8 -> V_15 < V_11 -> V_17 ) {
V_10 -> type = V_29 | V_64 ;
V_10 -> V_30 = V_8 -> V_15 ;
V_10 -> V_1 = ! ! F_42 ( V_11 -> V_65 [ V_10 -> V_30 ] ,
V_62 -> V_66 ) ;
} else {
V_10 -> type = V_33 | V_64 ;
V_10 -> V_30 = V_8 -> V_15 - V_11 -> V_17 ;
V_10 -> V_1 = V_11 -> abs [ V_10 -> V_30 ] ;
}
V_8 -> V_15 ++ ;
}
F_43 ( & V_8 -> V_12 ) ;
return V_63 ;
}
static int F_44 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
int V_63 ;
F_41 ( & V_8 -> V_12 ) ;
V_63 = V_8 -> V_14 != V_8 -> V_19 ;
if ( V_63 ) {
* V_10 = V_8 -> V_13 [ V_8 -> V_19 ++ ] ;
V_8 -> V_19 &= V_18 - 1 ;
}
F_43 ( & V_8 -> V_12 ) ;
return V_63 ;
}
static T_1 F_45 ( struct V_7 * V_8 ,
struct V_46 * V_62 ,
char T_2 * V_67 )
{
struct V_11 * V_11 = V_8 -> V_11 ;
struct V_68 V_69 ;
int V_47 ;
F_41 ( & V_62 -> V_70 ) ;
for ( V_69 . V_71 = V_47 = 0 ; V_47 < 32 && V_47 < V_11 -> V_17 ; V_47 ++ )
V_69 . V_71 |=
F_42 ( V_11 -> V_65 [ V_47 ] , V_62 -> V_66 ) ? ( 1 << V_47 ) : 0 ;
V_69 . V_72 = ( V_11 -> abs [ 0 ] / 256 + 128 ) >> V_11 -> V_73 . V_74 . V_72 ;
V_69 . V_75 = ( V_11 -> abs [ 1 ] / 256 + 128 ) >> V_11 -> V_73 . V_74 . V_75 ;
F_4 ( & V_8 -> V_12 ) ;
V_8 -> V_15 = 0 ;
V_8 -> V_19 = V_8 -> V_14 ;
F_5 ( & V_8 -> V_12 ) ;
F_43 ( & V_62 -> V_70 ) ;
if ( F_46 ( V_67 , & V_69 , sizeof( struct V_68 ) ) )
return - V_76 ;
return sizeof( struct V_68 ) ;
}
static inline int F_47 ( struct V_7 * V_8 )
{
struct V_11 * V_11 = V_8 -> V_11 ;
return V_8 -> V_15 < V_11 -> V_16 + V_11 -> V_17 ||
V_8 -> V_14 != V_8 -> V_19 ;
}
static T_1 F_48 ( struct V_38 * V_38 , char T_2 * V_67 ,
T_3 V_77 , T_4 * V_78 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
struct V_11 * V_11 = V_8 -> V_11 ;
struct V_46 * V_62 = V_11 -> V_24 . V_42 ;
struct V_9 V_10 ;
int V_50 ;
if ( ! V_11 -> V_52 )
return - V_53 ;
if ( V_77 < sizeof( struct V_9 ) )
return - V_79 ;
if ( V_77 == sizeof( struct V_68 ) )
return F_45 ( V_8 , V_62 , V_67 ) ;
if ( ! F_47 ( V_8 ) && ( V_38 -> V_80 & V_81 ) )
return - V_82 ;
V_50 = F_49 ( V_11 -> V_36 ,
! V_11 -> V_52 || F_47 ( V_8 ) ) ;
if ( V_50 )
return V_50 ;
if ( ! V_11 -> V_52 )
return - V_53 ;
while ( V_50 + sizeof( struct V_9 ) <= V_77 &&
F_40 ( V_8 , V_62 , & V_10 ) ) {
if ( F_46 ( V_67 + V_50 , & V_10 , sizeof( struct V_9 ) ) )
return - V_76 ;
V_50 += sizeof( struct V_9 ) ;
}
while ( V_50 + sizeof( struct V_9 ) <= V_77 &&
F_44 ( V_8 , & V_10 ) ) {
if ( F_46 ( V_67 + V_50 , & V_10 , sizeof( struct V_9 ) ) )
return - V_76 ;
V_50 += sizeof( struct V_9 ) ;
}
return V_50 ;
}
static unsigned int F_50 ( struct V_38 * V_38 , T_5 * V_36 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
struct V_11 * V_11 = V_8 -> V_11 ;
F_51 ( V_38 , & V_11 -> V_36 , V_36 ) ;
return ( F_47 ( V_8 ) ? ( V_83 | V_84 ) : 0 ) |
( V_11 -> V_52 ? 0 : ( V_85 | V_86 ) ) ;
}
static int F_52 ( struct V_11 * V_11 ,
void T_2 * V_87 , T_3 V_88 )
{
T_6 * V_49 ;
int V_47 ;
int V_50 = 0 ;
V_88 = F_53 ( V_88 , sizeof( V_11 -> V_49 ) ) ;
V_49 = F_54 ( V_87 , V_88 ) ;
if ( F_55 ( V_49 ) )
return F_56 ( V_49 ) ;
for ( V_47 = 0 ; V_47 < V_11 -> V_16 ; V_47 ++ ) {
if ( V_49 [ V_47 ] > V_89 ) {
V_50 = - V_79 ;
goto V_90;
}
}
memcpy ( V_11 -> V_49 , V_49 , V_88 ) ;
for ( V_47 = 0 ; V_47 < V_11 -> V_16 ; V_47 ++ )
V_11 -> V_34 [ V_11 -> V_49 [ V_47 ] ] = V_47 ;
V_90:
F_18 ( V_49 ) ;
return V_50 ;
}
static int F_57 ( struct V_11 * V_11 ,
void T_2 * V_87 , T_3 V_88 )
{
T_7 * V_65 ;
int V_47 ;
int V_50 = 0 ;
V_88 = F_53 ( V_88 , sizeof( V_11 -> V_65 ) ) ;
V_65 = F_54 ( V_87 , V_88 ) ;
if ( F_55 ( V_65 ) )
return F_56 ( V_65 ) ;
for ( V_47 = 0 ; V_47 < V_11 -> V_17 ; V_47 ++ ) {
if ( V_65 [ V_47 ] > V_91 || V_65 [ V_47 ] < V_28 ) {
V_50 = - V_79 ;
goto V_90;
}
}
memcpy ( V_11 -> V_65 , V_65 , V_88 ) ;
for ( V_47 = 0 ; V_47 < V_11 -> V_17 ; V_47 ++ )
V_11 -> V_31 [ V_65 [ V_47 ] - V_28 ] = V_47 ;
V_90:
F_18 ( V_65 ) ;
return V_50 ;
}
static int F_58 ( struct V_11 * V_11 ,
unsigned int V_92 , void T_2 * V_87 )
{
struct V_46 * V_42 = V_11 -> V_24 . V_42 ;
T_3 V_88 ;
int V_47 ;
const char * V_93 ;
switch ( V_92 ) {
case V_94 :
return F_59 ( & V_11 -> V_73 . V_74 , V_87 ,
sizeof( V_11 -> V_73 . V_74 ) ) ? - V_76 : 0 ;
case V_95 :
return F_46 ( V_87 , & V_11 -> V_73 . V_74 ,
sizeof( V_11 -> V_73 . V_74 ) ) ? - V_76 : 0 ;
case V_96 :
return F_60 ( V_11 -> V_73 . V_97 , ( V_98 T_2 * ) V_87 ) ;
case V_99 :
return F_61 ( V_11 -> V_73 . V_97 , ( V_98 T_2 * ) V_87 ) ;
case V_100 :
return F_61 ( V_101 , ( V_102 T_2 * ) V_87 ) ;
case V_103 :
return F_61 ( V_11 -> V_16 , ( T_6 T_2 * ) V_87 ) ;
case V_104 :
return F_61 ( V_11 -> V_17 , ( T_6 T_2 * ) V_87 ) ;
case V_105 :
if ( F_59 ( V_11 -> V_3 , V_87 ,
sizeof( V_11 -> V_3 [ 0 ] ) * V_11 -> V_16 ) )
return - V_76 ;
for ( V_47 = 0 ; V_47 < V_11 -> V_16 ; V_47 ++ ) {
int V_48 = F_25 ( V_42 , V_11 -> V_49 [ V_47 ] ) ;
V_11 -> abs [ V_47 ] = F_1 ( V_48 , & V_11 -> V_3 [ V_47 ] ) ;
}
return 0 ;
case V_106 :
return F_46 ( V_87 , V_11 -> V_3 ,
sizeof( V_11 -> V_3 [ 0 ] ) * V_11 -> V_16 ) ? - V_76 : 0 ;
}
switch ( V_92 & ~ V_107 ) {
case ( V_108 & ~ V_107 ) :
return F_52 ( V_11 , V_87 , F_62 ( V_92 ) ) ;
case ( V_109 & ~ V_107 ) :
V_88 = F_63 ( T_3 , F_62 ( V_92 ) , sizeof( V_11 -> V_49 ) ) ;
return F_46 ( V_87 , V_11 -> V_49 , V_88 ) ? - V_76 : V_88 ;
case ( V_110 & ~ V_107 ) :
return F_57 ( V_11 , V_87 , F_62 ( V_92 ) ) ;
case ( V_111 & ~ V_107 ) :
V_88 = F_63 ( T_3 , F_62 ( V_92 ) , sizeof( V_11 -> V_65 ) ) ;
return F_46 ( V_87 , V_11 -> V_65 , V_88 ) ? - V_76 : V_88 ;
case F_64 ( 0 ) :
V_93 = V_42 -> V_93 ;
if ( ! V_93 )
return 0 ;
V_88 = F_63 ( T_3 , F_62 ( V_92 ) , strlen ( V_93 ) + 1 ) ;
return F_46 ( V_87 , V_93 , V_88 ) ? - V_76 : V_88 ;
}
return - V_79 ;
}
static long F_65 ( struct V_38 * V_38 ,
unsigned int V_92 , unsigned long V_112 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
struct V_11 * V_11 = V_8 -> V_11 ;
void T_2 * V_87 = ( void T_2 * ) V_112 ;
V_98 V_113 ;
struct V_114 V_115 ;
int V_50 ;
V_50 = F_27 ( & V_11 -> V_51 ) ;
if ( V_50 )
return V_50 ;
if ( ! V_11 -> V_52 ) {
V_50 = - V_53 ;
goto V_90;
}
switch ( V_92 ) {
case V_116 :
V_50 = F_60 ( V_113 , ( V_98 T_2 * ) V_112 ) ;
if ( V_50 == 0 )
V_11 -> V_73 . V_117 = V_113 ;
break;
case V_118 :
V_113 = V_11 -> V_73 . V_117 ;
V_50 = F_61 ( V_113 , ( V_98 T_2 * ) V_112 ) ;
break;
case V_119 :
V_50 = F_59 ( & V_115 , V_87 ,
sizeof( V_115 ) ) ? - V_76 : 0 ;
if ( V_50 == 0 ) {
V_11 -> V_73 . V_97 = V_115 . V_97 ;
V_11 -> V_73 . V_120 = V_115 . V_120 ;
V_11 -> V_73 . V_121 = V_115 . V_121 ;
V_11 -> V_73 . V_117 = V_115 . V_117 ;
V_11 -> V_73 . V_122 = V_115 . V_122 ;
V_11 -> V_73 . V_74 = V_115 . V_74 ;
}
break;
case V_123 :
V_115 . V_97 = V_11 -> V_73 . V_97 ;
V_115 . V_120 = V_11 -> V_73 . V_120 ;
V_115 . V_121 = V_11 -> V_73 . V_121 ;
V_115 . V_117 = V_11 -> V_73 . V_117 ;
V_115 . V_122 = V_11 -> V_73 . V_122 ;
V_115 . V_74 = V_11 -> V_73 . V_74 ;
V_50 = F_46 ( V_87 , & V_115 , sizeof( V_115 ) ) ? - V_76 : 0 ;
break;
default:
V_50 = F_58 ( V_11 , V_92 , V_87 ) ;
break;
}
V_90:
F_29 ( & V_11 -> V_51 ) ;
return V_50 ;
}
static long F_66 ( struct V_38 * V_38 ,
unsigned int V_92 , unsigned long V_112 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
struct V_11 * V_11 = V_8 -> V_11 ;
void T_2 * V_87 = ( void T_2 * ) V_112 ;
int V_50 ;
V_50 = F_27 ( & V_11 -> V_51 ) ;
if ( V_50 )
return V_50 ;
if ( ! V_11 -> V_52 ) {
V_50 = - V_53 ;
goto V_90;
}
switch ( V_92 ) {
case V_116 :
V_50 = F_60 ( V_11 -> V_73 . V_117 ,
( long T_2 * ) V_112 ) ;
break;
case V_118 :
V_50 = F_61 ( V_11 -> V_73 . V_117 ,
( long T_2 * ) V_112 ) ;
break;
case V_119 :
V_50 = F_59 ( & V_11 -> V_73 , V_87 ,
sizeof( V_11 -> V_73 ) ) ? - V_76 : 0 ;
break;
case V_123 :
V_50 = F_46 ( V_87 , & V_11 -> V_73 ,
sizeof( V_11 -> V_73 ) ) ? - V_76 : 0 ;
break;
default:
V_50 = F_58 ( V_11 , V_92 , V_87 ) ;
break;
}
V_90:
F_29 ( & V_11 -> V_51 ) ;
return V_50 ;
}
static void F_67 ( struct V_11 * V_11 )
{
F_31 ( & V_11 -> V_51 ) ;
V_11 -> V_52 = false ;
F_29 ( & V_11 -> V_51 ) ;
}
static void F_68 ( struct V_11 * V_11 )
{
struct V_23 * V_24 = & V_11 -> V_24 ;
F_67 ( V_11 ) ;
F_33 ( V_11 ) ;
F_69 ( & V_11 -> V_58 ) ;
if ( V_11 -> V_54 )
F_32 ( V_24 ) ;
}
static bool F_70 ( struct V_46 * V_42 )
{
F_71 ( V_124 , V_125 ) ;
F_72 ( V_126 > V_125 || V_127 > V_125 ) ;
F_73 ( V_124 , V_127 ) ;
F_74 ( V_32 , V_124 ) ;
F_74 ( V_27 , V_124 ) ;
F_74 ( V_128 , V_124 ) ;
if ( ! F_75 ( V_124 , V_42 -> V_129 , V_127 ) )
return false ;
F_73 ( V_124 , V_126 ) ;
F_74 ( V_130 , V_124 ) ;
F_74 ( V_131 , V_124 ) ;
if ( ! F_75 ( V_42 -> V_132 , V_124 , V_126 ) )
return false ;
F_73 ( V_124 , V_125 ) ;
F_74 ( V_133 , V_124 ) ;
F_74 ( V_134 , V_124 ) ;
F_74 ( V_135 , V_124 ) ;
if ( ! F_75 ( V_42 -> V_136 , V_124 , V_125 ) )
return false ;
if ( V_42 -> V_137 . V_138 == V_139 )
return false ;
return true ;
}
static bool F_76 ( struct V_140 * V_141 , struct V_46 * V_42 )
{
if ( F_42 ( V_27 , V_42 -> V_129 ) && F_42 ( V_142 , V_42 -> V_136 ) )
return false ;
if ( F_42 ( V_27 , V_42 -> V_129 ) && F_42 ( V_143 , V_42 -> V_136 ) )
return false ;
if ( F_70 ( V_42 ) )
return false ;
return true ;
}
static int F_77 ( struct V_140 * V_141 , struct V_46 * V_42 ,
const struct V_144 * V_137 )
{
struct V_11 * V_11 ;
int V_47 , V_145 , V_146 , V_147 , V_148 ;
int error ;
V_147 = F_78 ( V_149 , V_150 , true ) ;
if ( V_147 < 0 ) {
error = V_147 ;
F_79 ( L_1 , error ) ;
return error ;
}
V_11 = F_37 ( sizeof( struct V_11 ) , V_59 ) ;
if ( ! V_11 ) {
error = - V_60 ;
goto V_151;
}
F_80 ( & V_11 -> V_45 ) ;
F_38 ( & V_11 -> V_43 ) ;
F_81 ( & V_11 -> V_51 ) ;
F_82 ( & V_11 -> V_36 ) ;
V_11 -> V_52 = true ;
V_148 = V_147 ;
if ( V_148 < V_149 + V_150 )
V_148 -= V_149 ;
F_83 ( & V_11 -> V_42 , L_2 , V_148 ) ;
V_11 -> V_24 . V_42 = F_84 ( V_42 ) ;
V_11 -> V_24 . V_93 = F_85 ( & V_11 -> V_42 ) ;
V_11 -> V_24 . V_141 = V_141 ;
V_11 -> V_24 . V_26 = V_11 ;
F_86 (i, dev->absbit, ABS_CNT) {
V_11 -> V_34 [ V_47 ] = V_11 -> V_16 ;
V_11 -> V_49 [ V_11 -> V_16 ] = V_47 ;
V_11 -> V_16 ++ ;
}
for ( V_47 = V_152 - V_28 ; V_47 < V_91 - V_28 + 1 ; V_47 ++ )
if ( F_42 ( V_47 + V_28 , V_42 -> V_136 ) ) {
V_11 -> V_31 [ V_47 ] = V_11 -> V_17 ;
V_11 -> V_65 [ V_11 -> V_17 ] = V_47 + V_28 ;
V_11 -> V_17 ++ ;
}
for ( V_47 = 0 ; V_47 < V_152 - V_28 ; V_47 ++ )
if ( F_42 ( V_47 + V_28 , V_42 -> V_136 ) ) {
V_11 -> V_31 [ V_47 ] = V_11 -> V_17 ;
V_11 -> V_65 [ V_11 -> V_17 ] = V_47 + V_28 ;
V_11 -> V_17 ++ ;
}
for ( V_47 = 0 ; V_47 < V_11 -> V_16 ; V_47 ++ ) {
V_145 = V_11 -> V_49 [ V_47 ] ;
if ( F_87 ( V_42 , V_145 ) == F_88 ( V_42 , V_145 ) ) {
V_11 -> V_3 [ V_47 ] . type = V_4 ;
continue;
}
V_11 -> V_3 [ V_47 ] . type = V_5 ;
V_11 -> V_3 [ V_47 ] . V_153 = F_89 ( V_42 , V_145 ) ;
V_146 = ( F_87 ( V_42 , V_145 ) + F_88 ( V_42 , V_145 ) ) / 2 ;
V_11 -> V_3 [ V_47 ] . V_6 [ 0 ] = V_146 - F_90 ( V_42 , V_145 ) ;
V_11 -> V_3 [ V_47 ] . V_6 [ 1 ] = V_146 + F_90 ( V_42 , V_145 ) ;
V_146 = ( F_87 ( V_42 , V_145 ) - F_88 ( V_42 , V_145 ) ) / 2
- 2 * F_90 ( V_42 , V_145 ) ;
if ( V_146 ) {
V_11 -> V_3 [ V_47 ] . V_6 [ 2 ] = ( 1 << 29 ) / V_146 ;
V_11 -> V_3 [ V_47 ] . V_6 [ 3 ] = ( 1 << 29 ) / V_146 ;
}
}
V_11 -> V_42 . V_154 = F_91 ( V_155 , V_147 ) ;
V_11 -> V_42 . V_156 = & V_157 ;
V_11 -> V_42 . V_158 = & V_42 -> V_42 ;
V_11 -> V_42 . V_159 = F_15 ;
F_92 ( & V_11 -> V_42 ) ;
error = F_93 ( & V_11 -> V_24 ) ;
if ( error )
goto V_160;
F_94 ( & V_11 -> V_58 , & V_161 ) ;
V_11 -> V_58 . V_162 . V_158 = & V_11 -> V_42 . V_162 ;
error = F_95 ( & V_11 -> V_58 , V_11 -> V_42 . V_154 , 1 ) ;
if ( error )
goto V_163;
error = F_96 ( & V_11 -> V_42 ) ;
if ( error )
goto V_164;
return 0 ;
V_164:
F_68 ( V_11 ) ;
V_163:
F_97 ( & V_11 -> V_24 ) ;
V_160:
F_98 ( & V_11 -> V_42 ) ;
V_151:
F_99 ( V_147 ) ;
return error ;
}
static void F_100 ( struct V_23 * V_24 )
{
struct V_11 * V_11 = V_24 -> V_26 ;
F_101 ( & V_11 -> V_42 ) ;
F_68 ( V_11 ) ;
F_99 ( F_102 ( V_11 -> V_42 . V_154 ) ) ;
F_97 ( V_24 ) ;
F_98 ( & V_11 -> V_42 ) ;
}
static int T_8 F_103 ( void )
{
return F_104 ( & V_165 ) ;
}
static void T_9 F_105 ( void )
{
F_106 ( & V_165 ) ;
}
