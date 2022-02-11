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
for ( V_12 = 0 ; V_12 < V_85 ; V_12 ++ )
F_49 ( V_2 -> V_76 [ V_12 ] . V_43 ) ;
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
struct V_1 * V_2 = F_54 ( V_90 ) ;
int V_88 ;
if ( V_2 == NULL || ! F_7 ( V_2 ) )
return - V_59 ;
if ( F_55 ( & V_2 -> V_91 ) )
return - V_92 ;
if ( ! V_2 -> V_93 )
F_1 ( V_2 , 0x0 , 0x24 ) ;
else
V_2 -> V_93 = 0 ;
V_88 = F_56 ( V_90 ) ;
if ( ! V_88 )
F_57 ( V_2 -> V_94 ) ;
F_58 ( & V_2 -> V_91 ) ;
return V_88 ;
}
static int F_59 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_54 ( V_90 ) ;
F_60 ( & V_2 -> V_91 ) ;
if ( V_2 -> V_95 == V_90 ) {
F_16 ( V_2 ) ;
F_52 ( V_2 ) ;
F_1 ( V_2 , 0x0 , 0x49 ) ;
F_61 ( V_2 ) ;
V_2 -> V_95 = NULL ;
}
if ( F_7 ( V_2 ) )
F_62 ( V_2 -> V_94 ) ;
F_58 ( & V_2 -> V_91 ) ;
return F_63 ( V_90 ) ;
}
static T_3 F_64 ( struct V_89 * V_90 , char T_4 * V_75 ,
T_5 V_96 , T_6 * V_97 )
{
int V_12 ;
int V_7 ;
unsigned long V_28 ;
struct V_31 * V_98 ;
struct V_1 * V_2 = F_54 ( V_90 ) ;
if ( ! F_7 ( V_2 ) )
return - V_99 ;
if ( V_2 -> V_95 && ( ! V_2 -> V_100 || V_2 -> V_95 != V_90 ) )
return - V_87 ;
V_2 -> V_95 = V_90 ;
if ( ! F_65 ( V_2 ) ) {
if ( F_20 ( V_2 )
|| F_51 ( V_2 , 3 )
|| F_6 ( V_2 ) )
return - V_60 ;
V_2 -> V_100 = 1 ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_86 ; V_12 ++ ) {
F_66 ( & V_2 -> V_76 [ V_12 ] . V_42 , & V_2 -> V_41 ) ;
V_2 -> V_76 [ V_12 ] . V_44 . V_28 = V_101 ;
}
F_32 ( & V_2 -> V_38 , V_28 ) ;
}
if ( * V_97 == 0 ) {
if ( V_90 -> V_102 & V_103 && F_26 ( & V_2 -> V_54 ) )
return - V_104 ;
V_7 = F_67 ( V_2 -> V_55 ,
! F_26 ( & V_2 -> V_54 ) || ! F_7 ( V_2 ) ) ;
if ( V_7 )
return V_7 ;
if ( ! F_7 ( V_2 ) )
return - V_99 ;
}
if ( V_96 + * V_97 > V_2 -> V_52 )
V_96 = V_2 -> V_52 - * V_97 ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
if ( F_26 ( & V_2 -> V_54 ) ) {
F_32 ( & V_2 -> V_38 , V_28 ) ;
F_10 ( L_20 ) ;
return 0 ;
}
V_98 = F_28 ( & V_2 -> V_54 , struct V_31 , V_42 ) ;
F_32 ( & V_2 -> V_38 , V_28 ) ;
if ( F_68 ( V_75 , V_98 -> V_43 + * V_97 , V_96 ) )
return - V_16 ;
* V_97 += V_96 ;
if ( * V_97 >= V_2 -> V_52 ) {
* V_97 = 0 ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
F_30 ( & V_98 -> V_42 , & V_2 -> V_41 ) ;
F_32 ( & V_2 -> V_38 , V_28 ) ;
}
return V_96 ;
}
static T_3 F_69 ( struct V_89 * V_90 , char T_4 * V_75 ,
T_5 V_96 , T_6 * V_97 )
{
struct V_1 * V_2 = F_54 ( V_90 ) ;
int V_7 ;
if ( F_55 ( & V_2 -> V_91 ) )
return - V_92 ;
V_7 = F_64 ( V_90 , V_75 , V_96 , V_97 ) ;
F_58 ( & V_2 -> V_91 ) ;
return V_7 ;
}
static unsigned int F_70 ( struct V_89 * V_90 , T_7 * V_105 )
{
struct V_1 * V_2 = F_54 ( V_90 ) ;
unsigned V_106 = F_71 ( V_90 , V_105 ) ;
F_72 ( V_90 , & V_2 -> V_55 , V_105 ) ;
if ( ! F_7 ( V_2 ) )
return V_107 ;
if ( ! F_26 ( & V_2 -> V_54 ) )
return V_106 | V_108 | V_109 ;
return V_106 ;
}
static void F_73 ( struct V_110 * V_111 )
{
struct V_31 * V_98 = V_111 -> V_112 ;
V_98 -> V_77 ++ ;
}
static void F_74 ( struct V_110 * V_111 )
{
struct V_31 * V_98 = V_111 -> V_112 ;
V_98 -> V_77 -- ;
if ( V_98 -> V_77 == 0 )
V_98 -> V_44 . V_28 &= ~ V_113 ;
}
static int F_75 ( struct V_89 * V_90 , struct V_110 * V_111 )
{
unsigned int V_12 ;
int V_7 ;
unsigned long V_51 = V_111 -> V_114 << V_115 ;
struct V_1 * V_2 = F_54 ( V_90 ) ;
struct V_31 * V_98 = NULL ;
if ( ! ( V_111 -> V_116 & V_117 ) || ! ( V_111 -> V_116 & V_118 ) )
return - V_119 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_86 ; V_12 ++ ) {
if ( V_2 -> V_76 [ V_12 ] . V_44 . V_84 . V_51 == V_51 ) {
V_98 = V_2 -> V_76 + V_12 ;
break;
}
}
if ( V_98 == NULL )
return - V_119 ;
V_7 = F_76 ( V_111 , V_98 -> V_43 , 0 ) ;
if ( V_7 )
return V_7 ;
V_111 -> V_116 |= V_120 ;
V_111 -> V_112 = V_98 ;
V_111 -> V_121 = & V_122 ;
V_98 -> V_44 . V_28 |= V_113 ;
F_73 ( V_111 ) ;
return 0 ;
}
static int F_77 ( struct V_89 * V_123 ,
void * V_124 , struct V_125 * V_126 )
{
struct V_1 * V_2 = F_54 ( V_123 ) ;
strcpy ( V_126 -> V_127 , L_21 ) ;
strcpy ( V_126 -> V_128 , L_21 ) ;
F_78 ( V_2 -> V_6 , V_126 -> V_129 , sizeof( V_126 -> V_129 ) ) ;
V_126 -> V_130 = V_131
| V_132 | V_133 ;
V_126 -> V_134 = V_126 -> V_130 | V_135 ;
return 0 ;
}
static int F_79 ( struct V_89 * V_123 ,
void * V_124 , struct V_136 * V_137 )
{
if ( V_137 -> V_3 != 0 )
return - V_119 ;
strcpy ( V_137 -> V_138 , L_22 ) ;
V_137 -> type = V_139 ;
return 0 ;
}
static int F_80 ( struct V_89 * V_123 , void * V_124 , unsigned int * V_12 )
{
* V_12 = 0 ;
return 0 ;
}
static int F_81 ( struct V_89 * V_123 , void * V_124 , unsigned int V_12 )
{
return V_12 ? - V_119 : 0 ;
}
static int F_82 ( struct V_140 * V_141 )
{
struct V_1 * V_2 =
F_83 ( V_141 -> V_142 , struct V_1 , V_143 ) ;
switch ( V_141 -> V_144 ) {
case V_145 :
return F_84 ( V_2 , V_141 -> V_26 ) ;
case V_146 :
if ( F_85 ( V_147 ) )
V_2 -> V_148 . V_149 = ! V_141 -> V_26 ;
else
V_2 -> V_148 . V_149 = V_141 -> V_26 ;
return 0 ;
case V_150 :
if ( F_85 ( V_147 ) )
V_2 -> V_148 . V_151 = ! V_141 -> V_26 ;
else
V_2 -> V_148 . V_151 = V_141 -> V_26 ;
return 0 ;
default:
return - V_119 ;
}
return 0 ;
}
static int F_86 ( struct V_89 * V_123 ,
void * V_124 , struct V_152 * V_153 )
{
switch ( V_153 -> V_3 ) {
case 0 :
V_153 -> V_154 = V_155 ;
strcpy ( V_153 -> V_156 , L_23 ) ;
break;
case 1 :
V_153 -> V_154 = V_157 ;
strcpy ( V_153 -> V_156 , L_24 ) ;
break;
case 2 :
V_153 -> V_154 = V_158 ;
strcpy ( V_153 -> V_156 , L_25 ) ;
break;
case 3 :
V_153 -> V_154 = V_159 ;
strcpy ( V_153 -> V_156 , L_26 ) ;
break;
case 4 :
V_153 -> V_154 = V_160 ;
strcpy ( V_153 -> V_156 , L_25 ) ;
break;
default:
return - V_119 ;
}
return 0 ;
}
static int F_87 ( struct V_89 * V_123 ,
void * V_124 , struct V_161 * V_162 )
{
struct V_163 * V_164 = & V_162 -> V_165 . V_166 ;
struct V_1 * V_2 = F_54 ( V_123 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_88 ( V_167 ) &&
V_167 [ V_12 ] . V_84 != V_2 -> V_148 . V_168 ; V_12 ++ )
;
if ( V_12 == F_88 ( V_167 ) ) {
F_10 ( L_27 ) ;
return - V_119 ;
}
V_164 -> V_169 = V_167 [ V_12 ] . V_170 ;
V_164 -> V_171 = V_167 [ V_12 ] . V_172 ;
V_164 -> V_80 = V_81 ;
V_164 -> V_173 = V_174 ;
V_164 -> V_154 = V_2 -> V_148 . V_175 ;
if ( V_2 -> V_148 . V_175 == V_159 )
V_164 -> V_176 = V_164 -> V_169 ;
else
V_164 -> V_176 = 2 * V_164 -> V_169 ;
V_164 -> V_177 = V_164 -> V_176
* V_164 -> V_171 ;
return 0 ;
}
static int F_89 ( struct V_89 * V_123 ,
struct V_161 * V_153 , int * V_178 )
{
int V_12 ;
switch ( V_153 -> V_165 . V_166 . V_154 ) {
case V_155 :
case V_157 :
case V_158 :
case V_160 :
case V_159 :
break;
default:
return - V_119 ;
}
for ( V_12 = 1 ; V_12 < F_88 ( V_167 ) ; V_12 ++ ) {
if ( V_153 -> V_165 . V_166 . V_169 > V_167 [ V_12 ] . V_170 )
break;
}
if ( V_12 == F_88 ( V_167 )
|| ( abs ( V_153 -> V_165 . V_166 . V_169 - V_167 [ V_12 - 1 ] . V_170 )
< abs ( V_153 -> V_165 . V_166 . V_169 - V_167 [ V_12 ] . V_170 ) ) ) {
V_153 -> V_165 . V_166 . V_171 = V_167 [ V_12 - 1 ] . V_172 ;
V_153 -> V_165 . V_166 . V_169 = V_167 [ V_12 - 1 ] . V_170 ;
if ( V_178 )
* V_178 = V_12 - 1 ;
} else {
V_153 -> V_165 . V_166 . V_171 = V_167 [ V_12 ] . V_172 ;
V_153 -> V_165 . V_166 . V_169 = V_167 [ V_12 ] . V_170 ;
if ( V_178 )
* V_178 = V_12 ;
}
V_153 -> V_165 . V_166 . V_80 = V_81 ;
V_153 -> V_165 . V_166 . V_173 = V_174 ;
if ( V_153 -> V_165 . V_166 . V_154 == V_159 )
V_153 -> V_165 . V_166 . V_176 = V_153 -> V_165 . V_166 . V_169 ;
else
V_153 -> V_165 . V_166 . V_176 = 2 * V_153 -> V_165 . V_166 . V_169 ;
V_153 -> V_165 . V_166 . V_177 = V_153 -> V_165 . V_166 . V_176
* V_153 -> V_165 . V_166 . V_171 ;
return 0 ;
}
static int F_90 ( struct V_89 * V_123 ,
void * V_124 , struct V_161 * V_153 )
{
return F_89 ( V_123 , V_153 , NULL ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
int V_179 ;
if ( V_2 -> V_148 . V_175 == V_159 )
V_179 = 1 ;
else
V_179 = 2 ;
while ( V_12 < F_88 ( V_167 ) &&
V_167 [ V_12 ] . V_84 != V_2 -> V_148 . V_168 )
V_12 ++ ;
if ( V_12 == F_88 ( V_167 ) ) {
F_10 ( L_28 , V_180 ) ;
return - V_16 ;
}
F_1 ( V_2 , 0x001b , 0x0e ) ;
if ( V_2 -> V_148 . V_168 == V_181 )
F_1 ( V_2 , 0x001c , 0x0e ) ;
else
F_1 ( V_2 , 0x001c , 0x46 ) ;
F_1 ( V_2 , 0x0115 ,
( ( V_167 [ V_12 ] . V_170 * V_179 ) >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x0114 ,
( V_167 [ V_12 ] . V_170 * V_179 ) & 0xff ) ;
F_1 ( V_2 , 0x0117 ,
( V_167 [ V_12 ] . V_172 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x0116 ,
V_167 [ V_12 ] . V_172 & 0xff ) ;
return F_92 ( V_2 ) ;
}
static int F_93 ( struct V_89 * V_123 ,
void * V_124 , struct V_161 * V_153 )
{
int V_7 ;
int V_178 ;
struct V_1 * V_2 = F_54 ( V_123 ) ;
if ( V_2 == NULL )
return - V_15 ;
if ( ! F_7 ( V_2 ) )
return - V_15 ;
if ( F_65 ( V_2 ) )
return - V_87 ;
if ( V_2 -> V_95 )
return - V_87 ;
V_7 = F_89 ( V_123 , V_153 , & V_178 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_148 . V_175 = V_153 -> V_165 . V_166 . V_154 ;
F_52 ( V_2 ) ;
V_2 -> V_52 = V_153 -> V_165 . V_166 . V_177 ;
V_2 -> V_148 . V_168 = V_167 [ V_178 ] . V_84 ;
F_20 ( V_2 ) ;
return F_91 ( V_2 ) ;
}
static int F_94 ( struct V_89 * V_123 ,
void * V_124 , struct V_182 * V_183 )
{
struct V_1 * V_2 = F_54 ( V_123 ) ;
if ( V_2 == NULL )
return - V_15 ;
if ( V_183 -> V_82 != V_83 )
return - V_119 ;
if ( F_65 ( V_2 )
|| ( V_2 -> V_95 && V_2 -> V_95 != V_123 ) )
return - V_87 ;
F_52 ( V_2 ) ;
if ( V_183 -> V_96 == 0 ) {
F_1 ( V_2 , 0x0 , 0x49 ) ;
F_61 ( V_2 ) ;
V_2 -> V_95 = NULL ;
return 0 ;
}
V_2 -> V_95 = V_123 ;
if ( V_183 -> V_96 < 3 )
V_183 -> V_96 = 3 ;
else if ( V_183 -> V_96 > 5 )
V_183 -> V_96 = 5 ;
F_51 ( V_2 , V_183 -> V_96 ) ;
V_183 -> V_96 = V_2 -> V_86 ;
return 0 ;
}
static int F_95 ( struct V_89 * V_123 ,
void * V_124 , struct V_184 * V_75 )
{
struct V_1 * V_2 = F_54 ( V_123 ) ;
struct V_31 * V_98 ;
if ( V_75 -> V_3 >= V_2 -> V_86 )
return - V_119 ;
V_98 = V_2 -> V_76 + V_75 -> V_3 ;
* V_75 = V_98 -> V_44 ;
return 0 ;
}
static int F_96 ( struct V_89 * V_123 ,
void * V_124 , struct V_184 * V_75 )
{
struct V_1 * V_2 = F_54 ( V_123 ) ;
struct V_31 * V_98 ;
unsigned long V_28 ;
if ( V_75 -> V_82 != V_83 )
return - V_119 ;
if ( V_75 -> V_3 >= V_2 -> V_86 )
return - V_119 ;
V_98 = V_2 -> V_76 + V_75 -> V_3 ;
if ( V_98 -> V_44 . V_28 & V_101 )
return 0 ;
V_98 -> V_44 . V_28 |= V_101 ;
V_98 -> V_44 . V_28 &= ~ V_185 ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
F_66 ( & V_98 -> V_42 , & V_2 -> V_41 ) ;
* V_75 = V_98 -> V_44 ;
F_32 ( & V_2 -> V_38 , V_28 ) ;
return 0 ;
}
static int F_97 ( struct V_89 * V_123 ,
void * V_124 , struct V_184 * V_75 )
{
struct V_1 * V_2 = F_54 ( V_123 ) ;
struct V_31 * V_98 ;
unsigned long V_28 ;
int V_7 ;
if ( ! F_65 ( V_2 ) )
return - V_119 ;
if ( V_123 -> V_102 & V_103 && F_26 ( & V_2 -> V_54 ) )
return - V_104 ;
V_7 = F_67 ( V_2 -> V_55 ,
! F_26 ( & V_2 -> V_54 ) || ! F_7 ( V_2 ) ) ;
if ( V_7 )
return V_7 ;
if ( ! F_7 ( V_2 ) )
return - V_99 ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
V_98 = F_28 ( & V_2 -> V_54 , struct V_31 , V_42 ) ;
F_98 ( & V_98 -> V_42 ) ;
F_32 ( & V_2 -> V_38 , V_28 ) ;
V_98 -> V_44 . V_28 &= ~ V_101 ;
V_98 -> V_44 . V_28 |= V_185 ;
V_98 -> V_44 . V_186 = ++ V_2 -> V_186 ;
F_99 ( & V_98 -> V_44 . V_187 ) ;
* V_75 = V_98 -> V_44 ;
return 0 ;
}
static int F_100 ( struct V_89 * V_123 ,
void * V_124 , enum V_188 type )
{
struct V_1 * V_2 = F_54 ( V_123 ) ;
if ( F_65 ( V_2 ) )
return 0 ;
if ( V_2 -> V_76 == NULL )
return - V_119 ;
V_2 -> V_186 = 0 ;
return F_6 ( V_2 ) ;
}
static int F_101 ( struct V_89 * V_123 ,
void * V_124 , enum V_188 type )
{
struct V_1 * V_2 = F_54 ( V_123 ) ;
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
static int F_102 ( struct V_89 * V_123 ,
void * V_124 , struct V_189 * V_190 )
{
V_190 -> V_191 . V_192 . V_193 . V_194 = 1 ;
V_190 -> V_191 . V_192 . V_193 . V_195 = 30 ;
V_190 -> V_191 . V_192 . V_196 = 2 ;
return 0 ;
}
static int F_103 ( struct V_89 * V_123 ,
void * V_124 , struct V_197 * V_198 )
{
if ( V_198 -> V_3 >= F_88 ( V_167 ) )
return - V_119 ;
switch ( V_198 -> V_199 ) {
case V_155 :
case V_157 :
case V_158 :
case V_160 :
case V_159 :
V_198 -> type = V_200 ;
V_198 -> V_201 . V_169 = V_167 [ V_198 -> V_3 ] . V_170 ;
V_198 -> V_201 . V_171 = V_167 [ V_198 -> V_3 ] . V_172 ;
return 0 ;
default: return - V_119 ;
}
}
static void F_104 ( struct V_202 * V_203 )
{
struct V_1 * V_2 = F_105 ( V_203 ) ;
if ( V_2 -> V_76 != NULL || V_2 -> V_18 != NULL )
F_10 ( L_29 ) ;
F_106 ( V_2 -> V_94 ) ;
F_39 ( V_2 ) ;
}
static int F_107 ( struct V_1 * V_2 )
{
int V_88 ;
V_2 -> V_204 = V_205 ;
V_2 -> V_204 . V_91 = & V_2 -> V_91 ;
V_2 -> V_204 . V_206 = & V_2 -> V_206 ;
F_108 ( & V_2 -> V_204 , V_2 ) ;
V_88 = F_109 ( & V_2 -> V_204 , V_207 , - 1 ) ;
if ( V_88 )
F_10 ( L_30 ) ;
else
F_110 ( L_31 ,
F_111 ( & V_2 -> V_204 ) ) ;
return V_88 ;
}
static int F_112 ( struct V_208 * V_94 ,
const struct V_209 * V_144 )
{
struct V_210 * V_143 ;
int V_88 = 0 ;
int V_12 ;
struct V_1 * V_2 = NULL ;
struct V_5 * V_6 = F_113 ( V_94 ) ;
struct V_211 * V_212 ;
struct V_213 * V_214 ;
V_2 = F_35 ( sizeof( struct V_1 ) , V_20 ) ;
if ( V_2 == NULL ) {
F_10 ( L_32 ) ;
return - V_60 ;
}
V_88 = F_114 ( & V_94 -> V_2 , & V_2 -> V_206 ) ;
if ( V_88 < 0 ) {
F_115 ( & V_6 -> V_2 , L_33 ) ;
F_39 ( V_2 ) ;
return V_88 ;
}
V_143 = & V_2 -> V_143 ;
F_116 ( V_143 , 3 ) ;
F_117 ( V_143 , & V_215 ,
V_145 , 0 , 0xff , 0x1 , 0x60 ) ;
F_117 ( V_143 , & V_215 ,
V_146 , 0 , 1 , 1 , 1 ) ;
F_117 ( V_143 , & V_215 ,
V_150 , 0 , 1 , 1 , 1 ) ;
if ( V_143 -> error ) {
V_88 = V_143 -> error ;
F_115 ( & V_6 -> V_2 , L_34 ) ;
goto error;
}
V_2 -> V_206 . V_216 = V_143 ;
F_118 ( & V_2 -> V_38 ) ;
F_119 ( & V_2 -> V_91 ) ;
F_120 ( & V_2 -> V_55 ) ;
V_2 -> V_93 = 1 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_94 = V_94 ;
F_121 ( V_94 ) ;
if ( V_149 != - 1 )
V_2 -> V_148 . V_149 = V_149 ;
else if ( F_85 ( V_147 ) )
V_2 -> V_148 . V_149 = 1 ;
else
V_2 -> V_148 . V_149 = 0 ;
if ( V_151 != - 1 )
V_2 -> V_148 . V_151 = V_151 ;
else if ( F_85 ( V_147 ) )
V_2 -> V_148 . V_151 = 1 ;
else
V_2 -> V_148 . V_151 = 0 ;
V_2 -> V_86 = 0 ;
F_122 ( V_2 ) ;
V_212 = V_94 -> V_217 ;
for ( V_12 = 0 ; V_12 < V_212 -> V_218 . V_219 ; ++ V_12 ) {
V_214 = & V_212 -> V_214 [ V_12 ] . V_218 ;
if ( ! V_2 -> V_67
&& F_123 ( V_214 ) ) {
V_2 -> V_67 = F_124 ( V_214 ) ;
break;
}
}
if ( ! V_2 -> V_67 ) {
F_10 ( L_35 ) ;
V_88 = - V_15 ;
goto error;
}
V_2 -> V_148 . V_175 = V_155 ;
V_2 -> V_148 . V_168 = V_220 ;
V_2 -> V_52 = 640 * 480 * 2 ;
F_45 ( & V_2 -> V_41 ) ;
F_45 ( & V_2 -> V_54 ) ;
F_125 ( V_94 , V_2 ) ;
V_88 = F_107 ( V_2 ) ;
if ( V_88 )
goto error;
return 0 ;
error:
F_126 ( V_143 ) ;
F_127 ( & V_2 -> V_206 ) ;
F_39 ( V_2 ) ;
return V_88 ;
}
static void F_128 ( struct V_208 * V_94 )
{
struct V_1 * V_2 = F_129 ( V_94 ) ;
F_125 ( V_94 , NULL ) ;
F_130 ( V_2 ) ;
F_131 ( & V_2 -> V_55 ) ;
F_110 ( L_36 ,
F_111 ( & V_2 -> V_204 ) ) ;
F_132 ( & V_2 -> V_204 ) ;
F_126 ( & V_2 -> V_143 ) ;
F_127 ( & V_2 -> V_206 ) ;
}
static int F_133 ( struct V_208 * V_221 , T_8 V_222 )
{
struct V_1 * V_2 = F_129 ( V_221 ) ;
if ( F_65 ( V_2 ) ) {
F_16 ( V_2 ) ;
F_15 ( V_2 ) ;
}
return 0 ;
}
static int F_134 ( struct V_208 * V_221 )
{
struct V_1 * V_2 = F_129 ( V_221 ) ;
if ( ! F_9 ( V_2 ) )
return 0 ;
F_61 ( V_2 ) ;
F_20 ( V_2 ) ;
F_1 ( V_2 , 0x0 , 0x49 ) ;
F_91 ( V_2 ) ;
if ( F_65 ( V_2 ) )
F_6 ( V_2 ) ;
return 0 ;
}
