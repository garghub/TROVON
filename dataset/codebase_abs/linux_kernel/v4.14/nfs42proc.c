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
T_2 V_21 ;
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
V_19 -> V_64 . V_65 = F_26 ( sizeof( struct V_66 ) , V_67 ) ;
if ( ! V_19 -> V_64 . V_65 )
return - V_28 ;
V_21 = F_7 ( V_11 -> V_29 , V_11 , & V_2 ,
& args -> V_30 , & V_19 -> V_31 , 0 ) ;
if ( V_21 == - V_36 )
V_11 -> V_43 &= ~ V_68 ;
if ( V_21 )
goto V_69;
if ( F_27 ( & V_19 -> V_70 . V_71 . V_71 ,
& V_19 -> V_64 . V_65 -> V_71 ) ) {
V_21 = - V_72 ;
goto V_69;
}
F_23 ( V_54 , V_57 ,
V_57 + V_19 -> V_70 . V_59 ) ;
V_21 = V_19 -> V_70 . V_59 ;
V_69:
F_9 ( V_19 -> V_64 . V_65 ) ;
return V_21 ;
}
T_2 F_28 ( struct V_3 * V_47 , T_1 V_55 ,
struct V_3 * V_49 , T_1 V_57 ,
T_3 V_59 )
{
struct V_10 * V_11 = F_3 ( F_2 ( V_49 ) ) ;
struct V_5 * V_48 ;
struct V_5 * V_50 ;
struct V_51 args = {
. V_73 = F_4 ( F_2 ( V_47 ) ) ,
. V_56 = V_55 ,
. V_74 = F_4 ( F_2 ( V_49 ) ) ,
. V_58 = V_57 ,
. V_59 = V_59 ,
} ;
struct V_52 V_19 ;
struct V_32 V_75 = {
. V_9 = F_2 ( V_47 ) ,
. V_76 = & args . V_60 ,
} ;
struct V_32 V_77 = {
. V_9 = F_2 ( V_49 ) ,
. V_76 = & args . V_63 ,
} ;
T_2 V_34 , V_78 ;
if ( ! F_18 ( F_2 ( V_49 ) , V_68 ) )
return - V_37 ;
V_48 = F_11 ( F_12 ( V_47 ) ) ;
if ( F_13 ( V_48 ) )
return F_14 ( V_48 ) ;
V_75 . V_35 = V_48 -> V_25 -> V_35 ;
V_50 = F_11 ( F_12 ( V_49 ) ) ;
if ( F_13 ( V_50 ) ) {
V_34 = F_14 ( V_50 ) ;
goto V_79;
}
V_77 . V_35 = V_50 -> V_25 -> V_35 ;
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
} if ( V_34 == - V_72 ) {
V_77 . V_38 = 1 ;
continue;
}
V_78 = F_15 ( V_11 , V_34 , & V_75 ) ;
V_34 = F_15 ( V_11 , V_34 , & V_77 ) ;
if ( ! V_34 )
V_34 = V_78 ;
} while ( V_75 . V_38 || V_77 . V_38 );
F_16 ( V_50 ) ;
V_79:
F_16 ( V_48 ) ;
return V_34 ;
}
static T_1 F_29 ( struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_7 , int V_80 )
{
struct V_9 * V_9 = F_2 ( V_4 ) ;
struct V_81 args = {
. V_82 = F_4 ( V_9 ) ,
. V_83 = V_7 ,
. V_84 = ( V_80 == V_85 ) ?
V_86 : V_87 ,
} ;
struct V_88 V_19 ;
struct V_1 V_2 = {
. V_39 = & V_40 [ V_89 ] ,
. V_22 = & args ,
. V_23 = & V_19 ,
} ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
int V_21 ;
if ( ! F_18 ( V_9 , V_90 ) )
return - V_36 ;
V_21 = F_5 ( & args . V_91 , V_6 -> V_25 ,
V_6 , V_61 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_25 ( V_9 -> V_62 ,
V_7 , V_92 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_11 -> V_29 , V_11 , & V_2 ,
& args . V_30 , & V_19 . V_31 , 0 ) ;
if ( V_21 == - V_36 )
V_11 -> V_43 &= ~ V_90 ;
if ( V_21 )
return V_21 ;
return F_30 ( V_4 , V_19 . V_93 , V_9 -> V_94 -> V_95 ) ;
}
T_1 F_31 ( struct V_3 * V_4 , T_1 V_7 , int V_80 )
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
V_34 = F_29 ( V_4 , V_6 , V_7 , V_80 ) ;
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
F_32 ( struct V_96 * V_97 , void * V_98 )
{
struct V_99 * V_100 = V_98 ;
struct V_9 * V_9 = V_100 -> V_9 ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
struct V_101 * V_102 ;
F_33 ( & V_9 -> V_103 ) ;
V_102 = F_34 ( V_9 ) -> V_104 ;
if ( ! F_35 ( V_102 ) ) {
F_36 ( & V_9 -> V_103 ) ;
F_37 ( V_97 , 0 ) ;
return;
}
F_38 ( & V_100 -> args . V_76 , & V_102 -> V_105 ) ;
F_36 ( & V_9 -> V_103 ) ;
F_39 ( V_11 -> V_106 , & V_100 -> args . V_30 ,
& V_100 -> V_19 . V_31 , V_97 ) ;
}
static void
F_40 ( struct V_96 * V_97 , void * V_98 )
{
struct V_99 * V_100 = V_98 ;
struct V_9 * V_9 = V_100 -> V_9 ;
struct V_101 * V_102 ;
if ( ! F_41 ( V_97 , & V_100 -> V_19 . V_31 ) )
return;
switch ( V_97 -> V_107 ) {
case 0 :
break;
case - V_108 :
case - V_109 :
case - V_110 :
case - V_111 :
case - V_112 :
F_33 ( & V_9 -> V_103 ) ;
V_102 = F_34 ( V_9 ) -> V_104 ;
if ( F_35 ( V_102 ) &&
F_42 ( & V_100 -> args . V_76 ,
& V_102 -> V_105 ) ) {
F_43 ( V_113 ) ;
F_44 ( V_102 , & V_113 ) ;
F_36 ( & V_9 -> V_103 ) ;
F_45 ( & V_113 ) ;
F_46 ( V_9 , 0 ) ;
} else
F_36 ( & V_9 -> V_103 ) ;
break;
case - V_114 :
F_33 ( & V_9 -> V_103 ) ;
V_102 = F_34 ( V_9 ) -> V_104 ;
if ( F_35 ( V_102 ) &&
F_47 ( & V_100 -> args . V_76 ,
& V_102 -> V_105 ) ) {
if ( ! F_48 ( & V_102 -> V_105 ,
& V_100 -> args . V_76 ) )
F_49 ( V_97 , V_115 ) ;
F_50 ( V_97 ) ;
}
F_36 ( & V_9 -> V_103 ) ;
break;
case - V_36 :
case - V_37 :
F_3 ( V_9 ) -> V_43 &= ~ V_116 ;
}
}
static void
F_51 ( void * V_98 )
{
struct V_99 * V_100 = V_98 ;
struct V_117 * V_118 = V_100 -> args . V_118 ;
int V_119 ;
for ( V_119 = 0 ; V_119 < V_100 -> args . V_120 ; V_119 ++ ) {
if ( V_118 [ V_119 ] . V_121 . V_122 && V_118 [ V_119 ] . V_121 . V_122 -> free )
V_118 [ V_119 ] . V_121 . V_122 -> free ( & V_118 [ V_119 ] . V_121 ) ;
}
F_52 ( F_34 ( V_100 -> args . V_9 ) -> V_104 ) ;
F_53 () ;
F_54 ( V_123 , & F_34 ( V_100 -> args . V_9 ) -> V_124 ) ;
F_55 () ;
F_56 ( V_100 -> V_9 ) ;
F_9 ( V_100 -> args . V_118 ) ;
F_9 ( V_100 ) ;
}
int F_57 ( struct V_10 * V_11 ,
struct V_99 * V_100 )
{
struct V_1 V_2 = {
. V_39 = & V_40 [ V_125 ] ,
. V_22 = & V_100 -> args ,
. V_23 = & V_100 -> V_19 ,
} ;
struct V_126 V_127 = {
. V_128 = V_11 -> V_29 ,
. V_1 = & V_2 ,
. V_129 = & V_130 ,
. V_131 = V_100 ,
. V_124 = V_132 ,
} ;
struct V_96 * V_97 ;
V_100 -> V_9 = F_58 ( V_100 -> args . V_9 ) ;
if ( ! V_100 -> V_9 ) {
F_51 ( V_100 ) ;
return - V_72 ;
}
F_59 ( & V_100 -> args . V_30 , & V_100 -> V_19 . V_31 , 0 ) ;
V_97 = F_60 ( & V_127 ) ;
if ( F_13 ( V_97 ) )
return F_14 ( V_97 ) ;
F_61 ( V_97 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_3 * V_133 ,
struct V_3 * V_134 , struct V_5 * V_48 ,
struct V_5 * V_50 , T_1 V_135 ,
T_1 V_136 , T_1 V_59 )
{
struct V_9 * V_137 = F_2 ( V_133 ) ;
struct V_9 * V_54 = F_2 ( V_134 ) ;
struct V_10 * V_11 = F_3 ( V_54 ) ;
struct V_138 args = {
. V_73 = F_4 ( V_137 ) ,
. V_74 = F_4 ( V_54 ) ,
. V_135 = V_135 ,
. V_136 = V_136 ,
. V_59 = V_59 ,
. V_139 = V_11 -> V_17 ,
} ;
struct V_140 V_19 = {
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
V_19 . V_141 = F_6 () ;
if ( ! V_19 . V_141 )
return - V_28 ;
V_21 = F_7 ( V_11 -> V_29 , V_11 , V_2 ,
& args . V_30 , & V_19 . V_31 , 0 ) ;
if ( V_21 == 0 )
V_21 = F_8 ( V_54 , V_19 . V_141 ) ;
F_9 ( V_19 . V_141 ) ;
return V_21 ;
}
int F_63 ( struct V_3 * V_133 , struct V_3 * V_134 ,
T_1 V_135 , T_1 V_136 , T_1 V_59 )
{
struct V_1 V_2 = {
. V_39 = & V_40 [ V_142 ] ,
} ;
struct V_9 * V_9 = F_2 ( V_133 ) ;
struct V_10 * V_11 = F_3 ( F_2 ( V_133 ) ) ;
struct V_5 * V_48 ;
struct V_5 * V_50 ;
struct V_32 V_75 = { } ;
struct V_32 V_77 = { } ;
int V_34 , V_78 ;
if ( ! F_18 ( V_9 , V_143 ) )
return - V_37 ;
V_48 = F_11 ( F_12 ( V_133 ) ) ;
if ( F_13 ( V_48 ) )
return F_14 ( V_48 ) ;
V_75 . V_9 = F_2 ( V_133 ) ;
V_75 . V_35 = V_48 -> V_25 -> V_35 ;
V_50 = F_11 ( F_12 ( V_134 ) ) ;
if ( F_13 ( V_50 ) ) {
V_34 = F_14 ( V_50 ) ;
goto V_79;
}
V_77 . V_9 = F_2 ( V_134 ) ;
V_77 . V_35 = V_50 -> V_25 -> V_35 ;
do {
V_34 = F_62 ( & V_2 , V_133 , V_134 , V_48 , V_50 ,
V_135 , V_136 , V_59 ) ;
if ( V_34 == - V_36 || V_34 == - V_37 ) {
F_3 ( V_9 ) -> V_43 &= ~ V_143 ;
V_34 = - V_37 ;
break;
}
V_78 = F_15 ( V_11 , V_34 , & V_75 ) ;
V_34 = F_15 ( V_11 , V_34 , & V_77 ) ;
if ( ! V_34 )
V_34 = V_78 ;
} while ( V_75 . V_38 || V_77 . V_38 );
F_16 ( V_50 ) ;
V_79:
F_16 ( V_48 ) ;
return V_34 ;
}
