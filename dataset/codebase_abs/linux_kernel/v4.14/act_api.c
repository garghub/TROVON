static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = V_2 -> V_6 & V_7 ;
if ( ! V_4 )
return - V_8 ;
V_2 -> V_9 = F_2 ( V_4 -> V_10 -> V_11 , V_5 , true ) ;
if ( ! V_2 -> V_9 )
return - V_12 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_9 ) ;
}
static void F_5 ( const struct V_1 * V_2 ,
struct V_13 * V_14 )
{
const struct V_15 * V_10 = V_2 -> V_9 ;
V_14 -> V_16 = F_6 ( V_10 -> V_17 ) ;
}
static void F_7 ( struct V_1 * V_18 )
{
F_8 ( V_18 -> V_19 ) ;
F_8 ( V_18 -> V_20 ) ;
if ( V_18 -> V_21 ) {
F_9 ( V_18 -> V_21 -> V_22 ) ;
F_9 ( V_18 -> V_21 ) ;
}
if ( V_18 -> V_9 )
F_3 ( V_18 ) ;
F_9 ( V_18 ) ;
}
static void F_10 ( struct V_23 * V_24 , struct V_1 * V_18 )
{
F_11 ( & V_24 -> V_25 ) ;
F_12 ( & V_24 -> V_26 , V_18 -> V_27 ) ;
F_13 ( & V_24 -> V_25 ) ;
F_14 ( & V_18 -> V_28 ) ;
F_7 ( V_18 ) ;
}
int F_15 ( struct V_1 * V_18 , bool V_29 , bool V_30 )
{
int V_31 = 0 ;
F_16 () ;
if ( V_18 ) {
if ( V_29 )
V_18 -> V_32 -- ;
else if ( V_30 && V_18 -> V_32 > 0 )
return - V_33 ;
V_18 -> V_34 -- ;
if ( V_18 -> V_32 <= 0 && V_18 -> V_34 <= 0 ) {
if ( V_18 -> V_35 -> V_36 )
V_18 -> V_35 -> V_36 ( V_18 , V_29 ) ;
F_10 ( V_18 -> V_24 , V_18 ) ;
V_31 = V_37 ;
}
}
return V_31 ;
}
static int F_17 ( struct V_23 * V_24 , struct V_38 * V_39 ,
struct V_40 * V_41 )
{
int V_42 = 0 , V_43 = - 1 , V_44 = 0 , V_45 = 0 ;
T_1 V_46 = V_41 -> args [ 2 ] ;
unsigned long V_47 = V_41 -> args [ 3 ] ;
struct V_48 * V_49 ;
struct V_50 * V_50 = & V_24 -> V_26 ;
struct V_1 * V_18 ;
unsigned long V_51 = 1 ;
F_11 ( & V_24 -> V_25 ) ;
V_44 = V_41 -> args [ 0 ] ;
F_18 (idr, p, id) {
V_43 ++ ;
if ( V_43 < V_44 )
continue;
if ( V_47 &&
F_19 ( V_47 ,
( unsigned long ) V_18 -> V_52 . V_53 ) )
continue;
V_49 = F_20 ( V_39 , V_45 ) ;
if ( ! V_49 )
goto V_54;
V_42 = F_21 ( V_39 , V_18 , 0 , 0 ) ;
if ( V_42 < 0 ) {
V_43 -- ;
F_22 ( V_39 , V_49 ) ;
goto V_55;
}
F_23 ( V_39 , V_49 ) ;
V_45 ++ ;
if ( ! ( V_46 & V_56 ) &&
V_45 >= V_57 )
goto V_55;
}
V_55:
if ( V_43 >= 0 )
V_41 -> args [ 0 ] = V_43 + 1 ;
F_13 ( & V_24 -> V_25 ) ;
if ( V_45 ) {
if ( V_46 & V_56 )
V_41 -> args [ 1 ] = V_45 ;
}
return V_45 ;
V_54:
F_24 ( V_39 , V_49 ) ;
goto V_55;
}
static int F_25 ( struct V_23 * V_24 , struct V_38 * V_39 ,
const struct V_58 * V_35 )
{
struct V_48 * V_49 ;
int V_45 = 0 ;
int V_31 = - V_8 ;
struct V_50 * V_50 = & V_24 -> V_26 ;
struct V_1 * V_18 ;
unsigned long V_51 = 1 ;
V_49 = F_20 ( V_39 , 0 ) ;
if ( V_49 == NULL )
goto V_54;
if ( F_26 ( V_39 , V_59 , V_35 -> V_60 ) )
goto V_54;
F_18 (idr, p, id) {
V_31 = F_15 ( V_18 , false , true ) ;
if ( V_31 == V_37 ) {
F_27 ( V_35 -> V_61 ) ;
V_45 ++ ;
} else if ( V_31 < 0 ) {
goto V_54;
}
}
if ( F_28 ( V_39 , V_62 , V_45 ) )
goto V_54;
F_23 ( V_39 , V_49 ) ;
return V_45 ;
V_54:
F_24 ( V_39 , V_49 ) ;
return V_31 ;
}
int F_29 ( struct V_63 * V_64 , struct V_38 * V_39 ,
struct V_40 * V_41 , int type ,
const struct V_58 * V_35 )
{
struct V_23 * V_24 = V_64 -> V_24 ;
if ( type == V_65 ) {
return F_25 ( V_24 , V_39 , V_35 ) ;
} else if ( type == V_66 ) {
return F_17 ( V_24 , V_39 , V_41 ) ;
} else {
F_30 ( 1 , L_1 , type ) ;
return - V_8 ;
}
}
static struct V_1 * F_31 ( T_1 V_43 , struct V_23 * V_24 )
{
struct V_1 * V_18 = NULL ;
F_11 ( & V_24 -> V_25 ) ;
V_18 = F_32 ( & V_24 -> V_26 , V_43 ) ;
F_13 ( & V_24 -> V_25 ) ;
return V_18 ;
}
int F_33 ( struct V_63 * V_64 , struct V_1 * * V_2 , T_1 V_43 )
{
struct V_23 * V_24 = V_64 -> V_24 ;
struct V_1 * V_18 = F_31 ( V_43 , V_24 ) ;
if ( V_18 ) {
* V_2 = V_18 ;
return 1 ;
}
return 0 ;
}
bool F_34 ( struct V_63 * V_64 , T_1 V_43 , struct V_1 * * V_2 ,
int V_29 )
{
struct V_23 * V_24 = V_64 -> V_24 ;
struct V_1 * V_18 = F_31 ( V_43 , V_24 ) ;
if ( V_43 && V_18 ) {
if ( V_29 )
V_18 -> V_32 ++ ;
V_18 -> V_34 ++ ;
* V_2 = V_18 ;
return true ;
}
return false ;
}
void F_35 ( struct V_1 * V_2 , struct V_48 * V_67 )
{
if ( V_67 )
F_14 ( & V_2 -> V_28 ) ;
F_7 ( V_2 ) ;
}
int F_36 ( struct V_63 * V_64 , T_1 V_43 , struct V_48 * V_67 ,
struct V_1 * * V_2 , const struct V_58 * V_35 ,
int V_29 , bool V_68 )
{
struct V_1 * V_18 = F_37 ( V_35 -> V_69 , V_70 ) ;
struct V_23 * V_24 = V_64 -> V_24 ;
struct V_50 * V_50 = & V_24 -> V_26 ;
int V_42 = - V_12 ;
unsigned long V_71 ;
if ( F_38 ( ! V_18 ) )
return - V_12 ;
V_18 -> V_34 = 1 ;
if ( V_29 )
V_18 -> V_32 = 1 ;
if ( V_68 ) {
V_18 -> V_19 = F_39 ( struct V_72 ) ;
if ( ! V_18 -> V_19 ) {
V_73:
F_9 ( V_18 ) ;
return V_42 ;
}
V_18 -> V_20 = F_40 ( struct V_74 ) ;
if ( ! V_18 -> V_20 ) {
V_75:
F_8 ( V_18 -> V_19 ) ;
goto V_73;
}
}
F_41 ( & V_18 -> V_76 ) ;
if ( ! V_43 ) {
F_42 ( V_70 ) ;
F_11 ( & V_24 -> V_25 ) ;
V_42 = F_43 ( V_50 , NULL , & V_71 , 1 , 0 ,
V_77 ) ;
F_13 ( & V_24 -> V_25 ) ;
F_44 () ;
if ( V_42 ) {
V_78:
F_8 ( V_18 -> V_20 ) ;
goto V_75;
}
V_18 -> V_27 = V_71 ;
} else {
F_42 ( V_70 ) ;
F_11 ( & V_24 -> V_25 ) ;
V_42 = F_43 ( V_50 , NULL , NULL , V_43 , V_43 + 1 ,
V_77 ) ;
F_13 ( & V_24 -> V_25 ) ;
F_44 () ;
if ( V_42 )
goto V_78;
V_18 -> V_27 = V_43 ;
}
V_18 -> V_52 . V_79 = V_80 ;
V_18 -> V_52 . V_53 = V_80 ;
V_18 -> V_52 . V_81 = 0 ;
if ( V_67 ) {
V_42 = F_45 ( & V_18 -> V_82 , V_18 -> V_19 ,
& V_18 -> V_28 ,
& V_18 -> V_76 , NULL , V_67 ) ;
if ( V_42 ) {
goto V_78;
}
}
V_18 -> V_24 = V_24 ;
V_18 -> V_35 = V_35 ;
F_46 ( & V_18 -> V_83 ) ;
* V_2 = V_18 ;
return 0 ;
}
void F_47 ( struct V_63 * V_64 , struct V_1 * V_2 )
{
struct V_23 * V_24 = V_64 -> V_24 ;
F_11 ( & V_24 -> V_25 ) ;
F_48 ( & V_24 -> V_26 , V_2 , V_2 -> V_27 ) ;
F_13 ( & V_24 -> V_25 ) ;
}
void F_49 ( const struct V_58 * V_35 ,
struct V_23 * V_24 )
{
struct V_50 * V_50 = & V_24 -> V_26 ;
struct V_1 * V_18 ;
int V_31 ;
unsigned long V_51 = 1 ;
F_18 (idr, p, id) {
V_31 = F_15 ( V_18 , false , true ) ;
if ( V_31 == V_37 )
F_27 ( V_35 -> V_61 ) ;
else if ( V_31 < 0 )
return;
}
F_50 ( & V_24 -> V_26 ) ;
}
int F_51 ( struct V_58 * V_84 ,
struct V_85 * V_35 )
{
struct V_58 * V_2 ;
int V_31 ;
if ( ! V_84 -> V_84 || ! V_84 -> V_86 || ! V_84 -> V_87 || ! V_84 -> V_88 || ! V_84 -> V_89 )
return - V_8 ;
V_31 = F_52 ( V_35 ) ;
if ( V_31 )
return V_31 ;
F_53 ( & V_90 ) ;
F_54 (a, &act_base, head) {
if ( V_84 -> type == V_2 -> type || ( strcmp ( V_84 -> V_60 , V_2 -> V_60 ) == 0 ) ) {
F_55 ( & V_90 ) ;
F_56 ( V_35 ) ;
return - V_91 ;
}
}
F_57 ( & V_84 -> V_92 , & V_93 ) ;
F_55 ( & V_90 ) ;
return 0 ;
}
int F_58 ( struct V_58 * V_84 ,
struct V_85 * V_35 )
{
struct V_58 * V_2 ;
int V_42 = - V_94 ;
F_53 ( & V_90 ) ;
F_54 (a, &act_base, head) {
if ( V_2 == V_84 ) {
F_59 ( & V_84 -> V_92 ) ;
V_42 = 0 ;
break;
}
}
F_55 ( & V_90 ) ;
if ( ! V_42 )
F_56 ( V_35 ) ;
return V_42 ;
}
static struct V_58 * F_60 ( char * V_60 )
{
struct V_58 * V_2 , * V_14 = NULL ;
if ( V_60 ) {
F_61 ( & V_90 ) ;
F_54 (a, &act_base, head) {
if ( strcmp ( V_60 , V_2 -> V_60 ) == 0 ) {
if ( F_62 ( V_2 -> V_61 ) )
V_14 = V_2 ;
break;
}
}
F_63 ( & V_90 ) ;
}
return V_14 ;
}
static struct V_58 * F_64 ( struct V_48 * V_60 )
{
struct V_58 * V_2 , * V_14 = NULL ;
if ( V_60 ) {
F_61 ( & V_90 ) ;
F_54 (a, &act_base, head) {
if ( F_65 ( V_60 , V_2 -> V_60 ) == 0 ) {
if ( F_62 ( V_2 -> V_61 ) )
V_14 = V_2 ;
break;
}
}
F_63 ( & V_90 ) ;
}
return V_14 ;
}
int F_66 ( struct V_38 * V_39 , struct V_1 * * V_95 ,
int V_96 , struct V_13 * V_14 )
{
T_1 V_97 = 0 ;
T_1 V_98 = V_57 ;
int V_99 ;
int V_31 = V_100 ;
if ( F_67 ( V_39 ) )
return V_100 ;
V_101:
for ( V_99 = 0 ; V_99 < V_96 ; V_99 ++ ) {
const struct V_1 * V_2 = V_95 [ V_99 ] ;
if ( V_97 > 0 ) {
V_97 -= 1 ;
continue;
}
V_102:
V_31 = V_2 -> V_35 -> V_84 ( V_39 , V_2 , V_14 ) ;
if ( V_31 == V_103 )
goto V_102;
if ( F_68 ( V_31 , V_104 ) ) {
V_97 = V_31 & V_105 ;
if ( ! V_97 || ( V_97 > V_96 ) ) {
return V_100 ;
} else {
V_98 -= 1 ;
if ( V_98 > 0 )
goto V_101;
else
return V_100 ;
}
} else if ( F_68 ( V_31 , V_106 ) ) {
F_5 ( V_2 , V_14 ) ;
}
if ( V_31 != V_107 )
break;
}
return V_31 ;
}
int F_69 ( struct V_108 * V_95 , int V_29 )
{
const struct V_58 * V_35 ;
struct V_1 * V_2 , * V_109 ;
int V_31 = 0 ;
F_70 (a, tmp, actions, list) {
V_35 = V_2 -> V_35 ;
V_31 = F_15 ( V_2 , V_29 , true ) ;
if ( V_31 == V_37 )
F_27 ( V_35 -> V_61 ) ;
else if ( V_31 < 0 )
return V_31 ;
}
return V_31 ;
}
int
F_71 ( struct V_38 * V_39 , struct V_1 * V_2 , int V_29 , int V_110 )
{
return V_2 -> V_35 -> V_86 ( V_39 , V_2 , V_29 , V_110 ) ;
}
int
F_21 ( struct V_38 * V_39 , struct V_1 * V_2 , int V_29 , int V_110 )
{
int V_42 = - V_8 ;
unsigned char * V_111 = F_72 ( V_39 ) ;
struct V_48 * V_49 ;
if ( F_26 ( V_39 , V_59 , V_2 -> V_35 -> V_60 ) )
goto V_54;
if ( F_73 ( V_39 , V_2 , 0 ) )
goto V_54;
if ( V_2 -> V_21 ) {
if ( F_74 ( V_39 , V_112 , V_2 -> V_21 -> V_113 ,
V_2 -> V_21 -> V_22 ) )
goto V_54;
}
V_49 = F_20 ( V_39 , V_114 ) ;
if ( V_49 == NULL )
goto V_54;
V_42 = F_71 ( V_39 , V_2 , V_29 , V_110 ) ;
if ( V_42 > 0 ) {
F_23 ( V_39 , V_49 ) ;
return V_42 ;
}
V_54:
F_22 ( V_39 , V_111 ) ;
return - 1 ;
}
int F_75 ( struct V_38 * V_39 , struct V_108 * V_95 ,
int V_29 , int V_110 )
{
struct V_1 * V_2 ;
int V_42 = - V_8 ;
struct V_48 * V_49 ;
F_54 (a, actions, list) {
V_49 = F_20 ( V_39 , V_2 -> V_115 ) ;
if ( V_49 == NULL )
goto V_54;
V_42 = F_21 ( V_39 , V_2 , V_29 , V_110 ) ;
if ( V_42 < 0 )
goto V_116;
F_23 ( V_39 , V_49 ) ;
}
return 0 ;
V_54:
V_42 = - V_8 ;
V_116:
F_24 ( V_39 , V_49 ) ;
return V_42 ;
}
static struct V_117 * F_76 ( struct V_48 * * V_118 )
{
struct V_117 * V_119 = F_37 ( sizeof( * V_119 ) , V_70 ) ;
if ( ! V_119 )
return NULL ;
V_119 -> V_22 = F_77 ( V_118 [ V_112 ] , V_70 ) ;
if ( ! V_119 -> V_22 ) {
F_9 ( V_119 ) ;
return NULL ;
}
V_119 -> V_113 = F_78 ( V_118 [ V_112 ] ) ;
return V_119 ;
}
struct V_1 * F_79 ( struct V_120 * V_120 , struct V_3 * V_4 ,
struct V_48 * V_121 , struct V_48 * V_67 ,
char * V_122 , int V_123 , int V_29 )
{
struct V_1 * V_2 ;
struct V_58 * V_124 ;
struct V_117 * V_125 = NULL ;
char V_126 [ V_127 ] ;
struct V_48 * V_118 [ V_128 + 1 ] ;
struct V_48 * V_60 ;
int V_42 ;
if ( V_122 == NULL ) {
V_42 = F_80 ( V_118 , V_128 , V_121 , NULL , NULL ) ;
if ( V_42 < 0 )
goto V_129;
V_42 = - V_8 ;
V_60 = V_118 [ V_130 ] ;
if ( V_60 == NULL )
goto V_129;
if ( F_81 ( V_126 , V_60 , V_127 ) >= V_127 )
goto V_129;
if ( V_118 [ V_112 ] ) {
int V_131 = F_78 ( V_118 [ V_112 ] ) ;
if ( V_131 > V_132 )
goto V_129;
V_125 = F_76 ( V_118 ) ;
if ( ! V_125 ) {
V_42 = - V_12 ;
goto V_129;
}
}
} else {
V_42 = - V_8 ;
if ( F_82 ( V_126 , V_122 , V_127 ) >= V_127 )
goto V_129;
}
V_124 = F_60 ( V_126 ) ;
if ( V_124 == NULL ) {
#ifdef F_83
F_84 () ;
F_85 ( L_2 , V_126 ) ;
F_86 () ;
V_124 = F_60 ( V_126 ) ;
if ( V_124 != NULL ) {
V_42 = - V_133 ;
goto V_134;
}
#endif
V_42 = - V_94 ;
goto V_129;
}
if ( V_122 == NULL )
V_42 = V_124 -> V_87 ( V_120 , V_118 [ V_135 ] , V_67 , & V_2 , V_123 , V_29 ) ;
else
V_42 = V_124 -> V_87 ( V_120 , V_121 , V_67 , & V_2 , V_123 , V_29 ) ;
if ( V_42 < 0 )
goto V_134;
if ( V_122 == NULL && V_118 [ V_112 ] ) {
if ( V_2 -> V_21 ) {
F_9 ( V_2 -> V_21 -> V_22 ) ;
F_9 ( V_2 -> V_21 ) ;
}
V_2 -> V_21 = V_125 ;
}
if ( V_42 != V_136 )
F_27 ( V_124 -> V_61 ) ;
if ( F_68 ( V_2 -> V_6 , V_106 ) ) {
V_42 = F_1 ( V_2 , V_4 ) ;
if ( V_42 ) {
F_87 ( V_95 ) ;
F_57 ( & V_2 -> V_83 , & V_95 ) ;
F_69 ( & V_95 , V_29 ) ;
return F_88 ( V_42 ) ;
}
}
return V_2 ;
V_134:
F_27 ( V_124 -> V_61 ) ;
V_129:
if ( V_125 ) {
F_9 ( V_125 -> V_22 ) ;
F_9 ( V_125 ) ;
}
return F_88 ( V_42 ) ;
}
static void F_89 ( struct V_108 * V_95 , int V_123 )
{
struct V_1 * V_2 ;
if ( ! V_123 )
return;
F_54 (a, actions, list)
V_2 -> V_34 -- ;
}
int F_90 ( struct V_120 * V_120 , struct V_3 * V_4 , struct V_48 * V_121 ,
struct V_48 * V_67 , char * V_122 , int V_123 , int V_29 ,
struct V_108 * V_95 )
{
struct V_48 * V_118 [ V_57 + 1 ] ;
struct V_1 * V_84 ;
int V_42 ;
int V_99 ;
V_42 = F_80 ( V_118 , V_57 , V_121 , NULL , NULL ) ;
if ( V_42 < 0 )
return V_42 ;
for ( V_99 = 1 ; V_99 <= V_57 && V_118 [ V_99 ] ; V_99 ++ ) {
V_84 = F_79 ( V_120 , V_4 , V_118 [ V_99 ] , V_67 , V_122 , V_123 , V_29 ) ;
if ( F_91 ( V_84 ) ) {
V_42 = F_92 ( V_84 ) ;
goto V_42;
}
V_84 -> V_115 = V_99 ;
if ( V_123 )
V_84 -> V_34 ++ ;
F_57 ( & V_84 -> V_83 , V_95 ) ;
}
F_89 ( V_95 , V_123 ) ;
return 0 ;
V_42:
F_69 ( V_95 , V_29 ) ;
return V_42 ;
}
int F_73 ( struct V_38 * V_39 , struct V_1 * V_18 ,
int V_137 )
{
int V_42 = 0 ;
struct V_138 V_139 ;
if ( V_18 == NULL )
goto V_116;
if ( V_137 ) {
if ( V_18 -> type == V_140 )
V_42 = F_93 ( V_39 , 0 ,
V_141 ,
V_142 ,
& V_18 -> V_76 , & V_139 ,
V_143 ) ;
else
return 0 ;
} else
V_42 = F_94 ( V_39 , V_144 ,
& V_18 -> V_76 , & V_139 , V_145 ) ;
if ( V_42 < 0 )
goto V_116;
if ( F_95 ( NULL , & V_139 , V_18 -> V_19 , & V_18 -> V_82 ) < 0 ||
F_96 ( & V_139 , & V_18 -> V_28 ) < 0 ||
F_97 ( & V_139 , V_18 -> V_20 ,
& V_18 -> V_146 ,
V_18 -> V_146 . V_147 ) < 0 )
goto V_116;
if ( F_98 ( & V_139 ) < 0 )
goto V_116;
return 0 ;
V_116:
return - 1 ;
}
static int F_99 ( struct V_38 * V_39 , struct V_108 * V_95 ,
T_1 V_148 , T_1 V_149 , T_2 V_150 , int V_151 , int V_29 ,
int V_110 )
{
struct V_152 * V_153 ;
struct V_154 * V_155 ;
unsigned char * V_111 = F_72 ( V_39 ) ;
struct V_48 * V_49 ;
V_155 = F_100 ( V_39 , V_148 , V_149 , V_151 , sizeof( * V_153 ) , V_150 ) ;
if ( ! V_155 )
goto V_156;
V_153 = F_101 ( V_155 ) ;
V_153 -> V_157 = V_158 ;
V_153 -> V_159 = 0 ;
V_153 -> V_160 = 0 ;
V_49 = F_20 ( V_39 , V_161 ) ;
if ( V_49 == NULL )
goto V_156;
if ( F_75 ( V_39 , V_95 , V_29 , V_110 ) < 0 )
goto V_156;
F_23 ( V_39 , V_49 ) ;
V_155 -> V_162 = F_72 ( V_39 ) - V_111 ;
return V_39 -> V_113 ;
V_156:
F_22 ( V_39 , V_111 ) ;
return - 1 ;
}
static int
F_102 ( struct V_120 * V_120 , T_1 V_148 , struct V_154 * V_163 ,
struct V_108 * V_95 , int V_151 )
{
struct V_38 * V_39 ;
V_39 = F_103 ( V_164 , V_70 ) ;
if ( ! V_39 )
return - V_165 ;
if ( F_99 ( V_39 , V_95 , V_148 , V_163 -> V_166 , 0 , V_151 ,
0 , 0 ) <= 0 ) {
F_104 ( V_39 ) ;
return - V_8 ;
}
return F_105 ( V_39 , V_120 , V_148 ) ;
}
static struct V_1 * F_106 ( struct V_120 * V_120 , struct V_48 * V_121 ,
struct V_154 * V_163 , T_1 V_148 )
{
struct V_48 * V_118 [ V_128 + 1 ] ;
const struct V_58 * V_35 ;
struct V_1 * V_2 ;
int V_43 ;
int V_42 ;
V_42 = F_80 ( V_118 , V_128 , V_121 , NULL , NULL ) ;
if ( V_42 < 0 )
goto V_129;
V_42 = - V_8 ;
if ( V_118 [ V_167 ] == NULL ||
F_78 ( V_118 [ V_167 ] ) < sizeof( V_43 ) )
goto V_129;
V_43 = F_107 ( V_118 [ V_167 ] ) ;
V_42 = - V_8 ;
V_35 = F_64 ( V_118 [ V_130 ] ) ;
if ( ! V_35 )
goto V_129;
V_42 = - V_94 ;
if ( V_35 -> V_89 ( V_120 , & V_2 , V_43 ) == 0 )
goto V_134;
F_27 ( V_35 -> V_61 ) ;
return V_2 ;
V_134:
F_27 ( V_35 -> V_61 ) ;
V_129:
return F_88 ( V_42 ) ;
}
static int F_108 ( struct V_120 * V_120 , struct V_48 * V_121 ,
struct V_154 * V_163 , T_1 V_148 )
{
struct V_38 * V_39 ;
unsigned char * V_111 ;
struct V_154 * V_155 ;
struct V_152 * V_153 ;
struct V_40 V_168 ;
struct V_48 * V_49 ;
struct V_48 * V_118 [ V_128 + 1 ] ;
const struct V_58 * V_35 ;
struct V_48 * V_60 ;
int V_42 = - V_12 ;
V_39 = F_103 ( V_164 , V_70 ) ;
if ( ! V_39 ) {
F_109 ( L_3 ) ;
return V_42 ;
}
V_111 = F_72 ( V_39 ) ;
V_42 = F_80 ( V_118 , V_128 , V_121 , NULL , NULL ) ;
if ( V_42 < 0 )
goto V_129;
V_42 = - V_8 ;
V_60 = V_118 [ V_130 ] ;
V_35 = F_64 ( V_60 ) ;
if ( ! V_35 )
goto V_129;
V_155 = F_100 ( V_39 , V_148 , V_163 -> V_166 , V_65 ,
sizeof( * V_153 ) , 0 ) ;
if ( ! V_155 )
goto V_169;
V_153 = F_101 ( V_155 ) ;
V_153 -> V_157 = V_158 ;
V_153 -> V_159 = 0 ;
V_153 -> V_160 = 0 ;
V_49 = F_20 ( V_39 , V_161 ) ;
if ( V_49 == NULL )
goto V_169;
V_42 = V_35 -> V_88 ( V_120 , V_39 , & V_168 , V_65 , V_35 ) ;
if ( V_42 <= 0 )
goto V_169;
F_23 ( V_39 , V_49 ) ;
V_155 -> V_162 = F_72 ( V_39 ) - V_111 ;
V_155 -> V_170 |= V_171 ;
F_27 ( V_35 -> V_61 ) ;
V_42 = F_110 ( V_39 , V_120 , V_148 , V_172 ,
V_163 -> V_170 & V_173 ) ;
if ( V_42 > 0 )
return 0 ;
return V_42 ;
V_169:
F_27 ( V_35 -> V_61 ) ;
V_129:
F_104 ( V_39 ) ;
return V_42 ;
}
static int
F_111 ( struct V_120 * V_120 , struct V_154 * V_163 , struct V_108 * V_95 ,
T_1 V_148 )
{
int V_31 ;
struct V_38 * V_39 ;
V_39 = F_103 ( V_164 , V_70 ) ;
if ( ! V_39 )
return - V_165 ;
if ( F_99 ( V_39 , V_95 , V_148 , V_163 -> V_166 , 0 , V_65 ,
0 , 1 ) <= 0 ) {
F_104 ( V_39 ) ;
return - V_8 ;
}
V_31 = F_69 ( V_95 , 0 ) ;
if ( V_31 < 0 ) {
F_104 ( V_39 ) ;
return V_31 ;
}
V_31 = F_110 ( V_39 , V_120 , V_148 , V_172 ,
V_163 -> V_170 & V_173 ) ;
if ( V_31 > 0 )
return 0 ;
return V_31 ;
}
static int
F_112 ( struct V_120 * V_120 , struct V_48 * V_121 , struct V_154 * V_163 ,
T_1 V_148 , int V_151 )
{
int V_99 , V_31 ;
struct V_48 * V_118 [ V_57 + 1 ] ;
struct V_1 * V_84 ;
F_87 ( V_95 ) ;
V_31 = F_80 ( V_118 , V_57 , V_121 , NULL , NULL ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_151 == V_65 && V_163 -> V_170 & V_171 ) {
if ( V_118 [ 1 ] != NULL )
return F_108 ( V_120 , V_118 [ 1 ] , V_163 , V_148 ) ;
else
return - V_8 ;
}
for ( V_99 = 1 ; V_99 <= V_57 && V_118 [ V_99 ] ; V_99 ++ ) {
V_84 = F_106 ( V_120 , V_118 [ V_99 ] , V_163 , V_148 ) ;
if ( F_91 ( V_84 ) ) {
V_31 = F_92 ( V_84 ) ;
goto V_42;
}
V_84 -> V_115 = V_99 ;
F_57 ( & V_84 -> V_83 , & V_95 ) ;
}
if ( V_151 == V_66 )
V_31 = F_102 ( V_120 , V_148 , V_163 , & V_95 , V_151 ) ;
else {
V_31 = F_111 ( V_120 , V_163 , & V_95 , V_148 ) ;
if ( V_31 )
goto V_42;
return V_31 ;
}
V_42:
if ( V_151 != V_66 )
F_69 ( & V_95 , 0 ) ;
return V_31 ;
}
static int
F_113 ( struct V_120 * V_120 , struct V_154 * V_163 , struct V_108 * V_95 ,
T_1 V_148 )
{
struct V_38 * V_39 ;
int V_42 = 0 ;
V_39 = F_103 ( V_164 , V_70 ) ;
if ( ! V_39 )
return - V_165 ;
if ( F_99 ( V_39 , V_95 , V_148 , V_163 -> V_166 , V_163 -> V_170 ,
V_174 , 0 , 0 ) <= 0 ) {
F_104 ( V_39 ) ;
return - V_8 ;
}
V_42 = F_110 ( V_39 , V_120 , V_148 , V_172 ,
V_163 -> V_170 & V_173 ) ;
if ( V_42 > 0 )
V_42 = 0 ;
return V_42 ;
}
static int F_114 ( struct V_120 * V_120 , struct V_48 * V_121 ,
struct V_154 * V_163 , T_1 V_148 , int V_123 )
{
int V_31 = 0 ;
F_87 ( V_95 ) ;
V_31 = F_90 ( V_120 , NULL , V_121 , NULL , NULL , V_123 , 0 , & V_95 ) ;
if ( V_31 )
return V_31 ;
return F_113 ( V_120 , V_163 , & V_95 , V_148 ) ;
}
static int F_115 ( struct V_38 * V_39 , struct V_154 * V_163 ,
struct V_175 * V_176 )
{
struct V_120 * V_120 = F_116 ( V_39 -> V_177 ) ;
struct V_48 * V_178 [ V_179 + 1 ] ;
T_1 V_148 = V_39 ? F_117 ( V_39 ) . V_148 : 0 ;
int V_31 = 0 , V_123 = 0 ;
if ( ( V_163 -> V_180 != V_66 ) &&
! F_118 ( V_39 , V_181 ) )
return - V_33 ;
V_31 = F_119 ( V_163 , sizeof( struct V_152 ) , V_178 , V_179 , NULL ,
V_176 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_178 [ V_161 ] == NULL ) {
F_120 ( L_4 ) ;
return - V_8 ;
}
switch ( V_163 -> V_180 ) {
case V_174 :
if ( V_163 -> V_170 & V_182 )
V_123 = 1 ;
V_183:
V_31 = F_114 ( V_120 , V_178 [ V_161 ] , V_163 , V_148 , V_123 ) ;
if ( V_31 == - V_133 )
goto V_183;
break;
case V_65 :
V_31 = F_112 ( V_120 , V_178 [ V_161 ] , V_163 ,
V_148 , V_65 ) ;
break;
case V_66 :
V_31 = F_112 ( V_120 , V_178 [ V_161 ] , V_163 ,
V_148 , V_66 ) ;
break;
default:
F_121 () ;
}
return V_31 ;
}
static struct V_48 * F_122 ( struct V_48 * * V_121 )
{
struct V_48 * V_184 , * V_185 [ V_128 + 1 ] ;
struct V_48 * V_118 [ V_57 + 1 ] ;
struct V_48 * V_60 ;
V_184 = V_121 [ V_161 ] ;
if ( V_184 == NULL )
return NULL ;
if ( F_123 ( V_118 , V_57 , F_124 ( V_184 ) ,
F_125 ( F_78 ( V_184 ) ) , NULL , NULL ) < 0 )
return NULL ;
if ( V_118 [ 1 ] == NULL )
return NULL ;
if ( F_80 ( V_185 , V_128 , V_118 [ 1 ] , NULL , NULL ) < 0 )
return NULL ;
V_60 = V_185 [ V_130 ] ;
return V_60 ;
}
static int F_126 ( struct V_38 * V_39 , struct V_40 * V_41 )
{
struct V_120 * V_120 = F_116 ( V_39 -> V_177 ) ;
struct V_154 * V_155 ;
unsigned char * V_111 = F_72 ( V_39 ) ;
struct V_48 * V_49 ;
struct V_58 * V_124 ;
int V_31 = 0 ;
struct V_152 * V_153 = (struct V_152 * ) F_101 ( V_41 -> V_155 ) ;
struct V_48 * V_118 [ V_179 + 1 ] ;
struct V_48 * V_186 = NULL ;
unsigned long V_47 = 0 ;
struct V_48 * V_60 = NULL ;
struct V_187 V_188 ;
T_1 V_189 = 0 ;
T_1 V_190 = 0 ;
V_31 = F_119 ( V_41 -> V_155 , sizeof( struct V_152 ) , V_118 , V_179 ,
V_191 , NULL ) ;
if ( V_31 < 0 )
return V_31 ;
V_60 = F_122 ( V_118 ) ;
if ( V_60 == NULL ) {
F_127 ( L_5 ) ;
return 0 ;
}
V_124 = F_64 ( V_60 ) ;
if ( V_124 == NULL )
return 0 ;
V_41 -> args [ 2 ] = 0 ;
if ( V_118 [ V_192 ] ) {
V_188 = F_128 ( V_118 [ V_192 ] ) ;
V_41 -> args [ 2 ] = V_188 . V_193 ;
}
if ( V_118 [ V_194 ] ) {
V_189 = F_107 ( V_118 [ V_194 ] ) ;
}
V_155 = F_100 ( V_39 , F_117 ( V_41 -> V_39 ) . V_148 , V_41 -> V_155 -> V_166 ,
V_41 -> V_155 -> V_180 , sizeof( * V_153 ) , 0 ) ;
if ( ! V_155 )
goto V_169;
if ( V_189 )
V_47 = V_80 - F_129 ( V_189 ) ;
V_153 = F_101 ( V_155 ) ;
V_153 -> V_157 = V_158 ;
V_153 -> V_159 = 0 ;
V_153 -> V_160 = 0 ;
V_41 -> args [ 3 ] = V_47 ;
V_186 = F_130 ( V_39 , V_195 , sizeof( T_1 ) ) ;
if ( ! V_186 )
goto V_169;
V_49 = F_20 ( V_39 , V_161 ) ;
if ( V_49 == NULL )
goto V_169;
V_31 = V_124 -> V_88 ( V_120 , V_39 , V_41 , V_66 , V_124 ) ;
if ( V_31 < 0 )
goto V_169;
if ( V_31 > 0 ) {
F_23 ( V_39 , V_49 ) ;
V_31 = V_39 -> V_113 ;
V_190 = V_41 -> args [ 1 ] ;
memcpy ( F_124 ( V_186 ) , & V_190 , sizeof( T_1 ) ) ;
V_41 -> args [ 1 ] = 0 ;
} else
F_22 ( V_39 , V_111 ) ;
V_155 -> V_162 = F_72 ( V_39 ) - V_111 ;
if ( F_117 ( V_41 -> V_39 ) . V_148 && V_31 )
V_155 -> V_170 |= V_196 ;
F_27 ( V_124 -> V_61 ) ;
return V_39 -> V_113 ;
V_169:
F_27 ( V_124 -> V_61 ) ;
F_22 ( V_39 , V_111 ) ;
return V_39 -> V_113 ;
}
static int T_3 F_131 ( void )
{
F_132 ( V_197 , V_174 , F_115 , NULL , 0 ) ;
F_132 ( V_197 , V_65 , F_115 , NULL , 0 ) ;
F_132 ( V_197 , V_66 , F_115 , F_126 ,
0 ) ;
return 0 ;
}
