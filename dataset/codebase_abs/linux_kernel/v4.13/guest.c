static void F_1 ( struct V_1 * V_2 ,
int V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 ;
if ( V_2 -> V_7 == NULL )
return;
F_2 (afu_dev, &afu->phb->bus->devices, bus_list) {
if ( ! V_6 -> V_8 )
continue;
switch ( V_3 ) {
case V_9 :
V_6 -> V_10 = V_4 ;
if ( V_6 -> V_8 -> V_11 &&
V_6 -> V_8 -> V_11 -> V_12 )
V_6 -> V_8 -> V_11 -> V_12 ( V_6 , V_4 ) ;
break;
case V_13 :
V_6 -> V_10 = V_4 ;
if ( V_6 -> V_8 -> V_11 &&
V_6 -> V_8 -> V_11 -> V_14 )
V_6 -> V_8 -> V_11 -> V_14 ( V_6 ) ;
break;
case V_15 :
if ( V_6 -> V_8 -> V_11 &&
V_6 -> V_8 -> V_11 -> V_16 )
V_6 -> V_8 -> V_11 -> V_16 ( V_6 ) ;
break;
}
}
}
static T_2 F_3 ( struct V_17 * V_18 , T_3 V_19 ,
T_3 V_20 )
{
F_4 ( L_1 , V_21 ) ;
F_5 ( & V_18 -> V_2 -> V_22 , L_2 , V_20 ) ;
return V_23 -> V_24 ( V_18 , 0 , V_20 ) ;
}
static T_4 F_6 ( struct V_25 * V_26 , struct V_1 * V_2 ,
void * V_27 , T_5 V_28 )
{
unsigned int V_29 , V_30 ;
unsigned long * * V_31 = NULL ;
struct V_32 * V_33 ;
int V_34 = 0 , V_35 , V_36 ;
T_3 V_37 = 0 ;
if ( V_27 == NULL )
return - V_38 ;
V_29 = V_28 / V_39 ;
V_30 = V_28 % V_39 ;
if ( V_30 )
V_29 ++ ;
if ( V_29 > V_40 ) {
V_29 = V_40 ;
V_28 = V_40 * V_39 ;
V_30 = 0 ;
}
V_31 = F_7 ( V_29 * sizeof( unsigned long * ) , V_41 ) ;
if ( ! V_31 )
return - V_42 ;
V_33 = (struct V_32 * ) F_8 ( V_41 ) ;
if ( ! V_33 ) {
V_34 = - V_42 ;
goto V_43;
}
for ( V_35 = 0 ; V_35 < V_29 ; V_35 ++ ) {
V_31 [ V_35 ] = ( unsigned long * ) F_8 ( V_41 ) ;
if ( ! V_31 [ V_35 ] ) {
V_34 = - V_42 ;
goto V_44;
}
V_33 [ V_35 ] . V_45 = F_9 ( F_10 ( V_31 [ V_35 ] ) ) ;
V_33 [ V_35 ] . V_28 = F_9 ( V_39 ) ;
if ( ( V_35 == ( V_29 - 1 ) ) && V_30 )
V_33 [ V_35 ] . V_28 = F_9 ( V_30 ) ;
}
if ( V_26 )
V_34 = F_11 ( V_26 -> V_46 -> V_47 ,
F_10 ( V_33 ) , V_29 , & V_37 ) ;
else
V_34 = F_12 ( V_2 -> V_46 -> V_47 , 0 ,
F_10 ( V_33 ) , V_29 , & V_37 ) ;
F_4 ( L_3 ,
V_29 , V_37 ) ;
if ( ! V_34 ) {
if ( V_37 < V_28 )
V_28 = V_37 ;
V_34 = V_28 ;
if ( V_37 ) {
for ( V_35 = 0 ; V_35 < V_29 ; V_35 ++ ) {
if ( V_28 < V_39 )
V_36 = V_28 ;
else
V_36 = V_39 ;
memcpy ( V_27 , V_31 [ V_35 ] , V_36 ) ;
V_27 += V_36 ;
V_28 -= V_36 ;
}
}
}
V_44:
for ( V_35 = 0 ; V_35 < V_29 ; V_35 ++ ) {
if ( V_31 [ V_35 ] )
F_13 ( ( unsigned long ) V_31 [ V_35 ] ) ;
}
F_13 ( ( unsigned long ) V_33 ) ;
V_43:
F_14 ( V_31 ) ;
return V_34 ;
}
static int F_15 ( struct V_17 * V_18 , struct V_48 * V_49 )
{
return F_16 ( V_18 -> V_2 -> V_46 -> V_47 , V_18 -> V_50 , V_49 ) ;
}
static T_2 F_17 ( int V_51 , void * V_52 )
{
struct V_17 * V_18 = V_52 ;
struct V_48 V_53 ;
int V_34 ;
F_4 ( L_4 , V_18 -> V_54 , V_51 ) ;
V_34 = F_15 ( V_18 , & V_53 ) ;
if ( V_34 ) {
F_18 ( 1 , L_5 , V_34 ) ;
return V_55 ;
}
V_34 = F_19 ( V_51 , V_18 , & V_53 ) ;
return V_34 ;
}
static int F_20 ( struct V_1 * V_2 , int * V_56 )
{
T_3 V_4 ;
int V_34 = 0 ;
if ( ! V_2 )
return - V_57 ;
V_34 = F_21 ( V_2 -> V_46 -> V_47 , & V_4 ) ;
if ( ! V_34 ) {
F_22 ( V_4 != V_58 &&
V_4 != V_59 &&
V_4 != V_60 &&
V_4 != V_61 ) ;
* V_56 = V_4 & 0xffffffff ;
}
return V_34 ;
}
static T_2 F_23 ( int V_51 , void * V_52 )
{
struct V_1 * V_2 = V_52 ;
int V_34 ;
T_3 V_62 , V_63 , V_19 ;
V_34 = F_24 ( V_2 -> V_46 -> V_47 , & V_62 ) ;
if ( V_34 ) {
F_5 ( & V_2 -> V_22 , L_6 , V_34 ) ;
return V_55 ;
}
V_63 = F_25 ( V_2 , V_64 ) ;
V_19 = F_25 ( V_2 , V_65 ) ;
F_26 ( V_2 , V_62 ) ;
F_5 ( & V_2 -> V_22 , L_7 , V_63 ) ;
F_5 ( & V_2 -> V_22 , L_8 , V_19 ) ;
V_34 = F_27 ( V_2 -> V_46 -> V_47 , V_62 ) ;
if ( V_34 )
F_5 ( & V_2 -> V_22 , L_9 ,
V_34 ) ;
return V_55 ;
}
static int F_28 ( struct V_25 * V_26 , int V_28 , int * V_51 )
{
int V_35 , V_66 ;
struct V_67 * V_68 ;
for ( V_35 = 0 ; V_35 < V_26 -> V_46 -> V_69 ; V_35 ++ ) {
V_68 = & V_26 -> V_46 -> V_67 [ V_35 ] ;
V_66 = F_29 ( V_68 -> V_70 , V_68 -> V_71 ,
0 , V_28 , 0 ) ;
if ( V_66 < V_68 -> V_71 ) {
F_30 ( V_68 -> V_70 , V_66 , V_28 ) ;
* V_51 = V_68 -> V_72 + V_66 ;
F_4 ( L_10 ,
* V_51 , * V_51 + V_28 - 1 ) ;
return 0 ;
}
}
return - V_73 ;
}
static int F_31 ( struct V_25 * V_26 , int V_51 , int V_28 )
{
int V_35 , V_66 ;
struct V_67 * V_68 ;
if ( V_28 == 0 )
return - V_74 ;
for ( V_35 = 0 ; V_35 < V_26 -> V_46 -> V_69 ; V_35 ++ ) {
V_68 = & V_26 -> V_46 -> V_67 [ V_35 ] ;
if ( V_51 >= V_68 -> V_72 &&
( V_51 + V_28 ) <= ( V_68 -> V_72 + V_68 -> V_71 ) ) {
V_66 = V_51 - V_68 -> V_72 ;
F_32 ( V_68 -> V_70 , V_66 , V_28 ) ;
F_4 ( L_11 ,
V_51 , V_51 + V_28 - 1 ) ;
return 0 ;
}
}
return - V_74 ;
}
static int F_33 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = NULL ;
int V_35 , V_34 ;
F_4 ( L_12 ) ;
for ( V_35 = 0 ; V_35 < V_26 -> V_75 ; V_35 ++ ) {
if ( ( V_2 = V_26 -> V_2 [ V_35 ] ) ) {
F_1 ( V_2 , V_9 ,
V_76 ) ;
F_34 ( V_2 ) ;
}
}
V_34 = F_35 ( V_26 -> V_46 -> V_47 ) ;
for ( V_35 = 0 ; V_35 < V_26 -> V_75 ; V_35 ++ ) {
if ( ! V_34 && ( V_2 = V_26 -> V_2 [ V_35 ] ) ) {
F_1 ( V_2 , V_13 ,
V_77 ) ;
F_1 ( V_2 , V_15 , 0 ) ;
}
}
return V_34 ;
}
static int F_36 ( struct V_25 * V_26 )
{
int V_51 ;
F_37 ( & V_26 -> V_46 -> V_78 ) ;
if ( F_28 ( V_26 , 1 , & V_51 ) )
V_51 = - V_73 ;
F_38 ( & V_26 -> V_46 -> V_78 ) ;
return V_51 ;
}
static void F_39 ( struct V_25 * V_26 , int V_51 )
{
F_37 ( & V_26 -> V_46 -> V_78 ) ;
F_31 ( V_26 , V_51 , 1 ) ;
F_38 ( & V_26 -> V_46 -> V_78 ) ;
}
static int F_40 ( struct V_79 * V_80 ,
struct V_25 * V_26 , unsigned int V_81 )
{
int V_35 , V_82 , V_51 ;
memset ( V_80 , 0 , sizeof( struct V_79 ) ) ;
F_37 ( & V_26 -> V_46 -> V_78 ) ;
for ( V_35 = 0 ; V_35 < V_83 && V_81 ; V_35 ++ ) {
V_82 = V_81 ;
while ( V_82 ) {
if ( F_28 ( V_26 , V_82 , & V_51 ) == 0 )
break;
V_82 /= 2 ;
}
if ( ! V_82 )
goto error;
V_80 -> V_72 [ V_35 ] = V_51 ;
V_80 -> V_71 [ V_35 ] = V_82 ;
V_81 -= V_82 ;
}
if ( V_81 )
goto error;
F_38 ( & V_26 -> V_46 -> V_78 ) ;
return 0 ;
error:
for ( V_35 = 0 ; V_35 < V_83 ; V_35 ++ )
F_31 ( V_26 , V_80 -> V_72 [ V_35 ] , V_80 -> V_71 [ V_35 ] ) ;
F_38 ( & V_26 -> V_46 -> V_78 ) ;
return - V_73 ;
}
static void F_41 ( struct V_79 * V_80 ,
struct V_25 * V_26 )
{
int V_35 ;
F_37 ( & V_26 -> V_46 -> V_78 ) ;
for ( V_35 = 0 ; V_35 < V_83 ; V_35 ++ )
F_31 ( V_26 , V_80 -> V_72 [ V_35 ] , V_80 -> V_71 [ V_35 ] ) ;
F_38 ( & V_26 -> V_46 -> V_78 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
V_2 -> V_84 = F_43 ( V_41 , L_13 ,
F_44 ( & V_2 -> V_22 ) ) ;
if ( ! V_2 -> V_84 )
return - V_42 ;
if ( ! ( V_2 -> V_85 = F_45 ( V_2 -> V_26 , V_2 -> V_86 ,
F_23 , V_2 , V_2 -> V_84 ) ) ) {
F_14 ( V_2 -> V_84 ) ;
V_2 -> V_84 = NULL ;
return - V_42 ;
}
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 -> V_85 , V_2 ) ;
V_23 -> V_87 ( V_2 -> V_26 , V_2 -> V_86 ) ;
F_14 ( V_2 -> V_84 ) ;
}
static int F_48 ( struct V_17 * V_18 , T_3 V_88 , T_3 V_89 )
{
return F_49 ( V_18 -> V_2 -> V_46 -> V_47 , V_18 -> V_50 ,
V_88 >> 32 , ( V_89 != 0 ) ) ;
}
static void F_50 ( struct V_17 * V_18 )
{
T_6 V_90 ;
unsigned int V_91 ;
int V_92 , V_35 ;
F_4 ( L_14 , V_18 -> V_2 -> V_93 ) ;
for ( V_92 = 0 ; V_92 < V_83 ; V_92 ++ ) {
V_90 = V_18 -> V_80 . V_72 [ V_92 ] ;
for ( V_35 = 0 ; V_35 < V_18 -> V_80 . V_71 [ V_92 ] ; V_90 ++ , V_35 ++ ) {
V_91 = F_51 ( NULL , V_90 ) ;
F_52 ( V_91 ) ;
}
}
}
static void F_53 ( struct V_17 * V_18 )
{
T_6 V_90 ;
unsigned int V_91 ;
int V_92 , V_35 ;
F_4 ( L_15 , V_18 -> V_2 -> V_93 ) ;
for ( V_92 = 0 ; V_92 < V_83 ; V_92 ++ ) {
V_90 = V_18 -> V_80 . V_72 [ V_92 ] ;
for ( V_35 = 0 ; V_35 < V_18 -> V_80 . V_71 [ V_92 ] ; V_90 ++ , V_35 ++ ) {
V_91 = F_51 ( NULL , V_90 ) ;
F_54 ( V_91 ) ;
}
}
}
static int F_55 ( int V_94 , struct V_1 * V_2 , int V_95 ,
T_3 V_72 , T_3 * V_96 )
{
unsigned long V_97 ;
char V_98 ;
int V_34 = 0 ;
if ( V_2 -> V_99 < V_94 )
return - V_74 ;
if ( F_56 ( V_72 >= V_2 -> V_99 ) )
return - V_100 ;
V_97 = F_8 ( V_41 ) ;
if ( ! V_97 )
return - V_42 ;
V_34 = F_57 ( V_2 -> V_46 -> V_47 , V_95 , V_72 ,
F_10 ( ( void * ) V_97 ) , V_94 ) ;
if ( V_34 )
goto V_101;
switch ( V_94 ) {
case 1 :
V_98 = * ( ( char * ) V_97 ) ;
* V_96 = V_98 ;
break;
case 2 :
* V_96 = F_58 ( ( V_102 * ) V_97 ) ;
break;
case 4 :
* V_96 = F_59 ( ( unsigned * ) V_97 ) ;
break;
case 8 :
* V_96 = F_60 ( ( T_3 * ) V_97 ) ;
break;
default:
F_22 ( 1 ) ;
}
V_101:
F_13 ( V_97 ) ;
return V_34 ;
}
static int F_61 ( struct V_1 * V_2 , int V_95 , T_3 V_72 ,
T_7 * V_37 )
{
int V_34 ;
T_3 V_96 ;
V_34 = F_55 ( 4 , V_2 , V_95 , V_72 , & V_96 ) ;
if ( ! V_34 )
* V_37 = ( T_7 ) V_96 ;
return V_34 ;
}
static int F_62 ( struct V_1 * V_2 , int V_95 , T_3 V_72 ,
V_102 * V_37 )
{
int V_34 ;
T_3 V_96 ;
V_34 = F_55 ( 2 , V_2 , V_95 , V_72 , & V_96 ) ;
if ( ! V_34 )
* V_37 = ( V_102 ) V_96 ;
return V_34 ;
}
static int F_63 ( struct V_1 * V_2 , int V_95 , T_3 V_72 ,
T_8 * V_37 )
{
int V_34 ;
T_3 V_96 ;
V_34 = F_55 ( 1 , V_2 , V_95 , V_72 , & V_96 ) ;
if ( ! V_34 )
* V_37 = ( T_8 ) V_96 ;
return V_34 ;
}
static int F_64 ( struct V_1 * V_2 , int V_95 , T_3 V_72 ,
T_3 * V_37 )
{
return F_55 ( 8 , V_2 , V_95 , V_72 , V_37 ) ;
}
static int F_65 ( struct V_1 * V_2 , int V_97 , T_3 V_103 , T_7 V_104 )
{
return - V_105 ;
}
static int F_66 ( struct V_1 * V_2 , int V_97 , T_3 V_103 , V_102 V_104 )
{
return - V_105 ;
}
static int F_67 ( struct V_1 * V_2 , int V_97 , T_3 V_103 , T_8 V_104 )
{
return - V_105 ;
}
static int F_68 ( struct V_17 * V_18 , T_3 V_106 , T_3 V_107 )
{
struct V_108 * V_109 ;
struct V_25 * V_26 = V_18 -> V_2 -> V_26 ;
const struct V_110 * V_110 ;
T_7 V_111 , V_112 ;
int V_34 , V_92 , V_35 ;
T_3 V_113 , V_114 ;
T_9 V_115 = 0 ;
if ( ! ( V_109 = (struct V_108 * )
F_8 ( V_41 ) ) )
return - V_42 ;
V_109 -> V_116 = F_9 ( V_117 ) ;
if ( V_18 -> V_118 ) {
V_111 = 0 ;
V_115 |= V_119 ;
V_115 |= V_120 ;
if ( F_69 () & V_121 )
V_115 |= V_122 ;
} else {
V_111 = V_123 -> V_111 ;
V_115 |= V_124 ;
V_115 |= V_119 ;
if ( ! F_70 ( V_123 , V_125 ) )
V_115 |= V_122 ;
V_110 = F_71 () ;
if ( F_72 ( V_110 -> V_126 , V_127 ) )
V_115 |= V_120 ;
F_73 ( V_110 ) ;
}
V_109 -> V_115 = F_9 ( V_115 ) ;
V_109 -> V_128 . V_129 = F_74 ( 0 ) ;
V_109 -> V_128 . V_111 = F_74 ( V_111 ) ;
V_109 -> V_128 . V_130 = F_9 ( 0 ) ;
V_109 -> V_128 . V_131 . V_132 . V_133 = F_9 ( 0 ) ;
V_109 -> V_128 . V_131 . V_132 . V_134 = F_9 ( 0 ) ;
F_75 ( V_18 , V_106 ) ;
V_109 -> V_128 . V_131 . V_132 . V_135 = F_9 ( V_18 -> V_135 ) ;
V_109 -> V_128 . V_131 . V_132 . V_136 = F_9 ( V_18 -> V_136 ) ;
if ( V_18 -> V_80 . V_71 [ 0 ] == 0 ) {
V_34 = F_76 ( V_18 , 0 ) ;
if ( V_34 )
goto V_137;
}
for ( V_92 = 0 ; V_92 < V_83 ; V_92 ++ ) {
for ( V_35 = 0 ; V_35 < V_18 -> V_80 . V_71 [ V_92 ] ; V_35 ++ ) {
if ( V_92 == 0 && V_35 == 0 ) {
V_109 -> V_138 = F_74 ( V_18 -> V_80 . V_72 [ 0 ] ) ;
} else {
V_112 = V_18 -> V_80 . V_72 [ V_92 ] + V_35 - V_26 -> V_46 -> V_139 ;
V_109 -> V_140 [ V_112 / 8 ] |= 0x80 >> ( V_112 % 8 ) ;
}
}
}
V_109 -> V_128 . V_107 = F_9 ( V_107 ) ;
V_109 -> V_128 . V_106 = F_9 ( V_106 ) ;
F_50 ( V_18 ) ;
V_34 = F_77 ( V_18 -> V_2 -> V_46 -> V_47 , V_109 ,
& V_18 -> V_50 , & V_113 , & V_114 ) ;
if ( V_34 == V_141 ) {
if ( V_18 -> V_142 || ! V_18 -> V_2 -> V_143 ) {
V_18 -> V_144 = V_18 -> V_2 -> V_144 ;
V_18 -> V_145 = V_18 -> V_2 -> V_26 -> V_146 ;
} else {
V_18 -> V_144 = V_113 ;
V_18 -> V_145 = V_114 ;
}
if ( V_18 -> V_2 -> V_143 && V_114 &&
V_18 -> V_2 -> V_147 == 0 ) {
V_18 -> V_2 -> V_147 = V_114 ;
}
V_18 -> V_148 = V_18 -> V_50 & 0xFFFFFFFF ;
F_4 ( L_16 ,
V_18 -> V_54 , V_18 -> V_148 , V_18 -> V_145 ) ;
V_18 -> V_149 = true ;
F_53 ( V_18 ) ;
}
V_137:
F_13 ( ( T_3 ) V_109 ) ;
return V_34 ;
}
static int F_78 ( struct V_17 * V_18 , bool V_118 , T_3 V_106 , T_3 V_107 )
{
F_4 ( L_1 , V_21 ) ;
if ( V_18 -> V_150 )
return - V_105 ;
V_18 -> V_118 = V_118 ;
if ( V_18 -> V_2 -> V_151 == V_152 )
return F_68 ( V_18 , V_106 , V_107 ) ;
return - V_38 ;
}
static int F_79 ( struct V_17 * V_18 )
{
if ( ! V_18 -> V_149 )
return 0 ;
if ( F_80 ( V_18 -> V_2 -> V_46 -> V_47 , V_18 -> V_50 ) )
return - 1 ;
return 0 ;
}
static int F_81 ( struct V_17 * V_18 )
{
F_4 ( L_1 , V_21 ) ;
F_82 ( V_18 ) ;
if ( ! V_23 -> V_153 ( V_18 -> V_2 -> V_26 , V_18 -> V_2 ) )
return - V_57 ;
if ( V_18 -> V_2 -> V_151 == V_152 )
return F_79 ( V_18 ) ;
return - V_38 ;
}
static void F_83 ( struct V_154 * V_22 )
{
struct V_1 * V_2 = F_84 ( V_22 ) ;
F_4 ( L_17 , V_21 ) ;
F_85 ( & V_2 -> V_155 ) ;
F_14 ( V_2 -> V_46 ) ;
F_14 ( V_2 ) ;
}
T_4 F_86 ( struct V_1 * V_2 , void * V_27 , T_5 V_28 )
{
return F_6 ( NULL , V_2 , V_27 , V_28 ) ;
}
static T_4 F_87 ( struct V_1 * V_2 , char * V_27 ,
T_10 V_103 , T_5 V_156 )
{
void * V_157 = NULL ;
int V_34 = 0 ;
V_157 = ( void * ) F_8 ( V_41 ) ;
if ( ! V_157 )
return - V_42 ;
V_34 = F_88 ( V_2 -> V_46 -> V_47 ,
V_103 & 0x7 ,
F_10 ( V_157 ) ,
V_156 ) ;
if ( V_34 )
goto V_101;
if ( V_156 > V_158 )
V_156 = V_158 - ( V_103 & 0x7 ) ;
memcpy ( V_27 , V_157 , V_156 ) ;
V_101:
F_13 ( ( T_3 ) V_157 ) ;
return V_34 ;
}
static int F_89 ( struct V_1 * V_2 )
{
return 0 ;
}
static bool F_90 ( const char * V_159 ,
enum V_160 type )
{
switch ( type ) {
case V_161 :
if ( ( strcmp ( V_159 , L_18 ) == 0 ) ||
( strcmp ( V_159 , L_19 ) == 0 ) ||
( strcmp ( V_159 , L_20 ) == 0 ) ||
( strcmp ( V_159 , L_21 ) == 0 ) )
return false ;
break;
case V_162 :
if ( ( strcmp ( V_159 , L_22 ) == 0 ) )
return false ;
break;
case V_163 :
break;
default:
break;
}
return true ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_34 ;
F_92 ( & V_2 -> V_22 , L_23 , V_2 -> V_93 ) ;
V_2 -> V_151 = V_152 ;
V_2 -> V_164 = V_2 -> V_165 ;
if ( ( V_34 = F_93 ( V_2 ) ) )
return V_34 ;
if ( ( V_34 = F_94 ( V_2 ) ) )
goto V_101;
if ( ( V_34 = F_95 ( V_2 ) ) )
goto V_43;
return 0 ;
V_43:
F_96 ( V_2 ) ;
V_101:
F_97 ( V_2 ) ;
return V_34 ;
}
static int F_98 ( struct V_1 * V_2 , int V_166 )
{
if ( ! V_166 )
return 0 ;
if ( ! ( V_166 & V_2 -> V_167 ) )
return - V_38 ;
if ( V_166 == V_152 )
return F_91 ( V_2 ) ;
if ( V_166 == V_168 )
F_99 ( & V_2 -> V_22 , L_24 ) ;
return - V_38 ;
}
static int F_100 ( struct V_1 * V_2 )
{
F_92 ( & V_2 -> V_22 , L_25 , V_2 -> V_93 ) ;
V_2 -> V_151 = 0 ;
V_2 -> V_164 = 0 ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
V_23 -> V_169 ( V_2 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 , int V_166 )
{
if ( ! V_166 )
return 0 ;
if ( ! ( V_166 & V_2 -> V_167 ) )
return - V_38 ;
if ( V_166 == V_152 )
return F_100 ( V_2 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
F_4 ( L_26 , V_2 -> V_93 ) ;
return F_103 ( V_2 -> V_46 -> V_47 ) ;
}
static int F_104 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_170 = F_105 ( V_2 -> V_46 -> V_171 , V_2 -> V_46 -> V_172 ) ) ) {
F_99 ( & V_2 -> V_22 , L_27 ,
V_2 -> V_93 ) ;
return - V_42 ;
}
return 0 ;
}
static void F_106 ( struct V_1 * V_2 )
{
if ( V_2 -> V_170 )
F_107 ( V_2 -> V_170 ) ;
}
static int F_108 ( struct V_1 * V_2 )
{
int V_34 , V_173 ;
V_34 = F_20 ( V_2 , & V_173 ) ;
if ( V_34 )
return V_34 ;
if ( V_2 -> V_46 -> V_174 == V_173 )
return 0 ;
F_4 ( L_28 , V_2 -> V_93 , V_173 ) ;
switch ( V_173 ) {
case V_58 :
V_2 -> V_46 -> V_174 = V_173 ;
break;
case V_59 :
F_1 ( V_2 , V_9 ,
V_76 ) ;
F_34 ( V_2 ) ;
if ( ( V_34 = V_23 -> V_169 ( V_2 ) ) )
F_4 ( L_29 , V_34 ) ;
V_34 = F_20 ( V_2 , & V_173 ) ;
if ( ! V_34 && V_173 == V_58 ) {
F_1 ( V_2 , V_13 ,
V_77 ) ;
F_1 ( V_2 , V_15 , 0 ) ;
}
V_2 -> V_46 -> V_174 = 0 ;
break;
case V_60 :
V_2 -> V_46 -> V_174 = V_173 ;
break;
case V_61 :
F_99 ( & V_2 -> V_22 , L_30 ) ;
F_1 ( V_2 , V_9 ,
V_175 ) ;
V_2 -> V_46 -> V_174 = V_173 ;
break;
default:
F_109 ( L_31 ,
V_2 -> V_93 , V_173 ) ;
return - V_38 ;
}
return V_34 ;
}
static void F_110 ( struct V_176 * V_177 )
{
struct V_178 * V_179 =
F_111 ( F_112 ( V_177 ) , struct V_178 , V_180 ) ;
if ( ! F_108 ( V_179 -> V_181 ) &&
V_179 -> V_174 == V_61 )
return;
if ( V_179 -> V_182 )
F_113 ( & V_179 -> V_180 ,
F_114 ( 3000 ) ) ;
}
static bool F_115 ( struct V_25 * V_25 , struct V_1 * V_2 )
{
int V_4 ;
if ( V_2 && ( ! F_20 ( V_2 , & V_4 ) ) ) {
if ( V_4 == V_58 )
return true ;
}
return false ;
}
static int F_116 ( struct V_1 * V_2 )
{
if ( V_2 -> V_183 < 0 ) {
F_99 ( & V_2 -> V_22 , L_32 ) ;
return - V_38 ;
}
if ( V_2 -> V_165 < 1 ) {
F_99 ( & V_2 -> V_22 , L_33 ) ;
return - V_38 ;
}
if ( V_2 -> V_99 < 0 ) {
F_99 ( & V_2 -> V_22 , L_34 ) ;
return - V_38 ;
}
return 0 ;
}
int F_117 ( struct V_25 * V_26 , int V_93 , struct V_184 * V_185 )
{
struct V_1 * V_2 ;
bool free = true ;
int V_34 ;
F_4 ( L_35 , V_21 , V_93 ) ;
if ( ! ( V_2 = F_118 ( V_26 , V_93 ) ) )
return - V_42 ;
if ( ! ( V_2 -> V_46 = F_7 ( sizeof( struct V_178 ) , V_41 ) ) ) {
F_14 ( V_2 ) ;
return - V_42 ;
}
if ( ( V_34 = F_119 ( & V_2 -> V_22 , L_36 ,
V_26 -> V_186 ,
V_93 ) ) )
goto V_43;
V_26 -> V_75 ++ ;
if ( ( V_34 = F_120 ( V_2 , V_185 ) ) )
goto V_43;
if ( ( V_34 = V_23 -> V_169 ( V_2 ) ) )
goto V_43;
if ( ( V_34 = F_121 ( V_2 , V_185 ) ) )
goto V_43;
if ( ( V_34 = F_116 ( V_2 ) ) )
goto V_43;
if ( ( V_34 = F_104 ( V_2 ) ) )
goto V_43;
if ( ( V_34 = F_42 ( V_2 ) ) )
goto V_44;
if ( ( V_34 = F_122 ( V_2 ) ) )
goto V_187;
if ( ( V_34 = F_123 ( V_2 ) ) )
goto V_187;
if ( V_2 -> V_165 == 1 )
V_2 -> V_167 = V_168 ;
else
V_2 -> V_167 = V_152 ;
if ( ( V_34 = F_124 ( V_2 ) ) )
goto V_188;
V_26 -> V_2 [ V_2 -> V_93 ] = V_2 ;
V_2 -> V_189 = true ;
V_2 -> V_46 -> V_181 = V_2 ;
V_2 -> V_46 -> V_182 = true ;
F_125 ( & V_2 -> V_46 -> V_180 , F_110 ) ;
F_113 ( & V_2 -> V_46 -> V_180 , F_114 ( 1000 ) ) ;
if ( ( V_34 = F_126 ( V_2 ) ) )
F_92 ( & V_2 -> V_22 , L_37 ) ;
return 0 ;
V_188:
F_127 ( V_2 ) ;
V_187:
F_128 ( & V_2 -> V_22 ) ;
free = false ;
F_46 ( V_2 ) ;
V_44:
F_106 ( V_2 ) ;
V_43:
if ( free ) {
F_14 ( V_2 -> V_46 ) ;
F_14 ( V_2 ) ;
}
return V_34 ;
}
void F_129 ( struct V_1 * V_2 )
{
F_4 ( L_35 , V_21 , V_2 -> V_93 ) ;
if ( ! V_2 )
return;
V_2 -> V_46 -> V_182 = false ;
F_130 ( & V_2 -> V_46 -> V_180 ) ;
F_131 ( V_2 ) ;
F_127 ( V_2 ) ;
F_37 ( & V_2 -> V_26 -> V_190 ) ;
V_2 -> V_26 -> V_2 [ V_2 -> V_93 ] = NULL ;
F_38 ( & V_2 -> V_26 -> V_190 ) ;
F_34 ( V_2 ) ;
V_23 -> V_191 ( V_2 , V_2 -> V_151 ) ;
F_46 ( V_2 ) ;
F_106 ( V_2 ) ;
F_128 ( & V_2 -> V_22 ) ;
}
static void F_132 ( struct V_25 * V_26 )
{
struct V_67 * V_68 ;
int V_35 ;
if ( V_26 -> V_46 ) {
if ( V_26 -> V_46 -> V_67 ) {
for ( V_35 = 0 ; V_35 < V_26 -> V_46 -> V_69 ; V_35 ++ ) {
V_68 = & V_26 -> V_46 -> V_67 [ V_35 ] ;
F_14 ( V_68 -> V_70 ) ;
}
F_14 ( V_26 -> V_46 -> V_67 ) ;
}
F_14 ( V_26 -> V_46 -> V_192 ) ;
F_14 ( V_26 -> V_46 ) ;
}
F_133 ( V_26 ) ;
F_14 ( V_26 ) ;
}
static int F_134 ( struct V_25 * V_26 )
{
if ( strlen ( V_26 -> V_46 -> V_192 ) &&
strcmp ( V_26 -> V_46 -> V_192 , L_38 ) ) {
F_109 ( L_39 ) ;
return - V_38 ;
}
return 0 ;
}
T_4 F_135 ( struct V_25 * V_26 , void * V_27 , T_5 V_28 )
{
return F_6 ( V_26 , NULL , V_27 , V_28 ) ;
}
void F_136 ( struct V_25 * V_26 )
{
F_4 ( L_1 , V_21 ) ;
F_137 ( V_26 ) ;
F_138 ( V_26 ) ;
F_128 ( & V_26 -> V_22 ) ;
}
static void F_139 ( struct V_154 * V_22 )
{
F_132 ( F_140 ( V_22 ) ) ;
}
struct V_25 * F_141 ( struct V_184 * V_193 , struct V_194 * V_195 )
{
struct V_25 * V_26 ;
bool free = true ;
int V_34 ;
if ( ! ( V_26 = F_142 () ) )
return F_143 ( - V_42 ) ;
if ( ! ( V_26 -> V_46 = F_7 ( sizeof( struct V_196 ) , V_41 ) ) ) {
F_132 ( V_26 ) ;
return F_143 ( - V_42 ) ;
}
V_26 -> V_75 = 0 ;
V_26 -> V_46 -> V_195 = V_195 ;
V_26 -> V_22 . V_181 = & V_195 -> V_22 ;
V_26 -> V_22 . V_197 = F_139 ;
F_144 ( & V_195 -> V_22 , V_26 ) ;
V_26 -> V_198 = true ;
if ( ( V_34 = F_145 ( V_26 , V_193 ) ) )
goto V_43;
if ( ( V_34 = F_146 ( V_26 , V_193 ) ) )
goto V_43;
if ( ( V_34 = F_134 ( V_26 ) ) )
goto V_43;
if ( ( V_34 = F_147 ( V_26 ) ) )
goto V_43;
if ( ( V_34 = F_148 ( V_26 ) ) )
goto V_187;
if ( ( V_34 = F_149 ( V_26 ) ) )
goto V_187;
F_150 ( V_26 ) ;
return V_26 ;
V_187:
F_128 ( & V_26 -> V_22 ) ;
free = false ;
F_138 ( V_26 ) ;
V_43:
if ( free )
F_132 ( V_26 ) ;
return F_143 ( V_34 ) ;
}
void F_151 ( struct V_25 * V_26 )
{
struct V_194 * V_195 ;
V_195 = V_26 -> V_46 -> V_195 ;
F_136 ( V_26 ) ;
F_152 ( V_195 ) ;
}
