static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 =
V_2 -> V_4 +
1000 /
( 8 * V_5 ) * V_6 ;
if ( V_3 < V_7 )
V_3 = V_7 ;
if ( V_3 > V_8 )
V_3 = V_8 ;
V_3 = F_2 ( V_3 ) ;
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 =
V_2 -> V_4 *
1000 /
( 8 * V_5 ) * V_9 ;
if ( V_3 >= V_2 -> V_10 . V_3 )
V_3 = V_2 -> V_10 . V_3 - 1 ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_10 . V_16 ; V_15 ++ ) {
V_12 = V_2 -> V_10 . V_17 [ V_15 ] ;
V_14 = F_5 ( V_12 ) ;
F_6 ( V_2 -> V_18 -> V_19 , V_14 -> V_20 ,
V_12 -> V_21 + F_7 ( V_12 ) ,
V_22 ) ;
F_8 ( V_12 ) ;
}
V_2 -> V_10 . V_16 = 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_23 )
{
struct V_24 * V_25 ;
struct V_11 * V_12 ;
T_1 V_20 ;
int V_26 = 0 , V_27 ;
V_27 = F_10 ( * ( V_2 -> V_10 . V_28 . V_29 ) ) ;
while ( V_23 > 0 ) {
V_12 = F_11 ( V_30 + V_31 ) ;
if ( ! V_12 ) {
V_26 = - V_32 ;
goto V_33;
}
if ( ! F_12 ( ( unsigned long ) V_12 -> V_34 , V_31 ) )
F_13 ( V_12 ,
F_14 ( V_12 -> V_34 , V_31 ) -
V_12 -> V_34 ) ;
V_25 = (struct V_24 * ) V_12 -> V_34 ;
V_25 -> V_35 . V_36 = F_15 ( 0 ) ;
V_20 = F_16 ( V_2 -> V_18 -> V_19 , V_12 -> V_34 ,
V_12 -> V_21 + F_7 ( V_12 ) ,
V_22 ) ;
if ( F_17 ( F_18 ( V_2 -> V_18 -> V_19 , V_20 ) ) ) {
F_8 ( V_12 ) ;
V_26 = - V_32 ;
goto V_33;
}
F_5 ( V_12 ) -> V_20 = V_20 ;
V_2 -> V_10 . V_17 [ V_27 ] = V_12 ;
V_2 -> V_10 . V_37 [ V_27 ] = F_15 ( V_20 ) ;
V_2 -> V_10 . V_16 ++ ;
V_23 -- ;
V_27 ++ ;
V_27 &= V_2 -> V_10 . V_38 ;
}
V_33:
* ( V_2 -> V_10 . V_28 . V_29 ) = F_15 ( V_27 ) ;
return V_26 ;
}
static int F_19 ( struct V_1 * V_2 , int V_23 )
{
F_20 ( & V_2 -> V_10 . V_39 ) ;
return F_9 ( V_2 , V_23 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
int V_26 , V_40 , V_41 ;
F_22 ( & V_2 -> V_10 . V_39 ) ;
V_40 = V_2 -> V_10 . V_42 - V_2 -> V_10 . V_16 ;
V_41 = F_23 ( V_43 , V_40 ) ;
V_40 -= V_41 ;
V_26 = F_19 ( V_2 , V_41 ) ;
if ( V_26 == - V_32 ) {
F_24 ( & V_2 -> V_10 . V_44 , V_45 +
F_25 ( V_46 ) ) ;
} else if ( V_40 > 0 ) {
F_26 ( & V_2 -> V_47 ) ;
}
F_27 ( & V_2 -> V_10 . V_39 ) ;
}
static void F_28 ( unsigned long V_48 )
{
struct V_1 * V_2 = (struct V_1 * ) V_48 ;
F_21 ( V_2 ) ;
}
static unsigned F_29 ( struct V_1 * V_2 )
{
return ( F_10 ( * V_2 -> V_10 . V_28 . V_29 ) -
V_2 -> V_10 . V_49 . V_50 ) & V_2 -> V_10 . V_38 ;
}
void F_30 ( struct V_1 * V_2 )
{
int V_49 = V_2 -> V_10 . V_49 . V_50 ;
F_31 ( & V_2 -> V_10 . V_44 ) ;
F_32 ( & V_2 -> V_47 ) ;
while ( V_49 != F_10 ( * ( V_2 -> V_10 . V_28 . V_29 ) ) ) {
struct V_11 * V_12 =
V_2 -> V_10 . V_17 [ V_49 ] ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
F_6 ( V_2 -> V_18 -> V_19 , V_14 -> V_20 ,
V_12 -> V_21 + F_7 ( V_12 ) ,
V_22 ) ;
F_8 ( V_2 -> V_10 . V_17 [ V_49 ] ) ;
V_49 ++ ;
V_49 &= V_2 -> V_10 . V_38 ;
}
F_33 ( V_2 -> V_18 -> V_19 ,
( V_2 -> V_10 . V_3 *
sizeof( V_2 -> V_10 . V_37 ) ) ,
V_2 -> V_10 . V_37 ,
V_2 -> V_10 . V_51 ) ;
F_33 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
V_2 -> V_10 . V_28 . V_29 ,
V_2 -> V_10 . V_28 . V_20 ) ;
F_34 ( V_2 -> V_10 . V_17 ) ;
}
static inline struct V_11 * F_35 ( struct V_1 * V_2 )
{
int V_27 ;
struct V_11 * V_52 ;
F_22 ( & V_2 -> V_10 . V_39 ) ;
if ( F_29 ( V_2 ) == 0 )
F_36 ( L_1 ) ;
V_27 = V_2 -> V_10 . V_49 . V_50 ;
V_52 = V_2 -> V_10 . V_17 [ V_27 ] ;
V_27 ++ ;
V_27 &= V_2 -> V_10 . V_38 ;
V_2 -> V_10 . V_49 . V_50 = V_27 ;
V_2 -> V_10 . V_16 -- ;
F_27 ( & V_2 -> V_10 . V_39 ) ;
return V_52 ;
}
static void F_37 ( struct V_11 * V_12 )
{
struct V_11 * V_53 ;
while ( V_12 ) {
V_53 = V_12 -> V_53 ;
F_8 ( V_12 ) ;
V_12 = V_53 ;
}
}
static int F_38 ( struct V_1 * V_2 ,
T_2 * * V_54 , int * V_55 ,
struct V_11 * * V_56 ,
struct V_11 * * V_57 )
{
int V_58 , V_59 = 0 ;
struct V_11 * V_52 ;
struct V_24 * V_25 ;
if ( F_29 ( V_2 ) == 0 )
F_36 ( L_1 ) ;
if ( V_2 -> V_60 ) {
F_36 ( L_2 ) ;
return 0 ;
}
V_52 = * V_56 = F_35 ( V_2 ) ;
while ( V_52 ) {
int V_61 , V_62 , V_63 ;
F_6 ( V_2 -> V_18 -> V_19 ,
F_5 ( V_52 ) -> V_20 ,
V_52 -> V_21 + F_7 ( V_52 ) ,
V_22 ) ;
F_39 ( V_64 , NULL , L_3 ,
V_52 -> V_34 , V_52 -> V_21 + F_7 ( V_52 ) ) ;
V_25 = (struct V_24 * ) V_52 -> V_34 ;
F_40 ( V_52 , F_41 ( struct V_24 , V_65 ) ) ;
F_13 ( V_52 , F_41 ( struct V_24 , V_65 ) ) ;
if ( ! ( F_10 ( V_25 -> V_35 . V_36 )
& V_66 ) ) {
F_37 ( * V_56 ) ;
* V_56 = NULL ;
V_52 = NULL ;
F_42 ( L_4 ) ;
V_2 -> V_60 = true ;
break;
}
if ( * V_55 > 0 ) {
V_25 -> V_54 . V_67 = * * V_54 ;
( * V_54 ) ++ ;
( * V_55 ) -- ;
} else {
V_25 -> V_54 . V_67 = 0 ;
}
V_62 = ! ! ( F_10 ( V_25 -> V_35 . V_36 )
& ( V_68 |
V_69 ) ) ;
V_58 = F_43 ( F_10 ( V_25 -> V_70 . V_67 ) ,
V_71 ) ;
V_63 = V_25 -> V_72 . V_73 ;
if ( V_62 )
V_58 = 0 ;
F_44 ( V_52 , 0 ) ;
F_40 ( V_52 , F_23 ( V_58 , V_74 ) ) ;
V_58 -= V_52 -> V_21 ;
while ( V_63 -- ) {
struct V_11 * V_53 = F_35 ( V_2 ) ;
F_6 ( V_2 -> V_18 -> V_19 ,
F_5 ( V_53 ) -> V_20 ,
V_53 -> V_21 + F_7 ( V_53 ) ,
V_22 ) ;
F_39 ( V_64 , NULL , L_3 ,
V_53 -> V_34 ,
V_53 -> V_21 + F_7 ( V_53 ) ) ;
F_44 ( V_53 , 0 ) ;
F_40 ( V_53 , F_23 ( V_58 , V_30 ) ) ;
V_58 -= V_53 -> V_21 ;
V_52 -> V_53 = V_53 ;
V_52 = V_53 ;
V_59 = 1 ;
}
if ( V_58 > 0 ) {
F_36 ( L_5 ,
V_58 ) ;
}
V_61 = F_10 ( V_25 -> V_75 . V_67 ) &
V_76 ;
if ( V_61 ) {
V_52 -> V_53 = NULL ;
break;
} else {
struct V_11 * V_53 = F_35 ( V_2 ) ;
V_52 -> V_53 = V_53 ;
V_52 = V_53 ;
}
}
* V_57 = V_52 ;
return V_59 ;
}
static void F_45 ( unsigned long V_77 )
{
struct V_1 * V_2 = (struct V_1 * ) V_77 ;
F_21 ( V_2 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
T_1 V_20 ;
void * V_29 ;
struct V_78 * V_79 = & V_2 -> V_10 . V_44 ;
V_2 -> V_10 . V_3 = F_1 ( V_2 ) ;
if ( ! F_47 ( V_2 -> V_10 . V_3 ) ) {
F_36 ( L_6 ) ;
return - V_80 ;
}
V_2 -> V_10 . V_38 = V_2 -> V_10 . V_3 - 1 ;
V_2 -> V_10 . V_42 = F_3 ( V_2 ) ;
V_2 -> V_10 . V_17 =
F_48 ( V_2 -> V_10 . V_3 * sizeof( struct V_11 * ) ,
V_81 ) ;
if ( ! V_2 -> V_10 . V_17 )
goto V_82;
V_29 = F_49 ( V_2 -> V_18 -> V_19 ,
( V_2 -> V_10 . V_3 * sizeof( V_2 -> V_10 . V_37 ) ) ,
& V_20 , V_83 ) ;
if ( ! V_29 )
goto V_84;
V_2 -> V_10 . V_37 = V_29 ;
V_2 -> V_10 . V_51 = V_20 ;
V_29 = F_49 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
& V_20 , V_83 ) ;
if ( ! V_29 )
goto V_85;
V_2 -> V_10 . V_28 . V_29 = V_29 ;
V_2 -> V_10 . V_28 . V_20 = V_20 ;
V_2 -> V_10 . V_49 . V_50 = 0 ;
* V_2 -> V_10 . V_28 . V_29 = 0 ;
F_50 ( V_79 , F_28 , ( unsigned long ) V_2 ) ;
F_51 ( & V_2 -> V_10 . V_39 ) ;
V_2 -> V_10 . V_16 = 0 ;
if ( F_9 ( V_2 , V_2 -> V_10 . V_42 ) )
goto V_86;
F_52 ( & V_2 -> V_47 , F_45 ,
( unsigned long ) V_2 ) ;
F_53 ( V_87 , L_7 ,
V_2 -> V_10 . V_3 , V_2 -> V_10 . V_42 ) ;
return 0 ;
V_86:
F_4 ( V_2 ) ;
F_33 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
V_2 -> V_10 . V_28 . V_29 ,
V_2 -> V_10 . V_28 . V_20 ) ;
V_85:
F_33 ( V_2 -> V_18 -> V_19 ,
( V_2 -> V_10 . V_3 *
sizeof( V_2 -> V_10 . V_37 ) ) ,
V_2 -> V_10 . V_37 ,
V_2 -> V_10 . V_51 ) ;
V_84:
F_34 ( V_2 -> V_10 . V_17 ) ;
V_82:
return - V_32 ;
}
static int F_54 ( enum V_88 type )
{
switch ( type ) {
case V_89 :
case V_90 :
return 4 ;
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
return 8 ;
case V_96 :
return 0 ;
}
F_36 ( L_8 , type ) ;
return 0 ;
}
static int F_55 ( enum V_88 type )
{
switch ( type ) {
case V_96 :
case V_89 :
case V_90 :
case V_92 :
case V_94 :
return 0 ;
case V_91 :
case V_93 :
return 4 ;
case V_95 :
return 8 ;
}
F_36 ( L_8 , type ) ;
return 0 ;
}
static struct V_97 * F_56 ( struct V_11 * V_12 )
{
struct V_24 * V_98 ;
enum V_99 V_100 ;
V_98 = ( void * ) V_12 -> V_34 - sizeof( * V_98 ) ;
V_100 = F_43 ( F_10 ( V_98 -> V_70 . V_101 ) ,
V_102 ) ;
if ( V_100 == V_103 )
return ( void * ) V_12 -> V_34 ;
else
return ( void * ) V_12 -> V_34 - V_104 ;
}
static bool F_57 ( struct V_97 * V_105 )
{
if ( F_58 ( V_105 -> V_106 ) ) {
T_2 * V_107 = F_59 ( V_105 ) ;
if ( V_107 [ 0 ] & 0x80 )
return true ;
}
return false ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_108 * V_109 )
{
struct V_24 * V_98 ;
struct V_11 * V_110 ;
struct V_11 * V_12 = V_109 -> V_12 ;
enum V_99 V_100 ;
enum V_88 V_111 ;
struct V_97 * V_105 ;
T_2 V_112 [ 64 ] , V_113 [ V_114 ] , * V_115 ;
unsigned int V_116 ;
V_98 = ( void * ) V_12 -> V_34 - sizeof( * V_98 ) ;
V_111 = F_43 ( F_10 ( V_98 -> V_117 . V_67 ) ,
V_118 ) ;
V_105 = (struct V_97 * ) V_98 -> V_119 ;
V_116 = F_61 ( V_105 -> V_106 ) ;
memcpy ( V_112 , V_105 , V_116 ) ;
V_105 = (struct V_97 * ) V_112 ;
V_110 = V_12 ;
while ( V_12 ) {
void * V_120 ;
int V_21 ;
V_98 = ( void * ) V_12 -> V_34 - sizeof( * V_98 ) ;
V_100 = F_43 ( F_10 ( V_98 -> V_70 . V_101 ) ,
V_102 ) ;
V_120 = ( void * ) V_98 -> V_119 ;
V_12 -> V_121 = F_62 ( V_12 ) ;
if ( V_12 == V_110 ) {
V_21 = F_63 ( F_61 ( V_105 -> V_106 ) , 4 ) ;
V_21 += F_63 ( F_54 ( V_111 ) ,
4 ) ;
V_120 += V_21 ;
}
switch ( V_100 ) {
case V_103 :
F_44 ( V_12 , V_12 -> V_21 - V_122 ) ;
break;
case V_123 :
V_105 = (struct V_97 * ) V_12 -> V_34 ;
V_116 = F_61 ( V_105 -> V_106 ) ;
memcpy ( V_113 , F_64 ( V_105 ) , V_114 ) ;
F_13 ( V_12 , V_116 ) ;
V_105 = (struct V_97 * ) V_112 ;
V_116 = F_61 ( V_105 -> V_106 ) ;
memcpy ( F_65 ( V_12 , V_116 ) , V_105 , V_116 ) ;
V_105 = (struct V_97 * ) V_12 -> V_34 ;
V_115 = F_59 ( V_105 ) ;
V_115 [ 0 ] &= ~ V_124 ;
memcpy ( F_64 ( V_105 ) , V_113 , V_114 ) ;
break;
case V_125 :
V_21 = 0 ;
V_21 += sizeof( struct V_126 ) ;
V_21 += sizeof( struct V_127 ) ;
F_13 ( V_12 , sizeof( struct V_128 ) ) ;
memcpy ( F_65 ( V_12 , V_21 ) , V_120 , V_21 ) ;
memcpy ( F_65 ( V_12 , V_116 ) , V_105 , V_116 ) ;
break;
case V_129 :
memcpy ( F_65 ( V_12 , V_116 ) , V_105 , V_116 ) ;
break;
}
V_109 -> V_12 = V_12 ;
V_109 -> V_130 = V_111 ;
V_12 = V_12 -> V_53 ;
V_109 -> V_12 -> V_53 = NULL ;
if ( V_12 )
V_109 -> V_131 = true ;
F_66 ( V_2 -> V_18 , V_109 ) ;
}
}
static void F_67 ( struct V_1 * V_2 , struct V_108 * V_109 )
{
struct V_11 * V_12 = V_109 -> V_12 ;
struct V_24 * V_98 ;
struct V_97 * V_105 ;
enum V_99 V_100 ;
enum V_88 V_111 ;
int V_116 ;
void * V_132 ;
if ( V_12 -> V_53 ) {
F_36 ( L_9 ) ;
F_37 ( V_12 -> V_53 ) ;
V_12 -> V_53 = NULL ;
}
V_98 = ( void * ) V_12 -> V_34 - sizeof( * V_98 ) ;
V_100 = F_43 ( F_10 ( V_98 -> V_70 . V_101 ) ,
V_102 ) ;
V_111 = F_43 ( F_10 ( V_98 -> V_117 . V_67 ) ,
V_118 ) ;
V_105 = (struct V_97 * ) V_98 -> V_119 ;
V_116 = F_61 ( V_105 -> V_106 ) ;
V_12 -> V_121 = F_62 ( V_12 ) ;
switch ( V_100 ) {
case V_103 :
F_44 ( V_12 , V_12 -> V_21 - V_122 ) ;
break;
case V_123 :
V_105 = (struct V_97 * ) V_12 -> V_34 ;
V_116 = F_61 ( V_105 -> V_106 ) ;
F_13 ( V_12 , V_116 ) ;
V_105 = (struct V_97 * ) V_98 -> V_119 ;
V_116 = F_61 ( V_105 -> V_106 ) ;
memcpy ( F_65 ( V_12 , V_116 ) , V_105 , V_116 ) ;
break;
case V_125 :
V_132 = V_105 ;
V_132 += F_68 ( V_116 , 4 ) ;
V_132 += F_68 ( F_54 ( V_111 ) , 4 ) ;
F_13 ( V_12 , sizeof( struct V_128 ) ) ;
memcpy ( F_65 ( V_12 , sizeof( struct V_126 ) ) ,
V_132 , sizeof( struct V_126 ) ) ;
memcpy ( F_65 ( V_12 , V_116 ) , V_105 , V_116 ) ;
break;
case V_129 :
F_13 ( V_12 , sizeof( struct V_127 ) ) ;
memcpy ( F_65 ( V_12 , V_116 ) , V_105 , V_116 ) ;
break;
}
V_109 -> V_12 = V_12 ;
V_109 -> V_130 = V_111 ;
F_66 ( V_2 -> V_18 , V_109 ) ;
}
static bool F_69 ( struct V_11 * V_12 )
{
struct V_24 * V_98 ;
T_3 V_36 ;
V_98 = ( void * ) V_12 -> V_34 - sizeof( * V_98 ) ;
V_36 = F_10 ( V_98 -> V_35 . V_36 ) ;
if ( V_36 & V_133 )
return true ;
return false ;
}
static bool F_70 ( struct V_11 * V_12 )
{
struct V_24 * V_98 ;
T_3 V_36 ;
V_98 = ( void * ) V_12 -> V_34 - sizeof( * V_98 ) ;
V_36 = F_10 ( V_98 -> V_35 . V_36 ) ;
if ( V_36 & V_134 )
return true ;
return false ;
}
static bool F_71 ( struct V_11 * V_12 )
{
struct V_24 * V_98 ;
T_3 V_36 ;
V_98 = ( void * ) V_12 -> V_34 - sizeof( * V_98 ) ;
V_36 = F_10 ( V_98 -> V_35 . V_36 ) ;
if ( V_36 & V_135 )
return true ;
return false ;
}
static int F_62 ( struct V_11 * V_12 )
{
struct V_24 * V_98 ;
T_3 V_36 , V_109 ;
bool V_136 , V_137 ;
bool V_138 , V_139 ;
bool V_140 , V_141 ;
V_98 = ( void * ) V_12 -> V_34 - sizeof( * V_98 ) ;
V_36 = F_10 ( V_98 -> V_35 . V_36 ) ;
V_109 = F_10 ( V_98 -> V_70 . V_101 ) ;
V_136 = ! ! ( V_109 & V_142 ) ;
V_137 = ! ! ( V_109 & V_143 ) ;
V_138 = ! ! ( V_109 & V_144 ) ;
V_139 = ! ! ( V_109 & V_145 ) ;
V_140 = ! ( V_36 & V_146 ) ;
V_141 = ! ( V_36 & V_147 ) ;
if ( ! V_136 && ! V_137 )
return V_148 ;
if ( ! V_138 && ! V_139 )
return V_148 ;
if ( ! V_140 )
return V_148 ;
if ( ! V_141 )
return V_148 ;
return V_149 ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_150 * V_151 )
{
struct V_108 V_109 ;
struct V_152 * V_153 ;
struct V_97 * V_105 ;
int V_154 ;
int V_55 ;
T_2 * V_54 ;
int V_15 , V_155 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_55 = F_73 ( V_151 -> V_156 . V_157 ) ;
V_54 = ( T_2 * ) & V_151 -> V_54 ;
V_154 = F_43 ( F_10 ( V_151 -> V_105 . V_101 ) ,
V_158 ) ;
V_153 = F_74 ( V_151 ) ;
F_39 ( V_64 , NULL , L_10 ,
V_151 , sizeof( * V_151 ) +
( sizeof( struct V_152 ) *
V_154 ) ) ;
for ( V_15 = 0 ; V_15 < V_154 ; V_15 ++ ) {
V_109 . V_159 = V_153 [ V_15 ] . V_160 ;
for ( V_155 = 0 ; V_155 < V_153 [ V_15 ] . V_161 ; V_155 ++ ) {
struct V_11 * V_162 , * V_163 ;
enum V_164 V_159 ;
int V_59 ;
V_162 = NULL ;
V_163 = NULL ;
V_59 = F_38 ( V_2 ,
& V_54 ,
& V_55 ,
& V_162 ,
& V_163 ) ;
if ( ! V_162 ) {
F_36 ( L_11 ) ;
continue;
}
if ( V_162 -> V_21 == 0 ) {
F_53 ( V_165 ,
L_12 ) ;
F_37 ( V_162 ) ;
continue;
}
if ( F_69 ( V_162 ) ) {
F_37 ( V_162 ) ;
continue;
}
V_159 = V_109 . V_159 ;
if ( V_159 == V_166 ) {
F_37 ( V_162 ) ;
continue;
}
if ( V_159 != V_167 &&
V_159 != V_168 &&
! V_2 -> V_18 -> V_169 ) {
F_53 ( V_165 ,
L_13 ,
V_159 ) ;
F_37 ( V_162 ) ;
continue;
}
if ( F_75 ( V_170 , & V_2 -> V_18 -> V_171 ) ) {
F_37 ( V_162 ) ;
continue;
}
if ( V_59 ) {
F_36 ( L_14 ) ;
F_37 ( V_162 ) ;
continue;
}
V_109 . V_12 = V_162 ;
V_109 . V_172 = F_70 ( V_162 ) ;
V_109 . V_173 = F_71 ( V_162 ) ;
V_109 . signal = V_174 ;
V_109 . signal += V_151 -> V_175 . V_176 ;
V_109 . V_177 . V_67 = V_151 -> V_175 . V_67 ;
V_109 . V_177 . V_101 = F_10 ( V_151 -> V_175 . V_101 ) ;
V_109 . V_177 . V_178 = F_10 ( V_151 -> V_175 . V_178 ) ;
V_105 = F_56 ( V_162 ) ;
if ( F_57 ( V_105 ) )
F_60 ( V_2 , & V_109 ) ;
else
F_67 ( V_2 , & V_109 ) ;
}
}
F_26 ( & V_2 -> V_47 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_179 * V_180 )
{
struct V_11 * V_162 , * V_163 ;
struct V_24 * V_98 ;
enum V_99 V_100 ;
struct V_108 V_109 = {} ;
struct V_97 * V_105 ;
int V_59 ;
bool V_181 ;
bool V_182 ;
T_2 * V_54 ;
int V_55 , V_183 , V_184 ;
int V_185 ;
V_55 = F_73 ( V_180 -> V_157 ) ;
V_54 = ( T_2 * ) V_180 -> V_186 ;
V_162 = NULL ;
V_163 = NULL ;
V_59 = F_38 ( V_2 , & V_54 , & V_55 ,
& V_162 , & V_163 ) ;
F_53 ( V_64 , L_15 ) ;
if ( ! V_162 ) {
F_36 ( L_16 ) ;
return;
}
if ( V_59 || V_162 != V_163 ) {
F_36 ( L_17 ) ;
F_37 ( V_162 ) ;
return;
}
V_105 = (struct V_97 * ) V_162 -> V_34 ;
V_98 = ( void * ) V_162 -> V_34 - sizeof( * V_98 ) ;
V_181 = ! ! ( F_10 ( V_98 -> V_35 . V_36 ) &
V_135 ) ;
V_182 = ! ! ( F_10 ( V_98 -> V_35 . V_36 ) &
V_133 ) ;
V_100 = F_43 ( F_10 ( V_98 -> V_70 . V_101 ) ,
V_102 ) ;
if ( V_100 != V_103 ) {
F_36 ( L_18 ) ;
F_8 ( V_162 ) ;
goto V_187;
}
V_109 . V_12 = V_162 ;
V_109 . V_159 = V_167 ;
V_109 . V_130 = F_43 ( F_10 ( V_98 -> V_117 . V_67 ) ,
V_118 ) ;
V_109 . V_12 -> V_121 = F_62 ( V_109 . V_12 ) ;
if ( V_181 ) {
F_36 ( L_19 ) ;
V_109 . V_159 = V_168 ;
}
if ( V_182 ) {
F_36 ( L_20 ) ;
F_8 ( V_109 . V_12 ) ;
goto V_187;
}
if ( V_109 . V_130 != V_96 ) {
V_183 = F_61 ( V_105 -> V_106 ) ;
V_184 = F_54 ( V_109 . V_130 ) ;
memmove ( ( void * ) V_109 . V_12 -> V_34 + V_184 ,
( void * ) V_109 . V_12 -> V_34 ,
V_183 ) ;
F_13 ( V_109 . V_12 , V_184 ) ;
V_105 = (struct V_97 * ) V_109 . V_12 -> V_34 ;
}
V_185 = 4 ;
V_185 += F_55 ( V_109 . V_130 ) ;
if ( ! F_77 ( V_105 -> V_106 ) &&
V_109 . V_130 == V_93 )
V_185 += 8 ;
if ( V_185 > V_109 . V_12 -> V_21 ) {
F_36 ( L_21 ) ;
F_8 ( V_109 . V_12 ) ;
goto V_187;
}
F_44 ( V_109 . V_12 , V_109 . V_12 -> V_21 - V_185 ) ;
F_39 ( V_64 , NULL , L_22 ,
V_109 . V_12 -> V_34 , V_109 . V_12 -> V_21 ) ;
F_66 ( V_2 -> V_18 , & V_109 ) ;
V_187:
if ( V_55 > 0 ) {
F_53 ( V_165 ,
L_23 ,
V_55 ) ;
}
}
void F_78 ( struct V_188 * V_18 , struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_18 -> V_2 ;
struct V_189 * V_190 = (struct V_189 * ) V_12 -> V_34 ;
if ( ! F_12 ( ( unsigned long ) V_12 -> V_34 , 4 ) )
F_36 ( L_24 ) ;
F_53 ( V_165 , L_25 ,
V_190 -> V_105 . V_191 ) ;
switch ( V_190 -> V_105 . V_191 ) {
case V_192 : {
V_2 -> V_193 = V_190 -> V_194 . V_195 ;
V_2 -> V_196 = V_190 -> V_194 . V_197 ;
F_79 ( & V_2 -> V_198 ) ;
break;
}
case V_199 : {
F_72 ( V_2 , & V_190 -> V_200 ) ;
break;
}
case V_201 : {
struct V_202 V_203 = {
. V_204 = V_190 -> V_205 . V_204 ,
. V_206 = F_73 ( V_190 -> V_205 . V_206 ) ,
} ;
memcpy ( V_203 . V_113 , V_190 -> V_205 . V_113 , sizeof( V_203 . V_113 ) ) ;
F_80 ( V_2 , & V_203 ) ;
break;
}
case V_207 : {
struct V_208 V_203 = {
. V_206 = F_73 ( V_190 -> V_209 . V_206 ) ,
} ;
F_81 ( V_2 , & V_203 ) ;
break;
}
case V_210 : {
struct V_211 V_212 = {} ;
int V_159 = F_10 ( V_190 -> V_213 . V_159 ) ;
V_212 . V_214 =
F_10 ( V_190 -> V_213 . V_215 ) ;
switch ( V_159 ) {
case V_216 :
break;
case V_217 :
V_212 . V_218 = true ;
break;
case V_219 :
V_212 . V_220 = true ;
break;
}
F_82 ( V_2 , & V_212 ) ;
break;
}
case V_221 : {
struct V_211 V_212 = {} ;
int V_159 = F_43 ( V_190 -> V_222 . V_36 ,
V_223 ) ;
T_4 V_214 ;
int V_15 ;
switch ( V_159 ) {
case V_224 :
V_212 . V_218 = true ;
break;
case V_225 :
break;
case V_226 :
case V_227 :
case V_228 :
V_212 . V_220 = true ;
break;
default:
F_36 ( L_26 ,
V_159 ) ;
V_212 . V_220 = true ;
break;
}
F_53 ( V_165 , L_27 ,
V_190 -> V_222 . V_229 ) ;
for ( V_15 = 0 ; V_15 < V_190 -> V_222 . V_229 ; V_15 ++ ) {
V_214 = V_190 -> V_222 . V_230 [ V_15 ] ;
V_212 . V_214 = F_73 ( V_214 ) ;
F_82 ( V_2 , & V_212 ) ;
}
break;
}
case V_231 : {
struct V_188 * V_18 = V_2 -> V_18 ;
struct V_232 * V_203 = & V_190 -> V_233 ;
F_53 ( V_165 ,
L_28 ,
F_73 ( V_203 -> V_206 ) ,
! ! ( V_203 -> V_36 & V_234 ) ,
F_43 ( V_203 -> V_36 , V_235 ) ) ;
F_79 ( & V_18 -> V_236 ) ;
break;
}
case V_237 : {
F_39 ( V_64 , NULL , L_29 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
F_76 ( V_2 , & V_190 -> V_238 ) ;
break;
}
case V_239 :
break;
case V_240 :
F_83 ( V_12 -> V_34 , V_12 -> V_21 ) ;
break;
case V_241 :
case V_242 :
case V_243 :
case V_244 :
default:
F_53 ( V_165 , L_30 ,
V_190 -> V_105 . V_191 ) ;
F_39 ( V_64 , NULL , L_29 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
break;
} ;
F_8 ( V_12 ) ;
}
