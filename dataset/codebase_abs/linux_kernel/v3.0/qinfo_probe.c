static long F_1 ( struct V_1 * V_2 , char * V_3 )
{
int V_4 = sizeof( V_5 ) / sizeof( struct V_6 ) ;
int V_7 ;
int V_8 = F_2 ( V_2 ) * 8 ;
int V_9 , V_10 ;
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ ) {
if ( strcmp ( V_3 , V_5 [ V_7 ] . V_3 ) == 0 ) {
V_9 = V_5 [ V_7 ] . V_9 & ( ( 1 << V_8 ) - 1 ) ;
V_10 = V_5 [ V_7 ] . V_10 & ( ( 1 << V_8 ) - 1 ) ;
return V_10 | ( V_9 << V_8 ) ;
}
}
F_3 ( V_11 L_1 , V_2 -> V_12 ) ;
F_4 () ;
return - 1 ;
}
static T_1 F_5 ( struct V_1 * V_2 , char * V_3 )
{
unsigned int V_13 , V_14 ;
int V_15 = F_2 ( V_2 ) * 8 ;
unsigned long V_16 = F_1 ( V_2 , V_3 ) ;
int V_17 = 20 ;
F_6 ( V_2 , F_7 ( V_18 ) ,
V_2 -> V_19 + V_20 ) ;
F_6 ( V_2 , F_7 ( V_16 & ( ( 1 << V_15 ) - 1 ) ) ,
V_2 -> V_19 + V_21 ) ;
F_6 ( V_2 , F_7 ( V_16 >> V_15 ) ,
V_2 -> V_19 + V_22 ) ;
F_6 ( V_2 , F_7 ( V_23 ) ,
V_2 -> V_19 + V_24 ) ;
while ( ( V_17 -- ) > 0 ) {
V_13 = F_8 ( F_9 ( V_2 , V_2 -> V_19 + V_25 ) ) ;
if ( V_13 & V_26 )
break;
F_10 ( 10 ) ;
}
V_14 = F_8 ( F_9 ( V_2 , V_2 -> V_19 + V_27 ) ) ;
return V_14 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
T_2 V_30 [ 4 ] ;
V_30 [ 0 ] = F_9 ( V_2 , V_2 -> V_19 + V_31 ) ;
V_30 [ 1 ] = F_9 ( V_2 , V_2 -> V_19 + V_32 ) ;
V_30 [ 2 ] = F_9 ( V_2 , V_2 -> V_19 + V_33 ) ;
V_30 [ 3 ] = F_9 ( V_2 , V_2 -> V_19 + V_34 ) ;
if ( ! F_12 ( V_2 , F_7 ( 'P' ) , V_30 [ 0 ] ) )
goto V_35;
if ( ! F_12 ( V_2 , F_7 ( 'F' ) , V_30 [ 1 ] ) )
goto V_35;
if ( ! F_12 ( V_2 , F_7 ( 'O' ) , V_30 [ 2 ] ) )
goto V_35;
if ( ! F_12 ( V_2 , F_7 ( 'W' ) , V_30 [ 3 ] ) )
goto V_35;
return 1 ;
V_35:
F_3 ( V_36 L_2 ,
V_2 -> V_12 , V_2 -> V_19 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
V_29 -> V_37 = F_14 ( sizeof( struct V_38 ) , V_39 ) ;
if ( ! V_29 -> V_37 ) {
F_3 ( V_36 L_3 ,
V_2 -> V_12 ) ;
return 0 ;
}
V_29 -> V_40 = F_8 ( F_9 ( V_2 , V_2 -> V_19 + V_41 ) ) ;
V_29 -> V_42 = F_8 ( F_9 ( V_2 , V_2 -> V_19 + V_43 ) ) ;
V_29 -> V_37 -> V_44 = F_5 ( V_2 , L_4 ) ;
V_29 -> V_37 -> V_45 = F_5 ( V_2 , L_5 ) ;
V_29 -> V_37 -> V_46 = F_5 ( V_2 , L_6 ) ;
V_29 -> V_37 -> V_47 = F_5 ( V_2 , L_7 ) ;
V_29 -> V_37 -> V_48 =
F_5 ( V_2 , L_8 ) ;
V_29 -> V_37 -> V_49 = F_5 ( V_2 , L_9 ) ;
V_29 -> V_37 -> V_50 =
F_5 ( V_2 , L_10 ) ;
V_29 -> V_37 -> V_51 = F_5 ( V_2 , L_11 ) ;
V_29 -> V_37 -> V_52 = F_5 ( V_2 , L_12 ) ;
return 1 ;
}
static struct V_28 * F_15 ( struct V_1 * V_2 )
{
struct V_28 V_29 ;
struct V_28 * V_53 ;
int V_54 ;
if ( ( V_2 -> V_19 + 0x1000 ) >= V_2 -> V_55 ) {
F_3 ( V_56 L_13
L_14 , V_2 -> V_12 ,
( unsigned long ) V_2 -> V_19 , V_2 -> V_55 - 1 ) ;
return NULL ;
}
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
if ( ! F_11 ( V_2 , & V_29 ) )
return NULL ;
if ( ! F_13 ( V_2 , & V_29 ) )
return NULL ;
V_29 . V_57 = V_29 . V_37 -> V_44 ;
V_29 . V_58 = 1 ;
V_54 = V_29 . V_58 * V_29 . V_37 -> V_47 ;
V_53 = F_14 ( sizeof( struct V_28 ) +
V_54 * sizeof( struct V_59 ) , V_39 ) ;
if ( ! V_53 )
return NULL ;
memcpy ( V_53 , & V_29 , sizeof( struct V_28 ) ) ;
V_53 -> V_58 = V_54 ;
V_53 -> V_57 = V_53 -> V_37 -> V_44 -
F_16 ( V_53 -> V_37 -> V_47 ) ;
return V_53 ;
}
struct V_60 * F_17 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = NULL ;
struct V_28 * V_29 ;
V_29 = F_15 ( V_2 ) ;
if ( ! V_29 )
return NULL ;
V_2 -> V_62 = V_29 ;
V_61 = F_18 ( V_2 ) ;
if ( V_61 ) {
if ( V_61 -> V_55 > V_2 -> V_55 ) {
F_3 ( V_36 L_15
L_16 , ( unsigned long ) V_61 -> V_55 >> 10 ,
( unsigned long ) V_2 -> V_55 >> 10 ) ;
V_61 -> V_55 = V_2 -> V_55 ;
}
return V_61 ;
}
F_19 ( V_29 -> V_37 ) ;
F_19 ( V_29 ) ;
V_2 -> V_62 = NULL ;
return NULL ;
}
static int T_3 F_20 ( void )
{
F_21 ( & V_63 ) ;
return 0 ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_63 ) ;
}
