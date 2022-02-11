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
struct V_40 * V_40 = F_23 ( V_5 ,
V_3 -> V_15 -> V_41 ) ;
unsigned V_42 ;
int V_43 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_44 ; V_42 ++ ) {
struct V_1 * V_30 ;
T_1 * V_31 ;
int V_28 ;
unsigned V_45 ;
if ( F_17 ( V_3 -> V_46 ) ) {
int V_28 = F_10 ( V_5 , V_5 -> V_16 + V_42 , 0 , true ) ;
if ( F_17 ( ! V_28 ) )
goto V_47;
if ( V_28 < 0 )
return V_28 ;
}
memcpy ( F_3 ( V_3 , V_5 ) , V_3 -> V_48 , V_3 -> V_7 ) ;
for ( V_43 = V_3 -> V_46 - 1 ; V_43 >= 0 ; V_43 -- ) {
int V_28 = F_10 ( V_5 , V_5 -> V_16 + V_42 , V_43 , false ) ;
if ( F_12 ( V_28 ) )
return V_28 ;
}
V_47:
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
V_45 = 1 << V_3 -> V_49 ;
while ( V_5 -> V_50 . V_51 ) {
T_1 * V_52 ;
struct V_53 V_54 = F_24 ( V_40 , V_5 -> V_50 ) ;
V_52 = F_25 ( V_54 . V_55 ) ;
V_28 = F_18 ( V_30 , V_52 + V_54 . V_56 ,
V_54 . V_57 ) ;
F_26 ( V_52 ) ;
if ( V_28 < 0 ) {
F_16 ( L_2 , V_28 ) ;
return V_28 ;
}
F_27 ( V_40 , & V_5 -> V_50 , V_54 . V_57 ) ;
}
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
( unsigned long long ) ( V_5 -> V_16 + V_42 ) ) ;
V_3 -> V_38 = 1 ;
return - V_39 ;
}
}
return 0 ;
}
static void F_28 ( struct V_4 * V_5 , int error )
{
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_40 * V_40 = F_23 ( V_5 , V_3 -> V_15 -> V_41 ) ;
V_40 -> V_58 = V_5 -> V_59 ;
V_40 -> V_60 = V_5 -> V_61 ;
F_29 ( V_40 , error ) ;
}
static void F_30 ( struct V_62 * V_63 )
{
struct V_4 * V_5 = F_31 ( V_63 , struct V_4 , V_64 ) ;
F_28 ( V_5 , F_22 ( V_5 ) ) ;
}
static void F_32 ( struct V_40 * V_40 , int error )
{
struct V_4 * V_5 = V_40 -> V_60 ;
if ( error ) {
F_28 ( V_5 , error ) ;
return;
}
F_33 ( & V_5 -> V_64 , F_30 ) ;
F_34 ( V_5 -> V_3 -> V_65 , & V_5 -> V_64 ) ;
}
static void F_35 ( struct V_62 * V_64 )
{
struct V_66 * V_67 =
F_31 ( V_64 , struct V_66 , V_64 ) ;
struct V_2 * V_3 = V_67 -> V_3 ;
int V_43 ;
for ( V_43 = V_3 -> V_46 - 2 ; V_43 >= 0 ; V_43 -- ) {
T_2 V_68 ;
T_2 V_69 ;
F_9 ( V_3 , V_67 -> V_16 , V_43 , & V_68 , NULL ) ;
F_9 ( V_3 , V_67 -> V_16 + V_67 -> V_44 - 1 , V_43 , & V_69 , NULL ) ;
if ( ! V_43 ) {
unsigned V_70 = F_36 ( V_71 ) ;
V_70 >>= V_3 -> V_49 ;
if ( F_12 ( ! V_70 ) )
goto V_72;
if ( F_12 ( V_70 & ( V_70 - 1 ) ) )
V_70 = 1 << F_37 ( V_70 ) ;
V_68 &= ~ ( T_2 ) ( V_70 - 1 ) ;
V_69 |= V_70 - 1 ;
if ( F_12 ( V_69 >= V_3 -> V_73 ) )
V_69 = V_3 -> V_73 - 1 ;
}
V_72:
F_38 ( V_3 -> V_29 , V_68 ,
V_69 - V_68 + 1 ) ;
}
F_39 ( V_67 ) ;
}
static void F_40 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_66 * V_67 ;
V_67 = F_41 ( sizeof( struct V_66 ) ,
V_74 | V_75 | V_76 | V_77 ) ;
if ( ! V_67 )
return;
F_33 ( & V_67 -> V_64 , F_35 ) ;
V_67 -> V_3 = V_3 ;
V_67 -> V_16 = V_5 -> V_16 ;
V_67 -> V_44 = V_5 -> V_44 ;
F_34 ( V_3 -> V_65 , & V_67 -> V_64 ) ;
}
static int F_42 ( struct V_78 * V_15 , struct V_40 * V_40 )
{
struct V_2 * V_3 = V_15 -> V_79 ;
struct V_4 * V_5 ;
V_40 -> V_80 = V_3 -> V_81 -> V_82 ;
V_40 -> V_83 . V_13 = F_6 ( V_3 , V_40 -> V_83 . V_13 ) ;
if ( ( ( unsigned ) V_40 -> V_83 . V_13 | F_43 ( V_40 ) ) &
( ( 1 << ( V_3 -> V_49 - V_84 ) ) - 1 ) ) {
F_20 ( L_6 ) ;
return - V_39 ;
}
if ( F_44 ( V_40 ) >>
( V_3 -> V_49 - V_84 ) > V_3 -> V_85 ) {
F_20 ( L_7 ) ;
return - V_39 ;
}
if ( F_45 ( V_40 ) == V_86 )
return - V_39 ;
V_5 = F_46 ( V_40 , V_15 -> V_41 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_59 = V_40 -> V_58 ;
V_5 -> V_61 = V_40 -> V_60 ;
V_5 -> V_16 = V_40 -> V_83 . V_13 >> ( V_3 -> V_49 - V_84 ) ;
V_5 -> V_44 = V_40 -> V_83 . V_51 >> V_3 -> V_49 ;
V_40 -> V_58 = F_32 ;
V_40 -> V_60 = V_5 ;
V_5 -> V_50 = V_40 -> V_83 ;
F_40 ( V_3 , V_5 ) ;
F_47 ( V_40 ) ;
return V_87 ;
}
static void F_48 ( struct V_78 * V_15 , T_3 type ,
unsigned V_88 , char * V_31 , unsigned V_89 )
{
struct V_2 * V_3 = V_15 -> V_79 ;
unsigned V_90 = 0 ;
unsigned V_91 ;
switch ( type ) {
case V_92 :
F_49 ( L_8 , V_3 -> V_38 ? 'C' : 'V' ) ;
break;
case V_93 :
F_49 ( L_9 ,
V_3 -> V_24 ,
V_3 -> V_81 -> V_94 ,
V_3 -> V_95 -> V_94 ,
1 << V_3 -> V_49 ,
1 << V_3 -> V_25 ,
( unsigned long long ) V_3 -> V_85 ,
( unsigned long long ) V_3 -> V_96 ,
V_3 -> V_97
) ;
for ( V_91 = 0 ; V_91 < V_3 -> V_7 ; V_91 ++ )
F_49 ( L_10 , V_3 -> V_48 [ V_91 ] ) ;
F_49 ( L_11 ) ;
if ( ! V_3 -> V_37 )
F_49 ( L_12 ) ;
else
for ( V_91 = 0 ; V_91 < V_3 -> V_37 ; V_91 ++ )
F_49 ( L_10 , V_3 -> V_36 [ V_91 ] ) ;
break;
}
}
static int F_50 ( struct V_78 * V_15 , unsigned V_98 ,
unsigned long V_99 )
{
struct V_2 * V_3 = V_15 -> V_79 ;
int V_28 = 0 ;
if ( V_3 -> V_14 ||
V_15 -> V_100 != F_51 ( V_3 -> V_81 -> V_82 -> V_101 ) >> V_84 )
V_28 = F_52 ( NULL , V_98 ) ;
return V_28 ? : F_53 ( V_3 -> V_81 -> V_82 , V_3 -> V_81 -> V_102 ,
V_98 , V_99 ) ;
}
static int F_54 ( struct V_78 * V_15 , struct V_103 * V_104 ,
struct V_53 * V_105 , int V_106 )
{
struct V_2 * V_3 = V_15 -> V_79 ;
struct V_107 * V_108 = F_55 ( V_3 -> V_81 -> V_82 ) ;
if ( ! V_108 -> V_109 )
return V_106 ;
V_104 -> V_80 = V_3 -> V_81 -> V_82 ;
V_104 -> V_13 = F_6 ( V_3 , V_104 -> V_13 ) ;
return F_56 ( V_106 , V_108 -> V_109 ( V_108 , V_104 , V_105 ) ) ;
}
static int F_57 ( struct V_78 * V_15 ,
T_4 V_110 , void * V_27 )
{
struct V_2 * V_3 = V_15 -> V_79 ;
return V_110 ( V_15 , V_3 -> V_81 , V_3 -> V_14 , V_15 -> V_100 , V_27 ) ;
}
static void F_58 ( struct V_78 * V_15 , struct V_111 * V_112 )
{
struct V_2 * V_3 = V_15 -> V_79 ;
if ( V_112 -> V_113 < 1 << V_3 -> V_49 )
V_112 -> V_113 = 1 << V_3 -> V_49 ;
if ( V_112 -> V_114 < 1 << V_3 -> V_49 )
V_112 -> V_114 = 1 << V_3 -> V_49 ;
F_59 ( V_112 , V_112 -> V_113 ) ;
}
static void F_60 ( struct V_78 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_79 ;
if ( V_3 -> V_65 )
F_61 ( V_3 -> V_65 ) ;
if ( V_3 -> V_115 )
F_62 ( V_3 -> V_115 ) ;
if ( V_3 -> V_29 )
F_63 ( V_3 -> V_29 ) ;
F_39 ( V_3 -> V_36 ) ;
F_39 ( V_3 -> V_48 ) ;
if ( V_3 -> V_33 )
F_64 ( V_3 -> V_33 ) ;
F_39 ( V_3 -> V_97 ) ;
if ( V_3 -> V_95 )
F_65 ( V_15 , V_3 -> V_95 ) ;
if ( V_3 -> V_81 )
F_65 ( V_15 , V_3 -> V_81 ) ;
F_39 ( V_3 ) ;
}
static int F_66 ( struct V_78 * V_15 , unsigned V_116 , char * * V_117 )
{
struct V_2 * V_3 ;
unsigned V_118 ;
unsigned long long V_119 ;
int V_28 ;
int V_43 ;
T_2 V_120 ;
char V_121 ;
V_3 = F_67 ( sizeof( struct V_2 ) , V_122 ) ;
if ( ! V_3 ) {
V_15 -> error = L_13 ;
return - V_123 ;
}
V_15 -> V_79 = V_3 ;
V_3 -> V_15 = V_15 ;
if ( ( F_68 ( V_15 -> V_124 ) & ~ V_125 ) ) {
V_15 -> error = L_14 ;
V_28 = - V_126 ;
goto V_127;
}
if ( V_116 != 10 ) {
V_15 -> error = L_15 ;
V_28 = - V_126 ;
goto V_127;
}
if ( sscanf ( V_117 [ 0 ] , L_16 , & V_118 , & V_121 ) != 1 ||
V_118 > 1 ) {
V_15 -> error = L_17 ;
V_28 = - V_126 ;
goto V_127;
}
V_3 -> V_24 = V_118 ;
V_28 = F_69 ( V_15 , V_117 [ 1 ] , V_125 , & V_3 -> V_81 ) ;
if ( V_28 ) {
V_15 -> error = L_18 ;
goto V_127;
}
V_28 = F_69 ( V_15 , V_117 [ 2 ] , V_125 , & V_3 -> V_95 ) ;
if ( V_28 ) {
V_15 -> error = L_18 ;
goto V_127;
}
if ( sscanf ( V_117 [ 3 ] , L_16 , & V_118 , & V_121 ) != 1 ||
! V_118 || ( V_118 & ( V_118 - 1 ) ) ||
V_118 < V_128 ( V_3 -> V_81 -> V_82 ) ||
V_118 > V_129 ) {
V_15 -> error = L_19 ;
V_28 = - V_126 ;
goto V_127;
}
V_3 -> V_49 = F_70 ( V_118 ) ;
if ( sscanf ( V_117 [ 4 ] , L_16 , & V_118 , & V_121 ) != 1 ||
! V_118 || ( V_118 & ( V_118 - 1 ) ) ||
V_118 < V_128 ( V_3 -> V_95 -> V_82 ) ||
V_118 > V_130 ) {
V_15 -> error = L_20 ;
V_28 = - V_126 ;
goto V_127;
}
V_3 -> V_25 = F_70 ( V_118 ) ;
if ( sscanf ( V_117 [ 5 ] , L_21 , & V_119 , & V_121 ) != 1 ||
( T_2 ) ( V_119 << ( V_3 -> V_49 - V_84 ) )
>> ( V_3 -> V_49 - V_84 ) != V_119 ) {
V_15 -> error = L_22 ;
V_28 = - V_126 ;
goto V_127;
}
V_3 -> V_85 = V_119 ;
if ( V_15 -> V_100 > ( V_3 -> V_85 << ( V_3 -> V_49 - V_84 ) ) ) {
V_15 -> error = L_23 ;
V_28 = - V_126 ;
goto V_127;
}
if ( sscanf ( V_117 [ 6 ] , L_21 , & V_119 , & V_121 ) != 1 ||
( T_2 ) ( V_119 << ( V_3 -> V_25 - V_84 ) )
>> ( V_3 -> V_25 - V_84 ) != V_119 ) {
V_15 -> error = L_24 ;
V_28 = - V_126 ;
goto V_127;
}
V_3 -> V_96 = V_119 ;
V_3 -> V_97 = F_71 ( V_117 [ 7 ] , V_122 ) ;
if ( ! V_3 -> V_97 ) {
V_15 -> error = L_25 ;
V_28 = - V_123 ;
goto V_127;
}
V_3 -> V_33 = F_72 ( V_3 -> V_97 , 0 , 0 ) ;
if ( F_13 ( V_3 -> V_33 ) ) {
V_15 -> error = L_26 ;
V_28 = F_14 ( V_3 -> V_33 ) ;
V_3 -> V_33 = NULL ;
goto V_127;
}
V_3 -> V_7 = F_73 ( V_3 -> V_33 ) ;
if ( ( 1 << V_3 -> V_25 ) < V_3 -> V_7 * 2 ) {
V_15 -> error = L_27 ;
V_28 = - V_126 ;
goto V_127;
}
V_3 -> V_6 =
sizeof( struct V_1 ) + F_74 ( V_3 -> V_33 ) ;
V_3 -> V_48 = F_41 ( V_3 -> V_7 , V_122 ) ;
if ( ! V_3 -> V_48 ) {
V_15 -> error = L_28 ;
V_28 = - V_123 ;
goto V_127;
}
if ( strlen ( V_117 [ 8 ] ) != V_3 -> V_7 * 2 ||
F_75 ( V_3 -> V_48 , V_117 [ 8 ] , V_3 -> V_7 ) ) {
V_15 -> error = L_29 ;
V_28 = - V_126 ;
goto V_127;
}
if ( strcmp ( V_117 [ 9 ] , L_12 ) ) {
V_3 -> V_37 = strlen ( V_117 [ 9 ] ) / 2 ;
V_3 -> V_36 = F_41 ( V_3 -> V_37 , V_122 ) ;
if ( ! V_3 -> V_36 ) {
V_15 -> error = L_30 ;
V_28 = - V_123 ;
goto V_127;
}
if ( strlen ( V_117 [ 9 ] ) != V_3 -> V_37 * 2 ||
F_75 ( V_3 -> V_36 , V_117 [ 9 ] , V_3 -> V_37 ) ) {
V_15 -> error = L_31 ;
V_28 = - V_126 ;
goto V_127;
}
}
V_3 -> V_18 =
F_37 ( ( 1 << V_3 -> V_25 ) / V_3 -> V_7 ) ;
V_3 -> V_46 = 0 ;
if ( V_3 -> V_85 )
while ( V_3 -> V_18 * V_3 -> V_46 < 64 &&
( unsigned long long ) ( V_3 -> V_85 - 1 ) >>
( V_3 -> V_18 * V_3 -> V_46 ) )
V_3 -> V_46 ++ ;
if ( V_3 -> V_46 > V_131 ) {
V_15 -> error = L_32 ;
V_28 = - V_132 ;
goto V_127;
}
V_120 = V_3 -> V_96 ;
for ( V_43 = V_3 -> V_46 - 1 ; V_43 >= 0 ; V_43 -- ) {
T_2 V_133 ;
V_3 -> V_23 [ V_43 ] = V_120 ;
V_133 = ( V_3 -> V_85 + ( ( T_2 ) 1 << ( ( V_43 + 1 ) * V_3 -> V_18 ) ) - 1 )
>> ( ( V_43 + 1 ) * V_3 -> V_18 ) ;
if ( V_120 + V_133 < V_120 ) {
V_15 -> error = L_33 ;
V_28 = - V_132 ;
goto V_127;
}
V_120 += V_133 ;
}
V_3 -> V_73 = V_120 ;
V_3 -> V_29 = F_76 ( V_3 -> V_95 -> V_82 ,
1 << V_3 -> V_25 , 1 , sizeof( struct V_10 ) ,
F_4 , NULL ) ;
if ( F_13 ( V_3 -> V_29 ) ) {
V_15 -> error = L_34 ;
V_28 = F_14 ( V_3 -> V_29 ) ;
V_3 -> V_29 = NULL ;
goto V_127;
}
if ( F_77 ( V_3 -> V_29 ) < V_3 -> V_73 ) {
V_15 -> error = L_35 ;
V_28 = - V_132 ;
goto V_127;
}
V_15 -> V_41 = F_78 ( sizeof( struct V_4 ) + V_3 -> V_6 + V_3 -> V_7 * 2 , F_79 ( struct V_4 ) ) ;
V_3 -> V_115 = F_80 ( V_134 ,
V_135 * sizeof( struct V_53 ) ) ;
if ( ! V_3 -> V_115 ) {
V_15 -> error = L_36 ;
V_28 = - V_123 ;
goto V_127;
}
V_3 -> V_65 = F_81 ( L_37 , V_136 | V_137 | V_138 , F_82 () ) ;
if ( ! V_3 -> V_65 ) {
V_15 -> error = L_38 ;
V_28 = - V_123 ;
goto V_127;
}
return 0 ;
V_127:
F_60 ( V_15 ) ;
return V_28 ;
}
static int T_5 F_83 ( void )
{
int V_28 ;
V_28 = F_84 ( & V_139 ) ;
if ( V_28 < 0 )
F_16 ( L_39 , V_28 ) ;
return V_28 ;
}
static void T_6 F_85 ( void )
{
F_86 ( & V_139 ) ;
}
