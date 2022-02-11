T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( & V_2 -> V_4 ,
V_5 +
V_6 + V_3 * 4 ) ;
}
void F_3 ( struct V_1 * V_2 , int V_7 )
{
struct V_8 * V_9 = & V_2 -> V_4 ;
if ( V_7 > V_10 )
return;
F_4 () ;
F_5 ( V_9 , V_11 ,
V_5 +
( V_12 + ( 4 * V_7 ) ) ) ;
}
T_1 F_6 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline int F_7 ( int V_13 )
{
return V_14 + V_13 ;
}
static inline int F_8 ( int V_15 )
{
return V_16 + V_15 ;
}
void F_9 ( struct V_17 * V_18 )
{
V_18 -> V_19 . V_20 = V_21 +
V_22 ;
}
int F_10 ( struct V_17 * V_18 , int V_13 )
{
int V_23 ;
if ( V_13 < V_21 ) {
return F_7 ( V_13 ) ;
} else {
V_23 = V_13 - V_21 +
V_16 ;
return F_8 ( V_23 ) ;
}
}
void T_2 *
F_11 ( struct V_1 * V_2 , T_3 V_24 , T_4 V_25 )
{
return F_12 ( V_24 , V_25 ) ;
}
void F_13 ( struct V_1 * V_2 , void T_2 * V_24 )
{
F_14 ( V_24 ) ;
}
static inline struct V_17 * F_15 ( struct V_26 * V_27 )
{
return F_16 ( V_27 -> V_28 . V_29 ) ;
}
static struct V_30 *
F_17 ( struct V_26 * V_27 ,
T_5 V_31 , T_5 V_32 ,
const char * V_33 , void * V_34 , int V_35 )
{
int V_36 = 0 ;
unsigned int V_37 = V_35 ;
unsigned long V_38 = V_37 ;
V_36 = F_18 ( V_37 , V_31 , V_32 , 0 , V_33 , V_34 ) ;
if ( V_36 ) {
F_19 ( F_15 ( V_27 ) -> V_28 ,
L_1 , V_36 ) ;
return F_20 ( V_36 ) ;
}
return (struct V_30 * ) V_38 ;
}
static void F_21 ( struct V_26 * V_27 ,
struct V_30 * V_38 , void * V_34 )
{
unsigned long V_37 = ( unsigned long ) V_38 ;
F_22 ( V_37 , V_34 ) ;
}
static void F_23 ( struct V_26 * V_27 , int V_39 )
{
F_6 ( & F_15 ( V_27 ) -> V_2 ) ;
}
static int T_6 F_24 ( struct V_40 * V_41 )
{
struct V_17 * V_18 = & V_42 ;
struct V_1 * V_2 = & V_18 -> V_2 ;
int V_36 = 0 ;
V_18 -> V_28 = & V_41 -> V_28 ;
snprintf ( V_18 -> V_33 , sizeof( V_43 ) , V_43 ) ;
V_2 -> V_4 . V_44 = V_45 ;
V_2 -> V_4 . V_46 = V_47 ;
V_2 -> V_4 . V_48 = F_25 ( & V_41 -> V_28 , V_45 ,
V_47 ) ;
if ( ! V_2 -> V_4 . V_48 ) {
F_19 ( & V_41 -> V_28 , L_2 ) ;
V_36 = - V_49 ;
goto V_50;
}
F_9 ( V_18 ) ;
F_26 ( V_41 , V_18 ) ;
V_18 -> V_51 = F_27 ( V_18 -> V_28 , V_52 ,
NULL , & V_53 ,
V_18 -> V_2 . V_4 . V_48 ) ;
if ( F_28 ( V_18 -> V_51 ) ) {
V_36 = F_29 ( V_18 -> V_51 ) ;
F_19 ( & V_41 -> V_28 , L_3 , V_36 ) ;
goto V_50;
}
V_36 = F_30 ( V_18 ) ;
if ( V_36 ) {
F_19 ( & V_41 -> V_28 , L_4 , V_36 ) ;
goto V_54;
}
V_50:
return V_36 ;
V_54:
F_31 ( V_18 -> V_51 ) ;
return V_36 ;
}
static int F_32 ( struct V_40 * V_41 )
{
struct V_17 * V_18 = & V_42 ;
F_33 ( V_18 ) ;
F_31 ( V_18 -> V_51 ) ;
return 0 ;
}
static void F_34 ( struct V_40 * V_41 )
{
F_32 ( V_41 ) ;
}
static int T_6 F_35 ( void )
{
int V_55 ;
struct V_56 * V_57 = & F_36 ( 0 ) ;
if ( ! ( V_57 -> V_58 == 11 && V_57 -> V_59 == 1 ) ) {
V_55 = - V_60 ;
F_37 ( L_5 , V_61 , V_55 ) ;
goto V_50;
}
F_38 () ;
V_55 = F_39 ( & V_62 ) ;
if ( V_55 ) {
F_37 ( L_6 , V_55 ) ;
goto V_63;
}
V_55 = F_40 ( & V_64 ) ;
if ( V_55 ) {
F_37 ( L_7 , V_55 ) ;
goto V_65;
}
return V_55 ;
V_65:
F_41 ( & V_62 ) ;
V_63:
F_42 () ;
V_50:
return V_55 ;
}
static void T_7 F_43 ( void )
{
F_44 ( & V_64 ) ;
F_41 ( & V_62 ) ;
F_42 () ;
}
