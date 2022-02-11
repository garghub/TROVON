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
struct V_24 * V_25 = F_13 ( V_8 -> V_26 ) -> V_27 ;
struct V_11 * V_28 = V_6 -> V_29 , * V_30 ;
int V_31 ;
F_3 ( L_4 ,
F_13 ( V_8 -> V_26 ) -> V_32 ,
V_28 -> V_14 , V_28 -> V_15 ) ;
if ( V_28 -> V_33 != V_25 ) {
F_14 ( L_5 ) ;
return - V_34 ;
}
V_30 = F_15 ( V_25 , V_28 -> V_14 ) ;
if ( ! V_30 ) {
F_14 ( L_6 ) ;
return - V_34 ;
}
if ( V_28 != V_30 ) {
F_16 ( V_30 ) ;
F_14 ( L_7 ) ;
return - V_34 ;
}
F_16 ( V_30 ) ;
F_17 ( & V_6 -> V_22 ) ;
F_18 ( V_28 , & V_6 -> V_6 ) ;
if ( F_19 ( V_28 ) ) {
V_31 = - V_35 ;
if ( F_6 ( V_28 ) )
goto V_36;
V_31 = 0 ;
if ( F_5 ( V_28 ) )
goto V_36;
F_4 ( L_8 ) ;
V_31 = V_25 -> V_37 -> V_38 ( NULL , V_28 ) ;
if ( V_31 < 0 )
goto V_36;
}
if ( F_19 ( V_28 ) ) {
F_4 ( L_9 , V_28 , V_28 -> V_15 ) ;
F_20 ( V_28 ) ;
}
F_14 ( L_10 ) ;
return - V_39 ;
V_36:
F_20 ( V_28 ) ;
F_21 ( & V_8 -> V_21 ) ;
F_7 ( & V_6 -> V_22 ) ;
F_22 ( & V_8 -> V_21 ) ;
F_14 ( L_11 , V_31 ) ;
return V_31 ;
}
static void F_23 ( struct V_40 * V_41 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_42 * V_19 ;
int error , V_43 ;
V_19 = F_2 ( V_41 , struct V_42 , V_19 ) ;
V_8 = F_2 ( V_19 -> V_19 . V_8 ,
struct V_7 , V_20 ) ;
F_3 ( L_12 , F_13 ( V_8 -> V_26 ) -> V_32 ) ;
V_43 = 8 ;
F_21 ( & V_8 -> V_21 ) ;
while ( ! F_24 ( & V_19 -> V_23 ) ) {
V_6 = F_25 ( V_19 -> V_23 . V_44 ,
struct V_5 , V_22 ) ;
F_7 ( & V_6 -> V_22 ) ;
F_22 ( & V_8 -> V_21 ) ;
F_4 ( L_13 , V_6 -> V_29 -> V_14 ) ;
V_45:
if ( F_26 ( V_46 ,
& V_8 -> V_20 . V_47 -> V_15 ) ) {
error = - V_48 ;
} else if ( F_5 ( V_6 -> V_29 ) ) {
F_27 ( V_6 -> V_13 , V_6 -> V_29 ) ;
F_28 ( V_6 -> V_19 ,
V_6 -> V_13 ) ;
error = 0 ;
} else if ( ! F_6 ( V_6 -> V_29 ) ) {
error = F_12 ( V_8 , V_6 ) ;
if ( error == - V_39 )
goto V_44;
goto V_45;
} else {
F_29 (
V_8 ,
L_14 ,
( unsigned long ) V_6 -> V_29 -> V_15 ) ;
error = - V_35 ;
}
F_30 ( V_6 -> V_29 ) ;
F_31 ( V_19 , V_6 -> V_13 , error ) ;
F_30 ( V_6 -> V_13 ) ;
F_32 ( V_19 , 1 ) ;
F_33 ( V_19 ) ;
F_34 ( V_6 ) ;
V_44:
V_43 -- ;
if ( V_43 < 0 || F_35 () ) {
if ( ! F_24 ( & V_19 -> V_23 ) )
F_11 ( V_19 ) ;
F_14 ( L_15 ) ;
return;
}
F_21 ( & V_8 -> V_21 ) ;
}
F_22 ( & V_8 -> V_21 ) ;
F_14 ( L_16 ) ;
}
static int F_36 ( struct V_7 * V_8 ,
struct V_42 * V_19 ,
struct V_11 * V_49 )
{
struct V_5 * V_6 ;
struct V_24 * V_25 ;
struct V_11 * V_50 , * V_28 ;
int V_31 ;
F_3 ( L_16 ) ;
F_4 ( L_17 ,
V_49 , V_49 -> V_14 , F_37 ( V_49 ) ) ;
V_6 = F_38 ( sizeof( * V_6 ) , V_51 ) ;
if ( ! V_6 )
goto V_52;
V_6 -> V_13 = V_49 ;
V_6 -> V_19 = F_39 ( V_19 ) ;
F_40 ( & V_6 -> V_6 , F_1 ) ;
V_25 = F_13 ( V_8 -> V_26 ) -> V_27 ;
V_50 = NULL ;
for (; ; ) {
V_28 = F_15 ( V_25 , V_49 -> V_14 ) ;
if ( V_28 )
goto V_53;
if ( ! V_50 ) {
V_50 = F_41 ( V_51 |
V_54 ) ;
if ( ! V_50 )
goto V_55;
}
V_31 = F_42 ( V_50 , V_25 ,
V_49 -> V_14 , V_51 ) ;
if ( V_31 == 0 )
goto V_56;
if ( V_31 != - V_57 )
goto V_58;
}
V_56:
F_4 ( L_18 , V_50 ) ;
V_28 = V_50 ;
V_50 = NULL ;
V_59:
V_31 = V_25 -> V_37 -> V_38 ( NULL , V_28 ) ;
if ( V_31 < 0 )
goto V_60;
V_61:
F_4 ( L_19 ) ;
F_43 ( V_6 -> V_13 ) ;
F_43 ( V_28 ) ;
V_6 -> V_29 = V_28 ;
V_6 -> V_6 . V_12 = V_28 ;
F_18 ( V_28 , & V_6 -> V_6 ) ;
V_6 = NULL ;
if ( F_19 ( V_28 ) ) {
F_4 ( L_9 , V_28 , V_28 -> V_15 ) ;
F_20 ( V_28 ) ;
}
goto V_62;
V_53:
F_4 ( L_20 ) ;
if ( V_50 ) {
F_30 ( V_50 ) ;
V_50 = NULL ;
}
if ( F_6 ( V_28 ) )
goto V_63;
if ( F_5 ( V_28 ) )
goto V_64;
if ( ! F_19 ( V_28 ) )
goto V_61;
F_4 ( L_21 , V_28 , V_28 -> V_15 ) ;
goto V_59;
V_64:
F_4 ( L_22 ) ;
F_28 ( V_19 , V_49 ) ;
F_27 ( V_49 , V_28 ) ;
F_31 ( V_19 , V_49 , 0 ) ;
F_32 ( V_19 , 1 ) ;
V_62:
F_4 ( L_23 ) ;
V_31 = 0 ;
V_65:
if ( V_28 )
F_30 ( V_28 ) ;
if ( V_6 ) {
F_33 ( V_6 -> V_19 ) ;
F_34 ( V_6 ) ;
}
F_14 ( L_11 , V_31 ) ;
return V_31 ;
V_60:
F_4 ( L_24 , V_31 ) ;
if ( V_31 == - V_66 ) {
F_32 ( V_19 , 1 ) ;
goto V_65;
}
V_63:
F_29 ( V_8 , L_25 ) ;
F_32 ( V_19 , 1 ) ;
V_31 = - V_67 ;
goto V_65;
V_58:
F_30 ( V_50 ) ;
V_55:
F_33 ( V_6 -> V_19 ) ;
F_34 ( V_6 ) ;
V_52:
F_32 ( V_19 , 1 ) ;
F_14 ( L_26 ) ;
return - V_66 ;
}
int F_44 ( struct V_42 * V_19 ,
struct V_11 * V_11 ,
T_2 V_68 )
{
struct V_7 * V_8 ;
struct V_69 * V_70 ;
struct V_71 * V_71 ;
T_3 V_72 , V_73 ;
unsigned V_74 ;
int V_31 ;
V_8 = F_2 ( V_19 -> V_19 . V_8 ,
struct V_7 , V_20 ) ;
V_70 = F_2 ( V_8 -> V_20 . V_70 ,
struct V_69 , V_70 ) ;
F_3 ( L_27 , V_8 , V_11 -> V_14 ) ;
if ( ! V_8 -> V_26 )
goto V_75;
V_71 = F_13 ( V_8 -> V_26 ) ;
ASSERT ( F_45 ( V_71 -> V_76 ) ) ;
ASSERT ( V_71 -> V_27 -> V_37 -> V_77 ) ;
ASSERT ( V_71 -> V_27 -> V_37 -> V_78 ) ;
V_74 = V_79 - V_71 -> V_80 -> V_81 ;
V_19 -> V_19 . V_15 &= V_82 ;
V_19 -> V_19 . V_15 |= V_83 ;
V_19 -> V_19 . V_84 = F_23 ;
V_72 = V_11 -> V_14 ;
V_72 <<= V_74 ;
V_73 = V_71 -> V_27 -> V_37 -> V_77 ( V_71 -> V_27 , V_72 ) ;
F_4 ( L_28 ,
( unsigned long long ) V_72 ,
( unsigned long long ) V_73 ) ;
if ( V_73 ) {
V_31 = F_36 ( V_8 , V_19 , V_11 ) ;
} else if ( F_46 ( V_70 , 0 , 1 ) == 0 ) {
F_28 ( V_19 , V_11 ) ;
F_32 ( V_19 , 1 ) ;
V_31 = - V_34 ;
} else {
goto V_75;
}
F_14 ( L_11 , V_31 ) ;
return V_31 ;
V_75:
F_32 ( V_19 , 1 ) ;
F_14 ( L_29 ) ;
return - V_67 ;
}
static int F_47 ( struct V_7 * V_8 ,
struct V_42 * V_19 ,
struct V_85 * V_86 )
{
struct V_5 * V_6 = NULL ;
struct V_24 * V_25 = F_13 ( V_8 -> V_26 ) -> V_27 ;
struct V_11 * V_50 = NULL , * V_49 , * V_87 , * V_28 = NULL ;
int V_31 = 0 ;
F_3 ( L_16 ) ;
F_48 (netpage, _n, list, lru) {
F_7 ( & V_49 -> V_88 ) ;
F_4 ( L_17 ,
V_49 , V_49 -> V_14 , F_37 ( V_49 ) ) ;
if ( ! V_6 ) {
V_6 = F_38 ( sizeof( * V_6 ) , V_51 ) ;
if ( ! V_6 )
goto V_52;
V_6 -> V_19 = F_39 ( V_19 ) ;
F_40 ( & V_6 -> V_6 ,
F_1 ) ;
}
for (; ; ) {
V_28 = F_15 ( V_25 , V_49 -> V_14 ) ;
if ( V_28 )
goto V_53;
if ( ! V_50 ) {
V_50 = F_41 ( V_51 |
V_54 ) ;
if ( ! V_50 )
goto V_52;
}
V_31 = F_42 ( V_50 , V_25 ,
V_49 -> V_14 ,
V_51 ) ;
if ( V_31 == 0 )
goto V_56;
if ( V_31 != - V_57 )
goto V_52;
}
V_56:
F_4 ( L_18 , V_50 ) ;
V_28 = V_50 ;
V_50 = NULL ;
V_89:
V_31 = V_25 -> V_37 -> V_38 ( NULL , V_28 ) ;
if ( V_31 < 0 )
goto V_60;
V_61:
F_4 ( L_19 ) ;
V_31 = F_42 ( V_49 , V_19 -> V_33 ,
V_49 -> V_14 , V_51 ) ;
if ( V_31 < 0 ) {
if ( V_31 == - V_57 ) {
F_30 ( V_49 ) ;
F_32 ( V_19 , 1 ) ;
continue;
}
goto V_52;
}
F_43 ( V_49 ) ;
V_6 -> V_13 = V_49 ;
F_43 ( V_28 ) ;
V_6 -> V_29 = V_28 ;
V_6 -> V_6 . V_12 = V_28 ;
F_18 ( V_28 , & V_6 -> V_6 ) ;
V_6 = NULL ;
if ( F_19 ( V_28 ) ) {
F_4 ( L_30 , V_28 , V_28 -> V_15 ) ;
F_20 ( V_28 ) ;
}
F_30 ( V_28 ) ;
V_28 = NULL ;
F_30 ( V_49 ) ;
V_49 = NULL ;
continue;
V_53:
F_4 ( L_31 , V_28 ) ;
if ( F_6 ( V_28 ) )
goto V_63;
if ( F_5 ( V_28 ) )
goto V_64;
F_4 ( L_32 , V_28 , V_28 -> V_15 ) ;
if ( ! F_19 ( V_28 ) )
goto V_61;
if ( F_6 ( V_28 ) ) {
F_4 ( L_33 , V_28 -> V_15 ) ;
F_20 ( V_28 ) ;
goto V_63;
}
if ( F_5 ( V_28 ) )
goto V_90;
goto V_89;
V_90:
F_4 ( L_34 , V_28 -> V_15 ) ;
F_20 ( V_28 ) ;
V_64:
F_4 ( L_22 ) ;
V_31 = F_42 ( V_49 , V_19 -> V_33 ,
V_49 -> V_14 , V_51 ) ;
if ( V_31 < 0 ) {
if ( V_31 == - V_57 ) {
F_30 ( V_49 ) ;
F_32 ( V_19 , 1 ) ;
continue;
}
goto V_52;
}
F_27 ( V_49 , V_28 ) ;
F_30 ( V_28 ) ;
V_28 = NULL ;
F_28 ( V_19 , V_49 ) ;
F_31 ( V_19 , V_49 , 0 ) ;
F_30 ( V_49 ) ;
V_49 = NULL ;
F_32 ( V_19 , 1 ) ;
continue;
}
V_49 = NULL ;
F_4 ( L_35 ) ;
V_65:
if ( V_50 )
F_30 ( V_50 ) ;
if ( V_49 )
F_30 ( V_49 ) ;
if ( V_28 )
F_30 ( V_28 ) ;
if ( V_6 ) {
F_33 ( V_19 ) ;
F_34 ( V_6 ) ;
}
F_48 (netpage, _n, list, lru) {
F_7 ( & V_49 -> V_88 ) ;
F_30 ( V_49 ) ;
F_32 ( V_19 , 1 ) ;
}
F_14 ( L_11 , V_31 ) ;
return V_31 ;
V_52:
F_4 ( L_36 ) ;
V_31 = - V_66 ;
goto V_91;
V_60:
F_4 ( L_24 , V_31 ) ;
if ( V_31 == - V_66 )
goto V_91;
V_63:
F_29 ( V_8 , L_25 ) ;
V_31 = - V_67 ;
V_91:
F_32 ( V_19 , 1 ) ;
goto V_65;
}
int F_49 ( struct V_42 * V_19 ,
struct V_85 * V_92 ,
unsigned * V_93 ,
T_2 V_68 )
{
struct V_7 * V_8 ;
struct V_69 * V_70 ;
struct V_85 V_94 ;
struct V_95 V_95 ;
struct V_71 * V_71 ;
struct V_11 * V_11 , * V_87 ;
unsigned V_74 , V_96 ;
int V_31 , V_97 , V_98 ;
V_8 = F_2 ( V_19 -> V_19 . V_8 ,
struct V_7 , V_20 ) ;
V_70 = F_2 ( V_8 -> V_20 . V_70 ,
struct V_69 , V_70 ) ;
F_3 ( L_37 ,
V_8 -> V_20 . V_99 , F_50 ( & V_19 -> V_19 . V_100 ) ,
* V_93 ) ;
if ( ! V_8 -> V_26 )
goto V_101;
V_98 = 1 ;
if ( F_46 ( V_70 , 0 , * V_93 ) < 0 )
V_98 = 0 ;
V_71 = F_13 ( V_8 -> V_26 ) ;
ASSERT ( F_45 ( V_71 -> V_76 ) ) ;
ASSERT ( V_71 -> V_27 -> V_37 -> V_77 ) ;
ASSERT ( V_71 -> V_27 -> V_37 -> V_78 ) ;
V_74 = V_79 - V_71 -> V_80 -> V_81 ;
F_51 ( & V_95 , 0 ) ;
V_19 -> V_19 . V_15 &= V_82 ;
V_19 -> V_19 . V_15 |= V_83 ;
V_19 -> V_19 . V_84 = F_23 ;
F_17 ( & V_94 ) ;
V_96 = 0 ;
V_31 = V_98 ? - V_34 : - V_67 ;
F_48 (page, _n, pages, lru) {
T_3 V_72 , V_73 ;
V_72 = V_11 -> V_14 ;
V_72 <<= V_74 ;
V_73 = V_71 -> V_27 -> V_37 -> V_77 ( V_71 -> V_27 ,
V_72 ) ;
F_4 ( L_28 ,
( unsigned long long ) V_72 ,
( unsigned long long ) V_73 ) ;
if ( V_73 ) {
F_52 ( & V_11 -> V_88 , & V_94 ) ;
( * V_93 ) -- ;
V_96 ++ ;
} else if ( V_98 && F_53 ( & V_95 , V_11 ) == 0 ) {
F_54 ( V_19 , & V_95 ) ;
F_32 ( V_19 , 1 ) ;
V_31 = - V_34 ;
} else {
F_32 ( V_19 , 1 ) ;
}
}
if ( F_55 ( & V_95 ) > 0 )
F_54 ( V_19 , & V_95 ) ;
if ( F_24 ( V_92 ) )
V_31 = 0 ;
if ( V_96 > 0 ) {
V_97 = F_47 ( V_8 , V_19 , & V_94 ) ;
if ( V_97 == - V_66 || V_97 == - V_102 )
V_31 = V_97 ;
}
F_14 ( L_38 ,
V_31 , * V_93 , F_24 ( V_92 ) ? L_39 : L_16 ) ;
return V_31 ;
V_101:
F_32 ( V_19 , * V_93 ) ;
return - V_67 ;
}
int F_56 ( struct V_42 * V_19 ,
struct V_11 * V_11 ,
T_2 V_68 )
{
struct V_7 * V_8 ;
struct V_69 * V_70 ;
int V_31 ;
V_8 = F_2 ( V_19 -> V_19 . V_8 ,
struct V_7 , V_20 ) ;
V_70 = F_2 ( V_8 -> V_20 . V_70 ,
struct V_69 , V_70 ) ;
F_3 ( L_40 , V_8 , V_11 -> V_14 ) ;
V_31 = F_46 ( V_70 , 0 , 1 ) ;
if ( V_31 == 0 )
F_28 ( V_19 , V_11 ) ;
else
V_31 = - V_67 ;
F_32 ( V_19 , 1 ) ;
F_14 ( L_11 , V_31 ) ;
return V_31 ;
}
int F_57 ( struct V_42 * V_19 ,
struct V_85 * V_92 ,
unsigned * V_93 ,
T_2 V_68 )
{
struct V_7 * V_8 ;
struct V_69 * V_70 ;
struct V_95 V_95 ;
struct V_11 * V_11 ;
int V_31 ;
V_8 = F_2 ( V_19 -> V_19 . V_8 ,
struct V_7 , V_20 ) ;
V_70 = F_2 ( V_8 -> V_20 . V_70 ,
struct V_69 , V_70 ) ;
F_3 ( L_41 , V_8 , * V_93 ) ;
V_31 = F_46 ( V_70 , 0 , * V_93 ) ;
if ( V_31 == 0 ) {
F_51 ( & V_95 , 0 ) ;
F_58 (page, pages, lru) {
if ( F_53 ( & V_95 , V_11 ) == 0 )
F_54 ( V_19 , & V_95 ) ;
}
if ( F_55 ( & V_95 ) > 0 )
F_54 ( V_19 , & V_95 ) ;
V_31 = - V_34 ;
} else {
V_31 = - V_67 ;
}
F_32 ( V_19 , * V_93 ) ;
F_14 ( L_11 , V_31 ) ;
return V_31 ;
}
int F_59 ( struct V_103 * V_19 , struct V_11 * V_11 )
{
struct V_7 * V_8 ;
struct V_69 * V_70 ;
struct V_104 * V_104 ;
struct V_105 V_105 ;
T_4 V_106 , V_107 ;
T_5 V_108 ;
void * V_109 ;
int V_31 = - V_67 ;
ASSERT ( V_19 != NULL ) ;
ASSERT ( V_11 != NULL ) ;
V_8 = F_2 ( V_19 -> V_19 . V_8 ,
struct V_7 , V_20 ) ;
F_3 ( L_42 , V_8 , V_11 , V_11 -> V_14 ) ;
if ( ! V_8 -> V_26 ) {
F_14 ( L_29 ) ;
return - V_67 ;
}
ASSERT ( F_60 ( V_8 -> V_26 ) ) ;
V_70 = F_2 ( V_8 -> V_20 . V_70 ,
struct V_69 , V_70 ) ;
V_106 = ( T_4 ) V_11 -> V_14 << V_79 ;
V_107 = V_8 -> V_20 . V_110 ;
if ( V_106 >= V_107 )
goto error;
V_105 . V_111 = V_70 -> V_111 ;
V_105 . V_112 = V_8 -> V_26 ;
V_104 = F_61 ( & V_105 , V_113 | V_114 , V_70 -> V_115 ) ;
if ( F_62 ( V_104 ) ) {
V_31 = F_63 ( V_104 ) ;
goto V_116;
}
V_108 = V_117 ;
if ( V_107 & ~ V_118 ) {
if ( V_107 - V_106 < V_117 ) {
F_4 ( L_43 ,
V_106 , V_107 ) ;
V_108 = V_107 - V_106 ;
F_64 ( V_106 + V_108 , == , V_107 ) ;
}
}
V_109 = F_65 ( V_11 ) ;
V_31 = F_66 ( V_104 , V_109 , V_108 , & V_106 ) ;
F_67 ( V_11 ) ;
F_68 ( V_104 ) ;
if ( V_31 != V_108 )
goto V_119;
F_14 ( L_44 ) ;
return 0 ;
V_119:
V_31 = - V_35 ;
V_116:
if ( V_31 == - V_35 )
F_29 ( V_8 ,
L_45 ) ;
error:
F_14 ( L_46 , V_31 ) ;
return - V_67 ;
}
void F_69 ( struct V_120 * V_121 , struct V_11 * V_11 )
{
struct V_7 * V_8 ;
struct V_69 * V_70 ;
V_8 = F_2 ( V_121 , struct V_7 , V_20 ) ;
V_70 = F_2 ( V_8 -> V_20 . V_70 ,
struct V_69 , V_70 ) ;
F_3 ( L_47 , V_8 , V_11 -> V_14 ) ;
F_10 ( & V_8 -> V_20 . V_47 -> V_122 ) ;
}
