static int T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_9 ;
if ( ! V_7 )
return - V_10 ;
* V_5 = F_2 ( V_7 ) ;
V_4 -> V_11 = F_3 ( V_7 ) ;
V_4 -> V_12 = F_4 ( & V_2 -> V_8 ,
sizeof( struct V_13 ) ,
V_14 ) ;
if ( F_5 ( V_7 , L_1 ) ) {
V_4 -> V_15 = 8 ;
V_4 -> V_16 = 1 ;
V_4 -> V_17 = 1 ;
}
return 0 ;
}
static int T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * * V_5 )
{
return - V_18 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_19 = 0 ;
struct V_20 * V_21 ;
void T_2 * V_22 = NULL ;
struct V_23 * V_24 = NULL ;
struct V_3 * V_25 = NULL ;
const char * V_5 = NULL ;
V_21 = F_7 ( V_2 , V_26 , 0 ) ;
if ( ! V_21 )
return - V_10 ;
if ( ! F_8 ( V_21 -> V_27 , F_9 ( V_21 ) , V_2 -> V_28 ) ) {
F_10 ( L_2
L_3 ,
V_29 , ( unsigned int ) V_21 -> V_27 ) ;
return - V_30 ;
}
V_22 = F_11 ( V_21 -> V_27 , F_9 ( V_21 ) ) ;
if ( ! V_22 ) {
F_10 ( L_4 , V_29 ) ;
V_19 = - V_31 ;
goto V_32;
}
if ( V_2 -> V_8 . V_9 ) {
V_25 = F_4 ( & V_2 -> V_8 ,
sizeof( struct V_3 ) ,
V_14 ) ;
if ( ! V_25 ) {
F_10 ( L_5 , V_29 ) ;
V_19 = - V_31 ;
goto V_33;
}
V_19 = F_1 ( V_2 , V_25 , & V_5 ) ;
if ( V_19 ) {
F_10 ( L_6 , V_29 ) ;
goto V_33;
}
} else {
V_25 = V_2 -> V_8 . V_34 ;
}
if ( V_25 -> V_35 ) {
V_19 = V_25 -> V_35 ( V_2 ) ;
if ( F_12 ( V_19 ) )
goto V_33;
}
V_24 = F_13 ( & ( V_2 -> V_8 ) , V_25 , V_22 ) ;
if ( ! V_24 ) {
F_10 ( L_7 , V_29 ) ;
goto V_33;
}
if ( V_5 )
memcpy ( V_24 -> V_8 -> V_36 , V_5 , V_37 ) ;
V_24 -> V_8 -> V_38 = F_14 ( V_2 , L_8 ) ;
if ( V_24 -> V_8 -> V_38 == - V_39 ) {
F_10 ( L_9
L_10 , V_29 ) ;
V_19 = - V_39 ;
goto V_33;
}
V_24 -> V_40 = F_14 ( V_2 , L_11 ) ;
if ( V_24 -> V_40 == - V_39 )
V_24 -> V_40 = V_24 -> V_8 -> V_38 ;
F_15 ( V_2 , V_24 -> V_8 ) ;
F_16 ( L_12 ) ;
return 0 ;
V_33:
F_17 ( V_22 ) ;
F_15 ( V_2 , NULL ) ;
V_32:
F_18 ( V_21 -> V_27 , F_9 ( V_21 ) ) ;
return V_19 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = F_20 ( V_2 ) ;
struct V_23 * V_24 = F_21 ( V_42 ) ;
struct V_20 * V_21 ;
int V_19 = F_22 ( V_42 ) ;
if ( V_24 -> V_4 -> exit )
V_24 -> V_4 -> exit ( V_2 ) ;
if ( V_24 -> V_4 -> exit )
V_24 -> V_4 -> exit ( V_2 ) ;
F_15 ( V_2 , NULL ) ;
F_17 ( ( void * ) V_24 -> V_43 ) ;
V_21 = F_7 ( V_2 , V_26 , 0 ) ;
F_18 ( V_21 -> V_27 , F_9 ( V_21 ) ) ;
return V_19 ;
}
static int F_23 ( struct V_44 * V_8 )
{
struct V_41 * V_42 = F_24 ( V_8 ) ;
return F_25 ( V_42 ) ;
}
static int F_26 ( struct V_44 * V_8 )
{
struct V_41 * V_42 = F_24 ( V_8 ) ;
return F_27 ( V_42 ) ;
}
int F_28 ( struct V_44 * V_8 )
{
struct V_41 * V_42 = F_24 ( V_8 ) ;
return F_29 ( V_42 ) ;
}
int F_30 ( struct V_44 * V_8 )
{
struct V_41 * V_42 = F_24 ( V_8 ) ;
return F_31 ( V_42 ) ;
}
