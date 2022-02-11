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
int V_18 = F_9 ( F_10 ( V_15 ) ) ;
int V_19 = - V_14 ;
F_11 ( & V_20 ) ;
switch ( V_18 & 0x0f ) {
case V_21 :
case V_22 :
case V_23 :
V_19 = F_12 ( V_18 , V_15 , V_12 , V_16 ) ;
break;
case V_24 :
case V_25 :
V_19 = F_13 ( V_18 , V_15 , V_12 , V_16 ) ;
break;
case V_26 :
V_19 = F_14 ( V_18 , V_15 , V_12 , V_16 ) ;
}
F_15 ( & V_20 ) ;
return V_19 ;
}
static T_3 F_16 ( struct V_15 * V_15 , const char T_1 * V_12 , T_4 V_16 , T_5 * V_17 )
{
int V_18 = F_9 ( F_10 ( V_15 ) ) ;
int V_19 = - V_14 ;
F_11 ( & V_20 ) ;
switch ( V_18 & 0x0f ) {
case V_24 :
case V_25 :
V_19 = F_17 ( V_18 , V_15 , V_12 , V_16 ) ;
break;
case V_21 :
case V_22 :
case V_23 :
V_19 = F_18 ( V_18 , V_15 , V_12 , V_16 ) ;
break;
case V_26 :
V_19 = F_19 ( V_18 , V_15 , V_12 , V_16 ) ;
break;
}
F_15 ( & V_20 ) ;
return V_19 ;
}
static int F_20 ( struct V_27 * V_27 , struct V_15 * V_15 )
{
int V_18 = F_9 ( V_27 ) ;
int V_28 ;
if ( ( V_18 >= V_29 ) || ( V_18 < 0 ) ) {
F_2 ( V_10 L_2 , V_18 ) ;
return - V_30 ;
}
F_11 ( & V_20 ) ;
switch ( V_18 & 0x0f ) {
case V_31 :
V_18 >>= 4 ;
if ( V_18 >= 0 && V_18 < V_9 && V_32 [ V_18 ] == NULL ) {
F_21 ( L_3 , V_18 ) ;
}
V_28 = - V_30 ;
if ( V_18 && ( V_18 >= V_33 || V_32 [ V_18 ] == NULL ) )
break;
if ( ! F_22 ( V_32 [ V_18 ] -> V_34 ) )
break;
V_28 = 0 ;
break;
case V_24 :
case V_25 :
V_28 = F_23 ( V_18 , V_15 ) ;
break;
case V_26 :
V_28 = F_24 ( V_18 , V_15 ) ;
break;
case V_21 :
case V_22 :
case V_23 :
V_28 = F_25 ( V_18 , V_15 ) ;
break;
default:
F_2 ( V_10 L_2 , V_18 ) ;
V_28 = - V_30 ;
}
F_15 ( & V_20 ) ;
return V_28 ;
}
static int F_26 ( struct V_27 * V_27 , struct V_15 * V_15 )
{
int V_18 = F_9 ( V_27 ) ;
F_11 ( & V_20 ) ;
switch ( V_18 & 0x0f ) {
case V_31 :
F_27 ( V_32 [ V_18 >> 4 ] -> V_34 ) ;
break;
case V_24 :
case V_25 :
F_28 ( V_18 , V_15 ) ;
break;
case V_26 :
F_29 ( V_18 , V_15 ) ;
break;
case V_21 :
case V_22 :
case V_23 :
F_30 ( V_18 , V_15 ) ;
break;
default:
F_2 ( V_10 L_4 , V_18 ) ;
}
F_15 ( & V_20 ) ;
return 0 ;
}
static int F_31 ( int V_18 , void T_1 * V_11 )
{
T_6 V_35 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
F_32 ( V_35 . V_36 , V_32 [ V_18 ] -> V_36 , sizeof( V_35 . V_36 ) ) ;
F_32 ( V_35 . V_1 , V_32 [ V_18 ] -> V_1 , sizeof( V_35 . V_1 ) ) ;
V_35 . V_37 = V_32 [ V_18 ] -> V_37 ;
if ( F_5 ( V_11 , & V_35 , sizeof( V_35 ) ) )
return - V_13 ;
return 0 ;
}
static int F_33 ( int V_18 , void T_1 * V_11 )
{
T_7 V_35 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
F_32 ( V_35 . V_36 , V_32 [ V_18 ] -> V_36 , sizeof( V_35 . V_36 ) ) ;
F_32 ( V_35 . V_1 , V_32 [ V_18 ] -> V_1 , sizeof( V_35 . V_1 ) ) ;
if ( F_34 ( V_11 , & V_35 , sizeof( V_35 ) ) )
return - V_13 ;
return 0 ;
}
static int F_35 ( int V_38 , unsigned int V_39 , void T_1 * V_11 )
{
if ( V_38 < 0 || V_38 >= V_9 )
return - V_30 ;
if ( V_32 [ V_38 ] == NULL ) {
F_21 ( L_3 , V_38 ) ;
}
if ( V_38 >= V_33 || ! V_32 [ V_38 ] )
return - V_30 ;
if ( V_39 == V_40 )
return F_31 ( V_38 , V_11 ) ;
if ( V_39 == V_41 )
return F_33 ( V_38 , V_11 ) ;
if ( F_36 ( V_39 ) & V_42 )
V_32 [ V_38 ] -> V_37 ++ ;
if ( ! V_32 [ V_38 ] -> V_43 )
return - V_14 ;
return V_32 [ V_38 ] -> V_43 ( V_38 , V_39 , V_11 ) ;
}
static long F_37 ( struct V_15 * V_15 , unsigned int V_39 , unsigned long V_11 )
{
int V_44 = 0 , V_45 ;
int V_18 = F_9 ( F_10 ( V_15 ) ) ;
long V_19 = - V_14 ;
void T_1 * V_46 = ( void T_1 * ) V_11 ;
if ( F_36 ( V_39 ) != V_47 && F_36 ( V_39 ) != 0 ) {
V_44 = F_38 ( V_39 ) ;
if ( V_44 < 1 || V_44 > 65536 || ! V_46 )
return - V_13 ;
if ( F_36 ( V_39 ) & V_42 )
if ( ! F_39 ( V_48 , V_46 , V_44 ) )
return - V_13 ;
if ( F_36 ( V_39 ) & V_49 )
if ( ! F_39 ( V_50 , V_46 , V_44 ) )
return - V_13 ;
}
if ( V_39 == V_51 )
return F_40 ( V_52 , ( int T_1 * ) V_46 ) ;
F_11 ( & V_20 ) ;
if ( F_41 ( V_39 ) == 'M' && V_33 > 0 &&
( V_18 & 0x0f ) != V_31 ) {
V_45 = V_18 & 0x0f ;
switch ( V_45 ) {
case V_21 :
case V_22 :
case V_23 :
V_19 = F_35 ( V_53 [ V_18 >> 4 ] -> V_54 ,
V_39 , V_46 ) ;
break;
default:
V_19 = F_35 ( V_18 >> 4 , V_39 , V_46 ) ;
break;
}
F_15 ( & V_20 ) ;
return V_19 ;
}
switch ( V_18 & 0x0f ) {
case V_31 :
if ( V_39 == V_55 )
V_19 = F_6 ( V_46 ) ;
else if ( V_39 == V_56 )
V_19 = F_3 ( V_46 ) ;
else
V_19 = F_35 ( V_18 >> 4 , V_39 , V_46 ) ;
break;
case V_24 :
case V_25 :
V_19 = F_42 ( V_18 , V_15 , V_39 , V_46 ) ;
break;
case V_21 :
case V_22 :
case V_23 :
V_19 = F_43 ( V_18 , V_15 , V_39 , V_46 ) ;
break;
case V_26 :
V_19 = F_44 ( V_18 , V_15 , V_39 , V_46 ) ;
break;
}
F_15 ( & V_20 ) ;
return V_19 ;
}
static unsigned int F_45 ( struct V_15 * V_15 , T_8 * V_57 )
{
struct V_27 * V_27 = F_10 ( V_15 ) ;
int V_18 = F_9 ( V_27 ) ;
switch ( V_18 & 0x0f ) {
case V_24 :
case V_25 :
return F_46 ( V_18 , V_15 , V_57 ) ;
case V_26 :
return F_47 ( V_18 , V_15 , V_57 ) ;
case V_21 :
case V_22 :
case V_23 :
return F_48 ( V_15 , V_18 >> 4 , V_57 ) ;
}
return 0 ;
}
static int F_49 ( struct V_15 * V_15 , struct V_58 * V_59 )
{
int V_60 ;
unsigned long V_61 ;
struct V_62 * V_63 = NULL ;
int V_18 = F_9 ( F_10 ( V_15 ) ) ;
V_60 = V_18 & 0x0f ;
V_18 >>= 4 ;
if ( V_60 != V_21 && V_60 != V_22 && V_60 != V_23 ) {
F_2 ( V_10 L_5 ) ;
return - V_14 ;
}
F_11 ( & V_20 ) ;
if ( V_59 -> V_64 & V_65 )
V_63 = V_53 [ V_18 ] -> V_66 ;
else if ( V_59 -> V_64 & V_67 )
V_63 = V_53 [ V_18 ] -> V_68 ;
else {
F_2 ( V_10 L_6 ) ;
F_15 ( & V_20 ) ;
return - V_14 ;
}
if ( V_63 == NULL ) {
F_2 ( V_10 L_7 ) ;
F_15 ( & V_20 ) ;
return - V_69 ;
}
if ( V_63 -> V_70 == NULL ) {
F_2 ( V_10 L_8 ) ;
F_15 ( & V_20 ) ;
return - V_69 ;
}
if ( V_63 -> V_71 ) {
F_2 ( V_10 L_9 ) ;
F_15 ( & V_20 ) ;
return - V_69 ;
}
if ( V_59 -> V_72 != 0 ) {
F_2 ( V_10 L_10 ) ;
F_15 ( & V_20 ) ;
return - V_14 ;
}
V_61 = V_59 -> V_73 - V_59 -> V_74 ;
if ( V_61 != V_63 -> V_75 ) {
F_2 ( V_76 L_11 , V_61 , V_63 -> V_75 ) ;
}
if ( F_50 ( V_59 , V_59 -> V_74 ,
F_51 ( V_63 -> V_70 ) >> V_77 ,
V_59 -> V_73 - V_59 -> V_74 , V_59 -> V_78 ) ) {
F_15 ( & V_20 ) ;
return - V_79 ;
}
V_63 -> V_71 |= V_80 ;
if( V_53 [ V_18 ] -> V_81 -> V_82 )
V_53 [ V_18 ] -> V_81 -> V_82 ( V_18 ) ;
memset ( V_63 -> V_70 ,
V_63 -> V_83 ,
V_63 -> V_75 ) ;
F_15 ( & V_20 ) ;
return 0 ;
}
static int F_52 ( void )
{
int V_84 , V_85 ;
V_84 = F_53 ( & V_86 , 1 ) ;
if( V_84 == - 1 )
goto V_87;
V_85 = F_53 ( & V_86 , 8 ) ;
if( V_85 != - 1 )
return 0 ;
F_54 ( 1 ) ;
V_87:
return - 1 ;
}
static int T_9 F_55 ( void )
{
int V_88 ;
int V_4 , V_89 ;
#ifdef F_56
if( V_90 )
V_91 = V_90 ;
#endif
V_88 = F_52 () ;
if ( V_88 ) {
F_2 ( V_10 L_12 ) ;
return V_88 ;
}
V_92 = ( V_93 > 0 ? 1 : 0 ) ;
for ( V_4 = 0 ; V_4 < F_57 ( V_94 ) ; V_4 ++ ) {
V_89 = 0 ;
do {
unsigned short V_95 = V_94 [ V_4 ] . V_95 + V_89 * 0x10 ;
if ( ! F_53 ( & V_86 , V_95 ) )
V_94 [ V_4 ] . V_96 = ( 1 << V_89 ) ;
} while ( ++ V_89 < V_97 );
}
if ( V_98 >= V_99 - 1 )
F_2 ( V_10 L_13 ) ;
return 0 ;
}
static void T_10 F_58 ( void )
{
int V_4 , V_89 ;
for ( V_4 = 0 ; V_4 < F_57 ( V_94 ) ; V_4 ++ ) {
V_89 = 0 ;
do {
if ( V_94 [ V_4 ] . V_96 & ( 1 << V_89 ) )
F_54 ( V_94 [ V_4 ] . V_95 ) ;
} while ( ++ V_89 < V_97 );
}
F_54 ( 1 ) ;
F_54 ( 8 ) ;
F_59 () ;
F_60 () ;
for ( V_4 = 0 ; V_4 < V_100 ; V_4 ++ )
if ( V_101 [ V_4 ] != V_102 ) {
F_2 ( V_10 L_14 , V_4 ) ;
F_61 ( V_4 ) ;
}
for ( V_4 = 0 ; V_4 < V_98 ; V_4 ++ )
F_62 ( V_103 [ V_4 ] ) ;
}
int F_63 ( int V_104 , char * V_105 )
{
int V_88 ;
if ( ( V_88 = F_64 ( V_104 , V_105 ) ) != 0 )
return V_88 ;
V_101 [ V_104 ] = V_106 ;
return 0 ;
}
int F_65 ( int V_104 , char * V_105 )
{
if ( ! F_66 ( V_104 ) ) {
F_2 ( V_10 L_15 , V_104 ) ;
return 1 ;
}
if ( V_101 [ V_104 ] != V_106 ) {
F_2 ( L_16 , V_104 , V_101 [ V_104 ] ) ;
return 1 ;
}
V_101 [ V_104 ] = V_107 ;
return 0 ;
}
void F_61 ( int V_104 )
{
if ( V_101 [ V_104 ] == V_102 ) {
return;
}
F_67 ( V_104 ) ;
V_101 [ V_104 ] = V_102 ;
}
void F_68 ( int V_104 )
{
if ( V_101 [ V_104 ] != V_107 ) {
F_2 ( V_10 L_17 , V_104 ) ;
return;
}
V_101 [ V_104 ] = V_106 ;
}
static void F_69 ( unsigned long V_108 )
{
F_70 ( 0 ) ;
}
void F_71 ( int V_16 )
{
extern unsigned long V_109 ;
if ( V_16 < 0 ) {
V_110 . V_111 = ( - V_16 ) + V_112 ;
F_72 ( & V_110 ) ;
return;
}
V_16 += V_109 ;
V_16 -= V_112 ;
if ( V_16 < 1 )
V_16 = 1 ;
V_110 . V_111 = ( V_16 ) + V_112 ;
F_72 ( & V_110 ) ;
}
void F_59 ( void )
{
F_73 ( & V_110 ) ;
}
void F_74 ( char * V_1 , struct V_113 * V_114 )
{
#ifndef F_75
return;
#else
F_2 ( L_18 , V_1 , V_114 -> V_115 ) ;
if ( V_114 -> V_116 )
F_2 ( L_19 , ( V_114 -> V_116 > 0 ) ? V_114 -> V_116 : - V_114 -> V_116 ) ;
if ( V_114 -> V_117 != - 1 || V_114 -> V_118 != - 1 )
{
F_2 ( L_20 , V_114 -> V_117 ) ;
if ( V_114 -> V_118 != - 1 )
F_2 ( L_21 , V_114 -> V_118 ) ;
}
F_2 ( L_22 ) ;
#endif
}
void F_76 ( char * V_1 , int V_119 , int V_116 , int V_117 , int V_118 )
{
#ifndef F_75
return;
#else
F_2 ( L_18 , V_1 , V_119 ) ;
if ( V_116 )
F_2 ( L_19 , ( V_116 > 0 ) ? V_116 : - V_116 ) ;
if ( V_117 != - 1 || V_118 != - 1 )
{
F_2 ( L_20 , V_117 ) ;
if ( V_118 != - 1 )
F_2 ( L_21 , V_118 ) ;
}
F_2 ( L_22 ) ;
#endif
}
