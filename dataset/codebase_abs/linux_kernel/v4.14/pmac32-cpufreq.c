static inline void F_1 ( unsigned long V_1 )
{
if ( V_2 )
F_2 ( V_1 ) ;
else
F_3 ( V_1 ) ;
}
static inline void F_4 ( void )
{
unsigned long V_3 = V_4 ;
F_5 () ;
V_4 = V_3 ;
}
static int F_6 ( int V_5 )
{
T_1 V_6 ;
if ( V_5 == 0 ) {
F_7 ( V_7 , NULL , V_8 , 0x05 ) ;
F_1 ( 10 ) ;
if ( V_9 ) {
V_6 = F_8 ( V_10 ) ;
V_6 &= ~ 0x2000 ;
F_9 ( V_10 , V_6 ) ;
}
}
#ifdef F_10
F_11 ( V_5 ) ;
#endif
if ( V_5 == 1 ) {
if ( V_9 ) {
V_6 = F_8 ( V_10 ) ;
V_6 |= 0x2000 ;
F_9 ( V_10 , V_6 ) ;
}
F_7 ( V_7 , NULL , V_8 , 0x04 ) ;
F_1 ( 10 ) ;
}
return 0 ;
}
static unsigned int F_12 ( void )
{
if ( F_8 ( V_11 ) & V_12 )
return V_13 ;
else
return V_14 ;
}
static int F_13 ( int V_5 )
{
if ( V_5 == 0 ) {
F_7 ( V_7 , NULL , V_8 , 0x05 ) ;
F_1 ( 1 ) ;
}
#ifdef F_10
F_14 ( V_5 ) ;
#endif
F_15 ( 100 ) ;
if ( V_5 == 1 ) {
F_7 ( V_7 , NULL , V_8 , 0x04 ) ;
F_1 ( 1 ) ;
}
return 0 ;
}
static unsigned int F_16 ( void )
{
if ( F_8 ( V_11 ) & V_15 )
return V_13 ;
else
return V_14 ;
}
static int F_17 ( int V_5 )
{
int V_16 , V_17 = 0 ;
if ( V_5 == 0 ) {
F_7 ( V_7 , NULL , V_8 , 0x05 ) ;
F_1 ( 10 ) ;
}
V_16 = F_7 ( V_18 , NULL , V_19 , 0 ) ;
if ( V_5 == ( ( V_16 & 0x01 ) == 0 ) )
goto V_20;
F_7 ( V_7 , NULL , V_19 ,
V_5 ? 0x04 : 0x05 ) ;
F_15 ( 200 ) ;
do {
if ( ++ V_17 > 100 )
break;
F_1 ( 1 ) ;
V_16 = F_7 ( V_18 , NULL , V_21 , 0 ) ;
} while( ( V_16 & 0x02 ) == 0 );
V_20:
if ( V_5 == 1 ) {
F_7 ( V_7 , NULL , V_8 , 0x04 ) ;
F_1 ( 10 ) ;
}
#ifdef F_18
F_4 () ;
#endif
return 0 ;
}
static int F_19 ( int V_5 )
{
struct V_22 V_23 ;
unsigned long V_24 ;
unsigned long V_25 ;
unsigned int V_26 ;
unsigned long V_27 ;
F_20 () ;
#ifdef F_18
F_21 ( V_28 L_1 , F_8 ( V_11 ) ) ;
#endif
F_22 () ;
V_26 = F_23 () ;
F_24 ( 0xf ) ;
asm volatile("mtdec %0" : : "r" (0x7fffffff));
F_25 () ;
asm volatile("mtdec %0" : : "r" (0x7fffffff));
F_26 ( V_27 ) ;
F_27 () ;
#ifdef F_28
if ( F_29 ( V_29 ) )
F_30 () ;
#endif
V_25 = F_31 () ;
V_24 = F_32 () ;
F_33 ( & V_23 , NULL , 6 , V_30 , 'W' , 'O' , 'O' , 'F' , V_5 ) ;
while ( ! V_23 . V_31 )
F_34 () ;
F_7 ( V_32 , NULL , 1 , 1 ) ;
F_35 () ;
F_7 ( V_32 , NULL , 1 , 0 ) ;
if ( V_24 != 0xffffffff && ( V_24 & V_33 ) != 0 )
F_36 ( V_24 ) ;
if ( V_25 != 0xffffffff && ( V_25 & V_34 ) != 0 )
F_37 ( V_25 ) ;
F_38 ( NULL , V_35 -> V_36 , NULL ) ;
#ifdef F_18
F_21 ( V_28 L_2 , F_8 ( V_11 ) ) ;
#endif
F_39 () ;
F_40 ( 1 ) ;
F_24 ( V_26 ) ;
F_41 ( V_27 ) ;
#ifdef F_18
F_4 () ;
#endif
F_42 () ;
F_43 () ;
return 0 ;
}
static int F_44 ( struct V_37 * V_38 , int V_39 )
{
unsigned long V_40 ;
static unsigned long V_41 ;
if ( V_39 == V_42 &&
F_29 ( V_43 ) ) {
V_40 = F_31 () ;
if ( V_40 & V_34 ) {
V_41 = V_40 ;
F_37 ( 0 ) ;
}
}
F_45 ( V_39 == V_42 ) ;
if ( V_39 == V_44 &&
F_29 ( V_43 ) ) {
V_40 = F_31 () ;
if ( ( V_41 & V_34 ) && V_40 != V_41 )
F_37 ( V_41 ) ;
}
V_45 = ( V_39 == V_44 ) ? V_14 : V_13 ;
return 0 ;
}
static unsigned int F_46 ( unsigned int V_46 )
{
return V_45 ;
}
static int F_47 ( struct V_37 * V_38 ,
unsigned int V_47 )
{
int V_48 ;
V_48 = F_44 ( V_38 , V_47 ) ;
V_49 = V_45 * 1000ul ;
return V_48 ;
}
static int F_48 ( struct V_37 * V_38 )
{
return F_49 ( V_38 , V_50 , V_51 ) ;
}
static T_1 F_50 ( struct V_52 * V_53 )
{
const T_1 * V_54 = F_51 ( V_53 , L_3 , NULL ) ;
T_1 V_55 ;
if ( V_54 == NULL )
return 0 ;
V_55 = * V_54 ;
if ( V_55 < V_56 )
V_55 += V_56 ;
return V_55 ;
}
static int F_52 ( struct V_37 * V_38 )
{
V_2 = 1 ;
V_57 = V_45 ;
if ( V_45 == V_13 && ! V_58 )
F_44 ( V_38 , V_44 ) ;
return 0 ;
}
static int F_53 ( struct V_37 * V_38 )
{
if ( V_59 )
V_45 = V_59 () ;
else
V_45 = 0 ;
F_44 ( V_38 , V_57 == V_13 ?
V_42 : V_44 ) ;
V_49 = V_45 * 1000ul ;
V_2 = 0 ;
return 0 ;
}
static int F_54 ( struct V_52 * V_60 )
{
struct V_52 * V_61 = F_55 ( NULL ,
L_4 ) ;
struct V_52 * V_62 = F_55 ( NULL ,
L_5 ) ;
struct V_52 * V_63 = F_55 ( NULL ,
L_6 ) ;
const T_1 * V_64 ;
if ( V_61 )
V_8 = F_50 ( V_61 ) ;
if ( V_62 )
V_19 = F_50 ( V_62 ) ;
if ( V_63 )
V_21 = F_50 ( V_63 ) ;
if ( V_19 && V_21 ) {
int V_65 , V_48 ;
const T_1 * V_66 , * V_67 ;
V_66 = F_51 ( V_60 , L_7 , & V_65 ) ;
V_65 /= sizeof( T_1 ) ;
if ( V_66 == NULL || V_65 != 2 ) {
F_56 ( L_8 ) ;
return 1 ;
}
V_67 = F_51 ( V_60 , L_9 ,
NULL ) ;
if ( V_67 == NULL ) {
F_56 ( L_10 ) ;
return 1 ;
}
V_13 = F_57 ( V_66 [ 0 ] , V_66 [ 1 ] ) ;
V_14 = F_58 ( V_66 [ 0 ] , V_66 [ 1 ] ) ;
if ( V_13 < 98000000 )
V_13 = 101000000 ;
V_13 = ( V_13 * ( * V_67 ) ) / 2000 ;
V_14 = ( V_14 * ( * V_67 ) ) / 2000 ;
V_48 = F_7 ( V_18 , NULL , V_19 , 0 ) ;
V_45 = ( V_48 & 0x01 ) ? V_14 : V_13 ;
F_45 = F_17 ;
return 1 ;
}
V_64 = F_51 ( V_60 , L_11 , NULL ) ;
if ( ! V_64 )
return 1 ;
V_13 = ( * V_64 ) / 1000 ;
if ( V_13 < 100000 )
V_13 *= 10 ;
V_64 = F_51 ( V_60 , L_12 , NULL ) ;
if ( ! V_64 )
return 1 ;
V_14 = ( * V_64 ) / 1000 ;
F_45 = F_19 ;
V_58 = 1 ;
return 0 ;
}
static int F_59 ( struct V_52 * V_60 )
{
struct V_52 * V_61 ;
if ( F_51 ( V_60 , L_13 , NULL ) == NULL )
return 1 ;
V_61 = F_55 ( NULL , L_14 ) ;
if ( V_61 )
V_8 = F_50 ( V_61 ) ;
if ( ! V_8 ) {
F_56 ( L_15 ) ;
return 1 ;
}
V_14 = V_45 ;
V_13 = V_45 / 2 ;
V_45 = F_16 () ;
F_45 = F_13 ;
V_59 = F_16 ;
return 0 ;
}
static int F_60 ( struct V_52 * V_60 )
{
struct V_52 * V_61 ;
T_1 V_68 ;
const T_1 * V_64 ;
if ( F_51 ( V_60 , L_13 , NULL ) == NULL )
return 1 ;
V_14 = V_45 ;
V_64 = F_51 ( V_60 , L_16 , NULL ) ;
if ( ! V_64 )
return 1 ;
V_13 = ( * V_64 ) / 1000 ;
V_61 = F_55 ( NULL , L_14 ) ;
if ( V_61 )
V_8 = F_50 ( V_61 ) ;
V_68 = F_8 ( V_69 ) ;
V_9 = ! ( ( V_68 & 0xf00 ) == 0x100 ) ;
F_45 = F_6 ;
V_59 = F_12 ;
V_45 = F_12 () ;
return 0 ;
}
static int T_2 F_61 ( void )
{
struct V_52 * V_60 ;
const T_1 * V_64 ;
if ( strstr ( V_70 , L_17 ) )
return 0 ;
V_60 = F_62 ( 0 ) ;
if ( ! V_60 )
goto V_71;
V_64 = F_51 ( V_60 , L_18 , NULL ) ;
if ( ! V_64 )
goto V_71;
V_45 = ( * V_64 ) / 1000 ;
if ( F_63 ( L_19 ) &&
F_51 ( V_60 , L_13 , NULL ) &&
F_64 ( F_8 ( V_69 ) ) == 0x8003 ) {
F_59 ( V_60 ) ;
V_51 = 8000000 ;
V_72 . V_27 &= ~ V_73 ;
} else if ( F_63 ( L_20 ) ||
F_63 ( L_21 ) ||
F_63 ( L_19 ) ) {
F_54 ( V_60 ) ;
} else if ( F_63 ( L_22 ) ) {
V_14 = V_45 ;
V_13 = 400000 ;
F_45 = F_19 ;
V_58 = 1 ;
}
else if ( F_63 ( L_23 ) && V_45 == 550000 ) {
V_14 = V_45 ;
V_13 = 500000 ;
F_45 = F_19 ;
V_58 = 1 ;
}
else if ( F_63 ( L_24 ) ) {
if ( V_45 < 350000 || V_45 > 550000 )
goto V_71;
V_14 = V_45 ;
V_13 = 300000 ;
F_45 = F_19 ;
V_58 = 1 ;
}
else if ( F_64 ( F_8 ( V_69 ) ) == 0x7000 )
F_60 ( V_60 ) ;
V_71:
F_65 ( V_60 ) ;
if ( F_45 == NULL )
return - V_74 ;
V_50 [ V_42 ] . V_75 = V_13 ;
V_50 [ V_44 ] . V_75 = V_14 ;
V_49 = V_45 * 1000ul ;
F_66 ( L_25 ) ;
F_66 ( L_26 ,
V_13 / 1000 , V_14 / 1000 , V_45 / 1000 ) ;
return F_67 ( & V_72 ) ;
}
