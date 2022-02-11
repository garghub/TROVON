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
return - V_44 ;
}
if ( V_42 ) {
int V_45 , V_46 ;
V_4 -> V_47 = F_7 ( sizeof( int ) * V_42 , V_48 ) ;
if ( V_4 -> V_47 == NULL ) {
F_4 ( V_43 L_6 ) ;
return - V_49 ;
}
V_4 -> V_42 = 0 ;
V_4 -> V_50 = V_4 -> V_51 = 0 ;
for ( V_45 = 0 , V_46 = V_41 + 1 ; V_45 < V_42 ; V_45 ++ , V_46 += 3 ) {
unsigned int V_52 = F_8 ( & V_13 [ V_46 ] ) ;
if ( ! V_52 )
continue;
if ( V_52 == 48000 && V_42 == 1 &&
( V_2 -> V_26 == F_3 ( 0x0d8c , 0x0201 ) ||
V_2 -> V_26 == F_3 ( 0x0d8c , 0x0102 ) ||
V_2 -> V_26 == F_3 ( 0x0ccd , 0x00b1 ) ) &&
V_4 -> V_24 == 5 && V_4 -> V_53 == 392 )
V_52 = 96000 ;
if ( V_52 == 16000 && V_2 -> V_26 == F_3 ( 0x041e , 0x4068 ) )
V_52 = 8000 ;
V_4 -> V_47 [ V_4 -> V_42 ] = V_52 ;
if ( ! V_4 -> V_50 || V_52 < V_4 -> V_50 )
V_4 -> V_50 = V_52 ;
if ( ! V_4 -> V_51 || V_52 > V_4 -> V_51 )
V_4 -> V_51 = V_52 ;
V_4 -> V_54 |= F_9 ( V_52 ) ;
V_4 -> V_42 ++ ;
}
if ( ! V_4 -> V_42 ) {
F_10 ( L_7 ) ;
return - V_44 ;
}
} else {
V_4 -> V_54 = V_55 ;
V_4 -> V_50 = F_8 ( & V_13 [ V_41 + 1 ] ) ;
V_4 -> V_51 = F_8 ( & V_13 [ V_41 + 4 ] ) ;
}
return 0 ;
}
static int F_11 ( struct V_3 * V_4 , int V_56 ,
const unsigned char * V_57 )
{
int V_58 , V_42 = 0 ;
V_4 -> V_54 = V_4 -> V_50 = V_4 -> V_51 = 0 ;
for ( V_58 = 0 ; V_58 < V_56 ; V_58 ++ ) {
int V_59 = F_12 ( & V_57 [ 2 + 12 * V_58 ] ) ;
int V_60 = F_12 ( & V_57 [ 6 + 12 * V_58 ] ) ;
int V_61 = F_12 ( & V_57 [ 10 + 12 * V_58 ] ) ;
unsigned int V_52 ;
if ( ( V_60 < 0 ) || ( V_59 < 0 ) || ( V_61 < 0 ) || ( V_60 < V_59 ) )
continue;
if ( V_61 == 1 ) {
V_4 -> V_50 = V_59 ;
V_4 -> V_51 = V_60 ;
V_4 -> V_54 = V_55 ;
return 0 ;
}
for ( V_52 = V_59 ; V_52 <= V_60 ; V_52 += V_61 ) {
if ( V_4 -> V_47 )
V_4 -> V_47 [ V_42 ] = V_52 ;
if ( ! V_4 -> V_50 || V_52 < V_4 -> V_50 )
V_4 -> V_50 = V_52 ;
if ( ! V_4 -> V_51 || V_52 > V_4 -> V_51 )
V_4 -> V_51 = V_52 ;
V_4 -> V_54 |= F_9 ( V_52 ) ;
V_42 ++ ;
if ( V_42 >= V_62 ) {
F_4 ( V_43 L_8 ) ;
break;
}
if ( V_61 == 0 )
break;
}
}
return V_42 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_63 * V_21 = V_2 -> V_21 ;
unsigned char V_64 [ 2 ] , * V_57 ;
int V_56 , V_65 , V_66 = 0 ;
int clock = F_14 ( V_2 , V_4 -> clock ) ;
if ( clock < 0 ) {
F_4 ( V_43 L_9 ,
V_67 , clock ) ;
goto V_68;
}
V_66 = F_15 ( V_21 , F_16 ( V_21 , 0 ) , V_69 ,
V_70 | V_71 | V_72 ,
V_73 << 8 ,
F_17 ( V_2 ) | ( clock << 8 ) ,
V_64 , sizeof( V_64 ) ) ;
if ( V_66 < 0 ) {
F_4 ( V_43 L_10 ,
V_67 , clock ) ;
goto V_68;
}
V_56 = ( V_64 [ 1 ] << 8 ) | V_64 [ 0 ] ;
V_65 = 2 + 12 * V_56 ;
V_57 = F_18 ( V_65 , V_48 ) ;
if ( ! V_57 ) {
V_66 = - V_49 ;
goto V_68;
}
V_66 = F_15 ( V_21 , F_16 ( V_21 , 0 ) , V_69 ,
V_70 | V_71 | V_72 ,
V_73 << 8 ,
F_17 ( V_2 ) | ( clock << 8 ) ,
V_57 , V_65 ) ;
if ( V_66 < 0 ) {
F_4 ( V_43 L_11 ,
V_67 , clock ) ;
V_66 = - V_44 ;
goto V_74;
}
F_19 ( V_4 -> V_47 ) ;
V_4 -> V_47 = NULL ;
V_4 -> V_42 = F_11 ( V_4 , V_56 , V_57 ) ;
if ( V_4 -> V_42 == 0 ) {
V_66 = 0 ;
goto V_74;
}
V_4 -> V_47 = F_7 ( sizeof( int ) * V_4 -> V_42 , V_48 ) ;
if ( ! V_4 -> V_47 ) {
V_66 = - V_49 ;
goto V_74;
}
F_11 ( V_4 , V_56 , V_57 ) ;
V_74:
F_19 ( V_57 ) ;
V_68:
return V_66 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 ,
struct V_75 * V_13 ,
struct V_76 * V_23 )
{
struct V_77 * V_78 = F_21 ( V_23 ) ;
int V_7 = V_78 -> V_79 ;
int V_80 , V_66 ;
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
return - V_44 ;
}
switch ( V_7 ) {
default:
F_2 ( V_87 L_12 ,
V_2 -> V_21 -> V_22 , V_4 -> V_23 , V_4 -> V_24 , V_7 ) ;
case V_11 :
V_4 -> V_88 = V_13 -> V_89 ;
V_66 = F_6 ( V_2 , V_4 , ( unsigned char * ) V_13 , 7 ) ;
break;
case V_16 :
V_66 = F_13 ( V_2 , V_4 ) ;
break;
}
if ( V_4 -> V_88 < 1 ) {
F_4 ( V_43 L_13 ,
V_2 -> V_21 -> V_22 , V_4 -> V_23 , V_4 -> V_24 , V_4 -> V_88 ) ;
return - V_44 ;
}
return V_66 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 , void * V_6 ,
struct V_76 * V_23 )
{
int V_90 , V_91 , V_66 ;
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
V_66 = F_6 ( V_2 , V_4 , V_6 , 8 ) ;
break;
}
case V_16 : {
struct V_99 * V_13 = V_6 ;
V_90 = F_24 ( V_13 -> V_96 ) ;
V_91 = F_24 ( V_13 -> V_97 ) ;
F_23 ( V_20 L_15 , V_90 , V_91 ) ;
V_4 -> V_98 = V_91 ;
V_66 = F_13 ( V_2 , V_4 ) ;
break;
}
}
return V_66 ;
}
int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , struct V_75 * V_13 ,
int V_100 , struct V_76 * V_23 )
{
int V_68 ;
switch ( V_13 -> V_81 ) {
case V_101 :
case V_82 :
V_68 = F_20 ( V_2 , V_4 , V_5 , V_13 , V_23 ) ;
break;
case V_102 :
V_68 = F_22 ( V_2 , V_4 , V_5 , V_13 , V_23 ) ;
break;
default:
F_23 ( V_20 L_16 ,
V_2 -> V_21 -> V_22 , V_4 -> V_23 , V_4 -> V_24 ,
V_13 -> V_81 ) ;
return - V_103 ;
}
V_4 -> V_104 = V_13 -> V_81 ;
if ( V_68 < 0 )
return V_68 ;
#if 1
if ( V_2 -> V_26 == F_3 ( 0x041e , 0x3000 ) ||
V_2 -> V_26 == F_3 ( 0x041e , 0x3020 ) ||
V_2 -> V_26 == F_3 ( 0x041e , 0x3061 ) ) {
if ( V_13 -> V_81 == V_101 &&
V_4 -> V_54 != V_105 &&
V_4 -> V_54 != V_106 )
return - V_103 ;
}
#endif
return 0 ;
}
