static unsigned int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_5 = V_6 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = V_14 ;
return 3 ;
}
static int F_2 ( struct V_1 * V_2 ,
unsigned char * V_15 , unsigned int V_16 )
{
unsigned int V_17 ;
if ( V_16 < 2 )
return V_18 ;
if ( V_16 > V_19 )
return V_20 ;
if ( ( V_2 -> V_5 != V_6 ) && ( V_2 -> V_5 != V_21 ) )
return V_22 ;
if ( V_23 & V_24 ) {
F_3 ( V_25 L_1 ) ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ )
F_3 ( L_2 , ( unsigned char ) V_15 [ V_17 ] ) ;
F_3 ( L_3 ) ;
}
V_2 -> V_11 = 0 ;
memcpy ( V_2 -> V_26 , V_15 , V_16 ) ;
V_2 -> V_8 = V_16 ;
V_2 -> V_9 = V_16 ;
V_2 -> V_7 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_5 = V_27 ;
V_2 -> V_13 = V_14 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned char * V_15 , unsigned int V_28 )
{
int V_17 ;
if ( V_23 & V_24 ) {
F_3 ( V_25 L_4 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_10 ; V_17 ++ )
F_3 ( L_2 , V_2 -> V_29 [ V_17 ] ) ;
F_3 ( L_3 ) ;
}
if ( V_28 < V_2 -> V_10 ) {
V_2 -> V_10 = V_28 ;
V_2 -> V_12 = 1 ;
}
memcpy ( V_15 , V_2 -> V_29 , V_2 -> V_10 ) ;
if ( ( V_28 >= 3 ) && ( V_2 -> V_10 < 3 ) ) {
V_15 [ 2 ] = V_30 ;
V_2 -> V_10 = 3 ;
}
if ( V_2 -> V_12 ) {
V_15 [ 2 ] = V_31 ;
V_2 -> V_12 = 0 ;
}
return V_2 -> V_10 ;
}
static inline unsigned char F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_4 -> V_32 ( V_2 -> V_4 , 2 ) ;
}
static inline unsigned char F_6 ( struct V_1 * V_2 )
{
return V_2 -> V_4 -> V_32 ( V_2 -> V_4 , 1 ) ;
}
static inline unsigned char F_7 ( struct V_1 * V_2 )
{
return V_2 -> V_4 -> V_32 ( V_2 -> V_4 , 0 ) ;
}
static inline void F_8 ( struct V_1 * V_2 ,
unsigned char V_33 )
{
V_2 -> V_4 -> V_34 ( V_2 -> V_4 , 2 , V_33 ) ;
}
static inline void F_9 ( struct V_1 * V_2 ,
unsigned char V_35 )
{
V_2 -> V_4 -> V_34 ( V_2 -> V_4 , 1 , V_35 ) ;
}
static inline void F_10 ( struct V_1 * V_2 ,
unsigned char V_15 )
{
V_2 -> V_4 -> V_34 ( V_2 -> V_4 , 0 , V_15 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , char * V_36 )
{
( V_2 -> V_11 ) ++ ;
if ( V_2 -> V_11 > V_37 ) {
if ( V_23 & V_38 )
F_3 ( V_39
L_5 , V_36 ) ;
V_2 -> V_5 = V_21 ;
} else {
V_2 -> V_8 = V_2 -> V_9 ;
V_2 -> V_7 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_5 = V_27 ;
V_2 -> V_13 = V_14 ;
}
}
static inline void F_12 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_2 -> V_26 [ V_2 -> V_7 ] ) ;
( V_2 -> V_7 ) ++ ;
( V_2 -> V_8 ) -- ;
}
static inline void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 >= V_40 ) {
F_7 ( V_2 ) ;
V_2 -> V_12 = 1 ;
} else {
V_2 -> V_29 [ V_2 -> V_10 ] = F_7 ( V_2 ) ;
V_2 -> V_10 ++ ;
}
}
static enum V_41 F_14 ( struct V_1 * V_2 , long time )
{
unsigned char V_42 ;
unsigned char V_33 ;
unsigned char V_15 ;
if ( V_2 -> V_5 == V_21 ) {
F_1 ( V_2 , V_2 -> V_4 ) ;
return V_43 ;
}
if ( V_2 -> V_5 != V_6 ) {
if ( V_23 & V_44 )
F_3 ( V_25
L_6
L_7 ,
V_2 -> V_13 , time ) ;
if ( time < V_14 ) {
V_2 -> V_13 -= time ;
if ( V_2 -> V_13 < 0 ) {
F_11 ( V_2 , L_8 ) ;
return V_45 ;
}
}
}
V_33 = F_5 ( V_2 ) ;
if ( V_33 & V_46 )
return V_45 ;
V_42 = F_6 ( V_2 ) ;
if ( V_23 & V_44 )
F_3 ( V_25
L_9
L_10 ,
V_2 -> V_5 , V_33 , V_42 ) ;
switch ( V_2 -> V_5 ) {
case V_6 :
if ( V_33 & V_47 )
return V_48 ;
return V_49 ;
case V_27 :
F_9 ( V_2 , V_50 ) ;
F_8 ( V_2 , V_33 | V_46 ) ;
V_2 -> V_5 = V_51 ;
break;
case V_51 :
if ( V_42 != V_52 ) {
F_11 ( V_2 ,
L_11
L_12 ) ;
return V_45 ;
}
F_9 ( V_2 , V_53 ) ;
F_12 ( V_2 ) ;
F_8 ( V_2 , V_33 | V_46 ) ;
V_2 -> V_5 = V_54 ;
break;
case V_54 :
if ( V_42 != V_55 ) {
F_11 ( V_2 ,
L_13
L_14 ) ;
return V_45 ;
}
if ( V_33 & V_56 ) {
if ( V_2 -> V_8 == 1 ) {
F_9 ( V_2 , V_57 ) ;
V_2 -> V_5 = V_58 ;
} else {
F_9 ( V_2 , V_59 ) ;
V_2 -> V_5 = V_60 ;
}
F_12 ( V_2 ) ;
F_8 ( V_2 , V_33 | V_46 ) ;
} else
return V_45 ;
break;
case V_60 :
if ( V_42 != V_61 ) {
F_11 ( V_2 ,
L_15
L_16 ) ;
return V_45 ;
}
if ( V_33 & V_56 ) {
if ( V_2 -> V_8 == 1 ) {
F_9 ( V_2 , V_57 ) ;
V_2 -> V_5 = V_58 ;
} else {
F_9 ( V_2 , V_59 ) ;
V_2 -> V_5 = V_60 ;
}
F_12 ( V_2 ) ;
F_8 ( V_2 , V_33 | V_46 ) ;
} else
return V_45 ;
break;
case V_58 :
if ( V_42 != V_62 ) {
F_11 ( V_2 ,
L_17
L_18 ) ;
return V_45 ;
}
V_15 = F_7 ( V_2 ) ;
if ( V_15 != 0 ) {
if ( V_23 & V_38 )
F_3 ( V_25
L_19 , V_15 ) ;
F_11 ( V_2 ,
L_17
L_20 ) ;
return V_45 ;
} else
V_2 -> V_5 = V_63 ;
break;
case V_63 :
if ( V_33 & V_64 ) {
F_9 ( V_2 , V_65 ) ;
F_8 ( V_2 , V_33 | V_46 ) ;
V_2 -> V_5 = V_66 ;
} else
return V_45 ;
break;
case V_66 :
if ( V_42 != V_67 ) {
F_11 ( V_2 ,
L_21
L_22 ) ;
return V_45 ;
}
if ( V_33 & V_64 ) {
F_13 ( V_2 ) ;
F_9 ( V_2 , V_68 ) ;
F_8 ( V_2 , V_33 | V_46 ) ;
V_2 -> V_5 = V_69 ;
} else
return V_45 ;
break;
case V_69 :
switch ( V_42 ) {
case V_70 :
F_13 ( V_2 ) ;
F_9 ( V_2 , V_71 ) ;
F_8 ( V_2 , V_33 | V_46 ) ;
V_2 -> V_5 = V_72 ;
break;
case V_73 :
if ( V_33 & V_64 ) {
F_13 ( V_2 ) ;
F_9 ( V_2 , V_68 ) ;
F_8 ( V_2 , V_33 | V_46 ) ;
V_2 -> V_5 = V_69 ;
} else
return V_45 ;
break;
default:
F_11 (
V_2 ,
L_23
L_24 ) ;
return V_45 ;
}
break;
case V_72 :
if ( V_42 != V_52 ) {
F_11 ( V_2 ,
L_25
L_26 ) ;
return V_45 ;
}
V_15 = F_7 ( V_2 ) ;
if ( V_15 != 0 ) {
if ( V_23 & V_38 )
F_3 ( V_25
L_27 , V_15 ) ;
F_11 ( V_2 ,
L_25
L_20 ) ;
return V_45 ;
} else {
V_2 -> V_5 = V_6 ;
return V_74 ;
}
case V_21 :
F_1 ( V_2 , V_2 -> V_4 ) ;
return V_43 ;
default:
if ( V_23 & V_38 ) {
F_3 ( V_25 L_28 , V_2 -> V_5 ) ;
F_11 ( V_2 , L_29 ) ;
return V_45 ;
}
}
V_2 -> V_13 = V_14 ;
return V_75 ;
}
static int F_15 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) == 0xff )
return 1 ;
return 0 ;
}
static void F_16 ( struct V_1 * V_76 )
{
}
static int F_17 ( void )
{
return sizeof( struct V_1 ) ;
}
