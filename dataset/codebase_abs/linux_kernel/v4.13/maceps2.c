static int F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
struct V_4 * V_5 = ( (struct V_6 * ) V_2 -> V_7 ) -> V_5 ;
unsigned int V_8 = V_9 ;
do {
if ( V_5 -> V_10 & V_11 ) {
V_5 -> V_12 = V_3 ;
return 0 ;
}
F_2 ( 50 ) ;
} while ( V_8 -- );
return - 1 ;
}
static T_1 F_3 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
struct V_4 * V_5 = ( (struct V_6 * ) V_2 -> V_7 ) -> V_5 ;
unsigned long V_15 ;
if ( V_5 -> V_10 & V_16 ) {
V_15 = V_5 -> V_17 ;
F_4 ( V_2 , V_15 & 0xff , 0 ) ;
}
return V_18 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_19 = (struct V_6 * ) V_2 -> V_7 ;
if ( F_6 ( V_19 -> V_13 , F_3 , 0 , L_1 , V_2 ) ) {
F_7 ( V_20 L_2 ) ;
return - V_21 ;
}
V_19 -> V_5 -> V_22 = V_23 | V_24 ;
F_2 ( 100 ) ;
V_19 -> V_5 -> V_22 = V_25 |
V_26 |
V_27 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_19 = (struct V_6 * ) V_2 -> V_7 ;
V_19 -> V_5 -> V_22 = V_23 | V_24 ;
F_2 ( 100 ) ;
F_9 ( V_19 -> V_13 , V_2 ) ;
}
static struct V_1 * F_10 ( int V_28 )
{
struct V_1 * V_1 ;
V_1 = F_11 ( sizeof( struct V_1 ) , V_29 ) ;
if ( V_1 ) {
V_1 -> V_30 . type = V_31 ;
V_1 -> V_32 = F_1 ;
V_1 -> V_33 = F_5 ;
V_1 -> V_34 = F_8 ;
snprintf ( V_1 -> V_35 , sizeof( V_1 -> V_35 ) , L_3 , V_28 ) ;
snprintf ( V_1 -> V_36 , sizeof( V_1 -> V_36 ) , L_4 , V_28 ) ;
V_1 -> V_7 = & V_7 [ V_28 ] ;
V_1 -> V_2 . V_37 = & V_38 -> V_2 ;
}
return V_1 ;
}
static int F_12 ( struct V_39 * V_2 )
{
V_40 [ 0 ] = F_10 ( 0 ) ;
V_40 [ 1 ] = F_10 ( 1 ) ;
if ( ! V_40 [ 0 ] || ! V_40 [ 1 ] ) {
F_13 ( V_40 [ 0 ] ) ;
F_13 ( V_40 [ 1 ] ) ;
return - V_41 ;
}
F_14 ( V_40 [ 0 ] ) ;
F_14 ( V_40 [ 1 ] ) ;
return 0 ;
}
static int F_15 ( struct V_39 * V_2 )
{
F_16 ( V_40 [ 0 ] ) ;
F_16 ( V_40 [ 1 ] ) ;
return 0 ;
}
static int T_2 F_17 ( void )
{
int error ;
error = F_18 ( & V_42 ) ;
if ( error )
return error ;
V_38 = F_19 ( L_5 , - 1 ) ;
if ( ! V_38 ) {
error = - V_41 ;
goto V_43;
}
V_7 [ 0 ] . V_5 = & V_44 -> V_45 . V_46 . V_47 ;
V_7 [ 0 ] . V_13 = V_48 ;
V_7 [ 1 ] . V_5 = & V_44 -> V_45 . V_46 . V_49 ;
V_7 [ 1 ] . V_13 = V_50 ;
error = F_20 ( V_38 ) ;
if ( error )
goto V_51;
return 0 ;
V_51:
F_21 ( V_38 ) ;
V_43:
F_22 ( & V_42 ) ;
return error ;
}
static void T_3 F_23 ( void )
{
F_24 ( V_38 ) ;
F_22 ( & V_42 ) ;
}
