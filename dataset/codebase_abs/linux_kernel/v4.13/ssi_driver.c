void F_1 ( const char * V_1 , const T_1 * V_2 , unsigned long V_3 )
{
int V_4 , V_5 = 0 , V_6 = 0 ;
const T_1 * V_7 ;
char V_8 [ 80 ] ;
if ( ! V_2 ) {
F_2 ( L_1 ) ;
return;
}
V_6 = snprintf ( V_8 , sizeof( V_8 ) , L_2 ,
V_1 , V_3 ) ;
if ( V_6 < 0 ) {
F_2 ( L_3 , V_6 ) ;
return;
}
V_5 = V_6 ;
for ( V_4 = 0 , V_7 = V_2 ;
( V_4 < V_3 ) && ( V_5 < sizeof( V_8 ) ) ; V_4 ++ , V_7 ++ ) {
V_6 = snprintf ( V_8 + V_5 ,
sizeof( V_8 ) - V_5 ,
L_4 , * V_7 ) ;
if ( V_6 < 0 ) {
F_2 ( L_3 , V_6 ) ;
return;
}
V_5 += V_6 ;
if ( V_5 > 75 ) {
F_3 ( L_5 , V_8 ) ;
V_5 = 0 ;
}
}
if ( V_5 > 0 )
F_3 ( L_5 , V_8 ) ;
}
static T_2 F_4 ( int V_9 , void * V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_10 ;
void T_3 * V_13 = V_12 -> V_13 ;
T_4 V_14 ;
T_4 V_15 ;
V_14 = F_5 ( F_6 ( V_16 , V_17 ) ) ;
F_3 ( L_6 , V_14 ) ;
if ( F_7 ( V_14 == 0 ) ) {
F_2 ( L_7 ) ;
return V_18 ;
}
V_15 = F_5 ( F_6 ( V_16 , V_19 ) ) ;
F_8 ( F_6 ( V_16 , V_20 ) , V_14 ) ;
V_12 -> V_9 = V_14 ;
if ( F_9 ( ( V_14 & V_21 ) != 0 ) ) {
F_8 ( F_6 ( V_16 , V_19 ) , V_15 | V_21 ) ;
V_14 &= ~ V_21 ;
F_10 ( V_12 ) ;
}
#ifdef F_11
if ( F_9 ( ( V_14 & V_22 ) != 0 ) ) {
F_8 ( F_6 ( V_16 , V_19 ) , V_15 | V_22 ) ;
V_14 &= ~ V_22 ;
F_12 ( V_12 ) ;
}
#endif
if ( F_7 ( ( V_14 & V_23 ) != 0 ) ) {
T_4 V_24 ;
V_24 = F_5 ( F_6 ( V_25 , V_26 ) ) ;
F_3 ( L_8 , V_24 ) ;
V_14 &= ~ V_23 ;
}
if ( F_7 ( V_14 != 0 ) ) {
F_3 ( L_9 , V_14 ) ;
}
return V_27 ;
}
int F_13 ( struct V_11 * V_12 , bool V_28 )
{
unsigned int V_29 , V_30 ;
void T_3 * V_13 = V_12 -> V_13 ;
V_29 = F_5 ( F_6 ( V_25 , V_31 ) ) ;
F_8 ( F_6 ( V_25 , V_31 ) , V_29 & ~ V_32 ) ;
F_3 ( L_10 , F_5 ( F_6 ( V_25 , V_31 ) ) ) ;
V_29 = F_5 ( F_6 ( V_16 , V_17 ) ) ;
F_3 ( L_11 , V_29 ) ;
F_8 ( F_6 ( V_16 , V_20 ) , V_29 ) ;
V_29 = ( ~ ( V_21 | V_23 | V_22 ) ) ;
F_8 ( F_6 ( V_16 , V_19 ) , V_29 ) ;
#ifdef F_14
#ifdef F_15
F_8 ( F_6 ( V_16 , V_33 ) ,
F_15 ) ;
#endif
if ( F_5 ( F_6 ( V_16 , V_33 ) ) > 0 ) {
F_3 ( L_12 ,
F_5 ( F_6 ( V_16 , V_33 ) ) ) ;
}
#endif
V_30 = ( V_12 -> V_34 ? V_35 : 0x0 ) ;
V_29 = F_5 ( F_6 ( V_25 , V_36 ) ) ;
if ( V_28 )
F_16 ( L_13 , V_29 ) ;
F_8 ( F_6 ( V_25 , V_36 ) ,
V_30 ) ;
V_29 = F_5 ( F_6 ( V_25 , V_36 ) ) ;
if ( V_28 )
F_16 ( L_14 ,
V_29 , V_30 ) ;
return 0 ;
}
static int F_17 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = NULL ;
void T_3 * V_13 = NULL ;
bool V_41 = false ;
struct V_11 * V_42 = F_18 ( sizeof( struct V_11 ) , V_43 ) ;
struct V_44 * V_45 = & V_38 -> V_45 ;
struct V_46 * V_47 = V_45 -> V_48 ;
T_4 V_49 ;
int V_50 = 0 ;
if ( F_7 ( ! V_42 ) ) {
F_2 ( L_15 ) ;
V_50 = - V_51 ;
goto V_52;
}
V_42 -> V_53 = F_19 ( V_47 , 0 ) ;
V_42 -> V_34 = F_20 ( V_47 ) ;
V_42 -> V_54 = 0 ;
F_21 ( & V_38 -> V_45 , V_42 ) ;
V_42 -> V_55 = F_22 ( V_38 , V_56 , 0 ) ;
if ( F_7 ( ! V_42 -> V_55 ) ) {
F_2 ( L_16 ) ;
V_50 = - V_57 ;
goto V_52;
}
F_3 ( L_17 ,
V_42 -> V_55 -> V_1 ,
( unsigned long long ) V_42 -> V_55 -> V_58 ,
( unsigned long long ) V_42 -> V_55 -> V_59 ) ;
V_40 = F_23 ( V_42 -> V_55 -> V_58 , F_24 ( V_42 -> V_55 ) , L_18 ) ;
if ( F_7 ( ! V_40 ) ) {
F_2 ( L_19
L_20 , ( unsigned int ) V_42 -> V_55 -> V_58 ) ;
V_50 = - V_60 ;
goto V_52;
}
V_13 = F_25 ( V_42 -> V_55 -> V_58 , F_24 ( V_42 -> V_55 ) ) ;
if ( F_7 ( ! V_13 ) ) {
F_2 ( L_21 ,
( unsigned int ) V_42 -> V_55 -> V_58 , ( unsigned int ) F_24 ( V_42 -> V_55 ) ) ;
V_50 = - V_51 ;
goto V_52;
}
F_3 ( L_22 , & V_42 -> V_55 -> V_58 , V_13 ) ;
V_42 -> V_13 = V_13 ;
V_42 -> V_61 = F_22 ( V_38 , V_62 , 0 ) ;
if ( F_7 ( ! V_42 -> V_61 ) ) {
F_2 ( L_23 ) ;
V_50 = - V_57 ;
goto V_52;
}
V_50 = F_26 ( V_42 -> V_61 -> V_58 , F_4 ,
V_63 , L_24 , V_42 ) ;
if ( F_7 ( V_50 != 0 ) ) {
F_2 ( L_25 ,
( unsigned long long ) V_42 -> V_61 -> V_58 ) ;
goto V_52;
}
F_27 ( & V_42 -> V_64 ) ;
V_41 = true ;
F_3 ( L_26 ,
V_42 -> V_61 -> V_1 ,
( unsigned long long ) V_42 -> V_61 -> V_58 ) ;
V_42 -> V_38 = V_38 ;
V_50 = F_28 ( V_42 ) ;
if ( V_50 )
goto V_52;
if ( ! V_42 -> V_38 -> V_45 . V_65 )
{
V_42 -> V_38 -> V_45 . V_65 = & V_42 -> V_38 -> V_45 . V_66 ;
}
if ( ! V_42 -> V_38 -> V_45 . V_66 )
{
V_42 -> V_38 -> V_45 . V_66 = F_29 ( V_67 ) ;
}
V_49 = F_5 ( F_6 ( V_16 , V_68 ) ) ;
if ( V_49 != V_69 ) {
F_2 ( L_27 ,
V_49 , ( T_4 ) V_69 ) ;
V_50 = - V_70 ;
goto V_52;
}
F_3 ( L_28 , V_49 ) ;
F_30 ( V_71 , L_29 , V_72 ,
F_5 ( F_6 ( V_16 , V_73 ) ) , V_74 ) ;
V_50 = F_13 ( V_42 , true ) ;
if ( F_7 ( V_50 != 0 ) ) {
F_2 ( L_30 ) ;
goto V_52;
}
#ifdef F_31
V_50 = F_32 ( & ( V_38 -> V_45 . V_75 ) , V_42 ) ;
if ( F_7 ( V_50 != 0 ) ) {
F_2 ( L_31 ) ;
goto V_52;
}
#endif
V_50 = F_33 ( V_42 ) ;
if ( F_7 ( V_50 != 0 ) ) {
F_2 ( L_32 ) ;
goto V_52;
}
V_42 -> V_76 =
F_34 ( V_42 , V_77 ) ;
if ( F_7 ( V_42 -> V_76 == V_78 ) ) {
F_2 ( L_33 ) ;
V_50 = - V_51 ;
goto V_52;
}
V_50 = F_35 ( V_42 ) ;
if ( F_7 ( V_50 != 0 ) ) {
F_2 ( L_34 ) ;
goto V_52;
}
V_50 = F_36 ( V_42 ) ;
if ( F_7 ( V_50 != 0 ) ) {
F_2 ( L_35 ) ;
goto V_52;
}
V_50 = F_37 ( V_42 ) ;
if ( F_7 ( V_50 != 0 ) ) {
F_2 ( L_36 ) ;
goto V_52;
}
V_50 = F_38 ( V_42 ) ;
if ( F_7 ( V_50 != 0 ) ) {
F_2 ( L_37 , V_50 ) ;
goto V_52;
}
V_50 = F_39 ( V_42 ) ;
if ( F_7 ( V_50 != 0 ) ) {
F_2 ( L_38 ) ;
goto V_52;
}
V_50 = F_40 ( V_42 ) ;
if ( F_7 ( V_50 != 0 ) ) {
F_2 ( L_39 ) ;
goto V_52;
}
V_50 = F_41 ( V_42 ) ;
if ( F_7 ( V_50 != 0 ) ) {
F_2 ( L_40 ) ;
goto V_52;
}
V_50 = F_42 ( V_42 ) ;
if ( F_7 ( V_50 != 0 ) ) {
F_2 ( L_41 ) ;
goto V_52;
}
return 0 ;
V_52:
F_2 ( L_42 ) ;
if ( V_42 ) {
F_43 ( V_42 ) ;
F_44 ( V_42 ) ;
F_45 ( V_42 ) ;
F_46 ( V_42 ) ;
F_47 ( V_42 ) ;
F_48 ( V_42 ) ;
F_49 ( V_42 ) ;
F_50 ( V_42 ) ;
F_51 ( V_42 ) ;
#ifdef F_31
F_52 () ;
#endif
if ( V_40 ) {
if ( V_41 ) {
F_53 ( V_42 -> V_61 -> V_58 , V_42 ) ;
V_42 -> V_61 = NULL ;
F_54 ( V_13 ) ;
V_42 -> V_13 = NULL ;
}
F_55 ( V_42 -> V_55 -> V_58 ,
F_24 ( V_42 -> V_55 ) ) ;
V_42 -> V_55 = NULL ;
}
F_56 ( V_42 ) ;
F_21 ( & V_38 -> V_45 , NULL ) ;
}
return V_50 ;
}
void F_57 ( struct V_11 * V_12 )
{
F_58 ( V_12 -> V_13 +
F_6 ( V_16 , V_19 ) , 0xFFFFFFFF ) ;
}
static void F_59 ( struct V_37 * V_38 )
{
struct V_11 * V_12 =
(struct V_11 * ) F_60 ( & V_38 -> V_45 ) ;
F_43 ( V_12 ) ;
F_44 ( V_12 ) ;
F_45 ( V_12 ) ;
F_46 ( V_12 ) ;
F_47 ( V_12 ) ;
F_48 ( V_12 ) ;
F_49 ( V_12 ) ;
F_50 ( V_12 ) ;
F_51 ( V_12 ) ;
#ifdef F_31
F_52 () ;
#endif
F_57 ( V_12 ) ;
F_61 ( V_12 ) ;
F_53 ( V_12 -> V_61 -> V_58 , V_12 ) ;
V_12 -> V_61 = NULL ;
if ( V_12 -> V_13 ) {
F_54 ( V_12 -> V_13 ) ;
F_55 ( V_12 -> V_55 -> V_58 ,
F_24 ( V_12 -> V_55 ) ) ;
V_12 -> V_13 = NULL ;
V_12 -> V_55 = NULL ;
}
F_56 ( V_12 ) ;
F_21 ( & V_38 -> V_45 , NULL ) ;
}
int F_28 ( struct V_11 * V_12 )
{
struct V_53 * V_53 = V_12 -> V_53 ;
int V_50 ;
if ( F_62 ( V_53 ) )
return 0 ;
V_50 = F_63 ( V_53 ) ;
if ( V_50 )
return V_50 ;
return 0 ;
}
void F_61 ( struct V_11 * V_12 )
{
struct V_53 * V_53 = V_12 -> V_53 ;
if ( F_62 ( V_53 ) )
return;
F_64 ( V_53 ) ;
}
static int F_65 ( struct V_37 * V_38 )
{
int V_50 ;
#if F_66 ( V_79 ) && F_66 ( V_80 )
T_4 V_81 , V_82 ;
asm volatile("mrc p15, 0, %0, c0, c0, 1" : "=r" (ctr));
V_82 = 4 << ( ( V_81 >> 16 ) & 0xf ) ;
F_3 ( L_43 ,
V_82 , V_83 ) ;
asm volatile("mrc p15, 0, %0, c0, c0, 0" : "=r" (ctr));
F_3 ( L_44
L_45 ,
( V_81 >> 24 ) , ( V_81 >> 16 ) & 0xF , ( V_81 >> 4 ) & 0xFFF , ( V_81 >> 20 ) & 0xF , V_81 & 0xF ) ;
#endif
V_50 = F_17 ( V_38 ) ;
if ( V_50 != 0 )
return V_50 ;
F_30 ( V_71 , L_46 ) ;
return 0 ;
}
static int F_67 ( struct V_37 * V_38 )
{
F_3 ( L_47 ) ;
F_59 ( V_38 ) ;
F_30 ( V_71 , L_48 ) ;
return 0 ;
}
