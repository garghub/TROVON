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
F_8 ( V_6 ) ;
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
F_16 ( V_2 ) ;
F_1 ( V_2 ) ;
F_6 ( V_6 , V_2 ) ;
F_11 ( V_6 , V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_39 * V_40 )
{
F_3 ( V_2 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_41 * V_42 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_43 * V_44 = F_20 ( V_6 ) ;
int V_45 = F_21 ( V_6 ) ;
int V_46 = F_22 ( V_44 ) ;
int V_47 ;
V_47 = F_23 ( V_2 , V_6 , V_42 ,
V_45 ?
L_1 : L_2 ,
V_48 ,
F_11 ,
& V_8 -> V_13 , V_46 ,
0x00800000 - 1 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_23 ( V_2 , V_6 , V_42 ,
V_45 ?
L_3 : L_4 ,
V_48 ,
F_11 ,
& V_8 -> V_35 , V_46 ,
1 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_24 ( V_2 , V_6 , V_42 ,
V_45 ?
L_5 : L_6 ,
V_48 ,
F_11 ,
& V_8 -> V_12 , 1 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_25 ( V_2 , V_6 , V_42 ,
V_45 ?
L_7 : L_8 ,
V_48 ,
F_11 ,
& V_8 -> V_49 ,
V_50 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_25 ( V_2 , V_6 , V_42 ,
V_45 ?
L_9 : L_10 ,
V_48 ,
F_11 ,
& V_8 -> V_51 ,
V_50 ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
static struct V_52 * F_26 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_39 * V_40 = F_27 ( V_2 ) ;
return F_28 ( F_29 ( V_40 ) ,
V_2 , L_11 ) ;
}
struct V_1 * F_30 ( struct V_39 * V_40 , int V_53 )
{
if ( F_31 ( V_53 < 0 || V_53 >= F_32 ( V_40 ) ) )
V_53 = 0 ;
return F_33 ( F_34 ( V_40 , V_53 ) ) ;
}
int F_35 ( struct V_39 * V_40 )
{
struct V_54 * V_55 ;
struct V_54 * V_56 ;
struct V_57 * V_58 = F_36 ( V_40 ) ;
struct V_7 * V_8 ;
struct V_59 * V_59 ;
char V_60 [ V_61 ] ;
int V_11 , V_62 , V_47 ;
if ( F_37 ( V_40 ) )
return 0 ;
V_55 = F_29 ( V_40 ) ;
if ( ! V_55 )
return 0 ;
V_62 = F_38 ( V_55 ) ;
if ( ! V_62 ) {
V_47 = - V_63 ;
goto V_64;
}
V_8 = F_39 ( V_58 , sizeof( * V_8 ) * V_62 , V_65 ) ;
if ( ! V_8 ) {
V_47 = - V_66 ;
goto V_64;
}
V_40 -> V_67 = V_62 ;
V_40 -> V_8 = V_8 ;
V_11 = 0 ;
V_47 = 0 ;
F_40 (node, np) {
V_8 = F_34 ( V_40 , V_11 ) ;
snprintf ( V_60 , V_61 , L_12 ,
V_68 , V_11 ) ;
V_59 = F_41 ( V_58 , V_60 ) ;
if ( F_42 ( V_59 ) ) {
V_47 = F_43 ( V_59 ) ;
F_44 ( V_56 ) ;
goto V_64;
}
V_47 = F_45 ( V_40 , F_33 ( V_8 ) , & V_69 ,
V_59 , V_70 , V_71 , V_11 ) ;
if ( V_47 ) {
F_44 ( V_56 ) ;
goto V_64;
}
V_11 ++ ;
}
V_64:
F_44 ( V_55 ) ;
return V_47 ;
}
void F_46 ( struct V_39 * V_40 )
{
struct V_7 * V_8 ;
int V_11 ;
F_47 (dvc, priv, i) {
F_48 ( F_33 ( V_8 ) ) ;
}
}
