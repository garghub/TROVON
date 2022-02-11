static long F_1 ( struct V_1 * V_2 , char * V_3 )
{
int V_4 = F_2 ( V_5 ) ;
int V_6 ;
int V_7 = F_3 ( V_2 ) * 8 ;
int V_8 , V_9 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
if ( strcmp ( V_3 , V_5 [ V_6 ] . V_3 ) == 0 ) {
V_8 = V_5 [ V_6 ] . V_8 & ( ( 1 << V_7 ) - 1 ) ;
V_9 = V_5 [ V_6 ] . V_9 & ( ( 1 << V_7 ) - 1 ) ;
return V_9 | ( V_8 << V_7 ) ;
}
}
F_4 ( V_10 L_1 , V_2 -> V_11 ) ;
F_5 () ;
return - 1 ;
}
static T_1 F_6 ( struct V_1 * V_2 , char * V_3 )
{
unsigned int V_12 , V_13 ;
int V_14 = F_3 ( V_2 ) * 8 ;
unsigned long V_15 = F_1 ( V_2 , V_3 ) ;
int V_16 = 20 ;
F_7 ( V_2 , F_8 ( V_17 ) ,
V_2 -> V_18 + V_19 ) ;
F_7 ( V_2 , F_8 ( V_15 & ( ( 1 << V_14 ) - 1 ) ) ,
V_2 -> V_18 + V_20 ) ;
F_7 ( V_2 , F_8 ( V_15 >> V_14 ) ,
V_2 -> V_18 + V_21 ) ;
F_7 ( V_2 , F_8 ( V_22 ) ,
V_2 -> V_18 + V_23 ) ;
while ( ( V_16 -- ) > 0 ) {
V_12 = F_9 ( F_10 ( V_2 , V_2 -> V_18 + V_24 ) ) ;
if ( V_12 & V_25 )
break;
F_11 ( 10 ) ;
}
V_13 = F_9 ( F_10 ( V_2 , V_2 -> V_18 + V_26 ) ) ;
return V_13 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
T_2 V_29 [ 4 ] ;
V_29 [ 0 ] = F_10 ( V_2 , V_2 -> V_18 + V_30 ) ;
V_29 [ 1 ] = F_10 ( V_2 , V_2 -> V_18 + V_31 ) ;
V_29 [ 2 ] = F_10 ( V_2 , V_2 -> V_18 + V_32 ) ;
V_29 [ 3 ] = F_10 ( V_2 , V_2 -> V_18 + V_33 ) ;
if ( ! F_13 ( V_2 , F_8 ( 'P' ) , V_29 [ 0 ] ) )
goto V_34;
if ( ! F_13 ( V_2 , F_8 ( 'F' ) , V_29 [ 1 ] ) )
goto V_34;
if ( ! F_13 ( V_2 , F_8 ( 'O' ) , V_29 [ 2 ] ) )
goto V_34;
if ( ! F_13 ( V_2 , F_8 ( 'W' ) , V_29 [ 3 ] ) )
goto V_34;
return 1 ;
V_34:
F_4 ( V_35 L_2 ,
V_2 -> V_11 , V_2 -> V_18 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
V_28 -> V_36 = F_15 ( sizeof( struct V_37 ) , V_38 ) ;
if ( ! V_28 -> V_36 ) {
F_4 ( V_35 L_3 ,
V_2 -> V_11 ) ;
return 0 ;
}
V_28 -> V_39 = F_9 ( F_10 ( V_2 , V_2 -> V_18 + V_40 ) ) ;
V_28 -> V_41 = F_9 ( F_10 ( V_2 , V_2 -> V_18 + V_42 ) ) ;
V_28 -> V_36 -> V_43 = F_6 ( V_2 , L_4 ) ;
V_28 -> V_36 -> V_44 = F_6 ( V_2 , L_5 ) ;
V_28 -> V_36 -> V_45 = F_6 ( V_2 , L_6 ) ;
V_28 -> V_36 -> V_46 = F_6 ( V_2 , L_7 ) ;
V_28 -> V_36 -> V_47 =
F_6 ( V_2 , L_8 ) ;
V_28 -> V_36 -> V_48 = F_6 ( V_2 , L_9 ) ;
V_28 -> V_36 -> V_49 =
F_6 ( V_2 , L_10 ) ;
V_28 -> V_36 -> V_50 = F_6 ( V_2 , L_11 ) ;
V_28 -> V_36 -> V_51 = F_6 ( V_2 , L_12 ) ;
return 1 ;
}
static struct V_27 * F_16 ( struct V_1 * V_2 )
{
struct V_27 V_28 ;
struct V_27 * V_52 ;
int V_53 ;
if ( ( V_2 -> V_18 + 0x1000 ) >= V_2 -> V_54 ) {
F_4 ( V_55 L_13
L_14 , V_2 -> V_11 ,
( unsigned long ) V_2 -> V_18 , V_2 -> V_54 - 1 ) ;
return NULL ;
}
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
if ( ! F_12 ( V_2 , & V_28 ) )
return NULL ;
if ( ! F_14 ( V_2 , & V_28 ) )
return NULL ;
V_28 . V_56 = V_28 . V_36 -> V_43 ;
V_28 . V_57 = 1 ;
V_53 = V_28 . V_57 * V_28 . V_36 -> V_46 ;
V_52 = F_15 ( sizeof( struct V_27 ) +
V_53 * sizeof( struct V_58 ) , V_38 ) ;
if ( ! V_52 )
return NULL ;
memcpy ( V_52 , & V_28 , sizeof( struct V_27 ) ) ;
V_52 -> V_57 = V_53 ;
V_52 -> V_56 = V_52 -> V_36 -> V_43 -
F_17 ( V_52 -> V_36 -> V_46 ) ;
return V_52 ;
}
struct V_59 * F_18 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = NULL ;
struct V_27 * V_28 ;
V_28 = F_16 ( V_2 ) ;
if ( ! V_28 )
return NULL ;
V_2 -> V_61 = V_28 ;
V_60 = F_19 ( V_2 ) ;
if ( V_60 ) {
if ( V_60 -> V_54 > V_2 -> V_54 ) {
F_4 ( V_35 L_15
L_16 , ( unsigned long ) V_60 -> V_54 >> 10 ,
( unsigned long ) V_2 -> V_54 >> 10 ) ;
V_60 -> V_54 = V_2 -> V_54 ;
}
return V_60 ;
}
F_20 ( V_28 -> V_36 ) ;
F_20 ( V_28 ) ;
V_2 -> V_61 = NULL ;
return NULL ;
}
static int T_3 F_21 ( void )
{
F_22 ( & V_62 ) ;
return 0 ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_62 ) ;
}
