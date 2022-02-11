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
if ( V_2 -> V_14 . V_15 && V_2 -> V_14 . V_15 -> V_17 )
F_12 ( V_2 -> V_14 . V_15 ) ;
F_13 ( NULL , & V_2 -> V_14 . V_15 ) ;
F_14 ( V_2 ) ;
}
* V_9 = NULL ;
}
static int
F_15 ( struct V_18 * V_12 , struct V_3 * V_4 ,
T_1 V_19 , T_1 V_8 , T_1 V_20 ,
struct V_1 * * V_9 )
{
struct V_21 * V_22 = F_16 ( V_12 -> V_22 ) ;
struct V_23 * V_24 = V_23 ( V_22 ) ;
struct V_25 * V_26 = V_25 ( V_22 ) ;
struct V_27 * V_28 = V_27 ( V_22 ) ;
struct V_29 * V_11 = & V_4 -> V_30 ;
struct V_31 args = {} ;
struct V_1 * V_2 ;
struct V_10 * V_14 ;
T_1 V_32 ;
int V_7 ;
V_2 = * V_9 = F_17 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_8 = V_8 ;
V_32 = V_35 ;
if ( V_36 )
V_32 = V_37 ;
V_7 = F_18 ( V_12 -> V_38 , V_20 , 0 , V_32 , 0 , 0 , NULL ,
& V_2 -> V_14 . V_15 ) ;
if ( V_7 == 0 ) {
V_7 = F_19 ( V_2 -> V_14 . V_15 , V_32 ) ;
if ( V_7 == 0 )
V_7 = F_20 ( V_2 -> V_14 . V_15 ) ;
}
if ( V_7 ) {
F_6 ( V_9 ) ;
return V_7 ;
}
V_2 -> V_14 . V_16 . V_39 = V_2 -> V_14 . V_15 -> V_40 . V_39 ;
V_2 -> V_14 . V_8 = V_41 | ( V_8 & 0xffff ) ;
if ( V_22 -> V_42 >= V_43 ) {
V_7 = F_21 ( V_2 -> V_14 . V_15 , V_11 -> V_44 ,
& V_2 -> V_14 . V_16 ) ;
if ( V_7 ) {
F_6 ( V_9 ) ;
return V_7 ;
}
args . V_45 = V_46 | V_47 ;
args . V_48 = 0 ;
args . V_49 = V_11 -> V_44 -> V_26 -> V_49 - 1 ;
} else
if ( V_2 -> V_14 . V_15 -> V_40 . V_50 . V_51 == V_52 ) {
T_2 V_49 = V_28 -> V_53 . V_20 - V_24 -> V_54 - 1 ;
if ( V_22 -> V_42 == V_55 ) {
args . V_45 = V_56 | V_57 ;
args . V_48 = F_22 ( V_22 -> V_58 , 1 ) ;
args . V_49 = args . V_48 + V_49 ;
} else {
args . V_45 = V_59 | V_57 ;
args . V_48 = 0 ;
args . V_49 = V_49 ;
}
} else {
if ( V_2 -> V_12 -> V_60 . V_61 == V_62 ) {
args . V_45 = V_63 | V_57 ;
args . V_48 = V_2 -> V_12 -> V_60 . V_30 ;
args . V_49 = V_2 -> V_12 -> V_60 . V_30 +
V_2 -> V_12 -> V_60 . V_20 - 1 ;
} else {
args . V_45 = V_46 | V_57 ;
args . V_48 = 0 ;
args . V_49 = V_26 -> V_49 - 1 ;
}
}
V_7 = F_23 ( F_7 ( V_2 -> V_4 ) , V_19 ,
V_2 -> V_14 . V_8 , 0x0002 ,
& args , sizeof( args ) , & V_14 ) ;
if ( V_7 ) {
F_6 ( V_9 ) ;
return V_7 ;
}
return 0 ;
}
static int
F_24 ( struct V_18 * V_12 , struct V_3 * V_4 ,
T_1 V_19 , T_1 V_8 , T_1 V_64 ,
struct V_1 * * V_9 )
{
static const T_3 V_65 [] = { V_66 ,
V_67 ,
V_68 ,
V_69 ,
0 } ;
const T_3 * V_70 = V_65 ;
struct V_71 args ;
struct V_1 * V_2 ;
int V_7 ;
V_7 = F_15 ( V_12 , V_4 , V_19 , V_8 , 0x12000 , & V_2 ) ;
* V_9 = V_2 ;
if ( V_7 )
return V_7 ;
args . V_72 = V_2 -> V_14 . V_8 ;
args . V_73 = 0x10000 + V_2 -> V_14 . V_16 . V_39 ;
args . V_74 = 0x02000 ;
args . V_64 = V_64 ;
do {
V_7 = F_23 ( F_7 ( V_4 ) , V_19 , V_8 ,
* V_70 ++ , & args , sizeof( args ) ,
& V_2 -> V_75 ) ;
if ( V_7 == 0 )
return V_7 ;
} while ( * V_70 );
F_6 ( V_9 ) ;
return V_7 ;
}
static int
F_25 ( struct V_18 * V_12 , struct V_3 * V_4 ,
T_1 V_19 , T_1 V_8 , struct V_1 * * V_9 )
{
static const T_3 V_65 [] = { V_76 ,
V_77 ,
V_78 ,
V_79 ,
0 } ;
const T_3 * V_70 = V_65 ;
struct V_80 args ;
struct V_1 * V_2 ;
int V_7 ;
V_7 = F_15 ( V_12 , V_4 , V_19 , V_8 , 0x10000 , & V_2 ) ;
* V_9 = V_2 ;
if ( V_7 )
return V_7 ;
args . V_72 = V_2 -> V_14 . V_8 ;
args . V_39 = V_2 -> V_14 . V_16 . V_39 ;
do {
V_7 = F_23 ( F_7 ( V_4 ) , V_19 , V_8 ,
* V_70 ++ , & args , sizeof( args ) ,
& V_2 -> V_75 ) ;
if ( V_7 == 0 )
return V_7 ;
} while ( V_7 && * V_70 );
F_6 ( V_9 ) ;
return V_7 ;
}
static int
F_26 ( struct V_1 * V_2 , T_1 V_81 , T_1 V_82 )
{
struct V_29 * V_11 = F_27 ( V_2 -> V_4 ) ;
struct V_21 * V_22 = F_16 ( V_2 -> V_12 -> V_22 ) ;
struct V_23 * V_24 = V_23 ( V_22 ) ;
struct V_25 * V_26 = V_25 ( V_22 ) ;
struct V_27 * V_28 = V_27 ( V_22 ) ;
struct V_83 * V_84 ;
struct V_10 * V_75 ;
struct V_31 args = {} ;
int V_7 , V_85 ;
if ( V_22 -> V_42 < V_86 ) {
if ( V_22 -> V_42 >= V_43 ) {
args . V_45 = V_46 | V_47 ;
args . V_48 = 0 ;
args . V_49 = V_11 -> V_44 -> V_26 -> V_49 - 1 ;
} else {
args . V_45 = V_59 | V_57 ;
args . V_48 = 0 ;
args . V_49 = V_28 -> V_53 . V_20 - V_24 -> V_54 - 1 ;
}
V_7 = F_23 ( F_7 ( V_11 ) , V_2 -> V_8 , V_81 ,
0x003d , & args , sizeof( args ) , & V_75 ) ;
if ( V_7 )
return V_7 ;
if ( V_22 -> V_42 >= V_43 ) {
args . V_45 = V_46 | V_47 ;
args . V_48 = 0 ;
args . V_49 = V_11 -> V_44 -> V_26 -> V_49 - 1 ;
} else
if ( V_2 -> V_12 -> V_60 . V_61 == V_62 ) {
args . V_45 = V_63 | V_57 ;
args . V_48 = V_2 -> V_12 -> V_60 . V_30 ;
args . V_49 = V_2 -> V_12 -> V_60 . V_30 +
V_2 -> V_12 -> V_60 . V_20 - 1 ;
} else {
args . V_45 = V_46 | V_57 ;
args . V_48 = 0 ;
args . V_49 = V_26 -> V_49 - 1 ;
}
V_7 = F_23 ( F_7 ( V_11 ) , V_2 -> V_8 , V_82 ,
0x003d , & args , sizeof( args ) , & V_75 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_81 = V_81 ;
V_2 -> V_82 = V_82 ;
}
switch ( F_28 ( V_2 -> V_75 ) & 0x00ff ) {
case 0x006b :
case 0x006e :
V_2 -> V_87 = 0x40 ;
V_2 -> V_88 = 0x44 ;
V_2 -> V_89 . V_90 = ( 0x10000 / 4 ) - 2 ;
break;
default:
V_2 -> V_87 = 0x40 ;
V_2 -> V_88 = 0x44 ;
V_2 -> V_91 = 0x60 ;
V_2 -> V_89 . V_92 = 0x10000 / 4 ;
V_2 -> V_89 . V_93 = ( 0x02000 / 8 ) - 1 ;
V_2 -> V_89 . V_94 = 0 ;
V_2 -> V_89 . V_95 = V_2 -> V_89 . V_93 - V_2 -> V_89 . V_94 ;
V_2 -> V_89 . V_90 = V_2 -> V_89 . V_92 ;
break;
}
V_2 -> V_89 . V_96 = 0 ;
V_2 -> V_89 . V_97 = V_2 -> V_89 . V_96 ;
V_2 -> V_89 . free = V_2 -> V_89 . V_90 - V_2 -> V_89 . V_97 ;
V_7 = F_29 ( V_2 , V_98 ) ;
if ( V_7 )
return V_7 ;
for ( V_85 = 0 ; V_85 < V_98 ; V_85 ++ )
F_30 ( V_2 , 0x00000000 ) ;
if ( ( V_22 -> V_42 < V_99 ) || V_82 ) {
V_7 = F_23 ( F_7 ( V_11 ) , V_2 -> V_8 ,
V_100 , F_31 ( V_2 -> V_12 ) ,
NULL , 0 , & V_75 ) ;
if ( V_7 )
return V_7 ;
V_84 = ( void * ) V_75 -> V_19 ;
V_84 -> V_101 = V_102 ;
V_84 -> V_103 = V_2 ;
}
if ( V_22 -> V_42 < V_86 ) {
V_7 = F_29 ( V_2 , 2 ) ;
if ( V_7 )
return V_7 ;
F_32 ( V_2 , V_104 , 0x0000 , 1 ) ;
F_30 ( V_2 , V_100 ) ;
F_33 ( V_2 ) ;
}
return V_5 ( V_2 -> V_12 ) -> F_34 ( V_2 ) ;
}
int
F_35 ( struct V_18 * V_12 , struct V_3 * V_4 ,
T_1 V_19 , T_1 V_8 , T_1 V_105 , T_1 V_106 ,
struct V_1 * * V_9 )
{
int V_7 ;
V_7 = F_24 ( V_12 , V_4 , V_19 , V_8 , V_105 , V_9 ) ;
if ( V_7 ) {
F_36 ( V_4 , L_2 , V_7 ) ;
V_7 = F_25 ( V_12 , V_4 , V_19 , V_8 , V_9 ) ;
if ( V_7 ) {
F_36 ( V_4 , L_3 , V_7 ) ;
return V_7 ;
}
}
V_7 = F_26 ( * V_9 , V_105 , V_106 ) ;
if ( V_7 ) {
F_5 ( V_4 , L_4 , V_7 ) ;
F_6 ( V_9 ) ;
return V_7 ;
}
return 0 ;
}
