static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , T_2 V_5 )
{
struct V_6 V_7 [] = {
{
. V_8 = V_2 -> V_8 ,
. V_9 = 0 ,
. V_10 = 1 ,
. V_11 = V_4
} ,
{
. V_8 = V_2 -> V_8 ,
. V_9 = V_12 ,
. V_10 = V_5 ,
. V_11 = V_4
}
} ;
int V_13 ;
V_4 [ 0 ] = V_3 ;
V_13 = F_2 ( V_2 -> V_14 , V_7 , F_3 ( V_7 ) ) ;
if ( V_13 != F_3 ( V_7 ) ) {
F_4 ( & V_2 -> V_15 , L_1 ,
V_16 , V_13 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_18 )
{
T_1 V_4 [ 2 ] = { V_3 , V_18 } ;
int V_19 ;
V_19 = F_6 ( V_2 , V_4 , sizeof( V_4 ) ) ;
if ( V_19 != sizeof( V_4 ) ) {
F_4 ( & V_2 -> V_15 ,
L_2 ,
V_16 , V_19 , V_4 [ 0 ] , V_4 [ 1 ] ) ;
return - V_17 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
T_1 V_11 [ V_22 + 1 ] ;
int V_13 ;
V_13 = F_1 ( V_2 , V_23 , V_11 , sizeof( V_11 ) ) ;
if ( V_13 )
return V_13 ;
if ( V_11 [ V_24 ] & ( V_25 | V_26 ) ) {
F_8 ( & V_2 -> V_15 ,
L_3
L_4 ,
V_11 [ V_24 ] & V_25 ? 85 : 75 ) ;
}
F_9 ( & V_2 -> V_15 ,
L_5
L_6
L_7 ,
V_16 ,
V_11 [ V_23 ] ,
V_11 [ V_27 ] ,
V_11 [ V_28 ] ,
V_11 [ V_29 ] ,
V_11 [ V_30 ] ,
V_11 [ V_31 ] ,
V_11 [ V_32 ] ,
V_11 [ V_24 ] ,
V_11 [ V_22 ] ) ;
V_21 -> V_33 = F_10 ( V_11 [ V_23 ] & 0x7F ) ;
V_21 -> V_34 = F_10 ( V_11 [ V_27 ] & 0x7F ) ;
V_21 -> V_35 = F_10 ( V_11 [ V_28 ] & 0x3F ) ;
V_21 -> V_36 = F_10 ( V_11 [ V_29 ] & 0x3F ) ;
V_21 -> V_37 = V_11 [ V_32 ] & 0x07 ;
V_21 -> V_38 = F_10 ( V_11 [ V_30 ] & 0x1F ) - 1 ;
V_21 -> V_39 = F_10 ( V_11 [ V_31 ] ) + 100 ;
F_9 ( & V_2 -> V_15 , L_8
L_9 ,
V_16 ,
V_21 -> V_33 , V_21 -> V_34 , V_21 -> V_35 ,
V_21 -> V_36 , V_21 -> V_38 , V_21 -> V_39 , V_21 -> V_37 ) ;
if ( F_11 ( V_21 ) < 0 )
F_4 ( & V_2 -> V_15 , L_10 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_40 * V_40 = F_13 ( V_2 ) ;
T_2 V_41 ;
int V_13 ;
T_1 V_11 [ V_32 + 1 ] ;
F_9 ( & V_2 -> V_15 , L_8
L_9 ,
V_16 ,
V_21 -> V_33 , V_21 -> V_34 , V_21 -> V_35 ,
V_21 -> V_36 , V_21 -> V_38 , V_21 -> V_39 , V_21 -> V_37 ) ;
if ( ! V_40 -> V_42 ) {
V_13 = F_1 ( V_2 , V_22 , V_11 , 1 ) ;
if ( V_13 )
return V_13 ;
if ( ! ( V_11 [ 0 ] & V_43 ) ) {
F_14 ( & V_2 -> V_15 ,
L_11 ) ;
V_13 = F_5 ( V_2 ,
V_22 ,
V_11 [ 0 ] | V_43 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_1 ( V_2 , V_28 ,
V_11 , 1 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_5 ( V_2 ,
V_28 ,
V_11 [ 0 ] | V_44 ) ;
if ( V_13 )
return V_13 ;
}
V_40 -> V_42 = 1 ;
}
V_11 [ V_23 ] = F_15 ( V_21 -> V_33 ) ;
V_11 [ V_27 ] = F_15 ( V_21 -> V_34 ) ;
V_11 [ V_28 ] = F_15 ( V_21 -> V_35 ) | V_44 ;
V_11 [ V_29 ] = F_15 ( V_21 -> V_36 ) ;
V_11 [ V_30 ] = F_15 ( V_21 -> V_38 + 1 ) ;
V_11 [ V_31 ] = F_15 ( V_21 -> V_39 % 100 ) ;
V_11 [ V_32 ] = V_21 -> V_37 & 0x07 ;
for ( V_41 = 0 ; V_41 < F_3 ( V_11 ) ; V_41 ++ ) {
V_13 = F_5 ( V_2 , V_23 + V_41 ,
V_11 [ V_23 + V_41 ] ) ;
if ( V_13 )
return - V_17 ;
}
return 0 ;
}
static int F_16 ( struct V_45 * V_15 , struct V_20 * V_21 )
{
return F_7 ( F_17 ( V_15 ) , V_21 ) ;
}
static int F_18 ( struct V_45 * V_15 , struct V_20 * V_21 )
{
return F_12 ( F_17 ( V_15 ) , V_21 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_46 * V_47 )
{
struct V_40 * V_40 ;
int V_13 = 0 ;
if ( ! F_20 ( V_2 -> V_14 , V_48 ) )
return - V_49 ;
V_40 = F_21 ( sizeof( struct V_40 ) , V_50 ) ;
if ( ! V_40 )
return - V_51 ;
F_9 ( & V_2 -> V_15 , L_12 V_52 L_13 ) ;
F_22 ( V_2 , V_40 ) ;
V_40 -> V_53 = F_23 ( V_54 . V_55 . V_56 ,
& V_2 -> V_15 ,
& V_57 ,
V_58 ) ;
if ( F_24 ( V_40 -> V_53 ) ) {
V_13 = F_25 ( V_40 -> V_53 ) ;
goto V_59;
}
return 0 ;
V_59:
F_26 ( V_40 ) ;
return V_13 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_40 * V_40 = F_13 ( V_2 ) ;
F_28 ( V_40 -> V_53 ) ;
F_26 ( V_40 ) ;
return 0 ;
}
