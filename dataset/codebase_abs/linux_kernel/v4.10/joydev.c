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
return V_1 < - 32767 ? - 32767 : ( V_1 > 32767 ? 32767 : V_1 ) ;
}
static void F_2 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_11 = V_8 -> V_11 ;
F_3 ( & V_8 -> V_12 ) ;
V_8 -> V_13 [ V_8 -> V_14 ] = * V_10 ;
if ( V_8 -> V_15 == V_11 -> V_16 + V_11 -> V_17 ) {
V_8 -> V_14 ++ ;
V_8 -> V_14 &= V_18 - 1 ;
if ( V_8 -> V_19 == V_8 -> V_14 )
V_8 -> V_15 = 0 ;
}
F_4 ( & V_8 -> V_12 ) ;
F_5 ( & V_8 -> V_20 , V_21 , V_22 ) ;
}
static void F_6 ( struct V_23 * V_24 ,
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
V_10 . time = F_7 ( V_35 ) ;
F_8 () ;
F_9 (client, &joydev->client_list, node)
F_2 ( V_8 , & V_10 ) ;
F_10 () ;
F_11 ( & V_11 -> V_36 ) ;
}
static int F_12 ( int V_37 , struct V_38 * V_38 , int V_39 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
return F_13 ( V_37 , V_38 , V_39 , & V_8 -> V_20 ) ;
}
static void F_14 ( struct V_41 * V_42 )
{
struct V_11 * V_11 = F_15 ( V_42 , struct V_11 , V_42 ) ;
F_16 ( V_11 -> V_24 . V_42 ) ;
F_17 ( V_11 ) ;
}
static void F_18 ( struct V_11 * V_11 ,
struct V_7 * V_8 )
{
F_3 ( & V_11 -> V_43 ) ;
F_19 ( & V_8 -> V_44 , & V_11 -> V_45 ) ;
F_4 ( & V_11 -> V_43 ) ;
}
static void F_20 ( struct V_11 * V_11 ,
struct V_7 * V_8 )
{
F_3 ( & V_11 -> V_43 ) ;
F_21 ( & V_8 -> V_44 ) ;
F_4 ( & V_11 -> V_43 ) ;
F_22 () ;
}
static int F_23 ( struct V_11 * V_11 )
{
int V_46 ;
V_46 = F_24 ( & V_11 -> V_47 ) ;
if ( V_46 )
return V_46 ;
if ( ! V_11 -> V_48 )
V_46 = - V_49 ;
else if ( ! V_11 -> V_50 ++ ) {
V_46 = F_25 ( & V_11 -> V_24 ) ;
if ( V_46 )
V_11 -> V_50 -- ;
}
F_26 ( & V_11 -> V_47 ) ;
return V_46 ;
}
static void F_27 ( struct V_11 * V_11 )
{
F_28 ( & V_11 -> V_47 ) ;
if ( V_11 -> V_48 && ! -- V_11 -> V_50 )
F_29 ( & V_11 -> V_24 ) ;
F_26 ( & V_11 -> V_47 ) ;
}
static void F_30 ( struct V_11 * V_11 )
{
struct V_7 * V_8 ;
F_3 ( & V_11 -> V_43 ) ;
F_31 (client, &joydev->client_list, node)
F_5 ( & V_8 -> V_20 , V_21 , V_51 ) ;
F_4 ( & V_11 -> V_43 ) ;
F_11 ( & V_11 -> V_36 ) ;
}
static int F_32 ( struct V_52 * V_52 , struct V_38 * V_38 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
struct V_11 * V_11 = V_8 -> V_11 ;
F_20 ( V_11 , V_8 ) ;
F_17 ( V_8 ) ;
F_27 ( V_11 ) ;
return 0 ;
}
static int F_33 ( struct V_52 * V_52 , struct V_38 * V_38 )
{
struct V_11 * V_11 =
F_15 ( V_52 -> V_53 , struct V_11 , V_54 ) ;
struct V_7 * V_8 ;
int error ;
V_8 = F_34 ( sizeof( struct V_7 ) , V_55 ) ;
if ( ! V_8 )
return - V_56 ;
F_35 ( & V_8 -> V_12 ) ;
V_8 -> V_11 = V_11 ;
F_18 ( V_11 , V_8 ) ;
error = F_23 ( V_11 ) ;
if ( error )
goto V_57;
V_38 -> V_40 = V_8 ;
F_36 ( V_52 , V_38 ) ;
return 0 ;
V_57:
F_20 ( V_11 , V_8 ) ;
F_17 ( V_8 ) ;
return error ;
}
static int F_37 ( struct V_7 * V_8 ,
struct V_58 * V_59 ,
struct V_9 * V_10 )
{
struct V_11 * V_11 = V_8 -> V_11 ;
int V_60 ;
F_38 ( & V_8 -> V_12 ) ;
V_60 = V_8 -> V_15 < V_11 -> V_16 + V_11 -> V_17 ;
if ( V_60 ) {
V_10 -> time = F_7 ( V_35 ) ;
if ( V_8 -> V_15 < V_11 -> V_17 ) {
V_10 -> type = V_29 | V_61 ;
V_10 -> V_30 = V_8 -> V_15 ;
V_10 -> V_1 = ! ! F_39 ( V_11 -> V_62 [ V_10 -> V_30 ] ,
V_59 -> V_63 ) ;
} else {
V_10 -> type = V_33 | V_61 ;
V_10 -> V_30 = V_8 -> V_15 - V_11 -> V_17 ;
V_10 -> V_1 = V_11 -> abs [ V_10 -> V_30 ] ;
}
V_8 -> V_15 ++ ;
}
F_40 ( & V_8 -> V_12 ) ;
return V_60 ;
}
static int F_41 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
int V_60 ;
F_38 ( & V_8 -> V_12 ) ;
V_60 = V_8 -> V_14 != V_8 -> V_19 ;
if ( V_60 ) {
* V_10 = V_8 -> V_13 [ V_8 -> V_19 ++ ] ;
V_8 -> V_19 &= V_18 - 1 ;
}
F_40 ( & V_8 -> V_12 ) ;
return V_60 ;
}
static T_1 F_42 ( struct V_7 * V_8 ,
struct V_58 * V_59 ,
char T_2 * V_64 )
{
struct V_11 * V_11 = V_8 -> V_11 ;
struct V_65 V_66 ;
int V_67 ;
F_38 ( & V_59 -> V_68 ) ;
for ( V_66 . V_69 = V_67 = 0 ; V_67 < 32 && V_67 < V_11 -> V_17 ; V_67 ++ )
V_66 . V_69 |=
F_39 ( V_11 -> V_62 [ V_67 ] , V_59 -> V_63 ) ? ( 1 << V_67 ) : 0 ;
V_66 . V_70 = ( V_11 -> abs [ 0 ] / 256 + 128 ) >> V_11 -> V_71 . V_72 . V_70 ;
V_66 . V_73 = ( V_11 -> abs [ 1 ] / 256 + 128 ) >> V_11 -> V_71 . V_72 . V_73 ;
F_3 ( & V_8 -> V_12 ) ;
V_8 -> V_15 = 0 ;
V_8 -> V_19 = V_8 -> V_14 ;
F_4 ( & V_8 -> V_12 ) ;
F_40 ( & V_59 -> V_68 ) ;
if ( F_43 ( V_64 , & V_66 , sizeof( struct V_65 ) ) )
return - V_74 ;
return sizeof( struct V_65 ) ;
}
static inline int F_44 ( struct V_7 * V_8 )
{
struct V_11 * V_11 = V_8 -> V_11 ;
return V_8 -> V_15 < V_11 -> V_16 + V_11 -> V_17 ||
V_8 -> V_14 != V_8 -> V_19 ;
}
static T_1 F_45 ( struct V_38 * V_38 , char T_2 * V_64 ,
T_3 V_75 , T_4 * V_76 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
struct V_11 * V_11 = V_8 -> V_11 ;
struct V_58 * V_59 = V_11 -> V_24 . V_42 ;
struct V_9 V_10 ;
int V_46 ;
if ( ! V_11 -> V_48 )
return - V_49 ;
if ( V_75 < sizeof( struct V_9 ) )
return - V_77 ;
if ( V_75 == sizeof( struct V_65 ) )
return F_42 ( V_8 , V_59 , V_64 ) ;
if ( ! F_44 ( V_8 ) && ( V_38 -> V_78 & V_79 ) )
return - V_80 ;
V_46 = F_46 ( V_11 -> V_36 ,
! V_11 -> V_48 || F_44 ( V_8 ) ) ;
if ( V_46 )
return V_46 ;
if ( ! V_11 -> V_48 )
return - V_49 ;
while ( V_46 + sizeof( struct V_9 ) <= V_75 &&
F_37 ( V_8 , V_59 , & V_10 ) ) {
if ( F_43 ( V_64 + V_46 , & V_10 , sizeof( struct V_9 ) ) )
return - V_74 ;
V_46 += sizeof( struct V_9 ) ;
}
while ( V_46 + sizeof( struct V_9 ) <= V_75 &&
F_41 ( V_8 , & V_10 ) ) {
if ( F_43 ( V_64 + V_46 , & V_10 , sizeof( struct V_9 ) ) )
return - V_74 ;
V_46 += sizeof( struct V_9 ) ;
}
return V_46 ;
}
static unsigned int F_47 ( struct V_38 * V_38 , T_5 * V_36 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
struct V_11 * V_11 = V_8 -> V_11 ;
F_48 ( V_38 , & V_11 -> V_36 , V_36 ) ;
return ( F_44 ( V_8 ) ? ( V_81 | V_82 ) : 0 ) |
( V_11 -> V_48 ? 0 : ( V_83 | V_84 ) ) ;
}
static int F_49 ( struct V_11 * V_11 ,
void T_2 * V_85 , T_3 V_86 )
{
T_6 * V_87 ;
int V_67 ;
int V_46 = 0 ;
V_86 = F_50 ( V_86 , sizeof( V_11 -> V_87 ) ) ;
V_87 = F_51 ( V_85 , V_86 ) ;
if ( F_52 ( V_87 ) )
return F_53 ( V_87 ) ;
for ( V_67 = 0 ; V_67 < V_11 -> V_16 ; V_67 ++ ) {
if ( V_87 [ V_67 ] > V_88 ) {
V_46 = - V_77 ;
goto V_89;
}
}
memcpy ( V_11 -> V_87 , V_87 , V_86 ) ;
for ( V_67 = 0 ; V_67 < V_11 -> V_16 ; V_67 ++ )
V_11 -> V_34 [ V_11 -> V_87 [ V_67 ] ] = V_67 ;
V_89:
F_17 ( V_87 ) ;
return V_46 ;
}
static int F_54 ( struct V_11 * V_11 ,
void T_2 * V_85 , T_3 V_86 )
{
T_7 * V_62 ;
int V_67 ;
int V_46 = 0 ;
V_86 = F_50 ( V_86 , sizeof( V_11 -> V_62 ) ) ;
V_62 = F_51 ( V_85 , V_86 ) ;
if ( F_52 ( V_62 ) )
return F_53 ( V_62 ) ;
for ( V_67 = 0 ; V_67 < V_11 -> V_17 ; V_67 ++ ) {
if ( V_62 [ V_67 ] > V_90 || V_62 [ V_67 ] < V_28 ) {
V_46 = - V_77 ;
goto V_89;
}
}
memcpy ( V_11 -> V_62 , V_62 , V_86 ) ;
for ( V_67 = 0 ; V_67 < V_11 -> V_17 ; V_67 ++ )
V_11 -> V_31 [ V_62 [ V_67 ] - V_28 ] = V_67 ;
V_89:
F_17 ( V_62 ) ;
return V_46 ;
}
static int F_55 ( struct V_11 * V_11 ,
unsigned int V_91 , void T_2 * V_85 )
{
struct V_58 * V_42 = V_11 -> V_24 . V_42 ;
T_3 V_86 ;
int V_67 ;
const char * V_92 ;
switch ( V_91 ) {
case V_93 :
return F_56 ( & V_11 -> V_71 . V_72 , V_85 ,
sizeof( V_11 -> V_71 . V_72 ) ) ? - V_74 : 0 ;
case V_94 :
return F_43 ( V_85 , & V_11 -> V_71 . V_72 ,
sizeof( V_11 -> V_71 . V_72 ) ) ? - V_74 : 0 ;
case V_95 :
return F_57 ( V_11 -> V_71 . V_96 , ( V_97 T_2 * ) V_85 ) ;
case V_98 :
return F_58 ( V_11 -> V_71 . V_96 , ( V_97 T_2 * ) V_85 ) ;
case V_99 :
return F_58 ( V_100 , ( V_101 T_2 * ) V_85 ) ;
case V_102 :
return F_58 ( V_11 -> V_16 , ( T_6 T_2 * ) V_85 ) ;
case V_103 :
return F_58 ( V_11 -> V_17 , ( T_6 T_2 * ) V_85 ) ;
case V_104 :
if ( F_56 ( V_11 -> V_3 , V_85 ,
sizeof( V_11 -> V_3 [ 0 ] ) * V_11 -> V_16 ) )
return - V_74 ;
for ( V_67 = 0 ; V_67 < V_11 -> V_16 ; V_67 ++ ) {
int V_105 = F_59 ( V_42 , V_11 -> V_87 [ V_67 ] ) ;
V_11 -> abs [ V_67 ] = F_1 ( V_105 , & V_11 -> V_3 [ V_67 ] ) ;
}
return 0 ;
case V_106 :
return F_43 ( V_85 , V_11 -> V_3 ,
sizeof( V_11 -> V_3 [ 0 ] ) * V_11 -> V_16 ) ? - V_74 : 0 ;
}
switch ( V_91 & ~ V_107 ) {
case ( V_108 & ~ V_107 ) :
return F_49 ( V_11 , V_85 , F_60 ( V_91 ) ) ;
case ( V_109 & ~ V_107 ) :
V_86 = F_61 ( T_3 , F_60 ( V_91 ) , sizeof( V_11 -> V_87 ) ) ;
return F_43 ( V_85 , V_11 -> V_87 , V_86 ) ? - V_74 : V_86 ;
case ( V_110 & ~ V_107 ) :
return F_54 ( V_11 , V_85 , F_60 ( V_91 ) ) ;
case ( V_111 & ~ V_107 ) :
V_86 = F_61 ( T_3 , F_60 ( V_91 ) , sizeof( V_11 -> V_62 ) ) ;
return F_43 ( V_85 , V_11 -> V_62 , V_86 ) ? - V_74 : V_86 ;
case F_62 ( 0 ) :
V_92 = V_42 -> V_92 ;
if ( ! V_92 )
return 0 ;
V_86 = F_61 ( T_3 , F_60 ( V_91 ) , strlen ( V_92 ) + 1 ) ;
return F_43 ( V_85 , V_92 , V_86 ) ? - V_74 : V_86 ;
}
return - V_77 ;
}
static long F_63 ( struct V_38 * V_38 ,
unsigned int V_91 , unsigned long V_112 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
struct V_11 * V_11 = V_8 -> V_11 ;
void T_2 * V_85 = ( void T_2 * ) V_112 ;
V_97 V_113 ;
struct V_114 V_115 ;
int V_46 ;
V_46 = F_24 ( & V_11 -> V_47 ) ;
if ( V_46 )
return V_46 ;
if ( ! V_11 -> V_48 ) {
V_46 = - V_49 ;
goto V_89;
}
switch ( V_91 ) {
case V_116 :
V_46 = F_57 ( V_113 , ( V_97 T_2 * ) V_112 ) ;
if ( V_46 == 0 )
V_11 -> V_71 . V_117 = V_113 ;
break;
case V_118 :
V_113 = V_11 -> V_71 . V_117 ;
V_46 = F_58 ( V_113 , ( V_97 T_2 * ) V_112 ) ;
break;
case V_119 :
V_46 = F_56 ( & V_115 , V_85 ,
sizeof( V_115 ) ) ? - V_74 : 0 ;
if ( V_46 == 0 ) {
V_11 -> V_71 . V_96 = V_115 . V_96 ;
V_11 -> V_71 . V_120 = V_115 . V_120 ;
V_11 -> V_71 . V_121 = V_115 . V_121 ;
V_11 -> V_71 . V_117 = V_115 . V_117 ;
V_11 -> V_71 . V_122 = V_115 . V_122 ;
V_11 -> V_71 . V_72 = V_115 . V_72 ;
}
break;
case V_123 :
V_115 . V_96 = V_11 -> V_71 . V_96 ;
V_115 . V_120 = V_11 -> V_71 . V_120 ;
V_115 . V_121 = V_11 -> V_71 . V_121 ;
V_115 . V_117 = V_11 -> V_71 . V_117 ;
V_115 . V_122 = V_11 -> V_71 . V_122 ;
V_115 . V_72 = V_11 -> V_71 . V_72 ;
V_46 = F_43 ( V_85 , & V_115 , sizeof( V_115 ) ) ? - V_74 : 0 ;
break;
default:
V_46 = F_55 ( V_11 , V_91 , V_85 ) ;
break;
}
V_89:
F_26 ( & V_11 -> V_47 ) ;
return V_46 ;
}
static long F_64 ( struct V_38 * V_38 ,
unsigned int V_91 , unsigned long V_112 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
struct V_11 * V_11 = V_8 -> V_11 ;
void T_2 * V_85 = ( void T_2 * ) V_112 ;
int V_46 ;
V_46 = F_24 ( & V_11 -> V_47 ) ;
if ( V_46 )
return V_46 ;
if ( ! V_11 -> V_48 ) {
V_46 = - V_49 ;
goto V_89;
}
switch ( V_91 ) {
case V_116 :
V_46 = F_57 ( V_11 -> V_71 . V_117 ,
( long T_2 * ) V_112 ) ;
break;
case V_118 :
V_46 = F_58 ( V_11 -> V_71 . V_117 ,
( long T_2 * ) V_112 ) ;
break;
case V_119 :
V_46 = F_56 ( & V_11 -> V_71 , V_85 ,
sizeof( V_11 -> V_71 ) ) ? - V_74 : 0 ;
break;
case V_123 :
V_46 = F_43 ( V_85 , & V_11 -> V_71 ,
sizeof( V_11 -> V_71 ) ) ? - V_74 : 0 ;
break;
default:
V_46 = F_55 ( V_11 , V_91 , V_85 ) ;
break;
}
V_89:
F_26 ( & V_11 -> V_47 ) ;
return V_46 ;
}
static void F_65 ( struct V_11 * V_11 )
{
F_28 ( & V_11 -> V_47 ) ;
V_11 -> V_48 = false ;
F_26 ( & V_11 -> V_47 ) ;
}
static void F_66 ( struct V_11 * V_11 )
{
struct V_23 * V_24 = & V_11 -> V_24 ;
F_65 ( V_11 ) ;
F_30 ( V_11 ) ;
F_67 ( & V_11 -> V_54 ) ;
if ( V_11 -> V_50 )
F_29 ( V_24 ) ;
}
static bool F_68 ( struct V_58 * V_42 )
{
F_69 ( V_124 , V_125 ) ;
F_70 ( V_126 > V_125 || V_127 > V_125 ) ;
F_71 ( V_124 , V_127 ) ;
F_72 ( V_32 , V_124 ) ;
F_72 ( V_27 , V_124 ) ;
F_72 ( V_128 , V_124 ) ;
if ( ! F_73 ( V_124 , V_42 -> V_129 , V_127 ) )
return false ;
F_71 ( V_124 , V_126 ) ;
F_72 ( V_130 , V_124 ) ;
F_72 ( V_131 , V_124 ) ;
if ( ! F_73 ( V_42 -> V_132 , V_124 , V_126 ) )
return false ;
F_71 ( V_124 , V_125 ) ;
F_72 ( V_133 , V_124 ) ;
F_72 ( V_134 , V_124 ) ;
F_72 ( V_135 , V_124 ) ;
if ( ! F_73 ( V_42 -> V_136 , V_124 , V_125 ) )
return false ;
if ( V_42 -> V_137 . V_138 == V_139 )
return false ;
return true ;
}
static bool F_74 ( struct V_140 * V_141 , struct V_58 * V_42 )
{
if ( F_39 ( V_27 , V_42 -> V_129 ) && F_39 ( V_142 , V_42 -> V_136 ) )
return false ;
if ( F_39 ( V_27 , V_42 -> V_129 ) && F_39 ( V_143 , V_42 -> V_136 ) )
return false ;
if ( F_68 ( V_42 ) )
return false ;
return true ;
}
static int F_75 ( struct V_140 * V_141 , struct V_58 * V_42 ,
const struct V_144 * V_137 )
{
struct V_11 * V_11 ;
int V_67 , V_145 , V_146 , V_147 , V_148 ;
int error ;
V_147 = F_76 ( V_149 , V_150 , true ) ;
if ( V_147 < 0 ) {
error = V_147 ;
F_77 ( L_1 , error ) ;
return error ;
}
V_11 = F_34 ( sizeof( struct V_11 ) , V_55 ) ;
if ( ! V_11 ) {
error = - V_56 ;
goto V_151;
}
F_78 ( & V_11 -> V_45 ) ;
F_35 ( & V_11 -> V_43 ) ;
F_79 ( & V_11 -> V_47 ) ;
F_80 ( & V_11 -> V_36 ) ;
V_11 -> V_48 = true ;
V_148 = V_147 ;
if ( V_148 < V_149 + V_150 )
V_148 -= V_149 ;
F_81 ( & V_11 -> V_42 , L_2 , V_148 ) ;
V_11 -> V_24 . V_42 = F_82 ( V_42 ) ;
V_11 -> V_24 . V_92 = F_83 ( & V_11 -> V_42 ) ;
V_11 -> V_24 . V_141 = V_141 ;
V_11 -> V_24 . V_26 = V_11 ;
F_84 (i, dev->absbit, ABS_CNT) {
V_11 -> V_34 [ V_67 ] = V_11 -> V_16 ;
V_11 -> V_87 [ V_11 -> V_16 ] = V_67 ;
V_11 -> V_16 ++ ;
}
for ( V_67 = V_152 - V_28 ; V_67 < V_90 - V_28 + 1 ; V_67 ++ )
if ( F_39 ( V_67 + V_28 , V_42 -> V_136 ) ) {
V_11 -> V_31 [ V_67 ] = V_11 -> V_17 ;
V_11 -> V_62 [ V_11 -> V_17 ] = V_67 + V_28 ;
V_11 -> V_17 ++ ;
}
for ( V_67 = 0 ; V_67 < V_152 - V_28 ; V_67 ++ )
if ( F_39 ( V_67 + V_28 , V_42 -> V_136 ) ) {
V_11 -> V_31 [ V_67 ] = V_11 -> V_17 ;
V_11 -> V_62 [ V_11 -> V_17 ] = V_67 + V_28 ;
V_11 -> V_17 ++ ;
}
for ( V_67 = 0 ; V_67 < V_11 -> V_16 ; V_67 ++ ) {
V_145 = V_11 -> V_87 [ V_67 ] ;
if ( F_85 ( V_42 , V_145 ) == F_86 ( V_42 , V_145 ) ) {
V_11 -> V_3 [ V_67 ] . type = V_4 ;
V_11 -> abs [ V_67 ] = F_59 ( V_42 , V_145 ) ;
continue;
}
V_11 -> V_3 [ V_67 ] . type = V_5 ;
V_11 -> V_3 [ V_67 ] . V_153 = F_87 ( V_42 , V_145 ) ;
V_146 = ( F_85 ( V_42 , V_145 ) + F_86 ( V_42 , V_145 ) ) / 2 ;
V_11 -> V_3 [ V_67 ] . V_6 [ 0 ] = V_146 - F_88 ( V_42 , V_145 ) ;
V_11 -> V_3 [ V_67 ] . V_6 [ 1 ] = V_146 + F_88 ( V_42 , V_145 ) ;
V_146 = ( F_85 ( V_42 , V_145 ) - F_86 ( V_42 , V_145 ) ) / 2
- 2 * F_88 ( V_42 , V_145 ) ;
if ( V_146 ) {
V_11 -> V_3 [ V_67 ] . V_6 [ 2 ] = ( 1 << 29 ) / V_146 ;
V_11 -> V_3 [ V_67 ] . V_6 [ 3 ] = ( 1 << 29 ) / V_146 ;
V_11 -> abs [ V_67 ] =
F_1 ( F_59 ( V_42 , V_145 ) ,
V_11 -> V_3 + V_67 ) ;
}
}
V_11 -> V_42 . V_154 = F_89 ( V_155 , V_147 ) ;
V_11 -> V_42 . V_156 = & V_157 ;
V_11 -> V_42 . V_158 = & V_42 -> V_42 ;
V_11 -> V_42 . V_159 = F_14 ;
F_90 ( & V_11 -> V_42 ) ;
error = F_91 ( & V_11 -> V_24 ) ;
if ( error )
goto V_160;
F_92 ( & V_11 -> V_54 , & V_161 ) ;
V_11 -> V_54 . V_162 . V_158 = & V_11 -> V_42 . V_162 ;
error = F_93 ( & V_11 -> V_54 , V_11 -> V_42 . V_154 , 1 ) ;
if ( error )
goto V_163;
error = F_94 ( & V_11 -> V_42 ) ;
if ( error )
goto V_164;
return 0 ;
V_164:
F_66 ( V_11 ) ;
V_163:
F_95 ( & V_11 -> V_24 ) ;
V_160:
F_96 ( & V_11 -> V_42 ) ;
V_151:
F_97 ( V_147 ) ;
return error ;
}
static void F_98 ( struct V_23 * V_24 )
{
struct V_11 * V_11 = V_24 -> V_26 ;
F_99 ( & V_11 -> V_42 ) ;
F_66 ( V_11 ) ;
F_97 ( F_100 ( V_11 -> V_42 . V_154 ) ) ;
F_95 ( V_24 ) ;
F_96 ( & V_11 -> V_42 ) ;
}
static int T_8 F_101 ( void )
{
return F_102 ( & V_165 ) ;
}
static void T_9 F_103 ( void )
{
F_104 ( & V_165 ) ;
}
