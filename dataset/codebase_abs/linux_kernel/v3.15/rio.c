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
int F_47 ( struct V_1 * V_2 ,
int V_51 , T_1 V_60 ,
T_5 V_61 , T_5 V_81 )
{
#ifdef F_48
T_2 V_78 ;
T_2 V_62 ;
F_49 ( L_1
L_2 , V_51 , V_60 , V_61 , V_81 ) ;
V_62 = F_37 ( V_2 , V_51 , V_60 , V_61 ) ;
if ( V_51 ) {
F_2 ( V_2 , V_62 +
F_45 ( 0 ) ,
& V_78 ) ;
} else {
if ( F_39 ( V_2 , V_60 , V_61 ,
V_62 + F_45 ( V_81 ) , & V_78 ) < 0 )
return - V_82 ;
}
if ( V_78 & V_83 ) {
V_78 = V_78 | V_84
| V_85 ;
} else {
V_78 = V_78 | V_86
| V_87 ;
}
if ( V_51 ) {
F_50 ( V_2 , V_62 +
F_45 ( 0 ) , V_78 ) ;
} else {
if ( F_51 ( V_2 , V_60 , V_61 ,
V_62 + F_45 ( V_81 ) , V_78 ) < 0 )
return - V_82 ;
}
#endif
return 0 ;
}
static int
F_52 ( struct V_6 * V_7 , struct V_6 * * V_88 , int * V_89 )
{
T_2 V_3 ;
int V_90 , V_18 = - V_82 ;
struct V_6 * V_91 = NULL ;
while ( V_7 -> V_91 && ( V_7 -> V_91 -> V_92 & V_93 ) ) {
if ( ! F_44 ( V_7 -> V_91 , V_94 , & V_3 ) ) {
V_91 = V_7 -> V_91 ;
break;
}
V_7 = V_7 -> V_91 ;
}
if ( V_91 == NULL )
goto V_95;
V_90 = V_91 -> V_96 -> V_97 [ V_7 -> V_60 ] ;
if ( V_90 != V_98 ) {
F_49 ( L_3 ,
F_53 ( V_91 ) , V_90 ) ;
* V_88 = V_91 ;
* V_89 = V_90 ;
V_18 = 0 ;
} else
F_49 ( L_4 , F_53 ( V_7 ) ) ;
V_95:
return V_18 ;
}
int
F_54 ( struct V_1 * V_13 , T_1 V_60 , T_5 V_61 )
{
int V_99 = 0 ;
T_2 V_100 ;
while ( F_39 ( V_13 , V_60 , V_61 ,
V_94 , & V_100 ) ) {
V_99 ++ ;
if ( V_99 == V_101 )
return - V_82 ;
F_55 ( 1 ) ;
}
return 0 ;
}
static int F_56 ( struct V_6 * V_7 )
{
return F_54 ( V_7 -> V_102 -> V_103 ,
V_7 -> V_60 , V_7 -> V_61 ) ;
}
static int
F_57 ( struct V_6 * V_7 , int V_76 , T_2 * V_104 )
{
T_2 V_78 ;
int V_105 ;
if ( V_104 ) {
F_44 ( V_7 ,
V_7 -> V_79 + F_58 ( V_76 ) ,
& V_78 ) ;
F_59 ( 50 ) ;
}
F_46 ( V_7 ,
V_7 -> V_79 + F_60 ( V_76 ) ,
V_106 ) ;
if ( V_104 == NULL )
return 0 ;
V_105 = 3 ;
while ( V_105 -- ) {
F_59 ( 50 ) ;
F_44 ( V_7 ,
V_7 -> V_79 + F_58 ( V_76 ) ,
& V_78 ) ;
if ( V_78 & V_107 ) {
* V_104 = V_78 ;
return 0 ;
}
}
return - V_82 ;
}
static int F_61 ( struct V_6 * V_7 , T_2 V_76 , T_2 V_108 )
{
struct V_6 * V_109 = V_7 -> V_96 -> V_109 [ V_76 ] ;
T_2 V_78 ;
T_2 V_110 , V_111 , V_112 ;
if ( V_108 == 0 )
F_44 ( V_7 ,
V_7 -> V_79 + F_62 ( V_76 ) ,
& V_108 ) ;
if ( V_108 & V_113 ) {
F_49 ( L_5 ) ;
if ( F_57 ( V_7 , V_76 , & V_78 ) ) {
F_49 ( L_6 ) ;
goto V_114;
}
F_49 ( L_7 ,
V_76 , V_78 ) ;
V_110 = ( V_78 & V_115 ) >> 5 ;
V_111 = V_78 & V_116 ;
F_44 ( V_7 ,
V_7 -> V_79 + F_63 ( V_76 ) ,
& V_78 ) ;
F_49 ( L_8 , V_76 , V_78 ) ;
V_112 = ( V_78 & V_117 ) >> 24 ;
F_49 ( L_9 \
L_10 ,
V_76 , V_110 , V_111 , V_112 ) ;
if ( ( V_110 != ( ( V_78 & V_118 ) >> 8 ) ) ||
( V_110 != ( V_78 & V_119 ) ) ) {
F_46 ( V_7 ,
V_7 -> V_79 + F_63 ( V_76 ) ,
( V_112 << 24 ) |
( V_110 << 8 ) | V_110 ) ;
V_110 ++ ;
if ( V_109 )
F_46 ( V_109 ,
V_109 -> V_79 +
F_63 ( F_64 ( V_109 -> V_120 ) ) ,
( V_110 << 24 ) |
( V_112 << 8 ) | V_112 ) ;
else
F_49 ( L_11 ) ;
}
V_114:
F_44 ( V_7 ,
V_7 -> V_79 + F_62 ( V_76 ) ,
& V_108 ) ;
F_49 ( L_12 , V_76 , V_108 ) ;
}
if ( ( V_108 & V_121 ) && V_109 ) {
F_49 ( L_13 ) ;
F_57 ( V_109 ,
F_64 ( V_109 -> V_120 ) , NULL ) ;
F_59 ( 50 ) ;
F_44 ( V_7 ,
V_7 -> V_79 + F_62 ( V_76 ) ,
& V_108 ) ;
F_49 ( L_12 , V_76 , V_108 ) ;
}
return ( V_108 & ( V_113 |
V_121 ) ) ? 1 : 0 ;
}
int F_65 ( union V_48 * V_122 )
{
struct V_6 * V_7 ;
T_2 V_108 , V_123 , V_124 ;
int V_18 , V_125 ;
V_7 = F_41 ( ( V_122 -> V_126 . V_127 & V_128 ) , NULL ) ;
if ( V_7 == NULL ) {
F_49 ( L_14 ,
V_129 , V_122 -> V_126 . V_127 ) ;
return - V_82 ;
}
F_49 ( L_15 , F_53 ( V_7 ) ) ;
#ifdef F_66
{
T_2 V_99 ;
for ( V_99 = 0 ; V_99 < V_130 / sizeof( T_2 ) ; ) {
F_49 ( L_16 ,
V_99 * 4 , V_122 -> V_131 [ V_99 ] , V_122 -> V_131 [ V_99 + 1 ] ,
V_122 -> V_131 [ V_99 + 2 ] , V_122 -> V_131 [ V_99 + 3 ] ) ;
V_99 += 4 ;
}
}
#endif
if ( V_7 -> F_31 != NULL ) {
V_18 = V_7 -> F_31 ( V_7 , V_122 , 0 ) ;
if ( V_18 == 0 )
return 0 ;
}
V_125 = V_122 -> V_126 . V_132 & 0xFF ;
if ( F_56 ( V_7 ) ) {
F_49 ( L_17 ) ;
if ( F_52 ( V_7 , & V_7 , & V_125 ) ) {
F_67 ( L_18 ,
F_53 ( V_7 ) ) ;
return - V_82 ;
}
V_122 = NULL ;
}
if ( ! ( V_7 -> V_92 & V_93 ) )
return 0 ;
if ( V_7 -> V_79 == 0 ) {
F_67 ( L_19 ,
F_53 ( V_7 ) ) ;
return 0 ;
}
if ( V_7 -> V_96 -> V_22 && V_7 -> V_96 -> V_22 -> V_133 )
V_7 -> V_96 -> V_22 -> V_133 ( V_7 , V_125 ) ;
F_44 ( V_7 ,
V_7 -> V_79 + F_62 ( V_125 ) ,
& V_108 ) ;
F_49 ( L_20 , V_125 , V_108 ) ;
if ( V_108 & V_134 ) {
if ( ! ( V_7 -> V_96 -> V_135 & ( 1 << V_125 ) ) ) {
V_7 -> V_96 -> V_135 |= ( 1 << V_125 ) ;
F_43 ( V_7 , V_125 , 0 ) ;
F_49 ( L_21 ,
F_53 ( V_7 ) , V_125 ) ;
}
if ( V_108 & ( V_113 |
V_121 ) ) {
if ( F_61 ( V_7 , V_125 , V_108 ) )
F_61 ( V_7 , V_125 , 0 ) ;
}
} else {
if ( V_7 -> V_96 -> V_135 & ( 1 << V_125 ) ) {
V_7 -> V_96 -> V_135 &= ~ ( 1 << V_125 ) ;
F_43 ( V_7 , V_125 , 1 ) ;
F_46 ( V_7 ,
V_7 -> V_79 +
F_63 ( V_125 ) ,
V_136 ) ;
F_49 ( L_22 ,
F_53 ( V_7 ) , V_125 ) ;
}
}
F_44 ( V_7 ,
V_7 -> V_137 + F_68 ( V_125 ) , & V_123 ) ;
if ( V_123 ) {
F_49 ( L_23 ,
V_125 , V_123 ) ;
F_46 ( V_7 ,
V_7 -> V_137 + F_68 ( V_125 ) , 0 ) ;
}
F_44 ( V_7 ,
V_7 -> V_137 + V_138 , & V_124 ) ;
if ( V_124 ) {
F_49 ( L_24 ,
V_124 ) ;
F_46 ( V_7 ,
V_7 -> V_137 + V_138 , 0 ) ;
}
F_46 ( V_7 ,
V_7 -> V_79 + F_62 ( V_125 ) ,
V_108 ) ;
return 0 ;
}
T_2
F_38 ( struct V_1 * V_2 , int V_51 , T_1 V_60 ,
T_5 V_61 , T_2 V_72 )
{
T_2 V_139 ;
if ( V_72 == 0 ) {
if ( V_51 )
F_2 ( V_2 , V_140 ,
& V_139 ) ;
else
F_39 ( V_2 , V_60 , V_61 ,
V_140 , & V_139 ) ;
return V_139 & V_141 ;
} else {
if ( V_51 )
F_2 ( V_2 , V_72 , & V_139 ) ;
else
F_39 ( V_2 , V_60 , V_61 ,
V_72 , & V_139 ) ;
return F_40 ( V_139 ) ;
}
}
T_2
F_69 ( struct V_1 * V_2 , int V_51 , T_1 V_60 ,
T_5 V_61 , int V_142 )
{
T_2 V_143 , V_62 , V_63 ;
if ( V_51 )
F_2 ( V_2 , V_140 , & V_143 ) ;
else
F_39 ( V_2 , V_60 , V_61 ,
V_140 , & V_143 ) ;
V_62 = V_143 & V_141 ;
while ( V_62 ) {
if ( V_51 )
F_2 ( V_2 , V_62 ,
& V_63 ) ;
else
F_39 ( V_2 , V_60 , V_61 ,
V_62 , & V_63 ) ;
if ( F_40 ( V_63 ) == V_142 )
return V_62 ;
if ( ! ( V_62 = F_70 ( V_63 ) ) )
break;
}
return 0 ;
}
struct V_6 * F_71 ( T_1 V_144 , T_1 V_145 ,
T_1 V_146 , T_1 V_147 , struct V_6 * V_72 )
{
struct V_73 * V_74 ;
struct V_6 * V_7 ;
F_72 ( F_73 () ) ;
F_6 ( & V_10 ) ;
V_74 = V_72 ? V_72 -> V_11 . V_75 : V_12 . V_75 ;
while ( V_74 && ( V_74 != & V_12 ) ) {
V_7 = F_42 ( V_74 ) ;
if ( ( V_144 == V_148 || V_7 -> V_144 == V_144 ) &&
( V_145 == V_148 || V_7 -> V_145 == V_145 ) &&
( V_146 == V_148 || V_7 -> V_146 == V_146 ) &&
( V_147 == V_148 || V_7 -> V_147 == V_147 ) )
goto exit;
V_74 = V_74 -> V_75 ;
}
V_7 = NULL ;
exit:
F_74 ( V_72 ) ;
V_7 = F_75 ( V_7 ) ;
F_8 ( & V_10 ) ;
return V_7 ;
}
struct V_6 * F_76 ( T_1 V_144 , T_1 V_145 , struct V_6 * V_72 )
{
return F_71 ( V_144 , V_145 , V_148 , V_148 , V_72 ) ;
}
static int
F_77 ( struct V_1 * V_13 , T_1 V_60 , T_5 V_61 ,
T_1 V_149 , T_1 V_150 , T_5 V_151 )
{
if ( V_149 == V_152 ) {
F_51 ( V_13 , V_60 , V_61 ,
V_153 ,
( T_2 ) V_150 ) ;
F_51 ( V_13 , V_60 , V_61 ,
V_154 ,
( T_2 ) V_151 ) ;
}
F_59 ( 10 ) ;
return 0 ;
}
static int
F_78 ( struct V_1 * V_13 , T_1 V_60 , T_5 V_61 ,
T_1 V_149 , T_1 V_150 , T_5 * V_151 )
{
T_2 V_3 ;
if ( V_149 == V_152 ) {
F_51 ( V_13 , V_60 , V_61 ,
V_153 , V_150 ) ;
F_39 ( V_13 , V_60 , V_61 ,
V_154 , & V_3 ) ;
* V_151 = ( T_5 ) V_3 ;
}
return 0 ;
}
static int
F_79 ( struct V_1 * V_13 , T_1 V_60 , T_5 V_61 ,
T_1 V_149 )
{
T_2 V_155 = 0xff ;
T_2 V_99 , V_92 , V_156 = 1 , V_157 = 0 ;
T_2 V_158 = V_98 ;
if ( V_149 == V_152 ) {
F_39 ( V_13 , V_60 , V_61 ,
V_159 , & V_92 ) ;
if ( V_13 -> V_5 ) {
F_39 ( V_13 , V_60 , V_61 ,
V_160 ,
& V_155 ) ;
V_155 &= V_161 ;
}
if ( V_92 & V_162 ) {
V_157 = 0x80000000 ;
V_156 = 4 ;
V_158 = ( V_98 << 24 ) |
( V_98 << 16 ) |
( V_98 << 8 ) |
V_98 ;
}
for ( V_99 = 0 ; V_99 <= V_155 ; ) {
F_51 ( V_13 , V_60 , V_61 ,
V_153 ,
V_157 | V_99 ) ;
F_51 ( V_13 , V_60 , V_61 ,
V_154 ,
V_158 ) ;
V_99 += V_156 ;
}
}
F_59 ( 10 ) ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 , T_1 V_60 ,
T_5 V_61 , int V_163 )
{
T_2 V_3 ;
int V_164 = 0 ;
F_51 ( V_2 , V_60 , V_61 ,
V_165 , V_2 -> V_166 ) ;
F_39 ( V_2 , V_60 , V_61 ,
V_165 , & V_3 ) ;
while ( V_3 != V_2 -> V_166 ) {
if ( V_163 != 0 && V_164 == V_163 ) {
F_49 ( L_25 ,
V_60 , V_61 ) ;
return - V_47 ;
}
F_55 ( 1 ) ;
V_164 ++ ;
F_51 ( V_2 , V_60 ,
V_61 ,
V_165 ,
V_2 -> V_166 ) ;
F_39 ( V_2 , V_60 ,
V_61 ,
V_165 , & V_3 ) ;
}
return 0 ;
}
int F_81 ( struct V_1 * V_2 , T_1 V_60 , T_5 V_61 )
{
T_2 V_3 ;
F_51 ( V_2 , V_60 ,
V_61 ,
V_165 ,
V_2 -> V_166 ) ;
F_39 ( V_2 , V_60 , V_61 ,
V_165 , & V_3 ) ;
if ( ( V_3 & 0xffff ) != 0xffff ) {
F_49 ( L_26 ,
V_60 , V_61 ) ;
return - V_47 ;
}
return 0 ;
}
int F_82 ( struct V_6 * V_7 ,
T_1 V_149 , T_1 V_150 , T_5 V_151 , int V_77 )
{
int V_18 = - V_47 ;
struct V_167 * V_22 = V_7 -> V_96 -> V_22 ;
if ( V_77 ) {
V_18 = F_80 ( V_7 -> V_102 -> V_103 , V_7 -> V_60 ,
V_7 -> V_61 , 1000 ) ;
if ( V_18 )
return V_18 ;
}
F_6 ( & V_7 -> V_96 -> V_77 ) ;
if ( V_22 == NULL || V_22 -> V_168 == NULL ) {
V_18 = F_77 ( V_7 -> V_102 -> V_103 , V_7 -> V_60 ,
V_7 -> V_61 , V_149 ,
V_150 , V_151 ) ;
} else if ( F_83 ( V_22 -> V_169 ) ) {
V_18 = V_22 -> V_168 ( V_7 -> V_102 -> V_103 , V_7 -> V_60 ,
V_7 -> V_61 , V_149 , V_150 ,
V_151 ) ;
F_84 ( V_22 -> V_169 ) ;
}
F_8 ( & V_7 -> V_96 -> V_77 ) ;
if ( V_77 )
F_81 ( V_7 -> V_102 -> V_103 , V_7 -> V_60 ,
V_7 -> V_61 ) ;
return V_18 ;
}
int F_85 ( struct V_6 * V_7 , T_1 V_149 ,
T_1 V_150 , T_5 * V_151 , int V_77 )
{
int V_18 = - V_47 ;
struct V_167 * V_22 = V_7 -> V_96 -> V_22 ;
if ( V_77 ) {
V_18 = F_80 ( V_7 -> V_102 -> V_103 , V_7 -> V_60 ,
V_7 -> V_61 , 1000 ) ;
if ( V_18 )
return V_18 ;
}
F_6 ( & V_7 -> V_96 -> V_77 ) ;
if ( V_22 == NULL || V_22 -> V_170 == NULL ) {
V_18 = F_78 ( V_7 -> V_102 -> V_103 , V_7 -> V_60 ,
V_7 -> V_61 , V_149 ,
V_150 , V_151 ) ;
} else if ( F_83 ( V_22 -> V_169 ) ) {
V_18 = V_22 -> V_170 ( V_7 -> V_102 -> V_103 , V_7 -> V_60 ,
V_7 -> V_61 , V_149 , V_150 ,
V_151 ) ;
F_84 ( V_22 -> V_169 ) ;
}
F_8 ( & V_7 -> V_96 -> V_77 ) ;
if ( V_77 )
F_81 ( V_7 -> V_102 -> V_103 , V_7 -> V_60 ,
V_7 -> V_61 ) ;
return V_18 ;
}
int F_86 ( struct V_6 * V_7 , T_1 V_149 , int V_77 )
{
int V_18 = - V_47 ;
struct V_167 * V_22 = V_7 -> V_96 -> V_22 ;
if ( V_77 ) {
V_18 = F_80 ( V_7 -> V_102 -> V_103 , V_7 -> V_60 ,
V_7 -> V_61 , 1000 ) ;
if ( V_18 )
return V_18 ;
}
F_6 ( & V_7 -> V_96 -> V_77 ) ;
if ( V_22 == NULL || V_22 -> V_171 == NULL ) {
V_18 = F_79 ( V_7 -> V_102 -> V_103 , V_7 -> V_60 ,
V_7 -> V_61 , V_149 ) ;
} else if ( F_83 ( V_22 -> V_169 ) ) {
V_18 = V_22 -> V_171 ( V_7 -> V_102 -> V_103 , V_7 -> V_60 ,
V_7 -> V_61 , V_149 ) ;
F_84 ( V_22 -> V_169 ) ;
}
F_8 ( & V_7 -> V_96 -> V_77 ) ;
if ( V_77 )
F_81 ( V_7 -> V_102 -> V_103 , V_7 -> V_60 ,
V_7 -> V_61 ) ;
return V_18 ;
}
static bool F_87 ( struct V_172 * V_173 , void * V_174 )
{
struct V_6 * V_7 = V_174 ;
return ( V_7 -> V_102 -> V_103 ==
F_88 ( V_173 -> V_175 , struct V_1 , V_176 ) ) ;
}
struct V_172 * F_89 ( struct V_6 * V_7 )
{
T_6 V_177 ;
struct V_172 * V_178 ;
F_90 ( V_177 ) ;
F_91 ( V_179 , V_177 ) ;
V_178 = F_92 ( V_177 , F_87 , V_7 ) ;
return V_178 ;
}
void F_93 ( struct V_172 * V_178 )
{
F_94 ( V_178 ) ;
}
struct V_180 * F_95 ( struct V_6 * V_7 ,
struct V_172 * V_178 , struct V_181 * V_182 ,
enum V_183 V_184 , unsigned long V_55 )
{
struct V_180 * V_185 = NULL ;
struct V_186 V_187 ;
if ( V_178 -> V_175 -> V_188 == NULL ) {
F_67 ( L_27 , V_129 ) ;
return NULL ;
}
V_187 . V_60 = V_7 -> V_60 ;
V_187 . V_189 = V_182 -> V_189 ;
V_187 . V_190 = V_182 -> V_190 ;
V_187 . V_191 = V_182 -> V_191 ;
V_185 = F_96 ( V_178 , V_182 -> V_192 , V_182 -> V_193 ,
V_184 , V_55 , & V_187 ) ;
return V_185 ;
}
struct V_1 * F_97 ( int V_194 )
{
struct V_1 * V_2 ;
F_98 ( & V_195 ) ;
F_26 (port, &rio_mports, node) {
if ( V_2 -> V_196 == V_194 )
goto V_46;
}
V_2 = NULL ;
V_46:
F_99 ( & V_195 ) ;
return V_2 ;
}
int F_100 ( int V_194 , struct V_197 * V_198 )
{
struct V_1 * V_2 ;
struct V_199 * V_200 ;
int V_18 = 0 ;
F_49 ( L_28 , V_129 , V_194 ) ;
if ( ( V_194 != V_201 && V_194 >= V_202 ) ||
! V_198 )
return - V_47 ;
F_98 ( & V_195 ) ;
F_26 (scan, &rio_scans, node) {
if ( V_200 -> V_194 == V_194 ) {
V_18 = - V_203 ;
goto V_95;
}
}
V_200 = F_101 ( sizeof( * V_200 ) , V_25 ) ;
if ( ! V_200 ) {
V_18 = - V_30 ;
goto V_95;
}
V_200 -> V_194 = V_194 ;
V_200 -> V_22 = V_198 ;
F_26 (port, &rio_mports, node) {
if ( V_2 -> V_196 == V_194 ) {
V_2 -> V_204 = V_198 ;
break;
} else if ( V_194 == V_201 && ! V_2 -> V_204 )
V_2 -> V_204 = V_198 ;
}
F_7 ( & V_200 -> V_41 , & V_205 ) ;
V_95:
F_99 ( & V_195 ) ;
return V_18 ;
}
int F_102 ( int V_194 , struct V_197 * V_198 )
{
struct V_1 * V_2 ;
struct V_199 * V_200 ;
F_49 ( L_28 , V_129 , V_194 ) ;
if ( V_194 != V_201 && V_194 >= V_202 )
return - V_47 ;
F_98 ( & V_195 ) ;
F_26 (port, &rio_mports, node)
if ( V_2 -> V_196 == V_194 ||
( V_194 == V_201 && V_2 -> V_204 == V_198 ) )
V_2 -> V_204 = NULL ;
F_26 (scan, &rio_scans, node) {
if ( V_200 -> V_194 == V_194 ) {
F_27 ( & V_200 -> V_41 ) ;
F_15 ( V_200 ) ;
break;
}
}
F_99 ( & V_195 ) ;
return 0 ;
}
int F_103 ( int V_194 )
{
struct V_1 * V_2 = NULL ;
int V_18 ;
F_98 ( & V_195 ) ;
F_26 (port, &rio_mports, node) {
if ( V_2 -> V_196 == V_194 )
goto V_46;
}
F_99 ( & V_195 ) ;
return - V_206 ;
V_46:
if ( ! V_2 -> V_204 ) {
F_99 ( & V_195 ) ;
return - V_47 ;
}
if ( ! F_83 ( V_2 -> V_204 -> V_169 ) ) {
F_99 ( & V_195 ) ;
return - V_206 ;
}
F_99 ( & V_195 ) ;
if ( V_2 -> V_166 >= 0 )
V_18 = V_2 -> V_204 -> V_207 ( V_2 , 0 ) ;
else
V_18 = V_2 -> V_204 -> V_208 ( V_2 , V_209 ) ;
F_84 ( V_2 -> V_204 -> V_169 ) ;
return V_18 ;
}
static void F_104 ( struct V_6 * V_9 )
{
}
static int F_105 ( void )
{
struct V_6 * V_9 = NULL ;
while ( ( V_9 = F_76 ( V_148 , V_148 , V_9 ) ) != NULL ) {
F_104 ( V_9 ) ;
}
return 0 ;
}
static void F_106 ( struct V_210 * V_211 )
{
struct V_212 * V_213 ;
V_213 = F_88 ( V_211 , struct V_212 , V_213 ) ;
F_49 ( L_29 ,
V_213 -> V_13 -> V_196 , V_213 -> V_13 -> V_214 ) ;
if ( F_83 ( V_213 -> V_13 -> V_204 -> V_169 ) ) {
V_213 -> V_13 -> V_204 -> V_208 ( V_213 -> V_13 , 0 ) ;
F_84 ( V_213 -> V_13 -> V_204 -> V_169 ) ;
}
}
int F_107 ( void )
{
struct V_1 * V_2 ;
struct V_212 * V_213 ;
int V_74 = 0 ;
if ( ! V_215 )
return - V_206 ;
F_98 ( & V_195 ) ;
F_26 (port, &rio_mports, node) {
if ( V_2 -> V_166 >= 0 ) {
if ( V_2 -> V_204 && F_83 ( V_2 -> V_204 -> V_169 ) ) {
V_2 -> V_204 -> V_207 ( V_2 , 0 ) ;
F_84 ( V_2 -> V_204 -> V_169 ) ;
}
} else
V_74 ++ ;
}
F_99 ( & V_195 ) ;
if ( ! V_74 )
goto V_216;
V_217 = F_108 ( L_30 , 0 , 0 ) ;
if ( ! V_217 ) {
F_67 ( L_31 ) ;
goto V_216;
}
V_213 = F_109 ( V_74 , sizeof *V_213 , V_25 ) ;
if ( ! V_213 ) {
F_67 ( L_32 ) ;
F_110 ( V_217 ) ;
goto V_216;
}
V_74 = 0 ;
F_98 ( & V_195 ) ;
F_26 (port, &rio_mports, node) {
if ( V_2 -> V_166 < 0 && V_2 -> V_204 ) {
V_213 [ V_74 ] . V_13 = V_2 ;
F_111 ( & V_213 [ V_74 ] . V_213 , F_106 ) ;
F_112 ( V_217 , & V_213 [ V_74 ] . V_213 ) ;
V_74 ++ ;
}
}
F_113 ( V_217 ) ;
F_99 ( & V_195 ) ;
F_49 ( L_33 ) ;
F_110 ( V_217 ) ;
F_15 ( V_213 ) ;
V_216:
F_105 () ;
return 0 ;
}
static int F_114 ( int V_218 )
{
if ( V_219 == 0 || V_219 <= V_218 || V_218 >= V_202 )
return - 1 ;
return V_220 [ V_218 ] ;
}
int F_115 ( struct V_1 * V_2 )
{
struct V_199 * V_200 = NULL ;
int V_21 = 0 ;
if ( V_215 >= V_202 ) {
F_67 ( L_34 ) ;
return 1 ;
}
V_2 -> V_196 = V_215 ++ ;
V_2 -> V_166 = F_114 ( V_2 -> V_196 ) ;
V_2 -> V_204 = NULL ;
F_116 ( & V_2 -> V_9 , L_35 , V_2 -> V_196 ) ;
V_2 -> V_9 . V_221 = & V_222 ;
V_21 = F_117 ( & V_2 -> V_9 ) ;
if ( V_21 )
F_118 ( & V_2 -> V_9 , L_36 ,
V_2 -> V_196 , V_21 ) ;
else
F_119 ( & V_2 -> V_9 , L_37 , V_2 -> V_196 ) ;
F_98 ( & V_195 ) ;
F_7 ( & V_2 -> V_41 , & V_223 ) ;
F_26 (scan, &rio_scans, node) {
if ( V_2 -> V_196 == V_200 -> V_194 ||
V_200 -> V_194 == V_201 ) {
V_2 -> V_204 = V_200 -> V_22 ;
if ( V_2 -> V_196 == V_200 -> V_194 )
break;
}
}
F_99 ( & V_195 ) ;
F_49 ( L_38 , V_129 , V_2 -> V_214 , V_2 -> V_196 ) ;
return 0 ;
}
