T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 ;
F_2 ( V_2 , V_4 , & V_3 ) ;
return ( F_3 ( V_2 -> V_5 , V_3 ) ) ;
}
int F_4 ( struct V_1 * V_6 ,
void * V_7 ,
int V_8 ,
int V_9 ,
void (* F_5) ( struct V_1 * V_6 , void * V_7 , int V_8 ,
int V_10 ) )
{
int V_11 = - V_12 ;
struct V_13 * V_14 ;
if ( V_6 -> V_15 -> V_16 == NULL )
goto V_17;
V_14 = F_6 ( sizeof( struct V_13 ) , V_18 ) ;
if ( V_14 ) {
F_7 ( V_14 , V_8 , V_8 ) ;
if ( ( V_11 =
F_8 ( & V_6 -> V_19 [ V_20 ] ,
V_14 ) ) < 0 ) {
F_9 ( V_14 ) ;
goto V_17;
}
V_6 -> V_21 [ V_8 ] . V_14 = V_14 ;
V_6 -> V_21 [ V_8 ] . V_22 = F_5 ;
V_11 = V_6 -> V_15 -> V_16 ( V_6 , V_7 , V_8 , V_9 ) ;
} else
V_11 = - V_23 ;
V_17:
return V_11 ;
}
int F_10 ( struct V_1 * V_6 , int V_8 )
{
if ( V_6 -> V_15 -> V_24 ) {
V_6 -> V_15 -> V_24 ( V_6 , V_8 ) ;
return F_11 ( V_6 -> V_21 [ V_8 ] . V_14 ) ;
} else
return - V_12 ;
}
int F_12 ( struct V_1 * V_6 ,
void * V_7 ,
int V_8 ,
int V_9 ,
void (* F_13) ( struct V_1 * V_6 , void * V_7 , int V_8 , int V_10 ) )
{
int V_11 = - V_12 ;
struct V_13 * V_14 ;
if ( V_6 -> V_15 -> V_25 == NULL )
goto V_17;
V_14 = F_6 ( sizeof( struct V_13 ) , V_18 ) ;
if ( V_14 ) {
F_7 ( V_14 , V_8 , V_8 ) ;
if ( ( V_11 =
F_8 ( & V_6 -> V_19 [ V_26 ] ,
V_14 ) ) < 0 ) {
F_9 ( V_14 ) ;
goto V_17;
}
V_6 -> V_27 [ V_8 ] . V_14 = V_14 ;
V_6 -> V_27 [ V_8 ] . V_22 = F_13 ;
V_11 = V_6 -> V_15 -> V_25 ( V_6 , V_7 , V_8 , V_9 ) ;
} else
V_11 = - V_23 ;
V_17:
return V_11 ;
}
int F_14 ( struct V_1 * V_6 , int V_8 )
{
if ( V_6 -> V_15 -> V_28 ) {
V_6 -> V_15 -> V_28 ( V_6 , V_8 ) ;
return F_11 ( V_6 -> V_27 [ V_8 ] . V_14 ) ;
} else
return - V_12 ;
}
static int
F_15 ( struct V_1 * V_6 , void * V_7 , struct V_13 * V_14 ,
void (* F_16) ( struct V_1 * V_6 , void * V_7 , T_1 V_29 , T_1 V_30 ,
T_1 V_31 ) )
{
int V_11 = 0 ;
struct V_32 * V_33 ;
if ( ! ( V_33 = F_6 ( sizeof( struct V_32 ) , V_18 ) ) ) {
V_11 = - V_23 ;
goto V_17;
}
V_33 -> V_14 = V_14 ;
V_33 -> F_16 = F_16 ;
V_33 -> V_7 = V_7 ;
F_17 ( & V_33 -> V_34 , & V_6 -> V_35 ) ;
V_17:
return V_11 ;
}
int F_18 ( struct V_1 * V_6 ,
void * V_7 ,
T_1 V_36 ,
T_1 V_37 ,
void (* F_16) ( struct V_1 * V_6 , void * V_7 , T_1 V_29 ,
T_1 V_30 , T_1 V_31 ) )
{
int V_11 = 0 ;
struct V_13 * V_14 = F_6 ( sizeof( struct V_13 ) , V_18 ) ;
if ( V_14 ) {
F_19 ( V_14 , V_36 , V_37 ) ;
if ( ( V_11 =
F_8 ( & V_6 -> V_19 [ V_38 ] ,
V_14 ) ) < 0 ) {
F_9 ( V_14 ) ;
goto V_17;
}
V_11 = F_15 ( V_6 , V_7 , V_14 , F_16 ) ;
} else
V_11 = - V_23 ;
V_17:
return V_11 ;
}
int F_20 ( struct V_1 * V_6 , T_1 V_36 , T_1 V_37 )
{
int V_11 = 0 , V_39 = 0 ;
struct V_32 * V_33 ;
F_21 (dbell, &mport->dbells, node) {
if ( ( V_33 -> V_14 -> V_36 == V_36 ) && ( V_33 -> V_14 -> V_37 == V_37 ) ) {
V_39 = 1 ;
break;
}
}
if ( ! V_39 ) {
V_11 = - V_40 ;
goto V_17;
}
F_22 ( & V_33 -> V_34 ) ;
V_11 = F_11 ( V_33 -> V_14 ) ;
F_9 ( V_33 ) ;
V_17:
return V_11 ;
}
struct V_13 * F_23 ( struct V_41 * V_42 , T_1 V_36 ,
T_1 V_37 )
{
struct V_13 * V_14 = F_6 ( sizeof( struct V_13 ) , V_18 ) ;
if ( V_14 ) {
F_19 ( V_14 , V_36 , V_37 ) ;
if ( F_8 ( & V_42 -> V_19 [ V_38 ] , V_14 )
< 0 ) {
F_9 ( V_14 ) ;
V_14 = NULL ;
}
}
return V_14 ;
}
int F_24 ( struct V_41 * V_42 , struct V_13 * V_14 )
{
int V_11 = F_11 ( V_14 ) ;
F_9 ( V_14 ) ;
return V_11 ;
}
int F_25 ( struct V_41 * V_42 ,
int (* F_26)( struct V_41 * V_42 , union V_43 * V_44 , int V_45 ) )
{
int V_11 = 0 ;
F_27 ( & V_46 ) ;
if ( V_42 -> F_26 != NULL )
V_11 = - V_23 ;
else
V_42 -> F_26 = F_26 ;
F_28 ( & V_46 ) ;
return V_11 ;
}
int F_29 ( struct V_41 * V_42 )
{
int V_11 = - V_23 ;
F_27 ( & V_46 ) ;
if ( V_42 -> F_26 ) {
V_42 -> F_26 = NULL ;
V_11 = 0 ;
}
F_28 ( & V_46 ) ;
return V_11 ;
}
int F_30 ( struct V_1 * V_6 , T_3 V_47 ,
T_4 V_48 , T_2 V_49 , T_2 V_50 )
{
int V_11 = 0 ;
unsigned long V_51 ;
if ( ! V_6 -> V_15 -> V_52 )
return - 1 ;
F_31 ( & V_53 , V_51 ) ;
V_11 = V_6 -> V_15 -> V_52 ( V_6 , V_47 , V_48 , V_49 , V_50 ) ;
F_32 ( & V_53 , V_51 ) ;
return V_11 ;
}
void F_33 ( struct V_1 * V_6 , T_3 V_54 )
{
unsigned long V_51 ;
if ( ! V_6 -> V_15 -> V_55 )
return;
F_31 ( & V_53 , V_51 ) ;
V_6 -> V_15 -> V_55 ( V_6 , V_54 ) ;
F_32 ( & V_53 , V_51 ) ;
}
T_2
F_34 ( struct V_1 * V_2 , int V_47 ,
T_1 V_56 , T_5 V_57 )
{
T_2 V_58 ;
T_2 V_59 ;
V_58 = F_35 ( V_2 , V_47 , V_56 , V_57 , 0 ) ;
while ( V_58 ) {
if ( V_47 )
F_2 ( V_2 , V_58 ,
& V_59 ) ;
else
F_36 ( V_2 , V_56 , V_57 ,
V_58 , & V_59 ) ;
V_59 = F_37 ( V_59 ) ;
switch ( V_59 ) {
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
return V_58 ;
default:
break;
}
V_58 = F_35 ( V_2 , V_47 , V_56 ,
V_57 , V_58 ) ;
}
return V_58 ;
}
struct V_41 * F_38 ( T_2 V_67 , struct V_41 * V_68 )
{
struct V_69 * V_70 ;
struct V_41 * V_42 ;
F_27 ( & V_46 ) ;
V_70 = V_68 ? V_68 -> V_71 . V_72 : V_73 . V_72 ;
while ( V_70 && ( V_70 != & V_73 ) ) {
V_42 = F_39 ( V_70 ) ;
if ( V_42 -> V_67 == V_67 )
goto exit;
V_70 = V_70 -> V_72 ;
}
V_42 = NULL ;
exit:
F_28 ( & V_46 ) ;
return V_42 ;
}
int F_40 ( struct V_41 * V_42 , T_2 V_74 , int V_75 )
{
T_2 V_76 ;
F_41 ( V_42 ,
V_42 -> V_77 + F_42 ( V_74 ) ,
& V_76 ) ;
if ( V_75 )
V_76 |= V_78 ;
else
V_76 &= ~ V_78 ;
F_43 ( V_42 ,
V_42 -> V_77 + F_42 ( V_74 ) ,
V_76 ) ;
return 0 ;
}
static int
F_44 ( struct V_41 * V_42 , struct V_41 * * V_79 , int * V_80 )
{
T_2 V_3 ;
int V_81 , V_11 = - V_82 ;
struct V_41 * V_83 = NULL ;
while ( V_42 -> V_83 && ( V_42 -> V_83 -> V_84 & V_85 ) ) {
if ( ! F_41 ( V_42 -> V_83 , V_86 , & V_3 ) ) {
V_83 = V_42 -> V_83 ;
break;
}
V_42 = V_42 -> V_83 ;
}
if ( V_83 == NULL )
goto V_87;
V_81 = V_83 -> V_88 -> V_89 [ V_42 -> V_56 ] ;
if ( V_81 != V_90 ) {
F_45 ( L_1 ,
F_46 ( V_83 ) , V_81 ) ;
* V_79 = V_83 ;
* V_80 = V_81 ;
V_11 = 0 ;
} else
F_45 ( L_2 , F_46 ( V_42 ) ) ;
V_87:
return V_11 ;
}
int
F_47 ( struct V_1 * V_6 , T_1 V_56 , T_5 V_57 )
{
int V_91 = 0 ;
T_2 V_92 ;
while ( F_36 ( V_6 , V_56 , V_57 ,
V_86 , & V_92 ) ) {
V_91 ++ ;
if ( V_91 == V_93 )
return - V_82 ;
F_48 ( 1 ) ;
}
return 0 ;
}
static int F_49 ( struct V_41 * V_42 )
{
return F_47 ( V_42 -> V_94 -> V_95 ,
V_42 -> V_56 , V_42 -> V_57 ) ;
}
static int
F_50 ( struct V_41 * V_42 , int V_74 , T_2 * V_96 )
{
T_2 V_76 ;
int V_97 ;
if ( V_96 ) {
F_41 ( V_42 ,
V_42 -> V_77 + F_51 ( V_74 ) ,
& V_76 ) ;
F_52 ( 50 ) ;
}
F_43 ( V_42 ,
V_42 -> V_77 + F_53 ( V_74 ) ,
V_98 ) ;
if ( V_96 == NULL )
return 0 ;
V_97 = 3 ;
while ( V_97 -- ) {
F_52 ( 50 ) ;
F_41 ( V_42 ,
V_42 -> V_77 + F_51 ( V_74 ) ,
& V_76 ) ;
if ( V_76 & V_99 ) {
* V_96 = V_76 ;
return 0 ;
}
}
return - V_82 ;
}
static int F_54 ( struct V_41 * V_42 , T_2 V_74 , T_2 V_100 )
{
struct V_41 * V_101 = V_42 -> V_88 -> V_101 [ V_74 ] ;
T_2 V_76 ;
T_2 V_102 , V_103 , V_104 ;
if ( V_100 == 0 )
F_41 ( V_42 ,
V_42 -> V_77 + F_55 ( V_74 ) ,
& V_100 ) ;
if ( V_100 & V_105 ) {
F_45 ( L_3 ) ;
if ( F_50 ( V_42 , V_74 , & V_76 ) ) {
F_45 ( L_4 ) ;
goto V_106;
}
F_45 ( L_5 ,
V_74 , V_76 ) ;
V_102 = ( V_76 & V_107 ) >> 5 ;
V_103 = V_76 & V_108 ;
F_41 ( V_42 ,
V_42 -> V_77 + F_56 ( V_74 ) ,
& V_76 ) ;
F_45 ( L_6 , V_74 , V_76 ) ;
V_104 = ( V_76 & V_109 ) >> 24 ;
F_45 ( L_7 \
L_8 ,
V_74 , V_102 , V_103 , V_104 ) ;
if ( ( V_102 != ( ( V_76 & V_110 ) >> 8 ) ) ||
( V_102 != ( V_76 & V_111 ) ) ) {
F_43 ( V_42 ,
V_42 -> V_77 + F_56 ( V_74 ) ,
( V_104 << 24 ) |
( V_102 << 8 ) | V_102 ) ;
V_102 ++ ;
if ( V_101 )
F_43 ( V_101 ,
V_101 -> V_77 +
F_56 ( F_57 ( V_101 -> V_112 ) ) ,
( V_102 << 24 ) |
( V_104 << 8 ) | V_104 ) ;
else
F_45 ( L_9 ) ;
}
V_106:
F_41 ( V_42 ,
V_42 -> V_77 + F_55 ( V_74 ) ,
& V_100 ) ;
F_45 ( L_10 , V_74 , V_100 ) ;
}
if ( ( V_100 & V_113 ) && V_101 ) {
F_45 ( L_11 ) ;
F_50 ( V_101 ,
F_57 ( V_101 -> V_112 ) , NULL ) ;
F_52 ( 50 ) ;
F_41 ( V_42 ,
V_42 -> V_77 + F_55 ( V_74 ) ,
& V_100 ) ;
F_45 ( L_10 , V_74 , V_100 ) ;
}
return ( V_100 & ( V_105 |
V_113 ) ) ? 1 : 0 ;
}
int F_58 ( union V_43 * V_114 )
{
struct V_41 * V_42 ;
T_2 V_100 , V_115 , V_116 ;
int V_11 , V_117 ;
V_42 = F_38 ( ( V_114 -> V_118 . V_119 & V_120 ) , NULL ) ;
if ( V_42 == NULL ) {
F_45 ( L_12 ,
V_121 , V_114 -> V_118 . V_119 ) ;
return - V_82 ;
}
F_45 ( L_13 , F_46 ( V_42 ) ) ;
#ifdef F_59
{
T_2 V_91 ;
for ( V_91 = 0 ; V_91 < V_122 / sizeof( T_2 ) ; ) {
F_45 ( L_14 ,
V_91 * 4 , V_114 -> V_123 [ V_91 ] , V_114 -> V_123 [ V_91 + 1 ] ,
V_114 -> V_123 [ V_91 + 2 ] , V_114 -> V_123 [ V_91 + 3 ] ) ;
V_91 += 4 ;
}
}
#endif
if ( V_42 -> F_26 != NULL ) {
V_11 = V_42 -> F_26 ( V_42 , V_114 , 0 ) ;
if ( V_11 == 0 )
return 0 ;
}
V_117 = V_114 -> V_118 . V_124 & 0xFF ;
if ( F_49 ( V_42 ) ) {
F_45 ( L_15 ) ;
if ( F_44 ( V_42 , & V_42 , & V_117 ) ) {
F_60 ( L_16 ,
F_46 ( V_42 ) ) ;
return - V_82 ;
}
V_114 = NULL ;
}
if ( ! ( V_42 -> V_84 & V_85 ) )
return 0 ;
if ( V_42 -> V_77 == 0 ) {
F_60 ( L_17 ,
F_46 ( V_42 ) ) ;
return 0 ;
}
if ( V_42 -> V_88 -> V_125 )
V_42 -> V_88 -> V_125 ( V_42 , V_117 ) ;
F_41 ( V_42 ,
V_42 -> V_77 + F_55 ( V_117 ) ,
& V_100 ) ;
F_45 ( L_18 , V_117 , V_100 ) ;
if ( V_100 & V_126 ) {
if ( ! ( V_42 -> V_88 -> V_127 & ( 1 << V_117 ) ) ) {
V_42 -> V_88 -> V_127 |= ( 1 << V_117 ) ;
F_40 ( V_42 , V_117 , 0 ) ;
F_45 ( L_19 ,
F_46 ( V_42 ) , V_117 ) ;
}
if ( V_100 & ( V_105 |
V_113 ) ) {
if ( F_54 ( V_42 , V_117 , V_100 ) )
F_54 ( V_42 , V_117 , 0 ) ;
}
} else {
if ( V_42 -> V_88 -> V_127 & ( 1 << V_117 ) ) {
V_42 -> V_88 -> V_127 &= ~ ( 1 << V_117 ) ;
F_40 ( V_42 , V_117 , 1 ) ;
F_43 ( V_42 ,
V_42 -> V_77 +
F_56 ( V_117 ) ,
V_128 ) ;
F_45 ( L_20 ,
F_46 ( V_42 ) , V_117 ) ;
}
}
F_41 ( V_42 ,
V_42 -> V_129 + F_61 ( V_117 ) , & V_115 ) ;
if ( V_115 ) {
F_45 ( L_21 ,
V_117 , V_115 ) ;
F_43 ( V_42 ,
V_42 -> V_129 + F_61 ( V_117 ) , 0 ) ;
}
F_41 ( V_42 ,
V_42 -> V_129 + V_130 , & V_116 ) ;
if ( V_116 ) {
F_45 ( L_22 ,
V_116 ) ;
F_43 ( V_42 ,
V_42 -> V_129 + V_130 , 0 ) ;
}
F_43 ( V_42 ,
V_42 -> V_77 + F_55 ( V_117 ) ,
V_100 ) ;
return 0 ;
}
T_2
F_35 ( struct V_1 * V_2 , int V_47 , T_1 V_56 ,
T_5 V_57 , T_2 V_68 )
{
T_2 V_131 ;
if ( V_68 == 0 ) {
if ( V_47 )
F_2 ( V_2 , V_132 ,
& V_131 ) ;
else
F_36 ( V_2 , V_56 , V_57 ,
V_132 , & V_131 ) ;
return V_131 & V_133 ;
} else {
if ( V_47 )
F_2 ( V_2 , V_68 , & V_131 ) ;
else
F_36 ( V_2 , V_56 , V_57 ,
V_68 , & V_131 ) ;
return F_37 ( V_131 ) ;
}
}
T_2
F_62 ( struct V_1 * V_2 , int V_47 , T_1 V_56 ,
T_5 V_57 , int V_134 )
{
T_2 V_135 , V_58 , V_59 ;
if ( V_47 )
F_2 ( V_2 , V_132 , & V_135 ) ;
else
F_36 ( V_2 , V_56 , V_57 ,
V_132 , & V_135 ) ;
V_58 = V_135 & V_133 ;
while ( V_58 ) {
if ( V_47 )
F_2 ( V_2 , V_58 ,
& V_59 ) ;
else
F_36 ( V_2 , V_56 , V_57 ,
V_58 , & V_59 ) ;
if ( F_37 ( V_59 ) == V_134 )
return V_58 ;
if ( ! ( V_58 = F_63 ( V_59 ) ) )
break;
}
return 0 ;
}
struct V_41 * F_64 ( T_1 V_136 , T_1 V_137 ,
T_1 V_138 , T_1 V_139 , struct V_41 * V_68 )
{
struct V_69 * V_70 ;
struct V_41 * V_42 ;
F_65 ( F_66 () ) ;
F_27 ( & V_46 ) ;
V_70 = V_68 ? V_68 -> V_71 . V_72 : V_73 . V_72 ;
while ( V_70 && ( V_70 != & V_73 ) ) {
V_42 = F_39 ( V_70 ) ;
if ( ( V_136 == V_140 || V_42 -> V_136 == V_136 ) &&
( V_137 == V_140 || V_42 -> V_137 == V_137 ) &&
( V_138 == V_140 || V_42 -> V_138 == V_138 ) &&
( V_139 == V_140 || V_42 -> V_139 == V_139 ) )
goto exit;
V_70 = V_70 -> V_72 ;
}
V_42 = NULL ;
exit:
F_67 ( V_68 ) ;
V_42 = F_68 ( V_42 ) ;
F_28 ( & V_46 ) ;
return V_42 ;
}
struct V_41 * F_69 ( T_1 V_136 , T_1 V_137 , struct V_41 * V_68 )
{
return F_64 ( V_136 , V_137 , V_140 , V_140 , V_68 ) ;
}
int F_70 ( struct V_1 * V_6 , T_1 V_56 , T_5 V_57 ,
T_1 V_141 , T_1 V_142 , T_5 V_143 )
{
if ( V_141 == V_144 ) {
F_71 ( V_6 , V_56 , V_57 ,
V_145 ,
( T_2 ) V_142 ) ;
F_71 ( V_6 , V_56 , V_57 ,
V_146 ,
( T_2 ) V_143 ) ;
}
F_52 ( 10 ) ;
return 0 ;
}
int F_72 ( struct V_1 * V_6 , T_1 V_56 , T_5 V_57 ,
T_1 V_141 , T_1 V_142 , T_5 * V_143 )
{
T_2 V_3 ;
if ( V_141 == V_144 ) {
F_71 ( V_6 , V_56 , V_57 ,
V_145 , V_142 ) ;
F_36 ( V_6 , V_56 , V_57 ,
V_146 , & V_3 ) ;
* V_143 = ( T_5 ) V_3 ;
}
return 0 ;
}
int F_73 ( struct V_1 * V_6 , T_1 V_56 , T_5 V_57 ,
T_1 V_141 )
{
T_2 V_147 = 0xff ;
T_2 V_91 , V_84 , V_148 = 1 , V_149 = 0 ;
T_2 V_150 = V_90 ;
if ( V_141 == V_144 ) {
F_36 ( V_6 , V_56 , V_57 ,
V_151 , & V_84 ) ;
if ( V_6 -> V_5 ) {
F_36 ( V_6 , V_56 , V_57 ,
V_152 ,
& V_147 ) ;
V_147 &= V_153 ;
}
if ( V_84 & V_154 ) {
V_149 = 0x80000000 ;
V_148 = 4 ;
V_150 = ( V_90 << 24 ) |
( V_90 << 16 ) |
( V_90 << 8 ) |
V_90 ;
}
for ( V_91 = 0 ; V_91 <= V_147 ; ) {
F_71 ( V_6 , V_56 , V_57 ,
V_145 ,
V_149 | V_91 ) ;
F_71 ( V_6 , V_56 , V_57 ,
V_146 ,
V_150 ) ;
V_91 += V_148 ;
}
}
F_52 ( 10 ) ;
return 0 ;
}
static bool F_74 ( struct V_155 * V_156 , void * V_157 )
{
struct V_41 * V_42 = V_157 ;
return ( V_42 -> V_94 -> V_95 ==
F_75 ( V_156 -> V_158 , struct V_1 , V_159 ) ) ;
}
struct V_155 * F_76 ( struct V_41 * V_42 )
{
T_6 V_160 ;
struct V_155 * V_161 ;
F_77 ( V_160 ) ;
F_78 ( V_162 , V_160 ) ;
V_161 = F_79 ( V_160 , F_74 , V_42 ) ;
return V_161 ;
}
void F_80 ( struct V_155 * V_161 )
{
F_81 ( V_161 ) ;
}
struct V_163 * F_82 ( struct V_41 * V_42 ,
struct V_155 * V_161 , struct V_164 * V_165 ,
enum V_166 V_167 , unsigned long V_51 )
{
struct V_163 * V_168 = NULL ;
struct V_169 V_170 ;
if ( V_161 -> V_158 -> V_171 == NULL ) {
F_60 ( L_23 , V_121 ) ;
return NULL ;
}
V_170 . V_56 = V_42 -> V_56 ;
V_170 . V_172 = V_165 -> V_172 ;
V_170 . V_173 = V_165 -> V_173 ;
V_170 . V_174 = V_165 -> V_174 ;
V_168 = F_83 ( V_161 , V_165 -> V_175 , V_165 -> V_176 ,
V_167 , V_51 , & V_170 ) ;
return V_168 ;
}
static void F_84 ( struct V_41 * V_177 )
{
}
static int T_7 F_85 ( void )
{
struct V_41 * V_177 = NULL ;
while ( ( V_177 = F_69 ( V_140 , V_140 , V_177 ) ) != NULL ) {
F_84 ( V_177 ) ;
}
return 0 ;
}
static void T_7 F_86 ( struct V_178 * V_179 )
{
struct V_180 * V_181 ;
V_181 = F_75 ( V_179 , struct V_180 , V_181 ) ;
F_45 ( L_24 ,
V_181 -> V_6 -> V_182 , V_181 -> V_6 -> V_183 ) ;
F_87 ( V_181 -> V_6 ) ;
}
int T_7 F_88 ( void )
{
struct V_1 * V_2 ;
struct V_180 * V_181 ;
int V_70 = 0 ;
if ( ! V_184 )
return - V_185 ;
F_21 (port, &rio_mports, node) {
if ( V_2 -> V_186 >= 0 )
F_89 ( V_2 ) ;
else
V_70 ++ ;
}
if ( ! V_70 )
goto V_187;
V_188 = F_90 ( L_25 , 0 , 0 ) ;
if ( ! V_188 ) {
F_60 ( L_26 ) ;
goto V_187;
}
V_181 = F_91 ( V_70 , sizeof *V_181 , V_18 ) ;
if ( ! V_181 ) {
F_60 ( L_27 ) ;
F_92 ( V_188 ) ;
goto V_187;
}
V_70 = 0 ;
F_21 (port, &rio_mports, node) {
if ( V_2 -> V_186 < 0 ) {
V_181 [ V_70 ] . V_6 = V_2 ;
F_93 ( & V_181 [ V_70 ] . V_181 , F_86 ) ;
F_94 ( V_188 , & V_181 [ V_70 ] . V_181 ) ;
V_70 ++ ;
}
}
F_95 ( V_188 ) ;
F_45 ( L_28 ) ;
F_92 ( V_188 ) ;
F_9 ( V_181 ) ;
V_187:
F_85 () ;
return 0 ;
}
static int F_96 ( int V_189 )
{
if ( ! V_190 [ 0 ] || V_190 [ 0 ] <= V_189 || V_189 >= V_191 )
return - 1 ;
return V_190 [ V_189 + 1 ] ;
}
static int F_97 ( char * V_192 )
{
( void ) F_98 ( V_192 , F_99 ( V_190 ) , V_190 ) ;
return 1 ;
}
int F_100 ( struct V_1 * V_2 )
{
if ( V_184 >= V_191 ) {
F_60 ( L_29 ) ;
return 1 ;
}
V_2 -> V_182 = V_184 ++ ;
V_2 -> V_186 = F_96 ( V_2 -> V_182 ) ;
F_17 ( & V_2 -> V_34 , & V_193 ) ;
return 0 ;
}
