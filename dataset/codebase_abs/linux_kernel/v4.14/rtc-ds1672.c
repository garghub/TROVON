static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long time ;
unsigned char V_5 = V_6 ;
unsigned char V_7 [ 4 ] ;
struct V_8 V_9 [] = {
{
. V_5 = V_2 -> V_5 ,
. V_10 = 1 ,
. V_7 = & V_5
} ,
{
. V_5 = V_2 -> V_5 ,
. V_11 = V_12 ,
. V_10 = 4 ,
. V_7 = V_7
} ,
} ;
if ( ( F_2 ( V_2 -> V_13 , & V_9 [ 0 ] , 2 ) ) != 2 ) {
F_3 ( & V_2 -> V_14 , L_1 , V_15 ) ;
return - V_16 ;
}
F_4 ( & V_2 -> V_14 ,
L_2 ,
V_15 , V_7 [ 0 ] , V_7 [ 1 ] , V_7 [ 2 ] , V_7 [ 3 ] ) ;
time = ( V_7 [ 3 ] << 24 ) | ( V_7 [ 2 ] << 16 ) | ( V_7 [ 1 ] << 8 ) | V_7 [ 0 ] ;
F_5 ( time , V_4 ) ;
F_4 ( & V_2 -> V_14 , L_3
L_4 ,
V_15 , V_4 -> V_17 , V_4 -> V_18 , V_4 -> V_19 ,
V_4 -> V_20 , V_4 -> V_21 , V_4 -> V_22 , V_4 -> V_23 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_24 )
{
int V_25 ;
unsigned char V_7 [ 6 ] ;
V_7 [ 0 ] = V_6 ;
V_7 [ 1 ] = V_24 & 0x000000FF ;
V_7 [ 2 ] = ( V_24 & 0x0000FF00 ) >> 8 ;
V_7 [ 3 ] = ( V_24 & 0x00FF0000 ) >> 16 ;
V_7 [ 4 ] = ( V_24 & 0xFF000000 ) >> 24 ;
V_7 [ 5 ] = 0 ;
V_25 = F_7 ( V_2 , V_7 , 6 ) ;
if ( V_25 != 6 ) {
F_3 ( & V_2 -> V_14 , L_5 , V_15 , V_25 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_8 ( struct V_26 * V_14 , struct V_3 * V_4 )
{
return F_1 ( F_9 ( V_14 ) , V_4 ) ;
}
static int F_10 ( struct V_26 * V_14 , unsigned long V_24 )
{
return F_6 ( F_9 ( V_14 ) , V_24 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_1 * V_27 )
{
unsigned char V_5 = V_28 ;
struct V_8 V_9 [] = {
{
. V_5 = V_2 -> V_5 ,
. V_10 = 1 ,
. V_7 = & V_5
} ,
{
. V_5 = V_2 -> V_5 ,
. V_11 = V_12 ,
. V_10 = 1 ,
. V_7 = V_27
} ,
} ;
if ( ( F_2 ( V_2 -> V_13 , & V_9 [ 0 ] , 2 ) ) != 2 ) {
F_3 ( & V_2 -> V_14 , L_1 , V_15 ) ;
return - V_16 ;
}
return 0 ;
}
static T_2 F_12 ( struct V_26 * V_14 , struct V_29 * V_30 ,
char * V_7 )
{
struct V_1 * V_2 = F_9 ( V_14 ) ;
T_1 V_31 ;
int V_32 ;
V_32 = F_11 ( V_2 , & V_31 ) ;
if ( V_32 )
return V_32 ;
return sprintf ( V_7 , L_6 , ( V_31 & V_33 )
? L_7 : L_8 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
const struct V_34 * V_35 )
{
int V_32 = 0 ;
T_1 V_31 ;
struct V_36 * V_37 ;
F_4 ( & V_2 -> V_14 , L_6 , V_15 ) ;
if ( ! F_14 ( V_2 -> V_13 , V_38 ) )
return - V_39 ;
V_37 = F_15 ( & V_2 -> V_14 , V_40 . V_41 . V_42 ,
& V_43 , V_44 ) ;
if ( F_16 ( V_37 ) )
return F_17 ( V_37 ) ;
F_18 ( V_2 , V_37 ) ;
V_32 = F_11 ( V_2 , & V_31 ) ;
if ( V_32 ) {
F_19 ( & V_2 -> V_14 , L_9 ) ;
}
if ( V_31 & V_33 )
F_19 ( & V_2 -> V_14 , L_10
L_11 ) ;
V_32 = F_20 ( & V_2 -> V_14 , & V_45 ) ;
if ( V_32 )
F_3 ( & V_2 -> V_14 , L_12 ,
V_45 . V_30 . V_42 ) ;
return 0 ;
}
