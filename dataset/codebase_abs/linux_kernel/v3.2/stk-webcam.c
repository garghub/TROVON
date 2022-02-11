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
V_2 -> V_18 = F_34 ( V_17 * sizeof( * V_2 -> V_18 ) ,
V_20 ) ;
if ( V_2 -> V_18 == NULL ) {
F_10 ( L_14 ) ;
return - V_60 ;
}
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ ) {
if ( V_2 -> V_18 [ V_12 ] . V_61 == NULL ) {
V_57 = F_34 ( V_62 , V_20 ) ;
if ( V_57 == NULL ) {
F_10 ( L_15 ,
V_12 ) ;
goto V_63;
}
V_2 -> V_18 [ V_12 ] . V_61 = V_57 ;
} else
F_10 ( L_16 ) ;
if ( V_2 -> V_18 [ V_12 ] . V_19 == NULL ) {
V_19 = F_35 ( V_64 , V_20 ) ;
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
V_19 -> V_66 = F_36 ( V_6 , V_2 -> V_67 ) ;
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
F_37 ( V_2 ) ;
return 0 ;
V_63:
for ( V_12 = 0 ; V_12 < V_17 && V_2 -> V_18 [ V_12 ] . V_61 ; V_12 ++ )
F_38 ( V_2 -> V_18 [ V_12 ] . V_61 ) ;
for ( V_12 = 0 ; V_12 < V_17 && V_2 -> V_18 [ V_12 ] . V_19 ; V_12 ++ )
F_39 ( V_2 -> V_18 [ V_12 ] . V_19 ) ;
F_38 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
return - V_60 ;
}
static void F_40 ( struct V_1 * V_2 )
{
int V_12 ;
if ( V_2 == NULL || V_2 -> V_18 == NULL )
return;
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ ) {
struct V_19 * V_19 ;
V_19 = V_2 -> V_18 [ V_12 ] . V_19 ;
if ( V_19 ) {
if ( F_41 ( & V_2 -> V_21 ) && F_7 ( V_2 ) )
F_17 ( V_19 ) ;
F_39 ( V_19 ) ;
}
F_38 ( V_2 -> V_18 [ V_12 ] . V_61 ) ;
}
F_38 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
F_42 ( V_2 ) ;
}
static int F_43 ( struct V_1 * V_2 , int V_3 )
{
struct V_31 * V_75 = V_2 -> V_76 + V_3 ;
F_44 ( & V_75 -> V_42 ) ;
V_75 -> V_44 . V_74 = F_45 ( V_2 -> V_52 ) ;
V_75 -> V_43 = F_46 ( V_75 -> V_44 . V_74 ) ;
if ( V_75 -> V_43 == NULL )
return - V_60 ;
V_75 -> V_77 = 0 ;
V_75 -> V_2 = V_2 ;
V_75 -> V_44 . V_3 = V_3 ;
V_75 -> V_44 . type = V_78 ;
V_75 -> V_44 . V_79 = V_80 ;
V_75 -> V_44 . V_81 = V_82 ;
V_75 -> V_44 . V_83 . V_51 = 2 * V_3 * V_75 -> V_44 . V_74 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_12 ;
int V_84 ;
unsigned long V_28 ;
if ( V_2 -> V_85 == 0 || V_2 -> V_76 == NULL )
return 0 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_85 ; V_12 ++ ) {
if ( V_2 -> V_76 [ V_12 ] . V_77 > 0 )
return - V_86 ;
}
F_25 ( & V_2 -> V_38 , V_28 ) ;
F_44 ( & V_2 -> V_41 ) ;
F_44 ( & V_2 -> V_54 ) ;
V_84 = V_2 -> V_85 ;
V_2 -> V_85 = 0 ;
F_32 ( & V_2 -> V_38 , V_28 ) ;
for ( V_12 = 0 ; V_12 < V_84 ; V_12 ++ ) {
if ( V_2 -> V_76 [ V_12 ] . V_43 != NULL )
F_48 ( V_2 -> V_76 [ V_12 ] . V_43 ) ;
}
F_38 ( V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , unsigned V_85 )
{
int V_12 ;
if ( V_2 -> V_76 != NULL )
F_10 ( L_19 ) ;
else {
V_2 -> V_76 = F_34 ( V_85 * sizeof( struct V_31 ) ,
V_20 ) ;
if ( V_2 -> V_76 == NULL )
return - V_60 ;
for ( V_12 = 0 ; V_12 < V_85 ; V_12 ++ ) {
if ( F_43 ( V_2 , V_12 ) )
return ( V_2 -> V_85 > 1 ? 0 : - V_60 ) ;
V_2 -> V_85 = V_12 + 1 ;
}
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , unsigned V_85 )
{
int V_87 ;
V_87 = F_33 ( V_2 ) ;
if ( V_87 ) {
F_40 ( V_2 ) ;
return V_87 ;
}
V_87 = F_49 ( V_2 , V_85 ) ;
if ( V_87 ) {
F_47 ( V_2 ) ;
return V_87 ;
}
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
F_47 ( V_2 ) ;
}
static int F_52 ( struct V_88 * V_89 )
{
struct V_1 * V_2 ;
struct V_90 * V_91 ;
V_91 = F_53 ( V_89 ) ;
V_2 = F_54 ( V_91 ) ;
if ( V_2 == NULL || ! F_7 ( V_2 ) )
return - V_59 ;
if ( ! V_92 )
F_1 ( V_2 , 0x0 , 0x24 ) ;
else
V_92 = 0 ;
V_89 -> V_93 = V_2 ;
F_55 ( V_2 -> V_94 ) ;
return 0 ;
}
static int F_56 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = V_89 -> V_93 ;
if ( V_2 -> V_95 == V_89 ) {
F_16 ( V_2 ) ;
F_51 ( V_2 ) ;
F_1 ( V_2 , 0x0 , 0x49 ) ;
F_57 ( V_2 ) ;
V_2 -> V_95 = NULL ;
}
if ( F_7 ( V_2 ) )
F_58 ( V_2 -> V_94 ) ;
return 0 ;
}
static T_3 F_59 ( struct V_88 * V_89 , char T_4 * V_75 ,
T_5 V_96 , T_6 * V_97 )
{
int V_12 ;
int V_7 ;
unsigned long V_28 ;
struct V_31 * V_98 ;
struct V_1 * V_2 = V_89 -> V_93 ;
if ( ! F_7 ( V_2 ) )
return - V_99 ;
if ( V_2 -> V_95 && V_2 -> V_95 != V_89 )
return - V_86 ;
V_2 -> V_95 = V_89 ;
if ( ! F_60 ( V_2 ) ) {
if ( F_20 ( V_2 )
|| F_50 ( V_2 , 3 )
|| F_6 ( V_2 ) )
return - V_60 ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_85 ; V_12 ++ ) {
F_61 ( & V_2 -> V_76 [ V_12 ] . V_42 , & V_2 -> V_41 ) ;
V_2 -> V_76 [ V_12 ] . V_44 . V_28 = V_100 ;
}
F_32 ( & V_2 -> V_38 , V_28 ) ;
}
if ( * V_97 == 0 ) {
if ( V_89 -> V_101 & V_102 && F_26 ( & V_2 -> V_54 ) )
return - V_103 ;
V_7 = F_62 ( V_2 -> V_55 ,
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
if ( F_63 ( V_75 , V_98 -> V_43 + * V_97 , V_96 ) )
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
static unsigned int F_64 ( struct V_88 * V_89 , T_7 * V_104 )
{
struct V_1 * V_2 = V_89 -> V_93 ;
F_65 ( V_89 , & V_2 -> V_55 , V_104 ) ;
if ( ! F_7 ( V_2 ) )
return V_105 ;
if ( ! F_26 ( & V_2 -> V_54 ) )
return V_106 | V_107 ;
return 0 ;
}
static void F_66 ( struct V_108 * V_109 )
{
struct V_31 * V_98 = V_109 -> V_110 ;
V_98 -> V_77 ++ ;
}
static void F_67 ( struct V_108 * V_109 )
{
struct V_31 * V_98 = V_109 -> V_110 ;
V_98 -> V_77 -- ;
if ( V_98 -> V_77 == 0 )
V_98 -> V_44 . V_28 &= ~ V_111 ;
}
static int F_68 ( struct V_88 * V_89 , struct V_108 * V_109 )
{
unsigned int V_12 ;
int V_7 ;
unsigned long V_51 = V_109 -> V_112 << V_113 ;
struct V_1 * V_2 = V_89 -> V_93 ;
struct V_31 * V_98 = NULL ;
if ( ! ( V_109 -> V_114 & V_115 ) || ! ( V_109 -> V_114 & V_116 ) )
return - V_117 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_85 ; V_12 ++ ) {
if ( V_2 -> V_76 [ V_12 ] . V_44 . V_83 . V_51 == V_51 ) {
V_98 = V_2 -> V_76 + V_12 ;
break;
}
}
if ( V_98 == NULL )
return - V_117 ;
V_7 = F_69 ( V_109 , V_98 -> V_43 , 0 ) ;
if ( V_7 )
return V_7 ;
V_109 -> V_114 |= V_118 ;
V_109 -> V_110 = V_98 ;
V_109 -> V_119 = & V_120 ;
V_98 -> V_44 . V_28 |= V_111 ;
F_66 ( V_109 ) ;
return 0 ;
}
static int F_70 ( struct V_88 * V_121 ,
void * V_122 , struct V_123 * V_124 )
{
strcpy ( V_124 -> V_125 , L_21 ) ;
strcpy ( V_124 -> V_126 , L_21 ) ;
V_124 -> V_127 = V_128 ;
V_124 -> V_129 = V_130
| V_131 | V_132 ;
return 0 ;
}
static int F_71 ( struct V_88 * V_121 ,
void * V_122 , struct V_133 * V_134 )
{
if ( V_134 -> V_3 != 0 )
return - V_117 ;
strcpy ( V_134 -> V_135 , L_22 ) ;
V_134 -> type = V_136 ;
return 0 ;
}
static int F_72 ( struct V_88 * V_121 , void * V_122 , unsigned int * V_12 )
{
* V_12 = 0 ;
return 0 ;
}
static int F_73 ( struct V_88 * V_121 , void * V_122 , unsigned int V_12 )
{
if ( V_12 != 0 )
return - V_117 ;
else
return 0 ;
}
static int F_74 ( struct V_88 * V_121 , void * V_122 , T_8 * V_137 )
{
return 0 ;
}
static int F_75 ( struct V_88 * V_121 ,
void * V_122 , struct V_138 * V_139 )
{
int V_12 ;
int V_140 ;
V_140 = F_76 ( V_141 ) ;
for ( V_12 = 0 ; V_12 < V_140 ; V_12 ++ ) {
if ( V_141 [ V_12 ] . V_142 == V_139 -> V_142 ) {
memcpy ( V_139 , & V_141 [ V_12 ] ,
sizeof( struct V_138 ) ) ;
return 0 ;
}
}
return - V_117 ;
}
static int F_77 ( struct V_88 * V_121 ,
void * V_122 , struct V_143 * V_139 )
{
struct V_1 * V_2 = V_122 ;
switch ( V_139 -> V_142 ) {
case V_144 :
V_139 -> V_4 = V_2 -> V_145 . V_146 ;
break;
case V_147 :
V_139 -> V_4 = V_2 -> V_145 . V_148 ;
break;
case V_149 :
V_139 -> V_4 = V_2 -> V_145 . V_150 ;
break;
default:
return - V_117 ;
}
return 0 ;
}
static int F_78 ( struct V_88 * V_121 ,
void * V_122 , struct V_143 * V_139 )
{
struct V_1 * V_2 = V_122 ;
switch ( V_139 -> V_142 ) {
case V_144 :
V_2 -> V_145 . V_146 = V_139 -> V_4 ;
return F_79 ( V_2 , V_139 -> V_4 >> 8 ) ;
case V_147 :
V_2 -> V_145 . V_148 = V_139 -> V_4 ;
return 0 ;
case V_149 :
V_2 -> V_145 . V_150 = V_139 -> V_4 ;
return 0 ;
default:
return - V_117 ;
}
return 0 ;
}
static int F_80 ( struct V_88 * V_121 ,
void * V_122 , struct V_151 * V_152 )
{
switch ( V_152 -> V_3 ) {
case 0 :
V_152 -> V_153 = V_154 ;
strcpy ( V_152 -> V_155 , L_23 ) ;
break;
case 1 :
V_152 -> V_153 = V_156 ;
strcpy ( V_152 -> V_155 , L_24 ) ;
break;
case 2 :
V_152 -> V_153 = V_157 ;
strcpy ( V_152 -> V_155 , L_25 ) ;
break;
case 3 :
V_152 -> V_153 = V_158 ;
strcpy ( V_152 -> V_155 , L_26 ) ;
break;
case 4 :
V_152 -> V_153 = V_159 ;
strcpy ( V_152 -> V_155 , L_25 ) ;
break;
default:
return - V_117 ;
}
return 0 ;
}
static int F_81 ( struct V_88 * V_121 ,
void * V_122 , struct V_160 * V_161 )
{
struct V_162 * V_163 = & V_161 -> V_164 . V_165 ;
struct V_1 * V_2 = V_122 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_76 ( V_166 ) &&
V_166 [ V_12 ] . V_83 != V_2 -> V_145 . V_167 ; V_12 ++ )
;
if ( V_12 == F_76 ( V_166 ) ) {
F_10 ( L_27 ) ;
return - V_117 ;
}
V_163 -> V_168 = V_166 [ V_12 ] . V_169 ;
V_163 -> V_170 = V_166 [ V_12 ] . V_171 ;
V_163 -> V_79 = V_80 ;
V_163 -> V_172 = V_173 ;
V_163 -> V_153 = V_2 -> V_145 . V_174 ;
if ( V_2 -> V_145 . V_174 == V_158 )
V_163 -> V_175 = V_163 -> V_168 ;
else
V_163 -> V_175 = 2 * V_163 -> V_168 ;
V_163 -> V_176 = V_163 -> V_175
* V_163 -> V_170 ;
return 0 ;
}
static int F_82 ( struct V_88 * V_121 ,
void * V_122 , struct V_160 * V_152 )
{
int V_12 ;
switch ( V_152 -> V_164 . V_165 . V_153 ) {
case V_154 :
case V_156 :
case V_157 :
case V_159 :
case V_158 :
break;
default:
return - V_117 ;
}
for ( V_12 = 1 ; V_12 < F_76 ( V_166 ) ; V_12 ++ ) {
if ( V_152 -> V_164 . V_165 . V_168 > V_166 [ V_12 ] . V_169 )
break;
}
if ( V_12 == F_76 ( V_166 )
|| ( abs ( V_152 -> V_164 . V_165 . V_168 - V_166 [ V_12 - 1 ] . V_169 )
< abs ( V_152 -> V_164 . V_165 . V_168 - V_166 [ V_12 ] . V_169 ) ) ) {
V_152 -> V_164 . V_165 . V_170 = V_166 [ V_12 - 1 ] . V_171 ;
V_152 -> V_164 . V_165 . V_168 = V_166 [ V_12 - 1 ] . V_169 ;
V_152 -> V_164 . V_165 . V_122 = V_12 - 1 ;
} else {
V_152 -> V_164 . V_165 . V_170 = V_166 [ V_12 ] . V_171 ;
V_152 -> V_164 . V_165 . V_168 = V_166 [ V_12 ] . V_169 ;
V_152 -> V_164 . V_165 . V_122 = V_12 ;
}
V_152 -> V_164 . V_165 . V_79 = V_80 ;
V_152 -> V_164 . V_165 . V_172 = V_173 ;
if ( V_152 -> V_164 . V_165 . V_153 == V_158 )
V_152 -> V_164 . V_165 . V_175 = V_152 -> V_164 . V_165 . V_168 ;
else
V_152 -> V_164 . V_165 . V_175 = 2 * V_152 -> V_164 . V_165 . V_168 ;
V_152 -> V_164 . V_165 . V_176 = V_152 -> V_164 . V_165 . V_175
* V_152 -> V_164 . V_165 . V_170 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
int V_177 ;
if ( V_2 -> V_145 . V_174 == V_158 )
V_177 = 1 ;
else
V_177 = 2 ;
while ( V_12 < F_76 ( V_166 ) &&
V_166 [ V_12 ] . V_83 != V_2 -> V_145 . V_167 )
V_12 ++ ;
if ( V_12 == F_76 ( V_166 ) ) {
F_10 ( L_28 , V_178 ) ;
return - V_16 ;
}
F_1 ( V_2 , 0x001b , 0x0e ) ;
if ( V_2 -> V_145 . V_167 == V_179 )
F_1 ( V_2 , 0x001c , 0x0e ) ;
else
F_1 ( V_2 , 0x001c , 0x46 ) ;
F_1 ( V_2 , 0x0115 ,
( ( V_166 [ V_12 ] . V_169 * V_177 ) >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x0114 ,
( V_166 [ V_12 ] . V_169 * V_177 ) & 0xff ) ;
F_1 ( V_2 , 0x0117 ,
( V_166 [ V_12 ] . V_171 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x0116 ,
V_166 [ V_12 ] . V_171 & 0xff ) ;
return F_84 ( V_2 ) ;
}
static int F_85 ( struct V_88 * V_121 ,
void * V_122 , struct V_160 * V_152 )
{
int V_7 ;
struct V_1 * V_2 = V_122 ;
if ( V_2 == NULL )
return - V_15 ;
if ( ! F_7 ( V_2 ) )
return - V_15 ;
if ( F_60 ( V_2 ) )
return - V_86 ;
if ( V_2 -> V_95 && V_2 -> V_95 != V_121 )
return - V_86 ;
V_7 = F_82 ( V_121 , V_122 , V_152 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_95 = V_121 ;
V_2 -> V_145 . V_174 = V_152 -> V_164 . V_165 . V_153 ;
F_51 ( V_2 ) ;
V_2 -> V_52 = V_152 -> V_164 . V_165 . V_176 ;
V_2 -> V_145 . V_167 = V_166 [ V_152 -> V_164 . V_165 . V_122 ] . V_83 ;
F_20 ( V_2 ) ;
return F_83 ( V_2 ) ;
}
static int F_86 ( struct V_88 * V_121 ,
void * V_122 , struct V_180 * V_181 )
{
struct V_1 * V_2 = V_122 ;
if ( V_2 == NULL )
return - V_15 ;
if ( V_181 -> V_81 != V_82 )
return - V_117 ;
if ( F_60 ( V_2 )
|| ( V_2 -> V_95 && V_2 -> V_95 != V_121 ) )
return - V_86 ;
V_2 -> V_95 = V_121 ;
if ( V_181 -> V_96 < 3 )
V_181 -> V_96 = 3 ;
else if ( V_181 -> V_96 > 5 )
V_181 -> V_96 = 5 ;
F_50 ( V_2 , V_181 -> V_96 ) ;
V_181 -> V_96 = V_2 -> V_85 ;
return 0 ;
}
static int F_87 ( struct V_88 * V_121 ,
void * V_122 , struct V_182 * V_75 )
{
struct V_1 * V_2 = V_122 ;
struct V_31 * V_98 ;
if ( V_75 -> V_3 >= V_2 -> V_85 )
return - V_117 ;
V_98 = V_2 -> V_76 + V_75 -> V_3 ;
* V_75 = V_98 -> V_44 ;
return 0 ;
}
static int F_88 ( struct V_88 * V_121 ,
void * V_122 , struct V_182 * V_75 )
{
struct V_1 * V_2 = V_122 ;
struct V_31 * V_98 ;
unsigned long V_28 ;
if ( V_75 -> V_81 != V_82 )
return - V_117 ;
if ( V_75 -> V_3 >= V_2 -> V_85 )
return - V_117 ;
V_98 = V_2 -> V_76 + V_75 -> V_3 ;
if ( V_98 -> V_44 . V_28 & V_100 )
return 0 ;
V_98 -> V_44 . V_28 |= V_100 ;
V_98 -> V_44 . V_28 &= ~ V_183 ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
F_61 ( & V_98 -> V_42 , & V_2 -> V_41 ) ;
* V_75 = V_98 -> V_44 ;
F_32 ( & V_2 -> V_38 , V_28 ) ;
return 0 ;
}
static int F_89 ( struct V_88 * V_121 ,
void * V_122 , struct V_182 * V_75 )
{
struct V_1 * V_2 = V_122 ;
struct V_31 * V_98 ;
unsigned long V_28 ;
int V_7 ;
if ( ! F_60 ( V_2 ) )
return - V_117 ;
if ( V_121 -> V_101 & V_102 && F_26 ( & V_2 -> V_54 ) )
return - V_103 ;
V_7 = F_62 ( V_2 -> V_55 ,
! F_26 ( & V_2 -> V_54 ) || ! F_7 ( V_2 ) ) ;
if ( V_7 )
return V_7 ;
if ( ! F_7 ( V_2 ) )
return - V_99 ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
V_98 = F_28 ( & V_2 -> V_54 , struct V_31 , V_42 ) ;
F_90 ( & V_98 -> V_42 ) ;
F_32 ( & V_2 -> V_38 , V_28 ) ;
V_98 -> V_44 . V_28 &= ~ V_100 ;
V_98 -> V_44 . V_28 |= V_183 ;
V_98 -> V_44 . V_184 = ++ V_2 -> V_184 ;
F_91 ( & V_98 -> V_44 . V_185 ) ;
* V_75 = V_98 -> V_44 ;
return 0 ;
}
static int F_92 ( struct V_88 * V_121 ,
void * V_122 , enum V_186 type )
{
struct V_1 * V_2 = V_122 ;
if ( F_60 ( V_2 ) )
return 0 ;
if ( V_2 -> V_76 == NULL )
return - V_117 ;
V_2 -> V_184 = 0 ;
return F_6 ( V_2 ) ;
}
static int F_93 ( struct V_88 * V_121 ,
void * V_122 , enum V_186 type )
{
struct V_1 * V_2 = V_122 ;
unsigned long V_28 ;
int V_12 ;
F_16 ( V_2 ) ;
F_25 ( & V_2 -> V_38 , V_28 ) ;
F_44 ( & V_2 -> V_41 ) ;
F_44 ( & V_2 -> V_54 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_85 ; V_12 ++ ) {
F_44 ( & V_2 -> V_76 [ V_12 ] . V_42 ) ;
V_2 -> V_76 [ V_12 ] . V_44 . V_28 = 0 ;
}
F_32 ( & V_2 -> V_38 , V_28 ) ;
return 0 ;
}
static int F_94 ( struct V_88 * V_121 ,
void * V_122 , struct V_187 * V_188 )
{
V_188 -> V_189 . V_190 . V_191 . V_192 = 1 ;
V_188 -> V_189 . V_190 . V_191 . V_193 = 30 ;
V_188 -> V_189 . V_190 . V_194 = 2 ;
return 0 ;
}
static int F_95 ( struct V_88 * V_121 ,
void * V_122 , struct V_195 * V_196 )
{
if ( V_196 -> V_3 >= F_76 ( V_166 ) )
return - V_117 ;
switch ( V_196 -> V_197 ) {
case V_154 :
case V_156 :
case V_157 :
case V_159 :
case V_158 :
V_196 -> type = V_198 ;
V_196 -> V_199 . V_168 = V_166 [ V_196 -> V_3 ] . V_169 ;
V_196 -> V_199 . V_170 = V_166 [ V_196 -> V_3 ] . V_171 ;
return 0 ;
default: return - V_117 ;
}
}
static void F_96 ( struct V_90 * V_200 )
{
struct V_1 * V_2 = F_54 ( V_200 ) ;
if ( V_2 -> V_76 != NULL || V_2 -> V_18 != NULL )
F_10 ( L_29 ) ;
F_97 ( V_2 -> V_94 ) ;
F_38 ( V_2 ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_87 ;
V_2 -> V_91 = V_201 ;
V_2 -> V_91 . V_202 = V_202 ;
V_2 -> V_91 . V_203 = & V_2 -> V_94 -> V_2 ;
V_87 = F_99 ( & V_2 -> V_91 , V_204 , - 1 ) ;
if ( V_87 )
F_10 ( L_30 ) ;
else
F_100 ( L_31 ,
F_101 ( & V_2 -> V_91 ) ) ;
return V_87 ;
}
static int F_102 ( struct V_205 * V_94 ,
const struct V_206 * V_142 )
{
int V_12 ;
int V_87 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_5 * V_6 = F_103 ( V_94 ) ;
struct V_207 * V_208 ;
struct V_209 * V_210 ;
V_2 = F_34 ( sizeof( struct V_1 ) , V_20 ) ;
if ( V_2 == NULL ) {
F_10 ( L_32 ) ;
return - V_60 ;
}
F_104 ( & V_2 -> V_38 ) ;
F_105 ( & V_2 -> V_55 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_94 = V_94 ;
F_106 ( V_94 ) ;
V_2 -> V_145 . V_150 = V_150 ;
V_2 -> V_145 . V_148 = V_148 ;
V_2 -> V_85 = 0 ;
F_107 ( V_2 ) ;
V_208 = V_94 -> V_211 ;
for ( V_12 = 0 ; V_12 < V_208 -> V_212 . V_213 ; ++ V_12 ) {
V_210 = & V_208 -> V_210 [ V_12 ] . V_212 ;
if ( ! V_2 -> V_67
&& F_108 ( V_210 ) ) {
V_2 -> V_67 = F_109 ( V_210 ) ;
break;
}
}
if ( ! V_2 -> V_67 ) {
F_10 ( L_33 ) ;
V_87 = - V_15 ;
goto error;
}
V_2 -> V_145 . V_146 = 0x7fff ;
V_2 -> V_145 . V_174 = V_154 ;
V_2 -> V_145 . V_167 = V_214 ;
V_2 -> V_52 = 640 * 480 * 2 ;
F_44 ( & V_2 -> V_41 ) ;
F_44 ( & V_2 -> V_54 ) ;
F_110 ( V_94 , V_2 ) ;
V_87 = F_98 ( V_2 ) ;
if ( V_87 )
goto error;
return 0 ;
error:
F_38 ( V_2 ) ;
return V_87 ;
}
static void F_111 ( struct V_205 * V_94 )
{
struct V_1 * V_2 = F_112 ( V_94 ) ;
F_110 ( V_94 , NULL ) ;
F_113 ( V_2 ) ;
F_114 ( & V_2 -> V_55 ) ;
F_100 ( L_34 ,
F_101 ( & V_2 -> V_91 ) ) ;
F_115 ( & V_2 -> V_91 ) ;
}
static int F_116 ( struct V_205 * V_215 , T_9 V_216 )
{
struct V_1 * V_2 = F_112 ( V_215 ) ;
if ( F_60 ( V_2 ) ) {
F_16 ( V_2 ) ;
F_15 ( V_2 ) ;
}
return 0 ;
}
static int F_117 ( struct V_205 * V_215 )
{
struct V_1 * V_2 = F_112 ( V_215 ) ;
if ( ! F_9 ( V_2 ) )
return 0 ;
F_57 ( V_2 ) ;
F_20 ( V_2 ) ;
F_1 ( V_2 , 0x0 , 0x49 ) ;
F_83 ( V_2 ) ;
if ( F_60 ( V_2 ) )
F_6 ( V_2 ) ;
return 0 ;
}
static int T_10 F_118 ( void )
{
int V_217 ;
V_217 = F_119 ( & V_218 ) ;
if ( V_217 )
F_10 ( L_35 , V_217 ) ;
return V_217 ;
}
static void T_11 F_120 ( void )
{
F_121 ( & V_218 ) ;
}
