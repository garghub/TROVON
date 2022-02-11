int
F_1 ( T_1 V_1 , T_1 V_2 , unsigned type )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
if ( type && V_7 -> type != type )
continue;
if ( V_7 -> V_9 >= V_2 || V_7 -> V_9 + V_7 -> V_10 <= V_1 )
continue;
return 1 ;
}
return 0 ;
}
int T_2 F_2 ( T_1 V_1 , T_1 V_2 , unsigned type )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
if ( type && V_7 -> type != type )
continue;
if ( V_7 -> V_9 >= V_2 || V_7 -> V_9 + V_7 -> V_10 <= V_1 )
continue;
if ( V_7 -> V_9 <= V_1 )
V_1 = V_7 -> V_9 + V_7 -> V_10 ;
if ( V_1 >= V_2 )
return 1 ;
}
return 0 ;
}
static void T_2 F_3 ( struct V_11 * V_12 , T_1 V_1 , T_1 V_10 ,
int type )
{
int V_13 = V_12 -> V_5 ;
if ( V_13 >= F_4 ( V_12 -> V_8 ) ) {
F_5 ( V_14 L_1 ,
( unsigned long long ) V_1 ,
( unsigned long long ) ( V_1 + V_10 - 1 ) ) ;
return;
}
V_12 -> V_8 [ V_13 ] . V_9 = V_1 ;
V_12 -> V_8 [ V_13 ] . V_10 = V_10 ;
V_12 -> V_8 [ V_13 ] . type = type ;
V_12 -> V_5 ++ ;
}
void T_2 F_6 ( T_1 V_1 , T_1 V_10 , int type )
{
F_3 ( & V_4 , V_1 , V_10 , type ) ;
}
static void T_2 F_7 ( T_3 type )
{
switch ( type ) {
case V_15 :
case V_16 :
F_5 ( V_17 L_2 ) ;
break;
case V_18 :
F_5 ( V_17 L_3 ) ;
break;
case V_19 :
F_5 ( V_17 L_4 ) ;
break;
case V_20 :
F_5 ( V_17 L_5 ) ;
break;
case V_21 :
F_5 ( V_17 L_6 ) ;
break;
default:
F_5 ( V_17 L_7 , type ) ;
break;
}
}
void T_2 F_8 ( char * V_22 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
F_5 ( V_23 L_8 , V_22 ,
( unsigned long long ) V_4 . V_8 [ V_3 ] . V_9 ,
( unsigned long long )
( V_4 . V_8 [ V_3 ] . V_9 + V_4 . V_8 [ V_3 ] . V_10 - 1 ) ) ;
F_7 ( V_4 . V_8 [ V_3 ] . type ) ;
F_5 ( V_17 L_9 ) ;
}
}
static int T_2 F_9 ( const void * V_24 , const void * V_25 )
{
struct V_26 * const * V_27 = V_24 , * const * V_28 = V_25 ;
const struct V_26 * V_29 = * V_27 , * V_30 = * V_28 ;
if ( V_29 -> V_9 != V_30 -> V_9 )
return V_29 -> V_9 > V_30 -> V_9 ? 1 : - 1 ;
return ( V_29 -> V_9 != V_29 -> V_31 -> V_9 ) - ( V_30 -> V_9 != V_30 -> V_31 -> V_9 ) ;
}
int T_2 F_10 ( struct V_6 * V_32 , int V_33 ,
T_3 * V_34 )
{
static struct V_26 V_35 [ 2 * V_36 ] V_37 ;
static struct V_26 * V_38 [ 2 * V_36 ] V_37 ;
static struct V_6 * V_39 [ V_36 ] V_37 ;
static struct V_6 V_40 [ V_36 ] V_37 ;
unsigned long V_41 , V_42 ;
unsigned long long V_43 ;
int V_44 ;
int V_45 ;
int V_46 ;
int V_47 , V_48 , V_49 ;
int V_3 ;
if ( * V_34 < 2 )
return - 1 ;
V_47 = * V_34 ;
F_11 ( V_47 > V_33 ) ;
for ( V_3 = 0 ; V_3 < V_47 ; V_3 ++ )
if ( V_32 [ V_3 ] . V_9 + V_32 [ V_3 ] . V_10 < V_32 [ V_3 ] . V_9 )
return - 1 ;
for ( V_3 = 0 ; V_3 < 2 * V_47 ; V_3 ++ )
V_38 [ V_3 ] = & V_35 [ V_3 ] ;
V_44 = 0 ;
for ( V_3 = 0 ; V_3 < V_47 ; V_3 ++ ) {
if ( V_32 [ V_3 ] . V_10 != 0 ) {
V_38 [ V_44 ] -> V_9 = V_32 [ V_3 ] . V_9 ;
V_38 [ V_44 ++ ] -> V_31 = & V_32 [ V_3 ] ;
V_38 [ V_44 ] -> V_9 = V_32 [ V_3 ] . V_9 +
V_32 [ V_3 ] . V_10 ;
V_38 [ V_44 ++ ] -> V_31 = & V_32 [ V_3 ] ;
}
}
V_49 = V_44 ;
F_12 ( V_38 , V_49 , sizeof *V_38 , F_9 , NULL ) ;
V_45 = 0 ;
V_46 = 0 ;
V_42 = 0 ;
V_43 = 0 ;
for ( V_44 = 0 ; V_44 < V_49 ; V_44 ++ ) {
if ( V_38 [ V_44 ] -> V_9 ==
V_38 [ V_44 ] -> V_31 -> V_9 ) {
V_39 [ V_45 ++ ] =
V_38 [ V_44 ] -> V_31 ;
} else {
for ( V_3 = 0 ; V_3 < V_45 ; V_3 ++ ) {
if ( V_39 [ V_3 ] ==
V_38 [ V_44 ] -> V_31 )
V_39 [ V_3 ] =
V_39 [ V_45 - 1 ] ;
}
V_45 -- ;
}
V_41 = 0 ;
for ( V_3 = 0 ; V_3 < V_45 ; V_3 ++ )
if ( V_39 [ V_3 ] -> type > V_41 )
V_41 = V_39 [ V_3 ] -> type ;
if ( V_41 != V_42 ) {
if ( V_42 != 0 ) {
V_40 [ V_46 ] . V_10 =
V_38 [ V_44 ] -> V_9 - V_43 ;
if ( V_40 [ V_46 ] . V_10 != 0 )
if ( ++ V_46 >= V_33 )
break;
}
if ( V_41 != 0 ) {
V_40 [ V_46 ] . V_9 =
V_38 [ V_44 ] -> V_9 ;
V_40 [ V_46 ] . type = V_41 ;
V_43 = V_38 [ V_44 ] -> V_9 ;
}
V_42 = V_41 ;
}
}
V_48 = V_46 ;
memcpy ( V_32 , V_40 , V_48 * sizeof( struct V_6 ) ) ;
* V_34 = V_48 ;
return 0 ;
}
static int T_2 F_13 ( struct V_6 * V_32 , int V_5 )
{
while ( V_5 ) {
T_1 V_1 = V_32 -> V_9 ;
T_1 V_10 = V_32 -> V_10 ;
T_1 V_2 = V_1 + V_10 ;
T_3 type = V_32 -> type ;
if ( V_1 > V_2 )
return - 1 ;
F_6 ( V_1 , V_10 , type ) ;
V_32 ++ ;
V_5 -- ;
}
return 0 ;
}
static int T_2 F_14 ( struct V_6 * V_32 , int V_5 )
{
if ( V_5 < 2 )
return - 1 ;
return F_13 ( V_32 , V_5 ) ;
}
static T_1 T_2 F_15 ( struct V_11 * V_12 , T_1 V_1 ,
T_1 V_10 , unsigned V_50 ,
unsigned V_51 )
{
T_1 V_2 ;
unsigned int V_3 ;
T_1 V_52 = 0 ;
F_11 ( V_50 == V_51 ) ;
if ( V_10 > ( V_53 - V_1 ) )
V_10 = V_53 - V_1 ;
V_2 = V_1 + V_10 ;
F_5 ( V_54 L_10 ,
( unsigned long long ) V_1 , ( unsigned long long ) ( V_2 - 1 ) ) ;
F_7 ( V_50 ) ;
F_5 ( V_17 L_11 ) ;
F_7 ( V_51 ) ;
F_5 ( V_17 L_9 ) ;
for ( V_3 = 0 ; V_3 < V_12 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_12 -> V_8 [ V_3 ] ;
T_1 V_55 , V_56 ;
T_1 V_57 ;
if ( V_7 -> type != V_50 )
continue;
V_57 = V_7 -> V_9 + V_7 -> V_10 ;
if ( V_7 -> V_9 >= V_1 && V_57 <= V_2 ) {
V_7 -> type = V_51 ;
V_52 += V_7 -> V_10 ;
continue;
}
if ( V_7 -> V_9 < V_1 && V_57 > V_2 ) {
F_3 ( V_12 , V_1 , V_10 , V_51 ) ;
F_3 ( V_12 , V_2 , V_57 - V_2 , V_7 -> type ) ;
V_7 -> V_10 = V_1 - V_7 -> V_9 ;
V_52 += V_10 ;
continue;
}
V_55 = F_16 ( V_1 , V_7 -> V_9 ) ;
V_56 = F_17 ( V_2 , V_57 ) ;
if ( V_55 >= V_56 )
continue;
F_3 ( V_12 , V_55 , V_56 - V_55 ,
V_51 ) ;
V_52 += V_56 - V_55 ;
V_7 -> V_10 -= V_56 - V_55 ;
if ( V_7 -> V_9 < V_55 )
continue;
V_7 -> V_9 = V_56 ;
}
return V_52 ;
}
T_1 T_2 F_18 ( T_1 V_1 , T_1 V_10 , unsigned V_50 ,
unsigned V_51 )
{
return F_15 ( & V_4 , V_1 , V_10 , V_50 , V_51 ) ;
}
static T_1 T_2 F_19 ( T_1 V_1 , T_1 V_10 ,
unsigned V_50 , unsigned V_51 )
{
return F_15 ( & V_58 , V_1 , V_10 , V_50 ,
V_51 ) ;
}
T_1 T_2 F_20 ( T_1 V_1 , T_1 V_10 , unsigned V_50 ,
int V_59 )
{
int V_3 ;
T_1 V_2 ;
T_1 V_60 = 0 ;
if ( V_10 > ( V_53 - V_1 ) )
V_10 = V_53 - V_1 ;
V_2 = V_1 + V_10 ;
F_5 ( V_54 L_12 ,
( unsigned long long ) V_1 , ( unsigned long long ) ( V_2 - 1 ) ) ;
if ( V_59 )
F_7 ( V_50 ) ;
F_5 ( V_17 L_9 ) ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
T_1 V_55 , V_56 ;
T_1 V_57 ;
if ( V_59 && V_7 -> type != V_50 )
continue;
V_57 = V_7 -> V_9 + V_7 -> V_10 ;
if ( V_7 -> V_9 >= V_1 && V_57 <= V_2 ) {
V_60 += V_7 -> V_10 ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
continue;
}
if ( V_7 -> V_9 < V_1 && V_57 > V_2 ) {
F_6 ( V_2 , V_57 - V_2 , V_7 -> type ) ;
V_7 -> V_10 = V_1 - V_7 -> V_9 ;
V_60 += V_10 ;
continue;
}
V_55 = F_16 ( V_1 , V_7 -> V_9 ) ;
V_56 = F_17 ( V_2 , V_57 ) ;
if ( V_55 >= V_56 )
continue;
V_60 += V_56 - V_55 ;
V_7 -> V_10 -= V_56 - V_55 ;
if ( V_7 -> V_9 < V_55 )
continue;
V_7 -> V_9 = V_56 ;
}
return V_60 ;
}
void T_2 F_21 ( void )
{
T_3 V_5 ;
V_5 = V_4 . V_5 ;
if ( F_10 ( V_4 . V_8 , F_4 ( V_4 . V_8 ) , & V_5 ) )
return;
V_4 . V_5 = V_5 ;
F_5 ( V_23 L_13 ) ;
F_8 ( L_14 ) ;
}
static void T_2 F_22 ( void )
{
T_3 V_5 ;
V_5 = V_58 . V_5 ;
if ( F_10 ( V_58 . V_8 , F_4 ( V_58 . V_8 ) , & V_5 ) )
return;
V_58 . V_5 = V_5 ;
}
T_2 int F_23 ( unsigned long * V_61 , unsigned long * V_62 ,
unsigned long V_63 , unsigned long long V_64 )
{
unsigned long long V_65 ;
int V_3 = V_4 . V_5 ;
int V_66 = 0 ;
V_65 = ( V_64 && V_64 < V_67 ) ? V_64 : V_67 ;
while ( -- V_3 >= 0 ) {
unsigned long long V_1 = V_4 . V_8 [ V_3 ] . V_9 ;
unsigned long long V_2 = V_1 + V_4 . V_8 [ V_3 ] . V_10 ;
if ( V_2 < V_63 )
continue;
if ( V_65 > V_2 ) {
unsigned long V_68 = V_65 - V_2 ;
if ( V_68 >= * V_62 ) {
* V_62 = V_68 ;
* V_61 = V_2 ;
V_66 = 1 ;
}
}
if ( V_1 < V_65 )
V_65 = V_1 ;
}
return V_66 ;
}
T_2 void F_24 ( void )
{
unsigned long V_61 , V_62 ;
int V_66 ;
V_61 = 0x10000000 ;
V_62 = 0x400000 ;
V_66 = F_23 ( & V_61 , & V_62 , 0 , V_67 ) ;
#ifdef F_25
if ( ! V_66 ) {
V_61 = ( V_69 << V_70 ) + 1024 * 1024 ;
F_5 ( V_14
L_15
L_16 ) ;
}
#endif
V_71 = V_61 ;
F_5 ( V_23
L_17 ,
V_61 , V_61 + V_62 - 1 ) ;
}
void T_2 F_26 ( T_1 V_72 , T_3 V_73 )
{
int V_74 ;
struct V_6 * V_75 ;
struct V_76 * V_77 ;
V_77 = F_27 ( V_72 , V_73 ) ;
V_74 = V_77 -> V_78 / sizeof( struct V_6 ) ;
V_75 = (struct V_6 * ) ( V_77 -> V_79 ) ;
F_13 ( V_75 , V_74 ) ;
F_10 ( V_4 . V_8 , F_4 ( V_4 . V_8 ) , & V_4 . V_5 ) ;
F_28 ( V_77 , V_73 ) ;
F_5 ( V_23 L_18 ) ;
F_8 ( L_19 ) ;
}
void T_2 F_29 ( unsigned long V_80 )
{
int V_3 ;
unsigned long V_81 = 0 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
if ( V_81 < F_30 ( V_7 -> V_9 ) )
F_31 ( V_81 , F_30 ( V_7 -> V_9 ) ) ;
V_81 = F_32 ( V_7 -> V_9 + V_7 -> V_10 ) ;
if ( V_7 -> type != V_15 && V_7 -> type != V_16 )
F_31 ( F_30 ( V_7 -> V_9 ) , V_81 ) ;
if ( V_81 >= V_80 )
break;
}
}
static int T_2 F_33 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
if ( V_7 -> type == V_20 )
F_34 ( V_7 -> V_9 , V_7 -> V_10 ) ;
}
return 0 ;
}
T_1 T_2 F_35 ( T_1 V_10 , T_1 V_82 )
{
T_1 V_9 ;
V_9 = F_36 ( V_10 , V_82 , V_83 ) ;
if ( V_9 ) {
F_19 ( V_9 , V_10 , V_15 , V_18 ) ;
F_5 ( V_23 L_20 ) ;
F_22 () ;
}
return V_9 ;
}
static unsigned long T_2 F_37 ( unsigned long V_80 , unsigned type )
{
int V_3 ;
unsigned long V_84 = 0 ;
unsigned long V_85 = V_86 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
unsigned long V_87 ;
unsigned long V_88 ;
if ( V_7 -> type != type )
continue;
V_87 = V_7 -> V_9 >> V_70 ;
V_88 = ( V_7 -> V_9 + V_7 -> V_10 ) >> V_70 ;
if ( V_87 >= V_80 )
continue;
if ( V_88 > V_80 ) {
V_84 = V_80 ;
break;
}
if ( V_88 > V_84 )
V_84 = V_88 ;
}
if ( V_84 > V_85 )
V_84 = V_85 ;
F_5 ( V_23 L_21 ,
V_84 , V_85 ) ;
return V_84 ;
}
unsigned long T_2 F_38 ( void )
{
return F_37 ( V_86 , V_15 ) ;
}
unsigned long T_2 F_39 ( void )
{
return F_37 ( 1UL << ( 32 - V_70 ) , V_15 ) ;
}
static void F_40 ( char * V_89 )
{
F_41 ( V_89 ) ;
F_42 ( V_89 ) ;
}
static int T_2 F_43 ( char * V_90 )
{
T_1 V_91 ;
if ( ! V_90 )
return - V_92 ;
if ( ! strcmp ( V_90 , L_22 ) ) {
#ifdef F_44
F_45 ( V_93 ) ;
return 0 ;
#else
F_5 ( V_94 L_23 ) ;
return - V_92 ;
#endif
}
V_95 = 1 ;
V_91 = F_46 ( V_90 , & V_90 ) ;
if ( V_91 == 0 )
return - V_92 ;
F_20 ( V_91 , V_53 - V_91 , V_15 , 1 ) ;
return 0 ;
}
static int T_2 F_47 ( char * V_90 )
{
char * V_96 ;
T_1 V_97 , V_91 ;
if ( ! V_90 )
return - V_92 ;
if ( ! strncmp ( V_90 , L_24 , 8 ) ) {
#ifdef F_48
V_98 = F_38 () ;
#endif
V_4 . V_5 = 0 ;
V_95 = 1 ;
return 0 ;
}
V_96 = V_90 ;
V_91 = F_46 ( V_90 , & V_90 ) ;
if ( V_90 == V_96 )
return - V_92 ;
V_95 = 1 ;
if ( * V_90 == '@' ) {
V_97 = F_46 ( V_90 + 1 , & V_90 ) ;
F_6 ( V_97 , V_91 , V_15 ) ;
} else if ( * V_90 == '#' ) {
V_97 = F_46 ( V_90 + 1 , & V_90 ) ;
F_6 ( V_97 , V_91 , V_19 ) ;
} else if ( * V_90 == '$' ) {
V_97 = F_46 ( V_90 + 1 , & V_90 ) ;
F_6 ( V_97 , V_91 , V_18 ) ;
} else
F_20 ( V_91 , V_53 - V_91 , V_15 , 1 ) ;
return * V_90 == '\0' ? 0 : - V_92 ;
}
static int T_2 F_49 ( char * V_99 )
{
while ( V_99 ) {
char * V_100 = strchr ( V_99 , ',' ) ;
if ( V_100 )
* V_100 ++ = 0 ;
F_47 ( V_99 ) ;
V_99 = V_100 ;
}
return 0 ;
}
void T_2 F_50 ( void )
{
if ( V_95 ) {
T_3 V_101 = V_4 . V_5 ;
if ( F_10 ( V_4 . V_8 , F_4 ( V_4 . V_8 ) , & V_101 ) < 0 )
F_40 ( L_25 ) ;
V_4 . V_5 = V_101 ;
F_5 ( V_23 L_26 ) ;
F_8 ( L_27 ) ;
}
}
static inline const char * F_51 ( int V_102 )
{
switch ( V_102 ) {
case V_16 :
case V_15 : return L_28 ;
case V_19 : return L_29 ;
case V_20 : return L_30 ;
case V_21 : return L_31 ;
default: return L_3 ;
}
}
void T_2 F_52 ( void )
{
int V_3 ;
struct V_103 * V_104 ;
T_1 V_2 ;
V_104 = F_53 ( sizeof( struct V_103 ) * V_4 . V_5 ) ;
V_105 = V_104 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
V_2 = V_4 . V_8 [ V_3 ] . V_9 + V_4 . V_8 [ V_3 ] . V_10 - 1 ;
if ( V_2 != ( V_106 ) V_2 ) {
V_104 ++ ;
continue;
}
V_104 -> V_107 = F_51 ( V_4 . V_8 [ V_3 ] . type ) ;
V_104 -> V_1 = V_4 . V_8 [ V_3 ] . V_9 ;
V_104 -> V_2 = V_2 ;
V_104 -> V_108 = V_109 ;
if ( V_4 . V_8 [ V_3 ] . type != V_18 || V_104 -> V_1 < ( 1ULL << 20 ) ) {
V_104 -> V_108 |= V_110 ;
F_54 ( & V_111 , V_104 ) ;
}
V_104 ++ ;
}
for ( V_3 = 0 ; V_3 < V_58 . V_5 ; V_3 ++ ) {
struct V_6 * V_112 = & V_58 . V_8 [ V_3 ] ;
F_55 ( V_112 -> V_9 ,
V_112 -> V_9 + V_112 -> V_10 ,
F_51 ( V_112 -> type ) ) ;
}
}
static unsigned long F_56 ( V_106 V_113 )
{
unsigned long V_114 = V_113 >> 20 ;
if ( ! V_114 )
return 64 * 1024 ;
if ( V_114 < 16 )
return 1024 * 1024 ;
return 64 * 1024 * 1024 ;
}
void T_2 F_57 ( void )
{
int V_3 ;
struct V_103 * V_104 ;
V_104 = V_105 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
if ( ! V_104 -> V_115 && V_104 -> V_2 )
F_58 ( & V_111 , V_104 ) ;
V_104 ++ ;
}
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_112 = & V_4 . V_8 [ V_3 ] ;
T_1 V_1 , V_2 ;
if ( V_112 -> type != V_15 )
continue;
V_1 = V_112 -> V_9 + V_112 -> V_10 ;
V_2 = F_59 ( V_1 , F_56 ( V_1 ) ) - 1 ;
if ( V_2 > V_116 )
V_2 = V_116 ;
if ( V_1 >= V_2 )
continue;
F_5 ( V_54
L_32 ,
V_1 , V_2 ) ;
F_60 ( & V_111 , V_1 , V_2 ,
L_33 ) ;
}
}
char * T_2 F_61 ( void )
{
char * V_22 = L_34 ;
T_3 V_48 ;
V_48 = V_117 . V_118 ;
F_10 ( V_117 . V_119 ,
F_4 ( V_117 . V_119 ) ,
& V_48 ) ;
V_117 . V_118 = V_48 ;
if ( F_14 ( V_117 . V_119 , V_117 . V_118 )
< 0 ) {
T_1 V_91 ;
if ( V_117 . V_120
< V_117 . V_121 . V_122 ) {
V_91 = V_117 . V_121 . V_122 ;
V_22 = L_35 ;
} else {
V_91 = V_117 . V_120 ;
V_22 = L_36 ;
}
V_4 . V_5 = 0 ;
F_6 ( 0 , F_62 () , V_15 ) ;
F_6 ( V_123 , V_91 << 10 , V_15 ) ;
}
return V_22 ;
}
void T_2 F_63 ( void )
{
char * V_22 ;
V_22 = V_124 . V_125 . V_126 () ;
memcpy ( & V_58 , & V_4 , sizeof( struct V_11 ) ) ;
F_5 ( V_23 L_37 ) ;
F_8 ( V_22 ) ;
}
void T_2 F_64 ( void )
{
int V_3 ;
T_1 V_2 ;
F_65 () ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
V_2 = V_7 -> V_9 + V_7 -> V_10 ;
if ( V_2 != ( V_106 ) V_2 )
continue;
if ( V_7 -> type != V_15 && V_7 -> type != V_16 )
continue;
F_66 ( V_7 -> V_9 , V_7 -> V_10 ) ;
}
F_67 ( V_127 ) ;
F_68 () ;
}
void T_2 F_69 ( void )
{
#ifdef F_25
T_1 V_128 = 0 , V_129 = 0 ;
unsigned long V_87 , V_88 ;
T_4 V_1 , V_2 ;
int V_3 ;
T_1 V_130 ;
F_70 (i, MAX_NUMNODES, &start_pfn, &end_pfn, NULL) {
V_87 = F_17 ( V_87 , V_131 ) ;
V_88 = F_17 ( V_88 , V_131 ) ;
V_128 += V_88 - V_87 ;
}
F_71 (u, NUMA_NO_NODE, &start, &end, NULL) {
V_87 = F_72 (unsigned long, PFN_UP(start), MAX_DMA_PFN) ;
V_88 = F_72 (unsigned long, PFN_DOWN(end), MAX_DMA_PFN) ;
if ( V_87 < V_88 )
V_129 += V_88 - V_87 ;
}
F_73 ( V_128 - V_129 ) ;
#endif
}
