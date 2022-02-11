static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , 0 ) ;
F_2 ( V_2 , V_3 , 1 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_4 , 1 ) ;
F_2 ( V_2 , V_3 , 0 ) ;
}
static void F_4 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
T_1 V_9 [ V_10 ] ;
int V_11 ;
if ( V_8 -> V_12 . V_9 )
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
V_9 [ V_11 ] = V_8 -> V_13 . V_14 . V_15 ;
else
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
V_9 [ V_11 ] = V_8 -> V_13 . V_9 [ V_11 ] ;
F_2 ( V_2 , V_16 , V_9 [ 0 ] ) ;
F_2 ( V_2 , V_17 , V_9 [ 1 ] ) ;
F_2 ( V_2 , V_18 , V_9 [ 2 ] ) ;
F_2 ( V_2 , V_19 , V_9 [ 3 ] ) ;
F_2 ( V_2 , V_20 , V_9 [ 4 ] ) ;
F_2 ( V_2 , V_21 , V_9 [ 5 ] ) ;
F_2 ( V_2 , V_22 , V_9 [ 6 ] ) ;
F_2 ( V_2 , V_23 , V_9 [ 7 ] ) ;
}
static void F_6 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
T_1 V_24 = 0 ;
T_1 V_25 = 0 ;
T_1 V_26 = 0 ;
T_1 V_27 = 0 ;
T_1 V_28 = 0 ;
V_24 = F_7 ( V_2 , V_6 ) |
F_8 ( V_2 , V_6 ) ;
V_25 |= 0x101 ;
if ( V_8 -> V_12 . V_9 ) {
V_25 |= 0x10 ;
V_26 = 0xff ;
V_27 = F_9 ( V_8 ) ;
V_28 = F_10 ( V_8 ) ;
}
F_2 ( V_2 , V_4 , 1 ) ;
F_2 ( V_2 , V_29 , V_24 ) ;
F_2 ( V_2 , V_30 , V_25 ) ;
F_2 ( V_2 , V_31 , V_26 ) ;
F_2 ( V_2 , V_32 , V_27 ) ;
F_2 ( V_2 , V_33 , V_28 ) ;
F_4 ( V_6 , V_2 ) ;
F_2 ( V_2 , V_4 , 0 ) ;
}
static void F_11 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
T_1 V_34 = 0 ;
T_1 V_27 = 0 ;
T_1 V_28 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_35 . V_14 . V_36 ; V_11 ++ )
V_34 |= ( ! ! V_8 -> V_35 . V_14 . V_9 [ V_11 ] ) << V_11 ;
if ( V_8 -> V_12 . V_9 ) {
V_27 = F_9 ( V_8 ) ;
V_28 = F_10 ( V_8 ) ;
}
F_2 ( V_2 , V_37 , 0 ) ;
F_2 ( V_2 , V_38 , V_34 ) ;
F_2 ( V_2 , V_32 , V_27 ) ;
F_2 ( V_2 , V_33 , V_28 ) ;
F_4 ( V_6 , V_2 ) ;
F_2 ( V_2 , V_37 , 1 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_39 * V_40 )
{
return F_13 ( V_6 , F_14 ( V_2 ) ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_39 * V_40 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
F_16 ( V_8 -> V_13 ) ;
F_16 ( V_8 -> V_35 ) ;
F_16 ( V_8 -> V_12 ) ;
F_16 ( V_8 -> V_41 ) ;
F_16 ( V_8 -> V_42 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_39 * V_40 )
{
F_18 ( V_2 ) ;
F_1 ( V_2 ) ;
F_6 ( V_6 , V_2 ) ;
F_11 ( V_6 , V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_39 * V_40 )
{
F_3 ( V_2 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_43 * V_44 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
int V_45 = F_22 ( V_6 ) ;
int V_46 = F_23 ( V_6 ) ;
int V_47 ;
V_47 = F_24 ( V_2 , V_6 , V_44 ,
V_45 ?
L_1 : L_2 ,
F_11 ,
& V_8 -> V_13 , V_46 ,
0x00800000 - 1 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_24 ( V_2 , V_6 , V_44 ,
V_45 ?
L_3 : L_4 ,
F_11 ,
& V_8 -> V_35 , V_46 ,
1 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_25 ( V_2 , V_6 , V_44 ,
V_45 ?
L_5 : L_6 ,
F_11 ,
& V_8 -> V_12 , 1 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_26 ( V_2 , V_6 , V_44 ,
V_45 ?
L_7 : L_8 ,
& V_8 -> V_41 ,
F_11 ,
V_48 , F_27 ( V_48 ) ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_26 ( V_2 , V_6 , V_44 ,
V_45 ?
L_9 : L_10 ,
& V_8 -> V_42 ,
F_11 ,
V_48 , F_27 ( V_48 ) ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
static struct V_49 * F_28 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_39 * V_40 = F_29 ( V_2 ) ;
return F_30 ( F_31 ( V_40 ) ,
V_2 , L_11 ) ;
}
struct V_1 * F_32 ( struct V_39 * V_40 , int V_50 )
{
if ( F_33 ( V_50 < 0 || V_50 >= F_34 ( V_40 ) ) )
V_50 = 0 ;
return F_35 ( F_36 ( V_40 , V_50 ) ) ;
}
int F_37 ( struct V_39 * V_40 )
{
struct V_51 * V_52 ;
struct V_51 * V_53 ;
struct V_54 * V_55 = F_38 ( V_40 ) ;
struct V_7 * V_8 ;
struct V_56 * V_56 ;
char V_57 [ V_58 ] ;
int V_11 , V_59 , V_47 ;
if ( F_39 ( V_40 ) )
return 0 ;
V_52 = F_31 ( V_40 ) ;
if ( ! V_52 )
return 0 ;
V_59 = F_40 ( V_52 ) ;
if ( ! V_59 ) {
V_47 = - V_60 ;
goto V_61;
}
V_8 = F_41 ( V_55 , sizeof( * V_8 ) * V_59 , V_62 ) ;
if ( ! V_8 ) {
V_47 = - V_63 ;
goto V_61;
}
V_40 -> V_64 = V_59 ;
V_40 -> V_8 = V_8 ;
V_11 = 0 ;
V_47 = 0 ;
F_42 (node, np) {
V_8 = F_36 ( V_40 , V_11 ) ;
snprintf ( V_57 , V_58 , L_12 ,
V_65 , V_11 ) ;
V_56 = F_43 ( V_55 , V_57 ) ;
if ( F_44 ( V_56 ) ) {
V_47 = F_45 ( V_56 ) ;
goto V_61;
}
V_47 = F_46 ( V_40 , F_35 ( V_8 ) , & V_66 ,
V_56 , V_67 , V_11 ) ;
if ( V_47 )
goto V_61;
V_11 ++ ;
}
V_61:
F_47 ( V_52 ) ;
return V_47 ;
}
void F_48 ( struct V_39 * V_40 )
{
struct V_7 * V_8 ;
int V_11 ;
F_49 (dvc, priv, i) {
F_50 ( F_35 ( V_8 ) ) ;
}
}
