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
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_58 * V_58 = F_27 ( V_5 , V_3 -> V_15 -> V_59 ) ;
V_58 -> V_60 = V_5 -> V_61 ;
V_58 -> V_62 = V_5 -> V_63 ;
if ( V_5 -> V_54 != V_5 -> V_64 )
F_28 ( V_5 -> V_54 , V_3 -> V_65 ) ;
F_29 ( V_58 , error ) ;
}
static void F_30 ( struct V_66 * V_67 )
{
struct V_4 * V_5 = F_31 ( V_67 , struct V_4 , V_68 ) ;
F_26 ( V_5 , F_22 ( V_5 ) ) ;
}
static void F_32 ( struct V_58 * V_58 , int error )
{
struct V_4 * V_5 = V_58 -> V_62 ;
if ( error ) {
F_26 ( V_5 , error ) ;
return;
}
F_33 ( & V_5 -> V_68 , F_30 ) ;
F_34 ( V_5 -> V_3 -> V_69 , & V_5 -> V_68 ) ;
}
static void F_35 ( struct V_66 * V_68 )
{
struct V_70 * V_71 =
F_31 ( V_68 , struct V_70 , V_68 ) ;
struct V_2 * V_3 = V_71 -> V_3 ;
int V_41 ;
for ( V_41 = V_3 -> V_45 - 2 ; V_41 >= 0 ; V_41 -- ) {
T_2 V_72 ;
T_2 V_73 ;
F_9 ( V_3 , V_71 -> V_16 , V_41 , & V_72 , NULL ) ;
F_9 ( V_3 , V_71 -> V_16 + V_71 -> V_43 - 1 , V_41 , & V_73 , NULL ) ;
if ( ! V_41 ) {
unsigned V_74 = F_36 ( V_75 ) ;
V_74 >>= V_3 -> V_48 ;
if ( F_12 ( ! V_74 ) )
goto V_76;
if ( F_12 ( V_74 & ( V_74 - 1 ) ) )
V_74 = 1 << F_37 ( V_74 ) ;
V_72 &= ~ ( T_2 ) ( V_74 - 1 ) ;
V_73 |= V_74 - 1 ;
if ( F_12 ( V_73 >= V_3 -> V_77 ) )
V_73 = V_3 -> V_77 - 1 ;
}
V_76:
F_38 ( V_3 -> V_29 , V_72 ,
V_73 - V_72 + 1 ) ;
}
F_39 ( V_71 ) ;
}
static void F_40 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_70 * V_71 ;
V_71 = F_41 ( sizeof( struct V_70 ) ,
V_78 | V_79 | V_80 | V_81 ) ;
if ( ! V_71 )
return;
F_33 ( & V_71 -> V_68 , F_35 ) ;
V_71 -> V_3 = V_3 ;
V_71 -> V_16 = V_5 -> V_16 ;
V_71 -> V_43 = V_5 -> V_43 ;
F_34 ( V_3 -> V_69 , & V_71 -> V_68 ) ;
}
static int F_42 ( struct V_82 * V_15 , struct V_58 * V_58 )
{
struct V_2 * V_3 = V_15 -> V_83 ;
struct V_4 * V_5 ;
V_58 -> V_84 = V_3 -> V_85 -> V_86 ;
V_58 -> V_13 = F_6 ( V_3 , V_58 -> V_13 ) ;
if ( ( ( unsigned ) V_58 -> V_13 | F_43 ( V_58 ) ) &
( ( 1 << ( V_3 -> V_48 - V_87 ) ) - 1 ) ) {
F_20 ( L_6 ) ;
return - V_39 ;
}
if ( F_44 ( V_58 ) >>
( V_3 -> V_48 - V_87 ) > V_3 -> V_88 ) {
F_20 ( L_7 ) ;
return - V_39 ;
}
if ( F_45 ( V_58 ) == V_89 )
return - V_39 ;
V_5 = F_46 ( V_58 , V_15 -> V_59 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_61 = V_58 -> V_60 ;
V_5 -> V_63 = V_58 -> V_62 ;
V_5 -> V_16 = V_58 -> V_13 >> ( V_3 -> V_48 - V_87 ) ;
V_5 -> V_43 = V_58 -> V_90 >> V_3 -> V_48 ;
V_58 -> V_60 = F_32 ;
V_58 -> V_62 = V_5 ;
V_5 -> V_53 = F_47 ( V_58 ) ;
if ( V_5 -> V_53 < V_91 )
V_5 -> V_54 = V_5 -> V_64 ;
else
V_5 -> V_54 = F_48 ( V_3 -> V_65 , V_78 ) ;
memcpy ( V_5 -> V_54 , F_49 ( V_58 ) ,
V_5 -> V_53 * sizeof( struct V_49 ) ) ;
F_40 ( V_3 , V_5 ) ;
F_50 ( V_58 ) ;
return V_92 ;
}
static void F_51 ( struct V_82 * V_15 , T_3 type ,
unsigned V_93 , char * V_31 , unsigned V_94 )
{
struct V_2 * V_3 = V_15 -> V_83 ;
unsigned V_95 = 0 ;
unsigned V_96 ;
switch ( type ) {
case V_97 :
F_52 ( L_8 , V_3 -> V_38 ? 'C' : 'V' ) ;
break;
case V_98 :
F_52 ( L_9 ,
V_3 -> V_24 ,
V_3 -> V_85 -> V_99 ,
V_3 -> V_100 -> V_99 ,
1 << V_3 -> V_48 ,
1 << V_3 -> V_25 ,
( unsigned long long ) V_3 -> V_88 ,
( unsigned long long ) V_3 -> V_101 ,
V_3 -> V_102
) ;
for ( V_96 = 0 ; V_96 < V_3 -> V_7 ; V_96 ++ )
F_52 ( L_10 , V_3 -> V_47 [ V_96 ] ) ;
F_52 ( L_11 ) ;
if ( ! V_3 -> V_37 )
F_52 ( L_12 ) ;
else
for ( V_96 = 0 ; V_96 < V_3 -> V_37 ; V_96 ++ )
F_52 ( L_10 , V_3 -> V_36 [ V_96 ] ) ;
break;
}
}
static int F_53 ( struct V_82 * V_15 , unsigned V_103 ,
unsigned long V_104 )
{
struct V_2 * V_3 = V_15 -> V_83 ;
int V_28 = 0 ;
if ( V_3 -> V_14 ||
V_15 -> V_52 != F_54 ( V_3 -> V_85 -> V_86 -> V_105 ) >> V_87 )
V_28 = F_55 ( NULL , V_103 ) ;
return V_28 ? : F_56 ( V_3 -> V_85 -> V_86 , V_3 -> V_85 -> V_106 ,
V_103 , V_104 ) ;
}
static int F_57 ( struct V_82 * V_15 , struct V_107 * V_108 ,
struct V_49 * V_109 , int V_110 )
{
struct V_2 * V_3 = V_15 -> V_83 ;
struct V_111 * V_112 = F_58 ( V_3 -> V_85 -> V_86 ) ;
if ( ! V_112 -> V_113 )
return V_110 ;
V_108 -> V_84 = V_3 -> V_85 -> V_86 ;
V_108 -> V_13 = F_6 ( V_3 , V_108 -> V_13 ) ;
return F_59 ( V_110 , V_112 -> V_113 ( V_112 , V_108 , V_109 ) ) ;
}
static int F_60 ( struct V_82 * V_15 ,
T_4 V_114 , void * V_27 )
{
struct V_2 * V_3 = V_15 -> V_83 ;
return V_114 ( V_15 , V_3 -> V_85 , V_3 -> V_14 , V_15 -> V_52 , V_27 ) ;
}
static void F_61 ( struct V_82 * V_15 , struct V_115 * V_116 )
{
struct V_2 * V_3 = V_15 -> V_83 ;
if ( V_116 -> V_117 < 1 << V_3 -> V_48 )
V_116 -> V_117 = 1 << V_3 -> V_48 ;
if ( V_116 -> V_118 < 1 << V_3 -> V_48 )
V_116 -> V_118 = 1 << V_3 -> V_48 ;
F_62 ( V_116 , V_116 -> V_117 ) ;
}
static void F_63 ( struct V_82 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_83 ;
if ( V_3 -> V_69 )
F_64 ( V_3 -> V_69 ) ;
if ( V_3 -> V_65 )
F_65 ( V_3 -> V_65 ) ;
if ( V_3 -> V_29 )
F_66 ( V_3 -> V_29 ) ;
F_39 ( V_3 -> V_36 ) ;
F_39 ( V_3 -> V_47 ) ;
if ( V_3 -> V_33 )
F_67 ( V_3 -> V_33 ) ;
F_39 ( V_3 -> V_102 ) ;
if ( V_3 -> V_100 )
F_68 ( V_15 , V_3 -> V_100 ) ;
if ( V_3 -> V_85 )
F_68 ( V_15 , V_3 -> V_85 ) ;
F_39 ( V_3 ) ;
}
static int F_69 ( struct V_82 * V_15 , unsigned V_119 , char * * V_120 )
{
struct V_2 * V_3 ;
unsigned V_121 ;
unsigned long long V_122 ;
int V_28 ;
int V_41 ;
T_2 V_123 ;
char V_124 ;
V_3 = F_70 ( sizeof( struct V_2 ) , V_125 ) ;
if ( ! V_3 ) {
V_15 -> error = L_13 ;
return - V_126 ;
}
V_15 -> V_83 = V_3 ;
V_3 -> V_15 = V_15 ;
if ( ( F_71 ( V_15 -> V_127 ) & ~ V_128 ) ) {
V_15 -> error = L_14 ;
V_28 = - V_129 ;
goto V_130;
}
if ( V_119 != 10 ) {
V_15 -> error = L_15 ;
V_28 = - V_129 ;
goto V_130;
}
if ( sscanf ( V_120 [ 0 ] , L_16 , & V_121 , & V_124 ) != 1 ||
V_121 > 1 ) {
V_15 -> error = L_17 ;
V_28 = - V_129 ;
goto V_130;
}
V_3 -> V_24 = V_121 ;
V_28 = F_72 ( V_15 , V_120 [ 1 ] , V_128 , & V_3 -> V_85 ) ;
if ( V_28 ) {
V_15 -> error = L_18 ;
goto V_130;
}
V_28 = F_72 ( V_15 , V_120 [ 2 ] , V_128 , & V_3 -> V_100 ) ;
if ( V_28 ) {
V_15 -> error = L_18 ;
goto V_130;
}
if ( sscanf ( V_120 [ 3 ] , L_16 , & V_121 , & V_124 ) != 1 ||
! V_121 || ( V_121 & ( V_121 - 1 ) ) ||
V_121 < V_131 ( V_3 -> V_85 -> V_86 ) ||
V_121 > V_132 ) {
V_15 -> error = L_19 ;
V_28 = - V_129 ;
goto V_130;
}
V_3 -> V_48 = F_73 ( V_121 ) ;
if ( sscanf ( V_120 [ 4 ] , L_16 , & V_121 , & V_124 ) != 1 ||
! V_121 || ( V_121 & ( V_121 - 1 ) ) ||
V_121 < V_131 ( V_3 -> V_100 -> V_86 ) ||
V_121 > V_133 ) {
V_15 -> error = L_20 ;
V_28 = - V_129 ;
goto V_130;
}
V_3 -> V_25 = F_73 ( V_121 ) ;
if ( sscanf ( V_120 [ 5 ] , L_21 , & V_122 , & V_124 ) != 1 ||
( T_2 ) ( V_122 << ( V_3 -> V_48 - V_87 ) )
>> ( V_3 -> V_48 - V_87 ) != V_122 ) {
V_15 -> error = L_22 ;
V_28 = - V_129 ;
goto V_130;
}
V_3 -> V_88 = V_122 ;
if ( V_15 -> V_52 > ( V_3 -> V_88 << ( V_3 -> V_48 - V_87 ) ) ) {
V_15 -> error = L_23 ;
V_28 = - V_129 ;
goto V_130;
}
if ( sscanf ( V_120 [ 6 ] , L_21 , & V_122 , & V_124 ) != 1 ||
( T_2 ) ( V_122 << ( V_3 -> V_25 - V_87 ) )
>> ( V_3 -> V_25 - V_87 ) != V_122 ) {
V_15 -> error = L_24 ;
V_28 = - V_129 ;
goto V_130;
}
V_3 -> V_101 = V_122 ;
V_3 -> V_102 = F_74 ( V_120 [ 7 ] , V_125 ) ;
if ( ! V_3 -> V_102 ) {
V_15 -> error = L_25 ;
V_28 = - V_126 ;
goto V_130;
}
V_3 -> V_33 = F_75 ( V_3 -> V_102 , 0 , 0 ) ;
if ( F_13 ( V_3 -> V_33 ) ) {
V_15 -> error = L_26 ;
V_28 = F_14 ( V_3 -> V_33 ) ;
V_3 -> V_33 = NULL ;
goto V_130;
}
V_3 -> V_7 = F_76 ( V_3 -> V_33 ) ;
if ( ( 1 << V_3 -> V_25 ) < V_3 -> V_7 * 2 ) {
V_15 -> error = L_27 ;
V_28 = - V_129 ;
goto V_130;
}
V_3 -> V_6 =
sizeof( struct V_1 ) + F_77 ( V_3 -> V_33 ) ;
V_3 -> V_47 = F_41 ( V_3 -> V_7 , V_125 ) ;
if ( ! V_3 -> V_47 ) {
V_15 -> error = L_28 ;
V_28 = - V_126 ;
goto V_130;
}
if ( strlen ( V_120 [ 8 ] ) != V_3 -> V_7 * 2 ||
F_78 ( V_3 -> V_47 , V_120 [ 8 ] , V_3 -> V_7 ) ) {
V_15 -> error = L_29 ;
V_28 = - V_129 ;
goto V_130;
}
if ( strcmp ( V_120 [ 9 ] , L_12 ) ) {
V_3 -> V_37 = strlen ( V_120 [ 9 ] ) / 2 ;
V_3 -> V_36 = F_41 ( V_3 -> V_37 , V_125 ) ;
if ( ! V_3 -> V_36 ) {
V_15 -> error = L_30 ;
V_28 = - V_126 ;
goto V_130;
}
if ( strlen ( V_120 [ 9 ] ) != V_3 -> V_37 * 2 ||
F_78 ( V_3 -> V_36 , V_120 [ 9 ] , V_3 -> V_37 ) ) {
V_15 -> error = L_31 ;
V_28 = - V_129 ;
goto V_130;
}
}
V_3 -> V_18 =
F_37 ( ( 1 << V_3 -> V_25 ) / V_3 -> V_7 ) ;
V_3 -> V_45 = 0 ;
if ( V_3 -> V_88 )
while ( V_3 -> V_18 * V_3 -> V_45 < 64 &&
( unsigned long long ) ( V_3 -> V_88 - 1 ) >>
( V_3 -> V_18 * V_3 -> V_45 ) )
V_3 -> V_45 ++ ;
if ( V_3 -> V_45 > V_134 ) {
V_15 -> error = L_32 ;
V_28 = - V_135 ;
goto V_130;
}
V_123 = V_3 -> V_101 ;
for ( V_41 = V_3 -> V_45 - 1 ; V_41 >= 0 ; V_41 -- ) {
T_2 V_136 ;
V_3 -> V_23 [ V_41 ] = V_123 ;
V_136 = ( V_3 -> V_88 + ( ( T_2 ) 1 << ( ( V_41 + 1 ) * V_3 -> V_18 ) ) - 1 )
>> ( ( V_41 + 1 ) * V_3 -> V_18 ) ;
if ( V_123 + V_136 < V_123 ) {
V_15 -> error = L_33 ;
V_28 = - V_135 ;
goto V_130;
}
V_123 += V_136 ;
}
V_3 -> V_77 = V_123 ;
V_3 -> V_29 = F_79 ( V_3 -> V_100 -> V_86 ,
1 << V_3 -> V_25 , 1 , sizeof( struct V_10 ) ,
F_4 , NULL ) ;
if ( F_13 ( V_3 -> V_29 ) ) {
V_15 -> error = L_34 ;
V_28 = F_14 ( V_3 -> V_29 ) ;
V_3 -> V_29 = NULL ;
goto V_130;
}
if ( F_80 ( V_3 -> V_29 ) < V_3 -> V_77 ) {
V_15 -> error = L_35 ;
V_28 = - V_135 ;
goto V_130;
}
V_15 -> V_59 = F_81 ( sizeof( struct V_4 ) + V_3 -> V_6 + V_3 -> V_7 * 2 , F_82 ( struct V_4 ) ) ;
V_3 -> V_65 = F_83 ( V_137 ,
V_138 * sizeof( struct V_49 ) ) ;
if ( ! V_3 -> V_65 ) {
V_15 -> error = L_36 ;
V_28 = - V_126 ;
goto V_130;
}
V_3 -> V_69 = F_84 ( L_37 , V_139 | V_140 | V_141 , F_85 () ) ;
if ( ! V_3 -> V_69 ) {
V_15 -> error = L_38 ;
V_28 = - V_126 ;
goto V_130;
}
return 0 ;
V_130:
F_63 ( V_15 ) ;
return V_28 ;
}
static int T_5 F_86 ( void )
{
int V_28 ;
V_28 = F_87 ( & V_142 ) ;
if ( V_28 < 0 )
F_16 ( L_39 , V_28 ) ;
return V_28 ;
}
static void T_6 F_88 ( void )
{
F_89 ( & V_142 ) ;
}
