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
F_5 ( V_14 L_1 ) ;
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
( V_4 . V_8 [ V_3 ] . V_9 + V_4 . V_8 [ V_3 ] . V_10 ) ) ;
F_7 ( V_4 . V_8 [ V_3 ] . type ) ;
F_5 ( V_17 L_9 ) ;
}
}
int T_2 F_9 ( struct V_6 * V_24 , int V_25 ,
T_3 * V_26 )
{
struct V_27 {
struct V_6 * V_28 ;
unsigned long long V_9 ;
};
static struct V_27 V_29 [ 2 * V_30 ] V_31 ;
static struct V_27 * V_32 [ 2 * V_30 ] V_31 ;
static struct V_6 * V_33 [ V_30 ] V_31 ;
static struct V_6 V_34 [ V_30 ] V_31 ;
struct V_27 * V_35 ;
unsigned long V_36 , V_37 ;
unsigned long long V_38 ;
int V_39 , V_40 ;
int V_41 ;
int V_42 ;
int V_43 , V_44 , V_45 ;
int V_3 ;
if ( * V_26 < 2 )
return - 1 ;
V_43 = * V_26 ;
F_10 ( V_43 > V_25 ) ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
if ( V_24 [ V_3 ] . V_9 + V_24 [ V_3 ] . V_10 < V_24 [ V_3 ] . V_9 )
return - 1 ;
for ( V_3 = 0 ; V_3 < 2 * V_43 ; V_3 ++ )
V_32 [ V_3 ] = & V_29 [ V_3 ] ;
V_39 = 0 ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ ) {
if ( V_24 [ V_3 ] . V_10 != 0 ) {
V_32 [ V_39 ] -> V_9 = V_24 [ V_3 ] . V_9 ;
V_32 [ V_39 ++ ] -> V_28 = & V_24 [ V_3 ] ;
V_32 [ V_39 ] -> V_9 = V_24 [ V_3 ] . V_9 +
V_24 [ V_3 ] . V_10 ;
V_32 [ V_39 ++ ] -> V_28 = & V_24 [ V_3 ] ;
}
}
V_45 = V_39 ;
V_40 = 1 ;
while ( V_40 ) {
V_40 = 0 ;
for ( V_3 = 1 ; V_3 < V_45 ; V_3 ++ ) {
unsigned long long V_46 , V_47 ;
unsigned long long V_48 , V_49 ;
V_46 = V_32 [ V_3 ] -> V_9 ;
V_47 = V_32 [ V_3 - 1 ] -> V_9 ;
V_48 = V_32 [ V_3 ] -> V_28 -> V_9 ;
V_49 = V_32 [ V_3 - 1 ] -> V_28 -> V_9 ;
if ( V_46 < V_47 ||
( V_46 == V_47 && V_46 == V_48 &&
V_47 != V_49 ) ) {
V_35 = V_32 [ V_3 ] ;
V_32 [ V_3 ] = V_32 [ V_3 - 1 ] ;
V_32 [ V_3 - 1 ] = V_35 ;
V_40 = 1 ;
}
}
}
V_41 = 0 ;
V_42 = 0 ;
V_37 = 0 ;
V_38 = 0 ;
for ( V_39 = 0 ; V_39 < V_45 ; V_39 ++ ) {
if ( V_32 [ V_39 ] -> V_9 ==
V_32 [ V_39 ] -> V_28 -> V_9 ) {
V_33 [ V_41 ++ ] =
V_32 [ V_39 ] -> V_28 ;
} else {
for ( V_3 = 0 ; V_3 < V_41 ; V_3 ++ ) {
if ( V_33 [ V_3 ] ==
V_32 [ V_39 ] -> V_28 )
V_33 [ V_3 ] =
V_33 [ V_41 - 1 ] ;
}
V_41 -- ;
}
V_36 = 0 ;
for ( V_3 = 0 ; V_3 < V_41 ; V_3 ++ )
if ( V_33 [ V_3 ] -> type > V_36 )
V_36 = V_33 [ V_3 ] -> type ;
if ( V_36 != V_37 ) {
if ( V_37 != 0 ) {
V_34 [ V_42 ] . V_10 =
V_32 [ V_39 ] -> V_9 - V_38 ;
if ( V_34 [ V_42 ] . V_10 != 0 )
if ( ++ V_42 >= V_25 )
break;
}
if ( V_36 != 0 ) {
V_34 [ V_42 ] . V_9 =
V_32 [ V_39 ] -> V_9 ;
V_34 [ V_42 ] . type = V_36 ;
V_38 = V_32 [ V_39 ] -> V_9 ;
}
V_37 = V_36 ;
}
}
V_44 = V_42 ;
memcpy ( V_24 , V_34 , V_44 * sizeof( struct V_6 ) ) ;
* V_26 = V_44 ;
return 0 ;
}
static int T_2 F_11 ( struct V_6 * V_24 , int V_5 )
{
while ( V_5 ) {
T_1 V_1 = V_24 -> V_9 ;
T_1 V_10 = V_24 -> V_10 ;
T_1 V_2 = V_1 + V_10 ;
T_3 type = V_24 -> type ;
if ( V_1 > V_2 )
return - 1 ;
F_6 ( V_1 , V_10 , type ) ;
V_24 ++ ;
V_5 -- ;
}
return 0 ;
}
static int T_2 F_12 ( struct V_6 * V_24 , int V_5 )
{
if ( V_5 < 2 )
return - 1 ;
return F_11 ( V_24 , V_5 ) ;
}
static T_1 T_2 F_13 ( struct V_11 * V_12 , T_1 V_1 ,
T_1 V_10 , unsigned V_50 ,
unsigned V_51 )
{
T_1 V_2 ;
unsigned int V_3 ;
T_1 V_52 = 0 ;
F_10 ( V_50 == V_51 ) ;
if ( V_10 > ( V_53 - V_1 ) )
V_10 = V_53 - V_1 ;
V_2 = V_1 + V_10 ;
F_5 ( V_54 L_10 ,
( unsigned long long ) V_1 ,
( unsigned long long ) V_2 ) ;
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
V_55 = F_14 ( V_1 , V_7 -> V_9 ) ;
V_56 = F_15 ( V_2 , V_57 ) ;
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
T_1 T_2 F_16 ( T_1 V_1 , T_1 V_10 , unsigned V_50 ,
unsigned V_51 )
{
return F_13 ( & V_4 , V_1 , V_10 , V_50 , V_51 ) ;
}
static T_1 T_2 F_17 ( T_1 V_1 , T_1 V_10 ,
unsigned V_50 , unsigned V_51 )
{
return F_13 ( & V_58 , V_1 , V_10 , V_50 ,
V_51 ) ;
}
T_1 T_2 F_18 ( T_1 V_1 , T_1 V_10 , unsigned V_50 ,
int V_59 )
{
int V_3 ;
T_1 V_2 ;
T_1 V_60 = 0 ;
if ( V_10 > ( V_53 - V_1 ) )
V_10 = V_53 - V_1 ;
V_2 = V_1 + V_10 ;
F_5 ( V_54 L_12 ,
( unsigned long long ) V_1 ,
( unsigned long long ) V_2 ) ;
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
V_55 = F_14 ( V_1 , V_7 -> V_9 ) ;
V_56 = F_15 ( V_2 , V_57 ) ;
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
void T_2 F_19 ( void )
{
T_3 V_5 ;
V_5 = V_4 . V_5 ;
if ( F_9 ( V_4 . V_8 , F_4 ( V_4 . V_8 ) , & V_5 ) )
return;
V_4 . V_5 = V_5 ;
F_5 ( V_23 L_13 ) ;
F_8 ( L_14 ) ;
}
static void T_2 F_20 ( void )
{
T_3 V_5 ;
V_5 = V_58 . V_5 ;
if ( F_9 ( V_58 . V_8 , F_4 ( V_58 . V_8 ) , & V_5 ) )
return;
V_58 . V_5 = V_5 ;
}
T_2 int F_21 ( unsigned long * V_61 , unsigned long * V_62 ,
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
T_2 void F_22 ( void )
{
unsigned long V_61 , V_62 ;
int V_66 ;
V_61 = 0x10000000 ;
V_62 = 0x400000 ;
V_66 = F_21 ( & V_61 , & V_62 , 0 , V_67 ) ;
#ifdef F_23
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
V_71 , V_61 , V_62 ) ;
}
void T_2 F_24 ( struct V_72 * V_73 )
{
int V_74 ;
struct V_6 * V_75 ;
V_74 = V_73 -> V_76 / sizeof( struct V_6 ) ;
V_75 = (struct V_6 * ) ( V_73 -> V_77 ) ;
F_11 ( V_75 , V_74 ) ;
F_9 ( V_4 . V_8 , F_4 ( V_4 . V_8 ) , & V_4 . V_5 ) ;
F_5 ( V_23 L_18 ) ;
F_8 ( L_19 ) ;
}
void T_2 F_25 ( unsigned long V_78 )
{
int V_3 ;
unsigned long V_79 ;
V_79 = F_26 ( V_4 . V_8 [ 0 ] . V_9 + V_4 . V_8 [ 0 ] . V_10 ) ;
for ( V_3 = 1 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
if ( V_79 < F_27 ( V_7 -> V_9 ) )
F_28 ( V_79 , F_27 ( V_7 -> V_9 ) ) ;
V_79 = F_26 ( V_7 -> V_9 + V_7 -> V_10 ) ;
if ( V_7 -> type != V_15 && V_7 -> type != V_16 )
F_28 ( F_27 ( V_7 -> V_9 ) , V_79 ) ;
if ( V_79 >= V_78 )
break;
}
}
static int T_2 F_29 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
if ( V_7 -> type == V_20 )
F_30 ( V_7 -> V_9 , V_7 -> V_10 ) ;
}
return 0 ;
}
T_1 T_2 F_31 ( T_1 V_80 , T_1 V_81 , T_1 V_82 )
{
T_1 V_10 = 0 ;
T_1 V_9 ;
T_1 V_1 ;
for ( V_1 = V_80 ; ; V_1 += V_10 ) {
V_1 = F_32 ( V_1 , & V_10 , V_82 ) ;
if ( V_1 == V_83 )
return 0 ;
if ( V_10 >= V_81 )
break;
}
#ifdef F_33
if ( V_1 >= V_84 )
return 0 ;
if ( V_1 + V_10 > V_84 )
V_10 = V_84 - V_1 ;
#endif
V_9 = F_34 ( V_1 + V_10 - V_81 , V_82 ) ;
if ( V_9 < V_1 )
return 0 ;
F_35 ( V_9 , V_9 + V_81 , L_20 ) ;
F_17 ( V_9 , V_81 , V_15 , V_18 ) ;
F_5 ( V_23 L_21 ) ;
F_20 () ;
return V_9 ;
}
static unsigned long T_2 F_36 ( unsigned long V_78 , unsigned type )
{
int V_3 ;
unsigned long V_85 = 0 ;
unsigned long V_86 = V_87 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
unsigned long V_88 ;
unsigned long V_89 ;
if ( V_7 -> type != type )
continue;
V_88 = V_7 -> V_9 >> V_70 ;
V_89 = ( V_7 -> V_9 + V_7 -> V_10 ) >> V_70 ;
if ( V_88 >= V_78 )
continue;
if ( V_89 > V_78 ) {
V_85 = V_78 ;
break;
}
if ( V_89 > V_85 )
V_85 = V_89 ;
}
if ( V_85 > V_86 )
V_85 = V_86 ;
F_5 ( V_23 L_22 ,
V_85 , V_86 ) ;
return V_85 ;
}
unsigned long T_2 F_37 ( void )
{
return F_36 ( V_87 , V_15 ) ;
}
unsigned long T_2 F_38 ( void )
{
return F_36 ( 1UL << ( 32 - V_70 ) , V_15 ) ;
}
static void F_39 ( char * V_90 )
{
F_40 ( V_90 ) ;
F_41 ( V_90 ) ;
}
static int T_2 F_42 ( char * V_91 )
{
T_1 V_92 ;
if ( ! V_91 )
return - V_93 ;
if ( ! strcmp ( V_91 , L_23 ) ) {
#ifdef F_33
F_43 ( V_94 ) ;
return 0 ;
#else
F_5 ( V_95 L_24 ) ;
return - V_93 ;
#endif
}
V_96 = 1 ;
V_92 = F_44 ( V_91 , & V_91 ) ;
if ( V_92 == 0 )
return - V_93 ;
F_18 ( V_92 , V_53 - V_92 , V_15 , 1 ) ;
return 0 ;
}
static int T_2 F_45 ( char * V_91 )
{
char * V_97 ;
T_1 V_98 , V_92 ;
if ( ! V_91 )
return - V_93 ;
if ( ! strncmp ( V_91 , L_25 , 8 ) ) {
#ifdef F_46
V_99 = F_37 () ;
#endif
V_4 . V_5 = 0 ;
V_96 = 1 ;
return 0 ;
}
V_97 = V_91 ;
V_92 = F_44 ( V_91 , & V_91 ) ;
if ( V_91 == V_97 )
return - V_93 ;
V_96 = 1 ;
if ( * V_91 == '@' ) {
V_98 = F_44 ( V_91 + 1 , & V_91 ) ;
F_6 ( V_98 , V_92 , V_15 ) ;
} else if ( * V_91 == '#' ) {
V_98 = F_44 ( V_91 + 1 , & V_91 ) ;
F_6 ( V_98 , V_92 , V_19 ) ;
} else if ( * V_91 == '$' ) {
V_98 = F_44 ( V_91 + 1 , & V_91 ) ;
F_6 ( V_98 , V_92 , V_18 ) ;
} else
F_18 ( V_92 , V_53 - V_92 , V_15 , 1 ) ;
return * V_91 == '\0' ? 0 : - V_93 ;
}
void T_2 F_47 ( void )
{
if ( V_96 ) {
T_3 V_100 = V_4 . V_5 ;
if ( F_9 ( V_4 . V_8 , F_4 ( V_4 . V_8 ) , & V_100 ) < 0 )
F_39 ( L_26 ) ;
V_4 . V_5 = V_100 ;
F_5 ( V_23 L_27 ) ;
F_8 ( L_28 ) ;
}
}
static inline const char * F_48 ( int V_101 )
{
switch ( V_101 ) {
case V_16 :
case V_15 : return L_29 ;
case V_19 : return L_30 ;
case V_20 : return L_31 ;
case V_21 : return L_32 ;
default: return L_33 ;
}
}
void T_2 F_49 ( void )
{
int V_3 ;
struct V_102 * V_103 ;
T_1 V_2 ;
V_103 = F_50 ( sizeof( struct V_102 ) * V_4 . V_5 ) ;
V_104 = V_103 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
V_2 = V_4 . V_8 [ V_3 ] . V_9 + V_4 . V_8 [ V_3 ] . V_10 - 1 ;
if ( V_2 != ( V_105 ) V_2 ) {
V_103 ++ ;
continue;
}
V_103 -> V_106 = F_48 ( V_4 . V_8 [ V_3 ] . type ) ;
V_103 -> V_1 = V_4 . V_8 [ V_3 ] . V_9 ;
V_103 -> V_2 = V_2 ;
V_103 -> V_107 = V_108 ;
if ( V_4 . V_8 [ V_3 ] . type != V_18 || V_103 -> V_1 < ( 1ULL << 20 ) ) {
V_103 -> V_107 |= V_109 ;
F_51 ( & V_110 , V_103 ) ;
}
V_103 ++ ;
}
for ( V_3 = 0 ; V_3 < V_58 . V_5 ; V_3 ++ ) {
struct V_6 * V_111 = & V_58 . V_8 [ V_3 ] ;
F_52 ( V_111 -> V_9 ,
V_111 -> V_9 + V_111 -> V_10 - 1 ,
F_48 ( V_111 -> type ) ) ;
}
}
static unsigned long F_53 ( V_105 V_112 )
{
unsigned long V_113 = V_112 >> 20 ;
if ( ! V_113 )
return 64 * 1024 ;
if ( V_113 < 16 )
return 1024 * 1024 ;
return 64 * 1024 * 1024 ;
}
void T_2 F_54 ( void )
{
int V_3 ;
struct V_102 * V_103 ;
V_103 = V_104 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
if ( ! V_103 -> V_114 && V_103 -> V_2 )
F_55 ( & V_110 , V_103 ) ;
V_103 ++ ;
}
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_111 = & V_4 . V_8 [ V_3 ] ;
T_1 V_1 , V_2 ;
if ( V_111 -> type != V_15 )
continue;
V_1 = V_111 -> V_9 + V_111 -> V_10 ;
V_2 = F_56 ( V_1 , F_53 ( V_1 ) ) - 1 ;
if ( V_2 > V_115 )
V_2 = V_115 ;
if ( V_1 >= V_2 )
continue;
F_5 ( V_54 L_34 ,
V_1 , V_2 ) ;
F_57 ( & V_110 , V_1 , V_2 ,
L_35 ) ;
}
}
char * T_2 F_58 ( void )
{
char * V_22 = L_36 ;
T_3 V_44 ;
V_44 = V_116 . V_117 ;
F_9 ( V_116 . V_118 ,
F_4 ( V_116 . V_118 ) ,
& V_44 ) ;
V_116 . V_117 = V_44 ;
if ( F_12 ( V_116 . V_118 , V_116 . V_117 )
< 0 ) {
T_1 V_92 ;
if ( V_116 . V_119
< V_116 . V_120 . V_121 ) {
V_92 = V_116 . V_120 . V_121 ;
V_22 = L_37 ;
} else {
V_92 = V_116 . V_119 ;
V_22 = L_38 ;
}
V_4 . V_5 = 0 ;
F_6 ( 0 , F_59 () , V_15 ) ;
F_6 ( V_122 , V_92 << 10 , V_15 ) ;
}
return V_22 ;
}
void T_2 F_60 ( void )
{
char * V_22 ;
V_22 = V_123 . V_124 . V_125 () ;
memcpy ( & V_58 , & V_4 , sizeof( struct V_11 ) ) ;
F_5 ( V_23 L_39 ) ;
F_8 ( V_22 ) ;
}
void T_2 F_61 ( void )
{
int V_3 ;
T_1 V_2 ;
V_126 = 1 ;
for ( V_3 = 0 ; V_3 < V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_7 = & V_4 . V_8 [ V_3 ] ;
V_2 = V_7 -> V_9 + V_7 -> V_10 ;
if ( V_2 != ( V_105 ) V_2 )
continue;
if ( V_7 -> type != V_15 && V_7 -> type != V_16 )
continue;
F_62 ( V_7 -> V_9 , V_7 -> V_10 ) ;
}
F_63 () ;
F_64 () ;
}
void T_2 F_65 ( void )
{
#ifdef F_23
T_1 V_127 ;
T_1 V_128 ;
V_128 = F_66 ( 0 , V_129 << V_70 ) >> V_70 ;
V_127 = F_67 ( 0 , V_129 << V_70 ) >> V_70 ;
F_68 ( V_128 - V_127 ) ;
#endif
}
