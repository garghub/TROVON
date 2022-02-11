static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_2 = ( void * ) V_1 ;
struct V_3 * V_4 ;
int V_5 , V_6 , V_7 ;
for ( V_7 = 0 ; V_7 < 7 ; V_7 ++ )
if ( V_2 -> V_8 & ( 1 << V_7 ) ) {
V_4 = V_2 -> V_4 [ V_7 ] ;
F_2 ( V_2 -> V_9 -> V_10 , ~ ( 1 << V_7 ) ) ;
V_5 = F_3 ( V_2 -> V_9 -> V_10 ) ^ 0x7f ;
V_6 = F_4 ( V_2 -> V_9 -> V_10 ) ^ 0x04 ;
F_5 ( V_4 , V_11 , ! ! ( V_5 & V_12 ) - ! ! ( V_5 & V_13 ) ) ;
F_5 ( V_4 , V_14 , ! ! ( V_5 & V_15 ) - ! ! ( V_5 & V_16 ) ) ;
F_6 ( V_4 , V_17 , ( V_5 & V_18 ) ) ;
F_6 ( V_4 , V_19 , ( V_6 & V_20 ) ) ;
F_6 ( V_4 , V_21 , ( V_6 & V_22 ) ) ;
F_6 ( V_4 , V_23 , ( V_6 & V_24 ) ) ;
F_6 ( V_4 , V_25 , ( V_6 & V_26 ) ) ;
F_7 ( V_4 ) ;
}
F_8 ( & V_2 -> V_27 , V_28 + V_29 ) ;
}
static int F_9 ( struct V_3 * V_4 )
{
struct V_2 * V_2 = F_10 ( V_4 ) ;
int V_30 ;
V_30 = F_11 ( & V_2 -> V_31 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_2 -> V_32 ++ ) {
F_12 ( V_2 -> V_9 ) ;
F_13 ( V_2 -> V_9 -> V_10 , 0x04 ) ;
F_8 ( & V_2 -> V_27 , V_28 + V_29 ) ;
}
F_14 ( & V_2 -> V_31 ) ;
return 0 ;
}
static void F_15 ( struct V_3 * V_4 )
{
struct V_2 * V_2 = F_10 ( V_4 ) ;
F_16 ( & V_2 -> V_31 ) ;
if ( ! -- V_2 -> V_32 ) {
F_17 ( & V_2 -> V_27 ) ;
F_13 ( V_2 -> V_9 -> V_10 , 0x00 ) ;
F_18 ( V_2 -> V_9 ) ;
}
F_14 ( & V_2 -> V_31 ) ;
}
static struct V_2 T_1 * F_19 ( int V_33 , int * V_34 , int V_35 )
{
struct V_2 * V_2 ;
struct V_3 * V_3 ;
struct V_33 * V_36 ;
struct V_37 * V_9 ;
int V_7 , V_38 ;
int V_30 ;
V_36 = F_20 ( V_33 ) ;
if ( ! V_36 ) {
F_21 ( V_39 L_1 ) ;
V_30 = - V_40 ;
goto V_41;
}
V_9 = F_22 ( V_36 , L_2 , NULL , NULL , NULL , V_42 , NULL ) ;
if ( ! V_9 ) {
F_21 ( V_39 L_3 ) ;
V_30 = - V_43 ;
goto V_44;
}
V_2 = F_23 ( sizeof( struct V_2 ) , V_45 ) ;
if ( ! V_2 ) {
F_21 ( V_39 L_4 ) ;
V_30 = - V_46 ;
goto V_47;
}
F_24 ( & V_2 -> V_31 ) ;
V_2 -> V_9 = V_9 ;
F_25 ( & V_2 -> V_27 ) ;
V_2 -> V_27 . V_48 = ( long ) V_2 ;
V_2 -> V_27 . V_49 = F_1 ;
for ( V_7 = 0 ; V_7 < V_35 ; V_7 ++ ) {
if ( V_34 [ V_7 ] < 1 )
continue;
if ( V_34 [ V_7 ] > F_26 ( V_50 ) ) {
F_21 ( V_39 L_5 , V_34 [ V_7 ] ) ;
V_30 = - V_40 ;
goto V_51;
}
V_2 -> V_4 [ V_7 ] = V_3 = F_27 () ;
if ( ! V_3 ) {
F_21 ( V_39 L_6 ) ;
V_30 = - V_46 ;
goto V_51;
}
V_2 -> V_8 |= ( 1 << V_7 ) ;
snprintf ( V_2 -> V_52 [ V_7 ] , sizeof( V_2 -> V_52 [ V_7 ] ) ,
L_7 , V_34 [ V_7 ] ) ;
snprintf ( V_2 -> V_53 [ V_7 ] , sizeof( V_2 -> V_53 [ V_7 ] ) ,
L_8 , V_2 -> V_9 -> V_10 -> V_52 , V_7 ) ;
V_3 -> V_52 = V_2 -> V_52 [ V_7 ] ;
V_3 -> V_53 = V_2 -> V_53 [ V_7 ] ;
V_3 -> V_54 . V_55 = V_56 ;
V_3 -> V_54 . V_57 = 0x0003 ;
V_3 -> V_54 . V_58 = V_34 [ V_7 ] ;
V_3 -> V_54 . V_59 = 0x0100 ;
F_28 ( V_3 , V_2 ) ;
V_3 -> V_60 = F_9 ;
V_3 -> V_61 = F_15 ;
V_3 -> V_62 [ 0 ] = F_29 ( V_63 ) | F_29 ( V_64 ) ;
F_30 ( V_3 , V_11 , - 1 , 1 , 0 , 0 ) ;
F_30 ( V_3 , V_14 , - 1 , 1 , 0 , 0 ) ;
for ( V_38 = 0 ; V_38 < V_34 [ V_7 ] ; V_38 ++ )
F_31 ( V_50 [ V_38 ] , V_3 -> V_65 ) ;
V_30 = F_32 ( V_2 -> V_4 [ V_7 ] ) ;
if ( V_30 )
goto V_66;
}
if ( ! V_2 -> V_8 ) {
F_21 ( V_39 L_9 ) ;
V_30 = - V_40 ;
goto V_67;
}
F_33 ( V_36 ) ;
return V_2 ;
V_66:
F_34 ( V_2 -> V_4 [ V_7 ] ) ;
V_51:
while ( -- V_7 >= 0 )
if ( V_2 -> V_4 [ V_7 ] )
F_35 ( V_2 -> V_4 [ V_7 ] ) ;
V_67:
F_36 ( V_2 ) ;
V_47:
F_37 ( V_9 ) ;
V_44:
F_33 ( V_36 ) ;
V_41:
return F_38 ( V_30 ) ;
}
static void F_39 ( struct V_2 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_68 ; V_7 ++ )
if ( V_2 -> V_4 [ V_7 ] )
F_35 ( V_2 -> V_4 [ V_7 ] ) ;
F_37 ( V_2 -> V_9 ) ;
F_36 ( V_2 ) ;
}
static int T_1 F_40 ( void )
{
int V_7 ;
int V_69 = 0 ;
int V_30 = 0 ;
for ( V_7 = 0 ; V_7 < V_70 ; V_7 ++ ) {
if ( V_71 [ V_7 ] . V_72 == 0 || V_71 [ V_7 ] . args [ 0 ] < 0 )
continue;
if ( V_71 [ V_7 ] . V_72 < 2 ) {
F_21 ( V_39 L_10 ) ;
V_30 = - V_40 ;
break;
}
V_73 [ V_7 ] = F_19 ( V_71 [ V_7 ] . args [ 0 ] ,
V_71 [ V_7 ] . args + 1 ,
V_71 [ V_7 ] . V_72 - 1 ) ;
if ( F_41 ( V_73 [ V_7 ] ) ) {
V_30 = F_42 ( V_73 [ V_7 ] ) ;
break;
}
V_69 = 1 ;
}
if ( V_30 ) {
while ( -- V_7 >= 0 )
if ( V_73 [ V_7 ] )
F_39 ( V_73 [ V_7 ] ) ;
return V_30 ;
}
return V_69 ? 0 : - V_74 ;
}
static void T_2 F_43 ( void )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_70 ; V_7 ++ )
if ( V_73 [ V_7 ] )
F_39 ( V_73 [ V_7 ] ) ;
}
