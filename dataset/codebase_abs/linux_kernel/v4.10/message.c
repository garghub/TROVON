static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
V_3 -> V_5 = V_1 -> V_5 ;
F_2 ( & V_3 -> V_6 ) ;
}
static int F_3 ( struct V_1 * V_1 , int V_7 , int * V_8 )
{
struct V_2 V_3 ;
unsigned long V_9 ;
int V_10 ;
F_4 ( & V_3 . V_6 ) ;
V_1 -> V_4 = & V_3 ;
V_1 -> V_8 = 0 ;
V_10 = F_5 ( V_1 , V_11 ) ;
if ( F_6 ( V_10 ) )
goto V_12;
V_9 = V_7 ? F_7 ( V_7 ) : V_13 ;
if ( ! F_8 ( & V_3 . V_6 , V_9 ) ) {
F_9 ( V_1 ) ;
V_10 = ( V_3 . V_5 == - V_14 ? - V_15 : V_3 . V_5 ) ;
F_10 ( & V_1 -> V_16 -> V_16 ,
L_1 ,
V_17 -> V_18 ,
F_11 ( & V_1 -> V_19 -> V_20 ) ,
F_12 ( V_1 ) ? L_2 : L_3 ,
V_1 -> V_8 ,
V_1 -> V_21 ) ;
} else
V_10 = V_3 . V_5 ;
V_12:
if ( V_8 )
* V_8 = V_1 -> V_8 ;
F_13 ( V_1 ) ;
return V_10 ;
}
static int F_14 ( struct V_22 * V_23 ,
unsigned int V_24 ,
struct V_25 * V_26 ,
void * V_27 , int V_28 , int V_7 )
{
struct V_1 * V_1 ;
int V_29 ;
int V_30 ;
V_1 = F_15 ( 0 , V_11 ) ;
if ( ! V_1 )
return - V_31 ;
F_16 ( V_1 , V_23 , V_24 , ( unsigned char * ) V_26 , V_27 ,
V_28 , F_1 , NULL ) ;
V_29 = F_3 ( V_1 , V_7 , & V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
else
return V_30 ;
}
int F_17 ( struct V_22 * V_16 , unsigned int V_24 , T_1 V_32 ,
T_1 V_33 , T_2 V_34 , T_2 V_35 , void * V_27 ,
T_2 V_36 , int V_7 )
{
struct V_25 * V_37 ;
int V_38 ;
V_37 = F_18 ( sizeof( struct V_25 ) , V_11 ) ;
if ( ! V_37 )
return - V_31 ;
V_37 -> V_39 = V_33 ;
V_37 -> V_40 = V_32 ;
V_37 -> V_41 = F_19 ( V_34 ) ;
V_37 -> V_42 = F_19 ( V_35 ) ;
V_37 -> V_43 = F_19 ( V_36 ) ;
V_38 = F_14 ( V_16 , V_24 , V_37 , V_27 , V_36 , V_7 ) ;
F_20 ( V_37 ) ;
return V_38 ;
}
int F_21 ( struct V_22 * V_23 , unsigned int V_24 ,
void * V_27 , int V_28 , int * V_8 , int V_7 )
{
return F_22 ( V_23 , V_24 , V_27 , V_28 , V_8 , V_7 ) ;
}
int F_22 ( struct V_22 * V_23 , unsigned int V_24 ,
void * V_27 , int V_28 , int * V_8 , int V_7 )
{
struct V_1 * V_1 ;
struct V_44 * V_19 ;
V_19 = F_23 ( V_23 , V_24 ) ;
if ( ! V_19 || V_28 < 0 )
return - V_45 ;
V_1 = F_15 ( 0 , V_46 ) ;
if ( ! V_1 )
return - V_31 ;
if ( ( V_19 -> V_20 . V_47 & V_48 ) ==
V_49 ) {
V_24 = ( V_24 & ~ ( 3 << 30 ) ) | ( V_50 << 30 ) ;
F_24 ( V_1 , V_23 , V_24 , V_27 , V_28 ,
F_1 , NULL ,
V_19 -> V_20 . V_51 ) ;
} else
F_25 ( V_1 , V_23 , V_24 , V_27 , V_28 ,
F_1 , NULL ) ;
return F_3 ( V_1 , V_7 , V_8 ) ;
}
static void F_26 ( struct V_52 * V_53 )
{
if ( V_53 -> V_54 ) {
while ( V_53 -> V_55 -- )
F_13 ( V_53 -> V_54 [ V_53 -> V_55 ] ) ;
F_20 ( V_53 -> V_54 ) ;
V_53 -> V_54 = NULL ;
}
V_53 -> V_16 = NULL ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_52 * V_53 = V_1 -> V_4 ;
int V_5 = V_1 -> V_5 ;
F_28 ( & V_53 -> V_56 ) ;
if ( V_53 -> V_5
&& ( V_53 -> V_5 != - V_57
|| V_5 != - V_57 )
&& V_1 -> V_8 ) {
F_29 ( V_53 -> V_16 -> V_58 -> V_59 ,
L_4 ,
V_53 -> V_16 -> V_60 ,
F_11 ( & V_1 -> V_19 -> V_20 ) ,
F_12 ( V_1 ) ? L_2 : L_3 ,
V_5 , V_53 -> V_5 ) ;
}
if ( V_53 -> V_5 == 0 && V_5 && V_5 != - V_57 ) {
int V_61 , V_62 , V_10 ;
V_53 -> V_5 = V_5 ;
F_30 ( & V_53 -> V_56 ) ;
for ( V_61 = 0 , V_62 = 0 ; V_61 < V_53 -> V_55 ; V_61 ++ ) {
if ( ! V_53 -> V_54 [ V_61 ] )
continue;
if ( V_62 ) {
F_31 ( V_53 -> V_54 [ V_61 ] ) ;
V_10 = F_32 ( V_53 -> V_54 [ V_61 ] ) ;
if ( V_10 != - V_63 &&
V_10 != - V_64 &&
V_10 != - V_65 &&
V_10 != - V_66 )
F_29 ( & V_53 -> V_16 -> V_16 ,
L_5 ,
V_67 , V_10 ) ;
} else if ( V_1 == V_53 -> V_54 [ V_61 ] )
V_62 = 1 ;
}
F_28 ( & V_53 -> V_56 ) ;
}
V_53 -> V_68 += V_1 -> V_8 ;
V_53 -> V_69 -- ;
if ( ! V_53 -> V_69 )
F_2 ( & V_53 -> F_2 ) ;
F_30 ( & V_53 -> V_56 ) ;
}
int F_33 ( struct V_52 * V_53 , struct V_22 * V_16 ,
unsigned V_24 , unsigned V_70 , struct V_71 * V_72 ,
int V_73 , T_3 V_30 , T_4 V_74 )
{
int V_61 ;
int V_75 ;
int V_76 ;
if ( ! V_53 || ! V_16 || ! V_72
|| F_34 ( V_24 )
|| F_35 ( V_24 )
|| V_73 <= 0 )
return - V_45 ;
F_36 ( & V_53 -> V_56 ) ;
V_53 -> V_16 = V_16 ;
V_53 -> V_24 = V_24 ;
if ( V_16 -> V_58 -> V_77 > 0 ) {
V_76 = true ;
V_53 -> V_55 = 1 ;
} else {
V_76 = false ;
V_53 -> V_55 = V_73 ;
}
V_53 -> V_54 = F_18 ( V_53 -> V_55 * sizeof( * V_53 -> V_54 ) , V_74 ) ;
if ( ! V_53 -> V_54 )
goto V_78;
V_75 = V_79 ;
if ( F_37 ( V_24 ) )
V_75 |= V_80 ;
F_38 (sg, sg, io->entries, i) {
struct V_1 * V_1 ;
unsigned V_28 ;
V_1 = F_15 ( 0 , V_74 ) ;
if ( ! V_1 ) {
V_53 -> V_55 = V_61 ;
goto V_78;
}
V_53 -> V_54 [ V_61 ] = V_1 ;
V_1 -> V_16 = NULL ;
V_1 -> V_24 = V_24 ;
V_1 -> V_81 = V_70 ;
V_1 -> V_82 = V_75 ;
V_1 -> F_2 = F_27 ;
V_1 -> V_4 = V_53 ;
V_1 -> V_72 = V_72 ;
if ( V_76 ) {
V_1 -> V_83 = NULL ;
V_1 -> V_84 = V_73 ;
V_28 = V_30 ;
if ( V_28 == 0 ) {
struct V_71 * V_85 ;
int V_86 ;
F_38 (sg, sg2, nents, j)
V_28 += V_85 -> V_30 ;
}
} else {
if ( ! F_39 ( F_40 ( V_72 ) ) )
V_1 -> V_83 = F_41 ( V_72 ) ;
else
V_1 -> V_83 = NULL ;
V_28 = V_72 -> V_30 ;
if ( V_30 ) {
V_28 = F_42 ( T_3 , V_28 , V_30 ) ;
V_30 -= V_28 ;
if ( V_30 == 0 )
V_53 -> V_55 = V_61 + 1 ;
}
}
V_1 -> V_21 = V_28 ;
}
V_53 -> V_54 [ -- V_61 ] -> V_82 &= ~ V_79 ;
V_53 -> V_69 = V_53 -> V_55 ;
V_53 -> V_5 = 0 ;
V_53 -> V_68 = 0 ;
F_4 ( & V_53 -> F_2 ) ;
return 0 ;
V_78:
F_26 ( V_53 ) ;
return - V_31 ;
}
void F_43 ( struct V_52 * V_53 )
{
int V_61 ;
int V_55 = V_53 -> V_55 ;
F_44 ( & V_53 -> V_56 ) ;
V_61 = 0 ;
while ( V_61 < V_55 && ! V_53 -> V_5 ) {
int V_10 ;
V_53 -> V_54 [ V_61 ] -> V_16 = V_53 -> V_16 ;
F_45 ( & V_53 -> V_56 ) ;
V_10 = F_5 ( V_53 -> V_54 [ V_61 ] , V_11 ) ;
switch ( V_10 ) {
case - V_87 :
case - V_88 :
case - V_31 :
V_10 = 0 ;
F_46 () ;
break;
case 0 :
++ V_61 ;
F_47 () ;
break;
default:
V_53 -> V_54 [ V_61 ] -> V_5 = V_10 ;
F_10 ( & V_53 -> V_16 -> V_16 , L_6 ,
V_67 , V_10 ) ;
F_48 ( V_53 ) ;
}
F_44 ( & V_53 -> V_56 ) ;
if ( V_10 && ( V_53 -> V_5 == 0 || V_53 -> V_5 == - V_57 ) )
V_53 -> V_5 = V_10 ;
}
V_53 -> V_69 -= V_55 - V_61 ;
if ( V_53 -> V_69 == 0 )
F_2 ( & V_53 -> F_2 ) ;
F_45 ( & V_53 -> V_56 ) ;
F_49 ( & V_53 -> F_2 ) ;
F_26 ( V_53 ) ;
}
void F_48 ( struct V_52 * V_53 )
{
unsigned long V_89 ;
int V_61 , V_10 ;
F_50 ( & V_53 -> V_56 , V_89 ) ;
if ( V_53 -> V_5 ) {
F_51 ( & V_53 -> V_56 , V_89 ) ;
return;
}
V_53 -> V_5 = - V_57 ;
F_51 ( & V_53 -> V_56 , V_89 ) ;
for ( V_61 = V_53 -> V_55 - 1 ; V_61 >= 0 ; -- V_61 ) {
F_31 ( V_53 -> V_54 [ V_61 ] ) ;
V_10 = F_32 ( V_53 -> V_54 [ V_61 ] ) ;
if ( V_10 != - V_63
&& V_10 != - V_64
&& V_10 != - V_65
&& V_10 != - V_66 )
F_52 ( & V_53 -> V_16 -> V_16 , L_5 ,
V_67 , V_10 ) ;
}
}
int F_53 ( struct V_22 * V_16 , unsigned char type ,
unsigned char V_35 , void * V_90 , int V_36 )
{
int V_61 ;
int V_91 ;
memset ( V_90 , 0 , V_36 ) ;
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
V_91 = F_17 ( V_16 , F_54 ( V_16 , 0 ) ,
V_92 , V_93 ,
( type << 8 ) + V_35 , 0 , V_90 , V_36 ,
V_94 ) ;
if ( V_91 <= 0 && V_91 != - V_15 )
continue;
if ( V_91 > 1 && ( ( V_95 * ) V_90 ) [ 1 ] != type ) {
V_91 = - V_96 ;
continue;
}
break;
}
return V_91 ;
}
static int F_55 ( struct V_22 * V_16 , unsigned short V_97 ,
unsigned char V_35 , void * V_90 , int V_36 )
{
int V_61 ;
int V_91 ;
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
V_91 = F_17 ( V_16 , F_54 ( V_16 , 0 ) ,
V_92 , V_93 ,
( V_98 << 8 ) + V_35 , V_97 , V_90 , V_36 ,
V_94 ) ;
if ( V_91 == 0 || V_91 == - V_99 )
continue;
if ( V_91 > 1 && ( ( V_95 * ) V_90 ) [ 1 ] != V_98 ) {
V_91 = - V_96 ;
continue;
}
break;
}
return V_91 ;
}
static void F_56 ( unsigned char * V_90 , int * V_30 )
{
int V_100 , V_101 = * V_30 ;
for ( V_100 = 2 ; V_100 + 1 < V_101 ; V_100 += 2 )
if ( ! isprint ( V_90 [ V_100 ] ) || V_90 [ V_100 + 1 ] )
break;
if ( V_100 > 2 ) {
V_90 [ 0 ] = V_100 ;
* V_30 = V_100 ;
}
}
static int F_57 ( struct V_22 * V_16 , unsigned int V_97 ,
unsigned int V_35 , unsigned char * V_90 )
{
int V_102 ;
if ( V_16 -> V_103 & V_104 )
V_102 = - V_105 ;
else
V_102 = F_55 ( V_16 , V_97 , V_35 , V_90 , 255 ) ;
if ( V_102 < 2 ) {
V_102 = F_55 ( V_16 , V_97 , V_35 , V_90 , 2 ) ;
if ( V_102 == 2 )
V_102 = F_55 ( V_16 , V_97 , V_35 , V_90 , V_90 [ 0 ] ) ;
}
if ( V_102 >= 2 ) {
if ( ! V_90 [ 0 ] && ! V_90 [ 1 ] )
F_56 ( V_90 , & V_102 ) ;
if ( V_90 [ 0 ] < V_102 )
V_102 = V_90 [ 0 ] ;
V_102 = V_102 - ( V_102 & 1 ) ;
}
if ( V_102 < 2 )
V_102 = ( V_102 < 0 ? V_102 : - V_45 ) ;
return V_102 ;
}
static int F_58 ( struct V_22 * V_16 , unsigned char * V_106 )
{
int V_107 ;
if ( V_16 -> V_108 )
return 0 ;
if ( V_16 -> V_109 < 0 )
return - V_99 ;
V_107 = F_57 ( V_16 , 0 , 0 , V_106 ) ;
if ( V_107 == - V_96 || ( V_107 > 0 && V_107 < 4 ) ) {
V_16 -> V_109 = 0x0409 ;
V_16 -> V_108 = 1 ;
F_29 ( & V_16 -> V_16 ,
L_7 ) ;
return 0 ;
}
if ( V_107 < 0 ) {
F_29 ( & V_16 -> V_16 , L_8 ,
V_107 ) ;
V_16 -> V_109 = - 1 ;
return - V_99 ;
}
V_16 -> V_109 = V_106 [ 2 ] | ( V_106 [ 3 ] << 8 ) ;
V_16 -> V_108 = 1 ;
F_10 ( & V_16 -> V_16 , L_9 ,
V_16 -> V_109 ) ;
return 0 ;
}
int F_59 ( struct V_22 * V_16 , int V_35 , char * V_90 , T_3 V_36 )
{
unsigned char * V_106 ;
int V_107 ;
if ( V_16 -> V_110 == V_111 )
return - V_112 ;
if ( V_36 <= 0 || ! V_90 || ! V_35 )
return - V_45 ;
V_90 [ 0 ] = 0 ;
V_106 = F_18 ( 256 , V_11 ) ;
if ( ! V_106 )
return - V_31 ;
V_107 = F_58 ( V_16 , V_106 ) ;
if ( V_107 < 0 )
goto V_113;
V_107 = F_57 ( V_16 , V_16 -> V_109 , V_35 , V_106 ) ;
if ( V_107 < 0 )
goto V_113;
V_36 -- ;
V_107 = F_60 ( ( V_114 * ) & V_106 [ 2 ] , ( V_107 - 2 ) / 2 ,
V_115 , V_90 , V_36 ) ;
V_90 [ V_107 ] = 0 ;
if ( V_106 [ 1 ] != V_98 )
F_10 ( & V_16 -> V_16 ,
L_10 ,
V_106 [ 1 ] , V_35 , V_90 ) ;
V_113:
F_20 ( V_106 ) ;
return V_107 ;
}
char * F_61 ( struct V_22 * V_116 , int V_35 )
{
char * V_90 ;
char * V_117 = NULL ;
int V_28 ;
if ( V_35 <= 0 )
return NULL ;
V_90 = F_18 ( V_118 , V_11 ) ;
if ( V_90 ) {
V_28 = F_59 ( V_116 , V_35 , V_90 , V_118 ) ;
if ( V_28 > 0 ) {
V_117 = F_18 ( ++ V_28 , V_11 ) ;
if ( ! V_117 )
return V_90 ;
memcpy ( V_117 , V_90 , V_28 ) ;
}
F_20 ( V_90 ) ;
}
return V_117 ;
}
int F_62 ( struct V_22 * V_16 , unsigned int V_36 )
{
struct V_119 * V_20 ;
int V_38 ;
if ( V_36 > sizeof( * V_20 ) )
return - V_45 ;
V_20 = F_18 ( sizeof( * V_20 ) , V_11 ) ;
if ( ! V_20 )
return - V_31 ;
V_38 = F_53 ( V_16 , V_120 , 0 , V_20 , V_36 ) ;
if ( V_38 >= 0 )
memcpy ( & V_16 -> V_121 , V_20 , V_36 ) ;
F_20 ( V_20 ) ;
return V_38 ;
}
int F_63 ( struct V_22 * V_16 , int type , int V_122 , void * V_27 )
{
int V_38 ;
T_5 * V_5 = F_18 ( sizeof( * V_5 ) , V_46 ) ;
if ( ! V_5 )
return - V_31 ;
V_38 = F_17 ( V_16 , F_54 ( V_16 , 0 ) ,
V_123 , V_93 | type , 0 , V_122 , V_5 ,
sizeof( * V_5 ) , V_94 ) ;
if ( V_38 == 2 ) {
* ( V_124 * ) V_27 = F_64 ( * V_5 ) ;
V_38 = 0 ;
} else if ( V_38 >= 0 ) {
V_38 = - V_105 ;
}
F_20 ( V_5 ) ;
return V_38 ;
}
int F_65 ( struct V_22 * V_16 , int V_24 )
{
int V_91 ;
int V_125 = F_66 ( V_24 ) ;
if ( F_37 ( V_24 ) )
V_125 |= V_93 ;
V_91 = F_17 ( V_16 , F_67 ( V_16 , 0 ) ,
V_126 , V_127 ,
V_128 , V_125 , NULL , 0 ,
V_129 ) ;
if ( V_91 < 0 )
return V_91 ;
F_68 ( V_16 , V_125 ) ;
return 0 ;
}
static int F_69 ( struct V_130 * V_131 )
{
struct V_22 * V_116 = F_70 ( V_131 ) ;
struct V_132 * V_133 = V_131 -> V_134 ;
int V_61 ;
if ( V_131 -> V_135 || V_131 -> V_136 )
return 0 ;
for ( V_61 = 0 ; V_61 < V_133 -> V_20 . V_137 ; ++ V_61 )
( void ) F_71 ( & V_131 -> V_16 , & V_133 -> V_138 [ V_61 ] , V_116 ) ;
V_131 -> V_135 = 1 ;
return 0 ;
}
static void F_72 ( struct V_130 * V_131 )
{
struct V_132 * V_133 = V_131 -> V_134 ;
int V_61 ;
if ( ! V_131 -> V_135 )
return;
for ( V_61 = 0 ; V_61 < V_133 -> V_20 . V_137 ; ++ V_61 )
F_73 ( & V_133 -> V_138 [ V_61 ] ) ;
V_131 -> V_135 = 0 ;
}
void F_74 ( struct V_22 * V_16 , unsigned int V_139 ,
bool V_140 )
{
unsigned int V_141 = V_139 & V_142 ;
struct V_44 * V_19 ;
if ( ! V_16 )
return;
if ( F_75 ( V_139 ) ) {
V_19 = V_16 -> V_143 [ V_141 ] ;
if ( V_140 )
V_16 -> V_143 [ V_141 ] = NULL ;
} else {
V_19 = V_16 -> V_144 [ V_141 ] ;
if ( V_140 )
V_16 -> V_144 [ V_141 ] = NULL ;
}
if ( V_19 ) {
V_19 -> V_145 = 0 ;
F_76 ( V_16 , V_19 ) ;
if ( V_140 )
F_77 ( V_16 , V_19 ) ;
}
}
void F_68 ( struct V_22 * V_16 , unsigned int V_139 )
{
unsigned int V_141 = V_139 & V_142 ;
struct V_44 * V_19 ;
if ( F_75 ( V_139 ) )
V_19 = V_16 -> V_143 [ V_141 ] ;
else
V_19 = V_16 -> V_144 [ V_141 ] ;
if ( V_19 )
F_78 ( V_16 , V_19 ) ;
}
void F_79 ( struct V_22 * V_16 , struct V_130 * V_131 ,
bool V_140 )
{
struct V_132 * V_133 = V_131 -> V_134 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_133 -> V_20 . V_137 ; ++ V_61 ) {
F_74 ( V_16 ,
V_133 -> V_138 [ V_61 ] . V_20 . V_146 ,
V_140 ) ;
}
}
void F_80 ( struct V_22 * V_16 , int V_147 )
{
int V_61 ;
struct V_148 * V_149 = F_81 ( V_16 -> V_58 ) ;
if ( V_16 -> V_150 ) {
for ( V_61 = 0 ; V_61 < V_16 -> V_150 -> V_20 . V_151 ; V_61 ++ )
V_16 -> V_150 -> V_152 [ V_61 ] -> V_136 = 1 ;
for ( V_61 = 0 ; V_61 < V_16 -> V_150 -> V_20 . V_151 ; V_61 ++ ) {
struct V_130 * V_152 ;
V_152 = V_16 -> V_150 -> V_152 [ V_61 ] ;
if ( ! F_82 ( & V_152 -> V_16 ) )
continue;
F_10 ( & V_16 -> V_16 , L_11 ,
F_83 ( & V_152 -> V_16 ) ) ;
F_72 ( V_152 ) ;
F_84 ( & V_152 -> V_16 ) ;
}
for ( V_61 = 0 ; V_61 < V_16 -> V_150 -> V_20 . V_151 ; V_61 ++ ) {
F_85 ( & V_16 -> V_150 -> V_152 [ V_61 ] -> V_16 ) ;
V_16 -> V_150 -> V_152 [ V_61 ] = NULL ;
}
if ( V_16 -> V_153 == 1 )
F_86 ( V_16 , 0 ) ;
F_87 ( V_16 ) ;
F_88 ( V_16 ) ;
V_16 -> V_150 = NULL ;
if ( V_16 -> V_110 == V_154 )
F_89 ( V_16 , V_155 ) ;
}
F_10 ( & V_16 -> V_16 , L_12 , V_67 ,
V_147 ? L_13 : L_14 ) ;
if ( V_149 -> V_156 -> V_157 ) {
for ( V_61 = V_147 ; V_61 < 16 ; ++ V_61 ) {
F_74 ( V_16 , V_61 , false ) ;
F_74 ( V_16 , V_61 + V_93 , false ) ;
}
F_90 ( V_149 -> V_158 ) ;
F_91 ( V_16 , NULL , NULL , NULL ) ;
F_92 ( V_149 -> V_158 ) ;
}
for ( V_61 = V_147 ; V_61 < 16 ; ++ V_61 ) {
F_74 ( V_16 , V_61 , true ) ;
F_74 ( V_16 , V_61 + V_93 , true ) ;
}
}
void F_93 ( struct V_22 * V_16 , struct V_44 * V_19 ,
bool V_159 )
{
int V_141 = F_11 ( & V_19 -> V_20 ) ;
int V_160 = F_94 ( & V_19 -> V_20 ) ;
int V_161 = F_95 ( & V_19 -> V_20 ) ;
if ( V_159 )
F_78 ( V_16 , V_19 ) ;
if ( V_160 || V_161 )
V_16 -> V_143 [ V_141 ] = V_19 ;
if ( ! V_160 || V_161 )
V_16 -> V_144 [ V_141 ] = V_19 ;
V_19 -> V_145 = 1 ;
}
void F_96 ( struct V_22 * V_16 ,
struct V_130 * V_131 , bool V_162 )
{
struct V_132 * V_133 = V_131 -> V_134 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_133 -> V_20 . V_137 ; ++ V_61 )
F_93 ( V_16 , & V_133 -> V_138 [ V_61 ] , V_162 ) ;
}
int F_97 ( struct V_22 * V_16 , int V_152 , int V_163 )
{
struct V_130 * V_164 ;
struct V_132 * V_133 ;
struct V_148 * V_149 = F_81 ( V_16 -> V_58 ) ;
int V_61 , V_38 , V_165 = 0 ;
unsigned int V_139 ;
unsigned int V_24 ;
if ( V_16 -> V_110 == V_111 )
return - V_112 ;
V_164 = F_98 ( V_16 , V_152 ) ;
if ( ! V_164 ) {
F_10 ( & V_16 -> V_16 , L_15 ,
V_152 ) ;
return - V_45 ;
}
if ( V_164 -> V_136 )
return - V_64 ;
V_133 = F_99 ( V_164 , V_163 ) ;
if ( ! V_133 ) {
F_52 ( & V_16 -> V_16 , L_16 ,
V_163 ) ;
return - V_45 ;
}
F_90 ( V_149 -> V_158 ) ;
if ( F_100 ( V_16 ) ) {
F_29 ( & V_164 -> V_16 , L_17 , V_67 ) ;
F_92 ( V_149 -> V_158 ) ;
return - V_31 ;
}
for ( V_61 = 0 ; V_61 < V_164 -> V_134 -> V_20 . V_137 ; V_61 ++ )
V_164 -> V_134 -> V_138 [ V_61 ] . V_166 = 0 ;
V_38 = F_91 ( V_16 , NULL , V_164 -> V_134 , V_133 ) ;
if ( V_38 < 0 ) {
F_101 ( & V_16 -> V_16 , L_18 ,
V_163 ) ;
F_102 ( V_16 ) ;
F_92 ( V_149 -> V_158 ) ;
return V_38 ;
}
if ( V_16 -> V_103 & V_167 )
V_38 = - V_99 ;
else
V_38 = F_17 ( V_16 , F_67 ( V_16 , 0 ) ,
V_168 , V_169 ,
V_163 , V_152 , NULL , 0 , 5000 ) ;
if ( V_38 == - V_99 && V_164 -> V_170 == 1 ) {
F_10 ( & V_16 -> V_16 ,
L_19 ,
V_152 , V_163 ) ;
V_165 = 1 ;
} else if ( V_38 < 0 ) {
F_91 ( V_16 , NULL , V_133 , V_164 -> V_134 ) ;
F_102 ( V_16 ) ;
F_92 ( V_149 -> V_158 ) ;
return V_38 ;
}
F_92 ( V_149 -> V_158 ) ;
if ( V_164 -> V_134 != V_133 ) {
F_72 ( V_164 ) ;
F_103 ( V_164 ) ;
}
F_79 ( V_16 , V_164 , true ) ;
V_164 -> V_134 = V_133 ;
F_104 ( V_16 ) ;
if ( V_165 ) {
for ( V_61 = 0 ; V_61 < V_133 -> V_20 . V_137 ; V_61 ++ ) {
V_139 = V_133 -> V_138 [ V_61 ] . V_20 . V_146 ;
V_24 = F_105 ( V_16 ,
V_142 & V_139 ) |
( F_75 ( V_139 ) ?
V_171 : V_93 ) ;
F_65 ( V_16 , V_24 ) ;
}
}
F_96 ( V_16 , V_164 , true ) ;
if ( F_82 ( & V_164 -> V_16 ) ) {
F_106 ( V_164 ) ;
F_69 ( V_164 ) ;
}
return 0 ;
}
int F_107 ( struct V_22 * V_16 )
{
int V_61 , V_10 ;
struct V_172 * V_173 ;
struct V_148 * V_149 = F_81 ( V_16 -> V_58 ) ;
if ( V_16 -> V_110 == V_111 )
return - V_112 ;
for ( V_61 = 1 ; V_61 < 16 ; ++ V_61 ) {
F_74 ( V_16 , V_61 , true ) ;
F_74 ( V_16 , V_61 + V_93 , true ) ;
}
V_173 = V_16 -> V_150 ;
V_10 = 0 ;
F_90 ( V_149 -> V_158 ) ;
if ( F_100 ( V_16 ) ) {
F_29 ( & V_16 -> V_16 , L_17 , V_67 ) ;
F_92 ( V_149 -> V_158 ) ;
return - V_31 ;
}
for ( V_61 = 0 ; V_61 < V_173 -> V_20 . V_151 ; V_61 ++ ) {
struct V_130 * V_131 = V_173 -> V_152 [ V_61 ] ;
struct V_132 * V_133 ;
V_133 = F_99 ( V_131 , 0 ) ;
if ( ! V_133 )
V_133 = & V_131 -> V_174 [ 0 ] ;
if ( V_133 != V_131 -> V_134 )
V_10 = F_91 ( V_16 , NULL ,
V_131 -> V_134 , V_133 ) ;
if ( V_10 < 0 )
break;
}
if ( V_10 < 0 ) {
V_175:
for ( V_61 -- ; V_61 >= 0 ; V_61 -- ) {
struct V_130 * V_131 = V_173 -> V_152 [ V_61 ] ;
struct V_132 * V_133 ;
V_133 = F_99 ( V_131 , 0 ) ;
if ( ! V_133 )
V_133 = & V_131 -> V_174 [ 0 ] ;
if ( V_133 != V_131 -> V_134 )
F_91 ( V_16 , NULL ,
V_133 , V_131 -> V_134 ) ;
}
F_102 ( V_16 ) ;
F_92 ( V_149 -> V_158 ) ;
return V_10 ;
}
V_10 = F_17 ( V_16 , F_67 ( V_16 , 0 ) ,
V_176 , 0 ,
V_173 -> V_20 . V_177 , 0 ,
NULL , 0 , V_129 ) ;
if ( V_10 < 0 )
goto V_175;
F_92 ( V_149 -> V_158 ) ;
for ( V_61 = 0 ; V_61 < V_173 -> V_20 . V_151 ; V_61 ++ ) {
struct V_130 * V_131 = V_173 -> V_152 [ V_61 ] ;
struct V_132 * V_133 ;
V_133 = F_99 ( V_131 , 0 ) ;
if ( ! V_133 )
V_133 = & V_131 -> V_174 [ 0 ] ;
if ( V_133 != V_131 -> V_134 ) {
F_72 ( V_131 ) ;
F_103 ( V_131 ) ;
}
V_131 -> V_134 = V_133 ;
F_96 ( V_16 , V_131 , true ) ;
if ( F_82 ( & V_131 -> V_16 ) ) {
F_106 ( V_131 ) ;
F_69 ( V_131 ) ;
}
}
F_104 ( V_16 ) ;
return 0 ;
}
static void F_108 ( struct V_178 * V_16 )
{
struct V_130 * V_131 = F_109 ( V_16 ) ;
struct V_179 * V_180 =
F_110 ( V_131 -> V_174 ) ;
F_111 ( & V_180 -> V_181 , V_182 ) ;
F_112 ( F_70 ( V_131 ) ) ;
F_20 ( V_131 ) ;
}
void F_113 ( struct V_130 * V_131 )
{
struct V_178 * V_16 = & V_131 -> V_16 ;
F_114 ( V_16 -> V_183 ) ;
if ( V_131 -> V_184 ) {
F_114 ( V_16 ) ;
V_131 -> V_184 = 0 ;
F_115 ( V_16 ) ;
F_116 ( V_131 ) ;
}
F_115 ( V_16 -> V_183 ) ;
}
void F_117 ( struct V_130 * V_131 )
{
struct V_178 * V_16 = & V_131 -> V_16 ;
if ( ! V_131 -> V_184 ) {
F_114 ( V_16 ) ;
V_131 -> V_184 = 1 ;
F_115 ( V_16 ) ;
}
}
static int F_118 ( struct V_178 * V_16 , struct V_185 * V_186 )
{
struct V_22 * V_23 ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
V_131 = F_109 ( V_16 ) ;
V_23 = F_70 ( V_131 ) ;
V_133 = V_131 -> V_134 ;
if ( F_119 ( V_186 , L_20 ,
V_133 -> V_20 . V_187 ,
V_133 -> V_20 . V_188 ,
V_133 -> V_20 . V_189 ) )
return - V_31 ;
if ( F_119 ( V_186 ,
L_21
L_22 ,
F_64 ( V_23 -> V_121 . V_190 ) ,
F_64 ( V_23 -> V_121 . V_191 ) ,
F_64 ( V_23 -> V_121 . V_192 ) ,
V_23 -> V_121 . V_193 ,
V_23 -> V_121 . V_194 ,
V_23 -> V_121 . V_195 ,
V_133 -> V_20 . V_187 ,
V_133 -> V_20 . V_188 ,
V_133 -> V_20 . V_189 ,
V_133 -> V_20 . V_196 ) )
return - V_31 ;
return 0 ;
}
static struct V_197 * F_120 ( struct V_22 * V_16 ,
struct V_172 * V_173 ,
V_95 V_198 )
{
struct V_197 * V_10 = NULL ;
struct V_197 * V_199 ;
int V_200 ;
int V_201 ;
int V_61 ;
for ( V_61 = 0 ; ( V_61 < V_202 && V_173 -> V_199 [ V_61 ] ) ; V_61 ++ ) {
V_199 = V_173 -> V_199 [ V_61 ] ;
if ( V_199 -> V_203 == 0 )
continue;
V_200 = V_199 -> V_204 ;
V_201 = V_200 + ( V_199 -> V_203 - 1 ) ;
if ( V_198 >= V_200 && V_198 <= V_201 ) {
if ( ! V_10 )
V_10 = V_199 ;
else
F_29 ( & V_16 -> V_16 , L_23
L_24 , V_198 ) ;
}
}
return V_10 ;
}
static void F_121 ( struct V_205 * V_206 )
{
int V_102 ;
struct V_130 * V_164 =
F_122 ( V_206 , struct V_130 , V_207 ) ;
struct V_22 * V_116 = F_70 ( V_164 ) ;
V_102 = F_123 ( V_116 , V_164 ) ;
if ( V_102 >= 0 ) {
F_124 ( V_116 ) ;
F_125 ( V_116 ) ;
}
F_126 ( V_164 ) ;
}
int F_127 ( struct V_22 * V_16 , int V_208 )
{
int V_61 , V_38 ;
struct V_172 * V_209 = NULL ;
struct V_130 * * V_210 = NULL ;
struct V_148 * V_149 = F_81 ( V_16 -> V_58 ) ;
int V_211 , V_212 ;
if ( V_16 -> V_184 == 0 || V_208 == - 1 )
V_208 = 0 ;
else {
for ( V_61 = 0 ; V_61 < V_16 -> V_121 . V_213 ; V_61 ++ ) {
if ( V_16 -> V_173 [ V_61 ] . V_20 . V_177 ==
V_208 ) {
V_209 = & V_16 -> V_173 [ V_61 ] ;
break;
}
}
}
if ( ( ! V_209 && V_208 != 0 ) )
return - V_45 ;
if ( V_209 && V_208 == 0 )
F_52 ( & V_16 -> V_16 , L_25 ) ;
V_211 = V_212 = 0 ;
if ( V_209 ) {
V_212 = V_209 -> V_20 . V_151 ;
V_210 = F_18 ( V_212 * sizeof( * V_210 ) ,
V_11 ) ;
if ( ! V_210 )
return - V_31 ;
for (; V_211 < V_212 ; ++ V_211 ) {
V_210 [ V_211 ] = F_128 (
sizeof( struct V_130 ) ,
V_11 ) ;
if ( ! V_210 [ V_211 ] ) {
V_38 = - V_31 ;
V_214:
while ( -- V_211 >= 0 )
F_20 ( V_210 [ V_211 ] ) ;
F_20 ( V_210 ) ;
return V_38 ;
}
}
V_61 = V_16 -> V_215 - F_129 ( V_16 , V_209 ) ;
if ( V_61 < 0 )
F_52 ( & V_16 -> V_16 , L_26
L_27 ,
V_208 , - V_61 ) ;
}
V_38 = F_130 ( V_16 ) ;
if ( V_38 )
goto V_214;
if ( V_16 -> V_110 != V_155 )
F_80 ( V_16 , 1 ) ;
F_131 ( V_16 ) ;
F_90 ( V_149 -> V_158 ) ;
if ( V_16 -> V_150 && F_100 ( V_16 ) ) {
F_29 ( & V_16 -> V_16 , L_17 , V_67 ) ;
F_92 ( V_149 -> V_158 ) ;
V_38 = - V_31 ;
goto V_214;
}
V_38 = F_91 ( V_16 , V_209 , NULL , NULL ) ;
if ( V_38 < 0 ) {
if ( V_16 -> V_150 )
F_102 ( V_16 ) ;
F_92 ( V_149 -> V_158 ) ;
F_132 ( V_16 ) ;
goto V_214;
}
for ( V_61 = 0 ; V_61 < V_212 ; ++ V_61 ) {
struct V_179 * V_180 ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
V_209 -> V_152 [ V_61 ] = V_131 = V_210 [ V_61 ] ;
V_180 = V_209 -> V_216 [ V_61 ] ;
V_131 -> V_174 = V_180 -> V_174 ;
V_131 -> V_170 = V_180 -> V_170 ;
V_131 -> V_184 = ! ! F_133 ( V_149 ) ;
F_134 ( & V_180 -> V_181 ) ;
V_133 = F_99 ( V_131 , 0 ) ;
if ( ! V_133 )
V_133 = & V_131 -> V_174 [ 0 ] ;
V_131 -> V_199 =
F_120 ( V_16 , V_209 , V_133 -> V_20 . V_196 ) ;
V_131 -> V_134 = V_133 ;
F_96 ( V_16 , V_131 , true ) ;
V_131 -> V_16 . V_183 = & V_16 -> V_16 ;
V_131 -> V_16 . V_156 = NULL ;
V_131 -> V_16 . V_58 = & V_217 ;
V_131 -> V_16 . type = & V_218 ;
V_131 -> V_16 . V_219 = V_220 ;
V_131 -> V_16 . V_221 = V_16 -> V_16 . V_221 ;
V_131 -> V_16 . V_222 = V_16 -> V_16 . V_222 ;
F_135 ( & V_131 -> V_207 , F_121 ) ;
V_131 -> V_223 = - 1 ;
F_136 ( & V_131 -> V_16 ) ;
F_137 ( & V_131 -> V_16 ) ;
F_138 ( & V_131 -> V_16 , L_28 ,
V_16 -> V_58 -> V_224 , V_16 -> V_60 ,
V_208 , V_133 -> V_20 . V_196 ) ;
F_139 ( V_16 ) ;
}
F_20 ( V_210 ) ;
V_38 = F_17 ( V_16 , F_67 ( V_16 , 0 ) ,
V_176 , 0 , V_208 , 0 ,
NULL , 0 , V_129 ) ;
if ( V_38 < 0 && V_209 ) {
F_91 ( V_16 , NULL , NULL , NULL ) ;
for ( V_61 = 0 ; V_61 < V_212 ; ++ V_61 ) {
F_79 ( V_16 , V_209 -> V_152 [ V_61 ] , true ) ;
F_85 ( & V_209 -> V_152 [ V_61 ] -> V_16 ) ;
V_209 -> V_152 [ V_61 ] = NULL ;
}
V_209 = NULL ;
}
V_16 -> V_150 = V_209 ;
F_92 ( V_149 -> V_158 ) ;
if ( ! V_209 ) {
F_89 ( V_16 , V_155 ) ;
F_132 ( V_16 ) ;
return V_38 ;
}
F_89 ( V_16 , V_154 ) ;
if ( V_209 -> string == NULL &&
! ( V_16 -> V_103 & V_225 ) )
V_209 -> string = F_61 ( V_16 , V_209 -> V_20 . V_226 ) ;
F_104 ( V_16 ) ;
F_140 ( V_16 ) ;
for ( V_61 = 0 ; V_61 < V_212 ; ++ V_61 ) {
struct V_130 * V_131 = V_209 -> V_152 [ V_61 ] ;
F_10 ( & V_16 -> V_16 ,
L_29 ,
F_83 ( & V_131 -> V_16 ) , V_208 ,
V_131 -> V_134 -> V_20 . V_196 ) ;
F_141 ( & V_131 -> V_16 ) ;
V_38 = F_142 ( & V_131 -> V_16 ) ;
if ( V_38 != 0 ) {
F_29 ( & V_16 -> V_16 , L_30 ,
F_83 ( & V_131 -> V_16 ) , V_38 ) ;
continue;
}
F_69 ( V_131 ) ;
}
F_132 ( V_16 ) ;
return 0 ;
}
static void F_143 ( struct V_205 * V_227 )
{
struct V_228 * V_229 =
F_122 ( V_227 , struct V_228 , V_227 ) ;
struct V_22 * V_116 = V_229 -> V_116 ;
F_144 ( V_116 ) ;
F_28 ( & V_230 ) ;
F_145 ( & V_229 -> V_231 ) ;
F_30 ( & V_230 ) ;
if ( V_229 -> V_173 >= - 1 )
F_127 ( V_116 , V_229 -> V_173 ) ;
F_125 ( V_116 ) ;
F_112 ( V_116 ) ;
F_20 ( V_229 ) ;
}
static void F_131 ( struct V_22 * V_116 )
{
struct V_228 * V_229 ;
F_28 ( & V_230 ) ;
F_146 (req, &set_config_list, node) {
if ( V_229 -> V_116 == V_116 )
V_229 -> V_173 = - 999 ;
}
F_30 ( & V_230 ) ;
}
int F_147 ( struct V_22 * V_116 , int V_173 )
{
struct V_228 * V_229 ;
V_229 = F_18 ( sizeof( * V_229 ) , V_46 ) ;
if ( ! V_229 )
return - V_31 ;
V_229 -> V_116 = V_116 ;
V_229 -> V_173 = V_173 ;
F_135 ( & V_229 -> V_227 , F_143 ) ;
F_28 ( & V_230 ) ;
F_148 ( & V_229 -> V_231 , & V_232 ) ;
F_30 ( & V_230 ) ;
F_139 ( V_116 ) ;
F_149 ( & V_229 -> V_227 ) ;
return 0 ;
}
int F_150 ( struct V_233 * V_234 ,
struct V_130 * V_131 ,
V_95 * V_235 ,
int V_236 )
{
struct V_237 * V_238 = NULL ;
struct V_239 * V_240 = NULL ;
struct V_241 * V_242 = NULL ;
struct V_243 * V_244 = NULL ;
struct V_245 * V_20 = NULL ;
unsigned int V_246 ;
int V_247 = 0 ;
memset ( V_234 , 0x00 , sizeof( struct V_233 ) ) ;
V_234 -> V_248 = false ;
while ( V_236 > 0 ) {
V_246 = V_235 [ 0 ] ;
if ( ! V_246 ) {
F_29 ( & V_131 -> V_16 , L_31 ) ;
V_246 = 1 ;
goto V_249;
}
if ( V_235 [ 1 ] != V_250 ) {
F_29 ( & V_131 -> V_16 , L_32 ) ;
goto V_249;
}
switch ( V_235 [ 2 ] ) {
case V_251 :
if ( V_246 < sizeof( struct V_237 ) )
goto V_249;
if ( V_238 ) {
F_29 ( & V_131 -> V_16 , L_33 ) ;
goto V_249;
}
V_238 = (struct V_237 * ) V_235 ;
break;
case V_252 :
if ( V_246 < sizeof( struct V_253 ) )
goto V_249;
V_234 -> V_253 =
(struct V_253 * ) V_235 ;
break;
case V_254 :
if ( V_246 != sizeof( struct V_239 ) )
goto V_249;
if ( V_240 )
return - V_45 ;
V_240 = (struct V_239 * ) V_235 ;
break;
case V_255 :
if ( V_246 < sizeof( struct V_256 ) )
goto V_249;
V_234 -> V_256 =
(struct V_256 * ) V_235 ;
break;
case V_257 :
if ( V_246 != sizeof( struct V_241 ) )
goto V_249;
if ( V_242 )
return - V_45 ;
V_242 = (struct V_241 * ) V_235 ;
break;
case V_258 :
if ( V_246 < sizeof( struct V_259 ) )
goto V_249;
V_234 -> V_259 =
(struct V_259 * ) V_235 ;
break;
case V_260 :
if ( V_246 < sizeof( struct V_261 ) )
goto V_249;
V_234 -> V_261 =
(struct V_261 * ) V_235 ;
break;
case V_262 :
if ( V_246 < sizeof( struct V_245 * ) )
goto V_249;
if ( V_20 )
return - V_45 ;
V_20 = (struct V_245 * ) V_235 ;
break;
case V_263 :
if ( V_246 < sizeof( struct V_243 * ) )
goto V_249;
if ( V_244 )
return - V_45 ;
V_244 = (struct V_243 * ) V_235 ;
break;
case V_264 :
if ( V_246 < sizeof( struct V_265 ) )
goto V_249;
V_234 -> V_265 = (struct V_265 * ) V_235 ;
break;
case V_266 :
if ( V_246 < sizeof( struct V_267 ) )
goto V_249;
V_234 -> V_267 = (struct V_267 * ) V_235 ;
break;
case V_268 :
if ( V_246 < sizeof( struct V_269 ) )
break;
V_234 -> V_269 =
(struct V_269 * ) V_235 ;
break;
case V_270 :
V_234 -> V_248 = true ;
break;
default:
F_10 ( & V_131 -> V_16 , L_34 ,
V_235 [ 2 ] , V_246 ) ;
goto V_249;
}
V_247 ++ ;
V_249:
V_236 -= V_246 ;
V_235 += V_246 ;
}
V_234 -> V_237 = V_238 ;
V_234 -> V_239 = V_240 ;
V_234 -> V_243 = V_244 ;
V_234 -> V_245 = V_20 ;
V_234 -> V_241 = V_242 ;
return V_247 ;
}
