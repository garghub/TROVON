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
struct V_14 * V_15 = F_8 ( V_11 -> V_14 ) ;
* V_13 = F_9 ( V_15 , V_12 ) ;
return * V_13 ;
}
static unsigned long F_10 ( struct V_10 * V_11 ,
unsigned long V_16 )
{
return V_16 ;
}
static void F_11 ( void T_1 * V_17 , unsigned long div ,
unsigned long V_2 )
{
unsigned long V_18 ;
V_18 = F_3 ( V_17 + V_19 ) ;
V_18 = ( V_18 & ~ V_2 ) | ( div & V_2 ) ;
F_12 ( V_18 , V_17 + V_19 ) ;
F_1 ( V_17 + V_20 , V_2 ) ;
}
static int F_13 ( struct V_21 * V_22 ,
struct V_23 * V_24 , void T_1 * V_17 )
{
const struct V_25 * V_26 = V_24 -> V_27 ;
unsigned long V_28 = F_14 ( V_24 -> V_29 ) ;
unsigned long V_30 = 0 , V_31 = V_32 ;
unsigned long V_18 , V_33 = 0 , V_6 ;
while ( ( V_26 -> V_13 * 1000 ) != V_22 -> V_34 ) {
if ( V_26 -> V_13 == 0 )
return - V_35 ;
V_26 ++ ;
}
F_15 ( V_24 -> V_36 ) ;
V_18 = V_26 -> V_18 ;
if ( F_16 ( V_37 , & V_24 -> V_38 ) ) {
V_33 = V_26 -> V_33 ;
if ( F_3 ( V_17 + V_39 ) & V_40 )
V_33 = F_3 ( V_17 + V_41 ) &
( V_42 | V_43 ) ;
}
if ( V_28 > V_22 -> V_44 || V_22 -> V_44 > V_22 -> V_34 ) {
unsigned long V_45 = F_17 ( V_22 -> V_44 , V_22 -> V_34 ) ;
V_30 = F_18 ( V_28 , V_45 ) - 1 ;
F_19 ( V_30 >= V_46 ) ;
if ( F_16 ( V_47 , & V_24 -> V_38 ) ) {
V_30 |= V_48 ;
V_31 |= V_48 ;
}
F_11 ( V_17 , V_30 , V_31 ) ;
V_18 |= V_30 ;
}
V_6 = F_3 ( V_17 + V_39 ) ;
F_12 ( V_6 | ( 1 << 16 ) , V_17 + V_39 ) ;
F_6 ( V_17 + V_49 , 16 , 2 ) ;
F_12 ( V_18 , V_17 + V_19 ) ;
F_1 ( V_17 + V_20 , V_50 ) ;
if ( F_16 ( V_37 , & V_24 -> V_38 ) ) {
F_12 ( V_33 , V_17 + V_41 ) ;
F_1 ( V_17 + V_51 ,
V_50 ) ;
}
F_20 ( V_24 -> V_36 ) ;
return 0 ;
}
static int F_21 ( struct V_21 * V_22 ,
struct V_23 * V_24 , void T_1 * V_17 )
{
const struct V_25 * V_26 = V_24 -> V_27 ;
unsigned long div = 0 , V_52 = V_32 ;
unsigned long V_6 ;
if ( F_16 ( V_47 , & V_24 -> V_38 ) ) {
while ( ( V_26 -> V_13 * 1000 ) != V_22 -> V_34 ) {
if ( V_26 -> V_13 == 0 )
return - V_35 ;
V_26 ++ ;
}
}
F_15 ( V_24 -> V_36 ) ;
V_6 = F_3 ( V_17 + V_39 ) ;
F_12 ( V_6 & ~ ( 1 << 16 ) , V_17 + V_39 ) ;
F_6 ( V_17 + V_49 , 16 , 1 ) ;
if ( F_16 ( V_47 , & V_24 -> V_38 ) ) {
div |= ( V_26 -> V_18 & V_48 ) ;
V_52 |= V_48 ;
}
F_11 ( V_17 , div , V_52 ) ;
F_20 ( V_24 -> V_36 ) ;
return 0 ;
}
static int F_22 ( struct V_53 * V_54 ,
unsigned long V_55 , void * V_56 )
{
struct V_21 * V_22 = V_56 ;
struct V_23 * V_24 ;
void T_1 * V_17 ;
int V_57 = 0 ;
V_24 = F_23 ( V_54 , struct V_23 , V_58 ) ;
V_17 = V_24 -> V_59 ;
if ( V_55 == V_60 )
V_57 = F_13 ( V_22 , V_24 , V_17 ) ;
else if ( V_55 == V_61 )
V_57 = F_21 ( V_22 , V_24 , V_17 ) ;
return F_24 ( V_57 ) ;
}
int T_3 F_25 ( struct V_62 * V_63 ,
unsigned int V_64 , const char * V_65 , const char * V_15 ,
const char * V_29 , unsigned long V_66 ,
const struct V_25 * V_27 ,
unsigned long V_67 , unsigned long V_38 )
{
struct V_23 * V_24 ;
struct V_68 V_69 ;
struct V_14 * V_14 ;
int V_70 = 0 ;
V_24 = F_26 ( sizeof( * V_24 ) , V_71 ) ;
if ( ! V_24 )
return - V_72 ;
V_69 . V_65 = V_65 ;
V_69 . V_38 = V_73 ;
V_69 . V_74 = & V_15 ;
V_69 . V_75 = 1 ;
V_69 . V_76 = & V_77 ;
V_24 -> V_11 . V_69 = & V_69 ;
V_24 -> V_59 = V_63 -> V_78 + V_66 ;
V_24 -> V_36 = & V_63 -> V_36 ;
V_24 -> V_38 = V_38 ;
V_24 -> V_58 . V_79 = F_22 ;
V_24 -> V_29 = F_27 ( V_29 ) ;
if ( ! V_24 -> V_29 ) {
F_5 ( L_3 ,
V_5 , V_29 ) ;
V_70 = - V_35 ;
goto V_80;
}
V_14 = F_27 ( V_15 ) ;
if ( ! V_14 ) {
F_5 ( L_4 ,
V_5 , V_15 ) ;
V_70 = - V_35 ;
goto V_80;
}
V_70 = F_28 ( V_14 , & V_24 -> V_58 ) ;
if ( V_70 ) {
F_5 ( L_5 ,
V_5 , V_65 ) ;
goto V_80;
}
V_24 -> V_27 = F_29 ( V_27 , sizeof( * V_27 ) * V_67 , V_71 ) ;
if ( ! V_24 -> V_27 ) {
F_5 ( L_6 ,
V_5 ) ;
V_70 = - V_72 ;
goto V_81;
}
V_14 = F_30 ( NULL , & V_24 -> V_11 ) ;
if ( F_31 ( V_14 ) ) {
F_5 ( L_7 , V_5 , V_65 ) ;
V_70 = F_32 ( V_14 ) ;
goto V_82;
}
F_33 ( V_63 , V_14 , V_64 ) ;
return 0 ;
V_82:
F_34 ( V_24 -> V_27 ) ;
V_81:
F_35 ( F_27 ( V_15 ) , & V_24 -> V_58 ) ;
V_80:
F_34 ( V_24 ) ;
return V_70 ;
}
