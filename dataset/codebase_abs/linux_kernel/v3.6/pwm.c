int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
unsigned long long V_5 ;
unsigned long V_6 , V_7 , V_8 , V_9 ;
if ( V_2 == NULL || V_4 == 0 || V_3 > V_4 )
return - V_10 ;
V_5 = F_2 ( V_2 -> V_11 ) ;
V_5 = V_5 * V_4 ;
F_3 ( V_5 , 1000000000 ) ;
V_6 = V_5 ;
if ( V_6 < 1 )
V_6 = 1 ;
V_7 = ( V_6 - 1 ) / 1024 ;
V_8 = V_6 / ( V_7 + 1 ) - 1 ;
if ( V_7 > 63 )
return - V_10 ;
if ( V_3 == V_4 )
V_9 = V_12 ;
else
V_9 = ( V_8 + 1 ) * V_3 / V_4 ;
F_4 ( V_2 -> V_11 ) ;
V_13 = V_7 ;
V_14 = V_8 - V_9 ;
V_15 = V_8 ;
F_5 ( V_2 -> V_11 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_16 = 0 ;
if ( ! V_2 -> V_17 ) {
V_16 = F_4 ( V_2 -> V_11 ) ;
if ( ! V_16 )
V_2 -> V_17 = 1 ;
}
return V_16 ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 ) {
F_5 ( V_2 -> V_11 ) ;
V_2 -> V_17 = 0 ;
}
}
struct V_1 * F_8 ( int V_18 , const char * V_19 )
{
struct V_1 * V_2 ;
int V_20 = 0 ;
F_9 ( & V_21 ) ;
F_10 (pwm, &pwm_list, node) {
if ( V_2 -> V_18 == V_18 ) {
V_20 = 1 ;
break;
}
}
if ( V_20 ) {
if ( V_2 -> V_22 == 0 ) {
V_2 -> V_22 ++ ;
V_2 -> V_19 = V_19 ;
} else
V_2 = F_11 ( - V_23 ) ;
} else
V_2 = F_11 ( - V_24 ) ;
F_12 ( & V_21 ) ;
return V_2 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_9 ( & V_21 ) ;
if ( V_2 -> V_22 ) {
V_2 -> V_22 -- ;
V_2 -> V_19 = NULL ;
} else
F_14 ( L_1 ) ;
F_12 ( & V_21 ) ;
}
static inline void F_15 ( struct V_1 * V_2 )
{
F_9 ( & V_21 ) ;
F_16 ( & V_2 -> V_25 , & V_26 ) ;
F_12 ( & V_21 ) ;
}
static struct V_1 * F_17 ( struct V_27 * V_28 ,
unsigned int V_18 , struct V_1 * V_29 )
{
struct V_1 * V_2 ;
struct V_30 * V_31 ;
int V_32 = 0 ;
V_2 = F_18 ( sizeof( struct V_1 ) , V_33 ) ;
if ( V_2 == NULL ) {
F_19 ( & V_28 -> V_34 , L_2 ) ;
return F_11 ( - V_35 ) ;
}
V_2 -> V_11 = F_20 ( NULL , L_3 ) ;
if ( F_21 ( V_2 -> V_11 ) ) {
V_32 = F_22 ( V_2 -> V_11 ) ;
goto V_36;
}
V_2 -> V_17 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_28 = V_28 ;
V_31 = F_23 ( V_28 , V_37 , 0 ) ;
if ( V_31 == NULL ) {
F_19 ( & V_28 -> V_34 , L_4 ) ;
V_32 = - V_38 ;
goto V_39;
}
V_31 = F_24 ( V_31 -> V_40 , F_25 ( V_31 ) , V_28 -> V_41 ) ;
if ( V_31 == NULL ) {
F_19 ( & V_28 -> V_34 , L_5 ) ;
V_32 = - V_23 ;
goto V_39;
}
F_15 ( V_2 ) ;
F_26 ( V_28 , V_2 ) ;
return V_2 ;
V_39:
F_27 ( V_2 -> V_11 ) ;
V_36:
F_28 ( V_2 ) ;
return F_11 ( V_32 ) ;
}
static int T_1 F_29 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_17 ( V_28 , V_28 -> V_42 , NULL ) ;
if ( F_21 ( V_2 ) )
return F_22 ( V_2 ) ;
return 0 ;
}
static int T_2 F_30 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_30 * V_31 ;
V_2 = F_31 ( V_28 ) ;
if ( V_2 == NULL )
return - V_38 ;
F_9 ( & V_21 ) ;
F_32 ( & V_2 -> V_25 ) ;
F_12 ( & V_21 ) ;
V_31 = F_23 ( V_28 , V_37 , 0 ) ;
F_33 ( V_31 -> V_40 , F_25 ( V_31 ) ) ;
F_27 ( V_2 -> V_11 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
static int T_3 F_34 ( void )
{
int V_32 = 0 ;
V_32 = F_35 ( & V_43 ) ;
if ( V_32 ) {
F_36 ( V_44 L_6 ) ;
return V_32 ;
}
return V_32 ;
}
static void T_4 F_37 ( void )
{
F_38 ( & V_43 ) ;
}
