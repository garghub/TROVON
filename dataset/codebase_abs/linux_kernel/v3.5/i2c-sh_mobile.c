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
static void F_6 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
T_1 V_11 ;
T_1 V_12 ;
T_1 V_13 ;
F_7 ( V_2 -> V_14 ) ;
F_8 ( V_2 -> V_15 ) ;
V_10 = F_9 ( V_2 -> V_15 ) ;
V_11 = V_10 * 5 ;
V_12 = V_2 -> V_16 * 9 ;
V_13 = V_11 * 10 / V_12 ;
if ( V_13 % 10 >= 5 )
V_2 -> V_17 = ( V_18 ) ( ( V_11 / V_12 ) + 1 ) ;
else
V_2 -> V_17 = ( V_18 ) ( V_11 / V_12 ) ;
if ( V_2 -> V_19 & V_20 ) {
if ( ( V_11 / V_12 ) > 0xff )
V_2 -> V_6 |= V_21 ;
else
V_2 -> V_6 &= ~ V_21 ;
}
V_11 = V_10 * 4 ;
V_13 = V_11 * 10 / V_12 ;
if ( V_13 % 10 >= 5 )
V_2 -> V_22 = ( V_18 ) ( ( V_11 / V_12 ) + 1 ) ;
else
V_2 -> V_22 = ( V_18 ) ( V_11 / V_12 ) ;
if ( V_2 -> V_19 & V_20 ) {
if ( ( V_11 / V_12 ) > 0xff )
V_2 -> V_6 |= V_23 ;
else
V_2 -> V_6 &= ~ V_23 ;
}
F_5 ( V_2 , V_24 , V_25 , 0 ) ;
F_1 ( V_2 , V_5 , 0 ) ;
F_1 ( V_2 , V_26 , V_2 -> V_17 ) ;
F_1 ( V_2 , V_27 , V_2 -> V_22 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_28 , 0 ) ;
F_1 ( V_2 , V_5 , 0 ) ;
F_5 ( V_2 , V_24 , 0 , V_25 ) ;
F_11 ( V_2 -> V_15 ) ;
F_12 ( V_2 -> V_14 ) ;
}
static unsigned char F_13 ( struct V_1 * V_2 ,
enum V_29 V_30 , unsigned char V_4 )
{
unsigned char V_31 = 0 ;
unsigned long V_19 ;
F_14 ( V_2 -> V_14 , L_1 , V_30 , V_4 ) ;
F_15 ( & V_2 -> V_32 , V_19 ) ;
switch ( V_30 ) {
case V_33 :
F_1 ( V_2 , V_24 , 0x94 ) ;
break;
case V_34 :
F_1 ( V_2 , V_5 , V_35 | V_36 | V_37 ) ;
F_1 ( V_2 , V_38 , V_4 ) ;
break;
case V_39 :
F_1 ( V_2 , V_38 , V_4 ) ;
break;
case V_40 :
F_1 ( V_2 , V_38 , V_4 ) ;
F_1 ( V_2 , V_24 , 0x90 ) ;
break;
case V_41 :
F_1 ( V_2 , V_24 , 0x81 ) ;
break;
case V_42 :
V_31 = F_3 ( V_2 , V_38 ) ;
break;
case V_43 :
F_1 ( V_2 , V_5 ,
V_44 | V_35 | V_36 | V_37 ) ;
F_1 ( V_2 , V_24 , 0xc0 ) ;
break;
case V_45 :
F_1 ( V_2 , V_5 ,
V_44 | V_35 | V_36 | V_37 ) ;
V_31 = F_3 ( V_2 , V_38 ) ;
F_1 ( V_2 , V_24 , 0xc0 ) ;
break;
}
F_16 ( & V_2 -> V_32 , V_19 ) ;
F_14 ( V_2 -> V_14 , L_2 , V_30 , V_31 ) ;
return V_31 ;
}
static int F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 == - 1 )
return 1 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 == ( V_2 -> V_47 -> V_48 - 1 ) )
return 1 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 ,
unsigned char * V_49 )
{
switch ( V_2 -> V_46 ) {
case - 1 :
* V_49 = ( V_2 -> V_47 -> V_50 & 0x7f ) << 1 ;
* V_49 |= ( V_2 -> V_47 -> V_19 & V_51 ) ? 1 : 0 ;
break;
default:
* V_49 = V_2 -> V_47 -> V_49 [ V_2 -> V_46 ] ;
}
}
static int F_20 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
if ( V_2 -> V_46 == V_2 -> V_47 -> V_48 )
return 1 ;
F_19 ( V_2 , & V_4 ) ;
if ( F_18 ( V_2 ) )
F_13 ( V_2 , V_40 , V_4 ) ;
else if ( F_17 ( V_2 ) )
F_13 ( V_2 , V_34 , V_4 ) ;
else
F_13 ( V_2 , V_39 , V_4 ) ;
V_2 -> V_46 ++ ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
int V_52 ;
do {
if ( V_2 -> V_46 <= - 1 ) {
F_19 ( V_2 , & V_4 ) ;
if ( F_17 ( V_2 ) )
F_13 ( V_2 , V_34 , V_4 ) ;
else
F_13 ( V_2 , V_39 , V_4 ) ;
break;
}
if ( V_2 -> V_46 == 0 ) {
F_13 ( V_2 , V_41 , 0 ) ;
break;
}
V_52 = V_2 -> V_46 - 2 ;
if ( V_2 -> V_46 == V_2 -> V_47 -> V_48 ) {
if ( V_52 < 0 ) {
F_13 ( V_2 , V_43 , 0 ) ;
break;
}
V_4 = F_13 ( V_2 , V_45 , 0 ) ;
} else
V_4 = F_13 ( V_2 , V_42 , 0 ) ;
if ( V_52 >= 0 )
V_2 -> V_47 -> V_49 [ V_52 ] = V_4 ;
} while ( 0 );
V_2 -> V_46 ++ ;
return V_2 -> V_46 == ( V_2 -> V_47 -> V_48 + 2 ) ;
}
static T_2 F_22 ( int V_53 , void * V_54 )
{
struct V_55 * V_14 = V_54 ;
struct V_1 * V_2 = F_23 ( V_14 ) ;
unsigned char V_56 ;
int V_57 ;
V_56 = F_3 ( V_2 , V_28 ) ;
V_2 -> V_56 |= V_56 ;
F_14 ( V_2 -> V_14 , L_3 , V_56 , V_2 -> V_56 ,
( V_2 -> V_47 -> V_19 & V_51 ) ? L_4 : L_5 ,
V_2 -> V_46 , V_2 -> V_47 -> V_48 ) ;
if ( V_56 & ( V_58 | V_59 ) ) {
F_1 ( V_2 , V_28 , V_56 & ~ ( V_58 | V_59 ) ) ;
V_57 = 0 ;
} else if ( V_2 -> V_47 -> V_19 & V_51 )
V_57 = F_21 ( V_2 ) ;
else
V_57 = F_20 ( V_2 ) ;
if ( V_56 & V_60 )
F_1 ( V_2 , V_28 , V_56 & ~ V_60 ) ;
if ( V_57 ) {
V_2 -> V_56 |= V_61 ;
F_24 ( & V_2 -> V_62 ) ;
}
return V_63 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_64 * V_65 )
{
if ( V_65 -> V_48 == 0 && ( V_65 -> V_19 & V_51 ) ) {
F_26 ( V_2 -> V_14 , L_6 ) ;
return - V_66 ;
}
F_5 ( V_2 , V_24 , 0 , V_25 ) ;
F_5 ( V_2 , V_24 , V_25 , 0 ) ;
F_1 ( V_2 , V_26 , V_2 -> V_17 ) ;
F_1 ( V_2 , V_27 , V_2 -> V_22 ) ;
V_2 -> V_47 = V_65 ;
V_2 -> V_46 = - 1 ;
V_2 -> V_56 = 0 ;
F_1 ( V_2 , V_5 , V_44 | V_35 | V_36 | V_37 ) ;
return 0 ;
}
static int F_27 ( struct V_67 * V_68 ,
struct V_64 * V_69 ,
int V_11 )
{
struct V_1 * V_2 = F_28 ( V_68 ) ;
struct V_64 * V_47 ;
int V_70 = 0 ;
V_18 V_71 ;
int V_72 , V_73 , V_74 ;
F_6 ( V_2 ) ;
for ( V_72 = 0 ; V_72 < V_11 ; V_72 ++ ) {
V_47 = & V_69 [ V_72 ] ;
V_70 = F_25 ( V_2 , V_47 ) ;
if ( V_70 )
break;
F_13 ( V_2 , V_33 , 0 ) ;
V_73 = F_29 ( V_2 -> V_62 ,
V_2 -> V_56 & ( V_59 | V_61 ) ,
5 * V_75 ) ;
if ( ! V_73 )
F_26 ( V_2 -> V_14 , L_7 ) ;
V_74 = 1000 ;
V_76:
V_71 = F_3 ( V_2 , V_28 ) ;
F_14 ( V_2 -> V_14 , L_8 , V_71 , V_2 -> V_56 ) ;
if ( V_71 & V_77 ) {
F_30 ( 10 ) ;
if ( V_74 -- )
goto V_76;
V_70 = - V_66 ;
F_26 ( V_2 -> V_14 , L_9 ) ;
break;
}
if ( ( V_71 | V_2 -> V_56 ) & ( V_59 | V_58 ) ) {
V_70 = - V_66 ;
break;
}
}
F_10 ( V_2 ) ;
if ( ! V_70 )
V_70 = V_11 ;
return V_70 ;
}
static T_3 F_31 ( struct V_67 * V_68 )
{
return V_78 | V_79 ;
}
static int F_32 ( struct V_55 * V_14 , int V_80 )
{
struct V_81 * V_82 ;
int V_31 = - V_83 ;
int V_84 , V_73 = 0 ;
while ( ( V_82 = F_33 ( V_14 , V_85 , V_73 ) ) ) {
for ( V_84 = V_82 -> V_86 ; V_80 && V_84 <= V_82 -> V_87 ; V_84 ++ ) {
if ( F_34 ( V_84 , F_22 , 0 ,
F_35 ( & V_14 -> V_14 ) , V_14 ) ) {
for ( V_84 -- ; V_84 >= V_82 -> V_86 ; V_84 -- )
F_36 ( V_84 , V_14 ) ;
goto V_88;
}
}
V_73 ++ ;
}
if ( V_80 )
return V_73 > 0 ? 0 : - V_89 ;
V_31 = 0 ;
V_88:
V_73 -- ;
while ( V_73 >= 0 ) {
V_82 = F_33 ( V_14 , V_85 , V_73 ) ;
for ( V_84 = V_82 -> V_86 ; V_84 <= V_82 -> V_87 ; V_84 ++ )
F_36 ( V_84 , V_14 ) ;
V_73 -- ;
}
return V_31 ;
}
static int F_37 ( struct V_55 * V_14 )
{
struct V_90 * V_91 = V_14 -> V_14 . V_92 ;
struct V_1 * V_2 ;
struct V_67 * V_93 ;
struct V_81 * V_82 ;
int V_94 ;
int V_31 ;
V_2 = F_38 ( sizeof( struct V_1 ) , V_95 ) ;
if ( V_2 == NULL ) {
F_26 ( & V_14 -> V_14 , L_10 ) ;
return - V_96 ;
}
V_2 -> V_15 = F_39 ( & V_14 -> V_14 , NULL ) ;
if ( F_40 ( V_2 -> V_15 ) ) {
F_26 ( & V_14 -> V_14 , L_11 ) ;
V_31 = F_41 ( V_2 -> V_15 ) ;
goto V_70;
}
V_31 = F_32 ( V_14 , 1 ) ;
if ( V_31 ) {
F_26 ( & V_14 -> V_14 , L_12 ) ;
goto V_97;
}
V_2 -> V_14 = & V_14 -> V_14 ;
F_42 ( V_14 , V_2 ) ;
V_82 = F_33 ( V_14 , V_98 , 0 ) ;
if ( V_82 == NULL ) {
F_26 ( & V_14 -> V_14 , L_13 ) ;
V_31 = - V_89 ;
goto V_99;
}
V_94 = F_43 ( V_82 ) ;
V_2 -> V_7 = F_44 ( V_82 -> V_86 , V_94 ) ;
if ( V_2 -> V_7 == NULL ) {
F_26 ( & V_14 -> V_14 , L_14 ) ;
V_31 = - V_83 ;
goto V_99;
}
V_2 -> V_16 = V_100 ;
if ( V_91 && V_91 -> V_16 )
V_2 -> V_16 = V_91 -> V_16 ;
if ( V_94 > 0x17 )
V_2 -> V_19 |= V_20 ;
F_45 ( & V_14 -> V_14 , true ) ;
F_46 ( & V_14 -> V_14 ) ;
V_93 = & V_2 -> V_93 ;
F_47 ( V_93 , V_2 ) ;
V_93 -> V_101 = V_102 ;
V_93 -> V_103 = & V_104 ;
V_93 -> V_14 . V_105 = & V_14 -> V_14 ;
V_93 -> V_106 = 5 ;
V_93 -> V_107 = V_14 -> V_108 ;
V_93 -> V_14 . V_109 = V_14 -> V_14 . V_109 ;
F_48 ( V_93 -> V_110 , V_14 -> V_110 , sizeof( V_93 -> V_110 ) ) ;
F_49 ( & V_2 -> V_32 ) ;
F_50 ( & V_2 -> V_62 ) ;
V_31 = F_51 ( V_93 ) ;
if ( V_31 < 0 ) {
F_26 ( & V_14 -> V_14 , L_15 ) ;
goto V_111;
}
F_52 ( & V_14 -> V_14 , L_16 ,
V_93 -> V_107 , V_2 -> V_16 ) ;
F_53 ( V_93 ) ;
return 0 ;
V_111:
F_54 ( V_2 -> V_7 ) ;
V_99:
F_32 ( V_14 , 0 ) ;
V_97:
F_55 ( V_2 -> V_15 ) ;
V_70:
F_56 ( V_2 ) ;
return V_31 ;
}
static int F_57 ( struct V_55 * V_14 )
{
struct V_1 * V_2 = F_23 ( V_14 ) ;
F_58 ( & V_2 -> V_93 ) ;
F_54 ( V_2 -> V_7 ) ;
F_32 ( V_14 , 0 ) ;
F_55 ( V_2 -> V_15 ) ;
F_59 ( & V_14 -> V_14 ) ;
F_56 ( V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_112 * V_14 )
{
return 0 ;
}
static int T_4 F_61 ( void )
{
return F_62 ( & V_113 ) ;
}
static void T_5 F_63 ( void )
{
F_64 ( & V_113 ) ;
}
