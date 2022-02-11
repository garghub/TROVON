static void F_1 ( struct V_1 * V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = & V_1 -> V_7 ;
if ( ! F_2 ( V_8 + V_9 , & V_1 -> V_10 ) ) {
V_6 -> V_11 = F_3 ( V_4 -> V_11 ) ;
V_6 -> V_12 = F_3 ( V_4 -> V_12 ) ;
}
if ( ! F_2 ( V_8 + V_13 , & V_1 -> V_10 ) )
V_6 -> V_14 = F_3 ( V_4 -> V_14 ) ;
if ( ! F_2 ( V_8 + V_15 , & V_1 -> V_10 ) ) {
V_6 -> V_16 = F_3 ( V_4 -> V_16 ) ;
V_6 -> V_17 = F_3 ( V_4 -> V_17 ) ;
}
if ( ! F_2 ( V_8 + V_18 , & V_1 -> V_10 ) )
V_6 -> V_19 = F_3 ( V_4 -> V_19 ) ;
if ( ! F_2 ( V_8 + V_20 , & V_1 -> V_10 ) )
V_6 -> V_21 = F_3 ( V_4 -> V_21 ) ;
if ( ! F_2 ( V_8 + V_22 , & V_1 -> V_10 ) )
V_6 -> V_23 = F_3 ( V_4 -> V_23 ) ;
F_4 ( V_1 ) -> V_24 = F_5 ( V_4 -> V_25 ) ;
}
static void F_6 ( void * V_2 , struct V_1 * V_1 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = & V_1 -> V_7 ;
V_4 -> V_26 = F_7 ( F_8 ( & V_27 , V_1 -> V_28 ) ) ;
V_4 -> V_25 = F_7 ( F_4 ( V_1 ) -> V_24 ) ;
V_4 -> V_11 = F_9 ( V_6 -> V_11 ) ;
V_4 -> V_12 = F_9 ( V_6 -> V_12 ) ;
V_4 -> V_14 = F_9 ( V_6 -> V_14 ) ;
V_4 -> V_16 = F_9 ( V_6 -> V_16 ) ;
V_4 -> V_17 = F_9 ( V_6 -> V_17 ) ;
V_4 -> V_19 = F_9 ( V_6 -> V_19 ) ;
V_4 -> V_21 = F_9 ( V_6 -> V_21 ) ;
V_4 -> V_23 = F_9 ( V_6 -> V_23 ) ;
V_4 -> V_29 = V_4 -> V_30 = 0 ;
}
static int F_10 ( void * V_2 , struct V_1 * V_1 )
{
struct V_3 * V_4 = V_2 ;
struct V_31 * V_32 =
F_11 ( V_1 -> V_33 , V_1 -> V_28 . type ) -> V_34 ;
if ( F_12 ( & V_32 -> V_35 , V_2 ) )
return 0 ;
return F_13 ( F_14 ( & V_27 , V_1 -> V_28 . type ,
F_5 ( V_4 -> V_26 ) ) ,
V_1 -> V_28 ) ;
}
int F_15 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_40 * V_41 =
F_16 ( V_37 -> V_42 , V_39 -> V_43 ) ;
F_17 ( ( unsigned long long ) V_39 -> V_44 ) ;
F_18 ( ! F_19 ( V_39 ) ) ;
return F_20 ( V_37 , V_39 -> V_43 , & V_41 -> V_45 ) ;
}
int F_21 ( struct V_46 * V_46 , T_1 V_47 ,
struct V_38 * * V_48 )
{
int V_49 ;
* V_48 = NULL ;
V_49 = F_22 ( F_23 ( V_46 ) , V_47 , 1 , V_48 , 0 ,
F_15 ) ;
if ( V_49 )
F_24 ( V_49 ) ;
return V_49 ;
}
T_2 F_25 ( struct V_36 * V_37 , int type , char * V_50 ,
T_3 V_51 , T_4 V_52 )
{
struct V_31 * V_32 = F_11 ( V_37 , type ) -> V_34 ;
struct V_46 * V_53 = V_32 -> V_54 ;
T_4 V_55 = F_26 ( V_53 ) ;
int V_56 = V_52 & ( V_37 -> V_42 - 1 ) ;
T_5 V_57 = V_52 >> V_37 -> V_58 ;
int V_59 = 0 ;
struct V_38 * V_39 ;
T_3 V_60 , V_61 ;
T_1 V_62 = 0 , V_63 = 0 ;
if ( V_52 > V_55 )
return 0 ;
if ( V_52 + V_51 > V_55 )
V_51 = V_55 - V_52 ;
V_60 = V_51 ;
while ( V_60 > 0 ) {
V_61 = F_27 ( T_3 , ( V_37 -> V_42 - V_56 ) , V_60 ) ;
if ( ! V_63 ) {
V_59 = F_28 ( V_53 , V_57 , & V_62 ,
& V_63 , NULL ) ;
if ( V_59 ) {
F_24 ( V_59 ) ;
return V_59 ;
}
} else {
V_63 -- ;
V_62 ++ ;
}
V_39 = NULL ;
V_59 = F_21 ( V_53 , V_62 , & V_39 ) ;
if ( V_59 ) {
F_24 ( V_59 ) ;
return V_59 ;
}
memcpy ( V_50 , V_39 -> V_43 + V_56 , V_61 ) ;
F_29 ( V_39 ) ;
V_56 = 0 ;
V_60 -= V_61 ;
V_50 += V_61 ;
V_57 ++ ;
}
return V_51 ;
}
T_2 F_30 ( struct V_36 * V_37 , int type ,
const char * V_50 , T_3 V_51 , T_4 V_52 )
{
struct V_64 * V_65 = F_11 ( V_37 , type ) ;
struct V_31 * V_32 = V_65 -> V_34 ;
struct V_46 * V_53 = V_32 -> V_54 ;
int V_56 = V_52 & ( V_37 -> V_42 - 1 ) ;
T_5 V_57 = V_52 >> V_37 -> V_58 ;
int V_59 = 0 , V_66 = 0 , V_67 ;
struct V_38 * V_39 = NULL ;
T_6 * V_68 = F_31 () ;
T_1 V_62 , V_63 ;
if ( ! V_68 ) {
F_32 ( V_69 , L_1
L_2 ,
( unsigned long long ) V_52 , ( unsigned long long ) V_51 ) ;
return - V_70 ;
}
if ( V_51 > V_37 -> V_42 - V_71 - V_56 ) {
F_33 ( 1 ) ;
V_51 = V_37 -> V_42 - V_71 - V_56 ;
}
if ( F_26 ( V_53 ) < V_52 + V_51 ) {
T_4 V_72 =
F_34 ( V_37 , V_52 + V_51 ) ;
V_59 = F_35 ( V_53 ,
V_32 -> V_73 ,
V_72 ) ;
if ( V_59 < 0 )
goto V_74;
V_66 = 1 ;
}
V_59 = F_28 ( V_53 , V_57 , & V_62 , & V_63 , NULL ) ;
if ( V_59 ) {
F_24 ( V_59 ) ;
goto V_74;
}
if ( ( V_56 || V_51 < V_37 -> V_42 - V_71 ) &&
! V_66 ) {
V_59 = F_21 ( V_53 , V_62 , & V_39 ) ;
V_67 = V_75 ;
} else {
V_39 = F_36 ( V_37 , V_62 ) ;
if ( ! V_39 )
V_59 = - V_76 ;
V_67 = V_77 ;
}
if ( V_59 ) {
F_24 ( V_59 ) ;
goto V_74;
}
F_37 ( V_39 ) ;
if ( V_66 )
memset ( V_39 -> V_43 , 0 , V_37 -> V_42 ) ;
memcpy ( V_39 -> V_43 + V_56 , V_50 , V_51 ) ;
F_38 ( V_39 -> V_78 ) ;
F_39 ( V_39 ) ;
F_40 ( V_39 ) ;
F_41 ( F_23 ( V_53 ) , V_39 ) ;
V_59 = F_42 ( V_68 , F_23 ( V_53 ) , V_39 ,
V_67 ) ;
if ( V_59 < 0 ) {
F_29 ( V_39 ) ;
goto V_74;
}
F_43 ( V_68 , V_39 ) ;
F_29 ( V_39 ) ;
V_74:
if ( V_59 ) {
F_24 ( V_59 ) ;
return V_59 ;
}
V_53 -> V_79 ++ ;
F_44 ( V_68 , V_53 , V_32 -> V_73 ) ;
return V_51 ;
}
int F_45 ( struct V_31 * V_32 , int V_80 )
{
int V_81 ;
struct V_38 * V_39 = NULL ;
V_81 = F_46 ( V_32 -> V_54 , & V_39 , V_80 ) ;
if ( V_81 < 0 )
return V_81 ;
F_47 ( & V_82 ) ;
if ( ! V_32 -> V_83 ++ )
V_32 -> V_73 = V_39 ;
else
F_33 ( V_39 != V_32 -> V_73 ) ;
F_48 ( & V_82 ) ;
if ( V_80 ) {
F_49 ( & V_32 -> V_54 -> V_84 ) ;
F_50 ( & F_51 ( V_32 -> V_54 ) -> V_85 ) ;
} else {
F_52 ( & F_51 ( V_32 -> V_54 ) -> V_85 ) ;
}
return 0 ;
}
void F_53 ( struct V_31 * V_32 , int V_80 )
{
if ( V_80 ) {
F_54 ( & F_51 ( V_32 -> V_54 ) -> V_85 ) ;
F_55 ( & V_32 -> V_54 -> V_84 ) ;
} else {
F_56 ( & F_51 ( V_32 -> V_54 ) -> V_85 ) ;
}
F_57 ( V_32 -> V_54 , V_80 ) ;
F_29 ( V_32 -> V_73 ) ;
F_47 ( & V_82 ) ;
if ( ! -- V_32 -> V_83 )
V_32 -> V_73 = NULL ;
F_48 ( & V_82 ) ;
}
int F_58 ( struct V_36 * V_37 , int type )
{
struct V_46 * V_53 = NULL ;
unsigned int V_86 [ V_87 ] = { V_88 ,
V_89 } ;
struct V_90 V_91 ;
struct V_64 * V_65 = F_11 ( V_37 , type ) ;
struct V_31 * V_32 = V_65 -> V_34 ;
T_1 V_63 ;
int V_81 ;
V_53 = F_59 ( F_60 ( V_37 ) , V_86 [ type ] ,
V_92 ) ;
if ( ! V_53 ) {
F_32 ( V_69 , L_3 ,
type ) ;
V_81 = - V_93 ;
goto V_94;
}
V_32 -> V_35 . V_95 = V_37 ;
V_32 -> V_35 . V_96 = type ;
F_61 ( & V_32 -> V_97 , V_32 ) ;
V_32 -> V_35 . V_98 = sizeof( struct V_3 ) ;
V_32 -> V_35 . V_99 = & V_100 ;
V_32 -> V_73 = NULL ;
V_32 -> V_83 = 0 ;
V_32 -> V_54 = V_53 ;
V_81 = F_45 ( V_32 , 0 ) ;
if ( V_81 < 0 ) {
F_24 ( V_81 ) ;
goto V_94;
}
V_81 = F_28 ( V_53 , 0 , & V_32 -> V_101 ,
& V_63 , NULL ) ;
if ( V_81 < 0 )
goto V_102;
V_81 = F_62 ( V_32 , 0 ) ;
if ( V_81 < 0 )
goto V_102;
V_81 = V_37 -> V_103 -> V_104 ( V_37 , type , ( char * ) & V_91 ,
sizeof( struct V_90 ) ,
V_105 ) ;
F_63 ( V_32 , 0 ) ;
F_53 ( V_32 , 0 ) ;
if ( V_81 != sizeof( struct V_90 ) ) {
F_32 ( V_69 , L_4 ,
V_81 ) ;
if ( V_81 >= 0 )
V_81 = - V_70 ;
F_24 ( V_81 ) ;
goto V_94;
}
V_65 -> V_106 = F_5 ( V_91 . V_106 ) ;
V_65 -> V_107 = F_5 ( V_91 . V_107 ) ;
V_32 -> V_108 = F_5 ( V_91 . V_108 ) ;
V_32 -> V_35 . V_109 = F_5 ( V_91 . V_109 ) ;
V_32 -> V_35 . V_110 = F_5 ( V_91 . V_110 ) ;
V_32 -> V_35 . V_111 = F_5 ( V_91 . V_111 ) ;
V_32 -> V_35 . V_112 = V_37 -> V_58 ;
V_32 -> V_35 . V_113 = V_37 -> V_42 -
V_71 ;
V_32 -> V_35 . V_114 = F_64 ( & V_32 -> V_35 ) ;
F_65 ( & V_32 -> V_115 , V_116 ) ;
F_66 ( & V_32 -> V_115 ,
F_67 ( V_32 -> V_108 ) ) ;
V_94:
return V_81 ;
V_102:
F_53 ( V_32 , 0 ) ;
F_24 ( V_81 ) ;
goto V_94;
}
static int F_68 ( struct V_36 * V_37 , int type )
{
struct V_64 * V_65 = F_11 ( V_37 , type ) ;
struct V_31 * V_32 = V_65 -> V_34 ;
struct V_90 V_91 ;
T_2 V_117 ;
F_47 ( & V_82 ) ;
V_65 -> V_118 &= ~ V_119 ;
V_91 . V_106 = F_7 ( V_65 -> V_106 ) ;
V_91 . V_107 = F_7 ( V_65 -> V_107 ) ;
F_48 ( & V_82 ) ;
V_91 . V_108 = F_7 ( V_32 -> V_108 ) ;
V_91 . V_109 = F_7 ( V_32 -> V_35 . V_109 ) ;
V_91 . V_110 = F_7 ( V_32 -> V_35 . V_110 ) ;
V_91 . V_111 = F_7 ( V_32 -> V_35 . V_111 ) ;
V_117 = V_37 -> V_103 -> V_120 ( V_37 , type , ( char * ) & V_91 ,
sizeof( struct V_90 ) ,
V_105 ) ;
if ( V_117 != sizeof( struct V_90 ) ) {
F_32 ( V_69 , L_5 ) ;
if ( V_117 >= 0 )
V_117 = - V_70 ;
return V_117 ;
}
return 0 ;
}
int F_69 ( struct V_36 * V_37 , int type )
{
int V_59 ;
struct V_31 * V_65 = F_11 ( V_37 , type ) -> V_34 ;
V_59 = F_62 ( V_65 , 1 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_68 ( V_37 , type ) ;
F_63 ( V_65 , 1 ) ;
return V_59 ;
}
static int F_70 ( struct V_36 * V_37 , int type )
{
struct V_31 * V_32 = F_11 ( V_37 , type ) -> V_34 ;
return V_32 -> V_35 . V_114 ;
}
static int F_71 ( struct V_36 * V_37 , int type )
{
return ( F_70 ( V_37 , type ) + 2 ) *
V_121 + 1 ;
}
int F_72 ( struct V_1 * V_1 , int V_122 )
{
int V_59 , V_123 ;
struct V_36 * V_37 = V_1 -> V_33 ;
int type = V_1 -> V_28 . type ;
struct V_31 * V_65 = F_11 ( V_37 , type ) -> V_34 ;
struct V_3 V_124 ;
T_7 V_125 , V_126 ;
T_8 V_127 , V_128 ;
V_59 = V_37 -> V_103 -> V_104 ( V_37 , type , ( char * ) & V_124 ,
sizeof( struct V_3 ) ,
V_1 -> V_129 ) ;
if ( V_59 != sizeof( struct V_3 ) ) {
if ( V_59 >= 0 ) {
F_32 ( V_69 , L_6
L_7 , V_59 ) ;
V_59 = - V_70 ;
}
goto V_74;
}
F_47 ( & V_82 ) ;
V_125 = V_1 -> V_7 . V_19 -
F_4 ( V_1 ) -> V_130 ;
V_126 = V_1 -> V_7 . V_14 -
F_4 ( V_1 ) -> V_131 ;
V_127 = V_1 -> V_7 . V_23 ;
V_128 = V_1 -> V_7 . V_21 ;
F_1 ( V_1 , & V_124 ) ;
F_73 ( F_8 ( & V_27 , V_1 -> V_28 ) ,
V_1 -> V_7 . V_19 ,
( long long ) V_125 ,
V_1 -> V_7 . V_14 ,
( long long ) V_126 ) ;
if ( ! F_2 ( V_8 + V_18 , & V_1 -> V_10 ) )
V_1 -> V_7 . V_19 += V_125 ;
if ( ! F_2 ( V_8 + V_13 , & V_1 -> V_10 ) )
V_1 -> V_7 . V_14 += V_126 ;
if ( V_1 -> V_7 . V_17 &&
V_1 -> V_7 . V_19 > V_1 -> V_7 . V_17 ) {
if ( ! F_2 ( V_8 + V_20 , & V_1 -> V_10 ) &&
V_128 > 0 ) {
if ( V_1 -> V_7 . V_21 > 0 )
V_1 -> V_7 . V_21 =
F_74 ( V_1 -> V_7 . V_21 , V_128 ) ;
else
V_1 -> V_7 . V_21 = V_128 ;
}
} else {
V_1 -> V_7 . V_21 = 0 ;
F_75 ( V_132 , & V_1 -> V_10 ) ;
}
if ( V_1 -> V_7 . V_12 &&
V_1 -> V_7 . V_14 > V_1 -> V_7 . V_12 ) {
if ( ! F_2 ( V_8 + V_22 , & V_1 -> V_10 ) &&
V_127 > 0 ) {
if ( V_1 -> V_7 . V_23 > 0 )
V_1 -> V_7 . V_23 =
F_74 ( V_1 -> V_7 . V_23 , V_127 ) ;
else
V_1 -> V_7 . V_23 = V_127 ;
}
} else {
V_1 -> V_7 . V_23 = 0 ;
F_75 ( V_133 , & V_1 -> V_10 ) ;
}
F_76 ( V_8 + V_18 , & V_1 -> V_10 ) ;
F_76 ( V_8 + V_13 , & V_1 -> V_10 ) ;
F_76 ( V_8 + V_15 , & V_1 -> V_10 ) ;
F_76 ( V_8 + V_9 , & V_1 -> V_10 ) ;
F_76 ( V_8 + V_20 , & V_1 -> V_10 ) ;
F_76 ( V_8 + V_22 , & V_1 -> V_10 ) ;
F_4 ( V_1 ) -> V_130 = V_1 -> V_7 . V_19 ;
F_4 ( V_1 ) -> V_131 = V_1 -> V_7 . V_14 ;
F_48 ( & V_82 ) ;
V_59 = F_62 ( V_65 , V_122 ) ;
if ( V_59 < 0 ) {
F_32 ( V_69 , L_8
L_9 , V_1 -> V_28 . type ,
( unsigned ) F_8 ( & V_27 , V_1 -> V_28 ) ) ;
goto V_74;
}
if ( V_122 )
F_4 ( V_1 ) -> V_24 -- ;
V_59 = F_77 ( & V_65 -> V_35 , V_1 ) ;
if ( V_59 < 0 )
goto V_134;
if ( V_122 && ! F_4 ( V_1 ) -> V_24 ) {
V_59 = F_78 ( & V_65 -> V_35 , V_1 ) ;
if ( F_79 ( F_11 ( V_37 , type ) ) ) {
V_123 = F_68 ( V_37 , type ) ;
if ( ! V_59 )
V_59 = V_123 ;
}
}
V_134:
F_63 ( V_65 , V_122 ) ;
V_74:
if ( V_59 < 0 )
F_24 ( V_59 ) ;
return V_59 ;
}
static int F_80 ( struct V_1 * V_1 , unsigned long type )
{
T_6 * V_68 ;
struct V_36 * V_37 = V_1 -> V_33 ;
struct V_31 * V_32 = F_11 ( V_37 , type ) -> V_34 ;
struct V_135 * V_136 = F_60 ( V_37 ) ;
int V_81 = 0 ;
F_81 ( F_8 ( & V_27 , V_1 -> V_28 ) ,
V_1 -> V_28 . type ,
type , V_37 -> V_137 ) ;
if ( type != V_1 -> V_28 . type )
goto V_74;
V_81 = F_45 ( V_32 , 1 ) ;
if ( V_81 < 0 )
goto V_74;
V_68 = F_82 ( V_136 , V_138 ) ;
if ( F_83 ( V_68 ) ) {
V_81 = F_84 ( V_68 ) ;
F_24 ( V_81 ) ;
goto V_139;
}
F_49 ( & F_85 ( V_37 ) -> V_140 ) ;
V_81 = F_86 ( V_1 ) ;
if ( V_81 < 0 )
F_24 ( V_81 ) ;
V_81 = F_87 ( V_1 ) ;
if ( V_81 < 0 )
F_24 ( V_81 ) ;
F_55 ( & F_85 ( V_37 ) -> V_140 ) ;
F_88 ( V_136 , V_68 ) ;
V_139:
F_53 ( V_32 , 1 ) ;
V_74:
return V_81 ;
}
static void V_116 ( struct V_141 * V_142 )
{
struct V_31 * V_32 = F_89 ( V_142 ,
struct V_31 ,
V_115 . V_142 ) ;
struct V_36 * V_37 = V_32 -> V_54 -> V_143 ;
F_90 ( V_37 , F_80 , V_32 -> V_96 ) ;
F_66 ( & V_32 -> V_115 ,
F_67 ( V_32 -> V_108 ) ) ;
}
static int F_91 ( struct V_1 * V_1 )
{
T_6 * V_68 ;
struct V_135 * V_136 = F_60 ( V_1 -> V_33 ) ;
int V_81 = 0 ;
F_92 ( F_8 ( & V_27 , V_1 -> V_28 ) ,
V_1 -> V_28 . type ) ;
V_68 = F_82 ( V_136 , V_144 ) ;
if ( F_83 ( V_68 ) ) {
V_81 = F_84 ( V_68 ) ;
F_24 ( V_81 ) ;
goto V_74;
}
F_49 ( & F_85 ( V_1 -> V_33 ) -> V_140 ) ;
V_81 = F_87 ( V_1 ) ;
F_55 ( & F_85 ( V_1 -> V_33 ) -> V_140 ) ;
F_88 ( V_136 , V_68 ) ;
V_74:
return V_81 ;
}
static int F_93 ( struct V_36 * V_37 , int type )
{
struct V_31 * V_32 = F_11 ( V_37 , type ) -> V_34 ;
return ( V_32 -> V_35 . V_114 + 2 ) *
V_121 +
V_145 +
V_146 ;
}
void F_94 ( struct V_141 * V_142 )
{
struct V_135 * V_136 = F_89 ( V_142 , struct V_135 ,
V_147 ) ;
struct V_148 * V_149 ;
struct V_150 * V_151 , * V_152 ;
V_149 = F_95 ( & V_136 -> V_153 ) ;
F_96 (odquot, next_odquot, list, list) {
F_97 ( & V_151 -> V_154 ) ;
}
}
static int F_98 ( struct V_1 * V_1 )
{
T_6 * V_68 ;
struct V_31 * V_32 =
F_11 ( V_1 -> V_33 , V_1 -> V_28 . type ) -> V_34 ;
struct V_135 * V_136 = F_60 ( V_1 -> V_33 ) ;
int V_81 = 0 ;
F_99 ( F_8 ( & V_27 , V_1 -> V_28 ) ,
V_1 -> V_28 . type ) ;
F_49 ( & V_1 -> V_155 ) ;
if ( F_100 ( & V_1 -> V_156 ) > 1 )
goto V_74;
if ( V_157 == V_136 -> V_158 ) {
F_101 ( V_1 ) ;
if ( F_102 ( & F_4 ( V_1 ) -> V_149 , & V_136 -> V_153 ) )
F_103 ( V_159 , & V_136 -> V_147 ) ;
goto V_74;
}
V_81 = F_45 ( V_32 , 1 ) ;
if ( V_81 < 0 )
goto V_74;
V_68 = F_82 ( V_136 ,
F_93 ( V_1 -> V_33 , V_1 -> V_28 . type ) ) ;
if ( F_83 ( V_68 ) ) {
V_81 = F_84 ( V_68 ) ;
F_24 ( V_81 ) ;
goto V_139;
}
V_81 = F_104 ( V_1 ) ;
if ( V_81 < 0 ) {
F_24 ( V_81 ) ;
goto V_160;
}
V_81 = F_105 ( V_68 , V_1 ) ;
if ( V_81 < 0 )
F_24 ( V_81 ) ;
V_1 -> V_129 = 0 ;
F_75 ( V_161 , & V_1 -> V_10 ) ;
V_160:
F_88 ( V_136 , V_68 ) ;
V_139:
F_53 ( V_32 , 1 ) ;
V_74:
F_55 ( & V_1 -> V_155 ) ;
if ( V_81 )
F_24 ( V_81 ) ;
return V_81 ;
}
static int F_106 ( struct V_1 * V_1 )
{
int V_81 = 0 , V_59 ;
int V_80 = 0 ;
struct V_36 * V_37 = V_1 -> V_33 ;
struct V_135 * V_136 = F_60 ( V_37 ) ;
int type = V_1 -> V_28 . type ;
struct V_31 * V_65 = F_11 ( V_37 , type ) -> V_34 ;
struct V_46 * V_53 = V_65 -> V_54 ;
int V_162 = F_70 ( V_37 , type ) ;
T_6 * V_68 ;
F_107 ( F_8 ( & V_27 , V_1 -> V_28 ) ,
type ) ;
F_49 ( & V_1 -> V_155 ) ;
V_81 = F_45 ( V_65 , 1 ) ;
if ( V_81 < 0 )
goto V_74;
V_81 = F_62 ( V_65 , 0 ) ;
if ( V_81 < 0 )
goto V_163;
V_81 = F_108 ( & V_65 -> V_35 , V_1 ) ;
F_63 ( V_65 , 0 ) ;
if ( V_81 < 0 )
goto V_163;
F_4 ( V_1 ) -> V_24 ++ ;
F_4 ( V_1 ) -> V_130 = V_1 -> V_7 . V_19 ;
F_4 ( V_1 ) -> V_131 = V_1 -> V_7 . V_14 ;
if ( ! V_1 -> V_129 ) {
V_80 = 1 ;
F_33 ( F_31 () ) ;
V_81 = F_109 ( V_53 , NULL ,
F_26 ( V_53 ) + ( V_162 << V_37 -> V_58 ) ,
F_26 ( V_53 ) ) ;
if ( V_81 < 0 )
goto V_163;
}
V_68 = F_82 ( V_136 ,
F_71 ( V_37 , type ) ) ;
if ( F_83 ( V_68 ) ) {
V_81 = F_84 ( V_68 ) ;
goto V_163;
}
V_81 = F_62 ( V_65 , V_80 ) ;
if ( V_81 < 0 )
goto V_160;
V_81 = F_77 ( & V_65 -> V_35 , V_1 ) ;
if ( V_80 && F_79 ( F_11 ( V_37 , type ) ) ) {
V_59 = F_68 ( V_37 , type ) ;
if ( ! V_81 )
V_81 = V_59 ;
}
F_63 ( V_65 , V_80 ) ;
V_160:
F_88 ( V_136 , V_68 ) ;
V_163:
F_53 ( V_65 , 1 ) ;
if ( V_81 < 0 )
goto V_74;
V_81 = F_110 ( V_1 ) ;
if ( V_81 < 0 )
goto V_74;
F_111 ( V_161 , & V_1 -> V_10 ) ;
V_74:
F_55 ( & V_1 -> V_155 ) ;
if ( V_81 )
F_24 ( V_81 ) ;
return V_81 ;
}
static int F_112 ( struct V_1 * V_1 )
{
unsigned long V_164 = ( 1 << ( V_8 + V_9 ) ) |
( 1 << ( V_8 + V_15 ) ) |
( 1 << ( V_8 + V_13 ) ) |
( 1 << ( V_8 + V_18 ) ) |
( 1 << ( V_8 + V_20 ) ) |
( 1 << ( V_8 + V_22 ) ) ;
int V_165 = 0 ;
int V_81 ;
struct V_36 * V_37 = V_1 -> V_33 ;
int type = V_1 -> V_28 . type ;
struct V_31 * V_32 = F_11 ( V_37 , type ) -> V_34 ;
T_6 * V_68 ;
struct V_135 * V_136 = F_60 ( V_37 ) ;
F_113 ( F_8 ( & V_27 , V_1 -> V_28 ) ,
type ) ;
F_47 ( & V_82 ) ;
if ( V_1 -> V_10 & V_164 )
V_165 = 1 ;
F_48 ( & V_82 ) ;
if ( ! V_165 || F_31 () ) {
V_81 = F_91 ( V_1 ) ;
goto V_74;
}
V_81 = F_45 ( V_32 , 1 ) ;
if ( V_81 < 0 )
goto V_74;
V_68 = F_82 ( V_136 , V_138 ) ;
if ( F_83 ( V_68 ) ) {
V_81 = F_84 ( V_68 ) ;
F_24 ( V_81 ) ;
goto V_139;
}
F_49 ( & F_85 ( V_37 ) -> V_140 ) ;
V_81 = F_86 ( V_1 ) ;
if ( V_81 < 0 ) {
F_24 ( V_81 ) ;
goto V_166;
}
V_81 = F_87 ( V_1 ) ;
V_166:
F_55 ( & F_85 ( V_37 ) -> V_140 ) ;
F_88 ( V_136 , V_68 ) ;
V_139:
F_53 ( V_32 , 1 ) ;
V_74:
if ( V_81 )
F_24 ( V_81 ) ;
return V_81 ;
}
static int F_114 ( struct V_36 * V_37 , int type )
{
T_6 * V_68 ;
int V_81 = 0 ;
struct V_31 * V_32 = F_11 ( V_37 , type ) -> V_34 ;
V_81 = F_45 ( V_32 , 1 ) ;
if ( V_81 < 0 )
goto V_74;
V_68 = F_82 ( F_60 ( V_37 ) , V_145 ) ;
if ( F_83 ( V_68 ) ) {
V_81 = F_84 ( V_68 ) ;
F_24 ( V_81 ) ;
goto V_139;
}
V_81 = F_115 ( V_37 , type ) ;
F_88 ( F_60 ( V_37 ) , V_68 ) ;
V_139:
F_53 ( V_32 , 1 ) ;
V_74:
if ( V_81 )
F_24 ( V_81 ) ;
return V_81 ;
}
static struct V_1 * F_116 ( struct V_36 * V_37 , int type )
{
struct V_150 * V_1 =
F_117 ( V_167 , V_168 ) ;
if ( ! V_1 )
return NULL ;
return & V_1 -> V_154 ;
}
static void F_118 ( struct V_1 * V_1 )
{
F_119 ( V_167 , V_1 ) ;
}
