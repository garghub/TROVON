static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 || V_2 -> V_4 )
return 0 ;
if ( V_2 -> V_5 . V_6 && F_2 ( V_2 -> V_5 . V_6 ) )
return 0 ;
if ( V_2 -> V_7 && F_3 ( V_8 , & V_2 -> V_7 -> V_9 ) )
return 0 ;
F_4 ( F_5 ( & V_2 -> V_10 ) == 0 ) ;
F_4 ( V_2 -> V_11 == 0 ) ;
F_4 ( V_2 -> V_12 == 0 ) ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_13 , V_14 , V_15 , V_16 ;
struct V_17 V_5 ;
struct V_18 V_19 ;
F_7 ( L_1 ) ;
F_4 ( ! V_2 -> V_20 && ! V_2 -> V_21 ) ;
if ( V_2 -> V_22 ) {
V_13 = - V_23 ;
goto V_24;
}
if ( F_1 ( V_2 ) ) {
F_8 ( & V_2 -> V_25 ) ;
V_13 = 0 ;
goto V_26;
}
for ( V_16 = 0 ; V_16 < V_2 -> V_27 ; V_16 ++ ) {
V_13 = F_9 ( & V_2 -> V_28 [ V_16 ] . V_29 ) ;
if ( V_13 )
goto V_24;
}
V_2 -> V_30 += 1 ;
V_13 = F_10 ( V_2 ) ;
if ( V_13 )
goto V_24;
V_13 = F_11 ( V_2 ) ;
if ( V_13 )
goto V_24;
V_13 = F_12 ( V_2 , & V_14 ) ;
if ( V_13 )
goto V_24;
V_13 = F_13 ( V_2 , & V_5 ) ;
if ( V_13 )
goto V_24;
V_13 = F_14 ( V_2 ) ;
if ( V_13 )
goto V_24;
V_13 = F_15 ( V_2 ) ;
if ( V_13 )
goto V_24;
F_16 ( V_2 , & V_19 ) ;
F_8 ( & V_2 -> V_25 ) ;
V_13 = F_17 ( V_2 ) ;
if ( V_13 )
goto V_31;
V_13 = F_18 ( V_2 ) ;
if ( V_13 )
goto V_31;
V_13 = F_19 ( V_2 ) ;
if ( V_13 )
goto V_31;
V_15 = V_2 -> V_32 ;
V_13 = F_20 ( V_2 , V_14 ) ;
if ( V_13 )
goto V_31;
V_13 = F_21 ( V_2 , & V_5 ) ;
if ( V_13 )
goto V_31;
V_2 -> V_33 -> V_30 = F_22 ( V_2 -> V_30 ) ;
V_2 -> V_33 -> V_34 = F_23 ( V_14 ) ;
V_2 -> V_33 -> V_35 = F_23 ( V_5 . V_36 ) ;
V_2 -> V_33 -> V_37 = F_23 ( V_5 . V_38 ) ;
V_2 -> V_33 -> V_39 = F_23 ( V_5 . V_40 ) ;
V_2 -> V_33 -> V_41 = F_23 ( V_2 -> V_41 ) ;
V_2 -> V_33 -> V_42 = F_23 ( V_2 -> V_42 ) ;
V_2 -> V_33 -> V_43 = F_22 ( V_2 -> V_44 . V_45 ) ;
V_2 -> V_33 -> V_46 = F_23 ( V_2 -> V_46 ) ;
V_2 -> V_33 -> V_47 = F_23 ( V_2 -> V_47 ) ;
V_2 -> V_33 -> V_48 = F_23 ( V_2 -> V_48 ) ;
V_2 -> V_33 -> V_49 = F_23 ( V_2 -> V_49 ) ;
V_2 -> V_33 -> V_50 = F_23 ( V_2 -> V_50 ) ;
V_2 -> V_33 -> V_51 = F_23 ( V_2 -> V_51 ) ;
V_2 -> V_33 -> V_52 = F_23 ( V_2 -> V_52 ) ;
V_2 -> V_33 -> V_53 = F_23 ( V_2 -> V_53 ) ;
V_2 -> V_33 -> V_54 = F_23 ( V_2 -> V_54 ) ;
V_2 -> V_33 -> V_55 = F_23 ( V_19 . V_55 ) ;
V_2 -> V_33 -> V_56 = F_23 ( V_19 . V_56 ) ;
V_2 -> V_33 -> V_57 = F_22 ( V_19 . V_57 ) ;
V_2 -> V_33 -> V_58 = F_22 ( V_19 . V_58 ) ;
V_2 -> V_33 -> V_59 = F_22 ( V_19 . V_59 ) ;
V_2 -> V_33 -> V_60 = F_22 ( V_19 . V_60 ) ;
V_2 -> V_33 -> V_61 = F_22 ( V_19 . V_61 ) ;
if ( V_2 -> V_62 )
V_2 -> V_33 -> V_9 |= F_23 ( V_63 ) ;
else
V_2 -> V_33 -> V_9 &= ~ F_23 ( V_63 ) ;
V_13 = F_24 ( V_2 ) ;
if ( V_13 )
goto V_31;
V_13 = F_25 ( V_2 , V_15 ) ;
if ( V_13 )
goto V_31;
V_13 = F_26 ( V_2 ) ;
if ( V_13 )
goto V_31;
V_13 = F_27 ( V_2 ) ;
if ( V_13 )
goto V_31;
V_26:
F_28 ( & V_2 -> V_64 ) ;
V_2 -> V_65 = V_66 ;
F_29 ( & V_2 -> V_67 ) ;
F_7 ( L_2 ) ;
F_30 ( & V_2 -> V_64 ) ;
return 0 ;
V_24:
F_8 ( & V_2 -> V_25 ) ;
V_31:
F_31 ( L_3 , V_13 ) ;
F_28 ( & V_2 -> V_64 ) ;
V_2 -> V_65 = V_68 ;
F_29 ( & V_2 -> V_67 ) ;
F_30 ( & V_2 -> V_64 ) ;
F_32 ( V_2 , V_13 ) ;
return V_13 ;
}
static int F_33 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_65 != V_69 &&
V_2 -> V_65 != V_70 )
goto V_31;
F_30 ( & V_2 -> V_64 ) ;
F_34 ( & V_2 -> V_25 ) ;
F_28 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_65 == V_70 )
V_2 -> V_65 = V_71 ;
else if ( V_2 -> V_65 == V_69 )
V_2 -> V_65 = V_72 ;
else
goto V_73;
F_30 ( & V_2 -> V_64 ) ;
return F_6 ( V_2 ) ;
V_73:
F_8 ( & V_2 -> V_25 ) ;
V_31:
F_30 ( & V_2 -> V_64 ) ;
return 0 ;
}
int F_35 ( void * V_74 )
{
int V_13 ;
struct V_1 * V_2 = V_74 ;
F_36 ( L_4 ,
V_2 -> V_75 , V_76 -> V_77 ) ;
F_37 () ;
while ( 1 ) {
if ( F_38 () )
break;
if ( F_39 () )
continue;
F_40 ( V_78 ) ;
if ( ! V_2 -> V_79 ) {
if ( F_38 () )
break;
F_41 () ;
continue;
} else
F_42 ( V_80 ) ;
V_2 -> V_79 = 0 ;
V_13 = F_43 ( V_2 ) ;
if ( V_13 )
F_32 ( V_2 , V_13 ) ;
F_33 ( V_2 ) ;
F_44 () ;
}
F_36 ( L_5 , V_2 -> V_75 ) ;
return 0 ;
}
void F_45 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_64 ) ;
switch ( V_2 -> V_65 ) {
case V_66 :
case V_69 :
F_7 ( L_6 , F_46 ( V_2 -> V_65 ) ,
F_46 ( V_70 ) ) ;
V_2 -> V_65 = V_70 ;
break;
case V_72 :
F_7 ( L_6 , F_46 ( V_2 -> V_65 ) ,
F_46 ( V_71 ) ) ;
V_2 -> V_65 = V_71 ;
break;
case V_70 :
case V_71 :
case V_68 :
break;
}
F_30 ( & V_2 -> V_64 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_65 == V_66 ) {
F_7 ( L_6 , F_46 ( V_2 -> V_65 ) ,
F_46 ( V_69 ) ) ;
V_2 -> V_65 = V_69 ;
F_30 ( & V_2 -> V_64 ) ;
F_48 ( V_2 ) ;
} else
F_30 ( & V_2 -> V_64 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
F_7 ( L_7 , V_76 -> V_77 ) ;
F_50 ( V_2 -> V_67 , V_2 -> V_65 != V_72 &&
V_2 -> V_65 != V_71 ) ;
F_7 ( L_8 , V_76 -> V_77 ) ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_28 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_65 == V_68 ) {
V_13 = - V_23 ;
goto V_31;
}
if ( V_2 -> V_65 == V_72 )
V_2 -> V_65 = V_71 ;
if ( V_2 -> V_65 == V_71 ) {
F_30 ( & V_2 -> V_64 ) ;
return F_49 ( V_2 ) ;
}
F_30 ( & V_2 -> V_64 ) ;
F_34 ( & V_2 -> V_25 ) ;
F_28 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_65 == V_68 ) {
V_13 = - V_23 ;
goto V_73;
}
if ( V_2 -> V_65 == V_72 )
V_2 -> V_65 = V_71 ;
if ( V_2 -> V_65 == V_71 ) {
F_8 ( & V_2 -> V_25 ) ;
F_30 ( & V_2 -> V_64 ) ;
return F_49 ( V_2 ) ;
}
V_2 -> V_65 = V_71 ;
F_30 ( & V_2 -> V_64 ) ;
V_13 = F_6 ( V_2 ) ;
return V_13 ;
V_73:
F_8 ( & V_2 -> V_25 ) ;
V_31:
F_30 ( & V_2 -> V_64 ) ;
return V_13 ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_81 = 0 ;
F_28 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_65 == V_69 ) {
F_7 ( L_9 ) ;
V_2 -> V_65 = V_70 ;
} else
F_7 ( L_10 ) ;
if ( V_2 -> V_65 == V_70 )
V_81 = 1 ;
F_30 ( & V_2 -> V_64 ) ;
return V_81 ;
}
int F_53 ( struct V_1 * V_2 , struct V_17 * V_5 )
{
struct V_82 * V_83 ;
int V_36 , V_38 , V_40 , V_13 = 0 ;
struct V_84 * V_85 = V_2 -> V_86 ;
V_85 -> V_87 = * V_5 ;
V_36 = V_85 -> V_87 . V_36 ;
V_38 = V_85 -> V_87 . V_38 ;
V_40 = V_85 -> V_87 . V_40 ;
V_83 = F_54 ( V_2 -> V_88 , V_89 ) ;
if ( ! V_83 )
return - V_90 ;
V_13 = F_55 ( V_2 , V_83 , V_91 , V_40 , V_36 , V_38 ) ;
if ( V_13 )
goto V_31;
V_85 -> V_92 = F_56 ( V_83 -> V_93 ) ;
V_85 -> V_94 = F_57 ( V_83 -> V_95 . V_96 ) ;
V_31:
F_58 ( V_83 ) ;
return V_13 ;
}
int F_21 ( struct V_1 * V_2 , struct V_17 * V_5 )
{
int V_36 , V_38 , V_40 , V_13 = 0 , V_97 ( V_98 ) , V_99 ;
int V_100 = 1 , V_101 ;
struct V_84 * V_85 = V_2 -> V_86 ;
union V_102 V_97 ( V_103 ) , V_104 , V_105 , V_106 ;
unsigned long long V_97 ( V_107 ) ;
struct V_82 * V_83 ;
struct V_108 V_109 ;
struct V_110 * V_16 ;
T_1 V_111 ;
if ( ! F_59 ( V_2 ) )
return 0 ;
F_60 ( & V_109 ) ;
V_111 = sizeof( struct V_110 ) + F_61 ( V_2 , V_2 -> V_112 ) -
V_113 ;
V_36 = V_85 -> V_87 . V_36 ;
V_38 = V_85 -> V_87 . V_38 ;
V_40 = V_85 -> V_87 . V_40 ;
V_101 = 0 ;
while ( 1 ) {
struct V_114 * V_115 ;
V_16 = F_54 ( V_111 , V_89 ) ;
if ( ! V_16 ) {
V_13 = - V_90 ;
goto V_116;
}
V_16 -> V_101 = V_101 ;
F_62 ( & V_16 -> V_109 , & V_109 ) ;
V_83 = & V_16 -> V_83 ;
V_13 = F_55 ( V_2 , V_83 , V_91 , V_40 , V_36 , V_38 ) ;
if ( V_13 )
goto V_116;
V_99 = F_56 ( V_83 -> V_99 ) ;
if ( V_99 < 1 || V_99 > V_2 -> V_112 ) {
V_13 = 1 ;
goto V_117;
}
if ( V_100 ) {
V_100 = 0 ;
if ( F_56 ( V_83 -> V_93 ) != V_85 -> V_92 ) {
V_13 = 2 ;
goto V_117;
}
if ( F_57 ( V_83 -> V_95 . V_96 ) != V_85 -> V_94 ) {
V_13 = 3 ;
goto V_117;
}
V_98 = F_56 ( V_83 -> V_93 ) + 1 ;
V_107 = F_57 ( V_83 -> V_95 . V_96 ) + 1 ;
F_63 ( V_2 , F_64 ( V_2 , V_83 ) , & V_103 ) ;
F_65 ( V_2 , & V_104 , V_118 ) ;
}
F_66 ( V_2 , & V_104 , & V_16 -> V_104 ) ;
if ( F_56 ( V_83 -> V_93 ) != V_98 - 1 ) {
V_13 = 3 ;
goto V_117;
}
if ( F_57 ( V_83 -> V_95 . V_96 ) >= V_107 ) {
V_13 = 4 ;
goto V_117;
}
F_63 ( V_2 , F_64 ( V_2 , V_83 ) , & V_105 ) ;
V_115 = F_67 ( V_2 , V_83 , V_99 - 1 ) ;
F_63 ( V_2 , & V_115 -> V_119 , & V_106 ) ;
if ( F_68 ( V_2 , & V_103 , & V_105 ) > 0 ) {
V_13 = 5 ;
goto V_117;
}
if ( F_68 ( V_2 , & V_104 , & V_106 ) < 0 ) {
V_13 = 6 ;
goto V_117;
}
if ( F_68 ( V_2 , & V_104 , & V_106 ) == 0 )
if ( ! F_69 ( V_2 , & V_106 ) ) {
V_13 = 7 ;
goto V_117;
}
if ( F_56 ( V_83 -> V_93 ) == 0 ) {
while ( 1 ) {
F_70 ( & V_16 -> V_109 ) ;
F_58 ( V_16 ) ;
if ( F_71 ( & V_109 ) )
goto V_31;
V_16 = F_72 ( V_109 . V_120 , struct V_110 ,
V_109 ) ;
V_83 = & V_16 -> V_83 ;
if ( V_101 + 1 < F_56 ( V_83 -> V_99 ) ) {
V_101 = V_101 + 1 ;
break;
} else
V_101 = V_16 -> V_101 ;
}
} else
V_101 = 0 ;
V_98 = F_56 ( V_83 -> V_93 ) ;
V_107 = F_57 ( V_83 -> V_95 . V_96 ) ;
V_115 = F_67 ( V_2 , V_83 , V_101 ) ;
V_36 = F_73 ( V_115 -> V_36 ) ;
V_38 = F_73 ( V_115 -> V_38 ) ;
V_40 = F_73 ( V_115 -> V_40 ) ;
F_63 ( V_2 , & V_115 -> V_119 , & V_103 ) ;
if ( V_101 + 1 < F_56 ( V_83 -> V_99 ) ) {
V_115 = F_67 ( V_2 , V_83 , V_101 + 1 ) ;
F_63 ( V_2 , & V_115 -> V_119 , & V_104 ) ;
} else
F_66 ( V_2 , & V_16 -> V_104 , & V_104 ) ;
}
V_31:
V_13 = F_53 ( V_2 , V_5 ) ;
if ( V_13 )
goto V_116;
return 0 ;
V_117:
F_31 ( L_11 , V_16 -> V_101 ) ;
F_74 ( V_2 , V_83 ) ;
F_70 ( & V_16 -> V_109 ) ;
F_58 ( V_16 ) ;
if ( ! F_71 ( & V_109 ) ) {
V_16 = F_72 ( V_109 . V_120 , struct V_110 , V_109 ) ;
F_31 ( L_12 ) ;
F_74 ( V_2 , & V_16 -> V_83 ) ;
}
V_116:
while ( ! F_71 ( & V_109 ) ) {
V_16 = F_72 ( V_109 . V_121 , struct V_110 , V_109 ) ;
F_70 ( & V_16 -> V_109 ) ;
F_58 ( V_16 ) ;
}
F_31 ( L_13 , V_13 ) ;
if ( V_13 > 0 )
V_13 = - V_122 ;
return V_13 ;
}
