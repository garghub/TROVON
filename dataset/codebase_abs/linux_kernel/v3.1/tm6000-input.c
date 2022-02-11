void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_2 -> V_5 )
return;
if ( V_3 )
V_5 -> V_6 = 1 ;
else
V_5 -> V_6 = 0 ;
}
static int F_2 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
T_1 V_7 [ 10 ] ;
int V_8 ;
switch ( V_5 -> V_9 ) {
case V_10 :
F_3 ( V_2 , V_11 , 0xaa ) ;
F_3 ( V_2 , V_12 , 0x30 ) ;
F_3 ( V_2 , V_13 , 0x20 ) ;
F_3 ( V_2 , V_14 , 0xd0 ) ;
F_3 ( V_2 , V_15 , 0xfe ) ;
F_3 ( V_2 , V_16 , 0xff ) ;
F_3 ( V_2 , V_17 , 0xff ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( 100 ) ;
F_4 ( V_2 , 1 ) ;
break;
default:
V_7 [ 0 ] = 0xff ;
V_7 [ 1 ] = 0xff ;
V_7 [ 2 ] = 0xf2 ;
V_7 [ 3 ] = 0x2b ;
V_7 [ 4 ] = 0x20 ;
V_7 [ 5 ] = 0x35 ;
V_7 [ 6 ] = 0x60 ;
V_7 [ 7 ] = 0x04 ;
V_7 [ 8 ] = 0xc0 ;
V_7 [ 9 ] = 0x08 ;
V_8 = F_6 ( V_2 , V_18 | V_19 |
V_20 , V_21 , 0 , 0 , V_7 , 0x0a ) ;
F_5 ( 100 ) ;
if ( V_8 < 0 ) {
F_7 ( V_22 L_1 ) ;
return V_8 ;
}
break;
}
return 0 ;
}
static void F_8 ( struct V_23 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_8 ;
if ( V_23 -> V_25 != 0 )
F_7 ( V_22 L_2 ) ;
else if ( V_23 -> V_26 > 0 ) {
memcpy ( V_5 -> V_27 , V_23 -> V_28 , V_23 -> V_26 ) ;
F_9 ( L_3 , V_5 -> V_27 [ 0 ] ,
V_5 -> V_27 [ 1 ] , V_5 -> V_27 [ 2 ] , V_5 -> V_27 [ 3 ] ) ;
V_5 -> V_29 = 1 ;
}
V_8 = F_10 ( V_23 , V_30 ) ;
}
static int F_11 ( struct V_4 * V_5 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
int V_8 ;
T_1 V_7 [ 2 ] ;
if ( V_5 -> V_6 && ! & V_2 -> V_33 )
return 0 ;
if ( & V_2 -> V_33 ) {
switch ( V_5 -> V_9 ) {
case V_34 :
V_32 -> V_35 = V_5 -> V_27 [ 0 ] ;
break;
case V_10 :
if ( V_5 -> V_27 [ 1 ] == ( ( V_5 -> V_36 >> 8 ) & 0xff ) ) {
V_32 -> V_35 = V_5 -> V_27 [ 0 ]
| V_5 -> V_27 [ 1 ] << 8 ;
}
break;
default:
V_32 -> V_35 = V_5 -> V_27 [ 0 ]
| V_5 -> V_27 [ 1 ] << 8 ;
break;
}
} else {
F_3 ( V_2 , V_37 , 2 , 0 ) ;
F_5 ( 10 ) ;
F_3 ( V_2 , V_37 , 2 , 1 ) ;
F_5 ( 10 ) ;
if ( V_5 -> V_9 == V_34 ) {
V_8 = F_6 ( V_2 , V_38 |
V_19 | V_20 ,
V_39 , 0 , 0 , V_7 , 1 ) ;
F_5 ( 10 ) ;
F_9 ( L_4 , V_7 [ 0 ] ) ;
if ( V_8 < 0 )
return V_8 ;
V_32 -> V_35 = V_7 [ 0 ] ;
} else {
V_8 = F_6 ( V_2 , V_38 |
V_19 | V_20 ,
V_39 , 0 , 0 , V_7 , 2 ) ;
F_5 ( 10 ) ;
F_9 ( L_5 , V_7 [ 0 ] | V_7 [ 1 ] << 8 ) ;
if ( V_8 < 0 )
return V_8 ;
V_32 -> V_35 = V_7 [ 0 ] | V_7 [ 1 ] << 8 ;
}
if ( ( V_32 -> V_35 & 0x00ff ) != 0xff )
V_5 -> V_29 = 1 ;
}
return 0 ;
}
static void F_12 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
int V_40 ;
struct V_31 V_32 ;
V_40 = V_5 -> V_41 ( V_5 , & V_32 ) ;
if ( V_40 < 0 ) {
F_7 ( V_22 L_6 , V_40 ) ;
return;
}
F_9 ( L_7 , V_32 . V_35 ) ;
if ( V_5 -> V_42 ) {
if ( V_5 -> V_43 >= V_44 ) {
V_5 -> V_42 = 0 ;
V_5 -> V_43 = 0 ;
F_4 ( V_2 , 1 ) ;
} else
V_5 -> V_43 += 1 ;
}
if ( V_5 -> V_29 ) {
F_13 ( V_5 -> V_8 , V_32 . V_35 , 0 ) ;
V_5 -> V_29 = 0 ;
V_5 -> V_42 = 1 ;
V_5 -> V_43 = 0 ;
F_4 ( V_2 , 0 ) ;
}
return;
}
static void F_14 ( struct V_45 * V_46 )
{
struct V_4 * V_5 = F_15 ( V_46 , struct V_4 , V_46 . V_46 ) ;
F_12 ( V_5 ) ;
F_16 ( & V_5 -> V_46 , F_17 ( V_5 -> V_47 ) ) ;
}
static int F_18 ( struct V_48 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_49 ;
F_19 ( & V_5 -> V_46 , F_14 ) ;
F_16 ( & V_5 -> V_46 , 0 ) ;
return 0 ;
}
static void F_20 ( struct V_48 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_49 ;
F_21 ( & V_5 -> V_46 ) ;
}
int F_22 ( struct V_48 * V_8 , T_2 V_9 )
{
struct V_4 * V_5 = V_8 -> V_49 ;
if ( ! V_5 )
return 0 ;
if ( ( V_8 -> V_50 . V_51 ) && ( V_9 == V_10 ) )
V_5 -> V_36 = ( ( V_8 -> V_50 . V_51 [ 0 ] . V_52 >> 8 ) & 0xffff ) ;
V_5 -> V_41 = F_11 ;
V_5 -> V_9 = V_9 ;
F_2 ( V_5 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_53 , V_54 ;
int V_55 = - V_56 ;
if ( ! V_5 )
return - V_57 ;
V_5 -> V_58 = F_24 ( 0 , V_59 ) ;
if ( ! V_5 -> V_58 )
return - V_56 ;
V_53 = F_25 ( V_2 -> V_60 ,
V_2 -> V_33 . V_61 -> V_62 . V_63
& V_64 ) ;
V_54 = F_26 ( V_2 -> V_60 , V_53 , F_27 ( V_53 ) ) ;
F_9 ( L_8 , V_54 ) ;
V_5 -> V_58 -> V_28 = F_28 ( V_54 , V_59 ) ;
if ( V_5 -> V_58 -> V_28 == NULL ) {
F_29 ( V_5 -> V_58 ) ;
return V_55 ;
}
F_9 ( L_9 , V_2 -> V_33 . V_61 -> V_62 . V_65 ) ;
F_30 ( V_5 -> V_58 , V_2 -> V_60 , V_53 ,
V_5 -> V_58 -> V_28 , V_54 ,
F_8 , V_2 ,
V_2 -> V_33 . V_61 -> V_62 . V_65 ) ;
V_55 = F_10 ( V_5 -> V_58 , V_59 ) ;
if ( V_55 ) {
F_31 ( V_5 -> V_58 -> V_28 ) ;
F_29 ( V_5 -> V_58 ) ;
return V_55 ;
}
V_5 -> V_27 = F_28 ( V_54 , V_59 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_5 )
return;
F_33 ( V_5 -> V_58 ) ;
F_31 ( V_5 -> V_58 -> V_28 ) ;
F_29 ( V_5 -> V_58 ) ;
V_5 -> V_58 = NULL ;
F_31 ( V_5 -> V_27 ) ;
V_5 -> V_27 = NULL ;
}
int F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_48 * V_8 ;
int V_55 = - V_56 ;
if ( ! V_66 )
return - V_57 ;
if ( ! V_2 -> V_67 . V_68 )
return 0 ;
if ( ! V_2 -> V_69 )
return 0 ;
V_5 = F_28 ( sizeof( * V_5 ) , V_59 ) ;
V_8 = F_35 () ;
if ( ! V_5 || ! V_8 )
goto V_70;
V_5 -> V_2 = V_2 ;
V_2 -> V_5 = V_5 ;
V_5 -> V_8 = V_8 ;
V_8 -> V_71 = V_34 | V_10 ;
V_8 -> V_49 = V_5 ;
V_8 -> V_72 = F_22 ;
V_8 -> V_73 = F_18 ;
V_8 -> V_74 = F_20 ;
V_8 -> V_75 = V_76 ;
V_5 -> V_47 = 50 ;
V_5 -> V_42 = 0 ;
V_5 -> V_43 = 0 ;
snprintf ( V_5 -> V_77 , sizeof( V_5 -> V_77 ) , L_10 ,
V_2 -> V_77 ) ;
F_36 ( V_2 -> V_60 , V_5 -> V_78 , sizeof( V_5 -> V_78 ) ) ;
F_37 ( V_5 -> V_78 , L_11 , sizeof( V_5 -> V_78 ) ) ;
F_22 ( V_8 , V_79 ) ;
V_8 -> V_80 = V_5 -> V_77 ;
V_8 -> V_81 = V_5 -> V_78 ;
V_8 -> V_82 . V_83 = V_84 ;
V_8 -> V_82 . V_85 = 1 ;
V_8 -> V_82 . V_86 = F_38 ( V_2 -> V_60 -> V_87 . V_88 ) ;
V_8 -> V_82 . V_89 = F_38 ( V_2 -> V_60 -> V_87 . V_90 ) ;
V_8 -> V_91 = V_2 -> V_69 ;
V_8 -> V_92 = L_12 ;
V_8 -> V_2 . V_93 = & V_2 -> V_60 -> V_2 ;
if ( & V_2 -> V_33 ) {
F_9 ( L_13 ) ;
V_55 = F_23 ( V_2 ) ;
if ( V_55 )
goto V_70;
}
V_55 = F_39 ( V_8 ) ;
if ( V_55 )
goto V_70;
return 0 ;
V_70:
V_2 -> V_5 = NULL ;
F_40 ( V_8 ) ;
F_31 ( V_5 ) ;
return V_55 ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_5 )
return 0 ;
F_42 ( V_5 -> V_8 ) ;
if ( V_5 -> V_58 )
F_32 ( V_2 ) ;
F_31 ( V_5 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
