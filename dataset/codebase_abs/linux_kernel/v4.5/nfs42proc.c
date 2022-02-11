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
F_22 ( V_9 ) ;
F_19 ( V_9 ) ;
V_34 = F_10 ( & V_2 , V_4 , V_7 , V_8 ) ;
if ( V_34 == 0 )
F_23 ( V_9 , V_7 , ( V_7 + V_8 ) - 1 ) ;
if ( V_34 == - V_37 )
F_3 ( V_9 ) -> V_43 &= ~ V_45 ;
F_20 ( V_9 ) ;
return V_34 ;
}
static T_1 F_24 ( struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_7 , int V_46 )
{
struct V_9 * V_9 = F_2 ( V_4 ) ;
struct V_47 args = {
. V_48 = F_4 ( V_9 ) ,
. V_49 = V_7 ,
. V_50 = ( V_46 == V_51 ) ?
V_52 : V_53 ,
} ;
struct V_54 V_19 ;
struct V_1 V_2 = {
. V_39 = & V_40 [ V_55 ] ,
. V_22 = & args ,
. V_23 = & V_19 ,
} ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
int V_21 ;
if ( ! F_18 ( V_9 , V_56 ) )
return - V_36 ;
V_21 = F_5 ( & args . V_57 , V_6 -> V_25 ,
V_6 , V_58 ) ;
if ( V_21 )
return V_21 ;
F_22 ( V_9 ) ;
V_21 = F_7 ( V_11 -> V_29 , V_11 , & V_2 ,
& args . V_30 , & V_19 . V_31 , 0 ) ;
if ( V_21 == - V_36 )
V_11 -> V_43 &= ~ V_56 ;
if ( V_21 )
return V_21 ;
return F_25 ( V_4 , V_19 . V_59 , V_9 -> V_60 -> V_61 ) ;
}
T_1 F_26 ( struct V_3 * V_4 , T_1 V_7 , int V_46 )
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
V_34 = F_24 ( V_4 , V_6 , V_7 , V_46 ) ;
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
F_27 ( struct V_62 * V_63 , void * V_64 )
{
struct V_65 * V_66 = V_64 ;
struct V_10 * V_11 = F_3 ( V_66 -> args . V_9 ) ;
F_28 ( F_29 ( V_11 ) , & V_66 -> args . V_30 ,
& V_66 -> V_19 . V_31 , V_63 ) ;
}
static void
F_30 ( struct V_62 * V_63 , void * V_64 )
{
struct V_65 * V_66 = V_64 ;
struct V_9 * V_9 = V_66 -> V_9 ;
struct V_67 * V_68 ;
if ( ! F_31 ( V_63 , & V_66 -> V_19 . V_31 ) )
return;
switch ( V_63 -> V_69 ) {
case 0 :
break;
case - V_70 :
case - V_71 :
case - V_72 :
case - V_73 :
F_32 ( & V_9 -> V_74 ) ;
V_68 = F_33 ( V_9 ) -> V_75 ;
if ( V_68 && F_34 ( & V_66 -> args . V_76 ,
& V_68 -> V_77 ) ) {
F_35 ( V_78 ) ;
F_36 ( V_79 , & V_68 -> V_80 ) ;
F_37 ( V_68 , & V_78 , NULL ) ;
F_38 ( & V_9 -> V_74 ) ;
F_39 ( & V_78 ) ;
} else
F_38 ( & V_9 -> V_74 ) ;
break;
case - V_36 :
case - V_37 :
F_3 ( V_9 ) -> V_43 &= ~ V_81 ;
default:
break;
}
F_40 ( L_1 , V_82 , V_63 -> V_69 ) ;
}
static void
F_41 ( void * V_64 )
{
struct V_65 * V_66 = V_64 ;
struct V_10 * V_83 = F_3 ( V_66 -> args . V_9 ) ;
if ( V_83 -> V_84 -> V_85 )
V_83 -> V_84 -> V_85 ( V_66 ) ;
F_42 ( F_33 ( V_66 -> args . V_9 ) -> V_75 ) ;
F_43 () ;
F_44 ( V_86 , & F_33 ( V_66 -> args . V_9 ) -> V_87 ) ;
F_45 () ;
F_46 ( V_66 -> V_9 ) ;
F_9 ( V_66 -> args . V_88 ) ;
F_9 ( V_66 ) ;
}
int F_47 ( struct V_10 * V_11 ,
struct V_65 * V_66 )
{
struct V_1 V_2 = {
. V_39 = & V_40 [ V_89 ] ,
. V_22 = & V_66 -> args ,
. V_23 = & V_66 -> V_19 ,
} ;
struct V_90 V_91 = {
. V_92 = V_11 -> V_29 ,
. V_1 = & V_2 ,
. V_93 = & V_94 ,
. V_95 = V_66 ,
. V_87 = V_96 ,
} ;
struct V_62 * V_63 ;
V_66 -> V_9 = F_48 ( V_66 -> args . V_9 ) ;
if ( ! V_66 -> V_9 ) {
F_41 ( V_66 ) ;
return - V_97 ;
}
F_49 ( & V_66 -> args . V_30 , & V_66 -> V_19 . V_31 , 0 ) ;
V_63 = F_50 ( & V_91 ) ;
if ( F_13 ( V_63 ) )
return F_14 ( V_63 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_3 * V_98 ,
struct V_3 * V_99 , struct V_5 * V_100 ,
struct V_5 * V_101 , T_1 V_102 ,
T_1 V_103 , T_1 V_104 )
{
struct V_9 * V_105 = F_2 ( V_98 ) ;
struct V_9 * V_106 = F_2 ( V_99 ) ;
struct V_10 * V_11 = F_3 ( V_106 ) ;
struct V_107 args = {
. V_108 = F_4 ( V_105 ) ,
. V_109 = F_4 ( V_106 ) ,
. V_102 = V_102 ,
. V_103 = V_103 ,
. V_104 = V_104 ,
. V_110 = V_11 -> V_17 ,
} ;
struct V_111 V_19 = {
. V_11 = V_11 ,
} ;
int V_21 ;
V_2 -> V_22 = & args ;
V_2 -> V_23 = & V_19 ;
V_21 = F_5 ( & args . V_112 , V_100 -> V_25 ,
V_100 , V_58 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_5 ( & args . V_113 , V_101 -> V_25 ,
V_101 , V_26 ) ;
if ( V_21 )
return V_21 ;
V_19 . V_114 = F_6 () ;
if ( ! V_19 . V_114 )
return - V_28 ;
V_21 = F_7 ( V_11 -> V_29 , V_11 , V_2 ,
& args . V_30 , & V_19 . V_31 , 0 ) ;
if ( V_21 == 0 )
V_21 = F_8 ( V_106 , V_19 . V_114 ) ;
F_9 ( V_19 . V_114 ) ;
return V_21 ;
}
int F_52 ( struct V_3 * V_98 , struct V_3 * V_99 ,
T_1 V_102 , T_1 V_103 , T_1 V_104 )
{
struct V_1 V_2 = {
. V_39 = & V_40 [ V_115 ] ,
} ;
struct V_9 * V_9 = F_2 ( V_98 ) ;
struct V_10 * V_11 = F_3 ( F_2 ( V_98 ) ) ;
struct V_5 * V_100 ;
struct V_5 * V_101 ;
struct V_32 V_116 = { } ;
struct V_32 V_117 = { } ;
int V_34 , V_118 ;
if ( ! F_18 ( V_9 , V_119 ) )
return - V_37 ;
V_100 = F_11 ( F_12 ( V_98 ) ) ;
if ( F_13 ( V_100 ) )
return F_14 ( V_100 ) ;
V_116 . V_9 = F_2 ( V_98 ) ;
V_116 . V_35 = V_100 -> V_25 -> V_35 ;
V_101 = F_11 ( F_12 ( V_99 ) ) ;
if ( F_13 ( V_101 ) ) {
V_34 = F_14 ( V_101 ) ;
goto V_120;
}
V_117 . V_9 = F_2 ( V_99 ) ;
V_117 . V_35 = V_101 -> V_25 -> V_35 ;
do {
V_34 = F_51 ( & V_2 , V_98 , V_99 , V_100 , V_101 ,
V_102 , V_103 , V_104 ) ;
if ( V_34 == - V_36 || V_34 == - V_37 ) {
F_3 ( V_9 ) -> V_43 &= ~ V_119 ;
V_34 = - V_37 ;
break;
}
V_118 = F_15 ( V_11 , V_34 , & V_116 ) ;
V_34 = F_15 ( V_11 , V_34 , & V_117 ) ;
if ( ! V_34 )
V_34 = V_118 ;
} while ( V_116 . V_38 || V_117 . V_38 );
F_16 ( V_101 ) ;
V_120:
F_16 ( V_100 ) ;
return V_34 ;
}
