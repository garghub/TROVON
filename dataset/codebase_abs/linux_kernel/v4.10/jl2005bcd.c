static int F_1 ( struct V_1 * V_1 , unsigned char * V_2 )
{
int V_3 ;
memcpy ( V_1 -> V_4 , V_2 , 2 ) ;
V_3 = F_2 ( V_1 -> V_5 ,
F_3 ( V_1 -> V_5 , 3 ) ,
V_1 -> V_4 , 2 , NULL , 500 ) ;
if ( V_3 < 0 )
F_4 ( L_1 ,
V_1 -> V_4 [ 0 ] , V_3 ) ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_1 )
{
int V_3 ;
V_3 = F_2 ( V_1 -> V_5 ,
F_6 ( V_1 -> V_5 , 0x84 ) ,
V_1 -> V_4 , 1 , NULL , 500 ) ;
if ( V_3 < 0 )
F_4 ( L_2 ,
V_1 -> V_4 [ 0 ] , V_3 ) ;
return V_3 ;
}
static int F_7 ( struct V_1 * V_1 , unsigned char V_6 )
{
int V_3 ;
static T_1 V_7 [ 2 ] = { 0x95 , 0x00 } ;
V_7 [ 1 ] = V_6 ;
V_3 = F_1 ( V_1 , V_7 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_5 ( V_1 ) ;
return V_3 ;
}
static int F_8 ( struct V_1 * V_1 )
{
int V_8 ;
int V_3 ;
int V_9 = 0 ;
static T_1 V_7 [ 2 ] = { 0x7f , 0x01 } ;
V_3 = F_1 ( V_1 , V_7 ) ;
if ( V_3 < 0 )
return V_3 ;
V_8 = 0 ;
while ( V_8 < 20 && ! V_9 ) {
V_3 = F_7 ( V_1 , 0x7e ) ;
if ( V_3 < 0 )
return V_3 ;
V_9 = V_1 -> V_4 [ 0 ] ;
V_3 = F_7 ( V_1 , 0x7d ) ;
if ( V_3 < 0 )
return V_3 ;
V_8 ++ ;
}
F_9 ( V_10 , L_3 , V_1 -> V_4 [ 0 ] ) ;
return V_3 ;
}
static int F_10 ( struct V_1 * V_1 , unsigned char V_6 ,
unsigned char V_11 )
{
int V_3 ;
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_6 ;
V_7 [ 1 ] = V_11 ;
V_3 = F_1 ( V_1 , V_7 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_3 ;
}
static int F_11 ( struct V_1 * V_1 )
{
struct V_12 * V_12 = (struct V_12 * ) V_1 ;
int V_8 = 0 ;
int V_3 = - 1 ;
unsigned char V_13 [] = { 0x57 , 0x02 , 0x03 , 0x5d , 0x5e , 0x5f } ;
F_9 ( V_14 , L_4 ) ;
V_3 = F_7 ( V_1 , V_13 [ 0 ] ) ;
F_9 ( V_14 , L_5 , V_1 -> V_4 [ 0 ] ) ;
if ( V_3 < 0 )
return V_3 ;
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ ) {
V_3 = F_7 ( V_1 , V_13 [ V_8 ] ) ;
if ( V_3 < 0 )
return V_3 ;
V_12 -> V_15 [ V_8 ] = V_1 -> V_4 [ 0 ] ;
}
F_9 ( V_14 , L_6 ,
V_12 -> V_15 [ 0 ] ,
V_12 -> V_15 [ 1 ] ,
V_12 -> V_15 [ 2 ] ,
V_12 -> V_15 [ 3 ] ,
V_12 -> V_15 [ 4 ] ,
V_12 -> V_15 [ 5 ] ) ;
return 0 ;
}
static int F_12
( struct V_1 * V_1 )
{
int V_8 ;
int V_3 = - 1 ;
static T_1 V_7 [] [ 2 ] = {
{ 0x05 , 0x00 } ,
{ 0x7c , 0x00 } ,
{ 0x7d , 0x18 } ,
{ 0x02 , 0x00 } ,
{ 0x01 , 0x00 } ,
{ 0x04 , 0x52 } ,
} ;
for ( V_8 = 0 ; V_8 < F_13 ( V_7 ) ; V_8 ++ ) {
F_14 ( 60 ) ;
V_3 = F_1 ( V_1 , V_7 [ V_8 ] ) ;
if ( V_3 < 0 )
return V_3 ;
}
F_14 ( 60 ) ;
return V_3 ;
}
static int F_15 ( struct V_1 * V_1 )
{
int V_8 ;
int V_3 = - 1 ;
static T_1 V_7 [] [ 2 ] = {
{ 0x06 , 0x00 } ,
{ 0x7c , 0x00 } ,
{ 0x7d , 0x1a } ,
{ 0x02 , 0x00 } ,
{ 0x01 , 0x00 } ,
{ 0x04 , 0x52 } ,
} ;
for ( V_8 = 0 ; V_8 < F_13 ( V_7 ) ; V_8 ++ ) {
F_14 ( 60 ) ;
V_3 = F_1 ( V_1 , V_7 [ V_8 ] ) ;
if ( V_3 < 0 )
return V_3 ;
}
F_14 ( 60 ) ;
return V_3 ;
}
static int F_16 ( struct V_1 * V_1 )
{
int V_8 ;
int V_3 = - 1 ;
static T_1 V_7 [] [ 2 ] = {
{ 0x05 , 0x00 } ,
{ 0x7c , 0x00 } ,
{ 0x7d , 0x30 } ,
{ 0x02 , 0x00 } ,
{ 0x01 , 0x00 } ,
{ 0x04 , 0x42 } ,
} ;
for ( V_8 = 0 ; V_8 < F_13 ( V_7 ) ; V_8 ++ ) {
F_14 ( 60 ) ;
V_3 = F_1 ( V_1 , V_7 [ V_8 ] ) ;
if ( V_3 < 0 )
return V_3 ;
}
F_14 ( 60 ) ;
return V_3 ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_8 ;
int V_3 = - 1 ;
static T_1 V_7 [] [ 2 ] = {
{ 0x06 , 0x00 } ,
{ 0x7c , 0x00 } ,
{ 0x7d , 0x32 } ,
{ 0x02 , 0x00 } ,
{ 0x01 , 0x00 } ,
{ 0x04 , 0x42 } ,
} ;
for ( V_8 = 0 ; V_8 < F_13 ( V_7 ) ; V_8 ++ ) {
F_14 ( 60 ) ;
V_3 = F_1 ( V_1 , V_7 [ V_8 ] ) ;
if ( V_3 < 0 )
return V_3 ;
}
F_14 ( 60 ) ;
return V_3 ;
}
static int F_18 ( struct V_1 * V_1 )
{
return F_10 ( V_1 , 0x07 , 0x00 ) ;
}
static void F_19 ( struct V_16 * V_17 )
{
struct V_12 * V_5 = F_20 ( V_17 , struct V_12 , V_16 ) ;
struct V_1 * V_1 = & V_5 -> V_1 ;
int V_18 = 0 ;
int V_19 ;
int V_20 = 0 ;
unsigned char V_21 [ 2 ] = { 0x4a , 0x4c } ;
int V_22 ;
int V_23 ;
int V_24 ;
T_1 * V_25 ;
V_25 = F_21 ( V_26 , V_27 | V_28 ) ;
if ( ! V_25 ) {
F_4 ( L_7 ) ;
goto V_29;
}
while ( V_1 -> V_30 && V_1 -> V_31 ) {
#ifdef F_22
if ( V_1 -> V_32 )
break;
#endif
if ( ! V_20 ) {
F_23 ( & V_1 -> V_33 ) ;
V_24 = F_8 ( V_1 ) ;
F_24 ( & V_1 -> V_33 ) ;
if ( V_24 < 0 )
goto V_29;
V_24 = F_2 ( V_1 -> V_5 ,
F_6 ( V_1 -> V_5 , 0x82 ) ,
V_25 , V_26 , & V_22 ,
V_34 ) ;
F_9 ( V_35 ,
L_8 ,
V_22 , V_26 ) ;
if ( V_24 < 0 || V_22 < V_26 )
goto V_29;
if ( memcmp ( V_21 , V_25 , 2 ) != 0 ) {
F_4 ( L_9 ) ;
goto V_29;
}
V_18 = V_25 [ 0x07 ] * V_5 -> V_36 - V_22 ;
F_9 ( V_35 , L_10 , V_18 ) ;
V_23 = V_37 ;
F_25 ( V_1 , V_23 ,
V_25 , V_22 ) ;
V_20 = 1 ;
}
while ( V_18 > 0 && V_1 -> V_30 ) {
V_19 = V_18 > V_26 ?
V_26 : V_18 ;
V_24 = F_2 ( V_1 -> V_5 ,
F_6 ( V_1 -> V_5 , 0x82 ) ,
V_25 , V_19 , & V_22 ,
V_34 ) ;
if ( V_24 < 0 || V_22 < V_19 )
goto V_29;
F_9 ( V_35 ,
L_11 ,
V_19 , V_18 ) ;
V_18 -= V_19 ;
if ( V_18 == 0 ) {
V_23 = V_38 ;
V_20 = 0 ;
} else
V_23 = V_39 ;
F_25 ( V_1 , V_23 ,
V_25 , V_19 ) ;
}
}
V_29:
if ( V_1 -> V_30 ) {
F_23 ( & V_1 -> V_33 ) ;
F_18 ( V_1 ) ;
F_24 ( & V_1 -> V_33 ) ;
}
F_26 ( V_25 ) ;
}
static int F_27 ( struct V_1 * V_1 ,
const struct V_40 * V_41 )
{
struct V_42 * V_42 ;
struct V_12 * V_12 = (struct V_12 * ) V_1 ;
V_42 = & V_1 -> V_42 ;
V_42 -> V_43 = 64 ;
V_42 -> V_44 = 1 ;
F_11 ( V_1 ) ;
if ( ( V_12 -> V_15 [ 0 ] & 0xf0 ) == 0x40 ) {
V_42 -> V_45 = V_46 ;
V_42 -> V_47 = F_13 ( V_46 ) ;
V_12 -> V_36 = 0x80 ;
} else {
V_42 -> V_45 = V_48 ;
V_42 -> V_47 = F_13 ( V_48 ) ;
V_12 -> V_36 = 0x200 ;
}
F_28 ( & V_12 -> V_16 , F_19 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_12 * V_12 = (struct V_12 * ) V_1 ;
V_12 -> V_49 = V_1 -> V_42 . V_45 ;
switch ( V_1 -> V_50 . V_51 ) {
case 640 :
F_9 ( V_52 , L_12 ) ;
F_12 ( V_1 ) ;
break;
case 320 :
F_9 ( V_52 , L_13 ) ;
F_15 ( V_1 ) ;
break;
case 352 :
F_9 ( V_52 , L_14 ) ;
F_16 ( V_1 ) ;
break;
case 176 :
F_9 ( V_52 , L_15 ) ;
F_17 ( V_1 ) ;
break;
default:
F_4 ( L_16 ) ;
return - 1 ;
}
F_31 ( & V_12 -> V_16 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_1 )
{
struct V_12 * V_5 = (struct V_12 * ) V_1 ;
F_24 ( & V_1 -> V_33 ) ;
F_33 ( & V_5 -> V_16 ) ;
F_23 ( & V_1 -> V_33 ) ;
}
static int F_34 ( struct V_53 * V_54 ,
const struct V_40 * V_41 )
{
return F_35 ( V_54 , V_41 , & V_55 , sizeof( struct V_12 ) ,
V_56 ) ;
}
