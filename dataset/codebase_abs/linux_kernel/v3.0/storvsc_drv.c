static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 |= V_4 | V_5 ;
return 0 ;
}
static int F_2 ( struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_10 * V_11 )
{
return V_11 -> V_12 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_13 ,
V_14 ) ;
F_5 ( V_15 , L_1 ,
V_2 , V_16 ) ;
F_6 ( V_2 -> V_6 , V_16 ) ;
F_5 ( V_15 , L_2 ,
V_2 ) ;
F_7 ( V_2 -> V_6 , F_2 ) ;
F_8 ( V_2 -> V_6 , V_17 ) ;
return 0 ;
}
static void F_9 ( struct V_18 * V_19 ,
unsigned int V_20 )
{
int V_21 ;
struct V_22 * V_23 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
V_23 = F_10 ( ( & V_19 [ V_21 ] ) ) ;
if ( V_23 != NULL )
F_11 ( V_23 ) ;
}
F_12 ( V_19 ) ;
}
static int F_13 ( struct V_18 * V_19 , unsigned int V_20 )
{
int V_21 ;
if ( V_20 < 2 )
return - 1 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
if ( V_21 == 0 ) {
if ( V_19 [ V_21 ] . V_24 + V_19 [ V_21 ] . V_25 != V_16 )
return V_21 ;
} else if ( V_21 == V_20 - 1 ) {
if ( V_19 [ V_21 ] . V_24 != 0 )
return V_21 ;
} else {
if ( V_19 [ V_21 ] . V_25 != V_16 || V_19 [ V_21 ] . V_24 != 0 )
return V_21 ;
}
}
return - 1 ;
}
static struct V_18 * F_14 ( struct V_18 * V_19 ,
unsigned int V_20 ,
unsigned int V_26 )
{
int V_21 ;
int V_27 ;
struct V_18 * V_28 ;
struct V_22 * V_23 ;
V_27 = F_15 ( V_26 , V_16 ) >> V_29 ;
V_28 = F_16 ( V_27 , sizeof( struct V_18 ) , V_30 ) ;
if ( ! V_28 )
return NULL ;
for ( V_21 = 0 ; V_21 < V_27 ; V_21 ++ ) {
V_23 = F_17 ( V_30 ) ;
if ( ! V_23 )
goto V_31;
F_18 ( & V_28 [ V_21 ] , V_23 , 0 , 0 ) ;
}
return V_28 ;
V_31:
F_9 ( V_28 , V_27 ) ;
return NULL ;
}
static unsigned int F_19 ( struct V_18 * V_32 ,
struct V_18 * V_28 ,
unsigned int V_33 )
{
int V_21 ;
int V_34 = 0 ;
unsigned long V_35 , V_36 ;
unsigned int V_37 , V_38 , V_39 ;
unsigned int V_40 = 0 ;
unsigned long V_41 = 0 ;
unsigned long V_42 = 0 ;
unsigned long V_43 ;
F_20 ( V_43 ) ;
for ( V_21 = 0 ; V_21 < V_33 ; V_21 ++ ) {
V_42 = ( unsigned long ) F_21 ( F_10 ( ( & V_32 [ V_21 ] ) ) ,
V_44 ) + V_32 [ V_21 ] . V_24 ;
V_36 = V_42 ;
V_38 = V_32 [ V_21 ] . V_25 ;
if ( V_41 == 0 )
V_41 =
( unsigned long ) F_21 ( F_10 ( ( & V_28 [ V_34 ] ) ) ,
V_44 ) ;
while ( V_38 ) {
V_35 = V_41 + V_28 [ V_34 ] . V_24 ;
V_37 = V_28 [ V_34 ] . V_25 - V_28 [ V_34 ] . V_24 ;
V_39 = F_22 ( V_37 , V_38 ) ;
memcpy ( ( void * ) V_36 , ( void * ) V_35 , V_39 ) ;
V_40 += V_39 ;
V_28 [ V_34 ] . V_24 += V_39 ;
V_38 -= V_39 ;
V_36 += V_39 ;
if ( V_28 [ V_34 ] . V_24 == V_28 [ V_34 ] . V_25 ) {
F_23 ( ( void * ) V_41 , V_44 ) ;
V_34 ++ ;
if ( V_38 || V_21 != V_33 - 1 )
V_41 =
( unsigned long ) F_21 (
F_10 ( ( & V_28 [ V_34 ] ) ) , V_44 ) ;
} else if ( V_38 == 0 && V_21 == V_33 - 1 ) {
F_23 ( ( void * ) V_41 , V_44 ) ;
}
}
F_23 ( ( void * ) ( V_42 - V_32 [ V_21 ] . V_24 ) ,
V_44 ) ;
}
F_24 ( V_43 ) ;
return V_40 ;
}
static unsigned int F_25 ( struct V_18 * V_32 ,
struct V_18 * V_28 ,
unsigned int V_33 )
{
int V_21 ;
int V_34 = 0 ;
unsigned long V_35 , V_36 ;
unsigned int V_37 , V_38 , V_39 ;
unsigned int V_40 = 0 ;
unsigned long V_41 = 0 ;
unsigned long V_45 = 0 ;
unsigned long V_43 ;
F_20 ( V_43 ) ;
for ( V_21 = 0 ; V_21 < V_33 ; V_21 ++ ) {
V_45 = ( unsigned long ) F_21 ( F_10 ( ( & V_32 [ V_21 ] ) ) ,
V_44 ) + V_32 [ V_21 ] . V_24 ;
V_35 = V_45 ;
V_37 = V_32 [ V_21 ] . V_25 ;
if ( V_41 == 0 )
V_41 =
( unsigned long ) F_21 ( F_10 ( ( & V_28 [ V_34 ] ) ) ,
V_44 ) ;
while ( V_37 ) {
V_36 = V_41 + V_28 [ V_34 ] . V_25 ;
V_38 = V_16 - V_28 [ V_34 ] . V_25 ;
V_39 = F_22 ( V_37 , V_38 ) ;
memcpy ( ( void * ) V_36 , ( void * ) V_35 , V_39 ) ;
V_40 += V_39 ;
V_28 [ V_34 ] . V_25 += V_39 ;
V_37 -= V_39 ;
V_35 += V_39 ;
if ( V_28 [ V_34 ] . V_25 == V_16 ) {
F_23 ( ( void * ) V_41 , V_44 ) ;
V_34 ++ ;
if ( V_37 || V_21 != V_33 - 1 )
V_41 =
( unsigned long ) F_21 (
F_10 ( ( & V_28 [ V_34 ] ) ) , V_44 ) ;
} else if ( V_37 == 0 && V_21 == V_33 - 1 ) {
F_23 ( ( void * ) V_41 , V_44 ) ;
}
}
F_23 ( ( void * ) ( V_45 - V_32 [ V_21 ] . V_24 ) , V_44 ) ;
}
F_24 ( V_43 ) ;
return V_40 ;
}
static int F_26 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_27 ( & V_47 -> V_50 ) ;
struct V_51 * V_52 =
(struct V_51 * ) V_49 -> V_53 ;
F_28 ( V_47 ) ;
if ( V_52 -> V_54 ) {
F_29 ( V_52 -> V_54 ) ;
V_52 -> V_54 = NULL ;
}
F_5 ( V_55 , L_3 , V_49 ) ;
F_30 ( V_49 ) ;
F_5 ( V_55 , L_4 , V_49 ) ;
F_31 ( V_49 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_56 , struct V_57 * V_58 ,
T_1 V_59 , int * V_60 )
{
T_1 V_61 = V_59 ;
T_1 V_62 = V_61 ;
int V_63 , V_64 ;
V_63 = 0xff ;
V_64 = 0x3f ;
F_33 ( V_62 , V_63 * V_64 ) ;
if ( ( T_1 ) ( V_62 + 1 ) * V_63 * V_64 < V_61 )
V_62 = 0xffff ;
V_60 [ 0 ] = V_63 ;
V_60 [ 1 ] = V_64 ;
V_60 [ 2 ] = ( int ) V_62 ;
F_5 ( V_15 , L_5 , ( int ) V_62 , V_63 ,
V_64 ) ;
return 0 ;
}
static int F_34 ( struct V_46 * V_50 )
{
struct V_65 * V_66 ;
struct V_67 * V_68 ;
struct V_69 * V_69 ;
int V_70 , V_71 ;
F_5 ( V_55 , L_6 ) ;
V_66 = F_35 ( V_50 ) ;
if ( ! V_66 )
return - 1 ;
V_68 = & V_66 -> V_72 ;
V_69 = & V_68 -> V_69 ;
F_36 ( & V_68 -> V_73 ) ;
V_69 -> V_74 = V_75 ;
V_69 -> V_43 = V_76 ;
V_69 -> V_77 . V_78 = V_66 -> V_78 ;
V_70 = F_37 ( V_50 -> V_79 , V_69 ,
sizeof( struct V_69 ) ,
( unsigned long ) & V_66 -> V_72 ,
V_80 ,
V_81 ) ;
if ( V_70 != 0 )
goto V_31;
V_71 = F_38 ( & V_68 -> V_73 , V_82 ) ;
if ( V_71 == 0 ) {
V_70 = - V_83 ;
goto V_31;
}
F_5 ( V_55 , L_7 ) ;
V_31:
F_39 ( V_50 ) ;
return V_70 ;
}
static int F_40 ( struct V_84 * V_85 )
{
int V_70 ;
struct V_51 * V_52 =
(struct V_51 * ) V_85 -> V_50 -> V_49 -> V_53 ;
struct V_46 * V_47 = V_52 -> V_47 ;
F_5 ( V_15 , L_8 ,
V_85 -> V_50 , V_47 ) ;
V_70 = F_34 ( V_47 ) ;
if ( V_70 != 0 )
return V_70 ;
F_5 ( V_15 , L_9 ,
V_85 -> V_50 , V_47 ) ;
return V_70 ;
}
static void F_41 ( struct V_67 * V_68 )
{
struct V_86 * V_87 =
(struct V_86 * ) V_68 -> V_88 ;
struct V_84 * V_85 = V_87 -> V_89 ;
struct V_51 * V_52 =
(struct V_51 * ) V_85 -> V_50 -> V_49 -> V_53 ;
void (* F_42)( struct V_84 * );
struct V_90 V_91 ;
struct V_92 * V_77 ;
if ( V_87 -> V_93 ) {
F_19 ( F_43 ( V_85 ) ,
V_87 -> V_28 ,
F_44 ( V_85 ) ) ;
F_9 ( V_87 -> V_28 ,
V_87 -> V_93 ) ;
}
V_77 = & V_68 -> V_69 . V_77 ;
V_85 -> V_94 = V_77 -> V_95 ;
if ( V_85 -> V_94 ) {
if ( F_45 ( V_85 -> V_96 ,
V_97 , & V_91 ) )
F_46 ( L_10 , & V_91 ) ;
}
F_47 ( V_85 ,
V_68 -> V_98 . V_26 -
V_77 -> V_99 ) ;
F_42 = V_85 -> V_100 ;
V_85 -> V_101 = NULL ;
V_85 -> V_100 = NULL ;
F_42 ( V_85 ) ;
F_48 ( V_52 -> V_54 , V_87 ) ;
}
static int F_49 ( struct V_84 * V_85 ,
void (* F_50)( struct V_84 * ) )
{
int V_70 ;
struct V_51 * V_52 =
(struct V_51 * ) V_85 -> V_50 -> V_49 -> V_53 ;
struct V_46 * V_47 = V_52 -> V_47 ;
struct V_67 * V_68 ;
struct V_86 * V_87 ;
unsigned int V_102 = 0 ;
int V_21 ;
struct V_18 * V_19 ;
unsigned int V_20 = 0 ;
struct V_92 * V_77 ;
if ( V_85 -> V_101 ) {
V_87 =
(struct V_86 * ) V_85 -> V_101 ;
F_5 ( V_15 , L_11 ,
V_85 , V_87 ) ;
goto V_103;
}
V_85 -> V_100 = F_50 ;
V_102 = sizeof( struct V_86 ) ;
V_87 = F_51 ( V_52 -> V_54 ,
V_30 ) ;
if ( ! V_87 ) {
V_85 -> V_100 = NULL ;
return V_104 ;
}
V_87 -> V_93 = 0 ;
V_87 -> V_28 = NULL ;
V_87 -> V_89 = V_85 ;
V_85 -> V_101 = ( unsigned char * ) V_87 ;
V_68 = & V_87 -> V_68 ;
V_77 = & V_68 -> V_69 . V_77 ;
switch ( V_85 -> V_105 ) {
case V_106 :
V_77 -> V_107 = V_108 ;
break;
case V_109 :
V_77 -> V_107 = V_110 ;
break;
default:
V_77 -> V_107 = V_111 ;
break;
}
V_68 -> V_112 = F_41 ;
V_68 -> V_88 = V_87 ;
V_77 -> V_113 = V_52 -> V_114 ;
V_77 -> V_78 = V_85 -> V_50 -> V_79 ;
V_77 -> V_115 = V_85 -> V_50 -> V_116 ;
V_77 -> V_117 = V_85 -> V_50 -> V_117 ;
V_77 -> V_118 = V_85 -> V_119 ;
memcpy ( V_77 -> V_120 , V_85 -> V_121 , V_77 -> V_118 ) ;
V_68 -> V_96 = V_85 -> V_96 ;
V_68 -> V_98 . V_26 = F_52 ( V_85 ) ;
if ( F_44 ( V_85 ) ) {
V_19 = (struct V_18 * ) F_43 ( V_85 ) ;
V_20 = F_44 ( V_85 ) ;
if ( F_13 ( V_19 , F_44 ( V_85 ) ) != - 1 ) {
V_87 -> V_28 =
F_14 ( V_19 , F_44 ( V_85 ) ,
F_52 ( V_85 ) ) ;
if ( ! V_87 -> V_28 ) {
V_85 -> V_100 = NULL ;
V_85 -> V_101 = NULL ;
F_48 ( V_52 -> V_54 ,
V_87 ) ;
return V_122 ;
}
V_87 -> V_93 =
F_15 ( F_52 ( V_85 ) , V_16 ) >>
V_29 ;
F_25 ( V_19 , V_87 -> V_28 ,
F_44 ( V_85 ) ) ;
V_19 = V_87 -> V_28 ;
V_20 = V_87 -> V_93 ;
}
V_68 -> V_98 . V_24 = V_19 [ 0 ] . V_24 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ )
V_68 -> V_98 . V_123 [ V_21 ] =
F_53 ( F_10 ( ( & V_19 [ V_21 ] ) ) ) ;
} else if ( F_43 ( V_85 ) ) {
V_68 -> V_98 . V_24 =
F_54 ( F_43 ( V_85 ) ) & ( V_16 - 1 ) ;
V_68 -> V_98 . V_123 [ 0 ] =
F_54 ( F_43 ( V_85 ) ) >> V_29 ;
}
V_103:
V_70 = F_55 ( V_47 , & V_87 -> V_68 ) ;
if ( V_70 == - 1 ) {
if ( V_87 -> V_93 ) {
F_19 ( F_43 ( V_85 ) ,
V_87 -> V_28 ,
F_44 ( V_85 ) ) ;
F_9 ( V_87 -> V_28 ,
V_87 -> V_93 ) ;
}
F_48 ( V_52 -> V_54 , V_87 ) ;
V_85 -> V_100 = NULL ;
V_85 -> V_101 = NULL ;
V_70 = V_104 ;
}
return V_70 ;
}
static int F_56 ( struct V_46 * V_50 )
{
int V_70 ;
struct V_48 * V_49 ;
struct V_51 * V_52 ;
struct V_124 V_125 ;
V_49 = F_57 ( & V_126 ,
sizeof( struct V_51 ) ) ;
if ( ! V_49 )
return - V_127 ;
F_58 ( & V_50 -> V_50 , V_49 ) ;
V_52 = (struct V_51 * ) V_49 -> V_53 ;
memset ( V_52 , 0 , sizeof( struct V_51 ) ) ;
V_52 -> V_114 = V_49 -> V_128 ;
V_52 -> V_47 = V_50 ;
V_52 -> V_54 =
F_59 ( F_60 ( & V_50 -> V_50 ) ,
sizeof( struct V_86 ) , 0 ,
V_129 , NULL ) ;
if ( ! V_52 -> V_54 ) {
F_31 ( V_49 ) ;
return - V_127 ;
}
V_125 . V_113 = V_49 -> V_128 ;
V_125 . V_130 = V_131 ;
V_70 = F_61 ( V_50 , ( void * ) & V_125 ) ;
if ( V_70 != 0 ) {
F_29 ( V_52 -> V_54 ) ;
F_31 ( V_49 ) ;
return - 1 ;
}
V_52 -> V_132 = V_125 . V_78 ;
V_52 -> V_133 = V_125 . V_115 ;
V_49 -> V_134 = V_135 ;
V_49 -> V_136 = V_137 ;
V_49 -> V_138 = V_139 - 1 ;
V_70 = F_62 ( V_49 , & V_50 -> V_50 ) ;
if ( V_70 != 0 ) {
F_28 ( V_50 ) ;
F_29 ( V_52 -> V_54 ) ;
F_31 ( V_49 ) ;
return - 1 ;
}
F_63 ( V_49 ) ;
return V_70 ;
}
static int F_64 ( void )
{
int V_70 ;
struct V_140 * V_141 = & V_142 ;
T_2 V_143 ;
V_143 =
( ( V_131 - V_16 ) /
F_15 ( V_144 +
sizeof( struct V_69 ) + sizeof( V_145 ) ,
sizeof( V_145 ) ) ) ;
memcpy ( & V_141 -> V_146 , & V_147 ,
sizeof( struct V_148 ) ) ;
if ( V_143 <
V_14 )
return - 1 ;
V_141 -> V_149 = V_150 ;
V_141 -> V_151 . V_149 = V_150 ;
V_70 = F_65 ( & V_141 -> V_151 ) ;
return V_70 ;
}
static void F_66 ( void )
{
F_67 ( & V_142 . V_151 ) ;
}
static int T_3 F_68 ( void )
{
int V_70 ;
F_5 ( V_15 , L_12 ) ;
V_70 = F_64 () ;
return V_70 ;
}
static void T_4 F_69 ( void )
{
F_66 () ;
}
