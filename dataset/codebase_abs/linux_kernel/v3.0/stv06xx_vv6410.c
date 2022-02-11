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
if ( V_22 [ V_4 ] . V_2 == NULL ) {
V_3 = F_7 ( V_1 ,
V_22 [ V_4 ] . V_23 ,
V_22 [ V_4 ] . V_24 ) ;
} else {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_22 [ V_4 ] . V_24 ; V_25 ++ )
V_3 = F_7 ( V_1 ,
V_22 [ V_4 ] . V_23 + V_25 ,
V_22 [ V_4 ] . V_2 [ V_25 ] ) ;
}
}
if ( V_3 < 0 )
return V_3 ;
V_3 = F_8 ( V_1 , ( V_26 * ) V_27 ,
F_5 ( V_27 ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_9 ( & V_1 -> V_11 ,
V_5 [ V_28 ] ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_10 ( & V_1 -> V_11 ,
V_5 [ V_29 ] ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static void F_11 ( struct V_1 * V_1 )
{
V_1 -> V_30 = NULL ;
F_12 ( V_1 -> V_21 ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
int V_3 ;
struct V_12 * V_12 = & V_1 -> V_11 . V_12 ;
T_3 V_31 = V_12 -> V_13 [ V_1 -> V_11 . V_32 ] . V_31 ;
if ( V_31 & V_33 ) {
F_14 ( V_34 , L_2 ) ;
F_15 ( V_1 , V_35 , 320 - 1 ) ;
F_15 ( V_1 , V_36 , 240 - 1 ) ;
} else {
F_15 ( V_1 , V_35 , 360 - 1 ) ;
F_15 ( V_1 , V_36 , 294 - 1 ) ;
}
if ( V_31 & V_37 ) {
F_14 ( V_34 , L_3 ) ;
F_7 ( V_1 , V_38 , 0x02 ) ;
F_7 ( V_1 , V_39 , 0x06 ) ;
F_7 ( V_1 , V_40 , 0x10 ) ;
} else {
F_7 ( V_1 , V_38 , 0x01 ) ;
F_7 ( V_1 , V_39 , 0x0a ) ;
F_7 ( V_1 , V_40 , 0x20 ) ;
}
V_3 = F_7 ( V_1 , V_41 , V_42 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_15 ( V_1 , V_43 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
F_14 ( V_44 , L_4 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_1 )
{
int V_3 ;
V_3 = F_7 ( V_1 , V_41 , V_45 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_15 ( V_1 , V_43 , V_46 ) ;
if ( V_3 < 0 )
return V_3 ;
F_14 ( V_44 , L_5 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_17 ( struct V_1 * V_1 )
{
V_26 V_4 ;
int V_3 = 0 ;
F_3 ( L_6 ) ;
for ( V_4 = 0 ; V_4 < 0xff && ! V_3 ; V_4 ++ ) {
T_1 V_2 ;
V_3 = F_2 ( V_1 , V_4 , & V_2 ) ;
F_3 ( L_7 , V_4 , V_2 ) ;
}
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_18 ( struct V_11 * V_11 , T_4 * V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
* V_47 = V_5 [ V_48 ] ;
F_14 ( V_49 , L_8 , * V_47 ) ;
return 0 ;
}
static int F_19 ( struct V_11 * V_11 , T_4 V_47 )
{
int V_3 ;
T_1 V_50 ;
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
V_5 [ V_48 ] = V_47 ;
V_3 = F_2 ( V_1 , V_51 , & V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_47 )
V_50 |= V_52 ;
else
V_50 &= ~ V_52 ;
F_14 ( V_49 , L_9 , V_47 ) ;
V_3 = F_15 ( V_1 , V_51 , V_50 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_20 ( struct V_11 * V_11 , T_4 * V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
* V_47 = V_5 [ V_53 ] ;
F_14 ( V_49 , L_10 , * V_47 ) ;
return 0 ;
}
static int F_21 ( struct V_11 * V_11 , T_4 V_47 )
{
int V_3 ;
T_1 V_50 ;
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
V_5 [ V_53 ] = V_47 ;
V_3 = F_2 ( V_1 , V_51 , & V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_47 )
V_50 |= V_54 ;
else
V_50 &= ~ V_54 ;
F_14 ( V_49 , L_11 , V_47 ) ;
V_3 = F_15 ( V_1 , V_51 , V_50 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_22 ( struct V_11 * V_11 , T_4 * V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
* V_47 = V_5 [ V_29 ] ;
F_14 ( V_49 , L_12 , * V_47 ) ;
return 0 ;
}
static int F_10 ( struct V_11 * V_11 , T_4 V_47 )
{
int V_3 ;
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
V_5 [ V_29 ] = V_47 ;
F_14 ( V_49 , L_13 , V_47 ) ;
V_3 = F_15 ( V_1 , V_55 , 0xf0 | ( V_47 & 0xf ) ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_23 ( struct V_11 * V_11 , T_4 * V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
* V_47 = V_5 [ V_28 ] ;
F_14 ( V_49 , L_14 , * V_47 ) ;
return 0 ;
}
static int F_9 ( struct V_11 * V_11 , T_4 V_47 )
{
int V_3 ;
struct V_1 * V_1 = (struct V_1 * ) V_11 ;
T_2 * V_5 = V_1 -> V_21 ;
unsigned int V_56 , V_57 ;
V_5 [ V_28 ] = V_47 ;
V_47 = ( V_47 * V_47 >> 14 ) + V_47 / 4 ;
V_56 = V_47 % V_58 ;
V_57 = F_24 ( 512 , V_47 / V_58 ) ;
F_14 ( V_49 , L_15 ,
V_57 , V_56 ) ;
V_3 = F_15 ( V_1 , V_59 , V_56 >> 8 ) ;
if ( V_3 < 0 )
goto V_60;
V_3 = F_15 ( V_1 , V_61 , V_56 & 0xff ) ;
if ( V_3 < 0 )
goto V_60;
V_3 = F_15 ( V_1 , V_62 , V_57 >> 8 ) ;
if ( V_3 < 0 )
goto V_60;
V_3 = F_15 ( V_1 , V_63 , V_57 & 0xff ) ;
V_60:
return V_3 ;
}
