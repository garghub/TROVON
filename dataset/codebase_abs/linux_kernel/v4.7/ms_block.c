static T_1 F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 , int V_4 , T_1 V_5 , T_1 V_6 )
{
T_1 V_7 = 0 ;
while ( V_5 > 0 ) {
if ( V_5 >= V_2 -> V_8 ) {
if ( F_2 ( V_2 ) )
return 0 ;
V_5 -= V_2 -> V_8 ;
V_2 = F_3 ( V_2 ) ;
continue;
}
V_7 = F_4 ( V_6 , V_2 -> V_8 - V_5 ) ;
F_5 ( V_3 , F_6 ( V_2 ) ,
V_7 , V_2 -> V_5 + V_5 ) ;
V_6 -= V_7 ;
V_5 = 0 ;
if ( F_2 ( V_2 ) || ! V_6 )
goto V_9;
V_3 = F_3 ( V_3 ) ;
V_4 -- ;
V_2 = F_3 ( V_2 ) ;
}
while ( V_6 > V_2 -> V_8 && V_4 -- ) {
V_6 -= V_2 -> V_8 ;
V_7 += V_2 -> V_8 ;
F_5 ( V_3 , F_6 ( V_2 ) ,
V_2 -> V_8 , V_2 -> V_5 ) ;
if ( F_2 ( V_2 ) || ! V_6 )
goto V_9;
V_2 = F_3 ( V_2 ) ;
V_3 = F_3 ( V_3 ) ;
}
if ( V_6 && V_4 ) {
F_5 ( V_3 , F_6 ( V_2 ) , V_6 , V_2 -> V_5 ) ;
V_7 += V_6 ;
}
V_9:
F_7 ( V_3 ) ;
return V_7 ;
}
static int F_8 ( struct V_1 * V_10 ,
T_1 V_5 , T_2 * V_11 , T_1 V_6 )
{
int V_12 = 0 , V_13 ;
struct V_14 V_15 ;
F_9 ( & V_15 , V_10 , F_10 ( V_10 ) ,
V_16 | V_17 ) ;
while ( F_11 ( & V_15 ) && V_6 > 0 ) {
if ( V_5 >= V_15 . V_8 ) {
V_5 -= V_15 . V_8 ;
continue;
}
V_13 = F_4 ( V_15 . V_8 - V_5 , V_6 ) ;
V_12 = memcmp ( V_15 . V_18 + V_5 , V_11 , V_13 ) ? - 1 : 0 ;
if ( V_12 )
break;
V_11 += V_13 ;
V_6 -= V_13 ;
V_5 = 0 ;
}
if ( ! V_12 && V_6 )
V_12 = - 1 ;
F_12 ( & V_15 ) ;
return V_12 ;
}
static int F_13 ( int V_19 )
{
if ( V_19 < 494 )
return 0 ;
return ( ( V_19 - 494 ) / 496 ) + 1 ;
}
static int F_14 ( int V_20 )
{
return V_20 / V_21 ;
}
static int F_15 ( struct V_22 * V_23 )
{
int V_24 = 0 ;
int V_25 ;
if ( ! V_26 )
return 0 ;
for ( V_25 = 0 ; V_25 < V_23 -> V_27 ; V_25 ++ )
V_24 += V_23 -> V_28 [ V_25 ] ;
if ( V_23 -> V_29 - F_16 ( V_23 -> V_30 ,
V_23 -> V_29 ) == V_24 )
return 0 ;
F_17 ( L_1 ) ;
V_23 -> V_31 = true ;
return - V_32 ;
}
static void F_18 ( struct V_22 * V_23 , int V_20 )
{
int V_33 = F_14 ( V_20 ) ;
if ( F_19 ( V_20 , V_23 -> V_30 ) ) {
F_17 (
L_2 , V_20 ) ;
V_23 -> V_31 = true ;
return;
}
if ( F_15 ( V_23 ) )
return;
F_20 ( V_20 , V_23 -> V_30 ) ;
V_23 -> V_28 [ V_33 ] -- ;
}
static void F_21 ( struct V_22 * V_23 , int V_20 )
{
int V_33 = F_14 ( V_20 ) ;
if ( ! F_19 ( V_20 , V_23 -> V_30 ) ) {
F_17 ( L_3 , V_20 ) ;
V_23 -> V_31 = true ;
return;
}
if ( F_15 ( V_23 ) )
return;
F_22 ( V_20 , V_23 -> V_30 ) ;
V_23 -> V_28 [ V_33 ] ++ ;
}
static void F_23 ( struct V_22 * V_23 )
{
V_23 -> V_34 . V_35 = F_24 ( struct V_36 , V_37 ) ;
V_23 -> V_34 . V_38 = sizeof( struct V_39 ) ;
V_23 -> V_34 . V_40 = F_24 ( struct V_36 , V_37 ) ;
V_23 -> V_34 . V_41 = sizeof( struct V_39 ) ;
V_23 -> V_42 = false ;
}
static int F_25 ( struct V_22 * V_23 , int (* F_26)
( struct V_43 * V_44 , struct V_45 * * V_46 ) )
{
struct V_43 * V_44 = V_23 -> V_44 ;
F_27 ( V_23 -> V_47 != - 1 ) ;
V_23 -> V_48 = false ;
V_23 -> V_47 = 0 ;
V_23 -> V_49 = 0 ;
memset ( & V_44 -> V_50 , 0 , sizeof( V_44 -> V_50 ) ) ;
V_44 -> V_51 = F_26 ;
F_28 ( V_44 -> V_52 ) ;
F_29 ( & V_44 -> V_53 ) ;
F_27 ( V_23 -> V_47 != - 1 ) ;
return V_23 -> V_49 ;
}
static int F_30 ( struct V_22 * V_23 , int error )
{
F_27 ( V_23 -> V_47 == - 1 ) ;
V_23 -> V_47 = - 1 ;
V_23 -> V_49 = error ;
V_23 -> V_44 -> V_51 = V_54 ;
if ( error )
F_23 ( V_23 ) ;
F_31 ( & V_23 -> V_44 -> V_53 ) ;
return - V_55 ;
}
static int F_32 ( struct V_22 * V_23 , long V_56 )
{
struct V_45 * V_57 = & V_23 -> V_44 -> V_50 ;
F_27 ( V_23 -> V_47 == - 1 ) ;
if ( ! V_23 -> V_48 ) {
V_23 -> V_58 = V_59 +
F_33 ( V_56 == - 1 ? 500 : V_56 ) ;
V_23 -> V_48 = true ;
} else if ( F_34 ( V_59 , V_23 -> V_58 ) ) {
V_57 -> V_60 [ 0 ] = V_61 ;
return 0 ;
}
if ( ( V_23 -> V_62 & V_63 ) &&
V_57 -> V_64 && ! V_57 -> error ) {
V_57 -> V_60 [ 0 ] = V_57 -> V_65 ;
V_57 -> V_64 = false ;
return 0 ;
} else {
F_35 ( V_57 , V_66 , NULL , 1 ) ;
return 1 ;
}
}
static int F_36 ( struct V_22 * V_23 , int V_5 , int V_6 )
{
struct V_45 * V_46 = & V_23 -> V_44 -> V_50 ;
if ( V_23 -> V_34 . V_40 != V_5 ||
V_23 -> V_34 . V_41 != V_6 || ! V_23 -> V_42 ) {
V_23 -> V_34 . V_40 = V_5 ;
V_23 -> V_34 . V_41 = V_6 ;
V_23 -> V_42 = true ;
F_35 ( V_46 , V_67 ,
& V_23 -> V_34 , sizeof( V_23 -> V_34 ) ) ;
return 0 ;
}
F_35 ( V_46 , V_68 , NULL , V_6 ) ;
return 1 ;
}
static int F_37 ( struct V_22 * V_23 , int V_5 , int V_6 , void * V_69 )
{
struct V_45 * V_46 = & V_23 -> V_44 -> V_50 ;
if ( V_23 -> V_34 . V_35 != V_5 ||
V_23 -> V_34 . V_38 != V_6 || ! V_23 -> V_42 ) {
V_23 -> V_34 . V_35 = V_5 ;
V_23 -> V_34 . V_38 = V_6 ;
V_23 -> V_42 = true ;
F_35 ( V_46 , V_67 ,
& V_23 -> V_34 , sizeof( V_23 -> V_34 ) ) ;
return 0 ;
}
F_35 ( V_46 , V_70 , V_69 , V_6 ) ;
return 1 ;
}
static int V_54 ( struct V_43 * V_44 ,
struct V_45 * * V_57 )
{
return - V_55 ;
}
static int F_38 ( struct V_43 * V_44 ,
struct V_45 * * V_71 )
{
struct V_22 * V_23 = F_39 ( V_44 ) ;
struct V_45 * V_57 = * V_71 = & V_44 -> V_50 ;
struct V_1 V_10 [ 2 ] ;
T_2 V_72 , V_73 ;
if ( V_57 -> error ) {
F_40 ( L_4 ) ;
return F_30 ( V_23 , V_57 -> error ) ;
}
V_74:
switch ( V_23 -> V_47 ) {
case V_75 :
if ( ! F_37 ( V_23 ,
F_24 ( struct V_36 , V_76 ) ,
sizeof( struct V_77 ) ,
( unsigned char * ) & V_23 -> V_78 . V_76 ) )
return 0 ;
V_23 -> V_47 = V_79 ;
return 0 ;
case V_79 :
V_72 = V_80 ;
F_35 ( V_57 , V_81 , & V_72 , 1 ) ;
V_23 -> V_47 = V_82 ;
return 0 ;
case V_82 :
V_23 -> V_47 = V_83 ;
if ( F_32 ( V_23 , - 1 ) )
return 0 ;
case V_83 :
V_73 = V_57 -> V_60 [ 0 ] ;
V_23 -> V_78 . V_84 . V_85 = V_73 ;
if ( V_73 & V_61 )
return F_30 ( V_23 , - V_86 ) ;
if ( ! ( V_73 & V_87 ) ) {
V_23 -> V_47 = V_82 ;
goto V_74;
}
V_23 -> V_48 = false ;
V_23 -> V_47 = ( V_73 & V_88 ) ?
V_89 : V_90 ;
goto V_74;
case V_89 :
if ( ! F_36 ( V_23 ,
F_24 ( struct V_36 , V_84 ) ,
sizeof( struct V_91 ) ) )
return 0 ;
V_23 -> V_47 = V_92 ;
return 0 ;
case V_92 :
V_23 -> V_78 . V_84 = * (struct V_91 * ) V_57 -> V_60 ;
V_23 -> V_47 = V_90 ;
case V_90 :
if ( ! F_36 ( V_23 ,
F_24 ( struct V_36 , V_93 ) ,
sizeof( struct V_94 ) ) )
return 0 ;
V_23 -> V_47 = V_95 ;
return 0 ;
case V_95 :
V_23 -> V_78 . V_93 =
* (struct V_94 * ) V_57 -> V_60 ;
V_23 -> V_47 = V_96 ;
case V_96 :
if ( V_23 -> V_78 . V_76 . V_97 == V_98 ) {
V_23 -> V_47 = V_99 ;
goto V_74;
}
F_41 ( V_10 , F_42 ( V_10 ) ) ;
F_1 ( V_23 -> V_100 , V_10 , F_42 ( V_10 ) ,
V_23 -> V_101 ,
V_23 -> V_102 ) ;
F_43 ( V_57 , V_103 , V_10 ) ;
V_23 -> V_47 = V_99 ;
return 0 ;
case V_99 :
if ( ! ( V_23 -> V_78 . V_84 . V_85 & V_88 ) ) {
V_23 -> V_101 += V_23 -> V_102 ;
return F_30 ( V_23 , 0 ) ;
}
if ( V_23 -> V_78 . V_84 . V_104 & V_105 ) {
F_40 ( L_5 ) ;
return F_30 ( V_23 , - V_106 ) ;
}
if ( V_23 -> V_78 . V_84 . V_104 & V_107 ) {
F_40 ( L_6 ) ;
V_23 -> V_101 += V_23 -> V_102 ;
return F_30 ( V_23 , - V_108 ) ;
} else {
F_40 ( L_7 ) ;
return F_30 ( V_23 , - V_86 ) ;
}
}
F_44 () ;
}
static int F_45 ( struct V_43 * V_44 ,
struct V_45 * * V_71 )
{
struct V_22 * V_23 = F_39 ( V_44 ) ;
struct V_45 * V_57 = * V_71 = & V_44 -> V_50 ;
struct V_1 V_10 [ 2 ] ;
T_2 V_73 , V_72 ;
if ( V_57 -> error )
return F_30 ( V_23 , V_57 -> error ) ;
V_74:
switch ( V_23 -> V_47 ) {
case V_109 :
if ( ! F_37 ( V_23 ,
F_24 ( struct V_36 , V_76 ) ,
sizeof( struct V_77 ) ,
& V_23 -> V_78 . V_76 ) )
return 0 ;
V_23 -> V_47 = V_110 ;
return 0 ;
case V_110 :
if ( ! F_37 ( V_23 ,
F_24 ( struct V_36 , V_93 ) ,
sizeof( struct V_94 ) ,
& V_23 -> V_78 . V_93 ) )
return 0 ;
V_23 -> V_47 = V_111 ;
return 0 ;
case V_111 :
V_72 = V_112 ;
F_35 ( V_57 , V_81 , & V_72 , 1 ) ;
V_23 -> V_47 = V_113 ;
return 0 ;
case V_113 :
V_23 -> V_47 = V_114 ;
if ( F_32 ( V_23 , - 1 ) )
return 0 ;
case V_114 :
V_73 = V_57 -> V_60 [ 0 ] ;
V_23 -> V_78 . V_84 . V_85 = V_73 ;
if ( V_73 & ( V_61 ) )
return F_30 ( V_23 , - V_86 ) ;
if ( V_73 & V_88 )
return F_30 ( V_23 , - V_106 ) ;
if ( V_23 -> V_115 == V_23 -> V_116 ) {
if ( V_73 & V_87 )
return F_30 ( V_23 , 0 ) ;
V_23 -> V_47 = V_113 ;
goto V_74;
}
if ( ! ( V_73 & V_117 ) ) {
V_23 -> V_47 = V_113 ;
goto V_74;
}
V_23 -> V_48 = false ;
V_23 -> V_47 = V_118 ;
case V_118 :
F_41 ( V_10 , F_42 ( V_10 ) ) ;
if ( F_1 ( V_23 -> V_100 , V_10 , F_42 ( V_10 ) ,
V_23 -> V_101 ,
V_23 -> V_102 ) < V_23 -> V_102 )
return F_30 ( V_23 , - V_86 ) ;
F_43 ( V_57 , V_119 , V_10 ) ;
V_57 -> V_64 = 1 ;
V_23 -> V_47 = V_120 ;
return 0 ;
case V_120 :
V_23 -> V_115 ++ ;
V_23 -> V_101 += V_23 -> V_102 ;
V_23 -> V_47 = V_113 ;
goto V_74;
default:
F_44 () ;
}
return 0 ;
}
static int F_46 ( struct V_43 * V_44 ,
struct V_45 * * V_71 )
{
struct V_22 * V_23 = F_39 ( V_44 ) ;
struct V_45 * V_57 = * V_71 = & V_44 -> V_50 ;
T_2 V_73 ;
if ( V_57 -> error ) {
F_40 ( L_8 ) ;
return F_30 ( V_23 , V_57 -> error ) ;
}
V_74:
switch ( V_23 -> V_47 ) {
case V_121 :
if ( ! F_37 ( V_23 ,
F_24 ( struct V_36 , V_76 ) ,
sizeof( struct V_77 ) ,
& V_23 -> V_78 . V_76 ) )
return 0 ;
V_23 -> V_47 = V_122 ;
return 0 ;
case V_122 :
if ( ! V_23 -> V_123 ) {
V_23 -> V_47 = V_124 ;
goto V_74;
}
if ( ! F_37 ( V_23 ,
F_24 ( struct V_36 , V_93 ) ,
sizeof( struct V_94 ) ,
& V_23 -> V_78 . V_93 ) )
return 0 ;
V_23 -> V_47 = V_124 ;
return 0 ;
case V_124 :
F_35 ( V_57 , V_81 , & V_23 -> V_125 , 1 ) ;
V_23 -> V_47 = V_126 ;
return 0 ;
case V_126 :
V_23 -> V_47 = V_127 ;
if ( F_32 ( V_23 , - 1 ) )
return 0 ;
case V_127 :
V_73 = V_57 -> V_60 [ 0 ] ;
if ( V_73 & V_61 )
return F_30 ( V_23 , - V_86 ) ;
if ( V_73 & V_88 )
return F_30 ( V_23 , - V_106 ) ;
if ( ! ( V_73 & V_87 ) ) {
V_23 -> V_47 = V_126 ;
goto V_74;
}
return F_30 ( V_23 , 0 ) ;
}
F_44 () ;
}
static int F_47 ( struct V_43 * V_44 ,
struct V_45 * * V_71 )
{
T_2 V_72 = V_128 ;
struct V_22 * V_23 = F_39 ( V_44 ) ;
struct V_45 * V_57 = * V_71 = & V_44 -> V_50 ;
if ( V_57 -> error )
return F_30 ( V_23 , V_57 -> error ) ;
switch ( V_23 -> V_47 ) {
case V_129 :
F_35 ( V_57 , V_81 , & V_72 , 1 ) ;
V_57 -> V_64 = 0 ;
V_23 -> V_47 = V_130 ;
return 0 ;
case V_130 :
return F_30 ( V_23 , 0 ) ;
}
F_44 () ;
}
static int F_48 ( struct V_43 * V_44 ,
struct V_45 * * V_71 )
{
struct V_22 * V_23 = F_39 ( V_44 ) ;
struct V_45 * V_57 = * V_71 = & V_44 -> V_50 ;
struct V_131 * V_52 = V_44 -> V_52 ;
if ( V_57 -> error ) {
F_40 ( L_9 ) ;
V_23 -> V_78 . V_76 . system &= ~ V_132 ;
return F_30 ( V_23 , V_57 -> error ) ;
}
switch ( V_23 -> V_47 ) {
case V_133 :
V_23 -> V_78 . V_76 . system |= V_132 ;
if ( ! F_37 ( V_23 ,
F_24 ( struct V_36 , V_76 ) ,
1 ,
( unsigned char * ) & V_23 -> V_78 . V_76 ) )
return 0 ;
V_23 -> V_47 = V_134 ;
return 0 ;
case V_134 :
V_52 -> V_135 ( V_52 , V_136 , V_137 ) ;
F_35 ( V_57 , V_66 , NULL , 1 ) ;
V_23 -> V_47 = V_138 ;
return 0 ;
case V_138 :
return F_30 ( V_23 , 0 ) ;
}
F_44 () ;
}
static int F_49 ( struct V_22 * V_23 , bool V_139 )
{
bool V_140 = V_23 -> V_78 . V_76 . system & V_132 ;
struct V_43 * V_44 = V_23 -> V_44 ;
struct V_131 * V_52 = V_44 -> V_52 ;
int error ;
V_23 -> V_78 . V_76 . system = V_141 ;
if ( V_139 ) {
error = V_52 -> V_135 ( V_52 ,
V_142 , V_143 ) ;
if ( error )
goto V_144;
F_23 ( V_23 ) ;
error = V_52 -> V_135 ( V_52 ,
V_142 , V_145 ) ;
if ( error )
goto V_144;
error = V_52 -> V_135 ( V_52 ,
V_136 , V_146 ) ;
if ( error ) {
V_144:
F_40 ( L_10 ) ;
V_23 -> V_31 = true ;
return - V_147 ;
}
}
error = F_25 ( V_23 , F_47 ) ;
if ( error ) {
F_40 ( L_11 ) ;
V_23 -> V_31 = true ;
return - V_148 ;
}
if ( V_140 )
F_50 ( V_23 ) ;
return 0 ;
}
static int F_50 ( struct V_22 * V_23 )
{
int error ;
error = F_25 ( V_23 , F_48 ) ;
if ( error ) {
F_17 ( L_12 ) ;
V_23 -> V_78 . V_76 . system &= ~ V_132 ;
F_49 ( V_23 , true ) ;
return - V_147 ;
}
V_23 -> V_62 |= V_63 ;
return 0 ;
}
static int F_51 ( struct V_22 * V_23 ,
T_3 V_20 , T_2 V_149 , T_2 V_150 )
{
if ( V_23 -> V_31 )
return - V_151 ;
V_23 -> V_78 . V_76 . V_152 = F_52 ( V_20 ) ;
V_23 -> V_78 . V_76 . V_153 = V_149 ;
V_23 -> V_78 . V_76 . V_97 = V_154 ;
V_23 -> V_78 . V_93 . V_155 = V_150 ;
V_23 -> V_125 = V_112 ;
V_23 -> V_123 = true ;
F_53 ( L_13 ,
V_150 , V_20 , V_149 ) ;
return F_25 ( V_23 , F_46 ) ;
}
static int F_54 ( struct V_22 * V_23 , int V_20 )
{
F_55 ( L_14 , V_20 ) ;
F_49 ( V_23 , true ) ;
return F_51 (
V_23 , V_20 , 0 , 0xFF & ~ V_156 ) ;
}
static int F_56 ( struct V_22 * V_23 , int V_20 , int V_149 )
{
F_40 ( L_15 , V_149 , V_20 ) ;
F_49 ( V_23 , true ) ;
return F_51 ( V_23 ,
V_20 , V_149 , ~ V_157 ) ;
}
static int F_57 ( struct V_22 * V_23 , T_3 V_20 )
{
int error , V_158 ;
if ( V_23 -> V_31 )
return - V_151 ;
F_53 ( L_16 , V_20 ) ;
for ( V_158 = 1 ; V_158 < 3 ; V_158 ++ ) {
V_23 -> V_78 . V_76 . V_152 = F_52 ( V_20 ) ;
V_23 -> V_78 . V_76 . V_153 = 0 ;
V_23 -> V_78 . V_76 . V_97 = V_159 ;
V_23 -> V_125 = V_160 ;
V_23 -> V_123 = false ;
error = F_25 ( V_23 , F_46 ) ;
if ( ! error || F_49 ( V_23 , true ) )
break;
}
if ( error ) {
F_17 ( L_17 , V_20 ) ;
F_54 ( V_23 , V_20 ) ;
}
F_53 ( L_18 , V_20 ) ;
F_21 ( V_23 , V_20 ) ;
F_20 ( V_20 , V_23 -> V_161 ) ;
return error ;
}
static int F_58 ( struct V_22 * V_23 ,
T_3 V_20 , T_2 V_149 , struct V_94 * V_162 ,
struct V_1 * V_10 , int V_5 )
{
int V_158 , error ;
if ( V_20 == V_163 ) {
unsigned long V_164 ;
struct V_14 V_15 ;
T_1 V_6 = V_23 -> V_102 ;
F_53 ( L_19 ) ;
F_59 ( V_164 ) ;
F_9 ( & V_15 , V_10 , F_10 ( V_10 ) ,
V_16 | V_165 ) ;
while ( F_11 ( & V_15 ) && V_6 > 0 ) {
int V_166 ;
if ( V_5 && V_5 >= V_15 . V_8 ) {
V_5 -= V_15 . V_8 ;
continue;
}
V_166 = F_4 ( V_15 . V_8 - V_5 , V_6 ) ;
memset ( V_15 . V_18 + V_5 , 0xFF , V_166 ) ;
V_6 -= V_166 ;
V_5 = 0 ;
}
F_12 ( & V_15 ) ;
F_60 ( V_164 ) ;
if ( V_5 )
return - V_147 ;
if ( V_162 )
memset ( V_162 , 0xFF , sizeof( * V_162 ) ) ;
return 0 ;
}
if ( V_20 >= V_23 -> V_29 ) {
F_17 ( L_20 , V_20 ) ;
return - V_32 ;
}
for ( V_158 = 1 ; V_158 < 3 ; V_158 ++ ) {
V_23 -> V_78 . V_76 . V_152 = F_52 ( V_20 ) ;
V_23 -> V_78 . V_76 . V_153 = V_149 ;
V_23 -> V_78 . V_76 . V_97 = V_167 ;
V_23 -> V_100 = V_10 ;
V_23 -> V_101 = V_5 ;
error = F_25 ( V_23 , F_38 ) ;
if ( error == - V_108 ) {
F_55 ( L_21 ,
V_20 , V_149 ) ;
error = 0 ;
}
if ( ! error && V_162 )
* V_162 = V_23 -> V_78 . V_93 ;
if ( ! error || F_49 ( V_23 , true ) )
break;
}
if ( error == - V_106 ) {
F_17 ( L_22 ,
V_20 , V_149 ) ;
if ( V_23 -> V_78 . V_93 . V_155 &
V_157 )
F_56 ( V_23 , V_20 , V_149 ) ;
return - V_106 ;
}
if ( error )
F_17 ( L_23 ,
V_20 , V_149 , error ) ;
return error ;
}
static int F_61 ( struct V_22 * V_23 , T_3 V_20 , T_3 V_149 ,
struct V_94 * V_162 )
{
int error ;
F_62 ( ! V_162 ) ;
V_23 -> V_78 . V_76 . V_152 = F_52 ( V_20 ) ;
V_23 -> V_78 . V_76 . V_153 = V_149 ;
V_23 -> V_78 . V_76 . V_97 = V_98 ;
if ( V_20 > V_23 -> V_29 ) {
F_17 ( L_24 , V_20 ) ;
return - V_32 ;
}
error = F_25 ( V_23 , F_38 ) ;
* V_162 = V_23 -> V_78 . V_93 ;
if ( error == - V_108 ) {
F_55 ( L_21 ,
V_20 , V_149 ) ;
return 0 ;
}
return error ;
}
static int F_63 ( struct V_22 * V_23 , T_3 V_20 ,
struct V_1 * V_168 , int V_5 )
{
struct V_1 V_10 ;
int V_149 = 0 , error ;
F_64 ( & V_10 , V_23 -> V_169 , V_23 -> V_170 ) ;
while ( V_149 < V_23 -> V_116 ) {
error = F_58 ( V_23 , V_20 , V_149 ,
NULL , & V_10 , V_149 * V_23 -> V_102 ) ;
if ( error )
return error ;
V_149 ++ ;
}
if ( F_8 ( V_168 , V_5 ,
V_23 -> V_169 , V_23 -> V_170 ) )
return - V_86 ;
return 0 ;
}
static int F_65 ( struct V_22 * V_23 ,
T_3 V_20 , T_4 V_19 , struct V_1 * V_10 , int V_5 )
{
int error , V_171 = 1 ;
F_62 ( V_10 -> V_8 < V_23 -> V_102 ) ;
if ( V_23 -> V_31 )
return - V_151 ;
if ( V_20 == V_163 ) {
F_17 (
L_25 ) ;
return - V_32 ;
}
if ( V_20 >= V_23 -> V_29 || V_19 >= V_23 -> V_172 ) {
F_17 (
L_26 ) ;
return - V_32 ;
}
if ( F_13 ( V_19 ) != F_14 ( V_20 ) ) {
F_17 ( L_27 ) ;
return - V_32 ;
}
if ( V_20 == V_23 -> V_173 [ 0 ] ||
V_20 == V_23 -> V_173 [ 1 ] ) {
F_17 ( L_28 ) ;
return - V_32 ;
}
while ( 1 ) {
if ( V_23 -> V_31 )
return - V_151 ;
V_23 -> V_78 . V_76 . V_97 = V_159 ;
V_23 -> V_78 . V_76 . V_153 = 0 ;
V_23 -> V_78 . V_76 . V_152 = F_52 ( V_20 ) ;
V_23 -> V_78 . V_93 . V_174 = 0xFF ;
V_23 -> V_78 . V_93 . V_155 = 0xF8 ;
V_23 -> V_78 . V_93 . V_175 = F_52 ( V_19 ) ;
V_23 -> V_100 = V_10 ;
V_23 -> V_101 = V_5 ;
V_23 -> V_115 = 0 ;
error = F_25 ( V_23 , F_45 ) ;
if ( ! error && ( V_176 ||
! F_19 ( V_20 , V_23 -> V_161 ) ) )
error = F_63 ( V_23 , V_20 , V_10 , V_5 ) ;
if ( ! error )
break;
if ( V_171 > 1 || F_49 ( V_23 , true ) )
break;
F_17 ( L_29 , V_20 ) ;
error = F_57 ( V_23 , V_20 ) ;
if ( error )
break;
V_171 ++ ;
}
return error ;
}
static T_3 F_66 ( struct V_22 * V_23 , int V_33 )
{
T_3 V_177 ;
int V_20 = V_33 * V_21 ;
int V_25 ;
F_67 ( & V_177 , sizeof( V_177 ) ) ;
if ( ! V_23 -> V_28 [ V_33 ] ) {
F_17 ( L_30 , V_33 ) ;
V_23 -> V_31 = true ;
return V_163 ;
}
V_177 %= V_23 -> V_28 [ V_33 ] ;
F_53 ( L_31 ,
V_23 -> V_28 [ V_33 ] , V_177 ) ;
V_20 = F_68 ( V_23 -> V_30 ,
V_23 -> V_29 , V_20 ) ;
for ( V_25 = 0 ; V_25 < V_177 ; ++ V_25 )
V_20 = F_68 ( V_23 -> V_30 ,
V_23 -> V_29 , V_20 + 1 ) ;
F_53 ( L_32 , V_20 ) ;
if ( V_20 == V_23 -> V_29 || ( F_14 ( V_20 ) ) != V_33 ) {
F_17 ( L_33 ) ;
V_23 -> V_31 = true ;
return V_163 ;
}
F_18 ( V_23 , V_20 ) ;
return V_20 ;
}
static int F_69 ( struct V_22 * V_23 , T_3 V_19 ,
struct V_1 * V_10 , int V_5 )
{
T_3 V_20 , V_178 ;
int error , V_158 ;
V_20 = V_23 -> V_179 [ V_19 ] ;
F_53 ( L_34 , V_19 , V_20 ) ;
if ( V_20 != V_163 ) {
F_53 ( L_35 ) ;
F_51 ( V_23 , V_20 , 0 ,
0xFF & ~ V_180 ) ;
}
for ( V_158 = 0 ; V_158 < 3 ; V_158 ++ ) {
V_178 = F_66 ( V_23 ,
F_13 ( V_19 ) ) ;
if ( V_178 == V_163 ) {
error = - V_86 ;
goto V_9;
}
F_53 ( L_36 ,
V_178 ) ;
error = F_65 ( V_23 , V_178 , V_19 , V_10 , V_5 ) ;
if ( error == - V_106 ) {
F_54 ( V_23 , V_178 ) ;
continue;
}
if ( error )
goto V_9;
F_53 ( L_37 ) ;
F_57 ( V_23 , V_20 ) ;
V_23 -> V_179 [ V_19 ] = V_178 ;
return 0 ;
}
V_9:
if ( error ) {
F_17 ( L_38 , V_158 ) ;
V_23 -> V_31 = true ;
}
return error ;
}
static void F_70 ( struct V_181 * V_182 )
{
V_182 -> V_183 . V_184 = F_71 ( V_182 -> V_183 . V_184 ) ;
V_182 -> V_183 . V_185 = F_71 ( V_182 -> V_183 . V_185 ) ;
V_182 -> V_186 . V_187 . V_188
= F_72 ( V_182 -> V_186 . V_187 . V_188 ) ;
V_182 -> V_186 . V_187 . V_189
= F_72 ( V_182 -> V_186 . V_187 . V_189 ) ;
V_182 -> V_186 . V_190 . V_188
= F_72 ( V_182 -> V_186 . V_190 . V_188 ) ;
V_182 -> V_186 . V_190 . V_189
= F_72 ( V_182 -> V_186 . V_190 . V_189 ) ;
V_182 -> V_191 . V_170 = F_71 ( V_182 -> V_191 . V_170 ) ;
V_182 -> V_191 . V_192 = F_71 ( V_182 -> V_191 . V_192 ) ;
V_182 -> V_191 . V_193
= F_71 ( V_182 -> V_191 . V_193 ) ;
V_182 -> V_191 . V_102 = F_71 ( V_182 -> V_191 . V_102 ) ;
V_182 -> V_191 . V_194
= F_71 ( V_182 -> V_191 . V_194 ) ;
V_182 -> V_191 . V_195 = F_71 ( V_182 -> V_191 . V_195 ) ;
V_182 -> V_191 . V_196
= F_71 ( V_182 -> V_191 . V_196 ) ;
V_182 -> V_191 . V_197 = F_71 ( V_182 -> V_191 . V_197 ) ;
V_182 -> V_191 . V_198 = F_71 ( V_182 -> V_191 . V_198 ) ;
}
static int F_73 ( struct V_22 * V_23 )
{
int V_20 = 0 ;
struct V_1 V_10 ;
struct V_94 V_162 ;
struct V_181 * V_149 ;
V_23 -> V_173 [ 0 ] = V_163 ;
V_23 -> V_173 [ 1 ] = V_163 ;
V_23 -> V_199 = 0 ;
F_53 ( L_39 ) ;
if ( ! V_23 -> V_200 ) {
V_149 = F_74 ( sizeof( struct V_181 ) * 2 , V_201 ) ;
if ( ! V_149 )
return - V_202 ;
V_23 -> V_200 = V_149 ;
} else
V_149 = V_23 -> V_200 ;
V_23 -> V_29 = V_203 ;
for ( V_20 = 0 ; V_20 < V_203 ; V_20 ++ ) {
F_64 ( & V_10 , V_149 , sizeof( * V_149 ) ) ;
if ( F_58 ( V_23 , V_20 , 0 , & V_162 , & V_10 , 0 ) ) {
F_40 ( L_40 , V_20 ) ;
continue;
}
if ( V_162 . V_174 & V_204 ) {
F_40 ( L_41 ,
V_20 ) ;
continue;
}
if ( F_71 ( V_149 -> V_183 . V_184 ) != V_205 ) {
F_40 ( L_42 , V_20 ) ;
continue;
}
F_70 ( V_149 ) ;
V_23 -> V_173 [ V_23 -> V_199 ] = V_20 ;
V_149 ++ ;
V_23 -> V_199 ++ ;
if ( V_23 -> V_199 == 2 )
break;
}
if ( ! V_23 -> V_199 ) {
F_17 ( L_43 ) ;
return - V_86 ;
}
F_53 ( L_44 ) ;
return 0 ;
}
static int F_75 ( struct V_22 * V_23 , int V_206 )
{
struct V_181 * V_207 ;
struct V_1 V_10 ;
T_3 * V_11 = NULL ;
int V_5 = 0 ;
int V_25 , error = 0 ;
int V_189 , V_208 , V_149 , V_209 , V_210 ;
T_3 V_20 ;
F_62 ( V_206 > 1 ) ;
V_207 = & V_23 -> V_200 [ V_206 ] ;
V_20 = V_23 -> V_173 [ V_206 ] ;
if ( V_23 -> V_173 [ V_206 ] == V_163 )
return - V_32 ;
V_189 = V_207 -> V_186 . V_187 . V_189 ;
V_208 = sizeof( struct V_181 ) +
V_207 -> V_186 . V_187 . V_188 ;
if ( ! V_189 )
return 0 ;
V_149 = V_208 / V_23 -> V_102 ;
V_209 = V_208 % V_23 -> V_102 ;
V_210 =
F_76 ( V_189 + V_209 , V_23 -> V_102 ) *
V_23 -> V_102 ;
F_40 ( L_45 ,
V_20 , V_208 , V_189 ) ;
V_11 = F_77 ( V_210 , V_201 ) ;
if ( ! V_11 )
return - V_202 ;
F_64 ( & V_10 , V_11 , V_210 ) ;
while ( V_5 < V_210 ) {
error = F_58 ( V_23 , V_20 , V_149 , NULL , & V_10 , V_5 ) ;
if ( error )
goto V_9;
V_149 ++ ;
V_5 += V_23 -> V_102 ;
if ( V_149 == V_23 -> V_116 ) {
F_17 (
L_46 ) ;
break;
}
}
for ( V_25 = V_209 ; V_25 < V_189 / sizeof( T_3 ) ; V_25 ++ ) {
T_3 V_211 = F_71 ( V_11 [ V_25 ] ) ;
if ( V_211 >= V_23 -> V_29 ) {
F_40 ( L_47 ,
V_211 ) ;
continue;
}
if ( F_19 ( V_211 , V_23 -> V_30 ) ) {
F_40 ( L_48 ,
V_211 ) ;
continue;
}
F_40 ( L_49 , V_211 ) ;
F_18 ( V_23 , V_211 ) ;
}
V_9:
F_78 ( V_11 ) ;
return error ;
}
static int F_79 ( struct V_22 * V_23 )
{
int V_25 ;
if ( V_23 -> V_212 )
return 0 ;
V_23 -> V_27 = V_23 -> V_29 / V_21 ;
V_23 -> V_172 = V_23 -> V_27 * 496 - 2 ;
V_23 -> V_30 = F_77 ( V_23 -> V_29 / 8 , V_201 ) ;
V_23 -> V_161 = F_77 ( V_23 -> V_29 / 8 , V_201 ) ;
V_23 -> V_179 =
F_74 ( V_23 -> V_172 * sizeof( T_3 ) , V_201 ) ;
if ( ! V_23 -> V_30 || ! V_23 -> V_179 ||
! V_23 -> V_161 ) {
F_78 ( V_23 -> V_30 ) ;
F_78 ( V_23 -> V_179 ) ;
F_78 ( V_23 -> V_161 ) ;
return - V_202 ;
}
for ( V_25 = 0 ; V_25 < V_23 -> V_27 ; V_25 ++ )
V_23 -> V_28 [ V_25 ] = V_21 ;
memset ( V_23 -> V_179 , V_163 ,
V_23 -> V_172 * sizeof( T_3 ) ) ;
F_40 ( L_50 ,
V_23 -> V_27 , V_23 -> V_172 ) ;
V_23 -> V_212 = true ;
return 0 ;
}
static int F_80 ( struct V_22 * V_23 )
{
T_3 V_20 , V_19 , V_213 ;
T_2 V_155 , V_174 , V_214 ;
int error ;
struct V_94 V_162 ;
T_2 * V_215 = F_77 ( V_23 -> V_29 , V_201 ) ;
if ( ! V_215 )
return - V_202 ;
F_40 ( L_51 ) ;
for ( V_20 = 0 ; V_20 < V_23 -> V_29 ; V_20 ++ ) {
if ( V_20 == V_23 -> V_173 [ 0 ] ||
V_20 == V_23 -> V_173 [ 1 ] ) {
F_53 ( L_52 , V_20 ) ;
F_18 ( V_23 , V_20 ) ;
continue;
}
if ( F_19 ( V_20 , V_23 -> V_30 ) ) {
F_53 ( L_53 , V_20 ) ;
continue;
}
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
error = F_61 ( V_23 , V_20 , 0 , & V_162 ) ;
if ( error == - V_106 ) {
F_55 (
L_54 , V_20 ) ;
F_18 ( V_23 , V_20 ) ;
F_57 ( V_23 , V_20 ) ;
continue;
} else if ( error ) {
F_17 ( L_55 ,
error , V_20 ) ;
F_78 ( V_215 ) ;
return error ;
}
V_19 = F_71 ( V_162 . V_175 ) ;
V_174 = V_162 . V_174 ;
V_155 = V_162 . V_155 ;
V_215 [ V_20 ] = V_155 ;
if ( ! ( V_155 & V_156 ) ) {
F_40 ( L_56 , V_20 ) ;
F_18 ( V_23 , V_20 ) ;
continue;
}
if ( ( V_174 & V_216 ) !=
V_216 ) {
F_40 ( L_57 ,
V_20 , V_174 ) ;
F_18 ( V_23 , V_20 ) ;
continue;
}
if ( ! ( V_174 & V_217 ) ) {
F_40 ( L_58 , V_20 ) ;
F_18 ( V_23 , V_20 ) ;
F_57 ( V_23 , V_20 ) ;
continue;
}
if ( V_19 == V_163 ) {
F_53 ( L_59 , V_20 ) ;
continue;
}
F_18 ( V_23 , V_20 ) ;
if ( F_13 ( V_19 ) != F_14 ( V_20 ) ) {
F_55 ( L_60 ,
V_20 , V_19 ) ;
F_57 ( V_23 , V_20 ) ;
continue;
}
if ( V_23 -> V_179 [ V_19 ] == V_163 ) {
F_53 ( L_61 , V_20 , V_19 ) ;
V_23 -> V_179 [ V_19 ] = V_20 ;
continue;
}
V_213 = V_23 -> V_179 [ V_19 ] ;
V_214 = V_215 [ V_213 ] ;
F_55 ( L_62 ,
V_20 , V_213 ) ;
if ( ! ( V_155 & V_180 ) ) {
F_55 ( L_63 , V_20 ) ;
F_57 ( V_23 , V_213 ) ;
V_23 -> V_179 [ V_19 ] = V_20 ;
continue;
}
if ( ! ( V_214 & V_180 ) ) {
F_55 ( L_63 ,
V_213 ) ;
F_57 ( V_23 , V_20 ) ;
continue;
}
F_55 ( L_64 ,
V_20 , V_213 , V_213 ) ;
F_57 ( V_23 , V_213 ) ;
V_23 -> V_179 [ V_19 ] = V_20 ;
}
F_40 ( L_65 ) ;
F_78 ( V_215 ) ;
return 0 ;
}
static void F_81 ( unsigned long V_60 )
{
struct V_22 * V_23 = (struct V_22 * ) V_60 ;
V_23 -> V_218 = true ;
F_82 ( V_23 -> V_219 , & V_23 -> V_220 ) ;
}
static void F_83 ( struct V_22 * V_23 )
{
if ( V_23 -> V_221 == V_163 )
return;
F_84 ( & V_23 -> V_222 ) ;
F_53 ( L_66 ) ;
V_23 -> V_221 = V_163 ;
F_85 ( & V_23 -> V_223 , V_23 -> V_116 ) ;
}
static int F_86 ( struct V_22 * V_23 )
{
F_87 ( & V_23 -> V_222 , F_81 ,
( unsigned long ) V_23 ) ;
if ( ! V_23 -> V_224 )
V_23 -> V_224 = F_77 ( V_23 -> V_170 , V_201 ) ;
if ( ! V_23 -> V_224 )
return - V_202 ;
F_83 ( V_23 ) ;
return 0 ;
}
static int F_88 ( struct V_22 * V_23 )
{
struct V_1 V_10 ;
struct V_94 V_162 ;
int V_149 , V_5 , error ;
T_3 V_20 , V_19 ;
if ( V_23 -> V_31 )
return - V_151 ;
if ( V_23 -> V_221 == V_163 )
return 0 ;
V_19 = V_23 -> V_221 ;
V_20 = V_23 -> V_179 [ V_19 ] ;
F_53 ( L_67 ,
V_20 , V_23 -> V_221 ) ;
F_64 ( & V_10 , V_23 -> V_224 , V_23 -> V_170 ) ;
for ( V_149 = 0 ; V_149 < V_23 -> V_116 ; V_149 ++ ) {
if ( F_19 ( V_149 , & V_23 -> V_223 ) )
continue;
V_5 = V_149 * V_23 -> V_102 ;
F_53 ( L_68 ,
V_149 , V_19 ) ;
error = F_58 ( V_23 , V_20 , V_149 , & V_162 , & V_10 , V_5 ) ;
if ( error == - V_106 ) {
F_17 ( L_69 , V_149 ) ;
continue;
}
if ( error )
return error ;
if ( ( V_162 . V_155 & V_225 ) !=
V_225 ) {
F_40 ( L_70 , V_149 ) ;
continue;
}
F_89 ( V_149 , & V_23 -> V_223 ) ;
}
error = F_69 ( V_23 , V_23 -> V_221 , & V_10 , 0 ) ;
V_20 = V_23 -> V_179 [ V_23 -> V_221 ] ;
if ( ! error ) {
for ( V_149 = 0 ; V_149 < V_23 -> V_116 ; V_149 ++ ) {
if ( F_19 ( V_149 , & V_23 -> V_223 ) )
continue;
F_40 ( L_71 ,
V_149 ) ;
F_51 ( V_23 ,
V_20 , V_149 , 0xFF & ~ V_225 ) ;
}
}
F_83 ( V_23 ) ;
return error ;
}
static int F_90 ( struct V_22 * V_23 , int V_19 ,
int V_149 , bool V_226 , struct V_1 * V_10 , int V_5 )
{
int error ;
struct V_1 V_227 [ 10 ] ;
if ( V_23 -> V_31 )
return - V_151 ;
if ( V_23 -> V_221 == V_163 ||
V_19 != V_23 -> V_221 )
if ( V_226 )
return 0 ;
if ( V_23 -> V_221 != V_163 &&
V_19 != V_23 -> V_221 ) {
F_53 ( L_72 ) ;
error = F_88 ( V_23 ) ;
if ( error )
return error ;
}
if ( V_23 -> V_221 == V_163 ) {
V_23 -> V_221 = V_19 ;
F_91 ( & V_23 -> V_222 ,
V_59 + F_33 ( V_228 ) ) ;
}
F_53 ( L_73 , V_19 , V_149 ) ;
F_41 ( V_227 , F_42 ( V_227 ) ) ;
F_1 ( V_10 , V_227 , F_42 ( V_227 ) , V_5 , V_23 -> V_102 ) ;
F_92 ( V_227 , F_10 ( V_227 ) ,
V_23 -> V_224 + V_149 * V_23 -> V_102 , V_23 -> V_102 ) ;
F_89 ( V_149 , & V_23 -> V_223 ) ;
return 0 ;
}
static int F_93 ( struct V_22 * V_23 , int V_19 ,
int V_149 , struct V_1 * V_10 , int V_5 )
{
int V_20 = V_23 -> V_179 [ V_19 ] ;
struct V_1 V_227 [ 10 ] ;
int error = 0 ;
if ( V_19 == V_23 -> V_221 &&
F_19 ( V_149 , & V_23 -> V_223 ) ) {
F_53 ( L_74 ,
V_19 , V_20 , V_149 ) ;
F_41 ( V_227 , F_42 ( V_227 ) ) ;
F_1 ( V_10 , V_227 , F_42 ( V_227 ) ,
V_5 , V_23 -> V_102 ) ;
F_94 ( V_227 , F_10 ( V_227 ) ,
V_23 -> V_224 + V_23 -> V_102 * V_149 ,
V_23 -> V_102 ) ;
} else {
F_53 ( L_75 ,
V_19 , V_20 , V_149 ) ;
error = F_58 ( V_23 , V_20 , V_149 , NULL , V_10 , V_5 ) ;
if ( error )
return error ;
F_90 ( V_23 , V_19 , V_149 , true , V_10 , V_5 ) ;
}
return error ;
}
static int F_95 ( struct V_43 * V_44 )
{
struct V_22 * V_23 = F_39 ( V_44 ) ;
struct V_131 * V_52 = V_44 -> V_52 ;
struct V_181 * V_207 ;
int error = 0 , V_25 , V_229 ;
V_23 -> V_62 = 0 ;
if ( V_44 -> V_37 . V_230 >= V_231 &&
V_44 -> V_37 . V_230 <= V_231 )
V_23 -> V_31 = true ;
V_23 -> V_47 = - 1 ;
error = F_49 ( V_23 , false ) ;
if ( error )
return error ;
if ( V_52 -> V_62 & V_232 )
F_50 ( V_23 ) ;
V_23 -> V_102 = sizeof( struct V_181 ) ;
error = F_73 ( V_23 ) ;
if ( error )
return - V_86 ;
V_207 = & V_23 -> V_200 [ 0 ] ;
V_23 -> V_29 = V_207 -> V_191 . V_192 ;
V_23 -> V_102 = V_207 -> V_191 . V_102 ;
V_23 -> V_116 = V_207 -> V_191 . V_170 * 2 ;
V_23 -> V_170 = V_23 -> V_102 * V_23 -> V_116 ;
if ( V_23 -> V_102 > V_233 ) {
F_40 ( L_76 , V_23 -> V_102 ) ;
return - V_32 ;
}
V_23 -> V_169 = F_77 ( V_23 -> V_170 , V_201 ) ;
if ( ! V_23 -> V_169 )
return - V_202 ;
V_229 = ( V_23 -> V_170 * V_23 -> V_29 ) >> 20 ;
for ( V_25 = 0 ; V_234 [ V_25 ] . V_235 ; V_25 ++ ) {
if ( V_234 [ V_25 ] . V_235 != V_229 )
continue;
V_23 -> V_236 . V_237 = V_234 [ V_25 ] . V_238 ;
V_23 -> V_236 . V_239 = V_234 [ V_25 ] . V_240 ;
V_23 -> V_236 . V_241 = V_234 [ V_25 ] . V_242 ;
break;
}
if ( V_207 -> V_191 . V_243 == 1 )
V_23 -> V_62 |= V_232 ;
if ( V_207 -> V_191 . V_244 & 0x03 )
V_23 -> V_31 = true ;
F_40 ( L_77 , V_23 -> V_29 ) ;
F_40 ( L_78 , V_23 -> V_116 ) ;
F_40 ( L_79 , V_23 -> V_102 ) ;
F_40 ( L_80 , ! ! ( V_23 -> V_62 & V_232 ) ) ;
F_40 ( L_81 , V_23 -> V_31 ) ;
#if 0
if (host->caps & msb->caps & MEMSTICK_CAP_PAR4)
msb_switch_to_parallel(msb);
#endif
error = F_86 ( V_23 ) ;
if ( error )
return error ;
error = F_79 ( V_23 ) ;
if ( error )
return error ;
error = F_75 ( V_23 , 0 ) ;
if ( error && error != - V_202 ) {
F_40 ( L_82 ) ;
error = F_75 ( V_23 , 1 ) ;
}
if ( error )
return error ;
error = F_80 ( V_23 ) ;
if ( error ) {
F_17 ( L_83 ) ;
return error ;
}
return 0 ;
}
static int F_96 ( struct V_22 * V_23 , int V_19 ,
int V_149 , struct V_1 * V_10 , T_1 V_6 , int * V_245 )
{
int error = 0 ;
T_5 V_5 = 0 ;
* V_245 = 0 ;
while ( V_5 < V_6 ) {
if ( V_149 == 0 && V_6 - V_5 >= V_23 -> V_170 ) {
if ( V_23 -> V_221 == V_19 )
F_83 ( V_23 ) ;
F_53 ( L_84 , V_19 ) ;
error = F_69 ( V_23 , V_19 , V_10 , V_5 ) ;
if ( error )
return error ;
V_5 += V_23 -> V_170 ;
* V_245 += V_23 -> V_170 ;
V_19 ++ ;
continue;
}
error = F_90 ( V_23 , V_19 , V_149 , false , V_10 , V_5 ) ;
if ( error )
return error ;
V_5 += V_23 -> V_102 ;
* V_245 += V_23 -> V_102 ;
V_149 ++ ;
if ( V_149 == V_23 -> V_116 ) {
V_149 = 0 ;
V_19 ++ ;
}
}
return 0 ;
}
static int F_97 ( struct V_22 * V_23 , int V_19 ,
int V_149 , struct V_1 * V_10 , int V_6 , int * V_246 )
{
int error = 0 ;
int V_5 = 0 ;
* V_246 = 0 ;
while ( V_5 < V_6 ) {
error = F_93 ( V_23 , V_19 , V_149 , V_10 , V_5 ) ;
if ( error )
return error ;
V_5 += V_23 -> V_102 ;
* V_246 += V_23 -> V_102 ;
V_149 ++ ;
if ( V_149 == V_23 -> V_116 ) {
V_149 = 0 ;
V_19 ++ ;
}
}
return 0 ;
}
static void F_98 ( struct V_247 * V_248 )
{
struct V_22 * V_23 = F_99 ( V_248 , struct V_22 , V_220 ) ;
int V_149 , error , V_6 ;
T_6 V_19 ;
unsigned long V_164 ;
struct V_1 * V_10 = V_23 -> V_249 ;
F_53 ( L_85 ) ;
while ( 1 ) {
F_100 ( & V_23 -> V_250 , V_164 ) ;
if ( V_23 -> V_218 ) {
V_23 -> V_218 = false ;
F_101 ( & V_23 -> V_250 , V_164 ) ;
F_88 ( V_23 ) ;
continue;
}
if ( ! V_23 -> V_46 ) {
V_23 -> V_46 = F_102 ( V_23 -> V_251 ) ;
if ( ! V_23 -> V_46 ) {
F_53 ( L_86 ) ;
F_101 ( & V_23 -> V_250 , V_164 ) ;
return;
}
}
F_101 ( & V_23 -> V_250 , V_164 ) ;
if ( ! V_23 -> V_46 )
return;
F_53 ( L_87 ) ;
F_103 ( V_23 -> V_251 , V_23 -> V_46 , V_10 ) ;
V_19 = F_104 ( V_23 -> V_46 ) ;
F_105 ( V_19 , V_23 -> V_102 / 512 ) ;
V_149 = F_105 ( V_19 , V_23 -> V_116 ) ;
if ( F_106 ( V_23 -> V_46 ) == V_252 )
error = F_97 ( V_23 , V_19 , V_149 , V_10 ,
F_107 ( V_23 -> V_46 ) , & V_6 ) ;
else
error = F_96 ( V_23 , V_19 , V_149 , V_10 ,
F_107 ( V_23 -> V_46 ) , & V_6 ) ;
F_100 ( & V_23 -> V_250 , V_164 ) ;
if ( V_6 )
if ( ! F_108 ( V_23 -> V_46 , 0 , V_6 ) )
V_23 -> V_46 = NULL ;
if ( error && V_23 -> V_46 ) {
F_53 ( L_88 ) ;
if ( ! F_108 ( V_23 -> V_46 , error , V_23 -> V_102 ) )
V_23 -> V_46 = NULL ;
}
if ( V_23 -> V_46 )
F_53 ( L_89 ) ;
F_101 ( & V_23 -> V_250 , V_164 ) ;
}
}
static int F_109 ( struct V_253 * V_254 , T_7 V_255 )
{
struct V_256 * V_257 = V_254 -> V_258 ;
struct V_22 * V_23 = V_257 -> V_259 ;
F_53 ( L_90 ) ;
F_110 ( & V_260 ) ;
if ( V_23 && V_23 -> V_44 )
V_23 -> V_261 ++ ;
F_111 ( & V_260 ) ;
return 0 ;
}
static void F_112 ( struct V_22 * V_23 )
{
F_78 ( V_23 -> V_200 ) ;
F_78 ( V_23 -> V_30 ) ;
F_78 ( V_23 -> V_179 ) ;
F_78 ( V_23 -> V_224 ) ;
V_23 -> V_44 = NULL ;
}
static int F_113 ( struct V_256 * V_257 )
{
struct V_22 * V_23 = V_257 -> V_259 ;
F_53 ( L_91 ) ;
F_110 ( & V_260 ) ;
if ( V_23 ) {
if ( V_23 -> V_261 )
V_23 -> V_261 -- ;
if ( ! V_23 -> V_261 ) {
V_257 -> V_259 = NULL ;
F_114 ( & V_262 , V_23 -> V_263 ) ;
F_115 ( V_257 ) ;
F_78 ( V_23 ) ;
}
}
F_111 ( & V_260 ) ;
return 0 ;
}
static void F_116 ( struct V_256 * V_257 , T_7 V_255 )
{
F_113 ( V_257 ) ;
}
static int F_117 ( struct V_253 * V_254 ,
struct V_264 * V_265 )
{
struct V_22 * V_23 = V_254 -> V_258 -> V_259 ;
* V_265 = V_23 -> V_236 ;
return 0 ;
}
static int F_118 ( struct V_266 * V_267 , struct V_268 * V_46 )
{
if ( V_46 -> V_269 != V_270 &&
V_46 -> V_269 != V_271 ) {
F_119 ( V_46 , L_92 ) ;
return V_272 ;
}
V_46 -> V_273 |= V_274 ;
return V_275 ;
}
static void F_120 ( struct V_266 * V_267 )
{
struct V_43 * V_44 = V_267 -> V_276 ;
struct V_22 * V_23 = F_39 ( V_44 ) ;
struct V_268 * V_46 = NULL ;
F_53 ( L_93 ) ;
if ( V_23 -> V_277 ) {
F_40 ( L_94 ) ;
F_27 ( ! V_23 -> V_278 ) ;
while ( ( V_46 = F_102 ( V_267 ) ) != NULL )
F_121 ( V_46 , - V_148 ) ;
return;
}
if ( V_23 -> V_46 )
return;
if ( ! V_23 -> V_278 )
F_82 ( V_23 -> V_219 , & V_23 -> V_220 ) ;
}
static int F_122 ( struct V_43 * V_44 )
{
struct V_22 * V_23 = F_39 ( V_44 ) ;
return ( V_23 -> V_277 == 0 ) ;
}
static void F_123 ( struct V_43 * V_44 )
{
struct V_22 * V_23 = F_39 ( V_44 ) ;
unsigned long V_164 ;
F_40 ( L_95 ) ;
F_100 ( & V_23 -> V_250 , V_164 ) ;
F_124 ( V_23 -> V_251 ) ;
V_23 -> V_278 = true ;
F_101 ( & V_23 -> V_250 , V_164 ) ;
F_84 ( & V_23 -> V_222 ) ;
F_125 ( V_23 -> V_219 ) ;
if ( V_23 -> V_46 ) {
F_100 ( & V_23 -> V_250 , V_164 ) ;
F_126 ( V_23 -> V_251 , V_23 -> V_46 ) ;
V_23 -> V_46 = NULL ;
F_101 ( & V_23 -> V_250 , V_164 ) ;
}
}
static void F_127 ( struct V_43 * V_44 )
{
struct V_22 * V_23 = F_39 ( V_44 ) ;
unsigned long V_164 ;
F_40 ( L_96 ) ;
F_23 ( V_23 ) ;
F_100 ( & V_23 -> V_250 , V_164 ) ;
if ( ! V_23 -> V_278 || V_23 -> V_277 ) {
F_101 ( & V_23 -> V_250 , V_164 ) ;
return;
}
F_101 ( & V_23 -> V_250 , V_164 ) ;
V_23 -> V_218 = true ;
V_23 -> V_278 = false ;
F_100 ( & V_23 -> V_250 , V_164 ) ;
F_128 ( V_23 -> V_251 ) ;
F_101 ( & V_23 -> V_250 , V_164 ) ;
F_82 ( V_23 -> V_219 , & V_23 -> V_220 ) ;
}
static int F_129 ( struct V_43 * V_44 )
{
struct V_22 * V_23 = F_39 ( V_44 ) ;
struct V_131 * V_52 = V_44 -> V_52 ;
int V_279 ;
T_8 V_280 = V_281 ;
unsigned long V_282 ;
if ( V_52 -> V_283 . V_284 && * ( V_52 -> V_283 . V_284 ) )
V_280 = * ( V_52 -> V_283 . V_284 ) ;
F_110 ( & V_260 ) ;
V_23 -> V_263 = F_130 ( & V_262 , V_44 , 0 , 256 , V_201 ) ;
F_111 ( & V_260 ) ;
if ( V_23 -> V_263 < 0 )
return V_23 -> V_263 ;
V_23 -> V_257 = F_131 ( 0 ) ;
if ( ! V_23 -> V_257 ) {
V_279 = - V_202 ;
goto V_285;
}
V_23 -> V_251 = F_132 ( F_120 , & V_23 -> V_250 ) ;
if ( ! V_23 -> V_251 ) {
V_279 = - V_202 ;
goto V_286;
}
V_23 -> V_251 -> V_276 = V_44 ;
F_133 ( V_23 -> V_251 , F_118 ) ;
F_134 ( V_23 -> V_251 , V_280 ) ;
F_135 ( V_23 -> V_251 , V_287 ) ;
F_136 ( V_23 -> V_251 , V_288 ) ;
F_137 ( V_23 -> V_251 ,
V_287 * V_23 -> V_102 ) ;
F_138 ( V_23 -> V_251 , V_23 -> V_102 ) ;
sprintf ( V_23 -> V_257 -> V_289 , L_97 , V_23 -> V_263 ) ;
V_23 -> V_257 -> V_290 = & V_291 ;
V_23 -> V_257 -> V_259 = V_23 ;
V_23 -> V_257 -> V_251 = V_23 -> V_251 ;
V_23 -> V_257 -> V_292 = & V_44 -> V_283 ;
V_23 -> V_257 -> V_164 |= V_293 ;
V_282 = V_23 -> V_116 * V_23 -> V_172 ;
V_282 *= ( V_23 -> V_102 / 512 ) ;
F_139 ( V_23 -> V_257 , V_282 ) ;
F_40 ( L_98 , V_282 ) ;
V_23 -> V_261 = 1 ;
V_23 -> V_219 = F_140 ( L_99 , V_294 ) ;
F_141 ( & V_23 -> V_220 , F_98 ) ;
F_41 ( V_23 -> V_249 , V_288 + 1 ) ;
if ( V_23 -> V_31 )
F_142 ( V_23 -> V_257 , 1 ) ;
F_127 ( V_44 ) ;
F_143 ( V_23 -> V_257 ) ;
F_40 ( L_100 ) ;
return 0 ;
V_286:
F_115 ( V_23 -> V_257 ) ;
V_285:
F_110 ( & V_260 ) ;
F_114 ( & V_262 , V_23 -> V_263 ) ;
F_111 ( & V_260 ) ;
return V_279 ;
}
static int F_144 ( struct V_43 * V_44 )
{
struct V_22 * V_23 ;
int V_279 = 0 ;
V_23 = F_77 ( sizeof( struct V_22 ) , V_201 ) ;
if ( ! V_23 )
return - V_202 ;
F_145 ( V_44 , V_23 ) ;
V_23 -> V_44 = V_44 ;
F_146 ( & V_23 -> V_250 ) ;
V_279 = F_95 ( V_44 ) ;
if ( V_279 )
goto V_295;
V_279 = F_129 ( V_44 ) ;
if ( ! V_279 ) {
V_44 -> V_296 = F_122 ;
V_44 -> V_297 = F_123 ;
V_44 -> V_298 = F_127 ;
return 0 ;
}
V_295:
F_145 ( V_44 , NULL ) ;
F_112 ( V_23 ) ;
F_78 ( V_23 ) ;
return V_279 ;
}
static void F_147 ( struct V_43 * V_44 )
{
struct V_22 * V_23 = F_39 ( V_44 ) ;
unsigned long V_164 ;
if ( ! V_23 -> V_278 )
F_123 ( V_44 ) ;
F_40 ( L_101 ) ;
F_100 ( & V_23 -> V_250 , V_164 ) ;
V_23 -> V_277 = true ;
F_128 ( V_23 -> V_251 ) ;
F_101 ( & V_23 -> V_250 , V_164 ) ;
F_148 ( V_23 -> V_257 ) ;
F_149 ( V_23 -> V_251 ) ;
V_23 -> V_251 = NULL ;
F_110 ( & V_260 ) ;
F_112 ( V_23 ) ;
F_111 ( & V_260 ) ;
F_113 ( V_23 -> V_257 ) ;
F_145 ( V_44 , NULL ) ;
}
static int F_150 ( struct V_43 * V_44 , T_9 V_47 )
{
F_123 ( V_44 ) ;
return 0 ;
}
static int F_151 ( struct V_43 * V_44 )
{
struct V_22 * V_23 = F_39 ( V_44 ) ;
struct V_22 * V_299 = NULL ;
bool V_277 = true ;
#ifndef F_152
V_23 -> V_277 = true ;
return 0 ;
#endif
F_110 ( & V_44 -> V_52 -> V_300 ) ;
V_299 = F_77 ( sizeof( struct V_22 ) , V_201 ) ;
if ( ! V_299 )
goto V_9;
V_299 -> V_44 = V_44 ;
F_145 ( V_44 , V_299 ) ;
F_146 ( & V_299 -> V_250 ) ;
F_41 ( V_23 -> V_249 , V_288 + 1 ) ;
if ( F_95 ( V_44 ) )
goto V_9;
if ( V_23 -> V_170 != V_299 -> V_170 )
goto V_9;
if ( memcmp ( V_23 -> V_200 , V_299 -> V_200 ,
sizeof( struct V_181 ) ) )
goto V_9;
if ( V_23 -> V_172 != V_299 -> V_172 ||
memcmp ( V_23 -> V_179 , V_299 -> V_179 ,
V_23 -> V_172 ) )
goto V_9;
if ( V_23 -> V_29 != V_299 -> V_29 ||
memcmp ( V_23 -> V_30 , V_299 -> V_30 ,
V_23 -> V_29 / 8 ) )
goto V_9;
V_277 = false ;
V_9:
if ( V_277 )
F_40 ( L_102 ) ;
V_23 -> V_277 = V_277 ;
F_145 ( V_44 , V_23 ) ;
if ( V_299 ) {
F_112 ( V_299 ) ;
F_78 ( V_299 ) ;
}
F_127 ( V_44 ) ;
F_111 ( & V_44 -> V_52 -> V_300 ) ;
return 0 ;
}
static int T_10 F_153 ( void )
{
int V_279 = F_154 ( 0 , V_301 ) ;
if ( V_279 < 0 ) {
F_17 ( L_103 , V_279 ) ;
return V_279 ;
}
V_302 = V_279 ;
V_279 = F_155 ( & V_303 ) ;
if ( V_279 ) {
F_156 ( V_302 , V_301 ) ;
F_17 ( L_104 , V_279 ) ;
}
return V_279 ;
}
static void T_11 F_157 ( void )
{
F_158 ( & V_303 ) ;
F_156 ( V_302 , V_301 ) ;
F_159 ( & V_262 ) ;
}
