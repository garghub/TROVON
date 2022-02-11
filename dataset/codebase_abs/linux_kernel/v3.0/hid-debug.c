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
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_10 , V_16 -> V_20 ) ;
for ( V_17 = 0 ; V_17 < V_16 -> V_20 ; V_17 ++ ) {
F_9 ( V_14 + 2 , V_3 ) ; F_5 ( V_16 -> V_12 [ V_17 ] . V_21 , V_3 ) ; F_4 ( V_3 , L_11 ) ;
}
if ( V_16 -> V_22 != V_16 -> V_23 ) {
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_12 , V_16 -> V_22 ) ;
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_13 , V_16 -> V_23 ) ;
}
if ( V_16 -> V_24 != V_16 -> V_25 ) {
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_14 , V_16 -> V_24 ) ;
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_15 , V_16 -> V_25 ) ;
}
if ( V_16 -> V_26 ) {
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_16 , V_16 -> V_26 ) ;
}
if ( V_16 -> V_27 ) {
static const char * V_28 [ 5 ] = { L_17 , L_18 , L_19 , L_20 , L_21 } ;
static const char * V_29 [ 5 ] [ 8 ] = {
{ L_17 , L_17 , L_17 , L_17 , L_17 , L_17 , L_17 , L_17 } ,
{ L_17 , L_22 , L_23 , L_24 , L_25 , L_26 , L_27 , L_17 } ,
{ L_17 , L_28 , L_23 , L_24 , L_25 , L_26 , L_27 , L_17 } ,
{ L_17 , L_29 , L_30 , L_24 , L_31 , L_26 , L_27 , L_17 } ,
{ L_17 , L_32 , L_30 , L_24 , L_31 , L_26 , L_27 , L_17 }
} ;
int V_30 ;
int V_31 ;
T_1 V_32 = V_16 -> V_27 ;
V_31 = V_32 & 0xf ;
V_32 >>= 4 ;
if( V_31 > 4 ) {
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_33 ) ;
}
else {
int V_33 = 0 ;
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_34 , V_28 [ V_31 ] ) ;
for ( V_30 = 1 ; V_30 < sizeof( T_1 ) * 2 ; V_30 ++ ) {
char V_34 = V_32 & 0xf ;
V_32 >>= 4 ;
if ( V_34 != 0 ) {
if( V_33 ++ > 0 )
F_4 ( V_3 , L_35 ) ;
F_4 ( V_3 , L_1 , V_29 [ V_31 ] [ V_30 ] ) ;
if( V_34 != 1 ) {
int V_35 = V_34 & 0x7 ;
if( V_34 & 0x08 )
V_35 = - ( ( 0x7 & ~ V_35 ) + 1 ) ;
F_4 ( V_3 , L_36 , V_35 ) ;
}
}
}
F_4 ( V_3 , L_8 ) ;
}
}
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_37 , V_16 -> V_36 ) ;
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_38 , V_16 -> V_37 ) ;
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_39 , V_16 -> V_38 ) ;
F_9 ( V_14 , V_3 ) ; F_4 ( V_3 , L_40 ) ;
V_17 = V_16 -> V_39 ;
F_4 ( V_3 , L_1 , V_40 & V_17 ? L_41 : L_6 ) ;
F_4 ( V_3 , L_1 , V_41 & V_17 ? L_42 : L_43 ) ;
F_4 ( V_3 , L_1 , V_42 & V_17 ? L_44 : L_45 ) ;
F_4 ( V_3 , L_1 , V_43 & V_17 ? L_46 : L_6 ) ;
F_4 ( V_3 , L_1 , V_44 & V_17 ? L_47 : L_6 ) ;
F_4 ( V_3 , L_1 , V_45 & V_17 ? L_48 : L_6 ) ;
F_4 ( V_3 , L_1 , V_46 & V_17 ? L_49 : L_6 ) ;
F_4 ( V_3 , L_1 , V_47 & V_17 ? L_50 : L_6 ) ;
F_4 ( V_3 , L_1 , V_48 & V_17 ? L_51 : L_6 ) ;
F_4 ( V_3 , L_8 ) ;
}
void F_11 ( struct V_49 * V_50 , struct V_2 * V_3 )
{
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
unsigned V_30 , V_57 ;
static const char * V_58 [] = { L_52 , L_53 , L_54 } ;
for ( V_30 = 0 ; V_30 < V_59 ; V_30 ++ ) {
V_52 = V_50 -> V_52 + V_30 ;
V_56 = V_52 -> V_60 . V_61 ;
while ( V_56 != & V_52 -> V_60 ) {
V_54 = (struct V_53 * ) V_56 ;
F_9 ( 2 , V_3 ) ;
F_4 ( V_3 , L_1 , V_58 [ V_30 ] ) ;
if ( V_54 -> V_62 )
F_4 ( V_3 , L_55 , V_54 -> V_62 ) ;
F_4 ( V_3 , L_56 , V_58 [ V_54 -> type ] ) ;
F_4 ( V_3 , L_11 ) ;
for ( V_57 = 0 ; V_57 < V_54 -> V_63 ; V_57 ++ ) {
F_9 ( 4 , V_3 ) ;
F_4 ( V_3 , L_57 , V_57 ) ;
F_10 ( V_54 -> V_16 [ V_57 ] , 6 , V_3 ) ;
}
V_56 = V_56 -> V_61 ;
}
}
}
void F_12 ( struct V_49 * V_64 , char * V_6 )
{
int V_30 ;
struct V_65 * V_56 ;
F_13 (list, &hdev->debug_list, node) {
for ( V_30 = 0 ; V_30 < strlen ( V_6 ) ; V_30 ++ )
V_56 -> V_66 [ ( V_56 -> V_67 + V_30 ) % V_7 ] =
V_6 [ V_30 ] ;
V_56 -> V_67 = ( V_56 -> V_67 + V_30 ) % V_7 ;
}
F_14 ( & V_64 -> V_68 ) ;
}
void F_15 ( struct V_49 * V_64 , struct V_69 * V_12 , T_2 V_70 )
{
char * V_6 ;
int V_13 ;
V_6 = F_5 ( V_12 -> V_21 , NULL ) ;
if ( ! V_6 )
return;
V_13 = strlen ( V_6 ) ;
snprintf ( V_6 + V_13 , V_7 - V_13 - 1 , L_58 , V_70 ) ;
F_12 ( V_64 , V_6 ) ;
F_16 ( V_6 ) ;
F_14 ( & V_64 -> V_68 ) ;
}
static void F_17 ( T_3 type , T_4 V_71 , struct V_2 * V_3 )
{
F_4 ( V_3 , L_59 , V_72 [ type ] ? V_72 [ type ] : L_60 ,
V_73 [ type ] ? ( V_73 [ type ] [ V_71 ] ? V_73 [ type ] [ V_71 ] : L_60 ) : L_60 ) ;
}
static void F_18 ( struct V_49 * V_21 , struct V_2 * V_3 )
{
int V_30 , V_17 , V_57 ;
struct V_53 * V_54 ;
struct V_69 * V_12 ;
for ( V_57 = V_74 ; V_57 <= V_75 ; V_57 ++ ) {
F_13 (report, &hid->report_enum[k].report_list, list) {
for ( V_30 = 0 ; V_30 < V_54 -> V_63 ; V_30 ++ ) {
for ( V_17 = 0 ; V_17 < V_54 -> V_16 [ V_30 ] -> V_20 ; V_17 ++ ) {
V_12 = V_54 -> V_16 [ V_30 ] -> V_12 + V_17 ;
F_5 ( V_12 -> V_21 , V_3 ) ;
F_4 ( V_3 , L_61 ) ;
F_17 ( V_12 -> type , V_12 -> V_71 , V_3 ) ;
F_4 ( V_3 , L_11 ) ;
}
}
}
}
}
static int F_19 ( struct V_2 * V_3 , void * V_5 )
{
struct V_49 * V_64 = V_3 -> V_76 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_64 -> V_77 ; V_30 ++ )
F_4 ( V_3 , L_62 , V_64 -> V_78 [ V_30 ] ) ;
F_4 ( V_3 , L_63 ) ;
F_11 ( V_64 , V_3 ) ;
F_4 ( V_3 , L_11 ) ;
F_18 ( V_64 , V_3 ) ;
return 0 ;
}
static int F_20 ( struct V_79 * V_79 , struct V_80 * V_80 )
{
return F_21 ( V_80 , F_19 , V_79 -> V_81 ) ;
}
static int F_22 ( struct V_79 * V_79 , struct V_80 * V_80 )
{
int V_82 = 0 ;
struct V_65 * V_56 ;
if ( ! ( V_56 = F_2 ( sizeof( struct V_65 ) , V_83 ) ) ) {
V_82 = - V_9 ;
goto V_84;
}
if ( ! ( V_56 -> V_66 = F_2 ( sizeof( char ) * V_7 , V_83 ) ) ) {
V_82 = - V_9 ;
F_16 ( V_56 ) ;
goto V_84;
}
V_56 -> V_64 = (struct V_49 * ) V_79 -> V_81 ;
V_80 -> V_85 = V_56 ;
F_23 ( & V_56 -> V_86 ) ;
F_24 ( & V_56 -> V_87 , & V_56 -> V_64 -> V_88 ) ;
V_84:
return V_82 ;
}
static T_5 F_25 ( struct V_80 * V_80 , char T_6 * V_89 ,
T_7 V_90 , T_8 * V_91 )
{
struct V_65 * V_56 = V_80 -> V_85 ;
int V_92 = 0 , V_13 ;
F_26 ( V_93 , V_94 ) ;
F_27 ( & V_56 -> V_86 ) ;
while ( V_92 == 0 ) {
if ( V_56 -> V_95 == V_56 -> V_67 ) {
F_28 ( & V_56 -> V_64 -> V_68 , & V_93 ) ;
F_29 ( V_96 ) ;
while ( V_56 -> V_95 == V_56 -> V_67 ) {
if ( V_80 -> V_97 & V_98 ) {
V_92 = - V_99 ;
break;
}
if ( F_30 ( V_94 ) ) {
V_92 = - V_100 ;
break;
}
if ( ! V_56 -> V_64 || ! V_56 -> V_64 -> V_101 ) {
V_92 = - V_102 ;
break;
}
F_31 ( & V_56 -> V_86 ) ;
F_32 () ;
F_27 ( & V_56 -> V_86 ) ;
F_29 ( V_96 ) ;
}
F_29 ( V_103 ) ;
F_33 ( & V_56 -> V_64 -> V_68 , & V_93 ) ;
}
if ( V_92 )
goto V_84;
V_104:
if ( V_56 -> V_67 == V_56 -> V_95 )
goto V_84;
if ( V_56 -> V_67 > V_56 -> V_95 ) {
V_13 = V_56 -> V_67 - V_56 -> V_95 ;
if ( F_34 ( V_89 + V_92 , & V_56 -> V_66 [ V_56 -> V_95 ] , V_13 ) ) {
V_92 = - V_105 ;
goto V_84;
}
V_92 += V_13 ;
V_56 -> V_95 += V_13 ;
} else {
V_13 = V_7 - V_56 -> V_95 ;
if ( F_34 ( V_89 , & V_56 -> V_66 [ V_56 -> V_95 ] , V_13 ) ) {
V_92 = - V_105 ;
goto V_84;
}
V_56 -> V_95 = 0 ;
V_92 += V_13 ;
goto V_104;
}
}
V_84:
F_31 ( & V_56 -> V_86 ) ;
return V_92 ;
}
static unsigned int F_35 ( struct V_80 * V_80 , T_9 * V_93 )
{
struct V_65 * V_56 = V_80 -> V_85 ;
F_36 ( V_80 , & V_56 -> V_64 -> V_68 , V_93 ) ;
if ( V_56 -> V_95 != V_56 -> V_67 )
return V_106 | V_107 ;
if ( ! V_56 -> V_64 -> V_101 )
return V_108 | V_109 ;
return 0 ;
}
static int F_37 ( struct V_79 * V_79 , struct V_80 * V_80 )
{
struct V_65 * V_56 = V_80 -> V_85 ;
F_38 ( & V_56 -> V_87 ) ;
F_16 ( V_56 -> V_66 ) ;
F_16 ( V_56 ) ;
return 0 ;
}
void F_39 ( struct V_49 * V_64 , const char * V_110 )
{
V_64 -> V_111 = F_40 ( V_110 , V_112 ) ;
V_64 -> V_113 = F_41 ( L_64 , 0400 ,
V_64 -> V_111 , V_64 , & V_114 ) ;
V_64 -> V_115 = F_41 ( L_65 , 0400 ,
V_64 -> V_111 , V_64 , & V_116 ) ;
V_64 -> V_101 = 1 ;
}
void F_42 ( struct V_49 * V_64 )
{
V_64 -> V_101 = 0 ;
F_14 ( & V_64 -> V_68 ) ;
F_43 ( V_64 -> V_113 ) ;
F_43 ( V_64 -> V_115 ) ;
F_43 ( V_64 -> V_111 ) ;
}
void F_44 ( void )
{
V_112 = F_40 ( L_66 , NULL ) ;
}
void F_45 ( void )
{
F_46 ( V_112 ) ;
}
