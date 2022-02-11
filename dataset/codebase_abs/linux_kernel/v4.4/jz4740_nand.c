static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_3 -> V_8 ;
T_1 V_9 ;
int V_10 ;
V_9 = F_4 ( V_5 -> V_11 + V_12 ) ;
V_9 &= ~ V_13 ;
if ( V_4 == - 1 ) {
V_10 = - 1 ;
} else {
V_10 = V_5 -> V_14 [ V_4 ] - 1 ;
V_7 -> V_15 = V_5 -> V_16 [ V_10 ] ;
V_7 -> V_17 = V_5 -> V_16 [ V_10 ] ;
}
F_5 ( V_9 , V_5 -> V_11 + V_12 ) ;
V_5 -> V_18 = V_10 ;
}
static void F_6 ( struct V_2 * V_3 , int V_19 , unsigned int V_9 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_3 -> V_8 ;
T_1 V_20 ;
void T_2 * V_16 = V_5 -> V_16 [ V_5 -> V_18 ] ;
F_7 ( V_5 -> V_18 < 0 ) ;
if ( V_9 & V_21 ) {
F_7 ( ( V_9 & V_22 ) && ( V_9 & V_23 ) ) ;
if ( V_9 & V_22 )
V_16 += V_24 ;
else if ( V_9 & V_23 )
V_16 += V_25 ;
V_7 -> V_17 = V_16 ;
V_20 = F_4 ( V_5 -> V_11 + V_12 ) ;
if ( V_9 & V_26 )
V_20 |= F_8 ( V_5 -> V_18 ) ;
else
V_20 &= ~ F_8 ( V_5 -> V_18 ) ;
F_5 ( V_20 , V_5 -> V_11 + V_12 ) ;
}
if ( V_19 != V_27 )
F_9 ( V_19 , V_7 -> V_17 ) ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return F_11 ( V_5 -> V_28 ) ;
}
static void F_12 ( struct V_2 * V_3 , int V_29 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_20 ;
F_5 ( 0 , V_5 -> V_11 + V_30 ) ;
V_20 = F_4 ( V_5 -> V_11 + V_31 ) ;
V_20 |= V_32 ;
V_20 |= V_33 ;
V_20 |= V_34 ;
switch ( V_29 ) {
case V_35 :
V_20 &= ~ V_36 ;
V_5 -> V_37 = true ;
break;
case V_38 :
V_20 |= V_36 ;
V_5 -> V_37 = false ;
break;
default:
break;
}
F_5 ( V_20 , V_5 -> V_11 + V_31 ) ;
}
static int F_13 ( struct V_2 * V_3 , const T_3 * V_19 ,
T_3 * V_39 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_20 , V_40 ;
int V_41 ;
unsigned int V_42 = 1000 ;
static T_3 V_43 [] = { 0xcd , 0x9d , 0x90 , 0x58 , 0xf4 ,
0x8b , 0xff , 0xb7 , 0x6f } ;
if ( V_5 -> V_37 )
return 0 ;
do {
V_40 = F_4 ( V_5 -> V_11 + V_30 ) ;
} while ( ! ( V_40 & V_44 ) && -- V_42 );
if ( V_42 == 0 )
return - 1 ;
V_20 = F_4 ( V_5 -> V_11 + V_31 ) ;
V_20 &= ~ V_33 ;
F_5 ( V_20 , V_5 -> V_11 + V_31 ) ;
for ( V_41 = 0 ; V_41 < 9 ; ++ V_41 )
V_39 [ V_41 ] = F_14 ( V_5 -> V_11 + V_45 + V_41 ) ;
if ( memcmp ( V_39 , V_43 , 9 ) == 0 )
memset ( V_39 , 0xff , 9 ) ;
return 0 ;
}
static void F_15 ( T_3 * V_19 , int V_46 , int V_47 )
{
int V_48 = V_46 & 0x7 ;
T_4 V_49 ;
V_46 += ( V_46 >> 3 ) ;
V_49 = V_19 [ V_46 ] ;
V_49 |= V_19 [ V_46 + 1 ] << 8 ;
V_47 ^= ( V_49 >> V_48 ) & 0x1ff ;
V_49 &= ~ ( 0x1ff << V_48 ) ;
V_49 |= ( V_47 << V_48 ) ;
V_19 [ V_46 ] = V_49 & 0xff ;
V_19 [ V_46 + 1 ] = ( V_49 >> 8 ) & 0xff ;
}
static int F_16 ( struct V_2 * V_3 , T_3 * V_19 ,
T_3 * V_50 , T_3 * V_51 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_41 , V_52 , V_46 ;
T_1 V_20 , V_40 , error ;
T_1 V_53 ;
unsigned int V_42 = 1000 ;
V_53 = V_50 [ 0 ] ;
if ( V_53 == 0xff ) {
for ( V_41 = 1 ; V_41 < 9 ; ++ V_41 )
V_53 &= V_50 [ V_41 ] ;
V_53 &= V_19 [ 0 ] ;
V_53 &= V_19 [ V_5 -> V_7 . V_54 . V_55 / 2 ] ;
V_53 &= V_19 [ V_5 -> V_7 . V_54 . V_55 - 1 ] ;
if ( V_53 == 0xff ) {
for ( V_41 = 1 ; V_41 < V_5 -> V_7 . V_54 . V_55 - 1 ; ++ V_41 )
V_53 &= V_19 [ V_41 ] ;
if ( V_53 == 0xff )
return 0 ;
}
}
for ( V_41 = 0 ; V_41 < 9 ; ++ V_41 )
F_9 ( V_50 [ V_41 ] , V_5 -> V_11 + V_45 + V_41 ) ;
V_20 = F_4 ( V_5 -> V_11 + V_31 ) ;
V_20 |= V_56 ;
F_5 ( V_20 , V_5 -> V_11 + V_31 ) ;
do {
V_40 = F_4 ( V_5 -> V_11 + V_30 ) ;
} while ( ! ( V_40 & V_57 ) && -- V_42 );
if ( V_42 == 0 )
return - 1 ;
V_20 = F_4 ( V_5 -> V_11 + V_31 ) ;
V_20 &= ~ V_33 ;
F_5 ( V_20 , V_5 -> V_11 + V_31 ) ;
if ( V_40 & V_58 ) {
if ( V_40 & V_59 )
return - 1 ;
V_52 = ( V_40 & V_60 ) >> 29 ;
for ( V_41 = 0 ; V_41 < V_52 ; ++ V_41 ) {
error = F_4 ( V_5 -> V_11 + F_17 ( V_41 ) ) ;
V_46 = ( ( error >> 16 ) & 0x1ff ) - 1 ;
if ( V_46 >= 0 && V_46 < 512 )
F_15 ( V_19 , V_46 , error & 0x1ff ) ;
}
return V_52 ;
}
return 0 ;
}
static int F_18 ( struct V_61 * V_62 ,
const char * V_63 , struct V_64 * * V_65 , void * T_2 * V_11 )
{
int V_66 ;
* V_65 = F_19 ( V_62 , V_67 , V_63 ) ;
if ( ! * V_65 ) {
F_20 ( & V_62 -> V_68 , L_1 , V_63 ) ;
V_66 = - V_69 ;
goto V_70;
}
* V_65 = F_21 ( ( * V_65 ) -> V_71 , F_22 ( * V_65 ) ,
V_62 -> V_63 ) ;
if ( ! * V_65 ) {
F_20 ( & V_62 -> V_68 , L_2 , V_63 ) ;
V_66 = - V_72 ;
goto V_70;
}
* V_11 = F_23 ( ( * V_65 ) -> V_71 , F_22 ( * V_65 ) ) ;
if ( ! * V_11 ) {
F_20 ( & V_62 -> V_68 , L_3 , V_63 ) ;
V_66 = - V_72 ;
goto V_73;
}
return 0 ;
V_73:
F_24 ( ( * V_65 ) -> V_71 , F_22 ( * V_65 ) ) ;
V_70:
* V_65 = NULL ;
* V_11 = NULL ;
return V_66 ;
}
static inline void F_25 ( struct V_64 * V_65 ,
void T_2 * V_11 )
{
F_26 ( V_11 ) ;
F_24 ( V_65 -> V_71 , F_22 ( V_65 ) ) ;
}
static int F_27 ( struct V_61 * V_62 ,
struct V_1 * V_5 , unsigned char V_74 ,
T_5 V_4 , T_3 * V_75 ,
T_3 * V_76 )
{
int V_66 ;
int V_77 ;
char V_78 [ 9 ] ;
char V_79 [ 6 ] ;
T_1 V_9 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_7 ;
V_77 = V_80 + V_74 - 1 ;
sprintf ( V_78 , L_4 , V_74 ) ;
V_66 = F_28 ( V_77 , V_78 ) ;
if ( V_66 ) {
F_29 ( & V_62 -> V_68 ,
L_5 ,
V_78 , V_77 , V_66 ) ;
goto V_81;
}
sprintf ( V_79 , L_6 , V_74 ) ;
V_66 = F_18 ( V_62 , V_79 ,
& V_5 -> V_82 [ V_74 - 1 ] ,
& V_5 -> V_16 [ V_74 - 1 ] ) ;
if ( V_66 )
goto V_83;
F_30 ( V_77 , V_84 ) ;
V_9 = F_4 ( V_5 -> V_11 + V_12 ) ;
V_9 |= F_31 ( V_74 - 1 ) ;
F_5 ( V_9 , V_5 -> V_11 + V_12 ) ;
if ( V_4 == 0 ) {
V_66 = F_32 ( V_3 , 1 , NULL ) ;
if ( V_66 )
goto V_85;
V_7 -> V_86 ( V_3 , 0 ) ;
V_7 -> V_87 ( V_3 , V_88 , - 1 , - 1 ) ;
V_7 -> V_87 ( V_3 , V_89 , 0x00 , - 1 ) ;
* V_75 = V_7 -> V_90 ( V_3 ) ;
* V_76 = V_7 -> V_90 ( V_3 ) ;
} else {
V_7 -> V_86 ( V_3 , V_4 ) ;
V_7 -> V_87 ( V_3 , V_88 , - 1 , - 1 ) ;
V_7 -> V_87 ( V_3 , V_89 , 0x00 , - 1 ) ;
if ( * V_75 != V_7 -> V_90 ( V_3 )
|| * V_76 != V_7 -> V_90 ( V_3 ) ) {
V_66 = - V_91 ;
goto V_85;
}
V_7 -> V_92 ++ ;
V_3 -> V_55 += V_7 -> V_93 ;
}
F_33 ( & V_62 -> V_68 , L_7 , V_4 , V_74 ) ;
return 0 ;
V_85:
F_33 ( & V_62 -> V_68 , L_8 , V_74 ) ;
V_9 &= ~ ( F_31 ( V_74 - 1 ) ) ;
F_5 ( V_9 , V_5 -> V_11 + V_12 ) ;
F_30 ( V_77 , V_94 ) ;
F_25 ( V_5 -> V_82 [ V_74 - 1 ] ,
V_5 -> V_16 [ V_74 - 1 ] ) ;
V_83:
F_34 ( V_77 ) ;
V_81:
return V_66 ;
}
static int F_35 ( struct V_61 * V_62 )
{
int V_66 ;
struct V_1 * V_5 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_95 * V_96 = F_36 ( & V_62 -> V_68 ) ;
T_5 V_4 , V_97 ;
T_3 V_75 = 0 , V_76 = 0 ;
V_5 = F_37 ( sizeof( * V_5 ) , V_98 ) ;
if ( ! V_5 )
return - V_99 ;
V_66 = F_18 ( V_62 , L_9 , & V_5 -> V_100 , & V_5 -> V_11 ) ;
if ( V_66 )
goto V_101;
V_5 -> V_28 = F_38 ( & V_62 -> V_68 , L_10 , V_102 ) ;
if ( F_39 ( V_5 -> V_28 ) ) {
V_66 = F_40 ( V_5 -> V_28 ) ;
F_20 ( & V_62 -> V_68 , L_11 ,
V_66 ) ;
goto V_103;
}
V_3 = & V_5 -> V_3 ;
V_7 = & V_5 -> V_7 ;
V_3 -> V_8 = V_7 ;
V_3 -> V_68 . V_104 = & V_62 -> V_68 ;
V_3 -> V_63 = L_12 ;
V_7 -> V_54 . V_105 = F_12 ;
V_7 -> V_54 . V_106 = F_13 ;
V_7 -> V_54 . V_107 = F_16 ;
V_7 -> V_54 . V_29 = V_108 ;
V_7 -> V_54 . V_55 = 512 ;
V_7 -> V_54 . V_109 = 9 ;
V_7 -> V_54 . V_110 = 4 ;
if ( V_96 )
V_7 -> V_54 . V_111 = V_96 -> V_112 ;
V_7 -> V_113 = 50 ;
V_7 -> V_114 = F_6 ;
V_7 -> V_86 = F_3 ;
if ( V_5 -> V_28 )
V_7 -> V_115 = F_10 ;
F_41 ( V_62 , V_5 ) ;
V_4 = 0 ;
for ( V_97 = 0 ; V_97 < V_116 ; V_97 ++ ) {
unsigned char V_74 ;
V_74 = V_96 ? V_96 -> V_14 [ V_97 ] : V_97 ^ 1 ;
if ( V_74 == 0 )
break;
if ( V_74 > V_116 ) {
F_29 ( & V_62 -> V_68 ,
L_13 , V_74 ) ;
continue;
}
V_5 -> V_14 [ V_4 ] = V_74 ;
if ( F_27 ( V_62 , V_5 , V_74 , V_4 ,
& V_75 , & V_76 ) == 0 )
V_4 ++ ;
else
V_5 -> V_14 [ V_4 ] = 0 ;
}
if ( V_4 == 0 ) {
F_20 ( & V_62 -> V_68 , L_14 ) ;
goto V_103;
}
if ( V_96 && V_96 -> V_117 ) {
V_96 -> V_117 ( V_62 , V_7 , & V_96 -> V_118 ,
& V_96 -> V_119 ) ;
}
V_66 = F_42 ( V_3 ) ;
if ( V_66 ) {
F_20 ( & V_62 -> V_68 , L_15 ) ;
goto V_120;
}
V_66 = F_43 ( V_3 , NULL , NULL ,
V_96 ? V_96 -> V_118 : NULL ,
V_96 ? V_96 -> V_119 : 0 ) ;
if ( V_66 ) {
F_20 ( & V_62 -> V_68 , L_16 ) ;
goto V_121;
}
F_33 ( & V_62 -> V_68 , L_17 ) ;
return 0 ;
V_121:
F_44 ( V_3 ) ;
V_120:
while ( V_4 -- ) {
unsigned char V_74 = V_5 -> V_14 [ V_4 ] ;
F_34 ( V_80 + V_74 - 1 ) ;
F_25 ( V_5 -> V_82 [ V_74 - 1 ] ,
V_5 -> V_16 [ V_74 - 1 ] ) ;
}
F_5 ( 0 , V_5 -> V_11 + V_12 ) ;
V_103:
F_25 ( V_5 -> V_100 , V_5 -> V_11 ) ;
V_101:
F_45 ( V_5 ) ;
return V_66 ;
}
static int F_46 ( struct V_61 * V_62 )
{
struct V_1 * V_5 = F_47 ( V_62 ) ;
T_5 V_41 ;
F_44 ( & V_5 -> V_3 ) ;
F_5 ( 0 , V_5 -> V_11 + V_12 ) ;
for ( V_41 = 0 ; V_41 < V_116 ; ++ V_41 ) {
unsigned char V_74 = V_5 -> V_14 [ V_41 ] ;
if ( V_74 != 0 ) {
F_25 ( V_5 -> V_82 [ V_74 - 1 ] ,
V_5 -> V_16 [ V_74 - 1 ] ) ;
F_34 ( V_80 + V_74 - 1 ) ;
}
}
F_25 ( V_5 -> V_100 , V_5 -> V_11 ) ;
F_45 ( V_5 ) ;
return 0 ;
}
