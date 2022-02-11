static struct V_1 * F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
return (struct V_1 * ) ( V_5 + 1 ) ;
}
static T_1 * F_2 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
return ( T_1 * ) ( V_5 + 1 ) + V_3 -> V_6 ;
}
static T_1 * F_3 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
return ( T_1 * ) ( V_5 + 1 ) + V_3 -> V_6 + V_3 -> V_7 ;
}
static void F_4 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
V_11 -> V_12 = 0 ;
}
static T_2 F_6 ( struct V_2 * V_3 , T_2 V_13 )
{
return V_3 -> V_14 + F_7 ( V_3 -> V_15 , V_13 ) ;
}
static T_2 F_8 ( struct V_2 * V_3 , T_2 V_16 ,
int V_17 )
{
return V_16 >> ( V_17 * V_3 -> V_18 ) ;
}
static void F_9 ( struct V_2 * V_3 , T_2 V_16 , int V_17 ,
T_2 * V_19 , unsigned * V_20 )
{
T_2 V_21 = F_8 ( V_3 , V_16 , V_17 ) ;
unsigned V_22 ;
* V_19 = V_3 -> V_23 [ V_17 ] + ( V_21 >> V_3 -> V_18 ) ;
if ( ! V_20 )
return;
V_22 = V_21 & ( ( 1 << V_3 -> V_18 ) - 1 ) ;
if ( ! V_3 -> V_24 )
* V_20 = V_22 * V_3 -> V_7 ;
else
* V_20 = V_22 << ( V_3 -> V_25 - V_3 -> V_18 ) ;
}
static int F_10 ( struct V_4 * V_5 , T_2 V_16 ,
int V_17 , bool V_26 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
T_1 * V_27 ;
int V_28 ;
T_2 V_19 ;
unsigned V_20 ;
F_9 ( V_3 , V_16 , V_17 , & V_19 , & V_20 ) ;
V_27 = F_11 ( V_3 -> V_29 , V_19 , & V_9 ) ;
if ( F_12 ( F_13 ( V_27 ) ) )
return F_14 ( V_27 ) ;
V_11 = F_5 ( V_9 ) ;
if ( ! V_11 -> V_12 ) {
struct V_1 * V_30 ;
T_1 * V_31 ;
if ( V_26 ) {
V_28 = 1 ;
goto V_32;
}
V_30 = F_1 ( V_3 , V_5 ) ;
V_30 -> V_33 = V_3 -> V_33 ;
V_30 -> V_34 = V_35 ;
V_28 = F_15 ( V_30 ) ;
if ( V_28 < 0 ) {
F_16 ( L_1 , V_28 ) ;
goto V_32;
}
if ( F_17 ( V_3 -> V_24 >= 1 ) ) {
V_28 = F_18 ( V_30 , V_3 -> V_36 , V_3 -> V_37 ) ;
if ( V_28 < 0 ) {
F_16 ( L_2 , V_28 ) ;
goto V_32;
}
}
V_28 = F_18 ( V_30 , V_27 , 1 << V_3 -> V_25 ) ;
if ( V_28 < 0 ) {
F_16 ( L_2 , V_28 ) ;
goto V_32;
}
if ( ! V_3 -> V_24 ) {
V_28 = F_18 ( V_30 , V_3 -> V_36 , V_3 -> V_37 ) ;
if ( V_28 < 0 ) {
F_16 ( L_2 , V_28 ) ;
goto V_32;
}
}
V_31 = F_2 ( V_3 , V_5 ) ;
V_28 = F_19 ( V_30 , V_31 ) ;
if ( V_28 < 0 ) {
F_16 ( L_3 , V_28 ) ;
goto V_32;
}
if ( F_12 ( memcmp ( V_31 , F_3 ( V_3 , V_5 ) , V_3 -> V_7 ) ) ) {
F_20 ( L_4 ,
( unsigned long long ) V_19 ) ;
V_3 -> V_38 = 1 ;
V_28 = - V_39 ;
goto V_32;
} else
V_11 -> V_12 = 1 ;
}
V_27 += V_20 ;
memcpy ( F_3 ( V_3 , V_5 ) , V_27 , V_3 -> V_7 ) ;
F_21 ( V_9 ) ;
return 0 ;
V_32:
F_21 ( V_9 ) ;
return V_28 ;
}
static int F_22 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
unsigned V_40 ;
int V_41 ;
unsigned V_42 = 0 , V_20 = 0 ;
for ( V_40 = 0 ; V_40 < V_5 -> V_43 ; V_40 ++ ) {
struct V_1 * V_30 ;
T_1 * V_31 ;
int V_28 ;
unsigned V_44 ;
if ( F_17 ( V_3 -> V_45 ) ) {
int V_28 = F_10 ( V_5 , V_5 -> V_16 + V_40 , 0 , true ) ;
if ( F_17 ( ! V_28 ) )
goto V_46;
if ( V_28 < 0 )
return V_28 ;
}
memcpy ( F_3 ( V_3 , V_5 ) , V_3 -> V_47 , V_3 -> V_7 ) ;
for ( V_41 = V_3 -> V_45 - 1 ; V_41 >= 0 ; V_41 -- ) {
int V_28 = F_10 ( V_5 , V_5 -> V_16 + V_40 , V_41 , false ) ;
if ( F_12 ( V_28 ) )
return V_28 ;
}
V_46:
V_30 = F_1 ( V_3 , V_5 ) ;
V_30 -> V_33 = V_3 -> V_33 ;
V_30 -> V_34 = V_35 ;
V_28 = F_15 ( V_30 ) ;
if ( V_28 < 0 ) {
F_16 ( L_1 , V_28 ) ;
return V_28 ;
}
if ( F_17 ( V_3 -> V_24 >= 1 ) ) {
V_28 = F_18 ( V_30 , V_3 -> V_36 , V_3 -> V_37 ) ;
if ( V_28 < 0 ) {
F_16 ( L_2 , V_28 ) ;
return V_28 ;
}
}
V_44 = 1 << V_3 -> V_48 ;
do {
struct V_49 * V_50 ;
T_1 * V_51 ;
unsigned V_52 ;
F_23 ( V_42 >= V_5 -> V_53 ) ;
V_50 = & V_5 -> V_54 [ V_42 ] ;
V_51 = F_24 ( V_50 -> V_55 ) ;
V_52 = V_50 -> V_56 - V_20 ;
if ( F_17 ( V_52 >= V_44 ) )
V_52 = V_44 ;
V_28 = F_18 ( V_30 ,
V_51 + V_50 -> V_57 + V_20 , V_52 ) ;
F_25 ( V_51 ) ;
if ( V_28 < 0 ) {
F_16 ( L_2 , V_28 ) ;
return V_28 ;
}
V_20 += V_52 ;
if ( F_17 ( V_20 == V_50 -> V_56 ) ) {
V_20 = 0 ;
V_42 ++ ;
}
V_44 -= V_52 ;
} while ( V_44 );
if ( ! V_3 -> V_24 ) {
V_28 = F_18 ( V_30 , V_3 -> V_36 , V_3 -> V_37 ) ;
if ( V_28 < 0 ) {
F_16 ( L_2 , V_28 ) ;
return V_28 ;
}
}
V_31 = F_2 ( V_3 , V_5 ) ;
V_28 = F_19 ( V_30 , V_31 ) ;
if ( V_28 < 0 ) {
F_16 ( L_3 , V_28 ) ;
return V_28 ;
}
if ( F_12 ( memcmp ( V_31 , F_3 ( V_3 , V_5 ) , V_3 -> V_7 ) ) ) {
F_20 ( L_5 ,
( unsigned long long ) ( V_5 -> V_16 + V_40 ) ) ;
V_3 -> V_38 = 1 ;
return - V_39 ;
}
}
F_23 ( V_42 != V_5 -> V_53 ) ;
F_23 ( V_20 ) ;
return 0 ;
}
static void F_26 ( struct V_4 * V_5 , int error )
{
struct V_58 * V_58 = V_5 -> V_58 ;
struct V_2 * V_3 = V_5 -> V_3 ;
V_58 -> V_59 = V_5 -> V_60 ;
V_58 -> V_61 = V_5 -> V_62 ;
if ( V_5 -> V_54 != V_5 -> V_63 )
F_27 ( V_5 -> V_54 , V_3 -> V_64 ) ;
F_27 ( V_5 , V_3 -> V_65 ) ;
F_28 ( V_58 , error ) ;
}
static void F_29 ( struct V_66 * V_67 )
{
struct V_4 * V_5 = F_30 ( V_67 , struct V_4 , V_68 ) ;
F_26 ( V_5 , F_22 ( V_5 ) ) ;
}
static void F_31 ( struct V_58 * V_58 , int error )
{
struct V_4 * V_5 = V_58 -> V_61 ;
if ( error ) {
F_26 ( V_5 , error ) ;
return;
}
F_32 ( & V_5 -> V_68 , F_29 ) ;
F_33 ( V_5 -> V_3 -> V_69 , & V_5 -> V_68 ) ;
}
static void F_34 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_41 ;
for ( V_41 = V_3 -> V_45 - 2 ; V_41 >= 0 ; V_41 -- ) {
T_2 V_70 ;
T_2 V_71 ;
F_9 ( V_3 , V_5 -> V_16 , V_41 , & V_70 , NULL ) ;
F_9 ( V_3 , V_5 -> V_16 + V_5 -> V_43 - 1 , V_41 , & V_71 , NULL ) ;
if ( ! V_41 ) {
unsigned V_72 = * ( volatile unsigned * ) & V_73 ;
V_72 >>= V_3 -> V_48 ;
if ( F_12 ( ! V_72 ) )
goto V_74;
if ( F_12 ( V_72 & ( V_72 - 1 ) ) )
V_72 = 1 << ( F_35 ( V_72 ) - 1 ) ;
V_70 &= ~ ( T_2 ) ( V_72 - 1 ) ;
V_71 |= V_72 - 1 ;
if ( F_12 ( V_71 >= V_3 -> V_75 ) )
V_71 = V_3 -> V_75 - 1 ;
}
V_74:
F_36 ( V_3 -> V_29 , V_70 ,
V_71 - V_70 + 1 ) ;
}
}
static int F_37 ( struct V_76 * V_15 , struct V_58 * V_58 ,
union V_77 * V_78 )
{
struct V_2 * V_3 = V_15 -> V_79 ;
struct V_4 * V_5 ;
V_58 -> V_80 = V_3 -> V_81 -> V_82 ;
V_58 -> V_13 = F_6 ( V_3 , V_58 -> V_13 ) ;
if ( ( ( unsigned ) V_58 -> V_13 | F_38 ( V_58 ) ) &
( ( 1 << ( V_3 -> V_48 - V_83 ) ) - 1 ) ) {
F_20 ( L_6 ) ;
return - V_39 ;
}
if ( ( V_58 -> V_13 + F_38 ( V_58 ) ) >>
( V_3 -> V_48 - V_83 ) > V_3 -> V_84 ) {
F_20 ( L_7 ) ;
return - V_39 ;
}
if ( F_39 ( V_58 ) == V_85 )
return - V_39 ;
V_5 = F_40 ( V_3 -> V_65 , V_86 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_58 = V_58 ;
V_5 -> V_60 = V_58 -> V_59 ;
V_5 -> V_62 = V_58 -> V_61 ;
V_5 -> V_16 = V_58 -> V_13 >> ( V_3 -> V_48 - V_83 ) ;
V_5 -> V_43 = V_58 -> V_87 >> V_3 -> V_48 ;
V_58 -> V_59 = F_31 ;
V_58 -> V_61 = V_5 ;
V_5 -> V_53 = V_58 -> V_88 - V_58 -> V_89 ;
if ( V_5 -> V_53 < V_90 )
V_5 -> V_54 = V_5 -> V_63 ;
else
V_5 -> V_54 = F_40 ( V_3 -> V_64 , V_86 ) ;
memcpy ( V_5 -> V_54 , F_41 ( V_58 ) ,
V_5 -> V_53 * sizeof( struct V_49 ) ) ;
F_34 ( V_3 , V_5 ) ;
F_42 ( V_58 ) ;
return V_91 ;
}
static int F_43 ( struct V_76 * V_15 , T_3 type ,
unsigned V_92 , char * V_31 , unsigned V_93 )
{
struct V_2 * V_3 = V_15 -> V_79 ;
unsigned V_94 = 0 ;
unsigned V_95 ;
switch ( type ) {
case V_96 :
F_44 ( L_8 , V_3 -> V_38 ? 'C' : 'V' ) ;
break;
case V_97 :
F_44 ( L_9 ,
V_3 -> V_24 ,
V_3 -> V_81 -> V_98 ,
V_3 -> V_99 -> V_98 ,
1 << V_3 -> V_48 ,
1 << V_3 -> V_25 ,
( unsigned long long ) V_3 -> V_84 ,
( unsigned long long ) V_3 -> V_100 ,
V_3 -> V_101
) ;
for ( V_95 = 0 ; V_95 < V_3 -> V_7 ; V_95 ++ )
F_44 ( L_10 , V_3 -> V_47 [ V_95 ] ) ;
F_44 ( L_11 ) ;
if ( ! V_3 -> V_37 )
F_44 ( L_12 ) ;
else
for ( V_95 = 0 ; V_95 < V_3 -> V_37 ; V_95 ++ )
F_44 ( L_10 , V_3 -> V_36 [ V_95 ] ) ;
break;
}
return 0 ;
}
static int F_45 ( struct V_76 * V_15 , unsigned V_102 ,
unsigned long V_103 )
{
struct V_2 * V_3 = V_15 -> V_79 ;
int V_28 = 0 ;
if ( V_3 -> V_14 ||
V_15 -> V_52 != F_46 ( V_3 -> V_81 -> V_82 -> V_104 ) >> V_83 )
V_28 = F_47 ( NULL , V_102 ) ;
return V_28 ? : F_48 ( V_3 -> V_81 -> V_82 , V_3 -> V_81 -> V_105 ,
V_102 , V_103 ) ;
}
static int F_49 ( struct V_76 * V_15 , struct V_106 * V_107 ,
struct V_49 * V_108 , int V_109 )
{
struct V_2 * V_3 = V_15 -> V_79 ;
struct V_110 * V_111 = F_50 ( V_3 -> V_81 -> V_82 ) ;
if ( ! V_111 -> V_112 )
return V_109 ;
V_107 -> V_80 = V_3 -> V_81 -> V_82 ;
V_107 -> V_13 = F_6 ( V_3 , V_107 -> V_13 ) ;
return F_51 ( V_109 , V_111 -> V_112 ( V_111 , V_107 , V_108 ) ) ;
}
static int F_52 ( struct V_76 * V_15 ,
T_4 V_113 , void * V_27 )
{
struct V_2 * V_3 = V_15 -> V_79 ;
return V_113 ( V_15 , V_3 -> V_81 , V_3 -> V_14 , V_15 -> V_52 , V_27 ) ;
}
static void F_53 ( struct V_76 * V_15 , struct V_114 * V_115 )
{
struct V_2 * V_3 = V_15 -> V_79 ;
if ( V_115 -> V_116 < 1 << V_3 -> V_48 )
V_115 -> V_116 = 1 << V_3 -> V_48 ;
if ( V_115 -> V_117 < 1 << V_3 -> V_48 )
V_115 -> V_117 = 1 << V_3 -> V_48 ;
F_54 ( V_115 , V_115 -> V_116 ) ;
}
static void F_55 ( struct V_76 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_79 ;
if ( V_3 -> V_69 )
F_56 ( V_3 -> V_69 ) ;
if ( V_3 -> V_64 )
F_57 ( V_3 -> V_64 ) ;
if ( V_3 -> V_65 )
F_57 ( V_3 -> V_65 ) ;
if ( V_3 -> V_29 )
F_58 ( V_3 -> V_29 ) ;
F_59 ( V_3 -> V_36 ) ;
F_59 ( V_3 -> V_47 ) ;
if ( V_3 -> V_33 )
F_60 ( V_3 -> V_33 ) ;
F_59 ( V_3 -> V_101 ) ;
if ( V_3 -> V_99 )
F_61 ( V_15 , V_3 -> V_99 ) ;
if ( V_3 -> V_81 )
F_61 ( V_15 , V_3 -> V_81 ) ;
F_59 ( V_3 ) ;
}
static int F_62 ( struct V_76 * V_15 , unsigned V_118 , char * * V_119 )
{
struct V_2 * V_3 ;
unsigned V_120 ;
unsigned long long V_121 ;
int V_28 ;
int V_41 ;
T_2 V_122 ;
char V_123 ;
V_3 = F_63 ( sizeof( struct V_2 ) , V_124 ) ;
if ( ! V_3 ) {
V_15 -> error = L_13 ;
return - V_125 ;
}
V_15 -> V_79 = V_3 ;
V_3 -> V_15 = V_15 ;
if ( ( F_64 ( V_15 -> V_126 ) & ~ V_127 ) ) {
V_15 -> error = L_14 ;
V_28 = - V_128 ;
goto V_129;
}
if ( V_118 != 10 ) {
V_15 -> error = L_15 ;
V_28 = - V_128 ;
goto V_129;
}
if ( sscanf ( V_119 [ 0 ] , L_16 , & V_120 , & V_123 ) != 1 ||
V_120 < 0 || V_120 > 1 ) {
V_15 -> error = L_17 ;
V_28 = - V_128 ;
goto V_129;
}
V_3 -> V_24 = V_120 ;
V_28 = F_65 ( V_15 , V_119 [ 1 ] , V_127 , & V_3 -> V_81 ) ;
if ( V_28 ) {
V_15 -> error = L_18 ;
goto V_129;
}
V_28 = F_65 ( V_15 , V_119 [ 2 ] , V_127 , & V_3 -> V_99 ) ;
if ( V_28 ) {
V_15 -> error = L_18 ;
goto V_129;
}
if ( sscanf ( V_119 [ 3 ] , L_19 , & V_120 , & V_123 ) != 1 ||
! V_120 || ( V_120 & ( V_120 - 1 ) ) ||
V_120 < V_130 ( V_3 -> V_81 -> V_82 ) ||
V_120 > V_131 ) {
V_15 -> error = L_20 ;
V_28 = - V_128 ;
goto V_129;
}
V_3 -> V_48 = F_66 ( V_120 ) - 1 ;
if ( sscanf ( V_119 [ 4 ] , L_19 , & V_120 , & V_123 ) != 1 ||
! V_120 || ( V_120 & ( V_120 - 1 ) ) ||
V_120 < V_130 ( V_3 -> V_99 -> V_82 ) ||
V_120 > V_132 ) {
V_15 -> error = L_21 ;
V_28 = - V_128 ;
goto V_129;
}
V_3 -> V_25 = F_66 ( V_120 ) - 1 ;
if ( sscanf ( V_119 [ 5 ] , L_22 , & V_121 , & V_123 ) != 1 ||
( T_2 ) ( V_121 << ( V_3 -> V_48 - V_83 ) )
>> ( V_3 -> V_48 - V_83 ) != V_121 ) {
V_15 -> error = L_23 ;
V_28 = - V_128 ;
goto V_129;
}
V_3 -> V_84 = V_121 ;
if ( V_15 -> V_52 > ( V_3 -> V_84 << ( V_3 -> V_48 - V_83 ) ) ) {
V_15 -> error = L_24 ;
V_28 = - V_128 ;
goto V_129;
}
if ( sscanf ( V_119 [ 6 ] , L_22 , & V_121 , & V_123 ) != 1 ||
( T_2 ) ( V_121 << ( V_3 -> V_25 - V_83 ) )
>> ( V_3 -> V_25 - V_83 ) != V_121 ) {
V_15 -> error = L_25 ;
V_28 = - V_128 ;
goto V_129;
}
V_3 -> V_100 = V_121 ;
V_3 -> V_101 = F_67 ( V_119 [ 7 ] , V_124 ) ;
if ( ! V_3 -> V_101 ) {
V_15 -> error = L_26 ;
V_28 = - V_125 ;
goto V_129;
}
V_3 -> V_33 = F_68 ( V_3 -> V_101 , 0 , 0 ) ;
if ( F_13 ( V_3 -> V_33 ) ) {
V_15 -> error = L_27 ;
V_28 = F_14 ( V_3 -> V_33 ) ;
V_3 -> V_33 = NULL ;
goto V_129;
}
V_3 -> V_7 = F_69 ( V_3 -> V_33 ) ;
if ( ( 1 << V_3 -> V_25 ) < V_3 -> V_7 * 2 ) {
V_15 -> error = L_28 ;
V_28 = - V_128 ;
goto V_129;
}
V_3 -> V_6 =
sizeof( struct V_1 ) + F_70 ( V_3 -> V_33 ) ;
V_3 -> V_47 = F_71 ( V_3 -> V_7 , V_124 ) ;
if ( ! V_3 -> V_47 ) {
V_15 -> error = L_29 ;
V_28 = - V_125 ;
goto V_129;
}
if ( strlen ( V_119 [ 8 ] ) != V_3 -> V_7 * 2 ||
F_72 ( V_3 -> V_47 , V_119 [ 8 ] , V_3 -> V_7 ) ) {
V_15 -> error = L_30 ;
V_28 = - V_128 ;
goto V_129;
}
if ( strcmp ( V_119 [ 9 ] , L_12 ) ) {
V_3 -> V_37 = strlen ( V_119 [ 9 ] ) / 2 ;
V_3 -> V_36 = F_71 ( V_3 -> V_37 , V_124 ) ;
if ( ! V_3 -> V_36 ) {
V_15 -> error = L_31 ;
V_28 = - V_125 ;
goto V_129;
}
if ( strlen ( V_119 [ 9 ] ) != V_3 -> V_37 * 2 ||
F_72 ( V_3 -> V_36 , V_119 [ 9 ] , V_3 -> V_37 ) ) {
V_15 -> error = L_32 ;
V_28 = - V_128 ;
goto V_129;
}
}
V_3 -> V_18 =
F_35 ( ( 1 << V_3 -> V_25 ) / V_3 -> V_7 ) - 1 ;
V_3 -> V_45 = 0 ;
if ( V_3 -> V_84 )
while ( V_3 -> V_18 * V_3 -> V_45 < 64 &&
( unsigned long long ) ( V_3 -> V_84 - 1 ) >>
( V_3 -> V_18 * V_3 -> V_45 ) )
V_3 -> V_45 ++ ;
if ( V_3 -> V_45 > V_133 ) {
V_15 -> error = L_33 ;
V_28 = - V_134 ;
goto V_129;
}
V_122 = V_3 -> V_100 ;
for ( V_41 = V_3 -> V_45 - 1 ; V_41 >= 0 ; V_41 -- ) {
T_2 V_135 ;
V_3 -> V_23 [ V_41 ] = V_122 ;
V_135 = F_8 ( V_3 , V_3 -> V_84 , V_41 ) ;
V_135 = ( V_135 >> V_3 -> V_18 ) +
! ! ( V_135 & ( ( 1 << V_3 -> V_18 ) - 1 ) ) ;
if ( V_122 + V_135 < V_122 ) {
V_15 -> error = L_34 ;
V_28 = - V_134 ;
goto V_129;
}
V_122 += V_135 ;
}
V_3 -> V_75 = V_122 ;
V_3 -> V_29 = F_73 ( V_3 -> V_99 -> V_82 ,
1 << V_3 -> V_25 , 1 , sizeof( struct V_10 ) ,
F_4 , NULL ) ;
if ( F_13 ( V_3 -> V_29 ) ) {
V_15 -> error = L_35 ;
V_28 = F_14 ( V_3 -> V_29 ) ;
V_3 -> V_29 = NULL ;
goto V_129;
}
if ( F_74 ( V_3 -> V_29 ) < V_3 -> V_75 ) {
V_15 -> error = L_36 ;
V_28 = - V_134 ;
goto V_129;
}
V_3 -> V_65 = F_75 ( V_136 ,
sizeof( struct V_4 ) + V_3 -> V_6 + V_3 -> V_7 * 2 ) ;
if ( ! V_3 -> V_65 ) {
V_15 -> error = L_37 ;
V_28 = - V_125 ;
goto V_129;
}
V_3 -> V_64 = F_75 ( V_136 ,
V_137 * sizeof( struct V_49 ) ) ;
if ( ! V_3 -> V_64 ) {
V_15 -> error = L_38 ;
V_28 = - V_125 ;
goto V_129;
}
V_3 -> V_69 = F_76 ( L_39 , V_138 | V_139 | V_140 , F_77 () ) ;
if ( ! V_3 -> V_69 ) {
V_15 -> error = L_40 ;
V_28 = - V_125 ;
goto V_129;
}
return 0 ;
V_129:
F_55 ( V_15 ) ;
return V_28 ;
}
static int T_5 F_78 ( void )
{
int V_28 ;
V_28 = F_79 ( & V_141 ) ;
if ( V_28 < 0 )
F_16 ( L_41 , V_28 ) ;
return V_28 ;
}
static void T_6 F_80 ( void )
{
F_81 ( & V_141 ) ;
}
