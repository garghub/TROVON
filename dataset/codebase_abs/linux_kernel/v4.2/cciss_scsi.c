static T_1 *
F_1 ( T_2 * V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
T_3 V_8 ;
V_5 = V_1 -> V_9 ;
V_7 = & V_5 -> V_10 ;
if ( V_7 -> V_11 < 0 )
return NULL ;
V_3 = V_7 -> V_12 [ V_7 -> V_11 ] ;
memset ( & V_3 -> V_13 , 0 , sizeof( V_3 -> V_13 ) ) ;
memset ( & V_3 -> V_14 , 0 , sizeof( V_3 -> V_14 ) ) ;
V_3 -> V_13 . V_15 = V_3 -> V_15 ;
V_3 -> V_13 . V_16 = V_3 -> V_16 ;
V_8 . V_17 = ( V_18 ) ( V_3 -> V_15 + sizeof( T_1 ) ) ;
V_7 -> V_11 -- ;
V_3 -> V_13 . V_19 . V_20 . V_21 = V_8 . V_22 . V_21 ;
V_3 -> V_13 . V_19 . V_20 . V_23 = V_8 . V_22 . V_23 ;
V_3 -> V_13 . V_19 . V_24 = sizeof( V_25 ) ;
V_3 -> V_13 . V_26 = V_1 -> V_26 ;
V_3 -> V_13 . V_27 = & V_3 -> V_14 ;
return ( T_1 * ) V_3 ;
}
static void
F_2 ( T_2 * V_1 , T_1 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_5 = V_1 -> V_9 ;
V_7 = & V_5 -> V_10 ;
V_7 -> V_11 ++ ;
if ( V_7 -> V_11 >= V_7 -> V_28 ) {
F_3 ( & V_1 -> V_29 -> V_30 ,
L_1 ) ;
F_4 () ;
}
V_7 -> V_12 [ V_7 -> V_11 ] = (struct V_2 * ) V_3 ;
}
static int
F_5 ( T_2 * V_1 , struct V_4 * V_5 )
{
int V_31 ;
struct V_6 * V_7 ;
T_4 V_32 ;
V_7 = & V_5 -> V_10 ;
V_7 -> V_28 = V_33 + 2 ;
V_5 -> V_34 = F_6 ( V_1 ,
V_1 -> V_35 , V_7 -> V_28 ) ;
if ( ! V_5 -> V_34 && V_1 -> V_35 > 0 )
return - V_36 ;
V_32 = sizeof( struct V_2 ) * V_7 -> V_28 ;
F_7 ( ( sizeof( * V_7 -> V_37 ) % V_38 ) != 0 ) ;
V_7 -> V_37 = (struct V_2 * )
F_8 ( V_1 -> V_29 , V_32 , & V_7 -> V_39 ) ;
if ( V_7 -> V_37 == NULL ) {
F_9 ( V_5 -> V_34 , V_7 -> V_28 ) ;
V_5 -> V_34 = NULL ;
return - V_36 ;
}
V_7 -> V_12 = F_10 ( sizeof( V_7 -> V_12 [ 0 ] ) * V_7 -> V_28 , V_40 ) ;
if ( ! V_7 -> V_12 ) {
F_11 ( V_1 -> V_29 , V_32 , V_7 -> V_37 ,
V_7 -> V_39 ) ;
return - 1 ;
}
for ( V_31 = 0 ; V_31 < V_7 -> V_28 ; V_31 ++ ) {
V_7 -> V_12 [ V_31 ] = & V_7 -> V_37 [ V_31 ] ;
V_7 -> V_12 [ V_31 ] -> V_15 = ( V_41 ) ( V_7 -> V_39 +
( sizeof( struct V_2 ) * V_31 ) ) ;
V_7 -> V_12 [ V_31 ] -> V_16 = V_31 ;
}
V_7 -> V_11 = V_7 -> V_28 - 1 ;
return 0 ;
}
static void
F_12 ( T_2 * V_1 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
T_4 V_32 ;
V_5 = V_1 -> V_9 ;
V_7 = & V_5 -> V_10 ;
if ( V_7 -> V_11 != V_7 -> V_28 - 1 ) {
F_13 ( & V_1 -> V_29 -> V_30 ,
L_2 ,
V_7 -> V_28 - V_7 -> V_11 ) ;
}
V_32 = sizeof( struct V_2 ) * V_7 -> V_28 ;
F_11 ( V_1 -> V_29 , V_32 , V_7 -> V_37 , V_7 -> V_39 ) ;
V_7 -> V_37 = NULL ;
F_9 ( V_5 -> V_34 , V_7 -> V_28 ) ;
F_14 ( V_7 -> V_12 ) ;
V_7 -> V_12 = NULL ;
}
static int
F_15 ( T_2 * V_1 , int * V_42 , int * V_43 , int * V_44 )
{
int V_31 , V_45 = 0 ;
unsigned char V_46 [ V_47 ] ;
memset ( & V_46 [ 0 ] , 0 , V_47 ) ;
V_46 [ V_48 ] = 1 ;
for ( V_31 = 0 ; V_31 < V_49 [ V_1 -> V_26 ] . V_50 ; V_31 ++ )
V_46 [ V_49 [ V_1 -> V_26 ] . V_30 [ V_31 ] . V_43 ] = 1 ;
for ( V_31 = 0 ; V_31 < V_47 ; V_31 ++ ) {
if ( ! V_46 [ V_31 ] ) {
* V_42 = 0 ; * V_43 = V_31 ; * V_44 = 0 ; V_45 = 1 ;
break;
}
}
return ( ! V_45 ) ;
}
static int
F_16 ( T_2 * V_1 , int V_51 ,
struct V_52 * V_53 ,
struct V_54 * V_55 , int * V_56 )
{
int V_57 = V_49 [ V_1 -> V_26 ] . V_50 ;
struct V_52 * V_58 ;
int V_31 , V_42 , V_43 , V_44 ;
unsigned char V_59 [ 8 ] , V_60 [ 8 ] ;
if ( V_57 >= V_47 ) {
F_13 ( & V_1 -> V_29 -> V_30 , L_3
L_4 ) ;
return - 1 ;
}
V_42 = V_43 = - 1 ;
V_44 = 0 ;
if ( V_53 -> V_61 [ 4 ] != 0 ) {
memcpy ( V_59 , V_53 -> V_61 , 8 ) ;
V_59 [ 4 ] = 0 ;
for ( V_31 = 0 ; V_31 < V_57 ; V_31 ++ ) {
V_58 = & V_49 [ V_1 -> V_26 ] . V_30 [ V_31 ] ;
memcpy ( V_60 , V_58 -> V_61 , 8 ) ;
V_60 [ 4 ] = 0 ;
if ( memcmp ( V_59 , V_60 , 8 ) == 0 ) {
V_42 = V_58 -> V_42 ;
V_43 = V_58 -> V_43 ;
V_44 = V_53 -> V_61 [ 4 ] ;
break;
}
}
}
V_58 = & V_49 [ V_1 -> V_26 ] . V_30 [ V_57 ] ;
if ( V_44 == 0 ) {
if ( F_15 ( V_1 ,
& V_58 -> V_42 , & V_58 -> V_43 , & V_58 -> V_44 ) != 0 )
return - 1 ;
} else {
V_58 -> V_42 = V_42 ;
V_58 -> V_43 = V_43 ;
V_58 -> V_44 = V_44 ;
}
V_55 [ * V_56 ] . V_42 = V_58 -> V_42 ;
V_55 [ * V_56 ] . V_43 = V_58 -> V_43 ;
V_55 [ * V_56 ] . V_44 = V_58 -> V_44 ;
( * V_56 ) ++ ;
memcpy ( V_58 -> V_61 , V_53 -> V_61 , 8 ) ;
memcpy ( V_58 -> V_62 , V_53 -> V_62 , sizeof( V_58 -> V_62 ) ) ;
memcpy ( V_58 -> V_63 , V_53 -> V_63 , sizeof( V_58 -> V_63 ) ) ;
memcpy ( V_58 -> V_64 , V_53 -> V_64 , sizeof( V_58 -> V_64 ) ) ;
V_58 -> V_65 = V_53 -> V_65 ;
V_49 [ V_1 -> V_26 ] . V_50 ++ ;
if ( V_51 != - 1 )
F_17 ( & V_1 -> V_29 -> V_30 , L_5 ,
F_18 ( V_58 -> V_65 ) , V_51 ,
V_58 -> V_42 , V_58 -> V_43 , V_58 -> V_44 ) ;
return 0 ;
}
static void
F_19 ( T_2 * V_1 , int V_51 , int V_66 ,
struct V_54 * V_67 , int * V_68 )
{
int V_31 ;
struct V_52 V_58 ;
if ( V_66 < 0 || V_66 >= V_47 ) return;
V_58 = V_49 [ V_1 -> V_26 ] . V_30 [ V_66 ] ;
V_67 [ * V_68 ] . V_42 = V_58 . V_42 ;
V_67 [ * V_68 ] . V_43 = V_58 . V_43 ;
V_67 [ * V_68 ] . V_44 = V_58 . V_44 ;
( * V_68 ) ++ ;
for ( V_31 = V_66 ; V_31 < V_49 [ V_1 -> V_26 ] . V_50 - 1 ; V_31 ++ )
V_49 [ V_1 -> V_26 ] . V_30 [ V_31 ] = V_49 [ V_1 -> V_26 ] . V_30 [ V_31 + 1 ] ;
V_49 [ V_1 -> V_26 ] . V_50 -- ;
F_17 ( & V_1 -> V_29 -> V_30 , L_6 ,
F_18 ( V_58 . V_65 ) , V_51 ,
V_58 . V_42 , V_58 . V_43 , V_58 . V_44 ) ;
}
static void F_20 ( T_2 * V_1 , char * V_61 )
{
unsigned long V_69 ;
int V_31 , V_70 ;
F_21 ( V_1 , V_69 ) ;
for ( V_31 = 0 ; V_31 < V_49 [ V_1 -> V_26 ] . V_50 ; V_31 ++ ) {
if ( memcmp ( V_61 ,
V_49 [ V_1 -> V_26 ] . V_30 [ V_31 ] . V_61 , 8 ) == 0 ) {
for ( V_70 = V_31 ; V_70 < V_49 [ V_1 -> V_26 ] . V_50 - 1 ; V_70 ++ )
V_49 [ V_1 -> V_26 ] . V_30 [ V_70 ] =
V_49 [ V_1 -> V_26 ] . V_30 [ V_70 + 1 ] ;
V_49 [ V_1 -> V_26 ] . V_50 -- ;
break;
}
}
F_22 ( V_1 , V_69 ) ;
}
static int F_23 ( struct V_52 * V_71 ,
struct V_52 * V_72 )
{
return V_71 -> V_65 == V_72 -> V_65 &&
memcmp ( V_71 -> V_61 , V_72 -> V_61 ,
sizeof( V_71 -> V_61 ) ) == 0 &&
memcmp ( V_71 -> V_64 , V_72 -> V_64 ,
sizeof( V_71 -> V_64 ) ) == 0 &&
memcmp ( V_71 -> V_62 , V_72 -> V_62 ,
sizeof( V_71 -> V_62 ) ) == 0 &&
memcmp ( V_71 -> V_73 , V_72 -> V_73 ,
sizeof( V_71 -> V_73 ) ) == 0 &&
memcmp ( V_71 -> V_63 , V_72 -> V_63 ,
sizeof( V_71 -> V_63 ) ) == 0 ;
}
static int
F_24 ( T_2 * V_1 , int V_51 ,
struct V_52 V_58 [] , int V_74 )
{
int V_31 , V_70 , V_45 , V_75 = 0 ;
struct V_52 * V_76 ;
unsigned long V_69 ;
struct V_54 * V_55 , * V_67 ;
int V_56 , V_68 ;
struct V_77 * V_78 = NULL ;
V_55 = F_25 ( sizeof( * V_55 ) * V_47 ,
V_40 ) ;
V_67 = F_25 ( sizeof( * V_67 ) * V_47 ,
V_40 ) ;
if ( ! V_55 || ! V_67 ) {
F_13 ( & V_1 -> V_29 -> V_30 ,
L_7 ) ;
goto V_79;
}
F_21 ( V_1 , V_69 ) ;
if ( V_51 != - 1 )
V_78 = V_1 -> V_9 -> V_80 ;
V_31 = 0 ;
V_68 = 0 ;
V_56 = 0 ;
while ( V_31 < V_49 [ V_1 -> V_26 ] . V_50 ) {
V_76 = & V_49 [ V_1 -> V_26 ] . V_30 [ V_31 ] ;
V_45 = 0 ;
for ( V_70 = 0 ; V_70 < V_74 ; V_70 ++ ) {
if ( F_26 ( V_58 [ V_70 ] . V_61 ,
V_76 -> V_61 ) ) {
if ( F_23 ( & V_58 [ V_70 ] , V_76 ) )
V_45 = 2 ;
else
V_45 = 1 ;
break;
}
}
if ( V_45 == 0 ) {
V_75 ++ ;
F_19 ( V_1 , V_51 , V_31 ,
V_67 , & V_68 ) ;
} else if ( V_45 == 1 ) {
V_75 ++ ;
F_17 ( & V_1 -> V_29 -> V_30 ,
L_8 ,
V_51 , V_76 -> V_42 , V_76 -> V_43 , V_76 -> V_44 ) ;
F_19 ( V_1 , V_51 , V_31 ,
V_67 , & V_68 ) ;
if ( F_16 ( V_1 , V_51 , & V_58 [ V_70 ] ,
V_55 , & V_56 ) != 0 )
F_4 () ;
V_76 -> V_65 = V_58 [ V_70 ] . V_65 ;
memcpy ( V_76 -> V_64 , V_58 [ V_70 ] . V_64 ,
sizeof( V_76 -> V_64 ) ) ;
memcpy ( V_76 -> V_62 , V_58 [ V_70 ] . V_62 ,
sizeof( V_76 -> V_62 ) ) ;
memcpy ( V_76 -> V_73 , V_58 [ V_70 ] . V_73 ,
sizeof( V_76 -> V_73 ) ) ;
memcpy ( V_76 -> V_63 , V_58 [ V_70 ] . V_63 ,
sizeof( V_76 -> V_63 ) ) ;
} else
V_31 ++ ;
}
for ( V_31 = 0 ; V_31 < V_74 ; V_31 ++ ) {
V_45 = 0 ;
for ( V_70 = 0 ; V_70 < V_49 [ V_1 -> V_26 ] . V_50 ; V_70 ++ ) {
V_76 = & V_49 [ V_1 -> V_26 ] . V_30 [ V_70 ] ;
if ( F_26 ( V_58 [ V_31 ] . V_61 ,
V_76 -> V_61 ) ) {
if ( F_23 ( & V_58 [ V_31 ] , V_76 ) )
V_45 = 2 ;
else
V_45 = 1 ;
break;
}
}
if ( ! V_45 ) {
V_75 ++ ;
if ( F_16 ( V_1 , V_51 , & V_58 [ V_31 ] ,
V_55 , & V_56 ) != 0 )
break;
} else if ( V_45 == 1 ) {
V_75 ++ ;
F_13 ( & V_1 -> V_29 -> V_30 ,
L_9 ) ;
}
}
F_22 ( V_1 , V_69 ) ;
if ( V_51 == - 1 || ! V_75 )
goto V_79;
for ( V_31 = 0 ; V_31 < V_68 ; V_31 ++ ) {
struct V_81 * V_82 =
F_27 ( V_78 , V_67 [ V_31 ] . V_42 ,
V_67 [ V_31 ] . V_43 , V_67 [ V_31 ] . V_44 ) ;
if ( V_82 != NULL ) {
F_28 ( V_82 ) ;
F_29 ( V_82 ) ;
} else {
F_13 ( & V_1 -> V_29 -> V_30 , L_10
L_11 ,
V_51 , V_67 [ V_31 ] . V_42 ,
V_67 [ V_31 ] . V_43 , V_67 [ V_31 ] . V_44 ) ;
}
}
for ( V_31 = 0 ; V_31 < V_56 ; V_31 ++ ) {
int V_83 ;
V_83 = F_30 ( V_78 , V_55 [ V_31 ] . V_42 ,
V_55 [ V_31 ] . V_43 , V_55 [ V_31 ] . V_44 ) ;
if ( V_83 == 0 )
continue;
F_13 ( & V_1 -> V_29 -> V_30 , L_12
L_13 ,
V_51 , V_55 [ V_31 ] . V_42 , V_55 [ V_31 ] . V_43 , V_55 [ V_31 ] . V_44 ) ;
F_20 ( V_1 , V_55 [ V_31 ] . V_61 ) ;
}
V_79:
F_14 ( V_55 ) ;
F_14 ( V_67 ) ;
return 0 ;
}
static int
F_31 ( T_2 * V_1 , int V_42 , int V_43 , int V_44 , char * V_61 )
{
int V_31 ;
struct V_52 * V_58 ;
unsigned long V_69 ;
F_21 ( V_1 , V_69 ) ;
for ( V_31 = 0 ; V_31 < V_49 [ V_1 -> V_26 ] . V_50 ; V_31 ++ ) {
V_58 = & V_49 [ V_1 -> V_26 ] . V_30 [ V_31 ] ;
if ( V_58 -> V_42 == V_42 &&
V_58 -> V_43 == V_43 &&
V_58 -> V_44 == V_44 ) {
memcpy ( V_61 , & V_58 -> V_61 [ 0 ] , 8 ) ;
F_22 ( V_1 , V_69 ) ;
return 0 ;
}
}
F_22 ( V_1 , V_69 ) ;
return - 1 ;
}
static void
F_32 ( T_2 * V_1 )
{
struct V_4 * V_84 ;
V_49 [ V_1 -> V_26 ] . V_50 = 0 ;
V_84 = (struct V_4 * )
F_10 ( sizeof( * V_84 ) , V_40 ) ;
if ( V_84 == NULL )
return;
V_84 -> V_80 = NULL ;
F_33 ( & V_84 -> V_85 ) ;
V_84 -> V_86 = 0 ;
if ( F_5 ( V_1 , V_84 ) != 0 ) {
F_14 ( V_84 ) ;
V_84 = NULL ;
}
V_1 -> V_9 = V_84 ;
return;
}
static void F_34 ( T_1 * V_3 , int V_87 ,
V_41 V_88 )
{
struct V_89 * V_13 ;
T_2 * V_1 ;
V_25 * V_90 ;
V_90 = V_3 -> V_27 ;
if ( V_3 -> V_91 . Type . Type == V_92 ) {
V_3 -> V_93 = V_94 ;
return;
}
V_13 = (struct V_89 * ) V_3 -> V_95 ;
V_1 = V_96 [ V_3 -> V_26 ] ;
F_35 ( V_13 ) ;
if ( V_3 -> V_97 . V_98 > V_1 -> V_99 )
F_36 ( V_1 , V_3 ) ;
V_13 -> V_100 = ( V_101 << 16 ) ;
V_13 -> V_100 |= ( V_102 << 8 ) ;
V_13 -> V_100 |= ( V_90 -> V_103 ) ;
memcpy ( V_13 -> V_104 , V_90 -> V_105 ,
V_90 -> V_106 > V_107 ?
V_107 :
V_90 -> V_106 ) ;
F_37 ( V_13 , V_90 -> V_108 ) ;
if( V_90 -> V_109 != 0 )
{
switch( V_90 -> V_109 )
{
case V_110 :
if ( ! V_90 -> V_103 ) {
V_13 -> V_100 = V_111 << 16 ;
}
break;
case V_112 :
break;
case V_113 :
F_13 ( & V_1 -> V_29 -> V_30 , L_14
L_15
L_16 , V_3 ) ;
break;
case V_114 : {
V_13 -> V_100 = V_111 << 16 ;
}
break;
case V_115 :
V_13 -> V_100 = V_116 << 16 ;
F_13 ( & V_1 -> V_29 -> V_30 ,
L_17 , V_3 ) ;
break;
case V_117 :
V_13 -> V_100 = V_116 << 16 ;
F_13 ( & V_1 -> V_29 -> V_30 ,
L_18 , V_3 ) ;
break;
case V_118 :
V_13 -> V_100 = V_116 << 16 ;
F_13 ( & V_1 -> V_29 -> V_30 ,
L_19 , V_3 ) ;
break;
case V_119 :
V_13 -> V_100 = V_120 << 16 ;
F_13 ( & V_1 -> V_29 -> V_30 , L_20 , V_3 ) ;
break;
case V_121 :
V_13 -> V_100 = V_116 << 16 ;
F_13 ( & V_1 -> V_29 -> V_30 ,
L_21 , V_3 ) ;
break;
case V_122 :
V_13 -> V_100 = V_120 << 16 ;
F_13 ( & V_1 -> V_29 -> V_30 , L_22
L_23 , V_3 ) ;
break;
case V_123 :
V_13 -> V_100 = V_124 << 16 ;
F_13 ( & V_1 -> V_29 -> V_30 , L_24 , V_3 ) ;
break;
case V_125 :
V_13 -> V_100 = V_116 << 16 ;
F_13 ( & V_1 -> V_29 -> V_30 , L_25
L_26 , V_3 ) ;
break;
default:
V_13 -> V_100 = V_116 << 16 ;
F_13 ( & V_1 -> V_29 -> V_30 ,
L_27 , V_3 ,
V_90 -> V_109 ) ;
}
}
V_13 -> V_126 ( V_13 ) ;
F_2 ( V_1 , V_3 ) ;
}
static int
F_38 ( T_2 * V_1 )
{
struct V_77 * V_78 ;
int error ;
V_78 = F_39 ( & V_127 , sizeof( struct V_128 * ) ) ;
if ( V_78 == NULL )
goto V_129;
V_78 -> V_130 = 0 ;
V_78 -> V_131 = 0 ;
V_78 -> V_132 = V_48 ;
V_78 -> V_133 = V_33 ;
V_78 -> V_134 = V_1 -> V_135 ;
V_78 -> V_136 = V_137 ;
V_78 -> V_138 = V_1 -> V_139 ;
( (struct V_4 * )
V_1 -> V_9 ) -> V_80 = V_78 ;
V_78 -> V_140 [ 0 ] = ( unsigned long ) V_1 ;
V_78 -> V_141 = V_1 -> V_142 [ V_143 ] ;
V_78 -> V_144 = V_78 -> V_141 ;
error = F_40 ( V_78 , & V_1 -> V_29 -> V_30 ) ;
if ( error )
goto V_145;
F_41 ( V_78 ) ;
return 1 ;
V_145:
F_42 ( V_78 ) ;
V_129:
return 0 ;
}
static void
F_43 ( struct V_146 * V_29 ,
T_1 * V_3 ,
T_4 V_147 ,
int V_148 )
{
T_3 V_149 ;
V_149 . V_22 . V_21 = V_3 -> V_150 [ 0 ] . V_20 . V_21 ;
V_149 . V_22 . V_23 = V_3 -> V_150 [ 0 ] . V_20 . V_23 ;
F_44 ( V_29 , ( V_151 ) V_149 . V_17 , V_147 , V_148 ) ;
}
static void
F_45 ( struct V_146 * V_29 ,
T_1 * V_3 ,
unsigned char * V_152 ,
T_4 V_147 ,
int V_148 )
{
V_18 V_149 ;
V_149 = ( V_18 ) F_46 ( V_29 , V_152 , V_147 , V_148 ) ;
V_3 -> V_150 [ 0 ] . V_20 . V_21 =
( V_41 ) ( V_149 & ( V_18 ) 0x00000000FFFFFFFF ) ;
V_3 -> V_150 [ 0 ] . V_20 . V_23 =
( V_41 ) ( ( V_149 >> 32 ) & ( V_18 ) 0x00000000FFFFFFFF ) ;
V_3 -> V_150 [ 0 ] . V_24 = V_147 ;
V_3 -> V_97 . V_153 = ( V_154 ) 1 ;
V_3 -> V_97 . V_98 = ( V_155 ) 1 ;
}
static int
F_47 ( T_2 * V_1 ,
T_1 * V_3 ,
unsigned char * V_61 ,
unsigned char * V_156 ,
unsigned char V_157 ,
unsigned char * V_152 , int V_158 ,
int V_159 )
{
F_48 ( V_160 ) ;
V_3 -> V_93 = V_161 ;
V_3 -> V_95 = NULL ;
V_3 -> V_97 . V_162 = 0 ;
memcpy ( & V_3 -> V_97 . V_163 , V_61 , sizeof( V_3 -> V_97 . V_163 ) ) ;
V_3 -> V_97 . V_164 . V_21 = V_3 -> V_15 ;
memset ( V_3 -> V_91 . V_165 , 0 , sizeof( V_3 -> V_91 . V_165 ) ) ;
memcpy ( V_3 -> V_91 . V_165 , V_156 , V_157 ) ;
V_3 -> V_91 . V_166 = 0 ;
V_3 -> V_91 . V_167 = V_157 ;
V_3 -> V_91 . Type . Type = V_168 ;
V_3 -> V_91 . Type . V_169 = V_170 ;
V_3 -> V_91 . Type . V_171 = V_159 ;
F_45 ( V_1 -> V_29 , V_3 , ( unsigned char * ) V_152 ,
V_158 , V_172 ) ;
V_3 -> V_173 = & V_160 ;
F_49 ( V_1 , V_3 ) ;
F_50 ( & V_160 ) ;
F_43 ( V_1 -> V_29 , V_3 , V_158 , V_172 ) ;
return ( 0 ) ;
}
static void
F_51 ( T_2 * V_1 , T_1 * V_3 )
{
V_25 * V_90 ;
V_90 = V_3 -> V_27 ;
switch( V_90 -> V_109 )
{
case V_110 :
F_13 ( & V_1 -> V_29 -> V_30 ,
L_28 , V_3 ) ;
F_13 ( & V_1 -> V_29 -> V_30 ,
L_29 ,
V_3 , V_90 -> V_103 ) ;
if ( V_90 -> V_103 == 0 )
F_13 ( & V_1 -> V_29 -> V_30 ,
L_30
L_31
L_32
L_33 ) ;
break;
case V_112 :
F_17 ( & V_1 -> V_29 -> V_30 , L_34 ) ;
break;
case V_113 :
F_13 ( & V_1 -> V_29 -> V_30 , L_14
L_15
L_16 , V_3 ) ;
break;
case V_114 : {
F_13 ( & V_1 -> V_29 -> V_30 ,
L_35
L_36 , V_3 ) ;
}
break;
case V_115 :
F_13 ( & V_1 -> V_29 -> V_30 , L_17 , V_3 ) ;
break;
case V_117 :
F_13 ( & V_1 -> V_29 -> V_30 , L_18 , V_3 ) ;
break;
case V_118 :
F_13 ( & V_1 -> V_29 -> V_30 , L_19 , V_3 ) ;
break;
case V_119 :
F_13 ( & V_1 -> V_29 -> V_30 , L_20 , V_3 ) ;
break;
case V_121 :
F_13 ( & V_1 -> V_29 -> V_30 ,
L_21 , V_3 ) ;
break;
case V_122 :
F_13 ( & V_1 -> V_29 -> V_30 ,
L_37 , V_3 ) ;
break;
case V_123 :
F_13 ( & V_1 -> V_29 -> V_30 , L_24 , V_3 ) ;
break;
case V_125 :
F_13 ( & V_1 -> V_29 -> V_30 ,
L_38 , V_3 ) ;
break;
default:
F_13 ( & V_1 -> V_29 -> V_30 ,
L_27 ,
V_3 , V_90 -> V_109 ) ;
}
}
static int
F_52 ( T_2 * V_1 , unsigned char * V_61 ,
unsigned char V_174 , unsigned char * V_152 ,
unsigned char V_158 )
{
int V_83 ;
T_1 * V_3 ;
char V_156 [ 6 ] ;
V_25 * V_90 ;
unsigned long V_69 ;
F_53 ( & V_1 -> V_85 , V_69 ) ;
V_3 = F_1 ( V_1 ) ;
F_54 ( & V_1 -> V_85 , V_69 ) ;
if ( V_3 == NULL ) {
F_55 ( L_39 ) ;
return - 1 ;
}
V_90 = V_3 -> V_27 ;
V_156 [ 0 ] = V_175 ;
V_156 [ 1 ] = ( V_174 != 0 ) ;
V_156 [ 2 ] = V_174 ;
V_156 [ 3 ] = 0 ;
V_156 [ 4 ] = V_158 ;
V_156 [ 5 ] = 0 ;
V_83 = F_47 ( V_1 , V_3 , V_61 , V_156 ,
6 , V_152 , V_158 , V_176 ) ;
if ( V_83 != 0 ) return V_83 ;
if ( V_90 -> V_109 != 0 &&
V_90 -> V_109 != V_112 ) {
F_51 ( V_1 , V_3 ) ;
V_83 = - 1 ;
}
F_53 ( & V_1 -> V_85 , V_69 ) ;
F_2 ( V_1 , V_3 ) ;
F_54 ( & V_1 -> V_85 , V_69 ) ;
return V_83 ;
}
static int F_56 ( T_2 * V_1 , unsigned char * V_61 ,
unsigned char * V_64 , int V_147 )
{
int V_83 ;
unsigned char * V_152 ;
if ( V_147 > 16 )
V_147 = 16 ;
V_152 = F_25 ( 64 , V_40 ) ;
if ( ! V_152 )
return - 1 ;
V_83 = F_52 ( V_1 , V_61 , 0x83 , V_152 , 64 ) ;
if ( V_83 == 0 )
memcpy ( V_64 , & V_152 [ 8 ] , V_147 ) ;
F_14 ( V_152 ) ;
return V_83 != 0 ;
}
static int
F_57 ( T_2 * V_1 ,
T_5 * V_152 , int V_158 )
{
int V_83 ;
T_1 * V_3 ;
unsigned char V_156 [ 12 ] ;
unsigned char V_61 [ 8 ] ;
V_25 * V_90 ;
unsigned long V_69 ;
F_53 ( & V_1 -> V_85 , V_69 ) ;
V_3 = F_1 ( V_1 ) ;
F_54 ( & V_1 -> V_85 , V_69 ) ;
if ( V_3 == NULL ) {
F_55 ( L_39 ) ;
return - 1 ;
}
memset ( & V_61 [ 0 ] , 0 , 8 ) ;
V_156 [ 0 ] = V_177 ;
V_156 [ 1 ] = 0 ;
V_156 [ 2 ] = 0 ;
V_156 [ 3 ] = 0 ;
V_156 [ 4 ] = 0 ;
V_156 [ 5 ] = 0 ;
V_156 [ 6 ] = ( V_158 >> 24 ) & 0xFF ;
V_156 [ 7 ] = ( V_158 >> 16 ) & 0xFF ;
V_156 [ 8 ] = ( V_158 >> 8 ) & 0xFF ;
V_156 [ 9 ] = V_158 & 0xFF ;
V_156 [ 10 ] = 0 ;
V_156 [ 11 ] = 0 ;
V_83 = F_47 ( V_1 , V_3 , V_61 ,
V_156 , 12 ,
( unsigned char * ) V_152 ,
V_158 , V_176 ) ;
if ( V_83 != 0 ) return V_83 ;
V_90 = V_3 -> V_27 ;
if ( V_90 -> V_109 != 0 &&
V_90 -> V_109 != V_112 ) {
F_51 ( V_1 , V_3 ) ;
V_83 = - 1 ;
}
F_53 ( & V_1 -> V_85 , V_69 ) ;
F_2 ( V_1 , V_3 ) ;
F_54 ( & V_1 -> V_85 , V_69 ) ;
return V_83 ;
}
static void
F_58 ( T_2 * V_1 , int V_51 )
{
#define F_59 49
#define F_60 "$DR-10"
T_5 * V_178 ;
unsigned char * V_179 ;
unsigned char V_61 [ 8 ] ;
V_41 V_180 = 0 ;
unsigned char * V_181 ;
struct V_52 * V_182 , * V_183 ;
int V_184 = 0 ;
int V_185 = sizeof( * V_178 ) + V_186 * 8 ;
int V_31 ;
V_178 = F_25 ( V_185 , V_40 ) ;
V_179 = F_10 ( F_59 , V_40 ) ;
V_182 = F_25 ( sizeof( * V_182 ) *
( V_47 + 1 ) , V_40 ) ;
if ( V_178 == NULL || V_179 == NULL || V_182 == NULL ) {
F_55 ( V_187 L_40 ) ;
goto V_188;
}
V_183 = & V_182 [ V_47 ] ;
if ( F_57 ( V_1 , V_178 , V_185 ) == 0 ) {
V_181 = & V_178 -> V_189 [ 0 ] ;
V_180 = ( ( V_181 [ 0 ] << 24 ) | ( V_181 [ 1 ] << 16 ) | ( V_181 [ 2 ] << 8 ) | V_181 [ 3 ] ) / 8 ;
if ( V_180 > V_186 ) {
F_55 ( V_190
L_41
L_42 , V_186 ,
V_180 - V_186 ) ;
V_180 = V_186 ;
}
}
else {
F_55 ( V_187 L_43 ) ;
goto V_188;
}
for ( V_31 = 0 ; V_31 < V_180 ; V_31 ++ ) {
if ( V_178 -> V_163 [ V_31 ] [ 3 ] & 0xC0 ) continue;
memset ( V_179 , 0 , F_59 ) ;
memcpy ( & V_61 [ 0 ] , & V_178 -> V_163 [ V_31 ] [ 0 ] , 8 ) ;
if ( F_52 ( V_1 , V_61 , 0 , V_179 ,
( unsigned char ) F_59 ) != 0 )
continue;
V_183 -> V_65 = ( V_179 [ 0 ] & 0x1f ) ;
V_183 -> V_42 = - 1 ;
V_183 -> V_43 = - 1 ;
V_183 -> V_44 = - 1 ;
memcpy ( V_183 -> V_61 , V_61 , 8 ) ;
memcpy ( V_183 -> V_62 , & V_179 [ 8 ] ,
sizeof( V_183 -> V_62 ) ) ;
memcpy ( V_183 -> V_73 , & V_179 [ 16 ] ,
sizeof( V_183 -> V_73 ) ) ;
memcpy ( V_183 -> V_63 , & V_179 [ 32 ] ,
sizeof( V_183 -> V_63 ) ) ;
memset ( V_183 -> V_64 , 0 ,
sizeof( V_183 -> V_64 ) ) ;
F_56 ( V_1 , V_61 ,
V_183 -> V_64 , sizeof( V_183 -> V_64 ) ) ;
switch ( V_183 -> V_65 )
{
case 0x05 : {
char V_191 [ 7 ] ;
strncpy ( V_191 , & V_179 [ 43 ] , 6 ) ;
V_191 [ 6 ] = '\0' ;
if ( strncmp ( V_191 , F_60 , 6 ) != 0 )
break;
}
case 0x01 :
case 0x08 :
if ( V_184 >= V_47 ) {
F_55 ( V_192 L_44
L_45 , V_1 -> V_26 ,
F_18 ( V_183 -> V_65 ) ) ;
break;
}
V_182 [ V_184 ] = * V_183 ;
V_184 ++ ;
break;
default:
break;
}
}
F_24 ( V_1 , V_51 , V_182 , V_184 ) ;
V_188:
F_14 ( V_179 ) ;
F_14 ( V_178 ) ;
F_14 ( V_182 ) ;
return;
}
static int
F_61 ( char * V_193 , int V_194 , char * V_195 )
{
int V_196 = strlen ( V_195 ) ;
if ( V_194 >= V_196 && ! memcmp ( V_195 , V_193 , V_196 ) )
return V_196 ;
else
return 0 ;
}
static int
F_62 ( T_2 * V_1 , int V_51 , char * V_197 , int V_198 )
{
int V_199 ;
if ( ( V_199 = F_61 ( V_197 , V_198 , L_46 ) ) != 0 )
F_58 ( V_1 , V_51 ) ;
else
return - V_200 ;
return V_198 ;
}
static int
F_63 ( struct V_77 * V_78 ,
char * V_197 ,
int V_198 )
{
T_2 * V_1 = ( T_2 * ) V_78 -> V_140 [ 0 ] ;
if ( V_1 == NULL )
return - V_200 ;
return F_62 ( V_1 , V_78 -> V_201 ,
V_197 , V_198 ) ;
}
static int
F_64 ( struct V_202 * V_203 , struct V_77 * V_78 )
{
T_2 * V_1 = ( T_2 * ) V_78 -> V_140 [ 0 ] ;
int V_31 ;
if ( V_1 == NULL )
return - V_200 ;
F_65 ( V_203 , L_47 ,
V_1 -> V_26 , V_78 -> V_201 ) ;
for ( V_31 = 0 ; V_31 < V_49 [ V_1 -> V_26 ] . V_50 ; V_31 ++ ) {
struct V_52 * V_58 =
& V_49 [ V_1 -> V_26 ] . V_30 [ V_31 ] ;
F_65 ( V_203 , L_48
L_49 ,
V_78 -> V_201 , V_58 -> V_42 , V_58 -> V_43 , V_58 -> V_44 ,
V_58 -> V_65 ,
V_58 -> V_61 [ 0 ] , V_58 -> V_61 [ 1 ] ,
V_58 -> V_61 [ 2 ] , V_58 -> V_61 [ 3 ] ,
V_58 -> V_61 [ 4 ] , V_58 -> V_61 [ 5 ] ,
V_58 -> V_61 [ 6 ] , V_58 -> V_61 [ 7 ] ) ;
}
return 0 ;
}
static void F_66 ( T_2 * V_1 , T_1 * V_3 ,
struct V_89 * V_13 )
{
unsigned int V_194 ;
struct V_204 * V_205 ;
V_18 V_149 ;
int V_206 , V_31 , V_207 , V_208 ;
struct V_4 * V_5 = V_1 -> V_9 ;
T_6 * V_209 ;
F_67 ( F_68 ( V_13 ) > V_1 -> V_135 ) ;
V_207 = 0 ;
V_208 = 0 ;
V_209 = V_3 -> V_150 ;
V_206 = F_69 ( V_13 ) ;
if ( V_206 ) {
F_70 (cmd, sg, request_nsgs, i) {
if ( V_208 + 1 == V_1 -> V_99 &&
! V_207 && V_206 - V_31 > 1 ) {
V_207 = 1 ;
V_208 = 0 ;
V_209 = V_5 -> V_34 [ V_3 -> V_16 ] ;
}
V_149 = ( V_18 ) F_71 ( V_205 ) ;
V_194 = F_72 ( V_205 ) ;
V_209 [ V_208 ] . V_20 . V_21 =
( V_41 ) ( V_149 & 0x0FFFFFFFFULL ) ;
V_209 [ V_208 ] . V_20 . V_23 =
( V_41 ) ( ( V_149 >> 32 ) & 0x0FFFFFFFFULL ) ;
V_209 [ V_208 ] . V_24 = V_194 ;
V_209 [ V_208 ] . V_210 = 0 ;
++ V_208 ;
}
if ( V_207 )
F_73 ( V_1 , V_3 ,
V_5 -> V_34 [ V_3 -> V_16 ] ,
( V_206 - ( V_1 -> V_99 - 1 ) ) *
sizeof( T_6 ) ) ;
}
if ( V_206 > V_1 -> V_211 )
V_1 -> V_211 = V_206 ;
V_3 -> V_97 . V_98 = ( V_212 ) V_206 + V_207 ;
if ( V_206 > V_1 -> V_99 )
V_3 -> V_97 . V_153 = V_1 -> V_99 ;
else
V_3 -> V_97 . V_153 = V_3 -> V_97 . V_98 ;
return;
}
static int
F_74 ( struct V_89 * V_13 , void (* F_75)( struct V_89 * ) )
{
T_2 * V_1 ;
int V_83 ;
unsigned char V_61 [ 8 ] ;
T_1 * V_3 ;
unsigned long V_69 ;
V_1 = ( T_2 * ) V_13 -> V_53 -> V_213 -> V_140 [ 0 ] ;
V_83 = F_31 ( V_1 , V_13 -> V_53 -> V_214 , V_13 -> V_53 -> V_215 ,
V_13 -> V_53 -> V_44 , V_61 ) ;
if ( V_83 != 0 ) {
V_13 -> V_100 = V_111 << 16 ;
F_75 ( V_13 ) ;
return 0 ;
}
F_53 ( & V_1 -> V_85 , V_69 ) ;
V_3 = F_1 ( V_1 ) ;
F_54 ( & V_1 -> V_85 , V_69 ) ;
if ( V_3 == NULL ) {
F_13 ( & V_1 -> V_29 -> V_30 , L_50 ) ;
V_13 -> V_100 = V_111 << 16 ;
F_75 ( V_13 ) ;
return 0 ;
}
V_13 -> V_126 = F_75 ;
V_13 -> V_216 = ( unsigned char * ) V_3 ;
V_3 -> V_93 = V_217 ;
V_3 -> V_95 = V_13 ;
V_3 -> V_97 . V_162 = 0 ;
memcpy ( & V_3 -> V_97 . V_163 . V_218 [ 0 ] , & V_61 [ 0 ] , 8 ) ;
V_3 -> V_97 . V_164 . V_21 = V_3 -> V_15 ;
V_3 -> V_91 . V_166 = 0 ;
memset ( V_3 -> V_91 . V_165 , 0 , sizeof( V_3 -> V_91 . V_165 ) ) ;
F_67 ( V_13 -> V_219 > sizeof( V_3 -> V_91 . V_165 ) ) ;
V_3 -> V_91 . V_167 = V_13 -> V_219 ;
memcpy ( V_3 -> V_91 . V_165 , V_13 -> V_220 , V_13 -> V_219 ) ;
V_3 -> V_91 . Type . Type = V_168 ;
V_3 -> V_91 . Type . V_169 = V_170 ;
switch( V_13 -> V_221 )
{
case V_222 :
V_3 -> V_91 . Type . V_171 = V_223 ;
break;
case V_172 :
V_3 -> V_91 . Type . V_171 = V_176 ;
break;
case V_224 :
V_3 -> V_91 . Type . V_171 = V_225 ;
break;
case V_226 :
V_3 -> V_91 . Type . V_171 = V_227 ;
break;
default:
F_13 ( & V_1 -> V_29 -> V_30 , L_51 ,
V_13 -> V_221 ) ;
F_4 () ;
break;
}
F_66 ( V_1 , V_3 , V_13 ) ;
F_49 ( V_1 , V_3 ) ;
return 0 ;
}
int F_76 ( T_2 * V_1 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned long V_69 ;
F_53 ( & V_1 -> V_85 , V_69 ) ;
V_5 = V_1 -> V_9 ;
V_7 = & V_5 -> V_10 ;
if ( V_5 -> V_86 ) {
F_17 ( & V_1 -> V_29 -> V_30 , L_52 ) ;
F_54 ( & V_1 -> V_85 , V_69 ) ;
return - V_228 ;
}
V_5 -> V_86 = 1 ;
F_54 ( & V_1 -> V_85 , V_69 ) ;
F_58 ( V_1 , - 1 ) ;
F_38 ( V_1 ) ;
return 0 ;
}
static void
F_77 ( struct V_202 * V_229 , T_2 * V_1 )
{
unsigned long V_69 ;
F_21 ( V_1 , V_69 ) ;
F_65 ( V_229 ,
L_53 ,
V_49 [ V_1 -> V_26 ] . V_50 ) ;
F_22 ( V_1 , V_69 ) ;
}
static int F_78 ( T_2 * V_1 ,
unsigned char V_230 [] )
{
int V_83 ;
int V_231 = 0 ;
int V_232 = V_233 ;
T_1 * V_3 ;
V_3 = F_79 ( V_1 ) ;
if ( ! V_3 ) {
F_13 ( & V_1 -> V_29 -> V_30 , L_54
L_55 ) ;
return V_234 ;
}
while ( V_231 < 20 ) {
F_80 ( V_232 ) ;
V_231 ++ ;
if ( V_232 < ( V_233 * 30 ) )
V_232 = V_232 * 2 ;
V_83 = F_81 ( V_1 , V_3 , V_235 , NULL , 0 , 0 ,
V_230 , V_168 ) ;
if ( V_83 == 0 )
V_83 = F_82 ( V_1 , V_3 , 0 ) ;
( void ) F_83 ( V_1 , V_3 ) ;
if ( V_83 != 0 )
goto V_236;
if ( V_3 -> V_27 -> V_109 == V_237 )
break;
if ( V_3 -> V_27 -> V_109 == V_110 &&
V_3 -> V_27 -> V_103 == V_238 ) {
if ( V_3 -> V_27 -> V_105 [ 2 ] == V_239 )
break;
if ( V_3 -> V_27 -> V_105 [ 2 ] == V_240 ) {
unsigned char V_241 ;
V_241 = V_3 -> V_27 -> V_105 [ 12 ] ;
F_84 ( V_1 , V_3 ) ;
if ( V_241 == V_242 )
break;
}
}
V_236:
F_13 ( & V_1 -> V_29 -> V_30 , L_56
L_57 ,
V_232 / V_233 ) ;
V_83 = 1 ;
}
if ( V_83 )
F_13 ( & V_1 -> V_29 -> V_30 , L_58 ) ;
else
F_13 ( & V_1 -> V_29 -> V_30 , L_59 ) ;
F_85 ( V_1 , V_3 ) ;
return V_83 ;
}
static int F_86 ( struct V_89 * V_243 )
{
int V_83 ;
T_1 * V_244 ;
unsigned char V_230 [ 8 ] ;
T_2 * V_1 ;
V_1 = ( T_2 * ) V_243 -> V_53 -> V_213 -> V_140 [ 0 ] ;
if ( V_1 == NULL )
return V_245 ;
F_13 ( & V_1 -> V_29 -> V_30 , L_60 ) ;
V_244 = ( T_1 * ) V_243 -> V_216 ;
if ( V_244 == NULL )
return V_245 ;
memcpy ( V_230 , & V_244 -> V_97 . V_163 . V_218 [ 0 ] , 8 ) ;
V_83 = F_87 ( V_1 , V_246 , NULL , 0 , 0 , V_230 ,
V_92 ) ;
if ( V_83 == 0 && F_78 ( V_1 , V_230 ) == 0 )
return V_247 ;
F_13 ( & V_1 -> V_29 -> V_30 , L_61 ) ;
return V_245 ;
}
static int F_88 ( struct V_89 * V_243 )
{
int V_83 ;
T_1 * V_248 ;
unsigned char V_230 [ 8 ] ;
T_2 * V_1 ;
V_1 = ( T_2 * ) V_243 -> V_53 -> V_213 -> V_140 [ 0 ] ;
if ( V_1 == NULL )
return V_245 ;
F_13 ( & V_1 -> V_29 -> V_30 , L_62 ) ;
V_248 = ( T_1 * ) V_243 -> V_216 ;
if ( V_248 == NULL )
return V_245 ;
memcpy ( V_230 , & V_248 -> V_97 . V_163 . V_218 [ 0 ] , 8 ) ;
V_83 = F_87 ( V_1 , V_249 , & V_248 -> V_97 . V_164 ,
0 , 0 , V_230 , V_92 ) ;
if ( V_83 == 0 )
return V_247 ;
return V_245 ;
}
