int
F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 && V_2 -> V_3 ) ) {
struct V_4 * V_5 = ( void * ) V_2 -> V_6 . V_7 ;
struct V_8 * V_3 = NULL ;
int V_9 ;
V_9 = F_3 ( V_2 , false , & V_3 ) ;
if ( ! V_9 ) {
V_9 = F_4 ( V_3 , false , false ) ;
F_5 ( & V_3 ) ;
}
if ( V_9 ) {
F_6 ( V_10 , V_5 , L_1 ,
V_2 -> V_11 , F_7 ( & V_5 -> V_12 ) -> V_13 ) ;
return V_9 ;
}
}
return 0 ;
}
void
F_8 ( struct V_1 * * V_14 )
{
struct V_1 * V_2 = * V_14 ;
if ( V_2 ) {
if ( V_2 -> V_3 )
V_8 ( V_2 -> V_15 ) -> F_9 ( V_2 ) ;
F_10 ( & V_2 -> V_16 ) ;
F_10 ( & V_2 -> V_17 ) ;
F_10 ( & V_2 -> V_18 ) ;
F_10 ( & V_2 -> V_6 ) ;
F_10 ( & V_2 -> V_19 . V_20 ) ;
F_11 ( V_2 -> V_19 . V_21 , & V_2 -> V_19 . V_22 ) ;
F_12 ( V_2 -> V_19 . V_21 ) ;
if ( V_2 -> V_19 . V_21 && V_2 -> V_19 . V_21 -> V_23 )
F_13 ( V_2 -> V_19 . V_21 ) ;
F_14 ( NULL , & V_2 -> V_19 . V_21 ) ;
F_15 ( V_2 ) ;
}
* V_14 = NULL ;
}
static int
F_16 ( struct V_24 * V_15 , struct V_25 * V_26 ,
T_1 V_27 , struct V_1 * * V_14 )
{
struct V_4 * V_5 = ( void * ) V_26 -> V_28 . V_7 ;
struct V_29 * V_30 = F_17 ( V_26 ) ;
struct V_31 args = {} ;
struct V_1 * V_2 ;
T_1 V_32 ;
int V_9 ;
V_2 = * V_14 = F_18 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_15 = V_15 ;
V_32 = V_35 | V_36 ;
if ( V_37 )
V_32 = V_38 ;
V_9 = F_19 ( V_15 -> V_39 , V_27 , 0 , V_32 , 0 , 0 , NULL , NULL ,
& V_2 -> V_19 . V_21 ) ;
if ( V_9 == 0 ) {
V_9 = F_20 ( V_2 -> V_19 . V_21 , V_32 , false ) ;
if ( V_9 == 0 )
V_9 = F_21 ( V_2 -> V_19 . V_21 ) ;
}
if ( V_9 ) {
F_8 ( V_14 ) ;
return V_9 ;
}
V_2 -> V_19 . V_22 . V_40 = V_2 -> V_19 . V_21 -> V_41 . V_40 ;
if ( V_26 -> V_42 . V_43 >= V_44 ) {
V_9 = F_22 ( V_2 -> V_19 . V_21 , V_5 -> V_45 ,
& V_2 -> V_19 . V_22 ) ;
if ( V_9 ) {
F_8 ( V_14 ) ;
return V_9 ;
}
args . V_32 = V_46 ;
args . V_47 = V_48 ;
args . V_49 = 0 ;
args . V_50 = V_5 -> V_45 -> V_30 -> V_50 - 1 ;
} else
if ( V_2 -> V_19 . V_21 -> V_41 . V_51 . V_52 == V_53 ) {
if ( V_26 -> V_42 . V_43 == V_54 ) {
args . V_32 = V_55 ;
args . V_47 = V_56 ;
args . V_49 = F_23 ( V_26 ) -> V_57 ->
V_58 ( F_23 ( V_26 ) , 1 ) ;
args . V_50 = args . V_49 + V_26 -> V_42 . V_59 - 1 ;
} else {
args . V_32 = V_60 ;
args . V_47 = V_56 ;
args . V_49 = 0 ;
args . V_50 = V_26 -> V_42 . V_59 - 1 ;
}
} else {
if ( V_2 -> V_15 -> V_61 . V_62 ) {
args . V_32 = V_63 ;
args . V_47 = V_56 ;
args . V_49 = V_2 -> V_15 -> V_61 . V_12 ;
args . V_50 = V_2 -> V_15 -> V_61 . V_12 +
V_2 -> V_15 -> V_61 . V_27 - 1 ;
} else {
args . V_32 = V_46 ;
args . V_47 = V_56 ;
args . V_49 = 0 ;
args . V_50 = V_30 -> V_50 - 1 ;
}
}
V_9 = F_24 ( & V_26 -> V_28 , 0 , V_64 ,
& args , sizeof( args ) , & V_2 -> V_19 . V_20 ) ;
if ( V_9 ) {
F_8 ( V_14 ) ;
return V_9 ;
}
return 0 ;
}
static int
F_25 ( struct V_24 * V_15 , struct V_25 * V_26 ,
T_1 V_65 , struct V_1 * * V_14 )
{
static const T_2 V_66 [] = { V_67 ,
V_68 ,
V_69 ,
V_70 ,
V_71 ,
V_72 ,
V_73 ,
0 } ;
const T_2 * V_74 = V_66 ;
union {
struct V_75 V_76 ;
struct V_77 V_78 ;
struct V_79 V_80 ;
} args ;
struct V_1 * V_2 ;
T_1 V_27 ;
int V_9 ;
V_9 = F_16 ( V_15 , V_26 , 0x12000 , & V_2 ) ;
* V_14 = V_2 ;
if ( V_9 )
return V_9 ;
do {
if ( V_74 [ 0 ] >= V_70 ) {
args . V_80 . V_81 = 0 ;
args . V_80 . V_82 = V_65 ;
args . V_80 . V_83 = 0x02000 ;
args . V_80 . V_84 = 0x10000 + V_2 -> V_19 . V_22 . V_40 ;
args . V_80 . V_45 = 0 ;
V_27 = sizeof( args . V_80 ) ;
} else
if ( V_74 [ 0 ] >= V_71 ) {
args . V_78 . V_81 = 0 ;
args . V_78 . V_83 = 0x02000 ;
args . V_78 . V_84 = 0x10000 + V_2 -> V_19 . V_22 . V_40 ;
args . V_78 . V_45 = 0 ;
V_27 = sizeof( args . V_78 ) ;
} else {
args . V_76 . V_81 = 0 ;
args . V_76 . V_83 = 0x02000 ;
args . V_76 . V_84 = 0x10000 + V_2 -> V_19 . V_22 . V_40 ;
args . V_76 . V_85 = F_26 ( & V_2 -> V_19 . V_20 ) ;
args . V_76 . V_45 = 0 ;
V_27 = sizeof( args . V_76 ) ;
}
V_9 = F_24 ( & V_26 -> V_28 , 0 , * V_74 ++ ,
& args , V_27 , & V_2 -> V_6 ) ;
if ( V_9 == 0 ) {
if ( V_2 -> V_6 . V_74 >= V_70 )
V_2 -> V_11 = args . V_80 . V_11 ;
else
if ( V_2 -> V_6 . V_74 >= V_71 )
V_2 -> V_11 = args . V_78 . V_11 ;
else
V_2 -> V_11 = args . V_76 . V_11 ;
return V_9 ;
}
} while ( * V_74 );
F_8 ( V_14 ) ;
return V_9 ;
}
static int
F_27 ( struct V_24 * V_15 , struct V_25 * V_26 ,
struct V_1 * * V_14 )
{
static const T_2 V_66 [] = { V_86 ,
V_87 ,
V_88 ,
V_89 ,
0 } ;
const T_2 * V_74 = V_66 ;
struct V_90 args ;
struct V_1 * V_2 ;
int V_9 ;
V_9 = F_16 ( V_15 , V_26 , 0x10000 , & V_2 ) ;
* V_14 = V_2 ;
if ( V_9 )
return V_9 ;
args . V_81 = 0 ;
args . V_85 = F_26 ( & V_2 -> V_19 . V_20 ) ;
args . V_40 = V_2 -> V_19 . V_22 . V_40 ;
do {
V_9 = F_24 ( & V_26 -> V_28 , 0 , * V_74 ++ ,
& args , sizeof( args ) , & V_2 -> V_6 ) ;
if ( V_9 == 0 ) {
V_2 -> V_11 = args . V_11 ;
return V_9 ;
}
} while ( V_9 && * V_74 );
F_8 ( V_14 ) ;
return V_9 ;
}
static int
F_28 ( struct V_1 * V_2 , T_1 V_18 , T_1 V_17 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_4 * V_5 = ( void * ) V_2 -> V_6 . V_7 ;
struct V_29 * V_30 = F_17 ( V_26 ) ;
struct V_31 args = {} ;
int V_9 , V_91 ;
F_29 ( & V_2 -> V_6 ) ;
if ( V_26 -> V_42 . V_43 < V_92 ) {
if ( V_26 -> V_42 . V_43 >= V_44 ) {
args . V_32 = V_46 ;
args . V_47 = V_48 ;
args . V_49 = 0 ;
args . V_50 = V_5 -> V_45 -> V_30 -> V_50 - 1 ;
} else {
args . V_32 = V_60 ;
args . V_47 = V_56 ;
args . V_49 = 0 ;
args . V_50 = V_26 -> V_42 . V_59 - 1 ;
}
V_9 = F_24 ( & V_2 -> V_6 , V_18 , V_93 ,
& args , sizeof( args ) , & V_2 -> V_18 ) ;
if ( V_9 )
return V_9 ;
if ( V_26 -> V_42 . V_43 >= V_44 ) {
args . V_32 = V_46 ;
args . V_47 = V_48 ;
args . V_49 = 0 ;
args . V_50 = V_5 -> V_45 -> V_30 -> V_50 - 1 ;
} else
if ( V_2 -> V_15 -> V_61 . V_62 ) {
args . V_32 = V_63 ;
args . V_47 = V_56 ;
args . V_49 = V_2 -> V_15 -> V_61 . V_12 ;
args . V_50 = V_2 -> V_15 -> V_61 . V_12 +
V_2 -> V_15 -> V_61 . V_27 - 1 ;
} else {
args . V_32 = V_46 ;
args . V_47 = V_56 ;
args . V_49 = 0 ;
args . V_50 = V_30 -> V_50 - 1 ;
}
V_9 = F_24 ( & V_2 -> V_6 , V_17 , V_93 ,
& args , sizeof( args ) , & V_2 -> V_17 ) ;
if ( V_9 )
return V_9 ;
}
switch ( V_2 -> V_6 . V_74 & 0x00ff ) {
case 0x006b :
case 0x006e :
V_2 -> V_94 = 0x40 ;
V_2 -> V_95 = 0x44 ;
V_2 -> V_96 . V_97 = ( 0x10000 / 4 ) - 2 ;
break;
default:
V_2 -> V_94 = 0x40 ;
V_2 -> V_95 = 0x44 ;
V_2 -> V_98 = 0x60 ;
V_2 -> V_96 . V_99 = 0x10000 / 4 ;
V_2 -> V_96 . V_100 = ( 0x02000 / 8 ) - 1 ;
V_2 -> V_96 . V_101 = 0 ;
V_2 -> V_96 . V_102 = V_2 -> V_96 . V_100 - V_2 -> V_96 . V_101 ;
V_2 -> V_96 . V_97 = V_2 -> V_96 . V_99 ;
break;
}
V_2 -> V_96 . V_103 = 0 ;
V_2 -> V_96 . V_104 = V_2 -> V_96 . V_103 ;
V_2 -> V_96 . free = V_2 -> V_96 . V_97 - V_2 -> V_96 . V_104 ;
V_9 = F_30 ( V_2 , V_105 ) ;
if ( V_9 )
return V_9 ;
for ( V_91 = 0 ; V_91 < V_105 ; V_91 ++ )
F_31 ( V_2 , 0x00000000 ) ;
if ( V_26 -> V_42 . V_43 < V_106 ) {
V_9 = F_24 ( & V_2 -> V_6 , 0x006e ,
V_107 ,
NULL , 0 , & V_2 -> V_16 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_30 ( V_2 , 2 ) ;
if ( V_9 )
return V_9 ;
F_32 ( V_2 , V_108 , 0x0000 , 1 ) ;
F_31 ( V_2 , V_2 -> V_16 . V_109 ) ;
F_33 ( V_2 ) ;
}
return V_8 ( V_2 -> V_15 ) -> F_34 ( V_2 ) ;
}
int
F_35 ( struct V_24 * V_15 , struct V_25 * V_26 ,
T_1 V_110 , T_1 V_111 , struct V_1 * * V_14 )
{
struct V_4 * V_5 = ( void * ) V_26 -> V_28 . V_7 ;
bool V_112 ;
int V_9 ;
V_112 = V_5 -> V_12 . V_112 ;
V_5 -> V_12 . V_112 = true ;
V_9 = F_25 ( V_15 , V_26 , V_110 , V_14 ) ;
if ( V_9 ) {
F_6 ( V_113 , V_5 , L_2 , V_9 ) ;
V_9 = F_27 ( V_15 , V_26 , V_14 ) ;
if ( V_9 ) {
F_6 ( V_113 , V_5 , L_3 , V_9 ) ;
goto V_114;
}
}
V_9 = F_28 ( * V_14 , V_110 , V_111 ) ;
if ( V_9 ) {
F_6 ( V_10 , V_5 , L_4 , V_9 ) ;
F_8 ( V_14 ) ;
}
V_114:
V_5 -> V_12 . V_112 = V_112 ;
return V_9 ;
}
