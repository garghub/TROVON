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
void (* F_12)( struct V_24 * , unsigned long );
if ( V_22 == V_25 ) {
F_13 ( V_25 ) ;
F_14 ( V_26 ) ;
} else {
F_13 ( V_26 ) ;
F_14 ( V_25 ) ;
}
F_12 = F_15 ( V_27 ) ;
F_12 ( V_23 , F_16 ( 500 ) ) ;
F_17 ( V_27 ) ;
return V_28 ;
}
static int F_18 ( void * V_24 )
{
return F_19 ( V_29 ) & V_30 ;
}
static int F_20 ( void * V_24 )
{
return F_19 ( V_31 ) & ( 1 << 12 ) ;
}
static int F_21 ( void * V_24 , int V_32 )
{
int V_33 ;
if ( V_32 ) {
V_33 = F_22 ( V_25 , F_11 , 0 ,
L_1 , V_24 ) ;
if ( V_33 )
goto V_34;
V_33 = F_22 ( V_26 , F_11 , 0 ,
L_2 , V_24 ) ;
if ( V_33 ) {
F_23 ( V_25 , V_24 ) ;
goto V_34;
}
if ( F_20 ( V_24 ) )
F_14 ( V_26 ) ;
else
F_14 ( V_25 ) ;
} else {
F_23 ( V_25 , V_24 ) ;
F_23 ( V_26 , V_24 ) ;
}
V_33 = 0 ;
V_34:
return V_33 ;
}
static void F_24 ( struct V_35 * V_36 ,
enum V_37 V_38 )
{
if ( V_38 != V_39 )
F_25 ( V_40 , V_41 , 0 ) ;
else
F_25 ( V_40 , 0 , V_41 ) ;
}
static int F_26 ( void * V_24 )
{
return 0 ;
}
static int F_27 ( void * V_24 )
{
return 0 ;
}
static void F_28 ( struct V_35 * V_36 ,
enum V_37 V_38 )
{
if ( V_38 != V_39 )
F_25 ( V_40 , V_42 , 0 ) ;
else
F_25 ( V_40 , 0 , V_42 ) ;
}
static int F_29 ( void )
{
return 9 ;
}
static int F_30 ( void )
{
F_25 ( V_43 , V_44 | V_45 ,
V_46 ) ;
return 0 ;
}
static int F_31 ( void )
{
F_25 ( V_43 , V_46 ,
V_44 | V_45 ) ;
return 0 ;
}
static void F_32 ( struct V_47 * V_48 , int V_49 )
{
if ( V_49 )
F_14 ( V_50 ) ;
else
F_13 ( V_50 ) ;
}
static int F_33 ( struct V_51 * V_52 )
{
struct V_47 * V_48 = F_34 ( V_52 ) ;
F_35 ( V_48 , V_53 , V_54 ,
V_55 , V_56 ,
V_57 ) ;
F_35 ( V_48 , V_58 , V_59 ,
V_55 , V_60 ,
V_61 ) ;
V_48 -> V_62 = V_50 ;
return F_36 ( V_48 , & V_63 ) ;
}
int T_1 F_37 ( void )
{
int V_64 , V_65 ;
struct V_66 * V_67 ;
V_65 = F_38 ( V_68 ) ;
F_39 ( V_65 , V_69 ) ;
F_40 ( V_70 , V_71 , V_65 ) ;
F_41 ( V_25 , V_72 ) ;
F_41 ( V_26 , V_72 ) ;
F_41 ( V_73 , V_72 ) ;
F_41 ( V_74 , V_72 ) ;
F_42 ( & V_75 . V_76 [ 0 ] ) ;
F_43 ( 0 , V_77 ,
F_44 ( V_77 ) ) ;
if ( F_45 ( & V_78 ) )
F_46 ( L_3 ) ;
F_47 ( V_79 ,
( void V_19 * ) F_48 ( V_80 ) + V_81 ) ;
F_8 () ;
F_47 ( V_79 ,
( void V_19 * ) F_48 ( V_82 ) + V_81 ) ;
F_8 () ;
V_67 = F_49 ( NULL , L_4 ) ;
if ( ! F_50 ( V_67 ) ) {
F_51 ( V_67 , 50000000 ) ;
F_52 ( V_67 ) ;
F_53 ( V_67 ) ;
}
F_47 ( V_83 ,
( void V_19 * ) F_48 ( V_84 ) + V_81 ) ;
F_8 () ;
F_25 ( V_85 , 0 , V_86 | V_87 ) ;
F_54 (
V_88 ,
V_88 + 0x00400000 - 1 ,
V_89 ,
V_89 + 0x00400000 - 1 ,
V_90 ,
V_90 + 0x00010000 - 1 ,
V_91 , V_73 , 0 , V_74 , 1 ) ;
V_64 = F_19 ( V_29 ) & V_92 ;
F_55 ( 64 << 20 , 2 , V_64 ) ;
return F_56 ( V_93 , F_44 ( V_93 ) ) ;
}
int T_1 F_57 ( void )
{
unsigned short V_94 ;
F_58 ( V_95 ,
V_95 + V_96 ) ;
V_94 = F_19 ( V_97 ) ;
if ( F_59 ( V_94 ) != V_98 )
return - V_99 ;
F_1 () ;
F_60 ( V_100 L_5
L_6 ,
F_59 ( V_94 ) , F_61 ( V_94 ) ,
F_62 ( V_94 ) ) ;
F_63 ( V_101 ) ;
F_63 ( V_102 ) ;
F_63 ( V_103 ) ;
return 0 ;
}
