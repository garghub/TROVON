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
if ( F_28 ( ! V_39 ) ) {
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
if ( V_39 -> V_35 )
return 1 ;
return 0 ;
V_47:
F_26 ( & V_29 -> V_40 ) ;
return V_25 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_49 * V_50 ;
int V_25 = 0 , V_51 = 0 ;
if ( ! V_2 -> V_52 -> V_19 )
return 0 ;
if ( ! F_14 ( & V_2 -> V_5 ) )
return - V_53 ;
V_50 = F_34 ( V_20 , V_54 ) ;
if ( ! V_50 ) {
V_25 = - V_55 ;
goto V_47;
}
F_35 (req, &set->set_list, rq_link) {
if ( ! V_16 -> V_26 || V_16 -> V_27 )
continue;
if ( V_16 -> V_18 . V_19 -> V_56 == 0 )
continue;
F_36 ( V_50 , V_16 -> V_18 . V_19 ,
V_16 -> V_18 . V_19 -> V_56 ,
V_2 -> V_52 -> V_57 , V_16 -> V_58 , & V_51 ) ;
}
if ( ! V_51 ) {
F_37 ( L_2 ) ;
V_25 = - V_53 ;
}
if ( ( V_2 -> V_52 -> V_19 -> V_56 & V_59 ) &&
( V_2 -> V_52 -> V_57 -> V_60 != V_51 ) ) {
F_37 ( L_3 ) ;
V_25 = - V_53 ;
goto V_47;
}
V_50 -> V_61 = V_2 -> V_52 -> V_19 -> V_61 ;
memcpy ( V_2 -> V_52 -> V_19 , V_50 , sizeof( * V_2 -> V_52 -> V_19 ) ) ;
V_47:
if ( V_50 )
F_11 ( V_20 , V_50 ) ;
return V_25 ;
}
int F_38 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
if ( ! V_2 )
return 0 ;
F_7 ( V_2 -> V_30 ) ;
if ( F_14 ( & V_2 -> V_4 ) )
V_25 = F_33 ( V_2 ) ;
F_39 ( V_2 ) ;
return V_25 ;
}
static int F_40 ( void * V_62 , int V_25 )
{
struct V_63 * V_64 = V_62 ;
struct V_15 * V_65 ;
V_65 = F_41 ( V_64 , struct V_15 , V_18 ) ;
return F_20 ( V_65 -> V_36 , V_65 , V_25 ) ;
}
int F_42 ( struct V_66 * exp , struct V_63 * V_64 ,
struct V_1 * * V_67 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 = & exp -> V_31 -> V_32 . V_29 ;
int V_25 = 0 , V_68 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_55 ;
F_1 ( V_2 ) ;
V_2 -> V_30 = exp ;
V_2 -> V_52 = V_64 ;
for ( V_68 = 0 ; V_68 < V_64 -> V_57 -> V_60 ; V_68 ++ ) {
struct V_69 * V_70 ;
struct V_15 * V_16 ;
V_70 = V_64 -> V_57 -> V_71 [ V_68 ] ;
if ( F_44 ( V_70 ) )
continue;
if ( ! F_27 ( V_29 , V_70 -> V_72 ) ) {
F_15 ( V_73 , L_4 , V_70 -> V_72 ) ;
if ( V_64 -> V_19 -> V_56 & V_59 ) {
V_25 = - V_53 ;
goto V_74;
}
continue;
}
V_16 = F_43 ( sizeof( * V_16 ) , V_54 ) ;
if ( ! V_16 ) {
V_25 = - V_55 ;
goto V_74;
}
V_16 -> V_58 = V_68 ;
V_16 -> V_34 = V_70 -> V_72 ;
V_16 -> V_18 . V_19 = F_34 ( V_20 , V_54 ) ;
if ( ! V_16 -> V_18 . V_19 ) {
F_12 ( V_16 ) ;
V_25 = - V_55 ;
goto V_74;
}
memcpy ( V_16 -> V_18 . V_19 , V_64 -> V_19 ,
sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_61 = V_70 -> V_75 ;
V_16 -> V_18 . V_76 = F_40 ;
F_21 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_25 = - V_53 ;
goto V_74;
}
* V_67 = V_2 ;
return V_25 ;
V_74:
F_38 ( V_2 ) ;
return V_25 ;
}
int F_45 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return 0 ;
F_7 ( V_2 -> V_30 ) ;
if ( F_14 ( & V_2 -> V_4 ) ) {
}
F_39 ( V_2 ) ;
return 0 ;
}
int F_46 ( struct V_66 * exp , struct V_63 * V_64 ,
struct V_49 * V_77 , struct V_78 * V_79 ,
struct V_80 * V_81 ,
struct V_1 * * V_67 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 = & exp -> V_31 -> V_32 . V_29 ;
int V_25 = 0 , V_68 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_55 ;
F_1 ( V_2 ) ;
V_2 -> V_30 = exp ;
V_2 -> V_52 = V_64 ;
V_2 -> V_52 -> V_57 = V_79 ;
V_2 -> V_52 -> V_19 = V_77 ;
V_2 -> V_82 = V_81 ;
if ( V_81 && V_77 -> V_56 & V_83 )
V_2 -> V_7 = V_81 -> V_84 ;
for ( V_68 = 0 ; V_68 < V_79 -> V_60 ; V_68 ++ ) {
struct V_69 * V_70 ;
struct V_15 * V_16 ;
V_70 = V_79 -> V_71 [ V_68 ] ;
if ( F_44 ( V_70 ) )
continue;
if ( ! F_27 ( V_29 , V_70 -> V_72 ) ) {
F_15 ( V_73 , L_4 , V_70 -> V_72 ) ;
continue;
}
V_16 = F_43 ( sizeof( * V_16 ) , V_54 ) ;
if ( ! V_16 ) {
V_25 = - V_55 ;
goto V_74;
}
V_16 -> V_58 = V_68 ;
V_16 -> V_34 = V_70 -> V_72 ;
V_16 -> V_18 . V_19 = F_34 ( V_20 , V_54 ) ;
if ( ! V_16 -> V_18 . V_19 ) {
F_12 ( V_16 ) ;
V_25 = - V_55 ;
goto V_74;
}
memcpy ( V_16 -> V_18 . V_19 , V_77 , sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_61 = V_70 -> V_75 ;
F_21 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_25 = - V_53 ;
goto V_74;
}
* V_67 = V_2 ;
return V_25 ;
V_74:
F_45 ( V_2 ) ;
return V_25 ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
if ( ! V_2 )
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
struct V_78 * V_79 = V_16 -> V_36 -> V_52 -> V_57 ;
F_17 ( V_2 , V_16 , V_25 ) ;
if ( V_25 && ! ( V_29 -> V_33 [ V_16 -> V_34 ] &&
V_29 -> V_33 [ V_16 -> V_34 ] -> V_35 ) )
V_25 = 0 ;
if ( V_25 == 0 ) {
if ( V_16 -> V_18 . V_19 -> V_56 & V_85 )
V_79 -> V_71 [ V_16 -> V_58 ] -> V_86 . V_87 =
V_16 -> V_18 . V_19 -> V_88 ;
if ( V_16 -> V_18 . V_19 -> V_56 & V_89 )
V_79 -> V_71 [ V_16 -> V_58 ] -> V_86 . V_90 =
V_16 -> V_18 . V_19 -> V_91 ;
if ( V_16 -> V_18 . V_19 -> V_56 & V_92 )
V_79 -> V_71 [ V_16 -> V_58 ] -> V_86 . V_93 =
V_16 -> V_18 . V_19 -> V_94 ;
}
return V_25 ;
}
static int F_49 ( void * V_62 , int V_25 )
{
struct V_63 * V_64 = V_62 ;
struct V_15 * V_65 ;
V_65 = F_41 ( V_64 , struct V_15 , V_18 ) ;
return F_48 ( V_65 -> V_36 , V_65 , V_25 ) ;
}
int F_50 ( struct V_66 * exp , struct V_63 * V_64 ,
struct V_80 * V_81 ,
struct V_1 * * V_67 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 = & exp -> V_31 -> V_32 . V_29 ;
int V_25 = 0 , V_68 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_55 ;
F_1 ( V_2 ) ;
V_2 -> V_30 = exp ;
V_2 -> V_82 = V_81 ;
V_2 -> V_52 = V_64 ;
if ( V_81 && V_64 -> V_19 -> V_56 & V_83 )
V_2 -> V_7 = V_81 -> V_84 ;
for ( V_68 = 0 ; V_68 < V_64 -> V_57 -> V_60 ; V_68 ++ ) {
struct V_69 * V_70 = V_64 -> V_57 -> V_71 [ V_68 ] ;
struct V_15 * V_16 ;
if ( F_44 ( V_70 ) )
continue;
if ( ! F_27 ( V_29 , V_70 -> V_72 ) ) {
F_15 ( V_73 , L_4 , V_70 -> V_72 ) ;
continue;
}
V_16 = F_43 ( sizeof( * V_16 ) , V_54 ) ;
if ( ! V_16 ) {
V_25 = - V_55 ;
goto V_74;
}
V_16 -> V_58 = V_68 ;
V_16 -> V_34 = V_70 -> V_72 ;
V_16 -> V_18 . V_19 = F_34 ( V_20 , V_54 ) ;
if ( ! V_16 -> V_18 . V_19 ) {
F_12 ( V_16 ) ;
V_25 = - V_55 ;
goto V_74;
}
memcpy ( V_16 -> V_18 . V_19 , V_64 -> V_19 ,
sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_61 = V_70 -> V_75 ;
V_16 -> V_18 . V_19 -> V_95 = V_68 ;
V_16 -> V_18 . V_76 = F_49 ;
if ( V_64 -> V_19 -> V_56 & V_96 ) {
int V_97 = F_51 ( V_64 -> V_57 ,
V_64 -> V_19 -> V_98 , V_68 ,
& V_16 -> V_18 . V_19 -> V_98 ) ;
if ( V_97 < 0 && V_16 -> V_18 . V_19 -> V_98 )
V_16 -> V_18 . V_19 -> V_98 -- ;
F_15 ( V_99 , L_5 ,
V_68 , V_16 -> V_18 . V_19 -> V_98 ,
V_64 -> V_19 -> V_98 ) ;
}
F_21 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_25 = - V_53 ;
goto V_74;
}
* V_67 = V_2 ;
return V_25 ;
V_74:
F_47 ( V_2 ) ;
return V_25 ;
}
int F_52 ( struct V_100 * V_101 , struct V_102 * V_103 ,
int V_104 )
{
if ( V_104 ) {
T_2 V_105 = F_53 ( & V_101 -> V_32 . V_29 ,
V_106 , 0 ) ;
if ( V_103 -> V_107 != V_108 )
F_54 ( V_103 -> V_107 , V_105 ) ;
if ( V_103 -> V_109 != V_108 )
F_54 ( V_103 -> V_109 , V_105 ) ;
F_55 ( & V_101 -> V_110 ) ;
memcpy ( & V_101 -> V_111 , V_103 , sizeof( * V_103 ) ) ;
V_101 -> V_112 = F_56 () ;
F_57 ( & V_101 -> V_110 ) ;
return 0 ;
}
return - V_53 ;
}
int F_58 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
if ( ! V_2 )
return 0 ;
if ( F_14 ( & V_2 -> V_4 ) ) {
V_25 = F_52 ( V_2 -> V_113 , V_2 -> V_52 -> V_21 ,
F_14 ( & V_2 -> V_5 ) ) ;
}
F_39 ( V_2 ) ;
return V_25 ;
}
static void F_59 ( struct V_102 * V_103 ,
struct V_102 * V_114 ,
int V_104 )
{
int V_115 = 0 , V_116 = 0 ;
T_3 V_117 ;
if ( V_104 == 0 ) {
memcpy ( V_103 , V_114 , sizeof( * V_114 ) ) ;
} else {
if ( V_103 -> V_118 != V_114 -> V_118 ) {
V_117 = V_103 -> V_118 | V_114 -> V_118 ;
for ( V_115 = 0 ; V_115 <= 64 ; ++ V_115 ) {
if ( V_117 & 1 ) {
if ( V_116 )
break;
V_116 = 1 ;
V_115 = 0 ;
}
V_117 >>= 1 ;
}
}
if ( V_103 -> V_118 < V_114 -> V_118 ) {
V_103 -> V_118 = V_114 -> V_118 ;
V_103 -> V_119 >>= V_115 ;
V_103 -> V_120 >>= V_115 ;
V_103 -> V_121 >>= V_115 ;
} else if ( V_115 != 0 ) {
V_114 -> V_119 >>= V_115 ;
V_114 -> V_120 >>= V_115 ;
V_114 -> V_121 >>= V_115 ;
}
V_103 -> V_119 += V_114 -> V_119 ;
V_103 -> V_120 += V_114 -> V_120 ;
V_103 -> V_121 += V_114 -> V_121 ;
F_60 ( V_103 -> V_107 , V_114 -> V_107 ) ;
F_60 ( V_103 -> V_109 , V_114 -> V_109 ) ;
}
}
static int F_61 ( void * V_62 , int V_25 )
{
struct V_63 * V_64 = V_62 ;
struct V_15 * V_65 ;
struct V_1 * V_2 ;
struct V_102 * V_103 , * V_114 ;
struct V_28 * V_29 ;
struct V_38 * V_39 ;
struct V_100 * V_122 , * V_123 ;
int V_104 ;
V_65 = F_41 ( V_64 , struct V_15 , V_18 ) ;
V_2 = V_65 -> V_36 ;
V_122 = V_2 -> V_113 ;
V_29 = & V_122 -> V_32 . V_29 ;
V_103 = V_2 -> V_52 -> V_21 ;
V_114 = V_64 -> V_21 ;
V_104 = F_14 ( & V_2 -> V_5 ) ;
F_17 ( V_2 , V_65 , V_25 ) ;
if ( V_25 )
goto V_47;
F_62 ( V_122 ) ;
V_39 = V_29 -> V_33 [ V_65 -> V_34 ] ;
if ( ! V_39 || ! V_39 -> V_35 )
goto V_124;
V_123 = F_63 ( V_39 -> V_41 ) ;
F_55 ( & V_123 -> V_110 ) ;
memcpy ( & V_123 -> V_111 , V_114 , sizeof( * V_114 ) ) ;
if ( ( V_64 -> V_125 & V_126 ) == 0 )
V_123 -> V_112 = F_56 () ;
F_57 ( & V_123 -> V_110 ) ;
V_124:
F_59 ( V_103 , V_114 , V_104 ) ;
F_64 ( V_122 ) ;
V_47:
if ( V_2 -> V_52 -> V_125 & V_127 &&
F_13 ( V_2 , 0 ) ) {
F_65 ( NULL , V_2 , V_2 -> V_3 !=
F_14 ( & V_2 -> V_5 ) ) ;
}
return 0 ;
}
int F_66 ( struct V_100 * V_101 , struct V_63 * V_64 ,
struct V_1 * * V_67 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 = & V_101 -> V_32 . V_29 ;
int V_25 = 0 , V_68 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_55 ;
F_1 ( V_2 ) ;
V_2 -> V_113 = V_101 ;
V_2 -> V_52 = V_64 ;
for ( V_68 = 0 ; V_68 < V_29 -> V_128 . V_129 ; V_68 ++ ) {
struct V_15 * V_16 ;
if ( ! V_29 -> V_33 [ V_68 ] ||
( ! F_27 ( V_29 , V_68 ) &&
( V_64 -> V_125 & V_130 ) ) ) {
F_15 ( V_73 , L_4 , V_68 ) ;
continue;
}
if ( ! V_29 -> V_33 [ V_68 ] -> V_41 ) {
F_15 ( V_73 , L_6 , V_68 ) ;
continue;
}
V_16 = F_43 ( sizeof( * V_16 ) , V_54 ) ;
if ( ! V_16 ) {
V_25 = - V_55 ;
goto V_74;
}
V_16 -> V_18 . V_21 = F_43 ( sizeof( * V_16 -> V_18 . V_21 ) ,
V_54 ) ;
if ( ! V_16 -> V_18 . V_21 ) {
F_12 ( V_16 ) ;
V_25 = - V_55 ;
goto V_74;
}
V_16 -> V_34 = V_68 ;
V_16 -> V_18 . V_76 = F_61 ;
V_16 -> V_18 . V_125 = V_64 -> V_125 ;
F_21 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_25 = - V_53 ;
goto V_74;
}
* V_67 = V_2 ;
return V_25 ;
V_74:
F_58 ( V_2 ) ;
return V_25 ;
}
