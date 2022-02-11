char * F_1 ( T_1 V_1 )
{
return L_1 ;
}
char * F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case 0x0001 :
return L_2 ;
case 0x0002 :
return L_3 ;
case 0x0003 :
return L_4 ;
case 0x1001 :
return L_5 ;
case 0x1002 :
return L_6 ;
case 0x1003 :
return L_7 ;
case 0x1004 :
return L_8 ;
case 0x1005 :
return L_9 ;
case 0x1006 :
return L_10 ;
case 0x1007 :
return L_11 ;
case 0x1008 :
return L_12 ;
case 0x1009 :
return L_13 ;
case 0x100A :
return L_14 ;
case 0x100B :
return L_15 ;
case 0x1101 :
return L_16 ;
case 0x1102 :
return L_17 ;
case 0x1103 :
return L_18 ;
case 0x1104 :
return L_19 ;
case 0x1105 :
return L_20 ;
case 0x1106 :
return L_21 ;
case 0x1107 :
return L_22 ;
case 0x1108 :
return L_23 ;
case 0x1109 :
return L_13 ;
case 0x110A :
return L_14 ;
case 0x110B :
return L_15 ;
case 0x2001 :
return L_24 ;
case 0x2002 :
return L_25 ;
case 0x2003 :
return L_26 ;
case 0x2004 :
return L_27 ;
case 0x2005 :
return L_28 ;
case 0x2006 :
return L_29 ;
case 0x2007 :
return L_30 ;
case 0x3001 :
return L_31 ;
case 0x3002 :
return L_32 ;
case 0x3003 :
return L_33 ;
case 0x3004 :
return L_34 ;
case 0x3005 :
return L_35 ;
case 0x3006 :
return L_36 ;
case 0x3007 :
return L_37 ;
case 0x3008 :
return L_38 ;
case 0x3009 :
return L_39 ;
case 0x300A :
return L_40 ;
case 0x300B :
return L_41 ;
case 0x300C :
return L_42 ;
case 0x300D :
return L_43 ;
case 0x3301 :
return L_44 ;
case 0x3302 :
return L_45 ;
case 0x3303 :
return L_46 ;
case 0x3304 :
return L_47 ;
case 0x3311 :
return L_48 ;
case 0x3312 :
return L_49 ;
case 0x3313 :
return L_50 ;
case 0x3314 :
return L_51 ;
case 0x3315 :
return L_52 ;
case 0x3316 :
return L_53 ;
case 0x3317 :
return L_54 ;
case 0x3318 :
return L_55 ;
case 0x3319 :
return L_56 ;
case 0x3481 : return L_57 ;
case 0x3482 : return L_58 ;
case 0x3483 : return L_59 ;
case 0x3486 : return L_60 ;
case 0x3487 :
return L_61 ;
case 0x3490 : return L_62 ;
case 0x3491 : return L_63 ;
case 0x3492 : return L_64 ;
case 0x3493 : return L_65 ;
case 0x3495 : return L_66 ;
case 0x3496 : return L_67 ;
case 0x349A : return L_68 ;
case 0x349B : return L_69 ;
case 0x349C : return L_70 ;
case 0x349D : return L_71 ;
case 0x349E : return L_72 ;
case 0x349F : return L_73 ;
case 0x34A2 : return L_74 ;
case 0x34A6 : return L_75 ;
case 0x34A9 : return L_76 ;
case 0x34AA : return L_77 ;
case 0x34AB : return L_78 ;
case 0x34AC : return L_79 ;
case 0x34AF : return L_80 ;
case 0x34B1 : return L_81 ;
case 0x34B2 : return L_82 ;
case 0x34B9 : return L_83 ;
case 0x34BA : return L_84 ;
case 0x34BF : return L_85 ;
case 0x34C1 : return L_86 ;
case 0x34C2 : return L_87 ;
case 0x34C5 : return L_88 ;
case 0x34C6 : return L_89 ;
case 0x34CF : return L_90 ;
case 0x34D1 : return L_91 ;
case 0x34D2 : return L_92 ;
case 0x34D3 : return L_93 ;
case 0x34D4 : return L_94 ;
case 0x34D5 : return L_95 ;
case 0x34D6 : return L_96 ;
case 0x34D8 : return L_97 ;
case 0x34DB : return L_98 ;
case 0x34DF : return L_99 ;
case 0x34E0 : return L_100 ;
case 0x34E1 : return L_101 ;
case 0x34E2 : return L_102 ;
case 0x34E3 : return L_103 ;
case 0x34E4 : return L_104 ;
case 0x34E5 : return L_105 ;
case 0x34E6 : return L_106 ;
case 0x34EF : return L_107 ;
case 0x34FF : return L_108 ;
default: return L_109 ;
}
}
static unsigned F_2 ( unsigned V_2 , unsigned V_3 )
{
if ( V_2 & 0x80 )
V_2 = 0x9 + ( V_2 & 0x0f ) ;
else if ( V_2 <= 0x0f ) ;
else if ( V_2 == 0x41 )
V_2 = 0x9 + 0x1 ;
else if ( V_2 == 0xff )
V_2 = 0x00 ;
return ( V_3 & 3 ) * ( 0x9 + 0x9 ) + V_2 ;
}
static void F_3 ( T_2 * V_4 )
{
unsigned V_5 ;
for ( V_4 -> V_6 ++ , V_5 = 1 ; V_5 ; ) {
V_4 -> V_6 ++ ;
switch ( V_7 ) {
case V_8 :
V_5 ++ ;
break;
case V_9 :
V_5 -- ;
break;
}
}
}
static void F_4 ( T_2 * V_4 )
{
for (; V_7 != V_9 ; V_4 -> V_6 ++ ) {
switch ( V_7 ) {
case V_10 :
F_5 ( V_4 -> V_11 + V_4 -> V_12 , V_13 ) ;
V_4 -> V_12 ++ ;
break;
case V_14 :
F_6 ( V_4 -> V_11 + V_4 -> V_12 , V_13 ) ;
V_4 -> V_12 += 2 ;
break;
case V_15 :
F_7 ( V_4 -> V_11 + V_4 -> V_12 , V_13 ) ;
V_4 -> V_12 += 4 ;
break;
case V_16 :
if ( * ( V_17 * * ) V_13 == NULL ) {
* ( V_4 -> V_11 + V_4 -> V_12 ) = '\0' ;
V_4 -> V_12 ++ ;
} else if ( * * ( V_18 * ) V_13 != 0xff ) {
F_8 ( V_4 -> V_11 + V_4 -> V_12 , * ( V_18 * ) V_13 , 1 + * * ( V_18 * ) V_13 ) ;
V_4 -> V_12 += 1 + * * ( V_18 * ) V_13 ;
} else {
V_18 V_19 = * ( V_18 * ) V_13 ;
F_8 ( V_4 -> V_11 + V_4 -> V_12 , V_19 , 3 + * ( T_1 * ) ( V_19 + 1 ) ) ;
V_4 -> V_12 += 3 + * ( T_1 * ) ( V_19 + 1 ) ;
}
break;
case V_8 :
if ( * ( V_20 * ) V_13 == V_21 ) {
* ( V_4 -> V_11 + V_4 -> V_12 ) = '\0' ;
V_4 -> V_12 ++ ;
F_3 ( V_4 ) ;
}
else {
unsigned V_22 = V_4 -> V_12 ;
unsigned V_23 ;
V_4 -> V_12 ++ ;
V_4 -> V_6 ++ ;
F_4 ( V_4 ) ;
V_23 = V_4 -> V_12 - V_22 - 1 ;
if ( V_23 < 255 )
( V_4 -> V_11 + V_22 ) [ 0 ] = ( V_17 ) V_23 ;
else {
F_9 ( V_4 -> V_11 + V_22 + 3 , V_4 -> V_11 + V_22 + 1 , V_23 ) ;
( V_4 -> V_11 + V_22 ) [ 0 ] = 0xff ;
F_6 ( V_4 -> V_11 + V_22 + 1 , & V_23 ) ;
}
}
break;
}
}
}
unsigned F_10 ( T_2 * V_4 , V_17 * V_24 )
{
V_4 -> V_11 = V_24 ;
V_4 -> V_12 = 8 ;
V_4 -> V_6 = 0 ;
V_4 -> V_25 = V_26 [ F_2 ( V_4 -> V_27 , V_4 -> V_28 ) ] ;
F_4 ( V_4 ) ;
F_6 ( V_24 + 0 , & V_4 -> V_12 ) ;
F_5 ( V_4 -> V_11 + 4 , & V_4 -> V_27 ) ;
F_5 ( V_4 -> V_11 + 5 , & V_4 -> V_28 ) ;
F_6 ( V_4 -> V_11 + 2 , & V_4 -> V_29 ) ;
F_6 ( V_4 -> V_11 + 6 , & V_4 -> V_30 ) ;
return 0 ;
}
static void F_11 ( T_2 * V_4 )
{
for (; V_7 != V_9 ; V_4 -> V_6 ++ ) {
switch ( V_7 ) {
case V_10 :
F_12 ( V_4 -> V_11 + V_4 -> V_12 , V_13 ) ;
V_4 -> V_12 ++ ;
break;
case V_14 :
F_13 ( V_4 -> V_11 + V_4 -> V_12 , V_13 ) ;
V_4 -> V_12 += 2 ;
break;
case V_15 :
F_14 ( V_4 -> V_11 + V_4 -> V_12 , V_13 ) ;
V_4 -> V_12 += 4 ;
break;
case V_16 :
* ( V_17 * * ) V_13 = V_4 -> V_11 + V_4 -> V_12 ;
if ( V_4 -> V_11 [ V_4 -> V_12 ] != 0xff )
V_4 -> V_12 += 1 + V_4 -> V_11 [ V_4 -> V_12 ] ;
else
V_4 -> V_12 += 3 + * ( T_1 * ) ( V_4 -> V_11 + V_4 -> V_12 + 1 ) ;
break;
case V_8 :
if ( V_4 -> V_11 [ V_4 -> V_12 ] == '\0' ) {
* ( V_20 * ) V_13 = V_21 ;
V_4 -> V_12 ++ ;
F_3 ( V_4 ) ;
} else {
unsigned V_22 = V_4 -> V_12 ;
* ( V_20 * ) V_13 = V_31 ;
V_4 -> V_12 = ( V_4 -> V_11 + V_22 ) [ 0 ] == 255 ? V_4 -> V_12 + 3 : V_4 -> V_12 + 1 ;
V_4 -> V_6 ++ ;
F_11 ( V_4 ) ;
}
break;
}
}
}
unsigned F_15 ( T_2 * V_4 , V_17 * V_24 )
{
memset ( V_4 , 0 , sizeof( T_2 ) ) ;
V_4 -> V_11 = V_24 ;
V_4 -> V_12 = 8 ;
V_4 -> V_6 = 0 ;
F_12 ( V_4 -> V_11 + 4 , & V_4 -> V_27 ) ;
F_12 ( V_4 -> V_11 + 5 , & V_4 -> V_28 ) ;
V_4 -> V_25 = V_26 [ F_2 ( V_4 -> V_27 , V_4 -> V_28 ) ] ;
F_11 ( V_4 ) ;
F_13 ( V_24 + 0 , & V_4 -> V_12 ) ;
F_13 ( V_4 -> V_11 + 2 , & V_4 -> V_29 ) ;
F_13 ( V_4 -> V_11 + 6 , & V_4 -> V_30 ) ;
return 0 ;
}
unsigned F_16 ( T_2 * V_4 , T_1 V_32 ,
V_17 V_33 , V_17 V_34 ,
T_1 V_35 , T_3 V_36 )
{
memset ( V_4 , 0 , sizeof( T_2 ) ) ;
V_4 -> V_29 = V_32 ;
V_4 -> V_27 = V_33 ;
V_4 -> V_28 = V_34 ;
V_4 -> V_30 = V_35 ;
V_4 -> V_37 . V_38 = V_36 ;
return 0 ;
}
char * F_17 ( V_17 V_39 , V_17 V_40 )
{
return V_41 [ F_2 ( V_39 , V_40 ) ] ;
}
static T_4 * F_18 ( T_4 * V_42 , char * V_43 , ... )
{
T_5 V_44 ;
T_6 V_45 , V_46 ;
if ( ! V_42 )
return NULL ;
va_start ( V_44 , V_43 ) ;
V_46 = V_42 -> V_47 - V_42 -> V_48 ;
V_45 = vsnprintf ( V_42 -> V_6 , V_46 , V_43 , V_44 ) ;
va_end ( V_44 ) ;
if ( V_45 >= V_46 ) {
T_6 V_49 = 2 * V_42 -> V_47 ;
T_7 * V_50 ;
while ( ( V_49 - V_42 -> V_48 ) <= V_45 )
V_49 *= 2 ;
V_50 = F_19 ( V_49 , V_51 ) ;
if ( ! V_50 ) {
F_20 ( V_42 ) ;
return NULL ;
}
memcpy ( V_50 , V_42 -> V_52 , V_42 -> V_48 ) ;
F_21 ( V_42 -> V_52 ) ;
V_50 [ V_42 -> V_48 ] = 0 ;
V_42 -> V_52 = V_50 ;
V_42 -> V_6 = V_42 -> V_52 + V_42 -> V_48 ;
V_42 -> V_47 = V_49 ;
va_start ( V_44 , V_43 ) ;
V_46 = V_42 -> V_47 - V_42 -> V_48 ;
V_45 = vsnprintf ( V_42 -> V_6 , V_46 , V_43 , V_44 ) ;
va_end ( V_44 ) ;
}
V_42 -> V_6 += V_45 ;
V_42 -> V_48 += V_45 ;
return V_42 ;
}
static T_4 * F_22 ( T_4 * V_42 , V_17 * V_11 , unsigned V_53 )
{
unsigned V_54 = 0 ;
if ( ! V_42 )
return NULL ;
for (; V_53 ; V_53 -- , V_11 ++ )
if ( isalnum ( * V_11 ) || * V_11 == ' ' ) {
if ( V_54 )
V_42 = F_18 ( V_42 , L_110 ) ;
V_42 = F_18 ( V_42 , L_111 , * V_11 ) ;
V_54 = 0 ;
} else {
if ( ! V_54 )
V_42 = F_18 ( V_42 , L_112 , * V_11 ) ;
else
V_42 = F_18 ( V_42 , L_113 , * V_11 ) ;
V_54 = 1 ;
}
if ( V_54 )
V_42 = F_18 ( V_42 , L_110 ) ;
return V_42 ;
}
static T_4 * F_23 ( T_4 * V_42 , V_17 * V_11 )
{
unsigned V_53 ;
if ( V_11 [ 0 ] != 0xff ) {
V_53 = V_11 [ 0 ] ;
V_11 += 1 ;
} else {
V_53 = ( ( T_1 * ) ( V_11 + 1 ) ) [ 0 ] ;
V_11 += 3 ;
}
V_42 = F_22 ( V_42 , V_11 , V_53 ) ;
return V_42 ;
}
static T_4 * F_24 ( T_4 * V_42 , T_2 * V_4 , int V_55 )
{
for (; V_7 != V_9 ; V_4 -> V_6 ++ ) {
int V_56 = 29 + 3 - V_55 ;
int V_57 ;
if ( ! V_42 )
return NULL ;
V_42 = F_18 ( V_42 , L_114 ) ;
for ( V_57 = 0 ; V_57 < V_55 - 1 ; V_57 ++ )
V_42 = F_18 ( V_42 , L_115 ) ;
switch ( V_7 ) {
case V_10 :
V_42 = F_18 ( V_42 , L_116 , V_56 , V_58 , * ( V_17 * ) ( V_4 -> V_11 + V_4 -> V_12 ) ) ;
V_4 -> V_12 ++ ;
break;
case V_14 :
V_42 = F_18 ( V_42 , L_116 , V_56 , V_58 , * ( T_1 * ) ( V_4 -> V_11 + V_4 -> V_12 ) ) ;
V_4 -> V_12 += 2 ;
break;
case V_15 :
V_42 = F_18 ( V_42 , L_117 , V_56 , V_58 , * ( T_3 * ) ( V_4 -> V_11 + V_4 -> V_12 ) ) ;
V_4 -> V_12 += 4 ;
break;
case V_16 :
V_42 = F_18 ( V_42 , L_118 , V_56 , V_58 ) ;
if ( V_4 -> V_11 [ V_4 -> V_12 ] == '\0' )
V_42 = F_18 ( V_42 , L_119 ) ;
else
V_42 = F_23 ( V_42 , V_4 -> V_11 + V_4 -> V_12 ) ;
V_42 = F_18 ( V_42 , L_120 ) ;
if ( V_4 -> V_11 [ V_4 -> V_12 ] != 0xff )
V_4 -> V_12 += 1 + V_4 -> V_11 [ V_4 -> V_12 ] ;
else
V_4 -> V_12 += 3 + * ( T_1 * ) ( V_4 -> V_11 + V_4 -> V_12 + 1 ) ;
break;
case V_8 :
if ( V_4 -> V_11 [ V_4 -> V_12 ] == '\0' ) {
V_42 = F_18 ( V_42 , L_121 , V_56 , V_58 ) ;
V_4 -> V_12 ++ ;
F_3 ( V_4 ) ;
} else {
char * V_59 = V_58 ;
unsigned V_22 = V_4 -> V_12 ;
V_42 = F_18 ( V_42 , L_122 , V_56 , V_59 ) ;
V_4 -> V_12 = ( V_4 -> V_11 + V_22 ) [ 0 ] == 255 ? V_4 -> V_12 + 3 : V_4 -> V_12 + 1 ;
V_4 -> V_6 ++ ;
V_42 = F_24 ( V_42 , V_4 , V_55 + 1 ) ;
}
break;
}
}
return V_42 ;
}
static T_4 * F_25 ( void )
{
T_4 * V_42 ;
if ( F_26 ( ! F_27 ( 1 , & V_60 ) ) ) {
V_42 = V_61 ;
goto V_62;
} else
V_42 = F_19 ( sizeof( T_4 ) , V_51 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_52 = F_19 ( V_63 , V_51 ) ;
if ( ! V_42 -> V_52 ) {
F_21 ( V_42 ) ;
return NULL ;
}
V_42 -> V_47 = V_63 ;
V_62:
V_42 -> V_52 [ 0 ] = 0 ;
V_42 -> V_6 = V_42 -> V_52 ;
V_42 -> V_48 = 0 ;
return V_42 ;
}
void F_20 ( T_4 * V_42 )
{
if ( F_26 ( V_42 == V_61 ) ) {
F_28 ( 1 , & V_60 ) ;
return;
}
if ( F_26 ( V_42 ) )
F_21 ( V_42 -> V_52 ) ;
F_21 ( V_42 ) ;
}
T_4 * F_29 ( V_17 * V_24 )
{
T_4 * V_42 ;
T_2 * V_4 ;
V_42 = F_25 () ;
if ( F_30 ( ! V_42 ) )
return NULL ;
if ( F_26 ( V_42 == V_61 ) )
V_4 = V_64 ;
else
V_4 = F_19 ( sizeof( T_2 ) , V_51 ) ;
if ( F_30 ( ! V_4 ) ) {
F_20 ( V_42 ) ;
return NULL ;
}
V_4 -> V_11 = V_24 ;
V_4 -> V_12 = 8 ;
V_4 -> V_6 = 0 ;
F_12 ( V_4 -> V_11 + 4 , & V_4 -> V_27 ) ;
F_12 ( V_4 -> V_11 + 5 , & V_4 -> V_28 ) ;
V_4 -> V_25 = V_26 [ F_2 ( V_4 -> V_27 , V_4 -> V_28 ) ] ;
V_42 = F_18 ( V_42 , L_123 ,
V_41 [ F_2 ( V_4 -> V_27 , V_4 -> V_28 ) ] ,
( ( unsigned short * ) V_24 ) [ 1 ] ,
( ( unsigned short * ) V_24 ) [ 3 ] ,
( ( unsigned short * ) V_24 ) [ 0 ] ) ;
V_42 = F_24 ( V_42 , V_4 , 1 ) ;
if ( F_30 ( V_4 != V_64 ) )
F_21 ( V_4 ) ;
return V_42 ;
}
T_4 * F_31 ( T_2 * V_4 )
{
T_4 * V_42 ;
if ( ! V_4 -> V_11 )
return NULL ;
V_42 = F_25 () ;
if ( ! V_42 )
return NULL ;
V_4 -> V_12 = 8 ;
V_4 -> V_6 = 0 ;
V_42 = F_18 ( V_42 , L_124 ,
V_41 [ F_2 ( V_4 -> V_27 , V_4 -> V_28 ) ] ,
( ( T_1 * ) V_4 -> V_11 ) [ 1 ] ,
( ( T_1 * ) V_4 -> V_11 ) [ 3 ] ,
( ( T_1 * ) V_4 -> V_11 ) [ 0 ] ) ;
V_42 = F_24 ( V_42 , V_4 , 1 ) ;
return V_42 ;
}
int T_8 F_32 ( void )
{
V_64 = F_19 ( sizeof( T_2 ) , V_65 ) ;
if ( ! V_64 )
return - V_66 ;
V_61 = F_19 ( sizeof( T_4 ) , V_65 ) ;
if ( ! V_61 ) {
F_21 ( V_64 ) ;
return - V_66 ;
}
V_61 -> V_52 = F_19 ( V_67 , V_65 ) ;
if ( ! V_61 -> V_52 ) {
F_21 ( V_64 ) ;
F_21 ( V_61 ) ;
return - V_66 ;
}
V_61 -> V_47 = V_67 ;
V_61 -> V_52 [ 0 ] = 0 ;
V_61 -> V_6 = V_61 -> V_52 ;
V_61 -> V_48 = 0 ;
return 0 ;
}
void T_9 F_33 ( void )
{
if ( V_61 )
F_21 ( V_61 -> V_52 ) ;
F_21 ( V_61 ) ;
F_21 ( V_64 ) ;
}
T_4 * F_29 ( V_17 * V_24 )
{
return & V_61 ;
}
T_4 * F_31 ( T_2 * V_4 )
{
return & V_61 ;
}
void F_20 ( T_4 * V_42 )
{
}
int T_8 F_32 ( void )
{
return 0 ;
}
void T_9 F_33 ( void )
{
}
