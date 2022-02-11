static unsigned char * F_1 ( unsigned char V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_3 [ V_2 ] . V_1 == V_1 )
return V_3 [ V_2 ] . V_4 ;
return L_1 ;
}
static unsigned char F_3 ( int V_5 )
{
unsigned char V_6 = 0 ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 100 )
V_5 = 100 ;
if ( V_5 >= 0 )
V_6 = 7 ;
if ( V_5 >= 13 )
V_6 = 6 ;
if ( V_5 >= 25 )
V_6 = 5 ;
if ( V_5 >= 38 )
V_6 = 4 ;
if ( V_5 >= 50 )
V_6 = 3 ;
if ( V_5 >= 63 )
V_6 = 2 ;
if ( V_5 >= 75 )
V_6 = 1 ;
if ( V_5 >= 88 )
V_6 = 0 ;
V_6 |= 0x80 ;
return V_6 ;
}
static void F_4 ( struct V_7 * V_8 )
{
int V_2 ;
V_8 -> V_9 [ 0xb1 ] = V_10 ;
switch ( V_8 -> V_11 [ 4 ] ) {
case 1 :
F_5 ( V_8 -> V_4 , L_2 , sizeof( V_8 -> V_4 ) ) ;
if ( V_12 )
V_8 -> V_9 [ 0xb1 ] = V_13 ;
break;
case 2 :
F_5 ( V_8 -> V_4 , L_3 , sizeof( V_8 -> V_4 ) ) ;
break;
default:
F_5 ( V_8 -> V_4 , L_4 , sizeof( V_8 -> V_4 ) ) ;
F_6 ( V_14
L_5
L_6 , V_8 -> V_15 ) ;
F_6 ( V_14 L_7 ) ;
for ( V_2 = 0 ; V_2 < V_16 ; V_2 ++ )
F_6 ( L_8 , V_8 -> V_11 [ V_2 ] ) ;
F_6 ( L_9 ) ;
break;
}
F_6 ( V_17 L_10 ,
V_8 -> V_15 , V_8 -> V_4 ) ;
switch ( V_8 -> V_11 [ 2 ] ) {
case 0x00 :
break;
case V_18 :
F_6 ( V_14 L_11 ,
V_8 -> V_15 ) ;
break;
case V_19 :
F_6 ( V_14
L_12
L_13 , V_8 -> V_15 ) ;
break;
default:
F_6 ( V_14
L_14 ,
V_8 -> V_11 [ 2 ] , V_8 -> V_15 ) ;
break;
}
if ( V_8 -> V_11 [ 2 ] == V_18 && V_8 -> V_11 [ 3 ] != 0 )
F_6 ( V_14
L_15 ,
V_8 -> V_11 [ 3 ] , V_8 -> V_9 [ V_8 -> V_11 [ 3 ] ] ) ;
}
static T_1 F_7 ( struct V_20 * V_20 ,
unsigned char V_21 , unsigned int V_22 )
{
struct V_7 * V_8 = F_8 ( V_20 ) ;
struct V_23 * V_23 = V_8 -> V_24 ;
unsigned int V_9 ;
int V_2 ;
F_9 ( V_17 L_16 , V_21 ) ;
if ( V_8 -> V_25 > 0 ) {
F_9 ( V_17 L_17 , V_8 -> V_4 ) ;
V_8 -> V_11 [ V_16 - V_8 -> V_25 -- ] = V_21 ;
if ( V_8 -> V_25 == 0 )
F_4 ( V_8 ) ;
return V_26 ;
}
switch ( V_21 ) {
case V_27 :
for ( V_2 = 0 ; V_2 < F_2 ( V_28 ) ; V_2 ++ )
F_10 ( V_23 , V_8 -> V_9 [ V_2 ] , 0 ) ;
F_11 ( V_23 ) ;
break;
case 0x01 :
F_9 ( V_17 L_18 ) ;
V_8 -> V_25 = V_16 ;
V_8 -> V_11 [ V_16 - V_8 -> V_25 -- ] = V_21 ;
F_12 ( & V_8 -> V_29 ) ;
break;
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
F_9 ( V_17 L_19 ,
F_1 ( V_21 ) ) ;
break;
default:
V_9 = V_8 -> V_9 [ V_21 ] ;
if ( V_9 != V_38 ) {
F_10 ( V_23 , V_9 ,
! F_13 ( V_9 , V_23 -> V_39 ) ) ;
F_11 ( V_23 ) ;
} else {
F_6 ( V_40
L_20 ,
__FILE__ , V_21 , V_8 -> V_4 ) ;
}
}
return V_26 ;
}
static void F_14 ( struct V_7 * V_8 )
{
struct V_20 * V_20 = V_8 -> V_20 ;
unsigned char V_41 = 0 ;
unsigned char V_42 = 0 ;
F_15 ( V_8 , V_41 , V_42 , V_43 , V_44 ) ;
F_15 ( V_8 , V_41 , V_42 , V_45 , V_46 ) ;
F_15 ( V_8 , V_41 , V_42 , V_47 , V_48 ) ;
F_15 ( V_8 , V_41 , V_42 , V_49 , V_50 ) ;
if ( V_41 != 0 ) {
F_16 ( V_20 , V_51 ) ;
F_16 ( V_20 , V_41 ) ;
}
if ( V_42 != 0 ) {
F_16 ( V_20 , V_52 ) ;
F_16 ( V_20 , V_42 ) ;
}
}
static void F_17 ( struct V_7 * V_8 , bool V_53 )
{
struct V_20 * V_20 = V_8 -> V_20 ;
if ( V_53 ) {
F_9 ( L_21 , V_54 ) ;
F_16 ( V_20 , V_55 ) ;
F_16 ( V_20 , F_3 ( V_8 -> V_56 ) ) ;
F_16 ( V_20 , V_57 ) ;
F_16 ( V_20 , F_3 ( V_8 -> V_58 ) ) ;
} else {
F_9 ( L_22 , V_54 ) ;
F_16 ( V_20 , V_59 ) ;
F_16 ( V_20 , V_60 ) ;
}
}
static int F_18 ( struct V_23 * V_24 ,
unsigned int type , unsigned int V_61 , int V_1 )
{
struct V_7 * V_8 = F_19 ( V_24 ) ;
switch ( type ) {
case V_62 :
F_14 ( V_8 ) ;
return 0 ;
case V_63 :
switch ( V_61 ) {
case V_64 :
F_17 ( V_8 , V_1 ) ;
return 0 ;
case V_65 :
if ( V_1 != 0 )
F_16 ( V_8 -> V_20 , V_66 ) ;
return 0 ;
}
break;
default:
F_6 ( V_14 L_23 ,
V_54 , type , V_61 , V_1 ) ;
}
return - 1 ;
}
static void F_20 ( struct V_67 * V_68 )
{
struct V_7 * V_8 = F_21 ( V_68 , struct V_7 , V_29 ) ;
int V_69 ;
F_16 ( V_8 -> V_20 , V_70 ) ;
F_16 ( V_8 -> V_20 , V_71 ) ;
F_14 ( V_8 ) ;
F_16 ( V_8 -> V_20 , V_72 ) ;
for ( V_69 = 1 ; V_69 <= 14 ; V_69 ++ )
F_16 ( V_8 -> V_20 ,
F_22 ( V_73 , V_69 ) ) ;
F_16 ( V_8 -> V_20 , V_74 ) ;
F_16 ( V_8 -> V_20 , F_3 ( V_8 -> V_75 ) ) ;
F_17 ( V_8 , F_13 ( V_64 , V_8 -> V_24 -> V_76 ) ) ;
if ( F_13 ( V_65 , V_8 -> V_24 -> V_76 ) )
F_16 ( V_8 -> V_20 , V_66 ) ;
}
static int F_23 ( struct V_20 * V_20 , struct V_77 * V_78 )
{
struct V_7 * V_8 ;
struct V_23 * V_23 ;
int V_2 ;
int V_79 ;
V_8 = F_24 ( sizeof( struct V_7 ) , V_80 ) ;
V_23 = F_25 () ;
if ( ! V_8 || ! V_23 ) {
V_79 = - V_81 ;
goto V_82;
}
V_8 -> V_20 = V_20 ;
V_8 -> V_24 = V_23 ;
F_26 ( & V_8 -> V_29 , F_20 ) ;
V_8 -> V_75 = V_75 ;
V_8 -> V_56 = V_56 ;
V_8 -> V_58 = V_58 ;
memcpy ( V_8 -> V_9 , V_28 , sizeof( V_8 -> V_9 ) ) ;
F_5 ( V_8 -> V_4 , L_24 , sizeof( V_8 -> V_4 ) ) ;
snprintf ( V_8 -> V_15 , sizeof( V_8 -> V_15 ) , L_25 , V_20 -> V_15 ) ;
V_23 -> V_4 = V_8 -> V_4 ;
V_23 -> V_15 = V_8 -> V_15 ;
V_23 -> V_11 . V_83 = V_84 ;
V_23 -> V_11 . V_85 = V_86 ;
V_23 -> V_11 . V_87 = 0 ;
V_23 -> V_11 . V_88 = 0x0100 ;
V_23 -> V_24 . V_89 = & V_20 -> V_24 ;
V_23 -> V_90 = F_18 ;
F_27 ( V_23 , V_8 ) ;
F_28 ( V_91 , V_23 -> V_92 ) ;
F_28 ( V_62 , V_23 -> V_92 ) ;
F_28 ( V_63 , V_23 -> V_92 ) ;
F_28 ( V_93 , V_23 -> V_92 ) ;
F_28 ( V_43 , V_23 -> V_94 ) ;
F_28 ( V_49 , V_23 -> V_94 ) ;
F_28 ( V_45 , V_23 -> V_94 ) ;
F_28 ( V_47 , V_23 -> V_94 ) ;
F_28 ( V_65 , V_23 -> V_95 ) ;
F_28 ( V_64 , V_23 -> V_95 ) ;
V_23 -> V_9 = V_8 -> V_9 ;
V_23 -> V_96 = sizeof( V_8 -> V_9 [ 0 ] ) ;
V_23 -> V_97 = F_2 ( V_8 -> V_9 ) ;
for ( V_2 = 0 ; V_2 < V_98 ; V_2 ++ )
F_28 ( V_8 -> V_9 [ V_2 ] , V_23 -> V_99 ) ;
F_29 ( V_38 , V_23 -> V_99 ) ;
F_30 ( V_20 , V_8 ) ;
V_79 = F_31 ( V_20 , V_78 ) ;
if ( V_79 )
goto V_100;
V_79 = F_32 ( V_8 -> V_24 ) ;
if ( V_79 )
goto V_101;
F_16 ( V_8 -> V_20 , V_102 ) ;
return 0 ;
V_101: F_33 ( V_20 ) ;
V_100: F_30 ( V_20 , NULL ) ;
V_82: F_34 ( V_23 ) ;
F_35 ( V_8 ) ;
return V_79 ;
}
static void F_36 ( struct V_20 * V_20 )
{
struct V_7 * V_8 = F_8 ( V_20 ) ;
F_37 ( V_8 -> V_24 ) ;
F_38 ( V_8 -> V_24 ) ;
F_33 ( V_20 ) ;
F_30 ( V_20 , NULL ) ;
F_39 ( V_8 -> V_24 ) ;
F_35 ( V_8 ) ;
}
