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
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_4 -> V_14 ) ;
F_5 ( V_4 -> V_8 ) ;
F_5 ( V_4 -> V_13 ) ;
F_5 ( V_4 -> V_18 ) ;
F_5 ( V_4 -> V_19 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_27 ,
struct V_25 * V_26 )
{
struct V_28 * V_29 = F_7 ( V_27 ) ;
struct V_1 * V_30 = F_8 ( V_29 ) ;
struct V_31 * V_32 = F_9 ( V_26 ) ;
int V_33 = F_10 ( V_27 ) ;
int V_34 = F_10 ( V_30 ) ;
T_1 V_35 [] = {
[ 0 ] = 0x30000 ,
[ 1 ] = 0x30001 ,
[ 2 ] = 0x40000 ,
[ 3 ] = 0x10000 ,
[ 4 ] = 0x20000 ,
[ 5 ] = 0x40100
} ;
if ( V_34 >= F_11 ( V_35 ) ) {
F_12 ( V_32 , L_1 , V_33 , V_34 ) ;
return - V_36 ;
}
F_13 ( V_27 ) ;
F_3 ( V_27 , V_37 , V_35 [ V_34 ] ) ;
F_3 ( V_27 , V_38 , 0 ) ;
F_3 ( V_27 , V_38 , 1 ) ;
F_3 ( V_27 , V_39 , 1 ) ;
F_3 ( V_27 , V_40 , F_14 ( V_27 ) ) ;
F_1 ( V_27 ) ;
F_3 ( V_27 , V_39 , 0 ) ;
F_15 ( V_27 , V_29 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
F_17 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
F_3 ( V_2 , V_41 , 0x10 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
F_3 ( V_2 , V_41 , 0 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_28 * V_29 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_44 = F_21 ( V_29 ) ;
int V_45 ;
V_45 = F_22 ( V_2 , V_43 ,
V_44 ?
L_2 : L_3 ,
F_1 ,
& V_4 -> V_14 , 0x00800000 - 1 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_22 ( V_2 , V_43 ,
V_44 ?
L_4 : L_5 ,
F_1 ,
& V_4 -> V_8 , 1 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_23 ( V_2 , V_43 ,
V_44 ?
L_6 : L_7 ,
F_1 ,
& V_4 -> V_13 , 1 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_24 ( V_2 , V_43 ,
V_44 ?
L_8 : L_9 ,
& V_4 -> V_18 ,
F_1 ,
V_46 , F_11 ( V_46 ) ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_24 ( V_2 , V_43 ,
V_44 ?
L_10 : L_11 ,
& V_4 -> V_19 ,
F_1 ,
V_46 , F_11 ( V_46 ) ) ;
if ( V_45 < 0 )
return V_45 ;
return 0 ;
}
static struct V_47 * F_25 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_26 ( V_2 ) ;
return F_27 ( F_28 ( V_26 ) ,
V_2 , L_12 ) ;
}
struct V_1 * F_29 ( struct V_25 * V_26 , int V_48 )
{
if ( F_30 ( V_48 < 0 || V_48 >= F_31 ( V_26 ) ) )
V_48 = 0 ;
return & ( (struct V_3 * ) ( V_26 -> V_4 ) + V_48 ) -> V_2 ;
}
static void F_32 ( struct V_49 * V_50 ,
const struct V_51 * V_52 ,
struct V_25 * V_26 )
{
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 = F_33 ( V_26 ) ;
struct V_31 * V_32 = & V_50 -> V_32 ;
int V_59 ;
if ( ! V_52 )
return;
V_54 = F_34 ( V_32 -> V_60 , L_13 ) ;
if ( ! V_54 )
return;
V_59 = F_35 ( V_54 ) ;
if ( ! V_59 )
goto V_61;
V_56 = F_36 ( V_32 ,
sizeof( struct V_55 ) * V_59 ,
V_62 ) ;
if ( ! V_56 ) {
F_12 ( V_32 , L_14 ) ;
goto V_61;
}
V_58 -> V_56 = V_56 ;
V_58 -> V_63 = V_59 ;
V_61:
F_37 ( V_54 ) ;
}
int F_38 ( struct V_49 * V_50 ,
const struct V_51 * V_52 ,
struct V_25 * V_26 )
{
struct V_57 * V_58 = F_33 ( V_26 ) ;
struct V_31 * V_32 = F_9 ( V_26 ) ;
struct V_3 * V_4 ;
struct V_64 * V_64 ;
char V_65 [ V_66 ] ;
int V_9 , V_59 , V_45 ;
F_32 ( V_50 , V_52 , V_26 ) ;
V_59 = V_58 -> V_63 ;
if ( ! V_59 )
return 0 ;
if ( F_39 ( V_26 ) ) {
F_40 ( V_32 , L_15 ) ;
return - V_36 ;
}
V_4 = F_36 ( V_32 , sizeof( * V_4 ) * V_59 , V_62 ) ;
if ( ! V_4 ) {
F_12 ( V_32 , L_16 ) ;
return - V_67 ;
}
V_26 -> V_68 = V_59 ;
V_26 -> V_4 = V_4 ;
F_41 (dvc, priv, i) {
snprintf ( V_65 , V_66 , L_17 ,
V_69 , V_9 ) ;
V_64 = F_42 ( V_32 , V_65 ) ;
if ( F_43 ( V_64 ) )
return F_44 ( V_64 ) ;
V_4 -> V_58 = & V_58 -> V_56 [ V_9 ] ;
V_45 = F_45 ( & V_4 -> V_2 , & V_70 ,
V_64 , V_71 , V_9 ) ;
if ( V_45 )
return V_45 ;
}
return 0 ;
}
void F_46 ( struct V_49 * V_50 ,
struct V_25 * V_26 )
{
struct V_3 * V_4 ;
int V_9 ;
F_41 (dvc, priv, i) {
F_47 ( & V_4 -> V_2 ) ;
}
}
