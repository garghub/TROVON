static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , & V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_4 ) ;
F_5 ( V_2 ) ;
F_6 ( & V_4 ) ;
}
static struct V_1 * F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_9 ;
struct V_10 * V_11 ;
F_8 ( & V_4 ) ;
F_9 (s, node, &atalk_sockets) {
struct V_12 * V_13 = F_10 ( V_9 ) ;
if ( V_6 -> V_14 != V_13 -> V_15 )
continue;
if ( V_6 -> V_16 . V_17 == V_18 &&
V_6 -> V_16 . V_19 == V_20 )
goto V_21;
if ( V_6 -> V_16 . V_17 == V_13 -> V_22 &&
( V_6 -> V_16 . V_19 == V_13 -> V_23 ||
V_6 -> V_16 . V_19 == V_20 ||
V_6 -> V_16 . V_19 == V_24 ) )
goto V_21;
if ( V_6 -> V_16 . V_19 == V_24 &&
V_6 -> V_16 . V_17 != V_18 &&
V_8 -> V_25 . V_19 == V_13 -> V_23 ) {
V_6 -> V_16 . V_19 = V_8 -> V_25 . V_19 ;
goto V_21;
}
}
V_9 = NULL ;
V_21:
F_11 ( & V_4 ) ;
return V_9 ;
}
static struct V_1 * F_12 ( struct V_1 * V_2 ,
struct V_5 * V_26 )
{
struct V_1 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
F_4 ( & V_4 ) ;
F_9 (s, node, &atalk_sockets) {
V_13 = F_10 ( V_9 ) ;
if ( V_13 -> V_22 == V_26 -> V_16 . V_17 &&
V_13 -> V_23 == V_26 -> V_16 . V_19 &&
V_13 -> V_15 == V_26 -> V_14 )
goto V_21;
}
V_9 = NULL ;
F_1 ( V_2 ) ;
V_21:
F_6 ( & V_4 ) ;
return V_9 ;
}
static void F_13 ( unsigned long V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
if ( F_14 ( V_2 ) ) {
V_2 -> V_28 . V_29 = V_30 + V_31 ;
F_15 ( & V_2 -> V_28 ) ;
} else
F_16 ( V_2 ) ;
}
static inline void F_17 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
F_18 ( & V_2 -> V_32 ) ;
if ( F_14 ( V_2 ) ) {
F_19 ( & V_2 -> V_28 , F_13 ,
( unsigned long ) V_2 ) ;
V_2 -> V_28 . V_29 = V_30 + V_31 ;
F_15 ( & V_2 -> V_28 ) ;
} else
F_16 ( V_2 ) ;
}
static void F_20 ( struct V_33 * V_34 )
{
struct V_7 * * V_35 = & V_36 ;
struct V_7 * V_37 ;
F_4 ( & V_38 ) ;
while ( ( V_37 = * V_35 ) != NULL ) {
if ( V_37 -> V_34 == V_34 ) {
* V_35 = V_37 -> V_39 ;
F_21 ( V_34 ) ;
F_22 ( V_37 ) ;
V_34 -> V_40 = NULL ;
} else
V_35 = & V_37 -> V_39 ;
}
F_6 ( & V_38 ) ;
}
static struct V_7 * F_23 ( struct V_33 * V_34 ,
struct V_41 * V_42 )
{
struct V_7 * V_35 = F_24 ( sizeof( * V_35 ) , V_43 ) ;
if ( ! V_35 )
goto V_44;
F_25 ( V_34 ) ;
V_35 -> V_34 = V_34 ;
V_34 -> V_40 = V_35 ;
V_35 -> V_25 = * V_42 ;
V_35 -> V_45 = 0 ;
F_4 ( & V_38 ) ;
V_35 -> V_39 = V_36 ;
V_36 = V_35 ;
F_6 ( & V_38 ) ;
V_44:
return V_35 ;
}
static int F_26 ( struct V_7 * V_8 )
{
int V_46 = F_27 ( V_8 -> V_47 . V_48 ) -
F_27 ( V_8 -> V_47 . V_49 ) + 1 ;
int V_50 = F_27 ( V_8 -> V_25 . V_17 ) ;
int V_51 = V_8 -> V_25 . V_19 ;
int V_52 , V_53 ;
if ( V_50 == V_18 ) {
V_50 = F_27 ( V_8 -> V_47 . V_49 ) ;
if ( V_46 )
V_50 += V_30 % V_46 ;
}
if ( V_51 == V_24 )
V_51 = V_30 & 0xFF ;
V_8 -> V_45 |= V_54 ;
for ( V_52 = 0 ; V_52 <= V_46 ; V_52 ++ ) {
V_8 -> V_25 . V_17 = F_28 ( V_50 ) ;
for ( V_53 = 0 ; V_53 < 256 ; V_53 ++ ) {
V_8 -> V_25 . V_19 = ( V_53 + V_51 ) & 0xFF ;
if ( V_8 -> V_25 . V_19 > 0 &&
V_8 -> V_25 . V_19 < 254 ) {
F_29 ( V_8 ) ;
if ( ! ( V_8 -> V_45 & V_55 ) ) {
V_8 -> V_45 &= ~ V_54 ;
return 0 ;
}
}
V_8 -> V_45 &= ~ V_55 ;
}
V_50 ++ ;
if ( V_50 > F_27 ( V_8 -> V_47 . V_48 ) )
V_50 = F_27 ( V_8 -> V_47 . V_49 ) ;
}
V_8 -> V_45 &= ~ V_54 ;
return - V_56 ;
}
static int F_30 ( struct V_7 * V_8 ,
struct V_41 * V_57 )
{
int V_46 = F_27 ( V_8 -> V_47 . V_48 ) -
F_27 ( V_8 -> V_47 . V_49 ) + 1 ;
int V_50 = F_27 ( V_8 -> V_25 . V_17 ) ;
int V_51 = V_24 ;
int V_52 , V_53 ;
if ( V_50 == V_18 ) {
V_50 = F_27 ( V_8 -> V_47 . V_49 ) ;
if ( V_46 )
V_50 += V_30 % V_46 ;
}
if ( V_51 == V_24 )
V_51 = V_30 & 0xFF ;
for ( V_52 = 0 ; V_52 <= V_46 ; V_52 ++ ) {
V_57 -> V_17 = F_28 ( V_50 ) ;
for ( V_53 = 0 ; V_53 < 256 ; V_53 ++ ) {
V_57 -> V_19 = ( V_53 + V_51 ) & 0xFF ;
if ( V_57 -> V_19 > 0 &&
V_57 -> V_19 < 254 ) {
int V_58 = F_31 ( V_8 ,
V_57 ) ;
if ( V_58 != - V_56 )
return V_58 ;
}
}
V_50 ++ ;
if ( V_50 > F_27 ( V_8 -> V_47 . V_48 ) )
V_50 = F_27 ( V_8 -> V_47 . V_49 ) ;
}
return - V_56 ;
}
struct V_41 * F_32 ( struct V_33 * V_34 )
{
struct V_7 * V_35 = V_34 -> V_40 ;
return V_35 ? & V_35 -> V_25 : NULL ;
}
static struct V_41 * F_33 ( void )
{
struct V_7 * V_59 = NULL ;
struct V_41 * V_60 ;
struct V_7 * V_35 ;
F_8 ( & V_38 ) ;
for ( V_35 = V_36 ; V_35 ; V_35 = V_35 -> V_39 ) {
if ( ! V_59 && ! ( V_35 -> V_34 -> V_61 & V_62 ) )
V_59 = V_35 ;
if ( ! ( V_35 -> V_34 -> V_61 & ( V_62 | V_63 ) ) ) {
V_60 = & V_35 -> V_25 ;
goto V_44;
}
}
if ( V_59 )
V_60 = & V_59 -> V_25 ;
else if ( V_36 )
V_60 = & V_36 -> V_25 ;
else
V_60 = NULL ;
V_44:
F_11 ( & V_38 ) ;
return V_60 ;
}
static struct V_7 * F_34 ( int V_11 , struct V_33 * V_34 )
{
struct V_7 * V_35 = V_34 -> V_40 ;
if ( ! V_35 || V_35 -> V_45 & V_54 )
goto V_64;
if ( V_11 != V_20 &&
V_35 -> V_25 . V_19 != V_11 &&
V_11 != V_24 )
goto V_64;
V_44:
return V_35 ;
V_64:
V_35 = NULL ;
goto V_44;
}
static struct V_7 * F_35 ( T_1 V_65 , int V_11 )
{
struct V_7 * V_35 ;
F_8 ( & V_38 ) ;
for ( V_35 = V_36 ; V_35 ; V_35 = V_35 -> V_39 ) {
if ( ( V_11 == V_20 ||
V_11 == V_24 ||
V_35 -> V_25 . V_19 == V_11 ) &&
V_35 -> V_25 . V_17 == V_65 &&
! ( V_35 -> V_45 & V_54 ) )
break;
if ( V_11 == V_24 && V_65 != V_18 &&
F_27 ( V_35 -> V_47 . V_49 ) <= F_27 ( V_65 ) &&
F_27 ( V_65 ) <= F_27 ( V_35 -> V_47 . V_48 ) )
break;
}
F_11 ( & V_38 ) ;
return V_35 ;
}
static struct V_66 * F_36 ( struct V_41 * V_67 )
{
struct V_66 * V_68 = NULL ;
struct V_66 * V_69 ;
F_8 ( & V_70 ) ;
for ( V_69 = V_71 ; V_69 ; V_69 = V_69 -> V_39 ) {
if ( ! ( V_69 -> V_61 & V_72 ) )
continue;
if ( V_69 -> V_67 . V_17 == V_67 -> V_17 ) {
if ( V_69 -> V_61 & V_73 ) {
if ( V_69 -> V_67 . V_19 == V_67 -> V_19 )
goto V_44;
} else
V_68 = V_69 ;
}
}
if ( V_68 )
V_69 = V_68 ;
else if ( V_74 . V_34 )
V_69 = & V_74 ;
else
V_69 = NULL ;
V_44:
F_11 ( & V_70 ) ;
return V_69 ;
}
struct V_33 * F_37 ( struct V_41 * V_42 )
{
struct V_66 * V_75 = F_36 ( V_42 ) ;
return V_75 ? V_75 -> V_34 : NULL ;
}
static void F_38 ( struct V_33 * V_34 )
{
V_74 . V_34 = V_34 ;
V_74 . V_61 = V_72 ;
V_74 . V_76 . V_17 = F_28 ( 0 ) ;
V_74 . V_76 . V_19 = 0 ;
}
static int F_39 ( struct V_77 * V_69 , struct V_33 * V_78 )
{
struct V_5 * V_79 = (struct V_5 * ) & V_69 -> V_80 ;
struct V_5 * V_81 = (struct V_5 * ) & V_69 -> V_82 ;
struct V_66 * V_83 ;
struct V_7 * V_35 , * V_84 ;
int V_60 = - V_85 ;
if ( V_79 -> V_86 != V_87 ||
( ! V_78 && V_81 -> V_86 != V_87 ) )
goto V_44;
F_4 ( & V_70 ) ;
for ( V_83 = V_71 ; V_83 ; V_83 = V_83 -> V_39 ) {
if ( V_69 -> V_88 != V_83 -> V_61 )
continue;
if ( V_79 -> V_16 . V_17 == V_83 -> V_67 . V_17 ) {
if ( ! ( V_83 -> V_61 & V_73 ) )
break;
if ( V_79 -> V_16 . V_19 == V_83 -> V_67 . V_19 )
break;
}
}
if ( ! V_78 ) {
V_84 = NULL ;
F_8 ( & V_38 ) ;
for ( V_35 = V_36 ; V_35 ; V_35 = V_35 -> V_39 ) {
if ( ! V_84 &&
F_27 ( V_81 -> V_16 . V_17 ) >=
F_27 ( V_35 -> V_47 . V_49 ) &&
F_27 ( V_81 -> V_16 . V_17 ) <=
F_27 ( V_35 -> V_47 . V_48 ) )
V_84 = V_35 ;
if ( V_81 -> V_16 . V_17 == V_35 -> V_25 . V_17 &&
V_81 -> V_16 . V_19 == V_35 -> V_25 . V_19 )
V_84 = V_35 ;
}
F_11 ( & V_38 ) ;
V_60 = - V_89 ;
if ( ! V_84 )
goto V_90;
V_78 = V_84 -> V_34 ;
}
if ( ! V_83 ) {
V_83 = F_24 ( sizeof( * V_83 ) , V_91 ) ;
V_60 = - V_92 ;
if ( ! V_83 )
goto V_90;
V_83 -> V_39 = V_71 ;
V_71 = V_83 ;
}
V_83 -> V_67 = V_79 -> V_16 ;
F_25 ( V_78 ) ;
V_83 -> V_34 = V_78 ;
V_83 -> V_61 = V_69 -> V_88 ;
V_83 -> V_76 = V_81 -> V_16 ;
V_60 = 0 ;
V_90:
F_6 ( & V_70 ) ;
V_44:
return V_60 ;
}
static int F_40 ( struct V_41 * V_93 )
{
struct V_66 * * V_69 = & V_71 ;
int V_60 = 0 ;
struct V_66 * V_37 ;
F_4 ( & V_70 ) ;
while ( ( V_37 = * V_69 ) != NULL ) {
if ( V_37 -> V_67 . V_17 == V_93 -> V_17 &&
( ! ( V_37 -> V_61 & V_94 ) ||
V_37 -> V_67 . V_19 == V_93 -> V_19 ) ) {
* V_69 = V_37 -> V_39 ;
F_21 ( V_37 -> V_34 ) ;
F_22 ( V_37 ) ;
goto V_44;
}
V_69 = & V_37 -> V_39 ;
}
V_60 = - V_95 ;
V_44:
F_6 ( & V_70 ) ;
return V_60 ;
}
static void F_41 ( struct V_33 * V_34 )
{
struct V_66 * * V_69 = & V_71 ;
struct V_66 * V_37 ;
F_4 ( & V_70 ) ;
while ( ( V_37 = * V_69 ) != NULL ) {
if ( V_37 -> V_34 == V_34 ) {
* V_69 = V_37 -> V_39 ;
F_21 ( V_34 ) ;
F_22 ( V_37 ) ;
} else
V_69 = & V_37 -> V_39 ;
}
F_6 ( & V_70 ) ;
if ( V_74 . V_34 == V_34 )
F_38 ( NULL ) ;
}
static inline void F_42 ( struct V_33 * V_34 )
{
F_41 ( V_34 ) ;
F_43 ( V_34 ) ;
F_20 ( V_34 ) ;
}
static int F_44 ( struct V_96 * V_97 , unsigned long V_98 ,
void * V_99 )
{
struct V_33 * V_34 = V_99 ;
if ( ! F_45 ( F_46 ( V_34 ) , & V_100 ) )
return V_101 ;
if ( V_98 == V_102 )
F_42 ( V_34 ) ;
return V_101 ;
}
static int F_47 ( int V_103 , void T_2 * V_104 )
{
static char V_105 [ 6 ] = { 0x09 , 0x00 , 0x00 , 0xFF , 0xFF , 0xFF } ;
struct V_106 V_107 ;
struct V_108 * V_109 ;
struct V_5 * V_42 ;
struct V_33 * V_34 ;
struct V_7 * V_8 ;
int V_110 ;
int V_111 ;
struct V_77 V_112 ;
int V_113 ;
if ( F_48 ( & V_107 , V_104 , sizeof( V_107 ) ) )
return - V_114 ;
V_34 = F_49 ( & V_100 , V_107 . V_115 ) ;
if ( ! V_34 )
return - V_116 ;
V_42 = (struct V_5 * ) & V_107 . V_117 ;
V_8 = F_50 ( V_34 ) ;
switch ( V_103 ) {
case V_118 :
if ( ! F_51 ( V_119 ) )
return - V_120 ;
if ( V_42 -> V_86 != V_87 )
return - V_85 ;
if ( V_34 -> type != V_121 &&
V_34 -> type != V_122 &&
V_34 -> type != V_123 &&
V_34 -> type != V_124 )
return - V_125 ;
V_109 = (struct V_108 * ) & V_42 -> V_126 [ 0 ] ;
V_113 = 1 ;
if ( ( V_34 -> V_61 & V_63 ) &&
F_35 ( V_42 -> V_16 . V_17 ,
V_42 -> V_16 . V_19 ) ) {
F_52 ( V_127 L_1
L_2
L_3 ) ;
V_113 = 0 ;
}
if ( V_34 -> type == V_121 && V_109 -> V_128 != 2 )
return - V_125 ;
if ( V_42 -> V_16 . V_19 == V_20 ||
V_42 -> V_16 . V_19 == 254 )
return - V_85 ;
if ( V_8 ) {
if ( V_8 -> V_45 & V_54 )
return - V_129 ;
V_8 -> V_25 . V_17 = V_42 -> V_16 . V_17 ;
V_8 -> V_25 . V_19 = V_42 -> V_16 . V_19 ;
F_41 ( V_34 ) ;
} else {
V_8 = F_23 ( V_34 , & V_42 -> V_16 ) ;
if ( ! V_8 )
return - V_130 ;
}
V_8 -> V_47 = * V_109 ;
if ( ! ( V_34 -> V_61 & V_62 ) &&
! ( V_34 -> V_61 & V_63 ) &&
F_26 ( V_8 ) < 0 ) {
F_20 ( V_34 ) ;
return - V_56 ;
}
V_42 = (struct V_5 * ) & V_112 . V_82 ;
V_42 -> V_86 = V_87 ;
V_42 -> V_16 . V_17 = V_8 -> V_25 . V_17 ;
V_42 -> V_16 . V_19 = V_8 -> V_25 . V_19 ;
V_42 = (struct V_5 * ) & V_112 . V_80 ;
V_112 . V_88 = V_72 ;
V_42 -> V_86 = V_87 ;
V_42 -> V_16 . V_19 = V_24 ;
if ( V_34 -> V_61 & V_62 ||
V_34 -> V_61 & V_63 )
V_112 . V_88 |= V_73 ;
if ( V_109 -> V_49 == F_28 ( 0 ) &&
V_109 -> V_48 == F_28 ( 0xFFFE ) ) {
V_42 -> V_16 . V_17 = V_8 -> V_25 . V_17 ;
F_39 ( & V_112 , V_34 ) ;
F_38 ( V_34 ) ;
} else {
V_111 = F_27 ( V_109 -> V_48 ) ;
if ( V_111 - F_27 ( V_109 -> V_49 ) > 4096 ) {
F_52 ( V_131 L_4
L_5 ) ;
return - V_85 ;
}
if ( V_113 )
for ( V_110 = F_27 ( V_109 -> V_49 ) ;
V_110 <= V_111 ; V_110 ++ ) {
V_42 -> V_16 . V_17 = F_28 ( V_110 ) ;
F_39 ( & V_112 , V_34 ) ;
}
}
F_53 ( V_34 , V_105 ) ;
return 0 ;
case V_132 :
if ( ! V_8 )
return - V_133 ;
V_42 -> V_86 = V_87 ;
V_42 -> V_16 = V_8 -> V_25 ;
break;
case V_134 :
if ( ! V_8 )
return - V_133 ;
V_42 -> V_86 = V_87 ;
V_42 -> V_16 . V_17 = V_8 -> V_25 . V_17 ;
V_42 -> V_16 . V_19 = V_20 ;
break;
case V_135 :
case V_136 :
if ( ! F_51 ( V_119 ) )
return - V_120 ;
if ( V_42 -> V_86 != V_87 )
return - V_85 ;
F_42 ( V_34 ) ;
break;
case V_137 :
if ( ! F_51 ( V_119 ) )
return - V_120 ;
if ( V_42 -> V_86 != V_87 )
return - V_85 ;
if ( V_34 -> type != V_121 )
return - V_125 ;
if ( ! V_8 )
return - V_133 ;
V_109 = (struct V_108 * ) & ( V_8 -> V_47 ) ;
if ( V_34 -> type == V_121 && V_109 -> V_128 != 2 )
return - V_125 ;
if ( V_42 -> V_16 . V_19 == V_20 ||
V_42 -> V_16 . V_19 == 254 )
return - V_85 ;
if ( F_30 ( V_8 , & ( V_42 -> V_16 ) ) < 0 )
return - V_56 ;
break;
case V_138 :
if ( ! F_51 ( V_119 ) )
return - V_120 ;
if ( V_42 -> V_86 != V_87 )
return - V_85 ;
if ( ! V_8 )
return - V_133 ;
F_54 ( V_8 -> V_34 , & ( V_42 -> V_16 ) ) ;
return 0 ;
}
return F_55 ( V_104 , & V_107 , sizeof( V_107 ) ) ? - V_114 : 0 ;
}
static int F_56 ( unsigned int V_103 , void T_2 * V_104 )
{
struct V_77 V_83 ;
if ( F_48 ( & V_83 , V_104 , sizeof( V_83 ) ) )
return - V_114 ;
switch ( V_103 ) {
case V_139 :
if ( V_83 . V_80 . V_140 != V_87 )
return - V_85 ;
return F_40 ( & ( (struct V_5 * )
& V_83 . V_80 ) -> V_16 ) ;
case V_141 : {
struct V_33 * V_34 = NULL ;
if ( V_83 . V_142 ) {
char V_143 [ V_144 ] ;
if ( F_48 ( V_143 , V_83 . V_142 , V_144 - 1 ) )
return - V_114 ;
V_143 [ V_144 - 1 ] = '\0' ;
V_34 = F_49 ( & V_100 , V_143 ) ;
if ( ! V_34 )
return - V_116 ;
}
return F_39 ( & V_83 , V_34 ) ;
}
}
return - V_85 ;
}
static unsigned long F_57 ( const unsigned char * V_27 ,
int V_145 , unsigned long V_146 )
{
while ( V_145 -- ) {
V_146 += * V_27 ++ ;
V_146 = F_58 ( V_146 , 1 ) ;
}
return V_146 ;
}
static unsigned long F_59 ( const struct V_147 * V_148 , int V_149 ,
int V_145 , unsigned long V_146 )
{
int V_150 = F_60 ( V_148 ) ;
struct V_147 * V_151 ;
int V_152 , V_153 ;
if ( ( V_153 = V_150 - V_149 ) > 0 ) {
if ( V_153 > V_145 )
V_153 = V_145 ;
V_146 = F_57 ( V_148 -> V_27 + V_149 , V_153 , V_146 ) ;
if ( ( V_145 -= V_153 ) == 0 )
return V_146 ;
V_149 += V_153 ;
}
for ( V_152 = 0 ; V_152 < F_61 ( V_148 ) -> V_154 ; V_152 ++ ) {
int V_155 ;
F_62 ( V_150 > V_149 + V_145 ) ;
V_155 = V_150 + F_61 ( V_148 ) -> V_156 [ V_152 ] . V_157 ;
if ( ( V_153 = V_155 - V_149 ) > 0 ) {
T_3 * V_158 ;
T_4 * V_159 = & F_61 ( V_148 ) -> V_156 [ V_152 ] ;
if ( V_153 > V_145 )
V_153 = V_145 ;
V_158 = F_63 ( V_159 ) ;
V_146 = F_57 ( V_158 + V_159 -> V_160 +
V_149 - V_150 , V_153 , V_146 ) ;
F_64 ( V_158 ) ;
if ( ! ( V_145 -= V_153 ) )
return V_146 ;
V_149 += V_153 ;
}
V_150 = V_155 ;
}
F_65 (skb, frag_iter) {
int V_155 ;
F_62 ( V_150 > V_149 + V_145 ) ;
V_155 = V_150 + V_151 -> V_145 ;
if ( ( V_153 = V_155 - V_149 ) > 0 ) {
if ( V_153 > V_145 )
V_153 = V_145 ;
V_146 = F_59 ( V_151 , V_149 - V_150 ,
V_153 , V_146 ) ;
if ( ( V_145 -= V_153 ) == 0 )
return V_146 ;
V_149 += V_153 ;
}
V_150 = V_155 ;
}
F_66 ( V_145 > 0 ) ;
return V_146 ;
}
static T_1 F_67 ( const struct V_147 * V_148 , int V_145 )
{
unsigned long V_146 ;
V_146 = F_59 ( V_148 , 4 , V_145 - 4 , 0 ) ;
return V_146 ? F_28 ( ( unsigned short ) V_146 ) : F_28 ( 0xFFFF ) ;
}
static int F_68 ( struct V_65 * V_65 , struct V_161 * V_1 , int V_162 ,
int V_163 )
{
struct V_1 * V_2 ;
int V_164 = - V_165 ;
if ( ! F_45 ( V_65 , & V_100 ) )
return - V_166 ;
if ( V_1 -> type != V_167 && V_1 -> type != V_168 )
goto V_44;
V_164 = - V_130 ;
V_2 = F_69 ( V_65 , V_169 , V_43 , & V_170 ) ;
if ( ! V_2 )
goto V_44;
V_164 = 0 ;
V_1 -> V_171 = & V_172 ;
F_70 ( V_1 , V_2 ) ;
F_71 ( V_2 , V_173 ) ;
V_44:
return V_164 ;
}
static int F_72 ( struct V_161 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 ) {
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
V_1 -> V_2 = NULL ;
F_17 ( V_2 ) ;
F_76 ( V_2 ) ;
F_16 ( V_2 ) ;
}
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_5 * V_26 )
{
int V_60 ;
F_4 ( & V_4 ) ;
for ( V_26 -> V_14 = V_174 ;
V_26 -> V_14 < V_175 ;
V_26 -> V_14 ++ ) {
struct V_1 * V_9 ;
struct V_10 * V_11 ;
F_9 (s, node, &atalk_sockets) {
struct V_12 * V_13 = F_10 ( V_9 ) ;
if ( V_13 -> V_22 == V_26 -> V_16 . V_17 &&
V_13 -> V_23 == V_26 -> V_16 . V_19 &&
V_13 -> V_15 == V_26 -> V_14 )
goto V_176;
}
F_1 ( V_2 ) ;
F_10 ( V_2 ) -> V_15 = V_26 -> V_14 ;
V_60 = 0 ;
goto V_44;
V_176: ;
}
V_60 = - V_129 ;
V_44:
F_6 ( & V_4 ) ;
return V_60 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_10 ( V_2 ) ;
struct V_5 V_26 ;
struct V_41 * V_177 = F_33 () ;
int V_178 = - V_133 ;
if ( ! V_177 || V_177 -> V_17 == F_28 ( V_18 ) )
goto V_44;
V_13 -> V_22 = V_26 . V_16 . V_17 = V_177 -> V_17 ;
V_13 -> V_23 = V_26 . V_16 . V_19 = V_177 -> V_19 ;
V_178 = F_77 ( V_2 , & V_26 ) ;
if ( ! V_178 )
F_79 ( V_2 , V_173 ) ;
V_44:
return V_178 ;
}
static int F_80 ( struct V_161 * V_1 , struct V_179 * V_180 , int V_181 )
{
struct V_5 * V_93 = (struct V_5 * ) V_180 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_10 ( V_2 ) ;
int V_182 ;
if ( ! F_81 ( V_2 , V_173 ) ||
V_181 != sizeof( struct V_5 ) )
return - V_85 ;
if ( V_93 -> V_86 != V_87 )
return - V_166 ;
F_74 ( V_2 ) ;
if ( V_93 -> V_16 . V_17 == F_28 ( V_18 ) ) {
struct V_41 * V_177 = F_33 () ;
V_182 = - V_133 ;
if ( ! V_177 )
goto V_44;
V_13 -> V_22 = V_93 -> V_16 . V_17 = V_177 -> V_17 ;
V_13 -> V_23 = V_93 -> V_16 . V_19 = V_177 -> V_19 ;
} else {
V_182 = - V_133 ;
if ( ! F_35 ( V_93 -> V_16 . V_17 ,
V_93 -> V_16 . V_19 ) )
goto V_44;
V_13 -> V_22 = V_93 -> V_16 . V_17 ;
V_13 -> V_23 = V_93 -> V_16 . V_19 ;
}
if ( V_93 -> V_14 == V_183 ) {
V_182 = F_77 ( V_2 , V_93 ) ;
if ( V_182 < 0 )
goto V_44;
} else {
V_13 -> V_15 = V_93 -> V_14 ;
V_182 = - V_56 ;
if ( F_12 ( V_2 , V_93 ) )
goto V_44;
}
F_79 ( V_2 , V_173 ) ;
V_182 = 0 ;
V_44:
F_76 ( V_2 ) ;
return V_182 ;
}
static int F_82 ( struct V_161 * V_1 , struct V_179 * V_180 ,
int V_181 , int V_61 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_10 ( V_2 ) ;
struct V_5 * V_93 ;
int V_182 ;
V_2 -> V_184 = V_185 ;
V_1 -> V_186 = V_187 ;
if ( V_181 != sizeof( * V_93 ) )
return - V_85 ;
V_93 = (struct V_5 * ) V_180 ;
if ( V_93 -> V_86 != V_87 )
return - V_166 ;
if ( V_93 -> V_16 . V_19 == V_20 &&
! F_81 ( V_2 , V_188 ) ) {
#if 1
F_52 ( V_131 L_6
L_7
L_8 ,
V_189 -> V_190 ) ;
#else
return - V_191 ;
#endif
}
F_74 ( V_2 ) ;
V_182 = - V_129 ;
if ( F_81 ( V_2 , V_173 ) )
if ( F_78 ( V_2 ) < 0 )
goto V_44;
V_182 = - V_89 ;
if ( ! F_37 ( & V_93 -> V_16 ) )
goto V_44;
V_13 -> V_192 = V_93 -> V_14 ;
V_13 -> V_193 = V_93 -> V_16 . V_17 ;
V_13 -> V_194 = V_93 -> V_16 . V_19 ;
V_1 -> V_186 = V_195 ;
V_2 -> V_184 = V_196 ;
V_182 = 0 ;
V_44:
F_76 ( V_2 ) ;
return V_182 ;
}
static int F_83 ( struct V_161 * V_1 , struct V_179 * V_180 ,
int * V_197 , int V_198 )
{
struct V_5 V_26 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_10 ( V_2 ) ;
int V_182 ;
F_74 ( V_2 ) ;
V_182 = - V_92 ;
if ( F_81 ( V_2 , V_173 ) )
if ( F_78 ( V_2 ) < 0 )
goto V_44;
* V_197 = sizeof( struct V_5 ) ;
memset ( & V_26 . V_126 , 0 , sizeof( V_26 . V_126 ) ) ;
if ( V_198 ) {
V_182 = - V_199 ;
if ( V_2 -> V_184 != V_196 )
goto V_44;
V_26 . V_16 . V_17 = V_13 -> V_193 ;
V_26 . V_16 . V_19 = V_13 -> V_194 ;
V_26 . V_14 = V_13 -> V_192 ;
} else {
V_26 . V_16 . V_17 = V_13 -> V_22 ;
V_26 . V_16 . V_19 = V_13 -> V_23 ;
V_26 . V_14 = V_13 -> V_15 ;
}
V_182 = 0 ;
V_26 . V_86 = V_87 ;
memcpy ( V_180 , & V_26 , sizeof( V_26 ) ) ;
V_44:
F_76 ( V_2 ) ;
return V_182 ;
}
static T_5 int F_84 ( struct V_147 * V_148 )
{
return V_148 -> V_27 [ 12 ] == 22 ;
}
static int F_85 ( struct V_147 * V_148 )
{
struct V_33 * V_34 = F_49 ( & V_100 , L_9 ) ;
struct V_200 * V_201 ;
if ( ! V_34 ) {
F_86 ( V_148 ) ;
return V_202 ;
}
V_148 -> V_162 = F_28 ( V_203 ) ;
F_87 ( V_148 , 13 ) ;
V_148 -> V_34 = V_34 ;
F_88 ( V_148 ) ;
V_201 = F_89 ( V_34 ) ;
V_201 -> V_204 ++ ;
V_201 -> V_205 += V_148 -> V_145 + 13 ;
return F_90 ( V_148 ) ;
}
static int F_91 ( struct V_147 * V_148 , struct V_33 * V_34 ,
struct V_206 * V_207 , T_6 V_208 , int V_209 )
{
struct V_66 * V_83 ;
struct V_41 V_79 ;
if ( V_148 -> V_210 != V_211 || ! V_207 -> V_212 ) {
if ( V_34 -> type == V_124 )
F_52 ( V_127 L_10
L_11 ) ;
goto V_213;
}
V_79 . V_17 = V_207 -> V_212 ;
V_79 . V_19 = V_207 -> V_214 ;
V_83 = F_36 ( & V_79 ) ;
V_208 += 1 << 10 ;
if ( ! V_83 || ! ( V_208 & ( 15 << 10 ) ) )
goto V_213;
if ( V_83 -> V_61 & V_94 ) {
V_79 . V_17 = V_83 -> V_76 . V_17 ;
V_79 . V_19 = V_83 -> V_76 . V_19 ;
}
F_92 ( V_148 , F_93 (unsigned int, origlen,
(rt->dev->hard_header_len +
ddp_dl->header_length + (len_hops & 1023))) ) ;
V_207 -> V_215 = F_28 ( V_208 ) ;
if ( F_94 ( V_148 ) < 22 ) {
struct V_147 * V_216 = F_95 ( V_148 , 32 ) ;
F_86 ( V_148 ) ;
V_148 = V_216 ;
} else
V_148 = F_96 ( V_148 , V_91 ) ;
if ( V_148 == NULL )
goto V_217;
if ( F_97 ( V_83 -> V_34 , V_148 , & V_79 , NULL ) == V_218 )
return V_202 ;
return V_219 ;
V_213:
F_86 ( V_148 ) ;
V_217:
return V_202 ;
}
static int F_98 ( struct V_147 * V_148 , struct V_33 * V_34 ,
struct V_220 * V_221 , struct V_33 * V_222 )
{
struct V_206 * V_207 ;
struct V_1 * V_1 ;
struct V_7 * V_8 ;
struct V_5 V_223 ;
int V_209 ;
T_6 V_208 ;
if ( ! F_45 ( F_46 ( V_34 ) , & V_100 ) )
goto V_217;
if ( ! ( V_148 = F_99 ( V_148 , V_91 ) ) )
goto V_44;
if ( ! F_100 ( V_148 , sizeof( * V_207 ) ) )
goto V_217;
V_207 = F_101 ( V_148 ) ;
V_208 = F_27 ( V_207 -> V_215 ) ;
V_209 = V_148 -> V_145 ;
F_92 ( V_148 , F_93 (unsigned int, skb->len, len_hops & 1023 ) ) ;
if ( V_148 -> V_145 < sizeof( * V_207 ) || V_148 -> V_145 < ( V_208 & 1023 ) ) {
F_102 ( L_12
L_13 , V_208 & 1023 , V_148 -> V_145 ) ;
goto V_217;
}
if ( V_207 -> V_224 &&
F_67 ( V_148 , V_208 & 1023 ) != V_207 -> V_224 )
goto V_217;
if ( ! V_207 -> V_212 )
V_8 = F_34 ( V_207 -> V_214 , V_34 ) ;
else
V_8 = F_35 ( V_207 -> V_212 , V_207 -> V_214 ) ;
if ( ! V_8 ) {
return F_91 ( V_148 , V_34 , V_207 , V_208 , V_209 ) ;
}
if ( F_84 ( V_148 ) )
return F_85 ( V_148 ) ;
V_223 . V_16 . V_17 = V_207 -> V_212 ;
V_223 . V_16 . V_19 = V_207 -> V_214 ;
V_223 . V_14 = V_207 -> V_225 ;
V_1 = F_7 ( & V_223 , V_8 ) ;
if ( ! V_1 )
goto V_217;
V_148 -> V_2 = V_1 ;
if ( F_103 ( V_1 , V_148 ) < 0 )
goto V_217;
return V_219 ;
V_217:
F_86 ( V_148 ) ;
V_44:
return V_202 ;
}
static int F_104 ( struct V_147 * V_148 , struct V_33 * V_34 ,
struct V_220 * V_221 , struct V_33 * V_222 )
{
if ( ! F_45 ( F_46 ( V_34 ) , & V_100 ) )
goto V_226;
if ( F_105 ( V_148 ) [ 2 ] == 1 ) {
struct V_206 * V_207 ;
struct V_41 * V_177 = F_32 ( V_34 ) ;
if ( ! V_177 || V_148 -> V_145 < sizeof( T_1 ) || V_148 -> V_145 > 1023 )
goto V_226;
if ( ! ( V_148 = F_99 ( V_148 , V_91 ) ) )
return 0 ;
V_207 = (struct V_206 * ) F_106 ( V_148 , sizeof( * V_207 ) - 4 ) ;
V_207 -> V_214 = F_105 ( V_148 ) [ 0 ] ;
V_207 -> V_227 = F_105 ( V_148 ) [ 1 ] ;
V_207 -> V_212 = V_177 -> V_17 ;
V_207 -> V_228 = V_177 -> V_17 ;
V_207 -> V_224 = 0 ;
V_207 -> V_215 = F_28 ( V_148 -> V_145 + ( V_229 << 10 ) ) ;
}
F_88 ( V_148 ) ;
return F_98 ( V_148 , V_34 , V_221 , V_222 ) ;
V_226:
F_86 ( V_148 ) ;
return 0 ;
}
static int F_107 ( struct V_230 * V_231 , struct V_161 * V_1 , struct V_232 * V_233 ,
T_7 V_145 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_10 ( V_2 ) ;
struct V_5 * V_234 = (struct V_5 * ) V_233 -> V_235 ;
int V_61 = V_233 -> V_236 ;
int V_237 = 0 ;
struct V_5 V_238 , V_239 ;
struct V_147 * V_148 ;
struct V_33 * V_34 ;
struct V_206 * V_207 ;
int V_157 ;
struct V_66 * V_83 ;
int V_182 ;
if ( V_61 & ~ ( V_240 | V_241 ) )
return - V_85 ;
if ( V_145 > V_242 )
return - V_243 ;
F_74 ( V_2 ) ;
if ( V_234 ) {
V_182 = - V_129 ;
if ( F_81 ( V_2 , V_173 ) )
if ( F_78 ( V_2 ) < 0 )
goto V_44;
V_182 = - V_85 ;
if ( V_233 -> V_244 < sizeof( * V_234 ) ||
V_234 -> V_86 != V_87 )
goto V_44;
V_182 = - V_120 ;
if ( V_234 -> V_16 . V_19 == V_20 &&
! F_81 ( V_2 , V_188 ) ) {
goto V_44;
}
} else {
V_182 = - V_199 ;
if ( V_2 -> V_184 != V_196 )
goto V_44;
V_234 = & V_238 ;
V_234 -> V_86 = V_87 ;
V_234 -> V_14 = V_13 -> V_192 ;
V_234 -> V_16 . V_19 = V_13 -> V_194 ;
V_234 -> V_16 . V_17 = V_13 -> V_193 ;
}
F_108 ( V_2 , L_14 , V_2 ) ;
V_157 = sizeof( struct V_206 ) + V_145 + V_245 -> V_246 ;
if ( V_234 -> V_16 . V_17 || V_234 -> V_16 . V_19 == V_24 ) {
V_83 = F_36 ( & V_234 -> V_16 ) ;
} else {
struct V_41 V_247 ;
V_247 . V_19 = 0 ;
V_247 . V_17 = V_13 -> V_22 ;
V_83 = F_36 ( & V_247 ) ;
}
V_182 = V_89 ;
if ( ! V_83 )
goto V_44;
V_34 = V_83 -> V_34 ;
F_108 ( V_2 , L_15 ,
V_2 , V_157 , V_34 -> V_143 ) ;
V_157 += V_34 -> V_248 ;
F_76 ( V_2 ) ;
V_148 = F_109 ( V_2 , V_157 , ( V_61 & V_240 ) , & V_182 ) ;
F_74 ( V_2 ) ;
if ( ! V_148 )
goto V_44;
V_148 -> V_2 = V_2 ;
F_110 ( V_148 , V_245 -> V_246 ) ;
F_110 ( V_148 , V_34 -> V_248 ) ;
V_148 -> V_34 = V_34 ;
F_108 ( V_2 , L_16 , V_2 ) ;
V_207 = (struct V_206 * ) F_111 ( V_148 , sizeof( struct V_206 ) ) ;
V_207 -> V_215 = F_28 ( V_145 + sizeof( * V_207 ) ) ;
V_207 -> V_212 = V_234 -> V_16 . V_17 ;
V_207 -> V_228 = V_13 -> V_22 ;
V_207 -> V_214 = V_234 -> V_16 . V_19 ;
V_207 -> V_227 = V_13 -> V_23 ;
V_207 -> V_225 = V_234 -> V_14 ;
V_207 -> V_249 = V_13 -> V_15 ;
F_108 ( V_2 , L_17 , V_2 , V_145 ) ;
V_182 = F_112 ( F_111 ( V_148 , V_145 ) , V_233 -> V_250 , V_145 ) ;
if ( V_182 ) {
F_86 ( V_148 ) ;
V_182 = - V_114 ;
goto V_44;
}
if ( V_2 -> V_251 == 1 )
V_207 -> V_224 = 0 ;
else
V_207 -> V_224 = F_67 ( V_148 , V_145 + sizeof( * V_207 ) ) ;
if ( V_207 -> V_214 == V_20 &&
! ( V_83 -> V_61 & V_94 ) && ! ( V_34 -> V_61 & V_62 ) ) {
struct V_147 * V_252 = F_113 ( V_148 , V_43 ) ;
if ( V_252 ) {
V_237 = 1 ;
F_108 ( V_2 , L_18 , V_2 ) ;
F_97 ( V_34 , V_252 , & V_234 -> V_16 , NULL ) ;
}
}
if ( V_34 -> V_61 & V_62 || V_237 ) {
F_108 ( V_2 , L_19 , V_2 ) ;
F_114 ( V_148 ) ;
if ( V_207 -> V_214 == V_20 ) {
struct V_41 V_253 ;
V_253 . V_19 = 0 ;
V_253 . V_17 = 0 ;
V_83 = F_36 ( & V_253 ) ;
if ( ! V_83 ) {
F_86 ( V_148 ) ;
V_182 = - V_89 ;
goto V_44;
}
V_34 = V_83 -> V_34 ;
V_148 -> V_34 = V_34 ;
}
V_245 -> V_254 ( V_245 , V_148 , V_34 -> V_255 ) ;
} else {
F_108 ( V_2 , L_20 , V_2 ) ;
if ( V_83 -> V_61 & V_94 ) {
V_239 . V_16 = V_83 -> V_76 ;
V_234 = & V_239 ;
}
F_97 ( V_34 , V_148 , & V_234 -> V_16 , NULL ) ;
}
F_108 ( V_2 , L_21 , V_2 , V_145 ) ;
V_44:
F_76 ( V_2 ) ;
return V_182 ? : V_145 ;
}
static int F_115 ( struct V_230 * V_231 , struct V_161 * V_1 , struct V_232 * V_233 ,
T_7 V_157 , int V_61 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_5 * V_26 = (struct V_5 * ) V_233 -> V_235 ;
struct V_206 * V_207 ;
int V_256 = 0 ;
int V_149 = 0 ;
int V_182 = 0 ;
struct V_147 * V_148 ;
V_148 = F_116 ( V_2 , V_61 & ~ V_240 ,
V_61 & V_240 , & V_182 ) ;
F_74 ( V_2 ) ;
if ( ! V_148 )
goto V_44;
V_207 = F_101 ( V_148 ) ;
V_256 = F_27 ( V_207 -> V_215 ) & 1023 ;
if ( V_2 -> V_257 != V_167 ) {
V_149 = sizeof( * V_207 ) ;
V_256 -= V_149 ;
}
if ( V_256 > V_157 ) {
V_256 = V_157 ;
V_233 -> V_236 |= V_258 ;
}
V_182 = F_117 ( V_148 , V_149 , V_233 -> V_250 , V_256 ) ;
if ( ! V_182 ) {
if ( V_26 ) {
V_26 -> V_86 = V_87 ;
V_26 -> V_14 = V_207 -> V_249 ;
V_26 -> V_16 . V_19 = V_207 -> V_227 ;
V_26 -> V_16 . V_17 = V_207 -> V_228 ;
}
V_233 -> V_244 = sizeof( * V_26 ) ;
}
F_118 ( V_2 , V_148 ) ;
V_44:
F_76 ( V_2 ) ;
return V_182 ? : V_256 ;
}
static int F_119 ( struct V_161 * V_1 , unsigned int V_103 , unsigned long V_104 )
{
int V_164 = - V_259 ;
struct V_1 * V_2 = V_1 -> V_2 ;
void T_2 * V_260 = ( void T_2 * ) V_104 ;
switch ( V_103 ) {
case V_261 : {
long V_262 = V_2 -> V_263 - F_120 ( V_2 ) ;
if ( V_262 < 0 )
V_262 = 0 ;
V_164 = F_121 ( V_262 , ( int T_2 * ) V_260 ) ;
break;
}
case V_264 : {
struct V_147 * V_148 = F_122 ( & V_2 -> V_32 ) ;
long V_262 = 0 ;
if ( V_148 )
V_262 = V_148 -> V_145 - sizeof( struct V_206 ) ;
V_164 = F_121 ( V_262 , ( int T_2 * ) V_260 ) ;
break;
}
case V_265 :
V_164 = F_123 ( V_2 , V_260 ) ;
break;
case V_266 :
V_164 = F_124 ( V_2 , V_260 ) ;
break;
case V_141 :
case V_139 :
V_164 = - V_120 ;
if ( F_51 ( V_119 ) )
V_164 = F_56 ( V_103 , V_260 ) ;
break;
case V_132 :
case V_118 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
F_125 () ;
V_164 = F_47 ( V_103 , V_260 ) ;
F_126 () ;
break;
}
return V_164 ;
}
static int F_127 ( struct V_161 * V_1 , unsigned int V_103 , unsigned long V_104 )
{
if ( V_103 == V_135 )
return F_119 ( V_1 , V_103 , ( unsigned long ) F_128 ( V_104 ) ) ;
return - V_259 ;
}
static int T_8 F_129 ( void )
{
int V_164 = F_130 ( & V_170 , 0 ) ;
if ( V_164 != 0 )
goto V_44;
( void ) F_131 ( & V_267 ) ;
V_245 = F_132 ( V_268 , F_98 ) ;
if ( ! V_245 )
F_52 ( V_269 ) ;
F_133 ( & V_270 ) ;
F_133 ( & V_271 ) ;
F_134 ( & V_272 ) ;
F_135 () ;
F_136 () ;
F_137 () ;
V_44:
return V_164 ;
}
static void T_9 F_138 ( void )
{
#ifdef F_139
F_140 () ;
#endif
F_141 () ;
F_142 () ;
F_143 ( & V_272 ) ;
F_144 ( & V_270 ) ;
F_144 ( & V_271 ) ;
F_145 ( V_245 ) ;
F_146 ( V_169 ) ;
F_147 ( & V_170 ) ;
}
