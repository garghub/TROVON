static void * F_1 ( unsigned long V_1 )
{
void * V_2 ;
unsigned long V_3 ;
V_2 = F_2 ( V_1 ) ;
if ( ! V_2 )
return NULL ;
memset ( V_2 , 0 , V_1 ) ;
V_3 = ( unsigned long ) V_2 ;
while ( V_1 > 0 )
{
F_3 ( F_4 ( ( void * ) V_3 ) ) ;
V_3 += V_4 ;
V_1 -= V_4 ;
}
return V_2 ;
}
static void F_5 ( void * V_2 , unsigned long V_1 )
{
unsigned long V_3 ;
if ( ! V_2 )
return;
V_3 = ( unsigned long ) V_2 ;
while ( ( long ) V_1 > 0 )
{
F_6 ( F_4 ( ( void * ) V_3 ) ) ;
V_3 += V_4 ;
V_1 -= V_4 ;
}
F_7 ( V_2 ) ;
}
static int F_8 ( struct V_5 * V_6 )
{
int V_7 , V_8 ;
void * V_9 ;
F_9 ( L_1 , V_6 ) ;
if ( V_6 == NULL )
return - V_10 ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
if ( V_6 -> V_12 [ V_7 ] . V_13 == NULL ) {
V_9 = F_10 ( V_14 , V_15 ) ;
if ( V_9 == NULL ) {
F_11 ( L_2 , V_7 ) ;
return - V_16 ;
}
F_9 ( L_3 , V_9 ) ;
V_6 -> V_12 [ V_7 ] . V_13 = V_9 ;
}
}
if ( V_6 -> V_17 == NULL ) {
V_9 = F_10 ( V_18 * sizeof( struct V_19 ) , V_15 ) ;
if ( V_9 == NULL ) {
F_11 ( L_4 ) ;
return - V_16 ;
}
F_9 ( L_5 , V_9 ) ;
V_6 -> V_17 = V_9 ;
}
for ( V_7 = 0 ; V_7 < V_18 ; V_7 ++ ) {
if ( V_6 -> V_17 [ V_7 ] . V_13 == NULL ) {
V_9 = F_12 ( V_20 ) ;
if ( V_9 == NULL ) {
F_11 ( L_6 , V_7 ) ;
return - V_16 ;
}
F_9 ( L_7 , V_7 , V_9 ) ;
V_6 -> V_17 [ V_7 ] . V_13 = V_9 ;
}
}
if ( F_13 ( V_6 -> type ) )
V_8 = F_14 ( V_6 ) ;
else
V_8 = F_15 ( V_6 ) ;
if ( V_8 ) {
F_11 ( L_8 ) ;
return V_8 ;
}
V_9 = F_1 ( V_21 * V_6 -> V_22 ) ;
if ( V_9 == NULL ) {
F_11 ( L_9 ,
V_21 * V_6 -> V_22 ) ;
return - V_16 ;
}
F_9 ( L_10 , V_9 ) ;
V_6 -> V_23 = V_9 ;
for ( V_7 = 0 ; V_7 < V_21 ; V_7 ++ ) {
V_6 -> V_24 [ V_7 ] . V_25 = V_7 * V_6 -> V_22 ;
V_6 -> V_24 [ V_7 ] . V_26 = 0 ;
}
for (; V_7 < V_27 ; V_7 ++ ) {
V_6 -> V_24 [ V_7 ] . V_25 = 0 ;
}
V_9 = NULL ;
F_9 ( L_11 ) ;
return 0 ;
}
static void F_16 ( struct V_5 * V_6 )
{
int V_7 ;
F_9 ( L_12 , V_6 ) ;
if ( V_6 == NULL )
return;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ )
if ( V_6 -> V_12 [ V_7 ] . V_13 != NULL ) {
F_9 ( L_13 , V_6 -> V_12 [ V_7 ] . V_13 ) ;
F_17 ( V_6 -> V_12 [ V_7 ] . V_13 ) ;
V_6 -> V_12 [ V_7 ] . V_13 = NULL ;
}
if ( V_6 -> V_17 != NULL ) {
for ( V_7 = 0 ; V_7 < V_18 ; V_7 ++ ) {
if ( V_6 -> V_17 [ V_7 ] . V_13 != NULL ) {
F_9 ( L_14 , V_7 , V_6 -> V_17 [ V_7 ] . V_13 ) ;
F_7 ( V_6 -> V_17 [ V_7 ] . V_13 ) ;
V_6 -> V_17 [ V_7 ] . V_13 = NULL ;
}
}
F_17 ( V_6 -> V_17 ) ;
V_6 -> V_17 = NULL ;
}
if ( V_6 -> V_28 != NULL ) {
F_9 ( L_15 , V_6 -> V_28 ) ;
F_17 ( V_6 -> V_28 ) ;
V_6 -> V_28 = NULL ;
}
if ( V_6 -> V_23 != NULL ) {
F_9 ( L_16 , V_6 -> V_23 ) ;
F_5 ( V_6 -> V_23 , V_21 * V_6 -> V_22 ) ;
}
V_6 -> V_23 = NULL ;
F_9 ( L_17 ) ;
}
static int F_18 ( struct V_5 * V_6 )
{
int V_29 ;
unsigned long V_30 ;
V_29 = 0 ;
F_19 ( & V_6 -> V_31 , V_30 ) ;
if ( V_6 -> V_32 != NULL ) {
if ( V_6 -> V_33 == NULL ) {
V_6 -> V_33 = V_6 -> V_32 ;
V_6 -> V_34 = V_6 -> V_33 ;
}
else {
V_6 -> V_34 -> V_35 = V_6 -> V_32 ;
V_6 -> V_34 = V_6 -> V_32 ;
}
}
if ( V_6 -> V_36 != NULL ) {
V_6 -> V_32 = V_6 -> V_36 ;
V_6 -> V_36 = V_6 -> V_36 -> V_35 ;
}
else {
if ( V_6 -> V_33 == NULL ) {
F_11 ( L_18 ) ;
F_20 ( & V_6 -> V_31 , V_30 ) ;
return - V_37 ;
}
V_6 -> V_32 = V_6 -> V_33 ;
V_6 -> V_33 = V_6 -> V_33 -> V_35 ;
V_29 = 1 ;
}
V_6 -> V_32 -> V_35 = NULL ;
F_20 ( & V_6 -> V_31 , V_30 ) ;
return V_29 ;
}
static void F_21 ( struct V_5 * V_6 )
{
int V_7 ;
unsigned long V_30 ;
F_9 ( L_19 , V_38 ) ;
F_19 ( & V_6 -> V_31 , V_30 ) ;
V_6 -> V_33 = NULL ;
V_6 -> V_34 = NULL ;
for ( V_7 = 0 ; V_7 < V_18 ; V_7 ++ ) {
V_6 -> V_17 [ V_7 ] . V_39 = 0 ;
if ( V_7 > 0 )
V_6 -> V_17 [ V_7 ] . V_35 = & V_6 -> V_17 [ V_7 - 1 ] ;
else
V_6 -> V_17 -> V_35 = NULL ;
}
V_6 -> V_36 = & V_6 -> V_17 [ V_18 - 1 ] ;
V_6 -> V_40 = V_6 -> V_17 ;
V_6 -> V_41 = NULL ;
V_6 -> V_32 = V_6 -> V_36 ;
V_6 -> V_36 = V_6 -> V_36 -> V_35 ;
V_6 -> V_42 = 0 ;
V_6 -> V_43 = 0 ;
F_20 ( & V_6 -> V_31 , V_30 ) ;
F_9 ( L_20 , V_38 ) ;
}
int F_22 ( struct V_5 * V_6 )
{
int V_29 = 0 ;
unsigned long V_30 ;
F_19 ( & V_6 -> V_31 , V_30 ) ;
if ( V_6 -> V_41 != NULL ) {
F_11 ( L_21 ) ;
F_20 ( & V_6 -> V_31 , V_30 ) ;
return V_29 ;
}
if ( V_6 -> V_33 == NULL ) {
F_11 ( L_22 ) ;
}
else {
V_6 -> V_41 = V_6 -> V_33 ;
V_6 -> V_33 = V_6 -> V_33 -> V_35 ;
V_6 -> V_41 -> V_35 = NULL ;
}
if ( V_6 -> V_41 != NULL ) {
F_20 ( & V_6 -> V_31 , V_30 ) ;
V_29 = F_23 ( V_6 ) ;
F_19 ( & V_6 -> V_31 , V_30 ) ;
if ( V_6 -> V_36 == NULL ) {
V_6 -> V_36 = V_6 -> V_41 ;
V_6 -> V_40 = V_6 -> V_36 ;
}
else {
V_6 -> V_40 -> V_35 = V_6 -> V_41 ;
V_6 -> V_40 = V_6 -> V_41 ;
}
V_6 -> V_41 = NULL ;
}
F_20 ( & V_6 -> V_31 , V_30 ) ;
return V_29 ;
}
void F_24 ( struct V_5 * V_6 )
{
V_6 -> V_44 [ V_6 -> V_43 ] = 0 ;
V_6 -> V_43 = ( V_6 -> V_43 + 1 ) % V_21 ;
}
static void F_25 ( struct V_5 * V_6 )
{
V_6 -> V_45 ++ ;
if ( V_6 -> V_46 < V_47 )
return;
if ( V_6 -> V_45 < 20 )
F_26 ( L_23 , V_6 -> V_46 ) ;
else if ( V_6 -> V_45 == 20 )
F_26 ( L_24 ,
V_6 -> V_46 ) ;
}
static void F_27 ( struct V_5 * V_6 , int V_48 )
{
if ( V_48 ) {
F_28 ( L_25 ) ;
V_6 -> V_49 = 1 ;
} else {
F_28 ( L_26 ) ;
}
#ifdef F_29
if ( V_6 -> V_50 ) {
F_30 ( V_6 -> V_50 , V_51 , V_48 ) ;
F_31 ( V_6 -> V_50 ) ;
}
#endif
}
static int F_32 ( struct V_5 * V_6 , const struct V_19 * V_17 )
{
int V_52 = 0 ;
if ( V_6 -> type == 730 ) {
unsigned char * V_53 = ( unsigned char * ) V_17 -> V_13 ;
if ( V_53 [ 1 ] == 1 && V_53 [ 0 ] & 0x10 ) {
F_28 ( L_27 ) ;
V_6 -> V_54 += 2 ;
V_6 -> V_55 ++ ;
}
if ( ( V_53 [ 0 ] ^ V_6 -> V_56 ) & 0x01 ) {
F_27 ( V_6 , V_53 [ 0 ] & 0x01 ) ;
}
if ( ( V_53 [ 0 ] ^ V_6 -> V_56 ) & 0x02 ) {
if ( V_53 [ 0 ] & 0x02 )
F_28 ( L_28 ) ;
else
F_28 ( L_29 ) ;
}
V_6 -> V_56 = V_53 [ 0 ] & 0x03 ;
if ( V_17 -> V_39 == 4 )
V_6 -> V_54 ++ ;
}
else if ( V_6 -> type == 740 || V_6 -> type == 720 ) {
unsigned char * V_53 = ( unsigned char * ) V_17 -> V_13 ;
if ( ( V_53 [ 0 ] ^ V_6 -> V_56 ) & 0x01 ) {
F_27 ( V_6 , V_53 [ 0 ] & 0x01 ) ;
}
V_6 -> V_56 = V_53 [ 0 ] & 0x03 ;
}
if ( V_6 -> V_54 > 0 )
V_6 -> V_54 -- ;
else {
if ( V_17 -> V_39 < V_6 -> V_57 ) {
F_26 ( L_30
L_31 , V_17 -> V_39 ) ;
V_6 -> V_55 ++ ;
}
else {
V_52 = 1 ;
if ( F_18 ( V_6 ) )
F_25 ( V_6 ) ;
}
}
V_6 -> V_46 ++ ;
return V_52 ;
}
static void F_33 ( struct V_58 * V_58 )
{
struct V_5 * V_6 ;
int V_7 , V_59 , V_60 ;
int V_52 ;
struct V_19 * V_17 ;
unsigned char * V_61 = NULL , * V_62 = NULL ;
V_52 = 0 ;
V_6 = (struct V_5 * ) V_58 -> V_63 ;
if ( V_6 == NULL ) {
F_11 ( L_32 ) ;
return;
}
if ( V_58 -> V_64 == - V_65 || V_58 -> V_64 == - V_66 ) {
F_34 ( L_33 , V_58 , V_58 -> V_64 == - V_65 ? L_34 : L_35 ) ;
return;
}
if ( V_58 -> V_64 != - V_67 && V_58 -> V_64 != 0 ) {
const char * V_68 ;
V_68 = L_36 ;
switch( V_58 -> V_64 ) {
case - V_69 : V_68 = L_37 ; break;
case - V_70 : V_68 = L_38 ; break;
case - V_71 : V_68 = L_39 ; break;
case - V_72 : V_68 = L_40 ; break;
case - V_73 : V_68 = L_41 ; break;
case - V_74 : V_68 = L_42 ; break;
}
F_26 ( L_43 , V_58 -> V_64 , V_68 ) ;
if ( ++ V_6 -> V_75 > V_76 )
{
F_35 ( L_44 ) ;
V_6 -> V_77 = V_78 ;
V_52 = 1 ;
F_36 ( & V_6 -> V_79 ) ;
}
goto V_80;
}
V_17 = V_6 -> V_32 ;
if ( V_17 == NULL ) {
F_11 ( L_45 ) ;
V_52 = 1 ;
goto V_80;
}
else {
V_61 = V_17 -> V_13 + V_17 -> V_39 ;
}
V_6 -> V_75 = 0 ;
for ( V_7 = 0 ; V_7 < V_58 -> V_81 ; V_7 ++ ) {
V_59 = V_58 -> V_82 [ V_7 ] . V_64 ;
V_60 = V_58 -> V_82 [ V_7 ] . V_83 ;
V_62 = V_58 -> V_84 + V_58 -> V_82 [ V_7 ] . V_25 ;
if ( V_59 == 0 ) {
if ( V_60 > 0 ) {
if ( V_6 -> V_85 > 0 ) {
V_6 -> V_85 = 2 ;
if ( V_60 + V_17 -> V_39 > V_6 -> V_57 ) {
F_26 ( L_46 , V_60 , V_6 -> V_57 ) ;
V_6 -> V_85 = 0 ;
V_6 -> V_55 ++ ;
}
else {
memmove ( V_61 , V_62 , V_60 ) ;
V_61 += V_60 ;
}
}
V_17 -> V_39 += V_60 ;
}
if ( V_60 < V_6 -> V_86 ) {
if ( V_6 -> V_85 == 2 ) {
if ( F_32 ( V_6 , V_17 ) ) {
V_52 = 1 ;
V_17 = V_6 -> V_32 ;
}
}
V_17 -> V_39 = 0 ;
V_61 = V_17 -> V_13 ;
V_6 -> V_85 = 1 ;
}
V_6 -> V_86 = V_60 ;
}
else {
static int V_87 ;
V_87 ++ ;
if ( V_87 < 20 )
F_26 ( L_47 , V_7 , V_59 ) ;
}
}
V_80:
if ( V_52 )
F_36 ( & V_6 -> V_79 ) ;
V_58 -> V_88 = V_6 -> V_89 ;
V_7 = F_37 ( V_58 , V_90 ) ;
if ( V_7 != 0 )
F_11 ( L_48 , V_7 ) ;
}
int F_38 ( struct V_5 * V_6 )
{
struct V_91 * V_89 ;
struct V_58 * V_58 ;
int V_7 , V_92 , V_29 ;
struct V_93 * V_94 ;
struct V_95 * V_96 = NULL ;
if ( V_6 == NULL )
return - V_97 ;
if ( V_6 -> V_98 )
return 0 ;
V_6 -> V_85 = 0 ;
V_89 = V_6 -> V_89 ;
if ( ! V_89 -> V_99 )
return - V_97 ;
V_94 = F_39 ( V_89 , 0 ) ;
if ( V_94 )
V_96 = F_40 ( V_94 , V_6 -> V_100 ) ;
if ( ! V_96 )
return - V_97 ;
V_6 -> V_101 = - 1 ;
for ( V_7 = 0 ; V_7 < V_96 -> V_102 . V_103 ; V_7 ++ ) {
if ( ( V_96 -> V_104 [ V_7 ] . V_102 . V_105 & 0xF ) == V_6 -> V_106 ) {
V_6 -> V_101 = F_41 ( V_96 -> V_104 [ V_7 ] . V_102 . V_107 ) ;
break;
}
}
if ( V_6 -> V_101 < 0 || V_6 -> V_101 > V_108 ) {
F_11 ( L_49 ) ;
return - V_109 ;
}
V_29 = 0 ;
F_34 ( L_50 , V_6 -> V_100 ) ;
V_29 = F_42 ( V_6 -> V_89 , 0 , V_6 -> V_100 ) ;
if ( V_29 < 0 )
return V_29 ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
V_58 = F_43 ( V_110 , V_15 ) ;
if ( V_58 == NULL ) {
F_11 ( L_51 , V_7 ) ;
V_29 = - V_16 ;
break;
}
V_6 -> V_12 [ V_7 ] . V_58 = V_58 ;
F_9 ( L_52 , V_58 ) ;
}
if ( V_29 ) {
while ( V_7 -- ) {
F_44 ( V_6 -> V_12 [ V_7 ] . V_58 ) ;
V_6 -> V_12 [ V_7 ] . V_58 = NULL ;
}
return V_29 ;
}
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
V_58 = V_6 -> V_12 [ V_7 ] . V_58 ;
V_58 -> V_111 = 1 ;
V_58 -> V_88 = V_89 ;
V_58 -> V_112 = F_45 ( V_89 , V_6 -> V_106 ) ;
V_58 -> V_113 = V_114 ;
V_58 -> V_84 = V_6 -> V_12 [ V_7 ] . V_13 ;
V_58 -> V_115 = V_14 ;
V_58 -> V_116 = F_33 ;
V_58 -> V_63 = V_6 ;
V_58 -> V_117 = 0 ;
V_58 -> V_81 = V_110 ;
for ( V_92 = 0 ; V_92 < V_110 ; V_92 ++ ) {
V_58 -> V_82 [ V_92 ] . V_25 = V_92 * V_108 ;
V_58 -> V_82 [ V_92 ] . V_118 = V_6 -> V_101 ;
}
}
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
V_29 = F_37 ( V_6 -> V_12 [ V_7 ] . V_58 , V_15 ) ;
if ( V_29 ) {
F_11 ( L_53 , V_7 , V_29 ) ;
V_6 -> V_98 = 1 ;
F_46 ( V_6 ) ;
return V_29 ;
}
F_9 ( L_54 , V_6 -> V_12 [ V_7 ] . V_58 ) ;
}
V_6 -> V_98 = 1 ;
F_34 ( L_55 ) ;
return 0 ;
}
static void F_47 ( struct V_5 * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
struct V_58 * V_58 ;
V_58 = V_6 -> V_12 [ V_7 ] . V_58 ;
if ( V_58 ) {
F_9 ( L_56 , V_58 ) ;
F_48 ( V_58 ) ;
}
}
}
static void F_49 ( struct V_5 * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
struct V_58 * V_58 ;
V_58 = V_6 -> V_12 [ V_7 ] . V_58 ;
if ( V_58 ) {
F_9 ( L_57 ) ;
F_44 ( V_58 ) ;
V_6 -> V_12 [ V_7 ] . V_58 = NULL ;
}
}
}
void F_46 ( struct V_5 * V_6 )
{
F_34 ( L_58 ) ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_98 == 0 )
return;
F_47 ( V_6 ) ;
F_49 ( V_6 ) ;
if ( V_6 -> V_77 != V_70 ) {
F_34 ( L_59 ) ;
F_42 ( V_6 -> V_89 , 0 , 0 ) ;
}
V_6 -> V_98 = 0 ;
F_34 ( L_60 ) ;
}
static struct V_5 * F_50 ( struct V_119 * V_120 )
{
struct V_121 * V_122 = F_51 ( V_120 ) ;
return F_52 ( V_122 ) ;
}
static T_1 F_53 ( struct V_119 * V_123 ,
struct V_124 * V_125 , char * V_126 )
{
struct V_5 * V_6 = F_50 ( V_123 ) ;
return sprintf ( V_126 , L_61 , V_6 -> V_127 , V_6 -> V_128 ) ;
}
static T_1 F_54 ( struct V_119 * V_123 ,
struct V_124 * V_125 ,
const char * V_126 , T_2 V_129 )
{
struct V_5 * V_6 = F_50 ( V_123 ) ;
int V_130 , V_131 ;
int V_29 = - V_37 ;
if ( strncmp ( V_126 , L_62 , 5 ) == 0 )
V_29 = F_55 ( V_6 , 0x3 ) ;
else if ( sscanf ( V_126 , L_63 , & V_130 , & V_131 ) > 0 )
V_29 = F_56 ( V_6 , V_130 , V_131 ) ;
if ( V_29 < 0 )
return V_29 ;
return strlen ( V_126 ) ;
}
static T_1 F_57 ( struct V_119 * V_123 ,
struct V_124 * V_125 , char * V_126 )
{
struct V_5 * V_6 = F_50 ( V_123 ) ;
int V_64 = V_6 -> V_49 ;
V_6 -> V_49 = 0 ;
return sprintf ( V_126 , L_64 , V_64 ) ;
}
static int F_58 ( struct V_5 * V_6 )
{
int V_132 ;
V_132 = F_59 ( & V_6 -> V_122 . V_88 , & V_133 ) ;
if ( V_132 )
goto V_8;
if ( V_6 -> V_134 & V_135 ) {
V_132 = F_59 ( & V_6 -> V_122 . V_88 , & V_136 ) ;
if ( V_132 )
goto V_137;
}
return 0 ;
V_137:
F_60 ( & V_6 -> V_122 . V_88 , & V_133 ) ;
V_8:
F_11 ( L_65 ) ;
return V_132 ;
}
static void F_61 ( struct V_5 * V_6 )
{
if ( V_6 -> V_134 & V_135 )
F_60 ( & V_6 -> V_122 . V_88 , & V_136 ) ;
F_60 ( & V_6 -> V_122 . V_88 , & V_133 ) ;
}
static const char * F_62 ( unsigned int V_138 )
{
switch( V_138 ) {
case 0x00 :
return L_66 ;
case 0x20 :
return L_67 ;
case 0x2E :
return L_68 ;
case 0x2F :
return L_69 ;
case 0x30 :
return L_70 ;
case 0x3E :
return L_71 ;
case 0x3F :
return L_72 ;
case 0x40 :
return L_73 ;
case 0x100 :
return L_74 ;
case 0x101 :
return L_75 ;
default:
return L_76 ;
}
}
static int F_63 ( struct V_139 * V_139 )
{
int V_7 , V_29 ;
struct V_121 * V_122 = F_64 ( V_139 ) ;
struct V_5 * V_6 ;
F_34 ( L_77 , V_122 ) ;
V_6 = F_52 ( V_122 ) ;
F_65 ( ! V_6 ) ;
if ( V_6 -> V_140 ) {
F_34 ( L_78 ) ;
return - V_141 ;
}
F_66 ( V_6 ) ;
if ( ! V_6 -> V_142 ) {
F_34 ( L_79 ) ;
V_6 -> V_142 = 1 ;
V_29 = F_67 ( V_6 , & V_7 ) ;
if ( V_29 >= 0 )
{
F_34 ( L_80 ,
V_6 -> V_122 . V_143 ,
F_62 ( V_7 ) , V_7 ) ;
}
}
if ( V_144 ) {
V_7 = F_68 ( V_6 , 1 ) ;
if ( V_7 < 0 )
F_34 ( L_81 , V_7 ) ;
}
if ( F_69 ( V_6 , V_145 , V_146 ) < 0 )
F_34 ( L_82 ) ;
V_7 = F_8 ( V_6 ) ;
if ( V_7 < 0 ) {
F_34 ( L_83 ) ;
F_16 ( V_6 ) ;
return V_7 ;
}
F_21 ( V_6 ) ;
for ( V_7 = 0 ; V_7 < V_21 ; V_7 ++ )
V_6 -> V_44 [ V_7 ] = 0 ;
V_6 -> V_46 = 0 ;
V_6 -> V_45 = 0 ;
V_6 -> V_55 = 0 ;
V_6 -> V_75 = 0 ;
V_6 -> V_77 = 0 ;
F_66 ( V_6 ) ;
V_6 -> V_147 = 0 ;
V_7 = F_70 ( V_6 , V_148 [ V_6 -> V_149 ] . V_150 , V_148 [ V_6 -> V_149 ] . V_151 , V_6 -> V_152 , V_6 -> V_153 , 0 ) ;
if ( V_7 ) {
unsigned int V_154 ;
F_34 ( L_84 ) ;
if ( V_6 -> type >= 730 )
V_154 = V_155 ;
else
V_154 = V_156 ;
V_7 = F_70 ( V_6 ,
V_148 [ V_154 ] . V_150 ,
V_148 [ V_154 ] . V_151 ,
10 ,
V_6 -> V_153 ,
0 ) ;
}
if ( V_7 ) {
F_34 ( L_85 ) ;
F_16 ( V_6 ) ;
return V_7 ;
}
F_71 ( V_6 , 0x7fff ) ;
F_72 ( V_6 , 1 , 0 ) ;
V_6 -> V_140 ++ ;
V_139 -> V_157 = V_122 ;
F_34 ( L_86 ) ;
return 0 ;
}
static void F_73 ( struct V_121 * V_158 )
{
struct V_5 * V_6 = F_74 ( V_158 , struct V_5 , V_122 ) ;
int V_159 ;
for ( V_159 = 0 ; V_159 < V_160 ; V_159 ++ )
if ( V_161 [ V_159 ] . V_6 == V_6 )
V_161 [ V_159 ] . V_6 = NULL ;
F_17 ( V_6 ) ;
}
static int F_75 ( struct V_139 * V_139 )
{
struct V_121 * V_122 = V_139 -> V_157 ;
struct V_5 * V_6 ;
int V_7 ;
F_34 ( L_87 , V_122 ) ;
V_6 = F_52 ( V_122 ) ;
if ( V_6 -> V_140 == 0 )
F_76 ( L_88 ) ;
if ( V_6 -> V_46 > 20 )
F_76 ( L_89 , V_6 -> V_46 , V_6 -> V_45 , V_6 -> V_55 ) ;
if ( F_13 ( V_6 -> type ) )
F_77 () ;
else
F_78 () ;
F_46 ( V_6 ) ;
F_16 ( V_6 ) ;
if ( ! V_6 -> V_162 ) {
if ( F_69 ( V_6 , 0 , 0 ) < 0 )
F_76 ( L_82 ) ;
if ( V_144 ) {
V_7 = F_68 ( V_6 , 0 ) ;
if ( V_7 < 0 )
F_11 ( L_90 , V_7 ) ;
}
V_6 -> V_140 -- ;
F_34 ( L_91 , V_6 -> V_140 ) ;
}
return 0 ;
}
static T_1 F_79 ( struct V_139 * V_139 , char T_3 * V_126 ,
T_2 V_129 , T_4 * V_163 )
{
struct V_121 * V_122 = V_139 -> V_157 ;
struct V_5 * V_6 ;
int V_164 = V_139 -> V_165 & V_166 ;
F_80 ( V_167 , V_168 ) ;
int V_169 , V_170 = 0 ;
void * V_171 ;
F_81 ( L_92 ,
V_122 , V_126 , V_129 ) ;
if ( V_122 == NULL )
return - V_97 ;
V_6 = F_52 ( V_122 ) ;
if ( V_6 == NULL )
return - V_97 ;
if ( V_6 -> V_77 ) {
V_170 = - V_6 -> V_77 ;
goto V_172;
}
V_170 = F_38 ( V_6 ) ;
if ( V_170 )
goto V_172;
if ( V_6 -> V_42 == 0 ) {
F_82 ( & V_6 -> V_79 , & V_167 ) ;
while ( V_6 -> V_33 == NULL ) {
if ( V_6 -> V_77 ) {
F_83 ( & V_6 -> V_79 , & V_167 ) ;
F_84 ( V_173 ) ;
V_170 = - V_6 -> V_77 ;
goto V_172;
}
if ( V_164 ) {
F_83 ( & V_6 -> V_79 , & V_167 ) ;
F_84 ( V_173 ) ;
V_170 = - V_174 ;
goto V_172;
}
if ( F_85 ( V_168 ) ) {
F_83 ( & V_6 -> V_79 , & V_167 ) ;
F_84 ( V_173 ) ;
V_170 = - V_175 ;
goto V_172;
}
F_86 ( & V_6 -> V_176 ) ;
F_87 () ;
F_84 ( V_177 ) ;
F_88 ( & V_6 -> V_176 ) ;
}
F_83 ( & V_6 -> V_79 , & V_167 ) ;
F_84 ( V_173 ) ;
if ( F_22 ( V_6 ) ) {
V_170 = - V_97 ;
goto V_172;
}
}
F_81 ( L_93 ) ;
if ( V_6 -> V_178 != V_179 )
V_169 = V_6 -> V_180 + sizeof( struct V_181 ) ;
else
V_169 = V_6 -> V_182 . V_1 ;
if ( V_129 + V_6 -> V_42 > V_169 )
V_129 = V_169 - V_6 -> V_42 ;
V_171 = V_6 -> V_23 ;
V_171 += V_6 -> V_24 [ V_6 -> V_43 ] . V_25 ;
V_171 += V_6 -> V_42 ;
if ( F_89 ( V_126 , V_171 , V_129 ) ) {
V_170 = - V_97 ;
goto V_172;
}
V_6 -> V_42 += V_129 ;
if ( V_6 -> V_42 >= V_169 ) {
V_6 -> V_42 = 0 ;
F_24 ( V_6 ) ;
}
return V_129 ;
V_172:
return V_170 ;
}
static unsigned int F_90 ( struct V_139 * V_139 , T_5 * V_167 )
{
struct V_121 * V_122 = V_139 -> V_157 ;
struct V_5 * V_6 ;
int V_29 ;
if ( V_122 == NULL )
return - V_97 ;
V_6 = F_52 ( V_122 ) ;
if ( V_6 == NULL )
return - V_97 ;
V_29 = F_38 ( V_6 ) ;
if ( V_29 )
return V_29 ;
F_91 ( V_139 , & V_6 -> V_79 , V_167 ) ;
if ( V_6 -> V_77 )
return V_183 ;
if ( V_6 -> V_33 != NULL )
return ( V_184 | V_185 ) ;
return 0 ;
}
static int F_92 ( struct V_139 * V_139 , struct V_186 * V_187 )
{
struct V_121 * V_122 = V_139 -> V_157 ;
struct V_5 * V_6 ;
unsigned long V_188 ;
unsigned long V_1 ;
unsigned long V_189 , V_190 = 0 ;
int V_191 ;
F_9 ( L_94 , V_38 ) ;
V_6 = F_52 ( V_122 ) ;
V_1 = V_187 -> V_192 - V_187 -> V_193 ;
V_188 = V_187 -> V_193 ;
for ( V_191 = 0 ; V_191 < V_21 ; V_191 ++ ) {
V_190 = V_6 -> V_24 [ V_191 ] . V_25 ;
if ( ( V_190 >> V_194 ) == V_187 -> V_195 )
break;
}
if ( V_191 == V_27 )
return - V_37 ;
if ( V_191 == 0 ) {
unsigned long V_196 ;
V_196 = V_21 * V_6 -> V_22 ;
if ( V_1 != V_6 -> V_22 && V_1 != V_196 ) {
F_11 ( L_95 ,
V_1 , V_6 -> V_22 , V_196 ) ;
return - V_37 ;
}
} else if ( V_1 > V_6 -> V_22 )
return - V_37 ;
V_187 -> V_197 |= V_198 ;
V_190 += ( unsigned long ) V_6 -> V_23 ;
while ( V_1 > 0 ) {
V_189 = F_93 ( ( void * ) V_190 ) ;
if ( F_94 ( V_187 , V_188 , V_189 , V_4 , V_199 ) )
return - V_200 ;
V_188 += V_4 ;
V_190 += V_4 ;
if ( V_1 > V_4 )
V_1 -= V_4 ;
else
V_1 = 0 ;
}
return 0 ;
}
static int F_95 ( struct V_93 * V_94 , const struct V_201 * V_202 )
{
struct V_91 * V_89 = F_96 ( V_94 ) ;
struct V_5 * V_6 = NULL ;
int V_203 , V_204 , V_205 ;
int V_159 , V_132 ;
int V_134 = 0 ;
int V_206 = - 1 ;
char V_207 [ 30 ] , * V_143 ;
V_203 = F_41 ( V_89 -> V_208 . V_209 ) ;
V_204 = F_41 ( V_89 -> V_208 . V_210 ) ;
F_97 ( L_96 ,
V_203 , V_204 ,
V_94 -> V_211 -> V_102 . V_212 ) ;
if ( V_94 -> V_211 -> V_102 . V_212 > 0 )
return - V_213 ;
if ( V_203 == 0x0471 ) {
switch ( V_204 ) {
case 0x0302 :
F_35 ( L_97 ) ;
V_143 = L_98 ;
V_205 = 645 ;
break;
case 0x0303 :
F_35 ( L_99 ) ;
V_143 = L_100 ;
V_205 = 646 ;
break;
case 0x0304 :
F_35 ( L_101 ) ;
V_143 = L_102 ;
V_205 = 646 ;
break;
case 0x0307 :
F_35 ( L_103 ) ;
V_143 = L_104 ;
V_205 = 675 ;
break;
case 0x0308 :
F_35 ( L_105 ) ;
V_143 = L_106 ;
V_205 = 680 ;
break;
case 0x030C :
F_35 ( L_107 ) ;
V_143 = L_108 ;
V_205 = 690 ;
break;
case 0x0310 :
F_35 ( L_109 ) ;
V_143 = L_110 ;
V_205 = 730 ;
break;
case 0x0311 :
F_35 ( L_111 ) ;
V_143 = L_112 ;
V_205 = 740 ;
break;
case 0x0312 :
F_35 ( L_113 ) ;
V_143 = L_114 ;
V_205 = 750 ;
break;
case 0x0313 :
F_35 ( L_115 ) ;
V_143 = L_116 ;
V_205 = 720 ;
break;
case 0x0329 :
F_35 ( L_117 ) ;
V_143 = L_118 ;
V_205 = 740 ;
break;
default:
return - V_213 ;
break;
}
}
else if ( V_203 == 0x069A ) {
switch( V_204 ) {
case 0x0001 :
F_35 ( L_119 ) ;
V_143 = L_102 ;
V_205 = 645 ;
break;
default:
return - V_213 ;
break;
}
}
else if ( V_203 == 0x046d ) {
switch( V_204 ) {
case 0x08b0 :
F_35 ( L_120 ) ;
V_143 = L_121 ;
V_205 = 740 ;
break;
case 0x08b1 :
F_35 ( L_122 ) ;
V_143 = L_123 ;
V_205 = 740 ;
break;
case 0x08b2 :
F_35 ( L_124 ) ;
V_143 = L_125 ;
V_205 = 740 ;
break;
case 0x08b3 :
F_35 ( L_126 ) ;
V_143 = L_127 ;
V_205 = 740 ;
break;
case 0x08B4 :
F_35 ( L_128 ) ;
V_143 = L_127 ;
V_205 = 740 ;
V_144 = 1 ;
break;
case 0x08b5 :
F_35 ( L_129 ) ;
V_143 = L_130 ;
V_205 = 740 ;
V_134 |= V_135 ;
break;
case 0x08b6 :
F_35 ( L_131 ) ;
V_143 = L_132 ;
V_205 = 740 ;
break;
case 0x08b7 :
F_35 ( L_133 ) ;
V_143 = L_134 ;
V_205 = 740 ;
break;
case 0x08b8 :
F_35 ( L_135 ) ;
V_143 = L_136 ;
V_205 = 730 ;
break;
default:
return - V_213 ;
break;
}
}
else if ( V_203 == 0x055d ) {
switch( V_204 ) {
case 0x9000 :
F_35 ( L_137 ) ;
V_143 = L_138 ;
V_205 = 675 ;
break;
case 0x9001 :
F_35 ( L_139 ) ;
V_143 = L_140 ;
V_205 = 675 ;
break;
case 0x9002 :
F_35 ( L_141 ) ;
V_143 = L_140 ;
V_205 = 740 ;
break;
default:
return - V_213 ;
break;
}
}
else if ( V_203 == 0x041e ) {
switch( V_204 ) {
case 0x400c :
F_35 ( L_142 ) ;
V_143 = L_143 ;
V_205 = 730 ;
break;
case 0x4011 :
F_35 ( L_144 ) ;
V_143 = L_145 ;
V_205 = 740 ;
break;
default:
return - V_213 ;
break;
}
}
else if ( V_203 == 0x04cc ) {
switch( V_204 ) {
case 0x8116 :
F_35 ( L_146 ) ;
V_143 = L_147 ;
V_205 = 730 ;
break;
default:
return - V_213 ;
break;
}
}
else if ( V_203 == 0x06be ) {
switch( V_204 ) {
case 0x8116 :
F_35 ( L_148 ) ;
V_143 = L_149 ;
V_205 = 750 ;
break;
default:
return - V_213 ;
break;
}
}
else if ( V_203 == 0x0d81 ) {
switch( V_204 ) {
case 0x1900 :
F_35 ( L_150 ) ;
V_143 = L_151 ;
V_205 = 740 ;
break;
case 0x1910 :
F_35 ( L_152 ) ;
V_143 = L_153 ;
V_205 = 730 ;
break;
default:
return - V_213 ;
break;
}
}
else
return - V_213 ;
memset ( V_207 , 0 , 30 ) ;
F_98 ( V_89 , V_89 -> V_208 . V_214 , V_207 , 29 ) ;
F_97 ( L_154 , V_207 ) ;
if ( V_89 -> V_208 . V_215 > 1 )
F_99 ( L_155 ) ;
V_6 = F_10 ( sizeof( struct V_5 ) , V_15 ) ;
if ( V_6 == NULL ) {
F_11 ( L_156 ) ;
return - V_16 ;
}
V_6 -> type = V_205 ;
V_6 -> V_149 = V_216 ;
V_6 -> V_152 = V_217 ;
strcpy ( V_6 -> V_218 , V_207 ) ;
V_6 -> V_134 = V_134 ;
if ( V_203 == 0x046D && V_204 == 0x08B5 ) {
V_6 -> V_219 . V_220 = - 7000 ;
V_6 -> V_219 . V_221 = 7000 ;
V_6 -> V_219 . V_222 = - 3000 ;
V_6 -> V_219 . V_223 = 2500 ;
}
F_100 ( & V_6 -> V_176 ) ;
F_101 ( & V_6 -> V_31 ) ;
V_6 -> V_89 = V_89 ;
F_102 ( & V_6 -> V_79 ) ;
V_6 -> V_153 = V_224 ;
memcpy ( & V_6 -> V_122 , & V_225 , sizeof( V_225 ) ) ;
V_6 -> V_122 . V_226 = & V_94 -> V_88 ;
V_6 -> V_122 . V_227 = & V_6 -> V_176 ;
strcpy ( V_6 -> V_122 . V_143 , V_143 ) ;
F_103 ( & V_6 -> V_122 , V_6 ) ;
V_6 -> V_228 = F_41 ( V_89 -> V_208 . V_229 ) ;
F_97 ( L_157 , V_6 -> V_228 ) ;
for ( V_159 = 0 ; V_159 < V_160 ; V_159 ++ ) {
if ( ( ( V_161 [ V_159 ] . type == - 1 ) || ( V_161 [ V_159 ] . type == V_6 -> type ) ) &&
( V_161 [ V_159 ] . V_6 == NULL ) ) {
if ( ( V_161 [ V_159 ] . V_207 [ 0 ] == '*' ) || ! strcmp ( V_161 [ V_159 ] . V_207 , V_207 ) ) {
V_206 = V_161 [ V_159 ] . V_230 ;
F_97 ( L_158 , V_206 ) ;
break;
}
}
}
if ( V_159 < V_160 )
V_161 [ V_159 ] . V_6 = V_6 ;
F_97 ( L_159 , V_6 ) ;
F_104 ( V_94 , V_6 ) ;
F_69 ( V_6 , 0 , 0 ) ;
F_68 ( V_6 , 0 ) ;
V_132 = F_105 ( & V_6 -> V_122 , V_231 , V_206 ) ;
if ( V_132 < 0 ) {
F_11 ( L_160 , V_132 ) ;
goto V_232;
}
V_132 = F_58 ( V_6 ) ;
if ( V_132 )
goto V_233;
F_35 ( L_161 , F_106 ( & V_6 -> V_122 ) ) ;
#ifdef F_29
V_6 -> V_50 = F_107 () ;
if ( ! V_6 -> V_50 ) {
F_11 ( L_162 ) ;
V_132 = - V_16 ;
F_61 ( V_6 ) ;
goto V_233;
}
F_108 ( V_89 , V_6 -> V_234 , sizeof( V_6 -> V_234 ) ) ;
F_109 ( V_6 -> V_234 , L_163 , sizeof( V_6 -> V_234 ) ) ;
V_6 -> V_50 -> V_143 = L_164 ;
V_6 -> V_50 -> V_235 = V_6 -> V_234 ;
F_110 ( V_6 -> V_89 , & V_6 -> V_50 -> V_202 ) ;
V_6 -> V_50 -> V_88 . V_226 = & V_6 -> V_89 -> V_88 ;
V_6 -> V_50 -> V_236 [ 0 ] = F_111 ( V_237 ) ;
V_6 -> V_50 -> V_238 [ F_112 ( V_51 ) ] = F_111 ( V_51 ) ;
V_132 = F_113 ( V_6 -> V_50 ) ;
if ( V_132 ) {
F_114 ( V_6 -> V_50 ) ;
V_6 -> V_50 = NULL ;
F_61 ( V_6 ) ;
goto V_233;
}
#endif
return 0 ;
V_233:
if ( V_159 < V_160 )
V_161 [ V_159 ] . V_6 = NULL ;
F_115 ( & V_6 -> V_122 ) ;
V_232:
F_17 ( V_6 ) ;
return V_132 ;
}
static void F_116 ( struct V_93 * V_94 )
{
struct V_5 * V_6 = F_117 ( V_94 ) ;
F_88 ( & V_6 -> V_176 ) ;
F_104 ( V_94 , NULL ) ;
if ( V_6 == NULL ) {
F_11 ( L_165 ) ;
goto V_239;
}
if ( V_6 -> V_89 == NULL ) {
F_11 ( L_166 , V_6 ) ;
goto V_239;
}
if ( V_6 -> V_89 != F_96 ( V_94 ) ) {
F_11 ( L_167 ) ;
goto V_239;
}
V_6 -> V_77 = V_70 ;
V_6 -> V_162 = 1 ;
F_36 ( & V_6 -> V_79 ) ;
F_46 ( V_6 ) ;
V_239:
F_86 ( & V_6 -> V_176 ) ;
F_61 ( V_6 ) ;
F_115 ( & V_6 -> V_122 ) ;
#ifdef F_29
if ( V_6 -> V_50 )
F_118 ( V_6 -> V_50 ) ;
#endif
}
static int T_6 F_119 ( void )
{
int V_7 , V_240 ;
char * V_241 [ V_242 ] = { L_168 , L_169 , L_170 , L_171 , L_172 , L_173 } ;
F_35 ( L_174 V_243 L_175 ) ;
F_35 ( L_176 ) ;
F_35 ( L_177 ) ;
F_35 ( L_178 ) ;
if ( V_244 ) {
if ( V_244 < 4 || V_244 > 30 ) {
F_11 ( L_179 ) ;
return - V_37 ;
}
V_217 = V_244 ;
F_76 ( L_180 , V_217 ) ;
}
if ( V_1 ) {
for ( V_240 = 0 ; V_240 < V_242 ; V_240 ++ ) {
if ( ! strcmp ( V_241 [ V_240 ] , V_1 ) ) {
V_216 = V_240 ;
break;
}
}
if ( V_240 == V_242 ) {
F_11 ( L_181 ) ;
return - V_37 ;
}
F_76 ( L_182 , V_241 [ V_216 ] , V_148 [ V_216 ] . V_150 , V_148 [ V_216 ] . V_151 ) ;
}
if ( V_245 ) {
if ( V_245 < 1 || V_245 > V_27 ) {
F_11 ( L_183 , V_27 ) ;
return - V_37 ;
}
V_21 = V_245 ;
F_76 ( L_184 , V_21 ) ;
}
if ( V_246 ) {
if ( V_246 < 2 || V_246 > V_247 ) {
F_11 ( L_185 , V_247 ) ;
return - V_37 ;
}
V_18 = V_246 ;
F_76 ( L_186 , V_18 ) ;
}
#ifdef F_120
if ( V_248 >= 0 ) {
F_76 ( L_187 , V_248 ) ;
}
#endif
if ( V_249 >= 0 ) {
if ( V_249 > 3 ) {
F_11 ( L_188 ) ;
return - V_37 ;
}
V_224 = V_249 ;
F_76 ( L_189 , V_224 ) ;
}
if ( V_144 )
F_76 ( L_190 ) ;
if ( V_250 [ 0 ] >= 0 )
V_145 = V_250 [ 0 ] ;
if ( V_250 [ 1 ] >= 0 )
V_146 = V_250 [ 1 ] ;
for ( V_7 = 0 ; V_7 < V_160 ; V_7 ++ ) {
char * V_251 , * V_252 , * V_253 ;
V_161 [ V_7 ] . V_6 = NULL ;
V_251 = V_254 [ V_7 ] ;
if ( V_251 != NULL && * V_251 != '\0' ) {
V_161 [ V_7 ] . type = - 1 ;
strcpy ( V_161 [ V_7 ] . V_207 , L_191 ) ;
V_252 = V_253 = V_251 ;
while ( * V_252 != '\0' && * V_252 != ':' )
V_252 ++ ;
while ( * V_253 != '\0' && * V_253 != '.' )
V_253 ++ ;
if ( * V_253 != '\0' && V_253 > V_252 ) {
F_11 ( L_192 ) ;
return - V_37 ;
}
if ( * V_252 == '\0' ) {
if ( * V_253 != '\0' ) {
F_11 ( L_193 ) ;
return - V_37 ;
}
else {
V_161 [ V_7 ] . V_230 =
F_121 ( V_251 , NULL , 10 ) ;
}
}
else {
V_161 [ V_7 ] . type =
F_121 ( V_251 , NULL , 10 ) ;
V_161 [ V_7 ] . V_230 =
F_121 ( V_252 + 1 , NULL , 10 ) ;
if ( * V_253 != '\0' ) {
int V_255 ;
V_253 ++ ;
V_255 = 0 ;
while ( * V_253 != ':' && V_255 < 29 ) {
V_161 [ V_7 ] . V_207 [ V_255 ++ ] = * V_253 ;
V_253 ++ ;
}
V_161 [ V_7 ] . V_207 [ V_255 ] = '\0' ;
}
}
F_28 ( L_194 , V_7 ) ;
F_28 ( L_195 , V_161 [ V_7 ] . type ) ;
F_28 ( L_196 , V_161 [ V_7 ] . V_207 ) ;
F_28 ( L_197 , V_161 [ V_7 ] . V_230 ) ;
}
else
V_161 [ V_7 ] . type = 0 ;
}
F_97 ( L_198 , & V_256 ) ;
return F_122 ( & V_256 ) ;
}
static void T_7 F_123 ( void )
{
F_76 ( L_199 ) ;
F_124 ( & V_256 ) ;
F_35 ( L_200 ) ;
}
