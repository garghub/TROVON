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
if ( V_38 ) {
V_35 = F_26 ( V_31 ) ;
* V_33 = F_27 ( V_8 -> V_20 , V_35 , V_38 ,
( int ) V_31 -> V_40 ) ;
if ( * V_33 > V_8 -> V_41 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_9
L_10 ,
* V_33 , V_8 -> V_41 ) ;
return - 1 ;
}
for ( V_4 = 0 ; V_4 < * V_33 ; V_4 ++ ) {
V_39 = F_28 ( & V_35 [ V_4 ] ) ;
V_37 -> V_42 = F_29 ( F_30 ( V_39 ) ) ;
V_37 -> V_43 = F_29 ( F_31 ( V_39 ) ) ;
V_37 -> V_44 = 0 ;
F_32 ( V_8 , V_37 , F_29 ( F_33 ( & V_35 [ V_4 ] ) ) ) ;
if ( ( V_4 + 1 ) == * V_33 )
V_37 -> V_44 |= 1U << V_8 -> V_45 ;
F_34 ( V_8 , V_37 ) ;
}
} else {
V_31 -> V_46 . V_47 = F_35 ( V_31 ) ?
F_36 ( V_8 -> V_20 , F_26 ( V_31 ) ,
F_35 ( V_31 ) ,
( int ) V_31 -> V_40 )
: 0 ;
V_39 = V_31 -> V_46 . V_47 ;
V_37 -> V_42 = F_29 ( F_30 ( V_39 ) ) ;
V_37 -> V_43 = F_29 ( F_31 ( V_39 ) ) ;
V_37 -> V_44 = 1U << V_8 -> V_45 ;
F_32 ( V_8 , V_37 , F_29 ( F_35 ( V_31 ) ) ) ;
* V_33 = 1 ;
}
return 0 ;
}
static int F_37 ( struct V_7 * V_8 , struct V_48 * V_49 ,
unsigned int V_3 )
{
struct V_36 * V_37 ;
void * V_22 ;
T_1 V_50 ;
if ( V_3 == 0 )
return 0 ;
V_22 = F_17 ( V_8 -> V_20 , V_3 , & V_50 ) ;
if ( ! V_22 )
return - 1 ;
V_37 = (struct V_36 * ) & V_49 -> V_51 -> V_52 [ 0 ] ;
V_49 -> V_51 -> V_53 = 1 ;
V_49 -> V_54 = V_22 ;
V_37 -> V_42 = F_29 ( F_30 ( V_50 ) ) ;
V_37 -> V_43 = F_29 ( F_31 ( V_50 ) ) ;
V_37 -> V_44 = 1U << V_8 -> V_45 ;
F_32 ( V_8 , V_37 , F_29 ( V_3 ) ) ;
return 0 ;
}
static struct V_48 * F_38 ( struct V_7 * V_8 ,
unsigned int V_55 )
{
struct V_48 * V_49 ;
V_49 = F_14 ( sizeof( * V_49 ) , V_56 ) ;
if ( ! V_49 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_11 ) ;
return NULL ;
}
F_18 ( & V_49 -> V_57 ) ;
V_49 -> V_51 = F_39 ( V_8 -> V_20 ,
V_8 -> V_58 , & V_49 -> V_59 ) ;
if ( ! V_49 -> V_51 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_12
L_13 , V_8 -> V_58 ) ;
F_15 ( V_49 ) ;
return NULL ;
}
if ( V_55 ) {
if ( F_37 ( V_8 , V_49 , V_55 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_14
L_15 ) ;
F_22 ( V_8 -> V_20 , V_8 -> V_58 ,
V_49 -> V_51 , V_49 -> V_59 ) ;
F_15 ( V_49 ) ;
return NULL ;
}
} else
V_49 -> V_51 -> V_53 = 0 ;
return V_49 ;
}
static void F_40 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
struct V_36 * V_37 ;
unsigned int V_3 ;
T_1 V_50 ;
if ( V_49 && V_49 -> V_51 ) {
if ( V_49 -> V_51 -> V_53 ) {
V_37 = (struct V_36 * ) & V_49 -> V_51 -> V_52 [ 0 ] ;
F_41 ( V_8 , V_37 , V_3 ) ;
V_50 = ( T_1 ) V_37 -> V_42 |
( T_1 ) ( ( V_37 -> V_43 << 16 ) << 16 ) ;
F_22 ( V_8 -> V_20 , V_3 , V_49 -> V_54 ,
V_50 ) ;
}
F_22 ( V_8 -> V_20 , V_8 -> V_58 ,
V_49 -> V_51 , V_49 -> V_59 ) ;
F_15 ( V_49 ) ;
}
}
static struct V_48 * F_42 ( struct V_7 * V_8 )
{
struct V_48 * V_49 = NULL ;
if ( F_43 ( ! F_44 ( & V_8 -> V_60 ) ) ) {
V_49 = F_45 ( ( & V_8 -> V_60 ) -> V_61 ,
struct V_48 , V_57 ) ;
F_46 ( & V_49 -> V_57 ) ;
} else
F_47 ( & V_8 -> V_20 -> V_11 , L_16 ) ;
return V_49 ;
}
static inline void F_48 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
V_49 -> V_31 = NULL ;
F_19 ( & V_49 -> V_57 , & V_8 -> V_60 ) ;
}
static void F_49 ( struct V_7 * V_8 )
{
struct V_48 * V_49 ;
while ( ! F_44 ( & V_8 -> V_60 ) ) {
V_49 = F_50 ( & V_8 -> V_60 , struct V_48 ,
V_57 ) ;
F_23 ( & V_49 -> V_57 ) ;
if ( ! ( V_8 -> V_62 & V_63 ) )
F_15 ( V_49 -> V_51 ) ;
F_15 ( V_49 ) ;
}
}
static int F_51 ( struct V_7 * V_8 )
{
int V_4 ;
struct V_48 * V_49 ;
for ( V_4 = 0 ; V_4 < V_8 -> V_64 ; V_4 ++ ) {
V_49 = F_14 ( sizeof( * V_49 ) , V_56 ) ;
if ( ! V_49 )
goto V_65;
F_18 ( & V_49 -> V_57 ) ;
F_19 ( & V_49 -> V_57 , & V_8 -> V_60 ) ;
if ( V_8 -> V_62 & V_63 ) {
V_49 -> V_51 = V_8 -> V_66 + V_4 * V_8 -> V_58 ;
V_49 -> V_59 = V_8 -> V_67
+ V_4 * V_8 -> V_58 ;
} else
V_49 -> V_51 = F_14 ( V_8 -> V_58 , V_56 ) ;
if ( ! V_49 -> V_51 )
goto V_65;
}
return 0 ;
V_65:
F_11 ( & V_8 -> V_20 -> V_11 ,
L_17 , V_4 ) ;
while ( ! F_44 ( & V_8 -> V_60 ) ) {
V_49 = F_50 ( & V_8 -> V_60 , struct V_48 ,
V_57 ) ;
F_23 ( & V_49 -> V_57 ) ;
if ( ! ( V_8 -> V_62 & V_63 ) )
F_15 ( V_49 -> V_51 ) ;
F_15 ( V_49 ) ;
}
return - V_15 ;
}
static unsigned int F_52 ( struct V_7 * V_8 )
{
unsigned int V_68 ;
struct V_69 * V_70 = V_8 -> V_70 ;
V_68 = F_53 ( V_8 -> V_70 -> V_71 ) ;
if ( F_54 ( ( ( V_68 & V_70 -> V_72 ) ==
( V_8 -> V_73 & V_70 -> V_72 ) ) &&
( ( V_68 & V_70 -> V_74 )
!= ( V_8 -> V_73 & V_70 -> V_74 ) ) ) ) {
F_47 ( & V_8 -> V_20 -> V_11 , L_18 ) ;
return 0 ;
}
if ( F_55 ( & V_8 -> V_75 ) >= V_8 -> V_64 ) {
F_47 ( & V_8 -> V_20 -> V_11 , L_19 ) ;
return 0 ;
} else {
return V_8 -> V_64 - F_55 ( & V_8 -> V_75 ) ;
}
}
static unsigned int F_56 ( struct V_7 * V_8 )
{
unsigned int V_76 ;
if ( F_55 ( & V_8 -> V_75 ) >= ( V_8 -> V_64 - 1 ) )
return 0 ;
V_76 = F_53 ( V_8 -> V_77 ) ;
if ( V_76 == 0xffff )
return 0 ;
return V_76 ;
}
static void F_57 ( struct V_7 * V_8 , void * * V_78 )
{
unsigned int V_79 ;
V_79 = V_8 -> V_73 & V_8 -> V_70 -> V_72 ;
V_79 ++ ;
if ( V_79 >= V_8 -> V_80 ) {
V_79 -= V_8 -> V_80 ;
V_8 -> V_73 ^= V_8 -> V_70 -> V_74 ;
}
V_8 -> V_73 &= ~ V_8 -> V_70 -> V_72 ;
V_8 -> V_73 |= ( V_79 & V_8 -> V_70 -> V_72 ) ;
if ( V_8 -> V_62 & V_63 ) {
* V_78 = V_8 -> V_81 + V_79 *
sizeof( struct V_82 ) ;
} else {
* V_78 = V_8 -> V_81 + V_79 * V_8 -> V_58 ;
}
F_58 ( & V_8 -> V_75 ) ;
}
static void F_59 ( struct V_7 * V_8 )
{
F_60 ( 0xffff , V_8 -> V_77 ) ;
F_60 ( V_8 -> V_73 , V_8 -> V_70 -> V_83 ) ;
}
static char F_61 ( struct V_7 * V_8 ,
unsigned int V_84 , struct V_85 * V_86 )
{
unsigned short V_9 , V_87 ;
F_62 ( 1 ) ;
V_86 = V_8 -> V_88 + V_84 * V_8 -> V_89 ;
V_87 = V_86 -> V_87 ;
V_9 = V_86 -> V_9 ;
if ( V_9 > V_8 -> V_90 . V_3 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_20 ) ;
return - 1 ;
}
if ( V_8 -> V_91 [ V_9 ] == NULL ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_21 , V_9 ) ;
return - 1 ;
} else if ( V_8 -> V_91 [ V_9 ] -> V_87 != V_87 &&
V_8 -> V_92 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_22
L_23 , V_87 ,
V_8 -> V_91 [ V_9 ] -> V_87 ) ;
return - 1 ;
}
return 0 ;
}
static int F_63 ( struct V_7 * V_8 ,
unsigned int * V_84 , unsigned int * V_93 )
{
unsigned int V_94 , V_95 ;
struct V_69 * V_70 = V_8 -> V_70 ;
do {
V_94 = F_53 ( V_70 -> V_96 ) ;
V_95 = F_53 ( V_8 -> V_97 ) ;
} while ( ( V_94 & V_70 -> V_72 ) != V_95 );
* V_84 = V_8 -> V_98 & V_8 -> V_70 -> V_72 ;
* V_93 = V_94 & V_8 -> V_70 -> V_72 ;
if ( ( V_94 & V_70 -> V_74 ) !=
( V_8 -> V_98 & V_70 -> V_74 ) ) {
* V_93 += V_8 -> V_80 ;
}
return 0 ;
}
static int F_64 ( struct V_7 * V_8 ,
unsigned int * V_84 , unsigned int * V_93 )
{
unsigned int V_94 ;
struct V_69 * V_70 = V_8 -> V_70 ;
V_94 = F_53 ( V_70 -> V_99 ) ;
V_94 = F_53 ( V_70 -> V_96 ) ;
* V_84 = V_8 -> V_98 & V_8 -> V_70 -> V_72 ;
* V_93 = V_94 & V_8 -> V_70 -> V_72 ;
if ( * V_93 < * V_84 )
* V_93 += V_8 -> V_80 ;
else if ( * V_93 == * V_84 )
return - 1 ;
return 0 ;
}
static void F_65 ( struct V_7 * V_8 )
{
unsigned int V_84 , V_93 , V_4 ;
struct V_100 * V_101 ;
struct V_85 * V_86 ;
struct V_69 * V_70 = V_8 -> V_70 ;
if ( V_8 -> V_102 -> V_103 ( V_8 , & V_84 , & V_93 ) )
return;
for ( V_4 = ( V_93 - V_84 ) ; V_4 != 0 ; V_4 -- ) {
V_84 ++ ;
if ( V_84 >= V_8 -> V_80 ) {
V_84 -= V_8 -> V_80 ;
V_8 -> V_98 ^= V_70 -> V_74 ;
}
V_86 = V_8 -> V_88 + V_84 * V_8 -> V_89 ;
if ( F_54 ( V_86 -> V_9 > V_8 -> V_90 . V_3 ||
V_8 -> V_91 [ V_86 -> V_9 ] == NULL ||
V_86 -> V_87 !=
V_8 -> V_91 [ V_86 -> V_9 ] -> V_87 ) )
if ( F_61 ( V_8 , V_84 , V_86 ) )
continue;
if ( ! F_44 ( & V_8 -> V_104 ) ) {
V_101 = (struct V_100 * )
F_50 ( & V_8 -> V_104 ,
struct V_100 , V_105 ) ;
F_46 ( & V_101 -> V_105 ) ;
} else {
V_101 = NULL ;
if ( V_84 == 0 ) {
V_84 = V_8 -> V_80 - 1 ;
V_8 -> V_98 ^= V_70 -> V_74 ;
} else
V_84 -= 1 ;
break;
}
memcpy ( V_101 -> V_106 , V_86 , V_8 -> V_89 ) ;
V_86 -> V_9 = 0xff ;
F_19 ( & V_101 -> V_105 , & V_8 -> V_107 ) ;
}
V_8 -> V_98 &= ~ V_70 -> V_72 ;
V_8 -> V_98 |= ( V_84 & V_70 -> V_72 ) ;
F_60 ( V_8 -> V_98 , V_70 -> V_99 ) ;
}
static void F_66 ( struct V_7 * V_8 )
{
struct V_69 * V_70 = V_8 -> V_70 ;
F_60 ( 0 , V_70 -> V_108 ) ;
if ( F_53 ( V_70 -> V_109 ) != V_110 )
return;
F_60 ( V_111 , V_70 -> V_112 ) ;
}
static int F_67 ( struct V_7 * V_8 )
{
V_8 -> V_113 = V_114 ;
F_66 ( V_8 ) ;
if ( F_68 ( V_8 ) )
return V_115 ;
else
return V_116 ;
}
static int F_69 ( struct V_7 * V_8 )
{
struct V_69 * V_70 = V_8 -> V_70 ;
T_2 V_27 ;
unsigned long V_117 ;
V_117 = V_118 ;
F_60 ( 0 , V_70 -> V_108 ) ;
V_27 = F_53 ( V_70 -> V_109 ) ;
while ( V_27 != V_119 ) {
F_60 ( V_120 , V_70 -> V_112 ) ;
if ( F_70 ( V_118 , V_117 + V_121 * V_122 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_24 , V_27 ) ;
return V_115 ;
}
F_71 ( 500 ) ;
F_72 () ;
V_27 = F_53 ( V_70 -> V_109 ) ;
}
return V_116 ;
}
static void F_73 ( struct V_7 * V_8 )
{
unsigned char V_4 ;
for ( V_4 = 0 ; V_4 < V_13 ; V_4 ++ ) {
F_74 ( V_8 -> V_20 , 0x10 + V_4 * 4 ,
& V_8 -> V_123 [ V_4 ] ) ;
}
}
static void F_75 ( struct V_7 * V_8 )
{
unsigned char V_4 ;
for ( V_4 = 0 ; V_4 < V_13 ; V_4 ++ ) {
if ( V_8 -> V_123 [ V_4 ] )
F_76 ( V_8 -> V_20 , 0x10 + V_4 * 4 ,
V_8 -> V_123 [ V_4 ] ) ;
}
}
static unsigned int F_77 ( struct V_10 * V_20 )
{
unsigned int V_124 = 0 ;
F_78 ( V_20 ) ;
if ( V_125 ) {
if ( F_79 ( V_20 , F_80 ( 64 ) ) )
V_124 = F_79 ( V_20 , F_80 ( 32 ) ) ;
} else
V_124 = F_79 ( V_20 , F_80 ( 32 ) ) ;
return V_124 ;
}
static int F_81 ( struct V_7 * V_8 )
{
V_8 -> V_113 = V_114 ;
F_60 ( 0 , V_8 -> V_70 -> V_126 ) ;
F_60 ( 0xf , V_8 -> V_70 -> V_127 ) ;
F_60 ( 0x10 , V_8 -> V_70 -> V_126 ) ;
F_60 ( 0x10 , V_8 -> V_70 -> V_127 ) ;
F_71 ( 100 ) ;
F_82 ( V_8 -> V_20 ) ;
if ( F_83 ( V_8 -> V_20 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_25 ) ;
return V_115 ;
}
if ( F_77 ( V_8 -> V_20 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_26 ) ;
return V_115 ;
}
F_75 ( V_8 ) ;
if ( F_69 ( V_8 ) == V_115 )
return V_115 ;
return F_67 ( V_8 ) ;
}
static int F_84 ( struct V_7 * V_8 )
{
return F_67 ( V_8 ) ;
}
static int F_85 ( struct V_30 * V_31 )
{
struct V_7 * V_8 ;
V_8 = (struct V_7 * ) V_31 -> V_128 -> V_129 -> V_130 ;
F_86 ( V_131 , V_31 , L_27 ,
V_31 -> V_132 , V_31 -> V_133 [ 0 ] , V_31 -> V_134 ) ;
return V_8 -> V_102 -> V_135 ( V_8 ) ;
}
static int F_87 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
unsigned long V_44 ;
V_49 -> V_136 = V_137 ;
if ( F_55 ( & V_49 -> V_138 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_28 ,
F_55 ( & V_49 -> V_138 ) ) ;
F_2 ( 1 ) ;
return - 1 ;
}
F_58 ( & V_49 -> V_138 ) ;
F_88 ( V_8 -> V_139 -> V_140 , V_44 ) ;
V_8 -> V_102 -> V_141 ( V_8 , V_49 ) ;
F_89 ( V_8 -> V_139 -> V_140 , V_44 ) ;
F_90 ( V_8 -> V_142 ,
( V_49 -> V_136 != V_137 ) ,
V_143 * V_122 ) ;
if ( F_55 ( & V_49 -> V_138 ) ) {
F_88 ( V_8 -> V_139 -> V_140 , V_44 ) ;
F_91 ( & V_49 -> V_138 ) ;
if ( V_8 -> V_91 [ V_49 -> V_51 -> V_9 ] ) {
V_8 -> V_91 [ V_49 -> V_51 -> V_9 ] = 0 ;
F_47 ( & V_8 -> V_20 -> V_11 , L_29 ,
V_49 -> V_51 -> V_9 ) ;
F_4 ( V_8 , & V_8 -> V_90 , V_49 -> V_51 -> V_9 ) ;
}
if ( ! F_44 ( & V_49 -> V_57 ) ) {
F_47 ( & V_8 -> V_20 -> V_11 ,
L_30 ) ;
F_46 ( & V_49 -> V_57 ) ;
} else
F_91 ( & V_8 -> V_75 ) ;
F_89 ( V_8 -> V_139 -> V_140 , V_44 ) ;
}
return 0 ;
}
static void F_92 ( struct V_7 * V_8 )
{
F_49 ( V_8 ) ;
F_20 ( V_8 ) ;
F_6 ( V_8 -> V_20 , V_8 -> V_144 ) ;
F_22 ( V_8 -> V_20 , V_145 ,
V_8 -> V_146 , V_8 -> V_147 ) ;
F_15 ( V_8 -> V_70 ) ;
F_93 ( V_8 -> V_20 ) ;
}
static unsigned char F_94 ( struct V_7 * V_8 )
{
struct V_48 * V_49 ;
struct V_148 * V_51 ;
unsigned char V_149 , V_150 = 0 ;
unsigned char V_151 = sizeof( unsigned char ) * 8 ;
for ( V_149 = 0 ; V_149 < V_8 -> V_152 ; V_149 ++ ) {
if ( ! ( V_8 -> V_153 [ V_149 / V_151 ] &
( 1 << ( V_149 % V_151 ) ) ) )
continue;
V_154: V_49 = F_38 ( V_8 , 0 ) ;
if ( ! V_49 ) {
if ( V_150 ++ >= 5 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_31
L_32
L_33 , V_149 ) ;
V_150 = 0 ;
continue;
} else
goto V_154;
}
V_49 -> V_31 = NULL ;
V_49 -> V_136 = V_137 ;
F_95 ( & V_49 -> V_138 , 0 ) ;
V_51 = V_49 -> V_51 ;
V_51 -> V_155 = V_156 ;
V_51 -> V_149 = V_149 ;
V_51 -> V_157 = V_158 ;
V_51 -> V_159 = 0 ;
V_51 -> V_160 = V_161 ;
memset ( V_51 -> V_162 , 0 , V_161 ) ;
V_51 -> V_162 [ 0 ] = V_163 ;
V_51 -> V_162 [ 1 ] = V_164 ;
V_51 -> V_162 [ 2 ] = V_165 ;
F_87 ( V_8 , V_49 ) ;
if ( V_49 -> V_136 != V_166 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_34 ,
V_149 , V_49 -> V_136 ) ;
}
F_40 ( V_8 , V_49 ) ;
}
return 0 ;
}
static unsigned char
F_96 ( struct V_167 * V_168 ,
unsigned short V_169 )
{
unsigned char * V_170 ;
unsigned char V_124 = 0 , V_4 ;
V_170 = ( unsigned char * ) V_168 -> V_171 ;
for ( V_4 = 0 ; V_4 < V_169 ; V_4 ++ ) {
V_124 ^= * V_170 ;
V_170 ++ ;
}
return V_124 ;
}
static void F_97 ( struct V_7 * V_8 ,
struct V_167 * V_172 )
{
struct V_173 * V_174 ;
struct V_175 * V_176 ;
struct V_177 * V_178 ;
T_3 time ;
T_3 V_179 ;
switch ( V_172 -> V_180 ) {
case V_181 :
V_174 = (struct V_173 * ) V_172 ;
V_172 -> V_182 = sizeof( * V_174 ) - 4 ;
memset ( V_172 -> V_171 , 0 , V_172 -> V_182 ) ;
V_174 -> V_183 = 3 ;
if ( V_8 -> V_62 & V_63 )
V_174 -> V_184 = 0x08 ;
V_174 -> V_185 . V_186 = V_187 ;
V_174 -> V_185 . V_188 = V_189 ;
V_174 -> V_185 . V_190 = V_191 ;
V_174 -> V_185 . V_192 = V_193 ;
V_174 -> V_194 = 0 ;
V_174 -> V_195 = 0 ;
V_174 -> V_196 = 0 ;
V_174 -> V_197 = 0 ;
time = F_98 () ;
V_179 = ( time - ( V_198 . V_199 * 60 ) ) ;
V_174 -> V_200 = V_179 ;
V_172 -> V_201 = F_96 ( V_172 ,
V_172 -> V_182 ) ;
break;
case V_202 :
V_178 = (struct V_177 * ) V_172 ;
V_172 -> V_182 = sizeof( * V_178 ) - 4 ;
memset ( V_172 -> V_171 , 0 , V_172 -> V_182 ) ;
V_172 -> V_201 = F_96 ( V_172 ,
V_172 -> V_182 ) ;
break;
case V_203 :
V_176 = (struct V_175 * ) V_172 ;
V_172 -> V_182 = sizeof( * V_176 ) - 4 ;
memset ( V_172 -> V_171 , 0 , V_172 -> V_182 ) ;
V_176 -> V_204 = F_30 ( V_8 -> V_205 ) ;
V_176 -> V_206 = F_31 ( V_8 -> V_205 ) ;
V_176 -> V_207 = F_30 ( V_8 -> V_208 ) ;
V_176 -> V_209 = F_31 ( V_8 -> V_208 ) ;
V_176 -> V_210 = V_8 -> V_211 ;
V_176 -> V_212 = V_8 -> V_213 ;
if ( V_8 -> V_62
& V_214 ) {
V_176 -> V_215 = F_99 ( ( unsigned long * )
& V_8 -> V_80 ,
V_216 ) ;
V_176 -> V_217 = F_99 ( ( unsigned long * )
& V_8 -> V_80 ,
V_216 ) ;
} else {
V_176 -> V_215 = ( V_218 ) V_8 -> V_80 ;
V_176 -> V_217 = ( V_218 ) V_8 -> V_80 ;
}
V_172 -> V_201 = F_96 ( V_172 ,
V_172 -> V_182 ) ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_35 ,
V_172 -> V_180 ) ;
break;
}
}
static int F_100 ( struct V_7 * V_8 )
{
struct V_100 * V_219 ;
struct V_16 * V_220 ;
unsigned int V_221 , V_222 , V_4 ;
void * V_223 , * V_224 ;
T_1 V_225 ;
if ( V_8 -> V_28 & V_29 )
return 0 ;
V_221 = V_8 -> V_58 * V_8 -> V_64 ;
if ( V_8 -> V_62 & V_63 )
V_221 += sizeof( struct V_82 ) * V_8 -> V_64 ;
V_221 += 128 + V_8 -> V_89 * V_8 -> V_64 ;
V_221 += 8 + sizeof( T_2 ) * 2 + 16 ;
V_220 = F_13 ( V_8 ,
V_23 , V_221 ) ;
if ( ! V_220 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_36 ) ;
goto V_226;
}
V_225 = V_220 -> V_24 ;
V_224 = V_220 -> V_22 ;
V_222 = F_16 ( V_225 , 128 ) - V_225 ;
V_225 += V_222 ;
V_224 += V_222 ;
V_8 -> V_81 = V_224 ;
V_8 -> V_205 = V_225 ;
if ( V_8 -> V_62 & V_63 ) {
V_224 += sizeof( struct V_82 ) * V_8 -> V_64 ;
V_225 += sizeof( struct V_82 ) * V_8 -> V_64 ;
V_8 -> V_66 = V_224 ;
V_8 -> V_67 = V_225 ;
}
V_224 += V_8 -> V_58 * V_8 -> V_64 ;
V_225 += V_8 -> V_58 * V_8 -> V_64 ;
V_222 = F_16 ( V_225 , 8 ) - V_225 ;
V_225 += V_222 ;
V_224 += V_222 ;
V_8 -> V_77 = V_224 ;
V_8 -> V_227 = V_225 ;
V_225 += sizeof( T_2 ) * 2 ;
V_224 += sizeof( T_2 ) * 2 ;
if ( V_8 -> V_20 -> V_128 == V_228 ) {
V_222 = F_16 ( V_225 , 8 ) - V_225 ;
V_225 += V_222 ;
V_224 += V_222 ;
V_8 -> V_97 = V_224 ;
V_8 -> V_229 = V_225 ;
V_225 += 8 ;
V_224 += 8 ;
} else {
V_222 = F_16 ( V_225 , 4 ) - V_225 ;
V_225 += V_222 ;
V_224 += V_222 ;
V_8 -> V_97 = V_224 ;
V_8 -> V_229 = V_225 ;
V_225 += 4 ;
V_224 += 4 ;
}
V_222 = F_16 ( V_225 , 128 ) - V_225 ;
V_225 += V_222 ;
V_224 += V_222 ;
V_8 -> V_88 = V_224 ;
V_8 -> V_208 = V_225 ;
V_221 = V_8 -> V_64 * ( V_8 -> V_89 + sizeof( * V_219 ) ) ;
V_221 = F_16 ( V_221 , 8 ) ;
V_220 = F_13 ( V_8 ,
V_21 , V_221 ) ;
if ( ! V_220 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_37 ) ;
goto V_226;
}
V_223 = V_220 -> V_22 ;
for ( V_4 = V_8 -> V_64 ; V_4 != 0 ; V_4 -- ) {
V_219 = (struct V_100 * ) V_223 ;
F_19 ( & V_219 -> V_105 , & V_8 -> V_104 ) ;
V_223 += V_8 -> V_89 + sizeof( * V_219 ) ;
}
V_221 = sizeof( unsigned short ) * V_8 -> V_64 +
sizeof( struct V_48 * ) * V_8 -> V_64 ;
V_221 += F_16 ( V_8 -> V_152 , sizeof( unsigned char ) * 8 ) /
(sizeof( unsigned char ) * 8 ) ;
V_220 = F_13 ( V_8 ,
V_21 , V_221 ) ;
if ( ! V_220 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_38 ) ;
goto V_226;
}
V_223 = V_220 -> V_22 ;
V_8 -> V_90 . V_6 = V_223 ;
V_8 -> V_90 . V_3 = V_8 -> V_64 ;
F_1 ( & V_8 -> V_90 , V_8 -> V_64 ) ;
V_223 += sizeof( unsigned short ) * V_8 -> V_64 ;
V_8 -> V_91 = V_223 ;
V_223 += sizeof( struct V_48 * ) * V_8 -> V_64 ;
V_8 -> V_153 = V_223 ;
V_8 -> V_28 |= V_29 ;
return 0 ;
V_226:
F_20 ( V_8 ) ;
return - 1 ;
}
static int F_101 ( struct V_7 * V_8 ,
struct V_167 * V_172 )
{
struct V_230 * V_231 ;
unsigned char V_232 ;
V_232 = F_96 ( V_172 ,
V_172 -> V_182 ) ;
if ( V_232 != V_172 -> V_201 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_39 ) ;
return - 1 ;
}
switch ( V_172 -> V_180 ) {
case V_233 :
V_231 = (struct V_230 * ) V_172 ;
V_8 -> V_64 = V_231 -> V_234 ;
V_8 -> V_80 = V_231 -> V_235 ;
V_8 -> V_236 = V_231 -> V_236 ;
V_8 -> V_152 = V_231 -> V_237 ;
V_8 -> V_62 = V_231 -> V_238 ;
V_8 -> V_211 = V_231 -> V_239 ;
V_8 -> V_58 = ( 1 << V_231 -> V_239 ) << 2 ;
V_8 -> V_213 = V_231 -> V_240 ;
V_8 -> V_89 = ( 1 << V_231 -> V_240 ) << 2 ;
F_12 ( & V_8 -> V_20 -> V_11 , L_40 ,
V_231 -> V_241 . V_192 ) ;
if ( V_8 -> V_62 & V_242 )
V_8 -> V_45 = 22 ;
else
V_8 -> V_45 = 27 ;
if ( V_8 -> V_62 & V_214 )
V_8 -> V_80 = 1 << V_231 -> V_235 ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_41 ) ;
return - 1 ;
}
return 0 ;
}
static int F_102 ( struct V_7 * V_8 )
{
unsigned int V_243 , V_27 , V_244 ;
struct V_167 * V_172 ;
struct V_69 * V_70 = V_8 -> V_70 ;
if ( V_8 -> V_113 == V_245 )
V_243 = V_246 ;
else {
V_27 = F_53 ( V_70 -> V_247 ) ;
V_243 = F_103 ( V_27 ) ;
F_12 ( & V_8 -> V_20 -> V_11 , L_42 , V_243 ) ;
if ( F_104 ( V_27 ) != V_248 ) {
V_8 -> V_113 = V_245 ;
return - 1 ;
}
}
V_244 = 0 ;
switch ( V_243 ) {
case V_246 :
V_8 -> V_113 = V_249 ;
F_105 ( V_244 , V_248 ) ;
F_106 ( V_244 , V_250 ) ;
F_60 ( V_251 , V_70 -> V_252 ) ;
F_60 ( V_244 , V_70 -> V_253 ) ;
F_60 ( V_254 , V_70 -> V_112 ) ;
break;
case V_250 :
F_60 ( F_30 ( V_8 -> V_147 ) ,
V_70 -> V_252 ) ;
F_60 ( F_31 ( V_8 -> V_147 ) ,
V_70 -> V_109 ) ;
F_105 ( V_244 , V_248 ) ;
F_106 ( V_244 , V_255 ) ;
F_60 ( V_244 , V_70 -> V_253 ) ;
F_60 ( V_254 , V_70 -> V_112 ) ;
break;
case V_255 :
case V_256 :
case V_257 :
V_172 = (struct V_167 * ) V_8 -> V_146 ;
if ( V_172 -> V_180 == V_233 ) {
V_8 -> V_258 =
( (struct V_230 * ) V_172 ) -> V_259 ;
if ( V_8 -> V_258 == 0 )
V_8 -> V_258 = V_260 - 1 ;
}
if ( V_243 == V_256 ) {
if ( F_101 ( V_8 , V_172 ) ) {
F_106 ( V_244 , V_261 ) ;
return - 1 ;
}
if ( F_100 ( V_8 ) ) {
F_106 ( V_244 , V_261 ) ;
return - 1 ;
}
} else if ( V_243 == V_255 ) {
V_172 -> V_180 = 0 ;
V_8 -> V_258 = V_260 - 1 ;
}
if ( ( V_172 -> V_180 + 1 ) <= V_8 -> V_258 ) {
V_172 -> V_180 ++ ;
if ( V_172 -> V_180 != V_233 ) {
F_97 ( V_8 , V_172 ) ;
F_106 ( V_244 , V_257 ) ;
} else
F_106 ( V_244 , V_256 ) ;
} else
F_106 ( V_244 , V_262 ) ;
F_105 ( V_244 , V_248 ) ;
F_60 ( V_244 , V_70 -> V_253 ) ;
F_60 ( V_254 , V_70 -> V_112 ) ;
break;
case V_262 :
V_27 = F_53 ( V_70 -> V_108 ) ;
V_27 |= V_70 -> V_263 | V_70 -> V_264 ;
F_60 ( V_27 , V_70 -> V_108 ) ;
F_60 ( V_8 -> V_80 , V_8 -> V_77 ) ;
F_60 ( F_30 ( V_8 -> V_227 ) ,
V_70 -> V_265 ) ;
F_60 ( F_31 ( V_8 -> V_227 ) ,
V_70 -> V_266 ) ;
if ( V_8 -> V_20 -> V_128 == V_267 ) {
F_60 ( ( V_8 -> V_80 - 1 ) |
V_70 -> V_74 ,
V_8 -> V_97 ) ;
F_60 ( F_30 ( V_8 -> V_229 ) ,
V_70 -> V_268 ) ;
F_60 ( F_31 ( V_8 -> V_229 ) ,
V_70 -> V_269 ) ;
}
V_8 -> V_73 = ( V_8 -> V_80 - 1 ) |
V_70 -> V_74 ;
V_8 -> V_98 = ( V_8 -> V_80 - 1 ) |
V_70 -> V_74 ;
V_8 -> V_113 = V_270 ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_43 ,
V_243 ) ;
return - 1 ;
}
return 0 ;
}
static unsigned char F_107 ( struct V_7 * V_8 )
{
unsigned int V_271 ;
unsigned long V_117 ;
V_117 = V_118 ;
F_102 ( V_8 ) ;
do {
V_271 = V_8 -> V_102 -> V_272 ( V_8 ) ;
if ( V_8 -> V_113 == V_270 )
return 0 ;
if ( F_70 ( V_118 , V_117 + V_121 * V_122 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_44 ,
V_8 -> V_113 ) ;
F_11 ( & V_8 -> V_20 -> V_11 ,
L_45 ,
V_8 -> V_273 , V_271 ) ;
return - 1 ;
}
F_72 () ;
F_108 ( 1000 , 2000 ) ;
} while ( ! ( V_271 & V_274 ) );
return 0 ;
}
static unsigned char F_109 ( struct V_7 * V_8 )
{
unsigned int V_27 ;
unsigned long V_117 ;
V_117 = V_118 ;
V_27 = F_53 ( V_8 -> V_70 -> V_109 ) ;
while ( ( V_27 != V_119 ) && ( V_27 != V_110 ) ) {
if ( V_27 != V_119 )
F_60 ( V_120 ,
V_8 -> V_70 -> V_112 ) ;
if ( F_70 ( V_118 , V_117 + V_121 * V_122 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_46 , V_27 ) ;
return - 1 ;
}
F_108 ( 1000 , 2000 ) ;
F_72 () ;
V_27 = F_53 ( V_8 -> V_70 -> V_109 ) ;
}
V_8 -> V_113 = V_245 ;
F_12 ( & V_8 -> V_20 -> V_11 , L_47 ) ;
do {
if ( F_107 ( V_8 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_48 ,
V_8 -> V_113 ) ;
return - 1 ;
}
} while ( V_8 -> V_113 != V_270 );
F_12 ( & V_8 -> V_20 -> V_11 , L_49 ) ;
return 0 ;
}
static unsigned char F_68 ( struct V_7 * V_8 )
{
unsigned int V_27 ;
struct V_69 * V_70 = V_8 -> V_70 ;
V_27 = F_53 ( V_70 -> V_275 ) ;
F_60 ( V_27 , V_70 -> V_275 ) ;
F_60 ( V_70 -> V_276 , V_70 -> V_277 ) ;
V_27 = F_53 ( V_70 -> V_108 ) | V_70 -> V_278 ;
F_60 ( V_27 , V_70 -> V_108 ) ;
F_71 ( 100 ) ;
if ( F_109 ( V_8 ) )
return - 1 ;
return 0 ;
}
static void F_110 ( struct V_7 * V_8 , struct V_48 * V_49 ,
struct V_85 * V_279 )
{
struct V_30 * V_31 = V_49 -> V_31 ;
V_49 -> V_31 -> V_46 . V_170 = NULL ;
V_31 -> V_280 = V_279 -> V_281 ;
switch ( V_279 -> V_281 ) {
case V_166 :
V_31 -> V_280 |= V_282 << 16 ;
break;
case V_283 :
V_31 -> V_280 |= V_284 << 16 ;
break;
case V_285 :
V_31 -> V_280 |= ( V_282 << 16 ) ;
if ( V_279 -> V_286 & V_287 ) {
memcpy ( V_49 -> V_31 -> V_288 , V_279 -> V_52 ,
sizeof( struct V_289 ) ) ;
V_31 -> V_280 |= ( V_290 << 24 ) ;
}
break;
default:
V_31 -> V_280 |= ( V_291 << 24 ) | ( V_292 << 16 ) ;
break;
}
if ( F_35 ( V_31 ) ) {
if ( F_25 ( V_31 ) ) {
F_111 ( V_8 -> V_20 ,
F_26 ( V_31 ) ,
F_25 ( V_31 ) ,
( int ) V_31 -> V_40 ) ;
} else {
F_112 ( V_8 -> V_20 ,
V_31 -> V_46 . V_47 ,
F_35 ( V_31 ) ,
( int ) V_31 -> V_40 ) ;
V_31 -> V_46 . V_47 = 0 ;
}
}
V_49 -> V_31 -> V_293 ( V_31 ) ;
F_48 ( V_8 , V_49 ) ;
}
static void F_113 ( struct V_7 * V_8 ,
struct V_48 * V_49 ,
struct V_85 * V_279 )
{
if ( F_55 ( & V_49 -> V_138 ) ) {
V_49 -> V_136 = V_279 -> V_281 ;
if ( ( V_279 -> V_281 == V_285 ) &&
( V_279 -> V_286 & V_287 ) &&
V_49 -> V_54 ) {
memcpy ( V_49 -> V_54 , V_279 -> V_52 ,
sizeof( struct V_289 ) ) ;
}
F_91 ( & V_49 -> V_138 ) ;
F_114 ( & V_8 -> V_142 ) ;
}
}
static void F_115 ( struct V_7 * V_8 ,
struct V_294 * V_170 )
{
unsigned int V_4 ;
F_47 ( & V_8 -> V_20 -> V_11 ,
L_50 ,
V_170 -> V_295 , V_170 -> V_296 , V_170 -> V_297 , V_170 -> V_149 ) ;
if ( V_170 -> V_298 ) {
F_116 ( V_299 L_51 ,
V_170 -> V_298 ) ;
for ( V_4 = 0 ; V_4 < V_170 -> V_298 ; V_4 ++ )
F_116 ( V_299 L_52 , V_170 -> V_300 [ V_4 ] ) ;
F_116 ( V_299 L_53 ) ;
}
if ( V_170 -> V_301 ) {
F_116 ( V_299 L_54 ,
V_170 -> V_301 ) ;
for ( V_4 = 0 ; V_4 < V_170 -> V_301 ; V_4 ++ )
F_116 ( V_299 L_52 , V_170 -> V_302 [ V_4 ] ) ;
F_116 ( V_299 L_53 ) ;
}
}
static int F_117 ( struct V_7 * V_8 , T_4 V_303 , int V_304 )
{
struct V_305 * V_306 ;
int V_124 = - 1 ;
if ( V_304 == V_307 ) {
V_306 = F_118 ( V_8 -> V_139 , 0 , V_303 , 0 ) ;
if ( V_306 ) {
F_12 ( & V_8 -> V_20 -> V_11 , L_55 , 0 ,
V_306 -> V_308 , 0 ) ;
F_119 ( V_306 ) ;
F_120 ( V_306 ) ;
V_124 = 0 ;
} else
F_11 ( & V_8 -> V_20 -> V_11 , L_56 ,
V_303 ) ;
} else if ( V_304 == V_309 ) {
V_306 = F_118 ( V_8 -> V_139 , 0 , V_303 , 0 ) ;
if ( ! V_306 ) {
F_121 ( V_8 -> V_139 , 0 , V_303 , 0 ) ;
F_12 ( & V_8 -> V_20 -> V_11 , L_57 , 0 ,
V_303 , 0 ) ;
V_124 = 0 ;
} else {
F_11 ( & V_8 -> V_20 -> V_11 , L_58 ,
0 , V_303 , 0 ) ;
F_120 ( V_306 ) ;
}
}
return V_124 ;
}
static T_3 F_122 ( struct V_7 * V_8 ,
unsigned int V_308 , struct V_48 * V_49 )
{
struct V_148 * V_51 ;
T_3 V_310 = 0 ;
int V_311 = 0 ;
int V_312 = 64 ;
if ( ! V_49 ) {
V_49 = F_38 ( V_8 , V_312 ) ;
if ( V_49 )
V_311 = 1 ;
else
return 0 ;
} else {
memset ( V_49 -> V_54 , 0 , V_312 ) ;
}
V_49 -> V_31 = NULL ;
V_49 -> V_136 = V_137 ;
F_95 ( & V_49 -> V_138 , 0 ) ;
V_51 = V_49 -> V_51 ;
V_51 -> V_149 = ( T_4 ) V_308 ;
V_51 -> V_157 = V_313 ;
V_51 -> V_155 = V_156 ;
V_51 -> V_160 = 6 ;
V_51 -> V_159 = V_314 ;
memset ( V_51 -> V_162 , 0 , V_51 -> V_160 ) ;
V_51 -> V_162 [ 0 ] = V_315 ;
V_51 -> V_162 [ 4 ] = V_51 -> V_159 ;
F_87 ( V_8 , V_49 ) ;
if ( V_49 -> V_136 == V_166 ) {
if ( V_8 -> V_20 -> V_128 == V_267 )
V_310 = V_308 + 1 ;
else
memcpy ( ( void * ) & V_310 ,
( V_49 -> V_54 + V_316 ) ,
V_317 ) ;
F_12 ( & V_8 -> V_20 -> V_11 ,
L_59 , V_308 , V_310 ) ;
} else {
V_310 = 0 ;
}
if ( V_311 )
F_40 ( V_8 , V_49 ) ;
return V_310 ;
}
static void F_123 ( struct V_7 * V_8 )
{
struct V_318 * V_319 = NULL , * V_320 ;
struct V_305 * V_306 = NULL ;
F_124 ( & V_8 -> V_321 ) ;
F_21 (mv_dev, dev_next,
&mhba->shost_dev_list, list) {
F_117 ( V_8 , V_319 -> V_308 , V_307 ) ;
F_46 ( & V_319 -> V_105 ) ;
F_12 ( & V_8 -> V_20 -> V_11 , L_60 ,
V_319 -> V_308 , V_319 -> V_310 ) ;
F_15 ( V_319 ) ;
}
F_21 (mv_dev, dev_next, &mhba->mhba_dev_list, list) {
F_46 ( & V_319 -> V_105 ) ;
F_12 ( & V_8 -> V_20 -> V_11 , L_60 ,
V_319 -> V_308 , V_319 -> V_310 ) ;
F_15 ( V_319 ) ;
}
if ( V_8 -> V_20 -> V_128 == V_228 )
V_306 = F_118 ( V_8 -> V_139 , 0 ,
V_8 -> V_152 - 1 , 0 ) ;
if ( V_306 ) {
F_119 ( V_306 ) ;
F_120 ( V_306 ) ;
}
F_125 ( & V_8 -> V_321 ) ;
}
static void F_126 ( struct V_7 * V_8 , int V_308 )
{
struct V_305 * V_306 ;
V_306 = F_118 ( V_8 -> V_139 , 0 , V_308 , 0 ) ;
if ( V_306 ) {
F_127 ( & V_306 -> V_322 ) ;
F_120 ( V_306 ) ;
}
}
static int F_128 ( struct V_7 * V_8 , int V_308 , T_3 V_310 )
{
struct V_318 * V_319 = NULL ;
F_129 (mv_dev, &mhba->shost_dev_list, list) {
if ( V_319 -> V_310 == V_310 ) {
if ( V_319 -> V_308 != V_308 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_61
L_62 ,
V_323 , V_319 -> V_310 , V_319 -> V_308 , V_308 ) ;
return - 1 ;
} else {
if ( V_8 -> V_20 -> V_128 ==
V_267 )
F_126 ( V_8 , V_308 ) ;
return 1 ;
}
}
}
return 0 ;
}
static void F_130 ( struct V_7 * V_8 , int V_308 )
{
struct V_318 * V_319 = NULL , * V_320 ;
F_21 (mv_dev, dev_next,
&mhba->shost_dev_list, list) {
if ( V_319 -> V_308 == V_308 ) {
F_12 ( & V_8 -> V_20 -> V_11 ,
L_63 ,
V_319 -> V_308 , V_319 -> V_310 ) ;
F_117 ( V_8 , V_319 -> V_308 , V_307 ) ;
F_46 ( & V_319 -> V_105 ) ;
F_15 ( V_319 ) ;
}
}
}
static int F_131 ( struct V_7 * V_8 )
{
int V_308 , V_324 ;
T_3 V_310 = 0 ;
struct V_318 * V_319 = NULL ;
struct V_48 * V_49 = NULL ;
int V_325 = 0 ;
V_49 = F_38 ( V_8 , 64 ) ;
if ( ! V_49 )
return - 1 ;
if ( V_8 -> V_20 -> V_128 == V_267 )
V_324 = V_8 -> V_152 ;
else
V_324 = V_8 -> V_152 - 1 ;
for ( V_308 = 0 ; V_308 < V_324 ; V_308 ++ ) {
V_310 = F_122 ( V_8 , V_308 , V_49 ) ;
if ( ! V_310 ) {
F_130 ( V_8 , V_308 ) ;
} else {
V_325 = F_128 ( V_8 , V_308 , V_310 ) ;
if ( ! V_325 ) {
F_130 ( V_8 , V_308 ) ;
V_319 = F_14 ( sizeof( struct V_318 ) ,
V_56 ) ;
if ( ! V_319 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_64 ,
V_323 ) ;
continue;
}
V_319 -> V_308 = V_308 ;
V_319 -> V_310 = V_310 ;
V_319 -> V_306 = NULL ;
F_18 ( & V_319 -> V_105 ) ;
F_19 ( & V_319 -> V_105 ,
& V_8 -> V_326 ) ;
F_12 ( & V_8 -> V_20 -> V_11 ,
L_65
L_66 , V_308 , V_319 -> V_310 ) ;
} else if ( V_325 == - 1 )
return - 1 ;
else
continue;
}
}
if ( V_49 )
F_40 ( V_8 , V_49 ) ;
return 0 ;
}
static int F_132 ( void * V_106 )
{
int V_124 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) V_106 ;
struct V_318 * V_319 = NULL , * V_320 ;
while ( ! F_133 () ) {
F_134 ( V_327 ) ;
if ( ! F_55 ( & V_8 -> V_328 ) )
F_135 () ;
F_71 ( 1000 ) ;
F_95 ( & V_8 -> V_328 , 0 ) ;
F_136 ( V_329 ) ;
F_124 ( & V_8 -> V_321 ) ;
V_124 = F_131 ( V_8 ) ;
if ( ! V_124 ) {
F_21 (mv_dev, dev_next,
&mhba->mhba_dev_list, list) {
if ( F_117 ( V_8 , V_319 -> V_308 ,
V_309 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_67
L_68 ,
V_323 ,
V_319 -> V_308 , V_319 -> V_310 ) ;
F_46 ( & V_319 -> V_105 ) ;
F_15 ( V_319 ) ;
} else {
F_137 ( & V_319 -> V_105 ,
& V_8 -> V_330 ) ;
}
}
}
F_125 ( & V_8 -> V_321 ) ;
}
return 0 ;
}
static void F_138 ( struct V_7 * V_8 ,
struct V_331 * V_332 )
{
T_4 V_3 = V_332 -> V_3 ;
const unsigned long * V_333 ;
const unsigned long * V_334 ;
int V_335 ;
if ( V_8 -> V_28 & V_336 ) {
V_335 = - 1 ;
V_333 = ( const unsigned long * ) V_332 -> V_337 ;
V_334 = ( const unsigned long * ) & V_332 -> V_337 [ V_3 >> 3 ] ;
F_124 ( & V_8 -> V_338 ) ;
do {
V_335 = F_139 ( V_333 , V_3 , V_335 + 1 ) ;
if ( V_335 >= V_3 )
break;
F_117 ( V_8 , V_335 , V_309 ) ;
} while ( 1 );
V_335 = - 1 ;
do {
V_335 = F_139 ( V_334 , V_3 , V_335 + 1 ) ;
if ( V_335 >= V_3 )
break;
F_117 ( V_8 , V_335 , V_307 ) ;
} while ( 1 );
F_125 ( & V_8 -> V_338 ) ;
}
}
static void F_140 ( struct V_7 * V_8 , V_218 V_339 , void * V_340 )
{
if ( V_339 == V_341 ) {
int V_4 , V_76 ;
struct V_294 * V_332 = NULL ;
struct V_342 * V_343 = V_340 ;
V_76 = V_343 -> V_76 ;
if ( V_76 > V_344 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_69
L_70 ,
V_76 , V_344 ) ;
return;
}
for ( V_4 = 0 ; V_4 < V_76 ; V_4 ++ ) {
V_332 = & V_343 -> V_345 [ V_4 ] ;
F_115 ( V_8 , V_332 ) ;
}
} else if ( V_339 == V_346 ) {
F_138 ( V_8 , V_340 ) ;
}
}
static int F_141 ( struct V_7 * V_8 , unsigned char V_339 )
{
struct V_48 * V_49 ;
struct V_148 * V_51 ;
V_49 = F_38 ( V_8 , 512 ) ;
if ( ! V_49 )
return - 1 ;
V_49 -> V_31 = NULL ;
V_49 -> V_136 = V_137 ;
F_95 ( & V_49 -> V_138 , 0 ) ;
V_51 = V_49 -> V_51 ;
V_51 -> V_149 = 0 ;
V_51 -> V_157 = V_313 ;
V_51 -> V_155 = V_156 ;
V_51 -> V_160 = V_161 ;
V_51 -> V_159 = sizeof( struct V_342 ) ;
memset ( V_51 -> V_162 , 0 , V_161 ) ;
V_51 -> V_162 [ 0 ] = V_347 ;
V_51 -> V_162 [ 1 ] = V_339 ;
F_87 ( V_8 , V_49 ) ;
if ( V_49 -> V_136 != V_166 )
F_11 ( & V_8 -> V_20 -> V_11 , L_71 ,
V_49 -> V_136 ) ;
else
F_140 ( V_8 , V_49 -> V_51 -> V_162 [ 1 ] , V_49 -> V_54 ) ;
F_40 ( V_8 , V_49 ) ;
return 0 ;
}
static void F_142 ( struct V_348 * V_349 )
{
struct V_350 * V_351 =
F_143 ( V_349 , struct V_350 , V_352 ) ;
F_141 ( V_351 -> V_8 , V_351 -> V_353 ) ;
F_15 ( V_351 ) ;
}
static void F_144 ( struct V_7 * V_8 , T_2 V_271 )
{
struct V_350 * V_351 ;
while ( V_271 & ( V_354 | V_355 ) ) {
if ( V_271 & V_354 ) {
F_58 ( & V_8 -> V_328 ) ;
F_145 ( V_8 -> V_356 ) ;
V_271 &= ~ ( V_354 ) ;
continue;
}
V_351 = F_14 ( sizeof( * V_351 ) , V_19 ) ;
if ( V_351 ) {
F_146 ( & V_351 -> V_352 , F_142 ) ;
V_351 -> V_8 = V_8 ;
V_351 -> V_353 = V_341 ;
V_271 &= ~ ( V_355 ) ;
V_351 -> V_332 = NULL ;
F_147 ( & V_351 -> V_352 ) ;
}
}
}
static void F_148 ( struct V_7 * V_8 )
{
struct V_85 * V_279 ;
struct V_48 * V_49 ;
struct V_100 * V_357 ;
while ( ! F_44 ( & V_8 -> V_107 ) ) {
V_357 = F_50 ( & V_8 -> V_107 ,
struct V_100 , V_105 ) ;
F_46 ( & V_357 -> V_105 ) ;
F_19 ( & V_357 -> V_105 , & V_8 -> V_104 ) ;
V_279 = (struct V_85 * ) & V_357 -> V_106 [ 0 ] ;
V_49 = V_8 -> V_91 [ V_279 -> V_9 ] ;
F_91 ( & V_8 -> V_75 ) ;
V_8 -> V_91 [ V_279 -> V_9 ] = 0 ;
F_4 ( V_8 , & V_8 -> V_90 , V_279 -> V_9 ) ;
if ( V_49 -> V_31 )
F_110 ( V_8 , V_49 , V_279 ) ;
else
F_113 ( V_8 , V_49 , V_279 ) ;
}
V_8 -> V_102 -> V_141 ( V_8 , NULL ) ;
}
static T_5 F_149 ( int V_358 , void * V_359 )
{
struct V_7 * V_8 = (struct V_7 * ) V_359 ;
unsigned long V_44 ;
F_88 ( V_8 -> V_139 -> V_140 , V_44 ) ;
if ( F_54 ( V_8 -> V_102 -> V_360 ( V_8 ) || ! V_8 -> V_273 ) ) {
F_89 ( V_8 -> V_139 -> V_140 , V_44 ) ;
return V_361 ;
}
if ( V_8 -> V_273 & V_8 -> V_70 -> V_278 ) {
if ( V_8 -> V_271 & ( V_354 | V_355 ) )
F_144 ( V_8 , V_8 -> V_271 ) ;
if ( V_8 -> V_271 & V_274 ) {
F_47 ( & V_8 -> V_20 -> V_11 , L_72 ) ;
F_102 ( V_8 ) ;
}
}
if ( V_8 -> V_273 & V_8 -> V_70 -> V_263 )
F_65 ( V_8 ) ;
V_8 -> V_273 = 0 ;
V_8 -> V_271 = 0 ;
if ( V_8 -> V_113 == V_270 )
F_148 ( V_8 ) ;
F_89 ( V_8 -> V_139 -> V_140 , V_44 ) ;
return V_362 ;
}
static enum V_363 F_150 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
void * V_78 ;
struct V_148 * V_66 ;
unsigned int V_364 ;
V_66 = V_49 -> V_51 ;
if ( F_54 ( V_8 -> V_113 != V_270 ) ) {
F_12 ( & V_8 -> V_20 -> V_11 , L_73 ) ;
return V_365 ;
}
if ( F_5 ( & V_8 -> V_90 ) ) {
F_12 ( & V_8 -> V_20 -> V_11 , L_74 ) ;
return V_365 ;
}
F_57 ( V_8 , & V_78 ) ;
V_49 -> V_51 -> V_9 = F_3 ( V_8 , & V_8 -> V_90 ) ;
V_49 -> V_51 -> V_87 = V_8 -> V_366 ++ ;
V_49 -> V_87 = V_49 -> V_51 -> V_87 ;
V_8 -> V_91 [ V_49 -> V_51 -> V_9 ] = V_49 ;
V_364 = sizeof( * V_66 ) - 4 +
V_66 -> V_53 * sizeof( struct V_36 ) ;
if ( V_8 -> V_62 & V_63 ) {
struct V_82 * V_367 ;
V_367 = V_78 ;
V_367 -> V_368 =
F_29 ( F_30 ( V_49 -> V_59 ) ) ;
V_367 -> V_369 =
F_29 ( F_31 ( V_49 -> V_59 ) ) ;
V_367 -> V_370 = ( V_364 >> 2 ) & 0xFFF ;
} else {
memcpy ( V_78 , V_66 , V_364 ) ;
}
return V_371 ;
}
static void F_151 ( struct V_7 * V_8 , struct V_48 * V_49 )
{
unsigned short V_372 = 0 ;
unsigned int V_76 ;
enum V_363 V_280 ;
if ( V_49 )
F_19 ( & V_49 -> V_57 , & V_8 -> V_373 ) ;
V_76 = V_8 -> V_102 -> V_374 ( V_8 ) ;
if ( F_44 ( & V_8 -> V_373 ) || ! V_76 )
return;
do {
V_49 = F_50 ( & V_8 -> V_373 ,
struct V_48 , V_57 ) ;
F_46 ( & V_49 -> V_57 ) ;
V_280 = F_150 ( V_8 , V_49 ) ;
switch ( V_280 ) {
case V_371 :
V_372 ++ ;
break;
case V_365 :
F_152 ( & V_49 -> V_57 , & V_8 -> V_373 ) ;
if ( V_372 > 0 )
F_59 ( V_8 ) ;
return;
}
} while ( ! F_44 ( & V_8 -> V_373 ) && V_76 -- );
if ( V_372 > 0 )
F_59 ( V_8 ) ;
}
static void F_153 ( struct V_7 * V_8 )
{
unsigned int V_375 ;
struct V_69 * V_70 = V_8 -> V_70 ;
F_60 ( V_70 -> V_276 , V_70 -> V_277 ) ;
V_375 = F_53 ( V_70 -> V_108 ) ;
V_375 |= V_70 -> V_278 | V_70 -> V_263 | V_70 -> V_264 ;
F_60 ( V_375 , V_70 -> V_108 ) ;
}
static void F_154 ( struct V_7 * V_8 )
{
unsigned int V_375 ;
struct V_69 * V_70 = V_8 -> V_70 ;
F_60 ( 0 , V_70 -> V_277 ) ;
V_375 = F_53 ( V_70 -> V_108 ) ;
V_375 &= ~ ( V_70 -> V_278 | V_70 -> V_263 |
V_70 -> V_264 ) ;
F_60 ( V_375 , V_70 -> V_108 ) ;
}
static int F_155 ( void * V_376 )
{
struct V_7 * V_8 = (struct V_7 * ) V_376 ;
unsigned int V_304 , V_271 = 0 , V_27 = 0 ;
struct V_69 * V_70 = V_8 -> V_70 ;
V_304 = F_53 ( V_70 -> V_377 ) ;
if ( ! ( V_304 & V_70 -> V_378 ) || V_304 == 0xFFFFFFFF )
return 1 ;
if ( F_54 ( V_304 & V_70 -> V_264 ) ) {
V_27 = F_53 ( V_70 -> V_379 ) ;
if ( V_8 -> V_20 -> V_128 == V_228 ) {
if ( V_27 & V_70 -> V_380 ) {
F_60 ( V_27 & V_70 -> V_380 ,
V_70 -> V_379 ) ;
}
} else {
if ( V_27 & ( V_70 -> V_381 | V_70 -> V_380 ) )
F_60 ( V_27 & ( V_70 -> V_381 |
V_70 -> V_380 ) ,
V_70 -> V_379 ) ;
}
V_304 ^= V_8 -> V_70 -> V_264 ;
}
if ( V_304 & V_70 -> V_263 ) {
V_27 = F_53 ( V_70 -> V_379 ) ;
if ( V_27 & V_70 -> V_382 )
F_60 ( V_27 & V_70 -> V_382 , V_70 -> V_379 ) ;
}
if ( V_304 & V_70 -> V_278 ) {
V_271 = F_53 ( V_70 -> V_275 ) ;
if ( V_271 )
F_60 ( V_271 , V_70 -> V_275 ) ;
}
V_8 -> V_273 = V_304 ;
V_8 -> V_271 = V_271 ;
return 0 ;
}
static unsigned int F_156 ( struct V_7 * V_8 )
{
unsigned int V_304 ;
V_304 = F_53 ( V_8 -> V_70 -> V_275 ) ;
if ( V_304 )
F_60 ( V_304 , V_8 -> V_70 -> V_275 ) ;
return V_304 ;
}
static int F_157 ( struct V_305 * V_306 )
{
struct V_7 * V_8 ;
unsigned char V_151 = sizeof( unsigned char ) * 8 ;
V_8 = (struct V_7 * ) V_306 -> V_129 -> V_130 ;
if ( V_306 -> V_308 >= V_8 -> V_152 )
return - V_383 ;
V_8 -> V_153 [ V_306 -> V_308 / V_151 ] |= ( 1 << ( V_306 -> V_308 % V_151 ) ) ;
return 0 ;
}
static unsigned char F_158 ( struct V_7 * V_8 ,
struct V_30 * V_31 , struct V_48 * V_49 )
{
struct V_148 * V_384 ;
V_49 -> V_31 = V_31 ;
V_49 -> V_136 = V_137 ;
V_384 = V_49 -> V_51 ;
V_384 -> V_149 = ( ( unsigned short ) V_31 -> V_128 -> V_308 ) |
( ( ( unsigned short ) V_31 -> V_128 -> V_385 ) << 8 ) ;
V_384 -> V_157 = 0 ;
switch ( V_31 -> V_40 ) {
case V_386 :
V_384 -> V_157 |= V_158 ;
break;
case V_387 :
V_384 -> V_157 |= V_313 ;
break;
case V_388 :
V_384 -> V_157 |= V_389 ;
break;
case V_390 :
default:
F_47 ( & V_8 -> V_20 -> V_11 , L_75
L_76 , V_31 -> V_40 , V_31 -> V_133 [ 0 ] ) ;
goto error;
}
V_384 -> V_160 = V_31 -> V_391 ;
memcpy ( V_384 -> V_162 , V_31 -> V_133 , V_384 -> V_160 ) ;
V_384 -> V_155 = V_156 ;
if ( F_35 ( V_31 ) ) {
if ( F_24 ( V_8 , V_31 , & V_384 -> V_52 [ 0 ] ,
& V_384 -> V_53 ) )
goto error;
V_384 -> V_159 = F_35 ( V_31 ) ;
} else {
V_384 -> V_53 = 0 ;
V_384 -> V_159 = 0 ;
}
return 0 ;
error:
V_31 -> V_280 = ( V_282 << 16 ) | ( V_290 << 24 ) |
V_285 ;
F_159 ( 0 , V_31 -> V_288 , V_392 , 0x24 ,
0 ) ;
return - 1 ;
}
static int F_160 ( struct V_393 * V_139 ,
struct V_30 * V_31 )
{
struct V_48 * V_49 ;
struct V_7 * V_8 ;
unsigned long V_394 ;
F_88 ( V_139 -> V_140 , V_394 ) ;
F_161 ( V_139 , V_31 ) ;
V_8 = (struct V_7 * ) V_139 -> V_130 ;
V_31 -> V_280 = 0 ;
V_49 = F_42 ( V_8 ) ;
if ( F_54 ( ! V_49 ) ) {
F_89 ( V_139 -> V_140 , V_394 ) ;
return V_395 ;
}
if ( F_54 ( F_158 ( V_8 , V_31 , V_49 ) ) )
goto V_396;
V_49 -> V_31 = V_31 ;
V_31 -> V_46 . V_170 = ( char * ) V_49 ;
V_8 -> V_102 -> V_141 ( V_8 , V_49 ) ;
F_89 ( V_139 -> V_140 , V_394 ) ;
return 0 ;
V_396:
F_48 ( V_8 , V_49 ) ;
V_31 -> V_293 ( V_31 ) ;
F_89 ( V_139 -> V_140 , V_394 ) ;
return 0 ;
}
static enum V_397 F_162 ( struct V_30 * V_31 )
{
struct V_48 * V_49 = (struct V_48 * ) V_31 -> V_46 . V_170 ;
struct V_393 * V_129 = V_31 -> V_128 -> V_129 ;
struct V_7 * V_8 = F_163 ( V_129 ) ;
unsigned long V_44 ;
F_88 ( V_8 -> V_139 -> V_140 , V_44 ) ;
if ( V_8 -> V_91 [ V_49 -> V_51 -> V_9 ] ) {
V_8 -> V_91 [ V_49 -> V_51 -> V_9 ] = 0 ;
F_4 ( V_8 , & V_8 -> V_90 , V_49 -> V_51 -> V_9 ) ;
}
if ( ! F_44 ( & V_49 -> V_57 ) )
F_46 ( & V_49 -> V_57 ) ;
else
F_91 ( & V_8 -> V_75 ) ;
V_31 -> V_280 = ( V_291 << 24 ) | ( V_292 << 16 ) ;
V_31 -> V_46 . V_170 = NULL ;
if ( F_35 ( V_31 ) ) {
if ( F_25 ( V_31 ) ) {
F_111 ( V_8 -> V_20 ,
F_26 ( V_31 ) ,
F_25 ( V_31 ) ,
( int ) V_31 -> V_40 ) ;
} else {
F_112 ( V_8 -> V_20 ,
V_31 -> V_46 . V_47 ,
F_35 ( V_31 ) ,
( int ) V_31 -> V_40 ) ;
V_31 -> V_46 . V_47 = 0 ;
}
}
F_48 ( V_8 , V_49 ) ;
F_89 ( V_8 -> V_139 -> V_140 , V_44 ) ;
return V_398 ;
}
static int
F_164 ( struct V_305 * V_306 , struct V_399 * V_400 ,
T_6 V_401 , int V_402 [] )
{
int V_403 , V_404 ;
T_6 V_405 ;
unsigned long V_27 ;
V_403 = 64 ;
V_404 = 32 ;
V_27 = V_403 * V_404 ;
V_405 = V_401 ;
F_165 ( V_405 , V_27 ) ;
if ( V_401 >= 0x200000 ) {
V_403 = 255 ;
V_404 = 63 ;
V_27 = V_403 * V_404 ;
V_405 = V_401 ;
F_165 ( V_405 , V_27 ) ;
}
V_402 [ 0 ] = V_403 ;
V_402 [ 1 ] = V_404 ;
V_402 [ 2 ] = V_405 ;
return 0 ;
}
static int F_166 ( struct V_7 * V_8 )
{
void * V_406 = NULL ;
struct V_69 * V_70 ;
switch ( V_8 -> V_20 -> V_128 ) {
case V_267 :
V_8 -> V_407 = V_8 -> V_144 [ 0 ] ;
V_406 = V_8 -> V_407 ;
if ( ! V_8 -> V_70 ) {
V_8 -> V_70 = F_14 ( sizeof( * V_70 ) , V_56 ) ;
if ( V_8 -> V_70 == NULL )
return - V_15 ;
}
V_70 = V_8 -> V_70 ;
V_70 -> V_408 = V_406 + 0x20104 ;
V_70 -> V_409 = V_406 + 0x20108 ;
V_70 -> V_410 = V_406 + 0x2010C ;
V_70 -> V_377 = V_406 + 0x20200 ;
V_70 -> V_108 = V_406 + 0x2020C ;
V_70 -> V_411 = V_406 + 0xF1400 ;
V_70 -> V_112 = V_406 + 0x20400 ;
V_70 -> V_275 = V_406 + 0x20408 ;
V_70 -> V_277 = V_406 + 0x2040C ;
V_70 -> V_253 = V_406 + 0x20430 ;
V_70 -> V_252 = V_406 + 0x20434 ;
V_70 -> V_247 = V_406 + 0x20438 ;
V_70 -> V_109 = V_406 + 0x2043C ;
V_70 -> V_265 = V_406 + 0x508 ;
V_70 -> V_266 = V_406 + 0x50C ;
V_70 -> V_83 = V_406 + 0x518 ;
V_70 -> V_71 = V_406 + 0x51C ;
V_70 -> V_412 = V_406 + 0x568 ;
V_70 -> V_268 = V_406 + 0x5B0 ;
V_70 -> V_269 = V_406 + 0x5B4 ;
V_70 -> V_96 = V_406 + 0x544 ;
V_70 -> V_99 = V_406 + 0x548 ;
V_70 -> V_379 = V_406 + 0x560 ;
V_70 -> V_412 = V_406 + 0x568 ;
V_70 -> V_263 = 1 << 8 ;
V_70 -> V_264 = 1 << 6 ;
V_70 -> V_278 = 1 << 1 ;
V_70 -> V_74 = 1 << 12 ;
V_70 -> V_382 = 1 << 1 ;
V_70 -> V_381 = 1 << 8 ;
V_70 -> V_380 = 1 << 12 ;
V_70 -> V_72 = 0xFFF ;
V_70 -> V_276 = 0x3FFFFFFF ;
V_70 -> V_378 = V_70 -> V_278 | V_70 -> V_263 |
V_70 -> V_264 ;
break;
case V_228 :
V_8 -> V_407 = V_8 -> V_144 [ 2 ] ;
V_406 = V_8 -> V_407 ;
if ( ! V_8 -> V_70 ) {
V_8 -> V_70 = F_14 ( sizeof( * V_70 ) , V_56 ) ;
if ( V_8 -> V_70 == NULL )
return - V_15 ;
}
V_70 = V_8 -> V_70 ;
V_70 -> V_408 = V_406 + 0x20104 ;
V_70 -> V_409 = V_406 + 0x1010C ;
V_70 -> V_410 = V_406 + 0x10108 ;
V_70 -> V_377 = V_406 + 0x10200 ;
V_70 -> V_108 = V_406 + 0x1020C ;
V_70 -> V_411 = V_406 + 0xF1400 ;
V_70 -> V_112 = V_406 + 0x10460 ;
V_70 -> V_275 = V_406 + 0x10480 ;
V_70 -> V_277 = V_406 + 0x10484 ;
V_70 -> V_253 = V_406 + 0x10400 ;
V_70 -> V_252 = V_406 + 0x10404 ;
V_70 -> V_247 = V_406 + 0x10420 ;
V_70 -> V_109 = V_406 + 0x10424 ;
V_70 -> V_127 = V_406 + 0x10108 ;
V_70 -> V_126 = V_406 + 0x1010c ;
V_70 -> V_265 = V_406 + 0x4008 ;
V_70 -> V_266 = V_406 + 0x400C ;
V_70 -> V_83 = V_406 + 0x4018 ;
V_70 -> V_71 = V_406 + 0x401C ;
V_70 -> V_268 = V_406 + 0x4058 ;
V_70 -> V_269 = V_406 + 0x405C ;
V_70 -> V_96 = V_406 + 0x406C ;
V_70 -> V_99 = V_406 + 0x4070 ;
V_70 -> V_412 = V_406 + 0x4080 ;
V_70 -> V_379 = V_406 + 0x4088 ;
V_70 -> V_263 = 1 << 4 ;
V_70 -> V_278 = 1 << 12 ;
V_70 -> V_264 = 1 << 29 ;
V_70 -> V_74 = 1 << 14 ;
V_70 -> V_72 = 0x3FFF ;
V_70 -> V_382 = 1 << 0 ;
V_70 -> V_380 = 1 << 1 ;
V_70 -> V_276 = 0x3FFFFFFF ;
V_70 -> V_378 = V_70 -> V_278 | V_70 -> V_263 ;
break;
default:
return - 1 ;
break;
}
return 0 ;
}
static int F_167 ( struct V_7 * V_8 )
{
int V_124 = 0 ;
if ( F_168 ( V_8 -> V_20 , V_413 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_77 ) ;
return - V_414 ;
}
V_124 = F_9 ( V_8 -> V_20 , V_8 -> V_144 ) ;
if ( V_124 )
goto V_415;
switch ( V_8 -> V_20 -> V_128 ) {
case V_267 :
V_8 -> V_102 = & V_416 ;
V_8 -> V_366 = 0 ;
V_8 -> V_41 = V_417 ;
V_8 -> V_92 = 1 ;
break;
case V_228 :
V_8 -> V_102 = & V_418 ;
V_8 -> V_366 = 0 ;
V_8 -> V_41 = V_417 ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_78 ,
V_8 -> V_20 -> V_128 ) ;
V_8 -> V_102 = NULL ;
V_124 = - V_383 ;
goto V_419;
}
F_12 ( & V_8 -> V_20 -> V_11 , L_79 ,
V_8 -> V_20 -> V_128 ) ;
V_124 = F_166 ( V_8 ) ;
if ( V_124 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_80 ) ;
V_124 = - V_15 ;
goto V_419;
}
V_8 -> V_146 = F_39 ( V_8 -> V_20 , V_145 ,
& V_8 -> V_147 ) ;
if ( ! V_8 -> V_146 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_81 ) ;
V_124 = - V_15 ;
goto V_420;
}
if ( F_68 ( V_8 ) ) {
V_124 = - V_383 ;
goto V_421;
}
V_124 = F_51 ( V_8 ) ;
if ( V_124 )
goto V_421;
return 0 ;
V_421:
F_20 ( V_8 ) ;
F_22 ( V_8 -> V_20 , V_145 ,
V_8 -> V_146 , V_8 -> V_147 ) ;
V_420:
F_15 ( V_8 -> V_70 ) ;
V_419:
F_6 ( V_8 -> V_20 , V_8 -> V_144 ) ;
V_415:
F_93 ( V_8 -> V_20 ) ;
return V_124 ;
}
static int F_169 ( struct V_7 * V_8 )
{
struct V_393 * V_129 = V_8 -> V_139 ;
struct V_305 * V_306 = NULL ;
int V_124 ;
unsigned int V_422 = ( V_8 -> V_58 + 4 -
sizeof( struct V_148 ) ) / sizeof( struct V_36 ) ;
V_129 -> V_358 = V_8 -> V_20 -> V_358 ;
V_129 -> V_423 = V_8 -> V_423 ;
V_129 -> V_424 = ( V_8 -> V_64 - 1 ) ? ( V_8 -> V_64 - 1 ) : 1 ;
V_129 -> V_425 = V_8 -> V_41 > V_422 ? V_422 : V_8 -> V_41 ;
V_129 -> V_426 = V_8 -> V_236 / 512 ;
V_129 -> V_427 = ( V_8 -> V_64 - 1 ) ? ( V_8 -> V_64 - 1 ) : 1 ;
V_129 -> V_428 = V_8 -> V_152 ;
V_129 -> V_429 = V_161 ;
V_129 -> V_430 = & V_431 ;
V_124 = F_170 ( V_129 , & V_8 -> V_20 -> V_11 ) ;
if ( V_124 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_82 ) ;
return V_124 ;
}
V_8 -> V_28 |= V_336 ;
F_124 ( & V_8 -> V_338 ) ;
if ( V_8 -> V_20 -> V_128 == V_228 )
V_124 = F_121 ( V_129 , 0 , V_8 -> V_152 - 1 , 0 ) ;
else
V_124 = 0 ;
if ( V_124 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_83 ) ;
F_125 ( & V_8 -> V_338 ) ;
goto V_432;
}
V_8 -> V_356 = F_171 ( F_132 ,
V_8 , L_84 ) ;
if ( F_172 ( V_8 -> V_356 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_85 ) ;
F_125 ( & V_8 -> V_338 ) ;
goto V_433;
}
F_95 ( & V_8 -> V_328 , 1 ) ;
F_145 ( V_8 -> V_356 ) ;
F_125 ( & V_8 -> V_338 ) ;
return 0 ;
V_433:
if ( V_8 -> V_20 -> V_128 == V_228 )
V_306 = F_118 ( V_8 -> V_139 , 0 ,
V_8 -> V_152 - 1 , 0 ) ;
if ( V_306 ) {
F_119 ( V_306 ) ;
F_120 ( V_306 ) ;
}
V_432:
F_173 ( V_8 -> V_139 ) ;
return V_124 ;
}
static int F_174 ( struct V_10 * V_20 , const struct V_434 * V_308 )
{
struct V_393 * V_129 ;
struct V_7 * V_8 ;
int V_124 ;
F_12 ( & V_20 -> V_11 , L_86 ,
V_20 -> V_435 , V_20 -> V_128 , V_20 -> V_436 ,
V_20 -> V_437 ) ;
V_124 = F_83 ( V_20 ) ;
if ( V_124 )
return V_124 ;
F_78 ( V_20 ) ;
if ( V_125 ) {
V_124 = F_79 ( V_20 , F_80 ( 64 ) ) ;
if ( V_124 ) {
V_124 = F_79 ( V_20 , F_80 ( 32 ) ) ;
if ( V_124 )
goto V_438;
}
} else {
V_124 = F_79 ( V_20 , F_80 ( 32 ) ) ;
if ( V_124 )
goto V_438;
}
V_129 = F_175 ( & V_439 , sizeof( * V_8 ) ) ;
if ( ! V_129 ) {
F_11 ( & V_20 -> V_11 , L_87 ) ;
V_124 = - V_15 ;
goto V_440;
}
V_8 = F_163 ( V_129 ) ;
F_18 ( & V_8 -> V_60 ) ;
F_18 ( & V_8 -> V_104 ) ;
F_18 ( & V_8 -> V_107 ) ;
F_18 ( & V_8 -> V_26 ) ;
F_18 ( & V_8 -> V_373 ) ;
F_176 ( & V_8 -> V_321 ) ;
F_18 ( & V_8 -> V_326 ) ;
F_18 ( & V_8 -> V_330 ) ;
F_95 ( & V_8 -> V_75 , 0 ) ;
F_177 ( & V_8 -> V_142 ) ;
F_176 ( & V_8 -> V_338 ) ;
V_8 -> V_20 = V_20 ;
V_8 -> V_139 = V_129 ;
V_8 -> V_423 = V_20 -> V_441 -> V_442 << 8 | V_20 -> V_443 ;
V_124 = F_167 ( V_8 ) ;
if ( V_124 )
goto V_444;
V_124 = F_178 ( V_8 -> V_20 -> V_358 , F_149 , V_445 ,
L_88 , V_8 ) ;
if ( V_124 ) {
F_11 ( & V_20 -> V_11 , L_89 ) ;
goto V_446;
}
V_8 -> V_102 -> V_447 ( V_8 ) ;
F_179 ( V_20 , V_8 ) ;
V_124 = F_169 ( V_8 ) ;
if ( V_124 )
goto V_448;
F_73 ( V_8 ) ;
F_12 ( & V_20 -> V_11 , L_90 ) ;
return 0 ;
V_448:
V_8 -> V_102 -> V_449 ( V_8 ) ;
F_180 ( V_8 -> V_20 -> V_358 , V_8 ) ;
V_446:
F_92 ( V_8 ) ;
V_444:
F_181 ( V_129 ) ;
V_440:
V_438:
F_82 ( V_20 ) ;
return V_124 ;
}
static void F_182 ( struct V_10 * V_20 )
{
struct V_393 * V_129 ;
struct V_7 * V_8 ;
V_8 = F_183 ( V_20 ) ;
if ( V_8 -> V_356 ) {
F_184 ( V_8 -> V_356 ) ;
V_8 -> V_356 = NULL ;
}
F_123 ( V_8 ) ;
V_129 = V_8 -> V_139 ;
F_173 ( V_8 -> V_139 ) ;
F_94 ( V_8 ) ;
V_8 -> V_102 -> V_449 ( V_8 ) ;
F_180 ( V_8 -> V_20 -> V_358 , V_8 ) ;
F_92 ( V_8 ) ;
F_181 ( V_129 ) ;
F_82 ( V_20 ) ;
F_12 ( & V_20 -> V_11 , L_91 ) ;
}
static void F_185 ( struct V_10 * V_20 )
{
struct V_7 * V_8 = F_183 ( V_20 ) ;
F_94 ( V_8 ) ;
}
static int F_186 ( struct V_10 * V_20 , T_7 V_450 )
{
struct V_7 * V_8 = NULL ;
V_8 = F_183 ( V_20 ) ;
F_94 ( V_8 ) ;
F_179 ( V_20 , V_8 ) ;
V_8 -> V_102 -> V_449 ( V_8 ) ;
F_180 ( V_8 -> V_20 -> V_358 , V_8 ) ;
F_6 ( V_20 , V_8 -> V_144 ) ;
F_93 ( V_20 ) ;
F_187 ( V_20 ) ;
F_82 ( V_20 ) ;
F_188 ( V_20 , F_189 ( V_20 , V_450 ) ) ;
return 0 ;
}
static int F_190 ( struct V_10 * V_20 )
{
int V_124 ;
struct V_7 * V_8 = NULL ;
V_8 = F_183 ( V_20 ) ;
F_188 ( V_20 , V_451 ) ;
F_191 ( V_20 , V_451 , 0 ) ;
F_192 ( V_20 ) ;
V_124 = F_83 ( V_20 ) ;
if ( V_124 ) {
F_11 ( & V_20 -> V_11 , L_25 ) ;
return V_124 ;
}
F_78 ( V_20 ) ;
if ( V_125 ) {
V_124 = F_79 ( V_20 , F_80 ( 64 ) ) ;
if ( V_124 ) {
V_124 = F_79 ( V_20 , F_80 ( 32 ) ) ;
if ( V_124 )
goto V_452;
}
} else {
V_124 = F_79 ( V_20 , F_80 ( 32 ) ) ;
if ( V_124 )
goto V_452;
}
V_124 = F_168 ( V_8 -> V_20 , V_413 ) ;
if ( V_124 )
goto V_452;
V_124 = F_9 ( V_8 -> V_20 , V_8 -> V_144 ) ;
if ( V_124 )
goto V_453;
if ( F_166 ( V_8 ) ) {
V_124 = - V_383 ;
goto V_454;
}
V_8 -> V_407 = V_8 -> V_144 [ 0 ] ;
F_66 ( V_8 ) ;
if ( F_68 ( V_8 ) ) {
V_124 = - V_383 ;
goto V_454;
}
V_124 = F_178 ( V_8 -> V_20 -> V_358 , F_149 , V_445 ,
L_88 , V_8 ) ;
if ( V_124 ) {
F_11 ( & V_20 -> V_11 , L_89 ) ;
goto V_454;
}
V_8 -> V_102 -> V_447 ( V_8 ) ;
return 0 ;
V_454:
F_6 ( V_20 , V_8 -> V_144 ) ;
V_453:
F_93 ( V_20 ) ;
V_452:
F_82 ( V_20 ) ;
return V_124 ;
}
static int T_8 F_193 ( void )
{
return F_194 ( & V_455 ) ;
}
static void T_9 F_195 ( void )
{
F_196 ( & V_455 ) ;
}
