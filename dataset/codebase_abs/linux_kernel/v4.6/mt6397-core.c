static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_4 -> V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_4 -> V_6 , V_4 -> V_7 [ 0 ] ,
V_4 -> V_8 [ 0 ] ) ;
F_5 ( V_4 -> V_6 , V_4 -> V_7 [ 1 ] ,
V_4 -> V_8 [ 1 ] ) ;
F_6 ( & V_4 -> V_5 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_9 = V_2 -> V_10 & 0xf ;
int V_11 = V_2 -> V_10 >> 4 ;
V_4 -> V_8 [ V_11 ] &= ~ F_8 ( V_9 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_9 = V_2 -> V_10 & 0xf ;
int V_11 = V_2 -> V_10 >> 4 ;
V_4 -> V_8 [ V_11 ] |= F_8 ( V_9 ) ;
}
static int F_10 ( struct V_1 * V_1 , unsigned int V_12 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
int V_9 = V_1 -> V_10 & 0xf ;
int V_11 = V_1 -> V_10 >> 4 ;
if ( V_12 )
V_4 -> V_13 [ V_11 ] |= F_8 ( V_9 ) ;
else
V_4 -> V_13 [ V_11 ] &= ~ F_8 ( V_9 ) ;
return 0 ;
}
static void F_11 ( struct V_3 * V_4 , int V_11 ,
int V_14 )
{
unsigned int V_15 ;
int V_16 , V_17 , V_18 ;
V_18 = F_12 ( V_4 -> V_6 , V_11 , & V_15 ) ;
if ( V_18 ) {
F_13 ( V_4 -> V_19 , L_1 , V_18 ) ;
return;
}
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ ) {
if ( V_15 & F_8 ( V_16 ) ) {
V_17 = F_14 ( V_4 -> V_20 , V_14 + V_16 ) ;
if ( V_17 )
F_15 ( V_17 ) ;
}
}
F_5 ( V_4 -> V_6 , V_11 , V_15 ) ;
}
static T_1 F_16 ( int V_17 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_11 ( V_4 , V_4 -> V_21 [ 0 ] , 0 ) ;
F_11 ( V_4 , V_4 -> V_21 [ 1 ] , 16 ) ;
return V_22 ;
}
static int F_17 ( struct V_20 * V_23 , unsigned int V_17 ,
T_2 V_24 )
{
struct V_3 * V_4 = V_23 -> V_25 ;
F_18 ( V_17 , V_4 ) ;
F_19 ( V_17 , & V_26 , V_27 ) ;
F_20 ( V_17 , 1 ) ;
F_21 ( V_17 ) ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 )
{
int V_18 ;
F_23 ( & V_4 -> V_5 ) ;
F_5 ( V_4 -> V_6 , V_4 -> V_7 [ 0 ] , 0x0 ) ;
F_5 ( V_4 -> V_6 , V_4 -> V_7 [ 1 ] , 0x0 ) ;
V_4 -> V_20 = F_24 ( V_4 -> V_19 -> V_28 ,
V_29 , & V_30 , V_4 ) ;
if ( ! V_4 -> V_20 ) {
F_13 ( V_4 -> V_19 , L_2 ) ;
return - V_31 ;
}
V_18 = F_25 ( V_4 -> V_19 , V_4 -> V_17 , NULL ,
F_16 , V_32 , L_3 , V_4 ) ;
if ( V_18 ) {
F_13 ( V_4 -> V_19 , L_4 ,
V_4 -> V_17 , V_18 ) ;
return V_18 ;
}
return 0 ;
}
static int F_26 ( struct V_33 * V_19 )
{
struct V_3 * V_34 = F_27 ( V_19 ) ;
F_5 ( V_34 -> V_6 , V_34 -> V_7 [ 0 ] , V_34 -> V_13 [ 0 ] ) ;
F_5 ( V_34 -> V_6 , V_34 -> V_7 [ 1 ] , V_34 -> V_13 [ 1 ] ) ;
F_28 ( V_34 -> V_17 ) ;
return 0 ;
}
static int F_29 ( struct V_33 * V_19 )
{
struct V_3 * V_34 = F_27 ( V_19 ) ;
F_5 ( V_34 -> V_6 , V_34 -> V_7 [ 0 ] , V_34 -> V_8 [ 0 ] ) ;
F_5 ( V_34 -> V_6 , V_34 -> V_7 [ 1 ] , V_34 -> V_8 [ 1 ] ) ;
F_30 ( V_34 -> V_17 ) ;
return 0 ;
}
static int F_31 ( struct V_35 * V_36 )
{
int V_18 ;
unsigned int V_37 ;
struct V_3 * V_38 ;
V_38 = F_32 ( & V_36 -> V_19 , sizeof( * V_38 ) , V_39 ) ;
if ( ! V_38 )
return - V_31 ;
V_38 -> V_19 = & V_36 -> V_19 ;
V_38 -> V_6 = F_33 ( V_36 -> V_19 . V_40 , NULL ) ;
if ( ! V_38 -> V_6 )
return - V_41 ;
F_34 ( V_36 , V_38 ) ;
V_18 = F_12 ( V_38 -> V_6 , V_42 , & V_37 ) ;
if ( V_18 ) {
F_13 ( V_38 -> V_19 , L_5 , V_18 ) ;
goto V_43;
}
switch ( V_37 & 0xff ) {
case V_44 :
V_38 -> V_7 [ 0 ] = V_45 ;
V_38 -> V_7 [ 1 ] = V_46 ;
V_38 -> V_21 [ 0 ] = V_47 ;
V_38 -> V_21 [ 1 ] = V_48 ;
V_18 = F_35 ( & V_36 -> V_19 , - 1 , V_49 ,
F_36 ( V_49 ) , NULL , 0 , NULL ) ;
break;
case V_50 :
case V_51 :
V_38 -> V_7 [ 0 ] = V_52 ;
V_38 -> V_7 [ 1 ] = V_53 ;
V_38 -> V_21 [ 0 ] = V_54 ;
V_38 -> V_21 [ 1 ] = V_55 ;
V_18 = F_35 ( & V_36 -> V_19 , - 1 , V_56 ,
F_36 ( V_56 ) , NULL , 0 , NULL ) ;
break;
default:
F_13 ( & V_36 -> V_19 , L_6 , V_37 ) ;
V_18 = - V_41 ;
break;
}
V_38 -> V_17 = F_37 ( V_36 , 0 ) ;
if ( V_38 -> V_17 > 0 ) {
V_18 = F_22 ( V_38 ) ;
if ( V_18 )
return V_18 ;
}
V_43:
if ( V_18 ) {
F_38 ( V_38 -> V_20 ) ;
F_13 ( & V_36 -> V_19 , L_7 , V_18 ) ;
}
return V_18 ;
}
static int F_39 ( struct V_35 * V_36 )
{
F_40 ( & V_36 -> V_19 ) ;
return 0 ;
}
