static
struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 ( ! V_2 ) ;
F_3 (entry, &idletimer_tg_list, entry) {
if ( ! strcmp ( V_2 , V_3 -> V_4 . V_4 . V_5 ) )
return V_3 ;
}
return NULL ;
}
static T_1 F_4 ( struct V_6 * V_7 , struct V_8 * V_4 ,
char * V_9 )
{
struct V_1 * V_10 ;
unsigned long V_11 = 0 ;
F_5 ( & V_12 ) ;
V_10 = F_1 ( V_4 -> V_5 ) ;
if ( V_10 )
V_11 = V_10 -> V_10 . V_11 ;
F_6 ( & V_12 ) ;
if ( F_7 ( V_11 , V_13 ) )
return sprintf ( V_9 , L_1 ,
F_8 ( V_11 - V_13 ) / 1000 ) ;
return sprintf ( V_9 , L_2 ) ;
}
static void F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_10 = F_10 ( V_15 , struct V_1 ,
V_15 ) ;
F_11 ( V_16 , NULL , V_10 -> V_4 . V_4 . V_5 ) ;
}
static void F_12 ( unsigned long V_17 )
{
struct V_1 * V_10 = (struct V_1 * ) V_17 ;
F_13 ( L_3 , V_10 -> V_4 . V_4 . V_5 ) ;
F_14 ( & V_10 -> V_15 ) ;
}
static int F_15 ( struct V_18 * V_19 )
{
int V_20 ;
V_19 -> V_10 = F_16 ( sizeof( * V_19 -> V_10 ) , V_21 ) ;
if ( ! V_19 -> V_10 ) {
V_20 = - V_22 ;
goto V_23;
}
F_17 ( & V_19 -> V_10 -> V_4 . V_4 ) ;
V_19 -> V_10 -> V_4 . V_4 . V_5 = F_18 ( V_19 -> V_2 , V_21 ) ;
if ( ! V_19 -> V_10 -> V_4 . V_4 . V_5 ) {
V_20 = - V_22 ;
goto V_24;
}
V_19 -> V_10 -> V_4 . V_4 . V_25 = V_26 ;
V_19 -> V_10 -> V_4 . V_27 = F_4 ;
V_20 = F_19 ( V_16 , & V_19 -> V_10 -> V_4 . V_4 ) ;
if ( V_20 < 0 ) {
F_13 ( L_4 ) ;
goto V_28;
}
F_20 ( & V_19 -> V_10 -> V_3 , & V_29 ) ;
F_21 ( & V_19 -> V_10 -> V_10 , F_12 ,
( unsigned long ) V_19 -> V_10 ) ;
V_19 -> V_10 -> V_30 = 1 ;
F_22 ( & V_19 -> V_10 -> V_10 ,
F_23 ( V_19 -> V_31 * 1000 ) + V_13 ) ;
F_24 ( & V_19 -> V_10 -> V_15 , F_9 ) ;
return 0 ;
V_28:
F_25 ( V_19 -> V_10 -> V_4 . V_4 . V_5 ) ;
V_24:
F_25 ( V_19 -> V_10 ) ;
V_23:
return V_20 ;
}
static unsigned int F_26 ( struct V_32 * V_33 ,
const struct V_34 * V_35 )
{
const struct V_18 * V_19 = V_35 -> V_36 ;
F_13 ( L_5 ,
V_19 -> V_2 , V_19 -> V_31 ) ;
F_2 ( ! V_19 -> V_10 ) ;
F_22 ( & V_19 -> V_10 -> V_10 ,
F_23 ( V_19 -> V_31 * 1000 ) + V_13 ) ;
return V_37 ;
}
static int F_27 ( const struct V_38 * V_35 )
{
struct V_18 * V_19 = V_35 -> V_36 ;
int V_20 ;
F_13 ( L_6 , V_19 -> V_2 ) ;
if ( V_19 -> V_31 == 0 ) {
F_13 ( L_7 ) ;
return - V_39 ;
}
if ( V_19 -> V_2 [ 0 ] == '\0' ||
F_28 ( V_19 -> V_2 ,
V_40 ) == V_40 ) {
F_13 ( L_8 ) ;
return - V_39 ;
}
F_5 ( & V_12 ) ;
V_19 -> V_10 = F_1 ( V_19 -> V_2 ) ;
if ( V_19 -> V_10 ) {
V_19 -> V_10 -> V_30 ++ ;
F_22 ( & V_19 -> V_10 -> V_10 ,
F_23 ( V_19 -> V_31 * 1000 ) + V_13 ) ;
F_13 ( L_9 ,
V_19 -> V_2 , V_19 -> V_10 -> V_30 ) ;
} else {
V_20 = F_15 ( V_19 ) ;
if ( V_20 < 0 ) {
F_13 ( L_10 ) ;
F_6 ( & V_12 ) ;
return V_20 ;
}
}
F_6 ( & V_12 ) ;
return 0 ;
}
static void F_29 ( const struct V_41 * V_35 )
{
const struct V_18 * V_19 = V_35 -> V_36 ;
F_13 ( L_11 , V_19 -> V_2 ) ;
F_5 ( & V_12 ) ;
if ( -- V_19 -> V_10 -> V_30 == 0 ) {
F_13 ( L_12 , V_19 -> V_2 ) ;
F_30 ( & V_19 -> V_10 -> V_3 ) ;
F_31 ( & V_19 -> V_10 -> V_10 ) ;
F_32 ( V_16 , & V_19 -> V_10 -> V_4 . V_4 ) ;
F_25 ( V_19 -> V_10 -> V_4 . V_4 . V_5 ) ;
F_25 ( V_19 -> V_10 ) ;
} else {
F_13 ( L_13 ,
V_19 -> V_2 , V_19 -> V_10 -> V_30 ) ;
}
F_6 ( & V_12 ) ;
}
static int T_2 F_33 ( void )
{
int V_42 ;
V_43 = F_34 ( V_44 , L_14 ) ;
V_42 = F_35 ( V_43 ) ;
if ( F_36 ( V_43 ) ) {
F_13 ( L_15 ) ;
goto V_23;
}
V_45 = F_37 ( V_43 , NULL ,
F_38 ( 0 , 0 ) , NULL , L_16 ) ;
V_42 = F_35 ( V_45 ) ;
if ( F_36 ( V_45 ) ) {
F_13 ( L_17 ) ;
goto V_46;
}
V_16 = & V_45 -> V_7 ;
V_42 = F_39 ( & V_1 ) ;
if ( V_42 < 0 ) {
F_13 ( L_18 ) ;
goto V_47;
}
return 0 ;
V_47:
F_40 ( V_43 , F_38 ( 0 , 0 ) ) ;
V_46:
F_41 ( V_43 ) ;
V_23:
return V_42 ;
}
static void T_3 F_42 ( void )
{
F_43 ( & V_1 ) ;
F_40 ( V_43 , F_38 ( 0 , 0 ) ) ;
F_41 ( V_43 ) ;
}
