static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_2 ( V_7 , V_8 , V_4 ) ;
F_2 ( V_7 , V_9 , V_5 ) ;
F_2 ( V_7 , V_10 , V_3 ) ;
F_3 ( V_7 , V_11 , 1 ) ;
F_4 ( V_7 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_2 ( V_7 , V_10 , 0 ) ;
F_3 ( V_7 , V_11 , 0 ) ;
F_4 ( V_7 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_12 , V_13 ,
V_14 | V_15 |
V_16 | V_17 |
V_18 ) ;
}
static inline unsigned int F_8 ( struct V_1 * V_2 )
{
if ( F_9 () ) {
F_10 ( V_2 -> V_12 , V_19 , 0 ) ;
F_7 ( V_2 -> V_12 , V_13 ,
V_15 | V_14 |
V_20 | V_21 ) ;
F_11 ( 55 ) ;
return F_12 ( V_2 -> V_12 , V_22 , V_2 -> V_23 ) ;
} else {
F_7 ( V_2 -> V_12 , V_13 ,
V_14 | V_15 |
V_16 | V_17 |
V_24 | V_21 ) ;
return F_12 ( V_2 -> V_12 , V_25 , V_2 -> V_23 ) ;
}
}
static inline unsigned int F_13 ( struct V_1 * V_2 )
{
if ( F_9 () )
F_10 ( V_2 -> V_12 , 0 , V_19 ) ;
else {
F_7 ( V_2 -> V_12 , V_13 ,
V_26 | V_15 |
V_24 | V_21 ) ;
F_7 ( V_2 -> V_12 , V_13 ,
V_26 | V_15 |
V_24 | V_21 ) ;
}
F_7 ( V_2 -> V_12 , V_13 ,
V_26 | V_15 |
V_20 | V_21 ) ;
F_11 ( 55 ) ;
return F_12 ( V_2 -> V_12 , V_25 , V_2 -> V_23 ) ;
}
static inline unsigned int F_14 ( struct V_1 * V_2 )
{
if ( F_9 () )
F_10 ( V_2 -> V_12 , 0 , V_19 ) ;
else {
F_7 ( V_2 -> V_12 , V_13 ,
V_16 | V_27 |
V_24 | V_21 ) ;
F_7 ( V_2 -> V_12 , V_13 ,
V_16 | V_27 |
V_24 | V_21 ) ;
}
F_7 ( V_2 -> V_12 , V_13 ,
V_16 | V_27 |
V_20 | V_21 ) ;
F_11 ( 55 ) ;
return F_12 ( V_2 -> V_12 , V_28 , V_2 -> V_23 ) ;
}
static inline unsigned int F_15 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_12 , V_13 ,
V_26 | V_15 |
V_24 | V_21 ) ;
return F_12 ( V_2 -> V_12 , 0 , V_2 -> V_23 ) ;
}
static inline unsigned int F_16 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_12 , V_13 ,
V_16 | V_27 |
V_24 | V_21 ) ;
return F_12 ( V_2 -> V_12 , 0 , V_2 -> V_23 ) ;
}
static inline int F_17 ( struct V_1 * V_2 )
{
unsigned int V_29 = F_18 ( V_2 -> V_12 , V_13 ) ;
if ( F_9 () )
return ( ! ( V_29 & ( V_30 ) ) ) ;
else
return ( V_29 & ( V_30 | V_31 ) ) ;
}
static int F_19 ( void * V_32 )
{
struct V_1 * V_2 = V_32 ;
F_20 ( V_33 , V_34 ) ;
int V_35 = 0 ;
F_21 () ;
F_22 ( & V_2 -> V_36 , & V_33 ) ;
while ( ! F_23 () ) {
unsigned int V_4 , V_5 , V_37 ;
signed long V_38 ;
V_2 -> V_39 = 0 ;
F_24 ( V_2 -> V_12 ) ;
V_4 = F_13 ( V_2 ) ;
V_5 = F_14 ( V_2 ) ;
V_37 = F_8 ( V_2 ) ;
F_6 ( V_2 ) ;
F_25 ( V_2 -> V_12 ) ;
F_26 ( 10 ) ;
F_27 ( V_2 -> V_12 ) ;
if ( F_17 ( V_2 ) ) {
F_28 ( V_40 ) ;
F_29 ( V_2 -> V_12 , V_41 , F_9 () ? V_42 : V_43 ) ;
F_30 ( V_2 -> V_12 ) ;
if ( V_35 ) {
F_5 ( V_2 ) ;
V_35 = 0 ;
}
V_38 = V_44 ;
} else {
F_30 ( V_2 -> V_12 ) ;
if ( ! V_2 -> V_39 ) {
F_1 ( V_2 , V_37 , V_4 , V_5 ) ;
V_35 = 1 ;
}
F_28 ( V_40 ) ;
V_38 = V_45 / 100 ;
}
F_31 () ;
F_32 ( V_38 ) ;
}
F_33 ( & V_2 -> V_36 , & V_33 ) ;
V_2 -> V_46 = NULL ;
return 0 ;
}
static void F_34 ( int V_47 , void * V_48 )
{
struct V_1 * V_2 = V_48 ;
F_35 ( V_2 -> V_12 , V_41 , V_43 ) ;
F_36 ( & V_2 -> V_36 ) ;
}
static int F_37 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_38 ( V_7 ) ;
int V_49 = 0 ;
F_39 ( V_2 -> V_46 ) ;
F_40 ( & V_2 -> V_36 ) ;
V_49 = F_41 ( V_2 -> V_12 , V_41 , F_34 , V_2 ) ;
if ( V_49 < 0 )
goto V_50;
F_24 ( V_2 -> V_12 ) ;
V_2 -> V_51 = F_15 ( V_2 ) ;
V_2 -> V_52 = F_16 ( V_2 ) ;
F_25 ( V_2 -> V_12 ) ;
V_2 -> V_46 = F_42 ( F_19 , V_2 , L_1 ) ;
if ( ! F_43 ( V_2 -> V_46 ) ) {
V_49 = 0 ;
} else {
F_44 ( V_2 -> V_12 , V_41 , V_2 ) ;
V_2 -> V_46 = NULL ;
V_49 = - V_53 ;
}
V_50:
return V_49 ;
}
static void F_45 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_38 ( V_7 ) ;
if ( V_2 -> V_46 )
F_46 ( V_2 -> V_46 ) ;
F_27 ( V_2 -> V_12 ) ;
F_44 ( V_2 -> V_12 , V_41 , V_2 ) ;
F_7 ( V_2 -> V_12 , V_13 , 0 ) ;
F_30 ( V_2 -> V_12 ) ;
}
static int F_47 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = V_55 -> V_56 ;
if ( V_2 -> V_46 != NULL ) {
V_2 -> V_39 = 1 ;
F_36 ( & V_2 -> V_36 ) ;
}
return 0 ;
}
static int F_48 ( struct V_54 * V_55 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
int V_57 ;
V_2 = F_49 ( sizeof( struct V_1 ) , V_58 ) ;
V_7 = F_50 () ;
if ( ! V_2 || ! V_7 ) {
V_57 = - V_59 ;
goto V_60;
}
V_2 -> V_12 = V_55 -> V_12 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_23 = V_23 ? V_61 : V_62 ;
V_7 -> V_63 = L_2 ;
V_7 -> V_48 . V_64 = V_2 -> V_12 -> V_48 ;
V_7 -> V_65 = F_37 ;
V_7 -> V_66 = F_45 ;
V_7 -> V_67 [ 0 ] = F_51 ( V_68 ) | F_51 ( V_69 ) ;
V_7 -> V_70 [ F_52 ( V_11 ) ] = F_51 ( V_11 ) ;
F_53 ( V_7 , V_2 ) ;
F_24 ( V_2 -> V_12 ) ;
V_2 -> V_51 = F_15 ( V_2 ) ;
V_2 -> V_52 = F_16 ( V_2 ) ;
F_25 ( V_2 -> V_12 ) ;
F_54 ( V_7 , V_8 , 0 , V_2 -> V_51 , 0 , 0 ) ;
F_54 ( V_7 , V_9 , 0 , V_2 -> V_52 , 0 , 0 ) ;
F_54 ( V_7 , V_10 , 0 , 0 , 0 , 0 ) ;
V_57 = F_55 ( V_7 ) ;
if ( V_57 )
goto V_60;
V_55 -> V_56 = V_2 ;
return 0 ;
V_60:
F_56 ( V_7 ) ;
F_57 ( V_2 ) ;
return V_57 ;
}
static void F_58 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = V_55 -> V_56 ;
F_59 ( V_2 -> V_7 ) ;
F_57 ( V_2 ) ;
}
static int T_2 F_60 ( void )
{
return F_61 ( & V_71 ) ;
}
static void T_3 F_62 ( void )
{
F_63 ( & V_71 ) ;
}
