T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 ;
F_2 ( V_2 , V_4 , & V_3 ) ;
return ( F_3 ( V_2 -> V_5 , V_3 ) ) ;
}
int F_4 ( struct V_6 * V_7 )
{
int V_8 ;
V_8 = F_5 ( & V_7 -> V_9 ) ;
if ( V_8 )
return V_8 ;
F_6 ( & V_10 ) ;
F_7 ( & V_7 -> V_11 , & V_12 ) ;
F_8 ( & V_10 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_13 ,
void * V_14 ,
int V_15 ,
int V_16 ,
void (* F_11) ( struct V_1 * V_13 , void * V_14 , int V_15 ,
int V_17 ) )
{
int V_18 = - V_19 ;
struct V_20 * V_21 ;
if ( V_13 -> V_22 -> V_23 == NULL )
goto V_24;
V_21 = F_12 ( sizeof( struct V_20 ) , V_25 ) ;
if ( V_21 ) {
F_13 ( V_21 , V_15 , V_15 ) ;
if ( ( V_18 =
F_14 ( & V_13 -> V_26 [ V_27 ] ,
V_21 ) ) < 0 ) {
F_15 ( V_21 ) ;
goto V_24;
}
V_13 -> V_28 [ V_15 ] . V_21 = V_21 ;
V_13 -> V_28 [ V_15 ] . V_29 = F_11 ;
V_18 = V_13 -> V_22 -> V_23 ( V_13 , V_14 , V_15 , V_16 ) ;
} else
V_18 = - V_30 ;
V_24:
return V_18 ;
}
int F_16 ( struct V_1 * V_13 , int V_15 )
{
if ( V_13 -> V_22 -> V_31 ) {
V_13 -> V_22 -> V_31 ( V_13 , V_15 ) ;
return F_17 ( V_13 -> V_28 [ V_15 ] . V_21 ) ;
} else
return - V_19 ;
}
int F_18 ( struct V_1 * V_13 ,
void * V_14 ,
int V_15 ,
int V_16 ,
void (* F_19) ( struct V_1 * V_13 , void * V_14 , int V_15 , int V_17 ) )
{
int V_18 = - V_19 ;
struct V_20 * V_21 ;
if ( V_13 -> V_22 -> V_32 == NULL )
goto V_24;
V_21 = F_12 ( sizeof( struct V_20 ) , V_25 ) ;
if ( V_21 ) {
F_13 ( V_21 , V_15 , V_15 ) ;
if ( ( V_18 =
F_14 ( & V_13 -> V_26 [ V_33 ] ,
V_21 ) ) < 0 ) {
F_15 ( V_21 ) ;
goto V_24;
}
V_13 -> V_34 [ V_15 ] . V_21 = V_21 ;
V_13 -> V_34 [ V_15 ] . V_29 = F_19 ;
V_18 = V_13 -> V_22 -> V_32 ( V_13 , V_14 , V_15 , V_16 ) ;
} else
V_18 = - V_30 ;
V_24:
return V_18 ;
}
int F_20 ( struct V_1 * V_13 , int V_15 )
{
if ( V_13 -> V_22 -> V_35 ) {
V_13 -> V_22 -> V_35 ( V_13 , V_15 ) ;
return F_17 ( V_13 -> V_34 [ V_15 ] . V_21 ) ;
} else
return - V_19 ;
}
static int
F_21 ( struct V_1 * V_13 , void * V_14 , struct V_20 * V_21 ,
void (* F_22) ( struct V_1 * V_13 , void * V_14 , T_1 V_36 , T_1 V_37 ,
T_1 V_38 ) )
{
int V_18 = 0 ;
struct V_39 * V_40 ;
if ( ! ( V_40 = F_12 ( sizeof( struct V_39 ) , V_25 ) ) ) {
V_18 = - V_30 ;
goto V_24;
}
V_40 -> V_21 = V_21 ;
V_40 -> F_22 = F_22 ;
V_40 -> V_14 = V_14 ;
F_7 ( & V_40 -> V_41 , & V_13 -> V_42 ) ;
V_24:
return V_18 ;
}
int F_23 ( struct V_1 * V_13 ,
void * V_14 ,
T_1 V_43 ,
T_1 V_44 ,
void (* F_22) ( struct V_1 * V_13 , void * V_14 , T_1 V_36 ,
T_1 V_37 , T_1 V_38 ) )
{
int V_18 = 0 ;
struct V_20 * V_21 = F_12 ( sizeof( struct V_20 ) , V_25 ) ;
if ( V_21 ) {
F_24 ( V_21 , V_43 , V_44 ) ;
if ( ( V_18 =
F_14 ( & V_13 -> V_26 [ V_45 ] ,
V_21 ) ) < 0 ) {
F_15 ( V_21 ) ;
goto V_24;
}
V_18 = F_21 ( V_13 , V_14 , V_21 , F_22 ) ;
} else
V_18 = - V_30 ;
V_24:
return V_18 ;
}
int F_25 ( struct V_1 * V_13 , T_1 V_43 , T_1 V_44 )
{
int V_18 = 0 , V_46 = 0 ;
struct V_39 * V_40 ;
F_26 (dbell, &mport->dbells, node) {
if ( ( V_40 -> V_21 -> V_43 == V_43 ) && ( V_40 -> V_21 -> V_44 == V_44 ) ) {
V_46 = 1 ;
break;
}
}
if ( ! V_46 ) {
V_18 = - V_47 ;
goto V_24;
}
F_27 ( & V_40 -> V_41 ) ;
V_18 = F_17 ( V_40 -> V_21 ) ;
F_15 ( V_40 ) ;
V_24:
return V_18 ;
}
struct V_20 * F_28 ( struct V_6 * V_7 , T_1 V_43 ,
T_1 V_44 )
{
struct V_20 * V_21 = F_12 ( sizeof( struct V_20 ) , V_25 ) ;
if ( V_21 ) {
F_24 ( V_21 , V_43 , V_44 ) ;
if ( F_14 ( & V_7 -> V_26 [ V_45 ] , V_21 )
< 0 ) {
F_15 ( V_21 ) ;
V_21 = NULL ;
}
}
return V_21 ;
}
int F_29 ( struct V_6 * V_7 , struct V_20 * V_21 )
{
int V_18 = F_17 ( V_21 ) ;
F_15 ( V_21 ) ;
return V_18 ;
}
int F_30 ( struct V_6 * V_7 ,
int (* F_31)( struct V_6 * V_7 , union V_48 * V_49 , int V_50 ) )
{
int V_18 = 0 ;
F_6 ( & V_10 ) ;
if ( V_7 -> F_31 != NULL )
V_18 = - V_30 ;
else
V_7 -> F_31 = F_31 ;
F_8 ( & V_10 ) ;
return V_18 ;
}
int F_32 ( struct V_6 * V_7 )
{
int V_18 = - V_30 ;
F_6 ( & V_10 ) ;
if ( V_7 -> F_31 ) {
V_7 -> F_31 = NULL ;
V_18 = 0 ;
}
F_8 ( & V_10 ) ;
return V_18 ;
}
int F_33 ( struct V_1 * V_13 , T_3 V_51 ,
T_4 V_52 , T_2 V_53 , T_2 V_54 )
{
int V_18 = 0 ;
unsigned long V_55 ;
if ( ! V_13 -> V_22 -> V_56 )
return - 1 ;
F_34 ( & V_57 , V_55 ) ;
V_18 = V_13 -> V_22 -> V_56 ( V_13 , V_51 , V_52 , V_53 , V_54 ) ;
F_35 ( & V_57 , V_55 ) ;
return V_18 ;
}
void F_36 ( struct V_1 * V_13 , T_3 V_58 )
{
unsigned long V_55 ;
if ( ! V_13 -> V_22 -> V_59 )
return;
F_34 ( & V_57 , V_55 ) ;
V_13 -> V_22 -> V_59 ( V_13 , V_58 ) ;
F_35 ( & V_57 , V_55 ) ;
}
T_2
F_37 ( struct V_1 * V_2 , int V_51 ,
T_1 V_60 , T_5 V_61 )
{
T_2 V_62 ;
T_2 V_63 ;
V_62 = F_38 ( V_2 , V_51 , V_60 , V_61 , 0 ) ;
while ( V_62 ) {
if ( V_51 )
F_2 ( V_2 , V_62 ,
& V_63 ) ;
else
F_39 ( V_2 , V_60 , V_61 ,
V_62 , & V_63 ) ;
V_63 = F_40 ( V_63 ) ;
switch ( V_63 ) {
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
return V_62 ;
default:
break;
}
V_62 = F_38 ( V_2 , V_51 , V_60 ,
V_61 , V_62 ) ;
}
return V_62 ;
}
struct V_6 * F_41 ( T_2 V_71 , struct V_6 * V_72 )
{
struct V_73 * V_74 ;
struct V_6 * V_7 ;
F_6 ( & V_10 ) ;
V_74 = V_72 ? V_72 -> V_11 . V_75 : V_12 . V_75 ;
while ( V_74 && ( V_74 != & V_12 ) ) {
V_7 = F_42 ( V_74 ) ;
if ( V_7 -> V_71 == V_71 )
goto exit;
V_74 = V_74 -> V_75 ;
}
V_7 = NULL ;
exit:
F_8 ( & V_10 ) ;
return V_7 ;
}
int F_43 ( struct V_6 * V_7 , T_2 V_76 , int V_77 )
{
T_2 V_78 ;
F_44 ( V_7 ,
V_7 -> V_79 + F_45 ( V_76 ) ,
& V_78 ) ;
if ( V_77 )
V_78 |= V_80 ;
else
V_78 &= ~ V_80 ;
F_46 ( V_7 ,
V_7 -> V_79 + F_45 ( V_76 ) ,
V_78 ) ;
return 0 ;
}
void F_47 ( struct V_6 * V_7 , int V_81 )
{
struct V_82 * V_83 = V_84 ;
struct V_82 * V_44 = V_85 ;
while ( V_83 < V_44 ) {
if ( ( V_83 -> V_86 == V_7 -> V_86 ) && ( V_83 -> V_87 == V_7 -> V_87 ) ) {
F_48 ( L_1 ,
F_49 ( V_7 ) ) ;
V_83 -> V_88 ( V_7 , V_81 ) ;
break;
}
V_83 ++ ;
}
if ( ( V_83 >= V_44 ) && ( V_7 -> V_89 & V_90 ) ) {
F_48 ( L_2 ,
F_49 ( V_7 ) ) ;
V_7 -> V_91 -> V_92 = V_93 ;
V_7 -> V_91 -> V_94 = V_95 ;
V_7 -> V_91 -> V_96 = V_97 ;
}
if ( ! V_7 -> V_91 -> V_92 || ! V_7 -> V_91 -> V_94 )
F_50 ( V_98 L_3 ,
F_49 ( V_7 ) ) ;
}
int F_51 ( struct V_1 * V_2 ,
int V_51 , T_1 V_60 ,
T_5 V_61 , T_5 V_99 )
{
#ifdef F_52
T_2 V_78 ;
T_2 V_62 ;
F_48 ( L_4
L_5 , V_51 , V_60 , V_61 , V_99 ) ;
V_62 = F_37 ( V_2 , V_51 , V_60 , V_61 ) ;
if ( V_51 ) {
F_2 ( V_2 , V_62 +
F_45 ( 0 ) ,
& V_78 ) ;
} else {
if ( F_39 ( V_2 , V_60 , V_61 ,
V_62 + F_45 ( V_99 ) , & V_78 ) < 0 )
return - V_100 ;
}
if ( V_78 & V_101 ) {
V_78 = V_78 | V_102
| V_103 ;
} else {
V_78 = V_78 | V_104
| V_105 ;
}
if ( V_51 ) {
F_53 ( V_2 , V_62 +
F_45 ( 0 ) , V_78 ) ;
} else {
if ( F_54 ( V_2 , V_60 , V_61 ,
V_62 + F_45 ( V_99 ) , V_78 ) < 0 )
return - V_100 ;
}
#endif
return 0 ;
}
static int
F_55 ( struct V_6 * V_7 , struct V_6 * * V_106 , int * V_107 )
{
T_2 V_3 ;
int V_108 , V_18 = - V_100 ;
struct V_6 * V_109 = NULL ;
while ( V_7 -> V_109 && ( V_7 -> V_109 -> V_89 & V_110 ) ) {
if ( ! F_44 ( V_7 -> V_109 , V_111 , & V_3 ) ) {
V_109 = V_7 -> V_109 ;
break;
}
V_7 = V_7 -> V_109 ;
}
if ( V_109 == NULL )
goto V_112;
V_108 = V_109 -> V_91 -> V_113 [ V_7 -> V_60 ] ;
if ( V_108 != V_114 ) {
F_48 ( L_6 ,
F_49 ( V_109 ) , V_108 ) ;
* V_106 = V_109 ;
* V_107 = V_108 ;
V_18 = 0 ;
} else
F_48 ( L_7 , F_49 ( V_7 ) ) ;
V_112:
return V_18 ;
}
int
F_56 ( struct V_1 * V_13 , T_1 V_60 , T_5 V_61 )
{
int V_115 = 0 ;
T_2 V_116 ;
while ( F_39 ( V_13 , V_60 , V_61 ,
V_111 , & V_116 ) ) {
V_115 ++ ;
if ( V_115 == V_117 )
return - V_100 ;
F_57 ( 1 ) ;
}
return 0 ;
}
static int F_58 ( struct V_6 * V_7 )
{
return F_56 ( V_7 -> V_118 -> V_119 ,
V_7 -> V_60 , V_7 -> V_61 ) ;
}
static int
F_59 ( struct V_6 * V_7 , int V_76 , T_2 * V_120 )
{
T_2 V_78 ;
int V_121 ;
if ( V_120 ) {
F_44 ( V_7 ,
V_7 -> V_79 + F_60 ( V_76 ) ,
& V_78 ) ;
F_61 ( 50 ) ;
}
F_46 ( V_7 ,
V_7 -> V_79 + F_62 ( V_76 ) ,
V_122 ) ;
if ( V_120 == NULL )
return 0 ;
V_121 = 3 ;
while ( V_121 -- ) {
F_61 ( 50 ) ;
F_44 ( V_7 ,
V_7 -> V_79 + F_60 ( V_76 ) ,
& V_78 ) ;
if ( V_78 & V_123 ) {
* V_120 = V_78 ;
return 0 ;
}
}
return - V_100 ;
}
static int F_63 ( struct V_6 * V_7 , T_2 V_76 , T_2 V_124 )
{
struct V_6 * V_125 = V_7 -> V_91 -> V_125 [ V_76 ] ;
T_2 V_78 ;
T_2 V_126 , V_127 , V_128 ;
if ( V_124 == 0 )
F_44 ( V_7 ,
V_7 -> V_79 + F_64 ( V_76 ) ,
& V_124 ) ;
if ( V_124 & V_129 ) {
F_48 ( L_8 ) ;
if ( F_59 ( V_7 , V_76 , & V_78 ) ) {
F_48 ( L_9 ) ;
goto V_130;
}
F_48 ( L_10 ,
V_76 , V_78 ) ;
V_126 = ( V_78 & V_131 ) >> 5 ;
V_127 = V_78 & V_132 ;
F_44 ( V_7 ,
V_7 -> V_79 + F_65 ( V_76 ) ,
& V_78 ) ;
F_48 ( L_11 , V_76 , V_78 ) ;
V_128 = ( V_78 & V_133 ) >> 24 ;
F_48 ( L_12 \
L_13 ,
V_76 , V_126 , V_127 , V_128 ) ;
if ( ( V_126 != ( ( V_78 & V_134 ) >> 8 ) ) ||
( V_126 != ( V_78 & V_135 ) ) ) {
F_46 ( V_7 ,
V_7 -> V_79 + F_65 ( V_76 ) ,
( V_128 << 24 ) |
( V_126 << 8 ) | V_126 ) ;
V_126 ++ ;
if ( V_125 )
F_46 ( V_125 ,
V_125 -> V_79 +
F_65 ( F_66 ( V_125 -> V_136 ) ) ,
( V_126 << 24 ) |
( V_128 << 8 ) | V_128 ) ;
else
F_48 ( L_14 ) ;
}
V_130:
F_44 ( V_7 ,
V_7 -> V_79 + F_64 ( V_76 ) ,
& V_124 ) ;
F_48 ( L_15 , V_76 , V_124 ) ;
}
if ( ( V_124 & V_137 ) && V_125 ) {
F_48 ( L_16 ) ;
F_59 ( V_125 ,
F_66 ( V_125 -> V_136 ) , NULL ) ;
F_61 ( 50 ) ;
F_44 ( V_7 ,
V_7 -> V_79 + F_64 ( V_76 ) ,
& V_124 ) ;
F_48 ( L_15 , V_76 , V_124 ) ;
}
return ( V_124 & ( V_129 |
V_137 ) ) ? 1 : 0 ;
}
int F_67 ( union V_48 * V_138 )
{
struct V_6 * V_7 ;
T_2 V_124 , V_139 , V_140 ;
int V_18 , V_141 ;
V_7 = F_41 ( ( V_138 -> V_142 . V_143 & V_144 ) , NULL ) ;
if ( V_7 == NULL ) {
F_48 ( L_17 ,
V_145 , V_138 -> V_142 . V_143 ) ;
return - V_100 ;
}
F_48 ( L_18 , F_49 ( V_7 ) ) ;
#ifdef F_68
{
T_2 V_115 ;
for ( V_115 = 0 ; V_115 < V_146 / sizeof( T_2 ) ; ) {
F_48 ( L_19 ,
V_115 * 4 , V_138 -> V_147 [ V_115 ] , V_138 -> V_147 [ V_115 + 1 ] ,
V_138 -> V_147 [ V_115 + 2 ] , V_138 -> V_147 [ V_115 + 3 ] ) ;
V_115 += 4 ;
}
}
#endif
if ( V_7 -> F_31 != NULL ) {
V_18 = V_7 -> F_31 ( V_7 , V_138 , 0 ) ;
if ( V_18 == 0 )
return 0 ;
}
V_141 = V_138 -> V_142 . V_148 & 0xFF ;
if ( F_58 ( V_7 ) ) {
F_48 ( L_20 ) ;
if ( F_55 ( V_7 , & V_7 , & V_141 ) ) {
F_69 ( L_21 ,
F_49 ( V_7 ) ) ;
return - V_100 ;
}
V_138 = NULL ;
}
if ( ! ( V_7 -> V_89 & V_110 ) )
return 0 ;
if ( V_7 -> V_79 == 0 ) {
F_69 ( L_22 ,
F_49 ( V_7 ) ) ;
return 0 ;
}
if ( V_7 -> V_91 -> V_149 )
V_7 -> V_91 -> V_149 ( V_7 , V_141 ) ;
F_44 ( V_7 ,
V_7 -> V_79 + F_64 ( V_141 ) ,
& V_124 ) ;
F_48 ( L_23 , V_141 , V_124 ) ;
if ( V_124 & V_150 ) {
if ( ! ( V_7 -> V_91 -> V_151 & ( 1 << V_141 ) ) ) {
V_7 -> V_91 -> V_151 |= ( 1 << V_141 ) ;
F_43 ( V_7 , V_141 , 0 ) ;
F_48 ( L_24 ,
F_49 ( V_7 ) , V_141 ) ;
}
if ( V_124 & ( V_129 |
V_137 ) ) {
if ( F_63 ( V_7 , V_141 , V_124 ) )
F_63 ( V_7 , V_141 , 0 ) ;
}
} else {
if ( V_7 -> V_91 -> V_151 & ( 1 << V_141 ) ) {
V_7 -> V_91 -> V_151 &= ~ ( 1 << V_141 ) ;
F_43 ( V_7 , V_141 , 1 ) ;
F_46 ( V_7 ,
V_7 -> V_79 +
F_65 ( V_141 ) ,
V_152 ) ;
F_48 ( L_25 ,
F_49 ( V_7 ) , V_141 ) ;
}
}
F_44 ( V_7 ,
V_7 -> V_153 + F_70 ( V_141 ) , & V_139 ) ;
if ( V_139 ) {
F_48 ( L_26 ,
V_141 , V_139 ) ;
F_46 ( V_7 ,
V_7 -> V_153 + F_70 ( V_141 ) , 0 ) ;
}
F_44 ( V_7 ,
V_7 -> V_153 + V_154 , & V_140 ) ;
if ( V_140 ) {
F_48 ( L_27 ,
V_140 ) ;
F_46 ( V_7 ,
V_7 -> V_153 + V_154 , 0 ) ;
}
F_46 ( V_7 ,
V_7 -> V_79 + F_64 ( V_141 ) ,
V_124 ) ;
return 0 ;
}
T_2
F_38 ( struct V_1 * V_2 , int V_51 , T_1 V_60 ,
T_5 V_61 , T_2 V_72 )
{
T_2 V_155 ;
if ( V_72 == 0 ) {
if ( V_51 )
F_2 ( V_2 , V_156 ,
& V_155 ) ;
else
F_39 ( V_2 , V_60 , V_61 ,
V_156 , & V_155 ) ;
return V_155 & V_157 ;
} else {
if ( V_51 )
F_2 ( V_2 , V_72 , & V_155 ) ;
else
F_39 ( V_2 , V_60 , V_61 ,
V_72 , & V_155 ) ;
return F_40 ( V_155 ) ;
}
}
T_2
F_71 ( struct V_1 * V_2 , int V_51 , T_1 V_60 ,
T_5 V_61 , int V_158 )
{
T_2 V_159 , V_62 , V_63 ;
if ( V_51 )
F_2 ( V_2 , V_156 , & V_159 ) ;
else
F_39 ( V_2 , V_60 , V_61 ,
V_156 , & V_159 ) ;
V_62 = V_159 & V_157 ;
while ( V_62 ) {
if ( V_51 )
F_2 ( V_2 , V_62 ,
& V_63 ) ;
else
F_39 ( V_2 , V_60 , V_61 ,
V_62 , & V_63 ) ;
if ( F_40 ( V_63 ) == V_158 )
return V_62 ;
if ( ! ( V_62 = F_72 ( V_63 ) ) )
break;
}
return 0 ;
}
struct V_6 * F_73 ( T_1 V_86 , T_1 V_87 ,
T_1 V_160 , T_1 V_161 , struct V_6 * V_72 )
{
struct V_73 * V_74 ;
struct V_6 * V_7 ;
F_74 ( F_75 () ) ;
F_6 ( & V_10 ) ;
V_74 = V_72 ? V_72 -> V_11 . V_75 : V_12 . V_75 ;
while ( V_74 && ( V_74 != & V_12 ) ) {
V_7 = F_42 ( V_74 ) ;
if ( ( V_86 == V_162 || V_7 -> V_86 == V_86 ) &&
( V_87 == V_162 || V_7 -> V_87 == V_87 ) &&
( V_160 == V_162 || V_7 -> V_160 == V_160 ) &&
( V_161 == V_162 || V_7 -> V_161 == V_161 ) )
goto exit;
V_74 = V_74 -> V_75 ;
}
V_7 = NULL ;
exit:
F_76 ( V_72 ) ;
V_7 = F_77 ( V_7 ) ;
F_8 ( & V_10 ) ;
return V_7 ;
}
struct V_6 * F_78 ( T_1 V_86 , T_1 V_87 , struct V_6 * V_72 )
{
return F_73 ( V_86 , V_87 , V_162 , V_162 , V_72 ) ;
}
int V_93 ( struct V_1 * V_13 , T_1 V_60 , T_5 V_61 ,
T_1 V_163 , T_1 V_164 , T_5 V_165 )
{
if ( V_163 == V_166 ) {
F_54 ( V_13 , V_60 , V_61 ,
V_167 ,
( T_2 ) V_164 ) ;
F_54 ( V_13 , V_60 , V_61 ,
V_168 ,
( T_2 ) V_165 ) ;
}
F_61 ( 10 ) ;
return 0 ;
}
int V_95 ( struct V_1 * V_13 , T_1 V_60 , T_5 V_61 ,
T_1 V_163 , T_1 V_164 , T_5 * V_165 )
{
T_2 V_3 ;
if ( V_163 == V_166 ) {
F_54 ( V_13 , V_60 , V_61 ,
V_167 , V_164 ) ;
F_39 ( V_13 , V_60 , V_61 ,
V_168 , & V_3 ) ;
* V_165 = ( T_5 ) V_3 ;
}
return 0 ;
}
int V_97 ( struct V_1 * V_13 , T_1 V_60 , T_5 V_61 ,
T_1 V_163 )
{
T_2 V_169 = 0xff ;
T_2 V_115 , V_89 , V_170 = 1 , V_171 = 0 ;
T_2 V_172 = V_114 ;
if ( V_163 == V_166 ) {
F_39 ( V_13 , V_60 , V_61 ,
V_173 , & V_89 ) ;
if ( V_13 -> V_5 ) {
F_39 ( V_13 , V_60 , V_61 ,
V_174 ,
& V_169 ) ;
V_169 &= V_175 ;
}
if ( V_89 & V_176 ) {
V_171 = 0x80000000 ;
V_170 = 4 ;
V_172 = ( V_114 << 24 ) |
( V_114 << 16 ) |
( V_114 << 8 ) |
V_114 ;
}
for ( V_115 = 0 ; V_115 <= V_169 ; ) {
F_54 ( V_13 , V_60 , V_61 ,
V_167 ,
V_171 | V_115 ) ;
F_54 ( V_13 , V_60 , V_61 ,
V_168 ,
V_172 ) ;
V_115 += V_170 ;
}
}
F_61 ( 10 ) ;
return 0 ;
}
static bool F_79 ( struct V_177 * V_178 , void * V_179 )
{
struct V_6 * V_7 = V_179 ;
return ( V_7 -> V_118 -> V_119 ==
F_80 ( V_178 -> V_180 , struct V_1 , V_181 ) ) ;
}
struct V_177 * F_81 ( struct V_6 * V_7 )
{
T_6 V_182 ;
struct V_177 * V_183 ;
F_82 ( V_182 ) ;
F_83 ( V_184 , V_182 ) ;
V_183 = F_84 ( V_182 , F_79 , V_7 ) ;
return V_183 ;
}
void F_85 ( struct V_177 * V_183 )
{
F_86 ( V_183 ) ;
}
struct V_185 * F_87 ( struct V_6 * V_7 ,
struct V_177 * V_183 , struct V_186 * V_187 ,
enum V_188 V_189 , unsigned long V_55 )
{
struct V_185 * V_190 = NULL ;
struct V_191 V_192 ;
if ( V_183 -> V_180 -> V_193 == NULL ) {
F_69 ( L_28 , V_145 ) ;
return NULL ;
}
V_192 . V_60 = V_7 -> V_60 ;
V_192 . V_194 = V_187 -> V_194 ;
V_192 . V_195 = V_187 -> V_195 ;
V_192 . V_196 = V_187 -> V_196 ;
V_190 = F_88 ( V_183 , V_187 -> V_197 , V_187 -> V_198 ,
V_189 , V_55 , & V_192 ) ;
return V_190 ;
}
struct V_1 * F_89 ( int V_199 )
{
struct V_1 * V_2 ;
F_90 ( & V_200 ) ;
F_26 (port, &rio_mports, node) {
if ( V_2 -> V_201 == V_199 )
goto V_46;
}
V_2 = NULL ;
V_46:
F_91 ( & V_200 ) ;
return V_2 ;
}
int F_92 ( int V_199 , struct V_202 * V_203 )
{
struct V_1 * V_2 ;
int V_18 = - V_204 ;
F_90 ( & V_200 ) ;
F_26 (port, &rio_mports, node) {
if ( V_2 -> V_201 == V_199 || V_199 == V_205 ) {
if ( V_2 -> V_206 && V_199 == V_205 )
continue;
else if ( V_2 -> V_206 )
break;
V_2 -> V_206 = V_203 ;
V_18 = 0 ;
if ( V_199 != V_205 )
break;
}
}
F_91 ( & V_200 ) ;
return V_18 ;
}
int F_93 ( int V_199 )
{
struct V_1 * V_2 ;
F_90 ( & V_200 ) ;
F_26 (port, &rio_mports, node) {
if ( V_2 -> V_201 == V_199 || V_199 == V_205 ) {
if ( V_2 -> V_206 )
V_2 -> V_206 = NULL ;
if ( V_199 != V_205 )
break;
}
}
F_91 ( & V_200 ) ;
return 0 ;
}
static void F_94 ( struct V_6 * V_9 )
{
}
static int F_95 ( void )
{
struct V_6 * V_9 = NULL ;
while ( ( V_9 = F_78 ( V_162 , V_162 , V_9 ) ) != NULL ) {
F_94 ( V_9 ) ;
}
return 0 ;
}
static void F_96 ( struct V_207 * V_208 )
{
struct V_209 * V_210 ;
V_210 = F_80 ( V_208 , struct V_209 , V_210 ) ;
F_48 ( L_29 ,
V_210 -> V_13 -> V_201 , V_210 -> V_13 -> V_211 ) ;
V_210 -> V_13 -> V_206 -> V_212 ( V_210 -> V_13 , 0 ) ;
}
int F_97 ( void )
{
struct V_1 * V_2 ;
struct V_209 * V_210 ;
int V_74 = 0 ;
if ( ! V_213 )
return - V_214 ;
F_90 ( & V_200 ) ;
F_26 (port, &rio_mports, node) {
if ( V_2 -> V_215 >= 0 ) {
if ( V_2 -> V_206 )
V_2 -> V_206 -> V_216 ( V_2 , 0 ) ;
} else
V_74 ++ ;
}
F_91 ( & V_200 ) ;
if ( ! V_74 )
goto V_217;
V_218 = F_98 ( L_30 , 0 , 0 ) ;
if ( ! V_218 ) {
F_69 ( L_31 ) ;
goto V_217;
}
V_210 = F_99 ( V_74 , sizeof *V_210 , V_25 ) ;
if ( ! V_210 ) {
F_69 ( L_32 ) ;
F_100 ( V_218 ) ;
goto V_217;
}
V_74 = 0 ;
F_90 ( & V_200 ) ;
F_26 (port, &rio_mports, node) {
if ( V_2 -> V_215 < 0 && V_2 -> V_206 ) {
V_210 [ V_74 ] . V_13 = V_2 ;
F_101 ( & V_210 [ V_74 ] . V_210 , F_96 ) ;
F_102 ( V_218 , & V_210 [ V_74 ] . V_210 ) ;
V_74 ++ ;
}
}
F_91 ( & V_200 ) ;
F_103 ( V_218 ) ;
F_48 ( L_33 ) ;
F_100 ( V_218 ) ;
F_15 ( V_210 ) ;
V_217:
F_95 () ;
return 0 ;
}
static int F_104 ( int V_219 )
{
if ( ! V_220 [ 0 ] || V_220 [ 0 ] <= V_219 || V_219 >= V_221 )
return - 1 ;
return V_220 [ V_219 + 1 ] ;
}
static int F_105 ( char * V_222 )
{
( void ) F_106 ( V_222 , F_107 ( V_220 ) , V_220 ) ;
return 1 ;
}
int F_108 ( struct V_1 * V_2 )
{
if ( V_213 >= V_221 ) {
F_69 ( L_34 ) ;
return 1 ;
}
V_2 -> V_201 = V_213 ++ ;
V_2 -> V_215 = F_104 ( V_2 -> V_201 ) ;
V_2 -> V_206 = NULL ;
F_90 ( & V_200 ) ;
F_7 ( & V_2 -> V_41 , & V_223 ) ;
F_91 ( & V_200 ) ;
return 0 ;
}
