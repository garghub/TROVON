static void F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
unsigned int V_8 = V_7 -> V_9 ;
struct V_6 * V_10 ;
unsigned int V_11 , V_12 ;
for ( V_10 = V_7 , V_11 = 0 ; V_10 != V_7 || ! V_11 ;
V_10 = V_10 -> V_13 , V_11 = V_12 ) {
V_12 = V_11 + V_8 ;
if ( V_12 <= V_4 || V_11 >= V_5 )
continue;
if ( F_3 ( V_2 ) )
F_4 ( V_10 ) ;
F_5 ( V_2 -> V_14 , V_10 ) ;
}
}
static int F_6 ( struct V_15 * V_15 , T_1 V_16 ,
struct V_6 * V_17 , int V_18 )
{
int error ;
error = F_7 ( V_15 , V_16 , V_17 , 0 ) ;
if ( error )
return error ;
if ( ! F_8 ( V_17 ) )
return - V_19 ;
return 0 ;
}
static int F_9 ( struct V_15 * V_15 , T_1 V_16 ,
struct V_6 * V_17 , int V_18 )
{
return F_7 ( V_15 , V_16 , V_17 , 0 ) ;
}
static int F_10 ( struct V_3 * V_3 ,
struct V_20 * V_21 )
{
struct V_15 * V_15 = V_3 -> V_22 -> V_23 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
struct V_24 * V_25 = F_12 ( V_15 ) ;
T_2 V_26 = F_13 ( V_15 ) ;
T_3 V_27 = V_26 >> V_28 ;
unsigned V_29 ;
if ( F_14 ( V_25 , F_15 ( V_2 -> V_14 ) ) )
goto V_30;
if ( V_31 -> V_32 )
goto V_33;
V_29 = V_26 & ( V_34 - 1 ) ;
if ( V_3 -> V_35 > V_27 || ( V_3 -> V_35 == V_27 && ! V_29 ) ) {
V_3 -> V_22 -> V_36 -> V_37 ( V_3 , 0 , V_34 ) ;
goto V_30;
}
return 1 ;
V_33:
F_16 ( V_21 , V_3 ) ;
V_30:
F_17 ( V_3 ) ;
return 0 ;
}
static int F_18 ( struct V_3 * V_3 , struct V_20 * V_21 )
{
int V_38 ;
V_38 = F_10 ( V_3 , V_21 ) ;
if ( V_38 <= 0 )
return V_38 ;
return F_19 ( V_3 , F_6 , V_21 ) ;
}
static int F_20 ( struct V_3 * V_3 , T_4 * V_39 ,
struct V_20 * V_21 )
{
struct V_15 * const V_15 = V_3 -> V_22 -> V_23 ;
T_2 V_26 = F_13 ( V_15 ) ;
const T_3 V_27 = V_26 >> V_28 ;
unsigned V_29 ;
V_29 = V_26 & ( V_34 - 1 ) ;
if ( V_3 -> V_35 == V_27 && V_29 )
F_21 ( V_3 , V_29 , V_34 ) ;
return F_22 ( V_15 , V_3 , V_39 , V_21 ,
V_40 ) ;
}
static int F_23 ( struct V_3 * V_3 , struct V_20 * V_21 )
{
struct V_15 * V_15 = V_3 -> V_22 -> V_23 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
struct V_24 * V_25 = F_12 ( V_15 ) ;
if ( F_24 ( V_3 ) ) {
F_25 ( V_3 ) ;
if ( ! F_26 ( V_3 ) ) {
F_27 ( V_3 , V_15 -> V_41 -> V_42 ,
F_28 ( V_43 ) | F_28 ( V_44 ) ) ;
}
F_1 ( V_2 , V_3 , 0 , V_25 -> V_45 -> V_42 - 1 ) ;
}
return F_20 ( V_3 , F_6 , V_21 ) ;
}
static int F_29 ( struct V_3 * V_3 , struct V_20 * V_21 )
{
struct V_15 * V_15 = V_3 -> V_22 -> V_23 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
struct V_24 * V_25 = F_12 ( V_15 ) ;
int V_38 ;
if ( F_14 ( V_25 , F_15 ( V_2 -> V_14 ) ) )
goto V_30;
if ( F_24 ( V_3 ) || V_31 -> V_32 )
goto V_46;
V_38 = F_23 ( V_3 , V_21 ) ;
return V_38 ;
V_46:
F_16 ( V_21 , V_3 ) ;
V_30:
F_17 ( V_3 ) ;
return 0 ;
}
static int F_30 ( struct V_47 * V_22 ,
struct V_20 * V_21 )
{
struct V_24 * V_25 = F_31 ( V_22 ) ;
int V_38 = F_32 ( V_22 , V_21 , F_6 ) ;
if ( V_38 == 0 )
F_33 ( V_48 , & V_25 -> V_49 ) ;
return V_38 ;
}
static int F_34 ( struct V_47 * V_22 ,
struct V_20 * V_21 ,
struct V_50 * V_51 ,
int V_52 , T_3 V_12 ,
T_3 * V_53 )
{
struct V_15 * V_15 = V_22 -> V_23 ;
struct V_24 * V_25 = F_12 ( V_15 ) ;
unsigned V_54 = V_52 * ( V_34 / V_15 -> V_41 -> V_42 ) ;
int V_55 ;
int V_38 ;
V_38 = F_35 ( V_25 , V_54 , V_54 ) ;
if ( V_38 < 0 )
return V_38 ;
for( V_55 = 0 ; V_55 < V_52 ; V_55 ++ ) {
struct V_3 * V_3 = V_51 -> V_56 [ V_55 ] ;
if ( V_3 -> V_35 > V_12 ) {
V_38 = 1 ;
break;
}
* V_53 = V_3 -> V_35 ;
F_36 ( V_3 ) ;
if ( F_37 ( V_3 -> V_22 != V_22 ) ) {
V_57:
F_17 ( V_3 ) ;
continue;
}
if ( ! F_38 ( V_3 ) ) {
goto V_57;
}
if ( F_39 ( V_3 ) ) {
if ( V_21 -> V_58 != V_59 )
F_40 ( V_3 ) ;
else
goto V_57;
}
F_41 ( F_39 ( V_3 ) ) ;
if ( ! F_42 ( V_3 ) )
goto V_57;
F_43 ( V_21 , F_44 ( V_15 ) ) ;
V_38 = F_23 ( V_3 , V_21 ) ;
if ( F_37 ( V_38 ) ) {
if ( V_38 == V_60 ) {
F_17 ( V_3 ) ;
V_38 = 0 ;
} else {
* V_53 = V_3 -> V_35 + 1 ;
V_38 = 1 ;
break;
}
}
if ( -- V_21 -> V_61 <= 0 && V_21 -> V_58 == V_59 ) {
V_38 = 1 ;
break;
}
}
F_45 ( V_25 ) ;
return V_38 ;
}
static int F_46 ( struct V_47 * V_22 ,
struct V_20 * V_21 )
{
int V_38 = 0 ;
int V_62 = 0 ;
struct V_50 V_51 ;
int V_52 ;
T_3 V_63 ( V_64 ) ;
T_3 V_35 ;
T_3 V_12 ;
T_3 V_53 ;
int V_65 ;
int V_66 = 0 ;
int V_67 ;
F_47 ( & V_51 , 0 ) ;
if ( V_21 -> V_68 ) {
V_64 = V_22 -> V_64 ;
V_35 = V_64 ;
if ( V_35 == 0 )
V_65 = 1 ;
else
V_65 = 0 ;
V_12 = - 1 ;
} else {
V_35 = V_21 -> V_69 >> V_28 ;
V_12 = V_21 -> V_70 >> V_28 ;
if ( V_21 -> V_69 == 0 && V_21 -> V_70 == V_71 )
V_66 = 1 ;
V_65 = 1 ;
}
if ( V_21 -> V_58 == V_72 || V_21 -> V_73 )
V_67 = V_74 ;
else
V_67 = V_75 ;
V_76:
if ( V_21 -> V_58 == V_72 || V_21 -> V_73 )
F_48 ( V_22 , V_35 , V_12 ) ;
V_53 = V_35 ;
while ( ! V_62 && ( V_35 <= V_12 ) ) {
V_52 = F_49 ( & V_51 , V_22 , & V_35 , V_67 ,
F_50 ( V_12 - V_35 , ( T_3 ) V_77 - 1 ) + 1 ) ;
if ( V_52 == 0 )
break;
V_38 = F_34 ( V_22 , V_21 , & V_51 , V_52 , V_12 , & V_53 ) ;
if ( V_38 )
V_62 = 1 ;
if ( V_38 > 0 )
V_38 = 0 ;
F_51 ( & V_51 ) ;
F_52 () ;
}
if ( ! V_65 && ! V_62 ) {
V_65 = 1 ;
V_35 = 0 ;
V_12 = V_64 - 1 ;
goto V_76;
}
if ( V_21 -> V_68 || ( V_66 && V_21 -> V_61 > 0 ) )
V_22 -> V_64 = V_53 ;
return V_38 ;
}
static int F_53 ( struct V_47 * V_22 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = F_11 ( V_22 -> V_23 ) ;
struct V_24 * V_25 = F_12 ( V_22 -> V_23 ) ;
int V_38 ;
V_38 = F_46 ( V_22 , V_21 ) ;
if ( V_38 == 0 && V_21 -> V_58 == V_72 ) {
F_54 ( V_25 , V_2 -> V_14 , V_78 ) ;
V_38 = F_46 ( V_22 , V_21 ) ;
}
return V_38 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_6 * V_79 ;
T_5 V_80 = F_13 ( & V_2 -> V_81 ) ;
void * V_82 ;
int error ;
if ( F_37 ( V_3 -> V_35 ) ) {
F_56 ( V_3 , 0 , V_34 ) ;
F_57 ( V_3 ) ;
return 0 ;
}
error = F_58 ( V_2 , & V_79 ) ;
if ( error )
return error ;
V_82 = F_59 ( V_3 ) ;
if ( V_80 > ( V_79 -> V_9 - sizeof( struct V_83 ) ) )
V_80 = ( V_79 -> V_9 - sizeof( struct V_83 ) ) ;
memcpy ( V_82 , V_79 -> V_84 + sizeof( struct V_83 ) , V_80 ) ;
memset ( V_82 + V_80 , 0 , V_34 - V_80 ) ;
F_60 ( V_82 ) ;
F_61 ( V_3 ) ;
F_62 ( V_79 ) ;
F_57 ( V_3 ) ;
return 0 ;
}
static int F_63 ( void * V_85 , struct V_3 * V_3 )
{
struct V_1 * V_2 = F_11 ( V_3 -> V_22 -> V_23 ) ;
struct V_24 * V_25 = F_12 ( V_3 -> V_22 -> V_23 ) ;
int error ;
if ( F_64 ( V_2 ) ) {
error = F_55 ( V_2 , V_3 ) ;
F_17 ( V_3 ) ;
} else {
error = F_65 ( V_3 , F_7 ) ;
}
if ( F_37 ( F_66 ( V_86 , & V_25 -> V_49 ) ) )
return - V_19 ;
return error ;
}
static int F_67 ( struct V_85 * V_85 , struct V_3 * V_3 )
{
struct V_47 * V_22 = V_3 -> V_22 ;
struct V_1 * V_2 = F_11 ( V_22 -> V_23 ) ;
struct V_87 V_88 ;
int error ;
F_17 ( V_3 ) ;
F_68 ( V_2 -> V_14 , V_89 , 0 , & V_88 ) ;
error = F_69 ( & V_88 ) ;
if ( F_37 ( error ) )
goto V_30;
error = V_90 ;
F_36 ( V_3 ) ;
if ( V_3 -> V_22 == V_22 && ! F_70 ( V_3 ) )
error = F_63 ( V_85 , V_3 ) ;
else
F_17 ( V_3 ) ;
F_71 ( & V_88 ) ;
V_30:
F_72 ( & V_88 ) ;
if ( error && error != V_90 )
F_36 ( V_3 ) ;
return error ;
}
int F_73 ( struct V_1 * V_2 , char * V_91 , T_2 * V_92 ,
unsigned V_93 )
{
struct V_47 * V_22 = V_2 -> V_81 . V_94 ;
unsigned long V_35 = * V_92 / V_34 ;
unsigned V_29 = * V_92 & ( V_34 - 1 ) ;
unsigned V_95 = 0 ;
unsigned V_96 ;
struct V_3 * V_3 ;
void * V_97 ;
do {
V_96 = V_93 - V_95 ;
if ( V_29 + V_93 > V_34 )
V_96 = V_34 - V_29 ;
V_3 = F_74 ( V_22 , V_35 , F_63 , NULL ) ;
if ( F_75 ( V_3 ) )
return F_76 ( V_3 ) ;
V_97 = F_59 ( V_3 ) ;
memcpy ( V_91 + V_95 , V_97 + V_29 , V_96 ) ;
F_60 ( V_97 ) ;
F_77 ( V_3 ) ;
V_95 += V_96 ;
V_35 ++ ;
V_29 = 0 ;
} while( V_95 < V_93 );
( * V_92 ) += V_93 ;
return V_93 ;
}
static int F_78 ( struct V_85 * V_85 , struct V_47 * V_22 ,
struct V_98 * V_56 , unsigned V_52 )
{
struct V_15 * V_15 = V_22 -> V_23 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
struct V_24 * V_25 = F_12 ( V_15 ) ;
struct V_87 V_88 ;
int V_38 ;
F_68 ( V_2 -> V_14 , V_89 , 0 , & V_88 ) ;
V_38 = F_69 ( & V_88 ) ;
if ( F_37 ( V_38 ) )
goto V_99;
if ( ! F_64 ( V_2 ) )
V_38 = F_79 ( V_22 , V_56 , V_52 , F_7 ) ;
F_71 ( & V_88 ) ;
V_99:
F_72 ( & V_88 ) ;
if ( F_37 ( F_66 ( V_86 , & V_25 -> V_49 ) ) )
V_38 = - V_19 ;
return V_38 ;
}
static int F_80 ( struct V_85 * V_85 , struct V_47 * V_22 ,
T_2 V_92 , unsigned V_100 , unsigned V_101 ,
struct V_3 * * V_102 , void * * V_103 )
{
struct V_1 * V_2 = F_11 ( V_22 -> V_23 ) ;
struct V_24 * V_25 = F_12 ( V_22 -> V_23 ) ;
struct V_1 * V_104 = F_11 ( V_25 -> V_105 ) ;
unsigned int V_106 = 0 , V_107 = 0 , V_108 ;
unsigned V_109 = 0 ;
int V_110 ;
int error = 0 ;
T_3 V_35 = V_92 >> V_28 ;
unsigned V_4 = V_92 & ( V_34 - 1 ) ;
struct V_3 * V_3 ;
F_68 ( V_2 -> V_14 , V_111 , 0 , & V_2 -> V_112 ) ;
error = F_69 ( & V_2 -> V_112 ) ;
if ( F_37 ( error ) )
goto V_99;
if ( & V_2 -> V_81 == V_25 -> V_113 ) {
error = F_81 ( V_104 -> V_14 , V_111 ,
V_114 , & V_104 -> V_112 ) ;
if ( F_37 ( error ) ) {
F_71 ( & V_2 -> V_112 ) ;
goto V_99;
}
}
V_110 = F_82 ( V_2 , V_92 , V_100 ) ;
if ( V_110 || F_3 ( V_2 ) )
F_83 ( V_2 , V_100 , & V_106 , & V_107 ) ;
if ( V_110 ) {
struct V_115 V_116 = { . V_117 = 0 , } ;
V_109 = V_106 + V_107 ;
V_116 . V_118 = V_109 ;
error = F_84 ( V_2 , & V_116 ) ;
if ( error )
goto V_119;
error = F_85 ( V_2 , & V_116 ) ;
if ( error )
goto V_120;
}
V_108 = V_121 + V_107 ;
if ( F_3 ( V_2 ) )
V_108 += V_106 ? V_106 : 1 ;
if ( V_107 || V_106 )
V_108 += V_122 + V_123 ;
if ( & V_2 -> V_81 == V_25 -> V_113 )
V_108 += 2 * V_122 ;
if ( V_110 )
V_108 += F_86 ( V_2 , V_109 ) ;
error = F_35 ( V_25 , V_108 ,
V_34 / V_25 -> V_124 . V_125 ) ;
if ( error )
goto V_126;
error = - V_127 ;
V_101 |= V_128 ;
V_3 = F_87 ( V_22 , V_35 , V_101 ) ;
* V_102 = V_3 ;
if ( F_37 ( ! V_3 ) )
goto V_129;
if ( F_64 ( V_2 ) ) {
error = 0 ;
if ( V_92 + V_100 > V_25 -> V_124 . V_125 - sizeof( struct V_83 ) ) {
error = F_88 ( V_2 , V_3 ) ;
if ( error == 0 )
goto V_130;
} else if ( ! F_70 ( V_3 ) ) {
error = F_55 ( V_2 , V_3 ) ;
}
goto V_30;
}
V_130:
error = F_89 ( V_3 , V_4 , V_100 , F_7 ) ;
V_30:
if ( error == 0 )
return 0 ;
F_17 ( V_3 ) ;
F_77 ( V_3 ) ;
F_45 ( V_25 ) ;
if ( V_92 + V_100 > V_2 -> V_81 . V_26 )
F_90 ( & V_2 -> V_81 ) ;
goto V_126;
V_129:
F_45 ( V_25 ) ;
V_126:
if ( V_110 ) {
F_91 ( V_2 ) ;
V_120:
F_92 ( V_2 ) ;
}
V_119:
if ( & V_2 -> V_81 == V_25 -> V_113 ) {
F_71 ( & V_104 -> V_112 ) ;
F_72 ( & V_104 -> V_112 ) ;
}
F_71 ( & V_2 -> V_112 ) ;
V_99:
F_72 ( & V_2 -> V_112 ) ;
return error ;
}
static void F_93 ( struct V_15 * V_15 )
{
struct V_24 * V_25 = V_15 -> V_41 -> V_131 ;
struct V_1 * V_104 = F_11 ( V_25 -> V_105 ) ;
struct V_1 * V_132 = F_11 ( V_25 -> V_133 ) ;
struct V_134 * V_135 = & V_25 -> V_136 ;
struct V_134 * V_137 = & V_25 -> V_138 ;
struct V_6 * V_139 , * V_140 ;
T_5 V_141 , V_142 ;
V_141 = F_94 ( V_25 ) ;
if ( F_58 ( V_104 , & V_139 ) != 0 )
return;
F_95 ( & V_25 -> V_143 ) ;
F_96 ( V_135 , V_139 -> V_84 +
sizeof( struct V_83 ) ) ;
if ( V_141 > ( V_135 -> V_144 + V_137 -> V_144 ) )
V_142 = V_141 - ( V_135 -> V_144 + V_137 -> V_144 ) ;
else
V_142 = 0 ;
F_97 ( & V_25 -> V_143 ) ;
F_98 ( V_25 , L_1 ,
( unsigned long long ) V_142 ) ;
F_99 ( V_25 , V_142 , V_142 , 0 ) ;
if ( F_58 ( V_132 , & V_140 ) != 0 )
goto V_30;
F_100 ( V_25 , V_139 , V_140 ) ;
F_62 ( V_140 ) ;
V_30:
F_62 ( V_139 ) ;
}
static int F_101 ( struct V_15 * V_15 , struct V_6 * V_79 ,
T_2 V_92 , unsigned V_100 , unsigned V_95 ,
struct V_3 * V_3 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
struct V_24 * V_25 = F_12 ( V_15 ) ;
struct V_1 * V_104 = F_11 ( V_25 -> V_105 ) ;
T_5 V_5 = V_92 + V_95 ;
void * V_82 ;
unsigned char * V_91 = V_79 -> V_84 + sizeof( struct V_83 ) ;
F_41 ( ( V_92 + V_100 ) > ( V_79 -> V_9 - sizeof( struct V_83 ) ) ) ;
V_82 = F_59 ( V_3 ) ;
memcpy ( V_91 + V_92 , V_82 + V_92 , V_95 ) ;
F_61 ( V_3 ) ;
F_60 ( V_82 ) ;
F_102 ( ! F_70 ( V_3 ) ) ;
F_17 ( V_3 ) ;
F_77 ( V_3 ) ;
if ( V_95 ) {
if ( V_15 -> V_26 < V_5 )
F_103 ( V_15 , V_5 ) ;
F_104 ( V_15 ) ;
}
if ( V_15 == V_25 -> V_113 ) {
F_93 ( V_15 ) ;
V_25 -> V_145 = 0 ;
}
F_62 ( V_79 ) ;
F_45 ( V_25 ) ;
if ( V_15 == V_25 -> V_113 ) {
F_71 ( & V_104 -> V_112 ) ;
F_72 ( & V_104 -> V_112 ) ;
}
F_71 ( & V_2 -> V_112 ) ;
F_72 ( & V_2 -> V_112 ) ;
return V_95 ;
}
static int F_105 ( struct V_85 * V_85 , struct V_47 * V_22 ,
T_2 V_92 , unsigned V_100 , unsigned V_95 ,
struct V_3 * V_3 , void * V_103 )
{
struct V_15 * V_15 = V_3 -> V_22 -> V_23 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
struct V_24 * V_25 = F_12 ( V_15 ) ;
struct V_1 * V_104 = F_11 ( V_25 -> V_105 ) ;
struct V_6 * V_79 ;
unsigned int V_4 = V_92 & ( V_34 - 1 ) ;
unsigned int V_5 = V_4 + V_100 ;
int V_38 ;
struct V_146 * V_147 = V_31 -> V_32 ;
F_41 ( ! V_147 ) ;
F_41 ( F_106 ( V_2 -> V_14 ) == NULL ) ;
V_38 = F_58 ( V_2 , & V_79 ) ;
if ( F_37 ( V_38 ) ) {
F_17 ( V_3 ) ;
F_77 ( V_3 ) ;
goto V_148;
}
if ( F_64 ( V_2 ) )
return F_101 ( V_15 , V_79 , V_92 , V_100 , V_95 , V_3 ) ;
if ( ! F_107 ( V_2 ) )
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
V_38 = F_108 ( V_85 , V_22 , V_92 , V_100 , V_95 , V_3 , V_103 ) ;
if ( V_147 -> V_149 )
F_109 ( V_15 , V_150 ) ;
else
F_110 ( V_2 -> V_14 , V_79 ) ;
if ( V_15 == V_25 -> V_113 ) {
F_93 ( V_15 ) ;
V_25 -> V_145 = 0 ;
}
F_62 ( V_79 ) ;
V_148:
F_45 ( V_25 ) ;
F_91 ( V_2 ) ;
if ( V_2 -> V_151 && V_2 -> V_151 -> V_152 )
F_92 ( V_2 ) ;
if ( V_15 == V_25 -> V_113 ) {
F_71 ( & V_104 -> V_112 ) ;
F_72 ( & V_104 -> V_112 ) ;
}
F_71 ( & V_2 -> V_112 ) ;
F_72 ( & V_2 -> V_112 ) ;
return V_38 ;
}
static int F_111 ( struct V_3 * V_3 )
{
F_112 ( V_3 ) ;
return F_113 ( V_3 ) ;
}
static T_1 F_114 ( struct V_47 * V_22 , T_1 V_16 )
{
struct V_1 * V_2 = F_11 ( V_22 -> V_23 ) ;
struct V_87 V_112 ;
T_1 V_153 = 0 ;
int error ;
error = F_81 ( V_2 -> V_14 , V_89 , V_154 , & V_112 ) ;
if ( error )
return 0 ;
if ( ! F_64 ( V_2 ) )
V_153 = F_115 ( V_22 , V_16 , F_7 ) ;
F_116 ( & V_112 ) ;
return V_153 ;
}
static void F_117 ( struct V_24 * V_25 , struct V_6 * V_10 )
{
struct V_155 * V_156 ;
F_118 ( V_10 ) ;
F_119 ( V_25 ) ;
F_120 ( V_10 ) ;
V_156 = V_10 -> V_157 ;
if ( V_156 ) {
if ( ! F_121 ( & V_156 -> V_158 ) && ! F_122 ( V_10 ) )
F_123 ( & V_156 -> V_158 ) ;
else
F_124 ( V_10 , V_159 ) ;
}
V_10 -> V_160 = NULL ;
F_125 ( V_10 ) ;
F_126 ( V_10 ) ;
F_127 ( V_10 ) ;
F_128 ( V_25 ) ;
F_129 ( V_10 ) ;
}
static void F_130 ( struct V_3 * V_3 , unsigned int V_29 ,
unsigned int V_161 )
{
struct V_24 * V_25 = F_12 ( V_3 -> V_22 -> V_23 ) ;
unsigned int V_162 = V_29 + V_161 ;
int V_163 = ( V_29 || V_161 < V_34 ) ;
struct V_6 * V_10 , * V_7 ;
unsigned long V_92 = 0 ;
F_41 ( ! F_131 ( V_3 ) ) ;
if ( ! V_163 )
F_25 ( V_3 ) ;
if ( ! F_26 ( V_3 ) )
goto V_30;
V_10 = V_7 = F_2 ( V_3 ) ;
do {
if ( V_92 + V_10 -> V_9 > V_162 )
return;
if ( V_29 <= V_92 )
F_117 ( V_25 , V_10 ) ;
V_92 += V_10 -> V_9 ;
V_10 = V_10 -> V_13 ;
} while ( V_10 != V_7 );
V_30:
if ( ! V_163 )
F_132 ( V_3 , 0 ) ;
}
static int F_133 ( struct V_1 * V_2 , T_2 V_29 )
{
if ( F_64 ( V_2 ) )
return 0 ;
if ( V_29 >= F_13 ( & V_2 -> V_81 ) )
return 0 ;
return 1 ;
}
static T_6 F_134 ( struct V_164 * V_165 , struct V_166 * V_167 )
{
struct V_85 * V_85 = V_165 -> V_168 ;
struct V_15 * V_15 = V_85 -> V_169 -> V_23 ;
struct V_47 * V_22 = V_15 -> V_94 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
T_2 V_29 = V_165 -> V_170 ;
struct V_87 V_88 ;
int V_171 ;
F_68 ( V_2 -> V_14 , V_172 , 0 , & V_88 ) ;
V_171 = F_69 ( & V_88 ) ;
if ( V_171 )
goto V_99;
V_171 = F_133 ( V_2 , V_29 ) ;
if ( V_171 != 1 )
goto V_30;
if ( V_22 -> V_173 ) {
T_2 V_174 = V_29 & ~ ( V_34 - 1 ) ;
T_2 V_100 = F_135 ( V_167 ) ;
T_2 V_12 = F_136 ( V_29 + V_100 ) - 1 ;
V_171 = 0 ;
if ( V_100 == 0 )
goto V_30;
if ( F_137 ( V_175 , & V_2 -> V_176 ) )
F_138 ( V_2 -> V_81 . V_94 , V_29 , V_100 ) ;
V_171 = F_139 ( V_22 , V_174 , V_12 ) ;
if ( V_171 )
goto V_30;
if ( F_140 ( V_167 ) == V_177 )
F_141 ( V_22 , V_174 , V_12 ) ;
}
V_171 = F_142 ( V_165 , V_15 , V_15 -> V_41 -> V_178 , V_167 ,
F_9 , NULL , NULL , 0 ) ;
V_30:
F_71 ( & V_88 ) ;
V_99:
F_72 ( & V_88 ) ;
return V_171 ;
}
int F_143 ( struct V_3 * V_3 , T_7 V_179 )
{
struct V_47 * V_22 = V_3 -> V_22 ;
struct V_24 * V_25 = F_31 ( V_22 ) ;
struct V_6 * V_10 , * V_7 ;
struct V_155 * V_156 ;
if ( ! F_26 ( V_3 ) )
return 0 ;
F_119 ( V_25 ) ;
F_95 ( & V_25 -> V_180 ) ;
V_7 = V_10 = F_2 ( V_3 ) ;
do {
if ( F_144 ( & V_10 -> V_181 ) )
goto V_182;
V_156 = V_10 -> V_157 ;
if ( V_156 && V_156 -> V_183 )
goto V_182;
if ( F_145 ( V_10 ) || F_102 ( F_122 ( V_10 ) ) )
goto V_182;
V_10 = V_10 -> V_13 ;
} while( V_10 != V_7 );
F_97 ( & V_25 -> V_180 ) ;
V_7 = V_10 = F_2 ( V_3 ) ;
do {
V_156 = V_10 -> V_157 ;
if ( V_156 ) {
F_146 ( V_25 , V_156 -> V_184 == V_10 ) ;
if ( ! F_121 ( & V_156 -> V_158 ) )
F_123 ( & V_156 -> V_158 ) ;
V_156 -> V_184 = NULL ;
V_10 -> V_157 = NULL ;
F_147 ( V_185 , V_156 ) ;
}
V_10 = V_10 -> V_13 ;
} while ( V_10 != V_7 );
F_128 ( V_25 ) ;
return F_148 ( V_3 ) ;
V_182:
F_97 ( & V_25 -> V_180 ) ;
F_128 ( V_25 ) ;
return 0 ;
}
void F_149 ( struct V_15 * V_15 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
if ( F_107 ( V_2 ) )
V_15 -> V_94 -> V_36 = & V_186 ;
else if ( F_150 ( V_2 ) )
V_15 -> V_94 -> V_36 = & V_187 ;
else if ( F_3 ( V_2 ) )
V_15 -> V_94 -> V_36 = & V_188 ;
else
F_151 () ;
}
