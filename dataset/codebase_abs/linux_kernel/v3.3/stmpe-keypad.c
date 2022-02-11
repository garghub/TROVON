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
static int T_3 F_9 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_32 = V_5 -> V_32 ;
unsigned int V_33 = V_5 -> V_33 ;
struct V_6 * V_6 = V_2 -> V_6 ;
unsigned int V_34 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_5 -> V_35 ; V_8 ++ ) {
int V_36 = F_10 ( V_32 ) ;
if ( V_2 -> V_37 & ( 1 << V_8 ) )
V_34 |= 1 << V_36 ;
V_32 &= ~ ( 1 << V_36 ) ;
}
for ( V_8 = 0 ; V_8 < V_5 -> V_38 ; V_8 ++ ) {
int V_36 = F_10 ( V_33 ) ;
if ( V_2 -> V_39 & ( 1 << V_8 ) )
V_34 |= 1 << V_36 ;
V_33 &= ~ ( 1 << V_36 ) ;
}
return F_11 ( V_6 , V_34 , V_40 ) ;
}
static int T_3 F_12 ( struct V_1 * V_2 )
{
const struct V_41 * V_42 = V_2 -> V_42 ;
const struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 ;
if ( V_42 -> V_43 > V_44 )
return - V_45 ;
if ( V_42 -> V_46 > V_47 )
return - V_45 ;
V_7 = F_13 ( V_6 , V_40 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_9 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_14 ( V_6 , V_48 , V_2 -> V_37 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_14 ( V_6 , V_49 , V_2 -> V_39 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_5 -> V_38 > 8 ) {
V_7 = F_15 ( V_6 , V_50 ,
V_51 ,
V_2 -> V_39 >> 8 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_15 ( V_6 , V_52 ,
V_53 ,
V_42 -> V_46 << 4 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_15 ( V_6 , V_54 ,
V_55 |
V_56 ,
V_55 |
( V_42 -> V_43 << 1 ) ) ;
}
static int T_3 F_16 ( struct V_57 * V_58 )
{
struct V_6 * V_6 = F_17 ( V_58 -> V_13 . V_59 ) ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_7 ;
int V_12 ;
int V_8 ;
V_42 = V_6 -> V_60 -> V_2 ;
if ( ! V_42 )
return - V_61 ;
V_12 = F_18 ( V_58 , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 = F_19 ( sizeof( struct V_1 ) , V_62 ) ;
if ( ! V_2 )
return - V_63 ;
V_15 = F_20 () ;
if ( ! V_15 ) {
V_7 = - V_63 ;
goto V_64;
}
V_15 -> V_65 = L_1 ;
V_15 -> V_66 . V_67 = V_68 ;
V_15 -> V_13 . V_59 = & V_58 -> V_13 ;
F_21 ( V_15 , V_28 , V_29 ) ;
F_22 ( V_69 , V_15 -> V_70 ) ;
if ( ! V_42 -> V_71 )
F_22 ( V_72 , V_15 -> V_70 ) ;
V_15 -> V_73 = V_2 -> V_30 ;
V_15 -> V_74 = sizeof( V_2 -> V_30 [ 0 ] ) ;
V_15 -> V_75 = F_23 ( V_2 -> V_30 ) ;
F_24 ( V_42 -> V_76 , V_24 ,
V_15 -> V_73 , V_15 -> V_77 ) ;
for ( V_8 = 0 ; V_8 < V_42 -> V_76 -> V_78 ; V_8 ++ ) {
unsigned int V_79 = V_42 -> V_76 -> V_30 [ V_8 ] ;
V_2 -> V_37 |= 1 << F_25 ( V_79 ) ;
V_2 -> V_39 |= 1 << F_26 ( V_79 ) ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_42 = V_42 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_5 = & V_80 [ V_6 -> V_81 ] ;
V_7 = F_12 ( V_2 ) ;
if ( V_7 < 0 )
goto V_82;
V_7 = F_27 ( V_15 ) ;
if ( V_7 ) {
F_28 ( & V_58 -> V_13 ,
L_2 , V_7 ) ;
goto V_82;
}
V_7 = F_29 ( V_12 , NULL , F_4 , V_83 ,
L_3 , V_2 ) ;
if ( V_7 ) {
F_28 ( & V_58 -> V_13 , L_4 , V_7 ) ;
goto V_84;
}
F_30 ( V_58 , V_2 ) ;
return 0 ;
V_84:
F_31 ( V_15 ) ;
V_15 = NULL ;
V_82:
F_32 ( V_15 ) ;
V_64:
F_33 ( V_2 ) ;
return V_7 ;
}
static int T_4 F_34 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_35 ( V_58 ) ;
struct V_6 * V_6 = V_2 -> V_6 ;
int V_12 = F_18 ( V_58 , 0 ) ;
F_36 ( V_6 , V_40 ) ;
F_37 ( V_12 , V_2 ) ;
F_31 ( V_2 -> V_15 ) ;
F_30 ( V_58 , NULL ) ;
F_33 ( V_2 ) ;
return 0 ;
}
