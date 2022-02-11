static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_7 , T_1 V_8 )
{
struct V_9 * V_9 = F_2 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
struct V_12 args = {
. V_13 = F_4 ( V_9 ) ,
. V_14 = V_7 ,
. V_15 = V_8 ,
. V_16 = V_11 -> V_17 ,
} ;
struct V_18 V_19 = {
. V_20 = V_11 ,
} ;
int V_21 ;
V_2 -> V_22 = & args ;
V_2 -> V_23 = & V_19 ;
V_21 = F_5 ( & args . V_24 , V_6 -> V_25 ,
V_6 , V_26 ) ;
if ( V_21 )
return V_21 ;
V_19 . V_27 = F_6 () ;
if ( ! V_19 . V_27 )
return - V_28 ;
V_21 = F_7 ( V_11 -> V_29 , V_11 , V_2 ,
& args . V_30 , & V_19 . V_31 , 0 ) ;
if ( V_21 == 0 )
V_21 = F_8 ( V_9 , V_19 . V_27 ) ;
F_9 ( V_19 . V_27 ) ;
return V_21 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_7 , T_1 V_8 )
{
struct V_10 * V_11 = F_3 ( F_2 ( V_4 ) ) ;
struct V_32 V_33 = { } ;
struct V_5 * V_6 ;
int V_34 ;
V_6 = F_11 ( F_12 ( V_4 ) ) ;
if ( F_13 ( V_6 ) )
return F_14 ( V_6 ) ;
V_33 . V_9 = F_2 ( V_4 ) ;
V_33 . V_35 = V_6 -> V_25 -> V_35 ;
do {
V_34 = F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) ;
if ( V_34 == - V_36 ) {
V_34 = - V_37 ;
break;
}
V_34 = F_15 ( V_11 , V_34 , & V_33 ) ;
} while ( V_33 . V_38 );
F_16 ( V_6 ) ;
return V_34 ;
}
int F_17 ( struct V_3 * V_4 , T_1 V_7 , T_1 V_8 )
{
struct V_1 V_2 = {
. V_39 = & V_40 [ V_41 ] ,
} ;
struct V_9 * V_9 = F_2 ( V_4 ) ;
int V_34 ;
if ( ! F_18 ( V_9 , V_42 ) )
return - V_37 ;
F_19 ( V_9 ) ;
V_34 = F_10 ( & V_2 , V_4 , V_7 , V_8 ) ;
if ( V_34 == - V_37 )
F_3 ( V_9 ) -> V_43 &= ~ V_42 ;
F_20 ( V_9 ) ;
return V_34 ;
}
int F_21 ( struct V_3 * V_4 , T_1 V_7 , T_1 V_8 )
{
struct V_1 V_2 = {
. V_39 = & V_40 [ V_44 ] ,
} ;
struct V_9 * V_9 = F_2 ( V_4 ) ;
int V_34 ;
if ( ! F_18 ( V_9 , V_45 ) )
return - V_37 ;
F_19 ( V_9 ) ;
V_34 = F_22 ( V_9 ) ;
if ( V_34 )
goto V_46;
V_34 = F_10 ( & V_2 , V_4 , V_7 , V_8 ) ;
if ( V_34 == 0 )
F_23 ( V_9 , V_7 , ( V_7 + V_8 ) - 1 ) ;
if ( V_34 == - V_37 )
F_3 ( V_9 ) -> V_43 &= ~ V_45 ;
V_46:
F_20 ( V_9 ) ;
return V_34 ;
}
static T_2 F_24 ( struct V_3 * V_47 ,
struct V_5 * V_48 ,
struct V_3 * V_49 ,
struct V_5 * V_50 ,
struct V_51 * args ,
struct V_52 * V_19 )
{
struct V_1 V_2 = {
. V_39 = & V_40 [ V_53 ] ,
. V_22 = args ,
. V_23 = V_19 ,
} ;
struct V_9 * V_54 = F_2 ( V_49 ) ;
struct V_10 * V_11 = F_3 ( V_54 ) ;
T_1 V_55 = args -> V_56 ;
T_1 V_57 = args -> V_58 ;
T_3 V_59 = args -> V_59 ;
int V_21 ;
V_21 = F_5 ( & args -> V_60 , V_48 -> V_25 ,
V_48 , V_61 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_25 ( F_2 ( V_47 ) -> V_62 ,
V_55 , V_55 + ( T_1 ) V_59 - 1 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_5 ( & args -> V_63 , V_50 -> V_25 ,
V_50 , V_26 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_22 ( V_54 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_11 -> V_29 , V_11 , & V_2 ,
& args -> V_30 , & V_19 -> V_31 , 0 ) ;
if ( V_21 == - V_36 )
V_11 -> V_43 &= ~ V_64 ;
if ( V_21 )
return V_21 ;
if ( V_19 -> V_65 . V_66 . V_67 != V_68 ) {
V_21 = F_26 ( V_49 , & V_19 -> V_65 . V_66 . V_66 ) ;
if ( V_21 )
return V_21 ;
}
F_23 ( V_54 , V_57 ,
V_57 + V_19 -> V_65 . V_59 ) ;
return V_19 -> V_65 . V_59 ;
}
T_2 F_27 ( struct V_3 * V_47 , T_1 V_55 ,
struct V_3 * V_49 , T_1 V_57 ,
T_3 V_59 )
{
struct V_10 * V_11 = F_3 ( F_2 ( V_49 ) ) ;
struct V_5 * V_48 ;
struct V_5 * V_50 ;
struct V_51 args = {
. V_69 = F_4 ( F_2 ( V_47 ) ) ,
. V_56 = V_55 ,
. V_70 = F_4 ( F_2 ( V_49 ) ) ,
. V_58 = V_57 ,
. V_59 = V_59 ,
} ;
struct V_52 V_19 ;
struct V_32 V_71 = {
. V_9 = F_2 ( V_47 ) ,
. V_72 = & args . V_60 ,
} ;
struct V_32 V_73 = {
. V_9 = F_2 ( V_49 ) ,
. V_72 = & args . V_63 ,
} ;
T_2 V_34 , V_74 ;
if ( ! F_18 ( F_2 ( V_49 ) , V_64 ) )
return - V_37 ;
V_48 = F_11 ( F_12 ( V_47 ) ) ;
if ( F_13 ( V_48 ) )
return F_14 ( V_48 ) ;
V_71 . V_35 = V_48 -> V_25 -> V_35 ;
V_50 = F_11 ( F_12 ( V_49 ) ) ;
if ( F_13 ( V_50 ) ) {
V_34 = F_14 ( V_50 ) ;
goto V_75;
}
V_73 . V_35 = V_50 -> V_25 -> V_35 ;
do {
F_19 ( F_2 ( V_49 ) ) ;
V_34 = F_24 ( V_47 , V_48 ,
V_49 , V_50 ,
& args , & V_19 ) ;
F_20 ( F_2 ( V_49 ) ) ;
if ( V_34 >= 0 )
break;
if ( V_34 == - V_36 ) {
V_34 = - V_37 ;
break;
}
V_74 = F_15 ( V_11 , V_34 , & V_71 ) ;
V_34 = F_15 ( V_11 , V_34 , & V_73 ) ;
if ( ! V_34 )
V_34 = V_74 ;
} while ( V_71 . V_38 || V_73 . V_38 );
F_16 ( V_50 ) ;
V_75:
F_16 ( V_48 ) ;
return V_34 ;
}
static T_1 F_28 ( struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_7 , int V_76 )
{
struct V_9 * V_9 = F_2 ( V_4 ) ;
struct V_77 args = {
. V_78 = F_4 ( V_9 ) ,
. V_79 = V_7 ,
. V_80 = ( V_76 == V_81 ) ?
V_82 : V_83 ,
} ;
struct V_84 V_19 ;
struct V_1 V_2 = {
. V_39 = & V_40 [ V_85 ] ,
. V_22 = & args ,
. V_23 = & V_19 ,
} ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
int V_21 ;
if ( ! F_18 ( V_9 , V_86 ) )
return - V_36 ;
V_21 = F_5 ( & args . V_87 , V_6 -> V_25 ,
V_6 , V_61 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_25 ( V_9 -> V_62 ,
V_7 , V_88 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_11 -> V_29 , V_11 , & V_2 ,
& args . V_30 , & V_19 . V_31 , 0 ) ;
if ( V_21 == - V_36 )
V_11 -> V_43 &= ~ V_86 ;
if ( V_21 )
return V_21 ;
return F_29 ( V_4 , V_19 . V_89 , V_9 -> V_90 -> V_91 ) ;
}
T_1 F_30 ( struct V_3 * V_4 , T_1 V_7 , int V_76 )
{
struct V_10 * V_11 = F_3 ( F_2 ( V_4 ) ) ;
struct V_32 V_33 = { } ;
struct V_5 * V_6 ;
T_1 V_34 ;
V_6 = F_11 ( F_12 ( V_4 ) ) ;
if ( F_13 ( V_6 ) )
return F_14 ( V_6 ) ;
V_33 . V_9 = F_2 ( V_4 ) ;
V_33 . V_35 = V_6 -> V_25 -> V_35 ;
do {
V_34 = F_28 ( V_4 , V_6 , V_7 , V_76 ) ;
if ( V_34 >= 0 )
break;
if ( V_34 == - V_36 ) {
V_34 = - V_37 ;
break;
}
V_34 = F_15 ( V_11 , V_34 , & V_33 ) ;
} while ( V_33 . V_38 );
F_16 ( V_6 ) ;
return V_34 ;
}
static void
F_31 ( struct V_92 * V_93 , void * V_94 )
{
struct V_95 * V_96 = V_94 ;
struct V_9 * V_9 = V_96 -> V_9 ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
struct V_97 * V_98 ;
F_32 ( & V_9 -> V_99 ) ;
V_98 = F_33 ( V_9 ) -> V_100 ;
if ( ! F_34 ( V_98 ) ) {
F_35 ( & V_9 -> V_99 ) ;
F_36 ( V_93 , 0 ) ;
return;
}
F_37 ( & V_96 -> args . V_72 , & V_98 -> V_101 ) ;
F_35 ( & V_9 -> V_99 ) ;
F_38 ( V_11 -> V_102 , & V_96 -> args . V_30 ,
& V_96 -> V_19 . V_31 , V_93 ) ;
}
static void
F_39 ( struct V_92 * V_93 , void * V_94 )
{
struct V_95 * V_96 = V_94 ;
struct V_9 * V_9 = V_96 -> V_9 ;
struct V_97 * V_98 ;
if ( ! F_40 ( V_93 , & V_96 -> V_19 . V_31 ) )
return;
switch ( V_93 -> V_103 ) {
case 0 :
break;
case - V_104 :
case - V_105 :
case - V_106 :
case - V_107 :
case - V_108 :
F_32 ( & V_9 -> V_99 ) ;
V_98 = F_33 ( V_9 ) -> V_100 ;
if ( F_34 ( V_98 ) &&
F_41 ( & V_96 -> args . V_72 ,
& V_98 -> V_101 ) ) {
F_42 ( V_109 ) ;
F_43 ( V_98 , & V_109 ) ;
F_35 ( & V_9 -> V_99 ) ;
F_44 ( & V_109 ) ;
} else
F_35 ( & V_9 -> V_99 ) ;
break;
case - V_110 :
F_32 ( & V_9 -> V_99 ) ;
V_98 = F_33 ( V_9 ) -> V_100 ;
if ( F_34 ( V_98 ) &&
F_45 ( & V_96 -> args . V_72 ,
& V_98 -> V_101 ) ) {
if ( ! F_46 ( & V_98 -> V_101 ,
& V_96 -> args . V_72 ) )
F_47 ( V_93 , V_111 ) ;
F_48 ( V_93 ) ;
}
F_35 ( & V_9 -> V_99 ) ;
break;
case - V_36 :
case - V_37 :
F_3 ( V_9 ) -> V_43 &= ~ V_112 ;
}
F_49 ( L_1 , V_113 , V_93 -> V_103 ) ;
}
static void
F_50 ( void * V_94 )
{
struct V_95 * V_96 = V_94 ;
struct V_114 * V_115 = V_96 -> args . V_115 ;
int V_116 ;
for ( V_116 = 0 ; V_116 < V_96 -> args . V_117 ; V_116 ++ ) {
if ( V_115 [ V_116 ] . V_118 . V_119 && V_115 [ V_116 ] . V_118 . V_119 -> free )
V_115 [ V_116 ] . V_118 . V_119 -> free ( & V_115 [ V_116 ] . V_118 ) ;
}
F_51 ( F_33 ( V_96 -> args . V_9 ) -> V_100 ) ;
F_52 () ;
F_53 ( V_120 , & F_33 ( V_96 -> args . V_9 ) -> V_121 ) ;
F_54 () ;
F_55 ( V_96 -> V_9 ) ;
F_9 ( V_96 -> args . V_115 ) ;
F_9 ( V_96 ) ;
}
int F_56 ( struct V_10 * V_11 ,
struct V_95 * V_96 )
{
struct V_1 V_2 = {
. V_39 = & V_40 [ V_122 ] ,
. V_22 = & V_96 -> args ,
. V_23 = & V_96 -> V_19 ,
} ;
struct V_123 V_124 = {
. V_125 = V_11 -> V_29 ,
. V_1 = & V_2 ,
. V_126 = & V_127 ,
. V_128 = V_96 ,
. V_121 = V_129 ,
} ;
struct V_92 * V_93 ;
V_96 -> V_9 = F_57 ( V_96 -> args . V_9 ) ;
if ( ! V_96 -> V_9 ) {
F_50 ( V_96 ) ;
return - V_130 ;
}
F_58 ( & V_96 -> args . V_30 , & V_96 -> V_19 . V_31 , 0 ) ;
V_93 = F_59 ( & V_124 ) ;
if ( F_13 ( V_93 ) )
return F_14 ( V_93 ) ;
F_60 ( V_93 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_3 * V_131 ,
struct V_3 * V_132 , struct V_5 * V_48 ,
struct V_5 * V_50 , T_1 V_133 ,
T_1 V_134 , T_1 V_59 )
{
struct V_9 * V_135 = F_2 ( V_131 ) ;
struct V_9 * V_54 = F_2 ( V_132 ) ;
struct V_10 * V_11 = F_3 ( V_54 ) ;
struct V_136 args = {
. V_69 = F_4 ( V_135 ) ,
. V_70 = F_4 ( V_54 ) ,
. V_133 = V_133 ,
. V_134 = V_134 ,
. V_59 = V_59 ,
. V_137 = V_11 -> V_17 ,
} ;
struct V_138 V_19 = {
. V_11 = V_11 ,
} ;
int V_21 ;
V_2 -> V_22 = & args ;
V_2 -> V_23 = & V_19 ;
V_21 = F_5 ( & args . V_60 , V_48 -> V_25 ,
V_48 , V_61 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_5 ( & args . V_63 , V_50 -> V_25 ,
V_50 , V_26 ) ;
if ( V_21 )
return V_21 ;
V_19 . V_139 = F_6 () ;
if ( ! V_19 . V_139 )
return - V_28 ;
V_21 = F_7 ( V_11 -> V_29 , V_11 , V_2 ,
& args . V_30 , & V_19 . V_31 , 0 ) ;
if ( V_21 == 0 )
V_21 = F_8 ( V_54 , V_19 . V_139 ) ;
F_9 ( V_19 . V_139 ) ;
return V_21 ;
}
int F_62 ( struct V_3 * V_131 , struct V_3 * V_132 ,
T_1 V_133 , T_1 V_134 , T_1 V_59 )
{
struct V_1 V_2 = {
. V_39 = & V_40 [ V_140 ] ,
} ;
struct V_9 * V_9 = F_2 ( V_131 ) ;
struct V_10 * V_11 = F_3 ( F_2 ( V_131 ) ) ;
struct V_5 * V_48 ;
struct V_5 * V_50 ;
struct V_32 V_71 = { } ;
struct V_32 V_73 = { } ;
int V_34 , V_74 ;
if ( ! F_18 ( V_9 , V_141 ) )
return - V_37 ;
V_48 = F_11 ( F_12 ( V_131 ) ) ;
if ( F_13 ( V_48 ) )
return F_14 ( V_48 ) ;
V_71 . V_9 = F_2 ( V_131 ) ;
V_71 . V_35 = V_48 -> V_25 -> V_35 ;
V_50 = F_11 ( F_12 ( V_132 ) ) ;
if ( F_13 ( V_50 ) ) {
V_34 = F_14 ( V_50 ) ;
goto V_75;
}
V_73 . V_9 = F_2 ( V_132 ) ;
V_73 . V_35 = V_50 -> V_25 -> V_35 ;
do {
V_34 = F_61 ( & V_2 , V_131 , V_132 , V_48 , V_50 ,
V_133 , V_134 , V_59 ) ;
if ( V_34 == - V_36 || V_34 == - V_37 ) {
F_3 ( V_9 ) -> V_43 &= ~ V_141 ;
V_34 = - V_37 ;
break;
}
V_74 = F_15 ( V_11 , V_34 , & V_71 ) ;
V_34 = F_15 ( V_11 , V_34 , & V_73 ) ;
if ( ! V_34 )
V_34 = V_74 ;
} while ( V_71 . V_38 || V_73 . V_38 );
F_16 ( V_50 ) ;
V_75:
F_16 ( V_48 ) ;
return V_34 ;
}
