static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
unsigned long V_10 = V_2 -> V_10 + V_8 ;
V_7 [ 1 ] = F_2 ( V_10 ) ;
if ( V_4 -> V_11 > 8 )
V_7 [ 1 ] |= ( F_2 ( V_10 + 1 ) << 8 ) ;
if ( V_4 -> V_11 > 16 )
V_7 [ 1 ] |= ( F_2 ( V_10 + 2 ) << 16 ) ;
if ( V_4 -> V_11 > 24 )
V_7 [ 1 ] |= ( F_2 ( V_10 + 3 ) << 24 ) ;
return V_6 -> V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
unsigned long V_10 = V_2 -> V_10 + V_8 ;
V_7 [ 1 ] = F_4 ( V_10 ) ;
if ( V_4 -> V_11 > 16 )
V_7 [ 1 ] |= ( F_4 ( V_10 + 2 ) << 16 ) ;
return V_6 -> V_12 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
unsigned long V_10 = V_2 -> V_10 + V_8 ;
if ( F_6 ( V_4 , V_7 ) ) {
F_7 ( V_4 -> V_13 & 0xff , V_10 ) ;
if ( V_4 -> V_11 > 8 )
F_7 ( ( V_4 -> V_13 >> 8 ) & 0xff , V_10 + 1 ) ;
if ( V_4 -> V_11 > 16 )
F_7 ( ( V_4 -> V_13 >> 16 ) & 0xff , V_10 + 2 ) ;
if ( V_4 -> V_11 > 24 )
F_7 ( ( V_4 -> V_13 >> 24 ) & 0xff , V_10 + 3 ) ;
}
V_7 [ 1 ] = V_4 -> V_13 ;
return V_6 -> V_12 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
unsigned long V_10 = V_2 -> V_10 + V_8 ;
if ( F_6 ( V_4 , V_7 ) ) {
F_9 ( V_4 -> V_13 & 0xffff , V_10 ) ;
if ( V_4 -> V_11 > 16 )
F_9 ( ( V_4 -> V_13 >> 16 ) & 0xffff , V_10 + 2 ) ;
}
V_7 [ 1 ] = V_4 -> V_13 ;
return V_6 -> V_12 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned long V_14 )
{
if ( V_14 == V_15 || V_14 == V_16 )
F_9 ( 0 , V_2 -> V_10 + V_17 ) ;
switch ( V_14 ) {
case V_18 :
case V_19 :
case V_20 :
F_7 ( 0 , V_2 -> V_10 + V_21 ) ;
F_7 ( 0x0f , V_2 -> V_10 + V_22 ) ;
F_7 ( 0 , V_2 -> V_10 + V_23 ) ;
break;
case V_24 :
case V_25 :
case V_26 :
F_7 ( 0x88 , V_2 -> V_10 + V_27 ) ;
break;
case V_28 :
case V_29 :
F_7 ( 0x88 , V_2 -> V_10 + F_11 ( 0 ) ) ;
F_7 ( 0x80 , V_2 -> V_10 + F_11 ( 1 ) ) ;
F_7 ( 0x80 , V_2 -> V_10 + F_11 ( 2 ) ) ;
F_7 ( 0x80 , V_2 -> V_10 + F_11 ( 3 ) ) ;
if ( V_14 == V_29 ) {
F_7 ( 0x88 , V_2 -> V_10 + F_12 ( 0 ) ) ;
F_7 ( 0x80 , V_2 -> V_10 + F_12 ( 1 ) ) ;
F_7 ( 0x80 , V_2 -> V_10 + F_12 ( 2 ) ) ;
F_7 ( 0x80 , V_2 -> V_10 + F_12 ( 3 ) ) ;
}
break;
case V_30 :
case V_16 :
F_9 ( 0x08 , V_2 -> V_10 + F_13 ( 0 ) ) ;
F_9 ( 0x08 , V_2 -> V_10 + F_13 ( 1 ) ) ;
if ( V_14 == V_30 ) {
F_9 ( 0x08 , V_2 -> V_10 + F_13 ( 2 ) ) ;
F_9 ( 0x08 , V_2 -> V_10 + F_13 ( 3 ) ) ;
}
break;
case V_31 :
F_9 ( 0x0101 , V_2 -> V_10 + V_32 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned long V_33 )
{
struct V_34 * V_35 = F_15 ( V_2 ) ;
const struct V_36 * V_37 = NULL ;
const struct V_38 * V_39 ;
struct V_3 * V_4 ;
int V_40 , V_41 , V_42 , V_43 ;
if ( V_33 < F_16 ( V_44 ) )
V_37 = & V_44 [ V_33 ] ;
if ( ! V_37 )
return - V_45 ;
V_2 -> V_46 = V_37 ;
V_2 -> V_47 = V_37 -> V_48 ;
V_40 = F_17 ( V_2 ) ;
if ( V_40 )
return V_40 ;
if ( V_33 == V_20 )
V_2 -> V_10 = F_18 ( V_35 , 0 ) ;
else
V_2 -> V_10 = F_18 ( V_35 , 2 ) ;
F_10 ( V_2 , V_33 ) ;
V_40 = F_19 ( V_2 , V_37 -> V_49 ) ;
if ( V_40 )
return V_40 ;
V_41 = 0 ;
for ( V_42 = 0 ; V_42 < V_50 ; V_42 ++ ) {
V_39 = & V_37 -> V_51 [ V_42 ] ;
if ( V_39 -> V_52 ) {
V_4 = & V_2 -> V_53 [ V_41 ++ ] ;
V_4 -> type = V_54 ;
V_4 -> V_55 = V_56 ;
V_4 -> V_11 = V_39 -> V_52 ;
V_4 -> V_57 = 1 ;
V_4 -> V_58 = & V_59 ;
V_4 -> V_60 = V_37 -> V_61
? F_3
: F_1 ;
V_4 -> V_9 = ( void * ) V_39 -> V_62 ;
}
}
for ( V_42 = 0 ; V_42 < V_63 ; V_42 ++ ) {
V_39 = & V_37 -> V_64 [ V_42 ] ;
if ( V_39 -> V_52 ) {
V_4 = & V_2 -> V_53 [ V_41 ++ ] ;
V_4 -> type = V_65 ;
V_4 -> V_55 = V_66 ;
V_4 -> V_11 = V_39 -> V_52 ;
V_4 -> V_57 = 1 ;
V_4 -> V_58 = & V_59 ;
V_4 -> V_60 = V_37 -> V_61
? F_8
: F_5 ;
V_4 -> V_9 = ( void * ) V_39 -> V_62 ;
if ( V_37 -> V_61 ) {
F_9 ( 0 , V_2 -> V_10 + V_39 -> V_62 ) ;
if ( V_4 -> V_11 > 16 )
F_9 ( 0 , V_2 -> V_10 + V_39 -> V_62 + 2 ) ;
} else {
F_7 ( 0 , V_2 -> V_10 + V_39 -> V_62 ) ;
if ( V_4 -> V_11 > 8 )
F_7 ( 0 , V_2 -> V_10 + V_39 -> V_62 + 1 ) ;
if ( V_4 -> V_11 > 16 )
F_7 ( 0 , V_2 -> V_10 + V_39 -> V_62 + 2 ) ;
if ( V_4 -> V_11 > 24 )
F_7 ( 0 , V_2 -> V_10 + V_39 -> V_62 + 3 ) ;
}
}
}
for ( V_42 = 0 ; V_42 < V_67 ; V_42 ++ ) {
V_39 = & V_37 -> V_68 [ V_42 ] ;
for ( V_43 = 0 ; V_43 < V_39 -> V_52 ; V_43 ++ ) {
V_4 = & V_2 -> V_53 [ V_41 ++ ] ;
V_40 = F_20 ( V_2 , V_4 , NULL ,
V_39 -> V_62 + V_43 * V_69 ) ;
if ( V_40 )
return V_40 ;
}
}
if ( V_37 -> V_70 ) {
V_4 = & V_2 -> V_53 [ V_41 ++ ] ;
V_4 -> type = V_54 ;
V_4 -> V_55 = V_56 | V_71 ;
V_4 -> V_11 = 4 ;
V_4 -> V_57 = 1 ;
V_4 -> V_58 = & V_59 ;
V_4 -> V_60 = V_37 -> V_61 ? F_3
: F_1 ;
V_4 -> V_9 = ( void * ) V_37 -> V_70 ;
}
if ( V_37 -> V_72 ) {
V_4 = & V_2 -> V_53 [ V_41 ++ ] ;
V_2 -> V_73 = F_21 ( V_2 -> V_10 +
V_37 -> V_72 ,
0 , V_74 , 0 ) ;
if ( ! V_2 -> V_73 )
return - V_75 ;
F_22 ( V_4 , V_2 -> V_73 ) ;
}
return 0 ;
}
static unsigned long F_23 ( struct V_34 * V_35 ,
unsigned long V_14 )
{
if ( V_14 != V_28 )
return V_14 ;
if ( F_24 ( V_35 ) < 0 )
return V_14 ;
if ( F_25 ( V_35 , 2 , L_1 ) == 0 ) {
unsigned long V_8 = F_18 ( V_35 , 2 ) + 53 ;
F_7 ( 0x05 , V_8 ) ;
if ( ( F_2 ( V_8 ) & 0x07 ) == 0x02 ) {
F_7 ( 0x02 , V_8 ) ;
if ( ( F_2 ( V_8 ) & 0x07 ) == 0x05 )
V_14 = V_29 ;
}
F_26 ( V_35 , 2 ) ;
}
F_27 ( V_35 ) ;
return V_14 ;
}
static int F_28 ( struct V_34 * V_2 ,
const struct V_76 * V_77 )
{
unsigned long V_14 ;
V_14 = F_23 ( V_2 , V_77 -> V_78 ) ;
return F_29 ( V_2 , & V_79 , V_14 ) ;
}
