static void F_1 ( struct V_1 * V_2 , unsigned short V_3 )
{
unsigned short V_4 ;
F_2 ( V_3 != V_2 -> V_3 ) ;
V_2 -> V_5 = V_3 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_2 -> V_6 [ V_4 ] = V_3 - 1 - V_4 ;
}
static unsigned short F_3 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
F_2 ( V_2 -> V_5 <= 0 ) ;
return V_2 -> V_6 [ -- V_2 -> V_5 ] ;
}
static void F_4 ( struct V_7 * V_8 , struct V_1 * V_2 ,
unsigned short V_9 )
{
F_2 ( V_2 -> V_5 >= V_2 -> V_3 ) ;
V_2 -> V_6 [ V_2 -> V_5 ++ ] = V_9 ;
}
static bool F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 == 0 )
return 1 ;
else
return 0 ;
}
static void F_6 ( struct V_10 * V_11 , void * * V_12 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_13 ; V_4 ++ )
if ( ( F_7 ( V_11 , V_4 ) & V_14 ) &&
V_12 [ V_4 ] )
F_8 ( V_11 , V_12 [ V_4 ] ) ;
}
static int F_9 ( struct V_10 * V_11 , void * * V_12 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_13 ; V_4 ++ ) {
if ( F_7 ( V_11 , V_4 ) & V_14 ) {
V_12 [ V_4 ] = F_10 ( V_11 , V_4 , 0 ) ;
if ( ! V_12 [ V_4 ] ) {
F_11 ( & V_11 -> V_11 , L_1 ,
V_4 ) ;
F_6 ( V_11 , V_12 ) ;
return - V_15 ;
}
} else
V_12 [ V_4 ] = NULL ;
F_12 ( & V_11 -> V_11 , L_2 , V_4 , V_12 [ V_4 ] ) ;
}
return 0 ;
}
static struct V_16 * F_13 ( struct V_7 * V_8 ,
enum V_17 type , unsigned int V_3 )
{
struct V_16 * V_18 = F_14 ( sizeof( * V_18 ) , V_19 ) ;
if ( ! V_18 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_3 ) ;
return NULL ;
}
switch ( type ) {
case V_21 :
V_18 -> V_22 = F_14 ( V_3 , V_19 ) ;
if ( ! V_18 -> V_22 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_4 , V_3 ) ;
F_15 ( V_18 ) ;
return NULL ;
}
break;
case V_23 :
V_3 = F_16 ( V_3 , 8 ) ;
V_18 -> V_22 = F_17 ( V_8 -> V_20 , V_3 ,
& V_18 -> V_24 ) ;
if ( ! V_18 -> V_22 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_5
L_6 , V_3 ) ;
F_15 ( V_18 ) ;
return NULL ;
}
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_7 , type ) ;
F_15 ( V_18 ) ;
return NULL ;
}
V_18 -> type = type ;
V_18 -> V_3 = V_3 ;
F_18 ( & V_18 -> V_25 ) ;
F_19 ( & V_18 -> V_25 , & V_8 -> V_26 ) ;
return V_18 ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_16 * V_18 , * V_27 ;
F_21 (res, tmp, &mhba->res_list, entry) {
switch ( V_18 -> type ) {
case V_23 :
F_22 ( V_8 -> V_20 , V_18 -> V_3 ,
V_18 -> V_22 , V_18 -> V_24 ) ;
break;
case V_21 :
F_15 ( V_18 -> V_22 ) ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 ,
L_8 , V_18 -> type ) ;
break;
}
F_23 ( & V_18 -> V_25 ) ;
F_15 ( V_18 ) ;
}
V_8 -> V_28 &= ~ V_29 ;
}
static int F_24 ( struct V_7 * V_8 , struct V_30 * V_31 ,
void * V_32 , unsigned char * V_33 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 = (struct V_36 * ) V_32 ;
unsigned int V_4 ;
unsigned int V_38 = F_25 ( V_31 ) ;
T_1 V_39 ;
V_35 = F_26 ( V_31 ) ;
* V_33 = F_27 ( V_8 -> V_20 , V_35 , V_38 ,
( int ) V_31 -> V_40 ) ;
if ( * V_33 > V_8 -> V_41 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_9 ,
* V_33 , V_8 -> V_41 ) ;
F_28 ( V_8 -> V_20 , V_35 , V_38 ,
( int ) V_31 -> V_40 ) ;
return - 1 ;
}
for ( V_4 = 0 ; V_4 < * V_33 ; V_4 ++ ) {
V_39 = F_29 ( & V_35 [ V_4 ] ) ;
V_37 -> V_42 = F_30 ( F_31 ( V_39 ) ) ;
V_37 -> V_43 = F_30 ( F_32 ( V_39 ) ) ;
V_37 -> V_44 = 0 ;
F_33 ( V_8 , V_37 , F_30 ( F_34 ( & V_35 [ V_4 ] ) ) ) ;
if ( ( V_4 + 1 ) == * V_33 )
V_37 -> V_44 |= 1U << V_8 -> V_45 ;
F_35 ( V_8 , V_37 ) ;
}
return 0 ;
}
static int F_36 ( struct V_7 * V_8 , struct V_46 * V_47 ,
unsigned int V_3 )
{
struct V_36 * V_37 ;
void * V_22 ;
T_1 V_48 ;
if ( V_3 == 0 )
return 0 ;
V_22 = F_17 ( V_8 -> V_20 , V_3 , & V_48 ) ;
if ( ! V_22 )
return - 1 ;
V_37 = (struct V_36 * ) & V_47 -> V_49 -> V_50 [ 0 ] ;
V_47 -> V_49 -> V_51 = 1 ;
V_47 -> V_52 = V_22 ;
V_37 -> V_42 = F_30 ( F_31 ( V_48 ) ) ;
V_37 -> V_43 = F_30 ( F_32 ( V_48 ) ) ;
V_37 -> V_44 = 1U << V_8 -> V_45 ;
F_33 ( V_8 , V_37 , F_30 ( V_3 ) ) ;
return 0 ;
}
static struct V_46 * F_37 ( struct V_7 * V_8 ,
unsigned int V_53 )
{
struct V_46 * V_47 ;
V_47 = F_14 ( sizeof( * V_47 ) , V_54 ) ;
if ( ! V_47 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_10 ) ;
return NULL ;
}
F_18 ( & V_47 -> V_55 ) ;
V_47 -> V_49 = F_38 ( V_8 -> V_20 ,
V_8 -> V_56 , & V_47 -> V_57 ) ;
if ( ! V_47 -> V_49 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_11
L_12 , V_8 -> V_56 ) ;
F_15 ( V_47 ) ;
return NULL ;
}
if ( V_53 ) {
if ( F_36 ( V_8 , V_47 , V_53 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_13
L_14 ) ;
F_22 ( V_8 -> V_20 , V_8 -> V_56 ,
V_47 -> V_49 , V_47 -> V_57 ) ;
F_15 ( V_47 ) ;
return NULL ;
}
} else
V_47 -> V_49 -> V_51 = 0 ;
return V_47 ;
}
static void F_39 ( struct V_7 * V_8 ,
struct V_46 * V_47 )
{
struct V_36 * V_37 ;
unsigned int V_3 ;
T_1 V_48 ;
if ( V_47 && V_47 -> V_49 ) {
if ( V_47 -> V_49 -> V_51 ) {
V_37 = (struct V_36 * ) & V_47 -> V_49 -> V_50 [ 0 ] ;
F_40 ( V_8 , V_37 , V_3 ) ;
V_48 = ( T_1 ) V_37 -> V_42 |
( T_1 ) ( ( V_37 -> V_43 << 16 ) << 16 ) ;
F_22 ( V_8 -> V_20 , V_3 , V_47 -> V_52 ,
V_48 ) ;
}
F_22 ( V_8 -> V_20 , V_8 -> V_56 ,
V_47 -> V_49 , V_47 -> V_57 ) ;
F_15 ( V_47 ) ;
}
}
static struct V_46 * F_41 ( struct V_7 * V_8 )
{
struct V_46 * V_47 = NULL ;
if ( F_42 ( ! F_43 ( & V_8 -> V_58 ) ) ) {
V_47 = F_44 ( ( & V_8 -> V_58 ) -> V_59 ,
struct V_46 , V_55 ) ;
F_45 ( & V_47 -> V_55 ) ;
} else
F_46 ( & V_8 -> V_20 -> V_11 , L_15 ) ;
return V_47 ;
}
static inline void F_47 ( struct V_7 * V_8 ,
struct V_46 * V_47 )
{
V_47 -> V_31 = NULL ;
F_19 ( & V_47 -> V_55 , & V_8 -> V_58 ) ;
}
static void F_48 ( struct V_7 * V_8 )
{
struct V_46 * V_47 ;
while ( ! F_43 ( & V_8 -> V_58 ) ) {
V_47 = F_49 ( & V_8 -> V_58 , struct V_46 ,
V_55 ) ;
F_23 ( & V_47 -> V_55 ) ;
if ( ! ( V_8 -> V_60 & V_61 ) )
F_15 ( V_47 -> V_49 ) ;
F_15 ( V_47 ) ;
}
}
static int F_50 ( struct V_7 * V_8 )
{
int V_4 ;
struct V_46 * V_47 ;
for ( V_4 = 0 ; V_4 < V_8 -> V_62 ; V_4 ++ ) {
V_47 = F_14 ( sizeof( * V_47 ) , V_54 ) ;
if ( ! V_47 )
goto V_63;
F_18 ( & V_47 -> V_55 ) ;
F_19 ( & V_47 -> V_55 , & V_8 -> V_58 ) ;
if ( V_8 -> V_60 & V_61 ) {
V_47 -> V_49 = V_8 -> V_64 + V_4 * V_8 -> V_56 ;
V_47 -> V_57 = V_8 -> V_65
+ V_4 * V_8 -> V_56 ;
} else
V_47 -> V_49 = F_14 ( V_8 -> V_56 , V_54 ) ;
if ( ! V_47 -> V_49 )
goto V_63;
}
return 0 ;
V_63:
F_11 ( & V_8 -> V_20 -> V_11 ,
L_16 , V_4 ) ;
while ( ! F_43 ( & V_8 -> V_58 ) ) {
V_47 = F_49 ( & V_8 -> V_58 , struct V_46 ,
V_55 ) ;
F_23 ( & V_47 -> V_55 ) ;
if ( ! ( V_8 -> V_60 & V_61 ) )
F_15 ( V_47 -> V_49 ) ;
F_15 ( V_47 ) ;
}
return - V_15 ;
}
static unsigned int F_51 ( struct V_7 * V_8 )
{
unsigned int V_66 ;
struct V_67 * V_68 = V_8 -> V_68 ;
V_66 = F_52 ( V_8 -> V_68 -> V_69 ) ;
if ( F_53 ( ( ( V_66 & V_68 -> V_70 ) ==
( V_8 -> V_71 & V_68 -> V_70 ) ) &&
( ( V_66 & V_68 -> V_72 )
!= ( V_8 -> V_71 & V_68 -> V_72 ) ) ) ) {
F_46 ( & V_8 -> V_20 -> V_11 , L_17 ) ;
return 0 ;
}
if ( F_54 ( & V_8 -> V_73 ) >= V_8 -> V_62 ) {
F_46 ( & V_8 -> V_20 -> V_11 , L_18 ) ;
return 0 ;
} else {
return V_8 -> V_62 - F_54 ( & V_8 -> V_73 ) ;
}
}
static unsigned int F_55 ( struct V_7 * V_8 )
{
unsigned int V_74 ;
if ( F_54 ( & V_8 -> V_73 ) >= ( V_8 -> V_62 - 1 ) )
return 0 ;
V_74 = F_52 ( V_8 -> V_75 ) ;
if ( V_74 == 0xffff )
return 0 ;
return V_74 ;
}
static void F_56 ( struct V_7 * V_8 , void * * V_76 )
{
unsigned int V_77 ;
V_77 = V_8 -> V_71 & V_8 -> V_68 -> V_70 ;
V_77 ++ ;
if ( V_77 >= V_8 -> V_78 ) {
V_77 -= V_8 -> V_78 ;
V_8 -> V_71 ^= V_8 -> V_68 -> V_72 ;
}
V_8 -> V_71 &= ~ V_8 -> V_68 -> V_70 ;
V_8 -> V_71 |= ( V_77 & V_8 -> V_68 -> V_70 ) ;
if ( V_8 -> V_60 & V_61 ) {
* V_76 = V_8 -> V_79 + V_77 *
sizeof( struct V_80 ) ;
} else {
* V_76 = V_8 -> V_79 + V_77 * V_8 -> V_56 ;
}
F_57 ( & V_8 -> V_73 ) ;
}
static void F_58 ( struct V_7 * V_8 )
{
F_59 ( 0xffff , V_8 -> V_75 ) ;
F_59 ( V_8 -> V_71 , V_8 -> V_68 -> V_81 ) ;
}
static char F_60 ( struct V_7 * V_8 ,
unsigned int V_82 , struct V_83 * V_84 )
{
unsigned short V_9 , V_85 ;
F_61 ( 1 ) ;
V_84 = V_8 -> V_86 + V_82 * V_8 -> V_87 ;
V_85 = V_84 -> V_85 ;
V_9 = V_84 -> V_9 ;
if ( V_9 > V_8 -> V_88 . V_3 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_19 ) ;
return - 1 ;
}
if ( V_8 -> V_89 [ V_9 ] == NULL ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_20 , V_9 ) ;
return - 1 ;
} else if ( V_8 -> V_89 [ V_9 ] -> V_85 != V_85 &&
V_8 -> V_90 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_21
L_22 , V_85 ,
V_8 -> V_89 [ V_9 ] -> V_85 ) ;
return - 1 ;
}
return 0 ;
}
static int F_62 ( struct V_7 * V_8 ,
unsigned int * V_82 , unsigned int * V_91 )
{
unsigned int V_92 , V_93 ;
struct V_67 * V_68 = V_8 -> V_68 ;
do {
V_92 = F_52 ( V_68 -> V_94 ) ;
V_93 = F_52 ( V_8 -> V_95 ) ;
} while ( ( V_92 & V_68 -> V_70 ) != V_93 );
* V_82 = V_8 -> V_96 & V_8 -> V_68 -> V_70 ;
* V_91 = V_92 & V_8 -> V_68 -> V_70 ;
if ( ( V_92 & V_68 -> V_72 ) !=
( V_8 -> V_96 & V_68 -> V_72 ) ) {
* V_91 += V_8 -> V_78 ;
}
return 0 ;
}
static int F_63 ( struct V_7 * V_8 ,
unsigned int * V_82 , unsigned int * V_91 )
{
unsigned int V_92 ;
struct V_67 * V_68 = V_8 -> V_68 ;
V_92 = F_52 ( V_68 -> V_97 ) ;
V_92 = F_52 ( V_68 -> V_94 ) ;
* V_82 = V_8 -> V_96 & V_8 -> V_68 -> V_70 ;
* V_91 = V_92 & V_8 -> V_68 -> V_70 ;
if ( * V_91 < * V_82 )
* V_91 += V_8 -> V_78 ;
else if ( * V_91 == * V_82 )
return - 1 ;
return 0 ;
}
static void F_64 ( struct V_7 * V_8 )
{
unsigned int V_82 , V_91 , V_4 ;
struct V_98 * V_99 ;
struct V_83 * V_84 ;
struct V_67 * V_68 = V_8 -> V_68 ;
if ( V_8 -> V_100 -> V_101 ( V_8 , & V_82 , & V_91 ) )
return;
for ( V_4 = ( V_91 - V_82 ) ; V_4 != 0 ; V_4 -- ) {
V_82 ++ ;
if ( V_82 >= V_8 -> V_78 ) {
V_82 -= V_8 -> V_78 ;
V_8 -> V_96 ^= V_68 -> V_72 ;
}
V_84 = V_8 -> V_86 + V_82 * V_8 -> V_87 ;
if ( F_53 ( V_84 -> V_9 > V_8 -> V_88 . V_3 ||
V_8 -> V_89 [ V_84 -> V_9 ] == NULL ||
V_84 -> V_85 !=
V_8 -> V_89 [ V_84 -> V_9 ] -> V_85 ) )
if ( F_60 ( V_8 , V_82 , V_84 ) )
continue;
if ( ! F_43 ( & V_8 -> V_102 ) ) {
V_99 = (struct V_98 * )
F_49 ( & V_8 -> V_102 ,
struct V_98 , V_103 ) ;
F_45 ( & V_99 -> V_103 ) ;
} else {
V_99 = NULL ;
if ( V_82 == 0 ) {
V_82 = V_8 -> V_78 - 1 ;
V_8 -> V_96 ^= V_68 -> V_72 ;
} else
V_82 -= 1 ;
break;
}
memcpy ( V_99 -> V_104 , V_84 , V_8 -> V_87 ) ;
V_84 -> V_9 = 0xff ;
F_19 ( & V_99 -> V_103 , & V_8 -> V_105 ) ;
}
V_8 -> V_96 &= ~ V_68 -> V_70 ;
V_8 -> V_96 |= ( V_82 & V_68 -> V_70 ) ;
F_59 ( V_8 -> V_96 , V_68 -> V_97 ) ;
}
static void F_65 ( struct V_7 * V_8 )
{
struct V_67 * V_68 = V_8 -> V_68 ;
F_59 ( 0 , V_68 -> V_106 ) ;
if ( F_52 ( V_68 -> V_107 ) != V_108 )
return;
F_59 ( V_109 , V_68 -> V_110 ) ;
}
static int F_66 ( struct V_7 * V_8 )
{
V_8 -> V_111 = V_112 ;
F_65 ( V_8 ) ;
if ( F_67 ( V_8 ) )
return V_113 ;
else
return V_114 ;
}
static int F_68 ( struct V_7 * V_8 )
{
struct V_67 * V_68 = V_8 -> V_68 ;
T_2 V_27 ;
unsigned long V_115 ;
V_115 = V_116 ;
F_59 ( 0 , V_68 -> V_106 ) ;
V_27 = F_52 ( V_68 -> V_107 ) ;
while ( V_27 != V_117 ) {
F_59 ( V_118 , V_68 -> V_110 ) ;
if ( F_69 ( V_116 , V_115 + V_119 * V_120 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_23 , V_27 ) ;
return V_113 ;
}
F_70 ( 500 ) ;
F_71 () ;
V_27 = F_52 ( V_68 -> V_107 ) ;
}
return V_114 ;
}
static void F_72 ( struct V_7 * V_8 )
{
unsigned char V_4 ;
for ( V_4 = 0 ; V_4 < V_13 ; V_4 ++ ) {
F_73 ( V_8 -> V_20 , 0x10 + V_4 * 4 ,
& V_8 -> V_121 [ V_4 ] ) ;
}
}
static void F_74 ( struct V_7 * V_8 )
{
unsigned char V_4 ;
for ( V_4 = 0 ; V_4 < V_13 ; V_4 ++ ) {
if ( V_8 -> V_121 [ V_4 ] )
F_75 ( V_8 -> V_20 , 0x10 + V_4 * 4 ,
V_8 -> V_121 [ V_4 ] ) ;
}
}
static unsigned int F_76 ( struct V_10 * V_20 )
{
unsigned int V_122 = 0 ;
F_77 ( V_20 ) ;
if ( V_123 ) {
if ( F_78 ( V_20 , F_79 ( 64 ) ) )
V_122 = F_78 ( V_20 , F_79 ( 32 ) ) ;
} else
V_122 = F_78 ( V_20 , F_79 ( 32 ) ) ;
return V_122 ;
}
static int F_80 ( struct V_7 * V_8 )
{
V_8 -> V_111 = V_112 ;
F_59 ( 0 , V_8 -> V_68 -> V_124 ) ;
F_59 ( 0xf , V_8 -> V_68 -> V_125 ) ;
F_59 ( 0x10 , V_8 -> V_68 -> V_124 ) ;
F_59 ( 0x10 , V_8 -> V_68 -> V_125 ) ;
F_70 ( 100 ) ;
F_81 ( V_8 -> V_20 ) ;
if ( F_82 ( V_8 -> V_20 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_24 ) ;
return V_113 ;
}
if ( F_76 ( V_8 -> V_20 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_25 ) ;
return V_113 ;
}
F_74 ( V_8 ) ;
if ( F_68 ( V_8 ) == V_113 )
return V_113 ;
return F_66 ( V_8 ) ;
}
static int F_83 ( struct V_7 * V_8 )
{
return F_66 ( V_8 ) ;
}
static int F_84 ( struct V_30 * V_31 )
{
struct V_7 * V_8 ;
V_8 = (struct V_7 * ) V_31 -> V_126 -> V_127 -> V_128 ;
F_85 ( V_129 , V_31 , L_26 ,
V_31 -> V_130 , V_31 -> V_131 [ 0 ] , V_31 -> V_132 ) ;
return V_8 -> V_100 -> V_133 ( V_8 ) ;
}
static int F_86 ( struct V_7 * V_8 ,
struct V_46 * V_47 )
{
unsigned long V_44 ;
V_47 -> V_134 = V_135 ;
if ( F_54 ( & V_47 -> V_136 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_27 ,
F_54 ( & V_47 -> V_136 ) ) ;
F_2 ( 1 ) ;
return - 1 ;
}
F_57 ( & V_47 -> V_136 ) ;
F_87 ( V_8 -> V_137 -> V_138 , V_44 ) ;
V_8 -> V_100 -> V_139 ( V_8 , V_47 ) ;
F_88 ( V_8 -> V_137 -> V_138 , V_44 ) ;
F_89 ( V_8 -> V_140 ,
( V_47 -> V_134 != V_135 ) ,
V_141 * V_120 ) ;
if ( F_54 ( & V_47 -> V_136 ) ) {
F_87 ( V_8 -> V_137 -> V_138 , V_44 ) ;
F_90 ( & V_47 -> V_136 ) ;
if ( V_8 -> V_89 [ V_47 -> V_49 -> V_9 ] ) {
V_8 -> V_89 [ V_47 -> V_49 -> V_9 ] = 0 ;
F_46 ( & V_8 -> V_20 -> V_11 , L_28 ,
V_47 -> V_49 -> V_9 ) ;
F_4 ( V_8 , & V_8 -> V_88 , V_47 -> V_49 -> V_9 ) ;
}
if ( ! F_43 ( & V_47 -> V_55 ) ) {
F_46 ( & V_8 -> V_20 -> V_11 ,
L_29 ) ;
F_45 ( & V_47 -> V_55 ) ;
} else
F_90 ( & V_8 -> V_73 ) ;
F_88 ( V_8 -> V_137 -> V_138 , V_44 ) ;
}
return 0 ;
}
static void F_91 ( struct V_7 * V_8 )
{
F_48 ( V_8 ) ;
F_20 ( V_8 ) ;
F_6 ( V_8 -> V_20 , V_8 -> V_142 ) ;
F_22 ( V_8 -> V_20 , V_143 ,
V_8 -> V_144 , V_8 -> V_145 ) ;
F_15 ( V_8 -> V_68 ) ;
F_92 ( V_8 -> V_20 ) ;
}
static unsigned char F_93 ( struct V_7 * V_8 )
{
struct V_46 * V_47 ;
struct V_146 * V_49 ;
unsigned char V_147 , V_148 = 0 ;
unsigned char V_149 = sizeof( unsigned char ) * 8 ;
for ( V_147 = 0 ; V_147 < V_8 -> V_150 ; V_147 ++ ) {
if ( ! ( V_8 -> V_151 [ V_147 / V_149 ] &
( 1 << ( V_147 % V_149 ) ) ) )
continue;
V_152: V_47 = F_37 ( V_8 , 0 ) ;
if ( ! V_47 ) {
if ( V_148 ++ >= 5 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_30
L_31
L_32 , V_147 ) ;
V_148 = 0 ;
continue;
} else
goto V_152;
}
V_47 -> V_31 = NULL ;
V_47 -> V_134 = V_135 ;
F_94 ( & V_47 -> V_136 , 0 ) ;
V_49 = V_47 -> V_49 ;
V_49 -> V_153 = V_154 ;
V_49 -> V_147 = V_147 ;
V_49 -> V_155 = V_156 ;
V_49 -> V_157 = 0 ;
V_49 -> V_158 = V_159 ;
memset ( V_49 -> V_160 , 0 , V_159 ) ;
V_49 -> V_160 [ 0 ] = V_161 ;
V_49 -> V_160 [ 1 ] = V_162 ;
V_49 -> V_160 [ 2 ] = V_163 ;
F_86 ( V_8 , V_47 ) ;
if ( V_47 -> V_134 != V_164 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_33 ,
V_147 , V_47 -> V_134 ) ;
}
F_39 ( V_8 , V_47 ) ;
}
return 0 ;
}
static unsigned char
F_95 ( struct V_165 * V_166 ,
unsigned short V_167 )
{
unsigned char * V_168 ;
unsigned char V_122 = 0 , V_4 ;
V_168 = ( unsigned char * ) V_166 -> V_169 ;
for ( V_4 = 0 ; V_4 < V_167 ; V_4 ++ ) {
V_122 ^= * V_168 ;
V_168 ++ ;
}
return V_122 ;
}
static void F_96 ( struct V_7 * V_8 ,
struct V_165 * V_170 )
{
struct V_171 * V_172 ;
struct V_173 * V_174 ;
struct V_175 * V_176 ;
T_3 time ;
T_3 V_177 ;
switch ( V_170 -> V_178 ) {
case V_179 :
V_172 = (struct V_171 * ) V_170 ;
V_170 -> V_180 = sizeof( * V_172 ) - 4 ;
memset ( V_170 -> V_169 , 0 , V_170 -> V_180 ) ;
V_172 -> V_181 = 3 ;
if ( V_8 -> V_60 & V_61 )
V_172 -> V_182 = 0x08 ;
V_172 -> V_183 . V_184 = V_185 ;
V_172 -> V_183 . V_186 = V_187 ;
V_172 -> V_183 . V_188 = V_189 ;
V_172 -> V_183 . V_190 = V_191 ;
V_172 -> V_192 = 0 ;
V_172 -> V_193 = 0 ;
V_172 -> V_194 = 0 ;
V_172 -> V_195 = 0 ;
time = F_97 () ;
V_177 = ( time - ( V_196 . V_197 * 60 ) ) ;
V_172 -> V_198 = V_177 ;
V_170 -> V_199 = F_95 ( V_170 ,
V_170 -> V_180 ) ;
break;
case V_200 :
V_176 = (struct V_175 * ) V_170 ;
V_170 -> V_180 = sizeof( * V_176 ) - 4 ;
memset ( V_170 -> V_169 , 0 , V_170 -> V_180 ) ;
V_170 -> V_199 = F_95 ( V_170 ,
V_170 -> V_180 ) ;
break;
case V_201 :
V_174 = (struct V_173 * ) V_170 ;
V_170 -> V_180 = sizeof( * V_174 ) - 4 ;
memset ( V_170 -> V_169 , 0 , V_170 -> V_180 ) ;
V_174 -> V_202 = F_31 ( V_8 -> V_203 ) ;
V_174 -> V_204 = F_32 ( V_8 -> V_203 ) ;
V_174 -> V_205 = F_31 ( V_8 -> V_206 ) ;
V_174 -> V_207 = F_32 ( V_8 -> V_206 ) ;
V_174 -> V_208 = V_8 -> V_209 ;
V_174 -> V_210 = V_8 -> V_211 ;
if ( V_8 -> V_60
& V_212 ) {
V_174 -> V_213 = F_98 ( ( unsigned long * )
& V_8 -> V_78 ,
V_214 ) ;
V_174 -> V_215 = F_98 ( ( unsigned long * )
& V_8 -> V_78 ,
V_214 ) ;
} else {
V_174 -> V_213 = ( V_216 ) V_8 -> V_78 ;
V_174 -> V_215 = ( V_216 ) V_8 -> V_78 ;
}
V_170 -> V_199 = F_95 ( V_170 ,
V_170 -> V_180 ) ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_34 ,
V_170 -> V_178 ) ;
break;
}
}
static int F_99 ( struct V_7 * V_8 )
{
struct V_98 * V_217 ;
struct V_16 * V_218 ;
unsigned int V_219 , V_220 , V_4 ;
void * V_221 , * V_222 ;
T_1 V_223 ;
if ( V_8 -> V_28 & V_29 )
return 0 ;
V_219 = V_8 -> V_56 * V_8 -> V_62 ;
if ( V_8 -> V_60 & V_61 )
V_219 += sizeof( struct V_80 ) * V_8 -> V_62 ;
V_219 += 128 + V_8 -> V_87 * V_8 -> V_62 ;
V_219 += 8 + sizeof( T_2 ) * 2 + 16 ;
V_218 = F_13 ( V_8 ,
V_23 , V_219 ) ;
if ( ! V_218 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_35 ) ;
goto V_224;
}
V_223 = V_218 -> V_24 ;
V_222 = V_218 -> V_22 ;
V_220 = F_16 ( V_223 , 128 ) - V_223 ;
V_223 += V_220 ;
V_222 += V_220 ;
V_8 -> V_79 = V_222 ;
V_8 -> V_203 = V_223 ;
if ( V_8 -> V_60 & V_61 ) {
V_222 += sizeof( struct V_80 ) * V_8 -> V_62 ;
V_223 += sizeof( struct V_80 ) * V_8 -> V_62 ;
V_8 -> V_64 = V_222 ;
V_8 -> V_65 = V_223 ;
}
V_222 += V_8 -> V_56 * V_8 -> V_62 ;
V_223 += V_8 -> V_56 * V_8 -> V_62 ;
V_220 = F_16 ( V_223 , 8 ) - V_223 ;
V_223 += V_220 ;
V_222 += V_220 ;
V_8 -> V_75 = V_222 ;
V_8 -> V_225 = V_223 ;
V_223 += sizeof( T_2 ) * 2 ;
V_222 += sizeof( T_2 ) * 2 ;
if ( V_8 -> V_20 -> V_126 == V_226 ) {
V_220 = F_16 ( V_223 , 8 ) - V_223 ;
V_223 += V_220 ;
V_222 += V_220 ;
V_8 -> V_95 = V_222 ;
V_8 -> V_227 = V_223 ;
V_223 += 8 ;
V_222 += 8 ;
} else {
V_220 = F_16 ( V_223 , 4 ) - V_223 ;
V_223 += V_220 ;
V_222 += V_220 ;
V_8 -> V_95 = V_222 ;
V_8 -> V_227 = V_223 ;
V_223 += 4 ;
V_222 += 4 ;
}
V_220 = F_16 ( V_223 , 128 ) - V_223 ;
V_223 += V_220 ;
V_222 += V_220 ;
V_8 -> V_86 = V_222 ;
V_8 -> V_206 = V_223 ;
V_219 = V_8 -> V_62 * ( V_8 -> V_87 + sizeof( * V_217 ) ) ;
V_219 = F_16 ( V_219 , 8 ) ;
V_218 = F_13 ( V_8 ,
V_21 , V_219 ) ;
if ( ! V_218 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_36 ) ;
goto V_224;
}
V_221 = V_218 -> V_22 ;
for ( V_4 = V_8 -> V_62 ; V_4 != 0 ; V_4 -- ) {
V_217 = (struct V_98 * ) V_221 ;
F_19 ( & V_217 -> V_103 , & V_8 -> V_102 ) ;
V_221 += V_8 -> V_87 + sizeof( * V_217 ) ;
}
V_219 = sizeof( unsigned short ) * V_8 -> V_62 +
sizeof( struct V_46 * ) * V_8 -> V_62 ;
V_219 += F_16 ( V_8 -> V_150 , sizeof( unsigned char ) * 8 ) /
(sizeof( unsigned char ) * 8 ) ;
V_218 = F_13 ( V_8 ,
V_21 , V_219 ) ;
if ( ! V_218 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_37 ) ;
goto V_224;
}
V_221 = V_218 -> V_22 ;
V_8 -> V_88 . V_6 = V_221 ;
V_8 -> V_88 . V_3 = V_8 -> V_62 ;
F_1 ( & V_8 -> V_88 , V_8 -> V_62 ) ;
V_221 += sizeof( unsigned short ) * V_8 -> V_62 ;
V_8 -> V_89 = V_221 ;
V_221 += sizeof( struct V_46 * ) * V_8 -> V_62 ;
V_8 -> V_151 = V_221 ;
V_8 -> V_28 |= V_29 ;
return 0 ;
V_224:
F_20 ( V_8 ) ;
return - 1 ;
}
static int F_100 ( struct V_7 * V_8 ,
struct V_165 * V_170 )
{
struct V_228 * V_229 ;
unsigned char V_230 ;
V_230 = F_95 ( V_170 ,
V_170 -> V_180 ) ;
if ( V_230 != V_170 -> V_199 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_38 ) ;
return - 1 ;
}
switch ( V_170 -> V_178 ) {
case V_231 :
V_229 = (struct V_228 * ) V_170 ;
V_8 -> V_62 = V_229 -> V_232 ;
V_8 -> V_78 = V_229 -> V_233 ;
V_8 -> V_234 = V_229 -> V_234 ;
V_8 -> V_150 = V_229 -> V_235 ;
V_8 -> V_60 = V_229 -> V_236 ;
V_8 -> V_209 = V_229 -> V_237 ;
V_8 -> V_56 = ( 1 << V_229 -> V_237 ) << 2 ;
V_8 -> V_211 = V_229 -> V_238 ;
V_8 -> V_87 = ( 1 << V_229 -> V_238 ) << 2 ;
F_12 ( & V_8 -> V_20 -> V_11 , L_39 ,
V_229 -> V_239 . V_190 ) ;
if ( V_8 -> V_60 & V_240 )
V_8 -> V_45 = 22 ;
else
V_8 -> V_45 = 27 ;
if ( V_8 -> V_60 & V_212 )
V_8 -> V_78 = 1 << V_229 -> V_233 ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_40 ) ;
return - 1 ;
}
return 0 ;
}
static int F_101 ( struct V_7 * V_8 )
{
unsigned int V_241 , V_27 , V_242 ;
struct V_165 * V_170 ;
struct V_67 * V_68 = V_8 -> V_68 ;
if ( V_8 -> V_111 == V_243 )
V_241 = V_244 ;
else {
V_27 = F_52 ( V_68 -> V_245 ) ;
V_241 = F_102 ( V_27 ) ;
F_12 ( & V_8 -> V_20 -> V_11 , L_41 , V_241 ) ;
if ( F_103 ( V_27 ) != V_246 ) {
V_8 -> V_111 = V_243 ;
return - 1 ;
}
}
V_242 = 0 ;
switch ( V_241 ) {
case V_244 :
V_8 -> V_111 = V_247 ;
F_104 ( V_242 , V_246 ) ;
F_105 ( V_242 , V_248 ) ;
F_59 ( V_249 , V_68 -> V_250 ) ;
F_59 ( V_242 , V_68 -> V_251 ) ;
F_59 ( V_252 , V_68 -> V_110 ) ;
break;
case V_248 :
F_59 ( F_31 ( V_8 -> V_145 ) ,
V_68 -> V_250 ) ;
F_59 ( F_32 ( V_8 -> V_145 ) ,
V_68 -> V_107 ) ;
F_104 ( V_242 , V_246 ) ;
F_105 ( V_242 , V_253 ) ;
F_59 ( V_242 , V_68 -> V_251 ) ;
F_59 ( V_252 , V_68 -> V_110 ) ;
break;
case V_253 :
case V_254 :
case V_255 :
V_170 = (struct V_165 * ) V_8 -> V_144 ;
if ( V_170 -> V_178 == V_231 ) {
V_8 -> V_256 =
( (struct V_228 * ) V_170 ) -> V_257 ;
if ( V_8 -> V_256 == 0 )
V_8 -> V_256 = V_258 - 1 ;
}
if ( V_241 == V_254 ) {
if ( F_100 ( V_8 , V_170 ) ) {
F_105 ( V_242 , V_259 ) ;
return - 1 ;
}
if ( F_99 ( V_8 ) ) {
F_105 ( V_242 , V_259 ) ;
return - 1 ;
}
} else if ( V_241 == V_253 ) {
V_170 -> V_178 = 0 ;
V_8 -> V_256 = V_258 - 1 ;
}
if ( ( V_170 -> V_178 + 1 ) <= V_8 -> V_256 ) {
V_170 -> V_178 ++ ;
if ( V_170 -> V_178 != V_231 ) {
F_96 ( V_8 , V_170 ) ;
F_105 ( V_242 , V_255 ) ;
} else
F_105 ( V_242 , V_254 ) ;
} else
F_105 ( V_242 , V_260 ) ;
F_104 ( V_242 , V_246 ) ;
F_59 ( V_242 , V_68 -> V_251 ) ;
F_59 ( V_252 , V_68 -> V_110 ) ;
break;
case V_260 :
V_27 = F_52 ( V_68 -> V_106 ) ;
V_27 |= V_68 -> V_261 | V_68 -> V_262 ;
F_59 ( V_27 , V_68 -> V_106 ) ;
F_59 ( V_8 -> V_78 , V_8 -> V_75 ) ;
F_59 ( F_31 ( V_8 -> V_225 ) ,
V_68 -> V_263 ) ;
F_59 ( F_32 ( V_8 -> V_225 ) ,
V_68 -> V_264 ) ;
if ( V_8 -> V_20 -> V_126 == V_265 ) {
F_59 ( ( V_8 -> V_78 - 1 ) |
V_68 -> V_72 ,
V_8 -> V_95 ) ;
F_59 ( F_31 ( V_8 -> V_227 ) ,
V_68 -> V_266 ) ;
F_59 ( F_32 ( V_8 -> V_227 ) ,
V_68 -> V_267 ) ;
}
V_8 -> V_71 = ( V_8 -> V_78 - 1 ) |
V_68 -> V_72 ;
V_8 -> V_96 = ( V_8 -> V_78 - 1 ) |
V_68 -> V_72 ;
V_8 -> V_111 = V_268 ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_42 ,
V_241 ) ;
return - 1 ;
}
return 0 ;
}
static unsigned char F_106 ( struct V_7 * V_8 )
{
unsigned int V_269 ;
unsigned long V_115 ;
V_115 = V_116 ;
F_101 ( V_8 ) ;
do {
V_269 = V_8 -> V_100 -> V_270 ( V_8 ) ;
if ( V_8 -> V_111 == V_268 )
return 0 ;
if ( F_69 ( V_116 , V_115 + V_119 * V_120 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_43 ,
V_8 -> V_111 ) ;
F_11 ( & V_8 -> V_20 -> V_11 ,
L_44 ,
V_8 -> V_271 , V_269 ) ;
return - 1 ;
}
F_71 () ;
F_107 ( 1000 , 2000 ) ;
} while ( ! ( V_269 & V_272 ) );
return 0 ;
}
static unsigned char F_108 ( struct V_7 * V_8 )
{
unsigned int V_27 ;
unsigned long V_115 ;
V_115 = V_116 ;
V_27 = F_52 ( V_8 -> V_68 -> V_107 ) ;
while ( ( V_27 != V_117 ) && ( V_27 != V_108 ) ) {
if ( V_27 != V_117 )
F_59 ( V_118 ,
V_8 -> V_68 -> V_110 ) ;
if ( F_69 ( V_116 , V_115 + V_119 * V_120 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_45 , V_27 ) ;
return - 1 ;
}
F_107 ( 1000 , 2000 ) ;
F_71 () ;
V_27 = F_52 ( V_8 -> V_68 -> V_107 ) ;
}
V_8 -> V_111 = V_243 ;
F_12 ( & V_8 -> V_20 -> V_11 , L_46 ) ;
do {
if ( F_106 ( V_8 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_47 ,
V_8 -> V_111 ) ;
return - 1 ;
}
} while ( V_8 -> V_111 != V_268 );
F_12 ( & V_8 -> V_20 -> V_11 , L_48 ) ;
return 0 ;
}
static unsigned char F_67 ( struct V_7 * V_8 )
{
unsigned int V_27 ;
struct V_67 * V_68 = V_8 -> V_68 ;
V_27 = F_52 ( V_68 -> V_273 ) ;
F_59 ( V_27 , V_68 -> V_273 ) ;
F_59 ( V_68 -> V_274 , V_68 -> V_275 ) ;
V_27 = F_52 ( V_68 -> V_106 ) | V_68 -> V_276 ;
F_59 ( V_27 , V_68 -> V_106 ) ;
F_70 ( 100 ) ;
if ( F_108 ( V_8 ) )
return - 1 ;
return 0 ;
}
static void F_109 ( struct V_7 * V_8 , struct V_46 * V_47 ,
struct V_83 * V_277 )
{
struct V_30 * V_31 = V_47 -> V_31 ;
V_47 -> V_31 -> V_278 . V_168 = NULL ;
V_31 -> V_279 = V_277 -> V_280 ;
switch ( V_277 -> V_280 ) {
case V_164 :
V_31 -> V_279 |= V_281 << 16 ;
break;
case V_282 :
V_31 -> V_279 |= V_283 << 16 ;
break;
case V_284 :
V_31 -> V_279 |= ( V_281 << 16 ) ;
if ( V_277 -> V_285 & V_286 ) {
memcpy ( V_47 -> V_31 -> V_287 , V_277 -> V_50 ,
sizeof( struct V_288 ) ) ;
V_31 -> V_279 |= ( V_289 << 24 ) ;
}
break;
default:
V_31 -> V_279 |= ( V_290 << 24 ) | ( V_291 << 16 ) ;
break;
}
if ( F_110 ( V_31 ) )
F_28 ( V_8 -> V_20 , F_26 ( V_31 ) ,
F_25 ( V_31 ) ,
( int ) V_31 -> V_40 ) ;
V_47 -> V_31 -> V_292 ( V_31 ) ;
F_47 ( V_8 , V_47 ) ;
}
static void F_111 ( struct V_7 * V_8 ,
struct V_46 * V_47 ,
struct V_83 * V_277 )
{
if ( F_54 ( & V_47 -> V_136 ) ) {
V_47 -> V_134 = V_277 -> V_280 ;
if ( ( V_277 -> V_280 == V_284 ) &&
( V_277 -> V_285 & V_286 ) &&
V_47 -> V_52 ) {
memcpy ( V_47 -> V_52 , V_277 -> V_50 ,
sizeof( struct V_288 ) ) ;
}
F_90 ( & V_47 -> V_136 ) ;
F_112 ( & V_8 -> V_140 ) ;
}
}
static void F_113 ( struct V_7 * V_8 ,
struct V_293 * V_168 )
{
unsigned int V_4 ;
F_46 ( & V_8 -> V_20 -> V_11 ,
L_49 ,
V_168 -> V_294 , V_168 -> V_295 , V_168 -> V_296 , V_168 -> V_147 ) ;
if ( V_168 -> V_297 ) {
F_114 ( V_298 L_50 ,
V_168 -> V_297 ) ;
for ( V_4 = 0 ; V_4 < V_168 -> V_297 ; V_4 ++ )
F_114 ( V_298 L_51 , V_168 -> V_299 [ V_4 ] ) ;
F_114 ( V_298 L_52 ) ;
}
if ( V_168 -> V_300 ) {
F_114 ( V_298 L_53 ,
V_168 -> V_300 ) ;
for ( V_4 = 0 ; V_4 < V_168 -> V_300 ; V_4 ++ )
F_114 ( V_298 L_51 , V_168 -> V_301 [ V_4 ] ) ;
F_114 ( V_298 L_52 ) ;
}
}
static int F_115 ( struct V_7 * V_8 , T_4 V_302 , int V_303 )
{
struct V_304 * V_305 ;
int V_122 = - 1 ;
if ( V_303 == V_306 ) {
V_305 = F_116 ( V_8 -> V_137 , 0 , V_302 , 0 ) ;
if ( V_305 ) {
F_12 ( & V_8 -> V_20 -> V_11 , L_54 , 0 ,
V_305 -> V_307 , 0 ) ;
F_117 ( V_305 ) ;
F_118 ( V_305 ) ;
V_122 = 0 ;
} else
F_11 ( & V_8 -> V_20 -> V_11 , L_55 ,
V_302 ) ;
} else if ( V_303 == V_308 ) {
V_305 = F_116 ( V_8 -> V_137 , 0 , V_302 , 0 ) ;
if ( ! V_305 ) {
F_119 ( V_8 -> V_137 , 0 , V_302 , 0 ) ;
F_12 ( & V_8 -> V_20 -> V_11 , L_56 , 0 ,
V_302 , 0 ) ;
V_122 = 0 ;
} else {
F_11 ( & V_8 -> V_20 -> V_11 , L_57 ,
0 , V_302 , 0 ) ;
F_118 ( V_305 ) ;
}
}
return V_122 ;
}
static T_3 F_120 ( struct V_7 * V_8 ,
unsigned int V_307 , struct V_46 * V_47 )
{
struct V_146 * V_49 ;
T_3 V_309 = 0 ;
int V_310 = 0 ;
int V_311 = 64 ;
if ( ! V_47 ) {
V_47 = F_37 ( V_8 , V_311 ) ;
if ( V_47 )
V_310 = 1 ;
else
return 0 ;
} else {
memset ( V_47 -> V_52 , 0 , V_311 ) ;
}
V_47 -> V_31 = NULL ;
V_47 -> V_134 = V_135 ;
F_94 ( & V_47 -> V_136 , 0 ) ;
V_49 = V_47 -> V_49 ;
V_49 -> V_147 = ( T_4 ) V_307 ;
V_49 -> V_155 = V_312 ;
V_49 -> V_153 = V_154 ;
V_49 -> V_158 = 6 ;
V_49 -> V_157 = V_313 ;
memset ( V_49 -> V_160 , 0 , V_49 -> V_158 ) ;
V_49 -> V_160 [ 0 ] = V_314 ;
V_49 -> V_160 [ 4 ] = V_49 -> V_157 ;
F_86 ( V_8 , V_47 ) ;
if ( V_47 -> V_134 == V_164 ) {
if ( V_8 -> V_20 -> V_126 == V_265 )
V_309 = V_307 + 1 ;
else
memcpy ( ( void * ) & V_309 ,
( V_47 -> V_52 + V_315 ) ,
V_316 ) ;
F_12 ( & V_8 -> V_20 -> V_11 ,
L_58 , V_307 , V_309 ) ;
} else {
V_309 = 0 ;
}
if ( V_310 )
F_39 ( V_8 , V_47 ) ;
return V_309 ;
}
static void F_121 ( struct V_7 * V_8 )
{
struct V_317 * V_318 = NULL , * V_319 ;
struct V_304 * V_305 = NULL ;
F_122 ( & V_8 -> V_320 ) ;
F_21 (mv_dev, dev_next,
&mhba->shost_dev_list, list) {
F_115 ( V_8 , V_318 -> V_307 , V_306 ) ;
F_45 ( & V_318 -> V_103 ) ;
F_12 ( & V_8 -> V_20 -> V_11 , L_59 ,
V_318 -> V_307 , V_318 -> V_309 ) ;
F_15 ( V_318 ) ;
}
F_21 (mv_dev, dev_next, &mhba->mhba_dev_list, list) {
F_45 ( & V_318 -> V_103 ) ;
F_12 ( & V_8 -> V_20 -> V_11 , L_59 ,
V_318 -> V_307 , V_318 -> V_309 ) ;
F_15 ( V_318 ) ;
}
if ( V_8 -> V_20 -> V_126 == V_226 )
V_305 = F_116 ( V_8 -> V_137 , 0 ,
V_8 -> V_150 - 1 , 0 ) ;
if ( V_305 ) {
F_117 ( V_305 ) ;
F_118 ( V_305 ) ;
}
F_123 ( & V_8 -> V_320 ) ;
}
static void F_124 ( struct V_7 * V_8 , int V_307 )
{
struct V_304 * V_305 ;
V_305 = F_116 ( V_8 -> V_137 , 0 , V_307 , 0 ) ;
if ( V_305 ) {
F_125 ( & V_305 -> V_321 ) ;
F_118 ( V_305 ) ;
}
}
static int F_126 ( struct V_7 * V_8 , int V_307 , T_3 V_309 )
{
struct V_317 * V_318 = NULL ;
F_127 (mv_dev, &mhba->shost_dev_list, list) {
if ( V_318 -> V_309 == V_309 ) {
if ( V_318 -> V_307 != V_307 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_60
L_61 ,
V_322 , V_318 -> V_309 , V_318 -> V_307 , V_307 ) ;
return - 1 ;
} else {
if ( V_8 -> V_20 -> V_126 ==
V_265 )
F_124 ( V_8 , V_307 ) ;
return 1 ;
}
}
}
return 0 ;
}
static void F_128 ( struct V_7 * V_8 , int V_307 )
{
struct V_317 * V_318 = NULL , * V_319 ;
F_21 (mv_dev, dev_next,
&mhba->shost_dev_list, list) {
if ( V_318 -> V_307 == V_307 ) {
F_12 ( & V_8 -> V_20 -> V_11 ,
L_62 ,
V_318 -> V_307 , V_318 -> V_309 ) ;
F_115 ( V_8 , V_318 -> V_307 , V_306 ) ;
F_45 ( & V_318 -> V_103 ) ;
F_15 ( V_318 ) ;
}
}
}
static int F_129 ( struct V_7 * V_8 )
{
int V_307 , V_323 ;
T_3 V_309 = 0 ;
struct V_317 * V_318 = NULL ;
struct V_46 * V_47 = NULL ;
int V_324 = 0 ;
V_47 = F_37 ( V_8 , 64 ) ;
if ( ! V_47 )
return - 1 ;
if ( V_8 -> V_20 -> V_126 == V_265 )
V_323 = V_8 -> V_150 ;
else
V_323 = V_8 -> V_150 - 1 ;
for ( V_307 = 0 ; V_307 < V_323 ; V_307 ++ ) {
V_309 = F_120 ( V_8 , V_307 , V_47 ) ;
if ( ! V_309 ) {
F_128 ( V_8 , V_307 ) ;
} else {
V_324 = F_126 ( V_8 , V_307 , V_309 ) ;
if ( ! V_324 ) {
F_128 ( V_8 , V_307 ) ;
V_318 = F_14 ( sizeof( struct V_317 ) ,
V_54 ) ;
if ( ! V_318 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_63 ,
V_322 ) ;
continue;
}
V_318 -> V_307 = V_307 ;
V_318 -> V_309 = V_309 ;
V_318 -> V_305 = NULL ;
F_18 ( & V_318 -> V_103 ) ;
F_19 ( & V_318 -> V_103 ,
& V_8 -> V_325 ) ;
F_12 ( & V_8 -> V_20 -> V_11 ,
L_64
L_65 , V_307 , V_318 -> V_309 ) ;
} else if ( V_324 == - 1 )
return - 1 ;
else
continue;
}
}
if ( V_47 )
F_39 ( V_8 , V_47 ) ;
return 0 ;
}
static int F_130 ( void * V_104 )
{
int V_122 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) V_104 ;
struct V_317 * V_318 = NULL , * V_319 ;
while ( ! F_131 () ) {
F_132 ( V_326 ) ;
if ( ! F_54 ( & V_8 -> V_327 ) )
F_133 () ;
F_70 ( 1000 ) ;
F_94 ( & V_8 -> V_327 , 0 ) ;
F_134 ( V_328 ) ;
F_122 ( & V_8 -> V_320 ) ;
V_122 = F_129 ( V_8 ) ;
if ( ! V_122 ) {
F_21 (mv_dev, dev_next,
&mhba->mhba_dev_list, list) {
if ( F_115 ( V_8 , V_318 -> V_307 ,
V_308 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_66
L_67 ,
V_322 ,
V_318 -> V_307 , V_318 -> V_309 ) ;
F_45 ( & V_318 -> V_103 ) ;
F_15 ( V_318 ) ;
} else {
F_135 ( & V_318 -> V_103 ,
& V_8 -> V_329 ) ;
}
}
}
F_123 ( & V_8 -> V_320 ) ;
}
return 0 ;
}
static void F_136 ( struct V_7 * V_8 ,
struct V_330 * V_331 )
{
T_4 V_3 = V_331 -> V_3 ;
const unsigned long * V_332 ;
const unsigned long * V_333 ;
int V_334 ;
if ( V_8 -> V_28 & V_335 ) {
V_334 = - 1 ;
V_332 = ( const unsigned long * ) V_331 -> V_336 ;
V_333 = ( const unsigned long * ) & V_331 -> V_336 [ V_3 >> 3 ] ;
F_122 ( & V_8 -> V_337 ) ;
do {
V_334 = F_137 ( V_332 , V_3 , V_334 + 1 ) ;
if ( V_334 >= V_3 )
break;
F_115 ( V_8 , V_334 , V_308 ) ;
} while ( 1 );
V_334 = - 1 ;
do {
V_334 = F_137 ( V_333 , V_3 , V_334 + 1 ) ;
if ( V_334 >= V_3 )
break;
F_115 ( V_8 , V_334 , V_306 ) ;
} while ( 1 );
F_123 ( & V_8 -> V_337 ) ;
}
}
static void F_138 ( struct V_7 * V_8 , V_216 V_338 , void * V_339 )
{
if ( V_338 == V_340 ) {
int V_4 , V_74 ;
struct V_293 * V_331 = NULL ;
struct V_341 * V_342 = V_339 ;
V_74 = V_342 -> V_74 ;
if ( V_74 > V_343 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_68
L_69 ,
V_74 , V_343 ) ;
return;
}
for ( V_4 = 0 ; V_4 < V_74 ; V_4 ++ ) {
V_331 = & V_342 -> V_344 [ V_4 ] ;
F_113 ( V_8 , V_331 ) ;
}
} else if ( V_338 == V_345 ) {
F_136 ( V_8 , V_339 ) ;
}
}
static int F_139 ( struct V_7 * V_8 , unsigned char V_338 )
{
struct V_46 * V_47 ;
struct V_146 * V_49 ;
V_47 = F_37 ( V_8 , 512 ) ;
if ( ! V_47 )
return - 1 ;
V_47 -> V_31 = NULL ;
V_47 -> V_134 = V_135 ;
F_94 ( & V_47 -> V_136 , 0 ) ;
V_49 = V_47 -> V_49 ;
V_49 -> V_147 = 0 ;
V_49 -> V_155 = V_312 ;
V_49 -> V_153 = V_154 ;
V_49 -> V_158 = V_159 ;
V_49 -> V_157 = sizeof( struct V_341 ) ;
memset ( V_49 -> V_160 , 0 , V_159 ) ;
V_49 -> V_160 [ 0 ] = V_346 ;
V_49 -> V_160 [ 1 ] = V_338 ;
F_86 ( V_8 , V_47 ) ;
if ( V_47 -> V_134 != V_164 )
F_11 ( & V_8 -> V_20 -> V_11 , L_70 ,
V_47 -> V_134 ) ;
else
F_138 ( V_8 , V_47 -> V_49 -> V_160 [ 1 ] , V_47 -> V_52 ) ;
F_39 ( V_8 , V_47 ) ;
return 0 ;
}
static void F_140 ( struct V_347 * V_348 )
{
struct V_349 * V_350 =
F_141 ( V_348 , struct V_349 , V_351 ) ;
F_139 ( V_350 -> V_8 , V_350 -> V_352 ) ;
F_15 ( V_350 ) ;
}
static void F_142 ( struct V_7 * V_8 , T_2 V_269 )
{
struct V_349 * V_350 ;
while ( V_269 & ( V_353 | V_354 ) ) {
if ( V_269 & V_353 ) {
F_57 ( & V_8 -> V_327 ) ;
F_143 ( V_8 -> V_355 ) ;
V_269 &= ~ ( V_353 ) ;
continue;
}
V_350 = F_14 ( sizeof( * V_350 ) , V_19 ) ;
if ( V_350 ) {
F_144 ( & V_350 -> V_351 , F_140 ) ;
V_350 -> V_8 = V_8 ;
V_350 -> V_352 = V_340 ;
V_269 &= ~ ( V_354 ) ;
V_350 -> V_331 = NULL ;
F_145 ( & V_350 -> V_351 ) ;
}
}
}
static void F_146 ( struct V_7 * V_8 )
{
struct V_83 * V_277 ;
struct V_46 * V_47 ;
struct V_98 * V_356 ;
while ( ! F_43 ( & V_8 -> V_105 ) ) {
V_356 = F_49 ( & V_8 -> V_105 ,
struct V_98 , V_103 ) ;
F_45 ( & V_356 -> V_103 ) ;
F_19 ( & V_356 -> V_103 , & V_8 -> V_102 ) ;
V_277 = (struct V_83 * ) & V_356 -> V_104 [ 0 ] ;
V_47 = V_8 -> V_89 [ V_277 -> V_9 ] ;
F_90 ( & V_8 -> V_73 ) ;
V_8 -> V_89 [ V_277 -> V_9 ] = 0 ;
F_4 ( V_8 , & V_8 -> V_88 , V_277 -> V_9 ) ;
if ( V_47 -> V_31 )
F_109 ( V_8 , V_47 , V_277 ) ;
else
F_111 ( V_8 , V_47 , V_277 ) ;
}
V_8 -> V_100 -> V_139 ( V_8 , NULL ) ;
}
static T_5 F_147 ( int V_357 , void * V_358 )
{
struct V_7 * V_8 = (struct V_7 * ) V_358 ;
unsigned long V_44 ;
F_87 ( V_8 -> V_137 -> V_138 , V_44 ) ;
if ( F_53 ( V_8 -> V_100 -> V_359 ( V_8 ) || ! V_8 -> V_271 ) ) {
F_88 ( V_8 -> V_137 -> V_138 , V_44 ) ;
return V_360 ;
}
if ( V_8 -> V_271 & V_8 -> V_68 -> V_276 ) {
if ( V_8 -> V_269 & ( V_353 | V_354 ) )
F_142 ( V_8 , V_8 -> V_269 ) ;
if ( V_8 -> V_269 & V_272 ) {
F_46 ( & V_8 -> V_20 -> V_11 , L_71 ) ;
F_101 ( V_8 ) ;
}
}
if ( V_8 -> V_271 & V_8 -> V_68 -> V_261 )
F_64 ( V_8 ) ;
V_8 -> V_271 = 0 ;
V_8 -> V_269 = 0 ;
if ( V_8 -> V_111 == V_268 )
F_146 ( V_8 ) ;
F_88 ( V_8 -> V_137 -> V_138 , V_44 ) ;
return V_361 ;
}
static enum V_362 F_148 ( struct V_7 * V_8 ,
struct V_46 * V_47 )
{
void * V_76 ;
struct V_146 * V_64 ;
unsigned int V_363 ;
V_64 = V_47 -> V_49 ;
if ( F_53 ( V_8 -> V_111 != V_268 ) ) {
F_12 ( & V_8 -> V_20 -> V_11 , L_72 ) ;
return V_364 ;
}
if ( F_5 ( & V_8 -> V_88 ) ) {
F_12 ( & V_8 -> V_20 -> V_11 , L_73 ) ;
return V_364 ;
}
F_56 ( V_8 , & V_76 ) ;
V_47 -> V_49 -> V_9 = F_3 ( V_8 , & V_8 -> V_88 ) ;
V_47 -> V_49 -> V_85 = V_8 -> V_365 ++ ;
V_47 -> V_85 = V_47 -> V_49 -> V_85 ;
V_8 -> V_89 [ V_47 -> V_49 -> V_9 ] = V_47 ;
V_363 = sizeof( * V_64 ) - 4 +
V_64 -> V_51 * sizeof( struct V_36 ) ;
if ( V_8 -> V_60 & V_61 ) {
struct V_80 * V_366 ;
V_366 = V_76 ;
V_366 -> V_367 =
F_30 ( F_31 ( V_47 -> V_57 ) ) ;
V_366 -> V_368 =
F_30 ( F_32 ( V_47 -> V_57 ) ) ;
V_366 -> V_369 = ( V_363 >> 2 ) & 0xFFF ;
} else {
memcpy ( V_76 , V_64 , V_363 ) ;
}
return V_370 ;
}
static void F_149 ( struct V_7 * V_8 , struct V_46 * V_47 )
{
unsigned short V_371 = 0 ;
unsigned int V_74 ;
enum V_362 V_279 ;
if ( V_47 )
F_19 ( & V_47 -> V_55 , & V_8 -> V_372 ) ;
V_74 = V_8 -> V_100 -> V_373 ( V_8 ) ;
if ( F_43 ( & V_8 -> V_372 ) || ! V_74 )
return;
do {
V_47 = F_49 ( & V_8 -> V_372 ,
struct V_46 , V_55 ) ;
F_45 ( & V_47 -> V_55 ) ;
V_279 = F_148 ( V_8 , V_47 ) ;
switch ( V_279 ) {
case V_370 :
V_371 ++ ;
break;
case V_364 :
F_150 ( & V_47 -> V_55 , & V_8 -> V_372 ) ;
if ( V_371 > 0 )
F_58 ( V_8 ) ;
return;
}
} while ( ! F_43 ( & V_8 -> V_372 ) && V_74 -- );
if ( V_371 > 0 )
F_58 ( V_8 ) ;
}
static void F_151 ( struct V_7 * V_8 )
{
unsigned int V_374 ;
struct V_67 * V_68 = V_8 -> V_68 ;
F_59 ( V_68 -> V_274 , V_68 -> V_275 ) ;
V_374 = F_52 ( V_68 -> V_106 ) ;
V_374 |= V_68 -> V_276 | V_68 -> V_261 | V_68 -> V_262 ;
F_59 ( V_374 , V_68 -> V_106 ) ;
}
static void F_152 ( struct V_7 * V_8 )
{
unsigned int V_374 ;
struct V_67 * V_68 = V_8 -> V_68 ;
F_59 ( 0 , V_68 -> V_275 ) ;
V_374 = F_52 ( V_68 -> V_106 ) ;
V_374 &= ~ ( V_68 -> V_276 | V_68 -> V_261 |
V_68 -> V_262 ) ;
F_59 ( V_374 , V_68 -> V_106 ) ;
}
static int F_153 ( void * V_375 )
{
struct V_7 * V_8 = (struct V_7 * ) V_375 ;
unsigned int V_303 , V_269 = 0 , V_27 = 0 ;
struct V_67 * V_68 = V_8 -> V_68 ;
V_303 = F_52 ( V_68 -> V_376 ) ;
if ( ! ( V_303 & V_68 -> V_377 ) || V_303 == 0xFFFFFFFF )
return 1 ;
if ( F_53 ( V_303 & V_68 -> V_262 ) ) {
V_27 = F_52 ( V_68 -> V_378 ) ;
if ( V_8 -> V_20 -> V_126 == V_226 ) {
if ( V_27 & V_68 -> V_379 ) {
F_59 ( V_27 & V_68 -> V_379 ,
V_68 -> V_378 ) ;
}
} else {
if ( V_27 & ( V_68 -> V_380 | V_68 -> V_379 ) )
F_59 ( V_27 & ( V_68 -> V_380 |
V_68 -> V_379 ) ,
V_68 -> V_378 ) ;
}
V_303 ^= V_8 -> V_68 -> V_262 ;
}
if ( V_303 & V_68 -> V_261 ) {
V_27 = F_52 ( V_68 -> V_378 ) ;
if ( V_27 & V_68 -> V_381 )
F_59 ( V_27 & V_68 -> V_381 , V_68 -> V_378 ) ;
}
if ( V_303 & V_68 -> V_276 ) {
V_269 = F_52 ( V_68 -> V_273 ) ;
if ( V_269 )
F_59 ( V_269 , V_68 -> V_273 ) ;
}
V_8 -> V_271 = V_303 ;
V_8 -> V_269 = V_269 ;
return 0 ;
}
static unsigned int F_154 ( struct V_7 * V_8 )
{
unsigned int V_303 ;
V_303 = F_52 ( V_8 -> V_68 -> V_273 ) ;
if ( V_303 )
F_59 ( V_303 , V_8 -> V_68 -> V_273 ) ;
return V_303 ;
}
static int F_155 ( struct V_304 * V_305 )
{
struct V_7 * V_8 ;
unsigned char V_149 = sizeof( unsigned char ) * 8 ;
V_8 = (struct V_7 * ) V_305 -> V_127 -> V_128 ;
if ( V_305 -> V_307 >= V_8 -> V_150 )
return - V_382 ;
V_8 -> V_151 [ V_305 -> V_307 / V_149 ] |= ( 1 << ( V_305 -> V_307 % V_149 ) ) ;
return 0 ;
}
static unsigned char F_156 ( struct V_7 * V_8 ,
struct V_30 * V_31 , struct V_46 * V_47 )
{
struct V_146 * V_383 ;
V_47 -> V_31 = V_31 ;
V_47 -> V_134 = V_135 ;
V_383 = V_47 -> V_49 ;
V_383 -> V_147 = ( ( unsigned short ) V_31 -> V_126 -> V_307 ) |
( ( ( unsigned short ) V_31 -> V_126 -> V_384 ) << 8 ) ;
V_383 -> V_155 = 0 ;
switch ( V_31 -> V_40 ) {
case V_385 :
V_383 -> V_155 |= V_156 ;
break;
case V_386 :
V_383 -> V_155 |= V_312 ;
break;
case V_387 :
V_383 -> V_155 |= V_388 ;
break;
case V_389 :
default:
F_46 ( & V_8 -> V_20 -> V_11 , L_74
L_75 , V_31 -> V_40 , V_31 -> V_131 [ 0 ] ) ;
goto error;
}
V_383 -> V_158 = V_31 -> V_390 ;
memcpy ( V_383 -> V_160 , V_31 -> V_131 , V_383 -> V_158 ) ;
V_383 -> V_153 = V_154 ;
if ( F_110 ( V_31 ) ) {
if ( F_24 ( V_8 , V_31 , & V_383 -> V_50 [ 0 ] ,
& V_383 -> V_51 ) )
goto error;
V_383 -> V_157 = F_110 ( V_31 ) ;
} else {
V_383 -> V_51 = 0 ;
V_383 -> V_157 = 0 ;
}
return 0 ;
error:
V_31 -> V_279 = ( V_281 << 16 ) | ( V_289 << 24 ) |
V_284 ;
F_157 ( 0 , V_31 -> V_287 , V_391 , 0x24 ,
0 ) ;
return - 1 ;
}
static int F_158 ( struct V_392 * V_137 ,
struct V_30 * V_31 )
{
struct V_46 * V_47 ;
struct V_7 * V_8 ;
unsigned long V_393 ;
F_87 ( V_137 -> V_138 , V_393 ) ;
F_159 ( V_137 , V_31 ) ;
V_8 = (struct V_7 * ) V_137 -> V_128 ;
V_31 -> V_279 = 0 ;
V_47 = F_41 ( V_8 ) ;
if ( F_53 ( ! V_47 ) ) {
F_88 ( V_137 -> V_138 , V_393 ) ;
return V_394 ;
}
if ( F_53 ( F_156 ( V_8 , V_31 , V_47 ) ) )
goto V_395;
V_47 -> V_31 = V_31 ;
V_31 -> V_278 . V_168 = ( char * ) V_47 ;
V_8 -> V_100 -> V_139 ( V_8 , V_47 ) ;
F_88 ( V_137 -> V_138 , V_393 ) ;
return 0 ;
V_395:
F_47 ( V_8 , V_47 ) ;
V_31 -> V_292 ( V_31 ) ;
F_88 ( V_137 -> V_138 , V_393 ) ;
return 0 ;
}
static enum V_396 F_160 ( struct V_30 * V_31 )
{
struct V_46 * V_47 = (struct V_46 * ) V_31 -> V_278 . V_168 ;
struct V_392 * V_127 = V_31 -> V_126 -> V_127 ;
struct V_7 * V_8 = F_161 ( V_127 ) ;
unsigned long V_44 ;
F_87 ( V_8 -> V_137 -> V_138 , V_44 ) ;
if ( V_8 -> V_89 [ V_47 -> V_49 -> V_9 ] ) {
V_8 -> V_89 [ V_47 -> V_49 -> V_9 ] = 0 ;
F_4 ( V_8 , & V_8 -> V_88 , V_47 -> V_49 -> V_9 ) ;
}
if ( ! F_43 ( & V_47 -> V_55 ) )
F_45 ( & V_47 -> V_55 ) ;
else
F_90 ( & V_8 -> V_73 ) ;
V_31 -> V_279 = ( V_290 << 24 ) | ( V_291 << 16 ) ;
V_31 -> V_278 . V_168 = NULL ;
if ( F_110 ( V_31 ) ) {
F_28 ( V_8 -> V_20 , F_26 ( V_31 ) ,
F_25 ( V_31 ) ,
( int ) V_31 -> V_40 ) ;
}
F_47 ( V_8 , V_47 ) ;
F_88 ( V_8 -> V_137 -> V_138 , V_44 ) ;
return V_397 ;
}
static int
F_162 ( struct V_304 * V_305 , struct V_398 * V_399 ,
T_6 V_400 , int V_401 [] )
{
int V_402 , V_403 ;
T_6 V_404 ;
unsigned long V_27 ;
V_402 = 64 ;
V_403 = 32 ;
V_27 = V_402 * V_403 ;
V_404 = V_400 ;
F_163 ( V_404 , V_27 ) ;
if ( V_400 >= 0x200000 ) {
V_402 = 255 ;
V_403 = 63 ;
V_27 = V_402 * V_403 ;
V_404 = V_400 ;
F_163 ( V_404 , V_27 ) ;
}
V_401 [ 0 ] = V_402 ;
V_401 [ 1 ] = V_403 ;
V_401 [ 2 ] = V_404 ;
return 0 ;
}
static int F_164 ( struct V_7 * V_8 )
{
void * V_405 = NULL ;
struct V_67 * V_68 ;
switch ( V_8 -> V_20 -> V_126 ) {
case V_265 :
V_8 -> V_406 = V_8 -> V_142 [ 0 ] ;
V_405 = V_8 -> V_406 ;
if ( ! V_8 -> V_68 ) {
V_8 -> V_68 = F_14 ( sizeof( * V_68 ) , V_54 ) ;
if ( V_8 -> V_68 == NULL )
return - V_15 ;
}
V_68 = V_8 -> V_68 ;
V_68 -> V_407 = V_405 + 0x20104 ;
V_68 -> V_408 = V_405 + 0x20108 ;
V_68 -> V_409 = V_405 + 0x2010C ;
V_68 -> V_376 = V_405 + 0x20200 ;
V_68 -> V_106 = V_405 + 0x2020C ;
V_68 -> V_410 = V_405 + 0xF1400 ;
V_68 -> V_110 = V_405 + 0x20400 ;
V_68 -> V_273 = V_405 + 0x20408 ;
V_68 -> V_275 = V_405 + 0x2040C ;
V_68 -> V_251 = V_405 + 0x20430 ;
V_68 -> V_250 = V_405 + 0x20434 ;
V_68 -> V_245 = V_405 + 0x20438 ;
V_68 -> V_107 = V_405 + 0x2043C ;
V_68 -> V_263 = V_405 + 0x508 ;
V_68 -> V_264 = V_405 + 0x50C ;
V_68 -> V_81 = V_405 + 0x518 ;
V_68 -> V_69 = V_405 + 0x51C ;
V_68 -> V_411 = V_405 + 0x568 ;
V_68 -> V_266 = V_405 + 0x5B0 ;
V_68 -> V_267 = V_405 + 0x5B4 ;
V_68 -> V_94 = V_405 + 0x544 ;
V_68 -> V_97 = V_405 + 0x548 ;
V_68 -> V_378 = V_405 + 0x560 ;
V_68 -> V_411 = V_405 + 0x568 ;
V_68 -> V_261 = 1 << 8 ;
V_68 -> V_262 = 1 << 6 ;
V_68 -> V_276 = 1 << 1 ;
V_68 -> V_72 = 1 << 12 ;
V_68 -> V_381 = 1 << 1 ;
V_68 -> V_380 = 1 << 8 ;
V_68 -> V_379 = 1 << 12 ;
V_68 -> V_70 = 0xFFF ;
V_68 -> V_274 = 0x3FFFFFFF ;
V_68 -> V_377 = V_68 -> V_276 | V_68 -> V_261 |
V_68 -> V_262 ;
break;
case V_226 :
V_8 -> V_406 = V_8 -> V_142 [ 2 ] ;
V_405 = V_8 -> V_406 ;
if ( ! V_8 -> V_68 ) {
V_8 -> V_68 = F_14 ( sizeof( * V_68 ) , V_54 ) ;
if ( V_8 -> V_68 == NULL )
return - V_15 ;
}
V_68 = V_8 -> V_68 ;
V_68 -> V_407 = V_405 + 0x20104 ;
V_68 -> V_408 = V_405 + 0x1010C ;
V_68 -> V_409 = V_405 + 0x10108 ;
V_68 -> V_376 = V_405 + 0x10200 ;
V_68 -> V_106 = V_405 + 0x1020C ;
V_68 -> V_410 = V_405 + 0xF1400 ;
V_68 -> V_110 = V_405 + 0x10460 ;
V_68 -> V_273 = V_405 + 0x10480 ;
V_68 -> V_275 = V_405 + 0x10484 ;
V_68 -> V_251 = V_405 + 0x10400 ;
V_68 -> V_250 = V_405 + 0x10404 ;
V_68 -> V_245 = V_405 + 0x10420 ;
V_68 -> V_107 = V_405 + 0x10424 ;
V_68 -> V_125 = V_405 + 0x10108 ;
V_68 -> V_124 = V_405 + 0x1010c ;
V_68 -> V_263 = V_405 + 0x4008 ;
V_68 -> V_264 = V_405 + 0x400C ;
V_68 -> V_81 = V_405 + 0x4018 ;
V_68 -> V_69 = V_405 + 0x401C ;
V_68 -> V_266 = V_405 + 0x4058 ;
V_68 -> V_267 = V_405 + 0x405C ;
V_68 -> V_94 = V_405 + 0x406C ;
V_68 -> V_97 = V_405 + 0x4070 ;
V_68 -> V_411 = V_405 + 0x4080 ;
V_68 -> V_378 = V_405 + 0x4088 ;
V_68 -> V_261 = 1 << 4 ;
V_68 -> V_276 = 1 << 12 ;
V_68 -> V_262 = 1 << 29 ;
V_68 -> V_72 = 1 << 14 ;
V_68 -> V_70 = 0x3FFF ;
V_68 -> V_381 = 1 << 0 ;
V_68 -> V_379 = 1 << 1 ;
V_68 -> V_274 = 0x3FFFFFFF ;
V_68 -> V_377 = V_68 -> V_276 | V_68 -> V_261 ;
break;
default:
return - 1 ;
break;
}
return 0 ;
}
static int F_165 ( struct V_7 * V_8 )
{
int V_122 = 0 ;
if ( F_166 ( V_8 -> V_20 , V_412 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_76 ) ;
return - V_413 ;
}
V_122 = F_9 ( V_8 -> V_20 , V_8 -> V_142 ) ;
if ( V_122 )
goto V_414;
switch ( V_8 -> V_20 -> V_126 ) {
case V_265 :
V_8 -> V_100 = & V_415 ;
V_8 -> V_365 = 0 ;
V_8 -> V_41 = V_416 ;
V_8 -> V_90 = 1 ;
break;
case V_226 :
V_8 -> V_100 = & V_417 ;
V_8 -> V_365 = 0 ;
V_8 -> V_41 = V_416 ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_77 ,
V_8 -> V_20 -> V_126 ) ;
V_8 -> V_100 = NULL ;
V_122 = - V_382 ;
goto V_418;
}
F_12 ( & V_8 -> V_20 -> V_11 , L_78 ,
V_8 -> V_20 -> V_126 ) ;
V_122 = F_164 ( V_8 ) ;
if ( V_122 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_79 ) ;
V_122 = - V_15 ;
goto V_418;
}
V_8 -> V_144 = F_38 ( V_8 -> V_20 , V_143 ,
& V_8 -> V_145 ) ;
if ( ! V_8 -> V_144 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_80 ) ;
V_122 = - V_15 ;
goto V_419;
}
if ( F_67 ( V_8 ) ) {
V_122 = - V_382 ;
goto V_420;
}
V_122 = F_50 ( V_8 ) ;
if ( V_122 )
goto V_420;
return 0 ;
V_420:
F_20 ( V_8 ) ;
F_22 ( V_8 -> V_20 , V_143 ,
V_8 -> V_144 , V_8 -> V_145 ) ;
V_419:
F_15 ( V_8 -> V_68 ) ;
V_418:
F_6 ( V_8 -> V_20 , V_8 -> V_142 ) ;
V_414:
F_92 ( V_8 -> V_20 ) ;
return V_122 ;
}
static int F_167 ( struct V_7 * V_8 )
{
struct V_392 * V_127 = V_8 -> V_137 ;
struct V_304 * V_305 = NULL ;
int V_122 ;
unsigned int V_421 = ( V_8 -> V_56 + 4 -
sizeof( struct V_146 ) ) / sizeof( struct V_36 ) ;
V_127 -> V_357 = V_8 -> V_20 -> V_357 ;
V_127 -> V_422 = V_8 -> V_422 ;
V_127 -> V_423 = ( V_8 -> V_62 - 1 ) ? ( V_8 -> V_62 - 1 ) : 1 ;
V_127 -> V_424 = V_8 -> V_41 > V_421 ? V_421 : V_8 -> V_41 ;
V_127 -> V_425 = V_8 -> V_234 / 512 ;
V_127 -> V_426 = ( V_8 -> V_62 - 1 ) ? ( V_8 -> V_62 - 1 ) : 1 ;
V_127 -> V_427 = V_8 -> V_150 ;
V_127 -> V_428 = V_159 ;
V_122 = F_168 ( V_127 , & V_8 -> V_20 -> V_11 ) ;
if ( V_122 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_81 ) ;
return V_122 ;
}
V_8 -> V_28 |= V_335 ;
F_122 ( & V_8 -> V_337 ) ;
if ( V_8 -> V_20 -> V_126 == V_226 )
V_122 = F_119 ( V_127 , 0 , V_8 -> V_150 - 1 , 0 ) ;
else
V_122 = 0 ;
if ( V_122 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_82 ) ;
F_123 ( & V_8 -> V_337 ) ;
goto V_429;
}
V_8 -> V_355 = F_169 ( F_130 ,
V_8 , L_83 ) ;
if ( F_170 ( V_8 -> V_355 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_84 ) ;
F_123 ( & V_8 -> V_337 ) ;
goto V_430;
}
F_94 ( & V_8 -> V_327 , 1 ) ;
F_143 ( V_8 -> V_355 ) ;
F_123 ( & V_8 -> V_337 ) ;
return 0 ;
V_430:
if ( V_8 -> V_20 -> V_126 == V_226 )
V_305 = F_116 ( V_8 -> V_137 , 0 ,
V_8 -> V_150 - 1 , 0 ) ;
if ( V_305 ) {
F_117 ( V_305 ) ;
F_118 ( V_305 ) ;
}
V_429:
F_171 ( V_8 -> V_137 ) ;
return V_122 ;
}
static int F_172 ( struct V_10 * V_20 , const struct V_431 * V_307 )
{
struct V_392 * V_127 ;
struct V_7 * V_8 ;
int V_122 ;
F_12 ( & V_20 -> V_11 , L_85 ,
V_20 -> V_432 , V_20 -> V_126 , V_20 -> V_433 ,
V_20 -> V_434 ) ;
V_122 = F_82 ( V_20 ) ;
if ( V_122 )
return V_122 ;
F_77 ( V_20 ) ;
if ( V_123 ) {
V_122 = F_78 ( V_20 , F_79 ( 64 ) ) ;
if ( V_122 ) {
V_122 = F_78 ( V_20 , F_79 ( 32 ) ) ;
if ( V_122 )
goto V_435;
}
} else {
V_122 = F_78 ( V_20 , F_79 ( 32 ) ) ;
if ( V_122 )
goto V_435;
}
V_127 = F_173 ( & V_436 , sizeof( * V_8 ) ) ;
if ( ! V_127 ) {
F_11 ( & V_20 -> V_11 , L_86 ) ;
V_122 = - V_15 ;
goto V_437;
}
V_8 = F_161 ( V_127 ) ;
F_18 ( & V_8 -> V_58 ) ;
F_18 ( & V_8 -> V_102 ) ;
F_18 ( & V_8 -> V_105 ) ;
F_18 ( & V_8 -> V_26 ) ;
F_18 ( & V_8 -> V_372 ) ;
F_174 ( & V_8 -> V_320 ) ;
F_18 ( & V_8 -> V_325 ) ;
F_18 ( & V_8 -> V_329 ) ;
F_94 ( & V_8 -> V_73 , 0 ) ;
F_175 ( & V_8 -> V_140 ) ;
F_174 ( & V_8 -> V_337 ) ;
V_8 -> V_20 = V_20 ;
V_8 -> V_137 = V_127 ;
V_8 -> V_422 = V_20 -> V_438 -> V_439 << 8 | V_20 -> V_440 ;
V_122 = F_165 ( V_8 ) ;
if ( V_122 )
goto V_441;
V_122 = F_176 ( V_8 -> V_20 -> V_357 , F_147 , V_442 ,
L_87 , V_8 ) ;
if ( V_122 ) {
F_11 ( & V_20 -> V_11 , L_88 ) ;
goto V_443;
}
V_8 -> V_100 -> V_444 ( V_8 ) ;
F_177 ( V_20 , V_8 ) ;
V_122 = F_167 ( V_8 ) ;
if ( V_122 )
goto V_445;
F_72 ( V_8 ) ;
F_12 ( & V_20 -> V_11 , L_89 ) ;
return 0 ;
V_445:
V_8 -> V_100 -> V_446 ( V_8 ) ;
F_178 ( V_8 -> V_20 -> V_357 , V_8 ) ;
V_443:
F_91 ( V_8 ) ;
V_441:
F_179 ( V_127 ) ;
V_437:
V_435:
F_81 ( V_20 ) ;
return V_122 ;
}
static void F_180 ( struct V_10 * V_20 )
{
struct V_392 * V_127 ;
struct V_7 * V_8 ;
V_8 = F_181 ( V_20 ) ;
if ( V_8 -> V_355 ) {
F_182 ( V_8 -> V_355 ) ;
V_8 -> V_355 = NULL ;
}
F_121 ( V_8 ) ;
V_127 = V_8 -> V_137 ;
F_171 ( V_8 -> V_137 ) ;
F_93 ( V_8 ) ;
V_8 -> V_100 -> V_446 ( V_8 ) ;
F_178 ( V_8 -> V_20 -> V_357 , V_8 ) ;
F_91 ( V_8 ) ;
F_179 ( V_127 ) ;
F_81 ( V_20 ) ;
F_12 ( & V_20 -> V_11 , L_90 ) ;
}
static void F_183 ( struct V_10 * V_20 )
{
struct V_7 * V_8 = F_181 ( V_20 ) ;
F_93 ( V_8 ) ;
}
static int T_7 F_184 ( struct V_10 * V_20 , T_8 V_447 )
{
struct V_7 * V_8 = NULL ;
V_8 = F_181 ( V_20 ) ;
F_93 ( V_8 ) ;
F_177 ( V_20 , V_8 ) ;
V_8 -> V_100 -> V_446 ( V_8 ) ;
F_178 ( V_8 -> V_20 -> V_357 , V_8 ) ;
F_6 ( V_20 , V_8 -> V_142 ) ;
F_92 ( V_20 ) ;
F_185 ( V_20 ) ;
F_81 ( V_20 ) ;
F_186 ( V_20 , F_187 ( V_20 , V_447 ) ) ;
return 0 ;
}
static int T_7 F_188 ( struct V_10 * V_20 )
{
int V_122 ;
struct V_7 * V_8 = NULL ;
V_8 = F_181 ( V_20 ) ;
F_186 ( V_20 , V_448 ) ;
F_189 ( V_20 , V_448 , 0 ) ;
F_190 ( V_20 ) ;
V_122 = F_82 ( V_20 ) ;
if ( V_122 ) {
F_11 ( & V_20 -> V_11 , L_24 ) ;
return V_122 ;
}
F_77 ( V_20 ) ;
if ( V_123 ) {
V_122 = F_78 ( V_20 , F_79 ( 64 ) ) ;
if ( V_122 ) {
V_122 = F_78 ( V_20 , F_79 ( 32 ) ) ;
if ( V_122 )
goto V_449;
}
} else {
V_122 = F_78 ( V_20 , F_79 ( 32 ) ) ;
if ( V_122 )
goto V_449;
}
V_122 = F_166 ( V_8 -> V_20 , V_412 ) ;
if ( V_122 )
goto V_449;
V_122 = F_9 ( V_8 -> V_20 , V_8 -> V_142 ) ;
if ( V_122 )
goto V_450;
if ( F_164 ( V_8 ) ) {
V_122 = - V_382 ;
goto V_451;
}
V_8 -> V_406 = V_8 -> V_142 [ 0 ] ;
F_65 ( V_8 ) ;
if ( F_67 ( V_8 ) ) {
V_122 = - V_382 ;
goto V_451;
}
V_122 = F_176 ( V_8 -> V_20 -> V_357 , F_147 , V_442 ,
L_87 , V_8 ) ;
if ( V_122 ) {
F_11 ( & V_20 -> V_11 , L_88 ) ;
goto V_451;
}
V_8 -> V_100 -> V_444 ( V_8 ) ;
return 0 ;
V_451:
F_6 ( V_20 , V_8 -> V_142 ) ;
V_450:
F_92 ( V_20 ) ;
V_449:
F_81 ( V_20 ) ;
return V_122 ;
}
static int T_9 F_191 ( void )
{
return F_192 ( & V_452 ) ;
}
static void T_10 F_193 ( void )
{
F_194 ( & V_452 ) ;
}
