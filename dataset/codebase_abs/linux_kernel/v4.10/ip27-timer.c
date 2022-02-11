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
static T_1 F_8 ( int V_13 , void * V_14 )
{
unsigned int V_6 = F_4 () ;
struct V_4 * V_15 = & F_9 ( V_16 , V_6 ) ;
int V_7 = F_5 ( V_6 ) ;
F_7 ( V_17 + V_11 * V_7 , 0 ) ;
V_15 -> V_18 ( V_15 ) ;
return V_19 ;
}
void F_10 ( void )
{
unsigned int V_6 = F_4 () ;
struct V_4 * V_15 = & F_9 ( V_16 , V_6 ) ;
unsigned char * V_20 = F_9 ( V_21 , V_6 ) ;
int V_13 = V_22 ;
sprintf ( V_20 , L_1 , V_6 ) ;
V_15 -> V_20 = V_20 ;
V_15 -> V_23 = V_24 ;
F_11 ( V_15 , V_25 ) ;
V_15 -> V_26 = F_12 ( 0xfffffffffffff , V_15 ) ;
V_15 -> V_27 = F_12 ( 0x300 , V_15 ) ;
V_15 -> V_28 = 200 ;
V_15 -> V_13 = V_13 ;
V_15 -> V_29 = F_13 ( V_6 ) ;
V_15 -> V_30 = F_3 ;
F_14 ( V_15 ) ;
}
static void T_2 F_15 ( void )
{
int V_13 ;
do {
F_16 () ;
V_13 = V_22 ;
if ( V_13 )
break;
V_13 = F_17 () ;
if ( V_13 < 0 )
F_18 ( L_2 ) ;
} while ( F_19 ( & V_22 , V_13 ) );
F_20 ( V_13 , & V_31 , V_32 ) ;
F_21 ( V_13 , & V_33 ) ;
}
static T_3 F_22 ( struct V_34 * V_35 )
{
return F_23 ( F_24 ( 0 ) , V_9 ) ;
}
static T_3 T_4 F_25 ( void )
{
return F_23 ( F_24 ( 0 ) , V_9 ) ;
}
static void T_2 F_26 ( void )
{
struct V_34 * V_35 = & V_36 ;
F_27 ( V_35 , V_25 ) ;
F_28 ( F_25 , 52 , V_25 ) ;
}
void T_2 F_29 ( void )
{
F_26 () ;
F_15 () ;
F_10 () ;
}
void F_30 ( void )
{
T_5 * V_37 ;
T_6 * V_6 ;
int V_38 ;
V_37 = F_31 ( F_32 ( F_33 () ) , V_39 ) ;
if ( ! V_37 )
F_18 ( L_3 ) ;
V_38 = F_6 ( V_40 ) ? V_41 : V_42 ;
V_6 = ( T_6 * ) F_34 ( V_37 , V_38 ) ;
if ( ! V_6 )
F_18 ( L_4 ) ;
F_35 ( L_5 , F_4 () , V_6 -> V_43 ) ;
F_36 ( V_44 ) ;
}
void F_37 ( T_7 V_45 )
{
if ( F_38 () == V_45 ) {
F_7 ( V_46 , 1 ) ;
F_7 ( V_47 , 1 ) ;
F_7 ( V_48 , 0 ) ;
F_7 ( V_49 , 0 ) ;
F_7 ( V_9 , 0 ) ;
F_7 ( V_17 , 0 ) ;
F_7 ( V_50 , 0 ) ;
}
}
static int T_2 F_39 ( void )
{
struct V_51 V_52 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_53 = F_40 ( F_41 ( V_54 ) -> V_55 +
V_56 ) ;
V_52 . V_57 = V_52 . V_53 + 32767 ;
V_52 . V_58 = V_59 ;
return F_42 ( F_43 ( L_6 , - 1 ,
& V_52 , 1 ) ) ;
}
