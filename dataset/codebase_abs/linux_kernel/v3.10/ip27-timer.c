static void F_1 ( struct V_1 * V_2 )
{
}
static void F_2 ( struct V_1 * V_2 )
{
}
static int F_3 ( unsigned long V_3 , struct V_4 * V_5 )
{
unsigned int V_6 = F_4 () ;
int V_7 = F_5 ( V_6 ) ;
unsigned long V_8 ;
V_8 = F_6 ( V_9 ) ;
V_8 += V_3 ;
F_7 ( V_10 + V_11 * V_7 , V_8 ) ;
return F_6 ( V_9 ) >= V_8 ? - V_12 : 0 ;
}
static void F_8 ( enum V_13 V_14 ,
struct V_4 * V_5 )
{
}
static T_1 F_9 ( int V_15 , void * V_16 )
{
unsigned int V_6 = F_4 () ;
struct V_4 * V_17 = & F_10 ( V_18 , V_6 ) ;
int V_7 = F_5 ( V_6 ) ;
F_7 ( V_19 + V_11 * V_7 , 0 ) ;
V_17 -> V_20 ( V_17 ) ;
return V_21 ;
}
void T_2 F_11 ( void )
{
unsigned int V_6 = F_4 () ;
struct V_4 * V_17 = & F_10 ( V_18 , V_6 ) ;
unsigned char * V_22 = F_10 ( V_23 , V_6 ) ;
int V_15 = V_24 ;
sprintf ( V_22 , L_1 , V_6 ) ;
V_17 -> V_22 = V_22 ;
V_17 -> V_25 = V_26 ;
F_12 ( V_17 , V_27 ) ;
V_17 -> V_28 = F_13 ( 0xfffffffffffff , V_17 ) ;
V_17 -> V_29 = F_13 ( 0x300 , V_17 ) ;
V_17 -> V_30 = 200 ;
V_17 -> V_15 = V_15 ;
V_17 -> V_31 = F_14 ( V_6 ) ;
V_17 -> V_32 = F_3 ;
V_17 -> V_33 = F_8 ;
F_15 ( V_17 ) ;
}
static void T_3 F_16 ( void )
{
int V_15 ;
do {
F_17 () ;
V_15 = V_24 ;
if ( V_15 )
break;
V_15 = F_18 () ;
if ( V_15 < 0 )
F_19 ( L_2 ) ;
} while ( F_20 ( & V_24 , V_15 ) );
F_21 ( V_15 , & V_34 , V_35 ) ;
F_22 ( V_15 , & V_36 ) ;
}
static T_4 F_23 ( struct V_37 * V_38 )
{
return F_24 ( F_25 ( 0 ) , V_9 ) ;
}
static void T_3 F_26 ( void )
{
struct V_37 * V_38 = & V_39 ;
F_27 ( V_38 , V_27 ) ;
}
void T_3 F_28 ( void )
{
F_26 () ;
F_16 () ;
F_11 () ;
}
void T_2 F_29 ( void )
{
T_5 * V_40 ;
T_6 * V_6 ;
int V_41 ;
V_40 = F_30 ( F_31 ( F_32 () ) , V_42 ) ;
if ( ! V_40 )
F_19 ( L_3 ) ;
V_41 = F_6 ( V_43 ) ? V_44 : V_45 ;
V_6 = ( T_6 * ) F_33 ( V_40 , V_41 ) ;
if ( ! V_6 )
F_19 ( L_4 ) ;
F_34 ( L_5 , F_4 () , V_6 -> V_46 ) ;
F_35 ( V_47 ) ;
}
void T_2 F_36 ( T_7 V_48 )
{
if ( F_37 () == V_48 ) {
F_7 ( V_49 , 1 ) ;
F_7 ( V_50 , 1 ) ;
F_7 ( V_51 , 0 ) ;
F_7 ( V_52 , 0 ) ;
F_7 ( V_9 , 0 ) ;
F_7 ( V_19 , 0 ) ;
F_7 ( V_53 , 0 ) ;
}
}
static int T_3 F_38 ( void )
{
struct V_54 V_55 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_56 = F_39 ( F_40 ( V_57 ) -> V_58 +
V_59 ) ;
V_55 . V_60 = V_55 . V_56 + 32767 ;
V_55 . V_61 = V_62 ;
return F_41 ( F_42 ( L_6 , - 1 ,
& V_55 , 1 ) ) ;
}
