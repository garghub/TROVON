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
F_4 ( V_10 -> V_12 , F_5 () ) ;
return V_13 ;
} else
return V_14 ;
}
static int F_6 ( struct V_7 * V_8 , T_2 * V_15 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_16 * V_17 ;
struct V_18 V_19 ;
int V_20 , V_21 , V_22 = 0 ;
V_17 = F_7 ( F_8 ( V_8 -> V_23 ,
V_8 -> V_24 ) * 2 ,
sizeof( * V_17 ) , V_25 ) ;
if ( ! V_17 )
return - V_26 ;
F_9 ( & V_10 -> V_27 ) ;
for ( V_21 = 0 ; V_21 < F_10 ( V_28 ) / 4 ; V_21 ++ )
if ( F_11 ( V_21 , V_8 -> V_23 ) ) {
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
F_12 ( & V_19 ) ;
for ( V_22 = 0 ; V_22 < F_8 ( V_8 -> V_23 ,
V_8 -> V_24 ) * 2 ; V_22 ++ )
F_13 ( & V_17 [ V_22 ] , & V_19 ) ;
V_20 = F_14 ( V_10 -> V_35 , & V_19 ) ;
F_15 ( & V_10 -> V_27 ) ;
F_16 ( V_17 ) ;
return V_20 ;
}
static int F_17 ( struct V_7 * V_8 ,
T_2 * V_36 )
{
int V_20 , V_21 ;
T_2 * V_15 ;
T_4 * V_37 = ( T_4 * ) V_36 ;
int V_38 = F_8 ( V_8 -> V_23 ,
V_8 -> V_24 ) ;
V_15 = F_18 ( 4 * V_38 , V_25 ) ;
if ( V_15 == NULL )
return - V_26 ;
V_20 = F_6 ( V_8 , V_15 ) ;
if ( V_20 < 0 ) {
F_16 ( V_15 ) ;
return V_20 ;
}
for ( V_21 = 0 ; V_21 < V_38 ; V_21 ++ )
V_37 [ V_21 ] = F_1 ( V_15 [ V_21 * 4 + 1 ] ,
V_15 [ V_21 * 4 + 3 ] ) ;
F_16 ( V_15 ) ;
return V_21 * sizeof( V_37 [ 0 ] ) ;
}
static T_3 F_19 ( int V_5 , void * V_39 )
{
struct V_40 * V_41 = V_39 ;
struct V_7 * V_8 = V_41 -> V_8 ;
int V_33 = 0 ;
char * V_37 ;
V_37 = F_20 ( V_8 -> V_42 , V_25 ) ;
if ( V_37 == NULL ) {
F_21 ( V_8 -> V_43 . V_44 ,
L_1 ) ;
goto V_45;
}
if ( ! F_22 ( V_8 -> V_23 , V_8 -> V_24 ) )
V_33 = F_17 ( V_8 , V_37 ) ;
if ( V_8 -> V_46 )
* ( V_47 * ) ( ( T_2 * ) V_37 + F_23 ( V_33 , sizeof( V_47 ) ) )
= V_41 -> V_48 ;
F_24 ( V_8 , ( T_2 * ) V_37 ) ;
F_16 ( V_37 ) ;
V_45:
F_25 ( V_8 -> V_12 ) ;
return V_13 ;
}
static int
F_26 ( struct V_7 * V_8 , bool V_49 )
{
int V_20 ;
T_2 V_50 ;
bool V_51 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
V_20 = F_27 ( V_8 ,
V_52 ,
& V_50 ) ;
if ( V_20 )
goto V_53;
V_51
= V_50 & V_54 ;
if ( ! V_49 && V_51 ) {
V_50 &= ~ V_54 ;
V_20 = F_28 ( V_8 ,
V_52 ,
V_50 ) ;
if ( V_20 )
goto V_53;
V_20 = F_28 ( V_8 ,
V_52 ,
V_50 ) ;
if ( V_20 )
goto V_53;
V_10 -> V_11 = false ;
} else if ( V_49 && ! V_51 ) {
V_20 = F_29 ( V_8 ) ;
if ( V_20 < 0 )
goto V_53;
V_50 = V_20 |
V_54 ;
V_10 -> V_11 = true ;
V_20 = F_28 ( V_8 ,
V_52 ,
V_50 ) ;
if ( V_20 )
goto V_53;
}
return 0 ;
V_53:
return V_20 ;
}
static int F_30 ( struct V_55 * V_12 ,
bool V_49 )
{
struct V_7 * V_8 = V_12 -> V_56 ;
int V_20 = 0 ;
T_2 V_57 ;
F_26 ( V_8 , V_49 ) ;
if ( ! V_49 ) {
V_20 = F_6 ( V_8 , NULL ) ;
}
F_27 ( V_8 ,
V_58 ,
& V_57 ) ;
return V_20 ;
}
static int F_31 ( struct V_55 * V_12 )
{
struct V_7 * V_8 = V_12 -> V_56 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_21 ;
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ )
if ( F_32 ( V_10 -> V_59 ) )
F_6 ( V_8 , NULL ) ;
else
break;
if ( V_21 == 5 )
F_33 ( V_60
L_2 ) ;
return 0 ;
}
int F_34 ( struct V_7 * V_8 )
{
int V_20 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
V_10 -> V_12 = F_35 ( L_3 , V_8 -> V_61 ) ;
if ( ! V_10 -> V_12 ) {
V_20 = - V_26 ;
goto V_53;
}
V_10 -> V_12 -> V_43 . V_44 = & V_10 -> V_35 -> V_43 ;
V_10 -> V_12 -> V_62 = & V_63 ;
V_10 -> V_12 -> V_56 = V_8 ;
V_20 = F_36 ( V_10 -> V_12 ) ;
if ( V_20 )
goto V_64;
return 0 ;
V_64:
F_37 ( V_10 -> V_12 ) ;
V_53:
return V_20 ;
}
void F_38 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_39 ( V_10 -> V_12 ) ;
F_37 ( V_10 -> V_12 ) ;
}
void F_40 ( struct V_7 * V_8 )
{
F_41 ( V_8 -> V_65 ) ;
F_42 ( V_8 -> V_66 ) ;
}
static int F_43 ( struct V_7 * V_8 )
{
T_2 V_57 ;
int V_20 ;
bool V_67 = false ;
V_20 = F_27 ( V_8 ,
V_68 ,
& V_57 ) ;
if ( V_20 )
goto V_53;
if ( F_11 ( 0 , V_8 -> V_23 ) ) {
V_57 |= V_69 ;
V_67 = true ;
} else
V_57 &= ~ V_69 ;
if ( F_11 ( 1 , V_8 -> V_23 ) ) {
V_57 |= V_70 ;
V_67 = true ;
} else
V_57 &= ~ V_70 ;
if ( F_11 ( 2 , V_8 -> V_23 ) ) {
V_57 |= V_71 ;
V_67 = true ;
} else
V_57 &= ~ V_71 ;
if ( ! V_67 )
return - V_72 ;
V_20 = F_28 ( V_8 ,
V_68 ,
V_57 ) ;
if ( V_20 )
goto V_53;
return F_44 ( V_8 ) ;
V_53:
return V_20 ;
}
static int F_45 ( struct V_7 * V_8 )
{
T_2 V_57 ;
int V_20 ;
V_20 = F_46 ( V_8 ) ;
if ( V_20 )
goto V_53;
V_20 = F_27 ( V_8 ,
V_68 ,
& V_57 ) ;
if ( V_20 )
goto V_53;
V_57 |= V_69 |
V_70 |
V_71 ;
V_20 = F_28 ( V_8 ,
V_68 ,
V_57 ) ;
V_53:
return V_20 ;
}
int F_47 ( struct V_7 * V_8 )
{
int V_20 ;
struct V_73 * V_66 ;
V_66 = F_48 ( V_8 ) ;
if ( ! V_66 )
return - V_26 ;
V_8 -> V_66 = V_66 ;
V_66 -> V_46 = true ;
V_8 -> V_74 = & V_75 ;
V_8 -> V_65 = F_49 ( & V_76 ,
& F_19 ,
0 ,
V_8 ,
L_4 ,
V_8 -> V_61 ) ;
if ( V_8 -> V_65 == NULL ) {
V_20 = - V_26 ;
goto V_77;
}
V_8 -> V_78 |= V_79 ;
return 0 ;
V_77:
F_42 ( V_8 -> V_66 ) ;
return V_20 ;
}
