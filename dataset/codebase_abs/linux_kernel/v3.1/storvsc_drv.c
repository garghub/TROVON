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
F_5 ( V_2 -> V_6 , V_15 ) ;
F_6 ( V_2 -> V_6 , F_2 ) ;
F_7 ( V_2 -> V_6 , V_16 ) ;
return 0 ;
}
static void F_8 ( struct V_17 * V_18 ,
unsigned int V_19 )
{
int V_20 ;
struct V_21 * V_22 ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
V_22 = F_9 ( ( & V_18 [ V_20 ] ) ) ;
if ( V_22 != NULL )
F_10 ( V_22 ) ;
}
F_11 ( V_18 ) ;
}
static int F_12 ( struct V_17 * V_18 , unsigned int V_19 )
{
int V_20 ;
if ( V_19 < 2 )
return - 1 ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
if ( V_20 == 0 ) {
if ( V_18 [ V_20 ] . V_23 + V_18 [ V_20 ] . V_24 != V_15 )
return V_20 ;
} else if ( V_20 == V_19 - 1 ) {
if ( V_18 [ V_20 ] . V_23 != 0 )
return V_20 ;
} else {
if ( V_18 [ V_20 ] . V_24 != V_15 || V_18 [ V_20 ] . V_23 != 0 )
return V_20 ;
}
}
return - 1 ;
}
static struct V_17 * F_13 ( struct V_17 * V_18 ,
unsigned int V_19 ,
unsigned int V_25 )
{
int V_20 ;
int V_26 ;
struct V_17 * V_27 ;
struct V_21 * V_22 ;
V_26 = F_14 ( V_25 , V_15 ) >> V_28 ;
V_27 = F_15 ( V_26 , sizeof( struct V_17 ) , V_29 ) ;
if ( ! V_27 )
return NULL ;
for ( V_20 = 0 ; V_20 < V_26 ; V_20 ++ ) {
V_22 = F_16 ( V_29 ) ;
if ( ! V_22 )
goto V_30;
F_17 ( & V_27 [ V_20 ] , V_22 , 0 , 0 ) ;
}
return V_27 ;
V_30:
F_8 ( V_27 , V_26 ) ;
return NULL ;
}
static unsigned int F_18 ( struct V_17 * V_31 ,
struct V_17 * V_27 ,
unsigned int V_32 )
{
int V_20 ;
int V_33 = 0 ;
unsigned long V_34 , V_35 ;
unsigned int V_36 , V_37 , V_38 ;
unsigned int V_39 = 0 ;
unsigned long V_40 = 0 ;
unsigned long V_41 = 0 ;
unsigned long V_42 ;
F_19 ( V_42 ) ;
for ( V_20 = 0 ; V_20 < V_32 ; V_20 ++ ) {
V_41 = ( unsigned long ) F_20 ( F_9 ( ( & V_31 [ V_20 ] ) ) ,
V_43 ) + V_31 [ V_20 ] . V_23 ;
V_35 = V_41 ;
V_37 = V_31 [ V_20 ] . V_24 ;
if ( V_40 == 0 )
V_40 =
( unsigned long ) F_20 ( F_9 ( ( & V_27 [ V_33 ] ) ) ,
V_43 ) ;
while ( V_37 ) {
V_34 = V_40 + V_27 [ V_33 ] . V_23 ;
V_36 = V_27 [ V_33 ] . V_24 - V_27 [ V_33 ] . V_23 ;
V_38 = F_21 ( V_36 , V_37 ) ;
memcpy ( ( void * ) V_35 , ( void * ) V_34 , V_38 ) ;
V_39 += V_38 ;
V_27 [ V_33 ] . V_23 += V_38 ;
V_37 -= V_38 ;
V_35 += V_38 ;
if ( V_27 [ V_33 ] . V_23 == V_27 [ V_33 ] . V_24 ) {
F_22 ( ( void * ) V_40 , V_43 ) ;
V_33 ++ ;
if ( V_37 || V_20 != V_32 - 1 )
V_40 =
( unsigned long ) F_20 (
F_9 ( ( & V_27 [ V_33 ] ) ) , V_43 ) ;
} else if ( V_37 == 0 && V_20 == V_32 - 1 ) {
F_22 ( ( void * ) V_40 , V_43 ) ;
}
}
F_22 ( ( void * ) ( V_41 - V_31 [ V_20 ] . V_23 ) ,
V_43 ) ;
}
F_23 ( V_42 ) ;
return V_39 ;
}
static unsigned int F_24 ( struct V_17 * V_31 ,
struct V_17 * V_27 ,
unsigned int V_32 )
{
int V_20 ;
int V_33 = 0 ;
unsigned long V_34 , V_35 ;
unsigned int V_36 , V_37 , V_38 ;
unsigned int V_39 = 0 ;
unsigned long V_40 = 0 ;
unsigned long V_44 = 0 ;
unsigned long V_42 ;
F_19 ( V_42 ) ;
for ( V_20 = 0 ; V_20 < V_32 ; V_20 ++ ) {
V_44 = ( unsigned long ) F_20 ( F_9 ( ( & V_31 [ V_20 ] ) ) ,
V_43 ) + V_31 [ V_20 ] . V_23 ;
V_34 = V_44 ;
V_36 = V_31 [ V_20 ] . V_24 ;
if ( V_40 == 0 )
V_40 =
( unsigned long ) F_20 ( F_9 ( ( & V_27 [ V_33 ] ) ) ,
V_43 ) ;
while ( V_36 ) {
V_35 = V_40 + V_27 [ V_33 ] . V_24 ;
V_37 = V_15 - V_27 [ V_33 ] . V_24 ;
V_38 = F_21 ( V_36 , V_37 ) ;
memcpy ( ( void * ) V_35 , ( void * ) V_34 , V_38 ) ;
V_39 += V_38 ;
V_27 [ V_33 ] . V_24 += V_38 ;
V_36 -= V_38 ;
V_34 += V_38 ;
if ( V_27 [ V_33 ] . V_24 == V_15 ) {
F_22 ( ( void * ) V_40 , V_43 ) ;
V_33 ++ ;
if ( V_36 || V_20 != V_32 - 1 )
V_40 =
( unsigned long ) F_20 (
F_9 ( ( & V_27 [ V_33 ] ) ) , V_43 ) ;
} else if ( V_36 == 0 && V_20 == V_32 - 1 ) {
F_22 ( ( void * ) V_40 , V_43 ) ;
}
}
F_22 ( ( void * ) ( V_44 - V_31 [ V_20 ] . V_23 ) , V_43 ) ;
}
F_23 ( V_42 ) ;
return V_39 ;
}
static int F_25 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_26 ( & V_46 -> V_49 ) ;
struct V_50 * V_51 =
(struct V_50 * ) V_48 -> V_52 ;
F_27 ( V_48 ) ;
F_28 ( V_48 ) ;
F_29 ( V_46 ) ;
if ( V_51 -> V_53 ) {
F_30 ( V_51 -> V_53 ) ;
V_51 -> V_53 = NULL ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_54 , struct V_55 * V_56 ,
T_1 V_57 , int * V_58 )
{
T_1 V_59 = V_57 ;
T_1 V_60 = V_59 ;
int V_61 , V_62 ;
V_61 = 0xff ;
V_62 = 0x3f ;
F_32 ( V_60 , V_61 * V_62 ) ;
if ( ( T_1 ) ( V_60 + 1 ) * V_61 * V_62 < V_59 )
V_60 = 0xffff ;
V_58 [ 0 ] = V_61 ;
V_58 [ 1 ] = V_62 ;
V_58 [ 2 ] = ( int ) V_60 ;
return 0 ;
}
static int F_33 ( struct V_45 * V_49 )
{
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_67 * V_67 ;
int V_68 , V_69 ;
V_64 = F_34 ( V_49 ) ;
if ( ! V_64 )
return - 1 ;
V_66 = & V_64 -> V_70 ;
V_67 = & V_66 -> V_67 ;
F_35 ( & V_66 -> V_71 ) ;
V_67 -> V_72 = V_73 ;
V_67 -> V_42 = V_74 ;
V_67 -> V_75 . V_76 = V_64 -> V_76 ;
V_68 = F_36 ( V_49 -> V_77 , V_67 ,
sizeof( struct V_67 ) ,
( unsigned long ) & V_64 -> V_70 ,
V_78 ,
V_79 ) ;
if ( V_68 != 0 )
goto V_30;
V_69 = F_37 ( & V_66 -> V_71 , 5 * V_80 ) ;
if ( V_69 == 0 ) {
V_68 = - V_81 ;
goto V_30;
}
V_30:
F_38 ( V_49 ) ;
return V_68 ;
}
static int F_39 ( struct V_82 * V_83 )
{
int V_68 ;
struct V_50 * V_51 =
(struct V_50 * ) V_83 -> V_49 -> V_48 -> V_52 ;
struct V_45 * V_46 = V_51 -> V_46 ;
V_68 = F_33 ( V_46 ) ;
if ( V_68 != 0 )
return V_68 ;
return V_68 ;
}
static void F_40 ( struct V_65 * V_66 )
{
struct V_84 * V_85 =
(struct V_84 * ) V_66 -> V_86 ;
struct V_82 * V_83 = V_85 -> V_87 ;
struct V_50 * V_51 =
(struct V_50 * ) V_83 -> V_49 -> V_48 -> V_52 ;
void (* F_41)( struct V_82 * );
struct V_88 V_89 ;
struct V_90 * V_75 ;
if ( V_85 -> V_91 ) {
F_18 ( F_42 ( V_83 ) ,
V_85 -> V_27 ,
F_43 ( V_83 ) ) ;
F_8 ( V_85 -> V_27 ,
V_85 -> V_91 ) ;
}
V_75 = & V_66 -> V_67 . V_75 ;
V_83 -> V_92 = V_75 -> V_93 ;
if ( V_83 -> V_92 ) {
if ( F_44 ( V_83 -> V_94 ,
V_95 , & V_89 ) )
F_45 ( L_1 , & V_89 ) ;
}
F_46 ( V_83 ,
V_66 -> V_96 . V_25 -
V_75 -> V_97 ) ;
F_41 = V_83 -> V_98 ;
V_83 -> V_99 = NULL ;
V_83 -> V_98 = NULL ;
F_41 ( V_83 ) ;
F_47 ( V_51 -> V_53 , V_85 ) ;
}
static int F_48 ( struct V_82 * V_83 ,
void (* F_49)( struct V_82 * ) )
{
int V_68 ;
struct V_50 * V_51 =
(struct V_50 * ) V_83 -> V_49 -> V_48 -> V_52 ;
struct V_45 * V_46 = V_51 -> V_46 ;
struct V_65 * V_66 ;
struct V_84 * V_85 ;
unsigned int V_100 = 0 ;
int V_20 ;
struct V_17 * V_18 ;
unsigned int V_19 = 0 ;
struct V_90 * V_75 ;
if ( V_83 -> V_99 ) {
V_85 =
(struct V_84 * ) V_83 -> V_99 ;
goto V_101;
}
V_83 -> V_98 = F_49 ;
V_100 = sizeof( struct V_84 ) ;
V_85 = F_50 ( V_51 -> V_53 ,
V_29 ) ;
if ( ! V_85 ) {
V_83 -> V_98 = NULL ;
return V_102 ;
}
V_85 -> V_91 = 0 ;
V_85 -> V_27 = NULL ;
V_85 -> V_87 = V_83 ;
V_83 -> V_99 = ( unsigned char * ) V_85 ;
V_66 = & V_85 -> V_66 ;
V_75 = & V_66 -> V_67 . V_75 ;
switch ( V_83 -> V_103 ) {
case V_104 :
V_75 -> V_105 = V_106 ;
break;
case V_107 :
V_75 -> V_105 = V_108 ;
break;
default:
V_75 -> V_105 = V_109 ;
break;
}
V_66 -> V_110 = F_40 ;
V_66 -> V_86 = V_85 ;
V_75 -> V_111 = V_51 -> V_112 ;
V_75 -> V_76 = V_83 -> V_49 -> V_77 ;
V_75 -> V_113 = V_83 -> V_49 -> V_114 ;
V_75 -> V_115 = V_83 -> V_49 -> V_115 ;
V_75 -> V_116 = V_83 -> V_117 ;
memcpy ( V_75 -> V_118 , V_83 -> V_119 , V_75 -> V_116 ) ;
V_66 -> V_94 = V_83 -> V_94 ;
V_66 -> V_96 . V_25 = F_51 ( V_83 ) ;
if ( F_43 ( V_83 ) ) {
V_18 = (struct V_17 * ) F_42 ( V_83 ) ;
V_19 = F_43 ( V_83 ) ;
if ( F_12 ( V_18 , F_43 ( V_83 ) ) != - 1 ) {
V_85 -> V_27 =
F_13 ( V_18 , F_43 ( V_83 ) ,
F_51 ( V_83 ) ) ;
if ( ! V_85 -> V_27 ) {
V_83 -> V_98 = NULL ;
V_83 -> V_99 = NULL ;
F_47 ( V_51 -> V_53 ,
V_85 ) ;
return V_120 ;
}
V_85 -> V_91 =
F_14 ( F_51 ( V_83 ) , V_15 ) >>
V_28 ;
F_24 ( V_18 , V_85 -> V_27 ,
F_43 ( V_83 ) ) ;
V_18 = V_85 -> V_27 ;
V_19 = V_85 -> V_91 ;
}
V_66 -> V_96 . V_23 = V_18 [ 0 ] . V_23 ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ )
V_66 -> V_96 . V_121 [ V_20 ] =
F_52 ( F_9 ( ( & V_18 [ V_20 ] ) ) ) ;
} else if ( F_42 ( V_83 ) ) {
V_66 -> V_96 . V_23 =
F_53 ( F_42 ( V_83 ) ) & ( V_15 - 1 ) ;
V_66 -> V_96 . V_121 [ 0 ] =
F_53 ( F_42 ( V_83 ) ) >> V_28 ;
}
V_101:
V_68 = F_54 ( V_46 , & V_85 -> V_66 ) ;
if ( V_68 == - 1 ) {
if ( V_85 -> V_91 ) {
F_18 ( F_42 ( V_83 ) ,
V_85 -> V_27 ,
F_43 ( V_83 ) ) ;
F_8 ( V_85 -> V_27 ,
V_85 -> V_91 ) ;
}
F_47 ( V_51 -> V_53 , V_85 ) ;
V_83 -> V_98 = NULL ;
V_83 -> V_99 = NULL ;
V_68 = V_102 ;
}
return V_68 ;
}
static int F_55 ( struct V_45 * V_49 )
{
int V_68 ;
struct V_47 * V_48 ;
struct V_50 * V_51 ;
struct V_122 V_123 ;
V_48 = F_56 ( & V_124 ,
sizeof( struct V_50 ) ) ;
if ( ! V_48 )
return - V_125 ;
F_57 ( & V_49 -> V_49 , V_48 ) ;
V_51 = (struct V_50 * ) V_48 -> V_52 ;
memset ( V_51 , 0 , sizeof( struct V_50 ) ) ;
V_51 -> V_112 = V_48 -> V_126 ;
V_51 -> V_46 = V_49 ;
V_51 -> V_53 =
F_58 ( F_59 ( & V_49 -> V_49 ) ,
sizeof( struct V_84 ) , 0 ,
V_127 , NULL ) ;
if ( ! V_51 -> V_53 ) {
F_28 ( V_48 ) ;
return - V_125 ;
}
V_123 . V_111 = V_48 -> V_126 ;
V_123 . V_128 = V_129 ;
V_68 = F_60 ( V_49 , ( void * ) & V_123 ) ;
if ( V_68 != 0 ) {
F_30 ( V_51 -> V_53 ) ;
F_28 ( V_48 ) ;
return - 1 ;
}
V_51 -> V_130 = V_123 . V_76 ;
V_51 -> V_131 = V_123 . V_113 ;
V_48 -> V_132 = V_133 ;
V_48 -> V_134 = V_135 ;
V_48 -> V_136 = V_137 - 1 ;
V_68 = F_61 ( V_48 , & V_49 -> V_49 ) ;
if ( V_68 != 0 ) {
F_29 ( V_49 ) ;
F_30 ( V_51 -> V_53 ) ;
F_28 ( V_48 ) ;
return - 1 ;
}
F_62 ( V_48 ) ;
return V_68 ;
}
static int T_2 F_63 ( void )
{
int V_68 ;
struct V_138 * V_139 = & V_140 ;
T_3 V_141 ;
V_141 =
( ( V_129 - V_15 ) /
F_14 ( V_142 +
sizeof( struct V_67 ) + sizeof( V_143 ) ,
sizeof( V_143 ) ) ) ;
memcpy ( & V_139 -> V_144 , & V_145 ,
sizeof( struct V_146 ) ) ;
if ( V_141 <
V_14 )
return - 1 ;
V_139 -> V_147 . V_148 = V_149 ;
V_68 = F_64 ( & V_139 -> V_147 ) ;
return V_68 ;
}
static void T_4 F_65 ( void )
{
F_66 ( & V_140 . V_147 ) ;
}
