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
}
void F_5 ( struct V_2 * V_31 , T_1 * V_32 ,
int V_33 )
{
int V_4 = F_3 ( V_31 ) ;
if ( F_6 ( V_31 , V_34 , V_35 ) ||
F_6 ( V_31 , V_34 , V_36 ) )
F_7 ( & V_16 [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_37 , V_38 ) )
F_7 ( & V_17 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_8 ( V_31 , V_39 ) )
F_7 ( & V_27 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_8 ( V_31 , V_40 ) )
F_7 ( & V_28 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_8 ( V_31 , V_41 ) )
F_7 ( & V_29 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_37 , V_42 ) )
F_7 ( & V_18 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_37 , V_43 ) )
F_7 ( & V_19 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_37 , V_44 ) )
F_7 ( & V_20 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_37 , V_45 ) )
F_7 ( & V_21 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_46 , V_47 ) )
F_7 ( & V_22 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_46 , V_48 ) )
F_7 ( & V_24 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_46 , V_49 ) )
F_7 ( & V_24 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_46 , V_50 ) )
F_7 ( & V_26 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_46 , V_51 ) )
F_7 ( & V_25 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
}
static const char * F_9 ( enum V_52 type , double V_53 )
{
static const double V_54 [ V_55 ] [ 3 ] = {
[ V_56 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_57 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_58 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_59 = V_60 ;
if ( V_53 > V_54 [ type ] [ 0 ] )
V_59 = V_61 ;
else if ( V_53 > V_54 [ type ] [ 1 ] )
V_59 = V_62 ;
else if ( V_53 > V_54 [ type ] [ 2 ] )
V_59 = V_63 ;
return V_59 ;
}
static void F_10 ( int V_33 ,
struct V_2 * V_3 , double V_64 ,
struct V_65 * V_66 )
{
double V_67 , V_53 = 0.0 ;
const char * V_59 ;
int V_4 = F_3 ( V_3 ) ;
V_67 = F_11 ( & V_17 [ V_4 ] [ V_33 ] ) ;
if ( V_67 )
V_53 = V_64 / V_67 * 100.0 ;
V_59 = F_9 ( V_56 , V_53 ) ;
if ( V_53 )
V_66 -> V_68 ( V_66 -> V_4 , V_59 , L_3 , L_4 ,
V_53 ) ;
else
V_66 -> V_68 ( V_66 -> V_4 , NULL , NULL , L_4 , 0 ) ;
}
static void F_12 ( int V_33 ,
struct V_2 * V_3 , double V_64 ,
struct V_65 * V_66 )
{
double V_67 , V_53 = 0.0 ;
const char * V_59 ;
int V_4 = F_3 ( V_3 ) ;
V_67 = F_11 ( & V_17 [ V_4 ] [ V_33 ] ) ;
if ( V_67 )
V_53 = V_64 / V_67 * 100.0 ;
V_59 = F_9 ( V_57 , V_53 ) ;
V_66 -> V_68 ( V_66 -> V_4 , V_59 , L_3 , L_5 , V_53 ) ;
}
static void F_13 ( int V_33 ,
struct V_2 * V_3 ,
double V_64 ,
struct V_65 * V_66 )
{
double V_67 , V_53 = 0.0 ;
const char * V_59 ;
int V_4 = F_3 ( V_3 ) ;
V_67 = F_11 ( & V_20 [ V_4 ] [ V_33 ] ) ;
if ( V_67 )
V_53 = V_64 / V_67 * 100.0 ;
V_59 = F_9 ( V_58 , V_53 ) ;
V_66 -> V_68 ( V_66 -> V_4 , V_59 , L_3 , L_6 , V_53 ) ;
}
static void F_14 ( int V_33 ,
struct V_2 * V_3 ,
double V_64 ,
struct V_65 * V_66 )
{
double V_67 , V_53 = 0.0 ;
const char * V_59 ;
int V_4 = F_3 ( V_3 ) ;
V_67 = F_11 ( & V_22 [ V_4 ] [ V_33 ] ) ;
if ( V_67 )
V_53 = V_64 / V_67 * 100.0 ;
V_59 = F_9 ( V_58 , V_53 ) ;
V_66 -> V_68 ( V_66 -> V_4 , V_59 , L_3 , L_7 , V_53 ) ;
}
static void F_15 ( int V_33 ,
struct V_2 * V_3 ,
double V_64 ,
struct V_65 * V_66 )
{
double V_67 , V_53 = 0.0 ;
const char * V_59 ;
int V_4 = F_3 ( V_3 ) ;
V_67 = F_11 ( & V_23 [ V_4 ] [ V_33 ] ) ;
if ( V_67 )
V_53 = V_64 / V_67 * 100.0 ;
V_59 = F_9 ( V_58 , V_53 ) ;
V_66 -> V_68 ( V_66 -> V_4 , V_59 , L_3 , L_8 , V_53 ) ;
}
static void F_16 ( int V_33 ,
struct V_2 * V_3 ,
double V_64 ,
struct V_65 * V_66 )
{
double V_67 , V_53 = 0.0 ;
const char * V_59 ;
int V_4 = F_3 ( V_3 ) ;
V_67 = F_11 ( & V_26 [ V_4 ] [ V_33 ] ) ;
if ( V_67 )
V_53 = V_64 / V_67 * 100.0 ;
V_59 = F_9 ( V_58 , V_53 ) ;
V_66 -> V_68 ( V_66 -> V_4 , V_59 , L_3 , L_9 , V_53 ) ;
}
static void F_17 ( int V_33 ,
struct V_2 * V_3 ,
double V_64 ,
struct V_65 * V_66 )
{
double V_67 , V_53 = 0.0 ;
const char * V_59 ;
int V_4 = F_3 ( V_3 ) ;
V_67 = F_11 ( & V_25 [ V_4 ] [ V_33 ] ) ;
if ( V_67 )
V_53 = V_64 / V_67 * 100.0 ;
V_59 = F_9 ( V_58 , V_53 ) ;
V_66 -> V_68 ( V_66 -> V_4 , V_59 , L_3 , L_10 , V_53 ) ;
}
static void F_18 ( int V_33 ,
struct V_2 * V_3 ,
double V_64 ,
struct V_65 * V_66 )
{
double V_67 , V_53 = 0.0 ;
const char * V_59 ;
int V_4 = F_3 ( V_3 ) ;
V_67 = F_11 ( & V_24 [ V_4 ] [ V_33 ] ) ;
if ( V_67 )
V_53 = V_64 / V_67 * 100.0 ;
V_59 = F_9 ( V_58 , V_53 ) ;
V_66 -> V_68 ( V_66 -> V_4 , V_59 , L_3 , L_11 , V_53 ) ;
}
void F_19 ( struct V_2 * V_3 ,
double V_64 , int V_33 ,
struct V_65 * V_66 )
{
void * V_69 = V_66 -> V_4 ;
T_2 V_68 = V_66 -> V_68 ;
double V_67 , V_53 = 0.0 , V_70 ;
int V_4 = F_3 ( V_3 ) ;
if ( F_6 ( V_3 , V_37 , V_71 ) ) {
V_67 = F_11 ( & V_17 [ V_4 ] [ V_33 ] ) ;
if ( V_67 ) {
V_53 = V_64 / V_67 ;
V_68 ( V_69 , NULL , L_12 ,
L_13 , V_53 ) ;
} else {
V_68 ( V_69 , NULL , NULL , L_13 , 0 ) ;
}
V_67 = F_11 ( & V_18 [ V_4 ] [ V_33 ] ) ;
V_67 = F_20 ( V_67 , F_11 ( & V_19 [ V_4 ] [ V_33 ] ) ) ;
if ( V_67 && V_64 ) {
V_66 -> V_72 ( V_69 ) ;
V_53 = V_67 / V_64 ;
V_68 ( V_69 , NULL , L_12 ,
L_14 ,
V_53 ) ;
} else if ( V_1 ) {
V_68 ( V_69 , NULL , NULL ,
L_14 , 0 ) ;
}
} else if ( F_6 ( V_3 , V_37 , V_73 ) ) {
if ( V_20 [ V_4 ] [ V_33 ] . V_74 != 0 )
F_13 ( V_33 , V_3 , V_64 , V_66 ) ;
else
V_68 ( V_69 , NULL , NULL , L_6 , 0 ) ;
} else if (
V_3 -> V_5 . type == V_75 &&
V_3 -> V_5 . V_76 == ( V_77 |
( ( V_78 ) << 8 ) |
( ( V_79 ) << 16 ) ) ) {
if ( V_22 [ V_4 ] [ V_33 ] . V_74 != 0 )
F_14 ( V_33 , V_3 , V_64 , V_66 ) ;
else
V_68 ( V_69 , NULL , NULL , L_7 , 0 ) ;
} else if (
V_3 -> V_5 . type == V_75 &&
V_3 -> V_5 . V_76 == ( V_80 |
( ( V_78 ) << 8 ) |
( ( V_79 ) << 16 ) ) ) {
if ( V_23 [ V_4 ] [ V_33 ] . V_74 != 0 )
F_15 ( V_33 , V_3 , V_64 , V_66 ) ;
else
V_68 ( V_69 , NULL , NULL , L_8 , 0 ) ;
} else if (
V_3 -> V_5 . type == V_75 &&
V_3 -> V_5 . V_76 == ( V_81 |
( ( V_78 ) << 8 ) |
( ( V_79 ) << 16 ) ) ) {
if ( V_26 [ V_4 ] [ V_33 ] . V_74 != 0 )
F_16 ( V_33 , V_3 , V_64 , V_66 ) ;
else
V_68 ( V_69 , NULL , NULL , L_9 , 0 ) ;
} else if (
V_3 -> V_5 . type == V_75 &&
V_3 -> V_5 . V_76 == ( V_82 |
( ( V_78 ) << 8 ) |
( ( V_79 ) << 16 ) ) ) {
if ( V_25 [ V_4 ] [ V_33 ] . V_74 != 0 )
F_17 ( V_33 , V_3 , V_64 , V_66 ) ;
else
V_68 ( V_69 , NULL , NULL , L_10 , 0 ) ;
} else if (
V_3 -> V_5 . type == V_75 &&
V_3 -> V_5 . V_76 == ( V_83 |
( ( V_78 ) << 8 ) |
( ( V_79 ) << 16 ) ) ) {
if ( V_24 [ V_4 ] [ V_33 ] . V_74 != 0 )
F_18 ( V_33 , V_3 , V_64 , V_66 ) ;
else
V_68 ( V_69 , NULL , NULL , L_11 , 0 ) ;
} else if ( F_6 ( V_3 , V_37 , V_84 ) ) {
V_67 = F_11 ( & V_21 [ V_4 ] [ V_33 ] ) ;
if ( V_67 )
V_53 = V_64 * 100 / V_67 ;
if ( V_21 [ V_4 ] [ V_33 ] . V_74 != 0 )
V_68 ( V_69 , NULL , L_15 ,
L_16 , V_53 ) ;
else
V_68 ( V_69 , NULL , NULL , L_16 , 0 ) ;
} else if ( F_6 ( V_3 , V_37 , V_42 ) ) {
F_10 ( V_33 , V_3 , V_64 , V_66 ) ;
} else if ( F_6 ( V_3 , V_37 , V_43 ) ) {
F_12 ( V_33 , V_3 , V_64 , V_66 ) ;
} else if ( F_6 ( V_3 , V_37 , V_38 ) ) {
V_67 = F_11 ( & V_16 [ V_33 ] ) ;
if ( V_67 ) {
V_53 = V_64 / V_67 ;
V_68 ( V_69 , NULL , L_17 , L_18 , V_53 ) ;
} else {
V_68 ( V_69 , NULL , NULL , L_19 , 0 ) ;
}
} else if ( F_8 ( V_3 , V_39 ) ) {
V_67 = F_11 ( & V_17 [ V_4 ] [ V_33 ] ) ;
if ( V_67 )
V_68 ( V_69 , NULL ,
L_3 , L_20 ,
100.0 * ( V_64 / V_67 ) ) ;
else
V_68 ( V_69 , NULL , NULL , L_20 ,
0 ) ;
} else if ( F_8 ( V_3 , V_85 ) ) {
V_67 = F_11 ( & V_17 [ V_4 ] [ V_33 ] ) ;
V_70 = F_11 ( & V_27 [ V_4 ] [ V_33 ] ) ;
if ( V_70 < V_64 )
V_70 = V_64 ;
if ( V_67 )
V_68 ( V_69 , NULL , L_3 , L_21 ,
100.0 * ( ( V_70 - V_64 ) / V_67 ) ) ;
else
V_68 ( V_69 , NULL , NULL , L_21 , 0 ) ;
} else if ( F_8 ( V_3 , V_40 ) ) {
V_67 = F_11 ( & V_27 [ V_4 ] [ V_33 ] ) ;
if ( V_64 )
V_53 = V_67 / V_64 ;
if ( V_27 [ V_4 ] [ V_33 ] . V_74 != 0 )
V_68 ( V_69 , NULL , L_22 ,
L_23 , V_53 ) ;
else
V_68 ( V_69 , NULL , NULL , L_23 ,
0 ) ;
} else if ( F_8 ( V_3 , V_41 ) ) {
V_67 = F_11 ( & V_27 [ V_4 ] [ V_33 ] ) ;
if ( V_64 )
V_53 = V_67 / V_64 ;
V_68 ( V_69 , NULL , L_22 , L_24 , V_53 ) ;
} else if ( F_6 ( V_3 , V_34 , V_35 ) ||
F_6 ( V_3 , V_34 , V_36 ) ) {
if ( ( V_53 = F_11 ( & V_30 ) ) != 0 )
V_68 ( V_69 , NULL , L_17 , L_25 ,
V_64 / V_53 ) ;
else
V_68 ( V_69 , NULL , NULL , L_25 , 0 ) ;
} else if ( V_16 [ V_33 ] . V_74 != 0 ) {
char V_86 = 'M' ;
char V_87 [ 10 ] ;
V_67 = F_11 ( & V_16 [ V_33 ] ) ;
if ( V_67 )
V_53 = 1000.0 * V_64 / V_67 ;
if ( V_53 < 0.001 ) {
V_53 *= 1000 ;
V_86 = 'K' ;
}
snprintf ( V_87 , sizeof( V_87 ) , L_26 , V_86 ) ;
V_68 ( V_69 , NULL , L_17 , V_87 , V_53 ) ;
} else {
V_68 ( V_69 , NULL , NULL , NULL , 0 ) ;
}
}
