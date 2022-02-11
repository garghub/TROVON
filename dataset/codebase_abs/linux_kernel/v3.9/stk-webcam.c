int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_6 , F_3 ( V_6 , 0 ) ,
0x01 ,
V_8 | V_9 | V_10 ,
V_4 ,
V_3 ,
NULL ,
0 ,
500 ) ;
if ( V_7 < 0 )
return V_7 ;
else
return 0 ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_3 , int * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_6 , F_5 ( V_6 , 0 ) ,
0x00 ,
V_11 | V_9 | V_10 ,
0x00 ,
V_3 ,
( T_2 * ) V_4 ,
sizeof( T_2 ) ,
500 ) ;
if ( V_7 < 0 )
return V_7 ;
else
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_4 ;
int V_12 , V_7 ;
int V_13 , V_14 ;
if ( ! F_7 ( V_2 ) )
return - V_15 ;
if ( ! F_8 ( V_2 ) || ! F_9 ( V_2 ) ) {
F_10 ( L_1 ) ;
return - V_16 ;
}
V_7 = F_11 ( V_2 -> V_6 , 0 , 5 ) ;
if ( V_7 < 0 )
F_10 ( L_2 ) ;
if ( F_12 ( V_2 ) )
F_10 ( L_3 ) ;
F_4 ( V_2 , 0x0116 , & V_13 ) ;
F_4 ( V_2 , 0x0117 , & V_14 ) ;
F_1 ( V_2 , 0x0116 , 0x0000 ) ;
F_1 ( V_2 , 0x0117 , 0x0000 ) ;
F_4 ( V_2 , 0x0100 , & V_4 ) ;
F_1 ( V_2 , 0x0100 , V_4 | 0x80 ) ;
F_1 ( V_2 , 0x0116 , V_13 ) ;
F_1 ( V_2 , 0x0117 , V_14 ) ;
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ ) {
if ( V_2 -> V_18 [ V_12 ] . V_19 ) {
V_7 = F_13 ( V_2 -> V_18 [ V_12 ] . V_19 , V_20 ) ;
F_14 ( & V_2 -> V_21 ) ;
if ( V_7 )
return V_7 ;
}
}
F_15 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_4 ;
int V_12 ;
if ( F_7 ( V_2 ) ) {
F_4 ( V_2 , 0x0100 , & V_4 ) ;
F_1 ( V_2 , 0x0100 , V_4 & ~ 0x80 ) ;
if ( V_2 -> V_18 != NULL ) {
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ ) {
if ( V_2 -> V_18 [ V_12 ] . V_19 )
F_17 ( V_2 -> V_18 [ V_12 ] . V_19 ) ;
}
}
F_18 ( V_2 ) ;
if ( F_11 ( V_2 -> V_6 , 0 , 0 ) )
F_10 ( L_2 ) ;
if ( F_19 ( V_2 ) )
F_10 ( L_4 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
int V_7 ;
if ( ! F_7 ( V_2 ) )
return - V_15 ;
if ( F_9 ( V_2 ) )
return 0 ;
V_23 = V_24 ;
while ( V_23 -> V_25 != 0xffff ) {
V_7 = F_1 ( V_2 , V_23 -> V_25 , V_23 -> V_26 ) ;
if ( V_7 )
return V_7 ;
V_23 ++ ;
}
if ( F_21 ( V_2 ) == 0 ) {
F_22 ( V_2 ) ;
return 0 ;
} else
return - 1 ;
}
static void F_23 ( struct V_19 * V_19 )
{
int V_12 ;
int V_7 ;
int V_27 ;
unsigned long V_28 ;
unsigned char * V_29 = NULL ;
unsigned char * V_30 = NULL ;
struct V_1 * V_2 ;
struct V_31 * V_32 ;
V_2 = (struct V_1 * ) V_19 -> V_33 ;
if ( V_2 == NULL ) {
F_10 ( L_5 ) ;
return;
}
if ( V_19 -> V_34 == - V_35 || V_19 -> V_34 == - V_36
|| V_19 -> V_34 == - V_37 ) {
F_24 ( & V_2 -> V_21 ) ;
return;
}
F_25 ( & V_2 -> V_38 , V_28 ) ;
if ( V_19 -> V_34 != - V_39 && V_19 -> V_34 != 0 ) {
F_10 ( L_6 , V_19 -> V_34 ) ;
goto V_40;
}
if ( F_26 ( & V_2 -> V_41 ) ) {
( void ) ( F_27 () &&
F_10 ( L_7 ) ) ;
goto V_40;
}
V_32 = F_28 ( & V_2 -> V_41 ,
struct V_31 , V_42 ) ;
V_29 = V_32 -> V_43 + V_32 -> V_44 . V_45 ;
for ( V_12 = 0 ; V_12 < V_19 -> V_46 ; V_12 ++ ) {
if ( V_19 -> V_47 [ V_12 ] . V_34 != 0 ) {
if ( V_19 -> V_47 [ V_12 ] . V_34 != - V_48 )
F_10 ( L_8 , V_12 ,
V_19 -> V_47 [ V_12 ] . V_34 ) ;
continue;
}
V_27 = V_19 -> V_47 [ V_12 ] . V_49 ;
V_30 = V_19 -> V_50 + V_19 -> V_47 [ V_12 ] . V_51 ;
if ( V_27 <= 4 )
continue;
if ( * V_30 & 0x80 ) {
V_27 -= 8 ;
V_30 += 8 ;
if ( V_32 -> V_44 . V_45 != 0
&& V_32 -> V_44 . V_45 != V_2 -> V_52 ) {
( void ) ( F_27 () &&
F_10 ( L_9
L_10 ,
V_12 , V_32 -> V_44 . V_45 ) ) ;
V_32 -> V_44 . V_45 = 0 ;
V_29 = V_32 -> V_43 ;
} else if ( V_32 -> V_44 . V_45 == V_2 -> V_52 ) {
if ( F_29 ( & V_2 -> V_41 ) ) {
V_32 -> V_44 . V_45 = 0 ;
V_29 = V_32 -> V_43 ;
} else {
F_30 ( V_2 -> V_41 . V_53 ,
& V_2 -> V_54 ) ;
F_31 ( & V_2 -> V_55 ) ;
V_32 = F_28 ( & V_2 -> V_41 ,
struct V_31 , V_42 ) ;
V_32 -> V_44 . V_45 = 0 ;
V_29 = V_32 -> V_43 ;
}
}
} else {
V_27 -= 4 ;
V_30 += 4 ;
}
if ( V_27 + V_32 -> V_44 . V_45 > V_2 -> V_52 ) {
( void ) ( F_27 () &&
F_10 ( L_11 ) ) ;
continue;
}
F_32 ( & V_2 -> V_38 , V_28 ) ;
memcpy ( V_29 , V_30 , V_27 ) ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
V_29 += V_27 ;
V_32 -> V_44 . V_45 += V_27 ;
}
V_40:
F_32 ( & V_2 -> V_38 , V_28 ) ;
V_19 -> V_2 = V_2 -> V_6 ;
V_7 = F_13 ( V_19 , V_56 ) ;
if ( V_7 != 0 ) {
F_10 ( L_12 ,
V_7 ) ;
}
}
static int F_33 ( struct V_1 * V_2 )
{
void * V_57 ;
int V_12 , V_58 ;
struct V_19 * V_19 ;
struct V_5 * V_6 ;
if ( V_2 == NULL )
return - V_59 ;
V_6 = V_2 -> V_6 ;
if ( V_2 -> V_18 )
F_10 ( L_13 ) ;
else
V_2 -> V_18 = F_34 ( V_17 , sizeof( * V_2 -> V_18 ) ,
V_20 ) ;
if ( V_2 -> V_18 == NULL ) {
F_10 ( L_14 ) ;
return - V_60 ;
}
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ ) {
if ( V_2 -> V_18 [ V_12 ] . V_61 == NULL ) {
V_57 = F_35 ( V_62 , V_20 ) ;
if ( V_57 == NULL ) {
F_10 ( L_15 ,
V_12 ) ;
goto V_63;
}
V_2 -> V_18 [ V_12 ] . V_61 = V_57 ;
} else
F_10 ( L_16 ) ;
if ( V_2 -> V_18 [ V_12 ] . V_19 == NULL ) {
V_19 = F_36 ( V_64 , V_20 ) ;
if ( V_19 == NULL ) {
F_10 ( L_17 , V_12 ) ;
goto V_63;
}
V_2 -> V_18 [ V_12 ] . V_19 = V_19 ;
} else {
F_10 ( L_18 ) ;
F_17 ( V_2 -> V_18 [ V_12 ] . V_19 ) ;
V_19 = V_2 -> V_18 [ V_12 ] . V_19 ;
}
V_19 -> V_65 = 1 ;
V_19 -> V_2 = V_6 ;
V_19 -> V_66 = F_37 ( V_6 , V_2 -> V_67 ) ;
V_19 -> V_68 = V_69 ;
V_19 -> V_50 = V_2 -> V_18 [ V_12 ] . V_61 ;
V_19 -> V_70 = V_62 ;
V_19 -> V_71 = F_23 ;
V_19 -> V_33 = V_2 ;
V_19 -> V_72 = 0 ;
V_19 -> V_46 = V_64 ;
for ( V_58 = 0 ; V_58 < V_64 ; V_58 ++ ) {
V_19 -> V_47 [ V_58 ] . V_51 = V_58 * V_73 ;
V_19 -> V_47 [ V_58 ] . V_74 = V_73 ;
}
}
F_38 ( V_2 ) ;
return 0 ;
V_63:
for ( V_12 = 0 ; V_12 < V_17 && V_2 -> V_18 [ V_12 ] . V_61 ; V_12 ++ )
F_39 ( V_2 -> V_18 [ V_12 ] . V_61 ) ;
for ( V_12 = 0 ; V_12 < V_17 && V_2 -> V_18 [ V_12 ] . V_19 ; V_12 ++ )
F_40 ( V_2 -> V_18 [ V_12 ] . V_19 ) ;
F_39 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
return - V_60 ;
}
static void F_41 ( struct V_1 * V_2 )
{
int V_12 ;
if ( V_2 == NULL || V_2 -> V_18 == NULL )
return;
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ ) {
struct V_19 * V_19 ;
V_19 = V_2 -> V_18 [ V_12 ] . V_19 ;
if ( V_19 ) {
if ( F_42 ( & V_2 -> V_21 ) && F_7 ( V_2 ) )
F_17 ( V_19 ) ;
F_40 ( V_19 ) ;
}
F_39 ( V_2 -> V_18 [ V_12 ] . V_61 ) ;
}
F_39 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
F_43 ( V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 , int V_3 )
{
struct V_31 * V_75 = V_2 -> V_76 + V_3 ;
F_45 ( & V_75 -> V_42 ) ;
V_75 -> V_44 . V_74 = F_46 ( V_2 -> V_52 ) ;
V_75 -> V_43 = F_47 ( V_75 -> V_44 . V_74 ) ;
if ( V_75 -> V_43 == NULL )
return - V_60 ;
V_75 -> V_77 = 0 ;
V_75 -> V_2 = V_2 ;
V_75 -> V_44 . V_3 = V_3 ;
V_75 -> V_44 . type = V_78 ;
V_75 -> V_44 . V_28 = V_79 ;
V_75 -> V_44 . V_80 = V_81 ;
V_75 -> V_44 . V_82 = V_83 ;
V_75 -> V_44 . V_84 . V_51 = 2 * V_3 * V_75 -> V_44 . V_74 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_12 ;
int V_85 ;
unsigned long V_28 ;
if ( V_2 -> V_86 == 0 || V_2 -> V_76 == NULL )
return 0 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_86 ; V_12 ++ ) {
if ( V_2 -> V_76 [ V_12 ] . V_77 > 0 )
return - V_87 ;
}
F_25 ( & V_2 -> V_38 , V_28 ) ;
F_45 ( & V_2 -> V_41 ) ;
F_45 ( & V_2 -> V_54 ) ;
V_85 = V_2 -> V_86 ;
V_2 -> V_86 = 0 ;
F_32 ( & V_2 -> V_38 , V_28 ) ;
for ( V_12 = 0 ; V_12 < V_85 ; V_12 ++ ) {
if ( V_2 -> V_76 [ V_12 ] . V_43 != NULL )
F_49 ( V_2 -> V_76 [ V_12 ] . V_43 ) ;
}
F_39 ( V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , unsigned V_86 )
{
int V_12 ;
if ( V_2 -> V_76 != NULL )
F_10 ( L_19 ) ;
else {
V_2 -> V_76 = F_35 ( V_86 * sizeof( struct V_31 ) ,
V_20 ) ;
if ( V_2 -> V_76 == NULL )
return - V_60 ;
for ( V_12 = 0 ; V_12 < V_86 ; V_12 ++ ) {
if ( F_44 ( V_2 , V_12 ) )
return ( V_2 -> V_86 > 1 ? 0 : - V_60 ) ;
V_2 -> V_86 = V_12 + 1 ;
}
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , unsigned V_86 )
{
int V_88 ;
V_88 = F_33 ( V_2 ) ;
if ( V_88 ) {
F_41 ( V_2 ) ;
return V_88 ;
}
V_88 = F_50 ( V_2 , V_86 ) ;
if ( V_88 ) {
F_48 ( V_2 ) ;
return V_88 ;
}
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_41 ( V_2 ) ;
F_48 ( V_2 ) ;
}
static int F_53 ( struct V_89 * V_90 )
{
static int V_91 = 1 ;
struct V_1 * V_2 ;
struct V_92 * V_93 ;
V_93 = F_54 ( V_90 ) ;
V_2 = F_55 ( V_93 ) ;
if ( V_2 == NULL || ! F_7 ( V_2 ) )
return - V_59 ;
if ( ! V_91 )
F_1 ( V_2 , 0x0 , 0x24 ) ;
else
V_91 = 0 ;
V_90 -> V_94 = V_2 ;
F_56 ( V_2 -> V_95 ) ;
return 0 ;
}
static int F_57 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_94 ;
if ( V_2 -> V_96 == V_90 ) {
F_16 ( V_2 ) ;
F_52 ( V_2 ) ;
F_1 ( V_2 , 0x0 , 0x49 ) ;
F_58 ( V_2 ) ;
V_2 -> V_96 = NULL ;
}
if ( F_7 ( V_2 ) )
F_59 ( V_2 -> V_95 ) ;
return 0 ;
}
static T_3 F_60 ( struct V_89 * V_90 , char T_4 * V_75 ,
T_5 V_97 , T_6 * V_98 )
{
int V_12 ;
int V_7 ;
unsigned long V_28 ;
struct V_31 * V_99 ;
struct V_1 * V_2 = V_90 -> V_94 ;
if ( ! F_7 ( V_2 ) )
return - V_100 ;
if ( V_2 -> V_96 && V_2 -> V_96 != V_90 )
return - V_87 ;
V_2 -> V_96 = V_90 ;
if ( ! F_61 ( V_2 ) ) {
if ( F_20 ( V_2 )
|| F_51 ( V_2 , 3 )
|| F_6 ( V_2 ) )
return - V_60 ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_86 ; V_12 ++ ) {
F_62 ( & V_2 -> V_76 [ V_12 ] . V_42 , & V_2 -> V_41 ) ;
V_2 -> V_76 [ V_12 ] . V_44 . V_28 = V_101 ;
}
F_32 ( & V_2 -> V_38 , V_28 ) ;
}
if ( * V_98 == 0 ) {
if ( V_90 -> V_102 & V_103 && F_26 ( & V_2 -> V_54 ) )
return - V_104 ;
V_7 = F_63 ( V_2 -> V_55 ,
! F_26 ( & V_2 -> V_54 ) || ! F_7 ( V_2 ) ) ;
if ( V_7 )
return V_7 ;
if ( ! F_7 ( V_2 ) )
return - V_100 ;
}
if ( V_97 + * V_98 > V_2 -> V_52 )
V_97 = V_2 -> V_52 - * V_98 ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
if ( F_26 ( & V_2 -> V_54 ) ) {
F_32 ( & V_2 -> V_38 , V_28 ) ;
F_10 ( L_20 ) ;
return 0 ;
}
V_99 = F_28 ( & V_2 -> V_54 , struct V_31 , V_42 ) ;
F_32 ( & V_2 -> V_38 , V_28 ) ;
if ( F_64 ( V_75 , V_99 -> V_43 + * V_98 , V_97 ) )
return - V_16 ;
* V_98 += V_97 ;
if ( * V_98 >= V_2 -> V_52 ) {
* V_98 = 0 ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
F_30 ( & V_99 -> V_42 , & V_2 -> V_41 ) ;
F_32 ( & V_2 -> V_38 , V_28 ) ;
}
return V_97 ;
}
static unsigned int F_65 ( struct V_89 * V_90 , T_7 * V_105 )
{
struct V_1 * V_2 = V_90 -> V_94 ;
F_66 ( V_90 , & V_2 -> V_55 , V_105 ) ;
if ( ! F_7 ( V_2 ) )
return V_106 ;
if ( ! F_26 ( & V_2 -> V_54 ) )
return V_107 | V_108 ;
return 0 ;
}
static void F_67 ( struct V_109 * V_110 )
{
struct V_31 * V_99 = V_110 -> V_111 ;
V_99 -> V_77 ++ ;
}
static void F_68 ( struct V_109 * V_110 )
{
struct V_31 * V_99 = V_110 -> V_111 ;
V_99 -> V_77 -- ;
if ( V_99 -> V_77 == 0 )
V_99 -> V_44 . V_28 &= ~ V_112 ;
}
static int F_69 ( struct V_89 * V_90 , struct V_109 * V_110 )
{
unsigned int V_12 ;
int V_7 ;
unsigned long V_51 = V_110 -> V_113 << V_114 ;
struct V_1 * V_2 = V_90 -> V_94 ;
struct V_31 * V_99 = NULL ;
if ( ! ( V_110 -> V_115 & V_116 ) || ! ( V_110 -> V_115 & V_117 ) )
return - V_118 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_86 ; V_12 ++ ) {
if ( V_2 -> V_76 [ V_12 ] . V_44 . V_84 . V_51 == V_51 ) {
V_99 = V_2 -> V_76 + V_12 ;
break;
}
}
if ( V_99 == NULL )
return - V_118 ;
V_7 = F_70 ( V_110 , V_99 -> V_43 , 0 ) ;
if ( V_7 )
return V_7 ;
V_110 -> V_115 |= V_119 ;
V_110 -> V_111 = V_99 ;
V_110 -> V_120 = & V_121 ;
V_99 -> V_44 . V_28 |= V_112 ;
F_67 ( V_110 ) ;
return 0 ;
}
static int F_71 ( struct V_89 * V_122 ,
void * V_123 , struct V_124 * V_125 )
{
strcpy ( V_125 -> V_126 , L_21 ) ;
strcpy ( V_125 -> V_127 , L_21 ) ;
V_125 -> V_128 = V_129 ;
V_125 -> V_130 = V_131
| V_132 | V_133 ;
return 0 ;
}
static int F_72 ( struct V_89 * V_122 ,
void * V_123 , struct V_134 * V_135 )
{
if ( V_135 -> V_3 != 0 )
return - V_118 ;
strcpy ( V_135 -> V_136 , L_22 ) ;
V_135 -> type = V_137 ;
return 0 ;
}
static int F_73 ( struct V_89 * V_122 , void * V_123 , unsigned int * V_12 )
{
* V_12 = 0 ;
return 0 ;
}
static int F_74 ( struct V_89 * V_122 , void * V_123 , unsigned int V_12 )
{
if ( V_12 != 0 )
return - V_118 ;
else
return 0 ;
}
static int F_75 ( struct V_89 * V_122 , void * V_123 , T_8 * V_138 )
{
return 0 ;
}
static int F_76 ( struct V_89 * V_122 ,
void * V_123 , struct V_139 * V_140 )
{
int V_12 ;
int V_141 ;
V_141 = F_77 ( V_142 ) ;
for ( V_12 = 0 ; V_12 < V_141 ; V_12 ++ ) {
if ( V_142 [ V_12 ] . V_143 == V_140 -> V_143 ) {
memcpy ( V_140 , & V_142 [ V_12 ] ,
sizeof( struct V_139 ) ) ;
return 0 ;
}
}
return - V_118 ;
}
static int F_78 ( struct V_89 * V_122 ,
void * V_123 , struct V_144 * V_140 )
{
struct V_1 * V_2 = V_123 ;
switch ( V_140 -> V_143 ) {
case V_145 :
V_140 -> V_4 = V_2 -> V_146 . V_147 ;
break;
case V_148 :
if ( F_79 ( V_149 ) )
V_140 -> V_4 = ! V_2 -> V_146 . V_150 ;
else
V_140 -> V_4 = V_2 -> V_146 . V_150 ;
break;
case V_151 :
if ( F_79 ( V_149 ) )
V_140 -> V_4 = ! V_2 -> V_146 . V_152 ;
else
V_140 -> V_4 = V_2 -> V_146 . V_152 ;
break;
default:
return - V_118 ;
}
return 0 ;
}
static int F_80 ( struct V_89 * V_122 ,
void * V_123 , struct V_144 * V_140 )
{
struct V_1 * V_2 = V_123 ;
switch ( V_140 -> V_143 ) {
case V_145 :
V_2 -> V_146 . V_147 = V_140 -> V_4 ;
return F_81 ( V_2 , V_140 -> V_4 >> 8 ) ;
case V_148 :
if ( F_79 ( V_149 ) )
V_2 -> V_146 . V_150 = ! V_140 -> V_4 ;
else
V_2 -> V_146 . V_150 = V_140 -> V_4 ;
return 0 ;
case V_151 :
if ( F_79 ( V_149 ) )
V_2 -> V_146 . V_152 = ! V_140 -> V_4 ;
else
V_2 -> V_146 . V_152 = V_140 -> V_4 ;
return 0 ;
default:
return - V_118 ;
}
return 0 ;
}
static int F_82 ( struct V_89 * V_122 ,
void * V_123 , struct V_153 * V_154 )
{
switch ( V_154 -> V_3 ) {
case 0 :
V_154 -> V_155 = V_156 ;
strcpy ( V_154 -> V_157 , L_23 ) ;
break;
case 1 :
V_154 -> V_155 = V_158 ;
strcpy ( V_154 -> V_157 , L_24 ) ;
break;
case 2 :
V_154 -> V_155 = V_159 ;
strcpy ( V_154 -> V_157 , L_25 ) ;
break;
case 3 :
V_154 -> V_155 = V_160 ;
strcpy ( V_154 -> V_157 , L_26 ) ;
break;
case 4 :
V_154 -> V_155 = V_161 ;
strcpy ( V_154 -> V_157 , L_25 ) ;
break;
default:
return - V_118 ;
}
return 0 ;
}
static int F_83 ( struct V_89 * V_122 ,
void * V_123 , struct V_162 * V_163 )
{
struct V_164 * V_165 = & V_163 -> V_166 . V_167 ;
struct V_1 * V_2 = V_123 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_77 ( V_168 ) &&
V_168 [ V_12 ] . V_84 != V_2 -> V_146 . V_169 ; V_12 ++ )
;
if ( V_12 == F_77 ( V_168 ) ) {
F_10 ( L_27 ) ;
return - V_118 ;
}
V_165 -> V_170 = V_168 [ V_12 ] . V_171 ;
V_165 -> V_172 = V_168 [ V_12 ] . V_173 ;
V_165 -> V_80 = V_81 ;
V_165 -> V_174 = V_175 ;
V_165 -> V_155 = V_2 -> V_146 . V_176 ;
if ( V_2 -> V_146 . V_176 == V_160 )
V_165 -> V_177 = V_165 -> V_170 ;
else
V_165 -> V_177 = 2 * V_165 -> V_170 ;
V_165 -> V_178 = V_165 -> V_177
* V_165 -> V_172 ;
return 0 ;
}
static int F_84 ( struct V_89 * V_122 ,
void * V_123 , struct V_162 * V_154 )
{
int V_12 ;
switch ( V_154 -> V_166 . V_167 . V_155 ) {
case V_156 :
case V_158 :
case V_159 :
case V_161 :
case V_160 :
break;
default:
return - V_118 ;
}
for ( V_12 = 1 ; V_12 < F_77 ( V_168 ) ; V_12 ++ ) {
if ( V_154 -> V_166 . V_167 . V_170 > V_168 [ V_12 ] . V_171 )
break;
}
if ( V_12 == F_77 ( V_168 )
|| ( abs ( V_154 -> V_166 . V_167 . V_170 - V_168 [ V_12 - 1 ] . V_171 )
< abs ( V_154 -> V_166 . V_167 . V_170 - V_168 [ V_12 ] . V_171 ) ) ) {
V_154 -> V_166 . V_167 . V_172 = V_168 [ V_12 - 1 ] . V_173 ;
V_154 -> V_166 . V_167 . V_170 = V_168 [ V_12 - 1 ] . V_171 ;
V_154 -> V_166 . V_167 . V_123 = V_12 - 1 ;
} else {
V_154 -> V_166 . V_167 . V_172 = V_168 [ V_12 ] . V_173 ;
V_154 -> V_166 . V_167 . V_170 = V_168 [ V_12 ] . V_171 ;
V_154 -> V_166 . V_167 . V_123 = V_12 ;
}
V_154 -> V_166 . V_167 . V_80 = V_81 ;
V_154 -> V_166 . V_167 . V_174 = V_175 ;
if ( V_154 -> V_166 . V_167 . V_155 == V_160 )
V_154 -> V_166 . V_167 . V_177 = V_154 -> V_166 . V_167 . V_170 ;
else
V_154 -> V_166 . V_167 . V_177 = 2 * V_154 -> V_166 . V_167 . V_170 ;
V_154 -> V_166 . V_167 . V_178 = V_154 -> V_166 . V_167 . V_177
* V_154 -> V_166 . V_167 . V_172 ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
int V_179 ;
if ( V_2 -> V_146 . V_176 == V_160 )
V_179 = 1 ;
else
V_179 = 2 ;
while ( V_12 < F_77 ( V_168 ) &&
V_168 [ V_12 ] . V_84 != V_2 -> V_146 . V_169 )
V_12 ++ ;
if ( V_12 == F_77 ( V_168 ) ) {
F_10 ( L_28 , V_180 ) ;
return - V_16 ;
}
F_1 ( V_2 , 0x001b , 0x0e ) ;
if ( V_2 -> V_146 . V_169 == V_181 )
F_1 ( V_2 , 0x001c , 0x0e ) ;
else
F_1 ( V_2 , 0x001c , 0x46 ) ;
F_1 ( V_2 , 0x0115 ,
( ( V_168 [ V_12 ] . V_171 * V_179 ) >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x0114 ,
( V_168 [ V_12 ] . V_171 * V_179 ) & 0xff ) ;
F_1 ( V_2 , 0x0117 ,
( V_168 [ V_12 ] . V_173 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x0116 ,
V_168 [ V_12 ] . V_173 & 0xff ) ;
return F_86 ( V_2 ) ;
}
static int F_87 ( struct V_89 * V_122 ,
void * V_123 , struct V_162 * V_154 )
{
int V_7 ;
struct V_1 * V_2 = V_123 ;
if ( V_2 == NULL )
return - V_15 ;
if ( ! F_7 ( V_2 ) )
return - V_15 ;
if ( F_61 ( V_2 ) )
return - V_87 ;
if ( V_2 -> V_96 && V_2 -> V_96 != V_122 )
return - V_87 ;
V_7 = F_84 ( V_122 , V_123 , V_154 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_96 = V_122 ;
V_2 -> V_146 . V_176 = V_154 -> V_166 . V_167 . V_155 ;
F_52 ( V_2 ) ;
V_2 -> V_52 = V_154 -> V_166 . V_167 . V_178 ;
V_2 -> V_146 . V_169 = V_168 [ V_154 -> V_166 . V_167 . V_123 ] . V_84 ;
F_20 ( V_2 ) ;
return F_85 ( V_2 ) ;
}
static int F_88 ( struct V_89 * V_122 ,
void * V_123 , struct V_182 * V_183 )
{
struct V_1 * V_2 = V_123 ;
if ( V_2 == NULL )
return - V_15 ;
if ( V_183 -> V_82 != V_83 )
return - V_118 ;
if ( F_61 ( V_2 )
|| ( V_2 -> V_96 && V_2 -> V_96 != V_122 ) )
return - V_87 ;
V_2 -> V_96 = V_122 ;
if ( V_183 -> V_97 < 3 )
V_183 -> V_97 = 3 ;
else if ( V_183 -> V_97 > 5 )
V_183 -> V_97 = 5 ;
F_51 ( V_2 , V_183 -> V_97 ) ;
V_183 -> V_97 = V_2 -> V_86 ;
return 0 ;
}
static int F_89 ( struct V_89 * V_122 ,
void * V_123 , struct V_184 * V_75 )
{
struct V_1 * V_2 = V_123 ;
struct V_31 * V_99 ;
if ( V_75 -> V_3 >= V_2 -> V_86 )
return - V_118 ;
V_99 = V_2 -> V_76 + V_75 -> V_3 ;
* V_75 = V_99 -> V_44 ;
return 0 ;
}
static int F_90 ( struct V_89 * V_122 ,
void * V_123 , struct V_184 * V_75 )
{
struct V_1 * V_2 = V_123 ;
struct V_31 * V_99 ;
unsigned long V_28 ;
if ( V_75 -> V_82 != V_83 )
return - V_118 ;
if ( V_75 -> V_3 >= V_2 -> V_86 )
return - V_118 ;
V_99 = V_2 -> V_76 + V_75 -> V_3 ;
if ( V_99 -> V_44 . V_28 & V_101 )
return 0 ;
V_99 -> V_44 . V_28 |= V_101 ;
V_99 -> V_44 . V_28 &= ~ V_185 ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
F_62 ( & V_99 -> V_42 , & V_2 -> V_41 ) ;
* V_75 = V_99 -> V_44 ;
F_32 ( & V_2 -> V_38 , V_28 ) ;
return 0 ;
}
static int F_91 ( struct V_89 * V_122 ,
void * V_123 , struct V_184 * V_75 )
{
struct V_1 * V_2 = V_123 ;
struct V_31 * V_99 ;
unsigned long V_28 ;
int V_7 ;
if ( ! F_61 ( V_2 ) )
return - V_118 ;
if ( V_122 -> V_102 & V_103 && F_26 ( & V_2 -> V_54 ) )
return - V_104 ;
V_7 = F_63 ( V_2 -> V_55 ,
! F_26 ( & V_2 -> V_54 ) || ! F_7 ( V_2 ) ) ;
if ( V_7 )
return V_7 ;
if ( ! F_7 ( V_2 ) )
return - V_100 ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
V_99 = F_28 ( & V_2 -> V_54 , struct V_31 , V_42 ) ;
F_92 ( & V_99 -> V_42 ) ;
F_32 ( & V_2 -> V_38 , V_28 ) ;
V_99 -> V_44 . V_28 &= ~ V_101 ;
V_99 -> V_44 . V_28 |= V_185 ;
V_99 -> V_44 . V_186 = ++ V_2 -> V_186 ;
F_93 ( & V_99 -> V_44 . V_187 ) ;
* V_75 = V_99 -> V_44 ;
return 0 ;
}
static int F_94 ( struct V_89 * V_122 ,
void * V_123 , enum V_188 type )
{
struct V_1 * V_2 = V_123 ;
if ( F_61 ( V_2 ) )
return 0 ;
if ( V_2 -> V_76 == NULL )
return - V_118 ;
V_2 -> V_186 = 0 ;
return F_6 ( V_2 ) ;
}
static int F_95 ( struct V_89 * V_122 ,
void * V_123 , enum V_188 type )
{
struct V_1 * V_2 = V_123 ;
unsigned long V_28 ;
int V_12 ;
F_16 ( V_2 ) ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
F_45 ( & V_2 -> V_41 ) ;
F_45 ( & V_2 -> V_54 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_86 ; V_12 ++ ) {
F_45 ( & V_2 -> V_76 [ V_12 ] . V_42 ) ;
V_2 -> V_76 [ V_12 ] . V_44 . V_28 = 0 ;
}
F_32 ( & V_2 -> V_38 , V_28 ) ;
return 0 ;
}
static int F_96 ( struct V_89 * V_122 ,
void * V_123 , struct V_189 * V_190 )
{
V_190 -> V_191 . V_192 . V_193 . V_194 = 1 ;
V_190 -> V_191 . V_192 . V_193 . V_195 = 30 ;
V_190 -> V_191 . V_192 . V_196 = 2 ;
return 0 ;
}
static int F_97 ( struct V_89 * V_122 ,
void * V_123 , struct V_197 * V_198 )
{
if ( V_198 -> V_3 >= F_77 ( V_168 ) )
return - V_118 ;
switch ( V_198 -> V_199 ) {
case V_156 :
case V_158 :
case V_159 :
case V_161 :
case V_160 :
V_198 -> type = V_200 ;
V_198 -> V_201 . V_170 = V_168 [ V_198 -> V_3 ] . V_171 ;
V_198 -> V_201 . V_172 = V_168 [ V_198 -> V_3 ] . V_173 ;
return 0 ;
default: return - V_118 ;
}
}
static void F_98 ( struct V_92 * V_202 )
{
struct V_1 * V_2 = F_55 ( V_202 ) ;
if ( V_2 -> V_76 != NULL || V_2 -> V_18 != NULL )
F_10 ( L_29 ) ;
F_99 ( V_2 -> V_95 ) ;
F_39 ( V_2 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_88 ;
V_2 -> V_93 = V_203 ;
V_2 -> V_93 . V_204 = V_204 ;
V_2 -> V_93 . V_205 = & V_2 -> V_95 -> V_2 ;
V_88 = F_101 ( & V_2 -> V_93 , V_206 , - 1 ) ;
if ( V_88 )
F_10 ( L_30 ) ;
else
F_102 ( L_31 ,
F_103 ( & V_2 -> V_93 ) ) ;
return V_88 ;
}
static int F_104 ( struct V_207 * V_95 ,
const struct V_208 * V_143 )
{
int V_12 ;
int V_88 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_5 * V_6 = F_105 ( V_95 ) ;
struct V_209 * V_210 ;
struct V_211 * V_212 ;
V_2 = F_35 ( sizeof( struct V_1 ) , V_20 ) ;
if ( V_2 == NULL ) {
F_10 ( L_32 ) ;
return - V_60 ;
}
F_106 ( & V_2 -> V_38 ) ;
F_107 ( & V_2 -> V_55 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_95 = V_95 ;
F_108 ( V_95 ) ;
if ( V_150 != - 1 )
V_2 -> V_146 . V_150 = V_150 ;
else if ( F_79 ( V_149 ) )
V_2 -> V_146 . V_150 = 1 ;
else
V_2 -> V_146 . V_150 = 0 ;
if ( V_152 != - 1 )
V_2 -> V_146 . V_152 = V_152 ;
else if ( F_79 ( V_149 ) )
V_2 -> V_146 . V_152 = 1 ;
else
V_2 -> V_146 . V_152 = 0 ;
V_2 -> V_86 = 0 ;
F_109 ( V_2 ) ;
V_210 = V_95 -> V_213 ;
for ( V_12 = 0 ; V_12 < V_210 -> V_214 . V_215 ; ++ V_12 ) {
V_212 = & V_210 -> V_212 [ V_12 ] . V_214 ;
if ( ! V_2 -> V_67
&& F_110 ( V_212 ) ) {
V_2 -> V_67 = F_111 ( V_212 ) ;
break;
}
}
if ( ! V_2 -> V_67 ) {
F_10 ( L_33 ) ;
V_88 = - V_15 ;
goto error;
}
V_2 -> V_146 . V_147 = 0x7fff ;
V_2 -> V_146 . V_176 = V_156 ;
V_2 -> V_146 . V_169 = V_216 ;
V_2 -> V_52 = 640 * 480 * 2 ;
F_45 ( & V_2 -> V_41 ) ;
F_45 ( & V_2 -> V_54 ) ;
F_112 ( V_95 , V_2 ) ;
V_88 = F_100 ( V_2 ) ;
if ( V_88 )
goto error;
return 0 ;
error:
F_39 ( V_2 ) ;
return V_88 ;
}
static void F_113 ( struct V_207 * V_95 )
{
struct V_1 * V_2 = F_114 ( V_95 ) ;
F_112 ( V_95 , NULL ) ;
F_115 ( V_2 ) ;
F_116 ( & V_2 -> V_55 ) ;
F_102 ( L_34 ,
F_103 ( & V_2 -> V_93 ) ) ;
F_117 ( & V_2 -> V_93 ) ;
}
static int F_118 ( struct V_207 * V_217 , T_9 V_218 )
{
struct V_1 * V_2 = F_114 ( V_217 ) ;
if ( F_61 ( V_2 ) ) {
F_16 ( V_2 ) ;
F_15 ( V_2 ) ;
}
return 0 ;
}
static int F_119 ( struct V_207 * V_217 )
{
struct V_1 * V_2 = F_114 ( V_217 ) ;
if ( ! F_9 ( V_2 ) )
return 0 ;
F_58 ( V_2 ) ;
F_20 ( V_2 ) ;
F_1 ( V_2 , 0x0 , 0x49 ) ;
F_85 ( V_2 ) ;
if ( F_61 ( V_2 ) )
F_6 ( V_2 ) ;
return 0 ;
}
