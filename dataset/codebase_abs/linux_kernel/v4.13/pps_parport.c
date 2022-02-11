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
static void F_8 ( struct V_1 * V_2 )
{
struct V_10 * V_23 ;
struct V_24 V_25 = {
. V_26 = V_27 ,
. V_28 = L_4 ,
. V_29 = V_30 | \
V_31 | V_32 | \
V_33 | V_34 | \
V_35 | V_36 ,
. V_37 = V_38 ,
. V_11 = NULL
} ;
V_23 = F_9 ( sizeof( struct V_10 ) , V_39 ) ;
if ( ! V_23 ) {
F_10 ( L_5 ) ;
return;
}
V_23 -> V_12 = F_11 ( V_2 , V_27 ,
NULL , NULL , F_2 , V_40 , V_23 ) ;
if ( ! V_23 -> V_12 ) {
F_10 ( L_6 , V_2 -> V_26 ) ;
goto V_41;
}
if ( F_12 ( V_23 -> V_12 ) < 0 ) {
F_10 ( L_7 , V_2 -> V_26 ) ;
goto V_42;
}
V_23 -> V_17 = F_13 ( & V_25 ,
V_30 | V_31 | V_32 ) ;
if ( V_23 -> V_17 == NULL ) {
F_10 ( L_8 ) ;
goto V_43;
}
V_23 -> V_15 = V_44 ;
V_2 -> V_3 -> V_45 ( V_2 ) ;
F_14 ( L_9 , V_2 -> V_26 ) ;
return;
V_43:
F_15 ( V_23 -> V_12 ) ;
V_42:
F_16 ( V_23 -> V_12 ) ;
V_41:
F_17 ( V_23 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_46 * V_12 = V_2 -> V_47 ;
struct V_10 * V_23 ;
if ( ! V_12 || strcmp ( V_12 -> V_26 , V_27 ) )
return;
V_23 = V_12 -> V_48 ;
V_2 -> V_3 -> V_49 ( V_2 ) ;
F_19 ( V_23 -> V_17 ) ;
F_15 ( V_12 ) ;
F_16 ( V_12 ) ;
F_17 ( V_23 ) ;
}
static int T_1 F_20 ( void )
{
int V_50 ;
F_14 ( V_51 L_10 ) ;
if ( V_44 > V_52 ) {
F_10 ( L_11
L_12 , V_52 ) ;
return - V_53 ;
}
V_50 = F_21 ( & V_54 ) ;
if ( V_50 ) {
F_10 ( L_13 ) ;
return V_50 ;
}
return 0 ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_54 ) ;
}
