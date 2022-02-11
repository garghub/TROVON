static struct V_1 *
F_1 ( const char * V_2 , const char * V_3 , int V_4 )
{
struct V_1 * V_5 ;
if ( ! V_3 || ! F_2 ( V_3 ) )
return F_3 ( - V_6 ) ;
if ( ! V_2 || ! F_2 ( V_2 ) )
return F_3 ( - V_6 ) ;
V_5 = F_4 ( F_5 ( V_4 ) , V_7 ) ;
if ( ! V_5 )
return F_3 ( - V_8 ) ;
V_5 -> V_9 . V_10 = & V_5 -> V_10 ;
V_5 -> V_9 . V_11 = F_6 ( V_3 , V_7 ) ;
if ( ! V_5 -> V_9 . V_11 )
goto error;
V_5 -> V_10 . system = F_6 ( V_2 , V_7 ) ;
if ( ! V_5 -> V_10 . system )
goto error;
F_7 ( & V_5 -> V_12 ) ;
return V_5 ;
error:
F_8 ( V_5 -> V_9 . V_11 ) ;
F_8 ( V_5 ) ;
return F_3 ( - V_8 ) ;
}
static void F_9 ( struct V_1 * V_5 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ )
F_10 ( & V_5 -> args [ V_13 ] ) ;
F_11 ( V_5 -> V_15 ) ;
F_8 ( V_5 -> V_9 . V_10 -> system ) ;
F_8 ( V_5 -> V_9 . V_11 ) ;
F_8 ( V_5 -> V_16 ) ;
F_8 ( V_5 ) ;
}
static struct V_1 * F_12 ( const char * V_3 , const char * V_2 )
{
struct V_1 * V_5 ;
F_13 (tu, &uprobe_list, list)
if ( strcmp ( V_5 -> V_9 . V_11 , V_3 ) == 0 &&
strcmp ( V_5 -> V_9 . V_10 -> system , V_2 ) == 0 )
return V_5 ;
return NULL ;
}
static void F_14 ( struct V_1 * V_5 )
{
F_15 ( & V_5 -> V_12 ) ;
F_16 ( V_5 ) ;
F_9 ( V_5 ) ;
}
static int F_17 ( struct V_1 * V_5 )
{
struct V_1 * V_17 ;
int V_18 ;
F_18 ( & V_19 ) ;
V_17 = F_12 ( V_5 -> V_9 . V_11 , V_5 -> V_9 . V_10 -> system ) ;
if ( V_17 )
F_14 ( V_17 ) ;
V_18 = F_19 ( V_5 ) ;
if ( V_18 ) {
F_20 ( L_1 , V_18 ) ;
goto V_20;
}
F_21 ( & V_5 -> V_12 , & V_21 ) ;
V_20:
F_22 ( & V_19 ) ;
return V_18 ;
}
static int F_23 ( int V_22 , char * * V_23 )
{
struct V_1 * V_5 ;
struct V_15 * V_15 ;
char * V_24 , * V_3 , * V_2 , * V_16 ;
char V_25 [ V_26 ] ;
struct V_27 V_27 ;
unsigned long V_28 ;
bool V_29 ;
int V_13 , V_18 ;
V_15 = NULL ;
V_18 = 0 ;
V_29 = false ;
V_3 = NULL ;
V_2 = NULL ;
if ( V_23 [ 0 ] [ 0 ] == '-' )
V_29 = true ;
else if ( V_23 [ 0 ] [ 0 ] != 'p' ) {
F_24 ( L_2 L_3 ) ;
return - V_6 ;
}
if ( V_23 [ 0 ] [ 1 ] == ':' ) {
V_3 = & V_23 [ 0 ] [ 2 ] ;
V_24 = strchr ( V_3 , '/' ) ;
if ( V_24 ) {
V_2 = V_3 ;
V_3 = V_24 + 1 ;
V_3 [ - 1 ] = '\0' ;
if ( strlen ( V_2 ) == 0 ) {
F_24 ( L_4 ) ;
return - V_6 ;
}
}
if ( strlen ( V_3 ) == 0 ) {
F_24 ( L_5 ) ;
return - V_6 ;
}
}
if ( ! V_2 )
V_2 = V_30 ;
if ( V_29 ) {
if ( ! V_3 ) {
F_24 ( L_6 ) ;
return - V_6 ;
}
F_18 ( & V_19 ) ;
V_5 = F_12 ( V_3 , V_2 ) ;
if ( ! V_5 ) {
F_22 ( & V_19 ) ;
F_24 ( L_7 , V_2 , V_3 ) ;
return - V_31 ;
}
F_14 ( V_5 ) ;
F_22 ( & V_19 ) ;
return 0 ;
}
if ( V_22 < 2 ) {
F_24 ( L_8 ) ;
return - V_6 ;
}
if ( isdigit ( V_23 [ 1 ] [ 0 ] ) ) {
F_24 ( L_9 ) ;
return - V_6 ;
}
V_24 = strchr ( V_23 [ 1 ] , ':' ) ;
if ( ! V_24 )
goto V_32;
* V_24 ++ = '\0' ;
V_16 = V_23 [ 1 ] ;
V_18 = F_25 ( V_16 , V_33 , & V_27 ) ;
if ( V_18 )
goto V_32;
V_18 = F_26 ( V_24 , 0 , & V_28 ) ;
if ( V_18 )
goto V_32;
V_15 = F_27 ( V_27 . V_34 -> V_35 ) ;
V_22 -= 2 ;
V_23 += 2 ;
if ( ! V_3 ) {
char * V_36 = strrchr ( V_16 , '/' ) ;
char * V_37 ;
V_37 = F_6 ( ( V_36 ? V_36 + 1 : V_16 ) , V_7 ) ;
if ( ! V_37 ) {
V_18 = - V_8 ;
goto V_32;
}
V_36 = V_37 ;
V_37 = strpbrk ( V_36 , L_10 ) ;
if ( V_37 )
* V_37 = '\0' ;
snprintf ( V_25 , V_26 , L_11 , 'p' , V_36 , V_28 ) ;
V_3 = V_25 ;
F_8 ( V_36 ) ;
}
V_5 = F_1 ( V_2 , V_3 , V_22 ) ;
if ( F_28 ( V_5 ) ) {
F_24 ( L_12 , ( int ) F_29 ( V_5 ) ) ;
V_18 = F_29 ( V_5 ) ;
goto V_32;
}
V_5 -> V_28 = V_28 ;
V_5 -> V_15 = V_15 ;
V_5 -> V_16 = F_6 ( V_16 , V_7 ) ;
if ( ! V_5 -> V_16 ) {
F_24 ( L_13 ) ;
V_18 = - V_8 ;
goto error;
}
V_18 = 0 ;
for ( V_13 = 0 ; V_13 < V_22 && V_13 < V_38 ; V_13 ++ ) {
V_5 -> V_14 ++ ;
V_24 = strchr ( V_23 [ V_13 ] , '=' ) ;
if ( V_24 ) {
* V_24 ++ = '\0' ;
V_5 -> args [ V_13 ] . V_11 = F_6 ( V_23 [ V_13 ] , V_7 ) ;
} else {
V_24 = V_23 [ V_13 ] ;
snprintf ( V_25 , V_26 , L_14 , V_13 + 1 ) ;
V_5 -> args [ V_13 ] . V_11 = F_6 ( V_25 , V_7 ) ;
}
if ( ! V_5 -> args [ V_13 ] . V_11 ) {
F_24 ( L_15 , V_13 ) ;
V_18 = - V_8 ;
goto error;
}
if ( ! F_2 ( V_5 -> args [ V_13 ] . V_11 ) ) {
F_24 ( L_16 , V_13 , V_5 -> args [ V_13 ] . V_11 ) ;
V_18 = - V_6 ;
goto error;
}
if ( F_30 ( V_5 -> args [ V_13 ] . V_11 , V_5 -> args , V_13 ) ) {
F_24 ( L_17
L_18 , V_13 , V_23 [ V_13 ] ) ;
V_18 = - V_6 ;
goto error;
}
V_18 = F_31 ( V_24 , & V_5 -> V_39 , & V_5 -> args [ V_13 ] , false , false ) ;
if ( V_18 ) {
F_24 ( L_19 , V_13 , V_18 ) ;
goto error;
}
}
V_18 = F_17 ( V_5 ) ;
if ( V_18 )
goto error;
return 0 ;
error:
F_9 ( V_5 ) ;
return V_18 ;
V_32:
if ( V_15 )
F_11 ( V_15 ) ;
F_24 ( L_20 ) ;
return V_18 ;
}
static void F_32 ( void )
{
struct V_1 * V_5 ;
F_18 ( & V_19 ) ;
while ( ! F_33 ( & V_21 ) ) {
V_5 = F_34 ( V_21 . V_40 , struct V_1 , V_12 ) ;
F_14 ( V_5 ) ;
}
F_22 ( & V_19 ) ;
}
static void * F_35 ( struct V_41 * V_42 , T_1 * V_43 )
{
F_18 ( & V_19 ) ;
return F_36 ( & V_21 , * V_43 ) ;
}
static void * F_37 ( struct V_41 * V_42 , void * V_44 , T_1 * V_43 )
{
return F_38 ( V_44 , & V_21 , V_43 ) ;
}
static void F_39 ( struct V_41 * V_42 , void * V_44 )
{
F_22 ( & V_19 ) ;
}
static int F_40 ( struct V_41 * V_42 , void * V_44 )
{
struct V_1 * V_5 = V_44 ;
int V_13 ;
F_41 ( V_42 , L_21 , V_5 -> V_9 . V_10 -> system , V_5 -> V_9 . V_11 ) ;
F_41 ( V_42 , L_22 , V_5 -> V_16 , ( void * ) V_5 -> V_28 ) ;
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ )
F_41 ( V_42 , L_23 , V_5 -> args [ V_13 ] . V_11 , V_5 -> args [ V_13 ] . V_45 ) ;
F_41 ( V_42 , L_24 ) ;
return 0 ;
}
static int F_42 ( struct V_15 * V_15 , struct V_46 * V_46 )
{
if ( ( V_46 -> V_47 & V_48 ) && ( V_46 -> V_49 & V_50 ) )
F_32 () ;
return F_43 ( V_46 , & V_51 ) ;
}
static T_2 F_44 ( struct V_46 * V_46 , const char T_3 * V_52 ,
T_4 V_53 , T_1 * V_54 )
{
return F_45 ( V_46 , V_52 , V_53 , V_54 , F_23 ) ;
}
static int F_46 ( struct V_41 * V_42 , void * V_44 )
{
struct V_1 * V_5 = V_44 ;
F_41 ( V_42 , L_25 , V_5 -> V_16 , V_5 -> V_9 . V_11 , V_5 -> V_55 ) ;
return 0 ;
}
static int F_47 ( struct V_15 * V_15 , struct V_46 * V_46 )
{
return F_43 ( V_46 , & V_56 ) ;
}
static void F_48 ( struct V_1 * V_5 , struct V_57 * V_58 )
{
struct V_59 * V_60 ;
struct V_61 * V_3 ;
struct V_62 * V_52 ;
T_5 * V_63 ;
int V_39 , V_13 , V_64 ;
unsigned long V_65 ;
struct V_66 * V_9 = & V_5 -> V_9 ;
V_5 -> V_55 ++ ;
F_49 ( V_65 ) ;
V_64 = F_50 () ;
V_39 = sizeof( * V_60 ) + V_5 -> V_39 ;
V_3 = F_51 ( & V_52 , V_9 -> V_3 . type ,
V_39 , V_65 , V_64 ) ;
if ( ! V_3 )
return;
V_60 = F_52 ( V_3 ) ;
V_60 -> V_67 = F_53 ( F_54 ( V_68 ) ) ;
V_63 = ( T_5 * ) & V_60 [ 1 ] ;
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ )
F_55 ( & V_5 -> args [ V_13 ] . V_69 , V_58 , V_63 + V_5 -> args [ V_13 ] . V_28 ) ;
if ( ! F_56 ( V_52 , V_9 , V_60 , V_3 ) )
F_57 ( V_52 , V_3 , V_65 , V_64 ) ;
}
static enum V_70
F_58 ( struct V_71 * V_72 , int V_73 , struct V_74 * V_3 )
{
struct V_59 * V_75 ;
struct V_76 * V_77 = & V_72 -> V_78 ;
struct V_1 * V_5 ;
T_5 * V_63 ;
int V_13 ;
V_75 = (struct V_59 * ) V_72 -> V_79 ;
V_5 = F_59 ( V_3 , struct V_1 , V_9 . V_3 ) ;
if ( ! F_60 ( V_77 , L_26 , V_5 -> V_9 . V_11 ) )
goto V_80;
if ( ! F_61 ( V_77 , V_75 -> V_67 , V_73 | V_81 ) )
goto V_80;
if ( ! F_62 ( V_77 , L_27 ) )
goto V_80;
V_63 = ( T_5 * ) & V_75 [ 1 ] ;
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ ) {
if ( ! V_5 -> args [ V_13 ] . type -> V_82 ( V_77 , V_5 -> args [ V_13 ] . V_11 ,
V_63 + V_5 -> args [ V_13 ] . V_28 , V_75 ) )
goto V_80;
}
if ( F_62 ( V_77 , L_24 ) )
return V_83 ;
V_80:
return V_84 ;
}
static int F_63 ( struct V_1 * V_5 , int V_85 )
{
struct V_86 * V_87 ;
int V_18 = 0 ;
if ( ! V_5 -> V_15 || V_5 -> V_88 )
return - V_89 ;
V_87 = F_4 ( sizeof( struct V_86 ) , V_7 ) ;
if ( ! V_87 )
return - V_89 ;
V_87 -> V_90 . V_91 = V_92 ;
V_87 -> V_90 . V_93 = NULL ;
V_18 = F_64 ( V_5 -> V_15 , V_5 -> V_28 , & V_87 -> V_90 ) ;
if ( V_18 ) {
F_8 ( V_87 ) ;
return V_18 ;
}
V_5 -> V_73 |= V_85 ;
V_87 -> V_5 = V_5 ;
V_5 -> V_88 = V_87 ;
return 0 ;
}
static void F_65 ( struct V_1 * V_5 , int V_85 )
{
if ( ! V_5 -> V_15 || ! V_5 -> V_88 )
return;
F_66 ( V_5 -> V_15 , V_5 -> V_28 , & V_5 -> V_88 -> V_90 ) ;
V_5 -> V_73 &= ~ V_85 ;
F_8 ( V_5 -> V_88 ) ;
V_5 -> V_88 = NULL ;
}
static int F_67 ( struct V_66 * V_94 )
{
int V_18 , V_13 ;
struct V_59 V_75 ;
struct V_1 * V_5 = (struct V_1 * ) V_94 -> V_63 ;
F_68 (unsigned long, ip, FIELD_STRING_IP, 0 ) ;
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ ) {
V_18 = F_69 ( V_94 , V_5 -> args [ V_13 ] . type -> V_95 ,
V_5 -> args [ V_13 ] . V_11 ,
sizeof( V_75 ) + V_5 -> args [ V_13 ] . V_28 ,
V_5 -> args [ V_13 ] . type -> V_39 ,
V_5 -> args [ V_13 ] . type -> V_96 ,
V_97 ) ;
if ( V_18 )
return V_18 ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_5 , char * V_25 , int V_98 )
{
const char * V_99 , * V_24 ;
int V_13 ;
int V_43 = 0 ;
V_99 = L_28 ;
V_24 = L_29 V_100 ;
V_43 += snprintf ( V_25 + V_43 , V_101 , L_30 , V_99 ) ;
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ ) {
V_43 += snprintf ( V_25 + V_43 , V_101 , L_23 ,
V_5 -> args [ V_13 ] . V_11 , V_5 -> args [ V_13 ] . type -> V_99 ) ;
}
V_43 += snprintf ( V_25 + V_43 , V_101 , L_31 , V_24 ) ;
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ ) {
V_43 += snprintf ( V_25 + V_43 , V_101 , L_32 ,
V_5 -> args [ V_13 ] . V_11 ) ;
}
return V_43 ;
}
static int F_71 ( struct V_1 * V_5 )
{
char * V_102 ;
int V_98 ;
V_98 = F_70 ( V_5 , NULL , 0 ) ;
V_102 = F_72 ( V_98 + 1 , V_7 ) ;
if ( ! V_102 )
return - V_8 ;
F_70 ( V_5 , V_102 , V_98 + 1 ) ;
V_5 -> V_9 . V_102 = V_102 ;
return 0 ;
}
static void F_73 ( struct V_1 * V_5 , struct V_57 * V_58 )
{
struct V_66 * V_9 = & V_5 -> V_9 ;
struct V_59 * V_60 ;
struct V_103 * V_104 ;
T_5 * V_63 ;
int V_39 , V_105 , V_13 ;
int V_106 ;
V_105 = sizeof( * V_60 ) + V_5 -> V_39 ;
V_39 = F_74 ( V_105 + sizeof( V_107 ) , sizeof( V_108 ) ) ;
V_39 -= sizeof( V_107 ) ;
if ( F_75 ( V_39 > V_109 , L_33 ) )
return;
F_76 () ;
V_60 = F_77 ( V_39 , V_9 -> V_3 . type , V_58 , & V_106 ) ;
if ( ! V_60 )
goto V_110;
V_60 -> V_67 = F_53 ( F_54 ( V_68 ) ) ;
V_63 = ( T_5 * ) & V_60 [ 1 ] ;
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ )
F_55 ( & V_5 -> args [ V_13 ] . V_69 , V_58 , V_63 + V_5 -> args [ V_13 ] . V_28 ) ;
V_104 = F_78 ( V_9 -> V_111 ) ;
F_79 ( V_60 , V_39 , V_106 , V_60 -> V_67 , 1 , V_58 , V_104 , NULL ) ;
V_110:
F_80 () ;
}
static
int F_81 ( struct V_66 * V_3 , enum V_112 type , void * V_63 )
{
struct V_1 * V_5 = (struct V_1 * ) V_3 -> V_63 ;
switch ( type ) {
case V_113 :
return F_63 ( V_5 , V_114 ) ;
case V_115 :
F_65 ( V_5 , V_114 ) ;
return 0 ;
#ifdef F_82
case V_116 :
return F_63 ( V_5 , V_117 ) ;
case V_118 :
F_65 ( V_5 , V_117 ) ;
return 0 ;
#endif
default:
return 0 ;
}
return 0 ;
}
static int V_92 ( struct V_119 * V_120 , struct V_57 * V_58 )
{
struct V_86 * V_87 ;
struct V_1 * V_5 ;
V_87 = F_59 ( V_120 , struct V_86 , V_90 ) ;
V_5 = V_87 -> V_5 ;
if ( ! V_5 || V_5 -> V_88 != V_87 )
return 0 ;
if ( V_5 -> V_73 & V_114 )
F_48 ( V_5 , V_58 ) ;
#ifdef F_82
if ( V_5 -> V_73 & V_117 )
F_73 ( V_5 , V_58 ) ;
#endif
return 0 ;
}
static int F_19 ( struct V_1 * V_5 )
{
struct V_66 * V_9 = & V_5 -> V_9 ;
int V_18 ;
F_7 ( & V_9 -> V_10 -> V_121 ) ;
V_9 -> V_3 . V_122 = & V_123 ;
V_9 -> V_10 -> V_124 = F_67 ;
if ( F_71 ( V_5 ) < 0 )
return - V_8 ;
V_18 = F_83 ( & V_9 -> V_3 ) ;
if ( ! V_18 ) {
F_8 ( V_9 -> V_102 ) ;
return - V_125 ;
}
V_9 -> V_73 = 0 ;
V_9 -> V_10 -> V_126 = F_81 ;
V_9 -> V_63 = V_5 ;
V_18 = F_84 ( V_9 ) ;
if ( V_18 ) {
F_24 ( L_34 , V_9 -> V_11 ) ;
F_8 ( V_9 -> V_102 ) ;
F_85 ( & V_9 -> V_3 ) ;
}
return V_18 ;
}
static void F_16 ( struct V_1 * V_5 )
{
F_86 ( & V_5 -> V_9 ) ;
F_8 ( V_5 -> V_9 . V_102 ) ;
V_5 -> V_9 . V_102 = NULL ;
}
static T_6 int F_87 ( void )
{
struct V_34 * V_127 ;
V_127 = F_88 () ;
if ( ! V_127 )
return 0 ;
F_89 ( L_35 , 0644 , V_127 ,
NULL , & V_128 ) ;
F_89 ( L_36 , 0444 , V_127 ,
NULL , & V_129 ) ;
return 0 ;
}
