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
while ( ( V_25 -> V_13 * 1000 ) != V_21 -> V_33 ) {
if ( V_25 -> V_13 == 0 )
return - V_34 ;
V_25 ++ ;
}
F_15 ( V_23 -> V_35 ) ;
V_17 = V_25 -> V_17 ;
if ( V_23 -> V_36 & V_37 ) {
V_32 = V_25 -> V_32 ;
if ( F_3 ( V_16 + V_38 ) & V_39 )
V_32 = F_3 ( V_16 + V_40 ) &
( V_41 | V_42 ) ;
}
if ( V_27 > V_21 -> V_43 || V_21 -> V_43 > V_21 -> V_33 ) {
unsigned long V_44 = F_16 ( V_21 -> V_43 , V_21 -> V_33 ) ;
V_29 = F_17 ( V_27 , V_44 ) - 1 ;
F_18 ( V_29 >= V_45 ) ;
if ( V_23 -> V_36 & V_46 ) {
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
if ( V_23 -> V_36 & V_37 ) {
F_12 ( V_32 , V_16 + V_40 ) ;
F_1 ( V_16 + V_50 ,
V_49 ) ;
}
F_19 ( V_23 -> V_35 ) ;
return 0 ;
}
static int F_20 ( struct V_20 * V_21 ,
struct V_22 * V_23 , void T_1 * V_16 )
{
const struct V_24 * V_25 = V_23 -> V_26 ;
unsigned long div = 0 , V_51 = V_31 ;
unsigned long V_6 ;
if ( V_23 -> V_36 & V_46 ) {
while ( ( V_25 -> V_13 * 1000 ) != V_21 -> V_33 ) {
if ( V_25 -> V_13 == 0 )
return - V_34 ;
V_25 ++ ;
}
}
F_15 ( V_23 -> V_35 ) ;
V_6 = F_3 ( V_16 + V_38 ) ;
F_12 ( V_6 & ~ ( 1 << 16 ) , V_16 + V_38 ) ;
F_6 ( V_16 + V_48 , 16 , 1 ) ;
if ( V_23 -> V_36 & V_46 ) {
div |= ( V_25 -> V_17 & V_47 ) ;
V_51 |= V_47 ;
}
F_11 ( V_16 , div , V_51 ) ;
F_19 ( V_23 -> V_35 ) ;
return 0 ;
}
static int F_21 ( struct V_52 * V_53 ,
unsigned long V_54 , void * V_55 )
{
struct V_20 * V_21 = V_55 ;
struct V_22 * V_23 ;
void T_1 * V_16 ;
int V_56 = 0 ;
V_23 = F_22 ( V_53 , struct V_22 , V_57 ) ;
V_16 = V_23 -> V_58 ;
if ( V_54 == V_59 )
V_56 = F_13 ( V_21 , V_23 , V_16 ) ;
else if ( V_54 == V_60 )
V_56 = F_20 ( V_21 , V_23 , V_16 ) ;
return F_23 ( V_56 ) ;
}
int T_3 F_24 ( struct V_61 * V_62 ,
unsigned int V_63 , const char * V_64 , const char * V_14 ,
const char * V_28 , unsigned long V_65 ,
const struct V_24 * V_26 ,
unsigned long V_66 , unsigned long V_36 )
{
struct V_22 * V_23 ;
struct V_67 V_68 ;
struct V_69 * V_69 ;
int V_70 = 0 ;
V_23 = F_25 ( sizeof( * V_23 ) , V_71 ) ;
if ( ! V_23 )
return - V_72 ;
V_68 . V_64 = V_64 ;
V_68 . V_36 = V_73 ;
V_68 . V_74 = & V_14 ;
V_68 . V_75 = 1 ;
V_68 . V_76 = & V_77 ;
V_23 -> V_11 . V_68 = & V_68 ;
V_23 -> V_58 = V_62 -> V_78 + V_65 ;
V_23 -> V_35 = & V_62 -> V_35 ;
V_23 -> V_36 = V_36 ;
V_23 -> V_57 . V_79 = F_21 ;
V_23 -> V_28 = F_26 ( V_28 ) ;
if ( ! V_23 -> V_28 ) {
F_5 ( L_3 ,
V_5 , V_28 ) ;
V_70 = - V_34 ;
goto V_80;
}
V_69 = F_26 ( V_14 ) ;
if ( ! V_69 ) {
F_5 ( L_4 ,
V_5 , V_14 ) ;
V_70 = - V_34 ;
goto V_80;
}
V_70 = F_27 ( V_69 , & V_23 -> V_57 ) ;
if ( V_70 ) {
F_5 ( L_5 ,
V_5 , V_64 ) ;
goto V_80;
}
V_23 -> V_26 = F_28 ( V_26 , sizeof( * V_26 ) * V_66 , V_71 ) ;
if ( ! V_23 -> V_26 ) {
F_5 ( L_6 ,
V_5 ) ;
V_70 = - V_72 ;
goto V_81;
}
V_69 = F_29 ( NULL , & V_23 -> V_11 ) ;
if ( F_30 ( V_69 ) ) {
F_5 ( L_7 , V_5 , V_64 ) ;
V_70 = F_31 ( V_69 ) ;
goto V_82;
}
F_32 ( V_62 , V_69 , V_63 ) ;
return 0 ;
V_82:
F_33 ( V_23 -> V_26 ) ;
V_81:
F_34 ( F_26 ( V_14 ) , & V_23 -> V_57 ) ;
V_80:
F_33 ( V_23 ) ;
return V_70 ;
}
