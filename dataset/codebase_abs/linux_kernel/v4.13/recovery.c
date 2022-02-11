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
struct V_8 * V_9 , T_2 V_10 )
{
struct V_12 * V_12 ;
struct V_7 * V_11 ;
V_12 = F_6 ( V_2 -> V_14 , V_10 ) ;
if ( F_7 ( V_12 ) )
return F_8 ( V_12 ) ;
V_11 = F_9 ( V_15 , V_16 ) ;
V_11 -> V_12 = V_12 ;
F_10 ( & V_11 -> V_17 , V_9 ) ;
return V_11 ;
}
static void F_11 ( struct V_7 * V_11 )
{
F_12 ( V_11 -> V_12 ) ;
F_13 ( & V_11 -> V_17 ) ;
F_14 ( V_15 , V_11 ) ;
}
static int F_15 ( struct V_12 * V_12 , struct V_18 * V_19 ,
struct V_8 * V_20 )
{
struct V_21 * V_22 = F_16 ( V_19 ) ;
T_2 V_23 = F_17 ( V_22 -> V_24 ) ;
struct V_25 * V_26 ;
struct V_27 V_28 ;
struct V_18 * V_18 ;
struct V_12 * V_29 , * V_30 ;
struct V_7 * V_11 ;
int V_31 = 0 ;
char * V_32 ;
V_11 = F_3 ( V_20 , V_23 ) ;
if ( ! V_11 ) {
V_11 = F_5 ( F_18 ( V_12 ) , V_20 , V_23 ) ;
if ( F_7 ( V_11 ) ) {
V_29 = F_8 ( V_11 ) ;
V_31 = F_19 ( V_11 ) ;
goto V_33;
}
}
V_29 = V_11 -> V_12 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
V_28 . V_34 . V_35 = F_17 ( V_22 -> V_36 ) ;
V_28 . V_34 . V_32 = V_22 -> V_37 ;
if ( F_20 ( V_28 . V_34 . V_35 > V_38 ) ) {
F_21 ( 1 ) ;
V_31 = - V_39 ;
goto V_33;
}
V_40:
V_26 = F_22 ( V_29 , & V_28 , & V_18 ) ;
if ( V_26 && V_12 -> V_13 == F_17 ( V_26 -> V_10 ) )
goto V_41;
if ( V_26 ) {
V_30 = F_6 ( V_12 -> V_42 , F_17 ( V_26 -> V_10 ) ) ;
if ( F_7 ( V_30 ) ) {
F_21 ( 1 ) ;
V_31 = F_19 ( V_30 ) ;
if ( V_31 == - V_43 )
V_31 = - V_44 ;
goto V_41;
}
V_31 = F_23 ( F_18 ( V_12 ) ) ;
if ( V_31 ) {
F_12 ( V_30 ) ;
goto V_41;
}
F_24 ( V_26 , V_18 , V_29 , V_30 ) ;
F_12 ( V_30 ) ;
goto V_40;
} else if ( F_7 ( V_18 ) ) {
V_31 = F_19 ( V_18 ) ;
} else {
V_31 = F_25 ( V_29 , & V_28 , V_12 ,
V_12 -> V_13 , V_12 -> V_45 ) ;
}
if ( V_31 == - V_46 )
goto V_40;
goto V_33;
V_41:
F_26 ( V_29 , V_18 ) ;
F_27 ( V_18 , 0 ) ;
V_33:
if ( F_28 ( V_12 ) )
V_32 = L_1 ;
else
V_32 = V_22 -> V_37 ;
F_29 ( V_12 -> V_42 , V_47 ,
L_2 ,
V_48 , F_30 ( V_19 ) , V_32 ,
F_7 ( V_29 ) ? 0 : V_29 -> V_13 , V_31 ) ;
return V_31 ;
}
static void F_31 ( struct V_12 * V_12 , struct V_18 * V_18 )
{
struct V_21 * V_49 = F_16 ( V_18 ) ;
char * V_32 ;
V_12 -> V_45 = F_32 ( V_49 -> V_45 ) ;
F_33 ( V_12 , F_34 ( V_49 -> V_50 ) ) ;
V_12 -> V_51 . V_52 = F_34 ( V_49 -> V_51 ) ;
V_12 -> V_53 . V_52 = F_34 ( V_49 -> V_53 ) ;
V_12 -> V_54 . V_52 = F_34 ( V_49 -> V_54 ) ;
V_12 -> V_51 . V_55 = F_17 ( V_49 -> V_56 ) ;
V_12 -> V_53 . V_55 = F_17 ( V_49 -> V_57 ) ;
V_12 -> V_54 . V_55 = F_17 ( V_49 -> V_58 ) ;
F_35 ( V_12 ) -> V_59 = V_49 -> V_59 ;
if ( F_28 ( V_12 ) )
V_32 = L_1 ;
else
V_32 = F_16 ( V_18 ) -> V_37 ;
F_29 ( V_12 -> V_42 , V_47 , L_3 ,
F_30 ( V_18 ) , V_32 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_8 * V_9 ,
bool V_60 )
{
struct V_61 * V_62 ;
struct V_18 * V_18 = NULL ;
T_3 V_63 ;
int V_31 = 0 ;
V_62 = F_37 ( V_2 , V_64 ) ;
V_63 = F_38 ( V_2 , V_62 ) ;
while ( 1 ) {
struct V_7 * V_11 ;
if ( ! F_39 ( V_2 , V_63 , V_65 ) )
return 0 ;
V_18 = F_40 ( V_2 , V_63 ) ;
if ( ! F_41 ( V_18 ) )
break;
if ( ! F_42 ( V_18 ) )
goto V_66;
V_11 = F_3 ( V_9 , F_30 ( V_18 ) ) ;
if ( ! V_11 ) {
if ( ! V_60 &&
F_43 ( V_18 ) && F_44 ( V_18 ) ) {
V_31 = F_45 ( V_2 , V_18 ) ;
if ( V_31 )
break;
}
V_11 = F_5 ( V_2 , V_9 , F_30 ( V_18 ) ) ;
if ( F_7 ( V_11 ) ) {
V_31 = F_19 ( V_11 ) ;
if ( V_31 == - V_43 ) {
V_31 = 0 ;
goto V_66;
}
break;
}
}
V_11 -> V_63 = V_63 ;
if ( F_43 ( V_18 ) && F_44 ( V_18 ) )
V_11 -> V_67 = V_63 ;
V_66:
V_63 = F_46 ( V_18 ) ;
F_27 ( V_18 , 1 ) ;
F_47 ( V_2 , V_63 ) ;
}
F_27 ( V_18 , 1 ) ;
return V_31 ;
}
static void F_48 ( struct V_8 * V_9 )
{
struct V_7 * V_11 , * V_68 ;
F_49 (entry, tmp, head, list)
F_11 ( V_11 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
T_3 V_63 , struct V_69 * V_70 )
{
struct V_71 * V_72 ;
unsigned int V_73 = F_51 ( V_2 , V_63 ) ;
unsigned short V_74 = F_52 ( V_2 , V_63 ) ;
struct V_75 * V_76 ;
struct V_77 V_78 ;
struct V_18 * V_79 , * V_80 ;
struct V_69 V_81 = * V_70 ;
T_2 V_10 , V_82 ;
struct V_12 * V_12 ;
unsigned int V_83 ;
T_3 V_84 ;
int V_85 ;
V_72 = F_53 ( V_2 , V_73 ) ;
if ( ! F_54 ( V_74 , V_72 -> V_86 ) )
return 0 ;
for ( V_85 = V_87 ; V_85 <= V_88 ; V_85 ++ ) {
struct V_61 * V_62 = F_37 ( V_2 , V_85 ) ;
if ( V_62 -> V_73 == V_73 ) {
V_78 = V_62 -> V_89 -> V_90 [ V_74 ] ;
goto V_91;
}
}
V_79 = F_55 ( V_2 , V_73 ) ;
V_76 = (struct V_75 * ) F_56 ( V_79 ) ;
V_78 = V_76 -> V_90 [ V_74 ] ;
F_27 ( V_79 , 1 ) ;
V_91:
V_82 = F_17 ( V_78 . V_82 ) ;
if ( V_70 -> V_12 -> V_13 == V_82 ) {
V_81 . V_82 = V_82 ;
if ( ! V_70 -> V_92 )
F_57 ( V_70 -> V_93 ) ;
V_81 . V_80 = V_70 -> V_93 ;
V_81 . V_94 = F_32 ( V_78 . V_94 ) ;
goto V_95;
} else if ( V_70 -> V_82 == V_82 ) {
V_81 . V_94 = F_32 ( V_78 . V_94 ) ;
goto V_95;
}
V_80 = F_58 ( V_2 , V_82 ) ;
if ( F_7 ( V_80 ) )
return F_19 ( V_80 ) ;
V_83 = F_59 ( V_80 ) ;
V_10 = F_30 ( V_80 ) ;
F_27 ( V_80 , 1 ) ;
if ( V_10 != V_70 -> V_12 -> V_13 ) {
V_12 = F_6 ( V_2 -> V_14 , V_10 ) ;
if ( F_7 ( V_12 ) )
return F_19 ( V_12 ) ;
} else {
V_12 = V_70 -> V_12 ;
}
V_84 = F_60 ( V_83 , V_12 ) + F_32 ( V_78 . V_94 ) ;
if ( V_10 == V_70 -> V_12 -> V_13 && V_70 -> V_92 )
F_61 ( V_70 -> V_93 ) ;
F_62 ( & V_81 , V_12 , NULL , NULL , 0 ) ;
if ( F_63 ( & V_81 , V_84 , V_96 ) )
goto V_33;
if ( V_81 . V_97 == V_63 )
F_64 ( & V_81 , 1 ) ;
F_65 ( & V_81 ) ;
V_33:
if ( V_10 != V_70 -> V_12 -> V_13 )
F_12 ( V_12 ) ;
else if ( V_70 -> V_92 )
F_57 ( V_70 -> V_93 ) ;
return 0 ;
V_95:
if ( F_66 ( V_81 . V_80 , V_81 . V_94 ) == V_63 )
F_64 ( & V_81 , 1 ) ;
if ( V_70 -> V_12 -> V_13 == V_82 && ! V_70 -> V_92 )
F_61 ( V_70 -> V_93 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_12 * V_12 ,
struct V_18 * V_18 , T_3 V_63 )
{
struct V_69 V_70 ;
struct V_98 V_99 ;
unsigned int V_100 , V_101 ;
int V_31 = 0 , V_102 = 0 ;
if ( F_43 ( V_18 ) ) {
F_68 ( V_12 , V_18 ) ;
} else if ( F_69 ( F_59 ( V_18 ) ) ) {
V_31 = F_70 ( V_12 , V_18 , V_63 ) ;
if ( ! V_31 )
V_102 ++ ;
goto V_33;
}
if ( F_71 ( V_12 , V_18 ) )
goto V_33;
V_100 = F_60 ( F_59 ( V_18 ) , V_12 ) ;
V_101 = V_100 + F_72 ( V_18 , V_12 ) ;
F_62 ( & V_70 , V_12 , NULL , NULL , 0 ) ;
V_103:
V_31 = F_63 ( & V_70 , V_100 , V_104 ) ;
if ( V_31 ) {
if ( V_31 == - V_46 ) {
F_73 ( V_105 , V_106 / 50 ) ;
goto V_103;
}
goto V_33;
}
F_74 ( V_70 . V_80 , V_107 , true ) ;
F_75 ( V_2 , V_70 . V_82 , & V_99 ) ;
F_76 ( V_2 , V_99 . V_10 != F_30 ( V_18 ) ) ;
F_76 ( V_2 , F_59 ( V_70 . V_80 ) != F_59 ( V_18 ) ) ;
for (; V_100 < V_101 ; V_100 ++ , V_70 . V_94 ++ ) {
T_3 V_108 , V_109 ;
V_108 = F_66 ( V_70 . V_80 , V_70 . V_94 ) ;
V_109 = F_66 ( V_18 , V_70 . V_94 ) ;
if ( V_108 == V_109 )
continue;
if ( V_109 == V_110 ) {
F_64 ( & V_70 , 1 ) ;
continue;
}
if ( ! F_77 ( V_12 ) &&
( F_78 ( V_12 ) <= ( ( V_111 ) V_100 << V_112 ) ) )
F_33 ( V_12 ,
( V_111 ) ( V_100 + 1 ) << V_112 ) ;
if ( V_109 == V_113 ) {
F_64 ( & V_70 , 1 ) ;
F_79 ( & V_70 ) ;
continue;
}
if ( F_39 ( V_2 , V_109 , V_65 ) ) {
if ( V_108 == V_110 ) {
V_31 = F_79 ( & V_70 ) ;
#ifdef F_80
while ( V_31 )
V_31 = F_79 ( & V_70 ) ;
#endif
F_76 ( V_2 , V_31 ) ;
if ( V_31 )
goto V_31;
}
V_114:
V_31 = F_50 ( V_2 , V_109 , & V_70 ) ;
if ( V_31 ) {
if ( V_31 == - V_46 ) {
F_73 ( V_105 , V_106 / 50 ) ;
goto V_114;
}
goto V_31;
}
F_81 ( V_2 , & V_70 , V_108 , V_109 ,
V_99 . V_115 , false , false ) ;
V_102 ++ ;
}
}
F_82 ( V_70 . V_80 , V_18 ) ;
F_83 ( V_70 . V_80 , V_70 . V_82 , V_99 . V_10 ,
F_59 ( V_18 ) , false ) ;
F_84 ( V_70 . V_80 ) ;
V_31:
F_65 ( & V_70 ) ;
V_33:
F_29 ( V_2 -> V_14 , V_47 ,
L_4 ,
V_12 -> V_13 ,
F_77 ( V_12 ) ? L_5 : L_6 ,
V_102 , V_31 ) ;
return V_31 ;
}
static int F_85 ( struct V_1 * V_2 , struct V_8 * V_116 ,
struct V_8 * V_20 )
{
struct V_61 * V_62 ;
struct V_18 * V_18 = NULL ;
int V_31 = 0 ;
T_3 V_63 ;
V_62 = F_37 ( V_2 , V_64 ) ;
V_63 = F_38 ( V_2 , V_62 ) ;
while ( 1 ) {
struct V_7 * V_11 ;
if ( ! F_39 ( V_2 , V_63 , V_65 ) )
break;
F_47 ( V_2 , V_63 ) ;
V_18 = F_40 ( V_2 , V_63 ) ;
if ( ! F_41 ( V_18 ) ) {
F_27 ( V_18 , 1 ) ;
break;
}
V_11 = F_3 ( V_116 , F_30 ( V_18 ) ) ;
if ( ! V_11 )
goto V_66;
if ( F_43 ( V_18 ) )
F_31 ( V_11 -> V_12 , V_18 ) ;
if ( V_11 -> V_67 == V_63 ) {
V_31 = F_15 ( V_11 -> V_12 , V_18 , V_20 ) ;
if ( V_31 ) {
F_27 ( V_18 , 1 ) ;
break;
}
}
V_31 = F_67 ( V_2 , V_11 -> V_12 , V_18 , V_63 ) ;
if ( V_31 ) {
F_27 ( V_18 , 1 ) ;
break;
}
if ( V_11 -> V_63 == V_63 )
F_11 ( V_11 ) ;
V_66:
V_63 = F_46 ( V_18 ) ;
F_27 ( V_18 , 1 ) ;
}
if ( ! V_31 )
F_86 ( V_2 ) ;
return V_31 ;
}
int F_87 ( struct V_1 * V_2 , bool V_60 )
{
struct V_8 V_116 ;
struct V_8 V_20 ;
int V_31 ;
int V_117 = 0 ;
bool V_118 = false ;
V_15 = F_88 ( L_7 ,
sizeof( struct V_7 ) ) ;
if ( ! V_15 )
return - V_46 ;
F_89 ( & V_116 ) ;
F_89 ( & V_20 ) ;
F_90 ( & V_2 -> V_119 ) ;
V_31 = F_36 ( V_2 , & V_116 , V_60 ) ;
if ( V_31 || F_91 ( & V_116 ) )
goto V_33;
if ( V_60 ) {
V_117 = 1 ;
goto V_33;
}
V_118 = true ;
V_31 = F_85 ( V_2 , & V_116 , & V_20 ) ;
if ( ! V_31 )
F_76 ( V_2 , ! F_91 ( & V_116 ) ) ;
V_33:
F_48 ( & V_116 ) ;
F_92 ( F_93 ( V_2 ) ,
( V_111 ) F_94 ( V_2 ) << V_112 , - 1 ) ;
if ( V_31 ) {
F_95 ( F_96 ( V_2 ) ) ;
F_95 ( F_93 ( V_2 ) ) ;
}
F_97 ( V_2 , V_120 ) ;
if ( V_31 )
F_98 ( V_2 , V_121 ) ;
F_99 ( & V_2 -> V_119 ) ;
F_48 ( & V_20 ) ;
if ( ! V_31 && V_118 ) {
struct V_122 V_123 = {
. V_124 = V_125 ,
} ;
V_31 = F_100 ( V_2 , & V_123 ) ;
}
F_101 ( V_15 ) ;
return V_117 ? V_117 : V_31 ;
}
