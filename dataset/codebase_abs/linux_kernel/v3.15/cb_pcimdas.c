static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 ;
V_11 = F_2 ( V_9 -> V_12 + 2 ) ;
if ( ( V_11 & 0x80 ) == 0 )
return 0 ;
return - V_13 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_14 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_15 ;
unsigned int V_16 ;
int V_17 = F_4 ( V_6 -> V_18 ) ;
unsigned short V_19 ;
int V_20 ;
int V_21 ;
if ( ( F_2 ( V_9 -> V_12 + 2 ) & 0x20 ) == 0 )
V_20 = V_4 -> V_22 / 2 ;
else
V_20 = V_4 -> V_22 ;
if ( V_17 > ( V_20 - 1 ) )
return - V_23 ;
V_16 = F_2 ( V_9 -> V_12 + 5 ) ;
if ( ( V_16 & 0x03 ) > 0 ) {
V_16 = V_16 & 0xfd ;
F_5 ( V_16 , V_9 -> V_12 + 5 ) ;
}
F_5 ( 0x01 , V_9 -> V_12 + 6 ) ;
F_5 ( 0x00 , V_9 -> V_12 + 7 ) ;
V_19 = V_17 | ( V_17 << 4 ) ;
F_5 ( V_19 , V_9 -> V_12 + 0 ) ;
for ( V_15 = 0 ; V_15 < V_6 -> V_15 ; V_15 ++ ) {
F_6 ( 0 , V_2 -> V_24 + 0 ) ;
V_21 = F_7 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_21 )
return V_21 ;
V_14 [ V_15 ] = F_8 ( V_2 -> V_24 + 0 ) ;
}
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_14 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_25 ;
int V_17 = F_4 ( V_6 -> V_18 ) ;
for ( V_25 = 0 ; V_25 < V_6 -> V_15 ; V_25 ++ ) {
switch ( V_17 ) {
case 0 :
F_6 ( V_14 [ V_25 ] & 0x0FFF , V_2 -> V_24 + V_26 ) ;
break;
case 1 :
F_6 ( V_14 [ V_25 ] & 0x0FFF , V_2 -> V_24 + V_27 ) ;
break;
default:
return - 1 ;
}
V_9 -> V_28 [ V_17 ] = V_14 [ V_25 ] ;
}
return V_25 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_14 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_25 ;
int V_17 = F_4 ( V_6 -> V_18 ) ;
for ( V_25 = 0 ; V_25 < V_6 -> V_15 ; V_25 ++ )
V_14 [ V_25 ] = V_9 -> V_28 [ V_17 ] ;
return V_25 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned long V_29 )
{
struct V_30 * V_31 = F_12 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
unsigned long V_32 ;
int V_21 ;
V_9 = F_13 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_33 ;
V_21 = F_14 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_24 = F_15 ( V_31 , 2 ) ;
V_9 -> V_12 = F_15 ( V_31 , 3 ) ;
V_32 = F_15 ( V_31 , 4 ) ;
V_21 = F_16 ( V_2 , 3 ) ;
if ( V_21 )
return V_21 ;
V_4 = & V_2 -> V_34 [ 0 ] ;
V_4 -> type = V_35 ;
V_4 -> V_36 = V_37 | V_38 ;
V_4 -> V_22 = 16 ;
V_4 -> V_39 = 0xffff ;
V_4 -> V_40 = & V_41 ;
V_4 -> V_42 = 1 ;
V_4 -> V_43 = F_3 ;
V_4 = & V_2 -> V_34 [ 1 ] ;
V_4 -> type = V_44 ;
V_4 -> V_36 = V_45 ;
V_4 -> V_22 = 2 ;
V_4 -> V_39 = 0xfff ;
V_4 -> V_40 = & V_41 ;
V_4 -> V_46 = & F_9 ;
V_4 -> V_43 = & F_10 ;
V_4 = & V_2 -> V_34 [ 2 ] ;
V_21 = F_17 ( V_2 , V_4 , NULL , V_32 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_47 )
F_19 ( V_2 -> V_47 , V_2 ) ;
F_20 ( V_2 ) ;
}
static int F_21 ( struct V_30 * V_2 ,
const struct V_48 * V_49 )
{
return F_22 ( V_2 , & V_50 ,
V_49 -> V_51 ) ;
}
