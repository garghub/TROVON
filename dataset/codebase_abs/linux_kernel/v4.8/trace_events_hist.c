static T_1 F_1 ( struct V_1 * V_2 , void * V_3 )
{
return 0 ;
}
static T_1 F_2 ( struct V_1 * V_2 , void * V_3 )
{
return 1 ;
}
static T_1 F_3 ( struct V_1 * V_1 , void * V_3 )
{
char * V_4 = ( char * ) ( V_3 + V_1 -> V_2 -> V_5 ) ;
return ( T_1 ) ( unsigned long ) V_4 ;
}
static T_1 F_4 ( struct V_1 * V_1 , void * V_3 )
{
T_2 V_6 = * ( T_2 * ) ( V_3 + V_1 -> V_2 -> V_5 ) ;
int V_7 = V_6 & 0xffff ;
char * V_4 = ( char * ) ( V_3 + V_7 ) ;
return ( T_1 ) ( unsigned long ) V_4 ;
}
static T_1 F_5 ( struct V_1 * V_1 , void * V_3 )
{
char * * V_4 = ( char * * ) ( V_3 + V_1 -> V_2 -> V_5 ) ;
return ( T_1 ) ( unsigned long ) * V_4 ;
}
static T_1 F_6 ( struct V_1 * V_1 , void * V_3 )
{
T_1 V_8 = * ( T_1 * ) ( V_3 + V_1 -> V_2 -> V_5 ) ;
return ( T_1 ) F_7 ( F_8 ( V_8 ) ) ;
}
static T_3 F_9 ( int V_9 , int V_10 )
{
T_3 V_11 = NULL ;
switch ( V_9 ) {
case 8 :
if ( V_10 )
V_11 = V_12 ;
else
V_11 = V_13 ;
break;
case 4 :
if ( V_10 )
V_11 = V_14 ;
else
V_11 = V_15 ;
break;
case 2 :
if ( V_10 )
V_11 = V_16 ;
else
V_11 = V_17 ;
break;
case 1 :
if ( V_10 )
V_11 = V_18 ;
else
V_11 = V_19 ;
break;
}
return V_11 ;
}
static int F_10 ( char * V_20 )
{
unsigned long V_21 , V_22 ;
int V_23 ;
F_11 ( & V_20 , L_1 ) ;
if ( ! V_20 ) {
V_23 = - V_24 ;
goto V_25;
}
V_23 = F_12 ( V_20 , 0 , & V_21 ) ;
if ( V_23 )
goto V_25;
V_22 = F_7 ( F_8 ( V_21 ) ) ;
if ( V_22 < V_26 ||
V_22 > V_27 )
V_23 = - V_24 ;
else
V_23 = V_22 ;
V_25:
return V_23 ;
}
static void F_13 ( struct V_28 * V_29 )
{
if ( ! V_29 )
return;
F_14 ( V_29 -> V_30 ) ;
F_14 ( V_29 -> V_31 ) ;
F_14 ( V_29 -> V_32 ) ;
F_14 ( V_29 -> V_33 ) ;
F_14 ( V_29 ) ;
}
static struct V_28 * F_15 ( char * V_34 )
{
struct V_28 * V_29 ;
int V_23 = 0 ;
V_29 = F_16 ( sizeof( * V_29 ) , V_35 ) ;
if ( ! V_29 )
return F_17 ( - V_36 ) ;
while ( V_34 ) {
char * V_20 = F_11 ( & V_34 , L_2 ) ;
if ( ( strncmp ( V_20 , L_3 , strlen ( L_3 ) ) == 0 ) ||
( strncmp ( V_20 , L_4 , strlen ( L_4 ) ) == 0 ) )
V_29 -> V_32 = F_18 ( V_20 , V_35 ) ;
else if ( ( strncmp ( V_20 , L_5 , strlen ( L_5 ) ) == 0 ) ||
( strncmp ( V_20 , L_6 , strlen ( L_6 ) ) == 0 ) ||
( strncmp ( V_20 , L_7 , strlen ( L_7 ) ) == 0 ) )
V_29 -> V_33 = F_18 ( V_20 , V_35 ) ;
else if ( strncmp ( V_20 , L_8 , strlen ( L_8 ) ) == 0 )
V_29 -> V_31 = F_18 ( V_20 , V_35 ) ;
else if ( strncmp ( V_20 , L_9 , strlen ( L_9 ) ) == 0 )
V_29 -> V_30 = F_18 ( V_20 , V_35 ) ;
else if ( strcmp ( V_20 , L_10 ) == 0 )
V_29 -> V_37 = true ;
else if ( ( strcmp ( V_20 , L_11 ) == 0 ) ||
( strcmp ( V_20 , L_12 ) == 0 ) )
V_29 -> V_38 = true ;
else if ( strcmp ( V_20 , L_13 ) == 0 )
V_29 -> V_39 = true ;
else if ( strncmp ( V_20 , L_14 , strlen ( L_14 ) ) == 0 ) {
int V_22 = F_10 ( V_20 ) ;
if ( V_22 < 0 ) {
V_23 = V_22 ;
goto free;
}
V_29 -> V_22 = V_22 ;
} else {
V_23 = - V_24 ;
goto free;
}
}
if ( ! V_29 -> V_32 ) {
V_23 = - V_24 ;
goto free;
}
return V_29 ;
free:
F_13 ( V_29 ) ;
return F_17 ( V_23 ) ;
}
static inline void F_19 ( char * V_40 , struct V_41 * V_42 )
{
if ( ! V_42 -> V_43 ) {
strcpy ( V_40 , L_15 ) ;
return;
}
if ( F_20 ( V_42 -> V_43 < 0 ) ) {
strcpy ( V_40 , L_16 ) ;
return;
}
memcpy ( V_40 , V_42 -> V_40 , V_44 ) ;
}
static void F_21 ( struct V_45 * V_46 )
{
F_14 ( ( char * ) V_46 -> V_47 ) ;
}
static int F_22 ( struct V_45 * V_46 )
{
struct V_48 * V_49 = V_46 -> V_50 -> V_47 ;
struct V_1 * V_51 ;
unsigned int V_52 ;
F_23 (i, hist_data) {
V_51 = V_49 -> V_53 [ V_52 ] ;
if ( V_51 -> V_54 & V_55 ) {
unsigned int V_21 = V_44 + 1 ;
V_46 -> V_47 = F_16 ( V_21 , V_35 ) ;
if ( ! V_46 -> V_47 )
return - V_36 ;
break;
}
}
return 0 ;
}
static void F_24 ( struct V_45 * V_56 ,
struct V_45 * V_57 )
{
char * V_58 = V_57 -> V_47 ;
char * V_59 = V_56 -> V_47 ;
if ( V_58 )
memcpy ( V_59 , V_58 , V_44 + 1 ) ;
}
static void F_25 ( struct V_45 * V_46 )
{
char * V_40 = V_46 -> V_47 ;
if ( V_40 )
F_19 ( V_40 , V_60 ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
F_14 ( V_1 ) ;
}
static struct V_1 * F_27 ( struct V_61 * V_2 ,
unsigned long V_54 )
{
struct V_1 * V_1 ;
if ( V_2 && F_28 ( V_2 ) )
return NULL ;
V_1 = F_16 ( sizeof( struct V_1 ) , V_35 ) ;
if ( ! V_1 )
return NULL ;
if ( V_54 & V_62 ) {
V_1 -> V_11 = F_2 ;
goto V_25;
}
if ( V_54 & V_63 ) {
V_1 -> V_11 = F_1 ;
goto V_25;
}
if ( V_54 & V_64 ) {
V_1 -> V_11 = F_6 ;
goto V_25;
}
if ( F_20 ( ! V_2 ) )
goto V_25;
if ( F_29 ( V_2 ) ) {
V_54 |= V_65 ;
if ( V_2 -> V_66 == V_67 )
V_1 -> V_11 = F_3 ;
else if ( V_2 -> V_66 == V_68 )
V_1 -> V_11 = F_4 ;
else
V_1 -> V_11 = F_5 ;
} else {
V_1 -> V_11 = F_9 ( V_2 -> V_21 ,
V_2 -> V_69 ) ;
if ( ! V_1 -> V_11 ) {
F_26 ( V_1 ) ;
return NULL ;
}
}
V_25:
V_1 -> V_2 = V_2 ;
V_1 -> V_54 = V_54 ;
return V_1 ;
}
static void F_30 ( struct V_48 * V_49 )
{
unsigned int V_52 ;
for ( V_52 = 0 ; V_52 < V_70 ; V_52 ++ ) {
if ( V_49 -> V_53 [ V_52 ] ) {
F_26 ( V_49 -> V_53 [ V_52 ] ) ;
V_49 -> V_53 [ V_52 ] = NULL ;
}
}
}
static int F_31 ( struct V_48 * V_49 )
{
V_49 -> V_53 [ V_71 ] =
F_27 ( NULL , V_62 ) ;
if ( ! V_49 -> V_53 [ V_71 ] )
return - V_36 ;
V_49 -> V_72 ++ ;
if ( F_32 ( V_49 -> V_72 > V_73 ) )
return - V_24 ;
return 0 ;
}
static int F_33 ( struct V_48 * V_49 ,
unsigned int V_74 ,
struct V_75 * V_76 ,
char * V_77 )
{
struct V_61 * V_2 = NULL ;
unsigned long V_54 = 0 ;
char * V_78 ;
int V_23 = 0 ;
if ( F_32 ( V_74 >= V_73 ) )
return - V_24 ;
V_78 = F_11 ( & V_77 , L_17 ) ;
if ( V_77 ) {
if ( strcmp ( V_77 , L_18 ) == 0 )
V_54 |= V_79 ;
else {
V_23 = - V_24 ;
goto V_25;
}
}
V_2 = F_34 ( V_76 -> V_80 , V_78 ) ;
if ( ! V_2 ) {
V_23 = - V_24 ;
goto V_25;
}
V_49 -> V_53 [ V_74 ] = F_27 ( V_2 , V_54 ) ;
if ( ! V_49 -> V_53 [ V_74 ] ) {
V_23 = - V_36 ;
goto V_25;
}
++ V_49 -> V_72 ;
if ( F_32 ( V_49 -> V_72 > V_73 ) )
V_23 = - V_24 ;
V_25:
return V_23 ;
}
static int F_35 ( struct V_48 * V_49 ,
struct V_75 * V_76 )
{
char * V_81 , * V_77 ;
unsigned int V_52 , V_82 ;
int V_23 ;
V_23 = F_31 ( V_49 ) ;
if ( V_23 )
goto V_25;
V_81 = V_49 -> V_29 -> V_33 ;
if ( ! V_81 )
goto V_25;
F_11 ( & V_81 , L_1 ) ;
if ( ! V_81 )
goto V_25;
for ( V_52 = 0 , V_82 = 1 ; V_52 < V_73 &&
V_82 < V_73 ; V_52 ++ ) {
V_77 = F_11 ( & V_81 , L_19 ) ;
if ( ! V_77 )
break;
if ( strcmp ( V_77 , L_20 ) == 0 )
continue;
V_23 = F_33 ( V_49 , V_82 ++ , V_76 , V_77 ) ;
if ( V_23 )
goto V_25;
}
if ( V_81 && ( strcmp ( V_81 , L_20 ) != 0 ) )
V_23 = - V_24 ;
V_25:
return V_23 ;
}
static int F_36 ( struct V_48 * V_49 ,
unsigned int V_83 ,
unsigned int V_84 ,
struct V_75 * V_76 ,
char * V_77 )
{
struct V_61 * V_2 = NULL ;
unsigned long V_54 = 0 ;
unsigned int V_85 ;
int V_23 = 0 ;
if ( F_32 ( V_83 >= V_70 ) )
return - V_24 ;
V_54 |= V_86 ;
if ( strcmp ( V_77 , L_21 ) == 0 ) {
V_54 |= V_63 ;
V_85 = sizeof( unsigned long ) * V_87 ;
} else {
char * V_78 = F_11 ( & V_77 , L_17 ) ;
if ( V_77 ) {
if ( strcmp ( V_77 , L_18 ) == 0 )
V_54 |= V_79 ;
else if ( strcmp ( V_77 , L_22 ) == 0 )
V_54 |= V_88 ;
else if ( strcmp ( V_77 , L_23 ) == 0 )
V_54 |= V_89 ;
else if ( ( strcmp ( V_77 , L_24 ) == 0 ) &&
( strcmp ( V_78 , L_25 ) == 0 ) )
V_54 |= V_55 ;
else if ( strcmp ( V_77 , L_26 ) == 0 )
V_54 |= V_90 ;
else if ( strcmp ( V_77 , L_27 ) == 0 )
V_54 |= V_64 ;
else {
V_23 = - V_24 ;
goto V_25;
}
}
V_2 = F_34 ( V_76 -> V_80 , V_78 ) ;
if ( ! V_2 ) {
V_23 = - V_24 ;
goto V_25;
}
if ( F_29 ( V_2 ) )
V_85 = V_91 ;
else
V_85 = V_2 -> V_21 ;
}
V_49 -> V_53 [ V_83 ] = F_27 ( V_2 , V_54 ) ;
if ( ! V_49 -> V_53 [ V_83 ] ) {
V_23 = - V_36 ;
goto V_25;
}
V_85 = F_37 ( V_85 , sizeof( T_1 ) ) ;
V_49 -> V_53 [ V_83 ] -> V_21 = V_85 ;
V_49 -> V_53 [ V_83 ] -> V_5 = V_84 ;
V_49 -> V_85 += V_85 ;
if ( V_49 -> V_85 > V_92 ) {
V_23 = - V_24 ;
goto V_25;
}
V_49 -> V_93 ++ ;
if ( F_32 ( V_49 -> V_93 > V_94 ) )
return - V_24 ;
V_23 = V_85 ;
V_25:
return V_23 ;
}
static int F_38 ( struct V_48 * V_49 ,
struct V_75 * V_76 )
{
unsigned int V_52 , V_84 = 0 , V_72 = V_49 -> V_72 ;
char * V_81 , * V_77 ;
int V_23 = - V_24 ;
V_81 = V_49 -> V_29 -> V_32 ;
if ( ! V_81 )
goto V_25;
F_11 ( & V_81 , L_1 ) ;
if ( ! V_81 )
goto V_25;
for ( V_52 = V_72 ; V_52 < V_72 + V_94 ; V_52 ++ ) {
V_77 = F_11 ( & V_81 , L_19 ) ;
if ( ! V_77 )
break;
V_23 = F_36 ( V_49 , V_52 , V_84 ,
V_76 , V_77 ) ;
if ( V_23 < 0 )
goto V_25;
V_84 += V_23 ;
}
if ( V_81 ) {
V_23 = - V_24 ;
goto V_25;
}
V_23 = 0 ;
V_25:
return V_23 ;
}
static int F_39 ( struct V_48 * V_49 ,
struct V_75 * V_76 )
{
int V_23 ;
V_23 = F_35 ( V_49 , V_76 ) ;
if ( V_23 )
goto V_25;
V_23 = F_38 ( V_49 , V_76 ) ;
if ( V_23 )
goto V_25;
V_49 -> V_95 = V_49 -> V_72 + V_49 -> V_93 ;
V_25:
return V_23 ;
}
static int F_40 ( const char * V_20 )
{
if ( ! V_20 )
return 0 ;
if ( strcmp ( V_20 , L_28 ) == 0 )
return 1 ;
if ( strcmp ( V_20 , L_29 ) == 0 )
return 0 ;
return - V_24 ;
}
static int F_41 ( struct V_48 * V_49 )
{
char * V_81 = V_49 -> V_29 -> V_31 ;
struct V_61 * V_2 = NULL ;
struct V_96 * V_97 ;
int V_98 , V_23 = 0 ;
unsigned int V_52 , V_82 ;
V_49 -> V_99 = 1 ;
if ( ! V_81 )
goto V_25;
F_11 ( & V_81 , L_1 ) ;
if ( ! V_81 ) {
V_23 = - V_24 ;
goto V_25;
}
for ( V_52 = 0 ; V_52 < V_100 ; V_52 ++ ) {
char * V_77 , * V_78 ;
V_97 = & V_49 -> V_101 [ V_52 ] ;
V_77 = F_11 ( & V_81 , L_19 ) ;
if ( ! V_77 ) {
if ( V_52 == 0 )
V_23 = - V_24 ;
break;
}
if ( ( V_52 == V_100 - 1 ) && V_81 ) {
V_23 = - V_24 ;
break;
}
V_78 = F_11 ( & V_77 , L_17 ) ;
if ( ! V_78 ) {
V_23 = - V_24 ;
break;
}
if ( strcmp ( V_78 , L_20 ) == 0 ) {
V_98 = F_40 ( V_77 ) ;
if ( V_98 < 0 ) {
V_23 = V_98 ;
break;
}
V_97 -> V_98 = V_98 ;
continue;
}
for ( V_82 = 1 ; V_82 < V_49 -> V_95 ; V_82 ++ ) {
V_2 = V_49 -> V_53 [ V_82 ] -> V_2 ;
if ( V_2 && ( strcmp ( V_78 , V_2 -> V_30 ) == 0 ) ) {
V_97 -> V_102 = V_82 ;
V_98 = F_40 ( V_77 ) ;
if ( V_98 < 0 ) {
V_23 = V_98 ;
goto V_25;
}
V_97 -> V_98 = V_98 ;
break;
}
}
if ( V_82 == V_49 -> V_95 ) {
V_23 = - V_24 ;
break;
}
}
V_49 -> V_99 = V_52 ;
V_25:
return V_23 ;
}
static void F_42 ( struct V_48 * V_49 )
{
F_13 ( V_49 -> V_29 ) ;
F_30 ( V_49 ) ;
F_43 ( V_49 -> V_50 ) ;
F_14 ( V_49 ) ;
}
static int F_44 ( struct V_48 * V_49 )
{
struct V_103 * V_50 = V_49 -> V_50 ;
struct V_61 * V_2 ;
struct V_1 * V_1 ;
int V_52 , V_104 ;
F_45 (i, hist_data) {
V_1 = V_49 -> V_53 [ V_52 ] ;
if ( V_1 -> V_54 & V_86 ) {
T_4 V_105 ;
V_2 = V_1 -> V_2 ;
if ( V_1 -> V_54 & V_63 )
V_105 = V_106 ;
else if ( F_29 ( V_2 ) )
V_105 = V_107 ;
else
V_105 = F_46 ( V_2 -> V_21 ,
V_2 -> V_69 ) ;
V_104 = F_47 ( V_50 ,
V_1 -> V_5 ,
V_105 ) ;
} else
V_104 = F_48 ( V_50 ) ;
if ( V_104 < 0 )
return V_104 ;
}
return 0 ;
}
static bool F_49 ( struct V_48 * V_49 )
{
struct V_1 * V_51 ;
unsigned int V_52 ;
F_23 (i, hist_data) {
V_51 = V_49 -> V_53 [ V_52 ] ;
if ( V_51 -> V_54 & V_55 )
return true ;
}
return false ;
}
static struct V_48 *
F_50 ( unsigned int V_22 ,
struct V_28 * V_29 ,
struct V_75 * V_76 )
{
const struct V_108 * V_109 = NULL ;
struct V_48 * V_49 ;
int V_23 = 0 ;
V_49 = F_16 ( sizeof( * V_49 ) , V_35 ) ;
if ( ! V_49 )
return F_17 ( - V_36 ) ;
V_49 -> V_29 = V_29 ;
V_23 = F_39 ( V_49 , V_76 ) ;
if ( V_23 )
goto free;
V_23 = F_41 ( V_49 ) ;
if ( V_23 )
goto free;
if ( F_49 ( V_49 ) )
V_109 = & V_110 ;
V_49 -> V_50 = F_51 ( V_22 , V_49 -> V_85 ,
V_109 , V_49 ) ;
if ( F_52 ( V_49 -> V_50 ) ) {
V_23 = F_53 ( V_49 -> V_50 ) ;
V_49 -> V_50 = NULL ;
goto free;
}
V_23 = F_44 ( V_49 ) ;
if ( V_23 )
goto free;
V_23 = F_54 ( V_49 -> V_50 ) ;
if ( V_23 )
goto free;
V_49 -> V_111 = V_76 ;
V_25:
return V_49 ;
free:
V_49 -> V_29 = NULL ;
F_42 ( V_49 ) ;
V_49 = F_17 ( V_23 ) ;
goto V_25;
}
static void F_55 ( struct V_48 * V_49 ,
struct V_45 * V_46 ,
void * V_112 )
{
struct V_1 * V_1 ;
unsigned int V_52 ;
T_1 V_113 ;
F_56 (i, hist_data) {
V_1 = V_49 -> V_53 [ V_52 ] ;
V_113 = V_1 -> V_11 ( V_1 , V_112 ) ;
F_57 ( V_46 , V_52 , V_113 ) ;
}
}
static inline void F_58 ( char * V_114 , void * V_115 ,
struct V_1 * V_51 , void * V_112 )
{
T_5 V_21 = V_51 -> V_21 ;
if ( V_51 -> V_54 & V_65 ) {
struct V_61 * V_2 ;
V_2 = V_51 -> V_2 ;
if ( V_2 -> V_66 == V_68 )
V_21 = * ( T_2 * ) ( V_112 + V_2 -> V_5 ) >> 16 ;
else if ( V_2 -> V_66 == V_116 )
V_21 = strlen ( V_115 ) ;
else if ( V_2 -> V_66 == V_67 )
V_21 = V_2 -> V_21 ;
if ( V_21 > V_51 -> V_21 - 1 )
V_21 = V_51 -> V_21 - 1 ;
}
memcpy ( V_114 + V_51 -> V_5 , V_115 , V_21 ) ;
}
static void F_59 ( struct V_117 * V_118 , void * V_112 )
{
struct V_48 * V_49 = V_118 -> V_47 ;
bool V_119 = ( V_49 -> V_93 > 1 ) ;
unsigned long V_120 [ V_87 ] ;
char V_114 [ V_92 ] ;
struct V_121 V_122 ;
struct V_1 * V_51 ;
struct V_45 * V_46 ;
T_1 V_123 ;
void * V_115 = NULL ;
unsigned int V_52 ;
memset ( V_114 , 0 , V_49 -> V_85 ) ;
F_23 (i, hist_data) {
V_51 = V_49 -> V_53 [ V_52 ] ;
if ( V_51 -> V_54 & V_63 ) {
V_122 . V_124 = V_87 ;
V_122 . V_120 = V_120 ;
V_122 . V_125 = 0 ;
V_122 . V_126 = V_127 ;
memset ( V_122 . V_120 , 0 , V_128 ) ;
F_60 ( & V_122 ) ;
V_115 = V_120 ;
} else {
V_123 = V_51 -> V_11 ( V_51 , V_112 ) ;
if ( V_51 -> V_54 & V_65 ) {
V_115 = ( void * ) ( unsigned long ) V_123 ;
V_119 = true ;
} else
V_115 = ( void * ) & V_123 ;
}
if ( V_119 )
F_58 ( V_114 , V_115 , V_51 , V_112 ) ;
}
if ( V_119 )
V_115 = V_114 ;
V_46 = F_61 ( V_49 -> V_50 , V_115 ) ;
if ( V_46 )
F_55 ( V_49 , V_46 , V_112 ) ;
}
static void F_62 ( struct V_129 * V_130 ,
unsigned long * V_131 ,
unsigned int V_124 )
{
char V_20 [ V_132 ] ;
unsigned int V_133 = 8 ;
unsigned int V_52 ;
for ( V_52 = 0 ; V_52 < V_124 ; V_52 ++ ) {
if ( V_131 [ V_52 ] == V_134 )
return;
F_63 ( V_130 , L_30 , 1 + V_133 , ' ' ) ;
F_64 ( V_20 , V_131 [ V_52 ] ) ;
F_63 ( V_130 , L_31 , V_20 ) ;
}
}
static void
F_65 ( struct V_129 * V_130 ,
struct V_48 * V_49 , void * V_115 ,
struct V_45 * V_46 )
{
struct V_1 * V_51 ;
char V_20 [ V_132 ] ;
bool V_135 = false ;
unsigned int V_52 ;
T_1 V_136 ;
F_66 ( V_130 , L_32 ) ;
F_23 (i, hist_data) {
V_51 = V_49 -> V_53 [ V_52 ] ;
if ( V_52 > V_49 -> V_72 )
F_66 ( V_130 , L_33 ) ;
if ( V_51 -> V_54 & V_79 ) {
V_136 = * ( T_1 * ) ( V_115 + V_51 -> V_5 ) ;
F_63 ( V_130 , L_34 ,
V_51 -> V_2 -> V_30 , V_136 ) ;
} else if ( V_51 -> V_54 & V_88 ) {
V_136 = * ( T_1 * ) ( V_115 + V_51 -> V_5 ) ;
F_67 ( V_20 , V_136 ) ;
F_63 ( V_130 , L_35 ,
V_51 -> V_2 -> V_30 , V_136 , V_20 ) ;
} else if ( V_51 -> V_54 & V_89 ) {
V_136 = * ( T_1 * ) ( V_115 + V_51 -> V_5 ) ;
F_64 ( V_20 , V_136 ) ;
F_63 ( V_130 , L_36 ,
V_51 -> V_2 -> V_30 , V_136 , V_20 ) ;
} else if ( V_51 -> V_54 & V_55 ) {
char * V_40 = V_46 -> V_47 ;
V_136 = * ( T_1 * ) ( V_115 + V_51 -> V_5 ) ;
F_63 ( V_130 , L_37 ,
V_51 -> V_2 -> V_30 , V_40 , V_136 ) ;
} else if ( V_51 -> V_54 & V_90 ) {
const char * V_137 ;
V_136 = * ( T_1 * ) ( V_115 + V_51 -> V_5 ) ;
V_137 = F_68 ( V_136 ) ;
if ( ! V_137 )
V_137 = L_38 ;
F_63 ( V_130 , L_39 ,
V_51 -> V_2 -> V_30 , V_137 , V_136 ) ;
} else if ( V_51 -> V_54 & V_63 ) {
F_66 ( V_130 , L_40 ) ;
F_62 ( V_130 ,
V_115 + V_51 -> V_5 ,
V_87 ) ;
V_135 = true ;
} else if ( V_51 -> V_54 & V_64 ) {
F_63 ( V_130 , L_41 , V_51 -> V_2 -> V_30 ,
* ( T_1 * ) ( V_115 + V_51 -> V_5 ) ) ;
} else if ( V_51 -> V_54 & V_65 ) {
F_63 ( V_130 , L_42 , V_51 -> V_2 -> V_30 ,
( char * ) ( V_115 + V_51 -> V_5 ) ) ;
} else {
V_136 = * ( T_1 * ) ( V_115 + V_51 -> V_5 ) ;
F_63 ( V_130 , L_43 , V_51 -> V_2 -> V_30 ,
V_136 ) ;
}
}
if ( ! V_135 )
F_66 ( V_130 , L_44 ) ;
F_66 ( V_130 , L_45 ) ;
F_63 ( V_130 , L_46 ,
F_69 ( V_46 , V_71 ) ) ;
for ( V_52 = 1 ; V_52 < V_49 -> V_72 ; V_52 ++ ) {
if ( V_49 -> V_53 [ V_52 ] -> V_54 & V_79 ) {
F_63 ( V_130 , L_47 ,
V_49 -> V_53 [ V_52 ] -> V_2 -> V_30 ,
F_69 ( V_46 , V_52 ) ) ;
} else {
F_63 ( V_130 , L_48 ,
V_49 -> V_53 [ V_52 ] -> V_2 -> V_30 ,
F_69 ( V_46 , V_52 ) ) ;
}
}
F_66 ( V_130 , L_49 ) ;
}
static int F_70 ( struct V_129 * V_130 ,
struct V_48 * V_49 )
{
struct V_138 * * V_139 = NULL ;
struct V_103 * V_50 = V_49 -> V_50 ;
int V_52 , V_140 ;
V_140 = F_71 ( V_50 , V_49 -> V_101 ,
V_49 -> V_99 ,
& V_139 ) ;
if ( V_140 < 0 )
return V_140 ;
for ( V_52 = 0 ; V_52 < V_140 ; V_52 ++ )
F_65 ( V_130 , V_49 ,
V_139 [ V_52 ] -> V_115 ,
V_139 [ V_52 ] -> V_46 ) ;
F_72 ( V_139 , V_140 ) ;
return V_140 ;
}
static void F_73 ( struct V_129 * V_130 ,
struct V_117 * V_118 , int V_141 )
{
struct V_48 * V_49 ;
int V_140 , V_23 = 0 ;
if ( V_141 > 0 )
F_66 ( V_130 , L_50 ) ;
F_66 ( V_130 , L_51 ) ;
V_118 -> V_142 -> V_143 ( V_130 , V_118 -> V_142 , V_118 ) ;
F_66 ( V_130 , L_52 ) ;
V_49 = V_118 -> V_47 ;
V_140 = F_70 ( V_130 , V_49 ) ;
if ( V_140 < 0 ) {
V_23 = V_140 ;
V_140 = 0 ;
}
F_63 ( V_130 , L_53 ,
( T_1 ) F_74 ( & V_49 -> V_50 -> V_144 ) ,
V_140 , ( T_1 ) F_74 ( & V_49 -> V_50 -> V_145 ) ) ;
}
static int F_75 ( struct V_129 * V_130 , void * V_146 )
{
struct V_117 * V_118 ;
struct V_75 * V_111 ;
int V_141 = 0 , V_23 = 0 ;
F_76 ( & V_147 ) ;
V_111 = F_77 ( V_130 -> V_148 ) ;
if ( F_78 ( ! V_111 ) ) {
V_23 = - V_149 ;
goto V_150;
}
F_79 (data, &event_file->triggers, list) {
if ( V_118 -> V_151 -> V_152 == V_153 )
F_73 ( V_130 , V_118 , V_141 ++ ) ;
}
V_150:
F_80 ( & V_147 ) ;
return V_23 ;
}
static int F_81 ( struct V_154 * V_154 , struct V_76 * V_76 )
{
return F_82 ( V_76 , F_75 , V_76 ) ;
}
static const char * F_83 ( struct V_1 * V_1 )
{
const char * V_155 = NULL ;
if ( V_1 -> V_54 & V_79 )
V_155 = L_18 ;
else if ( V_1 -> V_54 & V_88 )
V_155 = L_22 ;
else if ( V_1 -> V_54 & V_89 )
V_155 = L_23 ;
else if ( V_1 -> V_54 & V_55 )
V_155 = L_24 ;
else if ( V_1 -> V_54 & V_90 )
V_155 = L_26 ;
else if ( V_1 -> V_54 & V_64 )
V_155 = L_27 ;
return V_155 ;
}
static void F_84 ( struct V_129 * V_130 , struct V_1 * V_1 )
{
F_63 ( V_130 , L_54 , V_1 -> V_2 -> V_30 ) ;
if ( V_1 -> V_54 ) {
const char * V_155 = F_83 ( V_1 ) ;
if ( V_155 )
F_63 ( V_130 , L_55 , V_155 ) ;
}
}
static int F_85 ( struct V_129 * V_130 ,
struct V_156 * V_142 ,
struct V_117 * V_118 )
{
struct V_48 * V_49 = V_118 -> V_47 ;
struct V_1 * V_51 ;
unsigned int V_52 ;
F_66 ( V_130 , L_56 ) ;
if ( V_118 -> V_30 )
F_63 ( V_130 , L_57 , V_118 -> V_30 ) ;
F_66 ( V_130 , L_4 ) ;
F_23 (i, hist_data) {
V_51 = V_49 -> V_53 [ V_52 ] ;
if ( V_52 > V_49 -> V_72 )
F_66 ( V_130 , L_19 ) ;
if ( V_51 -> V_54 & V_63 )
F_66 ( V_130 , L_21 ) ;
else
F_84 ( V_130 , V_51 ) ;
}
F_66 ( V_130 , L_58 ) ;
F_56 (i, hist_data) {
if ( V_52 == V_71 )
F_66 ( V_130 , L_20 ) ;
else {
F_66 ( V_130 , L_19 ) ;
F_84 ( V_130 , V_49 -> V_53 [ V_52 ] ) ;
}
}
F_66 ( V_130 , L_59 ) ;
for ( V_52 = 0 ; V_52 < V_49 -> V_99 ; V_52 ++ ) {
struct V_96 * V_97 ;
V_97 = & V_49 -> V_101 [ V_52 ] ;
if ( V_52 > 0 )
F_66 ( V_130 , L_19 ) ;
if ( V_97 -> V_102 == V_71 )
F_66 ( V_130 , L_20 ) ;
else {
unsigned int V_104 = V_97 -> V_102 ;
if ( F_32 ( V_104 >= V_70 ) )
return - V_24 ;
F_84 ( V_130 , V_49 -> V_53 [ V_104 ] ) ;
}
if ( V_97 -> V_98 )
F_66 ( V_130 , L_60 ) ;
}
F_63 ( V_130 , L_61 , ( 1 << V_49 -> V_50 -> V_22 ) ) ;
if ( V_118 -> V_157 )
F_63 ( V_130 , L_62 , V_118 -> V_157 ) ;
if ( V_118 -> V_158 )
F_66 ( V_130 , L_63 ) ;
else
F_66 ( V_130 , L_64 ) ;
F_86 ( V_130 , '\n' ) ;
return 0 ;
}
static int F_87 ( struct V_156 * V_142 ,
struct V_117 * V_118 )
{
struct V_48 * V_49 = V_118 -> V_47 ;
if ( ! V_118 -> V_159 && V_49 -> V_29 -> V_30 )
F_88 ( V_49 -> V_29 -> V_30 , V_118 ) ;
V_118 -> V_159 ++ ;
return 0 ;
}
static void F_89 ( struct V_156 * V_142 ,
struct V_117 * V_118 )
{
struct V_48 * V_49 = V_118 -> V_47 ;
if ( F_20 ( V_118 -> V_159 <= 0 ) )
return;
V_118 -> V_159 -- ;
if ( ! V_118 -> V_159 ) {
if ( V_118 -> V_30 )
F_90 ( V_118 ) ;
F_91 ( V_118 ) ;
F_42 ( V_49 ) ;
}
}
static int F_92 ( struct V_156 * V_142 ,
struct V_117 * V_118 )
{
V_118 -> V_159 ++ ;
F_88 ( V_118 -> V_160 -> V_30 , V_118 ) ;
F_87 ( V_142 , V_118 -> V_160 ) ;
return 0 ;
}
static void F_93 ( struct V_156 * V_142 ,
struct V_117 * V_118 )
{
if ( F_20 ( V_118 -> V_159 <= 0 ) )
return;
F_89 ( V_142 , V_118 -> V_160 ) ;
V_118 -> V_159 -- ;
if ( ! V_118 -> V_159 ) {
F_90 ( V_118 ) ;
F_91 ( V_118 ) ;
}
}
static struct V_156 * F_94 ( char * V_161 ,
char * V_162 )
{
return & V_163 ;
}
static void F_95 ( struct V_117 * V_118 )
{
struct V_48 * V_49 = V_118 -> V_47 ;
if ( V_118 -> V_30 )
F_96 ( V_118 ) ;
F_97 () ;
F_98 ( V_49 -> V_50 ) ;
if ( V_118 -> V_30 )
F_99 ( V_118 ) ;
}
static bool F_100 ( struct V_61 * V_2 ,
struct V_61 * V_164 )
{
if ( V_2 == V_164 )
return true ;
if ( V_2 == NULL || V_164 == NULL )
return false ;
if ( strcmp ( V_2 -> V_30 , V_164 -> V_30 ) != 0 )
return false ;
if ( strcmp ( V_2 -> type , V_164 -> type ) != 0 )
return false ;
if ( V_2 -> V_21 != V_164 -> V_21 )
return false ;
if ( V_2 -> V_69 != V_164 -> V_69 )
return false ;
return true ;
}
static bool F_101 ( struct V_117 * V_118 ,
struct V_117 * V_165 ,
struct V_117 * V_160 ,
bool V_166 )
{
struct V_96 * V_97 , * V_167 ;
struct V_48 * V_49 , * V_168 ;
struct V_1 * V_51 , * V_169 ;
unsigned int V_52 ;
if ( V_160 && ( V_160 != V_165 ) &&
( V_160 != V_165 -> V_160 ) )
return false ;
if ( ! V_160 && F_102 ( V_165 ) )
return false ;
V_49 = V_118 -> V_47 ;
V_168 = V_165 -> V_47 ;
if ( V_49 -> V_72 != V_168 -> V_72 ||
V_49 -> V_95 != V_168 -> V_95 ||
V_49 -> V_99 != V_168 -> V_99 )
return false ;
if ( ! V_166 ) {
if ( ( V_118 -> V_157 && ! V_165 -> V_157 ) ||
( ! V_118 -> V_157 && V_165 -> V_157 ) )
return false ;
}
F_45 (i, hist_data) {
V_51 = V_49 -> V_53 [ V_52 ] ;
V_169 = V_168 -> V_53 [ V_52 ] ;
if ( V_51 -> V_54 != V_169 -> V_54 )
return false ;
if ( ! F_100 ( V_51 -> V_2 , V_169 -> V_2 ) )
return false ;
if ( V_51 -> V_5 != V_169 -> V_5 )
return false ;
}
for ( V_52 = 0 ; V_52 < V_49 -> V_99 ; V_52 ++ ) {
V_97 = & V_49 -> V_101 [ V_52 ] ;
V_167 = & V_168 -> V_101 [ V_52 ] ;
if ( V_97 -> V_102 != V_167 -> V_102 ||
V_97 -> V_98 != V_167 -> V_98 )
return false ;
}
if ( ! V_166 && V_118 -> V_157 &&
( strcmp ( V_118 -> V_157 , V_165 -> V_157 ) != 0 ) )
return false ;
return true ;
}
static int F_103 ( char * V_170 , struct V_156 * V_142 ,
struct V_117 * V_118 ,
struct V_75 * V_76 )
{
struct V_48 * V_49 = V_118 -> V_47 ;
struct V_117 * V_171 , * V_160 = NULL ;
int V_23 = 0 ;
if ( V_49 -> V_29 -> V_30 ) {
V_160 = F_104 ( V_49 -> V_29 -> V_30 ) ;
if ( V_160 ) {
if ( ! F_101 ( V_118 , V_160 , V_160 ,
true ) ) {
V_23 = - V_24 ;
goto V_25;
}
}
}
if ( V_49 -> V_29 -> V_30 && ! V_160 )
goto V_172;
F_79 (test, &file->triggers, list) {
if ( V_171 -> V_151 -> V_152 == V_153 ) {
if ( ! F_101 ( V_118 , V_171 , V_160 , false ) )
continue;
if ( V_49 -> V_29 -> V_37 )
V_171 -> V_158 = true ;
else if ( V_49 -> V_29 -> V_38 )
V_171 -> V_158 = false ;
else if ( V_49 -> V_29 -> V_39 )
F_95 ( V_171 ) ;
else
V_23 = - V_173 ;
goto V_25;
}
}
V_172:
if ( V_49 -> V_29 -> V_38 || V_49 -> V_29 -> V_39 ) {
V_23 = - V_174 ;
goto V_25;
}
if ( V_49 -> V_29 -> V_37 )
V_118 -> V_158 = true ;
if ( V_160 ) {
F_42 ( V_118 -> V_47 ) ;
V_118 -> V_47 = V_160 -> V_47 ;
F_105 ( V_118 , V_160 ) ;
V_118 -> V_142 = & V_175 ;
}
if ( V_118 -> V_142 -> V_176 ) {
V_23 = V_118 -> V_142 -> V_176 ( V_118 -> V_142 , V_118 ) ;
if ( V_23 < 0 )
goto V_25;
}
F_106 ( & V_118 -> V_177 , & V_76 -> V_178 ) ;
V_23 ++ ;
F_107 ( V_76 ) ;
if ( F_108 ( V_76 , 1 ) < 0 ) {
F_109 ( & V_118 -> V_177 ) ;
F_107 ( V_76 ) ;
V_23 -- ;
}
V_25:
return V_23 ;
}
static void F_110 ( char * V_170 , struct V_156 * V_142 ,
struct V_117 * V_118 ,
struct V_75 * V_76 )
{
struct V_48 * V_49 = V_118 -> V_47 ;
struct V_117 * V_171 , * V_160 = NULL ;
bool V_179 = false ;
if ( V_49 -> V_29 -> V_30 )
V_160 = F_104 ( V_49 -> V_29 -> V_30 ) ;
F_79 (test, &file->triggers, list) {
if ( V_171 -> V_151 -> V_152 == V_153 ) {
if ( ! F_101 ( V_118 , V_171 , V_160 , false ) )
continue;
V_179 = true ;
F_109 ( & V_171 -> V_177 ) ;
F_108 ( V_76 , 0 ) ;
F_107 ( V_76 ) ;
break;
}
}
if ( V_179 && V_171 -> V_142 -> free )
V_171 -> V_142 -> free ( V_171 -> V_142 , V_171 ) ;
}
static void F_111 ( struct V_75 * V_76 )
{
struct V_117 * V_171 , * V_141 ;
F_112 (test, n, &file->triggers, list) {
if ( V_171 -> V_151 -> V_152 == V_153 ) {
F_109 ( & V_171 -> V_177 ) ;
F_108 ( V_76 , 0 ) ;
F_107 ( V_76 ) ;
if ( V_171 -> V_142 -> free )
V_171 -> V_142 -> free ( V_171 -> V_142 , V_171 ) ;
}
}
}
static int F_113 ( struct V_180 * V_151 ,
struct V_75 * V_76 ,
char * V_170 , char * V_161 , char * V_162 )
{
unsigned int V_181 = V_182 ;
struct V_117 * V_183 ;
struct V_28 * V_29 ;
struct V_156 * V_184 ;
struct V_48 * V_49 ;
char * V_185 ;
int V_23 = 0 ;
if ( ! V_162 )
return - V_24 ;
V_185 = F_11 ( & V_162 , L_65 ) ;
if ( ! V_185 )
return - V_24 ;
V_29 = F_15 ( V_185 ) ;
if ( F_52 ( V_29 ) )
return F_53 ( V_29 ) ;
if ( V_29 -> V_22 )
V_181 = V_29 -> V_22 ;
V_49 = F_50 ( V_181 , V_29 , V_76 ) ;
if ( F_52 ( V_49 ) ) {
F_13 ( V_29 ) ;
return F_53 ( V_49 ) ;
}
V_184 = V_151 -> V_186 ( V_161 , V_185 ) ;
V_23 = - V_36 ;
V_183 = F_16 ( sizeof( * V_183 ) , V_35 ) ;
if ( ! V_183 )
goto V_187;
V_183 -> V_188 = - 1 ;
V_183 -> V_142 = V_184 ;
V_183 -> V_151 = V_151 ;
F_114 ( & V_183 -> V_177 ) ;
F_115 ( V_183 -> V_189 , NULL ) ;
V_183 -> V_47 = V_49 ;
if ( V_162 && V_151 -> V_190 ) {
V_23 = V_151 -> V_190 ( V_162 , V_183 , V_76 ) ;
if ( V_23 < 0 )
goto V_187;
}
if ( V_170 [ 0 ] == '!' ) {
V_151 -> V_191 ( V_170 + 1 , V_184 , V_183 , V_76 ) ;
V_23 = 0 ;
goto V_187;
}
V_23 = V_151 -> V_192 ( V_170 , V_184 , V_183 , V_76 ) ;
if ( ! V_23 ) {
if ( ! ( V_29 -> V_37 || V_29 -> V_38 || V_29 -> V_39 ) )
V_23 = - V_174 ;
goto V_187;
} else if ( V_23 < 0 )
goto V_187;
V_23 = 0 ;
V_25:
return V_23 ;
V_187:
if ( V_151 -> V_190 )
V_151 -> V_190 ( NULL , V_183 , NULL ) ;
F_14 ( V_183 ) ;
F_42 ( V_49 ) ;
goto V_25;
}
T_6 int F_116 ( void )
{
int V_23 ;
V_23 = F_117 ( & V_193 ) ;
F_32 ( V_23 < 0 ) ;
return V_23 ;
}
static void
F_118 ( struct V_117 * V_118 , void * V_112 )
{
struct V_194 * V_195 = V_118 -> V_47 ;
struct V_117 * V_171 ;
F_79 (test, &enable_data->file->triggers, list) {
if ( V_171 -> V_151 -> V_152 == V_153 ) {
if ( V_195 -> V_196 )
V_171 -> V_158 = false ;
else
V_171 -> V_158 = true ;
}
}
}
static void
F_119 ( struct V_117 * V_118 , void * V_112 )
{
if ( ! V_118 -> V_188 )
return;
if ( V_118 -> V_188 != - 1 )
( V_118 -> V_188 ) -- ;
F_118 ( V_118 , V_112 ) ;
}
static struct V_156 *
F_120 ( char * V_161 , char * V_162 )
{
struct V_156 * V_142 ;
bool V_196 ;
V_196 = ( strcmp ( V_161 , V_197 ) == 0 ) ;
if ( V_196 )
V_142 = V_162 ? & V_198 :
& V_199 ;
else
V_142 = V_162 ? & V_200 :
& V_201 ;
return V_142 ;
}
static void F_121 ( struct V_75 * V_76 )
{
struct V_117 * V_171 , * V_141 ;
F_112 (test, n, &file->triggers, list) {
if ( V_171 -> V_151 -> V_152 == V_202 ) {
F_109 ( & V_171 -> V_177 ) ;
F_107 ( V_76 ) ;
F_108 ( V_76 , 0 ) ;
if ( V_171 -> V_142 -> free )
V_171 -> V_142 -> free ( V_171 -> V_142 , V_171 ) ;
}
}
}
static T_6 void F_122 ( void )
{
F_123 ( & V_203 ) ;
F_123 ( & V_204 ) ;
}
T_6 int F_124 ( void )
{
int V_23 ;
V_23 = F_117 ( & V_203 ) ;
if ( F_32 ( V_23 < 0 ) )
return V_23 ;
V_23 = F_117 ( & V_204 ) ;
if ( F_32 ( V_23 < 0 ) )
F_122 () ;
return V_23 ;
}
