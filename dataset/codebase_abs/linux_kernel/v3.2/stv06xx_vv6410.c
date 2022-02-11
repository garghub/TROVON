static int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 ;
int V_3 , V_4 ;
T_2 * V_5 ;
V_3 = F_2 ( V_1 , V_6 , & V_2 ) ;
if ( V_3 < 0 )
return - V_7 ;
if ( V_2 == 0x19 ) {
F_3 ( L_1 ) ;
V_5 = F_4 ( F_5 ( V_8 ) * sizeof( T_2 ) ,
V_9 ) ;
if ( ! V_5 )
return - V_10 ;
V_1 -> V_11 . V_12 . V_13 = V_14 ;
V_1 -> V_11 . V_12 . V_15 = F_5 ( V_14 ) ;
V_1 -> V_16 . V_17 = V_8 ;
V_1 -> V_16 . V_18 = F_5 ( V_8 ) ;
for ( V_4 = 0 ; V_4 < V_1 -> V_16 . V_18 ; V_4 ++ )
V_5 [ V_4 ] = V_8 [ V_4 ] . V_19 . V_20 ;
V_1 -> V_21 = V_5 ;
return 0 ;
}
return - V_7 ;
}
static int F_6 ( struct V_1 * V_1 )
{
int V_3 = 0 , V_4 ;
T_2 * V_5 = V_1 -> V_21 ;
for ( V_4 = 0 ; V_4 < F_5 ( V_22 ) ; V_4 ++ ) {
F_7 ( V_1 , V_22 [ V_4 ] . V_23 , V_22 [ V_4 ] . V_2 ) ;
}
if ( V_3 < 0 )
return V_3 ;
V_3 = F_8 ( V_1 , ( V_24 * ) V_25 ,
F_5 ( V_25 ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_9 ( & V_1 -> V_11 ,
V_5 [ V_26 ] ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_10 ( & V_1 -> V_11 ,
V_5 [ V_27 ] ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static void F_11 ( struct V_1 * V_1 )
{
V_1 -> V_28 = NULL ;
F_12 ( V_1 -> V_21 ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
int V_3 ;
struct V_12 * V_12 = & V_1 -> V_11 . V_12 ;
T_3 V_29 = V_12 -> V_13 [ V_1 -> V_11 . V_30 ] . V_29 ;
if ( V_29 & V_31 ) {
F_14 ( V_32 , L_2 ) ;
F_7 ( V_1 , V_33 , 0x02 ) ;
F_7 ( V_1 , V_34 , 0x06 ) ;
F_7 ( V_1 , V_35 , 0x10 ) ;
} else {
F_7 ( V_1 , V_33 , 0x01 ) ;
F_7 ( V_1 , V_34 , 0x0a ) ;
F_7 ( V_1 , V_35 , 0x00 ) ;
}
V_3 = F_7 ( V_1 , V_36 , V_37 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_15 ( V_1 , V_38 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
F_14 ( V_39 , L_3 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_1 )
{
int V_3 ;
V_3 = F_7 ( V_1 , V_36 , V_40 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_15 ( V_1 , V_38 , V_41 ) ;
if ( V_3 < 0 )
return V_3 ;
F_14 ( V_39 , L_4 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_17 ( struct V_1 * V_1 )
{
V_24 V_4 ;
int V_3 = 0 ;
F_3 ( L_5 ) ;
for ( V_4 = 0 ; V_4 < 0xff && ! V_3 ; V_4 ++ ) {
T_1 V_2 ;
V_3 = F_2 ( V_1 , V_4 , & V_2 ) ;
F_3 ( L_6 , V_4 , V_2 ) ;
}
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_18 ( struct V_11 * V_11 , T_4 * V_42 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
* V_42 = V_5 [ V_43 ] ;
F_14 ( V_44 , L_7 , * V_42 ) ;
return 0 ;
}
static int F_19 ( struct V_11 * V_11 , T_4 V_42 )
{
int V_3 ;
T_1 V_45 ;
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
V_5 [ V_43 ] = V_42 ;
V_3 = F_2 ( V_1 , V_46 , & V_45 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_42 )
V_45 |= V_47 ;
else
V_45 &= ~ V_47 ;
F_14 ( V_44 , L_8 , V_42 ) ;
V_3 = F_15 ( V_1 , V_46 , V_45 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_20 ( struct V_11 * V_11 , T_4 * V_42 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
* V_42 = V_5 [ V_48 ] ;
F_14 ( V_44 , L_9 , * V_42 ) ;
return 0 ;
}
static int F_21 ( struct V_11 * V_11 , T_4 V_42 )
{
int V_3 ;
T_1 V_45 ;
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
V_5 [ V_48 ] = V_42 ;
V_3 = F_2 ( V_1 , V_46 , & V_45 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_42 )
V_45 |= V_49 ;
else
V_45 &= ~ V_49 ;
F_14 ( V_44 , L_10 , V_42 ) ;
V_3 = F_15 ( V_1 , V_46 , V_45 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_22 ( struct V_11 * V_11 , T_4 * V_42 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
* V_42 = V_5 [ V_27 ] ;
F_14 ( V_44 , L_11 , * V_42 ) ;
return 0 ;
}
static int F_10 ( struct V_11 * V_11 , T_4 V_42 )
{
int V_3 ;
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
V_5 [ V_27 ] = V_42 ;
F_14 ( V_44 , L_12 , V_42 ) ;
V_3 = F_15 ( V_1 , V_50 , 0xf0 | ( V_42 & 0xf ) ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_23 ( struct V_11 * V_11 , T_4 * V_42 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
* V_42 = V_5 [ V_26 ] ;
F_14 ( V_44 , L_13 , * V_42 ) ;
return 0 ;
}
static int F_9 ( struct V_11 * V_11 , T_4 V_42 )
{
int V_3 ;
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
unsigned int V_51 , V_52 ;
V_5 [ V_26 ] = V_42 ;
V_42 = ( V_42 * V_42 >> 14 ) + V_42 / 4 ;
V_51 = V_42 % V_53 ;
V_52 = F_24 ( 512 , V_42 / V_53 ) ;
F_14 ( V_44 , L_14 ,
V_52 , V_51 ) ;
V_3 = F_15 ( V_1 , V_54 , V_51 >> 8 ) ;
if ( V_3 < 0 )
goto V_55;
V_3 = F_15 ( V_1 , V_56 , V_51 & 0xff ) ;
if ( V_3 < 0 )
goto V_55;
V_3 = F_15 ( V_1 , V_57 , V_52 >> 8 ) ;
if ( V_3 < 0 )
goto V_55;
V_3 = F_15 ( V_1 , V_58 , V_52 & 0xff ) ;
V_55:
return V_3 ;
}
