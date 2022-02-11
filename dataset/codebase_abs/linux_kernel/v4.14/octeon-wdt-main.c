static int F_1 ( int V_1 )
{
#ifdef F_2
return F_3 ( V_1 ) & 0x3f ;
#else
return F_4 () ;
#endif
}
static T_1 F_5 ( int V_2 , void * V_3 )
{
int V_1 = F_6 () ;
unsigned int V_4 = F_1 ( V_1 ) ;
int V_5 = F_7 ( V_1 ) ;
if ( V_6 ) {
if ( V_7 [ V_1 ] > 0 ) {
F_8 ( V_5 , F_9 ( V_4 ) , 1 ) ;
V_7 [ V_1 ] -- ;
} else {
F_10 ( V_2 ) ;
F_11 ( V_1 , & V_8 ) ;
}
} else {
F_8 ( V_5 , F_9 ( V_4 ) , 1 ) ;
}
return V_9 ;
}
static void F_12 ( const char * V_10 )
{
while ( * V_10 )
F_13 ( * V_10 ++ ) ;
}
static void F_14 ( T_2 V_11 , int V_12 )
{
int V_13 ;
int V_14 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_14 = ( V_11 >> ( ( V_12 - V_13 - 1 ) * 4 ) ) & 0xf ;
if ( V_14 >= 10 )
F_13 ( 'a' + V_14 - 10 ) ;
else
F_13 ( '0' + V_14 ) ;
}
}
void F_15 ( T_2 V_15 [ 32 ] )
{
T_2 V_16 ;
unsigned int V_17 = F_4 () ;
T_2 V_18 = F_16 () ;
T_2 V_19 = F_17 () ;
T_2 V_20 = F_18 () ;
T_2 V_21 = F_19 () ;
F_20 ( 85000 * V_17 ) ;
F_12 ( L_1 ) ;
F_14 ( V_17 , 2 ) ;
F_12 ( L_2 ) ;
for ( V_16 = 0 ; V_16 < 32 ; V_16 ++ ) {
F_12 ( L_3 ) ;
F_12 ( V_22 [ V_16 ] ) ;
F_12 ( L_4 ) ;
F_14 ( V_15 [ V_16 ] , 16 ) ;
if ( V_16 & 1 )
F_12 ( L_5 ) ;
}
F_12 ( L_6 ) ;
F_14 ( V_20 , 16 ) ;
F_12 ( L_7 ) ;
F_14 ( V_21 , 16 ) ;
F_12 ( L_5 ) ;
F_12 ( L_8 ) ;
F_14 ( V_19 , 16 ) ;
F_12 ( L_9 ) ;
F_14 ( V_18 , 16 ) ;
F_12 ( L_5 ) ;
if ( F_21 ( V_23 ) ) {
F_12 ( L_10 ) ;
F_14 ( F_22 ( F_23 ( V_17 ) ) , 16 ) ;
F_12 ( L_11 ) ;
F_14 ( F_22 ( F_24 ( V_17 ) ) , 16 ) ;
F_12 ( L_5 ) ;
F_12 ( L_12 ) ;
F_14 ( F_22 ( F_25 ( V_17 ) ) , 16 ) ;
F_12 ( L_13 ) ;
F_14 ( F_22 ( F_26 ( V_17 ) ) , 16 ) ;
F_12 ( L_5 ) ;
F_12 ( L_14 ) ;
F_14 ( F_22 ( F_27 ( V_17 ) ) , 16 ) ;
F_12 ( L_5 ) ;
} else if ( ! F_28 ( V_24 ) ) {
F_12 ( L_15 ) ;
F_14 ( F_22 ( F_29 ( V_17 * 2 ) ) , 16 ) ;
F_12 ( L_16 ) ;
F_14 ( F_22 ( F_30 ( V_17 * 2 ) ) , 16 ) ;
F_12 ( L_5 ) ;
}
F_12 ( L_17 ) ;
if ( F_31 () && ! F_21 ( V_25 ) ) {
T_2 V_26 ;
unsigned int V_5 = F_32 () ;
unsigned int V_27 = F_33 () ;
union V_28 V_29 ;
do {
V_29 . T_2 = F_34 ( V_5 , F_35 ( V_27 ) ) ;
} while ( V_29 . V_30 . V_31 > 0x10000 );
V_26 = F_34 ( 0 , F_36 ( 0 ) ) ;
V_26 |= 1 << 11 ;
F_8 ( 0 , F_36 ( 0 ) , V_26 ) ;
F_8 ( 0 , V_32 , 1 ) ;
}
}
static int F_37 ( int V_1 )
{
unsigned int V_17 ;
int V_5 ;
int V_33 ;
V_17 = F_1 ( V_1 ) ;
V_5 = F_7 ( V_1 ) ;
if ( F_28 ( V_24 ) ) {
struct V_34 * V_35 ;
int V_36 ;
V_35 = F_38 ( V_5 ,
V_37 ) ;
V_36 = V_37 << 12 | 0x200 | V_17 ;
V_33 = F_39 ( V_35 , V_36 ) ;
} else {
V_33 = V_38 + V_17 ;
}
return V_33 ;
}
static int F_40 ( unsigned int V_1 )
{
unsigned int V_4 ;
int V_5 ;
union V_28 V_29 ;
V_4 = F_1 ( V_1 ) ;
V_5 = F_7 ( V_1 ) ;
F_8 ( V_5 , F_9 ( V_4 ) , 1 ) ;
V_29 . T_2 = 0 ;
F_8 ( V_5 , F_35 ( V_4 ) , V_29 . T_2 ) ;
F_41 ( F_37 ( V_1 ) , F_5 ) ;
return 0 ;
}
static int F_42 ( unsigned int V_1 )
{
unsigned int V_4 ;
unsigned int V_33 ;
union V_28 V_29 ;
int V_5 ;
struct V_34 * V_35 ;
int V_36 ;
V_4 = F_1 ( V_1 ) ;
V_5 = F_7 ( V_1 ) ;
V_39 [ V_4 ] . V_40 = ( T_2 ) V_41 ;
V_29 . T_2 = 0 ;
F_8 ( V_5 , F_35 ( V_4 ) , V_29 . T_2 ) ;
V_7 [ V_1 ] = V_42 ;
if ( F_28 ( V_24 ) ) {
V_35 = F_38 ( V_5 , V_37 ) ;
V_36 = V_37 << 12 | 0x200 | V_4 ;
V_33 = F_43 ( V_35 , V_36 ) ;
F_44 ( F_45 ( V_33 ) ,
V_43 ) ;
} else
V_33 = V_38 + V_4 ;
if ( F_46 ( V_33 , F_5 ,
V_44 , L_18 , F_5 ) )
F_47 ( L_19 , V_33 ) ;
if ( F_28 ( V_24 ) ) {
T_3 V_45 ;
F_48 ( & V_45 ) ;
F_49 ( V_1 , & V_45 ) ;
F_50 ( V_33 , & V_45 ) ;
}
F_49 ( V_1 , & V_8 ) ;
F_8 ( V_5 , F_9 ( V_4 ) , 1 ) ;
V_29 . T_2 = 0 ;
V_29 . V_30 . V_46 = V_47 ;
V_29 . V_30 . V_48 = 3 ;
F_8 ( V_5 , F_35 ( V_4 ) , V_29 . T_2 ) ;
return 0 ;
}
static int F_51 ( struct V_49 T_4 * V_50 )
{
int V_1 ;
int V_17 ;
int V_5 ;
if ( V_51 )
return 0 ;
F_52 (cpu) {
V_17 = F_1 ( V_1 ) ;
V_5 = F_7 ( V_1 ) ;
F_8 ( V_5 , F_9 ( V_17 ) , 1 ) ;
V_7 [ V_1 ] = V_42 ;
if ( ( V_42 || ! V_6 ) &&
! F_53 ( V_1 , & V_8 ) ) {
F_54 ( F_37 ( V_1 ) ) ;
F_49 ( V_1 , & V_8 ) ;
}
}
return 0 ;
}
static void F_55 ( int V_52 )
{
unsigned int V_53 ;
V_54 = V_55 ;
while ( ( V_52 % V_54 ) != 0 )
V_54 -- ;
V_53 = V_52 / V_54 ;
V_42 = V_53 > 2 ? V_53 - 2 : 0 ;
V_56 = V_52 ;
V_47 = ( ( F_56 () / V_57 ) * V_54 ) >> 8 ;
}
static int F_57 ( struct V_49 * V_50 ,
unsigned int V_52 )
{
int V_1 ;
int V_17 ;
union V_28 V_29 ;
int V_5 ;
if ( V_52 <= 0 )
return - 1 ;
F_55 ( V_52 ) ;
if ( V_51 )
return 0 ;
F_52 (cpu) {
V_17 = F_1 ( V_1 ) ;
V_5 = F_7 ( V_1 ) ;
F_8 ( V_5 , F_9 ( V_17 ) , 1 ) ;
V_29 . T_2 = 0 ;
V_29 . V_30 . V_46 = V_47 ;
V_29 . V_30 . V_48 = 3 ;
F_8 ( V_5 , F_35 ( V_17 ) , V_29 . T_2 ) ;
F_8 ( V_5 , F_9 ( V_17 ) , 1 ) ;
}
F_51 ( V_50 ) ;
return 0 ;
}
static int F_58 ( struct V_49 * V_50 )
{
F_51 ( V_50 ) ;
V_6 = 1 ;
return 0 ;
}
static int F_59 ( struct V_49 * V_50 )
{
V_6 = 0 ;
F_51 ( V_50 ) ;
return 0 ;
}
static int T_5 F_60 ( void )
{
int V_58 ;
V_39 = F_61 () ;
if ( ! V_39 ) {
F_62 ( L_20 ) ;
return - V_59 ;
}
if ( F_21 ( V_23 ) )
V_57 = 0x200 ;
else if ( F_21 ( V_60 ) )
V_57 = 0x400 ;
else
V_57 = 0x100 ;
V_55 = 6 ;
do {
V_55 -- ;
V_47 = ( ( F_56 () / V_57 ) * V_55 ) >> 8 ;
} while ( V_47 > 65535 );
F_63 ( V_47 == 0 ) ;
F_55 ( V_56 ) ;
F_64 ( L_21 , V_54 ) ;
V_61 . V_62 = V_54 ;
V_61 . V_63 = V_64 ;
F_65 ( & V_61 , V_65 ) ;
V_58 = F_66 ( & V_61 ) ;
if ( V_58 ) {
F_62 ( L_22 , V_58 ) ;
return V_58 ;
}
if ( V_51 ) {
F_67 ( L_23 ) ;
return 0 ;
}
F_48 ( & V_8 ) ;
V_58 = F_68 ( V_66 , L_24 ,
F_42 , F_40 ) ;
if ( V_58 < 0 )
goto V_67;
V_68 = V_58 ;
return 0 ;
V_67:
F_69 ( F_70 ( 0 ) , 0 ) ;
F_71 ( & V_61 ) ;
return V_58 ;
}
static void T_6 F_72 ( void )
{
F_71 ( & V_61 ) ;
if ( V_51 )
return;
F_73 ( V_68 ) ;
F_69 ( F_70 ( 0 ) , 0 ) ;
}
