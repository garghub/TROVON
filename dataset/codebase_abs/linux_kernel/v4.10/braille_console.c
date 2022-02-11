static void F_1 ( unsigned int V_1 )
{
if ( V_2 )
F_2 ( V_1 , V_3 / 10 ) ;
}
static void F_3 ( T_1 * V_4 )
{
static T_1 V_5 [ V_6 ] ;
unsigned char V_7 [ 1 + 1 + 2 * V_6 + 2 + 1 ] , V_8 = 0 , * V_9 ;
T_1 V_10 ;
int V_11 ;
if ( ! V_12 )
return;
if ( ! memcmp ( V_5 , V_4 , V_6 * sizeof( * V_4 ) ) )
return;
memcpy ( V_5 , V_4 , V_6 * sizeof( * V_4 ) ) ;
#define F_4 1
#define F_5 2
#define F_6 2
#define F_7 4
#define F_8 5
V_7 [ 0 ] = F_5 ;
V_7 [ 1 ] = '>' ;
V_8 ^= '>' ;
V_9 = & V_7 [ 2 ] ;
for ( V_11 = 0 ; V_11 < V_6 ; V_11 ++ ) {
V_10 = V_4 [ V_11 ] ;
if ( V_10 >= 0x100 )
V_10 = '?' ;
else if ( V_10 == 0x00 )
V_10 = ' ' ;
V_8 ^= V_10 ;
if ( V_10 <= 0x05 ) {
* V_9 ++ = F_4 ;
V_10 |= 0x40 ;
}
* V_9 ++ = V_10 ;
}
if ( V_8 <= 0x05 ) {
* V_9 ++ = F_4 ;
V_8 |= 0x40 ;
}
* V_9 ++ = V_8 ;
* V_9 ++ = F_6 ;
V_12 -> V_13 ( V_12 , V_7 , V_9 - V_7 ) ;
}
static void F_9 ( struct V_14 * V_15 )
{
V_16 = V_15 -> V_16 - ( V_15 -> V_16 % V_6 ) ;
V_17 = V_15 -> V_17 ;
V_18 = V_15 -> V_16 ;
V_19 = V_15 -> V_17 ;
}
static void F_10 ( struct V_14 * V_15 )
{
if ( V_15 -> V_16 != V_18 || V_15 -> V_17 != V_19 )
F_9 ( V_15 ) ;
}
static void F_11 ( struct V_14 * V_15 )
{
T_1 V_4 [ V_6 ] ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_6 ; V_11 ++ ) {
T_1 V_20 = F_12 ( V_15 ,
2 * ( V_16 + V_11 ) + V_17 * V_15 -> V_21 ) ;
V_4 [ V_11 ] = F_13 ( V_15 , V_20 , 1 ) ;
}
F_3 ( V_4 ) ;
}
static int F_14 ( struct V_22 * V_23 ,
unsigned long V_24 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_14 * V_15 = V_27 -> V_15 ;
int V_28 = V_29 ;
if ( ! V_27 -> V_30 )
return V_28 ;
switch ( V_24 ) {
case V_31 :
if ( V_32 ) {
if ( V_27 -> V_33 == V_34 ) {
V_32 = 0 ;
F_1 ( 880 ) ;
F_10 ( V_15 ) ;
F_11 ( V_15 ) ;
V_28 = V_35 ;
}
} else {
V_28 = V_35 ;
switch ( V_27 -> V_33 ) {
case V_36 :
F_1 ( 440 ) ;
V_32 = 1 ;
V_37 = - 1 ;
F_3 ( V_38 ) ;
break;
case V_39 :
if ( V_16 > 0 ) {
V_16 -= V_6 ;
if ( V_16 < 0 )
V_16 = 0 ;
} else if ( V_17 >= 1 ) {
F_1 ( 880 ) ;
V_17 -- ;
V_16 = V_15 -> V_40 - V_6 ;
} else
F_1 ( 220 ) ;
break;
case V_41 :
if ( V_16 + V_6 < V_15 -> V_40 ) {
V_16 += V_6 ;
} else if ( V_17 + 1 < V_15 -> V_42 ) {
F_1 ( 880 ) ;
V_17 ++ ;
V_16 = 0 ;
} else
F_1 ( 220 ) ;
break;
case V_43 :
if ( V_17 + 1 < V_15 -> V_42 )
V_17 ++ ;
else
F_1 ( 220 ) ;
break;
case V_44 :
if ( V_17 >= 1 )
V_17 -- ;
else
F_1 ( 220 ) ;
break;
case V_45 :
F_9 ( V_15 ) ;
break;
case V_46 :
V_16 = 0 ;
V_17 = 0 ;
break;
case V_47 :
V_16 = 0 ;
V_17 = V_15 -> V_42 - 1 ;
break;
default:
V_28 = V_29 ;
break;
}
if ( V_28 == V_35 )
F_11 ( V_15 ) ;
}
break;
case V_48 :
{
unsigned char type = F_15 ( V_27 -> V_33 ) - 0xf0 ;
if ( type == V_49 ) {
unsigned char V_50 = F_16 ( V_27 -> V_33 ) ;
int V_51 = - 1 ;
switch ( V_50 ) {
case F_16 ( V_52 ) :
V_51 = F_17 ( V_53 , V_54 ) ;
break;
case F_16 ( V_55 ) :
V_51 = F_17 ( V_53 , V_56 ) ;
break;
case F_16 ( V_57 ) :
V_51 = F_17 ( V_53 , V_58 ) ;
break;
}
if ( V_51 == 1 )
F_1 ( 880 ) ;
else if ( V_51 == 0 )
F_1 ( 440 ) ;
}
}
case V_59 :
case V_60 :
case V_61 :
break;
}
return V_28 ;
}
static int F_18 ( struct V_22 * V_23 ,
unsigned long V_24 , void * V_25 )
{
struct V_62 * V_27 = V_25 ;
struct V_14 * V_15 = V_27 -> V_15 ;
switch ( V_24 ) {
case V_63 :
break;
case V_64 :
break;
case V_65 :
{
unsigned char V_9 = V_27 -> V_9 ;
if ( V_15 -> V_66 != V_53 )
break;
switch ( V_9 ) {
case '\b' :
case 127 :
if ( V_67 > 0 ) {
V_67 -- ;
V_38 [ V_67 ] = ' ' ;
}
break;
case '\n' :
case '\v' :
case '\f' :
case '\r' :
V_68 = 1 ;
break;
case '\t' :
V_9 = ' ' ;
default:
if ( V_9 < 32 )
break;
if ( V_68 ) {
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
V_67 = 0 ;
V_68 = 0 ;
}
if ( V_67 == V_6 )
memmove ( V_38 , & V_38 [ 1 ] ,
( V_6 - 1 ) * sizeof( * V_38 ) ) ;
else
V_67 ++ ;
V_38 [ V_67 - 1 ] = V_9 ;
break;
}
if ( V_32 )
F_3 ( V_38 ) ;
else {
F_10 ( V_15 ) ;
F_11 ( V_15 ) ;
}
break;
}
case V_69 :
if ( V_32 ) {
if ( V_15 -> V_66 != V_37 ) {
V_37 = V_15 -> V_66 ;
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
V_67 = 0 ;
F_3 ( V_38 ) ;
}
} else {
F_10 ( V_15 ) ;
F_11 ( V_15 ) ;
}
break;
}
return V_29 ;
}
int F_19 ( struct V_70 * V_70 , int V_71 ,
char * V_72 , char * V_73 )
{
int V_28 ;
if ( ! ( V_70 -> V_74 & V_75 ) )
return 0 ;
if ( ! V_72 )
V_72 = L_1 ;
if ( V_12 )
return - V_76 ;
if ( V_70 -> V_77 ) {
V_28 = V_70 -> V_77 ( V_70 , V_72 ) ;
if ( V_28 != 0 )
return V_28 ;
}
V_70 -> V_74 |= V_78 ;
V_70 -> V_71 = V_71 ;
V_12 = V_70 ;
F_20 ( & V_79 ) ;
F_21 ( & V_80 ) ;
return 1 ;
}
int F_22 ( struct V_70 * V_70 )
{
if ( V_12 != V_70 )
return - V_81 ;
if ( ! ( V_70 -> V_74 & V_75 ) )
return 0 ;
F_23 ( & V_79 ) ;
F_24 ( & V_80 ) ;
V_12 = NULL ;
return 1 ;
}
