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
F_1 ( V_2 , V_29 , 0x90 ) ;
break;
case V_46 :
F_1 ( V_2 , V_29 , 0x81 ) ;
break;
case V_47 :
V_36 = F_3 ( V_2 , V_43 ) ;
break;
case V_48 :
F_1 ( V_2 , V_5 ,
V_49 | V_40 | V_41 | V_42 ) ;
F_1 ( V_2 , V_29 , 0xc0 ) ;
break;
case V_50 :
F_1 ( V_2 , V_5 ,
V_49 | V_40 | V_41 | V_42 ) ;
V_36 = F_3 ( V_2 , V_43 ) ;
F_1 ( V_2 , V_29 , 0xc0 ) ;
break;
}
F_20 ( & V_2 -> V_37 , V_24 ) ;
F_18 ( V_2 -> V_21 , L_3 , V_35 , V_36 ) ;
return V_36 ;
}
static int F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_51 == - 1 )
return 1 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_51 == ( V_2 -> V_52 -> V_53 - 1 ) )
return 1 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
unsigned char * V_54 )
{
switch ( V_2 -> V_51 ) {
case - 1 :
* V_54 = ( V_2 -> V_52 -> V_55 & 0x7f ) << 1 ;
* V_54 |= ( V_2 -> V_52 -> V_24 & V_56 ) ? 1 : 0 ;
break;
default:
* V_54 = V_2 -> V_52 -> V_54 [ V_2 -> V_51 ] ;
}
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
if ( V_2 -> V_51 == V_2 -> V_52 -> V_53 )
return 1 ;
F_23 ( V_2 , & V_4 ) ;
if ( F_22 ( V_2 ) )
F_17 ( V_2 , V_45 , V_4 ) ;
else if ( F_21 ( V_2 ) )
F_17 ( V_2 , V_39 , V_4 ) ;
else
F_17 ( V_2 , V_44 , V_4 ) ;
V_2 -> V_51 ++ ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
int V_57 ;
do {
if ( V_2 -> V_51 <= - 1 ) {
F_23 ( V_2 , & V_4 ) ;
if ( F_21 ( V_2 ) )
F_17 ( V_2 , V_39 , V_4 ) ;
else
F_17 ( V_2 , V_44 , V_4 ) ;
break;
}
if ( V_2 -> V_51 == 0 ) {
F_17 ( V_2 , V_46 , 0 ) ;
break;
}
V_57 = V_2 -> V_51 - 2 ;
if ( V_2 -> V_51 == V_2 -> V_52 -> V_53 ) {
if ( V_57 < 0 ) {
F_17 ( V_2 , V_48 , 0 ) ;
break;
}
V_4 = F_17 ( V_2 , V_50 , 0 ) ;
} else
V_4 = F_17 ( V_2 , V_47 , 0 ) ;
if ( V_57 >= 0 )
V_2 -> V_52 -> V_54 [ V_57 ] = V_4 ;
} while ( 0 );
V_2 -> V_51 ++ ;
return V_2 -> V_51 == ( V_2 -> V_52 -> V_53 + 2 ) ;
}
static T_2 F_26 ( int V_58 , void * V_59 )
{
struct V_60 * V_21 = V_59 ;
struct V_1 * V_2 = F_27 ( V_21 ) ;
unsigned char V_61 ;
int V_62 ;
V_61 = F_3 ( V_2 , V_33 ) ;
V_2 -> V_61 |= V_61 ;
F_18 ( V_2 -> V_21 , L_4 , V_61 , V_2 -> V_61 ,
( V_2 -> V_52 -> V_24 & V_56 ) ? L_5 : L_6 ,
V_2 -> V_51 , V_2 -> V_52 -> V_53 ) ;
if ( V_61 & ( V_63 | V_64 ) ) {
F_1 ( V_2 , V_33 , V_61 & ~ ( V_63 | V_64 ) ) ;
V_62 = 0 ;
} else if ( V_2 -> V_52 -> V_24 & V_56 )
V_62 = F_25 ( V_2 ) ;
else
V_62 = F_24 ( V_2 ) ;
if ( V_61 & V_65 )
F_1 ( V_2 , V_33 , V_61 & ~ V_65 ) ;
if ( V_62 ) {
V_2 -> V_61 |= V_66 ;
F_28 ( & V_2 -> V_67 ) ;
}
F_3 ( V_2 , V_33 ) ;
return V_68 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
if ( V_70 -> V_53 == 0 && ( V_70 -> V_24 & V_56 ) ) {
F_11 ( V_2 -> V_21 , L_7 ) ;
return - V_71 ;
}
F_5 ( V_2 , V_29 , 0 , V_30 ) ;
F_5 ( V_2 , V_29 , V_30 , 0 ) ;
F_1 ( V_2 , V_31 , V_2 -> V_23 & 0xff ) ;
F_1 ( V_2 , V_32 , V_2 -> V_27 & 0xff ) ;
V_2 -> V_52 = V_70 ;
V_2 -> V_51 = - 1 ;
V_2 -> V_61 = 0 ;
F_1 ( V_2 , V_5 , V_49 | V_40 | V_41 | V_42 ) ;
return 0 ;
}
static int F_30 ( struct V_72 * V_73 ,
struct V_69 * V_74 ,
int V_75 )
{
struct V_1 * V_2 = F_31 ( V_73 ) ;
struct V_69 * V_52 ;
int V_76 = 0 ;
T_3 V_77 ;
int V_78 , V_79 , V_80 ;
F_13 ( V_2 ) ;
for ( V_78 = 0 ; V_78 < V_75 ; V_78 ++ ) {
V_52 = & V_74 [ V_78 ] ;
V_76 = F_29 ( V_2 , V_52 ) ;
if ( V_76 )
break;
F_17 ( V_2 , V_38 , 0 ) ;
V_79 = F_32 ( V_2 -> V_67 ,
V_2 -> V_61 & ( V_64 | V_66 ) ,
5 * V_81 ) ;
if ( ! V_79 )
F_11 ( V_2 -> V_21 , L_8 ) ;
V_80 = 1000 ;
V_82:
V_77 = F_3 ( V_2 , V_33 ) ;
F_18 ( V_2 -> V_21 , L_9 , V_77 , V_2 -> V_61 ) ;
if ( V_77 & V_83 ) {
F_33 ( 10 ) ;
if ( V_80 -- )
goto V_82;
V_76 = - V_71 ;
F_11 ( V_2 -> V_21 , L_10 ) ;
break;
}
if ( ( V_77 | V_2 -> V_61 ) & ( V_64 | V_63 ) ) {
V_76 = - V_71 ;
break;
}
}
F_15 ( V_2 ) ;
if ( ! V_76 )
V_76 = V_75 ;
return V_76 ;
}
static T_1 F_34 ( struct V_72 * V_73 )
{
return V_84 | V_85 ;
}
static int F_35 ( struct V_60 * V_21 , int V_86 )
{
struct V_87 * V_88 ;
int V_36 = - V_89 ;
int V_90 , V_79 = 0 ;
while ( ( V_88 = F_36 ( V_21 , V_91 , V_79 ) ) ) {
for ( V_90 = V_88 -> V_92 ; V_86 && V_90 <= V_88 -> V_93 ; V_90 ++ ) {
if ( F_37 ( V_90 , F_26 , 0 ,
F_38 ( & V_21 -> V_21 ) , V_21 ) ) {
for ( V_90 -- ; V_90 >= V_88 -> V_92 ; V_90 -- )
F_39 ( V_90 , V_21 ) ;
goto V_94;
}
}
V_79 ++ ;
}
if ( V_86 )
return V_79 > 0 ? 0 : - V_95 ;
V_36 = 0 ;
V_94:
V_79 -- ;
while ( V_79 >= 0 ) {
V_88 = F_36 ( V_21 , V_91 , V_79 ) ;
for ( V_90 = V_88 -> V_92 ; V_90 <= V_88 -> V_93 ; V_90 ++ )
F_39 ( V_90 , V_21 ) ;
V_79 -- ;
}
return V_36 ;
}
static int F_40 ( struct V_60 * V_21 )
{
struct V_96 * V_97 = V_21 -> V_21 . V_98 ;
struct V_1 * V_2 ;
struct V_72 * V_99 ;
struct V_87 * V_88 ;
int V_100 ;
int V_36 ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_101 ) ;
if ( V_2 == NULL ) {
F_11 ( & V_21 -> V_21 , L_11 ) ;
return - V_102 ;
}
V_2 -> V_16 = F_42 ( & V_21 -> V_21 , NULL ) ;
if ( F_43 ( V_2 -> V_16 ) ) {
F_11 ( & V_21 -> V_21 , L_12 ) ;
V_36 = F_44 ( V_2 -> V_16 ) ;
goto V_76;
}
V_36 = F_35 ( V_21 , 1 ) ;
if ( V_36 ) {
F_11 ( & V_21 -> V_21 , L_13 ) ;
goto V_103;
}
V_2 -> V_21 = & V_21 -> V_21 ;
F_45 ( V_21 , V_2 ) ;
V_88 = F_36 ( V_21 , V_104 , 0 ) ;
if ( V_88 == NULL ) {
F_11 ( & V_21 -> V_21 , L_14 ) ;
V_36 = - V_95 ;
goto V_105;
}
V_100 = F_46 ( V_88 ) ;
V_2 -> V_7 = F_47 ( V_88 -> V_92 , V_100 ) ;
if ( V_2 -> V_7 == NULL ) {
F_11 ( & V_21 -> V_21 , L_15 ) ;
V_36 = - V_89 ;
goto V_105;
}
V_2 -> V_18 = V_19 ;
if ( V_97 && V_97 -> V_18 )
V_2 -> V_18 = V_97 -> V_18 ;
V_2 -> V_17 = 1 ;
if ( V_97 && V_97 -> V_17 )
V_2 -> V_17 = V_97 -> V_17 ;
if ( V_100 > 0x17 )
V_2 -> V_24 |= V_25 ;
F_8 ( V_2 ) ;
F_48 ( & V_21 -> V_21 , true ) ;
F_49 ( & V_21 -> V_21 ) ;
V_99 = & V_2 -> V_99 ;
F_50 ( V_99 , V_2 ) ;
V_99 -> V_106 = V_107 ;
V_99 -> V_108 = & V_109 ;
V_99 -> V_21 . V_110 = & V_21 -> V_21 ;
V_99 -> V_111 = 5 ;
V_99 -> V_112 = V_21 -> V_113 ;
V_99 -> V_21 . V_114 = V_21 -> V_21 . V_114 ;
F_51 ( V_99 -> V_115 , V_21 -> V_115 , sizeof( V_99 -> V_115 ) ) ;
F_52 ( & V_2 -> V_37 ) ;
F_53 ( & V_2 -> V_67 ) ;
V_36 = F_54 ( V_99 ) ;
if ( V_36 < 0 ) {
F_11 ( & V_21 -> V_21 , L_16 ) ;
goto V_116;
}
F_55 ( & V_21 -> V_21 ,
L_17 ,
V_99 -> V_112 , V_2 -> V_18 , V_2 -> V_23 , V_2 -> V_27 ) ;
F_56 ( V_99 ) ;
return 0 ;
V_116:
F_57 ( V_2 -> V_7 ) ;
V_105:
F_35 ( V_21 , 0 ) ;
V_103:
F_58 ( V_2 -> V_16 ) ;
V_76:
F_59 ( V_2 ) ;
return V_36 ;
}
static int F_60 ( struct V_60 * V_21 )
{
struct V_1 * V_2 = F_27 ( V_21 ) ;
F_61 ( & V_2 -> V_99 ) ;
F_57 ( V_2 -> V_7 ) ;
F_35 ( V_21 , 0 ) ;
F_58 ( V_2 -> V_16 ) ;
F_62 ( & V_21 -> V_21 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_117 * V_21 )
{
return 0 ;
}
static int T_4 F_64 ( void )
{
return F_65 ( & V_118 ) ;
}
static void T_5 F_66 ( void )
{
F_67 ( & V_118 ) ;
}
