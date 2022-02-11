static int F_1 ( unsigned int V_1 , int V_2 , T_1 * V_3 , int V_4 )
{
int V_5 = 0 ;
if ( ! ( F_2 ( V_1 + V_6 ) & V_7 ) )
return 0 ;
while ( ( V_2 -- > 0 ) && ( V_5 < V_4 ) ) {
F_3 ( V_3 [ V_5 ] , V_1 + V_8 ) ;
V_5 ++ ;
}
return V_5 ;
}
static void F_4 ( T_2 * V_9 )
{
if ( ! V_9 ) {
F_5 ( L_1 ) ;
return;
}
if ( F_6 ( V_10 , & ( V_9 -> V_11 ) ) ) {
F_7 ( V_12 , & ( V_9 -> V_11 ) ) ;
return;
}
do {
register unsigned int V_1 = V_9 -> V_13 -> V_14 [ 0 ] -> V_15 ;
register struct V_16 * V_17 ;
register int V_4 ;
F_8 ( V_12 , & ( V_9 -> V_11 ) ) ;
if ( ! F_9 ( V_9 -> V_13 ) )
return;
if ( ! ( V_17 = F_10 ( & ( V_9 -> V_18 ) ) ) )
break;
V_4 = F_1 ( V_1 , 16 , V_17 -> V_19 , V_17 -> V_4 ) ;
F_7 ( V_12 , & ( V_9 -> V_11 ) ) ;
if ( V_4 == V_17 -> V_4 ) {
F_11 ( V_17 ) ;
} else {
F_12 ( V_17 , V_4 ) ;
F_13 ( & ( V_9 -> V_18 ) , V_17 ) ;
}
V_9 -> V_20 -> V_21 . V_22 += V_4 ;
} while ( F_14 ( V_12 , & ( V_9 -> V_11 ) ) );
F_8 ( V_10 , & ( V_9 -> V_11 ) ) ;
}
static void F_15 ( T_2 * V_9 )
{
unsigned int V_1 ;
int V_23 = 0 ;
if ( ! V_9 ) {
F_5 ( L_1 ) ;
return;
}
V_1 = V_9 -> V_13 -> V_14 [ 0 ] -> V_15 ;
do {
V_9 -> V_20 -> V_21 . V_24 ++ ;
if ( V_9 -> V_25 == NULL ) {
V_9 -> V_26 = V_27 ;
V_9 -> V_28 = 0 ;
if ( ! ( V_9 -> V_25 = F_16 ( V_29 , V_30 ) ) ) {
F_5 ( L_2 ) ;
return;
}
}
if ( V_9 -> V_26 == V_27 ) {
V_9 -> V_25 -> V_31 = ( void * ) V_9 -> V_20 ;
F_17 ( V_9 -> V_25 ) -> V_32 = F_2 ( V_1 + V_33 ) ;
switch ( F_17 ( V_9 -> V_25 ) -> V_32 ) {
case V_34 :
V_9 -> V_26 = V_35 ;
V_9 -> V_28 = V_36 ;
break;
case V_37 :
V_9 -> V_26 = V_38 ;
V_9 -> V_28 = V_39 ;
break;
case V_40 :
V_9 -> V_26 = V_41 ;
V_9 -> V_28 = V_42 ;
break;
default:
F_5 ( L_3 , F_17 ( V_9 -> V_25 ) -> V_32 ) ;
V_9 -> V_20 -> V_21 . V_43 ++ ;
F_8 ( V_44 , & ( V_9 -> V_20 -> V_45 ) ) ;
F_11 ( V_9 -> V_25 ) ;
V_9 -> V_25 = NULL ;
break;
}
} else {
* F_18 ( V_9 -> V_25 , 1 ) = F_2 ( V_1 + V_33 ) ;
V_9 -> V_28 -- ;
if ( V_9 -> V_28 == 0 ) {
int V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
switch ( V_9 -> V_26 ) {
case V_35 :
V_48 = V_47 ( V_9 -> V_25 ) ;
V_9 -> V_26 = V_53 ;
V_9 -> V_28 = V_48 -> V_54 ;
break;
case V_38 :
V_50 = V_49 ( V_9 -> V_25 ) ;
V_46 = F_19 ( V_50 -> V_46 ) ;
V_9 -> V_26 = V_53 ;
V_9 -> V_28 = V_46 ;
break;
case V_41 :
V_52 = V_51 ( V_9 -> V_25 ) ;
V_9 -> V_26 = V_53 ;
V_9 -> V_28 = V_52 -> V_46 ;
break;
case V_53 :
F_20 ( V_9 -> V_25 ) ;
V_9 -> V_25 = NULL ;
break;
}
}
}
if ( V_23 ++ > 16 )
break;
} while ( F_2 ( V_1 + V_6 ) & V_55 );
}
static T_3 F_21 ( int V_56 , void * V_57 )
{
T_2 * V_9 = V_57 ;
unsigned int V_1 ;
int V_23 = 0 ;
int V_58 , V_59 ;
T_3 V_60 = V_61 ;
if ( ! V_9 || ! V_9 -> V_20 )
return V_61 ;
V_1 = V_9 -> V_13 -> V_14 [ 0 ] -> V_15 ;
F_22 ( & ( V_9 -> V_62 ) ) ;
V_58 = F_2 ( V_1 + V_63 ) & V_64 ;
while ( V_58 ) {
V_60 = V_65 ;
V_59 = F_2 ( V_1 + V_6 ) ;
switch ( V_58 ) {
case V_66 :
F_5 ( L_4 ) ;
break;
case V_67 :
F_15 ( V_9 ) ;
break;
case V_68 :
if ( V_59 & V_7 ) {
F_4 ( V_9 ) ;
}
break;
default:
F_5 ( L_5 , V_58 ) ;
break;
}
if ( V_23 ++ > 100 )
break;
V_58 = F_2 ( V_1 + V_63 ) & V_64 ;
}
F_23 ( & ( V_9 -> V_62 ) ) ;
return V_60 ;
}
static void F_24 ( T_2 * V_9 , unsigned int V_69 )
{
unsigned long V_45 ;
unsigned int V_1 ;
int V_70 ;
int V_71 ;
int V_72 ;
if ( ! V_9 ) {
F_5 ( L_1 ) ;
return;
}
V_1 = V_9 -> V_13 -> V_14 [ 0 ] -> V_15 ;
F_25 ( & ( V_9 -> V_62 ) , V_45 ) ;
F_3 ( 0 , V_1 + V_73 ) ;
V_72 = V_74 / V_69 ;
V_70 = V_75 | V_76 | V_77 ;
if ( V_69 < 38400 )
V_70 |= V_78 ;
else
V_70 |= V_79 ;
V_71 = V_80 ;
F_3 ( V_81 | V_71 , V_1 + V_82 ) ;
F_3 ( V_72 & 0xff , V_1 + V_83 ) ;
F_3 ( V_72 >> 8 , V_1 + V_84 ) ;
F_3 ( V_71 , V_1 + V_82 ) ;
F_3 ( V_70 , V_1 + V_85 ) ;
F_3 ( V_86 | V_87 | V_88 , V_1 + V_73 ) ;
F_26 ( & ( V_9 -> V_62 ) , V_45 ) ;
}
static int F_27 ( struct V_89 * V_20 )
{
T_2 * V_9 = ( T_2 * ) ( V_20 -> V_90 ) ;
F_28 ( & ( V_9 -> V_18 ) ) ;
return 0 ;
}
static int F_29 ( struct V_89 * V_20 )
{
F_7 ( V_44 , & ( V_20 -> V_45 ) ) ;
return 0 ;
}
static int F_30 ( struct V_89 * V_20 )
{
if ( ! F_31 ( V_44 , & ( V_20 -> V_45 ) ) )
return 0 ;
F_27 ( V_20 ) ;
return 0 ;
}
static int F_32 ( struct V_16 * V_17 )
{
T_2 * V_9 ;
struct V_89 * V_20 = (struct V_89 * ) ( V_17 -> V_31 ) ;
if ( ! V_20 ) {
F_5 ( L_6 ) ;
return - V_91 ;
}
V_9 = ( T_2 * ) ( V_20 -> V_90 ) ;
switch ( F_17 ( V_17 ) -> V_32 ) {
case V_92 :
V_20 -> V_21 . V_93 ++ ;
break;
case V_37 :
V_20 -> V_21 . V_94 ++ ;
break;
case V_40 :
V_20 -> V_21 . V_95 ++ ;
break;
} ;
memcpy ( F_33 ( V_17 , 1 ) , & F_17 ( V_17 ) -> V_32 , 1 ) ;
F_34 ( & ( V_9 -> V_18 ) , V_17 ) ;
F_4 ( V_9 ) ;
return 0 ;
}
static void F_35 ( struct V_89 * V_20 )
{
}
static int F_36 ( struct V_89 * V_20 , unsigned int V_96 , unsigned long V_97 )
{
return - V_98 ;
}
static int F_37 ( T_2 * V_9 )
{
unsigned long V_45 ;
unsigned int V_1 = V_9 -> V_13 -> V_14 [ 0 ] -> V_15 ;
struct V_89 * V_20 ;
F_38 ( & ( V_9 -> V_62 ) ) ;
F_39 ( & ( V_9 -> V_18 ) ) ;
V_9 -> V_26 = V_27 ;
V_9 -> V_28 = 0 ;
V_9 -> V_25 = NULL ;
V_20 = F_40 () ;
if ( ! V_20 ) {
F_5 ( L_7 ) ;
return - V_99 ;
}
V_9 -> V_20 = V_20 ;
V_20 -> V_100 = V_101 ;
V_20 -> V_90 = V_9 ;
F_41 ( V_20 , & V_9 -> V_13 -> V_31 ) ;
V_20 -> V_102 = F_29 ;
V_20 -> V_103 = F_30 ;
V_20 -> V_104 = F_27 ;
V_20 -> V_105 = F_32 ;
V_20 -> V_106 = F_35 ;
V_20 -> V_107 = F_36 ;
V_20 -> V_108 = V_109 ;
F_25 ( & ( V_9 -> V_62 ) , V_45 ) ;
F_3 ( 0 , V_1 + V_110 ) ;
F_3 ( 0 , V_1 + V_73 ) ;
F_3 ( V_80 , V_1 + V_82 ) ;
F_3 ( ( V_111 | V_112 | V_113 ) , V_1 + V_110 ) ;
F_26 ( & ( V_9 -> V_62 ) , V_45 ) ;
F_24 ( V_9 , V_114 ) ;
F_42 ( 1000 ) ;
if ( F_43 ( V_20 ) < 0 ) {
F_5 ( L_8 ) ;
V_9 -> V_20 = NULL ;
F_44 ( V_20 ) ;
return - V_91 ;
}
return 0 ;
}
static int F_45 ( T_2 * V_9 )
{
unsigned long V_45 ;
unsigned int V_1 = V_9 -> V_13 -> V_14 [ 0 ] -> V_15 ;
struct V_89 * V_20 = V_9 -> V_20 ;
if ( ! V_20 )
return - V_91 ;
F_30 ( V_20 ) ;
F_25 ( & ( V_9 -> V_62 ) , V_45 ) ;
F_3 ( 0 , V_1 + V_110 ) ;
F_3 ( 0 , V_1 + V_73 ) ;
F_26 ( & ( V_9 -> V_62 ) , V_45 ) ;
F_46 ( V_20 ) ;
F_44 ( V_20 ) ;
return 0 ;
}
static int F_47 ( struct V_115 * V_116 )
{
T_2 * V_9 ;
V_9 = F_48 ( sizeof( * V_9 ) , V_117 ) ;
if ( ! V_9 )
return - V_99 ;
V_9 -> V_13 = V_116 ;
V_116 -> V_118 = V_9 ;
V_116 -> V_119 |= V_120 | V_121 |
V_122 ;
return F_49 ( V_116 ) ;
}
static void F_50 ( struct V_115 * V_116 )
{
T_2 * V_9 = V_116 -> V_118 ;
F_51 ( V_116 ) ;
F_52 ( V_9 ) ;
}
static int F_53 ( struct V_115 * V_13 , void * V_123 )
{
int * V_124 = V_123 ;
if ( V_124 == 0 )
V_13 -> V_125 = 16 ;
if ( ( V_13 -> V_14 [ 0 ] -> V_126 != 8 ) || ( V_13 -> V_14 [ 0 ] -> V_15 == 0 ) )
return - V_127 ;
V_13 -> V_14 [ 0 ] -> V_126 = 8 ;
V_13 -> V_14 [ 0 ] -> V_45 &= ~ V_128 ;
V_13 -> V_14 [ 0 ] -> V_45 |= V_129 ;
return F_54 ( V_13 ) ;
}
static int F_55 ( struct V_115 * V_13 ,
void * V_123 )
{
static unsigned int V_130 [ 5 ] = { 0x3f8 , 0x2f8 , 0x3e8 , 0x2e8 , 0x0 } ;
int V_131 ;
if ( V_13 -> V_125 > 3 )
return - V_91 ;
V_13 -> V_14 [ 0 ] -> V_45 &= ~ V_128 ;
V_13 -> V_14 [ 0 ] -> V_45 |= V_129 ;
V_13 -> V_14 [ 0 ] -> V_126 = 8 ;
for ( V_131 = 0 ; V_131 < 5 ; V_131 ++ ) {
V_13 -> V_14 [ 0 ] -> V_15 = V_130 [ V_131 ] ;
V_13 -> V_125 = V_130 [ V_131 ] ? 16 : 3 ;
if ( ! F_54 ( V_13 ) )
return 0 ;
}
return - V_91 ;
}
static int F_49 ( struct V_115 * V_116 )
{
T_2 * V_9 = V_116 -> V_118 ;
int V_132 ;
int V_124 ;
for ( V_124 = 0 ; V_124 < 2 ; V_124 ++ )
if ( ! F_56 ( V_116 , F_53 , & V_124 ) )
goto V_133;
if ( ! F_56 ( V_116 , F_55 , NULL ) )
goto V_133;
F_5 ( L_9 ) ;
goto V_134;
V_133:
V_132 = F_57 ( V_116 , F_21 ) ;
if ( V_132 != 0 )
goto V_134;
V_132 = F_58 ( V_116 ) ;
if ( V_132 != 0 )
goto V_134;
if ( F_37 ( V_9 ) != 0 )
goto V_134;
return 0 ;
V_134:
F_51 ( V_116 ) ;
return - V_91 ;
}
static void F_51 ( struct V_115 * V_116 )
{
T_2 * V_9 = V_116 -> V_118 ;
F_45 ( V_9 ) ;
F_59 ( V_116 ) ;
}
static int T_4 F_60 ( void )
{
return F_61 ( & V_135 ) ;
}
static void T_5 F_62 ( void )
{
F_63 ( & V_135 ) ;
}
