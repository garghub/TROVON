static void
F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = 0 ;
unsigned long V_4 = 0 ;
if ( ! V_2 )
return;
if ( V_2 -> V_5 )
return;
V_2 -> V_5 = 1 ;
if ( V_2 -> V_6 == 0 )
{
V_7 &= ~ F_2 ( V_8 , V_9 ) ;
V_7 |= F_3 ( V_8 , V_9 , V_10 ) ;
}
else if ( V_2 -> V_6 == 1 )
{
V_7 &= ~ F_2 ( V_8 , V_11 ) ;
V_7 |= F_3 ( V_8 , V_11 , V_12 ) ;
}
else if ( V_2 -> V_6 == 2 )
{
V_7 &= ~ F_2 ( V_8 , V_13 ) ;
V_7 |= F_3 ( V_8 , V_13 , V_14 ) ;
V_7 &= ~ F_2 ( V_8 , V_15 ) ;
V_7 |= F_3 ( V_8 , V_15 , V_14 ) ;
V_7 |= F_3 ( V_8 , V_16 , V_17 ) ;
}
else
{
V_7 &= ~ F_2 ( V_8 , V_18 ) ;
V_7 |= F_3 ( V_8 , V_18 , V_19 ) ;
V_7 &= ~ F_2 ( V_8 , V_20 ) ;
V_7 |= F_3 ( V_8 , V_20 , V_19 ) ;
V_7 |= F_3 ( V_8 , V_21 , V_17 ) ;
}
* V_8 = V_7 ;
* V_2 -> V_22 =
F_3 ( V_23 , V_24 , V_25 ) |
F_3 ( V_23 , V_26 , V_27 ) |
F_4 ( V_23 , V_28 , 0 ) ;
switch ( V_2 -> V_29 )
{
case 0 :
case 115200 :
* V_2 -> V_30 =
F_3 ( V_31 , V_32 , V_33 ) |
F_3 ( V_31 , V_34 , V_33 ) ;
break;
case 1200 :
* V_2 -> V_30 =
F_3 ( V_31 , V_32 , V_35 ) |
F_3 ( V_31 , V_34 , V_35 ) ;
break;
case 2400 :
* V_2 -> V_30 =
F_3 ( V_31 , V_32 , V_36 ) |
F_3 ( V_31 , V_34 , V_36 ) ;
break;
case 4800 :
* V_2 -> V_30 =
F_3 ( V_31 , V_32 , V_37 ) |
F_3 ( V_31 , V_34 , V_37 ) ;
break;
case 9600 :
* V_2 -> V_30 =
F_3 ( V_31 , V_32 , V_38 ) |
F_3 ( V_31 , V_34 , V_38 ) ;
break;
case 19200 :
* V_2 -> V_30 =
F_3 ( V_31 , V_32 , V_39 ) |
F_3 ( V_31 , V_34 , V_39 ) ;
break;
case 38400 :
* V_2 -> V_30 =
F_3 ( V_31 , V_32 , V_40 ) |
F_3 ( V_31 , V_34 , V_40 ) ;
break;
case 57600 :
* V_2 -> V_30 =
F_3 ( V_31 , V_32 , V_41 ) |
F_3 ( V_31 , V_34 , V_41 ) ;
break;
default:
* V_2 -> V_30 =
F_3 ( V_31 , V_32 , V_33 ) |
F_3 ( V_31 , V_34 , V_33 ) ;
break;
}
if ( V_2 -> V_42 == 'E' ) {
V_3 =
F_3 ( V_43 , V_44 , V_45 ) |
F_3 ( V_43 , V_46 , V_25 ) ;
V_4 =
F_3 ( V_47 , V_48 , V_45 ) |
F_3 ( V_47 , V_49 , V_25 ) ;
} else if ( V_2 -> V_42 == 'O' ) {
V_3 =
F_3 ( V_43 , V_44 , V_50 ) |
F_3 ( V_43 , V_46 , V_25 ) ;
V_4 =
F_3 ( V_47 , V_48 , V_50 ) |
F_3 ( V_47 , V_49 , V_25 ) ;
} else {
V_3 =
F_3 ( V_43 , V_44 , V_45 ) |
F_3 ( V_43 , V_46 , V_27 ) ;
V_4 =
F_3 ( V_47 , V_48 , V_45 ) |
F_3 ( V_47 , V_49 , V_27 ) ;
}
if ( V_2 -> V_51 == 7 )
{
V_3 |= F_3 ( V_43 , V_52 , V_53 ) ;
V_4 |= F_3 ( V_47 , V_54 , V_55 ) ;
}
else
{
V_3 |= F_3 ( V_43 , V_52 , V_56 ) ;
V_4 |= F_3 ( V_47 , V_54 , V_57 ) ;
}
* V_2 -> V_3 =
F_3 ( V_43 , V_58 , V_59 ) |
F_3 ( V_43 , V_60 , V_25 ) |
F_3 ( V_43 , V_61 , V_62 ) |
F_3 ( V_43 , V_63 , V_64 ) |
F_3 ( V_43 , V_65 , V_66 ) |
V_3 ;
* V_2 -> V_4 =
F_4 ( V_47 , V_67 , 0 ) |
F_3 ( V_47 , V_68 , V_25 ) |
F_3 ( V_47 , V_69 , V_70 ) |
F_3 ( V_47 , V_71 , V_72 ) |
F_3 ( V_47 , V_73 , V_66 ) |
V_4 ;
}
static void
F_5 ( struct V_74 * V_75 , const char * V_76 , unsigned int V_77 )
{
int V_78 ;
unsigned long V_79 ;
if ( ! V_80 )
return;
F_6 ( V_79 ) ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ ) {
if ( V_76 [ V_78 ] == '\n' ) {
while ( ! ( * V_80 -> V_81 & F_2 ( V_82 , V_83 ) ) )
;
* V_80 -> V_84 = '\r' ;
}
while ( ! ( * V_80 -> V_81 & F_2 ( V_82 , V_83 ) ) )
;
* V_80 -> V_84 = V_76 [ V_78 ] ;
}
F_7 () ;
F_8 ( V_79 ) ;
}
static void
F_9 ( struct V_74 * V_75 , const char * V_76 , unsigned int V_77 )
{
if ( ! V_80 )
return;
#ifdef F_10
F_11 ( V_76 , V_77 ) ;
return;
#endif
F_5 ( V_75 , V_76 , V_77 ) ;
}
void
F_12 ( const char * V_76 )
{
F_9 ( NULL , V_76 , strlen ( V_76 ) ) ;
}
int
F_13 ( void )
{
unsigned long V_85 ;
if ( ! V_86 )
return 0 ;
do {
V_85 = * V_86 -> V_81 ;
} while ( ! ( V_85 & F_2 ( V_82 , V_87 ) ) );
return ( V_85 & F_2 ( V_82 , V_88 ) ) ;
}
void
F_14 ( int V_89 )
{
if ( ! V_86 )
return;
while ( ! ( * V_86 -> V_81 & F_2 ( V_82 , V_83 ) ) )
;
* V_86 -> V_84 = V_89 ;
}
void
F_15 ( void )
{
if ( ! V_86 )
return;
* V_90 = V_86 -> V_91 ;
* V_92 = F_3 ( V_92 , V_93 , V_94 ) ;
* V_86 -> V_3 = F_3 ( V_43 , V_60 , V_25 ) ;
}
static int T_1
F_16 ( struct V_74 * V_75 , char * V_95 )
{
char * V_96 ;
if ( V_95 ) {
V_80 = & V_97 [ V_75 -> V_6 ] ;
V_80 -> V_29 = 115200 ;
V_80 -> V_42 = 'N' ;
V_80 -> V_51 = 8 ;
V_80 -> V_29 = F_17 ( V_95 , NULL , 10 ) ;
V_96 = V_95 ;
while( * V_96 >= '0' && * V_96 <= '9' )
V_96 ++ ;
if ( * V_96 ) V_80 -> V_42 = * V_96 ++ ;
if ( * V_96 ) V_80 -> V_51 = * V_96 ++ - '0' ;
V_80 -> V_5 = 0 ;
F_1 ( 0 ) ;
}
return 0 ;
}
static int F_18 ( struct V_98 * V_99 , struct V_100 * V_101 )
{
return 0 ;
}
static void F_19 ( struct V_98 * V_99 , struct V_100 * V_101 )
{
}
static int F_20 ( struct V_98 * V_99 ,
const unsigned char * V_76 , int V_102 )
{
return V_102 ;
}
static int F_21 ( struct V_98 * V_99 )
{
return 8192 ;
}
void T_1
F_22 ( void )
{
memset ( & V_103 , 0 , sizeof( struct V_104 ) ) ;
V_103 . V_105 = L_1 ;
V_103 . V_106 = L_2 ;
V_103 . V_107 = V_108 ;
V_103 . V_109 = 68 ;
V_103 . V_110 = 1 ;
V_103 . type = V_111 ;
V_103 . V_112 = V_113 ;
V_103 . V_114 = V_115 ;
V_103 . V_114 . V_116 =
V_117 | V_118 | V_119 | V_120 | V_121 ;
V_103 . V_79 = V_122 | V_123 ;
V_103 . V_114 . V_124 = 115200 ;
V_103 . V_114 . V_125 = 115200 ;
V_103 . V_126 = & V_127 ;
if ( F_23 ( & V_103 ) )
F_24 ( L_3 ) ;
}
static struct V_104 *
F_25 ( struct V_74 * V_75 , int * V_6 )
{
if ( V_80 )
* V_6 = V_80 -> V_6 ;
else
* V_6 = 0 ;
#ifdef F_26
return V_80 ? V_128 : & V_103 ;
#else
return & V_103 ;
#endif
}
int T_1
F_27 ( void )
{
static int V_129 = 1 ;
if ( ! V_129 ) {
F_28 ( & V_130 ) ;
F_29 ( & V_131 ) ;
F_29 ( & V_132 ) ;
F_29 ( & V_133 ) ;
F_29 ( & V_134 ) ;
F_22 () ;
return 0 ;
}
V_129 = 0 ;
F_29 ( & V_130 ) ;
F_1 ( V_80 ) ;
#ifdef F_30
F_1 ( V_86 ) ;
#endif
return 0 ;
}
