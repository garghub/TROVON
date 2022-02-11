T_1 unsigned long F_1 ( void )
{
return V_1 ;
}
unsigned long F_2 ( struct V_2 * V_3 , unsigned long V_4 , unsigned long V_5 , unsigned long V_6 , unsigned long V_7 )
{
struct V_8 * V_9 ;
if ( V_7 & V_10 ) {
if ( ( V_7 & V_11 ) &&
( ( V_4 - ( V_6 << V_12 ) ) & ( V_13 - 1 ) ) )
return - V_14 ;
return V_4 ;
}
if ( V_5 > V_15 - V_1 )
return - V_16 ;
if ( V_17 && V_5 > 0x20000000 )
return - V_16 ;
if ( ! V_4 )
V_4 = V_18 ;
if ( V_7 & V_11 )
V_4 = F_3 ( V_4 ) ;
else
V_4 = F_4 ( V_4 ) ;
for ( V_9 = F_5 ( V_19 -> V_20 , V_4 ) ; ; V_9 = V_9 -> V_21 ) {
if ( V_17 && V_4 < 0xe0000000 && 0x20000000 - V_5 < V_4 ) {
V_4 = V_22 ;
V_9 = F_5 ( V_19 -> V_20 , V_22 ) ;
}
if ( V_15 - V_1 - V_5 < V_4 )
return - V_16 ;
if ( ! V_9 || V_4 + V_5 <= V_9 -> V_23 )
return V_4 ;
V_4 = V_9 -> V_24 ;
if ( V_7 & V_11 )
V_4 = F_3 ( V_4 ) ;
}
}
T_1 int F_6 ( struct V_25 * V_26 )
{
int V_27 [ 2 ] ;
int error ;
error = F_7 ( V_27 , 0 ) ;
if ( error )
goto V_28;
V_26 -> V_29 [ V_30 ] = V_27 [ 1 ] ;
error = V_27 [ 0 ] ;
V_28:
return error ;
}
int F_8 ( unsigned long V_4 , unsigned long V_5 )
{
if ( V_17 &&
( V_5 > 0x20000000 ||
( V_4 < 0xe0000000 && V_4 + V_5 > 0x20000000 ) ) )
return - V_14 ;
if ( V_5 > V_15 - V_1 || V_4 + V_5 > V_15 - V_1 )
return - V_14 ;
return 0 ;
}
T_1 unsigned long F_9 ( unsigned long V_4 , unsigned long V_5 ,
unsigned long V_31 , unsigned long V_7 , unsigned long V_27 ,
unsigned long V_6 )
{
return F_10 ( V_4 , V_5 , V_31 , V_7 , V_27 ,
V_6 >> ( V_12 - 12 ) ) ;
}
T_1 unsigned long F_11 ( unsigned long V_4 , unsigned long V_5 ,
unsigned long V_31 , unsigned long V_7 , unsigned long V_27 ,
unsigned long V_32 )
{
return F_10 ( V_4 , V_5 , V_31 , V_7 , V_27 , V_32 >> V_12 ) ;
}
long F_12 ( unsigned long V_33 , unsigned long V_34 ,
unsigned long V_31 , unsigned long V_6 ,
unsigned long V_7 )
{
return F_13 ( V_33 , V_34 , V_31 ,
( V_6 >> ( V_12 - 12 ) ) , V_7 ) ;
}
T_1 unsigned long
F_14 ( struct V_25 * V_26 )
{
static int V_35 = 0 ;
if ( V_35 ++ > 5 )
return - V_36 ;
F_15 ( L_1 ,
V_19 -> V_37 , F_16 ( V_19 ) , ( int ) V_26 -> V_29 [ 1 ] ) ;
#ifdef F_17
F_18 ( V_26 ) ;
#endif
return - V_36 ;
}
T_1 void
F_19 ( struct V_25 * V_26 )
{
T_2 V_38 ;
#ifdef F_20
F_15 ( L_2 , V_26 -> V_39 , V_26 -> V_40 ) ;
#endif
V_38 . V_41 = V_42 ;
V_38 . V_43 = 0 ;
V_38 . V_44 = V_45 ;
V_38 . V_46 = ( void V_47 * ) V_26 -> V_39 ;
V_38 . V_48 = 0 ;
F_21 ( V_42 , & V_38 , V_19 ) ;
#ifdef F_20
F_15 ( L_3 , V_26 -> V_39 , V_26 -> V_40 ) ;
#endif
}
T_1 int
F_22 ( int V_49 , const struct V_50 V_47 * V_51 ,
struct V_50 V_47 * V_52 )
{
struct V_53 V_54 , V_55 ;
int V_56 ;
F_23 ( V_49 >= 0 ) ;
V_49 = - V_49 ;
if ( V_51 ) {
unsigned long V_57 ;
if ( ! F_24 ( V_58 , V_51 , sizeof( * V_51 ) ) ||
F_25 ( V_54 . V_59 . V_60 , & V_51 -> V_60 ) ||
F_25 ( V_54 . V_59 . V_61 , & V_51 -> V_61 ) )
return - V_62 ;
F_25 ( V_54 . V_59 . V_63 , & V_51 -> V_63 ) ;
F_25 ( V_57 , & V_51 -> V_64 ) ;
F_26 ( & V_54 . V_59 . V_64 , V_57 ) ;
V_54 . V_65 = NULL ;
}
V_56 = F_27 ( V_49 , V_51 ? & V_54 : NULL , V_52 ? & V_55 : NULL ) ;
if ( ! V_56 && V_52 ) {
if ( ! F_24 ( V_66 , V_52 , sizeof( * V_52 ) ) ||
F_28 ( V_55 . V_59 . V_60 , & V_52 -> V_60 ) ||
F_28 ( V_55 . V_59 . V_61 , & V_52 -> V_61 ) )
return - V_62 ;
F_28 ( V_55 . V_59 . V_63 , & V_52 -> V_63 ) ;
F_28 ( V_55 . V_59 . V_64 . V_49 [ 0 ] , & V_52 -> V_64 ) ;
}
return V_56 ;
}
T_1 long
F_29 ( int V_49 ,
const struct V_67 V_47 * V_51 ,
struct V_67 V_47 * V_52 ,
void V_47 * V_68 ,
T_3 V_69 )
{
struct V_53 V_54 , V_55 ;
int V_56 ;
if ( V_69 != sizeof( V_70 ) )
return - V_14 ;
if ( V_51 ) {
V_54 . V_65 = V_68 ;
if ( F_30 ( & V_54 . V_59 , V_51 , sizeof( * V_51 ) ) )
return - V_62 ;
}
V_56 = F_27 ( V_49 , V_51 ? & V_54 : NULL , V_52 ? & V_55 : NULL ) ;
if ( ! V_56 && V_52 ) {
if ( F_31 ( V_52 , & V_55 . V_59 , sizeof( * V_52 ) ) )
return - V_62 ;
}
return V_56 ;
}
T_1 int F_32 ( char V_47 * V_71 , int V_5 )
{
int V_72 , V_73 ;
if ( V_5 < 0 )
return - V_14 ;
F_33 ( & V_74 ) ;
V_72 = strlen ( F_34 () -> V_75 ) + 1 ;
V_73 = - V_14 ;
if ( V_72 > V_5 )
goto V_28;
V_73 = - V_62 ;
if ( ! F_31 ( V_71 , F_34 () -> V_75 , V_72 ) )
V_73 = 0 ;
V_28:
F_35 ( & V_74 ) ;
return V_73 ;
}
int F_36 ( const char * V_76 ,
const char * const V_77 [] ,
const char * const V_78 [] )
{
long V_79 ;
register long T_4 V_80 ( L_4 ) = V_81 ;
register long T_5 V_80 ( L_5 ) = ( long ) ( V_76 ) ;
register long T_6 V_80 ( L_6 ) = ( long ) ( V_77 ) ;
register long T_7 V_80 ( L_7 ) = ( long ) ( V_78 ) ;
asm volatile ("t 0x10\n\t"
"bcc 1f\n\t"
"mov %%o0, %0\n\t"
"sub %%g0, %%o0, %0\n\t"
"1:\n\t"
: "=r" (__res), "=&r" (__o0)
: "1" (__o0), "r" (__o1), "r" (__o2), "r" (__g1)
: "cc");
return V_79 ;
}
