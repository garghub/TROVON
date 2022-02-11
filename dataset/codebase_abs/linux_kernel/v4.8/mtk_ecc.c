static inline void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_7 ;
int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + F_3 ( V_4 ) , V_7 ,
V_7 & V_10 ,
10 , V_11 ) ;
if ( V_8 )
F_4 ( V_6 , L_1 ,
V_4 == V_12 ? L_2 : L_3 ) ;
}
static T_2 F_5 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
enum V_3 V_4 ;
T_1 V_15 , V_16 ;
V_15 = F_6 ( V_2 -> V_9 + V_17 ) & V_18 ;
if ( V_15 ) {
V_4 = V_19 ;
V_15 = F_6 ( V_2 -> V_9 + V_20 ) ;
if ( V_15 & V_2 -> V_21 ) {
V_2 -> V_21 = 0 ;
F_7 ( & V_2 -> V_22 ) ;
} else {
return V_23 ;
}
} else {
V_16 = F_8 ( V_2 -> V_9 + V_24 ) & V_18 ;
if ( V_16 ) {
V_4 = V_12 ;
F_7 ( & V_2 -> V_22 ) ;
} else {
return V_25 ;
}
}
F_9 ( 0 , V_2 -> V_9 + F_10 ( V_4 ) ) ;
return V_23 ;
}
static void F_11 ( struct V_1 * V_2 , struct F_11 * V_26 )
{
T_1 V_27 = V_28 , V_29 , V_30 ;
T_1 V_31 ;
switch ( V_26 -> V_32 ) {
case 4 :
V_27 = V_28 ;
break;
case 6 :
V_27 = V_33 ;
break;
case 8 :
V_27 = V_34 ;
break;
case 10 :
V_27 = V_35 ;
break;
case 12 :
V_27 = V_36 ;
break;
case 14 :
V_27 = V_37 ;
break;
case 16 :
V_27 = V_38 ;
break;
case 18 :
V_27 = V_39 ;
break;
case 20 :
V_27 = V_40 ;
break;
case 22 :
V_27 = V_41 ;
break;
case 24 :
V_27 = V_42 ;
break;
case 28 :
V_27 = V_43 ;
break;
case 32 :
V_27 = V_44 ;
break;
case 36 :
V_27 = V_45 ;
break;
case 40 :
V_27 = V_46 ;
break;
case 44 :
V_27 = V_47 ;
break;
case 48 :
V_27 = V_48 ;
break;
case 52 :
V_27 = V_49 ;
break;
case 56 :
V_27 = V_50 ;
break;
case 60 :
V_27 = V_51 ;
break;
default:
F_12 ( V_2 -> V_6 , L_4 ,
V_26 -> V_32 ) ;
}
if ( V_26 -> V_4 == V_12 ) {
V_30 = V_26 -> V_52 << 3 ;
V_31 = V_27 | ( V_26 -> V_53 << V_54 ) ;
V_31 |= ( V_30 << V_55 ) ;
F_9 ( V_31 , V_2 -> V_9 + V_56 ) ;
if ( V_26 -> V_53 != V_57 )
F_9 ( F_13 ( V_26 -> V_58 ) ,
V_2 -> V_9 + V_59 ) ;
} else {
V_29 = ( V_26 -> V_52 << 3 ) +
V_26 -> V_32 * V_60 ;
V_31 = V_27 | ( V_26 -> V_53 << V_54 ) ;
V_31 |= ( V_29 << V_55 ) | V_61 ;
V_31 |= V_62 ;
F_9 ( V_31 , V_2 -> V_9 + V_63 ) ;
if ( V_26 -> V_21 )
V_2 -> V_21 = 1 << ( V_26 -> V_21 - 1 ) ;
}
}
void F_14 ( struct V_1 * V_2 , struct V_64 * V_65 ,
int V_21 )
{
T_1 V_66 , V_67 , V_68 ;
T_1 V_69 = 0 ;
V_65 -> V_70 = 0 ;
V_65 -> V_71 = 0 ;
for ( V_67 = 0 ; V_67 < V_21 ; V_67 ++ ) {
V_66 = ( V_67 >> 2 ) << 2 ;
V_68 = F_8 ( V_2 -> V_9 + V_72 + V_66 ) ;
V_68 = V_68 >> ( ( V_67 % 4 ) * 8 ) ;
V_68 &= V_73 ;
if ( V_68 == V_73 ) {
V_65 -> V_71 ++ ;
continue;
}
V_65 -> V_70 += V_68 ;
V_69 = F_15 ( T_1 , V_69 , V_68 ) ;
}
V_65 -> V_69 = V_69 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_74 ) ;
F_18 ( V_2 -> V_6 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_12 ) ;
F_20 ( V_75 , V_2 -> V_9 + V_76 ) ;
F_1 ( V_2 , V_19 ) ;
F_9 ( V_75 , V_2 -> V_9 + V_77 ) ;
}
static struct V_1 * F_21 ( struct V_78 * V_79 )
{
struct V_80 * V_81 ;
struct V_1 * V_2 ;
V_81 = F_22 ( V_79 ) ;
if ( ! V_81 || ! F_23 ( V_81 ) )
return F_24 ( - V_82 ) ;
F_25 ( & V_81 -> V_6 ) ;
V_2 = F_23 ( V_81 ) ;
F_26 ( V_2 -> V_74 ) ;
F_19 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_27 ( struct V_78 * V_83 )
{
struct V_1 * V_2 = NULL ;
struct V_78 * V_79 ;
V_79 = F_28 ( V_83 , L_5 , 0 ) ;
if ( V_79 ) {
V_2 = F_21 ( V_79 ) ;
F_29 ( V_79 ) ;
}
return V_2 ;
}
int F_30 ( struct V_1 * V_2 , struct F_11 * V_26 )
{
enum V_3 V_4 = V_26 -> V_4 ;
int V_8 ;
V_8 = F_31 ( & V_2 -> V_84 ) ;
if ( V_8 ) {
F_12 ( V_2 -> V_6 , L_6 ) ;
return V_8 ;
}
F_1 ( V_2 , V_4 ) ;
F_11 ( V_2 , V_26 ) ;
F_20 ( V_85 , V_2 -> V_9 + F_32 ( V_4 ) ) ;
F_33 ( & V_2 -> V_22 ) ;
F_20 ( V_18 , V_2 -> V_9 + F_10 ( V_4 ) ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
enum V_3 V_4 = V_12 ;
if ( F_6 ( V_2 -> V_9 + F_32 ( V_4 ) ) != V_85 )
V_4 = V_19 ;
F_1 ( V_2 , V_4 ) ;
F_20 ( 0 , V_2 -> V_9 + F_10 ( V_4 ) ) ;
F_20 ( V_75 , V_2 -> V_9 + F_32 ( V_4 ) ) ;
F_35 ( & V_2 -> V_84 ) ;
}
int F_36 ( struct V_1 * V_2 , enum V_3 V_4 )
{
int V_8 ;
V_8 = F_37 ( & V_2 -> V_22 , F_38 ( 500 ) ) ;
if ( ! V_8 ) {
F_12 ( V_2 -> V_6 , L_7 ,
( V_4 == V_12 ) ? L_2 : L_3 ) ;
return - V_86 ;
}
return 0 ;
}
int F_39 ( struct V_1 * V_2 , struct F_11 * V_26 ,
T_3 * V_87 , T_1 V_88 )
{
T_4 V_58 ;
T_3 * V_89 ;
T_1 V_52 , V_67 , V_7 ;
int V_8 = 0 ;
V_58 = F_40 ( V_2 -> V_6 , V_87 , V_88 , V_90 ) ;
V_8 = F_41 ( V_2 -> V_6 , V_58 ) ;
if ( V_8 ) {
F_12 ( V_2 -> V_6 , L_8 ) ;
return - V_91 ;
}
V_26 -> V_4 = V_12 ;
V_26 -> V_58 = V_58 ;
V_8 = F_30 ( V_2 , V_26 ) ;
if ( V_8 ) {
F_42 ( V_2 -> V_6 , V_58 , V_88 , V_90 ) ;
return V_8 ;
}
V_8 = F_36 ( V_2 , V_12 ) ;
if ( V_8 )
goto V_92;
F_1 ( V_2 , V_12 ) ;
V_52 = ( V_26 -> V_32 * V_60 + 7 ) >> 3 ;
V_89 = V_87 + V_88 ;
for ( V_67 = 0 ; V_67 < V_52 ; V_67 ++ ) {
if ( ( V_67 % 4 ) == 0 )
V_7 = F_8 ( V_2 -> V_9 + F_43 ( V_67 / 4 ) ) ;
V_89 [ V_67 ] = ( V_7 >> ( ( V_67 % 4 ) * 8 ) ) & 0xff ;
}
V_92:
F_42 ( V_2 -> V_6 , V_58 , V_88 , V_90 ) ;
F_34 ( V_2 ) ;
return V_8 ;
}
void F_44 ( T_1 * V_89 )
{
T_1 V_2 [] = { 4 , 6 , 8 , 10 , 12 , 14 , 16 , 18 , 20 , 22 , 24 , 28 , 32 , 36 ,
40 , 44 , 48 , 52 , 56 , 60 } ;
int V_67 ;
for ( V_67 = 0 ; V_67 < F_45 ( V_2 ) ; V_67 ++ ) {
if ( * V_89 <= V_2 [ V_67 ] ) {
if ( ! V_67 )
* V_89 = V_2 [ V_67 ] ;
else if ( * V_89 != V_2 [ V_67 ] )
* V_89 = V_2 [ V_67 - 1 ] ;
return;
}
}
* V_89 = V_2 [ F_45 ( V_2 ) - 1 ] ;
}
static int F_46 ( struct V_80 * V_81 )
{
struct V_5 * V_6 = & V_81 -> V_6 ;
struct V_1 * V_2 ;
struct V_93 * V_94 ;
int V_13 , V_8 ;
V_2 = F_47 ( V_6 , sizeof( * V_2 ) , V_95 ) ;
if ( ! V_2 )
return - V_96 ;
V_94 = F_48 ( V_81 , V_97 , 0 ) ;
V_2 -> V_9 = F_49 ( V_6 , V_94 ) ;
if ( F_50 ( V_2 -> V_9 ) ) {
F_12 ( V_6 , L_9 , F_51 ( V_2 -> V_9 ) ) ;
return F_51 ( V_2 -> V_9 ) ;
}
V_2 -> V_74 = F_52 ( V_6 , NULL ) ;
if ( F_50 ( V_2 -> V_74 ) ) {
F_12 ( V_6 , L_10 , F_51 ( V_2 -> V_74 ) ) ;
return F_51 ( V_2 -> V_74 ) ;
}
V_13 = F_53 ( V_81 , 0 ) ;
if ( V_13 < 0 ) {
F_12 ( V_6 , L_11 ) ;
return - V_91 ;
}
V_8 = F_54 ( V_6 , F_55 ( 32 ) ) ;
if ( V_8 ) {
F_12 ( V_6 , L_12 ) ;
return V_8 ;
}
V_8 = F_56 ( V_6 , V_13 , F_5 , 0x0 , L_13 , V_2 ) ;
if ( V_8 ) {
F_12 ( V_6 , L_14 ) ;
return - V_91 ;
}
V_2 -> V_6 = V_6 ;
F_57 ( & V_2 -> V_84 ) ;
F_58 ( V_81 , V_2 ) ;
F_59 ( V_6 , L_15 ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_61 ( V_6 ) ;
F_17 ( V_2 -> V_74 ) ;
return 0 ;
}
static int F_62 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_61 ( V_6 ) ;
int V_8 ;
V_8 = F_26 ( V_2 -> V_74 ) ;
if ( V_8 ) {
F_12 ( V_6 , L_16 ) ;
return V_8 ;
}
F_19 ( V_2 ) ;
return 0 ;
}
