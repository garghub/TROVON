bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_5 + V_3 > V_2 -> V_6 )
return false ;
return true ;
}
static struct V_7 * F_3 ( struct V_8 * V_9 ,
T_2 V_10 )
{
struct V_7 * V_11 ;
F_4 (entry, head, list)
if ( V_11 -> V_12 -> V_13 == V_10 )
return V_11 ;
return NULL ;
}
static struct V_7 * F_5 ( struct V_1 * V_2 ,
struct V_8 * V_9 , T_2 V_10 , bool V_14 )
{
struct V_12 * V_12 ;
struct V_7 * V_11 ;
int V_15 ;
V_12 = F_6 ( V_2 -> V_16 , V_10 ) ;
if ( F_7 ( V_12 ) )
return F_8 ( V_12 ) ;
V_15 = F_9 ( V_12 ) ;
if ( V_15 )
goto V_17;
if ( V_14 ) {
V_15 = F_10 ( V_12 ) ;
if ( V_15 )
goto V_17;
}
V_11 = F_11 ( V_18 , V_19 ) ;
V_11 -> V_12 = V_12 ;
F_12 ( & V_11 -> V_20 , V_9 ) ;
return V_11 ;
V_17:
F_13 ( V_12 ) ;
return F_14 ( V_15 ) ;
}
static void F_15 ( struct V_7 * V_11 )
{
F_13 ( V_11 -> V_12 ) ;
F_16 ( & V_11 -> V_20 ) ;
F_17 ( V_18 , V_11 ) ;
}
static int F_18 ( struct V_12 * V_12 , struct V_21 * V_22 ,
struct V_8 * V_23 )
{
struct V_24 * V_25 = F_19 ( V_22 ) ;
T_2 V_26 = F_20 ( V_25 -> V_27 ) ;
struct V_28 * V_29 ;
struct V_30 V_31 ;
struct V_21 * V_21 ;
struct V_12 * V_32 , * V_33 ;
struct V_7 * V_11 ;
int V_15 = 0 ;
char * V_34 ;
V_11 = F_3 ( V_23 , V_26 ) ;
if ( ! V_11 ) {
V_11 = F_5 ( F_21 ( V_12 ) , V_23 ,
V_26 , false ) ;
if ( F_7 ( V_11 ) ) {
V_32 = F_8 ( V_11 ) ;
V_15 = F_22 ( V_11 ) ;
goto V_35;
}
}
V_32 = V_11 -> V_12 ;
memset ( & V_31 , 0 , sizeof( struct V_30 ) ) ;
V_31 . V_36 . V_37 = F_20 ( V_25 -> V_38 ) ;
V_31 . V_36 . V_34 = V_25 -> V_39 ;
if ( F_23 ( V_31 . V_36 . V_37 > V_40 ) ) {
F_24 ( 1 ) ;
V_15 = - V_41 ;
goto V_35;
}
V_42:
V_29 = F_25 ( V_32 , & V_31 , & V_21 ) ;
if ( V_29 && V_12 -> V_13 == F_20 ( V_29 -> V_10 ) )
goto V_43;
if ( V_29 ) {
V_33 = F_6 ( V_12 -> V_44 , F_20 ( V_29 -> V_10 ) ) ;
if ( F_7 ( V_33 ) ) {
F_24 ( 1 ) ;
V_15 = F_22 ( V_33 ) ;
if ( V_15 == - V_45 )
V_15 = - V_46 ;
goto V_43;
}
V_15 = F_9 ( V_33 ) ;
if ( V_15 ) {
F_13 ( V_33 ) ;
goto V_43;
}
V_15 = F_26 ( F_21 ( V_12 ) ) ;
if ( V_15 ) {
F_13 ( V_33 ) ;
goto V_43;
}
F_27 ( V_29 , V_21 , V_32 , V_33 ) ;
F_13 ( V_33 ) ;
goto V_42;
} else if ( F_7 ( V_21 ) ) {
V_15 = F_22 ( V_21 ) ;
} else {
V_15 = F_28 ( V_32 , & V_31 , V_12 ,
V_12 -> V_13 , V_12 -> V_47 ) ;
}
if ( V_15 == - V_48 )
goto V_42;
goto V_35;
V_43:
F_29 ( V_32 , V_21 ) ;
F_30 ( V_21 , 0 ) ;
V_35:
if ( F_31 ( V_12 ) )
V_34 = L_1 ;
else
V_34 = V_25 -> V_39 ;
F_32 ( V_12 -> V_44 , V_49 ,
L_2 ,
V_50 , F_33 ( V_22 ) , V_34 ,
F_7 ( V_32 ) ? 0 : V_32 -> V_13 , V_15 ) ;
return V_15 ;
}
static void F_34 ( struct V_12 * V_12 , struct V_21 * V_21 )
{
struct V_24 * V_51 = F_19 ( V_21 ) ;
char * V_34 ;
V_12 -> V_47 = F_35 ( V_51 -> V_47 ) ;
F_36 ( V_12 , F_37 ( V_51 -> V_52 ) ) ;
V_12 -> V_53 . V_54 = F_37 ( V_51 -> V_53 ) ;
V_12 -> V_55 . V_54 = F_37 ( V_51 -> V_55 ) ;
V_12 -> V_56 . V_54 = F_37 ( V_51 -> V_56 ) ;
V_12 -> V_53 . V_57 = F_20 ( V_51 -> V_58 ) ;
V_12 -> V_55 . V_57 = F_20 ( V_51 -> V_59 ) ;
V_12 -> V_56 . V_57 = F_20 ( V_51 -> V_60 ) ;
F_38 ( V_12 ) -> V_61 = V_51 -> V_61 ;
if ( F_31 ( V_12 ) )
V_34 = L_1 ;
else
V_34 = F_19 ( V_21 ) -> V_39 ;
F_32 ( V_12 -> V_44 , V_49 , L_3 ,
F_33 ( V_21 ) , V_34 ) ;
}
static int F_39 ( struct V_1 * V_2 , struct V_8 * V_9 ,
bool V_62 )
{
struct V_63 * V_64 ;
struct V_21 * V_21 = NULL ;
T_3 V_65 ;
int V_15 = 0 ;
V_64 = F_40 ( V_2 , V_66 ) ;
V_65 = F_41 ( V_2 , V_64 ) ;
while ( 1 ) {
struct V_7 * V_11 ;
if ( ! F_42 ( V_2 , V_65 , V_67 ) )
return 0 ;
V_21 = F_43 ( V_2 , V_65 ) ;
if ( ! F_44 ( V_21 ) )
break;
if ( ! F_45 ( V_21 ) )
goto V_68;
V_11 = F_3 ( V_9 , F_33 ( V_21 ) ) ;
if ( ! V_11 ) {
bool V_14 = false ;
if ( ! V_62 &&
F_46 ( V_21 ) && F_47 ( V_21 ) ) {
V_15 = F_48 ( V_2 , V_21 ) ;
if ( V_15 )
break;
V_14 = true ;
}
V_11 = F_5 ( V_2 , V_9 , F_33 ( V_21 ) ,
V_14 ) ;
if ( F_7 ( V_11 ) ) {
V_15 = F_22 ( V_11 ) ;
if ( V_15 == - V_45 ) {
V_15 = 0 ;
goto V_68;
}
break;
}
}
V_11 -> V_65 = V_65 ;
if ( F_46 ( V_21 ) && F_47 ( V_21 ) )
V_11 -> V_69 = V_65 ;
V_68:
V_65 = F_49 ( V_21 ) ;
F_30 ( V_21 , 1 ) ;
F_50 ( V_2 , V_65 ) ;
}
F_30 ( V_21 , 1 ) ;
return V_15 ;
}
static void F_51 ( struct V_8 * V_9 )
{
struct V_7 * V_11 , * V_70 ;
F_52 (entry, tmp, head, list)
F_15 ( V_11 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
T_3 V_65 , struct V_71 * V_72 )
{
struct V_73 * V_74 ;
unsigned int V_75 = F_54 ( V_2 , V_65 ) ;
unsigned short V_76 = F_55 ( V_2 , V_65 ) ;
struct V_77 * V_78 ;
struct V_79 V_80 ;
struct V_21 * V_81 , * V_82 ;
struct V_71 V_83 = * V_72 ;
T_2 V_10 , V_84 ;
struct V_12 * V_12 ;
unsigned int V_85 ;
T_3 V_86 ;
int V_87 ;
V_74 = F_56 ( V_2 , V_75 ) ;
if ( ! F_57 ( V_76 , V_74 -> V_88 ) )
return 0 ;
for ( V_87 = V_89 ; V_87 <= V_90 ; V_87 ++ ) {
struct V_63 * V_64 = F_40 ( V_2 , V_87 ) ;
if ( V_64 -> V_75 == V_75 ) {
V_80 = V_64 -> V_91 -> V_92 [ V_76 ] ;
goto V_93;
}
}
V_81 = F_58 ( V_2 , V_75 ) ;
V_78 = (struct V_77 * ) F_59 ( V_81 ) ;
V_80 = V_78 -> V_92 [ V_76 ] ;
F_30 ( V_81 , 1 ) ;
V_93:
V_84 = F_20 ( V_80 . V_84 ) ;
if ( V_72 -> V_12 -> V_13 == V_84 ) {
V_83 . V_84 = V_84 ;
if ( ! V_72 -> V_94 )
F_60 ( V_72 -> V_95 ) ;
V_83 . V_82 = V_72 -> V_95 ;
V_83 . V_96 = F_35 ( V_80 . V_96 ) ;
goto V_97;
} else if ( V_72 -> V_84 == V_84 ) {
V_83 . V_96 = F_35 ( V_80 . V_96 ) ;
goto V_97;
}
V_82 = F_61 ( V_2 , V_84 ) ;
if ( F_7 ( V_82 ) )
return F_22 ( V_82 ) ;
V_85 = F_62 ( V_82 ) ;
V_10 = F_33 ( V_82 ) ;
F_30 ( V_82 , 1 ) ;
if ( V_10 != V_72 -> V_12 -> V_13 ) {
int V_98 ;
V_12 = F_6 ( V_2 -> V_16 , V_10 ) ;
if ( F_7 ( V_12 ) )
return F_22 ( V_12 ) ;
V_98 = F_9 ( V_12 ) ;
if ( V_98 ) {
F_13 ( V_12 ) ;
return V_98 ;
}
} else {
V_12 = V_72 -> V_12 ;
}
V_86 = F_63 ( V_85 , V_12 ) + F_35 ( V_80 . V_96 ) ;
if ( V_10 == V_72 -> V_12 -> V_13 && V_72 -> V_94 )
F_64 ( V_72 -> V_95 ) ;
F_65 ( & V_83 , V_12 , NULL , NULL , 0 ) ;
if ( F_66 ( & V_83 , V_86 , V_99 ) )
goto V_35;
if ( V_83 . V_100 == V_65 )
F_67 ( & V_83 , 1 ) ;
F_68 ( & V_83 ) ;
V_35:
if ( V_10 != V_72 -> V_12 -> V_13 )
F_13 ( V_12 ) ;
else if ( V_72 -> V_94 )
F_60 ( V_72 -> V_95 ) ;
return 0 ;
V_97:
if ( F_69 ( V_83 . V_12 , V_83 . V_82 ,
V_83 . V_96 ) == V_65 )
F_67 ( & V_83 , 1 ) ;
if ( V_72 -> V_12 -> V_13 == V_84 && ! V_72 -> V_94 )
F_64 ( V_72 -> V_95 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_12 * V_12 ,
struct V_21 * V_21 , T_3 V_65 )
{
struct V_71 V_72 ;
struct V_101 V_102 ;
unsigned int V_103 , V_104 ;
int V_15 = 0 , V_105 = 0 ;
if ( F_46 ( V_21 ) ) {
F_71 ( V_12 , V_21 ) ;
} else if ( F_72 ( F_62 ( V_21 ) ) ) {
V_15 = F_73 ( V_12 , V_21 , V_65 ) ;
if ( ! V_15 )
V_105 ++ ;
goto V_35;
}
if ( F_74 ( V_12 , V_21 ) )
goto V_35;
V_103 = F_63 ( F_62 ( V_21 ) , V_12 ) ;
V_104 = V_103 + F_75 ( V_21 , V_12 ) ;
F_65 ( & V_72 , V_12 , NULL , NULL , 0 ) ;
V_106:
V_15 = F_66 ( & V_72 , V_103 , V_107 ) ;
if ( V_15 ) {
if ( V_15 == - V_48 ) {
F_76 ( V_108 , V_109 / 50 ) ;
goto V_106;
}
goto V_35;
}
F_77 ( V_72 . V_82 , V_110 , true ) ;
F_78 ( V_2 , V_72 . V_84 , & V_102 ) ;
F_79 ( V_2 , V_102 . V_10 != F_33 ( V_21 ) ) ;
F_79 ( V_2 , F_62 ( V_72 . V_82 ) != F_62 ( V_21 ) ) ;
for (; V_103 < V_104 ; V_103 ++ , V_72 . V_96 ++ ) {
T_3 V_111 , V_112 ;
V_111 = F_69 ( V_72 . V_12 , V_72 . V_82 , V_72 . V_96 ) ;
V_112 = F_69 ( V_72 . V_12 , V_21 , V_72 . V_96 ) ;
if ( V_111 == V_112 )
continue;
if ( V_112 == V_113 ) {
F_67 ( & V_72 , 1 ) ;
continue;
}
if ( ! F_80 ( V_12 ) &&
( F_81 ( V_12 ) <= ( ( V_114 ) V_103 << V_115 ) ) )
F_36 ( V_12 ,
( V_114 ) ( V_103 + 1 ) << V_115 ) ;
if ( V_112 == V_116 ) {
F_67 ( & V_72 , 1 ) ;
F_82 ( & V_72 ) ;
continue;
}
if ( F_42 ( V_2 , V_112 , V_67 ) ) {
if ( V_111 == V_113 ) {
V_15 = F_82 ( & V_72 ) ;
#ifdef F_83
while ( V_15 )
V_15 = F_82 ( & V_72 ) ;
#endif
F_79 ( V_2 , V_15 ) ;
if ( V_15 )
goto V_15;
}
V_117:
V_15 = F_53 ( V_2 , V_112 , & V_72 ) ;
if ( V_15 ) {
if ( V_15 == - V_48 ) {
F_76 ( V_108 , V_109 / 50 ) ;
goto V_117;
}
goto V_15;
}
F_84 ( V_2 , & V_72 , V_111 , V_112 ,
V_102 . V_118 , false , false ) ;
V_105 ++ ;
}
}
F_85 ( V_72 . V_82 , V_21 ) ;
F_86 ( V_72 . V_82 , V_72 . V_84 , V_102 . V_10 ,
F_62 ( V_21 ) , false ) ;
F_87 ( V_72 . V_82 ) ;
V_15:
F_68 ( & V_72 ) ;
V_35:
F_32 ( V_2 -> V_16 , V_49 ,
L_4 ,
V_12 -> V_13 ,
F_80 ( V_12 ) ? L_5 : L_6 ,
V_105 , V_15 ) ;
return V_15 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_8 * V_119 ,
struct V_8 * V_23 )
{
struct V_63 * V_64 ;
struct V_21 * V_21 = NULL ;
int V_15 = 0 ;
T_3 V_65 ;
V_64 = F_40 ( V_2 , V_66 ) ;
V_65 = F_41 ( V_2 , V_64 ) ;
while ( 1 ) {
struct V_7 * V_11 ;
if ( ! F_42 ( V_2 , V_65 , V_67 ) )
break;
F_50 ( V_2 , V_65 ) ;
V_21 = F_43 ( V_2 , V_65 ) ;
if ( ! F_44 ( V_21 ) ) {
F_30 ( V_21 , 1 ) ;
break;
}
V_11 = F_3 ( V_119 , F_33 ( V_21 ) ) ;
if ( ! V_11 )
goto V_68;
if ( F_46 ( V_21 ) )
F_34 ( V_11 -> V_12 , V_21 ) ;
if ( V_11 -> V_69 == V_65 ) {
V_15 = F_18 ( V_11 -> V_12 , V_21 , V_23 ) ;
if ( V_15 ) {
F_30 ( V_21 , 1 ) ;
break;
}
}
V_15 = F_70 ( V_2 , V_11 -> V_12 , V_21 , V_65 ) ;
if ( V_15 ) {
F_30 ( V_21 , 1 ) ;
break;
}
if ( V_11 -> V_65 == V_65 )
F_15 ( V_11 ) ;
V_68:
V_65 = F_49 ( V_21 ) ;
F_30 ( V_21 , 1 ) ;
}
if ( ! V_15 )
F_89 ( V_2 ) ;
return V_15 ;
}
int F_90 ( struct V_1 * V_2 , bool V_62 )
{
struct V_8 V_119 ;
struct V_8 V_23 ;
int V_15 ;
int V_98 = 0 ;
unsigned long V_120 = V_2 -> V_16 -> V_120 ;
bool V_121 = false ;
if ( V_120 & V_122 ) {
F_32 ( V_2 -> V_16 , V_123 , L_7 ) ;
V_2 -> V_16 -> V_120 &= ~ V_122 ;
}
#ifdef F_91
V_2 -> V_16 -> V_120 |= V_124 ;
F_92 ( V_2 ) ;
#endif
V_18 = F_93 ( L_8 ,
sizeof( struct V_7 ) ) ;
if ( ! V_18 ) {
V_15 = - V_48 ;
goto V_35;
}
F_94 ( & V_119 ) ;
F_94 ( & V_23 ) ;
F_95 ( & V_2 -> V_125 ) ;
V_15 = F_39 ( V_2 , & V_119 , V_62 ) ;
if ( V_15 || F_96 ( & V_119 ) )
goto V_126;
if ( V_62 ) {
V_98 = 1 ;
goto V_126;
}
V_121 = true ;
V_15 = F_88 ( V_2 , & V_119 , & V_23 ) ;
if ( ! V_15 )
F_79 ( V_2 , ! F_96 ( & V_119 ) ) ;
V_126:
F_51 ( & V_119 ) ;
F_97 ( F_98 ( V_2 ) ,
( V_114 ) F_99 ( V_2 ) << V_115 , - 1 ) ;
if ( V_15 ) {
F_100 ( F_101 ( V_2 ) ) ;
F_100 ( F_98 ( V_2 ) ) ;
}
F_102 ( V_2 , V_127 ) ;
F_103 ( & V_2 -> V_125 ) ;
F_51 ( & V_23 ) ;
if ( ! V_15 && V_121 ) {
struct V_128 V_129 = {
. V_130 = V_131 ,
} ;
V_15 = F_104 ( V_2 , & V_129 ) ;
}
F_105 ( V_18 ) ;
V_35:
#ifdef F_91
F_106 ( V_2 -> V_16 ) ;
#endif
V_2 -> V_16 -> V_120 = V_120 ;
return V_98 ? V_98 : V_15 ;
}
