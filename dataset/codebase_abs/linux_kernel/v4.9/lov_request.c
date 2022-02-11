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
}
void F_5 ( struct V_1 * V_2 )
{
struct V_11 * V_12 , * V_13 ;
F_6 ( V_2 ) ;
F_7 (pos, n, &set->set_list) {
struct V_14 * V_15 = F_8 ( V_12 ,
struct V_14 ,
V_16 ) ;
F_9 ( & V_15 -> V_16 ) ;
if ( V_15 -> V_17 . V_18 )
F_10 ( V_19 , V_15 -> V_17 . V_18 ) ;
F_11 ( V_15 -> V_17 . V_20 ) ;
F_11 ( V_15 ) ;
}
F_11 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_21 )
{
int V_22 = F_13 ( & V_2 -> V_4 ) ;
F_14 ( V_23 , L_1 , V_22 , V_2 -> V_3 ) ;
if ( V_22 == V_2 -> V_3 ) {
if ( V_21 )
return 1 ;
if ( F_15 ( & V_2 -> V_6 ) == 1 )
return 1 ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_14 * V_15 , int V_24 )
{
V_15 -> V_25 = 1 ;
V_15 -> V_26 = V_24 ;
F_17 ( & V_2 -> V_4 ) ;
if ( V_24 == 0 )
F_17 ( & V_2 -> V_5 ) ;
F_18 ( & V_2 -> V_10 ) ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_14 * V_15 , int V_24 )
{
struct V_27 * V_28 = & V_2 -> V_29 -> V_30 -> V_31 . V_28 ;
F_16 ( V_2 , V_15 , V_24 ) ;
if ( V_24 && ! ( V_28 -> V_32 [ V_15 -> V_33 ] &&
V_28 -> V_32 [ V_15 -> V_33 ] -> V_34 ) )
V_24 = 0 ;
return V_24 ;
}
static void F_20 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
F_21 ( & V_15 -> V_16 , & V_2 -> V_8 ) ;
V_2 -> V_3 ++ ;
V_15 -> V_35 = V_2 ;
}
static int F_22 ( struct V_27 * V_28 , int V_36 )
{
int V_24 ;
struct V_37 * V_38 ;
F_23 ( & V_28 -> V_39 ) ;
V_38 = V_28 -> V_32 [ V_36 ] ;
V_24 = ! V_38 || V_38 -> V_34 ||
( V_38 -> V_40 &&
F_24 ( V_38 -> V_40 ) -> V_41 ) ;
F_25 ( & V_28 -> V_39 ) ;
return V_24 ;
}
static int F_26 ( struct V_27 * V_28 , int V_42 )
{
T_1 V_43 ;
struct V_44 V_45 ;
struct V_37 * V_38 ;
int V_24 = 0 ;
F_23 ( & V_28 -> V_39 ) ;
V_38 = V_28 -> V_32 [ V_42 ] ;
if ( F_27 ( ! V_38 ) ) {
V_24 = 0 ;
goto V_46;
}
if ( F_28 ( V_38 -> V_34 ) ) {
V_24 = 1 ;
goto V_46;
}
if ( V_38 -> V_40 && F_24 ( V_38 -> V_40 ) -> V_41 ) {
V_24 = 0 ;
goto V_46;
}
F_25 ( & V_28 -> V_39 ) ;
F_4 ( & V_43 ) ;
V_45 = F_29 ( F_30 ( V_47 ) ,
F_30 ( 1 ) , NULL , NULL ) ;
V_24 = F_31 ( V_43 , F_22 ( V_28 , V_42 ) , & V_45 ) ;
if ( V_38 -> V_34 )
return 1 ;
return 0 ;
V_46:
F_25 ( & V_28 -> V_39 ) ;
return V_24 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_48 * V_49 ;
int V_24 = 0 , V_50 = 0 ;
if ( ! V_2 -> V_51 -> V_18 )
return 0 ;
if ( ! F_13 ( & V_2 -> V_5 ) )
return - V_52 ;
V_49 = F_33 ( V_19 , V_53 ) ;
if ( ! V_49 ) {
V_24 = - V_54 ;
goto V_46;
}
F_34 (req, &set->set_list, rq_link) {
if ( ! V_15 -> V_25 || V_15 -> V_26 )
continue;
if ( V_15 -> V_17 . V_18 -> V_55 == 0 )
continue;
F_35 ( V_49 , V_15 -> V_17 . V_18 ,
V_15 -> V_17 . V_18 -> V_55 ,
V_2 -> V_51 -> V_56 , V_15 -> V_57 , & V_50 ) ;
}
if ( ! V_50 ) {
F_36 ( L_2 ) ;
V_24 = - V_52 ;
}
if ( ( V_2 -> V_51 -> V_18 -> V_55 & V_58 ) &&
( V_2 -> V_51 -> V_56 -> V_59 != V_50 ) ) {
F_36 ( L_3 ) ;
V_24 = - V_52 ;
goto V_46;
}
V_49 -> V_60 = V_2 -> V_51 -> V_18 -> V_60 ;
memcpy ( V_2 -> V_51 -> V_18 , V_49 , sizeof( * V_2 -> V_51 -> V_18 ) ) ;
V_46:
if ( V_49 )
F_10 ( V_19 , V_49 ) ;
return V_24 ;
}
int F_37 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
if ( ! V_2 )
return 0 ;
F_6 ( V_2 -> V_29 ) ;
if ( F_13 ( & V_2 -> V_4 ) )
V_24 = F_32 ( V_2 ) ;
F_38 ( V_2 ) ;
return V_24 ;
}
static int F_39 ( void * V_61 , int V_24 )
{
struct V_62 * V_63 = V_61 ;
struct V_14 * V_64 ;
V_64 = F_40 ( V_63 , struct V_14 , V_17 ) ;
return F_19 ( V_64 -> V_35 , V_64 , V_24 ) ;
}
int F_41 ( struct V_65 * exp , struct V_62 * V_63 ,
struct V_1 * * V_66 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 = & exp -> V_30 -> V_31 . V_28 ;
int V_24 = 0 , V_67 ;
V_2 = F_42 ( sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
F_1 ( V_2 ) ;
V_2 -> V_29 = exp ;
V_2 -> V_51 = V_63 ;
for ( V_67 = 0 ; V_67 < V_63 -> V_56 -> V_59 ; V_67 ++ ) {
struct V_68 * V_69 ;
struct V_14 * V_15 ;
V_69 = V_63 -> V_56 -> V_70 [ V_67 ] ;
if ( F_43 ( V_69 ) )
continue;
if ( ! F_26 ( V_28 , V_69 -> V_71 ) ) {
F_14 ( V_72 , L_4 , V_69 -> V_71 ) ;
if ( V_63 -> V_18 -> V_55 & V_58 ) {
V_24 = - V_52 ;
goto V_73;
}
continue;
}
V_15 = F_42 ( sizeof( * V_15 ) , V_53 ) ;
if ( ! V_15 ) {
V_24 = - V_54 ;
goto V_73;
}
V_15 -> V_57 = V_67 ;
V_15 -> V_33 = V_69 -> V_71 ;
V_15 -> V_17 . V_18 = F_33 ( V_19 , V_53 ) ;
if ( ! V_15 -> V_17 . V_18 ) {
F_11 ( V_15 ) ;
V_24 = - V_54 ;
goto V_73;
}
memcpy ( V_15 -> V_17 . V_18 , V_63 -> V_18 ,
sizeof( * V_15 -> V_17 . V_18 ) ) ;
V_15 -> V_17 . V_18 -> V_60 = V_69 -> V_74 ;
V_15 -> V_17 . V_75 = F_39 ;
F_20 ( V_15 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_24 = - V_52 ;
goto V_73;
}
* V_66 = V_2 ;
return V_24 ;
V_73:
F_37 ( V_2 ) ;
return V_24 ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
if ( ! V_2 )
return 0 ;
F_6 ( V_2 -> V_29 ) ;
if ( F_13 ( & V_2 -> V_4 ) ) {
V_24 = F_32 ( V_2 ) ;
}
F_38 ( V_2 ) ;
return V_24 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_14 * V_15 , int V_24 )
{
struct V_27 * V_28 = & V_15 -> V_35 -> V_29 -> V_30 -> V_31 . V_28 ;
struct V_76 * V_77 = V_15 -> V_35 -> V_51 -> V_56 ;
F_16 ( V_2 , V_15 , V_24 ) ;
if ( V_24 && ! ( V_28 -> V_32 [ V_15 -> V_33 ] &&
V_28 -> V_32 [ V_15 -> V_33 ] -> V_34 ) )
V_24 = 0 ;
if ( V_24 == 0 ) {
if ( V_15 -> V_17 . V_18 -> V_55 & V_78 )
V_77 -> V_70 [ V_15 -> V_57 ] -> V_79 . V_80 =
V_15 -> V_17 . V_18 -> V_81 ;
if ( V_15 -> V_17 . V_18 -> V_55 & V_82 )
V_77 -> V_70 [ V_15 -> V_57 ] -> V_79 . V_83 =
V_15 -> V_17 . V_18 -> V_84 ;
if ( V_15 -> V_17 . V_18 -> V_55 & V_85 )
V_77 -> V_70 [ V_15 -> V_57 ] -> V_79 . V_86 =
V_15 -> V_17 . V_18 -> V_87 ;
}
return V_24 ;
}
static int F_46 ( void * V_61 , int V_24 )
{
struct V_62 * V_63 = V_61 ;
struct V_14 * V_64 ;
V_64 = F_40 ( V_63 , struct V_14 , V_17 ) ;
return F_45 ( V_64 -> V_35 , V_64 , V_24 ) ;
}
int F_47 ( struct V_65 * exp , struct V_62 * V_63 ,
struct V_88 * V_89 ,
struct V_1 * * V_66 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 = & exp -> V_30 -> V_31 . V_28 ;
int V_24 = 0 , V_67 ;
V_2 = F_42 ( sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
F_1 ( V_2 ) ;
V_2 -> V_29 = exp ;
V_2 -> V_51 = V_63 ;
if ( V_89 && V_63 -> V_18 -> V_55 & V_90 )
V_2 -> V_7 = V_89 -> V_91 ;
for ( V_67 = 0 ; V_67 < V_63 -> V_56 -> V_59 ; V_67 ++ ) {
struct V_68 * V_69 = V_63 -> V_56 -> V_70 [ V_67 ] ;
struct V_14 * V_15 ;
if ( F_43 ( V_69 ) )
continue;
if ( ! F_26 ( V_28 , V_69 -> V_71 ) ) {
F_14 ( V_72 , L_4 , V_69 -> V_71 ) ;
continue;
}
V_15 = F_42 ( sizeof( * V_15 ) , V_53 ) ;
if ( ! V_15 ) {
V_24 = - V_54 ;
goto V_73;
}
V_15 -> V_57 = V_67 ;
V_15 -> V_33 = V_69 -> V_71 ;
V_15 -> V_17 . V_18 = F_33 ( V_19 , V_53 ) ;
if ( ! V_15 -> V_17 . V_18 ) {
F_11 ( V_15 ) ;
V_24 = - V_54 ;
goto V_73;
}
memcpy ( V_15 -> V_17 . V_18 , V_63 -> V_18 ,
sizeof( * V_15 -> V_17 . V_18 ) ) ;
V_15 -> V_17 . V_18 -> V_60 = V_69 -> V_74 ;
V_15 -> V_17 . V_18 -> V_92 = V_67 ;
V_15 -> V_17 . V_75 = F_46 ;
if ( V_63 -> V_18 -> V_55 & V_93 ) {
int V_94 = F_48 ( V_63 -> V_56 ,
V_63 -> V_18 -> V_95 , V_67 ,
& V_15 -> V_17 . V_18 -> V_95 ) ;
if ( V_94 < 0 && V_15 -> V_17 . V_18 -> V_95 )
V_15 -> V_17 . V_18 -> V_95 -- ;
F_14 ( V_96 , L_5 ,
V_67 , V_15 -> V_17 . V_18 -> V_95 ,
V_63 -> V_18 -> V_95 ) ;
}
F_20 ( V_15 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_24 = - V_52 ;
goto V_73;
}
* V_66 = V_2 ;
return V_24 ;
V_73:
F_44 ( V_2 ) ;
return V_24 ;
}
int F_49 ( struct V_97 * V_98 , struct V_99 * V_100 ,
int V_101 )
{
if ( V_101 ) {
T_2 V_102 = F_50 ( & V_98 -> V_31 . V_28 ,
V_103 , 0 ) ;
if ( V_100 -> V_104 != V_105 )
F_51 ( V_100 -> V_104 , V_102 ) ;
if ( V_100 -> V_106 != V_105 )
F_51 ( V_100 -> V_106 , V_102 ) ;
F_52 ( & V_98 -> V_107 ) ;
memcpy ( & V_98 -> V_108 , V_100 , sizeof( * V_100 ) ) ;
V_98 -> V_109 = F_53 () ;
F_54 ( & V_98 -> V_107 ) ;
return 0 ;
}
return - V_52 ;
}
int F_55 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
if ( ! V_2 )
return 0 ;
if ( F_13 ( & V_2 -> V_4 ) ) {
V_24 = F_49 ( V_2 -> V_110 , V_2 -> V_51 -> V_20 ,
F_13 ( & V_2 -> V_5 ) ) ;
}
F_38 ( V_2 ) ;
return V_24 ;
}
static void F_56 ( struct V_99 * V_100 ,
struct V_99 * V_111 ,
int V_101 )
{
int V_112 = 0 , V_113 = 0 ;
T_3 V_114 ;
if ( V_101 == 0 ) {
memcpy ( V_100 , V_111 , sizeof( * V_111 ) ) ;
} else {
if ( V_100 -> V_115 != V_111 -> V_115 ) {
V_114 = V_100 -> V_115 | V_111 -> V_115 ;
for ( V_112 = 0 ; V_112 <= 64 ; ++ V_112 ) {
if ( V_114 & 1 ) {
if ( V_113 )
break;
V_113 = 1 ;
V_112 = 0 ;
}
V_114 >>= 1 ;
}
}
if ( V_100 -> V_115 < V_111 -> V_115 ) {
V_100 -> V_115 = V_111 -> V_115 ;
V_100 -> V_116 >>= V_112 ;
V_100 -> V_117 >>= V_112 ;
V_100 -> V_118 >>= V_112 ;
} else if ( V_112 != 0 ) {
V_111 -> V_116 >>= V_112 ;
V_111 -> V_117 >>= V_112 ;
V_111 -> V_118 >>= V_112 ;
}
V_100 -> V_116 += V_111 -> V_116 ;
V_100 -> V_117 += V_111 -> V_117 ;
V_100 -> V_118 += V_111 -> V_118 ;
F_57 ( V_100 -> V_104 , V_111 -> V_104 ) ;
F_57 ( V_100 -> V_106 , V_111 -> V_106 ) ;
}
}
static int F_58 ( void * V_61 , int V_24 )
{
struct V_62 * V_63 = V_61 ;
struct V_14 * V_64 ;
struct V_1 * V_2 ;
struct V_99 * V_100 , * V_111 ;
struct V_27 * V_28 ;
struct V_37 * V_38 ;
struct V_97 * V_119 , * V_120 ;
int V_101 ;
V_64 = F_40 ( V_63 , struct V_14 , V_17 ) ;
V_2 = V_64 -> V_35 ;
V_119 = V_2 -> V_110 ;
V_28 = & V_119 -> V_31 . V_28 ;
V_100 = V_2 -> V_51 -> V_20 ;
V_111 = V_63 -> V_20 ;
V_101 = F_13 ( & V_2 -> V_5 ) ;
F_16 ( V_2 , V_64 , V_24 ) ;
if ( V_24 )
goto V_46;
F_59 ( V_119 ) ;
V_38 = V_28 -> V_32 [ V_64 -> V_33 ] ;
if ( ! V_38 || ! V_38 -> V_34 )
goto V_121;
V_120 = F_60 ( V_38 -> V_40 ) ;
F_52 ( & V_120 -> V_107 ) ;
memcpy ( & V_120 -> V_108 , V_111 , sizeof( * V_111 ) ) ;
if ( ( V_63 -> V_122 & V_123 ) == 0 )
V_120 -> V_109 = F_53 () ;
F_54 ( & V_120 -> V_107 ) ;
V_121:
F_56 ( V_100 , V_111 , V_101 ) ;
F_61 ( V_119 ) ;
V_46:
if ( V_2 -> V_51 -> V_122 & V_124 &&
F_12 ( V_2 , 0 ) ) {
F_62 ( NULL , V_2 , V_2 -> V_3 !=
F_13 ( & V_2 -> V_5 ) ) ;
}
return 0 ;
}
int F_63 ( struct V_97 * V_98 , struct V_62 * V_63 ,
struct V_1 * * V_66 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 = & V_98 -> V_31 . V_28 ;
int V_24 = 0 , V_67 ;
V_2 = F_42 ( sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
F_1 ( V_2 ) ;
V_2 -> V_110 = V_98 ;
V_2 -> V_51 = V_63 ;
for ( V_67 = 0 ; V_67 < V_28 -> V_125 . V_126 ; V_67 ++ ) {
struct V_14 * V_15 ;
if ( ! V_28 -> V_32 [ V_67 ] ||
( V_63 -> V_122 & V_127 &&
! V_28 -> V_32 [ V_67 ] -> V_34 ) ) {
F_14 ( V_72 , L_4 , V_67 ) ;
continue;
}
if ( ! V_28 -> V_32 [ V_67 ] -> V_34 )
F_26 ( V_28 , V_67 ) ;
if ( ! V_28 -> V_32 [ V_67 ] -> V_40 ) {
F_14 ( V_72 , L_6 , V_67 ) ;
continue;
}
V_15 = F_42 ( sizeof( * V_15 ) , V_53 ) ;
if ( ! V_15 ) {
V_24 = - V_54 ;
goto V_73;
}
V_15 -> V_17 . V_20 = F_42 ( sizeof( * V_15 -> V_17 . V_20 ) ,
V_53 ) ;
if ( ! V_15 -> V_17 . V_20 ) {
F_11 ( V_15 ) ;
V_24 = - V_54 ;
goto V_73;
}
V_15 -> V_33 = V_67 ;
V_15 -> V_17 . V_75 = F_58 ;
V_15 -> V_17 . V_122 = V_63 -> V_122 ;
F_20 ( V_15 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_24 = - V_52 ;
goto V_73;
}
* V_66 = V_2 ;
return V_24 ;
V_73:
F_55 ( V_2 ) ;
return V_24 ;
}
