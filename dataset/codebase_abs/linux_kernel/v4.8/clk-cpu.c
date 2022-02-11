static void F_1 ( void T_1 * V_1 , unsigned long V_2 )
{
unsigned long V_3 = V_4 + F_2 ( 10 ) ;
do {
if ( ! ( F_3 ( V_1 ) & V_2 ) )
return;
} while ( F_4 ( V_4 , V_3 ) );
if ( ! ( F_3 ( V_1 ) & V_2 ) )
return;
F_5 ( L_1 , V_5 ) ;
}
static void F_6 ( void T_1 * V_6 , T_2 V_7 ,
unsigned long V_8 )
{
unsigned long V_3 = V_4 + F_2 ( 10 ) ;
do {
if ( ( ( F_3 ( V_6 ) >> V_7 ) & V_9 ) == V_8 )
return;
} while ( F_4 ( V_4 , V_3 ) );
if ( ( ( F_3 ( V_6 ) >> V_7 ) & V_9 ) == V_8 )
return;
F_5 ( L_2 , V_5 ) ;
}
static long F_7 ( struct V_10 * V_11 ,
unsigned long V_12 , unsigned long * V_13 )
{
struct V_10 * V_14 = F_8 ( V_11 ) ;
* V_13 = F_9 ( V_14 , V_12 ) ;
return * V_13 ;
}
static unsigned long F_10 ( struct V_10 * V_11 ,
unsigned long V_15 )
{
return V_15 ;
}
static void F_11 ( void T_1 * V_16 , unsigned long div ,
unsigned long V_2 )
{
unsigned long V_17 ;
V_17 = F_3 ( V_16 + V_18 ) ;
V_17 = ( V_17 & ~ V_2 ) | ( div & V_2 ) ;
F_12 ( V_17 , V_16 + V_18 ) ;
F_1 ( V_16 + V_19 , V_2 ) ;
}
static int F_13 ( struct V_20 * V_21 ,
struct V_22 * V_23 , void T_1 * V_16 )
{
const struct V_24 * V_25 = V_23 -> V_26 ;
unsigned long V_27 = F_14 ( V_23 -> V_28 ) ;
unsigned long V_29 = 0 , V_30 = V_31 ;
unsigned long V_17 , V_32 = 0 , V_6 ;
unsigned long V_33 ;
while ( ( V_25 -> V_13 * 1000 ) != V_21 -> V_34 ) {
if ( V_25 -> V_13 == 0 )
return - V_35 ;
V_25 ++ ;
}
F_15 ( V_23 -> V_36 , V_33 ) ;
V_17 = V_25 -> V_17 ;
if ( V_23 -> V_33 & V_37 ) {
V_32 = V_25 -> V_32 ;
if ( F_3 ( V_16 + V_38 ) & V_39 )
V_32 = F_3 ( V_16 + V_40 ) &
( V_41 | V_42 ) ;
}
if ( V_27 > V_21 -> V_43 || V_21 -> V_43 > V_21 -> V_34 ) {
unsigned long V_44 = F_16 ( V_21 -> V_43 , V_21 -> V_34 ) ;
V_29 = F_17 ( V_27 , V_44 ) - 1 ;
F_18 ( V_29 >= V_45 ) ;
if ( V_23 -> V_33 & V_46 ) {
V_29 |= V_47 ;
V_30 |= V_47 ;
}
F_11 ( V_16 , V_29 , V_30 ) ;
V_17 |= V_29 ;
}
V_6 = F_3 ( V_16 + V_38 ) ;
F_12 ( V_6 | ( 1 << 16 ) , V_16 + V_38 ) ;
F_6 ( V_16 + V_48 , 16 , 2 ) ;
F_12 ( V_17 , V_16 + V_18 ) ;
F_1 ( V_16 + V_19 , V_49 ) ;
if ( V_23 -> V_33 & V_37 ) {
F_12 ( V_32 , V_16 + V_40 ) ;
F_1 ( V_16 + V_50 ,
V_49 ) ;
}
F_19 ( V_23 -> V_36 , V_33 ) ;
return 0 ;
}
static int F_20 ( struct V_20 * V_21 ,
struct V_22 * V_23 , void T_1 * V_16 )
{
const struct V_24 * V_25 = V_23 -> V_26 ;
unsigned long div = 0 , V_51 = V_31 ;
unsigned long V_6 ;
unsigned long V_33 ;
if ( V_23 -> V_33 & V_46 ) {
while ( ( V_25 -> V_13 * 1000 ) != V_21 -> V_34 ) {
if ( V_25 -> V_13 == 0 )
return - V_35 ;
V_25 ++ ;
}
}
F_15 ( V_23 -> V_36 , V_33 ) ;
V_6 = F_3 ( V_16 + V_38 ) ;
F_12 ( V_6 & ~ ( 1 << 16 ) , V_16 + V_38 ) ;
F_6 ( V_16 + V_48 , 16 , 1 ) ;
if ( V_23 -> V_33 & V_46 ) {
div |= ( V_25 -> V_17 & V_47 ) ;
V_51 |= V_47 ;
}
F_11 ( V_16 , div , V_51 ) ;
F_19 ( V_23 -> V_36 , V_33 ) ;
return 0 ;
}
static void F_21 ( void T_1 * V_16 , unsigned long div ,
unsigned long V_2 )
{
unsigned long V_17 ;
V_17 = F_3 ( V_16 + V_52 ) ;
V_17 = ( V_17 & ~ V_2 ) | ( div & V_2 ) ;
F_12 ( V_17 , V_16 + V_52 ) ;
F_1 ( V_16 + V_53 , V_2 ) ;
}
static int F_22 ( struct V_20 * V_21 ,
struct V_22 * V_23 , void T_1 * V_16 )
{
const struct V_24 * V_25 = V_23 -> V_26 ;
unsigned long V_27 = F_14 ( V_23 -> V_28 ) ;
unsigned long V_29 = 0 , V_30 = V_31 ;
unsigned long V_17 , V_32 = 0 , V_6 ;
unsigned long V_33 ;
while ( ( V_25 -> V_13 * 1000 ) != V_21 -> V_34 ) {
if ( V_25 -> V_13 == 0 )
return - V_35 ;
V_25 ++ ;
}
F_15 ( V_23 -> V_36 , V_33 ) ;
V_17 = V_25 -> V_17 ;
V_32 = V_25 -> V_32 ;
if ( V_27 > V_21 -> V_43 || V_21 -> V_43 > V_21 -> V_34 ) {
unsigned long V_44 = F_16 ( V_21 -> V_43 , V_21 -> V_34 ) ;
V_29 = F_17 ( V_27 , V_44 ) - 1 ;
F_18 ( V_29 >= V_45 ) ;
F_21 ( V_16 , V_29 , V_30 ) ;
V_17 |= V_29 ;
}
V_6 = F_3 ( V_16 + V_54 ) ;
F_12 ( V_6 | 1 , V_16 + V_54 ) ;
F_6 ( V_16 + V_55 , 0 , 2 ) ;
F_12 ( V_17 , V_16 + V_52 ) ;
F_1 ( V_16 + V_53 , V_49 ) ;
F_12 ( V_32 , V_16 + V_56 ) ;
F_1 ( V_16 + V_57 , V_49 ) ;
F_19 ( V_23 -> V_36 , V_33 ) ;
return 0 ;
}
static int F_23 ( struct V_20 * V_21 ,
struct V_22 * V_23 , void T_1 * V_16 )
{
unsigned long div = 0 , V_51 = V_31 ;
unsigned long V_6 ;
unsigned long V_33 ;
F_15 ( V_23 -> V_36 , V_33 ) ;
V_6 = F_3 ( V_16 + V_54 ) ;
F_12 ( V_6 & ~ 1 , V_16 + V_54 ) ;
F_6 ( V_16 + V_55 , 0 , 1 ) ;
F_21 ( V_16 , div , V_51 ) ;
F_19 ( V_23 -> V_36 , V_33 ) ;
return 0 ;
}
static int F_24 ( struct V_58 * V_59 ,
unsigned long V_60 , void * V_61 )
{
struct V_20 * V_21 = V_61 ;
struct V_22 * V_23 ;
void T_1 * V_16 ;
int V_62 = 0 ;
V_23 = F_25 ( V_59 , struct V_22 , V_63 ) ;
V_16 = V_23 -> V_64 ;
if ( V_60 == V_65 )
V_62 = F_13 ( V_21 , V_23 , V_16 ) ;
else if ( V_60 == V_66 )
V_62 = F_20 ( V_21 , V_23 , V_16 ) ;
return F_26 ( V_62 ) ;
}
static int F_27 ( struct V_58 * V_59 ,
unsigned long V_60 , void * V_61 )
{
struct V_20 * V_21 = V_61 ;
struct V_22 * V_23 ;
void T_1 * V_16 ;
int V_62 = 0 ;
V_23 = F_25 ( V_59 , struct V_22 , V_63 ) ;
V_16 = V_23 -> V_64 ;
if ( V_60 == V_65 )
V_62 = F_22 ( V_21 , V_23 , V_16 ) ;
else if ( V_60 == V_66 )
V_62 = F_23 ( V_21 , V_23 , V_16 ) ;
return F_26 ( V_62 ) ;
}
int T_3 F_28 ( struct V_67 * V_68 ,
unsigned int V_69 , const char * V_70 , const char * V_14 ,
const char * V_28 , unsigned long V_71 ,
const struct V_24 * V_26 ,
unsigned long V_72 , unsigned long V_33 )
{
struct V_22 * V_23 ;
struct V_73 V_74 ;
struct V_75 * V_75 ;
int V_76 = 0 ;
V_23 = F_29 ( sizeof( * V_23 ) , V_77 ) ;
if ( ! V_23 )
return - V_78 ;
V_74 . V_70 = V_70 ;
V_74 . V_33 = V_79 ;
V_74 . V_80 = & V_14 ;
V_74 . V_81 = 1 ;
V_74 . V_82 = & V_83 ;
V_23 -> V_11 . V_74 = & V_74 ;
V_23 -> V_64 = V_68 -> V_84 + V_71 ;
V_23 -> V_36 = & V_68 -> V_36 ;
V_23 -> V_33 = V_33 ;
if ( V_33 & V_85 )
V_23 -> V_63 . V_86 = F_27 ;
else
V_23 -> V_63 . V_86 = F_24 ;
V_23 -> V_28 = F_30 ( V_28 ) ;
if ( ! V_23 -> V_28 ) {
F_5 ( L_3 ,
V_5 , V_28 ) ;
V_76 = - V_35 ;
goto V_87;
}
V_75 = F_30 ( V_14 ) ;
if ( ! V_75 ) {
F_5 ( L_4 ,
V_5 , V_14 ) ;
V_76 = - V_35 ;
goto V_87;
}
V_76 = F_31 ( V_75 , & V_23 -> V_63 ) ;
if ( V_76 ) {
F_5 ( L_5 ,
V_5 , V_70 ) ;
goto V_87;
}
V_23 -> V_26 = F_32 ( V_26 , sizeof( * V_26 ) * V_72 , V_77 ) ;
if ( ! V_23 -> V_26 ) {
F_5 ( L_6 ,
V_5 ) ;
V_76 = - V_78 ;
goto V_88;
}
V_75 = F_33 ( NULL , & V_23 -> V_11 ) ;
if ( F_34 ( V_75 ) ) {
F_5 ( L_7 , V_5 , V_70 ) ;
V_76 = F_35 ( V_75 ) ;
goto V_89;
}
F_36 ( V_68 , V_75 , V_69 ) ;
return 0 ;
V_89:
F_37 ( V_23 -> V_26 ) ;
V_88:
F_38 ( F_30 ( V_14 ) , & V_23 -> V_63 ) ;
V_87:
F_37 ( V_23 ) ;
return V_76 ;
}
