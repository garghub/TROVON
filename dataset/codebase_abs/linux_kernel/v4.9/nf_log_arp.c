static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 , unsigned int V_7 )
{
const struct V_8 * V_9 ;
struct V_8 V_10 ;
const struct V_11 * V_12 ;
struct V_11 V_13 ;
V_9 = F_2 ( V_6 , 0 , sizeof( V_10 ) , & V_10 ) ;
if ( V_9 == NULL ) {
F_3 ( V_2 , L_1 ) ;
return;
}
F_3 ( V_2 , L_2 ,
F_4 ( V_9 -> V_14 ) , F_4 ( V_9 -> V_15 ) , F_4 ( V_9 -> V_16 ) ) ;
if ( V_9 -> V_14 != F_5 ( V_17 ) ||
V_9 -> V_18 != V_19 ||
V_9 -> V_20 != sizeof( V_21 ) )
return;
V_12 = F_2 ( V_6 , sizeof( V_10 ) , sizeof( V_13 ) , & V_13 ) ;
if ( V_12 == NULL ) {
F_3 ( V_2 , L_3 ,
V_6 -> V_22 - sizeof( V_10 ) ) ;
return;
}
F_3 ( V_2 , L_4 ,
V_12 -> V_23 , V_12 -> V_24 , V_12 -> V_25 , V_12 -> V_26 ) ;
}
static void F_6 ( struct V_27 * V_27 , T_1 V_28 ,
unsigned int V_29 , const struct V_5 * V_6 ,
const struct V_30 * V_31 ,
const struct V_30 * V_32 ,
const struct V_3 * V_33 ,
const char * V_34 )
{
struct V_1 * V_2 ;
if ( ! F_7 ( V_27 , & V_35 ) )
return;
V_2 = F_8 () ;
if ( ! V_33 )
V_33 = & V_36 ;
F_9 ( V_2 , V_28 , V_29 , V_6 , V_31 , V_32 , V_33 ,
V_34 ) ;
F_1 ( V_2 , V_33 , V_6 , 0 ) ;
F_10 ( V_2 ) ;
}
static int T_2 F_11 ( struct V_27 * V_27 )
{
return F_12 ( V_27 , V_37 , & V_38 ) ;
}
static void T_3 F_13 ( struct V_27 * V_27 )
{
F_14 ( V_27 , & V_38 ) ;
}
static int T_4 F_15 ( void )
{
int V_39 ;
V_39 = F_16 ( & V_40 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_17 ( V_37 , & V_38 ) ;
if ( V_39 < 0 ) {
F_18 ( L_5 ) ;
goto V_41;
}
return 0 ;
V_41:
F_19 ( & V_40 ) ;
return V_39 ;
}
static void T_5 F_20 ( void )
{
F_19 ( & V_40 ) ;
F_21 ( & V_38 ) ;
}
