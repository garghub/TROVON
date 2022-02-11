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
F_13 (list, &hdev->debug_list, node) {
for ( V_31 = 0 ; V_31 < strlen ( V_6 ) ; V_31 ++ )
V_57 -> V_67 [ ( V_57 -> V_68 + V_31 ) % V_7 ] =
V_6 [ V_31 ] ;
V_57 -> V_68 = ( V_57 -> V_68 + V_31 ) % V_7 ;
}
F_14 ( & V_65 -> V_69 ) ;
}
void F_15 ( struct V_50 * V_65 , struct V_70 * V_12 , T_2 V_71 )
{
char * V_6 ;
int V_13 ;
V_6 = F_5 ( V_12 -> V_22 , NULL ) ;
if ( ! V_6 )
return;
V_13 = strlen ( V_6 ) ;
snprintf ( V_6 + V_13 , V_7 - V_13 - 1 , L_59 , V_71 ) ;
F_12 ( V_65 , V_6 ) ;
F_16 ( V_6 ) ;
F_14 ( & V_65 -> V_69 ) ;
}
static void F_17 ( T_3 type , T_4 V_72 , struct V_2 * V_3 )
{
F_4 ( V_3 , L_60 , V_73 [ type ] ? V_73 [ type ] : L_61 ,
V_74 [ type ] ? ( V_74 [ type ] [ V_72 ] ? V_74 [ type ] [ V_72 ] : L_61 ) : L_61 ) ;
}
static void F_18 ( struct V_50 * V_22 , struct V_2 * V_3 )
{
int V_31 , V_17 , V_58 ;
struct V_54 * V_55 ;
struct V_70 * V_12 ;
for ( V_58 = V_75 ; V_58 <= V_76 ; V_58 ++ ) {
F_13 (report, &hid->report_enum[k].report_list, list) {
for ( V_31 = 0 ; V_31 < V_55 -> V_64 ; V_31 ++ ) {
for ( V_17 = 0 ; V_17 < V_55 -> V_16 [ V_31 ] -> V_21 ; V_17 ++ ) {
V_12 = V_55 -> V_16 [ V_31 ] -> V_12 + V_17 ;
F_5 ( V_12 -> V_22 , V_3 ) ;
F_4 ( V_3 , L_62 ) ;
F_17 ( V_12 -> type , V_12 -> V_72 , V_3 ) ;
F_4 ( V_3 , L_12 ) ;
}
}
}
}
}
static int F_19 ( struct V_2 * V_3 , void * V_5 )
{
struct V_50 * V_65 = V_3 -> V_77 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_65 -> V_78 ; V_31 ++ )
F_4 ( V_3 , L_63 , V_65 -> V_79 [ V_31 ] ) ;
F_4 ( V_3 , L_64 ) ;
F_11 ( V_65 , V_3 ) ;
F_4 ( V_3 , L_12 ) ;
F_18 ( V_65 , V_3 ) ;
return 0 ;
}
static int F_20 ( struct V_80 * V_80 , struct V_81 * V_81 )
{
return F_21 ( V_81 , F_19 , V_80 -> V_82 ) ;
}
static int F_22 ( struct V_80 * V_80 , struct V_81 * V_81 )
{
int V_83 = 0 ;
struct V_66 * V_57 ;
if ( ! ( V_57 = F_2 ( sizeof( struct V_66 ) , V_84 ) ) ) {
V_83 = - V_9 ;
goto V_85;
}
if ( ! ( V_57 -> V_67 = F_2 ( sizeof( char ) * V_7 , V_84 ) ) ) {
V_83 = - V_9 ;
F_16 ( V_57 ) ;
goto V_85;
}
V_57 -> V_65 = (struct V_50 * ) V_80 -> V_82 ;
V_81 -> V_86 = V_57 ;
F_23 ( & V_57 -> V_87 ) ;
F_24 ( & V_57 -> V_88 , & V_57 -> V_65 -> V_89 ) ;
V_85:
return V_83 ;
}
static T_5 F_25 ( struct V_81 * V_81 , char T_6 * V_90 ,
T_7 V_91 , T_8 * V_92 )
{
struct V_66 * V_57 = V_81 -> V_86 ;
int V_93 = 0 , V_13 ;
F_26 ( V_94 , V_95 ) ;
F_27 ( & V_57 -> V_87 ) ;
while ( V_93 == 0 ) {
if ( V_57 -> V_96 == V_57 -> V_68 ) {
F_28 ( & V_57 -> V_65 -> V_69 , & V_94 ) ;
F_29 ( V_97 ) ;
while ( V_57 -> V_96 == V_57 -> V_68 ) {
if ( V_81 -> V_98 & V_99 ) {
V_93 = - V_100 ;
break;
}
if ( F_30 ( V_95 ) ) {
V_93 = - V_101 ;
break;
}
if ( ! V_57 -> V_65 || ! V_57 -> V_65 -> V_102 ) {
V_93 = - V_103 ;
break;
}
F_31 ( & V_57 -> V_87 ) ;
F_32 () ;
F_27 ( & V_57 -> V_87 ) ;
F_29 ( V_97 ) ;
}
F_29 ( V_104 ) ;
F_33 ( & V_57 -> V_65 -> V_69 , & V_94 ) ;
}
if ( V_93 )
goto V_85;
V_105:
if ( V_57 -> V_68 == V_57 -> V_96 )
goto V_85;
if ( V_57 -> V_68 > V_57 -> V_96 ) {
V_13 = V_57 -> V_68 - V_57 -> V_96 ;
if ( F_34 ( V_90 + V_93 , & V_57 -> V_67 [ V_57 -> V_96 ] , V_13 ) ) {
V_93 = - V_106 ;
goto V_85;
}
V_93 += V_13 ;
V_57 -> V_96 += V_13 ;
} else {
V_13 = V_7 - V_57 -> V_96 ;
if ( F_34 ( V_90 , & V_57 -> V_67 [ V_57 -> V_96 ] , V_13 ) ) {
V_93 = - V_106 ;
goto V_85;
}
V_57 -> V_96 = 0 ;
V_93 += V_13 ;
goto V_105;
}
}
V_85:
F_31 ( & V_57 -> V_87 ) ;
return V_93 ;
}
static unsigned int F_35 ( struct V_81 * V_81 , T_9 * V_94 )
{
struct V_66 * V_57 = V_81 -> V_86 ;
F_36 ( V_81 , & V_57 -> V_65 -> V_69 , V_94 ) ;
if ( V_57 -> V_96 != V_57 -> V_68 )
return V_107 | V_108 ;
if ( ! V_57 -> V_65 -> V_102 )
return V_109 | V_110 ;
return 0 ;
}
static int F_37 ( struct V_80 * V_80 , struct V_81 * V_81 )
{
struct V_66 * V_57 = V_81 -> V_86 ;
F_38 ( & V_57 -> V_88 ) ;
F_16 ( V_57 -> V_67 ) ;
F_16 ( V_57 ) ;
return 0 ;
}
void F_39 ( struct V_50 * V_65 , const char * V_111 )
{
V_65 -> V_112 = F_40 ( V_111 , V_113 ) ;
V_65 -> V_114 = F_41 ( L_65 , 0400 ,
V_65 -> V_112 , V_65 , & V_115 ) ;
V_65 -> V_116 = F_41 ( L_66 , 0400 ,
V_65 -> V_112 , V_65 , & V_117 ) ;
V_65 -> V_102 = 1 ;
}
void F_42 ( struct V_50 * V_65 )
{
V_65 -> V_102 = 0 ;
F_14 ( & V_65 -> V_69 ) ;
F_43 ( V_65 -> V_114 ) ;
F_43 ( V_65 -> V_116 ) ;
F_43 ( V_65 -> V_112 ) ;
}
void F_44 ( void )
{
V_113 = F_40 ( L_67 , NULL ) ;
}
void F_45 ( void )
{
F_46 ( V_113 ) ;
}
