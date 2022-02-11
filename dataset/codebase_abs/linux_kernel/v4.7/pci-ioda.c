void F_1 ( const struct V_1 * V_2 , const char * V_3 ,
const char * V_4 , ... )
{
struct V_5 V_6 ;
T_1 args ;
char V_7 [ 32 ] ;
va_start ( args , V_4 ) ;
V_6 . V_4 = V_4 ;
V_6 . V_8 = & args ;
if ( V_2 -> V_9 & V_10 )
F_2 ( V_7 , F_3 ( & V_2 -> V_11 -> V_12 ) , sizeof( V_7 ) ) ;
else if ( V_2 -> V_9 & ( V_13 | V_14 ) )
sprintf ( V_7 , L_1 ,
F_4 ( V_2 -> V_15 ) , V_2 -> V_15 -> V_16 ) ;
#ifdef F_5
else if ( V_2 -> V_9 & V_17 )
sprintf ( V_7 , L_2 ,
F_4 ( V_2 -> V_18 -> V_19 ) ,
( V_2 -> V_20 & 0xff00 ) >> 8 ,
F_6 ( V_2 -> V_20 ) , F_7 ( V_2 -> V_20 ) ) ;
#endif
F_8 ( L_3 ,
V_3 , V_7 , V_2 -> V_21 , & V_6 ) ;
va_end ( args ) ;
}
static int T_2 F_9 ( char * V_22 )
{
if ( ! V_22 )
return - V_23 ;
while ( * V_22 ) {
if ( ! strncmp ( V_22 , L_4 , 8 ) ) {
V_24 = true ;
F_10 ( L_5 ) ;
break;
}
V_22 += strcspn ( V_22 , L_6 ) ;
if ( * V_22 == ',' )
V_22 ++ ;
}
return 0 ;
}
static inline bool F_11 ( unsigned long V_9 )
{
return ( ( V_9 & ( V_25 | V_26 ) ) ==
( V_25 | V_26 ) ) ;
}
static struct V_1 * F_12 ( struct V_27 * V_28 , int V_29 )
{
V_28 -> V_30 . V_31 [ V_29 ] . V_28 = V_28 ;
V_28 -> V_30 . V_31 [ V_29 ] . V_21 = V_29 ;
return & V_28 -> V_30 . V_31 [ V_29 ] ;
}
static void F_13 ( struct V_27 * V_28 , int V_29 )
{
if ( ! ( V_29 >= 0 && V_29 < V_28 -> V_30 . V_32 ) ) {
F_14 ( L_7 ,
V_33 , V_29 , V_28 -> V_34 -> V_35 ) ;
return;
}
if ( F_15 ( V_29 , V_28 -> V_30 . V_36 ) )
F_16 ( L_8 ,
V_33 , V_29 , V_28 -> V_34 -> V_35 ) ;
F_12 ( V_28 , V_29 ) ;
}
static struct V_1 * F_17 ( struct V_27 * V_28 )
{
unsigned long V_2 ;
do {
V_2 = F_18 ( V_28 -> V_30 . V_36 ,
V_28 -> V_30 . V_32 , 0 ) ;
if ( V_2 >= V_28 -> V_30 . V_32 )
return NULL ;
} while( F_15 ( V_2 , V_28 -> V_30 . V_36 ) );
return F_12 ( V_28 , V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
F_20 ( V_2 -> V_11 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_21 ( V_2 -> V_21 , V_28 -> V_30 . V_36 ) ;
}
static int F_22 ( struct V_27 * V_28 )
{
const char * V_37 ;
struct V_38 * V_39 ;
T_3 V_40 ;
V_40 = F_23 ( V_28 -> V_41 ,
V_42 ,
V_28 -> V_30 . V_43 ,
V_28 -> V_30 . V_44 ,
0 ,
V_28 -> V_30 . V_45 ) ;
if ( V_40 != V_46 ) {
V_37 = L_9 ;
goto V_47;
}
V_40 = F_24 ( V_28 -> V_41 ,
V_42 ,
V_28 -> V_30 . V_43 ,
V_48 ) ;
if ( V_40 != V_46 ) {
V_37 = L_10 ;
goto V_47;
}
F_25 ( V_28 -> V_30 . V_43 , & V_28 -> V_30 . V_49 ) ;
V_39 = & V_28 -> V_34 -> V_50 [ 1 ] ;
if ( V_28 -> V_30 . V_51 == 0 )
V_39 -> V_52 += V_28 -> V_30 . V_53 ;
else if ( V_28 -> V_30 . V_51 == ( V_28 -> V_30 . V_32 - 1 ) )
V_39 -> V_54 -= V_28 -> V_30 . V_53 ;
else
F_14 ( L_11 ,
V_28 -> V_30 . V_51 ) ;
return 0 ;
V_47:
F_14 ( L_12 ,
V_40 , V_37 , V_28 -> V_30 . V_43 ) ;
F_24 ( V_28 -> V_41 ,
V_42 ,
V_28 -> V_30 . V_43 ,
V_55 ) ;
return - V_56 ;
}
static void F_26 ( struct V_57 * V_11 ,
unsigned long * V_58 )
{
struct V_59 * V_34 = F_27 ( V_11 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
struct V_38 * V_39 ;
T_4 V_61 , V_62 , V_52 , V_54 ;
int V_63 , V_64 ;
V_61 = V_28 -> V_30 . V_44 ;
V_62 = V_28 -> V_30 . V_53 ;
for ( V_64 = 0 ; V_64 <= V_65 ; V_64 ++ ) {
V_39 = & V_11 -> V_38 [ V_64 ] ;
if ( ! V_39 -> V_66 || ! F_11 ( V_39 -> V_9 ) )
continue;
V_52 = F_28 ( V_39 -> V_52 - V_61 , V_62 ) ;
V_54 = F_29 ( V_39 -> V_54 - V_61 , V_62 ) ;
for ( V_63 = V_52 / V_62 ; V_63 < V_54 / V_62 ; V_63 ++ ) {
if ( V_58 )
F_25 ( V_63 , V_58 ) ;
else
F_13 ( V_28 , V_63 ) ;
}
}
}
static int F_30 ( struct V_27 * V_28 )
{
struct V_38 * V_39 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
unsigned long V_61 , V_69 = V_28 -> V_30 . V_53 ;
T_5 V_40 ;
V_61 = V_28 -> V_30 . V_44 +
V_67 * V_70 * V_69 ;
V_40 = F_23 ( V_28 -> V_41 ,
V_42 , V_67 , V_61 , 0 ,
V_70 * V_69 ) ;
if ( V_40 != V_46 ) {
F_14 ( L_13 ,
V_40 , V_28 -> V_34 -> V_35 , V_67 ) ;
goto V_47;
}
V_40 = F_24 ( V_28 -> V_41 ,
V_42 , V_67 ,
V_48 ) ;
if ( V_40 != V_46 ) {
F_14 ( L_14 ,
V_40 , V_28 -> V_34 -> V_35 , V_67 ) ;
goto V_47;
}
}
V_39 = & V_28 -> V_34 -> V_50 [ 1 ] ;
if ( V_28 -> V_30 . V_51 == 0 )
V_39 -> V_52 += V_28 -> V_30 . V_53 ;
else if ( V_28 -> V_30 . V_51 == ( V_28 -> V_30 . V_32 - 1 ) )
V_39 -> V_54 -= V_28 -> V_30 . V_53 ;
else
F_31 ( 1 , L_15 ,
V_28 -> V_30 . V_51 , V_28 -> V_34 -> V_35 ) ;
return 0 ;
V_47:
for ( ; V_67 >= 0 ; V_67 -- )
F_24 ( V_28 -> V_41 ,
V_42 , V_67 , V_55 ) ;
return - V_56 ;
}
static void F_32 ( struct V_71 * V_19 ,
unsigned long * V_58 ,
bool V_72 )
{
struct V_57 * V_11 ;
F_33 (pdev, &bus->devices, bus_list) {
F_26 ( V_11 , V_58 ) ;
if ( V_72 && V_11 -> V_73 )
F_32 ( V_11 -> V_73 ,
V_58 , V_72 ) ;
}
}
static struct V_1 * F_34 ( struct V_71 * V_19 , bool V_72 )
{
struct V_59 * V_34 = F_27 ( V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
struct V_1 * V_74 , * V_2 ;
unsigned long V_75 , * V_36 ;
int V_64 ;
if ( F_35 ( V_19 ) )
return NULL ;
V_75 = F_29 ( V_28 -> V_30 . V_32 / 8 , sizeof( unsigned long ) ) ;
V_36 = F_36 ( V_75 , V_76 ) ;
if ( ! V_36 ) {
F_14 ( L_16 ,
V_33 ) ;
return NULL ;
}
F_32 ( V_19 , V_36 , V_72 ) ;
if ( F_37 ( V_36 , V_28 -> V_30 . V_32 ) ) {
F_38 ( V_36 ) ;
return NULL ;
}
V_74 = NULL ;
V_64 = - 1 ;
while ( ( V_64 = F_39 ( V_36 , V_28 -> V_30 . V_32 , V_64 + 1 ) ) <
V_28 -> V_30 . V_32 ) {
V_2 = & V_28 -> V_30 . V_31 [ V_64 ] ;
V_28 -> V_30 . V_77 [ V_2 -> V_21 ] = V_2 -> V_21 ;
if ( ! V_74 ) {
V_2 -> V_9 |= V_78 ;
F_40 ( & V_2 -> V_79 ) ;
V_74 = V_2 ;
} else {
V_2 -> V_9 |= V_80 ;
V_2 -> V_81 = V_74 ;
F_41 ( & V_2 -> V_82 , & V_74 -> V_79 ) ;
}
if ( V_28 -> type == V_83 ) {
T_5 V_40 ;
V_40 = F_42 ( V_28 -> V_41 ,
V_2 -> V_21 , V_42 ,
V_2 -> V_21 / V_70 ,
V_2 -> V_21 % V_70 ) ;
if ( V_40 != V_46 )
F_14 ( L_17 ,
V_33 , V_40 , V_28 -> V_34 -> V_35 ,
V_2 -> V_21 ) ;
}
}
F_38 ( V_36 ) ;
return V_74 ;
}
static void T_2 F_43 ( struct V_27 * V_28 )
{
struct V_59 * V_34 = V_28 -> V_34 ;
struct V_84 * V_85 = V_34 -> V_85 ;
struct V_38 * V_86 ;
const T_6 * V_39 ;
T_7 V_87 ;
if ( V_28 -> type != V_83 && V_28 -> type != V_88 ) {
F_10 ( L_18 ) ;
return;
}
if ( ! F_44 ( V_89 ) ) {
F_10 ( L_19 ) ;
return;
}
V_39 = F_45 ( V_85 , L_20 , NULL ) ;
if ( ! V_39 ) {
F_10 ( L_21 ,
V_85 -> V_90 ) ;
return;
}
V_86 = & V_34 -> V_50 [ 1 ] ;
V_86 -> V_91 = V_85 -> V_90 ;
V_86 -> V_52 = F_46 ( V_85 , V_39 + 2 ) ;
V_86 -> V_54 = V_86 -> V_52 + F_47 ( V_39 + 4 , 2 ) - 1 ;
V_86 -> V_9 = ( V_92 | V_25 | V_26 ) ;
V_87 = F_47 ( V_39 , 2 ) ;
V_34 -> V_93 [ 1 ] = V_86 -> V_52 - V_87 ;
V_28 -> V_30 . V_45 = F_48 ( V_86 ) ;
V_28 -> V_30 . V_53 = V_28 -> V_30 . V_45 / V_28 -> V_30 . V_32 ;
V_28 -> V_30 . V_44 = V_87 ;
F_10 ( L_22 ,
V_86 -> V_52 , V_86 -> V_54 , V_87 ) ;
V_28 -> V_30 . V_43 = 15 ;
if ( V_28 -> type == V_83 )
V_28 -> V_94 = F_30 ;
else
V_28 -> V_94 = F_22 ;
V_28 -> V_95 = F_32 ;
V_28 -> V_96 = F_34 ;
}
static void F_49 ( struct V_27 * V_28 , int V_29 )
{
struct V_1 * V_2 = & V_28 -> V_30 . V_31 [ V_29 ] ;
struct V_1 * V_97 ;
T_3 V_40 ;
if ( V_2 -> V_9 & V_80 ) {
V_2 = V_2 -> V_81 ;
if ( F_20 ( ! V_2 || ! ( V_2 -> V_9 & V_78 ) ) )
return;
V_29 = V_2 -> V_21 ;
}
V_40 = F_50 ( V_28 -> V_41 ,
V_29 ,
V_98 ) ;
if ( V_40 != V_46 ) {
F_14 ( L_23 ,
V_33 , V_40 , V_28 -> V_34 -> V_35 , V_29 ) ;
return;
}
if ( ! ( V_2 -> V_9 & V_78 ) )
return;
F_33 (slave, &pe->slaves, list) {
V_40 = F_50 ( V_28 -> V_41 ,
V_97 -> V_21 ,
V_98 ) ;
if ( V_40 != V_46 )
F_14 ( L_23 ,
V_33 , V_40 , V_28 -> V_34 -> V_35 ,
V_97 -> V_21 ) ;
}
}
static int F_51 ( struct V_27 * V_28 , int V_29 , int V_99 )
{
struct V_1 * V_2 , * V_97 ;
T_3 V_40 ;
V_2 = & V_28 -> V_30 . V_31 [ V_29 ] ;
if ( V_2 -> V_9 & V_80 ) {
V_2 = V_2 -> V_81 ;
F_20 ( ! V_2 || ! ( V_2 -> V_9 & V_78 ) ) ;
V_29 = V_2 -> V_21 ;
}
V_40 = F_52 ( V_28 -> V_41 , V_29 , V_99 ) ;
if ( V_40 != V_46 ) {
F_14 ( L_24 ,
V_33 , V_40 , V_99 , V_28 -> V_34 -> V_35 , V_29 ) ;
return - V_56 ;
}
if ( ! ( V_2 -> V_9 & V_78 ) )
return 0 ;
F_33 (slave, &pe->slaves, list) {
V_40 = F_52 ( V_28 -> V_41 ,
V_97 -> V_21 ,
V_99 ) ;
if ( V_40 != V_46 ) {
F_14 ( L_24 ,
V_33 , V_40 , V_99 , V_28 -> V_34 -> V_35 ,
V_97 -> V_21 ) ;
return - V_56 ;
}
}
return 0 ;
}
static int F_53 ( struct V_27 * V_28 , int V_29 )
{
struct V_1 * V_97 , * V_2 ;
T_8 V_100 , V_101 ;
T_9 V_102 ;
T_3 V_40 ;
if ( V_29 < 0 || V_29 >= V_28 -> V_30 . V_32 )
return V_103 ;
V_2 = & V_28 -> V_30 . V_31 [ V_29 ] ;
if ( V_2 -> V_9 & V_80 ) {
V_2 = V_2 -> V_81 ;
F_20 ( ! V_2 || ! ( V_2 -> V_9 & V_78 ) ) ;
V_29 = V_2 -> V_21 ;
}
V_40 = F_54 ( V_28 -> V_41 , V_29 ,
& V_101 , & V_102 , NULL ) ;
if ( V_40 != V_46 ) {
F_14 ( L_25
L_26 ,
V_33 , V_40 ,
V_28 -> V_34 -> V_35 , V_29 ) ;
return V_104 ;
}
if ( ! ( V_2 -> V_9 & V_78 ) )
return V_101 ;
F_33 (slave, &pe->slaves, list) {
V_40 = F_54 ( V_28 -> V_41 ,
V_97 -> V_21 ,
& V_100 ,
& V_102 ,
NULL ) ;
if ( V_40 != V_46 ) {
F_14 ( L_25
L_26 ,
V_33 , V_40 ,
V_28 -> V_34 -> V_35 , V_97 -> V_21 ) ;
return V_104 ;
}
if ( V_100 > V_101 )
V_101 = V_100 ;
}
return V_101 ;
}
static struct V_1 * F_55 ( struct V_57 * V_12 )
{
struct V_59 * V_34 = F_27 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
struct V_105 * V_106 = F_56 ( V_12 ) ;
if ( ! V_106 )
return NULL ;
if ( V_106 -> V_21 == V_107 )
return NULL ;
return & V_28 -> V_30 . V_31 [ V_106 -> V_21 ] ;
}
static int F_57 ( struct V_27 * V_28 ,
struct V_1 * V_66 ,
struct V_1 * V_108 ,
bool V_109 )
{
const char * V_37 = V_109 ? L_27 : L_28 ;
T_10 V_110 = V_109 ? V_111 :
V_112 ;
struct V_1 * V_97 ;
long V_40 ;
V_40 = F_58 ( V_28 -> V_41 , V_66 -> V_21 ,
V_108 -> V_21 , V_110 ) ;
if ( V_40 != V_46 ) {
F_59 ( V_108 , L_29 ,
V_40 , V_37 ) ;
return - V_113 ;
}
if ( ! ( V_108 -> V_9 & V_78 ) )
return 0 ;
F_33 (slave, &child->slaves, list) {
V_40 = F_58 ( V_28 -> V_41 , V_66 -> V_21 ,
V_97 -> V_21 , V_110 ) ;
if ( V_40 != V_46 ) {
F_59 ( V_97 , L_29 ,
V_40 , V_37 ) ;
return - V_113 ;
}
}
return 0 ;
}
static int F_60 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
bool V_109 )
{
struct V_1 * V_97 ;
struct V_57 * V_11 = NULL ;
int V_114 ;
if ( V_109 ) {
F_52 ( V_28 -> V_41 , V_2 -> V_21 ,
V_115 ) ;
if ( V_2 -> V_9 & V_78 ) {
F_33 (slave, &pe->slaves, list)
F_52 ( V_28 -> V_41 ,
V_97 -> V_21 ,
V_115 ) ;
}
}
V_114 = F_57 ( V_28 , V_2 , V_2 , V_109 ) ;
if ( V_114 )
return V_114 ;
if ( V_2 -> V_9 & V_78 ) {
F_33 (slave, &pe->slaves, list) {
V_114 = F_57 ( V_28 , V_97 , V_2 , V_109 ) ;
if ( V_114 )
return V_114 ;
}
}
if ( V_2 -> V_9 & ( V_14 | V_13 ) )
V_11 = V_2 -> V_15 -> V_116 ;
else if ( V_2 -> V_9 & V_10 )
V_11 = V_2 -> V_11 -> V_19 -> V_116 ;
#ifdef F_5
else if ( V_2 -> V_9 & V_17 )
V_11 = V_2 -> V_18 ;
#endif
while ( V_11 ) {
struct V_105 * V_106 = F_56 ( V_11 ) ;
struct V_1 * V_66 ;
if ( V_106 && V_106 -> V_21 != V_107 ) {
V_66 = & V_28 -> V_30 . V_31 [ V_106 -> V_21 ] ;
V_114 = F_57 ( V_28 , V_66 , V_2 , V_109 ) ;
if ( V_114 )
return V_114 ;
}
V_11 = V_11 -> V_19 -> V_116 ;
}
return 0 ;
}
static int F_61 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
struct V_57 * V_66 ;
T_10 V_117 , V_118 , V_119 ;
T_5 V_40 ;
long V_120 , V_20 ;
if ( V_2 -> V_15 ) {
int V_121 ;
V_118 = V_122 ;
V_119 = V_123 ;
V_66 = V_2 -> V_15 -> V_116 ;
if ( V_2 -> V_9 & V_14 )
V_121 = V_2 -> V_15 -> V_124 . V_54 - V_2 -> V_15 -> V_124 . V_52 + 1 ;
else
V_121 = 1 ;
switch( V_121 ) {
case 1 : V_117 = V_125 ; break;
case 2 : V_117 = V_126 ; break;
case 4 : V_117 = V_127 ; break;
case 8 : V_117 = V_128 ; break;
case 16 : V_117 = V_129 ; break;
case 32 : V_117 = V_130 ; break;
default:
F_62 ( & V_2 -> V_15 -> V_12 , L_30 ,
V_121 ) ;
V_117 = V_125 ;
}
V_120 = V_2 -> V_20 + ( V_121 << 8 ) ;
} else {
if ( V_2 -> V_9 & V_17 )
V_66 = V_2 -> V_18 ;
else
V_66 = V_2 -> V_11 -> V_19 -> V_116 ;
V_117 = V_125 ;
V_118 = V_131 ;
V_119 = V_132 ;
V_120 = V_2 -> V_20 + 1 ;
}
for ( V_20 = V_2 -> V_20 ; V_20 < V_120 ; V_20 ++ )
V_28 -> V_30 . V_133 [ V_20 ] = 0 ;
while ( V_66 ) {
struct V_105 * V_106 = F_56 ( V_66 ) ;
if ( V_106 && V_106 -> V_21 != V_107 ) {
V_40 = F_58 ( V_28 -> V_41 , V_106 -> V_21 ,
V_2 -> V_21 , V_112 ) ;
}
V_66 = V_66 -> V_19 -> V_116 ;
}
F_52 ( V_28 -> V_41 , V_2 -> V_21 ,
V_115 ) ;
V_40 = F_58 ( V_28 -> V_41 , V_2 -> V_21 ,
V_2 -> V_21 , V_112 ) ;
if ( V_40 )
F_59 ( V_2 , L_31 , V_40 ) ;
V_40 = F_63 ( V_28 -> V_41 , V_2 -> V_21 , V_2 -> V_20 ,
V_117 , V_118 , V_119 , V_134 ) ;
if ( V_40 )
F_64 ( V_2 , L_32 , V_40 ) ;
V_2 -> V_15 = NULL ;
V_2 -> V_11 = NULL ;
V_2 -> V_18 = NULL ;
return 0 ;
}
static int F_65 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
struct V_57 * V_66 ;
T_10 V_117 , V_118 , V_119 ;
long V_40 , V_120 , V_20 ;
if ( V_2 -> V_15 ) {
int V_121 ;
V_118 = V_122 ;
V_119 = V_123 ;
V_66 = V_2 -> V_15 -> V_116 ;
if ( V_2 -> V_9 & V_14 )
V_121 = V_2 -> V_15 -> V_124 . V_54 - V_2 -> V_15 -> V_124 . V_52 + 1 ;
else
V_121 = 1 ;
switch( V_121 ) {
case 1 : V_117 = V_125 ; break;
case 2 : V_117 = V_126 ; break;
case 4 : V_117 = V_127 ; break;
case 8 : V_117 = V_128 ; break;
case 16 : V_117 = V_129 ; break;
case 32 : V_117 = V_130 ; break;
default:
F_62 ( & V_2 -> V_15 -> V_12 , L_30 ,
V_121 ) ;
V_117 = V_125 ;
}
V_120 = V_2 -> V_20 + ( V_121 << 8 ) ;
} else {
#ifdef F_5
if ( V_2 -> V_9 & V_17 )
V_66 = V_2 -> V_18 ;
else
#endif
V_66 = V_2 -> V_11 -> V_19 -> V_116 ;
V_117 = V_125 ;
V_118 = V_131 ;
V_119 = V_132 ;
V_120 = V_2 -> V_20 + 1 ;
}
V_40 = F_63 ( V_28 -> V_41 , V_2 -> V_21 , V_2 -> V_20 ,
V_117 , V_118 , V_119 , V_135 ) ;
if ( V_40 ) {
F_64 ( V_2 , L_32 , V_40 ) ;
return - V_113 ;
}
if ( V_28 -> type != V_136 )
F_60 ( V_28 , V_2 , true ) ;
for ( V_20 = V_2 -> V_20 ; V_20 < V_120 ; V_20 ++ )
V_28 -> V_30 . V_133 [ V_20 ] = V_2 -> V_21 ;
if ( V_28 -> type != V_83 ) {
V_2 -> V_137 = 0 ;
goto V_138;
}
V_2 -> V_137 = V_2 -> V_21 ;
V_40 = F_66 ( V_28 -> V_41 , V_2 -> V_137 , V_2 -> V_21 ) ;
if ( V_40 != V_46 ) {
F_64 ( V_2 , L_33 ,
V_40 , V_2 -> V_137 ) ;
V_2 -> V_137 = - 1 ;
} else {
V_40 = F_67 ( V_28 -> V_41 ,
V_2 -> V_137 , V_139 ) ;
if ( V_40 ) {
F_64 ( V_2 , L_34 ,
V_40 , V_2 -> V_137 ) ;
V_2 -> V_137 = - 1 ;
}
}
V_138:
return 0 ;
}
static int F_68 ( struct V_57 * V_12 , int V_140 )
{
struct V_105 * V_106 = F_56 ( V_12 ) ;
int V_64 ;
struct V_38 * V_86 , V_141 ;
T_4 V_75 ;
T_11 V_142 ;
if ( ! V_12 -> V_143 )
return - V_23 ;
V_142 = V_106 -> V_142 ;
for ( V_64 = 0 ; V_64 < V_144 ; V_64 ++ ) {
V_86 = & V_12 -> V_38 [ V_64 + V_145 ] ;
if ( ! V_86 -> V_9 || ! V_86 -> V_66 )
continue;
V_75 = F_69 ( V_12 , V_64 + V_145 ) ;
V_141 . V_9 = V_86 -> V_9 ;
V_141 . V_52 = V_86 -> V_52 + ( V_75 * V_140 ) ;
V_141 . V_54 = V_141 . V_52 + ( V_75 * V_142 ) - 1 ;
if ( V_141 . V_54 > V_86 -> V_54 ) {
F_62 ( & V_12 -> V_12 , L_35 ,
V_64 , & V_141 , V_86 , V_142 , V_140 ) ;
return - V_146 ;
}
}
for ( V_64 = 0 ; V_64 < V_144 ; V_64 ++ ) {
V_86 = & V_12 -> V_38 [ V_64 + V_145 ] ;
if ( ! V_86 -> V_9 || ! V_86 -> V_66 )
continue;
V_75 = F_69 ( V_12 , V_64 + V_145 ) ;
V_141 = * V_86 ;
V_86 -> V_52 += V_75 * V_140 ;
F_70 ( & V_12 -> V_12 , L_36 ,
V_64 , & V_141 , V_86 , ( V_140 > 0 ) ? L_37 : L_38 ,
V_142 , V_140 ) ;
F_71 ( V_12 , V_64 + V_145 ) ;
}
return 0 ;
}
static struct V_1 * F_72 ( struct V_57 * V_12 )
{
struct V_59 * V_34 = F_27 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
struct V_105 * V_106 = F_56 ( V_12 ) ;
struct V_1 * V_2 ;
if ( ! V_106 ) {
F_73 ( L_39 ,
F_74 ( V_12 ) ) ;
return NULL ;
}
if ( V_106 -> V_21 != V_107 )
return NULL ;
V_2 = F_17 ( V_28 ) ;
if ( ! V_2 ) {
F_75 ( L_40 ,
F_74 ( V_12 ) ) ;
return NULL ;
}
F_76 ( V_12 ) ;
V_106 -> V_147 = V_12 ;
V_106 -> V_21 = V_2 -> V_21 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = V_12 ;
V_2 -> V_15 = NULL ;
V_2 -> V_137 = - 1 ;
V_2 -> V_20 = V_12 -> V_19 -> V_16 << 8 | V_106 -> V_148 ;
F_77 ( V_2 , L_41 ) ;
if ( F_65 ( V_28 , V_2 ) ) {
F_19 ( V_2 ) ;
V_106 -> V_21 = V_107 ;
V_2 -> V_11 = NULL ;
F_78 ( V_12 ) ;
return NULL ;
}
F_41 ( & V_2 -> V_82 , & V_28 -> V_30 . V_149 ) ;
return V_2 ;
}
static void F_79 ( struct V_71 * V_19 , struct V_1 * V_2 )
{
struct V_57 * V_12 ;
F_33 (dev, &bus->devices, bus_list) {
struct V_105 * V_106 = F_56 ( V_12 ) ;
if ( V_106 == NULL ) {
F_14 ( L_42 ,
F_74 ( V_12 ) ) ;
continue;
}
V_106 -> V_147 = V_12 ;
V_106 -> V_21 = V_2 -> V_21 ;
if ( ( V_2 -> V_9 & V_14 ) && V_12 -> V_73 )
F_79 ( V_12 -> V_73 , V_2 ) ;
}
}
static struct V_1 * F_80 ( struct V_71 * V_19 , bool V_72 )
{
struct V_59 * V_34 = F_27 ( V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
struct V_1 * V_2 = NULL ;
if ( V_28 -> V_96 )
V_2 = V_28 -> V_96 ( V_19 , V_72 ) ;
if ( ! V_2 )
V_2 = F_17 ( V_28 ) ;
if ( ! V_2 ) {
F_75 ( L_43 ,
V_33 , F_4 ( V_19 ) , V_19 -> V_16 ) ;
return NULL ;
}
V_2 -> V_9 |= ( V_72 ? V_14 : V_13 ) ;
V_2 -> V_15 = V_19 ;
V_2 -> V_11 = NULL ;
V_2 -> V_137 = - 1 ;
V_2 -> V_20 = V_19 -> V_124 . V_52 << 8 ;
if ( V_72 )
F_77 ( V_2 , L_44 ,
V_19 -> V_124 . V_52 , V_19 -> V_124 . V_54 , V_2 -> V_21 ) ;
else
F_77 ( V_2 , L_45 ,
V_19 -> V_124 . V_52 , V_2 -> V_21 ) ;
if ( F_65 ( V_28 , V_2 ) ) {
F_19 ( V_2 ) ;
V_2 -> V_15 = NULL ;
return NULL ;
}
F_79 ( V_19 , V_2 ) ;
F_41 ( & V_2 -> V_82 , & V_28 -> V_30 . V_149 ) ;
return V_2 ;
}
static struct V_1 * F_81 ( struct V_57 * V_150 )
{
int V_151 , V_152 = false , V_40 ;
long V_20 ;
struct V_1 * V_2 ;
struct V_57 * V_153 ;
struct V_105 * V_154 ;
struct V_59 * V_34 = F_27 ( V_150 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
V_153 = F_82 ( V_150 ) ;
for ( V_151 = 0 ; V_151 < V_28 -> V_30 . V_32 ; V_151 ++ ) {
V_2 = & V_28 -> V_30 . V_31 [ V_151 ] ;
if ( ! V_2 -> V_11 )
continue;
if ( F_82 ( V_2 -> V_11 ) == V_153 ) {
F_70 ( & V_150 -> V_12 ,
L_46 , V_151 ) ;
F_76 ( V_150 ) ;
V_154 = F_56 ( V_150 ) ;
V_20 = V_150 -> V_19 -> V_16 << 8 | V_154 -> V_148 ;
V_154 -> V_147 = V_150 ;
V_154 -> V_21 = V_151 ;
V_28 -> V_30 . V_133 [ V_20 ] = V_2 -> V_21 ;
V_40 = F_63 ( V_28 -> V_41 , V_151 , V_20 ,
V_125 ,
V_131 ,
V_132 ,
V_135 ) ;
F_20 ( V_40 != V_46 ) ;
V_152 = true ;
break;
}
}
if ( ! V_152 )
return F_72 ( V_150 ) ;
else
return V_2 ;
}
static void F_83 ( struct V_71 * V_19 )
{
struct V_57 * V_11 ;
F_33 (pdev, &bus->devices, bus_list)
F_81 ( V_11 ) ;
}
static void F_84 ( struct V_71 * V_19 )
{
struct V_57 * V_12 ;
F_80 ( V_19 , false ) ;
F_33 (dev, &bus->devices, bus_list) {
if ( V_12 -> V_73 ) {
if ( F_85 ( V_12 ) == V_155 )
F_80 ( V_12 -> V_73 , true ) ;
else
F_84 ( V_12 -> V_73 ) ;
}
}
}
static void F_86 ( void )
{
struct V_59 * V_34 , * V_156 ;
struct V_27 * V_28 ;
F_87 (hose, tmp, &hose_list, list_node) {
V_28 = V_34 -> V_60 ;
if ( V_28 -> V_95 )
V_28 -> V_95 ( V_34 -> V_19 , NULL , true ) ;
if ( V_28 -> type == V_136 ) {
F_13 ( V_28 , 0 ) ;
F_83 ( V_34 -> V_19 ) ;
} else
F_84 ( V_34 -> V_19 ) ;
}
}
static int F_88 ( struct V_57 * V_11 , T_11 V_142 )
{
struct V_71 * V_19 ;
struct V_59 * V_34 ;
struct V_27 * V_28 ;
struct V_105 * V_106 ;
int V_64 , V_157 ;
int V_158 ;
V_19 = V_11 -> V_19 ;
V_34 = F_27 ( V_19 ) ;
V_28 = V_34 -> V_60 ;
V_106 = F_56 ( V_11 ) ;
if ( V_106 -> V_159 )
V_158 = V_142 ;
else
V_158 = 1 ;
for ( V_64 = 0 ; V_64 < V_144 ; V_64 ++ )
for ( V_157 = 0 ; V_157 < V_158 ; V_157 ++ ) {
if ( V_106 -> V_160 [ V_157 ] [ V_64 ] == V_161 )
continue;
F_24 ( V_28 -> V_41 ,
V_42 , V_106 -> V_160 [ V_157 ] [ V_64 ] , 0 ) ;
F_21 ( V_106 -> V_160 [ V_157 ] [ V_64 ] , & V_28 -> V_30 . V_49 ) ;
V_106 -> V_160 [ V_157 ] [ V_64 ] = V_161 ;
}
F_38 ( V_106 -> V_160 ) ;
return 0 ;
}
static int F_89 ( struct V_57 * V_11 , T_11 V_142 )
{
struct V_71 * V_19 ;
struct V_59 * V_34 ;
struct V_27 * V_28 ;
struct V_105 * V_106 ;
unsigned int V_162 ;
struct V_38 * V_86 ;
int V_64 , V_157 ;
T_5 V_40 ;
int V_163 ;
T_4 V_75 , V_52 ;
int V_151 ;
int V_158 ;
V_19 = V_11 -> V_19 ;
V_34 = F_27 ( V_19 ) ;
V_28 = V_34 -> V_60 ;
V_106 = F_56 ( V_11 ) ;
V_163 = F_90 ( V_11 ) ;
if ( V_106 -> V_159 )
V_158 = V_142 ;
else
V_158 = 1 ;
V_106 -> V_160 = F_91 ( sizeof( * V_106 -> V_160 ) * V_158 , V_76 ) ;
if ( ! V_106 -> V_160 )
return - V_164 ;
for ( V_64 = 0 ; V_64 < V_158 ; V_64 ++ )
for ( V_157 = 0 ; V_157 < V_144 ; V_157 ++ )
V_106 -> V_160 [ V_64 ] [ V_157 ] = V_161 ;
for ( V_64 = 0 ; V_64 < V_144 ; V_64 ++ ) {
V_86 = & V_11 -> V_38 [ V_64 + V_145 ] ;
if ( ! V_86 -> V_9 || ! V_86 -> V_66 )
continue;
for ( V_157 = 0 ; V_157 < V_158 ; V_157 ++ ) {
do {
V_162 = F_18 ( & V_28 -> V_30 . V_49 ,
V_28 -> V_30 . V_43 + 1 , 0 ) ;
if ( V_162 >= V_28 -> V_30 . V_43 + 1 )
goto V_165;
} while ( F_15 ( V_162 , & V_28 -> V_30 . V_49 ) );
V_106 -> V_160 [ V_157 ] [ V_64 ] = V_162 ;
if ( V_106 -> V_159 ) {
V_75 = F_69 ( V_11 ,
V_145 + V_64 ) ;
V_52 = V_86 -> V_52 + V_75 * V_157 ;
} else {
V_75 = F_48 ( V_86 ) ;
V_52 = V_86 -> V_52 ;
}
if ( V_106 -> V_159 ) {
V_151 = V_106 -> V_166 [ V_157 ] ;
V_40 = F_42 ( V_28 -> V_41 ,
V_151 , V_42 ,
V_106 -> V_160 [ V_157 ] [ V_64 ] , 0 ) ;
}
V_40 = F_23 ( V_28 -> V_41 ,
V_42 ,
V_106 -> V_160 [ V_157 ] [ V_64 ] ,
V_52 ,
0 ,
V_75 ) ;
if ( V_40 != V_46 ) {
F_62 ( & V_11 -> V_12 , L_47 ,
V_162 , V_40 ) ;
goto V_165;
}
if ( V_106 -> V_159 )
V_40 = F_24 ( V_28 -> V_41 ,
V_42 , V_106 -> V_160 [ V_157 ] [ V_64 ] , 2 ) ;
else
V_40 = F_24 ( V_28 -> V_41 ,
V_42 , V_106 -> V_160 [ V_157 ] [ V_64 ] , 1 ) ;
if ( V_40 != V_46 ) {
F_62 ( & V_11 -> V_12 , L_48 ,
V_162 , V_40 ) ;
goto V_165;
}
}
}
return 0 ;
V_165:
F_88 ( V_11 , V_142 ) ;
return - V_146 ;
}
static void F_92 ( struct V_57 * V_12 , struct V_1 * V_2 )
{
struct V_167 * V_168 ;
T_5 V_40 ;
V_168 = V_2 -> V_169 . V_170 [ 0 ] ;
V_40 = F_93 ( & V_2 -> V_169 , 0 ) ;
if ( V_40 )
F_59 ( V_2 , L_49 , V_40 ) ;
F_94 ( V_2 , false ) ;
if ( V_2 -> V_169 . V_171 ) {
F_95 ( V_2 -> V_169 . V_171 ) ;
F_96 ( V_2 -> V_169 . V_171 ) ;
}
F_97 ( V_168 ) ;
F_98 ( V_168 , F_99 ( V_12 -> V_12 . V_172 ) ) ;
}
static void F_100 ( struct V_57 * V_11 )
{
struct V_71 * V_19 ;
struct V_59 * V_34 ;
struct V_27 * V_28 ;
struct V_1 * V_2 , * V_173 ;
struct V_105 * V_106 ;
V_19 = V_11 -> V_19 ;
V_34 = F_27 ( V_19 ) ;
V_28 = V_34 -> V_60 ;
V_106 = F_56 ( V_11 ) ;
if ( ! V_11 -> V_143 )
return;
F_87 (pe, pe_n, &phb->ioda.pe_list, list) {
if ( V_2 -> V_18 != V_11 )
continue;
F_92 ( V_11 , V_2 ) ;
F_101 ( & V_28 -> V_30 . V_174 ) ;
F_102 ( & V_2 -> V_82 ) ;
F_103 ( & V_28 -> V_30 . V_174 ) ;
F_61 ( V_28 , V_2 ) ;
F_19 ( V_2 ) ;
}
}
void F_104 ( struct V_57 * V_11 )
{
struct V_71 * V_19 ;
struct V_59 * V_34 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
struct V_105 * V_106 ;
struct V_175 * V_176 ;
T_11 V_142 , V_64 ;
V_19 = V_11 -> V_19 ;
V_34 = F_27 ( V_19 ) ;
V_28 = V_34 -> V_60 ;
V_106 = F_56 ( V_11 ) ;
V_176 = V_11 -> V_177 ;
V_142 = V_106 -> V_142 ;
F_100 ( V_11 ) ;
if ( V_28 -> type == V_88 ) {
if ( ! V_106 -> V_159 )
F_68 ( V_11 , - * V_106 -> V_166 ) ;
F_88 ( V_11 , V_142 ) ;
if ( V_106 -> V_159 ) {
for ( V_64 = 0 ; V_64 < V_142 ; V_64 ++ ) {
if ( V_106 -> V_166 [ V_64 ] == V_107 )
continue;
V_2 = & V_28 -> V_30 . V_31 [ V_106 -> V_166 [ V_64 ] ] ;
F_19 ( V_2 ) ;
}
} else
F_105 ( V_28 -> V_30 . V_36 , * V_106 -> V_166 , V_142 ) ;
F_38 ( V_106 -> V_166 ) ;
}
}
static void F_106 ( struct V_57 * V_11 , T_11 V_142 )
{
struct V_71 * V_19 ;
struct V_59 * V_34 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
int V_151 ;
T_11 V_178 ;
struct V_105 * V_106 ;
V_19 = V_11 -> V_19 ;
V_34 = F_27 ( V_19 ) ;
V_28 = V_34 -> V_60 ;
V_106 = F_56 ( V_11 ) ;
if ( ! V_11 -> V_143 )
return;
for ( V_178 = 0 ; V_178 < V_142 ; V_178 ++ ) {
if ( V_106 -> V_159 )
V_151 = V_106 -> V_166 [ V_178 ] ;
else
V_151 = * V_106 -> V_166 + V_178 ;
V_2 = & V_28 -> V_30 . V_31 [ V_151 ] ;
V_2 -> V_21 = V_151 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_9 = V_17 ;
V_2 -> V_15 = NULL ;
V_2 -> V_18 = V_11 ;
V_2 -> V_137 = - 1 ;
V_2 -> V_20 = ( F_107 ( V_11 , V_178 ) << 8 ) |
F_108 ( V_11 , V_178 ) ;
F_77 ( V_2 , L_50 ,
V_34 -> V_35 , V_11 -> V_19 -> V_16 ,
F_6 ( F_108 ( V_11 , V_178 ) ) ,
F_7 ( F_108 ( V_11 , V_178 ) ) , V_151 ) ;
if ( F_65 ( V_28 , V_2 ) ) {
F_19 ( V_2 ) ;
V_2 -> V_11 = NULL ;
continue;
}
F_101 ( & V_28 -> V_30 . V_174 ) ;
F_41 ( & V_2 -> V_82 , & V_28 -> V_30 . V_149 ) ;
F_103 ( & V_28 -> V_30 . V_174 ) ;
F_109 ( V_28 , V_2 ) ;
}
}
int F_110 ( struct V_57 * V_11 , T_11 V_142 )
{
struct V_71 * V_19 ;
struct V_59 * V_34 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
struct V_105 * V_106 ;
int V_114 ;
T_11 V_64 ;
V_19 = V_11 -> V_19 ;
V_34 = F_27 ( V_19 ) ;
V_28 = V_34 -> V_60 ;
V_106 = F_56 ( V_11 ) ;
if ( V_28 -> type == V_88 ) {
if ( ! V_106 -> V_179 ) {
F_70 ( & V_11 -> V_12 , L_51
L_52 ) ;
return - V_180 ;
}
if ( V_106 -> V_159 && V_142 > V_28 -> V_30 . V_43 ) {
F_70 ( & V_11 -> V_12 , L_53 ) ;
return - V_146 ;
}
if ( V_106 -> V_159 )
V_106 -> V_166 = F_91 ( sizeof( * V_106 -> V_166 ) * V_142 ,
V_76 ) ;
else
V_106 -> V_166 = F_91 ( sizeof( * V_106 -> V_166 ) , V_76 ) ;
if ( ! V_106 -> V_166 )
return - V_164 ;
if ( V_106 -> V_159 )
for ( V_64 = 0 ; V_64 < V_142 ; V_64 ++ )
V_106 -> V_166 [ V_64 ] = V_107 ;
if ( V_106 -> V_159 ) {
for ( V_64 = 0 ; V_64 < V_142 ; V_64 ++ ) {
V_2 = F_17 ( V_28 ) ;
if ( ! V_2 ) {
V_114 = - V_146 ;
goto V_165;
}
V_106 -> V_166 [ V_64 ] = V_2 -> V_21 ;
}
} else {
F_101 ( & V_28 -> V_30 . V_181 ) ;
* V_106 -> V_166 = F_111 (
V_28 -> V_30 . V_36 , V_28 -> V_30 . V_32 ,
0 , V_142 , 0 ) ;
if ( * V_106 -> V_166 >= V_28 -> V_30 . V_32 ) {
F_103 ( & V_28 -> V_30 . V_181 ) ;
F_70 ( & V_11 -> V_12 , L_54 , V_142 ) ;
F_38 ( V_106 -> V_166 ) ;
return - V_146 ;
}
F_112 ( V_28 -> V_30 . V_36 , * V_106 -> V_166 , V_142 ) ;
F_103 ( & V_28 -> V_30 . V_181 ) ;
}
V_106 -> V_142 = V_142 ;
V_114 = F_89 ( V_11 , V_142 ) ;
if ( V_114 ) {
F_70 ( & V_11 -> V_12 , L_55 ) ;
goto V_165;
}
if ( ! V_106 -> V_159 ) {
V_114 = F_68 ( V_11 , * V_106 -> V_166 ) ;
if ( V_114 )
goto V_165;
}
}
F_106 ( V_11 , V_142 ) ;
return 0 ;
V_165:
if ( V_106 -> V_159 ) {
for ( V_64 = 0 ; V_64 < V_142 ; V_64 ++ ) {
if ( V_106 -> V_166 [ V_64 ] == V_107 )
continue;
V_2 = & V_28 -> V_30 . V_31 [ V_106 -> V_166 [ V_64 ] ] ;
F_19 ( V_2 ) ;
}
} else
F_105 ( V_28 -> V_30 . V_36 , * V_106 -> V_166 , V_142 ) ;
F_38 ( V_106 -> V_166 ) ;
return V_114 ;
}
int F_113 ( struct V_57 * V_11 )
{
F_104 ( V_11 ) ;
F_114 ( V_11 ) ;
return 0 ;
}
int F_115 ( struct V_57 * V_11 , T_11 V_142 )
{
F_116 ( V_11 ) ;
return F_110 ( V_11 , V_142 ) ;
}
static void F_117 ( struct V_27 * V_28 , struct V_57 * V_11 )
{
struct V_105 * V_106 = F_56 ( V_11 ) ;
struct V_1 * V_2 ;
if ( ! V_106 || V_106 -> V_21 == V_107 )
return;
V_2 = & V_28 -> V_30 . V_31 [ V_106 -> V_21 ] ;
F_20 ( F_118 ( & V_11 -> V_12 ) != & V_182 ) ;
F_119 ( & V_11 -> V_12 , V_2 -> V_183 ) ;
F_120 ( & V_11 -> V_12 , V_2 -> V_169 . V_170 [ 0 ] ) ;
}
static int F_121 ( struct V_57 * V_11 , T_7 V_184 )
{
struct V_59 * V_34 = F_27 ( V_11 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
struct V_105 * V_106 = F_56 ( V_11 ) ;
struct V_1 * V_2 ;
T_12 V_185 ;
bool V_186 = false ;
if ( F_20 ( ! V_106 || V_106 -> V_21 == V_107 ) )
return - V_187 ; ;
V_2 = & V_28 -> V_30 . V_31 [ V_106 -> V_21 ] ;
if ( V_2 -> V_188 ) {
V_185 = V_2 -> V_183 + F_122 () - 1 ;
V_186 = ( V_184 >= V_185 ) ;
}
if ( V_186 ) {
F_70 ( & V_11 -> V_12 , L_56 ) ;
F_123 ( & V_11 -> V_12 , & V_189 ) ;
} else {
F_70 ( & V_11 -> V_12 , L_57 ) ;
F_123 ( & V_11 -> V_12 , & V_182 ) ;
}
* V_11 -> V_12 . V_184 = V_184 ;
F_124 ( V_11 , V_186 ) ;
return 0 ;
}
static T_7 F_125 ( struct V_57 * V_11 )
{
struct V_59 * V_34 = F_27 ( V_11 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
struct V_105 * V_106 = F_56 ( V_11 ) ;
struct V_1 * V_2 ;
T_7 V_54 , V_190 ;
if ( F_20 ( ! V_106 || V_106 -> V_21 == V_107 ) )
return 0 ;
V_2 = & V_28 -> V_30 . V_31 [ V_106 -> V_21 ] ;
if ( ! V_2 -> V_188 )
return F_126 ( & V_11 -> V_12 ) ;
V_54 = V_2 -> V_183 + F_122 () ;
V_190 = 1ULL << ( F_127 ( V_54 ) - 1 ) ;
V_190 += V_190 - 1 ;
return V_190 ;
}
static void F_128 ( struct V_1 * V_2 ,
struct V_71 * V_19 )
{
struct V_57 * V_12 ;
F_33 (dev, &bus->devices, bus_list) {
F_120 ( & V_12 -> V_12 , V_2 -> V_169 . V_170 [ 0 ] ) ;
F_119 ( & V_12 -> V_12 , V_2 -> V_183 ) ;
F_129 ( & V_12 -> V_12 ) ;
if ( ( V_2 -> V_9 & V_14 ) && V_12 -> V_73 )
F_128 ( V_2 , V_12 -> V_73 ) ;
}
}
static void F_130 ( struct V_167 * V_168 ,
unsigned long V_67 , unsigned long V_191 , bool V_192 )
{
struct V_193 * V_194 = F_131 (
& V_168 -> V_195 , struct V_193 ,
V_196 ) ;
struct V_1 * V_2 = F_132 ( V_194 -> V_169 ,
struct V_1 , V_169 ) ;
T_13 T_14 * V_197 = V_192 ?
( T_13 T_14 * ) V_2 -> V_28 -> V_30 . V_198 :
V_2 -> V_28 -> V_30 . V_199 ;
unsigned long V_52 , V_54 , V_200 ;
const unsigned V_201 = V_168 -> V_202 ;
V_52 = F_133 ( ( ( T_13 * ) V_168 -> V_203 ) + V_67 - V_168 -> V_204 ) ;
V_54 = F_133 ( ( ( T_13 * ) V_168 -> V_203 ) + V_67 - V_168 -> V_204 +
V_191 - 1 ) ;
if ( V_168 -> V_205 ) {
V_52 <<= V_201 ;
V_54 <<= V_201 ;
V_200 = 128ull << V_201 ;
V_52 |= V_168 -> V_205 ;
V_54 |= V_168 -> V_205 ;
} else if ( V_168 -> V_206 & V_207 ) {
V_52 |= ( 1ull << 63 ) ;
V_54 |= ( 1ull << 63 ) ;
V_200 = 16 ;
} else {
V_200 = 128 ;
}
V_54 |= V_200 - 1 ;
F_134 () ;
while ( V_52 <= V_54 ) {
if ( V_192 )
F_135 ( F_136 ( V_52 ) , V_197 ) ;
else
F_137 ( F_136 ( V_52 ) , V_197 ) ;
V_52 += V_200 ;
}
}
static int F_138 ( struct V_167 * V_168 , long V_67 ,
long V_191 , unsigned long V_208 ,
enum V_209 V_210 ,
struct V_211 * V_212 )
{
int V_114 = F_139 ( V_168 , V_67 , V_191 , V_208 , V_210 ,
V_212 ) ;
if ( ! V_114 && ( V_168 -> V_206 & V_213 ) )
F_130 ( V_168 , V_67 , V_191 , false ) ;
return V_114 ;
}
static int F_140 ( struct V_167 * V_168 , long V_67 ,
unsigned long * V_214 , enum V_209 * V_210 )
{
long V_114 = F_141 ( V_168 , V_67 , V_214 , V_210 ) ;
if ( ! V_114 && ( V_168 -> V_206 &
( V_213 | V_215 ) ) )
F_130 ( V_168 , V_67 , 1 , false ) ;
return V_114 ;
}
static void F_142 ( struct V_167 * V_168 , long V_67 ,
long V_191 )
{
F_143 ( V_168 , V_67 , V_191 ) ;
if ( V_168 -> V_206 & V_215 )
F_130 ( V_168 , V_67 , V_191 , false ) ;
}
void F_144 ( struct V_27 * V_28 , bool V_192 )
{
const unsigned long V_216 = V_217 ;
F_134 () ;
if ( V_192 )
F_135 ( F_136 ( V_216 ) ,
( T_13 T_14 * )
V_28 -> V_30 . V_198 ) ;
else
F_137 ( F_136 ( V_216 ) , V_28 -> V_30 . V_199 ) ;
}
static inline void F_145 ( struct V_1 * V_2 )
{
unsigned long V_216 = V_218 | ( V_2 -> V_21 & 0xFF ) ;
struct V_27 * V_28 = V_2 -> V_28 ;
if ( ! V_28 -> V_30 . V_199 )
return;
F_134 () ;
F_137 ( F_136 ( V_216 ) , V_28 -> V_30 . V_199 ) ;
}
static void F_146 ( unsigned V_21 , bool V_192 ,
T_13 T_14 * V_197 , unsigned V_201 ,
unsigned long V_67 , unsigned long V_191 )
{
unsigned long V_52 , V_54 , V_200 ;
V_52 = V_219 ;
V_52 |= ( V_21 & 0xFF ) ;
V_54 = V_52 ;
V_52 |= ( V_67 << V_201 ) ;
V_54 |= ( ( V_67 + V_191 - 1 ) << V_201 ) ;
V_200 = ( 0x1ull << V_201 ) ;
F_134 () ;
while ( V_52 <= V_54 ) {
if ( V_192 )
F_135 ( F_136 ( V_52 ) , V_197 ) ;
else
F_137 ( F_136 ( V_52 ) , V_197 ) ;
V_52 += V_200 ;
}
}
static void F_147 ( struct V_167 * V_168 ,
unsigned long V_67 , unsigned long V_191 , bool V_192 )
{
struct V_193 * V_194 ;
F_148 (tgl, &tbl->it_group_list, next) {
struct V_1 * V_2 = F_132 ( V_194 -> V_169 ,
struct V_1 , V_169 ) ;
T_13 T_14 * V_197 = V_192 ?
( T_13 T_14 * ) V_2 -> V_28 -> V_30 . V_198 :
V_2 -> V_28 -> V_30 . V_199 ;
if ( V_2 -> V_28 -> type == V_136 ) {
F_144 ( V_2 -> V_28 , V_192 ) ;
continue;
}
F_146 ( V_2 -> V_21 , V_192 ,
V_197 , V_168 -> V_202 ,
V_67 , V_191 ) ;
}
}
static int F_149 ( struct V_167 * V_168 , long V_67 ,
long V_191 , unsigned long V_208 ,
enum V_209 V_210 ,
struct V_211 * V_212 )
{
int V_114 = F_139 ( V_168 , V_67 , V_191 , V_208 , V_210 ,
V_212 ) ;
if ( ! V_114 && ( V_168 -> V_206 & V_213 ) )
F_147 ( V_168 , V_67 , V_191 , false ) ;
return V_114 ;
}
static int F_150 ( struct V_167 * V_168 , long V_67 ,
unsigned long * V_214 , enum V_209 * V_210 )
{
long V_114 = F_141 ( V_168 , V_67 , V_214 , V_210 ) ;
if ( ! V_114 && ( V_168 -> V_206 &
( V_213 | V_215 ) ) )
F_147 ( V_168 , V_67 , 1 , false ) ;
return V_114 ;
}
static void F_151 ( struct V_167 * V_168 , long V_67 ,
long V_191 )
{
F_143 ( V_168 , V_67 , V_191 ) ;
if ( V_168 -> V_206 & V_215 )
F_147 ( V_168 , V_67 , V_191 , false ) ;
}
static void F_152 ( struct V_167 * V_168 )
{
F_97 ( V_168 ) ;
F_98 ( V_168 , L_58 ) ;
}
static int F_153 ( struct V_57 * V_12 , void * V_220 )
{
unsigned int * V_221 = ( unsigned int * ) V_220 ;
if ( V_12 -> V_222 != V_223 )
return 0 ;
if ( V_12 -> V_224 == V_225 ||
V_12 -> V_224 == V_226 ||
V_12 -> V_224 == V_227 )
* V_221 += 3 ;
else if ( ( V_12 -> V_224 >> 8 ) == V_228 )
* V_221 += 15 ;
else
* V_221 += 10 ;
return 0 ;
}
static unsigned int F_154 ( struct V_1 * V_2 )
{
unsigned int V_221 = 0 ;
#ifdef F_5
if ( ( V_2 -> V_9 & V_17 ) && V_2 -> V_18 ) {
F_153 ( V_2 -> V_18 , & V_221 ) ;
return V_221 ;
}
#endif
if ( ( V_2 -> V_9 & V_10 ) && V_2 -> V_11 ) {
F_153 ( V_2 -> V_11 , & V_221 ) ;
} else if ( ( V_2 -> V_9 & V_13 ) && V_2 -> V_15 ) {
struct V_57 * V_11 ;
F_33 (pdev, &pe->pbus->devices, bus_list)
F_153 ( V_11 , & V_221 ) ;
} else if ( ( V_2 -> V_9 & V_14 ) && V_2 -> V_15 ) {
F_155 ( V_2 -> V_15 , F_153 , & V_221 ) ;
}
return V_221 ;
}
static void F_156 ( struct V_27 * V_28 ,
struct V_1 * V_2 )
{
struct V_229 * V_230 = NULL ;
struct V_167 * V_168 ;
unsigned int V_221 , V_231 = 0 ;
unsigned int V_232 , V_61 , V_233 , V_234 , V_64 ;
T_5 V_40 ;
void * V_235 ;
V_221 = F_154 ( V_2 ) ;
if ( ! V_221 )
return;
F_155 ( V_28 -> V_34 -> V_19 , F_153 ,
& V_231 ) ;
V_233 = ( V_221 * V_28 -> V_30 . V_236 ) / V_231 ;
if ( ! V_233 )
V_233 = 1 ;
do {
for ( V_61 = 0 ; V_61 <= V_28 -> V_30 . V_236 - V_233 ; V_61 ++ ) {
for ( V_234 = 0 , V_64 = V_61 ; V_64 < V_61 + V_233 ; V_64 ++ ) {
if ( V_28 -> V_30 . V_237 [ V_64 ] ==
V_107 )
V_234 ++ ;
}
if ( V_234 == V_233 )
goto V_238;
}
} while ( -- V_233 );
if ( ! V_233 ) {
F_59 ( V_2 , L_59 ) ;
return;
}
V_238:
V_168 = F_157 ( V_28 -> V_34 -> V_239 ) ;
F_158 ( & V_2 -> V_169 , V_28 -> V_34 -> V_35 ,
V_2 -> V_21 ) ;
F_159 ( V_28 -> V_34 -> V_239 , 0 , V_168 , & V_2 -> V_169 ) ;
F_77 ( V_2 , L_60 ,
V_221 , V_231 , V_61 , V_233 ) ;
F_77 ( V_2 , L_61 ,
V_61 * V_240 ,
( V_61 + V_233 ) * V_240 - 1 ) ;
V_232 = V_240 >> ( V_241 - 3 ) ;
V_230 = F_160 ( V_28 -> V_34 -> V_239 , V_76 ,
F_161 ( V_232 * V_233 ) ) ;
if ( ! V_230 ) {
F_64 ( V_2 , L_62 ) ;
goto V_47;
}
V_235 = F_162 ( V_230 ) ;
memset ( V_235 , 0 , V_232 * V_233 ) ;
for ( V_64 = 0 ; V_64 < V_233 ; V_64 ++ ) {
V_40 = F_163 ( V_28 -> V_41 ,
V_2 -> V_21 ,
V_61 + V_64 , 1 ,
F_133 ( V_235 ) + V_232 * V_64 ,
V_232 , V_242 ) ;
if ( V_40 ) {
F_64 ( V_2 , L_63
L_64 , V_40 ) ;
goto V_47;
}
}
for ( V_64 = V_61 ; V_64 < V_61 + V_233 ; V_64 ++ )
V_28 -> V_30 . V_237 [ V_64 ] = V_2 -> V_21 ;
F_164 ( V_168 , V_235 , V_232 * V_233 ,
V_61 * V_240 ,
V_241 ) ;
if ( V_28 -> V_30 . V_199 )
V_168 -> V_206 |= ( V_213 |
V_215 |
V_207 ) ;
V_168 -> V_243 = & V_244 ;
V_2 -> V_169 . V_245 = V_168 -> V_204 << V_168 -> V_202 ;
V_2 -> V_169 . V_246 = V_168 -> V_247 << V_168 -> V_202 ;
F_165 ( V_168 , V_28 -> V_34 -> V_239 ) ;
if ( V_2 -> V_9 & V_10 ) {
F_120 ( & V_2 -> V_11 -> V_12 , V_168 ) ;
F_129 ( & V_2 -> V_11 -> V_12 ) ;
} else if ( V_2 -> V_9 & ( V_13 | V_14 ) )
F_128 ( V_2 , V_2 -> V_15 ) ;
return;
V_47:
if ( V_230 )
F_166 ( V_230 , F_161 ( V_232 * V_233 ) ) ;
if ( V_168 ) {
F_167 ( V_168 , & V_2 -> V_169 ) ;
F_98 ( V_168 , L_58 ) ;
}
}
static long F_168 ( struct V_248 * V_169 ,
int V_249 , struct V_167 * V_168 )
{
struct V_1 * V_2 = F_132 ( V_169 , struct V_1 ,
V_169 ) ;
struct V_27 * V_28 = V_2 -> V_28 ;
T_5 V_40 ;
const unsigned long V_75 = V_168 -> V_250 ?
V_168 -> V_251 : V_168 -> V_247 ;
const T_15 V_252 = V_168 -> V_204 << V_168 -> V_202 ;
const T_15 V_253 = V_168 -> V_247 << V_168 -> V_202 ;
F_77 ( V_2 , L_65 , V_249 ,
V_252 , V_252 + V_253 - 1 ,
F_169 ( V_168 ) ) ;
V_40 = F_163 ( V_28 -> V_41 ,
V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + V_249 ,
V_168 -> V_250 + 1 ,
F_133 ( V_168 -> V_203 ) ,
V_75 << 3 ,
F_169 ( V_168 ) ) ;
if ( V_40 ) {
F_64 ( V_2 , L_66 , V_40 ) ;
return V_40 ;
}
F_159 ( V_28 -> V_34 -> V_239 , V_249 ,
V_168 , & V_2 -> V_169 ) ;
F_145 ( V_2 ) ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 , bool V_254 )
{
T_16 V_255 = ( V_2 -> V_21 << 1 ) + 1 ;
T_5 V_40 ;
F_77 ( V_2 , L_67 , V_254 ? L_37 : L_38 ) ;
if ( V_254 ) {
T_17 V_185 = F_122 () ;
V_185 = F_170 ( V_185 ) ;
V_40 = F_171 ( V_2 -> V_28 -> V_41 ,
V_2 -> V_21 ,
V_255 ,
V_2 -> V_183 ,
V_185 ) ;
} else {
V_40 = F_171 ( V_2 -> V_28 -> V_41 ,
V_2 -> V_21 ,
V_255 ,
V_2 -> V_183 ,
0 ) ;
}
if ( V_40 )
F_64 ( V_2 , L_68 , V_40 ) ;
else
V_2 -> V_188 = V_254 ;
}
static long F_172 ( struct V_248 * V_169 ,
int V_249 , T_18 V_256 , T_15 V_257 , T_18 V_258 ,
struct V_167 * * V_259 )
{
struct V_1 * V_2 = F_132 ( V_169 , struct V_1 ,
V_169 ) ;
int V_260 = V_2 -> V_28 -> V_34 -> V_239 ;
T_15 V_261 = V_249 ? V_2 -> V_183 : V_169 -> V_245 ;
long V_114 ;
struct V_167 * V_168 ;
V_168 = F_157 ( V_260 ) ;
if ( ! V_168 )
return - V_164 ;
V_114 = F_173 ( V_260 ,
V_261 , V_256 , V_257 ,
V_258 , V_168 ) ;
if ( V_114 ) {
F_98 ( V_168 , L_58 ) ;
return V_114 ;
}
V_168 -> V_243 = & V_262 ;
if ( V_2 -> V_28 -> V_30 . V_199 )
V_168 -> V_206 |= ( V_213 | V_215 ) ;
* V_259 = V_168 ;
return 0 ;
}
static long F_174 ( struct V_1 * V_2 )
{
struct V_167 * V_168 = NULL ;
long V_40 ;
const T_7 V_263 = F_175 ( F_176 () ) ;
const T_7 V_257 = F_177 ( ( T_7 ) V_2 -> V_169 . V_246 , V_263 ) ;
V_40 = F_172 ( & V_2 -> V_169 , 0 ,
V_241 ,
V_257 ,
V_264 , & V_168 ) ;
if ( V_40 ) {
F_64 ( V_2 , L_69 ,
V_40 ) ;
return V_40 ;
}
F_165 ( V_168 , V_2 -> V_28 -> V_34 -> V_239 ) ;
V_40 = F_168 ( & V_2 -> V_169 , 0 , V_168 ) ;
if ( V_40 ) {
F_64 ( V_2 , L_70 ,
V_40 ) ;
F_152 ( V_168 ) ;
return V_40 ;
}
if ( ! V_24 )
F_94 ( V_2 , true ) ;
if ( V_2 -> V_28 -> V_30 . V_199 )
V_168 -> V_206 |= ( V_213 | V_215 ) ;
if ( V_2 -> V_9 & V_10 )
F_120 ( & V_2 -> V_11 -> V_12 , V_168 ) ;
return 0 ;
}
static long F_93 ( struct V_248 * V_169 ,
int V_249 )
{
struct V_1 * V_2 = F_132 ( V_169 , struct V_1 ,
V_169 ) ;
struct V_27 * V_28 = V_2 -> V_28 ;
long V_114 ;
F_77 ( V_2 , L_71 , V_249 ) ;
V_114 = F_163 ( V_28 -> V_41 , V_2 -> V_21 ,
( V_2 -> V_21 << 1 ) + V_249 ,
0 , 0 ,
0 , 0 ) ;
if ( V_114 )
F_59 ( V_2 , L_72 , V_114 ) ;
else
F_145 ( V_2 ) ;
F_167 ( V_169 -> V_170 [ V_249 ] , V_169 ) ;
return V_114 ;
}
static unsigned long F_178 ( T_18 V_256 ,
T_15 V_257 , T_18 V_258 )
{
unsigned long V_265 = 0 ;
const unsigned V_266 = F_179 ( V_257 ) ;
unsigned V_267 = V_266 - V_256 ;
unsigned V_268 = V_267 + 3 ;
unsigned long V_269 = F_180 ( 0x1000UL , 1UL << V_268 ) ;
unsigned long V_270 ;
if ( ! V_258 || ( V_258 > V_271 ) ||
( V_257 > F_176 () ) ||
! F_181 ( V_257 ) )
return 0 ;
V_267 = ( V_267 + V_258 - 1 ) / V_258 ;
V_268 = V_267 + 3 ;
V_268 = F_182 ( unsigned , V_268 , V_272 ) ;
V_270 = 1UL << V_268 ;
for ( ; V_258 ; -- V_258 ) {
V_265 += F_29 ( V_269 , V_270 ) ;
V_269 /= V_270 ;
V_269 <<= 3 ;
V_269 = F_29 ( V_269 , V_270 ) ;
}
return V_265 ;
}
static void F_183 ( struct V_248 * V_169 )
{
struct V_1 * V_2 = F_132 ( V_169 , struct V_1 ,
V_169 ) ;
struct V_167 * V_168 = V_2 -> V_169 . V_170 [ 0 ] ;
F_94 ( V_2 , false ) ;
F_93 ( & V_2 -> V_169 , 0 ) ;
F_152 ( V_168 ) ;
}
static void F_184 ( struct V_248 * V_169 )
{
struct V_1 * V_2 = F_132 ( V_169 , struct V_1 ,
V_169 ) ;
F_174 ( V_2 ) ;
}
static int F_185 ( struct V_273 * V_12 , void * V_274 )
{
struct V_59 * V_34 ;
struct V_27 * V_28 ;
struct V_1 * * V_275 = V_274 ;
struct V_57 * V_11 = F_132 ( V_12 , struct V_57 , V_12 ) ;
struct V_105 * V_106 = F_56 ( V_11 ) ;
if ( ! V_106 || V_106 -> V_21 == V_107 )
return 0 ;
V_34 = F_27 ( V_11 -> V_19 ) ;
V_28 = V_34 -> V_60 ;
if ( V_28 -> type != V_136 )
return 0 ;
* V_275 = & V_28 -> V_30 . V_31 [ V_106 -> V_21 ] ;
return 1 ;
}
static struct V_1 * F_186 (
struct V_248 * V_169 )
{
struct V_1 * V_276 = NULL ;
int V_114 = F_187 ( V_169 -> V_171 , & V_276 ,
F_185 ) ;
F_96 ( ! V_114 || ! V_276 ) ;
return V_276 ;
}
static long F_188 ( struct V_248 * V_169 ,
int V_249 , struct V_167 * V_168 )
{
long V_114 = F_168 ( V_169 , V_249 , V_168 ) ;
if ( V_114 )
return V_114 ;
V_114 = F_189 ( F_186 ( V_169 ) , V_249 , V_168 ) ;
if ( V_114 )
F_93 ( V_169 , V_249 ) ;
return V_114 ;
}
static long F_190 (
struct V_248 * V_169 ,
int V_249 )
{
long V_114 = F_93 ( V_169 , V_249 ) ;
if ( V_114 )
return V_114 ;
return F_191 ( F_186 ( V_169 ) , V_249 ) ;
}
static void F_192 ( struct V_248 * V_169 )
{
F_193 ( F_186 ( V_169 ) ) ;
F_183 ( V_169 ) ;
}
static void F_194 ( void )
{
struct V_59 * V_34 , * V_156 ;
struct V_27 * V_28 ;
struct V_1 * V_2 , * V_277 ;
F_87 (hose, tmp, &hose_list, list_node) {
V_28 = V_34 -> V_60 ;
if ( V_28 -> type != V_136 )
continue;
F_33 (pe, &phb->ioda.pe_list, list) {
V_277 = F_195 ( V_2 ) ;
if ( V_277 )
V_277 -> V_169 . V_278 = & V_279 ;
}
}
}
static void F_194 ( void ) { }
static void F_196 ( struct V_27 * V_28 )
{
const T_13 * V_280 ;
V_280 = F_45 ( V_28 -> V_34 -> V_85 , L_73 , NULL ) ;
if ( ! V_280 )
return;
V_28 -> V_30 . V_198 = F_197 ( V_280 ) ;
V_28 -> V_30 . V_199 = F_198 ( V_28 -> V_30 . V_198 , 8 ) ;
}
static T_13 * F_199 ( int V_260 , unsigned V_201 ,
unsigned V_258 , unsigned long V_281 ,
unsigned long * V_282 , unsigned long * V_283 )
{
struct V_229 * V_230 = NULL ;
T_13 * V_235 , * V_156 ;
unsigned V_284 = F_182 ( unsigned , V_201 , V_272 ) - V_272 ;
unsigned long V_285 = 1UL << ( V_284 + V_272 ) ;
unsigned V_286 = 1UL << ( V_201 - 3 ) ;
long V_64 ;
V_230 = F_160 ( V_260 , V_76 , V_284 ) ;
if ( ! V_230 ) {
F_73 ( L_74 , V_284 ) ;
return NULL ;
}
V_235 = F_162 ( V_230 ) ;
memset ( V_235 , 0 , V_285 ) ;
* V_283 += V_285 ;
-- V_258 ;
if ( ! V_258 ) {
* V_282 += V_285 ;
return V_235 ;
}
for ( V_64 = 0 ; V_64 < V_286 ; ++ V_64 ) {
V_156 = F_199 ( V_260 , V_201 ,
V_258 , V_281 , V_282 , V_283 ) ;
if ( ! V_156 )
break;
V_235 [ V_64 ] = F_136 ( F_133 ( V_156 ) |
V_287 | V_288 ) ;
if ( * V_282 >= V_281 )
break;
}
return V_235 ;
}
static long F_173 ( int V_260 , T_15 V_261 ,
T_18 V_256 , T_15 V_257 , T_18 V_258 ,
struct V_167 * V_168 )
{
void * V_235 ;
unsigned long V_140 = 0 , V_289 , V_283 = 0 ;
const unsigned V_266 = F_179 ( V_257 ) ;
unsigned V_267 = V_266 - V_256 ;
unsigned V_268 = F_182 ( unsigned , V_267 + 3 , V_272 ) ;
const unsigned long V_269 = 1UL << V_268 ;
if ( ! V_258 || ( V_258 > V_271 ) )
return - V_23 ;
if ( ( V_257 > F_176 () ) || ! F_181 ( V_257 ) )
return - V_23 ;
V_267 = ( V_267 + V_258 - 1 ) / V_258 ;
V_289 = V_267 + 3 ;
V_289 = F_182 ( unsigned , V_289 , V_272 ) ;
V_235 = F_199 ( V_260 , V_289 ,
V_258 , V_269 , & V_140 , & V_283 ) ;
if ( ! V_235 )
return - V_164 ;
if ( V_140 < V_269 ) {
F_200 ( V_235 ,
1ULL << ( V_289 - 3 ) , V_258 - 1 ) ;
return - V_164 ;
}
F_164 ( V_168 , V_235 , V_269 , V_261 ,
V_256 ) ;
V_168 -> V_251 = 1ULL << ( V_289 - 3 ) ;
V_168 -> V_250 = V_258 - 1 ;
V_168 -> V_290 = V_283 ;
F_201 ( L_75 ,
V_257 , V_269 , V_261 ) ;
return 0 ;
}
static void F_200 ( T_13 * V_235 ,
unsigned long V_75 , unsigned V_3 )
{
const unsigned long V_291 = ( unsigned long ) V_235 &
~ ( V_287 | V_288 ) ;
if ( V_3 ) {
long V_64 ;
T_7 * V_156 = ( T_7 * ) V_291 ;
for ( V_64 = 0 ; V_64 < V_75 ; ++ V_64 ) {
unsigned long V_214 = F_202 ( V_156 [ V_64 ] ) ;
if ( ! ( V_214 & ( V_287 | V_288 ) ) )
continue;
F_200 ( F_203 ( V_214 ) , V_75 ,
V_3 - 1 ) ;
}
}
F_204 ( V_291 , F_161 ( V_75 << 3 ) ) ;
}
static void F_97 ( struct V_167 * V_168 )
{
const unsigned long V_75 = V_168 -> V_250 ?
V_168 -> V_251 : V_168 -> V_247 ;
if ( ! V_168 -> V_247 )
return;
F_200 ( ( T_13 * ) V_168 -> V_203 , V_75 ,
V_168 -> V_250 ) ;
}
static void F_109 ( struct V_27 * V_28 ,
struct V_1 * V_2 )
{
T_5 V_40 ;
V_2 -> V_183 = 1ull << 59 ;
F_158 ( & V_2 -> V_169 , V_28 -> V_34 -> V_35 ,
V_2 -> V_21 ) ;
F_77 ( V_2 , L_76 ,
V_28 -> V_30 . V_292 ) ;
V_2 -> V_169 . V_245 = 0 ;
V_2 -> V_169 . V_246 = V_28 -> V_30 . V_292 ;
V_2 -> V_169 . V_293 =
V_294 ;
V_2 -> V_169 . V_295 = V_271 ;
V_2 -> V_169 . V_296 = V_297 | V_298 | V_299 ;
#ifdef F_205
V_2 -> V_169 . V_278 = & V_300 ;
#endif
V_40 = F_174 ( V_2 ) ;
if ( V_40 )
return;
if ( V_2 -> V_9 & V_10 )
F_129 ( & V_2 -> V_11 -> V_12 ) ;
else if ( V_2 -> V_9 & ( V_13 | V_14 ) )
F_128 ( V_2 , V_2 -> V_15 ) ;
}
static void F_206 ( struct V_27 * V_28 )
{
struct V_59 * V_34 = V_28 -> V_34 ;
struct V_1 * V_2 ;
unsigned int V_221 ;
F_10 ( L_77 ,
V_34 -> V_35 , V_28 -> V_30 . V_236 ) ;
F_196 ( V_28 ) ;
F_33 (pe, &phb->ioda.pe_list, list) {
V_221 = F_154 ( V_2 ) ;
if ( ! V_221 )
continue;
if ( V_28 -> type == V_83 ) {
F_156 ( V_28 , V_2 ) ;
} else if ( V_28 -> type == V_88 ) {
F_77 ( V_2 , L_78 ) ;
F_109 ( V_28 , V_2 ) ;
} else if ( V_28 -> type == V_136 ) {
}
}
}
static void F_207 ( struct V_301 * V_302 )
{
unsigned int V_303 = ( unsigned int ) F_208 ( V_302 ) ;
struct V_304 * V_305 = F_209 ( V_302 ) ;
struct V_27 * V_28 = F_132 ( V_305 , struct V_27 ,
V_30 . V_304 ) ;
T_5 V_40 ;
V_40 = F_210 ( V_28 -> V_41 , V_303 ) ;
F_211 ( V_40 ) ;
F_212 ( V_302 ) ;
}
static void F_213 ( struct V_27 * V_28 , unsigned int V_306 )
{
struct V_301 * V_307 ;
struct V_304 * V_308 ;
if ( V_28 -> type != V_88 )
return;
if ( ! V_28 -> V_30 . V_309 ) {
V_307 = F_214 ( V_306 ) ;
V_308 = F_209 ( V_307 ) ;
V_28 -> V_30 . V_309 = 1 ;
V_28 -> V_30 . V_304 = * V_308 ;
V_28 -> V_30 . V_304 . V_310 = F_207 ;
}
F_215 ( V_306 , & V_28 -> V_30 . V_304 ) ;
}
struct V_84 * F_216 ( struct V_57 * V_12 )
{
struct V_59 * V_34 = F_27 ( V_12 -> V_19 ) ;
return F_217 ( V_34 -> V_85 ) ;
}
int F_218 ( struct V_57 * V_12 , T_12 V_311 )
{
struct V_59 * V_34 = F_27 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
struct V_1 * V_2 ;
int V_40 ;
V_2 = F_55 ( V_12 ) ;
if ( ! V_2 )
return - V_187 ;
F_77 ( V_2 , L_79 ) ;
V_40 = F_219 ( V_28 -> V_41 , V_311 , V_2 -> V_21 ) ;
if ( V_40 )
F_62 ( & V_12 -> V_12 , L_80 , V_40 ) ;
return V_40 ;
}
int F_220 ( struct V_57 * V_12 , int V_249 )
{
struct V_59 * V_34 = F_27 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
int V_312 = F_221 ( & V_28 -> V_313 , V_249 ) ;
if ( V_312 < 0 ) {
F_222 ( & V_12 -> V_12 , L_81 ) ;
return - V_180 ;
}
return V_28 -> V_314 + V_312 ;
}
void F_223 ( struct V_57 * V_12 , int V_312 , int V_249 )
{
struct V_59 * V_34 = F_27 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
F_224 ( & V_28 -> V_313 , V_312 - V_28 -> V_314 , V_249 ) ;
}
void F_225 ( struct V_315 * V_316 ,
struct V_57 * V_12 )
{
struct V_59 * V_34 = F_27 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
int V_64 , V_312 ;
for ( V_64 = 1 ; V_64 < V_317 ; V_64 ++ ) {
if ( ! V_316 -> V_318 [ V_64 ] )
continue;
F_201 ( L_82 ,
V_64 , V_316 -> V_140 [ V_64 ] ,
V_316 -> V_318 [ V_64 ] ) ;
V_312 = V_316 -> V_140 [ V_64 ] - V_28 -> V_314 ;
F_224 ( & V_28 -> V_313 , V_312 ,
V_316 -> V_318 [ V_64 ] ) ;
}
}
int F_226 ( struct V_315 * V_316 ,
struct V_57 * V_12 , int V_249 )
{
struct V_59 * V_34 = F_27 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
int V_64 , V_312 , V_319 ;
memset ( V_316 , 0 , sizeof( struct V_315 ) ) ;
for ( V_64 = 1 ; V_64 < V_317 && V_249 ; V_64 ++ ) {
V_319 = V_249 ;
while ( V_319 ) {
V_312 = F_221 ( & V_28 -> V_313 , V_319 ) ;
if ( V_312 >= 0 )
break;
V_319 /= 2 ;
}
if ( ! V_319 )
goto V_47;
V_316 -> V_140 [ V_64 ] = V_28 -> V_314 + V_312 ;
V_316 -> V_318 [ V_64 ] = V_319 ;
F_201 ( L_83 ,
V_64 , V_316 -> V_140 [ V_64 ] , V_316 -> V_318 [ V_64 ] ) ;
V_249 -= V_319 ;
}
if ( V_249 )
goto V_47;
return 0 ;
V_47:
F_225 ( V_316 , V_12 ) ;
return - V_180 ;
}
int F_227 ( struct V_57 * V_12 )
{
struct V_59 * V_34 = F_27 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
return V_28 -> V_313 . V_320 ;
}
int F_228 ( struct V_57 * V_12 , unsigned int V_312 ,
unsigned int V_306 )
{
struct V_59 * V_34 = F_27 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
unsigned int V_321 = V_312 - V_28 -> V_314 ;
struct V_1 * V_2 ;
int V_40 ;
if ( ! ( V_2 = F_55 ( V_12 ) ) )
return - V_187 ;
V_40 = F_229 ( V_28 -> V_41 , V_2 -> V_21 , V_321 ) ;
if ( V_40 ) {
F_59 ( V_2 , L_84
L_85 ,
F_74 ( V_12 ) , V_40 , V_28 -> V_314 , V_312 , V_321 ) ;
return - V_56 ;
}
F_213 ( V_28 , V_306 ) ;
return 0 ;
}
static int F_230 ( struct V_27 * V_28 , struct V_57 * V_12 ,
unsigned int V_312 , unsigned int V_306 ,
unsigned int V_322 , struct V_323 * V_324 )
{
struct V_1 * V_2 = F_55 ( V_12 ) ;
unsigned int V_321 = V_312 - V_28 -> V_314 ;
T_19 V_220 ;
int V_40 ;
if ( V_2 == NULL )
return - V_113 ;
if ( V_2 -> V_137 < 0 )
return - V_113 ;
if ( V_12 -> V_325 )
V_322 = 0 ;
V_40 = F_229 ( V_28 -> V_41 , V_2 -> V_21 , V_321 ) ;
if ( V_40 ) {
F_14 ( L_86 ,
F_74 ( V_12 ) , V_40 , V_321 ) ;
return - V_56 ;
}
if ( V_322 ) {
T_13 V_326 ;
V_40 = F_231 ( V_28 -> V_41 , V_2 -> V_137 , V_321 , 1 ,
& V_326 , & V_220 ) ;
if ( V_40 ) {
F_14 ( L_87 ,
F_74 ( V_12 ) , V_40 ) ;
return - V_56 ;
}
V_324 -> V_327 = F_202 ( V_326 ) >> 32 ;
V_324 -> V_328 = F_202 ( V_326 ) & 0xfffffffful ;
} else {
T_19 V_329 ;
V_40 = F_232 ( V_28 -> V_41 , V_2 -> V_137 , V_321 , 1 ,
& V_329 , & V_220 ) ;
if ( V_40 ) {
F_14 ( L_88 ,
F_74 ( V_12 ) , V_40 ) ;
return - V_56 ;
}
V_324 -> V_327 = 0 ;
V_324 -> V_328 = F_233 ( V_329 ) ;
}
V_324 -> V_220 = F_233 ( V_220 ) ;
F_213 ( V_28 , V_306 ) ;
F_201 ( L_89
L_90 ,
F_74 ( V_12 ) , V_322 ? L_91 : L_92 , V_312 , V_321 ,
V_324 -> V_327 , V_324 -> V_328 , V_220 , V_2 -> V_21 ) ;
return 0 ;
}
static void F_234 ( struct V_27 * V_28 )
{
unsigned int V_121 ;
const T_19 * V_330 = F_45 ( V_28 -> V_34 -> V_85 ,
L_93 , NULL ) ;
if ( ! V_330 ) {
V_330 = F_45 ( V_28 -> V_34 -> V_85 , L_94 , NULL ) ;
}
if ( ! V_330 )
return;
V_28 -> V_314 = F_235 ( V_330 ) ;
V_121 = F_235 ( V_330 + 1 ) ;
if ( F_236 ( & V_28 -> V_313 , V_121 , V_28 -> V_34 -> V_85 ) ) {
F_73 ( L_95 ,
V_28 -> V_34 -> V_35 ) ;
return;
}
V_28 -> V_331 = F_230 ;
V_28 -> V_332 = 1 ;
F_10 ( L_96 ,
V_121 , V_28 -> V_314 ) ;
}
static void F_234 ( struct V_27 * V_28 ) { }
static void F_237 ( struct V_57 * V_11 )
{
struct V_59 * V_34 = F_27 ( V_11 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
const T_4 V_333 = V_28 -> V_30 . V_53 >> 2 ;
struct V_38 * V_86 ;
int V_64 ;
T_4 V_75 , V_334 ;
struct V_105 * V_106 ;
int V_335 , V_163 ;
if ( ! V_11 -> V_143 || V_11 -> V_336 )
return;
V_106 = F_56 ( V_11 ) ;
V_106 -> V_179 = 0 ;
V_106 -> V_159 = false ;
V_163 = F_90 ( V_11 ) ;
V_335 = V_28 -> V_30 . V_32 ;
V_334 = 0 ;
for ( V_64 = 0 ; V_64 < V_144 ; V_64 ++ ) {
V_86 = & V_11 -> V_38 [ V_64 + V_145 ] ;
if ( ! V_86 -> V_9 || V_86 -> V_66 )
continue;
if ( ! F_11 ( V_86 -> V_9 ) ) {
F_222 ( & V_11 -> V_12 , L_97
L_98 ,
V_64 , V_86 ) ;
goto V_337;
}
V_334 += F_69 ( V_11 ,
V_64 + V_145 ) ;
if ( V_334 > V_333 ) {
V_335 = F_170 ( V_163 ) ;
F_70 ( & V_11 -> V_12 ,
L_99 ,
V_334 , V_333 , V_335 ) ;
V_106 -> V_159 = true ;
break;
}
}
for ( V_64 = 0 ; V_64 < V_144 ; V_64 ++ ) {
V_86 = & V_11 -> V_38 [ V_64 + V_145 ] ;
if ( ! V_86 -> V_9 || V_86 -> V_66 )
continue;
V_75 = F_69 ( V_11 , V_64 + V_145 ) ;
if ( V_106 -> V_159 && ( V_75 < V_338 ) )
goto V_337;
F_238 ( & V_11 -> V_12 , L_100 , V_64 , V_86 ) ;
V_86 -> V_54 = V_86 -> V_52 + V_75 * V_335 - 1 ;
F_238 ( & V_11 -> V_12 , L_101 , V_86 ) ;
F_70 ( & V_11 -> V_12 , L_102 ,
V_64 , V_86 , V_335 ) ;
}
V_106 -> V_179 = V_335 ;
return;
V_337:
for ( V_64 = 0 ; V_64 < V_144 ; V_64 ++ ) {
V_86 = & V_11 -> V_38 [ V_64 + V_145 ] ;
V_86 -> V_9 = 0 ;
V_86 -> V_54 = V_86 -> V_52 - 1 ;
}
}
static void F_239 ( struct V_1 * V_2 ,
struct V_38 * V_86 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_339 V_340 ;
int V_67 ;
T_5 V_40 ;
if ( ! V_86 || ! V_86 -> V_9 || V_86 -> V_52 > V_86 -> V_54 )
return;
if ( V_86 -> V_9 & V_341 ) {
V_340 . V_52 = V_86 -> V_52 - V_28 -> V_30 . V_342 ;
V_340 . V_54 = V_86 -> V_54 - V_28 -> V_30 . V_342 ;
V_67 = V_340 . V_52 / V_28 -> V_30 . V_343 ;
while ( V_67 < V_28 -> V_30 . V_32 &&
V_340 . V_52 <= V_340 . V_54 ) {
V_28 -> V_30 . V_344 [ V_67 ] = V_2 -> V_21 ;
V_40 = F_42 ( V_28 -> V_41 ,
V_2 -> V_21 , V_345 , 0 , V_67 ) ;
if ( V_40 != V_46 ) {
F_73 ( L_103 ,
V_33 , V_40 , V_67 , V_2 -> V_21 ) ;
break;
}
V_340 . V_52 += V_28 -> V_30 . V_343 ;
V_67 ++ ;
}
} else if ( ( V_86 -> V_9 & V_92 ) &&
! F_11 ( V_86 -> V_9 ) ) {
V_340 . V_52 = V_86 -> V_52 -
V_28 -> V_34 -> V_93 [ 0 ] -
V_28 -> V_30 . V_292 ;
V_340 . V_54 = V_86 -> V_54 -
V_28 -> V_34 -> V_93 [ 0 ] -
V_28 -> V_30 . V_292 ;
V_67 = V_340 . V_52 / V_28 -> V_30 . V_346 ;
while ( V_67 < V_28 -> V_30 . V_32 &&
V_340 . V_52 <= V_340 . V_54 ) {
V_28 -> V_30 . V_347 [ V_67 ] = V_2 -> V_21 ;
V_40 = F_42 ( V_28 -> V_41 ,
V_2 -> V_21 , V_348 , 0 , V_67 ) ;
if ( V_40 != V_46 ) {
F_73 ( L_104 ,
V_33 , V_40 , V_67 , V_2 -> V_21 ) ;
break;
}
V_340 . V_52 += V_28 -> V_30 . V_346 ;
V_67 ++ ;
}
}
}
static void F_240 ( struct V_1 * V_2 )
{
struct V_57 * V_11 ;
int V_64 ;
F_96 ( ! ( V_2 -> V_9 & ( V_13 | V_14 ) ) ) ;
F_33 (pdev, &pe->pbus->devices, bus_list) {
for ( V_64 = 0 ; V_64 <= V_65 ; V_64 ++ )
F_239 ( V_2 , & V_11 -> V_38 [ V_64 ] ) ;
if ( ! ( V_2 -> V_9 & V_14 ) || ! F_241 ( V_11 ) )
continue;
for ( V_64 = 0 ; V_64 < V_349 ; V_64 ++ )
F_239 ( V_2 ,
& V_11 -> V_38 [ V_350 + V_64 ] ) ;
}
}
static void F_242 ( void )
{
struct V_59 * V_156 , * V_34 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
F_87 (hose, tmp, &hose_list, list_node) {
V_28 = V_34 -> V_60 ;
if ( V_28 -> type == V_136 )
continue;
F_33 (pe, &phb->ioda.pe_list, list) {
F_240 ( V_2 ) ;
}
}
}
static void F_243 ( void )
{
struct V_59 * V_34 , * V_156 ;
struct V_27 * V_28 ;
F_87 (hose, tmp, &hose_list, list_node) {
F_206 ( V_34 -> V_60 ) ;
V_28 = V_34 -> V_60 ;
V_28 -> V_351 = 1 ;
}
F_194 () ;
}
static void F_244 ( void )
{
#ifdef F_245
struct V_59 * V_34 , * V_156 ;
struct V_27 * V_28 ;
char V_91 [ 16 ] ;
F_87 (hose, tmp, &hose_list, list_node) {
V_28 = V_34 -> V_60 ;
sprintf ( V_91 , L_105 , V_34 -> V_35 ) ;
V_28 -> V_352 = F_246 ( V_91 , V_353 ) ;
if ( ! V_28 -> V_352 )
F_75 ( L_106 ,
V_33 , V_34 -> V_35 ) ;
}
#endif
}
static void F_247 ( void )
{
F_86 () ;
F_242 () ;
F_243 () ;
F_244 () ;
#ifdef F_248
F_249 () ;
F_250 () ;
#endif
}
static T_4 F_251 ( struct V_71 * V_19 ,
unsigned long type )
{
struct V_57 * V_354 ;
struct V_59 * V_34 = F_27 ( V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
int V_355 = 0 ;
V_354 = V_19 -> V_116 ;
while ( V_354 ) {
if ( F_85 ( V_354 ) == V_155 ) {
V_355 ++ ;
if ( V_355 >= 2 )
return 1 ;
}
V_354 = V_354 -> V_19 -> V_116 ;
}
if ( V_28 -> V_30 . V_53 &&
F_11 ( type ) )
return V_28 -> V_30 . V_53 ;
if ( type & V_92 )
return V_28 -> V_30 . V_346 ;
return V_28 -> V_30 . V_343 ;
}
static T_4 F_252 ( struct V_57 * V_11 ,
int V_356 )
{
struct V_59 * V_34 = F_27 ( V_11 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
struct V_105 * V_106 = F_56 ( V_11 ) ;
T_4 V_357 ;
V_357 = F_69 ( V_11 , V_356 ) ;
if ( ! V_106 -> V_179 )
return V_357 ;
if ( V_106 -> V_159 )
return F_180 ( V_357 , ( T_4 ) V_28 -> V_30 . V_53 ) ;
return V_106 -> V_179 * V_357 ;
}
static bool F_253 ( struct V_57 * V_12 )
{
struct V_59 * V_34 = F_27 ( V_12 -> V_19 ) ;
struct V_27 * V_28 = V_34 -> V_60 ;
struct V_105 * V_106 ;
if ( ! V_28 -> V_351 )
return true ;
V_106 = F_56 ( V_12 ) ;
if ( ! V_106 || V_106 -> V_21 == V_107 )
return false ;
return true ;
}
static void F_254 ( struct V_59 * V_34 )
{
struct V_27 * V_28 = V_34 -> V_60 ;
F_255 ( V_28 -> V_41 , V_358 ,
V_359 ) ;
}
static int F_256 ( struct V_57 * V_360 , T_7 V_184 )
{
F_257 ( & V_360 -> V_12 ,
L_107 ,
V_33 ) ;
return - V_361 ;
}
static void T_2 F_258 ( struct V_84 * V_362 ,
T_7 V_363 , int V_364 )
{
struct V_59 * V_34 ;
struct V_27 * V_28 ;
unsigned long V_75 , V_365 , V_366 , V_367 ;
unsigned long V_368 = 0 , V_369 = 0 ;
const T_13 * V_370 ;
const T_19 * V_371 ;
int V_372 ;
unsigned int V_63 ;
T_7 V_373 ;
void * V_374 ;
long V_40 ;
F_10 ( L_108 , V_364 , V_362 -> V_90 ) ;
V_370 = F_45 ( V_362 , L_109 , NULL ) ;
if ( ! V_370 ) {
F_73 ( L_110 ) ;
return;
}
V_373 = F_197 ( V_370 ) ;
F_16 ( L_111 , V_373 ) ;
V_28 = F_259 ( sizeof( struct V_27 ) , 0 ) ;
V_28 -> V_34 = V_34 = F_260 ( V_362 ) ;
if ( ! V_28 -> V_34 ) {
F_73 ( L_112 ,
V_362 -> V_90 ) ;
F_261 ( F_133 ( V_28 ) , sizeof( struct V_27 ) ) ;
return;
}
F_262 ( & V_28 -> V_375 ) ;
V_371 = F_45 ( V_362 , L_113 , & V_372 ) ;
if ( V_371 && V_372 == 8 ) {
V_34 -> V_376 = F_233 ( V_371 [ 0 ] ) ;
V_34 -> V_377 = F_233 ( V_371 [ 1 ] ) ;
} else {
F_14 ( L_114 , V_362 -> V_90 ) ;
V_34 -> V_376 = 0 ;
V_34 -> V_377 = 0xff ;
}
V_34 -> V_60 = V_28 ;
V_28 -> V_363 = V_363 ;
V_28 -> V_41 = V_373 ;
V_28 -> type = V_364 ;
F_263 ( & V_28 -> V_30 . V_181 ) ;
if ( F_264 ( V_362 , L_115 ) )
V_28 -> V_378 = V_379 ;
else if ( F_264 ( V_362 , L_116 ) )
V_28 -> V_378 = V_380 ;
else if ( F_264 ( V_362 , L_117 ) )
V_28 -> V_378 = V_381 ;
else
V_28 -> V_378 = V_382 ;
F_265 ( V_34 , V_362 , ! V_34 -> V_35 ) ;
V_28 -> V_383 = F_266 ( V_362 , 0 ) ;
if ( V_28 -> V_383 == NULL )
F_73 ( L_118 ) ;
V_28 -> V_30 . V_32 = 1 ;
V_371 = F_45 ( V_362 , L_119 , NULL ) ;
if ( V_371 )
V_28 -> V_30 . V_32 = F_235 ( V_371 ) ;
V_371 = F_45 ( V_362 , L_120 , NULL ) ;
if ( V_371 )
V_28 -> V_30 . V_51 = F_235 ( V_371 ) ;
F_43 ( V_28 ) ;
V_28 -> V_30 . V_384 = F_48 ( & V_34 -> V_50 [ 0 ] ) ;
V_28 -> V_30 . V_384 += 0x10000 ;
V_28 -> V_30 . V_346 = V_28 -> V_30 . V_384 / V_28 -> V_30 . V_32 ;
V_28 -> V_30 . V_292 = V_34 -> V_50 [ 0 ] . V_52 - V_34 -> V_93 [ 0 ] ;
V_28 -> V_30 . V_385 = V_34 -> V_386 ;
V_28 -> V_30 . V_343 = V_28 -> V_30 . V_385 / V_28 -> V_30 . V_32 ;
V_28 -> V_30 . V_342 = 0 ;
V_28 -> V_30 . V_236 = V_28 -> V_30 . V_292 /
V_240 ;
V_75 = F_29 ( F_182 ( unsigned , V_28 -> V_30 . V_32 , 8 ) / 8 ,
sizeof( unsigned long ) ) ;
V_365 = V_75 ;
V_75 += V_28 -> V_30 . V_32 * sizeof( V_28 -> V_30 . V_77 [ 0 ] ) ;
V_366 = V_75 ;
V_75 += V_28 -> V_30 . V_32 * sizeof( V_28 -> V_30 . V_347 [ 0 ] ) ;
if ( V_28 -> type == V_83 ) {
V_368 = V_75 ;
V_75 += V_28 -> V_30 . V_32 * sizeof( V_28 -> V_30 . V_344 [ 0 ] ) ;
V_369 = V_75 ;
V_75 += V_28 -> V_30 . V_236 *
sizeof( V_28 -> V_30 . V_237 [ 0 ] ) ;
}
V_367 = V_75 ;
V_75 += V_28 -> V_30 . V_32 * sizeof( struct V_1 ) ;
V_374 = F_259 ( V_75 , 0 ) ;
V_28 -> V_30 . V_36 = V_374 ;
V_28 -> V_30 . V_77 = V_374 + V_365 ;
V_28 -> V_30 . V_347 = V_374 + V_366 ;
for ( V_63 = 0 ; V_63 < V_28 -> V_30 . V_32 ; V_63 ++ ) {
V_28 -> V_30 . V_77 [ V_63 ] = V_107 ;
V_28 -> V_30 . V_347 [ V_63 ] = V_107 ;
}
if ( V_28 -> type == V_83 ) {
V_28 -> V_30 . V_344 = V_374 + V_368 ;
for ( V_63 = 0 ; V_63 < V_28 -> V_30 . V_32 ; V_63 ++ )
V_28 -> V_30 . V_344 [ V_63 ] = V_107 ;
V_28 -> V_30 . V_237 = V_374 + V_369 ;
for ( V_63 = 0 ; V_63 < V_28 -> V_30 . V_236 ; V_63 ++ )
V_28 -> V_30 . V_237 [ V_63 ] = V_107 ;
}
V_28 -> V_30 . V_31 = V_374 + V_367 ;
F_25 ( V_28 -> V_30 . V_51 , V_28 -> V_30 . V_36 ) ;
F_40 ( & V_28 -> V_30 . V_149 ) ;
F_263 ( & V_28 -> V_30 . V_174 ) ;
V_28 -> V_30 . V_236 = V_28 -> V_30 . V_292 /
V_240 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_10 ( L_121 ,
V_28 -> V_30 . V_32 , V_28 -> V_30 . V_51 ,
V_28 -> V_30 . V_384 , V_28 -> V_30 . V_346 ) ;
if ( V_28 -> V_30 . V_45 )
F_10 ( L_122 ,
V_28 -> V_30 . V_45 , V_28 -> V_30 . V_53 ) ;
if ( V_28 -> V_30 . V_385 )
F_10 ( L_123 ,
V_28 -> V_30 . V_385 , V_28 -> V_30 . V_343 ) ;
V_28 -> V_34 -> V_278 = & V_387 ;
V_28 -> V_388 = F_53 ;
V_28 -> V_389 = F_49 ;
V_28 -> V_390 = F_51 ;
F_234 ( V_28 ) ;
V_391 . V_392 = F_247 ;
if ( V_28 -> type == V_136 ) {
V_34 -> V_393 = V_394 ;
} else {
V_28 -> V_395 = F_117 ;
V_34 -> V_393 = V_396 ;
}
#ifdef F_5
V_391 . V_397 = F_237 ;
V_391 . V_398 = F_252 ;
#endif
F_267 ( V_399 ) ;
V_40 = F_255 ( V_373 , V_358 , V_359 ) ;
if ( V_40 )
F_75 ( L_124 , V_40 ) ;
if ( F_268 () ) {
F_10 ( L_125 ) ;
F_269 ( V_34 , V_400 ) ;
F_269 ( V_34 , V_401 ) ;
}
if ( ! V_28 -> V_94 || V_28 -> V_94 ( V_28 ) )
V_34 -> V_50 [ 1 ] . V_9 = 0 ;
}
void T_2 F_270 ( struct V_84 * V_362 )
{
F_258 ( V_362 , 0 , V_88 ) ;
}
void T_2 F_271 ( struct V_84 * V_362 )
{
F_258 ( V_362 , 0 , V_136 ) ;
}
void T_2 F_272 ( struct V_84 * V_362 )
{
struct V_84 * V_402 ;
const T_13 * V_370 ;
T_7 V_363 ;
F_10 ( L_126 , V_362 -> V_90 ) ;
V_370 = F_45 ( V_362 , L_127 , NULL ) ;
if ( ! V_370 ) {
F_73 ( L_128 ) ;
return;
}
V_363 = F_197 ( V_370 ) ;
F_201 ( L_129 , V_363 ) ;
F_273 (np, phbn) {
if ( F_264 ( V_402 , L_130 ) )
F_258 ( V_402 , V_363 , V_83 ) ;
}
}
