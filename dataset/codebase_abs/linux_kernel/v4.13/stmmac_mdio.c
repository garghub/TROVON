static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_7 = F_2 ( V_6 ) ;
unsigned int V_9 = V_7 -> V_10 -> V_11 . V_12 ;
unsigned int V_13 = V_7 -> V_10 -> V_11 . V_14 ;
T_1 V_15 ;
int V_14 ;
T_1 V_16 = V_17 ;
V_16 |= ( V_3 << V_7 -> V_10 -> V_11 . V_18 )
& V_7 -> V_10 -> V_11 . V_19 ;
V_16 |= ( V_4 << V_7 -> V_10 -> V_11 . V_20 ) & V_7 -> V_10 -> V_11 . V_21 ;
V_16 |= ( V_7 -> V_22 << V_7 -> V_10 -> V_11 . V_23 )
& V_7 -> V_10 -> V_11 . V_24 ;
if ( V_7 -> V_25 -> V_26 )
V_16 |= V_27 ;
if ( F_3 ( V_7 -> V_28 + V_9 , V_15 , ! ( V_15 & V_17 ) ,
100 , 10000 ) )
return - V_29 ;
F_4 ( V_16 , V_7 -> V_28 + V_9 ) ;
if ( F_3 ( V_7 -> V_28 + V_9 , V_15 , ! ( V_15 & V_17 ) ,
100 , 10000 ) )
return - V_29 ;
V_14 = ( int ) F_5 ( V_7 -> V_28 + V_13 ) ;
return V_14 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_2 V_30 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_7 = F_2 ( V_6 ) ;
unsigned int V_9 = V_7 -> V_10 -> V_11 . V_12 ;
unsigned int V_13 = V_7 -> V_10 -> V_11 . V_14 ;
T_1 V_15 ;
T_1 V_16 = V_17 ;
V_16 |= ( V_3 << V_7 -> V_10 -> V_11 . V_18 )
& V_7 -> V_10 -> V_11 . V_19 ;
V_16 |= ( V_4 << V_7 -> V_10 -> V_11 . V_20 ) & V_7 -> V_10 -> V_11 . V_21 ;
V_16 |= ( V_7 -> V_22 << V_7 -> V_10 -> V_11 . V_23 )
& V_7 -> V_10 -> V_11 . V_24 ;
if ( V_7 -> V_25 -> V_26 )
V_16 |= V_31 ;
else
V_16 |= V_32 ;
if ( F_3 ( V_7 -> V_28 + V_9 , V_15 , ! ( V_15 & V_17 ) ,
100 , 10000 ) )
return - V_29 ;
F_4 ( V_30 , V_7 -> V_28 + V_13 ) ;
F_4 ( V_16 , V_7 -> V_28 + V_9 ) ;
return F_3 ( V_7 -> V_28 + V_9 , V_15 , ! ( V_15 & V_17 ) ,
100 , 10000 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
#if F_8 ( V_33 )
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_7 = F_2 ( V_6 ) ;
unsigned int V_9 = V_7 -> V_10 -> V_11 . V_12 ;
struct V_34 * V_14 = V_7 -> V_25 -> V_35 ;
#ifdef F_9
if ( V_7 -> V_36 -> V_37 ) {
if ( V_14 -> V_38 < 0 ) {
struct V_39 * V_40 = V_7 -> V_36 -> V_37 ;
if ( ! V_40 )
return 0 ;
V_14 -> V_38 = F_10 ( V_40 ,
L_1 , 0 ) ;
if ( V_14 -> V_38 < 0 )
return 0 ;
V_14 -> V_41 = F_11 ( V_40 ,
L_2 ) ;
F_12 ( V_40 ,
L_3 , V_14 -> V_42 , 3 ) ;
if ( F_13 ( V_14 -> V_38 , L_4 ) )
return 0 ;
}
F_14 ( V_14 -> V_38 ,
V_14 -> V_41 ? 1 : 0 ) ;
if ( V_14 -> V_42 [ 0 ] )
F_15 ( F_16 ( V_14 -> V_42 [ 0 ] , 1000 ) ) ;
F_17 ( V_14 -> V_38 , V_14 -> V_41 ? 0 : 1 ) ;
if ( V_14 -> V_42 [ 1 ] )
F_15 ( F_16 ( V_14 -> V_42 [ 1 ] , 1000 ) ) ;
F_17 ( V_14 -> V_38 , V_14 -> V_41 ? 1 : 0 ) ;
if ( V_14 -> V_42 [ 2 ] )
F_15 ( F_16 ( V_14 -> V_42 [ 2 ] , 1000 ) ) ;
}
#endif
if ( V_14 -> V_43 ) {
F_18 ( V_6 , L_5 ) ;
V_14 -> V_43 ( V_7 -> V_25 -> V_44 ) ;
}
if ( ! V_7 -> V_25 -> V_26 )
F_4 ( 0 , V_7 -> V_28 + V_9 ) ;
#endif
return 0 ;
}
int F_19 ( struct V_5 * V_6 )
{
int V_45 = 0 ;
struct V_1 * V_46 ;
struct V_8 * V_7 = F_2 ( V_6 ) ;
struct V_34 * V_35 = V_7 -> V_25 -> V_35 ;
struct V_39 * V_47 = V_7 -> V_25 -> V_47 ;
struct V_36 * V_48 = V_6 -> V_48 . V_49 ;
int V_12 , V_50 ;
if ( ! V_35 )
return 0 ;
V_46 = F_20 () ;
if ( ! V_46 )
return - V_51 ;
if ( V_35 -> V_52 )
memcpy ( V_46 -> V_53 , V_35 -> V_52 , sizeof( V_46 -> V_53 ) ) ;
#ifdef F_9
if ( V_7 -> V_36 -> V_37 )
V_35 -> V_38 = - 1 ;
#endif
V_46 -> V_54 = L_6 ;
V_46 -> V_55 = & F_1 ;
V_46 -> V_56 = & F_6 ;
V_46 -> V_57 = & F_7 ;
snprintf ( V_46 -> V_58 , V_59 , L_7 ,
V_46 -> V_54 , V_7 -> V_25 -> V_60 ) ;
V_46 -> V_7 = V_6 ;
V_46 -> V_61 = V_35 -> V_61 ;
V_46 -> V_49 = V_7 -> V_36 ;
if ( V_47 )
V_45 = F_21 ( V_46 , V_47 ) ;
else
V_45 = F_22 ( V_46 ) ;
if ( V_45 != 0 ) {
F_23 ( V_48 , L_8 ) ;
goto V_62;
}
if ( V_7 -> V_25 -> V_63 || V_47 )
goto V_64;
V_50 = 0 ;
for ( V_12 = 0 ; V_12 < V_65 ; V_12 ++ ) {
struct V_66 * V_67 = F_24 ( V_46 , V_12 ) ;
int V_68 = 0 ;
char V_69 [ 4 ] ;
char * V_70 ;
if ( ! V_67 )
continue;
if ( ! V_35 -> V_52 &&
( V_35 -> V_71 > 0 ) ) {
V_46 -> V_53 [ V_12 ] = V_35 -> V_71 ;
V_67 -> V_53 = V_35 -> V_71 ;
}
if ( V_7 -> V_25 -> V_72 == - 1 )
V_7 -> V_25 -> V_72 = V_12 ;
V_68 = ( V_7 -> V_25 -> V_72 == V_12 ) ;
switch ( V_67 -> V_53 ) {
case V_73 :
V_70 = L_9 ;
break;
case V_74 :
V_70 = L_10 ;
break;
default:
sprintf ( V_69 , L_11 , V_67 -> V_53 ) ;
V_70 = V_69 ;
break;
}
F_25 ( V_67 ) ;
V_50 = 1 ;
}
if ( ! V_50 && ! V_47 ) {
F_26 ( V_48 , L_12 ) ;
F_27 ( V_46 ) ;
F_28 ( V_46 ) ;
return - V_75 ;
}
V_64:
V_7 -> V_11 = V_46 ;
return 0 ;
V_62:
F_28 ( V_46 ) ;
return V_45 ;
}
int F_29 ( struct V_5 * V_6 )
{
struct V_8 * V_7 = F_2 ( V_6 ) ;
if ( ! V_7 -> V_11 )
return 0 ;
F_27 ( V_7 -> V_11 ) ;
V_7 -> V_11 -> V_7 = NULL ;
F_28 ( V_7 -> V_11 ) ;
V_7 -> V_11 = NULL ;
return 0 ;
}
