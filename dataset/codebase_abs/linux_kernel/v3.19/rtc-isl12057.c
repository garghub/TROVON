static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
V_2 -> V_4 = F_2 ( V_3 [ V_5 ] ) ;
V_2 -> V_6 = F_2 ( V_3 [ V_7 ] ) ;
if ( V_3 [ V_8 ] & V_9 ) {
V_2 -> V_10 = F_2 ( V_3 [ V_8 ] & 0x1f ) ;
if ( V_3 [ V_8 ] & V_11 )
V_2 -> V_10 += 12 ;
} else {
V_2 -> V_10 = F_2 ( V_3 [ V_8 ] & 0x3f ) ;
}
V_2 -> V_12 = F_2 ( V_3 [ V_13 ] ) ;
V_2 -> V_14 = F_2 ( V_3 [ V_15 ] ) - 1 ;
V_2 -> V_16 = F_2 ( V_3 [ V_17 ] & 0x1f ) - 1 ;
V_2 -> V_18 = F_2 ( V_3 [ V_19 ] ) + 100 ;
if ( V_3 [ V_17 ] & V_20 )
V_2 -> V_18 += 100 ;
}
static int F_3 ( T_1 * V_3 , struct V_1 * V_2 )
{
T_1 V_21 ;
if ( V_2 -> V_18 < 100 || V_2 -> V_18 > 299 )
return - V_22 ;
V_21 = ( V_2 -> V_18 > 199 ) ? V_20 : 0 ;
V_3 [ V_5 ] = F_4 ( V_2 -> V_4 ) ;
V_3 [ V_7 ] = F_4 ( V_2 -> V_6 ) ;
V_3 [ V_8 ] = F_4 ( V_2 -> V_10 ) ;
V_3 [ V_13 ] = F_4 ( V_2 -> V_12 ) ;
V_3 [ V_17 ] = F_4 ( V_2 -> V_16 + 1 ) | V_21 ;
V_3 [ V_19 ] = F_4 ( V_2 -> V_18 % 100 ) ;
V_3 [ V_15 ] = F_4 ( V_2 -> V_14 + 1 ) ;
return 0 ;
}
static int F_5 ( struct V_23 * V_23 )
{
T_1 V_3 [ V_24 ] ;
static const T_1 V_25 [ V_24 ] = { 0x80 , 0x80 , 0x80 , 0xf8 ,
0xc0 , 0x60 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x60 , 0x7c } ;
int V_26 , V_27 ;
V_26 = F_6 ( V_23 , 0 , V_3 , V_24 ) ;
if ( V_26 )
return V_26 ;
for ( V_27 = 0 ; V_27 < V_24 ; ++ V_27 ) {
if ( V_3 [ V_27 ] & V_25 [ V_27 ] )
return - V_28 ;
}
return 0 ;
}
static int F_7 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
struct V_31 * V_32 = F_8 ( V_30 ) ;
T_1 V_3 [ V_33 ] ;
unsigned int V_34 ;
int V_26 ;
F_9 ( & V_32 -> V_35 ) ;
V_26 = F_10 ( V_32 -> V_23 , V_36 , & V_34 ) ;
if ( V_26 ) {
F_11 ( V_30 , L_1 ,
V_37 , V_26 ) ;
goto V_38;
} else {
if ( V_34 & V_39 ) {
V_26 = - V_40 ;
goto V_38;
}
}
V_26 = F_6 ( V_32 -> V_23 , V_5 , V_3 ,
V_33 ) ;
if ( V_26 )
F_11 ( V_30 , L_2 ,
V_37 , V_26 ) ;
V_38:
F_12 ( & V_32 -> V_35 ) ;
if ( V_26 )
return V_26 ;
F_1 ( V_2 , V_3 ) ;
return F_13 ( V_2 ) ;
}
static int F_14 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
struct V_31 * V_32 = F_8 ( V_30 ) ;
T_1 V_3 [ V_33 ] ;
int V_26 ;
V_26 = F_3 ( V_3 , V_2 ) ;
if ( V_26 )
return V_26 ;
F_9 ( & V_32 -> V_35 ) ;
V_26 = F_15 ( V_32 -> V_23 , V_5 , V_3 ,
V_33 ) ;
if ( V_26 ) {
F_11 ( V_30 , L_3 ,
V_37 , V_26 ) ;
goto V_38;
}
V_26 = F_16 ( V_32 -> V_23 , V_36 ,
V_39 , 0 ) ;
if ( V_26 < 0 )
F_11 ( V_30 , L_4 ,
V_37 , V_26 ) ;
V_38:
F_12 ( & V_32 -> V_35 ) ;
return V_26 ;
}
static int F_17 ( struct V_29 * V_30 , struct V_23 * V_23 )
{
int V_26 ;
V_26 = F_16 ( V_23 , V_41 ,
V_42 , 0 ) ;
if ( V_26 < 0 ) {
F_11 ( V_30 , L_5 ,
V_37 , V_26 ) ;
return V_26 ;
}
V_26 = F_16 ( V_23 , V_36 ,
V_43 , 0 ) ;
if ( V_26 < 0 ) {
F_11 ( V_30 , L_6 ,
V_37 , V_26 ) ;
return V_26 ;
}
return 0 ;
}
static int F_18 ( struct V_44 * V_45 ,
const struct V_46 * V_47 )
{
struct V_29 * V_30 = & V_45 -> V_30 ;
struct V_31 * V_32 ;
struct V_48 * V_49 ;
struct V_23 * V_23 ;
int V_26 ;
if ( ! F_19 ( V_45 -> V_50 , V_51 |
V_52 |
V_53 ) )
return - V_28 ;
V_23 = F_20 ( V_45 , & V_54 ) ;
if ( F_21 ( V_23 ) ) {
V_26 = F_22 ( V_23 ) ;
F_11 ( V_30 , L_7 ,
V_37 , V_26 ) ;
return V_26 ;
}
V_26 = F_5 ( V_23 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_17 ( V_30 , V_23 ) ;
if ( V_26 )
return V_26 ;
V_32 = F_23 ( V_30 , sizeof( * V_32 ) , V_55 ) ;
if ( ! V_32 )
return - V_56 ;
F_24 ( & V_32 -> V_35 ) ;
V_32 -> V_23 = V_23 ;
F_25 ( V_30 , V_32 ) ;
V_49 = F_26 ( V_30 , V_57 , & V_58 , V_59 ) ;
return F_27 ( V_49 ) ;
}
