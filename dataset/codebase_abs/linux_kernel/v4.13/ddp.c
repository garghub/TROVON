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
F_8 ( & V_4 ) ;
F_9 (s, &atalk_sockets) {
struct V_10 * V_11 = F_10 ( V_9 ) ;
if ( V_6 -> V_12 != V_11 -> V_13 )
continue;
if ( V_6 -> V_14 . V_15 == V_16 &&
V_6 -> V_14 . V_17 == V_18 )
goto V_19;
if ( V_6 -> V_14 . V_15 == V_11 -> V_20 &&
( V_6 -> V_14 . V_17 == V_11 -> V_21 ||
V_6 -> V_14 . V_17 == V_18 ||
V_6 -> V_14 . V_17 == V_22 ) )
goto V_19;
if ( V_6 -> V_14 . V_17 == V_22 &&
V_6 -> V_14 . V_15 != V_16 &&
V_8 -> V_23 . V_17 == V_11 -> V_21 ) {
V_6 -> V_14 . V_17 = V_8 -> V_23 . V_17 ;
goto V_19;
}
}
V_9 = NULL ;
V_19:
F_11 ( & V_4 ) ;
return V_9 ;
}
static struct V_1 * F_12 ( struct V_1 * V_2 ,
struct V_5 * V_24 )
{
struct V_1 * V_9 ;
struct V_10 * V_11 ;
F_4 ( & V_4 ) ;
F_9 (s, &atalk_sockets) {
V_11 = F_10 ( V_9 ) ;
if ( V_11 -> V_20 == V_24 -> V_14 . V_15 &&
V_11 -> V_21 == V_24 -> V_14 . V_17 &&
V_11 -> V_13 == V_24 -> V_12 )
goto V_19;
}
V_9 = NULL ;
F_1 ( V_2 ) ;
V_19:
F_6 ( & V_4 ) ;
return V_9 ;
}
static void F_13 ( unsigned long V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
if ( F_14 ( V_2 ) ) {
V_2 -> V_26 . V_27 = V_28 + V_29 ;
F_15 ( & V_2 -> V_26 ) ;
} else
F_16 ( V_2 ) ;
}
static inline void F_17 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
F_18 ( & V_2 -> V_30 ) ;
if ( F_14 ( V_2 ) ) {
F_19 ( & V_2 -> V_26 , F_13 ,
( unsigned long ) V_2 ) ;
V_2 -> V_26 . V_27 = V_28 + V_29 ;
F_15 ( & V_2 -> V_26 ) ;
} else
F_16 ( V_2 ) ;
}
static void F_20 ( struct V_31 * V_32 )
{
struct V_7 * * V_33 = & V_34 ;
struct V_7 * V_35 ;
F_4 ( & V_36 ) ;
while ( ( V_35 = * V_33 ) != NULL ) {
if ( V_35 -> V_32 == V_32 ) {
* V_33 = V_35 -> V_37 ;
F_21 ( V_32 ) ;
F_22 ( V_35 ) ;
V_32 -> V_38 = NULL ;
} else
V_33 = & V_35 -> V_37 ;
}
F_6 ( & V_36 ) ;
}
static struct V_7 * F_23 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_7 * V_33 = F_24 ( sizeof( * V_33 ) , V_41 ) ;
if ( ! V_33 )
goto V_42;
F_25 ( V_32 ) ;
V_33 -> V_32 = V_32 ;
V_32 -> V_38 = V_33 ;
V_33 -> V_23 = * V_40 ;
V_33 -> V_43 = 0 ;
F_4 ( & V_36 ) ;
V_33 -> V_37 = V_34 ;
V_34 = V_33 ;
F_6 ( & V_36 ) ;
V_42:
return V_33 ;
}
static int F_26 ( struct V_7 * V_8 )
{
int V_44 = F_27 ( V_8 -> V_45 . V_46 ) -
F_27 ( V_8 -> V_45 . V_47 ) + 1 ;
int V_48 = F_27 ( V_8 -> V_23 . V_15 ) ;
int V_49 = V_8 -> V_23 . V_17 ;
int V_50 , V_51 ;
if ( V_48 == V_16 ) {
V_48 = F_27 ( V_8 -> V_45 . V_47 ) ;
if ( V_44 )
V_48 += V_28 % V_44 ;
}
if ( V_49 == V_22 )
V_49 = V_28 & 0xFF ;
V_8 -> V_43 |= V_52 ;
for ( V_50 = 0 ; V_50 <= V_44 ; V_50 ++ ) {
V_8 -> V_23 . V_15 = F_28 ( V_48 ) ;
for ( V_51 = 0 ; V_51 < 256 ; V_51 ++ ) {
V_8 -> V_23 . V_17 = ( V_51 + V_49 ) & 0xFF ;
if ( V_8 -> V_23 . V_17 > 0 &&
V_8 -> V_23 . V_17 < 254 ) {
F_29 ( V_8 ) ;
if ( ! ( V_8 -> V_43 & V_53 ) ) {
V_8 -> V_43 &= ~ V_52 ;
return 0 ;
}
}
V_8 -> V_43 &= ~ V_53 ;
}
V_48 ++ ;
if ( V_48 > F_27 ( V_8 -> V_45 . V_46 ) )
V_48 = F_27 ( V_8 -> V_45 . V_47 ) ;
}
V_8 -> V_43 &= ~ V_52 ;
return - V_54 ;
}
static int F_30 ( struct V_7 * V_8 ,
struct V_39 * V_55 )
{
int V_44 = F_27 ( V_8 -> V_45 . V_46 ) -
F_27 ( V_8 -> V_45 . V_47 ) + 1 ;
int V_48 = F_27 ( V_8 -> V_23 . V_15 ) ;
int V_49 = V_22 ;
int V_50 , V_51 ;
if ( V_48 == V_16 ) {
V_48 = F_27 ( V_8 -> V_45 . V_47 ) ;
if ( V_44 )
V_48 += V_28 % V_44 ;
}
if ( V_49 == V_22 )
V_49 = V_28 & 0xFF ;
for ( V_50 = 0 ; V_50 <= V_44 ; V_50 ++ ) {
V_55 -> V_15 = F_28 ( V_48 ) ;
for ( V_51 = 0 ; V_51 < 256 ; V_51 ++ ) {
V_55 -> V_17 = ( V_51 + V_49 ) & 0xFF ;
if ( V_55 -> V_17 > 0 &&
V_55 -> V_17 < 254 ) {
int V_56 = F_31 ( V_8 ,
V_55 ) ;
if ( V_56 != - V_54 )
return V_56 ;
}
}
V_48 ++ ;
if ( V_48 > F_27 ( V_8 -> V_45 . V_46 ) )
V_48 = F_27 ( V_8 -> V_45 . V_47 ) ;
}
return - V_54 ;
}
struct V_39 * F_32 ( struct V_31 * V_32 )
{
struct V_7 * V_33 = V_32 -> V_38 ;
return V_33 ? & V_33 -> V_23 : NULL ;
}
static struct V_39 * F_33 ( void )
{
struct V_7 * V_57 = NULL ;
struct V_39 * V_58 ;
struct V_7 * V_33 ;
F_8 ( & V_36 ) ;
for ( V_33 = V_34 ; V_33 ; V_33 = V_33 -> V_37 ) {
if ( ! V_57 && ! ( V_33 -> V_32 -> V_59 & V_60 ) )
V_57 = V_33 ;
if ( ! ( V_33 -> V_32 -> V_59 & ( V_60 | V_61 ) ) ) {
V_58 = & V_33 -> V_23 ;
goto V_42;
}
}
if ( V_57 )
V_58 = & V_57 -> V_23 ;
else if ( V_34 )
V_58 = & V_34 -> V_23 ;
else
V_58 = NULL ;
V_42:
F_11 ( & V_36 ) ;
return V_58 ;
}
static struct V_7 * F_34 ( int V_62 , struct V_31 * V_32 )
{
struct V_7 * V_33 = V_32 -> V_38 ;
if ( ! V_33 || V_33 -> V_43 & V_52 )
goto V_63;
if ( V_62 != V_18 &&
V_33 -> V_23 . V_17 != V_62 &&
V_62 != V_22 )
goto V_63;
V_42:
return V_33 ;
V_63:
V_33 = NULL ;
goto V_42;
}
static struct V_7 * F_35 ( T_1 V_64 , int V_62 )
{
struct V_7 * V_33 ;
F_8 ( & V_36 ) ;
for ( V_33 = V_34 ; V_33 ; V_33 = V_33 -> V_37 ) {
if ( ( V_62 == V_18 ||
V_62 == V_22 ||
V_33 -> V_23 . V_17 == V_62 ) &&
V_33 -> V_23 . V_15 == V_64 &&
! ( V_33 -> V_43 & V_52 ) )
break;
if ( V_62 == V_22 && V_64 != V_16 &&
F_27 ( V_33 -> V_45 . V_47 ) <= F_27 ( V_64 ) &&
F_27 ( V_64 ) <= F_27 ( V_33 -> V_45 . V_46 ) )
break;
}
F_11 ( & V_36 ) ;
return V_33 ;
}
static struct V_65 * F_36 ( struct V_39 * V_66 )
{
struct V_65 * V_67 = NULL ;
struct V_65 * V_68 ;
F_8 ( & V_69 ) ;
for ( V_68 = V_70 ; V_68 ; V_68 = V_68 -> V_37 ) {
if ( ! ( V_68 -> V_59 & V_71 ) )
continue;
if ( V_68 -> V_66 . V_15 == V_66 -> V_15 ) {
if ( V_68 -> V_59 & V_72 ) {
if ( V_68 -> V_66 . V_17 == V_66 -> V_17 )
goto V_42;
} else
V_67 = V_68 ;
}
}
if ( V_67 )
V_68 = V_67 ;
else if ( V_73 . V_32 )
V_68 = & V_73 ;
else
V_68 = NULL ;
V_42:
F_11 ( & V_69 ) ;
return V_68 ;
}
struct V_31 * F_37 ( struct V_39 * V_40 )
{
struct V_65 * V_74 = F_36 ( V_40 ) ;
return V_74 ? V_74 -> V_32 : NULL ;
}
static void F_38 ( struct V_31 * V_32 )
{
V_73 . V_32 = V_32 ;
V_73 . V_59 = V_71 ;
V_73 . V_75 . V_15 = F_28 ( 0 ) ;
V_73 . V_75 . V_17 = 0 ;
}
static int F_39 ( struct V_76 * V_68 , struct V_31 * V_77 )
{
struct V_5 * V_78 = (struct V_5 * ) & V_68 -> V_79 ;
struct V_5 * V_80 = (struct V_5 * ) & V_68 -> V_81 ;
struct V_65 * V_82 ;
struct V_7 * V_33 , * V_83 ;
int V_58 = - V_84 ;
if ( V_78 -> V_85 != V_86 ||
( ! V_77 && V_80 -> V_85 != V_86 ) )
goto V_42;
F_4 ( & V_69 ) ;
for ( V_82 = V_70 ; V_82 ; V_82 = V_82 -> V_37 ) {
if ( V_68 -> V_87 != V_82 -> V_59 )
continue;
if ( V_78 -> V_14 . V_15 == V_82 -> V_66 . V_15 ) {
if ( ! ( V_82 -> V_59 & V_72 ) )
break;
if ( V_78 -> V_14 . V_17 == V_82 -> V_66 . V_17 )
break;
}
}
if ( ! V_77 ) {
V_83 = NULL ;
F_8 ( & V_36 ) ;
for ( V_33 = V_34 ; V_33 ; V_33 = V_33 -> V_37 ) {
if ( ! V_83 &&
F_27 ( V_80 -> V_14 . V_15 ) >=
F_27 ( V_33 -> V_45 . V_47 ) &&
F_27 ( V_80 -> V_14 . V_15 ) <=
F_27 ( V_33 -> V_45 . V_46 ) )
V_83 = V_33 ;
if ( V_80 -> V_14 . V_15 == V_33 -> V_23 . V_15 &&
V_80 -> V_14 . V_17 == V_33 -> V_23 . V_17 )
V_83 = V_33 ;
}
F_11 ( & V_36 ) ;
V_58 = - V_88 ;
if ( ! V_83 )
goto V_89;
V_77 = V_83 -> V_32 ;
}
if ( ! V_82 ) {
V_82 = F_24 ( sizeof( * V_82 ) , V_90 ) ;
V_58 = - V_91 ;
if ( ! V_82 )
goto V_89;
V_82 -> V_37 = V_70 ;
V_70 = V_82 ;
}
V_82 -> V_66 = V_78 -> V_14 ;
F_25 ( V_77 ) ;
V_82 -> V_32 = V_77 ;
V_82 -> V_59 = V_68 -> V_87 ;
V_82 -> V_75 = V_80 -> V_14 ;
V_58 = 0 ;
V_89:
F_6 ( & V_69 ) ;
V_42:
return V_58 ;
}
static int F_40 ( struct V_39 * V_92 )
{
struct V_65 * * V_68 = & V_70 ;
int V_58 = 0 ;
struct V_65 * V_35 ;
F_4 ( & V_69 ) ;
while ( ( V_35 = * V_68 ) != NULL ) {
if ( V_35 -> V_66 . V_15 == V_92 -> V_15 &&
( ! ( V_35 -> V_59 & V_93 ) ||
V_35 -> V_66 . V_17 == V_92 -> V_17 ) ) {
* V_68 = V_35 -> V_37 ;
F_21 ( V_35 -> V_32 ) ;
F_22 ( V_35 ) ;
goto V_42;
}
V_68 = & V_35 -> V_37 ;
}
V_58 = - V_94 ;
V_42:
F_6 ( & V_69 ) ;
return V_58 ;
}
static void F_41 ( struct V_31 * V_32 )
{
struct V_65 * * V_68 = & V_70 ;
struct V_65 * V_35 ;
F_4 ( & V_69 ) ;
while ( ( V_35 = * V_68 ) != NULL ) {
if ( V_35 -> V_32 == V_32 ) {
* V_68 = V_35 -> V_37 ;
F_21 ( V_32 ) ;
F_22 ( V_35 ) ;
} else
V_68 = & V_35 -> V_37 ;
}
F_6 ( & V_69 ) ;
if ( V_73 . V_32 == V_32 )
F_38 ( NULL ) ;
}
static inline void F_42 ( struct V_31 * V_32 )
{
F_41 ( V_32 ) ;
F_43 ( V_32 ) ;
F_20 ( V_32 ) ;
}
static int F_44 ( struct V_95 * V_96 , unsigned long V_97 ,
void * V_98 )
{
struct V_31 * V_32 = F_45 ( V_98 ) ;
if ( ! F_46 ( F_47 ( V_32 ) , & V_99 ) )
return V_100 ;
if ( V_97 == V_101 )
F_42 ( V_32 ) ;
return V_100 ;
}
static int F_48 ( int V_102 , void T_2 * V_103 )
{
static char V_104 [ 6 ] = { 0x09 , 0x00 , 0x00 , 0xFF , 0xFF , 0xFF } ;
struct V_105 V_106 ;
struct V_107 * V_108 ;
struct V_5 * V_40 ;
struct V_31 * V_32 ;
struct V_7 * V_8 ;
int V_109 ;
int V_110 ;
struct V_76 V_111 ;
int V_112 ;
if ( F_49 ( & V_106 , V_103 , sizeof( V_106 ) ) )
return - V_113 ;
V_32 = F_50 ( & V_99 , V_106 . V_114 ) ;
if ( ! V_32 )
return - V_115 ;
V_40 = (struct V_5 * ) & V_106 . V_116 ;
V_8 = F_51 ( V_32 ) ;
switch ( V_102 ) {
case V_117 :
if ( ! F_52 ( V_118 ) )
return - V_119 ;
if ( V_40 -> V_85 != V_86 )
return - V_84 ;
if ( V_32 -> type != V_120 &&
V_32 -> type != V_121 &&
V_32 -> type != V_122 &&
V_32 -> type != V_123 )
return - V_124 ;
V_108 = (struct V_107 * ) & V_40 -> V_125 [ 0 ] ;
V_112 = 1 ;
if ( ( V_32 -> V_59 & V_61 ) &&
F_35 ( V_40 -> V_14 . V_15 ,
V_40 -> V_14 . V_17 ) ) {
F_53 ( V_126 L_1
L_2
L_3 ) ;
V_112 = 0 ;
}
if ( V_32 -> type == V_120 && V_108 -> V_127 != 2 )
return - V_124 ;
if ( V_40 -> V_14 . V_17 == V_18 ||
V_40 -> V_14 . V_17 == 254 )
return - V_84 ;
if ( V_8 ) {
if ( V_8 -> V_43 & V_52 )
return - V_128 ;
V_8 -> V_23 . V_15 = V_40 -> V_14 . V_15 ;
V_8 -> V_23 . V_17 = V_40 -> V_14 . V_17 ;
F_41 ( V_32 ) ;
} else {
V_8 = F_23 ( V_32 , & V_40 -> V_14 ) ;
if ( ! V_8 )
return - V_129 ;
}
V_8 -> V_45 = * V_108 ;
if ( ! ( V_32 -> V_59 & V_60 ) &&
! ( V_32 -> V_59 & V_61 ) &&
F_26 ( V_8 ) < 0 ) {
F_20 ( V_32 ) ;
return - V_54 ;
}
V_40 = (struct V_5 * ) & V_111 . V_81 ;
V_40 -> V_85 = V_86 ;
V_40 -> V_14 . V_15 = V_8 -> V_23 . V_15 ;
V_40 -> V_14 . V_17 = V_8 -> V_23 . V_17 ;
V_40 = (struct V_5 * ) & V_111 . V_79 ;
V_111 . V_87 = V_71 ;
V_40 -> V_85 = V_86 ;
V_40 -> V_14 . V_17 = V_22 ;
if ( V_32 -> V_59 & V_60 ||
V_32 -> V_59 & V_61 )
V_111 . V_87 |= V_72 ;
if ( V_108 -> V_47 == F_28 ( 0 ) &&
V_108 -> V_46 == F_28 ( 0xFFFE ) ) {
V_40 -> V_14 . V_15 = V_8 -> V_23 . V_15 ;
F_39 ( & V_111 , V_32 ) ;
F_38 ( V_32 ) ;
} else {
V_110 = F_27 ( V_108 -> V_46 ) ;
if ( V_110 - F_27 ( V_108 -> V_47 ) > 4096 ) {
F_53 ( V_130 L_4
L_5 ) ;
return - V_84 ;
}
if ( V_112 )
for ( V_109 = F_27 ( V_108 -> V_47 ) ;
V_109 <= V_110 ; V_109 ++ ) {
V_40 -> V_14 . V_15 = F_28 ( V_109 ) ;
F_39 ( & V_111 , V_32 ) ;
}
}
F_54 ( V_32 , V_104 ) ;
return 0 ;
case V_131 :
if ( ! V_8 )
return - V_132 ;
V_40 -> V_85 = V_86 ;
V_40 -> V_14 = V_8 -> V_23 ;
break;
case V_133 :
if ( ! V_8 )
return - V_132 ;
V_40 -> V_85 = V_86 ;
V_40 -> V_14 . V_15 = V_8 -> V_23 . V_15 ;
V_40 -> V_14 . V_17 = V_18 ;
break;
case V_134 :
case V_135 :
if ( ! F_52 ( V_118 ) )
return - V_119 ;
if ( V_40 -> V_85 != V_86 )
return - V_84 ;
F_42 ( V_32 ) ;
break;
case V_136 :
if ( ! F_52 ( V_118 ) )
return - V_119 ;
if ( V_40 -> V_85 != V_86 )
return - V_84 ;
if ( V_32 -> type != V_120 )
return - V_124 ;
if ( ! V_8 )
return - V_132 ;
V_108 = (struct V_107 * ) & ( V_8 -> V_45 ) ;
if ( V_32 -> type == V_120 && V_108 -> V_127 != 2 )
return - V_124 ;
if ( V_40 -> V_14 . V_17 == V_18 ||
V_40 -> V_14 . V_17 == 254 )
return - V_84 ;
if ( F_30 ( V_8 , & ( V_40 -> V_14 ) ) < 0 )
return - V_54 ;
break;
case V_137 :
if ( ! F_52 ( V_118 ) )
return - V_119 ;
if ( V_40 -> V_85 != V_86 )
return - V_84 ;
if ( ! V_8 )
return - V_132 ;
F_55 ( V_8 -> V_32 , & ( V_40 -> V_14 ) ) ;
return 0 ;
}
return F_56 ( V_103 , & V_106 , sizeof( V_106 ) ) ? - V_113 : 0 ;
}
static int F_57 ( unsigned int V_102 , void T_2 * V_103 )
{
struct V_76 V_82 ;
if ( F_49 ( & V_82 , V_103 , sizeof( V_82 ) ) )
return - V_113 ;
switch ( V_102 ) {
case V_138 :
if ( V_82 . V_79 . V_139 != V_86 )
return - V_84 ;
return F_40 ( & ( (struct V_5 * )
& V_82 . V_79 ) -> V_14 ) ;
case V_140 : {
struct V_31 * V_32 = NULL ;
if ( V_82 . V_141 ) {
char V_142 [ V_143 ] ;
if ( F_49 ( V_142 , V_82 . V_141 , V_143 - 1 ) )
return - V_113 ;
V_142 [ V_143 - 1 ] = '\0' ;
V_32 = F_50 ( & V_99 , V_142 ) ;
if ( ! V_32 )
return - V_115 ;
}
return F_39 ( & V_82 , V_32 ) ;
}
}
return - V_84 ;
}
static unsigned long F_58 ( const unsigned char * V_25 ,
int V_144 , unsigned long V_145 )
{
while ( V_144 -- ) {
V_145 += * V_25 ++ ;
V_145 = F_59 ( V_145 , 1 ) ;
}
return V_145 ;
}
static unsigned long F_60 ( const struct V_146 * V_147 , int V_148 ,
int V_144 , unsigned long V_145 )
{
int V_149 = F_61 ( V_147 ) ;
struct V_146 * V_150 ;
int V_151 , V_152 ;
if ( ( V_152 = V_149 - V_148 ) > 0 ) {
if ( V_152 > V_144 )
V_152 = V_144 ;
V_145 = F_58 ( V_147 -> V_25 + V_148 , V_152 , V_145 ) ;
if ( ( V_144 -= V_152 ) == 0 )
return V_145 ;
V_148 += V_152 ;
}
for ( V_151 = 0 ; V_151 < F_62 ( V_147 ) -> V_153 ; V_151 ++ ) {
int V_154 ;
const T_3 * V_155 = & F_62 ( V_147 ) -> V_156 [ V_151 ] ;
F_63 ( V_149 > V_148 + V_144 ) ;
V_154 = V_149 + F_64 ( V_155 ) ;
if ( ( V_152 = V_154 - V_148 ) > 0 ) {
T_4 * V_157 ;
if ( V_152 > V_144 )
V_152 = V_144 ;
V_157 = F_65 ( F_66 ( V_155 ) ) ;
V_145 = F_58 ( V_157 + V_155 -> V_158 +
V_148 - V_149 , V_152 , V_145 ) ;
F_67 ( V_157 ) ;
if ( ! ( V_144 -= V_152 ) )
return V_145 ;
V_148 += V_152 ;
}
V_149 = V_154 ;
}
F_68 (skb, frag_iter) {
int V_154 ;
F_63 ( V_149 > V_148 + V_144 ) ;
V_154 = V_149 + V_150 -> V_144 ;
if ( ( V_152 = V_154 - V_148 ) > 0 ) {
if ( V_152 > V_144 )
V_152 = V_144 ;
V_145 = F_60 ( V_150 , V_148 - V_149 ,
V_152 , V_145 ) ;
if ( ( V_144 -= V_152 ) == 0 )
return V_145 ;
V_148 += V_152 ;
}
V_149 = V_154 ;
}
F_69 ( V_144 > 0 ) ;
return V_145 ;
}
static T_1 F_70 ( const struct V_146 * V_147 , int V_144 )
{
unsigned long V_145 ;
V_145 = F_60 ( V_147 , 4 , V_144 - 4 , 0 ) ;
return V_145 ? F_28 ( ( unsigned short ) V_145 ) : F_28 ( 0xFFFF ) ;
}
static int F_71 ( struct V_64 * V_64 , struct V_159 * V_1 , int V_160 ,
int V_161 )
{
struct V_1 * V_2 ;
int V_162 = - V_163 ;
if ( ! F_46 ( V_64 , & V_99 ) )
return - V_164 ;
if ( V_1 -> type != V_165 && V_1 -> type != V_166 )
goto V_42;
V_162 = - V_129 ;
V_2 = F_72 ( V_64 , V_167 , V_41 , & V_168 , V_161 ) ;
if ( ! V_2 )
goto V_42;
V_162 = 0 ;
V_1 -> V_169 = & V_170 ;
F_73 ( V_1 , V_2 ) ;
F_74 ( V_2 , V_171 ) ;
V_42:
return V_162 ;
}
static int F_75 ( struct V_159 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 ) {
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
V_1 -> V_2 = NULL ;
F_17 ( V_2 ) ;
F_79 ( V_2 ) ;
F_16 ( V_2 ) ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_5 * V_24 )
{
int V_58 ;
F_4 ( & V_4 ) ;
for ( V_24 -> V_12 = V_172 ;
V_24 -> V_12 < V_173 ;
V_24 -> V_12 ++ ) {
struct V_1 * V_9 ;
F_9 (s, &atalk_sockets) {
struct V_10 * V_11 = F_10 ( V_9 ) ;
if ( V_11 -> V_20 == V_24 -> V_14 . V_15 &&
V_11 -> V_21 == V_24 -> V_14 . V_17 &&
V_11 -> V_13 == V_24 -> V_12 )
goto V_174;
}
F_1 ( V_2 ) ;
F_10 ( V_2 ) -> V_13 = V_24 -> V_12 ;
V_58 = 0 ;
goto V_42;
V_174: ;
}
V_58 = - V_128 ;
V_42:
F_6 ( & V_4 ) ;
return V_58 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_10 ( V_2 ) ;
struct V_5 V_24 ;
struct V_39 * V_175 = F_33 () ;
int V_176 = - V_132 ;
if ( ! V_175 || V_175 -> V_15 == F_28 ( V_16 ) )
goto V_42;
V_11 -> V_20 = V_24 . V_14 . V_15 = V_175 -> V_15 ;
V_11 -> V_21 = V_24 . V_14 . V_17 = V_175 -> V_17 ;
V_176 = F_80 ( V_2 , & V_24 ) ;
if ( ! V_176 )
F_82 ( V_2 , V_171 ) ;
V_42:
return V_176 ;
}
static int F_83 ( struct V_159 * V_1 , struct V_177 * V_178 , int V_179 )
{
struct V_5 * V_92 = (struct V_5 * ) V_178 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_10 * V_11 = F_10 ( V_2 ) ;
int V_180 ;
if ( ! F_84 ( V_2 , V_171 ) ||
V_179 != sizeof( struct V_5 ) )
return - V_84 ;
if ( V_92 -> V_85 != V_86 )
return - V_164 ;
F_77 ( V_2 ) ;
if ( V_92 -> V_14 . V_15 == F_28 ( V_16 ) ) {
struct V_39 * V_175 = F_33 () ;
V_180 = - V_132 ;
if ( ! V_175 )
goto V_42;
V_11 -> V_20 = V_92 -> V_14 . V_15 = V_175 -> V_15 ;
V_11 -> V_21 = V_92 -> V_14 . V_17 = V_175 -> V_17 ;
} else {
V_180 = - V_132 ;
if ( ! F_35 ( V_92 -> V_14 . V_15 ,
V_92 -> V_14 . V_17 ) )
goto V_42;
V_11 -> V_20 = V_92 -> V_14 . V_15 ;
V_11 -> V_21 = V_92 -> V_14 . V_17 ;
}
if ( V_92 -> V_12 == V_181 ) {
V_180 = F_80 ( V_2 , V_92 ) ;
if ( V_180 < 0 )
goto V_42;
} else {
V_11 -> V_13 = V_92 -> V_12 ;
V_180 = - V_54 ;
if ( F_12 ( V_2 , V_92 ) )
goto V_42;
}
F_82 ( V_2 , V_171 ) ;
V_180 = 0 ;
V_42:
F_79 ( V_2 ) ;
return V_180 ;
}
static int F_85 ( struct V_159 * V_1 , struct V_177 * V_178 ,
int V_179 , int V_59 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_10 * V_11 = F_10 ( V_2 ) ;
struct V_5 * V_92 ;
int V_180 ;
V_2 -> V_182 = V_183 ;
V_1 -> V_184 = V_185 ;
if ( V_179 != sizeof( * V_92 ) )
return - V_84 ;
V_92 = (struct V_5 * ) V_178 ;
if ( V_92 -> V_85 != V_86 )
return - V_164 ;
if ( V_92 -> V_14 . V_17 == V_18 &&
! F_84 ( V_2 , V_186 ) ) {
#if 1
F_86 ( L_6 ,
V_187 -> V_188 ) ;
#else
return - V_189 ;
#endif
}
F_77 ( V_2 ) ;
V_180 = - V_128 ;
if ( F_84 ( V_2 , V_171 ) )
if ( F_81 ( V_2 ) < 0 )
goto V_42;
V_180 = - V_88 ;
if ( ! F_37 ( & V_92 -> V_14 ) )
goto V_42;
V_11 -> V_190 = V_92 -> V_12 ;
V_11 -> V_191 = V_92 -> V_14 . V_15 ;
V_11 -> V_192 = V_92 -> V_14 . V_17 ;
V_1 -> V_184 = V_193 ;
V_2 -> V_182 = V_194 ;
V_180 = 0 ;
V_42:
F_79 ( V_2 ) ;
return V_180 ;
}
static int F_87 ( struct V_159 * V_1 , struct V_177 * V_178 ,
int * V_195 , int V_196 )
{
struct V_5 V_24 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_10 * V_11 = F_10 ( V_2 ) ;
int V_180 ;
F_77 ( V_2 ) ;
V_180 = - V_91 ;
if ( F_84 ( V_2 , V_171 ) )
if ( F_81 ( V_2 ) < 0 )
goto V_42;
* V_195 = sizeof( struct V_5 ) ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
if ( V_196 ) {
V_180 = - V_197 ;
if ( V_2 -> V_182 != V_194 )
goto V_42;
V_24 . V_14 . V_15 = V_11 -> V_191 ;
V_24 . V_14 . V_17 = V_11 -> V_192 ;
V_24 . V_12 = V_11 -> V_190 ;
} else {
V_24 . V_14 . V_15 = V_11 -> V_20 ;
V_24 . V_14 . V_17 = V_11 -> V_21 ;
V_24 . V_12 = V_11 -> V_13 ;
}
V_180 = 0 ;
V_24 . V_85 = V_86 ;
memcpy ( V_178 , & V_24 , sizeof( V_24 ) ) ;
V_42:
F_79 ( V_2 ) ;
return V_180 ;
}
static T_5 int F_88 ( struct V_146 * V_147 )
{
return V_147 -> V_25 [ 12 ] == 22 ;
}
static int F_89 ( struct V_146 * V_147 )
{
struct V_31 * V_32 = F_50 ( & V_99 , L_7 ) ;
struct V_198 * V_199 ;
if ( ! V_32 ) {
F_90 ( V_147 ) ;
return V_200 ;
}
V_147 -> V_160 = F_28 ( V_201 ) ;
F_91 ( V_147 , 13 ) ;
V_147 -> V_32 = V_32 ;
F_92 ( V_147 ) ;
V_199 = F_93 ( V_32 ) ;
V_199 -> V_202 ++ ;
V_199 -> V_203 += V_147 -> V_144 + 13 ;
return F_94 ( V_147 ) ;
}
static int F_95 ( struct V_146 * V_147 , struct V_31 * V_32 ,
struct V_204 * V_205 , T_6 V_206 , int V_207 )
{
struct V_65 * V_82 ;
struct V_39 V_78 ;
if ( V_147 -> V_208 != V_209 || ! V_205 -> V_210 ) {
if ( V_32 -> type == V_123 )
F_53 ( V_126 L_8
L_9 ) ;
goto V_211;
}
V_78 . V_15 = V_205 -> V_210 ;
V_78 . V_17 = V_205 -> V_212 ;
V_82 = F_36 ( & V_78 ) ;
V_206 += 1 << 10 ;
if ( ! V_82 || ! ( V_206 & ( 15 << 10 ) ) )
goto V_211;
if ( V_82 -> V_59 & V_93 ) {
V_78 . V_15 = V_82 -> V_75 . V_15 ;
V_78 . V_17 = V_82 -> V_75 . V_17 ;
}
F_96 ( V_147 , F_97 (unsigned int, origlen,
(rt->dev->hard_header_len +
ddp_dl->header_length + (len_hops & 1023))) ) ;
V_205 -> V_213 = F_28 ( V_206 ) ;
if ( F_98 ( V_147 ) < 22 ) {
struct V_146 * V_214 = F_99 ( V_147 , 32 ) ;
F_90 ( V_147 ) ;
V_147 = V_214 ;
} else
V_147 = F_100 ( V_147 , V_90 ) ;
if ( V_147 == NULL )
goto V_215;
if ( F_101 ( V_82 -> V_32 , V_147 , & V_78 , NULL ) == V_216 )
return V_200 ;
return V_217 ;
V_211:
F_90 ( V_147 ) ;
V_215:
return V_200 ;
}
static int F_102 ( struct V_146 * V_147 , struct V_31 * V_32 ,
struct V_218 * V_219 , struct V_31 * V_220 )
{
struct V_204 * V_205 ;
struct V_1 * V_1 ;
struct V_7 * V_8 ;
struct V_5 V_221 ;
int V_207 ;
T_6 V_206 ;
if ( ! F_46 ( F_47 ( V_32 ) , & V_99 ) )
goto V_215;
if ( ! ( V_147 = F_103 ( V_147 , V_90 ) ) )
goto V_42;
if ( ! F_104 ( V_147 , sizeof( * V_205 ) ) )
goto V_215;
V_205 = F_105 ( V_147 ) ;
V_206 = F_27 ( V_205 -> V_213 ) ;
V_207 = V_147 -> V_144 ;
F_96 ( V_147 , F_97 (unsigned int, skb->len, len_hops & 1023 ) ) ;
if ( V_147 -> V_144 < sizeof( * V_205 ) || V_147 -> V_144 < ( V_206 & 1023 ) ) {
F_106 ( L_10
L_11 , V_206 & 1023 , V_147 -> V_144 ) ;
goto V_215;
}
if ( V_205 -> V_222 &&
F_70 ( V_147 , V_206 & 1023 ) != V_205 -> V_222 )
goto V_215;
if ( ! V_205 -> V_210 )
V_8 = F_34 ( V_205 -> V_212 , V_32 ) ;
else
V_8 = F_35 ( V_205 -> V_210 , V_205 -> V_212 ) ;
if ( ! V_8 ) {
return F_95 ( V_147 , V_32 , V_205 , V_206 , V_207 ) ;
}
if ( F_88 ( V_147 ) )
return F_89 ( V_147 ) ;
V_221 . V_14 . V_15 = V_205 -> V_210 ;
V_221 . V_14 . V_17 = V_205 -> V_212 ;
V_221 . V_12 = V_205 -> V_223 ;
V_1 = F_7 ( & V_221 , V_8 ) ;
if ( ! V_1 )
goto V_215;
if ( F_107 ( V_1 , V_147 ) < 0 )
goto V_215;
return V_217 ;
V_215:
F_90 ( V_147 ) ;
V_42:
return V_200 ;
}
static int F_108 ( struct V_146 * V_147 , struct V_31 * V_32 ,
struct V_218 * V_219 , struct V_31 * V_220 )
{
if ( ! F_46 ( F_47 ( V_32 ) , & V_99 ) )
goto V_224;
if ( F_109 ( V_147 ) [ 2 ] == 1 ) {
struct V_204 * V_205 ;
struct V_39 * V_175 = F_32 ( V_32 ) ;
if ( ! V_175 || V_147 -> V_144 < sizeof( T_1 ) || V_147 -> V_144 > 1023 )
goto V_224;
if ( ! ( V_147 = F_103 ( V_147 , V_90 ) ) )
return 0 ;
V_205 = F_110 ( V_147 , sizeof( * V_205 ) - 4 ) ;
V_205 -> V_212 = F_109 ( V_147 ) [ 0 ] ;
V_205 -> V_225 = F_109 ( V_147 ) [ 1 ] ;
V_205 -> V_210 = V_175 -> V_15 ;
V_205 -> V_226 = V_175 -> V_15 ;
V_205 -> V_222 = 0 ;
V_205 -> V_213 = F_28 ( V_147 -> V_144 + ( V_227 << 10 ) ) ;
}
F_92 ( V_147 ) ;
return F_102 ( V_147 , V_32 , V_219 , V_220 ) ;
V_224:
F_90 ( V_147 ) ;
return 0 ;
}
static int F_111 ( struct V_159 * V_1 , struct V_228 * V_229 , T_7 V_144 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_10 * V_11 = F_10 ( V_2 ) ;
F_112 ( struct V_5 * , V_230 , V_229 -> V_231 ) ;
int V_59 = V_229 -> V_232 ;
int V_233 = 0 ;
struct V_5 V_234 , V_235 ;
struct V_146 * V_147 ;
struct V_31 * V_32 ;
struct V_204 * V_205 ;
int V_236 ;
struct V_65 * V_82 ;
int V_180 ;
if ( V_59 & ~ ( V_237 | V_238 ) )
return - V_84 ;
if ( V_144 > V_239 )
return - V_240 ;
F_77 ( V_2 ) ;
if ( V_230 ) {
V_180 = - V_128 ;
if ( F_84 ( V_2 , V_171 ) )
if ( F_81 ( V_2 ) < 0 )
goto V_42;
V_180 = - V_84 ;
if ( V_229 -> V_241 < sizeof( * V_230 ) ||
V_230 -> V_85 != V_86 )
goto V_42;
V_180 = - V_119 ;
if ( V_230 -> V_14 . V_17 == V_18 &&
! F_84 ( V_2 , V_186 ) ) {
goto V_42;
}
} else {
V_180 = - V_197 ;
if ( V_2 -> V_182 != V_194 )
goto V_42;
V_230 = & V_234 ;
V_230 -> V_85 = V_86 ;
V_230 -> V_12 = V_11 -> V_190 ;
V_230 -> V_14 . V_17 = V_11 -> V_192 ;
V_230 -> V_14 . V_15 = V_11 -> V_191 ;
}
F_113 ( V_2 , L_12 , V_2 ) ;
V_236 = sizeof( struct V_204 ) + V_144 + V_242 -> V_243 ;
if ( V_230 -> V_14 . V_15 || V_230 -> V_14 . V_17 == V_22 ) {
V_82 = F_36 ( & V_230 -> V_14 ) ;
} else {
struct V_39 V_244 ;
V_244 . V_17 = 0 ;
V_244 . V_15 = V_11 -> V_20 ;
V_82 = F_36 ( & V_244 ) ;
}
V_180 = - V_88 ;
if ( ! V_82 )
goto V_42;
V_32 = V_82 -> V_32 ;
F_113 ( V_2 , L_13 ,
V_2 , V_236 , V_32 -> V_142 ) ;
V_236 += V_32 -> V_245 ;
F_79 ( V_2 ) ;
V_147 = F_114 ( V_2 , V_236 , ( V_59 & V_237 ) , & V_180 ) ;
F_77 ( V_2 ) ;
if ( ! V_147 )
goto V_42;
F_115 ( V_147 , V_242 -> V_243 ) ;
F_115 ( V_147 , V_32 -> V_245 ) ;
V_147 -> V_32 = V_32 ;
F_113 ( V_2 , L_14 , V_2 ) ;
V_205 = F_116 ( V_147 , sizeof( struct V_204 ) ) ;
V_205 -> V_213 = F_28 ( V_144 + sizeof( * V_205 ) ) ;
V_205 -> V_210 = V_230 -> V_14 . V_15 ;
V_205 -> V_226 = V_11 -> V_20 ;
V_205 -> V_212 = V_230 -> V_14 . V_17 ;
V_205 -> V_225 = V_11 -> V_21 ;
V_205 -> V_223 = V_230 -> V_12 ;
V_205 -> V_246 = V_11 -> V_13 ;
F_113 ( V_2 , L_15 , V_2 , V_144 ) ;
V_180 = F_117 ( F_116 ( V_147 , V_144 ) , V_229 , V_144 ) ;
if ( V_180 ) {
F_90 ( V_147 ) ;
V_180 = - V_113 ;
goto V_42;
}
if ( V_2 -> V_247 )
V_205 -> V_222 = 0 ;
else
V_205 -> V_222 = F_70 ( V_147 , V_144 + sizeof( * V_205 ) ) ;
if ( V_205 -> V_212 == V_18 &&
! ( V_82 -> V_59 & V_93 ) && ! ( V_32 -> V_59 & V_60 ) ) {
struct V_146 * V_248 = F_118 ( V_147 , V_41 ) ;
if ( V_248 ) {
V_233 = 1 ;
F_113 ( V_2 , L_16 , V_2 ) ;
F_101 ( V_32 , V_248 , & V_230 -> V_14 , NULL ) ;
}
}
if ( V_32 -> V_59 & V_60 || V_233 ) {
F_113 ( V_2 , L_17 , V_2 ) ;
F_119 ( V_147 ) ;
if ( V_205 -> V_212 == V_18 ) {
struct V_39 V_249 ;
V_249 . V_17 = 0 ;
V_249 . V_15 = 0 ;
V_82 = F_36 ( & V_249 ) ;
if ( ! V_82 ) {
F_90 ( V_147 ) ;
V_180 = - V_88 ;
goto V_42;
}
V_32 = V_82 -> V_32 ;
V_147 -> V_32 = V_32 ;
}
V_242 -> V_250 ( V_242 , V_147 , V_32 -> V_251 ) ;
} else {
F_113 ( V_2 , L_18 , V_2 ) ;
if ( V_82 -> V_59 & V_93 ) {
V_235 . V_14 = V_82 -> V_75 ;
V_230 = & V_235 ;
}
F_101 ( V_32 , V_147 , & V_230 -> V_14 , NULL ) ;
}
F_113 ( V_2 , L_19 , V_2 , V_144 ) ;
V_42:
F_79 ( V_2 ) ;
return V_180 ? : V_144 ;
}
static int F_120 ( struct V_159 * V_1 , struct V_228 * V_229 , T_7 V_236 ,
int V_59 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_204 * V_205 ;
int V_252 = 0 ;
int V_148 = 0 ;
int V_180 = 0 ;
struct V_146 * V_147 ;
V_147 = F_121 ( V_2 , V_59 & ~ V_237 ,
V_59 & V_237 , & V_180 ) ;
F_77 ( V_2 ) ;
if ( ! V_147 )
goto V_42;
V_205 = F_105 ( V_147 ) ;
V_252 = F_27 ( V_205 -> V_213 ) & 1023 ;
if ( V_2 -> V_253 != V_165 ) {
V_148 = sizeof( * V_205 ) ;
V_252 -= V_148 ;
}
if ( V_252 > V_236 ) {
V_252 = V_236 ;
V_229 -> V_232 |= V_254 ;
}
V_180 = F_122 ( V_147 , V_148 , V_229 , V_252 ) ;
if ( ! V_180 && V_229 -> V_231 ) {
F_112 ( struct V_5 * , V_24 , V_229 -> V_231 ) ;
V_24 -> V_85 = V_86 ;
V_24 -> V_12 = V_205 -> V_246 ;
V_24 -> V_14 . V_17 = V_205 -> V_225 ;
V_24 -> V_14 . V_15 = V_205 -> V_226 ;
V_229 -> V_241 = sizeof( * V_24 ) ;
}
F_123 ( V_2 , V_147 ) ;
V_42:
F_79 ( V_2 ) ;
return V_180 ? : V_252 ;
}
static int F_124 ( struct V_159 * V_1 , unsigned int V_102 , unsigned long V_103 )
{
int V_162 = - V_255 ;
struct V_1 * V_2 = V_1 -> V_2 ;
void T_2 * V_256 = ( void T_2 * ) V_103 ;
switch ( V_102 ) {
case V_257 : {
long V_258 = V_2 -> V_259 - F_125 ( V_2 ) ;
if ( V_258 < 0 )
V_258 = 0 ;
V_162 = F_126 ( V_258 , ( int T_2 * ) V_256 ) ;
break;
}
case V_260 : {
struct V_146 * V_147 = F_127 ( & V_2 -> V_30 ) ;
long V_258 = 0 ;
if ( V_147 )
V_258 = V_147 -> V_144 - sizeof( struct V_204 ) ;
V_162 = F_126 ( V_258 , ( int T_2 * ) V_256 ) ;
break;
}
case V_261 :
V_162 = F_128 ( V_2 , V_256 ) ;
break;
case V_262 :
V_162 = F_129 ( V_2 , V_256 ) ;
break;
case V_140 :
case V_138 :
V_162 = - V_119 ;
if ( F_52 ( V_118 ) )
V_162 = F_57 ( V_102 , V_256 ) ;
break;
case V_131 :
case V_117 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
F_130 () ;
V_162 = F_48 ( V_102 , V_256 ) ;
F_131 () ;
break;
}
return V_162 ;
}
static int F_132 ( struct V_159 * V_1 , unsigned int V_102 , unsigned long V_103 )
{
if ( V_102 == V_134 )
return F_124 ( V_1 , V_102 , ( unsigned long ) F_133 ( V_103 ) ) ;
return - V_255 ;
}
static int T_8 F_134 ( void )
{
int V_162 = F_135 ( & V_168 , 0 ) ;
if ( V_162 != 0 )
goto V_42;
( void ) F_136 ( & V_263 ) ;
V_242 = F_137 ( V_264 , F_102 ) ;
if ( ! V_242 )
F_53 ( V_265 ) ;
F_138 ( & V_266 ) ;
F_138 ( & V_267 ) ;
F_139 ( & V_268 ) ;
F_140 () ;
F_141 () ;
F_142 () ;
V_42:
return V_162 ;
}
static void T_9 F_143 ( void )
{
#ifdef F_144
F_145 () ;
#endif
F_146 () ;
F_147 () ;
F_148 ( & V_268 ) ;
F_149 ( & V_266 ) ;
F_149 ( & V_267 ) ;
F_150 ( V_242 ) ;
F_151 ( V_167 ) ;
F_152 ( & V_168 ) ;
}
