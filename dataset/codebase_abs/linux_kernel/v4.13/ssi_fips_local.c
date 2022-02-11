static enum V_1 F_1 ( struct V_2 * V_3 )
{
T_1 V_4 ;
void T_2 * V_5 = V_3 -> V_5 ;
V_4 = F_2 ( F_3 ( V_6 , V_7 ) ) ;
if ( V_4 == ( V_8 | V_9 ) )
return V_10 ;
return V_11 ;
}
static void F_4 ( struct V_2 * V_3 , enum V_12 V_13 )
{
void T_2 * V_5 = V_3 -> V_5 ;
if ( V_13 == V_10 )
F_5 ( F_3 ( V_6 , V_14 ) , ( V_15 | V_9 ) ) ;
else
F_5 ( F_3 ( V_6 , V_14 ) , ( V_15 | V_16 ) ) ;
}
void F_6 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_19 ;
if ( ! V_18 )
return;
#ifdef F_7
if ( V_18 -> V_20 ) {
F_8 ( V_18 -> V_20 ) ;
F_9 ( V_18 -> V_20 ) ;
}
#else
F_10 ( & V_18 -> V_21 ) ;
#endif
memset ( V_18 , 0 , sizeof( struct V_17 ) ) ;
F_11 ( V_18 ) ;
V_3 -> V_19 = NULL ;
}
void F_12 ( struct V_2 * V_3 )
{
struct V_17 * V_22 =
V_3 -> V_19 ;
#ifdef F_7
F_13 ( V_22 -> V_20 , & V_22 -> V_23 , 0 ) ;
#else
F_14 ( & V_22 -> V_21 ) ;
#endif
}
static void F_15 ( struct V_24 * V_25 )
{
struct V_2 * V_3 =
F_16 ( V_25 , struct V_2 , V_23 . V_25 ) ;
F_17 ( ( unsigned long ) V_3 ) ;
}
static void F_17 ( unsigned long V_26 )
{
struct V_2 * V_3 = (struct V_2 * ) V_26 ;
void T_2 * V_5 = V_3 -> V_5 ;
T_1 V_27 ;
T_1 V_28 = 0 ;
V_27 = ( V_3 -> V_27 & ( V_29 ) ) ;
if ( V_27 & V_29 ) {
V_28 = F_2 ( F_3 ( V_6 , V_7 ) ) ;
if ( V_28 != ( V_8 | V_9 ) )
F_18 ( V_3 , V_11 ) ;
}
F_5 ( F_3 ( V_6 , V_30 ) ,
F_2 (
F_3 ( V_6 , V_30 ) ) & ~ V_27 ) ;
}
enum V_12 F_19 ( struct V_2 * V_3 )
{
enum V_12 V_31 = V_10 ;
void * V_32 = NULL ;
T_3 V_33 ;
T_4 V_34 = F_20 () ;
struct V_35 * V_36 = & V_3 -> V_37 -> V_36 ;
F_21 ( L_1 ) ;
V_32 = F_22 ( V_36 , V_34 , & V_33 , V_38 ) ;
if ( ! V_32 )
return V_39 ;
F_21 ( L_2 , ( T_4 ) V_32 , V_34 ) ;
#if V_40
F_21 ( L_3 ) ;
V_31 = F_23 ( V_3 , V_32 , V_33 ) ;
F_21 ( L_4 , V_31 ) ;
#endif
#if V_41
if ( F_24 ( V_31 == V_10 ) ) {
F_21 ( L_5 ) ;
V_31 = F_25 ( V_3 , V_32 , V_33 ) ;
F_21 ( L_6 , V_31 ) ;
}
#endif
#if V_42
if ( F_24 ( V_31 == V_10 ) ) {
F_21 ( L_7 ) ;
V_31 = F_26 ( V_3 , V_32 , V_33 ) ;
F_21 ( L_8 , V_31 ) ;
}
#endif
#if V_43
if ( F_24 ( V_31 == V_10 ) ) {
F_21 ( L_9 ) ;
V_31 = F_27 ( V_3 , V_32 , V_33 ) ;
F_21 ( L_10 , V_31 ) ;
}
#endif
#if V_44
if ( F_24 ( V_31 == V_10 ) ) {
F_21 ( L_11 ) ;
V_31 = F_28 ( V_3 , V_32 , V_33 ) ;
F_21 ( L_12 , V_31 ) ;
}
#endif
#if V_45
if ( F_24 ( V_31 == V_10 ) ) {
F_21 ( L_13 ) ;
V_31 = F_29 ( V_3 , V_32 , V_33 ) ;
F_21 ( L_14 , V_31 ) ;
}
#endif
F_21 ( L_15 ) ;
F_30 ( V_36 , V_34 , V_32 , V_33 ) ;
return V_31 ;
}
int F_31 ( void )
{
enum V_46 V_47 ;
if ( F_32 ( & V_47 ) != 0 ) {
F_33 ( L_16 ) ;
return - V_48 ;
}
if ( V_47 == V_49 ) {
F_33 ( L_17 , V_47 ) ;
return - V_48 ;
}
return 0 ;
}
int F_34 ( enum V_46 V_50 )
{
return F_35 ( V_50 ) ;
}
int F_18 ( struct V_2 * V_51 , enum V_12 V_13 )
{
int V_52 = 0 ;
enum V_12 V_53 ;
F_33 ( L_18 , V_13 ) ;
if ( V_13 == V_10 )
return - V_48 ;
if ( F_36 ( & V_53 ) != 0 )
return - V_48 ;
if ( V_53 != V_10 )
return - V_48 ;
V_52 = F_37 ( V_13 ) ;
if ( V_52 != 0 )
return - V_48 ;
V_52 = F_35 ( V_49 ) ;
if ( V_52 != 0 )
return - V_48 ;
if ( V_13 != V_11 )
F_4 ( V_51 , V_13 ) ;
return V_52 ;
}
int F_38 ( struct V_2 * V_51 )
{
enum V_12 V_52 = V_10 ;
struct V_17 * V_18 ;
F_21 ( L_19 , V_54 ) ;
V_18 = F_39 ( sizeof( struct V_17 ) , V_38 ) ;
if ( ! V_18 ) {
F_18 ( V_51 , V_39 ) ;
return - V_55 ;
}
V_51 -> V_19 = V_18 ;
#ifdef F_7
F_40 ( L_20 ) ;
V_18 -> V_20 = F_41 ( L_21 ) ;
if ( F_42 ( ! V_18 -> V_20 ) ) {
F_43 ( L_22 ) ;
F_18 ( V_51 , V_39 ) ;
V_52 = - V_55 ;
goto V_56;
}
F_44 ( & V_18 -> V_23 , F_15 ) ;
#else
F_40 ( L_23 ) ;
F_45 ( & V_18 -> V_21 , F_17 , ( unsigned long ) V_51 ) ;
#endif
V_52 = F_34 ( ( V_54 == 0 ) ? V_57 : V_58 ) ;
if ( F_42 ( V_52 != 0 ) ) {
F_18 ( V_51 , V_39 ) ;
V_52 = - V_59 ;
goto V_56;
}
F_21 ( L_24 ) ;
V_52 = F_1 ( V_51 ) ;
if ( F_42 ( V_52 != V_10 ) ) {
F_18 ( V_51 , V_11 ) ;
V_52 = - V_59 ;
goto V_56;
}
F_21 ( L_25 ) ;
V_52 = F_19 ( V_51 ) ;
if ( F_42 ( V_52 != V_10 ) ) {
F_18 ( V_51 , V_52 ) ;
V_52 = - V_59 ;
goto V_56;
}
F_33 ( L_26 , V_52 ) ;
F_4 ( V_51 , V_10 ) ;
if ( F_42 ( V_52 != 0 ) ) {
V_52 = - V_59 ;
F_18 ( V_51 , V_39 ) ;
goto V_56;
}
return 0 ;
V_56:
F_6 ( V_51 ) ;
return V_52 ;
}
