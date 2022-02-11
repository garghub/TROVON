static bool T_1 F_1 ( void )
{
#ifdef F_2
T_2 * V_1 = NULL ;
unsigned int V_2 ;
F_3 (cpu) {
int V_3 = F_4 ( V_2 ) ;
if ( F_5 ( V_3 ) && F_6 ( V_3 ) &&
V_1 && V_1 != F_6 ( V_3 ) )
return true ;
V_1 = F_6 ( V_3 ) ;
}
#endif
return false ;
}
static void * T_1 F_7 ( unsigned int V_2 , unsigned long V_4 ,
unsigned long V_5 )
{
const unsigned long V_6 = F_8 ( V_7 ) ;
#ifdef F_2
int V_3 = F_4 ( V_2 ) ;
void * V_8 ;
if ( ! F_5 ( V_3 ) || ! F_6 ( V_3 ) ) {
V_8 = F_9 ( V_4 , V_5 , V_6 ) ;
F_10 ( L_1 ,
V_2 , V_3 ) ;
F_11 ( L_2 ,
V_2 , V_4 , F_8 ( V_8 ) ) ;
} else {
V_8 = F_12 ( F_6 ( V_3 ) ,
V_4 , V_5 , V_6 ) ;
F_11 ( L_3 ,
V_2 , V_4 , V_3 , F_8 ( V_8 ) ) ;
}
return V_8 ;
#else
return F_9 ( V_4 , V_5 , V_6 ) ;
#endif
}
static void * T_1 F_13 ( unsigned int V_2 , T_3 V_4 , T_3 V_5 )
{
return F_7 ( V_2 , V_4 , V_5 ) ;
}
static void T_1 F_14 ( void * V_8 , T_3 V_4 )
{
F_15 ( F_8 ( V_8 ) , V_4 ) ;
}
static int T_1 F_16 ( unsigned int V_9 , unsigned int V_10 )
{
#ifdef F_2
if ( F_4 ( V_9 ) == F_4 ( V_10 ) )
return V_11 ;
else
return V_12 ;
#else
return V_11 ;
#endif
}
static void T_1 F_17 ( unsigned long V_13 )
{
F_18 ( V_13 ) ;
}
static inline void F_19 ( int V_2 )
{
#ifdef F_20
struct V_14 V_15 ;
F_21 ( & V_15 , F_22 ( V_2 ) , 0xFFFFF ,
0x2 | V_16 , 0x8 ) ;
V_15 . V_17 = 1 ;
F_23 ( F_24 ( V_2 ) ,
V_18 , & V_15 , V_16 ) ;
#endif
}
void T_1 F_25 ( void )
{
unsigned int V_2 ;
unsigned long V_19 ;
int V_20 ;
F_10 ( L_4 ,
V_21 , V_22 , V_23 , V_24 ) ;
#ifdef F_20
if ( V_25 == V_26 && F_1 () )
V_25 = V_27 ;
#endif
V_20 = - V_28 ;
if ( V_25 != V_27 ) {
const T_3 V_29 = V_30 +
V_31 - V_32 ;
T_3 V_33 ;
#ifdef F_26
V_33 = V_34 ;
#else
V_33 = V_35 ;
#endif
V_20 = F_27 ( V_32 ,
V_29 , V_33 ,
F_16 ,
F_13 , F_14 ) ;
if ( V_20 < 0 )
F_28 ( L_5 ,
V_36 [ V_25 ] , V_20 ) ;
}
if ( V_20 < 0 )
V_20 = F_29 ( V_32 ,
F_13 , F_14 ,
F_17 ) ;
if ( V_20 < 0 )
F_30 ( L_6 , V_20 ) ;
V_19 = ( unsigned long ) V_37 - ( unsigned long ) V_38 ;
F_3 (cpu) {
F_22 ( V_2 ) = V_19 + V_39 [ V_2 ] ;
F_31 ( V_40 , V_2 ) = F_22 ( V_2 ) ;
F_31 ( V_41 , V_2 ) = V_2 ;
F_19 ( V_2 ) ;
F_32 ( V_2 ) ;
#ifdef F_33
F_31 ( V_42 , V_2 ) =
F_34 ( V_42 , V_2 ) ;
F_31 ( V_43 , V_2 ) =
F_34 ( V_43 , V_2 ) ;
#endif
#ifdef F_20
F_31 ( V_44 , V_2 ) =
F_34 ( V_44 , V_2 ) ;
#endif
#ifdef F_26
F_31 ( V_45 , V_2 ) =
F_31 ( V_46 . V_47 , V_2 ) +
V_48 - 64 ;
#endif
#ifdef F_35
F_31 ( V_49 , V_2 ) =
F_34 ( V_49 , V_2 ) ;
F_36 ( V_2 , F_4 ( V_2 ) ) ;
#endif
if ( ! V_2 )
F_37 ( V_2 ) ;
}
#ifdef F_33
F_38 ( V_42 ) = NULL ;
F_38 ( V_43 ) = NULL ;
#endif
#ifdef F_20
F_38 ( V_44 ) = NULL ;
#endif
#ifdef F_35
F_38 ( V_49 ) = NULL ;
#endif
F_39 () ;
F_40 () ;
}
