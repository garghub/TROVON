static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
T_1 V_5 ;
V_5 = F_2 ( V_2 -> V_6 + F_3 ( V_3 ) ) ;
V_5 = ( V_5 & ~ V_7 ) | V_4 ;
F_4 ( V_5 , V_2 -> V_6 + F_3 ( V_3 ) ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
T_1 V_8 ;
V_8 = F_2 ( V_2 -> V_6 + F_3 ( V_3 ) ) ;
V_8 = ( V_8 & ~ V_9 ) | V_4 ;
F_4 ( V_8 , V_2 -> V_6 + F_3 ( V_3 ) ) ;
}
static bool F_6 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_2 = V_13 -> V_15 ;
T_1 V_16 ;
F_7 ( V_2 -> V_17 ) ;
V_16 = F_2 ( V_2 -> V_6 + F_3 ( V_13 -> V_3 ) ) ;
return ( ( V_16 & V_7 ) == V_18 ) ;
}
static int F_8 ( struct V_10 * V_11 , void * V_19 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_2 = V_13 -> V_15 ;
unsigned int V_3 = V_13 -> V_3 ;
T_1 * V_20 = V_19 ;
int V_21 ;
V_13 -> V_22 = V_23 ;
F_1 ( V_2 , V_3 , V_24 ) ;
if ( V_2 -> V_17 )
F_5 ( V_2 , V_3 , V_25 ) ;
else
F_5 ( V_2 , V_3 , V_26 ) ;
for ( V_21 = 0 ; V_21 < V_27 ; V_21 ++ )
F_4 ( V_20 [ V_21 ] , V_2 -> V_6 + F_9 ( V_3 ) + V_21 * 4 ) ;
F_4 ( F_10 ( V_13 -> V_28 ) , F_11 ( V_2 -> V_29 ) ) ;
return 0 ;
}
static T_2 F_12 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
struct V_12 * V_13 ;
struct V_10 * V_11 ;
unsigned int V_16 , V_32 , V_21 ;
T_1 V_19 [ V_27 ] ;
V_16 = F_2 ( F_13 ( V_2 -> V_29 ) ) ;
if ( ! V_16 ) {
F_14 ( V_2 -> V_33 , L_1 ,
V_34 ) ;
return V_35 ;
}
while ( V_16 ) {
V_32 = F_15 ( V_16 ) ;
V_16 &= ( V_16 - 1 ) ;
V_11 = V_2 -> V_36 [ V_32 ] ;
if ( ! V_11 ) {
F_14 ( V_2 -> V_33 , L_2 ,
V_34 , V_32 ) ;
continue;
}
V_13 = V_11 -> V_14 ;
if ( V_13 -> V_22 == V_23 )
F_16 ( V_11 , 0 ) ;
else {
for ( V_21 = 0 ; V_21 < V_27 ; V_21 ++ )
V_19 [ V_21 ] = F_2 ( V_2 -> V_6 +
F_9 ( V_13 -> V_3 ) + V_21 * 4 ) ;
F_17 ( V_11 , ( void * ) V_19 ) ;
}
F_4 ( F_10 ( V_13 -> V_37 ) , F_18 ( V_2 -> V_29 ) ) ;
F_1 ( V_2 , V_13 -> V_3 , V_18 ) ;
}
return V_35 ;
}
static int F_19 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_2 = V_13 -> V_15 ;
V_13 -> V_22 = 0 ;
F_4 ( F_10 ( V_13 -> V_37 ) , F_20 ( V_2 -> V_29 ) ) ;
return 0 ;
}
static void F_21 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_2 = V_13 -> V_15 ;
F_4 ( F_10 ( V_13 -> V_37 ) , F_22 ( V_2 -> V_29 ) ) ;
V_2 -> V_36 [ V_13 -> V_37 ] = NULL ;
}
static struct V_10 * F_23 ( struct V_38 * V_39 ,
const struct V_40 * V_41 )
{
struct V_1 * V_2 = F_24 ( V_39 -> V_33 ) ;
struct V_12 * V_13 ;
struct V_10 * V_11 ;
unsigned int V_21 = V_41 -> args [ 0 ] ;
unsigned int V_28 = V_41 -> args [ 1 ] ;
unsigned int V_37 = V_41 -> args [ 2 ] ;
if ( V_21 >= V_2 -> V_42 || V_28 >= V_2 -> V_42 ||
V_37 >= V_2 -> V_42 ) {
F_25 ( V_2 -> V_33 ,
L_3 ,
V_21 , V_28 , V_37 ) ;
return F_26 ( - V_43 ) ;
}
V_11 = & V_2 -> V_11 [ V_21 ] ;
if ( V_2 -> V_36 [ V_37 ] == ( void * ) V_11 ) {
F_25 ( V_2 -> V_33 , L_4 ) ;
return F_26 ( - V_44 ) ;
}
V_13 = V_11 -> V_14 ;
V_13 -> V_28 = V_28 ;
V_13 -> V_37 = V_37 ;
V_2 -> V_36 [ V_37 ] = ( void * ) V_11 ;
return V_11 ;
}
static int F_27 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = V_46 -> V_33 . V_49 ;
struct V_50 * V_33 = & V_46 -> V_33 ;
struct V_1 * V_2 ;
struct V_51 * V_52 ;
int V_21 , V_53 ;
V_2 = F_28 ( V_33 , sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_55 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_42 = V_56 ;
V_2 -> V_13 = F_28 ( V_33 ,
V_2 -> V_42 * sizeof( * V_2 -> V_13 ) , V_54 ) ;
if ( ! V_2 -> V_13 )
return - V_55 ;
V_2 -> V_11 = F_28 ( V_33 ,
V_2 -> V_42 * sizeof( * V_2 -> V_11 ) , V_54 ) ;
if ( ! V_2 -> V_11 )
return - V_55 ;
V_2 -> V_30 = F_29 ( V_46 , 0 ) ;
if ( V_2 -> V_30 < 0 )
return V_2 -> V_30 ;
V_52 = F_30 ( V_46 , V_57 , 0 ) ;
V_2 -> V_29 = F_31 ( V_33 , V_52 ) ;
if ( F_32 ( V_2 -> V_29 ) ) {
F_25 ( V_33 , L_5 ) ;
return F_33 ( V_2 -> V_29 ) ;
}
V_52 = F_30 ( V_46 , V_57 , 1 ) ;
V_2 -> V_6 = F_31 ( V_33 , V_52 ) ;
if ( F_32 ( V_2 -> V_6 ) ) {
F_25 ( V_33 , L_6 ) ;
return F_33 ( V_2 -> V_6 ) ;
}
V_53 = F_34 ( V_33 , V_2 -> V_30 , F_12 , 0 ,
F_35 ( V_33 ) , V_2 ) ;
if ( V_53 ) {
F_25 ( V_33 , L_7 ,
V_53 ) ;
return - V_58 ;
}
V_2 -> V_39 . V_33 = V_33 ;
V_2 -> V_39 . V_59 = & V_2 -> V_11 [ 0 ] ;
V_2 -> V_39 . V_60 = V_2 -> V_42 ;
V_2 -> V_39 . V_61 = & V_62 ;
V_2 -> V_39 . V_63 = F_23 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_42 ; V_21 ++ ) {
V_2 -> V_11 [ V_21 ] . V_14 = & V_2 -> V_13 [ V_21 ] ;
V_2 -> V_36 [ V_21 ] = NULL ;
V_2 -> V_13 [ V_21 ] . V_15 = V_2 ;
V_2 -> V_13 [ V_21 ] . V_3 = V_21 ;
}
F_4 ( 0x0 , F_36 ( V_2 -> V_29 ) ) ;
F_4 ( ~ 0x0 , F_18 ( V_2 -> V_29 ) ) ;
if ( F_37 ( V_48 , L_8 , NULL ) )
V_2 -> V_17 = false ;
else
V_2 -> V_17 = true ;
if ( V_2 -> V_17 )
V_2 -> V_39 . V_64 = true ;
else {
V_2 -> V_39 . V_65 = true ;
V_2 -> V_39 . V_66 = 5 ;
}
V_53 = F_38 ( & V_2 -> V_39 ) ;
if ( V_53 ) {
F_25 ( V_33 , L_9 , V_53 ) ;
return V_53 ;
}
F_39 ( V_46 , V_2 ) ;
F_40 ( V_33 , L_10 ) ;
return 0 ;
}
static int F_41 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_42 ( V_46 ) ;
F_43 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_67 ) ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_67 ) ;
}
