static int F_1 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 , int V_5 )
{
T_2 * V_6 = V_3 ;
if ( F_2 ( V_2 -> V_7 ) )
F_3 ( V_2 , V_3 , V_4 + V_8 , V_5 ) ;
else {
for ( ; V_5 > 0 ; V_5 -- , V_4 ++ , V_6 ++ )
* V_6 = F_4 ( V_2 , V_4 ) ;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_9 * V_10 , T_1 V_4 )
{
int V_11 = F_1 ( V_2 , V_10 , V_4 , sizeof( * V_10 ) ) ;
if ( V_11 ) {
F_6 ( L_1 ) ;
return V_11 ;
}
if ( V_10 -> V_12 [ 0 ] != 'M' || V_10 -> V_12 [ 1 ] != 'O' ) {
F_6 ( L_2 ,
V_10 -> V_12 [ 0 ] , V_10 -> V_12 [ 1 ] ) ;
return - V_13 ;
}
if ( V_10 -> V_14 != 0 ) {
F_7 ( L_3 ,
V_10 -> V_14 ) ;
return - V_13 ;
}
V_10 -> V_15 &= 0xf ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 , int V_5 )
{
T_2 * V_6 = V_3 ;
if ( F_2 ( V_2 -> V_7 ) )
F_9 ( V_2 , V_3 , V_4 + V_8 , V_5 ) ;
else {
for ( ; V_5 > 0 ; V_5 -- , V_4 ++ , V_6 ++ )
F_10 ( V_2 , V_4 , * V_6 ) ;
}
return;
}
static int F_11 ( struct V_9 * V_10 , T_2 type ,
T_1 * V_4 , T_1 * V_5 )
{
int V_16 ;
struct V_17 * V_18 ;
for ( V_16 = 0 ; V_16 < V_10 -> V_15 ; V_16 ++ ) {
if ( V_10 -> V_19 [ V_16 ] . type == type )
break;
}
if ( V_16 >= V_10 -> V_15 )
return - V_13 ;
V_18 = & V_10 -> V_19 [ V_16 ] ;
* V_4 = ( T_1 ) F_12 ( V_18 -> V_4 ) ;
* V_5 = ( T_1 ) F_12 ( V_18 -> V_5 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
int V_11 ;
struct V_20 * V_21 ;
T_1 V_4 , V_5 ;
V_11 = F_11 ( V_10 , V_22 , & V_4 , & V_5 ) ;
if ( V_11 ) {
F_6 ( L_4 ) ;
goto V_23;
}
V_11 = - V_24 ;
V_21 = F_14 ( sizeof( * V_21 ) , V_25 ) ;
if ( ! V_21 ) {
F_7 ( L_5 ) ;
goto V_23;
}
V_11 = F_1 ( V_2 , ( void * ) V_21 , V_4 ,
sizeof( * V_21 ) ) ;
if ( V_11 ) {
F_6 ( L_1 ) ;
goto V_26;
}
if ( strncmp ( V_21 -> V_12 , L_6 , 4 )
&& strncmp ( V_21 -> V_12 , L_7 , 4 ) ) {
F_6 ( L_8 ,
V_21 -> V_12 [ 0 ] , V_21 -> V_12 [ 1 ] ,
V_21 -> V_12 [ 2 ] , V_21 -> V_12 [ 3 ] ) ;
V_11 = - V_13 ;
goto V_26;
}
if ( V_21 -> V_14 != 1 ) {
F_7 ( L_9 ,
V_21 -> V_14 ) ;
V_11 = - V_13 ;
goto V_26;
}
if ( V_21 -> V_27 & V_28 ) {
V_2 -> V_29 . V_30 . V_31 = 1 ;
V_2 -> V_29 . V_30 . V_32 = V_21 -> V_33 ;
V_2 -> V_29 . V_30 . V_34 = V_21 -> V_35 ;
V_2 -> V_29 . V_30 . V_36 = F_15 ( V_21 -> V_37 ) ;
F_6 ( L_10 ,
V_2 -> V_29 . V_30 . V_32 ,
V_2 -> V_29 . V_30 . V_34 ,
V_2 -> V_29 . V_30 . V_36 ) ;
}
V_2 -> V_29 . V_38 . V_39 = F_16 ( V_21 -> V_40 ) ;
V_2 -> V_29 . V_38 . V_5 = F_16 ( V_21 -> V_41 ) ;
F_6 ( L_11 , V_2 -> V_29 . V_38 . V_39 ,
V_2 -> V_29 . V_38 . V_5 ) ;
V_5 = V_2 -> V_29 . V_38 . V_39 * V_2 -> V_29 . V_38 . V_5 ;
if ( V_5 > 0 ) {
V_11 = - V_24 ;
V_2 -> V_29 . V_38 . V_42 = F_14 ( V_5 , V_25 ) ;
if ( ! V_2 -> V_29 . V_38 . V_42 )
goto V_26;
V_11 = F_1 ( V_2 , ( void * ) V_2 -> V_29 . V_38 . V_42 ,
V_4 + sizeof( * V_21 ) , V_5 ) ;
if ( V_11 ) {
F_17 ( V_2 -> V_29 . V_38 . V_42 ) ;
V_2 -> V_29 . V_38 . V_42 = NULL ;
V_2 -> V_29 . V_38 . V_39 = 0 ;
V_2 -> V_29 . V_38 . V_5 = 0 ;
F_6 ( L_12 , V_11 ) ;
}
}
V_26:
F_17 ( V_21 ) ;
V_23:
return V_11 ;
}
static void
F_18 ( struct V_1 * V_2 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_43 ; V_16 += 4 )
F_19 ( V_2 , V_16 , 0 ) ;
F_8 ( V_2 , & V_44 , 0 ,
sizeof( struct V_9 ) ) ;
for ( V_16 = 0 ; V_16 < V_45 ; V_16 ++ )
F_8 ( V_2 , & V_46 [ V_16 ] ,
sizeof( struct V_9 ) +
( V_16 * sizeof( struct V_17 ) )
, sizeof( struct V_17 ) ) ;
}
static int
F_20 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = V_2 -> V_48 ;
T_1 V_49 ;
int V_11 = 0 ;
T_1 V_50 ;
V_49 = F_21 ( V_2 , V_51 ) ;
if ( ! ( V_49 & V_52 ) ) {
V_11 = F_22 ( V_48 , V_53 , & V_50 ) ;
if ( V_11 ) {
F_7 ( L_13 ,
F_23 ( V_48 ) ) ;
goto V_23;
}
F_24 ( V_54 L_14
L_15
L_16 , V_50 ) ;
if ( V_50 )
V_11 = F_25 ( V_48 ,
V_53 , V_50 ) ;
if ( V_11 ) {
F_7 ( L_17 ,
F_23 ( V_48 ) ) ;
goto V_23;
}
F_18 ( V_2 ) ;
}
V_23:
return V_11 ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_11 ;
struct V_9 * V_10 ;
if ( F_20 ( V_2 ) )
return - 1 ;
V_10 = F_14 ( sizeof( * V_10 ) , V_25 ) ;
if ( ! V_10 ) {
F_7 ( L_18 ) ;
return - V_24 ;
}
V_11 = F_5 ( V_2 , V_10 , 0 ) ;
if ( V_11 )
goto V_23;
V_11 = F_13 ( V_2 , V_10 ) ;
V_23:
F_17 ( V_10 ) ;
return V_11 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_55 ;
T_2 V_56 ;
for ( V_55 = 5000 ; V_55 > 0 ; V_55 -- ) {
V_56 = F_28 ( V_2 , V_2 -> V_29 . V_57 . V_58 ) ;
V_56 ^= F_28 ( V_2 , V_2 -> V_29 . V_57 . V_58 ) ;
if ( ! V_56 )
return 0 ;
F_29 ( 5 ) ;
}
return - V_13 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_27 ( V_2 ) ;
if ( V_11 )
return V_11 ;
F_31 ( V_2 , V_2 -> V_29 . V_57 . V_58 , V_59 ) ;
V_11 = F_27 ( V_2 ) ;
return V_11 ;
}
static int F_32 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 , int V_5 )
{
F_3 ( V_2 , V_3 , V_2 -> V_29 . V_57 . V_58 + V_4 ,
V_5 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
T_1 V_50 ;
for ( V_50 = 0 ; V_50 < V_62 ; V_50 += V_63 ) {
F_32 ( V_2 , V_61 , V_50 ,
sizeof( V_64 ) - 1 ) ;
if ( memcmp ( V_61 -> V_65 , V_64 ,
sizeof( V_64 ) - 1 ) == 0 ) {
V_2 -> V_29 . V_57 . V_66 = V_50 ;
F_32 ( V_2 , V_61 , V_50 ,
sizeof( * V_61 ) ) ;
return 1 ;
}
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
T_1 V_49 ;
V_49 = F_21 ( V_2 , V_51 ) ;
if ( F_22 ( V_2 -> V_48 , V_67 ,
& V_2 -> V_29 . V_57 . V_58 ) ) {
F_7 ( L_19 ,
F_23 ( V_2 -> V_48 ) ) ;
return - V_13 ;
}
V_2 -> V_29 . V_57 . V_31 = 1 ;
V_2 -> V_29 . V_57 . V_68 = V_49 & V_69 ? 1 : 0 ;
V_11 = F_30 ( V_2 ) ;
if ( V_11 ) {
F_6 ( L_20 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
static T_3 F_35 ( T_3 * V_6 , int V_5 )
{
T_3 V_70 = 0 ;
while ( V_5 -- > 0 )
V_70 += * V_6 ++ ;
return V_70 ;
}
static int F_36 ( struct V_60 * V_61 , T_1 V_71 ,
T_1 * V_4 , T_1 * V_5 )
{
int V_16 ;
struct V_72 * V_73 ;
for ( V_16 = 0 ; V_16 < V_74 ; V_16 ++ ) {
T_1 type = F_15 ( V_61 -> V_75 [ V_16 ] . type ) ;
type &= V_76 ;
if ( type == V_71 )
break;
}
if ( V_16 >= V_74 )
return - V_13 ;
V_73 = & V_61 -> V_75 [ V_16 ] ;
* V_4 = F_15 ( V_73 -> V_4 ) ;
* V_5 = F_15 ( V_73 -> V_77 ) ;
return 0 ;
}
static int F_37 ( struct V_78 * V_79 )
{
if ( V_79 -> V_12 [ 0 ] != 'S' || V_79 -> V_12 [ 1 ] != 'M' ) {
F_6 ( L_21 ,
V_79 -> V_12 [ 0 ] , V_79 -> V_12 [ 1 ] ) ;
return - V_13 ;
}
if ( V_79 -> V_32 != 0 ) {
F_7 ( L_22 ,
V_79 -> V_32 ) ;
return - V_13 ;
}
V_79 -> V_80 = F_16 ( ( V_81 V_82 ) V_79 -> V_80 ) ;
V_79 -> V_70 = F_16 ( ( V_81 V_82 ) V_79 -> V_70 ) ;
V_79 -> V_5 = F_16 ( ( V_81 V_82 ) V_79 -> V_5 ) ;
if ( F_35 ( ( T_3 * ) V_79 , V_79 -> V_5 / 2 ) ) {
F_7 ( L_23 ) ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
memcpy ( V_2 -> V_29 . V_83 , V_79 -> V_83 , V_84 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
memcpy ( V_2 -> V_29 . V_85 , V_79 -> V_85 , V_86 ) ;
V_2 -> V_29 . V_85 [ V_86 ] = '\0' ;
return 0 ;
}
static void * F_40 ( void * const V_87 , const T_2 V_88 , const T_2 V_89 )
{
struct V_90 * V_91 = V_87 ;
do {
switch ( V_89 ) {
default:
if ( V_91 -> V_89 == V_89 )
case 0xFF :
if ( V_91 -> V_88 == V_88 )
return V_91 ;
}
V_91 = V_87 + F_16 ( V_91 -> V_92 ) ;
} while ( V_91 != V_87 );
return NULL ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_78 * V_93 )
{
int V_16 ;
int V_94 = 0 ;
int V_95 = 0 ;
struct V_96 * V_97 ;
struct V_96 V_98 ;
V_97 = F_40 ( V_93 , 'P' , 'M' ) ;
if ( ! V_97 ) {
F_6 ( L_24 ) ;
F_6 ( L_25 ) ;
V_98 . V_12 [ 0 ] = 'P' ;
V_98 . V_12 [ 1 ] = 'M' ;
V_98 . V_32 = 0 ;
V_98 . V_34 = 2 ;
V_98 . V_99 = 8 ;
V_98 . V_100 = sizeof( struct V_101 ) ;
for ( V_16 = 0 ; V_16 < V_102 ; V_16 ++ ) {
V_98 . V_103 [ V_16 ] . V_104 = 0 ;
V_98 . V_103 [ V_16 ] . V_105 = V_16 ;
V_98 . V_103 [ V_16 ] . V_106 = 0xf6 ;
V_98 . V_103 [ V_16 ] . V_107 = 0x10 ;
V_98 . V_103 [ V_16 ] . V_108 = 0x43 ;
V_98 . V_103 [ V_16 ] . V_109 = 0xeb ;
}
V_97 = & V_98 ;
}
if ( V_97 -> V_32 != 0 ) {
F_7 ( L_26 ,
V_97 -> V_32 ) ;
return - V_13 ;
}
F_6 ( L_27 , V_97 -> V_99 ) ;
V_2 -> V_29 . V_110 = 0 ;
for ( V_16 = 0 ; V_16 < V_97 -> V_99 ; V_16 ++ ) {
struct V_101 * V_111 = & V_97 -> V_103 [ V_16 ] ;
switch ( V_111 -> V_104 & 0xF ) {
case V_112 :
F_6 ( L_28 , V_16 ) ;
continue;
case V_113 :
F_6 ( L_29 , V_16 ) ;
V_2 -> V_29 . V_110 &= ~ ( 1 << V_16 ) ;
V_95 ++ ;
continue;
case V_114 :
F_6 ( L_30 , V_16 ) ;
V_2 -> V_29 . V_110 |= ( 1 << V_16 ) ;
V_94 ++ ;
break;
}
V_2 -> V_29 . V_103 [ V_16 ] . V_106 = V_111 -> V_106 ;
V_2 -> V_29 . V_103 [ V_16 ] . V_107 = V_111 -> V_107 ;
V_2 -> V_29 . V_103 [ V_16 ] . V_108 = V_111 -> V_108 ;
V_2 -> V_29 . V_103 [ V_16 ] . V_109 = V_111 -> V_109 ;
}
V_2 -> V_29 . V_115 = V_95 + V_94 ;
V_2 -> V_29 . V_116 = V_94 ;
F_6 ( L_31 ,
V_2 -> V_29 . V_115 , V_2 -> V_29 . V_116 ) ;
F_6 ( L_32 , V_2 -> V_29 . V_110 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_78 * V_93 )
{
struct V_117 * V_118 ;
V_118 = F_40 ( V_93 , 'M' , 'C' ) ;
if ( ! V_118 ) {
F_6 ( L_33 ) ;
return 0 ;
}
if ( V_118 -> V_32 != 0 ) {
F_6 ( L_34
L_35 , V_118 -> V_32 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
int V_11 ;
struct V_78 * V_93 ;
T_1 V_4 , V_5 ;
V_11 = F_36 ( V_61 , V_119 , & V_4 , & V_5 ) ;
if ( V_11 ) {
F_6 ( L_36 ) ;
goto V_23;
}
if ( V_5 == 0 )
goto V_23;
V_11 = - V_24 ;
V_93 = F_14 ( V_5 , V_25 ) ;
if ( ! V_93 ) {
F_6 ( L_37 ) ;
goto V_23;
}
V_11 = F_32 ( V_2 , ( void * ) V_93 , V_4 , V_5 ) ;
if ( V_11 ) {
F_6 ( L_38 ,
V_4 , V_5 ) ;
goto V_26;
}
V_11 = F_37 ( V_93 ) ;
if ( V_11 ) {
F_6 ( L_39 ) ;
goto V_26;
}
V_11 = F_38 ( V_2 , V_93 ) ;
if ( V_11 ) {
F_6 ( L_40 ) ;
goto V_26;
}
F_6 ( L_41 ,
F_44 ( V_2 -> V_29 . V_83 ) ) ;
V_11 = F_39 ( V_2 , V_93 ) ;
if ( V_11 ) {
F_6 ( L_42 ) ;
goto V_26;
}
F_6 ( L_43 , V_2 -> V_29 . V_85 ) ;
V_11 = F_41 ( V_2 , V_93 ) ;
if ( V_11 ) {
F_6 ( L_44 ) ;
goto V_26;
}
V_11 = F_42 ( V_2 , V_93 ) ;
if ( V_11 ) {
F_6 ( L_45 ) ;
goto V_26;
}
V_26:
F_17 ( V_93 ) ;
V_23:
return V_11 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_121 -> V_116 ; V_16 ++ ) {
struct V_122 * V_123 = & V_121 -> V_124 [ V_16 ] ;
if ( ! F_46 ( V_2 , V_16 ) )
continue;
if ( * ( V_125 * ) V_123 -> V_83 == 0 ) {
V_2 -> V_29 . V_110 &= ~ ( 1 << V_16 ) ;
continue;
}
memcpy ( V_2 -> V_29 . V_103 [ V_16 ] . V_83 , V_123 -> V_83 ,
V_84 ) ;
V_2 -> V_29 . V_103 [ V_16 ] . V_126 =
( V_123 -> V_127 & 0xF0 ) >> 4 ;
V_2 -> V_29 . V_103 [ V_16 ] . V_128 =
( V_123 -> V_127 & 0x0F ) ;
V_2 -> V_29 . V_103 [ V_16 ] . V_129 =
( V_123 -> V_130 & 0xF0 ) >> 4 ;
V_2 -> V_29 . V_103 [ V_16 ] . V_131 =
( V_123 -> V_130 & 0x0F ) ;
V_2 -> V_29 . V_103 [ V_16 ] . V_27 = V_123 -> V_27 ;
F_6 ( L_46
L_47 ,
V_16 ,
F_44 ( V_2 -> V_29 . V_103 [ V_16 ] . V_83 ) ,
V_2 -> V_29 . V_103 [ V_16 ] . V_126 ,
V_2 -> V_29 . V_103 [ V_16 ] . V_128 ,
V_2 -> V_29 . V_103 [ V_16 ] . V_129 ,
V_2 -> V_29 . V_103 [ V_16 ] . V_131 ,
V_2 -> V_29 . V_103 [ V_16 ] . V_27 ) ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
int V_11 , V_16 ;
T_1 V_4 , V_5 ;
struct V_90 * V_91 ;
struct V_120 * V_121 ;
struct V_120 V_132 ;
V_11 = F_36 ( V_61 , V_133 , & V_4 , & V_5 ) ;
if ( V_11 ) {
F_6 ( L_48 ) ;
F_6 ( L_49 ) ;
V_132 . V_88 = 'h' ;
V_132 . V_116 = 8 ;
for ( V_16 = 0 ; V_16 < V_102 ; V_16 ++ ) {
memcpy ( V_132 . V_124 [ V_16 ] . V_83 ,
V_2 -> V_29 . V_83 , V_84 ) ;
V_132 . V_124 [ V_16 ] . V_127 = 0x98 ;
V_132 . V_124 [ V_16 ] . V_27 = 0x0 ;
V_132 . V_124 [ V_16 ] . V_130 = 0x0 ;
}
V_5 = sizeof( struct V_120 ) ;
V_121 = & V_132 ;
}
if ( V_5 == 0 )
goto V_23;
V_11 = - V_24 ;
V_91 = F_14 ( V_5 , V_25 ) ;
if ( ! V_91 ) {
F_6 ( L_50 ) ;
goto V_23;
}
V_11 = F_32 ( V_2 , ( void * ) V_91 , V_4 , V_5 ) ;
if ( V_11 ) {
F_6 ( L_51 ) ;
goto V_26;
}
V_11 = - V_13 ;
V_121 = F_40 ( V_91 , 'h' , 0xFF ) ;
if ( ! V_121 ) {
F_6 ( L_52 ) ;
goto V_26;
}
V_11 = F_45 ( V_2 , V_121 ) ;
if ( V_11 ) {
F_6 ( L_53 ) ;
goto V_26;
}
V_26:
F_17 ( V_91 ) ;
V_23:
return V_11 ;
}
int F_48 ( struct V_1 * V_2 )
{
int V_11 ;
struct V_60 * V_61 ;
V_11 = F_34 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_61 = F_14 ( sizeof( * V_61 ) , V_25 ) ;
if ( ! V_61 )
return - V_24 ;
V_11 = - V_13 ;
if ( ! F_33 ( V_2 , V_61 ) ) {
F_6 ( L_54 ) ;
goto V_23;
}
if ( F_15 ( V_61 -> V_134 ) != 2 ) {
F_7 ( L_55 ,
F_15 ( V_61 -> V_134 ) ) ;
goto V_23;
}
V_11 = F_43 ( V_2 , V_61 ) ;
if ( V_11 ) {
F_6 ( L_56 ) ;
goto V_23;
}
V_11 = F_47 ( V_2 , V_61 ) ;
if ( V_11 ) {
F_6 ( L_57 ) ;
goto V_23;
}
V_23:
F_17 ( V_61 ) ;
return V_11 ;
}
int F_49 ( struct V_1 * V_2 ,
const void * V_135 , T_1 V_136 , T_1 V_137 )
{
const T_2 * V_138 ;
T_2 V_139 ;
int V_11 ;
T_1 V_140 , V_49 , V_16 ;
V_49 = V_2 -> V_29 . V_57 . V_58 ;
V_138 = NULL ;
V_11 = V_141 ;
V_140 = V_136 ;
V_138 = ( const T_2 * ) V_135 ;
for ( V_16 = 0 ; V_16 < V_137 ; V_16 ++ ) {
V_139 = F_28 ( V_2 , V_49 + V_140 + V_16 ) ;
if ( V_139 != V_138 [ V_16 ] ) {
V_11 = V_142 ;
break;
}
}
return V_11 ;
}
int F_50 ( struct V_1 * V_2 ,
const void * V_135 , T_1 V_136 , T_1 V_143 )
{
const T_2 * V_138 ;
T_1 V_140 , V_49 , V_16 ;
int V_11 ;
V_49 = V_2 -> V_29 . V_57 . V_58 ;
V_138 = NULL ;
V_11 = F_51 ( V_2 ) ;
if ( V_11 ) {
F_6 ( L_58 , V_11 ) ;
return V_11 ;
}
V_140 = V_136 ;
V_11 = F_52 ( V_2 , V_140 , V_143 ) ;
if ( V_11 ) {
F_6 ( L_59 ,
V_140 ) ;
return V_11 ;
}
V_11 = F_30 ( V_2 ) ;
if ( V_11 ) {
F_6 ( L_60 , V_11 ) ;
return V_11 ;
}
V_138 = ( const T_2 * ) V_135 ;
for ( V_16 = 0 ; V_16 < V_143 ; V_16 ++ ) {
switch ( V_2 -> V_29 . V_57 . V_144 ) {
case V_145 :
{
F_31 ( V_2 ,
( V_49 + 0xAAA ) , 0xAA ) ;
F_31 ( V_2 ,
( V_49 + 0x555 ) , 0x55 ) ;
F_31 ( V_2 ,
( V_49 + 0xAAA ) , 0xA0 ) ;
F_31 ( V_2 ,
( V_49 + V_140 + V_16 ) ,
( * ( V_138 + V_16 ) ) ) ;
break;
}
case V_146 :
{
F_31 ( V_2 ,
( V_49 + 0x555 ) , 0xAA ) ;
F_31 ( V_2 ,
( V_49 + 0x2AA ) , 0x55 ) ;
F_31 ( V_2 ,
( V_49 + 0x555 ) , 0xA0 ) ;
F_31 ( V_2 ,
( V_49 + V_140 + V_16 ) ,
( * ( V_138 + V_16 ) ) ) ;
break;
}
default:
break;
}
if ( F_53 ( V_2 ,
( V_140 + V_16 ) , 0 ) != 0 ) {
F_6 ( L_61 ,
V_49 + V_140 + V_16 ) ;
return V_147 ;
}
}
V_11 = F_30 ( V_2 ) ;
if ( V_11 ) {
F_6 ( L_60 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
int F_53 ( struct V_1 * V_2 ,
T_1 V_148 , T_2 V_149 )
{
T_1 V_49 ;
T_1 V_150 ;
T_2 V_151 , V_152 ;
T_2 V_153 ;
V_49 = V_2 -> V_29 . V_57 . V_58 ;
for ( V_150 = 0 ; V_150 < 50000 ; V_150 ++ ) {
V_151 = F_28 ( V_2 , V_49 ) ;
V_152 = F_28 ( V_2 , V_49 ) ;
V_153 = ( ( V_151 & V_154 )
^ ( V_152 & V_154 ) ) ;
if ( V_153 == 0 ) {
return 0 ;
} else {
if ( V_152 & V_155 ) {
V_151 = F_28 ( V_2 ,
V_49 ) ;
V_152 = F_28 ( V_2 ,
V_49 ) ;
V_153 =
( ( V_151 & V_154 )
^ ( V_152 & V_154 ) ) ;
if ( V_153 == 0 )
return 0 ;
}
}
if ( V_149 ) {
F_29 ( V_156 ) ;
} else {
F_29 ( V_157 ) ;
}
}
return - 1 ;
}
int F_52 ( struct V_1 * V_2 , T_1 V_158 , T_1 V_5 )
{
T_1 V_49 ;
T_1 V_148 ;
V_49 = V_2 -> V_29 . V_57 . V_58 ;
V_148 = V_158 & V_159 ;
while ( V_148 < V_158 + V_5 ) {
switch ( V_2 -> V_29 . V_57 . V_144 ) {
case V_145 :
F_31 ( V_2 , ( V_49 + 0xAAA ) , 0xAA ) ;
F_31 ( V_2 , ( V_49 + 0x555 ) , 0x55 ) ;
F_31 ( V_2 , ( V_49 + 0xAAA ) , 0x80 ) ;
F_31 ( V_2 , ( V_49 + 0xAAA ) , 0xAA ) ;
F_31 ( V_2 , ( V_49 + 0x555 ) , 0x55 ) ;
F_31 ( V_2 , ( V_49 + V_148 ) , 0x30 ) ;
break;
case V_146 :
F_31 ( V_2 , ( V_49 + 0x555 ) , 0xAA ) ;
F_31 ( V_2 , ( V_49 + 0x2AA ) , 0x55 ) ;
F_31 ( V_2 , ( V_49 + 0x555 ) , 0x80 ) ;
F_31 ( V_2 , ( V_49 + 0x555 ) , 0xAA ) ;
F_31 ( V_2 , ( V_49 + 0x2AA ) , 0x55 ) ;
F_31 ( V_2 , ( V_49 + V_148 ) , 0x30 ) ;
break;
default:
break;
}
if ( F_53 ( V_2 , V_148 , 1 ) != 0 )
return V_160 ;
V_148 += V_161 ;
}
return 0 ;
}
int F_51 ( struct V_1 * V_2 )
{
T_2 V_162 ;
T_2 V_163 ;
T_2 V_164 ;
T_1 V_165 ;
T_1 V_49 ;
int V_11 ;
V_49 = V_2 -> V_29 . V_57 . V_58 ;
V_11 = F_30 ( V_2 ) ;
if ( V_11 ) {
F_6 ( L_60 , V_11 ) ;
return V_11 ;
}
V_2 -> V_29 . V_57 . V_144 = V_166 ;
V_2 -> V_29 . V_57 . V_167 = V_168 ;
V_2 -> V_29 . V_57 . V_163 = V_169 ;
V_165 = V_2 -> V_29 . V_57 . V_68 ? 2 : 1 ;
F_31 ( V_2 , V_49 + 0xAAA , 0xAA ) ;
F_31 ( V_2 , V_49 + 0x555 , 0x55 ) ;
F_31 ( V_2 , V_49 + 0xAAA , 0x90 ) ;
V_162 = F_28 ( V_2 , V_49 ) ;
V_163 = F_28 ( V_2 , V_49 + V_165 ) ;
V_164 = F_28 ( V_2 , V_49 + V_165 + V_165 ) ;
V_11 = F_30 ( V_2 ) ;
if ( V_11 ) {
F_6 ( L_60 , V_11 ) ;
return V_11 ;
}
F_6 ( L_62
L_63 , V_162 , V_163 , V_164 ) ;
V_11 = F_30 ( V_2 ) ;
if ( V_11 != 0 )
return V_11 ;
switch ( V_162 ) {
case V_170 :
switch ( V_164 ) {
case V_171 :
case V_172 :
case V_173 :
V_2 -> V_29 . V_57 . V_144 = V_145 ;
break;
default:
break;
}
break;
case V_174 :
switch ( V_164 ) {
case V_175 :
case V_176 :
V_2 -> V_29 . V_57 . V_144 = V_145 ;
break;
default:
break;
}
break;
case V_177 :
switch ( V_164 ) {
case V_178 :
case V_179 :
V_2 -> V_29 . V_57 . V_144 = V_145 ;
break;
}
break;
case V_180 :
switch ( V_164 ) {
case V_181 :
V_2 -> V_29 . V_57 . V_144 = V_145 ;
break;
}
break;
}
if ( V_2 -> V_29 . V_57 . V_144 == V_166 ) {
V_11 = F_30 ( V_2 ) ;
if ( V_11 ) {
F_6 ( L_60 , V_11 ) ;
return V_11 ;
}
F_31 ( V_2 , ( V_49 + 0x555 ) , 0xAA ) ;
F_31 ( V_2 , ( V_49 + 0x2AA ) , 0x55 ) ;
F_31 ( V_2 , ( V_49 + 0x555 ) , 0x90 ) ;
V_162 = F_28 ( V_2 , V_49 ) ;
V_163 = F_28 ( V_2 , V_49 + V_165 ) ;
V_164 = F_28 ( V_2 , V_49 + V_165 + V_165 ) ;
F_6 ( L_64
L_65 , V_162 , V_163 , V_164 ) ;
V_11 = F_30 ( V_2 ) ;
if ( V_11 != 0 ) {
F_6 ( L_60 , V_11 ) ;
return V_11 ;
}
switch ( V_162 ) {
case V_170 :
switch ( V_163 ) {
case V_182 :
V_2 -> V_29 . V_57 . V_144 = V_146 ;
break;
default:
break;
}
break;
case V_174 :
switch ( V_163 ) {
case V_183 :
V_2 -> V_29 . V_57 . V_144 = V_146 ;
break;
default:
break;
}
break;
case V_177 :
switch ( V_163 ) {
case V_184 :
V_2 -> V_29 . V_57 . V_144 = V_146 ;
break;
}
break;
case V_185 :
switch ( V_163 ) {
case V_186 :
V_2 -> V_29 . V_57 . V_144 = V_146 ;
break;
}
break;
case V_180 :
switch ( V_163 ) {
case V_186 :
V_2 -> V_29 . V_57 . V_144 = V_146 ;
break;
}
break;
default:
return V_187 ;
}
}
if ( V_2 -> V_29 . V_57 . V_144 == V_166 )
return V_187 ;
V_2 -> V_29 . V_57 . V_167 = V_162 ;
V_2 -> V_29 . V_57 . V_163 = V_163 ;
V_2 -> V_29 . V_57 . V_164 = V_164 ;
return 0 ;
}
