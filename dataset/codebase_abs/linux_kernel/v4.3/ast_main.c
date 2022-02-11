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
static int F_7 ( struct V_9 * V_10 , bool * V_11 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
T_1 V_13 , V_14 ;
F_8 ( V_2 ) ;
if ( V_10 -> V_15 -> V_16 == V_17 ) {
V_2 -> V_18 = V_19 ;
F_9 ( L_1 ) ;
} else {
if ( V_10 -> V_15 -> V_20 >= 0x30 ) {
V_2 -> V_18 = V_21 ;
F_9 ( L_2 ) ;
} else if ( V_10 -> V_15 -> V_20 >= 0x20 ) {
V_2 -> V_18 = V_22 ;
F_9 ( L_3 ) ;
} else if ( V_10 -> V_15 -> V_20 >= 0x10 ) {
T_1 V_13 ;
F_10 ( V_2 , 0xf004 , 0x1e6e0000 ) ;
F_10 ( V_2 , 0xf000 , 0x1 ) ;
V_13 = F_11 ( V_2 , 0x1207c ) ;
switch ( V_13 & 0x0300 ) {
case 0x0200 :
V_2 -> V_18 = V_19 ;
F_9 ( L_4 ) ;
break;
case 0x0100 :
V_2 -> V_18 = V_23 ;
F_9 ( L_5 ) ;
break;
case 0x0000 :
V_2 -> V_18 = V_24 ;
F_9 ( L_6 ) ;
break;
default:
V_2 -> V_18 = V_25 ;
F_9 ( L_7 ) ;
break;
}
V_2 -> V_26 = false ;
} else {
V_2 -> V_18 = V_27 ;
F_9 ( L_8 ) ;
}
}
if ( ! F_12 ( V_10 ) ) {
F_13 ( V_10 ) ;
F_14 ( V_10 ) ;
F_9 ( L_9 ) ;
* V_11 = true ;
} else
* V_11 = false ;
switch ( V_2 -> V_18 ) {
case V_28 :
V_2 -> V_29 = true ;
break;
case V_27 :
V_2 -> V_29 = false ;
break;
default:
V_14 = F_6 ( V_2 , V_30 , 0xd0 , 0xff ) ;
if ( ! ( V_14 & 0x80 ) )
V_2 -> V_29 = true ;
else if ( V_14 & 0x01 )
V_2 -> V_29 = true ;
else {
V_2 -> V_29 = false ;
F_10 ( V_2 , 0xf004 , 0x1e6e0000 ) ;
F_10 ( V_2 , 0xf000 , 0x1 ) ;
V_13 = F_11 ( V_2 , 0x1207c ) ;
V_13 &= 0x300 ;
if ( V_2 -> V_18 == V_22 && V_13 == 0x0 )
V_2 -> V_29 = true ;
if ( V_2 -> V_18 == V_21 && V_13 == 0x100 )
V_2 -> V_29 = true ;
}
break;
}
V_2 -> V_31 = V_32 ;
if ( ! * V_11 ) {
V_14 = F_6 ( V_2 , V_30 , 0xa3 , 0xff ) ;
if ( V_14 & 0x80 )
V_2 -> V_31 = V_33 ;
}
if ( ( V_2 -> V_18 == V_22 ) || ( V_2 -> V_18 == V_21 ) ) {
V_14 = F_6 ( V_2 , V_30 , 0xd1 , 0xff ) ;
switch ( V_14 ) {
case 0x04 :
V_2 -> V_31 = V_33 ;
break;
case 0x08 :
V_2 -> V_34 = F_15 ( 32 * 1024 , V_35 ) ;
if ( V_2 -> V_34 ) {
if ( F_16 ( V_10 , V_2 -> V_34 , 32 * 1024 ) ) {
F_17 ( V_2 -> V_34 ) ;
V_2 -> V_34 = NULL ;
}
}
case 0x0c :
V_2 -> V_31 = V_36 ;
}
}
switch( V_2 -> V_31 ) {
case V_33 :
F_9 ( L_10 ) ;
break;
case V_36 :
F_9 ( L_11 ) ;
break;
default:
F_9 ( L_12 ) ;
}
return 0 ;
}
static int F_18 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
T_1 V_13 , V_37 ;
T_1 V_38 , V_39 , div , V_40 ;
F_10 ( V_2 , 0xf004 , 0x1e6e0000 ) ;
F_10 ( V_2 , 0xf000 , 0x1 ) ;
F_10 ( V_2 , 0x10000 , 0xfc600309 ) ;
do {
;
} while ( F_11 ( V_2 , 0x10000 ) != 0x01 );
V_13 = F_11 ( V_2 , 0x10004 ) ;
if ( V_13 & 0x400 )
V_2 -> V_41 = 16 ;
else
V_2 -> V_41 = 32 ;
if ( V_2 -> V_18 == V_22 || V_2 -> V_18 == V_21 ) {
switch ( V_13 & 0x03 ) {
case 0 :
V_2 -> V_42 = V_43 ;
break;
default:
case 1 :
V_2 -> V_42 = V_44 ;
break;
case 2 :
V_2 -> V_42 = V_45 ;
break;
case 3 :
V_2 -> V_42 = V_46 ;
break;
}
} else {
switch ( V_13 & 0x0c ) {
case 0 :
case 4 :
V_2 -> V_42 = V_43 ;
break;
case 8 :
if ( V_13 & 0x40 )
V_2 -> V_42 = V_44 ;
else
V_2 -> V_42 = V_47 ;
break;
case 0xc :
V_2 -> V_42 = V_48 ;
break;
}
}
V_13 = F_11 ( V_2 , 0x10120 ) ;
V_37 = F_11 ( V_2 , 0x10170 ) ;
if ( V_37 & 0x2000 )
V_40 = 14318 ;
else
V_40 = 12000 ;
V_38 = V_13 & 0x1f ;
V_39 = ( V_13 & 0x3fe0 ) >> 5 ;
V_13 = ( V_13 & 0xc000 ) >> 14 ;
switch ( V_13 ) {
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
V_2 -> V_49 = V_40 * ( V_39 + 2 ) / ( V_38 + 2 ) * ( div * 1000 ) ;
return 0 ;
}
static void F_19 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_20 ( V_51 ) ;
if ( V_53 -> V_54 )
F_21 ( V_53 -> V_54 ) ;
F_22 ( V_51 ) ;
F_17 ( V_51 ) ;
}
int F_23 ( struct V_9 * V_10 ,
struct V_52 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_54 )
{
int V_8 ;
F_24 ( & V_53 -> V_3 , V_56 ) ;
V_53 -> V_54 = V_54 ;
V_8 = F_25 ( V_10 , & V_53 -> V_3 , & V_58 ) ;
if ( V_8 ) {
F_26 ( L_13 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static struct V_50 *
F_27 ( struct V_9 * V_10 ,
struct V_59 * V_60 ,
struct V_55 * V_56 )
{
struct V_57 * V_54 ;
struct V_52 * V_53 ;
int V_8 ;
V_54 = F_28 ( V_10 , V_60 , V_56 -> V_61 [ 0 ] ) ;
if ( V_54 == NULL )
return F_29 ( - V_62 ) ;
V_53 = F_15 ( sizeof( * V_53 ) , V_35 ) ;
if ( ! V_53 ) {
F_21 ( V_54 ) ;
return F_29 ( - V_63 ) ;
}
V_8 = F_23 ( V_10 , V_53 , V_56 , V_54 ) ;
if ( V_8 ) {
F_21 ( V_54 ) ;
F_17 ( V_53 ) ;
return F_29 ( V_8 ) ;
}
return & V_53 -> V_3 ;
}
static T_4 F_30 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
T_3 V_14 ;
T_4 V_64 ;
F_8 ( V_2 ) ;
V_64 = V_65 ;
V_14 = F_6 ( V_2 , V_30 , 0xaa , 0xff ) ;
switch ( V_14 & 3 ) {
case 0 : V_64 = V_66 ; break;
case 1 : V_64 = V_67 ; break;
case 2 : V_64 = V_68 ; break;
case 3 : V_64 = V_69 ; break;
}
V_14 = F_6 ( V_2 , V_30 , 0x99 , 0xff ) ;
switch ( V_14 & 0x03 ) {
case 1 :
V_64 -= 0x100000 ;
break;
case 2 :
V_64 -= 0x200000 ;
break;
case 3 :
V_64 -= 0x400000 ;
break;
}
return V_64 ;
}
int F_31 ( struct V_9 * V_10 , unsigned long V_70 )
{
struct V_1 * V_2 ;
bool V_11 ;
int V_8 = 0 ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_35 ) ;
if ( ! V_2 )
return - V_63 ;
V_10 -> V_12 = V_2 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_71 = F_32 ( V_10 -> V_15 , 1 , 0 ) ;
if ( ! V_2 -> V_71 ) {
V_8 = - V_72 ;
goto V_73;
}
if ( ! ( F_33 ( V_10 -> V_15 , 2 ) & V_74 ) ) {
F_9 ( L_14 ) ;
V_2 -> V_75 = V_2 -> V_71 + V_76 ;
}
if ( ! V_2 -> V_75 ) {
V_2 -> V_75 = F_32 ( V_10 -> V_15 , 2 , 0 ) ;
if ( ! V_2 -> V_75 ) {
V_8 = - V_72 ;
goto V_73;
}
}
F_7 ( V_10 , & V_11 ) ;
if ( V_2 -> V_18 != V_28 ) {
F_18 ( V_10 ) ;
V_2 -> V_64 = F_30 ( V_10 ) ;
F_9 ( L_15 , V_2 -> V_49 , V_2 -> V_42 , V_2 -> V_41 , V_2 -> V_64 ) ;
}
if ( V_11 )
F_34 ( V_10 ) ;
V_8 = F_35 ( V_2 ) ;
if ( V_8 )
goto V_73;
F_36 ( V_10 ) ;
V_10 -> V_77 . V_78 = ( void * ) & V_79 ;
V_10 -> V_77 . V_80 = 0 ;
V_10 -> V_77 . V_81 = 0 ;
V_10 -> V_77 . V_82 = 24 ;
V_10 -> V_77 . V_83 = 1 ;
if ( V_2 -> V_18 == V_25 ||
V_2 -> V_18 == V_23 ||
V_2 -> V_18 == V_22 ||
V_2 -> V_18 == V_21 ||
V_2 -> V_18 == V_28 ) {
V_10 -> V_77 . V_84 = 1920 ;
V_10 -> V_77 . V_85 = 2048 ;
} else {
V_10 -> V_77 . V_84 = 1600 ;
V_10 -> V_77 . V_85 = 1200 ;
}
V_8 = F_37 ( V_10 ) ;
if ( V_8 )
goto V_73;
V_8 = F_38 ( V_10 ) ;
if ( V_8 )
goto V_73;
return 0 ;
V_73:
F_17 ( V_2 ) ;
V_10 -> V_12 = NULL ;
return V_8 ;
}
int F_39 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
F_17 ( V_2 -> V_34 ) ;
F_40 ( V_10 ) ;
F_41 ( V_10 ) ;
F_42 ( V_10 ) ;
F_43 ( V_2 ) ;
F_44 ( V_10 -> V_15 , V_2 -> V_75 ) ;
F_44 ( V_10 -> V_15 , V_2 -> V_71 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
int F_45 ( struct V_9 * V_10 ,
T_4 V_86 , bool V_87 ,
struct V_57 * * V_54 )
{
struct V_88 * V_89 ;
int V_8 ;
* V_54 = NULL ;
V_86 = F_46 ( V_86 , V_90 ) ;
if ( V_86 == 0 )
return - V_91 ;
V_8 = F_47 ( V_10 , V_86 , 0 , 0 , & V_89 ) ;
if ( V_8 ) {
if ( V_8 != - V_92 )
F_26 ( L_16 ) ;
return V_8 ;
}
* V_54 = & V_89 -> V_93 ;
return 0 ;
}
int F_48 ( struct V_59 * V_94 ,
struct V_9 * V_10 ,
struct V_95 * args )
{
int V_8 ;
struct V_57 * V_96 ;
T_4 V_97 ;
args -> V_98 = args -> V_99 * ( ( args -> V_100 + 7 ) / 8 ) ;
args -> V_86 = args -> V_98 * args -> V_101 ;
V_8 = F_45 ( V_10 , args -> V_86 , false ,
& V_96 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_49 ( V_94 , V_96 , & V_97 ) ;
F_21 ( V_96 ) ;
if ( V_8 )
return V_8 ;
args -> V_97 = V_97 ;
return 0 ;
}
static void F_50 ( struct V_88 * * V_102 )
{
struct V_103 * V_104 ;
if ( ( * V_102 ) == NULL )
return;
V_104 = & ( ( * V_102 ) -> V_102 ) ;
F_51 ( & V_104 ) ;
* V_102 = NULL ;
}
void F_52 ( struct V_57 * V_54 )
{
struct V_88 * V_88 = F_53 ( V_54 ) ;
F_50 ( & V_88 ) ;
}
static inline T_5 F_54 ( struct V_88 * V_102 )
{
return F_55 ( & V_102 -> V_102 . V_105 ) ;
}
int
F_56 ( struct V_59 * V_94 ,
struct V_9 * V_10 ,
T_1 V_97 ,
T_6 * V_106 )
{
struct V_57 * V_54 ;
struct V_88 * V_102 ;
V_54 = F_28 ( V_10 , V_94 , V_97 ) ;
if ( V_54 == NULL )
return - V_62 ;
V_102 = F_53 ( V_54 ) ;
* V_106 = F_54 ( V_102 ) ;
F_21 ( V_54 ) ;
return 0 ;
}
