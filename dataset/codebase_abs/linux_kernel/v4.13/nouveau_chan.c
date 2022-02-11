static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , F_3 ( * V_4 ) , V_5 ) ;
struct V_6 * V_7 = ( void * ) V_4 -> V_8 . V_9 ;
F_4 ( V_10 , V_7 , L_1 , V_4 -> V_11 ) ;
F_5 ( & V_4 -> V_12 , 1 ) ;
return V_13 ;
}
int
F_6 ( struct V_3 * V_4 )
{
if ( F_7 ( V_4 && V_4 -> V_14 && ! F_8 ( & V_4 -> V_12 ) ) ) {
struct V_6 * V_7 = ( void * ) V_4 -> V_8 . V_9 ;
struct V_15 * V_14 = NULL ;
int V_16 ;
V_16 = F_9 ( V_4 , false , & V_14 ) ;
if ( ! V_16 ) {
V_16 = F_10 ( V_14 , false , false ) ;
F_11 ( & V_14 ) ;
}
if ( V_16 ) {
F_4 ( V_17 , V_7 , L_2 ,
V_4 -> V_11 , F_12 ( & V_7 -> V_18 ) -> V_19 ) ;
return V_16 ;
}
}
return 0 ;
}
void
F_13 ( struct V_3 * * V_20 )
{
struct V_3 * V_4 = * V_20 ;
if ( V_4 ) {
if ( V_4 -> V_14 )
V_15 ( V_4 -> V_21 ) -> F_14 ( V_4 ) ;
F_15 ( & V_4 -> V_22 ) ;
F_15 ( & V_4 -> V_23 ) ;
F_15 ( & V_4 -> V_24 ) ;
F_16 ( & V_4 -> V_5 ) ;
F_15 ( & V_4 -> V_8 ) ;
F_15 ( & V_4 -> V_25 . V_26 ) ;
F_17 ( V_4 -> V_25 . V_27 , & V_4 -> V_25 . V_28 ) ;
F_18 ( V_4 -> V_25 . V_27 ) ;
if ( V_4 -> V_25 . V_27 && V_4 -> V_25 . V_27 -> V_29 )
F_19 ( V_4 -> V_25 . V_27 ) ;
F_20 ( NULL , & V_4 -> V_25 . V_27 ) ;
F_21 ( V_4 ) ;
}
* V_20 = NULL ;
}
static int
F_22 ( struct V_30 * V_21 , struct V_31 * V_32 ,
T_1 V_33 , struct V_3 * * V_20 )
{
struct V_6 * V_7 = ( void * ) V_32 -> V_34 . V_9 ;
struct V_35 * V_36 = F_23 ( V_32 ) ;
struct V_37 args = {} ;
struct V_3 * V_4 ;
T_1 V_38 ;
int V_16 ;
V_4 = * V_20 = F_24 ( sizeof( * V_4 ) , V_39 ) ;
if ( ! V_4 )
return - V_40 ;
V_4 -> V_32 = V_32 ;
V_4 -> V_21 = V_21 ;
F_5 ( & V_4 -> V_12 , 0 ) ;
V_38 = V_41 | V_42 ;
if ( V_43 )
V_38 = V_44 ;
V_16 = F_25 ( V_7 , V_33 , 0 , V_38 , 0 , 0 , NULL , NULL ,
& V_4 -> V_25 . V_27 ) ;
if ( V_16 == 0 ) {
V_16 = F_26 ( V_4 -> V_25 . V_27 , V_38 , false ) ;
if ( V_16 == 0 )
V_16 = F_27 ( V_4 -> V_25 . V_27 ) ;
}
if ( V_16 ) {
F_13 ( V_20 ) ;
return V_16 ;
}
V_4 -> V_25 . V_28 . V_45 = V_4 -> V_25 . V_27 -> V_46 . V_45 ;
if ( V_32 -> V_47 . V_48 >= V_49 ) {
V_16 = F_28 ( V_4 -> V_25 . V_27 , V_7 -> V_50 ,
& V_4 -> V_25 . V_28 ) ;
if ( V_16 ) {
F_13 ( V_20 ) ;
return V_16 ;
}
args . V_38 = V_51 ;
args . V_52 = V_53 ;
args . V_54 = 0 ;
args . V_55 = V_7 -> V_50 -> V_36 -> V_55 - 1 ;
} else
if ( V_4 -> V_25 . V_27 -> V_46 . V_56 . V_57 == V_58 ) {
if ( V_32 -> V_47 . V_48 == V_59 ) {
args . V_38 = V_60 ;
args . V_52 = V_61 ;
args . V_54 = F_29 ( V_32 ) -> V_62 ->
V_63 ( F_29 ( V_32 ) , 1 ) ;
args . V_55 = args . V_54 + V_32 -> V_47 . V_64 - 1 ;
} else {
args . V_38 = V_65 ;
args . V_52 = V_61 ;
args . V_54 = 0 ;
args . V_55 = V_32 -> V_47 . V_64 - 1 ;
}
} else {
if ( V_4 -> V_21 -> V_66 . V_67 ) {
args . V_38 = V_68 ;
args . V_52 = V_61 ;
args . V_54 = V_4 -> V_21 -> V_66 . V_18 ;
args . V_55 = V_4 -> V_21 -> V_66 . V_18 +
V_4 -> V_21 -> V_66 . V_33 - 1 ;
} else {
args . V_38 = V_51 ;
args . V_52 = V_61 ;
args . V_54 = 0 ;
args . V_55 = V_36 -> V_55 - 1 ;
}
}
V_16 = F_30 ( & V_32 -> V_34 , 0 , V_69 ,
& args , sizeof( args ) , & V_4 -> V_25 . V_26 ) ;
if ( V_16 ) {
F_13 ( V_20 ) ;
return V_16 ;
}
return 0 ;
}
static int
F_31 ( struct V_30 * V_21 , struct V_31 * V_32 ,
T_1 V_70 , struct V_3 * * V_20 )
{
static const T_2 V_71 [] = { V_72 ,
V_73 ,
V_74 ,
V_75 ,
V_76 ,
V_77 ,
V_78 ,
0 } ;
const T_2 * V_79 = V_71 ;
union {
struct V_80 V_81 ;
struct V_82 V_83 ;
struct V_84 V_85 ;
} args ;
struct V_3 * V_4 ;
T_1 V_33 ;
int V_16 ;
V_16 = F_22 ( V_21 , V_32 , 0x12000 , & V_4 ) ;
* V_20 = V_4 ;
if ( V_16 )
return V_16 ;
do {
if ( V_79 [ 0 ] >= V_75 ) {
args . V_85 . V_86 = 0 ;
args . V_85 . V_87 = V_70 ;
args . V_85 . V_88 = 0x02000 ;
args . V_85 . V_89 = 0x10000 + V_4 -> V_25 . V_28 . V_45 ;
args . V_85 . V_50 = 0 ;
V_33 = sizeof( args . V_85 ) ;
} else
if ( V_79 [ 0 ] >= V_76 ) {
args . V_83 . V_86 = 0 ;
args . V_83 . V_88 = 0x02000 ;
args . V_83 . V_89 = 0x10000 + V_4 -> V_25 . V_28 . V_45 ;
args . V_83 . V_50 = 0 ;
V_33 = sizeof( args . V_83 ) ;
} else {
args . V_81 . V_86 = 0 ;
args . V_81 . V_88 = 0x02000 ;
args . V_81 . V_89 = 0x10000 + V_4 -> V_25 . V_28 . V_45 ;
args . V_81 . V_90 = F_32 ( & V_4 -> V_25 . V_26 ) ;
args . V_81 . V_50 = 0 ;
V_33 = sizeof( args . V_81 ) ;
}
V_16 = F_30 ( & V_32 -> V_34 , 0 , * V_79 ++ ,
& args , V_33 , & V_4 -> V_8 ) ;
if ( V_16 == 0 ) {
if ( V_4 -> V_8 . V_79 >= V_75 )
V_4 -> V_11 = args . V_85 . V_11 ;
else
if ( V_4 -> V_8 . V_79 >= V_76 )
V_4 -> V_11 = args . V_83 . V_11 ;
else
V_4 -> V_11 = args . V_81 . V_11 ;
return V_16 ;
}
} while ( * V_79 );
F_13 ( V_20 ) ;
return V_16 ;
}
static int
F_33 ( struct V_30 * V_21 , struct V_31 * V_32 ,
struct V_3 * * V_20 )
{
static const T_2 V_71 [] = { V_91 ,
V_92 ,
V_93 ,
V_94 ,
0 } ;
const T_2 * V_79 = V_71 ;
struct V_95 args ;
struct V_3 * V_4 ;
int V_16 ;
V_16 = F_22 ( V_21 , V_32 , 0x10000 , & V_4 ) ;
* V_20 = V_4 ;
if ( V_16 )
return V_16 ;
args . V_86 = 0 ;
args . V_90 = F_32 ( & V_4 -> V_25 . V_26 ) ;
args . V_45 = V_4 -> V_25 . V_28 . V_45 ;
do {
V_16 = F_30 ( & V_32 -> V_34 , 0 , * V_79 ++ ,
& args , sizeof( args ) , & V_4 -> V_8 ) ;
if ( V_16 == 0 ) {
V_4 -> V_11 = args . V_11 ;
return V_16 ;
}
} while ( V_16 && * V_79 );
F_13 ( V_20 ) ;
return V_16 ;
}
static int
F_34 ( struct V_3 * V_4 , T_1 V_24 , T_1 V_23 )
{
struct V_31 * V_32 = V_4 -> V_32 ;
struct V_6 * V_7 = ( void * ) V_4 -> V_8 . V_9 ;
struct V_30 * V_21 = V_4 -> V_21 ;
struct V_35 * V_36 = F_23 ( V_32 ) ;
struct V_37 args = {} ;
int V_16 , V_96 ;
F_35 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_8 . V_79 >= V_76 ) {
V_16 = F_36 ( & V_4 -> V_8 , F_1 ,
true , V_97 ,
NULL , 0 , 0 , & V_4 -> V_5 ) ;
if ( V_16 == 0 )
V_16 = F_37 ( & V_4 -> V_5 ) ;
if ( V_16 ) {
F_38 ( V_21 , L_3
L_4 , V_16 ) ;
return V_16 ;
}
}
if ( V_32 -> V_47 . V_48 < V_98 ) {
if ( V_32 -> V_47 . V_48 >= V_49 ) {
args . V_38 = V_51 ;
args . V_52 = V_53 ;
args . V_54 = 0 ;
args . V_55 = V_7 -> V_50 -> V_36 -> V_55 - 1 ;
} else {
args . V_38 = V_65 ;
args . V_52 = V_61 ;
args . V_54 = 0 ;
args . V_55 = V_32 -> V_47 . V_64 - 1 ;
}
V_16 = F_30 ( & V_4 -> V_8 , V_24 , V_99 ,
& args , sizeof( args ) , & V_4 -> V_24 ) ;
if ( V_16 )
return V_16 ;
if ( V_32 -> V_47 . V_48 >= V_49 ) {
args . V_38 = V_51 ;
args . V_52 = V_53 ;
args . V_54 = 0 ;
args . V_55 = V_7 -> V_50 -> V_36 -> V_55 - 1 ;
} else
if ( V_4 -> V_21 -> V_66 . V_67 ) {
args . V_38 = V_68 ;
args . V_52 = V_61 ;
args . V_54 = V_4 -> V_21 -> V_66 . V_18 ;
args . V_55 = V_4 -> V_21 -> V_66 . V_18 +
V_4 -> V_21 -> V_66 . V_33 - 1 ;
} else {
args . V_38 = V_51 ;
args . V_52 = V_61 ;
args . V_54 = 0 ;
args . V_55 = V_36 -> V_55 - 1 ;
}
V_16 = F_30 ( & V_4 -> V_8 , V_23 , V_99 ,
& args , sizeof( args ) , & V_4 -> V_23 ) ;
if ( V_16 )
return V_16 ;
}
switch ( V_4 -> V_8 . V_79 & 0x00ff ) {
case 0x006b :
case 0x006e :
V_4 -> V_100 = 0x40 ;
V_4 -> V_101 = 0x44 ;
V_4 -> V_102 . V_103 = ( 0x10000 / 4 ) - 2 ;
break;
default:
V_4 -> V_100 = 0x40 ;
V_4 -> V_101 = 0x44 ;
V_4 -> V_104 = 0x60 ;
V_4 -> V_102 . V_105 = 0x10000 / 4 ;
V_4 -> V_102 . V_106 = ( 0x02000 / 8 ) - 1 ;
V_4 -> V_102 . V_107 = 0 ;
V_4 -> V_102 . V_108 = V_4 -> V_102 . V_106 - V_4 -> V_102 . V_107 ;
V_4 -> V_102 . V_103 = V_4 -> V_102 . V_105 ;
break;
}
V_4 -> V_102 . V_109 = 0 ;
V_4 -> V_102 . V_110 = V_4 -> V_102 . V_109 ;
V_4 -> V_102 . free = V_4 -> V_102 . V_103 - V_4 -> V_102 . V_110 ;
V_16 = F_39 ( V_4 , V_111 ) ;
if ( V_16 )
return V_16 ;
for ( V_96 = 0 ; V_96 < V_111 ; V_96 ++ )
F_40 ( V_4 , 0x00000000 ) ;
if ( V_32 -> V_47 . V_48 < V_112 ) {
V_16 = F_30 ( & V_4 -> V_8 , 0x006e ,
V_113 ,
NULL , 0 , & V_4 -> V_22 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_39 ( V_4 , 2 ) ;
if ( V_16 )
return V_16 ;
F_41 ( V_4 , V_114 , 0x0000 , 1 ) ;
F_40 ( V_4 , V_4 -> V_22 . V_115 ) ;
F_42 ( V_4 ) ;
}
return V_15 ( V_4 -> V_21 ) -> F_43 ( V_4 ) ;
}
int
F_44 ( struct V_30 * V_21 , struct V_31 * V_32 ,
T_1 V_116 , T_1 V_117 , struct V_3 * * V_20 )
{
struct V_6 * V_7 = ( void * ) V_32 -> V_34 . V_9 ;
bool V_118 ;
int V_16 ;
V_118 = V_7 -> V_18 . V_118 ;
V_7 -> V_18 . V_118 = true ;
V_16 = F_31 ( V_21 , V_32 , V_116 , V_20 ) ;
if ( V_16 ) {
F_4 ( V_119 , V_7 , L_5 , V_16 ) ;
V_16 = F_33 ( V_21 , V_32 , V_20 ) ;
if ( V_16 ) {
F_4 ( V_119 , V_7 , L_6 , V_16 ) ;
goto V_120;
}
}
V_16 = F_34 ( * V_20 , V_116 , V_117 ) ;
if ( V_16 ) {
F_4 ( V_17 , V_7 , L_7 , V_16 ) ;
F_13 ( V_20 ) ;
}
V_120:
V_7 -> V_18 . V_118 = V_118 ;
return V_16 ;
}
