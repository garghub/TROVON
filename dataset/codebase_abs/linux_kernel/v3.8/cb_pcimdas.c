static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 , V_12 ;
unsigned int V_13 ;
unsigned int V_14 ;
int V_15 = F_2 ( V_6 -> V_16 ) ;
unsigned short V_17 ;
int V_18 ;
if ( ( F_3 ( V_9 -> V_19 + 2 ) & 0x20 ) == 0 )
V_18 = V_4 -> V_20 / 2 ;
else
V_18 = V_4 -> V_20 ;
if ( V_15 > ( V_18 - 1 ) )
return - V_21 ;
V_13 = F_3 ( V_9 -> V_19 + 5 ) ;
if ( ( V_13 & 0x03 ) > 0 ) {
V_13 = V_13 & 0xfd ;
F_4 ( V_13 , V_9 -> V_19 + 5 ) ;
}
F_4 ( 0x01 , V_9 -> V_19 + 6 ) ;
F_4 ( 0x00 , V_9 -> V_19 + 7 ) ;
V_17 = V_15 | ( V_15 << 4 ) ;
F_4 ( V_17 , V_9 -> V_19 + 0 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_11 ; V_11 ++ ) {
F_5 ( 0 , V_2 -> V_22 + 0 ) ;
#define F_6 1000
for ( V_12 = 0 ; V_12 < F_6 ; V_12 ++ ) {
V_14 = F_3 ( V_9 -> V_19 + 2 ) & 0x80 ;
if ( ! V_14 )
break;
}
if ( V_12 == F_6 ) {
F_7 ( L_1 ) ;
return - V_21 ;
}
V_7 [ V_11 ] = F_8 ( V_2 -> V_22 + 0 ) ;
}
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_12 ;
int V_15 = F_2 ( V_6 -> V_16 ) ;
for ( V_12 = 0 ; V_12 < V_6 -> V_11 ; V_12 ++ ) {
switch ( V_15 ) {
case 0 :
F_5 ( V_7 [ V_12 ] & 0x0FFF , V_2 -> V_22 + V_23 ) ;
break;
case 1 :
F_5 ( V_7 [ V_12 ] & 0x0FFF , V_2 -> V_22 + V_24 ) ;
break;
default:
return - 1 ;
}
V_9 -> V_25 [ V_15 ] = V_7 [ V_12 ] ;
}
return V_12 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_12 ;
int V_15 = F_2 ( V_6 -> V_16 ) ;
for ( V_12 = 0 ; V_12 < V_6 -> V_11 ; V_12 ++ )
V_7 [ V_12 ] = V_9 -> V_25 [ V_15 ] ;
return V_12 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned long V_26 )
{
struct V_27 * V_28 = F_12 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
unsigned long V_29 ;
int V_30 ;
V_2 -> V_31 = V_2 -> V_32 -> V_33 ;
V_9 = F_13 ( sizeof( * V_9 ) , V_34 ) ;
if ( ! V_9 )
return - V_35 ;
V_2 -> V_10 = V_9 ;
V_30 = F_14 ( V_28 , V_2 -> V_31 ) ;
if ( V_30 )
return V_30 ;
V_2 -> V_22 = F_15 ( V_28 , 2 ) ;
V_9 -> V_19 = F_15 ( V_28 , 3 ) ;
V_29 = F_15 ( V_28 , 4 ) ;
V_30 = F_16 ( V_2 , 3 ) ;
if ( V_30 )
return V_30 ;
V_4 = & V_2 -> V_36 [ 0 ] ;
V_4 -> type = V_37 ;
V_4 -> V_38 = V_39 | V_40 ;
V_4 -> V_20 = 16 ;
V_4 -> V_41 = 0xffff ;
V_4 -> V_42 = & V_43 ;
V_4 -> V_44 = 1 ;
V_4 -> V_45 = F_1 ;
V_4 = & V_2 -> V_36 [ 1 ] ;
V_4 -> type = V_46 ;
V_4 -> V_38 = V_47 ;
V_4 -> V_20 = 2 ;
V_4 -> V_41 = 0xfff ;
V_4 -> V_42 = & V_43 ;
V_4 -> V_48 = & F_9 ;
V_4 -> V_45 = & F_10 ;
V_4 = & V_2 -> V_36 [ 2 ] ;
F_17 ( V_2 , V_4 , NULL , V_29 ) ;
F_18 ( V_2 -> V_49 , L_2 , V_2 -> V_31 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_12 ( V_2 ) ;
if ( V_2 -> V_50 )
F_20 ( V_2 -> V_50 , V_2 ) ;
if ( V_28 ) {
if ( V_2 -> V_22 )
F_21 ( V_28 ) ;
}
}
static int F_22 ( struct V_27 * V_2 ,
const struct V_51 * V_52 )
{
return F_23 ( V_2 , & V_53 ) ;
}
static void F_24 ( struct V_27 * V_2 )
{
F_25 ( V_2 ) ;
}
