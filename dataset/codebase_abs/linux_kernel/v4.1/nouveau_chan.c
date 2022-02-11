int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = NULL ;
int V_8 ;
V_8 = F_3 ( V_2 , false , & V_7 ) ;
if ( ! V_8 ) {
V_8 = F_4 ( V_7 , false , false ) ;
F_5 ( & V_7 ) ;
}
if ( V_8 )
F_6 ( error , V_4 , L_1 ,
V_2 -> V_5 -> V_9 , F_7 ( & V_4 -> V_10 ) -> V_11 ) ;
return V_8 ;
}
void
F_8 ( struct V_1 * * V_12 )
{
struct V_1 * V_2 = * V_12 ;
if ( V_2 ) {
if ( V_2 -> V_7 ) {
F_1 ( V_2 ) ;
V_6 ( V_2 -> V_13 ) -> F_9 ( V_2 ) ;
}
F_10 ( & V_2 -> V_14 ) ;
F_10 ( & V_2 -> V_15 ) ;
F_10 ( & V_2 -> V_16 ) ;
F_11 ( NULL , & V_2 -> V_5 ) ;
F_10 ( & V_2 -> V_17 . V_18 ) ;
F_12 ( V_2 -> V_17 . V_19 , & V_2 -> V_17 . V_20 ) ;
F_13 ( V_2 -> V_17 . V_19 ) ;
if ( V_2 -> V_17 . V_19 && V_2 -> V_17 . V_19 -> V_21 )
F_14 ( V_2 -> V_17 . V_19 ) ;
F_15 ( NULL , & V_2 -> V_17 . V_19 ) ;
F_16 ( NULL , & V_2 -> V_22 ) ;
F_17 ( V_2 ) ;
}
* V_12 = NULL ;
}
static int
F_18 ( struct V_23 * V_13 , struct V_24 * V_22 ,
T_1 V_9 , T_1 V_25 , struct V_1 * * V_12 )
{
struct V_3 * V_4 = ( void * ) F_2 ( & V_22 -> V_10 ) ;
struct V_26 * V_27 = F_19 ( V_22 ) ;
struct V_28 args = {} ;
struct V_1 * V_2 ;
T_1 V_29 ;
int V_8 ;
V_2 = * V_12 = F_20 ( sizeof( * V_2 ) , V_30 ) ;
if ( ! V_2 )
return - V_31 ;
F_16 ( V_22 , & V_2 -> V_22 ) ;
V_2 -> V_13 = V_13 ;
V_29 = V_32 | V_33 ;
if ( V_34 )
V_29 = V_35 ;
V_8 = F_21 ( V_13 -> V_36 , V_25 , 0 , V_29 , 0 , 0 , NULL , NULL ,
& V_2 -> V_17 . V_19 ) ;
if ( V_8 == 0 ) {
V_8 = F_22 ( V_2 -> V_17 . V_19 , V_29 , false ) ;
if ( V_8 == 0 )
V_8 = F_23 ( V_2 -> V_17 . V_19 ) ;
}
if ( V_8 ) {
F_8 ( V_12 ) ;
return V_8 ;
}
V_2 -> V_17 . V_20 . V_37 = V_2 -> V_17 . V_19 -> V_38 . V_37 ;
if ( V_22 -> V_39 . V_40 >= V_41 ) {
V_8 = F_24 ( V_2 -> V_17 . V_19 , V_4 -> V_42 ,
& V_2 -> V_17 . V_20 ) ;
if ( V_8 ) {
F_8 ( V_12 ) ;
return V_8 ;
}
args . V_29 = V_43 ;
args . V_44 = V_45 ;
args . V_46 = 0 ;
args . V_47 = V_4 -> V_42 -> V_27 -> V_47 - 1 ;
} else
if ( V_2 -> V_17 . V_19 -> V_38 . V_48 . V_49 == V_50 ) {
if ( V_22 -> V_39 . V_40 == V_51 ) {
args . V_29 = V_52 ;
args . V_44 = V_53 ;
args . V_46 = F_25 ( F_26 ( V_22 ) , 1 ) ;
args . V_47 = args . V_46 + V_22 -> V_39 . V_54 - 1 ;
} else {
args . V_29 = V_55 ;
args . V_44 = V_53 ;
args . V_46 = 0 ;
args . V_47 = V_22 -> V_39 . V_54 - 1 ;
}
} else {
if ( V_2 -> V_13 -> V_56 . V_57 == V_58 ) {
args . V_29 = V_59 ;
args . V_44 = V_53 ;
args . V_46 = V_2 -> V_13 -> V_56 . V_10 ;
args . V_47 = V_2 -> V_13 -> V_56 . V_10 +
V_2 -> V_13 -> V_56 . V_25 - 1 ;
} else {
args . V_29 = V_43 ;
args . V_44 = V_53 ;
args . V_46 = 0 ;
args . V_47 = V_27 -> V_47 - 1 ;
}
}
V_8 = F_27 ( F_28 ( V_22 ) , NULL , V_60 |
( V_9 & 0xffff ) , V_61 ,
& args , sizeof( args ) , & V_2 -> V_17 . V_18 ) ;
if ( V_8 ) {
F_8 ( V_12 ) ;
return V_8 ;
}
return 0 ;
}
static int
F_29 ( struct V_23 * V_13 , struct V_24 * V_22 ,
T_1 V_9 , T_1 V_62 , struct V_1 * * V_12 )
{
static const T_2 V_63 [] = { V_64 ,
V_65 ,
V_66 ,
V_67 ,
V_68 ,
0 } ;
const T_2 * V_69 = V_63 ;
union {
struct V_70 V_71 ;
struct V_72 V_73 ;
} args , * V_74 ;
struct V_1 * V_2 ;
T_1 V_25 ;
int V_8 ;
V_8 = F_18 ( V_13 , V_22 , V_9 , 0x12000 , & V_2 ) ;
* V_12 = V_2 ;
if ( V_8 )
return V_8 ;
do {
if ( V_69 [ 0 ] >= V_65 ) {
args . V_73 . V_75 = 0 ;
args . V_73 . V_62 = V_62 ;
args . V_73 . V_76 = V_2 -> V_17 . V_18 . V_9 ;
args . V_73 . V_77 = 0x02000 ;
args . V_73 . V_78 = 0x10000 + V_2 -> V_17 . V_20 . V_37 ;
V_25 = sizeof( args . V_73 ) ;
} else {
args . V_71 . V_75 = 0 ;
args . V_71 . V_76 = V_2 -> V_17 . V_18 . V_9 ;
args . V_71 . V_77 = 0x02000 ;
args . V_71 . V_78 = 0x10000 + V_2 -> V_17 . V_20 . V_37 ;
V_25 = sizeof( args . V_71 ) ;
}
V_8 = F_30 ( F_28 ( V_22 ) , V_9 , * V_69 ++ ,
& args , V_25 , & V_2 -> V_5 ) ;
if ( V_8 == 0 ) {
V_74 = V_2 -> V_5 -> V_79 ;
if ( V_2 -> V_5 -> V_69 >= V_65 )
V_2 -> V_80 = V_74 -> V_73 . V_80 ;
else
V_2 -> V_80 = V_74 -> V_71 . V_80 ;
return V_8 ;
}
} while ( * V_69 );
F_8 ( V_12 ) ;
return V_8 ;
}
static int
F_31 ( struct V_23 * V_13 , struct V_24 * V_22 ,
T_1 V_9 , struct V_1 * * V_12 )
{
static const T_2 V_63 [] = { V_81 ,
V_82 ,
V_83 ,
V_84 ,
0 } ;
const T_2 * V_69 = V_63 ;
struct V_85 args , * V_74 ;
struct V_1 * V_2 ;
int V_8 ;
V_8 = F_18 ( V_13 , V_22 , V_9 , 0x10000 , & V_2 ) ;
* V_12 = V_2 ;
if ( V_8 )
return V_8 ;
args . V_75 = 0 ;
args . V_76 = V_2 -> V_17 . V_18 . V_9 ;
args . V_37 = V_2 -> V_17 . V_20 . V_37 ;
do {
V_8 = F_30 ( F_28 ( V_22 ) , V_9 , * V_69 ++ ,
& args , sizeof( args ) , & V_2 -> V_5 ) ;
if ( V_8 == 0 ) {
V_74 = V_2 -> V_5 -> V_79 ;
V_2 -> V_80 = V_74 -> V_80 ;
return V_8 ;
}
} while ( V_8 && * V_69 );
F_8 ( V_12 ) ;
return V_8 ;
}
static int
F_32 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_15 )
{
struct V_24 * V_22 = V_2 -> V_22 ;
struct V_3 * V_4 = ( void * ) F_2 ( & V_22 -> V_10 ) ;
struct V_26 * V_27 = F_19 ( V_22 ) ;
struct V_86 * V_87 ;
struct V_28 args = {} ;
int V_8 , V_88 ;
F_33 ( V_2 -> V_5 ) ;
if ( V_22 -> V_39 . V_40 < V_89 ) {
if ( V_22 -> V_39 . V_40 >= V_41 ) {
args . V_29 = V_43 ;
args . V_44 = V_45 ;
args . V_46 = 0 ;
args . V_47 = V_4 -> V_42 -> V_27 -> V_47 - 1 ;
} else {
args . V_29 = V_55 ;
args . V_44 = V_53 ;
args . V_46 = 0 ;
args . V_47 = V_22 -> V_39 . V_54 - 1 ;
}
V_8 = F_27 ( V_2 -> V_5 , NULL , V_16 ,
V_90 , & args ,
sizeof( args ) , & V_2 -> V_16 ) ;
if ( V_8 )
return V_8 ;
if ( V_22 -> V_39 . V_40 >= V_41 ) {
args . V_29 = V_43 ;
args . V_44 = V_45 ;
args . V_46 = 0 ;
args . V_47 = V_4 -> V_42 -> V_27 -> V_47 - 1 ;
} else
if ( V_2 -> V_13 -> V_56 . V_57 == V_58 ) {
args . V_29 = V_59 ;
args . V_44 = V_53 ;
args . V_46 = V_2 -> V_13 -> V_56 . V_10 ;
args . V_47 = V_2 -> V_13 -> V_56 . V_10 +
V_2 -> V_13 -> V_56 . V_25 - 1 ;
} else {
args . V_29 = V_43 ;
args . V_44 = V_53 ;
args . V_46 = 0 ;
args . V_47 = V_27 -> V_47 - 1 ;
}
V_8 = F_27 ( V_2 -> V_5 , NULL , V_15 ,
V_90 , & args ,
sizeof( args ) , & V_2 -> V_15 ) ;
if ( V_8 )
return V_8 ;
}
switch ( V_2 -> V_5 -> V_69 & 0x00ff ) {
case 0x006b :
case 0x006e :
V_2 -> V_91 = 0x40 ;
V_2 -> V_92 = 0x44 ;
V_2 -> V_93 . V_94 = ( 0x10000 / 4 ) - 2 ;
break;
default:
V_2 -> V_91 = 0x40 ;
V_2 -> V_92 = 0x44 ;
V_2 -> V_95 = 0x60 ;
V_2 -> V_93 . V_96 = 0x10000 / 4 ;
V_2 -> V_93 . V_97 = ( 0x02000 / 8 ) - 1 ;
V_2 -> V_93 . V_98 = 0 ;
V_2 -> V_93 . V_99 = V_2 -> V_93 . V_97 - V_2 -> V_93 . V_98 ;
V_2 -> V_93 . V_94 = V_2 -> V_93 . V_96 ;
break;
}
V_2 -> V_93 . V_100 = 0 ;
V_2 -> V_93 . V_101 = V_2 -> V_93 . V_100 ;
V_2 -> V_93 . free = V_2 -> V_93 . V_94 - V_2 -> V_93 . V_101 ;
V_8 = F_34 ( V_2 , V_102 ) ;
if ( V_8 )
return V_8 ;
for ( V_88 = 0 ; V_88 < V_102 ; V_88 ++ )
F_35 ( V_2 , 0x00000000 ) ;
if ( V_22 -> V_39 . V_40 < V_103 ) {
V_8 = F_27 ( V_2 -> V_5 , NULL , 0x006e , 0x006e ,
NULL , 0 , & V_2 -> V_14 ) ;
if ( V_8 )
return V_8 ;
V_87 = ( void * ) F_36 ( & V_2 -> V_14 ) -> V_104 ;
V_87 -> V_105 = V_106 ;
V_87 -> V_107 = V_2 ;
V_8 = F_34 ( V_2 , 2 ) ;
if ( V_8 )
return V_8 ;
F_37 ( V_2 , V_108 , 0x0000 , 1 ) ;
F_35 ( V_2 , V_2 -> V_14 . V_9 ) ;
F_38 ( V_2 ) ;
}
return V_6 ( V_2 -> V_13 ) -> F_39 ( V_2 ) ;
}
int
F_40 ( struct V_23 * V_13 , struct V_24 * V_22 ,
T_1 V_9 , T_1 V_109 , T_1 V_110 ,
struct V_1 * * V_12 )
{
struct V_3 * V_4 = ( void * ) F_2 ( & V_22 -> V_10 ) ;
bool V_111 ;
int V_8 ;
V_111 = V_4 -> V_10 . V_111 ;
V_4 -> V_10 . V_111 = true ;
V_8 = F_29 ( V_13 , V_22 , V_9 , V_109 , V_12 ) ;
if ( V_8 ) {
F_6 ( V_112 , V_4 , L_2 , V_8 ) ;
V_8 = F_31 ( V_13 , V_22 , V_9 , V_12 ) ;
if ( V_8 ) {
F_6 ( V_112 , V_4 , L_3 , V_8 ) ;
goto V_113;
}
}
V_8 = F_32 ( * V_12 , V_109 , V_110 ) ;
if ( V_8 ) {
F_6 ( error , V_4 , L_4 , V_8 ) ;
F_8 ( V_12 ) ;
}
V_113:
V_4 -> V_10 . V_111 = V_111 ;
return V_8 ;
}
