static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_4 . V_5 )
V_3 |= V_6 ;
if ( V_2 -> V_4 . V_7 )
V_3 |= V_8 ;
if ( V_2 -> V_4 . V_9 )
V_3 |= V_10 ;
if ( V_2 -> V_4 . V_11 )
V_3 |= V_12 ;
if ( V_2 -> V_4 . V_13 )
V_3 |= V_14 ;
return V_3 ;
}
void F_2 ( void )
{
memset ( V_15 , 0 , sizeof( V_15 ) ) ;
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
memset ( V_26 , 0 ,
sizeof( V_26 ) ) ;
memset ( V_27 , 0 ,
sizeof( V_27 ) ) ;
memset ( V_28 , 0 , sizeof( V_28 ) ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
}
void F_3 ( struct V_1 * V_30 , T_1 * V_31 ,
int V_32 )
{
int V_3 = F_1 ( V_30 ) ;
if ( F_4 ( V_30 , V_33 , V_34 ) )
F_5 ( & V_15 [ V_32 ] , V_31 [ 0 ] ) ;
else if ( F_4 ( V_30 , V_35 , V_36 ) )
F_5 ( & V_16 [ V_3 ] [ V_32 ] , V_31 [ 0 ] ) ;
else if ( F_6 ( V_30 , V_37 ) )
F_5 ( & V_26 [ V_3 ] [ V_32 ] , V_31 [ 0 ] ) ;
else if ( F_6 ( V_30 , V_38 ) )
F_5 ( & V_27 [ V_3 ] [ V_32 ] , V_31 [ 0 ] ) ;
else if ( F_6 ( V_30 , V_39 ) )
F_5 ( & V_28 [ V_3 ] [ V_32 ] , V_31 [ 0 ] ) ;
else if ( F_4 ( V_30 , V_35 , V_40 ) )
F_5 ( & V_17 [ V_3 ] [ V_32 ] , V_31 [ 0 ] ) ;
else if ( F_4 ( V_30 , V_35 , V_41 ) )
F_5 ( & V_18 [ V_3 ] [ V_32 ] , V_31 [ 0 ] ) ;
else if ( F_4 ( V_30 , V_35 , V_42 ) )
F_5 ( & V_19 [ V_3 ] [ V_32 ] , V_31 [ 0 ] ) ;
else if ( F_4 ( V_30 , V_35 , V_43 ) )
F_5 ( & V_20 [ V_3 ] [ V_32 ] , V_31 [ 0 ] ) ;
else if ( F_4 ( V_30 , V_44 , V_45 ) )
F_5 ( & V_21 [ V_3 ] [ V_32 ] , V_31 [ 0 ] ) ;
else if ( F_4 ( V_30 , V_44 , V_46 ) )
F_5 ( & V_23 [ V_3 ] [ V_32 ] , V_31 [ 0 ] ) ;
else if ( F_4 ( V_30 , V_44 , V_47 ) )
F_5 ( & V_23 [ V_3 ] [ V_32 ] , V_31 [ 0 ] ) ;
else if ( F_4 ( V_30 , V_44 , V_48 ) )
F_5 ( & V_25 [ V_3 ] [ V_32 ] , V_31 [ 0 ] ) ;
else if ( F_4 ( V_30 , V_44 , V_49 ) )
F_5 ( & V_24 [ V_3 ] [ V_32 ] , V_31 [ 0 ] ) ;
}
static const char * F_7 ( enum V_50 type , double V_51 )
{
static const double V_52 [ V_53 ] [ 3 ] = {
[ V_54 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_55 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_56 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_57 = V_58 ;
if ( V_51 > V_52 [ type ] [ 0 ] )
V_57 = V_59 ;
else if ( V_51 > V_52 [ type ] [ 1 ] )
V_57 = V_60 ;
else if ( V_51 > V_52 [ type ] [ 2 ] )
V_57 = V_61 ;
return V_57 ;
}
static void F_8 ( T_2 * V_62 , int V_32 ,
struct V_1 * V_2
V_63 , double V_64 )
{
double V_65 , V_51 = 0.0 ;
const char * V_57 ;
int V_3 = F_1 ( V_2 ) ;
V_65 = F_9 ( & V_16 [ V_3 ] [ V_32 ] ) ;
if ( V_65 )
V_51 = V_64 / V_65 * 100.0 ;
V_57 = F_7 ( V_54 , V_51 ) ;
fprintf ( V_62 , L_1 ) ;
F_10 ( V_62 , V_57 , L_2 , V_51 ) ;
fprintf ( V_62 , L_3 ) ;
}
static void F_11 ( T_2 * V_62 , int V_32 ,
struct V_1 * V_2
V_63 , double V_64 )
{
double V_65 , V_51 = 0.0 ;
const char * V_57 ;
int V_3 = F_1 ( V_2 ) ;
V_65 = F_9 ( & V_16 [ V_3 ] [ V_32 ] ) ;
if ( V_65 )
V_51 = V_64 / V_65 * 100.0 ;
V_57 = F_7 ( V_55 , V_51 ) ;
fprintf ( V_62 , L_1 ) ;
F_10 ( V_62 , V_57 , L_2 , V_51 ) ;
fprintf ( V_62 , L_4 ) ;
}
static void F_12 ( T_2 * V_62 , int V_32 ,
struct V_1 * V_2 V_63 ,
double V_64 )
{
double V_65 , V_51 = 0.0 ;
const char * V_57 ;
int V_3 = F_1 ( V_2 ) ;
V_65 = F_9 ( & V_19 [ V_3 ] [ V_32 ] ) ;
if ( V_65 )
V_51 = V_64 / V_65 * 100.0 ;
V_57 = F_7 ( V_56 , V_51 ) ;
fprintf ( V_62 , L_1 ) ;
F_10 ( V_62 , V_57 , L_2 , V_51 ) ;
fprintf ( V_62 , L_5 ) ;
}
static void F_13 ( T_2 * V_62 , int V_32 ,
struct V_1 * V_2 V_63 ,
double V_64 )
{
double V_65 , V_51 = 0.0 ;
const char * V_57 ;
int V_3 = F_1 ( V_2 ) ;
V_65 = F_9 ( & V_21 [ V_3 ] [ V_32 ] ) ;
if ( V_65 )
V_51 = V_64 / V_65 * 100.0 ;
V_57 = F_7 ( V_56 , V_51 ) ;
fprintf ( V_62 , L_1 ) ;
F_10 ( V_62 , V_57 , L_2 , V_51 ) ;
fprintf ( V_62 , L_6 ) ;
}
static void F_14 ( T_2 * V_62 , int V_32 ,
struct V_1 * V_2 V_63 ,
double V_64 )
{
double V_65 , V_51 = 0.0 ;
const char * V_57 ;
int V_3 = F_1 ( V_2 ) ;
V_65 = F_9 ( & V_22 [ V_3 ] [ V_32 ] ) ;
if ( V_65 )
V_51 = V_64 / V_65 * 100.0 ;
V_57 = F_7 ( V_56 , V_51 ) ;
fprintf ( V_62 , L_1 ) ;
F_10 ( V_62 , V_57 , L_2 , V_51 ) ;
fprintf ( V_62 , L_7 ) ;
}
static void F_15 ( T_2 * V_62 , int V_32 ,
struct V_1 * V_2 V_63 ,
double V_64 )
{
double V_65 , V_51 = 0.0 ;
const char * V_57 ;
int V_3 = F_1 ( V_2 ) ;
V_65 = F_9 ( & V_25 [ V_3 ] [ V_32 ] ) ;
if ( V_65 )
V_51 = V_64 / V_65 * 100.0 ;
V_57 = F_7 ( V_56 , V_51 ) ;
fprintf ( V_62 , L_1 ) ;
F_10 ( V_62 , V_57 , L_2 , V_51 ) ;
fprintf ( V_62 , L_8 ) ;
}
static void F_16 ( T_2 * V_62 , int V_32 ,
struct V_1 * V_2 V_63 ,
double V_64 )
{
double V_65 , V_51 = 0.0 ;
const char * V_57 ;
int V_3 = F_1 ( V_2 ) ;
V_65 = F_9 ( & V_24 [ V_3 ] [ V_32 ] ) ;
if ( V_65 )
V_51 = V_64 / V_65 * 100.0 ;
V_57 = F_7 ( V_56 , V_51 ) ;
fprintf ( V_62 , L_1 ) ;
F_10 ( V_62 , V_57 , L_2 , V_51 ) ;
fprintf ( V_62 , L_9 ) ;
}
static void F_17 ( T_2 * V_62 , int V_32 ,
struct V_1 * V_2 V_63 ,
double V_64 )
{
double V_65 , V_51 = 0.0 ;
const char * V_57 ;
int V_3 = F_1 ( V_2 ) ;
V_65 = F_9 ( & V_23 [ V_3 ] [ V_32 ] ) ;
if ( V_65 )
V_51 = V_64 / V_65 * 100.0 ;
V_57 = F_7 ( V_56 , V_51 ) ;
fprintf ( V_62 , L_1 ) ;
F_10 ( V_62 , V_57 , L_2 , V_51 ) ;
fprintf ( V_62 , L_10 ) ;
}
void F_18 ( T_2 * V_62 , struct V_1 * V_2 ,
double V_64 , int V_32 , enum V_66 V_67 )
{
double V_65 , V_51 = 0.0 , V_68 ;
int V_3 = F_1 ( V_2 ) ;
if ( F_4 ( V_2 , V_35 , V_69 ) ) {
V_65 = F_9 ( & V_16 [ V_3 ] [ V_32 ] ) ;
if ( V_65 ) {
V_51 = V_64 / V_65 ;
fprintf ( V_62 , L_11 , V_51 ) ;
} else {
fprintf ( V_62 , L_12 ) ;
}
V_65 = F_9 ( & V_17 [ V_3 ] [ V_32 ] ) ;
V_65 = F_19 ( V_65 , F_9 ( & V_18 [ V_3 ] [ V_32 ] ) ) ;
if ( V_65 && V_64 ) {
V_51 = V_65 / V_64 ;
fprintf ( V_62 , L_13 ) ;
if ( V_67 == V_70 )
fprintf ( V_62 , L_14 ) ;
fprintf ( V_62 , L_15 , V_51 ) ;
}
} else if ( F_4 ( V_2 , V_35 , V_71 ) &&
V_19 [ V_3 ] [ V_32 ] . V_72 != 0 ) {
F_12 ( V_62 , V_32 , V_2 , V_64 ) ;
} else if (
V_2 -> V_4 . type == V_73 &&
V_2 -> V_4 . V_74 == ( V_75 |
( ( V_76 ) << 8 ) |
( ( V_77 ) << 16 ) ) &&
V_21 [ V_3 ] [ V_32 ] . V_72 != 0 ) {
F_13 ( V_62 , V_32 , V_2 , V_64 ) ;
} else if (
V_2 -> V_4 . type == V_73 &&
V_2 -> V_4 . V_74 == ( V_78 |
( ( V_76 ) << 8 ) |
( ( V_77 ) << 16 ) ) &&
V_22 [ V_3 ] [ V_32 ] . V_72 != 0 ) {
F_14 ( V_62 , V_32 , V_2 , V_64 ) ;
} else if (
V_2 -> V_4 . type == V_73 &&
V_2 -> V_4 . V_74 == ( V_79 |
( ( V_76 ) << 8 ) |
( ( V_77 ) << 16 ) ) &&
V_25 [ V_3 ] [ V_32 ] . V_72 != 0 ) {
F_15 ( V_62 , V_32 , V_2 , V_64 ) ;
} else if (
V_2 -> V_4 . type == V_73 &&
V_2 -> V_4 . V_74 == ( V_80 |
( ( V_76 ) << 8 ) |
( ( V_77 ) << 16 ) ) &&
V_24 [ V_3 ] [ V_32 ] . V_72 != 0 ) {
F_16 ( V_62 , V_32 , V_2 , V_64 ) ;
} else if (
V_2 -> V_4 . type == V_73 &&
V_2 -> V_4 . V_74 == ( V_81 |
( ( V_76 ) << 8 ) |
( ( V_77 ) << 16 ) ) &&
V_23 [ V_3 ] [ V_32 ] . V_72 != 0 ) {
F_17 ( V_62 , V_32 , V_2 , V_64 ) ;
} else if ( F_4 ( V_2 , V_35 , V_82 ) &&
V_20 [ V_3 ] [ V_32 ] . V_72 != 0 ) {
V_65 = F_9 ( & V_20 [ V_3 ] [ V_32 ] ) ;
if ( V_65 )
V_51 = V_64 * 100 / V_65 ;
fprintf ( V_62 , L_16 , V_51 ) ;
} else if ( F_4 ( V_2 , V_35 , V_40 ) ) {
F_8 ( V_62 , V_32 , V_2 , V_64 ) ;
} else if ( F_4 ( V_2 , V_35 , V_41 ) ) {
F_11 ( V_62 , V_32 , V_2 , V_64 ) ;
} else if ( F_4 ( V_2 , V_35 , V_36 ) ) {
V_65 = F_9 ( & V_15 [ V_32 ] ) ;
if ( V_65 ) {
V_51 = V_64 / V_65 ;
fprintf ( V_62 , L_17 , V_51 ) ;
} else {
fprintf ( V_62 , L_12 ) ;
}
} else if ( F_6 ( V_2 , V_37 ) ) {
V_65 = F_9 ( & V_16 [ V_3 ] [ V_32 ] ) ;
if ( V_65 )
fprintf ( V_62 ,
L_18 ,
100.0 * ( V_64 / V_65 ) ) ;
} else if ( F_6 ( V_2 , V_83 ) ) {
V_65 = F_9 ( & V_16 [ V_3 ] [ V_32 ] ) ;
V_68 = F_9 ( & V_26 [ V_3 ] [ V_32 ] ) ;
if ( V_68 < V_64 )
V_68 = V_64 ;
if ( V_65 )
fprintf ( V_62 ,
L_19 ,
100.0 * ( ( V_68 - V_64 ) / V_65 ) ) ;
} else if ( F_6 ( V_2 , V_38 ) &&
V_26 [ V_3 ] [ V_32 ] . V_72 != 0 ) {
V_65 = F_9 ( & V_26 [ V_3 ] [ V_32 ] ) ;
if ( V_64 )
V_51 = V_65 / V_64 ;
fprintf ( V_62 , L_20 , V_51 ) ;
} else if ( F_6 ( V_2 , V_39 ) &&
V_26 [ V_3 ] [ V_32 ] . V_72 != 0 ) {
V_65 = F_9 ( & V_26 [ V_3 ] [ V_32 ] ) ;
if ( V_64 )
V_51 = V_65 / V_64 ;
fprintf ( V_62 , L_21 , V_51 ) ;
} else if ( F_4 ( V_2 , V_33 , V_34 ) ) {
if ( ( V_51 = F_9 ( & V_29 ) ) != 0 )
fprintf ( V_62 , L_22 , V_64 / V_51 ) ;
else
fprintf ( V_62 , L_12 ) ;
} else if ( V_15 [ V_32 ] . V_72 != 0 ) {
char V_84 = 'M' ;
V_65 = F_9 ( & V_15 [ V_32 ] ) ;
if ( V_65 )
V_51 = 1000.0 * V_64 / V_65 ;
if ( V_51 < 0.001 ) {
V_51 *= 1000 ;
V_84 = 'K' ;
}
fprintf ( V_62 , L_23 , V_51 , V_84 ) ;
} else {
fprintf ( V_62 , L_12 ) ;
}
}
