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
case V_23 :
F_5 ( V_17 L_7 , type ) ;
break;
default:
F_5 ( V_17 L_8 , type ) ;
break;
}
}
void T_2 F_8 ( char * V_24 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
F_5 ( V_25 L_9 , V_24 ,
( unsigned long long ) V_4 . V_8 [ V_3 ] . V_9 ,
( unsigned long long )
( V_4 . V_8 [ V_3 ] . V_9 + V_4 . V_8 [ V_3 ] . V_10 - 1 ) ) ;
F_7 ( V_4 . V_8 [ V_3 ] . type ) ;
F_5 ( V_17 L_10 ) ;
}
}
static int T_2 F_9 ( const void * V_26 , const void * V_27 )
{
struct V_28 * const * V_29 = V_26 , * const * V_30 = V_27 ;
const struct V_28 * V_31 = * V_29 , * V_32 = * V_30 ;
if ( V_31 -> V_9 != V_32 -> V_9 )
return V_31 -> V_9 > V_32 -> V_9 ? 1 : - 1 ;
return ( V_31 -> V_9 != V_31 -> V_33 -> V_9 ) - ( V_32 -> V_9 != V_32 -> V_33 -> V_9 ) ;
}
int T_2 F_10 ( struct V_6 * V_34 , int V_35 ,
T_3 * V_36 )
{
static struct V_28 V_37 [ 2 * V_38 ] V_39 ;
static struct V_28 * V_40 [ 2 * V_38 ] V_39 ;
static struct V_6 * V_41 [ V_38 ] V_39 ;
static struct V_6 V_42 [ V_38 ] V_39 ;
unsigned long V_43 , V_44 ;
unsigned long long V_45 ;
int V_46 ;
int V_47 ;
int V_48 ;
int V_49 , V_50 , V_51 ;
int V_3 ;
if ( * V_36 < 2 )
return - 1 ;
V_49 = * V_36 ;
F_11 ( V_49 > V_35 ) ;
for ( V_3 = 0 ; V_3 < V_49 ; V_3 ++ )
if ( V_34 [ V_3 ] . V_9 + V_34 [ V_3 ] . V_10 < V_34 [ V_3 ] . V_9 )
return - 1 ;
for ( V_3 = 0 ; V_3 < 2 * V_49 ; V_3 ++ )
V_40 [ V_3 ] = & V_37 [ V_3 ] ;
V_46 = 0 ;
for ( V_3 = 0 ; V_3 < V_49 ; V_3 ++ ) {
if ( V_34 [ V_3 ] . V_10 != 0 ) {
V_40 [ V_46 ] -> V_9 = V_34 [ V_3 ] . V_9 ;
V_40 [ V_46 ++ ] -> V_33 = & V_34 [ V_3 ] ;
V_40 [ V_46 ] -> V_9 = V_34 [ V_3 ] . V_9 +
V_34 [ V_3 ] . V_10 ;
V_40 [ V_46 ++ ] -> V_33 = & V_34 [ V_3 ] ;
}
}
V_51 = V_46 ;
F_12 ( V_40 , V_51 , sizeof *V_40 , F_9 , NULL ) ;
V_47 = 0 ;
V_48 = 0 ;
V_44 = 0 ;
V_45 = 0 ;
for ( V_46 = 0 ; V_46 < V_51 ; V_46 ++ ) {
if ( V_40 [ V_46 ] -> V_9 ==
V_40 [ V_46 ] -> V_33 -> V_9 ) {
V_41 [ V_47 ++ ] =
V_40 [ V_46 ] -> V_33 ;
} else {
for ( V_3 = 0 ; V_3 < V_47 ; V_3 ++ ) {
if ( V_41 [ V_3 ] ==
V_40 [ V_46 ] -> V_33 )
V_41 [ V_3 ] =
V_41 [ V_47 - 1 ] ;
}
V_47 -- ;
}
V_43 = 0 ;
for ( V_3 = 0 ; V_3 < V_47 ; V_3 ++ )
if ( V_41 [ V_3 ] -> type > V_43 )
V_43 = V_41 [ V_3 ] -> type ;
if ( V_43 != V_44 || V_43 == V_23 ) {
if ( V_44 != 0 ) {
V_42 [ V_48 ] . V_10 =
V_40 [ V_46 ] -> V_9 - V_45 ;
if ( V_42 [ V_48 ] . V_10 != 0 )
if ( ++ V_48 >= V_35 )
break;
}
if ( V_43 != 0 ) {
V_42 [ V_48 ] . V_9 =
V_40 [ V_46 ] -> V_9 ;
V_42 [ V_48 ] . type = V_43 ;
V_45 = V_40 [ V_46 ] -> V_9 ;
}
V_44 = V_43 ;
}
}
V_50 = V_48 ;
memcpy ( V_34 , V_42 , V_50 * sizeof( struct V_6 ) ) ;
* V_36 = V_50 ;
return 0 ;
}
static int T_2 F_13 ( struct V_6 * V_34 , int V_5 )
{
while ( V_5 ) {
T_1 V_1 = V_34 -> V_9 ;
T_1 V_10 = V_34 -> V_10 ;
T_1 V_2 = V_1 + V_10 ;
T_3 type = V_34 -> type ;
if ( V_1 > V_2 )
return - 1 ;
F_6 ( V_1 , V_10 , type ) ;
V_34 ++ ;
V_5 -- ;
}
return 0 ;
}
static int T_2 F_14 ( struct V_6 * V_34 , int V_5 )
{
if ( V_5 < 2 )
return - 1 ;
return F_13 ( V_34 , V_5 ) ;
}
static T_1 T_2 F_15 ( struct V_11 * V_12 , T_1 V_1 ,
T_1 V_10 , unsigned V_52 ,
unsigned V_53 )
{
T_1 V_2 ;
unsigned int V_3 ;
T_1 V_54 = 0 ;
F_11 ( V_52 == V_53 ) ;
if ( V_10 > ( V_55 - V_1 ) )
V_10 = V_55 - V_1 ;
V_2 = V_1 + V_10 ;
F_5 ( V_56 L_11 ,
( unsigned long long ) V_1 , ( unsigned long long ) ( V_2 - 1 ) ) ;
F_7 ( V_52 ) ;
F_5 ( V_17 L_12 ) ;
F_7 ( V_53 ) ;
F_5 ( V_17 L_10 ) ;
for ( V_3 = 0 ; V_3 < V_12 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_12 -> V_8 [ V_3 ] ;
T_1 V_57 , V_58 ;
T_1 V_59 ;
if ( V_7 -> type != V_52 )
continue;
V_59 = V_7 -> V_9 + V_7 -> V_10 ;
if ( V_7 -> V_9 >= V_1 && V_59 <= V_2 ) {
V_7 -> type = V_53 ;
V_54 += V_7 -> V_10 ;
continue;
}
if ( V_7 -> V_9 < V_1 && V_59 > V_2 ) {
F_3 ( V_12 , V_1 , V_10 , V_53 ) ;
F_3 ( V_12 , V_2 , V_59 - V_2 , V_7 -> type ) ;
V_7 -> V_10 = V_1 - V_7 -> V_9 ;
V_54 += V_10 ;
continue;
}
V_57 = F_16 ( V_1 , V_7 -> V_9 ) ;
V_58 = F_17 ( V_2 , V_59 ) ;
if ( V_57 >= V_58 )
continue;
F_3 ( V_12 , V_57 , V_58 - V_57 ,
V_53 ) ;
V_54 += V_58 - V_57 ;
V_7 -> V_10 -= V_58 - V_57 ;
if ( V_7 -> V_9 < V_57 )
continue;
V_7 -> V_9 = V_58 ;
}
return V_54 ;
}
T_1 T_2 F_18 ( T_1 V_1 , T_1 V_10 , unsigned V_52 ,
unsigned V_53 )
{
return F_15 ( & V_4 , V_1 , V_10 , V_52 , V_53 ) ;
}
static T_1 T_2 F_19 ( T_1 V_1 , T_1 V_10 ,
unsigned V_52 , unsigned V_53 )
{
return F_15 ( & V_60 , V_1 , V_10 , V_52 ,
V_53 ) ;
}
T_1 T_2 F_20 ( T_1 V_1 , T_1 V_10 , unsigned V_52 ,
int V_61 )
{
int V_3 ;
T_1 V_2 ;
T_1 V_62 = 0 ;
if ( V_10 > ( V_55 - V_1 ) )
V_10 = V_55 - V_1 ;
V_2 = V_1 + V_10 ;
F_5 ( V_56 L_13 ,
( unsigned long long ) V_1 , ( unsigned long long ) ( V_2 - 1 ) ) ;
if ( V_61 )
F_7 ( V_52 ) ;
F_5 ( V_17 L_10 ) ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
T_1 V_57 , V_58 ;
T_1 V_59 ;
if ( V_61 && V_7 -> type != V_52 )
continue;
V_59 = V_7 -> V_9 + V_7 -> V_10 ;
if ( V_7 -> V_9 >= V_1 && V_59 <= V_2 ) {
V_62 += V_7 -> V_10 ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
continue;
}
if ( V_7 -> V_9 < V_1 && V_59 > V_2 ) {
F_6 ( V_2 , V_59 - V_2 , V_7 -> type ) ;
V_7 -> V_10 = V_1 - V_7 -> V_9 ;
V_62 += V_10 ;
continue;
}
V_57 = F_16 ( V_1 , V_7 -> V_9 ) ;
V_58 = F_17 ( V_2 , V_59 ) ;
if ( V_57 >= V_58 )
continue;
V_62 += V_58 - V_57 ;
V_7 -> V_10 -= V_58 - V_57 ;
if ( V_7 -> V_9 < V_57 )
continue;
V_7 -> V_9 = V_58 ;
}
return V_62 ;
}
void T_2 F_21 ( void )
{
if ( F_10 ( V_4 . V_8 , F_4 ( V_4 . V_8 ) , & V_4 . V_5 ) )
return;
F_5 ( V_25 L_14 ) ;
F_8 ( L_15 ) ;
}
static void T_2 F_22 ( void )
{
F_10 ( V_60 . V_8 , F_4 ( V_60 . V_8 ) ,
& V_60 . V_5 ) ;
}
T_2 int F_23 ( unsigned long * V_63 , unsigned long * V_64 ,
unsigned long V_65 , unsigned long long V_66 )
{
unsigned long long V_67 ;
int V_3 = V_4 . V_5 ;
int V_68 = 0 ;
V_67 = ( V_66 && V_66 < V_69 ) ? V_66 : V_69 ;
while ( -- V_3 >= 0 ) {
unsigned long long V_1 = V_4 . V_8 [ V_3 ] . V_9 ;
unsigned long long V_2 = V_1 + V_4 . V_8 [ V_3 ] . V_10 ;
if ( V_2 < V_65 )
continue;
if ( V_67 > V_2 ) {
unsigned long V_70 = V_67 - V_2 ;
if ( V_70 >= * V_64 ) {
* V_64 = V_70 ;
* V_63 = V_2 ;
V_68 = 1 ;
}
}
if ( V_1 < V_67 )
V_67 = V_1 ;
}
return V_68 ;
}
T_2 void F_24 ( void )
{
unsigned long V_63 , V_64 ;
int V_68 ;
V_63 = 0x10000000 ;
V_64 = 0x400000 ;
V_68 = F_23 ( & V_63 , & V_64 , 0 , V_69 ) ;
#ifdef F_25
if ( ! V_68 ) {
V_63 = ( V_71 << V_72 ) + 1024 * 1024 ;
F_5 ( V_14
L_16
L_17 ) ;
}
#endif
V_73 = V_63 ;
F_5 ( V_25
L_18 ,
V_63 , V_63 + V_64 - 1 ) ;
}
void T_2 F_26 ( T_1 V_74 , T_3 V_75 )
{
int V_76 ;
struct V_6 * V_77 ;
struct V_78 * V_79 ;
V_79 = F_27 ( V_74 , V_75 ) ;
V_76 = V_79 -> V_80 / sizeof( struct V_6 ) ;
V_77 = (struct V_6 * ) ( V_79 -> V_81 ) ;
F_13 ( V_77 , V_76 ) ;
F_10 ( V_4 . V_8 , F_4 ( V_4 . V_8 ) , & V_4 . V_5 ) ;
F_28 ( V_79 , V_75 ) ;
F_5 ( V_25 L_19 ) ;
F_8 ( L_20 ) ;
}
void T_2 F_29 ( unsigned long V_82 )
{
int V_3 ;
unsigned long V_83 = 0 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
if ( V_83 < F_30 ( V_7 -> V_9 ) )
F_31 ( V_83 , F_30 ( V_7 -> V_9 ) ) ;
V_83 = F_32 ( V_7 -> V_9 + V_7 -> V_10 ) ;
if ( V_7 -> type != V_15 && V_7 -> type != V_16 )
F_31 ( F_30 ( V_7 -> V_9 ) , V_83 ) ;
if ( V_83 >= V_82 )
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
T_1 T_2 F_35 ( T_1 V_10 , T_1 V_84 )
{
T_1 V_9 ;
V_9 = F_36 ( V_10 , V_84 , V_85 ) ;
if ( V_9 ) {
F_19 ( V_9 , V_10 , V_15 , V_18 ) ;
F_5 ( V_25 L_21 ) ;
F_22 () ;
}
return V_9 ;
}
static unsigned long T_2 F_37 ( unsigned long V_82 )
{
int V_3 ;
unsigned long V_86 = 0 ;
unsigned long V_87 = V_88 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
unsigned long V_89 ;
unsigned long V_90 ;
if ( V_7 -> type != V_15 && V_7 -> type != V_23 )
continue;
V_89 = V_7 -> V_9 >> V_72 ;
V_90 = ( V_7 -> V_9 + V_7 -> V_10 ) >> V_72 ;
if ( V_89 >= V_82 )
continue;
if ( V_90 > V_82 ) {
V_86 = V_82 ;
break;
}
if ( V_90 > V_86 )
V_86 = V_90 ;
}
if ( V_86 > V_87 )
V_86 = V_87 ;
F_5 ( V_25 L_22 ,
V_86 , V_87 ) ;
return V_86 ;
}
unsigned long T_2 F_38 ( void )
{
return F_37 ( V_88 ) ;
}
unsigned long T_2 F_39 ( void )
{
return F_37 ( 1UL << ( 32 - V_72 ) ) ;
}
static void F_40 ( char * V_91 )
{
F_41 ( V_91 ) ;
F_42 ( V_91 ) ;
}
static int T_2 F_43 ( char * V_92 )
{
T_1 V_93 ;
if ( ! V_92 )
return - V_94 ;
if ( ! strcmp ( V_92 , L_23 ) ) {
#ifdef F_44
F_45 ( V_95 ) ;
return 0 ;
#else
F_5 ( V_96 L_24 ) ;
return - V_94 ;
#endif
}
V_97 = 1 ;
V_93 = F_46 ( V_92 , & V_92 ) ;
if ( V_93 == 0 )
return - V_94 ;
F_20 ( V_93 , V_55 - V_93 , V_15 , 1 ) ;
return 0 ;
}
static int T_2 F_47 ( char * V_92 )
{
char * V_98 ;
T_1 V_99 , V_93 ;
if ( ! V_92 )
return - V_94 ;
if ( ! strncmp ( V_92 , L_25 , 8 ) ) {
#ifdef F_48
V_100 = F_38 () ;
#endif
V_4 . V_5 = 0 ;
V_97 = 1 ;
return 0 ;
}
V_98 = V_92 ;
V_93 = F_46 ( V_92 , & V_92 ) ;
if ( V_92 == V_98 )
return - V_94 ;
V_97 = 1 ;
if ( * V_92 == '@' ) {
V_99 = F_46 ( V_92 + 1 , & V_92 ) ;
F_6 ( V_99 , V_93 , V_15 ) ;
} else if ( * V_92 == '#' ) {
V_99 = F_46 ( V_92 + 1 , & V_92 ) ;
F_6 ( V_99 , V_93 , V_19 ) ;
} else if ( * V_92 == '$' ) {
V_99 = F_46 ( V_92 + 1 , & V_92 ) ;
F_6 ( V_99 , V_93 , V_18 ) ;
} else if ( * V_92 == '!' ) {
V_99 = F_46 ( V_92 + 1 , & V_92 ) ;
F_6 ( V_99 , V_93 , V_23 ) ;
} else
F_20 ( V_93 , V_55 - V_93 , V_15 , 1 ) ;
return * V_92 == '\0' ? 0 : - V_94 ;
}
static int T_2 F_49 ( char * V_101 )
{
while ( V_101 ) {
char * V_102 = strchr ( V_101 , ',' ) ;
if ( V_102 )
* V_102 ++ = 0 ;
F_47 ( V_101 ) ;
V_101 = V_102 ;
}
return 0 ;
}
void T_2 F_50 ( void )
{
if ( V_97 ) {
if ( F_10 ( V_4 . V_8 , F_4 ( V_4 . V_8 ) ,
& V_4 . V_5 ) < 0 )
F_40 ( L_26 ) ;
F_5 ( V_25 L_27 ) ;
F_8 ( L_28 ) ;
}
}
static const char * F_51 ( int V_103 )
{
switch ( V_103 ) {
case V_16 :
case V_15 : return L_29 ;
case V_19 : return L_30 ;
case V_20 : return L_31 ;
case V_21 : return L_32 ;
case V_23 : return L_33 ;
case V_22 : return L_34 ;
default: return L_3 ;
}
}
static unsigned long F_52 ( int V_103 )
{
switch ( V_103 ) {
case V_16 :
case V_15 :
return V_104 ;
case V_19 :
case V_20 :
case V_21 :
case V_23 :
case V_22 :
default:
return V_105 ;
}
}
static unsigned long F_53 ( int V_103 )
{
switch ( V_103 ) {
case V_19 :
return V_106 ;
case V_20 :
return V_107 ;
case V_22 :
return V_108 ;
case V_23 :
return V_109 ;
case V_16 :
case V_15 :
case V_21 :
default:
return V_110 ;
}
}
static bool F_54 ( T_3 type , struct V_111 * V_112 )
{
if ( V_112 -> V_1 < ( 1ULL << 20 ) )
return true ;
switch ( type ) {
case V_18 :
case V_23 :
case V_22 :
return false ;
default:
return true ;
}
}
void T_2 F_55 ( void )
{
int V_3 ;
struct V_111 * V_112 ;
T_1 V_2 ;
V_112 = F_56 ( sizeof( struct V_111 ) * V_4 . V_5 ) ;
V_113 = V_112 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
V_2 = V_4 . V_8 [ V_3 ] . V_9 + V_4 . V_8 [ V_3 ] . V_10 - 1 ;
if ( V_2 != ( V_114 ) V_2 ) {
V_112 ++ ;
continue;
}
V_112 -> V_115 = F_51 ( V_4 . V_8 [ V_3 ] . type ) ;
V_112 -> V_1 = V_4 . V_8 [ V_3 ] . V_9 ;
V_112 -> V_2 = V_2 ;
V_112 -> V_116 = F_52 ( V_4 . V_8 [ V_3 ] . type ) ;
V_112 -> V_117 = F_53 ( V_4 . V_8 [ V_3 ] . type ) ;
if ( F_54 ( V_4 . V_8 [ V_3 ] . type , V_112 ) ) {
V_112 -> V_116 |= V_118 ;
F_57 ( & V_119 , V_112 ) ;
}
V_112 ++ ;
}
for ( V_3 = 0 ; V_3 < V_60 . V_5 ; V_3 ++ ) {
struct V_6 * V_120 = & V_60 . V_8 [ V_3 ] ;
F_58 ( V_120 -> V_9 ,
V_120 -> V_9 + V_120 -> V_10 ,
F_51 ( V_120 -> type ) ) ;
}
}
static unsigned long F_59 ( V_114 V_121 )
{
unsigned long V_122 = V_121 >> 20 ;
if ( ! V_122 )
return 64 * 1024 ;
if ( V_122 < 16 )
return 1024 * 1024 ;
return 64 * 1024 * 1024 ;
}
void T_2 F_60 ( void )
{
int V_3 ;
struct V_111 * V_112 ;
V_112 = V_113 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
if ( ! V_112 -> V_123 && V_112 -> V_2 )
F_61 ( & V_119 , V_112 ) ;
V_112 ++ ;
}
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_120 = & V_4 . V_8 [ V_3 ] ;
T_1 V_1 , V_2 ;
if ( V_120 -> type != V_15 )
continue;
V_1 = V_120 -> V_9 + V_120 -> V_10 ;
V_2 = F_62 ( V_1 , F_59 ( V_1 ) ) - 1 ;
if ( V_2 > V_124 )
V_2 = V_124 ;
if ( V_1 >= V_2 )
continue;
F_5 ( V_56
L_35 ,
V_1 , V_2 ) ;
F_63 ( & V_119 , V_1 , V_2 ,
L_36 ) ;
}
}
char * T_2 F_64 ( void )
{
char * V_24 = L_37 ;
T_3 V_50 ;
V_50 = V_125 . V_126 ;
F_10 ( V_125 . V_127 ,
F_4 ( V_125 . V_127 ) ,
& V_50 ) ;
V_125 . V_126 = V_50 ;
if ( F_14 ( V_125 . V_127 , V_125 . V_126 )
< 0 ) {
T_1 V_93 ;
if ( V_125 . V_128
< V_125 . V_129 . V_130 ) {
V_93 = V_125 . V_129 . V_130 ;
V_24 = L_38 ;
} else {
V_93 = V_125 . V_128 ;
V_24 = L_39 ;
}
V_4 . V_5 = 0 ;
F_6 ( 0 , F_65 () , V_15 ) ;
F_6 ( V_131 , V_93 << 10 , V_15 ) ;
}
return V_24 ;
}
void T_2 F_66 ( void )
{
char * V_24 ;
V_24 = V_132 . V_133 . V_134 () ;
memcpy ( & V_60 , & V_4 , sizeof( struct V_11 ) ) ;
F_5 ( V_25 L_40 ) ;
F_8 ( V_24 ) ;
}
void T_2 F_67 ( void )
{
int V_3 ;
T_1 V_2 ;
F_68 () ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
V_2 = V_7 -> V_9 + V_7 -> V_10 ;
if ( V_2 != ( V_114 ) V_2 )
continue;
if ( V_7 -> type != V_15 && V_7 -> type != V_16 )
continue;
F_69 ( V_7 -> V_9 , V_7 -> V_10 ) ;
}
F_70 ( V_135 ) ;
F_71 () ;
}
void T_2 F_72 ( void )
{
#ifdef F_25
T_1 V_136 = 0 , V_137 = 0 ;
unsigned long V_89 , V_90 ;
T_4 V_1 , V_2 ;
int V_3 ;
T_1 V_138 ;
F_73 (i, MAX_NUMNODES, &start_pfn, &end_pfn, NULL) {
V_89 = F_17 ( V_89 , V_139 ) ;
V_90 = F_17 ( V_90 , V_139 ) ;
V_136 += V_90 - V_89 ;
}
F_74 (u, NUMA_NO_NODE, MEMBLOCK_NONE, &start, &end,
NULL) {
V_89 = F_75 (unsigned long, PFN_UP(start), MAX_DMA_PFN) ;
V_90 = F_75 (unsigned long, PFN_DOWN(end), MAX_DMA_PFN) ;
if ( V_89 < V_90 )
V_137 += V_90 - V_89 ;
}
F_76 ( V_136 - V_137 ) ;
#endif
}
