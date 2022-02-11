static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
struct V_4 * V_5 ,
enum V_6 V_7 )
{
unsigned int V_8 , V_9 ;
const struct V_10 * V_11 ;
struct V_10 V_12 ;
void * V_13 ;
int V_14 = V_15 ;
int V_16 = F_2 ( V_7 ) ;
struct V_17 * V_18 = F_3 ( V_5 ) ;
struct V_19 * exp ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
if ( V_7 != V_26 &&
V_7 != V_27 )
return V_15 ;
V_11 = F_4 ( V_2 , V_3 , sizeof( V_12 ) , & V_12 ) ;
if ( V_11 == NULL )
return V_15 ;
V_8 = V_3 + V_11 -> V_28 * 4 ;
if ( V_8 >= V_2 -> V_29 )
return V_15 ;
V_9 = V_2 -> V_29 - V_8 ;
F_5 ( & V_30 ) ;
V_13 = F_4 ( V_2 , V_8 , V_9 , V_31 ) ;
F_6 ( V_13 == NULL ) ;
if ( V_16 == V_32 ) {
if ( V_9 != sizeof( struct V_22 ) )
goto V_33;
V_23 = V_13 ;
if ( V_23 -> V_34 != F_7 ( V_35 ) ) {
V_18 -> V_36 = V_37 ;
goto V_33;
}
V_18 -> V_36 = V_38 ;
goto V_33;
}
if ( V_18 -> V_36 != V_38 )
goto V_33;
V_18 -> V_36 = V_37 ;
if ( V_9 < sizeof( struct V_24 ) ) {
F_8 ( L_1 ) ;
goto V_33;
}
V_25 = V_13 ;
if ( V_25 -> V_39 != F_7 ( V_40 ) ) {
F_8 ( L_2 ,
F_9 ( V_25 -> V_39 ) ) ;
goto V_33;
}
if ( V_25 -> V_41 != 0 )
goto V_33;
exp = F_10 ( V_5 ) ;
if ( exp == NULL ) {
V_14 = V_42 ;
goto V_33;
}
V_21 = & V_5 -> V_43 [ V_32 ] . V_21 ;
F_11 ( exp , V_44 , F_12 ( V_5 ) ,
& V_21 -> V_45 . V_46 , & V_21 -> V_47 . V_46 ,
V_48 , NULL , & V_25 -> V_49 ) ;
F_8 ( L_3 ) ;
F_13 ( & exp -> V_21 ) ;
if ( F_14 ( exp ) != 0 )
V_14 = V_42 ;
F_15 ( exp ) ;
V_33:
F_16 ( & V_30 ) ;
return V_14 ;
}
static void F_17 ( void )
{
int V_50 , V_51 ;
for ( V_50 = 0 ; V_50 < V_52 ; V_50 ++ ) {
for ( V_51 = 0 ; V_51 < 2 ; V_51 ++ ) {
F_8 ( L_4
L_5 ,
V_53 [ V_50 ] [ V_51 ] . V_21 . V_45 . V_54 , V_55 [ V_50 ] ) ;
F_18 ( & V_53 [ V_50 ] [ V_51 ] ) ;
}
}
F_19 ( V_31 ) ;
}
static int T_1 F_20 ( void )
{
int V_50 , V_51 = - 1 , V_14 = 0 ;
V_31 = F_21 ( 65536 , V_56 ) ;
if ( ! V_31 )
return - V_57 ;
if ( V_52 == 0 )
V_55 [ V_52 ++ ] = V_58 ;
for ( V_50 = 0 ; V_50 < V_52 ; V_50 ++ ) {
V_53 [ V_50 ] [ 0 ] . V_21 . V_45 . V_54 = V_59 ;
V_53 [ V_50 ] [ 1 ] . V_21 . V_45 . V_54 = V_60 ;
for ( V_51 = 0 ; V_51 < 2 ; V_51 ++ ) {
V_53 [ V_50 ] [ V_51 ] . V_61 = sizeof( struct V_17 ) ;
V_53 [ V_50 ] [ V_51 ] . V_21 . V_45 . V_62 . V_63 . V_49 = F_22 ( V_55 [ V_50 ] ) ;
V_53 [ V_50 ] [ V_51 ] . V_21 . V_47 . V_64 = V_48 ;
V_53 [ V_50 ] [ V_51 ] . V_65 = & V_66 ;
V_53 [ V_50 ] [ V_51 ] . V_67 = V_68 ;
V_53 [ V_50 ] [ V_51 ] . F_1 = F_1 ;
if ( V_55 [ V_50 ] == V_58 )
sprintf ( V_53 [ V_50 ] [ V_51 ] . V_69 , L_6 ) ;
else
sprintf ( V_53 [ V_50 ] [ V_51 ] . V_69 , L_7 , V_55 [ V_50 ] ) ;
F_8 ( L_8
L_5 ,
V_53 [ V_50 ] [ V_51 ] . V_21 . V_45 . V_54 , V_55 [ V_50 ] ) ;
V_14 = F_23 ( & V_53 [ V_50 ] [ V_51 ] ) ;
if ( V_14 ) {
F_24 ( V_70 L_9
L_10 ,
V_53 [ V_50 ] [ V_51 ] . V_21 . V_45 . V_54 , V_55 [ V_50 ] ) ;
F_17 () ;
return V_14 ;
}
}
}
return 0 ;
}
