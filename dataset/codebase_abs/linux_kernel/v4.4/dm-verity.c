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
if ( F_20 ( V_49 ) )
return F_21 ( V_49 ) ;
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
V_50 = F_22 ( V_52 ) ;
if ( V_50 < 0 ) {
F_13 ( L_8 , V_50 ) ;
goto V_54;
}
if ( F_23 ( V_3 -> V_24 >= 1 ) ) {
V_50 = F_24 ( V_52 , V_3 -> V_58 , V_3 -> V_59 ) ;
if ( V_50 < 0 ) {
F_13 ( L_9 , V_50 ) ;
goto V_54;
}
}
V_50 = F_24 ( V_52 , V_49 , 1 << V_3 -> V_25 ) ;
if ( V_50 < 0 ) {
F_13 ( L_9 , V_50 ) ;
goto V_54;
}
if ( ! V_3 -> V_24 ) {
V_50 = F_24 ( V_52 , V_3 -> V_58 , V_3 -> V_59 ) ;
if ( V_50 < 0 ) {
F_13 ( L_9 , V_50 ) ;
goto V_54;
}
}
V_53 = F_2 ( V_3 , V_5 ) ;
V_50 = F_25 ( V_52 , V_53 ) ;
if ( V_50 < 0 ) {
F_13 ( L_10 , V_50 ) ;
goto V_54;
}
if ( F_26 ( memcmp ( V_53 , F_3 ( V_3 , V_5 ) , V_3 -> V_7 ) ) ) {
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
if ( F_23 ( V_3 -> V_67 ) ) {
int V_50 = F_18 ( V_5 , V_5 -> V_16 + V_63 , 0 , true ) ;
if ( F_23 ( ! V_50 ) )
goto V_68;
if ( V_50 < 0 )
return V_50 ;
}
memcpy ( F_3 ( V_3 , V_5 ) , V_3 -> V_69 , V_3 -> V_7 ) ;
for ( V_64 = V_3 -> V_67 - 1 ; V_64 >= 0 ; V_64 -- ) {
int V_50 = F_18 ( V_5 , V_5 -> V_16 + V_63 , V_64 , false ) ;
if ( F_26 ( V_50 ) )
return V_50 ;
}
V_68:
V_52 = F_1 ( V_3 , V_5 ) ;
V_52 -> V_55 = V_3 -> V_55 ;
V_52 -> V_56 = V_57 ;
V_50 = F_22 ( V_52 ) ;
if ( V_50 < 0 ) {
F_13 ( L_8 , V_50 ) ;
return V_50 ;
}
if ( F_23 ( V_3 -> V_24 >= 1 ) ) {
V_50 = F_24 ( V_52 , V_3 -> V_58 , V_3 -> V_59 ) ;
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
if ( F_23 ( V_72 >= V_66 ) )
V_72 = V_66 ;
V_50 = F_24 ( V_52 , V_71 + V_74 . V_78 , V_72 ) ;
F_32 ( V_71 ) ;
if ( V_50 < 0 ) {
F_13 ( L_9 , V_50 ) ;
return V_50 ;
}
F_33 ( V_61 , & V_5 -> V_75 , V_72 ) ;
V_66 -= V_72 ;
} while ( V_66 );
if ( ! V_3 -> V_24 ) {
V_50 = F_24 ( V_52 , V_3 -> V_58 , V_3 -> V_59 ) ;
if ( V_50 < 0 ) {
F_13 ( L_9 , V_50 ) ;
return V_50 ;
}
}
V_53 = F_2 ( V_3 , V_5 ) ;
V_50 = F_25 ( V_52 , V_53 ) ;
if ( V_50 < 0 ) {
F_13 ( L_10 , V_50 ) ;
return V_50 ;
}
if ( F_26 ( memcmp ( V_53 , F_3 ( V_3 , V_5 ) , V_3 -> V_7 ) ) ) {
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
V_61 -> V_83 = error ;
F_35 ( V_61 ) ;
}
static void F_36 ( struct V_84 * V_85 )
{
struct V_4 * V_5 = F_37 ( V_85 , struct V_4 , V_86 ) ;
F_34 ( V_5 , F_28 ( V_5 ) ) ;
}
static void F_38 ( struct V_61 * V_61 )
{
struct V_4 * V_5 = V_61 -> V_81 ;
if ( V_61 -> V_83 ) {
F_34 ( V_5 , V_61 -> V_83 ) ;
return;
}
F_39 ( & V_5 -> V_86 , F_36 ) ;
F_40 ( V_5 -> V_3 -> V_87 , & V_5 -> V_86 ) ;
}
static void F_41 ( struct V_84 * V_86 )
{
struct V_88 * V_89 =
F_37 ( V_86 , struct V_88 , V_86 ) ;
struct V_2 * V_3 = V_89 -> V_3 ;
int V_64 ;
for ( V_64 = V_3 -> V_67 - 2 ; V_64 >= 0 ; V_64 -- ) {
T_2 V_90 ;
T_2 V_91 ;
F_9 ( V_3 , V_89 -> V_16 , V_64 , & V_90 , NULL ) ;
F_9 ( V_3 , V_89 -> V_16 + V_89 -> V_65 - 1 , V_64 , & V_91 , NULL ) ;
if ( ! V_64 ) {
unsigned V_92 = F_42 ( V_93 ) ;
V_92 >>= V_3 -> V_70 ;
if ( F_26 ( ! V_92 ) )
goto V_94;
if ( F_26 ( V_92 & ( V_92 - 1 ) ) )
V_92 = 1 << F_43 ( V_92 ) ;
V_90 &= ~ ( T_2 ) ( V_92 - 1 ) ;
V_91 |= V_92 - 1 ;
if ( F_26 ( V_91 >= V_3 -> V_95 ) )
V_91 = V_3 -> V_95 - 1 ;
}
V_94:
F_44 ( V_3 -> V_51 , V_90 ,
V_91 - V_90 + 1 ) ;
}
F_45 ( V_89 ) ;
}
static void F_46 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_88 * V_89 ;
V_89 = F_47 ( sizeof( struct V_88 ) ,
V_96 | V_97 | V_98 | V_99 ) ;
if ( ! V_89 )
return;
F_39 ( & V_89 -> V_86 , F_41 ) ;
V_89 -> V_3 = V_3 ;
V_89 -> V_16 = V_5 -> V_16 ;
V_89 -> V_65 = V_5 -> V_65 ;
F_40 ( V_3 -> V_87 , & V_89 -> V_86 ) ;
}
static int F_48 ( struct V_100 * V_15 , struct V_61 * V_61 )
{
struct V_2 * V_3 = V_15 -> V_101 ;
struct V_4 * V_5 ;
V_61 -> V_102 = V_3 -> V_40 -> V_103 ;
V_61 -> V_104 . V_13 = F_6 ( V_3 , V_61 -> V_104 . V_13 ) ;
if ( ( ( unsigned ) V_61 -> V_104 . V_13 | F_49 ( V_61 ) ) &
( ( 1 << ( V_3 -> V_70 - V_105 ) ) - 1 ) ) {
F_50 ( L_11 ) ;
return - V_60 ;
}
if ( F_51 ( V_61 ) >>
( V_3 -> V_70 - V_105 ) > V_3 -> V_106 ) {
F_50 ( L_12 ) ;
return - V_60 ;
}
if ( F_52 ( V_61 ) == V_107 )
return - V_60 ;
V_5 = F_53 ( V_61 , V_15 -> V_62 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_80 = V_61 -> V_79 ;
V_5 -> V_82 = V_61 -> V_81 ;
V_5 -> V_16 = V_61 -> V_104 . V_13 >> ( V_3 -> V_70 - V_105 ) ;
V_5 -> V_65 = V_61 -> V_104 . V_108 >> V_3 -> V_70 ;
V_61 -> V_79 = F_38 ;
V_61 -> V_81 = V_5 ;
V_5 -> V_75 = V_61 -> V_104 ;
F_46 ( V_3 , V_5 ) ;
F_54 ( V_61 ) ;
return V_109 ;
}
static void F_55 ( struct V_100 * V_15 , T_3 type ,
unsigned V_110 , char * V_53 , unsigned V_111 )
{
struct V_2 * V_3 = V_15 -> V_101 ;
unsigned V_112 = 0 ;
unsigned V_113 ;
switch ( type ) {
case V_114 :
F_56 ( L_13 , V_3 -> V_34 ? 'C' : 'V' ) ;
break;
case V_115 :
F_56 ( L_14 ,
V_3 -> V_24 ,
V_3 -> V_40 -> V_41 ,
V_3 -> V_116 -> V_41 ,
1 << V_3 -> V_70 ,
1 << V_3 -> V_25 ,
( unsigned long long ) V_3 -> V_106 ,
( unsigned long long ) V_3 -> V_117 ,
V_3 -> V_118
) ;
for ( V_113 = 0 ; V_113 < V_3 -> V_7 ; V_113 ++ )
F_56 ( L_15 , V_3 -> V_69 [ V_113 ] ) ;
F_56 ( L_16 ) ;
if ( ! V_3 -> V_59 )
F_56 ( L_17 ) ;
else
for ( V_113 = 0 ; V_113 < V_3 -> V_59 ; V_113 ++ )
F_56 ( L_15 , V_3 -> V_58 [ V_113 ] ) ;
if ( V_3 -> V_45 != V_119 ) {
F_56 ( L_18 ) ;
switch ( V_3 -> V_45 ) {
case V_46 :
F_56 ( V_120 ) ;
break;
case V_47 :
F_56 ( V_121 ) ;
break;
default:
F_12 () ;
}
}
break;
}
}
static int F_57 ( struct V_100 * V_15 ,
struct V_122 * * V_103 , T_4 * V_45 )
{
struct V_2 * V_3 = V_15 -> V_101 ;
* V_103 = V_3 -> V_40 -> V_103 ;
if ( V_3 -> V_14 ||
V_15 -> V_72 != F_58 ( V_3 -> V_40 -> V_103 -> V_123 ) >> V_105 )
return 1 ;
return 0 ;
}
static int F_59 ( struct V_100 * V_15 ,
T_5 V_124 , void * V_49 )
{
struct V_2 * V_3 = V_15 -> V_101 ;
return V_124 ( V_15 , V_3 -> V_40 , V_3 -> V_14 , V_15 -> V_72 , V_49 ) ;
}
static void F_60 ( struct V_100 * V_15 , struct V_125 * V_126 )
{
struct V_2 * V_3 = V_15 -> V_101 ;
if ( V_126 -> V_127 < 1 << V_3 -> V_70 )
V_126 -> V_127 = 1 << V_3 -> V_70 ;
if ( V_126 -> V_128 < 1 << V_3 -> V_70 )
V_126 -> V_128 = 1 << V_3 -> V_70 ;
F_61 ( V_126 , V_126 -> V_127 ) ;
}
static void F_62 ( struct V_100 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_101 ;
if ( V_3 -> V_87 )
F_63 ( V_3 -> V_87 ) ;
if ( V_3 -> V_51 )
F_64 ( V_3 -> V_51 ) ;
F_45 ( V_3 -> V_58 ) ;
F_45 ( V_3 -> V_69 ) ;
if ( V_3 -> V_55 )
F_65 ( V_3 -> V_55 ) ;
F_45 ( V_3 -> V_118 ) ;
if ( V_3 -> V_116 )
F_66 ( V_15 , V_3 -> V_116 ) ;
if ( V_3 -> V_40 )
F_66 ( V_15 , V_3 -> V_40 ) ;
F_45 ( V_3 ) ;
}
static int F_67 ( struct V_100 * V_15 , unsigned V_129 , char * * V_130 )
{
struct V_2 * V_3 ;
struct V_131 V_132 ;
const char * V_133 ;
unsigned int V_134 , V_135 ;
unsigned long long V_136 ;
int V_50 ;
int V_64 ;
T_2 V_137 ;
char V_138 ;
static struct V_139 V_140 [] = {
{ 0 , 1 , L_19 } ,
} ;
V_3 = F_68 ( sizeof( struct V_2 ) , V_141 ) ;
if ( ! V_3 ) {
V_15 -> error = L_20 ;
return - V_142 ;
}
V_15 -> V_101 = V_3 ;
V_3 -> V_15 = V_15 ;
if ( ( F_69 ( V_15 -> V_33 ) & ~ V_143 ) ) {
V_15 -> error = L_21 ;
V_50 = - V_144 ;
goto V_145;
}
if ( V_129 < 10 ) {
V_15 -> error = L_22 ;
V_50 = - V_144 ;
goto V_145;
}
if ( sscanf ( V_130 [ 0 ] , L_23 , & V_134 , & V_138 ) != 1 ||
V_134 > 1 ) {
V_15 -> error = L_24 ;
V_50 = - V_144 ;
goto V_145;
}
V_3 -> V_24 = V_134 ;
V_50 = F_70 ( V_15 , V_130 [ 1 ] , V_143 , & V_3 -> V_40 ) ;
if ( V_50 ) {
V_15 -> error = L_25 ;
goto V_145;
}
V_50 = F_70 ( V_15 , V_130 [ 2 ] , V_143 , & V_3 -> V_116 ) ;
if ( V_50 ) {
V_15 -> error = L_25 ;
goto V_145;
}
if ( sscanf ( V_130 [ 3 ] , L_23 , & V_134 , & V_138 ) != 1 ||
! V_134 || ( V_134 & ( V_134 - 1 ) ) ||
V_134 < V_146 ( V_3 -> V_40 -> V_103 ) ||
V_134 > V_147 ) {
V_15 -> error = L_26 ;
V_50 = - V_144 ;
goto V_145;
}
V_3 -> V_70 = F_71 ( V_134 ) ;
if ( sscanf ( V_130 [ 4 ] , L_23 , & V_134 , & V_138 ) != 1 ||
! V_134 || ( V_134 & ( V_134 - 1 ) ) ||
V_134 < V_146 ( V_3 -> V_116 -> V_103 ) ||
V_134 > V_148 ) {
V_15 -> error = L_27 ;
V_50 = - V_144 ;
goto V_145;
}
V_3 -> V_25 = F_71 ( V_134 ) ;
if ( sscanf ( V_130 [ 5 ] , L_28 , & V_136 , & V_138 ) != 1 ||
( T_2 ) ( V_136 << ( V_3 -> V_70 - V_105 ) )
>> ( V_3 -> V_70 - V_105 ) != V_136 ) {
V_15 -> error = L_29 ;
V_50 = - V_144 ;
goto V_145;
}
V_3 -> V_106 = V_136 ;
if ( V_15 -> V_72 > ( V_3 -> V_106 << ( V_3 -> V_70 - V_105 ) ) ) {
V_15 -> error = L_30 ;
V_50 = - V_144 ;
goto V_145;
}
if ( sscanf ( V_130 [ 6 ] , L_28 , & V_136 , & V_138 ) != 1 ||
( T_2 ) ( V_136 << ( V_3 -> V_25 - V_105 ) )
>> ( V_3 -> V_25 - V_105 ) != V_136 ) {
V_15 -> error = L_31 ;
V_50 = - V_144 ;
goto V_145;
}
V_3 -> V_117 = V_136 ;
V_3 -> V_118 = F_72 ( V_130 [ 7 ] , V_141 ) ;
if ( ! V_3 -> V_118 ) {
V_15 -> error = L_32 ;
V_50 = - V_142 ;
goto V_145;
}
V_3 -> V_55 = F_73 ( V_3 -> V_118 , 0 , 0 ) ;
if ( F_20 ( V_3 -> V_55 ) ) {
V_15 -> error = L_33 ;
V_50 = F_21 ( V_3 -> V_55 ) ;
V_3 -> V_55 = NULL ;
goto V_145;
}
V_3 -> V_7 = F_74 ( V_3 -> V_55 ) ;
if ( ( 1 << V_3 -> V_25 ) < V_3 -> V_7 * 2 ) {
V_15 -> error = L_34 ;
V_50 = - V_144 ;
goto V_145;
}
V_3 -> V_6 =
sizeof( struct V_1 ) + F_75 ( V_3 -> V_55 ) ;
V_3 -> V_69 = F_47 ( V_3 -> V_7 , V_141 ) ;
if ( ! V_3 -> V_69 ) {
V_15 -> error = L_35 ;
V_50 = - V_142 ;
goto V_145;
}
if ( strlen ( V_130 [ 8 ] ) != V_3 -> V_7 * 2 ||
F_76 ( V_3 -> V_69 , V_130 [ 8 ] , V_3 -> V_7 ) ) {
V_15 -> error = L_36 ;
V_50 = - V_144 ;
goto V_145;
}
if ( strcmp ( V_130 [ 9 ] , L_17 ) ) {
V_3 -> V_59 = strlen ( V_130 [ 9 ] ) / 2 ;
V_3 -> V_58 = F_47 ( V_3 -> V_59 , V_141 ) ;
if ( ! V_3 -> V_58 ) {
V_15 -> error = L_37 ;
V_50 = - V_142 ;
goto V_145;
}
if ( strlen ( V_130 [ 9 ] ) != V_3 -> V_59 * 2 ||
F_76 ( V_3 -> V_58 , V_130 [ 9 ] , V_3 -> V_59 ) ) {
V_15 -> error = L_38 ;
V_50 = - V_144 ;
goto V_145;
}
}
V_130 += 10 ;
V_129 -= 10 ;
if ( V_129 ) {
V_132 . V_129 = V_129 ;
V_132 . V_130 = V_130 ;
V_50 = F_77 ( V_140 , & V_132 , & V_135 , & V_15 -> error ) ;
if ( V_50 )
goto V_145;
while ( V_135 ) {
V_135 -- ;
V_133 = F_78 ( & V_132 ) ;
if ( ! V_133 ) {
V_15 -> error = L_39 ;
V_50 = - V_144 ;
goto V_145;
}
if ( ! strcasecmp ( V_133 , V_120 ) )
V_3 -> V_45 = V_46 ;
else if ( ! strcasecmp ( V_133 , V_121 ) )
V_3 -> V_45 = V_47 ;
else {
V_15 -> error = L_40 ;
V_50 = - V_144 ;
goto V_145;
}
}
}
V_3 -> V_18 =
F_43 ( ( 1 << V_3 -> V_25 ) / V_3 -> V_7 ) ;
V_3 -> V_67 = 0 ;
if ( V_3 -> V_106 )
while ( V_3 -> V_18 * V_3 -> V_67 < 64 &&
( unsigned long long ) ( V_3 -> V_106 - 1 ) >>
( V_3 -> V_18 * V_3 -> V_67 ) )
V_3 -> V_67 ++ ;
if ( V_3 -> V_67 > V_149 ) {
V_15 -> error = L_41 ;
V_50 = - V_150 ;
goto V_145;
}
V_137 = V_3 -> V_117 ;
for ( V_64 = V_3 -> V_67 - 1 ; V_64 >= 0 ; V_64 -- ) {
T_2 V_151 ;
V_3 -> V_23 [ V_64 ] = V_137 ;
V_151 = ( V_3 -> V_106 + ( ( T_2 ) 1 << ( ( V_64 + 1 ) * V_3 -> V_18 ) ) - 1 )
>> ( ( V_64 + 1 ) * V_3 -> V_18 ) ;
if ( V_137 + V_151 < V_137 ) {
V_15 -> error = L_42 ;
V_50 = - V_150 ;
goto V_145;
}
V_137 += V_151 ;
}
V_3 -> V_95 = V_137 ;
V_3 -> V_51 = F_79 ( V_3 -> V_116 -> V_103 ,
1 << V_3 -> V_25 , 1 , sizeof( struct V_10 ) ,
F_4 , NULL ) ;
if ( F_20 ( V_3 -> V_51 ) ) {
V_15 -> error = L_43 ;
V_50 = F_21 ( V_3 -> V_51 ) ;
V_3 -> V_51 = NULL ;
goto V_145;
}
if ( F_80 ( V_3 -> V_51 ) < V_3 -> V_95 ) {
V_15 -> error = L_44 ;
V_50 = - V_150 ;
goto V_145;
}
V_15 -> V_62 = F_81 ( sizeof( struct V_4 ) + V_3 -> V_6 + V_3 -> V_7 * 2 , F_82 ( struct V_4 ) ) ;
V_3 -> V_87 = F_83 ( L_45 , V_152 | V_153 | V_154 , F_84 () ) ;
if ( ! V_3 -> V_87 ) {
V_15 -> error = L_46 ;
V_50 = - V_142 ;
goto V_145;
}
return 0 ;
V_145:
F_62 ( V_15 ) ;
return V_50 ;
}
static int T_6 F_85 ( void )
{
int V_50 ;
V_50 = F_86 ( & V_155 ) ;
if ( V_50 < 0 )
F_13 ( L_47 , V_50 ) ;
return V_50 ;
}
static void T_7 F_87 ( void )
{
F_88 ( & V_155 ) ;
}
