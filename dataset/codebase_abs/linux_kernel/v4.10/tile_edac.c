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
F_5 ( V_16 , V_2 , 1 ,
0 , 0 , 0 ,
0 , 0 , - 1 ,
V_2 -> V_17 , L_3 ) ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 [ 0 ] ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_21 V_22 ;
struct V_23 * V_24 = V_19 -> V_25 [ 0 ] -> V_24 ;
if ( F_2 ( V_4 -> V_8 , 0 , ( V_9 ) & V_22 ,
sizeof( struct V_21 ) , V_26 ) !=
sizeof( struct V_21 ) ) {
F_3 ( V_11 L_4 ) ;
return - 1 ;
}
if ( V_22 . V_27 )
V_24 -> V_28 = V_29 ;
else
V_24 -> V_28 = V_30 ;
switch ( V_22 . V_31 ) {
case V_32 :
V_24 -> V_33 = V_34 ;
break;
case V_35 :
V_24 -> V_33 = V_36 ;
break;
default:
return - 1 ;
}
V_24 -> V_37 = V_22 . V_38 >> V_39 ;
V_24 -> V_40 = V_41 ;
V_24 -> V_42 = V_43 ;
return 0 ;
}
static int F_7 ( struct V_44 * V_14 )
{
char V_45 [ 32 ] ;
int V_8 ;
struct V_1 * V_2 ;
struct V_46 V_47 [ 2 ] ;
struct V_3 * V_4 ;
int V_48 ;
sprintf ( V_45 , L_5 , V_14 -> V_49 ) ;
V_8 = F_8 ( ( V_9 ) V_45 , 0 ) ;
if ( V_8 < 0 )
return - V_50 ;
V_47 [ 0 ] . type = V_51 ;
V_47 [ 0 ] . V_52 = V_53 ;
V_47 [ 0 ] . V_54 = true ;
V_47 [ 1 ] . type = V_55 ;
V_47 [ 1 ] . V_52 = V_56 ;
V_47 [ 1 ] . V_54 = false ;
V_2 = F_9 ( V_14 -> V_49 , F_10 ( V_47 ) , V_47 ,
sizeof( struct V_3 ) ) ;
if ( V_2 == NULL )
return - V_57 ;
V_4 = V_2 -> V_5 ;
V_4 -> V_15 = V_14 -> V_49 ;
V_4 -> V_8 = V_8 ;
V_2 -> V_14 = & V_14 -> V_58 ;
V_2 -> V_59 = V_60 ;
V_2 -> V_61 = V_62 ;
V_2 -> V_63 = V_11 ;
#ifdef F_11
V_2 -> V_17 = L_6 ;
#else
V_2 -> V_17 = L_7 ;
#endif
V_2 -> V_64 = V_64 ( & V_14 -> V_58 ) ;
V_2 -> V_65 = F_1 ;
if ( F_6 ( V_2 ) ) {
V_2 -> V_66 = V_67 ;
} else {
V_2 -> V_66 = V_62 ;
}
F_12 ( V_14 , V_2 ) ;
V_48 = F_13 ( V_2 ) ;
if ( V_48 ) {
F_14 ( & V_14 -> V_58 , L_8 ) ;
F_15 ( V_2 ) ;
return V_48 ;
}
return 0 ;
}
static int F_16 ( struct V_44 * V_14 )
{
struct V_1 * V_2 = F_17 ( V_14 ) ;
F_18 ( & V_14 -> V_58 ) ;
if ( V_2 )
F_15 ( V_2 ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
char V_45 [ 32 ] ;
struct V_44 * V_14 ;
int V_68 , V_69 , V_70 = 0 ;
V_71 = V_72 ;
V_69 = F_20 ( & V_73 ) ;
if ( V_69 )
return V_69 ;
for ( V_68 = 0 ; V_68 < V_74 ; V_68 ++ ) {
sprintf ( V_45 , L_5 , V_68 ) ;
if ( F_8 ( ( V_9 ) V_45 , 0 ) < 0 )
continue;
V_14 = F_21 ( V_11 , V_68 , NULL , 0 ) ;
if ( F_22 ( V_14 ) )
continue;
V_75 [ V_68 ] = V_14 ;
V_70 ++ ;
}
if ( V_70 == 0 ) {
F_23 ( & V_73 ) ;
return - V_76 ;
}
return 0 ;
}
static void T_2 F_24 ( void )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_74 ; V_68 ++ ) {
struct V_44 * V_14 = V_75 [ V_68 ] ;
if ( ! V_14 )
continue;
F_25 ( V_14 ) ;
}
F_23 ( & V_73 ) ;
}
