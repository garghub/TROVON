int * F_1 ( char * V_1 , int * V_2 , int V_3 )
{
int V_4 , V_5 ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
if ( strncmp ( V_1 , V_7 [ V_4 ] . V_1 , 32 ) == 0 ) {
if ( V_3 )
V_7 [ V_4 ] . V_8 = V_4 ;
return V_7 [ V_4 ] . V_2 ;
}
}
if ( V_6 >= V_9 ) {
F_2 ( V_10 L_1 , V_1 ) ;
return V_2 ;
}
V_5 = V_6 ++ ;
strncpy ( V_7 [ V_5 ] . V_1 , V_1 , 32 ) ;
if ( V_3 )
V_7 [ V_5 ] . V_8 = V_5 ;
else
V_7 [ V_5 ] . V_8 = - 1 ;
for ( V_4 = 0 ; V_4 < 32 ; V_4 ++ )
V_7 [ V_5 ] . V_2 [ V_4 ] = V_2 [ V_4 ] ;
return V_7 [ V_5 ] . V_2 ;
}
static int F_3 ( void T_1 * V_11 )
{
T_2 V_12 ;
if ( F_4 ( & V_12 , V_11 , sizeof( V_12 ) ) )
return - V_13 ;
F_1 ( V_12 . V_1 , V_12 . V_2 , 0 ) ;
if ( F_5 ( V_11 , & V_12 , sizeof( V_12 ) ) )
return - V_13 ;
return 0 ;
}
static int F_6 ( void T_1 * V_11 )
{
int V_5 ;
if ( F_7 ( V_5 , ( int T_1 * ) ( & ( ( ( T_2 T_1 * ) V_11 ) -> V_8 ) ) ) )
return - V_13 ;
if ( V_5 < 0 || V_5 >= V_6 )
return - V_14 ;
if ( F_5 ( V_11 , & V_7 [ V_5 ] , sizeof( T_2 ) ) )
return - V_13 ;
return 0 ;
}
static T_3 F_8 ( struct V_15 * V_15 , char T_1 * V_12 , T_4 V_16 , T_5 * V_17 )
{
int V_18 = F_9 ( V_15 -> V_19 . V_20 -> V_21 ) ;
int V_22 = - V_14 ;
F_10 ( & V_23 ) ;
F_11 ( F_2 ( L_2 , V_18 , V_16 ) ) ;
switch ( V_18 & 0x0f ) {
case V_24 :
case V_25 :
case V_26 :
V_22 = F_12 ( V_18 , V_15 , V_12 , V_16 ) ;
break;
case V_27 :
case V_28 :
V_22 = F_13 ( V_18 , V_15 , V_12 , V_16 ) ;
break;
case V_29 :
V_22 = F_14 ( V_18 , V_15 , V_12 , V_16 ) ;
}
F_15 ( & V_23 ) ;
return V_22 ;
}
static T_3 F_16 ( struct V_15 * V_15 , const char T_1 * V_12 , T_4 V_16 , T_5 * V_17 )
{
int V_18 = F_9 ( V_15 -> V_19 . V_20 -> V_21 ) ;
int V_22 = - V_14 ;
F_10 ( & V_23 ) ;
F_11 ( F_2 ( L_3 , V_18 , V_16 ) ) ;
switch ( V_18 & 0x0f ) {
case V_27 :
case V_28 :
V_22 = F_17 ( V_18 , V_15 , V_12 , V_16 ) ;
break;
case V_24 :
case V_25 :
case V_26 :
V_22 = F_18 ( V_18 , V_15 , V_12 , V_16 ) ;
break;
case V_29 :
V_22 = F_19 ( V_18 , V_15 , V_12 , V_16 ) ;
break;
}
F_15 ( & V_23 ) ;
return V_22 ;
}
static int F_20 ( struct V_30 * V_30 , struct V_15 * V_15 )
{
int V_18 = F_9 ( V_30 ) ;
int V_31 ;
F_11 ( F_2 ( L_4 , V_18 ) ) ;
if ( ( V_18 >= V_32 ) || ( V_18 < 0 ) ) {
F_2 ( V_10 L_5 , V_18 ) ;
return - V_33 ;
}
F_10 ( & V_23 ) ;
switch ( V_18 & 0x0f ) {
case V_34 :
V_18 >>= 4 ;
if ( V_18 >= 0 && V_18 < V_9 && V_35 [ V_18 ] == NULL ) {
F_21 ( L_6 , V_18 ) ;
}
V_31 = - V_33 ;
if ( V_18 && ( V_18 >= V_36 || V_35 [ V_18 ] == NULL ) )
break;
if ( ! F_22 ( V_35 [ V_18 ] -> V_37 ) )
break;
V_31 = 0 ;
break;
case V_27 :
case V_28 :
V_31 = F_23 ( V_18 , V_15 ) ;
break;
case V_29 :
V_31 = F_24 ( V_18 , V_15 ) ;
break;
case V_24 :
case V_25 :
case V_26 :
V_31 = F_25 ( V_18 , V_15 ) ;
break;
default:
F_2 ( V_10 L_5 , V_18 ) ;
V_31 = - V_33 ;
}
F_15 ( & V_23 ) ;
return V_31 ;
}
static int F_26 ( struct V_30 * V_30 , struct V_15 * V_15 )
{
int V_18 = F_9 ( V_30 ) ;
F_10 ( & V_23 ) ;
F_11 ( F_2 ( L_7 , V_18 ) ) ;
switch ( V_18 & 0x0f ) {
case V_34 :
F_27 ( V_35 [ V_18 >> 4 ] -> V_37 ) ;
break;
case V_27 :
case V_28 :
F_28 ( V_18 , V_15 ) ;
break;
case V_29 :
F_29 ( V_18 , V_15 ) ;
break;
case V_24 :
case V_25 :
case V_26 :
F_30 ( V_18 , V_15 ) ;
break;
default:
F_2 ( V_10 L_8 , V_18 ) ;
}
F_15 ( & V_23 ) ;
return 0 ;
}
static int F_31 ( int V_18 , void T_1 * V_11 )
{
T_6 V_38 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
F_32 ( V_38 . V_39 , V_35 [ V_18 ] -> V_39 , sizeof( V_38 . V_39 ) ) ;
F_32 ( V_38 . V_1 , V_35 [ V_18 ] -> V_1 , sizeof( V_38 . V_1 ) ) ;
V_38 . V_40 = V_35 [ V_18 ] -> V_40 ;
if ( F_5 ( V_11 , & V_38 , sizeof( V_38 ) ) )
return - V_13 ;
return 0 ;
}
static int F_33 ( int V_18 , void T_1 * V_11 )
{
T_7 V_38 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
F_32 ( V_38 . V_39 , V_35 [ V_18 ] -> V_39 , sizeof( V_38 . V_39 ) ) ;
F_32 ( V_38 . V_1 , V_35 [ V_18 ] -> V_1 , sizeof( V_38 . V_1 ) ) ;
if ( F_34 ( V_11 , & V_38 , sizeof( V_38 ) ) )
return - V_13 ;
return 0 ;
}
static int F_35 ( int V_41 , unsigned int V_42 , void T_1 * V_11 )
{
if ( V_41 < 0 || V_41 >= V_9 )
return - V_33 ;
if ( V_35 [ V_41 ] == NULL ) {
F_21 ( L_6 , V_41 ) ;
}
if ( V_41 >= V_36 || ! V_35 [ V_41 ] )
return - V_33 ;
if ( V_42 == V_43 )
return F_31 ( V_41 , V_11 ) ;
if ( V_42 == V_44 )
return F_33 ( V_41 , V_11 ) ;
if ( F_36 ( V_42 ) & V_45 )
V_35 [ V_41 ] -> V_40 ++ ;
if ( ! V_35 [ V_41 ] -> V_46 )
return - V_14 ;
return V_35 [ V_41 ] -> V_46 ( V_41 , V_42 , V_11 ) ;
}
static long F_37 ( struct V_15 * V_15 , unsigned int V_42 , unsigned long V_11 )
{
int V_47 = 0 , V_48 ;
int V_18 = F_9 ( V_15 -> V_49 -> V_21 ) ;
long V_22 = - V_14 ;
void T_1 * V_50 = ( void T_1 * ) V_11 ;
if ( F_36 ( V_42 ) != V_51 && F_36 ( V_42 ) != 0 ) {
V_47 = F_38 ( V_42 ) ;
if ( V_47 < 1 || V_47 > 65536 || ! V_50 )
return - V_13 ;
if ( F_36 ( V_42 ) & V_45 )
if ( ! F_39 ( V_52 , V_50 , V_47 ) )
return - V_13 ;
if ( F_36 ( V_42 ) & V_53 )
if ( ! F_39 ( V_54 , V_50 , V_47 ) )
return - V_13 ;
}
F_11 ( F_2 ( L_9 , V_18 , V_42 , V_11 ) ) ;
if ( V_42 == V_55 )
return F_40 ( V_56 , ( int T_1 * ) V_50 ) ;
F_10 ( & V_23 ) ;
if ( F_41 ( V_42 ) == 'M' && V_36 > 0 &&
( V_18 & 0x0f ) != V_34 ) {
V_48 = V_18 & 0x0f ;
switch ( V_48 ) {
case V_24 :
case V_25 :
case V_26 :
V_22 = F_35 ( V_57 [ V_18 >> 4 ] -> V_58 ,
V_42 , V_50 ) ;
break;
default:
V_22 = F_35 ( V_18 >> 4 , V_42 , V_50 ) ;
break;
}
F_15 ( & V_23 ) ;
return V_22 ;
}
switch ( V_18 & 0x0f ) {
case V_34 :
if ( V_42 == V_59 )
V_22 = F_6 ( V_50 ) ;
else if ( V_42 == V_60 )
V_22 = F_3 ( V_50 ) ;
else
V_22 = F_35 ( V_18 >> 4 , V_42 , V_50 ) ;
break;
case V_27 :
case V_28 :
V_22 = F_42 ( V_18 , V_15 , V_42 , V_50 ) ;
break;
case V_24 :
case V_25 :
case V_26 :
V_22 = F_43 ( V_18 , V_15 , V_42 , V_50 ) ;
break;
case V_29 :
V_22 = F_44 ( V_18 , V_15 , V_42 , V_50 ) ;
break;
}
F_15 ( & V_23 ) ;
return V_22 ;
}
static unsigned int F_45 ( struct V_15 * V_15 , T_8 * V_61 )
{
struct V_30 * V_30 = V_15 -> V_19 . V_20 -> V_21 ;
int V_18 = F_9 ( V_30 ) ;
F_11 ( F_2 ( L_10 , V_18 ) ) ;
switch ( V_18 & 0x0f ) {
case V_27 :
case V_28 :
return F_46 ( V_18 , V_15 , V_61 ) ;
case V_29 :
return F_47 ( V_18 , V_15 , V_61 ) ;
case V_24 :
case V_25 :
case V_26 :
return F_48 ( V_15 , V_18 >> 4 , V_61 ) ;
}
return 0 ;
}
static int F_49 ( struct V_15 * V_15 , struct V_62 * V_63 )
{
int V_64 ;
unsigned long V_65 ;
struct V_66 * V_67 = NULL ;
int V_18 = F_9 ( V_15 -> V_19 . V_20 -> V_21 ) ;
V_64 = V_18 & 0x0f ;
V_18 >>= 4 ;
if ( V_64 != V_24 && V_64 != V_25 && V_64 != V_26 ) {
F_2 ( V_10 L_11 ) ;
return - V_14 ;
}
F_10 ( & V_23 ) ;
if ( V_63 -> V_68 & V_69 )
V_67 = V_57 [ V_18 ] -> V_70 ;
else if ( V_63 -> V_68 & V_71 )
V_67 = V_57 [ V_18 ] -> V_72 ;
else {
F_2 ( V_10 L_12 ) ;
F_15 ( & V_23 ) ;
return - V_14 ;
}
if ( V_67 == NULL ) {
F_2 ( V_10 L_13 ) ;
F_15 ( & V_23 ) ;
return - V_73 ;
}
if ( V_67 -> V_74 == NULL ) {
F_2 ( V_10 L_14 ) ;
F_15 ( & V_23 ) ;
return - V_73 ;
}
if ( V_67 -> V_75 ) {
F_2 ( V_10 L_15 ) ;
F_15 ( & V_23 ) ;
return - V_73 ;
}
if ( V_63 -> V_76 != 0 ) {
F_2 ( V_10 L_16 ) ;
F_15 ( & V_23 ) ;
return - V_14 ;
}
V_65 = V_63 -> V_77 - V_63 -> V_78 ;
if ( V_65 != V_67 -> V_79 ) {
F_2 ( V_80 L_17 , V_65 , V_67 -> V_79 ) ;
}
if ( F_50 ( V_63 , V_63 -> V_78 ,
F_51 ( V_67 -> V_74 ) >> V_81 ,
V_63 -> V_77 - V_63 -> V_78 , V_63 -> V_82 ) ) {
F_15 ( & V_23 ) ;
return - V_83 ;
}
V_67 -> V_75 |= V_84 ;
if( V_57 [ V_18 ] -> V_85 -> V_86 )
V_57 [ V_18 ] -> V_85 -> V_86 ( V_18 ) ;
memset ( V_67 -> V_74 ,
V_67 -> V_87 ,
V_67 -> V_79 ) ;
F_15 ( & V_23 ) ;
return 0 ;
}
static int F_52 ( void )
{
int V_88 , V_89 ;
V_88 = F_53 ( & V_90 , 1 ) ;
if( V_88 == - 1 )
goto V_91;
V_89 = F_53 ( & V_90 , 8 ) ;
if( V_89 != - 1 )
return 0 ;
F_54 ( 1 ) ;
V_91:
return - 1 ;
}
static int T_9 F_55 ( void )
{
int V_92 ;
int V_4 , V_93 ;
#ifdef F_56
if( V_94 )
V_95 = V_94 ;
#endif
V_92 = F_52 () ;
if ( V_92 ) {
F_2 ( V_10 L_18 ) ;
return V_92 ;
}
V_96 = ( V_97 > 0 ? 1 : 0 ) ;
for ( V_4 = 0 ; V_4 < F_57 ( V_98 ) ; V_4 ++ ) {
V_93 = 0 ;
do {
unsigned short V_99 = V_98 [ V_4 ] . V_99 + V_93 * 0x10 ;
if ( ! F_53 ( & V_90 , V_99 ) )
V_98 [ V_4 ] . V_100 = ( 1 << V_93 ) ;
} while ( ++ V_93 < V_101 );
}
if ( V_102 >= V_103 - 1 )
F_2 ( V_10 L_19 ) ;
return 0 ;
}
static void T_10 F_58 ( void )
{
int V_4 , V_93 ;
for ( V_4 = 0 ; V_4 < F_57 ( V_98 ) ; V_4 ++ ) {
V_93 = 0 ;
do {
if ( V_98 [ V_4 ] . V_100 & ( 1 << V_93 ) )
F_54 ( V_98 [ V_4 ] . V_99 ) ;
} while ( ++ V_93 < V_101 );
}
F_54 ( 1 ) ;
F_54 ( 8 ) ;
F_59 () ;
F_60 () ;
for ( V_4 = 0 ; V_4 < V_104 ; V_4 ++ )
if ( V_105 [ V_4 ] != V_106 ) {
F_2 ( V_10 L_20 , V_4 ) ;
F_61 ( V_4 ) ;
}
for ( V_4 = 0 ; V_4 < V_102 ; V_4 ++ )
F_62 ( V_107 [ V_4 ] ) ;
}
int F_63 ( int V_108 , char * V_109 )
{
int V_92 ;
if ( ( V_92 = F_64 ( V_108 , V_109 ) ) != 0 )
return V_92 ;
V_105 [ V_108 ] = V_110 ;
return 0 ;
}
int F_65 ( int V_108 , char * V_109 )
{
if ( ! F_66 ( V_108 ) ) {
F_2 ( V_10 L_21 , V_108 ) ;
return 1 ;
}
if ( V_105 [ V_108 ] != V_110 ) {
F_2 ( L_22 , V_108 , V_105 [ V_108 ] ) ;
return 1 ;
}
V_105 [ V_108 ] = V_111 ;
return 0 ;
}
void F_61 ( int V_108 )
{
if ( V_105 [ V_108 ] == V_106 ) {
return;
}
F_67 ( V_108 ) ;
V_105 [ V_108 ] = V_106 ;
}
void F_68 ( int V_108 )
{
if ( V_105 [ V_108 ] != V_111 ) {
F_2 ( V_10 L_23 , V_108 ) ;
return;
}
V_105 [ V_108 ] = V_110 ;
}
static void F_69 ( unsigned long V_112 )
{
F_70 ( 0 ) ;
}
void F_71 ( int V_16 )
{
extern unsigned long V_113 ;
if ( V_16 < 0 ) {
V_114 . V_115 = ( - V_16 ) + V_116 ;
F_72 ( & V_114 ) ;
return;
}
V_16 += V_113 ;
V_16 -= V_116 ;
if ( V_16 < 1 )
V_16 = 1 ;
V_114 . V_115 = ( V_16 ) + V_116 ;
F_72 ( & V_114 ) ;
}
void F_59 ( void )
{
F_73 ( & V_114 ) ;
}
void F_74 ( char * V_1 , struct V_117 * V_118 )
{
#ifndef F_75
return;
#else
F_2 ( L_24 , V_1 , V_118 -> V_119 ) ;
if ( V_118 -> V_120 )
F_2 ( L_25 , ( V_118 -> V_120 > 0 ) ? V_118 -> V_120 : - V_118 -> V_120 ) ;
if ( V_118 -> V_121 != - 1 || V_118 -> V_122 != - 1 )
{
F_2 ( L_26 , V_118 -> V_121 ) ;
if ( V_118 -> V_122 != - 1 )
F_2 ( L_27 , V_118 -> V_122 ) ;
}
F_2 ( L_28 ) ;
#endif
}
void F_76 ( char * V_1 , int V_123 , int V_120 , int V_121 , int V_122 )
{
#ifndef F_75
return;
#else
F_2 ( L_24 , V_1 , V_123 ) ;
if ( V_120 )
F_2 ( L_25 , ( V_120 > 0 ) ? V_120 : - V_120 ) ;
if ( V_121 != - 1 || V_122 != - 1 )
{
F_2 ( L_26 , V_121 ) ;
if ( V_122 != - 1 )
F_2 ( L_27 , V_122 ) ;
}
F_2 ( L_28 ) ;
#endif
}
