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
F_12 ( V_16 -> V_18 . V_20 ) ;
F_12 ( V_16 ) ;
}
F_12 ( V_2 ) ;
}
int F_13 ( struct V_1 * V_2 , int V_21 )
{
int V_22 = F_14 ( & V_2 -> V_4 ) ;
F_15 ( V_23 , L_1 , V_22 , V_2 -> V_3 ) ;
if ( V_22 == V_2 -> V_3 ) {
if ( V_21 )
return 1 ;
if ( F_16 ( & V_2 -> V_6 ) == 1 )
return 1 ;
}
return 0 ;
}
void F_17 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_24 )
{
V_16 -> V_25 = 1 ;
V_16 -> V_26 = V_24 ;
F_18 ( & V_2 -> V_4 ) ;
if ( V_24 == 0 )
F_18 ( & V_2 -> V_5 ) ;
F_19 ( & V_2 -> V_10 ) ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_24 )
{
struct V_27 * V_28 = & V_2 -> V_29 -> V_30 -> V_31 . V_28 ;
F_17 ( V_2 , V_16 , V_24 ) ;
if ( V_24 && ! ( V_28 -> V_32 [ V_16 -> V_33 ] &&
V_28 -> V_32 [ V_16 -> V_33 ] -> V_34 ) )
V_24 = 0 ;
return V_24 ;
}
void F_21 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
F_22 ( & V_16 -> V_17 , & V_2 -> V_8 ) ;
V_2 -> V_3 ++ ;
V_16 -> V_35 = V_2 ;
}
static int F_23 ( struct V_27 * V_28 , int V_36 )
{
int V_24 ;
struct V_37 * V_38 ;
F_24 ( & V_28 -> V_39 ) ;
V_38 = V_28 -> V_32 [ V_36 ] ;
V_24 = ! V_38 || V_38 -> V_34 ||
( V_38 -> V_40 &&
F_25 ( V_38 -> V_40 ) -> V_41 ) ;
F_26 ( & V_28 -> V_39 ) ;
return V_24 ;
}
int F_27 ( struct V_27 * V_28 , int V_42 )
{
T_1 V_43 ;
struct V_44 V_45 ;
struct V_37 * V_38 ;
int V_24 = 0 ;
F_24 ( & V_28 -> V_39 ) ;
V_38 = V_28 -> V_32 [ V_42 ] ;
if ( F_28 ( V_38 == NULL ) ) {
V_24 = 0 ;
goto V_46;
}
if ( F_29 ( V_38 -> V_34 ) ) {
V_24 = 1 ;
goto V_46;
}
if ( V_38 -> V_40 && F_25 ( V_38 -> V_40 ) -> V_41 ) {
V_24 = 0 ;
goto V_46;
}
F_26 ( & V_28 -> V_39 ) ;
F_4 ( & V_43 ) ;
V_45 = F_30 ( F_31 ( V_47 ) ,
F_31 ( 1 ) , NULL , NULL ) ;
V_24 = F_32 ( V_43 , F_23 ( V_28 , V_42 ) , & V_45 ) ;
if ( V_38 != NULL && V_38 -> V_34 )
return 1 ;
return 0 ;
V_46:
F_26 ( & V_28 -> V_39 ) ;
return V_24 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_15 * V_16 ;
struct V_48 * V_49 ;
int V_24 = 0 , V_50 = 0 ;
F_7 ( V_2 -> V_51 != NULL ) ;
if ( V_2 -> V_51 -> V_19 == NULL )
return 0 ;
if ( ! F_14 ( & V_2 -> V_5 ) )
return - V_52 ;
F_34 ( V_49 ) ;
if ( V_49 == NULL ) {
V_24 = - V_53 ;
goto V_46;
}
F_35 (pos, &set->set_list) {
V_16 = F_9 ( V_13 , struct V_15 , V_17 ) ;
if ( ! V_16 -> V_25 || V_16 -> V_26 )
continue;
if ( V_16 -> V_18 . V_19 -> V_54 == 0 )
continue;
F_36 ( V_49 , V_16 -> V_18 . V_19 ,
V_16 -> V_18 . V_19 -> V_54 ,
V_2 -> V_51 -> V_55 , V_16 -> V_56 , & V_50 ) ;
}
if ( ! V_50 ) {
F_37 ( L_2 ) ;
V_24 = - V_52 ;
}
if ( ( V_2 -> V_51 -> V_19 -> V_54 & V_57 ) &&
( V_2 -> V_51 -> V_55 -> V_58 != V_50 ) ) {
F_37 ( L_3 ) ;
V_24 = - V_52 ;
goto V_46;
}
V_49 -> V_59 = V_2 -> V_51 -> V_19 -> V_59 ;
memcpy ( V_2 -> V_51 -> V_19 , V_49 , sizeof( * V_2 -> V_51 -> V_19 ) ) ;
V_46:
if ( V_49 )
F_11 ( V_49 ) ;
return V_24 ;
}
int F_38 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_29 ) ;
if ( F_14 ( & V_2 -> V_4 ) )
V_24 = F_33 ( V_2 ) ;
F_39 ( V_2 ) ;
return V_24 ;
}
static int F_40 ( void * V_60 , int V_24 )
{
struct V_61 * V_62 = V_60 ;
struct V_15 * V_63 ;
V_63 = F_41 ( V_62 , struct V_15 , V_18 ) ;
return F_20 ( V_63 -> V_35 , V_63 , V_24 ) ;
}
int F_42 ( struct V_64 * exp , struct V_61 * V_62 ,
struct V_1 * * V_65 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 = & exp -> V_30 -> V_31 . V_28 ;
int V_24 = 0 , V_66 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 )
return - V_53 ;
F_1 ( V_2 ) ;
V_2 -> V_29 = exp ;
V_2 -> V_51 = V_62 ;
for ( V_66 = 0 ; V_66 < V_62 -> V_55 -> V_58 ; V_66 ++ ) {
struct V_68 * V_69 ;
struct V_15 * V_16 ;
V_69 = V_62 -> V_55 -> V_70 [ V_66 ] ;
if ( F_44 ( V_69 ) )
continue;
if ( ! F_27 ( V_28 , V_69 -> V_71 ) ) {
F_15 ( V_72 , L_4 , V_69 -> V_71 ) ;
if ( V_62 -> V_19 -> V_54 & V_57 ) {
V_24 = - V_52 ;
goto V_73;
}
continue;
}
V_16 = F_43 ( sizeof( * V_16 ) , V_67 ) ;
if ( ! V_16 ) {
V_24 = - V_53 ;
goto V_73;
}
V_16 -> V_56 = V_66 ;
V_16 -> V_33 = V_69 -> V_71 ;
F_34 ( V_16 -> V_18 . V_19 ) ;
if ( V_16 -> V_18 . V_19 == NULL ) {
F_12 ( V_16 ) ;
V_24 = - V_53 ;
goto V_73;
}
memcpy ( V_16 -> V_18 . V_19 , V_62 -> V_19 ,
sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_59 = V_69 -> V_74 ;
V_16 -> V_18 . V_75 = F_40 ;
V_16 -> V_18 . V_76 = V_62 -> V_76 ;
F_21 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_24 = - V_52 ;
goto V_73;
}
* V_65 = V_2 ;
return V_24 ;
V_73:
F_38 ( V_2 ) ;
return V_24 ;
}
int F_45 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_29 ) ;
if ( F_14 ( & V_2 -> V_4 ) ) {
}
F_39 ( V_2 ) ;
return 0 ;
}
int F_46 ( struct V_64 * exp , struct V_61 * V_62 ,
struct V_48 * V_77 , struct V_78 * V_79 ,
struct V_80 * V_81 ,
struct V_1 * * V_65 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 = & exp -> V_30 -> V_31 . V_28 ;
int V_24 = 0 , V_66 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 )
return - V_53 ;
F_1 ( V_2 ) ;
V_2 -> V_29 = exp ;
V_2 -> V_51 = V_62 ;
V_2 -> V_51 -> V_55 = V_79 ;
V_2 -> V_51 -> V_19 = V_77 ;
V_2 -> V_82 = V_81 ;
if ( V_81 != NULL && V_77 -> V_54 & V_83 )
V_2 -> V_7 = V_81 -> V_84 ;
for ( V_66 = 0 ; V_66 < V_79 -> V_58 ; V_66 ++ ) {
struct V_68 * V_69 ;
struct V_15 * V_16 ;
V_69 = V_79 -> V_70 [ V_66 ] ;
if ( F_44 ( V_69 ) )
continue;
if ( ! F_27 ( V_28 , V_69 -> V_71 ) ) {
F_15 ( V_72 , L_4 , V_69 -> V_71 ) ;
continue;
}
V_16 = F_43 ( sizeof( * V_16 ) , V_67 ) ;
if ( ! V_16 ) {
V_24 = - V_53 ;
goto V_73;
}
V_16 -> V_56 = V_66 ;
V_16 -> V_33 = V_69 -> V_71 ;
F_34 ( V_16 -> V_18 . V_19 ) ;
if ( V_16 -> V_18 . V_19 == NULL ) {
F_12 ( V_16 ) ;
V_24 = - V_53 ;
goto V_73;
}
memcpy ( V_16 -> V_18 . V_19 , V_77 , sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_59 = V_69 -> V_74 ;
F_21 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_24 = - V_52 ;
goto V_73;
}
* V_65 = V_2 ;
return V_24 ;
V_73:
F_45 ( V_2 ) ;
return V_24 ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_29 ) ;
if ( F_14 ( & V_2 -> V_4 ) ) {
V_24 = F_33 ( V_2 ) ;
}
F_39 ( V_2 ) ;
return V_24 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_24 )
{
struct V_27 * V_28 = & V_16 -> V_35 -> V_29 -> V_30 -> V_31 . V_28 ;
struct V_78 * V_79 = V_16 -> V_35 -> V_51 -> V_55 ;
F_17 ( V_2 , V_16 , V_24 ) ;
if ( V_24 && ! ( V_28 -> V_32 [ V_16 -> V_33 ] &&
V_28 -> V_32 [ V_16 -> V_33 ] -> V_34 ) )
V_24 = 0 ;
if ( V_24 == 0 ) {
if ( V_16 -> V_18 . V_19 -> V_54 & V_85 )
V_79 -> V_70 [ V_16 -> V_56 ] -> V_86 . V_87 =
V_16 -> V_18 . V_19 -> V_88 ;
if ( V_16 -> V_18 . V_19 -> V_54 & V_89 )
V_79 -> V_70 [ V_16 -> V_56 ] -> V_86 . V_90 =
V_16 -> V_18 . V_19 -> V_91 ;
if ( V_16 -> V_18 . V_19 -> V_54 & V_92 )
V_79 -> V_70 [ V_16 -> V_56 ] -> V_86 . V_93 =
V_16 -> V_18 . V_19 -> V_94 ;
}
return V_24 ;
}
static int F_49 ( void * V_60 , int V_24 )
{
struct V_61 * V_62 = V_60 ;
struct V_15 * V_63 ;
V_63 = F_41 ( V_62 , struct V_15 , V_18 ) ;
return F_48 ( V_63 -> V_35 , V_63 , V_24 ) ;
}
int F_50 ( struct V_64 * exp , struct V_61 * V_62 ,
struct V_80 * V_81 ,
struct V_1 * * V_65 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 = & exp -> V_30 -> V_31 . V_28 ;
int V_24 = 0 , V_66 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 )
return - V_53 ;
F_1 ( V_2 ) ;
V_2 -> V_29 = exp ;
V_2 -> V_82 = V_81 ;
V_2 -> V_51 = V_62 ;
if ( V_81 != NULL && V_62 -> V_19 -> V_54 & V_83 )
V_2 -> V_7 = V_81 -> V_84 ;
for ( V_66 = 0 ; V_66 < V_62 -> V_55 -> V_58 ; V_66 ++ ) {
struct V_68 * V_69 = V_62 -> V_55 -> V_70 [ V_66 ] ;
struct V_15 * V_16 ;
if ( F_44 ( V_69 ) )
continue;
if ( ! F_27 ( V_28 , V_69 -> V_71 ) ) {
F_15 ( V_72 , L_4 , V_69 -> V_71 ) ;
continue;
}
V_16 = F_43 ( sizeof( * V_16 ) , V_67 ) ;
if ( ! V_16 ) {
V_24 = - V_53 ;
goto V_73;
}
V_16 -> V_56 = V_66 ;
V_16 -> V_33 = V_69 -> V_71 ;
F_34 ( V_16 -> V_18 . V_19 ) ;
if ( V_16 -> V_18 . V_19 == NULL ) {
F_12 ( V_16 ) ;
V_24 = - V_53 ;
goto V_73;
}
memcpy ( V_16 -> V_18 . V_19 , V_62 -> V_19 ,
sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_59 = V_69 -> V_74 ;
V_16 -> V_18 . V_19 -> V_95 = V_66 ;
V_16 -> V_18 . V_75 = F_49 ;
V_16 -> V_18 . V_76 = V_62 -> V_76 ;
if ( V_62 -> V_19 -> V_54 & V_96 ) {
int V_97 = F_51 ( V_62 -> V_55 ,
V_62 -> V_19 -> V_98 , V_66 ,
& V_16 -> V_18 . V_19 -> V_98 ) ;
if ( V_97 < 0 && V_16 -> V_18 . V_19 -> V_98 )
V_16 -> V_18 . V_19 -> V_98 -- ;
F_15 ( V_99 , L_5 ,
V_66 , V_16 -> V_18 . V_19 -> V_98 ,
V_62 -> V_19 -> V_98 ) ;
}
F_21 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_24 = - V_52 ;
goto V_73;
}
* V_65 = V_2 ;
return V_24 ;
V_73:
F_47 ( V_2 ) ;
return V_24 ;
}
int F_52 ( struct V_100 * V_101 , struct V_102 * V_103 ,
int V_104 )
{
if ( V_104 ) {
T_2 V_105 = F_53 ( & V_101 -> V_31 . V_28 ,
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
return - V_52 ;
}
int F_58 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
if ( V_2 == NULL )
return 0 ;
if ( F_14 ( & V_2 -> V_4 ) ) {
V_24 = F_52 ( V_2 -> V_113 , V_2 -> V_51 -> V_20 ,
F_14 ( & V_2 -> V_5 ) ) ;
}
F_39 ( V_2 ) ;
return V_24 ;
}
void F_59 ( struct V_102 * V_103 , struct V_102 * V_114 ,
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
static int F_61 ( void * V_60 , int V_24 )
{
struct V_61 * V_62 = V_60 ;
struct V_15 * V_63 ;
struct V_1 * V_2 ;
struct V_102 * V_103 , * V_114 ;
struct V_27 * V_28 ;
struct V_37 * V_38 ;
struct V_100 * V_122 , * V_123 ;
int V_104 ;
V_63 = F_41 ( V_62 , struct V_15 , V_18 ) ;
V_2 = V_63 -> V_35 ;
V_122 = V_2 -> V_113 ;
V_28 = & V_122 -> V_31 . V_28 ;
V_103 = V_2 -> V_51 -> V_20 ;
V_114 = V_62 -> V_20 ;
V_104 = F_14 ( & V_2 -> V_5 ) ;
F_17 ( V_2 , V_63 , V_24 ) ;
if ( V_24 )
goto V_46;
F_62 ( V_122 ) ;
V_38 = V_28 -> V_32 [ V_63 -> V_33 ] ;
if ( ! V_38 || ! V_38 -> V_34 )
goto V_124;
V_123 = F_63 ( V_38 -> V_40 ) ;
F_55 ( & V_123 -> V_110 ) ;
memcpy ( & V_123 -> V_111 , V_114 , sizeof( * V_114 ) ) ;
if ( ( V_62 -> V_125 & V_126 ) == 0 )
V_123 -> V_112 = F_56 () ;
F_57 ( & V_123 -> V_110 ) ;
V_124:
F_59 ( V_103 , V_114 , V_104 ) ;
F_64 ( V_122 ) ;
V_46:
if ( V_2 -> V_51 -> V_125 & V_127 &&
F_13 ( V_2 , 0 ) ) {
F_65 ( NULL , V_2 , V_2 -> V_3 !=
F_14 ( & V_2 -> V_5 ) ) ;
}
return 0 ;
}
int F_66 ( struct V_100 * V_101 , struct V_61 * V_62 ,
struct V_1 * * V_65 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 = & V_101 -> V_31 . V_28 ;
int V_24 = 0 , V_66 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 )
return - V_53 ;
F_1 ( V_2 ) ;
V_2 -> V_113 = V_101 ;
V_2 -> V_51 = V_62 ;
for ( V_66 = 0 ; V_66 < V_28 -> V_128 . V_129 ; V_66 ++ ) {
struct V_15 * V_16 ;
if ( V_28 -> V_32 [ V_66 ] == NULL ||
( ! F_27 ( V_28 , V_66 ) &&
( V_62 -> V_125 & V_130 ) ) ) {
F_15 ( V_72 , L_4 , V_66 ) ;
continue;
}
if ( ! V_28 -> V_32 [ V_66 ] -> V_40 ) {
F_15 ( V_72 , L_6 , V_66 ) ;
continue;
}
V_16 = F_43 ( sizeof( * V_16 ) , V_67 ) ;
if ( ! V_16 ) {
V_24 = - V_53 ;
goto V_73;
}
V_16 -> V_18 . V_20 = F_43 ( sizeof( * V_16 -> V_18 . V_20 ) ,
V_67 ) ;
if ( ! V_16 -> V_18 . V_20 ) {
F_12 ( V_16 ) ;
V_24 = - V_53 ;
goto V_73;
}
V_16 -> V_33 = V_66 ;
V_16 -> V_18 . V_75 = F_61 ;
V_16 -> V_18 . V_125 = V_62 -> V_125 ;
F_21 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_24 = - V_52 ;
goto V_73;
}
* V_65 = V_2 ;
return V_24 ;
V_73:
F_58 ( V_2 ) ;
return V_24 ;
}
