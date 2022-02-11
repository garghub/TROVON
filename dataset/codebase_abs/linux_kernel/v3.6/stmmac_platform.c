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
if ( F_5 ( V_7 , L_1 ) ||
F_5 ( V_7 , L_2 ) ||
F_5 ( V_7 , L_3 ) ) {
V_4 -> V_15 = 1 ;
V_4 -> V_16 = 1 ;
}
return 0 ;
}
static int T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * * V_5 )
{
return - V_17 ;
}
static int T_1 F_6 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
struct V_19 * V_20 ;
void T_2 * V_21 = NULL ;
struct V_22 * V_23 = NULL ;
struct V_3 * V_24 = NULL ;
const char * V_5 = NULL ;
V_20 = F_7 ( V_2 , V_25 , 0 ) ;
if ( ! V_20 )
return - V_10 ;
if ( ! F_8 ( V_20 -> V_26 , F_9 ( V_20 ) , V_2 -> V_27 ) ) {
F_10 ( L_4
L_5 ,
V_28 , ( unsigned int ) V_20 -> V_26 ) ;
return - V_29 ;
}
V_21 = F_11 ( V_20 -> V_26 , F_9 ( V_20 ) ) ;
if ( ! V_21 ) {
F_10 ( L_6 , V_28 ) ;
V_18 = - V_30 ;
goto V_31;
}
if ( V_2 -> V_8 . V_9 ) {
V_24 = F_4 ( & V_2 -> V_8 ,
sizeof( struct V_3 ) ,
V_14 ) ;
if ( ! V_24 ) {
F_10 ( L_7 , V_28 ) ;
V_18 = - V_30 ;
goto V_32;
}
V_18 = F_1 ( V_2 , V_24 , & V_5 ) ;
if ( V_18 ) {
F_10 ( L_8 , V_28 ) ;
goto V_32;
}
} else {
V_24 = V_2 -> V_8 . V_33 ;
}
if ( V_24 -> V_34 ) {
V_18 = V_24 -> V_34 ( V_2 ) ;
if ( F_12 ( V_18 ) )
goto V_32;
}
V_23 = F_13 ( & ( V_2 -> V_8 ) , V_24 , V_21 ) ;
if ( ! V_23 ) {
F_10 ( L_9 , V_28 ) ;
goto V_32;
}
if ( V_5 )
memcpy ( V_23 -> V_8 -> V_35 , V_5 , V_36 ) ;
V_23 -> V_8 -> V_37 = F_14 ( V_2 , L_10 ) ;
if ( V_23 -> V_8 -> V_37 == - V_38 ) {
F_10 ( L_11
L_12 , V_28 ) ;
V_18 = - V_38 ;
goto V_32;
}
V_23 -> V_39 = F_14 ( V_2 , L_13 ) ;
if ( V_23 -> V_39 == - V_38 )
V_23 -> V_39 = V_23 -> V_8 -> V_37 ;
V_23 -> V_40 = F_14 ( V_2 , L_14 ) ;
F_15 ( V_2 , V_23 -> V_8 ) ;
F_16 ( L_15 ) ;
return 0 ;
V_32:
F_17 ( V_21 ) ;
F_15 ( V_2 , NULL ) ;
V_31:
F_18 ( V_20 -> V_26 , F_9 ( V_20 ) ) ;
return V_18 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = F_20 ( V_2 ) ;
struct V_22 * V_23 = F_21 ( V_42 ) ;
struct V_19 * V_20 ;
int V_18 = F_22 ( V_42 ) ;
if ( V_23 -> V_4 -> exit )
V_23 -> V_4 -> exit ( V_2 ) ;
F_15 ( V_2 , NULL ) ;
F_17 ( ( void V_43 T_2 * ) V_23 -> V_44 ) ;
V_20 = F_7 ( V_2 , V_25 , 0 ) ;
F_18 ( V_20 -> V_26 , F_9 ( V_20 ) ) ;
return V_18 ;
}
static int F_23 ( struct V_45 * V_8 )
{
struct V_41 * V_42 = F_24 ( V_8 ) ;
return F_25 ( V_42 ) ;
}
static int F_26 ( struct V_45 * V_8 )
{
struct V_41 * V_42 = F_24 ( V_8 ) ;
return F_27 ( V_42 ) ;
}
int F_28 ( struct V_45 * V_8 )
{
int V_18 ;
struct V_3 * V_24 = F_29 ( V_8 ) ;
struct V_41 * V_42 = F_24 ( V_8 ) ;
struct V_1 * V_2 = F_30 ( V_8 ) ;
V_18 = F_31 ( V_42 ) ;
if ( V_24 -> exit )
V_24 -> exit ( V_2 ) ;
return V_18 ;
}
int F_32 ( struct V_45 * V_8 )
{
struct V_3 * V_24 = F_29 ( V_8 ) ;
struct V_41 * V_42 = F_24 ( V_8 ) ;
struct V_1 * V_2 = F_30 ( V_8 ) ;
if ( V_24 -> V_34 )
V_24 -> V_34 ( V_2 ) ;
return F_33 ( V_42 ) ;
}
