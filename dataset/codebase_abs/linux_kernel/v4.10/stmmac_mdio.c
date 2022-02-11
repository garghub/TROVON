static int F_1 ( void T_1 * V_1 , unsigned int V_2 )
{
unsigned long V_3 ;
unsigned long V_4 = V_5 + 3 * V_6 ;
do {
V_3 = V_5 ;
if ( F_2 ( V_1 + V_2 ) & V_7 )
F_3 () ;
else
return 0 ;
} while ( ! F_4 ( V_3 , V_4 ) );
return - V_8 ;
}
static int F_5 ( struct V_9 * V_10 , int V_11 , int V_12 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_15 = F_6 ( V_14 ) ;
unsigned int V_17 = V_15 -> V_18 -> V_19 . V_20 ;
unsigned int V_21 = V_15 -> V_18 -> V_19 . V_22 ;
int V_22 ;
T_2 V_23 = V_7 ;
V_23 |= ( V_11 << V_15 -> V_18 -> V_19 . V_24 )
& V_15 -> V_18 -> V_19 . V_25 ;
V_23 |= ( V_12 << V_15 -> V_18 -> V_19 . V_26 ) & V_15 -> V_18 -> V_19 . V_27 ;
V_23 |= ( V_15 -> V_28 << V_15 -> V_18 -> V_19 . V_29 )
& V_15 -> V_18 -> V_19 . V_30 ;
if ( V_15 -> V_31 -> V_32 )
V_23 |= V_33 ;
if ( F_1 ( V_15 -> V_1 , V_17 ) )
return - V_8 ;
F_7 ( V_23 , V_15 -> V_1 + V_17 ) ;
if ( F_1 ( V_15 -> V_1 , V_17 ) )
return - V_8 ;
V_22 = ( int ) F_2 ( V_15 -> V_1 + V_21 ) ;
return V_22 ;
}
static int F_8 ( struct V_9 * V_10 , int V_11 , int V_12 ,
T_3 V_34 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_15 = F_6 ( V_14 ) ;
unsigned int V_17 = V_15 -> V_18 -> V_19 . V_20 ;
unsigned int V_21 = V_15 -> V_18 -> V_19 . V_22 ;
T_2 V_23 = V_7 ;
V_23 |= ( V_11 << V_15 -> V_18 -> V_19 . V_24 )
& V_15 -> V_18 -> V_19 . V_25 ;
V_23 |= ( V_12 << V_15 -> V_18 -> V_19 . V_26 ) & V_15 -> V_18 -> V_19 . V_27 ;
V_23 |= ( V_15 -> V_28 << V_15 -> V_18 -> V_19 . V_29 )
& V_15 -> V_18 -> V_19 . V_30 ;
if ( V_15 -> V_31 -> V_32 )
V_23 |= V_35 ;
else
V_23 |= V_36 ;
if ( F_1 ( V_15 -> V_1 , V_17 ) )
return - V_8 ;
F_7 ( V_34 , V_15 -> V_1 + V_21 ) ;
F_7 ( V_23 , V_15 -> V_1 + V_17 ) ;
return F_1 ( V_15 -> V_1 , V_17 ) ;
}
int F_9 ( struct V_9 * V_10 )
{
#if F_10 ( V_37 )
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_15 = F_6 ( V_14 ) ;
unsigned int V_17 = V_15 -> V_18 -> V_19 . V_20 ;
struct V_38 * V_22 = V_15 -> V_31 -> V_39 ;
#ifdef F_11
if ( V_15 -> V_40 -> V_41 ) {
if ( V_22 -> V_42 < 0 ) {
struct V_43 * V_44 = V_15 -> V_40 -> V_41 ;
if ( ! V_44 )
return 0 ;
V_22 -> V_42 = F_12 ( V_44 ,
L_1 , 0 ) ;
if ( V_22 -> V_42 < 0 )
return 0 ;
V_22 -> V_45 = F_13 ( V_44 ,
L_2 ) ;
F_14 ( V_44 ,
L_3 , V_22 -> V_46 , 3 ) ;
if ( F_15 ( V_22 -> V_42 , L_4 ) )
return 0 ;
}
F_16 ( V_22 -> V_42 ,
V_22 -> V_45 ? 1 : 0 ) ;
if ( V_22 -> V_46 [ 0 ] )
F_17 ( F_18 ( V_22 -> V_46 [ 0 ] , 1000 ) ) ;
F_19 ( V_22 -> V_42 , V_22 -> V_45 ? 0 : 1 ) ;
if ( V_22 -> V_46 [ 1 ] )
F_17 ( F_18 ( V_22 -> V_46 [ 1 ] , 1000 ) ) ;
F_19 ( V_22 -> V_42 , V_22 -> V_45 ? 1 : 0 ) ;
if ( V_22 -> V_46 [ 2 ] )
F_17 ( F_18 ( V_22 -> V_46 [ 2 ] , 1000 ) ) ;
}
#endif
if ( V_22 -> V_47 ) {
F_20 ( V_14 , L_5 ) ;
V_22 -> V_47 ( V_15 -> V_31 -> V_48 ) ;
}
if ( ! V_15 -> V_31 -> V_32 )
F_7 ( 0 , V_15 -> V_1 + V_17 ) ;
#endif
return 0 ;
}
int F_21 ( struct V_13 * V_14 )
{
int V_49 = 0 ;
struct V_9 * V_50 ;
struct V_16 * V_15 = F_6 ( V_14 ) ;
struct V_38 * V_39 = V_15 -> V_31 -> V_39 ;
struct V_43 * V_51 = V_15 -> V_31 -> V_51 ;
int V_20 , V_52 ;
if ( ! V_39 )
return 0 ;
V_50 = F_22 () ;
if ( V_50 == NULL )
return - V_53 ;
if ( V_39 -> V_54 )
memcpy ( V_50 -> V_55 , V_39 -> V_54 , sizeof( V_50 -> V_55 ) ) ;
#ifdef F_11
if ( V_15 -> V_40 -> V_41 )
V_39 -> V_42 = - 1 ;
#endif
V_50 -> V_56 = L_6 ;
V_50 -> V_57 = & F_5 ;
V_50 -> V_58 = & F_8 ;
V_50 -> V_59 = & F_9 ;
snprintf ( V_50 -> V_60 , V_61 , L_7 ,
V_50 -> V_56 , V_15 -> V_31 -> V_62 ) ;
V_50 -> V_15 = V_14 ;
V_50 -> V_63 = V_39 -> V_63 ;
V_50 -> V_64 = V_15 -> V_40 ;
if ( V_51 )
V_49 = F_23 ( V_50 , V_51 ) ;
else
V_49 = F_24 ( V_50 ) ;
if ( V_49 != 0 ) {
F_25 ( V_14 , L_8 ) ;
goto V_65;
}
if ( V_15 -> V_31 -> V_66 || V_51 )
goto V_67;
V_52 = 0 ;
for ( V_20 = 0 ; V_20 < V_68 ; V_20 ++ ) {
struct V_69 * V_70 = F_26 ( V_50 , V_20 ) ;
if ( V_70 ) {
int V_71 = 0 ;
char V_72 [ 4 ] ;
char * V_73 ;
if ( ( V_39 -> V_54 == NULL ) &&
( V_39 -> V_74 > 0 ) ) {
V_50 -> V_55 [ V_20 ] =
V_39 -> V_74 ;
V_70 -> V_55 = V_39 -> V_74 ;
}
if ( V_15 -> V_31 -> V_75 == - 1 )
V_15 -> V_31 -> V_75 = V_20 ;
V_71 = ( V_15 -> V_31 -> V_75 == V_20 ) ;
switch ( V_70 -> V_55 ) {
case V_76 :
V_73 = L_9 ;
break;
case V_77 :
V_73 = L_10 ;
break;
default:
sprintf ( V_72 , L_11 , V_70 -> V_55 ) ;
V_73 = V_72 ;
break;
}
F_27 ( V_14 , L_12 ,
V_70 -> V_78 , V_20 ,
V_73 , F_28 ( V_70 ) ,
V_71 ? L_13 : L_14 ) ;
V_52 = 1 ;
}
}
if ( ! V_52 && ! V_51 ) {
F_29 ( V_14 , L_15 ) ;
F_30 ( V_50 ) ;
F_31 ( V_50 ) ;
return - V_79 ;
}
V_67:
V_15 -> V_19 = V_50 ;
return 0 ;
V_65:
F_31 ( V_50 ) ;
return V_49 ;
}
int F_32 ( struct V_13 * V_14 )
{
struct V_16 * V_15 = F_6 ( V_14 ) ;
if ( ! V_15 -> V_19 )
return 0 ;
F_30 ( V_15 -> V_19 ) ;
V_15 -> V_19 -> V_15 = NULL ;
F_31 ( V_15 -> V_19 ) ;
V_15 -> V_19 = NULL ;
return 0 ;
}
