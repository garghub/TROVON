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
return F_31 ( V_22 , V_21 , F_6 ) ;
}
static int F_32 ( struct V_47 * V_22 ,
struct V_20 * V_21 ,
struct V_48 * V_49 ,
int V_50 , T_3 V_12 ,
T_3 * V_51 )
{
struct V_15 * V_15 = V_22 -> V_23 ;
struct V_24 * V_25 = F_12 ( V_15 ) ;
unsigned V_52 = V_50 * ( V_34 / V_15 -> V_41 -> V_42 ) ;
int V_53 ;
int V_38 ;
V_38 = F_33 ( V_25 , V_52 , V_52 ) ;
if ( V_38 < 0 )
return V_38 ;
for( V_53 = 0 ; V_53 < V_50 ; V_53 ++ ) {
struct V_3 * V_3 = V_49 -> V_54 [ V_53 ] ;
if ( V_3 -> V_35 > V_12 ) {
V_38 = 1 ;
break;
}
* V_51 = V_3 -> V_35 ;
F_34 ( V_3 ) ;
if ( F_35 ( V_3 -> V_22 != V_22 ) ) {
V_55:
F_17 ( V_3 ) ;
continue;
}
if ( ! F_36 ( V_3 ) ) {
goto V_55;
}
if ( F_37 ( V_3 ) ) {
if ( V_21 -> V_56 != V_57 )
F_38 ( V_3 ) ;
else
goto V_55;
}
F_39 ( F_37 ( V_3 ) ) ;
if ( ! F_40 ( V_3 ) )
goto V_55;
F_41 ( V_21 , F_42 ( V_15 ) ) ;
V_38 = F_23 ( V_3 , V_21 ) ;
if ( F_35 ( V_38 ) ) {
if ( V_38 == V_58 ) {
F_17 ( V_3 ) ;
V_38 = 0 ;
} else {
* V_51 = V_3 -> V_35 + 1 ;
V_38 = 1 ;
break;
}
}
if ( -- V_21 -> V_59 <= 0 && V_21 -> V_56 == V_57 ) {
V_38 = 1 ;
break;
}
}
F_43 ( V_25 ) ;
return V_38 ;
}
static int F_44 ( struct V_47 * V_22 ,
struct V_20 * V_21 )
{
int V_38 = 0 ;
int V_60 = 0 ;
struct V_48 V_49 ;
int V_50 ;
T_3 V_61 ( V_62 ) ;
T_3 V_35 ;
T_3 V_12 ;
T_3 V_51 ;
int V_63 ;
int V_64 = 0 ;
int V_65 ;
F_45 ( & V_49 , 0 ) ;
if ( V_21 -> V_66 ) {
V_62 = V_22 -> V_62 ;
V_35 = V_62 ;
if ( V_35 == 0 )
V_63 = 1 ;
else
V_63 = 0 ;
V_12 = - 1 ;
} else {
V_35 = V_21 -> V_67 >> V_28 ;
V_12 = V_21 -> V_68 >> V_28 ;
if ( V_21 -> V_67 == 0 && V_21 -> V_68 == V_69 )
V_64 = 1 ;
V_63 = 1 ;
}
if ( V_21 -> V_56 == V_70 || V_21 -> V_71 )
V_65 = V_72 ;
else
V_65 = V_73 ;
V_74:
if ( V_21 -> V_56 == V_70 || V_21 -> V_71 )
F_46 ( V_22 , V_35 , V_12 ) ;
V_51 = V_35 ;
while ( ! V_60 && ( V_35 <= V_12 ) ) {
V_50 = F_47 ( & V_49 , V_22 , & V_35 , V_65 ,
F_48 ( V_12 - V_35 , ( T_3 ) V_75 - 1 ) + 1 ) ;
if ( V_50 == 0 )
break;
V_38 = F_32 ( V_22 , V_21 , & V_49 , V_50 , V_12 , & V_51 ) ;
if ( V_38 )
V_60 = 1 ;
if ( V_38 > 0 )
V_38 = 0 ;
F_49 ( & V_49 ) ;
F_50 () ;
}
if ( ! V_63 && ! V_60 ) {
V_63 = 1 ;
V_35 = 0 ;
V_12 = V_62 - 1 ;
goto V_74;
}
if ( V_21 -> V_66 || ( V_64 && V_21 -> V_59 > 0 ) )
V_22 -> V_62 = V_51 ;
return V_38 ;
}
static int F_51 ( struct V_47 * V_22 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = F_11 ( V_22 -> V_23 ) ;
struct V_24 * V_25 = F_12 ( V_22 -> V_23 ) ;
int V_38 ;
V_38 = F_44 ( V_22 , V_21 ) ;
if ( V_38 == 0 && V_21 -> V_56 == V_70 ) {
F_52 ( V_25 , V_2 -> V_14 , V_76 ) ;
V_38 = F_44 ( V_22 , V_21 ) ;
}
return V_38 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_6 * V_77 ;
T_5 V_78 = F_13 ( & V_2 -> V_79 ) ;
void * V_80 ;
int error ;
if ( F_35 ( V_3 -> V_35 ) ) {
F_54 ( V_3 , 0 , V_34 ) ;
F_55 ( V_3 ) ;
return 0 ;
}
error = F_56 ( V_2 , & V_77 ) ;
if ( error )
return error ;
V_80 = F_57 ( V_3 ) ;
if ( V_78 > ( V_77 -> V_9 - sizeof( struct V_81 ) ) )
V_78 = ( V_77 -> V_9 - sizeof( struct V_81 ) ) ;
memcpy ( V_80 , V_77 -> V_82 + sizeof( struct V_81 ) , V_78 ) ;
memset ( V_80 + V_78 , 0 , V_34 - V_78 ) ;
F_58 ( V_80 ) ;
F_59 ( V_3 ) ;
F_60 ( V_77 ) ;
F_55 ( V_3 ) ;
return 0 ;
}
static int F_61 ( void * V_83 , struct V_3 * V_3 )
{
struct V_1 * V_2 = F_11 ( V_3 -> V_22 -> V_23 ) ;
struct V_24 * V_25 = F_12 ( V_3 -> V_22 -> V_23 ) ;
int error ;
if ( F_62 ( V_2 ) ) {
error = F_53 ( V_2 , V_3 ) ;
F_17 ( V_3 ) ;
} else {
error = F_63 ( V_3 , F_7 ) ;
}
if ( F_35 ( F_64 ( V_84 , & V_25 -> V_85 ) ) )
return - V_19 ;
return error ;
}
static int F_65 ( struct V_83 * V_83 , struct V_3 * V_3 )
{
struct V_47 * V_22 = V_3 -> V_22 ;
struct V_1 * V_2 = F_11 ( V_22 -> V_23 ) ;
struct V_86 V_87 ;
int error ;
F_17 ( V_3 ) ;
F_66 ( V_2 -> V_14 , V_88 , 0 , & V_87 ) ;
error = F_67 ( & V_87 ) ;
if ( F_35 ( error ) )
goto V_30;
error = V_89 ;
F_34 ( V_3 ) ;
if ( V_3 -> V_22 == V_22 && ! F_68 ( V_3 ) )
error = F_61 ( V_83 , V_3 ) ;
else
F_17 ( V_3 ) ;
F_69 ( & V_87 ) ;
V_30:
F_70 ( & V_87 ) ;
if ( error && error != V_89 )
F_34 ( V_3 ) ;
return error ;
}
int F_71 ( struct V_1 * V_2 , char * V_90 , T_2 * V_91 ,
unsigned V_92 )
{
struct V_47 * V_22 = V_2 -> V_79 . V_93 ;
unsigned long V_35 = * V_91 / V_34 ;
unsigned V_29 = * V_91 & ( V_34 - 1 ) ;
unsigned V_94 = 0 ;
unsigned V_95 ;
struct V_3 * V_3 ;
void * V_96 ;
do {
V_95 = V_92 - V_94 ;
if ( V_29 + V_92 > V_34 )
V_95 = V_34 - V_29 ;
V_3 = F_72 ( V_22 , V_35 , F_61 , NULL ) ;
if ( F_73 ( V_3 ) )
return F_74 ( V_3 ) ;
V_96 = F_57 ( V_3 ) ;
memcpy ( V_90 + V_94 , V_96 + V_29 , V_95 ) ;
F_58 ( V_96 ) ;
F_75 ( V_3 ) ;
V_94 += V_95 ;
V_35 ++ ;
V_29 = 0 ;
} while( V_94 < V_92 );
( * V_91 ) += V_92 ;
return V_92 ;
}
static int F_76 ( struct V_83 * V_83 , struct V_47 * V_22 ,
struct V_97 * V_54 , unsigned V_50 )
{
struct V_15 * V_15 = V_22 -> V_23 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
struct V_24 * V_25 = F_12 ( V_15 ) ;
struct V_86 V_87 ;
int V_38 ;
F_66 ( V_2 -> V_14 , V_88 , 0 , & V_87 ) ;
V_38 = F_67 ( & V_87 ) ;
if ( F_35 ( V_38 ) )
goto V_98;
if ( ! F_62 ( V_2 ) )
V_38 = F_77 ( V_22 , V_54 , V_50 , F_7 ) ;
F_69 ( & V_87 ) ;
V_98:
F_70 ( & V_87 ) ;
if ( F_35 ( F_64 ( V_84 , & V_25 -> V_85 ) ) )
V_38 = - V_19 ;
return V_38 ;
}
static int F_78 ( struct V_83 * V_83 , struct V_47 * V_22 ,
T_2 V_91 , unsigned V_99 , unsigned V_100 ,
struct V_3 * * V_101 , void * * V_102 )
{
struct V_1 * V_2 = F_11 ( V_22 -> V_23 ) ;
struct V_24 * V_25 = F_12 ( V_22 -> V_23 ) ;
struct V_1 * V_103 = F_11 ( V_25 -> V_104 ) ;
unsigned int V_105 = 0 , V_106 = 0 , V_107 ;
unsigned V_108 = 0 ;
int V_109 ;
int error = 0 ;
T_3 V_35 = V_91 >> V_28 ;
unsigned V_4 = V_91 & ( V_34 - 1 ) ;
struct V_3 * V_3 ;
F_66 ( V_2 -> V_14 , V_110 , 0 , & V_2 -> V_111 ) ;
error = F_67 ( & V_2 -> V_111 ) ;
if ( F_35 ( error ) )
goto V_98;
if ( & V_2 -> V_79 == V_25 -> V_112 ) {
error = F_79 ( V_103 -> V_14 , V_110 ,
V_113 , & V_103 -> V_111 ) ;
if ( F_35 ( error ) ) {
F_69 ( & V_2 -> V_111 ) ;
goto V_98;
}
}
V_109 = F_80 ( V_2 , V_91 , V_99 ) ;
if ( V_109 || F_3 ( V_2 ) )
F_81 ( V_2 , V_99 , & V_105 , & V_106 ) ;
if ( V_109 ) {
struct V_114 V_115 = { . V_116 = 0 , } ;
V_108 = V_105 + V_106 ;
V_115 . V_117 = V_108 ;
error = F_82 ( V_2 , & V_115 ) ;
if ( error )
goto V_118;
error = F_83 ( V_2 , & V_115 ) ;
if ( error )
goto V_119;
}
V_107 = V_120 + V_106 ;
if ( F_3 ( V_2 ) )
V_107 += V_105 ? V_105 : 1 ;
if ( V_106 || V_105 )
V_107 += V_121 + V_122 ;
if ( & V_2 -> V_79 == V_25 -> V_112 )
V_107 += 2 * V_121 ;
if ( V_109 )
V_107 += F_84 ( V_2 , V_108 ) ;
error = F_33 ( V_25 , V_107 ,
V_34 / V_25 -> V_123 . V_124 ) ;
if ( error )
goto V_125;
error = - V_126 ;
V_100 |= V_127 ;
V_3 = F_85 ( V_22 , V_35 , V_100 ) ;
* V_101 = V_3 ;
if ( F_35 ( ! V_3 ) )
goto V_128;
if ( F_62 ( V_2 ) ) {
error = 0 ;
if ( V_91 + V_99 > V_25 -> V_123 . V_124 - sizeof( struct V_81 ) ) {
error = F_86 ( V_2 , V_3 ) ;
if ( error == 0 )
goto V_129;
} else if ( ! F_68 ( V_3 ) ) {
error = F_53 ( V_2 , V_3 ) ;
}
goto V_30;
}
V_129:
error = F_87 ( V_3 , V_4 , V_99 , F_7 ) ;
V_30:
if ( error == 0 )
return 0 ;
F_17 ( V_3 ) ;
F_75 ( V_3 ) ;
F_43 ( V_25 ) ;
if ( V_91 + V_99 > V_2 -> V_79 . V_26 )
F_88 ( & V_2 -> V_79 ) ;
goto V_125;
V_128:
F_43 ( V_25 ) ;
V_125:
if ( V_109 ) {
F_89 ( V_2 ) ;
V_119:
F_90 ( V_2 ) ;
}
V_118:
if ( & V_2 -> V_79 == V_25 -> V_112 ) {
F_69 ( & V_103 -> V_111 ) ;
F_70 ( & V_103 -> V_111 ) ;
}
F_69 ( & V_2 -> V_111 ) ;
V_98:
F_70 ( & V_2 -> V_111 ) ;
return error ;
}
static void F_91 ( struct V_15 * V_15 )
{
struct V_24 * V_25 = V_15 -> V_41 -> V_130 ;
struct V_1 * V_103 = F_11 ( V_25 -> V_104 ) ;
struct V_1 * V_131 = F_11 ( V_25 -> V_132 ) ;
struct V_133 * V_134 = & V_25 -> V_135 ;
struct V_133 * V_136 = & V_25 -> V_137 ;
struct V_6 * V_138 , * V_139 ;
T_5 V_140 , V_141 ;
V_140 = F_92 ( V_25 ) ;
if ( F_56 ( V_103 , & V_138 ) != 0 )
return;
F_93 ( & V_25 -> V_142 ) ;
F_94 ( V_134 , V_138 -> V_82 +
sizeof( struct V_81 ) ) ;
if ( V_140 > ( V_134 -> V_143 + V_136 -> V_143 ) )
V_141 = V_140 - ( V_134 -> V_143 + V_136 -> V_143 ) ;
else
V_141 = 0 ;
F_95 ( & V_25 -> V_142 ) ;
F_96 ( V_25 , L_1 ,
( unsigned long long ) V_141 ) ;
F_97 ( V_25 , V_141 , V_141 , 0 ) ;
if ( F_56 ( V_131 , & V_139 ) != 0 )
goto V_30;
F_98 ( V_25 , V_138 , V_139 ) ;
F_60 ( V_139 ) ;
V_30:
F_60 ( V_138 ) ;
}
static int F_99 ( struct V_15 * V_15 , struct V_6 * V_77 ,
T_2 V_91 , unsigned V_99 , unsigned V_94 ,
struct V_3 * V_3 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
struct V_24 * V_25 = F_12 ( V_15 ) ;
struct V_1 * V_103 = F_11 ( V_25 -> V_104 ) ;
T_5 V_5 = V_91 + V_94 ;
void * V_80 ;
unsigned char * V_90 = V_77 -> V_82 + sizeof( struct V_81 ) ;
F_39 ( ( V_91 + V_99 ) > ( V_77 -> V_9 - sizeof( struct V_81 ) ) ) ;
V_80 = F_57 ( V_3 ) ;
memcpy ( V_90 + V_91 , V_80 + V_91 , V_94 ) ;
F_59 ( V_3 ) ;
F_58 ( V_80 ) ;
F_100 ( ! F_68 ( V_3 ) ) ;
F_17 ( V_3 ) ;
F_75 ( V_3 ) ;
if ( V_94 ) {
if ( V_15 -> V_26 < V_5 )
F_101 ( V_15 , V_5 ) ;
F_102 ( V_15 ) ;
}
if ( V_15 == V_25 -> V_112 ) {
F_91 ( V_15 ) ;
V_25 -> V_144 = 0 ;
}
F_60 ( V_77 ) ;
F_43 ( V_25 ) ;
if ( V_15 == V_25 -> V_112 ) {
F_69 ( & V_103 -> V_111 ) ;
F_70 ( & V_103 -> V_111 ) ;
}
F_69 ( & V_2 -> V_111 ) ;
F_70 ( & V_2 -> V_111 ) ;
return V_94 ;
}
static int F_103 ( struct V_83 * V_83 , struct V_47 * V_22 ,
T_2 V_91 , unsigned V_99 , unsigned V_94 ,
struct V_3 * V_3 , void * V_102 )
{
struct V_15 * V_15 = V_3 -> V_22 -> V_23 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
struct V_24 * V_25 = F_12 ( V_15 ) ;
struct V_1 * V_103 = F_11 ( V_25 -> V_104 ) ;
struct V_6 * V_77 ;
unsigned int V_4 = V_91 & ( V_34 - 1 ) ;
unsigned int V_5 = V_4 + V_99 ;
int V_38 ;
struct V_145 * V_146 = V_31 -> V_32 ;
F_39 ( ! V_146 ) ;
F_39 ( F_104 ( V_2 -> V_14 ) == NULL ) ;
V_38 = F_56 ( V_2 , & V_77 ) ;
if ( F_35 ( V_38 ) ) {
F_17 ( V_3 ) ;
F_75 ( V_3 ) ;
goto V_147;
}
if ( F_62 ( V_2 ) )
return F_99 ( V_15 , V_77 , V_91 , V_99 , V_94 , V_3 ) ;
if ( ! F_105 ( V_2 ) )
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
V_38 = F_106 ( V_83 , V_22 , V_91 , V_99 , V_94 , V_3 , V_102 ) ;
if ( V_146 -> V_148 )
F_107 ( V_15 , V_149 ) ;
else
F_108 ( V_2 -> V_14 , V_77 ) ;
if ( V_15 == V_25 -> V_112 ) {
F_91 ( V_15 ) ;
V_25 -> V_144 = 0 ;
}
F_60 ( V_77 ) ;
V_147:
F_43 ( V_25 ) ;
F_89 ( V_2 ) ;
if ( V_2 -> V_150 && V_2 -> V_150 -> V_151 )
F_90 ( V_2 ) ;
if ( V_15 == V_25 -> V_112 ) {
F_69 ( & V_103 -> V_111 ) ;
F_70 ( & V_103 -> V_111 ) ;
}
F_69 ( & V_2 -> V_111 ) ;
F_70 ( & V_2 -> V_111 ) ;
return V_38 ;
}
static int F_109 ( struct V_3 * V_3 )
{
F_110 ( V_3 ) ;
return F_111 ( V_3 ) ;
}
static T_1 F_112 ( struct V_47 * V_22 , T_1 V_16 )
{
struct V_1 * V_2 = F_11 ( V_22 -> V_23 ) ;
struct V_86 V_111 ;
T_1 V_152 = 0 ;
int error ;
error = F_79 ( V_2 -> V_14 , V_88 , V_153 , & V_111 ) ;
if ( error )
return 0 ;
if ( ! F_62 ( V_2 ) )
V_152 = F_113 ( V_22 , V_16 , F_7 ) ;
F_114 ( & V_111 ) ;
return V_152 ;
}
static void F_115 ( struct V_24 * V_25 , struct V_6 * V_10 )
{
struct V_154 * V_155 ;
F_116 ( V_10 ) ;
F_117 ( V_25 ) ;
F_118 ( V_10 ) ;
V_155 = V_10 -> V_156 ;
if ( V_155 ) {
if ( ! F_119 ( & V_155 -> V_157 ) && ! F_120 ( V_10 ) )
F_121 ( & V_155 -> V_157 ) ;
else
F_122 ( V_10 , V_158 ) ;
}
V_10 -> V_159 = NULL ;
F_123 ( V_10 ) ;
F_124 ( V_10 ) ;
F_125 ( V_10 ) ;
F_126 ( V_25 ) ;
F_127 ( V_10 ) ;
}
static void F_128 ( struct V_3 * V_3 , unsigned int V_29 ,
unsigned int V_160 )
{
struct V_24 * V_25 = F_12 ( V_3 -> V_22 -> V_23 ) ;
unsigned int V_161 = V_29 + V_160 ;
int V_162 = ( V_29 || V_160 < V_34 ) ;
struct V_6 * V_10 , * V_7 ;
unsigned long V_91 = 0 ;
F_39 ( ! F_129 ( V_3 ) ) ;
if ( ! V_162 )
F_25 ( V_3 ) ;
if ( ! F_26 ( V_3 ) )
goto V_30;
V_10 = V_7 = F_2 ( V_3 ) ;
do {
if ( V_91 + V_10 -> V_9 > V_161 )
return;
if ( V_29 <= V_91 )
F_115 ( V_25 , V_10 ) ;
V_91 += V_10 -> V_9 ;
V_10 = V_10 -> V_13 ;
} while ( V_10 != V_7 );
V_30:
if ( ! V_162 )
F_130 ( V_3 , 0 ) ;
}
static int F_131 ( struct V_1 * V_2 , T_2 V_29 )
{
if ( F_62 ( V_2 ) )
return 0 ;
if ( V_29 >= F_13 ( & V_2 -> V_79 ) )
return 0 ;
return 1 ;
}
static T_6 F_132 ( struct V_163 * V_164 , struct V_165 * V_166 )
{
struct V_83 * V_83 = V_164 -> V_167 ;
struct V_15 * V_15 = V_83 -> V_168 -> V_23 ;
struct V_47 * V_22 = V_15 -> V_93 ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
T_2 V_29 = V_164 -> V_169 ;
struct V_86 V_87 ;
int V_170 ;
F_66 ( V_2 -> V_14 , V_171 , 0 , & V_87 ) ;
V_170 = F_67 ( & V_87 ) ;
if ( V_170 )
goto V_98;
V_170 = F_131 ( V_2 , V_29 ) ;
if ( V_170 != 1 )
goto V_30;
if ( V_22 -> V_172 ) {
T_2 V_173 = V_29 & ~ ( V_34 - 1 ) ;
T_2 V_99 = F_133 ( V_166 ) ;
T_2 V_12 = F_134 ( V_29 + V_99 ) - 1 ;
V_170 = 0 ;
if ( V_99 == 0 )
goto V_30;
if ( F_135 ( V_174 , & V_2 -> V_175 ) )
F_136 ( V_2 -> V_79 . V_93 , V_29 , V_99 ) ;
V_170 = F_137 ( V_22 , V_173 , V_12 ) ;
if ( V_170 )
goto V_30;
if ( F_138 ( V_166 ) == V_176 )
F_139 ( V_22 , V_173 , V_12 ) ;
}
V_170 = F_140 ( V_164 , V_15 , V_15 -> V_41 -> V_177 , V_166 ,
F_9 , NULL , NULL , 0 ) ;
V_30:
F_69 ( & V_87 ) ;
V_98:
F_70 ( & V_87 ) ;
return V_170 ;
}
int F_141 ( struct V_3 * V_3 , T_7 V_178 )
{
struct V_47 * V_22 = V_3 -> V_22 ;
struct V_24 * V_25 = F_142 ( V_22 ) ;
struct V_6 * V_10 , * V_7 ;
struct V_154 * V_155 ;
if ( ! F_26 ( V_3 ) )
return 0 ;
F_117 ( V_25 ) ;
F_93 ( & V_25 -> V_179 ) ;
V_7 = V_10 = F_2 ( V_3 ) ;
do {
if ( F_143 ( & V_10 -> V_180 ) )
goto V_181;
V_155 = V_10 -> V_156 ;
if ( V_155 && V_155 -> V_182 )
goto V_181;
if ( F_144 ( V_10 ) || F_100 ( F_120 ( V_10 ) ) )
goto V_181;
V_10 = V_10 -> V_13 ;
} while( V_10 != V_7 );
F_95 ( & V_25 -> V_179 ) ;
V_7 = V_10 = F_2 ( V_3 ) ;
do {
V_155 = V_10 -> V_156 ;
if ( V_155 ) {
F_145 ( V_25 , V_155 -> V_183 == V_10 ) ;
if ( ! F_119 ( & V_155 -> V_157 ) )
F_121 ( & V_155 -> V_157 ) ;
V_155 -> V_183 = NULL ;
V_10 -> V_156 = NULL ;
F_146 ( V_184 , V_155 ) ;
}
V_10 = V_10 -> V_13 ;
} while ( V_10 != V_7 );
F_126 ( V_25 ) ;
return F_147 ( V_3 ) ;
V_181:
F_95 ( & V_25 -> V_179 ) ;
F_126 ( V_25 ) ;
return 0 ;
}
void F_148 ( struct V_15 * V_15 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
if ( F_105 ( V_2 ) )
V_15 -> V_93 -> V_36 = & V_185 ;
else if ( F_149 ( V_2 ) )
V_15 -> V_93 -> V_36 = & V_186 ;
else if ( F_3 ( V_2 ) )
V_15 -> V_93 -> V_36 = & V_187 ;
else
F_150 () ;
}
