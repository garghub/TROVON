static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , V_3 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
}
int F_7 ( void )
{
int V_4 ;
if ( strncmp ( V_5 -> V_6 , L_1 , 6 ) == 0 )
V_4 = 0 ;
else
V_4 = - V_7 ;
return V_4 ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_9 ( V_2 ) ;
struct V_10 * V_11 = & V_9 -> V_12 [ 0 ] ;
int V_13 ;
V_11 -> V_14 = 0 ;
V_11 -> V_15 = V_16 | V_17 ;
V_11 -> V_18 = 0 ;
V_11 -> V_19 = V_20 | V_21 | V_22 ;
V_11 ++ ;
V_11 -> V_14 = 0 ;
V_11 -> V_15 = 0xef600000 | V_23 | V_17 ;
V_11 -> V_18 = 0xef600000 ;
V_11 -> V_19 = V_20 | V_21 | V_22
| V_24 | V_25 ;
V_2 -> V_26 . V_27 = F_10 ( V_28 ) ;
for ( V_13 = 0 ; V_13 < F_11 ( V_9 -> V_29 ) ; V_13 ++ )
V_9 -> V_29 [ V_13 ] . V_30 = - 1 ;
V_2 -> V_26 . V_31 = V_32 ;
V_2 -> V_26 . V_33 = F_10 ( V_34 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
int V_37 ;
T_1 V_38 ;
T_2 V_39 ;
T_2 V_40 ;
V_38 = V_36 -> V_41 ;
V_39 = ( V_36 -> V_41 >> 32 ) & 0xff ;
V_40 = ( V_36 -> V_41 >> 40 ) & 0x1 ;
V_37 = F_13 ( V_2 , V_38 , V_39 , V_40 ) ;
if ( V_37 == - 1 ) {
V_36 -> V_42 = 0 ;
return 0 ;
}
V_36 -> V_43 = F_14 ( V_2 , V_37 , V_38 ) ;
V_36 -> V_42 = 1 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
return F_16 ( V_2 , V_45 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
return F_18 ( V_2 , V_45 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_3 V_46 ,
union V_47 * V_48 )
{
return - V_49 ;
}
static int F_20 ( struct V_1 * V_2 , T_3 V_46 ,
union V_47 * V_48 )
{
return - V_49 ;
}
static struct V_1 * F_21 ( struct V_50 * V_50 ,
unsigned int V_46 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
int V_51 ;
V_9 = F_22 ( V_52 , V_53 ) ;
if ( ! V_9 ) {
V_51 = - V_54 ;
goto V_55;
}
V_2 = & V_9 -> V_2 ;
V_51 = F_23 ( V_2 , V_50 , V_46 ) ;
if ( V_51 )
goto V_56;
V_2 -> V_26 . V_57 = ( void * ) F_24 ( V_53 | V_58 ) ;
if ( ! V_2 -> V_26 . V_57 )
goto V_59;
return V_2 ;
V_59:
F_25 ( V_2 ) ;
V_56:
F_26 ( V_52 , V_9 ) ;
V_55:
return F_27 ( V_51 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_9 ( V_2 ) ;
F_29 ( ( unsigned long ) V_2 -> V_26 . V_57 ) ;
F_25 ( V_2 ) ;
F_26 ( V_52 , V_9 ) ;
}
static int F_30 ( struct V_50 * V_50 )
{
return 0 ;
}
static void F_31 ( struct V_50 * V_50 )
{
}
static int T_4 F_32 ( void )
{
int V_4 ;
V_4 = F_33 () ;
if ( V_4 )
goto V_60;
V_4 = F_34 ( NULL , sizeof( struct V_8 ) , 0 , V_61 ) ;
if ( V_4 )
goto V_60;
V_62 . V_63 = V_61 ;
V_64 = & V_62 ;
V_60:
return V_4 ;
}
static void T_5 F_35 ( void )
{
V_64 = NULL ;
F_36 () ;
}
