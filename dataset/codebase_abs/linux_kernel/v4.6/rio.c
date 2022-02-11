T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 ;
F_2 ( V_2 , V_4 , & V_3 ) ;
return ( F_3 ( V_2 -> V_5 , V_3 ) ) ;
}
int F_4 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
if ( ! V_2 -> V_8 -> V_9 )
return - V_10 ;
return V_2 -> V_8 -> V_9 ( V_2 , V_7 ) ;
}
struct V_11 * F_5 ( struct V_1 * V_12 )
{
struct V_11 * V_13 ;
V_13 = F_6 ( sizeof( struct V_11 ) , V_14 ) ;
if ( V_13 ) {
F_7 ( & V_13 -> V_15 ) ;
F_7 ( & V_13 -> V_16 ) ;
F_7 ( & V_13 -> V_17 ) ;
F_7 ( & V_13 -> V_18 ) ;
V_12 -> V_13 = V_13 ;
}
return V_13 ;
}
int F_8 ( struct V_11 * V_13 )
{
int V_19 ;
V_19 = F_9 ( & V_13 -> V_20 ) ;
if ( V_19 )
return V_19 ;
F_10 ( & V_21 ) ;
F_11 ( & V_13 -> V_15 , & V_22 ) ;
F_12 ( & V_21 ) ;
return 0 ;
}
void F_13 ( struct V_11 * V_13 )
{
F_10 ( & V_21 ) ;
if ( ! F_14 ( & V_13 -> V_15 ) )
F_15 ( & V_13 -> V_15 ) ;
F_12 ( & V_21 ) ;
if ( V_13 -> V_23 )
V_13 -> V_23 ( V_13 ) ;
F_16 ( & V_13 -> V_20 ) ;
}
void F_17 ( struct V_1 * V_2 , T_1 V_24 )
{
F_18 ( V_2 , V_4 ,
F_19 ( V_2 -> V_5 , V_24 ) ) ;
}
int F_20 ( struct V_25 * V_26 )
{
int V_19 ;
F_21 ( & V_26 -> V_27 , V_28 ) ;
V_19 = F_9 ( & V_26 -> V_20 ) ;
if ( V_19 )
return V_19 ;
F_10 ( & V_21 ) ;
F_11 ( & V_26 -> V_29 , & V_30 ) ;
if ( V_26 -> V_13 ) {
F_11 ( & V_26 -> V_31 , & V_26 -> V_13 -> V_16 ) ;
if ( V_26 -> V_32 & V_33 )
F_11 ( & V_26 -> V_34 -> V_15 ,
& V_26 -> V_13 -> V_17 ) ;
}
F_12 ( & V_21 ) ;
F_22 ( V_26 ) ;
return 0 ;
}
void F_23 ( struct V_25 * V_26 , enum V_35 V_27 )
{
F_24 ( L_1 , V_36 , F_25 ( V_26 ) ) ;
F_21 ( & V_26 -> V_27 , V_27 ) ;
F_10 ( & V_21 ) ;
F_15 ( & V_26 -> V_29 ) ;
if ( V_26 -> V_13 ) {
F_15 ( & V_26 -> V_31 ) ;
if ( V_26 -> V_32 & V_33 ) {
F_15 ( & V_26 -> V_34 -> V_15 ) ;
F_26 ( V_26 -> V_34 -> V_37 ) ;
}
}
F_12 ( & V_21 ) ;
F_27 ( V_26 ) ;
F_16 ( & V_26 -> V_20 ) ;
}
int F_28 ( struct V_1 * V_12 ,
void * V_38 ,
int V_39 ,
int V_40 ,
void (* F_29) ( struct V_1 * V_12 , void * V_38 , int V_39 ,
int V_41 ) )
{
int V_42 = - V_43 ;
struct V_44 * V_45 ;
if ( V_12 -> V_8 -> V_46 == NULL )
goto V_47;
V_45 = F_6 ( sizeof( struct V_44 ) , V_14 ) ;
if ( V_45 ) {
F_30 ( V_45 , V_39 , V_39 ) ;
if ( ( V_42 =
F_31 ( & V_12 -> V_48 [ V_49 ] ,
V_45 ) ) < 0 ) {
F_26 ( V_45 ) ;
goto V_47;
}
V_12 -> V_50 [ V_39 ] . V_45 = V_45 ;
V_12 -> V_50 [ V_39 ] . V_51 = F_29 ;
V_42 = V_12 -> V_8 -> V_46 ( V_12 , V_38 , V_39 , V_40 ) ;
} else
V_42 = - V_52 ;
V_47:
return V_42 ;
}
int F_32 ( struct V_1 * V_12 , int V_39 )
{
if ( V_12 -> V_8 -> V_53 ) {
V_12 -> V_8 -> V_53 ( V_12 , V_39 ) ;
return F_33 ( V_12 -> V_50 [ V_39 ] . V_45 ) ;
} else
return - V_43 ;
}
int F_34 ( struct V_1 * V_12 ,
void * V_38 ,
int V_39 ,
int V_40 ,
void (* F_35) ( struct V_1 * V_12 , void * V_38 , int V_39 , int V_41 ) )
{
int V_42 = - V_43 ;
struct V_44 * V_45 ;
if ( V_12 -> V_8 -> V_54 == NULL )
goto V_47;
V_45 = F_6 ( sizeof( struct V_44 ) , V_14 ) ;
if ( V_45 ) {
F_30 ( V_45 , V_39 , V_39 ) ;
if ( ( V_42 =
F_31 ( & V_12 -> V_48 [ V_55 ] ,
V_45 ) ) < 0 ) {
F_26 ( V_45 ) ;
goto V_47;
}
V_12 -> V_56 [ V_39 ] . V_45 = V_45 ;
V_12 -> V_56 [ V_39 ] . V_51 = F_35 ;
V_42 = V_12 -> V_8 -> V_54 ( V_12 , V_38 , V_39 , V_40 ) ;
} else
V_42 = - V_52 ;
V_47:
return V_42 ;
}
int F_36 ( struct V_1 * V_12 , int V_39 )
{
if ( V_12 -> V_8 -> V_57 ) {
V_12 -> V_8 -> V_57 ( V_12 , V_39 ) ;
return F_33 ( V_12 -> V_56 [ V_39 ] . V_45 ) ;
} else
return - V_43 ;
}
static int
F_37 ( struct V_1 * V_12 , void * V_38 , struct V_44 * V_45 ,
void (* F_38) ( struct V_1 * V_12 , void * V_38 , T_1 V_58 , T_1 V_59 ,
T_1 V_60 ) )
{
int V_42 = 0 ;
struct V_61 * V_62 ;
if ( ! ( V_62 = F_39 ( sizeof( struct V_61 ) , V_14 ) ) ) {
V_42 = - V_52 ;
goto V_47;
}
V_62 -> V_45 = V_45 ;
V_62 -> F_38 = F_38 ;
V_62 -> V_38 = V_38 ;
F_40 ( & V_12 -> V_63 ) ;
F_11 ( & V_62 -> V_15 , & V_12 -> V_64 ) ;
F_41 ( & V_12 -> V_63 ) ;
V_47:
return V_42 ;
}
int F_42 ( struct V_1 * V_12 ,
void * V_38 ,
T_1 V_65 ,
T_1 V_66 ,
void (* F_38) ( struct V_1 * V_12 , void * V_38 , T_1 V_58 ,
T_1 V_59 , T_1 V_60 ) )
{
int V_42 = 0 ;
struct V_44 * V_45 = F_6 ( sizeof( struct V_44 ) , V_14 ) ;
if ( V_45 ) {
F_43 ( V_45 , V_65 , V_66 ) ;
if ( ( V_42 =
F_31 ( & V_12 -> V_48 [ V_67 ] ,
V_45 ) ) < 0 ) {
F_26 ( V_45 ) ;
goto V_47;
}
V_42 = F_37 ( V_12 , V_38 , V_45 , F_38 ) ;
} else
V_42 = - V_52 ;
V_47:
return V_42 ;
}
int F_44 ( struct V_1 * V_12 , T_1 V_65 , T_1 V_66 )
{
int V_42 = 0 , V_68 = 0 ;
struct V_61 * V_62 ;
F_40 ( & V_12 -> V_63 ) ;
F_45 (dbell, &mport->dbells, node) {
if ( ( V_62 -> V_45 -> V_65 == V_65 ) && ( V_62 -> V_45 -> V_66 == V_66 ) ) {
F_15 ( & V_62 -> V_15 ) ;
V_68 = 1 ;
break;
}
}
F_41 ( & V_12 -> V_63 ) ;
if ( ! V_68 ) {
V_42 = - V_69 ;
goto V_47;
}
V_42 = F_33 ( V_62 -> V_45 ) ;
F_26 ( V_62 ) ;
V_47:
return V_42 ;
}
struct V_44 * F_46 ( struct V_25 * V_26 , T_1 V_65 ,
T_1 V_66 )
{
struct V_44 * V_45 = F_6 ( sizeof( struct V_44 ) , V_14 ) ;
if ( V_45 ) {
F_43 ( V_45 , V_65 , V_66 ) ;
if ( F_31 ( & V_26 -> V_48 [ V_67 ] , V_45 )
< 0 ) {
F_26 ( V_45 ) ;
V_45 = NULL ;
}
}
return V_45 ;
}
int F_47 ( struct V_25 * V_26 , struct V_44 * V_45 )
{
int V_42 = F_33 ( V_45 ) ;
F_26 ( V_45 ) ;
return V_42 ;
}
int F_48 ( struct V_1 * V_12 , void * V_70 ,
int (* F_49)( struct V_1 * V_12 ,
void * V_70 , union V_71 * V_72 , int V_73 ) )
{
int V_42 = 0 ;
struct V_74 * V_75 ;
V_75 = F_6 ( sizeof( struct V_74 ) , V_14 ) ;
if ( ! V_75 ) {
V_42 = - V_52 ;
goto V_47;
}
V_75 -> F_49 = F_49 ;
V_75 -> V_70 = V_70 ;
F_40 ( & V_12 -> V_63 ) ;
F_11 ( & V_75 -> V_15 , & V_12 -> V_76 ) ;
F_41 ( & V_12 -> V_63 ) ;
V_47:
return V_42 ;
}
int F_50 ( struct V_1 * V_12 , void * V_70 ,
int (* F_49)( struct V_1 * V_12 ,
void * V_70 , union V_71 * V_72 , int V_73 ) )
{
int V_42 = - V_69 ;
struct V_74 * V_75 ;
F_40 ( & V_12 -> V_63 ) ;
F_45 (pwrite, &mport->pwrites, node) {
if ( V_75 -> F_49 == F_49 && V_75 -> V_70 == V_70 ) {
F_15 ( & V_75 -> V_15 ) ;
F_26 ( V_75 ) ;
V_42 = 0 ;
break;
}
}
F_41 ( & V_12 -> V_63 ) ;
return V_42 ;
}
int F_51 ( struct V_25 * V_26 ,
int (* F_49)( struct V_25 * V_26 , union V_71 * V_72 , int V_73 ) )
{
int V_42 = 0 ;
F_10 ( & V_21 ) ;
if ( V_26 -> F_49 != NULL )
V_42 = - V_52 ;
else
V_26 -> F_49 = F_49 ;
F_12 ( & V_21 ) ;
return V_42 ;
}
int F_52 ( struct V_25 * V_26 )
{
int V_42 = - V_52 ;
F_10 ( & V_21 ) ;
if ( V_26 -> F_49 ) {
V_26 -> F_49 = NULL ;
V_42 = 0 ;
}
F_12 ( & V_21 ) ;
return V_42 ;
}
void F_53 ( struct V_1 * V_12 , int V_77 )
{
if ( V_12 -> V_8 -> V_78 ) {
F_40 ( & V_12 -> V_63 ) ;
if ( ( V_77 && ++ V_12 -> V_79 == 1 ) ||
( ! V_77 && V_12 -> V_79 && -- V_12 -> V_79 == 0 ) )
V_12 -> V_8 -> V_78 ( V_12 , V_77 ) ;
F_41 ( & V_12 -> V_63 ) ;
}
}
int F_54 ( struct V_1 * V_12 , T_3 V_80 ,
T_4 V_81 , T_2 V_82 , T_2 V_83 )
{
int V_42 = 0 ;
unsigned long V_84 ;
if ( ! V_12 -> V_8 -> V_85 )
return - 1 ;
F_55 ( & V_86 , V_84 ) ;
V_42 = V_12 -> V_8 -> V_85 ( V_12 , V_80 , V_81 , V_82 , V_83 ) ;
F_56 ( & V_86 , V_84 ) ;
return V_42 ;
}
void F_57 ( struct V_1 * V_12 , T_3 V_87 )
{
unsigned long V_84 ;
if ( ! V_12 -> V_8 -> V_88 )
return;
F_55 ( & V_86 , V_84 ) ;
V_12 -> V_8 -> V_88 ( V_12 , V_87 ) ;
F_56 ( & V_86 , V_84 ) ;
}
int F_58 ( struct V_1 * V_12 , T_1 V_89 , T_4 V_81 ,
T_2 V_82 , T_2 V_83 , T_3 * V_80 )
{
int V_42 = 0 ;
unsigned long V_84 ;
if ( ! V_12 -> V_8 -> V_90 )
return - V_91 ;
F_55 ( & V_86 , V_84 ) ;
V_42 = V_12 -> V_8 -> V_90 ( V_12 , V_89 , V_81 , V_82 ,
V_83 , V_80 ) ;
F_56 ( & V_86 , V_84 ) ;
return V_42 ;
}
void F_59 ( struct V_1 * V_12 , T_1 V_89 , T_4 V_92 )
{
unsigned long V_84 ;
if ( ! V_12 -> V_8 -> V_93 )
return;
F_55 ( & V_86 , V_84 ) ;
V_12 -> V_8 -> V_93 ( V_12 , V_89 , V_92 ) ;
F_56 ( & V_86 , V_84 ) ;
}
T_2
F_60 ( struct V_1 * V_2 , int V_80 ,
T_1 V_89 , T_5 V_94 )
{
T_2 V_95 ;
T_2 V_96 ;
V_95 = F_61 ( V_2 , V_80 , V_89 , V_94 , 0 ) ;
while ( V_95 ) {
if ( V_80 )
F_2 ( V_2 , V_95 ,
& V_96 ) ;
else
F_62 ( V_2 , V_89 , V_94 ,
V_95 , & V_96 ) ;
V_96 = F_63 ( V_96 ) ;
switch ( V_96 ) {
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
return V_95 ;
default:
break;
}
V_95 = F_61 ( V_2 , V_80 , V_89 ,
V_94 , V_95 ) ;
}
return V_95 ;
}
struct V_25 * F_64 ( T_2 V_104 , struct V_25 * V_105 )
{
struct V_106 * V_107 ;
struct V_25 * V_26 ;
F_10 ( & V_21 ) ;
V_107 = V_105 ? V_105 -> V_29 . V_108 : V_30 . V_108 ;
while ( V_107 && ( V_107 != & V_30 ) ) {
V_26 = F_65 ( V_107 ) ;
if ( V_26 -> V_104 == V_104 )
goto exit;
V_107 = V_107 -> V_108 ;
}
V_26 = NULL ;
exit:
F_12 ( & V_21 ) ;
return V_26 ;
}
int F_66 ( struct V_25 * V_26 , T_2 V_109 , int V_63 )
{
T_2 V_110 ;
F_67 ( V_26 ,
V_26 -> V_111 + F_68 ( V_109 ) ,
& V_110 ) ;
if ( V_63 )
V_110 |= V_112 ;
else
V_110 &= ~ V_112 ;
F_69 ( V_26 ,
V_26 -> V_111 + F_68 ( V_109 ) ,
V_110 ) ;
return 0 ;
}
int F_70 ( struct V_1 * V_2 ,
int V_80 , T_1 V_89 ,
T_5 V_94 , T_5 V_113 )
{
#ifdef F_71
T_2 V_110 ;
T_2 V_95 ;
F_24 ( L_2
L_3 , V_80 , V_89 , V_94 , V_113 ) ;
V_95 = F_60 ( V_2 , V_80 , V_89 , V_94 ) ;
if ( V_80 ) {
F_2 ( V_2 , V_95 +
F_68 ( 0 ) ,
& V_110 ) ;
} else {
if ( F_62 ( V_2 , V_89 , V_94 ,
V_95 + F_68 ( V_113 ) , & V_110 ) < 0 )
return - V_114 ;
}
if ( V_110 & V_115 ) {
V_110 = V_110 | V_116
| V_117 ;
} else {
V_110 = V_110 | V_118
| V_119 ;
}
if ( V_80 ) {
F_18 ( V_2 , V_95 +
F_68 ( 0 ) , V_110 ) ;
} else {
if ( F_72 ( V_2 , V_89 , V_94 ,
V_95 + F_68 ( V_113 ) , V_110 ) < 0 )
return - V_114 ;
}
#endif
return 0 ;
}
static int
F_73 ( struct V_25 * V_26 , struct V_25 * * V_120 , int * V_121 )
{
T_2 V_3 ;
int V_122 , V_42 = - V_114 ;
struct V_25 * V_123 = NULL ;
while ( V_26 -> V_123 && ( V_26 -> V_123 -> V_32 & V_33 ) ) {
if ( ! F_67 ( V_26 -> V_123 , V_124 , & V_3 ) ) {
V_123 = V_26 -> V_123 ;
break;
}
V_26 = V_26 -> V_123 ;
}
if ( V_123 == NULL )
goto V_125;
V_122 = V_123 -> V_34 -> V_37 [ V_26 -> V_89 ] ;
if ( V_122 != V_126 ) {
F_24 ( L_4 ,
F_25 ( V_123 ) , V_122 ) ;
* V_120 = V_123 ;
* V_121 = V_122 ;
V_42 = 0 ;
} else
F_24 ( L_5 , F_25 ( V_26 ) ) ;
V_125:
return V_42 ;
}
int
F_74 ( struct V_1 * V_12 , T_1 V_89 , T_5 V_94 )
{
int V_127 = 0 ;
T_2 V_128 ;
while ( F_62 ( V_12 , V_89 , V_94 ,
V_124 , & V_128 ) ) {
V_127 ++ ;
if ( V_127 == V_129 )
return - V_114 ;
F_75 ( 1 ) ;
}
return 0 ;
}
static int F_76 ( struct V_25 * V_26 )
{
return F_74 ( V_26 -> V_13 -> V_130 ,
V_26 -> V_89 , V_26 -> V_94 ) ;
}
static int
F_77 ( struct V_25 * V_26 , int V_109 , T_2 * V_131 )
{
T_2 V_110 ;
int V_132 ;
if ( V_131 ) {
F_67 ( V_26 ,
V_26 -> V_111 + F_78 ( V_109 ) ,
& V_110 ) ;
F_79 ( 50 ) ;
}
F_69 ( V_26 ,
V_26 -> V_111 + F_80 ( V_109 ) ,
V_133 ) ;
if ( V_131 == NULL )
return 0 ;
V_132 = 3 ;
while ( V_132 -- ) {
F_79 ( 50 ) ;
F_67 ( V_26 ,
V_26 -> V_111 + F_78 ( V_109 ) ,
& V_110 ) ;
if ( V_110 & V_134 ) {
* V_131 = V_110 ;
return 0 ;
}
}
return - V_114 ;
}
static int F_81 ( struct V_25 * V_26 , T_2 V_109 , T_2 V_135 )
{
struct V_25 * V_136 = V_26 -> V_34 -> V_136 [ V_109 ] ;
T_2 V_110 ;
T_2 V_137 , V_138 , V_139 ;
if ( V_135 == 0 )
F_67 ( V_26 ,
V_26 -> V_111 + F_82 ( V_109 ) ,
& V_135 ) ;
if ( V_135 & V_140 ) {
F_24 ( L_6 ) ;
if ( F_77 ( V_26 , V_109 , & V_110 ) ) {
F_24 ( L_7 ) ;
goto V_141;
}
F_24 ( L_8 ,
V_109 , V_110 ) ;
V_137 = ( V_110 & V_142 ) >> 5 ;
V_138 = V_110 & V_143 ;
F_67 ( V_26 ,
V_26 -> V_111 + F_83 ( V_109 ) ,
& V_110 ) ;
F_24 ( L_9 , V_109 , V_110 ) ;
V_139 = ( V_110 & V_144 ) >> 24 ;
F_24 ( L_10 \
L_11 ,
V_109 , V_137 , V_138 , V_139 ) ;
if ( ( V_137 != ( ( V_110 & V_145 ) >> 8 ) ) ||
( V_137 != ( V_110 & V_146 ) ) ) {
F_69 ( V_26 ,
V_26 -> V_111 + F_83 ( V_109 ) ,
( V_139 << 24 ) |
( V_137 << 8 ) | V_137 ) ;
V_137 ++ ;
if ( V_136 )
F_69 ( V_136 ,
V_136 -> V_111 +
F_83 ( F_84 ( V_136 -> V_147 ) ) ,
( V_137 << 24 ) |
( V_139 << 8 ) | V_139 ) ;
else
F_24 ( L_12 ) ;
}
V_141:
F_67 ( V_26 ,
V_26 -> V_111 + F_82 ( V_109 ) ,
& V_135 ) ;
F_24 ( L_13 , V_109 , V_135 ) ;
}
if ( ( V_135 & V_148 ) && V_136 ) {
F_24 ( L_14 ) ;
F_77 ( V_136 ,
F_84 ( V_136 -> V_147 ) , NULL ) ;
F_79 ( 50 ) ;
F_67 ( V_26 ,
V_26 -> V_111 + F_82 ( V_109 ) ,
& V_135 ) ;
F_24 ( L_13 , V_109 , V_135 ) ;
}
return ( V_135 & ( V_140 |
V_148 ) ) ? 1 : 0 ;
}
int F_85 ( struct V_1 * V_12 , union V_71 * V_149 )
{
struct V_25 * V_26 ;
T_2 V_135 , V_150 , V_151 ;
int V_42 , V_152 ;
struct V_74 * V_75 ;
#ifdef F_86
{
T_2 V_127 ;
F_24 ( L_15 , V_36 , V_12 -> V_153 ) ;
for ( V_127 = 0 ; V_127 < V_154 / sizeof( T_2 ) ; V_127 = V_127 + 4 ) {
F_24 ( L_16 ,
V_127 * 4 , V_149 -> V_155 [ V_127 ] , V_149 -> V_155 [ V_127 + 1 ] ,
V_149 -> V_155 [ V_127 + 2 ] , V_149 -> V_155 [ V_127 + 3 ] ) ;
}
}
#endif
V_26 = F_64 ( ( V_149 -> V_156 . V_157 & V_158 ) , NULL ) ;
if ( V_26 ) {
F_24 ( L_17 , F_25 ( V_26 ) ) ;
} else {
F_24 ( L_18 ,
V_36 , V_149 -> V_156 . V_157 ) ;
}
if ( V_26 && V_26 -> F_49 ) {
V_42 = V_26 -> F_49 ( V_26 , V_149 , 0 ) ;
if ( V_42 == 0 )
return 0 ;
}
F_40 ( & V_12 -> V_63 ) ;
F_45 (pwrite, &mport->pwrites, node)
V_75 -> F_49 ( V_12 , V_75 -> V_70 , V_149 , 0 ) ;
F_41 ( & V_12 -> V_63 ) ;
if ( ! V_26 )
return 0 ;
V_152 = V_149 -> V_156 . V_159 & 0xFF ;
if ( F_76 ( V_26 ) ) {
F_24 ( L_19 ) ;
if ( F_73 ( V_26 , & V_26 , & V_152 ) ) {
F_87 ( L_20 ,
F_25 ( V_26 ) ) ;
return - V_114 ;
}
V_149 = NULL ;
}
if ( ! ( V_26 -> V_32 & V_33 ) )
return 0 ;
if ( V_26 -> V_111 == 0 ) {
F_87 ( L_21 ,
F_25 ( V_26 ) ) ;
return 0 ;
}
if ( V_26 -> V_34 -> V_8 && V_26 -> V_34 -> V_8 -> V_160 )
V_26 -> V_34 -> V_8 -> V_160 ( V_26 , V_152 ) ;
F_67 ( V_26 ,
V_26 -> V_111 + F_82 ( V_152 ) ,
& V_135 ) ;
F_24 ( L_22 , V_152 , V_135 ) ;
if ( V_135 & V_161 ) {
if ( ! ( V_26 -> V_34 -> V_162 & ( 1 << V_152 ) ) ) {
V_26 -> V_34 -> V_162 |= ( 1 << V_152 ) ;
F_66 ( V_26 , V_152 , 0 ) ;
F_24 ( L_23 ,
F_25 ( V_26 ) , V_152 ) ;
}
if ( V_135 & ( V_140 |
V_148 ) ) {
if ( F_81 ( V_26 , V_152 , V_135 ) )
F_81 ( V_26 , V_152 , 0 ) ;
}
} else {
if ( V_26 -> V_34 -> V_162 & ( 1 << V_152 ) ) {
V_26 -> V_34 -> V_162 &= ~ ( 1 << V_152 ) ;
F_66 ( V_26 , V_152 , 1 ) ;
F_69 ( V_26 ,
V_26 -> V_111 +
F_83 ( V_152 ) ,
V_163 ) ;
F_24 ( L_24 ,
F_25 ( V_26 ) , V_152 ) ;
}
}
F_67 ( V_26 ,
V_26 -> V_164 + F_88 ( V_152 ) , & V_150 ) ;
if ( V_150 ) {
F_24 ( L_25 ,
V_152 , V_150 ) ;
F_69 ( V_26 ,
V_26 -> V_164 + F_88 ( V_152 ) , 0 ) ;
}
F_67 ( V_26 ,
V_26 -> V_164 + V_165 , & V_151 ) ;
if ( V_151 ) {
F_24 ( L_26 ,
V_151 ) ;
F_69 ( V_26 ,
V_26 -> V_164 + V_165 , 0 ) ;
}
F_69 ( V_26 ,
V_26 -> V_111 + F_82 ( V_152 ) ,
V_135 ) ;
return 0 ;
}
T_2
F_61 ( struct V_1 * V_2 , int V_80 , T_1 V_89 ,
T_5 V_94 , T_2 V_105 )
{
T_2 V_166 ;
if ( V_105 == 0 ) {
if ( V_80 )
F_2 ( V_2 , V_167 ,
& V_166 ) ;
else
F_62 ( V_2 , V_89 , V_94 ,
V_167 , & V_166 ) ;
return V_166 & V_168 ;
} else {
if ( V_80 )
F_2 ( V_2 , V_105 , & V_166 ) ;
else
F_62 ( V_2 , V_89 , V_94 ,
V_105 , & V_166 ) ;
return F_63 ( V_166 ) ;
}
}
T_2
F_89 ( struct V_1 * V_2 , int V_80 , T_1 V_89 ,
T_5 V_94 , int V_169 )
{
T_2 V_170 , V_95 , V_96 ;
if ( V_80 )
F_2 ( V_2 , V_167 , & V_170 ) ;
else
F_62 ( V_2 , V_89 , V_94 ,
V_167 , & V_170 ) ;
V_95 = V_170 & V_168 ;
while ( V_95 ) {
if ( V_80 )
F_2 ( V_2 , V_95 ,
& V_96 ) ;
else
F_62 ( V_2 , V_89 , V_94 ,
V_95 , & V_96 ) ;
if ( F_63 ( V_96 ) == V_169 )
return V_95 ;
if ( ! ( V_95 = F_90 ( V_96 ) ) )
break;
}
return 0 ;
}
struct V_25 * F_91 ( T_1 V_171 , T_1 V_24 ,
T_1 V_172 , T_1 V_173 , struct V_25 * V_105 )
{
struct V_106 * V_107 ;
struct V_25 * V_26 ;
F_92 ( F_93 () ) ;
F_10 ( & V_21 ) ;
V_107 = V_105 ? V_105 -> V_29 . V_108 : V_30 . V_108 ;
while ( V_107 && ( V_107 != & V_30 ) ) {
V_26 = F_65 ( V_107 ) ;
if ( ( V_171 == V_174 || V_26 -> V_171 == V_171 ) &&
( V_24 == V_174 || V_26 -> V_24 == V_24 ) &&
( V_172 == V_174 || V_26 -> V_172 == V_172 ) &&
( V_173 == V_174 || V_26 -> V_173 == V_173 ) )
goto exit;
V_107 = V_107 -> V_108 ;
}
V_26 = NULL ;
exit:
F_94 ( V_105 ) ;
V_26 = F_95 ( V_26 ) ;
F_12 ( & V_21 ) ;
return V_26 ;
}
struct V_25 * F_96 ( T_1 V_171 , T_1 V_24 , struct V_25 * V_105 )
{
return F_91 ( V_171 , V_24 , V_174 , V_174 , V_105 ) ;
}
static int
F_97 ( struct V_1 * V_12 , T_1 V_89 , T_5 V_94 ,
T_1 V_175 , T_1 V_176 , T_5 V_177 )
{
if ( V_175 == V_178 ) {
F_72 ( V_12 , V_89 , V_94 ,
V_179 ,
( T_2 ) V_176 ) ;
F_72 ( V_12 , V_89 , V_94 ,
V_180 ,
( T_2 ) V_177 ) ;
}
F_79 ( 10 ) ;
return 0 ;
}
static int
F_98 ( struct V_1 * V_12 , T_1 V_89 , T_5 V_94 ,
T_1 V_175 , T_1 V_176 , T_5 * V_177 )
{
T_2 V_3 ;
if ( V_175 == V_178 ) {
F_72 ( V_12 , V_89 , V_94 ,
V_179 , V_176 ) ;
F_62 ( V_12 , V_89 , V_94 ,
V_180 , & V_3 ) ;
* V_177 = ( T_5 ) V_3 ;
}
return 0 ;
}
static int
F_99 ( struct V_1 * V_12 , T_1 V_89 , T_5 V_94 ,
T_1 V_175 )
{
T_2 V_181 = 0xff ;
T_2 V_127 , V_32 , V_182 = 1 , V_183 = 0 ;
T_2 V_184 = V_126 ;
if ( V_175 == V_178 ) {
F_62 ( V_12 , V_89 , V_94 ,
V_185 , & V_32 ) ;
if ( V_12 -> V_5 ) {
F_62 ( V_12 , V_89 , V_94 ,
V_186 ,
& V_181 ) ;
V_181 &= V_187 ;
}
if ( V_32 & V_188 ) {
V_183 = 0x80000000 ;
V_182 = 4 ;
V_184 = ( V_126 << 24 ) |
( V_126 << 16 ) |
( V_126 << 8 ) |
V_126 ;
}
for ( V_127 = 0 ; V_127 <= V_181 ; ) {
F_72 ( V_12 , V_89 , V_94 ,
V_179 ,
V_183 | V_127 ) ;
F_72 ( V_12 , V_89 , V_94 ,
V_180 ,
V_184 ) ;
V_127 += V_182 ;
}
}
F_79 ( 10 ) ;
return 0 ;
}
int F_100 ( struct V_1 * V_2 , T_1 V_89 ,
T_5 V_94 , int V_189 )
{
T_2 V_3 ;
int V_190 = 0 ;
F_72 ( V_2 , V_89 , V_94 ,
V_191 , V_2 -> V_192 ) ;
F_62 ( V_2 , V_89 , V_94 ,
V_191 , & V_3 ) ;
while ( V_3 != V_2 -> V_192 ) {
if ( V_189 != 0 && V_190 == V_189 ) {
F_24 ( L_27 ,
V_89 , V_94 ) ;
return - V_69 ;
}
F_75 ( 1 ) ;
V_190 ++ ;
F_72 ( V_2 , V_89 ,
V_94 ,
V_191 ,
V_2 -> V_192 ) ;
F_62 ( V_2 , V_89 ,
V_94 ,
V_191 , & V_3 ) ;
}
return 0 ;
}
int F_101 ( struct V_1 * V_2 , T_1 V_89 , T_5 V_94 )
{
T_2 V_3 ;
F_72 ( V_2 , V_89 ,
V_94 ,
V_191 ,
V_2 -> V_192 ) ;
F_62 ( V_2 , V_89 , V_94 ,
V_191 , & V_3 ) ;
if ( ( V_3 & 0xffff ) != 0xffff ) {
F_24 ( L_28 ,
V_89 , V_94 ) ;
return - V_69 ;
}
return 0 ;
}
int F_102 ( struct V_25 * V_26 ,
T_1 V_175 , T_1 V_176 , T_5 V_177 , int V_63 )
{
int V_42 = - V_69 ;
struct V_193 * V_8 = V_26 -> V_34 -> V_8 ;
if ( V_63 ) {
V_42 = F_100 ( V_26 -> V_13 -> V_130 , V_26 -> V_89 ,
V_26 -> V_94 , 1000 ) ;
if ( V_42 )
return V_42 ;
}
F_10 ( & V_26 -> V_34 -> V_63 ) ;
if ( V_8 == NULL || V_8 -> V_194 == NULL ) {
V_42 = F_97 ( V_26 -> V_13 -> V_130 , V_26 -> V_89 ,
V_26 -> V_94 , V_175 ,
V_176 , V_177 ) ;
} else if ( F_103 ( V_8 -> V_195 ) ) {
V_42 = V_8 -> V_194 ( V_26 -> V_13 -> V_130 , V_26 -> V_89 ,
V_26 -> V_94 , V_175 , V_176 ,
V_177 ) ;
F_104 ( V_8 -> V_195 ) ;
}
F_12 ( & V_26 -> V_34 -> V_63 ) ;
if ( V_63 )
F_101 ( V_26 -> V_13 -> V_130 , V_26 -> V_89 ,
V_26 -> V_94 ) ;
return V_42 ;
}
int F_105 ( struct V_25 * V_26 , T_1 V_175 ,
T_1 V_176 , T_5 * V_177 , int V_63 )
{
int V_42 = - V_69 ;
struct V_193 * V_8 = V_26 -> V_34 -> V_8 ;
if ( V_63 ) {
V_42 = F_100 ( V_26 -> V_13 -> V_130 , V_26 -> V_89 ,
V_26 -> V_94 , 1000 ) ;
if ( V_42 )
return V_42 ;
}
F_10 ( & V_26 -> V_34 -> V_63 ) ;
if ( V_8 == NULL || V_8 -> V_196 == NULL ) {
V_42 = F_98 ( V_26 -> V_13 -> V_130 , V_26 -> V_89 ,
V_26 -> V_94 , V_175 ,
V_176 , V_177 ) ;
} else if ( F_103 ( V_8 -> V_195 ) ) {
V_42 = V_8 -> V_196 ( V_26 -> V_13 -> V_130 , V_26 -> V_89 ,
V_26 -> V_94 , V_175 , V_176 ,
V_177 ) ;
F_104 ( V_8 -> V_195 ) ;
}
F_12 ( & V_26 -> V_34 -> V_63 ) ;
if ( V_63 )
F_101 ( V_26 -> V_13 -> V_130 , V_26 -> V_89 ,
V_26 -> V_94 ) ;
return V_42 ;
}
int F_106 ( struct V_25 * V_26 , T_1 V_175 , int V_63 )
{
int V_42 = - V_69 ;
struct V_193 * V_8 = V_26 -> V_34 -> V_8 ;
if ( V_63 ) {
V_42 = F_100 ( V_26 -> V_13 -> V_130 , V_26 -> V_89 ,
V_26 -> V_94 , 1000 ) ;
if ( V_42 )
return V_42 ;
}
F_10 ( & V_26 -> V_34 -> V_63 ) ;
if ( V_8 == NULL || V_8 -> V_197 == NULL ) {
V_42 = F_99 ( V_26 -> V_13 -> V_130 , V_26 -> V_89 ,
V_26 -> V_94 , V_175 ) ;
} else if ( F_103 ( V_8 -> V_195 ) ) {
V_42 = V_8 -> V_197 ( V_26 -> V_13 -> V_130 , V_26 -> V_89 ,
V_26 -> V_94 , V_175 ) ;
F_104 ( V_8 -> V_195 ) ;
}
F_12 ( & V_26 -> V_34 -> V_63 ) ;
if ( V_63 )
F_101 ( V_26 -> V_13 -> V_130 , V_26 -> V_89 ,
V_26 -> V_94 ) ;
return V_42 ;
}
static bool F_107 ( struct V_198 * V_199 , void * V_200 )
{
struct V_1 * V_12 = V_200 ;
return V_12 == F_108 ( V_199 -> V_201 , struct V_1 , V_202 ) ;
}
struct V_198 * F_109 ( struct V_1 * V_12 )
{
T_6 V_203 ;
F_110 ( V_203 ) ;
F_111 ( V_204 , V_203 ) ;
return F_112 ( V_203 , F_107 , V_12 ) ;
}
struct V_198 * F_113 ( struct V_25 * V_26 )
{
return F_109 ( V_26 -> V_13 -> V_130 ) ;
}
void F_114 ( struct V_198 * V_205 )
{
F_115 ( V_205 ) ;
}
struct V_206 * F_116 ( struct V_198 * V_205 ,
T_1 V_89 , struct V_207 * V_208 ,
enum V_209 V_210 , unsigned long V_84 )
{
struct V_211 V_212 ;
if ( V_205 -> V_201 -> V_213 == NULL ) {
F_87 ( L_29 , V_36 ) ;
return NULL ;
}
V_212 . V_89 = V_89 ;
V_212 . V_214 = V_208 -> V_214 ;
V_212 . V_215 = V_208 -> V_215 ;
V_212 . V_216 = V_208 -> V_216 ;
return F_117 ( V_205 , V_208 -> V_217 , V_208 -> V_218 ,
V_210 , V_84 , & V_212 ) ;
}
struct V_206 * F_118 ( struct V_25 * V_26 ,
struct V_198 * V_205 , struct V_207 * V_208 ,
enum V_209 V_210 , unsigned long V_84 )
{
return F_116 ( V_205 , V_26 -> V_89 , V_208 , V_210 , V_84 ) ;
}
struct V_1 * F_119 ( int V_219 )
{
struct V_1 * V_2 ;
F_40 ( & V_220 ) ;
F_45 (port, &rio_mports, node) {
if ( V_2 -> V_153 == V_219 )
goto V_68;
}
V_2 = NULL ;
V_68:
F_41 ( & V_220 ) ;
return V_2 ;
}
int F_120 ( int V_219 , struct V_221 * V_222 )
{
struct V_1 * V_2 ;
struct V_223 * V_224 ;
int V_42 = 0 ;
F_24 ( L_30 , V_36 , V_219 ) ;
if ( ( V_219 != V_225 && V_219 >= V_226 ) ||
! V_222 )
return - V_69 ;
F_40 ( & V_220 ) ;
F_45 (scan, &rio_scans, node) {
if ( V_224 -> V_219 == V_219 ) {
V_42 = - V_227 ;
goto V_125;
}
}
V_224 = F_6 ( sizeof( * V_224 ) , V_14 ) ;
if ( ! V_224 ) {
V_42 = - V_52 ;
goto V_125;
}
V_224 -> V_219 = V_219 ;
V_224 -> V_8 = V_222 ;
F_45 (port, &rio_mports, node) {
if ( V_2 -> V_153 == V_219 ) {
V_2 -> V_228 = V_222 ;
break;
} else if ( V_219 == V_225 && ! V_2 -> V_228 )
V_2 -> V_228 = V_222 ;
}
F_11 ( & V_224 -> V_15 , & V_229 ) ;
V_125:
F_41 ( & V_220 ) ;
return V_42 ;
}
int F_121 ( int V_219 , struct V_221 * V_222 )
{
struct V_1 * V_2 ;
struct V_223 * V_224 ;
F_24 ( L_30 , V_36 , V_219 ) ;
if ( V_219 != V_225 && V_219 >= V_226 )
return - V_69 ;
F_40 ( & V_220 ) ;
F_45 (port, &rio_mports, node)
if ( V_2 -> V_153 == V_219 ||
( V_219 == V_225 && V_2 -> V_228 == V_222 ) )
V_2 -> V_228 = NULL ;
F_45 (scan, &rio_scans, node) {
if ( V_224 -> V_219 == V_219 ) {
F_15 ( & V_224 -> V_15 ) ;
F_26 ( V_224 ) ;
break;
}
}
F_41 ( & V_220 ) ;
return 0 ;
}
int F_122 ( int V_219 )
{
struct V_1 * V_2 = NULL ;
int V_42 ;
F_40 ( & V_220 ) ;
F_45 (port, &rio_mports, node) {
if ( V_2 -> V_153 == V_219 )
goto V_68;
}
F_41 ( & V_220 ) ;
return - V_91 ;
V_68:
if ( ! V_2 -> V_228 ) {
F_41 ( & V_220 ) ;
return - V_69 ;
}
if ( ! F_103 ( V_2 -> V_228 -> V_195 ) ) {
F_41 ( & V_220 ) ;
return - V_91 ;
}
F_41 ( & V_220 ) ;
if ( V_2 -> V_192 >= 0 )
V_42 = V_2 -> V_228 -> V_230 ( V_2 , 0 ) ;
else
V_42 = V_2 -> V_228 -> V_231 ( V_2 , V_232 ) ;
F_104 ( V_2 -> V_228 -> V_195 ) ;
return V_42 ;
}
static void F_123 ( struct V_25 * V_20 )
{
}
static int F_124 ( void )
{
struct V_25 * V_20 = NULL ;
while ( ( V_20 = F_96 ( V_174 , V_174 , V_20 ) ) != NULL ) {
F_123 ( V_20 ) ;
}
return 0 ;
}
static void F_125 ( struct V_233 * V_234 )
{
struct V_235 * V_236 ;
V_236 = F_108 ( V_234 , struct V_235 , V_236 ) ;
F_24 ( L_31 ,
V_236 -> V_12 -> V_153 , V_236 -> V_12 -> V_237 ) ;
if ( F_103 ( V_236 -> V_12 -> V_228 -> V_195 ) ) {
V_236 -> V_12 -> V_228 -> V_231 ( V_236 -> V_12 , 0 ) ;
F_104 ( V_236 -> V_12 -> V_228 -> V_195 ) ;
}
}
int F_126 ( void )
{
struct V_1 * V_2 ;
struct V_235 * V_236 ;
int V_107 = 0 ;
if ( ! V_238 )
return - V_91 ;
F_40 ( & V_220 ) ;
F_45 (port, &rio_mports, node) {
if ( V_2 -> V_192 >= 0 ) {
if ( V_2 -> V_228 && F_103 ( V_2 -> V_228 -> V_195 ) ) {
V_2 -> V_228 -> V_230 ( V_2 , 0 ) ;
F_104 ( V_2 -> V_228 -> V_195 ) ;
}
} else
V_107 ++ ;
}
F_41 ( & V_220 ) ;
if ( ! V_107 )
goto V_239;
V_240 = F_127 ( L_32 , 0 , 0 ) ;
if ( ! V_240 ) {
F_87 ( L_33 ) ;
goto V_239;
}
V_236 = F_128 ( V_107 , sizeof *V_236 , V_14 ) ;
if ( ! V_236 ) {
F_87 ( L_34 ) ;
F_129 ( V_240 ) ;
goto V_239;
}
V_107 = 0 ;
F_40 ( & V_220 ) ;
F_45 (port, &rio_mports, node) {
if ( V_2 -> V_192 < 0 && V_2 -> V_228 ) {
V_236 [ V_107 ] . V_12 = V_2 ;
F_130 ( & V_236 [ V_107 ] . V_236 , F_125 ) ;
F_131 ( V_240 , & V_236 [ V_107 ] . V_236 ) ;
V_107 ++ ;
}
}
F_132 ( V_240 ) ;
F_41 ( & V_220 ) ;
F_24 ( L_35 ) ;
F_129 ( V_240 ) ;
F_26 ( V_236 ) ;
V_239:
F_124 () ;
return 0 ;
}
static int F_133 ( int V_241 )
{
if ( V_242 == 0 || V_242 <= V_241 || V_241 >= V_226 )
return - 1 ;
return V_243 [ V_241 ] ;
}
int F_134 ( struct V_1 * V_12 )
{
if ( V_238 >= V_226 ) {
F_87 ( L_36 ) ;
return - V_91 ;
}
F_21 ( & V_12 -> V_27 , V_244 ) ;
V_12 -> V_153 = V_238 ++ ;
V_12 -> V_192 = F_133 ( V_12 -> V_153 ) ;
V_12 -> V_228 = NULL ;
F_135 ( & V_12 -> V_63 ) ;
V_12 -> V_79 = 0 ;
F_7 ( & V_12 -> V_76 ) ;
return 0 ;
}
int F_136 ( struct V_1 * V_2 )
{
struct V_223 * V_224 = NULL ;
int V_45 = 0 ;
F_40 ( & V_220 ) ;
F_45 (scan, &rio_scans, node) {
if ( V_2 -> V_153 == V_224 -> V_219 ||
V_224 -> V_219 == V_225 ) {
V_2 -> V_228 = V_224 -> V_8 ;
if ( V_2 -> V_153 == V_224 -> V_219 )
break;
}
}
F_11 ( & V_2 -> V_15 , & V_245 ) ;
F_41 ( & V_220 ) ;
F_137 ( & V_2 -> V_20 , L_37 , V_2 -> V_153 ) ;
V_2 -> V_20 . V_246 = & V_247 ;
F_21 ( & V_2 -> V_27 , V_28 ) ;
V_45 = F_9 ( & V_2 -> V_20 ) ;
if ( V_45 )
F_138 ( & V_2 -> V_20 , L_38 ,
V_2 -> V_153 , V_45 ) ;
else
F_139 ( & V_2 -> V_20 , L_39 , V_2 -> V_153 ) ;
return V_45 ;
}
static int F_140 ( struct V_201 * V_20 , void * V_208 )
{
struct V_25 * V_26 = F_141 ( V_20 ) ;
if ( V_20 -> V_248 == & V_249 )
F_23 ( V_26 , V_250 ) ;
return 0 ;
}
static int F_142 ( struct V_11 * V_13 )
{
F_143 ( & V_13 -> V_20 , NULL , F_140 ) ;
return 0 ;
}
int F_144 ( struct V_1 * V_2 )
{
F_24 ( L_40 , V_36 , V_2 -> V_237 , V_2 -> V_153 ) ;
if ( F_145 ( & V_2 -> V_27 ,
V_28 ,
V_250 ) != V_28 ) {
F_87 ( L_41 ,
V_36 , V_2 -> V_237 ) ;
}
if ( V_2 -> V_13 && V_2 -> V_13 -> V_130 == V_2 ) {
F_142 ( V_2 -> V_13 ) ;
F_13 ( V_2 -> V_13 ) ;
}
F_40 ( & V_220 ) ;
F_15 ( & V_2 -> V_15 ) ;
F_41 ( & V_220 ) ;
F_16 ( & V_2 -> V_20 ) ;
return 0 ;
}
