static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 ;
int V_8 ;
if ( V_5 -> V_9 )
return F_2 ( V_6 , V_10 ,
V_5 -> V_11 , V_3 ) ;
for ( V_8 = 0 ; V_8 < V_5 -> V_11 ; V_8 ++ ) {
V_7 = F_3 ( V_6 , V_10 + V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
V_3 [ V_8 ] = V_7 ;
}
return 0 ;
}
static T_2 F_4 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
struct V_14 * V_15 = V_2 -> V_15 ;
const struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_16 [ V_5 -> V_11 ] ;
int V_7 ;
int V_8 ;
V_7 = F_1 ( V_2 , V_16 ) ;
if ( V_7 < 0 )
return V_17 ;
for ( V_8 = 0 ; V_8 < V_5 -> V_18 ; V_8 ++ ) {
T_1 V_3 = V_16 [ V_8 ] ;
int V_19 = ( V_3 & V_20 ) >> 3 ;
int V_21 = V_3 & V_22 ;
int V_23 = F_5 ( V_19 , V_21 , V_24 ) ;
bool V_25 = V_3 & V_26 ;
if ( ( V_3 & V_27 )
== V_27 )
continue;
F_6 ( V_15 , V_28 , V_29 , V_23 ) ;
F_7 ( V_15 , V_2 -> V_30 [ V_23 ] , ! V_25 ) ;
F_8 ( V_15 ) ;
}
return V_31 ;
}
static int F_9 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_32 = V_5 -> V_32 ;
unsigned int V_33 = V_5 -> V_33 ;
struct V_6 * V_6 = V_2 -> V_6 ;
T_1 V_34 = V_6 -> V_35 [ V_36 ] ;
unsigned int V_37 = 0 ;
unsigned int V_38 = 0 ;
int V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_5 -> V_39 ; V_8 ++ ) {
int V_40 = F_10 ( V_32 ) ;
if ( V_2 -> V_41 & ( 1 << V_8 ) ) {
V_37 |= 1 << V_40 ;
V_38 |= 1 << V_40 ;
}
V_32 &= ~ ( 1 << V_40 ) ;
}
for ( V_8 = 0 ; V_8 < V_5 -> V_42 ; V_8 ++ ) {
int V_40 = F_10 ( V_33 ) ;
if ( V_2 -> V_43 & ( 1 << V_8 ) )
V_37 |= 1 << V_40 ;
V_33 &= ~ ( 1 << V_40 ) ;
}
V_7 = F_11 ( V_6 , V_37 , V_44 ) ;
if ( V_7 )
return V_7 ;
if ( V_5 -> V_45 ) {
T_1 V_46 ;
V_7 = F_3 ( V_6 , V_34 ) ;
if ( V_7 )
return V_7 ;
V_46 = V_7 & ~ V_38 ;
V_46 |= V_38 ;
V_7 = F_12 ( V_6 , V_34 , V_46 ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 ;
if ( V_2 -> V_47 > V_48 )
return - V_49 ;
if ( V_2 -> V_50 > V_51 )
return - V_49 ;
V_7 = F_14 ( V_6 , V_44 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_9 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_6 , V_52 , V_2 -> V_41 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_6 , V_53 , V_2 -> V_43 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_5 -> V_42 > 8 ) {
V_7 = F_15 ( V_6 , V_54 ,
V_55 ,
V_2 -> V_43 >> 8 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_15 ( V_6 , V_56 ,
V_57 ,
V_2 -> V_50 << 4 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_15 ( V_6 , V_58 ,
V_59 |
V_60 ,
V_59 |
( V_2 -> V_47 << 1 ) ) ;
}
static void F_16 ( struct V_1 * V_2 ,
T_3 V_61 , T_3 V_62 )
{
int V_19 , V_21 ;
for ( V_19 = 0 ; V_19 < V_61 ; V_19 ++ ) {
for ( V_21 = 0 ; V_21 < V_62 ; V_21 ++ ) {
int V_23 = F_5 ( V_19 , V_21 ,
V_24 ) ;
if ( V_2 -> V_30 [ V_23 ] != V_63 ) {
V_2 -> V_43 |= 1 << V_19 ;
V_2 -> V_41 |= 1 << V_21 ;
}
}
}
}
static int F_17 ( struct V_64 * V_65 )
{
struct V_6 * V_6 = F_18 ( V_65 -> V_13 . V_66 ) ;
struct V_67 * V_68 = V_65 -> V_13 . V_69 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
T_3 V_43 ;
T_3 V_41 ;
int error ;
int V_12 ;
V_12 = F_19 ( V_65 , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 = F_20 ( & V_65 -> V_13 , sizeof( struct V_1 ) ,
V_70 ) ;
if ( ! V_2 )
return - V_71 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_5 = & V_72 [ V_6 -> V_73 ] ;
F_21 ( V_68 , L_1 , & V_2 -> V_47 ) ;
F_21 ( V_68 , L_2 , & V_2 -> V_50 ) ;
V_2 -> V_74 = F_22 ( V_68 , L_3 ) ;
V_15 = F_23 ( & V_65 -> V_13 ) ;
if ( ! V_15 )
return - V_71 ;
V_15 -> V_75 = L_4 ;
V_15 -> V_76 . V_77 = V_78 ;
V_15 -> V_13 . V_66 = & V_65 -> V_13 ;
error = F_24 ( & V_65 -> V_13 , & V_43 , & V_41 ) ;
if ( error )
return error ;
error = F_25 ( NULL , NULL , V_43 , V_41 ,
V_2 -> V_30 , V_15 ) ;
if ( error )
return error ;
F_26 ( V_15 , V_28 , V_29 ) ;
if ( ! V_2 -> V_74 )
F_27 ( V_79 , V_15 -> V_80 ) ;
F_16 ( V_2 , V_43 , V_41 ) ;
V_2 -> V_15 = V_15 ;
error = F_13 ( V_2 ) ;
if ( error < 0 )
return error ;
error = F_28 ( & V_65 -> V_13 , V_12 ,
NULL , F_4 ,
V_81 , L_5 , V_2 ) ;
if ( error ) {
F_29 ( & V_65 -> V_13 , L_6 , error ) ;
return error ;
}
error = F_30 ( V_15 ) ;
if ( error ) {
F_29 ( & V_65 -> V_13 ,
L_7 , error ) ;
return error ;
}
F_31 ( V_65 , V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_33 ( V_65 ) ;
F_34 ( V_2 -> V_6 , V_44 ) ;
return 0 ;
}
