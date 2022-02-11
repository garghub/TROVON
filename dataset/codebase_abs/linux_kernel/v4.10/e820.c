int
F_1 ( T_1 V_1 , T_1 V_2 , unsigned type )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 -> V_8 [ V_3 ] ;
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
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 -> V_8 [ V_3 ] ;
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
F_3 ( V_4 , V_1 , V_10 , type ) ;
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
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
F_5 ( V_25 L_9 , V_24 ,
( unsigned long long ) V_4 -> V_8 [ V_3 ] . V_9 ,
( unsigned long long )
( V_4 -> V_8 [ V_3 ] . V_9 + V_4 -> V_8 [ V_3 ] . V_10 - 1 ) ) ;
F_7 ( V_4 -> V_8 [ V_3 ] . type ) ;
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
T_1 V_2 = V_1 + V_10 - 1 ;
T_3 type = V_34 -> type ;
if ( V_1 > V_2 && F_14 ( V_10 ) )
return - 1 ;
F_6 ( V_1 , V_10 , type ) ;
V_34 ++ ;
V_5 -- ;
}
return 0 ;
}
static int T_2 F_15 ( struct V_6 * V_34 , int V_5 )
{
if ( V_5 < 2 )
return - 1 ;
return F_13 ( V_34 , V_5 ) ;
}
static T_1 T_2 F_16 ( struct V_11 * V_12 , T_1 V_1 ,
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
V_57 = F_17 ( V_1 , V_7 -> V_9 ) ;
V_58 = F_18 ( V_2 , V_59 ) ;
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
T_1 T_2 F_19 ( T_1 V_1 , T_1 V_10 , unsigned V_52 ,
unsigned V_53 )
{
return F_16 ( V_4 , V_1 , V_10 , V_52 , V_53 ) ;
}
static T_1 T_2 F_20 ( T_1 V_1 , T_1 V_10 ,
unsigned V_52 , unsigned V_53 )
{
return F_16 ( V_60 , V_1 , V_10 , V_52 ,
V_53 ) ;
}
T_1 T_2 F_21 ( T_1 V_1 , T_1 V_10 , unsigned V_52 ,
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
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 -> V_8 [ V_3 ] ;
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
V_57 = F_17 ( V_1 , V_7 -> V_9 ) ;
V_58 = F_18 ( V_2 , V_59 ) ;
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
void T_2 F_22 ( void )
{
if ( F_10 ( V_4 -> V_8 , F_4 ( V_4 -> V_8 ) , & V_4 -> V_5 ) )
return;
F_5 ( V_25 L_14 ) ;
F_8 ( L_15 ) ;
}
static void T_2 F_23 ( void )
{
F_10 ( V_60 -> V_8 , F_4 ( V_60 -> V_8 ) ,
& V_60 -> V_5 ) ;
}
T_2 int F_24 ( unsigned long * V_63 , unsigned long * V_64 ,
unsigned long V_65 , unsigned long long V_66 )
{
unsigned long long V_67 ;
int V_3 = V_4 -> V_5 ;
int V_68 = 0 ;
V_67 = ( V_66 && V_66 < V_69 ) ? V_66 : V_69 ;
while ( -- V_3 >= 0 ) {
unsigned long long V_1 = V_4 -> V_8 [ V_3 ] . V_9 ;
unsigned long long V_2 = V_1 + V_4 -> V_8 [ V_3 ] . V_10 ;
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
T_2 void F_25 ( void )
{
unsigned long V_63 , V_64 ;
int V_68 ;
V_63 = 0x10000000 ;
V_64 = 0x400000 ;
V_68 = F_24 ( & V_63 , & V_64 , 0 , V_69 ) ;
#ifdef F_26
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
T_2 void F_27 ( void )
{
struct V_11 * V_74 ;
int V_10 ;
V_10 = F_28 ( struct V_11 , V_8 ) + sizeof( struct V_6 ) * V_4 -> V_5 ;
V_74 = F_29 ( V_10 , V_75 ) ;
F_11 ( ! V_74 ) ;
memcpy ( V_74 , V_4 , V_10 ) ;
V_4 = V_74 ;
V_10 = F_28 ( struct V_11 , V_8 ) + sizeof( struct V_6 ) * V_60 -> V_5 ;
V_74 = F_29 ( V_10 , V_75 ) ;
F_11 ( ! V_74 ) ;
memcpy ( V_74 , V_60 , V_10 ) ;
V_60 = V_74 ;
}
void T_2 F_30 ( T_1 V_76 , T_3 V_77 )
{
int V_78 ;
struct V_6 * V_79 ;
struct V_80 * V_81 ;
V_81 = F_31 ( V_76 , V_77 ) ;
V_78 = V_81 -> V_82 / sizeof( struct V_6 ) ;
V_79 = (struct V_6 * ) ( V_81 -> V_83 ) ;
F_13 ( V_79 , V_78 ) ;
F_10 ( V_4 -> V_8 , F_4 ( V_4 -> V_8 ) , & V_4 -> V_5 ) ;
F_32 ( V_81 , V_77 ) ;
F_5 ( V_25 L_19 ) ;
F_8 ( L_20 ) ;
}
void T_2 F_33 ( unsigned long V_84 )
{
int V_3 ;
unsigned long V_85 = 0 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 -> V_8 [ V_3 ] ;
if ( V_85 < F_34 ( V_7 -> V_9 ) )
F_35 ( V_85 , F_34 ( V_7 -> V_9 ) ) ;
V_85 = F_36 ( V_7 -> V_9 + V_7 -> V_10 ) ;
if ( V_7 -> type != V_15 && V_7 -> type != V_16 )
F_35 ( F_34 ( V_7 -> V_9 ) , V_85 ) ;
if ( V_85 >= V_84 )
break;
}
}
static int T_2 F_37 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 -> V_8 [ V_3 ] ;
if ( V_7 -> type == V_20 )
F_38 ( V_7 -> V_9 , V_7 -> V_10 ) ;
}
return 0 ;
}
T_1 T_2 F_39 ( T_1 V_10 , T_1 V_86 )
{
T_1 V_9 ;
V_9 = F_40 ( V_10 , V_86 , V_87 ) ;
if ( V_9 ) {
F_20 ( V_9 , V_10 , V_15 , V_18 ) ;
F_5 ( V_25 L_21 ) ;
F_23 () ;
}
return V_9 ;
}
static unsigned long T_2 F_41 ( unsigned long V_84 , unsigned type )
{
int V_3 ;
unsigned long V_88 = 0 ;
unsigned long V_89 = V_90 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 -> V_8 [ V_3 ] ;
unsigned long V_91 ;
unsigned long V_92 ;
if ( V_7 -> type != type )
continue;
V_91 = V_7 -> V_9 >> V_72 ;
V_92 = ( V_7 -> V_9 + V_7 -> V_10 ) >> V_72 ;
if ( V_91 >= V_84 )
continue;
if ( V_92 > V_84 ) {
V_88 = V_84 ;
break;
}
if ( V_92 > V_88 )
V_88 = V_92 ;
}
if ( V_88 > V_89 )
V_88 = V_89 ;
F_5 ( V_25 L_22 ,
V_88 , V_89 ) ;
return V_88 ;
}
unsigned long T_2 F_42 ( void )
{
return F_41 ( V_90 , V_15 ) ;
}
unsigned long T_2 F_43 ( void )
{
return F_41 ( 1UL << ( 32 - V_72 ) , V_15 ) ;
}
static void T_2 F_44 ( char * V_93 )
{
F_45 ( V_93 ) ;
F_46 ( V_93 ) ;
}
static int T_2 F_47 ( char * V_94 )
{
T_1 V_95 ;
if ( ! V_94 )
return - V_96 ;
if ( ! strcmp ( V_94 , L_23 ) ) {
#ifdef F_48
F_49 ( V_97 ) ;
return 0 ;
#else
F_5 ( V_98 L_24 ) ;
return - V_96 ;
#endif
}
V_99 = 1 ;
V_95 = F_50 ( V_94 , & V_94 ) ;
if ( V_95 == 0 )
return - V_96 ;
F_21 ( V_95 , V_55 - V_95 , V_15 , 1 ) ;
return 0 ;
}
static int T_2 F_51 ( char * V_94 )
{
char * V_100 ;
T_1 V_101 , V_95 ;
if ( ! V_94 )
return - V_96 ;
if ( ! strncmp ( V_94 , L_25 , 8 ) ) {
#ifdef F_52
V_102 = F_42 () ;
#endif
V_4 -> V_5 = 0 ;
V_99 = 1 ;
return 0 ;
}
V_100 = V_94 ;
V_95 = F_50 ( V_94 , & V_94 ) ;
if ( V_94 == V_100 )
return - V_96 ;
V_99 = 1 ;
if ( * V_94 == '@' ) {
V_101 = F_50 ( V_94 + 1 , & V_94 ) ;
F_6 ( V_101 , V_95 , V_15 ) ;
} else if ( * V_94 == '#' ) {
V_101 = F_50 ( V_94 + 1 , & V_94 ) ;
F_6 ( V_101 , V_95 , V_19 ) ;
} else if ( * V_94 == '$' ) {
V_101 = F_50 ( V_94 + 1 , & V_94 ) ;
F_6 ( V_101 , V_95 , V_18 ) ;
} else if ( * V_94 == '!' ) {
V_101 = F_50 ( V_94 + 1 , & V_94 ) ;
F_6 ( V_101 , V_95 , V_23 ) ;
} else
F_21 ( V_95 , V_55 - V_95 , V_15 , 1 ) ;
return * V_94 == '\0' ? 0 : - V_96 ;
}
static int T_2 F_53 ( char * V_103 )
{
while ( V_103 ) {
char * V_104 = strchr ( V_103 , ',' ) ;
if ( V_104 )
* V_104 ++ = 0 ;
F_51 ( V_103 ) ;
V_103 = V_104 ;
}
return 0 ;
}
void T_2 F_54 ( void )
{
if ( V_99 ) {
if ( F_10 ( V_4 -> V_8 , F_4 ( V_4 -> V_8 ) ,
& V_4 -> V_5 ) < 0 )
F_44 ( L_26 ) ;
F_5 ( V_25 L_27 ) ;
F_8 ( L_28 ) ;
}
}
static const char * T_2 F_55 ( int V_105 )
{
switch ( V_105 ) {
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
static unsigned long T_2 F_56 ( int V_105 )
{
switch ( V_105 ) {
case V_16 :
case V_15 :
return V_106 ;
case V_19 :
case V_20 :
case V_21 :
case V_23 :
case V_22 :
default:
return V_107 ;
}
}
static unsigned long T_2 F_57 ( int V_105 )
{
switch ( V_105 ) {
case V_19 :
return V_108 ;
case V_20 :
return V_109 ;
case V_22 :
return V_110 ;
case V_23 :
return V_111 ;
case V_16 :
case V_15 :
case V_21 :
default:
return V_112 ;
}
}
static bool T_2 F_58 ( T_3 type , struct V_113 * V_114 )
{
if ( V_114 -> V_1 < ( 1ULL << 20 ) )
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
void T_2 F_59 ( void )
{
int V_3 ;
struct V_113 * V_114 ;
T_1 V_2 ;
V_114 = F_60 ( sizeof( struct V_113 ) * V_4 -> V_5 ) ;
V_115 = V_114 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
V_2 = V_4 -> V_8 [ V_3 ] . V_9 + V_4 -> V_8 [ V_3 ] . V_10 - 1 ;
if ( V_2 != ( V_116 ) V_2 ) {
V_114 ++ ;
continue;
}
V_114 -> V_117 = F_55 ( V_4 -> V_8 [ V_3 ] . type ) ;
V_114 -> V_1 = V_4 -> V_8 [ V_3 ] . V_9 ;
V_114 -> V_2 = V_2 ;
V_114 -> V_118 = F_56 ( V_4 -> V_8 [ V_3 ] . type ) ;
V_114 -> V_119 = F_57 ( V_4 -> V_8 [ V_3 ] . type ) ;
if ( F_58 ( V_4 -> V_8 [ V_3 ] . type , V_114 ) ) {
V_114 -> V_118 |= V_120 ;
F_61 ( & V_121 , V_114 ) ;
}
V_114 ++ ;
}
for ( V_3 = 0 ; V_3 < V_60 -> V_5 ; V_3 ++ ) {
struct V_6 * V_122 = & V_60 -> V_8 [ V_3 ] ;
F_62 ( V_122 -> V_9 ,
V_122 -> V_9 + V_122 -> V_10 ,
F_55 ( V_122 -> type ) ) ;
}
}
static unsigned long T_2 F_63 ( V_116 V_123 )
{
unsigned long V_124 = V_123 >> 20 ;
if ( ! V_124 )
return 64 * 1024 ;
if ( V_124 < 16 )
return 1024 * 1024 ;
return 64 * 1024 * 1024 ;
}
void T_2 F_64 ( void )
{
int V_3 ;
struct V_113 * V_114 ;
V_114 = V_115 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
if ( ! V_114 -> V_125 && V_114 -> V_2 )
F_65 ( & V_121 , V_114 ) ;
V_114 ++ ;
}
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
struct V_6 * V_122 = & V_4 -> V_8 [ V_3 ] ;
T_1 V_1 , V_2 ;
if ( V_122 -> type != V_15 )
continue;
V_1 = V_122 -> V_9 + V_122 -> V_10 ;
V_2 = F_66 ( V_1 , F_63 ( V_1 ) ) - 1 ;
if ( V_2 > V_126 )
V_2 = V_126 ;
if ( V_1 >= V_2 )
continue;
F_5 ( V_56
L_35 ,
V_1 , V_2 ) ;
F_67 ( & V_121 , V_1 , V_2 ,
L_36 ) ;
}
}
char * T_2 F_68 ( void )
{
char * V_24 = L_37 ;
T_3 V_50 ;
V_50 = V_127 . V_128 ;
F_10 ( V_127 . V_129 ,
F_4 ( V_127 . V_129 ) ,
& V_50 ) ;
V_127 . V_128 = V_50 ;
if ( F_15 ( V_127 . V_129 , V_127 . V_128 )
< 0 ) {
T_1 V_95 ;
if ( V_127 . V_130
< V_127 . V_131 . V_132 ) {
V_95 = V_127 . V_131 . V_132 ;
V_24 = L_38 ;
} else {
V_95 = V_127 . V_130 ;
V_24 = L_39 ;
}
V_4 -> V_5 = 0 ;
F_6 ( 0 , F_69 () , V_15 ) ;
F_6 ( V_133 , V_95 << 10 , V_15 ) ;
}
return V_24 ;
}
void T_2 F_70 ( void )
{
char * V_24 ;
V_24 = V_134 . V_135 . V_136 () ;
memcpy ( V_60 , V_4 , sizeof( struct V_11 ) ) ;
F_5 ( V_25 L_40 ) ;
F_8 ( V_24 ) ;
}
void T_2 F_71 ( void )
{
int V_3 ;
T_1 V_2 ;
F_72 () ;
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 -> V_8 [ V_3 ] ;
V_2 = V_7 -> V_9 + V_7 -> V_10 ;
if ( V_2 != ( V_116 ) V_2 )
continue;
if ( V_7 -> type != V_15 && V_7 -> type != V_16 )
continue;
F_73 ( V_7 -> V_9 , V_7 -> V_10 ) ;
}
F_74 ( V_137 ) ;
F_75 () ;
}
void T_2 F_76 ( void )
{
#ifdef F_26
T_1 V_138 = 0 , V_139 = 0 ;
unsigned long V_91 , V_92 ;
T_4 V_1 , V_2 ;
int V_3 ;
T_1 V_140 ;
F_77 (i, MAX_NUMNODES, &start_pfn, &end_pfn, NULL) {
V_91 = F_18 ( V_91 , V_141 ) ;
V_92 = F_18 ( V_92 , V_141 ) ;
V_138 += V_92 - V_91 ;
}
F_78 (u, NUMA_NO_NODE, MEMBLOCK_NONE, &start, &end,
NULL) {
V_91 = F_79 (unsigned long, PFN_UP(start), MAX_DMA_PFN) ;
V_92 = F_79 (unsigned long, PFN_DOWN(end), MAX_DMA_PFN) ;
if ( V_91 < V_92 )
V_139 += V_92 - V_91 ;
}
F_80 ( V_138 - V_139 ) ;
#endif
}
