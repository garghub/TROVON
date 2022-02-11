static void F_1 ( struct V_1 * V_2 , int V_3 , void * V_4 , short V_5 )
{
char * V_6 ;
const void * V_7 ;
int V_8 , V_9 ;
V_6 = V_4 ;
while( V_5 )
{
V_8 = V_3 & V_10 ;
V_9 = V_8 + V_5 > V_11 ? V_11 - V_8 : V_5 ;
V_7 = ( const void * ) ( V_2 -> V_12 + V_8 ) ;
F_2 ( V_2 , V_3 ) ;
memcpy ( V_6 , V_7 , V_9 ) ;
V_3 += V_9 ;
V_6 += V_9 ;
V_5 -= V_9 ;
}
}
static void F_3 ( struct V_1 * V_2 , int V_3 , void * V_4 , short V_5 )
{
unsigned long V_13 ;
F_4 ( & V_14 , V_13 ) ;
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
F_5 ( & V_14 , V_13 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_3 ,
const void * V_4 , short V_5 )
{
const char * V_6 ;
void * V_7 ;
int V_8 , V_9 ;
V_6 = V_4 ;
while( V_5 )
{
V_8 = V_3 & V_10 ;
V_9 = V_8 + V_5 > V_11 ? V_11 - V_8 : V_5 ;
V_7 = ( void * ) ( V_2 -> V_12 + V_8 ) ;
F_2 ( V_2 , V_3 ) ;
memcpy ( V_7 , V_6 , V_9 ) ;
V_3 += V_9 ;
V_6 += V_9 ;
V_5 -= V_9 ;
}
}
static void F_7 ( struct V_1 * V_2 , int V_3 ,
const void * V_4 , short V_5 )
{
unsigned long V_13 ;
F_4 ( & V_14 , V_13 ) ;
F_6 ( V_2 , V_3 , V_4 , V_5 ) ;
F_5 ( & V_14 , V_13 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned long V_13 ;
char * V_7 ;
int V_5 , V_3 , V_9 ;
V_5 = 65536 ;
V_3 = 0 ;
V_9 = V_11 ;
V_7 = ( void * ) V_2 -> V_12 ;
F_4 ( & V_14 , V_13 ) ;
while( V_5 )
{
F_2 ( V_2 , V_3 ) ;
memset ( V_7 , 0 , V_9 ) ;
V_3 += V_9 ;
V_5 -= V_9 ;
}
F_5 ( & V_14 , V_13 ) ;
}
static char F_9 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_13 ;
char V_15 , * V_6 ;
V_6 = ( void * ) ( V_2 -> V_12 + ( V_3 & V_10 ) ) ;
F_4 ( & V_14 , V_13 ) ;
F_2 ( V_2 , V_3 ) ;
V_15 = * V_6 ;
F_5 ( & V_14 , V_13 ) ;
return V_15 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
V_17 = F_11 ( V_2 ) ;
switch( V_17 -> type )
{
case V_18 :
F_12 ( V_19 , V_2 -> V_20 + V_21 ) ;
V_17 -> V_22 = V_23 ;
break;
case V_24 :
F_12 ( V_23 , V_2 -> V_20 + V_25 ) ;
F_12 ( V_26 , V_2 -> V_20 + V_21 ) ;
V_17 -> V_22 = V_26 ;
break;
case V_27 :
V_17 -> V_22 &= ~ V_28 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
break;
case V_29 :
V_17 -> V_22 &= ~ V_28 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
break;
}
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
V_17 = F_11 ( V_2 ) ;
switch( V_17 -> type )
{
case V_18 :
F_12 ( V_30 , V_2 -> V_20 + V_21 ) ;
F_12 ( V_31 , V_2 -> V_20 + V_21 ) ;
V_17 -> V_22 = V_31 ;
break;
case V_24 :
F_12 ( V_32 , V_2 -> V_20 + V_25 ) ;
F_12 ( 0x00 , V_2 -> V_20 + V_21 ) ;
V_17 -> V_22 = 0 ;
break;
case V_27 :
V_17 -> V_22 |= V_28 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
break;
case V_29 :
V_17 -> V_22 |= V_28 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
break;
}
}
static int F_14 ( struct V_1 * V_2 , int V_33 , int V_34 , char V_35 , char V_36 )
{
unsigned long V_37 , V_38 , V_39 ;
char V_40 , * V_6 ;
V_37 = V_39 = V_41 ;
V_38 = V_41 + V_34 ;
V_6 = ( void * ) V_2 -> V_12 ;
V_6 += V_33 & V_10 ;
V_40 = ~ V_35 ;
while ( F_15 ( V_41 , V_38 ) && ( V_40 != V_35 ) && ( ! V_36 || ( V_40 != V_36 ) ) )
{
if ( V_41 != V_39 )
{
F_2 ( V_2 , V_33 ) ;
V_39 = V_41 ;
V_40 = * V_6 ;
}
}
return F_15 ( V_41 , V_38 ) ? V_41 - V_37 : - 1 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
int V_34 ;
char V_44 ;
F_13 ( V_2 ) ;
if ( F_14 ( V_2 , 0 , 3 * V_45 , V_46 , 0 ) < 0 )
return - V_47 ;
V_44 = V_48 ;
F_7 ( V_2 , 0 , & V_44 , 1 ) ;
if ( ( V_34 = F_14 ( V_2 , 0 , 8 * V_45 , V_49 , V_50 ) ) < 0 )
return - V_47 ;
F_10 ( V_2 ) ;
F_3 ( V_2 , 0 , & V_44 , 1 ) ;
if ( V_44 == V_50 )
{
F_17 ( L_1 , V_2 -> V_51 ) ;
return - V_47 ;
}
if ( V_44 != V_49 )
return - V_52 ;
if ( V_34 < 165 )
V_43 -> V_53 = V_54 ;
else if ( V_34 < 220 )
V_43 -> V_53 = V_55 ;
else if ( V_34 < 258 )
V_43 -> V_53 = V_56 ;
else if ( V_34 < 357 )
V_43 -> V_53 = V_57 ;
else if ( V_34 < 467 )
V_43 -> V_53 = V_58 ;
else
V_43 -> V_53 = V_59 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , int V_60 , int V_61 , int V_62 , int V_5 , void * V_44 )
{
struct V_63 * V_64 ;
short * V_65 ;
int V_66 ;
char * V_22 , line [ 30 ] ;
switch ( V_62 )
{
case V_67 :
V_22 = V_44 ;
if ( * V_22 & V_68 )
F_17 ( V_69 L_2 , V_2 -> V_51 ) ;
if ( * V_22 & V_70 )
F_17 ( V_69 L_3 , V_2 -> V_51 ) ;
break;
case V_71 :
F_17 ( V_69 L_4 , V_2 -> V_51 ) ;
break;
case V_72 :
F_17 ( V_69 L_5 , V_2 -> V_51 ) ;
break;
case V_73 :
F_17 ( V_69 L_6 , V_2 -> V_51 ) ;
V_5 /= sizeof( struct V_63 ) ;
for( V_64 = V_44 , V_66 = 0 ; V_66 < V_5 ; V_66 ++ , V_64 ++ )
{
if ( V_64 -> V_13 & V_74 )
V_22 = L_7 ;
else if ( V_64 -> V_13 & V_75 )
V_22 = L_8 ;
else if ( V_64 -> V_13 & V_76 )
V_22 = L_9 ;
else
{
sprintf ( line , L_10 , V_64 -> V_13 ) ;
V_22 = line ;
}
F_17 ( V_69 L_11 , V_2 -> V_51 , V_64 -> V_61 , V_22 ) ;
}
break;
case V_77 :
F_17 ( V_69 L_12 , V_2 -> V_51 ) ;
V_5 /= sizeof( short ) ;
for( V_65 = V_44 , V_66 = 0 ; V_66 < V_5 ; V_66 ++ , V_65 ++ )
F_17 ( L_13 , * V_65 ) ;
F_17 ( L_14 ) ;
break;
case V_78 :
F_17 ( V_79 L_15 , V_2 -> V_51 ) ;
break;
case V_80 :
F_17 ( V_69 L_16 , V_2 -> V_51 , V_5 ) ;
break;
case V_81 :
F_17 ( V_69 L_17 , V_2 -> V_51 , V_5 ) ;
break;
case V_82 :
case V_83 :
case V_84 :
case V_85 :
if ( V_60 == V_86 )
break;
default:
F_17 ( V_87 L_18 , V_2 -> V_51 , V_60 , V_62 ) ;
break;
}
}
static int F_19 ( struct V_1 * V_2 , int V_60 , short V_61 , short V_13 ,
void * V_88 , short V_89 , void * V_90 , short * V_91 )
{
static struct V_92 V_93 ;
struct V_16 * V_17 ;
struct F_19 * V_94 ;
unsigned long V_95 ;
unsigned long V_34 ;
int V_62 , V_96 , V_5 ;
long V_97 ;
V_17 = F_11 ( V_2 ) ;
V_97 = V_17 -> type == V_29 ? V_98 : V_99 ;
V_94 = (struct F_19 * ) ( V_2 -> V_12 + ( V_97 & V_10 ) ) ;
V_62 = 0 ;
V_5 = 0 ;
V_34 = V_41 + V_45 ;
F_4 ( & V_14 , V_95 ) ;
F_2 ( V_2 , V_97 ) ;
V_94 -> V_60 = V_60 ;
V_94 -> V_61 = V_61 ;
V_94 -> V_13 = V_13 ;
if ( V_88 )
memcpy ( V_94 -> V_44 , V_88 , V_89 ) ;
V_94 -> V_100 = V_89 ;
V_94 -> V_101 = 1 ;
F_5 ( & V_14 , V_95 ) ;
V_96 = 1 ;
V_5 = 0 ;
while ( V_96 && F_20 ( V_41 , V_34 ) )
{
if ( V_96 ++ % 3 )
{
F_4 ( & V_14 , V_95 ) ;
F_2 ( V_2 , V_97 ) ;
V_96 = ( ( volatile int ) ( V_94 -> V_101 ) ) ;
F_5 ( & V_14 , V_95 ) ;
}
}
if ( ! V_96 )
{
F_4 ( & V_14 , V_95 ) ;
F_2 ( V_2 , V_97 ) ;
V_62 = V_94 -> V_102 ;
V_5 = V_94 -> V_100 ;
if ( V_90 && V_91 )
{
* V_91 = * V_91 >= V_5 ? V_5 : * V_91 ;
if ( * V_91 )
memcpy ( V_90 , V_94 -> V_44 , * V_91 ) ;
}
if ( V_62 )
memcpy ( & V_93 , V_94 -> V_44 , V_5 > sizeof( V_93 ) ? sizeof( V_93 ) : V_5 ) ;
F_5 ( & V_14 , V_95 ) ;
}
else
V_62 = V_78 ;
if ( V_62 != V_103 )
F_18 ( V_2 , V_60 , V_61 , V_62 , V_5 , & V_93 ) ;
return V_62 ;
}
static int F_21 ( struct V_1 * V_104 , struct V_1 * V_105 )
{
struct V_16 * V_17 ;
int V_66 ;
V_17 = F_11 ( V_104 ) ;
for( V_66 = 0 ; V_66 < V_106 ; V_66 ++ )
if ( V_17 -> V_105 [ V_66 ] == V_105 )
break;
if ( V_66 == V_106 )
return - V_107 ;
V_17 -> V_61 [ V_66 ] = abs ( V_17 -> V_61 [ V_66 ] ) ;
if ( F_22 ( V_104 ) && ( V_17 -> V_108 . V_109 == V_110 ) )
F_19 ( V_104 , V_111 , 0 , 0 , & V_17 -> V_61 [ V_66 ] , sizeof( short ) , NULL , NULL ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_104 , struct V_1 * V_105 )
{
struct V_16 * V_17 ;
int V_66 ;
V_17 = F_11 ( V_104 ) ;
for( V_66 = 0 ; V_66 < V_106 ; V_66 ++ )
if ( V_17 -> V_105 [ V_66 ] == V_105 )
break;
if ( V_66 == V_106 )
return - V_107 ;
V_17 -> V_61 [ V_66 ] = - abs ( V_17 -> V_61 [ V_66 ] ) ;
if ( F_22 ( V_104 ) && ( V_17 -> V_108 . V_109 == V_110 ) )
F_19 ( V_104 , V_112 , 0 , 0 , & V_17 -> V_61 [ V_66 ] , sizeof( short ) , NULL , NULL ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_104 , struct V_1 * V_105 )
{
struct V_16 * V_17 ;
int V_66 ;
if ( V_105 -> type != V_113 )
return - V_52 ;
V_17 = F_11 ( V_104 ) ;
for( V_66 = 0 ; V_66 < V_106 ; V_66 ++ )
{
if ( ! V_17 -> V_105 [ V_66 ] )
break;
if ( abs ( V_17 -> V_61 [ V_66 ] ) == * ( short * ) ( V_105 -> V_114 ) )
return - V_115 ;
}
if ( V_66 == V_106 )
return - V_116 ;
V_17 -> V_105 [ V_66 ] = V_105 ;
V_17 -> V_61 [ V_66 ] = - * ( short * ) ( V_105 -> V_114 ) ;
V_105 -> V_117 = V_104 -> V_117 ;
if ( F_22 ( V_104 ) ) {
if ( V_17 -> V_108 . V_109 == V_118 )
F_25 ( V_104 ) ;
else
F_19 ( V_104 , V_119 , 0 , 0 , V_105 -> V_114 , sizeof( short ) , NULL , NULL ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_104 , struct V_1 * V_105 )
{
struct V_16 * V_17 ;
int V_66 ;
V_17 = F_11 ( V_104 ) ;
for( V_66 = 0 ; V_66 < V_106 ; V_66 ++ )
if ( V_17 -> V_105 [ V_66 ] == V_105 )
break;
if ( V_66 == V_106 )
return - V_107 ;
V_17 -> V_105 [ V_66 ] = NULL ;
V_17 -> V_61 [ V_66 ] = 0 ;
if ( F_22 ( V_104 ) ) {
if ( V_17 -> V_108 . V_109 == V_118 )
F_25 ( V_104 ) ;
else
F_19 ( V_104 , V_120 , 0 , 0 , V_105 -> V_114 , sizeof( short ) , NULL , NULL ) ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_104 , struct V_1 * V_105 , int V_121 )
{
struct V_16 * V_17 ;
struct V_122 * V_123 ;
int V_66 ;
short V_5 , V_62 ;
V_17 = F_11 ( V_104 ) ;
for( V_66 = 0 ; V_66 < V_106 ; V_66 ++ )
if ( V_17 -> V_105 [ V_66 ] == V_105 )
break;
if ( V_66 == V_106 )
return - V_107 ;
V_123 = F_11 ( V_105 ) ;
V_62 = V_103 ;
V_5 = sizeof( struct V_124 ) ;
if ( F_22 ( V_104 ) ) {
if ( V_121 )
V_62 = F_19 ( V_104 , V_125 , abs ( V_17 -> V_61 [ V_66 ] ) , 0 ,
NULL , 0 , & V_123 -> V_108 , & V_5 ) ;
else
V_62 = F_19 ( V_104 , V_126 , abs ( V_17 -> V_61 [ V_66 ] ) , 0 ,
& V_123 -> V_108 , sizeof( struct V_124 ) - 4 * sizeof( short ) , NULL , NULL ) ;
}
return V_62 == V_103 ? 0 : - V_47 ;
}
static T_1 F_28 ( struct V_127 * V_128 ,
struct V_1 * V_2 )
{
struct V_16 * V_17 ;
int V_62 , V_3 , V_129 , V_66 ;
short V_130 ;
unsigned long V_13 ;
struct V_131 * V_132 ;
V_17 = F_11 ( V_2 ) ;
V_62 = 0 ;
V_129 = 1 ;
F_29 ( V_2 ) ;
V_129 = 1 ;
switch ( V_2 -> type )
{
case V_133 :
if ( V_128 -> V_2 -> type != V_113 )
{
F_17 ( V_134 L_19 , V_2 -> V_51 , V_128 -> V_2 -> type ) ;
V_129 = 0 ;
}
break;
default:
F_17 ( V_134 L_20 , V_2 -> V_51 , V_2 -> type ) ;
V_129 = 0 ;
break;
}
if ( V_129 )
{
switch ( V_17 -> type )
{
case V_18 :
case V_24 :
V_62 = F_19 ( V_2 , V_86 , * ( short * ) ( V_128 -> V_2 -> V_114 ) , 0 , V_128 -> V_44 , V_128 -> V_5 , NULL , NULL ) ;
break;
case V_29 :
V_130 = sizeof( V_3 ) ;
V_62 = F_19 ( V_2 , V_86 , * ( short * ) ( V_128 -> V_2 -> V_114 ) , 0 , NULL , V_128 -> V_5 , & V_3 , & V_130 ) ;
if ( V_62 == V_103 )
{
F_4 ( & V_14 , V_13 ) ;
F_2 ( V_2 , V_3 ) ;
V_132 = ( void * ) ( ( ( int ) V_2 -> V_12 ) + ( V_3 & V_10 ) ) ;
F_6 ( V_2 , V_132 -> V_135 , V_128 -> V_44 , V_128 -> V_5 ) ;
F_2 ( V_2 , V_3 ) ;
V_132 -> V_101 = 1 ;
F_5 ( & V_14 , V_13 ) ;
}
break;
}
switch ( V_62 )
{
case V_103 :
V_2 -> V_136 . V_137 ++ ;
break;
case V_84 :
case V_80 :
case V_85 :
V_2 -> V_136 . V_138 ++ ;
break;
default:
V_2 -> V_136 . V_139 ++ ;
break;
}
}
F_30 ( V_2 ) ;
for( V_66 = 0 ; V_66 < V_106 ; V_66 ++ )
{
if( V_17 -> V_105 [ V_66 ] != NULL )
F_30 ( V_17 -> V_105 [ V_66 ] ) ;
}
F_31 ( V_128 ) ;
return V_140 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_1 * V_105 ;
struct V_16 * V_17 ;
struct V_122 * V_123 ;
struct V_127 * V_128 ;
struct F_19 * V_60 ;
struct V_141 * V_142 ;
struct V_131 * V_132 ;
unsigned long V_13 ;
int V_66 = 0 , V_143 , V_144 , V_3 , V_145 , V_146 ;
short V_61 , V_5 , V_147 , V_148 ;
V_17 = F_11 ( V_2 ) ;
V_144 = 1 ;
V_143 = V_3 = V_146 = V_145 = 0 ;
V_5 = V_61 = 0 ;
V_128 = NULL ;
V_105 = NULL ;
V_60 = NULL ;
V_142 = NULL ;
V_132 = NULL ;
F_4 ( & V_14 , V_13 ) ;
switch ( V_17 -> type )
{
case V_18 :
case V_24 :
V_60 = ( void * ) ( V_2 -> V_12 + ( V_149 & V_10 ) ) ;
F_2 ( V_2 , V_149 ) ;
V_144 = V_60 -> V_101 ;
if ( ! V_144 )
break;
V_61 = V_60 -> V_61 ;
V_5 = V_60 -> V_100 ;
break;
case V_29 :
V_142 = ( void * ) ( V_2 -> V_12 + ( V_150 & V_10 ) ) ;
F_2 ( V_2 , V_150 ) ;
V_132 = ( void * ) ( V_2 -> V_12 + ( ( V_142 -> V_151 + V_17 -> V_152 * sizeof( struct V_131 ) ) & V_10 ) ) ;
V_144 = V_132 -> V_101 ;
if ( ! V_144 )
break;
V_146 = V_142 -> V_146 ;
V_145 = V_142 -> V_145 ;
V_61 = V_132 -> V_61 ;
V_5 = V_132 -> V_100 ;
V_3 = V_132 -> V_135 ;
break;
}
if ( V_144 )
{
for ( V_66 = 0 ; V_66 < V_106 ; V_66 ++ )
if ( V_17 -> V_61 [ V_66 ] == V_61 )
break;
if ( V_66 == V_106 )
{
F_17 ( V_153 L_21 , V_2 -> V_51 , V_61 ) ;
V_2 -> V_136 . V_154 ++ ;
V_144 = 0 ;
}
}
if ( V_144 )
{
V_105 = V_17 -> V_105 [ V_66 ] ;
V_128 = F_33 ( V_5 + sizeof( struct V_155 ) ) ;
if ( V_128 == NULL )
{
F_17 ( V_153 L_22 , V_2 -> V_51 ) ;
V_2 -> V_136 . V_156 ++ ;
V_144 = 0 ;
}
else
F_34 ( V_128 , sizeof( struct V_155 ) ) ;
}
switch ( V_17 -> type )
{
case V_18 :
case V_24 :
if ( V_144 )
F_1 ( V_2 , V_149 + V_157 , F_35 ( V_128 , V_5 ) , V_5 ) ;
F_2 ( V_2 , V_149 ) ;
V_60 -> V_101 = 0 ;
break;
case V_29 :
if ( V_144 )
{
V_148 = V_3 + V_5 > V_146 + 1 ? V_5 - ( V_146 - V_3 + 1 ) : 0 ;
V_147 = V_5 - V_148 ;
F_1 ( V_2 , V_3 , F_35 ( V_128 , V_147 ) , V_147 ) ;
if ( V_148 )
F_1 ( V_2 , V_145 , F_35 ( V_128 , V_148 ) , V_148 ) ;
}
F_2 ( V_2 , V_150 ) ;
V_17 -> V_152 = ( V_17 -> V_152 + 1 ) % V_142 -> V_158 ;
V_132 -> V_101 = 0 ;
break;
}
if ( V_144 )
{
V_2 -> V_136 . V_159 ++ ;
V_123 = F_11 ( V_105 ) ;
(* V_123 -> V_160 )( V_128 , V_105 ) ;
}
F_5 ( & V_14 , V_13 ) ;
}
static T_2 F_36 ( int V_161 , void * V_162 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
char V_15 ;
V_2 = V_162 ;
V_17 = F_11 ( V_2 ) ;
if ( ! V_17 -> V_163 )
{
F_17 ( V_134 L_23 ,
V_2 -> V_51 , V_2 -> V_164 ) ;
return V_165 ;
}
V_15 = F_9 ( V_2 , V_17 -> type == V_29 ? V_166 : V_167 ) ;
switch ( V_15 )
{
case V_168 :
F_32 ( V_2 ) ;
break;
case V_169 :
case V_170 :
F_19 ( V_2 , V_171 , 0 , 0 , NULL , 0 , NULL , NULL ) ;
break;
case V_172 :
case V_173 :
case V_174 :
F_17 ( V_134 L_24 , V_2 -> V_51 , V_15 ) ;
break;
}
if ( V_17 -> type == V_24 )
{
V_17 -> V_22 &= ~ V_175 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
V_17 -> V_22 |= V_175 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
}
V_15 = 0 ;
F_7 ( V_2 , V_17 -> type == V_29 ? V_166 : V_167 , & V_15 , sizeof( V_15 ) ) ;
return V_176 ;
}
static void F_37 ( unsigned long V_177 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
V_2 = (struct V_1 * ) V_177 ;
V_17 = F_11 ( V_2 ) ;
if ( F_9 ( V_2 , V_149 ) )
F_32 ( V_2 ) ;
V_17 -> V_178 . V_179 = 1 ;
F_38 ( & V_17 -> V_178 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_180 V_181 ;
int V_5 , V_66 ;
short V_182 [ V_106 ] ;
V_17 = F_11 ( V_2 ) ;
V_5 = 0 ;
for( V_66 = 0 ; V_66 < V_106 ; V_66 ++ )
if ( V_17 -> V_61 [ V_66 ] )
V_182 [ V_5 ++ ] = abs ( V_17 -> V_61 [ V_66 ] ) ;
V_5 *= 2 ;
if ( V_17 -> V_108 . V_109 == V_110 )
{
for( V_66 = 0 ; V_66 < V_106 ; V_66 ++ )
if ( V_17 -> V_61 [ V_66 ] > 0 )
F_19 ( V_2 , V_112 , 0 , 0 , V_182 , V_5 , NULL , NULL ) ;
F_19 ( V_2 , V_120 , 0 , 0 , & V_17 -> V_61 [ V_66 ] , sizeof( V_17 -> V_61 [ V_66 ] ) , NULL , NULL ) ;
}
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
switch( V_17 -> type )
{
case V_18 :
F_40 ( & V_17 -> V_178 ) ;
break;
case V_24 :
F_19 ( V_2 , V_183 , 0 , 0 , & V_181 , sizeof( char ) + sizeof( short ) , NULL , NULL ) ;
V_17 -> V_22 &= ~ V_175 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
break;
case V_27 :
break;
case V_29 :
F_19 ( V_2 , V_183 , 0 , 0 , & V_181 , sizeof( struct V_180 ) , NULL , NULL ) ;
V_17 -> V_22 &= ~ V_184 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
break;
}
F_19 ( V_2 , V_185 , 0 , 0 , NULL , 0 , NULL , NULL ) ;
F_29 ( V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_122 * V_123 ;
struct V_186 V_44 ;
struct V_180 V_181 ;
int V_5 , V_66 ;
char V_15 ;
V_17 = F_11 ( V_2 ) ;
if ( ! V_17 -> V_163 )
return - V_187 ;
if ( ! V_17 -> V_188 )
return - V_187 ;
V_5 = 0 ;
for( V_66 = 0 ; V_66 < V_106 ; V_66 ++ )
if ( V_17 -> V_61 [ V_66 ] )
V_44 . V_61 [ V_5 ++ ] = abs ( V_17 -> V_61 [ V_66 ] ) ;
V_5 *= 2 ;
memcpy ( & V_44 . V_108 , & V_17 -> V_108 , sizeof( struct V_189 ) ) ;
V_5 += sizeof( struct V_189 ) ;
F_19 ( V_2 , V_185 , 0 , 0 , NULL , 0 , NULL , NULL ) ;
F_19 ( V_2 , V_126 , 0 , 0 , & V_44 , V_5 , NULL , NULL ) ;
if ( V_17 -> type == V_29 )
V_17 -> V_152 = 0 ;
F_19 ( V_2 , V_190 , 0 , 0 , NULL , 0 , NULL , NULL ) ;
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
switch( V_17 -> type )
{
case V_18 :
V_17 -> V_178 . V_179 = 1 ;
F_38 ( & V_17 -> V_178 ) ;
break;
case V_24 :
V_17 -> V_22 |= V_26 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
V_17 -> V_22 |= V_175 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
V_15 = 0 ;
F_7 ( V_2 , V_167 , & V_15 , sizeof( V_15 ) ) ;
V_181 . V_13 = V_168 | V_170 | V_169 ;
F_19 ( V_2 , V_183 , 0 , 0 , & V_181 , sizeof( char ) + sizeof( short ) , NULL , NULL ) ;
break;
case V_27 :
break;
case V_29 :
V_17 -> V_22 |= V_184 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
V_15 = 0 ;
F_7 ( V_2 , V_166 , & V_15 , sizeof( V_15 ) ) ;
V_181 . V_13 = V_168 | V_170 | V_169 ;
V_181 . V_164 = V_2 -> V_164 ;
F_19 ( V_2 , V_183 , 0 , 0 , & V_181 , sizeof( struct V_180 ) , NULL , NULL ) ;
break;
}
if ( V_17 -> V_108 . V_109 == V_118 )
{
V_15 = V_191 ;
F_19 ( V_2 , V_192 , 0 , 0 , & V_15 , sizeof( V_15 ) , NULL , NULL ) ;
}
else
{
F_19 ( V_2 , V_119 , 0 , 0 , V_44 . V_61 , V_5 - sizeof( struct V_189 ) , NULL , NULL ) ;
for( V_66 = 0 ; V_66 < V_106 ; V_66 ++ )
if ( V_17 -> V_61 [ V_66 ] > 0 )
F_19 ( V_2 , V_111 , 0 , 0 , & V_17 -> V_61 [ V_66 ] , 2 * sizeof( V_17 -> V_61 [ V_66 ] ) , NULL , NULL ) ;
}
for( V_66 = 0 ; V_66 < V_106 ; V_66 ++ )
if ( V_17 -> V_61 [ V_66 ] )
{
V_123 = F_11 ( V_17 -> V_105 [ V_66 ] ) ;
if ( V_123 -> V_188 )
F_19 ( V_2 , V_126 , abs ( V_17 -> V_61 [ V_66 ] ) , 0 , & V_123 -> V_108 , sizeof( struct V_124 ) , NULL , NULL ) ;
}
F_42 ( V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_189 T_3 * V_193 , int V_121 )
{
struct V_16 * V_17 ;
struct V_186 V_44 ;
int V_66 ;
short V_130 ;
if ( V_2 -> type == 0xFFFF )
return - V_194 ;
V_17 = F_11 ( V_2 ) ;
if ( ! V_121 )
{
if ( F_22 ( V_2 ) )
return - V_195 ;
if( F_44 ( & V_44 . V_108 , V_193 , sizeof( struct V_189 ) ) )
return - V_196 ;
if ( V_44 . V_108 . V_109 & ~ V_110 )
return - V_52 ;
if ( V_44 . V_108 . V_13 & ~ V_197 )
return - V_52 ;
if ( ( V_44 . V_108 . V_198 < 0 ) ||
( ( V_44 . V_108 . V_198 > 128 ) && ( V_17 -> type != V_29 ) ) )
return - V_52 ;
if ( V_44 . V_108 . V_199 & ~ ( V_200 | V_201 ) )
return - V_52 ;
if ( ( V_44 . V_108 . V_117 < 0 ) || ( V_44 . V_108 . V_117 > V_202 ) )
return - V_52 ;
if ( ( V_44 . V_108 . V_203 < 5 ) || ( V_44 . V_108 . V_203 > 30 ) )
return - V_52 ;
if ( ( V_44 . V_108 . V_204 < 5 ) || ( V_44 . V_108 . V_204 > 30 ) )
return - V_52 ;
if ( ( V_44 . V_108 . V_205 < 1 ) || ( V_44 . V_108 . V_205 > 255 ) )
return - V_52 ;
if ( ( V_44 . V_108 . V_206 < 1 ) || ( V_44 . V_108 . V_206 > 10 ) )
return - V_52 ;
if ( ( V_44 . V_108 . V_207 < 1 ) || ( V_44 . V_108 . V_207 > 10 ) )
return - V_52 ;
memcpy ( & V_17 -> V_108 , & V_44 . V_108 , sizeof( struct V_189 ) ) ;
V_17 -> V_108 . V_13 |= V_208 ;
if ( V_17 -> type == V_29 )
V_17 -> V_108 . V_13 |= V_209 ;
if ( V_2 -> V_117 != V_17 -> V_108 . V_117 )
{
V_2 -> V_117 = V_17 -> V_108 . V_117 ;
for( V_66 = 0 ; V_66 < V_106 ; V_66 ++ )
if ( V_17 -> V_105 [ V_66 ] )
V_17 -> V_105 [ V_66 ] -> V_117 = V_17 -> V_108 . V_117 ;
}
V_17 -> V_108 . V_117 += sizeof( struct V_155 ) ;
if ( ! V_17 -> V_188 )
F_13 ( V_2 ) ;
V_17 -> V_188 = 1 ;
}
else
{
if ( F_22 ( V_2 ) )
{
V_130 = sizeof( V_44 ) ;
if ( F_19 ( V_2 , V_125 , 0 , 0 , NULL , 0 , & V_44 , & V_130 ) != V_103 )
return - V_47 ;
}
else
if ( V_17 -> V_188 )
memcpy ( & V_44 . V_108 , & V_17 -> V_108 , sizeof( struct V_189 ) ) ;
else
memset ( & V_44 . V_108 , 0 , sizeof( struct V_189 ) ) ;
memcpy ( & V_17 -> V_108 , & V_44 . V_108 , sizeof( struct V_189 ) ) ;
V_44 . V_108 . V_13 &= V_197 ;
V_44 . V_108 . V_117 -= V_44 . V_108 . V_117 > sizeof( struct V_155 ) ? sizeof( struct V_155 ) : V_44 . V_108 . V_117 ;
return F_45 ( V_193 , & V_44 . V_108 , sizeof( struct V_189 ) ) ? - V_196 : 0 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_210 T_3 * V_211 , int V_212 )
{
struct V_210 V_213 ;
char * V_6 ;
if( F_44 ( & V_213 , V_211 , sizeof( V_213 ) ) )
return - V_196 ;
if ( V_212 )
{
V_6 = F_47 ( V_213 . V_5 , V_214 ) ;
if ( ! V_6 )
return - V_215 ;
F_3 ( V_2 , V_213 . V_3 , V_6 , V_213 . V_5 ) ;
if( F_45 ( V_213 . V_44 , V_6 , V_213 . V_5 ) )
{
F_48 ( V_6 ) ;
return - V_196 ;
}
F_48 ( V_6 ) ;
}
else
{
V_6 = F_49 ( V_213 . V_44 , V_213 . V_5 ) ;
if ( F_50 ( V_6 ) )
return F_51 ( V_6 ) ;
F_7 ( V_2 , V_213 . V_3 , V_6 , V_213 . V_5 ) ;
F_48 ( V_6 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_186 V_44 ;
int V_66 , V_5 ;
V_17 = F_11 ( V_2 ) ;
V_5 = 0 ;
for( V_66 = 0 ; V_66 < V_106 ; V_66 ++ )
if ( V_17 -> V_61 [ V_66 ] )
V_44 . V_61 [ V_5 ++ ] = V_17 -> V_61 [ V_66 ] ;
V_5 *= 2 ;
memcpy ( & V_44 , & V_17 -> V_108 , sizeof( struct V_189 ) ) ;
V_5 += sizeof( struct V_189 ) ;
F_19 ( V_2 , V_185 , 0 , 0 , NULL , 0 , NULL , NULL ) ;
F_19 ( V_2 , V_126 , 0 , 0 , & V_44 , V_5 , NULL , NULL ) ;
F_19 ( V_2 , V_190 , 0 , 0 , NULL , 0 , NULL , NULL ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_42 * V_43 , int V_60 )
{
struct V_16 * V_17 ;
if( ! F_53 ( V_216 ) )
return - V_187 ;
V_17 = F_11 ( V_2 ) ;
if ( ! V_17 -> V_163 )
return - V_52 ;
switch ( V_60 )
{
case V_217 :
case V_218 :
return F_43 ( V_2 , V_43 -> V_219 , V_60 == V_217 ) ;
case V_220 :
V_43 -> V_221 = V_17 -> type ;
break;
case V_222 :
return F_16 ( V_2 , V_43 ) ;
case V_223 :
if ( V_17 -> V_188 )
return - V_224 ;
switch ( V_43 -> V_221 )
{
case V_133 :
V_2 -> type = V_43 -> V_221 ;
break;
default:
return - V_225 ;
}
break;
case V_226 :
F_8 ( V_2 ) ;
break;
case V_227 :
case V_228 :
if( ! F_53 ( V_229 ) )
return - V_187 ;
return F_46 ( V_2 , V_43 -> V_219 , V_60 == V_228 ) ;
case V_230 :
F_13 ( V_2 ) ;
break;
case V_231 :
F_10 ( V_2 ) ;
break;
default:
return - V_232 ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , int V_233 )
{
struct V_16 * V_17 ;
V_17 = F_11 ( V_2 ) ;
if ( F_22 ( V_2 ) )
return - V_195 ;
return - V_232 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_234 * V_235 )
{
struct V_16 * V_17 ;
int V_66 ;
char V_15 ;
unsigned V_7 ;
int V_236 = - V_52 ;
V_17 = F_11 ( V_2 ) ;
if ( V_17 -> V_163 )
return - V_52 ;
for( V_66 = 0 ; V_66 < F_56 ( V_237 ) ; V_66 ++ )
if ( V_237 [ V_66 ] == V_235 -> V_20 )
break;
if ( V_66 == F_56 ( V_237 ) )
return - V_52 ;
if ( ! F_57 ( V_235 -> V_20 , V_238 , V_2 -> V_51 ) ) {
F_17 ( V_134 L_25 , V_2 -> V_20 ) ;
return - V_52 ;
}
V_7 = V_235 -> V_20 ;
V_17 -> type = V_239 ;
V_17 -> V_22 = 0 ;
for( V_66 = 1 ; V_66 < V_238 ; V_66 ++ )
if ( F_58 ( V_7 + V_66 ) != 0xFF )
break;
if ( V_66 == V_238 ) {
F_12 ( V_23 , V_7 + V_25 ) ;
if ( ( F_58 ( V_7 + V_240 ) & 0x0F ) == 0x08 ) {
F_12 ( V_175 , V_7 + V_21 ) ;
if ( ( F_58 ( V_7 + V_240 ) & 0x0F ) == 0x0C ) {
F_12 ( V_23 , V_7 + V_21 ) ;
V_17 -> type = V_24 ;
goto V_241;
}
}
}
for( V_15 = F_58 ( V_7 ) , V_66 = 0 ; V_66 < V_238 ; V_66 ++ )
if ( F_58 ( V_7 + V_66 ) != V_15 )
break;
if ( V_66 == V_238 ) {
F_12 ( V_23 , V_7 + V_21 ) ;
if ( ( F_58 ( V_7 + V_240 ) & 0x7E ) == 0x30 ) {
F_12 ( V_242 , V_7 + V_21 ) ;
if ( ( F_58 ( V_7 + V_240 ) & 0x7E ) == 0x32 ) {
F_12 ( V_23 , V_7 + V_21 ) ;
V_17 -> type = V_27 ;
goto V_241;
}
}
}
F_12 ( V_23 , V_7 + V_21 ) ;
if ( ( F_58 ( V_7 + V_243 ) & 0x3F ) == 0x00 ) {
F_12 ( V_184 , V_7 + V_21 ) ;
if ( ( F_58 ( V_7 + V_243 ) & 0x3F ) == 0x10 ) {
F_12 ( V_23 , V_7 + V_21 ) ;
V_17 -> type = V_29 ;
goto V_241;
}
}
F_12 ( V_19 , V_7 + V_21 ) ;
if ( F_58 ( V_7 + V_240 ) == 0x40 ) {
F_12 ( V_31 , V_7 + V_21 ) ;
if ( F_58 ( V_7 + V_240 ) == 0x40 ) {
F_12 ( V_244 , V_7 + V_21 ) ;
if ( F_58 ( V_7 + V_240 ) == 0x44 ) {
F_12 ( V_31 , V_7 + V_21 ) ;
V_17 -> type = V_18 ;
goto V_241;
}
}
}
F_17 ( V_153 L_26 , V_2 -> V_51 ) ;
V_236 = - V_107 ;
goto V_245;
V_241:
switch( V_7 ) {
case 0x270 :
case 0x280 :
case 0x380 :
case 0x390 :
if ( V_17 -> type != V_29 && V_17 -> type != V_27 )
goto V_245;
}
switch ( V_235 -> V_164 ) {
case 2 :
if ( V_17 -> type != V_24 )
goto V_245;
break;
case 10 :
case 11 :
case 12 :
case 15 :
case 4 :
if ( V_17 -> type != V_29 && V_17 -> type != V_27 )
goto V_245;
break;
case 3 :
case 5 :
case 7 :
if ( V_17 -> type == V_18 )
goto V_245;
break;
default:
goto V_245;
}
V_236 = - V_246 ;
if ( F_59 ( V_2 -> V_164 , F_36 , 0 , V_2 -> V_51 , V_2 ) )
goto V_245;
if ( V_17 -> type == V_27 ) {
switch( V_2 -> V_164 ) {
case 3 :
V_17 -> V_22 = V_247 ;
break;
case 4 :
V_17 -> V_22 = V_248 ;
break;
case 5 :
V_17 -> V_22 = V_249 ;
break;
case 7 :
V_17 -> V_22 = V_250 ;
break;
case 10 :
V_17 -> V_22 = V_251 ;
break;
case 11 :
V_17 -> V_22 = V_252 ;
break;
case 12 :
V_17 -> V_22 = V_253 ;
break;
case 15 :
V_17 -> V_22 = V_254 ;
break;
}
}
for( V_66 = 0 ; V_66 < F_56 ( V_255 ) ; V_66 ++ )
if ( V_255 [ V_66 ] == V_235 -> V_12 )
break;
V_236 = - V_52 ;
if ( V_66 == F_56 ( V_255 ) )
goto V_256;
if ( V_17 -> type == V_18 && ( V_235 -> V_12 & 0xF000 ) >> 12 == 0x0E )
goto V_256;
if ( V_17 -> type != V_27 && V_235 -> V_12 >> 16 == 0x0B )
goto V_256;
if ( V_17 -> type == V_27 && V_235 -> V_12 >> 16 == 0x0D )
goto V_256;
V_15 = V_17 -> type != V_29 ? V_257 : 0 ;
V_15 |= ( V_235 -> V_12 & 0xF000 ) >> ( 12 + ( V_17 -> type == V_29 ? 1 : 0 ) ) ;
switch( V_17 -> type ) {
case V_18 :
case V_24 :
switch ( V_235 -> V_12 >> 16 ) {
case 0x0A :
V_15 |= V_258 ;
break;
case 0x0C :
V_15 |= V_259 ;
break;
case 0x0D :
V_15 |= V_260 ;
break;
case 0x0E :
V_15 |= V_261 ;
break;
}
break;
case V_27 :
switch ( V_235 -> V_12 >> 16 ) {
case 0x0A :
V_15 |= V_262 ;
break;
case 0x0B :
V_15 |= V_263 ;
break;
case 0x0C :
V_15 |= V_264 ;
break;
case 0x0E :
V_15 |= V_265 ;
break;
}
break;
case V_29 :
switch ( V_235 -> V_12 >> 16 ) {
case 0x0A :
V_15 |= V_266 ;
break;
case 0x0C :
V_15 |= V_267 ;
break;
case 0x0D :
V_15 |= V_268 ;
break;
case 0x0E :
V_15 |= V_269 ;
break;
}
break;
}
F_12 ( V_15 , V_7 + V_270 ) ;
switch( V_17 -> type )
{
case V_24 :
V_17 -> V_22 = V_26 ;
break;
case V_27 :
V_17 -> V_22 |= V_271 ;
break;
case V_29 :
V_17 -> V_22 = V_271 ;
break;
}
F_12 ( V_17 -> V_22 , V_7 + V_21 ) ;
V_2 -> V_164 = V_235 -> V_164 ;
V_2 -> V_20 = V_7 ;
V_2 -> V_12 = V_235 -> V_12 ;
V_2 -> V_272 = V_2 -> V_12 + 0x2000 ;
V_17 -> V_163 = 1 ;
return 0 ;
V_256:
F_60 ( V_235 -> V_164 , V_2 ) ;
V_245:
F_61 ( V_7 , V_238 ) ;
return V_236 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_11 ( V_2 ) ;
F_63 ( V_2 ) ;
V_2 -> V_273 = & V_274 ;
V_2 -> V_13 = 0 ;
V_2 -> type = 0xFFFF ;
V_2 -> V_275 = 0 ;
V_2 -> V_276 = 0 ;
V_2 -> V_117 = V_202 ;
V_17 -> V_277 = F_21 ;
V_17 -> V_278 = F_23 ;
V_17 -> V_279 = F_24 ;
V_17 -> V_280 = F_26 ;
V_17 -> V_124 = F_27 ;
F_64 ( & V_17 -> V_178 ) ;
V_17 -> V_178 . V_179 = 1 ;
V_17 -> V_178 . V_44 = ( unsigned long ) V_2 ;
V_17 -> V_178 . V_281 = F_37 ;
}
static int T_4 F_65 ( void )
{
int V_236 ;
F_17 ( L_27 , V_282 ) ;
V_283 = F_66 ( sizeof( struct V_16 ) , L_28 , F_62 ) ;
if ( ! V_283 )
return - V_215 ;
V_236 = F_67 ( V_283 ) ;
if ( V_236 )
F_68 ( V_283 ) ;
return V_236 ;
}
static void T_5 F_69 ( void )
{
struct V_16 * V_17 = F_11 ( V_283 ) ;
F_70 ( V_283 ) ;
if ( V_17 -> V_163 ) {
F_60 ( V_283 -> V_164 , V_283 ) ;
F_61 ( V_283 -> V_20 , V_238 ) ;
}
F_71 ( & V_17 -> V_178 ) ;
F_68 ( V_283 ) ;
}
