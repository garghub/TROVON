static int F_1 ( void )
{
struct V_1 V_2 [] = {
{ 0x180 , 0x00 , 0x0 } ,
{ 0x181 , 0x00 , 0x0 } ,
{ 0x182 , 0xF8 , 0x0 } ,
{ 0x183 , 0x08 , 0x0 } ,
{ 0x184 , 0x00 , 0x0 } ,
{ 0x185 , 0x40 , 0x0 } ,
{ 0x186 , 0x06 , 0x0 } ,
{ 0x187 , 0x80 , 0x0 } ,
{ 0x188 , 0x40 , 0x0 } ,
{ 0x189 , 0x39 , 0x0 } ,
{ 0x18a , 0x39 , 0x0 } ,
{ 0x18b , 0x1F , 0x0 } ,
{ 0x18c , 0x00 , 0x0 } ,
{ 0x18d , 0x00 , 0x0 } ,
{ 0x18e , 0x39 , 0x0 } ,
{ 0x18f , 0x39 , 0x0 } ,
{ 0x190 , 0x39 , 0x0 } ,
{ 0x191 , 0x11 , 0x0 } ,
{ 0x192 , 0x0E , 0x0 } ,
{ 0x193 , 0x00 , 0x0 } ,
{ 0x194 , 0x00 , 0x0 } ,
{ 0x195 , 0x00 , 0x0 } ,
{ 0x196 , 0x7C , 0x0 } ,
{ 0x197 , 0x00 , 0x0 } ,
{ 0x198 , 0x0B , 0x0 } ,
{ 0x199 , 0x00 , 0x0 } ,
{ 0x037 , 0x3F , 0x0 } ,
} ;
V_3 . V_4 = V_5 ;
V_3 . V_6 = V_7 ;
V_3 . V_8 = V_7 ;
V_3 . V_9 = 2 ;
return F_2 ( V_2 , V_10 , 27 ) ;
}
static int F_3 ( int V_11 )
{
struct V_1 V_2 [ 3 ] ;
V_2 [ 0 ] . V_12 = V_13 ;
V_2 [ 1 ] . V_12 = V_14 ;
V_2 [ 2 ] . V_12 = V_15 ;
V_2 [ 0 ] . V_16 = V_2 [ 1 ] . V_16 = V_2 [ 2 ] . V_16 = V_17 ;
if ( V_3 . V_8 == V_18 )
return 0 ;
if ( V_11 == V_18 ) {
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 =
V_2 [ 2 ] . V_11 = 0x80 ;
} else {
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 =
V_2 [ 2 ] . V_11 = 0x0 ;
}
if ( V_3 . V_9 == 1 )
V_2 [ 1 ] . V_11 = V_2 [ 2 ] . V_11 = 0x80 ;
return F_2 ( V_2 , V_19 , 3 ) ;
}
static int F_4 ( unsigned int V_20 )
{
struct V_1 V_2 [] = {
{ V_21 , 0x00 , V_17 } ,
{ V_22 , 0xC6 , 0xC6 } ,
{ V_23 , 0x30 , 0x30 } ,
} ;
int V_24 = 0 ;
if ( V_3 . V_4 == V_25 )
V_24 = F_1 () ;
if ( V_24 )
return V_24 ;
V_24 = F_3 ( V_18 ) ;
V_24 = F_2 ( V_2 , V_19 , 3 ) ;
if ( V_24 )
return V_24 ;
F_5 ( L_1 ) ;
return F_3 ( V_7 ) ;
}
static int F_6 ( unsigned int V_26 )
{
struct V_1 V_2 [] = {
{ V_22 , 0x00 , 0xC6 } ,
{ V_23 , 0x00 , 0x30 } ,
} ;
int V_24 = 0 ;
if ( V_3 . V_4 == V_25 )
V_24 = F_1 () ;
if ( V_24 )
return V_24 ;
V_24 = F_3 ( V_18 ) ;
V_24 = F_2 ( V_2 , V_19 , 2 ) ;
if ( V_24 )
return V_24 ;
F_5 ( L_2 ) ;
return F_3 ( V_7 ) ;
}
static int F_7 ( unsigned int V_20 )
{
struct V_1 V_2 [] = {
{ V_23 , 0x32 , 0x32 } ,
{ V_21 , 0x00 , V_17 } ,
} ;
int V_24 = 0 ;
if ( V_3 . V_4 == V_25 )
V_24 = F_1 () ;
if ( V_24 )
return V_24 ;
return F_2 ( V_2 , V_19 , 2 ) ;
}
static int F_8 ( unsigned int V_26 )
{
struct V_1 V_2 [] = {
{ V_23 , 0x00 , 0x03 } ,
} ;
int V_24 = 0 ;
if ( V_3 . V_4 == V_25 )
V_24 = F_1 () ;
if ( V_24 )
return V_24 ;
return F_2 ( V_2 , V_19 , 1 ) ;
}
static int F_9 ( void )
{
int V_24 = 0 ;
struct V_1 V_2 [] = {
{ V_21 , V_17 , V_17 } ,
} ;
if ( V_3 . V_4 == V_25 )
V_24 = F_1 () ;
if ( V_24 )
return V_24 ;
return F_2 ( V_2 , V_19 , 1 ) ;
}
static int F_10 ( void )
{
struct V_1 V_2 [] = {
{ 0x180 , 0xA0 , 0 } ,
{ 0x181 , 0x04 , 0 } ,
{ 0x182 , 0x0 , 0 } ,
{ 0x183 , 0x0 , 0 } ,
{ 0x184 , 0x18 , 0 } ,
{ 0x185 , 0x40 , 0 } ,
{ 0x186 , 0x06 , 0 } ,
{ 0x187 , 0x0 , 0 } ,
{ 0x188 , 0x10 , 0 } ,
{ 0x189 , 0x39 , 0 } ,
{ 0x18a , 0x39 , 0 } ,
{ 0x18b , 0x02 , 0 } ,
{ 0x18c , 0x0 , 0 } ,
{ 0x18d , 0x0 , 0 } ,
{ 0x18e , 0x39 , 0 } ,
{ 0x18f , 0x0 , 0 } ,
{ 0x190 , 0x0 , 0 } ,
{ 0x191 , 0x20 , 0 } ,
{ 0x192 , 0x20 , 0 } ,
{ 0x193 , 0x0 , 0 } ,
{ 0x194 , 0x0 , 0 } ,
{ 0x195 , 0x06 , 0 } ,
{ 0x196 , 0x25 , 0 } ,
{ 0x197 , 0x0 , 0 } ,
{ 0x198 , 0xF , 0 } ,
{ 0x199 , 0x0 , 0 } ,
} ;
int V_24 = 0 ;
if ( V_3 . V_4 == V_25 )
V_24 = F_1 () ;
if ( V_24 )
return V_24 ;
return F_2 ( V_2 , V_10 , 26 ) ;
}
static int F_11 ( int V_27 )
{
struct V_1 V_2 [ 2 ] ;
int V_24 = 0 ;
if ( V_3 . V_4 == V_25 )
V_24 = F_1 () ;
if ( V_24 )
return V_24 ;
if ( V_27 == V_28 ) {
V_2 [ 0 ] . V_11 = 0x00 ;
V_2 [ 0 ] . V_16 = V_29 | V_17 ;
V_2 [ 0 ] . V_12 = V_30 ;
V_2 [ 1 ] . V_11 = 0x00 ;
V_2 [ 1 ] . V_16 = V_31 | V_32 ;
V_2 [ 1 ] . V_12 = V_23 ;
return F_2 ( V_2 , V_19 , 2 ) ;
} else if ( V_27 == V_33 ) {
V_2 [ 0 ] . V_11 = 0xC0 ;
V_2 [ 0 ] . V_16 = V_29 | V_17 ;
V_2 [ 0 ] . V_12 = V_30 ;
V_2 [ 1 ] . V_11 = 0x30 ;
V_2 [ 1 ] . V_16 = V_31 | V_32 ;
V_2 [ 1 ] . V_12 = V_23 ;
return F_2 ( V_2 , V_19 , 2 ) ;
} else
return - V_34 ;
}
static int F_12 ( int V_27 )
{
struct V_1 V_2 [ 2 ] ;
int V_24 = 0 ;
if ( V_3 . V_4 == V_25 )
V_24 = F_1 () ;
if ( V_24 )
return V_24 ;
if ( V_27 == V_28 ) {
V_2 [ 0 ] . V_11 = 0x00 ;
V_2 [ 0 ] . V_16 = V_29 | V_17 ;
V_2 [ 0 ] . V_12 = V_35 ;
V_2 [ 1 ] . V_11 = 0x00 ;
V_2 [ 1 ] . V_16 = V_36 | V_37 ;
V_2 [ 1 ] . V_12 = V_23 ;
return F_2 ( V_2 , V_19 , 2 ) ;
} else if ( V_27 == V_33 ) {
V_2 [ 0 ] . V_11 = 0xC0 ;
V_2 [ 0 ] . V_16 = V_29 | V_17 ;
V_2 [ 0 ] . V_12 = V_35 ;
V_2 [ 1 ] . V_11 = 0x03 ;
V_2 [ 1 ] . V_16 = V_36 | V_37 ;
V_2 [ 1 ] . V_12 = V_23 ;
return F_2 ( V_2 , V_19 , 2 ) ;
} else
return - V_34 ;
}
static int F_13 ( int V_38 , int V_39 , int V_9 )
{
T_1 V_40 = 0 ;
struct V_1 V_2 [ 4 ] ;
int V_24 = 0 , V_41 = 0 ;
if ( V_3 . V_4 == V_25 )
V_24 = F_1 () ;
if ( V_24 )
return V_24 ;
switch ( V_38 ) {
case 8000 :
V_40 = 0x00 ;
break;
case 11025 :
V_40 = 0x01 ;
break;
case 12000 :
V_40 = 0x02 ;
break;
case 16000 :
V_40 = 0x03 ;
break;
case 22050 :
V_40 = 0x04 ;
break;
case 24000 :
V_40 = 0x05 ;
break;
case 26000 :
V_40 = 0x06 ;
break;
case 32000 :
V_40 = 0x07 ;
break;
case 44100 :
V_40 = 0x08 ;
break;
case 48000 :
V_40 = 0x09 ;
break;
}
V_3 . V_9 = V_9 ;
if ( V_3 . V_9 == 1 ) {
V_2 [ 0 ] . V_12 = V_14 ;
V_2 [ 1 ] . V_12 = V_15 ;
V_2 [ 0 ] . V_16 = V_2 [ 1 ] . V_16 = V_17 ;
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 = 0x80 ;
F_2 ( V_2 , V_19 , 2 ) ;
} else {
V_2 [ 0 ] . V_12 = V_14 ;
V_2 [ 1 ] . V_12 = V_15 ;
V_2 [ 0 ] . V_16 = V_2 [ 1 ] . V_16 = V_17 ;
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 = 0x00 ;
F_2 ( V_2 , V_19 , 2 ) ;
}
F_5 ( L_3 , V_38 , V_40 ) ;
if ( V_39 == 24 ) {
V_2 [ 0 ] . V_12 = V_30 ;
V_2 [ 0 ] . V_16 = V_36 | V_37 | V_42 | V_43 ;
V_2 [ 0 ] . V_11 = 0xFB ;
V_2 [ 1 ] . V_12 = V_44 ;
V_2 [ 1 ] . V_11 = V_40 | 0x10 ;
V_2 [ 1 ] . V_16 = V_36 | V_37 | V_42 | V_43
| V_31 | V_32 | V_29 ;
V_2 [ 2 ] . V_12 = V_45 ;
V_2 [ 2 ] . V_11 = 0x02 ;
V_2 [ 2 ] . V_16 = 0x02 ;
V_41 = 3 ;
} else {
V_2 [ 0 ] . V_12 = V_44 ;
V_2 [ 0 ] . V_11 = V_40 ;
V_2 [ 0 ] . V_16 = V_36 | V_37 | V_42 | V_43 ;
V_2 [ 1 ] . V_12 = V_45 ;
V_2 [ 1 ] . V_11 = 0x00 ;
V_2 [ 1 ] . V_16 = 0x02 ;
V_41 = 2 ;
}
return F_2 ( V_2 , V_19 , V_41 ) ;
}
static int F_14 ( T_1 V_11 )
{
struct V_1 V_46 [] = {
{ V_47 , 0x81 , 0xf7 } ,
{ V_48 , 0x00 , 0xE0 } ,
} ;
struct V_1 V_49 [] = {
{ V_47 , 0x40 , V_42 | V_31 | V_32 | V_29 | V_17 } ,
{ V_48 , 0x00 , 0xE0 } ,
} ;
struct V_1 V_50 [] = {
{ V_47 , 0x10 , V_42 | V_31 | V_32 | V_29 | V_17 } ,
{ V_48 , 0x00 , 0xE0 } ,
} ;
int V_24 = 0 ;
if ( V_3 . V_4 == V_25 )
V_24 = F_1 () ;
if ( V_24 )
return V_24 ;
switch ( V_11 ) {
case V_51 :
F_5 ( L_4 ) ;
return F_2 ( V_49 , V_19 , 2 ) ;
break;
case V_52 :
F_5 ( L_5 ) ;
return F_2 ( V_50 ,
V_19 , 2 ) ;
break;
case V_53 :
F_5 ( L_6 ) ;
return F_2 ( V_46 , V_19 , 2 ) ;
break;
default:
return - V_34 ;
}
}
static int F_15 ( T_1 V_11 )
{
struct V_1 V_54 [] = {
{ 0x191 , 0x11 , 0x0 } ,
{ 0x192 , 0x0E , 0x0 } ,
} ;
struct V_1 V_55 [] = {
{ 0x191 , 0x17 , 0xFF } ,
{ 0x192 , 0x08 , 0xFF } ,
} ;
int V_24 = 0 ;
if ( V_3 . V_4 == V_25 )
V_24 = F_1 () ;
if ( V_24 )
return V_24 ;
switch ( V_11 ) {
case V_56 :
F_5 ( L_7 ) ;
return F_2 ( V_54 , V_10 , 2 ) ;
break;
case V_57 :
case V_58 :
F_5 ( L_8 ) ;
return F_2 ( V_55 , V_19 , 2 ) ;
break;
default:
return - V_34 ;
}
}
static int F_16 ( int V_59 , T_1 V_11 )
{
struct V_1 V_2 [ 6 ] = { { 0 ,} ,} ;
int V_60 = 0 ;
int V_24 = 0 ;
if ( V_3 . V_4 == V_25 )
V_24 = F_1 () ;
if ( V_24 )
return V_24 ;
F_5 ( L_9 , V_59 , V_11 ) ;
switch ( V_59 ) {
case V_61 :
V_2 [ 0 ] . V_12 = V_47 ;
V_2 [ 1 ] . V_12 = V_62 ;
V_2 [ 2 ] . V_12 = V_63 ;
V_2 [ 0 ] . V_16 = V_32 ;
V_2 [ 1 ] . V_16 = V_2 [ 2 ] . V_16 = V_29 ;
if ( V_11 == V_18 ) {
V_2 [ 0 ] . V_11 = 0x20 ;
V_2 [ 2 ] . V_11 = V_2 [ 1 ] . V_11 = 0x40 ;
} else
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11
= V_2 [ 2 ] . V_11 = 0x0 ;
V_60 = 3 ;
break;
case V_64 :
case V_65 :
V_2 [ 0 ] . V_12 = V_62 ;
V_2 [ 1 ] . V_12 = V_63 ;
V_2 [ 0 ] . V_16 = V_2 [ 1 ] . V_16 = V_29 ;
if ( V_11 == V_18 )
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 = 0x40 ;
else
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 = 0x0 ;
V_60 = 2 ;
break;
case V_66 :
case V_67 :
V_2 [ 0 ] . V_12 = V_13 ;
V_2 [ 1 ] . V_12 = V_15 ;
V_2 [ 0 ] . V_16 = V_2 [ 1 ] . V_16 = V_17 ;
if ( V_11 == V_18 )
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 = 0x80 ;
else
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 = 0x0 ;
V_60 = 2 ;
V_3 . V_8 = V_11 ;
break;
case V_68 :
case V_69 :
V_2 [ 0 ] . V_12 = V_14 ;
V_2 [ 1 ] . V_12 = V_15 ;
V_2 [ 0 ] . V_16 = V_2 [ 1 ] . V_16 = V_17 ;
if ( V_11 == V_18 )
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 = 0x80 ;
else
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 = 0x0 ;
V_3 . V_8 = V_11 ;
if ( V_3 . V_9 == 1 )
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 = 0x80 ;
V_60 = 2 ;
break;
case V_70 :
V_2 [ 0 ] . V_12 = V_13 ;
V_2 [ 1 ] . V_12 = V_14 ;
V_2 [ 2 ] . V_12 = V_15 ;
V_2 [ 3 ] . V_12 = V_47 ;
V_2 [ 4 ] . V_12 = V_62 ;
V_2 [ 5 ] . V_12 = V_63 ;
V_2 [ 0 ] . V_16 = V_2 [ 1 ] . V_16 =
V_2 [ 2 ] . V_16 = V_17 ;
V_2 [ 3 ] . V_16 = V_32 ;
V_2 [ 4 ] . V_16 = V_2 [ 5 ] . V_16 = V_29 ;
if ( V_11 == V_18 ) {
V_2 [ 0 ] . V_11 =
V_2 [ 1 ] . V_11 = V_2 [ 2 ] . V_11 = 0x80 ;
V_2 [ 3 ] . V_11 = 0x20 ;
V_2 [ 4 ] . V_11 = V_2 [ 5 ] . V_11 = 0x40 ;
} else {
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 =
V_2 [ 2 ] . V_11 = V_2 [ 3 ] . V_11 =
V_2 [ 4 ] . V_11 = V_2 [ 5 ] . V_11 = 0x0 ;
}
if ( V_3 . V_9 == 1 )
V_2 [ 1 ] . V_11 = V_2 [ 2 ] . V_11 = 0x80 ;
V_60 = 6 ;
V_3 . V_8 = V_11 ;
V_3 . V_6 = V_11 ;
break;
}
return F_2 ( V_2 , V_19 , V_60 ) ;
}
static int F_17 ( int V_59 , int V_11 )
{
struct V_1 V_71 , V_2 [ 4 ] = { { 0 } ,} ;
int V_60 = 0 ;
int V_24 = 0 ;
if ( V_3 . V_4 == V_25 )
V_24 = F_1 () ;
if ( V_24 )
return V_24 ;
switch ( V_59 ) {
case V_72 :
F_5 ( L_10 , V_11 ) ;
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 = V_11 ;
V_2 [ 0 ] . V_12 = V_13 ;
V_2 [ 1 ] . V_12 = V_15 ;
V_2 [ 0 ] . V_16 = V_2 [ 1 ] . V_16 =
( V_36 | V_37 | V_42 | V_43 | V_31 | V_32 ) ;
V_60 = 2 ;
break;
case V_73 :
F_5 ( L_11 , V_11 ) ;
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 = V_11 ;
V_2 [ 0 ] . V_12 = V_14 ;
V_2 [ 1 ] . V_12 = V_15 ;
V_2 [ 0 ] . V_16 = V_2 [ 1 ] . V_16 =
( V_36 | V_37 | V_42 | V_43 | V_31 | V_32 ) ;
if ( V_3 . V_9 == 1 ) {
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 = 0x80 ;
V_2 [ 0 ] . V_16 = V_2 [ 1 ] . V_16 = V_17 ;
}
V_60 = 2 ;
break;
case V_74 :
F_5 ( L_12 , V_11 ) ;
V_2 [ 0 ] . V_12 = V_62 ;
V_2 [ 1 ] . V_12 = V_63 ;
V_2 [ 2 ] . V_12 = V_75 ;
V_2 [ 2 ] . V_11 = V_11 ;
V_2 [ 0 ] . V_11 = V_2 [ 1 ] . V_11 = V_11 ;
V_71 . V_12 = V_48 ;
V_71 . V_11 = V_11 ;
V_71 . V_16 = ( V_36 | V_37 | V_42 | V_43 | V_32 | V_29 | V_17 ) ;
V_24 = F_2 ( & V_71 , V_19 , 1 ) ;
V_2 [ 0 ] . V_16 = V_2 [ 1 ] . V_16 =
V_2 [ 2 ] . V_16 = ( V_36 | V_37 | V_42 | V_43 | V_31 | V_32 ) ;
V_60 = 3 ;
break;
default:
return - V_34 ;
}
return F_2 ( V_2 , V_19 , V_60 ) ;
}
static int F_18 ( int V_59 , T_1 * V_11 )
{
struct V_1 V_2 [ 6 ] = { { 0 ,} ,} ;
int V_24 = 0 , V_76 = 0 , V_16 = 0 ;
if ( V_3 . V_4 == V_25 )
V_24 = F_1 () ;
if ( V_24 )
return V_24 ;
switch ( V_59 ) {
case V_65 :
case V_64 :
V_2 [ 0 ] . V_12 = V_62 ;
V_16 = V_29 ;
V_24 = F_2 ( V_2 , V_77 , 1 ) ;
if ( V_2 [ 0 ] . V_11 & V_16 )
* V_11 = V_18 ;
else
* V_11 = V_7 ;
break;
case V_61 :
V_2 [ 0 ] . V_12 = V_47 ;
V_16 = V_32 ;
V_24 = F_2 ( V_2 , V_77 , 1 ) ;
V_76 = ( V_2 [ 0 ] . V_11 & V_16 ) ;
if ( V_76 == 0 )
* V_11 = V_7 ;
else
* V_11 = V_18 ;
break;
case V_67 :
case V_66 :
V_2 [ 0 ] . V_12 = V_13 ;
V_16 = V_17 ;
V_24 = F_2 ( V_2 , V_77 , 1 ) ;
V_76 = V_2 [ 0 ] . V_11 & V_16 ;
if ( V_76 == 0 )
* V_11 = V_7 ;
else
* V_11 = V_18 ;
break;
case V_68 :
case V_69 :
V_2 [ 0 ] . V_12 = V_14 ;
V_16 = V_17 ;
V_24 = F_2 ( V_2 , V_77 , 1 ) ;
V_76 = V_2 [ 0 ] . V_11 & V_16 ;
if ( V_76 == 0 )
* V_11 = V_7 ;
else
* V_11 = V_18 ;
break;
default:
return - V_34 ;
}
return V_24 ;
}
static int F_19 ( int V_59 , int * V_11 )
{
struct V_1 V_2 = { 0 ,} ;
int V_24 = 0 , V_16 = 0 ;
if ( V_3 . V_4 == V_25 )
V_24 = F_1 () ;
if ( V_24 )
return V_24 ;
switch ( V_59 ) {
case V_74 :
F_5 ( L_13 ) ;
V_2 . V_12 = V_62 ;
V_16 = ( V_32 | V_31 | V_43 | V_42 | V_37 | V_36 ) ;
break;
case V_72 :
F_5 ( L_14 ) ;
V_2 . V_12 = V_13 ;
V_16 = ( V_32 | V_31 | V_43 | V_42 | V_37 | V_36 ) ;
break;
case V_73 :
F_5 ( L_15 ) ;
V_2 . V_12 = V_14 ;
V_16 = ( V_32 | V_31 | V_43 | V_42 | V_37 | V_36 ) ;
break;
default:
return - V_34 ;
}
V_24 = F_2 ( & V_2 , V_77 , 1 ) ;
F_5 ( L_16 , V_2 . V_11 ) ;
* V_11 = ( int ) ( V_2 . V_11 & V_16 ) ;
F_5 ( L_17 , * V_11 ) ;
return V_24 ;
}
static void F_20 ( void * V_78 )
{
struct V_79 * V_80 = V_78 ;
struct V_1 V_2 [] = {
{ 0x187 , 0x00 , V_17 } ,
{ 0x188 , 0x10 , V_31 } ,
{ 0x18b , 0x10 , V_31 } ,
} ;
struct V_1 V_81 [] = {
{ 0x198 , 0x00 , 0x0 } ,
} ;
F_5 ( L_18 ) ;
F_2 ( V_2 , V_19 , 3 ) ;
F_2 ( V_81 , V_10 , 1 ) ;
V_80 -> V_82 [ 0 ] . V_83 = 0 ;
V_84 = true ;
return;
}
static void F_21 ( void * V_85 , T_1 V_11 )
{
struct V_86 * V_87 = NULL ;
struct V_79 * V_80 = V_85 ;
unsigned int V_88 = 0 , V_89 = 0 , V_90 = 0 ;
V_87 = & V_80 -> V_82 [ 0 ] ;
if ( V_11 & 0x4 ) {
if ( ! V_84 )
F_20 ( V_80 ) ;
F_5 ( L_19 , V_11 & 0x4 ) ;
V_88 = ! ( V_87 -> V_83 ) ;
V_87 -> V_83 = V_88 ;
V_89 = 1 ;
V_87 -> V_82 . type = V_91 ;
}
if ( V_11 & 0x2 ) {
F_5 ( L_20 , V_11 & 0x2 ) ;
V_88 = 1 ;
V_89 = 1 ;
V_90 = 1 ;
V_87 -> V_82 . type = V_92 ;
}
if ( V_11 & 0x1 ) {
F_5 ( L_21 , V_11 & 0x1 ) ;
V_88 = 1 ;
V_89 = 1 ;
V_90 = 1 ;
V_87 -> V_82 . type = V_93 ;
}
if ( V_11 & 0x8 ) {
if ( ! V_84 )
F_20 ( V_80 ) ;
F_5 ( L_22 , V_11 & 0x8 ) ;
V_88 = ! ( V_87 -> V_83 ) ;
V_87 -> V_83 = V_88 ;
V_89 = 1 ;
V_87 -> V_82 . type = V_94 ;
}
if ( V_89 )
F_22 ( & V_87 -> V_82 ,
V_90 , V_88 ) ;
return;
}
static int F_23 ( void )
{
return 0 ;
}
