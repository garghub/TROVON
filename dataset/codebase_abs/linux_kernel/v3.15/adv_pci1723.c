static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
F_2 ( 0x01 , V_2 -> V_7 + V_8 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) {
V_4 -> V_9 [ V_6 ] = 0x8000 ;
F_2 ( V_4 -> V_9 [ V_6 ] , V_2 -> V_7 + F_3 ( V_6 ) ) ;
V_4 -> V_10 [ V_6 ] = 0 ;
F_2 ( ( ( V_4 -> V_10 [ V_6 ] << 4 ) | V_6 ) ,
V_11 ) ;
}
F_2 ( 0 , V_2 -> V_7 + V_12 ) ;
F_2 ( 0 , V_2 -> V_7 + V_13 ) ;
F_2 ( 0 , V_2 -> V_7 + V_8 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_16 * V_17 , unsigned int * V_18 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_19 , V_20 ;
V_20 = F_5 ( V_17 -> V_21 ) ;
for ( V_19 = 0 ; V_19 < V_17 -> V_19 ; V_19 ++ )
V_18 [ V_19 ] = V_4 -> V_9 [ V_20 ] ;
return V_19 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_16 * V_17 , unsigned int * V_18 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_19 , V_20 ;
V_20 = F_5 ( V_17 -> V_21 ) ;
for ( V_19 = 0 ; V_19 < V_17 -> V_19 ; V_19 ++ ) {
V_4 -> V_9 [ V_20 ] = V_18 [ V_19 ] ;
F_2 ( V_18 [ V_19 ] , V_2 -> V_7 + F_3 ( V_20 ) ) ;
}
return V_19 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_16 * V_17 , unsigned int * V_18 )
{
unsigned int V_20 = F_5 ( V_17 -> V_21 ) ;
unsigned int V_22 ;
unsigned short V_23 ;
int V_24 ;
if ( V_20 < 8 )
V_22 = 0x00ff ;
else
V_22 = 0xff00 ;
V_24 = F_8 ( V_2 , V_15 , V_17 , V_18 , V_22 ) ;
if ( V_24 )
return V_24 ;
V_23 = 0x0000 ;
if ( ! ( V_15 -> V_25 & 0x00ff ) )
V_23 |= 0x0001 ;
if ( ! ( V_15 -> V_25 & 0xff00 ) )
V_23 |= 0x0002 ;
F_2 ( V_23 , V_2 -> V_7 + V_26 ) ;
return V_17 -> V_19 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
if ( F_10 ( V_15 , V_18 ) )
F_2 ( V_15 -> V_27 , V_2 -> V_7 + V_28 ) ;
V_18 [ 1 ] = F_11 ( V_2 -> V_7 + V_29 ) ;
return V_17 -> V_19 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned long V_30 )
{
struct V_31 * V_32 = F_13 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
int V_24 ;
V_4 = F_14 ( V_2 , sizeof( * V_4 ) ) ;
if ( ! V_4 )
return - V_33 ;
V_24 = F_15 ( V_2 ) ;
if ( V_24 )
return V_24 ;
V_2 -> V_7 = F_16 ( V_32 , 2 ) ;
V_24 = F_17 ( V_2 , 2 ) ;
if ( V_24 )
return V_24 ;
V_15 = & V_2 -> V_34 [ 0 ] ;
V_2 -> V_35 = V_15 ;
V_15 -> type = V_36 ;
V_15 -> V_37 = V_38 | V_39 | V_40 ;
V_15 -> V_41 = 8 ;
V_15 -> V_42 = 0xffff ;
V_15 -> V_43 = 8 ;
V_15 -> V_44 = & V_45 ;
V_15 -> V_46 = F_6 ;
V_15 -> V_47 = F_4 ;
V_15 = & V_2 -> V_34 [ 1 ] ;
V_15 -> type = V_48 ;
V_15 -> V_37 = V_49 | V_50 ;
V_15 -> V_41 = 16 ;
V_15 -> V_42 = 1 ;
V_15 -> V_43 = 16 ;
V_15 -> V_44 = & V_51 ;
V_15 -> V_52 = F_7 ;
V_15 -> V_53 = F_9 ;
switch ( F_11 ( V_2 -> V_7 + V_54 ) & 0x03 ) {
case 0x00 :
V_15 -> V_25 = 0xFFFF ;
break;
case 0x01 :
V_15 -> V_25 = 0xFF00 ;
break;
case 0x02 :
V_15 -> V_25 = 0x00FF ;
break;
case 0x03 :
V_15 -> V_25 = 0x0000 ;
break;
}
V_15 -> V_27 = F_11 ( V_2 -> V_7 + V_29 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 )
F_1 ( V_2 ) ;
F_19 ( V_2 ) ;
}
static int F_20 ( struct V_31 * V_2 ,
const struct V_55 * V_56 )
{
return F_21 ( V_2 , & V_57 ,
V_56 -> V_58 ) ;
}
