static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_9 = V_4 -> V_9 ;
unsigned int V_10 ;
int V_11 ;
if ( V_9 == V_5 )
return 0 ;
if ( V_9 > V_5 )
return - V_12 ;
V_10 = V_5 - V_9 ;
V_11 = F_2 ( V_2 -> V_13 -> V_14 ,
F_3 ( V_7 , V_4 ) + F_4 ( V_9 ) ,
F_4 ( V_10 ) , V_15 , 0 ) ;
if ( V_11 ) {
F_5 ( V_2 -> V_13 ,
L_1 ,
F_6 ( V_7 , V_4 ) , ( unsigned long long ) V_9 ,
( unsigned long long ) V_5 , V_10 , V_11 ) ;
return V_11 ;
}
V_4 -> V_9 = V_5 ;
return 0 ;
}
static void F_7 ( int V_16 , unsigned long V_17 ,
void * V_18 )
{
struct V_1 * V_2 = V_18 ;
if ( V_16 || V_17 )
V_2 -> V_19 = - V_12 ;
else
V_2 -> V_19 = 0 ;
F_8 ( V_20 , & V_2 -> V_21 ) ;
F_9 () ;
F_10 ( & V_2 -> V_21 , V_20 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_22 , struct V_3 * V_23 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_24 * V_13 = V_2 -> V_13 ;
struct V_25 V_26 , V_27 ;
T_1 V_5 = 0 , V_28 ;
T_1 V_10 ;
T_1 V_29 ;
T_1 V_30 ;
unsigned long V_21 = 0 ;
int V_11 ;
if ( F_12 ( V_22 ) )
V_28 = V_22 -> V_9 ;
else
V_28 = V_13 -> V_31 ;
V_29 = F_13 ( V_7 , V_22 ) ;
V_30 = F_13 ( V_7 , V_23 ) ;
if ( F_12 ( V_23 ) )
F_14 ( V_32 , & V_21 ) ;
while ( V_5 < V_28 ) {
V_11 = F_15 ( V_7 , V_22 , & V_5 ) ;
if ( V_11 <= 0 )
return V_11 ;
V_10 = V_11 ;
if ( F_12 ( V_23 ) ) {
V_11 = F_1 ( V_2 , V_23 , V_5 ) ;
if ( V_11 )
return V_11 ;
}
V_26 . V_14 = V_13 -> V_14 ;
V_26 . V_33 = F_4 ( V_29 + V_5 ) ;
V_26 . V_34 = F_4 ( V_10 ) ;
V_27 . V_14 = V_13 -> V_14 ;
V_27 . V_33 = F_4 ( V_30 + V_5 ) ;
V_27 . V_34 = V_26 . V_34 ;
F_14 ( V_20 , & V_2 -> V_21 ) ;
V_11 = F_16 ( V_2 -> V_35 , & V_26 , 1 , & V_27 , V_21 ,
F_7 , V_2 ) ;
if ( V_11 )
return V_11 ;
F_17 ( & V_2 -> V_21 , V_20 ,
V_36 ) ;
if ( V_2 -> V_19 )
return V_2 -> V_19 ;
V_5 += V_10 ;
if ( F_12 ( V_23 ) )
V_23 -> V_9 = V_5 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_3 * V_37 )
{
struct V_3 * V_38 = V_37 -> V_38 ;
T_1 V_39 = V_37 -> V_9 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 ;
F_19 ( V_2 -> V_13 ,
L_2 ,
V_37 -> V_40 , F_6 ( V_7 , V_38 ) , F_20 ( V_38 ) ,
F_6 ( V_7 , V_37 ) , F_20 ( V_37 ) ) ;
V_11 = F_11 ( V_2 , V_38 , V_37 ) ;
if ( V_11 < 0 )
return V_11 ;
F_21 ( V_7 ) ;
V_11 = F_22 ( V_7 , V_38 , V_37 , V_39 ) ;
if ( V_11 == 0 ) {
F_23 ( V_7 , V_38 , 0 , V_2 -> V_13 -> V_31 ) ;
F_24 ( V_7 ) ;
F_25 ( V_7 , V_38 ) ;
F_26 ( V_37 ) ;
F_27 ( V_7 , V_38 ) ;
F_28 ( V_7 ) ;
}
F_29 ( V_7 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_3 * V_37 )
{
unsigned int V_40 = V_37 -> V_40 ;
struct V_3 * V_38 = V_37 -> V_38 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_19 ( V_2 -> V_13 ,
L_3 ,
V_40 , F_6 ( V_7 , V_37 ) , F_20 ( V_37 ) ,
F_6 ( V_7 , V_38 ) , F_20 ( V_38 ) ) ;
V_11 = F_11 ( V_2 , V_37 , V_38 ) ;
if ( V_11 < 0 )
return V_11 ;
F_21 ( V_7 ) ;
V_11 = F_22 ( V_7 , V_37 , V_38 , 0 ) ;
if ( V_11 == 0 ) {
F_23 ( V_7 , V_37 , 0 , V_2 -> V_13 -> V_31 ) ;
F_24 ( V_7 ) ;
F_25 ( V_7 , V_38 ) ;
F_25 ( V_7 , V_37 ) ;
F_26 ( V_37 ) ;
F_27 ( V_7 , V_37 ) ;
F_31 ( V_7 , V_38 , V_40 ) ;
F_28 ( V_7 ) ;
}
F_29 ( V_7 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_3 * V_37 )
{
unsigned int V_40 = V_37 -> V_40 ;
struct V_3 * V_41 = NULL ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 ;
F_24 ( V_7 ) ;
V_41 = F_33 ( V_7 , V_42 ) ;
F_28 ( V_7 ) ;
if ( ! V_41 )
return - V_43 ;
F_19 ( V_2 -> V_13 ,
L_4 ,
V_40 , F_6 ( V_7 , V_37 ) , F_20 ( V_37 ) ,
F_6 ( V_7 , V_41 ) ) ;
V_11 = F_11 ( V_2 , V_37 , V_41 ) ;
F_21 ( V_7 ) ;
if ( V_11 == 0 ) {
V_11 = F_34 ( V_7 , V_37 , V_41 ) ;
}
if ( V_11 ) {
F_24 ( V_7 ) ;
F_27 ( V_7 , V_41 ) ;
F_28 ( V_7 ) ;
} else {
F_23 ( V_7 , V_37 , 0 , V_2 -> V_13 -> V_31 ) ;
F_24 ( V_7 ) ;
F_25 ( V_7 , V_37 ) ;
F_26 ( V_37 ) ;
F_27 ( V_7 , V_37 ) ;
F_31 ( V_7 , V_41 , V_40 ) ;
F_28 ( V_7 ) ;
}
F_29 ( V_7 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 , struct V_3 * V_37 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_21 ( V_7 ) ;
F_24 ( V_7 ) ;
F_25 ( V_7 , V_37 ) ;
F_26 ( V_37 ) ;
F_27 ( V_7 , V_37 ) ;
F_28 ( V_7 ) ;
F_29 ( V_7 ) ;
}
static void V_1 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_3 * V_37 ;
struct V_3 * V_44 ;
unsigned long V_45 ;
int V_11 ;
V_37 = F_36 ( V_7 ) ;
if ( ! V_37 )
return;
V_45 = V_46 ;
if ( F_37 ( V_37 ) ) {
if ( ! F_20 ( V_37 ) ) {
F_35 ( V_2 , V_37 ) ;
V_11 = 0 ;
} else {
V_11 = F_32 ( V_2 , V_37 ) ;
}
V_44 = V_37 ;
} else {
struct V_3 * V_38 = V_37 -> V_38 ;
T_1 V_39 = 0 ;
V_11 = F_15 ( V_7 , V_38 , & V_39 ) ;
if ( V_11 < 0 )
goto V_47;
if ( V_11 == 0 || V_39 >= V_37 -> V_9 ) {
V_11 = F_18 ( V_2 , V_37 ) ;
V_44 = V_38 ;
} else {
V_11 = F_30 ( V_2 , V_37 ) ;
V_44 = V_37 ;
}
}
V_47:
if ( V_11 ) {
F_26 ( V_37 ) ;
return;
}
( void ) F_38 ( V_2 -> V_8 ) ;
F_19 ( V_2 -> V_13 , L_5 ,
F_6 ( V_7 , V_44 ) , F_39 ( V_46 - V_45 ) ) ;
}
static inline int F_40 ( struct V_1 * V_2 )
{
return F_41 ( V_2 -> V_48 + V_49 ) ;
}
static bool F_42 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_50 = F_43 ( V_7 ) ;
unsigned int V_51 = F_44 ( V_7 ) ;
unsigned int V_52 = V_51 * 100 / V_50 ;
if ( F_40 ( V_2 ) && V_51 < V_50 )
return true ;
if ( V_52 >= V_53 )
return false ;
return V_52 <= V_54 ;
}
static void F_45 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_46 ( V_56 , struct V_1 , V_56 . V_56 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_50 , V_51 ;
unsigned int V_52 ;
if ( ! F_42 ( V_2 ) ) {
F_47 ( V_2 -> V_57 , & V_2 -> V_56 , V_49 ) ;
return;
}
V_50 = F_43 ( V_7 ) ;
V_51 = F_44 ( V_7 ) ;
V_52 = V_51 * 100 / V_50 ;
if ( F_40 ( V_2 ) || V_52 < V_54 / 2 ) {
V_2 -> V_58 . V_59 = 100 ;
} else {
V_2 -> V_58 . V_59 = F_48 ( 75U , 100U - V_52 / 2 ) ;
}
F_19 ( V_2 -> V_13 ,
L_6 ,
V_2 -> V_58 . V_59 ,
( F_40 ( V_2 ) ? L_7 : L_8 ) ,
V_52 , V_51 , V_50 ) ;
V_1 ( V_2 ) ;
F_49 ( V_2 ) ;
}
int F_50 ( struct V_24 * V_13 , struct V_6 * V_7 ,
struct V_1 * * V_60 )
{
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_51 ( sizeof( struct V_1 ) , V_61 ) ;
if ( ! V_2 )
return - V_62 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_8 = V_7 ;
V_2 -> V_48 = V_46 ;
V_2 -> V_35 = F_52 ( & V_2 -> V_58 ) ;
if ( F_53 ( V_2 -> V_35 ) ) {
V_11 = F_54 ( V_2 -> V_35 ) ;
V_2 -> V_35 = NULL ;
goto V_63;
}
F_55 ( & V_2 -> V_56 , F_45 ) ;
V_2 -> V_57 = F_56 ( L_9 , V_64 ,
V_13 -> V_65 ) ;
if ( ! V_2 -> V_57 ) {
V_11 = - V_62 ;
goto V_63;
}
* V_60 = V_2 ;
F_57 ( V_2 -> V_57 , & V_2 -> V_56 , 0 ) ;
return 0 ;
V_63:
if ( V_2 -> V_35 )
F_58 ( V_2 -> V_35 ) ;
F_59 ( V_2 ) ;
return V_11 ;
}
void F_60 ( struct V_1 * V_2 )
{
F_61 ( & V_2 -> V_56 ) ;
F_62 ( V_2 -> V_57 ) ;
F_58 ( V_2 -> V_35 ) ;
F_59 ( V_2 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
F_61 ( & V_2 -> V_56 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
F_57 ( V_2 -> V_57 , & V_2 -> V_56 , V_49 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
V_2 -> V_48 = V_46 ;
}
void F_49 ( struct V_1 * V_2 )
{
if ( F_42 ( V_2 ) )
F_47 ( V_2 -> V_57 , & V_2 -> V_56 , 0 ) ;
}
