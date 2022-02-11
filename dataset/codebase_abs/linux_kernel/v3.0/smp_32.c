void T_1 F_1 ( int V_1 )
{
int V_2 ;
int V_3 ;
F_2 ( V_1 ) . V_4 = V_5 ;
F_3 ( V_1 , & V_2 ) ;
F_2 ( V_1 ) . V_6 = F_4 ( V_2 ,
L_1 , 0 ) ;
F_2 ( V_1 ) . V_7 = V_2 ;
V_3 = F_5 ( V_2 ) ;
if ( V_3 < 0 ) {
F_6 ( V_8 L_2 , V_1 , V_2 ) ;
V_3 = 0 ;
}
F_2 ( V_1 ) . V_3 = V_3 ;
}
void T_2 F_7 ( unsigned int V_9 )
{
extern void V_10 ( void ) ;
extern void V_11 ( void ) ;
unsigned long V_12 = 0 ;
int V_13 , V_14 = 0 ;
F_8 (cpu) {
V_14 ++ ;
V_12 += F_2 ( V_13 ) . V_4 ;
}
F_6 ( L_3 ,
V_14 , V_12 / ( 500000 / V_15 ) ,
( V_12 / ( 5000 / V_15 ) ) % 100 ) ;
switch( V_16 ) {
case V_17 :
F_6 ( L_4 ) ;
F_9 () ;
break;
case V_18 :
F_6 ( L_5 ) ;
F_9 () ;
break;
case V_19 :
V_10 () ;
break;
case V_20 :
V_11 () ;
break;
case V_21 :
F_10 () ;
break;
case V_22 :
F_6 ( L_6 ) ;
F_9 () ;
break;
case V_23 :
F_6 ( L_7 ) ;
F_9 () ;
break;
default:
F_6 ( L_8 ) ;
F_9 () ;
break;
}
}
void F_11 ( void )
{
F_6 ( L_9 , F_12 () ) ;
F_13 ( L_10 ) ;
}
void F_14 ( int V_13 )
{
T_3 (F_15)( V_13 );
}
void F_16 ( void )
{
}
void F_17 ( int V_13 )
{
T_3 (F_18)( V_13 );
}
void F_19 ( const struct V_24 * V_25 )
{
int V_13 ;
F_20 (cpu, mask)
T_3 (F_21)( V_13 );
}
void F_22 ( void )
{
F_23 () ;
F_24 () ;
F_25 () . V_26 ++ ;
F_26 () ;
}
void F_27 ( void )
{
F_23 () ;
F_28 () ;
F_25 () . V_27 ++ ;
F_26 () ;
}
void F_29 ( void )
{
F_23 () ;
F_30 () ;
F_25 () . V_27 ++ ;
F_26 () ;
}
void F_31 ( void )
{
F_32 ( ( V_28 ) T_3 ( V_29 ) ) ;
V_29 () ;
}
void F_33 ( void )
{
F_32 ( ( V_28 ) T_3 ( V_30 ) ) ;
V_30 () ;
}
void F_34 ( struct V_31 * V_32 )
{
if( V_32 -> V_33 != V_34 ) {
T_4 V_35 ;
F_35 ( & V_35 , F_36 ( V_32 ) ) ;
F_37 ( F_12 () , & V_35 ) ;
if ( ! F_38 ( & V_35 ) )
F_39 ( ( V_28 ) T_3 ( V_36 ) , ( unsigned long ) V_32 ) ;
V_36 ( V_32 ) ;
}
}
void F_40 ( struct V_31 * V_32 )
{
if( V_32 -> V_33 != V_34 ) {
T_4 V_35 ;
F_35 ( & V_35 , F_36 ( V_32 ) ) ;
F_37 ( F_12 () , & V_35 ) ;
if ( ! F_38 ( & V_35 ) ) {
F_39 ( ( V_28 ) T_3 ( V_37 ) , ( unsigned long ) V_32 ) ;
if( F_41 ( & V_32 -> V_38 ) == 1 && V_39 -> V_40 == V_32 )
F_35 ( F_36 ( V_32 ) ,
F_42 ( F_12 () ) ) ;
}
V_37 ( V_32 ) ;
}
}
void F_43 ( struct V_41 * V_42 , unsigned long V_43 ,
unsigned long V_44 )
{
struct V_31 * V_32 = V_42 -> V_45 ;
if ( V_32 -> V_33 != V_34 ) {
T_4 V_35 ;
F_35 ( & V_35 , F_36 ( V_32 ) ) ;
F_37 ( F_12 () , & V_35 ) ;
if ( ! F_38 ( & V_35 ) )
F_44 ( ( V_28 ) T_3 ( V_46 ) , ( unsigned long ) V_42 , V_43 , V_44 ) ;
V_46 ( V_42 , V_43 , V_44 ) ;
}
}
void F_45 ( struct V_41 * V_42 , unsigned long V_43 ,
unsigned long V_44 )
{
struct V_31 * V_32 = V_42 -> V_45 ;
if ( V_32 -> V_33 != V_34 ) {
T_4 V_35 ;
F_35 ( & V_35 , F_36 ( V_32 ) ) ;
F_37 ( F_12 () , & V_35 ) ;
if ( ! F_38 ( & V_35 ) )
F_44 ( ( V_28 ) T_3 ( V_47 ) , ( unsigned long ) V_42 , V_43 , V_44 ) ;
V_47 ( V_42 , V_43 , V_44 ) ;
}
}
void F_46 ( struct V_41 * V_42 , unsigned long V_48 )
{
struct V_31 * V_32 = V_42 -> V_45 ;
if( V_32 -> V_33 != V_34 ) {
T_4 V_35 ;
F_35 ( & V_35 , F_36 ( V_32 ) ) ;
F_37 ( F_12 () , & V_35 ) ;
if ( ! F_38 ( & V_35 ) )
F_47 ( ( V_28 ) T_3 ( V_49 ) , ( unsigned long ) V_42 , V_48 ) ;
V_49 ( V_42 , V_48 ) ;
}
}
void F_48 ( struct V_41 * V_42 , unsigned long V_48 )
{
struct V_31 * V_32 = V_42 -> V_45 ;
if( V_32 -> V_33 != V_34 ) {
T_4 V_35 ;
F_35 ( & V_35 , F_36 ( V_32 ) ) ;
F_37 ( F_12 () , & V_35 ) ;
if ( ! F_38 ( & V_35 ) )
F_47 ( ( V_28 ) T_3 ( V_50 ) , ( unsigned long ) V_42 , V_48 ) ;
V_50 ( V_42 , V_48 ) ;
}
}
void F_49 ( unsigned long V_48 )
{
#if 1
F_39 ( ( V_28 ) T_3 ( V_51 ) , V_48 ) ;
#endif
V_51 ( V_48 ) ;
}
void F_50 ( struct V_31 * V_32 , unsigned long V_52 )
{
T_4 V_35 ;
F_35 ( & V_35 , F_36 ( V_32 ) ) ;
F_37 ( F_12 () , & V_35 ) ;
if ( ! F_38 ( & V_35 ) )
F_47 ( ( V_28 ) T_3 ( V_53 ) , ( unsigned long ) V_32 , V_52 ) ;
V_53 ( V_32 , V_52 ) ;
}
int F_51 ( unsigned int V_54 )
{
int V_55 ;
unsigned long V_56 ;
if( ( ! V_54 ) || ( V_57 / V_54 ) < 500 )
return - V_58 ;
F_52 ( & V_59 , V_56 ) ;
F_53 (i) {
F_54 ( V_55 , V_57 / V_54 ) ;
F_55 ( V_55 ) = V_54 ;
}
F_56 ( & V_59 , V_56 ) ;
return 0 ;
}
void T_2 F_57 ( unsigned int V_9 )
{
extern void T_2 V_60 ( void ) ;
extern void T_2 V_61 ( void ) ;
int V_55 , V_62 , V_63 ;
F_6 ( L_11 ) ;
V_63 = 0 ;
for ( V_55 = 0 ; ! F_58 ( V_55 , NULL , & V_62 ) ; V_55 ++ ) {
if ( V_62 >= V_64 )
V_63 ++ ;
}
if ( V_63 && V_9 > V_55 - V_63 )
F_6 ( L_12 ) ;
F_1 ( V_65 ) ;
switch( V_16 ) {
case V_17 :
F_6 ( L_4 ) ;
F_9 () ;
break;
case V_18 :
F_6 ( L_5 ) ;
F_9 () ;
break;
case V_19 :
V_60 () ;
break;
case V_20 :
V_61 () ;
break;
case V_21 :
F_59 () ;
break;
case V_22 :
F_6 ( L_6 ) ;
F_9 () ;
break;
case V_23 :
F_6 ( L_7 ) ;
F_9 () ;
break;
default:
F_6 ( L_8 ) ;
F_9 () ;
break;
}
}
void T_2 F_60 ( void )
{
int V_66 , V_3 ;
V_66 = 0 ;
while ( ! F_58 ( V_66 , NULL , & V_3 ) ) {
if ( V_3 < V_64 ) {
F_61 ( V_3 , true ) ;
F_62 ( V_3 , true ) ;
}
V_66 ++ ;
}
}
void T_2 F_63 ( void )
{
int V_62 = F_64 () ;
if ( V_62 >= V_64 ) {
F_65 ( L_13 ) ;
F_66 () ;
}
if ( V_62 != 0 )
F_6 ( L_14 ) ;
F_67 () -> V_13 = V_62 ;
F_68 ( V_62 , true ) ;
F_61 ( V_62 , true ) ;
}
int T_1 F_69 ( unsigned int V_13 )
{
extern int T_1 V_67 ( int ) ;
extern int T_1 V_68 ( int ) ;
int V_69 = 0 ;
switch( V_16 ) {
case V_17 :
F_6 ( L_4 ) ;
F_9 () ;
break;
case V_18 :
F_6 ( L_5 ) ;
F_9 () ;
break;
case V_19 :
V_69 = V_67 ( V_13 ) ;
break;
case V_20 :
V_69 = V_68 ( V_13 ) ;
break;
case V_21 :
V_69 = F_70 ( V_13 ) ;
break;
case V_22 :
F_6 ( L_6 ) ;
F_9 () ;
break;
case V_23 :
F_6 ( L_7 ) ;
F_9 () ;
break;
default:
F_6 ( L_8 ) ;
F_9 () ;
break;
}
if ( ! V_69 ) {
F_71 ( V_13 , & V_70 ) ;
while ( ! F_72 ( V_13 ) )
F_73 () ;
}
return V_69 ;
}
void F_74 ( struct V_71 * V_72 )
{
int V_55 ;
F_8 (i) {
F_75 ( V_72 ,
L_15 ,
V_55 ,
F_2 ( V_55 ) . V_4 / ( 500000 / V_15 ) ,
( F_2 ( V_55 ) . V_4 / ( 5000 / V_15 ) ) % 100 ) ;
}
}
void F_76 ( struct V_71 * V_72 )
{
int V_55 ;
F_75 ( V_72 , L_16 ) ;
F_8 (i)
F_75 ( V_72 , L_17 , V_55 ) ;
}
