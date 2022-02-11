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
static void F_19 ( struct V_33 * V_34 )
{
struct V_2 * V_2 ;
struct V_3 * V_3 ;
struct V_35 * V_9 ;
int V_7 , V_36 , V_37 ;
int * V_38 , V_39 ;
struct V_40 V_41 ;
for ( V_37 = 0 ; V_37 < V_42 ; V_37 ++ ) {
if ( V_43 [ V_37 ] . V_44 == 0 ||
V_43 [ V_37 ] . args [ 0 ] < 0 )
continue;
if ( V_43 [ V_37 ] . args [ 0 ] == V_34 -> V_45 )
break;
}
if ( V_37 == V_42 ) {
F_20 ( L_1 , V_34 -> V_45 ) ;
return;
}
V_38 = V_43 [ V_37 ] . args + 1 ;
V_39 = V_43 [ V_37 ] . V_44 - 1 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_46 = V_47 ;
V_9 = F_21 ( V_34 , L_2 , & V_41 ,
V_37 ) ;
if ( ! V_9 ) {
F_22 ( L_3 ) ;
return;
}
V_2 = F_23 ( sizeof( struct V_2 ) , V_48 ) ;
if ( ! V_2 ) {
F_24 ( V_49 L_4 ) ;
goto V_50;
}
F_25 ( & V_2 -> V_31 ) ;
V_2 -> V_9 = V_9 ;
V_2 -> V_51 = V_34 -> V_45 ;
F_26 ( & V_2 -> V_27 , F_1 , ( long ) V_2 ) ;
for ( V_7 = 0 ; V_7 < V_39 ; V_7 ++ ) {
if ( V_38 [ V_7 ] < 1 )
continue;
if ( V_38 [ V_7 ] > F_27 ( V_52 ) ) {
F_24 ( V_49 L_5 , V_38 [ V_7 ] ) ;
goto V_53;
}
V_2 -> V_4 [ V_7 ] = V_3 = F_28 () ;
if ( ! V_3 ) {
F_24 ( V_49 L_6 ) ;
goto V_53;
}
V_2 -> V_8 |= ( 1 << V_7 ) ;
snprintf ( V_2 -> V_54 [ V_7 ] , sizeof( V_2 -> V_54 [ V_7 ] ) ,
L_7 , V_38 [ V_7 ] ) ;
snprintf ( V_2 -> V_55 [ V_7 ] , sizeof( V_2 -> V_55 [ V_7 ] ) ,
L_8 , V_2 -> V_9 -> V_10 -> V_54 , V_7 ) ;
V_3 -> V_54 = V_2 -> V_54 [ V_7 ] ;
V_3 -> V_55 = V_2 -> V_55 [ V_7 ] ;
V_3 -> V_56 . V_57 = V_58 ;
V_3 -> V_56 . V_59 = 0x0003 ;
V_3 -> V_56 . V_60 = V_38 [ V_7 ] ;
V_3 -> V_56 . V_61 = 0x0100 ;
F_29 ( V_3 , V_2 ) ;
V_3 -> V_62 = F_9 ;
V_3 -> V_63 = F_15 ;
V_3 -> V_64 [ 0 ] = F_30 ( V_65 ) | F_30 ( V_66 ) ;
F_31 ( V_3 , V_11 , - 1 , 1 , 0 , 0 ) ;
F_31 ( V_3 , V_14 , - 1 , 1 , 0 , 0 ) ;
for ( V_36 = 0 ; V_36 < V_38 [ V_7 ] ; V_36 ++ )
F_32 ( V_52 [ V_36 ] , V_3 -> V_67 ) ;
if ( F_33 ( V_2 -> V_4 [ V_7 ] ) )
goto V_68;
}
if ( ! V_2 -> V_8 ) {
F_24 ( V_49 L_9 ) ;
goto V_69;
}
V_70 [ V_37 ] = V_2 ;
return;
V_68:
F_34 ( V_2 -> V_4 [ V_7 ] ) ;
V_53:
while ( -- V_7 >= 0 )
if ( V_2 -> V_4 [ V_7 ] )
F_35 ( V_2 -> V_4 [ V_7 ] ) ;
V_69:
F_36 ( V_2 ) ;
V_50:
F_37 ( V_9 ) ;
}
static void F_38 ( struct V_33 * V_10 )
{
int V_7 ;
struct V_2 * V_2 ;
for ( V_7 = 0 ; V_7 < V_42 ; V_7 ++ ) {
if ( V_70 [ V_7 ] && V_70 [ V_7 ] -> V_51 == V_10 -> V_45 )
break;
}
if ( V_7 == V_42 )
return;
V_2 = V_70 [ V_7 ] ;
V_70 [ V_7 ] = NULL ;
for ( V_7 = 0 ; V_7 < V_71 ; V_7 ++ )
if ( V_2 -> V_4 [ V_7 ] )
F_35 ( V_2 -> V_4 [ V_7 ] ) ;
F_37 ( V_2 -> V_9 ) ;
F_36 ( V_2 ) ;
}
static int T_1 F_39 ( void )
{
int V_7 ;
int V_72 = 0 ;
for ( V_7 = 0 ; V_7 < V_42 ; V_7 ++ ) {
if ( V_43 [ V_7 ] . V_44 == 0 || V_43 [ V_7 ] . args [ 0 ] < 0 )
continue;
if ( V_43 [ V_7 ] . V_44 < 2 ) {
F_24 ( V_49 L_10 ) ;
return - V_73 ;
}
V_72 = 1 ;
}
if ( ! V_72 )
return - V_74 ;
return F_40 ( & V_75 ) ;
}
static void T_2 F_41 ( void )
{
F_42 ( & V_75 ) ;
}
