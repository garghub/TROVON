static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
T_2 V_15 = 0 ;
V_10 = & V_2 -> V_16 ;
V_12 = V_2 -> V_17 -> V_12 ;
F_2 ( & V_10 -> V_18 , V_3 ) ;
if ( V_10 -> V_19 != 0 ) {
if ( ( ( V_10 -> V_20 - 1 ) == F_3 ( & V_2 -> V_21 ) ) &&
( F_3 ( & V_2 -> V_22 ) == 0 ) ) {
F_4 ( & V_2 -> V_22 , 1 ) ;
F_5 ( & V_10 -> V_18 , V_3 ) ;
V_2 -> V_23 . V_24 = V_25 + ( V_26 / 2 ) ;
F_6 ( & V_2 -> V_23 ) ;
} else {
F_5 ( & V_10 -> V_18 , V_3 ) ;
}
return;
}
V_10 -> V_19 = 1 ;
F_5 ( & V_10 -> V_18 , V_3 ) ;
do {
V_6 = F_7 ( V_2 -> V_17 -> V_27 ) ;
if ( V_6 ) {
V_6 -> V_28 = V_2 -> V_17 -> V_29 ;
V_4 = F_8 ( V_12 -> V_30 ,
V_6 -> V_31 , V_2 -> V_17 -> V_27 , V_32 ) ;
V_14 = (struct V_13 * ) & V_6 -> V_14 [ 0 ] ;
V_14 -> V_33 = V_4 ;
V_14 -> V_34 = V_2 -> V_17 -> V_27 ;
V_8 = & V_10 -> V_35 [ V_2 -> V_16 . V_36 ] ;
V_8 -> V_37 [ V_38 ] =
F_9 ( V_2 -> V_17 -> V_27 ) ;
V_8 -> V_37 [ V_39 ] = 0 ;
V_8 -> V_37 [ V_40 ] =
F_9 ( ( T_2 ) V_4 ) ;
V_8 -> V_37 [ V_41 ] =
F_9 ( ( T_2 ) ( ( V_42 ) V_4 >> 32 ) ) ;
V_10 -> V_43 [ V_10 -> V_36 ] = V_6 ;
V_10 -> V_36 ++ ;
V_10 -> V_36 &= V_10 -> V_20 - 1 ;
F_10 ( & V_2 -> V_21 ) ;
F_11 () ;
if ( ++ V_15 == 255 ) {
F_12 ( V_12 -> V_44 + V_45 , ( V_15 << 24 ) | V_10 -> V_46 ) ;
V_15 = 0 ;
}
} else {
F_2 ( & V_10 -> V_18 , V_3 ) ;
if ( ( ( V_10 -> V_20 - 1 ) == F_3 ( & V_2 -> V_21 ) ) &&
( F_3 ( & V_2 -> V_22 ) == 0 ) ) {
F_4 ( & V_2 -> V_22 , 1 ) ;
F_5 ( & V_10 -> V_18 , V_3 ) ;
V_2 -> V_23 . V_24 = V_25 + ( V_26 / 2 ) ;
F_6 ( & V_2 -> V_23 ) ;
} else {
F_5 ( & V_10 -> V_18 , V_3 ) ;
}
break;
}
} while ( F_3 ( & V_2 -> V_21 ) );
F_11 () ;
if ( V_15 )
F_12 ( V_12 -> V_44 + V_45 , ( V_15 << 24 ) | V_10 -> V_46 ) ;
V_10 -> V_19 = 0 ;
}
static void F_13 ( unsigned long V_47 )
{
struct V_1 * V_2 = (struct V_1 * ) V_47 ;
F_4 ( & V_2 -> V_22 , 0 ) ;
if ( F_3 ( & V_2 -> V_21 ) )
F_1 ( V_2 ) ;
}
static void F_14 ( struct V_11 * V_12 , struct V_5 * V_6 , T_2 V_48 )
{
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) & V_6 -> V_14 [ 0 ] ;
F_15 ( V_12 -> V_30 , V_14 -> V_33 , V_14 -> V_34 , V_48 ) ;
V_14 -> V_33 = 0 ;
F_16 ( V_6 ) ;
}
static void F_17 ( struct V_11 * V_12 , struct V_49 * V_50 )
{
struct V_51 * V_52 = V_50 -> V_53 ;
struct V_54 * V_55 = V_52 -> V_55 ;
struct V_5 * V_6 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_52 -> V_57 ; V_56 ++ ) {
V_6 = V_52 -> V_58 [ V_56 ] . V_6 ;
if ( V_52 -> V_58 [ V_56 ] . V_59 ) {
F_14 ( V_12 , V_6 , V_60 ) ;
F_18 ( V_55 -> V_61 ) ;
}
}
if ( V_52 -> V_62 )
F_19 ( V_12 -> V_30 , V_52 -> V_63 ,
V_52 -> V_62 , V_52 -> V_64 ) ;
F_20 ( V_52 ) ;
}
static T_2 F_21 ( struct V_5 * V_6 , T_2 * V_65 , T_3 * V_66 , T_2 * V_67 , T_2 * V_68 )
{
struct V_13 * V_14 = (struct V_13 * ) & V_6 -> V_14 [ 0 ] ;
struct V_69 * V_70 = (struct V_69 * ) ( V_14 -> V_71 + V_72 ) ;
struct V_73 * V_74 = (struct V_73 * ) ( ( ( char * ) V_70 ) + ( 4 * V_70 -> V_75 ) ) ;
* V_65 = F_22 ( V_74 -> V_76 ) ;
* V_66 = F_23 ( V_74 -> V_77 ) ;
* V_67 = V_74 -> V_78 ;
* V_68 = V_74 -> V_79 ;
return F_22 ( V_74 -> V_80 ) ;
}
static struct V_5 * F_24 ( struct V_11 * V_12 , struct V_54 * V_55 ,
struct V_5 * V_6 , T_2 V_81 , T_2 * V_65 ,
T_3 * V_66 , T_2 * V_67 , T_2 * V_68 )
{
T_2 V_80 ;
bool V_82 ;
struct V_5 * V_83 ;
if ( V_6 ) {
if ( V_6 -> V_84 == (struct V_5 * ) & V_55 -> V_85 )
goto V_86;
V_6 = V_6 -> V_84 ;
V_82 = false ;
} else {
if ( F_25 ( & V_55 -> V_85 ) )
goto V_86;
V_6 = F_26 ( & V_55 -> V_85 ) ;
V_82 = true ;
}
while ( 1 ) {
V_80 = F_21 ( V_6 , V_65 , V_66 , V_67 , V_68 ) ;
if ( V_80 == V_81 ) {
if ( V_6 -> V_87 || V_82 )
break;
} else if ( F_27 ( V_80 , V_81 ) ) {
goto V_86;
}
if ( V_6 -> V_84 == (struct V_5 * ) & V_55 -> V_85 )
goto V_86;
V_83 = V_6 ;
V_6 = V_6 -> V_84 ;
F_28 ( V_83 , & V_55 -> V_85 ) ;
F_14 ( V_12 , V_83 , V_60 ) ;
F_18 ( V_55 -> V_61 ) ;
}
return V_6 ;
V_86:
return NULL ;
}
static int F_29 ( struct V_11 * V_12 , struct V_54 * V_55 ,
struct V_51 * * V_51 )
{
struct V_5 * V_6 ;
struct V_69 * V_70 ;
struct V_73 * V_74 ;
struct V_13 * V_14 ;
struct V_51 * V_52 = NULL ;
struct V_88 V_58 [ V_89 ] ;
unsigned long V_3 ;
T_2 V_90 = 0 ;
T_2 V_91 ;
int V_57 = 0 ;
T_2 V_92 ;
T_2 V_93 ;
T_2 V_65 ;
T_2 V_67 ;
T_2 V_68 ;
T_3 V_66 ;
int V_56 ;
int V_94 = 0 ;
* V_51 = NULL ;
F_2 ( & V_55 -> V_95 , V_3 ) ;
V_6 = F_24 ( V_12 , V_55 , NULL , V_55 -> V_96 , & V_65 , & V_66 , & V_67 , & V_68 ) ;
if ( ! V_6 ) {
F_5 ( & V_55 -> V_95 , V_3 ) ;
goto V_86;
}
V_14 = (struct V_13 * ) & V_6 -> V_14 [ 0 ] ;
if ( V_6 -> V_87 ) {
V_90 = F_23 ( * ( V_97 * ) V_6 -> V_31 ) + V_98 ;
V_90 = ( V_90 + 3 ) & 0xfffffffc ;
V_91 = V_90 ;
V_93 = 0 ;
memset ( & V_58 , 0 , sizeof V_58 ) ;
for ( V_56 = 0 ; V_56 < V_89 ; V_56 ++ ) {
V_58 [ V_56 ] . V_99 = V_14 -> V_33 ;
V_58 [ V_56 ] . V_99 += V_6 -> V_31 - V_14 -> V_71 ;
V_58 [ V_56 ] . V_100 = F_30 ( V_91 , V_6 -> V_87 ) ;
V_58 [ V_56 ] . V_6 = V_6 ;
V_58 [ V_56 ] . V_59 = ( V_6 -> V_87 == V_58 [ V_56 ] . V_100 ) ;
V_93 += V_58 [ V_56 ] . V_100 ;
V_57 ++ ;
V_91 -= V_58 [ V_56 ] . V_100 ;
if ( V_91 == 0 )
break;
V_6 = F_24 ( V_12 , V_55 , V_6 ,
V_55 -> V_96 + V_93 , & V_65 , & V_66 , & V_67 , & V_68 ) ;
if ( ! V_6 ) {
F_5 ( & V_55 -> V_95 , V_3 ) ;
goto V_86;
} else if ( V_68 ) {
for (; V_56 >= 0 ; V_56 -- ) {
F_28 ( V_58 [ V_56 ] . V_6 , & V_55 -> V_85 ) ;
F_14 ( V_12 , V_58 [ V_56 ] . V_6 , V_60 ) ;
}
V_14 = (struct V_13 * ) & V_6 -> V_14 [ 0 ] ;
V_58 [ 0 ] . V_99 = V_14 -> V_33 ;
V_58 [ 0 ] . V_99 += V_6 -> V_31 - V_14 -> V_71 ;
V_58 [ 0 ] . V_100 = V_6 -> V_87 ;
V_58 [ 0 ] . V_6 = V_6 ;
V_58 [ 0 ] . V_59 = true ;
V_57 = 1 ;
break;
}
V_14 = (struct V_13 * ) & V_6 -> V_14 [ 0 ] ;
}
} else {
V_58 [ 0 ] . V_99 = V_14 -> V_33 ;
V_58 [ 0 ] . V_100 = 0 ;
V_58 [ 0 ] . V_6 = V_6 ;
V_58 [ 0 ] . V_59 = true ;
V_57 = 1 ;
}
F_5 ( & V_55 -> V_95 , V_3 ) ;
V_52 = F_31 ( sizeof( * V_52 ) , V_101 ) ;
if ( V_52 == NULL ) {
F_32 ( V_102 , L_1 ) ;
V_94 = - V_103 ;
goto V_86;
}
V_52 -> V_50 = F_33 ( V_12 ) ;
if ( V_52 -> V_50 == NULL ) {
F_32 ( V_102 , L_2 ) ;
V_94 = - V_103 ;
goto V_86;
}
V_14 = (struct V_13 * ) & V_58 [ 0 ] . V_6 -> V_14 [ 0 ] ;
V_70 = (struct V_69 * ) ( V_14 -> V_71 + V_72 ) ;
V_74 = (struct V_73 * ) ( ( ( char * ) V_70 ) + ( 4 * V_70 -> V_75 ) ) ;
V_52 -> V_63 = ( ( ( unsigned char * ) V_74 ) + 4 * ( V_74 -> V_104 ) ) - V_14 -> V_71 ;
V_52 -> V_105 = V_90 ;
V_92 = V_52 -> V_63 + V_90 - V_72 ;
if ( V_58 [ 0 ] . V_59 ) {
V_52 -> V_64 = V_14 -> V_33 ;
V_52 -> V_62 = NULL ;
} else {
V_52 -> V_62 = F_34 ( V_12 -> V_30 ,
V_52 -> V_63 , & V_52 -> V_64 ) ;
if ( ! V_52 -> V_62 ) {
F_32 ( V_102 , L_3 ) ;
V_94 = - V_103 ;
goto V_86;
}
memcpy ( V_52 -> V_62 , V_14 -> V_71 , V_52 -> V_63 ) ;
V_70 = (struct V_69 * ) ( V_52 -> V_62 + V_72 ) ;
V_74 = (struct V_73 * ) ( ( ( char * ) V_70 ) + ( 4 * V_70 -> V_75 ) ) ;
}
V_70 -> V_92 = F_35 ( V_92 ) ;
V_70 -> V_106 = F_36 ( 0x7f000001 ) ;
V_74 -> V_80 = F_36 ( V_55 -> V_96 ) ;
V_74 -> V_76 = F_36 ( V_65 ) ;
V_74 -> V_77 = F_35 ( V_66 ) ;
V_55 -> V_96 += V_90 + V_67 ;
memcpy ( V_52 -> V_58 , V_58 , sizeof( V_52 -> V_58 ) ) ;
V_52 -> V_57 = V_57 ;
V_52 -> V_55 = V_55 ;
* V_51 = V_52 ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
V_14 = (struct V_13 * ) & V_58 [ V_56 ] . V_6 -> V_14 [ 0 ] ;
F_37 ( V_58 [ V_56 ] . V_6 , V_58 [ V_56 ] . V_100 ) ;
if ( V_58 [ V_56 ] . V_6 -> V_87 == 0 ) {
F_2 ( & V_55 -> V_95 , V_3 ) ;
F_28 ( V_58 [ V_56 ] . V_6 , & V_55 -> V_85 ) ;
F_5 ( & V_55 -> V_95 , V_3 ) ;
} else {
V_70 = (struct V_69 * ) ( V_14 -> V_71 + V_72 ) ;
V_74 = (struct V_73 * ) ( ( ( char * ) V_70 ) + ( 4 * V_70 -> V_75 ) ) ;
V_74 -> V_80 = F_36 ( V_55 -> V_96 ) ;
}
}
V_86:
if ( V_94 ) {
if ( V_52 ) {
if ( V_52 -> V_50 )
F_38 ( V_12 , V_52 -> V_50 ) ;
F_20 ( V_52 ) ;
}
}
return V_94 ;
}
static int F_39 ( struct V_107 * V_17 , struct V_54 * V_55 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_51 * V_52 ;
struct V_108 * V_109 ;
struct V_49 * V_50 ;
V_42 V_110 ;
T_2 V_111 ;
int V_94 ;
while ( 1 ) {
V_94 = F_29 ( V_12 , V_55 , & V_52 ) ;
if ( V_52 == NULL )
return V_94 ;
V_50 = V_52 -> V_50 ;
V_109 = & V_50 -> V_109 ;
F_40 ( V_109 , V_12 ) ;
F_41 ( V_109 -> V_37 , V_112 ,
V_113 |
( ( ( T_2 ) V_17 -> V_114 ) << V_115 ) ) ;
V_111 = V_52 -> V_63 << 16 ;
V_111 |= V_52 -> V_63 + ( T_2 ) V_52 -> V_105 ;
F_41 ( V_109 -> V_37 , V_116 ,
V_111 ) ;
V_111 = ( V_52 -> V_58 [ 1 ] . V_100 << 16 ) | V_52 -> V_58 [ 0 ] . V_100 ;
F_41 ( V_109 -> V_37 , V_117 ,
V_111 ) ;
V_111 = ( V_52 -> V_58 [ 3 ] . V_100 << 16 ) | V_52 -> V_58 [ 2 ] . V_100 ;
F_41 ( V_109 -> V_37 , V_118 ,
V_111 ) ;
V_110 = ( V_42 ) V_52 -> V_64 ;
F_41 ( V_109 -> V_37 , V_119 ,
F_42 ( V_110 ) ) ;
F_41 ( V_109 -> V_37 , V_120 ,
F_43 ( V_110 >> 32 ) ) ;
F_41 ( V_109 -> V_37 , V_121 ,
F_42 ( V_52 -> V_58 [ 0 ] . V_99 ) ) ;
F_41 ( V_109 -> V_37 , V_122 ,
F_43 ( V_52 -> V_58 [ 0 ] . V_99 ) ) ;
F_41 ( V_109 -> V_37 , V_123 ,
F_42 ( V_52 -> V_58 [ 1 ] . V_99 ) ) ;
F_41 ( V_109 -> V_37 , V_124 ,
F_43 ( V_52 -> V_58 [ 1 ] . V_99 ) ) ;
F_41 ( V_109 -> V_37 , V_125 ,
F_42 ( V_52 -> V_58 [ 2 ] . V_99 ) ) ;
F_41 ( V_109 -> V_37 , V_126 ,
F_43 ( V_52 -> V_58 [ 2 ] . V_99 ) ) ;
F_41 ( V_109 -> V_37 , V_127 ,
F_42 ( V_52 -> V_58 [ 3 ] . V_99 ) ) ;
F_41 ( V_109 -> V_37 , V_128 ,
F_43 ( V_52 -> V_58 [ 3 ] . V_99 ) ) ;
V_50 -> V_53 = V_52 ;
V_50 -> V_129 = 1 ;
V_50 -> V_130 = F_17 ;
F_4 ( & V_50 -> V_131 , 1 ) ;
F_44 ( V_12 , V_50 ) ;
}
return 0 ;
}
static void F_45 ( struct V_107 * V_17 , struct V_54 * V_55 )
{
int V_132 = 1 ;
unsigned long V_3 ;
do {
F_39 ( V_17 , V_55 ) ;
F_2 ( & V_55 -> V_95 , V_3 ) ;
if ( V_55 -> V_133 ) {
V_55 -> V_133 = 0 ;
} else {
V_55 -> V_134 = 0 ;
V_132 = 0 ;
}
F_5 ( & V_55 -> V_95 , V_3 ) ;
} while ( V_132 );
}
static void F_46 ( struct V_5 * V_6 , struct V_107 * V_17 , struct V_54 * V_55 )
{
struct V_5 * V_135 ;
struct V_13 * V_14 ;
struct V_69 * V_70 ;
struct V_73 * V_74 ;
unsigned char * V_136 ;
T_2 V_137 ;
T_2 V_138 ;
T_2 V_139 ;
T_2 V_87 ;
bool V_140 = false ;
unsigned long V_3 ;
V_70 = (struct V_69 * ) V_6 -> V_31 ;
V_74 = (struct V_73 * ) ( ( ( char * ) V_70 ) + ( 4 * V_70 -> V_75 ) ) ;
V_139 = F_22 ( V_74 -> V_80 ) ;
V_136 = ( ( ( char * ) V_74 ) + ( 4 * V_74 -> V_104 ) ) ;
V_87 = F_23 ( V_70 -> V_92 ) ;
if ( V_6 -> V_87 > V_87 )
F_47 ( V_6 , V_87 ) ;
F_37 ( V_6 , V_136 - V_6 -> V_31 ) ;
V_14 = (struct V_13 * ) & V_6 -> V_14 [ 0 ] ;
V_14 -> V_139 = V_139 ;
V_137 = V_55 -> V_96 ;
V_138 = F_48 ( V_55 -> V_141 -> V_138 ) ;
if ( ! F_49 ( V_139 , V_137 , ( V_137 + V_138 ) ) ) {
F_14 ( V_17 -> V_12 , V_6 , V_60 ) ;
F_18 ( V_55 -> V_61 ) ;
return;
}
F_2 ( & V_55 -> V_95 , V_3 ) ;
if ( V_55 -> V_134 )
V_55 -> V_133 = 1 ;
else
V_55 -> V_134 = 1 ;
if ( F_50 ( & V_55 -> V_85 ) == 0 ) {
F_51 ( & V_55 -> V_85 , V_6 ) ;
} else {
V_135 = V_55 -> V_85 . V_84 ;
while ( V_135 != (struct V_5 * ) & V_55 -> V_85 ) {
V_14 = (struct V_13 * ) & V_135 -> V_14 [ 0 ] ;
if ( F_52 ( V_139 , V_14 -> V_139 ) )
break;
V_135 = V_135 -> V_84 ;
}
F_53 ( V_135 , V_6 , & V_55 -> V_85 ) ;
}
if ( V_55 -> V_142 == V_143 )
V_140 = true ;
F_5 ( & V_55 -> V_95 , V_3 ) ;
if ( V_140 )
F_45 ( V_17 , V_55 ) ;
return;
}
static int F_54 ( void * V_144 )
{
struct V_107 * V_17 = V_144 ;
struct V_5 * V_6 ;
struct V_13 * V_14 ;
while ( ! F_55 () ) {
F_56 ( V_17 -> V_145 ,
F_50 ( & V_17 -> V_146 ) || F_55 () ) ;
while ( ( F_50 ( & V_17 -> V_146 ) ) && ! F_55 () ) {
V_6 = F_57 ( & V_17 -> V_146 ) ;
V_14 = (struct V_13 * ) & V_6 -> V_14 [ 0 ] ;
V_14 -> V_71 = V_6 -> V_31 - V_72 ;
V_14 -> V_33 = F_8 ( V_17 -> V_12 -> V_30 , V_14 -> V_71 ,
V_17 -> V_27 , V_60 ) ;
F_46 ( V_6 , V_17 , V_14 -> V_55 ) ;
}
}
while ( F_50 ( & V_17 -> V_146 ) ) {
V_6 = F_57 ( & V_17 -> V_146 ) ;
V_14 = (struct V_13 * ) & V_6 -> V_14 [ 0 ] ;
F_18 ( V_14 -> V_55 -> V_61 ) ;
F_16 ( V_6 ) ;
}
return 0 ;
}
void F_58 ( struct V_5 * V_6 , struct V_107 * V_17 , struct V_54 * V_55 )
{
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) & V_6 -> V_14 [ 0 ] ;
V_14 -> V_55 = V_55 ;
F_59 ( & V_17 -> V_146 , V_6 ) ;
F_60 ( & V_17 -> V_145 ) ;
}
void F_61 ( struct V_11 * V_12 , struct V_54 * V_55 )
{
struct V_5 * V_6 ;
unsigned long V_3 ;
F_62 ( & V_147 ) ;
F_2 ( & V_55 -> V_95 , V_3 ) ;
while ( F_50 ( & V_55 -> V_85 ) ) {
V_6 = F_57 ( & V_55 -> V_85 ) ;
F_14 ( V_12 , V_6 , V_60 ) ;
F_18 ( V_55 -> V_61 ) ;
}
F_5 ( & V_55 -> V_95 , V_3 ) ;
}
static void F_63 ( struct V_11 * V_12 , struct V_49 * V_50 )
{
struct V_148 * V_149 = V_50 -> V_53 ;
struct V_49 * V_150 ;
struct V_108 * V_109 ;
struct V_151 * V_152 ;
struct V_54 * V_55 ;
struct V_153 V_154 ;
T_2 V_155 ;
V_42 V_156 ;
V_152 = V_12 -> V_152 ;
V_55 = V_149 -> V_55 ;
if ( V_50 -> V_157 ) {
F_64 (KERN_ERR PFX L_4 ,
cqp_request->major_code) ;
F_65 ( 1 ) ;
}
switch ( V_55 -> V_142 ) {
case V_158 :
V_55 -> V_142 = V_159 ;
V_150 = F_33 ( V_12 ) ;
if ( V_150 == NULL ) {
F_32 ( V_102 , L_5 ) ;
F_65 ( 1 ) ;
return;
}
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_160 =
F_9 ( ( T_2 ) F_66 ( V_12 -> V_30 -> V_161 ) << 24 ) ;
V_154 . V_162 = F_36 ( 0x7f000001 ) ;
V_154 . V_163 [ 0 ] = F_67 ( V_55 -> V_141 -> V_164 [ 1 ] ) ;
V_154 . V_163 [ 1 ] = F_67 ( V_55 -> V_141 -> V_164 [ 0 ] ) ;
V_155 = F_68 ( & V_154 ) ;
V_55 -> V_165 = F_36 ( V_155 ^ 0xffffffff ) ;
F_32 ( V_102 , L_6 ,
V_55 -> V_165 , V_55 -> V_165 & V_152 -> V_166 ) ;
V_55 -> V_165 &= V_152 -> V_166 ;
V_55 -> V_141 -> V_165 = F_9 ( V_55 -> V_165 ) ;
V_55 -> V_141 -> V_167 = F_9 ( 0x7f000001 ) ;
V_55 -> V_141 -> V_137 = F_9 ( V_55 -> V_96 ) ;
V_109 = & V_150 -> V_109 ;
F_40 ( V_109 , V_12 ) ;
F_41 ( V_109 -> V_37 ,
V_168 , V_169 |
V_170 | V_171 | V_172 ) ;
F_41 ( V_109 -> V_37 , V_173 , V_55 -> V_174 . V_46 ) ;
V_156 = ( V_42 ) V_55 -> V_175 ;
F_69 ( V_109 -> V_37 , V_176 , V_156 ) ;
F_32 ( V_102 , L_7 ) ;
V_150 -> V_53 = V_149 ;
V_150 -> V_129 = 1 ;
V_150 -> V_130 = F_63 ;
F_4 ( & V_150 -> V_131 , 1 ) ;
F_44 ( V_12 , V_150 ) ;
break;
case V_159 :
V_55 -> V_142 = V_143 ;
F_45 ( V_149 -> V_17 , V_149 -> V_55 ) ;
F_20 ( V_149 ) ;
break;
}
}
static int F_70 ( struct V_11 * V_12 ,
struct V_107 * V_17 , struct V_54 * V_55 )
{
struct V_49 * V_50 = NULL ;
struct V_148 * V_149 = NULL ;
V_42 V_156 ;
struct V_108 * V_109 ;
int V_177 = 0 ;
V_50 = F_33 ( V_12 ) ;
if ( V_50 == NULL ) {
F_32 ( V_102 , L_2 ) ;
V_177 = - V_103 ;
goto V_178;
}
V_149 = F_71 ( sizeof *V_149 , V_101 ) ;
if ( V_149 == NULL ) {
F_32 ( V_102 , L_2 ) ;
V_177 = - V_103 ;
goto V_178;
}
V_149 -> V_12 = V_12 ;
V_149 -> V_17 = V_17 ;
V_149 -> V_55 = V_55 ;
V_55 -> V_142 = V_158 ;
V_109 = & V_50 -> V_109 ;
F_40 ( V_109 , V_12 ) ;
F_41 ( V_109 -> V_37 ,
V_168 , V_169 | V_179 |
V_170 | V_171 | V_172 ) ;
F_41 ( V_109 -> V_37 , V_173 , V_55 -> V_174 . V_46 ) ;
V_156 = ( V_42 ) V_55 -> V_175 ;
F_69 ( V_109 -> V_37 , V_176 , V_156 ) ;
F_32 ( V_102 , L_8 ) ;
V_50 -> V_53 = V_149 ;
V_50 -> V_129 = 1 ;
V_50 -> V_130 = F_63 ;
F_4 ( & V_50 -> V_131 , 1 ) ;
F_44 ( V_12 , V_50 ) ;
return V_177 ;
V_178:
F_20 ( V_149 ) ;
if ( V_50 )
F_38 ( V_12 , V_50 ) ;
return V_177 ;
}
static void F_72 ( struct V_11 * V_12 , struct V_180 * V_181 )
{
struct V_1 * V_2 = F_73 ( V_181 , struct V_1 , V_182 ) ;
struct V_151 * V_152 = V_12 -> V_152 ;
T_2 V_183 ;
T_2 V_184 ;
T_2 V_185 = 0 ;
T_2 V_186 ;
T_2 V_46 = 0 ;
T_2 V_187 ;
unsigned long V_144 ;
struct V_54 * V_55 ;
struct V_5 * V_43 ;
struct V_13 * V_14 ;
V_183 = V_181 -> V_188 ;
V_184 = V_181 -> V_184 ;
while ( 1 ) {
V_186 = F_48 ( V_181 -> V_189 [ V_183 ] . V_190 [ V_191 ] ) ;
if ( ! ( V_186 & V_192 ) )
break;
V_55 = NULL ;
if ( V_186 & V_193 ) {
V_46 = F_48 ( V_181 -> V_189 [ V_183 ] . V_190 [ V_194 ] ) ;
V_46 &= 0x001fffff ;
if ( V_46 < V_152 -> V_195 ) {
V_144 = ( unsigned long ) V_152 -> V_196 [ V_46 - V_197 ] ;
V_55 = (struct V_54 * ) V_144 ;
}
}
if ( V_55 ) {
if ( V_55 -> V_198 == false ) {
V_55 -> V_198 = true ;
V_55 -> V_96 = F_48 (
V_181 -> V_189 [ V_183 ] . V_190 [ V_199 ] ) ;
F_74 ( & V_55 -> V_85 ) ;
F_75 ( & V_55 -> V_95 ) ;
F_62 ( & V_200 ) ;
F_70 ( V_12 , V_2 -> V_17 , V_55 ) ;
}
V_43 = V_2 -> V_16 . V_43 [ V_2 -> V_16 . V_201 ] ;
V_43 -> V_87 = 0 ;
F_76 ( V_43 , V_186 & 0x0000ffff ) ;
V_43 -> V_202 = F_77 ( V_43 , V_2 -> V_17 -> V_29 ) ;
V_14 = (struct V_13 * ) & V_43 -> V_14 [ 0 ] ;
F_15 ( V_12 -> V_30 , V_14 -> V_33 , V_14 -> V_34 , V_32 ) ;
V_14 -> V_33 = 0 ;
V_2 -> V_16 . V_201 ++ ;
V_2 -> V_16 . V_201 &= V_2 -> V_16 . V_20 - 1 ;
F_78 ( V_55 -> V_61 ) ;
F_58 ( V_43 , V_2 -> V_17 , V_55 ) ;
} else {
F_64 (KERN_ERR PFX L_9 , qp_id) ;
}
V_181 -> V_189 [ V_183 ] . V_190 [ V_191 ] = 0 ;
V_185 ++ ;
if ( ++ V_183 >= V_184 )
V_183 = 0 ;
if ( V_185 == 255 ) {
F_12 ( V_12 -> V_44 + V_203 , V_181 -> V_204 | ( V_185 << 16 ) ) ;
V_12 -> V_205 += V_185 ;
V_185 = 0 ;
}
V_187 = F_79 ( & V_2 -> V_21 ) ;
if ( V_187 > ( V_2 -> V_16 . V_20 >> 1 ) )
F_1 ( V_2 ) ;
}
V_181 -> V_188 = V_183 ;
F_12 ( V_12 -> V_44 + V_203 , V_206 |
V_181 -> V_204 | ( V_185 << 16 ) ) ;
F_80 ( V_12 -> V_44 + V_203 ) ;
V_12 -> V_205 += V_185 ;
}
int F_81 ( struct V_11 * V_12 , struct V_207 * V_29 , struct V_107 * V_17 )
{
struct V_1 * V_2 ;
T_2 V_208 ;
void * V_209 ;
T_1 V_210 ;
struct V_108 * V_109 ;
T_2 V_211 ;
unsigned long V_3 ;
struct V_212 * V_213 ;
V_42 V_156 ;
struct V_7 * V_214 ;
struct V_5 * V_6 ;
T_2 V_215 ;
struct V_13 * V_14 ;
T_2 V_216 ;
void * V_217 ;
T_1 V_218 ;
int V_56 ;
int V_177 ;
V_2 = F_31 ( V_219 * sizeof( struct V_1 ) , V_220 ) ;
if ( V_2 == NULL ) {
F_32 ( V_221 , L_10 ) ;
return - V_103 ;
}
V_216 = 256 +
( V_222 * sizeof( struct V_7 ) ) +
( V_222 * sizeof( struct V_223 ) ) +
sizeof( struct V_212 ) ;
V_216 = ( V_216 + V_224 - 1 ) & ~ ( V_224 - 1 ) ;
V_217 = F_34 ( V_12 -> V_30 , V_219 * V_216 , & V_218 ) ;
if ( ! V_217 ) {
F_20 ( V_2 ) ;
F_32 ( V_221 , L_11 ) ;
return - V_103 ;
}
V_17 -> V_216 = V_219 * V_216 ;
V_17 -> V_217 = V_217 ;
V_17 -> V_218 = V_218 ;
F_74 ( & V_17 -> V_146 ) ;
F_82 ( & V_17 -> V_145 ) ;
V_17 -> F_54 = F_83 ( F_54 , V_17 , L_12 ) ;
for ( V_56 = 0 ; V_56 < V_219 ; V_56 ++ ) {
V_2 -> V_17 = V_17 ;
V_2 -> V_16 . V_46 = V_12 -> V_225 + V_226 + V_56 ;
memset ( V_217 , 0 , V_216 ) ;
F_32 ( V_221 , L_13 ,
V_217 , ( unsigned long ) V_218 , V_216 ) ;
V_209 = ( void * ) ( ( ( unsigned long ) V_217 + ( 256 - 1 ) ) &
~ ( unsigned long ) ( 256 - 1 ) ) ;
V_210 = ( T_1 ) ( ( ( unsigned long long ) V_218 + ( 256 - 1 ) ) &
~ ( unsigned long long ) ( 256 - 1 ) ) ;
F_75 ( & V_2 -> V_16 . V_18 ) ;
V_2 -> V_16 . V_35 = V_209 ;
V_2 -> V_16 . V_227 = V_210 ;
V_2 -> V_16 . V_36 = 0 ;
V_2 -> V_16 . V_201 = 0 ;
V_2 -> V_16 . V_20 = V_222 ;
V_209 += ( V_222 * sizeof( struct V_7 ) ) ;
V_210 += ( V_222 * sizeof( struct V_7 ) ) ;
V_2 -> V_182 . V_204 = V_2 -> V_16 . V_46 ;
V_2 -> V_182 . V_189 = V_209 ;
V_2 -> V_182 . V_228 = V_210 ;
V_2 -> V_182 . V_188 = 0 ;
V_2 -> V_182 . V_184 = V_222 ;
V_2 -> V_182 . V_229 = F_72 ;
F_2 ( & V_12 -> V_230 . V_231 , V_3 ) ;
V_211 = V_12 -> V_230 . V_232 ;
V_109 = & V_12 -> V_230 . V_233 [ V_211 ] ;
F_40 ( V_109 , V_12 ) ;
V_109 -> V_37 [ V_168 ] = F_9 (
V_234 | V_235 |
( ( T_2 ) V_2 -> V_182 . V_184 << 16 ) ) ;
V_109 -> V_37 [ V_173 ] = F_9 (
V_2 -> V_182 . V_204 | ( ( T_2 ) V_12 -> V_236 << 16 ) ) ;
V_156 = ( V_42 ) V_2 -> V_182 . V_228 ;
F_69 ( V_109 -> V_37 , V_237 , V_156 ) ;
V_109 -> V_37 [ V_238 ] = 0 ;
V_156 = ( unsigned long ) & V_2 -> V_182 ;
V_109 -> V_37 [ V_239 ] = F_9 ( ( T_2 ) ( V_156 >> 1 ) ) ;
V_109 -> V_37 [ V_238 ] =
F_9 ( ( ( T_2 ) ( ( V_156 ) >> 33 ) ) & 0x7FFFFFFF ) ;
V_109 -> V_37 [ V_240 ] = 0 ;
if ( ++ V_211 >= V_12 -> V_230 . V_241 )
V_211 = 0 ;
V_109 = & V_12 -> V_230 . V_233 [ V_211 ] ;
F_40 ( V_109 , V_12 ) ;
V_213 = ( void * ) ( & V_2 -> V_182 . V_189 [ V_2 -> V_182 . V_184 ] ) ;
V_213 -> V_242 [ V_243 ] =
F_9 ( ( T_2 ) V_244 |
( ( T_2 ) F_66 ( V_12 -> V_30 -> V_161 ) << 12 ) ) ;
F_32 ( V_221 , L_14 ,
F_84 ( V_12 , V_245 ) ,
F_84 ( V_12 , V_246 ) ) ;
if ( F_84 ( V_12 , V_246 ) != 0 )
V_213 -> V_242 [ V_243 ] |= F_9 ( V_247 ) ;
V_156 = ( V_42 ) V_2 -> V_16 . V_227 ;
V_213 -> V_242 [ V_248 ] = F_9 ( ( T_2 ) V_156 ) ;
V_213 -> V_242 [ V_249 ] = F_9 ( ( T_2 ) ( V_156 >> 32 ) ) ;
V_156 = ( V_42 ) V_2 -> V_16 . V_227 ;
V_213 -> V_242 [ V_250 ] = F_9 ( ( T_2 ) V_156 ) ;
V_213 -> V_242 [ V_251 ] = F_9 ( ( T_2 ) ( V_156 >> 32 ) ) ;
V_109 -> V_37 [ V_168 ] = F_9 ( V_252 |
V_253 ) ;
V_109 -> V_37 [ V_173 ] = F_9 ( V_2 -> V_16 . V_46 ) ;
V_156 = ( V_42 ) V_2 -> V_182 . V_228 +
( V_2 -> V_182 . V_184 * sizeof( struct V_223 ) ) ;
F_69 ( V_109 -> V_37 , V_176 , V_156 ) ;
if ( ++ V_211 >= V_12 -> V_230 . V_241 )
V_211 = 0 ;
V_12 -> V_230 . V_232 = V_211 ;
F_11 () ;
F_12 ( V_12 -> V_44 + V_45 , 0x02800000 | V_12 -> V_230 . V_46 ) ;
F_5 ( & V_12 -> V_230 . V_231 , V_3 ) ;
F_32 ( V_221 , L_15 ,
V_2 -> V_16 . V_46 ) ;
V_177 = F_85 ( V_12 -> V_230 . V_254 , ( V_12 -> V_230 . V_255 == V_211 ) ,
V_256 ) ;
F_32 ( V_221 , L_16 ,
V_2 -> V_16 . V_46 , V_177 ) ;
if ( ! V_177 ) {
F_32 ( V_221 , L_17 , V_2 -> V_16 . V_46 ) ;
if ( V_56 == 0 ) {
F_19 ( V_12 -> V_30 , V_17 -> V_216 , V_17 -> V_217 ,
V_17 -> V_218 ) ;
F_20 ( V_2 ) ;
} else {
F_86 ( V_17 ) ;
}
return - V_257 ;
}
for ( V_208 = 0 ; V_208 < ( V_222 - 1 ) ; V_208 ++ ) {
V_6 = F_7 ( V_17 -> V_27 ) ;
if ( ! V_6 ) {
F_32 ( V_221 , L_18 , V_29 -> V_258 ) ;
return - V_103 ;
}
V_6 -> V_28 = V_29 ;
V_210 = F_8 ( V_12 -> V_30 , V_6 -> V_31 ,
V_17 -> V_27 , V_32 ) ;
V_14 = (struct V_13 * ) & V_6 -> V_14 [ 0 ] ;
V_14 -> V_33 = V_210 ;
V_14 -> V_34 = V_17 -> V_27 ;
V_214 = & V_2 -> V_16 . V_35 [ V_208 ] ;
V_214 -> V_37 [ V_38 ] = F_9 ( ( T_2 ) V_17 -> V_27 ) ;
V_214 -> V_37 [ V_39 ] = 0 ;
V_214 -> V_37 [ V_40 ] = F_9 ( ( T_2 ) V_210 ) ;
V_214 -> V_37 [ V_41 ] = F_9 ( ( T_2 ) ( ( V_42 ) V_210 >> 32 ) ) ;
V_2 -> V_16 . V_43 [ V_208 ] = V_6 ;
}
F_87 ( & V_2 -> V_23 ) ;
V_2 -> V_23 . V_259 = F_13 ;
V_2 -> V_23 . V_31 = ( unsigned long ) V_2 ;
V_215 = V_222 - 1 ;
V_2 -> V_16 . V_36 = V_215 ;
F_11 () ;
do {
V_208 = F_30 ( V_215 , ( ( T_2 ) 255 ) ) ;
V_215 -= V_208 ;
F_12 ( V_12 -> V_44 + V_45 , ( V_208 << 24 ) | V_2 -> V_16 . V_46 ) ;
} while ( V_215 );
F_12 ( V_12 -> V_44 + V_203 , V_206 |
V_2 -> V_182 . V_204 ) ;
F_80 ( V_12 -> V_44 + V_203 ) ;
V_217 += V_216 ;
V_218 += V_216 ;
V_17 -> V_2 [ V_56 ] = V_2 ++ ;
}
return 0 ;
}
void F_86 ( struct V_107 * V_17 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_1 * V_2 ;
struct V_1 * V_260 ;
unsigned long V_3 ;
struct V_108 * V_109 ;
T_2 V_211 ;
struct V_5 * V_43 ;
int V_56 ;
int V_177 ;
F_88 ( V_17 -> F_54 ) ;
V_260 = V_17 -> V_2 [ 0 ] ;
for ( V_56 = 0 ; V_56 < V_219 ; V_56 ++ ) {
V_2 = V_17 -> V_2 [ V_56 ] ;
if ( V_2 == NULL )
continue;
while ( V_2 -> V_16 . V_36 != V_2 -> V_16 . V_201 ) {
V_43 = V_2 -> V_16 . V_43 [ V_2 -> V_16 . V_201 ] ;
F_14 ( V_12 , V_43 , V_32 ) ;
V_2 -> V_16 . V_201 ++ ;
V_2 -> V_16 . V_201 &= ( V_2 -> V_16 . V_20 - 1 ) ;
}
F_2 ( & V_12 -> V_230 . V_231 , V_3 ) ;
V_211 = V_12 -> V_230 . V_232 ;
V_109 = & V_12 -> V_230 . V_233 [ V_211 ] ;
F_40 ( V_109 , V_12 ) ;
F_41 ( V_109 -> V_37 , V_168 ,
( V_261 | V_253 ) ) ;
F_41 ( V_109 -> V_37 , V_173 ,
V_2 -> V_16 . V_46 ) ;
if ( ++ V_211 >= V_12 -> V_230 . V_241 )
V_211 = 0 ;
V_109 = & V_12 -> V_230 . V_233 [ V_211 ] ;
F_40 ( V_109 , V_12 ) ;
F_41 ( V_109 -> V_37 , V_168 ,
( V_262 | ( ( T_2 ) V_2 -> V_182 . V_184 << 16 ) ) ) ;
F_41 ( V_109 -> V_37 , V_173 ,
( V_2 -> V_182 . V_204 | ( ( T_2 ) V_12 -> V_236 << 16 ) ) ) ;
if ( ++ V_211 >= V_12 -> V_230 . V_241 )
V_211 = 0 ;
V_12 -> V_230 . V_232 = V_211 ;
F_11 () ;
F_12 ( V_12 -> V_44 + V_45 , 0x02800000 | V_12 -> V_230 . V_46 ) ;
F_5 ( & V_12 -> V_230 . V_231 , V_3 ) ;
F_32 ( V_263 , L_19
L_20 ,
V_211 , V_12 -> V_230 . V_232 ,
V_12 -> V_230 . V_255 , V_12 -> V_230 . V_241 ) ;
V_177 = F_85 ( V_12 -> V_230 . V_254 , ( V_12 -> V_230 . V_255 == V_211 ) ,
V_256 ) ;
F_32 ( V_263 , L_21
L_22 ,
V_177 , V_211 , V_12 -> V_230 . V_232 , V_12 -> V_230 . V_255 ) ;
if ( ! V_177 )
F_32 ( V_263 , L_23 ,
V_2 -> V_16 . V_46 ) ;
V_17 -> V_2 [ V_56 ] = NULL ;
}
if ( V_17 -> V_217 ) {
F_19 ( V_12 -> V_30 , V_17 -> V_216 , V_17 -> V_217 ,
V_17 -> V_218 ) ;
V_17 -> V_217 = NULL ;
V_17 -> V_218 = 0 ;
}
F_20 ( V_260 ) ;
}
