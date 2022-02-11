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
static void F_7 ( struct V_9 * V_10 , T_4 * V_11 )
{
struct V_12 * V_13 = V_10 -> V_14 -> V_10 . V_15 ;
struct V_1 * V_2 = V_10 -> V_16 ;
T_1 V_17 , V_18 , V_19 ;
V_2 -> V_20 = V_21 ;
* V_11 = 0xffffffff ;
if ( V_13 && ! F_8 ( V_13 , L_1 ,
V_11 ) ) {
V_2 -> V_20 = V_22 ;
F_9 ( L_2 ) ;
return;
}
if ( V_10 -> V_14 -> V_23 != V_24 )
return;
V_18 = F_6 ( V_2 , V_25 , 0xd0 , 0xff ) ;
V_19 = F_6 ( V_2 , V_25 , 0xd1 , 0xff ) ;
if ( ! ( V_18 & 0x80 ) || ! ( V_19 & 0x10 ) ) {
V_17 = F_10 ( V_2 , 0xf004 ) ;
if ( V_17 != 0xFFFFFFFF ) {
V_2 -> V_20 = V_26 ;
F_9 ( L_3 ) ;
F_11 ( V_2 , 0xf004 , 0x1e6e0000 ) ;
F_11 ( V_2 , 0xf000 , 0x1 ) ;
* V_11 = F_10 ( V_2 , 0x1207c ) ;
return;
}
}
F_9 ( L_4 ) ;
}
static int F_12 ( struct V_9 * V_10 , bool * V_27 )
{
struct V_1 * V_2 = V_10 -> V_16 ;
T_1 V_28 , V_11 ;
if ( ! F_13 ( V_10 ) ) {
F_14 ( V_10 ) ;
F_9 ( L_5 ) ;
* V_27 = true ;
} else
* V_27 = false ;
F_15 ( V_10 ) ;
F_16 ( V_2 ) ;
F_7 ( V_10 , & V_11 ) ;
if ( V_10 -> V_14 -> V_23 == V_29 ) {
V_2 -> V_30 = V_31 ;
F_9 ( L_6 ) ;
} else {
if ( V_10 -> V_14 -> V_32 >= 0x40 ) {
V_2 -> V_30 = V_33 ;
F_9 ( L_7 ) ;
} else if ( V_10 -> V_14 -> V_32 >= 0x30 ) {
V_2 -> V_30 = V_34 ;
F_9 ( L_8 ) ;
} else if ( V_10 -> V_14 -> V_32 >= 0x20 ) {
V_2 -> V_30 = V_35 ;
F_9 ( L_9 ) ;
} else if ( V_10 -> V_14 -> V_32 >= 0x10 ) {
switch ( V_11 & 0x0300 ) {
case 0x0200 :
V_2 -> V_30 = V_31 ;
F_9 ( L_10 ) ;
break;
case 0x0100 :
V_2 -> V_30 = V_36 ;
F_9 ( L_11 ) ;
break;
case 0x0000 :
V_2 -> V_30 = V_37 ;
F_9 ( L_12 ) ;
break;
default:
V_2 -> V_30 = V_38 ;
F_9 ( L_13 ) ;
break;
}
V_2 -> V_39 = false ;
} else {
V_2 -> V_30 = V_40 ;
F_9 ( L_14 ) ;
}
}
switch ( V_2 -> V_30 ) {
case V_41 :
V_2 -> V_42 = true ;
break;
case V_40 :
V_2 -> V_42 = false ;
break;
default:
V_28 = F_6 ( V_2 , V_25 , 0xd0 , 0xff ) ;
if ( ! ( V_28 & 0x80 ) )
V_2 -> V_42 = true ;
else if ( V_28 & 0x01 )
V_2 -> V_42 = true ;
else {
V_2 -> V_42 = false ;
if ( V_2 -> V_30 == V_35 &&
( V_11 & 0x300 ) == 0x0 )
V_2 -> V_42 = true ;
if ( V_2 -> V_30 == V_34 &&
( V_11 & 0x300 ) == 0x100 )
V_2 -> V_42 = true ;
if ( V_2 -> V_30 == V_33 &&
V_11 == 0x100 )
V_2 -> V_42 = true ;
}
break;
}
V_2 -> V_43 = V_44 ;
if ( ! * V_27 ) {
V_28 = F_6 ( V_2 , V_25 , 0xa3 , 0xff ) ;
if ( V_28 & 0x80 )
V_2 -> V_43 = V_45 ;
}
if ( ( V_2 -> V_30 == V_35 ) || ( V_2 -> V_30 == V_34 ) ) {
V_28 = F_6 ( V_2 , V_25 , 0xd1 , 0xff ) ;
switch ( V_28 ) {
case 0x04 :
V_2 -> V_43 = V_45 ;
break;
case 0x08 :
V_2 -> V_46 = F_17 ( 32 * 1024 , V_47 ) ;
if ( V_2 -> V_46 ) {
if ( F_18 ( V_10 , V_2 -> V_46 , 32 * 1024 ) ) {
F_19 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
}
}
case 0x0c :
V_2 -> V_43 = V_48 ;
}
}
switch( V_2 -> V_43 ) {
case V_45 :
F_9 ( L_15 ) ;
break;
case V_48 :
F_9 ( L_16 ) ;
break;
default:
F_9 ( L_17 ) ;
}
return 0 ;
}
static int F_20 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 -> V_10 . V_15 ;
struct V_1 * V_2 = V_10 -> V_16 ;
T_1 V_49 , V_50 , V_51 ;
T_1 V_52 , V_53 , div , V_54 , V_55 ;
switch ( V_2 -> V_20 ) {
case V_22 :
if ( F_8 ( V_13 , L_18 ,
& V_49 ) )
V_49 = 0x00000577 ;
if ( F_8 ( V_13 , L_19 ,
& V_50 ) )
V_50 = 0x000050C0 ;
if ( F_8 ( V_13 , L_20 ,
& V_51 ) )
V_51 = 0 ;
break;
case V_26 :
F_11 ( V_2 , 0xf004 , 0x1e6e0000 ) ;
F_11 ( V_2 , 0xf000 , 0x1 ) ;
V_49 = F_10 ( V_2 , 0x10004 ) ;
V_50 = F_10 ( V_2 , 0x10120 ) ;
V_51 = F_10 ( V_2 , 0x10170 ) ;
break;
case V_21 :
default:
V_2 -> V_56 = 16 ;
V_2 -> V_57 = V_58 ;
if ( V_2 -> V_30 == V_33 )
V_2 -> V_59 = 800 ;
else
V_2 -> V_59 = 396 ;
return 0 ;
}
if ( V_49 & 0x40 )
V_2 -> V_56 = 16 ;
else
V_2 -> V_56 = 32 ;
if ( V_2 -> V_30 == V_33 ) {
switch ( V_49 & 0x03 ) {
case 0 :
V_2 -> V_57 = V_58 ;
break;
default:
case 1 :
V_2 -> V_57 = V_60 ;
break;
case 2 :
V_2 -> V_57 = V_61 ;
break;
case 3 :
V_2 -> V_57 = V_62 ;
break;
}
} else if ( V_2 -> V_30 == V_35 || V_2 -> V_30 == V_34 ) {
switch ( V_49 & 0x03 ) {
case 0 :
V_2 -> V_57 = V_63 ;
break;
default:
case 1 :
V_2 -> V_57 = V_58 ;
break;
case 2 :
V_2 -> V_57 = V_60 ;
break;
case 3 :
V_2 -> V_57 = V_61 ;
break;
}
} else {
switch ( V_49 & 0x0c ) {
case 0 :
case 4 :
V_2 -> V_57 = V_63 ;
break;
case 8 :
if ( V_49 & 0x40 )
V_2 -> V_57 = V_58 ;
else
V_2 -> V_57 = V_64 ;
break;
case 0xc :
V_2 -> V_57 = V_65 ;
break;
}
}
if ( V_51 & 0x2000 )
V_54 = 14318 ;
else
V_54 = 12000 ;
V_52 = V_50 & 0x1f ;
V_53 = ( V_50 & 0x3fe0 ) >> 5 ;
V_55 = ( V_50 & 0xc000 ) >> 14 ;
switch ( V_55 ) {
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
V_2 -> V_59 = V_54 * ( V_53 + 2 ) / ( ( V_52 + 2 ) * ( div * 1000 ) ) ;
return 0 ;
}
static void F_21 ( struct V_66 * V_67 )
{
struct V_68 * V_69 = F_22 ( V_67 ) ;
F_23 ( V_69 -> V_70 ) ;
F_24 ( V_67 ) ;
F_19 ( V_67 ) ;
}
int F_25 ( struct V_9 * V_10 ,
struct V_68 * V_69 ,
const struct V_71 * V_72 ,
struct V_73 * V_70 )
{
int V_8 ;
F_26 ( V_10 , & V_69 -> V_3 , V_72 ) ;
V_69 -> V_70 = V_70 ;
V_8 = F_27 ( V_10 , & V_69 -> V_3 , & V_74 ) ;
if ( V_8 ) {
F_28 ( L_21 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static struct V_66 *
F_29 ( struct V_9 * V_10 ,
struct V_75 * V_76 ,
const struct V_71 * V_72 )
{
struct V_73 * V_70 ;
struct V_68 * V_69 ;
int V_8 ;
V_70 = F_30 ( V_76 , V_72 -> V_77 [ 0 ] ) ;
if ( V_70 == NULL )
return F_31 ( - V_78 ) ;
V_69 = F_17 ( sizeof( * V_69 ) , V_47 ) ;
if ( ! V_69 ) {
F_23 ( V_70 ) ;
return F_31 ( - V_79 ) ;
}
V_8 = F_25 ( V_10 , V_69 , V_72 , V_70 ) ;
if ( V_8 ) {
F_23 ( V_70 ) ;
F_19 ( V_69 ) ;
return F_31 ( V_8 ) ;
}
return & V_69 -> V_3 ;
}
static T_4 F_32 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_16 ;
T_3 V_28 ;
T_4 V_80 ;
F_16 ( V_2 ) ;
V_80 = V_81 ;
V_28 = F_6 ( V_2 , V_25 , 0xaa , 0xff ) ;
switch ( V_28 & 3 ) {
case 0 : V_80 = V_82 ; break;
case 1 : V_80 = V_83 ; break;
case 2 : V_80 = V_84 ; break;
case 3 : V_80 = V_85 ; break;
}
V_28 = F_6 ( V_2 , V_25 , 0x99 , 0xff ) ;
switch ( V_28 & 0x03 ) {
case 1 :
V_80 -= 0x100000 ;
break;
case 2 :
V_80 -= 0x200000 ;
break;
case 3 :
V_80 -= 0x400000 ;
break;
}
return V_80 ;
}
int F_33 ( struct V_9 * V_10 , unsigned long V_86 )
{
struct V_1 * V_2 ;
bool V_27 ;
int V_8 = 0 ;
V_2 = F_17 ( sizeof( struct V_1 ) , V_47 ) ;
if ( ! V_2 )
return - V_79 ;
V_10 -> V_16 = V_2 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_87 = F_34 ( V_10 -> V_14 , 1 , 0 ) ;
if ( ! V_2 -> V_87 ) {
V_8 = - V_88 ;
goto V_89;
}
if ( ! ( F_35 ( V_10 -> V_14 , 2 ) & V_90 ) ) {
F_9 ( L_22 ) ;
V_2 -> V_91 = V_2 -> V_87 + V_92 ;
}
if ( ! V_2 -> V_91 ) {
V_2 -> V_91 = F_34 ( V_10 -> V_14 , 2 , 0 ) ;
if ( ! V_2 -> V_91 ) {
V_8 = - V_88 ;
goto V_89;
}
}
F_12 ( V_10 , & V_27 ) ;
if ( V_27 )
F_36 ( V_10 ) ;
if ( V_2 -> V_30 != V_41 ) {
V_8 = F_20 ( V_10 ) ;
if ( V_8 )
goto V_89;
V_2 -> V_80 = F_32 ( V_10 ) ;
F_9 ( L_23 ,
V_2 -> V_59 , V_2 -> V_57 ,
V_2 -> V_56 , V_2 -> V_80 ) ;
}
V_8 = F_37 ( V_2 ) ;
if ( V_8 )
goto V_89;
F_38 ( V_10 ) ;
V_10 -> V_93 . V_94 = ( void * ) & V_95 ;
V_10 -> V_93 . V_96 = 0 ;
V_10 -> V_93 . V_97 = 0 ;
V_10 -> V_93 . V_98 = 24 ;
V_10 -> V_93 . V_99 = 1 ;
V_10 -> V_93 . V_100 = F_39 ( V_2 -> V_10 -> V_14 , 0 ) ;
if ( V_2 -> V_30 == V_38 ||
V_2 -> V_30 == V_36 ||
V_2 -> V_30 == V_35 ||
V_2 -> V_30 == V_34 ||
V_2 -> V_30 == V_33 ||
V_2 -> V_30 == V_41 ) {
V_10 -> V_93 . V_101 = 1920 ;
V_10 -> V_93 . V_102 = 2048 ;
} else {
V_10 -> V_93 . V_101 = 1600 ;
V_10 -> V_93 . V_102 = 1200 ;
}
V_8 = F_40 ( V_10 ) ;
if ( V_8 )
goto V_89;
V_8 = F_41 ( V_10 ) ;
if ( V_8 )
goto V_89;
return 0 ;
V_89:
F_19 ( V_2 ) ;
V_10 -> V_16 = NULL ;
return V_8 ;
}
void F_42 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_16 ;
F_19 ( V_2 -> V_46 ) ;
F_43 ( V_10 ) ;
F_44 ( V_10 ) ;
F_45 ( V_10 ) ;
F_46 ( V_2 ) ;
F_47 ( V_10 -> V_14 , V_2 -> V_91 ) ;
F_47 ( V_10 -> V_14 , V_2 -> V_87 ) ;
F_19 ( V_2 ) ;
}
int F_48 ( struct V_9 * V_10 ,
T_4 V_103 , bool V_104 ,
struct V_73 * * V_70 )
{
struct V_105 * V_106 ;
int V_8 ;
* V_70 = NULL ;
V_103 = F_49 ( V_103 , V_107 ) ;
if ( V_103 == 0 )
return - V_108 ;
V_8 = F_50 ( V_10 , V_103 , 0 , 0 , & V_106 ) ;
if ( V_8 ) {
if ( V_8 != - V_109 )
F_28 ( L_24 ) ;
return V_8 ;
}
* V_70 = & V_106 -> V_110 ;
return 0 ;
}
int F_51 ( struct V_75 * V_111 ,
struct V_9 * V_10 ,
struct V_112 * args )
{
int V_8 ;
struct V_73 * V_113 ;
T_4 V_114 ;
args -> V_115 = args -> V_116 * ( ( args -> V_117 + 7 ) / 8 ) ;
args -> V_103 = args -> V_115 * args -> V_118 ;
V_8 = F_48 ( V_10 , args -> V_103 , false ,
& V_113 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_52 ( V_111 , V_113 , & V_114 ) ;
F_23 ( V_113 ) ;
if ( V_8 )
return V_8 ;
args -> V_114 = V_114 ;
return 0 ;
}
static void F_53 ( struct V_105 * * V_119 )
{
struct V_120 * V_121 ;
if ( ( * V_119 ) == NULL )
return;
V_121 = & ( ( * V_119 ) -> V_119 ) ;
F_54 ( & V_121 ) ;
* V_119 = NULL ;
}
void F_55 ( struct V_73 * V_70 )
{
struct V_105 * V_105 = F_56 ( V_70 ) ;
F_53 ( & V_105 ) ;
}
static inline T_5 F_57 ( struct V_105 * V_119 )
{
return F_58 ( & V_119 -> V_119 . V_122 ) ;
}
int
F_59 ( struct V_75 * V_111 ,
struct V_9 * V_10 ,
T_1 V_114 ,
T_6 * V_123 )
{
struct V_73 * V_70 ;
struct V_105 * V_119 ;
V_70 = F_30 ( V_111 , V_114 ) ;
if ( V_70 == NULL )
return - V_78 ;
V_119 = F_56 ( V_70 ) ;
* V_123 = F_57 ( V_119 ) ;
F_23 ( V_70 ) ;
return 0 ;
}
