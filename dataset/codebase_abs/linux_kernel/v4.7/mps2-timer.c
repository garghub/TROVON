static T_1 T_2 F_1 ( void )
{
return ~ F_2 ( V_1 + V_2 ) ;
}
static inline struct V_3 * F_3 ( struct V_4 * V_5 )
{
return F_4 ( V_5 , struct V_3 , V_6 ) ;
}
static void F_5 ( T_3 V_7 , struct V_4 * V_5 , T_3 V_8 )
{
F_6 ( V_7 , F_3 ( V_5 ) -> V_9 + V_8 ) ;
}
static int F_7 ( struct V_4 * V_10 )
{
F_5 ( 0 , V_10 , V_11 ) ;
F_5 ( 0 , V_10 , V_12 ) ;
return 0 ;
}
static int F_8 ( unsigned long V_13 , struct V_4 * V_10 )
{
F_5 ( V_13 , V_10 , V_2 ) ;
F_5 ( V_14 | V_15 , V_10 , V_12 ) ;
return 0 ;
}
static int F_9 ( struct V_4 * V_10 )
{
T_3 V_16 = F_3 ( V_10 ) -> V_16 ;
F_5 ( V_16 , V_10 , V_11 ) ;
F_5 ( V_16 , V_10 , V_2 ) ;
F_5 ( V_14 | V_15 , V_10 , V_12 ) ;
return 0 ;
}
static T_4 F_10 ( int V_17 , void * V_18 )
{
struct V_3 * V_10 = V_18 ;
T_3 V_19 = F_2 ( V_10 -> V_9 + V_20 ) ;
if ( ! V_19 ) {
F_11 ( L_1 ) ;
return V_21 ;
}
F_6 ( 1 , V_10 -> V_9 + V_20 ) ;
V_10 -> V_6 . V_22 ( & V_10 -> V_6 ) ;
return V_23 ;
}
static int T_5 F_12 ( struct V_24 * V_25 )
{
void T_6 * V_26 ;
struct V_27 * V_27 = NULL ;
struct V_3 * V_10 ;
T_3 V_28 ;
int V_17 , V_29 ;
const char * V_30 = L_2 ;
V_29 = F_13 ( V_25 , L_3 , & V_28 ) ;
if ( V_29 ) {
V_27 = F_14 ( V_25 , 0 ) ;
if ( F_15 ( V_27 ) ) {
V_29 = F_16 ( V_27 ) ;
F_17 ( L_4 , V_29 ) ;
goto V_31;
}
V_29 = F_18 ( V_27 ) ;
if ( V_29 ) {
F_17 ( L_5 , V_29 ) ;
goto V_32;
}
V_28 = F_19 ( V_27 ) ;
}
V_26 = F_20 ( V_25 , 0 ) ;
if ( ! V_26 ) {
V_29 = - V_33 ;
F_17 ( L_6 , V_29 ) ;
goto V_34;
}
V_17 = F_21 ( V_25 , 0 ) ;
if ( ! V_17 ) {
V_29 = - V_35 ;
F_17 ( L_7 , V_29 ) ;
goto V_36;
}
V_10 = F_22 ( sizeof( * V_10 ) , V_37 ) ;
if ( ! V_10 ) {
V_29 = - V_38 ;
goto V_36;
}
V_10 -> V_9 = V_26 ;
V_10 -> V_16 = F_23 ( V_28 , V_39 ) ;
V_10 -> V_6 . V_17 = V_17 ;
V_10 -> V_6 . V_30 = V_30 ;
V_10 -> V_6 . V_40 = 200 ;
V_10 -> V_6 . V_41 = V_42 | V_43 ;
V_10 -> V_6 . V_44 = V_45 ;
V_10 -> V_6 . V_46 = F_7 ,
V_10 -> V_6 . V_47 = F_9 ,
V_10 -> V_6 . V_48 = F_7 ,
V_10 -> V_6 . V_49 = F_8 ;
F_6 ( 0 , V_26 + V_12 ) ;
V_29 = F_24 ( V_17 , F_10 , V_50 , V_30 , V_10 ) ;
if ( V_29 ) {
F_17 ( L_8 , V_29 ) ;
goto V_51;
}
F_25 ( & V_10 -> V_6 , V_28 , 0xf , 0xffffffff ) ;
return 0 ;
V_51:
F_26 ( V_10 ) ;
V_36:
F_27 ( V_26 ) ;
V_34:
F_28 ( V_27 ) ;
V_32:
F_29 ( V_27 ) ;
V_31:
return V_29 ;
}
static int T_5 F_30 ( struct V_24 * V_25 )
{
void T_6 * V_26 ;
struct V_27 * V_27 = NULL ;
T_3 V_28 ;
int V_29 ;
const char * V_30 = L_9 ;
V_29 = F_13 ( V_25 , L_3 , & V_28 ) ;
if ( V_29 ) {
V_27 = F_14 ( V_25 , 0 ) ;
if ( F_15 ( V_27 ) ) {
V_29 = F_16 ( V_27 ) ;
F_17 ( L_10 , V_29 ) ;
goto V_31;
}
V_29 = F_18 ( V_27 ) ;
if ( V_29 ) {
F_17 ( L_11 , V_29 ) ;
goto V_32;
}
V_28 = F_19 ( V_27 ) ;
}
V_26 = F_20 ( V_25 , 0 ) ;
if ( ! V_26 ) {
V_29 = - V_33 ;
F_17 ( L_12 , V_29 ) ;
goto V_34;
}
F_6 ( 0 , V_26 + V_12 ) ;
F_6 ( 0xffffffff , V_26 + V_2 ) ;
F_6 ( 0xffffffff , V_26 + V_11 ) ;
F_6 ( V_15 , V_26 + V_12 ) ;
V_29 = F_31 ( V_26 + V_2 , V_30 ,
V_28 , 200 , 32 ,
V_52 ) ;
if ( V_29 ) {
F_17 ( L_13 , V_29 ) ;
goto V_36;
}
V_1 = V_26 ;
F_32 ( F_1 , 32 , V_28 ) ;
return 0 ;
V_36:
F_27 ( V_26 ) ;
V_34:
F_28 ( V_27 ) ;
V_32:
F_29 ( V_27 ) ;
V_31:
return V_29 ;
}
static void T_5 F_33 ( struct V_24 * V_25 )
{
static int V_53 , V_54 ;
int V_29 ;
if ( ! V_53 ) {
V_29 = F_30 ( V_25 ) ;
if ( ! V_29 ) {
V_53 = 1 ;
return;
}
}
if ( ! V_54 ) {
V_29 = F_12 ( V_25 ) ;
if ( ! V_29 ) {
V_54 = 1 ;
return;
}
}
}
