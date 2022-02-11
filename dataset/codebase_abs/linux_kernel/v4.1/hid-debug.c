static char * F_1 ( unsigned V_1 , struct V_2 * V_3 ) {
const struct V_4 * V_5 ;
char * V_6 = NULL ;
if ( ! V_3 ) {
V_6 = F_2 ( sizeof( char ) * V_7 , V_8 ) ;
if ( ! V_6 )
return F_3 ( - V_9 ) ;
}
for ( V_5 = V_10 ; V_5 -> V_11 ; V_5 ++ )
if ( V_5 -> V_1 == V_1 ) {
if ( ! V_3 ) {
snprintf ( V_6 , V_7 , L_1 ,
V_5 -> V_11 ) ;
return V_6 ;
}
else {
F_4 ( V_3 , L_1 , V_5 -> V_11 ) ;
return NULL ;
}
}
if ( ! V_3 )
snprintf ( V_6 , V_7 , L_2 , V_1 ) ;
else
F_4 ( V_3 , L_2 , V_1 ) ;
return V_6 ;
}
char * F_5 ( unsigned V_12 , struct V_2 * V_3 ) {
const struct V_4 * V_5 ;
char * V_6 = NULL ;
int V_13 = 0 ;
V_6 = F_1 ( V_12 >> 16 , V_3 ) ;
if ( F_6 ( V_6 ) ) {
F_7 ( L_3 ) ;
return NULL ;
}
if ( ! V_3 ) {
V_13 = strlen ( V_6 ) ;
snprintf ( V_6 + V_13 , F_8 ( 0 , V_7 - V_13 ) , L_4 ) ;
V_13 ++ ;
}
else {
F_4 ( V_3 , L_4 ) ;
}
for ( V_5 = V_10 ; V_5 -> V_11 ; V_5 ++ )
if ( V_5 -> V_1 == ( V_12 >> 16 ) ) {
for( ++ V_5 ; V_5 -> V_11 && V_5 -> V_12 != 0 ; V_5 ++ )
if ( V_5 -> V_12 == ( V_12 & 0xffff ) ) {
if ( ! V_3 )
snprintf ( V_6 + V_13 ,
F_8 ( 0 , V_7 - V_13 - 1 ) ,
L_1 , V_5 -> V_11 ) ;
else
F_4 ( V_3 ,
L_1 ,
V_5 -> V_11 ) ;
return V_6 ;
}
break;
}
if ( ! V_3 )
snprintf ( V_6 + V_13 , F_8 ( 0 , V_7 - V_13 - 1 ) ,
L_2 , V_12 & 0xffff ) ;
else
F_4 ( V_3 , L_2 , V_12 & 0xffff ) ;
return V_6 ;
}
static void F_9 ( int V_14 , struct V_2 * V_3 ) {
F_4 ( V_3 , L_5 , V_14 , L_6 ) ;
}
void F_10 ( struct V_15 * V_16 , int V_14 , struct V_2 * V_3 ) {
int V_17 ;
if ( V_16 -> V_18 ) {
F_9 ( V_14 , V_3 ) ;
F_4 ( V_3 , L_7 ) ;
F_5 ( V_16 -> V_18 , V_3 ) ; F_4 ( V_3 , L_8 ) ;
}
if ( V_16 -> V_19 ) {
F_9 ( V_14 , V_3 ) ;
F_4 ( V_3 , L_9 ) ;
F_5 ( V_16 -> V_19 , V_3 ) ; F_4 ( V_3 , L_8 ) ;
}
if ( V_16 -> V_20 ) {
F_9 ( V_14 , V_3 ) ;
F_4 ( V_3 , L_10 ) ;
F_5 ( V_16 -> V_20 , V_3 ) ; F_4 ( V_3 , L_8 ) ;
}
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_11 , V_16 -> V_21 ) ;
for ( V_17 = 0 ; V_17 < V_16 -> V_21 ; V_17 ++ ) {
F_9 ( V_14 + 2 , V_3 ) ; F_5 ( V_16 -> V_12 [ V_17 ] . V_22 , V_3 ) ; F_4 ( V_3 , L_12 ) ;
}
if ( V_16 -> V_23 != V_16 -> V_24 ) {
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_13 , V_16 -> V_23 ) ;
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_14 , V_16 -> V_24 ) ;
}
if ( V_16 -> V_25 != V_16 -> V_26 ) {
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_15 , V_16 -> V_25 ) ;
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_16 , V_16 -> V_26 ) ;
}
if ( V_16 -> V_27 ) {
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_17 , V_16 -> V_27 ) ;
}
if ( V_16 -> V_28 ) {
static const char * V_29 [ 5 ] = { L_18 , L_19 , L_20 , L_21 , L_22 } ;
static const char * V_30 [ 5 ] [ 8 ] = {
{ L_18 , L_18 , L_18 , L_18 , L_18 , L_18 , L_18 , L_18 } ,
{ L_18 , L_23 , L_24 , L_25 , L_26 , L_27 , L_28 , L_18 } ,
{ L_18 , L_29 , L_24 , L_25 , L_26 , L_27 , L_28 , L_18 } ,
{ L_18 , L_30 , L_31 , L_25 , L_32 , L_27 , L_28 , L_18 } ,
{ L_18 , L_33 , L_31 , L_25 , L_32 , L_27 , L_28 , L_18 }
} ;
int V_31 ;
int V_32 ;
T_1 V_33 = V_16 -> V_28 ;
V_32 = V_33 & 0xf ;
V_33 >>= 4 ;
if( V_32 > 4 ) {
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_34 ) ;
}
else {
int V_34 = 0 ;
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_35 , V_29 [ V_32 ] ) ;
for ( V_31 = 1 ; V_31 < sizeof( T_1 ) * 2 ; V_31 ++ ) {
char V_35 = V_33 & 0xf ;
V_33 >>= 4 ;
if ( V_35 != 0 ) {
if( V_34 ++ > 0 )
F_4 ( V_3 , L_36 ) ;
F_4 ( V_3 , L_1 , V_30 [ V_32 ] [ V_31 ] ) ;
if( V_35 != 1 ) {
int V_36 = V_35 & 0x7 ;
if( V_35 & 0x08 )
V_36 = - ( ( 0x7 & ~ V_36 ) + 1 ) ;
F_4 ( V_3 , L_37 , V_36 ) ;
}
}
}
F_4 ( V_3 , L_8 ) ;
}
}
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_38 , V_16 -> V_37 ) ;
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_39 , V_16 -> V_38 ) ;
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_40 , V_16 -> V_39 ) ;
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_41 ) ;
V_17 = V_16 -> V_40 ;
F_4 ( V_3 , L_1 , V_41 & V_17 ? L_42 : L_6 ) ;
F_4 ( V_3 , L_1 , V_42 & V_17 ? L_43 : L_44 ) ;
F_4 ( V_3 , L_1 , V_43 & V_17 ? L_45 : L_46 ) ;
F_4 ( V_3 , L_1 , V_44 & V_17 ? L_47 : L_6 ) ;
F_4 ( V_3 , L_1 , V_45 & V_17 ? L_48 : L_6 ) ;
F_4 ( V_3 , L_1 , V_46 & V_17 ? L_49 : L_6 ) ;
F_4 ( V_3 , L_1 , V_47 & V_17 ? L_50 : L_6 ) ;
F_4 ( V_3 , L_1 , V_48 & V_17 ? L_51 : L_6 ) ;
F_4 ( V_3 , L_1 , V_49 & V_17 ? L_52 : L_6 ) ;
F_4 ( V_3 , L_8 ) ;
}
void F_11 ( struct V_50 * V_51 , struct V_2 * V_3 )
{
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
unsigned V_31 , V_58 ;
static const char * V_59 [] = { L_53 , L_54 , L_55 } ;
for ( V_31 = 0 ; V_31 < V_60 ; V_31 ++ ) {
V_53 = V_51 -> V_53 + V_31 ;
V_57 = V_53 -> V_61 . V_62 ;
while ( V_57 != & V_53 -> V_61 ) {
V_55 = (struct V_54 * ) V_57 ;
F_9 ( 2 , V_3 ) ;
F_4 ( V_3 , L_1 , V_59 [ V_31 ] ) ;
if ( V_55 -> V_63 )
F_4 ( V_3 , L_56 , V_55 -> V_63 ) ;
F_4 ( V_3 , L_57 , V_59 [ V_55 -> type ] ) ;
F_4 ( V_3 , L_12 ) ;
for ( V_58 = 0 ; V_58 < V_55 -> V_64 ; V_58 ++ ) {
F_9 ( 4 , V_3 ) ;
F_4 ( V_3 , L_58 , V_58 ) ;
F_10 ( V_55 -> V_16 [ V_58 ] , 6 , V_3 ) ;
}
V_57 = V_57 -> V_62 ;
}
}
}
void F_12 ( struct V_50 * V_65 , char * V_6 )
{
int V_31 ;
struct V_66 * V_57 ;
unsigned long V_40 ;
F_13 ( & V_65 -> V_67 , V_40 ) ;
F_14 (list, &hdev->debug_list, node) {
for ( V_31 = 0 ; V_31 < strlen ( V_6 ) ; V_31 ++ )
V_57 -> V_68 [ ( V_57 -> V_69 + V_31 ) % V_7 ] =
V_6 [ V_31 ] ;
V_57 -> V_69 = ( V_57 -> V_69 + V_31 ) % V_7 ;
}
F_15 ( & V_65 -> V_67 , V_40 ) ;
F_16 ( & V_65 -> V_70 ) ;
}
void F_17 ( struct V_50 * V_22 , int type , T_2 * V_33 ,
int V_71 )
{
struct V_52 * V_53 ;
char * V_6 ;
unsigned int V_31 ;
V_6 = F_18 ( sizeof( char ) * V_7 , V_8 ) ;
if ( ! V_6 )
return;
V_53 = V_22 -> V_53 + type ;
snprintf ( V_6 , V_7 - 1 ,
L_59 , V_71 ,
V_53 -> V_72 ? L_6 : L_60 ) ;
F_12 ( V_22 , V_6 ) ;
for ( V_31 = 0 ; V_31 < V_71 ; V_31 ++ ) {
snprintf ( V_6 , V_7 - 1 ,
L_61 , V_33 [ V_31 ] ) ;
F_12 ( V_22 , V_6 ) ;
}
F_12 ( V_22 , L_12 ) ;
F_19 ( V_6 ) ;
}
void F_20 ( struct V_50 * V_65 , struct V_73 * V_12 , T_3 V_74 )
{
char * V_6 ;
int V_13 ;
V_6 = F_5 ( V_12 -> V_22 , NULL ) ;
if ( ! V_6 )
return;
V_13 = strlen ( V_6 ) ;
snprintf ( V_6 + V_13 , V_7 - V_13 - 1 , L_62 , V_74 ) ;
F_12 ( V_65 , V_6 ) ;
F_19 ( V_6 ) ;
F_16 ( & V_65 -> V_70 ) ;
}
static void F_21 ( T_4 type , T_5 V_75 , struct V_2 * V_3 )
{
F_4 ( V_3 , L_63 , V_76 [ type ] ? V_76 [ type ] : L_64 ,
V_77 [ type ] ? ( V_77 [ type ] [ V_75 ] ? V_77 [ type ] [ V_75 ] : L_64 ) : L_64 ) ;
}
static void F_22 ( struct V_50 * V_22 , struct V_2 * V_3 )
{
int V_31 , V_17 , V_58 ;
struct V_54 * V_55 ;
struct V_73 * V_12 ;
for ( V_58 = V_78 ; V_58 <= V_79 ; V_58 ++ ) {
F_14 (report, &hid->report_enum[k].report_list, list) {
for ( V_31 = 0 ; V_31 < V_55 -> V_64 ; V_31 ++ ) {
for ( V_17 = 0 ; V_17 < V_55 -> V_16 [ V_31 ] -> V_21 ; V_17 ++ ) {
V_12 = V_55 -> V_16 [ V_31 ] -> V_12 + V_17 ;
F_5 ( V_12 -> V_22 , V_3 ) ;
F_4 ( V_3 , L_65 ) ;
F_21 ( V_12 -> type , V_12 -> V_75 , V_3 ) ;
F_4 ( V_3 , L_12 ) ;
}
}
}
}
}
static int F_23 ( struct V_2 * V_3 , void * V_5 )
{
struct V_50 * V_65 = V_3 -> V_80 ;
const T_4 * V_81 = V_65 -> V_81 ;
unsigned V_82 = V_65 -> V_82 ;
int V_31 ;
if ( ! V_81 ) {
V_81 = V_65 -> V_83 ;
V_82 = V_65 -> V_84 ;
}
for ( V_31 = 0 ; V_31 < V_82 ; V_31 ++ )
F_4 ( V_3 , L_66 , V_81 [ V_31 ] ) ;
F_4 ( V_3 , L_67 ) ;
F_11 ( V_65 , V_3 ) ;
F_4 ( V_3 , L_12 ) ;
F_22 ( V_65 , V_3 ) ;
return 0 ;
}
static int F_24 ( struct V_85 * V_85 , struct V_86 * V_86 )
{
return F_25 ( V_86 , F_23 , V_85 -> V_87 ) ;
}
static int F_26 ( struct V_85 * V_85 , struct V_86 * V_86 )
{
int V_88 = 0 ;
struct V_66 * V_57 ;
unsigned long V_40 ;
if ( ! ( V_57 = F_2 ( sizeof( struct V_66 ) , V_89 ) ) ) {
V_88 = - V_9 ;
goto V_90;
}
if ( ! ( V_57 -> V_68 = F_2 ( sizeof( char ) * V_7 , V_89 ) ) ) {
V_88 = - V_9 ;
F_19 ( V_57 ) ;
goto V_90;
}
V_57 -> V_65 = (struct V_50 * ) V_85 -> V_87 ;
V_86 -> V_91 = V_57 ;
F_27 ( & V_57 -> V_92 ) ;
F_13 ( & V_57 -> V_65 -> V_67 , V_40 ) ;
F_28 ( & V_57 -> V_93 , & V_57 -> V_65 -> V_94 ) ;
F_15 ( & V_57 -> V_65 -> V_67 , V_40 ) ;
V_90:
return V_88 ;
}
static T_6 F_29 ( struct V_86 * V_86 , char T_7 * V_95 ,
T_8 V_96 , T_9 * V_97 )
{
struct V_66 * V_57 = V_86 -> V_91 ;
int V_98 = 0 , V_13 ;
F_30 ( V_99 , V_100 ) ;
F_31 ( & V_57 -> V_92 ) ;
while ( V_98 == 0 ) {
if ( V_57 -> V_101 == V_57 -> V_69 ) {
F_32 ( & V_57 -> V_65 -> V_70 , & V_99 ) ;
F_33 ( V_102 ) ;
while ( V_57 -> V_101 == V_57 -> V_69 ) {
if ( V_86 -> V_103 & V_104 ) {
V_98 = - V_105 ;
break;
}
if ( F_34 ( V_100 ) ) {
V_98 = - V_106 ;
break;
}
if ( ! V_57 -> V_65 || ! V_57 -> V_65 -> V_107 ) {
V_98 = - V_108 ;
F_33 ( V_109 ) ;
goto V_90;
}
F_35 ( & V_57 -> V_92 ) ;
F_36 () ;
F_31 ( & V_57 -> V_92 ) ;
F_33 ( V_102 ) ;
}
F_33 ( V_109 ) ;
F_37 ( & V_57 -> V_65 -> V_70 , & V_99 ) ;
}
if ( V_98 )
goto V_90;
V_110:
if ( V_57 -> V_69 == V_57 -> V_101 )
goto V_90;
if ( V_57 -> V_69 > V_57 -> V_101 ) {
V_13 = V_57 -> V_69 - V_57 -> V_101 ;
if ( F_38 ( V_95 + V_98 , & V_57 -> V_68 [ V_57 -> V_101 ] , V_13 ) ) {
V_98 = - V_111 ;
goto V_90;
}
V_98 += V_13 ;
V_57 -> V_101 += V_13 ;
} else {
V_13 = V_7 - V_57 -> V_101 ;
if ( F_38 ( V_95 , & V_57 -> V_68 [ V_57 -> V_101 ] , V_13 ) ) {
V_98 = - V_111 ;
goto V_90;
}
V_57 -> V_101 = 0 ;
V_98 += V_13 ;
goto V_110;
}
}
V_90:
F_35 ( & V_57 -> V_92 ) ;
return V_98 ;
}
static unsigned int F_39 ( struct V_86 * V_86 , T_10 * V_99 )
{
struct V_66 * V_57 = V_86 -> V_91 ;
F_40 ( V_86 , & V_57 -> V_65 -> V_70 , V_99 ) ;
if ( V_57 -> V_101 != V_57 -> V_69 )
return V_112 | V_113 ;
if ( ! V_57 -> V_65 -> V_107 )
return V_114 | V_115 ;
return 0 ;
}
static int F_41 ( struct V_85 * V_85 , struct V_86 * V_86 )
{
struct V_66 * V_57 = V_86 -> V_91 ;
unsigned long V_40 ;
F_13 ( & V_57 -> V_65 -> V_67 , V_40 ) ;
F_42 ( & V_57 -> V_93 ) ;
F_15 ( & V_57 -> V_65 -> V_67 , V_40 ) ;
F_19 ( V_57 -> V_68 ) ;
F_19 ( V_57 ) ;
return 0 ;
}
void F_43 ( struct V_50 * V_65 , const char * V_116 )
{
V_65 -> V_117 = F_44 ( V_116 , V_118 ) ;
V_65 -> V_119 = F_45 ( L_68 , 0400 ,
V_65 -> V_117 , V_65 , & V_120 ) ;
V_65 -> V_121 = F_45 ( L_69 , 0400 ,
V_65 -> V_117 , V_65 , & V_122 ) ;
V_65 -> V_107 = 1 ;
}
void F_46 ( struct V_50 * V_65 )
{
V_65 -> V_107 = 0 ;
F_16 ( & V_65 -> V_70 ) ;
F_47 ( V_65 -> V_119 ) ;
F_47 ( V_65 -> V_121 ) ;
F_47 ( V_65 -> V_117 ) ;
}
void F_48 ( void )
{
V_118 = F_44 ( L_70 , NULL ) ;
}
void F_49 ( void )
{
F_50 ( V_118 ) ;
}
