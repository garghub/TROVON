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
memset ( V_18 -> V_22 , 0 , V_3 ) ;
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
memset ( V_22 , 0 , V_3 ) ;
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
V_49 -> V_51 = F_17 ( V_8 -> V_20 ,
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
static void F_39 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
struct V_36 * V_37 ;
unsigned int V_3 ;
T_1 V_50 ;
if ( V_49 && V_49 -> V_51 ) {
if ( V_49 -> V_51 -> V_53 ) {
V_37 = (struct V_36 * ) & V_49 -> V_51 -> V_52 [ 0 ] ;
F_40 ( V_8 , V_37 , V_3 ) ;
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
static struct V_48 * F_41 ( struct V_7 * V_8 )
{
struct V_48 * V_49 = NULL ;
if ( F_42 ( ! F_43 ( & V_8 -> V_60 ) ) ) {
V_49 = F_44 ( ( & V_8 -> V_60 ) -> V_61 ,
struct V_48 , V_57 ) ;
F_45 ( & V_49 -> V_57 ) ;
} else
F_46 ( & V_8 -> V_20 -> V_11 , L_16 ) ;
return V_49 ;
}
static inline void F_47 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
V_49 -> V_31 = NULL ;
F_19 ( & V_49 -> V_57 , & V_8 -> V_60 ) ;
}
static void F_48 ( struct V_7 * V_8 )
{
struct V_48 * V_49 ;
while ( ! F_43 ( & V_8 -> V_60 ) ) {
V_49 = F_49 ( & V_8 -> V_60 , struct V_48 ,
V_57 ) ;
F_23 ( & V_49 -> V_57 ) ;
if ( ! ( V_8 -> V_62 & V_63 ) )
F_15 ( V_49 -> V_51 ) ;
F_15 ( V_49 ) ;
}
}
static int F_50 ( struct V_7 * V_8 )
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
while ( ! F_43 ( & V_8 -> V_60 ) ) {
V_49 = F_49 ( & V_8 -> V_60 , struct V_48 ,
V_57 ) ;
F_23 ( & V_49 -> V_57 ) ;
if ( ! ( V_8 -> V_62 & V_63 ) )
F_15 ( V_49 -> V_51 ) ;
F_15 ( V_49 ) ;
}
return - V_15 ;
}
static unsigned int F_51 ( struct V_7 * V_8 )
{
unsigned int V_68 ;
struct V_69 * V_70 = V_8 -> V_70 ;
V_68 = F_52 ( V_8 -> V_70 -> V_71 ) ;
if ( F_53 ( ( ( V_68 & V_70 -> V_72 ) ==
( V_8 -> V_73 & V_70 -> V_72 ) ) &&
( ( V_68 & V_70 -> V_74 )
!= ( V_8 -> V_73 & V_70 -> V_74 ) ) ) ) {
F_46 ( & V_8 -> V_20 -> V_11 , L_18 ) ;
return 0 ;
}
if ( F_54 ( & V_8 -> V_75 ) >= V_8 -> V_64 ) {
F_46 ( & V_8 -> V_20 -> V_11 , L_19 ) ;
return 0 ;
} else {
return V_8 -> V_64 - F_54 ( & V_8 -> V_75 ) ;
}
}
static unsigned int F_55 ( struct V_7 * V_8 )
{
unsigned int V_76 ;
if ( F_54 ( & V_8 -> V_75 ) >= ( V_8 -> V_64 - 1 ) )
return 0 ;
V_76 = F_52 ( V_8 -> V_77 ) ;
if ( V_76 == 0xffff )
return 0 ;
return V_76 ;
}
static void F_56 ( struct V_7 * V_8 , void * * V_78 )
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
F_57 ( & V_8 -> V_75 ) ;
}
static void F_58 ( struct V_7 * V_8 )
{
F_59 ( 0xffff , V_8 -> V_77 ) ;
F_59 ( V_8 -> V_73 , V_8 -> V_70 -> V_83 ) ;
}
static char F_60 ( struct V_7 * V_8 ,
unsigned int V_84 , struct V_85 * V_86 )
{
unsigned short V_9 , V_87 ;
F_61 ( 1 ) ;
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
static int F_62 ( struct V_7 * V_8 ,
unsigned int * V_84 , unsigned int * V_93 )
{
unsigned int V_94 , V_95 ;
struct V_69 * V_70 = V_8 -> V_70 ;
do {
V_94 = F_52 ( V_70 -> V_96 ) ;
V_95 = F_52 ( V_8 -> V_97 ) ;
} while ( ( V_94 & V_70 -> V_72 ) != V_95 );
* V_84 = V_8 -> V_98 & V_8 -> V_70 -> V_72 ;
* V_93 = V_94 & V_8 -> V_70 -> V_72 ;
if ( ( V_94 & V_70 -> V_74 ) !=
( V_8 -> V_98 & V_70 -> V_74 ) ) {
* V_93 += V_8 -> V_80 ;
}
return 0 ;
}
static int F_63 ( struct V_7 * V_8 ,
unsigned int * V_84 , unsigned int * V_93 )
{
unsigned int V_94 ;
struct V_69 * V_70 = V_8 -> V_70 ;
V_94 = F_52 ( V_70 -> V_99 ) ;
V_94 = F_52 ( V_70 -> V_96 ) ;
* V_84 = V_8 -> V_98 & V_8 -> V_70 -> V_72 ;
* V_93 = V_94 & V_8 -> V_70 -> V_72 ;
if ( * V_93 < * V_84 )
* V_93 += V_8 -> V_80 ;
else if ( * V_93 == * V_84 )
return - 1 ;
return 0 ;
}
static void F_64 ( struct V_7 * V_8 )
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
if ( F_53 ( V_86 -> V_9 > V_8 -> V_90 . V_3 ||
V_8 -> V_91 [ V_86 -> V_9 ] == NULL ||
V_86 -> V_87 !=
V_8 -> V_91 [ V_86 -> V_9 ] -> V_87 ) )
if ( F_60 ( V_8 , V_84 , V_86 ) )
continue;
if ( ! F_43 ( & V_8 -> V_104 ) ) {
V_101 = (struct V_100 * )
F_49 ( & V_8 -> V_104 ,
struct V_100 , V_105 ) ;
F_45 ( & V_101 -> V_105 ) ;
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
F_59 ( V_8 -> V_98 , V_70 -> V_99 ) ;
}
static void F_65 ( struct V_7 * V_8 )
{
struct V_69 * V_70 = V_8 -> V_70 ;
F_59 ( 0 , V_70 -> V_108 ) ;
if ( F_52 ( V_70 -> V_109 ) != V_110 )
return;
F_59 ( V_111 , V_70 -> V_112 ) ;
}
static int F_66 ( struct V_7 * V_8 )
{
V_8 -> V_113 = V_114 ;
F_65 ( V_8 ) ;
if ( F_67 ( V_8 ) )
return V_115 ;
else
return V_116 ;
}
static int F_68 ( struct V_7 * V_8 )
{
struct V_69 * V_70 = V_8 -> V_70 ;
T_2 V_27 ;
unsigned long V_117 ;
V_117 = V_118 ;
F_59 ( 0 , V_70 -> V_108 ) ;
V_27 = F_52 ( V_70 -> V_109 ) ;
while ( V_27 != V_119 ) {
F_59 ( V_120 , V_70 -> V_112 ) ;
if ( F_69 ( V_118 , V_117 + V_121 * V_122 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_24 , V_27 ) ;
return V_115 ;
}
F_70 ( 500 ) ;
F_71 () ;
V_27 = F_52 ( V_70 -> V_109 ) ;
}
return V_116 ;
}
static void F_72 ( struct V_7 * V_8 )
{
unsigned char V_4 ;
for ( V_4 = 0 ; V_4 < V_13 ; V_4 ++ ) {
F_73 ( V_8 -> V_20 , 0x10 + V_4 * 4 ,
& V_8 -> V_123 [ V_4 ] ) ;
}
}
static void F_74 ( struct V_7 * V_8 )
{
unsigned char V_4 ;
for ( V_4 = 0 ; V_4 < V_13 ; V_4 ++ ) {
if ( V_8 -> V_123 [ V_4 ] )
F_75 ( V_8 -> V_20 , 0x10 + V_4 * 4 ,
V_8 -> V_123 [ V_4 ] ) ;
}
}
static unsigned int F_76 ( struct V_10 * V_20 )
{
unsigned int V_124 = 0 ;
F_77 ( V_20 ) ;
if ( V_125 ) {
if ( F_78 ( V_20 , F_79 ( 64 ) ) )
V_124 = F_78 ( V_20 , F_79 ( 32 ) ) ;
} else
V_124 = F_78 ( V_20 , F_79 ( 32 ) ) ;
return V_124 ;
}
static int F_80 ( struct V_7 * V_8 )
{
V_8 -> V_113 = V_114 ;
F_59 ( 0 , V_8 -> V_70 -> V_126 ) ;
F_59 ( 0xf , V_8 -> V_70 -> V_127 ) ;
F_59 ( 0x10 , V_8 -> V_70 -> V_126 ) ;
F_59 ( 0x10 , V_8 -> V_70 -> V_127 ) ;
F_70 ( 100 ) ;
F_81 ( V_8 -> V_20 ) ;
if ( F_82 ( V_8 -> V_20 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_25 ) ;
return V_115 ;
}
if ( F_76 ( V_8 -> V_20 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_26 ) ;
return V_115 ;
}
F_74 ( V_8 ) ;
if ( F_68 ( V_8 ) == V_115 )
return V_115 ;
return F_66 ( V_8 ) ;
}
static int F_83 ( struct V_7 * V_8 )
{
return F_66 ( V_8 ) ;
}
static int F_84 ( struct V_30 * V_31 )
{
struct V_7 * V_8 ;
V_8 = (struct V_7 * ) V_31 -> V_128 -> V_129 -> V_130 ;
F_85 ( V_131 , V_31 , L_27 ,
V_31 -> V_132 , V_31 -> V_133 [ 0 ] , V_31 -> V_134 ) ;
return V_8 -> V_102 -> V_135 ( V_8 ) ;
}
static int F_86 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
unsigned long V_44 ;
V_49 -> V_136 = V_137 ;
if ( F_54 ( & V_49 -> V_138 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_28 ,
F_54 ( & V_49 -> V_138 ) ) ;
F_2 ( 1 ) ;
return - 1 ;
}
F_57 ( & V_49 -> V_138 ) ;
F_87 ( V_8 -> V_139 -> V_140 , V_44 ) ;
V_8 -> V_102 -> V_141 ( V_8 , V_49 ) ;
F_88 ( V_8 -> V_139 -> V_140 , V_44 ) ;
F_89 ( V_8 -> V_142 ,
( V_49 -> V_136 != V_137 ) ,
V_143 * V_122 ) ;
if ( F_54 ( & V_49 -> V_138 ) ) {
F_87 ( V_8 -> V_139 -> V_140 , V_44 ) ;
F_90 ( & V_49 -> V_138 ) ;
if ( V_8 -> V_91 [ V_49 -> V_51 -> V_9 ] ) {
V_8 -> V_91 [ V_49 -> V_51 -> V_9 ] = 0 ;
F_46 ( & V_8 -> V_20 -> V_11 , L_29 ,
V_49 -> V_51 -> V_9 ) ;
F_4 ( V_8 , & V_8 -> V_90 , V_49 -> V_51 -> V_9 ) ;
}
if ( ! F_43 ( & V_49 -> V_57 ) ) {
F_46 ( & V_8 -> V_20 -> V_11 ,
L_30 ) ;
F_45 ( & V_49 -> V_57 ) ;
} else
F_90 ( & V_8 -> V_75 ) ;
F_88 ( V_8 -> V_139 -> V_140 , V_44 ) ;
}
return 0 ;
}
static void F_91 ( struct V_7 * V_8 )
{
F_48 ( V_8 ) ;
F_20 ( V_8 ) ;
F_6 ( V_8 -> V_20 , V_8 -> V_144 ) ;
F_22 ( V_8 -> V_20 , V_145 ,
V_8 -> V_146 , V_8 -> V_147 ) ;
F_15 ( V_8 -> V_70 ) ;
F_92 ( V_8 -> V_20 ) ;
}
static unsigned char F_93 ( struct V_7 * V_8 )
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
F_94 ( & V_49 -> V_138 , 0 ) ;
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
F_86 ( V_8 , V_49 ) ;
if ( V_49 -> V_136 != V_166 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_34 ,
V_149 , V_49 -> V_136 ) ;
}
F_39 ( V_8 , V_49 ) ;
}
return 0 ;
}
static unsigned char
F_95 ( struct V_167 * V_168 ,
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
static void F_96 ( struct V_7 * V_8 ,
struct V_167 * V_172 )
{
struct V_173 * V_174 ;
struct V_175 * V_176 ;
struct V_177 * V_178 ;
struct V_179 time ;
unsigned int V_180 ;
switch ( V_172 -> V_181 ) {
case V_182 :
V_174 = (struct V_173 * ) V_172 ;
V_172 -> V_183 = sizeof( * V_174 ) - 4 ;
memset ( V_172 -> V_171 , 0 , V_172 -> V_183 ) ;
V_174 -> V_184 = 3 ;
if ( V_8 -> V_62 & V_63 )
V_174 -> V_185 = 0x08 ;
V_174 -> V_186 . V_187 = V_188 ;
V_174 -> V_186 . V_189 = V_190 ;
V_174 -> V_186 . V_191 = V_192 ;
V_174 -> V_186 . V_193 = V_194 ;
V_174 -> V_195 = 0 ;
V_174 -> V_196 = 0 ;
V_174 -> V_197 = 0 ;
V_174 -> V_198 = 0 ;
F_97 ( & time ) ;
V_180 = ( unsigned int ) ( time . V_199 -
( V_200 . V_201 * 60 ) ) ;
V_174 -> V_202 = V_180 ;
V_172 -> V_203 = F_95 ( V_172 ,
V_172 -> V_183 ) ;
break;
case V_204 :
V_178 = (struct V_177 * ) V_172 ;
V_172 -> V_183 = sizeof( * V_178 ) - 4 ;
memset ( V_172 -> V_171 , 0 , V_172 -> V_183 ) ;
V_172 -> V_203 = F_95 ( V_172 ,
V_172 -> V_183 ) ;
break;
case V_205 :
V_176 = (struct V_175 * ) V_172 ;
V_172 -> V_183 = sizeof( * V_176 ) - 4 ;
memset ( V_172 -> V_171 , 0 , V_172 -> V_183 ) ;
V_176 -> V_206 = F_30 ( V_8 -> V_207 ) ;
V_176 -> V_208 = F_31 ( V_8 -> V_207 ) ;
V_176 -> V_209 = F_30 ( V_8 -> V_210 ) ;
V_176 -> V_211 = F_31 ( V_8 -> V_210 ) ;
V_176 -> V_212 = V_8 -> V_213 ;
V_176 -> V_214 = V_8 -> V_215 ;
if ( V_8 -> V_62
& V_216 ) {
V_176 -> V_217 = F_98 ( ( unsigned long * )
& V_8 -> V_80 ,
V_218 ) ;
V_176 -> V_219 = F_98 ( ( unsigned long * )
& V_8 -> V_80 ,
V_218 ) ;
} else {
V_176 -> V_217 = ( V_220 ) V_8 -> V_80 ;
V_176 -> V_219 = ( V_220 ) V_8 -> V_80 ;
}
V_172 -> V_203 = F_95 ( V_172 ,
V_172 -> V_183 ) ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_35 ,
V_172 -> V_181 ) ;
break;
}
}
static int F_99 ( struct V_7 * V_8 )
{
struct V_100 * V_221 ;
struct V_16 * V_222 ;
unsigned int V_223 , V_224 , V_4 ;
void * V_225 , * V_226 ;
T_1 V_227 ;
if ( V_8 -> V_28 & V_29 )
return 0 ;
V_223 = V_8 -> V_58 * V_8 -> V_64 ;
if ( V_8 -> V_62 & V_63 )
V_223 += sizeof( struct V_82 ) * V_8 -> V_64 ;
V_223 += 128 + V_8 -> V_89 * V_8 -> V_64 ;
V_223 += 8 + sizeof( T_2 ) * 2 + 16 ;
V_222 = F_13 ( V_8 ,
V_23 , V_223 ) ;
if ( ! V_222 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_36 ) ;
goto V_228;
}
V_227 = V_222 -> V_24 ;
V_226 = V_222 -> V_22 ;
V_224 = F_16 ( V_227 , 128 ) - V_227 ;
V_227 += V_224 ;
V_226 += V_224 ;
V_8 -> V_81 = V_226 ;
V_8 -> V_207 = V_227 ;
if ( V_8 -> V_62 & V_63 ) {
V_226 += sizeof( struct V_82 ) * V_8 -> V_64 ;
V_227 += sizeof( struct V_82 ) * V_8 -> V_64 ;
V_8 -> V_66 = V_226 ;
V_8 -> V_67 = V_227 ;
}
V_226 += V_8 -> V_58 * V_8 -> V_64 ;
V_227 += V_8 -> V_58 * V_8 -> V_64 ;
V_224 = F_16 ( V_227 , 8 ) - V_227 ;
V_227 += V_224 ;
V_226 += V_224 ;
V_8 -> V_77 = V_226 ;
V_8 -> V_229 = V_227 ;
V_227 += sizeof( T_2 ) * 2 ;
V_226 += sizeof( T_2 ) * 2 ;
if ( V_8 -> V_20 -> V_128 == V_230 ) {
V_224 = F_16 ( V_227 , 8 ) - V_227 ;
V_227 += V_224 ;
V_226 += V_224 ;
V_8 -> V_97 = V_226 ;
V_8 -> V_231 = V_227 ;
V_227 += 8 ;
V_226 += 8 ;
} else {
V_224 = F_16 ( V_227 , 4 ) - V_227 ;
V_227 += V_224 ;
V_226 += V_224 ;
V_8 -> V_97 = V_226 ;
V_8 -> V_231 = V_227 ;
V_227 += 4 ;
V_226 += 4 ;
}
V_224 = F_16 ( V_227 , 128 ) - V_227 ;
V_227 += V_224 ;
V_226 += V_224 ;
V_8 -> V_88 = V_226 ;
V_8 -> V_210 = V_227 ;
V_223 = V_8 -> V_64 * ( V_8 -> V_89 + sizeof( * V_221 ) ) ;
V_223 = F_16 ( V_223 , 8 ) ;
V_222 = F_13 ( V_8 ,
V_21 , V_223 ) ;
if ( ! V_222 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_37 ) ;
goto V_228;
}
V_225 = V_222 -> V_22 ;
for ( V_4 = V_8 -> V_64 ; V_4 != 0 ; V_4 -- ) {
V_221 = (struct V_100 * ) V_225 ;
F_19 ( & V_221 -> V_105 , & V_8 -> V_104 ) ;
V_225 += V_8 -> V_89 + sizeof( * V_221 ) ;
}
V_223 = sizeof( unsigned short ) * V_8 -> V_64 +
sizeof( struct V_48 * ) * V_8 -> V_64 ;
V_223 += F_16 ( V_8 -> V_152 , sizeof( unsigned char ) * 8 ) /
(sizeof( unsigned char ) * 8 ) ;
V_222 = F_13 ( V_8 ,
V_21 , V_223 ) ;
if ( ! V_222 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_38 ) ;
goto V_228;
}
V_225 = V_222 -> V_22 ;
V_8 -> V_90 . V_6 = V_225 ;
V_8 -> V_90 . V_3 = V_8 -> V_64 ;
F_1 ( & V_8 -> V_90 , V_8 -> V_64 ) ;
V_225 += sizeof( unsigned short ) * V_8 -> V_64 ;
V_8 -> V_91 = V_225 ;
V_225 += sizeof( struct V_48 * ) * V_8 -> V_64 ;
V_8 -> V_153 = V_225 ;
V_8 -> V_28 |= V_29 ;
return 0 ;
V_228:
F_20 ( V_8 ) ;
return - 1 ;
}
static int F_100 ( struct V_7 * V_8 ,
struct V_167 * V_172 )
{
struct V_232 * V_233 ;
unsigned char V_234 ;
V_234 = F_95 ( V_172 ,
V_172 -> V_183 ) ;
if ( V_234 != V_172 -> V_203 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_39 ) ;
return - 1 ;
}
switch ( V_172 -> V_181 ) {
case V_235 :
V_233 = (struct V_232 * ) V_172 ;
V_8 -> V_64 = V_233 -> V_236 ;
V_8 -> V_80 = V_233 -> V_237 ;
V_8 -> V_238 = V_233 -> V_238 ;
V_8 -> V_152 = V_233 -> V_239 ;
V_8 -> V_62 = V_233 -> V_240 ;
V_8 -> V_213 = V_233 -> V_241 ;
V_8 -> V_58 = ( 1 << V_233 -> V_241 ) << 2 ;
V_8 -> V_215 = V_233 -> V_242 ;
V_8 -> V_89 = ( 1 << V_233 -> V_242 ) << 2 ;
F_12 ( & V_8 -> V_20 -> V_11 , L_40 ,
V_233 -> V_243 . V_193 ) ;
if ( V_8 -> V_62 & V_244 )
V_8 -> V_45 = 22 ;
else
V_8 -> V_45 = 27 ;
if ( V_8 -> V_62 & V_216 )
V_8 -> V_80 = 1 << V_233 -> V_237 ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_41 ) ;
return - 1 ;
}
return 0 ;
}
static int F_101 ( struct V_7 * V_8 )
{
unsigned int V_245 , V_27 , V_246 ;
struct V_167 * V_172 ;
struct V_69 * V_70 = V_8 -> V_70 ;
if ( V_8 -> V_113 == V_247 )
V_245 = V_248 ;
else {
V_27 = F_52 ( V_70 -> V_249 ) ;
V_245 = F_102 ( V_27 ) ;
F_12 ( & V_8 -> V_20 -> V_11 , L_42 , V_245 ) ;
if ( F_103 ( V_27 ) != V_250 ) {
V_8 -> V_113 = V_247 ;
return - 1 ;
}
}
V_246 = 0 ;
switch ( V_245 ) {
case V_248 :
V_8 -> V_113 = V_251 ;
F_104 ( V_246 , V_250 ) ;
F_105 ( V_246 , V_252 ) ;
F_59 ( V_253 , V_70 -> V_254 ) ;
F_59 ( V_246 , V_70 -> V_255 ) ;
F_59 ( V_256 , V_70 -> V_112 ) ;
break;
case V_252 :
F_59 ( F_30 ( V_8 -> V_147 ) ,
V_70 -> V_254 ) ;
F_59 ( F_31 ( V_8 -> V_147 ) ,
V_70 -> V_109 ) ;
F_104 ( V_246 , V_250 ) ;
F_105 ( V_246 , V_257 ) ;
F_59 ( V_246 , V_70 -> V_255 ) ;
F_59 ( V_256 , V_70 -> V_112 ) ;
break;
case V_257 :
case V_258 :
case V_259 :
V_172 = (struct V_167 * ) V_8 -> V_146 ;
if ( V_172 -> V_181 == V_235 ) {
V_8 -> V_260 =
( (struct V_232 * ) V_172 ) -> V_261 ;
if ( V_8 -> V_260 == 0 )
V_8 -> V_260 = V_262 - 1 ;
}
if ( V_245 == V_258 ) {
if ( F_100 ( V_8 , V_172 ) ) {
F_105 ( V_246 , V_263 ) ;
return - 1 ;
}
if ( F_99 ( V_8 ) ) {
F_105 ( V_246 , V_263 ) ;
return - 1 ;
}
} else if ( V_245 == V_257 ) {
V_172 -> V_181 = 0 ;
V_8 -> V_260 = V_262 - 1 ;
}
if ( ( V_172 -> V_181 + 1 ) <= V_8 -> V_260 ) {
V_172 -> V_181 ++ ;
if ( V_172 -> V_181 != V_235 ) {
F_96 ( V_8 , V_172 ) ;
F_105 ( V_246 , V_259 ) ;
} else
F_105 ( V_246 , V_258 ) ;
} else
F_105 ( V_246 , V_264 ) ;
F_104 ( V_246 , V_250 ) ;
F_59 ( V_246 , V_70 -> V_255 ) ;
F_59 ( V_256 , V_70 -> V_112 ) ;
break;
case V_264 :
V_27 = F_52 ( V_70 -> V_108 ) ;
V_27 |= V_70 -> V_265 | V_70 -> V_266 ;
F_59 ( V_27 , V_70 -> V_108 ) ;
F_59 ( V_8 -> V_80 , V_8 -> V_77 ) ;
F_59 ( F_30 ( V_8 -> V_229 ) ,
V_70 -> V_267 ) ;
F_59 ( F_31 ( V_8 -> V_229 ) ,
V_70 -> V_268 ) ;
if ( V_8 -> V_20 -> V_128 == V_269 ) {
F_59 ( ( V_8 -> V_80 - 1 ) |
V_70 -> V_74 ,
V_8 -> V_97 ) ;
F_59 ( F_30 ( V_8 -> V_231 ) ,
V_70 -> V_270 ) ;
F_59 ( F_31 ( V_8 -> V_231 ) ,
V_70 -> V_271 ) ;
}
V_8 -> V_73 = ( V_8 -> V_80 - 1 ) |
V_70 -> V_74 ;
V_8 -> V_98 = ( V_8 -> V_80 - 1 ) |
V_70 -> V_74 ;
V_8 -> V_113 = V_272 ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_43 ,
V_245 ) ;
return - 1 ;
}
return 0 ;
}
static unsigned char F_106 ( struct V_7 * V_8 )
{
unsigned int V_273 ;
unsigned long V_117 ;
V_117 = V_118 ;
F_101 ( V_8 ) ;
do {
V_273 = V_8 -> V_102 -> V_274 ( V_8 ) ;
if ( V_8 -> V_113 == V_272 )
return 0 ;
if ( F_69 ( V_118 , V_117 + V_121 * V_122 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_44 ,
V_8 -> V_113 ) ;
F_11 ( & V_8 -> V_20 -> V_11 ,
L_45 ,
V_8 -> V_275 , V_273 ) ;
return - 1 ;
}
F_71 () ;
F_107 ( 1000 , 2000 ) ;
} while ( ! ( V_273 & V_276 ) );
return 0 ;
}
static unsigned char F_108 ( struct V_7 * V_8 )
{
unsigned int V_27 ;
unsigned long V_117 ;
V_117 = V_118 ;
V_27 = F_52 ( V_8 -> V_70 -> V_109 ) ;
while ( ( V_27 != V_119 ) && ( V_27 != V_110 ) ) {
if ( V_27 != V_119 )
F_59 ( V_120 ,
V_8 -> V_70 -> V_112 ) ;
if ( F_69 ( V_118 , V_117 + V_121 * V_122 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_46 , V_27 ) ;
return - 1 ;
}
F_107 ( 1000 , 2000 ) ;
F_71 () ;
V_27 = F_52 ( V_8 -> V_70 -> V_109 ) ;
}
V_8 -> V_113 = V_247 ;
F_12 ( & V_8 -> V_20 -> V_11 , L_47 ) ;
do {
if ( F_106 ( V_8 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_48 ,
V_8 -> V_113 ) ;
return - 1 ;
}
} while ( V_8 -> V_113 != V_272 );
F_12 ( & V_8 -> V_20 -> V_11 , L_49 ) ;
return 0 ;
}
static unsigned char F_67 ( struct V_7 * V_8 )
{
unsigned int V_27 ;
struct V_69 * V_70 = V_8 -> V_70 ;
V_27 = F_52 ( V_70 -> V_277 ) ;
F_59 ( V_27 , V_70 -> V_277 ) ;
F_59 ( V_70 -> V_278 , V_70 -> V_279 ) ;
V_27 = F_52 ( V_70 -> V_108 ) | V_70 -> V_280 ;
F_59 ( V_27 , V_70 -> V_108 ) ;
F_70 ( 100 ) ;
if ( F_108 ( V_8 ) )
return - 1 ;
return 0 ;
}
static void F_109 ( struct V_7 * V_8 , struct V_48 * V_49 ,
struct V_85 * V_281 )
{
struct V_30 * V_31 = V_49 -> V_31 ;
V_49 -> V_31 -> V_46 . V_170 = NULL ;
V_31 -> V_282 = V_281 -> V_283 ;
switch ( V_281 -> V_283 ) {
case V_166 :
V_31 -> V_282 |= V_284 << 16 ;
break;
case V_285 :
V_31 -> V_282 |= V_286 << 16 ;
break;
case V_287 :
V_31 -> V_282 |= ( V_284 << 16 ) ;
if ( V_281 -> V_288 & V_289 ) {
memcpy ( V_49 -> V_31 -> V_290 , V_281 -> V_52 ,
sizeof( struct V_291 ) ) ;
V_31 -> V_282 |= ( V_292 << 24 ) ;
}
break;
default:
V_31 -> V_282 |= ( V_293 << 24 ) | ( V_294 << 16 ) ;
break;
}
if ( F_35 ( V_31 ) ) {
if ( F_25 ( V_31 ) ) {
F_110 ( V_8 -> V_20 ,
F_26 ( V_31 ) ,
F_25 ( V_31 ) ,
( int ) V_31 -> V_40 ) ;
} else {
F_111 ( V_8 -> V_20 ,
V_31 -> V_46 . V_47 ,
F_35 ( V_31 ) ,
( int ) V_31 -> V_40 ) ;
V_31 -> V_46 . V_47 = 0 ;
}
}
V_49 -> V_31 -> V_295 ( V_31 ) ;
F_47 ( V_8 , V_49 ) ;
}
static void F_112 ( struct V_7 * V_8 ,
struct V_48 * V_49 ,
struct V_85 * V_281 )
{
if ( F_54 ( & V_49 -> V_138 ) ) {
V_49 -> V_136 = V_281 -> V_283 ;
if ( ( V_281 -> V_283 == V_287 ) &&
( V_281 -> V_288 & V_289 ) &&
V_49 -> V_54 ) {
memcpy ( V_49 -> V_54 , V_281 -> V_52 ,
sizeof( struct V_291 ) ) ;
}
F_90 ( & V_49 -> V_138 ) ;
F_113 ( & V_8 -> V_142 ) ;
}
}
static void F_114 ( struct V_7 * V_8 ,
struct V_296 * V_170 )
{
unsigned int V_4 ;
F_46 ( & V_8 -> V_20 -> V_11 ,
L_50 ,
V_170 -> V_297 , V_170 -> V_298 , V_170 -> V_299 , V_170 -> V_149 ) ;
if ( V_170 -> V_300 ) {
F_115 ( V_301 L_51 ,
V_170 -> V_300 ) ;
for ( V_4 = 0 ; V_4 < V_170 -> V_300 ; V_4 ++ )
F_115 ( V_301 L_52 , V_170 -> V_302 [ V_4 ] ) ;
F_115 ( V_301 L_53 ) ;
}
if ( V_170 -> V_303 ) {
F_115 ( V_301 L_54 ,
V_170 -> V_303 ) ;
for ( V_4 = 0 ; V_4 < V_170 -> V_303 ; V_4 ++ )
F_115 ( V_301 L_52 , V_170 -> V_304 [ V_4 ] ) ;
F_115 ( V_301 L_53 ) ;
}
}
static int F_116 ( struct V_7 * V_8 , T_3 V_305 , int V_306 )
{
struct V_307 * V_308 ;
int V_124 = - 1 ;
if ( V_306 == V_309 ) {
V_308 = F_117 ( V_8 -> V_139 , 0 , V_305 , 0 ) ;
if ( V_308 ) {
F_12 ( & V_8 -> V_20 -> V_11 , L_55 , 0 ,
V_308 -> V_310 , 0 ) ;
F_118 ( V_308 ) ;
F_119 ( V_308 ) ;
V_124 = 0 ;
} else
F_11 ( & V_8 -> V_20 -> V_11 , L_56 ,
V_305 ) ;
} else if ( V_306 == V_311 ) {
V_308 = F_117 ( V_8 -> V_139 , 0 , V_305 , 0 ) ;
if ( ! V_308 ) {
F_120 ( V_8 -> V_139 , 0 , V_305 , 0 ) ;
F_12 ( & V_8 -> V_20 -> V_11 , L_57 , 0 ,
V_305 , 0 ) ;
V_124 = 0 ;
} else {
F_11 ( & V_8 -> V_20 -> V_11 , L_58 ,
0 , V_305 , 0 ) ;
F_119 ( V_308 ) ;
}
}
return V_124 ;
}
static T_4 F_121 ( struct V_7 * V_8 ,
unsigned int V_310 , struct V_48 * V_49 )
{
struct V_148 * V_51 ;
T_4 V_312 = 0 ;
int V_313 = 0 ;
int V_314 = 64 ;
if ( ! V_49 ) {
V_49 = F_38 ( V_8 , V_314 ) ;
if ( V_49 )
V_313 = 1 ;
else
return 0 ;
} else {
memset ( V_49 -> V_54 , 0 , V_314 ) ;
}
V_49 -> V_31 = NULL ;
V_49 -> V_136 = V_137 ;
F_94 ( & V_49 -> V_138 , 0 ) ;
V_51 = V_49 -> V_51 ;
V_51 -> V_149 = ( T_3 ) V_310 ;
V_51 -> V_157 = V_315 ;
V_51 -> V_155 = V_156 ;
V_51 -> V_160 = 6 ;
V_51 -> V_159 = V_316 ;
memset ( V_51 -> V_162 , 0 , V_51 -> V_160 ) ;
V_51 -> V_162 [ 0 ] = V_317 ;
V_51 -> V_162 [ 4 ] = V_51 -> V_159 ;
F_86 ( V_8 , V_49 ) ;
if ( V_49 -> V_136 == V_166 ) {
if ( V_8 -> V_20 -> V_128 == V_269 )
V_312 = V_310 + 1 ;
else
memcpy ( ( void * ) & V_312 ,
( V_49 -> V_54 + V_318 ) ,
V_319 ) ;
F_12 ( & V_8 -> V_20 -> V_11 ,
L_59 , V_310 , V_312 ) ;
} else {
V_312 = 0 ;
}
if ( V_313 )
F_39 ( V_8 , V_49 ) ;
return V_312 ;
}
static void F_122 ( struct V_7 * V_8 )
{
struct V_320 * V_321 = NULL , * V_322 ;
struct V_307 * V_308 = NULL ;
F_123 ( & V_8 -> V_323 ) ;
F_21 (mv_dev, dev_next,
&mhba->shost_dev_list, list) {
F_116 ( V_8 , V_321 -> V_310 , V_309 ) ;
F_45 ( & V_321 -> V_105 ) ;
F_12 ( & V_8 -> V_20 -> V_11 , L_60 ,
V_321 -> V_310 , V_321 -> V_312 ) ;
F_15 ( V_321 ) ;
}
F_21 (mv_dev, dev_next, &mhba->mhba_dev_list, list) {
F_45 ( & V_321 -> V_105 ) ;
F_12 ( & V_8 -> V_20 -> V_11 , L_60 ,
V_321 -> V_310 , V_321 -> V_312 ) ;
F_15 ( V_321 ) ;
}
if ( V_8 -> V_20 -> V_128 == V_230 )
V_308 = F_117 ( V_8 -> V_139 , 0 ,
V_8 -> V_152 - 1 , 0 ) ;
if ( V_308 ) {
F_118 ( V_308 ) ;
F_119 ( V_308 ) ;
}
F_124 ( & V_8 -> V_323 ) ;
}
static void F_125 ( struct V_7 * V_8 , int V_310 )
{
struct V_307 * V_308 ;
V_308 = F_117 ( V_8 -> V_139 , 0 , V_310 , 0 ) ;
if ( V_308 ) {
F_126 ( & V_308 -> V_324 ) ;
F_119 ( V_308 ) ;
}
}
static int F_127 ( struct V_7 * V_8 , int V_310 , T_4 V_312 )
{
struct V_320 * V_321 = NULL ;
F_128 (mv_dev, &mhba->shost_dev_list, list) {
if ( V_321 -> V_312 == V_312 ) {
if ( V_321 -> V_310 != V_310 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_61
L_62 ,
V_325 , V_321 -> V_312 , V_321 -> V_310 , V_310 ) ;
return - 1 ;
} else {
if ( V_8 -> V_20 -> V_128 ==
V_269 )
F_125 ( V_8 , V_310 ) ;
return 1 ;
}
}
}
return 0 ;
}
static void F_129 ( struct V_7 * V_8 , int V_310 )
{
struct V_320 * V_321 = NULL , * V_322 ;
F_21 (mv_dev, dev_next,
&mhba->shost_dev_list, list) {
if ( V_321 -> V_310 == V_310 ) {
F_12 ( & V_8 -> V_20 -> V_11 ,
L_63 ,
V_321 -> V_310 , V_321 -> V_312 ) ;
F_116 ( V_8 , V_321 -> V_310 , V_309 ) ;
F_45 ( & V_321 -> V_105 ) ;
F_15 ( V_321 ) ;
}
}
}
static int F_130 ( struct V_7 * V_8 )
{
int V_310 , V_326 ;
T_4 V_312 = 0 ;
struct V_320 * V_321 = NULL ;
struct V_48 * V_49 = NULL ;
int V_327 = 0 ;
V_49 = F_38 ( V_8 , 64 ) ;
if ( ! V_49 )
return - 1 ;
if ( V_8 -> V_20 -> V_128 == V_269 )
V_326 = V_8 -> V_152 ;
else
V_326 = V_8 -> V_152 - 1 ;
for ( V_310 = 0 ; V_310 < V_326 ; V_310 ++ ) {
V_312 = F_121 ( V_8 , V_310 , V_49 ) ;
if ( ! V_312 ) {
F_129 ( V_8 , V_310 ) ;
} else {
V_327 = F_127 ( V_8 , V_310 , V_312 ) ;
if ( ! V_327 ) {
F_129 ( V_8 , V_310 ) ;
V_321 = F_14 ( sizeof( struct V_320 ) ,
V_56 ) ;
if ( ! V_321 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_64 ,
V_325 ) ;
continue;
}
V_321 -> V_310 = V_310 ;
V_321 -> V_312 = V_312 ;
V_321 -> V_308 = NULL ;
F_18 ( & V_321 -> V_105 ) ;
F_19 ( & V_321 -> V_105 ,
& V_8 -> V_328 ) ;
F_12 ( & V_8 -> V_20 -> V_11 ,
L_65
L_66 , V_310 , V_321 -> V_312 ) ;
} else if ( V_327 == - 1 )
return - 1 ;
else
continue;
}
}
if ( V_49 )
F_39 ( V_8 , V_49 ) ;
return 0 ;
}
static int F_131 ( void * V_106 )
{
int V_124 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) V_106 ;
struct V_320 * V_321 = NULL , * V_322 ;
while ( ! F_132 () ) {
F_133 ( V_329 ) ;
if ( ! F_54 ( & V_8 -> V_330 ) )
F_134 () ;
F_70 ( 1000 ) ;
F_94 ( & V_8 -> V_330 , 0 ) ;
F_135 ( V_331 ) ;
F_123 ( & V_8 -> V_323 ) ;
V_124 = F_130 ( V_8 ) ;
if ( ! V_124 ) {
F_21 (mv_dev, dev_next,
&mhba->mhba_dev_list, list) {
if ( F_116 ( V_8 , V_321 -> V_310 ,
V_311 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_67
L_68 ,
V_325 ,
V_321 -> V_310 , V_321 -> V_312 ) ;
F_45 ( & V_321 -> V_105 ) ;
F_15 ( V_321 ) ;
} else {
F_136 ( & V_321 -> V_105 ,
& V_8 -> V_332 ) ;
}
}
}
F_124 ( & V_8 -> V_323 ) ;
}
return 0 ;
}
static void F_137 ( struct V_7 * V_8 ,
struct V_333 * V_334 )
{
T_3 V_3 = V_334 -> V_3 ;
const unsigned long * V_335 ;
const unsigned long * V_336 ;
int V_337 ;
if ( V_8 -> V_28 & V_338 ) {
V_337 = - 1 ;
V_335 = ( const unsigned long * ) V_334 -> V_339 ;
V_336 = ( const unsigned long * ) & V_334 -> V_339 [ V_3 >> 3 ] ;
F_123 ( & V_8 -> V_340 ) ;
do {
V_337 = F_138 ( V_335 , V_3 , V_337 + 1 ) ;
if ( V_337 >= V_3 )
break;
F_116 ( V_8 , V_337 , V_311 ) ;
} while ( 1 );
V_337 = - 1 ;
do {
V_337 = F_138 ( V_336 , V_3 , V_337 + 1 ) ;
if ( V_337 >= V_3 )
break;
F_116 ( V_8 , V_337 , V_309 ) ;
} while ( 1 );
F_124 ( & V_8 -> V_340 ) ;
}
}
static void F_139 ( struct V_7 * V_8 , V_220 V_341 , void * V_342 )
{
if ( V_341 == V_343 ) {
int V_4 , V_76 ;
struct V_296 * V_334 = NULL ;
struct V_344 * V_345 = V_342 ;
V_76 = V_345 -> V_76 ;
if ( V_76 > V_346 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_69
L_70 ,
V_76 , V_346 ) ;
return;
}
for ( V_4 = 0 ; V_4 < V_76 ; V_4 ++ ) {
V_334 = & V_345 -> V_347 [ V_4 ] ;
F_114 ( V_8 , V_334 ) ;
}
} else if ( V_341 == V_348 ) {
F_137 ( V_8 , V_342 ) ;
}
}
static int F_140 ( struct V_7 * V_8 , unsigned char V_341 )
{
struct V_48 * V_49 ;
struct V_148 * V_51 ;
V_49 = F_38 ( V_8 , 512 ) ;
if ( ! V_49 )
return - 1 ;
V_49 -> V_31 = NULL ;
V_49 -> V_136 = V_137 ;
F_94 ( & V_49 -> V_138 , 0 ) ;
V_51 = V_49 -> V_51 ;
V_51 -> V_149 = 0 ;
V_51 -> V_157 = V_315 ;
V_51 -> V_155 = V_156 ;
V_51 -> V_160 = V_161 ;
V_51 -> V_159 = sizeof( struct V_344 ) ;
memset ( V_51 -> V_162 , 0 , V_161 ) ;
V_51 -> V_162 [ 0 ] = V_349 ;
V_51 -> V_162 [ 1 ] = V_341 ;
F_86 ( V_8 , V_49 ) ;
if ( V_49 -> V_136 != V_166 )
F_11 ( & V_8 -> V_20 -> V_11 , L_71 ,
V_49 -> V_136 ) ;
else
F_139 ( V_8 , V_49 -> V_51 -> V_162 [ 1 ] , V_49 -> V_54 ) ;
F_39 ( V_8 , V_49 ) ;
return 0 ;
}
static void F_141 ( struct V_350 * V_351 )
{
struct V_352 * V_353 =
F_142 ( V_351 , struct V_352 , V_354 ) ;
F_140 ( V_353 -> V_8 , V_353 -> V_355 ) ;
F_15 ( V_353 ) ;
}
static void F_143 ( struct V_7 * V_8 , T_2 V_273 )
{
struct V_352 * V_353 ;
while ( V_273 & ( V_356 | V_357 ) ) {
if ( V_273 & V_356 ) {
F_57 ( & V_8 -> V_330 ) ;
F_144 ( V_8 -> V_358 ) ;
V_273 &= ~ ( V_356 ) ;
continue;
}
V_353 = F_14 ( sizeof( * V_353 ) , V_19 ) ;
if ( V_353 ) {
F_145 ( & V_353 -> V_354 , F_141 ) ;
V_353 -> V_8 = V_8 ;
V_353 -> V_355 = V_343 ;
V_273 &= ~ ( V_357 ) ;
V_353 -> V_334 = NULL ;
F_146 ( & V_353 -> V_354 ) ;
}
}
}
static void F_147 ( struct V_7 * V_8 )
{
struct V_85 * V_281 ;
struct V_48 * V_49 ;
struct V_100 * V_359 ;
while ( ! F_43 ( & V_8 -> V_107 ) ) {
V_359 = F_49 ( & V_8 -> V_107 ,
struct V_100 , V_105 ) ;
F_45 ( & V_359 -> V_105 ) ;
F_19 ( & V_359 -> V_105 , & V_8 -> V_104 ) ;
V_281 = (struct V_85 * ) & V_359 -> V_106 [ 0 ] ;
V_49 = V_8 -> V_91 [ V_281 -> V_9 ] ;
F_90 ( & V_8 -> V_75 ) ;
V_8 -> V_91 [ V_281 -> V_9 ] = 0 ;
F_4 ( V_8 , & V_8 -> V_90 , V_281 -> V_9 ) ;
if ( V_49 -> V_31 )
F_109 ( V_8 , V_49 , V_281 ) ;
else
F_112 ( V_8 , V_49 , V_281 ) ;
}
V_8 -> V_102 -> V_141 ( V_8 , NULL ) ;
}
static T_5 F_148 ( int V_360 , void * V_361 )
{
struct V_7 * V_8 = (struct V_7 * ) V_361 ;
unsigned long V_44 ;
F_87 ( V_8 -> V_139 -> V_140 , V_44 ) ;
if ( F_53 ( V_8 -> V_102 -> V_362 ( V_8 ) || ! V_8 -> V_275 ) ) {
F_88 ( V_8 -> V_139 -> V_140 , V_44 ) ;
return V_363 ;
}
if ( V_8 -> V_275 & V_8 -> V_70 -> V_280 ) {
if ( V_8 -> V_273 & ( V_356 | V_357 ) )
F_143 ( V_8 , V_8 -> V_273 ) ;
if ( V_8 -> V_273 & V_276 ) {
F_46 ( & V_8 -> V_20 -> V_11 , L_72 ) ;
F_101 ( V_8 ) ;
}
}
if ( V_8 -> V_275 & V_8 -> V_70 -> V_265 )
F_64 ( V_8 ) ;
V_8 -> V_275 = 0 ;
V_8 -> V_273 = 0 ;
if ( V_8 -> V_113 == V_272 )
F_147 ( V_8 ) ;
F_88 ( V_8 -> V_139 -> V_140 , V_44 ) ;
return V_364 ;
}
static enum V_365 F_149 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
void * V_78 ;
struct V_148 * V_66 ;
unsigned int V_366 ;
V_66 = V_49 -> V_51 ;
if ( F_53 ( V_8 -> V_113 != V_272 ) ) {
F_12 ( & V_8 -> V_20 -> V_11 , L_73 ) ;
return V_367 ;
}
if ( F_5 ( & V_8 -> V_90 ) ) {
F_12 ( & V_8 -> V_20 -> V_11 , L_74 ) ;
return V_367 ;
}
F_56 ( V_8 , & V_78 ) ;
V_49 -> V_51 -> V_9 = F_3 ( V_8 , & V_8 -> V_90 ) ;
V_49 -> V_51 -> V_87 = V_8 -> V_368 ++ ;
V_49 -> V_87 = V_49 -> V_51 -> V_87 ;
V_8 -> V_91 [ V_49 -> V_51 -> V_9 ] = V_49 ;
V_366 = sizeof( * V_66 ) - 4 +
V_66 -> V_53 * sizeof( struct V_36 ) ;
if ( V_8 -> V_62 & V_63 ) {
struct V_82 * V_369 ;
V_369 = V_78 ;
V_369 -> V_370 =
F_29 ( F_30 ( V_49 -> V_59 ) ) ;
V_369 -> V_371 =
F_29 ( F_31 ( V_49 -> V_59 ) ) ;
V_369 -> V_372 = ( V_366 >> 2 ) & 0xFFF ;
} else {
memcpy ( V_78 , V_66 , V_366 ) ;
}
return V_373 ;
}
static void F_150 ( struct V_7 * V_8 , struct V_48 * V_49 )
{
unsigned short V_374 = 0 ;
unsigned int V_76 ;
enum V_365 V_282 ;
if ( V_49 )
F_19 ( & V_49 -> V_57 , & V_8 -> V_375 ) ;
V_76 = V_8 -> V_102 -> V_376 ( V_8 ) ;
if ( F_43 ( & V_8 -> V_375 ) || ! V_76 )
return;
do {
V_49 = F_49 ( & V_8 -> V_375 ,
struct V_48 , V_57 ) ;
F_45 ( & V_49 -> V_57 ) ;
V_282 = F_149 ( V_8 , V_49 ) ;
switch ( V_282 ) {
case V_373 :
V_374 ++ ;
break;
case V_367 :
F_151 ( & V_49 -> V_57 , & V_8 -> V_375 ) ;
if ( V_374 > 0 )
F_58 ( V_8 ) ;
return;
}
} while ( ! F_43 ( & V_8 -> V_375 ) && V_76 -- );
if ( V_374 > 0 )
F_58 ( V_8 ) ;
}
static void F_152 ( struct V_7 * V_8 )
{
unsigned int V_377 ;
struct V_69 * V_70 = V_8 -> V_70 ;
F_59 ( V_70 -> V_278 , V_70 -> V_279 ) ;
V_377 = F_52 ( V_70 -> V_108 ) ;
V_377 |= V_70 -> V_280 | V_70 -> V_265 | V_70 -> V_266 ;
F_59 ( V_377 , V_70 -> V_108 ) ;
}
static void F_153 ( struct V_7 * V_8 )
{
unsigned int V_377 ;
struct V_69 * V_70 = V_8 -> V_70 ;
F_59 ( 0 , V_70 -> V_279 ) ;
V_377 = F_52 ( V_70 -> V_108 ) ;
V_377 &= ~ ( V_70 -> V_280 | V_70 -> V_265 |
V_70 -> V_266 ) ;
F_59 ( V_377 , V_70 -> V_108 ) ;
}
static int F_154 ( void * V_378 )
{
struct V_7 * V_8 = (struct V_7 * ) V_378 ;
unsigned int V_306 , V_273 = 0 , V_27 = 0 ;
struct V_69 * V_70 = V_8 -> V_70 ;
V_306 = F_52 ( V_70 -> V_379 ) ;
if ( ! ( V_306 & V_70 -> V_380 ) || V_306 == 0xFFFFFFFF )
return 1 ;
if ( F_53 ( V_306 & V_70 -> V_266 ) ) {
V_27 = F_52 ( V_70 -> V_381 ) ;
if ( V_8 -> V_20 -> V_128 == V_230 ) {
if ( V_27 & V_70 -> V_382 ) {
F_59 ( V_27 & V_70 -> V_382 ,
V_70 -> V_381 ) ;
}
} else {
if ( V_27 & ( V_70 -> V_383 | V_70 -> V_382 ) )
F_59 ( V_27 & ( V_70 -> V_383 |
V_70 -> V_382 ) ,
V_70 -> V_381 ) ;
}
V_306 ^= V_8 -> V_70 -> V_266 ;
}
if ( V_306 & V_70 -> V_265 ) {
V_27 = F_52 ( V_70 -> V_381 ) ;
if ( V_27 & V_70 -> V_384 )
F_59 ( V_27 & V_70 -> V_384 , V_70 -> V_381 ) ;
}
if ( V_306 & V_70 -> V_280 ) {
V_273 = F_52 ( V_70 -> V_277 ) ;
if ( V_273 )
F_59 ( V_273 , V_70 -> V_277 ) ;
}
V_8 -> V_275 = V_306 ;
V_8 -> V_273 = V_273 ;
return 0 ;
}
static unsigned int F_155 ( struct V_7 * V_8 )
{
unsigned int V_306 ;
V_306 = F_52 ( V_8 -> V_70 -> V_277 ) ;
if ( V_306 )
F_59 ( V_306 , V_8 -> V_70 -> V_277 ) ;
return V_306 ;
}
static int F_156 ( struct V_307 * V_308 )
{
struct V_7 * V_8 ;
unsigned char V_151 = sizeof( unsigned char ) * 8 ;
V_8 = (struct V_7 * ) V_308 -> V_129 -> V_130 ;
if ( V_308 -> V_310 >= V_8 -> V_152 )
return - V_385 ;
V_8 -> V_153 [ V_308 -> V_310 / V_151 ] |= ( 1 << ( V_308 -> V_310 % V_151 ) ) ;
return 0 ;
}
static unsigned char F_157 ( struct V_7 * V_8 ,
struct V_30 * V_31 , struct V_48 * V_49 )
{
struct V_148 * V_386 ;
V_49 -> V_31 = V_31 ;
V_49 -> V_136 = V_137 ;
V_386 = V_49 -> V_51 ;
V_386 -> V_149 = ( ( unsigned short ) V_31 -> V_128 -> V_310 ) |
( ( ( unsigned short ) V_31 -> V_128 -> V_387 ) << 8 ) ;
V_386 -> V_157 = 0 ;
switch ( V_31 -> V_40 ) {
case V_388 :
V_386 -> V_157 |= V_158 ;
break;
case V_389 :
V_386 -> V_157 |= V_315 ;
break;
case V_390 :
V_386 -> V_157 |= V_391 ;
break;
case V_392 :
default:
F_46 ( & V_8 -> V_20 -> V_11 , L_75
L_76 , V_31 -> V_40 , V_31 -> V_133 [ 0 ] ) ;
goto error;
}
V_386 -> V_160 = V_31 -> V_393 ;
memcpy ( V_386 -> V_162 , V_31 -> V_133 , V_386 -> V_160 ) ;
V_386 -> V_155 = V_156 ;
if ( F_35 ( V_31 ) ) {
if ( F_24 ( V_8 , V_31 , & V_386 -> V_52 [ 0 ] ,
& V_386 -> V_53 ) )
goto error;
V_386 -> V_159 = F_35 ( V_31 ) ;
} else {
V_386 -> V_53 = 0 ;
V_386 -> V_159 = 0 ;
}
return 0 ;
error:
V_31 -> V_282 = ( V_284 << 16 ) | ( V_292 << 24 ) |
V_287 ;
F_158 ( 0 , V_31 -> V_290 , V_394 , 0x24 ,
0 ) ;
return - 1 ;
}
static int F_159 ( struct V_395 * V_139 ,
struct V_30 * V_31 )
{
struct V_48 * V_49 ;
struct V_7 * V_8 ;
unsigned long V_396 ;
F_87 ( V_139 -> V_140 , V_396 ) ;
F_160 ( V_139 , V_31 ) ;
V_8 = (struct V_7 * ) V_139 -> V_130 ;
V_31 -> V_282 = 0 ;
V_49 = F_41 ( V_8 ) ;
if ( F_53 ( ! V_49 ) ) {
F_88 ( V_139 -> V_140 , V_396 ) ;
return V_397 ;
}
if ( F_53 ( F_157 ( V_8 , V_31 , V_49 ) ) )
goto V_398;
V_49 -> V_31 = V_31 ;
V_31 -> V_46 . V_170 = ( char * ) V_49 ;
V_8 -> V_102 -> V_141 ( V_8 , V_49 ) ;
F_88 ( V_139 -> V_140 , V_396 ) ;
return 0 ;
V_398:
F_47 ( V_8 , V_49 ) ;
V_31 -> V_295 ( V_31 ) ;
F_88 ( V_139 -> V_140 , V_396 ) ;
return 0 ;
}
static enum V_399 F_161 ( struct V_30 * V_31 )
{
struct V_48 * V_49 = (struct V_48 * ) V_31 -> V_46 . V_170 ;
struct V_395 * V_129 = V_31 -> V_128 -> V_129 ;
struct V_7 * V_8 = F_162 ( V_129 ) ;
unsigned long V_44 ;
F_87 ( V_8 -> V_139 -> V_140 , V_44 ) ;
if ( V_8 -> V_91 [ V_49 -> V_51 -> V_9 ] ) {
V_8 -> V_91 [ V_49 -> V_51 -> V_9 ] = 0 ;
F_4 ( V_8 , & V_8 -> V_90 , V_49 -> V_51 -> V_9 ) ;
}
if ( ! F_43 ( & V_49 -> V_57 ) )
F_45 ( & V_49 -> V_57 ) ;
else
F_90 ( & V_8 -> V_75 ) ;
V_31 -> V_282 = ( V_293 << 24 ) | ( V_294 << 16 ) ;
V_31 -> V_46 . V_170 = NULL ;
if ( F_35 ( V_31 ) ) {
if ( F_25 ( V_31 ) ) {
F_110 ( V_8 -> V_20 ,
F_26 ( V_31 ) ,
F_25 ( V_31 ) ,
( int ) V_31 -> V_40 ) ;
} else {
F_111 ( V_8 -> V_20 ,
V_31 -> V_46 . V_47 ,
F_35 ( V_31 ) ,
( int ) V_31 -> V_40 ) ;
V_31 -> V_46 . V_47 = 0 ;
}
}
F_47 ( V_8 , V_49 ) ;
F_88 ( V_8 -> V_139 -> V_140 , V_44 ) ;
return V_400 ;
}
static int
F_163 ( struct V_307 * V_308 , struct V_401 * V_402 ,
T_6 V_403 , int V_404 [] )
{
int V_405 , V_406 ;
T_6 V_407 ;
unsigned long V_27 ;
V_405 = 64 ;
V_406 = 32 ;
V_27 = V_405 * V_406 ;
V_407 = V_403 ;
F_164 ( V_407 , V_27 ) ;
if ( V_403 >= 0x200000 ) {
V_405 = 255 ;
V_406 = 63 ;
V_27 = V_405 * V_406 ;
V_407 = V_403 ;
F_164 ( V_407 , V_27 ) ;
}
V_404 [ 0 ] = V_405 ;
V_404 [ 1 ] = V_406 ;
V_404 [ 2 ] = V_407 ;
return 0 ;
}
static int F_165 ( struct V_7 * V_8 )
{
void * V_408 = NULL ;
struct V_69 * V_70 ;
switch ( V_8 -> V_20 -> V_128 ) {
case V_269 :
V_8 -> V_409 = V_8 -> V_144 [ 0 ] ;
V_408 = V_8 -> V_409 ;
if ( ! V_8 -> V_70 ) {
V_8 -> V_70 = F_14 ( sizeof( * V_70 ) , V_56 ) ;
if ( V_8 -> V_70 == NULL )
return - V_15 ;
}
V_70 = V_8 -> V_70 ;
V_70 -> V_410 = V_408 + 0x20104 ;
V_70 -> V_411 = V_408 + 0x20108 ;
V_70 -> V_412 = V_408 + 0x2010C ;
V_70 -> V_379 = V_408 + 0x20200 ;
V_70 -> V_108 = V_408 + 0x2020C ;
V_70 -> V_413 = V_408 + 0xF1400 ;
V_70 -> V_112 = V_408 + 0x20400 ;
V_70 -> V_277 = V_408 + 0x20408 ;
V_70 -> V_279 = V_408 + 0x2040C ;
V_70 -> V_255 = V_408 + 0x20430 ;
V_70 -> V_254 = V_408 + 0x20434 ;
V_70 -> V_249 = V_408 + 0x20438 ;
V_70 -> V_109 = V_408 + 0x2043C ;
V_70 -> V_267 = V_408 + 0x508 ;
V_70 -> V_268 = V_408 + 0x50C ;
V_70 -> V_83 = V_408 + 0x518 ;
V_70 -> V_71 = V_408 + 0x51C ;
V_70 -> V_414 = V_408 + 0x568 ;
V_70 -> V_270 = V_408 + 0x5B0 ;
V_70 -> V_271 = V_408 + 0x5B4 ;
V_70 -> V_96 = V_408 + 0x544 ;
V_70 -> V_99 = V_408 + 0x548 ;
V_70 -> V_381 = V_408 + 0x560 ;
V_70 -> V_414 = V_408 + 0x568 ;
V_70 -> V_265 = 1 << 8 ;
V_70 -> V_266 = 1 << 6 ;
V_70 -> V_280 = 1 << 1 ;
V_70 -> V_74 = 1 << 12 ;
V_70 -> V_384 = 1 << 1 ;
V_70 -> V_383 = 1 << 8 ;
V_70 -> V_382 = 1 << 12 ;
V_70 -> V_72 = 0xFFF ;
V_70 -> V_278 = 0x3FFFFFFF ;
V_70 -> V_380 = V_70 -> V_280 | V_70 -> V_265 |
V_70 -> V_266 ;
break;
case V_230 :
V_8 -> V_409 = V_8 -> V_144 [ 2 ] ;
V_408 = V_8 -> V_409 ;
if ( ! V_8 -> V_70 ) {
V_8 -> V_70 = F_14 ( sizeof( * V_70 ) , V_56 ) ;
if ( V_8 -> V_70 == NULL )
return - V_15 ;
}
V_70 = V_8 -> V_70 ;
V_70 -> V_410 = V_408 + 0x20104 ;
V_70 -> V_411 = V_408 + 0x1010C ;
V_70 -> V_412 = V_408 + 0x10108 ;
V_70 -> V_379 = V_408 + 0x10200 ;
V_70 -> V_108 = V_408 + 0x1020C ;
V_70 -> V_413 = V_408 + 0xF1400 ;
V_70 -> V_112 = V_408 + 0x10460 ;
V_70 -> V_277 = V_408 + 0x10480 ;
V_70 -> V_279 = V_408 + 0x10484 ;
V_70 -> V_255 = V_408 + 0x10400 ;
V_70 -> V_254 = V_408 + 0x10404 ;
V_70 -> V_249 = V_408 + 0x10420 ;
V_70 -> V_109 = V_408 + 0x10424 ;
V_70 -> V_127 = V_408 + 0x10108 ;
V_70 -> V_126 = V_408 + 0x1010c ;
V_70 -> V_267 = V_408 + 0x4008 ;
V_70 -> V_268 = V_408 + 0x400C ;
V_70 -> V_83 = V_408 + 0x4018 ;
V_70 -> V_71 = V_408 + 0x401C ;
V_70 -> V_270 = V_408 + 0x4058 ;
V_70 -> V_271 = V_408 + 0x405C ;
V_70 -> V_96 = V_408 + 0x406C ;
V_70 -> V_99 = V_408 + 0x4070 ;
V_70 -> V_414 = V_408 + 0x4080 ;
V_70 -> V_381 = V_408 + 0x4088 ;
V_70 -> V_265 = 1 << 4 ;
V_70 -> V_280 = 1 << 12 ;
V_70 -> V_266 = 1 << 29 ;
V_70 -> V_74 = 1 << 14 ;
V_70 -> V_72 = 0x3FFF ;
V_70 -> V_384 = 1 << 0 ;
V_70 -> V_382 = 1 << 1 ;
V_70 -> V_278 = 0x3FFFFFFF ;
V_70 -> V_380 = V_70 -> V_280 | V_70 -> V_265 ;
break;
default:
return - 1 ;
break;
}
return 0 ;
}
static int F_166 ( struct V_7 * V_8 )
{
int V_124 = 0 ;
if ( F_167 ( V_8 -> V_20 , V_415 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_77 ) ;
return - V_416 ;
}
V_124 = F_9 ( V_8 -> V_20 , V_8 -> V_144 ) ;
if ( V_124 )
goto V_417;
switch ( V_8 -> V_20 -> V_128 ) {
case V_269 :
V_8 -> V_102 = & V_418 ;
V_8 -> V_368 = 0 ;
V_8 -> V_41 = V_419 ;
V_8 -> V_92 = 1 ;
break;
case V_230 :
V_8 -> V_102 = & V_420 ;
V_8 -> V_368 = 0 ;
V_8 -> V_41 = V_419 ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_78 ,
V_8 -> V_20 -> V_128 ) ;
V_8 -> V_102 = NULL ;
V_124 = - V_385 ;
goto V_421;
}
F_12 ( & V_8 -> V_20 -> V_11 , L_79 ,
V_8 -> V_20 -> V_128 ) ;
V_124 = F_165 ( V_8 ) ;
if ( V_124 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_80 ) ;
V_124 = - V_15 ;
goto V_421;
}
V_8 -> V_146 = F_17 ( V_8 -> V_20 , V_145 ,
& V_8 -> V_147 ) ;
if ( ! V_8 -> V_146 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_81 ) ;
V_124 = - V_15 ;
goto V_422;
}
if ( F_67 ( V_8 ) ) {
V_124 = - V_385 ;
goto V_423;
}
V_124 = F_50 ( V_8 ) ;
if ( V_124 )
goto V_423;
return 0 ;
V_423:
F_20 ( V_8 ) ;
F_22 ( V_8 -> V_20 , V_145 ,
V_8 -> V_146 , V_8 -> V_147 ) ;
V_422:
F_15 ( V_8 -> V_70 ) ;
V_421:
F_6 ( V_8 -> V_20 , V_8 -> V_144 ) ;
V_417:
F_92 ( V_8 -> V_20 ) ;
return V_124 ;
}
static int F_168 ( struct V_7 * V_8 )
{
struct V_395 * V_129 = V_8 -> V_139 ;
struct V_307 * V_308 = NULL ;
int V_124 ;
unsigned int V_424 = ( V_8 -> V_58 + 4 -
sizeof( struct V_148 ) ) / sizeof( struct V_36 ) ;
V_129 -> V_360 = V_8 -> V_20 -> V_360 ;
V_129 -> V_425 = V_8 -> V_425 ;
V_129 -> V_426 = ( V_8 -> V_64 - 1 ) ? ( V_8 -> V_64 - 1 ) : 1 ;
V_129 -> V_427 = V_8 -> V_41 > V_424 ? V_424 : V_8 -> V_41 ;
V_129 -> V_428 = V_8 -> V_238 / 512 ;
V_129 -> V_429 = ( V_8 -> V_64 - 1 ) ? ( V_8 -> V_64 - 1 ) : 1 ;
V_129 -> V_430 = V_8 -> V_152 ;
V_129 -> V_431 = V_161 ;
V_129 -> V_432 = & V_433 ;
V_124 = F_169 ( V_129 , & V_8 -> V_20 -> V_11 ) ;
if ( V_124 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_82 ) ;
return V_124 ;
}
V_8 -> V_28 |= V_338 ;
F_123 ( & V_8 -> V_340 ) ;
if ( V_8 -> V_20 -> V_128 == V_230 )
V_124 = F_120 ( V_129 , 0 , V_8 -> V_152 - 1 , 0 ) ;
else
V_124 = 0 ;
if ( V_124 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_83 ) ;
F_124 ( & V_8 -> V_340 ) ;
goto V_434;
}
V_8 -> V_358 = F_170 ( F_131 ,
V_8 , L_84 ) ;
if ( F_171 ( V_8 -> V_358 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_85 ) ;
F_124 ( & V_8 -> V_340 ) ;
goto V_435;
}
F_94 ( & V_8 -> V_330 , 1 ) ;
F_144 ( V_8 -> V_358 ) ;
F_124 ( & V_8 -> V_340 ) ;
return 0 ;
V_435:
if ( V_8 -> V_20 -> V_128 == V_230 )
V_308 = F_117 ( V_8 -> V_139 , 0 ,
V_8 -> V_152 - 1 , 0 ) ;
if ( V_308 ) {
F_118 ( V_308 ) ;
F_119 ( V_308 ) ;
}
V_434:
F_172 ( V_8 -> V_139 ) ;
return V_124 ;
}
static int F_173 ( struct V_10 * V_20 , const struct V_436 * V_310 )
{
struct V_395 * V_129 ;
struct V_7 * V_8 ;
int V_124 ;
F_12 ( & V_20 -> V_11 , L_86 ,
V_20 -> V_437 , V_20 -> V_128 , V_20 -> V_438 ,
V_20 -> V_439 ) ;
V_124 = F_82 ( V_20 ) ;
if ( V_124 )
return V_124 ;
F_77 ( V_20 ) ;
if ( V_125 ) {
V_124 = F_78 ( V_20 , F_79 ( 64 ) ) ;
if ( V_124 ) {
V_124 = F_78 ( V_20 , F_79 ( 32 ) ) ;
if ( V_124 )
goto V_440;
}
} else {
V_124 = F_78 ( V_20 , F_79 ( 32 ) ) ;
if ( V_124 )
goto V_440;
}
V_129 = F_174 ( & V_441 , sizeof( * V_8 ) ) ;
if ( ! V_129 ) {
F_11 ( & V_20 -> V_11 , L_87 ) ;
V_124 = - V_15 ;
goto V_442;
}
V_8 = F_162 ( V_129 ) ;
F_18 ( & V_8 -> V_60 ) ;
F_18 ( & V_8 -> V_104 ) ;
F_18 ( & V_8 -> V_107 ) ;
F_18 ( & V_8 -> V_26 ) ;
F_18 ( & V_8 -> V_375 ) ;
F_175 ( & V_8 -> V_323 ) ;
F_18 ( & V_8 -> V_328 ) ;
F_18 ( & V_8 -> V_332 ) ;
F_94 ( & V_8 -> V_75 , 0 ) ;
F_176 ( & V_8 -> V_142 ) ;
F_175 ( & V_8 -> V_340 ) ;
V_8 -> V_20 = V_20 ;
V_8 -> V_139 = V_129 ;
V_8 -> V_425 = V_20 -> V_443 -> V_444 << 8 | V_20 -> V_445 ;
V_124 = F_166 ( V_8 ) ;
if ( V_124 )
goto V_446;
V_124 = F_177 ( V_8 -> V_20 -> V_360 , F_148 , V_447 ,
L_88 , V_8 ) ;
if ( V_124 ) {
F_11 ( & V_20 -> V_11 , L_89 ) ;
goto V_448;
}
V_8 -> V_102 -> V_449 ( V_8 ) ;
F_178 ( V_20 , V_8 ) ;
V_124 = F_168 ( V_8 ) ;
if ( V_124 )
goto V_450;
F_72 ( V_8 ) ;
F_12 ( & V_20 -> V_11 , L_90 ) ;
return 0 ;
V_450:
V_8 -> V_102 -> V_451 ( V_8 ) ;
F_179 ( V_8 -> V_20 -> V_360 , V_8 ) ;
V_448:
F_91 ( V_8 ) ;
V_446:
F_180 ( V_129 ) ;
V_442:
V_440:
F_81 ( V_20 ) ;
return V_124 ;
}
static void F_181 ( struct V_10 * V_20 )
{
struct V_395 * V_129 ;
struct V_7 * V_8 ;
V_8 = F_182 ( V_20 ) ;
if ( V_8 -> V_358 ) {
F_183 ( V_8 -> V_358 ) ;
V_8 -> V_358 = NULL ;
}
F_122 ( V_8 ) ;
V_129 = V_8 -> V_139 ;
F_172 ( V_8 -> V_139 ) ;
F_93 ( V_8 ) ;
V_8 -> V_102 -> V_451 ( V_8 ) ;
F_179 ( V_8 -> V_20 -> V_360 , V_8 ) ;
F_91 ( V_8 ) ;
F_180 ( V_129 ) ;
F_81 ( V_20 ) ;
F_12 ( & V_20 -> V_11 , L_91 ) ;
}
static void F_184 ( struct V_10 * V_20 )
{
struct V_7 * V_8 = F_182 ( V_20 ) ;
F_93 ( V_8 ) ;
}
static int F_185 ( struct V_10 * V_20 , T_7 V_452 )
{
struct V_7 * V_8 = NULL ;
V_8 = F_182 ( V_20 ) ;
F_93 ( V_8 ) ;
F_178 ( V_20 , V_8 ) ;
V_8 -> V_102 -> V_451 ( V_8 ) ;
F_179 ( V_8 -> V_20 -> V_360 , V_8 ) ;
F_6 ( V_20 , V_8 -> V_144 ) ;
F_92 ( V_20 ) ;
F_186 ( V_20 ) ;
F_81 ( V_20 ) ;
F_187 ( V_20 , F_188 ( V_20 , V_452 ) ) ;
return 0 ;
}
static int F_189 ( struct V_10 * V_20 )
{
int V_124 ;
struct V_7 * V_8 = NULL ;
V_8 = F_182 ( V_20 ) ;
F_187 ( V_20 , V_453 ) ;
F_190 ( V_20 , V_453 , 0 ) ;
F_191 ( V_20 ) ;
V_124 = F_82 ( V_20 ) ;
if ( V_124 ) {
F_11 ( & V_20 -> V_11 , L_25 ) ;
return V_124 ;
}
F_77 ( V_20 ) ;
if ( V_125 ) {
V_124 = F_78 ( V_20 , F_79 ( 64 ) ) ;
if ( V_124 ) {
V_124 = F_78 ( V_20 , F_79 ( 32 ) ) ;
if ( V_124 )
goto V_454;
}
} else {
V_124 = F_78 ( V_20 , F_79 ( 32 ) ) ;
if ( V_124 )
goto V_454;
}
V_124 = F_167 ( V_8 -> V_20 , V_415 ) ;
if ( V_124 )
goto V_454;
V_124 = F_9 ( V_8 -> V_20 , V_8 -> V_144 ) ;
if ( V_124 )
goto V_455;
if ( F_165 ( V_8 ) ) {
V_124 = - V_385 ;
goto V_456;
}
V_8 -> V_409 = V_8 -> V_144 [ 0 ] ;
F_65 ( V_8 ) ;
if ( F_67 ( V_8 ) ) {
V_124 = - V_385 ;
goto V_456;
}
V_124 = F_177 ( V_8 -> V_20 -> V_360 , F_148 , V_447 ,
L_88 , V_8 ) ;
if ( V_124 ) {
F_11 ( & V_20 -> V_11 , L_89 ) ;
goto V_456;
}
V_8 -> V_102 -> V_449 ( V_8 ) ;
return 0 ;
V_456:
F_6 ( V_20 , V_8 -> V_144 ) ;
V_455:
F_92 ( V_20 ) ;
V_454:
F_81 ( V_20 ) ;
return V_124 ;
}
static int T_8 F_192 ( void )
{
return F_193 ( & V_457 ) ;
}
static void T_9 F_194 ( void )
{
F_195 ( & V_457 ) ;
}
