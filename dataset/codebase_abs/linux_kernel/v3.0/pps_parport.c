static inline int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 -> V_4 ( V_2 ) & V_5 ) != 0 ;
}
static void F_2 ( void * V_6 )
{
struct V_7 V_8 , V_9 ;
struct V_10 * V_11 = V_6 ;
struct V_1 * V_2 = V_11 -> V_12 -> V_2 ;
unsigned int V_13 ;
unsigned long V_14 ;
F_3 ( & V_8 ) ;
if ( V_11 -> V_15 == 0 )
goto V_16;
F_4 ( V_14 ) ;
if ( ! F_1 ( V_2 ) ) {
F_5 ( V_14 ) ;
F_6 ( V_11 -> V_17 -> V_11 , L_1 ) ;
goto V_16;
}
for ( V_13 = V_11 -> V_15 ; V_13 ; V_13 -- )
if ( ! F_1 ( V_2 ) ) {
F_3 ( & V_9 ) ;
F_5 ( V_14 ) ;
V_11 -> V_18 = 0 ;
goto V_19;
}
F_5 ( V_14 ) ;
V_11 -> V_18 ++ ;
if ( V_11 -> V_18 >= V_20 ) {
F_6 ( V_11 -> V_17 -> V_11 , L_2
L_3 , V_11 -> V_18 ) ;
V_11 -> V_15 = 0 ;
V_11 -> V_18 = 0 ;
}
V_16:
F_7 ( V_11 -> V_17 , & V_8 ,
V_21 , NULL ) ;
return;
V_19:
F_7 ( V_11 -> V_17 , & V_8 ,
V_21 , NULL ) ;
F_7 ( V_11 -> V_17 , & V_9 ,
V_22 , NULL ) ;
return;
}
static void F_8 ( struct V_23 * V_17 , int V_24 , void * V_25 )
{
F_9 ( V_17 -> V_11 , L_4 ,
V_24 & V_21 ? L_5 : L_6 ,
V_24 & V_22 ? L_7 : L_6 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_10 * V_26 ;
struct V_27 V_28 = {
. V_29 = V_30 ,
. V_31 = L_6 ,
. V_32 = V_33 | \
V_34 | V_35 | \
V_36 | V_37 | \
V_38 | V_39 ,
. V_40 = F_8 ,
. V_41 = V_42 ,
. V_11 = NULL
} ;
V_26 = F_11 ( sizeof( struct V_10 ) , V_43 ) ;
if ( ! V_26 ) {
F_12 ( L_8 ) ;
return;
}
V_26 -> V_12 = F_13 ( V_2 , V_30 ,
NULL , NULL , F_2 , V_44 , V_26 ) ;
if ( ! V_26 -> V_12 ) {
F_12 ( L_9 , V_2 -> V_29 ) ;
goto V_45;
}
if ( F_14 ( V_26 -> V_12 ) < 0 ) {
F_12 ( L_10 , V_2 -> V_29 ) ;
goto V_46;
}
V_26 -> V_17 = F_15 ( & V_28 ,
V_33 | V_34 | V_35 ) ;
if ( V_26 -> V_17 == NULL ) {
F_12 ( L_11 ) ;
goto V_47;
}
V_26 -> V_15 = V_48 ;
V_2 -> V_3 -> V_49 ( V_2 ) ;
F_16 ( L_12 , V_2 -> V_29 ) ;
return;
V_47:
F_17 ( V_26 -> V_12 ) ;
V_46:
F_18 ( V_26 -> V_12 ) ;
V_45:
F_19 ( V_26 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_50 * V_12 = V_2 -> V_51 ;
struct V_10 * V_26 ;
if ( strcmp ( V_12 -> V_29 , V_30 ) )
return;
V_26 = V_12 -> V_52 ;
V_2 -> V_3 -> V_53 ( V_2 ) ;
F_21 ( V_26 -> V_17 ) ;
F_17 ( V_12 ) ;
F_18 ( V_12 ) ;
F_19 ( V_26 ) ;
}
static int T_1 F_22 ( void )
{
int V_54 ;
F_16 ( V_55 L_13 ) ;
if ( V_48 > V_56 ) {
F_12 ( L_14
L_15 , V_56 ) ;
return - V_57 ;
}
V_54 = F_23 ( & V_58 ) ;
if ( V_54 ) {
F_12 ( L_16 ) ;
return V_54 ;
}
return 0 ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_58 ) ;
}
