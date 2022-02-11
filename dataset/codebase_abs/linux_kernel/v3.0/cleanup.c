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
V_41 = F_16 ( V_39 ) - 1 ;
else
V_41 = 32 ;
V_42 = F_17 ( V_40 ) - 1 ;
if ( V_42 > V_41 )
V_42 = V_41 ;
V_30 = 1 << V_42 ;
if ( V_14 ) {
char V_43 = 'K' , V_44 = 'K' ;
unsigned long V_45 , V_46 ;
V_45 = F_14 ( V_39 , & V_43 ) ;
V_46 = F_14 ( V_30 , & V_44 ) ;
F_18 ( L_5
L_6 ,
V_28 , V_45 , V_43 ,
V_46 , V_44 ,
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
F_19 ( struct V_47 * V_48 , unsigned long V_29 ,
unsigned long V_30 )
{
unsigned long V_49 , V_50 ;
unsigned long V_51 , V_52 ;
unsigned long V_53 , V_54 ;
unsigned long V_55 , V_40 ;
unsigned long V_56 ;
unsigned long V_57 ;
V_49 = 0 ;
V_50 = 0 ;
V_51 = 0 ;
V_52 = 0 ;
V_56 = V_48 -> V_56 ;
V_57 = V_48 -> V_57 ;
V_55 = F_20 ( V_48 -> V_39 , V_57 ) ;
if ( ( V_55 > V_29 ) && V_29 )
return V_52 ;
V_48 -> V_40 -= ( V_55 - V_48 -> V_39 ) ;
V_40 = F_20 ( V_48 -> V_40 , V_57 ) ;
while ( V_40 > V_48 -> V_40 ) {
V_40 -= V_57 ;
if ( ! V_40 )
return 0 ;
}
V_48 -> V_40 = V_40 ;
V_53 = V_48 -> V_39 ;
V_54 = F_20 ( V_48 -> V_40 , V_56 ) ;
if ( V_54 == V_48 -> V_40 ) {
F_18 ( L_10 ,
V_53 << 10 ,
( V_53 + V_48 -> V_40 ) << 10 ) ;
V_48 -> V_28 = F_15 ( V_48 -> V_28 , V_53 ,
V_48 -> V_40 , V_10 ) ;
return 0 ;
}
if ( V_30 ) {
while ( V_53 + V_54 > ( V_29 + V_30 ) ) {
if ( V_54 >= V_56 )
V_54 -= V_56 ;
else
V_54 = 0 ;
if ( ! V_54 )
break;
}
}
V_58:
V_55 = V_53 + V_54 ;
if ( V_55 > V_29 && V_55 <= ( V_29 + V_30 ) )
V_52 = V_55 - V_29 ;
if ( V_54 > V_48 -> V_40 ) {
V_50 = V_54 - V_48 -> V_40 - V_52 ;
if ( V_50 >= ( V_54 >> 1 ) &&
V_54 >= V_56 ) {
V_54 -= V_56 ;
V_52 = 0 ;
V_50 = 0 ;
goto V_58;
}
}
if ( V_54 ) {
F_18 ( L_11 ,
V_53 << 10 ,
( V_53 + V_54 ) << 10 ) ;
V_48 -> V_28 = F_15 ( V_48 -> V_28 , V_53 ,
V_54 , V_10 ) ;
}
if ( V_54 < V_48 -> V_40 ) {
V_40 = V_48 -> V_40 - V_54 ;
F_18 ( L_12 ,
V_55 << 10 ,
( V_55 + V_40 ) << 10 ) ;
V_48 -> V_28 = F_15 ( V_48 -> V_28 , V_55 ,
V_40 , V_10 ) ;
}
if ( V_50 ) {
V_49 = V_55 - V_50 - V_52 ;
F_18 ( L_13 ,
V_49 << 10 ,
( V_49 + V_50 ) << 10 ) ;
V_48 -> V_28 = F_15 ( V_48 -> V_28 , V_49 ,
V_50 , V_18 ) ;
}
return V_52 ;
}
static void T_1
F_21 ( struct V_47 * V_48 , unsigned long V_11 ,
unsigned long V_12 )
{
unsigned long V_29 , V_30 ;
unsigned long V_52 = 0 ;
if ( V_48 -> V_28 >= V_8 )
return;
V_29 = V_11 << ( V_20 - 10 ) ;
V_30 = V_12 << ( V_20 - 10 ) ;
if ( ( V_29 <= 1024 ) ||
( V_48 -> V_39 + V_48 -> V_40 == V_29 ) ) {
unsigned long V_59 = V_29 + V_30 ;
V_48 -> V_40 = V_59 - V_48 -> V_39 ;
return;
}
if ( V_48 -> V_40 != 0 )
V_52 = F_19 ( V_48 , V_29 , V_30 ) ;
V_48 -> V_39 = V_29 + V_52 ;
V_48 -> V_40 = V_30 - V_52 ;
}
static int T_1 F_22 ( char * V_60 )
{
if ( ! V_60 )
return - V_61 ;
V_62 = F_23 ( V_60 , & V_60 ) ;
return 0 ;
}
static int T_1 F_24 ( char * V_60 )
{
if ( ! V_60 )
return - V_61 ;
V_63 = F_23 ( V_60 , & V_60 ) ;
return 0 ;
}
static int T_1 F_25 ( char * V_64 )
{
if ( V_64 )
V_65 = F_26 ( V_64 , NULL , 0 ) ;
return 0 ;
}
static int T_1
F_27 ( struct V_1 * V_1 , int V_2 ,
T_4 V_66 , T_4 V_67 )
{
struct V_47 V_68 ;
int V_69 ;
int V_7 ;
V_68 . V_39 = 0 ;
V_68 . V_40 = 0 ;
V_68 . V_28 = 0 ;
V_68 . V_56 = V_66 >> 10 ;
V_68 . V_57 = V_67 >> 10 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) {
F_21 ( & V_68 , V_1 [ V_7 ] . V_16 ,
V_1 [ V_7 ] . V_17 - V_1 [ V_7 ] . V_16 ) ;
}
if ( V_68 . V_40 != 0 )
F_19 ( & V_68 , 0 , 0 ) ;
V_69 = V_68 . V_28 ;
while ( V_68 . V_28 < V_8 ) {
F_12 ( V_68 . V_28 , 0 , 0 , 0 ) ;
V_68 . V_28 ++ ;
}
return V_69 ;
}
static void T_1 F_28 ( void )
{
char V_43 = 'K' , V_44 = 'K' ;
unsigned long V_45 , V_46 ;
T_2 type ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_46 = V_9 [ V_7 ] . V_12 << ( V_20 - 10 ) ;
if ( ! V_46 )
continue;
V_46 = F_14 ( V_46 , & V_44 ) ,
V_45 = V_9 [ V_7 ] . V_11 << ( V_20 - 10 ) ;
V_45 = F_14 ( V_45 , & V_43 ) ,
type = V_9 [ V_7 ] . type ;
F_3 ( V_15 L_14 ,
V_7 , V_45 , V_43 ,
V_46 , V_44 ,
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
int V_70 [ V_71 + 1 ] ;
memset ( V_70 , 0 , sizeof( V_70 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
type = V_9 [ V_7 ] . type ;
V_6 = V_9 [ V_7 ] . V_12 ;
if ( type >= V_71 )
continue;
if ( ! V_6 )
type = V_71 ;
V_70 [ type ] ++ ;
}
if ( ! V_70 [ V_18 ] )
return 0 ;
if ( V_70 [ V_10 ] + V_70 [ V_18 ] !=
V_8 - V_70 [ V_71 ] )
return 0 ;
return 1 ;
}
static void T_1
F_30 ( T_4 V_66 , T_4 V_67 ,
unsigned long V_72 ,
unsigned long V_73 , int V_7 )
{
static struct V_1 V_74 [ V_13 ] ;
unsigned long V_75 ;
static int V_76 ;
int V_69 ;
V_69 = F_27 ( V_1 , V_2 , V_66 , V_67 ) ;
memset ( V_74 , 0 , sizeof( V_74 ) ) ;
V_76 = F_1 ( V_74 , 0 ,
V_72 , V_73 ) ;
V_75 = F_6 ( V_74 , V_76 ) ;
V_77 [ V_7 ] . V_56 = V_66 >> 10 ;
V_77 [ V_7 ] . V_57 = V_67 >> 10 ;
V_77 [ V_7 ] . V_69 = V_69 ;
if ( V_78 < V_75 ) {
V_77 [ V_7 ] . V_79 = ( V_75 - V_78 ) << V_80 ;
V_77 [ V_7 ] . V_81 = 1 ;
} else {
V_77 [ V_7 ] . V_79 = ( V_78 - V_75 ) << V_80 ;
}
if ( ! V_77 [ V_7 ] . V_81 && ! V_77 [ V_7 ] . V_79 ) {
if ( V_76 != V_2 || memcmp ( V_1 , V_74 , sizeof( V_1 ) ) )
V_77 [ V_7 ] . V_81 = 1 ;
}
if ( ! V_77 [ V_7 ] . V_81 && ( V_78 - V_75 < V_82 [ V_69 ] ) )
V_82 [ V_69 ] = V_78 - V_75 ;
}
static void T_1 F_31 ( int V_7 )
{
unsigned long V_83 , V_84 , V_85 ;
char V_86 , V_87 , V_88 ;
V_83 = F_14 ( V_77 [ V_7 ] . V_57 , & V_86 ) ;
V_84 = F_14 ( V_77 [ V_7 ] . V_56 , & V_87 ) ;
V_85 = F_14 ( V_77 [ V_7 ] . V_79 , & V_88 ) ;
F_32 ( L_16 ,
V_77 [ V_7 ] . V_81 ? L_17 : L_18 ,
V_83 , V_86 , V_84 , V_87 ) ;
F_33 ( L_19 ,
V_77 [ V_7 ] . V_69 , V_77 [ V_7 ] . V_81 ? L_20 : L_21 ,
V_85 , V_88 ) ;
}
static int T_1 F_34 ( void )
{
int V_89 ;
int V_90 ;
int V_7 ;
if ( V_65 >= V_8 )
V_65 = V_8 - 1 ;
V_89 = - 1 ;
for ( V_7 = V_8 - V_65 ; V_7 > 0 ; V_7 -- ) {
if ( ! V_82 [ V_7 ] )
V_89 = V_7 ;
}
V_90 = - 1 ;
if ( V_89 != - 1 ) {
for ( V_7 = 0 ; V_7 < V_91 ; V_7 ++ ) {
if ( ! V_77 [ V_7 ] . V_81 &&
V_77 [ V_7 ] . V_69 == V_89 &&
! V_77 [ V_7 ] . V_79 ) {
V_90 = V_7 ;
break;
}
}
}
return V_90 ;
}
int T_1 F_35 ( unsigned V_31 )
{
unsigned long V_72 , V_73 ;
unsigned long V_5 , V_6 , V_92 , V_93 ;
T_4 V_66 , V_67 ;
T_2 type ;
int V_90 ;
int V_7 ;
if ( ! F_36 ( V_94 ) || V_27 < 1 )
return 0 ;
F_37 ( V_95 , V_92 , V_93 ) ;
V_92 &= 0xff ;
if ( V_92 != V_18 )
return 0 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_96 -> V_97 ( V_7 , & V_5 , & V_6 , & type ) ;
V_9 [ V_7 ] . V_11 = V_5 ;
V_9 [ V_7 ] . V_12 = V_6 ;
V_9 [ V_7 ] . type = type ;
}
if ( ! F_29 () )
return 0 ;
F_3 ( V_15 L_22 ) ;
F_28 () ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
V_73 = 0 ;
V_72 = 1 << ( 32 - V_20 ) ;
if ( V_98 )
V_73 = ( V_98 >> V_20 ) - V_72 ;
V_2 = F_1 ( V_1 , 0 , V_72 , V_73 ) ;
V_2 = F_2 ( V_1 , V_13 , V_2 , 0 ,
1ULL << ( 20 - V_20 ) ) ;
F_38 ( V_1 , V_2 ) ;
V_78 = F_6 ( V_1 , V_2 ) ;
F_3 ( V_99 L_23 ,
V_78 >> ( 20 - V_20 ) ) ;
if ( V_62 && V_63 ) {
V_7 = 0 ;
F_30 ( V_62 , V_63 ,
V_72 , V_73 , V_7 ) ;
F_31 ( V_7 ) ;
if ( ! V_77 [ V_7 ] . V_81 ) {
F_13 ( V_31 ) ;
F_3 ( V_15 L_24 ) ;
F_28 () ;
return 1 ;
}
F_3 ( V_99 L_25
L_26 ) ;
}
V_7 = 0 ;
memset ( V_82 , 0xff , sizeof( V_82 ) ) ;
memset ( V_77 , 0 , sizeof( V_77 ) ) ;
for ( V_67 = ( 1ULL << 16 ) ; V_67 < ( 1ULL << 32 ) ; V_67 <<= 1 ) {
for ( V_66 = V_67 ; V_66 < ( 1ULL << 32 ) ;
V_66 <<= 1 ) {
if ( V_7 >= V_91 )
continue;
F_30 ( V_66 , V_67 ,
V_72 , V_73 , V_7 ) ;
if ( V_14 ) {
F_31 ( V_7 ) ;
F_3 ( V_99 L_27 ) ;
}
V_7 ++ ;
}
}
V_90 = F_34 () ;
if ( V_90 != - 1 ) {
F_3 ( V_99 L_28 ) ;
V_7 = V_90 ;
F_31 ( V_7 ) ;
V_66 = V_77 [ V_7 ] . V_56 ;
V_66 <<= 10 ;
V_67 = V_77 [ V_7 ] . V_57 ;
V_67 <<= 10 ;
F_27 ( V_1 , V_2 , V_66 , V_67 ) ;
F_13 ( V_31 ) ;
F_3 ( V_15 L_24 ) ;
F_28 () ;
return 1 ;
} else {
for ( V_7 = 0 ; V_7 < V_91 ; V_7 ++ )
F_31 ( V_7 ) ;
}
F_3 ( V_99 L_29 ) ;
F_3 ( V_99 L_30 ) ;
return 0 ;
}
int T_1 F_35 ( unsigned V_31 )
{
return 0 ;
}
static int T_1 F_39 ( char * V_26 )
{
V_100 = 1 ;
return 0 ;
}
int T_1 F_40 ( void )
{
T_3 V_101 , V_102 ;
if ( V_103 . V_104 != V_105 )
return 0 ;
if ( V_103 . V_106 < 0xf )
return 0 ;
if ( F_41 ( V_107 , & V_101 , & V_102 ) < 0 )
return 0 ;
if ( ( V_101 & ( V_108 | V_109 ) ) ==
( V_108 | V_109 ) )
return 1 ;
return 0 ;
}
static T_4 T_1
F_42 ( unsigned long V_110 , unsigned long V_111 )
{
T_4 V_112 , V_113 ;
V_112 = V_110 ;
V_112 <<= V_20 ;
V_113 = V_111 ;
V_113 <<= V_20 ;
V_113 -= V_112 ;
return F_43 ( V_112 , V_113 , V_114 , V_115 ) ;
}
int T_1 F_44 ( unsigned long V_116 )
{
unsigned long V_7 , V_5 , V_6 , V_117 = 0 , V_92 , V_93 ;
T_2 type ;
T_4 V_118 ;
int V_70 [ V_71 + 1 ] ;
if ( ! F_36 ( V_94 ) || V_100 )
return 0 ;
F_37 ( V_95 , V_92 , V_93 ) ;
V_92 &= 0xff ;
if ( V_92 != V_18 )
return 0 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_96 -> V_97 ( V_7 , & V_5 , & V_6 , & type ) ;
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
if ( V_117 < V_5 + V_6 )
V_117 = V_5 + V_6 ;
}
if ( ! V_117 ) {
F_3 ( V_99 L_31 ) ;
return 0 ;
}
memset ( V_70 , 0 , sizeof( V_70 ) ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
type = V_9 [ V_7 ] . type ;
if ( type >= V_71 )
continue;
V_6 = V_9 [ V_7 ] . V_12 ;
if ( ! V_6 )
type = V_71 ;
V_70 [ type ] ++ ;
}
if ( ! V_70 [ V_10 ] )
return 0 ;
if ( V_70 [ V_10 ] + V_70 [ V_18 ] !=
V_8 - V_70 [ V_71 ] )
return 0 ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
V_2 = 0 ;
if ( V_98 ) {
V_1 [ V_2 ] . V_16 = ( 1ULL << ( 32 - V_20 ) ) ;
V_1 [ V_2 ] . V_17 = V_98 >> V_20 ;
if ( V_117 < V_1 [ V_2 ] . V_17 )
V_117 = V_1 [ V_2 ] . V_17 ;
V_2 ++ ;
}
V_2 = F_1 ( V_1 , V_2 , 0 , 0 ) ;
V_118 = 0 ;
if ( V_1 [ 0 ] . V_16 )
V_118 += F_42 ( 0 , V_1 [ 0 ] . V_16 ) ;
for ( V_7 = 0 ; V_7 < V_2 - 1 ; V_7 ++ ) {
if ( V_1 [ V_7 ] . V_17 < V_1 [ V_7 + 1 ] . V_16 )
V_118 += F_42 ( V_1 [ V_7 ] . V_17 ,
V_1 [ V_7 + 1 ] . V_16 ) ;
}
V_7 = V_2 - 1 ;
if ( V_1 [ V_7 ] . V_17 < V_116 )
V_118 += F_42 ( V_1 [ V_7 ] . V_17 ,
V_116 ) ;
if ( V_118 ) {
F_45 ( L_32 , V_118 >> 20 ) ;
if ( ! V_119 )
F_46 ( 1 ) ;
F_32 ( L_33 ) ;
F_47 () ;
return 1 ;
}
return 0 ;
}
