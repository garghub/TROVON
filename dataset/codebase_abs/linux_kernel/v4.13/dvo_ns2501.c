static bool F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
T_2 V_11 [ 2 ] ;
T_2 V_12 [ 2 ] ;
struct V_13 V_14 [] = {
{
. V_3 = V_2 -> V_15 ,
. V_16 = 0 ,
. V_17 = 1 ,
. V_18 = V_11 ,
} ,
{
. V_3 = V_2 -> V_15 ,
. V_16 = V_19 ,
. V_17 = 1 ,
. V_18 = V_12 ,
}
} ;
V_11 [ 0 ] = V_3 ;
V_11 [ 1 ] = 0 ;
if ( F_2 ( V_9 , V_14 , 2 ) == 2 ) {
* V_4 = V_12 [ 0 ] ;
return true ;
}
if ( ! V_6 -> V_20 ) {
F_3
( L_1 , V_3 ,
V_9 -> V_21 , V_2 -> V_15 ) ;
}
return false ;
}
static bool F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
T_1 V_11 [ 2 ] ;
struct V_13 V_22 = {
. V_3 = V_2 -> V_15 ,
. V_16 = 0 ,
. V_17 = 2 ,
. V_18 = V_11 ,
} ;
V_11 [ 0 ] = V_3 ;
V_11 [ 1 ] = V_4 ;
if ( F_2 ( V_9 , & V_22 , 1 ) == 1 ) {
return true ;
}
if ( ! V_6 -> V_20 ) {
F_3 ( L_2 ,
V_3 , V_9 -> V_21 , V_2 -> V_15 ) ;
}
return false ;
}
static bool F_5 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_5 * V_6 ;
unsigned char V_4 ;
V_6 = F_6 ( sizeof( struct V_5 ) , V_23 ) ;
if ( V_6 == NULL )
return false ;
V_2 -> V_10 = V_9 ;
V_2 -> V_7 = V_6 ;
V_6 -> V_20 = true ;
if ( ! F_1 ( V_2 , V_24 , & V_4 ) )
goto V_25;
if ( V_4 != ( V_26 & 0xff ) ) {
F_3 ( L_3 ,
V_4 , V_9 -> V_21 , V_2 -> V_15 ) ;
goto V_25;
}
if ( ! F_1 ( V_2 , V_27 , & V_4 ) )
goto V_25;
if ( V_4 != ( V_28 & 0xff ) ) {
F_3 ( L_3 ,
V_4 , V_9 -> V_21 , V_2 -> V_15 ) ;
goto V_25;
}
V_6 -> V_20 = false ;
F_3 ( L_4 ) ;
return true ;
V_25:
F_7 ( V_6 ) ;
return false ;
}
static enum V_29 F_8 ( struct V_1 * V_2 )
{
return V_30 ;
}
static enum V_31 F_9 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
F_3
( L_5 ,
V_33 -> V_34 , V_33 -> V_35 , V_33 -> V_36 , V_33 -> V_37 ) ;
if ( ( V_33 -> V_34 == 640 && V_33 -> V_36 == 480 && V_33 -> clock == 25175 ) ||
( V_33 -> V_34 == 800 && V_33 -> V_36 == 600 && V_33 -> clock == 40000 ) ||
( V_33 -> V_34 == 1024 && V_33 -> V_36 == 768 && V_33 -> clock == 65000 ) ) {
return V_38 ;
} else {
return V_39 ;
}
}
static void F_10 ( struct V_1 * V_2 ,
const struct V_32 * V_33 ,
const struct V_32 * V_40 )
{
const struct V_41 * V_42 ;
struct V_5 * V_6 = (struct V_5 * ) ( V_2 -> V_7 ) ;
int V_43 , V_44 ;
F_3
( L_6 ,
V_33 -> V_34 , V_33 -> V_35 , V_33 -> V_36 , V_33 -> V_37 ) ;
F_3 ( L_7
L_8
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16
L_17
L_11
L_18
L_19
L_20 ,
V_40 -> V_45 ,
V_40 -> V_46 ,
V_40 -> V_47 ,
V_40 -> V_48 ,
V_40 -> V_49 ,
V_40 -> V_50 ,
V_40 -> V_51 ,
V_40 -> V_52 ,
V_40 -> V_53 ,
V_40 -> V_54 ,
V_40 -> V_55 ,
V_40 -> V_56 ,
V_40 -> V_57 ,
V_40 -> V_58 ) ;
if ( V_33 -> V_34 == 640 && V_33 -> V_36 == 480 )
V_43 = V_59 ;
else if ( V_33 -> V_34 == 800 && V_33 -> V_36 == 600 )
V_43 = V_60 ;
else if ( V_33 -> V_34 == 1024 && V_33 -> V_36 == 768 )
V_43 = V_61 ;
else
return;
for ( V_44 = 0 ; V_44 < F_11 ( V_62 ) ; V_44 ++ )
F_4 ( V_2 , V_62 [ V_44 ] . V_63 , V_62 [ V_44 ] . V_64 ) ;
for ( V_44 = 0 ; V_44 < F_11 ( V_65 ) ; V_44 ++ )
F_4 ( V_2 , V_65 [ V_44 ] . V_63 ,
V_65 [ V_44 ] . V_64 ) ;
V_42 = V_66 + V_43 ;
V_6 -> V_42 = V_42 ;
F_4 ( V_2 , V_67 , V_42 -> V_42 ) ;
F_4 ( V_2 , V_68 , V_42 -> V_69 ) ;
F_4 ( V_2 , V_70 , V_42 -> V_71 & 0xff ) ;
F_4 ( V_2 , V_72 , V_42 -> V_71 >> 8 ) ;
F_4 ( V_2 , V_73 , V_42 -> V_74 & 0xff ) ;
F_4 ( V_2 , V_75 , V_42 -> V_74 >> 8 ) ;
F_4 ( V_2 , V_76 , V_42 -> V_77 & 0xff ) ;
F_4 ( V_2 , V_78 , V_42 -> V_77 >> 8 ) ;
F_4 ( V_2 , V_79 , V_42 -> V_80 & 0xff ) ;
F_4 ( V_2 , V_81 , V_42 -> V_80 >> 8 ) ;
F_4 ( V_2 , V_82 , V_42 -> V_83 & 0xff ) ;
F_4 ( V_2 , V_84 , V_42 -> V_83 >> 8 ) ;
F_4 ( V_2 , V_85 , V_42 -> V_86 & 0xff ) ;
F_4 ( V_2 , V_87 , V_42 -> V_86 >> 8 ) ;
F_4 ( V_2 , V_88 , V_42 -> V_37 & 0xff ) ;
F_4 ( V_2 , V_89 , V_42 -> V_37 >> 8 ) ;
F_4 ( V_2 , V_90 , V_42 -> V_91 & 0xff ) ;
F_4 ( V_2 , V_92 , V_42 -> V_91 >> 8 ) ;
F_4 ( V_2 , V_93 , V_42 -> V_94 & 0xff ) ;
F_4 ( V_2 , V_95 , V_42 -> V_94 >> 8 ) ;
F_4 ( V_2 , V_96 , V_42 -> V_97 & 0xff ) ;
F_4 ( V_2 , V_98 , V_42 -> V_97 >> 8 ) ;
F_4 ( V_2 , V_99 , V_42 -> V_100 & 0xff ) ;
F_4 ( V_2 , V_101 , V_42 -> V_100 >> 8 ) ;
F_4 ( V_2 , V_102 , V_42 -> V_103 & 0xff ) ;
F_4 ( V_2 , V_104 , V_42 -> V_103 >> 8 ) ;
F_4 ( V_2 , V_105 , V_42 -> V_106 ) ;
F_4 ( V_2 , V_107 , V_42 -> V_108 ) ;
F_4 ( V_2 , V_109 , V_42 -> V_110 ) ;
}
static bool F_12 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
if ( ! F_1 ( V_2 , V_67 , & V_4 ) )
return false ;
return V_4 & V_111 ;
}
static void F_13 ( struct V_1 * V_2 , bool V_112 )
{
struct V_5 * V_6 = (struct V_5 * ) ( V_2 -> V_7 ) ;
F_3 ( L_21 , V_112 ) ;
if ( V_112 ) {
F_4 ( V_2 , V_109 , V_6 -> V_42 -> V_110 | 0x08 ) ;
F_4 ( V_2 , V_107 , V_6 -> V_42 -> V_108 ) ;
F_4 ( V_2 , V_113 , V_114 ) ;
F_14 ( 15 ) ;
F_4 ( V_2 , V_67 ,
V_6 -> V_42 -> V_42 | V_115 ) ;
if ( ! ( V_6 -> V_42 -> V_42 & V_115 ) )
F_4 ( V_2 , V_67 , V_6 -> V_42 -> V_42 ) ;
F_14 ( 200 ) ;
F_4 ( V_2 , V_113 ,
V_114 | V_116 ) ;
F_4 ( V_2 , V_109 , V_6 -> V_42 -> V_110 ) ;
} else {
F_4 ( V_2 , V_113 , V_114 ) ;
F_14 ( 200 ) ;
F_4 ( V_2 , V_67 , V_117 | V_118 |
V_115 ) ;
F_14 ( 15 ) ;
F_4 ( V_2 , V_113 , 0x00 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 ) {
F_7 ( V_6 ) ;
V_2 -> V_7 = NULL ;
}
}
