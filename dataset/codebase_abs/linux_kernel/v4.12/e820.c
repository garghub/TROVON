bool F_1 ( T_1 V_1 , T_1 V_2 , enum V_3 type )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_4 ] ;
if ( type && V_8 -> type != type )
continue;
if ( V_8 -> V_10 >= V_2 || V_8 -> V_10 + V_8 -> V_11 <= V_1 )
continue;
return 1 ;
}
return 0 ;
}
bool T_2 F_2 ( T_1 V_1 , T_1 V_2 , enum V_3 type )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_4 ] ;
if ( type && V_8 -> type != type )
continue;
if ( V_8 -> V_10 >= V_2 || V_8 -> V_10 + V_8 -> V_11 <= V_1 )
continue;
if ( V_8 -> V_10 <= V_1 )
V_1 = V_8 -> V_10 + V_8 -> V_11 ;
if ( V_1 >= V_2 )
return 1 ;
}
return 0 ;
}
static void T_2 F_3 ( struct V_5 * V_12 , T_1 V_1 , T_1 V_11 , enum V_3 type )
{
int V_13 = V_12 -> V_6 ;
if ( V_13 >= F_4 ( V_12 -> V_9 ) ) {
F_5 ( L_1 , V_1 , V_1 + V_11 - 1 ) ;
return;
}
V_12 -> V_9 [ V_13 ] . V_10 = V_1 ;
V_12 -> V_9 [ V_13 ] . V_11 = V_11 ;
V_12 -> V_9 [ V_13 ] . type = type ;
V_12 -> V_6 ++ ;
}
void T_2 F_6 ( T_1 V_1 , T_1 V_11 , enum V_3 type )
{
F_3 ( V_5 , V_1 , V_11 , type ) ;
}
static void T_2 F_7 ( enum V_3 type )
{
switch ( type ) {
case V_14 :
case V_15 : F_8 ( L_2 ) ; break;
case V_16 : F_8 ( L_3 ) ; break;
case V_17 : F_8 ( L_4 ) ; break;
case V_18 : F_8 ( L_5 ) ; break;
case V_19 : F_8 ( L_6 ) ; break;
case V_20 :
case V_21 : F_8 ( L_7 , type ) ; break;
default: F_8 ( L_8 , type ) ; break;
}
}
void T_2 F_9 ( char * V_22 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
F_10 ( L_9 , V_22 ,
V_5 -> V_9 [ V_4 ] . V_10 ,
V_5 -> V_9 [ V_4 ] . V_10 + V_5 -> V_9 [ V_4 ] . V_11 - 1 ) ;
F_7 ( V_5 -> V_9 [ V_4 ] . type ) ;
F_8 ( L_10 ) ;
}
}
static int T_2 F_11 ( const void * V_23 , const void * V_24 )
{
struct V_25 * const * V_26 = V_23 , * const * V_27 = V_24 ;
const struct V_25 * V_28 = * V_26 , * V_29 = * V_27 ;
if ( V_28 -> V_10 != V_29 -> V_10 )
return V_28 -> V_10 > V_29 -> V_10 ? 1 : - 1 ;
return ( V_28 -> V_10 != V_28 -> V_8 -> V_10 ) - ( V_29 -> V_10 != V_29 -> V_8 -> V_10 ) ;
}
int T_2 F_12 ( struct V_5 * V_12 )
{
struct V_7 * V_9 = V_12 -> V_9 ;
T_3 V_30 = F_4 ( V_12 -> V_9 ) ;
enum V_3 V_31 , V_32 ;
unsigned long long V_33 ;
T_3 V_34 , V_35 ;
T_3 V_4 , V_36 , V_37 ;
if ( V_12 -> V_6 < 2 )
return - 1 ;
F_13 ( V_12 -> V_6 > V_30 ) ;
for ( V_4 = 0 ; V_4 < V_12 -> V_6 ; V_4 ++ ) {
if ( V_9 [ V_4 ] . V_10 + V_9 [ V_4 ] . V_11 < V_9 [ V_4 ] . V_10 )
return - 1 ;
}
for ( V_4 = 0 ; V_4 < 2 * V_12 -> V_6 ; V_4 ++ )
V_38 [ V_4 ] = & V_39 [ V_4 ] ;
V_36 = 0 ;
for ( V_4 = 0 ; V_4 < V_12 -> V_6 ; V_4 ++ ) {
if ( V_9 [ V_4 ] . V_11 != 0 ) {
V_38 [ V_36 ] -> V_10 = V_9 [ V_4 ] . V_10 ;
V_38 [ V_36 ++ ] -> V_8 = & V_9 [ V_4 ] ;
V_38 [ V_36 ] -> V_10 = V_9 [ V_4 ] . V_10 + V_9 [ V_4 ] . V_11 ;
V_38 [ V_36 ++ ] -> V_8 = & V_9 [ V_4 ] ;
}
}
V_37 = V_36 ;
F_14 ( V_38 , V_37 , sizeof( * V_38 ) , F_11 , NULL ) ;
V_35 = 0 ;
V_34 = 0 ;
V_32 = 0 ;
V_33 = 0 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
if ( V_38 [ V_36 ] -> V_10 == V_38 [ V_36 ] -> V_8 -> V_10 ) {
V_40 [ V_35 ++ ] = V_38 [ V_36 ] -> V_8 ;
} else {
for ( V_4 = 0 ; V_4 < V_35 ; V_4 ++ ) {
if ( V_40 [ V_4 ] == V_38 [ V_36 ] -> V_8 )
V_40 [ V_4 ] = V_40 [ V_35 - 1 ] ;
}
V_35 -- ;
}
V_31 = 0 ;
for ( V_4 = 0 ; V_4 < V_35 ; V_4 ++ ) {
if ( V_40 [ V_4 ] -> type > V_31 )
V_31 = V_40 [ V_4 ] -> type ;
}
if ( V_31 != V_32 || V_31 == V_21 ) {
if ( V_32 != 0 ) {
V_41 [ V_34 ] . V_11 = V_38 [ V_36 ] -> V_10 - V_33 ;
if ( V_41 [ V_34 ] . V_11 != 0 )
if ( ++ V_34 >= V_30 )
break;
}
if ( V_31 != 0 ) {
V_41 [ V_34 ] . V_10 = V_38 [ V_36 ] -> V_10 ;
V_41 [ V_34 ] . type = V_31 ;
V_33 = V_38 [ V_36 ] -> V_10 ;
}
V_32 = V_31 ;
}
}
memcpy ( V_9 , V_41 , V_34 * sizeof( * V_9 ) ) ;
V_12 -> V_6 = V_34 ;
return 0 ;
}
static int T_2 F_15 ( struct V_42 * V_9 , T_3 V_6 )
{
struct V_42 * V_8 = V_9 ;
while ( V_6 ) {
T_1 V_1 = V_8 -> V_10 ;
T_1 V_11 = V_8 -> V_11 ;
T_1 V_2 = V_1 + V_11 - 1 ;
T_3 type = V_8 -> type ;
if ( V_1 > V_2 && F_16 ( V_11 ) )
return - 1 ;
F_6 ( V_1 , V_11 , type ) ;
V_8 ++ ;
V_6 -- ;
}
return 0 ;
}
static int T_2 F_17 ( struct V_42 * V_9 , T_3 V_6 )
{
if ( V_6 < 2 )
return - 1 ;
return F_15 ( V_9 , V_6 ) ;
}
static T_1 T_2
F_18 ( struct V_5 * V_12 , T_1 V_1 , T_1 V_11 , enum V_3 V_43 , enum V_3 V_44 )
{
T_1 V_2 ;
unsigned int V_4 ;
T_1 V_45 = 0 ;
F_13 ( V_43 == V_44 ) ;
if ( V_11 > ( V_46 - V_1 ) )
V_11 = V_46 - V_1 ;
V_2 = V_1 + V_11 ;
F_19 ( V_47 L_11 , V_1 , V_2 - 1 ) ;
F_7 ( V_43 ) ;
F_8 ( L_12 ) ;
F_7 ( V_44 ) ;
F_8 ( L_10 ) ;
for ( V_4 = 0 ; V_4 < V_12 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_12 -> V_9 [ V_4 ] ;
T_1 V_48 , V_49 ;
T_1 V_50 ;
if ( V_8 -> type != V_43 )
continue;
V_50 = V_8 -> V_10 + V_8 -> V_11 ;
if ( V_8 -> V_10 >= V_1 && V_50 <= V_2 ) {
V_8 -> type = V_44 ;
V_45 += V_8 -> V_11 ;
continue;
}
if ( V_8 -> V_10 < V_1 && V_50 > V_2 ) {
F_3 ( V_12 , V_1 , V_11 , V_44 ) ;
F_3 ( V_12 , V_2 , V_50 - V_2 , V_8 -> type ) ;
V_8 -> V_11 = V_1 - V_8 -> V_10 ;
V_45 += V_11 ;
continue;
}
V_48 = F_20 ( V_1 , V_8 -> V_10 ) ;
V_49 = F_21 ( V_2 , V_50 ) ;
if ( V_48 >= V_49 )
continue;
F_3 ( V_12 , V_48 , V_49 - V_48 , V_44 ) ;
V_45 += V_49 - V_48 ;
V_8 -> V_11 -= V_49 - V_48 ;
if ( V_8 -> V_10 < V_48 )
continue;
V_8 -> V_10 = V_49 ;
}
return V_45 ;
}
T_1 T_2 F_22 ( T_1 V_1 , T_1 V_11 , enum V_3 V_43 , enum V_3 V_44 )
{
return F_18 ( V_5 , V_1 , V_11 , V_43 , V_44 ) ;
}
static T_1 T_2 F_23 ( T_1 V_1 , T_1 V_11 , enum V_3 V_43 , enum V_3 V_44 )
{
return F_18 ( V_51 , V_1 , V_11 , V_43 , V_44 ) ;
}
T_1 T_2 F_24 ( T_1 V_1 , T_1 V_11 , enum V_3 V_43 , bool V_52 )
{
int V_4 ;
T_1 V_2 ;
T_1 V_53 = 0 ;
if ( V_11 > ( V_46 - V_1 ) )
V_11 = V_46 - V_1 ;
V_2 = V_1 + V_11 ;
F_19 ( V_47 L_13 , V_1 , V_2 - 1 ) ;
if ( V_52 )
F_7 ( V_43 ) ;
F_8 ( L_10 ) ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_4 ] ;
T_1 V_48 , V_49 ;
T_1 V_50 ;
if ( V_52 && V_8 -> type != V_43 )
continue;
V_50 = V_8 -> V_10 + V_8 -> V_11 ;
if ( V_8 -> V_10 >= V_1 && V_50 <= V_2 ) {
V_53 += V_8 -> V_11 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
continue;
}
if ( V_8 -> V_10 < V_1 && V_50 > V_2 ) {
F_6 ( V_2 , V_50 - V_2 , V_8 -> type ) ;
V_8 -> V_11 = V_1 - V_8 -> V_10 ;
V_53 += V_11 ;
continue;
}
V_48 = F_20 ( V_1 , V_8 -> V_10 ) ;
V_49 = F_21 ( V_2 , V_50 ) ;
if ( V_48 >= V_49 )
continue;
V_53 += V_49 - V_48 ;
V_8 -> V_11 -= V_49 - V_48 ;
if ( V_8 -> V_10 < V_48 )
continue;
V_8 -> V_10 = V_49 ;
}
return V_53 ;
}
void T_2 F_25 ( void )
{
if ( F_12 ( V_5 ) )
return;
F_10 ( L_14 ) ;
F_9 ( L_15 ) ;
}
static void T_2 F_26 ( void )
{
F_12 ( V_51 ) ;
}
static int T_2 F_27 ( unsigned long * V_54 , unsigned long * V_55 )
{
unsigned long long V_56 = V_57 ;
int V_4 = V_5 -> V_6 ;
int V_58 = 0 ;
while ( -- V_4 >= 0 ) {
unsigned long long V_1 = V_5 -> V_9 [ V_4 ] . V_10 ;
unsigned long long V_2 = V_1 + V_5 -> V_9 [ V_4 ] . V_11 ;
if ( V_56 > V_2 ) {
unsigned long V_59 = V_56 - V_2 ;
if ( V_59 >= * V_55 ) {
* V_55 = V_59 ;
* V_54 = V_2 ;
V_58 = 1 ;
}
}
if ( V_1 < V_56 )
V_56 = V_1 ;
}
return V_58 ;
}
T_2 void F_28 ( void )
{
unsigned long V_54 , V_55 ;
int V_58 ;
V_55 = 0x400000 ;
V_58 = F_27 ( & V_54 , & V_55 ) ;
if ( ! V_58 ) {
#ifdef F_29
V_54 = ( V_60 << V_61 ) + 1024 * 1024 ;
F_5 (
L_16
L_17 ) ;
#else
V_54 = 0x10000000 ;
#endif
}
V_62 = V_54 ;
F_10 ( L_18 , V_54 , V_54 + V_55 - 1 ) ;
}
T_2 void F_30 ( void )
{
struct V_5 * V_63 ;
int V_11 ;
V_11 = F_31 ( struct V_5 , V_9 ) + sizeof( struct V_7 ) * V_5 -> V_6 ;
V_63 = F_32 ( V_11 , V_64 ) ;
F_13 ( ! V_63 ) ;
memcpy ( V_63 , V_5 , V_11 ) ;
V_5 = V_63 ;
V_11 = F_31 ( struct V_5 , V_9 ) + sizeof( struct V_7 ) * V_51 -> V_6 ;
V_63 = F_32 ( V_11 , V_64 ) ;
F_13 ( ! V_63 ) ;
memcpy ( V_63 , V_51 , V_11 ) ;
V_51 = V_63 ;
}
void T_2 F_33 ( T_1 V_65 , T_3 V_66 )
{
int V_9 ;
struct V_42 * V_67 ;
struct V_68 * V_69 ;
V_69 = F_34 ( V_65 , V_66 ) ;
V_9 = V_69 -> V_70 / sizeof( * V_67 ) ;
V_67 = (struct V_42 * ) ( V_69 -> V_71 ) ;
F_15 ( V_67 , V_9 ) ;
F_12 ( V_5 ) ;
F_35 ( V_69 , V_66 ) ;
F_10 ( L_19 ) ;
F_9 ( L_20 ) ;
}
void T_2 F_36 ( unsigned long V_72 )
{
int V_4 ;
unsigned long V_73 = 0 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_4 ] ;
if ( V_73 < F_37 ( V_8 -> V_10 ) )
F_38 ( V_73 , F_37 ( V_8 -> V_10 ) ) ;
V_73 = F_39 ( V_8 -> V_10 + V_8 -> V_11 ) ;
if ( V_8 -> type != V_14 && V_8 -> type != V_15 )
F_38 ( F_37 ( V_8 -> V_10 ) , V_73 ) ;
if ( V_73 >= V_72 )
break;
}
}
static int T_2 F_40 ( void )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_4 ] ;
if ( V_8 -> type == V_18 )
F_41 ( V_8 -> V_10 , V_8 -> V_11 ) ;
}
return 0 ;
}
T_1 T_2 F_42 ( T_1 V_11 , T_1 V_74 )
{
T_1 V_10 ;
V_10 = F_43 ( V_11 , V_74 , V_75 ) ;
if ( V_10 ) {
F_23 ( V_10 , V_11 , V_14 , V_16 ) ;
F_10 ( L_21 ) ;
F_26 () ;
}
return V_10 ;
}
static unsigned long T_2 F_44 ( unsigned long V_72 , enum V_3 type )
{
int V_4 ;
unsigned long V_76 = 0 ;
unsigned long V_77 = V_78 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_4 ] ;
unsigned long V_79 ;
unsigned long V_80 ;
if ( V_8 -> type != type )
continue;
V_79 = V_8 -> V_10 >> V_61 ;
V_80 = ( V_8 -> V_10 + V_8 -> V_11 ) >> V_61 ;
if ( V_79 >= V_72 )
continue;
if ( V_80 > V_72 ) {
V_76 = V_72 ;
break;
}
if ( V_80 > V_76 )
V_76 = V_80 ;
}
if ( V_76 > V_77 )
V_76 = V_77 ;
F_10 ( L_22 ,
V_76 , V_77 ) ;
return V_76 ;
}
unsigned long T_2 F_45 ( void )
{
return F_44 ( V_78 , V_14 ) ;
}
unsigned long T_2 F_46 ( void )
{
return F_44 ( 1UL << ( 32 - V_61 ) , V_14 ) ;
}
static void T_2 F_47 ( char * V_81 )
{
F_48 ( V_81 ) ;
F_49 ( V_81 ) ;
}
static int T_2 F_50 ( char * V_82 )
{
T_1 V_83 ;
if ( ! V_82 )
return - V_84 ;
if ( ! strcmp ( V_82 , L_23 ) ) {
#ifdef F_51
F_52 ( V_85 ) ;
return 0 ;
#else
F_53 ( L_24 ) ;
return - V_84 ;
#endif
}
V_86 = 1 ;
V_83 = F_54 ( V_82 , & V_82 ) ;
if ( V_83 == 0 )
return - V_84 ;
F_24 ( V_83 , V_46 - V_83 , V_14 , 1 ) ;
return 0 ;
}
static int T_2 F_55 ( char * V_82 )
{
char * V_87 ;
T_1 V_88 , V_83 ;
if ( ! V_82 )
return - V_84 ;
if ( ! strncmp ( V_82 , L_25 , 8 ) ) {
#ifdef F_56
V_89 = F_45 () ;
#endif
V_5 -> V_6 = 0 ;
V_86 = 1 ;
return 0 ;
}
V_87 = V_82 ;
V_83 = F_54 ( V_82 , & V_82 ) ;
if ( V_82 == V_87 )
return - V_84 ;
V_86 = 1 ;
if ( * V_82 == '@' ) {
V_88 = F_54 ( V_82 + 1 , & V_82 ) ;
F_6 ( V_88 , V_83 , V_14 ) ;
} else if ( * V_82 == '#' ) {
V_88 = F_54 ( V_82 + 1 , & V_82 ) ;
F_6 ( V_88 , V_83 , V_17 ) ;
} else if ( * V_82 == '$' ) {
V_88 = F_54 ( V_82 + 1 , & V_82 ) ;
F_6 ( V_88 , V_83 , V_16 ) ;
} else if ( * V_82 == '!' ) {
V_88 = F_54 ( V_82 + 1 , & V_82 ) ;
F_6 ( V_88 , V_83 , V_21 ) ;
} else {
F_24 ( V_83 , V_46 - V_83 , V_14 , 1 ) ;
}
return * V_82 == '\0' ? 0 : - V_84 ;
}
static int T_2 F_57 ( char * V_90 )
{
while ( V_90 ) {
char * V_91 = strchr ( V_90 , ',' ) ;
if ( V_91 )
* V_91 ++ = 0 ;
F_55 ( V_90 ) ;
V_90 = V_91 ;
}
return 0 ;
}
void T_2 F_58 ( void )
{
struct V_68 * V_71 ;
T_1 V_92 ;
V_92 = V_93 . V_94 . V_68 ;
if ( ! V_92 )
return;
while ( V_92 ) {
V_71 = F_34 ( V_92 , sizeof( * V_71 ) ) ;
F_22 ( V_92 , sizeof( * V_71 ) + V_71 -> V_70 , V_14 , V_15 ) ;
V_92 = V_71 -> V_95 ;
F_35 ( V_71 , sizeof( * V_71 ) ) ;
}
F_12 ( V_5 ) ;
memcpy ( V_51 , V_5 , sizeof( * V_51 ) ) ;
F_10 ( L_26 ) ;
F_9 ( L_27 ) ;
}
void T_2 F_59 ( void )
{
if ( V_86 ) {
if ( F_12 ( V_5 ) < 0 )
F_47 ( L_28 ) ;
F_10 ( L_29 ) ;
F_9 ( L_30 ) ;
}
}
static const char * T_2 F_60 ( struct V_7 * V_8 )
{
switch ( V_8 -> type ) {
case V_15 :
case V_14 : return L_31 ;
case V_17 : return L_32 ;
case V_18 : return L_33 ;
case V_19 : return L_34 ;
case V_21 : return L_35 ;
case V_20 : return L_36 ;
case V_16 : return L_37 ;
default: return L_38 ;
}
}
static unsigned long T_2 F_61 ( struct V_7 * V_8 )
{
switch ( V_8 -> type ) {
case V_15 :
case V_14 : return V_96 ;
case V_17 :
case V_18 :
case V_19 :
case V_21 :
case V_20 :
case V_16 :
default: return V_97 ;
}
}
static unsigned long T_2 F_62 ( struct V_7 * V_8 )
{
switch ( V_8 -> type ) {
case V_17 : return V_98 ;
case V_18 : return V_99 ;
case V_20 : return V_100 ;
case V_21 : return V_101 ;
case V_15 :
case V_14 :
case V_19 :
case V_16 :
default: return V_102 ;
}
}
static bool T_2 F_63 ( enum V_3 type , struct V_103 * V_104 )
{
if ( V_104 -> V_1 < ( 1ULL << 20 ) )
return true ;
switch ( type ) {
case V_16 :
case V_21 :
case V_20 :
return false ;
case V_15 :
case V_14 :
case V_17 :
case V_18 :
case V_19 :
default:
return true ;
}
}
void T_2 F_64 ( void )
{
int V_4 ;
struct V_103 * V_104 ;
T_1 V_2 ;
V_104 = F_65 ( sizeof( * V_104 ) * V_5 -> V_6 ) ;
V_105 = V_104 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = V_5 -> V_9 + V_4 ;
V_2 = V_8 -> V_10 + V_8 -> V_11 - 1 ;
if ( V_2 != ( V_106 ) V_2 ) {
V_104 ++ ;
continue;
}
V_104 -> V_1 = V_8 -> V_10 ;
V_104 -> V_2 = V_2 ;
V_104 -> V_107 = F_60 ( V_8 ) ;
V_104 -> V_108 = F_61 ( V_8 ) ;
V_104 -> V_109 = F_62 ( V_8 ) ;
if ( F_63 ( V_8 -> type , V_104 ) ) {
V_104 -> V_108 |= V_110 ;
F_66 ( & V_111 , V_104 ) ;
}
V_104 ++ ;
}
for ( V_4 = 0 ; V_4 < V_51 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = V_51 -> V_9 + V_4 ;
F_67 ( V_8 -> V_10 , V_8 -> V_10 + V_8 -> V_11 , F_60 ( V_8 ) ) ;
}
}
static unsigned long T_2 F_68 ( V_106 V_112 )
{
unsigned long V_113 = V_112 >> 20 ;
if ( ! V_113 )
return 64 * 1024 ;
if ( V_113 < 16 )
return 1024 * 1024 ;
return 64 * 1024 * 1024 ;
}
void T_2 F_69 ( void )
{
int V_4 ;
struct V_103 * V_104 ;
V_104 = V_105 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
if ( ! V_104 -> V_114 && V_104 -> V_2 )
F_70 ( & V_111 , V_104 ) ;
V_104 ++ ;
}
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_4 ] ;
T_1 V_1 , V_2 ;
if ( V_8 -> type != V_14 )
continue;
V_1 = V_8 -> V_10 + V_8 -> V_11 ;
V_2 = F_71 ( V_1 , F_68 ( V_1 ) ) - 1 ;
if ( V_2 > V_115 )
V_2 = V_115 ;
if ( V_1 >= V_2 )
continue;
F_19 ( V_47 L_39 , V_1 , V_2 ) ;
F_72 ( & V_111 , V_1 , V_2 , L_40 ) ;
}
}
char * T_2 F_73 ( void )
{
char * V_22 = L_41 ;
if ( F_17 ( V_93 . V_5 , V_93 . V_116 ) < 0 ) {
T_1 V_83 ;
if ( V_93 . V_117 < V_93 . V_118 . V_119 ) {
V_83 = V_93 . V_118 . V_119 ;
V_22 = L_42 ;
} else {
V_83 = V_93 . V_117 ;
V_22 = L_43 ;
}
V_5 -> V_6 = 0 ;
F_6 ( 0 , F_74 () , V_14 ) ;
F_6 ( V_120 , V_83 << 10 , V_14 ) ;
}
F_12 ( V_5 ) ;
return V_22 ;
}
void T_2 F_75 ( void )
{
char * V_22 ;
F_76 ( sizeof( struct V_42 ) != 20 ) ;
V_22 = V_121 . V_122 . V_123 () ;
memcpy ( V_51 , V_5 , sizeof( * V_51 ) ) ;
F_10 ( L_44 ) ;
F_9 ( V_22 ) ;
}
void T_2 F_77 ( void )
{
int V_4 ;
T_1 V_2 ;
F_78 () ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_4 ] ;
V_2 = V_8 -> V_10 + V_8 -> V_11 ;
if ( V_2 != ( V_106 ) V_2 )
continue;
if ( V_8 -> type != V_14 && V_8 -> type != V_15 )
continue;
F_79 ( V_8 -> V_10 , V_8 -> V_11 ) ;
}
F_80 ( V_124 ) ;
F_81 () ;
}
