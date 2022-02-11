static int F_1 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned short V_4 )
{
unsigned long V_5 ;
F_2 ( V_4 & 0xff , V_2 -> V_6 + F_3 ( 0 ) ) ;
F_2 ( ( V_4 >> 8 ) & 0xff , V_2 -> V_6 + F_3 ( 1 ) ) ;
F_2 ( V_3 , V_2 -> V_6 + F_3 ( 2 ) ) ;
F_2 ( 0 , V_2 -> V_6 + F_3 ( 3 ) ) ;
V_5 = V_7 + F_4 ( V_8 ) ;
do {
if ( F_5 ( V_2 -> V_6 + F_6 ( 2 ) ) == V_3 ) {
return F_5 ( V_2 -> V_6 + F_6 ( 0 ) ) |
( F_5 ( V_2 -> V_6 + F_6 ( 1 ) ) << 8 ) ;
}
F_7 () ;
} while ( F_8 ( V_7 , V_5 ) );
return - V_9 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned short V_4 )
{
int V_10 ;
int V_11 ;
if ( F_5 ( V_2 -> V_6 + F_6 ( 2 ) ) == V_3 ) {
V_11 = F_1 ( V_2 , V_12 , 0 ) ;
if ( V_11 < 0 ) {
V_11 = F_1 ( V_2 , V_12 , 0 ) ;
if ( V_11 < 0 )
return - V_13 ;
}
}
for ( V_10 = 0 ; V_10 < V_14 ; V_10 ++ ) {
V_11 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_11 >= 0 )
return V_11 ;
}
return - V_13 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
unsigned int * V_19 )
{
V_19 [ 1 ] = F_5 ( V_2 -> V_6 + F_6 ( 3 ) ) ;
return V_18 -> V_20 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
unsigned int * V_19 )
{
int V_11 ;
if ( F_12 ( V_16 , V_19 ) ) {
V_11 = F_9 ( V_2 , V_21 , V_16 -> V_22 ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_19 [ 1 ] = V_16 -> V_22 ;
return V_18 -> V_20 ;
}
static int F_13 ( unsigned int V_23 , unsigned int V_24 )
{
unsigned int V_25 ;
switch ( V_23 ) {
case V_26 :
V_25 = F_14 ( V_24 , V_27 ) ;
break;
case V_28 :
V_25 = F_15 ( V_24 , V_27 ) ;
break;
case V_29 :
V_25 = V_24 / V_27 ;
default:
return - V_30 ;
}
if ( V_25 < 1 )
V_25 = 1 ;
if ( V_25 > 0xffff )
V_25 = 0xffff ;
return V_25 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned int V_31 , bool V_32 )
{
int V_11 ;
V_11 = F_9 ( V_2 , V_33 , V_34 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_32 )
V_11 |= F_17 ( V_31 ) ;
else
V_11 &= ~ F_17 ( V_31 ) ;
return F_9 ( V_2 , V_34 , V_11 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
unsigned int * V_19 )
{
unsigned int V_31 = F_19 ( V_18 -> V_35 ) ;
int V_36 ;
int V_37 ;
int V_11 ;
switch ( V_19 [ 0 ] ) {
case V_38 :
V_11 = F_16 ( V_2 , V_31 , false ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_19 [ 1 ] > 0xffff )
return - V_30 ;
V_11 = F_9 ( V_2 , F_20 ( V_31 ) , V_19 [ 1 ] ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_16 ( V_2 , V_31 , true ) ;
if ( V_11 < 0 )
return V_11 ;
break;
case V_39 :
V_11 = F_16 ( V_2 , V_31 , false ) ;
if ( V_11 < 0 )
return V_11 ;
break;
case V_40 :
V_11 = F_16 ( V_2 , V_31 , false ) ;
if ( V_11 < 0 )
return V_11 ;
V_36 = F_13 ( V_19 [ 1 ] , V_19 [ 2 ] ) ;
V_37 = F_13 ( V_19 [ 3 ] , V_19 [ 4 ] ) ;
if ( V_36 < 0 || V_37 < 0 )
return - V_30 ;
if ( ( V_36 * V_27 ) != V_19 [ 2 ] ||
( V_37 * V_27 ) != V_19 [ 4 ] ) {
V_19 [ 2 ] = V_36 * V_27 ;
V_19 [ 4 ] = V_37 * V_27 ;
return - V_41 ;
}
V_11 = F_9 ( V_2 , F_21 ( V_31 ) , V_36 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( V_2 , F_22 ( V_31 ) , V_37 ) ;
if ( V_11 < 0 )
return V_11 ;
break;
case V_42 :
V_36 = F_9 ( V_2 , V_33 ,
F_21 ( V_31 ) ) ;
V_37 = F_9 ( V_2 , V_33 ,
F_22 ( V_31 ) ) ;
if ( V_36 < 0 || V_37 < 0 )
return - V_13 ;
V_19 [ 1 ] = V_36 * V_27 ;
V_19 [ 2 ] = V_37 * V_27 ;
break;
case V_43 :
V_11 = F_9 ( V_2 , V_33 ,
V_34 ) ;
if ( V_11 < 0 )
return V_11 ;
V_19 [ 1 ] = ( V_11 & F_17 ( V_31 ) ) ? 1 : 0 ;
break;
default:
return - V_30 ;
}
return V_18 -> V_20 ;
}
static void F_23 ( struct V_1 * V_2 )
{
int V_44 ;
F_2 ( 0 , V_2 -> V_6 + F_24 ( 0 ) ) ;
F_2 ( 0 , V_2 -> V_6 + F_24 ( 1 ) ) ;
F_2 ( 0 , V_2 -> V_6 + F_24 ( 3 ) ) ;
F_9 ( V_2 , V_45 , 0 ) ;
F_9 ( V_2 , V_46 , 0 ) ;
F_9 ( V_2 , V_47 , 0 ) ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ ) {
F_9 ( V_2 , F_25 ( V_44 ) , 0x8000 ) ;
F_9 ( V_2 , F_26 ( V_44 ) , 0x0000 ) ;
}
F_9 ( V_2 , V_48 , 0xff ) ;
F_9 ( V_2 , V_49 , 0 ) ;
F_9 ( V_2 , V_50 , 0 ) ;
F_9 ( V_2 , V_51 , 0 ) ;
F_9 ( V_2 , V_52 , 0 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned long V_53 )
{
struct V_54 * V_55 = F_28 ( V_2 ) ;
struct V_15 * V_16 ;
int V_11 ;
V_11 = F_29 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_6 = F_30 ( V_55 , 0 ) ;
F_23 ( V_2 ) ;
V_11 = F_31 ( V_2 , 4 ) ;
if ( V_11 )
return V_11 ;
V_16 = & V_2 -> V_56 [ 0 ] ;
V_16 -> type = V_57 ;
V_16 -> V_58 = V_59 ;
V_16 -> V_60 = 8 ;
V_16 -> V_61 = 1 ;
V_16 -> V_62 = & V_63 ;
V_16 -> V_64 = F_10 ;
V_16 = & V_2 -> V_56 [ 1 ] ;
V_16 -> type = V_65 ;
V_16 -> V_58 = V_66 ;
V_16 -> V_60 = 8 ;
V_16 -> V_61 = 1 ;
V_16 -> V_62 = & V_63 ;
V_16 -> V_64 = F_11 ;
V_11 = F_9 ( V_2 , V_67 , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_16 -> V_22 = V_11 ;
V_16 = & V_2 -> V_56 [ 2 ] ;
V_16 -> type = V_68 ;
V_16 -> V_58 = V_69 ;
V_16 -> V_60 = 2 ;
V_16 -> V_70 = F_18 ;
V_16 = & V_2 -> V_56 [ 3 ] ;
V_16 -> type = V_71 ;
return 0 ;
}
static int F_32 ( struct V_54 * V_2 ,
const struct V_72 * V_73 )
{
return F_33 ( V_2 , & V_74 , V_73 -> V_75 ) ;
}
