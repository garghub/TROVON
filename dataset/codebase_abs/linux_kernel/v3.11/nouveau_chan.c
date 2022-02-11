int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = NULL ;
int V_7 ;
V_7 = F_2 ( V_2 , false , & V_6 ) ;
if ( ! V_7 ) {
V_7 = F_3 ( V_6 , false , false ) ;
F_4 ( & V_6 ) ;
}
if ( V_7 )
F_5 ( V_4 , L_1 ,
V_2 -> V_8 , V_4 -> V_9 . V_10 ) ;
return V_7 ;
}
void
F_6 ( struct V_1 * * V_11 )
{
struct V_1 * V_2 = * V_11 ;
if ( V_2 ) {
struct V_12 * V_13 = F_7 ( V_2 -> V_4 ) ;
if ( V_2 -> V_6 ) {
F_1 ( V_2 ) ;
V_5 ( V_2 -> V_14 ) -> F_8 ( V_2 ) ;
}
F_9 ( V_13 , V_15 , V_2 -> V_8 ) ;
F_9 ( V_13 , V_15 , V_2 -> V_16 . V_8 ) ;
F_10 ( V_2 -> V_16 . V_17 , & V_2 -> V_16 . V_18 ) ;
F_11 ( V_2 -> V_16 . V_17 ) ;
if ( V_2 -> V_16 . V_17 && V_2 -> V_16 . V_17 -> V_19 )
F_12 ( V_2 -> V_16 . V_17 ) ;
F_13 ( NULL , & V_2 -> V_16 . V_17 ) ;
F_14 ( V_2 ) ;
}
* V_11 = NULL ;
}
static int
F_15 ( struct V_20 * V_14 , struct V_3 * V_4 ,
T_1 V_21 , T_1 V_8 , T_1 V_22 ,
struct V_1 * * V_11 )
{
struct V_23 * V_24 = F_16 ( V_14 -> V_24 ) ;
struct V_25 * V_26 = V_25 ( V_24 ) ;
struct V_27 * V_28 = V_27 ( V_24 ) ;
struct V_29 * V_30 = V_29 ( V_24 ) ;
struct V_31 * V_13 = & V_4 -> V_9 ;
struct V_32 args = {} ;
struct V_1 * V_2 ;
struct V_12 * V_16 ;
T_1 V_33 ;
int V_7 ;
V_2 = * V_11 = F_17 ( sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 )
return - V_35 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_8 = V_8 ;
V_33 = V_36 ;
if ( V_37 )
V_33 = V_38 ;
V_7 = F_18 ( V_14 -> V_39 , V_22 , 0 , V_33 , 0 , 0 , NULL ,
& V_2 -> V_16 . V_17 ) ;
if ( V_7 == 0 ) {
V_7 = F_19 ( V_2 -> V_16 . V_17 , V_33 ) ;
if ( V_7 == 0 )
V_7 = F_20 ( V_2 -> V_16 . V_17 ) ;
}
if ( V_7 ) {
F_6 ( V_11 ) ;
return V_7 ;
}
V_2 -> V_16 . V_18 . V_40 = V_2 -> V_16 . V_17 -> V_41 . V_40 ;
V_2 -> V_16 . V_8 = V_42 | ( V_8 & 0xffff ) ;
if ( V_24 -> V_43 >= V_44 ) {
V_7 = F_21 ( V_2 -> V_16 . V_17 , V_13 -> V_45 ,
& V_2 -> V_16 . V_18 ) ;
if ( V_7 ) {
F_6 ( V_11 ) ;
return V_7 ;
}
args . V_46 = V_47 | V_48 ;
args . V_49 = 0 ;
args . V_50 = V_13 -> V_45 -> V_28 -> V_50 - 1 ;
} else
if ( V_2 -> V_16 . V_17 -> V_41 . V_51 . V_52 == V_53 ) {
T_2 V_50 = V_30 -> V_54 -> V_22 - V_26 -> V_55 - 1 ;
if ( V_24 -> V_43 == V_56 ) {
args . V_46 = V_57 | V_58 ;
args . V_49 = F_22 ( V_24 -> V_59 , 1 ) ;
args . V_50 = args . V_49 + V_50 ;
} else {
args . V_46 = V_60 | V_58 ;
args . V_49 = 0 ;
args . V_50 = V_50 ;
}
} else {
if ( V_2 -> V_14 -> V_61 . V_62 == V_63 ) {
args . V_46 = V_64 | V_58 ;
args . V_49 = V_2 -> V_14 -> V_61 . V_9 ;
args . V_50 = V_2 -> V_14 -> V_61 . V_9 +
V_2 -> V_14 -> V_61 . V_22 - 1 ;
} else {
args . V_46 = V_47 | V_58 ;
args . V_49 = 0 ;
args . V_50 = V_28 -> V_50 - 1 ;
}
}
V_7 = F_23 ( F_7 ( V_2 -> V_4 ) , V_21 ,
V_2 -> V_16 . V_8 , 0x0002 ,
& args , sizeof( args ) , & V_16 ) ;
if ( V_7 ) {
F_6 ( V_11 ) ;
return V_7 ;
}
return 0 ;
}
static int
F_24 ( struct V_20 * V_14 , struct V_3 * V_4 ,
T_1 V_21 , T_1 V_8 , T_1 V_65 ,
struct V_1 * * V_11 )
{
static const T_3 V_66 [] = { V_67 ,
V_68 ,
V_69 ,
V_70 ,
0 } ;
const T_3 * V_71 = V_66 ;
struct V_72 args ;
struct V_1 * V_2 ;
int V_7 ;
V_7 = F_15 ( V_14 , V_4 , V_21 , V_8 , 0x12000 , & V_2 ) ;
* V_11 = V_2 ;
if ( V_7 )
return V_7 ;
args . V_73 = V_2 -> V_16 . V_8 ;
args . V_74 = 0x10000 + V_2 -> V_16 . V_18 . V_40 ;
args . V_75 = 0x02000 ;
args . V_65 = V_65 ;
do {
V_7 = F_23 ( F_7 ( V_4 ) , V_21 , V_8 ,
* V_71 ++ , & args , sizeof( args ) ,
& V_2 -> V_76 ) ;
if ( V_7 == 0 )
return V_7 ;
} while ( * V_71 );
F_6 ( V_11 ) ;
return V_7 ;
}
static int
F_25 ( struct V_20 * V_14 , struct V_3 * V_4 ,
T_1 V_21 , T_1 V_8 , struct V_1 * * V_11 )
{
static const T_3 V_66 [] = { V_77 ,
V_78 ,
V_79 ,
V_80 ,
0 } ;
const T_3 * V_71 = V_66 ;
struct V_81 args ;
struct V_1 * V_2 ;
int V_7 ;
V_7 = F_15 ( V_14 , V_4 , V_21 , V_8 , 0x10000 , & V_2 ) ;
* V_11 = V_2 ;
if ( V_7 )
return V_7 ;
args . V_73 = V_2 -> V_16 . V_8 ;
args . V_40 = V_2 -> V_16 . V_18 . V_40 ;
do {
V_7 = F_23 ( F_7 ( V_4 ) , V_21 , V_8 ,
* V_71 ++ , & args , sizeof( args ) ,
& V_2 -> V_76 ) ;
if ( V_7 == 0 )
return V_7 ;
} while ( V_7 && * V_71 );
F_6 ( V_11 ) ;
return V_7 ;
}
static int
F_26 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_83 )
{
struct V_31 * V_13 = F_27 ( V_2 -> V_4 ) ;
struct V_23 * V_24 = F_16 ( V_2 -> V_14 -> V_24 ) ;
struct V_25 * V_26 = V_25 ( V_24 ) ;
struct V_27 * V_28 = V_27 ( V_24 ) ;
struct V_29 * V_30 = V_29 ( V_24 ) ;
struct V_84 * V_85 ;
struct V_12 * V_76 ;
struct V_32 args = {} ;
int V_7 , V_86 ;
if ( V_24 -> V_43 < V_87 ) {
if ( V_24 -> V_43 >= V_44 ) {
args . V_46 = V_47 | V_48 ;
args . V_49 = 0 ;
args . V_50 = V_13 -> V_45 -> V_28 -> V_50 - 1 ;
} else {
args . V_46 = V_60 | V_58 ;
args . V_49 = 0 ;
args . V_50 = V_30 -> V_54 -> V_22 - V_26 -> V_55 - 1 ;
}
V_7 = F_23 ( F_7 ( V_13 ) , V_2 -> V_8 , V_82 ,
0x003d , & args , sizeof( args ) , & V_76 ) ;
if ( V_7 )
return V_7 ;
if ( V_24 -> V_43 >= V_44 ) {
args . V_46 = V_47 | V_48 ;
args . V_49 = 0 ;
args . V_50 = V_13 -> V_45 -> V_28 -> V_50 - 1 ;
} else
if ( V_2 -> V_14 -> V_61 . V_62 == V_63 ) {
args . V_46 = V_64 | V_58 ;
args . V_49 = V_2 -> V_14 -> V_61 . V_9 ;
args . V_50 = V_2 -> V_14 -> V_61 . V_9 +
V_2 -> V_14 -> V_61 . V_22 - 1 ;
} else {
args . V_46 = V_47 | V_58 ;
args . V_49 = 0 ;
args . V_50 = V_28 -> V_50 - 1 ;
}
V_7 = F_23 ( F_7 ( V_13 ) , V_2 -> V_8 , V_83 ,
0x003d , & args , sizeof( args ) , & V_76 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_82 = V_82 ;
V_2 -> V_83 = V_83 ;
}
switch ( F_28 ( V_2 -> V_76 ) & 0x00ff ) {
case 0x006b :
case 0x006e :
V_2 -> V_88 = 0x40 ;
V_2 -> V_89 = 0x44 ;
V_2 -> V_90 . V_91 = ( 0x10000 / 4 ) - 2 ;
break;
default:
V_2 -> V_88 = 0x40 ;
V_2 -> V_89 = 0x44 ;
V_2 -> V_92 = 0x60 ;
V_2 -> V_90 . V_93 = 0x10000 / 4 ;
V_2 -> V_90 . V_94 = ( 0x02000 / 8 ) - 1 ;
V_2 -> V_90 . V_95 = 0 ;
V_2 -> V_90 . V_96 = V_2 -> V_90 . V_94 - V_2 -> V_90 . V_95 ;
V_2 -> V_90 . V_91 = V_2 -> V_90 . V_93 ;
break;
}
V_2 -> V_90 . V_97 = 0 ;
V_2 -> V_90 . V_98 = V_2 -> V_90 . V_97 ;
V_2 -> V_90 . free = V_2 -> V_90 . V_91 - V_2 -> V_90 . V_98 ;
V_7 = F_29 ( V_2 , V_99 ) ;
if ( V_7 )
return V_7 ;
for ( V_86 = 0 ; V_86 < V_99 ; V_86 ++ )
F_30 ( V_2 , 0x00000000 ) ;
if ( ( V_24 -> V_43 < V_100 ) || V_83 ) {
V_7 = F_23 ( F_7 ( V_13 ) , V_2 -> V_8 ,
V_101 , F_31 ( V_2 -> V_14 ) ,
NULL , 0 , & V_76 ) ;
if ( V_7 )
return V_7 ;
V_85 = ( void * ) V_76 -> V_21 ;
V_85 -> V_102 = V_103 ;
V_85 -> V_104 = V_2 ;
}
if ( V_24 -> V_43 < V_87 ) {
V_7 = F_29 ( V_2 , 2 ) ;
if ( V_7 )
return V_7 ;
F_32 ( V_2 , V_105 , 0x0000 , 1 ) ;
F_30 ( V_2 , V_101 ) ;
F_33 ( V_2 ) ;
}
return V_5 ( V_2 -> V_14 ) -> F_34 ( V_2 ) ;
}
int
F_35 ( struct V_20 * V_14 , struct V_3 * V_4 ,
T_1 V_21 , T_1 V_8 , T_1 V_106 , T_1 V_107 ,
struct V_1 * * V_11 )
{
int V_7 ;
V_7 = F_24 ( V_14 , V_4 , V_21 , V_8 , V_106 , V_11 ) ;
if ( V_7 ) {
F_36 ( V_4 , L_2 , V_7 ) ;
V_7 = F_25 ( V_14 , V_4 , V_21 , V_8 , V_11 ) ;
if ( V_7 ) {
F_36 ( V_4 , L_3 , V_7 ) ;
return V_7 ;
}
}
V_7 = F_26 ( * V_11 , V_106 , V_107 ) ;
if ( V_7 ) {
F_5 ( V_4 , L_4 , V_7 ) ;
F_6 ( V_11 ) ;
return V_7 ;
}
return 0 ;
}
