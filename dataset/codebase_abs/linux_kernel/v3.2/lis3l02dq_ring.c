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
T_4 F_6 ( struct V_15 * V_16 ,
int V_17 ,
int * V_18 )
{
int V_19 ;
T_5 * V_20 ;
if ( ! F_7 ( V_16 , V_17 ) )
return - V_21 ;
if ( ! V_16 -> V_22 -> V_23 )
return - V_24 ;
V_20 = F_8 ( V_16 -> V_22 -> V_25 ( V_16 ) ,
V_26 ) ;
if ( V_20 == NULL )
return - V_27 ;
V_19 = V_16 -> V_22 -> V_23 ( V_16 , ( T_2 * ) V_20 ) ;
if ( V_19 )
goto V_28;
* V_18 = V_20 [ F_9 ( V_16 -> V_29 , V_17 ) ] ;
V_28:
F_10 ( V_20 ) ;
return V_19 ;
}
static int F_11 ( struct V_7 * V_8 , T_2 * V_30 )
{
struct V_15 * V_16 = V_8 -> V_16 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_31 * V_32 ;
struct V_33 V_34 ;
int V_19 , V_35 , V_36 = 0 ;
V_32 = F_12 ( ( V_16 -> V_37 ) * 2
* sizeof( * V_32 ) , V_26 ) ;
if ( ! V_32 )
return - V_27 ;
F_13 ( & V_10 -> V_38 ) ;
for ( V_35 = 0 ; V_35 < F_14 ( V_39 ) / 4 ; V_35 ++ )
if ( F_15 ( V_35 , V_16 -> V_29 ) ) {
V_32 [ V_36 ] . V_40 = V_10 -> V_41 + 2 * V_36 ;
V_10 -> V_41 [ 2 * V_36 ] = V_39 [ V_35 * 4 ] ;
V_10 -> V_41 [ 2 * V_36 + 1 ] = 0 ;
if ( V_30 )
V_32 [ V_36 ] . V_42 = V_30 + V_36 * 2 ;
V_32 [ V_36 ] . V_43 = 8 ;
V_32 [ V_36 ] . V_44 = 2 ;
V_32 [ V_36 ] . V_45 = 1 ;
V_36 ++ ;
V_32 [ V_36 ] . V_40 = V_10 -> V_41 + 2 * V_36 ;
V_10 -> V_41 [ 2 * V_36 ] = V_39 [ V_35 * 4 + 2 ] ;
V_10 -> V_41 [ 2 * V_36 + 1 ] = 0 ;
if ( V_30 )
V_32 [ V_36 ] . V_42 = V_30 + V_36 * 2 ;
V_32 [ V_36 ] . V_43 = 8 ;
V_32 [ V_36 ] . V_44 = 2 ;
V_32 [ V_36 ] . V_45 = 1 ;
V_36 ++ ;
}
F_16 ( & V_34 ) ;
for ( V_36 = 0 ; V_36 < V_16 -> V_37 * 2 ; V_36 ++ )
F_17 ( & V_32 [ V_36 ] , & V_34 ) ;
V_19 = F_18 ( V_10 -> V_46 , & V_34 ) ;
F_19 ( & V_10 -> V_38 ) ;
F_10 ( V_32 ) ;
return V_19 ;
}
static int F_20 ( struct V_7 * V_8 ,
T_2 * V_47 )
{
int V_19 , V_35 ;
T_2 * V_30 ;
T_5 * V_20 = ( T_5 * ) V_47 ;
V_30 = F_12 ( 4 * ( V_8 -> V_16 -> V_37 ) , V_26 ) ;
if ( V_30 == NULL )
return - V_27 ;
V_19 = F_11 ( V_8 , V_30 ) ;
if ( V_19 < 0 )
return V_19 ;
for ( V_35 = 0 ; V_35 < V_8 -> V_16 -> V_37 ; V_35 ++ )
V_20 [ V_35 ] = F_1 ( V_30 [ V_35 * 4 + 1 ] ,
V_30 [ V_35 * 4 + 3 ] ) ;
F_10 ( V_30 ) ;
return V_35 * sizeof( V_20 [ 0 ] ) ;
}
static T_3 F_21 ( int V_5 , void * V_48 )
{
struct V_49 * V_50 = V_48 ;
struct V_7 * V_8 = V_50 -> V_8 ;
struct V_15 * V_16 = V_8 -> V_16 ;
int V_44 = 0 ;
T_6 V_51 = V_16 -> V_22 -> V_25 ( V_16 ) ;
char * V_20 = F_8 ( V_51 , V_26 ) ;
if ( V_20 == NULL ) {
F_22 ( V_8 -> V_52 . V_53 ,
L_1 ) ;
return - V_27 ;
}
if ( V_16 -> V_37 )
V_44 = F_20 ( V_8 , V_20 ) ;
if ( V_16 -> V_54 )
* ( V_55 * ) ( ( ( V_56 ) V_20 + V_44
+ sizeof( V_55 ) - 1 ) & ~ ( sizeof( V_55 ) - 1 ) )
= V_50 -> V_57 ;
V_16 -> V_22 -> V_58 ( V_16 , ( T_2 * ) V_20 , V_50 -> V_57 ) ;
F_23 ( V_8 -> V_12 ) ;
F_10 ( V_20 ) ;
return V_13 ;
}
static int
F_24 ( struct V_59 * V_52 , bool V_60 )
{
int V_19 ;
T_2 V_61 ;
bool V_62 ;
struct V_7 * V_8 = F_25 ( V_52 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
V_19 = F_26 ( V_8 ,
V_63 ,
& V_61 ) ;
if ( V_19 )
goto V_64;
V_62
= V_61 & V_65 ;
if ( ! V_60 && V_62 ) {
V_61 &= ~ V_65 ;
V_19 = F_27 ( V_8 ,
V_63 ,
V_61 ) ;
if ( V_19 )
goto V_64;
V_19 = F_27 ( V_8 ,
V_63 ,
V_61 ) ;
if ( V_19 )
goto V_64;
V_10 -> V_11 = false ;
} else if ( V_60 && ! V_62 ) {
V_19 = F_28 ( V_8 ) ;
if ( V_19 < 0 )
goto V_64;
V_61 = V_19 |
V_65 ;
V_10 -> V_11 = true ;
V_19 = F_27 ( V_8 ,
V_63 ,
V_61 ) ;
if ( V_19 )
goto V_64;
}
return 0 ;
V_64:
return V_19 ;
}
static int F_29 ( struct V_66 * V_12 ,
bool V_60 )
{
struct V_7 * V_8 = V_12 -> V_67 ;
int V_19 = 0 ;
T_2 V_68 ;
F_24 ( & V_8 -> V_52 , V_60 ) ;
if ( V_60 == false ) {
V_19 = F_11 ( V_8 , NULL ) ;
}
F_26 ( V_8 ,
V_69 ,
& V_68 ) ;
return V_19 ;
}
static int F_30 ( struct V_66 * V_12 )
{
struct V_7 * V_8 = V_12 -> V_67 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_35 ;
for ( V_35 = 0 ; V_35 < 5 ; V_35 ++ )
if ( F_31 ( F_32 ( V_10 -> V_46 -> V_5 ) ) )
F_11 ( V_8 , NULL ) ;
else
break;
if ( V_35 == 5 )
F_33 ( V_70
L_2 ) ;
return 0 ;
}
int F_34 ( struct V_7 * V_8 )
{
int V_19 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
V_10 -> V_12 = F_35 ( L_3 , V_8 -> V_71 ) ;
if ( ! V_10 -> V_12 ) {
V_19 = - V_27 ;
goto V_64;
}
V_10 -> V_12 -> V_52 . V_53 = & V_10 -> V_46 -> V_52 ;
V_10 -> V_12 -> V_72 = & V_73 ;
V_10 -> V_12 -> V_67 = V_8 ;
V_19 = F_36 ( V_10 -> V_12 ) ;
if ( V_19 )
goto V_74;
return 0 ;
V_74:
F_37 ( V_10 -> V_12 ) ;
V_64:
return V_19 ;
}
void F_38 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_39 ( V_10 -> V_12 ) ;
F_37 ( V_10 -> V_12 ) ;
}
void F_40 ( struct V_7 * V_8 )
{
F_41 ( V_8 -> V_75 ) ;
F_42 ( V_8 -> V_16 ) ;
}
static int F_43 ( struct V_7 * V_8 )
{
T_2 V_68 ;
int V_19 ;
bool V_76 = false ;
V_19 = F_26 ( V_8 ,
V_77 ,
& V_68 ) ;
if ( V_19 )
goto V_64;
if ( F_7 ( V_8 -> V_16 , 0 ) ) {
V_68 |= V_78 ;
V_76 = true ;
} else
V_68 &= ~ V_78 ;
if ( F_7 ( V_8 -> V_16 , 1 ) ) {
V_68 |= V_79 ;
V_76 = true ;
} else
V_68 &= ~ V_79 ;
if ( F_7 ( V_8 -> V_16 , 2 ) ) {
V_68 |= V_80 ;
V_76 = true ;
} else
V_68 &= ~ V_80 ;
if ( ! V_76 )
return - V_21 ;
V_19 = F_27 ( V_8 ,
V_77 ,
V_68 ) ;
if ( V_19 )
goto V_64;
return F_44 ( V_8 ) ;
V_64:
return V_19 ;
}
static int F_45 ( struct V_7 * V_8 )
{
T_2 V_68 ;
int V_19 ;
V_19 = F_46 ( V_8 ) ;
if ( V_19 )
goto V_64;
V_19 = F_26 ( V_8 ,
V_77 ,
& V_68 ) ;
if ( V_19 )
goto V_64;
V_68 |= V_78 |
V_79 |
V_80 ;
V_19 = F_27 ( V_8 ,
V_77 ,
V_68 ) ;
V_64:
return V_19 ;
}
int F_47 ( struct V_7 * V_8 )
{
int V_19 ;
struct V_15 * V_16 ;
V_16 = F_48 ( V_8 ) ;
if ( ! V_16 )
return - V_27 ;
V_8 -> V_16 = V_16 ;
V_8 -> V_16 -> V_22 = & V_81 ;
V_16 -> V_82 = 2 ;
V_16 -> V_54 = true ;
V_16 -> V_83 = & V_84 ;
V_16 -> V_85 = V_86 ;
V_8 -> V_75 = F_49 ( & V_87 ,
& F_21 ,
0 ,
V_8 ,
L_4 ,
V_8 -> V_71 ) ;
if ( V_8 -> V_75 == NULL ) {
V_19 = - V_27 ;
goto V_88;
}
V_8 -> V_89 |= V_90 ;
return 0 ;
V_88:
F_42 ( V_8 -> V_16 ) ;
return V_19 ;
}
