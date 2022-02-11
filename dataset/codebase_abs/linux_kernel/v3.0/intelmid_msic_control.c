static int F_1 ( void )
{
struct V_1 V_2 [] = {
{ 0x241 , 0x85 , 0 } ,
{ 0x242 , 0x02 , 0 } ,
{ 0x24C , 0x10 , 0 } ,
{ 0x24D , 0x32 , 0 } ,
{ 0x272 , 0x10 , 0 } ,
{ 0x273 , 0x32 , 0 } ,
{ 0x274 , 0xFF , 0 } ,
{ 0x275 , 0x10 , 0 } ,
{ 0x276 , 0x32 , 0 } ,
{ 0x277 , 0x54 , 0 } ,
{ 0x24E , 0x28 , 0 } ,
{ 0x384 , 0x80 , 0 } ,
{ 0x385 , 0x80 , 0 } ,
{ 0x267 , 0x00 , 0 } ,
{ 0x261 , 0x00 , 0 } ,
{ 0x278 , 0x00 , 0 } ,
{ 0x27B , 0x01 , 0 } ,
{ 0x27C , 0x0a , 0 } ,
{ 0x259 , 0x08 , 0 } ,
{ 0x25A , 0x08 , 0 } ,
{ 0x25B , 0x08 , 0 } ,
{ 0x25C , 0x08 , 0 } ,
{ 0x250 , 0x30 , 0 } ,
{ 0x256 , 0x11 , 0 } ,
{ 0x249 , 0x01 , 0x0 } ,
{ 0x24A , 0x01 , 0x0 } ,
{ 0x1d , 0x00 , 0x00 } ,
{ 0x1e , 0x00 , 0x00 } ,
} ;
V_3 . V_4 = V_5 ;
F_2 ( V_2 , V_6 , 28 ) ;
V_3 . V_7 = 0 ;
V_3 . V_8 = 0 ;
V_3 . V_9 = 0 ;
V_3 . V_10 = V_11 ;
V_3 . V_12 = V_13 ;
V_3 . V_14 = false ;
F_3 ( L_1 ) ;
return 0 ;
}
static int F_4 ( T_1 V_15 )
{
struct V_1 V_16 [] = {
{ 0x25d , 0x03 , 0x03 } ,
} ;
struct V_1 V_17 [] = {
{ 0x25d , 0x40 , 0x40 } ,
} ;
struct V_1 V_18 [] = {
{ 0x25d , 0x0c , 0x0c } ,
} ;
struct V_1 V_19 [] = {
{ 0x25d , 0x10 , 0x10 } ,
} ;
struct V_1 V_20 [] = {
{ 0x25d , 0x20 , 0x20 } ,
} ;
struct V_1 V_21 [] = {
{ 0x381 , 0x10 , 0x10 } ,
} ;
int V_22 = 0 ;
F_3 ( L_2 , V_15 ) ;
switch ( V_15 ) {
case V_23 :
F_3 ( L_3 ) ;
if ( V_3 . V_12 == V_13 )
V_22 = F_2 ( V_16 ,
V_24 , 1 ) ;
else
V_22 = F_2 ( V_17 ,
V_24 , 1 ) ;
break;
case V_25 :
F_3 ( L_4 ) ;
V_22 = F_2 ( V_18 , V_24 , 1 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_2 ( V_21 , V_24 , 1 ) ;
break;
case V_26 :
F_3 ( L_5 ) ;
V_22 = F_2 ( V_19 , V_24 , 1 ) ;
break;
case V_27 :
F_3 ( L_6 ) ;
V_22 = F_2 ( V_20 , V_24 , 1 ) ;
break;
case V_28 :
F_3 ( L_7 ) ;
break;
default:
return - V_29 ;
}
return V_22 ;
}
static int F_5 ( void )
{
struct V_1 V_30 [ 2 ] = {
{ 0x257 , 0x0 , 0x0 } ,
{ 0x25d , 0x0 , 0x0 } ,
} ;
struct V_1 V_31 [ 2 ] = {
{ 0x264 , 0x0 , 0x0 } ,
{ 0x25D , 0x0 , 0x0 } ,
} ;
struct V_1 V_32 [ 2 ] = {
{ 0x26A , 0x0 , 0x0 } ,
{ 0x25D , 0x0 , 0x0 } ,
} ;
int V_22 = 0 , V_33 , V_34 , V_35 , V_36 ;
for ( V_35 = 0 ; V_35 < V_3 . V_37 ; V_35 ++ ) {
switch ( V_35 ) {
case V_23 :
F_3 ( L_8 ) ;
F_2 ( V_30 , V_38 , 2 ) ;
V_36 = ( V_39 | V_40 ) ;
V_34 = ( V_30 [ 0 ] . V_15 ) & V_36 ;
V_36 = ( ( V_39 | V_40 ) | V_41 ) ;
V_33 = ( V_30 [ 1 ] . V_15 ) & V_36 ;
if ( V_34 && ( ! V_33 ) ) {
V_3 . V_42 = V_23 ;
return V_22 ;
}
break;
case V_25 :
F_3 ( L_9 ) ;
F_2 ( V_30 , V_38 , 2 ) ;
V_36 = ( V_43 | V_44 ) ;
V_34 = ( V_30 [ 0 ] . V_15 ) & V_36 ;
V_36 = ( V_43 | V_44 ) ;
V_33 = ( V_30 [ 1 ] . V_15 ) & V_36 ;
if ( V_34 && ( ! V_33 ) ) {
V_3 . V_42 = V_25 ;
return V_22 ;
}
break;
case V_26 :
F_3 ( L_10 ) ;
F_2 ( V_31 , V_38 , 2 ) ;
V_36 = V_40 ;
V_34 = ( V_31 [ 0 ] . V_15 ) & V_36 ;
V_36 = V_45 ;
V_33 = ( V_31 [ 1 ] . V_15 ) & V_36 ;
if ( V_34 && ( ! V_33 ) ) {
V_3 . V_42 = V_26 ;
return V_22 ;
}
break;
case V_27 :
F_3 ( L_11 ) ;
F_2 ( V_32 , V_38 , 2 ) ;
V_36 = V_40 ;
V_34 = ( V_32 [ 0 ] . V_15 ) & V_36 ;
V_36 = V_46 ;
V_33 = ( ( V_32 [ 1 ] . V_15 ) & V_36 ) ;
if ( V_34 && ( ! V_33 ) ) {
V_3 . V_42 = V_27 ;
return V_22 ;
}
break;
case V_28 :
F_3 ( L_12 ) ;
V_3 . V_42 = V_28 ;
return V_22 ;
default:
F_3 ( L_13 ) ;
V_3 . V_42 = V_28 ;
return - V_29 ;
}
}
return V_22 ;
}
static int F_6 ( T_1 V_15 )
{
struct V_1 V_47 [] = {
{ 0x25e , 0x33 , 0xFF } ,
{ 0x25d , 0x0 , 0x43 } ,
} ;
struct V_1 V_48 [] = {
{ 0x25e , 0x55 , 0xff } ,
{ 0x25d , 0x0 , 0x0c } ,
} ;
struct V_1 V_49 [] = {
{ 0x25e , 0x61 , 0xff } ,
{ 0x25d , 0x0 , 0x10 } ,
} ;
struct V_1 V_50 [] = {
{ 0x25e , 0x16 , 0xff } ,
{ 0x25d , 0x0 , 0x20 } ,
} ;
struct V_1 V_51 [] = {
{ 0x25e , 0x66 , 0x0 } ,
} ;
struct V_1 V_52 [] = {
{ 0x381 , 0x00 , 0x10 } ,
} ;
struct V_1 V_21 [] = {
{ 0x381 , 0x10 , 0x10 } ,
} ;
int V_22 = 0 ;
F_3 ( L_14 , V_15 ) ;
F_5 () ;
F_4 ( V_3 . V_42 ) ;
V_3 . V_53 = V_15 ;
switch ( V_15 ) {
case V_23 :
F_3 ( L_15 ) ;
if ( V_3 . V_7 )
V_22 = F_2 ( V_47 ,
V_24 , 2 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_2 ( V_52 ,
V_24 , 1 ) ;
break;
case V_25 :
F_3 ( L_16 ) ;
if ( V_3 . V_7 )
V_22 = F_2 ( V_48 ,
V_24 , 2 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_2 ( V_21 ,
V_24 , 1 ) ;
break;
case V_26 :
F_3 ( L_17 ) ;
if ( V_3 . V_7 )
V_22 = F_2 ( V_49 ,
V_24 , 2 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_2 ( V_52 ,
V_24 , 1 ) ;
break;
case V_27 :
F_3 ( L_18 ) ;
if ( V_3 . V_7 )
V_22 = F_2 ( V_50 ,
V_24 , 2 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_2 ( V_52 ,
V_24 , 1 ) ;
break;
case V_28 :
F_3 ( L_19 ) ;
V_22 = F_2 ( V_51 ,
V_6 , 1 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_2 ( V_52 ,
V_24 , 1 ) ;
break;
default:
return - V_29 ;
}
return V_22 ;
}
static int F_7 ( unsigned int V_54 )
{
struct V_1 V_55 [] = {
{ 0x0DB , 0x07 , 0 } ,
} ;
struct V_1 V_56 [] = {
{ 0x240 , 0x20 , 0 } ,
} ;
struct V_1 V_57 [] = {
{ 0x0DC , 0x3D , 0 } ,
{ 0x0DD , 0x3F , 0 } ,
} ;
struct V_1 V_58 [] = {
{ 0x382 , 0x40 , 0x40 } ,
{ 0x25D , 0x0 , 0x43 } ,
{ 0x257 , 0x03 , 0x03 } ,
} ;
struct V_1 V_59 [] = {
{ 0x250 , 0x30 , 0 } ,
{ 0x256 , 0x11 , 0 } ,
} ;
struct V_1 V_60 [] = {
{ 0x25D , 0x3 , 0x3 } ,
{ 0x26C , 0x0 , 0x2 } ,
{ 0x259 , 0x80 , 0x80 } ,
{ 0x25A , 0x80 , 0x80 } ,
} ;
struct V_1 V_61 [] = {
{ 0x0C9 , 0x27 , 0x00 } ,
} ;
struct V_1 V_62 [] = {
{ 0x25D , 0x00 , 0x0C } ,
{ 0x251 , 0x03 , 0x03 } ,
{ 0x257 , 0x0C , 0x0C } ,
} ;
struct V_1 V_63 [] = {
{ 0x25D , 0x0C , 0x0c } ,
} ;
struct V_1 V_64 [] = {
{ 0x25B , 0x80 , 0x80 } ,
{ 0x25C , 0x80 , 0x80 } ,
} ;
struct V_1 V_65 [] = {
{ 0x25D , 0x0 , 0x43 } ,
{ 0x257 , 0x03 , 0x03 } ,
} ;
struct V_1 V_66 [] = {
{ 0x25D , 0x40 , 0x40 } ,
{ 0x259 , 0x80 , 0x80 } ,
{ 0x25A , 0x80 , 0x80 } ,
} ;
struct V_1 V_67 [] = {
{ 0x25D , 0x10 , 0x10 } ,
{ 0x264 , 0x02 , 0x82 } ,
} ;
struct V_1 V_68 [] = {
{ 0x25D , 0x20 , 0x20 } ,
{ 0x26A , 0x02 , 0x82 } ,
} ;
struct V_1 V_69 [] = {
{ 0x27C , 0x1 , 0x1 } ,
} ;
int V_22 = 0 ;
if ( V_3 . V_4 == V_70 ) {
V_22 = F_1 () ;
if ( V_22 )
return V_22 ;
}
F_3 ( L_20 , V_54 ) ;
F_2 ( V_55 , V_6 , 1 ) ;
F_8 ( 1 ) ;
F_2 ( V_56 , V_6 , 1 ) ;
F_8 ( 1 ) ;
switch ( V_54 ) {
case V_71 :
V_3 . V_7 = 1 ;
V_3 . V_8 = 1 ;
if ( V_3 . V_12 == V_13 ) {
F_2 ( V_57 , V_6 , 2 ) ;
F_2 ( V_58 , V_24 , 3 ) ;
F_2 ( V_59 , V_6 , 2 ) ;
F_2 ( V_60 , V_24 , 4 ) ;
} else {
F_2 ( V_65 , V_24 , 2 ) ;
F_2 ( V_59 , V_6 , 2 ) ;
F_2 ( V_66 , V_24 , 3 ) ;
}
if ( V_3 . V_53 == V_23 )
F_6 ( V_23 ) ;
break;
case V_72 :
V_3 . V_7 = 1 ;
F_2 ( V_61 , V_6 , 1 ) ;
F_2 ( V_62 , V_24 , 3 ) ;
F_2 ( V_63 , V_24 , 1 ) ;
F_2 ( V_64 , V_24 , 2 ) ;
if ( V_3 . V_53 == V_25 )
F_6 ( V_25 ) ;
break;
case V_73 :
V_3 . V_7 = 1 ;
F_2 ( V_67 , V_24 , 2 ) ;
if ( V_3 . V_53 == V_26 )
F_6 ( V_26 ) ;
break;
case V_74 :
V_3 . V_7 = 1 ;
F_2 ( V_68 , V_24 , 2 ) ;
if ( V_3 . V_53 == V_27 )
F_6 ( V_27 ) ;
break;
default:
F_9 ( L_21 ,
V_54 , V_3 . V_12 ) ;
}
return F_2 ( V_69 , V_24 , 1 ) ;
}
static int F_10 ( unsigned int V_54 )
{
struct V_1 V_55 [] = {
{ 0x0DB , 0x07 , 0 } ,
} ;
struct V_1 V_56 [] = {
{ 0x240 , 0x20 , 0 } ,
} ;
struct V_1 V_75 [] = {
{ 0x247 , 0xA0 , 0xA0 } ,
} ;
struct V_1 V_76 [] = {
{ 0x245 , 0x3F , 0x3F } ,
{ 0x246 , 0x07 , 0x07 } ,
} ;
struct V_1 V_77 [] = {
{ 0x247 , 0xFC , 0xFC } ,
} ;
struct V_1 V_78 [] = {
{ 0x249 , 0x01 , 0x01 } ,
{ 0x24A , 0x01 , 0x01 } ,
{ 0x248 , 0x05 , 0x0F } ,
} ;
struct V_1 V_79 [] = {
{ 0x27C , 0x1 , 0x1 } ,
} ;
struct V_1 V_80 [] = {
{ 0x24F , 0x3C , 0x0 } ,
} ;
int V_22 = 0 ;
if ( V_3 . V_4 == V_70 ) {
V_22 = F_1 () ;
if ( V_22 )
return V_22 ;
}
F_3 ( L_22 , V_3 . V_10 ) ;
F_2 ( V_55 , V_6 , 1 ) ;
F_8 ( 500 ) ;
F_2 ( V_56 , V_6 , 1 ) ;
F_8 ( 1 ) ;
V_3 . V_9 = 1 ;
if ( V_3 . V_10 == V_81 ) {
F_2 ( V_77 , V_24 , 1 ) ;
F_8 ( 1 ) ;
F_2 ( V_78 , V_24 , 3 ) ;
} else {
F_2 ( V_75 , V_24 , 1 ) ;
F_8 ( 1 ) ;
F_2 ( V_76 , V_24 , 2 ) ;
}
F_8 ( 1 ) ;
F_2 ( V_80 , V_6 , 1 ) ;
return F_2 ( V_79 , V_24 , 1 ) ;
}
static int F_11 ( void )
{
struct V_1 V_82 [] = {
{ 0x0DC , 0xC4 , 0 } ,
{ 0x0DD , 0x04 , 0 } ,
{ 0x0C9 , 0x24 , 0 } ,
} ;
struct V_1 V_56 [] = {
{ 0x240 , 0x00 , 0x0 } ,
} ;
struct V_1 V_55 [] = {
{ 0x0DB , 0x04 , 0 } ,
} ;
F_3 ( L_23 ) ;
V_3 . V_8 = 0 ;
V_3 . V_7 = 0 ;
V_3 . V_9 = 0 ;
F_2 ( V_82 , V_6 , 3 ) ;
F_8 ( 1 ) ;
F_2 ( V_56 , V_6 , 1 ) ;
F_8 ( 1 ) ;
F_2 ( V_55 , V_6 , 1 ) ;
return 0 ;
}
static int F_12 ( unsigned int V_54 )
{
struct V_1 V_83 [] = {
{ 0x25D , 0x00 , 0x00 } ,
} ;
struct V_1 V_84 [] = {
{ 0x259 , 0x80 , 0x80 } ,
{ 0x25A , 0x80 , 0x80 } ,
{ 0x26C , 0x02 , 0x02 } ,
} ;
struct V_1 V_85 [] = {
{ 0x257 , 0x00 , 0x03 } ,
{ 0x250 , 0x00 , 0x30 } ,
{ 0x382 , 0x00 , 0x40 } ,
} ;
struct V_1 V_86 [] = {
{ 0x25B , 0x80 , 0x80 } ,
{ 0x25C , 0x80 , 0x80 } ,
} ;
struct V_1 V_87 [] = {
{ 0x257 , 0x00 , 0x0C } ,
{ 0x251 , 0x00 , 0x03 } ,
} ;
struct V_1 V_88 [] = {
{ 0x264 , 0x00 , 0x82 } ,
} ;
struct V_1 V_89 [] = {
{ 0x26A , 0x00 , 0x82 } ,
} ;
struct V_1 V_90 [] = {
{ 0x25e , 0x66 , 0x00 } ,
} ;
struct V_1 V_52 [] = {
{ 0x381 , 0x00 , 0x10 } ,
} ;
F_3 ( L_24 , V_54 ) ;
switch ( V_54 ) {
case V_71 :
V_3 . V_8 = 0 ;
F_2 ( V_84 , V_24 , 3 ) ;
V_83 [ 0 ] . V_36 = 0x43 ;
F_2 ( V_83 , V_24 , 1 ) ;
F_2 ( V_85 , V_24 , 3 ) ;
if ( V_3 . V_53 == V_23 )
F_2 ( V_90 , V_6 , 1 ) ;
break;
case V_72 :
F_2 ( V_86 , V_24 , 2 ) ;
V_83 [ 0 ] . V_36 = 0x0C ;
F_2 ( V_83 , V_24 , 1 ) ;
F_2 ( V_87 , V_24 , 2 ) ;
if ( V_3 . V_53 == V_25 ) {
F_2 ( V_90 , V_6 , 1 ) ;
F_2 ( V_52 , V_24 , 1 ) ;
}
break;
case V_73 :
F_2 ( V_88 , V_24 , 1 ) ;
V_83 [ 0 ] . V_36 = 0x10 ;
F_2 ( V_83 , V_24 , 1 ) ;
if ( V_3 . V_53 == V_26 )
F_2 ( V_90 , V_6 , 1 ) ;
break;
case V_74 :
F_2 ( V_89 , V_24 , 1 ) ;
V_83 [ 0 ] . V_36 = 0x20 ;
F_2 ( V_83 , V_24 , 1 ) ;
if ( V_3 . V_53 == V_27 )
F_2 ( V_90 , V_6 , 1 ) ;
break;
}
return 0 ;
}
static int F_13 ( unsigned int V_54 )
{
struct V_1 V_76 [] = {
{ 0x247 , 0x00 , 0xA0 } ,
{ 0x245 , 0x00 , 0x38 } ,
{ 0x246 , 0x00 , 0x07 } ,
} ;
struct V_1 V_78 [] = {
{ 0x248 , 0x00 , 0x05 } ,
{ 0x249 , 0x00 , 0x01 } ,
{ 0x24A , 0x00 , 0x01 } ,
{ 0x247 , 0x00 , 0xA3 } ,
} ;
struct V_1 V_91 [] = {
{ 0x24F , 0x00 , 0x3C } ,
} ;
F_3 ( L_25 ) ;
V_3 . V_9 = 0 ;
F_2 ( V_91 , V_24 , 1 ) ;
if ( V_3 . V_10 == V_11 )
F_2 ( V_76 , V_24 , 3 ) ;
else
F_2 ( V_78 , V_24 , 4 ) ;
return 0 ;
}
static int F_14 ( T_1 V_15 )
{
int V_22 = 0 ;
F_3 ( L_26 , V_15 ) ;
V_3 . V_12 = V_15 ;
if ( V_3 . V_8 )
F_7 ( V_71 ) ;
return V_22 ;
}
static int F_15 ( T_1 V_15 )
{
struct V_1 V_92 [] = {
{ 0x24C , 0x10 , 0x0 } ,
} ;
struct V_1 V_93 [] = {
{ 0x24C , 0x76 , 0x0 } ,
} ;
int V_22 = 0 ;
F_3 ( L_27 , V_15 ) ;
V_3 . V_10 = V_15 ;
switch ( V_15 ) {
case V_81 :
F_3 ( L_28 ) ;
V_22 = F_2 ( V_93 , V_6 , 1 ) ;
break;
case V_11 :
F_3 ( L_29 ) ;
V_22 = F_2 ( V_92 , V_6 , 1 ) ;
break;
default:
return - V_29 ;
}
if ( V_3 . V_9 )
V_22 = F_10 ( V_94 ) ;
return V_22 ;
}
static int F_16 ( T_1 V_95 )
{
struct V_1 V_96 ;
int V_22 = - V_29 ;
switch ( V_95 ) {
case V_97 :
V_96 . V_98 = V_99 ;
V_96 . V_15 = V_3 . V_100 [ 0 ] ;
V_96 . V_36 = ( V_43 | V_40 | V_39 ) ;
F_3 ( L_30 ,
V_96 . V_15 ) ;
V_22 = F_2 ( & V_96 ,
V_24 , 1 ) ;
break;
case V_101 :
V_96 . V_98 = V_99 ;
V_96 . V_15 = ( V_3 . V_100 [ 1 ] ) << 4 ;
V_96 . V_36 = ( V_41 | V_46 | V_45 ) ;
F_3 ( L_31 ,
V_96 . V_15 ) ;
V_22 = F_2 ( & V_96 ,
V_24 , 1 ) ;
break;
case V_102 :
V_96 . V_98 = V_103 ;
V_96 . V_15 = V_3 . V_100 [ 2 ] ;
V_96 . V_36 = ( V_43 | V_40 | V_39 ) ;
F_3 ( L_32 ,
V_96 . V_15 ) ;
V_22 = F_2 ( & V_96 ,
V_24 , 1 ) ;
break;
case V_104 :
V_96 . V_98 = V_103 ;
V_96 . V_15 = ( V_3 . V_100 [ 3 ] ) << 4 ;
V_96 . V_36 = ( V_41 | V_46 | V_45 ) ;
F_3 ( L_33 ,
V_96 . V_15 ) ;
V_22 = F_2 ( & V_96 ,
V_24 , 1 ) ;
break;
}
return V_22 ;
}
static int F_17 ( void )
{
return 0 ;
}
static int F_18 ( int V_105 , int V_106 , int V_107 )
{
return 0 ;
}
static int F_19 ( int V_108 )
{
return 0 ;
}
static int F_20 ( int V_108 )
{
return 0 ;
}
static int F_21 ( int V_35 , T_1 V_15 )
{
return 0 ;
}
static int F_22 ( int V_35 , int V_15 )
{
return 0 ;
}
static int F_23 ( int V_35 , T_1 * V_15 )
{
return 0 ;
}
static int F_24 ( int V_35 , int * V_15 )
{
return 0 ;
}
static int F_25 ( int V_109 )
{
struct V_1 V_60 [] = {
{ 0x25D , 0x03 , 0x03 } ,
} ;
if ( V_109 )
F_2 ( V_60 , V_24 , 1 ) ;
else {
V_60 [ 0 ] . V_15 = 0 ;
F_2 ( V_60 , V_24 , 1 ) ;
}
return 0 ;
}
static int F_26 ( void )
{
struct V_1 V_110 [] = {
{ 0x0DB , 0x07 , 0x00 } ,
} ;
struct V_1 V_111 [] = {
{ 0x247 , 0x0C , 0x0C } ,
} ;
F_2 ( V_110 , V_6 , 1 ) ;
F_2 ( V_111 , V_24 , 1 ) ;
return 0 ;
}
static int F_27 ( void )
{
if ( V_3 . V_14 == true )
return 0 ;
if ( ! ( V_3 . V_7 || V_3 . V_9 ) )
F_11 () ;
return 0 ;
}
static int F_28 ( void )
{
struct V_1 V_112 [] = {
{ 0x26C , 0x00 , 0x01 }
} ;
if ( ! ( V_3 . V_7 || V_3 . V_9 ) )
F_11 () ;
V_3 . V_14 = false ;
return F_2 ( V_112 , V_24 , 1 ) ;
}
static int F_29 ( void )
{
struct V_1 V_113 [] = {
{ 0x26b , 0x77 , 0x00 } ,
{ 0x26C , 0x01 , 0x00 } ,
} ;
return F_2 ( V_113 , V_6 , 2 ) ;
}
static int F_30 ( unsigned int V_114 )
{
return ( V_115 * V_114 ) / 1000 ;
}
int F_31 ( int V_114 )
{
struct V_1 V_116 [] = {
{ 0x070 , 0x00 , 0x01 } ,
} ;
if ( V_114 >= 0 && V_114 < 400 ) {
F_3 ( L_34 ) ;
F_2 ( V_116 , V_24 , 1 ) ;
} else if ( V_114 > 400 && V_114 < 650 ) {
F_3 ( L_35 ) ;
V_116 [ 0 ] . V_15 = 0x01 ;
F_2 ( V_116 , V_24 , 1 ) ;
} else if ( V_114 >= 650 && V_114 < 2000 ) {
F_3 ( L_36 ) ;
F_2 ( V_116 , V_24 , 1 ) ;
V_3 . V_14 = true ;
F_29 () ;
F_26 () ;
return V_117 ;
} else
F_3 ( L_37 ) ;
return V_118 ;
}
static int F_32 ( void * V_119 )
{
struct V_120 * V_121 = (struct V_120 * ) V_119 ;
T_2 V_122 = V_121 -> V_123 ;
T_2 V_124 ;
int V_125 ;
struct V_1 V_126 [ 2 ] = {
{ 0x1C2 , 0x05 , 0x0 } ,
} ;
struct V_1 V_127 = { 0 ,} ;
struct V_1 V_128 = { 0 ,} ;
F_26 () ;
V_125 = F_2 ( V_126 , V_6 , 1 ) ;
if ( V_125 )
return V_125 ;
V_126 [ 0 ] . V_15 = 0x04 ;
V_125 = F_2 ( V_126 , V_6 , 1 ) ;
if ( V_125 )
return V_125 ;
V_127 . V_98 = V_122 ;
F_8 ( 1000 ) ;
V_125 = F_2 ( & V_127 , V_38 , 1 ) ;
if ( V_125 )
return V_125 ;
F_3 ( L_38 , V_127 . V_15 ) ;
V_124 = ( V_127 . V_15 << 2 ) ;
V_122 ++ ;
V_128 . V_98 = V_122 ;
V_125 = F_2 ( & V_128 , V_38 , 1 ) ;
if ( V_125 )
return V_125 ;
F_3 ( L_38 , V_128 . V_15 ) ;
V_128 . V_15 &= 03 ;
V_124 += V_128 . V_15 ;
F_3 ( L_39 , V_124 ) ;
F_27 () ;
return V_124 ;
}
static void F_33 ( void * V_129 , T_1 V_130 )
{
struct V_131 * V_132 = NULL ;
unsigned int V_133 = 0 , V_134 = 0 , V_135 = 0 ;
struct V_120 * V_136 = V_129 ;
int V_22 = 0 ;
F_3 ( L_40 , V_130 ) ;
if ( V_3 . V_4 == V_70 ) {
V_22 = F_1 () ;
if ( V_22 )
return;
}
V_132 = & V_136 -> V_137 [ 0 ] ;
if ( V_130 & 0x1 ) {
F_3 ( L_41 ) ;
V_133 = V_138 ;
V_134 = V_135 = 1 ;
V_132 -> V_137 . type = V_138 ;
V_132 -> V_137 . V_139 [ 0 ] = V_140 ;
}
if ( V_130 & 0x2 ) {
F_3 ( L_42 ) ;
V_134 = V_135 = 1 ;
V_132 -> V_137 . type = V_133 = V_141 ;
V_132 -> V_137 . V_139 [ 1 ] = V_142 ;
}
if ( V_130 & 0x4 ) {
unsigned int V_114 ;
V_134 = 1 ;
V_135 = 0 ;
V_114 = F_32 ( V_136 ) ;
F_3 ( L_43 , V_114 ) ;
V_114 = F_30 ( V_114 ) ;
F_3 ( L_44 , V_114 ) ;
V_132 -> V_143 = F_31 ( V_114 ) ;
V_132 -> V_137 . type = V_133 = V_132 -> V_143 ;
}
if ( V_130 & 0x8 ) {
V_132 -> V_137 . type = V_132 -> V_143 ;
V_133 = 0 ;
V_134 = 1 ;
V_135 = 0 ;
F_28 () ;
F_27 () ;
}
if ( V_134 )
F_34 ( & V_132 -> V_137 ,
V_135 , V_133 ) ;
}
