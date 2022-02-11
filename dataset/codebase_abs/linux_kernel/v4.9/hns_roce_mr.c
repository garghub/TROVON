static T_1 F_1 ( unsigned long V_1 )
{
return ( T_1 ) ( V_1 >> 24 ) | ( V_1 << 8 ) ;
}
static unsigned long F_2 ( T_1 V_2 )
{
return ( V_2 << 24 ) | ( V_2 >> 8 ) ;
}
static int F_3 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
return F_4 ( V_4 , V_6 -> V_8 , 0 , V_7 , 0 ,
V_9 ,
V_10 ) ;
}
static int F_5 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
return F_4 ( V_4 , 0 , V_6 ? V_6 -> V_8 : 0 ,
V_7 , ! V_6 , V_11 ,
V_10 ) ;
}
static int F_6 ( struct V_12 * V_13 , int V_14 ,
unsigned long * V_15 )
{
int V_16 ;
T_1 V_17 ;
F_7 ( & V_13 -> V_18 ) ;
for ( V_16 = V_14 ; V_16 <= V_13 -> V_19 ; ++ V_16 ) {
if ( V_13 -> V_20 [ V_16 ] ) {
V_17 = 1 << ( V_13 -> V_19 - V_16 ) ;
* V_15 = F_8 ( V_13 -> V_21 [ V_16 ] , V_17 ) ;
if ( * V_15 < V_17 )
goto V_22;
}
}
F_9 ( & V_13 -> V_18 ) ;
return - 1 ;
V_22:
F_10 ( * V_15 , V_13 -> V_21 [ V_16 ] ) ;
-- V_13 -> V_20 [ V_16 ] ;
while ( V_16 > V_14 ) {
-- V_16 ;
* V_15 <<= 1 ;
F_11 ( * V_15 ^ 1 , V_13 -> V_21 [ V_16 ] ) ;
++ V_13 -> V_20 [ V_16 ] ;
}
F_9 ( & V_13 -> V_18 ) ;
* V_15 <<= V_14 ;
return 0 ;
}
static void F_12 ( struct V_12 * V_13 , unsigned long V_15 ,
int V_14 )
{
V_15 >>= V_14 ;
F_7 ( & V_13 -> V_18 ) ;
while ( F_13 ( V_15 ^ 1 , V_13 -> V_21 [ V_14 ] ) ) {
F_10 ( V_15 ^ 1 , V_13 -> V_21 [ V_14 ] ) ;
-- V_13 -> V_20 [ V_14 ] ;
V_15 >>= 1 ;
++ V_14 ;
}
F_11 ( V_15 , V_13 -> V_21 [ V_14 ] ) ;
++ V_13 -> V_20 [ V_14 ] ;
F_9 ( & V_13 -> V_18 ) ;
}
static int F_14 ( struct V_12 * V_13 , int V_19 )
{
int V_23 , V_24 ;
V_13 -> V_19 = V_19 ;
F_15 ( & V_13 -> V_18 ) ;
V_13 -> V_21 = F_16 ( ( V_13 -> V_19 + 1 ) * sizeof( long * ) ,
V_25 ) ;
V_13 -> V_20 = F_16 ( ( V_13 -> V_19 + 1 ) * sizeof( int * ) ,
V_25 ) ;
if ( ! V_13 -> V_21 || ! V_13 -> V_20 )
goto V_26;
for ( V_23 = 0 ; V_23 <= V_13 -> V_19 ; ++ V_23 ) {
V_24 = F_17 ( 1 << ( V_13 -> V_19 - V_23 ) ) ;
V_13 -> V_21 [ V_23 ] = F_18 ( V_24 , sizeof( long ) , V_25 ) ;
if ( ! V_13 -> V_21 [ V_23 ] )
goto V_27;
F_19 ( V_13 -> V_21 [ V_23 ] , 1 << ( V_13 -> V_19 - V_23 ) ) ;
}
F_11 ( 0 , V_13 -> V_21 [ V_13 -> V_19 ] ) ;
V_13 -> V_20 [ V_13 -> V_19 ] = 1 ;
return 0 ;
V_27:
for ( V_23 = 0 ; V_23 <= V_13 -> V_19 ; ++ V_23 )
F_20 ( V_13 -> V_21 [ V_23 ] ) ;
V_26:
F_20 ( V_13 -> V_21 ) ;
F_20 ( V_13 -> V_20 ) ;
return - V_28 ;
}
static void F_21 ( struct V_12 * V_13 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 <= V_13 -> V_19 ; ++ V_23 )
F_20 ( V_13 -> V_21 [ V_23 ] ) ;
F_20 ( V_13 -> V_21 ) ;
F_20 ( V_13 -> V_20 ) ;
}
static int F_22 ( struct V_3 * V_4 , int V_14 ,
unsigned long * V_15 )
{
struct V_29 * V_30 = & V_4 -> V_30 ;
int V_31 = 0 ;
V_31 = F_6 ( & V_30 -> V_32 , V_14 , V_15 ) ;
if ( V_31 == - 1 )
return - 1 ;
if ( F_23 ( V_4 , & V_30 -> V_33 , * V_15 ,
* V_15 + ( 1 << V_14 ) - 1 ) ) {
F_12 ( & V_30 -> V_32 , * V_15 , V_14 ) ;
return - 1 ;
}
return 0 ;
}
int F_24 ( struct V_3 * V_4 , int V_34 , int V_35 ,
struct V_36 * V_37 )
{
int V_31 = 0 ;
int V_23 ;
if ( ! V_34 ) {
V_37 -> V_14 = - 1 ;
V_37 -> V_35 = V_38 ;
return 0 ;
}
V_37 -> V_35 = V_35 ;
for ( V_37 -> V_14 = 0 , V_23 = V_39 ; V_23 < V_34 ;
V_23 <<= 1 )
++ V_37 -> V_14 ;
V_31 = F_22 ( V_4 , V_37 -> V_14 , & V_37 -> V_40 ) ;
if ( V_31 == - 1 )
return - V_28 ;
return 0 ;
}
void F_25 ( struct V_3 * V_4 , struct V_36 * V_37 )
{
struct V_29 * V_30 = & V_4 -> V_30 ;
if ( V_37 -> V_14 < 0 )
return;
F_12 ( & V_30 -> V_32 , V_37 -> V_40 , V_37 -> V_14 ) ;
F_26 ( V_4 , & V_30 -> V_33 , V_37 -> V_40 ,
V_37 -> V_40 + ( 1 << V_37 -> V_14 ) - 1 ) ;
}
static int F_27 ( struct V_3 * V_4 , T_1 V_41 , T_2 V_42 ,
T_2 V_43 , T_1 V_44 , int V_34 ,
struct V_45 * V_46 )
{
unsigned long V_47 = 0 ;
int V_31 = 0 ;
struct V_48 * V_49 = & V_4 -> V_50 -> V_49 ;
V_31 = F_28 ( & V_4 -> V_30 . V_51 , & V_47 ) ;
if ( V_31 == - 1 )
return - V_28 ;
V_46 -> V_42 = V_42 ;
V_46 -> V_43 = V_43 ;
V_46 -> V_41 = V_41 ;
V_46 -> V_44 = V_44 ;
V_46 -> V_52 = 0 ;
V_46 -> V_2 = F_1 ( V_47 ) ;
if ( V_43 == ~ 0ull ) {
V_46 -> type = V_53 ;
V_46 -> V_54 = NULL ;
V_46 -> V_55 = 0 ;
} else {
V_46 -> type = V_56 ;
V_46 -> V_54 = F_29 ( V_49 , V_34 * 8 ,
& ( V_46 -> V_55 ) ,
V_25 ) ;
if ( ! V_46 -> V_54 )
return - V_28 ;
}
return 0 ;
}
static void F_30 ( struct V_3 * V_4 ,
struct V_45 * V_46 )
{
struct V_48 * V_49 = & V_4 -> V_50 -> V_49 ;
int V_34 = 0 ;
int V_31 ;
if ( V_46 -> V_52 ) {
V_31 = F_5 ( V_4 , NULL , F_2 ( V_46 -> V_2 )
& ( V_4 -> V_57 . V_58 - 1 ) ) ;
if ( V_31 )
F_31 ( V_49 , L_1 , V_31 ) ;
}
if ( V_46 -> V_43 != ~ 0ULL ) {
V_34 = F_32 ( V_46 -> V_59 ) ;
F_33 ( V_49 , ( unsigned int ) ( V_34 * 8 ) , V_46 -> V_54 ,
V_46 -> V_55 ) ;
}
F_34 ( & V_4 -> V_30 . V_51 ,
F_2 ( V_46 -> V_2 ) ) ;
}
static int F_35 ( struct V_3 * V_4 ,
struct V_45 * V_46 )
{
int V_31 ;
unsigned long V_60 = F_2 ( V_46 -> V_2 ) ;
struct V_48 * V_49 = & V_4 -> V_50 -> V_49 ;
struct V_5 * V_6 ;
struct V_29 * V_30 = & V_4 -> V_30 ;
V_31 = F_36 ( V_4 , & V_30 -> V_61 , V_60 ) ;
if ( V_31 )
return V_31 ;
V_6 = F_37 ( V_4 ) ;
if ( F_38 ( V_6 ) ) {
V_31 = F_39 ( V_6 ) ;
goto V_62;
}
V_31 = V_4 -> V_63 -> V_64 ( V_6 -> V_65 , V_46 , V_60 ) ;
if ( V_31 ) {
F_40 ( V_49 , L_2 ) ;
goto V_66;
}
V_31 = F_3 ( V_4 , V_6 ,
V_60 & ( V_4 -> V_57 . V_58 - 1 ) ) ;
if ( V_31 ) {
F_40 ( V_49 , L_3 , V_31 ) ;
goto V_66;
}
V_46 -> V_52 = 1 ;
F_41 ( V_4 , V_6 ) ;
return 0 ;
V_66:
F_41 ( V_4 , V_6 ) ;
V_62:
F_42 ( V_4 , & V_30 -> V_61 , V_60 ) ;
return V_31 ;
}
static int F_43 ( struct V_3 * V_4 ,
struct V_36 * V_37 , T_1 V_67 ,
T_1 V_34 , T_2 * V_68 )
{
T_1 V_23 = 0 ;
T_3 * V_69 = NULL ;
T_4 V_70 ;
T_1 V_24 = V_67 * sizeof( T_2 ) ;
if ( V_67 / ( V_71 / sizeof( T_2 ) ) !=
( V_67 + V_34 - 1 ) / ( V_71 / sizeof( T_2 ) ) )
return - V_72 ;
if ( V_67 & ( V_39 - 1 ) )
return - V_72 ;
V_69 = F_44 ( & V_4 -> V_30 . V_33 ,
V_37 -> V_40 + V_24 / V_4 -> V_57 . V_73 ,
& V_70 ) ;
if ( ! V_69 )
return - V_28 ;
for ( V_23 = 0 ; V_23 < V_34 ; ++ V_23 )
V_69 [ V_23 ] = ( F_45 ( V_68 [ V_23 ] ) ) >> V_74 ;
return 0 ;
}
static int F_46 ( struct V_3 * V_4 ,
struct V_36 * V_37 , T_1 V_67 ,
T_1 V_34 , T_2 * V_68 )
{
int V_75 ;
int V_31 ;
if ( V_37 -> V_14 < 0 )
return - V_72 ;
while ( V_34 > 0 ) {
V_75 = F_47 ( int , V_71 / sizeof( T_2 ) , V_34 ) ;
V_31 = F_43 ( V_4 , V_37 , V_67 , V_75 ,
V_68 ) ;
if ( V_31 )
return V_31 ;
V_34 -= V_75 ;
V_67 += V_75 ;
V_68 += V_75 ;
}
return 0 ;
}
int F_48 ( struct V_3 * V_4 ,
struct V_36 * V_37 , struct V_76 * V_65 )
{
T_1 V_23 = 0 ;
int V_31 = 0 ;
T_2 * V_68 = NULL ;
V_68 = F_18 ( V_65 -> V_34 , sizeof( * V_68 ) , V_25 ) ;
if ( ! V_68 )
return - V_28 ;
for ( V_23 = 0 ; V_23 < V_65 -> V_34 ; ++ V_23 ) {
if ( V_65 -> V_77 == 1 )
V_68 [ V_23 ] = V_65 -> V_78 . V_79 + ( V_23 << V_65 -> V_35 ) ;
else
V_68 [ V_23 ] = V_65 -> V_68 [ V_23 ] . V_79 ;
}
V_31 = F_46 ( V_4 , V_37 , 0 , V_65 -> V_34 , V_68 ) ;
F_20 ( V_68 ) ;
return V_31 ;
}
int F_49 ( struct V_3 * V_4 )
{
struct V_29 * V_30 = & V_4 -> V_30 ;
int V_31 = 0 ;
V_31 = F_50 ( & V_30 -> V_51 ,
V_4 -> V_57 . V_58 ,
V_4 -> V_57 . V_58 - 1 ,
V_4 -> V_57 . V_80 , 0 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_14 ( & V_30 -> V_32 ,
F_51 ( V_4 -> V_57 . V_81 ) ) ;
if ( V_31 )
goto V_82;
return 0 ;
V_82:
F_52 ( & V_30 -> V_51 ) ;
return V_31 ;
}
void F_53 ( struct V_3 * V_4 )
{
struct V_29 * V_30 = & V_4 -> V_30 ;
F_21 ( & V_30 -> V_32 ) ;
F_52 ( & V_30 -> V_51 ) ;
}
struct V_83 * F_54 ( struct V_84 * V_41 , int V_85 )
{
int V_31 = 0 ;
struct V_45 * V_46 = NULL ;
V_46 = F_55 ( sizeof( * V_46 ) , V_25 ) ;
if ( V_46 == NULL )
return F_56 ( - V_28 ) ;
V_31 = F_27 ( F_57 ( V_41 -> V_48 ) , F_58 ( V_41 ) -> V_86 , 0 ,
~ 0ULL , V_85 , 0 , V_46 ) ;
if ( V_31 )
goto V_87;
V_31 = F_35 ( F_57 ( V_41 -> V_48 ) , V_46 ) ;
if ( V_31 )
goto V_88;
V_46 -> V_89 . V_90 = V_46 -> V_89 . V_91 = V_46 -> V_2 ;
V_46 -> V_59 = NULL ;
return & V_46 -> V_89 ;
V_88:
F_30 ( F_57 ( V_41 -> V_48 ) , V_46 ) ;
V_87:
F_20 ( V_46 ) ;
return F_56 ( V_31 ) ;
}
int F_59 ( struct V_3 * V_4 ,
struct V_36 * V_37 , struct V_92 * V_59 )
{
struct V_93 * V_94 ;
int V_23 , V_95 , V_96 ;
int V_31 = 0 ;
T_2 * V_97 ;
T_1 V_98 ;
int V_99 ;
V_97 = ( T_2 * ) F_60 ( V_25 ) ;
if ( ! V_97 )
return - V_28 ;
V_23 = V_98 = 0 ;
F_61 (umem->sg_head.sgl, sg, umem->nmap, entry) {
V_99 = F_62 ( V_94 ) >> V_37 -> V_35 ;
for ( V_95 = 0 ; V_95 < V_99 ; ++ V_95 ) {
V_97 [ V_23 ++ ] = F_63 ( V_94 ) + V_59 -> V_100 * V_95 ;
if ( V_23 == V_71 / sizeof( T_2 ) ) {
V_31 = F_46 ( V_4 , V_37 , V_98 , V_23 ,
V_97 ) ;
if ( V_31 )
goto V_101;
V_98 += V_23 ;
V_23 = 0 ;
}
}
}
if ( V_23 )
V_31 = F_46 ( V_4 , V_37 , V_98 , V_23 , V_97 ) ;
V_101:
F_64 ( ( unsigned long ) V_97 ) ;
return V_31 ;
}
static int F_65 ( struct V_45 * V_46 ,
struct V_92 * V_59 )
{
int V_23 = 0 ;
int V_96 ;
struct V_93 * V_94 ;
F_61 (umem->sg_head.sgl, sg, umem->nmap, entry) {
V_46 -> V_54 [ V_23 ] = ( ( T_2 ) F_63 ( V_94 ) ) >> 12 ;
V_23 ++ ;
}
F_66 () ;
return 0 ;
}
struct V_83 * F_67 ( struct V_84 * V_41 , T_2 V_102 , T_2 V_103 ,
T_2 V_104 , int V_105 ,
struct V_106 * V_107 )
{
struct V_3 * V_4 = F_57 ( V_41 -> V_48 ) ;
struct V_48 * V_49 = & V_4 -> V_50 -> V_49 ;
struct V_45 * V_46 = NULL ;
int V_31 = 0 ;
int V_98 = 0 ;
V_46 = F_55 ( sizeof( * V_46 ) , V_25 ) ;
if ( ! V_46 )
return F_56 ( - V_28 ) ;
V_46 -> V_59 = F_68 ( V_41 -> V_108 -> V_109 , V_102 , V_103 ,
V_105 , 0 ) ;
if ( F_38 ( V_46 -> V_59 ) ) {
V_31 = F_39 ( V_46 -> V_59 ) ;
goto V_87;
}
V_98 = F_32 ( V_46 -> V_59 ) ;
if ( V_46 -> V_59 -> V_100 != V_110 ) {
F_40 ( V_49 , L_4 ,
V_46 -> V_59 -> V_100 ) ;
V_31 = - V_72 ;
goto V_111;
}
if ( V_98 > V_112 ) {
F_40 ( V_49 , L_5 ,
V_103 ) ;
V_31 = - V_72 ;
goto V_111;
}
V_31 = F_27 ( V_4 , F_58 ( V_41 ) -> V_86 , V_104 , V_103 ,
V_105 , V_98 , V_46 ) ;
if ( V_31 )
goto V_111;
V_31 = F_65 ( V_46 , V_46 -> V_59 ) ;
if ( V_31 )
goto V_88;
V_31 = F_35 ( V_4 , V_46 ) ;
if ( V_31 )
goto V_88;
V_46 -> V_89 . V_90 = V_46 -> V_89 . V_91 = V_46 -> V_2 ;
return & V_46 -> V_89 ;
V_88:
F_30 ( V_4 , V_46 ) ;
V_111:
F_69 ( V_46 -> V_59 ) ;
V_87:
F_20 ( V_46 ) ;
return F_56 ( V_31 ) ;
}
int F_70 ( struct V_83 * V_89 )
{
struct V_45 * V_46 = F_71 ( V_89 ) ;
F_30 ( F_57 ( V_89 -> V_48 ) , V_46 ) ;
if ( V_46 -> V_59 )
F_69 ( V_46 -> V_59 ) ;
F_20 ( V_46 ) ;
return 0 ;
}
