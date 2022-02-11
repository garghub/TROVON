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
F_11 ( V_20 , V_16 -> V_18 . V_19 ) ;
F_12 ( V_16 -> V_18 . V_21 ) ;
F_12 ( V_16 ) ;
}
F_12 ( V_2 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_22 )
{
int V_23 = F_14 ( & V_2 -> V_4 ) ;
F_15 ( V_24 , L_1 , V_23 , V_2 -> V_3 ) ;
if ( V_23 == V_2 -> V_3 ) {
if ( V_22 )
return 1 ;
if ( F_16 ( & V_2 -> V_6 ) == 1 )
return 1 ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_25 )
{
V_16 -> V_26 = 1 ;
V_16 -> V_27 = V_25 ;
F_18 ( & V_2 -> V_4 ) ;
if ( V_25 == 0 )
F_18 ( & V_2 -> V_5 ) ;
F_19 ( & V_2 -> V_10 ) ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_25 )
{
struct V_28 * V_29 = & V_2 -> V_30 -> V_31 -> V_32 . V_29 ;
F_17 ( V_2 , V_16 , V_25 ) ;
if ( V_25 && ! ( V_29 -> V_33 [ V_16 -> V_34 ] &&
V_29 -> V_33 [ V_16 -> V_34 ] -> V_35 ) )
V_25 = 0 ;
return V_25 ;
}
static void F_21 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
F_22 ( & V_16 -> V_17 , & V_2 -> V_8 ) ;
V_2 -> V_3 ++ ;
V_16 -> V_36 = V_2 ;
}
static int F_23 ( struct V_28 * V_29 , int V_37 )
{
int V_25 ;
struct V_38 * V_39 ;
F_24 ( & V_29 -> V_40 ) ;
V_39 = V_29 -> V_33 [ V_37 ] ;
V_25 = ! V_39 || V_39 -> V_35 ||
( V_39 -> V_41 &&
F_25 ( V_39 -> V_41 ) -> V_42 ) ;
F_26 ( & V_29 -> V_40 ) ;
return V_25 ;
}
static int F_27 ( struct V_28 * V_29 , int V_43 )
{
T_1 V_44 ;
struct V_45 V_46 ;
struct V_38 * V_39 ;
int V_25 = 0 ;
F_24 ( & V_29 -> V_40 ) ;
V_39 = V_29 -> V_33 [ V_43 ] ;
if ( F_28 ( V_39 == NULL ) ) {
V_25 = 0 ;
goto V_47;
}
if ( F_29 ( V_39 -> V_35 ) ) {
V_25 = 1 ;
goto V_47;
}
if ( V_39 -> V_41 && F_25 ( V_39 -> V_41 ) -> V_42 ) {
V_25 = 0 ;
goto V_47;
}
F_26 ( & V_29 -> V_40 ) ;
F_4 ( & V_44 ) ;
V_46 = F_30 ( F_31 ( V_48 ) ,
F_31 ( 1 ) , NULL , NULL ) ;
V_25 = F_32 ( V_44 , F_23 ( V_29 , V_43 ) , & V_46 ) ;
if ( V_39 != NULL && V_39 -> V_35 )
return 1 ;
return 0 ;
V_47:
F_26 ( & V_29 -> V_40 ) ;
return V_25 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_15 * V_16 ;
struct V_49 * V_50 ;
int V_25 = 0 , V_51 = 0 ;
F_7 ( V_2 -> V_52 != NULL ) ;
if ( V_2 -> V_52 -> V_19 == NULL )
return 0 ;
if ( ! F_14 ( & V_2 -> V_5 ) )
return - V_53 ;
V_50 = F_34 ( V_20 , V_54 | V_55 ) ;
if ( V_50 == NULL ) {
V_25 = - V_56 ;
goto V_47;
}
F_35 (pos, &set->set_list) {
V_16 = F_9 ( V_13 , struct V_15 , V_17 ) ;
if ( ! V_16 -> V_26 || V_16 -> V_27 )
continue;
if ( V_16 -> V_18 . V_19 -> V_57 == 0 )
continue;
F_36 ( V_50 , V_16 -> V_18 . V_19 ,
V_16 -> V_18 . V_19 -> V_57 ,
V_2 -> V_52 -> V_58 , V_16 -> V_59 , & V_51 ) ;
}
if ( ! V_51 ) {
F_37 ( L_2 ) ;
V_25 = - V_53 ;
}
if ( ( V_2 -> V_52 -> V_19 -> V_57 & V_60 ) &&
( V_2 -> V_52 -> V_58 -> V_61 != V_51 ) ) {
F_37 ( L_3 ) ;
V_25 = - V_53 ;
goto V_47;
}
V_50 -> V_62 = V_2 -> V_52 -> V_19 -> V_62 ;
memcpy ( V_2 -> V_52 -> V_19 , V_50 , sizeof( * V_2 -> V_52 -> V_19 ) ) ;
V_47:
if ( V_50 )
F_11 ( V_20 , V_50 ) ;
return V_25 ;
}
int F_38 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_30 ) ;
if ( F_14 ( & V_2 -> V_4 ) )
V_25 = F_33 ( V_2 ) ;
F_39 ( V_2 ) ;
return V_25 ;
}
static int F_40 ( void * V_63 , int V_25 )
{
struct V_64 * V_65 = V_63 ;
struct V_15 * V_66 ;
V_66 = F_41 ( V_65 , struct V_15 , V_18 ) ;
return F_20 ( V_66 -> V_36 , V_66 , V_25 ) ;
}
int F_42 ( struct V_67 * exp , struct V_64 * V_65 ,
struct V_1 * * V_68 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 = & exp -> V_31 -> V_32 . V_29 ;
int V_25 = 0 , V_69 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_56 ;
F_1 ( V_2 ) ;
V_2 -> V_30 = exp ;
V_2 -> V_52 = V_65 ;
for ( V_69 = 0 ; V_69 < V_65 -> V_58 -> V_61 ; V_69 ++ ) {
struct V_70 * V_71 ;
struct V_15 * V_16 ;
V_71 = V_65 -> V_58 -> V_72 [ V_69 ] ;
if ( F_44 ( V_71 ) )
continue;
if ( ! F_27 ( V_29 , V_71 -> V_73 ) ) {
F_15 ( V_74 , L_4 , V_71 -> V_73 ) ;
if ( V_65 -> V_19 -> V_57 & V_60 ) {
V_25 = - V_53 ;
goto V_75;
}
continue;
}
V_16 = F_43 ( sizeof( * V_16 ) , V_54 ) ;
if ( ! V_16 ) {
V_25 = - V_56 ;
goto V_75;
}
V_16 -> V_59 = V_69 ;
V_16 -> V_34 = V_71 -> V_73 ;
V_16 -> V_18 . V_19 = F_34 ( V_20 ,
V_54 | V_55 ) ;
if ( V_16 -> V_18 . V_19 == NULL ) {
F_12 ( V_16 ) ;
V_25 = - V_56 ;
goto V_75;
}
memcpy ( V_16 -> V_18 . V_19 , V_65 -> V_19 ,
sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_62 = V_71 -> V_76 ;
V_16 -> V_18 . V_77 = F_40 ;
F_21 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_25 = - V_53 ;
goto V_75;
}
* V_68 = V_2 ;
return V_25 ;
V_75:
F_38 ( V_2 ) ;
return V_25 ;
}
int F_45 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_30 ) ;
if ( F_14 ( & V_2 -> V_4 ) ) {
}
F_39 ( V_2 ) ;
return 0 ;
}
int F_46 ( struct V_67 * exp , struct V_64 * V_65 ,
struct V_49 * V_78 , struct V_79 * V_80 ,
struct V_81 * V_82 ,
struct V_1 * * V_68 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 = & exp -> V_31 -> V_32 . V_29 ;
int V_25 = 0 , V_69 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_56 ;
F_1 ( V_2 ) ;
V_2 -> V_30 = exp ;
V_2 -> V_52 = V_65 ;
V_2 -> V_52 -> V_58 = V_80 ;
V_2 -> V_52 -> V_19 = V_78 ;
V_2 -> V_83 = V_82 ;
if ( V_82 != NULL && V_78 -> V_57 & V_84 )
V_2 -> V_7 = V_82 -> V_85 ;
for ( V_69 = 0 ; V_69 < V_80 -> V_61 ; V_69 ++ ) {
struct V_70 * V_71 ;
struct V_15 * V_16 ;
V_71 = V_80 -> V_72 [ V_69 ] ;
if ( F_44 ( V_71 ) )
continue;
if ( ! F_27 ( V_29 , V_71 -> V_73 ) ) {
F_15 ( V_74 , L_4 , V_71 -> V_73 ) ;
continue;
}
V_16 = F_43 ( sizeof( * V_16 ) , V_54 ) ;
if ( ! V_16 ) {
V_25 = - V_56 ;
goto V_75;
}
V_16 -> V_59 = V_69 ;
V_16 -> V_34 = V_71 -> V_73 ;
V_16 -> V_18 . V_19 = F_34 ( V_20 ,
V_54 | V_55 ) ;
if ( V_16 -> V_18 . V_19 == NULL ) {
F_12 ( V_16 ) ;
V_25 = - V_56 ;
goto V_75;
}
memcpy ( V_16 -> V_18 . V_19 , V_78 , sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_62 = V_71 -> V_76 ;
F_21 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_25 = - V_53 ;
goto V_75;
}
* V_68 = V_2 ;
return V_25 ;
V_75:
F_45 ( V_2 ) ;
return V_25 ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_30 ) ;
if ( F_14 ( & V_2 -> V_4 ) ) {
V_25 = F_33 ( V_2 ) ;
}
F_39 ( V_2 ) ;
return V_25 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_25 )
{
struct V_28 * V_29 = & V_16 -> V_36 -> V_30 -> V_31 -> V_32 . V_29 ;
struct V_79 * V_80 = V_16 -> V_36 -> V_52 -> V_58 ;
F_17 ( V_2 , V_16 , V_25 ) ;
if ( V_25 && ! ( V_29 -> V_33 [ V_16 -> V_34 ] &&
V_29 -> V_33 [ V_16 -> V_34 ] -> V_35 ) )
V_25 = 0 ;
if ( V_25 == 0 ) {
if ( V_16 -> V_18 . V_19 -> V_57 & V_86 )
V_80 -> V_72 [ V_16 -> V_59 ] -> V_87 . V_88 =
V_16 -> V_18 . V_19 -> V_89 ;
if ( V_16 -> V_18 . V_19 -> V_57 & V_90 )
V_80 -> V_72 [ V_16 -> V_59 ] -> V_87 . V_91 =
V_16 -> V_18 . V_19 -> V_92 ;
if ( V_16 -> V_18 . V_19 -> V_57 & V_93 )
V_80 -> V_72 [ V_16 -> V_59 ] -> V_87 . V_94 =
V_16 -> V_18 . V_19 -> V_95 ;
}
return V_25 ;
}
static int F_49 ( void * V_63 , int V_25 )
{
struct V_64 * V_65 = V_63 ;
struct V_15 * V_66 ;
V_66 = F_41 ( V_65 , struct V_15 , V_18 ) ;
return F_48 ( V_66 -> V_36 , V_66 , V_25 ) ;
}
int F_50 ( struct V_67 * exp , struct V_64 * V_65 ,
struct V_81 * V_82 ,
struct V_1 * * V_68 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 = & exp -> V_31 -> V_32 . V_29 ;
int V_25 = 0 , V_69 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_56 ;
F_1 ( V_2 ) ;
V_2 -> V_30 = exp ;
V_2 -> V_83 = V_82 ;
V_2 -> V_52 = V_65 ;
if ( V_82 != NULL && V_65 -> V_19 -> V_57 & V_84 )
V_2 -> V_7 = V_82 -> V_85 ;
for ( V_69 = 0 ; V_69 < V_65 -> V_58 -> V_61 ; V_69 ++ ) {
struct V_70 * V_71 = V_65 -> V_58 -> V_72 [ V_69 ] ;
struct V_15 * V_16 ;
if ( F_44 ( V_71 ) )
continue;
if ( ! F_27 ( V_29 , V_71 -> V_73 ) ) {
F_15 ( V_74 , L_4 , V_71 -> V_73 ) ;
continue;
}
V_16 = F_43 ( sizeof( * V_16 ) , V_54 ) ;
if ( ! V_16 ) {
V_25 = - V_56 ;
goto V_75;
}
V_16 -> V_59 = V_69 ;
V_16 -> V_34 = V_71 -> V_73 ;
V_16 -> V_18 . V_19 = F_34 ( V_20 ,
V_54 | V_55 ) ;
if ( V_16 -> V_18 . V_19 == NULL ) {
F_12 ( V_16 ) ;
V_25 = - V_56 ;
goto V_75;
}
memcpy ( V_16 -> V_18 . V_19 , V_65 -> V_19 ,
sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_62 = V_71 -> V_76 ;
V_16 -> V_18 . V_19 -> V_96 = V_69 ;
V_16 -> V_18 . V_77 = F_49 ;
if ( V_65 -> V_19 -> V_57 & V_97 ) {
int V_98 = F_51 ( V_65 -> V_58 ,
V_65 -> V_19 -> V_99 , V_69 ,
& V_16 -> V_18 . V_19 -> V_99 ) ;
if ( V_98 < 0 && V_16 -> V_18 . V_19 -> V_99 )
V_16 -> V_18 . V_19 -> V_99 -- ;
F_15 ( V_100 , L_5 ,
V_69 , V_16 -> V_18 . V_19 -> V_99 ,
V_65 -> V_19 -> V_99 ) ;
}
F_21 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_25 = - V_53 ;
goto V_75;
}
* V_68 = V_2 ;
return V_25 ;
V_75:
F_47 ( V_2 ) ;
return V_25 ;
}
int F_52 ( struct V_101 * V_102 , struct V_103 * V_104 ,
int V_105 )
{
if ( V_105 ) {
T_2 V_106 = F_53 ( & V_102 -> V_32 . V_29 ,
V_107 , 0 ) ;
if ( V_104 -> V_108 != V_109 )
F_54 ( V_104 -> V_108 , V_106 ) ;
if ( V_104 -> V_110 != V_109 )
F_54 ( V_104 -> V_110 , V_106 ) ;
F_55 ( & V_102 -> V_111 ) ;
memcpy ( & V_102 -> V_112 , V_104 , sizeof( * V_104 ) ) ;
V_102 -> V_113 = F_56 () ;
F_57 ( & V_102 -> V_111 ) ;
return 0 ;
}
return - V_53 ;
}
int F_58 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
if ( V_2 == NULL )
return 0 ;
if ( F_14 ( & V_2 -> V_4 ) ) {
V_25 = F_52 ( V_2 -> V_114 , V_2 -> V_52 -> V_21 ,
F_14 ( & V_2 -> V_5 ) ) ;
}
F_39 ( V_2 ) ;
return V_25 ;
}
static void F_59 ( struct V_103 * V_104 ,
struct V_103 * V_115 ,
int V_105 )
{
int V_116 = 0 , V_117 = 0 ;
T_3 V_118 ;
if ( V_105 == 0 ) {
memcpy ( V_104 , V_115 , sizeof( * V_115 ) ) ;
} else {
if ( V_104 -> V_119 != V_115 -> V_119 ) {
V_118 = V_104 -> V_119 | V_115 -> V_119 ;
for ( V_116 = 0 ; V_116 <= 64 ; ++ V_116 ) {
if ( V_118 & 1 ) {
if ( V_117 )
break;
V_117 = 1 ;
V_116 = 0 ;
}
V_118 >>= 1 ;
}
}
if ( V_104 -> V_119 < V_115 -> V_119 ) {
V_104 -> V_119 = V_115 -> V_119 ;
V_104 -> V_120 >>= V_116 ;
V_104 -> V_121 >>= V_116 ;
V_104 -> V_122 >>= V_116 ;
} else if ( V_116 != 0 ) {
V_115 -> V_120 >>= V_116 ;
V_115 -> V_121 >>= V_116 ;
V_115 -> V_122 >>= V_116 ;
}
V_104 -> V_120 += V_115 -> V_120 ;
V_104 -> V_121 += V_115 -> V_121 ;
V_104 -> V_122 += V_115 -> V_122 ;
F_60 ( V_104 -> V_108 , V_115 -> V_108 ) ;
F_60 ( V_104 -> V_110 , V_115 -> V_110 ) ;
}
}
static int F_61 ( void * V_63 , int V_25 )
{
struct V_64 * V_65 = V_63 ;
struct V_15 * V_66 ;
struct V_1 * V_2 ;
struct V_103 * V_104 , * V_115 ;
struct V_28 * V_29 ;
struct V_38 * V_39 ;
struct V_101 * V_123 , * V_124 ;
int V_105 ;
V_66 = F_41 ( V_65 , struct V_15 , V_18 ) ;
V_2 = V_66 -> V_36 ;
V_123 = V_2 -> V_114 ;
V_29 = & V_123 -> V_32 . V_29 ;
V_104 = V_2 -> V_52 -> V_21 ;
V_115 = V_65 -> V_21 ;
V_105 = F_14 ( & V_2 -> V_5 ) ;
F_17 ( V_2 , V_66 , V_25 ) ;
if ( V_25 )
goto V_47;
F_62 ( V_123 ) ;
V_39 = V_29 -> V_33 [ V_66 -> V_34 ] ;
if ( ! V_39 || ! V_39 -> V_35 )
goto V_125;
V_124 = F_63 ( V_39 -> V_41 ) ;
F_55 ( & V_124 -> V_111 ) ;
memcpy ( & V_124 -> V_112 , V_115 , sizeof( * V_115 ) ) ;
if ( ( V_65 -> V_126 & V_127 ) == 0 )
V_124 -> V_113 = F_56 () ;
F_57 ( & V_124 -> V_111 ) ;
V_125:
F_59 ( V_104 , V_115 , V_105 ) ;
F_64 ( V_123 ) ;
V_47:
if ( V_2 -> V_52 -> V_126 & V_128 &&
F_13 ( V_2 , 0 ) ) {
F_65 ( NULL , V_2 , V_2 -> V_3 !=
F_14 ( & V_2 -> V_5 ) ) ;
}
return 0 ;
}
int F_66 ( struct V_101 * V_102 , struct V_64 * V_65 ,
struct V_1 * * V_68 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 = & V_102 -> V_32 . V_29 ;
int V_25 = 0 , V_69 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_56 ;
F_1 ( V_2 ) ;
V_2 -> V_114 = V_102 ;
V_2 -> V_52 = V_65 ;
for ( V_69 = 0 ; V_69 < V_29 -> V_129 . V_130 ; V_69 ++ ) {
struct V_15 * V_16 ;
if ( V_29 -> V_33 [ V_69 ] == NULL ||
( ! F_27 ( V_29 , V_69 ) &&
( V_65 -> V_126 & V_131 ) ) ) {
F_15 ( V_74 , L_4 , V_69 ) ;
continue;
}
if ( ! V_29 -> V_33 [ V_69 ] -> V_41 ) {
F_15 ( V_74 , L_6 , V_69 ) ;
continue;
}
V_16 = F_43 ( sizeof( * V_16 ) , V_54 ) ;
if ( ! V_16 ) {
V_25 = - V_56 ;
goto V_75;
}
V_16 -> V_18 . V_21 = F_43 ( sizeof( * V_16 -> V_18 . V_21 ) ,
V_54 ) ;
if ( ! V_16 -> V_18 . V_21 ) {
F_12 ( V_16 ) ;
V_25 = - V_56 ;
goto V_75;
}
V_16 -> V_34 = V_69 ;
V_16 -> V_18 . V_77 = F_61 ;
V_16 -> V_18 . V_126 = V_65 -> V_126 ;
F_21 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_25 = - V_53 ;
goto V_75;
}
* V_68 = V_2 ;
return V_25 ;
V_75:
F_58 ( V_2 ) ;
return V_25 ;
}
