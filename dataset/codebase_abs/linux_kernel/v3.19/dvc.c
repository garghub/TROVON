static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 [ V_6 ] ;
T_1 V_7 = 0 ;
T_1 V_8 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_4 -> V_8 . V_10 . V_11 ; V_9 ++ )
V_8 |= ( ! ! V_4 -> V_8 . V_10 . V_5 [ V_9 ] ) << V_9 ;
F_3 ( V_2 , V_12 , 0 ) ;
if ( V_4 -> V_13 . V_5 ) {
V_7 |= 0x10 ;
for ( V_9 = 0 ; V_9 < V_6 ; V_9 ++ )
V_5 [ V_9 ] = V_4 -> V_14 . V_10 . V_15 ;
F_3 ( V_2 , V_16 , 0xff ) ;
F_3 ( V_2 , V_17 , V_4 -> V_18 . V_5 << 8 |
V_4 -> V_19 . V_5 ) ;
F_3 ( V_2 , V_20 ,
0x3ff - ( V_4 -> V_14 . V_5 [ 0 ] >> 13 ) ) ;
} else {
for ( V_9 = 0 ; V_9 < V_6 ; V_9 ++ )
V_5 [ V_9 ] = V_4 -> V_14 . V_5 [ V_9 ] ;
}
V_7 |= 0x100 ;
F_3 ( V_2 , V_21 , V_5 [ 0 ] ) ;
F_3 ( V_2 , V_22 , V_5 [ 1 ] ) ;
if ( V_8 ) {
V_7 |= 0x1 ;
F_3 ( V_2 , V_23 , V_8 ) ;
}
F_3 ( V_2 , V_24 , V_7 ) ;
F_3 ( V_2 , V_12 , 1 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_2 ) ;
struct V_29 * V_30 = F_6 ( V_28 ) ;
F_7 ( V_30 , L_1 ,
F_8 ( V_2 ) , F_9 ( V_2 ) ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_31 ,
struct V_25 * V_26 )
{
struct V_3 * V_4 = F_2 ( V_31 ) ;
struct V_32 * V_33 = F_11 ( V_31 ) ;
struct V_27 * V_28 = F_5 ( V_31 ) ;
struct V_1 * V_34 = F_12 ( V_33 ) ;
struct V_29 * V_30 = F_6 ( V_28 ) ;
int V_35 = F_9 ( V_31 ) ;
int V_36 = F_9 ( V_34 ) ;
T_1 V_37 [] = {
[ 0 ] = 0x30000 ,
[ 1 ] = 0x30001 ,
[ 2 ] = 0x40000 ,
[ 3 ] = 0x10000 ,
[ 4 ] = 0x20000 ,
[ 5 ] = 0x40100
} ;
if ( V_36 >= F_13 ( V_37 ) ) {
F_14 ( V_30 , L_2 , V_35 , V_36 ) ;
return - V_38 ;
}
F_15 ( V_4 -> V_39 ) ;
F_3 ( V_31 , V_40 , V_37 [ V_36 ] ) ;
F_3 ( V_31 , V_41 , 0 ) ;
F_3 ( V_31 , V_41 , 1 ) ;
F_3 ( V_31 , V_42 , 1 ) ;
F_3 ( V_31 , V_43 , F_16 ( V_31 ) ) ;
F_1 ( V_31 ) ;
F_3 ( V_31 , V_42 , 0 ) ;
F_17 ( V_26 , V_31 , V_33 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_19 ( V_4 -> V_39 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
F_3 ( V_2 , V_44 , 0x10 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
F_3 ( V_2 , V_44 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_45 * V_46 )
{
struct V_32 * V_33 = F_11 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_47 ;
V_47 = F_23 ( V_2 , V_26 , V_46 ,
F_24 ( V_26 , V_33 ) ?
L_3 : L_4 ,
F_1 ,
& V_4 -> V_14 , 0x00800000 - 1 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_23 ( V_2 , V_26 , V_46 ,
F_24 ( V_26 , V_33 ) ?
L_5 : L_6 ,
F_1 ,
& V_4 -> V_8 , 1 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_25 ( V_2 , V_26 , V_46 ,
F_24 ( V_26 , V_33 ) ?
L_7 : L_8 ,
F_1 ,
& V_4 -> V_13 , 1 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_26 ( V_2 , V_26 , V_46 ,
F_24 ( V_26 , V_33 ) ?
L_9 : L_10 ,
& V_4 -> V_18 ,
F_1 ,
V_48 , F_13 ( V_48 ) ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_26 ( V_2 , V_26 , V_46 ,
F_24 ( V_26 , V_33 ) ?
L_11 : L_12 ,
& V_4 -> V_19 ,
F_1 ,
V_48 , F_13 ( V_48 ) ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
struct V_1 * F_27 ( struct V_27 * V_28 , int V_49 )
{
if ( F_28 ( V_49 < 0 || V_49 >= F_29 ( V_28 ) ) )
V_49 = 0 ;
return & ( (struct V_3 * ) ( V_28 -> V_4 ) + V_49 ) -> V_2 ;
}
static void F_30 ( struct V_50 * V_51 ,
const struct V_52 * V_53 ,
struct V_27 * V_28 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 = F_31 ( V_28 ) ;
struct V_29 * V_30 = & V_51 -> V_30 ;
int V_60 ;
if ( ! V_53 )
return;
V_55 = F_32 ( V_30 -> V_61 , L_13 ) ;
if ( ! V_55 )
return;
V_60 = F_33 ( V_55 ) ;
if ( ! V_60 )
goto V_62;
V_57 = F_34 ( V_30 ,
sizeof( struct V_56 ) * V_60 ,
V_63 ) ;
if ( ! V_57 ) {
F_14 ( V_30 , L_14 ) ;
goto V_62;
}
V_59 -> V_57 = V_57 ;
V_59 -> V_64 = V_60 ;
V_62:
F_35 ( V_55 ) ;
}
int F_36 ( struct V_50 * V_51 ,
const struct V_52 * V_53 ,
struct V_27 * V_28 )
{
struct V_58 * V_59 = F_31 ( V_28 ) ;
struct V_29 * V_30 = F_6 ( V_28 ) ;
struct V_3 * V_4 ;
struct V_39 * V_39 ;
char V_65 [ V_66 ] ;
int V_9 , V_60 ;
F_30 ( V_51 , V_53 , V_28 ) ;
V_60 = V_59 -> V_64 ;
if ( ! V_60 )
return 0 ;
if ( F_37 ( V_28 ) ) {
F_38 ( V_30 , L_15 ) ;
return - V_38 ;
}
V_4 = F_34 ( V_30 , sizeof( * V_4 ) * V_60 , V_63 ) ;
if ( ! V_4 ) {
F_14 ( V_30 , L_16 ) ;
return - V_67 ;
}
V_28 -> V_68 = V_60 ;
V_28 -> V_4 = V_4 ;
F_39 (dvc, priv, i) {
snprintf ( V_65 , V_66 , L_17 ,
V_69 , V_9 ) ;
V_39 = F_40 ( V_30 , V_65 ) ;
if ( F_41 ( V_39 ) )
return F_42 ( V_39 ) ;
V_4 -> V_59 = & V_59 -> V_57 [ V_9 ] ;
V_4 -> V_39 = V_39 ;
F_43 ( V_28 , & V_4 -> V_2 , & V_70 , V_71 , V_9 ) ;
F_7 ( V_30 , L_18 , V_9 ) ;
}
return 0 ;
}
