static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 V_7 [ V_8 ] ;
T_1 V_9 = 0 ;
T_1 V_10 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_10 . V_12 . V_13 ; V_11 ++ )
V_10 |= ( ! ! V_6 -> V_10 . V_12 . V_7 [ V_11 ] ) << V_11 ;
F_3 ( V_4 , V_14 , 0 ) ;
if ( V_6 -> V_15 . V_7 ) {
V_9 |= 0x10 ;
for ( V_11 = 0 ; V_11 < V_8 ; V_11 ++ )
V_7 [ V_11 ] = V_6 -> V_16 . V_12 . V_17 ;
F_3 ( V_4 , V_18 , 0xff ) ;
F_3 ( V_4 , V_19 , V_6 -> V_20 . V_7 << 8 |
V_6 -> V_21 . V_7 ) ;
F_3 ( V_4 , V_22 ,
0x3ff - ( V_6 -> V_16 . V_7 [ 0 ] >> 13 ) ) ;
} else {
for ( V_11 = 0 ; V_11 < V_8 ; V_11 ++ )
V_7 [ V_11 ] = V_6 -> V_16 . V_7 [ V_11 ] ;
}
V_9 |= 0x100 ;
F_3 ( V_4 , V_23 , V_7 [ 0 ] ) ;
F_3 ( V_4 , V_24 , V_7 [ 1 ] ) ;
if ( V_10 ) {
V_9 |= 0x1 ;
F_3 ( V_4 , V_25 , V_10 ) ;
}
F_3 ( V_4 , V_26 , V_9 ) ;
F_3 ( V_4 , V_14 , 1 ) ;
}
static int F_4 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_5 ( V_6 -> V_16 ) ;
F_5 ( V_6 -> V_10 ) ;
F_5 ( V_6 -> V_15 ) ;
F_5 ( V_6 -> V_20 ) ;
F_5 ( V_6 -> V_21 ) ;
return 0 ;
}
static int F_6 ( struct V_3 * V_29 ,
struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_3 * V_30 = F_7 ( V_2 ) ;
struct V_31 * V_32 = F_8 ( V_28 ) ;
int V_33 = F_9 ( V_29 ) ;
int V_34 = F_9 ( V_30 ) ;
T_1 V_35 [] = {
[ 0 ] = 0x30000 ,
[ 1 ] = 0x30001 ,
[ 2 ] = 0x40000 ,
[ 3 ] = 0x10000 ,
[ 4 ] = 0x20000 ,
[ 5 ] = 0x40100
} ;
if ( V_34 >= F_10 ( V_35 ) ) {
F_11 ( V_32 , L_1 , V_33 , V_34 ) ;
return - V_36 ;
}
F_12 ( V_29 ) ;
F_3 ( V_29 , V_37 , V_35 [ V_34 ] ) ;
F_3 ( V_29 , V_38 , 0 ) ;
F_3 ( V_29 , V_38 , 1 ) ;
F_3 ( V_29 , V_39 , 1 ) ;
F_3 ( V_29 , V_40 , F_13 ( V_29 , V_2 ) ) ;
F_1 ( V_2 , V_29 ) ;
F_3 ( V_29 , V_39 , 0 ) ;
F_14 ( V_29 , V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_16 ( V_4 ) ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_3 ( V_4 , V_41 , 0x10 ) ;
return 0 ;
}
static int F_18 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_3 ( V_4 , V_41 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_44 = F_20 ( V_2 ) ;
int V_45 ;
V_45 = F_21 ( V_4 , V_2 , V_43 ,
V_44 ?
L_2 : L_3 ,
F_1 ,
& V_6 -> V_16 , 0x00800000 - 1 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_21 ( V_4 , V_2 , V_43 ,
V_44 ?
L_4 : L_5 ,
F_1 ,
& V_6 -> V_10 , 1 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_22 ( V_4 , V_2 , V_43 ,
V_44 ?
L_6 : L_7 ,
F_1 ,
& V_6 -> V_15 , 1 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_23 ( V_4 , V_2 , V_43 ,
V_44 ?
L_8 : L_9 ,
& V_6 -> V_20 ,
F_1 ,
V_46 , F_10 ( V_46 ) ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_23 ( V_4 , V_2 , V_43 ,
V_44 ?
L_10 : L_11 ,
& V_6 -> V_21 ,
F_1 ,
V_46 , F_10 ( V_46 ) ) ;
if ( V_45 < 0 )
return V_45 ;
return 0 ;
}
static struct V_47 * F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_27 * V_28 = F_25 ( V_4 ) ;
return F_26 ( F_27 ( V_28 ) ,
V_4 , L_12 ) ;
}
struct V_3 * F_28 ( struct V_27 * V_28 , int V_48 )
{
if ( F_29 ( V_48 < 0 || V_48 >= F_30 ( V_28 ) ) )
V_48 = 0 ;
return & ( (struct V_5 * ) ( V_28 -> V_6 ) + V_48 ) -> V_4 ;
}
static void F_31 ( struct V_49 * V_50 ,
const struct V_51 * V_52 ,
struct V_27 * V_28 )
{
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 = F_32 ( V_28 ) ;
struct V_31 * V_32 = & V_50 -> V_32 ;
int V_59 ;
if ( ! V_52 )
return;
V_54 = F_33 ( V_32 -> V_60 , L_13 ) ;
if ( ! V_54 )
return;
V_59 = F_34 ( V_54 ) ;
if ( ! V_59 )
goto V_61;
V_56 = F_35 ( V_32 ,
sizeof( struct V_55 ) * V_59 ,
V_62 ) ;
if ( ! V_56 ) {
F_11 ( V_32 , L_14 ) ;
goto V_61;
}
V_58 -> V_56 = V_56 ;
V_58 -> V_63 = V_59 ;
V_61:
F_36 ( V_54 ) ;
}
int F_37 ( struct V_49 * V_50 ,
const struct V_51 * V_52 ,
struct V_27 * V_28 )
{
struct V_57 * V_58 = F_32 ( V_28 ) ;
struct V_31 * V_32 = F_8 ( V_28 ) ;
struct V_5 * V_6 ;
struct V_64 * V_64 ;
char V_65 [ V_66 ] ;
int V_11 , V_59 , V_45 ;
F_31 ( V_50 , V_52 , V_28 ) ;
V_59 = V_58 -> V_63 ;
if ( ! V_59 )
return 0 ;
if ( F_38 ( V_28 ) ) {
F_39 ( V_32 , L_15 ) ;
return - V_36 ;
}
V_6 = F_35 ( V_32 , sizeof( * V_6 ) * V_59 , V_62 ) ;
if ( ! V_6 ) {
F_11 ( V_32 , L_16 ) ;
return - V_67 ;
}
V_28 -> V_68 = V_59 ;
V_28 -> V_6 = V_6 ;
F_40 (dvc, priv, i) {
snprintf ( V_65 , V_66 , L_17 ,
V_69 , V_11 ) ;
V_64 = F_41 ( V_32 , V_65 ) ;
if ( F_42 ( V_64 ) )
return F_43 ( V_64 ) ;
V_6 -> V_58 = & V_58 -> V_56 [ V_11 ] ;
V_45 = F_44 ( V_28 , & V_6 -> V_4 , & V_70 ,
V_64 , V_71 , V_11 ) ;
if ( V_45 )
return V_45 ;
}
return 0 ;
}
void F_45 ( struct V_49 * V_50 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 ;
int V_11 ;
F_40 (dvc, priv, i) {
F_46 ( & V_6 -> V_4 ) ;
}
}
