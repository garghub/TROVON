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
struct V_27 * V_28 = F_5 ( V_26 ) ;
F_6 ( V_28 , L_1 ,
F_7 ( V_2 ) , F_8 ( V_2 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_10 ( V_4 -> V_14 ) ;
F_10 ( V_4 -> V_8 ) ;
F_10 ( V_4 -> V_13 ) ;
F_10 ( V_4 -> V_18 ) ;
F_10 ( V_4 -> V_19 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_29 ,
struct V_25 * V_26 )
{
struct V_30 * V_31 = F_12 ( V_29 ) ;
struct V_1 * V_32 = F_13 ( V_31 ) ;
struct V_27 * V_28 = F_5 ( V_26 ) ;
int V_33 = F_8 ( V_29 ) ;
int V_34 = F_8 ( V_32 ) ;
T_1 V_35 [] = {
[ 0 ] = 0x30000 ,
[ 1 ] = 0x30001 ,
[ 2 ] = 0x40000 ,
[ 3 ] = 0x10000 ,
[ 4 ] = 0x20000 ,
[ 5 ] = 0x40100
} ;
if ( V_34 >= F_14 ( V_35 ) ) {
F_15 ( V_28 , L_2 , V_33 , V_34 ) ;
return - V_36 ;
}
F_16 ( V_29 ) ;
F_3 ( V_29 , V_37 , V_35 [ V_34 ] ) ;
F_3 ( V_29 , V_38 , 0 ) ;
F_3 ( V_29 , V_38 , 1 ) ;
F_3 ( V_29 , V_39 , 1 ) ;
F_3 ( V_29 , V_40 , F_17 ( V_29 ) ) ;
F_1 ( V_29 ) ;
F_3 ( V_29 , V_39 , 0 ) ;
F_18 ( V_29 , V_31 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
F_20 ( V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
F_3 ( V_2 , V_41 , 0x10 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
F_3 ( V_2 , V_41 , 0 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_30 * V_31 = F_12 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_44 = F_24 ( V_31 ) ;
int V_45 ;
V_45 = F_25 ( V_2 , V_43 ,
V_44 ?
L_3 : L_4 ,
F_1 ,
& V_4 -> V_14 , 0x00800000 - 1 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_25 ( V_2 , V_43 ,
V_44 ?
L_5 : L_6 ,
F_1 ,
& V_4 -> V_8 , 1 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_26 ( V_2 , V_43 ,
V_44 ?
L_7 : L_8 ,
F_1 ,
& V_4 -> V_13 , 1 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_27 ( V_2 , V_43 ,
V_44 ?
L_9 : L_10 ,
& V_4 -> V_18 ,
F_1 ,
V_46 , F_14 ( V_46 ) ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_27 ( V_2 , V_43 ,
V_44 ?
L_11 : L_12 ,
& V_4 -> V_19 ,
F_1 ,
V_46 , F_14 ( V_46 ) ) ;
if ( V_45 < 0 )
return V_45 ;
return 0 ;
}
struct V_1 * F_28 ( struct V_25 * V_26 , int V_47 )
{
if ( F_29 ( V_47 < 0 || V_47 >= F_30 ( V_26 ) ) )
V_47 = 0 ;
return & ( (struct V_3 * ) ( V_26 -> V_4 ) + V_47 ) -> V_2 ;
}
static void F_31 ( struct V_48 * V_49 ,
const struct V_50 * V_51 ,
struct V_25 * V_26 )
{
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 = F_32 ( V_26 ) ;
struct V_27 * V_28 = & V_49 -> V_28 ;
int V_58 ;
if ( ! V_51 )
return;
V_53 = F_33 ( V_28 -> V_59 , L_13 ) ;
if ( ! V_53 )
return;
V_58 = F_34 ( V_53 ) ;
if ( ! V_58 )
goto V_60;
V_55 = F_35 ( V_28 ,
sizeof( struct V_54 ) * V_58 ,
V_61 ) ;
if ( ! V_55 ) {
F_15 ( V_28 , L_14 ) ;
goto V_60;
}
V_57 -> V_55 = V_55 ;
V_57 -> V_62 = V_58 ;
V_60:
F_36 ( V_53 ) ;
}
int F_37 ( struct V_48 * V_49 ,
const struct V_50 * V_51 ,
struct V_25 * V_26 )
{
struct V_56 * V_57 = F_32 ( V_26 ) ;
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_3 * V_4 ;
struct V_63 * V_63 ;
char V_64 [ V_65 ] ;
int V_9 , V_58 ;
F_31 ( V_49 , V_51 , V_26 ) ;
V_58 = V_57 -> V_62 ;
if ( ! V_58 )
return 0 ;
if ( F_38 ( V_26 ) ) {
F_39 ( V_28 , L_15 ) ;
return - V_36 ;
}
V_4 = F_35 ( V_28 , sizeof( * V_4 ) * V_58 , V_61 ) ;
if ( ! V_4 ) {
F_15 ( V_28 , L_16 ) ;
return - V_66 ;
}
V_26 -> V_67 = V_58 ;
V_26 -> V_4 = V_4 ;
F_40 (dvc, priv, i) {
snprintf ( V_64 , V_65 , L_17 ,
V_68 , V_9 ) ;
V_63 = F_41 ( V_28 , V_64 ) ;
if ( F_42 ( V_63 ) )
return F_43 ( V_63 ) ;
V_4 -> V_57 = & V_57 -> V_55 [ V_9 ] ;
F_44 ( & V_4 -> V_2 , & V_69 ,
V_63 , V_70 , V_9 ) ;
F_6 ( V_28 , L_18 , V_9 ) ;
}
return 0 ;
}
