static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = ( 0x00800000 - 1 ) ;
T_1 V_6 [ V_7 ] ;
T_1 V_8 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_7 ; V_9 ++ ) {
V_6 [ V_9 ] = V_5 / V_10 * V_4 -> V_11 [ V_9 ] ;
V_8 |= ( ! ! V_4 -> V_8 [ V_9 ] ) << V_9 ;
}
F_3 ( V_2 , V_12 , V_6 [ 0 ] ) ;
F_3 ( V_2 , V_13 , V_6 [ 1 ] ) ;
F_3 ( V_2 , V_14 , V_8 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_5 ( V_2 ) ;
struct V_19 * V_20 = F_6 ( V_18 ) ;
F_7 ( V_20 , L_1 , F_8 ( V_2 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_21 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_21 ) ;
struct V_22 * V_23 = F_10 ( V_21 ) ;
struct V_17 * V_18 = F_5 ( V_21 ) ;
struct V_1 * V_24 = F_11 ( V_23 ) ;
struct V_19 * V_20 = F_6 ( V_18 ) ;
int V_25 = F_12 ( V_21 ) ;
int V_26 = F_12 ( V_24 ) ;
T_1 V_27 [] = {
[ 0 ] = 0x30000 ,
[ 1 ] = 0x30001 ,
[ 2 ] = 0x40000 ,
[ 3 ] = 0x10000 ,
[ 4 ] = 0x20000 ,
[ 5 ] = 0x40100
} ;
if ( V_26 >= F_13 ( V_27 ) ) {
F_14 ( V_20 , L_2 , V_25 , V_26 ) ;
return - V_28 ;
}
F_15 ( V_4 -> V_29 ) ;
F_3 ( V_21 , V_30 , V_27 [ V_26 ] ) ;
F_3 ( V_21 , V_31 , 0 ) ;
F_3 ( V_21 , V_31 , 1 ) ;
F_3 ( V_21 , V_32 , 1 ) ;
F_3 ( V_21 , V_33 , F_16 ( V_21 ) ) ;
F_3 ( V_21 , V_34 , 0x101 ) ;
F_1 ( V_21 ) ;
F_3 ( V_21 , V_32 , 0 ) ;
F_3 ( V_21 , V_35 , 1 ) ;
F_17 ( V_16 , V_21 , V_23 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_19 ( V_4 -> V_29 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_3 ( V_2 , V_36 , 0x10 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_3 ( V_2 , V_36 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = F_23 ( V_38 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 * V_41 = ( T_2 * ) V_38 -> V_42 ;
V_40 -> V_43 = V_7 ;
V_40 -> V_44 . integer . V_45 = 0 ;
if ( V_41 == V_4 -> V_11 ) {
V_40 -> type = V_46 ;
V_40 -> V_44 . integer . V_5 = V_10 ;
} else {
V_40 -> type = V_47 ;
V_40 -> V_44 . integer . V_5 = 1 ;
}
return 0 ;
}
static int F_24 ( struct V_37 * V_38 ,
struct V_48 * V_49 )
{
T_2 * V_41 = ( T_2 * ) V_38 -> V_42 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_7 ; V_9 ++ )
V_49 -> V_44 . integer . V_44 [ V_9 ] = V_41 [ V_9 ] ;
return 0 ;
}
static int F_25 ( struct V_37 * V_38 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_23 ( V_38 ) ;
T_2 * V_41 = ( T_2 * ) V_38 -> V_42 ;
int V_9 , V_50 = 0 ;
for ( V_9 = 0 ; V_9 < V_7 ; V_9 ++ ) {
V_50 |= ( V_49 -> V_44 . integer . V_44 [ V_9 ] != V_41 [ V_9 ] ) ;
V_41 [ V_9 ] = V_49 -> V_44 . integer . V_44 [ V_9 ] ;
}
if ( V_50 )
F_1 ( V_2 ) ;
return V_50 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_51 * V_52 ,
const unsigned char * V_53 ,
T_2 * V_54 )
{
struct V_55 * V_56 = V_52 -> V_56 -> V_55 ;
struct V_37 * V_38 ;
struct V_57 V_58 = {
. V_59 = V_60 ,
. V_53 = V_53 ,
. V_61 = F_22 ,
. V_62 = F_24 ,
. V_63 = F_25 ,
. V_42 = ( unsigned long ) V_54 ,
} ;
int V_64 ;
V_38 = F_27 ( & V_58 , V_2 ) ;
if ( ! V_38 )
return - V_65 ;
V_64 = F_28 ( V_56 , V_38 ) ;
if ( V_64 < 0 )
return V_64 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_51 * V_52 )
{
struct V_22 * V_23 = F_10 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_64 ;
V_64 = F_26 ( V_2 , V_16 , V_52 ,
F_30 ( V_16 , V_23 ) ?
L_3 : L_4 ,
V_4 -> V_11 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_26 ( V_2 , V_16 , V_52 ,
F_30 ( V_16 , V_23 ) ?
L_5 : L_6 ,
V_4 -> V_8 ) ;
if ( V_64 < 0 )
return V_64 ;
return 0 ;
}
struct V_1 * F_31 ( struct V_17 * V_18 , int V_66 )
{
if ( F_32 ( V_66 < 0 || V_66 >= F_33 ( V_18 ) ) )
V_66 = 0 ;
return & ( (struct V_3 * ) ( V_18 -> V_4 ) + V_66 ) -> V_2 ;
}
static void F_34 ( struct V_67 * V_68 ,
const struct V_69 * V_70 ,
struct V_17 * V_18 )
{
struct V_71 * V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_61 = F_35 ( V_18 ) ;
struct V_19 * V_20 = & V_68 -> V_20 ;
int V_76 ;
if ( ! V_70 )
return;
V_72 = F_36 ( V_20 -> V_77 , L_7 ) ;
if ( ! V_72 )
return;
V_76 = F_37 ( V_72 ) ;
if ( ! V_76 )
goto V_78;
V_74 = F_38 ( V_20 ,
sizeof( struct V_73 ) * V_76 ,
V_79 ) ;
if ( ! V_74 ) {
F_14 ( V_20 , L_8 ) ;
goto V_78;
}
V_61 -> V_74 = V_74 ;
V_61 -> V_80 = V_76 ;
V_78:
F_39 ( V_72 ) ;
}
int F_40 ( struct V_67 * V_68 ,
const struct V_69 * V_70 ,
struct V_17 * V_18 )
{
struct V_75 * V_61 = F_35 ( V_18 ) ;
struct V_19 * V_20 = F_6 ( V_18 ) ;
struct V_3 * V_4 ;
struct V_29 * V_29 ;
char V_53 [ V_81 ] ;
int V_9 , V_76 ;
F_34 ( V_68 , V_70 , V_18 ) ;
V_76 = V_61 -> V_80 ;
if ( ! V_76 )
return 0 ;
if ( F_41 ( V_18 ) ) {
F_42 ( V_20 , L_9 ) ;
return - V_28 ;
}
V_4 = F_38 ( V_20 , sizeof( * V_4 ) * V_76 , V_79 ) ;
if ( ! V_4 ) {
F_14 ( V_20 , L_10 ) ;
return - V_65 ;
}
V_18 -> V_82 = V_76 ;
V_18 -> V_4 = V_4 ;
F_43 (dvc, priv, i) {
snprintf ( V_53 , V_81 , L_11 ,
V_83 , V_9 ) ;
V_29 = F_44 ( V_20 , V_53 ) ;
if ( F_45 ( V_29 ) )
return F_46 ( V_29 ) ;
V_4 -> V_61 = & V_61 -> V_74 [ V_9 ] ;
V_4 -> V_29 = V_29 ;
F_47 ( V_18 , & V_4 -> V_2 , & V_84 , V_85 , V_9 ) ;
F_7 ( V_20 , L_12 , V_9 ) ;
}
return 0 ;
}
