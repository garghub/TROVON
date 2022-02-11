static int F_1 ( struct V_1 * V_2 ,
bool V_3 , int V_4 , int V_5 ,
int V_6 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 . V_9 ;
struct V_11 * V_12 = V_9 -> V_13 ;
bool V_14 = false ;
int V_15 = V_2 -> V_10 . V_16 / 8 ;
int V_17 , V_18 ;
unsigned long V_19 ;
struct V_20 * V_21 = F_2 ( V_2 -> V_21 ) ;
if ( ( V_6 <= 0 ) ||
( V_4 + V_6 > V_2 -> V_10 . V_6 ) ||
( V_5 + V_7 > V_2 -> V_10 . V_7 ) ) {
F_3 ( L_1 ,
V_6 , V_7 , V_4 , V_5 ,
V_2 -> V_10 . V_6 , V_2 -> V_10 . V_7 ) ;
return - V_22 ;
}
if ( F_4 () || V_3 )
V_14 = true ;
V_17 = V_4 + V_6 - 1 ;
V_18 = V_5 + V_7 - 1 ;
F_5 ( & V_2 -> V_23 , V_19 ) ;
if ( V_2 -> y1 < V_5 )
V_5 = V_2 -> y1 ;
if ( V_2 -> V_18 > V_18 )
V_18 = V_2 -> V_18 ;
if ( V_2 -> V_24 < V_4 )
V_4 = V_2 -> V_24 ;
if ( V_2 -> V_17 > V_17 )
V_17 = V_2 -> V_17 ;
if ( V_14 ) {
V_2 -> V_24 = V_4 ;
V_2 -> V_17 = V_17 ;
V_2 -> y1 = V_5 ;
V_2 -> V_18 = V_18 ;
F_6 ( & V_2 -> V_23 , V_19 ) ;
return 0 ;
}
V_2 -> V_24 = V_2 -> y1 = V_25 ;
V_2 -> V_17 = V_2 -> V_18 = 0 ;
F_6 ( & V_2 -> V_23 , V_19 ) ;
{
T_1 V_26 ;
T_1 V_27 = V_17 - V_4 + 1 ;
T_1 V_28 = V_18 - V_5 + 1 ;
V_26 = ( V_5 * V_2 -> V_10 . V_29 [ 0 ] ) + V_4 * V_15 ;
F_7 ( V_12 , V_21 -> V_30 ,
V_26 ,
F_8 ( V_27 ) ,
F_8 ( V_28 ) ,
F_8 ( V_4 ) ,
F_8 ( V_5 ) ,
NULL ) ;
}
F_9 ( V_12 , V_21 -> V_30 ,
V_4 , V_5 , V_17 - V_4 + 1 , V_18 - V_5 + 1 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_31 ,
struct V_32 * V_33 ,
unsigned V_34 )
{
struct V_11 * V_12 = V_31 -> V_10 . V_9 -> V_13 ;
struct V_20 * V_21 = F_2 ( V_31 -> V_21 ) ;
struct V_32 V_35 ;
struct V_32 * V_36 ;
int V_37 , V_38 , V_39 , V_40 ;
int V_41 ;
int V_42 = 1 ;
if ( ! V_34 ) {
V_34 = 1 ;
V_33 = & V_35 ;
V_35 . V_24 = V_35 . y1 = 0 ;
V_35 . V_17 = V_31 -> V_10 . V_6 ;
V_35 . V_18 = V_31 -> V_10 . V_7 ;
}
V_37 = V_33 -> V_24 ;
V_38 = V_33 -> V_17 ;
V_39 = V_33 -> y1 ;
V_40 = V_33 -> V_18 ;
for ( V_41 = 1 , V_36 = V_33 + V_42 ;
V_41 < V_34 ; V_41 ++ , V_36 += V_42 ) {
V_37 = F_11 ( int , V_37 , ( int ) V_36 -> V_24 ) ;
V_38 = F_12 ( int , V_38 , ( int ) V_36 -> V_17 ) ;
V_39 = F_11 ( int , V_39 , ( int ) V_36 -> y1 ) ;
V_40 = F_12 ( int , V_40 , ( int ) V_36 -> V_18 ) ;
}
if ( V_21 -> V_43 )
return F_1 ( V_31 , false , V_37 , V_39 ,
V_38 - V_37 , V_40 - V_39 ) ;
F_9 ( V_12 , V_21 -> V_30 ,
V_37 , V_39 , V_38 - V_37 , V_40 - V_39 ) ;
return 0 ;
}
static void F_13 ( struct V_44 * V_45 )
{
struct V_46 * V_46 = F_14 ( V_45 ) ;
struct V_47 * V_48 =
F_15 ( V_46 , struct V_47 , V_45 ) ;
struct V_1 * V_31 = & V_48 -> V_31 ;
F_1 ( & V_48 -> V_31 , false , V_31 -> V_24 , V_31 -> y1 ,
V_31 -> V_17 - V_31 -> V_24 , V_31 -> V_18 - V_31 -> y1 ) ;
}
static void F_16 ( struct V_49 * V_50 ,
const struct V_51 * V_52 )
{
struct V_47 * V_48 = V_50 -> V_53 ;
F_17 ( V_50 , V_52 ) ;
F_1 ( & V_48 -> V_31 , true , V_52 -> V_54 , V_52 -> V_55 ,
V_52 -> V_6 , V_52 -> V_7 ) ;
F_18 ( & V_48 -> V_45 , V_56 ) ;
}
static void F_19 ( struct V_49 * V_50 ,
const struct V_57 * V_58 )
{
struct V_47 * V_48 = V_50 -> V_53 ;
F_20 ( V_50 , V_58 ) ;
F_1 ( & V_48 -> V_31 , true , V_58 -> V_54 , V_58 -> V_55 ,
V_58 -> V_6 , V_58 -> V_7 ) ;
F_18 ( & V_48 -> V_45 , V_56 ) ;
}
static void F_21 ( struct V_49 * V_50 ,
const struct V_59 * V_60 )
{
struct V_47 * V_48 = V_50 -> V_53 ;
F_22 ( V_50 , V_60 ) ;
F_1 ( & V_48 -> V_31 , true , V_60 -> V_54 , V_60 -> V_55 ,
V_60 -> V_6 , V_60 -> V_7 ) ;
F_18 ( & V_48 -> V_45 , V_56 ) ;
}
static int F_23 ( struct V_11 * V_12 ,
struct V_20 * V_21 )
{
return F_24 ( V_21 , NULL ) ;
}
static int F_25 ( struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_47 * V_48 =
F_15 ( V_62 , struct V_47 , V_62 ) ;
struct V_8 * V_9 = V_62 -> V_9 ;
struct V_11 * V_12 = V_9 -> V_13 ;
struct V_49 * V_50 ;
struct V_65 * V_2 ;
struct V_66 V_67 = {} ;
struct V_20 * V_21 ;
struct V_68 * V_68 = V_12 -> V_9 ;
T_1 V_69 , V_70 , V_71 ;
int V_72 ;
V_67 . V_6 = V_64 -> V_73 ;
V_67 . V_7 = V_64 -> V_74 ;
V_67 . V_29 [ 0 ] = V_67 . V_6 * 4 ;
V_67 . V_75 = F_26 ( 32 , 24 ) ;
switch ( V_67 . V_75 ) {
#ifdef F_27
case V_76 :
V_70 = V_77 ;
break;
case V_78 :
V_70 = V_79 ;
break;
case V_80 :
V_70 = V_81 ;
break;
case V_82 :
V_70 = V_83 ;
break;
case V_84 :
V_70 = V_85 ;
break;
case V_86 :
V_70 = V_87 ;
break;
case V_88 :
V_70 = V_89 ;
break;
case V_90 :
V_70 = V_91 ;
break;
#else
case V_76 :
V_70 = V_81 ;
break;
case V_78 :
V_70 = V_83 ;
break;
case V_80 :
V_70 = V_77 ;
break;
case V_82 :
V_70 = V_79 ;
break;
case V_84 :
V_70 = V_89 ;
break;
case V_86 :
V_70 = V_91 ;
break;
case V_88 :
V_70 = V_85 ;
break;
case V_90 :
V_70 = V_87 ;
break;
#endif
default:
F_28 ( L_2 ,
V_67 . V_75 ) ;
return - V_22 ;
}
V_71 = V_67 . V_29 [ 0 ] * V_67 . V_7 ;
V_21 = F_29 ( V_9 , V_71 , false , true ) ;
if ( F_30 ( V_21 ) )
return F_31 ( V_21 ) ;
F_32 ( V_12 , & V_69 ) ;
F_33 ( V_12 , V_69 , V_70 ,
V_67 . V_6 , V_67 . V_7 ) ;
V_72 = F_23 ( V_12 , V_21 ) ;
if ( V_72 ) {
F_28 ( L_3 , V_72 ) ;
goto V_92;
}
V_72 = F_34 ( V_12 , V_21 , V_69 , NULL ) ;
if ( V_72 )
goto V_93;
V_50 = F_35 ( 0 , V_68 ) ;
if ( ! V_50 ) {
V_72 = - V_94 ;
goto V_95;
}
V_72 = F_36 ( & V_50 -> V_96 , 256 , 0 ) ;
if ( V_72 ) {
V_72 = - V_94 ;
goto V_97;
}
V_50 -> V_53 = V_62 ;
V_72 = F_37 ( V_9 , & V_48 -> V_31 ,
& V_67 , & V_21 -> V_98 ) ;
if ( V_72 )
goto V_99;
V_2 = & V_48 -> V_31 . V_10 ;
V_48 -> V_62 . V_2 = V_2 ;
V_48 -> V_62 . V_100 = V_50 ;
strcpy ( V_50 -> V_101 . V_102 , L_4 ) ;
V_50 -> V_19 = V_103 ;
V_50 -> V_104 = & V_105 ;
V_50 -> V_106 . V_19 = V_107 ;
V_50 -> V_108 = V_21 -> V_109 ;
V_50 -> V_110 = V_21 -> V_98 . V_71 ;
F_38 ( V_50 , V_2 -> V_29 [ 0 ] , V_2 -> V_111 ) ;
F_39 ( V_50 , & V_48 -> V_62 ,
V_64 -> V_112 , V_64 -> V_113 ) ;
V_50 -> V_101 . V_114 = 0 ;
V_50 -> V_101 . V_115 = 0 ;
return 0 ;
V_99:
F_40 ( & V_50 -> V_96 ) ;
V_97:
F_41 ( V_50 ) ;
V_95:
F_42 ( V_12 , V_69 ) ;
V_93:
V_92:
F_43 ( & V_21 -> V_98 ) ;
return V_72 ;
}
static int F_44 ( struct V_8 * V_9 ,
struct V_47 * V_116 )
{
struct V_49 * V_50 ;
struct V_1 * V_31 = & V_116 -> V_31 ;
if ( V_116 -> V_62 . V_100 ) {
V_50 = V_116 -> V_62 . V_100 ;
F_45 ( V_50 ) ;
F_41 ( V_50 ) ;
}
if ( V_31 -> V_21 )
V_31 -> V_21 = NULL ;
F_46 ( & V_116 -> V_62 ) ;
F_47 ( & V_31 -> V_10 ) ;
return 0 ;
}
int F_48 ( struct V_11 * V_12 )
{
struct V_47 * V_116 ;
int V_117 = 32 ;
int V_72 ;
V_116 = F_49 ( sizeof( struct V_47 ) , V_118 ) ;
if ( ! V_116 )
return - V_94 ;
V_116 -> V_12 = V_12 ;
V_12 -> V_116 = V_116 ;
F_50 ( & V_116 -> V_45 , F_13 ) ;
F_51 ( V_12 -> V_119 , & V_116 -> V_62 ,
& V_120 ) ;
V_72 = F_52 ( V_12 -> V_119 , & V_116 -> V_62 ,
V_12 -> V_121 ,
V_122 ) ;
if ( V_72 ) {
F_53 ( V_116 ) ;
return V_72 ;
}
F_54 ( & V_116 -> V_62 ) ;
F_55 ( & V_116 -> V_62 , V_117 ) ;
return 0 ;
}
void F_56 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_116 )
return;
F_44 ( V_12 -> V_119 , V_12 -> V_116 ) ;
F_53 ( V_12 -> V_116 ) ;
V_12 -> V_116 = NULL ;
}
