static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . type == V_4 ) {
V_2 -> V_5 . V_6 . V_7 = V_8 ;
V_2 -> V_5 . V_6 . V_9 = V_10 ;
V_2 -> V_5 . V_6 . V_11 = V_12 ;
V_2 -> V_5 . V_13 . V_7 = V_14 ;
V_2 -> V_5 . V_13 . V_9 = V_15 ;
V_2 -> V_5 . V_13 . V_11 = V_16 ;
} else {
V_2 -> V_5 . V_6 . V_7 = V_17 ;
V_2 -> V_5 . V_6 . V_9 = V_18 ;
V_2 -> V_5 . V_6 . V_11 = V_19 ;
V_2 -> V_5 . V_13 . V_7 = V_20 ;
V_2 -> V_5 . V_13 . V_9 = V_21 ;
V_2 -> V_5 . V_13 . V_11 = V_22 ;
}
}
static T_1 F_2 ( struct V_1 * V_2 )
{
T_1 V_23 ;
V_23 = F_3 ( V_2 , & V_2 -> V_5 . V_6 . V_24 ,
V_25 ,
( V_2 -> V_5 . V_26 *
sizeof( struct V_27 ) ) ,
V_28 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_4 ( V_2 , & V_2 -> V_5 . V_6 . V_29 ,
( V_2 -> V_5 . V_26 *
sizeof( struct V_30 ) ) ) ;
if ( V_23 ) {
F_5 ( V_2 , & V_2 -> V_5 . V_6 . V_24 ) ;
return V_23 ;
}
return V_23 ;
}
static T_1 F_6 ( struct V_1 * V_2 )
{
T_1 V_23 ;
V_23 = F_3 ( V_2 , & V_2 -> V_5 . V_13 . V_24 ,
V_31 ,
( V_2 -> V_5 . V_32 *
sizeof( struct V_27 ) ) ,
V_28 ) ;
return V_23 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_5 ( V_2 , & V_2 -> V_5 . V_6 . V_24 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_5 ( V_2 , & V_2 -> V_5 . V_13 . V_24 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
T_1 V_23 ;
struct V_27 * V_33 ;
struct V_34 * V_35 ;
int V_36 ;
V_23 = F_4 ( V_2 , & V_2 -> V_5 . V_13 . V_37 ,
( V_2 -> V_5 . V_32 * sizeof( struct V_34 ) ) ) ;
if ( V_23 )
goto V_38;
V_2 -> V_5 . V_13 . V_39 . V_40 = (struct V_34 * ) V_2 -> V_5 . V_13 . V_37 . V_41 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_5 . V_32 ; V_36 ++ ) {
V_35 = & V_2 -> V_5 . V_13 . V_39 . V_40 [ V_36 ] ;
V_23 = F_3 ( V_2 , V_35 ,
V_42 ,
V_2 -> V_5 . V_43 ,
V_28 ) ;
if ( V_23 )
goto V_44;
V_33 = F_10 ( V_2 -> V_5 . V_13 , V_36 ) ;
V_33 -> V_45 = F_11 ( V_46 ) ;
if ( V_2 -> V_5 . V_43 > V_47 )
V_33 -> V_45 |= F_11 ( V_48 ) ;
V_33 -> V_49 = 0 ;
V_33 -> V_50 = F_11 ( ( V_51 ) V_35 -> V_52 ) ;
V_33 -> V_53 = 0 ;
V_33 -> V_54 = 0 ;
V_33 -> V_55 = 0 ;
V_33 -> V_56 . V_57 . V_58 =
F_12 ( F_13 ( V_35 -> V_59 ) ) ;
V_33 -> V_56 . V_57 . V_60 =
F_12 ( F_14 ( V_35 -> V_59 ) ) ;
V_33 -> V_56 . V_57 . V_61 = 0 ;
V_33 -> V_56 . V_57 . V_62 = 0 ;
}
V_38:
return V_23 ;
V_44:
V_36 -- ;
for (; V_36 >= 0 ; V_36 -- )
F_5 ( V_2 , & V_2 -> V_5 . V_13 . V_39 . V_40 [ V_36 ] ) ;
F_15 ( V_2 , & V_2 -> V_5 . V_13 . V_37 ) ;
return V_23 ;
}
static T_1 F_16 ( struct V_1 * V_2 )
{
T_1 V_23 ;
struct V_34 * V_35 ;
int V_36 ;
V_23 = F_4 ( V_2 , & V_2 -> V_5 . V_6 . V_37 ,
( V_2 -> V_5 . V_26 * sizeof( struct V_34 ) ) ) ;
if ( V_23 )
goto V_63;
V_2 -> V_5 . V_6 . V_39 . V_64 = (struct V_34 * ) V_2 -> V_5 . V_6 . V_37 . V_41 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_5 . V_26 ; V_36 ++ ) {
V_35 = & V_2 -> V_5 . V_6 . V_39 . V_64 [ V_36 ] ;
V_23 = F_3 ( V_2 , V_35 ,
V_65 ,
V_2 -> V_5 . V_66 ,
V_28 ) ;
if ( V_23 )
goto V_67;
}
V_63:
return V_23 ;
V_67:
V_36 -- ;
for (; V_36 >= 0 ; V_36 -- )
F_5 ( V_2 , & V_2 -> V_5 . V_6 . V_39 . V_64 [ V_36 ] ) ;
F_15 ( V_2 , & V_2 -> V_5 . V_6 . V_37 ) ;
return V_23 ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_5 . V_32 ; V_36 ++ )
F_5 ( V_2 , & V_2 -> V_5 . V_13 . V_39 . V_40 [ V_36 ] ) ;
F_5 ( V_2 , & V_2 -> V_5 . V_13 . V_24 ) ;
F_15 ( V_2 , & V_2 -> V_5 . V_13 . V_37 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_5 . V_26 ; V_36 ++ )
if ( V_2 -> V_5 . V_6 . V_39 . V_64 [ V_36 ] . V_59 )
F_5 ( V_2 , & V_2 -> V_5 . V_6 . V_39 . V_64 [ V_36 ] ) ;
F_15 ( V_2 , & V_2 -> V_5 . V_6 . V_29 ) ;
F_5 ( V_2 , & V_2 -> V_5 . V_6 . V_24 ) ;
F_15 ( V_2 , & V_2 -> V_5 . V_6 . V_37 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . type == V_4 ) {
F_20 ( V_2 , V_68 ,
F_13 ( V_2 -> V_5 . V_6 . V_24 . V_59 ) ) ;
F_20 ( V_2 , V_69 ,
F_14 ( V_2 -> V_5 . V_6 . V_24 . V_59 ) ) ;
F_20 ( V_2 , V_12 , ( V_2 -> V_5 . V_26 |
V_70 ) ) ;
} else {
F_20 ( V_2 , V_71 ,
F_13 ( V_2 -> V_5 . V_6 . V_24 . V_59 ) ) ;
F_20 ( V_2 , V_72 ,
F_14 ( V_2 -> V_5 . V_6 . V_24 . V_59 ) ) ;
F_20 ( V_2 , V_19 , ( V_2 -> V_5 . V_26 |
V_73 ) ) ;
}
}
static void F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . type == V_4 ) {
F_20 ( V_2 , V_74 ,
F_13 ( V_2 -> V_5 . V_13 . V_24 . V_59 ) ) ;
F_20 ( V_2 , V_75 ,
F_14 ( V_2 -> V_5 . V_13 . V_24 . V_59 ) ) ;
F_20 ( V_2 , V_16 , ( V_2 -> V_5 . V_32 |
V_76 ) ) ;
} else {
F_20 ( V_2 , V_77 ,
F_13 ( V_2 -> V_5 . V_13 . V_24 . V_59 ) ) ;
F_20 ( V_2 , V_78 ,
F_14 ( V_2 -> V_5 . V_13 . V_24 . V_59 ) ) ;
F_20 ( V_2 , V_22 , ( V_2 -> V_5 . V_32 |
V_79 ) ) ;
}
F_20 ( V_2 , V_2 -> V_5 . V_13 . V_7 , V_2 -> V_5 . V_32 - 1 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
T_1 V_23 = 0 ;
if ( V_2 -> V_5 . V_6 . V_80 > 0 ) {
V_23 = V_81 ;
goto V_82;
}
if ( ( V_2 -> V_5 . V_26 == 0 ) ||
( V_2 -> V_5 . V_66 == 0 ) ) {
V_23 = V_83 ;
goto V_82;
}
V_2 -> V_5 . V_6 . V_84 = 0 ;
V_2 -> V_5 . V_6 . V_85 = 0 ;
V_2 -> V_5 . V_6 . V_80 = V_2 -> V_5 . V_26 ;
V_23 = F_2 ( V_2 ) ;
if ( V_23 )
goto V_82;
V_23 = F_16 ( V_2 ) ;
if ( V_23 )
goto V_86;
F_19 ( V_2 ) ;
goto V_82;
V_86:
F_7 ( V_2 ) ;
V_82:
return V_23 ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
T_1 V_23 = 0 ;
if ( V_2 -> V_5 . V_13 . V_80 > 0 ) {
V_23 = V_81 ;
goto V_82;
}
if ( ( V_2 -> V_5 . V_32 == 0 ) ||
( V_2 -> V_5 . V_43 == 0 ) ) {
V_23 = V_83 ;
goto V_82;
}
V_2 -> V_5 . V_13 . V_84 = 0 ;
V_2 -> V_5 . V_13 . V_85 = 0 ;
V_2 -> V_5 . V_13 . V_80 = V_2 -> V_5 . V_32 ;
V_23 = F_6 ( V_2 ) ;
if ( V_23 )
goto V_82;
V_23 = F_9 ( V_2 ) ;
if ( V_23 )
goto V_86;
F_21 ( V_2 ) ;
goto V_82;
V_86:
F_8 ( V_2 ) ;
V_82:
return V_23 ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
T_1 V_23 = 0 ;
if ( V_2 -> V_5 . V_6 . V_80 == 0 )
return V_81 ;
F_20 ( V_2 , V_2 -> V_5 . V_6 . V_9 , 0 ) ;
F_20 ( V_2 , V_2 -> V_5 . V_6 . V_7 , 0 ) ;
F_20 ( V_2 , V_2 -> V_5 . V_6 . V_11 , 0 ) ;
F_25 ( & V_2 -> V_5 . V_87 ) ;
V_2 -> V_5 . V_6 . V_80 = 0 ;
F_18 ( V_2 ) ;
F_26 ( & V_2 -> V_5 . V_87 ) ;
return V_23 ;
}
static T_1 F_27 ( struct V_1 * V_2 )
{
T_1 V_23 = 0 ;
if ( V_2 -> V_5 . V_13 . V_80 == 0 )
return V_81 ;
F_20 ( V_2 , V_2 -> V_5 . V_13 . V_9 , 0 ) ;
F_20 ( V_2 , V_2 -> V_5 . V_13 . V_7 , 0 ) ;
F_20 ( V_2 , V_2 -> V_5 . V_13 . V_11 , 0 ) ;
F_25 ( & V_2 -> V_5 . V_88 ) ;
V_2 -> V_5 . V_13 . V_80 = 0 ;
F_17 ( V_2 ) ;
F_26 ( & V_2 -> V_5 . V_88 ) ;
return V_23 ;
}
T_1 F_28 ( struct V_1 * V_2 )
{
T_1 V_23 ;
V_51 V_89 , V_90 ;
int V_91 = 0 ;
if ( ( V_2 -> V_5 . V_32 == 0 ) ||
( V_2 -> V_5 . V_26 == 0 ) ||
( V_2 -> V_5 . V_43 == 0 ) ||
( V_2 -> V_5 . V_66 == 0 ) ) {
V_23 = V_83 ;
goto V_82;
}
F_29 ( & V_2 -> V_5 . V_87 ) ;
F_29 ( & V_2 -> V_5 . V_88 ) ;
F_1 ( V_2 ) ;
V_23 = F_22 ( V_2 ) ;
if ( V_23 )
goto V_92;
V_23 = F_23 ( V_2 ) ;
if ( V_23 )
goto V_93;
do {
V_23 = F_30 ( V_2 ,
& V_2 -> V_5 . V_94 ,
& V_2 -> V_5 . V_95 ,
& V_2 -> V_5 . V_96 ,
& V_2 -> V_5 . V_97 ,
NULL ) ;
if ( V_23 != V_98 )
break;
V_91 ++ ;
F_31 ( 100 ) ;
F_32 ( V_2 ) ;
} while ( V_91 < 10 );
if ( V_23 != V_99 )
goto V_100;
F_33 ( V_2 , V_101 , & V_2 -> V_102 . V_103 ) ;
F_33 ( V_2 , V_104 , & V_89 ) ;
F_33 ( V_2 , V_105 , & V_90 ) ;
V_2 -> V_102 . V_106 = ( V_90 << 16 ) | V_89 ;
if ( V_2 -> V_5 . V_96 != V_107 ||
V_2 -> V_5 . V_97 > V_108 ) {
V_23 = V_109 ;
goto V_100;
}
F_34 ( V_2 , V_110 , 0 , NULL ) ;
V_23 = F_35 ( V_2 ,
V_111 ,
0 ,
NULL ) ;
V_23 = 0 ;
goto V_82;
V_100:
F_27 ( V_2 ) ;
V_93:
F_24 ( V_2 ) ;
V_92:
V_82:
return V_23 ;
}
T_1 F_36 ( struct V_1 * V_2 )
{
T_1 V_23 = 0 ;
if ( F_37 ( V_2 ) )
F_38 ( V_2 , true ) ;
F_24 ( V_2 ) ;
F_27 ( V_2 ) ;
return V_23 ;
}
static V_51 F_39 ( struct V_1 * V_2 )
{
struct V_112 * V_6 = & ( V_2 -> V_5 . V_6 ) ;
struct V_30 * V_113 ;
V_51 V_114 = V_6 -> V_85 ;
struct V_27 V_115 ;
struct V_27 * V_33 ;
V_33 = F_10 ( * V_6 , V_114 ) ;
V_113 = F_40 ( * V_6 , V_114 ) ;
while ( F_41 ( V_2 , V_2 -> V_5 . V_6 . V_9 ) != V_114 ) {
if ( V_113 -> V_116 ) {
T_2 V_117 =
( T_2 ) V_113 -> V_116 ;
V_115 = * V_33 ;
V_117 ( V_2 , & V_115 ) ;
}
memset ( ( void * ) V_33 , 0 , sizeof( struct V_27 ) ) ;
memset ( ( void * ) V_113 , 0 ,
sizeof( struct V_30 ) ) ;
V_114 ++ ;
if ( V_114 == V_6 -> V_80 )
V_114 = 0 ;
V_33 = F_10 ( * V_6 , V_114 ) ;
V_113 = F_40 ( * V_6 , V_114 ) ;
}
V_6 -> V_85 = V_114 ;
return F_42 ( V_6 ) ;
}
static bool F_43 ( struct V_1 * V_2 )
{
return F_41 ( V_2 , V_2 -> V_5 . V_6 . V_9 ) == V_2 -> V_5 . V_6 . V_84 ;
}
T_1 F_44 ( struct V_1 * V_2 ,
struct V_27 * V_33 ,
void * V_118 ,
V_51 V_119 ,
struct V_30 * V_120 )
{
T_1 V_121 = 0 ;
struct V_34 * V_122 = NULL ;
struct V_30 * V_113 ;
struct V_27 * V_123 ;
bool V_124 = false ;
V_51 V_53 = 0 ;
if ( V_2 -> V_5 . V_6 . V_80 == 0 ) {
F_45 ( V_2 , V_125 ,
L_1 ) ;
V_121 = V_126 ;
goto V_127;
}
V_113 = F_40 ( V_2 -> V_5 . V_6 , V_2 -> V_5 . V_6 . V_84 ) ;
if ( V_120 ) {
* V_113 = * V_120 ;
if ( V_113 -> V_128 ) {
V_33 -> V_54 =
F_12 ( F_13 ( V_113 -> V_128 ) ) ;
V_33 -> V_55 =
F_12 ( F_14 ( V_113 -> V_128 ) ) ;
}
} else {
memset ( V_113 , 0 , sizeof( struct V_30 ) ) ;
}
V_33 -> V_45 &= ~ F_11 ( V_113 -> V_129 ) ;
V_33 -> V_45 |= F_11 ( V_113 -> V_130 ) ;
F_25 ( & V_2 -> V_5 . V_87 ) ;
if ( V_119 > V_2 -> V_5 . V_66 ) {
F_45 ( V_2 ,
V_125 ,
L_2 ,
V_119 ) ;
V_121 = V_131 ;
goto V_132;
}
if ( V_113 -> V_133 && ! V_113 -> V_134 ) {
F_45 ( V_2 ,
V_125 ,
L_3 ) ;
V_121 = V_135 ;
goto V_132;
}
if ( F_39 ( V_2 ) == 0 ) {
F_45 ( V_2 ,
V_125 ,
L_4 ) ;
V_121 = V_136 ;
goto V_132;
}
V_123 = F_10 ( V_2 -> V_5 . V_6 , V_2 -> V_5 . V_6 . V_84 ) ;
* V_123 = * V_33 ;
if ( V_118 != NULL ) {
V_122 = & ( V_2 -> V_5 . V_6 . V_39 . V_64 [ V_2 -> V_5 . V_6 . V_84 ] ) ;
memcpy ( V_122 -> V_41 , V_118 , V_119 ) ;
V_123 -> V_50 = F_11 ( V_119 ) ;
V_123 -> V_56 . V_57 . V_58 =
F_12 ( F_13 ( V_122 -> V_59 ) ) ;
V_123 -> V_56 . V_57 . V_60 =
F_12 ( F_14 ( V_122 -> V_59 ) ) ;
}
F_46 ( V_2 , V_137 , ( void * ) V_123 , V_118 ) ;
( V_2 -> V_5 . V_6 . V_84 ) ++ ;
if ( V_2 -> V_5 . V_6 . V_84 == V_2 -> V_5 . V_6 . V_80 )
V_2 -> V_5 . V_6 . V_84 = 0 ;
if ( ! V_113 -> V_133 )
F_20 ( V_2 , V_2 -> V_5 . V_6 . V_7 , V_2 -> V_5 . V_6 . V_84 ) ;
if ( ! V_113 -> V_134 && ! V_113 -> V_133 ) {
T_3 V_138 = 0 ;
T_3 V_139 = 10 ;
do {
if ( F_43 ( V_2 ) )
break;
F_47 ( V_139 ) ;
V_138 += V_139 ;
} while ( V_138 < V_140 );
}
if ( F_43 ( V_2 ) ) {
* V_33 = * V_123 ;
if ( V_118 != NULL )
memcpy ( V_118 , V_122 -> V_41 , V_119 ) ;
V_53 = F_48 ( V_33 -> V_53 ) ;
if ( V_53 != 0 ) {
F_45 ( V_2 ,
V_125 ,
L_5 ,
V_53 ) ;
V_53 &= 0xff ;
}
V_124 = true ;
if ( (enum V_141 ) V_53 == V_142 )
V_121 = 0 ;
else
V_121 = V_143 ;
V_2 -> V_5 . V_144 = (enum V_141 ) V_53 ;
}
if ( ( ! V_124 ) &&
( ! V_113 -> V_134 && ! V_113 -> V_133 ) ) {
F_45 ( V_2 ,
V_125 ,
L_6 ) ;
V_121 = V_98 ;
}
V_132:
F_26 ( & V_2 -> V_5 . V_87 ) ;
V_127:
return V_121 ;
}
void F_49 ( struct V_27 * V_33 ,
V_51 V_49 )
{
memset ( ( void * ) V_33 , 0 , sizeof( struct V_27 ) ) ;
V_33 -> V_49 = F_11 ( V_49 ) ;
V_33 -> V_45 = F_11 ( V_145 ) ;
}
T_1 F_50 ( struct V_1 * V_2 ,
struct V_146 * V_147 ,
V_51 * V_148 )
{
T_1 V_23 = 0 ;
V_51 V_114 = V_2 -> V_5 . V_13 . V_85 ;
struct V_27 * V_33 ;
struct V_34 * V_35 ;
V_51 V_149 ;
V_51 V_50 ;
V_51 V_45 ;
V_51 V_150 ;
F_25 ( & V_2 -> V_5 . V_88 ) ;
V_150 = ( F_41 ( V_2 , V_2 -> V_5 . V_13 . V_9 ) & V_151 ) ;
if ( V_150 == V_114 ) {
F_45 ( V_2 ,
V_125 ,
L_7 ) ;
V_23 = V_152 ;
goto V_153;
}
V_33 = F_10 ( V_2 -> V_5 . V_13 , V_114 ) ;
V_149 = V_114 ;
F_46 ( V_2 ,
V_137 ,
( void * ) V_33 ,
V_2 -> V_5 . V_13 . V_39 . V_40 [ V_149 ] . V_41 ) ;
V_45 = F_48 ( V_33 -> V_45 ) ;
if ( V_45 & V_154 ) {
V_23 = V_143 ;
V_2 -> V_5 . V_155 =
(enum V_141 ) F_48 ( V_33 -> V_53 ) ;
F_45 ( V_2 ,
V_125 ,
L_8 ,
V_2 -> V_5 . V_155 ) ;
} else {
V_147 -> V_33 = * V_33 ;
V_50 = F_48 ( V_33 -> V_50 ) ;
V_147 -> V_156 = F_51 ( V_50 , V_147 -> V_156 ) ;
if ( V_147 -> V_157 != NULL && ( V_147 -> V_156 != 0 ) )
memcpy ( V_147 -> V_157 , V_2 -> V_5 . V_13 . V_39 . V_40 [ V_149 ] . V_41 ,
V_147 -> V_156 ) ;
}
V_35 = & V_2 -> V_5 . V_13 . V_39 . V_40 [ V_114 ] ;
memset ( ( void * ) V_33 , 0 , sizeof( struct V_27 ) ) ;
V_33 -> V_45 = F_11 ( V_46 ) ;
if ( V_2 -> V_5 . V_43 > V_47 )
V_33 -> V_45 |= F_11 ( V_48 ) ;
V_33 -> V_50 = F_11 ( ( V_51 ) V_35 -> V_52 ) ;
V_33 -> V_56 . V_57 . V_58 = F_12 ( F_13 ( V_35 -> V_59 ) ) ;
V_33 -> V_56 . V_57 . V_60 = F_12 ( F_14 ( V_35 -> V_59 ) ) ;
F_20 ( V_2 , V_2 -> V_5 . V_13 . V_7 , V_114 ) ;
V_114 ++ ;
if ( V_114 == V_2 -> V_5 . V_32 )
V_114 = 0 ;
V_2 -> V_5 . V_13 . V_85 = V_114 ;
V_2 -> V_5 . V_13 . V_84 = V_150 ;
V_153:
if ( V_148 != NULL )
* V_148 = ( V_114 > V_150 ? V_2 -> V_5 . V_13 . V_80 : 0 ) + ( V_150 - V_114 ) ;
F_26 ( & V_2 -> V_5 . V_88 ) ;
return V_23 ;
}
static void F_32 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_6 . V_84 = 0 ;
V_2 -> V_5 . V_6 . V_85 = 0 ;
F_19 ( V_2 ) ;
V_2 -> V_5 . V_13 . V_84 = 0 ;
V_2 -> V_5 . V_13 . V_85 = 0 ;
F_21 ( V_2 ) ;
}
