static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( L_1 ) ;
return V_3 ;
}
static int T_2 F_3 ( char * V_4 , unsigned long * V_5 )
{
struct V_6 * V_7 ;
const unsigned int * V_8 ;
int V_9 = 0 ;
V_7 = F_4 ( NULL , L_2 ) ;
if ( V_7 ) {
V_8 = F_5 ( V_7 , V_4 , NULL ) ;
if ( V_8 ) {
V_9 = 1 ;
* V_5 = * V_8 ;
}
F_6 ( V_7 ) ;
}
return V_9 ;
}
void T_2 F_7 ( void )
{
struct V_6 * V_7 ;
T_3 T_4 * V_10 ;
T_5 T_4 * V_11 ;
T_6 T_4 * V_12 ;
T_7 T_4 * V_13 ;
int V_1 , V_14 ;
V_10 = F_8 ( V_15 ) ;
F_9 ( & V_10 -> V_16 , ~ V_17 ) ;
F_9 ( & V_10 -> V_16 , V_17 ) ;
F_10 ( V_10 ) ;
V_11 = F_8 ( V_18 ) ;
F_11 ( & V_11 -> V_19 , 0x02000000 ) ;
F_10 ( V_11 ) ;
V_20 = 50000000 ;
if ( ! F_3 ( L_3 , & V_20 ) )
F_2 ( V_21 L_4
L_5 ) ;
V_22 = V_20 / 16 ;
F_2 ( L_6 , V_22 ) ;
V_12 = F_8 ( V_23 ) ;
F_9 ( & V_12 -> V_24 , ~ V_17 ) ;
F_9 ( & V_12 -> V_25 , ~ V_17 ) ;
F_9 ( & V_12 -> V_26 , ~ V_17 ) ;
F_9 ( & V_12 -> V_24 , V_17 ) ;
F_9 ( & V_12 -> V_25 , V_17 ) ;
F_9 ( & V_12 -> V_26 , V_17 ) ;
F_10 ( V_12 ) ;
F_12 () ;
V_7 = F_4 ( NULL , L_2 ) ;
V_14 = F_13 ( V_7 , 0 ) ;
V_1 = F_14 ( V_14 ) ;
V_13 = F_8 ( V_27 ) ;
F_15 ( & V_13 -> V_28 , ( ( 1 << ( 7 - ( V_1 / 2 ) ) ) << 8 ) |
( V_29 | V_30 ) ) ;
F_10 ( V_13 ) ;
if ( F_16 ( V_14 , & V_31 ) )
F_17 ( L_7 ) ;
}
int F_18 ( struct V_32 * V_33 )
{
T_6 T_4 * V_12 ;
T_7 T_4 * V_13 ;
int time ;
V_12 = F_8 ( V_23 ) ;
V_13 = F_8 ( V_27 ) ;
time = mktime ( V_33 -> V_34 + 1900 , V_33 -> V_35 + 1 , V_33 -> V_36 ,
V_33 -> V_37 , V_33 -> V_38 , V_33 -> V_39 ) ;
F_9 ( & V_12 -> V_40 , V_17 ) ;
F_9 ( & V_13 -> V_41 , time ) ;
F_9 ( & V_12 -> V_40 , ~ V_17 ) ;
F_10 ( V_13 ) ;
F_10 ( V_12 ) ;
return 0 ;
}
void F_19 ( struct V_32 * V_33 )
{
unsigned long V_42 ;
T_7 T_4 * V_43 = F_8 ( V_27 ) ;
V_42 = F_20 ( & V_43 -> V_41 ) ;
F_21 ( V_42 , V_33 ) ;
V_33 -> V_34 -= 1900 ;
V_33 -> V_35 -= 1 ;
F_10 ( V_43 ) ;
return;
}
void F_22 ( char * V_44 )
{
T_5 T_4 * V_45 = F_8 ( V_18 ) ;
F_23 () ;
F_11 ( & V_45 -> V_46 , 0x00000080 ) ;
F_24 ( F_25 () & ~ 0x1000 ) ;
F_26 ( & V_45 -> V_47 [ 0 ] ) ;
F_17 ( L_8 ) ;
}
static void F_27 ( unsigned int V_1 , struct V_48 * V_49 )
{
struct V_50 * V_51 = F_28 ( V_49 ) ;
int V_52 = F_29 () ;
if ( V_52 >= 0 )
F_30 ( V_52 ) ;
V_51 -> V_53 ( & V_49 -> V_54 ) ;
}
void T_2 F_31 ( void )
{
int V_1 ;
if ( F_32 () ) {
F_2 ( V_21 L_9 ) ;
return;
}
V_1 = F_33 () ;
if ( V_1 != V_55 )
F_34 ( V_1 , F_27 ) ;
}
