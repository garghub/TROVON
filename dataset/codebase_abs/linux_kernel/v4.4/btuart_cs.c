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
static void F_4 ( struct V_9 * V_10 )
{
if ( ! V_10 ) {
F_5 ( L_1 ) ;
return;
}
if ( F_6 ( V_11 , & ( V_10 -> V_12 ) ) ) {
F_7 ( V_13 , & ( V_10 -> V_12 ) ) ;
return;
}
do {
unsigned int V_1 = V_10 -> V_14 -> V_15 [ 0 ] -> V_16 ;
register struct V_17 * V_18 ;
int V_4 ;
F_8 ( V_13 , & ( V_10 -> V_12 ) ) ;
if ( ! F_9 ( V_10 -> V_14 ) )
return;
V_18 = F_10 ( & ( V_10 -> V_19 ) ) ;
if ( ! V_18 )
break;
V_4 = F_1 ( V_1 , 16 , V_18 -> V_20 , V_18 -> V_4 ) ;
F_7 ( V_13 , & ( V_10 -> V_12 ) ) ;
if ( V_4 == V_18 -> V_4 ) {
F_11 ( V_18 ) ;
} else {
F_12 ( V_18 , V_4 ) ;
F_13 ( & ( V_10 -> V_19 ) , V_18 ) ;
}
V_10 -> V_21 -> V_22 . V_23 += V_4 ;
} while ( F_14 ( V_13 , & ( V_10 -> V_12 ) ) );
F_8 ( V_11 , & ( V_10 -> V_12 ) ) ;
}
static void F_15 ( struct V_9 * V_10 )
{
unsigned int V_1 ;
int V_24 = 0 ;
if ( ! V_10 ) {
F_5 ( L_1 ) ;
return;
}
V_1 = V_10 -> V_14 -> V_15 [ 0 ] -> V_16 ;
do {
V_10 -> V_21 -> V_22 . V_25 ++ ;
if ( ! V_10 -> V_26 ) {
V_10 -> V_27 = V_28 ;
V_10 -> V_29 = 0 ;
V_10 -> V_26 = F_16 ( V_30 , V_31 ) ;
if ( ! V_10 -> V_26 ) {
F_5 ( L_2 ) ;
return;
}
}
if ( V_10 -> V_27 == V_28 ) {
F_17 ( V_10 -> V_26 ) -> V_32 = F_2 ( V_1 + V_33 ) ;
switch ( F_17 ( V_10 -> V_26 ) -> V_32 ) {
case V_34 :
V_10 -> V_27 = V_35 ;
V_10 -> V_29 = V_36 ;
break;
case V_37 :
V_10 -> V_27 = V_38 ;
V_10 -> V_29 = V_39 ;
break;
case V_40 :
V_10 -> V_27 = V_41 ;
V_10 -> V_29 = V_42 ;
break;
default:
F_5 ( L_3 , F_17 ( V_10 -> V_26 ) -> V_32 ) ;
V_10 -> V_21 -> V_22 . V_43 ++ ;
F_11 ( V_10 -> V_26 ) ;
V_10 -> V_26 = NULL ;
break;
}
} else {
* F_18 ( V_10 -> V_26 , 1 ) = F_2 ( V_1 + V_33 ) ;
V_10 -> V_29 -- ;
if ( V_10 -> V_29 == 0 ) {
int V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
switch ( V_10 -> V_27 ) {
case V_35 :
V_46 = V_45 ( V_10 -> V_26 ) ;
V_10 -> V_27 = V_51 ;
V_10 -> V_29 = V_46 -> V_52 ;
break;
case V_38 :
V_48 = V_47 ( V_10 -> V_26 ) ;
V_44 = F_19 ( V_48 -> V_44 ) ;
V_10 -> V_27 = V_51 ;
V_10 -> V_29 = V_44 ;
break;
case V_41 :
V_50 = V_49 ( V_10 -> V_26 ) ;
V_10 -> V_27 = V_51 ;
V_10 -> V_29 = V_50 -> V_44 ;
break;
case V_51 :
F_20 ( V_10 -> V_21 , V_10 -> V_26 ) ;
V_10 -> V_26 = NULL ;
break;
}
}
}
if ( V_24 ++ > 16 )
break;
} while ( F_2 ( V_1 + V_6 ) & V_53 );
}
static T_2 F_21 ( int V_54 , void * V_55 )
{
struct V_9 * V_10 = V_55 ;
unsigned int V_1 ;
int V_24 = 0 ;
int V_56 , V_57 ;
T_2 V_58 = V_59 ;
if ( ! V_10 || ! V_10 -> V_21 )
return V_59 ;
V_1 = V_10 -> V_14 -> V_15 [ 0 ] -> V_16 ;
F_22 ( & ( V_10 -> V_60 ) ) ;
V_56 = F_2 ( V_1 + V_61 ) & V_62 ;
while ( V_56 ) {
V_58 = V_63 ;
V_57 = F_2 ( V_1 + V_6 ) ;
switch ( V_56 ) {
case V_64 :
F_5 ( L_4 ) ;
break;
case V_65 :
F_15 ( V_10 ) ;
break;
case V_66 :
if ( V_57 & V_7 ) {
F_4 ( V_10 ) ;
}
break;
default:
F_5 ( L_5 , V_56 ) ;
break;
}
if ( V_24 ++ > 100 )
break;
V_56 = F_2 ( V_1 + V_61 ) & V_62 ;
}
F_23 ( & ( V_10 -> V_60 ) ) ;
return V_58 ;
}
static void F_24 ( struct V_9 * V_10 ,
unsigned int V_67 )
{
unsigned long V_68 ;
unsigned int V_1 ;
int V_69 ;
int V_70 ;
int V_71 ;
if ( ! V_10 ) {
F_5 ( L_1 ) ;
return;
}
V_1 = V_10 -> V_14 -> V_15 [ 0 ] -> V_16 ;
F_25 ( & ( V_10 -> V_60 ) , V_68 ) ;
F_3 ( 0 , V_1 + V_72 ) ;
V_71 = V_73 / V_67 ;
V_69 = V_74 | V_75 | V_76 ;
if ( V_67 < 38400 )
V_69 |= V_77 ;
else
V_69 |= V_78 ;
V_70 = V_79 ;
F_3 ( V_80 | V_70 , V_1 + V_81 ) ;
F_3 ( V_71 & 0xff , V_1 + V_82 ) ;
F_3 ( V_71 >> 8 , V_1 + V_83 ) ;
F_3 ( V_70 , V_1 + V_81 ) ;
F_3 ( V_69 , V_1 + V_84 ) ;
F_3 ( V_85 | V_86 | V_87 , V_1 + V_72 ) ;
F_26 ( & ( V_10 -> V_60 ) , V_68 ) ;
}
static int F_27 ( struct V_88 * V_21 )
{
struct V_9 * V_10 = F_28 ( V_21 ) ;
F_29 ( & ( V_10 -> V_19 ) ) ;
return 0 ;
}
static int F_30 ( struct V_88 * V_21 )
{
return 0 ;
}
static int F_31 ( struct V_88 * V_21 )
{
F_27 ( V_21 ) ;
return 0 ;
}
static int F_32 ( struct V_88 * V_21 , struct V_17 * V_18 )
{
struct V_9 * V_10 = F_28 ( V_21 ) ;
switch ( F_17 ( V_18 ) -> V_32 ) {
case V_89 :
V_21 -> V_22 . V_90 ++ ;
break;
case V_37 :
V_21 -> V_22 . V_91 ++ ;
break;
case V_40 :
V_21 -> V_22 . V_92 ++ ;
break;
}
memcpy ( F_33 ( V_18 , 1 ) , & F_17 ( V_18 ) -> V_32 , 1 ) ;
F_34 ( & ( V_10 -> V_19 ) , V_18 ) ;
F_4 ( V_10 ) ;
return 0 ;
}
static int F_35 ( struct V_9 * V_10 )
{
unsigned long V_68 ;
unsigned int V_1 = V_10 -> V_14 -> V_15 [ 0 ] -> V_16 ;
struct V_88 * V_21 ;
F_36 ( & ( V_10 -> V_60 ) ) ;
F_37 ( & ( V_10 -> V_19 ) ) ;
V_10 -> V_27 = V_28 ;
V_10 -> V_29 = 0 ;
V_10 -> V_26 = NULL ;
V_21 = F_38 () ;
if ( ! V_21 ) {
F_5 ( L_6 ) ;
return - V_93 ;
}
V_10 -> V_21 = V_21 ;
V_21 -> V_94 = V_95 ;
F_39 ( V_21 , V_10 ) ;
F_40 ( V_21 , & V_10 -> V_14 -> V_96 ) ;
V_21 -> V_97 = F_30 ;
V_21 -> V_98 = F_31 ;
V_21 -> V_99 = F_27 ;
V_21 -> V_100 = F_32 ;
F_25 ( & ( V_10 -> V_60 ) , V_68 ) ;
F_3 ( 0 , V_1 + V_101 ) ;
F_3 ( 0 , V_1 + V_72 ) ;
F_3 ( V_79 , V_1 + V_81 ) ;
F_3 ( ( V_102 | V_103 | V_104 ) , V_1 + V_101 ) ;
F_26 ( & ( V_10 -> V_60 ) , V_68 ) ;
F_24 ( V_10 , V_105 ) ;
F_41 ( 1000 ) ;
if ( F_42 ( V_21 ) < 0 ) {
F_5 ( L_7 ) ;
V_10 -> V_21 = NULL ;
F_43 ( V_21 ) ;
return - V_106 ;
}
return 0 ;
}
static int F_44 ( struct V_9 * V_10 )
{
unsigned long V_68 ;
unsigned int V_1 = V_10 -> V_14 -> V_15 [ 0 ] -> V_16 ;
struct V_88 * V_21 = V_10 -> V_21 ;
if ( ! V_21 )
return - V_106 ;
F_31 ( V_21 ) ;
F_25 ( & ( V_10 -> V_60 ) , V_68 ) ;
F_3 ( 0 , V_1 + V_101 ) ;
F_3 ( 0 , V_1 + V_72 ) ;
F_26 ( & ( V_10 -> V_60 ) , V_68 ) ;
F_45 ( V_21 ) ;
F_43 ( V_21 ) ;
return 0 ;
}
static int F_46 ( struct V_107 * V_108 )
{
struct V_9 * V_10 ;
V_10 = F_47 ( & V_108 -> V_96 , sizeof( * V_10 ) , V_109 ) ;
if ( ! V_10 )
return - V_93 ;
V_10 -> V_14 = V_108 ;
V_108 -> V_110 = V_10 ;
V_108 -> V_111 |= V_112 | V_113 |
V_114 ;
return F_48 ( V_108 ) ;
}
static void F_49 ( struct V_107 * V_108 )
{
F_50 ( V_108 ) ;
}
static int F_51 ( struct V_107 * V_14 , void * V_115 )
{
int * V_116 = V_115 ;
if ( ! V_116 )
V_14 -> V_117 = 16 ;
if ( ( V_14 -> V_15 [ 0 ] -> V_118 != 8 ) || ( V_14 -> V_15 [ 0 ] -> V_16 == 0 ) )
return - V_119 ;
V_14 -> V_15 [ 0 ] -> V_118 = 8 ;
V_14 -> V_15 [ 0 ] -> V_68 &= ~ V_120 ;
V_14 -> V_15 [ 0 ] -> V_68 |= V_121 ;
return F_52 ( V_14 ) ;
}
static int F_53 ( struct V_107 * V_14 ,
void * V_115 )
{
static unsigned int V_122 [ 5 ] = { 0x3f8 , 0x2f8 , 0x3e8 , 0x2e8 , 0x0 } ;
int V_123 ;
if ( V_14 -> V_117 > 3 )
return - V_106 ;
V_14 -> V_15 [ 0 ] -> V_68 &= ~ V_120 ;
V_14 -> V_15 [ 0 ] -> V_68 |= V_121 ;
V_14 -> V_15 [ 0 ] -> V_118 = 8 ;
for ( V_123 = 0 ; V_123 < 5 ; V_123 ++ ) {
V_14 -> V_15 [ 0 ] -> V_16 = V_122 [ V_123 ] ;
V_14 -> V_117 = V_122 [ V_123 ] ? 16 : 3 ;
if ( ! F_52 ( V_14 ) )
return 0 ;
}
return - V_106 ;
}
static int F_48 ( struct V_107 * V_108 )
{
struct V_9 * V_10 = V_108 -> V_110 ;
int V_124 ;
int V_116 ;
for ( V_116 = 0 ; V_116 < 2 ; V_116 ++ )
if ( ! F_54 ( V_108 , F_51 , & V_116 ) )
goto V_125;
if ( ! F_54 ( V_108 , F_53 , NULL ) )
goto V_125;
F_5 ( L_8 ) ;
goto V_126;
V_125:
V_124 = F_55 ( V_108 , F_21 ) ;
if ( V_124 != 0 )
goto V_126;
V_124 = F_56 ( V_108 ) ;
if ( V_124 != 0 )
goto V_126;
if ( F_35 ( V_10 ) != 0 )
goto V_126;
return 0 ;
V_126:
F_50 ( V_108 ) ;
return - V_106 ;
}
static void F_50 ( struct V_107 * V_108 )
{
struct V_9 * V_10 = V_108 -> V_110 ;
F_44 ( V_10 ) ;
F_57 ( V_108 ) ;
}
