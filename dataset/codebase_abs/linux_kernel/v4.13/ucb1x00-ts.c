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
F_29 ( & V_2 -> V_42 ) ;
if ( V_2 -> V_43 ) {
V_2 -> V_43 = 0 ;
F_30 ( V_2 -> V_12 -> V_44 + V_45 ) ;
}
F_31 ( & V_2 -> V_42 ) ;
F_32 ( V_2 -> V_12 ) ;
if ( V_37 ) {
F_5 ( V_2 ) ;
V_37 = 0 ;
}
V_40 = V_46 ;
} else {
F_32 ( V_2 -> V_12 ) ;
if ( ! V_36 ) {
F_1 ( V_2 , V_39 , V_4 , V_5 ) ;
V_37 = 1 ;
}
F_28 ( V_41 ) ;
V_40 = V_47 / 100 ;
}
F_33 ( V_40 ) ;
}
F_34 ( & V_2 -> V_38 , & V_33 ) ;
V_2 -> V_48 = NULL ;
return 0 ;
}
static T_2 F_35 ( int V_49 , void * V_50 )
{
struct V_1 * V_2 = V_50 ;
F_36 ( & V_2 -> V_42 ) ;
V_2 -> V_43 = 1 ;
F_37 ( V_2 -> V_12 -> V_44 + V_45 ) ;
F_38 ( & V_2 -> V_42 ) ;
F_39 ( & V_2 -> V_38 ) ;
return V_51 ;
}
static int F_40 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_41 ( V_7 ) ;
unsigned long V_52 = 0 ;
int V_53 = 0 ;
F_42 ( V_2 -> V_48 ) ;
if ( F_9 () )
V_52 = V_54 ;
else
V_52 = V_55 ;
V_2 -> V_43 = 0 ;
F_43 ( & V_2 -> V_38 ) ;
V_53 = F_44 ( V_2 -> V_12 -> V_44 + V_45 , F_35 ,
V_52 , L_1 , V_2 ) ;
if ( V_53 < 0 )
goto V_56;
F_24 ( V_2 -> V_12 ) ;
V_2 -> V_57 = F_15 ( V_2 ) ;
V_2 -> V_58 = F_16 ( V_2 ) ;
F_25 ( V_2 -> V_12 ) ;
V_2 -> V_48 = F_45 ( F_19 , V_2 , L_2 ) ;
if ( ! F_46 ( V_2 -> V_48 ) ) {
V_53 = 0 ;
} else {
F_47 ( V_2 -> V_12 -> V_44 + V_45 , V_2 ) ;
V_2 -> V_48 = NULL ;
V_53 = - V_59 ;
}
V_56:
return V_53 ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_41 ( V_7 ) ;
if ( V_2 -> V_48 )
F_49 ( V_2 -> V_48 ) ;
F_27 ( V_2 -> V_12 ) ;
F_47 ( V_2 -> V_12 -> V_44 + V_45 , V_2 ) ;
F_7 ( V_2 -> V_12 , V_13 , 0 ) ;
F_32 ( V_2 -> V_12 ) ;
}
static int F_50 ( struct V_60 * V_61 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
int V_62 ;
V_2 = F_51 ( sizeof( struct V_1 ) , V_63 ) ;
V_7 = F_52 () ;
if ( ! V_2 || ! V_7 ) {
V_62 = - V_64 ;
goto V_65;
}
V_2 -> V_12 = V_61 -> V_12 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_23 = V_23 ? V_66 : V_67 ;
F_53 ( & V_2 -> V_42 ) ;
V_7 -> V_68 = L_3 ;
V_7 -> V_50 . V_69 = V_2 -> V_12 -> V_50 ;
V_7 -> V_70 = F_40 ;
V_7 -> V_71 = F_48 ;
V_7 -> V_61 . V_72 = & V_2 -> V_12 -> V_61 ;
V_7 -> V_73 [ 0 ] = F_54 ( V_74 ) | F_54 ( V_75 ) ;
V_7 -> V_76 [ F_55 ( V_11 ) ] = F_54 ( V_11 ) ;
F_56 ( V_7 , V_2 ) ;
F_24 ( V_2 -> V_12 ) ;
V_2 -> V_57 = F_15 ( V_2 ) ;
V_2 -> V_58 = F_16 ( V_2 ) ;
F_25 ( V_2 -> V_12 ) ;
F_57 ( V_7 , V_8 , 0 , V_2 -> V_57 , 0 , 0 ) ;
F_57 ( V_7 , V_9 , 0 , V_2 -> V_58 , 0 , 0 ) ;
F_57 ( V_7 , V_10 , 0 , 0 , 0 , 0 ) ;
V_62 = F_58 ( V_7 ) ;
if ( V_62 )
goto V_65;
V_61 -> V_77 = V_2 ;
return 0 ;
V_65:
F_59 ( V_7 ) ;
F_60 ( V_2 ) ;
return V_62 ;
}
static void F_61 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_77 ;
F_62 ( V_2 -> V_7 ) ;
F_60 ( V_2 ) ;
}
static int T_3 F_63 ( void )
{
return F_64 ( & V_78 ) ;
}
static void T_4 F_65 ( void )
{
F_66 ( & V_78 ) ;
}
