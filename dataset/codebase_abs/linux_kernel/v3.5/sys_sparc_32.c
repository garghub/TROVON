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
if ( ! V_4 )
V_4 = V_17 ;
if ( V_7 & V_11 )
V_4 = F_3 ( V_4 ) ;
else
V_4 = F_4 ( V_4 ) ;
for ( V_9 = F_5 ( V_18 -> V_19 , V_4 ) ; ; V_9 = V_9 -> V_20 ) {
if ( V_15 - V_1 - V_5 < V_4 )
return - V_16 ;
if ( ! V_9 || V_4 + V_5 <= V_9 -> V_21 )
return V_4 ;
V_4 = V_9 -> V_22 ;
if ( V_7 & V_11 )
V_4 = F_3 ( V_4 ) ;
}
}
T_1 int F_6 ( struct V_23 * V_24 )
{
int V_25 [ 2 ] ;
int error ;
error = F_7 ( V_25 , 0 ) ;
if ( error )
goto V_26;
V_24 -> V_27 [ V_28 ] = V_25 [ 1 ] ;
error = V_25 [ 0 ] ;
V_26:
return error ;
}
int F_8 ( unsigned long V_4 , unsigned long V_5 )
{
if ( V_5 > V_15 - V_1 || V_4 + V_5 > V_15 - V_1 )
return - V_14 ;
return 0 ;
}
T_1 unsigned long F_9 ( unsigned long V_4 , unsigned long V_5 ,
unsigned long V_29 , unsigned long V_7 , unsigned long V_25 ,
unsigned long V_6 )
{
return F_10 ( V_4 , V_5 , V_29 , V_7 , V_25 ,
V_6 >> ( V_12 - 12 ) ) ;
}
T_1 unsigned long F_11 ( unsigned long V_4 , unsigned long V_5 ,
unsigned long V_29 , unsigned long V_7 , unsigned long V_25 ,
unsigned long V_30 )
{
return F_10 ( V_4 , V_5 , V_29 , V_7 , V_25 , V_30 >> V_12 ) ;
}
long F_12 ( unsigned long V_31 , unsigned long V_32 ,
unsigned long V_29 , unsigned long V_6 ,
unsigned long V_7 )
{
return F_13 ( V_31 , V_32 , V_29 ,
( V_6 >> ( V_12 - 12 ) ) , V_7 ) ;
}
T_1 unsigned long
F_14 ( struct V_23 * V_24 )
{
static int V_33 = 0 ;
if ( V_33 ++ > 5 )
return - V_34 ;
F_15 ( L_1 ,
V_18 -> V_35 , F_16 ( V_18 ) , ( int ) V_24 -> V_27 [ 1 ] ) ;
#ifdef F_17
F_18 ( V_24 ) ;
#endif
return - V_34 ;
}
T_1 void
F_19 ( struct V_23 * V_24 )
{
T_2 V_36 ;
#ifdef F_20
F_15 ( L_2 , V_24 -> V_37 , V_24 -> V_38 ) ;
#endif
V_36 . V_39 = V_40 ;
V_36 . V_41 = 0 ;
V_36 . V_42 = V_43 ;
V_36 . V_44 = ( void V_45 * ) V_24 -> V_37 ;
V_36 . V_46 = 0 ;
F_21 ( V_40 , & V_36 , V_18 ) ;
#ifdef F_20
F_15 ( L_3 , V_24 -> V_37 , V_24 -> V_38 ) ;
#endif
}
T_1 int
F_22 ( int V_47 , const struct V_48 V_45 * V_49 ,
struct V_48 V_45 * V_50 )
{
struct V_51 V_52 , V_53 ;
int V_54 ;
F_23 ( V_47 >= 0 ) ;
V_47 = - V_47 ;
if ( V_49 ) {
unsigned long V_55 ;
if ( ! F_24 ( V_56 , V_49 , sizeof( * V_49 ) ) ||
F_25 ( V_52 . V_57 . V_58 , & V_49 -> V_58 ) ||
F_25 ( V_52 . V_57 . V_59 , & V_49 -> V_59 ) ||
F_25 ( V_52 . V_57 . V_60 , & V_49 -> V_60 ) ||
F_25 ( V_55 , & V_49 -> V_61 ) )
return - V_62 ;
F_26 ( & V_52 . V_57 . V_61 , V_55 ) ;
V_52 . V_63 = NULL ;
}
V_54 = F_27 ( V_47 , V_49 ? & V_52 : NULL , V_50 ? & V_53 : NULL ) ;
if ( ! V_54 && V_50 ) {
if ( ! F_24 ( V_64 , V_50 , sizeof( * V_50 ) ) ||
F_28 ( V_53 . V_57 . V_58 , & V_50 -> V_58 ) ||
F_28 ( V_53 . V_57 . V_59 , & V_50 -> V_59 ) ||
F_28 ( V_53 . V_57 . V_60 , & V_50 -> V_60 ) ||
F_28 ( V_53 . V_57 . V_61 . V_47 [ 0 ] , & V_50 -> V_61 ) )
return - V_62 ;
}
return V_54 ;
}
T_1 long
F_29 ( int V_47 ,
const struct V_65 V_45 * V_49 ,
struct V_65 V_45 * V_50 ,
void V_45 * V_66 ,
T_3 V_67 )
{
struct V_51 V_52 , V_53 ;
int V_54 ;
if ( V_67 != sizeof( V_68 ) )
return - V_14 ;
if ( V_49 ) {
V_52 . V_63 = V_66 ;
if ( F_30 ( & V_52 . V_57 , V_49 , sizeof( * V_49 ) ) )
return - V_62 ;
}
V_54 = F_27 ( V_47 , V_49 ? & V_52 : NULL , V_50 ? & V_53 : NULL ) ;
if ( ! V_54 && V_50 ) {
if ( F_31 ( V_50 , & V_53 . V_57 , sizeof( * V_50 ) ) )
return - V_62 ;
}
return V_54 ;
}
T_1 int F_32 ( char V_45 * V_69 , int V_5 )
{
int V_70 , V_71 ;
if ( V_5 < 0 )
return - V_14 ;
F_33 ( & V_72 ) ;
V_70 = strlen ( F_34 () -> V_73 ) + 1 ;
V_71 = - V_14 ;
if ( V_70 > V_5 )
goto V_26;
V_71 = - V_62 ;
if ( ! F_31 ( V_69 , F_34 () -> V_73 , V_70 ) )
V_71 = 0 ;
V_26:
F_35 ( & V_72 ) ;
return V_71 ;
}
int F_36 ( const char * V_74 ,
const char * const V_75 [] ,
const char * const V_76 [] )
{
long V_77 ;
register long T_4 V_78 ( L_4 ) = V_79 ;
register long T_5 V_78 ( L_5 ) = ( long ) ( V_74 ) ;
register long T_6 V_78 ( L_6 ) = ( long ) ( V_75 ) ;
register long T_7 V_78 ( L_7 ) = ( long ) ( V_76 ) ;
asm volatile ("t 0x10\n\t"
"bcc 1f\n\t"
"mov %%o0, %0\n\t"
"sub %%g0, %%o0, %0\n\t"
"1:\n\t"
: "=r" (__res), "=&r" (__o0)
: "1" (__o0), "r" (__o1), "r" (__o2), "r" (__g1)
: "cc");
return V_77 ;
}
