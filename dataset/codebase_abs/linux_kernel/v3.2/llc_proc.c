static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
F_2 ( V_2 , L_1 , V_3 ) ;
}
static struct V_4 * F_3 ( T_2 V_5 )
{
struct V_6 * V_7 ;
struct V_4 * V_8 = NULL ;
int V_9 ;
F_4 (sap, &llc_sap_list, node) {
F_5 ( & V_7 -> V_10 ) ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
struct V_12 * V_13 = & V_7 -> V_14 [ V_9 ] ;
struct V_15 * V_16 ;
F_6 (sk, node, head) {
if ( ! V_5 )
goto V_17;
-- V_5 ;
}
}
F_7 ( & V_7 -> V_10 ) ;
}
V_8 = NULL ;
V_17:
return V_8 ;
}
static void * F_8 ( struct V_1 * V_2 , T_2 * V_5 )
{
T_2 V_18 = * V_5 ;
F_9 () ;
return V_18 ? F_3 ( -- V_18 ) : V_19 ;
}
static struct V_4 * F_10 ( struct V_6 * V_7 , int V_20 )
{
struct V_15 * V_16 ;
struct V_4 * V_8 = NULL ;
while ( ++ V_20 < V_11 )
F_6 (sk, node, &sap->sk_laddr_hash[bucket])
goto V_21;
V_21:
return V_8 ;
}
static void * F_11 ( struct V_1 * V_2 , void * V_22 , T_2 * V_5 )
{
struct V_4 * V_8 , * V_23 ;
struct V_24 * V_25 ;
struct V_6 * V_7 ;
++ * V_5 ;
if ( V_22 == V_19 ) {
V_8 = F_3 ( 0 ) ;
goto V_21;
}
V_8 = V_22 ;
V_23 = F_12 ( V_8 ) ;
if ( V_23 ) {
V_8 = V_23 ;
goto V_21;
}
V_25 = F_13 ( V_8 ) ;
V_7 = V_25 -> V_7 ;
V_8 = F_10 ( V_7 , F_14 ( V_7 , & V_25 -> V_26 ) ) ;
if ( V_8 )
goto V_21;
F_7 ( & V_7 -> V_10 ) ;
F_15 (sap, &llc_sap_list, node) {
F_5 ( & V_7 -> V_10 ) ;
V_8 = F_10 ( V_7 , - 1 ) ;
if ( V_8 )
break;
F_7 ( & V_7 -> V_10 ) ;
}
V_21:
return V_8 ;
}
static void F_16 ( struct V_1 * V_2 , void * V_22 )
{
if ( V_22 && V_22 != V_19 ) {
struct V_4 * V_8 = V_22 ;
struct V_24 * V_25 = F_13 ( V_8 ) ;
struct V_6 * V_7 = V_25 -> V_7 ;
F_7 ( & V_7 -> V_10 ) ;
}
F_17 () ;
}
static int F_18 ( struct V_1 * V_2 , void * V_22 )
{
struct V_4 * V_8 ;
struct V_24 * V_25 ;
if ( V_22 == V_19 ) {
F_19 ( V_2 , L_2
L_3 ) ;
goto V_21;
}
V_8 = V_22 ;
V_25 = F_13 ( V_8 ) ;
F_2 ( V_2 , L_4 , V_8 -> V_27 , 0 ) ;
if ( V_25 -> V_28 )
F_1 ( V_2 , V_25 -> V_28 -> V_29 ) ;
else {
T_1 V_3 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
F_1 ( V_2 , V_3 ) ;
}
F_2 ( V_2 , L_5 , V_25 -> V_7 -> V_26 . V_30 ) ;
F_1 ( V_2 , V_25 -> V_31 . V_32 ) ;
F_2 ( V_2 , L_6 , V_25 -> V_31 . V_30 ,
F_20 ( V_8 ) ,
F_21 ( V_8 ) - V_25 -> V_33 ,
V_8 -> V_34 ,
V_8 -> V_35 ? F_22 ( V_8 -> V_35 ) -> V_36 : - 1 ,
V_25 -> V_37 ) ;
V_21:
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , void * V_22 )
{
struct V_4 * V_8 ;
struct V_24 * V_25 ;
if ( V_22 == V_19 ) {
F_19 ( V_2 , L_7
L_8
L_9 ) ;
goto V_21;
}
V_8 = V_22 ;
V_25 = F_13 ( V_8 ) ;
F_2 ( V_2 , L_10
L_11 ,
V_25 -> V_31 . V_30 , V_38 [ V_25 -> V_39 ] ,
V_25 -> V_40 , V_25 -> V_41 , V_25 -> V_42 , V_25 -> V_43 , V_25 -> V_44 ,
V_25 -> V_45 , V_25 -> V_46 , V_25 -> V_47 ,
V_25 -> V_48 , F_24 ( & V_25 -> V_49 . V_50 ) ,
F_24 ( & V_25 -> V_51 . V_50 ) ,
F_24 ( & V_25 -> V_52 . V_50 ) ,
F_24 ( & V_25 -> V_53 . V_50 ) ,
! ! V_8 -> V_54 . V_55 , ! ! F_25 ( V_8 ) ) ;
V_21:
return 0 ;
}
static int F_26 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_27 ( V_57 , & V_58 ) ;
}
static int F_28 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_27 ( V_57 , & V_59 ) ;
}
int T_3 F_29 ( void )
{
int V_60 = - V_61 ;
struct V_62 * V_63 ;
V_64 = F_30 ( L_12 , V_65 . V_66 ) ;
if ( ! V_64 )
goto V_21;
V_63 = F_31 ( L_13 , V_67 , V_64 , & V_68 ) ;
if ( ! V_63 )
goto V_69;
V_63 = F_31 ( L_14 , V_67 , V_64 , & V_70 ) ;
if ( ! V_63 )
goto V_71;
V_60 = 0 ;
V_21:
return V_60 ;
V_71:
F_32 ( L_13 , V_64 ) ;
V_69:
F_32 ( L_12 , V_65 . V_66 ) ;
goto V_21;
}
void F_33 ( void )
{
F_32 ( L_13 , V_64 ) ;
F_32 ( L_14 , V_64 ) ;
F_32 ( L_12 , V_65 . V_66 ) ;
}
