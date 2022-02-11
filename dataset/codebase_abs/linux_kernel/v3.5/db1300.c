static void T_1 F_1 ( void )
{
int * V_1 ;
V_1 = & V_2 [ 0 ] ;
while ( * V_1 != - 1 )
F_2 ( * V_1 ++ ) ;
V_1 = & V_3 [ 0 ] ;
while ( * V_1 != - 1 )
F_3 ( * V_1 ++ ) ;
F_4 ( 1 , V_4 ) ;
}
char * F_5 ( void )
{
return L_1 ;
}
static void F_6 ( struct V_5 * V_6 , int V_7 ,
unsigned int V_8 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
unsigned long V_12 = ( unsigned long ) V_10 -> V_13 ;
V_12 &= 0xffffff00 ;
if ( V_8 & V_14 ) {
V_12 += V_15 ;
} else if ( V_8 & V_16 ) {
V_12 += V_17 ;
} else {
V_12 += V_18 ;
}
V_10 -> V_19 = V_10 -> V_13 = ( void V_20 * ) V_12 ;
if ( V_7 != V_21 ) {
F_7 ( V_7 , V_10 -> V_13 ) ;
F_8 () ;
}
}
static int F_9 ( struct V_5 * V_6 )
{
return F_10 ( ( void V_20 * ) V_22 ) & 1 ;
}
static T_2 F_11 ( int V_23 , void * V_24 )
{
void (* F_12)( struct V_25 * , unsigned long );
if ( V_23 == V_26 ) {
F_13 ( V_26 ) ;
F_14 ( V_27 ) ;
} else {
F_13 ( V_27 ) ;
F_14 ( V_26 ) ;
}
F_12 = F_15 ( V_28 ) ;
F_12 ( V_24 , F_16 ( 500 ) ) ;
F_17 ( V_28 ) ;
return V_29 ;
}
static int F_18 ( void * V_25 )
{
return F_19 ( V_30 ) & V_31 ;
}
static int F_20 ( void * V_25 )
{
return F_19 ( V_32 ) & ( 1 << 12 ) ;
}
static int F_21 ( void * V_25 , int V_33 )
{
int V_34 ;
if ( V_33 ) {
V_34 = F_22 ( V_26 , F_11 , 0 ,
L_2 , V_25 ) ;
if ( V_34 )
goto V_35;
V_34 = F_22 ( V_27 , F_11 , 0 ,
L_3 , V_25 ) ;
if ( V_34 ) {
F_23 ( V_26 , V_25 ) ;
goto V_35;
}
if ( F_20 ( V_25 ) )
F_14 ( V_27 ) ;
else
F_14 ( V_26 ) ;
} else {
F_23 ( V_26 , V_25 ) ;
F_23 ( V_27 , V_25 ) ;
}
V_34 = 0 ;
V_35:
return V_34 ;
}
static void F_24 ( struct V_36 * V_37 ,
enum V_38 V_39 )
{
if ( V_39 != V_40 )
F_25 ( V_41 , V_42 , 0 ) ;
else
F_25 ( V_41 , 0 , V_42 ) ;
}
static int F_26 ( void * V_25 )
{
return 0 ;
}
static int F_27 ( void * V_25 )
{
return 0 ;
}
static void F_28 ( struct V_36 * V_37 ,
enum V_38 V_39 )
{
if ( V_39 != V_40 )
F_25 ( V_41 , V_43 , 0 ) ;
else
F_25 ( V_41 , 0 , V_43 ) ;
}
static int F_29 ( void )
{
return 9 ;
}
static int F_30 ( void )
{
F_25 ( V_44 , V_45 | V_46 ,
V_47 ) ;
return 0 ;
}
static int F_31 ( void )
{
F_25 ( V_44 , V_47 ,
V_45 | V_46 ) ;
return 0 ;
}
static int T_1 F_32 ( void )
{
int V_48 , V_49 ;
V_49 = F_33 ( V_50 ) ;
F_34 ( V_49 , V_51 ) ;
F_35 ( V_52 , V_53 , V_49 ) ;
F_36 ( V_26 , V_54 ) ;
F_36 ( V_27 , V_54 ) ;
F_36 ( V_55 , V_54 ) ;
F_36 ( V_56 , V_54 ) ;
F_37 ( & V_57 . V_58 [ 0 ] ) ;
F_38 ( 0 , V_59 ,
F_39 ( V_59 ) ) ;
F_40 ( V_60 ,
( void V_20 * ) F_41 ( V_61 ) + V_62 ) ;
F_8 () ;
F_40 ( V_60 ,
( void V_20 * ) F_41 ( V_63 ) + V_62 ) ;
F_8 () ;
F_40 ( V_64 ,
( void V_20 * ) F_41 ( V_65 ) + V_62 ) ;
F_8 () ;
F_25 ( V_66 , 0 , V_67 | V_68 ) ;
F_42 (
V_69 ,
V_69 + 0x00400000 - 1 ,
V_70 ,
V_70 + 0x00400000 - 1 ,
V_71 ,
V_71 + 0x00010000 - 1 ,
V_72 , V_55 , 0 , V_56 , 1 ) ;
V_48 = F_19 ( V_30 ) & V_73 ;
F_43 ( 64 << 20 , 2 , V_48 ) ;
return F_44 ( V_74 , F_39 ( V_74 ) ) ;
}
void T_1 F_45 ( void )
{
unsigned short V_75 ;
F_1 () ;
F_46 ( V_76 ,
V_76 + V_77 ) ;
V_75 = F_19 ( V_78 ) ;
F_47 ( V_79 L_4
L_5 ,
F_48 ( V_75 ) , F_49 ( V_75 ) ,
F_50 ( V_75 ) ) ;
F_51 ( V_80 ) ;
F_51 ( V_81 ) ;
F_51 ( V_82 ) ;
}
