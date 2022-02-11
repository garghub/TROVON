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
F_3 ( V_15 L_1 ) ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
F_3 ( V_15 L_2 ,
V_1 [ V_7 ] . V_16 , V_1 [ V_7 ] . V_17 ) ;
}
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
type = V_9 [ V_7 ] . type ;
if ( type != V_18 &&
type != V_19 )
continue;
V_6 = V_9 [ V_7 ] . V_12 ;
if ( ! V_6 )
continue;
V_5 = V_9 [ V_7 ] . V_11 ;
if ( V_5 < ( 1 << ( 20 - V_20 ) ) && V_21 . V_22 &&
( V_21 . V_23 & V_24 ) &&
( V_21 . V_23 & V_25 ) ) {
F_3 ( V_26 , V_7 ) ;
if ( V_5 + V_6 <= ( 1 << ( 20 - V_20 ) ) )
continue;
V_6 -= ( 1 << ( 20 - V_20 ) ) - V_5 ;
V_5 = 1 << ( 20 - V_20 ) ;
}
F_4 ( V_1 , V_13 , V_5 , V_5 + V_6 ) ;
}
if ( V_4 )
F_4 ( V_1 , V_13 , V_3 ,
V_3 + V_4 ) ;
if ( V_14 ) {
F_3 ( V_15 L_3 ) ;
for ( V_7 = 0 ; V_7 < V_13 ; V_7 ++ ) {
if ( ! V_1 [ V_7 ] . V_17 )
continue;
F_3 ( V_15 L_2 ,
V_1 [ V_7 ] . V_16 , V_1 [ V_7 ] . V_17 ) ;
}
}
V_2 = F_5 ( V_1 , V_13 ) ;
if ( V_14 ) {
F_3 ( V_15 L_4 ) ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
F_3 ( V_15 L_2 ,
V_1 [ V_7 ] . V_16 , V_1 [ V_7 ] . V_17 ) ;
}
return V_2 ;
}
static unsigned long T_1 F_6 ( struct V_1 * V_1 , int V_2 )
{
unsigned long V_27 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
V_27 += V_1 [ V_7 ] . V_17 - V_1 [ V_7 ] . V_16 ;
return V_27 ;
}
static int T_1 F_7 ( char * V_28 )
{
V_29 = 0 ;
return 0 ;
}
static int T_1 F_8 ( char * V_28 )
{
V_29 = 1 ;
return 0 ;
}
static int T_1 F_9 ( char * V_28 )
{
V_14 = 1 ;
return 0 ;
}
static void T_1
F_10 ( unsigned int V_30 , unsigned long V_31 , unsigned long V_32 ,
unsigned char type , unsigned int V_33 )
{
T_3 V_34 , V_35 , V_36 , V_37 ;
T_4 V_5 , V_38 ;
if ( ! V_32 ) {
F_11 ( V_30 , 0 , 0 , 0 , 0 ) ;
return;
}
V_38 = ( 1ULL << V_33 ) - 1 ;
V_38 &= ~ ( ( ( ( T_4 ) V_32 ) << 10 ) - 1 ) ;
V_5 = ( ( T_4 ) V_31 ) << 10 ;
V_5 |= type ;
V_38 |= 0x800 ;
V_34 = V_5 & ( ( 1ULL << 32 ) - 1 ) ;
V_35 = V_5 >> 32 ;
V_36 = V_38 & ( ( 1ULL << 32 ) - 1 ) ;
V_37 = V_38 >> 32 ;
F_11 ( V_30 , V_34 , V_35 , V_36 , V_37 ) ;
}
static void T_1
F_12 ( unsigned int V_30 , unsigned long V_31 , unsigned long V_32 ,
unsigned char type )
{
V_9 [ V_30 ] . V_11 = V_31 >> ( V_20 - 10 ) ;
V_9 [ V_30 ] . V_12 = V_32 >> ( V_20 - 10 ) ;
V_9 [ V_30 ] . type = type ;
}
static void T_1 F_13 ( unsigned int V_33 )
{
unsigned long V_31 , V_32 ;
unsigned char type ;
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < V_8 ; V_30 ++ ) {
V_31 = V_9 [ V_30 ] . V_11 << ( V_20 - 10 ) ;
V_32 = V_9 [ V_30 ] . V_12 << ( V_20 - 10 ) ;
type = V_9 [ V_30 ] . type ;
F_10 ( V_30 , V_31 , V_32 , type , V_33 ) ;
}
}
static unsigned long F_14 ( unsigned long V_32 , char * V_39 )
{
unsigned long V_5 = V_32 ;
char V_40 ;
if ( V_5 & ( ( 1 << 10 ) - 1 ) ) {
V_40 = 'K' ;
} else if ( V_5 & ( ( 1 << 20 ) - 1 ) ) {
V_40 = 'M' ;
V_5 >>= 10 ;
} else {
V_40 = 'G' ;
V_5 >>= 20 ;
}
* V_39 = V_40 ;
return V_5 ;
}
static unsigned int T_1
F_15 ( unsigned int V_30 , unsigned long V_41 ,
unsigned long V_42 , unsigned char type )
{
if ( ! V_42 || ( V_30 >= V_8 ) )
return V_30 ;
while ( V_42 ) {
unsigned long V_43 , V_44 ;
unsigned long V_32 ;
if ( V_41 )
V_43 = F_16 ( V_41 ) ;
else
V_43 = V_45 - 1 ;
V_44 = F_17 ( V_42 ) ;
if ( V_44 > V_43 )
V_44 = V_43 ;
V_32 = 1UL << V_44 ;
if ( V_14 ) {
char V_46 = 'K' , V_47 = 'K' ;
unsigned long V_48 , V_49 ;
V_48 = F_14 ( V_41 , & V_46 ) ;
V_49 = F_14 ( V_32 , & V_47 ) ;
F_18 ( L_5
L_6 ,
V_30 , V_48 , V_46 ,
V_49 , V_47 ,
( type == V_18 ) ? L_7 :
( ( type == V_10 ) ? L_8 : L_9 )
) ;
}
F_12 ( V_30 ++ , V_41 , V_32 , type ) ;
V_41 += V_32 ;
V_42 -= V_32 ;
if ( V_30 >= V_8 )
break;
}
return V_30 ;
}
static unsigned T_1
F_19 ( struct V_50 * V_51 , unsigned long V_31 ,
unsigned long V_32 )
{
unsigned long V_52 , V_53 ;
unsigned long V_54 , V_55 ;
unsigned long V_56 , V_57 ;
unsigned long V_58 , V_42 ;
unsigned long V_59 ;
unsigned long V_60 ;
V_52 = 0 ;
V_53 = 0 ;
V_54 = 0 ;
V_55 = 0 ;
V_59 = V_51 -> V_59 ;
V_60 = V_51 -> V_60 ;
V_58 = F_20 ( V_51 -> V_41 , V_60 ) ;
if ( ( V_58 > V_31 ) && V_31 )
return V_55 ;
V_51 -> V_42 -= ( V_58 - V_51 -> V_41 ) ;
V_42 = F_20 ( V_51 -> V_42 , V_60 ) ;
while ( V_42 > V_51 -> V_42 ) {
V_42 -= V_60 ;
if ( ! V_42 )
return 0 ;
}
V_51 -> V_42 = V_42 ;
V_56 = V_51 -> V_41 ;
V_57 = F_20 ( V_51 -> V_42 , V_59 ) ;
if ( V_57 == V_51 -> V_42 ) {
F_18 ( L_10 ,
V_56 << 10 ,
( V_56 + V_51 -> V_42 ) << 10 ) ;
V_51 -> V_30 = F_15 ( V_51 -> V_30 , V_56 ,
V_51 -> V_42 , V_10 ) ;
return 0 ;
}
if ( V_32 ) {
while ( V_56 + V_57 > ( V_31 + V_32 ) ) {
if ( V_57 >= V_59 )
V_57 -= V_59 ;
else
V_57 = 0 ;
if ( ! V_57 )
break;
}
}
V_61:
V_58 = V_56 + V_57 ;
if ( V_58 > V_31 && V_58 <= ( V_31 + V_32 ) )
V_55 = V_58 - V_31 ;
if ( V_57 > V_51 -> V_42 ) {
V_53 = V_57 - V_51 -> V_42 - V_55 ;
if ( V_53 >= ( V_57 >> 1 ) &&
V_57 >= V_59 ) {
V_57 -= V_59 ;
V_55 = 0 ;
V_53 = 0 ;
goto V_61;
}
}
if ( V_57 ) {
F_18 ( L_11 ,
V_56 << 10 ,
( V_56 + V_57 ) << 10 ) ;
V_51 -> V_30 = F_15 ( V_51 -> V_30 , V_56 ,
V_57 , V_10 ) ;
}
if ( V_57 < V_51 -> V_42 ) {
V_42 = V_51 -> V_42 - V_57 ;
F_18 ( L_12 ,
V_58 << 10 ,
( V_58 + V_42 ) << 10 ) ;
V_51 -> V_30 = F_15 ( V_51 -> V_30 , V_58 ,
V_42 , V_10 ) ;
}
if ( V_53 ) {
V_52 = V_58 - V_53 - V_55 ;
F_18 ( L_13 ,
V_52 << 10 ,
( V_52 + V_53 ) << 10 ) ;
V_51 -> V_30 = F_15 ( V_51 -> V_30 , V_52 ,
V_53 , V_18 ) ;
}
return V_55 ;
}
static void T_1
F_21 ( struct V_50 * V_51 , unsigned long V_11 ,
unsigned long V_12 )
{
unsigned long V_31 , V_32 ;
unsigned long V_55 = 0 ;
if ( V_51 -> V_30 >= V_8 )
return;
V_31 = V_11 << ( V_20 - 10 ) ;
V_32 = V_12 << ( V_20 - 10 ) ;
if ( ( V_31 <= 1024 ) ||
( V_51 -> V_41 + V_51 -> V_42 == V_31 ) ) {
unsigned long V_62 = V_31 + V_32 ;
V_51 -> V_42 = V_62 - V_51 -> V_41 ;
return;
}
if ( V_51 -> V_42 != 0 )
V_55 = F_19 ( V_51 , V_31 , V_32 ) ;
V_51 -> V_41 = V_31 + V_55 ;
V_51 -> V_42 = V_32 - V_55 ;
}
static int T_1 F_22 ( char * V_63 )
{
if ( ! V_63 )
return - V_64 ;
V_65 = F_23 ( V_63 , & V_63 ) ;
return 0 ;
}
static int T_1 F_24 ( char * V_63 )
{
if ( ! V_63 )
return - V_64 ;
V_66 = F_23 ( V_63 , & V_63 ) ;
return 0 ;
}
static int T_1 F_25 ( char * V_67 )
{
if ( V_67 )
V_68 = F_26 ( V_67 , NULL , 0 ) ;
return 0 ;
}
static int T_1
F_27 ( struct V_1 * V_1 , int V_2 ,
T_4 V_69 , T_4 V_70 )
{
struct V_50 V_71 ;
int V_72 ;
int V_7 ;
V_71 . V_41 = 0 ;
V_71 . V_42 = 0 ;
V_71 . V_30 = 0 ;
V_71 . V_59 = V_69 >> 10 ;
V_71 . V_60 = V_70 >> 10 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) {
F_21 ( & V_71 , V_1 [ V_7 ] . V_16 ,
V_1 [ V_7 ] . V_17 - V_1 [ V_7 ] . V_16 ) ;
}
if ( V_71 . V_42 != 0 )
F_19 ( & V_71 , 0 , 0 ) ;
V_72 = V_71 . V_30 ;
while ( V_71 . V_30 < V_8 ) {
F_12 ( V_71 . V_30 , 0 , 0 , 0 ) ;
V_71 . V_30 ++ ;
}
return V_72 ;
}
static void T_1 F_28 ( void )
{
char V_46 = 'K' , V_47 = 'K' ;
unsigned long V_48 , V_49 ;
T_2 type ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_49 = V_9 [ V_7 ] . V_12 << ( V_20 - 10 ) ;
if ( ! V_49 )
continue;
V_49 = F_14 ( V_49 , & V_47 ) ,
V_48 = V_9 [ V_7 ] . V_11 << ( V_20 - 10 ) ;
V_48 = F_14 ( V_48 , & V_46 ) ,
type = V_9 [ V_7 ] . type ;
F_3 ( V_15 L_14 ,
V_7 , V_48 , V_46 ,
V_49 , V_47 ,
( type == V_18 ) ? L_7 :
( ( type == V_19 ) ? L_15 :
( ( type == V_10 ) ? L_8 : L_9 ) )
) ;
}
}
static int T_1 F_29 ( void )
{
int V_7 ;
T_2 type ;
unsigned long V_6 ;
int V_73 [ V_74 + 1 ] ;
memset ( V_73 , 0 , sizeof( V_73 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
type = V_9 [ V_7 ] . type ;
V_6 = V_9 [ V_7 ] . V_12 ;
if ( type >= V_74 )
continue;
if ( ! V_6 )
type = V_74 ;
V_73 [ type ] ++ ;
}
if ( ! V_73 [ V_18 ] )
return 0 ;
if ( V_73 [ V_10 ] + V_73 [ V_18 ] !=
V_8 - V_73 [ V_74 ] )
return 0 ;
return 1 ;
}
static void T_1
F_30 ( T_4 V_69 , T_4 V_70 ,
unsigned long V_75 ,
unsigned long V_76 , int V_7 )
{
static struct V_1 V_77 [ V_13 ] V_78 ;
unsigned long V_79 ;
int V_80 ;
int V_72 ;
V_72 = F_27 ( V_1 , V_2 , V_69 , V_70 ) ;
memset ( V_77 , 0 , sizeof( V_77 ) ) ;
V_80 = F_1 ( V_77 , 0 ,
V_75 , V_76 ) ;
V_79 = F_6 ( V_77 , V_80 ) ;
V_81 [ V_7 ] . V_59 = V_69 >> 10 ;
V_81 [ V_7 ] . V_60 = V_70 >> 10 ;
V_81 [ V_7 ] . V_72 = V_72 ;
if ( V_82 < V_79 ) {
V_81 [ V_7 ] . V_83 = ( V_79 - V_82 ) << V_84 ;
V_81 [ V_7 ] . V_85 = 1 ;
} else {
V_81 [ V_7 ] . V_83 = ( V_82 - V_79 ) << V_84 ;
}
if ( ! V_81 [ V_7 ] . V_85 && ! V_81 [ V_7 ] . V_83 ) {
if ( V_80 != V_2 || memcmp ( V_1 , V_77 , sizeof( V_1 ) ) )
V_81 [ V_7 ] . V_85 = 1 ;
}
if ( ! V_81 [ V_7 ] . V_85 && ( V_82 - V_79 < V_86 [ V_72 ] ) )
V_86 [ V_72 ] = V_82 - V_79 ;
}
static void T_1 F_31 ( int V_7 )
{
unsigned long V_87 , V_88 , V_89 ;
char V_90 , V_91 , V_92 ;
V_87 = F_14 ( V_81 [ V_7 ] . V_60 , & V_90 ) ;
V_88 = F_14 ( V_81 [ V_7 ] . V_59 , & V_91 ) ;
V_89 = F_14 ( V_81 [ V_7 ] . V_83 , & V_92 ) ;
F_32 ( L_16 ,
V_81 [ V_7 ] . V_85 ? L_17 : L_18 ,
V_87 , V_90 , V_88 , V_91 ) ;
F_33 ( L_19 ,
V_81 [ V_7 ] . V_72 , V_81 [ V_7 ] . V_85 ? L_20 : L_21 ,
V_89 , V_92 ) ;
}
static int T_1 F_34 ( void )
{
int V_93 ;
int V_94 ;
int V_7 ;
if ( V_68 >= V_8 )
V_68 = V_8 - 1 ;
V_93 = - 1 ;
for ( V_7 = V_8 - V_68 ; V_7 > 0 ; V_7 -- ) {
if ( ! V_86 [ V_7 ] )
V_93 = V_7 ;
}
V_94 = - 1 ;
if ( V_93 != - 1 ) {
for ( V_7 = 0 ; V_7 < V_95 ; V_7 ++ ) {
if ( ! V_81 [ V_7 ] . V_85 &&
V_81 [ V_7 ] . V_72 == V_93 &&
! V_81 [ V_7 ] . V_83 ) {
V_94 = V_7 ;
break;
}
}
}
return V_94 ;
}
int T_1 F_35 ( unsigned V_33 )
{
unsigned long V_75 , V_76 ;
unsigned long V_5 , V_6 , V_96 , V_97 ;
T_4 V_69 , V_70 ;
T_2 type ;
int V_94 ;
int V_7 ;
if ( ! F_36 ( V_98 ) || V_29 < 1 )
return 0 ;
F_37 ( V_99 , V_96 , V_97 ) ;
V_96 &= 0xff ;
if ( V_96 != V_18 )
return 0 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_100 -> V_101 ( V_7 , & V_5 , & V_6 , & type ) ;
V_9 [ V_7 ] . V_11 = V_5 ;
V_9 [ V_7 ] . V_12 = V_6 ;
V_9 [ V_7 ] . type = type ;
}
if ( ! F_29 () )
return 0 ;
F_3 ( V_15 L_22 ) ;
F_28 () ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
V_76 = 0 ;
V_75 = 1 << ( 32 - V_20 ) ;
if ( V_102 )
V_76 = ( V_102 >> V_20 ) - V_75 ;
V_2 = F_2 ( V_1 , V_13 , 0 , 0 ,
1ULL << ( 20 - V_20 ) ) ;
V_2 = F_1 ( V_1 , V_2 ,
V_75 , V_76 ) ;
V_82 = F_6 ( V_1 , V_2 ) ;
F_3 ( V_103 L_23 ,
V_82 >> ( 20 - V_20 ) ) ;
if ( V_65 && V_66 ) {
V_7 = 0 ;
F_30 ( V_65 , V_66 ,
V_75 , V_76 , V_7 ) ;
F_31 ( V_7 ) ;
if ( ! V_81 [ V_7 ] . V_85 ) {
F_13 ( V_33 ) ;
F_3 ( V_15 L_24 ) ;
F_28 () ;
return 1 ;
}
F_3 ( V_103 L_25
L_26 ) ;
}
V_7 = 0 ;
memset ( V_86 , 0xff , sizeof( V_86 ) ) ;
memset ( V_81 , 0 , sizeof( V_81 ) ) ;
for ( V_70 = ( 1ULL << 16 ) ; V_70 < ( 1ULL << 32 ) ; V_70 <<= 1 ) {
for ( V_69 = V_70 ; V_69 < ( 1ULL << 32 ) ;
V_69 <<= 1 ) {
if ( V_7 >= V_95 )
continue;
F_30 ( V_69 , V_70 ,
V_75 , V_76 , V_7 ) ;
if ( V_14 ) {
F_31 ( V_7 ) ;
F_3 ( V_103 L_27 ) ;
}
V_7 ++ ;
}
}
V_94 = F_34 () ;
if ( V_94 != - 1 ) {
F_3 ( V_103 L_28 ) ;
V_7 = V_94 ;
F_31 ( V_7 ) ;
V_69 = V_81 [ V_7 ] . V_59 ;
V_69 <<= 10 ;
V_70 = V_81 [ V_7 ] . V_60 ;
V_70 <<= 10 ;
F_27 ( V_1 , V_2 , V_69 , V_70 ) ;
F_13 ( V_33 ) ;
F_3 ( V_15 L_24 ) ;
F_28 () ;
return 1 ;
} else {
for ( V_7 = 0 ; V_7 < V_95 ; V_7 ++ )
F_31 ( V_7 ) ;
}
F_3 ( V_103 L_29 ) ;
F_3 ( V_103 L_30 ) ;
return 0 ;
}
int T_1 F_35 ( unsigned V_33 )
{
return 0 ;
}
static int T_1 F_38 ( char * V_28 )
{
V_104 = 1 ;
return 0 ;
}
int T_1 F_39 ( void )
{
T_3 V_105 , V_106 ;
if ( V_107 . V_108 != V_109 )
return 0 ;
if ( V_107 . V_110 < 0xf )
return 0 ;
if ( F_40 ( V_111 , & V_105 , & V_106 ) < 0 )
return 0 ;
if ( ( V_105 & ( V_112 | V_113 ) ) ==
( V_112 | V_113 ) )
return 1 ;
return 0 ;
}
static T_4 T_1
F_41 ( unsigned long V_114 , unsigned long V_115 )
{
T_4 V_116 , V_117 ;
V_116 = V_114 ;
V_116 <<= V_20 ;
V_117 = V_115 ;
V_117 <<= V_20 ;
V_117 -= V_116 ;
return F_42 ( V_116 , V_117 , V_118 , V_119 ) ;
}
int T_1 F_43 ( unsigned long V_120 )
{
unsigned long V_7 , V_5 , V_6 , V_121 = 0 , V_96 , V_97 ;
T_2 type ;
T_4 V_122 ;
int V_73 [ V_74 + 1 ] ;
if ( ! F_36 ( V_98 ) || V_104 )
return 0 ;
F_37 ( V_99 , V_96 , V_97 ) ;
V_96 &= 0xff ;
if ( V_96 != V_18 )
return 0 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_100 -> V_101 ( V_7 , & V_5 , & V_6 , & type ) ;
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
if ( V_121 < V_5 + V_6 )
V_121 = V_5 + V_6 ;
}
if ( ! V_121 ) {
F_3 ( V_103 L_31 ) ;
return 0 ;
}
memset ( V_73 , 0 , sizeof( V_73 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
type = V_9 [ V_7 ] . type ;
if ( type >= V_74 )
continue;
V_6 = V_9 [ V_7 ] . V_12 ;
if ( ! V_6 )
type = V_74 ;
V_73 [ type ] ++ ;
}
if ( ! V_73 [ V_10 ] )
return 0 ;
if ( V_73 [ V_10 ] + V_73 [ V_18 ] !=
V_8 - V_73 [ V_74 ] )
return 0 ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
V_2 = 0 ;
if ( V_102 ) {
V_1 [ V_2 ] . V_16 = ( 1ULL << ( 32 - V_20 ) ) ;
V_1 [ V_2 ] . V_17 = V_102 >> V_20 ;
if ( V_121 < V_1 [ V_2 ] . V_17 )
V_121 = V_1 [ V_2 ] . V_17 ;
V_2 ++ ;
}
V_2 = F_1 ( V_1 , V_2 , 0 , 0 ) ;
V_122 = 0 ;
if ( V_1 [ 0 ] . V_16 )
V_122 += F_41 ( 0 , V_1 [ 0 ] . V_16 ) ;
for ( V_7 = 0 ; V_7 < V_2 - 1 ; V_7 ++ ) {
if ( V_1 [ V_7 ] . V_17 < V_1 [ V_7 + 1 ] . V_16 )
V_122 += F_41 ( V_1 [ V_7 ] . V_17 ,
V_1 [ V_7 + 1 ] . V_16 ) ;
}
V_7 = V_2 - 1 ;
if ( V_1 [ V_7 ] . V_17 < V_120 )
V_122 += F_41 ( V_1 [ V_7 ] . V_17 ,
V_120 ) ;
if ( V_122 ) {
F_44 ( L_32 , V_122 >> 20 ) ;
if ( ! V_123 )
F_45 ( 1 ) ;
F_32 ( L_33 ) ;
F_46 () ;
return 1 ;
}
return 0 ;
}
