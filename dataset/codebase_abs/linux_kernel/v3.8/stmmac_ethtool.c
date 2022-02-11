static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 -> V_8 )
F_3 ( V_4 -> V_9 , V_10 , sizeof( V_4 -> V_9 ) ) ;
else
F_3 ( V_4 -> V_9 , V_11 ,
sizeof( V_4 -> V_9 ) ) ;
strcpy ( V_4 -> V_12 , V_13 ) ;
V_4 -> V_14 [ 0 ] = '\0' ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_6 -> V_19 ;
int V_20 ;
if ( V_18 == NULL ) {
F_5 ( L_1 ,
V_21 , V_2 -> V_22 ) ;
return - V_23 ;
}
if ( ! F_6 ( V_2 ) ) {
F_5 ( L_2
L_3 , V_2 -> V_22 ) ;
return - V_24 ;
}
V_16 -> V_25 = V_26 ;
F_7 ( & V_6 -> V_27 ) ;
V_20 = F_8 ( V_18 , V_16 ) ;
F_9 ( & V_6 -> V_27 ) ;
return V_20 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_6 -> V_19 ;
int V_20 ;
F_11 ( & V_6 -> V_27 ) ;
V_20 = F_12 ( V_18 , V_16 ) ;
F_13 ( & V_6 -> V_27 ) ;
return V_20 ;
}
static T_1 F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_28 ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_28 = V_29 ;
}
static int F_16 ( struct V_1 * V_2 )
{
if ( ! F_6 ( V_2 ) )
return - V_24 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return V_30 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_31 * V_32 , void * V_33 )
{
int V_34 ;
T_1 * V_35 = ( T_1 * ) V_33 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_35 , 0x0 , V_30 ) ;
if ( ! V_6 -> V_7 -> V_8 ) {
for ( V_34 = 0 ; V_34 < 12 ; V_34 ++ )
V_35 [ V_34 ] = F_19 ( V_6 -> V_36 + ( V_34 * 4 ) ) ;
for ( V_34 = 0 ; V_34 < 9 ; V_34 ++ )
V_35 [ V_34 + 12 ] =
F_19 ( V_6 -> V_36 + ( V_37 + ( V_34 * 4 ) ) ) ;
V_35 [ 22 ] = F_19 ( V_6 -> V_36 + V_38 ) ;
V_35 [ 23 ] = F_19 ( V_6 -> V_36 + V_39 ) ;
} else {
for ( V_34 = 0 ; V_34 < 55 ; V_34 ++ )
V_35 [ V_34 ] = F_19 ( V_6 -> V_36 + ( V_34 * 4 ) ) ;
for ( V_34 = 0 ; V_34 < 22 ; V_34 ++ )
V_35 [ V_34 + 55 ] =
F_19 ( V_6 -> V_36 + ( V_37 + ( V_34 * 4 ) ) ) ;
}
}
static void
F_20 ( struct V_1 * V_40 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_40 ) ;
F_11 ( & V_6 -> V_27 ) ;
V_42 -> V_43 = 0 ;
V_42 -> V_44 = 0 ;
V_42 -> V_45 = V_6 -> V_19 -> V_45 ;
if ( V_6 -> V_46 & V_47 )
V_42 -> V_43 = 1 ;
if ( V_6 -> V_46 & V_48 )
V_42 -> V_44 = 1 ;
F_13 ( & V_6 -> V_27 ) ;
}
static int
F_21 ( struct V_1 * V_40 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_40 ) ;
struct V_17 * V_18 = V_6 -> V_19 ;
int V_49 = V_50 ;
int V_51 = 0 ;
F_11 ( & V_6 -> V_27 ) ;
if ( V_42 -> V_43 )
V_49 |= V_47 ;
if ( V_42 -> V_44 )
V_49 |= V_48 ;
V_6 -> V_46 = V_49 ;
V_18 -> V_45 = V_42 -> V_45 ;
if ( V_18 -> V_45 ) {
if ( F_6 ( V_40 ) )
V_51 = F_22 ( V_18 ) ;
} else
V_6 -> V_52 -> V_53 -> V_46 ( V_6 -> V_36 , V_18 -> V_54 ,
V_6 -> V_46 , V_6 -> V_42 ) ;
F_13 ( & V_6 -> V_27 ) ;
return V_51 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_55 * V_56 , T_2 * V_57 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_34 , V_58 = 0 ;
if ( ! V_6 -> V_7 -> V_8 )
V_6 -> V_52 -> V_59 -> V_60 ( & V_2 -> V_61 ,
( void * ) & V_6 -> V_62 ,
V_6 -> V_36 ) ;
else {
if ( V_6 -> V_63 . V_64 ) {
F_24 ( V_6 -> V_36 , & V_6 -> V_65 ) ;
for ( V_34 = 0 ; V_34 < V_66 ; V_34 ++ ) {
char * V_67 ;
V_67 = ( char * ) V_6 + V_68 [ V_34 ] . V_69 ;
V_57 [ V_58 ++ ] = ( V_68 [ V_34 ] . V_70 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_67 ) :
( * ( T_1 * ) V_67 ) ;
}
}
if ( V_6 -> V_71 ) {
int V_72 = F_25 ( V_6 -> V_19 ) ;
if ( V_72 )
V_6 -> V_62 . V_73 = V_72 ;
}
}
for ( V_34 = 0 ; V_34 < V_74 ; V_34 ++ ) {
char * V_67 = ( char * ) V_6 + V_75 [ V_34 ] . V_69 ;
V_57 [ V_58 ++ ] = ( V_75 [ V_34 ] . V_70 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_67 ) : ( * ( T_1 * ) V_67 ) ;
}
}
static int F_26 ( struct V_1 * V_40 , int V_76 )
{
struct V_5 * V_6 = F_2 ( V_40 ) ;
int V_77 ;
switch ( V_76 ) {
case V_78 :
V_77 = V_74 ;
if ( V_6 -> V_63 . V_64 )
V_77 += V_66 ;
return V_77 ;
default:
return - V_79 ;
}
}
static void F_27 ( struct V_1 * V_2 , T_1 V_80 , T_3 * V_57 )
{
int V_34 ;
T_3 * V_67 = V_57 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_80 ) {
case V_78 :
if ( V_6 -> V_63 . V_64 )
for ( V_34 = 0 ; V_34 < V_66 ; V_34 ++ ) {
memcpy ( V_67 , V_68 [ V_34 ] . V_81 ,
V_82 ) ;
V_67 += V_82 ;
}
for ( V_34 = 0 ; V_34 < V_74 ; V_34 ++ ) {
memcpy ( V_67 , V_75 [ V_34 ] . V_81 ,
V_82 ) ;
V_67 += V_82 ;
}
break;
default:
F_28 ( 1 ) ;
break;
}
}
static void F_29 ( struct V_1 * V_2 , struct V_83 * V_84 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_7 ( & V_6 -> V_27 ) ;
if ( F_30 ( V_6 -> V_85 ) ) {
V_84 -> V_86 = V_87 | V_88 ;
V_84 -> V_89 = V_6 -> V_89 ;
}
F_9 ( & V_6 -> V_27 ) ;
}
static int F_31 ( struct V_1 * V_2 , struct V_83 * V_84 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_90 = V_87 | V_88 ;
if ( ( V_6 -> V_91 ) && ( ! V_6 -> V_63 . V_92 ) )
V_84 -> V_89 &= ~ V_87 ;
if ( ! F_30 ( V_6 -> V_85 ) )
return - V_93 ;
if ( V_84 -> V_89 & ~ V_90 )
return - V_93 ;
if ( V_84 -> V_89 ) {
F_32 ( L_4 ) ;
F_33 ( V_6 -> V_85 , 1 ) ;
F_34 ( V_6 -> V_94 ) ;
} else {
F_33 ( V_6 -> V_85 , 0 ) ;
F_35 ( V_6 -> V_94 ) ;
}
F_7 ( & V_6 -> V_27 ) ;
V_6 -> V_89 = V_84 -> V_89 ;
F_9 ( & V_6 -> V_27 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_63 . V_97 )
return - V_79 ;
V_96 -> V_71 = V_6 -> V_71 ;
V_96 -> V_98 = V_6 -> V_98 ;
V_96 -> V_99 = V_6 -> V_99 ;
return F_37 ( V_6 -> V_19 , V_96 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_71 = V_96 -> V_71 ;
if ( ! V_6 -> V_71 )
F_39 ( V_6 ) ;
else {
V_6 -> V_71 = F_40 ( V_6 ) ;
if ( ! V_6 -> V_71 )
return - V_79 ;
V_6 -> V_99 = V_96 -> V_99 ;
}
return F_41 ( V_6 -> V_19 , V_96 ) ;
}
static T_1 F_42 ( T_1 V_100 , struct V_5 * V_6 )
{
unsigned long V_101 = F_43 ( V_6 -> V_102 ) ;
if ( ! V_101 )
return 0 ;
return ( V_100 * ( V_101 / 1000000 ) ) / 256 ;
}
static T_1 F_44 ( T_1 V_103 , struct V_5 * V_6 )
{
unsigned long V_101 = F_43 ( V_6 -> V_102 ) ;
if ( ! V_101 )
return 0 ;
return ( V_103 * 256 ) / ( V_101 / 1000000 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_104 * V_105 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_105 -> V_106 = V_6 -> V_107 ;
V_105 -> V_108 = V_6 -> V_109 ;
if ( V_6 -> V_110 )
V_105 -> V_111 = F_44 ( V_6 -> V_112 , V_6 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_104 * V_105 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_112 ;
if ( ( V_105 -> V_113 ) || ( V_105 -> V_114 ) ||
( V_105 -> V_115 ) || ( V_105 -> V_116 ) ||
( V_105 -> V_117 ) || ( V_105 -> V_118 ) ||
( V_105 -> V_119 ) || ( V_105 -> V_120 ) ||
( V_105 -> V_121 ) || ( V_105 -> V_122 ) ||
( V_105 -> V_123 ) || ( V_105 -> V_124 ) ||
( V_105 -> V_125 ) || ( V_105 -> V_126 ) ||
( V_105 -> V_127 ) ||
( V_105 -> V_128 ) ||
( V_105 -> V_129 ) ||
( V_105 -> V_130 ) || ( V_105 -> V_131 ) )
return - V_79 ;
if ( V_105 -> V_111 == 0 )
return - V_93 ;
if ( ( V_105 -> V_106 == 0 ) &&
( V_105 -> V_108 == 0 ) )
return - V_93 ;
if ( ( V_105 -> V_106 > V_132 ) ||
( V_105 -> V_108 > V_133 ) )
return - V_93 ;
V_112 = F_42 ( V_105 -> V_111 , V_6 ) ;
if ( ( V_112 > V_134 ) || ( V_112 < V_135 ) )
return - V_93 ;
else if ( ! V_6 -> V_110 )
return - V_79 ;
V_6 -> V_109 = V_105 -> V_108 ;
V_6 -> V_107 = V_105 -> V_106 ;
V_6 -> V_112 = V_112 ;
V_6 -> V_52 -> V_59 -> V_136 ( V_6 -> V_36 , V_6 -> V_112 ) ;
return 0 ;
}
void F_47 ( struct V_1 * V_40 )
{
F_48 ( V_40 , & V_137 ) ;
}
