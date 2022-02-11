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
V_4 -> V_26 = F_7 ( V_1 -> V_27 ) ;
V_4 -> V_25 = F_7 ( F_4 ( V_1 ) -> V_24 ) ;
V_4 -> V_11 = F_8 ( V_6 -> V_11 ) ;
V_4 -> V_12 = F_8 ( V_6 -> V_12 ) ;
V_4 -> V_14 = F_8 ( V_6 -> V_14 ) ;
V_4 -> V_16 = F_8 ( V_6 -> V_16 ) ;
V_4 -> V_17 = F_8 ( V_6 -> V_17 ) ;
V_4 -> V_19 = F_8 ( V_6 -> V_19 ) ;
V_4 -> V_21 = F_8 ( V_6 -> V_21 ) ;
V_4 -> V_23 = F_8 ( V_6 -> V_23 ) ;
V_4 -> V_28 = V_4 -> V_29 = 0 ;
}
static int F_9 ( void * V_2 , struct V_1 * V_1 )
{
struct V_3 * V_4 = V_2 ;
struct V_30 * V_31 =
F_10 ( V_1 -> V_32 , V_1 -> V_33 ) -> V_34 ;
if ( F_11 ( & V_31 -> V_35 , V_2 ) )
return 0 ;
return F_5 ( V_4 -> V_26 ) == V_1 -> V_27 ;
}
int F_12 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_40 * V_41 =
F_13 ( V_37 -> V_42 , V_39 -> V_43 ) ;
F_14 ( ( unsigned long long ) V_39 -> V_44 ) ;
F_15 ( ! F_16 ( V_39 ) ) ;
return F_17 ( V_37 , V_39 -> V_43 , & V_41 -> V_45 ) ;
}
int F_18 ( struct V_46 * V_46 , T_1 V_47 ,
struct V_38 * * V_48 )
{
int V_49 ;
* V_48 = NULL ;
V_49 = F_19 ( F_20 ( V_46 ) , V_47 , 1 , V_48 , 0 ,
F_12 ) ;
if ( V_49 )
F_21 ( V_49 ) ;
return V_49 ;
}
T_2 F_22 ( struct V_36 * V_37 , int type , char * V_50 ,
T_3 V_51 , T_4 V_52 )
{
struct V_30 * V_31 = F_10 ( V_37 , type ) -> V_34 ;
struct V_46 * V_53 = V_31 -> V_54 ;
T_4 V_55 = F_23 ( V_53 ) ;
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
V_61 = F_24 ( T_3 , ( V_37 -> V_42 - V_56 ) , V_60 ) ;
if ( ! V_63 ) {
V_59 = F_25 ( V_53 , V_57 , & V_62 ,
& V_63 , NULL ) ;
if ( V_59 ) {
F_21 ( V_59 ) ;
return V_59 ;
}
} else {
V_63 -- ;
V_62 ++ ;
}
V_39 = NULL ;
V_59 = F_18 ( V_53 , V_62 , & V_39 ) ;
if ( V_59 ) {
F_21 ( V_59 ) ;
return V_59 ;
}
memcpy ( V_50 , V_39 -> V_43 + V_56 , V_61 ) ;
F_26 ( V_39 ) ;
V_56 = 0 ;
V_60 -= V_61 ;
V_50 += V_61 ;
V_57 ++ ;
}
return V_51 ;
}
T_2 F_27 ( struct V_36 * V_37 , int type ,
const char * V_50 , T_3 V_51 , T_4 V_52 )
{
struct V_64 * V_65 = F_10 ( V_37 , type ) ;
struct V_30 * V_31 = V_65 -> V_34 ;
struct V_46 * V_53 = V_31 -> V_54 ;
int V_56 = V_52 & ( V_37 -> V_42 - 1 ) ;
T_5 V_57 = V_52 >> V_37 -> V_58 ;
int V_59 = 0 , V_66 = 0 , V_67 ;
struct V_38 * V_39 = NULL ;
T_6 * V_68 = F_28 () ;
T_1 V_62 , V_63 ;
if ( ! V_68 ) {
F_29 ( V_69 , L_1
L_2 ,
( unsigned long long ) V_52 , ( unsigned long long ) V_51 ) ;
return - V_70 ;
}
if ( V_51 > V_37 -> V_42 - V_71 - V_56 ) {
F_30 ( 1 ) ;
V_51 = V_37 -> V_42 - V_71 - V_56 ;
}
if ( V_53 -> V_55 < V_52 + V_51 ) {
T_4 V_72 =
F_31 ( V_37 , V_52 + V_51 ) ;
V_59 = F_32 ( V_53 ,
V_31 -> V_73 ,
V_72 ) ;
if ( V_59 < 0 )
goto V_74;
V_66 = 1 ;
}
V_59 = F_25 ( V_53 , V_57 , & V_62 , & V_63 , NULL ) ;
if ( V_59 ) {
F_21 ( V_59 ) ;
goto V_74;
}
if ( ( V_56 || V_51 < V_37 -> V_42 - V_71 ) &&
! V_66 ) {
V_59 = F_18 ( V_53 , V_62 , & V_39 ) ;
V_67 = V_75 ;
} else {
V_39 = F_33 ( V_37 , V_62 ) ;
if ( ! V_39 )
V_59 = - V_76 ;
V_67 = V_77 ;
}
if ( V_59 ) {
F_21 ( V_59 ) ;
goto V_74;
}
F_34 ( V_39 ) ;
if ( V_66 )
memset ( V_39 -> V_43 , 0 , V_37 -> V_42 ) ;
memcpy ( V_39 -> V_43 + V_56 , V_50 , V_51 ) ;
F_35 ( V_39 -> V_78 ) ;
F_36 ( V_39 ) ;
F_37 ( V_39 ) ;
F_38 ( F_20 ( V_53 ) , V_39 ) ;
V_59 = F_39 ( V_68 , F_20 ( V_53 ) , V_39 ,
V_67 ) ;
if ( V_59 < 0 ) {
F_26 ( V_39 ) ;
goto V_74;
}
F_40 ( V_68 , V_39 ) ;
F_26 ( V_39 ) ;
V_74:
if ( V_59 ) {
F_21 ( V_59 ) ;
return V_59 ;
}
V_53 -> V_79 ++ ;
F_41 ( V_68 , V_53 , V_31 -> V_73 ) ;
return V_51 ;
}
int F_42 ( struct V_30 * V_31 , int V_80 )
{
int V_81 ;
struct V_38 * V_39 = NULL ;
V_81 = F_43 ( V_31 -> V_54 , & V_39 , V_80 ) ;
if ( V_81 < 0 )
return V_81 ;
F_44 ( & V_82 ) ;
if ( ! V_31 -> V_83 ++ )
V_31 -> V_73 = V_39 ;
else
F_30 ( V_39 != V_31 -> V_73 ) ;
F_45 ( & V_82 ) ;
if ( V_80 ) {
F_46 ( & V_31 -> V_54 -> V_84 ) ;
F_47 ( & F_48 ( V_31 -> V_54 ) -> V_85 ) ;
} else {
F_49 ( & F_48 ( V_31 -> V_54 ) -> V_85 ) ;
}
return 0 ;
}
void F_50 ( struct V_30 * V_31 , int V_80 )
{
if ( V_80 ) {
F_51 ( & F_48 ( V_31 -> V_54 ) -> V_85 ) ;
F_52 ( & V_31 -> V_54 -> V_84 ) ;
} else {
F_53 ( & F_48 ( V_31 -> V_54 ) -> V_85 ) ;
}
F_54 ( V_31 -> V_54 , V_80 ) ;
F_26 ( V_31 -> V_73 ) ;
F_44 ( & V_82 ) ;
if ( ! -- V_31 -> V_83 )
V_31 -> V_73 = NULL ;
F_45 ( & V_82 ) ;
}
int F_55 ( struct V_36 * V_37 , int type )
{
struct V_46 * V_53 = NULL ;
unsigned int V_86 [ V_87 ] = { V_88 ,
V_89 } ;
struct V_90 V_91 ;
struct V_64 * V_65 = F_10 ( V_37 , type ) ;
struct V_30 * V_31 = V_65 -> V_34 ;
T_1 V_63 ;
int V_81 ;
V_53 = F_56 ( F_57 ( V_37 ) , V_86 [ type ] ,
V_92 ) ;
if ( ! V_53 ) {
F_29 ( V_69 , L_3 ,
type ) ;
V_81 = - V_93 ;
goto V_94;
}
V_31 -> V_35 . V_95 = V_37 ;
V_31 -> V_35 . V_96 = type ;
F_58 ( & V_31 -> V_97 , V_31 ) ;
V_31 -> V_35 . V_98 = sizeof( struct V_3 ) ;
V_31 -> V_35 . V_99 = & V_100 ;
V_31 -> V_73 = NULL ;
V_31 -> V_83 = 0 ;
V_31 -> V_54 = V_53 ;
V_81 = F_42 ( V_31 , 0 ) ;
if ( V_81 < 0 ) {
F_21 ( V_81 ) ;
goto V_94;
}
V_81 = F_25 ( V_53 , 0 , & V_31 -> V_101 ,
& V_63 , NULL ) ;
if ( V_81 < 0 )
goto V_102;
V_81 = F_59 ( V_31 , 0 ) ;
if ( V_81 < 0 )
goto V_102;
V_81 = V_37 -> V_103 -> V_104 ( V_37 , type , ( char * ) & V_91 ,
sizeof( struct V_90 ) ,
V_105 ) ;
F_60 ( V_31 , 0 ) ;
F_50 ( V_31 , 0 ) ;
if ( V_81 != sizeof( struct V_90 ) ) {
F_29 ( V_69 , L_4 ,
V_81 ) ;
if ( V_81 >= 0 )
V_81 = - V_70 ;
F_21 ( V_81 ) ;
goto V_94;
}
V_65 -> V_106 = F_5 ( V_91 . V_106 ) ;
V_65 -> V_107 = F_5 ( V_91 . V_107 ) ;
V_31 -> V_108 = F_5 ( V_91 . V_108 ) ;
V_31 -> V_35 . V_109 = F_5 ( V_91 . V_109 ) ;
V_31 -> V_35 . V_110 = F_5 ( V_91 . V_110 ) ;
V_31 -> V_35 . V_111 = F_5 ( V_91 . V_111 ) ;
V_31 -> V_35 . V_112 = V_37 -> V_58 ;
V_31 -> V_35 . V_113 = V_37 -> V_42 -
V_71 ;
V_31 -> V_35 . V_114 = F_61 ( & V_31 -> V_35 ) ;
F_62 ( & V_31 -> V_115 , V_116 ) ;
F_63 ( & V_31 -> V_115 ,
F_64 ( V_31 -> V_108 ) ) ;
V_94:
if ( V_81 )
F_21 ( V_81 ) ;
return V_81 ;
V_102:
F_50 ( V_31 , 0 ) ;
F_21 ( V_81 ) ;
goto V_94;
}
static int F_65 ( struct V_36 * V_37 , int type )
{
struct V_64 * V_65 = F_10 ( V_37 , type ) ;
struct V_30 * V_31 = V_65 -> V_34 ;
struct V_90 V_91 ;
T_2 V_117 ;
F_44 ( & V_82 ) ;
V_65 -> V_118 &= ~ V_119 ;
V_91 . V_106 = F_7 ( V_65 -> V_106 ) ;
V_91 . V_107 = F_7 ( V_65 -> V_107 ) ;
F_45 ( & V_82 ) ;
V_91 . V_108 = F_7 ( V_31 -> V_108 ) ;
V_91 . V_109 = F_7 ( V_31 -> V_35 . V_109 ) ;
V_91 . V_110 = F_7 ( V_31 -> V_35 . V_110 ) ;
V_91 . V_111 = F_7 ( V_31 -> V_35 . V_111 ) ;
V_117 = V_37 -> V_103 -> V_120 ( V_37 , type , ( char * ) & V_91 ,
sizeof( struct V_90 ) ,
V_105 ) ;
if ( V_117 != sizeof( struct V_90 ) ) {
F_29 ( V_69 , L_5 ) ;
if ( V_117 >= 0 )
V_117 = - V_70 ;
return V_117 ;
}
return 0 ;
}
int F_66 ( struct V_36 * V_37 , int type )
{
int V_59 ;
struct V_30 * V_65 = F_10 ( V_37 , type ) -> V_34 ;
V_59 = F_59 ( V_65 , 1 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_65 ( V_37 , type ) ;
F_60 ( V_65 , 1 ) ;
return V_59 ;
}
static int F_67 ( struct V_36 * V_37 , int type )
{
struct V_30 * V_31 = F_10 ( V_37 , type ) -> V_34 ;
return V_31 -> V_35 . V_114 ;
}
static int F_68 ( struct V_36 * V_37 , int type )
{
return ( F_67 ( V_37 , type ) + 2 ) *
V_121 + 1 ;
}
int F_69 ( struct V_1 * V_1 , int V_122 )
{
int V_59 , V_123 ;
struct V_36 * V_37 = V_1 -> V_32 ;
int type = V_1 -> V_33 ;
struct V_30 * V_65 = F_10 ( V_37 , type ) -> V_34 ;
struct V_3 V_124 ;
T_7 V_125 , V_126 ;
T_8 V_127 , V_128 ;
V_59 = V_37 -> V_103 -> V_104 ( V_37 , type , ( char * ) & V_124 ,
sizeof( struct V_3 ) ,
V_1 -> V_129 ) ;
if ( V_59 != sizeof( struct V_3 ) ) {
if ( V_59 >= 0 ) {
F_29 ( V_69 , L_6
L_7 , V_59 ) ;
V_59 = - V_70 ;
}
goto V_74;
}
F_44 ( & V_82 ) ;
V_125 = V_1 -> V_7 . V_19 -
F_4 ( V_1 ) -> V_130 ;
V_126 = V_1 -> V_7 . V_14 -
F_4 ( V_1 ) -> V_131 ;
V_127 = V_1 -> V_7 . V_23 ;
V_128 = V_1 -> V_7 . V_21 ;
F_1 ( V_1 , & V_124 ) ;
F_70 ( V_1 -> V_27 , V_1 -> V_7 . V_19 ,
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
F_71 ( V_1 -> V_7 . V_21 , V_128 ) ;
else
V_1 -> V_7 . V_21 = V_128 ;
}
} else {
V_1 -> V_7 . V_21 = 0 ;
F_72 ( V_132 , & V_1 -> V_10 ) ;
}
if ( V_1 -> V_7 . V_12 &&
V_1 -> V_7 . V_14 > V_1 -> V_7 . V_12 ) {
if ( ! F_2 ( V_8 + V_22 , & V_1 -> V_10 ) &&
V_127 > 0 ) {
if ( V_1 -> V_7 . V_23 > 0 )
V_1 -> V_7 . V_23 =
F_71 ( V_1 -> V_7 . V_23 , V_127 ) ;
else
V_1 -> V_7 . V_23 = V_127 ;
}
} else {
V_1 -> V_7 . V_23 = 0 ;
F_72 ( V_133 , & V_1 -> V_10 ) ;
}
F_73 ( V_8 + V_18 , & V_1 -> V_10 ) ;
F_73 ( V_8 + V_13 , & V_1 -> V_10 ) ;
F_73 ( V_8 + V_15 , & V_1 -> V_10 ) ;
F_73 ( V_8 + V_9 , & V_1 -> V_10 ) ;
F_73 ( V_8 + V_20 , & V_1 -> V_10 ) ;
F_73 ( V_8 + V_22 , & V_1 -> V_10 ) ;
F_4 ( V_1 ) -> V_130 = V_1 -> V_7 . V_19 ;
F_4 ( V_1 ) -> V_131 = V_1 -> V_7 . V_14 ;
F_45 ( & V_82 ) ;
V_59 = F_59 ( V_65 , V_122 ) ;
if ( V_59 < 0 ) {
F_29 ( V_69 , L_8
L_9 , V_1 -> V_33 ,
( unsigned ) V_1 -> V_27 ) ;
goto V_74;
}
if ( V_122 )
F_4 ( V_1 ) -> V_24 -- ;
V_59 = F_74 ( & V_65 -> V_35 , V_1 ) ;
if ( V_59 < 0 )
goto V_134;
if ( V_122 && ! F_4 ( V_1 ) -> V_24 ) {
V_59 = F_75 ( & V_65 -> V_35 , V_1 ) ;
if ( F_76 ( F_10 ( V_37 , type ) ) ) {
V_123 = F_65 ( V_37 , type ) ;
if ( ! V_59 )
V_59 = V_123 ;
}
}
V_134:
F_60 ( V_65 , V_122 ) ;
V_74:
if ( V_59 < 0 )
F_21 ( V_59 ) ;
return V_59 ;
}
static int F_77 ( struct V_1 * V_1 , unsigned long type )
{
T_6 * V_68 ;
struct V_36 * V_37 = V_1 -> V_32 ;
struct V_30 * V_31 = F_10 ( V_37 , type ) -> V_34 ;
struct V_135 * V_136 = F_57 ( V_37 ) ;
int V_81 = 0 ;
F_78 ( V_1 -> V_27 , V_1 -> V_33 ,
type , V_37 -> V_137 ) ;
if ( type != V_1 -> V_33 )
goto V_74;
V_81 = F_42 ( V_31 , 1 ) ;
if ( V_81 < 0 )
goto V_74;
V_68 = F_79 ( V_136 , V_138 ) ;
if ( F_80 ( V_68 ) ) {
V_81 = F_81 ( V_68 ) ;
F_21 ( V_81 ) ;
goto V_139;
}
F_46 ( & F_82 ( V_37 ) -> V_140 ) ;
V_81 = F_83 ( V_1 ) ;
if ( V_81 < 0 )
F_21 ( V_81 ) ;
V_81 = F_84 ( V_1 ) ;
if ( V_81 < 0 )
F_21 ( V_81 ) ;
F_52 ( & F_82 ( V_37 ) -> V_140 ) ;
F_85 ( V_136 , V_68 ) ;
V_139:
F_50 ( V_31 , 1 ) ;
V_74:
return V_81 ;
}
static void V_116 ( struct V_141 * V_142 )
{
struct V_30 * V_31 = F_86 ( V_142 ,
struct V_30 ,
V_115 . V_142 ) ;
struct V_36 * V_37 = V_31 -> V_54 -> V_143 ;
F_87 ( V_37 , F_77 , V_31 -> V_96 ) ;
F_63 ( & V_31 -> V_115 ,
F_64 ( V_31 -> V_108 ) ) ;
}
static int F_88 ( struct V_1 * V_1 )
{
T_6 * V_68 ;
struct V_135 * V_136 = F_57 ( V_1 -> V_32 ) ;
int V_81 = 0 ;
F_89 ( V_1 -> V_27 , V_1 -> V_33 ) ;
V_68 = F_79 ( V_136 , V_144 ) ;
if ( F_80 ( V_68 ) ) {
V_81 = F_81 ( V_68 ) ;
F_21 ( V_81 ) ;
goto V_74;
}
F_46 ( & F_82 ( V_1 -> V_32 ) -> V_140 ) ;
V_81 = F_84 ( V_1 ) ;
F_52 ( & F_82 ( V_1 -> V_32 ) -> V_140 ) ;
F_85 ( V_136 , V_68 ) ;
V_74:
return V_81 ;
}
static int F_90 ( struct V_36 * V_37 , int type )
{
struct V_30 * V_31 = F_10 ( V_37 , type ) -> V_34 ;
return ( V_31 -> V_35 . V_114 + 2 ) *
V_121 +
V_145 +
V_146 ;
}
static int F_91 ( struct V_1 * V_1 )
{
T_6 * V_68 ;
struct V_30 * V_31 =
F_10 ( V_1 -> V_32 , V_1 -> V_33 ) -> V_34 ;
struct V_135 * V_136 = F_57 ( V_1 -> V_32 ) ;
int V_81 = 0 ;
F_92 ( V_1 -> V_27 , V_1 -> V_33 ) ;
F_46 ( & V_1 -> V_147 ) ;
if ( F_93 ( & V_1 -> V_148 ) > 1 )
goto V_74;
V_81 = F_42 ( V_31 , 1 ) ;
if ( V_81 < 0 )
goto V_74;
V_68 = F_79 ( V_136 ,
F_90 ( V_1 -> V_32 , V_1 -> V_33 ) ) ;
if ( F_80 ( V_68 ) ) {
V_81 = F_81 ( V_68 ) ;
F_21 ( V_81 ) ;
goto V_139;
}
V_81 = F_94 ( V_1 ) ;
if ( V_81 < 0 ) {
F_21 ( V_81 ) ;
goto V_149;
}
V_81 = F_95 ( V_68 , V_1 ) ;
if ( V_81 < 0 )
F_21 ( V_81 ) ;
F_72 ( V_150 , & V_1 -> V_10 ) ;
V_149:
F_85 ( V_136 , V_68 ) ;
V_139:
F_50 ( V_31 , 1 ) ;
V_74:
F_52 ( & V_1 -> V_147 ) ;
if ( V_81 )
F_21 ( V_81 ) ;
return V_81 ;
}
static int F_96 ( struct V_1 * V_1 )
{
int V_81 = 0 , V_59 ;
int V_80 = 0 ;
struct V_36 * V_37 = V_1 -> V_32 ;
struct V_135 * V_136 = F_57 ( V_37 ) ;
int type = V_1 -> V_33 ;
struct V_30 * V_65 = F_10 ( V_37 , type ) -> V_34 ;
struct V_46 * V_53 = V_65 -> V_54 ;
int V_151 = F_67 ( V_37 , type ) ;
T_6 * V_68 ;
F_97 ( V_1 -> V_27 , type ) ;
F_46 ( & V_1 -> V_147 ) ;
V_81 = F_42 ( V_65 , 1 ) ;
if ( V_81 < 0 )
goto V_74;
if ( ! F_2 ( V_152 , & V_1 -> V_10 ) ) {
V_81 = F_59 ( V_65 , 0 ) ;
if ( V_81 < 0 )
goto V_153;
V_81 = F_98 ( & V_65 -> V_35 , V_1 ) ;
F_60 ( V_65 , 0 ) ;
if ( V_81 < 0 )
goto V_153;
}
F_99 ( V_152 , & V_1 -> V_10 ) ;
F_4 ( V_1 ) -> V_24 ++ ;
F_4 ( V_1 ) -> V_130 = V_1 -> V_7 . V_19 ;
F_4 ( V_1 ) -> V_131 = V_1 -> V_7 . V_14 ;
if ( ! V_1 -> V_129 ) {
V_80 = 1 ;
F_30 ( F_28 () ) ;
V_81 = F_100 ( V_53 , NULL ,
V_53 -> V_55 + ( V_151 << V_37 -> V_58 ) ,
V_53 -> V_55 ) ;
if ( V_81 < 0 )
goto V_153;
}
V_68 = F_79 ( V_136 ,
F_68 ( V_37 , type ) ) ;
if ( F_80 ( V_68 ) ) {
V_81 = F_81 ( V_68 ) ;
goto V_153;
}
V_81 = F_59 ( V_65 , V_80 ) ;
if ( V_81 < 0 )
goto V_149;
V_81 = F_74 ( & V_65 -> V_35 , V_1 ) ;
if ( V_80 && F_76 ( F_10 ( V_37 , type ) ) ) {
V_59 = F_65 ( V_37 , type ) ;
if ( ! V_81 )
V_81 = V_59 ;
}
F_60 ( V_65 , V_80 ) ;
V_149:
F_85 ( V_136 , V_68 ) ;
V_153:
F_50 ( V_65 , 1 ) ;
if ( V_81 < 0 )
goto V_74;
V_81 = F_101 ( V_1 ) ;
if ( V_81 < 0 )
goto V_74;
F_99 ( V_150 , & V_1 -> V_10 ) ;
V_74:
F_52 ( & V_1 -> V_147 ) ;
if ( V_81 )
F_21 ( V_81 ) ;
return V_81 ;
}
static int F_102 ( struct V_1 * V_1 )
{
unsigned long V_154 = ( 1 << ( V_8 + V_9 ) ) |
( 1 << ( V_8 + V_15 ) ) |
( 1 << ( V_8 + V_13 ) ) |
( 1 << ( V_8 + V_18 ) ) |
( 1 << ( V_8 + V_20 ) ) |
( 1 << ( V_8 + V_22 ) ) ;
int V_155 = 0 ;
int V_81 ;
struct V_36 * V_37 = V_1 -> V_32 ;
int type = V_1 -> V_33 ;
struct V_30 * V_31 = F_10 ( V_37 , type ) -> V_34 ;
T_6 * V_68 ;
struct V_135 * V_136 = F_57 ( V_37 ) ;
F_103 ( V_1 -> V_27 , type ) ;
F_44 ( & V_82 ) ;
if ( V_1 -> V_10 & V_154 )
V_155 = 1 ;
F_45 ( & V_82 ) ;
if ( ! V_155 || F_28 () ) {
V_81 = F_88 ( V_1 ) ;
goto V_74;
}
V_81 = F_42 ( V_31 , 1 ) ;
if ( V_81 < 0 )
goto V_74;
V_68 = F_79 ( V_136 , V_138 ) ;
if ( F_80 ( V_68 ) ) {
V_81 = F_81 ( V_68 ) ;
F_21 ( V_81 ) ;
goto V_139;
}
F_46 ( & F_82 ( V_37 ) -> V_140 ) ;
V_81 = F_83 ( V_1 ) ;
if ( V_81 < 0 ) {
F_21 ( V_81 ) ;
goto V_156;
}
V_81 = F_84 ( V_1 ) ;
V_156:
F_52 ( & F_82 ( V_37 ) -> V_140 ) ;
F_85 ( V_136 , V_68 ) ;
V_139:
F_50 ( V_31 , 1 ) ;
V_74:
if ( V_81 )
F_21 ( V_81 ) ;
return V_81 ;
}
static int F_104 ( struct V_36 * V_37 , int type )
{
T_6 * V_68 ;
int V_81 = 0 ;
struct V_30 * V_31 = F_10 ( V_37 , type ) -> V_34 ;
V_81 = F_42 ( V_31 , 1 ) ;
if ( V_81 < 0 )
goto V_74;
V_68 = F_79 ( F_57 ( V_37 ) , V_145 ) ;
if ( F_80 ( V_68 ) ) {
V_81 = F_81 ( V_68 ) ;
F_21 ( V_81 ) ;
goto V_139;
}
V_81 = F_105 ( V_37 , type ) ;
F_85 ( F_57 ( V_37 ) , V_68 ) ;
V_139:
F_50 ( V_31 , 1 ) ;
V_74:
if ( V_81 )
F_21 ( V_81 ) ;
return V_81 ;
}
static struct V_1 * F_106 ( struct V_36 * V_37 , int type )
{
struct V_157 * V_1 =
F_107 ( V_158 , V_159 ) ;
if ( ! V_1 )
return NULL ;
return & V_1 -> V_160 ;
}
static void F_108 ( struct V_1 * V_1 )
{
F_109 ( V_158 , V_1 ) ;
}
