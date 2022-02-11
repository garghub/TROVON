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
if ( V_10 -> V_12 -> V_13 == V_14 ) {
V_2 -> V_15 = V_16 ;
F_8 ( L_1 ) ;
} else {
if ( V_10 -> V_12 -> V_17 >= 0x20 ) {
V_2 -> V_15 = V_18 ;
F_8 ( L_2 ) ;
} else if ( V_10 -> V_12 -> V_17 >= 0x10 ) {
T_1 V_19 ;
F_9 ( V_2 , 0xf004 , 0x1e6e0000 ) ;
F_9 ( V_2 , 0xf000 , 0x1 ) ;
V_19 = F_10 ( V_2 , 0x1207c ) ;
switch ( V_19 & 0x0300 ) {
case 0x0200 :
V_2 -> V_15 = V_16 ;
F_8 ( L_3 ) ;
break;
case 0x0100 :
V_2 -> V_15 = V_20 ;
F_8 ( L_4 ) ;
break;
case 0x0000 :
V_2 -> V_15 = V_21 ;
F_8 ( L_5 ) ;
break;
default:
V_2 -> V_15 = V_22 ;
F_8 ( L_6 ) ;
break;
}
V_2 -> V_23 = false ;
} else {
V_2 -> V_15 = 2000 ;
F_8 ( L_7 ) ;
}
}
return 0 ;
}
static int F_11 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
T_1 V_19 , V_24 ;
T_1 V_25 , V_26 , div , V_27 ;
F_9 ( V_2 , 0xf004 , 0x1e6e0000 ) ;
F_9 ( V_2 , 0xf000 , 0x1 ) ;
F_9 ( V_2 , 0x10000 , 0xfc600309 ) ;
do {
;
} while ( F_10 ( V_2 , 0x10000 ) != 0x01 );
V_19 = F_10 ( V_2 , 0x10004 ) ;
if ( V_19 & 0x400 )
V_2 -> V_28 = 16 ;
else
V_2 -> V_28 = 32 ;
if ( V_2 -> V_15 == V_18 ) {
switch ( V_19 & 0x03 ) {
case 0 :
V_2 -> V_29 = V_30 ;
break;
default:
case 1 :
V_2 -> V_29 = V_31 ;
break;
case 2 :
V_2 -> V_29 = V_32 ;
break;
case 3 :
V_2 -> V_29 = V_33 ;
break;
}
} else {
switch ( V_19 & 0x0c ) {
case 0 :
case 4 :
V_2 -> V_29 = V_30 ;
break;
case 8 :
if ( V_19 & 0x40 )
V_2 -> V_29 = V_31 ;
else
V_2 -> V_29 = V_34 ;
break;
case 0xc :
V_2 -> V_29 = V_35 ;
break;
}
}
V_19 = F_10 ( V_2 , 0x10120 ) ;
V_24 = F_10 ( V_2 , 0x10170 ) ;
if ( V_24 & 0x2000 )
V_27 = 14318 ;
else
V_27 = 12000 ;
V_25 = V_19 & 0x1f ;
V_26 = ( V_19 & 0x3fe0 ) >> 5 ;
V_19 = ( V_19 & 0xc000 ) >> 14 ;
switch ( V_19 ) {
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
V_2 -> V_36 = V_27 * ( V_26 + 2 ) / ( V_25 + 2 ) * ( div * 1000 ) ;
return 0 ;
}
static void F_12 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_13 ( V_38 ) ;
if ( V_40 -> V_41 )
F_14 ( V_40 -> V_41 ) ;
F_15 ( V_38 ) ;
F_16 ( V_38 ) ;
}
int F_17 ( struct V_9 * V_10 ,
struct V_39 * V_40 ,
struct V_42 * V_43 ,
struct V_44 * V_41 )
{
int V_8 ;
F_18 ( & V_40 -> V_3 , V_43 ) ;
V_40 -> V_41 = V_41 ;
V_8 = F_19 ( V_10 , & V_40 -> V_3 , & V_45 ) ;
if ( V_8 ) {
F_20 ( L_8 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static struct V_37 *
F_21 ( struct V_9 * V_10 ,
struct V_46 * V_47 ,
struct V_42 * V_43 )
{
struct V_44 * V_41 ;
struct V_39 * V_40 ;
int V_8 ;
V_41 = F_22 ( V_10 , V_47 , V_43 -> V_48 [ 0 ] ) ;
if ( V_41 == NULL )
return F_23 ( - V_49 ) ;
V_40 = F_24 ( sizeof( * V_40 ) , V_50 ) ;
if ( ! V_40 ) {
F_14 ( V_41 ) ;
return F_23 ( - V_51 ) ;
}
V_8 = F_17 ( V_10 , V_40 , V_43 , V_41 ) ;
if ( V_8 ) {
F_14 ( V_41 ) ;
F_16 ( V_40 ) ;
return F_23 ( V_8 ) ;
}
return & V_40 -> V_3 ;
}
static T_4 F_25 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
T_3 V_52 ;
F_26 ( V_2 ) ;
V_52 = F_6 ( V_2 , V_53 , 0xaa , 0xff ) ;
switch ( V_52 & 3 ) {
case 0 : return V_54 ;
case 1 : return V_55 ;
case 2 : return V_56 ;
case 3 : return V_57 ;
}
return V_58 ;
}
int F_27 ( struct V_9 * V_10 , unsigned long V_59 )
{
struct V_1 * V_2 ;
int V_8 = 0 ;
V_2 = F_24 ( sizeof( struct V_1 ) , V_50 ) ;
if ( ! V_2 )
return - V_51 ;
V_10 -> V_11 = V_2 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_60 = F_28 ( V_10 -> V_12 , 1 , 0 ) ;
if ( ! V_2 -> V_60 ) {
V_8 = - V_61 ;
goto V_62;
}
V_2 -> V_63 = F_28 ( V_10 -> V_12 , 2 , 0 ) ;
if ( ! V_2 -> V_63 ) {
V_8 = - V_61 ;
goto V_62;
}
F_7 ( V_10 ) ;
if ( V_2 -> V_15 != V_64 ) {
F_11 ( V_10 ) ;
V_2 -> V_65 = F_25 ( V_10 ) ;
F_8 ( L_9 , V_2 -> V_36 , V_2 -> V_29 , V_2 -> V_28 , V_2 -> V_65 ) ;
}
V_8 = F_29 ( V_2 ) ;
if ( V_8 )
goto V_62;
F_30 ( V_10 ) ;
V_10 -> V_66 . V_67 = ( void * ) & V_68 ;
V_10 -> V_66 . V_69 = 0 ;
V_10 -> V_66 . V_70 = 0 ;
V_10 -> V_66 . V_71 = 24 ;
V_10 -> V_66 . V_72 = 1 ;
if ( V_2 -> V_15 == V_22 ||
V_2 -> V_15 == V_20 ||
V_2 -> V_15 == V_18 ||
V_2 -> V_15 == V_64 ) {
V_10 -> V_66 . V_73 = 1920 ;
V_10 -> V_66 . V_74 = 2048 ;
} else {
V_10 -> V_66 . V_73 = 1600 ;
V_10 -> V_66 . V_74 = 1200 ;
}
V_8 = F_31 ( V_10 ) ;
if ( V_8 )
goto V_62;
V_8 = F_32 ( V_10 ) ;
if ( V_8 )
goto V_62;
return 0 ;
V_62:
F_16 ( V_2 ) ;
V_10 -> V_11 = NULL ;
return V_8 ;
}
int F_33 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
F_34 ( V_10 ) ;
F_35 ( V_10 ) ;
F_36 ( V_10 ) ;
F_37 ( V_2 ) ;
F_38 ( V_10 -> V_12 , V_2 -> V_63 ) ;
F_38 ( V_10 -> V_12 , V_2 -> V_60 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
int F_39 ( struct V_9 * V_10 ,
T_4 V_75 , bool V_76 ,
struct V_44 * * V_41 )
{
struct V_77 * V_78 ;
int V_8 ;
* V_41 = NULL ;
V_75 = F_40 ( V_75 , V_79 ) ;
if ( V_75 == 0 )
return - V_80 ;
V_8 = F_41 ( V_10 , V_75 , 0 , 0 , & V_78 ) ;
if ( V_8 ) {
if ( V_8 != - V_81 )
F_20 ( L_10 ) ;
return V_8 ;
}
* V_41 = & V_78 -> V_82 ;
return 0 ;
}
int F_42 ( struct V_46 * V_83 ,
struct V_9 * V_10 ,
struct V_84 * args )
{
int V_8 ;
struct V_44 * V_85 ;
T_4 V_86 ;
args -> V_87 = args -> V_88 * ( ( args -> V_89 + 7 ) / 8 ) ;
args -> V_75 = args -> V_87 * args -> V_90 ;
V_8 = F_39 ( V_10 , args -> V_75 , false ,
& V_85 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_43 ( V_83 , V_85 , & V_86 ) ;
F_14 ( V_85 ) ;
if ( V_8 )
return V_8 ;
args -> V_86 = V_86 ;
return 0 ;
}
static void F_44 ( struct V_77 * * V_91 )
{
struct V_92 * V_93 ;
if ( ( * V_91 ) == NULL )
return;
V_93 = & ( ( * V_91 ) -> V_91 ) ;
F_45 ( & V_93 ) ;
if ( V_93 == NULL )
* V_91 = NULL ;
}
void F_46 ( struct V_44 * V_41 )
{
struct V_77 * V_77 = F_47 ( V_41 ) ;
if ( ! V_77 )
return;
F_44 ( & V_77 ) ;
}
static inline T_5 F_48 ( struct V_77 * V_91 )
{
return F_49 ( & V_91 -> V_91 . V_94 ) ;
}
int
F_50 ( struct V_46 * V_83 ,
struct V_9 * V_10 ,
T_1 V_86 ,
T_6 * V_95 )
{
struct V_44 * V_41 ;
int V_8 ;
struct V_77 * V_91 ;
F_51 ( & V_10 -> V_96 ) ;
V_41 = F_22 ( V_10 , V_83 , V_86 ) ;
if ( V_41 == NULL ) {
V_8 = - V_49 ;
goto V_97;
}
V_91 = F_47 ( V_41 ) ;
* V_95 = F_48 ( V_91 ) ;
F_52 ( V_41 ) ;
V_8 = 0 ;
V_97:
F_53 ( & V_10 -> V_96 ) ;
return V_8 ;
}
