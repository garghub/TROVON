static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
F_2 ( & V_2 -> V_4 , 0 ) ;
F_2 ( & V_2 -> V_5 , 0 ) ;
F_2 ( & V_2 -> V_6 , 0 ) ;
V_2 -> V_7 = NULL ;
F_3 ( & V_2 -> V_8 ) ;
F_2 ( & V_2 -> V_9 , 1 ) ;
F_4 ( & V_2 -> V_10 ) ;
F_5 ( & V_2 -> V_11 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_12 * V_13 , * V_14 ;
F_7 ( V_2 ) ;
F_8 (pos, n, &set->set_list) {
struct V_15 * V_16 = F_9 ( V_13 ,
struct V_15 ,
V_17 ) ;
F_10 ( & V_16 -> V_17 ) ;
if ( V_16 -> V_18 . V_19 )
F_11 ( V_16 -> V_18 . V_19 ) ;
if ( V_16 -> V_18 . V_20 )
F_12 ( V_16 -> V_18 . V_20 , V_16 -> V_21 ) ;
if ( V_16 -> V_18 . V_22 )
F_13 ( V_16 -> V_18 . V_22 ,
sizeof( * V_16 -> V_18 . V_22 ) ) ;
F_13 ( V_16 , sizeof( * V_16 ) ) ;
}
if ( V_2 -> V_23 ) {
int V_24 = V_2 -> V_25 * sizeof( * V_2 -> V_23 ) ;
F_12 ( V_2 -> V_23 , V_24 ) ;
}
if ( V_2 -> V_26 )
F_14 ( V_2 -> V_26 ) ;
F_13 ( V_2 , sizeof( * V_2 ) ) ;
}
int F_15 ( struct V_1 * V_2 , int V_27 )
{
int V_28 = F_16 ( & V_2 -> V_4 ) ;
F_17 ( V_29 , L_1 , V_28 , V_2 -> V_3 ) ;
if ( V_28 == V_2 -> V_3 ) {
if ( V_27 )
return 1 ;
if ( F_18 ( & V_2 -> V_6 ) == 1 )
return 1 ;
}
return 0 ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_30 )
{
V_16 -> V_31 = 1 ;
V_16 -> V_32 = V_30 ;
F_20 ( & V_2 -> V_4 ) ;
if ( V_30 == 0 )
F_20 ( & V_2 -> V_5 ) ;
F_21 ( & V_2 -> V_10 ) ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_30 )
{
struct V_33 * V_34 = & V_2 -> V_35 -> V_36 -> V_37 . V_34 ;
F_19 ( V_2 , V_16 , V_30 ) ;
if ( V_30 && ! ( V_34 -> V_38 [ V_16 -> V_39 ] &&
V_34 -> V_38 [ V_16 -> V_39 ] -> V_40 ) )
V_30 = 0 ;
return V_30 ;
}
void F_23 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
F_24 ( & V_16 -> V_17 , & V_2 -> V_8 ) ;
V_2 -> V_3 ++ ;
V_16 -> V_41 = V_2 ;
}
static int F_25 ( struct V_33 * V_34 , int V_42 )
{
int V_30 ;
struct V_43 * V_44 ;
F_26 ( & V_34 -> V_45 ) ;
V_44 = V_34 -> V_38 [ V_42 ] ;
V_30 = ! V_44 || V_44 -> V_40 ||
( V_44 -> V_46 &&
F_27 ( V_44 -> V_46 ) -> V_47 ) ;
F_28 ( & V_34 -> V_45 ) ;
return V_30 ;
}
int F_29 ( struct V_33 * V_34 , int V_48 )
{
T_1 V_49 ;
struct V_50 V_51 ;
struct V_43 * V_44 ;
int V_30 = 0 ;
F_26 ( & V_34 -> V_45 ) ;
V_44 = V_34 -> V_38 [ V_48 ] ;
if ( F_30 ( V_44 == NULL ) ) {
V_30 = 0 ;
goto V_52;
}
if ( F_31 ( V_44 -> V_40 ) ) {
V_30 = 1 ;
goto V_52;
}
if ( V_44 -> V_46 && F_27 ( V_44 -> V_46 ) -> V_47 ) {
V_30 = 0 ;
goto V_52;
}
F_28 ( & V_34 -> V_45 ) ;
F_4 ( & V_49 ) ;
V_51 = F_32 ( F_33 ( V_53 ) ,
F_33 ( 1 ) , NULL , NULL ) ;
V_30 = F_34 ( V_49 , F_25 ( V_34 , V_48 ) , & V_51 ) ;
if ( V_44 != NULL && V_44 -> V_40 )
return 1 ;
return 0 ;
V_52:
F_28 ( & V_34 -> V_45 ) ;
return V_30 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_15 * V_16 ;
struct V_54 * V_55 ;
int V_30 = 0 , V_56 = 0 ;
F_7 ( V_2 -> V_57 != NULL ) ;
if ( V_2 -> V_57 -> V_19 == NULL )
return 0 ;
if ( ! F_16 ( & V_2 -> V_5 ) )
return - V_58 ;
F_36 ( V_55 ) ;
if ( V_55 == NULL ) {
V_30 = - V_59 ;
goto V_52;
}
F_37 (pos, &set->set_list) {
V_16 = F_9 ( V_13 , struct V_15 , V_17 ) ;
if ( ! V_16 -> V_31 || V_16 -> V_32 )
continue;
if ( V_16 -> V_18 . V_19 -> V_60 == 0 )
continue;
F_38 ( V_55 , V_16 -> V_18 . V_19 ,
V_16 -> V_18 . V_19 -> V_60 ,
V_2 -> V_57 -> V_20 , V_16 -> V_61 , & V_56 ) ;
}
if ( ! V_56 ) {
F_39 ( L_2 ) ;
V_30 = - V_58 ;
}
if ( ( V_2 -> V_57 -> V_19 -> V_60 & V_62 ) &&
( V_2 -> V_57 -> V_20 -> V_63 != V_56 ) ) {
F_39 ( L_3 ) ;
V_30 = - V_58 ;
goto V_52;
}
V_55 -> V_64 = V_2 -> V_57 -> V_19 -> V_64 ;
memcpy ( V_2 -> V_57 -> V_19 , V_55 , sizeof( * V_2 -> V_57 -> V_19 ) ) ;
V_52:
if ( V_55 )
F_11 ( V_55 ) ;
return V_30 ;
}
int F_40 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_35 ) ;
if ( F_16 ( & V_2 -> V_4 ) )
V_30 = F_35 ( V_2 ) ;
F_41 ( V_2 ) ;
return V_30 ;
}
static int F_42 ( void * V_65 , int V_30 )
{
struct V_66 * V_67 = V_65 ;
struct V_15 * V_68 ;
V_68 = F_43 ( V_67 , struct V_15 , V_18 ) ;
return F_22 ( V_68 -> V_41 , V_68 , V_30 ) ;
}
int F_44 ( struct V_69 * exp , struct V_66 * V_67 ,
struct V_1 * * V_70 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 = & exp -> V_36 -> V_37 . V_34 ;
int V_30 = 0 , V_71 ;
F_45 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return - V_59 ;
F_1 ( V_2 ) ;
V_2 -> V_35 = exp ;
V_2 -> V_57 = V_67 ;
for ( V_71 = 0 ; V_71 < V_67 -> V_20 -> V_63 ; V_71 ++ ) {
struct V_72 * V_73 ;
struct V_15 * V_16 ;
V_73 = V_67 -> V_20 -> V_74 [ V_71 ] ;
if ( ! F_29 ( V_34 , V_73 -> V_75 ) ) {
F_17 ( V_76 , L_4 , V_73 -> V_75 ) ;
if ( V_67 -> V_19 -> V_60 & V_62 ) {
V_30 = - V_58 ;
goto V_77;
}
continue;
}
F_45 ( V_16 , sizeof( * V_16 ) ) ;
if ( V_16 == NULL ) {
V_30 = - V_59 ;
goto V_77;
}
V_16 -> V_61 = V_71 ;
V_16 -> V_39 = V_73 -> V_75 ;
F_36 ( V_16 -> V_18 . V_19 ) ;
if ( V_16 -> V_18 . V_19 == NULL ) {
F_13 ( V_16 , sizeof( * V_16 ) ) ;
V_30 = - V_59 ;
goto V_77;
}
memcpy ( V_16 -> V_18 . V_19 , V_67 -> V_19 ,
sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_64 = V_73 -> V_78 ;
V_16 -> V_18 . V_79 = F_42 ;
V_16 -> V_18 . V_80 = V_67 -> V_80 ;
F_23 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_30 = - V_58 ;
goto V_77;
}
* V_70 = V_2 ;
return V_30 ;
V_77:
F_40 ( V_2 ) ;
return V_30 ;
}
int F_46 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_35 ) ;
if ( F_16 ( & V_2 -> V_4 ) ) {
}
F_41 ( V_2 ) ;
return 0 ;
}
int F_47 ( struct V_69 * exp , struct V_66 * V_67 ,
struct V_54 * V_81 , struct V_82 * V_83 ,
struct V_84 * V_85 ,
struct V_1 * * V_70 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 = & exp -> V_36 -> V_37 . V_34 ;
int V_30 = 0 , V_71 ;
F_45 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return - V_59 ;
F_1 ( V_2 ) ;
V_2 -> V_35 = exp ;
V_2 -> V_57 = V_67 ;
V_2 -> V_57 -> V_20 = V_83 ;
V_2 -> V_57 -> V_19 = V_81 ;
V_2 -> V_86 = V_85 ;
if ( V_85 != NULL && V_81 -> V_60 & V_87 )
V_2 -> V_7 = V_85 -> V_88 ;
for ( V_71 = 0 ; V_71 < V_83 -> V_63 ; V_71 ++ ) {
struct V_72 * V_73 ;
struct V_15 * V_16 ;
V_73 = V_83 -> V_74 [ V_71 ] ;
if ( ! F_29 ( V_34 , V_73 -> V_75 ) ) {
F_17 ( V_76 , L_4 , V_73 -> V_75 ) ;
continue;
}
F_45 ( V_16 , sizeof( * V_16 ) ) ;
if ( V_16 == NULL ) {
V_30 = - V_59 ;
goto V_77;
}
V_16 -> V_61 = V_71 ;
V_16 -> V_39 = V_73 -> V_75 ;
F_36 ( V_16 -> V_18 . V_19 ) ;
if ( V_16 -> V_18 . V_19 == NULL ) {
F_13 ( V_16 , sizeof( * V_16 ) ) ;
V_30 = - V_59 ;
goto V_77;
}
memcpy ( V_16 -> V_18 . V_19 , V_81 , sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_64 = V_73 -> V_78 ;
F_23 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_30 = - V_58 ;
goto V_77;
}
* V_70 = V_2 ;
return V_30 ;
V_77:
F_46 ( V_2 ) ;
return V_30 ;
}
int F_48 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_35 ) ;
if ( F_16 ( & V_2 -> V_4 ) ) {
V_30 = F_35 ( V_2 ) ;
}
F_41 ( V_2 ) ;
return V_30 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_30 )
{
struct V_33 * V_34 = & V_16 -> V_41 -> V_35 -> V_36 -> V_37 . V_34 ;
struct V_82 * V_83 = V_16 -> V_41 -> V_57 -> V_20 ;
F_19 ( V_2 , V_16 , V_30 ) ;
if ( V_30 && ! ( V_34 -> V_38 [ V_16 -> V_39 ] &&
V_34 -> V_38 [ V_16 -> V_39 ] -> V_40 ) )
V_30 = 0 ;
if ( V_30 == 0 ) {
if ( V_16 -> V_18 . V_19 -> V_60 & V_89 )
V_83 -> V_74 [ V_16 -> V_61 ] -> V_90 . V_91 =
V_16 -> V_18 . V_19 -> V_92 ;
if ( V_16 -> V_18 . V_19 -> V_60 & V_93 )
V_83 -> V_74 [ V_16 -> V_61 ] -> V_90 . V_94 =
V_16 -> V_18 . V_19 -> V_95 ;
if ( V_16 -> V_18 . V_19 -> V_60 & V_96 )
V_83 -> V_74 [ V_16 -> V_61 ] -> V_90 . V_97 =
V_16 -> V_18 . V_19 -> V_98 ;
}
return V_30 ;
}
static int F_50 ( void * V_65 , int V_30 )
{
struct V_66 * V_67 = V_65 ;
struct V_15 * V_68 ;
V_68 = F_43 ( V_67 , struct V_15 , V_18 ) ;
return F_49 ( V_68 -> V_41 , V_68 , V_30 ) ;
}
int F_51 ( struct V_69 * exp , struct V_66 * V_67 ,
struct V_84 * V_85 ,
struct V_1 * * V_70 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 = & exp -> V_36 -> V_37 . V_34 ;
int V_30 = 0 , V_71 ;
F_45 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return - V_59 ;
F_1 ( V_2 ) ;
V_2 -> V_35 = exp ;
V_2 -> V_86 = V_85 ;
V_2 -> V_57 = V_67 ;
if ( V_85 != NULL && V_67 -> V_19 -> V_60 & V_87 )
V_2 -> V_7 = V_85 -> V_88 ;
for ( V_71 = 0 ; V_71 < V_67 -> V_20 -> V_63 ; V_71 ++ ) {
struct V_72 * V_73 = V_67 -> V_20 -> V_74 [ V_71 ] ;
struct V_15 * V_16 ;
if ( ! F_29 ( V_34 , V_73 -> V_75 ) ) {
F_17 ( V_76 , L_4 , V_73 -> V_75 ) ;
continue;
}
F_45 ( V_16 , sizeof( * V_16 ) ) ;
if ( V_16 == NULL ) {
V_30 = - V_59 ;
goto V_77;
}
V_16 -> V_61 = V_71 ;
V_16 -> V_39 = V_73 -> V_75 ;
F_36 ( V_16 -> V_18 . V_19 ) ;
if ( V_16 -> V_18 . V_19 == NULL ) {
F_13 ( V_16 , sizeof( * V_16 ) ) ;
V_30 = - V_59 ;
goto V_77;
}
memcpy ( V_16 -> V_18 . V_19 , V_67 -> V_19 ,
sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_64 = V_73 -> V_78 ;
V_16 -> V_18 . V_19 -> V_99 = V_71 ;
V_16 -> V_18 . V_79 = F_50 ;
V_16 -> V_18 . V_80 = V_67 -> V_80 ;
if ( V_67 -> V_19 -> V_60 & V_100 ) {
int V_101 = F_52 ( V_67 -> V_20 ,
V_67 -> V_19 -> V_102 , V_71 ,
& V_16 -> V_18 . V_19 -> V_102 ) ;
if ( V_101 < 0 && V_16 -> V_18 . V_19 -> V_102 )
V_16 -> V_18 . V_19 -> V_102 -- ;
F_17 ( V_103 , L_5 ,
V_71 , V_16 -> V_18 . V_19 -> V_102 ,
V_67 -> V_19 -> V_102 ) ;
}
F_23 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_30 = - V_58 ;
goto V_77;
}
* V_70 = V_2 ;
return V_30 ;
V_77:
F_48 ( V_2 ) ;
return V_30 ;
}
int F_53 ( struct V_104 * V_105 , struct V_106 * V_107 ,
int V_108 )
{
if ( V_108 ) {
T_2 V_109 = F_54 ( & V_105 -> V_37 . V_34 ,
V_110 , 0 ) ;
if ( V_107 -> V_111 != V_112 )
F_55 ( V_107 -> V_111 , V_109 ) ;
if ( V_107 -> V_113 != V_112 )
F_55 ( V_107 -> V_113 , V_109 ) ;
F_56 ( & V_105 -> V_114 ) ;
memcpy ( & V_105 -> V_115 , V_107 , sizeof( * V_107 ) ) ;
V_105 -> V_116 = F_57 () ;
F_58 ( & V_105 -> V_114 ) ;
return 0 ;
}
return - V_58 ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
if ( V_2 == NULL )
return 0 ;
if ( F_16 ( & V_2 -> V_4 ) ) {
V_30 = F_53 ( V_2 -> V_117 , V_2 -> V_57 -> V_22 ,
F_16 ( & V_2 -> V_5 ) ) ;
}
F_41 ( V_2 ) ;
return V_30 ;
}
void F_60 ( struct V_106 * V_107 , struct V_106 * V_118 ,
int V_108 )
{
int V_119 = 0 , V_120 = 0 ;
T_3 V_121 ;
if ( V_108 == 0 ) {
memcpy ( V_107 , V_118 , sizeof( * V_118 ) ) ;
} else {
if ( V_107 -> V_122 != V_118 -> V_122 ) {
V_121 = V_107 -> V_122 | V_118 -> V_122 ;
for ( V_119 = 0 ; V_119 <= 64 ; ++ V_119 ) {
if ( V_121 & 1 ) {
if ( V_120 )
break;
else
V_120 = 1 ;
V_119 = 0 ;
}
V_121 >>= 1 ;
}
}
if ( V_107 -> V_122 < V_118 -> V_122 ) {
V_107 -> V_122 = V_118 -> V_122 ;
V_107 -> V_123 >>= V_119 ;
V_107 -> V_124 >>= V_119 ;
V_107 -> V_125 >>= V_119 ;
} else if ( V_119 != 0 ) {
V_118 -> V_123 >>= V_119 ;
V_118 -> V_124 >>= V_119 ;
V_118 -> V_125 >>= V_119 ;
}
V_107 -> V_123 += V_118 -> V_123 ;
V_107 -> V_124 += V_118 -> V_124 ;
V_107 -> V_125 += V_118 -> V_125 ;
F_61 ( V_107 -> V_111 , V_118 -> V_111 ) ;
F_61 ( V_107 -> V_113 , V_118 -> V_113 ) ;
}
}
static int F_62 ( void * V_65 , int V_30 )
{
struct V_66 * V_67 = V_65 ;
struct V_15 * V_68 ;
struct V_1 * V_2 ;
struct V_106 * V_107 , * V_118 ;
struct V_33 * V_34 ;
struct V_43 * V_44 ;
struct V_104 * V_126 , * V_127 ;
int V_108 ;
V_68 = F_43 ( V_67 , struct V_15 , V_18 ) ;
V_2 = V_68 -> V_41 ;
V_126 = V_2 -> V_117 ;
V_34 = & V_126 -> V_37 . V_34 ;
V_107 = V_2 -> V_57 -> V_22 ;
V_118 = V_67 -> V_22 ;
V_108 = F_16 ( & V_2 -> V_5 ) ;
F_19 ( V_2 , V_68 , V_30 ) ;
if ( V_30 )
goto V_52;
F_63 ( V_126 ) ;
V_44 = V_34 -> V_38 [ V_68 -> V_39 ] ;
if ( ! V_44 || ! V_44 -> V_40 )
goto V_128;
V_127 = F_64 ( V_44 -> V_46 ) ;
F_56 ( & V_127 -> V_114 ) ;
memcpy ( & V_127 -> V_115 , V_118 , sizeof( * V_118 ) ) ;
if ( ( V_67 -> V_129 & V_130 ) == 0 )
V_127 -> V_116 = F_57 () ;
F_58 ( & V_127 -> V_114 ) ;
V_128:
F_60 ( V_107 , V_118 , V_108 ) ;
F_65 ( V_126 ) ;
V_52:
if ( V_2 -> V_57 -> V_129 & V_131 &&
F_15 ( V_2 , 0 ) ) {
F_66 ( NULL , V_2 , V_2 -> V_3 !=
F_16 ( & V_2 -> V_5 ) ) ;
}
return 0 ;
}
int F_67 ( struct V_104 * V_105 , struct V_66 * V_67 ,
struct V_1 * * V_70 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 = & V_105 -> V_37 . V_34 ;
int V_30 = 0 , V_71 ;
F_45 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return - V_59 ;
F_1 ( V_2 ) ;
V_2 -> V_117 = V_105 ;
V_2 -> V_57 = V_67 ;
for ( V_71 = 0 ; V_71 < V_34 -> V_132 . V_133 ; V_71 ++ ) {
struct V_15 * V_16 ;
if ( V_34 -> V_38 [ V_71 ] == NULL ||
( ! F_29 ( V_34 , V_71 ) &&
( V_67 -> V_129 & V_134 ) ) ) {
F_17 ( V_76 , L_4 , V_71 ) ;
continue;
}
if ( ! V_34 -> V_38 [ V_71 ] -> V_46 ) {
F_17 ( V_76 , L_6 , V_71 ) ;
continue;
}
F_45 ( V_16 , sizeof( * V_16 ) ) ;
if ( V_16 == NULL ) {
V_30 = - V_59 ;
goto V_77;
}
F_45 ( V_16 -> V_18 . V_22 , sizeof( * V_16 -> V_18 . V_22 ) ) ;
if ( V_16 -> V_18 . V_22 == NULL ) {
F_13 ( V_16 , sizeof( * V_16 ) ) ;
V_30 = - V_59 ;
goto V_77;
}
V_16 -> V_39 = V_71 ;
V_16 -> V_18 . V_79 = F_62 ;
V_16 -> V_18 . V_129 = V_67 -> V_129 ;
F_23 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_30 = - V_58 ;
goto V_77;
}
* V_70 = V_2 ;
return V_30 ;
V_77:
F_59 ( V_2 ) ;
return V_30 ;
}
