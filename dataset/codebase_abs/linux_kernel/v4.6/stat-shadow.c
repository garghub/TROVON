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
if ( F_6 ( V_31 , V_34 , V_35 ) )
F_7 ( & V_16 [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_36 , V_37 ) )
F_7 ( & V_17 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_8 ( V_31 , V_38 ) )
F_7 ( & V_27 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_8 ( V_31 , V_39 ) )
F_7 ( & V_28 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_8 ( V_31 , V_40 ) )
F_7 ( & V_29 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_36 , V_41 ) )
F_7 ( & V_18 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_36 , V_42 ) )
F_7 ( & V_19 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_36 , V_43 ) )
F_7 ( & V_20 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_36 , V_44 ) )
F_7 ( & V_21 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_45 , V_46 ) )
F_7 ( & V_22 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_45 , V_47 ) )
F_7 ( & V_24 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_45 , V_48 ) )
F_7 ( & V_24 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_45 , V_49 ) )
F_7 ( & V_26 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
else if ( F_6 ( V_31 , V_45 , V_50 ) )
F_7 ( & V_25 [ V_4 ] [ V_33 ] , V_32 [ 0 ] ) ;
}
static const char * F_9 ( enum V_51 type , double V_52 )
{
static const double V_53 [ V_54 ] [ 3 ] = {
[ V_55 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_56 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_57 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_58 = V_59 ;
if ( V_52 > V_53 [ type ] [ 0 ] )
V_58 = V_60 ;
else if ( V_52 > V_53 [ type ] [ 1 ] )
V_58 = V_61 ;
else if ( V_52 > V_53 [ type ] [ 2 ] )
V_58 = V_62 ;
return V_58 ;
}
static void F_10 ( int V_33 ,
struct V_2 * V_3 , double V_63 ,
struct V_64 * V_65 )
{
double V_66 , V_52 = 0.0 ;
const char * V_58 ;
int V_4 = F_3 ( V_3 ) ;
V_66 = F_11 ( & V_17 [ V_4 ] [ V_33 ] ) ;
if ( V_66 )
V_52 = V_63 / V_66 * 100.0 ;
V_58 = F_9 ( V_55 , V_52 ) ;
if ( V_52 )
V_65 -> V_67 ( V_65 -> V_4 , V_58 , L_3 , L_4 ,
V_52 ) ;
else
V_65 -> V_67 ( V_65 -> V_4 , NULL , NULL , L_4 , 0 ) ;
}
static void F_12 ( int V_33 ,
struct V_2 * V_3 , double V_63 ,
struct V_64 * V_65 )
{
double V_66 , V_52 = 0.0 ;
const char * V_58 ;
int V_4 = F_3 ( V_3 ) ;
V_66 = F_11 ( & V_17 [ V_4 ] [ V_33 ] ) ;
if ( V_66 )
V_52 = V_63 / V_66 * 100.0 ;
V_58 = F_9 ( V_56 , V_52 ) ;
V_65 -> V_67 ( V_65 -> V_4 , V_58 , L_5 , L_6 , V_52 ) ;
}
static void F_13 ( int V_33 ,
struct V_2 * V_3 ,
double V_63 ,
struct V_64 * V_65 )
{
double V_66 , V_52 = 0.0 ;
const char * V_58 ;
int V_4 = F_3 ( V_3 ) ;
V_66 = F_11 ( & V_20 [ V_4 ] [ V_33 ] ) ;
if ( V_66 )
V_52 = V_63 / V_66 * 100.0 ;
V_58 = F_9 ( V_57 , V_52 ) ;
V_65 -> V_67 ( V_65 -> V_4 , V_58 , L_3 , L_7 , V_52 ) ;
}
static void F_14 ( int V_33 ,
struct V_2 * V_3 ,
double V_63 ,
struct V_64 * V_65 )
{
double V_66 , V_52 = 0.0 ;
const char * V_58 ;
int V_4 = F_3 ( V_3 ) ;
V_66 = F_11 ( & V_22 [ V_4 ] [ V_33 ] ) ;
if ( V_66 )
V_52 = V_63 / V_66 * 100.0 ;
V_58 = F_9 ( V_57 , V_52 ) ;
V_65 -> V_67 ( V_65 -> V_4 , V_58 , L_3 , L_8 , V_52 ) ;
}
static void F_15 ( int V_33 ,
struct V_2 * V_3 ,
double V_63 ,
struct V_64 * V_65 )
{
double V_66 , V_52 = 0.0 ;
const char * V_58 ;
int V_4 = F_3 ( V_3 ) ;
V_66 = F_11 ( & V_23 [ V_4 ] [ V_33 ] ) ;
if ( V_66 )
V_52 = V_63 / V_66 * 100.0 ;
V_58 = F_9 ( V_57 , V_52 ) ;
V_65 -> V_67 ( V_65 -> V_4 , V_58 , L_3 , L_9 , V_52 ) ;
}
static void F_16 ( int V_33 ,
struct V_2 * V_3 ,
double V_63 ,
struct V_64 * V_65 )
{
double V_66 , V_52 = 0.0 ;
const char * V_58 ;
int V_4 = F_3 ( V_3 ) ;
V_66 = F_11 ( & V_26 [ V_4 ] [ V_33 ] ) ;
if ( V_66 )
V_52 = V_63 / V_66 * 100.0 ;
V_58 = F_9 ( V_57 , V_52 ) ;
V_65 -> V_67 ( V_65 -> V_4 , V_58 , L_3 , L_10 , V_52 ) ;
}
static void F_17 ( int V_33 ,
struct V_2 * V_3 ,
double V_63 ,
struct V_64 * V_65 )
{
double V_66 , V_52 = 0.0 ;
const char * V_58 ;
int V_4 = F_3 ( V_3 ) ;
V_66 = F_11 ( & V_25 [ V_4 ] [ V_33 ] ) ;
if ( V_66 )
V_52 = V_63 / V_66 * 100.0 ;
V_58 = F_9 ( V_57 , V_52 ) ;
V_65 -> V_67 ( V_65 -> V_4 , V_58 , L_3 , L_11 , V_52 ) ;
}
static void F_18 ( int V_33 ,
struct V_2 * V_3 ,
double V_63 ,
struct V_64 * V_65 )
{
double V_66 , V_52 = 0.0 ;
const char * V_58 ;
int V_4 = F_3 ( V_3 ) ;
V_66 = F_11 ( & V_24 [ V_4 ] [ V_33 ] ) ;
if ( V_66 )
V_52 = V_63 / V_66 * 100.0 ;
V_58 = F_9 ( V_57 , V_52 ) ;
V_65 -> V_67 ( V_65 -> V_4 , V_58 , L_3 , L_12 , V_52 ) ;
}
void F_19 ( struct V_2 * V_3 ,
double V_63 , int V_33 ,
struct V_64 * V_65 )
{
void * V_68 = V_65 -> V_4 ;
T_2 V_67 = V_65 -> V_67 ;
double V_66 , V_52 = 0.0 , V_69 ;
int V_4 = F_3 ( V_3 ) ;
if ( F_6 ( V_3 , V_36 , V_70 ) ) {
V_66 = F_11 ( & V_17 [ V_4 ] [ V_33 ] ) ;
if ( V_66 ) {
V_52 = V_63 / V_66 ;
V_67 ( V_68 , NULL , L_13 ,
L_14 , V_52 ) ;
} else {
V_67 ( V_68 , NULL , NULL , L_14 , 0 ) ;
}
V_66 = F_11 ( & V_18 [ V_4 ] [ V_33 ] ) ;
V_66 = F_20 ( V_66 , F_11 ( & V_19 [ V_4 ] [ V_33 ] ) ) ;
if ( V_66 && V_63 ) {
V_65 -> V_71 ( V_68 ) ;
V_52 = V_66 / V_63 ;
V_67 ( V_68 , NULL , L_13 ,
L_15 ,
V_52 ) ;
} else if ( V_1 ) {
V_67 ( V_68 , NULL , NULL ,
L_15 , 0 ) ;
}
} else if ( F_6 ( V_3 , V_36 , V_72 ) ) {
if ( V_20 [ V_4 ] [ V_33 ] . V_73 != 0 )
F_13 ( V_33 , V_3 , V_63 , V_65 ) ;
else
V_67 ( V_68 , NULL , NULL , L_7 , 0 ) ;
} else if (
V_3 -> V_5 . type == V_74 &&
V_3 -> V_5 . V_75 == ( V_76 |
( ( V_77 ) << 8 ) |
( ( V_78 ) << 16 ) ) ) {
if ( V_22 [ V_4 ] [ V_33 ] . V_73 != 0 )
F_14 ( V_33 , V_3 , V_63 , V_65 ) ;
else
V_67 ( V_68 , NULL , NULL , L_8 , 0 ) ;
} else if (
V_3 -> V_5 . type == V_74 &&
V_3 -> V_5 . V_75 == ( V_79 |
( ( V_77 ) << 8 ) |
( ( V_78 ) << 16 ) ) ) {
if ( V_23 [ V_4 ] [ V_33 ] . V_73 != 0 )
F_15 ( V_33 , V_3 , V_63 , V_65 ) ;
else
V_67 ( V_68 , NULL , NULL , L_9 , 0 ) ;
} else if (
V_3 -> V_5 . type == V_74 &&
V_3 -> V_5 . V_75 == ( V_80 |
( ( V_77 ) << 8 ) |
( ( V_78 ) << 16 ) ) ) {
if ( V_26 [ V_4 ] [ V_33 ] . V_73 != 0 )
F_16 ( V_33 , V_3 , V_63 , V_65 ) ;
else
V_67 ( V_68 , NULL , NULL , L_10 , 0 ) ;
} else if (
V_3 -> V_5 . type == V_74 &&
V_3 -> V_5 . V_75 == ( V_81 |
( ( V_77 ) << 8 ) |
( ( V_78 ) << 16 ) ) ) {
if ( V_25 [ V_4 ] [ V_33 ] . V_73 != 0 )
F_17 ( V_33 , V_3 , V_63 , V_65 ) ;
else
V_67 ( V_68 , NULL , NULL , L_11 , 0 ) ;
} else if (
V_3 -> V_5 . type == V_74 &&
V_3 -> V_5 . V_75 == ( V_82 |
( ( V_77 ) << 8 ) |
( ( V_78 ) << 16 ) ) ) {
if ( V_24 [ V_4 ] [ V_33 ] . V_73 != 0 )
F_18 ( V_33 , V_3 , V_63 , V_65 ) ;
else
V_67 ( V_68 , NULL , NULL , L_12 , 0 ) ;
} else if ( F_6 ( V_3 , V_36 , V_83 ) ) {
V_66 = F_11 ( & V_21 [ V_4 ] [ V_33 ] ) ;
if ( V_66 )
V_52 = V_63 * 100 / V_66 ;
if ( V_21 [ V_4 ] [ V_33 ] . V_73 != 0 )
V_67 ( V_68 , NULL , L_16 ,
L_17 , V_52 ) ;
else
V_67 ( V_68 , NULL , NULL , L_17 , 0 ) ;
} else if ( F_6 ( V_3 , V_36 , V_41 ) ) {
F_10 ( V_33 , V_3 , V_63 , V_65 ) ;
} else if ( F_6 ( V_3 , V_36 , V_42 ) ) {
F_12 ( V_33 , V_3 , V_63 , V_65 ) ;
} else if ( F_6 ( V_3 , V_36 , V_37 ) ) {
V_66 = F_11 ( & V_16 [ V_33 ] ) ;
if ( V_66 ) {
V_52 = V_63 / V_66 ;
V_67 ( V_68 , NULL , L_18 , L_19 , V_52 ) ;
} else {
V_67 ( V_68 , NULL , NULL , L_20 , 0 ) ;
}
} else if ( F_8 ( V_3 , V_38 ) ) {
V_66 = F_11 ( & V_17 [ V_4 ] [ V_33 ] ) ;
if ( V_66 )
V_67 ( V_68 , NULL ,
L_3 , L_21 ,
100.0 * ( V_63 / V_66 ) ) ;
else
V_67 ( V_68 , NULL , NULL , L_21 ,
0 ) ;
} else if ( F_8 ( V_3 , V_84 ) ) {
V_66 = F_11 ( & V_17 [ V_4 ] [ V_33 ] ) ;
V_69 = F_11 ( & V_27 [ V_4 ] [ V_33 ] ) ;
if ( V_69 < V_63 )
V_69 = V_63 ;
if ( V_66 )
V_67 ( V_68 , NULL , L_3 , L_22 ,
100.0 * ( ( V_69 - V_63 ) / V_66 ) ) ;
else
V_67 ( V_68 , NULL , NULL , L_22 , 0 ) ;
} else if ( F_8 ( V_3 , V_39 ) ) {
V_66 = F_11 ( & V_27 [ V_4 ] [ V_33 ] ) ;
if ( V_63 )
V_52 = V_66 / V_63 ;
if ( V_27 [ V_4 ] [ V_33 ] . V_73 != 0 )
V_67 ( V_68 , NULL , L_23 ,
L_24 , V_52 ) ;
else
V_67 ( V_68 , NULL , NULL , L_24 ,
0 ) ;
} else if ( F_8 ( V_3 , V_40 ) ) {
V_66 = F_11 ( & V_27 [ V_4 ] [ V_33 ] ) ;
if ( V_63 )
V_52 = V_66 / V_63 ;
V_67 ( V_68 , NULL , L_23 , L_25 , V_52 ) ;
} else if ( F_6 ( V_3 , V_34 , V_35 ) ) {
if ( ( V_52 = F_11 ( & V_30 ) ) != 0 )
V_67 ( V_68 , NULL , L_18 , L_26 ,
V_63 / V_52 ) ;
else
V_67 ( V_68 , NULL , NULL , L_26 , 0 ) ;
} else if ( V_16 [ V_33 ] . V_73 != 0 ) {
char V_85 = 'M' ;
char V_86 [ 10 ] ;
V_66 = F_11 ( & V_16 [ V_33 ] ) ;
if ( V_66 )
V_52 = 1000.0 * V_63 / V_66 ;
if ( V_52 < 0.001 ) {
V_52 *= 1000 ;
V_85 = 'K' ;
}
snprintf ( V_86 , sizeof( V_86 ) , L_27 , V_85 ) ;
V_67 ( V_68 , NULL , L_18 , V_86 , V_52 ) ;
} else {
V_67 ( V_68 , NULL , NULL , NULL , 0 ) ;
}
}
