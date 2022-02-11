static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 V_7 ;
if ( F_2 ( V_4 -> V_8 , 0 , ( V_9 ) & V_7 ,
sizeof( struct V_6 ) , V_10 ) !=
sizeof( struct V_6 ) ) {
F_3 ( V_11 L_1 ) ;
return;
}
if ( V_7 . V_12 != V_4 -> V_13 ) {
F_4 ( V_2 -> V_14 , L_2 , V_4 -> V_15 ) ;
V_4 -> V_13 = V_7 . V_12 ;
F_5 ( V_2 , 0 , 0 , 0 , 0 , 0 , V_2 -> V_16 ) ;
}
}
static int T_1 F_6 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_19 [ 0 ] ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 V_21 ;
if ( F_2 ( V_4 -> V_8 , 0 , ( V_9 ) & V_21 ,
sizeof( struct V_20 ) , V_22 ) !=
sizeof( struct V_20 ) ) {
F_3 ( V_11 L_3 ) ;
return - 1 ;
}
if ( V_21 . V_23 )
V_18 -> V_24 = V_25 ;
else
V_18 -> V_24 = V_26 ;
switch ( V_21 . V_27 ) {
case V_28 :
V_18 -> V_29 = V_30 ;
break;
case V_31 :
V_18 -> V_29 = V_32 ;
break;
default:
return - 1 ;
}
V_18 -> V_33 = 0 ;
V_18 -> V_34 = V_21 . V_35 >> V_36 ;
V_18 -> V_37 = V_18 -> V_33 + V_18 -> V_34 - 1 ;
V_18 -> V_38 = V_39 ;
V_18 -> V_40 = V_41 ;
return 0 ;
}
static int T_1 F_7 ( struct V_42 * V_43 )
{
char V_44 [ 32 ] ;
int V_8 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_45 ;
sprintf ( V_44 , L_4 , V_43 -> V_46 ) ;
V_8 = F_8 ( ( V_9 ) V_44 , 0 ) ;
if ( V_8 < 0 )
return - V_47 ;
V_2 = F_9 ( sizeof( struct V_3 ) ,
V_48 , V_49 , V_43 -> V_46 ) ;
if ( V_2 == NULL )
return - V_50 ;
V_4 = V_2 -> V_5 ;
V_4 -> V_15 = V_43 -> V_46 ;
V_4 -> V_8 = V_8 ;
V_2 -> V_14 = & V_43 -> V_14 ;
V_2 -> V_51 = V_52 ;
V_2 -> V_53 = V_54 ;
V_2 -> V_55 = V_11 ;
#ifdef F_10
V_2 -> V_16 = L_5 ;
#else
V_2 -> V_16 = L_6 ;
#endif
V_2 -> V_56 = V_56 ( & V_43 -> V_14 ) ;
V_2 -> V_57 = F_1 ;
if ( F_6 ( V_2 ) ) {
V_2 -> V_58 = V_59 ;
} else {
V_2 -> V_58 = V_54 ;
}
F_11 ( V_43 , V_2 ) ;
V_45 = F_12 ( V_2 ) ;
if ( V_45 ) {
F_13 ( & V_43 -> V_14 , L_7 ) ;
F_14 ( V_2 ) ;
return V_45 ;
}
return 0 ;
}
static int T_2 F_15 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_16 ( V_43 ) ;
F_17 ( & V_43 -> V_14 ) ;
if ( V_2 )
F_14 ( V_2 ) ;
return 0 ;
}
static int T_3 F_18 ( void )
{
char V_44 [ 32 ] ;
struct V_42 * V_43 ;
int V_60 , V_61 , V_62 = 0 ;
V_63 = V_64 ;
V_61 = F_19 ( & V_65 ) ;
if ( V_61 )
return V_61 ;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
sprintf ( V_44 , L_4 , V_60 ) ;
if ( F_8 ( ( V_9 ) V_44 , 0 ) < 0 )
continue;
V_43 = F_20 ( V_11 , V_60 , NULL , 0 ) ;
if ( F_21 ( V_43 ) )
continue;
V_67 [ V_60 ] = V_43 ;
V_62 ++ ;
}
if ( V_62 == 0 ) {
F_22 ( & V_65 ) ;
return - V_68 ;
}
return 0 ;
}
static void T_4 F_23 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
struct V_42 * V_43 = V_67 [ V_60 ] ;
if ( ! V_43 )
continue;
F_11 ( V_43 , NULL ) ;
F_24 ( V_43 ) ;
}
F_22 ( & V_65 ) ;
}
