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
static int F_10 ( struct V_2 * V_3 , enum V_26 type ,
unsigned long long V_16 )
{
char V_27 [ V_28 ] ;
char * V_29 [] = { V_27 , NULL } ;
const char * V_30 = L_1 ;
struct V_31 * V_32 = F_11 ( V_3 -> V_15 -> V_33 ) ;
V_3 -> V_34 = 1 ;
if ( V_3 -> V_35 >= V_36 )
goto V_37;
V_3 -> V_35 ++ ;
switch ( type ) {
case V_38 :
V_30 = L_2 ;
break;
case V_39 :
V_30 = L_3 ;
break;
default:
F_12 () ;
}
F_13 ( L_4 , V_3 -> V_40 -> V_41 , V_30 ,
V_16 ) ;
if ( V_3 -> V_35 == V_36 )
F_13 ( L_5 , V_3 -> V_40 -> V_41 ) ;
snprintf ( V_27 , V_28 , L_6 ,
V_42 , type , V_16 ) ;
F_14 ( & F_15 ( F_16 ( V_32 ) ) -> V_43 , V_44 , V_29 ) ;
V_37:
if ( V_3 -> V_45 == V_46 )
return 0 ;
if ( V_3 -> V_45 == V_47 )
F_17 ( L_7 ) ;
return 1 ;
}
static int F_18 ( struct V_4 * V_5 , T_2 V_16 ,
int V_17 , bool V_48 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
T_1 * V_49 ;
int V_50 ;
T_2 V_19 ;
unsigned V_20 ;
F_9 ( V_3 , V_16 , V_17 , & V_19 , & V_20 ) ;
V_49 = F_19 ( V_3 -> V_51 , V_19 , & V_9 ) ;
if ( F_20 ( F_21 ( V_49 ) ) )
return F_22 ( V_49 ) ;
V_11 = F_5 ( V_9 ) ;
if ( ! V_11 -> V_12 ) {
struct V_1 * V_52 ;
T_1 * V_53 ;
if ( V_48 ) {
V_50 = 1 ;
goto V_54;
}
V_52 = F_1 ( V_3 , V_5 ) ;
V_52 -> V_55 = V_3 -> V_55 ;
V_52 -> V_56 = V_57 ;
V_50 = F_23 ( V_52 ) ;
if ( V_50 < 0 ) {
F_13 ( L_8 , V_50 ) ;
goto V_54;
}
if ( F_24 ( V_3 -> V_24 >= 1 ) ) {
V_50 = F_25 ( V_52 , V_3 -> V_58 , V_3 -> V_59 ) ;
if ( V_50 < 0 ) {
F_13 ( L_9 , V_50 ) ;
goto V_54;
}
}
V_50 = F_25 ( V_52 , V_49 , 1 << V_3 -> V_25 ) ;
if ( V_50 < 0 ) {
F_13 ( L_9 , V_50 ) ;
goto V_54;
}
if ( ! V_3 -> V_24 ) {
V_50 = F_25 ( V_52 , V_3 -> V_58 , V_3 -> V_59 ) ;
if ( V_50 < 0 ) {
F_13 ( L_9 , V_50 ) ;
goto V_54;
}
}
V_53 = F_2 ( V_3 , V_5 ) ;
V_50 = F_26 ( V_52 , V_53 ) ;
if ( V_50 < 0 ) {
F_13 ( L_10 , V_50 ) ;
goto V_54;
}
if ( F_20 ( memcmp ( V_53 , F_3 ( V_3 , V_5 ) , V_3 -> V_7 ) ) ) {
if ( F_10 ( V_3 , V_39 ,
V_19 ) ) {
V_50 = - V_60 ;
goto V_54;
}
} else
V_11 -> V_12 = 1 ;
}
V_49 += V_20 ;
memcpy ( F_3 ( V_3 , V_5 ) , V_49 , V_3 -> V_7 ) ;
F_27 ( V_9 ) ;
return 0 ;
V_54:
F_27 ( V_9 ) ;
return V_50 ;
}
static int F_28 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_61 * V_61 = F_29 ( V_5 ,
V_3 -> V_15 -> V_62 ) ;
unsigned V_63 ;
int V_64 ;
for ( V_63 = 0 ; V_63 < V_5 -> V_65 ; V_63 ++ ) {
struct V_1 * V_52 ;
T_1 * V_53 ;
int V_50 ;
unsigned V_66 ;
if ( F_24 ( V_3 -> V_67 ) ) {
int V_50 = F_18 ( V_5 , V_5 -> V_16 + V_63 , 0 , true ) ;
if ( F_24 ( ! V_50 ) )
goto V_68;
if ( V_50 < 0 )
return V_50 ;
}
memcpy ( F_3 ( V_3 , V_5 ) , V_3 -> V_69 , V_3 -> V_7 ) ;
for ( V_64 = V_3 -> V_67 - 1 ; V_64 >= 0 ; V_64 -- ) {
int V_50 = F_18 ( V_5 , V_5 -> V_16 + V_63 , V_64 , false ) ;
if ( F_20 ( V_50 ) )
return V_50 ;
}
V_68:
V_52 = F_1 ( V_3 , V_5 ) ;
V_52 -> V_55 = V_3 -> V_55 ;
V_52 -> V_56 = V_57 ;
V_50 = F_23 ( V_52 ) ;
if ( V_50 < 0 ) {
F_13 ( L_8 , V_50 ) ;
return V_50 ;
}
if ( F_24 ( V_3 -> V_24 >= 1 ) ) {
V_50 = F_25 ( V_52 , V_3 -> V_58 , V_3 -> V_59 ) ;
if ( V_50 < 0 ) {
F_13 ( L_9 , V_50 ) ;
return V_50 ;
}
}
V_66 = 1 << V_3 -> V_70 ;
do {
T_1 * V_71 ;
unsigned V_72 ;
struct V_73 V_74 = F_30 ( V_61 , V_5 -> V_75 ) ;
V_71 = F_31 ( V_74 . V_76 ) ;
V_72 = V_74 . V_77 ;
if ( F_24 ( V_72 >= V_66 ) )
V_72 = V_66 ;
V_50 = F_25 ( V_52 , V_71 + V_74 . V_78 , V_72 ) ;
F_32 ( V_71 ) ;
if ( V_50 < 0 ) {
F_13 ( L_9 , V_50 ) ;
return V_50 ;
}
F_33 ( V_61 , & V_5 -> V_75 , V_72 ) ;
V_66 -= V_72 ;
} while ( V_66 );
if ( ! V_3 -> V_24 ) {
V_50 = F_25 ( V_52 , V_3 -> V_58 , V_3 -> V_59 ) ;
if ( V_50 < 0 ) {
F_13 ( L_9 , V_50 ) ;
return V_50 ;
}
}
V_53 = F_2 ( V_3 , V_5 ) ;
V_50 = F_26 ( V_52 , V_53 ) ;
if ( V_50 < 0 ) {
F_13 ( L_10 , V_50 ) ;
return V_50 ;
}
if ( F_20 ( memcmp ( V_53 , F_3 ( V_3 , V_5 ) , V_3 -> V_7 ) ) ) {
if ( F_10 ( V_3 , V_38 ,
V_5 -> V_16 + V_63 ) )
return - V_60 ;
}
}
return 0 ;
}
static void F_34 ( struct V_4 * V_5 , int error )
{
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_61 * V_61 = F_29 ( V_5 , V_3 -> V_15 -> V_62 ) ;
V_61 -> V_79 = V_5 -> V_80 ;
V_61 -> V_81 = V_5 -> V_82 ;
F_35 ( V_61 , error ) ;
}
static void F_36 ( struct V_83 * V_84 )
{
struct V_4 * V_5 = F_37 ( V_84 , struct V_4 , V_85 ) ;
F_34 ( V_5 , F_28 ( V_5 ) ) ;
}
static void F_38 ( struct V_61 * V_61 , int error )
{
struct V_4 * V_5 = V_61 -> V_81 ;
if ( error ) {
F_34 ( V_5 , error ) ;
return;
}
F_39 ( & V_5 -> V_85 , F_36 ) ;
F_40 ( V_5 -> V_3 -> V_86 , & V_5 -> V_85 ) ;
}
static void F_41 ( struct V_83 * V_85 )
{
struct V_87 * V_88 =
F_37 ( V_85 , struct V_87 , V_85 ) ;
struct V_2 * V_3 = V_88 -> V_3 ;
int V_64 ;
for ( V_64 = V_3 -> V_67 - 2 ; V_64 >= 0 ; V_64 -- ) {
T_2 V_89 ;
T_2 V_90 ;
F_9 ( V_3 , V_88 -> V_16 , V_64 , & V_89 , NULL ) ;
F_9 ( V_3 , V_88 -> V_16 + V_88 -> V_65 - 1 , V_64 , & V_90 , NULL ) ;
if ( ! V_64 ) {
unsigned V_91 = F_42 ( V_92 ) ;
V_91 >>= V_3 -> V_70 ;
if ( F_20 ( ! V_91 ) )
goto V_93;
if ( F_20 ( V_91 & ( V_91 - 1 ) ) )
V_91 = 1 << F_43 ( V_91 ) ;
V_89 &= ~ ( T_2 ) ( V_91 - 1 ) ;
V_90 |= V_91 - 1 ;
if ( F_20 ( V_90 >= V_3 -> V_94 ) )
V_90 = V_3 -> V_94 - 1 ;
}
V_93:
F_44 ( V_3 -> V_51 , V_89 ,
V_90 - V_89 + 1 ) ;
}
F_45 ( V_88 ) ;
}
static void F_46 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_87 * V_88 ;
V_88 = F_47 ( sizeof( struct V_87 ) ,
V_95 | V_96 | V_97 | V_98 ) ;
if ( ! V_88 )
return;
F_39 ( & V_88 -> V_85 , F_41 ) ;
V_88 -> V_3 = V_3 ;
V_88 -> V_16 = V_5 -> V_16 ;
V_88 -> V_65 = V_5 -> V_65 ;
F_40 ( V_3 -> V_86 , & V_88 -> V_85 ) ;
}
static int F_48 ( struct V_99 * V_15 , struct V_61 * V_61 )
{
struct V_2 * V_3 = V_15 -> V_100 ;
struct V_4 * V_5 ;
V_61 -> V_101 = V_3 -> V_40 -> V_102 ;
V_61 -> V_103 . V_13 = F_6 ( V_3 , V_61 -> V_103 . V_13 ) ;
if ( ( ( unsigned ) V_61 -> V_103 . V_13 | F_49 ( V_61 ) ) &
( ( 1 << ( V_3 -> V_70 - V_104 ) ) - 1 ) ) {
F_50 ( L_11 ) ;
return - V_60 ;
}
if ( F_51 ( V_61 ) >>
( V_3 -> V_70 - V_104 ) > V_3 -> V_105 ) {
F_50 ( L_12 ) ;
return - V_60 ;
}
if ( F_52 ( V_61 ) == V_106 )
return - V_60 ;
V_5 = F_53 ( V_61 , V_15 -> V_62 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_80 = V_61 -> V_79 ;
V_5 -> V_82 = V_61 -> V_81 ;
V_5 -> V_16 = V_61 -> V_103 . V_13 >> ( V_3 -> V_70 - V_104 ) ;
V_5 -> V_65 = V_61 -> V_103 . V_107 >> V_3 -> V_70 ;
V_61 -> V_79 = F_38 ;
V_61 -> V_81 = V_5 ;
V_5 -> V_75 = V_61 -> V_103 ;
F_46 ( V_3 , V_5 ) ;
F_54 ( V_61 ) ;
return V_108 ;
}
static void F_55 ( struct V_99 * V_15 , T_3 type ,
unsigned V_109 , char * V_53 , unsigned V_110 )
{
struct V_2 * V_3 = V_15 -> V_100 ;
unsigned V_111 = 0 ;
unsigned V_112 ;
switch ( type ) {
case V_113 :
F_56 ( L_13 , V_3 -> V_34 ? 'C' : 'V' ) ;
break;
case V_114 :
F_56 ( L_14 ,
V_3 -> V_24 ,
V_3 -> V_40 -> V_41 ,
V_3 -> V_115 -> V_41 ,
1 << V_3 -> V_70 ,
1 << V_3 -> V_25 ,
( unsigned long long ) V_3 -> V_105 ,
( unsigned long long ) V_3 -> V_116 ,
V_3 -> V_117
) ;
for ( V_112 = 0 ; V_112 < V_3 -> V_7 ; V_112 ++ )
F_56 ( L_15 , V_3 -> V_69 [ V_112 ] ) ;
F_56 ( L_16 ) ;
if ( ! V_3 -> V_59 )
F_56 ( L_17 ) ;
else
for ( V_112 = 0 ; V_112 < V_3 -> V_59 ; V_112 ++ )
F_56 ( L_15 , V_3 -> V_58 [ V_112 ] ) ;
if ( V_3 -> V_45 != V_118 ) {
F_56 ( L_18 ) ;
switch ( V_3 -> V_45 ) {
case V_46 :
F_56 ( V_119 ) ;
break;
case V_47 :
F_56 ( V_120 ) ;
break;
default:
F_12 () ;
}
}
break;
}
}
static int F_57 ( struct V_99 * V_15 , unsigned V_121 ,
unsigned long V_122 )
{
struct V_2 * V_3 = V_15 -> V_100 ;
int V_50 = 0 ;
if ( V_3 -> V_14 ||
V_15 -> V_72 != F_58 ( V_3 -> V_40 -> V_102 -> V_123 ) >> V_104 )
V_50 = F_59 ( NULL , V_121 ) ;
return V_50 ? : F_60 ( V_3 -> V_40 -> V_102 , V_3 -> V_40 -> V_45 ,
V_121 , V_122 ) ;
}
static int F_61 ( struct V_99 * V_15 , struct V_124 * V_125 ,
struct V_73 * V_126 , int V_127 )
{
struct V_2 * V_3 = V_15 -> V_100 ;
struct V_128 * V_129 = F_62 ( V_3 -> V_40 -> V_102 ) ;
if ( ! V_129 -> V_130 )
return V_127 ;
V_125 -> V_101 = V_3 -> V_40 -> V_102 ;
V_125 -> V_13 = F_6 ( V_3 , V_125 -> V_13 ) ;
return F_63 ( V_127 , V_129 -> V_130 ( V_129 , V_125 , V_126 ) ) ;
}
static int F_64 ( struct V_99 * V_15 ,
T_4 V_131 , void * V_49 )
{
struct V_2 * V_3 = V_15 -> V_100 ;
return V_131 ( V_15 , V_3 -> V_40 , V_3 -> V_14 , V_15 -> V_72 , V_49 ) ;
}
static void F_65 ( struct V_99 * V_15 , struct V_132 * V_133 )
{
struct V_2 * V_3 = V_15 -> V_100 ;
if ( V_133 -> V_134 < 1 << V_3 -> V_70 )
V_133 -> V_134 = 1 << V_3 -> V_70 ;
if ( V_133 -> V_135 < 1 << V_3 -> V_70 )
V_133 -> V_135 = 1 << V_3 -> V_70 ;
F_66 ( V_133 , V_133 -> V_134 ) ;
}
static void F_67 ( struct V_99 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_100 ;
if ( V_3 -> V_86 )
F_68 ( V_3 -> V_86 ) ;
if ( V_3 -> V_136 )
F_69 ( V_3 -> V_136 ) ;
if ( V_3 -> V_51 )
F_70 ( V_3 -> V_51 ) ;
F_45 ( V_3 -> V_58 ) ;
F_45 ( V_3 -> V_69 ) ;
if ( V_3 -> V_55 )
F_71 ( V_3 -> V_55 ) ;
F_45 ( V_3 -> V_117 ) ;
if ( V_3 -> V_115 )
F_72 ( V_15 , V_3 -> V_115 ) ;
if ( V_3 -> V_40 )
F_72 ( V_15 , V_3 -> V_40 ) ;
F_45 ( V_3 ) ;
}
static int F_73 ( struct V_99 * V_15 , unsigned V_137 , char * * V_138 )
{
struct V_2 * V_3 ;
struct V_139 V_140 ;
const char * V_141 ;
unsigned int V_142 , V_143 ;
unsigned long long V_144 ;
int V_50 ;
int V_64 ;
T_2 V_145 ;
char V_146 ;
static struct V_147 V_148 [] = {
{ 0 , 1 , L_19 } ,
} ;
V_3 = F_74 ( sizeof( struct V_2 ) , V_149 ) ;
if ( ! V_3 ) {
V_15 -> error = L_20 ;
return - V_150 ;
}
V_15 -> V_100 = V_3 ;
V_3 -> V_15 = V_15 ;
if ( ( F_75 ( V_15 -> V_33 ) & ~ V_151 ) ) {
V_15 -> error = L_21 ;
V_50 = - V_152 ;
goto V_153;
}
if ( V_137 < 10 ) {
V_15 -> error = L_22 ;
V_50 = - V_152 ;
goto V_153;
}
if ( sscanf ( V_138 [ 0 ] , L_23 , & V_142 , & V_146 ) != 1 ||
V_142 > 1 ) {
V_15 -> error = L_24 ;
V_50 = - V_152 ;
goto V_153;
}
V_3 -> V_24 = V_142 ;
V_50 = F_76 ( V_15 , V_138 [ 1 ] , V_151 , & V_3 -> V_40 ) ;
if ( V_50 ) {
V_15 -> error = L_25 ;
goto V_153;
}
V_50 = F_76 ( V_15 , V_138 [ 2 ] , V_151 , & V_3 -> V_115 ) ;
if ( V_50 ) {
V_15 -> error = L_25 ;
goto V_153;
}
if ( sscanf ( V_138 [ 3 ] , L_23 , & V_142 , & V_146 ) != 1 ||
! V_142 || ( V_142 & ( V_142 - 1 ) ) ||
V_142 < V_154 ( V_3 -> V_40 -> V_102 ) ||
V_142 > V_155 ) {
V_15 -> error = L_26 ;
V_50 = - V_152 ;
goto V_153;
}
V_3 -> V_70 = F_77 ( V_142 ) ;
if ( sscanf ( V_138 [ 4 ] , L_23 , & V_142 , & V_146 ) != 1 ||
! V_142 || ( V_142 & ( V_142 - 1 ) ) ||
V_142 < V_154 ( V_3 -> V_115 -> V_102 ) ||
V_142 > V_156 ) {
V_15 -> error = L_27 ;
V_50 = - V_152 ;
goto V_153;
}
V_3 -> V_25 = F_77 ( V_142 ) ;
if ( sscanf ( V_138 [ 5 ] , L_28 , & V_144 , & V_146 ) != 1 ||
( T_2 ) ( V_144 << ( V_3 -> V_70 - V_104 ) )
>> ( V_3 -> V_70 - V_104 ) != V_144 ) {
V_15 -> error = L_29 ;
V_50 = - V_152 ;
goto V_153;
}
V_3 -> V_105 = V_144 ;
if ( V_15 -> V_72 > ( V_3 -> V_105 << ( V_3 -> V_70 - V_104 ) ) ) {
V_15 -> error = L_30 ;
V_50 = - V_152 ;
goto V_153;
}
if ( sscanf ( V_138 [ 6 ] , L_28 , & V_144 , & V_146 ) != 1 ||
( T_2 ) ( V_144 << ( V_3 -> V_25 - V_104 ) )
>> ( V_3 -> V_25 - V_104 ) != V_144 ) {
V_15 -> error = L_31 ;
V_50 = - V_152 ;
goto V_153;
}
V_3 -> V_116 = V_144 ;
V_3 -> V_117 = F_78 ( V_138 [ 7 ] , V_149 ) ;
if ( ! V_3 -> V_117 ) {
V_15 -> error = L_32 ;
V_50 = - V_150 ;
goto V_153;
}
V_3 -> V_55 = F_79 ( V_3 -> V_117 , 0 , 0 ) ;
if ( F_21 ( V_3 -> V_55 ) ) {
V_15 -> error = L_33 ;
V_50 = F_22 ( V_3 -> V_55 ) ;
V_3 -> V_55 = NULL ;
goto V_153;
}
V_3 -> V_7 = F_80 ( V_3 -> V_55 ) ;
if ( ( 1 << V_3 -> V_25 ) < V_3 -> V_7 * 2 ) {
V_15 -> error = L_34 ;
V_50 = - V_152 ;
goto V_153;
}
V_3 -> V_6 =
sizeof( struct V_1 ) + F_81 ( V_3 -> V_55 ) ;
V_3 -> V_69 = F_47 ( V_3 -> V_7 , V_149 ) ;
if ( ! V_3 -> V_69 ) {
V_15 -> error = L_35 ;
V_50 = - V_150 ;
goto V_153;
}
if ( strlen ( V_138 [ 8 ] ) != V_3 -> V_7 * 2 ||
F_82 ( V_3 -> V_69 , V_138 [ 8 ] , V_3 -> V_7 ) ) {
V_15 -> error = L_36 ;
V_50 = - V_152 ;
goto V_153;
}
if ( strcmp ( V_138 [ 9 ] , L_17 ) ) {
V_3 -> V_59 = strlen ( V_138 [ 9 ] ) / 2 ;
V_3 -> V_58 = F_47 ( V_3 -> V_59 , V_149 ) ;
if ( ! V_3 -> V_58 ) {
V_15 -> error = L_37 ;
V_50 = - V_150 ;
goto V_153;
}
if ( strlen ( V_138 [ 9 ] ) != V_3 -> V_59 * 2 ||
F_82 ( V_3 -> V_58 , V_138 [ 9 ] , V_3 -> V_59 ) ) {
V_15 -> error = L_38 ;
V_50 = - V_152 ;
goto V_153;
}
}
V_138 += 10 ;
V_137 -= 10 ;
if ( V_137 ) {
V_140 . V_137 = V_137 ;
V_140 . V_138 = V_138 ;
V_50 = F_83 ( V_148 , & V_140 , & V_143 , & V_15 -> error ) ;
if ( V_50 )
goto V_153;
while ( V_143 ) {
V_143 -- ;
V_141 = F_84 ( & V_140 ) ;
if ( ! V_141 ) {
V_15 -> error = L_39 ;
V_50 = - V_152 ;
goto V_153;
}
if ( ! strcasecmp ( V_141 , V_119 ) )
V_3 -> V_45 = V_46 ;
else if ( ! strcasecmp ( V_141 , V_120 ) )
V_3 -> V_45 = V_47 ;
else {
V_15 -> error = L_40 ;
V_50 = - V_152 ;
goto V_153;
}
}
}
V_3 -> V_18 =
F_43 ( ( 1 << V_3 -> V_25 ) / V_3 -> V_7 ) ;
V_3 -> V_67 = 0 ;
if ( V_3 -> V_105 )
while ( V_3 -> V_18 * V_3 -> V_67 < 64 &&
( unsigned long long ) ( V_3 -> V_105 - 1 ) >>
( V_3 -> V_18 * V_3 -> V_67 ) )
V_3 -> V_67 ++ ;
if ( V_3 -> V_67 > V_157 ) {
V_15 -> error = L_41 ;
V_50 = - V_158 ;
goto V_153;
}
V_145 = V_3 -> V_116 ;
for ( V_64 = V_3 -> V_67 - 1 ; V_64 >= 0 ; V_64 -- ) {
T_2 V_159 ;
V_3 -> V_23 [ V_64 ] = V_145 ;
V_159 = ( V_3 -> V_105 + ( ( T_2 ) 1 << ( ( V_64 + 1 ) * V_3 -> V_18 ) ) - 1 )
>> ( ( V_64 + 1 ) * V_3 -> V_18 ) ;
if ( V_145 + V_159 < V_145 ) {
V_15 -> error = L_42 ;
V_50 = - V_158 ;
goto V_153;
}
V_145 += V_159 ;
}
V_3 -> V_94 = V_145 ;
V_3 -> V_51 = F_85 ( V_3 -> V_115 -> V_102 ,
1 << V_3 -> V_25 , 1 , sizeof( struct V_10 ) ,
F_4 , NULL ) ;
if ( F_21 ( V_3 -> V_51 ) ) {
V_15 -> error = L_43 ;
V_50 = F_22 ( V_3 -> V_51 ) ;
V_3 -> V_51 = NULL ;
goto V_153;
}
if ( F_86 ( V_3 -> V_51 ) < V_3 -> V_94 ) {
V_15 -> error = L_44 ;
V_50 = - V_158 ;
goto V_153;
}
V_15 -> V_62 = F_87 ( sizeof( struct V_4 ) + V_3 -> V_6 + V_3 -> V_7 * 2 , F_88 ( struct V_4 ) ) ;
V_3 -> V_136 = F_89 ( V_160 ,
V_161 * sizeof( struct V_73 ) ) ;
if ( ! V_3 -> V_136 ) {
V_15 -> error = L_45 ;
V_50 = - V_150 ;
goto V_153;
}
V_3 -> V_86 = F_90 ( L_46 , V_162 | V_163 | V_164 , F_91 () ) ;
if ( ! V_3 -> V_86 ) {
V_15 -> error = L_47 ;
V_50 = - V_150 ;
goto V_153;
}
return 0 ;
V_153:
F_67 ( V_15 ) ;
return V_50 ;
}
static int T_5 F_92 ( void )
{
int V_50 ;
V_50 = F_93 ( & V_165 ) ;
if ( V_50 < 0 )
F_13 ( L_48 , V_50 ) ;
return V_50 ;
}
static void T_6 F_94 ( void )
{
F_95 ( & V_165 ) ;
}
