static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
V_2 -> V_4 = F_2 ( V_3 [ V_5 ] ) ;
V_2 -> V_6 = F_2 ( V_3 [ V_7 ] ) ;
if ( V_3 [ V_8 ] & V_9 ) {
V_2 -> V_10 = F_2 ( V_3 [ V_8 ] & 0x0f ) ;
if ( V_3 [ V_8 ] & V_11 )
V_2 -> V_10 += 12 ;
} else {
V_2 -> V_10 = F_2 ( V_3 [ V_8 ] & 0x3f ) ;
}
V_2 -> V_12 = F_2 ( V_3 [ V_13 ] ) ;
V_2 -> V_14 = F_2 ( V_3 [ V_15 ] ) - 1 ;
V_2 -> V_16 = F_2 ( V_3 [ V_17 ] ) - 1 ;
V_2 -> V_18 = F_2 ( V_3 [ V_19 ] ) + 100 ;
}
static int F_3 ( T_1 * V_3 , struct V_1 * V_2 )
{
if ( V_2 -> V_18 < 100 )
return - V_20 ;
V_3 [ V_5 ] = F_4 ( V_2 -> V_4 ) ;
V_3 [ V_7 ] = F_4 ( V_2 -> V_6 ) ;
V_3 [ V_8 ] = F_4 ( V_2 -> V_10 ) ;
V_3 [ V_13 ] = F_4 ( V_2 -> V_12 ) ;
V_3 [ V_17 ] = F_4 ( V_2 -> V_16 + 1 ) ;
V_3 [ V_19 ] = F_4 ( V_2 -> V_18 - 100 ) ;
V_3 [ V_15 ] = F_4 ( V_2 -> V_14 + 1 ) ;
return 0 ;
}
static int F_5 ( struct V_21 * V_21 )
{
T_1 V_3 [ V_22 ] ;
static const T_1 V_23 [ V_22 ] = { 0x80 , 0x80 , 0x80 , 0xf8 ,
0xc0 , 0x60 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x60 , 0x7c } ;
int V_24 , V_25 ;
V_24 = F_6 ( V_21 , 0 , V_3 , V_22 ) ;
if ( V_24 )
return V_24 ;
for ( V_25 = 0 ; V_25 < V_22 ; ++ V_25 ) {
if ( V_3 [ V_25 ] & V_23 [ V_25 ] )
return - V_26 ;
}
return 0 ;
}
static int F_7 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
struct V_29 * V_30 = F_8 ( V_28 ) ;
T_1 V_3 [ V_31 ] ;
int V_24 ;
F_9 ( & V_30 -> V_32 ) ;
V_24 = F_6 ( V_30 -> V_21 , V_5 , V_3 ,
V_31 ) ;
F_10 ( & V_30 -> V_32 ) ;
if ( V_24 ) {
F_11 ( V_28 , L_1 , V_33 ) ;
return V_24 ;
}
F_1 ( V_2 , V_3 ) ;
return F_12 ( V_2 ) ;
}
static int F_13 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
struct V_29 * V_30 = F_8 ( V_28 ) ;
T_1 V_3 [ V_31 ] ;
int V_24 ;
V_24 = F_3 ( V_3 , V_2 ) ;
if ( V_24 )
return V_24 ;
F_9 ( & V_30 -> V_32 ) ;
V_24 = F_14 ( V_30 -> V_21 , V_5 , V_3 ,
V_31 ) ;
F_10 ( & V_30 -> V_32 ) ;
if ( V_24 )
F_11 ( V_28 , L_2 , V_33 ) ;
return V_24 ;
}
static int F_15 ( struct V_27 * V_28 , struct V_21 * V_21 )
{
int V_24 ;
V_24 = F_16 ( V_21 , V_34 ,
V_35 , 0 ) ;
if ( V_24 < 0 ) {
F_11 ( V_28 , L_3 ) ;
return V_24 ;
}
V_24 = F_16 ( V_21 , V_36 ,
V_37 , 0 ) ;
if ( V_24 < 0 ) {
F_11 ( V_28 , L_4 ) ;
return V_24 ;
}
V_24 = F_16 ( V_21 , V_36 ,
V_38 , 0 ) ;
if ( V_24 < 0 ) {
F_11 ( V_28 , L_5 ) ;
return V_24 ;
}
return 0 ;
}
static int F_17 ( struct V_39 * V_40 ,
const struct V_41 * V_42 )
{
struct V_27 * V_28 = & V_40 -> V_28 ;
struct V_29 * V_30 ;
struct V_43 * V_44 ;
struct V_21 * V_21 ;
int V_24 ;
if ( ! F_18 ( V_40 -> V_45 , V_46 |
V_47 |
V_48 ) )
return - V_26 ;
V_21 = F_19 ( V_40 , & V_49 ) ;
if ( F_20 ( V_21 ) ) {
V_24 = F_21 ( V_21 ) ;
F_11 ( V_28 , L_6 , V_24 ) ;
return V_24 ;
}
V_24 = F_5 ( V_21 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_15 ( V_28 , V_21 ) ;
if ( V_24 )
return V_24 ;
V_30 = F_22 ( V_28 , sizeof( * V_30 ) , V_50 ) ;
if ( ! V_30 )
return - V_51 ;
F_23 ( & V_30 -> V_32 ) ;
V_30 -> V_21 = V_21 ;
F_24 ( V_28 , V_30 ) ;
V_44 = F_25 ( V_28 , V_52 , & V_53 , V_54 ) ;
if ( F_20 ( V_44 ) )
return F_21 ( V_44 ) ;
return 0 ;
}
