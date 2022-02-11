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
int V_26 , V_40 ;
F_22 ( & V_2 -> V_10 . V_39 ) ;
V_40 = V_2 -> V_10 . V_41 - V_2 -> V_10 . V_16 ;
V_26 = F_19 ( V_2 , V_40 ) ;
if ( V_26 == - V_32 ) {
F_23 ( & V_2 -> V_10 . V_42 , V_43 +
F_24 ( V_44 ) ) ;
}
F_25 ( & V_2 -> V_10 . V_39 ) ;
}
static void F_26 ( unsigned long V_45 )
{
struct V_1 * V_2 = (struct V_1 * ) V_45 ;
F_21 ( V_2 ) ;
}
static unsigned F_27 ( struct V_1 * V_2 )
{
return ( F_10 ( * V_2 -> V_10 . V_28 . V_29 ) -
V_2 -> V_10 . V_46 . V_47 ) & V_2 -> V_10 . V_38 ;
}
void F_28 ( struct V_1 * V_2 )
{
int V_46 = V_2 -> V_10 . V_46 . V_47 ;
F_29 ( & V_2 -> V_10 . V_42 ) ;
while ( V_46 != F_10 ( * ( V_2 -> V_10 . V_28 . V_29 ) ) ) {
struct V_11 * V_12 =
V_2 -> V_10 . V_17 [ V_46 ] ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
F_6 ( V_2 -> V_18 -> V_19 , V_14 -> V_20 ,
V_12 -> V_21 + F_7 ( V_12 ) ,
V_22 ) ;
F_8 ( V_2 -> V_10 . V_17 [ V_46 ] ) ;
V_46 ++ ;
V_46 &= V_2 -> V_10 . V_38 ;
}
F_30 ( V_2 -> V_18 -> V_19 ,
( V_2 -> V_10 . V_3 *
sizeof( V_2 -> V_10 . V_37 ) ) ,
V_2 -> V_10 . V_37 ,
V_2 -> V_10 . V_48 ) ;
F_30 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
V_2 -> V_10 . V_28 . V_29 ,
V_2 -> V_10 . V_28 . V_20 ) ;
F_31 ( V_2 -> V_10 . V_17 ) ;
}
static inline struct V_11 * F_32 ( struct V_1 * V_2 )
{
int V_27 ;
struct V_11 * V_49 ;
F_22 ( & V_2 -> V_10 . V_39 ) ;
if ( F_27 ( V_2 ) == 0 )
F_33 ( L_1 ) ;
V_27 = V_2 -> V_10 . V_46 . V_47 ;
V_49 = V_2 -> V_10 . V_17 [ V_27 ] ;
V_27 ++ ;
V_27 &= V_2 -> V_10 . V_38 ;
V_2 -> V_10 . V_46 . V_47 = V_27 ;
V_2 -> V_10 . V_16 -- ;
F_25 ( & V_2 -> V_10 . V_39 ) ;
return V_49 ;
}
static void F_34 ( struct V_11 * V_12 )
{
struct V_11 * V_50 ;
while ( V_12 ) {
V_50 = V_12 -> V_50 ;
F_8 ( V_12 ) ;
V_12 = V_50 ;
}
}
static int F_35 ( struct V_1 * V_2 ,
T_2 * * V_51 , int * V_52 ,
struct V_11 * * V_53 ,
struct V_11 * * V_54 )
{
int V_55 , V_56 = 0 ;
struct V_11 * V_49 ;
struct V_24 * V_25 ;
if ( F_27 ( V_2 ) == 0 )
F_33 ( L_1 ) ;
if ( V_2 -> V_57 ) {
F_33 ( L_2 ) ;
return 0 ;
}
V_49 = * V_53 = F_32 ( V_2 ) ;
while ( V_49 ) {
int V_58 , V_59 , V_60 ;
F_6 ( V_2 -> V_18 -> V_19 ,
F_5 ( V_49 ) -> V_20 ,
V_49 -> V_21 + F_7 ( V_49 ) ,
V_22 ) ;
F_36 ( V_61 , NULL , L_3 ,
V_49 -> V_34 , V_49 -> V_21 + F_7 ( V_49 ) ) ;
V_25 = (struct V_24 * ) V_49 -> V_34 ;
F_37 ( V_49 , F_38 ( struct V_24 , V_62 ) ) ;
F_13 ( V_49 , F_38 ( struct V_24 , V_62 ) ) ;
if ( ! ( F_10 ( V_25 -> V_35 . V_36 )
& V_63 ) ) {
F_34 ( * V_53 ) ;
* V_53 = NULL ;
V_49 = NULL ;
F_39 ( L_4 ) ;
V_2 -> V_57 = true ;
break;
}
if ( * V_52 > 0 ) {
V_25 -> V_51 . V_64 = * * V_51 ;
( * V_51 ) ++ ;
( * V_52 ) -- ;
} else {
V_25 -> V_51 . V_64 = 0 ;
}
V_59 = ! ! ( F_10 ( V_25 -> V_35 . V_36 )
& ( V_65 |
V_66 ) ) ;
V_55 = F_40 ( F_10 ( V_25 -> V_67 . V_64 ) ,
V_68 ) ;
V_60 = V_25 -> V_69 . V_70 ;
if ( V_59 )
V_55 = 0 ;
F_41 ( V_49 , 0 ) ;
F_37 ( V_49 , F_42 ( V_55 , V_71 ) ) ;
V_55 -= V_49 -> V_21 ;
while ( V_60 -- ) {
struct V_11 * V_50 = F_32 ( V_2 ) ;
F_6 ( V_2 -> V_18 -> V_19 ,
F_5 ( V_50 ) -> V_20 ,
V_50 -> V_21 + F_7 ( V_50 ) ,
V_22 ) ;
F_36 ( V_61 , NULL , L_3 ,
V_50 -> V_34 ,
V_50 -> V_21 + F_7 ( V_50 ) ) ;
F_41 ( V_50 , 0 ) ;
F_37 ( V_50 , F_42 ( V_55 , V_30 ) ) ;
V_55 -= V_50 -> V_21 ;
V_49 -> V_50 = V_50 ;
V_49 = V_50 ;
V_56 = 1 ;
}
if ( V_55 > 0 ) {
F_33 ( L_5 ,
V_55 ) ;
}
V_58 = F_10 ( V_25 -> V_72 . V_64 ) &
V_73 ;
if ( V_58 ) {
V_49 -> V_50 = NULL ;
break;
} else {
struct V_11 * V_50 = F_32 ( V_2 ) ;
V_49 -> V_50 = V_50 ;
V_49 = V_50 ;
}
}
* V_54 = V_49 ;
return V_56 ;
}
int F_43 ( struct V_1 * V_2 )
{
T_1 V_20 ;
void * V_29 ;
struct V_74 * V_75 = & V_2 -> V_10 . V_42 ;
V_2 -> V_10 . V_3 = F_1 ( V_2 ) ;
if ( ! F_44 ( V_2 -> V_10 . V_3 ) ) {
F_33 ( L_6 ) ;
return - V_76 ;
}
V_2 -> V_10 . V_38 = V_2 -> V_10 . V_3 - 1 ;
V_2 -> V_10 . V_41 = F_3 ( V_2 ) ;
V_2 -> V_10 . V_17 =
F_45 ( V_2 -> V_10 . V_3 * sizeof( struct V_11 * ) ,
V_77 ) ;
if ( ! V_2 -> V_10 . V_17 )
goto V_78;
V_29 = F_46 ( V_2 -> V_18 -> V_19 ,
( V_2 -> V_10 . V_3 * sizeof( V_2 -> V_10 . V_37 ) ) ,
& V_20 , V_79 ) ;
if ( ! V_29 )
goto V_80;
V_2 -> V_10 . V_37 = V_29 ;
V_2 -> V_10 . V_48 = V_20 ;
V_29 = F_46 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
& V_20 , V_79 ) ;
if ( ! V_29 )
goto V_81;
V_2 -> V_10 . V_28 . V_29 = V_29 ;
V_2 -> V_10 . V_28 . V_20 = V_20 ;
V_2 -> V_10 . V_46 . V_47 = 0 ;
* V_2 -> V_10 . V_28 . V_29 = 0 ;
F_47 ( V_75 , F_26 , ( unsigned long ) V_2 ) ;
F_48 ( & V_2 -> V_10 . V_39 ) ;
V_2 -> V_10 . V_16 = 0 ;
if ( F_9 ( V_2 , V_2 -> V_10 . V_41 ) )
goto V_82;
F_49 ( V_83 , L_7 ,
V_2 -> V_10 . V_3 , V_2 -> V_10 . V_41 ) ;
return 0 ;
V_82:
F_4 ( V_2 ) ;
F_30 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
V_2 -> V_10 . V_28 . V_29 ,
V_2 -> V_10 . V_28 . V_20 ) ;
V_81:
F_30 ( V_2 -> V_18 -> V_19 ,
( V_2 -> V_10 . V_3 *
sizeof( V_2 -> V_10 . V_37 ) ) ,
V_2 -> V_10 . V_37 ,
V_2 -> V_10 . V_48 ) ;
V_80:
F_31 ( V_2 -> V_10 . V_17 ) ;
V_78:
return - V_32 ;
}
static int F_50 ( enum V_84 type )
{
switch ( type ) {
case V_85 :
case V_86 :
return 4 ;
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
return 8 ;
case V_92 :
return 0 ;
}
F_33 ( L_8 , type ) ;
return 0 ;
}
static int F_51 ( enum V_84 type )
{
switch ( type ) {
case V_92 :
case V_85 :
case V_86 :
case V_88 :
case V_90 :
return 0 ;
case V_87 :
case V_89 :
return 4 ;
case V_91 :
return 8 ;
}
F_33 ( L_8 , type ) ;
return 0 ;
}
static struct V_93 * F_52 ( struct V_11 * V_12 )
{
struct V_24 * V_94 ;
enum V_95 V_96 ;
V_94 = ( void * ) V_12 -> V_34 - sizeof( * V_94 ) ;
V_96 = F_40 ( F_10 ( V_94 -> V_67 . V_97 ) ,
V_98 ) ;
if ( V_96 == V_99 )
return ( void * ) V_12 -> V_34 ;
else
return ( void * ) V_12 -> V_34 - V_100 ;
}
static bool F_53 ( struct V_93 * V_101 )
{
if ( F_54 ( V_101 -> V_102 ) ) {
T_2 * V_103 = F_55 ( V_101 ) ;
if ( V_103 [ 0 ] & 0x80 )
return true ;
}
return false ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_104 * V_105 )
{
struct V_24 * V_94 ;
struct V_11 * V_106 ;
struct V_11 * V_107 ;
struct V_93 * V_101 ;
struct V_11 * V_12 = V_105 -> V_12 ;
enum V_95 V_96 ;
enum V_84 V_108 ;
unsigned int V_109 ;
int V_110 ;
V_94 = ( void * ) V_12 -> V_34 - sizeof( * V_94 ) ;
V_96 = F_40 ( F_10 ( V_94 -> V_67 . V_97 ) ,
V_98 ) ;
V_108 = F_40 ( F_10 ( V_94 -> V_111 . V_64 ) ,
V_112 ) ;
if ( ( V_96 == V_99 && V_12 -> V_50 ) ||
( V_96 == V_113 ) ) {
F_34 ( V_12 -> V_50 ) ;
V_12 -> V_50 = NULL ;
return - V_114 ;
}
V_106 = F_11 ( 8 * 1024 ) ;
if ( ! V_106 ) {
F_33 ( L_9 ) ;
F_34 ( V_12 -> V_50 ) ;
V_12 -> V_50 = NULL ;
return - V_32 ;
}
if ( V_96 >= V_115 ) {
int V_116 ;
V_101 = ( void * ) V_94 -> V_117 ;
V_116 = F_57 ( V_101 -> V_102 ) ;
memcpy ( F_37 ( V_106 , V_116 ) , V_101 , V_116 ) ;
}
V_107 = V_12 ;
while ( V_12 ) {
void * V_118 ;
int V_119 = 0 ;
V_94 = ( void * ) V_12 -> V_34 - sizeof( * V_94 ) ;
V_96 = F_40 ( F_10 ( V_94 -> V_67 . V_97 ) ,
V_98 ) ;
V_118 = ( void * ) V_94 -> V_117 ;
if ( V_12 == V_107 ) {
V_101 = ( void * ) V_106 -> V_34 ;
V_109 = F_57 ( V_101 -> V_102 ) ;
V_110 = F_50 ( V_108 ) ;
V_118 += F_58 ( V_109 , 4 ) ;
V_118 += F_58 ( V_110 , 4 ) ;
}
if ( V_96 == V_120 ) {
F_13 ( V_12 , 6 + 6 + 2 ) ;
V_119 += 6 + 6 + 2 ;
V_119 += 8 ;
memcpy ( F_37 ( V_106 , V_119 ) , V_118 , V_119 ) ;
}
if ( V_96 == V_115 ) {
V_101 = (struct V_93 * ) V_12 -> V_34 ;
F_13 ( V_12 , F_57 ( V_101 -> V_102 ) ) ;
V_119 += 6 + 6 + 2 ;
memcpy ( F_37 ( V_106 , V_119 ) , V_118 , V_119 ) ;
}
if ( V_96 == V_99 )
F_41 ( V_12 , V_12 -> V_21 - 4 ) ;
memcpy ( F_37 ( V_106 , V_12 -> V_21 ) , V_12 -> V_34 , V_12 -> V_21 ) ;
if ( V_12 -> V_50 && ( ( V_119 + V_12 -> V_21 ) & 3 ) ) {
int V_121 = 4 - ( ( V_119 + V_12 -> V_21 ) & 3 ) ;
memset ( F_37 ( V_106 , V_121 ) , 0 , V_121 ) ;
}
V_12 = V_12 -> V_50 ;
}
V_105 -> V_12 = V_106 ;
V_105 -> V_122 = V_108 ;
F_34 ( V_107 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
struct V_11 * V_12 = V_105 -> V_12 ;
struct V_24 * V_94 ;
struct V_93 * V_101 ;
enum V_95 V_96 ;
enum V_84 V_108 ;
if ( V_12 -> V_50 ) {
F_33 ( L_10 ) ;
F_34 ( V_12 -> V_50 ) ;
V_12 -> V_50 = NULL ;
}
V_94 = ( void * ) V_12 -> V_34 - sizeof( * V_94 ) ;
V_96 = F_40 ( F_10 ( V_94 -> V_67 . V_97 ) ,
V_98 ) ;
V_108 = F_40 ( F_10 ( V_94 -> V_111 . V_64 ) ,
V_112 ) ;
V_101 = ( void * ) V_12 -> V_34 - V_100 ;
switch ( V_96 ) {
case V_99 :
F_41 ( V_12 , V_12 -> V_21 - 4 ) ;
break;
case V_115 :
break;
case V_120 :
F_13 ( V_12 , 6 + 6 + 2 ) ;
break;
case V_113 :
F_13 ( V_12 , 6 + 6 + 2 ) ;
break;
}
if ( V_96 == V_120 ) {
void * V_123 ;
int V_124 ;
V_124 = 8 ;
V_123 = V_101 ;
V_123 += F_58 ( F_57 ( V_101 -> V_102 ) , 4 ) ;
V_123 += F_58 ( F_50 ( V_108 ) , 4 ) ;
F_60 ( V_12 , V_124 ) ;
memcpy ( V_12 -> V_34 , V_123 , V_124 ) ;
}
if ( V_96 >= V_120 ) {
int V_21 = F_57 ( V_101 -> V_102 ) ;
F_60 ( V_12 , V_21 ) ;
memcpy ( V_12 -> V_34 , V_101 , V_21 ) ;
}
V_105 -> V_12 = V_12 ;
V_105 -> V_122 = V_108 ;
return 0 ;
}
static bool F_61 ( struct V_11 * V_12 )
{
struct V_24 * V_94 ;
T_3 V_36 ;
V_94 = ( void * ) V_12 -> V_34 - sizeof( * V_94 ) ;
V_36 = F_10 ( V_94 -> V_35 . V_36 ) ;
if ( V_36 & V_125 )
return true ;
return false ;
}
static bool F_62 ( struct V_11 * V_12 )
{
struct V_24 * V_94 ;
T_3 V_36 ;
V_94 = ( void * ) V_12 -> V_34 - sizeof( * V_94 ) ;
V_36 = F_10 ( V_94 -> V_35 . V_36 ) ;
if ( V_36 & V_126 )
return true ;
return false ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
struct V_104 V_105 ;
struct V_129 * V_130 ;
struct V_93 * V_101 ;
int V_131 ;
int V_52 ;
T_2 * V_51 ;
int V_15 , V_132 ;
int V_26 ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_52 = F_64 ( V_128 -> V_133 . V_134 ) ;
V_51 = ( T_2 * ) & V_128 -> V_51 ;
V_131 = F_40 ( F_10 ( V_128 -> V_101 . V_97 ) ,
V_135 ) ;
V_130 = F_65 ( V_128 ) ;
F_36 ( V_61 , NULL , L_11 ,
V_128 , sizeof( * V_128 ) +
( sizeof( struct V_129 ) *
V_131 ) ) ;
for ( V_15 = 0 ; V_15 < V_131 ; V_15 ++ ) {
V_105 . V_136 = V_130 [ V_15 ] . V_137 ;
for ( V_132 = 0 ; V_132 < V_130 [ V_15 ] . V_138 ; V_132 ++ ) {
struct V_11 * V_139 , * V_140 ;
enum V_141 V_136 ;
int V_56 ;
V_139 = NULL ;
V_140 = NULL ;
V_56 = F_35 ( V_2 ,
& V_51 ,
& V_52 ,
& V_139 ,
& V_140 ) ;
if ( ! V_139 ) {
F_33 ( L_12 ) ;
continue;
}
if ( V_139 -> V_21 == 0 ) {
F_49 ( V_83 ,
L_13 ) ;
F_34 ( V_139 ) ;
continue;
}
if ( F_61 ( V_139 ) ) {
F_34 ( V_139 ) ;
continue;
}
V_136 = V_105 . V_136 ;
if ( V_136 == V_142 ) {
F_34 ( V_139 ) ;
continue;
}
if ( V_136 != V_143 &&
V_136 != V_144 &&
! V_2 -> V_18 -> V_145 ) {
F_49 ( V_83 ,
L_14 ,
V_136 ) ;
F_34 ( V_139 ) ;
continue;
}
if ( V_56 ) {
F_33 ( L_15 ) ;
F_34 ( V_139 ) ;
continue;
}
V_105 . V_12 = V_139 ;
V_105 . V_146 = F_62 ( V_139 ) ;
V_105 . signal = V_147 ;
V_105 . signal += V_128 -> V_148 . V_149 ;
V_105 . V_150 . V_64 = V_128 -> V_148 . V_64 ;
V_105 . V_150 . V_97 = F_10 ( V_128 -> V_148 . V_97 ) ;
V_105 . V_150 . V_151 = F_10 ( V_128 -> V_148 . V_151 ) ;
V_101 = F_52 ( V_139 ) ;
if ( F_53 ( V_101 ) )
V_26 = F_56 ( V_2 , & V_105 ) ;
else
V_26 = F_59 ( V_2 , & V_105 ) ;
if ( V_26 && ! V_105 . V_146 ) {
F_33 ( L_16 , V_26 ) ;
F_8 ( V_105 . V_12 ) ;
continue;
}
if ( F_53 ( ( void * ) V_105 . V_12 -> V_34 ) )
F_49 ( V_83 , L_17 ) ;
F_36 ( V_61 , NULL , L_18 ,
V_105 . V_12 -> V_34 , V_105 . V_12 -> V_21 ) ;
F_66 ( V_2 -> V_18 , & V_105 ) ;
}
}
F_21 ( V_2 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_152 * V_153 )
{
struct V_11 * V_139 , * V_140 ;
struct V_24 * V_94 ;
enum V_95 V_96 ;
struct V_104 V_105 = {} ;
struct V_93 * V_101 ;
int V_56 ;
bool V_154 ;
bool V_155 ;
T_2 * V_51 ;
int V_52 , V_116 , V_156 ;
int V_157 ;
V_52 = F_64 ( V_153 -> V_134 ) ;
V_51 = ( T_2 * ) V_153 -> V_158 ;
V_139 = NULL ;
V_140 = NULL ;
V_56 = F_35 ( V_2 , & V_51 , & V_52 ,
& V_139 , & V_140 ) ;
F_49 ( V_61 , L_19 ) ;
if ( ! V_139 ) {
F_33 ( L_20 ) ;
return;
}
if ( V_56 || V_139 != V_140 ) {
F_33 ( L_21 ) ;
F_34 ( V_139 ) ;
return;
}
V_101 = (struct V_93 * ) V_139 -> V_34 ;
V_94 = ( void * ) V_139 -> V_34 - sizeof( * V_94 ) ;
V_154 = ! ! ( F_10 ( V_94 -> V_35 . V_36 ) &
V_159 ) ;
V_155 = ! ! ( F_10 ( V_94 -> V_35 . V_36 ) &
V_125 ) ;
V_96 = F_40 ( F_10 ( V_94 -> V_67 . V_97 ) ,
V_98 ) ;
if ( V_96 != V_99 ) {
F_33 ( L_22 ) ;
F_8 ( V_139 ) ;
goto V_160;
}
V_105 . V_12 = V_139 ;
V_105 . V_136 = V_143 ;
V_105 . V_122 = F_40 ( F_10 ( V_94 -> V_111 . V_64 ) ,
V_112 ) ;
if ( V_154 ) {
F_33 ( L_23 ) ;
V_105 . V_136 = V_144 ;
}
if ( V_155 ) {
F_33 ( L_24 ) ;
F_8 ( V_105 . V_12 ) ;
goto V_160;
}
if ( V_105 . V_122 != V_92 ) {
V_116 = F_57 ( V_101 -> V_102 ) ;
V_156 = F_50 ( V_105 . V_122 ) ;
memmove ( ( void * ) V_105 . V_12 -> V_34 + V_156 ,
( void * ) V_105 . V_12 -> V_34 ,
V_116 ) ;
F_13 ( V_105 . V_12 , V_156 ) ;
V_101 = (struct V_93 * ) V_105 . V_12 -> V_34 ;
}
V_157 = 4 ;
V_157 += F_51 ( V_105 . V_122 ) ;
if ( ! F_68 ( V_101 -> V_102 ) &&
V_105 . V_122 == V_89 )
V_157 += 8 ;
if ( V_157 > V_105 . V_12 -> V_21 ) {
F_33 ( L_25 ) ;
F_8 ( V_105 . V_12 ) ;
goto V_160;
}
F_41 ( V_105 . V_12 , V_105 . V_12 -> V_21 - V_157 ) ;
F_36 ( V_61 , NULL , L_26 ,
V_105 . V_12 -> V_34 , V_105 . V_12 -> V_21 ) ;
F_66 ( V_2 -> V_18 , & V_105 ) ;
V_160:
if ( V_52 > 0 ) {
F_49 ( V_83 ,
L_27 ,
V_52 ) ;
}
}
void F_69 ( struct V_161 * V_18 , struct V_11 * V_12 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_162 * V_163 = (struct V_162 * ) V_12 -> V_34 ;
if ( ! F_12 ( ( unsigned long ) V_12 -> V_34 , 4 ) )
F_33 ( L_28 ) ;
F_49 ( V_83 , L_29 ,
V_163 -> V_101 . V_164 ) ;
switch ( V_163 -> V_101 . V_164 ) {
case V_165 : {
V_2 -> V_166 = V_163 -> V_167 . V_168 ;
V_2 -> V_169 = V_163 -> V_167 . V_170 ;
F_70 ( & V_2 -> V_171 ) ;
break;
}
case V_172 : {
F_63 ( V_2 , & V_163 -> V_173 ) ;
break;
}
case V_174 : {
struct V_175 V_176 = {
. V_177 = V_163 -> V_178 . V_177 ,
. V_179 = F_64 ( V_163 -> V_178 . V_179 ) ,
} ;
memcpy ( V_176 . V_180 , V_163 -> V_178 . V_180 , sizeof( V_176 . V_180 ) ) ;
F_71 ( V_2 , & V_176 ) ;
break;
}
case V_181 : {
struct V_182 V_176 = {
. V_179 = F_64 ( V_163 -> V_183 . V_179 ) ,
} ;
F_72 ( V_2 , & V_176 ) ;
break;
}
case V_184 : {
struct V_185 V_186 = {} ;
int V_136 = F_10 ( V_163 -> V_187 . V_136 ) ;
V_186 . V_188 =
F_10 ( V_163 -> V_187 . V_189 ) ;
switch ( V_136 ) {
case V_190 :
break;
case V_191 :
V_186 . V_192 = true ;
break;
case V_193 :
V_186 . V_194 = true ;
break;
}
F_73 ( V_2 , & V_186 ) ;
break;
}
case V_195 : {
struct V_185 V_186 = {} ;
int V_136 = F_40 ( V_163 -> V_196 . V_36 ,
V_197 ) ;
T_4 V_188 ;
int V_15 ;
switch ( V_136 ) {
case V_198 :
V_186 . V_192 = true ;
break;
case V_199 :
break;
case V_200 :
case V_201 :
case V_202 :
V_186 . V_194 = true ;
break;
default:
F_33 ( L_30 ,
V_136 ) ;
V_186 . V_194 = true ;
break;
}
F_49 ( V_83 , L_31 ,
V_163 -> V_196 . V_203 ) ;
for ( V_15 = 0 ; V_15 < V_163 -> V_196 . V_203 ; V_15 ++ ) {
V_188 = V_163 -> V_196 . V_204 [ V_15 ] ;
V_186 . V_188 = F_64 ( V_188 ) ;
F_73 ( V_2 , & V_186 ) ;
}
break;
}
case V_205 : {
struct V_161 * V_18 = V_2 -> V_18 ;
struct V_206 * V_176 = & V_163 -> V_207 ;
F_49 ( V_83 ,
L_32 ,
F_64 ( V_176 -> V_179 ) ,
! ! ( V_176 -> V_36 & V_208 ) ,
F_40 ( V_176 -> V_36 , V_209 ) ) ;
F_70 ( & V_18 -> V_210 ) ;
break;
}
case V_211 : {
F_36 ( V_61 , NULL , L_33 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
F_67 ( V_2 , & V_163 -> V_212 ) ;
break;
}
case V_213 :
break;
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
default:
F_49 ( V_83 , L_34 ,
V_163 -> V_101 . V_164 ) ;
F_36 ( V_61 , NULL , L_33 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
break;
} ;
F_8 ( V_12 ) ;
}
