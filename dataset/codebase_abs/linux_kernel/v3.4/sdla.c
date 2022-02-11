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
F_19 ( V_2 , L_2 ) ;
if ( * V_22 & V_69 )
F_19 ( V_2 , L_3 ) ;
break;
case V_70 :
F_19 ( V_2 , L_4 ) ;
break;
case V_71 :
F_19 ( V_2 , L_5 ) ;
break;
case V_72 :
F_19 ( V_2 , L_6 ) ;
V_5 /= sizeof( struct V_63 ) ;
for( V_64 = V_44 , V_66 = 0 ; V_66 < V_5 ; V_66 ++ , V_64 ++ )
{
if ( V_64 -> V_13 & V_73 )
V_22 = L_7 ;
else if ( V_64 -> V_13 & V_74 )
V_22 = L_8 ;
else if ( V_64 -> V_13 & V_75 )
V_22 = L_9 ;
else
{
sprintf ( line , L_10 , V_64 -> V_13 ) ;
V_22 = line ;
}
F_19 ( V_2 , L_11 ,
V_64 -> V_61 , V_22 ) ;
}
break;
case V_76 :
F_19 ( V_2 , L_12 ) ;
V_5 /= sizeof( short ) ;
for( V_65 = V_44 , V_66 = 0 ; V_66 < V_5 ; V_66 ++ , V_65 ++ )
F_20 ( L_13 , * V_65 ) ;
F_20 ( L_14 ) ;
break;
case V_77 :
F_21 ( V_2 , L_15 ) ;
break;
case V_78 :
F_19 ( V_2 , L_16 ,
V_5 ) ;
break;
case V_79 :
F_19 ( V_2 , L_17 ,
V_5 ) ;
break;
case V_80 :
case V_81 :
case V_82 :
case V_83 :
if ( V_60 == V_84 )
break;
default:
F_22 ( V_2 , L_18 ,
V_60 , V_62 ) ;
break;
}
}
static int F_23 ( struct V_1 * V_2 , int V_60 , short V_61 , short V_13 ,
void * V_85 , short V_86 , void * V_87 , short * V_88 )
{
static struct V_89 V_90 ;
struct V_16 * V_17 ;
struct F_23 * V_91 ;
unsigned long V_92 ;
unsigned long V_34 ;
int V_62 , V_93 , V_5 ;
long V_94 ;
V_17 = F_11 ( V_2 ) ;
V_94 = V_17 -> type == V_29 ? V_95 : V_96 ;
V_91 = (struct F_23 * ) ( V_2 -> V_12 + ( V_94 & V_10 ) ) ;
V_62 = 0 ;
V_5 = 0 ;
V_34 = V_41 + V_45 ;
F_4 ( & V_14 , V_92 ) ;
F_2 ( V_2 , V_94 ) ;
V_91 -> V_60 = V_60 ;
V_91 -> V_61 = V_61 ;
V_91 -> V_13 = V_13 ;
if ( V_85 )
memcpy ( V_91 -> V_44 , V_85 , V_86 ) ;
V_91 -> V_97 = V_86 ;
V_91 -> V_98 = 1 ;
F_5 ( & V_14 , V_92 ) ;
V_93 = 1 ;
V_5 = 0 ;
while ( V_93 && F_24 ( V_41 , V_34 ) )
{
if ( V_93 ++ % 3 )
{
F_4 ( & V_14 , V_92 ) ;
F_2 ( V_2 , V_94 ) ;
V_93 = ( ( volatile int ) ( V_91 -> V_98 ) ) ;
F_5 ( & V_14 , V_92 ) ;
}
}
if ( ! V_93 )
{
F_4 ( & V_14 , V_92 ) ;
F_2 ( V_2 , V_94 ) ;
V_62 = V_91 -> V_99 ;
V_5 = V_91 -> V_97 ;
if ( V_87 && V_88 )
{
* V_88 = * V_88 >= V_5 ? V_5 : * V_88 ;
if ( * V_88 )
memcpy ( V_87 , V_91 -> V_44 , * V_88 ) ;
}
if ( V_62 )
memcpy ( & V_90 , V_91 -> V_44 , V_5 > sizeof( V_90 ) ? sizeof( V_90 ) : V_5 ) ;
F_5 ( & V_14 , V_92 ) ;
}
else
V_62 = V_77 ;
if ( V_62 != V_100 )
F_18 ( V_2 , V_60 , V_61 , V_62 , V_5 , & V_90 ) ;
return V_62 ;
}
static int F_25 ( struct V_1 * V_101 , struct V_1 * V_102 )
{
struct V_16 * V_17 ;
int V_66 ;
V_17 = F_11 ( V_101 ) ;
for( V_66 = 0 ; V_66 < V_103 ; V_66 ++ )
if ( V_17 -> V_102 [ V_66 ] == V_102 )
break;
if ( V_66 == V_103 )
return - V_104 ;
V_17 -> V_61 [ V_66 ] = abs ( V_17 -> V_61 [ V_66 ] ) ;
if ( F_26 ( V_101 ) && ( V_17 -> V_105 . V_106 == V_107 ) )
F_23 ( V_101 , V_108 , 0 , 0 , & V_17 -> V_61 [ V_66 ] , sizeof( short ) , NULL , NULL ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_101 , struct V_1 * V_102 )
{
struct V_16 * V_17 ;
int V_66 ;
V_17 = F_11 ( V_101 ) ;
for( V_66 = 0 ; V_66 < V_103 ; V_66 ++ )
if ( V_17 -> V_102 [ V_66 ] == V_102 )
break;
if ( V_66 == V_103 )
return - V_104 ;
V_17 -> V_61 [ V_66 ] = - abs ( V_17 -> V_61 [ V_66 ] ) ;
if ( F_26 ( V_101 ) && ( V_17 -> V_105 . V_106 == V_107 ) )
F_23 ( V_101 , V_109 , 0 , 0 , & V_17 -> V_61 [ V_66 ] , sizeof( short ) , NULL , NULL ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_101 , struct V_1 * V_102 )
{
struct V_16 * V_17 ;
int V_66 ;
if ( V_102 -> type != V_110 )
return - V_52 ;
V_17 = F_11 ( V_101 ) ;
for( V_66 = 0 ; V_66 < V_103 ; V_66 ++ )
{
if ( ! V_17 -> V_102 [ V_66 ] )
break;
if ( abs ( V_17 -> V_61 [ V_66 ] ) == * ( short * ) ( V_102 -> V_111 ) )
return - V_112 ;
}
if ( V_66 == V_103 )
return - V_113 ;
V_17 -> V_102 [ V_66 ] = V_102 ;
V_17 -> V_61 [ V_66 ] = - * ( short * ) ( V_102 -> V_111 ) ;
V_102 -> V_114 = V_101 -> V_114 ;
if ( F_26 ( V_101 ) ) {
if ( V_17 -> V_105 . V_106 == V_115 )
F_29 ( V_101 ) ;
else
F_23 ( V_101 , V_116 , 0 , 0 , V_102 -> V_111 , sizeof( short ) , NULL , NULL ) ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_101 , struct V_1 * V_102 )
{
struct V_16 * V_17 ;
int V_66 ;
V_17 = F_11 ( V_101 ) ;
for( V_66 = 0 ; V_66 < V_103 ; V_66 ++ )
if ( V_17 -> V_102 [ V_66 ] == V_102 )
break;
if ( V_66 == V_103 )
return - V_104 ;
V_17 -> V_102 [ V_66 ] = NULL ;
V_17 -> V_61 [ V_66 ] = 0 ;
if ( F_26 ( V_101 ) ) {
if ( V_17 -> V_105 . V_106 == V_115 )
F_29 ( V_101 ) ;
else
F_23 ( V_101 , V_117 , 0 , 0 , V_102 -> V_111 , sizeof( short ) , NULL , NULL ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_101 , struct V_1 * V_102 , int V_118 )
{
struct V_16 * V_17 ;
struct V_119 * V_120 ;
int V_66 ;
short V_5 , V_62 ;
V_17 = F_11 ( V_101 ) ;
for( V_66 = 0 ; V_66 < V_103 ; V_66 ++ )
if ( V_17 -> V_102 [ V_66 ] == V_102 )
break;
if ( V_66 == V_103 )
return - V_104 ;
V_120 = F_11 ( V_102 ) ;
V_62 = V_100 ;
V_5 = sizeof( struct V_121 ) ;
if ( F_26 ( V_101 ) ) {
if ( V_118 )
V_62 = F_23 ( V_101 , V_122 , abs ( V_17 -> V_61 [ V_66 ] ) , 0 ,
NULL , 0 , & V_120 -> V_105 , & V_5 ) ;
else
V_62 = F_23 ( V_101 , V_123 , abs ( V_17 -> V_61 [ V_66 ] ) , 0 ,
& V_120 -> V_105 , sizeof( struct V_121 ) - 4 * sizeof( short ) , NULL , NULL ) ;
}
return V_62 == V_100 ? 0 : - V_47 ;
}
static T_1 F_32 ( struct V_124 * V_125 ,
struct V_1 * V_2 )
{
struct V_16 * V_17 ;
int V_62 , V_3 , V_126 , V_66 ;
short V_127 ;
unsigned long V_13 ;
struct V_128 * V_129 ;
V_17 = F_11 ( V_2 ) ;
V_62 = 0 ;
V_126 = 1 ;
F_33 ( V_2 ) ;
V_126 = 1 ;
switch ( V_2 -> type )
{
case V_130 :
if ( V_125 -> V_2 -> type != V_110 )
{
F_34 ( V_2 , L_19 ,
V_125 -> V_2 -> type ) ;
V_126 = 0 ;
}
break;
default:
F_34 ( V_2 , L_20 ,
V_2 -> type ) ;
V_126 = 0 ;
break;
}
if ( V_126 )
{
switch ( V_17 -> type )
{
case V_18 :
case V_24 :
V_62 = F_23 ( V_2 , V_84 , * ( short * ) ( V_125 -> V_2 -> V_111 ) , 0 , V_125 -> V_44 , V_125 -> V_5 , NULL , NULL ) ;
break;
case V_29 :
V_127 = sizeof( V_3 ) ;
V_62 = F_23 ( V_2 , V_84 , * ( short * ) ( V_125 -> V_2 -> V_111 ) , 0 , NULL , V_125 -> V_5 , & V_3 , & V_127 ) ;
if ( V_62 == V_100 )
{
F_4 ( & V_14 , V_13 ) ;
F_2 ( V_2 , V_3 ) ;
V_129 = ( void * ) ( ( ( int ) V_2 -> V_12 ) + ( V_3 & V_10 ) ) ;
F_6 ( V_2 , V_129 -> V_131 , V_125 -> V_44 , V_125 -> V_5 ) ;
F_2 ( V_2 , V_3 ) ;
V_129 -> V_98 = 1 ;
F_5 ( & V_14 , V_13 ) ;
}
break;
}
switch ( V_62 )
{
case V_100 :
V_2 -> V_132 . V_133 ++ ;
break;
case V_82 :
case V_78 :
case V_83 :
V_2 -> V_132 . V_134 ++ ;
break;
default:
V_2 -> V_132 . V_135 ++ ;
break;
}
}
F_35 ( V_2 ) ;
for( V_66 = 0 ; V_66 < V_103 ; V_66 ++ )
{
if( V_17 -> V_102 [ V_66 ] != NULL )
F_35 ( V_17 -> V_102 [ V_66 ] ) ;
}
F_36 ( V_125 ) ;
return V_136 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_1 * V_102 ;
struct V_16 * V_17 ;
struct V_119 * V_120 ;
struct V_124 * V_125 ;
struct F_23 * V_60 ;
struct V_137 * V_138 ;
struct V_128 * V_129 ;
unsigned long V_13 ;
int V_66 = 0 , V_139 , V_140 , V_3 , V_141 , V_142 ;
short V_61 , V_5 , V_143 , V_144 ;
V_17 = F_11 ( V_2 ) ;
V_140 = 1 ;
V_139 = V_3 = V_142 = V_141 = 0 ;
V_5 = V_61 = 0 ;
V_125 = NULL ;
V_102 = NULL ;
V_60 = NULL ;
V_138 = NULL ;
V_129 = NULL ;
F_4 ( & V_14 , V_13 ) ;
switch ( V_17 -> type )
{
case V_18 :
case V_24 :
V_60 = ( void * ) ( V_2 -> V_12 + ( V_145 & V_10 ) ) ;
F_2 ( V_2 , V_145 ) ;
V_140 = V_60 -> V_98 ;
if ( ! V_140 )
break;
V_61 = V_60 -> V_61 ;
V_5 = V_60 -> V_97 ;
break;
case V_29 :
V_138 = ( void * ) ( V_2 -> V_12 + ( V_146 & V_10 ) ) ;
F_2 ( V_2 , V_146 ) ;
V_129 = ( void * ) ( V_2 -> V_12 + ( ( V_138 -> V_147 + V_17 -> V_148 * sizeof( struct V_128 ) ) & V_10 ) ) ;
V_140 = V_129 -> V_98 ;
if ( ! V_140 )
break;
V_142 = V_138 -> V_142 ;
V_141 = V_138 -> V_141 ;
V_61 = V_129 -> V_61 ;
V_5 = V_129 -> V_97 ;
V_3 = V_129 -> V_131 ;
break;
}
if ( V_140 )
{
for ( V_66 = 0 ; V_66 < V_103 ; V_66 ++ )
if ( V_17 -> V_61 [ V_66 ] == V_61 )
break;
if ( V_66 == V_103 )
{
F_38 ( V_2 , L_21 ,
V_61 ) ;
V_2 -> V_132 . V_149 ++ ;
V_140 = 0 ;
}
}
if ( V_140 )
{
V_102 = V_17 -> V_102 [ V_66 ] ;
V_125 = F_39 ( V_5 + sizeof( struct V_150 ) ) ;
if ( V_125 == NULL )
{
F_38 ( V_2 , L_22 ) ;
V_2 -> V_132 . V_151 ++ ;
V_140 = 0 ;
}
else
F_40 ( V_125 , sizeof( struct V_150 ) ) ;
}
switch ( V_17 -> type )
{
case V_18 :
case V_24 :
if ( V_140 )
F_1 ( V_2 , V_145 + V_152 , F_41 ( V_125 , V_5 ) , V_5 ) ;
F_2 ( V_2 , V_145 ) ;
V_60 -> V_98 = 0 ;
break;
case V_29 :
if ( V_140 )
{
V_144 = V_3 + V_5 > V_142 + 1 ? V_5 - ( V_142 - V_3 + 1 ) : 0 ;
V_143 = V_5 - V_144 ;
F_1 ( V_2 , V_3 , F_41 ( V_125 , V_143 ) , V_143 ) ;
if ( V_144 )
F_1 ( V_2 , V_141 , F_41 ( V_125 , V_144 ) , V_144 ) ;
}
F_2 ( V_2 , V_146 ) ;
V_17 -> V_148 = ( V_17 -> V_148 + 1 ) % V_138 -> V_153 ;
V_129 -> V_98 = 0 ;
break;
}
if ( V_140 )
{
V_2 -> V_132 . V_154 ++ ;
V_120 = F_11 ( V_102 ) ;
(* V_120 -> V_155 )( V_125 , V_102 ) ;
}
F_5 ( & V_14 , V_13 ) ;
}
static T_2 F_42 ( int V_156 , void * V_157 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
char V_15 ;
V_2 = V_157 ;
V_17 = F_11 ( V_2 ) ;
if ( ! V_17 -> V_158 )
{
F_34 ( V_2 , L_23 , V_2 -> V_159 ) ;
return V_160 ;
}
V_15 = F_9 ( V_2 , V_17 -> type == V_29 ? V_161 : V_162 ) ;
switch ( V_15 )
{
case V_163 :
F_37 ( V_2 ) ;
break;
case V_164 :
case V_165 :
F_23 ( V_2 , V_166 , 0 , 0 , NULL , 0 , NULL , NULL ) ;
break;
case V_167 :
case V_168 :
case V_169 :
F_34 ( V_2 , L_24 , V_15 ) ;
break;
}
if ( V_17 -> type == V_24 )
{
V_17 -> V_22 &= ~ V_170 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
V_17 -> V_22 |= V_170 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
}
V_15 = 0 ;
F_7 ( V_2 , V_17 -> type == V_29 ? V_161 : V_162 , & V_15 , sizeof( V_15 ) ) ;
return V_171 ;
}
static void F_43 ( unsigned long V_172 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
V_2 = (struct V_1 * ) V_172 ;
V_17 = F_11 ( V_2 ) ;
if ( F_9 ( V_2 , V_145 ) )
F_37 ( V_2 ) ;
V_17 -> V_173 . V_174 = 1 ;
F_44 ( & V_17 -> V_173 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_175 V_176 ;
int V_5 , V_66 ;
short V_177 [ V_103 ] ;
V_17 = F_11 ( V_2 ) ;
V_5 = 0 ;
for( V_66 = 0 ; V_66 < V_103 ; V_66 ++ )
if ( V_17 -> V_61 [ V_66 ] )
V_177 [ V_5 ++ ] = abs ( V_17 -> V_61 [ V_66 ] ) ;
V_5 *= 2 ;
if ( V_17 -> V_105 . V_106 == V_107 )
{
for( V_66 = 0 ; V_66 < V_103 ; V_66 ++ )
if ( V_17 -> V_61 [ V_66 ] > 0 )
F_23 ( V_2 , V_109 , 0 , 0 , V_177 , V_5 , NULL , NULL ) ;
F_23 ( V_2 , V_117 , 0 , 0 , & V_17 -> V_61 [ V_66 ] , sizeof( V_17 -> V_61 [ V_66 ] ) , NULL , NULL ) ;
}
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
switch( V_17 -> type )
{
case V_18 :
F_46 ( & V_17 -> V_173 ) ;
break;
case V_24 :
F_23 ( V_2 , V_178 , 0 , 0 , & V_176 , sizeof( char ) + sizeof( short ) , NULL , NULL ) ;
V_17 -> V_22 &= ~ V_170 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
break;
case V_27 :
break;
case V_29 :
F_23 ( V_2 , V_178 , 0 , 0 , & V_176 , sizeof( struct V_175 ) , NULL , NULL ) ;
V_17 -> V_22 &= ~ V_179 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
break;
}
F_23 ( V_2 , V_180 , 0 , 0 , NULL , 0 , NULL , NULL ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_119 * V_120 ;
struct V_181 V_44 ;
struct V_175 V_176 ;
int V_5 , V_66 ;
char V_15 ;
V_17 = F_11 ( V_2 ) ;
if ( ! V_17 -> V_158 )
return - V_182 ;
if ( ! V_17 -> V_183 )
return - V_182 ;
V_5 = 0 ;
for( V_66 = 0 ; V_66 < V_103 ; V_66 ++ )
if ( V_17 -> V_61 [ V_66 ] )
V_44 . V_61 [ V_5 ++ ] = abs ( V_17 -> V_61 [ V_66 ] ) ;
V_5 *= 2 ;
memcpy ( & V_44 . V_105 , & V_17 -> V_105 , sizeof( struct V_184 ) ) ;
V_5 += sizeof( struct V_184 ) ;
F_23 ( V_2 , V_180 , 0 , 0 , NULL , 0 , NULL , NULL ) ;
F_23 ( V_2 , V_123 , 0 , 0 , & V_44 , V_5 , NULL , NULL ) ;
if ( V_17 -> type == V_29 )
V_17 -> V_148 = 0 ;
F_23 ( V_2 , V_185 , 0 , 0 , NULL , 0 , NULL , NULL ) ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
switch( V_17 -> type )
{
case V_18 :
V_17 -> V_173 . V_174 = 1 ;
F_44 ( & V_17 -> V_173 ) ;
break;
case V_24 :
V_17 -> V_22 |= V_26 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
V_17 -> V_22 |= V_170 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
V_15 = 0 ;
F_7 ( V_2 , V_162 , & V_15 , sizeof( V_15 ) ) ;
V_176 . V_13 = V_163 | V_165 | V_164 ;
F_23 ( V_2 , V_178 , 0 , 0 , & V_176 , sizeof( char ) + sizeof( short ) , NULL , NULL ) ;
break;
case V_27 :
break;
case V_29 :
V_17 -> V_22 |= V_179 ;
F_12 ( V_17 -> V_22 , V_2 -> V_20 + V_21 ) ;
V_15 = 0 ;
F_7 ( V_2 , V_161 , & V_15 , sizeof( V_15 ) ) ;
V_176 . V_13 = V_163 | V_165 | V_164 ;
V_176 . V_159 = V_2 -> V_159 ;
F_23 ( V_2 , V_178 , 0 , 0 , & V_176 , sizeof( struct V_175 ) , NULL , NULL ) ;
break;
}
if ( V_17 -> V_105 . V_106 == V_115 )
{
V_15 = V_186 ;
F_23 ( V_2 , V_187 , 0 , 0 , & V_15 , sizeof( V_15 ) , NULL , NULL ) ;
}
else
{
F_23 ( V_2 , V_116 , 0 , 0 , V_44 . V_61 , V_5 - sizeof( struct V_184 ) , NULL , NULL ) ;
for( V_66 = 0 ; V_66 < V_103 ; V_66 ++ )
if ( V_17 -> V_61 [ V_66 ] > 0 )
F_23 ( V_2 , V_108 , 0 , 0 , & V_17 -> V_61 [ V_66 ] , 2 * sizeof( V_17 -> V_61 [ V_66 ] ) , NULL , NULL ) ;
}
for( V_66 = 0 ; V_66 < V_103 ; V_66 ++ )
if ( V_17 -> V_61 [ V_66 ] )
{
V_120 = F_11 ( V_17 -> V_102 [ V_66 ] ) ;
if ( V_120 -> V_183 )
F_23 ( V_2 , V_123 , abs ( V_17 -> V_61 [ V_66 ] ) , 0 , & V_120 -> V_105 , sizeof( struct V_121 ) , NULL , NULL ) ;
}
F_48 ( V_2 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_184 T_3 * V_188 , int V_118 )
{
struct V_16 * V_17 ;
struct V_181 V_44 ;
int V_66 ;
short V_127 ;
if ( V_2 -> type == 0xFFFF )
return - V_189 ;
V_17 = F_11 ( V_2 ) ;
if ( ! V_118 )
{
if ( F_26 ( V_2 ) )
return - V_190 ;
if( F_50 ( & V_44 . V_105 , V_188 , sizeof( struct V_184 ) ) )
return - V_191 ;
if ( V_44 . V_105 . V_106 & ~ V_107 )
return - V_52 ;
if ( V_44 . V_105 . V_13 & ~ V_192 )
return - V_52 ;
if ( ( V_44 . V_105 . V_193 < 0 ) ||
( ( V_44 . V_105 . V_193 > 128 ) && ( V_17 -> type != V_29 ) ) )
return - V_52 ;
if ( V_44 . V_105 . V_194 & ~ ( V_195 | V_196 ) )
return - V_52 ;
if ( ( V_44 . V_105 . V_114 < 0 ) || ( V_44 . V_105 . V_114 > V_197 ) )
return - V_52 ;
if ( ( V_44 . V_105 . V_198 < 5 ) || ( V_44 . V_105 . V_198 > 30 ) )
return - V_52 ;
if ( ( V_44 . V_105 . V_199 < 5 ) || ( V_44 . V_105 . V_199 > 30 ) )
return - V_52 ;
if ( ( V_44 . V_105 . V_200 < 1 ) || ( V_44 . V_105 . V_200 > 255 ) )
return - V_52 ;
if ( ( V_44 . V_105 . V_201 < 1 ) || ( V_44 . V_105 . V_201 > 10 ) )
return - V_52 ;
if ( ( V_44 . V_105 . V_202 < 1 ) || ( V_44 . V_105 . V_202 > 10 ) )
return - V_52 ;
memcpy ( & V_17 -> V_105 , & V_44 . V_105 , sizeof( struct V_184 ) ) ;
V_17 -> V_105 . V_13 |= V_203 ;
if ( V_17 -> type == V_29 )
V_17 -> V_105 . V_13 |= V_204 ;
if ( V_2 -> V_114 != V_17 -> V_105 . V_114 )
{
V_2 -> V_114 = V_17 -> V_105 . V_114 ;
for( V_66 = 0 ; V_66 < V_103 ; V_66 ++ )
if ( V_17 -> V_102 [ V_66 ] )
V_17 -> V_102 [ V_66 ] -> V_114 = V_17 -> V_105 . V_114 ;
}
V_17 -> V_105 . V_114 += sizeof( struct V_150 ) ;
if ( ! V_17 -> V_183 )
F_13 ( V_2 ) ;
V_17 -> V_183 = 1 ;
}
else
{
if ( F_26 ( V_2 ) )
{
V_127 = sizeof( V_44 ) ;
if ( F_23 ( V_2 , V_122 , 0 , 0 , NULL , 0 , & V_44 , & V_127 ) != V_100 )
return - V_47 ;
}
else
if ( V_17 -> V_183 )
memcpy ( & V_44 . V_105 , & V_17 -> V_105 , sizeof( struct V_184 ) ) ;
else
memset ( & V_44 . V_105 , 0 , sizeof( struct V_184 ) ) ;
memcpy ( & V_17 -> V_105 , & V_44 . V_105 , sizeof( struct V_184 ) ) ;
V_44 . V_105 . V_13 &= V_192 ;
V_44 . V_105 . V_114 -= V_44 . V_105 . V_114 > sizeof( struct V_150 ) ? sizeof( struct V_150 ) : V_44 . V_105 . V_114 ;
return F_51 ( V_188 , & V_44 . V_105 , sizeof( struct V_184 ) ) ? - V_191 : 0 ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_205 T_3 * V_206 , int V_207 )
{
struct V_205 V_208 ;
char * V_6 ;
if( F_50 ( & V_208 , V_206 , sizeof( V_208 ) ) )
return - V_191 ;
if ( V_207 )
{
V_6 = F_53 ( V_208 . V_5 , V_209 ) ;
if ( ! V_6 )
return - V_210 ;
F_3 ( V_2 , V_208 . V_3 , V_6 , V_208 . V_5 ) ;
if( F_51 ( V_208 . V_44 , V_6 , V_208 . V_5 ) )
{
F_54 ( V_6 ) ;
return - V_191 ;
}
F_54 ( V_6 ) ;
}
else
{
V_6 = F_55 ( V_208 . V_44 , V_208 . V_5 ) ;
if ( F_56 ( V_6 ) )
return F_57 ( V_6 ) ;
F_7 ( V_2 , V_208 . V_3 , V_6 , V_208 . V_5 ) ;
F_54 ( V_6 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_181 V_44 ;
int V_66 , V_5 ;
V_17 = F_11 ( V_2 ) ;
V_5 = 0 ;
for( V_66 = 0 ; V_66 < V_103 ; V_66 ++ )
if ( V_17 -> V_61 [ V_66 ] )
V_44 . V_61 [ V_5 ++ ] = V_17 -> V_61 [ V_66 ] ;
V_5 *= 2 ;
memcpy ( & V_44 , & V_17 -> V_105 , sizeof( struct V_184 ) ) ;
V_5 += sizeof( struct V_184 ) ;
F_23 ( V_2 , V_180 , 0 , 0 , NULL , 0 , NULL , NULL ) ;
F_23 ( V_2 , V_123 , 0 , 0 , & V_44 , V_5 , NULL , NULL ) ;
F_23 ( V_2 , V_185 , 0 , 0 , NULL , 0 , NULL , NULL ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_42 * V_43 , int V_60 )
{
struct V_16 * V_17 ;
if( ! F_59 ( V_211 ) )
return - V_182 ;
V_17 = F_11 ( V_2 ) ;
if ( ! V_17 -> V_158 )
return - V_52 ;
switch ( V_60 )
{
case V_212 :
case V_213 :
return F_49 ( V_2 , V_43 -> V_214 , V_60 == V_212 ) ;
case V_215 :
V_43 -> V_216 = V_17 -> type ;
break;
case V_217 :
return F_16 ( V_2 , V_43 ) ;
case V_218 :
if ( V_17 -> V_183 )
return - V_219 ;
switch ( V_43 -> V_216 )
{
case V_130 :
V_2 -> type = V_43 -> V_216 ;
break;
default:
return - V_220 ;
}
break;
case V_221 :
F_8 ( V_2 ) ;
break;
case V_222 :
case V_223 :
if( ! F_59 ( V_224 ) )
return - V_182 ;
return F_52 ( V_2 , V_43 -> V_214 , V_60 == V_223 ) ;
case V_225 :
F_13 ( V_2 ) ;
break;
case V_226 :
F_10 ( V_2 ) ;
break;
default:
return - V_227 ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , int V_228 )
{
struct V_16 * V_17 ;
V_17 = F_11 ( V_2 ) ;
if ( F_26 ( V_2 ) )
return - V_190 ;
return - V_227 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_229 * V_230 )
{
struct V_16 * V_17 ;
int V_66 ;
char V_15 ;
unsigned V_7 ;
int V_231 = - V_52 ;
V_17 = F_11 ( V_2 ) ;
if ( V_17 -> V_158 )
return - V_52 ;
for( V_66 = 0 ; V_66 < F_62 ( V_232 ) ; V_66 ++ )
if ( V_232 [ V_66 ] == V_230 -> V_20 )
break;
if ( V_66 == F_62 ( V_232 ) )
return - V_52 ;
if ( ! F_63 ( V_230 -> V_20 , V_233 , V_2 -> V_51 ) ) {
F_64 ( L_25 , V_2 -> V_20 ) ;
return - V_52 ;
}
V_7 = V_230 -> V_20 ;
V_17 -> type = V_234 ;
V_17 -> V_22 = 0 ;
for( V_66 = 1 ; V_66 < V_233 ; V_66 ++ )
if ( F_65 ( V_7 + V_66 ) != 0xFF )
break;
if ( V_66 == V_233 ) {
F_12 ( V_23 , V_7 + V_25 ) ;
if ( ( F_65 ( V_7 + V_235 ) & 0x0F ) == 0x08 ) {
F_12 ( V_170 , V_7 + V_21 ) ;
if ( ( F_65 ( V_7 + V_235 ) & 0x0F ) == 0x0C ) {
F_12 ( V_23 , V_7 + V_21 ) ;
V_17 -> type = V_24 ;
goto V_236;
}
}
}
for( V_15 = F_65 ( V_7 ) , V_66 = 0 ; V_66 < V_233 ; V_66 ++ )
if ( F_65 ( V_7 + V_66 ) != V_15 )
break;
if ( V_66 == V_233 ) {
F_12 ( V_23 , V_7 + V_21 ) ;
if ( ( F_65 ( V_7 + V_235 ) & 0x7E ) == 0x30 ) {
F_12 ( V_237 , V_7 + V_21 ) ;
if ( ( F_65 ( V_7 + V_235 ) & 0x7E ) == 0x32 ) {
F_12 ( V_23 , V_7 + V_21 ) ;
V_17 -> type = V_27 ;
goto V_236;
}
}
}
F_12 ( V_23 , V_7 + V_21 ) ;
if ( ( F_65 ( V_7 + V_238 ) & 0x3F ) == 0x00 ) {
F_12 ( V_179 , V_7 + V_21 ) ;
if ( ( F_65 ( V_7 + V_238 ) & 0x3F ) == 0x10 ) {
F_12 ( V_23 , V_7 + V_21 ) ;
V_17 -> type = V_29 ;
goto V_236;
}
}
F_12 ( V_19 , V_7 + V_21 ) ;
if ( F_65 ( V_7 + V_235 ) == 0x40 ) {
F_12 ( V_31 , V_7 + V_21 ) ;
if ( F_65 ( V_7 + V_235 ) == 0x40 ) {
F_12 ( V_239 , V_7 + V_21 ) ;
if ( F_65 ( V_7 + V_235 ) == 0x44 ) {
F_12 ( V_31 , V_7 + V_21 ) ;
V_17 -> type = V_18 ;
goto V_236;
}
}
}
F_38 ( V_2 , L_26 ) ;
V_231 = - V_104 ;
goto V_240;
V_236:
switch( V_7 ) {
case 0x270 :
case 0x280 :
case 0x380 :
case 0x390 :
if ( V_17 -> type != V_29 && V_17 -> type != V_27 )
goto V_240;
}
switch ( V_230 -> V_159 ) {
case 2 :
if ( V_17 -> type != V_24 )
goto V_240;
break;
case 10 :
case 11 :
case 12 :
case 15 :
case 4 :
if ( V_17 -> type != V_29 && V_17 -> type != V_27 )
goto V_240;
break;
case 3 :
case 5 :
case 7 :
if ( V_17 -> type == V_18 )
goto V_240;
break;
default:
goto V_240;
}
V_231 = - V_241 ;
if ( F_66 ( V_2 -> V_159 , F_42 , 0 , V_2 -> V_51 , V_2 ) )
goto V_240;
if ( V_17 -> type == V_27 ) {
switch( V_2 -> V_159 ) {
case 3 :
V_17 -> V_22 = V_242 ;
break;
case 4 :
V_17 -> V_22 = V_243 ;
break;
case 5 :
V_17 -> V_22 = V_244 ;
break;
case 7 :
V_17 -> V_22 = V_245 ;
break;
case 10 :
V_17 -> V_22 = V_246 ;
break;
case 11 :
V_17 -> V_22 = V_247 ;
break;
case 12 :
V_17 -> V_22 = V_248 ;
break;
case 15 :
V_17 -> V_22 = V_249 ;
break;
}
}
for( V_66 = 0 ; V_66 < F_62 ( V_250 ) ; V_66 ++ )
if ( V_250 [ V_66 ] == V_230 -> V_12 )
break;
V_231 = - V_52 ;
if ( V_66 == F_62 ( V_250 ) )
goto V_251;
if ( V_17 -> type == V_18 && ( V_230 -> V_12 & 0xF000 ) >> 12 == 0x0E )
goto V_251;
if ( V_17 -> type != V_27 && V_230 -> V_12 >> 16 == 0x0B )
goto V_251;
if ( V_17 -> type == V_27 && V_230 -> V_12 >> 16 == 0x0D )
goto V_251;
V_15 = V_17 -> type != V_29 ? V_252 : 0 ;
V_15 |= ( V_230 -> V_12 & 0xF000 ) >> ( 12 + ( V_17 -> type == V_29 ? 1 : 0 ) ) ;
switch( V_17 -> type ) {
case V_18 :
case V_24 :
switch ( V_230 -> V_12 >> 16 ) {
case 0x0A :
V_15 |= V_253 ;
break;
case 0x0C :
V_15 |= V_254 ;
break;
case 0x0D :
V_15 |= V_255 ;
break;
case 0x0E :
V_15 |= V_256 ;
break;
}
break;
case V_27 :
switch ( V_230 -> V_12 >> 16 ) {
case 0x0A :
V_15 |= V_257 ;
break;
case 0x0B :
V_15 |= V_258 ;
break;
case 0x0C :
V_15 |= V_259 ;
break;
case 0x0E :
V_15 |= V_260 ;
break;
}
break;
case V_29 :
switch ( V_230 -> V_12 >> 16 ) {
case 0x0A :
V_15 |= V_261 ;
break;
case 0x0C :
V_15 |= V_262 ;
break;
case 0x0D :
V_15 |= V_263 ;
break;
case 0x0E :
V_15 |= V_264 ;
break;
}
break;
}
F_12 ( V_15 , V_7 + V_265 ) ;
switch( V_17 -> type )
{
case V_24 :
V_17 -> V_22 = V_26 ;
break;
case V_27 :
V_17 -> V_22 |= V_266 ;
break;
case V_29 :
V_17 -> V_22 = V_266 ;
break;
}
F_12 ( V_17 -> V_22 , V_7 + V_21 ) ;
V_2 -> V_159 = V_230 -> V_159 ;
V_2 -> V_20 = V_7 ;
V_2 -> V_12 = V_230 -> V_12 ;
V_2 -> V_267 = V_2 -> V_12 + 0x2000 ;
V_17 -> V_158 = 1 ;
return 0 ;
V_251:
F_67 ( V_230 -> V_159 , V_2 ) ;
V_240:
F_68 ( V_7 , V_233 ) ;
return V_231 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_11 ( V_2 ) ;
F_70 ( V_2 ) ;
V_2 -> V_268 = & V_269 ;
V_2 -> V_13 = 0 ;
V_2 -> type = 0xFFFF ;
V_2 -> V_270 = 0 ;
V_2 -> V_271 = 0 ;
V_2 -> V_114 = V_197 ;
V_17 -> V_272 = F_25 ;
V_17 -> V_273 = F_27 ;
V_17 -> V_274 = F_28 ;
V_17 -> V_275 = F_30 ;
V_17 -> V_121 = F_31 ;
F_71 ( & V_17 -> V_173 ) ;
V_17 -> V_173 . V_174 = 1 ;
V_17 -> V_173 . V_44 = ( unsigned long ) V_2 ;
V_17 -> V_173 . V_276 = F_43 ;
}
static int T_4 F_72 ( void )
{
int V_231 ;
F_17 ( L_27 , V_277 ) ;
V_278 = F_73 ( sizeof( struct V_16 ) , L_28 , F_69 ) ;
if ( ! V_278 )
return - V_210 ;
V_231 = F_74 ( V_278 ) ;
if ( V_231 )
F_75 ( V_278 ) ;
return V_231 ;
}
static void T_5 F_76 ( void )
{
struct V_16 * V_17 = F_11 ( V_278 ) ;
F_77 ( V_278 ) ;
if ( V_17 -> V_158 ) {
F_67 ( V_278 -> V_159 , V_278 ) ;
F_68 ( V_278 -> V_20 , V_233 ) ;
}
F_78 ( & V_17 -> V_173 ) ;
F_75 ( V_278 ) ;
}
