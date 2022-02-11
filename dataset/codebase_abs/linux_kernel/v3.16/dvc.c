static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = ( 0x00800000 - 1 ) ;
T_1 V_6 [ V_7 ] ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
V_6 [ V_8 ] = V_5 / V_9 * V_4 -> V_10 [ V_8 ] ;
F_3 ( V_2 , V_11 , V_6 [ 0 ] ) ;
F_3 ( V_2 , V_12 , V_6 [ 1 ] ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = F_5 ( V_2 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
F_7 ( V_18 , L_1 , F_8 ( V_2 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_19 ,
struct V_13 * V_14 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
struct V_20 * V_21 = F_10 ( V_19 ) ;
struct V_15 * V_16 = F_5 ( V_19 ) ;
struct V_1 * V_22 = F_11 ( V_21 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
int V_23 = F_12 ( V_19 ) ;
int V_24 = F_12 ( V_22 ) ;
T_1 V_25 [] = {
[ 0 ] = 0x30000 ,
[ 1 ] = 0x30001 ,
[ 2 ] = 0x40000 ,
[ 3 ] = 0x10000 ,
[ 4 ] = 0x20000 ,
[ 5 ] = 0x40100
} ;
if ( V_24 >= F_13 ( V_25 ) ) {
F_14 ( V_18 , L_2 , V_23 , V_24 ) ;
return - V_26 ;
}
F_15 ( V_4 -> V_27 ) ;
F_3 ( V_19 , V_28 , V_25 [ V_24 ] ) ;
F_3 ( V_19 , V_29 , 0 ) ;
F_3 ( V_19 , V_29 , 1 ) ;
F_3 ( V_19 , V_30 , 1 ) ;
F_3 ( V_19 , V_31 , F_16 ( V_19 ) ) ;
F_3 ( V_19 , V_32 , 0x100 ) ;
F_1 ( V_19 ) ;
F_3 ( V_19 , V_30 , 0 ) ;
F_3 ( V_19 , V_33 , 1 ) ;
F_17 ( V_14 , V_19 , V_21 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_19 ( V_4 -> V_27 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
F_3 ( V_2 , V_34 , 0x10 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
F_3 ( V_2 , V_34 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_35 * V_36 ,
struct V_37 * V_38 )
{
V_38 -> type = V_39 ;
V_38 -> V_40 = V_7 ;
V_38 -> V_41 . integer . V_42 = 0 ;
V_38 -> V_41 . integer . V_5 = V_9 ;
return 0 ;
}
static int F_23 ( struct V_35 * V_36 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_24 ( V_36 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
V_44 -> V_41 . integer . V_41 [ V_8 ] = V_4 -> V_10 [ V_8 ] ;
return 0 ;
}
static int F_25 ( struct V_35 * V_36 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_24 ( V_36 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_8 , V_45 = 0 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
if ( V_44 -> V_41 . integer . V_41 [ V_8 ] < 0 ||
V_44 -> V_41 . integer . V_41 [ V_8 ] > V_9 )
return - V_26 ;
V_45 |= ( V_44 -> V_41 . integer . V_41 [ V_8 ] != V_4 -> V_10 [ V_8 ] ) ;
}
if ( V_45 ) {
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
V_4 -> V_10 [ V_8 ] = V_44 -> V_41 . integer . V_41 [ V_8 ] ;
F_1 ( V_2 ) ;
}
return V_45 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_46 * V_47 )
{
struct V_20 * V_21 = F_10 ( V_2 ) ;
struct V_15 * V_16 = F_5 ( V_2 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_48 * V_49 = V_47 -> V_49 -> V_48 ;
struct V_35 * V_36 ;
static struct V_50 V_51 = {
. V_52 = V_53 ,
. V_54 = L_3 ,
. V_55 = F_22 ,
. V_56 = F_23 ,
. V_57 = F_25 ,
} ;
int V_58 ;
if ( ! F_27 ( V_14 , V_21 ) ) {
F_14 ( V_18 , L_4 ,
F_12 ( V_2 ) ) ;
return - V_26 ;
}
V_36 = F_28 ( & V_51 , V_2 ) ;
if ( ! V_36 )
return - V_59 ;
V_58 = F_29 ( V_49 , V_36 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
struct V_1 * F_30 ( struct V_15 * V_16 , int V_60 )
{
if ( F_31 ( V_60 < 0 || V_60 >= F_32 ( V_16 ) ) )
V_60 = 0 ;
return & ( (struct V_3 * ) ( V_16 -> V_4 ) + V_60 ) -> V_2 ;
}
int F_33 ( struct V_61 * V_62 ,
const struct V_63 * V_64 ,
struct V_15 * V_16 )
{
struct V_65 * V_55 = F_34 ( V_16 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_3 * V_4 ;
struct V_27 * V_27 ;
char V_54 [ V_66 ] ;
int V_8 , V_67 ;
V_67 = V_55 -> V_68 ;
if ( ! V_67 )
return 0 ;
if ( F_35 ( V_16 ) ) {
F_36 ( V_18 , L_5 ) ;
return - V_26 ;
}
V_4 = F_37 ( V_18 , sizeof( * V_4 ) * V_67 , V_69 ) ;
if ( ! V_4 ) {
F_14 ( V_18 , L_6 ) ;
return - V_59 ;
}
V_16 -> V_70 = V_67 ;
V_16 -> V_4 = V_4 ;
F_38 (dvc, priv, i) {
snprintf ( V_54 , V_66 , L_7 ,
V_71 , V_8 ) ;
V_27 = F_39 ( V_18 , V_54 ) ;
if ( F_40 ( V_27 ) )
return F_41 ( V_27 ) ;
V_4 -> V_55 = & V_55 -> V_72 [ V_8 ] ;
V_4 -> V_27 = V_27 ;
F_42 ( V_16 , & V_4 -> V_2 , & V_73 , V_74 , V_8 ) ;
F_7 ( V_18 , L_8 , V_8 ) ;
}
return 0 ;
}
