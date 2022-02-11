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
F_6 ( V_7 , V_10 -> V_13 ) ;
F_7 () ;
}
}
static int F_8 ( struct V_5 * V_6 )
{
return F_9 ( V_22 ) & 1 ;
}
static T_2 F_10 ( int V_23 , void * V_24 )
{
void (* F_11)( struct V_25 * , unsigned long );
if ( V_23 == V_26 ) {
F_12 ( V_26 ) ;
F_13 ( V_27 ) ;
} else {
F_12 ( V_27 ) ;
F_13 ( V_26 ) ;
}
F_11 = F_14 ( V_28 ) ;
F_11 ( V_24 , F_15 ( 500 ) ) ;
F_16 ( V_28 ) ;
return V_29 ;
}
static int F_17 ( void * V_25 )
{
return F_18 ( V_30 ) & V_31 ;
}
static int F_19 ( void * V_25 )
{
return F_18 ( V_32 ) & ( 1 << 12 ) ;
}
static int F_20 ( void * V_25 , int V_33 )
{
int V_34 ;
if ( V_33 ) {
V_34 = F_21 ( V_26 , F_10 , 0 ,
L_1 , V_25 ) ;
if ( V_34 )
goto V_35;
V_34 = F_21 ( V_27 , F_10 , 0 ,
L_2 , V_25 ) ;
if ( V_34 ) {
F_22 ( V_26 , V_25 ) ;
goto V_35;
}
if ( F_19 ( V_25 ) )
F_13 ( V_27 ) ;
else
F_13 ( V_26 ) ;
} else {
F_22 ( V_26 , V_25 ) ;
F_22 ( V_27 , V_25 ) ;
}
V_34 = 0 ;
V_35:
return V_34 ;
}
static void F_23 ( struct V_36 * V_37 ,
enum V_38 V_39 )
{
if ( V_39 != V_40 )
F_24 ( V_41 , V_42 , 0 ) ;
else
F_24 ( V_41 , 0 , V_42 ) ;
}
static int F_25 ( void * V_25 )
{
return 0 ;
}
static int F_26 ( void * V_25 )
{
return 0 ;
}
static void F_27 ( struct V_36 * V_37 ,
enum V_38 V_39 )
{
if ( V_39 != V_40 )
F_24 ( V_41 , V_43 , 0 ) ;
else
F_24 ( V_41 , 0 , V_43 ) ;
}
static int F_28 ( void )
{
return 9 ;
}
static int F_29 ( void )
{
F_24 ( V_44 , V_45 | V_46 ,
V_47 ) ;
return 0 ;
}
static int F_30 ( void )
{
F_24 ( V_44 , V_47 ,
V_45 | V_46 ) ;
return 0 ;
}
static void F_31 ( struct V_48 * V_49 , int V_50 )
{
if ( V_50 )
F_13 ( V_51 ) ;
else
F_12 ( V_51 ) ;
}
static int F_32 ( struct V_52 * V_53 )
{
struct V_48 * V_49 = F_33 ( V_53 ) ;
F_34 ( V_49 , V_54 , V_55 ,
V_56 , V_57 ,
V_58 ) ;
F_34 ( V_49 , V_59 , V_60 ,
V_56 , V_61 ,
V_62 ) ;
V_49 -> V_63 = V_51 ;
return F_35 ( V_49 , & V_64 ) ;
}
int T_1 F_36 ( void )
{
int V_65 , V_66 ;
struct V_67 * V_68 ;
V_66 = F_37 ( V_69 ) ;
F_38 ( V_66 , V_70 ) ;
F_39 ( V_71 , V_72 , V_66 ) ;
F_40 ( V_26 , V_73 ) ;
F_40 ( V_27 , V_73 ) ;
F_40 ( V_74 , V_73 ) ;
F_40 ( V_75 , V_73 ) ;
F_41 ( & V_76 . V_77 [ 0 ] ) ;
F_42 ( 0 , V_78 ,
F_43 ( V_78 ) ) ;
if ( F_44 ( & V_79 ) )
F_45 ( L_3 ) ;
F_46 ( V_80 ,
( void V_20 * ) F_47 ( V_81 ) + V_82 ) ;
F_7 () ;
F_46 ( V_80 ,
( void V_20 * ) F_47 ( V_83 ) + V_82 ) ;
F_7 () ;
V_68 = F_48 ( NULL , L_4 ) ;
if ( ! F_49 ( V_68 ) ) {
F_50 ( V_68 , 50000000 ) ;
F_51 ( V_68 ) ;
F_52 ( V_68 ) ;
}
F_46 ( V_84 ,
( void V_20 * ) F_47 ( V_85 ) + V_82 ) ;
F_7 () ;
F_24 ( V_86 , 0 , V_87 | V_88 ) ;
F_53 (
V_89 ,
V_89 + 0x00400000 - 1 ,
V_90 ,
V_90 + 0x00400000 - 1 ,
V_91 ,
V_91 + 0x00010000 - 1 ,
V_92 , V_74 , 0 , V_75 , 1 ) ;
V_65 = F_18 ( V_30 ) & V_93 ;
F_54 ( 64 << 20 , 2 , V_65 ) ;
return F_55 ( V_94 , F_43 ( V_94 ) ) ;
}
int T_1 F_56 ( void )
{
unsigned short V_95 ;
F_57 ( V_96 ,
V_96 + V_97 ) ;
V_95 = F_18 ( V_98 ) ;
if ( F_58 ( V_95 ) != V_99 )
return - V_100 ;
F_1 () ;
F_59 ( V_101 L_5
L_6 ,
F_58 ( V_95 ) , F_60 ( V_95 ) ,
F_61 ( V_95 ) ) ;
F_62 ( V_102 ) ;
F_62 ( V_103 ) ;
F_62 ( V_104 ) ;
return 0 ;
}
