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
static struct V_7 * F_2 ( T_1 V_1 , T_1 V_2 ,
enum V_3 type )
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
return V_8 ;
}
return NULL ;
}
bool T_2 F_3 ( T_1 V_1 , T_1 V_2 , enum V_3 type )
{
return F_2 ( V_1 , V_2 , type ) ;
}
int F_4 ( T_1 V_1 , T_1 V_2 )
{
struct V_7 * V_8 = F_2 ( V_1 , V_2 , 0 ) ;
return V_8 ? V_8 -> type : - V_12 ;
}
static void T_2 F_5 ( struct V_5 * V_13 , T_1 V_1 , T_1 V_11 , enum V_3 type )
{
int V_14 = V_13 -> V_6 ;
if ( V_14 >= F_6 ( V_13 -> V_9 ) ) {
F_7 ( L_1 , V_1 , V_1 + V_11 - 1 ) ;
return;
}
V_13 -> V_9 [ V_14 ] . V_10 = V_1 ;
V_13 -> V_9 [ V_14 ] . V_11 = V_11 ;
V_13 -> V_9 [ V_14 ] . type = type ;
V_13 -> V_6 ++ ;
}
void T_2 F_8 ( T_1 V_1 , T_1 V_11 , enum V_3 type )
{
F_5 ( V_5 , V_1 , V_11 , type ) ;
}
static void T_2 F_9 ( enum V_3 type )
{
switch ( type ) {
case V_15 :
case V_16 : F_10 ( L_2 ) ; break;
case V_17 : F_10 ( L_3 ) ; break;
case V_18 : F_10 ( L_4 ) ; break;
case V_19 : F_10 ( L_5 ) ; break;
case V_20 : F_10 ( L_6 ) ; break;
case V_21 :
case V_22 : F_10 ( L_7 , type ) ; break;
default: F_10 ( L_8 , type ) ; break;
}
}
void T_2 F_11 ( char * V_23 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
F_12 ( L_9 , V_23 ,
V_5 -> V_9 [ V_4 ] . V_10 ,
V_5 -> V_9 [ V_4 ] . V_10 + V_5 -> V_9 [ V_4 ] . V_11 - 1 ) ;
F_9 ( V_5 -> V_9 [ V_4 ] . type ) ;
F_10 ( L_10 ) ;
}
}
static int T_2 F_13 ( const void * V_24 , const void * V_25 )
{
struct V_26 * const * V_27 = V_24 , * const * V_28 = V_25 ;
const struct V_26 * V_29 = * V_27 , * V_30 = * V_28 ;
if ( V_29 -> V_10 != V_30 -> V_10 )
return V_29 -> V_10 > V_30 -> V_10 ? 1 : - 1 ;
return ( V_29 -> V_10 != V_29 -> V_8 -> V_10 ) - ( V_30 -> V_10 != V_30 -> V_8 -> V_10 ) ;
}
int T_2 F_14 ( struct V_5 * V_13 )
{
struct V_7 * V_9 = V_13 -> V_9 ;
T_3 V_31 = F_6 ( V_13 -> V_9 ) ;
enum V_3 V_32 , V_33 ;
unsigned long long V_34 ;
T_3 V_35 , V_36 ;
T_3 V_4 , V_37 , V_38 ;
if ( V_13 -> V_6 < 2 )
return - 1 ;
F_15 ( V_13 -> V_6 > V_31 ) ;
for ( V_4 = 0 ; V_4 < V_13 -> V_6 ; V_4 ++ ) {
if ( V_9 [ V_4 ] . V_10 + V_9 [ V_4 ] . V_11 < V_9 [ V_4 ] . V_10 )
return - 1 ;
}
for ( V_4 = 0 ; V_4 < 2 * V_13 -> V_6 ; V_4 ++ )
V_39 [ V_4 ] = & V_40 [ V_4 ] ;
V_37 = 0 ;
for ( V_4 = 0 ; V_4 < V_13 -> V_6 ; V_4 ++ ) {
if ( V_9 [ V_4 ] . V_11 != 0 ) {
V_39 [ V_37 ] -> V_10 = V_9 [ V_4 ] . V_10 ;
V_39 [ V_37 ++ ] -> V_8 = & V_9 [ V_4 ] ;
V_39 [ V_37 ] -> V_10 = V_9 [ V_4 ] . V_10 + V_9 [ V_4 ] . V_11 ;
V_39 [ V_37 ++ ] -> V_8 = & V_9 [ V_4 ] ;
}
}
V_38 = V_37 ;
F_16 ( V_39 , V_38 , sizeof( * V_39 ) , F_13 , NULL ) ;
V_36 = 0 ;
V_35 = 0 ;
V_33 = 0 ;
V_34 = 0 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
if ( V_39 [ V_37 ] -> V_10 == V_39 [ V_37 ] -> V_8 -> V_10 ) {
V_41 [ V_36 ++ ] = V_39 [ V_37 ] -> V_8 ;
} else {
for ( V_4 = 0 ; V_4 < V_36 ; V_4 ++ ) {
if ( V_41 [ V_4 ] == V_39 [ V_37 ] -> V_8 )
V_41 [ V_4 ] = V_41 [ V_36 - 1 ] ;
}
V_36 -- ;
}
V_32 = 0 ;
for ( V_4 = 0 ; V_4 < V_36 ; V_4 ++ ) {
if ( V_41 [ V_4 ] -> type > V_32 )
V_32 = V_41 [ V_4 ] -> type ;
}
if ( V_32 != V_33 || V_32 == V_22 ) {
if ( V_33 != 0 ) {
V_42 [ V_35 ] . V_11 = V_39 [ V_37 ] -> V_10 - V_34 ;
if ( V_42 [ V_35 ] . V_11 != 0 )
if ( ++ V_35 >= V_31 )
break;
}
if ( V_32 != 0 ) {
V_42 [ V_35 ] . V_10 = V_39 [ V_37 ] -> V_10 ;
V_42 [ V_35 ] . type = V_32 ;
V_34 = V_39 [ V_37 ] -> V_10 ;
}
V_33 = V_32 ;
}
}
memcpy ( V_9 , V_42 , V_35 * sizeof( * V_9 ) ) ;
V_13 -> V_6 = V_35 ;
return 0 ;
}
static int T_2 F_17 ( struct V_43 * V_9 , T_3 V_6 )
{
struct V_43 * V_8 = V_9 ;
while ( V_6 ) {
T_1 V_1 = V_8 -> V_10 ;
T_1 V_11 = V_8 -> V_11 ;
T_1 V_2 = V_1 + V_11 - 1 ;
T_3 type = V_8 -> type ;
if ( V_1 > V_2 && F_18 ( V_11 ) )
return - 1 ;
F_8 ( V_1 , V_11 , type ) ;
V_8 ++ ;
V_6 -- ;
}
return 0 ;
}
static int T_2 F_19 ( struct V_43 * V_9 , T_3 V_6 )
{
if ( V_6 < 2 )
return - 1 ;
return F_17 ( V_9 , V_6 ) ;
}
static T_1 T_2
F_20 ( struct V_5 * V_13 , T_1 V_1 , T_1 V_11 , enum V_3 V_44 , enum V_3 V_45 )
{
T_1 V_2 ;
unsigned int V_4 ;
T_1 V_46 = 0 ;
F_15 ( V_44 == V_45 ) ;
if ( V_11 > ( V_47 - V_1 ) )
V_11 = V_47 - V_1 ;
V_2 = V_1 + V_11 ;
F_21 ( V_48 L_11 , V_1 , V_2 - 1 ) ;
F_9 ( V_44 ) ;
F_10 ( L_12 ) ;
F_9 ( V_45 ) ;
F_10 ( L_10 ) ;
for ( V_4 = 0 ; V_4 < V_13 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_13 -> V_9 [ V_4 ] ;
T_1 V_49 , V_50 ;
T_1 V_51 ;
if ( V_8 -> type != V_44 )
continue;
V_51 = V_8 -> V_10 + V_8 -> V_11 ;
if ( V_8 -> V_10 >= V_1 && V_51 <= V_2 ) {
V_8 -> type = V_45 ;
V_46 += V_8 -> V_11 ;
continue;
}
if ( V_8 -> V_10 < V_1 && V_51 > V_2 ) {
F_5 ( V_13 , V_1 , V_11 , V_45 ) ;
F_5 ( V_13 , V_2 , V_51 - V_2 , V_8 -> type ) ;
V_8 -> V_11 = V_1 - V_8 -> V_10 ;
V_46 += V_11 ;
continue;
}
V_49 = F_22 ( V_1 , V_8 -> V_10 ) ;
V_50 = F_23 ( V_2 , V_51 ) ;
if ( V_49 >= V_50 )
continue;
F_5 ( V_13 , V_49 , V_50 - V_49 , V_45 ) ;
V_46 += V_50 - V_49 ;
V_8 -> V_11 -= V_50 - V_49 ;
if ( V_8 -> V_10 < V_49 )
continue;
V_8 -> V_10 = V_50 ;
}
return V_46 ;
}
T_1 T_2 F_24 ( T_1 V_1 , T_1 V_11 , enum V_3 V_44 , enum V_3 V_45 )
{
return F_20 ( V_5 , V_1 , V_11 , V_44 , V_45 ) ;
}
static T_1 T_2 F_25 ( T_1 V_1 , T_1 V_11 , enum V_3 V_44 , enum V_3 V_45 )
{
return F_20 ( V_52 , V_1 , V_11 , V_44 , V_45 ) ;
}
T_1 T_2 F_26 ( T_1 V_1 , T_1 V_11 , enum V_3 V_44 , bool V_53 )
{
int V_4 ;
T_1 V_2 ;
T_1 V_54 = 0 ;
if ( V_11 > ( V_47 - V_1 ) )
V_11 = V_47 - V_1 ;
V_2 = V_1 + V_11 ;
F_21 ( V_48 L_13 , V_1 , V_2 - 1 ) ;
if ( V_53 )
F_9 ( V_44 ) ;
F_10 ( L_10 ) ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_4 ] ;
T_1 V_49 , V_50 ;
T_1 V_51 ;
if ( V_53 && V_8 -> type != V_44 )
continue;
V_51 = V_8 -> V_10 + V_8 -> V_11 ;
if ( V_8 -> V_10 >= V_1 && V_51 <= V_2 ) {
V_54 += V_8 -> V_11 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
continue;
}
if ( V_8 -> V_10 < V_1 && V_51 > V_2 ) {
F_8 ( V_2 , V_51 - V_2 , V_8 -> type ) ;
V_8 -> V_11 = V_1 - V_8 -> V_10 ;
V_54 += V_11 ;
continue;
}
V_49 = F_22 ( V_1 , V_8 -> V_10 ) ;
V_50 = F_23 ( V_2 , V_51 ) ;
if ( V_49 >= V_50 )
continue;
V_54 += V_50 - V_49 ;
V_8 -> V_11 -= V_50 - V_49 ;
if ( V_8 -> V_10 < V_49 )
continue;
V_8 -> V_10 = V_50 ;
}
return V_54 ;
}
void T_2 F_27 ( void )
{
if ( F_14 ( V_5 ) )
return;
F_12 ( L_14 ) ;
F_11 ( L_15 ) ;
}
static void T_2 F_28 ( void )
{
F_14 ( V_52 ) ;
}
static int T_2 F_29 ( unsigned long * V_55 , unsigned long * V_56 )
{
unsigned long long V_57 = V_58 ;
int V_4 = V_5 -> V_6 ;
int V_59 = 0 ;
while ( -- V_4 >= 0 ) {
unsigned long long V_1 = V_5 -> V_9 [ V_4 ] . V_10 ;
unsigned long long V_2 = V_1 + V_5 -> V_9 [ V_4 ] . V_11 ;
if ( V_57 > V_2 ) {
unsigned long V_60 = V_57 - V_2 ;
if ( V_60 >= * V_56 ) {
* V_56 = V_60 ;
* V_55 = V_2 ;
V_59 = 1 ;
}
}
if ( V_1 < V_57 )
V_57 = V_1 ;
}
return V_59 ;
}
T_2 void F_30 ( void )
{
unsigned long V_55 , V_56 ;
int V_59 ;
V_56 = 0x400000 ;
V_59 = F_29 ( & V_55 , & V_56 ) ;
if ( ! V_59 ) {
#ifdef F_31
V_55 = ( V_61 << V_62 ) + 1024 * 1024 ;
F_7 (
L_16
L_17 ) ;
#else
V_55 = 0x10000000 ;
#endif
}
V_63 = V_55 ;
F_12 ( L_18 , V_55 , V_55 + V_56 - 1 ) ;
}
T_2 void F_32 ( void )
{
struct V_5 * V_64 ;
int V_11 ;
V_11 = F_33 ( struct V_5 , V_9 ) + sizeof( struct V_7 ) * V_5 -> V_6 ;
V_64 = F_34 ( V_11 , V_65 ) ;
F_15 ( ! V_64 ) ;
memcpy ( V_64 , V_5 , V_11 ) ;
V_5 = V_64 ;
V_11 = F_33 ( struct V_5 , V_9 ) + sizeof( struct V_7 ) * V_52 -> V_6 ;
V_64 = F_34 ( V_11 , V_65 ) ;
F_15 ( ! V_64 ) ;
memcpy ( V_64 , V_52 , V_11 ) ;
V_52 = V_64 ;
V_11 = F_33 ( struct V_5 , V_9 ) + sizeof( struct V_7 ) * V_66 -> V_6 ;
V_64 = F_34 ( V_11 , V_65 ) ;
F_15 ( ! V_64 ) ;
memcpy ( V_64 , V_66 , V_11 ) ;
V_66 = V_64 ;
}
void T_2 F_35 ( T_1 V_67 , T_3 V_68 )
{
int V_9 ;
struct V_43 * V_69 ;
struct V_70 * V_71 ;
V_71 = F_36 ( V_67 , V_68 ) ;
V_9 = V_71 -> V_72 / sizeof( * V_69 ) ;
V_69 = (struct V_43 * ) ( V_71 -> V_73 ) ;
F_17 ( V_69 , V_9 ) ;
F_14 ( V_5 ) ;
memcpy ( V_52 , V_5 , sizeof( * V_52 ) ) ;
memcpy ( V_66 , V_5 , sizeof( * V_66 ) ) ;
F_37 ( V_71 , V_68 ) ;
F_12 ( L_19 ) ;
F_11 ( L_20 ) ;
}
void T_2 F_38 ( unsigned long V_74 )
{
int V_4 ;
unsigned long V_75 = 0 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_4 ] ;
if ( V_75 < F_39 ( V_8 -> V_10 ) )
F_40 ( V_75 , F_39 ( V_8 -> V_10 ) ) ;
V_75 = F_41 ( V_8 -> V_10 + V_8 -> V_11 ) ;
if ( V_8 -> type != V_15 && V_8 -> type != V_16 )
F_40 ( F_39 ( V_8 -> V_10 ) , V_75 ) ;
if ( V_75 >= V_74 )
break;
}
}
static int T_2 F_42 ( void )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_4 ] ;
if ( V_8 -> type == V_19 )
F_43 ( V_8 -> V_10 , V_8 -> V_11 ) ;
}
return 0 ;
}
T_1 T_2 F_44 ( T_1 V_11 , T_1 V_76 )
{
T_1 V_10 ;
V_10 = F_45 ( V_11 , V_76 , V_77 ) ;
if ( V_10 ) {
F_25 ( V_10 , V_11 , V_15 , V_17 ) ;
F_12 ( L_21 ) ;
F_28 () ;
}
return V_10 ;
}
static unsigned long T_2 F_46 ( unsigned long V_74 , enum V_3 type )
{
int V_4 ;
unsigned long V_78 = 0 ;
unsigned long V_79 = V_80 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_4 ] ;
unsigned long V_81 ;
unsigned long V_82 ;
if ( V_8 -> type != type )
continue;
V_81 = V_8 -> V_10 >> V_62 ;
V_82 = ( V_8 -> V_10 + V_8 -> V_11 ) >> V_62 ;
if ( V_81 >= V_74 )
continue;
if ( V_82 > V_74 ) {
V_78 = V_74 ;
break;
}
if ( V_82 > V_78 )
V_78 = V_82 ;
}
if ( V_78 > V_79 )
V_78 = V_79 ;
F_12 ( L_22 ,
V_78 , V_79 ) ;
return V_78 ;
}
unsigned long T_2 F_47 ( void )
{
return F_46 ( V_80 , V_15 ) ;
}
unsigned long T_2 F_48 ( void )
{
return F_46 ( 1UL << ( 32 - V_62 ) , V_15 ) ;
}
static void T_2 F_49 ( char * V_83 )
{
F_50 ( V_83 ) ;
F_51 ( V_83 ) ;
}
static int T_2 F_52 ( char * V_84 )
{
T_1 V_85 ;
if ( ! V_84 )
return - V_12 ;
if ( ! strcmp ( V_84 , L_23 ) ) {
#ifdef F_53
F_54 ( V_86 ) ;
return 0 ;
#else
F_55 ( L_24 ) ;
return - V_12 ;
#endif
}
V_87 = 1 ;
V_85 = F_56 ( V_84 , & V_84 ) ;
if ( V_85 == 0 )
return - V_12 ;
F_26 ( V_85 , V_47 - V_85 , V_15 , 1 ) ;
return 0 ;
}
static int T_2 F_57 ( char * V_84 )
{
char * V_88 ;
T_1 V_89 , V_85 ;
if ( ! V_84 )
return - V_12 ;
if ( ! strncmp ( V_84 , L_25 , 8 ) ) {
#ifdef F_58
V_90 = F_47 () ;
#endif
V_5 -> V_6 = 0 ;
V_87 = 1 ;
return 0 ;
}
V_88 = V_84 ;
V_85 = F_56 ( V_84 , & V_84 ) ;
if ( V_84 == V_88 )
return - V_12 ;
V_87 = 1 ;
if ( * V_84 == '@' ) {
V_89 = F_56 ( V_84 + 1 , & V_84 ) ;
F_8 ( V_89 , V_85 , V_15 ) ;
} else if ( * V_84 == '#' ) {
V_89 = F_56 ( V_84 + 1 , & V_84 ) ;
F_8 ( V_89 , V_85 , V_18 ) ;
} else if ( * V_84 == '$' ) {
V_89 = F_56 ( V_84 + 1 , & V_84 ) ;
F_8 ( V_89 , V_85 , V_17 ) ;
} else if ( * V_84 == '!' ) {
V_89 = F_56 ( V_84 + 1 , & V_84 ) ;
F_8 ( V_89 , V_85 , V_22 ) ;
} else {
F_26 ( V_85 , V_47 - V_85 , V_15 , 1 ) ;
}
return * V_84 == '\0' ? 0 : - V_12 ;
}
static int T_2 F_59 ( char * V_91 )
{
while ( V_91 ) {
char * V_92 = strchr ( V_91 , ',' ) ;
if ( V_92 )
* V_92 ++ = 0 ;
F_57 ( V_91 ) ;
V_91 = V_92 ;
}
return 0 ;
}
void T_2 F_60 ( void )
{
struct V_70 * V_73 ;
T_1 V_93 ;
V_93 = V_94 . V_95 . V_70 ;
if ( ! V_93 )
return;
while ( V_93 ) {
V_73 = F_36 ( V_93 , sizeof( * V_73 ) ) ;
F_24 ( V_93 , sizeof( * V_73 ) + V_73 -> V_72 , V_15 , V_16 ) ;
F_25 ( V_93 , sizeof( * V_73 ) + V_73 -> V_72 , V_15 , V_16 ) ;
V_93 = V_73 -> V_96 ;
F_37 ( V_73 , sizeof( * V_73 ) ) ;
}
F_14 ( V_5 ) ;
F_14 ( V_52 ) ;
F_12 ( L_26 ) ;
F_11 ( L_27 ) ;
}
void T_2 F_61 ( void )
{
if ( V_87 ) {
if ( F_14 ( V_5 ) < 0 )
F_49 ( L_28 ) ;
F_12 ( L_29 ) ;
F_11 ( L_30 ) ;
}
}
static const char * T_2 F_62 ( struct V_7 * V_8 )
{
switch ( V_8 -> type ) {
case V_16 :
case V_15 : return L_31 ;
case V_18 : return L_32 ;
case V_19 : return L_33 ;
case V_20 : return L_34 ;
case V_22 : return L_35 ;
case V_21 : return L_36 ;
case V_17 : return L_37 ;
default: return L_38 ;
}
}
static unsigned long T_2 F_63 ( struct V_7 * V_8 )
{
switch ( V_8 -> type ) {
case V_16 :
case V_15 : return V_97 ;
case V_18 :
case V_19 :
case V_20 :
case V_22 :
case V_21 :
case V_17 :
default: return V_98 ;
}
}
static unsigned long T_2 F_64 ( struct V_7 * V_8 )
{
switch ( V_8 -> type ) {
case V_18 : return V_99 ;
case V_19 : return V_100 ;
case V_21 : return V_101 ;
case V_22 : return V_102 ;
case V_16 :
case V_15 :
case V_20 :
case V_17 :
default: return V_103 ;
}
}
static bool T_2 F_65 ( enum V_3 type , struct V_104 * V_105 )
{
if ( V_105 -> V_1 < ( 1ULL << 20 ) )
return true ;
switch ( type ) {
case V_17 :
case V_22 :
case V_21 :
return false ;
case V_16 :
case V_15 :
case V_18 :
case V_19 :
case V_20 :
default:
return true ;
}
}
void T_2 F_66 ( void )
{
int V_4 ;
struct V_104 * V_105 ;
T_1 V_2 ;
V_105 = F_67 ( sizeof( * V_105 ) * V_5 -> V_6 ) ;
V_106 = V_105 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = V_5 -> V_9 + V_4 ;
V_2 = V_8 -> V_10 + V_8 -> V_11 - 1 ;
if ( V_2 != ( V_107 ) V_2 ) {
V_105 ++ ;
continue;
}
V_105 -> V_1 = V_8 -> V_10 ;
V_105 -> V_2 = V_2 ;
V_105 -> V_108 = F_62 ( V_8 ) ;
V_105 -> V_109 = F_63 ( V_8 ) ;
V_105 -> V_110 = F_64 ( V_8 ) ;
if ( F_65 ( V_8 -> type , V_105 ) ) {
V_105 -> V_109 |= V_111 ;
F_68 ( & V_112 , V_105 ) ;
}
V_105 ++ ;
}
for ( V_4 = 0 ; V_4 < V_66 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = V_66 -> V_9 + V_4 ;
F_69 ( V_8 -> V_10 , V_8 -> V_10 + V_8 -> V_11 , F_62 ( V_8 ) ) ;
}
}
static unsigned long T_2 F_70 ( V_107 V_113 )
{
unsigned long V_114 = V_113 >> 20 ;
if ( ! V_114 )
return 64 * 1024 ;
if ( V_114 < 16 )
return 1024 * 1024 ;
return 64 * 1024 * 1024 ;
}
void T_2 F_71 ( void )
{
int V_4 ;
struct V_104 * V_105 ;
V_105 = V_106 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
if ( ! V_105 -> V_115 && V_105 -> V_2 )
F_72 ( & V_112 , V_105 ) ;
V_105 ++ ;
}
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_4 ] ;
T_1 V_1 , V_2 ;
if ( V_8 -> type != V_15 )
continue;
V_1 = V_8 -> V_10 + V_8 -> V_11 ;
V_2 = F_73 ( V_1 , F_70 ( V_1 ) ) - 1 ;
if ( V_2 > V_116 )
V_2 = V_116 ;
if ( V_1 >= V_2 )
continue;
F_21 ( V_48 L_39 , V_1 , V_2 ) ;
F_74 ( & V_112 , V_1 , V_2 , L_40 ) ;
}
}
char * T_2 F_75 ( void )
{
char * V_23 = L_41 ;
if ( F_19 ( V_94 . V_5 , V_94 . V_117 ) < 0 ) {
T_1 V_85 ;
if ( V_94 . V_118 < V_94 . V_119 . V_120 ) {
V_85 = V_94 . V_119 . V_120 ;
V_23 = L_42 ;
} else {
V_85 = V_94 . V_118 ;
V_23 = L_43 ;
}
V_5 -> V_6 = 0 ;
F_8 ( 0 , F_76 () , V_15 ) ;
F_8 ( V_121 , V_85 << 10 , V_15 ) ;
}
F_14 ( V_5 ) ;
return V_23 ;
}
void T_2 F_77 ( void )
{
char * V_23 ;
F_78 ( sizeof( struct V_43 ) != 20 ) ;
V_23 = V_122 . V_123 . V_124 () ;
memcpy ( V_52 , V_5 , sizeof( * V_52 ) ) ;
memcpy ( V_66 , V_5 , sizeof( * V_66 ) ) ;
F_12 ( L_44 ) ;
F_11 ( V_23 ) ;
}
void T_2 F_79 ( void )
{
int V_4 ;
T_1 V_2 ;
F_80 () ;
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_4 ] ;
V_2 = V_8 -> V_10 + V_8 -> V_11 ;
if ( V_2 != ( V_107 ) V_2 )
continue;
if ( V_8 -> type != V_15 && V_8 -> type != V_16 )
continue;
F_81 ( V_8 -> V_10 , V_8 -> V_11 ) ;
}
F_82 ( V_125 ) ;
F_83 () ;
}
