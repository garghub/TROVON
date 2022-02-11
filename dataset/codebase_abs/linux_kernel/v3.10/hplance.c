static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 = - V_8 ;
V_6 = F_2 ( sizeof( struct V_9 ) ) ;
if ( ! V_6 )
goto V_10;
V_7 = - V_11 ;
if ( ! F_3 ( F_4 ( V_2 ) ,
F_5 ( V_2 ) , V_2 -> V_12 ) )
goto V_13;
F_6 ( V_6 , V_2 ) ;
V_7 = F_7 ( V_6 ) ;
if ( V_7 )
goto V_14;
F_8 ( V_2 , V_6 ) ;
F_9 ( V_15 L_1 ,
V_6 -> V_12 , V_2 -> V_12 , V_2 -> V_16 , V_6 -> V_17 , V_2 -> V_18 ) ;
return 0 ;
V_14:
F_10 ( F_4 ( V_2 ) , F_5 ( V_2 ) ) ;
V_13:
F_11 ( V_6 ) ;
V_10:
return V_7 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_13 ( V_2 ) ;
F_14 ( V_6 ) ;
F_10 ( F_4 ( V_2 ) , F_5 ( V_2 ) ) ;
F_11 ( V_6 ) ;
}
static void F_6 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
unsigned long V_19 = ( V_2 -> V_20 . V_21 + V_22 ) ;
struct V_9 * V_23 ;
int V_24 ;
F_15 ( V_19 + V_25 , 0xff ) ;
F_16 ( 100 ) ;
V_6 -> V_26 = V_19 ;
V_6 -> V_27 = & V_28 ;
V_6 -> V_29 = 0 ;
for ( V_24 = 0 ; V_24 < 6 ; V_24 ++ ) {
V_6 -> V_17 [ V_24 ] = ( ( F_17 ( V_19 + V_30 + V_24 * 4 + 1 ) & 0xF ) << 4 )
| ( F_17 ( V_19 + V_30 + V_24 * 4 + 3 ) & 0xF ) ;
}
V_23 = F_18 ( V_6 ) ;
V_23 -> V_31 . V_12 = ( char * ) V_2 -> V_12 ;
V_23 -> V_31 . V_32 = V_19 ;
V_23 -> V_31 . V_33 = (struct V_34 * ) ( V_19 + V_35 ) ;
V_23 -> V_31 . V_34 = NULL ;
V_23 -> V_31 . V_36 = V_37 ;
V_23 -> V_31 . V_38 = V_2 -> V_18 ;
V_23 -> V_31 . V_39 = V_40 ;
V_23 -> V_31 . V_41 = V_42 ;
V_23 -> V_31 . V_43 = V_44 ;
V_23 -> V_31 . V_45 = V_46 ;
V_23 -> V_31 . V_47 = V_48 ;
V_23 -> V_31 . V_49 = V_50 ;
V_23 -> V_31 . V_51 = V_52 ;
}
static void V_40 ( void * V_53 , unsigned short V_54 )
{
struct V_55 * V_23 = (struct V_55 * ) V_53 ;
do {
F_19 ( V_23 -> V_32 + V_56 + V_57 , V_54 ) ;
} while ( ( F_17 ( V_23 -> V_32 + V_58 ) & V_59 ) == 0 );
}
static void V_42 ( void * V_53 , unsigned short V_54 )
{
struct V_55 * V_23 = (struct V_55 * ) V_53 ;
do {
F_19 ( V_23 -> V_32 + V_56 + V_60 , V_54 ) ;
} while ( ( F_17 ( V_23 -> V_32 + V_58 ) & V_59 ) == 0 );
}
static unsigned short V_44 ( void * V_53 )
{
struct V_55 * V_23 = (struct V_55 * ) V_53 ;
T_1 V_54 ;
do {
V_54 = F_20 ( V_23 -> V_32 + V_56 + V_60 ) ;
} while ( ( F_17 ( V_23 -> V_32 + V_58 ) & V_59 ) == 0 );
return V_54 ;
}
static int F_21 ( struct V_5 * V_6 )
{
int V_61 ;
struct V_55 * V_23 = F_18 ( V_6 ) ;
V_61 = F_22 ( V_6 ) ;
if ( V_61 )
return V_61 ;
F_15 ( V_23 -> V_32 + V_58 , V_62 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 )
{
struct V_55 * V_23 = F_18 ( V_6 ) ;
F_15 ( V_23 -> V_32 + V_58 , 0 ) ;
F_24 ( V_6 ) ;
return 0 ;
}
static int T_2 F_25 ( void )
{
return F_26 ( & V_63 ) ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_63 ) ;
}
