static long F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
long V_8 = - V_9 ;
V_4 -> V_10 = ( void V_11 * ) F_2 ( - V_9 ) ;
if ( F_3 ( V_6 , true ) != 0 )
return V_8 ;
V_8 = F_4 ( V_2 , V_4 ) ;
if ( V_8 < 0 ) {
V_4 -> V_10 = ( void V_11 * ) F_2 ( V_8 ) ;
F_5 ( V_6 ) ;
return V_8 ;
}
return V_8 ;
}
static void F_6 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_7 ( V_4 -> V_10 ) )
return;
F_5 ( V_2 -> V_7 ) ;
}
struct V_12 * F_8 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_12 * V_12 = F_9 ( V_14 , 0 ) ;
struct V_3 V_4 = {
. V_15 = V_16 ,
. V_17 = V_13 & ~ ( ( ( ( int ) V_16 ) / 512 ) - 1 ) ,
} ;
long V_8 ;
if ( ! V_12 )
return F_2 ( - V_18 ) ;
V_8 = F_1 ( V_2 , & V_4 ) ;
if ( V_8 < 0 )
return F_2 ( V_8 ) ;
F_10 ( F_11 ( V_12 ) , V_4 . V_10 , V_16 ) ;
F_6 ( V_2 , & V_4 ) ;
return V_12 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_19 , long V_20 )
{
struct V_3 V_4 = {
. V_17 = V_19 ,
. V_15 = V_20 ,
} ;
F_13 () ;
do {
long V_21 , V_22 ;
V_21 = F_1 ( V_2 , & V_4 ) ;
if ( V_21 < 0 )
return V_21 ;
V_22 = F_14 ( long , V_21 , V_23 ) ;
F_15 ( V_4 . V_10 , V_22 ) ;
V_4 . V_15 -= V_22 ;
V_4 . V_17 += V_22 / 512 ;
F_6 ( V_2 , & V_4 ) ;
F_16 () ;
} while ( V_4 . V_15 );
F_17 () ;
return 0 ;
}
static void F_18 ( void V_11 * V_10 , unsigned V_15 , unsigned V_24 ,
T_2 V_25 , T_2 V_26 )
{
T_2 V_27 = V_26 - V_25 + V_24 ;
if ( V_24 > 0 )
F_15 ( V_10 , V_24 ) ;
if ( V_27 < V_15 )
F_15 ( V_10 + V_27 , V_15 - V_27 ) ;
}
static bool F_19 ( struct V_28 * V_29 )
{
return F_20 ( V_29 ) && ! F_21 ( V_29 ) ;
}
static bool F_22 ( struct V_28 * V_29 )
{
return V_29 -> V_30 != 0 ;
}
static T_1 F_23 ( const struct V_28 * V_29 ,
const struct V_31 * V_31 )
{
T_1 V_17 = V_29 -> V_32 << ( V_31 -> V_33 - 9 ) ;
return V_17 ;
}
static T_3 F_24 ( struct V_31 * V_31 , struct V_34 * V_35 ,
T_2 V_36 , T_2 V_26 , T_4 V_37 ,
struct V_28 * V_29 )
{
T_2 V_25 = V_36 , V_38 = V_36 , V_39 = V_36 ;
bool V_40 = false , V_41 = false ;
struct V_1 * V_2 = NULL ;
int V_42 = F_25 ( V_35 ) , V_8 ;
long V_43 = 0 ;
struct V_3 V_4 = {
. V_10 = ( void V_11 * ) F_2 ( - V_9 ) ,
} ;
if ( V_42 == V_44 )
V_26 = F_26 ( V_26 , F_27 ( V_31 ) ) ;
while ( V_25 < V_26 ) {
T_5 V_45 ;
if ( V_25 == V_38 ) {
unsigned V_46 = V_31 -> V_33 ;
long V_12 = V_25 >> V_47 ;
T_1 V_48 = V_12 << ( V_47 - V_46 ) ;
unsigned V_24 = V_25 - ( V_48 << V_46 ) ;
long V_15 ;
if ( V_25 == V_39 ) {
V_29 -> V_49 = F_28 ( V_26 - V_25 ) ;
V_29 -> V_30 = 0 ;
V_8 = V_37 ( V_31 , V_48 , V_29 , V_42 == V_50 ) ;
if ( V_8 )
break;
if ( ! F_22 ( V_29 ) )
V_29 -> V_49 = 1 << V_46 ;
V_39 = V_25 - V_24 + V_29 -> V_49 ;
V_2 = V_29 -> V_51 ;
} else {
unsigned V_52 = V_29 -> V_49 -
( V_39 - ( V_25 - V_24 ) ) ;
V_29 -> V_32 += V_52 >> V_46 ;
V_29 -> V_49 -= V_52 ;
}
V_40 = V_42 == V_44 && ! F_19 ( V_29 ) ;
if ( V_40 ) {
V_15 = V_29 -> V_49 - V_24 ;
} else {
F_6 ( V_2 , & V_4 ) ;
V_4 . V_17 = F_23 ( V_29 , V_31 ) ;
V_4 . V_15 = V_29 -> V_49 ;
V_43 = F_1 ( V_2 , & V_4 ) ;
if ( V_43 < 0 ) {
V_8 = V_43 ;
break;
}
if ( F_21 ( V_29 ) || F_29 ( V_29 ) ) {
F_18 ( V_4 . V_10 , V_43 , V_24 ,
V_25 , V_26 ) ;
V_41 = true ;
}
V_4 . V_10 += V_24 ;
V_15 = V_43 - V_24 ;
}
V_38 = F_26 ( V_25 + V_15 , V_26 ) ;
}
if ( F_25 ( V_35 ) == V_50 ) {
V_45 = F_30 ( V_4 . V_10 , V_38 - V_25 , V_35 ) ;
V_41 = true ;
} else if ( ! V_40 )
V_45 = F_31 ( ( void V_53 * ) V_4 . V_10 , V_38 - V_25 ,
V_35 ) ;
else
V_45 = F_32 ( V_38 - V_25 , V_35 ) ;
if ( ! V_45 ) {
V_8 = - V_54 ;
break;
}
V_25 += V_45 ;
if ( ! F_7 ( V_4 . V_10 ) )
V_4 . V_10 += V_45 ;
}
if ( V_41 )
F_17 () ;
F_6 ( V_2 , & V_4 ) ;
return ( V_25 == V_36 ) ? V_8 : V_25 - V_36 ;
}
T_3 F_33 ( struct V_55 * V_56 , struct V_31 * V_31 ,
struct V_34 * V_35 , T_2 V_25 , T_4 V_37 ,
T_6 V_57 , int V_58 )
{
struct V_28 V_29 ;
T_3 V_59 = - V_60 ;
T_2 V_26 = V_25 + F_34 ( V_35 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_51 = V_31 -> V_61 -> V_62 ;
if ( ( V_58 & V_63 ) && F_25 ( V_35 ) == V_44 ) {
struct V_64 * V_65 = V_31 -> V_66 ;
F_35 ( V_31 ) ;
V_59 = F_36 ( V_65 , V_25 , V_26 - 1 ) ;
if ( V_59 ) {
F_37 ( V_31 ) ;
goto V_67;
}
}
if ( ! ( V_58 & V_68 ) )
F_38 ( V_31 ) ;
V_59 = F_24 ( V_31 , V_35 , V_25 , V_26 , V_37 , & V_29 ) ;
if ( ( V_58 & V_63 ) && F_25 ( V_35 ) == V_44 )
F_37 ( V_31 ) ;
if ( ( V_59 > 0 ) && V_57 )
V_57 ( V_56 , V_25 , V_59 , V_29 . V_69 ) ;
if ( ! ( V_58 & V_68 ) )
F_39 ( V_31 ) ;
V_67:
return V_59 ;
}
static int F_40 ( struct V_64 * V_65 , struct V_12 * V_12 ,
struct V_70 * V_71 )
{
unsigned long V_15 ;
struct V_31 * V_31 = V_65 -> V_72 ;
if ( ! V_12 )
V_12 = F_41 ( V_65 , V_71 -> V_73 ,
V_14 | V_74 ) ;
if ( ! V_12 )
return V_75 ;
V_15 = ( F_27 ( V_31 ) + V_16 - 1 ) >> V_47 ;
if ( V_71 -> V_73 >= V_15 ) {
F_42 ( V_12 ) ;
F_43 ( V_12 ) ;
return V_76 ;
}
V_71 -> V_12 = V_12 ;
return V_77 ;
}
static int F_44 ( struct V_12 * V_78 , struct V_31 * V_31 ,
struct V_28 * V_29 , unsigned long V_79 )
{
struct V_3 V_4 = {
. V_17 = F_23 ( V_29 , V_31 ) ,
. V_15 = V_29 -> V_49 ,
} ;
struct V_1 * V_2 = V_29 -> V_51 ;
void * V_80 ;
if ( F_1 ( V_2 , & V_4 ) < 0 )
return F_45 ( V_4 . V_10 ) ;
V_80 = F_46 ( V_78 ) ;
F_47 ( V_80 , ( void V_53 * ) V_4 . V_10 , V_79 , V_78 ) ;
F_48 ( V_80 ) ;
F_6 ( V_2 , & V_4 ) ;
return 0 ;
}
static int F_49 ( struct V_64 * V_65 , T_7 V_81 ,
T_1 V_17 , bool V_82 , bool V_83 )
{
struct V_84 * V_85 = & V_65 -> V_85 ;
T_7 V_86 = F_50 ( V_81 ) ;
int type , error = 0 ;
void * V_87 ;
F_51 ( V_82 && ! V_83 ) ;
if ( V_83 )
F_52 ( V_65 -> V_72 , V_88 ) ;
F_53 ( & V_65 -> V_89 ) ;
V_87 = F_54 ( V_85 , V_86 ) ;
if ( V_87 && F_55 ( V_87 ) == V_90 ) {
V_81 = V_86 ;
goto V_83;
}
V_87 = F_54 ( V_85 , V_81 ) ;
if ( V_87 ) {
type = F_55 ( V_87 ) ;
if ( F_51 ( type != V_91 &&
type != V_90 ) ) {
error = - V_9 ;
goto V_92;
}
if ( ! V_82 || type == V_90 )
goto V_83;
F_56 ( & V_65 -> V_85 , V_81 ) ;
V_65 -> V_93 -- ;
}
if ( V_17 == V_94 ) {
goto V_92;
}
error = F_57 ( V_85 , V_81 ,
F_58 ( V_17 , V_82 ) ) ;
if ( error )
goto V_92;
V_65 -> V_93 ++ ;
V_83:
if ( V_83 )
F_59 ( V_85 , V_81 , V_95 ) ;
V_92:
F_60 ( & V_65 -> V_89 ) ;
return error ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_64 * V_65 , T_7 V_81 , void * V_87 )
{
struct V_84 * V_85 = & V_65 -> V_85 ;
int type = F_55 ( V_87 ) ;
struct V_96 * V_97 ;
struct V_3 V_4 ;
void * * V_98 ;
int V_99 = 0 ;
F_53 ( & V_65 -> V_89 ) ;
if ( ! F_62 ( V_85 , V_81 , & V_97 , & V_98 ) )
goto V_92;
if ( * V_98 != V_87 )
goto V_92;
if ( ! F_63 ( V_85 , V_81 , V_100 ) )
goto V_92;
if ( F_51 ( type != V_91 && type != V_90 ) ) {
V_99 = - V_9 ;
goto V_92;
}
V_4 . V_17 = F_64 ( V_87 ) ;
V_4 . V_15 = ( type == V_90 ? V_101 : V_16 ) ;
F_60 ( & V_65 -> V_89 ) ;
V_99 = F_1 ( V_2 , & V_4 ) ;
if ( V_99 < 0 )
return V_99 ;
if ( F_51 ( V_99 < V_4 . V_15 ) ) {
V_99 = - V_9 ;
goto V_102;
}
F_65 ( V_4 . V_10 , V_4 . V_15 ) ;
F_53 ( & V_65 -> V_89 ) ;
F_66 ( V_85 , V_81 , V_100 ) ;
F_60 ( & V_65 -> V_89 ) ;
V_102:
F_6 ( V_2 , & V_4 ) ;
return V_99 ;
V_92:
F_60 ( & V_65 -> V_89 ) ;
return V_99 ;
}
int F_67 ( struct V_64 * V_65 ,
struct V_1 * V_2 , struct V_103 * V_104 )
{
struct V_31 * V_31 = V_65 -> V_72 ;
T_7 V_105 , V_106 , V_86 ;
T_7 V_107 [ V_108 ] ;
struct V_109 V_110 ;
bool V_52 = false ;
int V_111 , V_99 = 0 ;
void * V_87 ;
if ( F_51 ( V_31 -> V_33 != V_47 ) )
return - V_9 ;
if ( ! V_65 -> V_93 || V_104 -> V_112 != V_113 )
return 0 ;
V_105 = V_104 -> V_114 >> V_115 ;
V_106 = V_104 -> V_116 >> V_115 ;
V_86 = F_50 ( V_105 ) ;
F_68 () ;
V_87 = F_54 ( & V_65 -> V_85 , V_86 ) ;
F_69 () ;
if ( V_87 && F_55 ( V_87 ) == V_90 )
V_105 = V_86 ;
F_70 ( V_65 , V_105 , V_106 ) ;
F_71 ( & V_110 , 0 ) ;
while ( ! V_52 ) {
V_110 . V_117 = F_72 ( V_65 , V_105 ,
V_100 , V_108 ,
V_110 . V_118 , V_107 ) ;
if ( V_110 . V_117 == 0 )
break;
for ( V_111 = 0 ; V_111 < V_110 . V_117 ; V_111 ++ ) {
if ( V_107 [ V_111 ] > V_106 ) {
V_52 = true ;
break;
}
V_99 = F_61 ( V_2 , V_65 , V_107 [ V_111 ] ,
V_110 . V_118 [ V_111 ] ) ;
if ( V_99 < 0 )
return V_99 ;
}
}
F_17 () ;
return 0 ;
}
static int F_73 ( struct V_31 * V_31 , struct V_28 * V_29 ,
struct V_119 * V_120 , struct V_70 * V_71 )
{
unsigned long V_79 = ( unsigned long ) V_71 -> V_121 ;
struct V_64 * V_65 = V_31 -> V_66 ;
struct V_1 * V_2 = V_29 -> V_51 ;
struct V_3 V_4 = {
. V_17 = F_23 ( V_29 , V_31 ) ,
. V_15 = V_29 -> V_49 ,
} ;
T_7 V_15 ;
int error ;
F_74 ( V_65 ) ;
V_15 = ( F_27 ( V_31 ) + V_16 - 1 ) >> V_47 ;
if ( F_75 ( V_71 -> V_73 >= V_15 ) ) {
error = - V_9 ;
goto V_67;
}
if ( F_1 ( V_2 , & V_4 ) < 0 ) {
error = F_45 ( V_4 . V_10 ) ;
goto V_67;
}
if ( F_21 ( V_29 ) || F_29 ( V_29 ) ) {
F_15 ( V_4 . V_10 , V_16 ) ;
F_17 () ;
}
F_6 ( V_2 , & V_4 ) ;
error = F_49 ( V_65 , V_71 -> V_73 , V_4 . V_17 , false ,
V_71 -> V_58 & V_122 ) ;
if ( error )
goto V_67;
error = F_76 ( V_120 , V_79 , V_4 . V_123 ) ;
V_67:
F_77 ( V_65 ) ;
return error ;
}
int F_78 ( struct V_119 * V_120 , struct V_70 * V_71 ,
T_4 V_37 , T_8 V_124 )
{
struct V_125 * V_125 = V_120 -> V_126 ;
struct V_64 * V_65 = V_125 -> V_127 ;
struct V_31 * V_31 = V_65 -> V_72 ;
struct V_12 * V_12 ;
struct V_28 V_29 ;
unsigned long V_79 = ( unsigned long ) V_71 -> V_121 ;
unsigned V_46 = V_31 -> V_33 ;
T_1 V_48 ;
T_7 V_15 ;
int error ;
int V_128 = 0 ;
V_15 = ( F_27 ( V_31 ) + V_16 - 1 ) >> V_47 ;
if ( V_71 -> V_73 >= V_15 )
return V_76 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_48 = ( T_1 ) V_71 -> V_73 << ( V_47 - V_46 ) ;
V_29 . V_51 = V_31 -> V_61 -> V_62 ;
V_29 . V_49 = V_16 ;
V_129:
V_12 = F_79 ( V_65 , V_71 -> V_73 ) ;
if ( V_12 ) {
if ( ! F_80 ( V_12 , V_120 -> V_130 , V_71 -> V_58 ) ) {
F_43 ( V_12 ) ;
return V_131 ;
}
if ( F_75 ( V_12 -> V_65 != V_65 ) ) {
F_42 ( V_12 ) ;
F_43 ( V_12 ) ;
goto V_129;
}
V_15 = ( F_27 ( V_31 ) + V_16 - 1 ) >> V_47 ;
if ( F_75 ( V_71 -> V_73 >= V_15 ) ) {
error = - V_9 ;
goto F_42;
}
}
error = V_37 ( V_31 , V_48 , & V_29 , 0 ) ;
if ( ! error && ( V_29 . V_49 < V_16 ) )
error = - V_9 ;
if ( error )
goto F_42;
if ( ! F_20 ( & V_29 ) && ! F_21 ( & V_29 ) && ! V_71 -> V_132 ) {
if ( V_71 -> V_58 & V_122 ) {
error = V_37 ( V_31 , V_48 , & V_29 , 1 ) ;
F_81 ( V_133 ) ;
F_82 ( V_120 -> V_130 , V_133 ) ;
V_128 = V_134 ;
if ( ! error && ( V_29 . V_49 < V_16 ) )
error = - V_9 ;
if ( error )
goto F_42;
} else {
return F_40 ( V_65 , V_12 , V_71 ) ;
}
}
if ( V_71 -> V_132 ) {
struct V_12 * V_135 = V_71 -> V_132 ;
if ( F_19 ( & V_29 ) )
error = F_44 ( V_135 , V_31 , & V_29 , V_79 ) ;
else
F_83 ( V_135 , V_79 ) ;
if ( error )
goto F_42;
V_71 -> V_12 = V_12 ;
if ( ! V_12 ) {
F_74 ( V_65 ) ;
V_15 = ( F_27 ( V_31 ) + V_16 - 1 ) >>
V_47 ;
if ( V_71 -> V_73 >= V_15 ) {
F_77 ( V_65 ) ;
error = - V_9 ;
goto V_67;
}
}
return V_77 ;
}
if ( ! V_12 && V_128 )
V_12 = F_84 ( V_65 , V_71 -> V_73 ) ;
if ( V_12 ) {
F_85 ( V_65 , V_71 -> V_73 << V_47 ,
V_136 , 0 ) ;
F_86 ( V_12 ) ;
F_42 ( V_12 ) ;
F_43 ( V_12 ) ;
V_12 = NULL ;
}
error = F_73 ( V_31 , & V_29 , V_120 , V_71 ) ;
if ( F_21 ( & V_29 ) ) {
if ( V_124 )
V_124 ( & V_29 , ! error ) ;
else
F_51 ( ! ( V_71 -> V_58 & V_122 ) ) ;
}
V_67:
if ( error == - V_18 )
return V_75 | V_128 ;
if ( ( error < 0 ) && ( error != - V_137 ) )
return V_76 | V_128 ;
return V_138 | V_128 ;
F_42:
if ( V_12 ) {
F_42 ( V_12 ) ;
F_43 ( V_12 ) ;
}
goto V_67;
}
int F_87 ( struct V_119 * V_120 , struct V_70 * V_71 ,
T_4 V_37 , T_8 V_124 )
{
int V_139 ;
struct V_140 * V_141 = F_88 ( V_120 -> V_126 ) -> V_61 ;
if ( V_71 -> V_58 & V_122 ) {
F_89 ( V_141 ) ;
F_90 ( V_120 -> V_126 ) ;
}
V_139 = F_78 ( V_120 , V_71 , V_37 , V_124 ) ;
if ( V_71 -> V_58 & V_122 )
F_91 ( V_141 ) ;
return V_139 ;
}
static void F_92 ( struct V_28 * V_29 , unsigned long V_142 ,
const char * V_143 , const char * V_144 )
{
if ( V_29 ) {
char V_145 [ V_146 ] ;
F_93 ( V_29 -> V_51 , V_145 ) ;
F_94 ( L_1
L_2 , V_144 , V_147 -> V_148 ,
V_142 , V_145 , V_29 -> V_30 , ( V_149 ) V_29 -> V_32 ,
V_29 -> V_49 , V_143 ) ;
} else {
F_94 ( L_3 , V_144 ,
V_147 -> V_148 , V_142 , V_143 ) ;
}
}
int F_95 ( struct V_119 * V_120 , unsigned long V_142 ,
T_9 * V_150 , unsigned int V_58 , T_4 V_37 ,
T_8 V_124 )
{
struct V_125 * V_125 = V_120 -> V_126 ;
struct V_64 * V_65 = V_125 -> V_127 ;
struct V_31 * V_31 = V_65 -> V_72 ;
struct V_28 V_29 ;
unsigned V_46 = V_31 -> V_33 ;
unsigned long V_151 = V_142 & V_152 ;
bool V_153 = V_58 & V_122 ;
struct V_1 * V_2 ;
T_7 V_15 , V_73 ;
T_1 V_48 ;
int error , V_139 = 0 ;
bool V_154 = false ;
if ( ! F_96 ( V_155 ) )
return V_156 ;
if ( V_153 && ! ( V_120 -> V_157 & V_158 ) ) {
F_97 ( V_120 , V_150 , V_142 ) ;
F_98 ( NULL , V_142 , L_4 ) ;
return V_156 ;
}
if ( V_151 < V_120 -> V_159 ) {
F_98 ( NULL , V_142 , L_5 ) ;
return V_156 ;
}
if ( ( V_151 + V_101 ) > V_120 -> V_160 ) {
F_98 ( NULL , V_142 , L_6 ) ;
return V_156 ;
}
V_73 = F_99 ( V_120 , V_151 ) ;
V_15 = ( F_27 ( V_31 ) + V_16 - 1 ) >> V_47 ;
if ( V_73 >= V_15 )
return V_76 ;
if ( ( V_73 | V_161 ) >= V_15 ) {
F_98 ( NULL , V_142 ,
L_7 ) ;
return V_156 ;
}
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_51 = V_31 -> V_61 -> V_62 ;
V_48 = ( T_1 ) V_73 << ( V_47 - V_46 ) ;
V_29 . V_49 = V_101 ;
if ( V_37 ( V_31 , V_48 , & V_29 , 0 ) != 0 )
return V_76 ;
if ( ! F_20 ( & V_29 ) && V_153 ) {
if ( V_37 ( V_31 , V_48 , & V_29 , 1 ) != 0 )
return V_76 ;
V_154 = true ;
}
V_2 = V_29 . V_51 ;
if ( ! F_22 ( & V_29 ) || V_29 . V_49 < V_101 ) {
F_98 ( & V_29 , V_142 , L_8 ) ;
return V_156 ;
}
if ( V_154 ) {
T_2 V_162 = V_73 << V_47 ;
T_2 V_163 = V_162 + V_101 - 1 ;
F_100 ( V_31 , V_162 , V_163 ) ;
}
F_74 ( V_65 ) ;
V_15 = ( F_27 ( V_31 ) + V_16 - 1 ) >> V_47 ;
if ( V_73 >= V_15 ) {
V_139 = V_76 ;
goto V_67;
}
if ( ( V_73 | V_161 ) >= V_15 ) {
F_98 ( & V_29 , V_142 ,
L_7 ) ;
goto V_164;
}
if ( ! V_153 && ! F_20 ( & V_29 ) && F_101 ( & V_29 ) ) {
T_10 * V_165 ;
T_9 V_87 ;
struct V_12 * V_166 = F_102 () ;
if ( F_75 ( ! V_166 ) ) {
F_98 ( & V_29 , V_142 , L_9 ) ;
goto V_164;
}
V_165 = F_103 ( V_120 -> V_130 , V_150 ) ;
if ( ! F_104 ( * V_150 ) ) {
F_105 ( V_165 ) ;
F_98 ( & V_29 , V_142 , L_10 ) ;
goto V_164;
}
F_106 ( F_107 ( V_2 -> V_167 ) ,
L_11 ,
V_168 , V_147 -> V_148 , V_142 ,
( unsigned long long ) F_23 ( & V_29 , V_31 ) ) ;
V_87 = F_108 ( V_166 , V_120 -> V_169 ) ;
V_87 = F_109 ( V_87 ) ;
F_110 ( V_120 -> V_130 , V_151 , V_150 , V_87 ) ;
V_139 = V_138 ;
F_105 ( V_165 ) ;
} else {
struct V_3 V_4 = {
. V_17 = F_23 ( & V_29 , V_31 ) ,
. V_15 = V_101 ,
} ;
long V_170 = F_1 ( V_2 , & V_4 ) ;
if ( V_170 < 0 ) {
V_139 = V_76 ;
goto V_67;
}
if ( V_170 < V_101 ) {
F_98 ( & V_29 , V_142 , L_12 ) ;
F_6 ( V_2 , & V_4 ) ;
goto V_164;
}
if ( F_111 ( V_4 . V_123 ) & V_161 ) {
F_98 ( & V_29 , V_142 , L_13 ) ;
F_6 ( V_2 , & V_4 ) ;
goto V_164;
}
if ( ! F_112 ( V_4 . V_123 ) ) {
F_6 ( V_2 , & V_4 ) ;
F_98 ( & V_29 , V_142 , L_14 ) ;
goto V_164;
}
if ( F_21 ( & V_29 ) || F_29 ( & V_29 ) ) {
F_15 ( V_4 . V_10 , V_101 ) ;
F_17 () ;
F_81 ( V_133 ) ;
F_82 ( V_120 -> V_130 , V_133 ) ;
V_139 |= V_134 ;
}
F_6 ( V_2 , & V_4 ) ;
if ( V_153 ) {
error = F_49 ( V_65 , V_73 , V_4 . V_17 ,
true , true ) ;
if ( error ) {
F_98 ( & V_29 , V_142 ,
L_15 ) ;
goto V_164;
}
}
F_106 ( F_107 ( V_2 -> V_167 ) ,
L_16 ,
V_168 , V_147 -> V_148 , V_142 ,
F_111 ( V_4 . V_123 ) ,
( unsigned long long ) V_4 . V_17 ) ;
V_139 |= F_113 ( V_120 , V_142 , V_150 ,
V_4 . V_123 , V_153 ) ;
}
V_67:
F_77 ( V_65 ) ;
if ( F_21 ( & V_29 ) )
V_124 ( & V_29 , ! ( V_139 & V_171 ) ) ;
return V_139 ;
V_164:
F_81 ( V_172 ) ;
V_139 = V_156 ;
goto V_67;
}
int F_114 ( struct V_119 * V_120 , unsigned long V_142 ,
T_9 * V_150 , unsigned int V_58 , T_4 V_37 ,
T_8 V_124 )
{
int V_139 ;
struct V_140 * V_141 = F_88 ( V_120 -> V_126 ) -> V_61 ;
if ( V_58 & V_122 ) {
F_89 ( V_141 ) ;
F_90 ( V_120 -> V_126 ) ;
}
V_139 = F_95 ( V_120 , V_142 , V_150 , V_58 , V_37 ,
V_124 ) ;
if ( V_58 & V_122 )
F_91 ( V_141 ) ;
return V_139 ;
}
int F_115 ( struct V_119 * V_120 , struct V_70 * V_71 )
{
struct V_125 * V_125 = V_120 -> V_126 ;
int error ;
error = F_49 ( V_125 -> V_127 , V_71 -> V_73 , V_94 , false ,
true ) ;
if ( error == - V_18 )
return V_75 ;
if ( error )
return V_76 ;
return V_138 ;
}
int F_116 ( struct V_31 * V_31 , T_2 V_173 , unsigned V_170 ,
T_4 V_37 )
{
struct V_28 V_29 ;
T_7 V_81 = V_173 >> V_115 ;
unsigned V_174 = V_173 & ( V_136 - 1 ) ;
int V_175 ;
if ( ! V_170 )
return 0 ;
F_117 ( ( V_174 + V_170 ) > V_136 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_51 = V_31 -> V_61 -> V_62 ;
V_29 . V_49 = V_136 ;
V_175 = V_37 ( V_31 , V_81 , & V_29 , 0 ) ;
if ( V_175 < 0 )
return V_175 ;
if ( F_19 ( & V_29 ) ) {
struct V_1 * V_2 = V_29 . V_51 ;
struct V_3 V_4 = {
. V_17 = F_23 ( & V_29 , V_31 ) ,
. V_15 = V_136 ,
} ;
if ( F_1 ( V_2 , & V_4 ) < 0 )
return F_45 ( V_4 . V_10 ) ;
F_15 ( V_4 . V_10 + V_174 , V_170 ) ;
F_17 () ;
F_6 ( V_2 , & V_4 ) ;
}
return 0 ;
}
int F_118 ( struct V_31 * V_31 , T_2 V_173 , T_4 V_37 )
{
unsigned V_170 = F_119 ( V_173 ) - V_173 ;
return F_116 ( V_31 , V_173 , V_170 , V_37 ) ;
}
