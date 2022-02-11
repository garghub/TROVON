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
case V_22 :
F_5 ( V_17 L_7 , type ) ;
break;
default:
F_5 ( V_17 L_8 , type ) ;
break;
}
}
void T_2 F_8 ( char * V_23 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
F_5 ( V_24 L_9 , V_23 ,
( unsigned long long ) V_4 . V_8 [ V_3 ] . V_9 ,
( unsigned long long )
( V_4 . V_8 [ V_3 ] . V_9 + V_4 . V_8 [ V_3 ] . V_10 - 1 ) ) ;
F_7 ( V_4 . V_8 [ V_3 ] . type ) ;
F_5 ( V_17 L_10 ) ;
}
}
static int T_2 F_9 ( const void * V_25 , const void * V_26 )
{
struct V_27 * const * V_28 = V_25 , * const * V_29 = V_26 ;
const struct V_27 * V_30 = * V_28 , * V_31 = * V_29 ;
if ( V_30 -> V_9 != V_31 -> V_9 )
return V_30 -> V_9 > V_31 -> V_9 ? 1 : - 1 ;
return ( V_30 -> V_9 != V_30 -> V_32 -> V_9 ) - ( V_31 -> V_9 != V_31 -> V_32 -> V_9 ) ;
}
int T_2 F_10 ( struct V_6 * V_33 , int V_34 ,
T_3 * V_35 )
{
static struct V_27 V_36 [ 2 * V_37 ] V_38 ;
static struct V_27 * V_39 [ 2 * V_37 ] V_38 ;
static struct V_6 * V_40 [ V_37 ] V_38 ;
static struct V_6 V_41 [ V_37 ] V_38 ;
unsigned long V_42 , V_43 ;
unsigned long long V_44 ;
int V_45 ;
int V_46 ;
int V_47 ;
int V_48 , V_49 , V_50 ;
int V_3 ;
if ( * V_35 < 2 )
return - 1 ;
V_48 = * V_35 ;
F_11 ( V_48 > V_34 ) ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ )
if ( V_33 [ V_3 ] . V_9 + V_33 [ V_3 ] . V_10 < V_33 [ V_3 ] . V_9 )
return - 1 ;
for ( V_3 = 0 ; V_3 < 2 * V_48 ; V_3 ++ )
V_39 [ V_3 ] = & V_36 [ V_3 ] ;
V_45 = 0 ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ ) {
if ( V_33 [ V_3 ] . V_10 != 0 ) {
V_39 [ V_45 ] -> V_9 = V_33 [ V_3 ] . V_9 ;
V_39 [ V_45 ++ ] -> V_32 = & V_33 [ V_3 ] ;
V_39 [ V_45 ] -> V_9 = V_33 [ V_3 ] . V_9 +
V_33 [ V_3 ] . V_10 ;
V_39 [ V_45 ++ ] -> V_32 = & V_33 [ V_3 ] ;
}
}
V_50 = V_45 ;
F_12 ( V_39 , V_50 , sizeof *V_39 , F_9 , NULL ) ;
V_46 = 0 ;
V_47 = 0 ;
V_43 = 0 ;
V_44 = 0 ;
for ( V_45 = 0 ; V_45 < V_50 ; V_45 ++ ) {
if ( V_39 [ V_45 ] -> V_9 ==
V_39 [ V_45 ] -> V_32 -> V_9 ) {
V_40 [ V_46 ++ ] =
V_39 [ V_45 ] -> V_32 ;
} else {
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ ) {
if ( V_40 [ V_3 ] ==
V_39 [ V_45 ] -> V_32 )
V_40 [ V_3 ] =
V_40 [ V_46 - 1 ] ;
}
V_46 -- ;
}
V_42 = 0 ;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ )
if ( V_40 [ V_3 ] -> type > V_42 )
V_42 = V_40 [ V_3 ] -> type ;
if ( V_42 != V_43 || V_42 == V_22 ) {
if ( V_43 != 0 ) {
V_41 [ V_47 ] . V_10 =
V_39 [ V_45 ] -> V_9 - V_44 ;
if ( V_41 [ V_47 ] . V_10 != 0 )
if ( ++ V_47 >= V_34 )
break;
}
if ( V_42 != 0 ) {
V_41 [ V_47 ] . V_9 =
V_39 [ V_45 ] -> V_9 ;
V_41 [ V_47 ] . type = V_42 ;
V_44 = V_39 [ V_45 ] -> V_9 ;
}
V_43 = V_42 ;
}
}
V_49 = V_47 ;
memcpy ( V_33 , V_41 , V_49 * sizeof( struct V_6 ) ) ;
* V_35 = V_49 ;
return 0 ;
}
static int T_2 F_13 ( struct V_6 * V_33 , int V_5 )
{
while ( V_5 ) {
T_1 V_1 = V_33 -> V_9 ;
T_1 V_10 = V_33 -> V_10 ;
T_1 V_2 = V_1 + V_10 ;
T_3 type = V_33 -> type ;
if ( V_1 > V_2 )
return - 1 ;
F_6 ( V_1 , V_10 , type ) ;
V_33 ++ ;
V_5 -- ;
}
return 0 ;
}
static int T_2 F_14 ( struct V_6 * V_33 , int V_5 )
{
if ( V_5 < 2 )
return - 1 ;
return F_13 ( V_33 , V_5 ) ;
}
static T_1 T_2 F_15 ( struct V_11 * V_12 , T_1 V_1 ,
T_1 V_10 , unsigned V_51 ,
unsigned V_52 )
{
T_1 V_2 ;
unsigned int V_3 ;
T_1 V_53 = 0 ;
F_11 ( V_51 == V_52 ) ;
if ( V_10 > ( V_54 - V_1 ) )
V_10 = V_54 - V_1 ;
V_2 = V_1 + V_10 ;
F_5 ( V_55 L_11 ,
( unsigned long long ) V_1 , ( unsigned long long ) ( V_2 - 1 ) ) ;
F_7 ( V_51 ) ;
F_5 ( V_17 L_12 ) ;
F_7 ( V_52 ) ;
F_5 ( V_17 L_10 ) ;
for ( V_3 = 0 ; V_3 < V_12 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_12 -> V_8 [ V_3 ] ;
T_1 V_56 , V_57 ;
T_1 V_58 ;
if ( V_7 -> type != V_51 )
continue;
V_58 = V_7 -> V_9 + V_7 -> V_10 ;
if ( V_7 -> V_9 >= V_1 && V_58 <= V_2 ) {
V_7 -> type = V_52 ;
V_53 += V_7 -> V_10 ;
continue;
}
if ( V_7 -> V_9 < V_1 && V_58 > V_2 ) {
F_3 ( V_12 , V_1 , V_10 , V_52 ) ;
F_3 ( V_12 , V_2 , V_58 - V_2 , V_7 -> type ) ;
V_7 -> V_10 = V_1 - V_7 -> V_9 ;
V_53 += V_10 ;
continue;
}
V_56 = F_16 ( V_1 , V_7 -> V_9 ) ;
V_57 = F_17 ( V_2 , V_58 ) ;
if ( V_56 >= V_57 )
continue;
F_3 ( V_12 , V_56 , V_57 - V_56 ,
V_52 ) ;
V_53 += V_57 - V_56 ;
V_7 -> V_10 -= V_57 - V_56 ;
if ( V_7 -> V_9 < V_56 )
continue;
V_7 -> V_9 = V_57 ;
}
return V_53 ;
}
T_1 T_2 F_18 ( T_1 V_1 , T_1 V_10 , unsigned V_51 ,
unsigned V_52 )
{
return F_15 ( & V_4 , V_1 , V_10 , V_51 , V_52 ) ;
}
static T_1 T_2 F_19 ( T_1 V_1 , T_1 V_10 ,
unsigned V_51 , unsigned V_52 )
{
return F_15 ( & V_59 , V_1 , V_10 , V_51 ,
V_52 ) ;
}
T_1 T_2 F_20 ( T_1 V_1 , T_1 V_10 , unsigned V_51 ,
int V_60 )
{
int V_3 ;
T_1 V_2 ;
T_1 V_61 = 0 ;
if ( V_10 > ( V_54 - V_1 ) )
V_10 = V_54 - V_1 ;
V_2 = V_1 + V_10 ;
F_5 ( V_55 L_13 ,
( unsigned long long ) V_1 , ( unsigned long long ) ( V_2 - 1 ) ) ;
if ( V_60 )
F_7 ( V_51 ) ;
F_5 ( V_17 L_10 ) ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
T_1 V_56 , V_57 ;
T_1 V_58 ;
if ( V_60 && V_7 -> type != V_51 )
continue;
V_58 = V_7 -> V_9 + V_7 -> V_10 ;
if ( V_7 -> V_9 >= V_1 && V_58 <= V_2 ) {
V_61 += V_7 -> V_10 ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
continue;
}
if ( V_7 -> V_9 < V_1 && V_58 > V_2 ) {
F_6 ( V_2 , V_58 - V_2 , V_7 -> type ) ;
V_7 -> V_10 = V_1 - V_7 -> V_9 ;
V_61 += V_10 ;
continue;
}
V_56 = F_16 ( V_1 , V_7 -> V_9 ) ;
V_57 = F_17 ( V_2 , V_58 ) ;
if ( V_56 >= V_57 )
continue;
V_61 += V_57 - V_56 ;
V_7 -> V_10 -= V_57 - V_56 ;
if ( V_7 -> V_9 < V_56 )
continue;
V_7 -> V_9 = V_57 ;
}
return V_61 ;
}
void T_2 F_21 ( void )
{
if ( F_10 ( V_4 . V_8 , F_4 ( V_4 . V_8 ) , & V_4 . V_5 ) )
return;
F_5 ( V_24 L_14 ) ;
F_8 ( L_15 ) ;
}
static void T_2 F_22 ( void )
{
F_10 ( V_59 . V_8 , F_4 ( V_59 . V_8 ) ,
& V_59 . V_5 ) ;
}
T_2 int F_23 ( unsigned long * V_62 , unsigned long * V_63 ,
unsigned long V_64 , unsigned long long V_65 )
{
unsigned long long V_66 ;
int V_3 = V_4 . V_5 ;
int V_67 = 0 ;
V_66 = ( V_65 && V_65 < V_68 ) ? V_65 : V_68 ;
while ( -- V_3 >= 0 ) {
unsigned long long V_1 = V_4 . V_8 [ V_3 ] . V_9 ;
unsigned long long V_2 = V_1 + V_4 . V_8 [ V_3 ] . V_10 ;
if ( V_2 < V_64 )
continue;
if ( V_66 > V_2 ) {
unsigned long V_69 = V_66 - V_2 ;
if ( V_69 >= * V_63 ) {
* V_63 = V_69 ;
* V_62 = V_2 ;
V_67 = 1 ;
}
}
if ( V_1 < V_66 )
V_66 = V_1 ;
}
return V_67 ;
}
T_2 void F_24 ( void )
{
unsigned long V_62 , V_63 ;
int V_67 ;
V_62 = 0x10000000 ;
V_63 = 0x400000 ;
V_67 = F_23 ( & V_62 , & V_63 , 0 , V_68 ) ;
#ifdef F_25
if ( ! V_67 ) {
V_62 = ( V_70 << V_71 ) + 1024 * 1024 ;
F_5 ( V_14
L_16
L_17 ) ;
}
#endif
V_72 = V_62 ;
F_5 ( V_24
L_18 ,
V_62 , V_62 + V_63 - 1 ) ;
}
void T_2 F_26 ( T_1 V_73 , T_3 V_74 )
{
int V_75 ;
struct V_6 * V_76 ;
struct V_77 * V_78 ;
V_78 = F_27 ( V_73 , V_74 ) ;
V_75 = V_78 -> V_79 / sizeof( struct V_6 ) ;
V_76 = (struct V_6 * ) ( V_78 -> V_80 ) ;
F_13 ( V_76 , V_75 ) ;
F_10 ( V_4 . V_8 , F_4 ( V_4 . V_8 ) , & V_4 . V_5 ) ;
F_28 ( V_78 , V_74 ) ;
F_5 ( V_24 L_19 ) ;
F_8 ( L_20 ) ;
}
void T_2 F_29 ( unsigned long V_81 )
{
int V_3 ;
unsigned long V_82 = 0 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
if ( V_82 < F_30 ( V_7 -> V_9 ) )
F_31 ( V_82 , F_30 ( V_7 -> V_9 ) ) ;
V_82 = F_32 ( V_7 -> V_9 + V_7 -> V_10 ) ;
if ( V_7 -> type != V_15 && V_7 -> type != V_16 )
F_31 ( F_30 ( V_7 -> V_9 ) , V_82 ) ;
if ( V_82 >= V_81 )
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
T_1 T_2 F_35 ( T_1 V_10 , T_1 V_83 )
{
T_1 V_9 ;
V_9 = F_36 ( V_10 , V_83 , V_84 ) ;
if ( V_9 ) {
F_19 ( V_9 , V_10 , V_15 , V_18 ) ;
F_5 ( V_24 L_21 ) ;
F_22 () ;
}
return V_9 ;
}
static unsigned long T_2 F_37 ( unsigned long V_81 )
{
int V_3 ;
unsigned long V_85 = 0 ;
unsigned long V_86 = V_87 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
unsigned long V_88 ;
unsigned long V_89 ;
if ( V_7 -> type != V_15 && V_7 -> type != V_22 )
continue;
V_88 = V_7 -> V_9 >> V_71 ;
V_89 = ( V_7 -> V_9 + V_7 -> V_10 ) >> V_71 ;
if ( V_88 >= V_81 )
continue;
if ( V_89 > V_81 ) {
V_85 = V_81 ;
break;
}
if ( V_89 > V_85 )
V_85 = V_89 ;
}
if ( V_85 > V_86 )
V_85 = V_86 ;
F_5 ( V_24 L_22 ,
V_85 , V_86 ) ;
return V_85 ;
}
unsigned long T_2 F_38 ( void )
{
return F_37 ( V_87 ) ;
}
unsigned long T_2 F_39 ( void )
{
return F_37 ( 1UL << ( 32 - V_71 ) ) ;
}
static void F_40 ( char * V_90 )
{
F_41 ( V_90 ) ;
F_42 ( V_90 ) ;
}
static int T_2 F_43 ( char * V_91 )
{
T_1 V_92 ;
if ( ! V_91 )
return - V_93 ;
if ( ! strcmp ( V_91 , L_23 ) ) {
#ifdef F_44
F_45 ( V_94 ) ;
return 0 ;
#else
F_5 ( V_95 L_24 ) ;
return - V_93 ;
#endif
}
V_96 = 1 ;
V_92 = F_46 ( V_91 , & V_91 ) ;
if ( V_92 == 0 )
return - V_93 ;
F_20 ( V_92 , V_54 - V_92 , V_15 , 1 ) ;
return 0 ;
}
static int T_2 F_47 ( char * V_91 )
{
char * V_97 ;
T_1 V_98 , V_92 ;
if ( ! V_91 )
return - V_93 ;
if ( ! strncmp ( V_91 , L_25 , 8 ) ) {
#ifdef F_48
V_99 = F_38 () ;
#endif
V_4 . V_5 = 0 ;
V_96 = 1 ;
return 0 ;
}
V_97 = V_91 ;
V_92 = F_46 ( V_91 , & V_91 ) ;
if ( V_91 == V_97 )
return - V_93 ;
V_96 = 1 ;
if ( * V_91 == '@' ) {
V_98 = F_46 ( V_91 + 1 , & V_91 ) ;
F_6 ( V_98 , V_92 , V_15 ) ;
} else if ( * V_91 == '#' ) {
V_98 = F_46 ( V_91 + 1 , & V_91 ) ;
F_6 ( V_98 , V_92 , V_19 ) ;
} else if ( * V_91 == '$' ) {
V_98 = F_46 ( V_91 + 1 , & V_91 ) ;
F_6 ( V_98 , V_92 , V_18 ) ;
} else if ( * V_91 == '!' ) {
V_98 = F_46 ( V_91 + 1 , & V_91 ) ;
F_6 ( V_98 , V_92 , V_22 ) ;
} else
F_20 ( V_92 , V_54 - V_92 , V_15 , 1 ) ;
return * V_91 == '\0' ? 0 : - V_93 ;
}
static int T_2 F_49 ( char * V_100 )
{
while ( V_100 ) {
char * V_101 = strchr ( V_100 , ',' ) ;
if ( V_101 )
* V_101 ++ = 0 ;
F_47 ( V_100 ) ;
V_100 = V_101 ;
}
return 0 ;
}
void T_2 F_50 ( void )
{
if ( V_96 ) {
if ( F_10 ( V_4 . V_8 , F_4 ( V_4 . V_8 ) ,
& V_4 . V_5 ) < 0 )
F_40 ( L_26 ) ;
F_5 ( V_24 L_27 ) ;
F_8 ( L_28 ) ;
}
}
static inline const char * F_51 ( int V_102 )
{
switch ( V_102 ) {
case V_16 :
case V_15 : return L_29 ;
case V_19 : return L_30 ;
case V_20 : return L_31 ;
case V_21 : return L_32 ;
case V_22 : return L_33 ;
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
if ( ( ( V_4 . V_8 [ V_3 ] . type != V_18 ) &&
( V_4 . V_8 [ V_3 ] . type != V_22 ) ) ||
V_104 -> V_1 < ( 1ULL << 20 ) ) {
V_104 -> V_108 |= V_110 ;
F_54 ( & V_111 , V_104 ) ;
}
V_104 ++ ;
}
for ( V_3 = 0 ; V_3 < V_59 . V_5 ; V_3 ++ ) {
struct V_6 * V_112 = & V_59 . V_8 [ V_3 ] ;
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
F_5 ( V_55
L_34 ,
V_1 , V_2 ) ;
F_60 ( & V_111 , V_1 , V_2 ,
L_35 ) ;
}
}
char * T_2 F_61 ( void )
{
char * V_23 = L_36 ;
T_3 V_49 ;
V_49 = V_117 . V_118 ;
F_10 ( V_117 . V_119 ,
F_4 ( V_117 . V_119 ) ,
& V_49 ) ;
V_117 . V_118 = V_49 ;
if ( F_14 ( V_117 . V_119 , V_117 . V_118 )
< 0 ) {
T_1 V_92 ;
if ( V_117 . V_120
< V_117 . V_121 . V_122 ) {
V_92 = V_117 . V_121 . V_122 ;
V_23 = L_37 ;
} else {
V_92 = V_117 . V_120 ;
V_23 = L_38 ;
}
V_4 . V_5 = 0 ;
F_6 ( 0 , F_62 () , V_15 ) ;
F_6 ( V_123 , V_92 << 10 , V_15 ) ;
}
return V_23 ;
}
void T_2 F_63 ( void )
{
char * V_23 ;
V_23 = V_124 . V_125 . V_126 () ;
memcpy ( & V_59 , & V_4 , sizeof( struct V_11 ) ) ;
F_5 ( V_24 L_39 ) ;
F_8 ( V_23 ) ;
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
unsigned long V_88 , V_89 ;
T_4 V_1 , V_2 ;
int V_3 ;
T_1 V_130 ;
F_70 (i, MAX_NUMNODES, &start_pfn, &end_pfn, NULL) {
V_88 = F_17 ( V_88 , V_131 ) ;
V_89 = F_17 ( V_89 , V_131 ) ;
V_128 += V_89 - V_88 ;
}
F_71 (u, NUMA_NO_NODE, &start, &end, NULL) {
V_88 = F_72 (unsigned long, PFN_UP(start), MAX_DMA_PFN) ;
V_89 = F_72 (unsigned long, PFN_DOWN(end), MAX_DMA_PFN) ;
if ( V_88 < V_89 )
V_129 += V_89 - V_88 ;
}
F_73 ( V_128 - V_129 ) ;
#endif
}
