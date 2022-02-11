static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned int V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_12 ; V_11 ++ ) {
V_10 = V_7 [ 0 ] ;
F_3 ( ( V_10 >> 24 ) & 0xff , V_2 -> V_13 + F_4 ( V_8 ) ) ;
F_3 ( ( V_10 >> 16 ) & 0xff , V_2 -> V_13 + F_5 ( V_8 ) ) ;
F_3 ( ( V_10 >> 8 ) & 0xff , V_2 -> V_13 + F_6 ( V_8 ) ) ;
F_3 ( ( V_10 >> 0 ) & 0xff , V_2 -> V_13 + F_7 ( V_8 ) ) ;
}
return V_6 -> V_12 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned int V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_12 ; V_11 ++ ) {
F_9 ( V_2 -> V_13 + F_10 ( V_8 ) ) ;
V_10 = F_9 ( V_2 -> V_13 + F_7 ( V_8 ) ) ;
V_10 |= ( F_9 ( V_2 -> V_13 + F_6 ( V_8 ) ) << 8 ) ;
V_10 |= ( F_9 ( V_2 -> V_13 + F_5 ( V_8 ) ) << 16 ) ;
V_10 |= ( F_9 ( V_2 -> V_13 + F_4 ( V_8 ) ) << 24 ) ;
V_7 [ V_11 ] = V_10 ;
}
return V_6 -> V_12 ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ )
F_3 ( 0 , V_2 -> V_13 + F_12 ( V_8 ) ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned char V_14 ;
switch ( V_7 [ 0 ] ) {
case V_15 :
switch ( V_7 [ 1 ] ) {
case V_16 :
V_14 = V_17 ;
break;
case V_18 :
V_14 = V_19 ;
break;
case V_20 :
V_14 = V_21 ;
break;
default:
return - V_22 ;
}
F_3 ( V_14 , V_2 -> V_13 + V_23 ) ;
break;
case V_24 :
V_14 = F_9 ( V_2 -> V_13 + V_23 ) ;
switch ( V_14 ) {
case V_17 :
V_7 [ 1 ] = V_16 ;
V_7 [ 2 ] = 50 ;
break;
case V_19 :
V_7 [ 1 ] = V_18 ;
V_7 [ 2 ] = 250 ;
break;
case V_21 :
V_7 [ 1 ] = V_20 ;
V_7 [ 2 ] = 0 ;
break;
default:
return - V_22 ;
}
break;
case V_25 :
F_11 ( V_2 ) ;
break;
default:
return - V_22 ;
}
return V_6 -> V_12 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( F_15 ( V_4 , V_7 ) )
F_3 ( V_4 -> V_26 , V_2 -> V_13 + V_27 ) ;
V_7 [ 1 ] = V_4 -> V_26 ;
return V_6 -> V_12 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned long V_28 )
{
struct V_29 * V_30 = F_17 ( V_2 ) ;
struct V_3 * V_4 ;
int V_31 ;
V_31 = F_18 ( V_2 ) ;
if ( V_31 )
return V_31 ;
V_2 -> V_13 = F_19 ( V_30 , 0 ) ;
V_31 = F_20 ( V_2 , 2 ) ;
if ( V_31 )
return V_31 ;
V_4 = & V_2 -> V_32 [ 0 ] ;
V_4 -> type = V_33 ;
V_4 -> V_34 = V_35 ;
V_4 -> V_36 = 3 ;
V_4 -> V_37 = 0x01ffffff ;
V_4 -> V_38 = & V_39 ;
V_4 -> V_40 = F_8 ;
V_4 -> V_41 = F_1 ;
V_4 -> V_42 = F_13 ;
V_4 = & V_2 -> V_32 [ 1 ] ;
V_4 -> type = V_43 ;
V_4 -> V_34 = V_44 ;
V_4 -> V_36 = 3 ;
V_4 -> V_37 = 1 ;
V_4 -> V_38 = & V_45 ;
V_4 -> V_46 = F_14 ;
F_3 ( V_17 , V_2 -> V_13 + V_23 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_29 * V_2 ,
const struct V_47 * V_48 )
{
return F_22 ( V_2 , & V_49 ,
V_48 -> V_50 ) ;
}
