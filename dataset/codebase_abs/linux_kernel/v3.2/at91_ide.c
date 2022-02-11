static void F_1 ( const T_1 V_1 , const T_2 V_2 ,
const T_2 V_3 , const T_2 V_4 ,
const T_2 V_5 , int V_6 )
{
unsigned long V_7 = V_8 | V_9 |
V_10 ;
if ( V_6 )
V_7 |= V_11 ;
if ( V_5 )
V_7 |= F_2 ( V_5 ) ;
F_3 ( F_4 ( V_1 ) , V_7 ) ;
F_3 ( F_5 ( V_1 ) , F_6 ( V_3 ) |
F_7 ( 0 ) |
F_8 ( V_3 ) |
F_9 ( 0 ) ) ;
F_3 ( F_10 ( V_1 ) , F_11 ( V_4 ) |
F_12 ( V_2 ) |
F_13 ( V_4 ) |
F_14 ( V_2 ) ) ;
F_3 ( F_15 ( V_1 ) , F_16 ( V_2 ) |
F_17 ( V_2 ) ) ;
}
static unsigned int F_18 ( unsigned int V_12 , unsigned int V_13 )
{
T_3 V_14 = V_12 ;
V_14 *= V_13 ;
V_14 += 1000 * 1000 * 1000 - 1 ;
F_19 ( V_14 , 1000 * 1000 * 1000 ) ;
return ( unsigned int ) V_14 ;
}
static void F_20 ( const T_1 V_1 , const T_1 V_15 ,
const struct V_16 * V_17 , int V_6 )
{
unsigned int V_18 , V_19 , V_20 , V_21 ;
unsigned int V_2 , V_3 , V_4 , V_5 ;
unsigned int V_13 ;
struct V_22 * V_23 ;
V_18 = V_17 -> V_24 ;
V_19 = V_17 -> V_3 ;
V_20 = V_17 -> V_25 ;
V_21 = ( V_15 < 5 ) ? 30 : 20 ;
F_21 ( L_1 , V_18 , V_19 , V_20 , V_21 ) ;
V_23 = F_22 ( NULL , L_2 ) ;
F_23 ( F_24 ( V_23 ) ) ;
V_13 = F_25 ( V_23 ) ;
F_21 ( L_3 , V_13 ) ;
V_2 = F_18 ( V_18 , V_13 ) ;
V_3 = F_18 ( V_19 , V_13 ) ;
V_4 = F_18 ( V_20 , V_13 ) ;
V_5 = F_18 ( V_21 , V_13 ) ;
F_21 ( L_4 ,
V_2 , V_3 , V_4 , V_5 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static void F_26 ( T_4 * V_26 , struct V_27 * V_28 ,
void * V_29 , unsigned int V_30 )
{
T_5 * V_31 = V_26 -> V_31 ;
struct V_32 * V_33 = & V_31 -> V_33 ;
T_1 V_1 = V_31 -> V_34 ;
unsigned long V_7 ;
F_21 ( L_5 , V_1 , V_29 , V_30 ) ;
V_30 ++ ;
F_27 ( V_1 , V_7 ) ;
F_28 ( ( void V_35 * ) V_33 -> V_36 , V_29 , V_30 / 2 ) ;
F_29 ( V_1 , V_7 ) ;
}
static void F_30 ( T_4 * V_26 , struct V_27 * V_28 ,
void * V_29 , unsigned int V_30 )
{
T_5 * V_31 = V_26 -> V_31 ;
struct V_32 * V_33 = & V_31 -> V_33 ;
T_1 V_1 = V_31 -> V_34 ;
unsigned long V_7 ;
F_21 ( L_5 , V_1 , V_29 , V_30 ) ;
F_27 ( V_1 , V_7 ) ;
F_31 ( ( void V_35 * ) V_33 -> V_36 , V_29 , V_30 / 2 ) ;
F_29 ( V_1 , V_7 ) ;
}
static void F_32 ( T_5 * V_31 , T_4 * V_26 )
{
struct V_16 * V_17 ;
T_1 V_1 = V_31 -> V_34 ;
int V_6 = 0 ;
const T_1 V_15 = V_26 -> V_37 - V_38 ;
F_21 ( L_6 , V_1 , V_15 ) ;
V_17 = F_33 ( V_38 + V_15 ) ;
F_23 ( ! V_17 ) ;
if ( F_34 ( V_26 , V_15 ) )
V_6 = 1 ;
F_20 ( V_1 , V_15 , V_17 , V_6 ) ;
}
T_6 F_35 ( int V_39 , void * V_40 )
{
int V_41 = 8 ;
int V_42 , V_43 ;
do {
V_42 = F_36 ( V_39 ) ;
V_43 = F_36 ( V_39 ) ;
} while ( V_42 != V_43 && -- V_41 > 0 );
if ( V_42 == 0 || V_41 <= 0 )
return V_44 ;
return F_37 ( V_39 , V_40 ) ;
}
static int T_7 F_38 ( struct V_45 * V_46 )
{
int V_47 ;
struct V_48 V_49 , * V_50 [] = { & V_49 } ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
unsigned long V_55 = 0 , V_56 = 0 ;
struct V_57 * V_58 = V_46 -> V_59 . V_60 ;
if ( ! V_58 )
return - V_61 ;
if ( V_58 -> V_62 && F_36 ( V_58 -> V_62 ) != 0 ) {
F_39 ( L_7 ) ;
return - V_61 ;
}
V_54 = F_40 ( V_46 , V_63 , 0 ) ;
if ( ! V_54 ) {
F_39 ( L_8 ) ;
return - V_61 ;
}
if ( ! F_41 ( & V_46 -> V_59 , V_54 -> V_64 + V_65 ,
V_66 , L_9 ) ||
! F_41 ( & V_46 -> V_59 , V_54 -> V_64 + V_67 ,
V_66 , L_10 ) ) {
F_39 ( L_11 ) ;
return - V_68 ;
}
F_21 ( L_12 , V_58 -> V_1 ,
V_58 -> V_69 , ( unsigned long ) V_54 -> V_64 ) ;
V_55 = ( unsigned long ) F_42 ( & V_46 -> V_59 , V_54 -> V_64 + V_65 ,
V_66 ) ;
V_56 = ( unsigned long ) F_42 ( & V_46 -> V_59 , V_54 -> V_64 + V_67 ,
V_66 ) ;
if ( ! V_55 || ! V_56 ) {
F_39 ( L_13 ) ;
return - V_68 ;
}
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
if ( V_58 -> V_70 & V_71 ) {
V_49 . V_33 . V_36 = V_55 + 0 ;
V_49 . V_33 . V_72 = V_55 + 4 ;
V_49 . V_33 . V_73 = V_55 + 2 ;
V_49 . V_33 . V_74 = V_55 + 6 ;
V_49 . V_33 . V_75 = V_55 + 1 ;
V_49 . V_33 . V_76 = V_55 + 5 ;
V_49 . V_33 . V_77 = V_55 + 3 ;
V_49 . V_33 . V_78 = V_55 + 7 ;
V_49 . V_33 . V_79 = V_56 + 3 ;
} else
F_43 ( & V_49 , V_55 , V_56 + 6 ) ;
V_49 . V_39 = V_58 -> V_69 ;
V_49 . V_59 = & V_46 -> V_59 ;
V_52 = F_44 ( & V_80 , V_50 , 1 ) ;
if ( ! V_52 ) {
F_39 ( L_14 ) ;
return - V_81 ;
}
F_20 ( V_58 -> V_1 , 0 , F_33 ( V_38 ) , 0 ) ;
if ( V_58 -> V_69 >= V_82 )
V_52 -> V_83 = F_35 ;
V_52 -> V_84 [ 0 ] -> V_34 = V_58 -> V_1 ;
V_47 = F_45 ( V_52 , & V_80 , V_50 ) ;
if ( V_47 ) {
F_39 ( L_15 ) ;
goto V_85;
}
F_46 ( V_46 , V_52 ) ;
return 0 ;
V_85:
F_47 ( V_52 ) ;
return V_47 ;
}
static int T_8 F_48 ( struct V_45 * V_46 )
{
struct V_51 * V_52 = F_49 ( V_46 ) ;
F_50 ( V_52 ) ;
return 0 ;
}
static int T_7 F_51 ( void )
{
return F_52 ( & V_86 , F_38 ) ;
}
static void T_8 F_53 ( void )
{
F_54 ( & V_86 ) ;
}
