static void F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
unsigned int V_5 = ( unsigned int ) F_2 ( V_2 ) ;
V_3 = V_5 & 0x1f ;
V_4 = V_5 >> 5 ;
V_6 [ V_4 ] |= ( 1 << ( 31 - V_3 ) ) ;
F_3 ( & V_7 -> V_8 , V_6 [ V_4 ] ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
unsigned int V_5 = ( unsigned int ) F_2 ( V_2 ) ;
V_3 = V_5 & 0x1f ;
V_4 = V_5 >> 5 ;
V_6 [ V_4 ] &= ~ ( 1 << ( 31 - V_3 ) ) ;
F_3 ( & V_7 -> V_8 , V_6 [ V_4 ] ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_5 = ( unsigned int ) F_2 ( V_2 ) ;
V_3 = V_5 & 0x1f ;
F_3 ( & V_7 -> V_9 , 1 << ( 31 - V_3 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
unsigned int V_5 = ( unsigned int ) F_2 ( V_2 ) ;
V_3 = V_5 & 0x1f ;
V_4 = V_5 >> 5 ;
V_6 [ V_4 ] |= ( 1 << ( 31 - V_3 ) ) ;
F_3 ( & V_7 -> V_8 , V_6 [ V_4 ] ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_10 )
{
if ( V_10 & V_11 ) {
T_1 V_12 = ( unsigned int ) F_2 ( V_2 ) ;
unsigned int V_13 = F_8 ( & V_7 -> V_14 ) ;
if ( ( V_12 & 1 ) == 0 ) {
V_13 |= ( 0x80000000 >> V_12 ) ;
F_3 ( & V_7 -> V_14 , V_13 ) ;
F_9 ( V_2 -> V_15 , V_16 ) ;
}
}
return 0 ;
}
unsigned int F_10 ( void )
{
int V_15 ;
V_15 = F_8 ( & V_7 -> V_17 ) >> 26 ;
if ( V_15 == V_18 )
V_15 = V_19 ;
return F_11 ( V_20 , V_15 ) ;
}
static int F_12 ( struct V_21 * V_22 , unsigned int V_23 ,
T_1 V_12 )
{
F_13 ( L_1 , V_23 , V_12 ) ;
F_14 ( V_23 , & V_24 , V_25 ) ;
return 0 ;
}
static int F_15 ( struct V_21 * V_22 , struct V_26 * V_27 ,
const T_2 * V_28 , unsigned int V_29 ,
T_1 * V_30 , unsigned int * V_31 )
{
static unsigned char V_32 [ 4 ] = {
V_33 ,
V_34 ,
V_35 ,
V_11 ,
} ;
* V_30 = V_28 [ 0 ] ;
if ( V_29 > 1 && V_28 [ 1 ] < 4 )
* V_31 = V_32 [ V_28 [ 1 ] ] ;
else
* V_31 = V_36 ;
return 0 ;
}
int F_16 ( void )
{
struct V_37 V_38 ;
struct V_26 * V_39 ;
int V_40 ;
V_39 = F_17 ( NULL , NULL , L_2 ) ;
if ( V_39 == NULL )
V_39 = F_18 ( NULL , L_3 ) ;
if ( V_39 == NULL ) {
F_19 ( V_41 L_4 ) ;
return - V_42 ;
}
V_40 = F_20 ( V_39 , 0 , & V_38 ) ;
if ( V_40 )
goto V_43;
V_7 = F_21 ( V_38 . V_44 , V_38 . V_45 - V_38 . V_44 + 1 ) ;
if ( V_7 == NULL ) {
V_40 = - V_46 ;
goto V_43;
}
V_20 = F_22 ( V_39 , V_47 ,
64 , & V_48 , 64 ) ;
if ( V_20 == NULL ) {
F_19 ( V_41 L_5 ) ;
V_40 = - V_42 ;
goto V_43;
}
return 0 ;
V_43:
F_23 ( V_39 ) ;
return V_40 ;
}
