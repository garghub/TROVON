static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
const struct V_4 {
int V_5 ;
T_1 V_6 ;
} V_7 [] = {
{ V_8 , 0x0038 } ,
{ V_9 , 0xAB95 } ,
{ V_8 , 0x2038 } ,
{ V_9 , 0xBB22 } ,
{ V_8 , 0x6038 } ,
{ V_9 , 0xFFC5 } ,
{ V_8 , 0x003a } ,
{ V_9 , 0x2002 } ,
} ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < F_2 ( V_7 ) ; V_10 ++ ) {
V_3 = F_3 ( V_2 ,
V_7 [ V_10 ] . V_5 ,
V_7 [ V_10 ] . V_6 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static void F_4 ( struct V_1 * V_2 ,
T_1 V_5 , T_1 V_6 )
{
F_3 ( V_2 , V_8 , V_11 | V_5 ) ;
F_3 ( V_2 , V_9 , V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
T_1 V_5 , T_1 V_12 , T_1 V_6 )
{
int V_13 ;
F_3 ( V_2 , V_14 , V_15 ) ;
V_13 = F_6 ( V_2 , V_14 ) ;
V_13 |= V_16 ;
F_3 ( V_2 , V_14 , V_13 ) ;
V_13 = ( V_12 * V_17 ) | V_5 ;
F_3 ( V_2 , V_8 , V_13 ) ;
F_3 ( V_2 , V_9 , V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_18 , 0x0048 ) ;
F_5 ( V_2 , V_19 , 0x021b ) ;
F_5 ( V_2 , V_20 , 0x0e20 ) ;
F_5 ( V_2 , V_21 , 0x690b ) ;
F_3 ( V_2 , V_22 , 0xd ) ;
F_4 ( V_2 , V_23 , 0x0010 ) ;
F_4 ( V_2 , V_23 , 0x0000 ) ;
F_5 ( V_2 , V_24 , 0xeb19 ) ;
F_5 ( V_2 , V_25 , 0x9a3f ) ;
F_5 ( V_2 , V_26 , 0x7fc0 ) ;
F_5 ( V_2 , V_27 , 0x000b ) ;
F_5 ( V_2 , V_28 , 0x0800 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
return F_7 ( V_2 ) ;
}
static int F_9 ( struct V_1 * V_29 , int V_30 ,
int V_31 , int V_32 )
{
int V_33 , V_3 ;
V_33 = F_6 ( V_29 , V_30 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 &= ~ V_32 ;
V_33 |= V_31 ;
V_3 = F_3 ( V_29 , V_30 , V_33 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_33 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_3 ;
F_3 ( V_2 , V_34 , V_35 ) ;
F_6 ( V_2 , V_34 ) ;
if ( ! ( V_2 -> V_36 & V_37 ) )
return 0 ;
V_3 = F_9 ( V_2 , V_38 ,
V_39 , V_39 ) ;
if ( V_3 < 0 )
return V_3 ;
F_3 ( V_2 , V_40 , 0x0F00 ) ;
F_11 ( 10 ) ;
F_3 ( V_2 , V_40 , 0x0C00 ) ;
F_3 ( V_2 , V_41 , 0x7555 ) ;
V_3 = F_9 ( V_2 , V_38 , V_39 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_3 ;
const struct V_42 {
int V_5 ;
T_1 V_6 ;
} V_43 [] = {
{ V_38 , 0x008b } ,
{ V_44 , 0x01c0 } ,
{ V_40 , 0x7000 } ,
{ V_38 , 0x000f } ,
{ V_44 , 0x20d0 } ,
{ V_38 , 0x000b } ,
} ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < F_2 ( V_43 ) ; V_10 ++ ) {
V_3 = F_3 ( V_2 ,
V_43 [ V_10 ] . V_5 ,
V_43 [ V_10 ] . V_6 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( V_45 ,
F_2 ( V_45 ) ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( V_45 ,
F_2 ( V_45 ) ) ;
}
