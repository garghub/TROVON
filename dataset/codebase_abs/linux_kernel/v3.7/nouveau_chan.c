int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = NULL ;
int V_7 ;
V_7 = F_2 ( V_2 , & V_6 ) ;
if ( ! V_7 ) {
V_7 = F_3 ( V_6 , false , false ) ;
F_4 ( & V_6 ) ;
}
if ( V_7 )
F_5 ( V_4 , L_1 , V_2 -> V_8 ) ;
return V_7 ;
}
void
F_6 ( struct V_1 * * V_9 )
{
struct V_1 * V_2 = * V_9 ;
if ( V_2 ) {
struct V_10 * V_11 = F_7 ( V_2 -> V_4 ) ;
if ( V_2 -> V_6 ) {
F_1 ( V_2 ) ;
V_5 ( V_2 -> V_12 ) -> F_8 ( V_2 ) ;
}
F_9 ( V_11 , V_13 , V_2 -> V_8 ) ;
F_9 ( V_11 , V_13 , V_2 -> V_14 . V_8 ) ;
F_10 ( V_2 -> V_14 . V_15 , & V_2 -> V_14 . V_16 ) ;
F_11 ( V_2 -> V_14 . V_15 ) ;
F_12 ( NULL , & V_2 -> V_14 . V_15 ) ;
F_13 ( V_2 ) ;
}
* V_9 = NULL ;
}
static int
F_14 ( struct V_17 * V_12 , struct V_3 * V_4 ,
T_1 V_18 , T_1 V_8 , T_1 V_19 ,
struct V_1 * * V_9 )
{
struct V_20 * V_21 = F_15 ( V_12 -> V_21 ) ;
struct V_22 * V_23 = V_22 ( V_21 ) ;
struct V_24 * V_25 = V_24 ( V_21 ) ;
struct V_26 * V_27 = V_26 ( V_21 ) ;
struct V_28 * V_11 = & V_4 -> V_29 ;
struct V_30 args = {} ;
struct V_1 * V_2 ;
struct V_10 * V_14 ;
T_1 V_31 ;
int V_7 ;
V_2 = * V_9 = F_16 ( sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 )
return - V_33 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_8 = V_8 ;
V_31 = V_34 ;
if ( V_35 )
V_31 = V_36 ;
V_7 = F_17 ( V_12 -> V_37 , V_19 , 0 , V_31 , 0 , 0 , NULL ,
& V_2 -> V_14 . V_15 ) ;
if ( V_7 == 0 ) {
V_7 = F_18 ( V_2 -> V_14 . V_15 , V_31 ) ;
if ( V_7 == 0 )
V_7 = F_19 ( V_2 -> V_14 . V_15 ) ;
}
if ( V_7 ) {
F_6 ( V_9 ) ;
return V_7 ;
}
V_2 -> V_14 . V_16 . V_38 = V_2 -> V_14 . V_15 -> V_39 . V_38 ;
V_2 -> V_14 . V_8 = V_40 | ( V_8 & 0xffff ) ;
if ( V_21 -> V_41 >= V_42 ) {
V_7 = F_20 ( V_2 -> V_14 . V_15 , V_11 -> V_43 ,
& V_2 -> V_14 . V_16 ) ;
if ( V_7 ) {
F_6 ( V_9 ) ;
return V_7 ;
}
args . V_44 = V_45 | V_46 ;
args . V_47 = 0 ;
args . V_48 = V_11 -> V_43 -> V_25 -> V_48 - 1 ;
} else
if ( V_2 -> V_14 . V_15 -> V_39 . V_49 . V_50 == V_51 ) {
T_2 V_48 = V_27 -> V_52 . V_19 - V_23 -> V_53 - 1 ;
if ( V_21 -> V_41 == V_54 ) {
args . V_44 = V_55 | V_56 ;
args . V_47 = F_21 ( V_21 -> V_57 , 1 ) ;
args . V_48 = args . V_47 + V_48 ;
} else {
args . V_44 = V_58 | V_56 ;
args . V_47 = 0 ;
args . V_48 = V_48 ;
}
} else {
if ( V_2 -> V_12 -> V_59 . V_60 == V_61 ) {
args . V_44 = V_62 | V_56 ;
args . V_47 = V_2 -> V_12 -> V_59 . V_29 ;
args . V_48 = V_2 -> V_12 -> V_59 . V_29 +
V_2 -> V_12 -> V_59 . V_19 - 1 ;
} else {
args . V_44 = V_45 | V_56 ;
args . V_47 = 0 ;
args . V_48 = V_25 -> V_48 - 1 ;
}
}
V_7 = F_22 ( F_7 ( V_2 -> V_4 ) , V_18 ,
V_2 -> V_14 . V_8 , 0x0002 ,
& args , sizeof( args ) , & V_14 ) ;
if ( V_7 ) {
F_6 ( V_9 ) ;
return V_7 ;
}
return 0 ;
}
static int
F_23 ( struct V_17 * V_12 , struct V_3 * V_4 ,
T_1 V_18 , T_1 V_8 , T_1 V_63 ,
struct V_1 * * V_9 )
{
static const T_3 V_64 [] = { V_65 ,
V_66 ,
V_67 ,
V_68 ,
0 } ;
const T_3 * V_69 = V_64 ;
struct V_70 args ;
struct V_1 * V_2 ;
int V_7 ;
V_7 = F_14 ( V_12 , V_4 , V_18 , V_8 , 0x12000 , & V_2 ) ;
* V_9 = V_2 ;
if ( V_7 )
return V_7 ;
args . V_71 = V_2 -> V_14 . V_8 ;
args . V_72 = 0x10000 + V_2 -> V_14 . V_16 . V_38 ;
args . V_73 = 0x02000 ;
args . V_63 = V_63 ;
do {
V_7 = F_22 ( F_7 ( V_4 ) , V_18 , V_8 ,
* V_69 ++ , & args , sizeof( args ) ,
& V_2 -> V_74 ) ;
if ( V_7 == 0 )
return V_7 ;
} while ( * V_69 );
F_6 ( V_9 ) ;
return V_7 ;
}
static int
F_24 ( struct V_17 * V_12 , struct V_3 * V_4 ,
T_1 V_18 , T_1 V_8 , struct V_1 * * V_9 )
{
static const T_3 V_64 [] = { V_75 ,
V_76 ,
V_77 ,
V_78 ,
0 } ;
const T_3 * V_69 = V_64 ;
struct V_79 args ;
struct V_1 * V_2 ;
int V_7 ;
V_7 = F_14 ( V_12 , V_4 , V_18 , V_8 , 0x10000 , & V_2 ) ;
* V_9 = V_2 ;
if ( V_7 )
return V_7 ;
args . V_71 = V_2 -> V_14 . V_8 ;
args . V_38 = V_2 -> V_14 . V_16 . V_38 ;
do {
V_7 = F_22 ( F_7 ( V_4 ) , V_18 , V_8 ,
* V_69 ++ , & args , sizeof( args ) ,
& V_2 -> V_74 ) ;
if ( V_7 == 0 )
return V_7 ;
} while ( V_7 && * V_69 );
F_6 ( V_9 ) ;
return V_7 ;
}
static int
F_25 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_81 )
{
struct V_28 * V_11 = F_26 ( V_2 -> V_4 ) ;
struct V_20 * V_21 = F_15 ( V_2 -> V_12 -> V_21 ) ;
struct V_22 * V_23 = V_22 ( V_21 ) ;
struct V_24 * V_25 = V_24 ( V_21 ) ;
struct V_26 * V_27 = V_26 ( V_21 ) ;
struct V_82 * V_83 ;
struct V_10 * V_74 ;
struct V_30 args ;
int V_7 , V_84 ;
if ( V_21 -> V_41 < V_85 ) {
if ( V_21 -> V_41 >= V_42 ) {
args . V_44 = V_45 | V_46 ;
args . V_47 = 0 ;
args . V_48 = V_11 -> V_43 -> V_25 -> V_48 - 1 ;
} else {
args . V_44 = V_58 | V_56 ;
args . V_47 = 0 ;
args . V_48 = V_27 -> V_52 . V_19 - V_23 -> V_53 - 1 ;
}
V_7 = F_22 ( F_7 ( V_11 ) , V_2 -> V_8 , V_80 ,
0x003d , & args , sizeof( args ) , & V_74 ) ;
if ( V_7 )
return V_7 ;
if ( V_21 -> V_41 >= V_42 ) {
args . V_44 = V_45 | V_46 ;
args . V_47 = 0 ;
args . V_48 = V_11 -> V_43 -> V_25 -> V_48 - 1 ;
} else
if ( V_2 -> V_12 -> V_59 . V_60 == V_61 ) {
args . V_44 = V_62 | V_56 ;
args . V_47 = V_2 -> V_12 -> V_59 . V_29 ;
args . V_48 = V_2 -> V_12 -> V_59 . V_29 +
V_2 -> V_12 -> V_59 . V_19 - 1 ;
} else {
args . V_44 = V_45 | V_56 ;
args . V_47 = 0 ;
args . V_48 = V_25 -> V_48 - 1 ;
}
V_7 = F_22 ( F_7 ( V_11 ) , V_2 -> V_8 , V_81 ,
0x003d , & args , sizeof( args ) , & V_74 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_80 = V_80 ;
V_2 -> V_81 = V_81 ;
}
switch ( F_27 ( V_2 -> V_74 ) & 0x00ff ) {
case 0x006b :
case 0x006e :
V_2 -> V_86 = 0x40 ;
V_2 -> V_87 = 0x44 ;
V_2 -> V_88 . V_89 = ( 0x10000 / 4 ) - 2 ;
break;
default:
V_2 -> V_86 = 0x40 ;
V_2 -> V_87 = 0x44 ;
V_2 -> V_90 = 0x60 ;
V_2 -> V_88 . V_91 = 0x10000 / 4 ;
V_2 -> V_88 . V_92 = ( 0x02000 / 8 ) - 1 ;
V_2 -> V_88 . V_93 = 0 ;
V_2 -> V_88 . V_94 = V_2 -> V_88 . V_92 - V_2 -> V_88 . V_93 ;
V_2 -> V_88 . V_89 = V_2 -> V_88 . V_91 ;
break;
}
V_2 -> V_88 . V_95 = 0 ;
V_2 -> V_88 . V_96 = V_2 -> V_88 . V_95 ;
V_2 -> V_88 . free = V_2 -> V_88 . V_89 - V_2 -> V_88 . V_96 ;
V_7 = F_28 ( V_2 , V_97 ) ;
if ( V_7 )
return V_7 ;
for ( V_84 = 0 ; V_84 < V_97 ; V_84 ++ )
F_29 ( V_2 , 0x00000000 ) ;
if ( V_2 != V_2 -> V_12 -> V_98 ) {
V_7 = F_22 ( F_7 ( V_11 ) , V_2 -> V_8 ,
V_99 , F_30 ( V_2 -> V_12 ) ,
NULL , 0 , & V_74 ) ;
if ( V_7 )
return V_7 ;
V_83 = ( void * ) V_74 -> V_18 ;
V_83 -> V_100 = V_101 ;
V_83 -> V_102 = V_2 ;
}
if ( V_21 -> V_41 < V_85 ) {
V_7 = F_28 ( V_2 , 2 ) ;
if ( V_7 )
return V_7 ;
F_31 ( V_2 , V_103 , 0x0000 , 1 ) ;
F_29 ( V_2 , V_99 ) ;
F_32 ( V_2 ) ;
}
return V_5 ( V_2 -> V_12 ) -> F_33 ( V_2 ) ;
}
int
F_34 ( struct V_17 * V_12 , struct V_3 * V_4 ,
T_1 V_18 , T_1 V_8 , T_1 V_104 , T_1 V_105 ,
struct V_1 * * V_9 )
{
int V_7 ;
V_7 = F_23 ( V_12 , V_4 , V_18 , V_8 , V_104 , V_9 ) ;
if ( V_7 ) {
F_35 ( V_4 , L_2 , V_7 ) ;
V_7 = F_24 ( V_12 , V_4 , V_18 , V_8 , V_9 ) ;
if ( V_7 ) {
F_35 ( V_4 , L_3 , V_7 ) ;
return V_7 ;
}
}
V_7 = F_25 ( * V_9 , V_104 , V_105 ) ;
if ( V_7 ) {
F_5 ( V_4 , L_4 , V_7 ) ;
F_6 ( V_9 ) ;
return V_7 ;
}
return 0 ;
}
