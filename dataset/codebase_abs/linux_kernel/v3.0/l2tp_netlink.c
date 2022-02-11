static struct V_1 * F_1 ( struct V_2 * V_3 )
{
T_1 V_4 ;
T_1 V_5 ;
char * V_6 ;
struct V_7 * V_8 ;
struct V_1 * V_9 = NULL ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( V_3 -> V_11 [ V_12 ] ) {
V_6 = F_3 ( V_3 -> V_11 [ V_12 ] ) ;
V_9 = F_4 ( V_10 , V_6 ) ;
} else if ( ( V_3 -> V_11 [ V_13 ] ) &&
( V_3 -> V_11 [ V_14 ] ) ) {
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_5 = F_5 ( V_3 -> V_11 [ V_13 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 )
V_9 = F_7 ( V_10 , V_8 , V_5 ) ;
}
return V_9 ;
}
static int F_8 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_15 * V_17 ;
void * V_18 ;
int V_19 = - V_20 ;
V_17 = F_9 ( V_21 , V_22 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto V_24;
}
V_18 = F_10 ( V_17 , V_3 -> V_25 , V_3 -> V_26 ,
& V_27 , 0 , V_28 ) ;
if ( F_11 ( V_18 ) ) {
V_19 = F_12 ( V_18 ) ;
goto V_29;
}
F_13 ( V_17 , V_18 ) ;
return F_14 ( F_2 ( V_3 ) , V_17 , V_3 -> V_25 ) ;
V_29:
F_15 ( V_17 ) ;
V_24:
return V_19 ;
}
static int F_16 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
T_1 V_4 ;
T_1 V_30 ;
int V_31 ;
int V_32 ;
int V_19 = 0 ;
struct V_33 V_34 = { 0 , } ;
struct V_7 * V_8 ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_35 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
if ( ! V_3 -> V_11 [ V_36 ] ) {
V_19 = - V_35 ;
goto V_24;
}
V_30 = F_5 ( V_3 -> V_11 [ V_36 ] ) ;
if ( ! V_3 -> V_11 [ V_37 ] ) {
V_19 = - V_35 ;
goto V_24;
}
V_31 = F_17 ( V_3 -> V_11 [ V_37 ] ) ;
if ( ! V_3 -> V_11 [ V_38 ] ) {
V_19 = - V_35 ;
goto V_24;
}
V_34 . V_39 = F_18 ( V_3 -> V_11 [ V_38 ] ) ;
V_32 = - 1 ;
if ( V_3 -> V_11 [ V_40 ] ) {
V_32 = F_5 ( V_3 -> V_11 [ V_40 ] ) ;
} else {
if ( V_3 -> V_11 [ V_41 ] )
V_34 . V_42 . V_43 = F_19 ( V_3 -> V_11 [ V_41 ] ) ;
if ( V_3 -> V_11 [ V_44 ] )
V_34 . V_45 . V_43 = F_19 ( V_3 -> V_11 [ V_44 ] ) ;
if ( V_3 -> V_11 [ V_46 ] )
V_34 . V_47 = F_18 ( V_3 -> V_11 [ V_46 ] ) ;
if ( V_3 -> V_11 [ V_48 ] )
V_34 . V_49 = F_18 ( V_3 -> V_11 [ V_48 ] ) ;
if ( V_3 -> V_11 [ V_50 ] )
V_34 . V_51 = F_20 ( V_3 -> V_11 [ V_50 ] ) ;
}
if ( V_3 -> V_11 [ V_52 ] )
V_34 . V_53 = F_5 ( V_3 -> V_11 [ V_52 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 != NULL ) {
V_19 = - V_54 ;
goto V_24;
}
V_19 = - V_35 ;
switch ( V_34 . V_39 ) {
case V_55 :
case V_56 :
V_19 = F_21 ( V_10 , V_32 , V_31 , V_4 ,
V_30 , & V_34 , & V_8 ) ;
break;
}
V_24:
return V_19 ;
}
static int F_22 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_7 * V_8 ;
T_1 V_4 ;
int V_19 = 0 ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_35 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 == NULL ) {
V_19 = - V_57 ;
goto V_24;
}
( void ) F_23 ( V_8 ) ;
V_24:
return V_19 ;
}
static int F_24 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_7 * V_8 ;
T_1 V_4 ;
int V_19 = 0 ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_35 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 == NULL ) {
V_19 = - V_57 ;
goto V_24;
}
if ( V_3 -> V_11 [ V_52 ] )
V_8 -> V_53 = F_5 ( V_3 -> V_11 [ V_52 ] ) ;
V_24:
return V_19 ;
}
static int F_25 ( struct V_15 * V_16 , T_1 V_58 , T_1 V_59 , int V_60 ,
struct V_7 * V_8 )
{
void * V_18 ;
struct V_61 * V_62 ;
struct V_63 * V_64 = NULL ;
struct V_65 * V_66 ;
V_18 = F_10 ( V_16 , V_58 , V_59 , & V_27 , V_60 ,
V_67 ) ;
if ( F_11 ( V_18 ) )
return F_12 ( V_18 ) ;
F_26 ( V_16 , V_37 , V_8 -> V_68 ) ;
F_27 ( V_16 , V_14 , V_8 -> V_4 ) ;
F_27 ( V_16 , V_36 , V_8 -> V_30 ) ;
F_27 ( V_16 , V_52 , V_8 -> V_53 ) ;
F_28 ( V_16 , V_38 , V_8 -> V_39 ) ;
V_62 = F_29 ( V_16 , V_69 ) ;
if ( V_62 == NULL )
goto V_70;
F_30 ( V_16 , V_71 , V_8 -> V_72 . V_73 ) ;
F_30 ( V_16 , V_74 , V_8 -> V_72 . V_75 ) ;
F_30 ( V_16 , V_76 , V_8 -> V_72 . V_77 ) ;
F_30 ( V_16 , V_78 , V_8 -> V_72 . V_79 ) ;
F_30 ( V_16 , V_80 , V_8 -> V_72 . V_81 ) ;
F_30 ( V_16 , V_82 , V_8 -> V_72 . V_83 ) ;
F_30 ( V_16 , V_84 , V_8 -> V_72 . V_85 ) ;
F_30 ( V_16 , V_86 , V_8 -> V_72 . V_87 ) ;
F_31 ( V_16 , V_62 ) ;
V_64 = V_8 -> V_63 ;
if ( ! V_64 )
goto V_24;
V_66 = F_32 ( V_64 ) ;
switch ( V_8 -> V_39 ) {
case V_55 :
F_28 ( V_16 , V_46 , F_33 ( V_66 -> V_88 ) ) ;
F_28 ( V_16 , V_48 , F_33 ( V_66 -> V_89 ) ) ;
F_26 ( V_16 , V_50 , ( V_64 -> V_90 != V_91 ) ) ;
case V_56 :
F_34 ( V_16 , V_41 , V_66 -> V_92 ) ;
F_34 ( V_16 , V_44 , V_66 -> V_93 ) ;
break;
}
V_24:
return F_13 ( V_16 , V_18 ) ;
V_70:
F_35 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_36 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_7 * V_8 ;
struct V_15 * V_17 ;
T_1 V_4 ;
int V_19 = - V_20 ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_35 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 == NULL ) {
V_19 = - V_57 ;
goto V_24;
}
V_17 = F_9 ( V_21 , V_22 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto V_24;
}
V_19 = F_25 ( V_17 , V_3 -> V_25 , V_3 -> V_26 ,
V_94 , V_8 ) ;
if ( V_19 < 0 )
goto V_29;
return F_14 ( V_10 , V_17 , V_3 -> V_25 ) ;
V_29:
F_15 ( V_17 ) ;
V_24:
return V_19 ;
}
static int F_37 ( struct V_15 * V_16 , struct V_95 * V_96 )
{
int V_97 = V_96 -> args [ 0 ] ;
struct V_7 * V_8 ;
struct V_10 * V_10 = F_38 ( V_16 -> V_64 ) ;
for (; ; ) {
V_8 = F_39 ( V_10 , V_97 ) ;
if ( V_8 == NULL )
goto V_24;
if ( F_25 ( V_16 , F_40 ( V_96 -> V_16 ) . V_58 ,
V_96 -> V_98 -> V_99 , V_100 ,
V_8 ) <= 0 )
goto V_24;
V_97 ++ ;
}
V_24:
V_96 -> args [ 0 ] = V_97 ;
return V_16 -> V_101 ;
}
static int F_41 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
T_1 V_4 = 0 ;
T_1 V_5 ;
T_1 V_102 ;
int V_19 = 0 ;
struct V_7 * V_8 ;
struct V_1 * V_9 ;
struct V_103 V_34 = { 0 , } ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_35 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( ! V_8 ) {
V_19 = - V_57 ;
goto V_24;
}
if ( ! V_3 -> V_11 [ V_13 ] ) {
V_19 = - V_35 ;
goto V_24;
}
V_5 = F_5 ( V_3 -> V_11 [ V_13 ] ) ;
V_9 = F_7 ( V_10 , V_8 , V_5 ) ;
if ( V_9 ) {
V_19 = - V_54 ;
goto V_24;
}
if ( ! V_3 -> V_11 [ V_104 ] ) {
V_19 = - V_35 ;
goto V_24;
}
V_102 = F_5 ( V_3 -> V_11 [ V_104 ] ) ;
if ( ! V_3 -> V_11 [ V_105 ] ) {
V_19 = - V_35 ;
goto V_24;
}
V_34 . V_106 = F_18 ( V_3 -> V_11 [ V_105 ] ) ;
if ( V_34 . V_106 >= V_107 ) {
V_19 = - V_35 ;
goto V_24;
}
if ( V_8 -> V_68 > 2 ) {
if ( V_3 -> V_11 [ V_108 ] )
V_34 . V_109 = F_18 ( V_3 -> V_11 [ V_108 ] ) ;
if ( V_3 -> V_11 [ V_110 ] )
V_34 . V_111 = F_17 ( V_3 -> V_11 [ V_110 ] ) ;
V_34 . V_112 = V_113 ;
if ( V_3 -> V_11 [ V_114 ] )
V_34 . V_112 = F_17 ( V_3 -> V_11 [ V_114 ] ) ;
V_34 . V_115 = 4 ;
if ( V_3 -> V_11 [ V_116 ] )
V_34 . V_115 = F_17 ( V_3 -> V_11 [ V_116 ] ) ;
if ( V_3 -> V_11 [ V_117 ] ) {
T_2 V_101 = F_42 ( V_3 -> V_11 [ V_117 ] ) ;
if ( V_101 > 8 ) {
V_19 = - V_35 ;
goto V_24;
}
V_34 . V_118 = V_101 ;
memcpy ( & V_34 . V_119 [ 0 ] , F_3 ( V_3 -> V_11 [ V_117 ] ) , V_101 ) ;
}
if ( V_3 -> V_11 [ V_120 ] ) {
T_2 V_101 = F_42 ( V_3 -> V_11 [ V_120 ] ) ;
if ( V_101 > 8 ) {
V_19 = - V_35 ;
goto V_24;
}
V_34 . V_121 = V_101 ;
memcpy ( & V_34 . V_122 [ 0 ] , F_3 ( V_3 -> V_11 [ V_120 ] ) , V_101 ) ;
}
if ( V_3 -> V_11 [ V_12 ] )
V_34 . V_6 = F_3 ( V_3 -> V_11 [ V_12 ] ) ;
if ( V_3 -> V_11 [ V_123 ] )
V_34 . V_124 = F_18 ( V_3 -> V_11 [ V_123 ] ) ;
}
if ( V_3 -> V_11 [ V_52 ] )
V_34 . V_53 = F_5 ( V_3 -> V_11 [ V_52 ] ) ;
if ( V_3 -> V_11 [ V_125 ] )
V_34 . V_126 = F_17 ( V_3 -> V_11 [ V_125 ] ) ;
if ( V_3 -> V_11 [ V_127 ] )
V_34 . V_128 = F_17 ( V_3 -> V_11 [ V_127 ] ) ;
if ( V_3 -> V_11 [ V_129 ] )
V_34 . V_130 = F_17 ( V_3 -> V_11 [ V_129 ] ) ;
if ( V_3 -> V_11 [ V_131 ] )
V_34 . V_132 = F_43 ( V_3 -> V_11 [ V_131 ] ) ;
if ( V_3 -> V_11 [ V_133 ] )
V_34 . V_134 = F_18 ( V_3 -> V_11 [ V_133 ] ) ;
if ( V_3 -> V_11 [ V_135 ] )
V_34 . V_136 = F_18 ( V_3 -> V_11 [ V_135 ] ) ;
if ( ( V_137 [ V_34 . V_106 ] == NULL ) ||
( V_137 [ V_34 . V_106 ] -> V_138 == NULL ) ) {
V_19 = - V_139 ;
goto V_24;
}
switch ( V_34 . V_106 ) {
case V_140 :
break;
case V_141 :
if ( ! V_3 -> V_11 [ V_123 ] ) {
V_19 = - V_35 ;
goto V_24;
}
break;
case V_142 :
break;
case V_143 :
case V_144 :
break;
case V_145 :
default:
V_19 = - V_139 ;
break;
}
V_19 = - V_139 ;
if ( V_137 [ V_34 . V_106 ] -> V_138 )
V_19 = ( * V_137 [ V_34 . V_106 ] -> V_138 ) ( V_10 , V_4 ,
V_5 , V_102 , & V_34 ) ;
V_24:
return V_19 ;
}
static int F_44 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
int V_19 = 0 ;
struct V_1 * V_9 ;
T_2 V_106 ;
V_9 = F_1 ( V_3 ) ;
if ( V_9 == NULL ) {
V_19 = - V_57 ;
goto V_24;
}
V_106 = V_9 -> V_146 ;
if ( V_106 < V_107 )
if ( V_137 [ V_106 ] && V_137 [ V_106 ] -> V_147 )
V_19 = ( * V_137 [ V_106 ] -> V_147 ) ( V_9 ) ;
V_24:
return V_19 ;
}
static int F_45 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
int V_19 = 0 ;
struct V_1 * V_9 ;
V_9 = F_1 ( V_3 ) ;
if ( V_9 == NULL ) {
V_19 = - V_57 ;
goto V_24;
}
if ( V_3 -> V_11 [ V_52 ] )
V_9 -> V_53 = F_5 ( V_3 -> V_11 [ V_52 ] ) ;
if ( V_3 -> V_11 [ V_110 ] )
V_9 -> V_111 = F_17 ( V_3 -> V_11 [ V_110 ] ) ;
if ( V_3 -> V_11 [ V_125 ] )
V_9 -> V_126 = F_17 ( V_3 -> V_11 [ V_125 ] ) ;
if ( V_3 -> V_11 [ V_127 ] )
V_9 -> V_128 = F_17 ( V_3 -> V_11 [ V_127 ] ) ;
if ( V_3 -> V_11 [ V_129 ] )
V_9 -> V_130 = F_17 ( V_3 -> V_11 [ V_129 ] ) ;
if ( V_3 -> V_11 [ V_131 ] )
V_9 -> V_132 = F_43 ( V_3 -> V_11 [ V_131 ] ) ;
if ( V_3 -> V_11 [ V_133 ] )
V_9 -> V_134 = F_18 ( V_3 -> V_11 [ V_133 ] ) ;
if ( V_3 -> V_11 [ V_135 ] )
V_9 -> V_136 = F_18 ( V_3 -> V_11 [ V_135 ] ) ;
V_24:
return V_19 ;
}
static int F_46 ( struct V_15 * V_16 , T_1 V_58 , T_1 V_59 , int V_60 ,
struct V_1 * V_9 )
{
void * V_18 ;
struct V_61 * V_62 ;
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_63 * V_64 = NULL ;
V_64 = V_8 -> V_63 ;
V_18 = F_10 ( V_16 , V_58 , V_59 , & V_27 , V_60 , V_148 ) ;
if ( F_11 ( V_18 ) )
return F_12 ( V_18 ) ;
F_27 ( V_16 , V_14 , V_8 -> V_4 ) ;
F_27 ( V_16 , V_13 , V_9 -> V_5 ) ;
F_27 ( V_16 , V_36 , V_8 -> V_30 ) ;
F_27 ( V_16 , V_104 , V_9 -> V_102 ) ;
F_27 ( V_16 , V_52 , V_9 -> V_53 ) ;
F_28 ( V_16 , V_105 , V_9 -> V_146 ) ;
F_28 ( V_16 , V_133 , V_9 -> V_134 ) ;
if ( V_9 -> V_136 )
F_28 ( V_16 , V_135 , V_9 -> V_136 ) ;
if ( V_9 -> V_6 && V_9 -> V_6 [ 0 ] )
F_47 ( V_16 , V_12 , V_9 -> V_6 ) ;
if ( V_9 -> V_118 )
F_48 ( V_16 , V_117 , V_9 -> V_118 , & V_9 -> V_119 [ 0 ] ) ;
if ( V_9 -> V_121 )
F_48 ( V_16 , V_120 , V_9 -> V_121 , & V_9 -> V_122 [ 0 ] ) ;
F_26 ( V_16 , V_125 , V_9 -> V_126 ) ;
F_26 ( V_16 , V_127 , V_9 -> V_128 ) ;
F_26 ( V_16 , V_129 , V_9 -> V_130 ) ;
#ifdef F_49
if ( ( V_64 ) && ( V_64 -> V_149 [ 0 ] || V_64 -> V_149 [ 1 ] ) )
F_26 ( V_16 , V_150 , 1 ) ;
#endif
if ( V_9 -> V_132 )
F_50 ( V_16 , V_131 , V_9 -> V_132 ) ;
V_62 = F_29 ( V_16 , V_69 ) ;
if ( V_62 == NULL )
goto V_70;
F_30 ( V_16 , V_71 , V_9 -> V_72 . V_73 ) ;
F_30 ( V_16 , V_74 , V_9 -> V_72 . V_75 ) ;
F_30 ( V_16 , V_76 , V_9 -> V_72 . V_77 ) ;
F_30 ( V_16 , V_78 , V_9 -> V_72 . V_79 ) ;
F_30 ( V_16 , V_80 , V_9 -> V_72 . V_81 ) ;
F_30 ( V_16 , V_82 , V_9 -> V_72 . V_83 ) ;
F_30 ( V_16 , V_84 , V_9 -> V_72 . V_85 ) ;
F_30 ( V_16 , V_86 , V_9 -> V_72 . V_87 ) ;
F_31 ( V_16 , V_62 ) ;
return F_13 ( V_16 , V_18 ) ;
V_70:
F_35 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_51 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_15 * V_17 ;
int V_19 ;
V_9 = F_1 ( V_3 ) ;
if ( V_9 == NULL ) {
V_19 = - V_57 ;
goto V_24;
}
V_17 = F_9 ( V_21 , V_22 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto V_24;
}
V_19 = F_46 ( V_17 , V_3 -> V_25 , V_3 -> V_26 ,
0 , V_9 ) ;
if ( V_19 < 0 )
goto V_29;
return F_14 ( F_2 ( V_3 ) , V_17 , V_3 -> V_25 ) ;
V_29:
F_15 ( V_17 ) ;
V_24:
return V_19 ;
}
static int F_52 ( struct V_15 * V_16 , struct V_95 * V_96 )
{
struct V_10 * V_10 = F_38 ( V_16 -> V_64 ) ;
struct V_1 * V_9 ;
struct V_7 * V_8 = NULL ;
int V_97 = V_96 -> args [ 0 ] ;
int V_151 = V_96 -> args [ 1 ] ;
for (; ; ) {
if ( V_8 == NULL ) {
V_8 = F_39 ( V_10 , V_97 ) ;
if ( V_8 == NULL )
goto V_24;
}
V_9 = F_53 ( V_8 , V_151 ) ;
if ( V_9 == NULL ) {
V_97 ++ ;
V_8 = NULL ;
V_151 = 0 ;
continue;
}
if ( F_46 ( V_16 , F_40 ( V_96 -> V_16 ) . V_58 ,
V_96 -> V_98 -> V_99 , V_100 ,
V_9 ) <= 0 )
break;
V_151 ++ ;
}
V_24:
V_96 -> args [ 0 ] = V_97 ;
V_96 -> args [ 1 ] = V_151 ;
return V_16 -> V_101 ;
}
int F_54 ( enum V_152 V_106 , const struct V_137 * V_153 )
{
int V_19 ;
V_19 = - V_35 ;
if ( V_106 >= V_107 )
goto V_154;
F_55 () ;
V_19 = - V_155 ;
if ( V_137 [ V_106 ] )
goto V_24;
V_137 [ V_106 ] = V_153 ;
V_19 = 0 ;
V_24:
F_56 () ;
V_154:
return V_19 ;
}
void F_57 ( enum V_152 V_106 )
{
if ( V_106 < V_107 ) {
F_55 () ;
V_137 [ V_106 ] = NULL ;
F_56 () ;
}
}
static int F_58 ( void )
{
int V_154 ;
F_59 ( V_156 L_1 ) ;
V_154 = F_60 ( & V_27 , V_157 ,
F_61 ( V_157 ) ) ;
return V_154 ;
}
static void F_62 ( void )
{
F_63 ( & V_27 ) ;
}
