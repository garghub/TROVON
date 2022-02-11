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
( V_21 . V_23 & 1 ) ) {
F_3 ( V_24 , V_7 ) ;
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
unsigned long V_25 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
V_25 += V_1 [ V_7 ] . V_17 - V_1 [ V_7 ] . V_16 ;
return V_25 ;
}
static int T_1 F_7 ( char * V_26 )
{
V_27 = 0 ;
return 0 ;
}
static int T_1 F_8 ( char * V_26 )
{
V_27 = 1 ;
return 0 ;
}
static int T_1 F_9 ( char * V_26 )
{
V_14 = 1 ;
return 0 ;
}
static void T_1
F_10 ( unsigned int V_28 , unsigned long V_29 , unsigned long V_30 ,
unsigned char type , unsigned int V_31 )
{
T_3 V_32 , V_33 , V_34 , V_35 ;
T_4 V_5 , V_36 ;
if ( ! V_30 ) {
F_11 ( V_28 , 0 , 0 , 0 , 0 ) ;
return;
}
V_36 = ( 1ULL << V_31 ) - 1 ;
V_36 &= ~ ( ( ( ( T_4 ) V_30 ) << 10 ) - 1 ) ;
V_5 = ( ( T_4 ) V_29 ) << 10 ;
V_5 |= type ;
V_36 |= 0x800 ;
V_32 = V_5 & ( ( 1ULL << 32 ) - 1 ) ;
V_33 = V_5 >> 32 ;
V_34 = V_36 & ( ( 1ULL << 32 ) - 1 ) ;
V_35 = V_36 >> 32 ;
F_11 ( V_28 , V_32 , V_33 , V_34 , V_35 ) ;
}
static void T_1
F_12 ( unsigned int V_28 , unsigned long V_29 , unsigned long V_30 ,
unsigned char type )
{
V_9 [ V_28 ] . V_11 = V_29 >> ( V_20 - 10 ) ;
V_9 [ V_28 ] . V_12 = V_30 >> ( V_20 - 10 ) ;
V_9 [ V_28 ] . type = type ;
}
static void T_1 F_13 ( unsigned int V_31 )
{
unsigned long V_29 , V_30 ;
unsigned char type ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_8 ; V_28 ++ ) {
V_29 = V_9 [ V_28 ] . V_11 << ( V_20 - 10 ) ;
V_30 = V_9 [ V_28 ] . V_12 << ( V_20 - 10 ) ;
type = V_9 [ V_28 ] . type ;
F_10 ( V_28 , V_29 , V_30 , type , V_31 ) ;
}
}
static unsigned long F_14 ( unsigned long V_30 , char * V_37 )
{
unsigned long V_5 = V_30 ;
char V_38 ;
if ( V_5 & ( ( 1 << 10 ) - 1 ) ) {
V_38 = 'K' ;
} else if ( V_5 & ( ( 1 << 20 ) - 1 ) ) {
V_38 = 'M' ;
V_5 >>= 10 ;
} else {
V_38 = 'G' ;
V_5 >>= 20 ;
}
* V_37 = V_38 ;
return V_5 ;
}
static unsigned int T_1
F_15 ( unsigned int V_28 , unsigned long V_39 ,
unsigned long V_40 , unsigned char type )
{
if ( ! V_40 || ( V_28 >= V_8 ) )
return V_28 ;
while ( V_40 ) {
unsigned long V_41 , V_42 ;
unsigned long V_30 ;
if ( V_39 )
V_41 = F_16 ( V_39 ) ;
else
V_41 = V_43 - 1 ;
V_42 = F_17 ( V_40 ) ;
if ( V_42 > V_41 )
V_42 = V_41 ;
V_30 = 1UL << V_42 ;
if ( V_14 ) {
char V_44 = 'K' , V_45 = 'K' ;
unsigned long V_46 , V_47 ;
V_46 = F_14 ( V_39 , & V_44 ) ;
V_47 = F_14 ( V_30 , & V_45 ) ;
F_18 ( L_5
L_6 ,
V_28 , V_46 , V_44 ,
V_47 , V_45 ,
( type == V_18 ) ? L_7 :
( ( type == V_10 ) ? L_8 : L_9 )
) ;
}
F_12 ( V_28 ++ , V_39 , V_30 , type ) ;
V_39 += V_30 ;
V_40 -= V_30 ;
if ( V_28 >= V_8 )
break;
}
return V_28 ;
}
static unsigned T_1
F_19 ( struct V_48 * V_49 , unsigned long V_29 ,
unsigned long V_30 )
{
unsigned long V_50 , V_51 ;
unsigned long V_52 , V_53 ;
unsigned long V_54 , V_55 ;
unsigned long V_56 , V_40 ;
unsigned long V_57 ;
unsigned long V_58 ;
V_50 = 0 ;
V_51 = 0 ;
V_52 = 0 ;
V_53 = 0 ;
V_57 = V_49 -> V_57 ;
V_58 = V_49 -> V_58 ;
V_56 = F_20 ( V_49 -> V_39 , V_58 ) ;
if ( ( V_56 > V_29 ) && V_29 )
return V_53 ;
V_49 -> V_40 -= ( V_56 - V_49 -> V_39 ) ;
V_40 = F_20 ( V_49 -> V_40 , V_58 ) ;
while ( V_40 > V_49 -> V_40 ) {
V_40 -= V_58 ;
if ( ! V_40 )
return 0 ;
}
V_49 -> V_40 = V_40 ;
V_54 = V_49 -> V_39 ;
V_55 = F_20 ( V_49 -> V_40 , V_57 ) ;
if ( V_55 == V_49 -> V_40 ) {
F_18 ( L_10 ,
V_54 << 10 ,
( V_54 + V_49 -> V_40 ) << 10 ) ;
V_49 -> V_28 = F_15 ( V_49 -> V_28 , V_54 ,
V_49 -> V_40 , V_10 ) ;
return 0 ;
}
if ( V_30 ) {
while ( V_54 + V_55 > ( V_29 + V_30 ) ) {
if ( V_55 >= V_57 )
V_55 -= V_57 ;
else
V_55 = 0 ;
if ( ! V_55 )
break;
}
}
V_59:
V_56 = V_54 + V_55 ;
if ( V_56 > V_29 && V_56 <= ( V_29 + V_30 ) )
V_53 = V_56 - V_29 ;
if ( V_55 > V_49 -> V_40 ) {
V_51 = V_55 - V_49 -> V_40 - V_53 ;
if ( V_51 >= ( V_55 >> 1 ) &&
V_55 >= V_57 ) {
V_55 -= V_57 ;
V_53 = 0 ;
V_51 = 0 ;
goto V_59;
}
}
if ( V_55 ) {
F_18 ( L_11 ,
V_54 << 10 ,
( V_54 + V_55 ) << 10 ) ;
V_49 -> V_28 = F_15 ( V_49 -> V_28 , V_54 ,
V_55 , V_10 ) ;
}
if ( V_55 < V_49 -> V_40 ) {
V_40 = V_49 -> V_40 - V_55 ;
F_18 ( L_12 ,
V_56 << 10 ,
( V_56 + V_40 ) << 10 ) ;
V_49 -> V_28 = F_15 ( V_49 -> V_28 , V_56 ,
V_40 , V_10 ) ;
}
if ( V_51 ) {
V_50 = V_56 - V_51 - V_53 ;
F_18 ( L_13 ,
V_50 << 10 ,
( V_50 + V_51 ) << 10 ) ;
V_49 -> V_28 = F_15 ( V_49 -> V_28 , V_50 ,
V_51 , V_18 ) ;
}
return V_53 ;
}
static void T_1
F_21 ( struct V_48 * V_49 , unsigned long V_11 ,
unsigned long V_12 )
{
unsigned long V_29 , V_30 ;
unsigned long V_53 = 0 ;
if ( V_49 -> V_28 >= V_8 )
return;
V_29 = V_11 << ( V_20 - 10 ) ;
V_30 = V_12 << ( V_20 - 10 ) ;
if ( ( V_29 <= 1024 ) ||
( V_49 -> V_39 + V_49 -> V_40 == V_29 ) ) {
unsigned long V_60 = V_29 + V_30 ;
V_49 -> V_40 = V_60 - V_49 -> V_39 ;
return;
}
if ( V_49 -> V_40 != 0 )
V_53 = F_19 ( V_49 , V_29 , V_30 ) ;
V_49 -> V_39 = V_29 + V_53 ;
V_49 -> V_40 = V_30 - V_53 ;
}
static int T_1 F_22 ( char * V_61 )
{
if ( ! V_61 )
return - V_62 ;
V_63 = F_23 ( V_61 , & V_61 ) ;
return 0 ;
}
static int T_1 F_24 ( char * V_61 )
{
if ( ! V_61 )
return - V_62 ;
V_64 = F_23 ( V_61 , & V_61 ) ;
return 0 ;
}
static int T_1 F_25 ( char * V_65 )
{
if ( V_65 )
V_66 = F_26 ( V_65 , NULL , 0 ) ;
return 0 ;
}
static int T_1
F_27 ( struct V_1 * V_1 , int V_2 ,
T_4 V_67 , T_4 V_68 )
{
struct V_48 V_69 ;
int V_70 ;
int V_7 ;
V_69 . V_39 = 0 ;
V_69 . V_40 = 0 ;
V_69 . V_28 = 0 ;
V_69 . V_57 = V_67 >> 10 ;
V_69 . V_58 = V_68 >> 10 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) {
F_21 ( & V_69 , V_1 [ V_7 ] . V_16 ,
V_1 [ V_7 ] . V_17 - V_1 [ V_7 ] . V_16 ) ;
}
if ( V_69 . V_40 != 0 )
F_19 ( & V_69 , 0 , 0 ) ;
V_70 = V_69 . V_28 ;
while ( V_69 . V_28 < V_8 ) {
F_12 ( V_69 . V_28 , 0 , 0 , 0 ) ;
V_69 . V_28 ++ ;
}
return V_70 ;
}
static void T_1 F_28 ( void )
{
char V_44 = 'K' , V_45 = 'K' ;
unsigned long V_46 , V_47 ;
T_2 type ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_47 = V_9 [ V_7 ] . V_12 << ( V_20 - 10 ) ;
if ( ! V_47 )
continue;
V_47 = F_14 ( V_47 , & V_45 ) ,
V_46 = V_9 [ V_7 ] . V_11 << ( V_20 - 10 ) ;
V_46 = F_14 ( V_46 , & V_44 ) ,
type = V_9 [ V_7 ] . type ;
F_3 ( V_15 L_14 ,
V_7 , V_46 , V_44 ,
V_47 , V_45 ,
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
int V_71 [ V_72 + 1 ] ;
memset ( V_71 , 0 , sizeof( V_71 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
type = V_9 [ V_7 ] . type ;
V_6 = V_9 [ V_7 ] . V_12 ;
if ( type >= V_72 )
continue;
if ( ! V_6 )
type = V_72 ;
V_71 [ type ] ++ ;
}
if ( ! V_71 [ V_18 ] )
return 0 ;
if ( V_71 [ V_10 ] + V_71 [ V_18 ] !=
V_8 - V_71 [ V_72 ] )
return 0 ;
return 1 ;
}
static void T_1
F_30 ( T_4 V_67 , T_4 V_68 ,
unsigned long V_73 ,
unsigned long V_74 , int V_7 )
{
static struct V_1 V_75 [ V_13 ] ;
unsigned long V_76 ;
static int V_77 ;
int V_70 ;
V_70 = F_27 ( V_1 , V_2 , V_67 , V_68 ) ;
memset ( V_75 , 0 , sizeof( V_75 ) ) ;
V_77 = F_1 ( V_75 , 0 ,
V_73 , V_74 ) ;
V_76 = F_6 ( V_75 , V_77 ) ;
V_78 [ V_7 ] . V_57 = V_67 >> 10 ;
V_78 [ V_7 ] . V_58 = V_68 >> 10 ;
V_78 [ V_7 ] . V_70 = V_70 ;
if ( V_79 < V_76 ) {
V_78 [ V_7 ] . V_80 = ( V_76 - V_79 ) << V_81 ;
V_78 [ V_7 ] . V_82 = 1 ;
} else {
V_78 [ V_7 ] . V_80 = ( V_79 - V_76 ) << V_81 ;
}
if ( ! V_78 [ V_7 ] . V_82 && ! V_78 [ V_7 ] . V_80 ) {
if ( V_77 != V_2 || memcmp ( V_1 , V_75 , sizeof( V_1 ) ) )
V_78 [ V_7 ] . V_82 = 1 ;
}
if ( ! V_78 [ V_7 ] . V_82 && ( V_79 - V_76 < V_83 [ V_70 ] ) )
V_83 [ V_70 ] = V_79 - V_76 ;
}
static void T_1 F_31 ( int V_7 )
{
unsigned long V_84 , V_85 , V_86 ;
char V_87 , V_88 , V_89 ;
V_84 = F_14 ( V_78 [ V_7 ] . V_58 , & V_87 ) ;
V_85 = F_14 ( V_78 [ V_7 ] . V_57 , & V_88 ) ;
V_86 = F_14 ( V_78 [ V_7 ] . V_80 , & V_89 ) ;
F_32 ( L_16 ,
V_78 [ V_7 ] . V_82 ? L_17 : L_18 ,
V_84 , V_87 , V_85 , V_88 ) ;
F_33 ( L_19 ,
V_78 [ V_7 ] . V_70 , V_78 [ V_7 ] . V_82 ? L_20 : L_21 ,
V_86 , V_89 ) ;
}
static int T_1 F_34 ( void )
{
int V_90 ;
int V_91 ;
int V_7 ;
if ( V_66 >= V_8 )
V_66 = V_8 - 1 ;
V_90 = - 1 ;
for ( V_7 = V_8 - V_66 ; V_7 > 0 ; V_7 -- ) {
if ( ! V_83 [ V_7 ] )
V_90 = V_7 ;
}
V_91 = - 1 ;
if ( V_90 != - 1 ) {
for ( V_7 = 0 ; V_7 < V_92 ; V_7 ++ ) {
if ( ! V_78 [ V_7 ] . V_82 &&
V_78 [ V_7 ] . V_70 == V_90 &&
! V_78 [ V_7 ] . V_80 ) {
V_91 = V_7 ;
break;
}
}
}
return V_91 ;
}
int T_1 F_35 ( unsigned V_31 )
{
unsigned long V_73 , V_74 ;
unsigned long V_5 , V_6 , V_93 , V_94 ;
T_4 V_67 , V_68 ;
T_2 type ;
int V_91 ;
int V_7 ;
if ( ! F_36 ( V_95 ) || V_27 < 1 )
return 0 ;
F_37 ( V_96 , V_93 , V_94 ) ;
V_93 &= 0xff ;
if ( V_93 != V_18 )
return 0 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_97 -> V_98 ( V_7 , & V_5 , & V_6 , & type ) ;
V_9 [ V_7 ] . V_11 = V_5 ;
V_9 [ V_7 ] . V_12 = V_6 ;
V_9 [ V_7 ] . type = type ;
}
if ( ! F_29 () )
return 0 ;
F_3 ( V_15 L_22 ) ;
F_28 () ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
V_74 = 0 ;
V_73 = 1 << ( 32 - V_20 ) ;
if ( V_99 )
V_74 = ( V_99 >> V_20 ) - V_73 ;
V_2 = F_2 ( V_1 , V_13 , 0 , 0 ,
1ULL << ( 20 - V_20 ) ) ;
V_2 = F_1 ( V_1 , V_2 ,
V_73 , V_74 ) ;
V_79 = F_6 ( V_1 , V_2 ) ;
F_3 ( V_100 L_23 ,
V_79 >> ( 20 - V_20 ) ) ;
if ( V_63 && V_64 ) {
V_7 = 0 ;
F_30 ( V_63 , V_64 ,
V_73 , V_74 , V_7 ) ;
F_31 ( V_7 ) ;
if ( ! V_78 [ V_7 ] . V_82 ) {
F_13 ( V_31 ) ;
F_3 ( V_15 L_24 ) ;
F_28 () ;
return 1 ;
}
F_3 ( V_100 L_25
L_26 ) ;
}
V_7 = 0 ;
memset ( V_83 , 0xff , sizeof( V_83 ) ) ;
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
for ( V_68 = ( 1ULL << 16 ) ; V_68 < ( 1ULL << 32 ) ; V_68 <<= 1 ) {
for ( V_67 = V_68 ; V_67 < ( 1ULL << 32 ) ;
V_67 <<= 1 ) {
if ( V_7 >= V_92 )
continue;
F_30 ( V_67 , V_68 ,
V_73 , V_74 , V_7 ) ;
if ( V_14 ) {
F_31 ( V_7 ) ;
F_3 ( V_100 L_27 ) ;
}
V_7 ++ ;
}
}
V_91 = F_34 () ;
if ( V_91 != - 1 ) {
F_3 ( V_100 L_28 ) ;
V_7 = V_91 ;
F_31 ( V_7 ) ;
V_67 = V_78 [ V_7 ] . V_57 ;
V_67 <<= 10 ;
V_68 = V_78 [ V_7 ] . V_58 ;
V_68 <<= 10 ;
F_27 ( V_1 , V_2 , V_67 , V_68 ) ;
F_13 ( V_31 ) ;
F_3 ( V_15 L_24 ) ;
F_28 () ;
return 1 ;
} else {
for ( V_7 = 0 ; V_7 < V_92 ; V_7 ++ )
F_31 ( V_7 ) ;
}
F_3 ( V_100 L_29 ) ;
F_3 ( V_100 L_30 ) ;
return 0 ;
}
int T_1 F_35 ( unsigned V_31 )
{
return 0 ;
}
static int T_1 F_38 ( char * V_26 )
{
V_101 = 1 ;
return 0 ;
}
int T_1 F_39 ( void )
{
T_3 V_102 , V_103 ;
if ( V_104 . V_105 != V_106 )
return 0 ;
if ( V_104 . V_107 < 0xf )
return 0 ;
if ( F_40 ( V_108 , & V_102 , & V_103 ) < 0 )
return 0 ;
if ( ( V_102 & ( V_109 | V_110 ) ) ==
( V_109 | V_110 ) )
return 1 ;
return 0 ;
}
static T_4 T_1
F_41 ( unsigned long V_111 , unsigned long V_112 )
{
T_4 V_113 , V_114 ;
V_113 = V_111 ;
V_113 <<= V_20 ;
V_114 = V_112 ;
V_114 <<= V_20 ;
V_114 -= V_113 ;
return F_42 ( V_113 , V_114 , V_115 , V_116 ) ;
}
int T_1 F_43 ( unsigned long V_117 )
{
unsigned long V_7 , V_5 , V_6 , V_118 = 0 , V_93 , V_94 ;
T_2 type ;
T_4 V_119 ;
int V_71 [ V_72 + 1 ] ;
if ( ! F_36 ( V_95 ) || V_101 )
return 0 ;
F_37 ( V_96 , V_93 , V_94 ) ;
V_93 &= 0xff ;
if ( V_93 != V_18 )
return 0 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_97 -> V_98 ( V_7 , & V_5 , & V_6 , & type ) ;
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
if ( V_118 < V_5 + V_6 )
V_118 = V_5 + V_6 ;
}
if ( ! V_118 ) {
F_3 ( V_100 L_31 ) ;
return 0 ;
}
memset ( V_71 , 0 , sizeof( V_71 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
type = V_9 [ V_7 ] . type ;
if ( type >= V_72 )
continue;
V_6 = V_9 [ V_7 ] . V_12 ;
if ( ! V_6 )
type = V_72 ;
V_71 [ type ] ++ ;
}
if ( ! V_71 [ V_10 ] )
return 0 ;
if ( V_71 [ V_10 ] + V_71 [ V_18 ] !=
V_8 - V_71 [ V_72 ] )
return 0 ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
V_2 = 0 ;
if ( V_99 ) {
V_1 [ V_2 ] . V_16 = ( 1ULL << ( 32 - V_20 ) ) ;
V_1 [ V_2 ] . V_17 = V_99 >> V_20 ;
if ( V_118 < V_1 [ V_2 ] . V_17 )
V_118 = V_1 [ V_2 ] . V_17 ;
V_2 ++ ;
}
V_2 = F_1 ( V_1 , V_2 , 0 , 0 ) ;
V_119 = 0 ;
if ( V_1 [ 0 ] . V_16 )
V_119 += F_41 ( 0 , V_1 [ 0 ] . V_16 ) ;
for ( V_7 = 0 ; V_7 < V_2 - 1 ; V_7 ++ ) {
if ( V_1 [ V_7 ] . V_17 < V_1 [ V_7 + 1 ] . V_16 )
V_119 += F_41 ( V_1 [ V_7 ] . V_17 ,
V_1 [ V_7 + 1 ] . V_16 ) ;
}
V_7 = V_2 - 1 ;
if ( V_1 [ V_7 ] . V_17 < V_117 )
V_119 += F_41 ( V_1 [ V_7 ] . V_17 ,
V_117 ) ;
if ( V_119 ) {
F_44 ( L_32 , V_119 >> 20 ) ;
if ( ! V_120 )
F_45 ( 1 ) ;
F_32 ( L_33 ) ;
F_46 () ;
return 1 ;
}
return 0 ;
}
