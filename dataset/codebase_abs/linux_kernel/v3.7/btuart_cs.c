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
unsigned int V_1 = V_9 -> V_13 -> V_14 [ 0 ] -> V_15 ;
register struct V_16 * V_17 ;
int V_4 ;
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
T_2 * V_9 = F_28 ( V_20 ) ;
F_29 ( & ( V_9 -> V_18 ) ) ;
return 0 ;
}
static int F_30 ( struct V_89 * V_20 )
{
F_7 ( V_44 , & ( V_20 -> V_45 ) ) ;
return 0 ;
}
static int F_31 ( struct V_89 * V_20 )
{
if ( ! F_32 ( V_44 , & ( V_20 -> V_45 ) ) )
return 0 ;
F_27 ( V_20 ) ;
return 0 ;
}
static int F_33 ( struct V_16 * V_17 )
{
T_2 * V_9 ;
struct V_89 * V_20 = (struct V_89 * ) ( V_17 -> V_31 ) ;
if ( ! V_20 ) {
F_5 ( L_6 ) ;
return - V_90 ;
}
V_9 = F_28 ( V_20 ) ;
switch ( F_17 ( V_17 ) -> V_32 ) {
case V_91 :
V_20 -> V_21 . V_92 ++ ;
break;
case V_37 :
V_20 -> V_21 . V_93 ++ ;
break;
case V_40 :
V_20 -> V_21 . V_94 ++ ;
break;
}
memcpy ( F_34 ( V_17 , 1 ) , & F_17 ( V_17 ) -> V_32 , 1 ) ;
F_35 ( & ( V_9 -> V_18 ) , V_17 ) ;
F_4 ( V_9 ) ;
return 0 ;
}
static int F_36 ( struct V_89 * V_20 , unsigned int V_95 , unsigned long V_96 )
{
return - V_97 ;
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
return - V_98 ;
}
V_9 -> V_20 = V_20 ;
V_20 -> V_99 = V_100 ;
F_41 ( V_20 , V_9 ) ;
F_42 ( V_20 , & V_9 -> V_13 -> V_31 ) ;
V_20 -> V_101 = F_30 ;
V_20 -> V_102 = F_31 ;
V_20 -> V_103 = F_27 ;
V_20 -> V_104 = F_33 ;
V_20 -> V_105 = F_36 ;
F_25 ( & ( V_9 -> V_62 ) , V_45 ) ;
F_3 ( 0 , V_1 + V_106 ) ;
F_3 ( 0 , V_1 + V_73 ) ;
F_3 ( V_80 , V_1 + V_82 ) ;
F_3 ( ( V_107 | V_108 | V_109 ) , V_1 + V_106 ) ;
F_26 ( & ( V_9 -> V_62 ) , V_45 ) ;
F_24 ( V_9 , V_110 ) ;
F_43 ( 1000 ) ;
if ( F_44 ( V_20 ) < 0 ) {
F_5 ( L_8 ) ;
V_9 -> V_20 = NULL ;
F_45 ( V_20 ) ;
return - V_90 ;
}
return 0 ;
}
static int F_46 ( T_2 * V_9 )
{
unsigned long V_45 ;
unsigned int V_1 = V_9 -> V_13 -> V_14 [ 0 ] -> V_15 ;
struct V_89 * V_20 = V_9 -> V_20 ;
if ( ! V_20 )
return - V_90 ;
F_31 ( V_20 ) ;
F_25 ( & ( V_9 -> V_62 ) , V_45 ) ;
F_3 ( 0 , V_1 + V_106 ) ;
F_3 ( 0 , V_1 + V_73 ) ;
F_26 ( & ( V_9 -> V_62 ) , V_45 ) ;
F_47 ( V_20 ) ;
F_45 ( V_20 ) ;
return 0 ;
}
static int F_48 ( struct V_111 * V_112 )
{
T_2 * V_9 ;
V_9 = F_49 ( & V_112 -> V_31 , sizeof( * V_9 ) , V_113 ) ;
if ( ! V_9 )
return - V_98 ;
V_9 -> V_13 = V_112 ;
V_112 -> V_114 = V_9 ;
V_112 -> V_115 |= V_116 | V_117 |
V_118 ;
return F_50 ( V_112 ) ;
}
static void F_51 ( struct V_111 * V_112 )
{
F_52 ( V_112 ) ;
}
static int F_53 ( struct V_111 * V_13 , void * V_119 )
{
int * V_120 = V_119 ;
if ( ! V_120 )
V_13 -> V_121 = 16 ;
if ( ( V_13 -> V_14 [ 0 ] -> V_122 != 8 ) || ( V_13 -> V_14 [ 0 ] -> V_15 == 0 ) )
return - V_123 ;
V_13 -> V_14 [ 0 ] -> V_122 = 8 ;
V_13 -> V_14 [ 0 ] -> V_45 &= ~ V_124 ;
V_13 -> V_14 [ 0 ] -> V_45 |= V_125 ;
return F_54 ( V_13 ) ;
}
static int F_55 ( struct V_111 * V_13 ,
void * V_119 )
{
static unsigned int V_126 [ 5 ] = { 0x3f8 , 0x2f8 , 0x3e8 , 0x2e8 , 0x0 } ;
int V_127 ;
if ( V_13 -> V_121 > 3 )
return - V_90 ;
V_13 -> V_14 [ 0 ] -> V_45 &= ~ V_124 ;
V_13 -> V_14 [ 0 ] -> V_45 |= V_125 ;
V_13 -> V_14 [ 0 ] -> V_122 = 8 ;
for ( V_127 = 0 ; V_127 < 5 ; V_127 ++ ) {
V_13 -> V_14 [ 0 ] -> V_15 = V_126 [ V_127 ] ;
V_13 -> V_121 = V_126 [ V_127 ] ? 16 : 3 ;
if ( ! F_54 ( V_13 ) )
return 0 ;
}
return - V_90 ;
}
static int F_50 ( struct V_111 * V_112 )
{
T_2 * V_9 = V_112 -> V_114 ;
int V_128 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < 2 ; V_120 ++ )
if ( ! F_56 ( V_112 , F_53 , & V_120 ) )
goto V_129;
if ( ! F_56 ( V_112 , F_55 , NULL ) )
goto V_129;
F_5 ( L_9 ) ;
goto V_130;
V_129:
V_128 = F_57 ( V_112 , F_21 ) ;
if ( V_128 != 0 )
goto V_130;
V_128 = F_58 ( V_112 ) ;
if ( V_128 != 0 )
goto V_130;
if ( F_37 ( V_9 ) != 0 )
goto V_130;
return 0 ;
V_130:
F_52 ( V_112 ) ;
return - V_90 ;
}
static void F_52 ( struct V_111 * V_112 )
{
T_2 * V_9 = V_112 -> V_114 ;
F_46 ( V_9 ) ;
F_59 ( V_112 ) ;
}
static int T_4 F_60 ( void )
{
return F_61 ( & V_131 ) ;
}
static void T_5 F_62 ( void )
{
F_63 ( & V_131 ) ;
}
