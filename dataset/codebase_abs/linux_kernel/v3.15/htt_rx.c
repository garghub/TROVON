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
void F_29 ( struct V_1 * V_2 )
{
int V_49 = V_2 -> V_10 . V_49 . V_50 ;
F_30 ( & V_2 -> V_10 . V_44 ) ;
F_31 ( & V_2 -> V_47 ) ;
F_31 ( & V_2 -> V_51 ) ;
F_32 ( & V_2 -> V_52 ) ;
F_32 ( & V_2 -> V_53 ) ;
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
V_2 -> V_10 . V_54 ) ;
F_33 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
V_2 -> V_10 . V_28 . V_29 ,
V_2 -> V_10 . V_28 . V_20 ) ;
F_34 ( V_2 -> V_10 . V_17 ) ;
}
static inline struct V_11 * F_35 ( struct V_1 * V_2 )
{
int V_27 ;
struct V_11 * V_55 ;
F_20 ( & V_2 -> V_10 . V_39 ) ;
if ( V_2 -> V_10 . V_16 == 0 ) {
F_36 ( L_1 ) ;
return NULL ;
}
V_27 = V_2 -> V_10 . V_49 . V_50 ;
V_55 = V_2 -> V_10 . V_17 [ V_27 ] ;
V_27 ++ ;
V_27 &= V_2 -> V_10 . V_38 ;
V_2 -> V_10 . V_49 . V_50 = V_27 ;
V_2 -> V_10 . V_16 -- ;
return V_55 ;
}
static void F_37 ( struct V_11 * V_12 )
{
struct V_11 * V_56 ;
while ( V_12 ) {
V_56 = V_12 -> V_56 ;
F_8 ( V_12 ) ;
V_12 = V_56 ;
}
}
static int F_38 ( struct V_1 * V_2 ,
T_2 * * V_57 , int * V_58 ,
struct V_11 * * V_59 ,
struct V_11 * * V_60 )
{
int V_61 , V_62 = 0 ;
struct V_11 * V_55 ;
struct V_24 * V_25 ;
F_20 ( & V_2 -> V_10 . V_39 ) ;
if ( V_2 -> V_63 ) {
F_36 ( L_2 ) ;
return 0 ;
}
V_55 = * V_59 = F_35 ( V_2 ) ;
while ( V_55 ) {
int V_64 , V_65 , V_66 ;
F_6 ( V_2 -> V_18 -> V_19 ,
F_5 ( V_55 ) -> V_20 ,
V_55 -> V_21 + F_7 ( V_55 ) ,
V_22 ) ;
F_39 ( V_67 , NULL , L_3 ,
V_55 -> V_34 , V_55 -> V_21 + F_7 ( V_55 ) ) ;
V_25 = (struct V_24 * ) V_55 -> V_34 ;
F_40 ( V_55 , F_41 ( struct V_24 , V_68 ) ) ;
F_13 ( V_55 , F_41 ( struct V_24 , V_68 ) ) ;
if ( ! ( F_10 ( V_25 -> V_35 . V_36 )
& V_69 ) ) {
F_37 ( * V_59 ) ;
* V_59 = NULL ;
V_55 = NULL ;
F_42 ( L_4 ) ;
V_2 -> V_63 = true ;
break;
}
if ( * V_58 > 0 ) {
V_25 -> V_57 . V_70 = * * V_57 ;
( * V_57 ) ++ ;
( * V_58 ) -- ;
} else {
V_25 -> V_57 . V_70 = 0 ;
}
V_65 = ! ! ( F_10 ( V_25 -> V_35 . V_36 )
& ( V_71 |
V_72 ) ) ;
V_61 = F_43 ( F_10 ( V_25 -> V_73 . V_70 ) ,
V_74 ) ;
V_66 = V_25 -> V_75 . V_76 ;
V_62 = V_66 ;
if ( V_65 )
V_61 = 0 ;
F_44 ( V_55 , 0 ) ;
F_40 ( V_55 , F_23 ( V_61 , V_77 ) ) ;
V_61 -= V_55 -> V_21 ;
while ( V_66 -- ) {
struct V_11 * V_56 = F_35 ( V_2 ) ;
F_6 ( V_2 -> V_18 -> V_19 ,
F_5 ( V_56 ) -> V_20 ,
V_56 -> V_21 + F_7 ( V_56 ) ,
V_22 ) ;
F_39 ( V_67 , NULL ,
L_5 , V_56 -> V_34 ,
V_56 -> V_21 + F_7 ( V_56 ) ) ;
F_44 ( V_56 , 0 ) ;
F_40 ( V_56 , F_23 ( V_61 , V_30 ) ) ;
V_61 -= V_56 -> V_21 ;
V_55 -> V_56 = V_56 ;
V_55 = V_56 ;
}
V_64 = F_10 ( V_25 -> V_78 . V_70 ) &
V_79 ;
if ( V_64 ) {
V_55 -> V_56 = NULL ;
break;
} else {
struct V_11 * V_56 = F_35 ( V_2 ) ;
V_55 -> V_56 = V_56 ;
V_55 = V_56 ;
}
}
* V_60 = V_55 ;
return V_62 ;
}
static void F_45 ( unsigned long V_80 )
{
struct V_1 * V_2 = (struct V_1 * ) V_80 ;
F_21 ( V_2 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
T_1 V_20 ;
void * V_29 ;
struct V_81 * V_82 = & V_2 -> V_10 . V_44 ;
V_2 -> V_10 . V_3 = F_1 ( V_2 ) ;
if ( ! F_47 ( V_2 -> V_10 . V_3 ) ) {
F_36 ( L_6 ) ;
return - V_83 ;
}
V_2 -> V_10 . V_38 = V_2 -> V_10 . V_3 - 1 ;
V_2 -> V_10 . V_42 = F_3 ( V_2 ) ;
V_2 -> V_10 . V_17 =
F_48 ( V_2 -> V_10 . V_3 * sizeof( struct V_11 * ) ,
V_84 ) ;
if ( ! V_2 -> V_10 . V_17 )
goto V_85;
V_29 = F_49 ( V_2 -> V_18 -> V_19 ,
( V_2 -> V_10 . V_3 * sizeof( V_2 -> V_10 . V_37 ) ) ,
& V_20 , V_86 ) ;
if ( ! V_29 )
goto V_87;
V_2 -> V_10 . V_37 = V_29 ;
V_2 -> V_10 . V_54 = V_20 ;
V_29 = F_49 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
& V_20 , V_86 ) ;
if ( ! V_29 )
goto V_88;
V_2 -> V_10 . V_28 . V_29 = V_29 ;
V_2 -> V_10 . V_28 . V_20 = V_20 ;
V_2 -> V_10 . V_49 . V_50 = 0 ;
* V_2 -> V_10 . V_28 . V_29 = 0 ;
F_50 ( V_82 , F_28 , ( unsigned long ) V_2 ) ;
F_51 ( & V_2 -> V_10 . V_39 ) ;
V_2 -> V_10 . V_16 = 0 ;
if ( F_9 ( V_2 , V_2 -> V_10 . V_42 ) )
goto V_89;
F_52 ( & V_2 -> V_47 , F_45 ,
( unsigned long ) V_2 ) ;
F_53 ( & V_2 -> V_52 ) ;
F_53 ( & V_2 -> V_53 ) ;
F_52 ( & V_2 -> V_51 , V_90 ,
( unsigned long ) V_2 ) ;
F_54 ( V_91 , L_7 ,
V_2 -> V_10 . V_3 , V_2 -> V_10 . V_42 ) ;
return 0 ;
V_89:
F_4 ( V_2 ) ;
F_33 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
V_2 -> V_10 . V_28 . V_29 ,
V_2 -> V_10 . V_28 . V_20 ) ;
V_88:
F_33 ( V_2 -> V_18 -> V_19 ,
( V_2 -> V_10 . V_3 *
sizeof( V_2 -> V_10 . V_37 ) ) ,
V_2 -> V_10 . V_37 ,
V_2 -> V_10 . V_54 ) ;
V_87:
F_34 ( V_2 -> V_10 . V_17 ) ;
V_85:
return - V_32 ;
}
static int F_55 ( enum V_92 type )
{
switch ( type ) {
case V_93 :
case V_94 :
return 4 ;
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
return 8 ;
case V_100 :
return 0 ;
}
F_36 ( L_8 , type ) ;
return 0 ;
}
static int F_56 ( enum V_92 type )
{
switch ( type ) {
case V_100 :
case V_93 :
case V_94 :
case V_96 :
case V_98 :
return 0 ;
case V_95 :
case V_97 :
return 4 ;
case V_99 :
return 8 ;
}
F_36 ( L_8 , type ) ;
return 0 ;
}
static struct V_101 * F_57 ( struct V_11 * V_12 )
{
struct V_24 * V_102 ;
enum V_103 V_104 ;
V_102 = ( void * ) V_12 -> V_34 - sizeof( * V_102 ) ;
V_104 = F_43 ( F_10 ( V_102 -> V_73 . V_105 ) ,
V_106 ) ;
if ( V_104 == V_107 )
return ( void * ) V_12 -> V_34 ;
else
return ( void * ) V_12 -> V_34 - V_108 ;
}
static bool F_58 ( struct V_101 * V_109 )
{
if ( F_59 ( V_109 -> V_110 ) ) {
T_2 * V_111 = F_60 ( V_109 ) ;
if ( V_111 [ 0 ] & 0x80 )
return true ;
}
return false ;
}
static int F_61 ( struct V_101 * V_109 )
{
return F_62 ( F_63 ( V_109 -> V_110 ) , 4 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
struct V_24 * V_102 ;
struct V_11 * V_114 ;
struct V_11 * V_12 = V_113 -> V_12 ;
enum V_103 V_104 ;
enum V_92 V_115 ;
struct V_101 * V_109 ;
T_2 V_116 [ 64 ] , V_117 [ V_118 ] , * V_119 ;
unsigned int V_120 ;
V_102 = ( void * ) V_12 -> V_34 - sizeof( * V_102 ) ;
V_115 = F_43 ( F_10 ( V_102 -> V_121 . V_70 ) ,
V_122 ) ;
V_109 = (struct V_101 * ) V_102 -> V_123 ;
V_120 = F_63 ( V_109 -> V_110 ) ;
memcpy ( V_116 , V_109 , V_120 ) ;
V_109 = (struct V_101 * ) V_116 ;
V_114 = V_12 ;
while ( V_12 ) {
void * V_124 ;
int V_21 ;
V_102 = ( void * ) V_12 -> V_34 - sizeof( * V_102 ) ;
V_104 = F_43 ( F_10 ( V_102 -> V_73 . V_105 ) ,
V_106 ) ;
V_124 = ( void * ) V_102 -> V_123 ;
V_12 -> V_125 = F_65 ( V_12 ) ;
if ( V_12 == V_114 ) {
V_21 = F_62 ( F_63 ( V_109 -> V_110 ) , 4 ) ;
V_21 += F_62 ( F_55 ( V_115 ) ,
4 ) ;
V_124 += V_21 ;
}
switch ( V_104 ) {
case V_107 :
F_44 ( V_12 , V_12 -> V_21 - V_126 ) ;
break;
case V_127 :
V_109 = (struct V_101 * ) V_12 -> V_34 ;
V_120 = F_61 ( V_109 ) ;
memcpy ( V_117 , F_66 ( V_109 ) , V_118 ) ;
F_13 ( V_12 , V_120 ) ;
V_109 = (struct V_101 * ) V_116 ;
V_120 = F_63 ( V_109 -> V_110 ) ;
memcpy ( F_67 ( V_12 , V_120 ) , V_109 , V_120 ) ;
V_109 = (struct V_101 * ) V_12 -> V_34 ;
V_119 = F_60 ( V_109 ) ;
V_119 [ 0 ] &= ~ V_128 ;
memcpy ( F_66 ( V_109 ) , V_117 , V_118 ) ;
break;
case V_129 :
V_21 = 0 ;
V_21 += sizeof( struct V_130 ) ;
V_21 += sizeof( struct V_131 ) ;
F_13 ( V_12 , sizeof( struct V_132 ) ) ;
memcpy ( F_67 ( V_12 , V_21 ) , V_124 , V_21 ) ;
memcpy ( F_67 ( V_12 , V_120 ) , V_109 , V_120 ) ;
break;
case V_133 :
memcpy ( F_67 ( V_12 , V_120 ) , V_109 , V_120 ) ;
break;
}
V_113 -> V_12 = V_12 ;
V_113 -> V_134 = V_115 ;
V_12 = V_12 -> V_56 ;
V_113 -> V_12 -> V_56 = NULL ;
if ( V_12 )
V_113 -> V_135 = true ;
F_68 ( V_2 -> V_18 , V_113 ) ;
}
}
static void F_69 ( struct V_1 * V_2 , struct V_112 * V_113 )
{
struct V_11 * V_12 = V_113 -> V_12 ;
struct V_24 * V_102 ;
struct V_101 * V_109 ;
enum V_103 V_104 ;
enum V_92 V_115 ;
int V_120 ;
void * V_136 ;
if ( V_12 -> V_56 ) {
F_36 ( L_9 ) ;
F_37 ( V_12 -> V_56 ) ;
V_12 -> V_56 = NULL ;
}
V_102 = ( void * ) V_12 -> V_34 - sizeof( * V_102 ) ;
V_104 = F_43 ( F_10 ( V_102 -> V_73 . V_105 ) ,
V_106 ) ;
V_115 = F_43 ( F_10 ( V_102 -> V_121 . V_70 ) ,
V_122 ) ;
V_109 = (struct V_101 * ) V_102 -> V_123 ;
V_120 = F_63 ( V_109 -> V_110 ) ;
V_12 -> V_125 = F_65 ( V_12 ) ;
switch ( V_104 ) {
case V_107 :
F_44 ( V_12 , V_12 -> V_21 - V_126 ) ;
break;
case V_127 :
V_109 = (struct V_101 * ) V_12 -> V_34 ;
V_120 = F_61 ( V_109 ) ;
F_13 ( V_12 , V_120 ) ;
V_109 = (struct V_101 * ) V_102 -> V_123 ;
V_120 = F_63 ( V_109 -> V_110 ) ;
memcpy ( F_67 ( V_12 , V_120 ) , V_109 , V_120 ) ;
break;
case V_129 :
V_136 = V_109 ;
V_136 += F_70 ( V_120 , 4 ) ;
V_136 += F_70 ( F_55 ( V_115 ) , 4 ) ;
F_13 ( V_12 , sizeof( struct V_132 ) ) ;
memcpy ( F_67 ( V_12 , sizeof( struct V_130 ) ) ,
V_136 , sizeof( struct V_130 ) ) ;
memcpy ( F_67 ( V_12 , V_120 ) , V_109 , V_120 ) ;
break;
case V_133 :
F_13 ( V_12 , sizeof( struct V_131 ) ) ;
memcpy ( F_67 ( V_12 , V_120 ) , V_109 , V_120 ) ;
break;
}
V_113 -> V_12 = V_12 ;
V_113 -> V_134 = V_115 ;
F_68 ( V_2 -> V_18 , V_113 ) ;
}
static bool F_71 ( struct V_11 * V_12 )
{
struct V_24 * V_102 ;
T_3 V_36 ;
V_102 = ( void * ) V_12 -> V_34 - sizeof( * V_102 ) ;
V_36 = F_10 ( V_102 -> V_35 . V_36 ) ;
if ( V_36 & V_137 )
return true ;
return false ;
}
static bool F_72 ( struct V_11 * V_12 )
{
struct V_24 * V_102 ;
T_3 V_36 ;
V_102 = ( void * ) V_12 -> V_34 - sizeof( * V_102 ) ;
V_36 = F_10 ( V_102 -> V_35 . V_36 ) ;
if ( V_36 & V_138 )
return true ;
return false ;
}
static bool F_73 ( struct V_11 * V_12 )
{
struct V_24 * V_102 ;
T_3 V_36 ;
V_102 = ( void * ) V_12 -> V_34 - sizeof( * V_102 ) ;
V_36 = F_10 ( V_102 -> V_35 . V_36 ) ;
if ( V_36 & V_139 )
return true ;
return false ;
}
static bool F_74 ( struct V_11 * V_12 )
{
struct V_24 * V_102 ;
T_3 V_36 ;
V_102 = ( void * ) V_12 -> V_34 - sizeof( * V_102 ) ;
V_36 = F_10 ( V_102 -> V_35 . V_36 ) ;
if ( V_36 & V_140 )
return true ;
return false ;
}
static int F_65 ( struct V_11 * V_12 )
{
struct V_24 * V_102 ;
T_3 V_36 , V_113 ;
bool V_141 , V_142 ;
bool V_143 , V_144 ;
bool V_145 , V_146 ;
V_102 = ( void * ) V_12 -> V_34 - sizeof( * V_102 ) ;
V_36 = F_10 ( V_102 -> V_35 . V_36 ) ;
V_113 = F_10 ( V_102 -> V_73 . V_105 ) ;
V_141 = ! ! ( V_113 & V_147 ) ;
V_142 = ! ! ( V_113 & V_148 ) ;
V_143 = ! ! ( V_113 & V_149 ) ;
V_144 = ! ! ( V_113 & V_150 ) ;
V_145 = ! ( V_36 & V_151 ) ;
V_146 = ! ( V_36 & V_152 ) ;
if ( ! V_141 && ! V_142 )
return V_153 ;
if ( ! V_143 && ! V_144 )
return V_153 ;
if ( ! V_145 )
return V_153 ;
if ( ! V_146 )
return V_153 ;
return V_154 ;
}
static int F_75 ( struct V_11 * V_155 )
{
struct V_11 * V_56 = V_155 -> V_56 ;
struct V_11 * V_156 = V_56 ;
int V_157 ;
int V_158 = 0 ;
V_155 -> V_56 = NULL ;
while ( V_56 ) {
V_158 += V_56 -> V_21 ;
V_56 = V_56 -> V_56 ;
}
V_157 = V_158 - F_7 ( V_155 ) ;
if ( ( V_157 > 0 ) &&
( F_76 ( V_155 , 0 , V_157 , V_159 ) < 0 ) ) {
V_155 -> V_56 = V_156 ;
return - 1 ;
}
V_56 = V_156 ;
while ( V_56 ) {
F_77 ( V_56 , F_40 ( V_155 , V_56 -> V_21 ) ,
V_56 -> V_21 ) ;
V_56 = V_56 -> V_56 ;
}
F_37 ( V_156 ) ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_160 * V_161 )
{
struct V_112 V_113 ;
struct V_162 * V_163 ;
struct V_101 * V_109 ;
int V_164 ;
int V_58 ;
T_2 * V_57 ;
int V_15 , V_165 ;
F_20 ( & V_2 -> V_10 . V_39 ) ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_58 = F_79 ( V_161 -> V_166 . V_167 ) ;
V_57 = ( T_2 * ) & V_161 -> V_57 ;
V_164 = F_43 ( F_10 ( V_161 -> V_109 . V_105 ) ,
V_168 ) ;
V_163 = F_80 ( V_161 ) ;
F_39 ( V_67 , NULL , L_10 ,
V_161 , sizeof( * V_161 ) +
( sizeof( struct V_162 ) *
V_164 ) ) ;
for ( V_15 = 0 ; V_15 < V_164 ; V_15 ++ ) {
V_113 . V_169 = V_163 [ V_15 ] . V_170 ;
for ( V_165 = 0 ; V_165 < V_163 [ V_15 ] . V_171 ; V_165 ++ ) {
struct V_11 * V_155 , * V_172 ;
enum V_173 V_169 ;
int V_62 ;
V_155 = NULL ;
V_172 = NULL ;
V_62 = F_38 ( V_2 ,
& V_57 ,
& V_58 ,
& V_155 ,
& V_172 ) ;
if ( ! V_155 ) {
F_36 ( L_11 ) ;
continue;
}
if ( V_155 -> V_21 == 0 ) {
F_54 ( V_174 ,
L_12 ) ;
F_37 ( V_155 ) ;
continue;
}
if ( F_71 ( V_155 ) ) {
F_54 ( V_174 ,
L_13 ) ;
F_37 ( V_155 ) ;
continue;
}
V_169 = V_113 . V_169 ;
if ( V_169 == V_175 ||
F_74 ( V_155 ) ) {
F_54 ( V_174 , L_14 ) ;
F_37 ( V_155 ) ;
continue;
}
if ( V_169 != V_176 &&
V_169 != V_177 &&
V_169 != V_178 &&
! V_2 -> V_18 -> V_179 ) {
F_54 ( V_174 ,
L_15 ,
V_169 ) ;
F_37 ( V_155 ) ;
continue;
}
if ( F_81 ( V_180 , & V_2 -> V_18 -> V_181 ) ) {
F_54 ( V_174 ,
L_16 ) ;
F_37 ( V_155 ) ;
continue;
}
if ( V_62 &&
( F_75 ( V_155 ) < 0 ) ) {
F_37 ( V_155 ) ;
continue;
}
V_113 . V_12 = V_155 ;
V_113 . V_182 = F_72 ( V_155 ) ;
V_113 . V_183 = F_73 ( V_155 ) ;
if ( V_113 . V_182 )
F_54 ( V_174 ,
L_17 ) ;
if ( V_113 . V_183 )
F_54 ( V_174 ,
L_18 ) ;
V_113 . signal = V_184 ;
V_113 . signal += V_161 -> V_185 . V_186 ;
V_113 . V_187 . V_70 = V_161 -> V_185 . V_70 ;
V_113 . V_187 . V_105 = F_10 ( V_161 -> V_185 . V_105 ) ;
V_113 . V_187 . V_188 = F_10 ( V_161 -> V_185 . V_188 ) ;
V_113 . V_189 = F_10 ( V_161 -> V_185 . V_189 ) ;
V_109 = F_57 ( V_155 ) ;
if ( F_58 ( V_109 ) )
F_64 ( V_2 , & V_113 ) ;
else
F_69 ( V_2 , & V_113 ) ;
}
}
F_26 ( & V_2 -> V_47 ) ;
}
static void F_82 ( struct V_1 * V_2 ,
struct V_190 * V_191 )
{
struct V_11 * V_155 , * V_172 ;
struct V_24 * V_102 ;
enum V_103 V_104 ;
struct V_112 V_113 = {} ;
struct V_101 * V_109 ;
int V_62 ;
bool V_192 ;
bool V_193 ;
T_2 * V_57 ;
int V_58 , V_194 , V_195 ;
int V_196 ;
V_58 = F_79 ( V_191 -> V_167 ) ;
V_57 = ( T_2 * ) V_191 -> V_197 ;
V_155 = NULL ;
V_172 = NULL ;
F_22 ( & V_2 -> V_10 . V_39 ) ;
V_62 = F_38 ( V_2 , & V_57 , & V_58 ,
& V_155 , & V_172 ) ;
F_27 ( & V_2 -> V_10 . V_39 ) ;
F_54 ( V_67 , L_19 ) ;
if ( ! V_155 ) {
F_36 ( L_20 ) ;
return;
}
if ( V_62 || V_155 != V_172 ) {
F_36 ( L_21 ) ;
F_37 ( V_155 ) ;
return;
}
V_109 = (struct V_101 * ) V_155 -> V_34 ;
V_102 = ( void * ) V_155 -> V_34 - sizeof( * V_102 ) ;
V_192 = ! ! ( F_10 ( V_102 -> V_35 . V_36 ) &
V_139 ) ;
V_193 = ! ! ( F_10 ( V_102 -> V_35 . V_36 ) &
V_137 ) ;
V_104 = F_43 ( F_10 ( V_102 -> V_73 . V_105 ) ,
V_106 ) ;
if ( V_104 != V_107 ) {
F_36 ( L_22 ) ;
F_8 ( V_155 ) ;
goto V_198;
}
V_113 . V_12 = V_155 ;
V_113 . V_169 = V_176 ;
V_113 . V_134 = F_43 ( F_10 ( V_102 -> V_121 . V_70 ) ,
V_122 ) ;
V_113 . V_12 -> V_125 = F_65 ( V_113 . V_12 ) ;
if ( V_192 ) {
F_36 ( L_23 ) ;
V_113 . V_169 = V_177 ;
}
if ( V_193 ) {
F_36 ( L_24 ) ;
F_8 ( V_113 . V_12 ) ;
goto V_198;
}
if ( V_113 . V_134 != V_100 ) {
V_194 = F_63 ( V_109 -> V_110 ) ;
V_195 = F_55 ( V_113 . V_134 ) ;
memmove ( ( void * ) V_113 . V_12 -> V_34 + V_195 ,
( void * ) V_113 . V_12 -> V_34 ,
V_194 ) ;
F_13 ( V_113 . V_12 , V_195 ) ;
V_109 = (struct V_101 * ) V_113 . V_12 -> V_34 ;
}
V_196 = 4 ;
V_196 += F_56 ( V_113 . V_134 ) ;
if ( ! F_83 ( V_109 -> V_110 ) &&
V_113 . V_134 == V_97 )
V_196 += 8 ;
if ( V_196 > V_113 . V_12 -> V_21 ) {
F_36 ( L_25 ) ;
F_8 ( V_113 . V_12 ) ;
goto V_198;
}
F_44 ( V_113 . V_12 , V_113 . V_12 -> V_21 - V_196 ) ;
F_39 ( V_67 , NULL , L_26 ,
V_113 . V_12 -> V_34 , V_113 . V_12 -> V_21 ) ;
F_68 ( V_2 -> V_18 , & V_113 ) ;
V_198:
if ( V_58 > 0 ) {
F_54 ( V_174 ,
L_27 ,
V_58 ) ;
}
}
static void F_84 ( struct V_199 * V_18 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_18 -> V_2 ;
struct V_200 * V_201 = (struct V_200 * ) V_12 -> V_34 ;
struct V_202 V_203 = {} ;
int V_169 = F_43 ( V_201 -> V_204 . V_36 , V_205 ) ;
T_4 V_206 ;
int V_15 ;
F_20 ( & V_2 -> V_207 ) ;
switch ( V_169 ) {
case V_208 :
V_203 . V_209 = true ;
break;
case V_210 :
break;
case V_211 :
case V_212 :
case V_213 :
V_203 . V_214 = true ;
break;
default:
F_36 ( L_28 , V_169 ) ;
V_203 . V_214 = true ;
break;
}
F_54 ( V_174 , L_29 ,
V_201 -> V_204 . V_215 ) ;
for ( V_15 = 0 ; V_15 < V_201 -> V_204 . V_215 ; V_15 ++ ) {
V_206 = V_201 -> V_204 . V_216 [ V_15 ] ;
V_203 . V_206 = F_79 ( V_206 ) ;
F_85 ( V_2 , & V_203 ) ;
}
}
void F_86 ( struct V_199 * V_18 , struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_18 -> V_2 ;
struct V_200 * V_201 = (struct V_200 * ) V_12 -> V_34 ;
if ( ! F_12 ( ( unsigned long ) V_12 -> V_34 , 4 ) )
F_36 ( L_30 ) ;
F_54 ( V_174 , L_31 ,
V_201 -> V_109 . V_217 ) ;
switch ( V_201 -> V_109 . V_217 ) {
case V_218 : {
V_2 -> V_219 = V_201 -> V_220 . V_221 ;
V_2 -> V_222 = V_201 -> V_220 . V_223 ;
F_87 ( & V_2 -> V_224 ) ;
break;
}
case V_225 :
F_22 ( & V_2 -> V_10 . V_39 ) ;
F_88 ( & V_2 -> V_53 , V_12 ) ;
F_27 ( & V_2 -> V_10 . V_39 ) ;
F_26 ( & V_2 -> V_51 ) ;
return;
case V_226 : {
struct V_227 V_228 = {
. V_229 = V_201 -> V_230 . V_229 ,
. V_231 = F_79 ( V_201 -> V_230 . V_231 ) ,
} ;
memcpy ( V_228 . V_117 , V_201 -> V_230 . V_117 , sizeof( V_228 . V_117 ) ) ;
F_89 ( V_2 , & V_228 ) ;
break;
}
case V_232 : {
struct V_233 V_228 = {
. V_231 = F_79 ( V_201 -> V_234 . V_231 ) ,
} ;
F_90 ( V_2 , & V_228 ) ;
break;
}
case V_235 : {
struct V_202 V_203 = {} ;
int V_169 = F_10 ( V_201 -> V_236 . V_169 ) ;
V_203 . V_206 =
F_10 ( V_201 -> V_236 . V_237 ) ;
switch ( V_169 ) {
case V_238 :
break;
case V_239 :
V_203 . V_209 = true ;
break;
case V_240 :
V_203 . V_214 = true ;
break;
}
F_22 ( & V_2 -> V_207 ) ;
F_85 ( V_2 , & V_203 ) ;
F_27 ( & V_2 -> V_207 ) ;
break;
}
case V_241 :
F_22 ( & V_2 -> V_207 ) ;
F_88 ( & V_2 -> V_52 , V_12 ) ;
F_27 ( & V_2 -> V_207 ) ;
F_26 ( & V_2 -> V_51 ) ;
return;
case V_242 : {
struct V_199 * V_18 = V_2 -> V_18 ;
struct V_243 * V_228 = & V_201 -> V_244 ;
F_54 ( V_174 ,
L_32 ,
F_79 ( V_228 -> V_231 ) ,
! ! ( V_228 -> V_36 & V_245 ) ,
F_43 ( V_228 -> V_36 , V_246 ) ) ;
F_87 ( & V_18 -> V_247 ) ;
break;
}
case V_248 : {
F_39 ( V_67 , NULL , L_33 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
F_82 ( V_2 , & V_201 -> V_249 ) ;
break;
}
case V_250 :
break;
case V_251 :
F_91 ( V_12 -> V_34 , V_12 -> V_21 ) ;
break;
case V_252 :
case V_253 :
case V_254 :
case V_255 :
default:
F_54 ( V_174 , L_34 ,
V_201 -> V_109 . V_217 ) ;
F_39 ( V_67 , NULL , L_33 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
break;
} ;
F_8 ( V_12 ) ;
}
static void V_90 ( unsigned long V_80 )
{
struct V_1 * V_2 = (struct V_1 * ) V_80 ;
struct V_200 * V_201 ;
struct V_11 * V_12 ;
F_22 ( & V_2 -> V_207 ) ;
while ( ( V_12 = F_92 ( & V_2 -> V_52 ) ) ) {
F_84 ( V_2 -> V_18 , V_12 ) ;
F_8 ( V_12 ) ;
}
F_27 ( & V_2 -> V_207 ) ;
F_22 ( & V_2 -> V_10 . V_39 ) ;
while ( ( V_12 = F_92 ( & V_2 -> V_53 ) ) ) {
V_201 = (struct V_200 * ) V_12 -> V_34 ;
F_78 ( V_2 , & V_201 -> V_256 ) ;
F_8 ( V_12 ) ;
}
F_27 ( & V_2 -> V_10 . V_39 ) ;
}
