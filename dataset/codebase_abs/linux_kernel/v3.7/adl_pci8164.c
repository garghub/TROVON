static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 ,
char * V_8 , unsigned short V_9 )
{
int V_10 , V_11 ;
char * V_12 ;
V_10 = F_2 ( V_6 -> V_13 ) ;
switch ( V_10 ) {
case 0 :
V_11 = V_14 ;
V_12 = L_1 ;
break;
case 1 :
V_11 = V_15 ;
V_12 = L_2 ;
break;
case 2 :
V_11 = V_16 ;
V_12 = L_3 ;
break;
case 3 :
V_11 = V_17 ;
V_12 = L_4 ;
break;
default:
V_11 = V_14 ;
V_12 = L_1 ;
}
V_7 [ 0 ] = F_3 ( V_2 -> V_18 + V_11 + V_9 ) ;
F_4 ( V_19 L_5
L_6 ,
V_8 , V_7 [ 0 ] , V_7 [ 1 ] , V_12 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
F_1 ( V_2 , V_4 , V_6 , V_7 , L_7 , V_20 ) ;
return 2 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
F_1 ( V_2 , V_4 , V_6 , V_7 , L_8 , V_21 ) ;
return 2 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
F_1 ( V_2 , V_4 , V_6 , V_7 , L_9 , V_22 ) ;
return 2 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
F_1 ( V_2 , V_4 , V_6 , V_7 , L_10 , V_23 ) ;
return 2 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 ,
char * V_8 , unsigned short V_9 )
{
unsigned int V_10 , V_11 ;
char * V_12 ;
V_10 = F_2 ( V_6 -> V_13 ) ;
switch ( V_10 ) {
case 0 :
V_11 = V_14 ;
V_12 = L_1 ;
break;
case 1 :
V_11 = V_15 ;
V_12 = L_2 ;
break;
case 2 :
V_11 = V_16 ;
V_12 = L_3 ;
break;
case 3 :
V_11 = V_17 ;
V_12 = L_4 ;
break;
default:
V_11 = V_14 ;
V_12 = L_1 ;
}
F_10 ( V_7 [ 0 ] , V_2 -> V_18 + V_11 + V_9 ) ;
F_4 ( V_19 L_11
L_6 ,
V_8 , V_7 [ 0 ] , V_7 [ 1 ] , V_12 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
F_9 ( V_2 , V_4 , V_6 , V_7 , L_12 , V_24 ) ;
return 2 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
F_9 ( V_2 , V_4 , V_6 , V_7 , L_13 , V_25 ) ;
return 2 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
F_9 ( V_2 , V_4 , V_6 , V_7 , L_9 , V_22 ) ;
return 2 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
F_9 ( V_2 , V_4 , V_6 , V_7 , L_10 , V_23 ) ;
return 2 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_3 * V_4 ;
int V_28 ;
F_16 ( V_2 , & V_27 -> V_2 ) ;
V_2 -> V_29 = V_2 -> V_30 -> V_31 ;
V_28 = F_17 ( V_27 , V_2 -> V_29 ) ;
if ( V_28 )
return V_28 ;
V_2 -> V_18 = F_18 ( V_27 , 2 ) ;
V_28 = F_19 ( V_2 , 4 ) ;
if ( V_28 )
return V_28 ;
V_4 = & V_2 -> V_32 [ 0 ] ;
V_4 -> type = V_33 ;
V_4 -> V_34 = V_35 | V_36 ;
V_4 -> V_37 = 4 ;
V_4 -> V_38 = 0xffff ;
V_4 -> V_39 = 4 ;
V_4 -> V_40 = F_5 ;
V_4 -> V_41 = F_11 ;
V_4 = & V_2 -> V_32 [ 1 ] ;
V_4 -> type = V_33 ;
V_4 -> V_34 = V_35 | V_36 ;
V_4 -> V_37 = 4 ;
V_4 -> V_38 = 0xffff ;
V_4 -> V_39 = 4 ;
V_4 -> V_40 = F_6 ;
V_4 -> V_41 = F_12 ;
V_4 = & V_2 -> V_32 [ 2 ] ;
V_4 -> type = V_33 ;
V_4 -> V_34 = V_35 | V_36 ;
V_4 -> V_37 = 4 ;
V_4 -> V_38 = 0xffff ;
V_4 -> V_39 = 4 ;
V_4 -> V_40 = F_7 ;
V_4 -> V_41 = F_13 ;
V_4 = & V_2 -> V_32 [ 3 ] ;
V_4 -> type = V_33 ;
V_4 -> V_34 = V_35 | V_36 ;
V_4 -> V_37 = 4 ;
V_4 -> V_38 = 0xffff ;
V_4 -> V_39 = 4 ;
V_4 -> V_40 = F_8 ;
V_4 -> V_41 = F_14 ;
F_20 ( V_2 -> V_42 , L_14 , V_2 -> V_29 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_22 ( V_2 ) ;
if ( V_27 ) {
if ( V_2 -> V_18 )
F_23 ( V_27 ) ;
}
}
static int T_1 F_24 ( struct V_26 * V_2 ,
const struct V_43 * V_44 )
{
return F_25 ( V_2 , & V_45 ) ;
}
static void T_2 F_26 ( struct V_26 * V_2 )
{
F_27 ( V_2 ) ;
}
