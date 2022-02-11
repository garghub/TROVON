static int T_1
F_1 ( struct V_1 * V_1 , int V_2 ,
unsigned long V_3 ,
unsigned long V_4 )
{
unsigned long V_5 , V_6 ;
T_2 type ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
type = V_9 [ V_7 ] . type ;
if ( type != V_10 )
continue;
V_5 = V_9 [ V_7 ] . V_11 ;
V_6 = V_9 [ V_7 ] . V_12 ;
V_2 = F_2 ( V_1 , V_13 , V_2 ,
V_5 , V_5 + V_6 ) ;
}
if ( V_14 ) {
F_3 ( L_1 ) ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
F_3 ( L_2 ,
V_1 [ V_7 ] . V_15 , V_1 [ V_7 ] . V_16 ) ;
}
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
type = V_9 [ V_7 ] . type ;
if ( type != V_17 &&
type != V_18 )
continue;
V_6 = V_9 [ V_7 ] . V_12 ;
if ( ! V_6 )
continue;
V_5 = V_9 [ V_7 ] . V_11 ;
if ( V_5 < ( 1 << ( 20 - V_19 ) ) && V_20 . V_21 &&
( V_20 . V_22 & V_23 ) &&
( V_20 . V_22 & V_24 ) ) {
F_4 ( V_25 , V_7 ) ;
if ( V_5 + V_6 <= ( 1 << ( 20 - V_19 ) ) )
continue;
V_6 -= ( 1 << ( 20 - V_19 ) ) - V_5 ;
V_5 = 1 << ( 20 - V_19 ) ;
}
F_5 ( V_1 , V_13 , V_5 , V_5 + V_6 ) ;
}
if ( V_4 )
F_5 ( V_1 , V_13 , V_3 ,
V_3 + V_4 ) ;
if ( V_14 ) {
F_3 ( L_3 ) ;
for ( V_7 = 0 ; V_7 < V_13 ; V_7 ++ ) {
if ( ! V_1 [ V_7 ] . V_16 )
continue;
F_3 ( L_2 ,
V_1 [ V_7 ] . V_15 , V_1 [ V_7 ] . V_16 ) ;
}
}
V_2 = F_6 ( V_1 , V_13 ) ;
if ( V_14 ) {
F_3 ( L_4 ) ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
F_3 ( L_2 ,
V_1 [ V_7 ] . V_15 , V_1 [ V_7 ] . V_16 ) ;
}
return V_2 ;
}
static unsigned long T_1 F_7 ( struct V_1 * V_1 , int V_2 )
{
unsigned long V_26 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
V_26 += V_1 [ V_7 ] . V_16 - V_1 [ V_7 ] . V_15 ;
return V_26 ;
}
static int T_1 F_8 ( char * V_27 )
{
V_28 = 0 ;
return 0 ;
}
static int T_1 F_9 ( char * V_27 )
{
V_28 = 1 ;
return 0 ;
}
static int T_1 F_10 ( char * V_27 )
{
V_14 = 1 ;
return 0 ;
}
static void T_1
F_11 ( unsigned int V_29 , unsigned long V_30 , unsigned long V_31 ,
unsigned char type , unsigned int V_32 )
{
T_3 V_33 , V_34 , V_35 , V_36 ;
T_4 V_5 , V_37 ;
if ( ! V_31 ) {
F_12 ( V_29 , 0 , 0 , 0 , 0 ) ;
return;
}
V_37 = ( 1ULL << V_32 ) - 1 ;
V_37 &= ~ ( ( ( ( T_4 ) V_31 ) << 10 ) - 1 ) ;
V_5 = ( ( T_4 ) V_30 ) << 10 ;
V_5 |= type ;
V_37 |= 0x800 ;
V_33 = V_5 & ( ( 1ULL << 32 ) - 1 ) ;
V_34 = V_5 >> 32 ;
V_35 = V_37 & ( ( 1ULL << 32 ) - 1 ) ;
V_36 = V_37 >> 32 ;
F_12 ( V_29 , V_33 , V_34 , V_35 , V_36 ) ;
}
static void T_1
F_13 ( unsigned int V_29 , unsigned long V_30 , unsigned long V_31 ,
unsigned char type )
{
V_9 [ V_29 ] . V_11 = V_30 >> ( V_19 - 10 ) ;
V_9 [ V_29 ] . V_12 = V_31 >> ( V_19 - 10 ) ;
V_9 [ V_29 ] . type = type ;
}
static void T_1 F_14 ( unsigned int V_32 )
{
unsigned long V_30 , V_31 ;
unsigned char type ;
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_8 ; V_29 ++ ) {
V_30 = V_9 [ V_29 ] . V_11 << ( V_19 - 10 ) ;
V_31 = V_9 [ V_29 ] . V_12 << ( V_19 - 10 ) ;
type = V_9 [ V_29 ] . type ;
F_11 ( V_29 , V_30 , V_31 , type , V_32 ) ;
}
}
static unsigned long F_15 ( unsigned long V_31 , char * V_38 )
{
unsigned long V_5 = V_31 ;
char V_39 ;
if ( V_5 & ( ( 1 << 10 ) - 1 ) ) {
V_39 = 'K' ;
} else if ( V_5 & ( ( 1 << 20 ) - 1 ) ) {
V_39 = 'M' ;
V_5 >>= 10 ;
} else {
V_39 = 'G' ;
V_5 >>= 20 ;
}
* V_38 = V_39 ;
return V_5 ;
}
static unsigned int T_1
F_16 ( unsigned int V_29 , unsigned long V_40 ,
unsigned long V_41 , unsigned char type )
{
if ( ! V_41 || ( V_29 >= V_8 ) )
return V_29 ;
while ( V_41 ) {
unsigned long V_42 , V_43 ;
unsigned long V_31 ;
if ( V_40 )
V_42 = F_17 ( V_40 ) ;
else
V_42 = V_44 - 1 ;
V_43 = F_18 ( V_41 ) ;
if ( V_43 > V_42 )
V_43 = V_42 ;
V_31 = 1UL << V_43 ;
if ( V_14 ) {
char V_45 = 'K' , V_46 = 'K' ;
unsigned long V_47 , V_48 ;
V_47 = F_15 ( V_40 , & V_45 ) ;
V_48 = F_15 ( V_31 , & V_46 ) ;
F_19 ( L_5
L_6 ,
V_29 , V_47 , V_45 ,
V_48 , V_46 ,
( type == V_17 ) ? L_7 :
( ( type == V_10 ) ? L_8 : L_9 )
) ;
}
F_13 ( V_29 ++ , V_40 , V_31 , type ) ;
V_40 += V_31 ;
V_41 -= V_31 ;
if ( V_29 >= V_8 )
break;
}
return V_29 ;
}
static unsigned T_1
F_20 ( struct V_49 * V_50 , unsigned long V_30 ,
unsigned long V_31 )
{
unsigned long V_51 , V_52 ;
unsigned long V_53 , V_54 ;
unsigned long V_55 , V_56 ;
unsigned long V_57 , V_41 ;
unsigned long V_58 ;
unsigned long V_59 ;
V_51 = 0 ;
V_52 = 0 ;
V_53 = 0 ;
V_54 = 0 ;
V_58 = V_50 -> V_58 ;
V_59 = V_50 -> V_59 ;
V_57 = F_21 ( V_50 -> V_40 , V_59 ) ;
if ( ( V_57 > V_30 ) && V_30 )
return V_54 ;
V_50 -> V_41 -= ( V_57 - V_50 -> V_40 ) ;
V_41 = F_21 ( V_50 -> V_41 , V_59 ) ;
while ( V_41 > V_50 -> V_41 ) {
V_41 -= V_59 ;
if ( ! V_41 )
return 0 ;
}
V_50 -> V_41 = V_41 ;
V_55 = V_50 -> V_40 ;
V_56 = F_21 ( V_50 -> V_41 , V_58 ) ;
if ( V_56 == V_50 -> V_41 ) {
F_19 ( L_10 ,
V_55 << 10 ,
( V_55 + V_50 -> V_41 ) << 10 ) ;
V_50 -> V_29 = F_16 ( V_50 -> V_29 , V_55 ,
V_50 -> V_41 , V_10 ) ;
return 0 ;
}
if ( V_31 ) {
while ( V_55 + V_56 > ( V_30 + V_31 ) ) {
if ( V_56 >= V_58 )
V_56 -= V_58 ;
else
V_56 = 0 ;
if ( ! V_56 )
break;
}
}
V_60:
V_57 = V_55 + V_56 ;
if ( V_57 > V_30 && V_57 <= ( V_30 + V_31 ) )
V_54 = V_57 - V_30 ;
if ( V_56 > V_50 -> V_41 ) {
V_52 = V_56 - V_50 -> V_41 - V_54 ;
if ( V_52 >= ( V_56 >> 1 ) &&
V_56 >= V_58 ) {
V_56 -= V_58 ;
V_54 = 0 ;
V_52 = 0 ;
goto V_60;
}
}
if ( V_56 ) {
F_19 ( L_11 ,
V_55 << 10 ,
( V_55 + V_56 ) << 10 ) ;
V_50 -> V_29 = F_16 ( V_50 -> V_29 , V_55 ,
V_56 , V_10 ) ;
}
if ( V_56 < V_50 -> V_41 ) {
V_41 = V_50 -> V_41 - V_56 ;
F_19 ( L_12 ,
V_57 << 10 ,
( V_57 + V_41 ) << 10 ) ;
V_50 -> V_29 = F_16 ( V_50 -> V_29 , V_57 ,
V_41 , V_10 ) ;
}
if ( V_52 ) {
V_51 = V_57 - V_52 - V_54 ;
F_19 ( L_13 ,
V_51 << 10 ,
( V_51 + V_52 ) << 10 ) ;
V_50 -> V_29 = F_16 ( V_50 -> V_29 , V_51 ,
V_52 , V_17 ) ;
}
return V_54 ;
}
static void T_1
F_22 ( struct V_49 * V_50 , unsigned long V_11 ,
unsigned long V_12 )
{
unsigned long V_30 , V_31 ;
unsigned long V_54 = 0 ;
if ( V_50 -> V_29 >= V_8 )
return;
V_30 = V_11 << ( V_19 - 10 ) ;
V_31 = V_12 << ( V_19 - 10 ) ;
if ( ( V_30 <= 1024 ) ||
( V_50 -> V_40 + V_50 -> V_41 == V_30 ) ) {
unsigned long V_61 = V_30 + V_31 ;
V_50 -> V_41 = V_61 - V_50 -> V_40 ;
return;
}
if ( V_50 -> V_41 != 0 )
V_54 = F_20 ( V_50 , V_30 , V_31 ) ;
V_50 -> V_40 = V_30 + V_54 ;
V_50 -> V_41 = V_31 - V_54 ;
}
static int T_1 F_23 ( char * V_62 )
{
if ( ! V_62 )
return - V_63 ;
V_64 = F_24 ( V_62 , & V_62 ) ;
return 0 ;
}
static int T_1 F_25 ( char * V_62 )
{
if ( ! V_62 )
return - V_63 ;
V_65 = F_24 ( V_62 , & V_62 ) ;
return 0 ;
}
static int T_1 F_26 ( char * V_66 )
{
if ( V_66 )
V_67 = F_27 ( V_66 , NULL , 0 ) ;
return 0 ;
}
static int T_1
F_28 ( struct V_1 * V_1 , int V_2 ,
T_4 V_68 , T_4 V_69 )
{
struct V_49 V_70 ;
int V_71 ;
int V_7 ;
V_70 . V_40 = 0 ;
V_70 . V_41 = 0 ;
V_70 . V_29 = 0 ;
V_70 . V_58 = V_68 >> 10 ;
V_70 . V_59 = V_69 >> 10 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) {
F_22 ( & V_70 , V_1 [ V_7 ] . V_15 ,
V_1 [ V_7 ] . V_16 - V_1 [ V_7 ] . V_15 ) ;
}
if ( V_70 . V_41 != 0 )
F_20 ( & V_70 , 0 , 0 ) ;
V_71 = V_70 . V_29 ;
while ( V_70 . V_29 < V_8 ) {
F_13 ( V_70 . V_29 , 0 , 0 , 0 ) ;
V_70 . V_29 ++ ;
}
return V_71 ;
}
static void T_1 F_29 ( void )
{
char V_45 = 'K' , V_46 = 'K' ;
unsigned long V_47 , V_48 ;
T_2 type ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_48 = V_9 [ V_7 ] . V_12 << ( V_19 - 10 ) ;
if ( ! V_48 )
continue;
V_48 = F_15 ( V_48 , & V_46 ) ,
V_47 = V_9 [ V_7 ] . V_11 << ( V_19 - 10 ) ;
V_47 = F_15 ( V_47 , & V_45 ) ,
type = V_9 [ V_7 ] . type ;
F_3 ( L_14 ,
V_7 , V_47 , V_45 ,
V_48 , V_46 ,
( type == V_17 ) ? L_7 :
( ( type == V_18 ) ? L_15 :
( ( type == V_10 ) ? L_8 : L_9 ) )
) ;
}
}
static int T_1 F_30 ( void )
{
int V_7 ;
T_2 type ;
unsigned long V_6 ;
int V_72 [ V_73 + 1 ] ;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
type = V_9 [ V_7 ] . type ;
V_6 = V_9 [ V_7 ] . V_12 ;
if ( type >= V_73 )
continue;
if ( ! V_6 )
type = V_73 ;
V_72 [ type ] ++ ;
}
if ( ! V_72 [ V_17 ] )
return 0 ;
if ( V_72 [ V_10 ] + V_72 [ V_17 ] !=
V_8 - V_72 [ V_73 ] )
return 0 ;
return 1 ;
}
static void T_1
F_31 ( T_4 V_68 , T_4 V_69 ,
unsigned long V_74 ,
unsigned long V_75 , int V_7 )
{
static struct V_1 V_76 [ V_13 ] V_77 ;
unsigned long V_78 ;
int V_79 ;
int V_71 ;
V_71 = F_28 ( V_1 , V_2 , V_68 , V_69 ) ;
memset ( V_76 , 0 , sizeof( V_76 ) ) ;
V_79 = F_1 ( V_76 , 0 ,
V_74 , V_75 ) ;
V_78 = F_7 ( V_76 , V_79 ) ;
V_80 [ V_7 ] . V_58 = V_68 >> 10 ;
V_80 [ V_7 ] . V_59 = V_69 >> 10 ;
V_80 [ V_7 ] . V_71 = V_71 ;
if ( V_81 < V_78 ) {
V_80 [ V_7 ] . V_82 = ( V_78 - V_81 ) << V_83 ;
V_80 [ V_7 ] . V_84 = 1 ;
} else {
V_80 [ V_7 ] . V_82 = ( V_81 - V_78 ) << V_83 ;
}
if ( ! V_80 [ V_7 ] . V_84 && ! V_80 [ V_7 ] . V_82 ) {
if ( V_79 != V_2 || memcmp ( V_1 , V_76 , sizeof( V_1 ) ) )
V_80 [ V_7 ] . V_84 = 1 ;
}
if ( ! V_80 [ V_7 ] . V_84 && ( V_81 - V_78 < V_85 [ V_71 ] ) )
V_85 [ V_71 ] = V_81 - V_78 ;
}
static void T_1 F_32 ( int V_7 )
{
unsigned long V_86 , V_87 , V_88 ;
char V_89 , V_90 , V_91 ;
V_86 = F_15 ( V_80 [ V_7 ] . V_59 , & V_89 ) ;
V_87 = F_15 ( V_80 [ V_7 ] . V_58 , & V_90 ) ;
V_88 = F_15 ( V_80 [ V_7 ] . V_82 , & V_91 ) ;
F_33 ( L_16 ,
V_80 [ V_7 ] . V_84 ? L_17 : L_18 ,
V_86 , V_89 , V_87 , V_90 ) ;
F_34 ( L_19 ,
V_80 [ V_7 ] . V_71 , V_80 [ V_7 ] . V_84 ? L_20 : L_21 ,
V_88 , V_91 ) ;
}
static int T_1 F_35 ( void )
{
int V_92 ;
int V_93 ;
int V_7 ;
if ( V_67 >= V_8 )
V_67 = V_8 - 1 ;
V_92 = - 1 ;
for ( V_7 = V_8 - V_67 ; V_7 > 0 ; V_7 -- ) {
if ( ! V_85 [ V_7 ] )
V_92 = V_7 ;
}
V_93 = - 1 ;
if ( V_92 != - 1 ) {
for ( V_7 = 0 ; V_7 < V_94 ; V_7 ++ ) {
if ( ! V_80 [ V_7 ] . V_84 &&
V_80 [ V_7 ] . V_71 == V_92 &&
! V_80 [ V_7 ] . V_82 ) {
V_93 = V_7 ;
break;
}
}
}
return V_93 ;
}
int T_1 F_36 ( unsigned V_32 )
{
unsigned long V_74 , V_75 ;
unsigned long V_5 , V_6 , V_95 , V_96 ;
T_4 V_68 , V_69 ;
T_2 type ;
int V_93 ;
int V_7 ;
if ( ! F_37 ( V_97 ) || V_28 < 1 )
return 0 ;
F_38 ( V_98 , V_95 , V_96 ) ;
V_95 &= 0xff ;
if ( V_95 != V_17 )
return 0 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_99 -> V_100 ( V_7 , & V_5 , & V_6 , & type ) ;
V_9 [ V_7 ] . V_11 = V_5 ;
V_9 [ V_7 ] . V_12 = V_6 ;
V_9 [ V_7 ] . type = type ;
}
if ( ! F_30 () )
return 0 ;
F_3 ( L_22 ) ;
F_29 () ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
V_75 = 0 ;
V_74 = 1 << ( 32 - V_19 ) ;
if ( V_101 )
V_75 = ( V_101 >> V_19 ) - V_74 ;
V_2 = F_2 ( V_1 , V_13 , 0 , 0 ,
1ULL << ( 20 - V_19 ) ) ;
V_2 = F_1 ( V_1 , V_2 ,
V_74 , V_75 ) ;
V_81 = F_7 ( V_1 , V_2 ) ;
F_33 ( L_23 ,
V_81 >> ( 20 - V_19 ) ) ;
if ( V_64 && V_65 ) {
V_7 = 0 ;
F_31 ( V_64 , V_65 ,
V_74 , V_75 , V_7 ) ;
F_32 ( V_7 ) ;
if ( ! V_80 [ V_7 ] . V_84 ) {
F_14 ( V_32 ) ;
F_3 ( L_24 ) ;
F_29 () ;
return 1 ;
}
F_33 ( L_25 ) ;
}
V_7 = 0 ;
memset ( V_85 , 0xff , sizeof( V_85 ) ) ;
memset ( V_80 , 0 , sizeof( V_80 ) ) ;
for ( V_69 = ( 1ULL << 16 ) ; V_69 < ( 1ULL << 32 ) ; V_69 <<= 1 ) {
for ( V_68 = V_69 ; V_68 < ( 1ULL << 32 ) ;
V_68 <<= 1 ) {
if ( V_7 >= V_94 )
continue;
F_31 ( V_68 , V_69 ,
V_74 , V_75 , V_7 ) ;
if ( V_14 ) {
F_32 ( V_7 ) ;
F_33 ( L_26 ) ;
}
V_7 ++ ;
}
}
V_93 = F_35 () ;
if ( V_93 != - 1 ) {
F_33 ( L_27 ) ;
V_7 = V_93 ;
F_32 ( V_7 ) ;
V_68 = V_80 [ V_7 ] . V_58 ;
V_68 <<= 10 ;
V_69 = V_80 [ V_7 ] . V_59 ;
V_69 <<= 10 ;
F_28 ( V_1 , V_2 , V_68 , V_69 ) ;
F_14 ( V_32 ) ;
F_3 ( L_24 ) ;
F_29 () ;
return 1 ;
} else {
for ( V_7 = 0 ; V_7 < V_94 ; V_7 ++ )
F_32 ( V_7 ) ;
}
F_33 ( L_28 ) ;
F_33 ( L_29 ) ;
return 0 ;
}
int T_1 F_36 ( unsigned V_32 )
{
return 0 ;
}
static int T_1 F_39 ( char * V_27 )
{
V_102 = 1 ;
return 0 ;
}
int T_1 F_40 ( void )
{
T_3 V_103 , V_104 ;
if ( V_105 . V_106 != V_107 )
return 0 ;
if ( V_105 . V_108 < 0xf )
return 0 ;
if ( F_41 ( V_109 , & V_103 , & V_104 ) < 0 )
return 0 ;
if ( ( V_103 & ( V_110 | V_111 ) ) ==
( V_110 | V_111 ) )
return 1 ;
return 0 ;
}
static T_4 T_1
F_42 ( unsigned long V_112 , unsigned long V_113 )
{
T_4 V_114 , V_115 ;
V_114 = V_112 ;
V_114 <<= V_19 ;
V_115 = V_113 ;
V_115 <<= V_19 ;
V_115 -= V_114 ;
return F_43 ( V_114 , V_115 , V_116 , V_117 ) ;
}
int T_1 F_44 ( unsigned long V_118 )
{
unsigned long V_7 , V_5 , V_6 , V_119 = 0 , V_95 , V_96 ;
T_2 type ;
T_4 V_120 ;
int V_72 [ V_73 + 1 ] ;
if ( ! F_37 ( V_97 ) || V_102 )
return 0 ;
F_38 ( V_98 , V_95 , V_96 ) ;
V_95 &= 0xff ;
if ( V_95 != V_17 )
return 0 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_99 -> V_100 ( V_7 , & V_5 , & V_6 , & type ) ;
V_9 [ V_7 ] . V_11 = V_5 ;
V_9 [ V_7 ] . V_12 = V_6 ;
V_9 [ V_7 ] . type = type ;
}
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
type = V_9 [ V_7 ] . type ;
if ( type != V_10 )
continue;
V_5 = V_9 [ V_7 ] . V_11 ;
V_6 = V_9 [ V_7 ] . V_12 ;
if ( V_119 < V_5 + V_6 )
V_119 = V_5 + V_6 ;
}
if ( ! V_119 ) {
F_33 ( L_30 ) ;
return 0 ;
}
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
type = V_9 [ V_7 ] . type ;
if ( type >= V_73 )
continue;
V_6 = V_9 [ V_7 ] . V_12 ;
if ( ! V_6 )
type = V_73 ;
V_72 [ type ] ++ ;
}
if ( ! V_72 [ V_10 ] )
return 0 ;
if ( V_72 [ V_10 ] + V_72 [ V_17 ] !=
V_8 - V_72 [ V_73 ] )
return 0 ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
V_2 = 0 ;
if ( V_101 ) {
V_1 [ V_2 ] . V_15 = ( 1ULL << ( 32 - V_19 ) ) ;
V_1 [ V_2 ] . V_16 = V_101 >> V_19 ;
if ( V_119 < V_1 [ V_2 ] . V_16 )
V_119 = V_1 [ V_2 ] . V_16 ;
V_2 ++ ;
}
V_2 = F_1 ( V_1 , V_2 , 0 , 0 ) ;
V_120 = 0 ;
if ( V_1 [ 0 ] . V_15 )
V_120 += F_42 ( 0 , V_1 [ 0 ] . V_15 ) ;
for ( V_7 = 0 ; V_7 < V_2 - 1 ; V_7 ++ ) {
if ( V_1 [ V_7 ] . V_16 < V_1 [ V_7 + 1 ] . V_15 )
V_120 += F_42 ( V_1 [ V_7 ] . V_16 ,
V_1 [ V_7 + 1 ] . V_15 ) ;
}
V_7 = V_2 - 1 ;
if ( V_1 [ V_7 ] . V_16 < V_118 )
V_120 += F_42 ( V_1 [ V_7 ] . V_16 ,
V_118 ) ;
if ( V_120 ) {
F_4 ( L_31 ,
V_120 >> 20 ) ;
if ( ! V_121 )
F_45 ( 1 ) ;
F_33 ( L_32 ) ;
F_46 () ;
return 1 ;
}
return 0 ;
}
