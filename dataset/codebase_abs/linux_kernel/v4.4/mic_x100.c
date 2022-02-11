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
static void F_6 ( struct V_8 * V_9 , int V_7 )
{
T_2 V_13 = V_14 + V_7 * 8 ;
T_1 V_15 = F_2 ( V_9 , V_5 +
V_13 ) ;
V_15 = ( V_15 | ( 1 << 13 ) ) ;
F_4 () ;
F_5 ( V_9 , V_15 ,
V_5 + V_13 ) ;
}
static void F_7 ( struct V_8 * V_9 , int V_7 )
{
int V_16 = V_17 + ( V_7 << 2 ) ;
F_4 () ;
F_5 ( V_9 , 0 , V_5 + V_16 ) ;
}
T_1 F_8 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline int F_9 ( int V_18 )
{
return V_19 + V_18 ;
}
static inline int F_10 ( int V_20 )
{
return V_21 + V_20 ;
}
void F_11 ( int V_18 , struct V_8 * V_9 )
{
int V_22 ;
if ( V_18 < V_23 ) {
F_6 ( V_9 , V_18 ) ;
} else {
V_22 = V_18 - V_23 ;
F_7 ( V_9 , V_22 ) ;
}
}
void F_12 ( struct V_24 * V_25 )
{
V_25 -> V_26 . V_27 = V_23 +
V_28 ;
}
int F_13 ( struct V_24 * V_25 , int V_18 )
{
int V_22 ;
if ( V_18 < V_23 ) {
return F_9 ( V_18 ) ;
} else {
V_22 = V_18 - V_23 ;
return F_10 ( V_22 ) ;
}
}
void T_3 *
F_14 ( struct V_1 * V_2 , T_4 V_29 , T_5 V_30 )
{
return F_15 ( V_29 , V_30 ) ;
}
void F_16 ( struct V_1 * V_2 , void T_3 * V_29 )
{
F_17 ( V_29 ) ;
}
static inline struct V_24 * F_18 ( struct V_31 * V_32 )
{
return F_19 ( V_32 -> V_33 . V_34 ) ;
}
static struct V_35 *
F_20 ( struct V_31 * V_32 ,
T_6 V_36 , T_6 V_37 ,
const char * V_38 , void * V_39 , int V_40 )
{
int V_41 = 0 ;
unsigned int V_42 = V_40 ;
unsigned long V_43 = V_42 ;
V_41 = F_21 ( V_42 , V_36 , V_37 , 0 , V_38 , V_39 ) ;
if ( V_41 ) {
F_22 ( F_18 ( V_32 ) -> V_33 ,
L_1 , V_41 ) ;
return F_23 ( V_41 ) ;
}
return (struct V_35 * ) V_43 ;
}
static void F_24 ( struct V_31 * V_32 ,
struct V_35 * V_43 , void * V_39 )
{
unsigned long V_42 = ( unsigned long ) V_43 ;
F_25 ( V_42 , V_39 ) ;
}
static void F_26 ( struct V_31 * V_32 , int V_44 )
{
F_8 ( & F_18 ( V_32 ) -> V_2 ) ;
}
static int T_7 F_27 ( struct V_45 * V_46 )
{
struct V_24 * V_25 = & V_47 ;
struct V_1 * V_2 = & V_25 -> V_2 ;
int V_41 = 0 ;
V_25 -> V_33 = & V_46 -> V_33 ;
snprintf ( V_25 -> V_38 , sizeof( V_48 ) , V_48 ) ;
V_2 -> V_4 . V_49 = V_50 ;
V_2 -> V_4 . V_51 = V_52 ;
V_2 -> V_4 . V_53 = F_28 ( & V_46 -> V_33 , V_50 ,
V_52 ) ;
if ( ! V_2 -> V_4 . V_53 ) {
F_22 ( & V_46 -> V_33 , L_2 ) ;
V_41 = - V_54 ;
goto V_55;
}
F_12 ( V_25 ) ;
F_29 ( V_46 , V_25 ) ;
V_25 -> V_56 = F_30 ( V_25 -> V_33 , V_57 ,
NULL , & V_58 , 0 ,
V_25 -> V_2 . V_4 . V_53 ) ;
if ( F_31 ( V_25 -> V_56 ) ) {
V_41 = F_32 ( V_25 -> V_56 ) ;
F_22 ( & V_46 -> V_33 , L_3 , V_41 ) ;
goto V_55;
}
V_41 = F_33 ( V_25 ) ;
if ( V_41 ) {
F_22 ( & V_46 -> V_33 , L_4 , V_41 ) ;
goto V_59;
}
V_55:
return V_41 ;
V_59:
F_34 ( V_25 -> V_56 ) ;
return V_41 ;
}
static int F_35 ( struct V_45 * V_46 )
{
struct V_24 * V_25 = & V_47 ;
F_36 ( V_25 ) ;
F_34 ( V_25 -> V_56 ) ;
return 0 ;
}
static void F_37 ( struct V_45 * V_46 )
{
F_35 ( V_46 ) ;
}
static int T_7 F_38 ( void )
{
int V_60 ;
struct V_61 * V_62 = & F_39 ( 0 ) ;
if ( ! ( V_62 -> V_63 == 11 && V_62 -> V_64 == 1 ) ) {
V_60 = - V_65 ;
F_40 ( L_5 , V_66 , V_60 ) ;
goto V_55;
}
F_41 () ;
V_60 = F_42 ( & V_67 ) ;
if ( V_60 ) {
F_40 ( L_6 , V_60 ) ;
goto V_68;
}
V_60 = F_43 ( & V_69 ) ;
if ( V_60 ) {
F_40 ( L_7 , V_60 ) ;
goto V_70;
}
return V_60 ;
V_70:
F_44 ( & V_67 ) ;
V_68:
F_45 () ;
V_55:
return V_60 ;
}
static void T_8 F_46 ( void )
{
F_47 ( & V_69 ) ;
F_44 ( & V_67 ) ;
F_45 () ;
}
