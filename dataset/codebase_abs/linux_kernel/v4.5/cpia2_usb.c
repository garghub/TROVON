static void F_1 ( struct V_1 * V_2 )
{
static int V_3 ;
unsigned char * V_4 = V_2 -> V_5 -> V_6 ;
F_2 ( L_1 ,
V_2 -> V_5 -> V_7 , V_2 -> V_8 -> V_7 ) ;
if( V_2 -> V_5 -> V_9 > V_2 -> V_5 -> V_10 )
V_2 -> V_5 -> V_10 = V_2 -> V_5 -> V_9 ;
if ( ( V_4 [ 0 ] == 0xFF ) && ( V_4 [ 1 ] == 0xD8 ) ) {
V_3 ++ ;
} else {
V_2 -> V_5 -> V_11 = V_12 ;
F_2 ( L_2 ) ;
return;
}
if( ! V_2 -> V_13 ) {
V_2 -> V_13 = 1 ;
V_2 -> V_5 -> V_11 = V_14 ;
return;
}
if ( V_2 -> V_5 -> V_9 > 3 ) {
if( V_2 -> V_15 &&
V_2 -> V_5 -> V_9 < V_2 -> V_5 -> V_10 ) {
memset ( V_2 -> V_5 -> V_6 + V_2 -> V_5 -> V_9 ,
0 , V_2 -> V_5 -> V_10 -
V_2 -> V_5 -> V_9 ) ;
}
V_2 -> V_5 -> V_10 = V_2 -> V_5 -> V_9 ;
V_2 -> V_5 -> V_11 = V_16 ;
if( ! V_2 -> V_15 && V_2 -> V_17 > 2 ) {
V_2 -> V_8 -> V_11 = V_14 ;
}
V_2 -> V_8 = V_2 -> V_5 ;
V_2 -> V_5 = V_2 -> V_5 -> V_18 ;
F_2 ( L_3 ,
V_2 -> V_5 -> V_7 , V_2 -> V_8 -> V_7 ) ;
return;
} else {
F_2 ( L_4 ) ;
}
V_2 -> V_5 -> V_11 = V_12 ;
return;
}
static void F_3 ( struct V_1 * V_2 )
{
if( V_2 -> V_19 > 0 ) {
V_2 -> V_5 -> V_6 [ V_2 -> V_5 -> V_9 ++ ] = 0xFF ;
V_2 -> V_5 -> V_6 [ V_2 -> V_5 -> V_9 ++ ] = 0xE0 + V_2 -> V_20 ;
V_2 -> V_5 -> V_6 [ V_2 -> V_5 -> V_9 ++ ] = 0 ;
V_2 -> V_5 -> V_6 [ V_2 -> V_5 -> V_9 ++ ] = V_2 -> V_19 + 2 ;
memcpy ( V_2 -> V_5 -> V_6 + V_2 -> V_5 -> V_9 ,
V_2 -> V_21 , V_2 -> V_19 ) ;
V_2 -> V_5 -> V_9 += V_2 -> V_19 ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
if( V_2 -> V_22 > 0 ) {
V_2 -> V_5 -> V_6 [ V_2 -> V_5 -> V_9 ++ ] = 0xFF ;
V_2 -> V_5 -> V_6 [ V_2 -> V_5 -> V_9 ++ ] = 0xFE ;
V_2 -> V_5 -> V_6 [ V_2 -> V_5 -> V_9 ++ ] = 0 ;
V_2 -> V_5 -> V_6 [ V_2 -> V_5 -> V_9 ++ ] = V_2 -> V_22 + 2 ;
memcpy ( V_2 -> V_5 -> V_6 + V_2 -> V_5 -> V_9 ,
V_2 -> V_23 , V_2 -> V_22 ) ;
V_2 -> V_5 -> V_9 += V_2 -> V_22 ;
}
}
static void F_5 ( struct V_24 * V_24 )
{
int V_25 ;
unsigned char * V_26 ;
static bool V_27 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_24 -> V_28 ;
if ( V_24 -> V_11 != 0 ) {
if ( ! ( V_24 -> V_11 == - V_29 ||
V_24 -> V_11 == - V_30 ||
V_24 -> V_11 == - V_31 ) )
{
F_2 ( L_5 , V_24 -> V_11 ) ;
}
F_2 ( L_6 ) ;
return;
}
if ( ! V_2 -> V_32 || ! F_6 ( & V_2 -> V_33 ) ) {
LOG ( L_7 ,
V_2 -> V_32 , F_6 ( & V_2 -> V_33 ) ) ;
return;
}
for ( V_25 = 0 ; V_25 < V_24 -> V_34 ; V_25 ++ ) {
T_1 V_35 , V_36 ;
int V_37 ;
int V_38 = V_24 -> V_39 [ V_25 ] . V_40 ;
int V_41 = V_24 -> V_39 [ V_25 ] . V_11 ;
if( V_2 -> V_5 -> V_11 == V_16 ) {
struct V_42 * V_43 ;
F_2 ( L_8 ) ;
for ( V_43 = V_2 -> V_5 -> V_18 ;
V_43 != V_2 -> V_5 ;
V_43 = V_43 -> V_18 )
{
if ( V_43 -> V_11 == V_14 ) {
V_43 -> V_11 = V_44 ;
V_43 -> V_9 = 0 ;
break;
}
}
if ( V_43 == V_2 -> V_5 )
break;
V_2 -> V_5 = V_43 ;
}
if ( V_2 -> V_5 -> V_11 == V_14 ||
V_2 -> V_5 -> V_11 == V_12 ) {
V_2 -> V_5 -> V_11 = V_44 ;
V_2 -> V_5 -> V_9 = 0 ;
}
V_26 = V_24 -> V_45 + V_24 -> V_39 [ V_25 ] . V_46 ;
if ( V_41 ) {
LOG ( L_9 ,
V_25 , V_38 , V_41 ) ;
if( ! V_47 )
V_2 -> V_5 -> V_11 = V_12 ;
continue;
}
if( V_38 <= 2 )
continue;
V_35 = 0 ;
for( V_37 = 0 ; V_37 < V_38 - 2 ; ++ V_37 )
V_35 += V_26 [ V_37 ] ;
V_36 = V_26 [ V_37 ] + V_26 [ V_37 + 1 ] * 256 ;
if( V_35 != V_36 ) {
LOG ( L_10 ,
V_25 , V_38 , ( int ) V_35 , ( int ) V_36 ) ;
if( ! V_47 ) {
V_2 -> V_5 -> V_11 = V_12 ;
continue;
}
}
V_38 -= 2 ;
if( V_2 -> V_5 -> V_11 != V_44 ) {
if( ( 0xFF == V_26 [ 0 ] && 0xD8 == V_26 [ 1 ] ) ||
( 0xD8 == V_26 [ 0 ] && 0xFF == V_26 [ 1 ] &&
0 != V_26 [ 2 ] ) ) {
V_2 -> V_3 ++ ;
}
F_2 ( L_11 ,
V_2 -> V_5 -> V_11 ) ;
continue;
}
if ( V_2 -> V_48 < V_2 -> V_5 -> V_9 + V_38 ) {
F_7 ( L_12 ,
V_2 -> V_5 -> V_9 , V_38 ) ;
V_2 -> V_5 -> V_11 = V_12 ;
if( V_2 -> V_5 -> V_9 > V_2 -> V_5 -> V_10 )
V_2 -> V_5 -> V_10 =
V_2 -> V_5 -> V_9 ;
continue;
}
if ( V_2 -> V_5 -> V_9 == 0 ) {
int V_49 ;
if ( ( 0xD8 == V_26 [ 0 ] ) && ( 0xFF == V_26 [ 1 ] ) ) {
V_49 = 1 ;
} else if( ( 0xFF == V_26 [ 0 ] ) && ( 0xD8 == V_26 [ 1 ] )
&& ( 0xFF == V_26 [ 2 ] ) ) {
V_49 = 2 ;
} else {
F_2 ( L_13 ) ;
continue;
}
F_2 ( L_14 ) ;
F_8 ( & V_2 -> V_5 -> V_50 ) ;
V_2 -> V_5 -> V_51 = V_2 -> V_3 ++ ;
V_2 -> V_5 -> V_6 [ 0 ] = 0xFF ;
V_2 -> V_5 -> V_6 [ 1 ] = 0xD8 ;
V_2 -> V_5 -> V_9 = 2 ;
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
memcpy ( V_2 -> V_5 -> V_6 + V_2 -> V_5 -> V_9 ,
V_26 + V_49 , V_38 - V_49 ) ;
V_2 -> V_5 -> V_9 += V_38 - V_49 ;
} else if ( V_2 -> V_5 -> V_9 > 0 ) {
memcpy ( V_2 -> V_5 -> V_6 + V_2 -> V_5 -> V_9 ,
V_26 , V_38 ) ;
V_2 -> V_5 -> V_9 += V_38 ;
}
if ( ( V_2 -> V_5 -> V_9 >= 3 ) &&
( V_2 -> V_5 -> V_6 [ V_2 -> V_5 -> V_9 - 3 ] == 0xFF ) &&
( V_2 -> V_5 -> V_6 [ V_2 -> V_5 -> V_9 - 2 ] == 0xD9 ) &&
( V_2 -> V_5 -> V_6 [ V_2 -> V_5 -> V_9 - 1 ] == 0xFF ) ) {
V_27 = true ;
V_2 -> V_5 -> V_6 [ V_2 -> V_5 -> V_9 - 1 ] = 0 ;
V_2 -> V_5 -> V_9 -= 1 ;
} else if ( ( V_2 -> V_5 -> V_9 >= 2 ) &&
( V_2 -> V_5 -> V_6 [ V_2 -> V_5 -> V_9 - 2 ] == 0xFF ) &&
( V_2 -> V_5 -> V_6 [ V_2 -> V_5 -> V_9 - 1 ] == 0xD9 ) ) {
V_27 = true ;
}
if ( V_27 ) {
F_2 ( L_15 , V_2 -> V_5 -> V_9 ) ;
F_1 ( V_2 ) ;
V_27 = false ;
if ( F_9 ( & V_2 -> V_52 ) )
F_10 ( & V_2 -> V_52 ) ;
}
}
if( V_2 -> V_32 ) {
V_24 -> V_53 = V_2 -> V_53 ;
if ( ( V_25 = F_11 ( V_24 , V_54 ) ) != 0 )
F_7 ( L_16 , V_55 , V_25 ) ;
}
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_56 )
{
static unsigned char V_57 [ 8 ] [ 4 ] = {
{ 0x00 , 0x00 , 0x00 , 0x00 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 } ,
{ 0xB9 , 0x00 , 0x00 , 0x7E } ,
{ 0xB9 , 0x00 , 0x01 , 0x7E } ,
{ 0xB9 , 0x00 , 0x02 , 0x7E } ,
{ 0xB9 , 0x00 , 0x02 , 0xFE } ,
{ 0xB9 , 0x00 , 0x03 , 0x7E } ,
{ 0xB9 , 0x00 , 0x03 , 0xFD }
} ;
struct V_58 V_59 ;
unsigned char V_60 ;
if ( ! F_6 ( & V_2 -> V_33 ) )
return - V_61 ;
V_59 . V_62 = V_63 ;
V_59 . V_64 . V_65 [ 0 ] = V_57 [ V_56 ] [ 0 ] ;
V_59 . V_64 . V_65 [ 1 ] = V_57 [ V_56 ] [ 1 ] ;
V_59 . V_64 . V_65 [ 2 ] = V_57 [ V_56 ] [ 2 ] ;
V_59 . V_64 . V_65 [ 3 ] = V_57 [ V_56 ] [ 3 ] ;
V_59 . V_66 = V_67 | V_68 ;
V_59 . V_69 = V_70 ;
V_59 . V_71 = 4 ;
F_13 ( V_2 , & V_59 ) ;
V_59 . V_62 = V_72 ;
V_59 . V_66 = V_67 | V_68 ;
V_59 . V_69 = V_73 ;
V_59 . V_71 = 1 ;
F_13 ( V_2 , & V_59 ) ;
V_60 = V_59 . V_64 . V_65 [ 0 ] ;
V_60 &= ~ ( V_74 |
V_75 |
V_76 ) ;
if ( V_56 == V_77 ) {
F_2 ( L_17 ) ;
V_60 |= V_74 ;
V_2 -> V_78 = V_79 ;
} else if ( V_56 >= V_80 ) {
F_2 ( L_18 ) ;
V_60 |= V_75 ;
V_2 -> V_78 = V_81 ;
}
V_59 . V_64 . V_65 [ 0 ] = V_60 ;
V_59 . V_62 = V_63 ;
V_59 . V_69 = V_73 ;
V_59 . V_71 = 1 ;
V_59 . V_66 = V_67 | V_68 ;
F_13 ( V_2 , & V_59 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
unsigned int V_56 )
{
int V_82 = 0 ;
if( V_56 < V_80 || V_56 > V_83 )
return - V_84 ;
if( V_56 == V_2 -> V_85 . V_86 . V_87 )
return 0 ;
F_15 ( V_2 ) ;
F_12 ( V_2 , V_56 ) ;
V_2 -> V_85 . V_86 . V_87 = V_56 ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
return V_82 ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_56 )
{
int V_82 = 0 ;
if( V_56 == V_2 -> V_88 )
return 0 ;
if ( V_2 -> V_88 != V_89 ) {
F_2 ( L_19 , V_2 -> V_88 , V_89 ) ;
V_82 = F_19 ( V_2 -> V_53 , V_2 -> V_90 , V_89 ) ;
if ( V_82 != 0 )
return V_82 ;
}
if ( V_56 != V_89 ) {
F_2 ( L_19 , V_89 , V_56 ) ;
V_82 = F_19 ( V_2 -> V_53 , V_2 -> V_90 , V_56 ) ;
if ( V_82 != 0 )
return V_82 ;
}
V_2 -> V_91 = V_2 -> V_88 ;
V_2 -> V_88 = V_56 ;
return V_82 ;
}
static void F_20 ( struct V_1 * V_2 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_92 ; V_25 ++ ) {
if( V_2 -> V_93 [ V_25 ] . V_24 ) {
F_21 ( V_2 -> V_93 [ V_25 ] . V_24 ) ;
F_22 ( V_2 -> V_93 [ V_25 ] . V_24 ) ;
V_2 -> V_93 [ V_25 ] . V_24 = NULL ;
}
if( V_2 -> V_93 [ V_25 ] . V_6 ) {
F_23 ( V_2 -> V_93 [ V_25 ] . V_6 ) ;
V_2 -> V_93 [ V_25 ] . V_6 = NULL ;
}
}
}
static int F_24 ( struct V_94 * V_95 ,
T_2 V_96 , T_2 * V_97 , T_1 V_69 , T_3 V_98 )
{
if ( ! V_97 || V_98 <= 0 )
return - V_84 ;
return F_25 ( V_95 ,
F_26 ( V_95 , 0 ) ,
V_96 ,
V_99 | V_100 ,
V_69 ,
0 ,
V_97 ,
V_98 ,
V_101 ) ;
}
static int F_27 ( struct V_94 * V_95 ,
T_2 V_96 , T_2 * V_97 , T_1 V_69 , T_3 V_98 )
{
if ( ! V_97 || V_98 <= 0 )
return - V_84 ;
return F_25 ( V_95 ,
F_28 ( V_95 , 0 ) ,
V_96 ,
V_102 | V_99 | V_100 ,
V_69 ,
0 ,
V_97 ,
V_98 ,
V_101 ) ;
}
int F_29 ( struct V_1 * V_2 ,
void * V_97 ,
T_2 V_96 , T_2 V_69 , T_2 V_103 , T_2 V_62 )
{
int V_104 = 0 ;
struct V_94 * V_95 = V_2 -> V_53 ;
if ( ! V_95 ) {
F_7 ( L_20 , V_55 ) ;
return - V_84 ;
}
if ( ! V_97 ) {
F_7 ( L_21 , V_55 ) ;
return - V_84 ;
}
if ( V_62 == V_72 ) {
V_104 = F_27 ( V_95 , V_96 , ( T_2 * ) V_97 , V_69 , V_103 ) ;
if ( V_104 > 0 )
V_104 = 0 ;
} else if ( V_62 == V_63 ) {
V_104 = F_24 ( V_95 , V_96 , ( T_2 * ) V_97 , V_69 , V_103 ) ;
if ( V_104 < 0 ) {
LOG ( L_22 , V_104 ) ;
LOG ( L_23 ,
V_96 , V_69 ) ;
LOG ( L_24 ,
V_103 , ( ( unsigned char * ) V_97 ) [ 0 ] ) ;
} else
V_104 = 0 ;
} else {
LOG ( L_25 ,
V_62 ) ;
return - V_84 ;
}
if( V_104 != 0 )
LOG ( L_26 , V_104 ) ;
return V_104 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_24 * V_24 ;
int V_105 , V_104 , V_25 , V_37 ;
for( V_25 = 0 ; V_25 < V_92 ; ++ V_25 ) {
if ( V_2 -> V_93 [ V_25 ] . V_6 )
continue;
V_2 -> V_93 [ V_25 ] . V_6 =
F_31 ( V_106 * V_107 , V_108 ) ;
if ( ! V_2 -> V_93 [ V_25 ] . V_6 ) {
while ( -- V_25 >= 0 ) {
F_23 ( V_2 -> V_93 [ V_25 ] . V_6 ) ;
V_2 -> V_93 [ V_25 ] . V_6 = NULL ;
}
return - V_109 ;
}
}
for( V_25 = 0 ; V_25 < V_92 ; ++ V_25 ) {
if( V_2 -> V_93 [ V_25 ] . V_24 ) {
continue;
}
V_24 = F_32 ( V_106 , V_108 ) ;
if ( ! V_24 ) {
F_7 ( L_27 , V_55 ) ;
for ( V_37 = 0 ; V_37 < V_25 ; V_37 ++ )
F_22 ( V_2 -> V_93 [ V_37 ] . V_24 ) ;
return - V_109 ;
}
V_2 -> V_93 [ V_25 ] . V_24 = V_24 ;
V_24 -> V_53 = V_2 -> V_53 ;
V_24 -> V_28 = V_2 ;
V_24 -> V_110 = F_33 ( V_2 -> V_53 , 1 ) ;
V_24 -> V_111 = V_112 ;
V_24 -> V_45 = V_2 -> V_93 [ V_25 ] . V_6 ;
V_24 -> V_113 = F_5 ;
V_24 -> V_34 = V_106 ;
V_24 -> V_114 = 1 ;
V_24 -> V_115 =
V_107 * V_106 ;
for ( V_105 = 0 ; V_105 < V_106 ; V_105 ++ ) {
V_24 -> V_39 [ V_105 ] . V_46 =
V_107 * V_105 ;
V_24 -> V_39 [ V_105 ] . V_9 = V_107 ;
}
}
for( V_25 = 0 ; V_25 < V_92 ; ++ V_25 ) {
V_104 = F_11 ( V_2 -> V_93 [ V_25 ] . V_24 , V_108 ) ;
if ( V_104 ) {
F_7 ( L_28 , V_25 , V_104 ) ;
return V_104 ;
}
}
return 0 ;
}
int F_34 ( struct V_1 * V_2 , unsigned int V_116 )
{
int V_82 ;
int V_91 ;
if( V_2 -> V_32 )
return 0 ;
if ( V_2 -> V_117 ) {
int V_25 ;
F_2 ( L_29 ) ;
for( V_25 = 0 ; V_25 < V_2 -> V_17 ; ++ V_25 ) {
V_2 -> V_118 [ V_25 ] . V_11 = V_14 ;
V_2 -> V_118 [ V_25 ] . V_9 = 0 ;
}
V_2 -> V_8 = & V_2 -> V_118 [ 0 ] ;
V_2 -> V_5 = V_2 -> V_8 -> V_18 ;
V_2 -> V_117 = false ;
}
V_91 = V_2 -> V_85 . V_86 . V_87 ;
V_2 -> V_85 . V_86 . V_87 = 0 ;
V_82 = F_14 ( V_2 , V_116 ) ;
if ( V_82 < 0 ) {
int V_119 ;
F_7 ( L_30 , V_82 ) ;
V_2 -> V_85 . V_86 . V_87 = V_91 ;
V_119 = F_18 ( V_2 , V_89 ) ;
if ( V_119 < 0 ) {
F_7 ( L_31
L_32
L_33 ,
V_116 , V_82 , V_119 ) ;
}
} else {
V_2 -> V_3 = 0 ;
V_2 -> V_32 = 1 ;
V_82 = F_17 ( V_2 ) ;
}
return V_82 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_82 = 0 ;
if( V_2 -> V_32 ) {
F_20 ( V_2 ) ;
V_82 = F_18 ( V_2 , V_89 ) ;
}
return V_82 ;
}
int F_17 ( struct V_1 * V_2 )
{
int V_82 = 0 ;
if( V_2 -> V_32 ) {
V_2 -> V_13 = 0 ;
V_82 = F_18 ( V_2 , V_2 -> V_85 . V_86 . V_87 ) ;
if( V_82 == 0 ) {
F_35 ( V_2 , V_120 , V_63 ,
V_2 -> V_85 . V_121 . V_122 ) ;
V_82 = F_30 ( V_2 ) ;
}
}
return V_82 ;
}
int F_36 ( struct V_1 * V_2 )
{
int V_82 ;
V_82 = F_15 ( V_2 ) ;
V_2 -> V_32 = 0 ;
F_12 ( V_2 , 0 ) ;
return V_82 ;
}
static int F_37 ( struct V_123 * V_124 ,
const struct V_125 * V_126 )
{
struct V_94 * V_95 = F_38 ( V_124 ) ;
struct V_127 * V_128 ;
struct V_1 * V_2 ;
int V_82 ;
if ( V_95 -> V_129 . V_130 != 1 )
return - V_61 ;
V_128 = & V_124 -> V_131 -> V_132 ;
LOG ( L_34 ) ;
V_2 = F_39 ( V_124 ) ;
if ( V_2 == NULL )
return - V_109 ;
V_2 -> V_53 = V_95 ;
V_2 -> V_90 = V_128 -> V_133 ;
V_82 = F_18 ( V_2 , V_89 ) ;
if ( V_82 < 0 ) {
F_7 ( L_35 , V_55 , V_82 ) ;
F_23 ( V_2 ) ;
return V_82 ;
}
if( ( V_82 = F_40 ( V_2 ) ) < 0 ) {
F_7 ( L_36 , V_55 , V_82 ) ;
F_23 ( V_2 ) ;
return V_82 ;
}
LOG ( L_37 ,
V_2 -> V_85 . V_134 . V_135 ,
V_2 -> V_85 . V_134 . V_136 ,
V_2 -> V_85 . V_134 . V_137 ,
V_2 -> V_85 . V_134 . V_138 ) ;
LOG ( L_38 ,
V_2 -> V_85 . V_139 . V_140 ,
V_2 -> V_85 . V_139 . V_141 ,
V_2 -> V_85 . V_139 . V_142 ) ;
LOG ( L_39 ,
V_2 -> V_85 . V_134 . V_143 ,
V_2 -> V_85 . V_134 . V_144 ) ;
F_41 ( V_124 , V_2 ) ;
V_82 = F_42 ( V_2 ) ;
if ( V_82 < 0 ) {
F_7 ( L_40 , V_55 , V_82 ) ;
F_23 ( V_2 ) ;
return V_82 ;
}
return 0 ;
}
static void F_43 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = F_44 ( V_124 ) ;
F_41 ( V_124 , NULL ) ;
F_2 ( L_41 ) ;
F_36 ( V_2 ) ;
F_45 ( & V_2 -> V_145 ) ;
F_2 ( L_42 ) ;
F_46 ( V_2 ) ;
F_47 ( & V_2 -> V_146 ) ;
F_48 ( & V_2 -> V_145 ) ;
F_49 ( & V_2 -> V_146 ) ;
if( V_2 -> V_118 ) {
F_2 ( L_43 ) ;
V_2 -> V_8 -> V_11 = V_16 ;
V_2 -> V_8 -> V_9 = 0 ;
F_10 ( & V_2 -> V_52 ) ;
}
F_2 ( L_44 ) ;
F_50 ( & V_147 , V_124 ) ;
LOG ( L_45 ) ;
}
static int F_51 ( struct V_123 * V_124 , T_4 V_148 )
{
struct V_1 * V_2 = F_44 ( V_124 ) ;
F_45 ( & V_2 -> V_145 ) ;
if ( V_2 -> V_32 ) {
F_36 ( V_2 ) ;
V_2 -> V_32 = 1 ;
}
F_48 ( & V_2 -> V_145 ) ;
F_52 ( & V_124 -> V_53 , L_46 ) ;
return 0 ;
}
static int F_53 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = F_44 ( V_124 ) ;
F_45 ( & V_2 -> V_145 ) ;
F_54 ( & V_2 -> V_149 ) ;
if ( V_2 -> V_32 ) {
V_2 -> V_32 = 0 ;
F_34 ( V_2 ,
V_2 -> V_85 . V_86 . V_87 ) ;
}
F_48 ( & V_2 -> V_145 ) ;
F_52 ( & V_124 -> V_53 , L_47 ) ;
return 0 ;
}
int F_55 ( void )
{
return F_56 ( & V_147 ) ;
}
void F_57 ( void )
{
F_58 ( 2 * V_101 ) ;
F_59 ( & V_147 ) ;
}
