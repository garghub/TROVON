static void F_1 ( struct V_1 * V_2 , int V_3 , unsigned char V_4 )
{
if ( V_3 == V_5 )
V_4 |= V_2 -> V_6 ;
F_2 ( V_4 , V_2 -> V_7 + V_3 ) ;
}
static unsigned char F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_7 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_8 , unsigned char V_9 )
{
F_1 ( V_2 , V_3 , ( F_3 ( V_2 , V_3 ) | V_8 ) & ~ V_9 ) ;
}
static T_1 F_6 ( unsigned long V_10 , T_1 V_11 , T_1 V_12 , int V_13 )
{
return ( ( ( V_10 * ( V_11 + V_12 ) ) + 5000 ) / 10000 ) + V_13 ;
}
static T_1 F_7 ( unsigned long V_10 , T_1 V_14 , T_1 V_12 , int V_13 )
{
return ( ( ( V_10 * ( V_14 + V_12 ) ) + 5000 ) / 10000 ) + V_13 ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned long V_15 ;
T_1 V_14 , V_11 , V_12 ;
int V_13 ;
F_9 ( V_2 -> V_16 ) ;
V_15 = F_10 ( V_2 -> V_16 ) / 1000 ;
V_15 /= V_2 -> V_17 ;
if ( V_2 -> V_18 == V_19 ) {
V_11 = 47 ;
V_14 = 40 ;
V_12 = 3 ;
V_13 = 0 ;
} else if ( V_2 -> V_18 == V_20 ) {
V_11 = 13 ;
V_14 = 6 ;
V_12 = 3 ;
V_13 = 0 ;
} else {
F_11 ( V_2 -> V_21 , L_1 ,
V_2 -> V_18 ) ;
goto V_22;
}
V_2 -> V_23 = F_6 ( V_15 , V_11 , V_12 , V_13 ) ;
if ( ( V_2 -> V_23 > 0xff ) && ( V_2 -> V_24 & V_25 ) )
V_2 -> V_6 |= V_26 ;
else
V_2 -> V_6 &= ~ V_26 ;
V_2 -> V_27 = F_7 ( V_15 , V_14 , V_12 , V_13 ) ;
if ( ( V_2 -> V_27 > 0xff ) && ( V_2 -> V_24 & V_25 ) )
V_2 -> V_6 |= V_28 ;
else
V_2 -> V_6 &= ~ V_28 ;
V_22:
F_12 ( V_2 -> V_16 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_21 ) ;
F_9 ( V_2 -> V_16 ) ;
F_5 ( V_2 , V_29 , V_30 , 0 ) ;
F_1 ( V_2 , V_5 , 0 ) ;
F_1 ( V_2 , V_31 , V_2 -> V_23 & 0xff ) ;
F_1 ( V_2 , V_32 , V_2 -> V_27 & 0xff ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_33 , 0 ) ;
F_1 ( V_2 , V_5 , 0 ) ;
F_5 ( V_2 , V_29 , 0 , V_30 ) ;
F_12 ( V_2 -> V_16 ) ;
F_16 ( V_2 -> V_21 ) ;
}
static unsigned char F_17 ( struct V_1 * V_2 ,
enum V_34 V_35 , unsigned char V_4 )
{
unsigned char V_36 = 0 ;
unsigned long V_24 ;
F_18 ( V_2 -> V_21 , L_2 , V_35 , V_4 ) ;
F_19 ( & V_2 -> V_37 , V_24 ) ;
switch ( V_35 ) {
case V_38 :
F_1 ( V_2 , V_29 , 0x94 ) ;
break;
case V_39 :
F_1 ( V_2 , V_5 , V_40 | V_41 | V_42 ) ;
F_1 ( V_2 , V_43 , V_4 ) ;
break;
case V_44 :
F_1 ( V_2 , V_43 , V_4 ) ;
break;
case V_45 :
F_1 ( V_2 , V_43 , V_4 ) ;
F_1 ( V_2 , V_29 , V_2 -> V_46 ? 0x90 : 0x94 ) ;
break;
case V_47 :
F_1 ( V_2 , V_29 , 0x81 ) ;
break;
case V_48 :
V_36 = F_3 ( V_2 , V_43 ) ;
break;
case V_49 :
F_1 ( V_2 , V_5 ,
V_50 | V_40 | V_41 | V_42 ) ;
F_1 ( V_2 , V_29 , 0xc0 ) ;
break;
case V_51 :
F_1 ( V_2 , V_5 ,
V_50 | V_40 | V_41 | V_42 ) ;
V_36 = F_3 ( V_2 , V_43 ) ;
F_1 ( V_2 , V_29 , 0xc0 ) ;
break;
}
F_20 ( & V_2 -> V_37 , V_24 ) ;
F_18 ( V_2 -> V_21 , L_3 , V_35 , V_36 ) ;
return V_36 ;
}
static bool F_21 ( struct V_1 * V_2 )
{
return V_2 -> V_52 == - 1 ;
}
static bool F_22 ( struct V_1 * V_2 )
{
return V_2 -> V_52 == V_2 -> V_53 -> V_54 - 1 ;
}
static void F_23 ( struct V_1 * V_2 ,
unsigned char * V_55 )
{
switch ( V_2 -> V_52 ) {
case - 1 :
* V_55 = ( V_2 -> V_53 -> V_56 & 0x7f ) << 1 ;
* V_55 |= ( V_2 -> V_53 -> V_24 & V_57 ) ? 1 : 0 ;
break;
default:
* V_55 = V_2 -> V_53 -> V_55 [ V_2 -> V_52 ] ;
}
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
if ( V_2 -> V_52 == V_2 -> V_53 -> V_54 )
return 1 ;
F_23 ( V_2 , & V_4 ) ;
if ( F_22 ( V_2 ) )
F_17 ( V_2 , V_45 , V_4 ) ;
else if ( F_21 ( V_2 ) )
F_17 ( V_2 , V_39 , V_4 ) ;
else
F_17 ( V_2 , V_44 , V_4 ) ;
V_2 -> V_52 ++ ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
int V_58 ;
do {
if ( V_2 -> V_52 <= - 1 ) {
F_23 ( V_2 , & V_4 ) ;
if ( F_21 ( V_2 ) )
F_17 ( V_2 , V_39 , V_4 ) ;
else
F_17 ( V_2 , V_44 , V_4 ) ;
break;
}
if ( V_2 -> V_52 == 0 ) {
F_17 ( V_2 , V_47 , 0 ) ;
break;
}
V_58 = V_2 -> V_52 - 2 ;
if ( V_2 -> V_52 == V_2 -> V_53 -> V_54 ) {
if ( V_58 < 0 ) {
F_17 ( V_2 , V_49 , 0 ) ;
break;
}
V_4 = F_17 ( V_2 , V_51 , 0 ) ;
} else
V_4 = F_17 ( V_2 , V_48 , 0 ) ;
if ( V_58 >= 0 )
V_2 -> V_53 -> V_55 [ V_58 ] = V_4 ;
} while ( 0 );
V_2 -> V_52 ++ ;
return V_2 -> V_52 == ( V_2 -> V_53 -> V_54 + 2 ) ;
}
static T_2 F_26 ( int V_59 , void * V_60 )
{
struct V_61 * V_21 = V_60 ;
struct V_1 * V_2 = F_27 ( V_21 ) ;
unsigned char V_62 ;
int V_63 ;
V_62 = F_3 ( V_2 , V_33 ) ;
V_2 -> V_62 |= V_62 ;
F_18 ( V_2 -> V_21 , L_4 , V_62 , V_2 -> V_62 ,
( V_2 -> V_53 -> V_24 & V_57 ) ? L_5 : L_6 ,
V_2 -> V_52 , V_2 -> V_53 -> V_54 ) ;
if ( V_62 & ( V_64 | V_65 ) ) {
F_1 ( V_2 , V_33 , V_62 & ~ ( V_64 | V_65 ) ) ;
V_63 = 0 ;
} else if ( V_2 -> V_53 -> V_24 & V_57 )
V_63 = F_25 ( V_2 ) ;
else
V_63 = F_24 ( V_2 ) ;
if ( V_62 & V_66 )
F_1 ( V_2 , V_33 , V_62 & ~ V_66 ) ;
if ( V_63 ) {
V_2 -> V_62 |= V_67 ;
F_28 ( & V_2 -> V_68 ) ;
}
F_3 ( V_2 , V_33 ) ;
return V_69 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_70 * V_71 ,
bool V_72 )
{
if ( V_71 -> V_54 == 0 && ( V_71 -> V_24 & V_57 ) ) {
F_11 ( V_2 -> V_21 , L_7 ) ;
return - V_73 ;
}
if ( V_72 ) {
F_5 ( V_2 , V_29 , 0 , V_30 ) ;
F_5 ( V_2 , V_29 , V_30 , 0 ) ;
F_1 ( V_2 , V_31 , V_2 -> V_23 & 0xff ) ;
F_1 ( V_2 , V_32 , V_2 -> V_27 & 0xff ) ;
}
V_2 -> V_53 = V_71 ;
V_2 -> V_52 = - 1 ;
V_2 -> V_62 = 0 ;
F_1 ( V_2 , V_5 , V_50 | V_40 | V_41 | V_42 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_74 ;
for ( V_74 = 1000 ; V_74 ; V_74 -- ) {
T_3 V_75 = F_3 ( V_2 , V_33 ) ;
if ( V_75 & V_76 )
break;
if ( V_75 & V_65 )
return - V_73 ;
F_31 ( 10 ) ;
}
if ( ! V_74 ) {
F_32 ( V_2 -> V_21 , L_8 ) ;
return - V_77 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_74 ;
for ( V_74 = 1000 ; V_74 ; V_74 -- ) {
T_3 V_75 = F_3 ( V_2 , V_33 ) ;
F_18 ( V_2 -> V_21 , L_9 , V_75 , V_2 -> V_62 ) ;
if ( ! ( V_75 & V_78 ) ) {
if ( ( V_75 | V_2 -> V_62 ) & ( V_65 | V_64 ) )
return - V_73 ;
break;
}
F_31 ( 10 ) ;
}
if ( ! V_74 ) {
F_11 ( V_2 -> V_21 , L_10 ) ;
return - V_77 ;
}
return 0 ;
}
static int F_34 ( struct V_79 * V_80 ,
struct V_70 * V_81 ,
int V_82 )
{
struct V_1 * V_2 = F_35 ( V_80 ) ;
struct V_70 * V_53 ;
int V_83 = 0 ;
int V_74 , V_84 ;
F_13 ( V_2 ) ;
for ( V_74 = 0 ; V_74 < V_82 ; V_74 ++ ) {
bool V_85 = V_2 -> V_46 || ! V_74 ;
V_53 = & V_81 [ V_74 ] ;
V_2 -> V_46 = V_74 == V_82 - 1 || V_53 -> V_24 & V_86 ;
V_83 = F_29 ( V_2 , V_53 , V_85 ) ;
if ( V_83 )
break;
if ( V_85 )
F_17 ( V_2 , V_38 , 0 ) ;
V_84 = F_36 ( V_2 -> V_68 ,
V_2 -> V_62 & ( V_65 | V_67 ) ,
5 * V_87 ) ;
if ( ! V_84 ) {
F_11 ( V_2 -> V_21 , L_11 ) ;
V_83 = - V_77 ;
break;
}
if ( V_2 -> V_46 )
V_83 = F_33 ( V_2 ) ;
else
V_83 = F_30 ( V_2 ) ;
if ( V_83 < 0 )
break;
}
F_15 ( V_2 ) ;
if ( ! V_83 )
V_83 = V_82 ;
return V_83 ;
}
static T_1 F_37 ( struct V_79 * V_80 )
{
return V_88 | V_89 | V_90 ;
}
static int F_38 ( struct V_61 * V_21 , int V_91 )
{
struct V_92 * V_93 ;
int V_36 = - V_94 ;
int V_95 , V_84 = 0 ;
while ( ( V_93 = F_39 ( V_21 , V_96 , V_84 ) ) ) {
for ( V_95 = V_93 -> V_97 ; V_91 && V_95 <= V_93 -> V_98 ; V_95 ++ ) {
if ( F_40 ( V_95 , F_26 , 0 ,
F_41 ( & V_21 -> V_21 ) , V_21 ) ) {
for ( V_95 -- ; V_95 >= V_93 -> V_97 ; V_95 -- )
F_42 ( V_95 , V_21 ) ;
goto V_99;
}
}
V_84 ++ ;
}
if ( V_91 )
return V_84 > 0 ? 0 : - V_100 ;
V_36 = 0 ;
V_99:
V_84 -- ;
while ( V_84 >= 0 ) {
V_93 = F_39 ( V_21 , V_96 , V_84 ) ;
for ( V_95 = V_93 -> V_97 ; V_95 <= V_93 -> V_98 ; V_95 ++ )
F_42 ( V_95 , V_21 ) ;
V_84 -- ;
}
return V_36 ;
}
static int F_43 ( struct V_61 * V_21 )
{
struct V_101 * V_102 = F_44 ( & V_21 -> V_21 ) ;
struct V_1 * V_2 ;
struct V_79 * V_103 ;
struct V_92 * V_93 ;
int V_104 ;
int V_36 ;
V_2 = F_45 ( sizeof( struct V_1 ) , V_105 ) ;
if ( V_2 == NULL ) {
F_11 ( & V_21 -> V_21 , L_12 ) ;
return - V_106 ;
}
V_2 -> V_16 = F_46 ( & V_21 -> V_21 , NULL ) ;
if ( F_47 ( V_2 -> V_16 ) ) {
F_11 ( & V_21 -> V_21 , L_13 ) ;
V_36 = F_48 ( V_2 -> V_16 ) ;
goto V_83;
}
V_36 = F_38 ( V_21 , 1 ) ;
if ( V_36 ) {
F_11 ( & V_21 -> V_21 , L_14 ) ;
goto V_107;
}
V_2 -> V_21 = & V_21 -> V_21 ;
F_49 ( V_21 , V_2 ) ;
V_93 = F_39 ( V_21 , V_108 , 0 ) ;
if ( V_93 == NULL ) {
F_11 ( & V_21 -> V_21 , L_15 ) ;
V_36 = - V_100 ;
goto V_109;
}
V_104 = F_50 ( V_93 ) ;
V_2 -> V_7 = F_51 ( V_93 -> V_97 , V_104 ) ;
if ( V_2 -> V_7 == NULL ) {
F_11 ( & V_21 -> V_21 , L_16 ) ;
V_36 = - V_94 ;
goto V_109;
}
V_2 -> V_18 = V_19 ;
if ( V_102 && V_102 -> V_18 )
V_2 -> V_18 = V_102 -> V_18 ;
V_2 -> V_17 = 1 ;
if ( V_102 && V_102 -> V_17 )
V_2 -> V_17 = V_102 -> V_17 ;
if ( V_104 > 0x17 )
V_2 -> V_24 |= V_25 ;
F_8 ( V_2 ) ;
F_52 ( & V_21 -> V_21 , true ) ;
F_53 ( & V_21 -> V_21 ) ;
V_103 = & V_2 -> V_103 ;
F_54 ( V_103 , V_2 ) ;
V_103 -> V_110 = V_111 ;
V_103 -> V_112 = & V_113 ;
V_103 -> V_21 . V_114 = & V_21 -> V_21 ;
V_103 -> V_115 = 5 ;
V_103 -> V_116 = V_21 -> V_117 ;
V_103 -> V_21 . V_118 = V_21 -> V_21 . V_118 ;
F_55 ( V_103 -> V_119 , V_21 -> V_119 , sizeof( V_103 -> V_119 ) ) ;
F_56 ( & V_2 -> V_37 ) ;
F_57 ( & V_2 -> V_68 ) ;
V_36 = F_58 ( V_103 ) ;
if ( V_36 < 0 ) {
F_11 ( & V_21 -> V_21 , L_17 ) ;
goto V_120;
}
F_59 ( & V_21 -> V_21 ,
L_18 ,
V_103 -> V_116 , V_2 -> V_18 , V_2 -> V_23 , V_2 -> V_27 ) ;
return 0 ;
V_120:
F_60 ( V_2 -> V_7 ) ;
V_109:
F_38 ( V_21 , 0 ) ;
V_107:
F_61 ( V_2 -> V_16 ) ;
V_83:
F_62 ( V_2 ) ;
return V_36 ;
}
static int F_63 ( struct V_61 * V_21 )
{
struct V_1 * V_2 = F_27 ( V_21 ) ;
F_64 ( & V_2 -> V_103 ) ;
F_60 ( V_2 -> V_7 ) ;
F_38 ( V_21 , 0 ) ;
F_61 ( V_2 -> V_16 ) ;
F_65 ( & V_21 -> V_21 ) ;
F_62 ( V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_121 * V_21 )
{
return 0 ;
}
static int T_4 F_67 ( void )
{
return F_68 ( & V_122 ) ;
}
static void T_5 F_69 ( void )
{
F_70 ( & V_122 ) ;
}
