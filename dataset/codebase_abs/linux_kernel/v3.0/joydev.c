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
F_33 ( & V_11 -> V_42 ) ;
return 0 ;
}
static int F_34 ( struct V_52 * V_52 , struct V_38 * V_38 )
{
struct V_7 * V_8 ;
struct V_11 * V_11 ;
int V_53 = F_35 ( V_52 ) - V_54 ;
int error ;
if ( V_53 >= V_55 )
return - V_49 ;
error = F_24 ( & V_56 ) ;
if ( error )
return error ;
V_11 = V_57 [ V_53 ] ;
if ( V_11 )
F_36 ( & V_11 -> V_42 ) ;
F_26 ( & V_56 ) ;
if ( ! V_11 )
return - V_49 ;
V_8 = F_37 ( sizeof( struct V_7 ) , V_58 ) ;
if ( ! V_8 ) {
error = - V_59 ;
goto V_60;
}
F_38 ( & V_8 -> V_12 ) ;
V_8 -> V_11 = V_11 ;
F_18 ( V_11 , V_8 ) ;
error = F_23 ( V_11 ) ;
if ( error )
goto V_61;
V_38 -> V_40 = V_8 ;
F_39 ( V_52 , V_38 ) ;
return 0 ;
V_61:
F_20 ( V_11 , V_8 ) ;
F_17 ( V_8 ) ;
V_60:
F_33 ( & V_11 -> V_42 ) ;
return error ;
}
static int F_40 ( struct V_7 * V_8 ,
struct V_62 * V_63 ,
struct V_9 * V_10 )
{
struct V_11 * V_11 = V_8 -> V_11 ;
int V_64 ;
F_41 ( & V_8 -> V_12 ) ;
V_64 = V_8 -> V_15 < V_11 -> V_16 + V_11 -> V_17 ;
if ( V_64 ) {
V_10 -> time = F_7 ( V_35 ) ;
if ( V_8 -> V_15 < V_11 -> V_17 ) {
V_10 -> type = V_29 | V_65 ;
V_10 -> V_30 = V_8 -> V_15 ;
V_10 -> V_1 = ! ! F_42 ( V_11 -> V_66 [ V_10 -> V_30 ] ,
V_63 -> V_67 ) ;
} else {
V_10 -> type = V_33 | V_65 ;
V_10 -> V_30 = V_8 -> V_15 - V_11 -> V_17 ;
V_10 -> V_1 = V_11 -> abs [ V_10 -> V_30 ] ;
}
V_8 -> V_15 ++ ;
}
F_43 ( & V_8 -> V_12 ) ;
return V_64 ;
}
static int F_44 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
int V_64 ;
F_41 ( & V_8 -> V_12 ) ;
V_64 = V_8 -> V_14 != V_8 -> V_19 ;
if ( V_64 ) {
* V_10 = V_8 -> V_13 [ V_8 -> V_19 ++ ] ;
V_8 -> V_19 &= V_18 - 1 ;
}
F_43 ( & V_8 -> V_12 ) ;
return V_64 ;
}
static T_1 F_45 ( struct V_7 * V_8 ,
struct V_62 * V_63 ,
char T_2 * V_68 )
{
struct V_11 * V_11 = V_8 -> V_11 ;
struct V_69 V_70 ;
int V_53 ;
F_41 ( & V_63 -> V_71 ) ;
for ( V_70 . V_72 = V_53 = 0 ; V_53 < 32 && V_53 < V_11 -> V_17 ; V_53 ++ )
V_70 . V_72 |=
F_42 ( V_11 -> V_66 [ V_53 ] , V_63 -> V_67 ) ? ( 1 << V_53 ) : 0 ;
V_70 . V_73 = ( V_11 -> abs [ 0 ] / 256 + 128 ) >> V_11 -> V_74 . V_75 . V_73 ;
V_70 . V_76 = ( V_11 -> abs [ 1 ] / 256 + 128 ) >> V_11 -> V_74 . V_75 . V_76 ;
F_3 ( & V_8 -> V_12 ) ;
V_8 -> V_15 = 0 ;
V_8 -> V_19 = V_8 -> V_14 ;
F_4 ( & V_8 -> V_12 ) ;
F_43 ( & V_63 -> V_71 ) ;
if ( F_46 ( V_68 , & V_70 , sizeof( struct V_69 ) ) )
return - V_77 ;
return sizeof( struct V_69 ) ;
}
static inline int F_47 ( struct V_7 * V_8 )
{
struct V_11 * V_11 = V_8 -> V_11 ;
return V_8 -> V_15 < V_11 -> V_16 + V_11 -> V_17 ||
V_8 -> V_14 != V_8 -> V_19 ;
}
static T_1 F_48 ( struct V_38 * V_38 , char T_2 * V_68 ,
T_3 V_78 , T_4 * V_79 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
struct V_11 * V_11 = V_8 -> V_11 ;
struct V_62 * V_63 = V_11 -> V_24 . V_42 ;
struct V_9 V_10 ;
int V_46 ;
if ( ! V_11 -> V_48 )
return - V_49 ;
if ( V_78 < sizeof( struct V_9 ) )
return - V_80 ;
if ( V_78 == sizeof( struct V_69 ) )
return F_45 ( V_8 , V_63 , V_68 ) ;
if ( ! F_47 ( V_8 ) && ( V_38 -> V_81 & V_82 ) )
return - V_83 ;
V_46 = F_49 ( V_11 -> V_36 ,
! V_11 -> V_48 || F_47 ( V_8 ) ) ;
if ( V_46 )
return V_46 ;
if ( ! V_11 -> V_48 )
return - V_49 ;
while ( V_46 + sizeof( struct V_9 ) <= V_78 &&
F_40 ( V_8 , V_63 , & V_10 ) ) {
if ( F_46 ( V_68 + V_46 , & V_10 , sizeof( struct V_9 ) ) )
return - V_77 ;
V_46 += sizeof( struct V_9 ) ;
}
while ( V_46 + sizeof( struct V_9 ) <= V_78 &&
F_44 ( V_8 , & V_10 ) ) {
if ( F_46 ( V_68 + V_46 , & V_10 , sizeof( struct V_9 ) ) )
return - V_77 ;
V_46 += sizeof( struct V_9 ) ;
}
return V_46 ;
}
static unsigned int F_50 ( struct V_38 * V_38 , T_5 * V_36 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
struct V_11 * V_11 = V_8 -> V_11 ;
F_51 ( V_38 , & V_11 -> V_36 , V_36 ) ;
return ( F_47 ( V_8 ) ? ( V_84 | V_85 ) : 0 ) |
( V_11 -> V_48 ? 0 : ( V_86 | V_87 ) ) ;
}
static int F_52 ( struct V_11 * V_11 ,
void T_2 * V_88 , T_3 V_89 )
{
T_6 * V_90 ;
int V_53 ;
int V_46 = 0 ;
V_89 = F_53 ( V_89 , sizeof( V_11 -> V_90 ) ) ;
V_90 = F_54 ( V_89 , V_58 ) ;
if ( ! V_90 )
return - V_59 ;
if ( F_55 ( V_90 , V_88 , V_89 ) ) {
V_46 = - V_77 ;
goto V_91;
}
for ( V_53 = 0 ; V_53 < V_11 -> V_16 ; V_53 ++ ) {
if ( V_90 [ V_53 ] > V_92 ) {
V_46 = - V_80 ;
goto V_91;
}
}
memcpy ( V_11 -> V_90 , V_90 , V_89 ) ;
for ( V_53 = 0 ; V_53 < V_11 -> V_16 ; V_53 ++ )
V_11 -> V_34 [ V_11 -> V_90 [ V_53 ] ] = V_53 ;
V_91:
F_17 ( V_90 ) ;
return V_46 ;
}
static int F_56 ( struct V_11 * V_11 ,
void T_2 * V_88 , T_3 V_89 )
{
T_7 * V_66 ;
int V_53 ;
int V_46 = 0 ;
V_89 = F_53 ( V_89 , sizeof( V_11 -> V_66 ) ) ;
V_66 = F_54 ( V_89 , V_58 ) ;
if ( ! V_66 )
return - V_59 ;
if ( F_55 ( V_66 , V_88 , V_89 ) ) {
V_46 = - V_77 ;
goto V_91;
}
for ( V_53 = 0 ; V_53 < V_11 -> V_17 ; V_53 ++ ) {
if ( V_66 [ V_53 ] > V_93 || V_66 [ V_53 ] < V_28 ) {
V_46 = - V_80 ;
goto V_91;
}
}
memcpy ( V_11 -> V_66 , V_66 , V_89 ) ;
for ( V_53 = 0 ; V_53 < V_11 -> V_17 ; V_53 ++ )
V_11 -> V_31 [ V_66 [ V_53 ] - V_28 ] = V_53 ;
V_91:
F_17 ( V_66 ) ;
return V_46 ;
}
static int F_57 ( struct V_11 * V_11 ,
unsigned int V_94 , void T_2 * V_88 )
{
struct V_62 * V_42 = V_11 -> V_24 . V_42 ;
T_3 V_89 ;
int V_53 ;
const char * V_95 ;
switch ( V_94 ) {
case V_96 :
return F_55 ( & V_11 -> V_74 . V_75 , V_88 ,
sizeof( V_11 -> V_74 . V_75 ) ) ? - V_77 : 0 ;
case V_97 :
return F_46 ( V_88 , & V_11 -> V_74 . V_75 ,
sizeof( V_11 -> V_74 . V_75 ) ) ? - V_77 : 0 ;
case V_98 :
return F_58 ( V_11 -> V_74 . V_99 , ( V_100 T_2 * ) V_88 ) ;
case V_101 :
return F_59 ( V_11 -> V_74 . V_99 , ( V_100 T_2 * ) V_88 ) ;
case V_102 :
return F_59 ( V_103 , ( V_104 T_2 * ) V_88 ) ;
case V_105 :
return F_59 ( V_11 -> V_16 , ( T_6 T_2 * ) V_88 ) ;
case V_106 :
return F_59 ( V_11 -> V_17 , ( T_6 T_2 * ) V_88 ) ;
case V_107 :
if ( F_55 ( V_11 -> V_3 , V_88 ,
sizeof( V_11 -> V_3 [ 0 ] ) * V_11 -> V_16 ) )
return - V_77 ;
for ( V_53 = 0 ; V_53 < V_11 -> V_16 ; V_53 ++ ) {
int V_108 = F_60 ( V_42 , V_11 -> V_90 [ V_53 ] ) ;
V_11 -> abs [ V_53 ] = F_1 ( V_108 , & V_11 -> V_3 [ V_53 ] ) ;
}
return 0 ;
case V_109 :
return F_46 ( V_88 , V_11 -> V_3 ,
sizeof( V_11 -> V_3 [ 0 ] ) * V_11 -> V_16 ) ? - V_77 : 0 ;
}
switch ( V_94 & ~ V_110 ) {
case ( V_111 & ~ V_110 ) :
return F_52 ( V_11 , V_88 , F_61 ( V_94 ) ) ;
case ( V_112 & ~ V_110 ) :
V_89 = F_62 ( T_3 , F_61 ( V_94 ) , sizeof( V_11 -> V_90 ) ) ;
return F_46 ( V_88 , V_11 -> V_90 , V_89 ) ? - V_77 : V_89 ;
case ( V_113 & ~ V_110 ) :
return F_56 ( V_11 , V_88 , F_61 ( V_94 ) ) ;
case ( V_114 & ~ V_110 ) :
V_89 = F_62 ( T_3 , F_61 ( V_94 ) , sizeof( V_11 -> V_66 ) ) ;
return F_46 ( V_88 , V_11 -> V_66 , V_89 ) ? - V_77 : V_89 ;
case F_63 ( 0 ) :
V_95 = V_42 -> V_95 ;
if ( ! V_95 )
return 0 ;
V_89 = F_62 ( T_3 , F_61 ( V_94 ) , strlen ( V_95 ) + 1 ) ;
return F_46 ( V_88 , V_95 , V_89 ) ? - V_77 : V_89 ;
}
return - V_80 ;
}
static long F_64 ( struct V_38 * V_38 ,
unsigned int V_94 , unsigned long V_115 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
struct V_11 * V_11 = V_8 -> V_11 ;
void T_2 * V_88 = ( void T_2 * ) V_115 ;
V_100 V_116 ;
struct V_117 V_118 ;
int V_46 ;
V_46 = F_24 ( & V_11 -> V_47 ) ;
if ( V_46 )
return V_46 ;
if ( ! V_11 -> V_48 ) {
V_46 = - V_49 ;
goto V_91;
}
switch ( V_94 ) {
case V_119 :
V_46 = F_58 ( V_116 , ( V_100 T_2 * ) V_115 ) ;
if ( V_46 == 0 )
V_11 -> V_74 . V_120 = V_116 ;
break;
case V_121 :
V_116 = V_11 -> V_74 . V_120 ;
V_46 = F_59 ( V_116 , ( V_100 T_2 * ) V_115 ) ;
break;
case V_122 :
V_46 = F_55 ( & V_118 , V_88 ,
sizeof( V_118 ) ) ? - V_77 : 0 ;
if ( V_46 == 0 ) {
V_11 -> V_74 . V_99 = V_118 . V_99 ;
V_11 -> V_74 . V_123 = V_118 . V_123 ;
V_11 -> V_74 . V_124 = V_118 . V_124 ;
V_11 -> V_74 . V_120 = V_118 . V_120 ;
V_11 -> V_74 . V_125 = V_118 . V_125 ;
V_11 -> V_74 . V_75 = V_118 . V_75 ;
}
break;
case V_126 :
V_118 . V_99 = V_11 -> V_74 . V_99 ;
V_118 . V_123 = V_11 -> V_74 . V_123 ;
V_118 . V_124 = V_11 -> V_74 . V_124 ;
V_118 . V_120 = V_11 -> V_74 . V_120 ;
V_118 . V_125 = V_11 -> V_74 . V_125 ;
V_118 . V_75 = V_11 -> V_74 . V_75 ;
V_46 = F_46 ( V_88 , & V_118 , sizeof( V_118 ) ) ? - V_77 : 0 ;
break;
default:
V_46 = F_57 ( V_11 , V_94 , V_88 ) ;
break;
}
V_91:
F_26 ( & V_11 -> V_47 ) ;
return V_46 ;
}
static long F_65 ( struct V_38 * V_38 ,
unsigned int V_94 , unsigned long V_115 )
{
struct V_7 * V_8 = V_38 -> V_40 ;
struct V_11 * V_11 = V_8 -> V_11 ;
void T_2 * V_88 = ( void T_2 * ) V_115 ;
int V_46 ;
V_46 = F_24 ( & V_11 -> V_47 ) ;
if ( V_46 )
return V_46 ;
if ( ! V_11 -> V_48 ) {
V_46 = - V_49 ;
goto V_91;
}
switch ( V_94 ) {
case V_119 :
V_46 = F_58 ( V_11 -> V_74 . V_120 ,
( long T_2 * ) V_115 ) ;
break;
case V_121 :
V_46 = F_59 ( V_11 -> V_74 . V_120 ,
( long T_2 * ) V_115 ) ;
break;
case V_122 :
V_46 = F_55 ( & V_11 -> V_74 , V_88 ,
sizeof( V_11 -> V_74 ) ) ? - V_77 : 0 ;
break;
case V_126 :
V_46 = F_46 ( V_88 , & V_11 -> V_74 ,
sizeof( V_11 -> V_74 ) ) ? - V_77 : 0 ;
break;
default:
V_46 = F_57 ( V_11 , V_94 , V_88 ) ;
break;
}
V_91:
F_26 ( & V_11 -> V_47 ) ;
return V_46 ;
}
static int F_66 ( struct V_11 * V_11 )
{
V_57 [ V_11 -> V_127 ] = V_11 ;
return 0 ;
}
static void F_67 ( struct V_11 * V_11 )
{
F_28 ( & V_56 ) ;
V_57 [ V_11 -> V_127 ] = NULL ;
F_26 ( & V_56 ) ;
}
static void F_68 ( struct V_11 * V_11 )
{
F_28 ( & V_11 -> V_47 ) ;
V_11 -> V_48 = false ;
F_26 ( & V_11 -> V_47 ) ;
}
static void F_69 ( struct V_11 * V_11 )
{
struct V_23 * V_24 = & V_11 -> V_24 ;
F_68 ( V_11 ) ;
F_30 ( V_11 ) ;
F_67 ( V_11 ) ;
if ( V_11 -> V_50 )
F_29 ( V_24 ) ;
}
static bool F_70 ( struct V_128 * V_129 , struct V_62 * V_42 )
{
if ( F_42 ( V_27 , V_42 -> V_130 ) && F_42 ( V_131 , V_42 -> V_132 ) )
return false ;
if ( F_42 ( V_27 , V_42 -> V_130 ) && F_42 ( V_133 , V_42 -> V_132 ) )
return false ;
return true ;
}
static int F_71 ( struct V_128 * V_129 , struct V_62 * V_42 ,
const struct V_134 * V_135 )
{
struct V_11 * V_11 ;
int V_53 , V_136 , V_137 , V_127 ;
int error ;
for ( V_127 = 0 ; V_127 < V_55 ; V_127 ++ )
if ( ! V_57 [ V_127 ] )
break;
if ( V_127 == V_55 ) {
F_72 ( L_1 ) ;
return - V_138 ;
}
V_11 = F_37 ( sizeof( struct V_11 ) , V_58 ) ;
if ( ! V_11 )
return - V_59 ;
F_73 ( & V_11 -> V_45 ) ;
F_38 ( & V_11 -> V_43 ) ;
F_74 ( & V_11 -> V_47 ) ;
F_75 ( & V_11 -> V_36 ) ;
F_76 ( & V_11 -> V_42 , L_2 , V_127 ) ;
V_11 -> V_48 = true ;
V_11 -> V_127 = V_127 ;
V_11 -> V_24 . V_42 = F_77 ( V_42 ) ;
V_11 -> V_24 . V_95 = F_78 ( & V_11 -> V_42 ) ;
V_11 -> V_24 . V_129 = V_129 ;
V_11 -> V_24 . V_26 = V_11 ;
for ( V_53 = 0 ; V_53 < V_139 ; V_53 ++ )
if ( F_42 ( V_53 , V_42 -> V_140 ) ) {
V_11 -> V_34 [ V_53 ] = V_11 -> V_16 ;
V_11 -> V_90 [ V_11 -> V_16 ] = V_53 ;
V_11 -> V_16 ++ ;
}
for ( V_53 = V_141 - V_28 ; V_53 < V_93 - V_28 + 1 ; V_53 ++ )
if ( F_42 ( V_53 + V_28 , V_42 -> V_132 ) ) {
V_11 -> V_31 [ V_53 ] = V_11 -> V_17 ;
V_11 -> V_66 [ V_11 -> V_17 ] = V_53 + V_28 ;
V_11 -> V_17 ++ ;
}
for ( V_53 = 0 ; V_53 < V_141 - V_28 ; V_53 ++ )
if ( F_42 ( V_53 + V_28 , V_42 -> V_132 ) ) {
V_11 -> V_31 [ V_53 ] = V_11 -> V_17 ;
V_11 -> V_66 [ V_11 -> V_17 ] = V_53 + V_28 ;
V_11 -> V_17 ++ ;
}
for ( V_53 = 0 ; V_53 < V_11 -> V_16 ; V_53 ++ ) {
V_136 = V_11 -> V_90 [ V_53 ] ;
if ( F_79 ( V_42 , V_136 ) == F_80 ( V_42 , V_136 ) ) {
V_11 -> V_3 [ V_53 ] . type = V_4 ;
V_11 -> abs [ V_53 ] = F_60 ( V_42 , V_136 ) ;
continue;
}
V_11 -> V_3 [ V_53 ] . type = V_5 ;
V_11 -> V_3 [ V_53 ] . V_142 = F_81 ( V_42 , V_136 ) ;
V_137 = ( F_79 ( V_42 , V_136 ) + F_80 ( V_42 , V_136 ) ) / 2 ;
V_11 -> V_3 [ V_53 ] . V_6 [ 0 ] = V_137 - F_82 ( V_42 , V_136 ) ;
V_11 -> V_3 [ V_53 ] . V_6 [ 1 ] = V_137 + F_82 ( V_42 , V_136 ) ;
V_137 = ( F_79 ( V_42 , V_136 ) - F_80 ( V_42 , V_136 ) ) / 2
- 2 * F_82 ( V_42 , V_136 ) ;
if ( V_137 ) {
V_11 -> V_3 [ V_53 ] . V_6 [ 2 ] = ( 1 << 29 ) / V_137 ;
V_11 -> V_3 [ V_53 ] . V_6 [ 3 ] = ( 1 << 29 ) / V_137 ;
V_11 -> abs [ V_53 ] =
F_1 ( F_60 ( V_42 , V_136 ) ,
V_11 -> V_3 + V_53 ) ;
}
}
V_11 -> V_42 . V_143 = F_83 ( V_144 , V_54 + V_127 ) ;
V_11 -> V_42 . V_145 = & V_146 ;
V_11 -> V_42 . V_147 = & V_42 -> V_42 ;
V_11 -> V_42 . V_148 = F_14 ;
F_84 ( & V_11 -> V_42 ) ;
error = F_85 ( & V_11 -> V_24 ) ;
if ( error )
goto V_149;
error = F_66 ( V_11 ) ;
if ( error )
goto V_150;
error = F_86 ( & V_11 -> V_42 ) ;
if ( error )
goto V_151;
return 0 ;
V_151:
F_69 ( V_11 ) ;
V_150:
F_87 ( & V_11 -> V_24 ) ;
V_149:
F_33 ( & V_11 -> V_42 ) ;
return error ;
}
static void F_88 ( struct V_23 * V_24 )
{
struct V_11 * V_11 = V_24 -> V_26 ;
F_89 ( & V_11 -> V_42 ) ;
F_69 ( V_11 ) ;
F_87 ( V_24 ) ;
F_33 ( & V_11 -> V_42 ) ;
}
static int T_8 F_90 ( void )
{
return F_91 ( & V_152 ) ;
}
static void T_9 F_92 ( void )
{
F_93 ( & V_152 ) ;
}
