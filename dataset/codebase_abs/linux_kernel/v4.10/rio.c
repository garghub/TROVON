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
if ( V_42 ) {
V_12 -> V_50 [ V_39 ] . V_51 = NULL ;
V_12 -> V_50 [ V_39 ] . V_45 = NULL ;
F_32 ( V_45 ) ;
F_26 ( V_45 ) ;
}
} else
V_42 = - V_52 ;
V_47:
return V_42 ;
}
int F_33 ( struct V_1 * V_12 , int V_39 )
{
int V_42 ;
if ( ! V_12 -> V_8 -> V_53 || ! V_12 -> V_50 [ V_39 ] . V_45 )
return - V_54 ;
V_12 -> V_8 -> V_53 ( V_12 , V_39 ) ;
V_12 -> V_50 [ V_39 ] . V_51 = NULL ;
V_42 = F_32 ( V_12 -> V_50 [ V_39 ] . V_45 ) ;
if ( V_42 )
return V_42 ;
F_26 ( V_12 -> V_50 [ V_39 ] . V_45 ) ;
V_12 -> V_50 [ V_39 ] . V_45 = NULL ;
return 0 ;
}
int F_34 ( struct V_1 * V_12 ,
void * V_38 ,
int V_39 ,
int V_40 ,
void (* F_35) ( struct V_1 * V_12 , void * V_38 , int V_39 , int V_41 ) )
{
int V_42 = - V_43 ;
struct V_44 * V_45 ;
if ( V_12 -> V_8 -> V_55 == NULL )
goto V_47;
V_45 = F_6 ( sizeof( struct V_44 ) , V_14 ) ;
if ( V_45 ) {
F_30 ( V_45 , V_39 , V_39 ) ;
if ( ( V_42 =
F_31 ( & V_12 -> V_48 [ V_56 ] ,
V_45 ) ) < 0 ) {
F_26 ( V_45 ) ;
goto V_47;
}
V_12 -> V_57 [ V_39 ] . V_45 = V_45 ;
V_12 -> V_57 [ V_39 ] . V_51 = F_35 ;
V_42 = V_12 -> V_8 -> V_55 ( V_12 , V_38 , V_39 , V_40 ) ;
if ( V_42 ) {
V_12 -> V_57 [ V_39 ] . V_51 = NULL ;
V_12 -> V_57 [ V_39 ] . V_45 = NULL ;
F_32 ( V_45 ) ;
F_26 ( V_45 ) ;
}
} else
V_42 = - V_52 ;
V_47:
return V_42 ;
}
int F_36 ( struct V_1 * V_12 , int V_39 )
{
int V_42 ;
if ( ! V_12 -> V_8 -> V_58 || ! V_12 -> V_57 [ V_39 ] . V_45 )
return - V_54 ;
V_12 -> V_8 -> V_58 ( V_12 , V_39 ) ;
V_12 -> V_57 [ V_39 ] . V_51 = NULL ;
V_42 = F_32 ( V_12 -> V_57 [ V_39 ] . V_45 ) ;
if ( V_42 )
return V_42 ;
F_26 ( V_12 -> V_57 [ V_39 ] . V_45 ) ;
V_12 -> V_57 [ V_39 ] . V_45 = NULL ;
return 0 ;
}
static int
F_37 ( struct V_1 * V_12 , void * V_38 , struct V_44 * V_45 ,
void (* F_38) ( struct V_1 * V_12 , void * V_38 , T_1 V_59 , T_1 V_60 ,
T_1 V_61 ) )
{
int V_42 = 0 ;
struct V_62 * V_63 ;
if ( ! ( V_63 = F_39 ( sizeof( struct V_62 ) , V_14 ) ) ) {
V_42 = - V_52 ;
goto V_47;
}
V_63 -> V_45 = V_45 ;
V_63 -> F_38 = F_38 ;
V_63 -> V_38 = V_38 ;
F_40 ( & V_12 -> V_64 ) ;
F_11 ( & V_63 -> V_15 , & V_12 -> V_65 ) ;
F_41 ( & V_12 -> V_64 ) ;
V_47:
return V_42 ;
}
int F_42 ( struct V_1 * V_12 ,
void * V_38 ,
T_1 V_66 ,
T_1 V_67 ,
void (* F_38) ( struct V_1 * V_12 , void * V_38 , T_1 V_59 ,
T_1 V_60 , T_1 V_61 ) )
{
int V_42 = 0 ;
struct V_44 * V_45 = F_6 ( sizeof( struct V_44 ) , V_14 ) ;
if ( V_45 ) {
F_43 ( V_45 , V_66 , V_67 ) ;
if ( ( V_42 =
F_31 ( & V_12 -> V_48 [ V_68 ] ,
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
int F_44 ( struct V_1 * V_12 , T_1 V_66 , T_1 V_67 )
{
int V_42 = 0 , V_69 = 0 ;
struct V_62 * V_63 ;
F_40 ( & V_12 -> V_64 ) ;
F_45 (dbell, &mport->dbells, node) {
if ( ( V_63 -> V_45 -> V_66 == V_66 ) && ( V_63 -> V_45 -> V_67 == V_67 ) ) {
F_15 ( & V_63 -> V_15 ) ;
V_69 = 1 ;
break;
}
}
F_41 ( & V_12 -> V_64 ) ;
if ( ! V_69 ) {
V_42 = - V_54 ;
goto V_47;
}
V_42 = F_32 ( V_63 -> V_45 ) ;
F_26 ( V_63 ) ;
V_47:
return V_42 ;
}
struct V_44 * F_46 ( struct V_25 * V_26 , T_1 V_66 ,
T_1 V_67 )
{
struct V_44 * V_45 = F_6 ( sizeof( struct V_44 ) , V_14 ) ;
if ( V_45 ) {
F_43 ( V_45 , V_66 , V_67 ) ;
if ( F_31 ( & V_26 -> V_48 [ V_68 ] , V_45 )
< 0 ) {
F_26 ( V_45 ) ;
V_45 = NULL ;
}
}
return V_45 ;
}
int F_47 ( struct V_25 * V_26 , struct V_44 * V_45 )
{
int V_42 = F_32 ( V_45 ) ;
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
F_40 ( & V_12 -> V_64 ) ;
F_11 ( & V_75 -> V_15 , & V_12 -> V_76 ) ;
F_41 ( & V_12 -> V_64 ) ;
V_47:
return V_42 ;
}
int F_50 ( struct V_1 * V_12 , void * V_70 ,
int (* F_49)( struct V_1 * V_12 ,
void * V_70 , union V_71 * V_72 , int V_73 ) )
{
int V_42 = - V_54 ;
struct V_74 * V_75 ;
F_40 ( & V_12 -> V_64 ) ;
F_45 (pwrite, &mport->pwrites, node) {
if ( V_75 -> F_49 == F_49 && V_75 -> V_70 == V_70 ) {
F_15 ( & V_75 -> V_15 ) ;
F_26 ( V_75 ) ;
V_42 = 0 ;
break;
}
}
F_41 ( & V_12 -> V_64 ) ;
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
F_40 ( & V_12 -> V_64 ) ;
if ( ( V_77 && ++ V_12 -> V_79 == 1 ) ||
( ! V_77 && V_12 -> V_79 && -- V_12 -> V_79 == 0 ) )
V_12 -> V_8 -> V_78 ( V_12 , V_77 ) ;
F_41 ( & V_12 -> V_64 ) ;
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
T_1 V_89 , T_5 V_94 , T_2 * V_95 )
{
T_2 V_96 ;
T_2 V_97 ;
V_96 = F_61 ( V_2 , V_80 , V_89 , V_94 , 0 ) ;
while ( V_96 ) {
if ( V_80 )
F_2 ( V_2 , V_96 ,
& V_97 ) ;
else
F_62 ( V_2 , V_89 , V_94 ,
V_96 , & V_97 ) ;
V_97 = F_63 ( V_97 ) ;
switch ( V_97 ) {
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
* V_95 = 1 ;
return V_96 ;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
* V_95 = 2 ;
return V_96 ;
default:
break;
}
V_96 = F_61 ( V_2 , V_80 , V_89 ,
V_94 , V_96 ) ;
}
return V_96 ;
}
struct V_25 * F_64 ( T_2 V_109 , struct V_25 * V_110 )
{
struct V_111 * V_112 ;
struct V_25 * V_26 ;
F_10 ( & V_21 ) ;
V_112 = V_110 ? V_110 -> V_29 . V_113 : V_30 . V_113 ;
while ( V_112 && ( V_112 != & V_30 ) ) {
V_26 = F_65 ( V_112 ) ;
if ( V_26 -> V_109 == V_109 )
goto exit;
V_112 = V_112 -> V_113 ;
}
V_26 = NULL ;
exit:
F_12 ( & V_21 ) ;
return V_26 ;
}
int F_66 ( struct V_25 * V_26 , T_2 V_114 , int V_64 )
{
T_2 V_115 ;
F_67 ( V_26 ,
F_68 ( V_26 , V_114 ) ,
& V_115 ) ;
if ( V_64 )
V_115 |= V_116 ;
else
V_115 &= ~ V_116 ;
F_69 ( V_26 ,
F_68 ( V_26 , V_114 ) ,
V_115 ) ;
return 0 ;
}
int F_70 ( struct V_1 * V_2 ,
int V_80 , T_1 V_89 ,
T_5 V_94 , T_5 V_117 )
{
#ifdef F_71
T_2 V_115 ;
T_2 V_96 ;
T_2 V_95 ;
F_24 ( L_2
L_3 , V_80 , V_89 , V_94 , V_117 ) ;
V_96 = F_60 ( V_2 , V_80 , V_89 ,
V_94 , & V_95 ) ;
if ( V_80 ) {
F_2 ( V_2 ,
V_96 + F_72 ( 0 , V_95 ) ,
& V_115 ) ;
} else {
if ( F_62 ( V_2 , V_89 , V_94 ,
V_96 + F_72 ( V_117 , V_95 ) ,
& V_115 ) < 0 )
return - V_118 ;
}
V_115 = V_115 | V_119 | V_120 ;
if ( V_80 ) {
F_18 ( V_2 ,
V_96 + F_72 ( 0 , V_95 ) , V_115 ) ;
} else {
if ( F_73 ( V_2 , V_89 , V_94 ,
V_96 + F_72 ( V_117 , V_95 ) ,
V_115 ) < 0 )
return - V_118 ;
}
#endif
return 0 ;
}
static int
F_74 ( struct V_25 * V_26 , struct V_25 * * V_121 , int * V_122 )
{
T_2 V_3 ;
int V_123 , V_42 = - V_118 ;
struct V_25 * V_124 = NULL ;
while ( V_26 -> V_124 && ( V_26 -> V_124 -> V_32 & V_33 ) ) {
if ( ! F_67 ( V_26 -> V_124 , V_125 , & V_3 ) ) {
V_124 = V_26 -> V_124 ;
break;
}
V_26 = V_26 -> V_124 ;
}
if ( V_124 == NULL )
goto V_126;
V_123 = V_124 -> V_34 -> V_37 [ V_26 -> V_89 ] ;
if ( V_123 != V_127 ) {
F_24 ( L_4 ,
F_25 ( V_124 ) , V_123 ) ;
* V_121 = V_124 ;
* V_122 = V_123 ;
V_42 = 0 ;
} else
F_24 ( L_5 , F_25 ( V_26 ) ) ;
V_126:
return V_42 ;
}
int
F_75 ( struct V_1 * V_12 , T_1 V_89 , T_5 V_94 )
{
int V_128 = 0 ;
T_2 V_129 ;
while ( F_62 ( V_12 , V_89 , V_94 ,
V_125 , & V_129 ) ) {
V_128 ++ ;
if ( V_128 == V_130 )
return - V_118 ;
F_76 ( 1 ) ;
}
return 0 ;
}
static int F_77 ( struct V_25 * V_26 )
{
return F_75 ( V_26 -> V_13 -> V_131 ,
V_26 -> V_89 , V_26 -> V_94 ) ;
}
static int
F_78 ( struct V_25 * V_26 , int V_114 , T_2 * V_132 )
{
T_2 V_115 ;
int V_133 ;
if ( V_132 ) {
F_67 ( V_26 ,
F_79 ( V_26 , V_114 ) ,
& V_115 ) ;
F_80 ( 50 ) ;
}
F_69 ( V_26 ,
F_81 ( V_26 , V_114 ) ,
V_134 ) ;
if ( V_132 == NULL )
return 0 ;
V_133 = 3 ;
while ( V_133 -- ) {
F_80 ( 50 ) ;
F_67 ( V_26 ,
F_79 ( V_26 , V_114 ) ,
& V_115 ) ;
if ( V_115 & V_135 ) {
* V_132 = V_115 ;
return 0 ;
}
}
return - V_118 ;
}
static int F_82 ( struct V_25 * V_26 , T_2 V_114 , T_2 V_136 )
{
struct V_25 * V_137 = V_26 -> V_34 -> V_137 [ V_114 ] ;
T_2 V_115 ;
T_2 V_138 , V_139 , V_140 ;
if ( V_136 == 0 )
F_67 ( V_26 ,
F_83 ( V_26 , V_114 ) ,
& V_136 ) ;
if ( V_136 & V_141 ) {
F_24 ( L_6 ) ;
if ( F_78 ( V_26 , V_114 , & V_115 ) ) {
F_24 ( L_7 ) ;
goto V_142;
}
F_24 ( L_8 ,
V_114 , V_115 ) ;
V_138 = ( V_115 & V_143 ) >> 5 ;
V_139 = V_115 & V_144 ;
F_67 ( V_26 ,
F_84 ( V_26 , V_114 ) ,
& V_115 ) ;
F_24 ( L_9 , V_114 , V_115 ) ;
V_140 = ( V_115 & V_145 ) >> 24 ;
F_24 ( L_10 \
L_11 ,
V_114 , V_138 , V_139 , V_140 ) ;
if ( ( V_138 != ( ( V_115 & V_146 ) >> 8 ) ) ||
( V_138 != ( V_115 & V_147 ) ) ) {
F_69 ( V_26 ,
F_84 ( V_26 , V_114 ) ,
( V_140 << 24 ) |
( V_138 << 8 ) | V_138 ) ;
V_138 ++ ;
if ( ! V_137 ) {
F_24 ( L_12 ) ;
goto V_142;
}
F_69 ( V_137 ,
F_84 ( V_137 ,
F_85 ( V_137 -> V_148 ) ) ,
( V_138 << 24 ) |
( V_140 << 8 ) | V_140 ) ;
}
V_142:
F_67 ( V_26 , F_83 ( V_26 , V_114 ) ,
& V_136 ) ;
F_24 ( L_13 , V_114 , V_136 ) ;
}
if ( ( V_136 & V_149 ) && V_137 ) {
F_24 ( L_14 ) ;
F_78 ( V_137 ,
F_85 ( V_137 -> V_148 ) , NULL ) ;
F_80 ( 50 ) ;
F_67 ( V_26 , F_83 ( V_26 , V_114 ) ,
& V_136 ) ;
F_24 ( L_13 , V_114 , V_136 ) ;
}
return ( V_136 & ( V_141 |
V_149 ) ) ? 1 : 0 ;
}
int F_86 ( struct V_1 * V_12 , union V_71 * V_150 )
{
struct V_25 * V_26 ;
T_2 V_136 , V_151 , V_152 ;
int V_42 , V_153 ;
struct V_74 * V_75 ;
#ifdef F_87
{
T_2 V_128 ;
F_24 ( L_15 , V_36 , V_12 -> V_154 ) ;
for ( V_128 = 0 ; V_128 < V_155 / sizeof( T_2 ) ; V_128 = V_128 + 4 ) {
F_24 ( L_16 ,
V_128 * 4 , V_150 -> V_156 [ V_128 ] , V_150 -> V_156 [ V_128 + 1 ] ,
V_150 -> V_156 [ V_128 + 2 ] , V_150 -> V_156 [ V_128 + 3 ] ) ;
}
}
#endif
V_26 = F_64 ( ( V_150 -> V_157 . V_158 & V_159 ) , NULL ) ;
if ( V_26 ) {
F_24 ( L_17 , F_25 ( V_26 ) ) ;
} else {
F_24 ( L_18 ,
V_36 , V_150 -> V_157 . V_158 ) ;
}
if ( V_26 && V_26 -> F_49 ) {
V_42 = V_26 -> F_49 ( V_26 , V_150 , 0 ) ;
if ( V_42 == 0 )
return 0 ;
}
F_40 ( & V_12 -> V_64 ) ;
F_45 (pwrite, &mport->pwrites, node)
V_75 -> F_49 ( V_12 , V_75 -> V_70 , V_150 , 0 ) ;
F_41 ( & V_12 -> V_64 ) ;
if ( ! V_26 )
return 0 ;
V_153 = V_150 -> V_157 . V_160 & 0xFF ;
if ( F_77 ( V_26 ) ) {
F_24 ( L_19 ) ;
if ( F_74 ( V_26 , & V_26 , & V_153 ) ) {
F_88 ( L_20 ,
F_25 ( V_26 ) ) ;
return - V_118 ;
}
V_150 = NULL ;
}
if ( ! ( V_26 -> V_32 & V_33 ) )
return 0 ;
if ( V_26 -> V_161 == 0 ) {
F_88 ( L_21 ,
F_25 ( V_26 ) ) ;
return 0 ;
}
if ( V_26 -> V_34 -> V_8 && V_26 -> V_34 -> V_8 -> V_162 )
V_26 -> V_34 -> V_8 -> V_162 ( V_26 , V_153 ) ;
F_67 ( V_26 , F_83 ( V_26 , V_153 ) ,
& V_136 ) ;
F_24 ( L_22 , V_153 , V_136 ) ;
if ( V_136 & V_163 ) {
if ( ! ( V_26 -> V_34 -> V_164 & ( 1 << V_153 ) ) ) {
V_26 -> V_34 -> V_164 |= ( 1 << V_153 ) ;
F_66 ( V_26 , V_153 , 0 ) ;
F_24 ( L_23 ,
F_25 ( V_26 ) , V_153 ) ;
}
if ( V_136 & ( V_141 |
V_149 ) ) {
if ( F_82 ( V_26 , V_153 , V_136 ) )
F_82 ( V_26 , V_153 , 0 ) ;
}
} else {
if ( V_26 -> V_34 -> V_164 & ( 1 << V_153 ) ) {
V_26 -> V_34 -> V_164 &= ~ ( 1 << V_153 ) ;
F_66 ( V_26 , V_153 , 1 ) ;
if ( V_26 -> V_165 == 1 ) {
F_69 ( V_26 ,
F_84 ( V_26 , V_153 ) ,
V_166 ) ;
} else {
F_69 ( V_26 ,
F_89 ( V_26 , V_153 ) ,
V_167 ) ;
F_69 ( V_26 ,
F_90 ( V_26 , V_153 ) ,
0 ) ;
}
F_24 ( L_24 ,
F_25 ( V_26 ) , V_153 ) ;
}
}
F_67 ( V_26 ,
V_26 -> V_168 + F_91 ( V_153 ) , & V_151 ) ;
if ( V_151 ) {
F_24 ( L_25 ,
V_153 , V_151 ) ;
F_69 ( V_26 ,
V_26 -> V_168 + F_91 ( V_153 ) , 0 ) ;
}
F_67 ( V_26 ,
V_26 -> V_168 + V_169 , & V_152 ) ;
if ( V_152 ) {
F_24 ( L_26 ,
V_152 ) ;
F_69 ( V_26 ,
V_26 -> V_168 + V_169 , 0 ) ;
}
F_69 ( V_26 , F_83 ( V_26 , V_153 ) ,
V_136 ) ;
return 0 ;
}
T_2
F_61 ( struct V_1 * V_2 , int V_80 , T_1 V_89 ,
T_5 V_94 , T_2 V_110 )
{
T_2 V_170 ;
if ( V_110 == 0 ) {
if ( V_80 )
F_2 ( V_2 , V_171 ,
& V_170 ) ;
else
F_62 ( V_2 , V_89 , V_94 ,
V_171 , & V_170 ) ;
return V_170 & V_172 ;
} else {
if ( V_80 )
F_2 ( V_2 , V_110 , & V_170 ) ;
else
F_62 ( V_2 , V_89 , V_94 ,
V_110 , & V_170 ) ;
return F_63 ( V_170 ) ;
}
}
T_2
F_92 ( struct V_1 * V_2 , int V_80 , T_1 V_89 ,
T_5 V_94 , int V_173 )
{
T_2 V_174 , V_96 , V_97 ;
if ( V_80 )
F_2 ( V_2 , V_171 , & V_174 ) ;
else
F_62 ( V_2 , V_89 , V_94 ,
V_171 , & V_174 ) ;
V_96 = V_174 & V_172 ;
while ( V_96 ) {
if ( V_80 )
F_2 ( V_2 , V_96 ,
& V_97 ) ;
else
F_62 ( V_2 , V_89 , V_94 ,
V_96 , & V_97 ) ;
if ( F_63 ( V_97 ) == V_173 )
return V_96 ;
if ( ! ( V_96 = F_93 ( V_97 ) ) )
break;
}
return 0 ;
}
struct V_25 * F_94 ( T_1 V_175 , T_1 V_24 ,
T_1 V_176 , T_1 V_177 , struct V_25 * V_110 )
{
struct V_111 * V_112 ;
struct V_25 * V_26 ;
F_95 ( F_96 () ) ;
F_10 ( & V_21 ) ;
V_112 = V_110 ? V_110 -> V_29 . V_113 : V_30 . V_113 ;
while ( V_112 && ( V_112 != & V_30 ) ) {
V_26 = F_65 ( V_112 ) ;
if ( ( V_175 == V_178 || V_26 -> V_175 == V_175 ) &&
( V_24 == V_178 || V_26 -> V_24 == V_24 ) &&
( V_176 == V_178 || V_26 -> V_176 == V_176 ) &&
( V_177 == V_178 || V_26 -> V_177 == V_177 ) )
goto exit;
V_112 = V_112 -> V_113 ;
}
V_26 = NULL ;
exit:
F_97 ( V_110 ) ;
V_26 = F_98 ( V_26 ) ;
F_12 ( & V_21 ) ;
return V_26 ;
}
struct V_25 * F_99 ( T_1 V_175 , T_1 V_24 , struct V_25 * V_110 )
{
return F_94 ( V_175 , V_24 , V_178 , V_178 , V_110 ) ;
}
static int
F_100 ( struct V_1 * V_12 , T_1 V_89 , T_5 V_94 ,
T_1 V_179 , T_1 V_180 , T_5 V_181 )
{
if ( V_179 == V_182 ) {
F_73 ( V_12 , V_89 , V_94 ,
V_183 ,
( T_2 ) V_180 ) ;
F_73 ( V_12 , V_89 , V_94 ,
V_184 ,
( T_2 ) V_181 ) ;
}
F_80 ( 10 ) ;
return 0 ;
}
static int
F_101 ( struct V_1 * V_12 , T_1 V_89 , T_5 V_94 ,
T_1 V_179 , T_1 V_180 , T_5 * V_181 )
{
T_2 V_3 ;
if ( V_179 == V_182 ) {
F_73 ( V_12 , V_89 , V_94 ,
V_183 , V_180 ) ;
F_62 ( V_12 , V_89 , V_94 ,
V_184 , & V_3 ) ;
* V_181 = ( T_5 ) V_3 ;
}
return 0 ;
}
static int
F_102 ( struct V_1 * V_12 , T_1 V_89 , T_5 V_94 ,
T_1 V_179 )
{
T_2 V_185 = 0xff ;
T_2 V_128 , V_32 , V_186 = 1 , V_187 = 0 ;
T_2 V_188 = V_127 ;
if ( V_179 == V_182 ) {
F_62 ( V_12 , V_89 , V_94 ,
V_189 , & V_32 ) ;
if ( V_12 -> V_5 ) {
F_62 ( V_12 , V_89 , V_94 ,
V_190 ,
& V_185 ) ;
V_185 &= V_191 ;
}
if ( V_32 & V_192 ) {
V_187 = 0x80000000 ;
V_186 = 4 ;
V_188 = ( V_127 << 24 ) |
( V_127 << 16 ) |
( V_127 << 8 ) |
V_127 ;
}
for ( V_128 = 0 ; V_128 <= V_185 ; ) {
F_73 ( V_12 , V_89 , V_94 ,
V_183 ,
V_187 | V_128 ) ;
F_73 ( V_12 , V_89 , V_94 ,
V_184 ,
V_188 ) ;
V_128 += V_186 ;
}
}
F_80 ( 10 ) ;
return 0 ;
}
int F_103 ( struct V_1 * V_2 , T_1 V_89 ,
T_5 V_94 , int V_193 )
{
T_2 V_3 ;
int V_194 = 0 ;
F_73 ( V_2 , V_89 , V_94 ,
V_195 , V_2 -> V_196 ) ;
F_62 ( V_2 , V_89 , V_94 ,
V_195 , & V_3 ) ;
while ( V_3 != V_2 -> V_196 ) {
if ( V_193 != 0 && V_194 == V_193 ) {
F_24 ( L_27 ,
V_89 , V_94 ) ;
return - V_54 ;
}
F_76 ( 1 ) ;
V_194 ++ ;
F_73 ( V_2 , V_89 ,
V_94 ,
V_195 ,
V_2 -> V_196 ) ;
F_62 ( V_2 , V_89 ,
V_94 ,
V_195 , & V_3 ) ;
}
return 0 ;
}
int F_104 ( struct V_1 * V_2 , T_1 V_89 , T_5 V_94 )
{
T_2 V_3 ;
F_73 ( V_2 , V_89 ,
V_94 ,
V_195 ,
V_2 -> V_196 ) ;
F_62 ( V_2 , V_89 , V_94 ,
V_195 , & V_3 ) ;
if ( ( V_3 & 0xffff ) != 0xffff ) {
F_24 ( L_28 ,
V_89 , V_94 ) ;
return - V_54 ;
}
return 0 ;
}
int F_105 ( struct V_25 * V_26 ,
T_1 V_179 , T_1 V_180 , T_5 V_181 , int V_64 )
{
int V_42 = - V_54 ;
struct V_197 * V_8 = V_26 -> V_34 -> V_8 ;
if ( V_64 ) {
V_42 = F_103 ( V_26 -> V_13 -> V_131 , V_26 -> V_89 ,
V_26 -> V_94 , 1000 ) ;
if ( V_42 )
return V_42 ;
}
F_10 ( & V_26 -> V_34 -> V_64 ) ;
if ( V_8 == NULL || V_8 -> V_198 == NULL ) {
V_42 = F_100 ( V_26 -> V_13 -> V_131 , V_26 -> V_89 ,
V_26 -> V_94 , V_179 ,
V_180 , V_181 ) ;
} else if ( F_106 ( V_8 -> V_199 ) ) {
V_42 = V_8 -> V_198 ( V_26 -> V_13 -> V_131 , V_26 -> V_89 ,
V_26 -> V_94 , V_179 , V_180 ,
V_181 ) ;
F_107 ( V_8 -> V_199 ) ;
}
F_12 ( & V_26 -> V_34 -> V_64 ) ;
if ( V_64 )
F_104 ( V_26 -> V_13 -> V_131 , V_26 -> V_89 ,
V_26 -> V_94 ) ;
return V_42 ;
}
int F_108 ( struct V_25 * V_26 , T_1 V_179 ,
T_1 V_180 , T_5 * V_181 , int V_64 )
{
int V_42 = - V_54 ;
struct V_197 * V_8 = V_26 -> V_34 -> V_8 ;
if ( V_64 ) {
V_42 = F_103 ( V_26 -> V_13 -> V_131 , V_26 -> V_89 ,
V_26 -> V_94 , 1000 ) ;
if ( V_42 )
return V_42 ;
}
F_10 ( & V_26 -> V_34 -> V_64 ) ;
if ( V_8 == NULL || V_8 -> V_200 == NULL ) {
V_42 = F_101 ( V_26 -> V_13 -> V_131 , V_26 -> V_89 ,
V_26 -> V_94 , V_179 ,
V_180 , V_181 ) ;
} else if ( F_106 ( V_8 -> V_199 ) ) {
V_42 = V_8 -> V_200 ( V_26 -> V_13 -> V_131 , V_26 -> V_89 ,
V_26 -> V_94 , V_179 , V_180 ,
V_181 ) ;
F_107 ( V_8 -> V_199 ) ;
}
F_12 ( & V_26 -> V_34 -> V_64 ) ;
if ( V_64 )
F_104 ( V_26 -> V_13 -> V_131 , V_26 -> V_89 ,
V_26 -> V_94 ) ;
return V_42 ;
}
int F_109 ( struct V_25 * V_26 , T_1 V_179 , int V_64 )
{
int V_42 = - V_54 ;
struct V_197 * V_8 = V_26 -> V_34 -> V_8 ;
if ( V_64 ) {
V_42 = F_103 ( V_26 -> V_13 -> V_131 , V_26 -> V_89 ,
V_26 -> V_94 , 1000 ) ;
if ( V_42 )
return V_42 ;
}
F_10 ( & V_26 -> V_34 -> V_64 ) ;
if ( V_8 == NULL || V_8 -> V_201 == NULL ) {
V_42 = F_102 ( V_26 -> V_13 -> V_131 , V_26 -> V_89 ,
V_26 -> V_94 , V_179 ) ;
} else if ( F_106 ( V_8 -> V_199 ) ) {
V_42 = V_8 -> V_201 ( V_26 -> V_13 -> V_131 , V_26 -> V_89 ,
V_26 -> V_94 , V_179 ) ;
F_107 ( V_8 -> V_199 ) ;
}
F_12 ( & V_26 -> V_34 -> V_64 ) ;
if ( V_64 )
F_104 ( V_26 -> V_13 -> V_131 , V_26 -> V_89 ,
V_26 -> V_94 ) ;
return V_42 ;
}
static bool F_110 ( struct V_202 * V_203 , void * V_204 )
{
struct V_1 * V_12 = V_204 ;
return V_12 == F_111 ( V_203 -> V_205 , struct V_1 , V_206 ) ;
}
struct V_202 * F_112 ( struct V_1 * V_12 )
{
T_6 V_207 ;
F_113 ( V_207 ) ;
F_114 ( V_208 , V_207 ) ;
return F_115 ( V_207 , F_110 , V_12 ) ;
}
struct V_202 * F_116 ( struct V_25 * V_26 )
{
return F_112 ( V_26 -> V_13 -> V_131 ) ;
}
void F_117 ( struct V_202 * V_209 )
{
F_118 ( V_209 ) ;
}
struct V_210 * F_119 ( struct V_202 * V_209 ,
T_1 V_89 , struct V_211 * V_212 ,
enum V_213 V_214 , unsigned long V_84 )
{
struct V_215 V_216 ;
if ( V_209 -> V_205 -> V_217 == NULL ) {
F_88 ( L_29 , V_36 ) ;
return NULL ;
}
V_216 . V_89 = V_89 ;
V_216 . V_218 = V_212 -> V_218 ;
V_216 . V_219 = V_212 -> V_219 ;
V_216 . V_220 = V_212 -> V_220 ;
return F_120 ( V_209 , V_212 -> V_221 , V_212 -> V_222 ,
V_214 , V_84 , & V_216 ) ;
}
struct V_210 * F_121 ( struct V_25 * V_26 ,
struct V_202 * V_209 , struct V_211 * V_212 ,
enum V_213 V_214 , unsigned long V_84 )
{
return F_119 ( V_209 , V_26 -> V_89 , V_212 , V_214 , V_84 ) ;
}
struct V_1 * F_122 ( int V_223 )
{
struct V_1 * V_2 ;
F_40 ( & V_224 ) ;
F_45 (port, &rio_mports, node) {
if ( V_2 -> V_154 == V_223 )
goto V_69;
}
V_2 = NULL ;
V_69:
F_41 ( & V_224 ) ;
return V_2 ;
}
int F_123 ( int V_223 , struct V_225 * V_226 )
{
struct V_1 * V_2 ;
struct V_227 * V_228 ;
int V_42 = 0 ;
F_24 ( L_30 , V_36 , V_223 ) ;
if ( ( V_223 != V_229 && V_223 >= V_230 ) ||
! V_226 )
return - V_54 ;
F_40 ( & V_224 ) ;
F_45 (scan, &rio_scans, node) {
if ( V_228 -> V_223 == V_223 ) {
V_42 = - V_231 ;
goto V_126;
}
}
V_228 = F_6 ( sizeof( * V_228 ) , V_14 ) ;
if ( ! V_228 ) {
V_42 = - V_52 ;
goto V_126;
}
V_228 -> V_223 = V_223 ;
V_228 -> V_8 = V_226 ;
F_45 (port, &rio_mports, node) {
if ( V_2 -> V_154 == V_223 ) {
V_2 -> V_232 = V_226 ;
break;
} else if ( V_223 == V_229 && ! V_2 -> V_232 )
V_2 -> V_232 = V_226 ;
}
F_11 ( & V_228 -> V_15 , & V_233 ) ;
V_126:
F_41 ( & V_224 ) ;
return V_42 ;
}
int F_124 ( int V_223 , struct V_225 * V_226 )
{
struct V_1 * V_2 ;
struct V_227 * V_228 ;
F_24 ( L_30 , V_36 , V_223 ) ;
if ( V_223 != V_229 && V_223 >= V_230 )
return - V_54 ;
F_40 ( & V_224 ) ;
F_45 (port, &rio_mports, node)
if ( V_2 -> V_154 == V_223 ||
( V_223 == V_229 && V_2 -> V_232 == V_226 ) )
V_2 -> V_232 = NULL ;
F_45 (scan, &rio_scans, node) {
if ( V_228 -> V_223 == V_223 ) {
F_15 ( & V_228 -> V_15 ) ;
F_26 ( V_228 ) ;
break;
}
}
F_41 ( & V_224 ) ;
return 0 ;
}
int F_125 ( int V_223 )
{
struct V_1 * V_2 = NULL ;
int V_42 ;
F_40 ( & V_224 ) ;
F_45 (port, &rio_mports, node) {
if ( V_2 -> V_154 == V_223 )
goto V_69;
}
F_41 ( & V_224 ) ;
return - V_91 ;
V_69:
if ( ! V_2 -> V_232 ) {
F_41 ( & V_224 ) ;
return - V_54 ;
}
if ( ! F_106 ( V_2 -> V_232 -> V_199 ) ) {
F_41 ( & V_224 ) ;
return - V_91 ;
}
F_41 ( & V_224 ) ;
if ( V_2 -> V_196 >= 0 )
V_42 = V_2 -> V_232 -> V_234 ( V_2 , 0 ) ;
else
V_42 = V_2 -> V_232 -> V_235 ( V_2 , V_236 ) ;
F_107 ( V_2 -> V_232 -> V_199 ) ;
return V_42 ;
}
static void F_126 ( struct V_25 * V_20 )
{
}
static int F_127 ( void )
{
struct V_25 * V_20 = NULL ;
while ( ( V_20 = F_99 ( V_178 , V_178 , V_20 ) ) != NULL ) {
F_126 ( V_20 ) ;
}
return 0 ;
}
static void F_128 ( struct V_237 * V_238 )
{
struct V_239 * V_240 ;
V_240 = F_111 ( V_238 , struct V_239 , V_240 ) ;
F_24 ( L_31 ,
V_240 -> V_12 -> V_154 , V_240 -> V_12 -> V_241 ) ;
if ( F_106 ( V_240 -> V_12 -> V_232 -> V_199 ) ) {
V_240 -> V_12 -> V_232 -> V_235 ( V_240 -> V_12 , 0 ) ;
F_107 ( V_240 -> V_12 -> V_232 -> V_199 ) ;
}
}
int F_129 ( void )
{
struct V_1 * V_2 ;
struct V_239 * V_240 ;
int V_112 = 0 ;
if ( ! V_242 )
return - V_91 ;
F_40 ( & V_224 ) ;
F_45 (port, &rio_mports, node) {
if ( V_2 -> V_196 >= 0 ) {
if ( V_2 -> V_232 && F_106 ( V_2 -> V_232 -> V_199 ) ) {
V_2 -> V_232 -> V_234 ( V_2 , 0 ) ;
F_107 ( V_2 -> V_232 -> V_199 ) ;
}
} else
V_112 ++ ;
}
F_41 ( & V_224 ) ;
if ( ! V_112 )
goto V_243;
V_244 = F_130 ( L_32 , 0 , 0 ) ;
if ( ! V_244 ) {
F_88 ( L_33 ) ;
goto V_243;
}
V_240 = F_131 ( V_112 , sizeof *V_240 , V_14 ) ;
if ( ! V_240 ) {
F_88 ( L_34 ) ;
F_132 ( V_244 ) ;
goto V_243;
}
V_112 = 0 ;
F_40 ( & V_224 ) ;
F_45 (port, &rio_mports, node) {
if ( V_2 -> V_196 < 0 && V_2 -> V_232 ) {
V_240 [ V_112 ] . V_12 = V_2 ;
F_133 ( & V_240 [ V_112 ] . V_240 , F_128 ) ;
F_134 ( V_244 , & V_240 [ V_112 ] . V_240 ) ;
V_112 ++ ;
}
}
F_135 ( V_244 ) ;
F_41 ( & V_224 ) ;
F_24 ( L_35 ) ;
F_132 ( V_244 ) ;
F_26 ( V_240 ) ;
V_243:
F_127 () ;
return 0 ;
}
static int F_136 ( int V_245 )
{
if ( V_246 == 0 || V_246 <= V_245 || V_245 >= V_230 )
return - 1 ;
return V_247 [ V_245 ] ;
}
int F_137 ( struct V_1 * V_12 )
{
if ( V_242 >= V_230 ) {
F_88 ( L_36 ) ;
return - V_91 ;
}
F_21 ( & V_12 -> V_27 , V_248 ) ;
V_12 -> V_154 = V_242 ++ ;
V_12 -> V_196 = F_136 ( V_12 -> V_154 ) ;
V_12 -> V_232 = NULL ;
F_138 ( & V_12 -> V_64 ) ;
V_12 -> V_79 = 0 ;
F_7 ( & V_12 -> V_76 ) ;
return 0 ;
}
int F_139 ( struct V_1 * V_2 )
{
struct V_227 * V_228 = NULL ;
int V_45 = 0 ;
F_40 ( & V_224 ) ;
F_45 (scan, &rio_scans, node) {
if ( V_2 -> V_154 == V_228 -> V_223 ||
V_228 -> V_223 == V_229 ) {
V_2 -> V_232 = V_228 -> V_8 ;
if ( V_2 -> V_154 == V_228 -> V_223 )
break;
}
}
F_11 ( & V_2 -> V_15 , & V_249 ) ;
F_41 ( & V_224 ) ;
F_140 ( & V_2 -> V_20 , L_37 , V_2 -> V_154 ) ;
V_2 -> V_20 . V_250 = & V_251 ;
F_21 ( & V_2 -> V_27 , V_28 ) ;
V_45 = F_9 ( & V_2 -> V_20 ) ;
if ( V_45 )
F_141 ( & V_2 -> V_20 , L_38 ,
V_2 -> V_154 , V_45 ) ;
else
F_142 ( & V_2 -> V_20 , L_39 , V_2 -> V_154 ) ;
return V_45 ;
}
static int F_143 ( struct V_205 * V_20 , void * V_212 )
{
struct V_25 * V_26 = F_144 ( V_20 ) ;
if ( V_20 -> V_252 == & V_253 )
F_23 ( V_26 , V_254 ) ;
return 0 ;
}
static int F_145 ( struct V_11 * V_13 )
{
F_146 ( & V_13 -> V_20 , NULL , F_143 ) ;
return 0 ;
}
int F_147 ( struct V_1 * V_2 )
{
F_24 ( L_40 , V_36 , V_2 -> V_241 , V_2 -> V_154 ) ;
if ( F_148 ( & V_2 -> V_27 ,
V_28 ,
V_254 ) != V_28 ) {
F_88 ( L_41 ,
V_36 , V_2 -> V_241 ) ;
}
if ( V_2 -> V_13 && V_2 -> V_13 -> V_131 == V_2 ) {
F_145 ( V_2 -> V_13 ) ;
F_13 ( V_2 -> V_13 ) ;
}
F_40 ( & V_224 ) ;
F_15 ( & V_2 -> V_15 ) ;
F_41 ( & V_224 ) ;
F_16 ( & V_2 -> V_20 ) ;
return 0 ;
}
