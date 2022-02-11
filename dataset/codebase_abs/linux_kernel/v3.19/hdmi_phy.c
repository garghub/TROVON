void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#define F_2 ( T_1 ) seq_printf(s, "%-35s %08x\n", #r,\
hdmi_read_reg(phy->base, r))
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
F_2 ( V_8 ) ;
if ( V_9 -> V_10 )
F_2 ( V_11 ) ;
}
int F_3 ( struct V_1 * V_2 , const T_2 * V_12 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 += 2 ) {
T_3 V_14 , V_15 ;
int V_16 , V_17 ;
V_16 = V_12 [ V_13 ] ;
V_17 = V_12 [ V_13 + 1 ] ;
if ( V_16 < 0 || V_16 >= 8 )
return - V_18 ;
if ( V_17 < 0 || V_17 >= 8 )
return - V_18 ;
if ( V_16 & 1 ) {
if ( V_17 != V_16 - 1 )
return - V_18 ;
V_15 = 1 ;
} else {
if ( V_17 != V_16 + 1 )
return - V_18 ;
V_15 = 0 ;
}
V_14 = V_16 / 2 ;
V_2 -> V_19 [ V_14 ] = V_13 / 2 ;
V_2 -> V_20 [ V_14 ] = V_15 ;
}
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
static const T_4 V_21 [] = {
0x0123 ,
0x0132 ,
0x0312 ,
0x0321 ,
0x0231 ,
0x0213 ,
0x1023 ,
0x1032 ,
0x3012 ,
0x3021 ,
0x2031 ,
0x2013 ,
0x1203 ,
0x1302 ,
0x3102 ,
0x3201 ,
0x2301 ,
0x2103 ,
0x1230 ,
0x1320 ,
0x3120 ,
0x3210 ,
0x2310 ,
0x2130 ,
} ;
T_4 V_22 = 0 ;
int V_13 ;
unsigned V_23 ;
T_4 V_24 = 0 ;
for ( V_13 = 0 ; V_13 < 4 ; ++ V_13 )
V_22 |= V_2 -> V_19 [ V_13 ] << ( ( 3 - V_13 ) * 4 ) ;
V_24 |= V_2 -> V_20 [ 0 ] << 0 ;
V_24 |= V_2 -> V_20 [ 1 ] << 3 ;
V_24 |= V_2 -> V_20 [ 2 ] << 2 ;
V_24 |= V_2 -> V_20 [ 3 ] << 1 ;
for ( V_13 = 0 ; V_13 < F_5 ( V_21 ) ; ++ V_13 )
if ( V_21 [ V_13 ] == V_22 )
break;
if ( F_6 ( V_13 == F_5 ( V_21 ) ) )
V_13 = 0 ;
V_23 = V_13 ;
F_7 ( V_2 -> V_25 , V_8 , V_23 , 26 , 22 ) ;
F_7 ( V_2 -> V_25 , V_8 , V_24 , 30 , 27 ) ;
}
int F_8 ( struct V_1 * V_2 , unsigned long V_26 ,
unsigned long V_27 )
{
T_3 V_28 ;
F_9 ( V_2 -> V_25 , V_5 ) ;
if ( V_9 -> V_10 )
F_7 ( V_2 -> V_25 , V_11 , 1 , 11 , 11 ) ;
if ( V_26 != V_27 )
V_28 = 0 ;
else if ( V_26 / 10 < V_9 -> V_29 )
V_28 = 1 ;
else
V_28 = 2 ;
F_7 ( V_2 -> V_25 , V_5 , V_28 , 31 , 30 ) ;
F_10 ( V_2 -> V_25 , V_6 , 0xF0000000 ) ;
if ( V_9 -> V_30 )
F_7 ( V_2 -> V_25 , V_7 , 0xB , 3 , 0 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_31 * V_32 )
{
struct V_33 * V_34 ;
const struct V_33 * V_35 ;
V_34 = F_12 ( & V_32 -> V_36 , sizeof( * V_34 ) , V_37 ) ;
if ( ! V_34 ) {
F_13 ( & V_32 -> V_36 , L_1 ) ;
return - V_38 ;
}
switch ( F_14 () ) {
case V_39 :
case V_40 :
case V_41 :
V_35 = & V_42 ;
break;
case V_43 :
V_35 = & V_44 ;
break;
default:
return - V_45 ;
}
memcpy ( V_34 , V_35 , sizeof( * V_34 ) ) ;
V_9 = V_34 ;
return 0 ;
}
int F_15 ( struct V_31 * V_32 , struct V_1 * V_2 )
{
int T_1 ;
struct V_46 * V_47 ;
T_1 = F_11 ( V_32 ) ;
if ( T_1 )
return T_1 ;
V_47 = F_16 ( V_32 , V_48 , L_2 ) ;
if ( ! V_47 ) {
F_17 ( L_3 ) ;
return - V_18 ;
}
V_2 -> V_25 = F_18 ( & V_32 -> V_36 , V_47 ) ;
if ( F_19 ( V_2 -> V_25 ) ) {
F_17 ( L_4 ) ;
return F_20 ( V_2 -> V_25 ) ;
}
return 0 ;
}
