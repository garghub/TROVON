static inline void F_1 ( void )
{
T_1 V_1 ;
T_1 V_2 = F_2 ( V_3 ) ;
if ( F_3 ( V_2 ) ) {
V_1 = F_4 ( & V_3 , V_2 , 0 ) ;
if ( V_1 == V_2 )
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
}
}
static inline void F_5 ( enum V_5 V_6 , T_2 V_7 )
{
F_1 () ;
V_4 . V_8 [ V_6 ] += V_7 ;
}
static inline T_3 F_6 ( void )
{
return F_7 () ;
}
static void F_8 ( T_3 V_9 , T_2 * V_10 )
{
unsigned V_11 = F_9 ( V_9 ) ;
F_1 () ;
if ( V_11 < V_12 )
V_10 [ V_11 ] ++ ;
else
V_10 [ V_12 ] ++ ;
}
static inline void F_10 ( T_3 V_13 )
{
T_2 V_9 = F_7 () - V_13 ;
F_8 ( V_9 , V_4 . V_14 ) ;
V_4 . V_15 += V_9 ;
}
static inline void F_5 ( enum V_5 V_6 , T_2 V_7 )
{
}
static inline T_3 F_6 ( void )
{
return 0 ;
}
static inline void F_10 ( T_3 V_13 )
{
}
static void F_11 ( struct V_16 * V_17 , T_4 V_18 )
{
int V_19 = F_12 ( V_20 ) ;
struct V_21 * V_22 = & F_13 ( V_23 ) ;
int V_24 = F_14 () ;
T_3 V_13 ;
unsigned long V_25 ;
if ( V_19 == - 1 )
return;
V_13 = F_6 () ;
F_15 ( V_25 ) ;
V_22 -> V_17 = NULL ;
F_16 () ;
V_22 -> V_18 = V_18 ;
F_16 () ;
V_22 -> V_17 = V_17 ;
F_17 ( V_24 , & V_26 ) ;
F_5 ( V_27 , 1 ) ;
F_18 ( V_19 ) ;
F_19 () ;
F_20 ( V_17 ) ;
if ( F_2 ( V_17 -> V_28 . V_29 ) == V_18 ) {
F_5 ( V_30 , 1 ) ;
goto V_31;
}
F_21 ( V_25 ) ;
F_22 ( V_19 ) ;
F_5 ( V_32 , ! F_23 ( V_19 ) ) ;
F_15 ( V_25 ) ;
F_24 ( V_19 , F_25 ( V_19 ) ) ;
V_31:
F_26 ( V_24 , & V_26 ) ;
V_22 -> V_17 = NULL ;
F_21 ( V_25 ) ;
F_10 ( V_13 ) ;
}
static void F_27 ( struct V_16 * V_17 , T_4 V_33 )
{
int V_24 ;
F_5 ( V_34 , 1 ) ;
F_28 (cpu, &waiting_cpus) {
const struct V_21 * V_22 = & F_29 ( V_23 , V_24 ) ;
if ( F_2 ( V_22 -> V_17 ) == V_17 &&
F_2 ( V_22 -> V_18 ) == V_33 ) {
F_5 ( V_35 , 1 ) ;
F_30 ( V_24 , V_36 ) ;
break;
}
}
}
static T_5 F_31 ( int V_19 , void * V_37 )
{
F_32 () ;
return V_38 ;
}
void F_33 ( int V_24 )
{
int V_19 ;
char * V_39 ;
if ( ! V_40 )
return;
F_34 ( F_29 ( V_20 , V_24 ) >= 0 , L_1 ,
V_24 , F_29 ( V_20 , V_24 ) ) ;
V_39 = F_35 ( V_41 , L_2 , V_24 ) ;
V_19 = F_36 ( V_36 ,
V_24 ,
F_31 ,
V_42 | V_43 | V_44 ,
V_39 ,
NULL ) ;
if ( V_19 >= 0 ) {
F_37 ( V_19 ) ;
F_29 ( V_20 , V_24 ) = V_19 ;
F_29 ( V_45 , V_24 ) = V_39 ;
}
F_38 ( L_3 , V_24 , V_19 ) ;
}
void F_39 ( int V_24 )
{
if ( ! V_40 )
return;
F_40 ( F_29 ( V_20 , V_24 ) , NULL ) ;
F_29 ( V_20 , V_24 ) = - 1 ;
F_41 ( F_29 ( V_45 , V_24 ) ) ;
F_29 ( V_45 , V_24 ) = NULL ;
}
void T_6 F_42 ( void )
{
if ( ! V_40 ) {
F_38 ( V_46 L_4 ) ;
return;
}
V_47 . V_48 = F_43 ( F_11 ) ;
V_47 . V_49 = F_27 ;
}
static T_6 int F_44 ( void )
{
if ( ! V_40 )
return 0 ;
F_45 ( & V_50 ) ;
return 0 ;
}
static T_6 int F_46 ( char * V_51 )
{
V_40 = false ;
return 0 ;
}
static int T_6 F_47 ( void )
{
struct V_52 * V_53 = F_48 () ;
if ( V_53 == NULL )
return - V_54 ;
if ( ! V_40 )
return 0 ;
V_55 = F_49 ( L_5 , V_53 ) ;
F_50 ( L_6 , 0644 , V_55 , & V_3 ) ;
F_51 ( L_7 , 0444 , V_55 ,
& V_4 . V_8 [ V_27 ] ) ;
F_51 ( L_8 , 0444 , V_55 ,
& V_4 . V_8 [ V_30 ] ) ;
F_51 ( L_9 , 0444 , V_55 ,
& V_4 . V_8 [ V_32 ] ) ;
F_51 ( L_10 , 0444 , V_55 ,
& V_4 . V_8 [ V_34 ] ) ;
F_51 ( L_11 , 0444 , V_55 ,
& V_4 . V_8 [ V_35 ] ) ;
F_52 ( L_12 , 0444 , V_55 ,
& V_4 . V_15 ) ;
F_53 ( L_13 , 0444 , V_55 ,
V_4 . V_14 , V_12 + 1 ) ;
return 0 ;
}
