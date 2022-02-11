static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 = ( unsigned long ) V_4 ;
if ( F_2 ( V_2 ) )
V_5 |= V_6 ;
V_2 -> V_4 = (struct V_3 * ) V_5 ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_4 = (struct V_3 * )
( ( unsigned long ) V_2 -> V_4 & ~ V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
F_3 ( V_2 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
unsigned long V_4 , * V_7 = ( unsigned long * ) & V_2 -> V_4 ;
do {
V_4 = * V_7 ;
} while ( F_6 ( V_7 , V_4 , V_4 | V_6 ) != V_4 );
}
static inline void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_4 = (struct V_3 * )
( ( unsigned long ) V_2 -> V_4 | V_6 ) ;
}
int F_7 ( struct V_3 * V_8 )
{
if ( F_8 ( ! F_9 ( V_8 ) ) )
return V_8 -> V_9 ;
return F_10 ( F_11 ( V_8 ) -> V_10 . V_11 ,
V_8 -> V_9 ) ;
}
static void F_12 ( struct V_3 * V_8 )
{
int V_11 = F_7 ( V_8 ) ;
if ( V_8 -> V_11 != V_11 )
F_13 ( V_8 , V_11 ) ;
}
static void F_14 ( struct V_3 * V_8 )
{
unsigned long V_12 ;
F_15 ( & V_8 -> V_13 , V_12 ) ;
F_12 ( V_8 ) ;
F_16 ( & V_8 -> V_13 , V_12 ) ;
}
static int F_17 ( struct V_3 * V_8 ,
int V_14 ,
struct V_1 * V_15 ,
struct V_16 * V_17 ,
struct V_3 * V_18 )
{
struct V_1 * V_2 ;
struct V_16 * V_19 , * V_20 = V_17 ;
int V_21 , V_22 = 0 , V_23 = 0 ;
unsigned long V_12 ;
V_21 = F_18 ( V_17 ,
V_14 ) ;
V_24:
if ( ++ V_23 > V_25 ) {
static int V_26 ;
if ( V_26 != V_25 ) {
V_26 = V_25 ;
F_19 ( V_27 L_1
L_2 , V_25 ,
V_18 -> V_28 , F_20 ( V_18 ) ) ;
}
F_21 ( V_8 ) ;
return V_14 ? - V_29 : 0 ;
}
V_30:
F_15 ( & V_8 -> V_13 , V_12 ) ;
V_19 = V_8 -> V_31 ;
if ( ! V_19 )
goto V_32;
if ( V_17 && ! F_22 ( V_15 ) )
goto V_32;
if ( V_20 && ( ! F_9 ( V_8 ) ||
V_20 != F_11 ( V_8 ) ) )
goto V_32;
if ( ! V_21 && V_19 -> V_33 . V_11 == V_8 -> V_11 )
goto V_32;
V_2 = V_19 -> V_2 ;
if ( ! F_23 ( & V_2 -> V_34 ) ) {
F_16 ( & V_8 -> V_13 , V_12 ) ;
F_24 () ;
goto V_30;
}
if ( V_2 == V_15 || F_22 ( V_2 ) == V_18 ) {
F_25 ( V_14 , V_17 , V_2 ) ;
F_26 ( & V_2 -> V_34 ) ;
V_22 = V_14 ? - V_29 : 0 ;
goto V_32;
}
V_20 = F_27 ( V_2 ) ;
F_28 ( & V_19 -> V_33 , & V_2 -> V_35 ) ;
V_19 -> V_33 . V_11 = V_8 -> V_11 ;
F_29 ( & V_19 -> V_33 , & V_2 -> V_35 ) ;
F_16 ( & V_8 -> V_13 , V_12 ) ;
if ( ! F_22 ( V_2 ) ) {
if ( V_20 != F_27 ( V_2 ) )
F_30 ( F_27 ( V_2 ) -> V_8 ) ;
F_26 ( & V_2 -> V_34 ) ;
goto V_36;
}
F_21 ( V_8 ) ;
V_8 = F_22 ( V_2 ) ;
F_31 ( V_8 ) ;
F_15 ( & V_8 -> V_13 , V_12 ) ;
if ( V_19 == F_27 ( V_2 ) ) {
F_28 ( & V_20 -> V_10 , & V_8 -> V_37 ) ;
V_19 -> V_10 . V_11 = V_19 -> V_33 . V_11 ;
F_29 ( & V_19 -> V_10 , & V_8 -> V_37 ) ;
F_12 ( V_8 ) ;
} else if ( V_20 == V_19 ) {
F_28 ( & V_19 -> V_10 , & V_8 -> V_37 ) ;
V_19 = F_27 ( V_2 ) ;
V_19 -> V_10 . V_11 = V_19 -> V_33 . V_11 ;
F_29 ( & V_19 -> V_10 , & V_8 -> V_37 ) ;
F_12 ( V_8 ) ;
}
F_16 ( & V_8 -> V_13 , V_12 ) ;
V_20 = F_27 ( V_2 ) ;
F_26 ( & V_2 -> V_34 ) ;
if ( ! V_21 && V_19 != V_20 )
goto V_36;
goto V_24;
V_32:
F_16 ( & V_8 -> V_13 , V_12 ) ;
V_36:
F_21 ( V_8 ) ;
return V_22 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_3 * V_8 ,
struct V_16 * V_19 )
{
F_5 ( V_2 ) ;
if ( F_22 ( V_2 ) )
return 0 ;
if ( F_2 ( V_2 ) ) {
if ( V_8 -> V_11 >= F_27 ( V_2 ) -> V_33 . V_11 ) {
if ( ! V_19 || V_19 != F_27 ( V_2 ) )
return 0 ;
}
}
if ( V_19 || F_2 ( V_2 ) ) {
unsigned long V_12 ;
struct V_16 * V_38 ;
F_15 ( & V_8 -> V_13 , V_12 ) ;
if ( V_19 ) {
F_28 ( & V_19 -> V_33 , & V_2 -> V_35 ) ;
V_8 -> V_31 = NULL ;
}
if ( F_2 ( V_2 ) ) {
V_38 = F_27 ( V_2 ) ;
V_38 -> V_10 . V_11 = V_38 -> V_33 . V_11 ;
F_29 ( & V_38 -> V_10 , & V_8 -> V_37 ) ;
}
F_16 ( & V_8 -> V_13 , V_12 ) ;
}
F_33 ( V_2 ) ;
F_1 ( V_2 , V_8 ) ;
F_34 ( V_2 , V_8 ) ;
return 1 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_16 * V_19 ,
struct V_3 * V_8 ,
int V_21 )
{
struct V_3 * V_4 = F_22 ( V_2 ) ;
struct V_16 * V_20 = V_19 ;
unsigned long V_12 ;
int V_39 = 0 , V_40 ;
F_15 ( & V_8 -> V_13 , V_12 ) ;
F_12 ( V_8 ) ;
V_19 -> V_8 = V_8 ;
V_19 -> V_2 = V_2 ;
F_36 ( & V_19 -> V_33 , V_8 -> V_11 ) ;
F_36 ( & V_19 -> V_10 , V_8 -> V_11 ) ;
if ( F_2 ( V_2 ) )
V_20 = F_27 ( V_2 ) ;
F_29 ( & V_19 -> V_33 , & V_2 -> V_35 ) ;
V_8 -> V_31 = V_19 ;
F_16 ( & V_8 -> V_13 , V_12 ) ;
if ( ! V_4 )
return 0 ;
if ( V_19 == F_27 ( V_2 ) ) {
F_15 ( & V_4 -> V_13 , V_12 ) ;
F_28 ( & V_20 -> V_10 , & V_4 -> V_37 ) ;
F_29 ( & V_19 -> V_10 , & V_4 -> V_37 ) ;
F_12 ( V_4 ) ;
if ( V_4 -> V_31 )
V_39 = 1 ;
F_16 ( & V_4 -> V_13 , V_12 ) ;
}
else if ( F_18 ( V_19 , V_21 ) )
V_39 = 1 ;
if ( ! V_39 )
return 0 ;
F_31 ( V_4 ) ;
F_26 ( & V_2 -> V_34 ) ;
V_40 = F_17 ( V_4 , V_21 , V_2 , V_19 ,
V_8 ) ;
F_37 ( & V_2 -> V_34 ) ;
return V_40 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
unsigned long V_12 ;
F_15 ( & V_41 -> V_13 , V_12 ) ;
V_19 = F_27 ( V_2 ) ;
F_28 ( & V_19 -> V_10 , & V_41 -> V_37 ) ;
F_1 ( V_2 , NULL ) ;
F_16 ( & V_41 -> V_13 , V_12 ) ;
F_30 ( V_19 -> V_8 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_16 * V_19 )
{
int V_42 = ( V_19 == F_27 ( V_2 ) ) ;
struct V_3 * V_4 = F_22 ( V_2 ) ;
unsigned long V_12 ;
int V_39 = 0 ;
F_15 ( & V_41 -> V_13 , V_12 ) ;
F_28 ( & V_19 -> V_33 , & V_2 -> V_35 ) ;
V_41 -> V_31 = NULL ;
F_16 ( & V_41 -> V_13 , V_12 ) ;
if ( ! V_4 )
return;
if ( V_42 ) {
F_15 ( & V_4 -> V_13 , V_12 ) ;
F_28 ( & V_19 -> V_10 , & V_4 -> V_37 ) ;
if ( F_2 ( V_2 ) ) {
struct V_16 * V_43 ;
V_43 = F_27 ( V_2 ) ;
F_29 ( & V_43 -> V_10 , & V_4 -> V_37 ) ;
}
F_12 ( V_4 ) ;
if ( V_4 -> V_31 )
V_39 = 1 ;
F_16 ( & V_4 -> V_13 , V_12 ) ;
}
F_40 ( ! F_41 ( & V_19 -> V_10 ) ) ;
if ( ! V_39 )
return;
F_31 ( V_4 ) ;
F_26 ( & V_2 -> V_34 ) ;
F_17 ( V_4 , 0 , V_2 , NULL , V_41 ) ;
F_37 ( & V_2 -> V_34 ) ;
}
void F_42 ( struct V_3 * V_8 )
{
struct V_16 * V_19 ;
unsigned long V_12 ;
F_15 ( & V_8 -> V_13 , V_12 ) ;
V_19 = V_8 -> V_31 ;
if ( ! V_19 || V_19 -> V_33 . V_11 == V_8 -> V_11 ) {
F_16 ( & V_8 -> V_13 , V_12 ) ;
return;
}
F_16 ( & V_8 -> V_13 , V_12 ) ;
F_31 ( V_8 ) ;
F_17 ( V_8 , 0 , NULL , NULL , V_8 ) ;
}
static int T_1
F_43 ( struct V_1 * V_2 , int V_44 ,
struct V_45 * V_46 ,
struct V_16 * V_19 )
{
int V_22 = 0 ;
for (; ; ) {
if ( F_32 ( V_2 , V_41 , V_19 ) )
break;
if ( F_44 ( V_44 == V_47 ) ) {
if ( F_45 ( V_41 ) )
V_22 = - V_48 ;
if ( V_46 && ! V_46 -> V_8 )
V_22 = - V_49 ;
if ( V_22 )
break;
}
F_26 ( & V_2 -> V_34 ) ;
F_46 ( V_19 ) ;
F_47 ( V_2 ) ;
F_37 ( & V_2 -> V_34 ) ;
F_48 ( V_44 ) ;
}
return V_22 ;
}
static int T_1
F_49 ( struct V_1 * V_2 , int V_44 ,
struct V_45 * V_46 ,
int V_21 )
{
struct V_16 V_19 ;
int V_22 = 0 ;
F_50 ( & V_19 ) ;
F_37 ( & V_2 -> V_34 ) ;
if ( F_32 ( V_2 , V_41 , NULL ) ) {
F_26 ( & V_2 -> V_34 ) ;
return 0 ;
}
F_48 ( V_44 ) ;
if ( F_44 ( V_46 ) ) {
F_51 ( & V_46 -> V_50 , V_51 ) ;
if ( ! F_52 ( & V_46 -> V_50 ) )
V_46 -> V_8 = NULL ;
}
V_22 = F_35 ( V_2 , & V_19 , V_41 , V_21 ) ;
if ( F_8 ( ! V_22 ) )
V_22 = F_43 ( V_2 , V_44 , V_46 , & V_19 ) ;
F_48 ( V_52 ) ;
if ( F_44 ( V_22 ) )
F_39 ( V_2 , & V_19 ) ;
F_4 ( V_2 ) ;
F_26 ( & V_2 -> V_34 ) ;
if ( F_44 ( V_46 ) )
F_53 ( & V_46 -> V_50 ) ;
F_54 ( & V_19 ) ;
return V_22 ;
}
static inline int
F_55 ( struct V_1 * V_2 )
{
int V_22 = 0 ;
F_37 ( & V_2 -> V_34 ) ;
if ( F_8 ( F_22 ( V_2 ) != V_41 ) ) {
V_22 = F_32 ( V_2 , V_41 , NULL ) ;
F_4 ( V_2 ) ;
}
F_26 ( & V_2 -> V_34 ) ;
return V_22 ;
}
static void T_1
F_56 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_34 ) ;
F_57 ( V_2 ) ;
F_58 ( V_41 ) ;
if ( ! F_2 ( V_2 ) ) {
V_2 -> V_4 = NULL ;
F_26 ( & V_2 -> V_34 ) ;
return;
}
F_38 ( V_2 ) ;
F_26 ( & V_2 -> V_34 ) ;
F_14 ( V_41 ) ;
}
static inline int
F_59 ( struct V_1 * V_2 , int V_44 ,
int V_21 ,
int (* F_60)( struct V_1 * V_2 , int V_44 ,
struct V_45 * V_46 ,
int V_21 ) )
{
if ( ! V_21 && F_8 ( F_61 ( V_2 , NULL , V_41 ) ) ) {
F_34 ( V_2 , V_41 ) ;
return 0 ;
} else
return F_60 ( V_2 , V_44 , NULL , V_21 ) ;
}
static inline int
F_62 ( struct V_1 * V_2 , int V_44 ,
struct V_45 * V_46 , int V_21 ,
int (* F_60)( struct V_1 * V_2 , int V_44 ,
struct V_45 * V_46 ,
int V_21 ) )
{
if ( ! V_21 && F_8 ( F_61 ( V_2 , NULL , V_41 ) ) ) {
F_34 ( V_2 , V_41 ) ;
return 0 ;
} else
return F_60 ( V_2 , V_44 , V_46 , V_21 ) ;
}
static inline int
F_63 ( struct V_1 * V_2 ,
int (* F_60)( struct V_1 * V_2 ) )
{
if ( F_8 ( F_61 ( V_2 , NULL , V_41 ) ) ) {
F_34 ( V_2 , V_41 ) ;
return 1 ;
}
return F_60 ( V_2 ) ;
}
static inline void
F_64 ( struct V_1 * V_2 ,
void (* F_60)( struct V_1 * V_2 ) )
{
if ( F_8 ( F_61 ( V_2 , V_41 , NULL ) ) )
F_58 ( V_41 ) ;
else
F_60 ( V_2 ) ;
}
void T_1 F_65 ( struct V_1 * V_2 )
{
F_66 () ;
F_59 ( V_2 , V_53 , 0 , F_49 ) ;
}
int T_1 F_67 ( struct V_1 * V_2 ,
int V_21 )
{
F_66 () ;
return F_59 ( V_2 , V_47 ,
V_21 , F_49 ) ;
}
int
F_68 ( struct V_1 * V_2 , struct V_45 * V_46 ,
int V_21 )
{
F_66 () ;
return F_62 ( V_2 , V_47 , V_46 ,
V_21 , F_49 ) ;
}
int T_1 F_69 ( struct V_1 * V_2 )
{
return F_63 ( V_2 , F_55 ) ;
}
void T_1 F_70 ( struct V_1 * V_2 )
{
F_64 ( V_2 , F_56 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
F_40 ( F_72 ( V_2 ) ) ;
#ifdef F_73
V_2 -> V_54 = NULL ;
#endif
}
void F_74 ( struct V_1 * V_2 , const char * V_55 )
{
V_2 -> V_4 = NULL ;
F_75 ( & V_2 -> V_34 ) ;
F_76 ( & V_2 -> V_35 ) ;
F_77 ( V_2 , V_55 ) ;
}
void F_78 ( struct V_1 * V_2 ,
struct V_3 * V_56 )
{
F_74 ( V_2 , NULL ) ;
F_79 ( V_2 , V_56 ) ;
F_1 ( V_2 , V_56 ) ;
F_34 ( V_2 , V_56 ) ;
}
void F_80 ( struct V_1 * V_2 ,
struct V_3 * V_56 )
{
F_81 ( V_2 ) ;
F_1 ( V_2 , NULL ) ;
F_58 ( V_56 ) ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_16 * V_19 ,
struct V_3 * V_8 , int V_21 )
{
int V_22 ;
F_37 ( & V_2 -> V_34 ) ;
if ( F_32 ( V_2 , V_8 , NULL ) ) {
F_26 ( & V_2 -> V_34 ) ;
return 1 ;
}
V_22 = F_35 ( V_2 , V_19 , V_8 , V_21 ) ;
if ( V_22 && ! F_22 ( V_2 ) ) {
V_22 = 0 ;
}
if ( F_44 ( V_22 ) )
F_39 ( V_2 , V_19 ) ;
F_26 ( & V_2 -> V_34 ) ;
F_46 ( V_19 ) ;
return V_22 ;
}
struct V_3 * F_83 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
return NULL ;
return F_27 ( V_2 ) -> V_8 ;
}
int F_84 ( struct V_1 * V_2 ,
struct V_45 * V_57 ,
struct V_16 * V_19 ,
int V_21 )
{
int V_22 ;
F_37 ( & V_2 -> V_34 ) ;
F_48 ( V_47 ) ;
V_22 = F_43 ( V_2 , V_47 , V_57 , V_19 ) ;
F_48 ( V_52 ) ;
if ( F_44 ( V_22 ) )
F_39 ( V_2 , V_19 ) ;
F_4 ( V_2 ) ;
F_26 ( & V_2 -> V_34 ) ;
return V_22 ;
}
