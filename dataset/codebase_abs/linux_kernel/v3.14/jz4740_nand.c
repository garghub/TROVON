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
return F_11 ( V_5 -> V_28 -> V_29 ) ;
}
static void F_12 ( struct V_2 * V_3 , int V_30 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_20 ;
F_5 ( 0 , V_5 -> V_11 + V_31 ) ;
V_20 = F_4 ( V_5 -> V_11 + V_32 ) ;
V_20 |= V_33 ;
V_20 |= V_34 ;
V_20 |= V_35 ;
switch ( V_30 ) {
case V_36 :
V_20 &= ~ V_37 ;
V_5 -> V_38 = true ;
break;
case V_39 :
V_20 |= V_37 ;
V_5 -> V_38 = false ;
break;
default:
break;
}
F_5 ( V_20 , V_5 -> V_11 + V_32 ) ;
}
static int F_13 ( struct V_2 * V_3 , const T_3 * V_19 ,
T_3 * V_40 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_20 , V_41 ;
int V_42 ;
unsigned int V_43 = 1000 ;
static T_3 V_44 [] = { 0xcd , 0x9d , 0x90 , 0x58 , 0xf4 ,
0x8b , 0xff , 0xb7 , 0x6f } ;
if ( V_5 -> V_38 )
return 0 ;
do {
V_41 = F_4 ( V_5 -> V_11 + V_31 ) ;
} while ( ! ( V_41 & V_45 ) && -- V_43 );
if ( V_43 == 0 )
return - 1 ;
V_20 = F_4 ( V_5 -> V_11 + V_32 ) ;
V_20 &= ~ V_34 ;
F_5 ( V_20 , V_5 -> V_11 + V_32 ) ;
for ( V_42 = 0 ; V_42 < 9 ; ++ V_42 )
V_40 [ V_42 ] = F_14 ( V_5 -> V_11 + V_46 + V_42 ) ;
if ( memcmp ( V_40 , V_44 , 9 ) == 0 )
memset ( V_40 , 0xff , 9 ) ;
return 0 ;
}
static void F_15 ( T_3 * V_19 , int V_47 , int V_48 )
{
int V_49 = V_47 & 0x7 ;
T_4 V_50 ;
V_47 += ( V_47 >> 3 ) ;
V_50 = V_19 [ V_47 ] ;
V_50 |= V_19 [ V_47 + 1 ] << 8 ;
V_48 ^= ( V_50 >> V_49 ) & 0x1ff ;
V_50 &= ~ ( 0x1ff << V_49 ) ;
V_50 |= ( V_48 << V_49 ) ;
V_19 [ V_47 ] = V_50 & 0xff ;
V_19 [ V_47 + 1 ] = ( V_50 >> 8 ) & 0xff ;
}
static int F_16 ( struct V_2 * V_3 , T_3 * V_19 ,
T_3 * V_51 , T_3 * V_52 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_42 , V_53 , V_47 ;
T_1 V_20 , V_41 , error ;
T_1 V_54 ;
unsigned int V_43 = 1000 ;
V_54 = V_51 [ 0 ] ;
if ( V_54 == 0xff ) {
for ( V_42 = 1 ; V_42 < 9 ; ++ V_42 )
V_54 &= V_51 [ V_42 ] ;
V_54 &= V_19 [ 0 ] ;
V_54 &= V_19 [ V_5 -> V_7 . V_55 . V_56 / 2 ] ;
V_54 &= V_19 [ V_5 -> V_7 . V_55 . V_56 - 1 ] ;
if ( V_54 == 0xff ) {
for ( V_42 = 1 ; V_42 < V_5 -> V_7 . V_55 . V_56 - 1 ; ++ V_42 )
V_54 &= V_19 [ V_42 ] ;
if ( V_54 == 0xff )
return 0 ;
}
}
for ( V_42 = 0 ; V_42 < 9 ; ++ V_42 )
F_9 ( V_51 [ V_42 ] , V_5 -> V_11 + V_46 + V_42 ) ;
V_20 = F_4 ( V_5 -> V_11 + V_32 ) ;
V_20 |= V_57 ;
F_5 ( V_20 , V_5 -> V_11 + V_32 ) ;
do {
V_41 = F_4 ( V_5 -> V_11 + V_31 ) ;
} while ( ! ( V_41 & V_58 ) && -- V_43 );
if ( V_43 == 0 )
return - 1 ;
V_20 = F_4 ( V_5 -> V_11 + V_32 ) ;
V_20 &= ~ V_34 ;
F_5 ( V_20 , V_5 -> V_11 + V_32 ) ;
if ( V_41 & V_59 ) {
if ( V_41 & V_60 )
return - 1 ;
V_53 = ( V_41 & V_61 ) >> 29 ;
for ( V_42 = 0 ; V_42 < V_53 ; ++ V_42 ) {
error = F_4 ( V_5 -> V_11 + F_17 ( V_42 ) ) ;
V_47 = ( ( error >> 16 ) & 0x1ff ) - 1 ;
if ( V_47 >= 0 && V_47 < 512 )
F_15 ( V_19 , V_47 , error & 0x1ff ) ;
}
return V_53 ;
}
return 0 ;
}
static int F_18 ( struct V_62 * V_63 ,
const char * V_64 , struct V_65 * * V_66 , void * T_2 * V_11 )
{
int V_67 ;
* V_66 = F_19 ( V_63 , V_68 , V_64 ) ;
if ( ! * V_66 ) {
F_20 ( & V_63 -> V_69 , L_1 , V_64 ) ;
V_67 = - V_70 ;
goto V_71;
}
* V_66 = F_21 ( ( * V_66 ) -> V_72 , F_22 ( * V_66 ) ,
V_63 -> V_64 ) ;
if ( ! * V_66 ) {
F_20 ( & V_63 -> V_69 , L_2 , V_64 ) ;
V_67 = - V_73 ;
goto V_71;
}
* V_11 = F_23 ( ( * V_66 ) -> V_72 , F_22 ( * V_66 ) ) ;
if ( ! * V_11 ) {
F_20 ( & V_63 -> V_69 , L_3 , V_64 ) ;
V_67 = - V_73 ;
goto V_74;
}
return 0 ;
V_74:
F_24 ( ( * V_66 ) -> V_72 , F_22 ( * V_66 ) ) ;
V_71:
* V_66 = NULL ;
* V_11 = NULL ;
return V_67 ;
}
static inline void F_25 ( struct V_65 * V_66 ,
void T_2 * V_11 )
{
F_26 ( V_11 ) ;
F_24 ( V_66 -> V_72 , F_22 ( V_66 ) ) ;
}
static int F_27 ( struct V_62 * V_63 ,
struct V_1 * V_5 , unsigned char V_75 ,
T_5 V_4 , T_3 * V_76 ,
T_3 * V_77 )
{
int V_67 ;
int V_78 ;
char V_79 [ 9 ] ;
char V_80 [ 6 ] ;
T_1 V_9 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_7 ;
V_78 = V_81 + V_75 - 1 ;
sprintf ( V_79 , L_4 , V_75 ) ;
V_67 = F_28 ( V_78 , V_79 ) ;
if ( V_67 ) {
F_29 ( & V_63 -> V_69 ,
L_5 ,
V_79 , V_78 , V_67 ) ;
goto V_82;
}
sprintf ( V_80 , L_6 , V_75 ) ;
V_67 = F_18 ( V_63 , V_80 ,
& V_5 -> V_83 [ V_75 - 1 ] ,
& V_5 -> V_16 [ V_75 - 1 ] ) ;
if ( V_67 )
goto V_84;
F_30 ( V_78 , V_85 ) ;
V_9 = F_4 ( V_5 -> V_11 + V_12 ) ;
V_9 |= F_31 ( V_75 - 1 ) ;
F_5 ( V_9 , V_5 -> V_11 + V_12 ) ;
if ( V_4 == 0 ) {
V_67 = F_32 ( V_3 , 1 , NULL ) ;
if ( V_67 )
goto V_86;
V_7 -> V_87 ( V_3 , 0 ) ;
V_7 -> V_88 ( V_3 , V_89 , - 1 , - 1 ) ;
V_7 -> V_88 ( V_3 , V_90 , 0x00 , - 1 ) ;
* V_76 = V_7 -> V_91 ( V_3 ) ;
* V_77 = V_7 -> V_91 ( V_3 ) ;
} else {
V_7 -> V_87 ( V_3 , V_4 ) ;
V_7 -> V_88 ( V_3 , V_89 , - 1 , - 1 ) ;
V_7 -> V_88 ( V_3 , V_90 , 0x00 , - 1 ) ;
if ( * V_76 != V_7 -> V_91 ( V_3 )
|| * V_77 != V_7 -> V_91 ( V_3 ) ) {
V_67 = - V_92 ;
goto V_86;
}
V_7 -> V_93 ++ ;
V_3 -> V_56 += V_7 -> V_94 ;
}
F_33 ( & V_63 -> V_69 , L_7 , V_4 , V_75 ) ;
return 0 ;
V_86:
F_33 ( & V_63 -> V_69 , L_8 , V_75 ) ;
V_9 &= ~ ( F_31 ( V_75 - 1 ) ) ;
F_5 ( V_9 , V_5 -> V_11 + V_12 ) ;
F_30 ( V_78 , V_95 ) ;
F_25 ( V_5 -> V_83 [ V_75 - 1 ] ,
V_5 -> V_16 [ V_75 - 1 ] ) ;
V_84:
F_34 ( V_78 ) ;
V_82:
return V_67 ;
}
static int F_35 ( struct V_62 * V_63 )
{
int V_67 ;
struct V_1 * V_5 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_96 * V_28 = F_36 ( & V_63 -> V_69 ) ;
T_5 V_4 , V_97 ;
T_3 V_76 = 0 , V_77 = 0 ;
V_5 = F_37 ( sizeof( * V_5 ) , V_98 ) ;
if ( ! V_5 )
return - V_99 ;
V_67 = F_18 ( V_63 , L_9 , & V_5 -> V_100 , & V_5 -> V_11 ) ;
if ( V_67 )
goto V_101;
if ( V_28 && F_38 ( V_28 -> V_29 ) ) {
V_67 = F_28 ( V_28 -> V_29 , L_10 ) ;
if ( V_67 ) {
F_20 ( & V_63 -> V_69 ,
L_11 ,
V_28 -> V_29 , V_67 ) ;
goto V_102;
}
}
V_3 = & V_5 -> V_3 ;
V_7 = & V_5 -> V_7 ;
V_3 -> V_8 = V_7 ;
V_3 -> V_103 = V_104 ;
V_3 -> V_64 = L_12 ;
V_7 -> V_55 . V_105 = F_12 ;
V_7 -> V_55 . V_106 = F_13 ;
V_7 -> V_55 . V_107 = F_16 ;
V_7 -> V_55 . V_30 = V_108 ;
V_7 -> V_55 . V_56 = 512 ;
V_7 -> V_55 . V_109 = 9 ;
V_7 -> V_55 . V_110 = 4 ;
if ( V_28 )
V_7 -> V_55 . V_111 = V_28 -> V_112 ;
V_7 -> V_113 = 50 ;
V_7 -> V_114 = F_6 ;
V_7 -> V_87 = F_3 ;
if ( V_28 && F_38 ( V_28 -> V_29 ) )
V_7 -> V_115 = F_10 ;
V_5 -> V_28 = V_28 ;
F_39 ( V_63 , V_5 ) ;
V_4 = 0 ;
for ( V_97 = 0 ; V_97 < V_116 ; V_97 ++ ) {
unsigned char V_75 ;
V_75 = V_28 ? V_28 -> V_14 [ V_97 ] : V_97 ^ 1 ;
if ( V_75 == 0 )
break;
if ( V_75 > V_116 ) {
F_29 ( & V_63 -> V_69 ,
L_13 , V_75 ) ;
continue;
}
V_5 -> V_14 [ V_4 ] = V_75 ;
if ( F_27 ( V_63 , V_5 , V_75 , V_4 ,
& V_76 , & V_77 ) == 0 )
V_4 ++ ;
else
V_5 -> V_14 [ V_4 ] = 0 ;
}
if ( V_4 == 0 ) {
F_20 ( & V_63 -> V_69 , L_14 ) ;
goto V_117;
}
if ( V_28 && V_28 -> V_118 ) {
V_28 -> V_118 ( V_63 , V_7 , & V_28 -> V_119 ,
& V_28 -> V_120 ) ;
}
V_67 = F_40 ( V_3 ) ;
if ( V_67 ) {
F_20 ( & V_63 -> V_69 , L_15 ) ;
goto V_121;
}
V_67 = F_41 ( V_3 , NULL , NULL ,
V_28 ? V_28 -> V_119 : NULL ,
V_28 ? V_28 -> V_120 : 0 ) ;
if ( V_67 ) {
F_20 ( & V_63 -> V_69 , L_16 ) ;
goto V_122;
}
F_33 ( & V_63 -> V_69 , L_17 ) ;
return 0 ;
V_122:
F_42 ( V_3 ) ;
V_121:
while ( V_4 -- ) {
unsigned char V_75 = V_5 -> V_14 [ V_4 ] ;
F_34 ( V_81 + V_75 - 1 ) ;
F_25 ( V_5 -> V_83 [ V_75 - 1 ] ,
V_5 -> V_16 [ V_75 - 1 ] ) ;
}
F_5 ( 0 , V_5 -> V_11 + V_12 ) ;
V_117:
if ( V_28 && F_38 ( V_28 -> V_29 ) )
F_34 ( V_28 -> V_29 ) ;
V_102:
F_25 ( V_5 -> V_100 , V_5 -> V_11 ) ;
V_101:
F_43 ( V_5 ) ;
return V_67 ;
}
static int F_44 ( struct V_62 * V_63 )
{
struct V_1 * V_5 = F_45 ( V_63 ) ;
struct V_96 * V_28 = F_36 ( & V_63 -> V_69 ) ;
T_5 V_42 ;
F_42 ( & V_5 -> V_3 ) ;
F_5 ( 0 , V_5 -> V_11 + V_12 ) ;
for ( V_42 = 0 ; V_42 < V_116 ; ++ V_42 ) {
unsigned char V_75 = V_5 -> V_14 [ V_42 ] ;
if ( V_75 != 0 ) {
F_25 ( V_5 -> V_83 [ V_75 - 1 ] ,
V_5 -> V_16 [ V_75 - 1 ] ) ;
F_34 ( V_81 + V_75 - 1 ) ;
}
}
if ( V_28 && F_38 ( V_28 -> V_29 ) )
F_34 ( V_28 -> V_29 ) ;
F_25 ( V_5 -> V_100 , V_5 -> V_11 ) ;
F_43 ( V_5 ) ;
return 0 ;
}
