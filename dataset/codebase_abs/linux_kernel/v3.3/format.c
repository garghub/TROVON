static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 , void * V_6 ,
int V_7 )
{
int V_8 , V_9 ;
T_1 V_10 ;
switch ( V_7 ) {
case V_11 :
default: {
struct V_12 * V_13 = V_6 ;
V_8 = V_13 -> V_14 ;
V_9 = V_13 -> V_15 ;
V_5 = 1 << V_5 ;
break;
}
case V_16 : {
struct V_17 * V_13 = V_6 ;
V_8 = V_13 -> V_14 ;
V_9 = V_13 -> V_18 ;
V_5 <<= 1 ;
break;
}
}
V_10 = 0 ;
if ( V_5 == 0 || V_5 == ( 1 << V_19 ) ) {
F_2 ( V_20 L_1 ,
V_2 -> V_21 -> V_22 , V_4 -> V_23 , V_4 -> V_24 ) ;
V_5 = 1 << V_25 ;
}
if ( V_5 & ( 1 << V_25 ) ) {
if ( V_2 -> V_26 == F_3 ( 0x0582 , 0x0016 ) &&
V_8 == 24 && V_9 == 2 )
V_9 = 3 ;
else if ( V_8 > V_9 * 8 ) {
F_4 ( V_20 L_2 ,
V_2 -> V_21 -> V_22 , V_4 -> V_23 , V_4 -> V_24 ,
V_8 , V_9 ) ;
}
switch ( V_9 ) {
case 1 :
V_10 |= V_27 ;
break;
case 2 :
if ( F_5 ( V_2 , V_4 ) )
V_10 |= V_28 ;
else
V_10 |= V_29 ;
break;
case 3 :
if ( F_5 ( V_2 , V_4 ) )
V_10 |= V_30 ;
else
V_10 |= V_31 ;
break;
case 4 :
V_10 |= V_32 ;
break;
default:
F_4 ( V_20 L_3 ,
V_2 -> V_21 -> V_22 , V_4 -> V_23 , V_4 -> V_24 ,
V_8 , V_9 ) ;
break;
}
}
if ( V_5 & ( 1 << V_33 ) ) {
if ( V_2 -> V_26 == F_3 ( 0x04fa , 0x4201 ) )
V_10 |= V_27 ;
else
V_10 |= V_34 ;
}
if ( V_5 & ( 1 << V_35 ) ) {
V_10 |= V_36 ;
}
if ( V_5 & ( 1 << V_37 ) ) {
V_10 |= V_38 ;
}
if ( V_5 & ( 1 << V_39 ) ) {
V_10 |= V_40 ;
}
if ( V_5 & ~ 0x3f ) {
F_4 ( V_20 L_4 ,
V_2 -> V_21 -> V_22 , V_4 -> V_23 , V_4 -> V_24 , V_5 ) ;
}
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned char * V_13 , int V_41 )
{
int V_42 = V_13 [ V_41 ] ;
if ( V_13 [ 0 ] < V_41 + 1 + 3 * ( V_42 ? V_42 : 2 ) ) {
F_4 ( V_43 L_5 ,
V_2 -> V_21 -> V_22 , V_4 -> V_23 , V_4 -> V_24 ) ;
return - 1 ;
}
if ( V_42 ) {
int V_44 , V_45 ;
V_4 -> V_46 = F_7 ( sizeof( int ) * V_42 , V_47 ) ;
if ( V_4 -> V_46 == NULL ) {
F_4 ( V_43 L_6 ) ;
return - 1 ;
}
V_4 -> V_42 = 0 ;
V_4 -> V_48 = V_4 -> V_49 = 0 ;
for ( V_44 = 0 , V_45 = V_41 + 1 ; V_44 < V_42 ; V_44 ++ , V_45 += 3 ) {
unsigned int V_50 = F_8 ( & V_13 [ V_45 ] ) ;
if ( ! V_50 )
continue;
if ( V_50 == 48000 && V_42 == 1 &&
( V_2 -> V_26 == F_3 ( 0x0d8c , 0x0201 ) ||
V_2 -> V_26 == F_3 ( 0x0d8c , 0x0102 ) ||
V_2 -> V_26 == F_3 ( 0x0ccd , 0x00b1 ) ) &&
V_4 -> V_24 == 5 && V_4 -> V_51 == 392 )
V_50 = 96000 ;
if ( V_50 == 16000 && V_2 -> V_26 == F_3 ( 0x041e , 0x4068 ) )
V_50 = 8000 ;
V_4 -> V_46 [ V_4 -> V_42 ] = V_50 ;
if ( ! V_4 -> V_48 || V_50 < V_4 -> V_48 )
V_4 -> V_48 = V_50 ;
if ( ! V_4 -> V_49 || V_50 > V_4 -> V_49 )
V_4 -> V_49 = V_50 ;
V_4 -> V_52 |= F_9 ( V_50 ) ;
V_4 -> V_42 ++ ;
}
if ( ! V_4 -> V_42 ) {
F_10 ( L_7 ) ;
return - 1 ;
}
} else {
V_4 -> V_52 = V_53 ;
V_4 -> V_48 = F_8 ( & V_13 [ V_41 + 1 ] ) ;
V_4 -> V_49 = F_8 ( & V_13 [ V_41 + 4 ] ) ;
}
return 0 ;
}
static int F_11 ( struct V_3 * V_4 , int V_54 ,
const unsigned char * V_55 )
{
int V_56 , V_42 = 0 ;
V_4 -> V_52 = V_4 -> V_48 = V_4 -> V_49 = 0 ;
for ( V_56 = 0 ; V_56 < V_54 ; V_56 ++ ) {
int V_57 = F_12 ( & V_55 [ 2 + 12 * V_56 ] ) ;
int V_58 = F_12 ( & V_55 [ 6 + 12 * V_56 ] ) ;
int V_59 = F_12 ( & V_55 [ 10 + 12 * V_56 ] ) ;
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
if ( V_4 -> V_46 )
V_4 -> V_46 [ V_42 ] = V_50 ;
if ( ! V_4 -> V_48 || V_50 < V_4 -> V_48 )
V_4 -> V_48 = V_50 ;
if ( ! V_4 -> V_49 || V_50 > V_4 -> V_49 )
V_4 -> V_49 = V_50 ;
V_4 -> V_52 |= F_9 ( V_50 ) ;
V_42 ++ ;
if ( V_42 >= V_60 ) {
F_4 ( V_43 L_8 ) ;
break;
}
if ( V_59 == 0 )
break;
}
}
return V_42 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_61 * V_21 = V_2 -> V_21 ;
unsigned char V_62 [ 2 ] , * V_55 ;
int V_54 , V_63 , V_64 = 0 ;
int clock = F_14 ( V_2 , V_4 -> clock ) ;
if ( clock < 0 ) {
F_4 ( V_43 L_9 ,
V_65 , clock ) ;
goto V_66;
}
V_64 = F_15 ( V_21 , F_16 ( V_21 , 0 ) , V_67 ,
V_68 | V_69 | V_70 ,
V_71 << 8 ,
F_17 ( V_2 ) | ( clock << 8 ) ,
V_62 , sizeof( V_62 ) ) ;
if ( V_64 < 0 ) {
F_4 ( V_43 L_10 ,
V_65 , clock ) ;
goto V_66;
}
V_54 = ( V_62 [ 1 ] << 8 ) | V_62 [ 0 ] ;
V_63 = 2 + 12 * V_54 ;
V_55 = F_18 ( V_63 , V_47 ) ;
if ( ! V_55 ) {
V_64 = - V_72 ;
goto V_66;
}
V_64 = F_15 ( V_21 , F_16 ( V_21 , 0 ) , V_67 ,
V_68 | V_69 | V_70 ,
V_71 << 8 ,
F_17 ( V_2 ) | ( clock << 8 ) ,
V_55 , V_63 ) ;
if ( V_64 < 0 ) {
F_4 ( V_43 L_11 ,
V_65 , clock ) ;
V_64 = - V_73 ;
goto V_74;
}
F_19 ( V_4 -> V_46 ) ;
V_4 -> V_46 = NULL ;
V_4 -> V_42 = F_11 ( V_4 , V_54 , V_55 ) ;
if ( V_4 -> V_42 == 0 ) {
V_64 = 0 ;
goto V_74;
}
V_4 -> V_46 = F_7 ( sizeof( int ) * V_4 -> V_42 , V_47 ) ;
if ( ! V_4 -> V_46 ) {
V_64 = - V_72 ;
goto V_74;
}
F_11 ( V_4 , V_54 , V_55 ) ;
V_74:
F_19 ( V_55 ) ;
V_66:
return V_64 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 ,
struct V_75 * V_13 ,
struct V_76 * V_23 )
{
struct V_77 * V_78 = F_21 ( V_23 ) ;
int V_7 = V_78 -> V_79 ;
int V_80 , V_64 ;
if ( V_13 -> V_81 == V_82 ) {
switch ( V_2 -> V_26 ) {
case F_3 ( 0x0763 , 0x2003 ) :
if ( V_2 -> V_83 == 0x00 &&
V_4 -> V_24 == 6 )
V_80 = V_84 ;
else
V_80 = V_85 ;
break;
default:
V_80 = V_85 ;
}
V_4 -> V_86 = 1uLL << V_80 ;
} else {
V_4 -> V_86 = F_1 ( V_2 , V_4 , V_5 ,
V_13 , V_7 ) ;
if ( ! V_4 -> V_86 )
return - 1 ;
}
switch ( V_7 ) {
default:
F_2 ( V_87 L_12 ,
V_2 -> V_21 -> V_22 , V_4 -> V_23 , V_4 -> V_24 , V_7 ) ;
case V_11 :
V_4 -> V_88 = V_13 -> V_89 ;
V_64 = F_6 ( V_2 , V_4 , ( unsigned char * ) V_13 , 7 ) ;
break;
case V_16 :
V_64 = F_13 ( V_2 , V_4 ) ;
break;
}
if ( V_4 -> V_88 < 1 ) {
F_4 ( V_43 L_13 ,
V_2 -> V_21 -> V_22 , V_4 -> V_23 , V_4 -> V_24 , V_4 -> V_88 ) ;
return - 1 ;
}
return V_64 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 , void * V_6 ,
struct V_76 * V_23 )
{
int V_90 , V_91 , V_64 ;
struct V_77 * V_78 = F_21 ( V_23 ) ;
int V_7 = V_78 -> V_79 ;
switch ( V_5 ) {
case V_92 :
V_4 -> V_86 = V_34 ;
break;
case V_93 :
V_4 -> V_86 = V_94 ;
break;
default:
F_23 ( V_20 L_14 ,
V_2 -> V_21 -> V_22 , V_4 -> V_23 , V_4 -> V_24 , V_5 ) ;
V_4 -> V_86 = V_94 ;
break;
}
V_4 -> V_88 = 1 ;
switch ( V_7 ) {
default:
F_2 ( V_87 L_12 ,
V_2 -> V_21 -> V_22 , V_4 -> V_23 , V_4 -> V_24 , V_7 ) ;
case V_11 : {
struct V_95 * V_13 = V_6 ;
V_90 = F_24 ( V_13 -> V_96 ) ;
V_91 = F_24 ( V_13 -> V_97 ) ;
F_23 ( V_20 L_15 , V_90 , V_91 ) ;
V_4 -> V_98 = V_91 ;
V_64 = F_6 ( V_2 , V_4 , V_6 , 8 ) ;
break;
}
case V_16 : {
struct V_99 * V_13 = V_6 ;
V_90 = F_24 ( V_13 -> V_96 ) ;
V_91 = F_24 ( V_13 -> V_97 ) ;
F_23 ( V_20 L_15 , V_90 , V_91 ) ;
V_4 -> V_98 = V_91 ;
V_64 = F_13 ( V_2 , V_4 ) ;
break;
}
}
return V_64 ;
}
int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , struct V_75 * V_13 ,
int V_100 , struct V_76 * V_23 )
{
int V_66 ;
switch ( V_13 -> V_81 ) {
case V_101 :
case V_82 :
V_66 = F_20 ( V_2 , V_4 , V_5 , V_13 , V_23 ) ;
break;
case V_102 :
V_66 = F_22 ( V_2 , V_4 , V_5 , V_13 , V_23 ) ;
break;
default:
F_23 ( V_20 L_16 ,
V_2 -> V_21 -> V_22 , V_4 -> V_23 , V_4 -> V_24 ,
V_13 -> V_81 ) ;
return - V_103 ;
}
V_4 -> V_104 = V_13 -> V_81 ;
if ( V_66 < 0 )
return V_66 ;
#if 1
if ( V_2 -> V_26 == F_3 ( 0x041e , 0x3000 ) ||
V_2 -> V_26 == F_3 ( 0x041e , 0x3020 ) ||
V_2 -> V_26 == F_3 ( 0x041e , 0x3061 ) ) {
if ( V_13 -> V_81 == V_101 &&
V_4 -> V_52 != V_105 &&
V_4 -> V_52 != V_106 )
return - V_103 ;
}
#endif
return 0 ;
}
