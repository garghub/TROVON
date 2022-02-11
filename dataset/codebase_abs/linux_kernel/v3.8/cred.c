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
struct V_1 * V_1 = F_9 ( V_6 , struct V_1 , V_6 ) ;
F_10 ( L_1 , V_1 ) ;
#ifdef F_2
if ( V_1 -> V_7 != V_8 ||
F_5 ( & V_1 -> V_9 ) != 0 ||
F_4 ( V_1 ) != 0 )
F_11 ( L_2
L_3 ,
V_1 , V_1 -> V_7 , V_1 -> V_10 ,
F_5 ( & V_1 -> V_9 ) ,
F_4 ( V_1 ) ) ;
#else
if ( F_5 ( & V_1 -> V_9 ) != 0 )
F_11 ( L_4 ,
V_1 , F_5 ( & V_1 -> V_9 ) ) ;
#endif
F_12 ( V_1 ) ;
F_13 ( V_1 -> V_11 ) ;
F_13 ( V_1 -> V_12 ) ;
F_13 ( V_1 -> V_13 ) ;
F_13 ( V_1 -> V_14 ) ;
if ( V_1 -> V_15 )
F_14 ( V_1 -> V_15 ) ;
F_15 ( V_1 -> V_16 ) ;
F_16 ( V_1 -> V_17 ) ;
F_17 ( V_18 , V_1 ) ;
}
void F_18 ( struct V_1 * V_1 )
{
F_10 ( L_5 , V_1 ,
F_5 ( & V_1 -> V_9 ) ,
F_4 ( V_1 ) ) ;
F_19 ( F_5 ( & V_1 -> V_9 ) != 0 ) ;
#ifdef F_2
F_19 ( F_4 ( V_1 ) != 0 ) ;
V_1 -> V_7 = V_8 ;
V_1 -> V_10 = F_20 ( 0 ) ;
#endif
F_19 ( V_1 == V_19 -> V_1 ) ;
F_19 ( V_1 == V_19 -> V_20 ) ;
F_21 ( & V_1 -> V_6 , F_8 ) ;
}
void F_22 ( struct V_21 * V_22 )
{
struct V_1 * V_1 ;
F_10 ( L_6 , V_22 -> V_23 , V_22 -> V_20 , V_22 -> V_1 ,
F_5 ( & V_22 -> V_1 -> V_9 ) ,
F_4 ( V_22 -> V_1 ) ) ;
V_1 = (struct V_1 * ) V_22 -> V_20 ;
V_22 -> V_20 = NULL ;
F_23 ( V_1 ) ;
F_6 ( V_1 , - 1 ) ;
F_24 ( V_1 ) ;
V_1 = (struct V_1 * ) V_22 -> V_1 ;
V_22 -> V_1 = NULL ;
F_23 ( V_1 ) ;
F_6 ( V_1 , - 1 ) ;
F_24 ( V_1 ) ;
}
const struct V_1 * F_25 ( struct V_21 * V_24 )
{
const struct V_1 * V_1 ;
F_26 () ;
do {
V_1 = F_27 ( ( V_24 ) ) ;
F_19 ( ! V_1 ) ;
} while ( ! F_28 ( & ( (struct V_1 * ) V_1 ) -> V_9 ) );
F_29 () ;
return V_1 ;
}
struct V_1 * F_30 ( void )
{
struct V_1 * V_25 ;
V_25 = F_31 ( V_18 , V_26 ) ;
if ( ! V_25 )
return NULL ;
F_3 ( & V_25 -> V_9 , 1 ) ;
#ifdef F_2
V_25 -> V_7 = V_27 ;
#endif
if ( F_32 ( V_25 , V_26 ) < 0 )
goto error;
return V_25 ;
error:
F_33 ( V_25 ) ;
return NULL ;
}
struct V_1 * F_34 ( void )
{
struct V_21 * V_24 = V_19 ;
const struct V_1 * V_28 ;
struct V_1 * V_25 ;
F_35 () ;
V_25 = F_36 ( V_18 , V_26 ) ;
if ( ! V_25 )
return NULL ;
F_10 ( L_7 , V_25 ) ;
V_28 = V_24 -> V_1 ;
memcpy ( V_25 , V_28 , sizeof( struct V_1 ) ) ;
F_3 ( & V_25 -> V_9 , 1 ) ;
F_1 ( V_25 , 0 ) ;
F_37 ( V_25 -> V_15 ) ;
F_38 ( V_25 -> V_16 ) ;
F_39 ( V_25 -> V_17 ) ;
#ifdef F_40
F_41 ( V_25 -> V_11 ) ;
F_41 ( V_25 -> V_12 ) ;
F_41 ( V_25 -> V_13 ) ;
F_41 ( V_25 -> V_14 ) ;
#endif
#ifdef F_42
V_25 -> V_29 = NULL ;
#endif
if ( F_43 ( V_25 , V_28 , V_26 ) < 0 )
goto error;
F_23 ( V_25 ) ;
return V_25 ;
error:
F_33 ( V_25 ) ;
return NULL ;
}
struct V_1 * F_44 ( void )
{
struct V_1 * V_25 ;
V_25 = F_34 () ;
if ( ! V_25 )
return V_25 ;
#ifdef F_40
F_13 ( V_25 -> V_13 ) ;
V_25 -> V_13 = NULL ;
F_13 ( V_25 -> V_12 ) ;
V_25 -> V_12 = NULL ;
#endif
return V_25 ;
}
int F_45 ( struct V_21 * V_30 , unsigned long V_31 )
{
struct V_1 * V_25 ;
int V_32 ;
if (
#ifdef F_40
! V_30 -> V_1 -> V_13 &&
#endif
V_31 & V_33
) {
V_30 -> V_20 = F_46 ( V_30 -> V_1 ) ;
F_46 ( V_30 -> V_1 ) ;
F_6 ( V_30 -> V_1 , 2 ) ;
F_10 ( L_8 ,
V_30 -> V_1 , F_5 ( & V_30 -> V_1 -> V_9 ) ,
F_4 ( V_30 -> V_1 ) ) ;
F_47 ( & V_30 -> V_1 -> V_16 -> V_34 ) ;
return 0 ;
}
V_25 = F_34 () ;
if ( ! V_25 )
return - V_35 ;
if ( V_31 & V_36 ) {
V_32 = F_48 ( V_25 ) ;
if ( V_32 < 0 )
goto V_37;
}
#ifdef F_40
if ( V_25 -> V_13 ) {
F_13 ( V_25 -> V_13 ) ;
V_25 -> V_13 = NULL ;
if ( V_31 & V_33 )
F_49 ( V_25 ) ;
}
if ( ! ( V_31 & V_33 ) ) {
F_13 ( V_25 -> V_12 ) ;
V_25 -> V_12 = NULL ;
}
#endif
F_47 ( & V_25 -> V_16 -> V_34 ) ;
V_30 -> V_1 = V_30 -> V_20 = F_46 ( V_25 ) ;
F_6 ( V_25 , 2 ) ;
F_23 ( V_25 ) ;
return 0 ;
V_37:
F_24 ( V_25 ) ;
return V_32 ;
}
static bool F_50 ( const struct V_1 * V_38 , const struct V_1 * V_39 )
{
const struct V_40 * V_41 = V_38 -> V_17 ;
const struct V_40 * V_42 = V_39 -> V_17 ;
if ( V_41 == V_42 )
return F_51 ( V_39 -> V_43 , V_38 -> V_43 ) ;
for (; V_42 != & V_44 ; V_42 = V_42 -> V_45 ) {
if ( ( V_41 == V_42 -> V_45 ) &&
F_52 ( V_42 -> V_46 , V_38 -> V_47 ) )
return true ;
}
return false ;
}
int F_53 ( struct V_1 * V_25 )
{
struct V_21 * V_24 = V_19 ;
const struct V_1 * V_28 = V_24 -> V_20 ;
F_10 ( L_9 , V_25 ,
F_5 ( & V_25 -> V_9 ) ,
F_4 ( V_25 ) ) ;
F_19 ( V_24 -> V_1 != V_28 ) ;
#ifdef F_2
F_19 ( F_4 ( V_28 ) < 2 ) ;
F_23 ( V_28 ) ;
F_23 ( V_25 ) ;
#endif
F_19 ( F_5 ( & V_25 -> V_9 ) < 1 ) ;
F_46 ( V_25 ) ;
if ( ! F_52 ( V_28 -> V_47 , V_25 -> V_47 ) ||
! F_54 ( V_28 -> V_48 , V_25 -> V_48 ) ||
! F_52 ( V_28 -> V_49 , V_25 -> V_49 ) ||
! F_54 ( V_28 -> V_50 , V_25 -> V_50 ) ||
! F_50 ( V_28 , V_25 ) ) {
if ( V_24 -> V_51 )
F_55 ( V_24 -> V_51 , V_52 ) ;
V_24 -> V_53 = 0 ;
F_56 () ;
}
if ( ! F_52 ( V_25 -> V_49 , V_28 -> V_49 ) )
F_57 ( V_24 ) ;
if ( ! F_54 ( V_25 -> V_50 , V_28 -> V_50 ) )
F_58 ( V_24 ) ;
F_6 ( V_25 , 2 ) ;
if ( V_25 -> V_16 != V_28 -> V_16 )
F_47 ( & V_25 -> V_16 -> V_34 ) ;
F_59 ( V_24 -> V_20 , V_25 ) ;
F_59 ( V_24 -> V_1 , V_25 ) ;
if ( V_25 -> V_16 != V_28 -> V_16 )
F_60 ( & V_28 -> V_16 -> V_34 ) ;
F_6 ( V_28 , - 2 ) ;
if ( ! F_52 ( V_25 -> V_54 , V_28 -> V_54 ) ||
! F_52 ( V_25 -> V_47 , V_28 -> V_47 ) ||
! F_52 ( V_25 -> V_55 , V_28 -> V_55 ) ||
! F_52 ( V_25 -> V_49 , V_28 -> V_49 ) )
F_61 ( V_24 , V_56 ) ;
if ( ! F_54 ( V_25 -> V_57 , V_28 -> V_57 ) ||
! F_54 ( V_25 -> V_48 , V_28 -> V_48 ) ||
! F_54 ( V_25 -> V_58 , V_28 -> V_58 ) ||
! F_54 ( V_25 -> V_50 , V_28 -> V_50 ) )
F_61 ( V_24 , V_59 ) ;
F_24 ( V_28 ) ;
F_24 ( V_28 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_25 )
{
F_10 ( L_10 , V_25 ,
F_5 ( & V_25 -> V_9 ) ,
F_4 ( V_25 ) ) ;
#ifdef F_2
F_19 ( F_4 ( V_25 ) != 0 ) ;
#endif
F_19 ( F_5 ( & V_25 -> V_9 ) < 1 ) ;
F_24 ( V_25 ) ;
}
const struct V_1 * F_62 ( const struct V_1 * V_25 )
{
const struct V_1 * V_28 = V_19 -> V_1 ;
F_10 ( L_11 , V_25 ,
F_5 ( & V_25 -> V_9 ) ,
F_4 ( V_25 ) ) ;
F_23 ( V_28 ) ;
F_23 ( V_25 ) ;
F_46 ( V_25 ) ;
F_6 ( V_25 , 1 ) ;
F_59 ( V_19 -> V_1 , V_25 ) ;
F_6 ( V_28 , - 1 ) ;
F_10 ( L_12 , V_28 ,
F_5 ( & V_28 -> V_9 ) ,
F_4 ( V_28 ) ) ;
return V_28 ;
}
void F_63 ( const struct V_1 * V_28 )
{
const struct V_1 * V_60 = V_19 -> V_1 ;
F_10 ( L_13 , V_28 ,
F_5 ( & V_28 -> V_9 ) ,
F_4 ( V_28 ) ) ;
F_23 ( V_28 ) ;
F_23 ( V_60 ) ;
F_6 ( V_28 , 1 ) ;
F_59 ( V_19 -> V_1 , V_28 ) ;
F_6 ( V_60 , - 1 ) ;
F_24 ( V_60 ) ;
}
void T_1 F_64 ( void )
{
V_18 = F_65 ( L_14 , sizeof( struct V_1 ) ,
0 , V_61 | V_62 , NULL ) ;
}
struct V_1 * F_66 ( struct V_21 * V_63 )
{
const struct V_1 * V_28 ;
struct V_1 * V_25 ;
V_25 = F_36 ( V_18 , V_26 ) ;
if ( ! V_25 )
return NULL ;
F_10 ( L_15 , V_25 ) ;
if ( V_63 )
V_28 = F_25 ( V_63 ) ;
else
V_28 = F_46 ( & V_64 ) ;
F_23 ( V_28 ) ;
* V_25 = * V_28 ;
F_3 ( & V_25 -> V_9 , 1 ) ;
F_1 ( V_25 , 0 ) ;
F_38 ( V_25 -> V_16 ) ;
F_39 ( V_25 -> V_17 ) ;
F_37 ( V_25 -> V_15 ) ;
#ifdef F_40
V_25 -> V_11 = NULL ;
V_25 -> V_12 = NULL ;
V_25 -> V_13 = NULL ;
V_25 -> V_14 = NULL ;
V_25 -> V_65 = V_66 ;
#endif
#ifdef F_42
V_25 -> V_29 = NULL ;
#endif
if ( F_43 ( V_25 , V_28 , V_26 ) < 0 )
goto error;
F_24 ( V_28 ) ;
F_23 ( V_25 ) ;
return V_25 ;
error:
F_24 ( V_25 ) ;
F_24 ( V_28 ) ;
return NULL ;
}
int F_67 ( struct V_1 * V_25 , T_2 V_67 )
{
return F_68 ( V_25 , V_67 ) ;
}
int F_69 ( struct V_1 * V_25 , const char * V_68 )
{
T_2 V_67 ;
int V_32 ;
V_32 = F_70 ( V_68 , strlen ( V_68 ) , & V_67 ) ;
if ( V_32 < 0 )
return V_32 ;
return F_67 ( V_25 , V_67 ) ;
}
int F_71 ( struct V_1 * V_25 , struct V_69 * V_69 )
{
V_25 -> V_49 = V_69 -> V_70 ;
V_25 -> V_50 = V_69 -> V_71 ;
return F_72 ( V_25 , V_69 ) ;
}
bool F_73 ( const struct V_1 * V_1 )
{
if ( V_1 -> V_7 != V_27 )
return true ;
#ifdef F_74
if ( F_75 () && V_1 -> V_29 ) {
if ( ( unsigned long ) V_1 -> V_29 < V_72 )
return true ;
if ( ( * ( T_2 * ) V_1 -> V_29 & 0xffffff00 ) ==
( V_73 << 24 | V_73 << 16 | V_73 << 8 ) )
return true ;
}
#endif
return false ;
}
static void F_76 ( const struct V_1 * V_1 , const char * V_74 ,
const struct V_21 * V_22 )
{
F_77 ( V_75 L_16 ,
V_74 , V_1 ,
V_1 == & V_64 ? L_17 : L_18 ,
V_1 == V_22 -> V_20 ? L_19 : L_18 ,
V_1 == V_22 -> V_1 ? L_20 : L_18 ) ;
F_77 ( V_75 L_21 ,
V_1 -> V_7 , V_1 -> V_10 ) ;
F_77 ( V_75 L_22 ,
F_5 ( & V_1 -> V_9 ) ,
F_4 ( V_1 ) ) ;
F_77 ( V_75 L_23 ,
F_78 ( & V_44 , V_1 -> V_54 ) ,
F_78 ( & V_44 , V_1 -> V_47 ) ,
F_78 ( & V_44 , V_1 -> V_55 ) ,
F_78 ( & V_44 , V_1 -> V_49 ) ) ;
F_77 ( V_75 L_24 ,
F_79 ( & V_44 , V_1 -> V_57 ) ,
F_79 ( & V_44 , V_1 -> V_48 ) ,
F_79 ( & V_44 , V_1 -> V_58 ) ,
F_79 ( & V_44 , V_1 -> V_50 ) ) ;
#ifdef F_42
F_77 ( V_75 L_25 , V_1 -> V_29 ) ;
if ( ( unsigned long ) V_1 -> V_29 >= V_72 &&
( ( ( unsigned long ) V_1 -> V_29 & 0xffffff00 ) !=
( V_73 << 24 | V_73 << 16 | V_73 << 8 ) ) )
F_77 ( V_75 L_26 ,
( ( T_2 * ) V_1 -> V_29 ) [ 0 ] ,
( ( T_2 * ) V_1 -> V_29 ) [ 1 ] ) ;
#endif
}
void F_80 ( const struct V_1 * V_1 , const char * V_76 , unsigned line )
{
F_77 ( V_75 L_27 ) ;
F_77 ( V_75 L_28 , V_76 , line ) ;
F_76 ( V_1 , L_29 , V_19 ) ;
F_81 () ;
}
void F_82 ( struct V_21 * V_22 ,
const char * V_76 , unsigned line )
{
if ( V_22 -> V_1 == V_22 -> V_20 ) {
if ( F_83 ( F_4 ( V_22 -> V_1 ) < 2 ||
F_73 ( V_22 -> V_1 ) ) )
goto V_77;
} else {
if ( F_83 ( F_4 ( V_22 -> V_20 ) < 1 ||
F_4 ( V_22 -> V_1 ) < 1 ||
F_73 ( V_22 -> V_20 ) ||
F_73 ( V_22 -> V_1 ) ) )
goto V_77;
}
return;
V_77:
F_77 ( V_75 L_30 ) ;
F_77 ( V_75 L_28 , V_76 , line ) ;
F_76 ( V_22 -> V_20 , L_31 , V_22 ) ;
if ( V_22 -> V_1 != V_22 -> V_20 )
F_76 ( V_22 -> V_1 , L_32 , V_22 ) ;
else
F_77 ( V_75 L_33 ) ;
F_81 () ;
}
void F_84 ( struct V_21 * V_22 )
{
F_10 ( L_34 ,
V_22 -> V_20 , V_22 -> V_1 ,
F_5 ( & V_22 -> V_1 -> V_9 ) ,
F_4 ( V_22 -> V_1 ) ) ;
F_82 ( V_22 , __FILE__ , __LINE__ ) ;
}
