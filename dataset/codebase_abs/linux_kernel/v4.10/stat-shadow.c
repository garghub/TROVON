void F_1 ( void )
{
V_1 = F_2 ( L_1 , L_2 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
int V_4 = 0 ;
if ( V_3 -> V_5 . V_6 )
V_4 |= V_7 ;
if ( V_3 -> V_5 . V_8 )
V_4 |= V_9 ;
if ( V_3 -> V_5 . V_10 )
V_4 |= V_11 ;
if ( V_3 -> V_5 . V_12 )
V_4 |= V_13 ;
if ( V_3 -> V_5 . V_14 )
V_4 |= V_15 ;
return V_4 ;
}
void F_4 ( void )
{
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
memset ( V_17 , 0 , sizeof( V_17 ) ) ;
memset ( V_18 , 0 , sizeof( V_18 ) ) ;
memset ( V_19 , 0 , sizeof( V_19 ) ) ;
memset ( V_20 , 0 , sizeof( V_20 ) ) ;
memset ( V_21 , 0 , sizeof( V_21 ) ) ;
memset ( V_22 , 0 , sizeof( V_22 ) ) ;
memset ( V_23 , 0 , sizeof( V_23 ) ) ;
memset ( V_24 , 0 , sizeof( V_24 ) ) ;
memset ( V_25 , 0 , sizeof( V_25 ) ) ;
memset ( V_26 , 0 , sizeof( V_26 ) ) ;
memset ( V_27 , 0 ,
sizeof( V_27 ) ) ;
memset ( V_28 , 0 ,
sizeof( V_28 ) ) ;
memset ( V_29 , 0 , sizeof( V_29 ) ) ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
memset ( V_34 , 0 , sizeof( V_34 ) ) ;
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
}
void F_5 ( struct V_2 * V_36 , T_1 * V_37 ,
int V_38 )
{
int V_4 = F_3 ( V_36 ) ;
if ( F_6 ( V_36 , V_39 , V_40 ) ||
F_6 ( V_36 , V_39 , V_41 ) )
F_7 ( & V_16 [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_6 ( V_36 , V_42 , V_43 ) )
F_7 ( & V_17 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_8 ( V_36 , V_44 ) )
F_7 ( & V_27 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_8 ( V_36 , V_45 ) )
F_7 ( & V_28 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_8 ( V_36 , V_46 ) )
F_7 ( & V_29 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_8 ( V_36 , V_47 ) )
F_7 ( & V_31 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_8 ( V_36 , V_48 ) )
F_7 ( & V_33 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_8 ( V_36 , V_49 ) )
F_7 ( & V_32 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_8 ( V_36 , V_50 ) )
F_7 ( & V_34 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_8 ( V_36 , V_51 ) )
F_7 ( & V_35 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_6 ( V_36 , V_42 , V_52 ) )
F_7 ( & V_18 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_6 ( V_36 , V_42 , V_53 ) )
F_7 ( & V_19 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_6 ( V_36 , V_42 , V_54 ) )
F_7 ( & V_20 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_6 ( V_36 , V_42 , V_55 ) )
F_7 ( & V_21 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_6 ( V_36 , V_56 , V_57 ) )
F_7 ( & V_22 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_6 ( V_36 , V_56 , V_58 ) )
F_7 ( & V_24 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_6 ( V_36 , V_56 , V_59 ) )
F_7 ( & V_24 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_6 ( V_36 , V_56 , V_60 ) )
F_7 ( & V_26 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
else if ( F_6 ( V_36 , V_56 , V_61 ) )
F_7 ( & V_25 [ V_4 ] [ V_38 ] , V_37 [ 0 ] ) ;
}
static const char * F_9 ( enum V_62 type , double V_63 )
{
static const double V_64 [ V_65 ] [ 3 ] = {
[ V_66 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_67 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_68 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_69 = V_70 ;
if ( V_63 > V_64 [ type ] [ 0 ] )
V_69 = V_71 ;
else if ( V_63 > V_64 [ type ] [ 1 ] )
V_69 = V_72 ;
else if ( V_63 > V_64 [ type ] [ 2 ] )
V_69 = V_73 ;
return V_69 ;
}
static void F_10 ( int V_38 ,
struct V_2 * V_3 , double V_74 ,
struct V_75 * V_76 )
{
double V_77 , V_63 = 0.0 ;
const char * V_69 ;
int V_4 = F_3 ( V_3 ) ;
V_77 = F_11 ( & V_17 [ V_4 ] [ V_38 ] ) ;
if ( V_77 )
V_63 = V_74 / V_77 * 100.0 ;
V_69 = F_9 ( V_66 , V_63 ) ;
if ( V_63 )
V_76 -> V_78 ( V_76 -> V_4 , V_69 , L_3 , L_4 ,
V_63 ) ;
else
V_76 -> V_78 ( V_76 -> V_4 , NULL , NULL , L_4 , 0 ) ;
}
static void F_12 ( int V_38 ,
struct V_2 * V_3 , double V_74 ,
struct V_75 * V_76 )
{
double V_77 , V_63 = 0.0 ;
const char * V_69 ;
int V_4 = F_3 ( V_3 ) ;
V_77 = F_11 ( & V_17 [ V_4 ] [ V_38 ] ) ;
if ( V_77 )
V_63 = V_74 / V_77 * 100.0 ;
V_69 = F_9 ( V_67 , V_63 ) ;
V_76 -> V_78 ( V_76 -> V_4 , V_69 , L_3 , L_5 , V_63 ) ;
}
static void F_13 ( int V_38 ,
struct V_2 * V_3 ,
double V_74 ,
struct V_75 * V_76 )
{
double V_77 , V_63 = 0.0 ;
const char * V_69 ;
int V_4 = F_3 ( V_3 ) ;
V_77 = F_11 ( & V_20 [ V_4 ] [ V_38 ] ) ;
if ( V_77 )
V_63 = V_74 / V_77 * 100.0 ;
V_69 = F_9 ( V_68 , V_63 ) ;
V_76 -> V_78 ( V_76 -> V_4 , V_69 , L_3 , L_6 , V_63 ) ;
}
static void F_14 ( int V_38 ,
struct V_2 * V_3 ,
double V_74 ,
struct V_75 * V_76 )
{
double V_77 , V_63 = 0.0 ;
const char * V_69 ;
int V_4 = F_3 ( V_3 ) ;
V_77 = F_11 ( & V_22 [ V_4 ] [ V_38 ] ) ;
if ( V_77 )
V_63 = V_74 / V_77 * 100.0 ;
V_69 = F_9 ( V_68 , V_63 ) ;
V_76 -> V_78 ( V_76 -> V_4 , V_69 , L_3 , L_7 , V_63 ) ;
}
static void F_15 ( int V_38 ,
struct V_2 * V_3 ,
double V_74 ,
struct V_75 * V_76 )
{
double V_77 , V_63 = 0.0 ;
const char * V_69 ;
int V_4 = F_3 ( V_3 ) ;
V_77 = F_11 ( & V_23 [ V_4 ] [ V_38 ] ) ;
if ( V_77 )
V_63 = V_74 / V_77 * 100.0 ;
V_69 = F_9 ( V_68 , V_63 ) ;
V_76 -> V_78 ( V_76 -> V_4 , V_69 , L_3 , L_8 , V_63 ) ;
}
static void F_16 ( int V_38 ,
struct V_2 * V_3 ,
double V_74 ,
struct V_75 * V_76 )
{
double V_77 , V_63 = 0.0 ;
const char * V_69 ;
int V_4 = F_3 ( V_3 ) ;
V_77 = F_11 ( & V_26 [ V_4 ] [ V_38 ] ) ;
if ( V_77 )
V_63 = V_74 / V_77 * 100.0 ;
V_69 = F_9 ( V_68 , V_63 ) ;
V_76 -> V_78 ( V_76 -> V_4 , V_69 , L_3 , L_9 , V_63 ) ;
}
static void F_17 ( int V_38 ,
struct V_2 * V_3 ,
double V_74 ,
struct V_75 * V_76 )
{
double V_77 , V_63 = 0.0 ;
const char * V_69 ;
int V_4 = F_3 ( V_3 ) ;
V_77 = F_11 ( & V_25 [ V_4 ] [ V_38 ] ) ;
if ( V_77 )
V_63 = V_74 / V_77 * 100.0 ;
V_69 = F_9 ( V_68 , V_63 ) ;
V_76 -> V_78 ( V_76 -> V_4 , V_69 , L_3 , L_10 , V_63 ) ;
}
static void F_18 ( int V_38 ,
struct V_2 * V_3 ,
double V_74 ,
struct V_75 * V_76 )
{
double V_77 , V_63 = 0.0 ;
const char * V_69 ;
int V_4 = F_3 ( V_3 ) ;
V_77 = F_11 ( & V_24 [ V_4 ] [ V_38 ] ) ;
if ( V_77 )
V_63 = V_74 / V_77 * 100.0 ;
V_69 = F_9 ( V_68 , V_63 ) ;
V_76 -> V_78 ( V_76 -> V_4 , V_69 , L_3 , L_11 , V_63 ) ;
}
static double F_19 ( double V_79 )
{
if ( V_79 < 0 && V_79 >= - 0.02 )
return 0.0 ;
return V_79 ;
}
static double F_20 ( int V_4 , int V_38 )
{
return F_11 ( & V_31 [ V_4 ] [ V_38 ] ) ;
}
static double F_21 ( int V_4 , int V_38 )
{
double V_80 = 0 ;
double V_81 ;
double V_77 ;
V_77 = F_11 ( & V_33 [ V_4 ] [ V_38 ] ) -
F_11 ( & V_32 [ V_4 ] [ V_38 ] ) +
F_11 ( & V_35 [ V_4 ] [ V_38 ] ) ;
V_81 = F_20 ( V_4 , V_38 ) ;
if ( V_81 )
V_80 = V_77 / V_81 ;
return F_19 ( V_80 ) ;
}
static double F_22 ( int V_4 , int V_38 )
{
double V_82 = 0 ;
double V_81 = F_20 ( V_4 , V_38 ) ;
double V_83 = F_11 ( & V_32 [ V_4 ] [ V_38 ] ) ;
if ( V_81 )
V_82 = V_83 / V_81 ;
return V_82 ;
}
static double F_23 ( int V_4 , int V_38 )
{
double V_84 = 0 ;
double V_81 = F_20 ( V_4 , V_38 ) ;
double V_85 = F_11 ( & V_34 [ V_4 ] [ V_38 ] ) ;
if ( V_81 )
V_84 = V_85 / V_81 ;
return V_84 ;
}
static double F_24 ( int V_4 , int V_38 )
{
double V_86 = ( F_23 ( V_4 , V_38 ) +
F_21 ( V_4 , V_38 ) +
F_22 ( V_4 , V_38 ) ) ;
if ( V_86 == 0 )
return 0 ;
return F_19 ( 1.0 - V_86 ) ;
}
void F_25 ( struct V_2 * V_3 ,
double V_74 , int V_38 ,
struct V_75 * V_76 )
{
void * V_87 = V_76 -> V_4 ;
T_2 V_78 = V_76 -> V_78 ;
double V_77 , V_63 = 0.0 , V_88 ;
const char * V_69 = NULL ;
int V_4 = F_3 ( V_3 ) ;
if ( F_6 ( V_3 , V_42 , V_89 ) ) {
V_77 = F_11 ( & V_17 [ V_4 ] [ V_38 ] ) ;
if ( V_77 ) {
V_63 = V_74 / V_77 ;
V_78 ( V_87 , NULL , L_12 ,
L_13 , V_63 ) ;
} else {
V_78 ( V_87 , NULL , NULL , L_13 , 0 ) ;
}
V_77 = F_11 ( & V_18 [ V_4 ] [ V_38 ] ) ;
V_77 = F_26 ( V_77 , F_11 ( & V_19 [ V_4 ] [ V_38 ] ) ) ;
if ( V_77 && V_74 ) {
V_76 -> V_90 ( V_87 ) ;
V_63 = V_77 / V_74 ;
V_78 ( V_87 , NULL , L_12 ,
L_14 ,
V_63 ) ;
} else if ( V_1 ) {
V_78 ( V_87 , NULL , NULL ,
L_14 , 0 ) ;
}
} else if ( F_6 ( V_3 , V_42 , V_91 ) ) {
if ( V_20 [ V_4 ] [ V_38 ] . V_92 != 0 )
F_13 ( V_38 , V_3 , V_74 , V_76 ) ;
else
V_78 ( V_87 , NULL , NULL , L_6 , 0 ) ;
} else if (
V_3 -> V_5 . type == V_93 &&
V_3 -> V_5 . V_94 == ( V_95 |
( ( V_96 ) << 8 ) |
( ( V_97 ) << 16 ) ) ) {
if ( V_22 [ V_4 ] [ V_38 ] . V_92 != 0 )
F_14 ( V_38 , V_3 , V_74 , V_76 ) ;
else
V_78 ( V_87 , NULL , NULL , L_7 , 0 ) ;
} else if (
V_3 -> V_5 . type == V_93 &&
V_3 -> V_5 . V_94 == ( V_98 |
( ( V_96 ) << 8 ) |
( ( V_97 ) << 16 ) ) ) {
if ( V_23 [ V_4 ] [ V_38 ] . V_92 != 0 )
F_15 ( V_38 , V_3 , V_74 , V_76 ) ;
else
V_78 ( V_87 , NULL , NULL , L_8 , 0 ) ;
} else if (
V_3 -> V_5 . type == V_93 &&
V_3 -> V_5 . V_94 == ( V_99 |
( ( V_96 ) << 8 ) |
( ( V_97 ) << 16 ) ) ) {
if ( V_26 [ V_4 ] [ V_38 ] . V_92 != 0 )
F_16 ( V_38 , V_3 , V_74 , V_76 ) ;
else
V_78 ( V_87 , NULL , NULL , L_9 , 0 ) ;
} else if (
V_3 -> V_5 . type == V_93 &&
V_3 -> V_5 . V_94 == ( V_100 |
( ( V_96 ) << 8 ) |
( ( V_97 ) << 16 ) ) ) {
if ( V_25 [ V_4 ] [ V_38 ] . V_92 != 0 )
F_17 ( V_38 , V_3 , V_74 , V_76 ) ;
else
V_78 ( V_87 , NULL , NULL , L_10 , 0 ) ;
} else if (
V_3 -> V_5 . type == V_93 &&
V_3 -> V_5 . V_94 == ( V_101 |
( ( V_96 ) << 8 ) |
( ( V_97 ) << 16 ) ) ) {
if ( V_24 [ V_4 ] [ V_38 ] . V_92 != 0 )
F_18 ( V_38 , V_3 , V_74 , V_76 ) ;
else
V_78 ( V_87 , NULL , NULL , L_11 , 0 ) ;
} else if ( F_6 ( V_3 , V_42 , V_102 ) ) {
V_77 = F_11 ( & V_21 [ V_4 ] [ V_38 ] ) ;
if ( V_77 )
V_63 = V_74 * 100 / V_77 ;
if ( V_21 [ V_4 ] [ V_38 ] . V_92 != 0 )
V_78 ( V_87 , NULL , L_15 ,
L_16 , V_63 ) ;
else
V_78 ( V_87 , NULL , NULL , L_16 , 0 ) ;
} else if ( F_6 ( V_3 , V_42 , V_52 ) ) {
F_10 ( V_38 , V_3 , V_74 , V_76 ) ;
} else if ( F_6 ( V_3 , V_42 , V_53 ) ) {
F_12 ( V_38 , V_3 , V_74 , V_76 ) ;
} else if ( F_6 ( V_3 , V_42 , V_43 ) ) {
V_77 = F_11 ( & V_16 [ V_38 ] ) ;
if ( V_77 ) {
V_63 = V_74 / V_77 ;
V_78 ( V_87 , NULL , L_17 , L_18 , V_63 ) ;
} else {
V_78 ( V_87 , NULL , NULL , L_19 , 0 ) ;
}
} else if ( F_8 ( V_3 , V_44 ) ) {
V_77 = F_11 ( & V_17 [ V_4 ] [ V_38 ] ) ;
if ( V_77 )
V_78 ( V_87 , NULL ,
L_3 , L_20 ,
100.0 * ( V_74 / V_77 ) ) ;
else
V_78 ( V_87 , NULL , NULL , L_20 ,
0 ) ;
} else if ( F_8 ( V_3 , V_103 ) ) {
V_77 = F_11 ( & V_17 [ V_4 ] [ V_38 ] ) ;
V_88 = F_11 ( & V_27 [ V_4 ] [ V_38 ] ) ;
if ( V_88 < V_74 )
V_88 = V_74 ;
if ( V_77 )
V_78 ( V_87 , NULL , L_3 , L_21 ,
100.0 * ( ( V_88 - V_74 ) / V_77 ) ) ;
else
V_78 ( V_87 , NULL , NULL , L_21 , 0 ) ;
} else if ( F_8 ( V_3 , V_45 ) ) {
V_77 = F_11 ( & V_27 [ V_4 ] [ V_38 ] ) ;
if ( V_74 )
V_63 = V_77 / V_74 ;
if ( V_27 [ V_4 ] [ V_38 ] . V_92 != 0 )
V_78 ( V_87 , NULL , L_22 ,
L_23 , V_63 ) ;
else
V_78 ( V_87 , NULL , NULL , L_23 ,
0 ) ;
} else if ( F_8 ( V_3 , V_46 ) ) {
V_77 = F_11 ( & V_27 [ V_4 ] [ V_38 ] ) ;
if ( V_74 )
V_63 = V_77 / V_74 ;
V_78 ( V_87 , NULL , L_22 , L_24 , V_63 ) ;
} else if ( F_6 ( V_3 , V_39 , V_40 ) ||
F_6 ( V_3 , V_39 , V_41 ) ) {
if ( ( V_63 = F_11 ( & V_30 ) ) != 0 )
V_78 ( V_87 , NULL , L_17 , L_25 ,
V_74 / V_63 ) ;
else
V_78 ( V_87 , NULL , NULL , L_25 , 0 ) ;
} else if ( F_8 ( V_3 , V_50 ) ) {
double V_84 = F_23 ( V_4 , V_38 ) ;
if ( V_84 > 0.2 )
V_69 = V_71 ;
V_78 ( V_87 , V_69 , L_26 , L_27 ,
V_84 * 100. ) ;
} else if ( F_8 ( V_3 , V_49 ) ) {
double V_82 = F_22 ( V_4 , V_38 ) ;
if ( V_82 > 0.7 )
V_69 = V_104 ;
V_78 ( V_87 , V_69 , L_26 , L_28 ,
V_82 * 100. ) ;
} else if ( F_8 ( V_3 , V_51 ) ) {
double V_80 = F_21 ( V_4 , V_38 ) ;
if ( V_80 > 0.1 )
V_69 = V_71 ;
V_78 ( V_87 , V_69 , L_26 , L_29 ,
V_80 * 100. ) ;
} else if ( F_8 ( V_3 , V_48 ) ) {
double V_105 = F_24 ( V_4 , V_38 ) ;
const char * V_106 = L_30 ;
static int V_107 = - 1 ;
if ( V_107 < 0 )
V_107 = F_2 ( L_1 ,
L_31 ) ;
if ( ! V_107 )
V_106 = L_32 ;
if ( V_105 > 0.2 )
V_69 = V_71 ;
if ( F_20 ( V_4 , V_38 ) > 0 )
V_78 ( V_87 , V_69 , L_26 , V_106 ,
V_105 * 100. ) ;
else
V_78 ( V_87 , NULL , NULL , V_106 , 0 ) ;
} else if ( V_16 [ V_38 ] . V_92 != 0 ) {
char V_108 = 'M' ;
char V_109 [ 10 ] ;
V_77 = F_11 ( & V_16 [ V_38 ] ) ;
if ( V_77 )
V_63 = 1000.0 * V_74 / V_77 ;
if ( V_63 < 0.001 ) {
V_63 *= 1000 ;
V_108 = 'K' ;
}
snprintf ( V_109 , sizeof( V_109 ) , L_33 , V_108 ) ;
V_78 ( V_87 , NULL , L_17 , V_109 , V_63 ) ;
} else {
V_78 ( V_87 , NULL , NULL , NULL , 0 ) ;
}
}
