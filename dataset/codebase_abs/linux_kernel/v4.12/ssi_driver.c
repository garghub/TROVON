void F_1 ( const char * V_1 , const T_1 * V_2 , unsigned long V_3 )
{
int V_4 , V_5 = 0 , V_6 = 0 ;
const T_1 * V_7 ;
char V_8 [ 80 ] ;
if ( V_2 == NULL ) {
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
V_16 ;
F_5 () ;
V_14 = F_6 ( F_7 ( V_17 , V_18 ) ) ;
F_3 ( L_6 , V_14 ) ;
if ( F_8 ( V_14 == 0 ) ) {
F_2 ( L_7 ) ;
return V_19 ;
}
V_15 = F_6 ( F_7 ( V_17 , V_20 ) ) ;
F_9 ( F_7 ( V_17 , V_21 ) , V_14 ) ;
V_12 -> V_9 = V_14 ;
if ( F_10 ( ( V_14 & V_22 ) != 0 ) ) {
F_9 ( F_7 ( V_17 , V_20 ) , V_15 | V_22 ) ;
V_14 &= ~ V_22 ;
F_11 ( V_12 ) ;
}
#ifdef F_12
if ( F_10 ( ( V_14 & V_23 ) != 0 ) ) {
F_9 ( F_7 ( V_17 , V_20 ) , V_15 | V_23 ) ;
V_14 &= ~ V_23 ;
F_13 ( V_12 ) ;
}
#endif
if ( F_8 ( ( V_14 & V_24 ) != 0 ) ) {
T_4 V_25 ;
V_25 = F_6 ( F_7 ( V_26 , V_27 ) ) ;
F_3 ( L_8 , V_25 ) ;
V_14 &= ~ V_24 ;
}
if ( F_8 ( V_14 != 0 ) ) {
F_3 ( L_9 , V_14 ) ;
}
F_14 ( V_28 , V_29 ) ;
F_15 ( V_12 -> V_30 ) ;
return V_31 ;
}
int F_16 ( struct V_11 * V_12 , bool V_32 )
{
unsigned int V_33 ;
void T_3 * V_13 = V_12 -> V_13 ;
V_33 = F_6 ( F_7 ( V_26 , V_34 ) ) ;
F_9 ( F_7 ( V_26 , V_34 ) , V_33 & ~ V_35 ) ;
F_3 ( L_10 , F_6 ( F_7 ( V_26 , V_34 ) ) ) ;
V_33 = F_6 ( F_7 ( V_17 , V_18 ) ) ;
F_3 ( L_11 , V_33 ) ;
F_9 ( F_7 ( V_17 , V_21 ) , V_33 ) ;
V_33 = ( ~ ( V_22 | V_24 | V_23 ) ) ;
F_9 ( F_7 ( V_17 , V_20 ) , V_33 ) ;
#ifdef F_17
#ifdef F_18
F_9 ( F_7 ( V_17 , V_36 ) ,
F_18 ) ;
#endif
if ( F_6 ( F_7 ( V_17 , V_36 ) ) > 0 ) {
F_3 ( L_12 ,
F_6 ( F_7 ( V_17 , V_36 ) ) ) ;
}
#endif
V_33 = F_6 ( F_7 ( V_26 , V_37 ) ) ;
if ( V_32 == true ) {
F_19 ( L_13 , V_33 ) ;
}
F_9 ( F_7 ( V_26 , V_37 ) , V_38 ) ;
V_33 = F_6 ( F_7 ( V_26 , V_37 ) ) ;
if ( V_32 == true ) {
F_19 ( L_14 , V_33 , V_38 ) ;
}
return 0 ;
}
static int F_20 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = NULL ;
void T_3 * V_13 = NULL ;
bool V_43 = false ;
struct V_11 * V_44 = F_21 ( sizeof( struct V_11 ) , V_45 ) ;
T_4 V_46 ;
int V_47 = 0 ;
if ( F_8 ( V_44 == NULL ) ) {
F_2 ( L_15 ) ;
V_47 = - V_48 ;
goto V_49;
}
V_44 -> V_50 = 0 ;
F_22 ( & V_40 -> V_51 , V_44 ) ;
V_44 -> V_52 = F_23 ( V_40 , V_53 , 0 ) ;
if ( F_8 ( V_44 -> V_52 == NULL ) ) {
F_2 ( L_16 ) ;
V_47 = - V_54 ;
goto V_49;
}
F_3 ( L_17 ,
V_44 -> V_52 -> V_1 ,
( unsigned long long ) V_44 -> V_52 -> V_55 ,
( unsigned long long ) V_44 -> V_52 -> V_56 ) ;
V_42 = F_24 ( V_44 -> V_52 -> V_55 , F_25 ( V_44 -> V_52 ) , L_18 ) ;
if ( F_8 ( V_42 == NULL ) ) {
F_2 ( L_19
L_20 , ( unsigned int ) V_44 -> V_52 -> V_55 ) ;
V_47 = - V_57 ;
goto V_49;
}
V_13 = F_26 ( V_44 -> V_52 -> V_55 , F_25 ( V_44 -> V_52 ) ) ;
if ( F_8 ( V_13 == NULL ) ) {
F_2 ( L_21 ,
( unsigned int ) V_44 -> V_52 -> V_55 , ( unsigned int ) F_25 ( V_44 -> V_52 ) ) ;
V_47 = - V_48 ;
goto V_49;
}
F_3 ( L_22 , & V_44 -> V_52 -> V_55 , V_13 ) ;
V_44 -> V_13 = V_13 ;
V_44 -> V_58 = F_23 ( V_40 , V_59 , 0 ) ;
if ( F_8 ( V_44 -> V_58 == NULL ) ) {
F_2 ( L_23 ) ;
V_47 = - V_54 ;
goto V_49;
}
V_47 = F_27 ( V_44 -> V_58 -> V_55 , F_4 ,
V_60 , L_24 , V_44 ) ;
if ( F_8 ( V_47 != 0 ) ) {
F_2 ( L_25 ,
( unsigned long long ) V_44 -> V_58 -> V_55 ) ;
goto V_49;
}
F_28 ( & V_44 -> V_61 ) ;
V_43 = true ;
F_3 ( L_26 ,
V_44 -> V_58 -> V_1 ,
( unsigned long long ) V_44 -> V_58 -> V_55 ) ;
V_44 -> V_40 = V_40 ;
if( V_44 -> V_40 -> V_51 . V_62 == NULL )
{
V_44 -> V_40 -> V_51 . V_62 = & V_44 -> V_40 -> V_51 . V_63 ;
}
if ( ! V_44 -> V_40 -> V_51 . V_63 )
{
V_44 -> V_40 -> V_51 . V_63 = F_29 ( V_64 ) ;
}
V_46 = F_6 ( F_7 ( V_17 , V_65 ) ) ;
if ( V_46 != V_66 ) {
F_2 ( L_27 ,
V_46 , ( T_4 ) V_66 ) ;
V_47 = - V_67 ;
goto V_49;
}
F_3 ( L_28 , V_46 ) ;
F_30 ( V_68 , L_29 , V_69 ,
F_6 ( F_7 ( V_17 , V_70 ) ) , V_71 ) ;
V_47 = F_16 ( V_44 , true ) ;
if ( F_8 ( V_47 != 0 ) ) {
F_2 ( L_30 ) ;
goto V_49;
}
#ifdef F_31
V_47 = F_32 ( & ( V_40 -> V_51 . V_72 ) , V_44 ) ;
if ( F_8 ( V_47 != 0 ) ) {
F_2 ( L_31 ) ;
goto V_49;
}
#endif
V_47 = F_33 ( V_44 ) ;
if ( F_8 ( V_47 != 0 ) ) {
F_2 ( L_32 ) ;
goto V_49;
}
V_44 -> V_73 =
F_34 ( V_44 , V_74 ) ;
if ( F_8 ( V_44 -> V_73 == V_75 ) ) {
F_2 ( L_33 ) ;
V_47 = - V_48 ;
goto V_49;
}
V_47 = F_35 ( V_44 ) ;
if ( F_8 ( V_47 != 0 ) ) {
F_2 ( L_34 ) ;
goto V_49;
}
V_47 = F_36 ( V_44 ) ;
if ( F_8 ( V_47 != 0 ) ) {
F_2 ( L_35 ) ;
goto V_49;
}
V_47 = F_37 ( V_44 ) ;
if ( F_8 ( V_47 != 0 ) ) {
F_2 ( L_36 ) ;
goto V_49;
}
V_47 = F_38 ( V_44 ) ;
if ( F_8 ( V_47 != 0 ) ) {
F_2 ( L_37 , V_47 ) ;
goto V_49;
}
V_47 = F_39 ( V_44 ) ;
if ( F_8 ( V_47 != 0 ) ) {
F_2 ( L_38 ) ;
goto V_49;
}
V_47 = F_40 ( V_44 ) ;
if ( F_8 ( V_47 != 0 ) ) {
F_2 ( L_39 ) ;
goto V_49;
}
V_47 = F_41 ( V_44 ) ;
if ( F_8 ( V_47 != 0 ) ) {
F_2 ( L_40 ) ;
goto V_49;
}
V_47 = F_42 ( V_44 ) ;
if ( F_8 ( V_47 != 0 ) ) {
F_2 ( L_41 ) ;
goto V_49;
}
return 0 ;
V_49:
F_2 ( L_42 ) ;
if ( V_44 != NULL ) {
F_43 ( V_44 ) ;
F_44 ( V_44 ) ;
F_45 ( V_44 ) ;
F_46 ( V_44 ) ;
F_47 ( V_44 ) ;
F_48 ( V_44 ) ;
F_49 ( V_44 ) ;
F_50 ( V_44 ) ;
F_51 ( V_44 ) ;
#ifdef F_31
F_52 () ;
#endif
if ( V_42 != NULL ) {
if ( V_43 ) {
F_53 ( V_44 -> V_58 -> V_55 , V_44 ) ;
V_44 -> V_58 = NULL ;
F_54 ( V_13 ) ;
V_44 -> V_13 = NULL ;
}
F_55 ( V_44 -> V_52 -> V_55 ,
F_25 ( V_44 -> V_52 ) ) ;
V_44 -> V_52 = NULL ;
}
F_56 ( V_44 ) ;
F_22 ( & V_40 -> V_51 , NULL ) ;
}
return V_47 ;
}
void F_57 ( struct V_11 * V_12 )
{
F_58 ( V_12 -> V_13 +
F_7 ( V_17 , V_20 ) , 0xFFFFFFFF ) ;
}
static void F_59 ( struct V_39 * V_40 )
{
struct V_11 * V_12 =
(struct V_11 * ) F_60 ( & V_40 -> V_51 ) ;
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
F_58 ( V_12 -> V_13 + F_7 ( V_17 , V_20 ) ,
0xFFFFFFFF ) ;
F_53 ( V_12 -> V_58 -> V_55 , V_12 ) ;
V_12 -> V_58 = NULL ;
F_57 ( V_12 ) ;
if ( V_12 -> V_13 != NULL ) {
F_54 ( V_12 -> V_13 ) ;
F_55 ( V_12 -> V_52 -> V_55 ,
F_25 ( V_12 -> V_52 ) ) ;
V_12 -> V_13 = NULL ;
V_12 -> V_52 = NULL ;
}
F_56 ( V_12 ) ;
F_22 ( & V_40 -> V_51 , NULL ) ;
}
static int F_61 ( struct V_39 * V_40 )
{
int V_47 ;
#if F_62 ( V_76 ) && F_62 ( V_77 )
T_4 V_78 , V_79 ;
asm volatile("mrc p15, 0, %0, c0, c0, 1" : "=r" (ctr));
V_79 = 4 << ( ( V_78 >> 16 ) & 0xf ) ;
F_3 ( L_43 ,
V_79 , V_80 ) ;
asm volatile("mrc p15, 0, %0, c0, c0, 0" : "=r" (ctr));
F_3 ( L_44
L_45 ,
( V_78 >> 24 ) , ( V_78 >> 16 ) & 0xF , ( V_78 >> 4 ) & 0xFFF , ( V_78 >> 20 ) & 0xF , V_78 & 0xF ) ;
#endif
V_47 = F_20 ( V_40 ) ;
if ( V_47 != 0 )
return V_47 ;
F_30 ( V_68 , L_46 ) ;
return 0 ;
}
static int F_63 ( struct V_39 * V_40 )
{
F_3 ( L_47 ) ;
F_59 ( V_40 ) ;
F_30 ( V_68 , L_48 ) ;
#ifdef F_64
F_65 () ;
#endif
return 0 ;
}
