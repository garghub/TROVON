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
if ( ! V_53 -> V_54 [ V_61 ] || ! V_53 -> V_54 [ V_61 ] -> V_16 )
continue;
if ( V_62 ) {
V_10 = F_31 ( V_53 -> V_54 [ V_61 ] ) ;
if ( V_10 != - V_63 &&
V_10 != - V_64 &&
V_10 != - V_65 )
F_29 ( & V_53 -> V_16 -> V_16 ,
L_5 ,
V_66 , V_10 ) ;
} else if ( V_1 == V_53 -> V_54 [ V_61 ] )
V_62 = 1 ;
}
F_28 ( & V_53 -> V_56 ) ;
}
V_1 -> V_16 = NULL ;
V_53 -> V_67 += V_1 -> V_8 ;
V_53 -> V_68 -- ;
if ( ! V_53 -> V_68 )
F_2 ( & V_53 -> F_2 ) ;
F_30 ( & V_53 -> V_56 ) ;
}
int F_32 ( struct V_52 * V_53 , struct V_22 * V_16 ,
unsigned V_24 , unsigned V_69 , struct V_70 * V_71 ,
int V_72 , T_3 V_30 , T_4 V_73 )
{
int V_61 ;
int V_74 ;
int V_75 ;
if ( ! V_53 || ! V_16 || ! V_71
|| F_33 ( V_24 )
|| F_34 ( V_24 )
|| V_72 <= 0 )
return - V_45 ;
F_35 ( & V_53 -> V_56 ) ;
V_53 -> V_16 = V_16 ;
V_53 -> V_24 = V_24 ;
if ( V_16 -> V_58 -> V_76 > 0 ) {
V_75 = true ;
V_53 -> V_55 = 1 ;
} else {
V_75 = false ;
V_53 -> V_55 = V_72 ;
}
V_53 -> V_54 = F_18 ( V_53 -> V_55 * sizeof * V_53 -> V_54 , V_73 ) ;
if ( ! V_53 -> V_54 )
goto V_77;
V_74 = V_78 ;
if ( F_36 ( V_24 ) )
V_74 |= V_79 ;
F_37 (sg, sg, io->entries, i) {
struct V_1 * V_1 ;
unsigned V_28 ;
V_1 = F_15 ( 0 , V_73 ) ;
if ( ! V_1 ) {
V_53 -> V_55 = V_61 ;
goto V_77;
}
V_53 -> V_54 [ V_61 ] = V_1 ;
V_1 -> V_16 = NULL ;
V_1 -> V_24 = V_24 ;
V_1 -> V_80 = V_69 ;
V_1 -> V_81 = V_74 ;
V_1 -> F_2 = F_27 ;
V_1 -> V_4 = V_53 ;
V_1 -> V_71 = V_71 ;
if ( V_75 ) {
V_1 -> V_82 = NULL ;
V_1 -> V_83 = V_72 ;
V_28 = V_30 ;
if ( V_28 == 0 ) {
struct V_70 * V_84 ;
int V_85 ;
F_37 (sg, sg2, nents, j)
V_28 += V_84 -> V_30 ;
}
} else {
if ( ! F_38 ( F_39 ( V_71 ) ) )
V_1 -> V_82 = F_40 ( V_71 ) ;
else
V_1 -> V_82 = NULL ;
V_28 = V_71 -> V_30 ;
if ( V_30 ) {
V_28 = F_41 ( unsigned , V_28 , V_30 ) ;
V_30 -= V_28 ;
if ( V_30 == 0 )
V_53 -> V_55 = V_61 + 1 ;
}
}
V_1 -> V_21 = V_28 ;
}
V_53 -> V_54 [ -- V_61 ] -> V_81 &= ~ V_78 ;
V_53 -> V_68 = V_53 -> V_55 ;
V_53 -> V_5 = 0 ;
V_53 -> V_67 = 0 ;
F_4 ( & V_53 -> F_2 ) ;
return 0 ;
V_77:
F_26 ( V_53 ) ;
return - V_31 ;
}
void F_42 ( struct V_52 * V_53 )
{
int V_61 ;
int V_55 = V_53 -> V_55 ;
F_43 ( & V_53 -> V_56 ) ;
V_61 = 0 ;
while ( V_61 < V_55 && ! V_53 -> V_5 ) {
int V_10 ;
V_53 -> V_54 [ V_61 ] -> V_16 = V_53 -> V_16 ;
V_10 = F_5 ( V_53 -> V_54 [ V_61 ] , V_86 ) ;
F_44 ( & V_53 -> V_56 ) ;
switch ( V_10 ) {
case - V_87 :
case - V_88 :
case - V_31 :
V_53 -> V_54 [ V_61 ] -> V_16 = NULL ;
V_10 = 0 ;
F_45 () ;
break;
case 0 :
++ V_61 ;
F_46 () ;
break;
default:
V_53 -> V_54 [ V_61 ] -> V_16 = NULL ;
V_53 -> V_54 [ V_61 ] -> V_5 = V_10 ;
F_10 ( & V_53 -> V_16 -> V_16 , L_6 ,
V_66 , V_10 ) ;
F_47 ( V_53 ) ;
}
F_43 ( & V_53 -> V_56 ) ;
if ( V_10 && ( V_53 -> V_5 == 0 || V_53 -> V_5 == - V_57 ) )
V_53 -> V_5 = V_10 ;
}
V_53 -> V_68 -= V_55 - V_61 ;
if ( V_53 -> V_68 == 0 )
F_2 ( & V_53 -> F_2 ) ;
F_44 ( & V_53 -> V_56 ) ;
F_48 ( & V_53 -> F_2 ) ;
F_26 ( V_53 ) ;
}
void F_47 ( struct V_52 * V_53 )
{
unsigned long V_89 ;
F_49 ( & V_53 -> V_56 , V_89 ) ;
if ( ! V_53 -> V_5 ) {
int V_61 ;
V_53 -> V_5 = - V_57 ;
F_30 ( & V_53 -> V_56 ) ;
for ( V_61 = 0 ; V_61 < V_53 -> V_55 ; V_61 ++ ) {
int V_10 ;
if ( ! V_53 -> V_54 [ V_61 ] -> V_16 )
continue;
V_10 = F_31 ( V_53 -> V_54 [ V_61 ] ) ;
if ( V_10 != - V_63 && V_10 != - V_65 )
F_50 ( & V_53 -> V_16 -> V_16 , L_5 ,
V_66 , V_10 ) ;
}
F_28 ( & V_53 -> V_56 ) ;
}
F_51 ( & V_53 -> V_56 , V_89 ) ;
}
int F_52 ( struct V_22 * V_16 , unsigned char type ,
unsigned char V_35 , void * V_90 , int V_36 )
{
int V_61 ;
int V_91 ;
memset ( V_90 , 0 , V_36 ) ;
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
V_91 = F_17 ( V_16 , F_53 ( V_16 , 0 ) ,
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
static int F_54 ( struct V_22 * V_16 , unsigned short V_97 ,
unsigned char V_35 , void * V_90 , int V_36 )
{
int V_61 ;
int V_91 ;
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
V_91 = F_17 ( V_16 , F_53 ( V_16 , 0 ) ,
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
static void F_55 ( unsigned char * V_90 , int * V_30 )
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
static int F_56 ( struct V_22 * V_16 , unsigned int V_97 ,
unsigned int V_35 , unsigned char * V_90 )
{
int V_102 ;
if ( V_16 -> V_103 & V_104 )
V_102 = - V_105 ;
else
V_102 = F_54 ( V_16 , V_97 , V_35 , V_90 , 255 ) ;
if ( V_102 < 2 ) {
V_102 = F_54 ( V_16 , V_97 , V_35 , V_90 , 2 ) ;
if ( V_102 == 2 )
V_102 = F_54 ( V_16 , V_97 , V_35 , V_90 , V_90 [ 0 ] ) ;
}
if ( V_102 >= 2 ) {
if ( ! V_90 [ 0 ] && ! V_90 [ 1 ] )
F_55 ( V_90 , & V_102 ) ;
if ( V_90 [ 0 ] < V_102 )
V_102 = V_90 [ 0 ] ;
V_102 = V_102 - ( V_102 & 1 ) ;
}
if ( V_102 < 2 )
V_102 = ( V_102 < 0 ? V_102 : - V_45 ) ;
return V_102 ;
}
static int F_57 ( struct V_22 * V_16 , unsigned char * V_106 )
{
int V_107 ;
if ( V_16 -> V_108 )
return 0 ;
if ( V_16 -> V_109 < 0 )
return - V_99 ;
V_107 = F_56 ( V_16 , 0 , 0 , V_106 ) ;
if ( V_107 == - V_96 || ( V_107 > 0 && V_107 < 4 ) ) {
V_16 -> V_109 = 0x0409 ;
V_16 -> V_108 = 1 ;
F_29 ( & V_16 -> V_16 ,
L_7
L_8 ,
V_107 , V_16 -> V_109 ) ;
return 0 ;
}
if ( V_107 < 0 ) {
F_29 ( & V_16 -> V_16 , L_9 ,
V_107 ) ;
V_16 -> V_109 = - 1 ;
return - V_99 ;
}
V_16 -> V_109 = V_106 [ 2 ] | ( V_106 [ 3 ] << 8 ) ;
V_16 -> V_108 = 1 ;
F_10 ( & V_16 -> V_16 , L_10 ,
V_16 -> V_109 ) ;
return 0 ;
}
int F_58 ( struct V_22 * V_16 , int V_35 , char * V_90 , T_3 V_36 )
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
V_107 = F_57 ( V_16 , V_106 ) ;
if ( V_107 < 0 )
goto V_113;
V_107 = F_56 ( V_16 , V_16 -> V_109 , V_35 , V_106 ) ;
if ( V_107 < 0 )
goto V_113;
V_36 -- ;
V_107 = F_59 ( ( V_114 * ) & V_106 [ 2 ] , ( V_107 - 2 ) / 2 ,
V_115 , V_90 , V_36 ) ;
V_90 [ V_107 ] = 0 ;
if ( V_106 [ 1 ] != V_98 )
F_10 ( & V_16 -> V_16 ,
L_11 ,
V_106 [ 1 ] , V_35 , V_90 ) ;
V_113:
F_20 ( V_106 ) ;
return V_107 ;
}
char * F_60 ( struct V_22 * V_116 , int V_35 )
{
char * V_90 ;
char * V_117 = NULL ;
int V_28 ;
if ( V_35 <= 0 )
return NULL ;
V_90 = F_18 ( V_118 , V_11 ) ;
if ( V_90 ) {
V_28 = F_58 ( V_116 , V_35 , V_90 , V_118 ) ;
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
int F_61 ( struct V_22 * V_16 , unsigned int V_36 )
{
struct V_119 * V_20 ;
int V_38 ;
if ( V_36 > sizeof( * V_20 ) )
return - V_45 ;
V_20 = F_18 ( sizeof( * V_20 ) , V_11 ) ;
if ( ! V_20 )
return - V_31 ;
V_38 = F_52 ( V_16 , V_120 , 0 , V_20 , V_36 ) ;
if ( V_38 >= 0 )
memcpy ( & V_16 -> V_121 , V_20 , V_36 ) ;
F_20 ( V_20 ) ;
return V_38 ;
}
int F_62 ( struct V_22 * V_16 , int type , int V_122 , void * V_27 )
{
int V_38 ;
T_5 * V_5 = F_18 ( sizeof( * V_5 ) , V_46 ) ;
if ( ! V_5 )
return - V_31 ;
V_38 = F_17 ( V_16 , F_53 ( V_16 , 0 ) ,
V_123 , V_93 | type , 0 , V_122 , V_5 ,
sizeof( * V_5 ) , V_94 ) ;
* ( T_5 * ) V_27 = * V_5 ;
F_20 ( V_5 ) ;
return V_38 ;
}
int F_63 ( struct V_22 * V_16 , int V_24 )
{
int V_91 ;
int V_124 = F_64 ( V_24 ) ;
if ( F_36 ( V_24 ) )
V_124 |= V_93 ;
V_91 = F_17 ( V_16 , F_65 ( V_16 , 0 ) ,
V_125 , V_126 ,
V_127 , V_124 , NULL , 0 ,
V_128 ) ;
if ( V_91 < 0 )
return V_91 ;
F_66 ( V_16 , V_124 ) ;
return 0 ;
}
static int F_67 ( struct V_129 * V_130 )
{
struct V_22 * V_116 = F_68 ( V_130 ) ;
struct V_131 * V_132 = V_130 -> V_133 ;
int V_61 ;
if ( V_130 -> V_134 || V_130 -> V_135 )
return 0 ;
for ( V_61 = 0 ; V_61 < V_132 -> V_20 . V_136 ; ++ V_61 )
( void ) F_69 ( & V_130 -> V_16 , & V_132 -> V_137 [ V_61 ] , V_116 ) ;
V_130 -> V_134 = 1 ;
return 0 ;
}
static void F_70 ( struct V_129 * V_130 )
{
struct V_131 * V_132 = V_130 -> V_133 ;
int V_61 ;
if ( ! V_130 -> V_134 )
return;
for ( V_61 = 0 ; V_61 < V_132 -> V_20 . V_136 ; ++ V_61 )
F_71 ( & V_132 -> V_137 [ V_61 ] ) ;
V_130 -> V_134 = 0 ;
}
void F_72 ( struct V_22 * V_16 , unsigned int V_138 ,
bool V_139 )
{
unsigned int V_140 = V_138 & V_141 ;
struct V_44 * V_19 ;
if ( ! V_16 )
return;
if ( F_73 ( V_138 ) ) {
V_19 = V_16 -> V_142 [ V_140 ] ;
if ( V_139 )
V_16 -> V_142 [ V_140 ] = NULL ;
} else {
V_19 = V_16 -> V_143 [ V_140 ] ;
if ( V_139 )
V_16 -> V_143 [ V_140 ] = NULL ;
}
if ( V_19 ) {
V_19 -> V_144 = 0 ;
F_74 ( V_16 , V_19 ) ;
if ( V_139 )
F_75 ( V_16 , V_19 ) ;
}
}
void F_66 ( struct V_22 * V_16 , unsigned int V_138 )
{
unsigned int V_140 = V_138 & V_141 ;
struct V_44 * V_19 ;
if ( F_73 ( V_138 ) )
V_19 = V_16 -> V_142 [ V_140 ] ;
else
V_19 = V_16 -> V_143 [ V_140 ] ;
if ( V_19 )
F_76 ( V_16 , V_19 ) ;
}
void F_77 ( struct V_22 * V_16 , struct V_129 * V_130 ,
bool V_139 )
{
struct V_131 * V_132 = V_130 -> V_133 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_132 -> V_20 . V_136 ; ++ V_61 ) {
F_72 ( V_16 ,
V_132 -> V_137 [ V_61 ] . V_20 . V_145 ,
V_139 ) ;
}
}
void F_78 ( struct V_22 * V_16 , int V_146 )
{
int V_61 ;
struct V_147 * V_148 = F_79 ( V_16 -> V_58 ) ;
if ( V_16 -> V_149 ) {
for ( V_61 = 0 ; V_61 < V_16 -> V_149 -> V_20 . V_150 ; V_61 ++ )
V_16 -> V_149 -> V_151 [ V_61 ] -> V_135 = 1 ;
for ( V_61 = 0 ; V_61 < V_16 -> V_149 -> V_20 . V_150 ; V_61 ++ ) {
struct V_129 * V_151 ;
V_151 = V_16 -> V_149 -> V_151 [ V_61 ] ;
if ( ! F_80 ( & V_151 -> V_16 ) )
continue;
F_10 ( & V_16 -> V_16 , L_12 ,
F_81 ( & V_151 -> V_16 ) ) ;
F_70 ( V_151 ) ;
F_82 ( & V_151 -> V_16 ) ;
}
for ( V_61 = 0 ; V_61 < V_16 -> V_149 -> V_20 . V_150 ; V_61 ++ ) {
F_83 ( & V_16 -> V_149 -> V_151 [ V_61 ] -> V_16 ) ;
V_16 -> V_149 -> V_151 [ V_61 ] = NULL ;
}
V_16 -> V_149 = NULL ;
if ( V_16 -> V_110 == V_152 )
F_84 ( V_16 , V_153 ) ;
}
F_10 ( & V_16 -> V_16 , L_13 , V_66 ,
V_146 ? L_14 : L_15 ) ;
if ( V_148 -> V_154 -> V_155 ) {
for ( V_61 = V_146 ; V_61 < 16 ; ++ V_61 ) {
F_72 ( V_16 , V_61 , false ) ;
F_72 ( V_16 , V_61 + V_93 , false ) ;
}
F_85 ( V_16 , NULL , NULL , NULL ) ;
}
for ( V_61 = V_146 ; V_61 < 16 ; ++ V_61 ) {
F_72 ( V_16 , V_61 , true ) ;
F_72 ( V_16 , V_61 + V_93 , true ) ;
}
}
void F_86 ( struct V_22 * V_16 , struct V_44 * V_19 ,
bool V_156 )
{
int V_140 = F_11 ( & V_19 -> V_20 ) ;
int V_157 = F_87 ( & V_19 -> V_20 ) ;
int V_158 = F_88 ( & V_19 -> V_20 ) ;
if ( V_156 )
F_76 ( V_16 , V_19 ) ;
if ( V_157 || V_158 )
V_16 -> V_142 [ V_140 ] = V_19 ;
if ( ! V_157 || V_158 )
V_16 -> V_143 [ V_140 ] = V_19 ;
V_19 -> V_144 = 1 ;
}
void F_89 ( struct V_22 * V_16 ,
struct V_129 * V_130 , bool V_159 )
{
struct V_131 * V_132 = V_130 -> V_133 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_132 -> V_20 . V_136 ; ++ V_61 )
F_86 ( V_16 , & V_132 -> V_137 [ V_61 ] , V_159 ) ;
}
int F_90 ( struct V_22 * V_16 , int V_151 , int V_160 )
{
struct V_129 * V_161 ;
struct V_131 * V_132 ;
struct V_147 * V_148 = F_79 ( V_16 -> V_58 ) ;
int V_38 ;
int V_162 = 0 ;
unsigned int V_138 ;
unsigned int V_24 ;
if ( V_16 -> V_110 == V_111 )
return - V_112 ;
V_161 = F_91 ( V_16 , V_151 ) ;
if ( ! V_161 ) {
F_10 ( & V_16 -> V_16 , L_16 ,
V_151 ) ;
return - V_45 ;
}
if ( V_161 -> V_135 )
return - V_64 ;
V_132 = F_92 ( V_161 , V_160 ) ;
if ( ! V_132 ) {
F_50 ( & V_16 -> V_16 , L_17 ,
V_160 ) ;
return - V_45 ;
}
F_93 ( V_148 -> V_163 ) ;
V_38 = F_85 ( V_16 , NULL , V_161 -> V_133 , V_132 ) ;
if ( V_38 < 0 ) {
F_94 ( & V_16 -> V_16 , L_18 ,
V_160 ) ;
F_95 ( V_148 -> V_163 ) ;
return V_38 ;
}
if ( V_16 -> V_103 & V_164 )
V_38 = - V_99 ;
else
V_38 = F_17 ( V_16 , F_65 ( V_16 , 0 ) ,
V_165 , V_166 ,
V_160 , V_151 , NULL , 0 , 5000 ) ;
if ( V_38 == - V_99 && V_161 -> V_167 == 1 ) {
F_10 ( & V_16 -> V_16 ,
L_19 ,
V_151 , V_160 ) ;
V_162 = 1 ;
} else if ( V_38 < 0 ) {
F_85 ( V_16 , NULL , V_132 , V_161 -> V_133 ) ;
F_95 ( V_148 -> V_163 ) ;
return V_38 ;
}
F_95 ( V_148 -> V_163 ) ;
if ( V_161 -> V_133 != V_132 ) {
F_70 ( V_161 ) ;
F_96 ( V_161 ) ;
}
F_77 ( V_16 , V_161 , true ) ;
V_161 -> V_133 = V_132 ;
if ( V_162 ) {
int V_61 ;
for ( V_61 = 0 ; V_61 < V_132 -> V_20 . V_136 ; V_61 ++ ) {
V_138 = V_132 -> V_137 [ V_61 ] . V_20 . V_145 ;
V_24 = F_97 ( V_16 ,
V_141 & V_138 ) |
( F_73 ( V_138 ) ?
V_168 : V_93 ) ;
F_63 ( V_16 , V_24 ) ;
}
}
F_89 ( V_16 , V_161 , true ) ;
if ( F_80 ( & V_161 -> V_16 ) ) {
F_98 ( V_161 ) ;
F_67 ( V_161 ) ;
}
return 0 ;
}
int F_99 ( struct V_22 * V_16 )
{
int V_61 , V_10 ;
struct V_169 * V_170 ;
struct V_147 * V_148 = F_79 ( V_16 -> V_58 ) ;
if ( V_16 -> V_110 == V_111 )
return - V_112 ;
for ( V_61 = 1 ; V_61 < 16 ; ++ V_61 ) {
F_72 ( V_16 , V_61 , true ) ;
F_72 ( V_16 , V_61 + V_93 , true ) ;
}
V_170 = V_16 -> V_149 ;
V_10 = 0 ;
F_93 ( V_148 -> V_163 ) ;
for ( V_61 = 0 ; V_61 < V_170 -> V_20 . V_150 ; V_61 ++ ) {
struct V_129 * V_130 = V_170 -> V_151 [ V_61 ] ;
struct V_131 * V_132 ;
V_132 = F_92 ( V_130 , 0 ) ;
if ( ! V_132 )
V_132 = & V_130 -> V_171 [ 0 ] ;
if ( V_132 != V_130 -> V_133 )
V_10 = F_85 ( V_16 , NULL ,
V_130 -> V_133 , V_132 ) ;
if ( V_10 < 0 )
break;
}
if ( V_10 < 0 ) {
V_172:
for ( V_61 -- ; V_61 >= 0 ; V_61 -- ) {
struct V_129 * V_130 = V_170 -> V_151 [ V_61 ] ;
struct V_131 * V_132 ;
V_132 = F_92 ( V_130 , 0 ) ;
if ( ! V_132 )
V_132 = & V_130 -> V_171 [ 0 ] ;
if ( V_132 != V_130 -> V_133 )
F_85 ( V_16 , NULL ,
V_132 , V_130 -> V_133 ) ;
}
F_95 ( V_148 -> V_163 ) ;
return V_10 ;
}
V_10 = F_17 ( V_16 , F_65 ( V_16 , 0 ) ,
V_173 , 0 ,
V_170 -> V_20 . V_174 , 0 ,
NULL , 0 , V_128 ) ;
if ( V_10 < 0 )
goto V_172;
F_95 ( V_148 -> V_163 ) ;
for ( V_61 = 0 ; V_61 < V_170 -> V_20 . V_150 ; V_61 ++ ) {
struct V_129 * V_130 = V_170 -> V_151 [ V_61 ] ;
struct V_131 * V_132 ;
V_132 = F_92 ( V_130 , 0 ) ;
if ( ! V_132 )
V_132 = & V_130 -> V_171 [ 0 ] ;
if ( V_132 != V_130 -> V_133 ) {
F_70 ( V_130 ) ;
F_96 ( V_130 ) ;
}
V_130 -> V_133 = V_132 ;
F_89 ( V_16 , V_130 , true ) ;
if ( F_80 ( & V_130 -> V_16 ) ) {
F_98 ( V_130 ) ;
F_67 ( V_130 ) ;
}
}
return 0 ;
}
static void F_100 ( struct V_175 * V_16 )
{
struct V_129 * V_130 = F_101 ( V_16 ) ;
struct V_176 * V_177 =
F_102 ( V_130 -> V_171 ) ;
F_103 ( & V_177 -> V_178 , V_179 ) ;
F_20 ( V_130 ) ;
}
static int F_104 ( struct V_175 * V_16 , struct V_180 * V_181 )
{
struct V_22 * V_23 ;
struct V_129 * V_130 ;
struct V_131 * V_132 ;
V_130 = F_101 ( V_16 ) ;
V_23 = F_68 ( V_130 ) ;
V_132 = V_130 -> V_133 ;
if ( F_105 ( V_181 , L_20 ,
V_132 -> V_20 . V_182 ,
V_132 -> V_20 . V_183 ,
V_132 -> V_20 . V_184 ) )
return - V_31 ;
if ( F_105 ( V_181 ,
L_21
L_22 ,
F_106 ( V_23 -> V_121 . V_185 ) ,
F_106 ( V_23 -> V_121 . V_186 ) ,
F_106 ( V_23 -> V_121 . V_187 ) ,
V_23 -> V_121 . V_188 ,
V_23 -> V_121 . V_189 ,
V_23 -> V_121 . V_190 ,
V_132 -> V_20 . V_182 ,
V_132 -> V_20 . V_183 ,
V_132 -> V_20 . V_184 ) )
return - V_31 ;
return 0 ;
}
static int F_104 ( struct V_175 * V_16 , struct V_180 * V_181 )
{
return - V_64 ;
}
static struct V_191 * F_107 ( struct V_22 * V_16 ,
struct V_169 * V_170 ,
V_95 V_192 )
{
struct V_191 * V_10 = NULL ;
struct V_191 * V_193 ;
int V_194 ;
int V_195 ;
int V_61 ;
for ( V_61 = 0 ; ( V_61 < V_196 && V_170 -> V_193 [ V_61 ] ) ; V_61 ++ ) {
V_193 = V_170 -> V_193 [ V_61 ] ;
if ( V_193 -> V_197 == 0 )
continue;
V_194 = V_193 -> V_198 ;
V_195 = V_194 + ( V_193 -> V_197 - 1 ) ;
if ( V_192 >= V_194 && V_192 <= V_195 ) {
if ( ! V_10 )
V_10 = V_193 ;
else
F_29 ( & V_16 -> V_16 , L_23
L_24 , V_192 ) ;
}
}
return V_10 ;
}
static void F_108 ( struct V_199 * V_200 )
{
int V_102 ;
struct V_129 * V_161 =
F_109 ( V_200 , struct V_129 , V_201 ) ;
struct V_22 * V_116 = F_68 ( V_161 ) ;
V_102 = F_110 ( V_116 , V_161 ) ;
if ( V_102 >= 0 ) {
V_161 -> V_202 = 1 ;
F_111 ( V_116 ) ;
V_161 -> V_202 = 0 ;
F_112 ( V_116 ) ;
}
}
int F_113 ( struct V_22 * V_16 , int V_203 )
{
int V_61 , V_38 ;
struct V_169 * V_204 = NULL ;
struct V_129 * * V_205 = NULL ;
struct V_147 * V_148 = F_79 ( V_16 -> V_58 ) ;
int V_206 , V_207 ;
if ( V_16 -> V_208 == 0 || V_203 == - 1 )
V_203 = 0 ;
else {
for ( V_61 = 0 ; V_61 < V_16 -> V_121 . V_209 ; V_61 ++ ) {
if ( V_16 -> V_170 [ V_61 ] . V_20 . V_174 ==
V_203 ) {
V_204 = & V_16 -> V_170 [ V_61 ] ;
break;
}
}
}
if ( ( ! V_204 && V_203 != 0 ) )
return - V_45 ;
if ( V_204 && V_203 == 0 )
F_50 ( & V_16 -> V_16 , L_25 ) ;
V_206 = V_207 = 0 ;
if ( V_204 ) {
V_207 = V_204 -> V_20 . V_150 ;
V_205 = F_18 ( V_207 * sizeof( * V_205 ) ,
V_11 ) ;
if ( ! V_205 ) {
F_29 ( & V_16 -> V_16 , L_26 ) ;
return - V_31 ;
}
for (; V_206 < V_207 ; ++ V_206 ) {
V_205 [ V_206 ] = F_114 (
sizeof( struct V_129 ) ,
V_11 ) ;
if ( ! V_205 [ V_206 ] ) {
F_29 ( & V_16 -> V_16 , L_26 ) ;
V_38 = - V_31 ;
V_210:
while ( -- V_206 >= 0 )
F_20 ( V_205 [ V_206 ] ) ;
F_20 ( V_205 ) ;
return V_38 ;
}
}
V_61 = V_16 -> V_211 - V_204 -> V_20 . V_212 * 2 ;
if ( V_61 < 0 )
F_50 ( & V_16 -> V_16 , L_27
L_28 ,
V_203 , - V_61 ) ;
}
V_38 = F_115 ( V_16 ) ;
if ( V_38 )
goto V_210;
F_93 ( V_148 -> V_163 ) ;
if ( V_16 -> V_110 != V_153 )
F_78 ( V_16 , 1 ) ;
F_116 ( V_16 ) ;
V_38 = F_85 ( V_16 , V_204 , NULL , NULL ) ;
if ( V_38 < 0 ) {
F_95 ( V_148 -> V_163 ) ;
F_117 ( V_16 ) ;
goto V_210;
}
V_38 = F_17 ( V_16 , F_65 ( V_16 , 0 ) ,
V_173 , 0 , V_203 , 0 ,
NULL , 0 , V_128 ) ;
if ( V_38 < 0 ) {
V_204 = NULL ;
}
V_16 -> V_149 = V_204 ;
if ( ! V_204 ) {
F_84 ( V_16 , V_153 ) ;
F_85 ( V_16 , NULL , NULL , NULL ) ;
F_95 ( V_148 -> V_163 ) ;
F_117 ( V_16 ) ;
goto V_210;
}
F_95 ( V_148 -> V_163 ) ;
F_84 ( V_16 , V_152 ) ;
for ( V_61 = 0 ; V_61 < V_207 ; ++ V_61 ) {
struct V_176 * V_177 ;
struct V_129 * V_130 ;
struct V_131 * V_132 ;
V_204 -> V_151 [ V_61 ] = V_130 = V_205 [ V_61 ] ;
V_177 = V_204 -> V_213 [ V_61 ] ;
V_130 -> V_171 = V_177 -> V_171 ;
V_130 -> V_167 = V_177 -> V_167 ;
V_130 -> V_193 = F_107 ( V_16 , V_204 , V_61 ) ;
F_118 ( & V_177 -> V_178 ) ;
V_132 = F_92 ( V_130 , 0 ) ;
if ( ! V_132 )
V_132 = & V_130 -> V_171 [ 0 ] ;
V_130 -> V_133 = V_132 ;
F_89 ( V_16 , V_130 , true ) ;
V_130 -> V_16 . V_214 = & V_16 -> V_16 ;
V_130 -> V_16 . V_154 = NULL ;
V_130 -> V_16 . V_58 = & V_215 ;
V_130 -> V_16 . type = & V_216 ;
V_130 -> V_16 . V_217 = V_218 ;
V_130 -> V_16 . V_219 = V_16 -> V_16 . V_219 ;
F_119 ( & V_130 -> V_201 , F_108 ) ;
V_130 -> V_220 = - 1 ;
F_120 ( & V_130 -> V_16 ) ;
F_121 ( & V_130 -> V_16 ) ;
F_122 ( & V_130 -> V_16 , L_29 ,
V_16 -> V_58 -> V_221 , V_16 -> V_60 ,
V_203 , V_132 -> V_20 . V_222 ) ;
}
F_20 ( V_205 ) ;
if ( V_204 -> string == NULL &&
! ( V_16 -> V_103 & V_223 ) )
V_204 -> string = F_60 ( V_16 , V_204 -> V_20 . V_224 ) ;
for ( V_61 = 0 ; V_61 < V_207 ; ++ V_61 ) {
struct V_129 * V_130 = V_204 -> V_151 [ V_61 ] ;
F_10 ( & V_16 -> V_16 ,
L_30 ,
F_81 ( & V_130 -> V_16 ) , V_203 ,
V_130 -> V_133 -> V_20 . V_222 ) ;
F_123 ( & V_130 -> V_16 ) ;
V_38 = F_124 ( & V_130 -> V_16 ) ;
if ( V_38 != 0 ) {
F_29 ( & V_16 -> V_16 , L_31 ,
F_81 ( & V_130 -> V_16 ) , V_38 ) ;
continue;
}
F_67 ( V_130 ) ;
}
F_117 ( V_16 ) ;
return 0 ;
}
static void F_125 ( struct V_199 * V_225 )
{
struct V_226 * V_227 =
F_109 ( V_225 , struct V_226 , V_225 ) ;
struct V_22 * V_116 = V_227 -> V_116 ;
F_126 ( V_116 ) ;
F_28 ( & V_228 ) ;
F_127 ( & V_227 -> V_229 ) ;
F_30 ( & V_228 ) ;
if ( V_227 -> V_170 >= - 1 )
F_113 ( V_116 , V_227 -> V_170 ) ;
F_112 ( V_116 ) ;
F_128 ( V_116 ) ;
F_20 ( V_227 ) ;
}
static void F_116 ( struct V_22 * V_116 )
{
struct V_226 * V_227 ;
F_28 ( & V_228 ) ;
F_129 (req, &set_config_list, node) {
if ( V_227 -> V_116 == V_116 )
V_227 -> V_170 = - 999 ;
}
F_30 ( & V_228 ) ;
}
int F_130 ( struct V_22 * V_116 , int V_170 )
{
struct V_226 * V_227 ;
V_227 = F_18 ( sizeof( * V_227 ) , V_46 ) ;
if ( ! V_227 )
return - V_31 ;
V_227 -> V_116 = V_116 ;
V_227 -> V_170 = V_170 ;
F_119 ( & V_227 -> V_225 , F_125 ) ;
F_28 ( & V_228 ) ;
F_131 ( & V_227 -> V_229 , & V_230 ) ;
F_30 ( & V_228 ) ;
F_132 ( V_116 ) ;
F_133 ( & V_227 -> V_225 ) ;
return 0 ;
}
