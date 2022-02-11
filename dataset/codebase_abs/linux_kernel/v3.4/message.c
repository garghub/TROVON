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
int F_32 ( struct V_52 * V_53 , struct V_22 * V_16 ,
unsigned V_24 , unsigned V_70 , struct V_71 * V_72 ,
int V_73 , T_3 V_30 , T_4 V_74 )
{
int V_61 ;
int V_75 ;
int V_76 ;
if ( ! V_53 || ! V_16 || ! V_72
|| F_33 ( V_24 )
|| F_34 ( V_24 )
|| V_73 <= 0 )
return - V_45 ;
F_35 ( & V_53 -> V_56 ) ;
V_53 -> V_16 = V_16 ;
V_53 -> V_24 = V_24 ;
if ( V_16 -> V_58 -> V_77 > 0 ) {
V_76 = true ;
V_53 -> V_55 = 1 ;
} else {
V_76 = false ;
V_53 -> V_55 = V_73 ;
}
V_53 -> V_54 = F_18 ( V_53 -> V_55 * sizeof * V_53 -> V_54 , V_74 ) ;
if ( ! V_53 -> V_54 )
goto V_78;
V_75 = V_79 ;
if ( F_36 ( V_24 ) )
V_75 |= V_80 ;
F_37 (sg, sg, io->entries, i) {
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
F_37 (sg, sg2, nents, j)
V_28 += V_85 -> V_30 ;
}
} else {
if ( ! F_38 ( F_39 ( V_72 ) ) )
V_1 -> V_83 = F_40 ( V_72 ) ;
else
V_1 -> V_83 = NULL ;
V_28 = V_72 -> V_30 ;
if ( V_30 ) {
V_28 = F_41 ( T_3 , V_28 , V_30 ) ;
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
void F_42 ( struct V_52 * V_53 )
{
int V_61 ;
int V_55 = V_53 -> V_55 ;
F_43 ( & V_53 -> V_56 ) ;
V_61 = 0 ;
while ( V_61 < V_55 && ! V_53 -> V_5 ) {
int V_10 ;
V_53 -> V_54 [ V_61 ] -> V_16 = V_53 -> V_16 ;
V_10 = F_5 ( V_53 -> V_54 [ V_61 ] , V_87 ) ;
F_44 ( & V_53 -> V_56 ) ;
switch ( V_10 ) {
case - V_88 :
case - V_89 :
case - V_31 :
V_10 = 0 ;
F_45 () ;
break;
case 0 :
++ V_61 ;
F_46 () ;
break;
default:
V_53 -> V_54 [ V_61 ] -> V_5 = V_10 ;
F_10 ( & V_53 -> V_16 -> V_16 , L_6 ,
V_67 , V_10 ) ;
F_47 ( V_53 ) ;
}
F_43 ( & V_53 -> V_56 ) ;
if ( V_10 && ( V_53 -> V_5 == 0 || V_53 -> V_5 == - V_57 ) )
V_53 -> V_5 = V_10 ;
}
V_53 -> V_69 -= V_55 - V_61 ;
if ( V_53 -> V_69 == 0 )
F_2 ( & V_53 -> F_2 ) ;
F_44 ( & V_53 -> V_56 ) ;
F_48 ( & V_53 -> F_2 ) ;
F_26 ( V_53 ) ;
}
void F_47 ( struct V_52 * V_53 )
{
unsigned long V_90 ;
F_49 ( & V_53 -> V_56 , V_90 ) ;
if ( ! V_53 -> V_5 ) {
int V_61 ;
V_53 -> V_5 = - V_57 ;
F_30 ( & V_53 -> V_56 ) ;
for ( V_61 = 0 ; V_61 < V_53 -> V_55 ; V_61 ++ ) {
int V_10 ;
if ( ! V_53 -> V_54 [ V_61 ] -> V_16 )
continue;
V_10 = F_31 ( V_53 -> V_54 [ V_61 ] ) ;
if ( V_10 != - V_63
&& V_10 != - V_64
&& V_10 != - V_65
&& V_10 != - V_66 )
F_50 ( & V_53 -> V_16 -> V_16 , L_5 ,
V_67 , V_10 ) ;
}
F_28 ( & V_53 -> V_56 ) ;
}
F_51 ( & V_53 -> V_56 , V_90 ) ;
}
int F_52 ( struct V_22 * V_16 , unsigned char type ,
unsigned char V_35 , void * V_91 , int V_36 )
{
int V_61 ;
int V_92 ;
memset ( V_91 , 0 , V_36 ) ;
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
V_92 = F_17 ( V_16 , F_53 ( V_16 , 0 ) ,
V_93 , V_94 ,
( type << 8 ) + V_35 , 0 , V_91 , V_36 ,
V_95 ) ;
if ( V_92 <= 0 && V_92 != - V_15 )
continue;
if ( V_92 > 1 && ( ( V_96 * ) V_91 ) [ 1 ] != type ) {
V_92 = - V_97 ;
continue;
}
break;
}
return V_92 ;
}
static int F_54 ( struct V_22 * V_16 , unsigned short V_98 ,
unsigned char V_35 , void * V_91 , int V_36 )
{
int V_61 ;
int V_92 ;
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
V_92 = F_17 ( V_16 , F_53 ( V_16 , 0 ) ,
V_93 , V_94 ,
( V_99 << 8 ) + V_35 , V_98 , V_91 , V_36 ,
V_95 ) ;
if ( V_92 == 0 || V_92 == - V_100 )
continue;
if ( V_92 > 1 && ( ( V_96 * ) V_91 ) [ 1 ] != V_99 ) {
V_92 = - V_97 ;
continue;
}
break;
}
return V_92 ;
}
static void F_55 ( unsigned char * V_91 , int * V_30 )
{
int V_101 , V_102 = * V_30 ;
for ( V_101 = 2 ; V_101 + 1 < V_102 ; V_101 += 2 )
if ( ! isprint ( V_91 [ V_101 ] ) || V_91 [ V_101 + 1 ] )
break;
if ( V_101 > 2 ) {
V_91 [ 0 ] = V_101 ;
* V_30 = V_101 ;
}
}
static int F_56 ( struct V_22 * V_16 , unsigned int V_98 ,
unsigned int V_35 , unsigned char * V_91 )
{
int V_103 ;
if ( V_16 -> V_104 & V_105 )
V_103 = - V_106 ;
else
V_103 = F_54 ( V_16 , V_98 , V_35 , V_91 , 255 ) ;
if ( V_103 < 2 ) {
V_103 = F_54 ( V_16 , V_98 , V_35 , V_91 , 2 ) ;
if ( V_103 == 2 )
V_103 = F_54 ( V_16 , V_98 , V_35 , V_91 , V_91 [ 0 ] ) ;
}
if ( V_103 >= 2 ) {
if ( ! V_91 [ 0 ] && ! V_91 [ 1 ] )
F_55 ( V_91 , & V_103 ) ;
if ( V_91 [ 0 ] < V_103 )
V_103 = V_91 [ 0 ] ;
V_103 = V_103 - ( V_103 & 1 ) ;
}
if ( V_103 < 2 )
V_103 = ( V_103 < 0 ? V_103 : - V_45 ) ;
return V_103 ;
}
static int F_57 ( struct V_22 * V_16 , unsigned char * V_107 )
{
int V_108 ;
if ( V_16 -> V_109 )
return 0 ;
if ( V_16 -> V_110 < 0 )
return - V_100 ;
V_108 = F_56 ( V_16 , 0 , 0 , V_107 ) ;
if ( V_108 == - V_97 || ( V_108 > 0 && V_108 < 4 ) ) {
V_16 -> V_110 = 0x0409 ;
V_16 -> V_109 = 1 ;
F_29 ( & V_16 -> V_16 ,
L_7
L_8 ,
V_108 , V_16 -> V_110 ) ;
return 0 ;
}
if ( V_108 < 0 ) {
F_29 ( & V_16 -> V_16 , L_9 ,
V_108 ) ;
V_16 -> V_110 = - 1 ;
return - V_100 ;
}
V_16 -> V_110 = V_107 [ 2 ] | ( V_107 [ 3 ] << 8 ) ;
V_16 -> V_109 = 1 ;
F_10 ( & V_16 -> V_16 , L_10 ,
V_16 -> V_110 ) ;
return 0 ;
}
int F_58 ( struct V_22 * V_16 , int V_35 , char * V_91 , T_3 V_36 )
{
unsigned char * V_107 ;
int V_108 ;
if ( V_16 -> V_111 == V_112 )
return - V_113 ;
if ( V_36 <= 0 || ! V_91 || ! V_35 )
return - V_45 ;
V_91 [ 0 ] = 0 ;
V_107 = F_18 ( 256 , V_11 ) ;
if ( ! V_107 )
return - V_31 ;
V_108 = F_57 ( V_16 , V_107 ) ;
if ( V_108 < 0 )
goto V_114;
V_108 = F_56 ( V_16 , V_16 -> V_110 , V_35 , V_107 ) ;
if ( V_108 < 0 )
goto V_114;
V_36 -- ;
V_108 = F_59 ( ( V_115 * ) & V_107 [ 2 ] , ( V_108 - 2 ) / 2 ,
V_116 , V_91 , V_36 ) ;
V_91 [ V_108 ] = 0 ;
if ( V_107 [ 1 ] != V_99 )
F_10 ( & V_16 -> V_16 ,
L_11 ,
V_107 [ 1 ] , V_35 , V_91 ) ;
V_114:
F_20 ( V_107 ) ;
return V_108 ;
}
char * F_60 ( struct V_22 * V_117 , int V_35 )
{
char * V_91 ;
char * V_118 = NULL ;
int V_28 ;
if ( V_35 <= 0 )
return NULL ;
V_91 = F_18 ( V_119 , V_11 ) ;
if ( V_91 ) {
V_28 = F_58 ( V_117 , V_35 , V_91 , V_119 ) ;
if ( V_28 > 0 ) {
V_118 = F_18 ( ++ V_28 , V_11 ) ;
if ( ! V_118 )
return V_91 ;
memcpy ( V_118 , V_91 , V_28 ) ;
}
F_20 ( V_91 ) ;
}
return V_118 ;
}
int F_61 ( struct V_22 * V_16 , unsigned int V_36 )
{
struct V_120 * V_20 ;
int V_38 ;
if ( V_36 > sizeof( * V_20 ) )
return - V_45 ;
V_20 = F_18 ( sizeof( * V_20 ) , V_11 ) ;
if ( ! V_20 )
return - V_31 ;
V_38 = F_52 ( V_16 , V_121 , 0 , V_20 , V_36 ) ;
if ( V_38 >= 0 )
memcpy ( & V_16 -> V_122 , V_20 , V_36 ) ;
F_20 ( V_20 ) ;
return V_38 ;
}
int F_62 ( struct V_22 * V_16 , int type , int V_123 , void * V_27 )
{
int V_38 ;
T_5 * V_5 = F_18 ( sizeof( * V_5 ) , V_46 ) ;
if ( ! V_5 )
return - V_31 ;
V_38 = F_17 ( V_16 , F_53 ( V_16 , 0 ) ,
V_124 , V_94 | type , 0 , V_123 , V_5 ,
sizeof( * V_5 ) , V_95 ) ;
* ( T_5 * ) V_27 = * V_5 ;
F_20 ( V_5 ) ;
return V_38 ;
}
int F_63 ( struct V_22 * V_16 , int V_24 )
{
int V_92 ;
int V_125 = F_64 ( V_24 ) ;
if ( F_36 ( V_24 ) )
V_125 |= V_94 ;
V_92 = F_17 ( V_16 , F_65 ( V_16 , 0 ) ,
V_126 , V_127 ,
V_128 , V_125 , NULL , 0 ,
V_129 ) ;
if ( V_92 < 0 )
return V_92 ;
F_66 ( V_16 , V_125 ) ;
return 0 ;
}
static int F_67 ( struct V_130 * V_131 )
{
struct V_22 * V_117 = F_68 ( V_131 ) ;
struct V_132 * V_133 = V_131 -> V_134 ;
int V_61 ;
if ( V_131 -> V_135 || V_131 -> V_136 )
return 0 ;
for ( V_61 = 0 ; V_61 < V_133 -> V_20 . V_137 ; ++ V_61 )
( void ) F_69 ( & V_131 -> V_16 , & V_133 -> V_138 [ V_61 ] , V_117 ) ;
V_131 -> V_135 = 1 ;
return 0 ;
}
static void F_70 ( struct V_130 * V_131 )
{
struct V_132 * V_133 = V_131 -> V_134 ;
int V_61 ;
if ( ! V_131 -> V_135 )
return;
for ( V_61 = 0 ; V_61 < V_133 -> V_20 . V_137 ; ++ V_61 )
F_71 ( & V_133 -> V_138 [ V_61 ] ) ;
V_131 -> V_135 = 0 ;
}
void F_72 ( struct V_22 * V_16 , unsigned int V_139 ,
bool V_140 )
{
unsigned int V_141 = V_139 & V_142 ;
struct V_44 * V_19 ;
if ( ! V_16 )
return;
if ( F_73 ( V_139 ) ) {
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
F_74 ( V_16 , V_19 ) ;
if ( V_140 )
F_75 ( V_16 , V_19 ) ;
}
}
void F_66 ( struct V_22 * V_16 , unsigned int V_139 )
{
unsigned int V_141 = V_139 & V_142 ;
struct V_44 * V_19 ;
if ( F_73 ( V_139 ) )
V_19 = V_16 -> V_143 [ V_141 ] ;
else
V_19 = V_16 -> V_144 [ V_141 ] ;
if ( V_19 )
F_76 ( V_16 , V_19 ) ;
}
void F_77 ( struct V_22 * V_16 , struct V_130 * V_131 ,
bool V_140 )
{
struct V_132 * V_133 = V_131 -> V_134 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_133 -> V_20 . V_137 ; ++ V_61 ) {
F_72 ( V_16 ,
V_133 -> V_138 [ V_61 ] . V_20 . V_146 ,
V_140 ) ;
}
}
void F_78 ( struct V_22 * V_16 , int V_147 )
{
int V_61 ;
struct V_148 * V_149 = F_79 ( V_16 -> V_58 ) ;
if ( V_16 -> V_150 ) {
for ( V_61 = 0 ; V_61 < V_16 -> V_150 -> V_20 . V_151 ; V_61 ++ )
V_16 -> V_150 -> V_152 [ V_61 ] -> V_136 = 1 ;
for ( V_61 = 0 ; V_61 < V_16 -> V_150 -> V_20 . V_151 ; V_61 ++ ) {
struct V_130 * V_152 ;
V_152 = V_16 -> V_150 -> V_152 [ V_61 ] ;
if ( ! F_80 ( & V_152 -> V_16 ) )
continue;
F_10 ( & V_16 -> V_16 , L_12 ,
F_81 ( & V_152 -> V_16 ) ) ;
F_70 ( V_152 ) ;
F_82 ( & V_152 -> V_16 ) ;
}
for ( V_61 = 0 ; V_61 < V_16 -> V_150 -> V_20 . V_151 ; V_61 ++ ) {
F_83 ( & V_16 -> V_150 -> V_152 [ V_61 ] -> V_16 ) ;
V_16 -> V_150 -> V_152 [ V_61 ] = NULL ;
}
V_16 -> V_150 = NULL ;
if ( V_16 -> V_111 == V_153 )
F_84 ( V_16 , V_154 ) ;
}
F_10 ( & V_16 -> V_16 , L_13 , V_67 ,
V_147 ? L_14 : L_15 ) ;
if ( V_149 -> V_155 -> V_156 ) {
for ( V_61 = V_147 ; V_61 < 16 ; ++ V_61 ) {
F_72 ( V_16 , V_61 , false ) ;
F_72 ( V_16 , V_61 + V_94 , false ) ;
}
F_85 ( V_149 -> V_157 ) ;
F_86 ( V_16 , NULL , NULL , NULL ) ;
F_87 ( V_149 -> V_157 ) ;
}
for ( V_61 = V_147 ; V_61 < 16 ; ++ V_61 ) {
F_72 ( V_16 , V_61 , true ) ;
F_72 ( V_16 , V_61 + V_94 , true ) ;
}
}
void F_88 ( struct V_22 * V_16 , struct V_44 * V_19 ,
bool V_158 )
{
int V_141 = F_11 ( & V_19 -> V_20 ) ;
int V_159 = F_89 ( & V_19 -> V_20 ) ;
int V_160 = F_90 ( & V_19 -> V_20 ) ;
if ( V_158 )
F_76 ( V_16 , V_19 ) ;
if ( V_159 || V_160 )
V_16 -> V_143 [ V_141 ] = V_19 ;
if ( ! V_159 || V_160 )
V_16 -> V_144 [ V_141 ] = V_19 ;
V_19 -> V_145 = 1 ;
}
void F_91 ( struct V_22 * V_16 ,
struct V_130 * V_131 , bool V_161 )
{
struct V_132 * V_133 = V_131 -> V_134 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_133 -> V_20 . V_137 ; ++ V_61 )
F_88 ( V_16 , & V_133 -> V_138 [ V_61 ] , V_161 ) ;
}
int F_92 ( struct V_22 * V_16 , int V_152 , int V_162 )
{
struct V_130 * V_163 ;
struct V_132 * V_133 ;
struct V_148 * V_149 = F_79 ( V_16 -> V_58 ) ;
int V_38 ;
int V_164 = 0 ;
unsigned int V_139 ;
unsigned int V_24 ;
if ( V_16 -> V_111 == V_112 )
return - V_113 ;
V_163 = F_93 ( V_16 , V_152 ) ;
if ( ! V_163 ) {
F_10 ( & V_16 -> V_16 , L_16 ,
V_152 ) ;
return - V_45 ;
}
if ( V_163 -> V_136 )
return - V_64 ;
V_133 = F_94 ( V_163 , V_162 ) ;
if ( ! V_133 ) {
F_50 ( & V_16 -> V_16 , L_17 ,
V_162 ) ;
return - V_45 ;
}
F_85 ( V_149 -> V_157 ) ;
V_38 = F_86 ( V_16 , NULL , V_163 -> V_134 , V_133 ) ;
if ( V_38 < 0 ) {
F_95 ( & V_16 -> V_16 , L_18 ,
V_162 ) ;
F_87 ( V_149 -> V_157 ) ;
return V_38 ;
}
if ( V_16 -> V_104 & V_165 )
V_38 = - V_100 ;
else
V_38 = F_17 ( V_16 , F_65 ( V_16 , 0 ) ,
V_166 , V_167 ,
V_162 , V_152 , NULL , 0 , 5000 ) ;
if ( V_38 == - V_100 && V_163 -> V_168 == 1 ) {
F_10 ( & V_16 -> V_16 ,
L_19 ,
V_152 , V_162 ) ;
V_164 = 1 ;
} else if ( V_38 < 0 ) {
F_86 ( V_16 , NULL , V_133 , V_163 -> V_134 ) ;
F_87 ( V_149 -> V_157 ) ;
return V_38 ;
}
F_87 ( V_149 -> V_157 ) ;
if ( V_163 -> V_134 != V_133 ) {
F_70 ( V_163 ) ;
F_96 ( V_163 ) ;
}
F_77 ( V_16 , V_163 , true ) ;
V_163 -> V_134 = V_133 ;
if ( V_164 ) {
int V_61 ;
for ( V_61 = 0 ; V_61 < V_133 -> V_20 . V_137 ; V_61 ++ ) {
V_139 = V_133 -> V_138 [ V_61 ] . V_20 . V_146 ;
V_24 = F_97 ( V_16 ,
V_142 & V_139 ) |
( F_73 ( V_139 ) ?
V_169 : V_94 ) ;
F_63 ( V_16 , V_24 ) ;
}
}
F_91 ( V_16 , V_163 , true ) ;
if ( F_80 ( & V_163 -> V_16 ) ) {
F_98 ( V_163 ) ;
F_67 ( V_163 ) ;
}
return 0 ;
}
int F_99 ( struct V_22 * V_16 )
{
int V_61 , V_10 ;
struct V_170 * V_171 ;
struct V_148 * V_149 = F_79 ( V_16 -> V_58 ) ;
if ( V_16 -> V_111 == V_112 )
return - V_113 ;
for ( V_61 = 1 ; V_61 < 16 ; ++ V_61 ) {
F_72 ( V_16 , V_61 , true ) ;
F_72 ( V_16 , V_61 + V_94 , true ) ;
}
V_171 = V_16 -> V_150 ;
V_10 = 0 ;
F_85 ( V_149 -> V_157 ) ;
for ( V_61 = 0 ; V_61 < V_171 -> V_20 . V_151 ; V_61 ++ ) {
struct V_130 * V_131 = V_171 -> V_152 [ V_61 ] ;
struct V_132 * V_133 ;
V_133 = F_94 ( V_131 , 0 ) ;
if ( ! V_133 )
V_133 = & V_131 -> V_172 [ 0 ] ;
if ( V_133 != V_131 -> V_134 )
V_10 = F_86 ( V_16 , NULL ,
V_131 -> V_134 , V_133 ) ;
if ( V_10 < 0 )
break;
}
if ( V_10 < 0 ) {
V_173:
for ( V_61 -- ; V_61 >= 0 ; V_61 -- ) {
struct V_130 * V_131 = V_171 -> V_152 [ V_61 ] ;
struct V_132 * V_133 ;
V_133 = F_94 ( V_131 , 0 ) ;
if ( ! V_133 )
V_133 = & V_131 -> V_172 [ 0 ] ;
if ( V_133 != V_131 -> V_134 )
F_86 ( V_16 , NULL ,
V_133 , V_131 -> V_134 ) ;
}
F_87 ( V_149 -> V_157 ) ;
return V_10 ;
}
V_10 = F_17 ( V_16 , F_65 ( V_16 , 0 ) ,
V_174 , 0 ,
V_171 -> V_20 . V_175 , 0 ,
NULL , 0 , V_129 ) ;
if ( V_10 < 0 )
goto V_173;
F_87 ( V_149 -> V_157 ) ;
for ( V_61 = 0 ; V_61 < V_171 -> V_20 . V_151 ; V_61 ++ ) {
struct V_130 * V_131 = V_171 -> V_152 [ V_61 ] ;
struct V_132 * V_133 ;
V_133 = F_94 ( V_131 , 0 ) ;
if ( ! V_133 )
V_133 = & V_131 -> V_172 [ 0 ] ;
if ( V_133 != V_131 -> V_134 ) {
F_70 ( V_131 ) ;
F_96 ( V_131 ) ;
}
V_131 -> V_134 = V_133 ;
F_91 ( V_16 , V_131 , true ) ;
if ( F_80 ( & V_131 -> V_16 ) ) {
F_98 ( V_131 ) ;
F_67 ( V_131 ) ;
}
}
return 0 ;
}
static void F_100 ( struct V_176 * V_16 )
{
struct V_130 * V_131 = F_101 ( V_16 ) ;
struct V_177 * V_178 =
F_102 ( V_131 -> V_172 ) ;
F_103 ( & V_178 -> V_179 , V_180 ) ;
F_20 ( V_131 ) ;
}
static int F_104 ( struct V_176 * V_16 , struct V_181 * V_182 )
{
struct V_22 * V_23 ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
V_131 = F_101 ( V_16 ) ;
V_23 = F_68 ( V_131 ) ;
V_133 = V_131 -> V_134 ;
if ( F_105 ( V_182 , L_20 ,
V_133 -> V_20 . V_183 ,
V_133 -> V_20 . V_184 ,
V_133 -> V_20 . V_185 ) )
return - V_31 ;
if ( F_105 ( V_182 ,
L_21
L_22 ,
F_106 ( V_23 -> V_122 . V_186 ) ,
F_106 ( V_23 -> V_122 . V_187 ) ,
F_106 ( V_23 -> V_122 . V_188 ) ,
V_23 -> V_122 . V_189 ,
V_23 -> V_122 . V_190 ,
V_23 -> V_122 . V_191 ,
V_133 -> V_20 . V_183 ,
V_133 -> V_20 . V_184 ,
V_133 -> V_20 . V_185 ) )
return - V_31 ;
return 0 ;
}
static int F_104 ( struct V_176 * V_16 , struct V_181 * V_182 )
{
return - V_64 ;
}
static struct V_192 * F_107 ( struct V_22 * V_16 ,
struct V_170 * V_171 ,
V_96 V_193 )
{
struct V_192 * V_10 = NULL ;
struct V_192 * V_194 ;
int V_195 ;
int V_196 ;
int V_61 ;
for ( V_61 = 0 ; ( V_61 < V_197 && V_171 -> V_194 [ V_61 ] ) ; V_61 ++ ) {
V_194 = V_171 -> V_194 [ V_61 ] ;
if ( V_194 -> V_198 == 0 )
continue;
V_195 = V_194 -> V_199 ;
V_196 = V_195 + ( V_194 -> V_198 - 1 ) ;
if ( V_193 >= V_195 && V_193 <= V_196 ) {
if ( ! V_10 )
V_10 = V_194 ;
else
F_29 ( & V_16 -> V_16 , L_23
L_24 , V_193 ) ;
}
}
return V_10 ;
}
static void F_108 ( struct V_200 * V_201 )
{
int V_103 ;
struct V_130 * V_163 =
F_109 ( V_201 , struct V_130 , V_202 ) ;
struct V_22 * V_117 = F_68 ( V_163 ) ;
V_103 = F_110 ( V_117 , V_163 ) ;
if ( V_103 >= 0 ) {
V_163 -> V_203 = 1 ;
F_111 ( V_117 ) ;
V_163 -> V_203 = 0 ;
F_112 ( V_117 ) ;
}
}
int F_113 ( struct V_22 * V_16 , int V_204 )
{
int V_61 , V_38 ;
struct V_170 * V_205 = NULL ;
struct V_130 * * V_206 = NULL ;
struct V_148 * V_149 = F_79 ( V_16 -> V_58 ) ;
int V_207 , V_208 ;
if ( V_16 -> V_209 == 0 || V_204 == - 1 )
V_204 = 0 ;
else {
for ( V_61 = 0 ; V_61 < V_16 -> V_122 . V_210 ; V_61 ++ ) {
if ( V_16 -> V_171 [ V_61 ] . V_20 . V_175 ==
V_204 ) {
V_205 = & V_16 -> V_171 [ V_61 ] ;
break;
}
}
}
if ( ( ! V_205 && V_204 != 0 ) )
return - V_45 ;
if ( V_205 && V_204 == 0 )
F_50 ( & V_16 -> V_16 , L_25 ) ;
V_207 = V_208 = 0 ;
if ( V_205 ) {
V_208 = V_205 -> V_20 . V_151 ;
V_206 = F_18 ( V_208 * sizeof( * V_206 ) ,
V_11 ) ;
if ( ! V_206 ) {
F_29 ( & V_16 -> V_16 , L_26 ) ;
return - V_31 ;
}
for (; V_207 < V_208 ; ++ V_207 ) {
V_206 [ V_207 ] = F_114 (
sizeof( struct V_130 ) ,
V_11 ) ;
if ( ! V_206 [ V_207 ] ) {
F_29 ( & V_16 -> V_16 , L_26 ) ;
V_38 = - V_31 ;
V_211:
while ( -- V_207 >= 0 )
F_20 ( V_206 [ V_207 ] ) ;
F_20 ( V_206 ) ;
return V_38 ;
}
}
V_61 = V_16 -> V_212 - V_205 -> V_20 . V_213 * 2 ;
if ( V_61 < 0 )
F_50 ( & V_16 -> V_16 , L_27
L_28 ,
V_204 , - V_61 ) ;
}
V_38 = F_115 ( V_16 ) ;
if ( V_38 )
goto V_211;
if ( V_16 -> V_111 != V_154 )
F_78 ( V_16 , 1 ) ;
F_116 ( V_16 ) ;
F_85 ( V_149 -> V_157 ) ;
V_38 = F_86 ( V_16 , V_205 , NULL , NULL ) ;
if ( V_38 < 0 ) {
F_87 ( V_149 -> V_157 ) ;
F_117 ( V_16 ) ;
goto V_211;
}
V_38 = F_17 ( V_16 , F_65 ( V_16 , 0 ) ,
V_174 , 0 , V_204 , 0 ,
NULL , 0 , V_129 ) ;
if ( V_38 < 0 ) {
V_205 = NULL ;
}
V_16 -> V_150 = V_205 ;
if ( ! V_205 ) {
F_84 ( V_16 , V_154 ) ;
F_86 ( V_16 , NULL , NULL , NULL ) ;
F_87 ( V_149 -> V_157 ) ;
F_117 ( V_16 ) ;
goto V_211;
}
F_87 ( V_149 -> V_157 ) ;
F_84 ( V_16 , V_153 ) ;
for ( V_61 = 0 ; V_61 < V_208 ; ++ V_61 ) {
struct V_177 * V_178 ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
V_205 -> V_152 [ V_61 ] = V_131 = V_206 [ V_61 ] ;
V_178 = V_205 -> V_214 [ V_61 ] ;
V_131 -> V_172 = V_178 -> V_172 ;
V_131 -> V_168 = V_178 -> V_168 ;
V_131 -> V_194 = F_107 ( V_16 , V_205 , V_61 ) ;
F_118 ( & V_178 -> V_179 ) ;
V_133 = F_94 ( V_131 , 0 ) ;
if ( ! V_133 )
V_133 = & V_131 -> V_172 [ 0 ] ;
V_131 -> V_134 = V_133 ;
F_91 ( V_16 , V_131 , true ) ;
V_131 -> V_16 . V_215 = & V_16 -> V_16 ;
V_131 -> V_16 . V_155 = NULL ;
V_131 -> V_16 . V_58 = & V_216 ;
V_131 -> V_16 . type = & V_217 ;
V_131 -> V_16 . V_218 = V_219 ;
V_131 -> V_16 . V_220 = V_16 -> V_16 . V_220 ;
F_119 ( & V_131 -> V_202 , F_108 ) ;
V_131 -> V_221 = - 1 ;
F_120 ( & V_131 -> V_16 ) ;
F_121 ( & V_131 -> V_16 ) ;
F_122 ( & V_131 -> V_16 , L_29 ,
V_16 -> V_58 -> V_222 , V_16 -> V_60 ,
V_204 , V_133 -> V_20 . V_223 ) ;
}
F_20 ( V_206 ) ;
if ( V_205 -> string == NULL &&
! ( V_16 -> V_104 & V_224 ) )
V_205 -> string = F_60 ( V_16 , V_205 -> V_20 . V_225 ) ;
for ( V_61 = 0 ; V_61 < V_208 ; ++ V_61 ) {
struct V_130 * V_131 = V_205 -> V_152 [ V_61 ] ;
F_10 ( & V_16 -> V_16 ,
L_30 ,
F_81 ( & V_131 -> V_16 ) , V_204 ,
V_131 -> V_134 -> V_20 . V_223 ) ;
F_123 ( & V_131 -> V_16 ) ;
V_38 = F_124 ( & V_131 -> V_16 ) ;
if ( V_38 != 0 ) {
F_29 ( & V_16 -> V_16 , L_31 ,
F_81 ( & V_131 -> V_16 ) , V_38 ) ;
continue;
}
F_67 ( V_131 ) ;
}
F_117 ( V_16 ) ;
return 0 ;
}
static void F_125 ( struct V_200 * V_226 )
{
struct V_227 * V_228 =
F_109 ( V_226 , struct V_227 , V_226 ) ;
struct V_22 * V_117 = V_228 -> V_117 ;
F_126 ( V_117 ) ;
F_28 ( & V_229 ) ;
F_127 ( & V_228 -> V_230 ) ;
F_30 ( & V_229 ) ;
if ( V_228 -> V_171 >= - 1 )
F_113 ( V_117 , V_228 -> V_171 ) ;
F_112 ( V_117 ) ;
F_128 ( V_117 ) ;
F_20 ( V_228 ) ;
}
static void F_116 ( struct V_22 * V_117 )
{
struct V_227 * V_228 ;
F_28 ( & V_229 ) ;
F_129 (req, &set_config_list, node) {
if ( V_228 -> V_117 == V_117 )
V_228 -> V_171 = - 999 ;
}
F_30 ( & V_229 ) ;
}
int F_130 ( struct V_22 * V_117 , int V_171 )
{
struct V_227 * V_228 ;
V_228 = F_18 ( sizeof( * V_228 ) , V_46 ) ;
if ( ! V_228 )
return - V_31 ;
V_228 -> V_117 = V_117 ;
V_228 -> V_171 = V_171 ;
F_119 ( & V_228 -> V_226 , F_125 ) ;
F_28 ( & V_229 ) ;
F_131 ( & V_228 -> V_230 , & V_231 ) ;
F_30 ( & V_229 ) ;
F_132 ( V_117 ) ;
F_133 ( & V_228 -> V_226 ) ;
return 0 ;
}
