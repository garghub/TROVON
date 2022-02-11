static enum V_1 F_1 ( struct V_2 * V_3 )
{
T_1 V_4 ;
void T_2 * V_5 = V_3 -> V_5 ;
V_4 = F_2 ( F_3 ( V_6 , V_7 ) ) ;
if ( V_4 == ( V_8 | V_9 ) ) {
return V_10 ;
}
return V_11 ;
}
static void F_4 ( struct V_2 * V_3 , T_3 V_12 )
{
void T_2 * V_5 = V_3 -> V_5 ;
if ( V_12 == V_10 ) {
F_5 ( F_3 ( V_6 , V_13 ) , ( V_14 | V_9 ) ) ;
} else {
F_5 ( F_3 ( V_6 , V_13 ) , ( V_14 | V_15 ) ) ;
}
}
void F_6 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = V_3 -> V_18 ;
if ( V_17 == NULL )
return;
#ifdef F_7
if ( V_17 -> V_19 != NULL ) {
F_8 ( V_17 -> V_19 ) ;
F_9 ( V_17 -> V_19 ) ;
}
#else
F_10 ( & V_17 -> V_20 ) ;
#endif
memset ( V_17 , 0 , sizeof( struct V_16 ) ) ;
F_11 ( V_17 ) ;
V_3 -> V_18 = NULL ;
}
void F_12 ( struct V_2 * V_3 )
{
struct V_16 * V_21 =
V_3 -> V_18 ;
#ifdef F_7
F_13 ( V_21 -> V_19 , & V_21 -> V_22 , 0 ) ;
#else
F_14 ( & V_21 -> V_20 ) ;
#endif
}
static void F_15 ( struct V_23 * V_24 )
{
struct V_2 * V_3 =
F_16 ( V_24 , struct V_2 , V_22 . V_24 ) ;
F_17 ( ( unsigned long ) V_3 ) ;
}
static void F_17 ( unsigned long V_25 )
{
struct V_2 * V_3 = (struct V_2 * ) V_25 ;
void T_2 * V_5 = V_3 -> V_5 ;
T_1 V_26 ;
T_1 V_27 = 0 ;
V_26 = ( V_3 -> V_26 & ( V_28 ) ) ;
if ( V_26 & V_28 ) {
V_27 = F_2 ( F_3 ( V_6 , V_7 ) ) ;
if ( V_27 != ( V_8 | V_9 ) ) {
F_18 ( V_3 , V_11 ) ;
}
}
F_5 ( F_3 ( V_6 , V_29 ) ,
F_2 (
F_3 ( V_6 , V_29 ) ) & ~ V_26 ) ;
}
T_3 F_19 ( struct V_2 * V_3 )
{
T_3 V_30 = V_10 ;
void * V_31 = NULL ;
T_4 V_32 ;
T_5 V_33 = F_20 () ;
struct V_34 * V_35 = & V_3 -> V_36 -> V_35 ;
F_21 ( L_1 ) ;
V_31 = F_22 ( V_35 , V_33 , & V_32 , V_37 ) ;
if ( V_31 == NULL ) {
return V_38 ;
}
F_21 ( L_2 , ( T_5 ) V_31 , V_33 ) ;
#if V_39
F_21 ( L_3 ) ;
V_30 = F_23 ( V_3 , V_31 , V_32 ) ;
F_21 ( L_4 , V_30 ) ;
#endif
#if V_40
if ( F_24 ( V_30 == V_10 ) ) {
F_21 ( L_5 ) ;
V_30 = F_25 ( V_3 , V_31 , V_32 ) ;
F_21 ( L_6 , V_30 ) ;
}
#endif
#if V_41
if ( F_24 ( V_30 == V_10 ) ) {
F_21 ( L_7 ) ;
V_30 = F_26 ( V_3 , V_31 , V_32 ) ;
F_21 ( L_8 , V_30 ) ;
}
#endif
#if V_42
if ( F_24 ( V_30 == V_10 ) ) {
F_21 ( L_9 ) ;
V_30 = F_27 ( V_3 , V_31 , V_32 ) ;
F_21 ( L_10 , V_30 ) ;
}
#endif
#if V_43
if ( F_24 ( V_30 == V_10 ) ) {
F_21 ( L_11 ) ;
V_30 = F_28 ( V_3 , V_31 , V_32 ) ;
F_21 ( L_12 , V_30 ) ;
}
#endif
#if V_44
if ( F_24 ( V_30 == V_10 ) ) {
F_21 ( L_13 ) ;
V_30 = F_29 ( V_3 , V_31 , V_32 ) ;
F_21 ( L_14 , V_30 ) ;
}
#endif
F_21 ( L_15 ) ;
F_30 ( V_35 , V_33 , V_31 , V_32 ) ;
return V_30 ;
}
int F_31 ( void )
{
T_6 V_45 ;
if ( F_32 ( & V_45 ) != 0 ) {
F_33 ( L_16 ) ;
return - V_46 ;
}
if ( V_45 == V_47 ) {
F_33 ( L_17 , V_45 ) ;
return - V_46 ;
}
return 0 ;
}
int F_34 ( T_6 V_48 )
{
return F_35 ( V_48 ) ;
}
int F_18 ( struct V_2 * V_49 , T_3 V_12 )
{
int V_50 = 0 ;
T_3 V_51 ;
F_33 ( L_18 , V_12 ) ;
if ( V_12 == V_10 ) {
return - V_46 ;
}
if ( F_36 ( & V_51 ) != 0 ) {
return - V_46 ;
}
if ( V_51 != V_10 ) {
return - V_46 ;
}
V_50 = F_37 ( V_12 ) ;
if ( V_50 != 0 ) {
return - V_46 ;
}
V_50 = F_35 ( V_47 ) ;
if ( V_50 != 0 ) {
return - V_46 ;
}
if ( V_12 != V_11 ) {
F_4 ( V_49 , V_12 ) ;
}
return V_50 ;
}
int F_38 ( struct V_2 * V_49 )
{
T_3 V_50 = V_10 ;
struct V_16 * V_17 ;
F_21 ( L_19 , V_52 ) ;
V_17 = F_39 ( sizeof( struct V_16 ) , V_37 ) ;
if ( V_17 == NULL ) {
F_18 ( V_49 , V_38 ) ;
return - V_53 ;
}
V_49 -> V_18 = V_17 ;
#ifdef F_7
F_40 ( L_20 ) ;
V_17 -> V_19 = F_41 ( L_21 ) ;
if ( F_42 ( V_17 -> V_19 == NULL ) ) {
F_43 ( L_22 ) ;
F_18 ( V_49 , V_38 ) ;
V_50 = - V_53 ;
goto V_54;
}
F_44 ( & V_17 -> V_22 , F_15 ) ;
#else
F_40 ( L_23 ) ;
F_45 ( & V_17 -> V_20 , F_17 , ( unsigned long ) V_49 ) ;
#endif
V_50 = F_34 ( ( V_52 == 0 ) ? V_55 : V_56 ) ;
if ( F_42 ( V_50 != 0 ) ) {
F_18 ( V_49 , V_38 ) ;
V_50 = - V_57 ;
goto V_54;
}
F_21 ( L_24 ) ;
V_50 = F_1 ( V_49 ) ;
if ( F_42 ( V_50 != V_10 ) ) {
F_18 ( V_49 , V_11 ) ;
V_50 = - V_57 ;
goto V_54;
}
F_21 ( L_25 ) ;
V_50 = F_19 ( V_49 ) ;
if ( F_42 ( V_50 != V_10 ) ) {
F_18 ( V_49 , V_50 ) ;
V_50 = - V_57 ;
goto V_54;
}
F_33 ( L_26 , V_50 ) ;
F_4 ( V_49 , V_10 ) ;
if ( F_42 ( V_50 != 0 ) ) {
V_50 = - V_57 ;
F_18 ( V_49 , V_38 ) ;
goto V_54;
}
return 0 ;
V_54:
F_6 ( V_49 ) ;
return V_50 ;
}
