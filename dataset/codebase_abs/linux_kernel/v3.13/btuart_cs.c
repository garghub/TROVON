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
F_17 ( V_9 -> V_25 ) -> V_31 = F_2 ( V_1 + V_32 ) ;
switch ( F_17 ( V_9 -> V_25 ) -> V_31 ) {
case V_33 :
V_9 -> V_26 = V_34 ;
V_9 -> V_28 = V_35 ;
break;
case V_36 :
V_9 -> V_26 = V_37 ;
V_9 -> V_28 = V_38 ;
break;
case V_39 :
V_9 -> V_26 = V_40 ;
V_9 -> V_28 = V_41 ;
break;
default:
F_5 ( L_3 , F_17 ( V_9 -> V_25 ) -> V_31 ) ;
V_9 -> V_20 -> V_21 . V_42 ++ ;
F_8 ( V_43 , & ( V_9 -> V_20 -> V_44 ) ) ;
F_11 ( V_9 -> V_25 ) ;
V_9 -> V_25 = NULL ;
break;
}
} else {
* F_18 ( V_9 -> V_25 , 1 ) = F_2 ( V_1 + V_32 ) ;
V_9 -> V_28 -- ;
if ( V_9 -> V_28 == 0 ) {
int V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
switch ( V_9 -> V_26 ) {
case V_34 :
V_47 = V_46 ( V_9 -> V_25 ) ;
V_9 -> V_26 = V_52 ;
V_9 -> V_28 = V_47 -> V_53 ;
break;
case V_37 :
V_49 = V_48 ( V_9 -> V_25 ) ;
V_45 = F_19 ( V_49 -> V_45 ) ;
V_9 -> V_26 = V_52 ;
V_9 -> V_28 = V_45 ;
break;
case V_40 :
V_51 = V_50 ( V_9 -> V_25 ) ;
V_9 -> V_26 = V_52 ;
V_9 -> V_28 = V_51 -> V_45 ;
break;
case V_52 :
F_20 ( V_9 -> V_20 , V_9 -> V_25 ) ;
V_9 -> V_25 = NULL ;
break;
}
}
}
if ( V_23 ++ > 16 )
break;
} while ( F_2 ( V_1 + V_6 ) & V_54 );
}
static T_3 F_21 ( int V_55 , void * V_56 )
{
T_2 * V_9 = V_56 ;
unsigned int V_1 ;
int V_23 = 0 ;
int V_57 , V_58 ;
T_3 V_59 = V_60 ;
if ( ! V_9 || ! V_9 -> V_20 )
return V_60 ;
V_1 = V_9 -> V_13 -> V_14 [ 0 ] -> V_15 ;
F_22 ( & ( V_9 -> V_61 ) ) ;
V_57 = F_2 ( V_1 + V_62 ) & V_63 ;
while ( V_57 ) {
V_59 = V_64 ;
V_58 = F_2 ( V_1 + V_6 ) ;
switch ( V_57 ) {
case V_65 :
F_5 ( L_4 ) ;
break;
case V_66 :
F_15 ( V_9 ) ;
break;
case V_67 :
if ( V_58 & V_7 ) {
F_4 ( V_9 ) ;
}
break;
default:
F_5 ( L_5 , V_57 ) ;
break;
}
if ( V_23 ++ > 100 )
break;
V_57 = F_2 ( V_1 + V_62 ) & V_63 ;
}
F_23 ( & ( V_9 -> V_61 ) ) ;
return V_59 ;
}
static void F_24 ( T_2 * V_9 , unsigned int V_68 )
{
unsigned long V_44 ;
unsigned int V_1 ;
int V_69 ;
int V_70 ;
int V_71 ;
if ( ! V_9 ) {
F_5 ( L_1 ) ;
return;
}
V_1 = V_9 -> V_13 -> V_14 [ 0 ] -> V_15 ;
F_25 ( & ( V_9 -> V_61 ) , V_44 ) ;
F_3 ( 0 , V_1 + V_72 ) ;
V_71 = V_73 / V_68 ;
V_69 = V_74 | V_75 | V_76 ;
if ( V_68 < 38400 )
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
F_26 ( & ( V_9 -> V_61 ) , V_44 ) ;
}
static int F_27 ( struct V_88 * V_20 )
{
T_2 * V_9 = F_28 ( V_20 ) ;
F_29 ( & ( V_9 -> V_18 ) ) ;
return 0 ;
}
static int F_30 ( struct V_88 * V_20 )
{
F_7 ( V_43 , & ( V_20 -> V_44 ) ) ;
return 0 ;
}
static int F_31 ( struct V_88 * V_20 )
{
if ( ! F_32 ( V_43 , & ( V_20 -> V_44 ) ) )
return 0 ;
F_27 ( V_20 ) ;
return 0 ;
}
static int F_33 ( struct V_88 * V_20 , struct V_16 * V_17 )
{
T_2 * V_9 = F_28 ( V_20 ) ;
switch ( F_17 ( V_17 ) -> V_31 ) {
case V_89 :
V_20 -> V_21 . V_90 ++ ;
break;
case V_36 :
V_20 -> V_21 . V_91 ++ ;
break;
case V_39 :
V_20 -> V_21 . V_92 ++ ;
break;
}
memcpy ( F_34 ( V_17 , 1 ) , & F_17 ( V_17 ) -> V_31 , 1 ) ;
F_35 ( & ( V_9 -> V_18 ) , V_17 ) ;
F_4 ( V_9 ) ;
return 0 ;
}
static int F_36 ( T_2 * V_9 )
{
unsigned long V_44 ;
unsigned int V_1 = V_9 -> V_13 -> V_14 [ 0 ] -> V_15 ;
struct V_88 * V_20 ;
F_37 ( & ( V_9 -> V_61 ) ) ;
F_38 ( & ( V_9 -> V_18 ) ) ;
V_9 -> V_26 = V_27 ;
V_9 -> V_28 = 0 ;
V_9 -> V_25 = NULL ;
V_20 = F_39 () ;
if ( ! V_20 ) {
F_5 ( L_6 ) ;
return - V_93 ;
}
V_9 -> V_20 = V_20 ;
V_20 -> V_94 = V_95 ;
F_40 ( V_20 , V_9 ) ;
F_41 ( V_20 , & V_9 -> V_13 -> V_96 ) ;
V_20 -> V_97 = F_30 ;
V_20 -> V_98 = F_31 ;
V_20 -> V_99 = F_27 ;
V_20 -> V_100 = F_33 ;
F_25 ( & ( V_9 -> V_61 ) , V_44 ) ;
F_3 ( 0 , V_1 + V_101 ) ;
F_3 ( 0 , V_1 + V_72 ) ;
F_3 ( V_79 , V_1 + V_81 ) ;
F_3 ( ( V_102 | V_103 | V_104 ) , V_1 + V_101 ) ;
F_26 ( & ( V_9 -> V_61 ) , V_44 ) ;
F_24 ( V_9 , V_105 ) ;
F_42 ( 1000 ) ;
if ( F_43 ( V_20 ) < 0 ) {
F_5 ( L_7 ) ;
V_9 -> V_20 = NULL ;
F_44 ( V_20 ) ;
return - V_106 ;
}
return 0 ;
}
static int F_45 ( T_2 * V_9 )
{
unsigned long V_44 ;
unsigned int V_1 = V_9 -> V_13 -> V_14 [ 0 ] -> V_15 ;
struct V_88 * V_20 = V_9 -> V_20 ;
if ( ! V_20 )
return - V_106 ;
F_31 ( V_20 ) ;
F_25 ( & ( V_9 -> V_61 ) , V_44 ) ;
F_3 ( 0 , V_1 + V_101 ) ;
F_3 ( 0 , V_1 + V_72 ) ;
F_26 ( & ( V_9 -> V_61 ) , V_44 ) ;
F_46 ( V_20 ) ;
F_44 ( V_20 ) ;
return 0 ;
}
static int F_47 ( struct V_107 * V_108 )
{
T_2 * V_9 ;
V_9 = F_48 ( & V_108 -> V_96 , sizeof( * V_9 ) , V_109 ) ;
if ( ! V_9 )
return - V_93 ;
V_9 -> V_13 = V_108 ;
V_108 -> V_110 = V_9 ;
V_108 -> V_111 |= V_112 | V_113 |
V_114 ;
return F_49 ( V_108 ) ;
}
static void F_50 ( struct V_107 * V_108 )
{
F_51 ( V_108 ) ;
}
static int F_52 ( struct V_107 * V_13 , void * V_115 )
{
int * V_116 = V_115 ;
if ( ! V_116 )
V_13 -> V_117 = 16 ;
if ( ( V_13 -> V_14 [ 0 ] -> V_118 != 8 ) || ( V_13 -> V_14 [ 0 ] -> V_15 == 0 ) )
return - V_119 ;
V_13 -> V_14 [ 0 ] -> V_118 = 8 ;
V_13 -> V_14 [ 0 ] -> V_44 &= ~ V_120 ;
V_13 -> V_14 [ 0 ] -> V_44 |= V_121 ;
return F_53 ( V_13 ) ;
}
static int F_54 ( struct V_107 * V_13 ,
void * V_115 )
{
static unsigned int V_122 [ 5 ] = { 0x3f8 , 0x2f8 , 0x3e8 , 0x2e8 , 0x0 } ;
int V_123 ;
if ( V_13 -> V_117 > 3 )
return - V_106 ;
V_13 -> V_14 [ 0 ] -> V_44 &= ~ V_120 ;
V_13 -> V_14 [ 0 ] -> V_44 |= V_121 ;
V_13 -> V_14 [ 0 ] -> V_118 = 8 ;
for ( V_123 = 0 ; V_123 < 5 ; V_123 ++ ) {
V_13 -> V_14 [ 0 ] -> V_15 = V_122 [ V_123 ] ;
V_13 -> V_117 = V_122 [ V_123 ] ? 16 : 3 ;
if ( ! F_53 ( V_13 ) )
return 0 ;
}
return - V_106 ;
}
static int F_49 ( struct V_107 * V_108 )
{
T_2 * V_9 = V_108 -> V_110 ;
int V_124 ;
int V_116 ;
for ( V_116 = 0 ; V_116 < 2 ; V_116 ++ )
if ( ! F_55 ( V_108 , F_52 , & V_116 ) )
goto V_125;
if ( ! F_55 ( V_108 , F_54 , NULL ) )
goto V_125;
F_5 ( L_8 ) ;
goto V_126;
V_125:
V_124 = F_56 ( V_108 , F_21 ) ;
if ( V_124 != 0 )
goto V_126;
V_124 = F_57 ( V_108 ) ;
if ( V_124 != 0 )
goto V_126;
if ( F_36 ( V_9 ) != 0 )
goto V_126;
return 0 ;
V_126:
F_51 ( V_108 ) ;
return - V_106 ;
}
static void F_51 ( struct V_107 * V_108 )
{
T_2 * V_9 = V_108 -> V_110 ;
F_45 ( V_9 ) ;
F_58 ( V_108 ) ;
}
