static T_1 F_1 ( unsigned long V_1 )
{
return ( T_1 ) ( V_1 >> 24 ) | ( V_1 << 8 ) ;
}
unsigned long F_2 ( T_1 V_2 )
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
int F_5 ( struct V_3 * V_4 ,
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
V_13 -> V_21 = F_16 ( V_13 -> V_19 + 1 ,
sizeof( * V_13 -> V_21 ) ,
V_25 ) ;
V_13 -> V_20 = F_16 ( V_13 -> V_19 + 1 ,
sizeof( * V_13 -> V_20 ) ,
V_25 ) ;
if ( ! V_13 -> V_21 || ! V_13 -> V_20 )
goto V_26;
for ( V_23 = 0 ; V_23 <= V_13 -> V_19 ; ++ V_23 ) {
V_24 = F_17 ( 1 << ( V_13 -> V_19 - V_23 ) ) ;
V_13 -> V_21 [ V_23 ] = F_16 ( V_24 , sizeof( long ) , V_25 |
V_27 ) ;
if ( ! V_13 -> V_21 [ V_23 ] ) {
V_13 -> V_21 [ V_23 ] = F_18 ( V_24 * sizeof( long ) ) ;
if ( ! V_13 -> V_21 [ V_23 ] )
goto V_28;
}
}
F_11 ( 0 , V_13 -> V_21 [ V_13 -> V_19 ] ) ;
V_13 -> V_20 [ V_13 -> V_19 ] = 1 ;
return 0 ;
V_28:
for ( V_23 = 0 ; V_23 <= V_13 -> V_19 ; ++ V_23 )
F_19 ( V_13 -> V_21 [ V_23 ] ) ;
V_26:
F_20 ( V_13 -> V_21 ) ;
F_20 ( V_13 -> V_20 ) ;
return - V_29 ;
}
static void F_21 ( struct V_12 * V_13 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 <= V_13 -> V_19 ; ++ V_23 )
F_19 ( V_13 -> V_21 [ V_23 ] ) ;
F_20 ( V_13 -> V_21 ) ;
F_20 ( V_13 -> V_20 ) ;
}
static int F_22 ( struct V_3 * V_4 , int V_14 ,
unsigned long * V_15 )
{
struct V_30 * V_31 = & V_4 -> V_31 ;
int V_32 = 0 ;
V_32 = F_6 ( & V_31 -> V_33 , V_14 , V_15 ) ;
if ( V_32 == - 1 )
return - 1 ;
if ( F_23 ( V_4 , & V_31 -> V_34 , * V_15 ,
* V_15 + ( 1 << V_14 ) - 1 ) ) {
F_12 ( & V_31 -> V_33 , * V_15 , V_14 ) ;
return - 1 ;
}
return 0 ;
}
int F_24 ( struct V_3 * V_4 , int V_35 , int V_36 ,
struct V_37 * V_38 )
{
int V_32 = 0 ;
int V_23 ;
if ( ! V_35 ) {
V_38 -> V_14 = - 1 ;
V_38 -> V_36 = V_39 ;
return 0 ;
}
V_38 -> V_36 = V_36 ;
for ( V_38 -> V_14 = 0 , V_23 = V_40 ; V_23 < V_35 ;
V_23 <<= 1 )
++ V_38 -> V_14 ;
V_32 = F_22 ( V_4 , V_38 -> V_14 , & V_38 -> V_41 ) ;
if ( V_32 == - 1 )
return - V_29 ;
return 0 ;
}
void F_25 ( struct V_3 * V_4 , struct V_37 * V_38 )
{
struct V_30 * V_31 = & V_4 -> V_31 ;
if ( V_38 -> V_14 < 0 )
return;
F_12 ( & V_31 -> V_33 , V_38 -> V_41 , V_38 -> V_14 ) ;
F_26 ( V_4 , & V_31 -> V_34 , V_38 -> V_41 ,
V_38 -> V_41 + ( 1 << V_38 -> V_14 ) - 1 ) ;
}
static int F_27 ( struct V_3 * V_4 , T_1 V_42 , T_2 V_43 ,
T_2 V_44 , T_1 V_45 , int V_35 ,
struct V_46 * V_47 )
{
unsigned long V_48 = 0 ;
int V_32 = 0 ;
struct V_49 * V_50 = & V_4 -> V_51 -> V_50 ;
V_32 = F_28 ( & V_4 -> V_31 . V_52 , & V_48 ) ;
if ( V_32 == - 1 )
return - V_29 ;
V_47 -> V_43 = V_43 ;
V_47 -> V_44 = V_44 ;
V_47 -> V_42 = V_42 ;
V_47 -> V_45 = V_45 ;
V_47 -> V_53 = 0 ;
V_47 -> V_2 = F_1 ( V_48 ) ;
if ( V_44 == ~ 0ull ) {
V_47 -> type = V_54 ;
V_47 -> V_55 = NULL ;
V_47 -> V_56 = 0 ;
} else {
V_47 -> type = V_57 ;
V_47 -> V_55 = F_29 ( V_50 , V_35 * 8 ,
& ( V_47 -> V_56 ) ,
V_25 ) ;
if ( ! V_47 -> V_55 )
return - V_29 ;
}
return 0 ;
}
static void F_30 ( struct V_3 * V_4 ,
struct V_46 * V_47 )
{
struct V_49 * V_50 = & V_4 -> V_51 -> V_50 ;
int V_35 = 0 ;
int V_32 ;
if ( V_47 -> V_53 ) {
V_32 = F_5 ( V_4 , NULL , F_2 ( V_47 -> V_2 )
& ( V_4 -> V_58 . V_59 - 1 ) ) ;
if ( V_32 )
F_31 ( V_50 , L_1 , V_32 ) ;
}
if ( V_47 -> V_44 != ~ 0ULL ) {
V_35 = F_32 ( V_47 -> V_60 ) ;
F_33 ( V_50 , ( unsigned int ) ( V_35 * 8 ) , V_47 -> V_55 ,
V_47 -> V_56 ) ;
}
F_34 ( & V_4 -> V_31 . V_52 ,
F_2 ( V_47 -> V_2 ) , V_61 ) ;
}
static int F_35 ( struct V_3 * V_4 ,
struct V_46 * V_47 )
{
int V_32 ;
unsigned long V_62 = F_2 ( V_47 -> V_2 ) ;
struct V_49 * V_50 = & V_4 -> V_51 -> V_50 ;
struct V_5 * V_6 ;
struct V_30 * V_31 = & V_4 -> V_31 ;
V_32 = F_36 ( V_4 , & V_31 -> V_63 , V_62 ) ;
if ( V_32 )
return V_32 ;
V_6 = F_37 ( V_4 ) ;
if ( F_38 ( V_6 ) ) {
V_32 = F_39 ( V_6 ) ;
goto V_64;
}
V_32 = V_4 -> V_65 -> V_66 ( V_6 -> V_67 , V_47 , V_62 ) ;
if ( V_32 ) {
F_40 ( V_50 , L_2 ) ;
goto V_68;
}
V_32 = F_3 ( V_4 , V_6 ,
V_62 & ( V_4 -> V_58 . V_59 - 1 ) ) ;
if ( V_32 ) {
F_40 ( V_50 , L_3 , V_32 ) ;
goto V_68;
}
V_47 -> V_53 = 1 ;
F_41 ( V_4 , V_6 ) ;
return 0 ;
V_68:
F_41 ( V_4 , V_6 ) ;
V_64:
F_42 ( V_4 , & V_31 -> V_63 , V_62 ) ;
return V_32 ;
}
static int F_43 ( struct V_3 * V_4 ,
struct V_37 * V_38 , T_1 V_69 ,
T_1 V_35 , T_2 * V_70 )
{
T_1 V_23 = 0 ;
T_3 * V_71 = NULL ;
T_4 V_72 ;
T_1 V_24 = V_69 * sizeof( T_2 ) ;
if ( V_69 / ( V_73 / sizeof( T_2 ) ) !=
( V_69 + V_35 - 1 ) / ( V_73 / sizeof( T_2 ) ) )
return - V_74 ;
if ( V_69 & ( V_40 - 1 ) )
return - V_74 ;
V_71 = F_44 ( & V_4 -> V_31 . V_34 ,
V_38 -> V_41 + V_24 / V_4 -> V_58 . V_75 ,
& V_72 ) ;
if ( ! V_71 )
return - V_29 ;
for ( V_23 = 0 ; V_23 < V_35 ; ++ V_23 )
V_71 [ V_23 ] = ( F_45 ( V_70 [ V_23 ] ) ) >> V_76 ;
return 0 ;
}
static int F_46 ( struct V_3 * V_4 ,
struct V_37 * V_38 , T_1 V_69 ,
T_1 V_35 , T_2 * V_70 )
{
int V_77 ;
int V_32 ;
if ( V_38 -> V_14 < 0 )
return - V_74 ;
while ( V_35 > 0 ) {
V_77 = F_47 ( int , V_73 / sizeof( T_2 ) , V_35 ) ;
V_32 = F_43 ( V_4 , V_38 , V_69 , V_77 ,
V_70 ) ;
if ( V_32 )
return V_32 ;
V_35 -= V_77 ;
V_69 += V_77 ;
V_70 += V_77 ;
}
return 0 ;
}
int F_48 ( struct V_3 * V_4 ,
struct V_37 * V_38 , struct V_78 * V_67 )
{
T_1 V_23 = 0 ;
int V_32 = 0 ;
T_2 * V_70 = NULL ;
V_70 = F_49 ( V_67 -> V_35 , sizeof( * V_70 ) , V_25 ) ;
if ( ! V_70 )
return - V_29 ;
for ( V_23 = 0 ; V_23 < V_67 -> V_35 ; ++ V_23 ) {
if ( V_67 -> V_79 == 1 )
V_70 [ V_23 ] = V_67 -> V_80 . V_81 + ( V_23 << V_67 -> V_36 ) ;
else
V_70 [ V_23 ] = V_67 -> V_70 [ V_23 ] . V_81 ;
}
V_32 = F_46 ( V_4 , V_38 , 0 , V_67 -> V_35 , V_70 ) ;
F_20 ( V_70 ) ;
return V_32 ;
}
int F_50 ( struct V_3 * V_4 )
{
struct V_30 * V_31 = & V_4 -> V_31 ;
int V_32 = 0 ;
V_32 = F_51 ( & V_31 -> V_52 ,
V_4 -> V_58 . V_59 ,
V_4 -> V_58 . V_59 - 1 ,
V_4 -> V_58 . V_82 , 0 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_14 ( & V_31 -> V_33 ,
F_52 ( V_4 -> V_58 . V_83 ) ) ;
if ( V_32 )
goto V_84;
return 0 ;
V_84:
F_53 ( & V_31 -> V_52 ) ;
return V_32 ;
}
void F_54 ( struct V_3 * V_4 )
{
struct V_30 * V_31 = & V_4 -> V_31 ;
F_21 ( & V_31 -> V_33 ) ;
F_53 ( & V_31 -> V_52 ) ;
}
struct V_85 * F_55 ( struct V_86 * V_42 , int V_87 )
{
int V_32 = 0 ;
struct V_46 * V_47 = NULL ;
V_47 = F_56 ( sizeof( * V_47 ) , V_25 ) ;
if ( V_47 == NULL )
return F_57 ( - V_29 ) ;
V_32 = F_27 ( F_58 ( V_42 -> V_49 ) , F_59 ( V_42 ) -> V_88 , 0 ,
~ 0ULL , V_87 , 0 , V_47 ) ;
if ( V_32 )
goto V_89;
V_32 = F_35 ( F_58 ( V_42 -> V_49 ) , V_47 ) ;
if ( V_32 )
goto V_90;
V_47 -> V_91 . V_92 = V_47 -> V_91 . V_93 = V_47 -> V_2 ;
V_47 -> V_60 = NULL ;
return & V_47 -> V_91 ;
V_90:
F_30 ( F_58 ( V_42 -> V_49 ) , V_47 ) ;
V_89:
F_20 ( V_47 ) ;
return F_57 ( V_32 ) ;
}
int F_60 ( struct V_3 * V_4 ,
struct V_37 * V_38 , struct V_94 * V_60 )
{
struct V_95 * V_96 ;
int V_23 , V_97 , V_98 ;
int V_32 = 0 ;
T_2 * V_99 ;
T_1 V_100 ;
int V_101 ;
V_99 = ( T_2 * ) F_61 ( V_25 ) ;
if ( ! V_99 )
return - V_29 ;
V_23 = V_100 = 0 ;
F_62 (umem->sg_head.sgl, sg, umem->nmap, entry) {
V_101 = F_63 ( V_96 ) >> V_38 -> V_36 ;
for ( V_97 = 0 ; V_97 < V_101 ; ++ V_97 ) {
V_99 [ V_23 ++ ] = F_64 ( V_96 ) +
( V_97 << V_60 -> V_36 ) ;
if ( V_23 == V_73 / sizeof( T_2 ) ) {
V_32 = F_46 ( V_4 , V_38 , V_100 , V_23 ,
V_99 ) ;
if ( V_32 )
goto V_102;
V_100 += V_23 ;
V_23 = 0 ;
}
}
}
if ( V_23 )
V_32 = F_46 ( V_4 , V_38 , V_100 , V_23 , V_99 ) ;
V_102:
F_65 ( ( unsigned long ) V_99 ) ;
return V_32 ;
}
static int F_66 ( struct V_46 * V_47 ,
struct V_94 * V_60 )
{
int V_23 = 0 ;
int V_98 ;
struct V_95 * V_96 ;
F_62 (umem->sg_head.sgl, sg, umem->nmap, entry) {
V_47 -> V_55 [ V_23 ] = ( ( T_2 ) F_64 ( V_96 ) ) >> 12 ;
V_23 ++ ;
}
F_67 () ;
return 0 ;
}
struct V_85 * F_68 ( struct V_86 * V_42 , T_2 V_103 , T_2 V_104 ,
T_2 V_105 , int V_106 ,
struct V_107 * V_108 )
{
struct V_3 * V_4 = F_58 ( V_42 -> V_49 ) ;
struct V_49 * V_50 = & V_4 -> V_51 -> V_50 ;
struct V_46 * V_47 = NULL ;
int V_32 = 0 ;
int V_100 = 0 ;
V_47 = F_56 ( sizeof( * V_47 ) , V_25 ) ;
if ( ! V_47 )
return F_57 ( - V_29 ) ;
V_47 -> V_60 = F_69 ( V_42 -> V_109 -> V_110 , V_103 , V_104 ,
V_106 , 0 ) ;
if ( F_38 ( V_47 -> V_60 ) ) {
V_32 = F_39 ( V_47 -> V_60 ) ;
goto V_89;
}
V_100 = F_32 ( V_47 -> V_60 ) ;
if ( V_47 -> V_60 -> V_36 != V_39 ) {
F_40 ( V_50 , L_4 ,
F_70 ( V_47 -> V_60 -> V_36 ) ) ;
V_32 = - V_74 ;
goto V_111;
}
if ( V_100 > V_112 ) {
F_40 ( V_50 , L_5 ,
V_104 ) ;
V_32 = - V_74 ;
goto V_111;
}
V_32 = F_27 ( V_4 , F_59 ( V_42 ) -> V_88 , V_105 , V_104 ,
V_106 , V_100 , V_47 ) ;
if ( V_32 )
goto V_111;
V_32 = F_66 ( V_47 , V_47 -> V_60 ) ;
if ( V_32 )
goto V_90;
V_32 = F_35 ( V_4 , V_47 ) ;
if ( V_32 )
goto V_90;
V_47 -> V_91 . V_92 = V_47 -> V_91 . V_93 = V_47 -> V_2 ;
return & V_47 -> V_91 ;
V_90:
F_30 ( V_4 , V_47 ) ;
V_111:
F_71 ( V_47 -> V_60 ) ;
V_89:
F_20 ( V_47 ) ;
return F_57 ( V_32 ) ;
}
int F_72 ( struct V_85 * V_91 )
{
struct V_3 * V_4 = F_58 ( V_91 -> V_49 ) ;
struct V_46 * V_47 = F_73 ( V_91 ) ;
int V_32 = 0 ;
if ( V_4 -> V_65 -> V_113 ) {
V_32 = V_4 -> V_65 -> V_113 ( V_4 , V_47 ) ;
} else {
F_30 ( V_4 , V_47 ) ;
if ( V_47 -> V_60 )
F_71 ( V_47 -> V_60 ) ;
F_20 ( V_47 ) ;
}
return V_32 ;
}
