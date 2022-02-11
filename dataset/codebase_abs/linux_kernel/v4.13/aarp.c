static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
static unsigned char V_4 [ V_5 ] =
{ 0x09 , 0x00 , 0x07 , 0xFF , 0xFF , 0xFF } ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 ;
int V_10 = V_7 -> V_11 + sizeof( * V_9 ) + V_12 -> V_13 ;
struct V_14 * V_15 = F_5 ( V_10 , V_16 ) ;
struct V_17 * V_18 = F_6 ( V_7 ) ;
if ( ! V_15 )
return;
if ( ! V_18 ) {
F_7 ( V_15 ) ;
return;
}
F_8 ( V_15 , V_7 -> V_11 + V_12 -> V_13 ) ;
F_9 ( V_15 ) ;
F_10 ( V_15 ) ;
F_11 ( V_15 , sizeof( * V_9 ) ) ;
V_15 -> V_19 = F_12 ( V_20 ) ;
V_15 -> V_7 = V_7 ;
V_9 = F_13 ( V_15 ) ;
V_9 -> V_21 = F_12 ( V_22 ) ;
V_9 -> V_23 = F_12 ( V_20 ) ;
V_9 -> V_24 = V_5 ;
V_9 -> V_25 = V_26 ;
V_9 -> V_27 = F_12 ( V_28 ) ;
F_14 ( V_9 -> V_29 , V_7 -> V_30 ) ;
V_9 -> V_31 = 0 ;
V_9 -> V_32 = V_18 -> V_33 ;
V_9 -> V_34 = V_18 -> V_35 ;
F_15 ( V_9 -> V_36 ) ;
V_9 -> V_37 = 0 ;
V_9 -> V_38 = V_2 -> V_39 . V_33 ;
V_9 -> V_40 = V_2 -> V_39 . V_35 ;
V_12 -> V_41 ( V_12 , V_15 , V_4 ) ;
V_2 -> V_42 ++ ;
V_2 -> V_43 = V_44 ;
}
static void F_16 ( struct V_6 * V_7 , struct V_17 * V_45 ,
struct V_17 * V_46 , unsigned char * V_47 )
{
struct V_8 * V_9 ;
int V_10 = V_7 -> V_11 + sizeof( * V_9 ) + V_12 -> V_13 ;
struct V_14 * V_15 = F_5 ( V_10 , V_16 ) ;
if ( ! V_15 )
return;
F_8 ( V_15 , V_7 -> V_11 + V_12 -> V_13 ) ;
F_9 ( V_15 ) ;
F_10 ( V_15 ) ;
F_11 ( V_15 , sizeof( * V_9 ) ) ;
V_15 -> V_19 = F_12 ( V_20 ) ;
V_15 -> V_7 = V_7 ;
V_9 = F_13 ( V_15 ) ;
V_9 -> V_21 = F_12 ( V_22 ) ;
V_9 -> V_23 = F_12 ( V_20 ) ;
V_9 -> V_24 = V_5 ;
V_9 -> V_25 = V_26 ;
V_9 -> V_27 = F_12 ( V_48 ) ;
F_14 ( V_9 -> V_29 , V_7 -> V_30 ) ;
V_9 -> V_31 = 0 ;
V_9 -> V_32 = V_45 -> V_33 ;
V_9 -> V_34 = V_45 -> V_35 ;
if ( ! V_47 )
F_15 ( V_9 -> V_36 ) ;
else
F_14 ( V_9 -> V_36 , V_47 ) ;
V_9 -> V_37 = 0 ;
V_9 -> V_38 = V_46 -> V_33 ;
V_9 -> V_40 = V_46 -> V_35 ;
V_12 -> V_41 ( V_12 , V_15 , V_47 ) ;
}
static void F_17 ( struct V_6 * V_7 , struct V_17 * V_45 )
{
struct V_8 * V_9 ;
int V_10 = V_7 -> V_11 + sizeof( * V_9 ) + V_12 -> V_13 ;
struct V_14 * V_15 = F_5 ( V_10 , V_16 ) ;
static unsigned char V_4 [ V_5 ] =
{ 0x09 , 0x00 , 0x07 , 0xFF , 0xFF , 0xFF } ;
if ( ! V_15 )
return;
F_8 ( V_15 , V_7 -> V_11 + V_12 -> V_13 ) ;
F_9 ( V_15 ) ;
F_10 ( V_15 ) ;
F_11 ( V_15 , sizeof( * V_9 ) ) ;
V_15 -> V_19 = F_12 ( V_20 ) ;
V_15 -> V_7 = V_7 ;
V_9 = F_13 ( V_15 ) ;
V_9 -> V_21 = F_12 ( V_22 ) ;
V_9 -> V_23 = F_12 ( V_20 ) ;
V_9 -> V_24 = V_5 ;
V_9 -> V_25 = V_26 ;
V_9 -> V_27 = F_12 ( V_49 ) ;
F_14 ( V_9 -> V_29 , V_7 -> V_30 ) ;
V_9 -> V_31 = 0 ;
V_9 -> V_32 = V_45 -> V_33 ;
V_9 -> V_34 = V_45 -> V_35 ;
F_15 ( V_9 -> V_36 ) ;
V_9 -> V_37 = 0 ;
V_9 -> V_38 = V_45 -> V_33 ;
V_9 -> V_40 = V_45 -> V_35 ;
V_12 -> V_41 ( V_12 , V_15 , V_4 ) ;
}
static void F_18 ( struct V_1 * * V_50 )
{
struct V_1 * V_51 ;
while ( * V_50 )
if ( F_19 ( V_44 , ( * V_50 ) -> V_52 ) ) {
V_51 = * V_50 ;
* V_50 = ( * V_50 ) -> V_53 ;
F_1 ( V_51 ) ;
} else
V_50 = & ( ( * V_50 ) -> V_53 ) ;
}
static void F_20 ( struct V_1 * * V_50 )
{
struct V_1 * V_51 ;
while ( * V_50 )
if ( ( * V_50 ) -> V_42 >= V_54 ) {
V_51 = * V_50 ;
* V_50 = ( * V_50 ) -> V_53 ;
F_1 ( V_51 ) ;
} else {
F_4 ( * V_50 ) ;
V_50 = & ( ( * V_50 ) -> V_53 ) ;
}
}
static void F_21 ( struct V_1 * * V_50 , struct V_6 * V_7 )
{
struct V_1 * V_51 ;
while ( * V_50 )
if ( ( * V_50 ) -> V_7 == V_7 ) {
V_51 = * V_50 ;
* V_50 = ( * V_50 ) -> V_53 ;
F_1 ( V_51 ) ;
} else
V_50 = & ( ( * V_50 ) -> V_53 ) ;
}
static void F_22 ( unsigned long V_55 )
{
int V_56 ;
F_23 ( & V_57 ) ;
for ( V_56 = 0 ; V_56 < V_58 ; V_56 ++ ) {
F_18 ( & V_59 [ V_56 ] ) ;
F_20 ( & V_60 [ V_56 ] ) ;
F_18 ( & V_60 [ V_56 ] ) ;
F_18 ( & V_61 [ V_56 ] ) ;
}
F_24 ( & V_57 ) ;
F_25 ( & V_62 , V_44 +
( V_63 ? V_64 :
V_65 ) ) ;
}
static int F_26 ( struct V_66 * V_67 , unsigned long V_68 ,
void * V_69 )
{
struct V_6 * V_7 = F_27 ( V_69 ) ;
int V_56 ;
if ( ! F_28 ( F_29 ( V_7 ) , & V_70 ) )
return V_71 ;
if ( V_68 == V_72 ) {
F_23 ( & V_57 ) ;
for ( V_56 = 0 ; V_56 < V_58 ; V_56 ++ ) {
F_21 ( & V_59 [ V_56 ] , V_7 ) ;
F_21 ( & V_60 [ V_56 ] , V_7 ) ;
F_21 ( & V_61 [ V_56 ] , V_7 ) ;
}
F_24 ( & V_57 ) ;
}
return V_71 ;
}
static void F_30 ( struct V_1 * * V_50 )
{
struct V_1 * V_51 ;
while ( * V_50 ) {
V_51 = * V_50 ;
* V_50 = ( * V_50 ) -> V_53 ;
F_1 ( V_51 ) ;
}
}
static void F_31 ( void )
{
int V_56 ;
F_23 ( & V_57 ) ;
for ( V_56 = 0 ; V_56 < V_58 ; V_56 ++ ) {
F_30 ( & V_59 [ V_56 ] ) ;
F_30 ( & V_60 [ V_56 ] ) ;
F_30 ( & V_61 [ V_56 ] ) ;
}
F_24 ( & V_57 ) ;
}
static struct V_1 * F_32 ( void )
{
struct V_1 * V_2 = F_33 ( sizeof( * V_2 ) , V_16 ) ;
if ( V_2 )
F_34 ( & V_2 -> V_3 ) ;
return V_2 ;
}
static struct V_1 * F_35 ( struct V_1 * V_73 ,
struct V_6 * V_7 ,
struct V_17 * V_18 )
{
while ( V_73 ) {
if ( V_73 -> V_39 . V_33 == V_18 -> V_33 &&
V_73 -> V_39 . V_35 == V_18 -> V_35 &&
V_73 -> V_7 == V_7 )
break;
V_73 = V_73 -> V_53 ;
}
return V_73 ;
}
void F_36 ( struct V_6 * V_7 , struct V_17 * V_74 )
{
int V_75 = V_74 -> V_35 % ( V_58 - 1 ) ;
struct V_1 * V_2 ;
F_23 ( & V_57 ) ;
V_2 = F_35 ( V_61 [ V_75 ] , V_7 , V_74 ) ;
if ( V_2 )
V_2 -> V_52 = V_44 - 1 ;
F_24 ( & V_57 ) ;
}
static struct V_17 * F_37 ( struct V_6 * V_7 ,
struct V_17 * V_74 )
{
int V_75 = V_74 -> V_35 % ( V_58 - 1 ) ;
struct V_1 * V_2 = F_35 ( V_61 [ V_75 ] , V_7 , V_74 ) ;
return V_2 ? V_74 : NULL ;
}
static void F_38 ( struct V_76 * V_77 )
{
struct V_78 V_79 ;
struct V_80 * V_74 = (struct V_80 * ) & V_79 . V_81 ;
const struct V_82 * V_83 = V_77 -> V_7 -> V_84 ;
V_74 -> V_85 . V_35 = V_77 -> V_86 . V_35 ;
V_74 -> V_85 . V_33 = F_39 ( V_77 -> V_86 . V_33 ) ;
if ( ! ( V_83 -> V_87 ( V_77 -> V_7 , & V_79 , V_88 ) ) ) {
V_83 -> V_87 ( V_77 -> V_7 , & V_79 , V_89 ) ;
if ( V_77 -> V_86 . V_33 != F_12 ( V_74 -> V_85 . V_33 ) ||
V_77 -> V_86 . V_35 != V_74 -> V_85 . V_35 )
V_77 -> V_90 |= V_91 ;
V_77 -> V_86 . V_33 = F_12 ( V_74 -> V_85 . V_33 ) ;
V_77 -> V_86 . V_35 = V_74 -> V_85 . V_35 ;
}
}
void F_40 ( struct V_76 * V_92 )
{
if ( V_92 -> V_7 -> type == V_93 ||
V_92 -> V_7 -> type == V_94 )
F_38 ( V_92 ) ;
else {
unsigned int V_95 ;
for ( V_95 = 0 ; V_95 < V_96 ; V_95 ++ ) {
F_17 ( V_92 -> V_7 , & V_92 -> V_86 ) ;
F_41 ( 100 ) ;
if ( V_92 -> V_90 & V_91 )
break;
}
}
}
int F_42 ( struct V_76 * V_92 , struct V_17 * V_74 )
{
int V_75 , V_97 = - V_98 ;
struct V_1 * V_99 ;
unsigned int V_95 ;
if ( V_92 -> V_7 -> type == V_93 ||
V_92 -> V_7 -> type == V_94 )
goto V_100;
V_99 = F_32 () ;
V_97 = - V_101 ;
if ( ! V_99 )
goto V_100;
V_99 -> V_52 = - 1 ;
V_99 -> V_90 = V_102 ;
V_99 -> V_39 . V_35 = V_74 -> V_35 ;
V_99 -> V_39 . V_33 = V_74 -> V_33 ;
V_99 -> V_7 = V_92 -> V_7 ;
F_23 ( & V_57 ) ;
V_75 = V_74 -> V_35 % ( V_58 - 1 ) ;
V_99 -> V_53 = V_61 [ V_75 ] ;
V_61 [ V_75 ] = V_99 ;
for ( V_95 = 0 ; V_95 < V_96 ; V_95 ++ ) {
F_17 ( V_92 -> V_7 , V_74 ) ;
F_24 ( & V_57 ) ;
F_41 ( 100 ) ;
F_23 ( & V_57 ) ;
if ( V_99 -> V_90 & V_91 )
break;
}
if ( V_99 -> V_90 & V_91 ) {
V_99 -> V_52 = V_44 - 1 ;
V_97 = - V_103 ;
} else {
V_99 -> V_90 &= ~ V_102 ;
V_97 = 1 ;
}
F_24 ( & V_57 ) ;
V_100:
return V_97 ;
}
int F_43 ( struct V_6 * V_7 , struct V_14 * V_15 ,
struct V_17 * V_74 , void * V_104 )
{
static char V_105 [ V_5 ] =
{ 0x09 , 0x00 , 0x07 , 0xFF , 0xFF , 0xFF } ;
int V_75 ;
struct V_1 * V_2 ;
F_9 ( V_15 ) ;
if ( V_7 -> type == V_93 ) {
struct V_17 * V_106 = F_6 ( V_7 ) ;
struct V_107 * V_108 = (struct V_107 * ) V_15 -> V_109 ;
int V_110 = 2 ;
if ( ( ! V_108 -> V_111 || V_106 -> V_33 == V_108 -> V_111 ) &&
( ! V_108 -> V_112 || V_106 -> V_33 == V_108 -> V_112 ) ) {
F_44 ( V_15 , sizeof( * V_108 ) - 4 ) ;
* ( ( V_113 * ) V_15 -> V_109 ) = F_12 ( V_15 -> V_10 ) ;
V_110 = 1 ;
}
F_45 ( V_15 , 3 ) ;
V_15 -> V_109 [ 0 ] = V_74 -> V_35 ;
V_15 -> V_109 [ 1 ] = V_106 -> V_35 ;
V_15 -> V_109 [ 2 ] = V_110 ;
V_15 -> V_7 = V_7 ;
goto V_114;
}
if ( V_7 -> type == V_94 ) {
V_15 -> V_19 = F_12 ( V_115 ) ;
V_15 -> V_7 = V_7 ;
goto V_114;
}
if ( V_7 -> type != V_116 )
goto V_117;
V_15 -> V_7 = V_7 ;
V_15 -> V_19 = F_12 ( V_20 ) ;
V_75 = V_74 -> V_35 % ( V_58 - 1 ) ;
if ( V_74 -> V_35 == V_118 ) {
V_119 -> V_41 ( V_119 , V_15 , V_105 ) ;
goto V_120;
}
F_23 ( & V_57 ) ;
V_2 = F_35 ( V_59 [ V_75 ] , V_7 , V_74 ) ;
if ( V_2 ) {
V_2 -> V_52 = V_44 + ( V_65 * 10 ) ;
V_119 -> V_41 ( V_119 , V_15 , V_2 -> V_104 ) ;
F_24 ( & V_57 ) ;
goto V_120;
}
V_2 = F_35 ( V_60 [ V_75 ] , V_7 , V_74 ) ;
if ( V_2 ) {
F_46 ( & V_2 -> V_3 , V_15 ) ;
goto V_121;
}
V_2 = F_32 () ;
if ( ! V_2 ) {
F_24 ( & V_57 ) ;
goto V_117;
}
F_46 ( & V_2 -> V_3 , V_15 ) ;
V_2 -> V_52 = V_44 + V_122 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_53 = V_60 [ V_75 ] ;
V_2 -> V_39 = * V_74 ;
V_2 -> V_42 = 0 ;
V_60 [ V_75 ] = V_2 ;
V_63 ++ ;
F_4 ( V_2 ) ;
if ( V_63 == 1 )
F_25 ( & V_62 , V_44 + V_64 ) ;
V_121:
F_24 ( & V_57 ) ;
goto V_120;
V_114:
if ( V_15 -> V_123 )
V_15 -> V_124 = V_15 -> V_123 -> V_125 ;
if ( F_47 ( V_15 ) )
goto V_126;
V_120:
return V_127 ;
V_117:
F_7 ( V_15 ) ;
V_126:
return V_128 ;
}
static void F_48 ( struct V_1 * * V_73 , struct V_1 * V_2 ,
int V_75 )
{
struct V_14 * V_15 ;
while ( * V_73 )
if ( * V_73 == V_2 ) {
V_63 -- ;
* V_73 = V_2 -> V_53 ;
V_2 -> V_53 = V_59 [ V_75 ] ;
V_59 [ V_75 ] = V_2 ;
while ( ( V_15 = F_49 ( & V_2 -> V_3 ) ) != NULL ) {
V_2 -> V_52 = V_44 +
V_65 * 10 ;
V_119 -> V_41 ( V_119 , V_15 , V_2 -> V_104 ) ;
}
} else
V_73 = & ( ( * V_73 ) -> V_53 ) ;
}
static int F_50 ( struct V_14 * V_15 , struct V_6 * V_7 ,
struct V_129 * V_130 , struct V_6 * V_131 )
{
struct V_8 * V_132 = F_13 ( V_15 ) ;
int V_75 , V_133 = 0 ;
T_1 V_27 ;
struct V_1 * V_2 ;
struct V_17 V_74 , * V_134 , V_135 ;
struct V_76 * V_136 ;
if ( ! F_28 ( F_29 ( V_7 ) , & V_70 ) )
goto V_137;
if ( V_7 -> type != V_116 )
goto V_137;
if ( ! F_44 ( V_15 , sizeof( * V_132 ) ) )
goto V_137;
V_27 = F_39 ( V_132 -> V_27 ) ;
if ( V_27 < V_28 || V_27 > V_49 ||
V_132 -> V_24 != V_5 || V_132 -> V_25 != V_26 ||
V_132 -> V_31 || V_132 -> V_37 )
goto V_137;
V_75 = V_132 -> V_34 % ( V_58 - 1 ) ;
V_74 . V_35 = V_132 -> V_34 ;
V_74 . V_33 = V_132 -> V_32 ;
V_136 = F_51 ( V_7 ) ;
if ( ! V_136 )
goto V_138;
if ( V_136 -> V_90 & V_102 &&
V_136 -> V_86 . V_35 == V_132 -> V_40 &&
V_136 -> V_86 . V_33 == V_132 -> V_38 ) {
V_136 -> V_90 |= V_91 ;
goto V_138;
}
V_135 . V_35 = V_132 -> V_40 ;
V_135 . V_33 = V_132 -> V_38 ;
F_23 ( & V_57 ) ;
V_2 = F_35 ( V_61 [ V_75 ] , V_7 , & V_135 ) ;
if ( V_2 && V_2 -> V_90 & V_102 ) {
V_2 -> V_90 |= V_91 ;
goto V_139;
}
switch ( V_27 ) {
case V_48 :
if ( ! V_63 )
break;
V_2 = F_35 ( V_60 [ V_75 ] , V_7 , & V_74 ) ;
if ( ! V_2 || V_7 != V_2 -> V_7 )
break;
F_14 ( V_2 -> V_104 , V_132 -> V_29 ) ;
F_48 ( & V_60 [ V_75 ] , V_2 , V_75 ) ;
if ( ! V_63 )
F_25 ( & V_62 ,
V_44 + V_65 ) ;
break;
case V_28 :
case V_49 :
V_74 . V_35 = V_132 -> V_40 ;
V_74 . V_33 = V_132 -> V_38 ;
V_134 = F_37 ( V_7 , & V_74 ) ;
if ( ! V_134 )
V_134 = & V_136 -> V_86 ;
else {
V_135 . V_35 = V_74 . V_35 ;
V_135 . V_33 = V_74 . V_33 ;
V_134 = & V_135 ;
}
if ( V_27 == V_49 ) {
V_2 = F_35 ( V_59 [ V_74 . V_35 %
( V_58 - 1 ) ] ,
V_15 -> V_7 , & V_74 ) ;
if ( V_2 ) {
V_2 -> V_52 = V_44 - 1 ;
F_25 ( & V_62 , V_44 +
V_64 ) ;
}
}
if ( V_74 . V_35 != V_134 -> V_35 )
break;
if ( V_74 . V_33 && V_134 -> V_33 && V_74 . V_33 != V_134 -> V_33 )
break;
V_74 . V_35 = V_132 -> V_34 ;
V_74 . V_33 = V_132 -> V_32 ;
F_16 ( V_7 , V_134 , & V_74 , V_132 -> V_29 ) ;
break;
}
V_139:
F_24 ( & V_57 ) ;
V_138:
V_133 = 1 ;
V_137:
F_7 ( V_15 ) ;
return V_133 ;
}
void T_2 F_52 ( void )
{
V_12 = F_53 ( V_140 , F_50 ) ;
if ( ! V_12 )
F_54 ( V_141 L_1 ) ;
F_55 ( & V_62 , F_22 , 0 ) ;
V_62 . V_142 = V_44 + V_65 ;
F_56 ( & V_62 ) ;
F_57 ( & V_143 ) ;
}
void F_58 ( struct V_6 * V_7 )
{
int V_56 ;
F_23 ( & V_57 ) ;
for ( V_56 = 0 ; V_56 < V_58 ; V_56 ++ ) {
F_21 ( & V_59 [ V_56 ] , V_7 ) ;
F_21 ( & V_60 [ V_56 ] , V_7 ) ;
F_21 ( & V_61 [ V_56 ] , V_7 ) ;
}
F_24 ( & V_57 ) ;
}
static struct V_1 * F_59 ( struct V_144 * V_145 , T_3 * V_146 )
{
int V_56 = V_145 -> V_147 ;
struct V_1 * * V_148 = V_145 -> V_148 ;
T_3 V_149 = 0 ;
struct V_1 * V_99 ;
V_150:
while ( V_56 < V_58 ) {
for ( V_99 = V_148 [ V_56 ] ; V_99 ; V_99 = V_99 -> V_53 ) {
if ( ! V_146 || ++ V_149 == * V_146 ) {
V_145 -> V_148 = V_148 ;
V_145 -> V_147 = V_56 ;
return V_99 ;
}
}
++ V_56 ;
}
if ( V_148 == V_59 ) {
V_56 = 0 ;
V_148 = V_60 ;
goto V_150;
}
if ( V_148 == V_60 ) {
V_56 = 0 ;
V_148 = V_61 ;
goto V_150;
}
return NULL ;
}
static void * F_60 ( struct V_151 * V_152 , T_3 * V_146 )
__acquires( V_57 )
{
struct V_144 * V_145 = V_152 -> V_153 ;
F_61 ( & V_57 ) ;
V_145 -> V_148 = V_59 ;
V_145 -> V_147 = 0 ;
return * V_146 ? F_59 ( V_145 , V_146 ) : V_154 ;
}
static void * F_62 ( struct V_151 * V_152 , void * V_155 , T_3 * V_146 )
{
struct V_1 * V_99 = V_155 ;
struct V_144 * V_145 = V_152 -> V_153 ;
++ * V_146 ;
if ( V_155 == V_154 )
V_99 = F_59 ( V_145 , NULL ) ;
else if ( V_99 -> V_53 )
V_99 = V_99 -> V_53 ;
else {
++ V_145 -> V_147 ;
V_99 = F_59 ( V_145 , NULL ) ;
}
return V_99 ;
}
static void F_63 ( struct V_151 * V_152 , void * V_155 )
__releases( V_57 )
{
F_64 ( & V_57 ) ;
}
static const char * F_65 ( unsigned long V_156 )
{
static char V_157 [ 32 ] ;
sprintf ( V_157 , L_2 , V_156 / V_158 , ( ( V_156 % V_158 ) * 100 ) / V_158 ) ;
return V_157 ;
}
static int F_66 ( struct V_151 * V_152 , void * V_155 )
{
struct V_144 * V_145 = V_152 -> V_153 ;
struct V_1 * V_99 = V_155 ;
unsigned long V_159 = V_44 ;
if ( V_155 == V_154 )
F_67 ( V_152 ,
L_3
L_4 ) ;
else {
F_68 ( V_152 , L_5 ,
F_39 ( V_99 -> V_39 . V_33 ) ,
( unsigned int ) V_99 -> V_39 . V_35 ,
V_99 -> V_7 ? V_99 -> V_7 -> V_160 : L_6 ) ;
F_68 ( V_152 , L_7 , V_99 -> V_104 ) ;
F_68 ( V_152 , L_8 ,
F_65 ( ( long ) V_99 -> V_52 - ( long ) V_159 ) ) ;
if ( V_145 -> V_148 == V_60 )
F_68 ( V_152 , L_9 ,
F_65 ( V_159 - V_99 -> V_43 ) ,
V_99 -> V_42 ) ;
else
F_67 ( V_152 , L_10 ) ;
F_68 ( V_152 , L_11 ,
( V_145 -> V_148 == V_59 ) ? L_12
: ( V_145 -> V_148 == V_60 ) ? L_13
: ( V_145 -> V_148 == V_61 ) ? L_14
: L_15 ) ;
}
return 0 ;
}
static int F_69 ( struct V_161 * V_161 , struct V_162 * V_162 )
{
return F_70 ( V_162 , & V_163 ,
sizeof( struct V_144 ) ) ;
}
void F_71 ( void )
{
F_72 ( & V_62 ) ;
F_73 ( & V_143 ) ;
F_74 ( V_12 ) ;
F_31 () ;
}
