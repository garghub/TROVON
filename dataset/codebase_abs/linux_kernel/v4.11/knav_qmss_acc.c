static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
int V_9 , V_10 ;
V_9 = V_6 -> V_11 + V_2 -> V_12 ;
if ( V_2 -> V_13 & V_14 ) {
for ( V_10 = 0 ; V_10 < V_2 -> V_15 ; V_10 ++ ) {
V_8 = F_2 ( V_6 , V_2 ,
V_10 ) ;
if ( V_8 -> V_16 ) {
V_8 -> V_16 = 0 ;
F_3 ( V_6 -> V_17 , L_1 ,
V_9 + V_10 ) ;
F_4 ( V_8 ) ;
}
}
} else {
V_10 = V_4 -> V_18 - V_2 -> V_19 . V_20 ;
V_8 = F_2 ( V_6 , V_2 , V_10 ) ;
F_3 ( V_6 -> V_17 , L_1 ,
V_9 + V_10 ) ;
F_4 ( V_8 ) ;
}
}
static int F_5 ( struct V_1 * V_2 ,
struct V_7 * V_21 ,
bool V_22 )
{
struct V_23 * V_24 = V_2 -> V_19 . V_24 ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_25 , V_26 ;
if ( ! V_22 || F_6 ( & V_21 -> V_27 ) <= 0 )
return 0 ;
V_21 -> V_16 = 1 ;
F_7 ( & V_21 -> V_4 -> V_28 ) ;
V_25 = F_8 ( V_21 -> V_4 -> V_18 % 32 ) ;
V_26 = F_9 ( V_21 -> V_4 -> V_18 ) ;
F_3 ( V_6 -> V_17 , L_2 ,
V_21 -> V_4 -> V_29 ) ;
F_10 ( V_25 , V_24 -> V_30 + V_26 ) ;
return 0 ;
}
static T_2 F_11 ( int V_31 , void * V_32 )
{
struct V_3 * V_4 ;
struct V_7 * V_21 = NULL ;
struct V_1 * V_2 ;
struct V_23 * V_24 ;
struct V_33 * V_34 ;
struct V_5 * V_6 ;
T_1 * V_35 , * V_36 , V_37 , V_38 , V_39 ;
int V_9 , V_18 , V_10 = 0 ;
T_3 V_40 ;
V_2 = V_32 ;
V_34 = & V_2 -> V_19 ;
V_6 = V_2 -> V_6 ;
V_24 = V_2 -> V_19 . V_24 ;
V_4 = V_2 -> V_4 ;
V_9 = V_6 -> V_11 + V_2 -> V_12 ;
if ( ( V_2 -> V_13 & V_14 ) == 0 ) {
for ( V_10 = 0 ; V_10 < V_2 -> V_41 ; V_10 ++ )
if ( V_2 -> V_42 [ V_10 ] . V_31 == V_31 )
break;
V_21 = F_2 ( V_6 , V_2 , V_10 ) ;
V_4 += V_10 ;
}
V_18 = V_4 -> V_18 ;
V_40 = V_4 -> V_40 [ V_4 -> V_43 ] ;
V_36 = V_4 -> V_36 [ V_4 -> V_43 ] ;
F_3 ( V_6 -> V_17 , L_3 ,
V_18 , V_4 -> V_43 , V_36 , & V_40 ) ;
if ( F_6 ( & V_4 -> V_28 ) ) {
F_12 ( & V_4 -> V_28 ) ;
F_1 ( V_2 , V_4 ) ;
F_10 ( 1 , V_24 -> V_30 + F_13 ( V_18 ) ) ;
F_10 ( V_44 + V_18 ,
V_24 -> V_30 + V_45 ) ;
return V_46 ;
}
V_39 = F_14 ( V_24 -> V_30 + F_13 ( V_18 ) ) ;
F_15 ( ! V_39 ) ;
F_16 ( V_6 -> V_17 , V_40 , V_34 -> V_47 ,
V_48 ) ;
for ( V_35 = V_36 ; V_35 < V_36 + ( V_34 -> V_47 / sizeof( T_1 ) ) ;
V_35 += V_49 ) {
if ( V_49 == 1 ) {
F_3 ( V_6 -> V_17 ,
L_4 ,
V_4 -> V_43 , V_35 , V_35 [ 0 ] ) ;
} else if ( V_49 == 2 ) {
F_3 ( V_6 -> V_17 ,
L_5 ,
V_4 -> V_43 , V_35 , V_35 [ 0 ] , V_35 [ 1 ] ) ;
} else if ( V_49 == 4 ) {
F_3 ( V_6 -> V_17 ,
L_6 ,
V_4 -> V_43 , V_35 , V_35 [ 0 ] , V_35 [ 1 ] ,
V_35 [ 2 ] , V_35 [ 3 ] ) ;
}
V_37 = V_35 [ V_50 ] ;
if ( ! V_37 )
break;
if ( V_2 -> V_13 & V_14 ) {
V_10 = V_35 [ V_51 ] >> 16 ;
if ( V_10 < V_9 ||
V_10 >= V_9 + V_2 -> V_15 ) {
F_17 ( V_6 -> V_17 ,
L_7 ,
V_10 , V_9 ,
V_9 + V_2 -> V_15 ) ;
break;
}
V_10 -= V_9 ;
V_21 = F_2 ( V_6 , V_2 ,
V_10 ) ;
}
if ( F_18 ( & V_21 -> V_27 ) >= V_52 ) {
F_12 ( & V_21 -> V_27 ) ;
F_17 ( V_6 -> V_17 ,
L_8 ,
V_10 + V_9 ) ;
continue;
}
V_38 = F_18 ( & V_21 -> V_53 ) & V_54 ;
V_21 -> V_55 [ V_38 ] = V_37 ;
V_21 -> V_16 = 1 ;
F_3 ( V_6 -> V_17 , L_9 ,
V_37 , V_38 , V_10 + V_9 ) ;
}
F_1 ( V_2 , V_4 ) ;
memset ( V_36 , 0 , V_34 -> V_47 ) ;
F_19 ( V_6 -> V_17 , V_40 , V_34 -> V_47 ,
V_56 ) ;
V_4 -> V_43 ^= 1 ;
F_10 ( 1 , V_24 -> V_30 + F_13 ( V_18 ) ) ;
F_10 ( V_44 + V_18 ,
V_24 -> V_30 + V_45 ) ;
return V_46 ;
}
static int F_20 ( struct V_1 * V_2 ,
int V_10 , bool V_22 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 ;
unsigned long V_57 ;
int V_58 = 0 , V_31 ;
T_1 V_59 , V_60 ;
if ( V_2 -> V_13 & V_14 ) {
V_4 = V_2 -> V_4 ;
V_31 = V_2 -> V_42 [ 0 ] . V_31 ;
V_57 = V_2 -> V_42 [ 0 ] . V_57 ;
} else {
V_4 = V_2 -> V_4 + V_10 ;
V_31 = V_2 -> V_42 [ V_10 ] . V_31 ;
V_57 = V_2 -> V_42 [ V_10 ] . V_57 ;
}
V_59 = V_4 -> V_61 ;
if ( V_22 )
V_60 = V_59 | F_8 ( V_10 ) ;
else
V_60 = V_59 & ~ F_8 ( V_10 ) ;
V_4 -> V_61 = V_60 ;
F_3 ( V_6 -> V_17 ,
L_10 ,
V_59 , V_60 , V_4 -> V_29 ) ;
if ( F_21 ( V_60 == V_59 ) )
return 0 ;
if ( V_60 && ! V_59 ) {
F_3 ( V_6 -> V_17 ,
L_11 ,
V_4 -> V_29 , V_4 -> V_29 ) ;
V_58 = F_22 ( V_31 , F_11 , 0 , V_4 -> V_29 ,
V_2 ) ;
if ( ! V_58 && V_57 ) {
V_58 = F_23 ( V_31 , F_24 ( & V_57 ) ) ;
if ( V_58 ) {
F_25 ( V_2 -> V_6 -> V_17 ,
L_12 ) ;
return V_58 ;
}
}
}
if ( V_59 && ! V_60 ) {
F_3 ( V_6 -> V_17 , L_13 ,
V_4 -> V_29 , V_4 -> V_29 ) ;
V_58 = F_23 ( V_31 , NULL ) ;
if ( V_58 )
F_25 ( V_2 -> V_6 -> V_17 ,
L_12 ) ;
F_26 ( V_31 , V_2 ) ;
}
return V_58 ;
}
static const char * F_27 ( enum V_62 V_63 )
{
static const char * const V_64 [] = {
[ V_65 ] = L_14 ,
[ V_66 ] = L_15 ,
[ V_67 ] = L_16 ,
[ V_68 ] = L_17 ,
[ V_69 ] = L_18 ,
[ V_70 ] = L_19 ,
[ V_71 ] = L_20 ,
[ V_72 ] = L_21 ,
} ;
if ( V_63 >= F_28 ( V_64 ) )
return V_64 [ V_72 ] ;
else
return V_64 [ V_63 ] ;
}
static enum V_62
F_29 ( struct V_5 * V_6 , struct V_23 * V_24 ,
struct V_73 * V_74 )
{
T_1 V_63 ;
F_3 ( V_6 -> V_17 , L_22 ,
V_74 -> V_75 , V_74 -> V_76 , V_74 -> V_40 ,
V_74 -> V_77 , V_74 -> V_78 ) ;
F_10 ( V_74 -> V_78 , & V_24 -> V_79 -> V_78 ) ;
F_10 ( V_74 -> V_77 , & V_24 -> V_79 -> V_77 ) ;
F_10 ( V_74 -> V_40 , & V_24 -> V_79 -> V_40 ) ;
F_10 ( V_74 -> V_76 , & V_24 -> V_79 -> V_76 ) ;
F_10 ( V_74 -> V_75 , & V_24 -> V_79 -> V_75 ) ;
do {
V_63 = F_14 ( & V_24 -> V_79 -> V_75 ) ;
} while ( ( V_63 >> 8 ) & 0xff );
return ( V_63 >> 24 ) & 0xff ;
}
static void F_30 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
struct V_73 * V_74 ,
int V_10 )
{
struct V_33 * V_34 = & V_2 -> V_19 ;
struct V_3 * V_4 ;
int V_12 ;
T_1 V_76 ;
if ( V_2 -> V_13 & V_14 ) {
V_4 = V_2 -> V_4 ;
V_12 = V_2 -> V_12 ;
V_76 = F_8 ( V_2 -> V_15 ) - 1 ;
} else {
V_4 = V_2 -> V_4 + V_10 ;
V_12 = V_2 -> V_12 + V_10 ;
V_76 = 0 ;
}
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
V_74 -> V_75 = V_4 -> V_18 ;
V_74 -> V_76 = V_76 ;
V_74 -> V_40 = ( T_1 ) V_4 -> V_40 [ 0 ] ;
V_74 -> V_77 = V_34 -> V_80 << 16 ;
V_74 -> V_77 |= V_12 ;
V_74 -> V_78 = V_81 << 18 ;
if ( V_2 -> V_13 & V_14 )
V_74 -> V_78 |= V_82 ;
V_74 -> V_78 |= V_34 -> V_83 << 16 ;
V_74 -> V_78 |= V_34 -> V_84 ;
}
static void F_31 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
int V_10 )
{
struct V_73 V_74 ;
struct V_3 * V_4 ;
enum V_62 V_63 ;
V_4 = V_2 -> V_4 + V_10 ;
F_30 ( V_6 , V_2 , & V_74 , V_10 ) ;
V_74 . V_75 |= V_85 << 8 ;
V_63 = F_29 ( V_6 , V_2 -> V_19 . V_24 , & V_74 ) ;
F_3 ( V_6 -> V_17 , L_23 ,
V_4 -> V_29 , F_27 ( V_63 ) ) ;
}
static enum V_62 F_32 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
int V_10 )
{
struct V_73 V_74 ;
struct V_3 * V_4 ;
enum V_62 V_63 ;
V_4 = V_2 -> V_4 + V_10 ;
F_30 ( V_6 , V_2 , & V_74 , V_10 ) ;
V_74 . V_75 |= V_86 << 8 ;
V_63 = F_29 ( V_6 , V_2 -> V_19 . V_24 , & V_74 ) ;
F_3 ( V_6 -> V_17 , L_24 ,
V_4 -> V_29 , F_27 ( V_63 ) ) ;
return V_63 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 ;
enum V_62 V_63 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_15 ; V_10 ++ ) {
V_4 = V_2 -> V_4 + V_10 ;
F_31 ( V_6 , V_2 , V_10 ) ;
V_4 -> V_43 = 0 ;
V_63 = F_32 ( V_6 , V_2 , V_10 ) ;
if ( V_63 != V_66 )
return - V_87 ;
if ( V_2 -> V_13 & V_14 )
return 0 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_7 * V_21 )
{
unsigned V_88 = V_21 -> V_88 - V_2 -> V_12 ;
V_21 -> V_55 = F_35 ( V_2 -> V_6 -> V_17 ,
V_52 * sizeof( T_1 ) , V_89 ) ;
if ( ! V_21 -> V_55 )
return - V_90 ;
V_21 -> V_4 = V_2 -> V_4 ;
if ( ( V_2 -> V_13 & V_14 ) == 0 )
V_21 -> V_4 += V_88 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_7 * V_8 , unsigned V_13 )
{
unsigned V_88 = V_8 -> V_88 - V_2 -> V_12 ;
return F_20 ( V_2 , V_88 , true ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned V_88 = V_8 -> V_88 - V_2 -> V_12 ;
return F_20 ( V_2 , V_88 , false ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 ;
struct V_33 * V_34 ;
int V_18 , V_91 ;
V_34 = & V_2 -> V_19 ;
if ( V_2 -> V_13 & V_14 )
V_91 = 1 ;
else
V_91 = V_2 -> V_15 ;
for ( V_18 = 0 ; V_18 < V_91 ; V_18 ++ ) {
V_4 = V_2 -> V_4 + V_18 ;
if ( ! V_4 -> V_36 [ 0 ] )
continue;
F_39 ( V_6 -> V_17 , V_4 -> V_40 [ 0 ] ,
V_34 -> V_92 , V_93 ) ;
F_40 ( V_4 -> V_36 [ 0 ] , V_34 -> V_92 ) ;
}
F_41 ( V_2 -> V_6 -> V_17 , V_2 -> V_4 ) ;
return 0 ;
}
int F_42 ( struct V_5 * V_6 ,
struct V_94 * V_95 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 ;
struct V_33 * V_34 ;
int V_58 , V_18 , V_91 ;
int V_47 , V_92 ;
T_3 V_40 ;
void * V_96 ;
T_1 V_97 [ 5 ] ;
V_2 -> V_13 |= V_98 ;
V_34 = & V_2 -> V_19 ;
V_58 = F_43 ( V_95 , L_25 , V_97 , 5 ) ;
if ( V_58 )
return V_58 ;
V_34 -> V_99 = V_97 [ 0 ] ;
V_34 -> V_20 = V_97 [ 1 ] ;
V_34 -> V_80 = V_97 [ 2 ] ;
V_34 -> V_83 = V_97 [ 3 ] ;
V_34 -> V_84 = V_97 [ 4 ] / V_100 ;
if ( V_34 -> V_20 > V_101 ) {
F_17 ( V_6 -> V_17 , L_26 ,
V_34 -> V_20 , V_2 -> V_29 ) ;
return - V_102 ;
}
if ( V_34 -> V_83 > 3 ) {
F_17 ( V_6 -> V_17 , L_27 ,
V_34 -> V_83 , V_2 -> V_29 ) ;
return - V_102 ;
}
V_24 = F_44 ( V_6 , V_34 -> V_99 ) ;
if ( ! V_24 ) {
F_17 ( V_6 -> V_17 , L_28 ,
V_34 -> V_99 , V_2 -> V_29 ) ;
return - V_102 ;
}
if ( ! V_24 -> V_103 ) {
F_17 ( V_6 -> V_17 , L_29 ,
V_34 -> V_99 , V_2 -> V_29 ) ;
return - V_104 ;
}
V_34 -> V_24 = V_24 ;
V_91 = V_2 -> V_15 ;
if ( F_45 ( V_95 , L_30 , NULL ) ) {
V_2 -> V_13 |= V_14 ;
V_91 = 1 ;
if ( V_2 -> V_12 & ( 32 - 1 ) ) {
F_17 ( V_6 -> V_17 ,
L_31 ,
V_2 -> V_29 ) ;
return - V_102 ;
}
if ( V_2 -> V_15 > 32 ) {
F_17 ( V_6 -> V_17 ,
L_32 ,
V_2 -> V_29 ) ;
return - V_102 ;
}
}
V_47 = V_34 -> V_80 ;
V_47 *= V_49 * sizeof( T_1 ) ;
V_34 -> V_47 = V_47 ;
V_92 = F_46 ( V_47 * 2 ) ;
V_34 -> V_92 = V_92 ;
V_2 -> V_4 = F_35 ( V_6 -> V_17 , V_91 * sizeof( * V_2 -> V_4 ) ,
V_89 ) ;
if ( ! V_2 -> V_4 )
return - V_90 ;
for ( V_18 = 0 ; V_18 < V_91 ; V_18 ++ ) {
V_4 = V_2 -> V_4 + V_18 ;
V_4 -> V_18 = V_34 -> V_20 + V_18 ;
V_96 = F_47 ( V_92 , V_89 | V_105 ) ;
if ( ! V_96 )
return - V_90 ;
V_40 = F_48 ( V_6 -> V_17 , V_96 , V_92 ,
V_93 ) ;
if ( F_49 ( V_6 -> V_17 , V_40 ) ) {
F_40 ( V_96 , V_92 ) ;
return - V_90 ;
}
memset ( V_96 , 0 , V_92 ) ;
F_19 ( V_6 -> V_17 , V_40 , V_92 ,
V_56 ) ;
F_50 ( V_4 -> V_29 , sizeof( V_4 -> V_29 ) , L_33 ,
V_4 -> V_18 ) ;
V_4 -> V_36 [ 0 ] = V_96 ;
V_4 -> V_36 [ 1 ] = V_96 + V_47 ;
V_4 -> V_40 [ 0 ] = V_40 ;
V_4 -> V_40 [ 1 ] = V_40 + V_47 ;
F_3 ( V_6 -> V_17 , L_34 ,
V_4 -> V_29 , V_4 -> V_18 , & V_40 , V_96 ) ;
}
V_2 -> V_106 = & V_107 ;
return 0 ;
}
