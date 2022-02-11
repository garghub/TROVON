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
T_1 F_12 ( struct V_9 * V_10 , int V_37 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
T_1 V_38 , V_39 ;
T_1 V_28 , V_36 , V_40 , V_41 , V_42 = 500 ;
V_28 = V_2 -> V_28 ;
V_36 = V_2 -> V_36 ;
if ( V_2 -> V_15 == V_22 ||
V_2 -> V_15 == V_16 ||
V_2 -> V_15 == V_20 ||
V_2 -> V_15 == V_21 ||
V_2 -> V_28 == 16 )
V_42 = 600 ;
else if ( V_2 -> V_15 == V_18 )
V_42 = 400 ;
V_40 = V_36 * V_28 * 2 / 8 ;
V_41 = V_40 * V_42 / 1000 ;
if ( V_2 -> V_15 == V_43 )
V_38 = V_41 / ( ( V_37 + 1 ) / 8 ) ;
else {
V_39 = F_6 ( V_2 , V_44 , 0xd0 , 0xff ) ;
if ( ( V_39 & 0x08 ) && ( V_2 -> V_15 == V_45 ) )
V_38 = V_41 / ( ( V_37 + 1 + 16 ) / 8 ) ;
else if ( ( V_39 & 0x08 ) && ( V_37 == 8 ) )
V_38 = V_41 / ( ( V_37 + 1 + 24 ) / 8 ) ;
else
V_38 = V_41 / ( ( V_37 + 1 ) / 8 ) ;
}
if ( V_2 -> V_15 == V_22 ||
V_2 -> V_15 == V_20 ||
V_2 -> V_15 == V_18 ||
V_2 -> V_15 == V_43 ) {
if ( V_38 > 200 )
V_38 = 200 ;
} else {
if ( V_38 > 165 )
V_38 = 165 ;
}
return V_38 ;
}
static void F_13 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_14 ( V_47 ) ;
if ( V_49 -> V_50 )
F_15 ( V_49 -> V_50 ) ;
F_16 ( V_47 ) ;
F_17 ( V_47 ) ;
}
int F_18 ( struct V_9 * V_10 ,
struct V_48 * V_49 ,
struct V_51 * V_52 ,
struct V_53 * V_50 )
{
int V_8 ;
F_19 ( & V_49 -> V_3 , V_52 ) ;
V_49 -> V_50 = V_50 ;
V_8 = F_20 ( V_10 , & V_49 -> V_3 , & V_54 ) ;
if ( V_8 ) {
F_21 ( L_8 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static struct V_46 *
F_22 ( struct V_9 * V_10 ,
struct V_55 * V_56 ,
struct V_51 * V_52 )
{
struct V_53 * V_50 ;
struct V_48 * V_49 ;
int V_8 ;
V_50 = F_23 ( V_10 , V_56 , V_52 -> V_57 [ 0 ] ) ;
if ( V_50 == NULL )
return F_24 ( - V_58 ) ;
V_49 = F_25 ( sizeof( * V_49 ) , V_59 ) ;
if ( ! V_49 ) {
F_15 ( V_50 ) ;
return F_24 ( - V_60 ) ;
}
V_8 = F_18 ( V_10 , V_49 , V_52 , V_50 ) ;
if ( V_8 ) {
F_15 ( V_50 ) ;
F_17 ( V_49 ) ;
return F_24 ( V_8 ) ;
}
return & V_49 -> V_3 ;
}
static T_4 F_26 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
T_3 V_39 ;
F_27 ( V_2 ) ;
V_39 = F_6 ( V_2 , V_44 , 0xaa , 0xff ) ;
switch ( V_39 & 3 ) {
case 0 : return V_61 ;
case 1 : return V_62 ;
case 2 : return V_63 ;
case 3 : return V_64 ;
}
return V_65 ;
}
int F_28 ( struct V_9 * V_10 , unsigned long V_66 )
{
struct V_1 * V_2 ;
int V_8 = 0 ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_59 ) ;
if ( ! V_2 )
return - V_60 ;
V_10 -> V_11 = V_2 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_67 = F_29 ( V_10 -> V_12 , 1 , 0 ) ;
if ( ! V_2 -> V_67 ) {
V_8 = - V_68 ;
goto V_69;
}
V_2 -> V_70 = F_29 ( V_10 -> V_12 , 2 , 0 ) ;
if ( ! V_2 -> V_70 ) {
V_8 = - V_68 ;
goto V_69;
}
F_7 ( V_10 ) ;
if ( V_2 -> V_15 != V_43 ) {
F_11 ( V_10 ) ;
V_2 -> V_71 = F_26 ( V_10 ) ;
F_8 ( L_9 , V_2 -> V_36 , V_2 -> V_29 , V_2 -> V_28 , V_2 -> V_71 ) ;
}
V_8 = F_30 ( V_2 ) ;
if ( V_8 )
goto V_69;
F_31 ( V_10 ) ;
V_10 -> V_72 . V_73 = ( void * ) & V_74 ;
V_10 -> V_72 . V_75 = 0 ;
V_10 -> V_72 . V_76 = 0 ;
V_10 -> V_72 . V_77 = 24 ;
V_10 -> V_72 . V_78 = 1 ;
if ( V_2 -> V_15 == V_22 ||
V_2 -> V_15 == V_20 ||
V_2 -> V_15 == V_18 ||
V_2 -> V_15 == V_43 ) {
V_10 -> V_72 . V_79 = 1920 ;
V_10 -> V_72 . V_80 = 2048 ;
} else {
V_10 -> V_72 . V_79 = 1600 ;
V_10 -> V_72 . V_80 = 1200 ;
}
V_8 = F_32 ( V_10 ) ;
if ( V_8 )
goto V_69;
V_8 = F_33 ( V_10 ) ;
if ( V_8 )
goto V_69;
return 0 ;
V_69:
F_17 ( V_2 ) ;
V_10 -> V_11 = NULL ;
return V_8 ;
}
int F_34 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
F_35 ( V_10 ) ;
F_36 ( V_10 ) ;
F_37 ( V_10 ) ;
F_38 ( V_2 ) ;
F_39 ( V_10 -> V_12 , V_2 -> V_70 ) ;
F_39 ( V_10 -> V_12 , V_2 -> V_67 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
int F_40 ( struct V_9 * V_10 ,
T_4 V_81 , bool V_82 ,
struct V_53 * * V_50 )
{
struct V_83 * V_84 ;
int V_8 ;
* V_50 = NULL ;
V_81 = F_41 ( V_81 , V_85 ) ;
if ( V_81 == 0 )
return - V_86 ;
V_8 = F_42 ( V_10 , V_81 , 0 , 0 , & V_84 ) ;
if ( V_8 ) {
if ( V_8 != - V_87 )
F_21 ( L_10 ) ;
return V_8 ;
}
* V_50 = & V_84 -> V_88 ;
return 0 ;
}
int F_43 ( struct V_55 * V_89 ,
struct V_9 * V_10 ,
struct V_90 * args )
{
int V_8 ;
struct V_53 * V_91 ;
T_4 V_92 ;
args -> V_93 = args -> V_94 * ( ( args -> V_37 + 7 ) / 8 ) ;
args -> V_81 = args -> V_93 * args -> V_95 ;
V_8 = F_40 ( V_10 , args -> V_81 , false ,
& V_91 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_44 ( V_89 , V_91 , & V_92 ) ;
F_15 ( V_91 ) ;
if ( V_8 )
return V_8 ;
args -> V_92 = V_92 ;
return 0 ;
}
int F_45 ( struct V_53 * V_50 )
{
F_46 () ;
return 0 ;
}
void F_47 ( struct V_83 * * V_96 )
{
struct V_97 * V_98 ;
if ( ( * V_96 ) == NULL )
return;
V_98 = & ( ( * V_96 ) -> V_96 ) ;
F_48 ( & V_98 ) ;
if ( V_98 == NULL )
* V_96 = NULL ;
}
void F_49 ( struct V_53 * V_50 )
{
struct V_83 * V_83 = F_50 ( V_50 ) ;
if ( ! V_83 )
return;
F_47 ( & V_83 ) ;
}
static inline T_5 F_51 ( struct V_83 * V_96 )
{
return F_52 ( & V_96 -> V_96 . V_99 ) ;
}
int
F_53 ( struct V_55 * V_89 ,
struct V_9 * V_10 ,
T_1 V_92 ,
T_6 * V_100 )
{
struct V_53 * V_50 ;
int V_8 ;
struct V_83 * V_96 ;
F_54 ( & V_10 -> V_101 ) ;
V_50 = F_23 ( V_10 , V_89 , V_92 ) ;
if ( V_50 == NULL ) {
V_8 = - V_58 ;
goto V_102;
}
V_96 = F_50 ( V_50 ) ;
* V_100 = F_51 ( V_96 ) ;
F_55 ( V_50 ) ;
V_8 = 0 ;
V_102:
F_56 ( & V_10 -> V_101 ) ;
return V_8 ;
}
