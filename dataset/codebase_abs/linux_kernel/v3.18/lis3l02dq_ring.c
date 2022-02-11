static inline T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
T_1 V_3 = V_1 ;
T_1 V_4 = V_2 ;
return V_3 | ( V_4 << 8 ) ;
}
T_3 F_2 ( int V_5 , void * V_6 )
{
struct V_7 * V_8 = V_6 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
if ( V_10 -> V_11 ) {
F_4 ( V_10 -> V_12 ) ;
return V_13 ;
}
return V_14 ;
}
static int F_5 ( struct V_7 * V_8 , T_2 * V_15 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_16 * V_17 ;
struct V_18 V_19 ;
int V_20 , V_21 , V_22 = 0 ;
V_17 = F_6 ( F_7 ( V_8 -> V_23 ,
V_8 -> V_24 ) * 2 ,
sizeof( * V_17 ) , V_25 ) ;
if ( ! V_17 )
return - V_26 ;
F_8 ( & V_10 -> V_27 ) ;
for ( V_21 = 0 ; V_21 < F_9 ( V_28 ) / 4 ; V_21 ++ )
if ( F_10 ( V_21 , V_8 -> V_23 ) ) {
V_17 [ V_22 ] . V_29 = V_10 -> V_30 + 2 * V_22 ;
V_10 -> V_30 [ 2 * V_22 ] = V_28 [ V_21 * 4 ] ;
V_10 -> V_30 [ 2 * V_22 + 1 ] = 0 ;
if ( V_15 )
V_17 [ V_22 ] . V_31 = V_15 + V_22 * 2 ;
V_17 [ V_22 ] . V_32 = 8 ;
V_17 [ V_22 ] . V_33 = 2 ;
V_17 [ V_22 ] . V_34 = 1 ;
V_22 ++ ;
V_17 [ V_22 ] . V_29 = V_10 -> V_30 + 2 * V_22 ;
V_10 -> V_30 [ 2 * V_22 ] = V_28 [ V_21 * 4 + 2 ] ;
V_10 -> V_30 [ 2 * V_22 + 1 ] = 0 ;
if ( V_15 )
V_17 [ V_22 ] . V_31 = V_15 + V_22 * 2 ;
V_17 [ V_22 ] . V_32 = 8 ;
V_17 [ V_22 ] . V_33 = 2 ;
V_17 [ V_22 ] . V_34 = 1 ;
V_22 ++ ;
}
F_11 ( & V_19 ) ;
for ( V_22 = 0 ; V_22 < F_7 ( V_8 -> V_23 ,
V_8 -> V_24 ) * 2 ; V_22 ++ )
F_12 ( & V_17 [ V_22 ] , & V_19 ) ;
V_20 = F_13 ( V_10 -> V_35 , & V_19 ) ;
F_14 ( & V_10 -> V_27 ) ;
F_15 ( V_17 ) ;
return V_20 ;
}
static int F_16 ( struct V_7 * V_8 ,
T_2 * V_36 )
{
int V_20 , V_21 ;
T_2 * V_15 ;
T_4 * V_37 = ( T_4 * ) V_36 ;
int V_38 = F_7 ( V_8 -> V_23 ,
V_8 -> V_24 ) ;
V_15 = F_17 ( 4 * V_38 , V_25 ) ;
if ( V_15 == NULL )
return - V_26 ;
V_20 = F_5 ( V_8 , V_15 ) ;
if ( V_20 < 0 ) {
F_15 ( V_15 ) ;
return V_20 ;
}
for ( V_21 = 0 ; V_21 < V_38 ; V_21 ++ )
V_37 [ V_21 ] = F_1 ( V_15 [ V_21 * 4 + 1 ] ,
V_15 [ V_21 * 4 + 3 ] ) ;
F_15 ( V_15 ) ;
return V_21 * sizeof( V_37 [ 0 ] ) ;
}
static T_3 F_18 ( int V_5 , void * V_39 )
{
struct V_40 * V_41 = V_39 ;
struct V_7 * V_8 = V_41 -> V_8 ;
int V_33 = 0 ;
char * V_37 ;
V_37 = F_19 ( V_8 -> V_42 , V_25 ) ;
if ( V_37 == NULL )
goto V_43;
if ( ! F_20 ( V_8 -> V_23 , V_8 -> V_24 ) )
V_33 = F_16 ( V_8 , V_37 ) ;
F_21 ( V_8 , V_37 , V_41 -> V_44 ) ;
F_15 ( V_37 ) ;
V_43:
F_22 ( V_8 -> V_12 ) ;
return V_13 ;
}
static int
F_23 ( struct V_7 * V_8 , bool V_45 )
{
int V_20 ;
T_2 V_46 ;
bool V_47 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
V_20 = F_24 ( V_8 ,
V_48 ,
& V_46 ) ;
if ( V_20 )
goto V_49;
V_47
= V_46 & V_50 ;
if ( ! V_45 && V_47 ) {
V_46 &= ~ V_50 ;
V_20 = F_25 ( V_8 ,
V_48 ,
V_46 ) ;
if ( V_20 )
goto V_49;
V_20 = F_25 ( V_8 ,
V_48 ,
V_46 ) ;
if ( V_20 )
goto V_49;
V_10 -> V_11 = false ;
} else if ( V_45 && ! V_47 ) {
V_20 = F_26 ( V_8 ) ;
if ( V_20 < 0 )
goto V_49;
V_46 = V_20 |
V_50 ;
V_10 -> V_11 = true ;
V_20 = F_25 ( V_8 ,
V_48 ,
V_46 ) ;
if ( V_20 )
goto V_49;
}
return 0 ;
V_49:
return V_20 ;
}
static int F_27 ( struct V_51 * V_12 ,
bool V_45 )
{
struct V_7 * V_8 = F_28 ( V_12 ) ;
int V_20 = 0 ;
T_2 V_52 ;
F_23 ( V_8 , V_45 ) ;
if ( ! V_45 ) {
V_20 = F_5 ( V_8 , NULL ) ;
}
F_24 ( V_8 ,
V_53 ,
& V_52 ) ;
return V_20 ;
}
static int F_29 ( struct V_51 * V_12 )
{
struct V_7 * V_8 = F_28 ( V_12 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_21 ;
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ )
if ( F_30 ( V_10 -> V_54 ) )
F_5 ( V_8 , NULL ) ;
else
break;
if ( V_21 == 5 )
F_31 ( L_1 ) ;
return 0 ;
}
int F_32 ( struct V_7 * V_8 )
{
int V_20 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
V_10 -> V_12 = F_33 ( L_2 , V_8 -> V_55 ) ;
if ( ! V_10 -> V_12 ) {
V_20 = - V_26 ;
goto V_49;
}
V_10 -> V_12 -> V_56 . V_57 = & V_10 -> V_35 -> V_56 ;
V_10 -> V_12 -> V_58 = & V_59 ;
F_34 ( V_10 -> V_12 , V_8 ) ;
V_20 = F_35 ( V_10 -> V_12 ) ;
if ( V_20 )
goto V_60;
return 0 ;
V_60:
F_36 ( V_10 -> V_12 ) ;
V_49:
return V_20 ;
}
void F_37 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_38 ( V_10 -> V_12 ) ;
F_36 ( V_10 -> V_12 ) ;
}
void F_39 ( struct V_7 * V_8 )
{
F_40 ( V_8 -> V_61 ) ;
F_41 ( V_8 -> V_62 ) ;
}
static int F_42 ( struct V_7 * V_8 )
{
T_2 V_52 ;
int V_20 ;
bool V_63 = false ;
V_20 = F_24 ( V_8 ,
V_64 ,
& V_52 ) ;
if ( V_20 )
goto V_49;
if ( F_10 ( 0 , V_8 -> V_23 ) ) {
V_52 |= V_65 ;
V_63 = true ;
} else
V_52 &= ~ V_65 ;
if ( F_10 ( 1 , V_8 -> V_23 ) ) {
V_52 |= V_66 ;
V_63 = true ;
} else
V_52 &= ~ V_66 ;
if ( F_10 ( 2 , V_8 -> V_23 ) ) {
V_52 |= V_67 ;
V_63 = true ;
} else
V_52 &= ~ V_67 ;
if ( ! V_63 )
return - V_68 ;
V_20 = F_25 ( V_8 ,
V_64 ,
V_52 ) ;
if ( V_20 )
goto V_49;
return F_43 ( V_8 ) ;
V_49:
return V_20 ;
}
static int F_44 ( struct V_7 * V_8 )
{
T_2 V_52 ;
int V_20 ;
V_20 = F_45 ( V_8 ) ;
if ( V_20 )
goto V_49;
V_20 = F_24 ( V_8 ,
V_64 ,
& V_52 ) ;
if ( V_20 )
goto V_49;
V_52 |= V_65 |
V_66 |
V_67 ;
V_20 = F_25 ( V_8 ,
V_64 ,
V_52 ) ;
V_49:
return V_20 ;
}
int F_46 ( struct V_7 * V_8 )
{
int V_20 ;
struct V_69 * V_62 ;
V_62 = F_47 ( V_8 ) ;
if ( ! V_62 )
return - V_26 ;
F_48 ( V_8 , V_62 ) ;
V_62 -> V_70 = true ;
V_8 -> V_71 = & V_72 ;
V_8 -> V_61 = F_49 ( & V_73 ,
& F_18 ,
0 ,
V_8 ,
L_3 ,
V_8 -> V_55 ) ;
if ( V_8 -> V_61 == NULL ) {
V_20 = - V_26 ;
goto V_74;
}
V_8 -> V_75 |= V_76 ;
return 0 ;
V_74:
F_41 ( V_8 -> V_62 ) ;
return V_20 ;
}
