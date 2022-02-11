static void T_1 F_1 ( void )
{
int V_1 ;
int V_2 ;
T_2 * V_3 = V_4 ;
#ifdef F_2
struct V_5 * V_6 = V_7 ;
struct V_8 * V_9 = V_10 ;
#endif
F_3 ( & V_3 , V_11 , V_12 ) ;
F_4 ( & V_3 , V_11 , V_13 ) ;
#ifdef F_2
if ( V_14 )
F_5 ( & V_3 , & V_9 , V_11 , F_6 ( V_15 ) ,
V_16 ) ;
#endif
F_7 ( & V_3 , V_11 , V_11 , V_17 | V_18 | V_19 ) ;
F_8 ( & V_3 , V_11 , V_13 ) ;
#ifdef F_2
if ( V_14 ) {
F_4 ( & V_3 , V_11 , V_20 ) ;
F_9 ( & V_3 , V_11 , V_11 , 0xf ) ;
F_10 ( & V_3 , V_11 , V_11 , 3 + 16 ) ;
F_7 ( & V_3 , V_11 , V_11 , 0x8001 ) ;
F_10 ( & V_3 , V_11 , V_11 , 16 ) ;
F_7 ( & V_3 , V_11 , V_11 , 0x0700 ) ;
F_11 ( & V_3 , V_11 , V_11 , 32 ) ;
F_12 ( & V_3 , V_11 , 0x500 , V_11 ) ;
F_5 ( & V_3 , & V_9 , V_11 , 1 , V_16 ) ;
F_13 ( & V_3 ) ;
}
#endif
F_14 ( & V_3 , 1 , 0 , 0 ) ;
F_15 ( & V_3 , V_11 , V_21 ) ;
F_16 ( & V_3 , V_11 , 0 , 0 , 6 ) ;
F_7 ( & V_3 , V_11 , V_11 , 0x1c0 | 54 ) ;
F_3 ( & V_3 , V_11 , V_21 ) ;
F_17 ( & V_3 , V_11 , ( long ) V_22 ) ;
F_18 ( & V_3 , V_11 ) ;
F_15 ( & V_3 , V_11 , V_12 ) ;
#ifdef F_2
if ( V_14 ) {
F_19 ( & V_6 , V_3 , V_16 ) ;
F_17 ( & V_3 , V_11 , ( long ) V_14 ) ;
F_18 ( & V_3 , V_11 ) ;
F_15 ( & V_3 , V_11 , V_12 ) ;
}
#endif
F_20 ( V_10 , V_7 ) ;
V_2 = ( int ) ( V_3 - V_4 ) ;
F_21 ( L_1 , V_2 ) ;
F_21 ( L_2 ) ;
F_21 ( L_3 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ )
F_21 ( L_4 , V_4 [ V_1 ] ) ;
F_21 ( L_5 ) ;
if ( V_2 > 32 )
F_22 ( L_6 ,
V_2 ) ;
}
static int F_23 ( int V_23 )
{
#ifdef F_24
return F_25 ( V_23 ) ;
#else
return F_26 () ;
#endif
}
static int F_27 ( int V_24 )
{
#ifdef F_24
return F_28 ( V_24 ) ;
#else
return 0 ;
#endif
}
static T_3 F_29 ( int V_25 , void * V_26 )
{
unsigned int V_27 = F_26 () ;
int V_23 = F_27 ( V_27 ) ;
if ( V_28 ) {
if ( V_29 [ V_23 ] > 0 ) {
F_30 ( F_31 ( V_27 ) , 1 ) ;
V_29 [ V_23 ] -- ;
} else {
F_32 ( V_25 ) ;
F_33 ( V_23 , & V_30 ) ;
}
} else {
F_30 ( F_31 ( V_27 ) , 1 ) ;
}
return V_31 ;
}
static void F_34 ( const char * V_32 )
{
while ( * V_32 )
F_35 ( * V_32 ++ ) ;
}
static void F_36 ( T_4 V_33 , int V_34 )
{
int V_35 ;
int V_36 ;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 ++ ) {
V_36 = ( V_33 >> ( ( V_34 - V_35 - 1 ) * 4 ) ) & 0xf ;
if ( V_36 >= 10 )
F_35 ( 'a' + V_36 - 10 ) ;
else
F_35 ( '0' + V_36 ) ;
}
}
void F_37 ( T_4 V_37 [ 32 ] )
{
T_4 V_1 ;
unsigned int V_24 = F_26 () ;
T_4 V_38 = F_38 () ;
T_4 V_39 = F_39 () ;
T_4 V_40 = F_40 () ;
T_4 V_41 = F_41 () ;
F_42 ( 100000000ull * V_24 ) ;
F_34 ( L_7 ) ;
F_36 ( V_24 , 1 ) ;
F_34 ( L_8 ) ;
for ( V_1 = 0 ; V_1 < 32 ; V_1 ++ ) {
F_34 ( L_9 ) ;
F_34 ( V_42 [ V_1 ] ) ;
F_34 ( L_10 ) ;
F_36 ( V_37 [ V_1 ] , 16 ) ;
if ( V_1 & 1 )
F_34 ( L_11 ) ;
}
F_34 ( L_12 ) ;
F_36 ( V_40 , 16 ) ;
F_34 ( L_13 ) ;
F_36 ( V_41 , 16 ) ;
F_34 ( L_11 ) ;
F_34 ( L_14 ) ;
F_36 ( V_39 , 16 ) ;
F_34 ( L_15 ) ;
F_36 ( V_38 , 16 ) ;
F_34 ( L_11 ) ;
F_34 ( L_16 ) ;
F_36 ( F_43 ( F_44 ( V_24 * 2 ) ) , 16 ) ;
F_34 ( L_17 ) ;
F_36 ( F_43 ( F_45 ( V_24 * 2 ) ) , 16 ) ;
F_34 ( L_11 ) ;
F_34 ( L_18 ) ;
}
static int F_46 ( unsigned int V_23 )
{
unsigned int V_27 ;
unsigned int V_43 ;
union V_44 V_45 ;
V_27 = F_23 ( V_23 ) ;
V_43 = V_46 + V_27 ;
F_30 ( F_31 ( V_27 ) , 1 ) ;
V_45 . T_4 = 0 ;
F_30 ( F_47 ( V_27 ) , V_45 . T_4 ) ;
F_48 ( V_43 , F_29 ) ;
return 0 ;
}
static int F_49 ( unsigned int V_23 )
{
unsigned int V_27 ;
unsigned int V_43 ;
union V_44 V_45 ;
V_27 = F_23 ( V_23 ) ;
V_45 . T_4 = 0 ;
F_30 ( F_47 ( V_27 ) , V_45 . T_4 ) ;
V_29 [ V_23 ] = V_47 ;
V_43 = V_46 + V_27 ;
if ( F_50 ( V_43 , F_29 ,
V_48 , L_19 , F_29 ) )
F_22 ( L_20 , V_43 ) ;
F_51 ( V_23 , & V_30 ) ;
F_30 ( F_31 ( V_27 ) , 1 ) ;
V_45 . T_4 = 0 ;
V_45 . V_49 . V_2 = V_50 ;
V_45 . V_49 . V_51 = 3 ;
F_30 ( F_47 ( V_27 ) , V_45 . T_4 ) ;
return 0 ;
}
static int F_52 ( struct V_52 T_5 * V_53 )
{
int V_23 ;
int V_24 ;
F_53 (cpu) {
V_24 = F_23 ( V_23 ) ;
F_30 ( F_31 ( V_24 ) , 1 ) ;
V_29 [ V_23 ] = V_47 ;
if ( ( V_47 || ! V_28 ) &&
! F_54 ( V_23 , & V_30 ) ) {
int V_43 = V_46 + V_24 ;
F_55 ( V_43 ) ;
F_51 ( V_23 , & V_30 ) ;
}
}
return 0 ;
}
static void F_56 ( int V_54 )
{
unsigned int V_55 ;
V_56 = V_57 ;
while ( ( V_54 % V_56 ) != 0 )
V_56 -- ;
V_55 = V_54 / V_56 ;
V_47 = V_55 > 2 ? V_55 - 2 : 0 ;
V_58 = V_54 ;
V_50 = ( ( F_57 () >> 8 ) * V_56 ) >> 8 ;
}
static int F_58 ( struct V_52 * V_53 ,
unsigned int V_54 )
{
int V_23 ;
int V_24 ;
union V_44 V_45 ;
if ( V_54 <= 0 )
return - 1 ;
F_56 ( V_54 ) ;
F_53 (cpu) {
V_24 = F_23 ( V_23 ) ;
F_30 ( F_31 ( V_24 ) , 1 ) ;
V_45 . T_4 = 0 ;
V_45 . V_49 . V_2 = V_50 ;
V_45 . V_49 . V_51 = 3 ;
F_30 ( F_47 ( V_24 ) , V_45 . T_4 ) ;
F_30 ( F_31 ( V_24 ) , 1 ) ;
}
F_52 ( V_53 ) ;
return 0 ;
}
static int F_59 ( struct V_52 * V_53 )
{
F_52 ( V_53 ) ;
V_28 = 1 ;
return 0 ;
}
static int F_60 ( struct V_52 * V_53 )
{
V_28 = 0 ;
F_52 ( V_53 ) ;
return 0 ;
}
static int T_1 F_61 ( void )
{
int V_1 ;
int V_59 ;
T_4 * V_60 ;
V_57 = 6 ;
do {
V_57 -- ;
V_50 = ( ( F_57 () >> 8 ) *
V_57 ) >> 8 ;
} while ( V_50 > 65535 );
F_62 ( V_50 == 0 ) ;
F_56 ( V_58 ) ;
F_63 ( L_21 , V_56 ) ;
V_61 . V_62 = V_56 ;
V_61 . V_63 = V_64 ;
F_64 ( & V_61 , V_65 ) ;
V_59 = F_65 ( & V_61 ) ;
if ( V_59 ) {
F_66 ( L_22 , V_59 ) ;
return V_59 ;
}
F_1 () ;
V_60 = ( T_4 * ) V_4 ;
for ( V_1 = 0 ; V_1 < 16 ; V_1 ++ ) {
F_30 ( V_66 , V_1 * 8 ) ;
F_30 ( V_67 , V_60 [ V_1 ] ) ;
}
F_30 ( F_67 ( 0 ) , 0x81fc0000 ) ;
F_68 ( & V_30 ) ;
V_59 = F_69 ( V_68 , L_23 ,
F_49 , F_46 ) ;
if ( V_59 < 0 )
goto V_69;
V_70 = V_59 ;
return 0 ;
V_69:
F_30 ( F_67 ( 0 ) , 0 ) ;
F_70 ( & V_61 ) ;
return V_59 ;
}
static void T_6 F_71 ( void )
{
F_70 ( & V_61 ) ;
F_72 ( V_70 ) ;
F_30 ( F_67 ( 0 ) , 0 ) ;
}
