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
F_2 ( V_22 L_1 ,
V_2 -> V_23 -> V_24 , V_4 -> V_25 , V_4 -> V_26 ) ;
V_5 = 1 << V_27 ;
}
if ( V_5 & ( 1 << V_27 ) ) {
if ( V_2 -> V_28 == F_3 ( 0x0582 , 0x0016 ) &&
V_7 == 24 && V_8 == 2 )
V_8 = 3 ;
else if ( V_7 > V_8 * 8 ) {
F_4 ( V_22 L_2 ,
V_2 -> V_23 -> V_24 , V_4 -> V_25 , V_4 -> V_26 ,
V_7 , V_8 ) ;
}
switch ( V_8 ) {
case 1 :
V_9 |= V_29 ;
break;
case 2 :
if ( F_5 ( V_2 , V_4 ) )
V_9 |= V_30 ;
else
V_9 |= V_31 ;
break;
case 3 :
if ( F_5 ( V_2 , V_4 ) )
V_9 |= V_32 ;
else
V_9 |= V_33 ;
break;
case 4 :
V_9 |= V_34 ;
break;
default:
F_4 ( V_22 L_3 ,
V_2 -> V_23 -> V_24 , V_4 -> V_25 , V_4 -> V_26 ,
V_7 , V_8 ) ;
break;
}
}
if ( V_5 & ( 1 << V_35 ) ) {
if ( V_2 -> V_28 == F_3 ( 0x04fa , 0x4201 ) )
V_9 |= V_29 ;
else
V_9 |= V_36 ;
}
if ( V_5 & ( 1 << V_37 ) ) {
V_9 |= V_38 ;
}
if ( V_5 & ( 1 << V_39 ) ) {
V_9 |= V_40 ;
}
if ( V_5 & ( 1 << V_41 ) ) {
V_9 |= V_42 ;
}
if ( V_5 & ~ 0x3f ) {
F_4 ( V_22 L_4 ,
V_2 -> V_23 -> V_24 , V_4 -> V_25 , V_4 -> V_26 , V_5 ) ;
}
V_9 |= F_6 ( V_2 , V_4 , V_8 ) ;
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned char * V_13 , int V_43 )
{
int V_44 = V_13 [ V_43 ] ;
if ( V_13 [ 0 ] < V_43 + 1 + 3 * ( V_44 ? V_44 : 2 ) ) {
F_4 ( V_45 L_5 ,
V_2 -> V_23 -> V_24 , V_4 -> V_25 , V_4 -> V_26 ) ;
return - V_46 ;
}
if ( V_44 ) {
int V_47 , V_48 ;
V_4 -> V_49 = F_8 ( sizeof( int ) * V_44 , V_50 ) ;
if ( V_4 -> V_49 == NULL ) {
F_4 ( V_45 L_6 ) ;
return - V_51 ;
}
V_4 -> V_44 = 0 ;
V_4 -> V_52 = V_4 -> V_53 = 0 ;
for ( V_47 = 0 , V_48 = V_43 + 1 ; V_47 < V_44 ; V_47 ++ , V_48 += 3 ) {
unsigned int V_54 = F_9 ( & V_13 [ V_48 ] ) ;
if ( ! V_54 )
continue;
if ( V_54 == 48000 && V_44 == 1 &&
( V_2 -> V_28 == F_3 ( 0x0d8c , 0x0201 ) ||
V_2 -> V_28 == F_3 ( 0x0d8c , 0x0102 ) ||
V_2 -> V_28 == F_3 ( 0x0ccd , 0x00b1 ) ) &&
V_4 -> V_26 == 5 && V_4 -> V_55 == 392 )
V_54 = 96000 ;
if ( V_54 == 16000 && V_2 -> V_28 == F_3 ( 0x041e , 0x4068 ) )
V_54 = 8000 ;
V_4 -> V_49 [ V_4 -> V_44 ] = V_54 ;
if ( ! V_4 -> V_52 || V_54 < V_4 -> V_52 )
V_4 -> V_52 = V_54 ;
if ( ! V_4 -> V_53 || V_54 > V_4 -> V_53 )
V_4 -> V_53 = V_54 ;
V_4 -> V_56 |= F_10 ( V_54 ) ;
V_4 -> V_44 ++ ;
}
if ( ! V_4 -> V_44 ) {
F_11 ( L_7 ) ;
return - V_46 ;
}
} else {
V_4 -> V_56 = V_57 ;
V_4 -> V_52 = F_9 ( & V_13 [ V_43 + 1 ] ) ;
V_4 -> V_53 = F_9 ( & V_13 [ V_43 + 4 ] ) ;
}
return 0 ;
}
static int F_12 ( struct V_3 * V_4 , int V_58 ,
const unsigned char * V_59 )
{
int V_60 , V_44 = 0 ;
V_4 -> V_56 = V_4 -> V_52 = V_4 -> V_53 = 0 ;
for ( V_60 = 0 ; V_60 < V_58 ; V_60 ++ ) {
int V_61 = F_13 ( & V_59 [ 2 + 12 * V_60 ] ) ;
int V_62 = F_13 ( & V_59 [ 6 + 12 * V_60 ] ) ;
int V_63 = F_13 ( & V_59 [ 10 + 12 * V_60 ] ) ;
unsigned int V_54 ;
if ( ( V_62 < 0 ) || ( V_61 < 0 ) || ( V_63 < 0 ) || ( V_62 < V_61 ) )
continue;
if ( V_63 == 1 ) {
V_4 -> V_52 = V_61 ;
V_4 -> V_53 = V_62 ;
V_4 -> V_56 = V_57 ;
return 0 ;
}
for ( V_54 = V_61 ; V_54 <= V_62 ; V_54 += V_63 ) {
if ( V_4 -> V_49 )
V_4 -> V_49 [ V_44 ] = V_54 ;
if ( ! V_4 -> V_52 || V_54 < V_4 -> V_52 )
V_4 -> V_52 = V_54 ;
if ( ! V_4 -> V_53 || V_54 > V_4 -> V_53 )
V_4 -> V_53 = V_54 ;
V_4 -> V_56 |= F_10 ( V_54 ) ;
V_44 ++ ;
if ( V_44 >= V_64 ) {
F_4 ( V_45 L_8 ) ;
break;
}
if ( V_63 == 0 )
break;
}
}
return V_44 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_65 * V_23 = V_2 -> V_23 ;
unsigned char V_66 [ 2 ] , * V_59 ;
int V_58 , V_67 , V_68 = 0 ;
int clock = F_15 ( V_2 , V_4 -> clock , false ) ;
if ( clock < 0 ) {
F_4 ( V_45 L_9 ,
V_69 , clock ) ;
goto V_70;
}
V_68 = F_16 ( V_23 , F_17 ( V_23 , 0 ) , V_71 ,
V_72 | V_73 | V_74 ,
V_75 << 8 ,
F_18 ( V_2 ) | ( clock << 8 ) ,
V_66 , sizeof( V_66 ) ) ;
if ( V_68 < 0 ) {
F_4 ( V_45 L_10 ,
V_69 , clock ) ;
goto V_70;
}
V_58 = ( V_66 [ 1 ] << 8 ) | V_66 [ 0 ] ;
V_67 = 2 + 12 * V_58 ;
V_59 = F_19 ( V_67 , V_50 ) ;
if ( ! V_59 ) {
V_68 = - V_51 ;
goto V_70;
}
V_68 = F_16 ( V_23 , F_17 ( V_23 , 0 ) , V_71 ,
V_72 | V_73 | V_74 ,
V_75 << 8 ,
F_18 ( V_2 ) | ( clock << 8 ) ,
V_59 , V_67 ) ;
if ( V_68 < 0 ) {
F_4 ( V_45 L_11 ,
V_69 , clock ) ;
V_68 = - V_46 ;
goto V_76;
}
F_20 ( V_4 -> V_49 ) ;
V_4 -> V_49 = NULL ;
V_4 -> V_44 = F_12 ( V_4 , V_58 , V_59 ) ;
if ( V_4 -> V_44 == 0 ) {
V_68 = 0 ;
goto V_76;
}
V_4 -> V_49 = F_8 ( sizeof( int ) * V_4 -> V_44 , V_50 ) ;
if ( ! V_4 -> V_49 ) {
V_68 = - V_51 ;
goto V_76;
}
F_12 ( V_4 , V_58 , V_59 ) ;
V_76:
F_20 ( V_59 ) ;
V_70:
return V_68 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_5 ,
struct V_77 * V_13 )
{
T_2 V_78 ;
int V_68 ;
if ( V_13 -> V_79 == V_80 ) {
switch ( V_2 -> V_28 ) {
case F_3 ( 0x0763 , 0x2003 ) :
if ( V_2 -> V_81 == 0x00 &&
V_4 -> V_26 == 6 )
V_78 = V_82 ;
else
V_78 = V_83 ;
break;
default:
V_78 = V_83 ;
}
V_4 -> V_84 = F_22 ( V_78 ) ;
} else {
V_4 -> V_84 = F_1 ( V_2 , V_4 , V_5 , V_13 ) ;
if ( ! V_4 -> V_84 )
return - V_46 ;
}
switch ( V_4 -> V_10 ) {
default:
case V_11 :
V_4 -> V_85 = V_13 -> V_86 ;
V_68 = F_7 ( V_2 , V_4 , ( unsigned char * ) V_13 , 7 ) ;
break;
case V_16 :
V_68 = F_14 ( V_2 , V_4 ) ;
break;
}
if ( V_4 -> V_85 < 1 ) {
F_4 ( V_45 L_12 ,
V_2 -> V_23 -> V_24 , V_4 -> V_25 , V_4 -> V_26 , V_4 -> V_85 ) ;
return - V_46 ;
}
return V_68 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 , void * V_6 )
{
int V_87 , V_88 , V_68 ;
switch ( V_5 ) {
case V_89 :
V_4 -> V_84 = V_36 ;
break;
case V_90 :
V_4 -> V_84 = V_91 ;
break;
default:
F_24 ( V_22 L_13 ,
V_2 -> V_23 -> V_24 , V_4 -> V_25 , V_4 -> V_26 , V_5 ) ;
V_4 -> V_84 = V_91 ;
break;
}
V_4 -> V_85 = 1 ;
switch ( V_4 -> V_10 ) {
default:
case V_11 : {
struct V_92 * V_13 = V_6 ;
V_87 = F_25 ( V_13 -> V_93 ) ;
V_88 = F_25 ( V_13 -> V_94 ) ;
F_24 ( V_22 L_14 , V_87 , V_88 ) ;
V_4 -> V_95 = V_88 ;
V_68 = F_7 ( V_2 , V_4 , V_6 , 8 ) ;
break;
}
case V_16 : {
struct V_96 * V_13 = V_6 ;
V_87 = F_25 ( V_13 -> V_93 ) ;
V_88 = F_25 ( V_13 -> V_94 ) ;
F_24 ( V_22 L_14 , V_87 , V_88 ) ;
V_4 -> V_95 = V_88 ;
V_68 = F_14 ( V_2 , V_4 ) ;
break;
}
}
return V_68 ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_5 ,
struct V_77 * V_13 ,
int V_97 )
{
int V_70 ;
switch ( V_13 -> V_79 ) {
case V_98 :
case V_80 :
V_70 = F_21 ( V_2 , V_4 , V_5 , V_13 ) ;
break;
case V_99 :
V_70 = F_23 ( V_2 , V_4 , V_5 , V_13 ) ;
break;
default:
F_24 ( V_22 L_15 ,
V_2 -> V_23 -> V_24 , V_4 -> V_25 , V_4 -> V_26 ,
V_13 -> V_79 ) ;
return - V_100 ;
}
V_4 -> V_101 = V_13 -> V_79 ;
if ( V_70 < 0 )
return V_70 ;
#if 1
if ( V_2 -> V_28 == F_3 ( 0x041e , 0x3000 ) ||
V_2 -> V_28 == F_3 ( 0x041e , 0x3020 ) ||
V_2 -> V_28 == F_3 ( 0x041e , 0x3061 ) ) {
if ( V_13 -> V_79 == V_98 &&
V_4 -> V_56 != V_102 &&
V_4 -> V_56 != V_103 )
return - V_100 ;
}
#endif
return 0 ;
}
