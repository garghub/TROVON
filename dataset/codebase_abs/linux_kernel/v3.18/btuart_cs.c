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
if ( V_10 -> V_26 == NULL ) {
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
F_8 ( V_44 , & ( V_10 -> V_21 -> V_45 ) ) ;
F_11 ( V_10 -> V_26 ) ;
V_10 -> V_26 = NULL ;
break;
}
} else {
* F_18 ( V_10 -> V_26 , 1 ) = F_2 ( V_1 + V_33 ) ;
V_10 -> V_29 -- ;
if ( V_10 -> V_29 == 0 ) {
int V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
switch ( V_10 -> V_27 ) {
case V_35 :
V_48 = V_47 ( V_10 -> V_26 ) ;
V_10 -> V_27 = V_53 ;
V_10 -> V_29 = V_48 -> V_54 ;
break;
case V_38 :
V_50 = V_49 ( V_10 -> V_26 ) ;
V_46 = F_19 ( V_50 -> V_46 ) ;
V_10 -> V_27 = V_53 ;
V_10 -> V_29 = V_46 ;
break;
case V_41 :
V_52 = V_51 ( V_10 -> V_26 ) ;
V_10 -> V_27 = V_53 ;
V_10 -> V_29 = V_52 -> V_46 ;
break;
case V_53 :
F_20 ( V_10 -> V_21 , V_10 -> V_26 ) ;
V_10 -> V_26 = NULL ;
break;
}
}
}
if ( V_24 ++ > 16 )
break;
} while ( F_2 ( V_1 + V_6 ) & V_55 );
}
static T_2 F_21 ( int V_56 , void * V_57 )
{
struct V_9 * V_10 = V_57 ;
unsigned int V_1 ;
int V_24 = 0 ;
int V_58 , V_59 ;
T_2 V_60 = V_61 ;
if ( ! V_10 || ! V_10 -> V_21 )
return V_61 ;
V_1 = V_10 -> V_14 -> V_15 [ 0 ] -> V_16 ;
F_22 ( & ( V_10 -> V_62 ) ) ;
V_58 = F_2 ( V_1 + V_63 ) & V_64 ;
while ( V_58 ) {
V_60 = V_65 ;
V_59 = F_2 ( V_1 + V_6 ) ;
switch ( V_58 ) {
case V_66 :
F_5 ( L_4 ) ;
break;
case V_67 :
F_15 ( V_10 ) ;
break;
case V_68 :
if ( V_59 & V_7 ) {
F_4 ( V_10 ) ;
}
break;
default:
F_5 ( L_5 , V_58 ) ;
break;
}
if ( V_24 ++ > 100 )
break;
V_58 = F_2 ( V_1 + V_63 ) & V_64 ;
}
F_23 ( & ( V_10 -> V_62 ) ) ;
return V_60 ;
}
static void F_24 ( struct V_9 * V_10 ,
unsigned int V_69 )
{
unsigned long V_45 ;
unsigned int V_1 ;
int V_70 ;
int V_71 ;
int V_72 ;
if ( ! V_10 ) {
F_5 ( L_1 ) ;
return;
}
V_1 = V_10 -> V_14 -> V_15 [ 0 ] -> V_16 ;
F_25 ( & ( V_10 -> V_62 ) , V_45 ) ;
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
F_26 ( & ( V_10 -> V_62 ) , V_45 ) ;
}
static int F_27 ( struct V_89 * V_21 )
{
struct V_9 * V_10 = F_28 ( V_21 ) ;
F_29 ( & ( V_10 -> V_19 ) ) ;
return 0 ;
}
static int F_30 ( struct V_89 * V_21 )
{
F_7 ( V_44 , & ( V_21 -> V_45 ) ) ;
return 0 ;
}
static int F_31 ( struct V_89 * V_21 )
{
if ( ! F_32 ( V_44 , & ( V_21 -> V_45 ) ) )
return 0 ;
F_27 ( V_21 ) ;
return 0 ;
}
static int F_33 ( struct V_89 * V_21 , struct V_17 * V_18 )
{
struct V_9 * V_10 = F_28 ( V_21 ) ;
switch ( F_17 ( V_18 ) -> V_32 ) {
case V_90 :
V_21 -> V_22 . V_91 ++ ;
break;
case V_37 :
V_21 -> V_22 . V_92 ++ ;
break;
case V_40 :
V_21 -> V_22 . V_93 ++ ;
break;
}
memcpy ( F_34 ( V_18 , 1 ) , & F_17 ( V_18 ) -> V_32 , 1 ) ;
F_35 ( & ( V_10 -> V_19 ) , V_18 ) ;
F_4 ( V_10 ) ;
return 0 ;
}
static int F_36 ( struct V_9 * V_10 )
{
unsigned long V_45 ;
unsigned int V_1 = V_10 -> V_14 -> V_15 [ 0 ] -> V_16 ;
struct V_89 * V_21 ;
F_37 ( & ( V_10 -> V_62 ) ) ;
F_38 ( & ( V_10 -> V_19 ) ) ;
V_10 -> V_27 = V_28 ;
V_10 -> V_29 = 0 ;
V_10 -> V_26 = NULL ;
V_21 = F_39 () ;
if ( ! V_21 ) {
F_5 ( L_6 ) ;
return - V_94 ;
}
V_10 -> V_21 = V_21 ;
V_21 -> V_95 = V_96 ;
F_40 ( V_21 , V_10 ) ;
F_41 ( V_21 , & V_10 -> V_14 -> V_97 ) ;
V_21 -> V_98 = F_30 ;
V_21 -> V_99 = F_31 ;
V_21 -> V_100 = F_27 ;
V_21 -> V_101 = F_33 ;
F_25 ( & ( V_10 -> V_62 ) , V_45 ) ;
F_3 ( 0 , V_1 + V_102 ) ;
F_3 ( 0 , V_1 + V_73 ) ;
F_3 ( V_80 , V_1 + V_82 ) ;
F_3 ( ( V_103 | V_104 | V_105 ) , V_1 + V_102 ) ;
F_26 ( & ( V_10 -> V_62 ) , V_45 ) ;
F_24 ( V_10 , V_106 ) ;
F_42 ( 1000 ) ;
if ( F_43 ( V_21 ) < 0 ) {
F_5 ( L_7 ) ;
V_10 -> V_21 = NULL ;
F_44 ( V_21 ) ;
return - V_107 ;
}
return 0 ;
}
static int F_45 ( struct V_9 * V_10 )
{
unsigned long V_45 ;
unsigned int V_1 = V_10 -> V_14 -> V_15 [ 0 ] -> V_16 ;
struct V_89 * V_21 = V_10 -> V_21 ;
if ( ! V_21 )
return - V_107 ;
F_31 ( V_21 ) ;
F_25 ( & ( V_10 -> V_62 ) , V_45 ) ;
F_3 ( 0 , V_1 + V_102 ) ;
F_3 ( 0 , V_1 + V_73 ) ;
F_26 ( & ( V_10 -> V_62 ) , V_45 ) ;
F_46 ( V_21 ) ;
F_44 ( V_21 ) ;
return 0 ;
}
static int F_47 ( struct V_108 * V_109 )
{
struct V_9 * V_10 ;
V_10 = F_48 ( & V_109 -> V_97 , sizeof( * V_10 ) , V_110 ) ;
if ( ! V_10 )
return - V_94 ;
V_10 -> V_14 = V_109 ;
V_109 -> V_111 = V_10 ;
V_109 -> V_112 |= V_113 | V_114 |
V_115 ;
return F_49 ( V_109 ) ;
}
static void F_50 ( struct V_108 * V_109 )
{
F_51 ( V_109 ) ;
}
static int F_52 ( struct V_108 * V_14 , void * V_116 )
{
int * V_117 = V_116 ;
if ( ! V_117 )
V_14 -> V_118 = 16 ;
if ( ( V_14 -> V_15 [ 0 ] -> V_119 != 8 ) || ( V_14 -> V_15 [ 0 ] -> V_16 == 0 ) )
return - V_120 ;
V_14 -> V_15 [ 0 ] -> V_119 = 8 ;
V_14 -> V_15 [ 0 ] -> V_45 &= ~ V_121 ;
V_14 -> V_15 [ 0 ] -> V_45 |= V_122 ;
return F_53 ( V_14 ) ;
}
static int F_54 ( struct V_108 * V_14 ,
void * V_116 )
{
static unsigned int V_123 [ 5 ] = { 0x3f8 , 0x2f8 , 0x3e8 , 0x2e8 , 0x0 } ;
int V_124 ;
if ( V_14 -> V_118 > 3 )
return - V_107 ;
V_14 -> V_15 [ 0 ] -> V_45 &= ~ V_121 ;
V_14 -> V_15 [ 0 ] -> V_45 |= V_122 ;
V_14 -> V_15 [ 0 ] -> V_119 = 8 ;
for ( V_124 = 0 ; V_124 < 5 ; V_124 ++ ) {
V_14 -> V_15 [ 0 ] -> V_16 = V_123 [ V_124 ] ;
V_14 -> V_118 = V_123 [ V_124 ] ? 16 : 3 ;
if ( ! F_53 ( V_14 ) )
return 0 ;
}
return - V_107 ;
}
static int F_49 ( struct V_108 * V_109 )
{
struct V_9 * V_10 = V_109 -> V_111 ;
int V_125 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < 2 ; V_117 ++ )
if ( ! F_55 ( V_109 , F_52 , & V_117 ) )
goto V_126;
if ( ! F_55 ( V_109 , F_54 , NULL ) )
goto V_126;
F_5 ( L_8 ) ;
goto V_127;
V_126:
V_125 = F_56 ( V_109 , F_21 ) ;
if ( V_125 != 0 )
goto V_127;
V_125 = F_57 ( V_109 ) ;
if ( V_125 != 0 )
goto V_127;
if ( F_36 ( V_10 ) != 0 )
goto V_127;
return 0 ;
V_127:
F_51 ( V_109 ) ;
return - V_107 ;
}
static void F_51 ( struct V_108 * V_109 )
{
struct V_9 * V_10 = V_109 -> V_111 ;
F_45 ( V_10 ) ;
F_58 ( V_109 ) ;
}
