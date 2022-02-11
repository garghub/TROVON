static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long time ;
unsigned char V_5 = V_6 ;
unsigned char V_7 [ 4 ] ;
struct V_8 V_9 [] = {
{ V_2 -> V_5 , 0 , 1 , & V_5 } ,
{ V_2 -> V_5 , V_10 , 4 , V_7 } ,
} ;
if ( ( F_2 ( V_2 -> V_11 , & V_9 [ 0 ] , 2 ) ) != 2 ) {
F_3 ( & V_2 -> V_12 , L_1 , V_13 ) ;
return - V_14 ;
}
F_4 ( & V_2 -> V_12 ,
L_2 ,
V_13 , V_7 [ 0 ] , V_7 [ 1 ] , V_7 [ 2 ] , V_7 [ 3 ] ) ;
time = ( V_7 [ 3 ] << 24 ) | ( V_7 [ 2 ] << 16 ) | ( V_7 [ 1 ] << 8 ) | V_7 [ 0 ] ;
F_5 ( time , V_4 ) ;
F_4 ( & V_2 -> V_12 , L_3
L_4 ,
V_13 , V_4 -> V_15 , V_4 -> V_16 , V_4 -> V_17 ,
V_4 -> V_18 , V_4 -> V_19 , V_4 -> V_20 , V_4 -> V_21 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_22 )
{
int V_23 ;
unsigned char V_7 [ 6 ] ;
V_7 [ 0 ] = V_6 ;
V_7 [ 1 ] = V_22 & 0x000000FF ;
V_7 [ 2 ] = ( V_22 & 0x0000FF00 ) >> 8 ;
V_7 [ 3 ] = ( V_22 & 0x00FF0000 ) >> 16 ;
V_7 [ 4 ] = ( V_22 & 0xFF000000 ) >> 24 ;
V_7 [ 5 ] = 0 ;
V_23 = F_7 ( V_2 , V_7 , 6 ) ;
if ( V_23 != 6 ) {
F_3 ( & V_2 -> V_12 , L_5 , V_13 , V_23 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_8 ( struct V_24 * V_12 , struct V_3 * V_4 )
{
return F_1 ( F_9 ( V_12 ) , V_4 ) ;
}
static int F_10 ( struct V_24 * V_12 , unsigned long V_22 )
{
return F_6 ( F_9 ( V_12 ) , V_22 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_1 * V_25 )
{
unsigned char V_5 = V_26 ;
struct V_8 V_9 [] = {
{ V_2 -> V_5 , 0 , 1 , & V_5 } ,
{ V_2 -> V_5 , V_10 , 1 , V_25 } ,
} ;
if ( ( F_2 ( V_2 -> V_11 , & V_9 [ 0 ] , 2 ) ) != 2 ) {
F_3 ( & V_2 -> V_12 , L_1 , V_13 ) ;
return - V_14 ;
}
return 0 ;
}
static T_2 F_12 ( struct V_24 * V_12 , struct V_27 * V_28 ,
char * V_7 )
{
struct V_1 * V_2 = F_9 ( V_12 ) ;
T_1 V_29 ;
int V_30 ;
V_30 = F_11 ( V_2 , & V_29 ) ;
if ( V_30 )
return V_30 ;
return sprintf ( V_7 , L_6 , ( V_29 & V_31 )
? L_7 : L_8 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_14 ( V_2 ) ;
if ( V_33 )
F_15 ( V_33 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_34 * V_35 )
{
int V_30 = 0 ;
T_1 V_29 ;
struct V_32 * V_33 ;
F_4 ( & V_2 -> V_12 , L_6 , V_13 ) ;
if ( ! F_17 ( V_2 -> V_11 , V_36 ) )
return - V_37 ;
F_18 ( & V_2 -> V_12 , L_9 V_38 L_10 ) ;
V_33 = F_19 ( V_39 . V_40 . V_41 , & V_2 -> V_12 ,
& V_42 , V_43 ) ;
if ( F_20 ( V_33 ) )
return F_21 ( V_33 ) ;
F_22 ( V_2 , V_33 ) ;
V_30 = F_11 ( V_2 , & V_29 ) ;
if ( V_30 )
goto V_44;
if ( V_29 & V_31 )
F_23 ( & V_2 -> V_12 , L_11
L_12 ) ;
V_30 = F_24 ( & V_2 -> V_12 , & V_45 ) ;
if ( V_30 )
goto V_44;
return 0 ;
V_44:
F_15 ( V_33 ) ;
return V_30 ;
}
