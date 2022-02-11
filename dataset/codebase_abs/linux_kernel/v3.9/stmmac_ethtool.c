static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 -> V_8 )
F_3 ( V_4 -> V_9 , V_10 , sizeof( V_4 -> V_9 ) ) ;
else
F_3 ( V_4 -> V_9 , V_11 ,
sizeof( V_4 -> V_9 ) ) ;
F_3 ( V_4 -> V_12 , V_13 , sizeof( V_4 -> V_12 ) ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_6 -> V_18 ;
int V_19 ;
if ( V_17 == NULL ) {
F_5 ( L_1 ,
V_20 , V_2 -> V_21 ) ;
return - V_22 ;
}
if ( ! F_6 ( V_2 ) ) {
F_5 ( L_2
L_3 , V_2 -> V_21 ) ;
return - V_23 ;
}
V_15 -> V_24 = V_25 ;
F_7 ( & V_6 -> V_26 ) ;
V_19 = F_8 ( V_17 , V_15 ) ;
F_9 ( & V_6 -> V_26 ) ;
return V_19 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_6 -> V_18 ;
int V_19 ;
F_11 ( & V_6 -> V_26 ) ;
V_19 = F_12 ( V_17 , V_15 ) ;
F_13 ( & V_6 -> V_26 ) ;
return V_19 ;
}
static T_1 F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_27 ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_27 = V_28 ;
}
static int F_16 ( struct V_1 * V_2 )
{
if ( ! F_6 ( V_2 ) )
return - V_23 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return V_29 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_30 * V_31 , void * V_32 )
{
int V_33 ;
T_1 * V_34 = ( T_1 * ) V_32 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_34 , 0x0 , V_29 ) ;
if ( ! V_6 -> V_7 -> V_8 ) {
for ( V_33 = 0 ; V_33 < 12 ; V_33 ++ )
V_34 [ V_33 ] = F_19 ( V_6 -> V_35 + ( V_33 * 4 ) ) ;
for ( V_33 = 0 ; V_33 < 9 ; V_33 ++ )
V_34 [ V_33 + 12 ] =
F_19 ( V_6 -> V_35 + ( V_36 + ( V_33 * 4 ) ) ) ;
V_34 [ 22 ] = F_19 ( V_6 -> V_35 + V_37 ) ;
V_34 [ 23 ] = F_19 ( V_6 -> V_35 + V_38 ) ;
} else {
for ( V_33 = 0 ; V_33 < 55 ; V_33 ++ )
V_34 [ V_33 ] = F_19 ( V_6 -> V_35 + ( V_33 * 4 ) ) ;
for ( V_33 = 0 ; V_33 < 22 ; V_33 ++ )
V_34 [ V_33 + 55 ] =
F_19 ( V_6 -> V_35 + ( V_36 + ( V_33 * 4 ) ) ) ;
}
}
static void
F_20 ( struct V_1 * V_39 ,
struct V_40 * V_41 )
{
struct V_5 * V_6 = F_2 ( V_39 ) ;
F_11 ( & V_6 -> V_26 ) ;
V_41 -> V_42 = 0 ;
V_41 -> V_43 = 0 ;
V_41 -> V_44 = V_6 -> V_18 -> V_44 ;
if ( V_6 -> V_45 & V_46 )
V_41 -> V_42 = 1 ;
if ( V_6 -> V_45 & V_47 )
V_41 -> V_43 = 1 ;
F_13 ( & V_6 -> V_26 ) ;
}
static int
F_21 ( struct V_1 * V_39 ,
struct V_40 * V_41 )
{
struct V_5 * V_6 = F_2 ( V_39 ) ;
struct V_16 * V_17 = V_6 -> V_18 ;
int V_48 = V_49 ;
int V_50 = 0 ;
F_11 ( & V_6 -> V_26 ) ;
if ( V_41 -> V_42 )
V_48 |= V_46 ;
if ( V_41 -> V_43 )
V_48 |= V_47 ;
V_6 -> V_45 = V_48 ;
V_17 -> V_44 = V_41 -> V_44 ;
if ( V_17 -> V_44 ) {
if ( F_6 ( V_39 ) )
V_50 = F_22 ( V_17 ) ;
} else
V_6 -> V_51 -> V_52 -> V_45 ( V_6 -> V_35 , V_17 -> V_53 ,
V_6 -> V_45 , V_6 -> V_41 ) ;
F_13 ( & V_6 -> V_26 ) ;
return V_50 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_54 * V_55 , T_2 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_33 , V_57 = 0 ;
if ( ! V_6 -> V_7 -> V_8 )
V_6 -> V_51 -> V_58 -> V_59 ( & V_2 -> V_60 ,
( void * ) & V_6 -> V_61 ,
V_6 -> V_35 ) ;
else {
if ( V_6 -> V_62 . V_63 ) {
F_24 ( V_6 -> V_35 , & V_6 -> V_64 ) ;
for ( V_33 = 0 ; V_33 < V_65 ; V_33 ++ ) {
char * V_66 ;
V_66 = ( char * ) V_6 + V_67 [ V_33 ] . V_68 ;
V_56 [ V_57 ++ ] = ( V_67 [ V_33 ] . V_69 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_66 ) :
( * ( T_1 * ) V_66 ) ;
}
}
if ( V_6 -> V_70 ) {
int V_71 = F_25 ( V_6 -> V_18 ) ;
if ( V_71 )
V_6 -> V_61 . V_72 = V_71 ;
}
}
for ( V_33 = 0 ; V_33 < V_73 ; V_33 ++ ) {
char * V_66 = ( char * ) V_6 + V_74 [ V_33 ] . V_68 ;
V_56 [ V_57 ++ ] = ( V_74 [ V_33 ] . V_69 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_66 ) : ( * ( T_1 * ) V_66 ) ;
}
}
static int F_26 ( struct V_1 * V_39 , int V_75 )
{
struct V_5 * V_6 = F_2 ( V_39 ) ;
int V_76 ;
switch ( V_75 ) {
case V_77 :
V_76 = V_73 ;
if ( V_6 -> V_62 . V_63 )
V_76 += V_65 ;
return V_76 ;
default:
return - V_78 ;
}
}
static void F_27 ( struct V_1 * V_2 , T_1 V_79 , T_3 * V_56 )
{
int V_33 ;
T_3 * V_66 = V_56 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_79 ) {
case V_77 :
if ( V_6 -> V_62 . V_63 )
for ( V_33 = 0 ; V_33 < V_65 ; V_33 ++ ) {
memcpy ( V_66 , V_67 [ V_33 ] . V_80 ,
V_81 ) ;
V_66 += V_81 ;
}
for ( V_33 = 0 ; V_33 < V_73 ; V_33 ++ ) {
memcpy ( V_66 , V_74 [ V_33 ] . V_80 ,
V_81 ) ;
V_66 += V_81 ;
}
break;
default:
F_28 ( 1 ) ;
break;
}
}
static void F_29 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_7 ( & V_6 -> V_26 ) ;
if ( F_30 ( V_6 -> V_84 ) ) {
V_83 -> V_85 = V_86 | V_87 ;
V_83 -> V_88 = V_6 -> V_88 ;
}
F_9 ( & V_6 -> V_26 ) ;
}
static int F_31 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_89 = V_86 | V_87 ;
if ( ( V_6 -> V_90 ) && ( ! V_6 -> V_62 . V_91 ) )
V_83 -> V_88 &= ~ V_86 ;
if ( ! F_30 ( V_6 -> V_84 ) )
return - V_92 ;
if ( V_83 -> V_88 & ~ V_89 )
return - V_92 ;
if ( V_83 -> V_88 ) {
F_32 ( L_4 ) ;
F_33 ( V_6 -> V_84 , 1 ) ;
F_34 ( V_6 -> V_93 ) ;
} else {
F_33 ( V_6 -> V_84 , 0 ) ;
F_35 ( V_6 -> V_93 ) ;
}
F_7 ( & V_6 -> V_26 ) ;
V_6 -> V_88 = V_83 -> V_88 ;
F_9 ( & V_6 -> V_26 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_62 . V_96 )
return - V_78 ;
V_95 -> V_70 = V_6 -> V_70 ;
V_95 -> V_97 = V_6 -> V_97 ;
V_95 -> V_98 = V_6 -> V_98 ;
return F_37 ( V_6 -> V_18 , V_95 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_70 = V_95 -> V_70 ;
if ( ! V_6 -> V_70 )
F_39 ( V_6 ) ;
else {
V_6 -> V_70 = F_40 ( V_6 ) ;
if ( ! V_6 -> V_70 )
return - V_78 ;
V_6 -> V_98 = V_95 -> V_98 ;
}
return F_41 ( V_6 -> V_18 , V_95 ) ;
}
static T_1 F_42 ( T_1 V_99 , struct V_5 * V_6 )
{
unsigned long V_100 = F_43 ( V_6 -> V_101 ) ;
if ( ! V_100 )
return 0 ;
return ( V_99 * ( V_100 / 1000000 ) ) / 256 ;
}
static T_1 F_44 ( T_1 V_102 , struct V_5 * V_6 )
{
unsigned long V_100 = F_43 ( V_6 -> V_101 ) ;
if ( ! V_100 )
return 0 ;
return ( V_102 * 256 ) / ( V_100 / 1000000 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_104 -> V_105 = V_6 -> V_106 ;
V_104 -> V_107 = V_6 -> V_108 ;
if ( V_6 -> V_109 )
V_104 -> V_110 = F_44 ( V_6 -> V_111 , V_6 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_111 ;
if ( ( V_104 -> V_112 ) || ( V_104 -> V_113 ) ||
( V_104 -> V_114 ) || ( V_104 -> V_115 ) ||
( V_104 -> V_116 ) || ( V_104 -> V_117 ) ||
( V_104 -> V_118 ) || ( V_104 -> V_119 ) ||
( V_104 -> V_120 ) || ( V_104 -> V_121 ) ||
( V_104 -> V_122 ) || ( V_104 -> V_123 ) ||
( V_104 -> V_124 ) || ( V_104 -> V_125 ) ||
( V_104 -> V_126 ) ||
( V_104 -> V_127 ) ||
( V_104 -> V_128 ) ||
( V_104 -> V_129 ) || ( V_104 -> V_130 ) )
return - V_78 ;
if ( V_104 -> V_110 == 0 )
return - V_92 ;
if ( ( V_104 -> V_105 == 0 ) &&
( V_104 -> V_107 == 0 ) )
return - V_92 ;
if ( ( V_104 -> V_105 > V_131 ) ||
( V_104 -> V_107 > V_132 ) )
return - V_92 ;
V_111 = F_42 ( V_104 -> V_110 , V_6 ) ;
if ( ( V_111 > V_133 ) || ( V_111 < V_134 ) )
return - V_92 ;
else if ( ! V_6 -> V_109 )
return - V_78 ;
V_6 -> V_108 = V_104 -> V_107 ;
V_6 -> V_106 = V_104 -> V_105 ;
V_6 -> V_111 = V_111 ;
V_6 -> V_51 -> V_58 -> V_135 ( V_6 -> V_35 , V_6 -> V_111 ) ;
return 0 ;
}
void F_47 ( struct V_1 * V_39 )
{
F_48 ( V_39 , & V_136 ) ;
}
