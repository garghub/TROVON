static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 , void * V_6 )
{
int V_7 , V_8 ;
T_1 V_9 = 0 ;
switch ( V_4 -> V_10 ) {
case V_11 :
default: {
struct V_12 * V_13 = V_6 ;
V_7 = V_13 -> V_14 ;
V_8 = V_13 -> V_15 ;
V_5 = 1 << V_5 ;
break;
}
case V_16 : {
struct V_17 * V_13 = V_6 ;
V_7 = V_13 -> V_14 ;
V_8 = V_13 -> V_18 ;
if ( V_5 & V_19 )
V_9 |= V_20 ;
V_5 <<= 1 ;
break;
}
}
if ( ( V_9 == 0 ) &&
( V_5 == 0 || V_5 == ( 1 << V_21 ) ) ) {
F_2 ( V_2 , L_1 ,
V_4 -> V_22 , V_4 -> V_23 ) ;
V_5 = 1 << V_24 ;
}
if ( V_5 & ( 1 << V_24 ) ) {
if ( V_2 -> V_25 == F_3 ( 0x0582 , 0x0016 ) &&
V_7 == 24 && V_8 == 2 )
V_8 = 3 ;
else if ( V_7 > V_8 * 8 ) {
F_2 ( V_2 , L_2 ,
V_4 -> V_22 , V_4 -> V_23 ,
V_7 , V_8 ) ;
}
switch ( V_8 ) {
case 1 :
V_9 |= V_26 ;
break;
case 2 :
if ( F_4 ( V_2 , V_4 ) )
V_9 |= V_27 ;
else
V_9 |= V_28 ;
break;
case 3 :
if ( F_4 ( V_2 , V_4 ) )
V_9 |= V_29 ;
else
V_9 |= V_30 ;
break;
case 4 :
V_9 |= V_31 ;
break;
default:
F_2 ( V_2 ,
L_3 ,
V_4 -> V_22 , V_4 -> V_23 ,
V_7 , V_8 ) ;
break;
}
}
if ( V_5 & ( 1 << V_32 ) ) {
if ( V_2 -> V_25 == F_3 ( 0x04fa , 0x4201 ) )
V_9 |= V_26 ;
else
V_9 |= V_33 ;
}
if ( V_5 & ( 1 << V_34 ) ) {
V_9 |= V_35 ;
}
if ( V_5 & ( 1 << V_36 ) ) {
V_9 |= V_37 ;
}
if ( V_5 & ( 1 << V_38 ) ) {
V_9 |= V_39 ;
}
if ( V_5 & ~ 0x3f ) {
F_2 ( V_2 ,
L_4 ,
V_4 -> V_22 , V_4 -> V_23 , V_5 ) ;
}
V_9 |= F_5 ( V_2 , V_4 , V_8 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned char * V_13 , int V_40 )
{
int V_41 = V_13 [ V_40 ] ;
if ( V_13 [ 0 ] < V_40 + 1 + 3 * ( V_41 ? V_41 : 2 ) ) {
F_7 ( V_2 ,
L_5 ,
V_4 -> V_22 , V_4 -> V_23 ) ;
return - V_42 ;
}
if ( V_41 ) {
int V_43 , V_44 ;
V_4 -> V_45 = F_8 ( sizeof( int ) * V_41 , V_46 ) ;
if ( V_4 -> V_45 == NULL ) {
F_7 ( V_2 , L_6 ) ;
return - V_47 ;
}
V_4 -> V_41 = 0 ;
V_4 -> V_48 = V_4 -> V_49 = 0 ;
for ( V_43 = 0 , V_44 = V_40 + 1 ; V_43 < V_41 ; V_43 ++ , V_44 += 3 ) {
unsigned int V_50 = F_9 ( & V_13 [ V_44 ] ) ;
if ( ! V_50 )
continue;
if ( V_50 == 48000 && V_41 == 1 &&
( V_2 -> V_25 == F_3 ( 0x0d8c , 0x0201 ) ||
V_2 -> V_25 == F_3 ( 0x0d8c , 0x0102 ) ||
V_2 -> V_25 == F_3 ( 0x0ccd , 0x00b1 ) ) &&
V_4 -> V_23 == 5 && V_4 -> V_51 == 392 )
V_50 = 96000 ;
if ( V_50 == 16000 &&
( V_2 -> V_25 == F_3 ( 0x041e , 0x4064 ) ||
V_2 -> V_25 == F_3 ( 0x041e , 0x4068 ) ) )
V_50 = 8000 ;
V_4 -> V_45 [ V_4 -> V_41 ] = V_50 ;
if ( ! V_4 -> V_48 || V_50 < V_4 -> V_48 )
V_4 -> V_48 = V_50 ;
if ( ! V_4 -> V_49 || V_50 > V_4 -> V_49 )
V_4 -> V_49 = V_50 ;
V_4 -> V_52 |= F_10 ( V_50 ) ;
V_4 -> V_41 ++ ;
}
if ( ! V_4 -> V_41 ) {
F_11 ( L_7 ) ;
return - V_42 ;
}
} else {
V_4 -> V_52 = V_53 ;
V_4 -> V_48 = F_9 ( & V_13 [ V_40 + 1 ] ) ;
V_4 -> V_49 = F_9 ( & V_13 [ V_40 + 4 ] ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_54 ,
const unsigned char * V_55 )
{
int V_56 , V_41 = 0 ;
V_4 -> V_52 = V_4 -> V_48 = V_4 -> V_49 = 0 ;
for ( V_56 = 0 ; V_56 < V_54 ; V_56 ++ ) {
int V_57 = F_13 ( & V_55 [ 2 + 12 * V_56 ] ) ;
int V_58 = F_13 ( & V_55 [ 6 + 12 * V_56 ] ) ;
int V_59 = F_13 ( & V_55 [ 10 + 12 * V_56 ] ) ;
unsigned int V_50 ;
if ( ( V_58 < 0 ) || ( V_57 < 0 ) || ( V_59 < 0 ) || ( V_58 < V_57 ) )
continue;
if ( V_59 == 1 ) {
V_4 -> V_48 = V_57 ;
V_4 -> V_49 = V_58 ;
V_4 -> V_52 = V_53 ;
return 0 ;
}
for ( V_50 = V_57 ; V_50 <= V_58 ; V_50 += V_59 ) {
if ( V_4 -> V_45 )
V_4 -> V_45 [ V_41 ] = V_50 ;
if ( ! V_4 -> V_48 || V_50 < V_4 -> V_48 )
V_4 -> V_48 = V_50 ;
if ( ! V_4 -> V_49 || V_50 > V_4 -> V_49 )
V_4 -> V_49 = V_50 ;
V_4 -> V_52 |= F_10 ( V_50 ) ;
V_41 ++ ;
if ( V_41 >= V_60 ) {
F_7 ( V_2 , L_8 ) ;
break;
}
if ( V_59 == 0 )
break;
}
}
return V_41 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
unsigned char V_63 [ 2 ] , * V_55 ;
int V_54 , V_64 , V_65 = 0 ;
int clock = F_15 ( V_2 , V_4 -> clock , false ) ;
if ( clock < 0 ) {
F_16 ( & V_62 -> V_62 ,
L_9 ,
V_66 , clock ) ;
goto V_67;
}
V_65 = F_17 ( V_62 , F_18 ( V_62 , 0 ) , V_68 ,
V_69 | V_70 | V_71 ,
V_72 << 8 ,
F_19 ( V_2 ) | ( clock << 8 ) ,
V_63 , sizeof( V_63 ) ) ;
if ( V_65 < 0 ) {
F_16 ( & V_62 -> V_62 ,
L_10 ,
V_66 , clock ) ;
goto V_67;
}
V_54 = ( V_63 [ 1 ] << 8 ) | V_63 [ 0 ] ;
V_64 = 2 + 12 * V_54 ;
V_55 = F_20 ( V_64 , V_46 ) ;
if ( ! V_55 ) {
V_65 = - V_47 ;
goto V_67;
}
V_65 = F_17 ( V_62 , F_18 ( V_62 , 0 ) , V_68 ,
V_69 | V_70 | V_71 ,
V_72 << 8 ,
F_19 ( V_2 ) | ( clock << 8 ) ,
V_55 , V_64 ) ;
if ( V_65 < 0 ) {
F_16 ( & V_62 -> V_62 ,
L_11 ,
V_66 , clock ) ;
V_65 = - V_42 ;
goto V_73;
}
F_21 ( V_4 -> V_45 ) ;
V_4 -> V_45 = NULL ;
V_4 -> V_41 = F_12 ( V_2 , V_4 , V_54 , V_55 ) ;
if ( V_4 -> V_41 == 0 ) {
V_65 = 0 ;
goto V_73;
}
V_4 -> V_45 = F_8 ( sizeof( int ) * V_4 -> V_41 , V_46 ) ;
if ( ! V_4 -> V_45 ) {
V_65 = - V_47 ;
goto V_73;
}
F_12 ( V_2 , V_4 , V_54 , V_55 ) ;
V_73:
F_21 ( V_55 ) ;
V_67:
return V_65 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_5 ,
struct V_74 * V_13 )
{
T_2 V_75 ;
int V_65 ;
if ( V_13 -> V_76 == V_77 ) {
switch ( V_2 -> V_25 ) {
case F_3 ( 0x0763 , 0x2003 ) :
if ( V_2 -> V_78 == 0x00 &&
V_4 -> V_23 == 6 )
V_75 = V_79 ;
else
V_75 = V_80 ;
break;
default:
V_75 = V_80 ;
}
V_4 -> V_81 = F_23 ( V_75 ) ;
} else {
V_4 -> V_81 = F_1 ( V_2 , V_4 , V_5 , V_13 ) ;
if ( ! V_4 -> V_81 )
return - V_42 ;
}
switch ( V_4 -> V_10 ) {
default:
case V_11 :
V_4 -> V_82 = V_13 -> V_83 ;
V_65 = F_6 ( V_2 , V_4 , ( unsigned char * ) V_13 , 7 ) ;
break;
case V_16 :
V_65 = F_14 ( V_2 , V_4 ) ;
break;
}
if ( V_4 -> V_82 < 1 ) {
F_7 ( V_2 ,
L_12 ,
V_4 -> V_22 , V_4 -> V_23 , V_4 -> V_82 ) ;
return - V_42 ;
}
return V_65 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 , void * V_6 )
{
int V_84 , V_85 , V_65 ;
switch ( V_5 ) {
case V_86 :
V_4 -> V_81 = V_33 ;
break;
case V_87 :
V_4 -> V_81 = V_88 ;
break;
default:
F_2 ( V_2 ,
L_13 ,
V_4 -> V_22 , V_4 -> V_23 , V_5 ) ;
V_4 -> V_81 = V_88 ;
break;
}
V_4 -> V_82 = 1 ;
switch ( V_4 -> V_10 ) {
default:
case V_11 : {
struct V_89 * V_13 = V_6 ;
V_84 = F_25 ( V_13 -> V_90 ) ;
V_85 = F_25 ( V_13 -> V_91 ) ;
F_2 ( V_2 , L_14 , V_84 , V_85 ) ;
V_4 -> V_92 = V_85 ;
V_65 = F_6 ( V_2 , V_4 , V_6 , 8 ) ;
break;
}
case V_16 : {
struct V_93 * V_13 = V_6 ;
V_84 = F_25 ( V_13 -> V_90 ) ;
V_85 = F_25 ( V_13 -> V_91 ) ;
F_2 ( V_2 , L_14 , V_84 , V_85 ) ;
V_4 -> V_92 = V_85 ;
V_65 = F_14 ( V_2 , V_4 ) ;
break;
}
}
return V_65 ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_5 ,
struct V_74 * V_13 ,
int V_94 )
{
int V_67 ;
switch ( V_13 -> V_76 ) {
case V_95 :
case V_77 :
V_67 = F_22 ( V_2 , V_4 , V_5 , V_13 ) ;
break;
case V_96 :
V_67 = F_24 ( V_2 , V_4 , V_5 , V_13 ) ;
break;
default:
F_2 ( V_2 ,
L_15 ,
V_4 -> V_22 , V_4 -> V_23 ,
V_13 -> V_76 ) ;
return - V_97 ;
}
V_4 -> V_98 = V_13 -> V_76 ;
if ( V_67 < 0 )
return V_67 ;
#if 1
if ( V_2 -> V_25 == F_3 ( 0x041e , 0x3000 ) ||
V_2 -> V_25 == F_3 ( 0x041e , 0x3020 ) ||
V_2 -> V_25 == F_3 ( 0x041e , 0x3061 ) ) {
if ( V_13 -> V_76 == V_95 &&
V_4 -> V_52 != V_99 &&
V_4 -> V_52 != V_100 )
return - V_97 ;
}
#endif
return 0 ;
}
