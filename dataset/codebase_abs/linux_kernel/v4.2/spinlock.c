static void F_1 ( int V_1 )
{
F_2 ( V_1 , V_2 ) ;
}
static void F_3 ( T_1 * V_3 , T_1 V_4 )
{
int V_5 = F_4 ( V_6 ) ;
if ( V_5 == - 1 )
return;
F_5 ( V_5 ) ;
F_6 () ;
if ( F_7 ( * V_3 ) != V_4 )
return;
F_8 ( V_5 ) ;
}
static inline void F_9 ( void )
{
T_1 V_7 ;
T_1 V_8 = F_7 ( V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_7 = F_11 ( & V_9 , V_8 , 0 ) ;
if ( V_7 == V_8 )
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
}
}
static inline void F_12 ( enum V_11 V_12 , T_2 V_4 )
{
F_9 () ;
V_10 . V_13 [ V_12 ] += V_4 ;
}
static inline T_3 F_13 ( void )
{
return F_14 () ;
}
static void F_15 ( T_3 V_14 , T_2 * V_15 )
{
unsigned V_16 = F_16 ( V_14 ) ;
F_9 () ;
if ( V_16 < V_17 )
V_15 [ V_16 ] ++ ;
else
V_15 [ V_17 ] ++ ;
}
static inline void F_17 ( T_3 V_18 )
{
T_2 V_14 = F_14 () - V_18 ;
F_15 ( V_14 , V_10 . V_19 ) ;
V_10 . V_20 += V_14 ;
}
static inline void F_12 ( enum V_11 V_12 , T_2 V_4 )
{
}
static inline T_3 F_13 ( void )
{
return 0 ;
}
static inline void F_17 ( T_3 V_18 )
{
}
T_4 void F_18 ( struct V_21 * V_22 , T_5 V_23 )
{
int V_5 = F_4 ( V_6 ) ;
struct V_24 * V_25 = F_19 ( & V_26 ) ;
int V_1 = F_20 () ;
T_3 V_18 ;
T_5 V_27 ;
unsigned long V_28 ;
if ( V_5 == - 1 )
return;
V_18 = F_13 () ;
F_21 ( V_28 ) ;
V_25 -> V_22 = NULL ;
F_22 () ;
V_25 -> V_23 = V_23 ;
F_22 () ;
V_25 -> V_22 = V_22 ;
F_23 ( V_1 , & V_29 ) ;
F_12 ( V_30 , 1 ) ;
F_5 ( V_5 ) ;
F_6 () ;
F_24 ( V_22 ) ;
F_25 () ;
V_27 = F_7 ( V_22 -> V_31 . V_27 ) ;
if ( F_26 ( V_27 , V_23 ) ) {
F_12 ( V_32 , 1 ) ;
goto V_33;
}
F_27 ( V_28 ) ;
F_8 ( V_5 ) ;
F_12 ( V_34 , ! F_28 ( V_5 ) ) ;
F_21 ( V_28 ) ;
F_29 ( V_5 ) ;
V_33:
F_30 ( V_1 , & V_29 ) ;
V_25 -> V_22 = NULL ;
F_27 ( V_28 ) ;
F_17 ( V_18 ) ;
}
static void F_31 ( struct V_21 * V_22 , T_5 V_35 )
{
int V_1 ;
F_12 ( V_36 , 1 ) ;
F_32 (cpu, &waiting_cpus) {
const struct V_24 * V_25 = & F_33 ( V_26 , V_1 ) ;
if ( F_7 ( V_25 -> V_22 ) == V_22 &&
F_7 ( V_25 -> V_23 ) == V_35 ) {
F_12 ( V_37 , 1 ) ;
F_2 ( V_1 , V_2 ) ;
break;
}
}
}
static T_6 F_34 ( int V_5 , void * V_38 )
{
F_35 () ;
return V_39 ;
}
void F_36 ( int V_1 )
{
int V_5 ;
char * V_40 ;
if ( ! V_41 )
return;
F_37 ( F_33 ( V_6 , V_1 ) >= 0 , L_1 ,
V_1 , F_33 ( V_6 , V_1 ) ) ;
V_40 = F_38 ( V_42 , L_2 , V_1 ) ;
V_5 = F_39 ( V_2 ,
V_1 ,
F_34 ,
V_43 | V_44 ,
V_40 ,
NULL ) ;
if ( V_5 >= 0 ) {
F_40 ( V_5 ) ;
F_33 ( V_6 , V_1 ) = V_5 ;
F_33 ( V_45 , V_1 ) = V_40 ;
}
F_41 ( L_3 , V_1 , V_5 ) ;
}
void F_42 ( int V_1 )
{
if ( ! V_41 )
return;
F_43 ( F_33 ( V_6 , V_1 ) , NULL ) ;
F_33 ( V_6 , V_1 ) = - 1 ;
F_44 ( F_33 ( V_45 , V_1 ) ) ;
F_33 ( V_45 , V_1 ) = NULL ;
}
void T_7 F_45 ( void )
{
if ( ! V_41 ) {
F_41 ( V_46 L_4 ) ;
return;
}
F_41 ( V_46 L_5 ) ;
#ifdef F_46
F_47 () ;
V_47 . V_48 = V_49 ;
V_47 . V_50 = F_48 ( V_51 ) ;
V_47 . V_52 = F_3 ;
V_47 . V_53 = F_1 ;
#else
V_47 . V_54 = F_48 ( F_18 ) ;
V_47 . V_55 = F_31 ;
#endif
}
static T_7 int F_49 ( void )
{
if ( ! V_41 )
return 0 ;
if ( ! F_50 () )
return 0 ;
F_51 ( & V_56 ) ;
return 0 ;
}
static T_7 int F_52 ( char * V_57 )
{
V_41 = false ;
return 0 ;
}
static int T_7 F_53 ( void )
{
struct V_58 * V_59 = F_54 () ;
if ( V_59 == NULL )
return - V_60 ;
if ( ! V_41 )
return 0 ;
V_61 = F_55 ( L_6 , V_59 ) ;
F_56 ( L_7 , 0644 , V_61 , & V_9 ) ;
F_57 ( L_8 , 0444 , V_61 ,
& V_10 . V_13 [ V_30 ] ) ;
F_57 ( L_9 , 0444 , V_61 ,
& V_10 . V_13 [ V_32 ] ) ;
F_57 ( L_10 , 0444 , V_61 ,
& V_10 . V_13 [ V_34 ] ) ;
F_57 ( L_11 , 0444 , V_61 ,
& V_10 . V_13 [ V_36 ] ) ;
F_57 ( L_12 , 0444 , V_61 ,
& V_10 . V_13 [ V_37 ] ) ;
F_58 ( L_13 , 0444 , V_61 ,
& V_10 . V_20 ) ;
F_59 ( L_14 , 0444 , V_61 ,
V_10 . V_19 , V_17 + 1 ) ;
return 0 ;
}
