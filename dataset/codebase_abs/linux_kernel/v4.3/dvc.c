static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , 0 ) ;
F_2 ( V_2 , V_3 , 1 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
F_2 ( V_2 , V_5 , V_4 ) ;
}
static void F_4 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
T_1 V_10 [ V_11 ] ;
T_1 V_12 = 0 ;
T_1 V_13 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_9 -> V_13 . V_15 . V_16 ; V_14 ++ )
V_13 |= ( ! ! V_9 -> V_13 . V_15 . V_10 [ V_14 ] ) << V_14 ;
F_2 ( V_2 , V_17 , 0 ) ;
if ( V_9 -> V_18 . V_10 ) {
V_12 |= 0x10 ;
for ( V_14 = 0 ; V_14 < V_11 ; V_14 ++ )
V_10 [ V_14 ] = V_9 -> V_19 . V_15 . V_20 ;
F_2 ( V_2 , V_21 , 0xff ) ;
F_2 ( V_2 , V_22 , V_9 -> V_23 . V_10 << 8 |
V_9 -> V_24 . V_10 ) ;
F_2 ( V_2 , V_25 ,
0x3ff - ( V_9 -> V_19 . V_10 [ 0 ] >> 13 ) ) ;
} else {
for ( V_14 = 0 ; V_14 < V_11 ; V_14 ++ )
V_10 [ V_14 ] = V_9 -> V_19 . V_10 [ V_14 ] ;
}
V_12 |= 0x100 ;
F_2 ( V_2 , V_26 , V_10 [ 0 ] ) ;
F_2 ( V_2 , V_27 , V_10 [ 1 ] ) ;
if ( V_13 ) {
V_12 |= 0x1 ;
F_2 ( V_2 , V_28 , V_13 ) ;
}
F_2 ( V_2 , V_29 , V_12 ) ;
F_2 ( V_2 , V_17 , 1 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_30 * V_31 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
F_7 ( V_9 -> V_19 ) ;
F_7 ( V_9 -> V_13 ) ;
F_7 ( V_9 -> V_18 ) ;
F_7 ( V_9 -> V_23 ) ;
F_7 ( V_9 -> V_24 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_30 * V_31 )
{
F_9 ( V_2 ) ;
F_1 ( V_2 ) ;
F_10 ( V_2 ) ;
F_11 ( V_31 , V_7 ) ;
F_2 ( V_2 , V_32 , F_12 ( V_2 , V_7 ) ) ;
F_4 ( V_7 , V_2 ) ;
F_13 ( V_2 , V_7 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_30 * V_31 )
{
F_15 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_30 * V_31 )
{
F_17 ( V_2 ) ;
F_2 ( V_2 , V_33 , 0x10 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_30 * V_31 )
{
F_2 ( V_2 , V_33 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_34 * V_35 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
int V_36 = F_20 ( V_7 ) ;
int V_37 ;
V_37 = F_21 ( V_2 , V_7 , V_35 ,
V_36 ?
L_1 : L_2 ,
F_4 ,
& V_9 -> V_19 , 0x00800000 - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_21 ( V_2 , V_7 , V_35 ,
V_36 ?
L_3 : L_4 ,
F_4 ,
& V_9 -> V_13 , 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_22 ( V_2 , V_7 , V_35 ,
V_36 ?
L_5 : L_6 ,
F_4 ,
& V_9 -> V_18 , 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_23 ( V_2 , V_7 , V_35 ,
V_36 ?
L_7 : L_8 ,
& V_9 -> V_23 ,
F_4 ,
V_38 , F_24 ( V_38 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_23 ( V_2 , V_7 , V_35 ,
V_36 ?
L_9 : L_10 ,
& V_9 -> V_24 ,
F_4 ,
V_38 , F_24 ( V_38 ) ) ;
if ( V_37 < 0 )
return V_37 ;
return 0 ;
}
static struct V_39 * F_25 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_30 * V_31 = F_26 ( V_2 ) ;
return F_27 ( F_28 ( V_31 ) ,
V_2 , L_11 ) ;
}
struct V_1 * F_29 ( struct V_30 * V_31 , int V_40 )
{
if ( F_30 ( V_40 < 0 || V_40 >= F_31 ( V_31 ) ) )
V_40 = 0 ;
return & ( (struct V_8 * ) ( V_31 -> V_9 ) + V_40 ) -> V_2 ;
}
static void F_32 ( struct V_41 * V_42 ,
const struct V_43 * V_44 ,
struct V_30 * V_31 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 = F_33 ( V_31 ) ;
struct V_51 * V_52 = & V_42 -> V_52 ;
int V_53 ;
if ( ! V_44 )
return;
V_46 = F_34 ( V_52 -> V_54 , L_12 ) ;
if ( ! V_46 )
return;
V_53 = F_35 ( V_46 ) ;
if ( ! V_53 )
goto V_55;
V_48 = F_36 ( V_52 ,
sizeof( struct V_47 ) * V_53 ,
V_56 ) ;
if ( ! V_48 ) {
F_37 ( V_52 , L_13 ) ;
goto V_55;
}
V_50 -> V_48 = V_48 ;
V_50 -> V_57 = V_53 ;
V_55:
F_38 ( V_46 ) ;
}
int F_39 ( struct V_41 * V_42 ,
const struct V_43 * V_44 ,
struct V_30 * V_31 )
{
struct V_49 * V_50 = F_33 ( V_31 ) ;
struct V_51 * V_52 = F_40 ( V_31 ) ;
struct V_8 * V_9 ;
struct V_58 * V_58 ;
char V_59 [ V_60 ] ;
int V_14 , V_53 , V_37 ;
if ( F_41 ( V_31 ) ) {
F_42 ( V_52 , L_14 ) ;
return - V_61 ;
}
F_32 ( V_42 , V_44 , V_31 ) ;
V_53 = V_50 -> V_57 ;
if ( ! V_53 )
return 0 ;
V_9 = F_36 ( V_52 , sizeof( * V_9 ) * V_53 , V_56 ) ;
if ( ! V_9 )
return - V_62 ;
V_31 -> V_63 = V_53 ;
V_31 -> V_9 = V_9 ;
F_43 (dvc, priv, i) {
snprintf ( V_59 , V_60 , L_15 ,
V_64 , V_14 ) ;
V_58 = F_44 ( V_52 , V_59 ) ;
if ( F_45 ( V_58 ) )
return F_46 ( V_58 ) ;
V_9 -> V_50 = & V_50 -> V_48 [ V_14 ] ;
V_37 = F_47 ( V_31 , & V_9 -> V_2 , & V_65 ,
V_58 , V_66 , V_14 ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
void F_48 ( struct V_41 * V_42 ,
struct V_30 * V_31 )
{
struct V_8 * V_9 ;
int V_14 ;
F_43 (dvc, priv, i) {
F_49 ( & V_9 -> V_2 ) ;
}
}
