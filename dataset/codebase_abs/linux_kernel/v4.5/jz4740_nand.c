static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static void F_4 ( struct V_2 * V_3 , int V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_4 = F_3 ( V_3 ) ;
T_1 V_8 ;
int V_9 ;
V_8 = F_5 ( V_6 -> V_10 + V_11 ) ;
V_8 &= ~ V_12 ;
if ( V_5 == - 1 ) {
V_9 = - 1 ;
} else {
V_9 = V_6 -> V_13 [ V_5 ] - 1 ;
V_4 -> V_14 = V_6 -> V_15 [ V_9 ] ;
V_4 -> V_16 = V_6 -> V_15 [ V_9 ] ;
}
F_6 ( V_8 , V_6 -> V_10 + V_11 ) ;
V_6 -> V_17 = V_9 ;
}
static void F_7 ( struct V_2 * V_3 , int V_18 , unsigned int V_8 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_4 = F_3 ( V_3 ) ;
T_1 V_19 ;
void T_2 * V_15 = V_6 -> V_15 [ V_6 -> V_17 ] ;
F_8 ( V_6 -> V_17 < 0 ) ;
if ( V_8 & V_20 ) {
F_8 ( ( V_8 & V_21 ) && ( V_8 & V_22 ) ) ;
if ( V_8 & V_21 )
V_15 += V_23 ;
else if ( V_8 & V_22 )
V_15 += V_24 ;
V_4 -> V_16 = V_15 ;
V_19 = F_5 ( V_6 -> V_10 + V_11 ) ;
if ( V_8 & V_25 )
V_19 |= F_9 ( V_6 -> V_17 ) ;
else
V_19 &= ~ F_9 ( V_6 -> V_17 ) ;
F_6 ( V_19 , V_6 -> V_10 + V_11 ) ;
}
if ( V_18 != V_26 )
F_10 ( V_18 , V_4 -> V_16 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_12 ( V_6 -> V_27 ) ;
}
static void F_13 ( struct V_2 * V_3 , int V_28 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_19 ;
F_6 ( 0 , V_6 -> V_10 + V_29 ) ;
V_19 = F_5 ( V_6 -> V_10 + V_30 ) ;
V_19 |= V_31 ;
V_19 |= V_32 ;
V_19 |= V_33 ;
switch ( V_28 ) {
case V_34 :
V_19 &= ~ V_35 ;
V_6 -> V_36 = true ;
break;
case V_37 :
V_19 |= V_35 ;
V_6 -> V_36 = false ;
break;
default:
break;
}
F_6 ( V_19 , V_6 -> V_10 + V_30 ) ;
}
static int F_14 ( struct V_2 * V_3 , const T_3 * V_18 ,
T_3 * V_38 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_19 , V_39 ;
int V_40 ;
unsigned int V_41 = 1000 ;
static T_3 V_42 [] = { 0xcd , 0x9d , 0x90 , 0x58 , 0xf4 ,
0x8b , 0xff , 0xb7 , 0x6f } ;
if ( V_6 -> V_36 )
return 0 ;
do {
V_39 = F_5 ( V_6 -> V_10 + V_29 ) ;
} while ( ! ( V_39 & V_43 ) && -- V_41 );
if ( V_41 == 0 )
return - 1 ;
V_19 = F_5 ( V_6 -> V_10 + V_30 ) ;
V_19 &= ~ V_32 ;
F_6 ( V_19 , V_6 -> V_10 + V_30 ) ;
for ( V_40 = 0 ; V_40 < 9 ; ++ V_40 )
V_38 [ V_40 ] = F_15 ( V_6 -> V_10 + V_44 + V_40 ) ;
if ( memcmp ( V_38 , V_42 , 9 ) == 0 )
memset ( V_38 , 0xff , 9 ) ;
return 0 ;
}
static void F_16 ( T_3 * V_18 , int V_45 , int V_46 )
{
int V_47 = V_45 & 0x7 ;
T_4 V_48 ;
V_45 += ( V_45 >> 3 ) ;
V_48 = V_18 [ V_45 ] ;
V_48 |= V_18 [ V_45 + 1 ] << 8 ;
V_46 ^= ( V_48 >> V_47 ) & 0x1ff ;
V_48 &= ~ ( 0x1ff << V_47 ) ;
V_48 |= ( V_46 << V_47 ) ;
V_18 [ V_45 ] = V_48 & 0xff ;
V_18 [ V_45 + 1 ] = ( V_48 >> 8 ) & 0xff ;
}
static int F_17 ( struct V_2 * V_3 , T_3 * V_18 ,
T_3 * V_49 , T_3 * V_50 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_40 , V_51 , V_45 ;
T_1 V_19 , V_39 , error ;
T_1 V_52 ;
unsigned int V_41 = 1000 ;
for ( V_40 = 0 ; V_40 < 9 ; ++ V_40 )
F_10 ( V_49 [ V_40 ] , V_6 -> V_10 + V_44 + V_40 ) ;
V_19 = F_5 ( V_6 -> V_10 + V_30 ) ;
V_19 |= V_53 ;
F_6 ( V_19 , V_6 -> V_10 + V_30 ) ;
do {
V_39 = F_5 ( V_6 -> V_10 + V_29 ) ;
} while ( ! ( V_39 & V_54 ) && -- V_41 );
if ( V_41 == 0 )
return - V_55 ;
V_19 = F_5 ( V_6 -> V_10 + V_30 ) ;
V_19 &= ~ V_32 ;
F_6 ( V_19 , V_6 -> V_10 + V_30 ) ;
if ( V_39 & V_56 ) {
if ( V_39 & V_57 )
return - V_58 ;
V_51 = ( V_39 & V_59 ) >> 29 ;
for ( V_40 = 0 ; V_40 < V_51 ; ++ V_40 ) {
error = F_5 ( V_6 -> V_10 + F_18 ( V_40 ) ) ;
V_45 = ( ( error >> 16 ) & 0x1ff ) - 1 ;
if ( V_45 >= 0 && V_45 < 512 )
F_16 ( V_18 , V_45 , error & 0x1ff ) ;
}
return V_51 ;
}
return 0 ;
}
static int F_19 ( struct V_60 * V_61 ,
const char * V_62 , struct V_63 * * V_64 , void * T_2 * V_10 )
{
int V_65 ;
* V_64 = F_20 ( V_61 , V_66 , V_62 ) ;
if ( ! * V_64 ) {
F_21 ( & V_61 -> V_67 , L_1 , V_62 ) ;
V_65 = - V_68 ;
goto V_69;
}
* V_64 = F_22 ( ( * V_64 ) -> V_70 , F_23 ( * V_64 ) ,
V_61 -> V_62 ) ;
if ( ! * V_64 ) {
F_21 ( & V_61 -> V_67 , L_2 , V_62 ) ;
V_65 = - V_71 ;
goto V_69;
}
* V_10 = F_24 ( ( * V_64 ) -> V_70 , F_23 ( * V_64 ) ) ;
if ( ! * V_10 ) {
F_21 ( & V_61 -> V_67 , L_3 , V_62 ) ;
V_65 = - V_71 ;
goto V_72;
}
return 0 ;
V_72:
F_25 ( ( * V_64 ) -> V_70 , F_23 ( * V_64 ) ) ;
V_69:
* V_64 = NULL ;
* V_10 = NULL ;
return V_65 ;
}
static inline void F_26 ( struct V_63 * V_64 ,
void T_2 * V_10 )
{
F_27 ( V_10 ) ;
F_25 ( V_64 -> V_70 , F_23 ( V_64 ) ) ;
}
static int F_28 ( struct V_60 * V_61 ,
struct V_1 * V_6 , unsigned char V_73 ,
T_5 V_5 , T_3 * V_74 ,
T_3 * V_75 )
{
int V_65 ;
int V_76 ;
char V_77 [ 9 ] ;
char V_78 [ 6 ] ;
T_1 V_8 ;
struct V_7 * V_4 = & V_6 -> V_4 ;
struct V_2 * V_3 = F_29 ( V_4 ) ;
V_76 = V_79 + V_73 - 1 ;
sprintf ( V_77 , L_4 , V_73 ) ;
V_65 = F_30 ( V_76 , V_77 ) ;
if ( V_65 ) {
F_31 ( & V_61 -> V_67 ,
L_5 ,
V_77 , V_76 , V_65 ) ;
goto V_80;
}
sprintf ( V_78 , L_6 , V_73 ) ;
V_65 = F_19 ( V_61 , V_78 ,
& V_6 -> V_81 [ V_73 - 1 ] ,
& V_6 -> V_15 [ V_73 - 1 ] ) ;
if ( V_65 )
goto V_82;
F_32 ( V_76 , V_83 ) ;
V_8 = F_5 ( V_6 -> V_10 + V_11 ) ;
V_8 |= F_33 ( V_73 - 1 ) ;
F_6 ( V_8 , V_6 -> V_10 + V_11 ) ;
if ( V_5 == 0 ) {
V_65 = F_34 ( V_3 , 1 , NULL ) ;
if ( V_65 )
goto V_84;
V_4 -> V_85 ( V_3 , 0 ) ;
V_4 -> V_86 ( V_3 , V_87 , - 1 , - 1 ) ;
V_4 -> V_86 ( V_3 , V_88 , 0x00 , - 1 ) ;
* V_74 = V_4 -> V_89 ( V_3 ) ;
* V_75 = V_4 -> V_89 ( V_3 ) ;
} else {
V_4 -> V_85 ( V_3 , V_5 ) ;
V_4 -> V_86 ( V_3 , V_87 , - 1 , - 1 ) ;
V_4 -> V_86 ( V_3 , V_88 , 0x00 , - 1 ) ;
if ( * V_74 != V_4 -> V_89 ( V_3 )
|| * V_75 != V_4 -> V_89 ( V_3 ) ) {
V_65 = - V_90 ;
goto V_84;
}
V_4 -> V_91 ++ ;
V_3 -> V_92 += V_4 -> V_93 ;
}
F_35 ( & V_61 -> V_67 , L_7 , V_5 , V_73 ) ;
return 0 ;
V_84:
F_35 ( & V_61 -> V_67 , L_8 , V_73 ) ;
V_8 &= ~ ( F_33 ( V_73 - 1 ) ) ;
F_6 ( V_8 , V_6 -> V_10 + V_11 ) ;
F_32 ( V_76 , V_94 ) ;
F_26 ( V_6 -> V_81 [ V_73 - 1 ] ,
V_6 -> V_15 [ V_73 - 1 ] ) ;
V_82:
F_36 ( V_76 ) ;
V_80:
return V_65 ;
}
static int F_37 ( struct V_60 * V_61 )
{
int V_65 ;
struct V_1 * V_6 ;
struct V_7 * V_4 ;
struct V_2 * V_3 ;
struct V_95 * V_96 = F_38 ( & V_61 -> V_67 ) ;
T_5 V_5 , V_97 ;
T_3 V_74 = 0 , V_75 = 0 ;
V_6 = F_39 ( sizeof( * V_6 ) , V_98 ) ;
if ( ! V_6 )
return - V_99 ;
V_65 = F_19 ( V_61 , L_9 , & V_6 -> V_100 , & V_6 -> V_10 ) ;
if ( V_65 )
goto V_101;
V_6 -> V_27 = F_40 ( & V_61 -> V_67 , L_10 , V_102 ) ;
if ( F_41 ( V_6 -> V_27 ) ) {
V_65 = F_42 ( V_6 -> V_27 ) ;
F_21 ( & V_61 -> V_67 , L_11 ,
V_65 ) ;
goto V_103;
}
V_4 = & V_6 -> V_4 ;
V_3 = F_29 ( V_4 ) ;
V_3 -> V_67 . V_104 = & V_61 -> V_67 ;
V_3 -> V_62 = L_12 ;
V_4 -> V_105 . V_106 = F_13 ;
V_4 -> V_105 . V_107 = F_14 ;
V_4 -> V_105 . V_108 = F_17 ;
V_4 -> V_105 . V_28 = V_109 ;
V_4 -> V_105 . V_92 = 512 ;
V_4 -> V_105 . V_110 = 9 ;
V_4 -> V_105 . V_111 = 4 ;
V_4 -> V_105 . V_112 = V_113 ;
if ( V_96 )
V_4 -> V_105 . V_114 = V_96 -> V_115 ;
V_4 -> V_116 = 50 ;
V_4 -> V_117 = F_7 ;
V_4 -> V_85 = F_4 ;
if ( V_6 -> V_27 )
V_4 -> V_118 = F_11 ;
F_43 ( V_61 , V_6 ) ;
V_5 = 0 ;
for ( V_97 = 0 ; V_97 < V_119 ; V_97 ++ ) {
unsigned char V_73 ;
V_73 = V_96 ? V_96 -> V_13 [ V_97 ] : V_97 ^ 1 ;
if ( V_73 == 0 )
break;
if ( V_73 > V_119 ) {
F_31 ( & V_61 -> V_67 ,
L_13 , V_73 ) ;
continue;
}
V_6 -> V_13 [ V_5 ] = V_73 ;
if ( F_28 ( V_61 , V_6 , V_73 , V_5 ,
& V_74 , & V_75 ) == 0 )
V_5 ++ ;
else
V_6 -> V_13 [ V_5 ] = 0 ;
}
if ( V_5 == 0 ) {
F_21 ( & V_61 -> V_67 , L_14 ) ;
goto V_103;
}
if ( V_96 && V_96 -> V_120 ) {
V_96 -> V_120 ( V_61 , V_4 , & V_96 -> V_121 ,
& V_96 -> V_122 ) ;
}
V_65 = F_44 ( V_3 ) ;
if ( V_65 ) {
F_21 ( & V_61 -> V_67 , L_15 ) ;
goto V_123;
}
V_65 = F_45 ( V_3 , NULL , NULL ,
V_96 ? V_96 -> V_121 : NULL ,
V_96 ? V_96 -> V_122 : 0 ) ;
if ( V_65 ) {
F_21 ( & V_61 -> V_67 , L_16 ) ;
goto V_124;
}
F_35 ( & V_61 -> V_67 , L_17 ) ;
return 0 ;
V_124:
F_46 ( V_3 ) ;
V_123:
while ( V_5 -- ) {
unsigned char V_73 = V_6 -> V_13 [ V_5 ] ;
F_36 ( V_79 + V_73 - 1 ) ;
F_26 ( V_6 -> V_81 [ V_73 - 1 ] ,
V_6 -> V_15 [ V_73 - 1 ] ) ;
}
F_6 ( 0 , V_6 -> V_10 + V_11 ) ;
V_103:
F_26 ( V_6 -> V_100 , V_6 -> V_10 ) ;
V_101:
F_47 ( V_6 ) ;
return V_65 ;
}
static int F_48 ( struct V_60 * V_61 )
{
struct V_1 * V_6 = F_49 ( V_61 ) ;
T_5 V_40 ;
F_46 ( F_29 ( & V_6 -> V_4 ) ) ;
F_6 ( 0 , V_6 -> V_10 + V_11 ) ;
for ( V_40 = 0 ; V_40 < V_119 ; ++ V_40 ) {
unsigned char V_73 = V_6 -> V_13 [ V_40 ] ;
if ( V_73 != 0 ) {
F_26 ( V_6 -> V_81 [ V_73 - 1 ] ,
V_6 -> V_15 [ V_73 - 1 ] ) ;
F_36 ( V_79 + V_73 - 1 ) ;
}
}
F_26 ( V_6 -> V_100 , V_6 -> V_10 ) ;
F_47 ( V_6 ) ;
return 0 ;
}
