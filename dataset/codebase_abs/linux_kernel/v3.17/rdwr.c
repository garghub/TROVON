static int F_1 ( T_1 * V_1 , unsigned V_2 ,
int V_3 , void * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_1 , struct V_5 , V_6 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = V_4 ;
struct V_11 * V_11 = V_1 -> V_12 ;
ASSERT ( V_10 ) ;
F_3 ( L_1 ,
V_6 -> V_13 -> V_14 , V_2 , V_3 ,
V_10 -> V_15 , V_10 -> V_16 ) ;
if ( V_10 -> V_15 != & V_11 -> V_15 ||
V_10 -> V_16 != V_17 )
return 0 ;
F_4 ( L_2 , V_11 , V_11 -> V_15 ) ;
if ( ! F_5 ( V_11 ) && ! F_6 ( V_11 ) ) {
F_4 ( L_3 ) ;
}
F_7 ( & V_1 -> V_18 ) ;
ASSERT ( V_6 -> V_19 ) ;
V_8 = F_2 ( V_6 -> V_19 -> V_19 . V_8 ,
struct V_7 , V_20 ) ;
F_8 ( & V_8 -> V_21 ) ;
F_9 ( & V_6 -> V_22 , & V_6 -> V_19 -> V_23 ) ;
F_10 ( & V_8 -> V_21 ) ;
F_11 ( V_6 -> V_19 ) ;
return 0 ;
}
static int F_12 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
struct V_24 * V_25 = V_8 -> V_26 -> V_27 -> V_28 ;
struct V_11 * V_29 = V_6 -> V_30 , * V_31 ;
int V_32 ;
F_3 ( L_4 ,
V_8 -> V_26 -> V_27 -> V_33 ,
V_29 -> V_14 , V_29 -> V_15 ) ;
if ( V_29 -> V_34 != V_25 ) {
F_13 ( L_5 ) ;
return - V_35 ;
}
V_31 = F_14 ( V_25 , V_29 -> V_14 ) ;
if ( ! V_31 ) {
F_13 ( L_6 ) ;
return - V_35 ;
}
if ( V_29 != V_31 ) {
F_15 ( V_31 ) ;
F_13 ( L_7 ) ;
return - V_35 ;
}
F_15 ( V_31 ) ;
F_16 ( & V_6 -> V_22 ) ;
F_17 ( V_29 , & V_6 -> V_6 ) ;
if ( F_18 ( V_29 ) ) {
V_32 = - V_36 ;
if ( F_6 ( V_29 ) )
goto V_37;
V_32 = 0 ;
if ( F_5 ( V_29 ) )
goto V_37;
F_4 ( L_8 ) ;
V_32 = V_25 -> V_38 -> V_39 ( NULL , V_29 ) ;
if ( V_32 < 0 )
goto V_37;
}
if ( F_18 ( V_29 ) ) {
F_4 ( L_9 , V_29 , V_29 -> V_15 ) ;
F_19 ( V_29 ) ;
}
F_13 ( L_10 ) ;
return - V_40 ;
V_37:
F_19 ( V_29 ) ;
F_20 ( & V_8 -> V_21 ) ;
F_7 ( & V_6 -> V_22 ) ;
F_21 ( & V_8 -> V_21 ) ;
F_13 ( L_11 , V_32 ) ;
return V_32 ;
}
static void F_22 ( struct V_41 * V_42 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_43 * V_19 ;
int error , V_44 ;
V_19 = F_2 ( V_42 , struct V_43 , V_19 ) ;
V_8 = F_2 ( V_19 -> V_19 . V_8 ,
struct V_7 , V_20 ) ;
F_3 ( L_12 , V_8 -> V_26 -> V_27 -> V_33 ) ;
V_44 = 8 ;
F_20 ( & V_8 -> V_21 ) ;
while ( ! F_23 ( & V_19 -> V_23 ) ) {
V_6 = F_24 ( V_19 -> V_23 . V_45 ,
struct V_5 , V_22 ) ;
F_7 ( & V_6 -> V_22 ) ;
F_21 ( & V_8 -> V_21 ) ;
F_4 ( L_13 , V_6 -> V_30 -> V_14 ) ;
V_46:
if ( F_25 ( V_47 ,
& V_8 -> V_20 . V_48 -> V_15 ) ) {
error = - V_49 ;
} else if ( F_5 ( V_6 -> V_30 ) ) {
F_26 ( V_6 -> V_13 , V_6 -> V_30 ) ;
F_27 ( V_6 -> V_19 ,
V_6 -> V_13 ) ;
error = 0 ;
} else if ( ! F_6 ( V_6 -> V_30 ) ) {
error = F_12 ( V_8 , V_6 ) ;
if ( error == - V_40 )
goto V_45;
goto V_46;
} else {
F_28 (
V_8 ,
L_14 ,
( unsigned long ) V_6 -> V_30 -> V_15 ) ;
error = - V_36 ;
}
F_29 ( V_6 -> V_30 ) ;
F_30 ( V_19 , V_6 -> V_13 , error ) ;
F_29 ( V_6 -> V_13 ) ;
F_31 ( V_19 , 1 ) ;
F_32 ( V_19 ) ;
F_33 ( V_6 ) ;
V_45:
V_44 -- ;
if ( V_44 < 0 || F_34 () ) {
if ( ! F_23 ( & V_19 -> V_23 ) )
F_11 ( V_19 ) ;
F_13 ( L_15 ) ;
return;
}
F_20 ( & V_8 -> V_21 ) ;
}
F_21 ( & V_8 -> V_21 ) ;
F_13 ( L_16 ) ;
}
static int F_35 ( struct V_7 * V_8 ,
struct V_43 * V_19 ,
struct V_11 * V_50 )
{
struct V_5 * V_6 ;
struct V_24 * V_25 ;
struct V_11 * V_51 , * V_29 ;
int V_32 ;
F_3 ( L_16 ) ;
F_4 ( L_17 ,
V_50 , V_50 -> V_14 , F_36 ( V_50 ) ) ;
V_6 = F_37 ( sizeof( * V_6 ) , V_52 ) ;
if ( ! V_6 )
goto V_53;
V_6 -> V_13 = V_50 ;
V_6 -> V_19 = F_38 ( V_19 ) ;
F_39 ( & V_6 -> V_6 , F_1 ) ;
V_25 = V_8 -> V_26 -> V_27 -> V_28 ;
V_51 = NULL ;
for (; ; ) {
V_29 = F_14 ( V_25 , V_50 -> V_14 ) ;
if ( V_29 )
goto V_54;
if ( ! V_51 ) {
V_51 = F_40 ( V_52 |
V_55 ) ;
if ( ! V_51 )
goto V_56;
}
V_32 = F_41 ( V_51 , V_25 ,
V_50 -> V_14 , V_52 ) ;
if ( V_32 == 0 )
goto V_57;
if ( V_32 != - V_58 )
goto V_59;
}
V_57:
F_4 ( L_18 , V_51 ) ;
V_29 = V_51 ;
V_51 = NULL ;
V_60:
V_32 = V_25 -> V_38 -> V_39 ( NULL , V_29 ) ;
if ( V_32 < 0 )
goto V_61;
V_62:
F_4 ( L_19 ) ;
F_42 ( V_6 -> V_13 ) ;
F_42 ( V_29 ) ;
V_6 -> V_30 = V_29 ;
V_6 -> V_6 . V_12 = V_29 ;
F_17 ( V_29 , & V_6 -> V_6 ) ;
V_6 = NULL ;
if ( F_18 ( V_29 ) ) {
F_4 ( L_9 , V_29 , V_29 -> V_15 ) ;
F_19 ( V_29 ) ;
}
goto V_63;
V_54:
F_4 ( L_20 ) ;
if ( V_51 ) {
F_29 ( V_51 ) ;
V_51 = NULL ;
}
if ( F_6 ( V_29 ) )
goto V_64;
if ( F_5 ( V_29 ) )
goto V_65;
if ( ! F_18 ( V_29 ) )
goto V_62;
F_4 ( L_21 , V_29 , V_29 -> V_15 ) ;
goto V_60;
V_65:
F_4 ( L_22 ) ;
F_27 ( V_19 , V_50 ) ;
F_26 ( V_50 , V_29 ) ;
F_30 ( V_19 , V_50 , 0 ) ;
F_31 ( V_19 , 1 ) ;
V_63:
F_4 ( L_23 ) ;
V_32 = 0 ;
V_66:
if ( V_29 )
F_29 ( V_29 ) ;
if ( V_6 ) {
F_32 ( V_6 -> V_19 ) ;
F_33 ( V_6 ) ;
}
F_13 ( L_11 , V_32 ) ;
return V_32 ;
V_61:
F_4 ( L_24 , V_32 ) ;
if ( V_32 == - V_67 ) {
F_31 ( V_19 , 1 ) ;
goto V_66;
}
V_64:
F_28 ( V_8 , L_25 ) ;
F_31 ( V_19 , 1 ) ;
V_32 = - V_68 ;
goto V_66;
V_59:
F_29 ( V_51 ) ;
V_56:
F_32 ( V_6 -> V_19 ) ;
F_33 ( V_6 ) ;
V_53:
F_31 ( V_19 , 1 ) ;
F_13 ( L_26 ) ;
return - V_67 ;
}
int F_43 ( struct V_43 * V_19 ,
struct V_11 * V_11 ,
T_2 V_69 )
{
struct V_7 * V_8 ;
struct V_70 * V_71 ;
struct V_72 * V_72 ;
T_3 V_73 , V_74 ;
unsigned V_75 ;
int V_32 ;
V_8 = F_2 ( V_19 -> V_19 . V_8 ,
struct V_7 , V_20 ) ;
V_71 = F_2 ( V_8 -> V_20 . V_71 ,
struct V_70 , V_71 ) ;
F_3 ( L_27 , V_8 , V_11 -> V_14 ) ;
if ( ! V_8 -> V_26 )
goto V_76;
V_72 = V_8 -> V_26 -> V_27 ;
ASSERT ( F_44 ( V_72 -> V_77 ) ) ;
ASSERT ( V_72 -> V_28 -> V_38 -> V_78 ) ;
ASSERT ( V_72 -> V_28 -> V_38 -> V_79 ) ;
if ( V_72 -> V_80 -> V_81 > V_82 )
goto V_76;
V_75 = V_83 - V_72 -> V_80 -> V_84 ;
V_19 -> V_19 . V_15 &= V_85 ;
V_19 -> V_19 . V_15 |= V_86 ;
V_19 -> V_19 . V_87 = F_22 ;
V_73 = V_11 -> V_14 ;
V_73 <<= V_75 ;
V_74 = V_72 -> V_28 -> V_38 -> V_78 ( V_72 -> V_28 , V_73 ) ;
F_4 ( L_28 ,
( unsigned long long ) V_73 ,
( unsigned long long ) V_74 ) ;
if ( V_74 ) {
V_32 = F_35 ( V_8 , V_19 , V_11 ) ;
} else if ( F_45 ( V_71 , 0 , 1 ) == 0 ) {
F_27 ( V_19 , V_11 ) ;
F_31 ( V_19 , 1 ) ;
V_32 = - V_35 ;
} else {
goto V_76;
}
F_13 ( L_11 , V_32 ) ;
return V_32 ;
V_76:
F_31 ( V_19 , 1 ) ;
F_13 ( L_29 ) ;
return - V_68 ;
}
static int F_46 ( struct V_7 * V_8 ,
struct V_43 * V_19 ,
struct V_88 * V_89 )
{
struct V_5 * V_6 = NULL ;
struct V_24 * V_25 = V_8 -> V_26 -> V_27 -> V_28 ;
struct V_11 * V_51 = NULL , * V_50 , * V_90 , * V_29 = NULL ;
int V_32 = 0 ;
F_3 ( L_16 ) ;
F_47 (netpage, _n, list, lru) {
F_7 ( & V_50 -> V_91 ) ;
F_4 ( L_17 ,
V_50 , V_50 -> V_14 , F_36 ( V_50 ) ) ;
if ( ! V_6 ) {
V_6 = F_37 ( sizeof( * V_6 ) , V_52 ) ;
if ( ! V_6 )
goto V_53;
V_6 -> V_19 = F_38 ( V_19 ) ;
F_39 ( & V_6 -> V_6 ,
F_1 ) ;
}
for (; ; ) {
V_29 = F_14 ( V_25 , V_50 -> V_14 ) ;
if ( V_29 )
goto V_54;
if ( ! V_51 ) {
V_51 = F_40 ( V_52 |
V_55 ) ;
if ( ! V_51 )
goto V_53;
}
V_32 = F_41 ( V_51 , V_25 ,
V_50 -> V_14 ,
V_52 ) ;
if ( V_32 == 0 )
goto V_57;
if ( V_32 != - V_58 )
goto V_53;
}
V_57:
F_4 ( L_18 , V_51 ) ;
V_29 = V_51 ;
V_51 = NULL ;
V_92:
V_32 = V_25 -> V_38 -> V_39 ( NULL , V_29 ) ;
if ( V_32 < 0 )
goto V_61;
V_62:
F_4 ( L_19 ) ;
V_32 = F_41 ( V_50 , V_19 -> V_34 ,
V_50 -> V_14 , V_52 ) ;
if ( V_32 < 0 ) {
if ( V_32 == - V_58 ) {
F_29 ( V_50 ) ;
F_31 ( V_19 , 1 ) ;
continue;
}
goto V_53;
}
F_42 ( V_50 ) ;
V_6 -> V_13 = V_50 ;
F_42 ( V_29 ) ;
V_6 -> V_30 = V_29 ;
V_6 -> V_6 . V_12 = V_29 ;
F_17 ( V_29 , & V_6 -> V_6 ) ;
V_6 = NULL ;
if ( F_18 ( V_29 ) ) {
F_4 ( L_30 , V_29 , V_29 -> V_15 ) ;
F_19 ( V_29 ) ;
}
F_29 ( V_29 ) ;
V_29 = NULL ;
F_29 ( V_50 ) ;
V_50 = NULL ;
continue;
V_54:
F_4 ( L_31 , V_29 ) ;
if ( F_6 ( V_29 ) )
goto V_64;
if ( F_5 ( V_29 ) )
goto V_65;
F_4 ( L_32 , V_29 , V_29 -> V_15 ) ;
if ( ! F_18 ( V_29 ) )
goto V_62;
if ( F_6 ( V_29 ) ) {
F_4 ( L_33 , V_29 -> V_15 ) ;
F_19 ( V_29 ) ;
goto V_64;
}
if ( F_5 ( V_29 ) )
goto V_93;
goto V_92;
V_93:
F_4 ( L_34 , V_29 -> V_15 ) ;
F_19 ( V_29 ) ;
V_65:
F_4 ( L_22 ) ;
V_32 = F_41 ( V_50 , V_19 -> V_34 ,
V_50 -> V_14 , V_52 ) ;
if ( V_32 < 0 ) {
if ( V_32 == - V_58 ) {
F_29 ( V_50 ) ;
F_31 ( V_19 , 1 ) ;
continue;
}
goto V_53;
}
F_26 ( V_50 , V_29 ) ;
F_29 ( V_29 ) ;
V_29 = NULL ;
F_27 ( V_19 , V_50 ) ;
F_30 ( V_19 , V_50 , 0 ) ;
F_29 ( V_50 ) ;
V_50 = NULL ;
F_31 ( V_19 , 1 ) ;
continue;
}
V_50 = NULL ;
F_4 ( L_35 ) ;
V_66:
if ( V_51 )
F_29 ( V_51 ) ;
if ( V_50 )
F_29 ( V_50 ) ;
if ( V_29 )
F_29 ( V_29 ) ;
if ( V_6 ) {
F_32 ( V_19 ) ;
F_33 ( V_6 ) ;
}
F_47 (netpage, _n, list, lru) {
F_7 ( & V_50 -> V_91 ) ;
F_29 ( V_50 ) ;
F_31 ( V_19 , 1 ) ;
}
F_13 ( L_11 , V_32 ) ;
return V_32 ;
V_53:
F_4 ( L_36 ) ;
V_32 = - V_67 ;
goto V_94;
V_61:
F_4 ( L_24 , V_32 ) ;
if ( V_32 == - V_67 )
goto V_94;
V_64:
F_28 ( V_8 , L_25 ) ;
V_32 = - V_68 ;
V_94:
F_31 ( V_19 , 1 ) ;
goto V_66;
}
int F_48 ( struct V_43 * V_19 ,
struct V_88 * V_95 ,
unsigned * V_96 ,
T_2 V_69 )
{
struct V_7 * V_8 ;
struct V_70 * V_71 ;
struct V_88 V_97 ;
struct V_98 V_98 ;
struct V_72 * V_72 ;
struct V_11 * V_11 , * V_90 ;
unsigned V_75 , V_99 ;
int V_32 , V_100 , V_101 ;
V_8 = F_2 ( V_19 -> V_19 . V_8 ,
struct V_7 , V_20 ) ;
V_71 = F_2 ( V_8 -> V_20 . V_71 ,
struct V_70 , V_71 ) ;
F_3 ( L_37 ,
V_8 -> V_20 . V_102 , F_49 ( & V_19 -> V_19 . V_103 ) ,
* V_96 ) ;
if ( ! V_8 -> V_26 )
goto V_104;
V_101 = 1 ;
if ( F_45 ( V_71 , 0 , * V_96 ) < 0 )
V_101 = 0 ;
V_72 = V_8 -> V_26 -> V_27 ;
ASSERT ( F_44 ( V_72 -> V_77 ) ) ;
ASSERT ( V_72 -> V_28 -> V_38 -> V_78 ) ;
ASSERT ( V_72 -> V_28 -> V_38 -> V_79 ) ;
if ( V_72 -> V_80 -> V_81 > V_82 )
goto V_104;
V_75 = V_83 - V_72 -> V_80 -> V_84 ;
F_50 ( & V_98 , 0 ) ;
V_19 -> V_19 . V_15 &= V_85 ;
V_19 -> V_19 . V_15 |= V_86 ;
V_19 -> V_19 . V_87 = F_22 ;
F_16 ( & V_97 ) ;
V_99 = 0 ;
V_32 = V_101 ? - V_35 : - V_68 ;
F_47 (page, _n, pages, lru) {
T_3 V_73 , V_74 ;
V_73 = V_11 -> V_14 ;
V_73 <<= V_75 ;
V_74 = V_72 -> V_28 -> V_38 -> V_78 ( V_72 -> V_28 ,
V_73 ) ;
F_4 ( L_28 ,
( unsigned long long ) V_73 ,
( unsigned long long ) V_74 ) ;
if ( V_74 ) {
F_51 ( & V_11 -> V_91 , & V_97 ) ;
( * V_96 ) -- ;
V_99 ++ ;
} else if ( V_101 && F_52 ( & V_98 , V_11 ) == 0 ) {
F_53 ( V_19 , & V_98 ) ;
F_31 ( V_19 , 1 ) ;
V_32 = - V_35 ;
} else {
F_31 ( V_19 , 1 ) ;
}
}
if ( F_54 ( & V_98 ) > 0 )
F_53 ( V_19 , & V_98 ) ;
if ( F_23 ( V_95 ) )
V_32 = 0 ;
if ( V_99 > 0 ) {
V_100 = F_46 ( V_8 , V_19 , & V_97 ) ;
if ( V_100 == - V_67 || V_100 == - V_105 )
V_32 = V_100 ;
}
F_13 ( L_38 ,
V_32 , * V_96 , F_23 ( V_95 ) ? L_39 : L_16 ) ;
return V_32 ;
V_104:
F_31 ( V_19 , * V_96 ) ;
return - V_68 ;
}
int F_55 ( struct V_43 * V_19 ,
struct V_11 * V_11 ,
T_2 V_69 )
{
struct V_7 * V_8 ;
struct V_70 * V_71 ;
int V_32 ;
V_8 = F_2 ( V_19 -> V_19 . V_8 ,
struct V_7 , V_20 ) ;
V_71 = F_2 ( V_8 -> V_20 . V_71 ,
struct V_70 , V_71 ) ;
F_3 ( L_40 , V_8 , V_11 -> V_14 ) ;
V_32 = F_45 ( V_71 , 0 , 1 ) ;
if ( V_32 == 0 )
F_27 ( V_19 , V_11 ) ;
else
V_32 = - V_68 ;
F_31 ( V_19 , 1 ) ;
F_13 ( L_11 , V_32 ) ;
return V_32 ;
}
int F_56 ( struct V_43 * V_19 ,
struct V_88 * V_95 ,
unsigned * V_96 ,
T_2 V_69 )
{
struct V_7 * V_8 ;
struct V_70 * V_71 ;
struct V_98 V_98 ;
struct V_11 * V_11 ;
int V_32 ;
V_8 = F_2 ( V_19 -> V_19 . V_8 ,
struct V_7 , V_20 ) ;
V_71 = F_2 ( V_8 -> V_20 . V_71 ,
struct V_70 , V_71 ) ;
F_3 ( L_41 , V_8 , * V_96 ) ;
V_32 = F_45 ( V_71 , 0 , * V_96 ) ;
if ( V_32 == 0 ) {
F_50 ( & V_98 , 0 ) ;
F_57 (page, pages, lru) {
if ( F_52 ( & V_98 , V_11 ) == 0 )
F_53 ( V_19 , & V_98 ) ;
}
if ( F_54 ( & V_98 ) > 0 )
F_53 ( V_19 , & V_98 ) ;
V_32 = - V_35 ;
} else {
V_32 = - V_68 ;
}
F_31 ( V_19 , * V_96 ) ;
F_13 ( L_11 , V_32 ) ;
return V_32 ;
}
int F_58 ( struct V_106 * V_19 , struct V_11 * V_11 )
{
struct V_7 * V_8 ;
struct V_70 * V_71 ;
T_4 V_107 ;
struct V_108 * V_108 ;
struct V_109 V_109 ;
T_5 V_110 , V_111 ;
T_6 V_112 ;
void * V_113 ;
int V_32 ;
ASSERT ( V_19 != NULL ) ;
ASSERT ( V_11 != NULL ) ;
V_8 = F_2 ( V_19 -> V_19 . V_8 ,
struct V_7 , V_20 ) ;
F_3 ( L_42 , V_8 , V_11 , V_11 -> V_14 ) ;
if ( ! V_8 -> V_26 ) {
F_13 ( L_29 ) ;
return - V_68 ;
}
ASSERT ( F_44 ( V_8 -> V_26 -> V_27 -> V_77 ) ) ;
V_71 = F_2 ( V_8 -> V_20 . V_71 ,
struct V_70 , V_71 ) ;
V_109 . V_114 = V_71 -> V_114 ;
V_109 . V_115 = V_8 -> V_26 ;
V_108 = F_59 ( & V_109 , V_116 | V_117 , V_71 -> V_118 ) ;
if ( F_60 ( V_108 ) ) {
V_32 = F_61 ( V_108 ) ;
} else {
V_32 = - V_36 ;
if ( V_108 -> V_119 -> V_120 ) {
V_110 = ( T_5 ) V_11 -> V_14 << V_83 ;
V_111 = V_8 -> V_20 . V_121 ;
V_112 = V_82 ;
if ( V_111 & ~ V_122 ) {
F_62 ( V_110 , < , V_111 ) ;
if ( V_111 - V_110 < V_82 ) {
F_4 ( L_43 ,
V_110 , V_111 ) ;
V_112 = V_111 - V_110 ;
F_62 ( V_110 + V_112 , == , V_111 ) ;
}
}
V_113 = F_63 ( V_11 ) ;
F_64 ( V_108 ) ;
V_107 = F_65 () ;
F_66 ( V_123 ) ;
V_32 = V_108 -> V_119 -> V_120 (
V_108 , ( const void V_124 * ) V_113 , V_112 , & V_110 ) ;
F_66 ( V_107 ) ;
F_67 ( V_11 ) ;
F_68 ( V_108 ) ;
if ( V_32 != V_112 )
V_32 = - V_36 ;
}
F_69 ( V_108 ) ;
}
if ( V_32 < 0 ) {
if ( V_32 == - V_36 )
F_28 (
V_8 , L_44 ) ;
V_32 = - V_68 ;
}
F_13 ( L_11 , V_32 ) ;
return V_32 ;
}
void F_70 ( struct V_125 * V_126 , struct V_11 * V_11 )
{
struct V_7 * V_8 ;
struct V_70 * V_71 ;
V_8 = F_2 ( V_126 , struct V_7 , V_20 ) ;
V_71 = F_2 ( V_8 -> V_20 . V_71 ,
struct V_70 , V_71 ) ;
F_3 ( L_45 , V_8 , V_11 -> V_14 ) ;
F_10 ( & V_8 -> V_20 . V_48 -> V_127 ) ;
}
