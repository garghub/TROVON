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
static void F_5 ( struct V_5 * V_6 , int V_7 ,
unsigned int V_8 )
{
struct V_9 * V_10 = F_6 ( V_6 ) ;
unsigned long V_11 = ( unsigned long ) V_10 -> V_12 ;
V_11 &= 0xffffff00 ;
if ( V_8 & V_13 ) {
V_11 += V_14 ;
} else if ( V_8 & V_15 ) {
V_11 += V_16 ;
} else {
V_11 += V_17 ;
}
V_10 -> V_18 = V_10 -> V_12 = ( void V_19 * ) V_11 ;
if ( V_7 != V_20 ) {
F_7 ( V_7 , V_10 -> V_12 ) ;
F_8 () ;
}
}
static int F_9 ( struct V_5 * V_6 )
{
return F_10 ( V_21 ) & 1 ;
}
static T_2 F_11 ( int V_22 , void * V_23 )
{
F_12 ( V_22 ) ;
return V_24 ;
}
static T_2 F_13 ( int V_22 , void * V_23 )
{
void (* F_14)( struct V_25 * , unsigned long );
F_14 = F_15 ( V_26 ) ;
F_14 ( V_23 , F_16 ( 200 ) ) ;
F_17 ( V_26 ) ;
F_18 ( 100 ) ;
if ( V_22 == V_27 )
F_19 ( V_28 ) ;
else
F_19 ( V_27 ) ;
return V_29 ;
}
static int F_20 ( void * V_25 )
{
return F_21 ( V_30 ) & V_31 ;
}
static int F_22 ( void * V_25 )
{
return F_21 ( V_32 ) & ( 1 << 12 ) ;
}
static int F_23 ( void * V_25 , int V_33 )
{
int V_34 ;
if ( V_33 ) {
V_34 = F_24 ( V_27 , F_11 ,
F_13 , 0 , L_1 , V_25 ) ;
if ( V_34 )
goto V_35;
V_34 = F_24 ( V_28 , F_11 ,
F_13 , 0 , L_2 , V_25 ) ;
if ( V_34 ) {
F_25 ( V_27 , V_25 ) ;
goto V_35;
}
if ( F_22 ( V_25 ) )
F_19 ( V_28 ) ;
else
F_19 ( V_27 ) ;
} else {
F_25 ( V_27 , V_25 ) ;
F_25 ( V_28 , V_25 ) ;
}
V_34 = 0 ;
V_35:
return V_34 ;
}
static void F_26 ( struct V_36 * V_37 ,
enum V_38 V_39 )
{
if ( V_39 != V_40 )
F_27 ( V_41 , V_42 , 0 ) ;
else
F_27 ( V_41 , 0 , V_42 ) ;
}
static int F_28 ( void * V_25 )
{
return 0 ;
}
static int F_29 ( void * V_25 )
{
return 0 ;
}
static void F_30 ( struct V_36 * V_37 ,
enum V_38 V_39 )
{
if ( V_39 != V_40 )
F_27 ( V_41 , V_43 , 0 ) ;
else
F_27 ( V_41 , 0 , V_43 ) ;
}
static int F_31 ( void )
{
return 9 ;
}
static int F_32 ( void )
{
F_27 ( V_44 , V_45 | V_46 ,
V_47 ) ;
return 0 ;
}
static int F_33 ( void )
{
F_27 ( V_44 , V_47 ,
V_45 | V_46 ) ;
return 0 ;
}
static void F_34 ( struct V_48 * V_49 , int V_50 )
{
if ( V_50 )
F_19 ( V_51 ) ;
else
F_12 ( V_51 ) ;
}
static int F_35 ( struct V_52 * V_53 )
{
struct V_48 * V_49 = F_36 ( V_53 ) ;
F_37 ( V_49 , V_54 , V_55 ,
V_56 , V_57 ,
V_58 ) ;
F_37 ( V_49 , V_59 , V_60 ,
V_56 , V_61 ,
V_62 ) ;
V_49 -> V_63 = V_51 ;
return F_38 ( V_49 , & V_64 ) ;
}
int T_1 F_39 ( void )
{
int V_65 , V_66 ;
struct V_67 * V_68 ;
V_66 = F_40 ( V_69 ) ;
F_41 ( V_66 , V_70 ) ;
F_42 ( V_71 , V_72 , V_66 ) ;
F_43 ( V_27 , V_73 ) ;
F_43 ( V_28 , V_73 ) ;
F_43 ( V_74 , V_73 ) ;
F_43 ( V_75 , V_73 ) ;
F_44 ( & V_76 . V_77 [ 0 ] ) ;
F_45 ( 0 , V_78 ,
F_46 ( V_78 ) ) ;
if ( F_47 ( & V_79 ) )
F_48 ( L_3 ) ;
F_49 ( V_80 ,
( void V_19 * ) F_50 ( V_81 ) + V_82 ) ;
F_8 () ;
F_49 ( V_80 ,
( void V_19 * ) F_50 ( V_83 ) + V_82 ) ;
F_8 () ;
V_68 = F_51 ( NULL , L_4 ) ;
if ( ! F_52 ( V_68 ) ) {
F_53 ( V_68 , 50000000 ) ;
F_54 ( V_68 ) ;
F_55 ( V_68 ) ;
}
F_49 ( V_84 ,
( void V_19 * ) F_50 ( V_85 ) + V_82 ) ;
F_8 () ;
F_27 ( V_86 , 0 , V_87 | V_88 ) ;
F_56 (
V_89 ,
V_89 + 0x00400000 - 1 ,
V_90 ,
V_90 + 0x00400000 - 1 ,
V_91 ,
V_91 + 0x00010000 - 1 ,
V_92 , V_74 , 0 , V_75 , 1 ) ;
V_65 = F_21 ( V_30 ) & V_93 ;
F_57 ( 64 << 20 , 2 , V_65 ) ;
return F_58 ( V_94 , F_46 ( V_94 ) ) ;
}
int T_1 F_59 ( void )
{
unsigned short V_95 ;
F_60 ( V_96 ,
V_96 + V_97 ) ;
V_95 = F_21 ( V_98 ) ;
if ( F_61 ( V_95 ) != V_99 )
return - V_100 ;
F_1 () ;
F_62 ( V_101 L_5
L_6 ,
F_61 ( V_95 ) , F_63 ( V_95 ) ,
F_64 ( V_95 ) ) ;
F_65 ( V_102 ) ;
F_65 ( V_103 ) ;
F_65 ( V_104 ) ;
return 0 ;
}
