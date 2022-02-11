static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_3 >= V_2 -> V_4 -> V_5 )
return - V_6 ;
if ( ! V_3 )
return 0 ;
if ( V_3 < 0x41 )
return 600000 + V_3 * 12500 ;
if ( V_3 < 0x71 )
return 1400000 + ( V_3 - 0x40 ) * 25000 ;
return 2600000 + ( V_3 - 0x70 ) * 50000 ;
}
static int F_2 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_3 >= V_2 -> V_4 -> V_5 )
return - V_6 ;
if ( V_3 < 0x10 )
return 1200000 + V_3 * 50000 ;
return 1800000 + ( V_3 - 0x10 ) * 100000 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_3 >= V_2 -> V_4 -> V_5 ||
( V_3 > 0x10 && V_3 < 0x20 ) )
return - V_6 ;
if ( V_3 < 0x11 )
return 900000 + V_3 * 50000 ;
return 1750000 + ( V_3 - 0x20 ) * 50000 ;
}
static int F_4 ( struct V_1 * V_2 ,
int * V_7 , int * V_8 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_6 ( & V_2 -> V_14 , L_1 , V_15 ,
* V_7 , V_2 -> V_4 -> V_7 , V_12 -> V_8 ) ;
if ( * V_8 < * V_7 ||
* V_7 > V_12 -> V_8 || V_2 -> V_4 -> V_7 > * V_8 )
return - V_6 ;
if ( V_2 -> V_4 -> V_5 == 1 )
return 0 ;
if ( * V_8 > V_12 -> V_8 )
* V_8 = V_12 -> V_8 ;
if ( * V_7 < V_2 -> V_4 -> V_7 )
* V_7 = V_2 -> V_4 -> V_7 ;
return * V_7 ;
}
static int F_7 ( int V_16 , int V_17 , int V_18 , int V_19 )
{
int V_20 , V_21 ;
V_20 = F_8 ( V_16 - V_18 , V_19 ) ;
V_21 = V_20 * V_19 + V_18 ;
F_9 ( L_2 , V_15 ,
V_16 , V_17 , V_18 , V_19 , V_20 ) ;
if ( V_21 > V_17 )
return - V_6 ;
return V_20 ;
}
static int F_10 ( struct V_1 * V_2 ,
int V_7 , int V_8 )
{
int V_22 ;
V_22 = F_4 ( V_2 , & V_7 , & V_8 ) ;
if ( V_22 <= 0 )
return V_22 ;
if ( V_7 <= 1400000 )
return F_7 ( V_7 , V_8 , 600000 , 12500 ) ;
if ( V_7 <= 2600000 )
return F_7 ( V_7 , V_8 , 1400000 , 25000 ) + 0x40 ;
return F_7 ( V_7 , V_8 , 2600000 , 50000 ) + 0x70 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_23 )
{
unsigned int V_24 = V_2 -> V_4 -> V_25 ,
V_26 = V_24 << 4 ;
T_1 V_27 ;
switch ( V_23 ) {
case V_28 :
V_27 = V_24 | V_26 ;
break;
case V_29 :
V_27 = V_26 ;
break;
case V_30 :
V_27 = 0 ;
break;
default:
return - V_6 ;
}
return F_12 ( V_2 -> V_31 , V_32 ,
V_26 | V_24 , V_27 ) ;
}
static unsigned int F_13 ( struct V_1 * V_2 )
{
unsigned int V_24 = V_2 -> V_4 -> V_25 ,
V_26 = V_24 << 4 , V_33 = V_24 | V_26 ;
unsigned int V_27 ;
int V_22 = F_14 ( V_2 -> V_31 , V_32 , & V_27 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( ( V_27 & V_33 ) == V_33 )
return V_28 ;
if ( ( V_27 & V_33 ) == V_26 )
return V_29 ;
if ( ! ( V_27 & V_33 ) )
return V_30 ;
return - V_6 ;
}
static int F_15 ( struct V_1 * V_2 ,
int V_7 , int V_8 )
{
int V_22 ;
V_22 = F_4 ( V_2 , & V_7 , & V_8 ) ;
if ( V_22 <= 0 )
return V_22 ;
if ( V_7 <= 1800000 )
return F_7 ( V_7 , V_8 , 1200000 , 50000 ) ;
return F_7 ( V_7 , V_8 , 1800000 , 100000 ) + 0x10 ;
}
static int F_16 ( struct V_1 * V_2 ,
int V_7 , int V_8 )
{
int V_22 ;
V_22 = F_4 ( V_2 , & V_7 , & V_8 ) ;
if ( V_22 <= 0 )
return V_22 ;
if ( V_7 <= 1700000 )
return F_7 ( V_7 , V_8 , 900000 , 50000 ) ;
return F_7 ( V_7 , V_8 , 1750000 , 50000 ) + 0x20 ;
}
static int F_17 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = F_18 ( & V_35 -> V_14 ) ;
struct V_38 * V_38 = F_19 ( V_35 -> V_14 . V_39 ) ;
struct V_40 * V_41 ;
struct V_42 V_43 = { . V_14 = & V_35 -> V_14 ,} ;
struct V_9 * V_10 = NULL ;
struct V_9 * V_44 ;
struct V_1 * V_2 ;
struct V_11 * V_45 ;
int V_22 ;
int V_46 ;
if ( ! V_37 )
F_6 ( & V_35 -> V_14 , L_3 ) ;
V_44 = F_20 ( & V_35 -> V_14 , V_47 *
sizeof( struct V_9 ) , V_48 ) ;
if ( ! V_44 ) {
F_21 ( & V_35 -> V_14 , L_4 ) ;
return - V_49 ;
}
for ( V_46 = 0 , V_45 = V_50 ; V_46 < V_47 ; ++ V_46 , V_45 ++ ) {
V_41 = V_37 ? V_37 -> V_51 [ V_46 ] : NULL ;
if ( ! V_41 )
continue;
V_10 = & V_44 [ V_46 ] ;
V_10 -> V_13 = V_45 ;
V_43 . V_51 = V_41 ;
V_43 . V_52 = V_10 ;
V_43 . V_31 = V_38 -> V_31 ;
V_2 = F_22 ( & V_45 -> V_4 , & V_43 ) ;
if ( F_23 ( V_2 ) ) {
F_21 ( & V_35 -> V_14 , L_5 ,
V_45 -> V_4 . V_53 ) ;
V_22 = F_24 ( V_2 ) ;
goto V_54;
}
V_10 -> V_2 = V_2 ;
}
F_25 ( V_35 , V_44 ) ;
return 0 ;
V_54:
while ( -- V_46 >= 0 )
F_26 ( V_44 [ V_46 ] . V_2 ) ;
return V_22 ;
}
static int F_27 ( struct V_34 * V_35 )
{
struct V_9 * V_44 = F_28 ( V_35 ) ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_47 ; ++ V_46 )
F_26 ( V_44 [ V_46 ] . V_2 ) ;
return 0 ;
}
static int T_2 F_29 ( void )
{
return F_30 ( & V_55 ) ;
}
static void T_3 F_31 ( void )
{
F_32 ( & V_55 ) ;
}
