static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( ( V_8 & V_11 ) == 0 )
return 0 ;
return - V_12 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
int V_14 = F_4 ( V_6 -> V_15 ) ;
int V_16 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_6 -> V_18 ; V_17 ++ ) {
F_5 ( V_14 , V_2 -> V_9 + V_19 ) ;
V_16 = F_6 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_16 )
return V_16 ;
V_13 [ V_17 ] = F_2 ( V_2 -> V_9 + V_20 ) ;
V_13 [ V_17 ] |= F_2 ( V_2 -> V_9 + V_21 ) << 8 ;
V_13 [ V_17 ] &= 0xfff ;
}
return V_17 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
struct V_22 * V_23 = V_2 -> V_24 ;
int V_17 ;
int V_14 ;
V_14 = F_4 ( V_6 -> V_15 ) ;
for ( V_17 = 0 ; V_17 < V_6 -> V_18 ; V_17 ++ ) {
F_5 ( V_13 [ V_17 ] & 0xff , V_2 -> V_9 + V_25 + 2 * V_14 ) ;
F_5 ( ( V_13 [ V_17 ] >> 8 ) & 0xff ,
V_2 -> V_9 + V_26 + 2 * V_14 ) ;
V_23 -> V_27 [ V_14 ] = V_13 [ V_17 ] ;
}
return V_17 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
struct V_22 * V_23 = V_2 -> V_24 ;
int V_17 ;
int V_14 ;
V_14 = F_4 ( V_6 -> V_15 ) ;
for ( V_17 = 0 ; V_17 < V_6 -> V_18 ; V_17 ++ )
V_13 [ V_17 ] = V_23 -> V_27 [ V_14 ] ;
return V_17 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
V_13 [ 1 ] = F_2 ( V_2 -> V_9 + V_28 ) ;
return V_6 -> V_18 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
if ( F_11 ( V_4 , V_13 ) )
F_5 ( V_4 -> V_29 , V_2 -> V_9 + V_28 ) ;
V_13 [ 1 ] = V_4 -> V_29 ;
return V_6 -> V_18 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
const struct V_32 * V_33 = F_13 ( V_2 ) ;
struct V_22 * V_23 ;
int V_16 ;
struct V_3 * V_4 ;
V_16 = F_14 ( V_2 , V_31 -> V_34 [ 0 ] , V_35 ) ;
if ( V_16 )
return V_16 ;
#if 0
outb(0, dev->iobase + DT2811_ADCSR);
udelay(100);
i = inb(dev->iobase + DT2811_ADDATLO);
i = inb(dev->iobase + DT2811_ADDATHI);
#endif
V_16 = F_15 ( V_2 , 4 ) ;
if ( V_16 )
return V_16 ;
V_23 = F_16 ( V_2 , sizeof( * V_23 ) ) ;
if ( ! V_23 )
return - V_36 ;
switch ( V_31 -> V_34 [ 2 ] ) {
case 0 :
V_23 -> V_37 = V_38 ;
break;
case 1 :
V_23 -> V_37 = V_39 ;
break;
case 2 :
V_23 -> V_37 = V_40 ;
break;
default:
V_23 -> V_37 = V_38 ;
break;
}
switch ( V_31 -> V_34 [ 4 ] ) {
case 0 :
V_23 -> V_41 [ 0 ] = V_42 ;
break;
case 1 :
V_23 -> V_41 [ 0 ] = V_43 ;
break;
case 2 :
V_23 -> V_41 [ 0 ] = V_44 ;
break;
default:
V_23 -> V_41 [ 0 ] = V_42 ;
break;
}
switch ( V_31 -> V_34 [ 5 ] ) {
case 0 :
V_23 -> V_41 [ 1 ] = V_42 ;
break;
case 1 :
V_23 -> V_41 [ 1 ] = V_43 ;
break;
case 2 :
V_23 -> V_41 [ 1 ] = V_44 ;
break;
default:
V_23 -> V_41 [ 1 ] = V_42 ;
break;
}
V_4 = & V_2 -> V_45 [ 0 ] ;
V_4 -> type = V_46 ;
V_4 -> V_47 = V_48 | V_49 ;
V_4 -> V_50 = V_23 -> V_37 == V_39 ? 8 : 16 ;
V_4 -> V_51 = F_3 ;
V_4 -> V_52 = 0xfff ;
switch ( V_31 -> V_34 [ 3 ] ) {
case 0 :
default:
V_4 -> V_53 = V_33 -> V_54 ;
break;
case 1 :
V_4 -> V_53 = V_33 -> V_55 ;
break;
case 2 :
V_4 -> V_53 = V_33 -> V_56 ;
break;
}
V_4 = & V_2 -> V_45 [ 1 ] ;
V_4 -> type = V_57 ;
V_4 -> V_47 = V_58 ;
V_4 -> V_50 = 2 ;
V_4 -> V_59 = F_7 ;
V_4 -> V_51 = F_8 ;
V_4 -> V_52 = 0xfff ;
V_4 -> V_60 = V_23 -> V_61 ;
V_23 -> V_61 [ 0 ] = V_62 [ V_23 -> V_41 [ 0 ] ] ;
V_23 -> V_61 [ 1 ] = V_62 [ V_23 -> V_41 [ 1 ] ] ;
V_4 = & V_2 -> V_45 [ 2 ] ;
V_4 -> type = V_63 ;
V_4 -> V_47 = V_48 ;
V_4 -> V_50 = 8 ;
V_4 -> V_64 = F_9 ;
V_4 -> V_52 = 1 ;
V_4 -> V_53 = & V_65 ;
V_4 = & V_2 -> V_45 [ 3 ] ;
V_4 -> type = V_66 ;
V_4 -> V_47 = V_58 ;
V_4 -> V_50 = 8 ;
V_4 -> V_64 = F_10 ;
V_4 -> V_52 = 1 ;
V_4 -> V_29 = 0 ;
V_4 -> V_53 = & V_65 ;
return 0 ;
}
