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
V_105 -> V_106 &= F_62 ( ~ V_120 ) ;
V_110 = V_12 ;
while ( V_12 ) {
void * V_121 ;
int V_21 ;
V_98 = ( void * ) V_12 -> V_34 - sizeof( * V_98 ) ;
V_100 = F_43 ( F_10 ( V_98 -> V_70 . V_101 ) ,
V_102 ) ;
V_121 = ( void * ) V_98 -> V_119 ;
V_12 -> V_122 = F_63 ( V_12 ) ;
if ( V_12 == V_110 ) {
V_21 = F_64 ( F_61 ( V_105 -> V_106 ) , 4 ) ;
V_21 += F_64 ( F_54 ( V_111 ) ,
4 ) ;
V_121 += V_21 ;
}
switch ( V_100 ) {
case V_103 :
F_44 ( V_12 , V_12 -> V_21 - V_123 ) ;
break;
case V_124 :
V_105 = (struct V_97 * ) V_12 -> V_34 ;
V_116 = F_61 ( V_105 -> V_106 ) ;
memcpy ( V_113 , F_65 ( V_105 ) , V_114 ) ;
F_13 ( V_12 , V_116 ) ;
V_105 = (struct V_97 * ) V_112 ;
V_116 = F_61 ( V_105 -> V_106 ) ;
memcpy ( F_66 ( V_12 , V_116 ) , V_105 , V_116 ) ;
V_105 = (struct V_97 * ) V_12 -> V_34 ;
V_115 = F_59 ( V_105 ) ;
V_115 [ 0 ] &= ~ V_125 ;
memcpy ( F_65 ( V_105 ) , V_113 , V_114 ) ;
break;
case V_126 :
V_21 = 0 ;
V_21 += sizeof( struct V_127 ) ;
V_21 += sizeof( struct V_128 ) ;
F_13 ( V_12 , sizeof( struct V_129 ) ) ;
memcpy ( F_66 ( V_12 , V_21 ) , V_121 , V_21 ) ;
memcpy ( F_66 ( V_12 , V_116 ) , V_105 , V_116 ) ;
break;
case V_130 :
memcpy ( F_66 ( V_12 , V_116 ) , V_105 , V_116 ) ;
break;
}
V_109 -> V_12 = V_12 ;
V_109 -> V_131 = V_111 ;
V_12 = V_12 -> V_53 ;
V_109 -> V_12 -> V_53 = NULL ;
F_67 ( V_2 -> V_18 , V_109 ) ;
}
}
static void F_68 ( struct V_1 * V_2 , struct V_108 * V_109 )
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
V_12 -> V_122 = F_63 ( V_12 ) ;
switch ( V_100 ) {
case V_103 :
F_44 ( V_12 , V_12 -> V_21 - V_123 ) ;
break;
case V_124 :
V_105 = (struct V_97 * ) V_12 -> V_34 ;
V_116 = F_61 ( V_105 -> V_106 ) ;
F_13 ( V_12 , V_116 ) ;
V_105 = (struct V_97 * ) V_98 -> V_119 ;
V_116 = F_61 ( V_105 -> V_106 ) ;
memcpy ( F_66 ( V_12 , V_116 ) , V_105 , V_116 ) ;
break;
case V_126 :
V_132 = V_105 ;
V_132 += F_69 ( V_116 , 4 ) ;
V_132 += F_69 ( F_54 ( V_111 ) , 4 ) ;
F_13 ( V_12 , sizeof( struct V_129 ) ) ;
memcpy ( F_66 ( V_12 , sizeof( struct V_127 ) ) ,
V_132 , sizeof( struct V_127 ) ) ;
memcpy ( F_66 ( V_12 , V_116 ) , V_105 , V_116 ) ;
break;
case V_130 :
F_13 ( V_12 , sizeof( struct V_128 ) ) ;
memcpy ( F_66 ( V_12 , V_116 ) , V_105 , V_116 ) ;
break;
}
V_109 -> V_12 = V_12 ;
V_109 -> V_131 = V_111 ;
F_67 ( V_2 -> V_18 , V_109 ) ;
}
static bool F_70 ( struct V_11 * V_12 )
{
struct V_24 * V_98 ;
T_3 V_36 ;
V_98 = ( void * ) V_12 -> V_34 - sizeof( * V_98 ) ;
V_36 = F_10 ( V_98 -> V_35 . V_36 ) ;
if ( V_36 & V_133 )
return true ;
return false ;
}
static bool F_71 ( struct V_11 * V_12 )
{
struct V_24 * V_98 ;
T_3 V_36 ;
V_98 = ( void * ) V_12 -> V_34 - sizeof( * V_98 ) ;
V_36 = F_10 ( V_98 -> V_35 . V_36 ) ;
if ( V_36 & V_134 )
return true ;
return false ;
}
static int F_63 ( struct V_11 * V_12 )
{
struct V_24 * V_98 ;
T_3 V_36 , V_109 ;
bool V_135 , V_136 ;
bool V_137 , V_138 ;
bool V_139 , V_140 ;
V_98 = ( void * ) V_12 -> V_34 - sizeof( * V_98 ) ;
V_36 = F_10 ( V_98 -> V_35 . V_36 ) ;
V_109 = F_10 ( V_98 -> V_70 . V_101 ) ;
V_135 = ! ! ( V_109 & V_141 ) ;
V_136 = ! ! ( V_109 & V_142 ) ;
V_137 = ! ! ( V_109 & V_143 ) ;
V_138 = ! ! ( V_109 & V_144 ) ;
V_139 = ! ( V_36 & V_145 ) ;
V_140 = ! ( V_36 & V_146 ) ;
if ( ! V_135 && ! V_136 )
return V_147 ;
if ( ! V_137 && ! V_138 )
return V_147 ;
if ( ! V_139 )
return V_147 ;
if ( ! V_140 )
return V_147 ;
return V_148 ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_149 * V_150 )
{
struct V_108 V_109 ;
struct V_151 * V_152 ;
struct V_97 * V_105 ;
int V_153 ;
int V_55 ;
T_2 * V_54 ;
int V_15 , V_154 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_55 = F_73 ( V_150 -> V_155 . V_156 ) ;
V_54 = ( T_2 * ) & V_150 -> V_54 ;
V_153 = F_43 ( F_10 ( V_150 -> V_105 . V_101 ) ,
V_157 ) ;
V_152 = F_74 ( V_150 ) ;
F_39 ( V_64 , NULL , L_10 ,
V_150 , sizeof( * V_150 ) +
( sizeof( struct V_151 ) *
V_153 ) ) ;
for ( V_15 = 0 ; V_15 < V_153 ; V_15 ++ ) {
V_109 . V_158 = V_152 [ V_15 ] . V_159 ;
for ( V_154 = 0 ; V_154 < V_152 [ V_15 ] . V_160 ; V_154 ++ ) {
struct V_11 * V_161 , * V_162 ;
enum V_163 V_158 ;
int V_59 ;
V_161 = NULL ;
V_162 = NULL ;
V_59 = F_38 ( V_2 ,
& V_54 ,
& V_55 ,
& V_161 ,
& V_162 ) ;
if ( ! V_161 ) {
F_36 ( L_11 ) ;
continue;
}
if ( V_161 -> V_21 == 0 ) {
F_53 ( V_164 ,
L_12 ) ;
F_37 ( V_161 ) ;
continue;
}
if ( F_70 ( V_161 ) ) {
F_37 ( V_161 ) ;
continue;
}
V_158 = V_109 . V_158 ;
if ( V_158 == V_165 ) {
F_37 ( V_161 ) ;
continue;
}
if ( V_158 != V_166 &&
V_158 != V_167 &&
! V_2 -> V_18 -> V_168 ) {
F_53 ( V_164 ,
L_13 ,
V_158 ) ;
F_37 ( V_161 ) ;
continue;
}
if ( V_59 ) {
F_36 ( L_14 ) ;
F_37 ( V_161 ) ;
continue;
}
V_109 . V_12 = V_161 ;
V_109 . V_169 = F_71 ( V_161 ) ;
V_109 . signal = V_170 ;
V_109 . signal += V_150 -> V_171 . V_172 ;
V_109 . V_173 . V_67 = V_150 -> V_171 . V_67 ;
V_109 . V_173 . V_101 = F_10 ( V_150 -> V_171 . V_101 ) ;
V_109 . V_173 . V_174 = F_10 ( V_150 -> V_171 . V_174 ) ;
V_105 = F_56 ( V_161 ) ;
if ( F_57 ( V_105 ) )
F_60 ( V_2 , & V_109 ) ;
else
F_68 ( V_2 , & V_109 ) ;
}
}
F_26 ( & V_2 -> V_47 ) ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_175 * V_176 )
{
struct V_11 * V_161 , * V_162 ;
struct V_24 * V_98 ;
enum V_99 V_100 ;
struct V_108 V_109 = {} ;
struct V_97 * V_105 ;
int V_59 ;
bool V_177 ;
bool V_178 ;
T_2 * V_54 ;
int V_55 , V_179 , V_180 ;
int V_181 ;
V_55 = F_73 ( V_176 -> V_156 ) ;
V_54 = ( T_2 * ) V_176 -> V_182 ;
V_161 = NULL ;
V_162 = NULL ;
V_59 = F_38 ( V_2 , & V_54 , & V_55 ,
& V_161 , & V_162 ) ;
F_53 ( V_64 , L_15 ) ;
if ( ! V_161 ) {
F_36 ( L_16 ) ;
return;
}
if ( V_59 || V_161 != V_162 ) {
F_36 ( L_17 ) ;
F_37 ( V_161 ) ;
return;
}
V_105 = (struct V_97 * ) V_161 -> V_34 ;
V_98 = ( void * ) V_161 -> V_34 - sizeof( * V_98 ) ;
V_177 = ! ! ( F_10 ( V_98 -> V_35 . V_36 ) &
V_183 ) ;
V_178 = ! ! ( F_10 ( V_98 -> V_35 . V_36 ) &
V_133 ) ;
V_100 = F_43 ( F_10 ( V_98 -> V_70 . V_101 ) ,
V_102 ) ;
if ( V_100 != V_103 ) {
F_36 ( L_18 ) ;
F_8 ( V_161 ) ;
goto V_184;
}
V_109 . V_12 = V_161 ;
V_109 . V_158 = V_166 ;
V_109 . V_131 = F_43 ( F_10 ( V_98 -> V_117 . V_67 ) ,
V_118 ) ;
V_109 . V_12 -> V_122 = F_63 ( V_109 . V_12 ) ;
if ( V_177 ) {
F_36 ( L_19 ) ;
V_109 . V_158 = V_167 ;
}
if ( V_178 ) {
F_36 ( L_20 ) ;
F_8 ( V_109 . V_12 ) ;
goto V_184;
}
if ( V_109 . V_131 != V_96 ) {
V_179 = F_61 ( V_105 -> V_106 ) ;
V_180 = F_54 ( V_109 . V_131 ) ;
memmove ( ( void * ) V_109 . V_12 -> V_34 + V_180 ,
( void * ) V_109 . V_12 -> V_34 ,
V_179 ) ;
F_13 ( V_109 . V_12 , V_180 ) ;
V_105 = (struct V_97 * ) V_109 . V_12 -> V_34 ;
}
V_181 = 4 ;
V_181 += F_55 ( V_109 . V_131 ) ;
if ( ! F_76 ( V_105 -> V_106 ) &&
V_109 . V_131 == V_93 )
V_181 += 8 ;
if ( V_181 > V_109 . V_12 -> V_21 ) {
F_36 ( L_21 ) ;
F_8 ( V_109 . V_12 ) ;
goto V_184;
}
F_44 ( V_109 . V_12 , V_109 . V_12 -> V_21 - V_181 ) ;
F_39 ( V_64 , NULL , L_22 ,
V_109 . V_12 -> V_34 , V_109 . V_12 -> V_21 ) ;
F_67 ( V_2 -> V_18 , & V_109 ) ;
V_184:
if ( V_55 > 0 ) {
F_53 ( V_164 ,
L_23 ,
V_55 ) ;
}
}
void F_77 ( struct V_185 * V_18 , struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_18 -> V_2 ;
struct V_186 * V_187 = (struct V_186 * ) V_12 -> V_34 ;
if ( ! F_12 ( ( unsigned long ) V_12 -> V_34 , 4 ) )
F_36 ( L_24 ) ;
F_53 ( V_164 , L_25 ,
V_187 -> V_105 . V_188 ) ;
switch ( V_187 -> V_105 . V_188 ) {
case V_189 : {
V_2 -> V_190 = V_187 -> V_191 . V_192 ;
V_2 -> V_193 = V_187 -> V_191 . V_194 ;
F_78 ( & V_2 -> V_195 ) ;
break;
}
case V_196 : {
F_72 ( V_2 , & V_187 -> V_197 ) ;
break;
}
case V_198 : {
struct V_199 V_200 = {
. V_201 = V_187 -> V_202 . V_201 ,
. V_203 = F_73 ( V_187 -> V_202 . V_203 ) ,
} ;
memcpy ( V_200 . V_113 , V_187 -> V_202 . V_113 , sizeof( V_200 . V_113 ) ) ;
F_79 ( V_2 , & V_200 ) ;
break;
}
case V_204 : {
struct V_205 V_200 = {
. V_203 = F_73 ( V_187 -> V_206 . V_203 ) ,
} ;
F_80 ( V_2 , & V_200 ) ;
break;
}
case V_207 : {
struct V_208 V_209 = {} ;
int V_158 = F_10 ( V_187 -> V_210 . V_158 ) ;
V_209 . V_211 =
F_10 ( V_187 -> V_210 . V_212 ) ;
switch ( V_158 ) {
case V_213 :
break;
case V_214 :
V_209 . V_215 = true ;
break;
case V_216 :
V_209 . V_217 = true ;
break;
}
F_81 ( V_2 , & V_209 ) ;
break;
}
case V_218 : {
struct V_208 V_209 = {} ;
int V_158 = F_43 ( V_187 -> V_219 . V_36 ,
V_220 ) ;
T_4 V_211 ;
int V_15 ;
switch ( V_158 ) {
case V_221 :
V_209 . V_215 = true ;
break;
case V_222 :
break;
case V_223 :
case V_224 :
case V_225 :
V_209 . V_217 = true ;
break;
default:
F_36 ( L_26 ,
V_158 ) ;
V_209 . V_217 = true ;
break;
}
F_53 ( V_164 , L_27 ,
V_187 -> V_219 . V_226 ) ;
for ( V_15 = 0 ; V_15 < V_187 -> V_219 . V_226 ; V_15 ++ ) {
V_211 = V_187 -> V_219 . V_227 [ V_15 ] ;
V_209 . V_211 = F_73 ( V_211 ) ;
F_81 ( V_2 , & V_209 ) ;
}
break;
}
case V_228 : {
struct V_185 * V_18 = V_2 -> V_18 ;
struct V_229 * V_200 = & V_187 -> V_230 ;
F_53 ( V_164 ,
L_28 ,
F_73 ( V_200 -> V_203 ) ,
! ! ( V_200 -> V_36 & V_231 ) ,
F_43 ( V_200 -> V_36 , V_232 ) ) ;
F_78 ( & V_18 -> V_233 ) ;
break;
}
case V_234 : {
F_39 ( V_64 , NULL , L_29 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
F_75 ( V_2 , & V_187 -> V_235 ) ;
break;
}
case V_236 :
break;
case V_237 :
F_82 ( V_12 -> V_34 , V_12 -> V_21 ) ;
break;
case V_238 :
case V_239 :
case V_240 :
case V_241 :
default:
F_53 ( V_164 , L_30 ,
V_187 -> V_105 . V_188 ) ;
F_39 ( V_64 , NULL , L_29 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
break;
} ;
F_8 ( V_12 ) ;
}
