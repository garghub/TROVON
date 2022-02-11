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
F_23 ( V_19 , V_1 ) ;
}
void F_24 ( struct V_1 * V_1 )
{
F_18 ( L_5 , V_1 ,
F_5 ( & V_1 -> V_9 ) ,
F_4 ( V_1 ) ) ;
F_10 ( F_5 ( & V_1 -> V_9 ) != 0 ) ;
#ifdef F_2
F_10 ( F_4 ( V_1 ) != 0 ) ;
V_1 -> V_12 = V_13 ;
V_1 -> V_14 = F_25 ( 0 ) ;
#endif
F_10 ( V_1 == V_20 -> V_1 ) ;
F_10 ( V_1 == V_20 -> V_21 ) ;
F_16 ( & V_1 -> V_6 , F_17 ) ;
}
void F_26 ( struct V_22 * V_23 )
{
struct V_1 * V_1 ;
F_18 ( L_6 , V_23 -> V_24 , V_23 -> V_21 , V_23 -> V_1 ,
F_5 ( & V_23 -> V_1 -> V_9 ) ,
F_4 ( V_23 -> V_1 ) ) ;
V_1 = (struct V_1 * ) V_23 -> V_21 ;
V_23 -> V_21 = NULL ;
F_27 ( V_1 ) ;
F_6 ( V_1 , - 1 ) ;
F_28 ( V_1 ) ;
V_1 = (struct V_1 * ) V_23 -> V_1 ;
V_23 -> V_1 = NULL ;
F_27 ( V_1 ) ;
F_6 ( V_1 , - 1 ) ;
F_28 ( V_1 ) ;
V_1 = (struct V_1 * ) V_23 -> V_25 ;
if ( V_1 ) {
V_23 -> V_25 = NULL ;
F_27 ( V_1 ) ;
F_28 ( V_1 ) ;
}
}
const struct V_1 * F_29 ( struct V_22 * V_26 )
{
const struct V_1 * V_1 ;
F_30 () ;
do {
V_1 = F_31 ( ( V_26 ) ) ;
F_10 ( ! V_1 ) ;
} while ( ! F_32 ( & ( (struct V_1 * ) V_1 ) -> V_9 ) );
F_33 () ;
return V_1 ;
}
struct V_1 * F_34 ( void )
{
struct V_1 * V_27 ;
V_27 = F_35 ( V_19 , V_28 ) ;
if ( ! V_27 )
return NULL ;
#ifdef F_14
V_27 -> V_8 = F_36 ( sizeof( * V_27 -> V_8 ) , V_28 ) ;
if ( ! V_27 -> V_8 ) {
F_23 ( V_19 , V_27 ) ;
return NULL ;
}
F_3 ( & V_27 -> V_8 -> V_9 , 1 ) ;
#endif
F_3 ( & V_27 -> V_9 , 1 ) ;
#ifdef F_2
V_27 -> V_12 = V_29 ;
#endif
if ( F_37 ( V_27 , V_28 ) < 0 )
goto error;
return V_27 ;
error:
F_38 ( V_27 ) ;
return NULL ;
}
struct V_1 * F_39 ( void )
{
struct V_22 * V_26 = V_20 ;
const struct V_1 * V_30 ;
struct V_1 * V_27 ;
F_40 () ;
V_27 = F_41 ( V_19 , V_28 ) ;
if ( ! V_27 )
return NULL ;
F_18 ( L_7 , V_27 ) ;
V_30 = V_26 -> V_1 ;
memcpy ( V_27 , V_30 , sizeof( struct V_1 ) ) ;
F_3 ( & V_27 -> V_9 , 1 ) ;
F_1 ( V_27 , 0 ) ;
F_42 ( V_27 -> V_17 ) ;
F_43 ( V_27 -> V_18 ) ;
#ifdef F_14
F_44 ( V_27 -> V_15 ) ;
F_44 ( V_27 -> V_16 ) ;
F_45 ( & V_27 -> V_8 -> V_9 ) ;
#endif
#ifdef F_46
V_27 -> V_31 = NULL ;
#endif
if ( F_47 ( V_27 , V_30 , V_28 ) < 0 )
goto error;
F_27 ( V_27 ) ;
return V_27 ;
error:
F_38 ( V_27 ) ;
return NULL ;
}
struct V_1 * F_48 ( void )
{
struct V_7 * V_8 = NULL ;
struct V_1 * V_27 ;
#ifdef F_14
V_8 = F_49 ( sizeof( * V_8 ) , V_28 ) ;
if ( ! V_8 )
return NULL ;
#endif
V_27 = F_39 () ;
if ( ! V_27 ) {
F_12 ( V_8 ) ;
return V_27 ;
}
#ifdef F_14
F_11 ( V_27 -> V_15 ) ;
V_27 -> V_15 = NULL ;
memcpy ( V_8 , V_27 -> V_8 , sizeof( struct V_7 ) ) ;
F_3 ( & V_8 -> V_9 , 1 ) ;
F_50 ( & V_8 -> V_32 ) ;
F_44 ( V_8 -> V_10 ) ;
V_8 -> V_11 = NULL ;
F_13 ( V_27 ) ;
V_27 -> V_8 = V_8 ;
#endif
return V_27 ;
}
int F_51 ( struct V_22 * V_33 , unsigned long V_34 )
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
V_33 -> V_21 = F_52 ( V_33 -> V_1 ) ;
F_52 ( V_33 -> V_1 ) ;
F_6 ( V_33 -> V_1 , 2 ) ;
F_18 ( L_8 ,
V_33 -> V_1 , F_5 ( & V_33 -> V_1 -> V_9 ) ,
F_4 ( V_33 -> V_1 ) ) ;
F_45 ( & V_33 -> V_1 -> V_18 -> V_37 ) ;
return 0 ;
}
V_27 = F_39 () ;
if ( ! V_27 )
return - V_38 ;
if ( V_34 & V_39 ) {
V_35 = F_53 ( V_27 ) ;
if ( V_35 < 0 )
goto V_40;
}
V_27 -> V_41 = V_27 -> V_18 -> V_41 ;
#ifdef F_14
if ( V_27 -> V_15 ) {
F_11 ( V_27 -> V_15 ) ;
V_27 -> V_15 = NULL ;
if ( V_34 & V_36 )
F_54 ( V_27 ) ;
}
if ( ! ( V_34 & V_36 ) ) {
V_8 = F_49 ( sizeof( * V_8 ) , V_28 ) ;
if ( ! V_8 ) {
V_35 = - V_38 ;
goto V_40;
}
F_3 ( & V_8 -> V_9 , 1 ) ;
F_50 ( & V_8 -> V_32 ) ;
V_8 -> V_11 = NULL ;
V_8 -> V_10 = F_44 ( V_27 -> V_8 -> V_10 ) ;
F_13 ( V_27 ) ;
V_27 -> V_8 = V_8 ;
}
#endif
F_45 ( & V_27 -> V_18 -> V_37 ) ;
V_33 -> V_1 = V_33 -> V_21 = F_52 ( V_27 ) ;
F_6 ( V_27 , 2 ) ;
F_27 ( V_27 ) ;
return 0 ;
V_40:
F_28 ( V_27 ) ;
return V_35 ;
}
int F_55 ( struct V_1 * V_27 )
{
struct V_22 * V_26 = V_20 ;
const struct V_1 * V_30 = V_26 -> V_21 ;
F_18 ( L_9 , V_27 ,
F_5 ( & V_27 -> V_9 ) ,
F_4 ( V_27 ) ) ;
F_10 ( V_26 -> V_1 != V_30 ) ;
#ifdef F_2
F_10 ( F_4 ( V_30 ) < 2 ) ;
F_27 ( V_30 ) ;
F_27 ( V_27 ) ;
#endif
F_10 ( F_5 ( & V_27 -> V_9 ) < 1 ) ;
F_52 ( V_27 ) ;
if ( V_30 -> V_42 != V_27 -> V_42 ||
V_30 -> V_43 != V_27 -> V_43 ||
V_30 -> V_44 != V_27 -> V_44 ||
V_30 -> V_45 != V_27 -> V_45 ||
! F_56 ( V_27 -> V_46 , V_30 -> V_46 ) ) {
if ( V_26 -> V_47 )
F_57 ( V_26 -> V_47 , V_48 ) ;
V_26 -> V_49 = 0 ;
F_58 () ;
}
if ( V_27 -> V_44 != V_30 -> V_44 )
F_59 ( V_26 ) ;
if ( V_27 -> V_45 != V_30 -> V_45 )
F_60 ( V_26 ) ;
F_6 ( V_27 , 2 ) ;
if ( V_27 -> V_18 != V_30 -> V_18 )
F_45 ( & V_27 -> V_18 -> V_37 ) ;
F_61 ( V_26 -> V_21 , V_27 ) ;
F_61 ( V_26 -> V_1 , V_27 ) ;
if ( V_27 -> V_18 != V_30 -> V_18 )
F_62 ( & V_30 -> V_18 -> V_37 ) ;
F_6 ( V_30 , - 2 ) ;
if ( V_27 -> V_50 != V_30 -> V_50 ||
V_27 -> V_42 != V_30 -> V_42 ||
V_27 -> V_51 != V_30 -> V_51 ||
V_27 -> V_44 != V_30 -> V_44 )
F_63 ( V_26 , V_52 ) ;
if ( V_27 -> V_53 != V_30 -> V_53 ||
V_27 -> V_43 != V_30 -> V_43 ||
V_27 -> V_54 != V_30 -> V_54 ||
V_27 -> V_45 != V_30 -> V_45 )
F_63 ( V_26 , V_55 ) ;
F_28 ( V_30 ) ;
F_28 ( V_30 ) ;
return 0 ;
}
void F_38 ( struct V_1 * V_27 )
{
F_18 ( L_10 , V_27 ,
F_5 ( & V_27 -> V_9 ) ,
F_4 ( V_27 ) ) ;
#ifdef F_2
F_10 ( F_4 ( V_27 ) != 0 ) ;
#endif
F_10 ( F_5 ( & V_27 -> V_9 ) < 1 ) ;
F_28 ( V_27 ) ;
}
const struct V_1 * F_64 ( const struct V_1 * V_27 )
{
const struct V_1 * V_30 = V_20 -> V_1 ;
F_18 ( L_11 , V_27 ,
F_5 ( & V_27 -> V_9 ) ,
F_4 ( V_27 ) ) ;
F_27 ( V_30 ) ;
F_27 ( V_27 ) ;
F_52 ( V_27 ) ;
F_6 ( V_27 , 1 ) ;
F_61 ( V_20 -> V_1 , V_27 ) ;
F_6 ( V_30 , - 1 ) ;
F_18 ( L_12 , V_30 ,
F_5 ( & V_30 -> V_9 ) ,
F_4 ( V_30 ) ) ;
return V_30 ;
}
void F_65 ( const struct V_1 * V_30 )
{
const struct V_1 * V_56 = V_20 -> V_1 ;
F_18 ( L_13 , V_30 ,
F_5 ( & V_30 -> V_9 ) ,
F_4 ( V_30 ) ) ;
F_27 ( V_30 ) ;
F_27 ( V_56 ) ;
F_6 ( V_30 , 1 ) ;
F_61 ( V_20 -> V_1 , V_30 ) ;
F_6 ( V_56 , - 1 ) ;
F_28 ( V_56 ) ;
}
void T_1 F_66 ( void )
{
V_19 = F_67 ( L_14 , sizeof( struct V_1 ) ,
0 , V_57 | V_58 , NULL ) ;
}
struct V_1 * F_68 ( struct V_22 * V_59 )
{
const struct V_1 * V_30 ;
struct V_1 * V_27 ;
V_27 = F_41 ( V_19 , V_28 ) ;
if ( ! V_27 )
return NULL ;
F_18 ( L_15 , V_27 ) ;
if ( V_59 )
V_30 = F_29 ( V_59 ) ;
else
V_30 = F_52 ( & V_60 ) ;
F_27 ( V_30 ) ;
* V_27 = * V_30 ;
F_3 ( & V_27 -> V_9 , 1 ) ;
F_1 ( V_27 , 0 ) ;
F_43 ( V_27 -> V_18 ) ;
F_42 ( V_27 -> V_17 ) ;
#ifdef F_14
F_45 ( & V_61 . V_9 ) ;
V_27 -> V_8 = & V_61 ;
V_27 -> V_16 = NULL ;
V_27 -> V_15 = NULL ;
V_27 -> V_62 = V_63 ;
#endif
#ifdef F_46
V_27 -> V_31 = NULL ;
#endif
if ( F_47 ( V_27 , V_30 , V_28 ) < 0 )
goto error;
F_28 ( V_30 ) ;
F_27 ( V_27 ) ;
return V_27 ;
error:
F_28 ( V_27 ) ;
F_28 ( V_30 ) ;
return NULL ;
}
int F_69 ( struct V_1 * V_27 , T_2 V_64 )
{
return F_70 ( V_27 , V_64 ) ;
}
int F_71 ( struct V_1 * V_27 , const char * V_65 )
{
T_2 V_64 ;
int V_35 ;
V_35 = F_72 ( V_65 , strlen ( V_65 ) , & V_64 ) ;
if ( V_35 < 0 )
return V_35 ;
return F_69 ( V_27 , V_64 ) ;
}
int F_73 ( struct V_1 * V_27 , struct V_66 * V_66 )
{
V_27 -> V_44 = V_66 -> V_67 ;
V_27 -> V_45 = V_66 -> V_68 ;
return F_74 ( V_27 , V_66 ) ;
}
bool F_75 ( const struct V_1 * V_1 )
{
if ( V_1 -> V_12 != V_29 )
return true ;
#ifdef F_76
if ( F_77 () && V_1 -> V_31 ) {
if ( ( unsigned long ) V_1 -> V_31 < V_69 )
return true ;
if ( ( * ( T_2 * ) V_1 -> V_31 & 0xffffff00 ) ==
( V_70 << 24 | V_70 << 16 | V_70 << 8 ) )
return true ;
}
#endif
return false ;
}
static void F_78 ( const struct V_1 * V_1 , const char * V_71 ,
const struct V_22 * V_23 )
{
F_79 ( V_72 L_16 ,
V_71 , V_1 ,
V_1 == & V_60 ? L_17 : L_18 ,
V_1 == V_23 -> V_21 ? L_19 : L_18 ,
V_1 == V_23 -> V_1 ? L_20 : L_18 ) ;
F_79 ( V_72 L_21 ,
V_1 -> V_12 , V_1 -> V_14 ) ;
F_79 ( V_72 L_22 ,
F_5 ( & V_1 -> V_9 ) ,
F_4 ( V_1 ) ) ;
F_79 ( V_72 L_23 ,
V_1 -> V_50 , V_1 -> V_42 , V_1 -> V_51 , V_1 -> V_44 ) ;
F_79 ( V_72 L_24 ,
V_1 -> V_53 , V_1 -> V_43 , V_1 -> V_54 , V_1 -> V_45 ) ;
#ifdef F_46
F_79 ( V_72 L_25 , V_1 -> V_31 ) ;
if ( ( unsigned long ) V_1 -> V_31 >= V_69 &&
( ( ( unsigned long ) V_1 -> V_31 & 0xffffff00 ) !=
( V_70 << 24 | V_70 << 16 | V_70 << 8 ) ) )
F_79 ( V_72 L_26 ,
( ( T_2 * ) V_1 -> V_31 ) [ 0 ] ,
( ( T_2 * ) V_1 -> V_31 ) [ 1 ] ) ;
#endif
}
void F_80 ( const struct V_1 * V_1 , const char * V_73 , unsigned line )
{
F_79 ( V_72 L_27 ) ;
F_79 ( V_72 L_28 , V_73 , line ) ;
F_78 ( V_1 , L_29 , V_20 ) ;
F_81 () ;
}
void F_82 ( struct V_22 * V_23 ,
const char * V_73 , unsigned line )
{
if ( V_23 -> V_1 == V_23 -> V_21 ) {
if ( F_83 ( F_4 ( V_23 -> V_1 ) < 2 ||
F_75 ( V_23 -> V_1 ) ) )
goto V_74;
} else {
if ( F_83 ( F_4 ( V_23 -> V_21 ) < 1 ||
F_4 ( V_23 -> V_1 ) < 1 ||
F_75 ( V_23 -> V_21 ) ||
F_75 ( V_23 -> V_1 ) ) )
goto V_74;
}
return;
V_74:
F_79 ( V_72 L_30 ) ;
F_79 ( V_72 L_28 , V_73 , line ) ;
F_78 ( V_23 -> V_21 , L_31 , V_23 ) ;
if ( V_23 -> V_1 != V_23 -> V_21 )
F_78 ( V_23 -> V_1 , L_32 , V_23 ) ;
else
F_79 ( V_72 L_33 ) ;
F_81 () ;
}
void F_84 ( struct V_22 * V_23 )
{
F_18 ( L_34 ,
V_23 -> V_21 , V_23 -> V_1 ,
F_5 ( & V_23 -> V_1 -> V_9 ) ,
F_4 ( V_23 -> V_1 ) ) ;
F_82 ( V_23 , __FILE__ , __LINE__ ) ;
}
