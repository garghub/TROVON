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
bool V_35 , V_36 = false ;
int V_37 = 0 ;
F_21 () ;
F_22 ( & V_2 -> V_38 , & V_33 ) ;
while ( ! F_23 ( & V_35 ) ) {
unsigned int V_4 , V_5 , V_39 ;
signed long V_40 ;
if ( V_35 )
V_36 = true ;
F_24 ( V_2 -> V_12 ) ;
V_4 = F_13 ( V_2 ) ;
V_5 = F_14 ( V_2 ) ;
V_39 = F_8 ( V_2 ) ;
F_6 ( V_2 ) ;
F_25 ( V_2 -> V_12 ) ;
F_26 ( 10 ) ;
F_27 ( V_2 -> V_12 ) ;
if ( F_17 ( V_2 ) ) {
F_28 ( V_41 ) ;
F_29 ( V_2 -> V_12 , V_42 , F_9 () ? V_43 : V_44 ) ;
F_30 ( V_2 -> V_12 ) ;
if ( V_37 ) {
F_5 ( V_2 ) ;
V_37 = 0 ;
}
V_40 = V_45 ;
} else {
F_30 ( V_2 -> V_12 ) ;
if ( ! V_36 ) {
F_1 ( V_2 , V_39 , V_4 , V_5 ) ;
V_37 = 1 ;
}
F_28 ( V_41 ) ;
V_40 = V_46 / 100 ;
}
F_31 ( V_40 ) ;
}
F_32 ( & V_2 -> V_38 , & V_33 ) ;
V_2 -> V_47 = NULL ;
return 0 ;
}
static void F_33 ( int V_48 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
F_34 ( V_2 -> V_12 , V_42 , V_44 ) ;
F_35 ( & V_2 -> V_38 ) ;
}
static int F_36 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_37 ( V_7 ) ;
int V_50 = 0 ;
F_38 ( V_2 -> V_47 ) ;
F_39 ( & V_2 -> V_38 ) ;
V_50 = F_40 ( V_2 -> V_12 , V_42 , F_33 , V_2 ) ;
if ( V_50 < 0 )
goto V_51;
F_24 ( V_2 -> V_12 ) ;
V_2 -> V_52 = F_15 ( V_2 ) ;
V_2 -> V_53 = F_16 ( V_2 ) ;
F_25 ( V_2 -> V_12 ) ;
V_2 -> V_47 = F_41 ( F_19 , V_2 , L_1 ) ;
if ( ! F_42 ( V_2 -> V_47 ) ) {
V_50 = 0 ;
} else {
F_43 ( V_2 -> V_12 , V_42 , V_2 ) ;
V_2 -> V_47 = NULL ;
V_50 = - V_54 ;
}
V_51:
return V_50 ;
}
static void F_44 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_37 ( V_7 ) ;
if ( V_2 -> V_47 )
F_45 ( V_2 -> V_47 ) ;
F_27 ( V_2 -> V_12 ) ;
F_43 ( V_2 -> V_12 , V_42 , V_2 ) ;
F_7 ( V_2 -> V_12 , V_13 , 0 ) ;
F_30 ( V_2 -> V_12 ) ;
}
static int F_46 ( struct V_55 * V_56 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
int V_57 ;
V_2 = F_47 ( sizeof( struct V_1 ) , V_58 ) ;
V_7 = F_48 () ;
if ( ! V_2 || ! V_7 ) {
V_57 = - V_59 ;
goto V_60;
}
V_2 -> V_12 = V_56 -> V_12 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_23 = V_23 ? V_61 : V_62 ;
V_7 -> V_63 = L_2 ;
V_7 -> V_49 . V_64 = V_2 -> V_12 -> V_49 ;
V_7 -> V_65 = F_36 ;
V_7 -> V_66 = F_44 ;
V_7 -> V_67 [ 0 ] = F_49 ( V_68 ) | F_49 ( V_69 ) ;
V_7 -> V_70 [ F_50 ( V_11 ) ] = F_49 ( V_11 ) ;
F_51 ( V_7 , V_2 ) ;
F_24 ( V_2 -> V_12 ) ;
V_2 -> V_52 = F_15 ( V_2 ) ;
V_2 -> V_53 = F_16 ( V_2 ) ;
F_25 ( V_2 -> V_12 ) ;
F_52 ( V_7 , V_8 , 0 , V_2 -> V_52 , 0 , 0 ) ;
F_52 ( V_7 , V_9 , 0 , V_2 -> V_53 , 0 , 0 ) ;
F_52 ( V_7 , V_10 , 0 , 0 , 0 , 0 ) ;
V_57 = F_53 ( V_7 ) ;
if ( V_57 )
goto V_60;
V_56 -> V_71 = V_2 ;
return 0 ;
V_60:
F_54 ( V_7 ) ;
F_55 ( V_2 ) ;
return V_57 ;
}
static void F_56 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_71 ;
F_57 ( V_2 -> V_7 ) ;
F_55 ( V_2 ) ;
}
static int T_2 F_58 ( void )
{
return F_59 ( & V_72 ) ;
}
static void T_3 F_60 ( void )
{
F_61 ( & V_72 ) ;
}
