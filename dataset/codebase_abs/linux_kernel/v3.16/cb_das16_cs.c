static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( V_8 & 0x0080 )
return 0 ;
return - V_11 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_12 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
int V_16 = F_4 ( V_6 -> V_17 ) ;
int V_18 = F_5 ( V_6 -> V_17 ) ;
int V_19 = F_6 ( V_6 -> V_17 ) ;
int V_20 ;
int V_21 ;
F_7 ( V_16 , V_2 -> V_9 + V_22 ) ;
V_14 -> V_23 &= ~ 0xf320 ;
V_14 -> V_23 |= ( V_19 == V_24 ) ? 0 : 0x0020 ;
F_7 ( V_14 -> V_23 , V_2 -> V_9 + V_10 ) ;
V_14 -> V_25 &= ~ 0xff00 ;
switch ( V_18 ) {
case 0 :
V_14 -> V_25 |= 0x800 ;
break;
case 1 :
V_14 -> V_25 |= 0x000 ;
break;
case 2 :
V_14 -> V_25 |= 0x100 ;
break;
case 3 :
V_14 -> V_25 |= 0x200 ;
break;
}
F_7 ( V_14 -> V_25 , V_2 -> V_9 + V_26 ) ;
for ( V_21 = 0 ; V_21 < V_6 -> V_27 ; V_21 ++ ) {
F_7 ( 0 , V_2 -> V_9 + V_28 ) ;
V_20 = F_8 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_20 )
return V_20 ;
V_12 [ V_21 ] = F_2 ( V_2 -> V_9 + V_28 ) ;
}
return V_21 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_12 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
int V_21 ;
int V_16 = F_4 ( V_6 -> V_17 ) ;
unsigned short V_23 ;
unsigned short V_29 ;
int V_30 ;
for ( V_21 = 0 ; V_21 < V_6 -> V_27 ; V_21 ++ ) {
V_14 -> V_31 [ V_16 ] = V_12 [ V_21 ] ;
V_29 = V_12 [ V_21 ] ;
F_7 ( V_14 -> V_23 , V_2 -> V_9 + V_10 ) ;
F_10 ( 1 ) ;
V_23 = V_14 -> V_23 & ~ 0xf ;
if ( V_16 )
V_23 |= 0x0001 ;
else
V_23 |= 0x0008 ;
F_7 ( V_23 , V_2 -> V_9 + V_10 ) ;
F_10 ( 1 ) ;
for ( V_30 = 15 ; V_30 >= 0 ; V_30 -- ) {
int V_32 = ( V_29 >> V_30 ) & 0x1 ;
V_32 <<= 1 ;
F_7 ( V_23 | V_32 | 0x0000 , V_2 -> V_9 + V_10 ) ;
F_10 ( 1 ) ;
F_7 ( V_23 | V_32 | 0x0004 , V_2 -> V_9 + V_10 ) ;
F_10 ( 1 ) ;
}
F_7 ( V_23 | 0x9 , V_2 -> V_9 + V_10 ) ;
}
return V_21 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_12 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
int V_21 ;
int V_16 = F_4 ( V_6 -> V_17 ) ;
for ( V_21 = 0 ; V_21 < V_6 -> V_27 ; V_21 ++ )
V_12 [ V_21 ] = V_14 -> V_31 [ V_16 ] ;
return V_21 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_12 )
{
if ( F_13 ( V_4 , V_12 ) )
F_7 ( V_4 -> V_33 , V_2 -> V_9 + V_34 ) ;
V_12 [ 1 ] = F_2 ( V_2 -> V_9 + V_34 ) ;
return V_6 -> V_27 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_12 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
unsigned int V_16 = F_4 ( V_6 -> V_17 ) ;
unsigned int V_35 ;
int V_20 ;
if ( V_16 < 4 )
V_35 = 0x0f ;
else
V_35 = 0xf0 ;
V_20 = F_15 ( V_2 , V_4 , V_6 , V_12 , V_35 ) ;
if ( V_20 )
return V_20 ;
V_14 -> V_25 &= ~ 0x00c0 ;
V_14 -> V_25 |= ( V_4 -> V_36 & 0xf0 ) ? 0x0080 : 0 ;
V_14 -> V_25 |= ( V_4 -> V_36 & 0x0f ) ? 0x0040 : 0 ;
F_7 ( V_14 -> V_25 , V_2 -> V_9 + V_26 ) ;
return V_6 -> V_27 ;
}
static const void * F_16 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
const struct V_39 * V_40 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_17 ( V_41 ) ; V_21 ++ ) {
V_40 = & V_41 [ V_21 ] ;
if ( V_40 -> V_42 == V_38 -> V_43 )
return V_40 ;
}
return NULL ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned long V_7 )
{
struct V_37 * V_38 = F_19 ( V_2 ) ;
const struct V_39 * V_40 ;
struct V_13 * V_14 ;
struct V_3 * V_4 ;
int V_20 ;
V_40 = F_16 ( V_2 , V_38 ) ;
if ( ! V_40 )
return - V_44 ;
V_2 -> V_45 = V_40 ;
V_2 -> V_46 = V_40 -> V_47 ;
V_38 -> V_48 |= V_49 | V_50 ;
V_20 = F_20 ( V_2 , NULL ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_9 = V_38 -> V_51 [ 0 ] -> V_52 ;
V_38 -> V_53 = V_2 ;
V_14 = F_21 ( V_2 , sizeof( * V_14 ) ) ;
if ( ! V_14 )
return - V_54 ;
V_20 = F_22 ( V_2 , 3 ) ;
if ( V_20 )
return V_20 ;
V_4 = & V_2 -> V_55 [ 0 ] ;
V_4 -> type = V_56 ;
V_4 -> V_57 = V_58 | V_59 | V_60 | V_61 ;
V_4 -> V_62 = 16 ;
V_4 -> V_63 = 0xffff ;
V_4 -> V_64 = & V_65 ;
V_4 -> V_66 = 16 ;
V_4 -> V_67 = F_3 ;
V_4 = & V_2 -> V_55 [ 1 ] ;
if ( V_40 -> V_68 ) {
V_4 -> type = V_69 ;
V_4 -> V_57 = V_70 ;
V_4 -> V_62 = V_40 -> V_68 ;
V_4 -> V_63 = 0xffff ;
V_4 -> V_64 = & V_71 ;
V_4 -> V_72 = & F_9 ;
V_4 -> V_67 = & F_11 ;
} else {
V_4 -> type = V_73 ;
}
V_4 = & V_2 -> V_55 [ 2 ] ;
V_4 -> type = V_74 ;
V_4 -> V_57 = V_58 | V_70 ;
V_4 -> V_62 = 8 ;
V_4 -> V_63 = 1 ;
V_4 -> V_64 = & V_75 ;
V_4 -> V_76 = F_12 ;
V_4 -> V_77 = F_14 ;
return 0 ;
}
static int F_23 ( struct V_37 * V_38 )
{
return F_24 ( V_38 , & V_78 ) ;
}
