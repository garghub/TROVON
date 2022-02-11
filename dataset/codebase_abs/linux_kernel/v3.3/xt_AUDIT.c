static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
switch ( V_5 ) {
case V_7 :
case V_8 :
case V_9 : {
const T_1 * V_10 ;
T_1 V_11 [ 2 ] ;
V_10 = F_2 ( V_4 , V_6 , sizeof( V_11 ) , V_11 ) ;
if ( V_10 == NULL ) {
F_3 ( V_2 , L_1 ) ;
return;
}
F_3 ( V_2 , L_2 ,
F_4 ( V_10 [ 0 ] ) , F_4 ( V_10 [ 1 ] ) ) ;
}
break;
case V_12 :
case V_13 : {
const T_2 * V_14 ;
T_2 V_15 [ 2 ] ;
V_14 = F_2 ( V_4 , V_6 , sizeof( V_15 ) , & V_15 ) ;
if ( V_14 == NULL ) {
F_3 ( V_2 , L_1 ) ;
return;
}
F_3 ( V_2 , L_3 ,
V_14 [ 0 ] , V_14 [ 1 ] ) ;
}
break;
}
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_16 V_17 ;
const struct V_16 * V_18 ;
V_18 = F_2 ( V_4 , 0 , sizeof( V_17 ) , & V_17 ) ;
if ( ! V_18 ) {
F_3 ( V_2 , L_1 ) ;
return;
}
F_3 ( V_2 , L_4 ,
& V_18 -> V_19 , & V_18 -> V_20 , F_4 ( V_18 -> V_21 ) , V_18 -> V_22 ) ;
if ( F_4 ( V_18 -> V_23 ) & V_24 ) {
F_3 ( V_2 , L_5 ) ;
return;
}
F_1 ( V_2 , V_4 , V_18 -> V_22 , V_18 -> V_25 * 4 ) ;
}
static void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_26 V_27 ;
const struct V_26 * V_18 ;
T_2 V_28 ;
T_1 V_23 ;
int V_6 ;
V_18 = F_2 ( V_4 , F_7 ( V_4 ) , sizeof( V_27 ) , & V_27 ) ;
if ( ! V_18 ) {
F_3 ( V_2 , L_1 ) ;
return;
}
V_28 = V_18 -> V_28 ;
V_6 = F_8 ( V_4 , F_7 ( V_4 ) + sizeof( V_27 ) ,
& V_28 , & V_23 ) ;
F_3 ( V_2 , L_6 ,
& V_18 -> V_19 , & V_18 -> V_20 , V_28 ) ;
if ( V_6 )
F_1 ( V_2 , V_4 , V_28 , V_6 ) ;
}
static unsigned int
F_9 ( struct V_3 * V_4 , const struct V_29 * V_30 )
{
const struct V_31 * V_32 = V_30 -> V_33 ;
struct V_1 * V_2 ;
V_2 = F_10 ( NULL , V_34 , V_35 ) ;
if ( V_2 == NULL )
goto V_36;
F_3 ( V_2 , L_7 ,
V_32 -> type , V_30 -> V_37 , V_4 -> V_38 ,
V_30 -> V_39 ? V_30 -> V_39 -> V_40 : L_8 ,
V_30 -> V_41 ? V_30 -> V_41 -> V_40 : L_8 ) ;
if ( V_4 -> V_42 )
F_3 ( V_2 , L_9 , V_4 -> V_42 ) ;
if ( V_4 -> V_43 && V_4 -> V_43 -> type == V_44 ) {
F_3 ( V_2 , L_10 ,
F_11 ( V_4 ) -> V_45 , F_11 ( V_4 ) -> V_46 ,
F_4 ( F_11 ( V_4 ) -> V_47 ) ) ;
if ( V_30 -> V_48 == V_49 ) {
switch ( F_11 ( V_4 ) -> V_47 ) {
case F_12 ( V_50 ) :
F_5 ( V_2 , V_4 ) ;
break;
case F_12 ( V_51 ) :
F_6 ( V_2 , V_4 ) ;
break;
}
}
}
switch ( V_30 -> V_48 ) {
case V_52 :
F_5 ( V_2 , V_4 ) ;
break;
case V_53 :
F_6 ( V_2 , V_4 ) ;
break;
}
#ifdef F_13
if ( V_4 -> V_54 )
F_14 ( V_2 , V_4 -> V_54 ) ;
#endif
F_15 ( V_2 ) ;
V_36:
return V_55 ;
}
static unsigned int
F_16 ( struct V_3 * V_4 , const struct V_29 * V_30 )
{
F_9 ( V_4 , V_30 ) ;
return V_56 ;
}
static int F_17 ( const struct V_57 * V_30 )
{
const struct V_31 * V_32 = V_30 -> V_33 ;
if ( V_32 -> type > V_58 ) {
F_18 ( L_11 ,
V_58 ) ;
return - V_59 ;
}
return 0 ;
}
static int T_3 F_19 ( void )
{
return F_20 ( V_60 , F_21 ( V_60 ) ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( V_60 , F_21 ( V_60 ) ) ;
}
