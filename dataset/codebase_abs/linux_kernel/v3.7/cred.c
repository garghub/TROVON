static inline void F_1 ( struct V_1 * V_1 , int V_2 )
{
#ifdef F_2
F_3 ( & V_1 -> V_3 , V_2 ) ;
#endif
}
static inline int F_4 ( const struct V_1 * V_1 )
{
#ifdef F_2
return F_5 ( & V_1 -> V_3 ) ;
#else
return 0 ;
#endif
}
static inline void F_6 ( const struct V_1 * V_4 , int V_2 )
{
#ifdef F_2
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
F_7 ( V_2 , & V_1 -> V_3 ) ;
#endif
}
static void F_8 ( struct V_5 * V_6 )
{
struct V_7 * V_8 =
F_9 ( V_6 , struct V_7 , V_6 ) ;
F_10 ( F_5 ( & V_8 -> V_9 ) != 0 ) ;
F_11 ( V_8 -> V_10 ) ;
F_11 ( V_8 -> V_11 ) ;
F_12 ( V_8 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
#ifdef F_14
struct V_7 * V_8 = V_1 -> V_8 ;
if ( F_15 ( & V_8 -> V_9 ) )
F_16 ( & V_8 -> V_6 , F_8 ) ;
#endif
}
static void F_17 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_9 ( V_6 , struct V_1 , V_6 ) ;
F_18 ( L_1 , V_1 ) ;
#ifdef F_2
if ( V_1 -> V_12 != V_13 ||
F_5 ( & V_1 -> V_9 ) != 0 ||
F_4 ( V_1 ) != 0 )
F_19 ( L_2
L_3 ,
V_1 , V_1 -> V_12 , V_1 -> V_14 ,
F_5 ( & V_1 -> V_9 ) ,
F_4 ( V_1 ) ) ;
#else
if ( F_5 ( & V_1 -> V_9 ) != 0 )
F_19 ( L_4 ,
V_1 , F_5 ( & V_1 -> V_9 ) ) ;
#endif
F_20 ( V_1 ) ;
F_11 ( V_1 -> V_15 ) ;
F_11 ( V_1 -> V_16 ) ;
F_13 ( V_1 ) ;
if ( V_1 -> V_17 )
F_21 ( V_1 -> V_17 ) ;
F_22 ( V_1 -> V_18 ) ;
F_23 ( V_1 -> V_19 ) ;
F_24 ( V_20 , V_1 ) ;
}
void F_25 ( struct V_1 * V_1 )
{
F_18 ( L_5 , V_1 ,
F_5 ( & V_1 -> V_9 ) ,
F_4 ( V_1 ) ) ;
F_10 ( F_5 ( & V_1 -> V_9 ) != 0 ) ;
#ifdef F_2
F_10 ( F_4 ( V_1 ) != 0 ) ;
V_1 -> V_12 = V_13 ;
V_1 -> V_14 = F_26 ( 0 ) ;
#endif
F_10 ( V_1 == V_21 -> V_1 ) ;
F_10 ( V_1 == V_21 -> V_22 ) ;
F_16 ( & V_1 -> V_6 , F_17 ) ;
}
void F_27 ( struct V_23 * V_24 )
{
struct V_1 * V_1 ;
F_18 ( L_6 , V_24 -> V_25 , V_24 -> V_22 , V_24 -> V_1 ,
F_5 ( & V_24 -> V_1 -> V_9 ) ,
F_4 ( V_24 -> V_1 ) ) ;
V_1 = (struct V_1 * ) V_24 -> V_22 ;
V_24 -> V_22 = NULL ;
F_28 ( V_1 ) ;
F_6 ( V_1 , - 1 ) ;
F_29 ( V_1 ) ;
V_1 = (struct V_1 * ) V_24 -> V_1 ;
V_24 -> V_1 = NULL ;
F_28 ( V_1 ) ;
F_6 ( V_1 , - 1 ) ;
F_29 ( V_1 ) ;
}
const struct V_1 * F_30 ( struct V_23 * V_26 )
{
const struct V_1 * V_1 ;
F_31 () ;
do {
V_1 = F_32 ( ( V_26 ) ) ;
F_10 ( ! V_1 ) ;
} while ( ! F_33 ( & ( (struct V_1 * ) V_1 ) -> V_9 ) );
F_34 () ;
return V_1 ;
}
struct V_1 * F_35 ( void )
{
struct V_1 * V_27 ;
V_27 = F_36 ( V_20 , V_28 ) ;
if ( ! V_27 )
return NULL ;
#ifdef F_14
V_27 -> V_8 = F_37 ( sizeof( * V_27 -> V_8 ) , V_28 ) ;
if ( ! V_27 -> V_8 ) {
F_24 ( V_20 , V_27 ) ;
return NULL ;
}
F_3 ( & V_27 -> V_8 -> V_9 , 1 ) ;
#endif
F_3 ( & V_27 -> V_9 , 1 ) ;
#ifdef F_2
V_27 -> V_12 = V_29 ;
#endif
if ( F_38 ( V_27 , V_28 ) < 0 )
goto error;
return V_27 ;
error:
F_39 ( V_27 ) ;
return NULL ;
}
struct V_1 * F_40 ( void )
{
struct V_23 * V_26 = V_21 ;
const struct V_1 * V_30 ;
struct V_1 * V_27 ;
F_41 () ;
V_27 = F_42 ( V_20 , V_28 ) ;
if ( ! V_27 )
return NULL ;
F_18 ( L_7 , V_27 ) ;
V_30 = V_26 -> V_1 ;
memcpy ( V_27 , V_30 , sizeof( struct V_1 ) ) ;
F_3 ( & V_27 -> V_9 , 1 ) ;
F_1 ( V_27 , 0 ) ;
F_43 ( V_27 -> V_17 ) ;
F_44 ( V_27 -> V_18 ) ;
F_45 ( V_27 -> V_19 ) ;
#ifdef F_14
F_46 ( V_27 -> V_15 ) ;
F_46 ( V_27 -> V_16 ) ;
F_47 ( & V_27 -> V_8 -> V_9 ) ;
#endif
#ifdef F_48
V_27 -> V_31 = NULL ;
#endif
if ( F_49 ( V_27 , V_30 , V_28 ) < 0 )
goto error;
F_28 ( V_27 ) ;
return V_27 ;
error:
F_39 ( V_27 ) ;
return NULL ;
}
struct V_1 * F_50 ( void )
{
struct V_7 * V_8 = NULL ;
struct V_1 * V_27 ;
#ifdef F_14
V_8 = F_51 ( sizeof( * V_8 ) , V_28 ) ;
if ( ! V_8 )
return NULL ;
#endif
V_27 = F_40 () ;
if ( ! V_27 ) {
F_12 ( V_8 ) ;
return V_27 ;
}
#ifdef F_14
F_11 ( V_27 -> V_15 ) ;
V_27 -> V_15 = NULL ;
memcpy ( V_8 , V_27 -> V_8 , sizeof( struct V_7 ) ) ;
F_3 ( & V_8 -> V_9 , 1 ) ;
F_52 ( & V_8 -> V_32 ) ;
F_46 ( V_8 -> V_10 ) ;
V_8 -> V_11 = NULL ;
F_13 ( V_27 ) ;
V_27 -> V_8 = V_8 ;
#endif
return V_27 ;
}
int F_53 ( struct V_23 * V_33 , unsigned long V_34 )
{
#ifdef F_14
struct V_7 * V_8 ;
#endif
struct V_1 * V_27 ;
int V_35 ;
if (
#ifdef F_14
! V_33 -> V_1 -> V_15 &&
#endif
V_34 & V_36
) {
V_33 -> V_22 = F_54 ( V_33 -> V_1 ) ;
F_54 ( V_33 -> V_1 ) ;
F_6 ( V_33 -> V_1 , 2 ) ;
F_18 ( L_8 ,
V_33 -> V_1 , F_5 ( & V_33 -> V_1 -> V_9 ) ,
F_4 ( V_33 -> V_1 ) ) ;
F_47 ( & V_33 -> V_1 -> V_18 -> V_37 ) ;
return 0 ;
}
V_27 = F_40 () ;
if ( ! V_27 )
return - V_38 ;
if ( V_34 & V_39 ) {
V_35 = F_55 ( V_27 ) ;
if ( V_35 < 0 )
goto V_40;
}
#ifdef F_14
if ( V_27 -> V_15 ) {
F_11 ( V_27 -> V_15 ) ;
V_27 -> V_15 = NULL ;
if ( V_34 & V_36 )
F_56 ( V_27 ) ;
}
if ( ! ( V_34 & V_36 ) ) {
V_8 = F_51 ( sizeof( * V_8 ) , V_28 ) ;
if ( ! V_8 ) {
V_35 = - V_38 ;
goto V_40;
}
F_3 ( & V_8 -> V_9 , 1 ) ;
F_52 ( & V_8 -> V_32 ) ;
V_8 -> V_11 = NULL ;
V_8 -> V_10 = F_46 ( V_27 -> V_8 -> V_10 ) ;
F_13 ( V_27 ) ;
V_27 -> V_8 = V_8 ;
}
#endif
F_47 ( & V_27 -> V_18 -> V_37 ) ;
V_33 -> V_1 = V_33 -> V_22 = F_54 ( V_27 ) ;
F_6 ( V_27 , 2 ) ;
F_28 ( V_27 ) ;
return 0 ;
V_40:
F_29 ( V_27 ) ;
return V_35 ;
}
int F_57 ( struct V_1 * V_27 )
{
struct V_23 * V_26 = V_21 ;
const struct V_1 * V_30 = V_26 -> V_22 ;
F_18 ( L_9 , V_27 ,
F_5 ( & V_27 -> V_9 ) ,
F_4 ( V_27 ) ) ;
F_10 ( V_26 -> V_1 != V_30 ) ;
#ifdef F_2
F_10 ( F_4 ( V_30 ) < 2 ) ;
F_28 ( V_30 ) ;
F_28 ( V_27 ) ;
#endif
F_10 ( F_5 ( & V_27 -> V_9 ) < 1 ) ;
F_54 ( V_27 ) ;
if ( ! F_58 ( V_30 -> V_41 , V_27 -> V_41 ) ||
! F_59 ( V_30 -> V_42 , V_27 -> V_42 ) ||
! F_58 ( V_30 -> V_43 , V_27 -> V_43 ) ||
! F_59 ( V_30 -> V_44 , V_27 -> V_44 ) ||
! F_60 ( V_27 -> V_45 , V_30 -> V_45 ) ) {
if ( V_26 -> V_46 )
F_61 ( V_26 -> V_46 , V_47 ) ;
V_26 -> V_48 = 0 ;
F_62 () ;
}
if ( ! F_58 ( V_27 -> V_43 , V_30 -> V_43 ) )
F_63 ( V_26 ) ;
if ( ! F_59 ( V_27 -> V_44 , V_30 -> V_44 ) )
F_64 ( V_26 ) ;
F_6 ( V_27 , 2 ) ;
if ( V_27 -> V_18 != V_30 -> V_18 )
F_47 ( & V_27 -> V_18 -> V_37 ) ;
F_65 ( V_26 -> V_22 , V_27 ) ;
F_65 ( V_26 -> V_1 , V_27 ) ;
if ( V_27 -> V_18 != V_30 -> V_18 )
F_66 ( & V_30 -> V_18 -> V_37 ) ;
F_6 ( V_30 , - 2 ) ;
if ( ! F_58 ( V_27 -> V_49 , V_30 -> V_49 ) ||
! F_58 ( V_27 -> V_41 , V_30 -> V_41 ) ||
! F_58 ( V_27 -> V_50 , V_30 -> V_50 ) ||
! F_58 ( V_27 -> V_43 , V_30 -> V_43 ) )
F_67 ( V_26 , V_51 ) ;
if ( ! F_59 ( V_27 -> V_52 , V_30 -> V_52 ) ||
! F_59 ( V_27 -> V_42 , V_30 -> V_42 ) ||
! F_59 ( V_27 -> V_53 , V_30 -> V_53 ) ||
! F_59 ( V_27 -> V_44 , V_30 -> V_44 ) )
F_67 ( V_26 , V_54 ) ;
F_29 ( V_30 ) ;
F_29 ( V_30 ) ;
return 0 ;
}
void F_39 ( struct V_1 * V_27 )
{
F_18 ( L_10 , V_27 ,
F_5 ( & V_27 -> V_9 ) ,
F_4 ( V_27 ) ) ;
#ifdef F_2
F_10 ( F_4 ( V_27 ) != 0 ) ;
#endif
F_10 ( F_5 ( & V_27 -> V_9 ) < 1 ) ;
F_29 ( V_27 ) ;
}
const struct V_1 * F_68 ( const struct V_1 * V_27 )
{
const struct V_1 * V_30 = V_21 -> V_1 ;
F_18 ( L_11 , V_27 ,
F_5 ( & V_27 -> V_9 ) ,
F_4 ( V_27 ) ) ;
F_28 ( V_30 ) ;
F_28 ( V_27 ) ;
F_54 ( V_27 ) ;
F_6 ( V_27 , 1 ) ;
F_65 ( V_21 -> V_1 , V_27 ) ;
F_6 ( V_30 , - 1 ) ;
F_18 ( L_12 , V_30 ,
F_5 ( & V_30 -> V_9 ) ,
F_4 ( V_30 ) ) ;
return V_30 ;
}
void F_69 ( const struct V_1 * V_30 )
{
const struct V_1 * V_55 = V_21 -> V_1 ;
F_18 ( L_13 , V_30 ,
F_5 ( & V_30 -> V_9 ) ,
F_4 ( V_30 ) ) ;
F_28 ( V_30 ) ;
F_28 ( V_55 ) ;
F_6 ( V_30 , 1 ) ;
F_65 ( V_21 -> V_1 , V_30 ) ;
F_6 ( V_55 , - 1 ) ;
F_29 ( V_55 ) ;
}
void T_1 F_70 ( void )
{
V_20 = F_71 ( L_14 , sizeof( struct V_1 ) ,
0 , V_56 | V_57 , NULL ) ;
}
struct V_1 * F_72 ( struct V_23 * V_58 )
{
#ifdef F_14
struct V_7 * V_8 ;
#endif
const struct V_1 * V_30 ;
struct V_1 * V_27 ;
V_27 = F_42 ( V_20 , V_28 ) ;
if ( ! V_27 )
return NULL ;
#ifdef F_14
V_8 = F_51 ( sizeof( * V_8 ) , V_28 ) ;
if ( ! V_8 ) {
F_24 ( V_20 , V_27 ) ;
return NULL ;
}
#endif
F_18 ( L_15 , V_27 ) ;
if ( V_58 )
V_30 = F_30 ( V_58 ) ;
else
V_30 = F_54 ( & V_59 ) ;
F_28 ( V_30 ) ;
* V_27 = * V_30 ;
F_3 ( & V_27 -> V_9 , 1 ) ;
F_1 ( V_27 , 0 ) ;
F_44 ( V_27 -> V_18 ) ;
F_45 ( V_27 -> V_19 ) ;
F_43 ( V_27 -> V_17 ) ;
#ifdef F_14
F_3 ( & V_8 -> V_9 , 1 ) ;
F_52 ( & V_8 -> V_32 ) ;
V_8 -> V_11 = NULL ;
V_8 -> V_10 = NULL ;
V_27 -> V_8 = V_8 ;
V_27 -> V_16 = NULL ;
V_27 -> V_15 = NULL ;
V_27 -> V_60 = V_61 ;
#endif
#ifdef F_48
V_27 -> V_31 = NULL ;
#endif
if ( F_49 ( V_27 , V_30 , V_28 ) < 0 )
goto error;
F_29 ( V_30 ) ;
F_28 ( V_27 ) ;
return V_27 ;
error:
F_29 ( V_27 ) ;
F_29 ( V_30 ) ;
return NULL ;
}
int F_73 ( struct V_1 * V_27 , T_2 V_62 )
{
return F_74 ( V_27 , V_62 ) ;
}
int F_75 ( struct V_1 * V_27 , const char * V_63 )
{
T_2 V_62 ;
int V_35 ;
V_35 = F_76 ( V_63 , strlen ( V_63 ) , & V_62 ) ;
if ( V_35 < 0 )
return V_35 ;
return F_73 ( V_27 , V_62 ) ;
}
int F_77 ( struct V_1 * V_27 , struct V_64 * V_64 )
{
V_27 -> V_43 = V_64 -> V_65 ;
V_27 -> V_44 = V_64 -> V_66 ;
return F_78 ( V_27 , V_64 ) ;
}
bool F_79 ( const struct V_1 * V_1 )
{
if ( V_1 -> V_12 != V_29 )
return true ;
#ifdef F_80
if ( F_81 () && V_1 -> V_31 ) {
if ( ( unsigned long ) V_1 -> V_31 < V_67 )
return true ;
if ( ( * ( T_2 * ) V_1 -> V_31 & 0xffffff00 ) ==
( V_68 << 24 | V_68 << 16 | V_68 << 8 ) )
return true ;
}
#endif
return false ;
}
static void F_82 ( const struct V_1 * V_1 , const char * V_69 ,
const struct V_23 * V_24 )
{
F_83 ( V_70 L_16 ,
V_69 , V_1 ,
V_1 == & V_59 ? L_17 : L_18 ,
V_1 == V_24 -> V_22 ? L_19 : L_18 ,
V_1 == V_24 -> V_1 ? L_20 : L_18 ) ;
F_83 ( V_70 L_21 ,
V_1 -> V_12 , V_1 -> V_14 ) ;
F_83 ( V_70 L_22 ,
F_5 ( & V_1 -> V_9 ) ,
F_4 ( V_1 ) ) ;
F_83 ( V_70 L_23 ,
F_84 ( & V_71 , V_1 -> V_49 ) ,
F_84 ( & V_71 , V_1 -> V_41 ) ,
F_84 ( & V_71 , V_1 -> V_50 ) ,
F_84 ( & V_71 , V_1 -> V_43 ) ) ;
F_83 ( V_70 L_24 ,
F_85 ( & V_71 , V_1 -> V_52 ) ,
F_85 ( & V_71 , V_1 -> V_42 ) ,
F_85 ( & V_71 , V_1 -> V_53 ) ,
F_85 ( & V_71 , V_1 -> V_44 ) ) ;
#ifdef F_48
F_83 ( V_70 L_25 , V_1 -> V_31 ) ;
if ( ( unsigned long ) V_1 -> V_31 >= V_67 &&
( ( ( unsigned long ) V_1 -> V_31 & 0xffffff00 ) !=
( V_68 << 24 | V_68 << 16 | V_68 << 8 ) ) )
F_83 ( V_70 L_26 ,
( ( T_2 * ) V_1 -> V_31 ) [ 0 ] ,
( ( T_2 * ) V_1 -> V_31 ) [ 1 ] ) ;
#endif
}
void F_86 ( const struct V_1 * V_1 , const char * V_72 , unsigned line )
{
F_83 ( V_70 L_27 ) ;
F_83 ( V_70 L_28 , V_72 , line ) ;
F_82 ( V_1 , L_29 , V_21 ) ;
F_87 () ;
}
void F_88 ( struct V_23 * V_24 ,
const char * V_72 , unsigned line )
{
if ( V_24 -> V_1 == V_24 -> V_22 ) {
if ( F_89 ( F_4 ( V_24 -> V_1 ) < 2 ||
F_79 ( V_24 -> V_1 ) ) )
goto V_73;
} else {
if ( F_89 ( F_4 ( V_24 -> V_22 ) < 1 ||
F_4 ( V_24 -> V_1 ) < 1 ||
F_79 ( V_24 -> V_22 ) ||
F_79 ( V_24 -> V_1 ) ) )
goto V_73;
}
return;
V_73:
F_83 ( V_70 L_30 ) ;
F_83 ( V_70 L_28 , V_72 , line ) ;
F_82 ( V_24 -> V_22 , L_31 , V_24 ) ;
if ( V_24 -> V_1 != V_24 -> V_22 )
F_82 ( V_24 -> V_1 , L_32 , V_24 ) ;
else
F_83 ( V_70 L_33 ) ;
F_87 () ;
}
void F_90 ( struct V_23 * V_24 )
{
F_18 ( L_34 ,
V_24 -> V_22 , V_24 -> V_1 ,
F_5 ( & V_24 -> V_1 -> V_9 ) ,
F_4 ( V_24 -> V_1 ) ) ;
F_88 ( V_24 , __FILE__ , __LINE__ ) ;
}
