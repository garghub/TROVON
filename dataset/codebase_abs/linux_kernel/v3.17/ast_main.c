void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_2 V_6 )
{
T_3 V_7 ;
F_2 ( V_2 , V_3 , V_4 ) ;
V_7 = ( F_3 ( V_2 , V_3 + 1 ) & V_5 ) | V_6 ;
F_4 ( V_2 , V_3 , V_4 , V_7 ) ;
}
T_2 F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
T_2 V_8 ;
F_2 ( V_2 , V_3 , V_4 ) ;
V_8 = F_3 ( V_2 , V_3 + 1 ) ;
return V_8 ;
}
T_2 F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , T_2 V_5 )
{
T_2 V_8 ;
F_2 ( V_2 , V_3 , V_4 ) ;
V_8 = F_3 ( V_2 , V_3 + 1 ) & V_5 ;
return V_8 ;
}
static int F_7 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
T_1 V_12 , V_13 ;
F_8 ( V_2 ) ;
if ( V_10 -> V_14 -> V_15 == V_16 ) {
V_2 -> V_17 = V_18 ;
F_9 ( L_1 ) ;
} else {
if ( V_10 -> V_14 -> V_19 >= 0x30 ) {
V_2 -> V_17 = V_20 ;
F_9 ( L_2 ) ;
} else if ( V_10 -> V_14 -> V_19 >= 0x20 ) {
V_2 -> V_17 = V_21 ;
F_9 ( L_3 ) ;
} else if ( V_10 -> V_14 -> V_19 >= 0x10 ) {
T_1 V_12 ;
F_10 ( V_2 , 0xf004 , 0x1e6e0000 ) ;
F_10 ( V_2 , 0xf000 , 0x1 ) ;
V_12 = F_11 ( V_2 , 0x1207c ) ;
switch ( V_12 & 0x0300 ) {
case 0x0200 :
V_2 -> V_17 = V_18 ;
F_9 ( L_4 ) ;
break;
case 0x0100 :
V_2 -> V_17 = V_22 ;
F_9 ( L_5 ) ;
break;
case 0x0000 :
V_2 -> V_17 = V_23 ;
F_9 ( L_6 ) ;
break;
default:
V_2 -> V_17 = V_24 ;
F_9 ( L_7 ) ;
break;
}
V_2 -> V_25 = false ;
} else {
V_2 -> V_17 = V_26 ;
F_9 ( L_8 ) ;
}
}
switch ( V_2 -> V_17 ) {
case V_27 :
V_2 -> V_28 = true ;
break;
case V_26 :
V_2 -> V_28 = false ;
break;
default:
V_13 = F_6 ( V_2 , V_29 , 0xd0 , 0xff ) ;
if ( ! ( V_13 & 0x80 ) )
V_2 -> V_28 = true ;
else if ( V_13 & 0x01 )
V_2 -> V_28 = true ;
else {
V_2 -> V_28 = false ;
F_10 ( V_2 , 0xf004 , 0x1e6e0000 ) ;
F_10 ( V_2 , 0xf000 , 0x1 ) ;
V_12 = F_11 ( V_2 , 0x1207c ) ;
V_12 &= 0x300 ;
if ( V_2 -> V_17 == V_21 && V_12 == 0x0 )
V_2 -> V_28 = true ;
if ( V_2 -> V_17 == V_20 && V_12 == 0x100 )
V_2 -> V_28 = true ;
}
break;
}
V_2 -> V_30 = V_31 ;
V_13 = F_6 ( V_2 , V_29 , 0xa3 , 0xff ) ;
if ( V_13 & 0x80 )
V_2 -> V_30 = V_32 ;
if ( ( V_2 -> V_17 == V_21 ) || ( V_2 -> V_17 == V_20 ) ) {
V_13 = F_6 ( V_2 , V_29 , 0xd1 , 0xff ) ;
switch ( V_13 ) {
case 0x04 :
V_2 -> V_30 = V_32 ;
break;
case 0x08 :
V_2 -> V_33 = F_12 ( 32 * 1024 , V_34 ) ;
if ( V_2 -> V_33 ) {
if ( F_13 ( V_10 , V_2 -> V_33 , 32 * 1024 ) ) {
F_14 ( V_2 -> V_33 ) ;
V_2 -> V_33 = NULL ;
}
}
case 0x0c :
V_2 -> V_30 = V_35 ;
}
}
return 0 ;
}
static int F_15 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
T_1 V_12 , V_36 ;
T_1 V_37 , V_38 , div , V_39 ;
F_10 ( V_2 , 0xf004 , 0x1e6e0000 ) ;
F_10 ( V_2 , 0xf000 , 0x1 ) ;
F_10 ( V_2 , 0x10000 , 0xfc600309 ) ;
do {
;
} while ( F_11 ( V_2 , 0x10000 ) != 0x01 );
V_12 = F_11 ( V_2 , 0x10004 ) ;
if ( V_12 & 0x400 )
V_2 -> V_40 = 16 ;
else
V_2 -> V_40 = 32 ;
if ( V_2 -> V_17 == V_21 || V_2 -> V_17 == V_20 ) {
switch ( V_12 & 0x03 ) {
case 0 :
V_2 -> V_41 = V_42 ;
break;
default:
case 1 :
V_2 -> V_41 = V_43 ;
break;
case 2 :
V_2 -> V_41 = V_44 ;
break;
case 3 :
V_2 -> V_41 = V_45 ;
break;
}
} else {
switch ( V_12 & 0x0c ) {
case 0 :
case 4 :
V_2 -> V_41 = V_42 ;
break;
case 8 :
if ( V_12 & 0x40 )
V_2 -> V_41 = V_43 ;
else
V_2 -> V_41 = V_46 ;
break;
case 0xc :
V_2 -> V_41 = V_47 ;
break;
}
}
V_12 = F_11 ( V_2 , 0x10120 ) ;
V_36 = F_11 ( V_2 , 0x10170 ) ;
if ( V_36 & 0x2000 )
V_39 = 14318 ;
else
V_39 = 12000 ;
V_37 = V_12 & 0x1f ;
V_38 = ( V_12 & 0x3fe0 ) >> 5 ;
V_12 = ( V_12 & 0xc000 ) >> 14 ;
switch ( V_12 ) {
case 3 :
div = 0x4 ;
break;
case 2 :
case 1 :
div = 0x2 ;
break;
default:
div = 0x1 ;
break;
}
V_2 -> V_48 = V_39 * ( V_38 + 2 ) / ( V_37 + 2 ) * ( div * 1000 ) ;
return 0 ;
}
static void F_16 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = F_17 ( V_50 ) ;
if ( V_52 -> V_53 )
F_18 ( V_52 -> V_53 ) ;
F_19 ( V_50 ) ;
F_14 ( V_50 ) ;
}
int F_20 ( struct V_9 * V_10 ,
struct V_51 * V_52 ,
struct V_54 * V_55 ,
struct V_56 * V_53 )
{
int V_8 ;
F_21 ( & V_52 -> V_3 , V_55 ) ;
V_52 -> V_53 = V_53 ;
V_8 = F_22 ( V_10 , & V_52 -> V_3 , & V_57 ) ;
if ( V_8 ) {
F_23 ( L_9 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static struct V_49 *
F_24 ( struct V_9 * V_10 ,
struct V_58 * V_59 ,
struct V_54 * V_55 )
{
struct V_56 * V_53 ;
struct V_51 * V_52 ;
int V_8 ;
V_53 = F_25 ( V_10 , V_59 , V_55 -> V_60 [ 0 ] ) ;
if ( V_53 == NULL )
return F_26 ( - V_61 ) ;
V_52 = F_12 ( sizeof( * V_52 ) , V_34 ) ;
if ( ! V_52 ) {
F_18 ( V_53 ) ;
return F_26 ( - V_62 ) ;
}
V_8 = F_20 ( V_10 , V_52 , V_55 , V_53 ) ;
if ( V_8 ) {
F_18 ( V_53 ) ;
F_14 ( V_52 ) ;
return F_26 ( V_8 ) ;
}
return & V_52 -> V_3 ;
}
static T_4 F_27 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
T_3 V_13 ;
T_4 V_63 ;
F_8 ( V_2 ) ;
V_63 = V_64 ;
V_13 = F_6 ( V_2 , V_29 , 0xaa , 0xff ) ;
switch ( V_13 & 3 ) {
case 0 : V_63 = V_65 ; break;
case 1 : V_63 = V_66 ; break;
case 2 : V_63 = V_67 ; break;
case 3 : V_63 = V_68 ; break;
}
V_13 = F_6 ( V_2 , V_29 , 0x99 , 0xff ) ;
switch ( V_13 & 0x03 ) {
case 1 :
V_63 -= 0x100000 ;
break;
case 2 :
V_63 -= 0x200000 ;
break;
case 3 :
V_63 -= 0x400000 ;
break;
}
return V_63 ;
}
int F_28 ( struct V_9 * V_10 , unsigned long V_69 )
{
struct V_1 * V_2 ;
int V_8 = 0 ;
V_2 = F_12 ( sizeof( struct V_1 ) , V_34 ) ;
if ( ! V_2 )
return - V_62 ;
V_10 -> V_11 = V_2 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_70 = F_29 ( V_10 -> V_14 , 1 , 0 ) ;
if ( ! V_2 -> V_70 ) {
V_8 = - V_71 ;
goto V_72;
}
V_2 -> V_73 = F_29 ( V_10 -> V_14 , 2 , 0 ) ;
if ( ! V_2 -> V_73 ) {
V_8 = - V_71 ;
goto V_72;
}
F_7 ( V_10 ) ;
if ( V_2 -> V_17 != V_27 ) {
F_15 ( V_10 ) ;
V_2 -> V_63 = F_27 ( V_10 ) ;
F_9 ( L_10 , V_2 -> V_48 , V_2 -> V_41 , V_2 -> V_40 , V_2 -> V_63 ) ;
}
V_8 = F_30 ( V_2 ) ;
if ( V_8 )
goto V_72;
F_31 ( V_10 ) ;
V_10 -> V_74 . V_75 = ( void * ) & V_76 ;
V_10 -> V_74 . V_77 = 0 ;
V_10 -> V_74 . V_78 = 0 ;
V_10 -> V_74 . V_79 = 24 ;
V_10 -> V_74 . V_80 = 1 ;
if ( V_2 -> V_17 == V_24 ||
V_2 -> V_17 == V_22 ||
V_2 -> V_17 == V_21 ||
V_2 -> V_17 == V_20 ||
V_2 -> V_17 == V_27 ) {
V_10 -> V_74 . V_81 = 1920 ;
V_10 -> V_74 . V_82 = 2048 ;
} else {
V_10 -> V_74 . V_81 = 1600 ;
V_10 -> V_74 . V_82 = 1200 ;
}
V_8 = F_32 ( V_10 ) ;
if ( V_8 )
goto V_72;
V_8 = F_33 ( V_10 ) ;
if ( V_8 )
goto V_72;
return 0 ;
V_72:
F_14 ( V_2 ) ;
V_10 -> V_11 = NULL ;
return V_8 ;
}
int F_34 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
F_14 ( V_2 -> V_33 ) ;
F_35 ( V_10 ) ;
F_36 ( V_10 ) ;
F_37 ( V_10 ) ;
F_38 ( V_2 ) ;
F_39 ( V_10 -> V_14 , V_2 -> V_73 ) ;
F_39 ( V_10 -> V_14 , V_2 -> V_70 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_40 ( struct V_9 * V_10 ,
T_4 V_83 , bool V_84 ,
struct V_56 * * V_53 )
{
struct V_85 * V_86 ;
int V_8 ;
* V_53 = NULL ;
V_83 = F_41 ( V_83 , V_87 ) ;
if ( V_83 == 0 )
return - V_88 ;
V_8 = F_42 ( V_10 , V_83 , 0 , 0 , & V_86 ) ;
if ( V_8 ) {
if ( V_8 != - V_89 )
F_23 ( L_11 ) ;
return V_8 ;
}
* V_53 = & V_86 -> V_90 ;
return 0 ;
}
int F_43 ( struct V_58 * V_91 ,
struct V_9 * V_10 ,
struct V_92 * args )
{
int V_8 ;
struct V_56 * V_93 ;
T_4 V_94 ;
args -> V_95 = args -> V_96 * ( ( args -> V_97 + 7 ) / 8 ) ;
args -> V_83 = args -> V_95 * args -> V_98 ;
V_8 = F_40 ( V_10 , args -> V_83 , false ,
& V_93 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_44 ( V_91 , V_93 , & V_94 ) ;
F_18 ( V_93 ) ;
if ( V_8 )
return V_8 ;
args -> V_94 = V_94 ;
return 0 ;
}
static void F_45 ( struct V_85 * * V_99 )
{
struct V_100 * V_101 ;
if ( ( * V_99 ) == NULL )
return;
V_101 = & ( ( * V_99 ) -> V_99 ) ;
F_46 ( & V_101 ) ;
* V_99 = NULL ;
}
void F_47 ( struct V_56 * V_53 )
{
struct V_85 * V_85 = F_48 ( V_53 ) ;
F_45 ( & V_85 ) ;
}
static inline T_5 F_49 ( struct V_85 * V_99 )
{
return F_50 ( & V_99 -> V_99 . V_102 ) ;
}
int
F_51 ( struct V_58 * V_91 ,
struct V_9 * V_10 ,
T_1 V_94 ,
T_6 * V_103 )
{
struct V_56 * V_53 ;
int V_8 ;
struct V_85 * V_99 ;
F_52 ( & V_10 -> V_104 ) ;
V_53 = F_25 ( V_10 , V_91 , V_94 ) ;
if ( V_53 == NULL ) {
V_8 = - V_61 ;
goto V_105;
}
V_99 = F_48 ( V_53 ) ;
* V_103 = F_49 ( V_99 ) ;
F_53 ( V_53 ) ;
V_8 = 0 ;
V_105:
F_54 ( & V_10 -> V_104 ) ;
return V_8 ;
}
