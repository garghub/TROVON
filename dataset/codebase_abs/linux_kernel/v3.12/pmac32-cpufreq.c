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
F_38 ( NULL , V_35 -> V_36 ) ;
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
static int F_44 ( struct V_37 * V_38 , int V_39 ,
int V_40 )
{
struct V_41 V_42 ;
unsigned long V_43 ;
static unsigned long V_44 ;
V_42 . V_45 = V_46 ;
V_42 . V_47 = ( V_39 == V_48 ) ? V_14 : V_13 ;
if ( V_42 . V_45 == V_42 . V_47 )
return 0 ;
if ( V_40 )
F_45 ( V_38 , & V_42 , V_49 ) ;
if ( V_39 == V_50 &&
F_29 ( V_51 ) ) {
V_43 = F_31 () ;
if ( V_43 & V_34 ) {
V_44 = V_43 ;
F_37 ( 0 ) ;
}
}
F_46 ( V_39 == V_50 ) ;
if ( V_39 == V_48 &&
F_29 ( V_51 ) ) {
V_43 = F_31 () ;
if ( ( V_44 & V_34 ) && V_43 != V_44 )
F_37 ( V_44 ) ;
}
if ( V_40 )
F_45 ( V_38 , & V_42 , V_52 ) ;
V_46 = ( V_39 == V_48 ) ? V_14 : V_13 ;
return 0 ;
}
static unsigned int F_47 ( unsigned int V_53 )
{
return V_46 ;
}
static int F_48 ( struct V_37 * V_38 )
{
return F_49 ( V_38 , V_54 ) ;
}
static int F_50 ( struct V_37 * V_38 ,
unsigned int V_55 ,
unsigned int V_56 )
{
unsigned int V_57 = 0 ;
int V_58 ;
if ( F_51 ( V_38 , V_54 ,
V_55 , V_56 , & V_57 ) )
return - V_59 ;
V_58 = F_44 ( V_38 , V_57 , 1 ) ;
V_60 = V_46 * 1000ul ;
return V_58 ;
}
static int F_52 ( struct V_37 * V_38 )
{
if ( V_38 -> V_53 != 0 )
return - V_61 ;
V_38 -> V_62 . V_63 = V_63 ;
V_38 -> V_64 = V_46 ;
F_53 ( V_54 , V_38 -> V_53 ) ;
return F_54 ( V_38 , V_54 ) ;
}
static T_1 F_55 ( struct V_65 * V_66 )
{
const T_1 * V_67 = F_56 ( V_66 , L_3 , NULL ) ;
T_1 V_68 ;
if ( V_67 == NULL )
return 0 ;
V_68 = * V_67 ;
if ( V_68 < V_69 )
V_68 += V_69 ;
return V_68 ;
}
static int F_57 ( struct V_37 * V_38 )
{
V_2 = 1 ;
V_70 = V_46 ;
if ( V_46 == V_13 && ! V_71 )
F_44 ( V_38 , V_48 , 0 ) ;
return 0 ;
}
static int F_58 ( struct V_37 * V_38 )
{
if ( V_72 )
V_46 = V_72 () ;
else
V_46 = 0 ;
F_44 ( V_38 , V_70 == V_13 ?
V_50 : V_48 , 0 ) ;
V_60 = V_46 * 1000ul ;
V_2 = 0 ;
return 0 ;
}
static int F_59 ( struct V_65 * V_73 )
{
struct V_65 * V_74 = F_60 ( NULL ,
L_4 ) ;
struct V_65 * V_75 = F_60 ( NULL ,
L_5 ) ;
struct V_65 * V_76 = F_60 ( NULL ,
L_6 ) ;
const T_1 * V_77 ;
if ( V_74 )
V_8 = F_55 ( V_74 ) ;
if ( V_75 )
V_19 = F_55 ( V_75 ) ;
if ( V_76 )
V_21 = F_55 ( V_76 ) ;
if ( V_19 && V_21 ) {
int V_78 , V_58 ;
const T_1 * V_42 , * V_79 ;
V_42 = F_56 ( V_73 , L_7 , & V_78 ) ;
V_78 /= sizeof( T_1 ) ;
if ( V_42 == NULL || V_78 != 2 ) {
F_21 ( V_80 L_8 ) ;
return 1 ;
}
V_79 = F_56 ( V_73 , L_9 ,
NULL ) ;
if ( V_79 == NULL ) {
F_21 ( V_80 L_10 ) ;
return 1 ;
}
V_13 = F_61 ( V_42 [ 0 ] , V_42 [ 1 ] ) ;
V_14 = F_62 ( V_42 [ 0 ] , V_42 [ 1 ] ) ;
if ( V_13 < 98000000 )
V_13 = 101000000 ;
V_13 = ( V_13 * ( * V_79 ) ) / 2000 ;
V_14 = ( V_14 * ( * V_79 ) ) / 2000 ;
V_58 = F_7 ( V_18 , NULL , V_19 , 0 ) ;
V_46 = ( V_58 & 0x01 ) ? V_14 : V_13 ;
F_46 = F_17 ;
return 1 ;
}
V_77 = F_56 ( V_73 , L_11 , NULL ) ;
if ( ! V_77 )
return 1 ;
V_13 = ( * V_77 ) / 1000 ;
if ( V_13 < 100000 )
V_13 *= 10 ;
V_77 = F_56 ( V_73 , L_12 , NULL ) ;
if ( ! V_77 )
return 1 ;
V_14 = ( * V_77 ) / 1000 ;
F_46 = F_19 ;
V_71 = 1 ;
return 0 ;
}
static int F_63 ( struct V_65 * V_73 )
{
struct V_65 * V_74 ;
if ( F_56 ( V_73 , L_13 , NULL ) == NULL )
return 1 ;
V_74 = F_60 ( NULL , L_14 ) ;
if ( V_74 )
V_8 = F_55 ( V_74 ) ;
if ( ! V_8 ) {
F_21 ( V_80 L_15 ) ;
return 1 ;
}
V_14 = V_46 ;
V_13 = V_46 / 2 ;
V_46 = F_16 () ;
F_46 = F_13 ;
V_72 = F_16 ;
return 0 ;
}
static int F_64 ( struct V_65 * V_73 )
{
struct V_65 * V_74 ;
T_1 V_81 ;
const T_1 * V_77 ;
if ( F_56 ( V_73 , L_13 , NULL ) == NULL )
return 1 ;
V_14 = V_46 ;
V_77 = F_56 ( V_73 , L_16 , NULL ) ;
if ( ! V_77 )
return 1 ;
V_13 = ( * V_77 ) / 1000 ;
V_74 = F_60 ( NULL , L_14 ) ;
if ( V_74 )
V_8 = F_55 ( V_74 ) ;
V_81 = F_8 ( V_82 ) ;
V_9 = ! ( ( V_81 & 0xf00 ) == 0x100 ) ;
F_46 = F_6 ;
V_72 = F_12 ;
V_46 = F_12 () ;
return 0 ;
}
static int T_2 F_65 ( void )
{
struct V_65 * V_73 ;
const T_1 * V_77 ;
if ( strstr ( V_83 , L_17 ) )
return 0 ;
V_73 = F_66 ( 0 ) ;
if ( ! V_73 )
goto V_84;
V_77 = F_56 ( V_73 , L_18 , NULL ) ;
if ( ! V_77 )
goto V_84;
V_46 = ( * V_77 ) / 1000 ;
V_63 = V_85 ;
if ( F_67 ( L_19 ) &&
F_56 ( V_73 , L_13 , NULL ) &&
F_68 ( F_8 ( V_82 ) ) == 0x8003 ) {
F_63 ( V_73 ) ;
V_63 = 8000000 ;
} else if ( F_67 ( L_20 ) ||
F_67 ( L_21 ) ||
F_67 ( L_19 ) ) {
F_59 ( V_73 ) ;
} else if ( F_67 ( L_22 ) ) {
V_14 = V_46 ;
V_13 = 400000 ;
F_46 = F_19 ;
V_71 = 1 ;
}
else if ( F_67 ( L_23 ) && V_46 == 550000 ) {
V_14 = V_46 ;
V_13 = 500000 ;
F_46 = F_19 ;
V_71 = 1 ;
}
else if ( F_67 ( L_24 ) ) {
if ( V_46 < 350000 || V_46 > 550000 )
goto V_84;
V_14 = V_46 ;
V_13 = 300000 ;
F_46 = F_19 ;
V_71 = 1 ;
}
else if ( F_68 ( F_8 ( V_82 ) ) == 0x7000 )
F_64 ( V_73 ) ;
V_84:
F_69 ( V_73 ) ;
if ( F_46 == NULL )
return - V_61 ;
V_54 [ V_50 ] . V_86 = V_13 ;
V_54 [ V_48 ] . V_86 = V_14 ;
V_60 = V_46 * 1000ul ;
F_21 ( V_87 L_25 ) ;
F_21 ( V_87 L_26 ,
V_13 / 1000 , V_14 / 1000 , V_46 / 1000 ) ;
return F_70 ( & V_88 ) ;
}
