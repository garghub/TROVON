static int F_1 ( void * V_1 , bool V_2 )
{
struct V_3 * V_4 = V_1 ;
int V_5 = 0 ;
F_2 ( L_1 , V_6 , V_2 ) ;
if ( V_2 ) {
if ( V_4 -> V_7 ) {
F_3 ( V_4 -> V_8 ) ;
V_4 -> V_7 = false ;
}
} else {
if ( ! V_4 -> V_7 ) {
V_5 = F_4 ( V_4 -> V_8 ) ;
if ( ! V_5 )
V_4 -> V_7 = true ;
}
}
F_2 ( L_2 , V_6 ,
F_5 ( V_4 -> V_8 ) ) ;
return V_5 ;
}
static int F_6 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
struct V_3 * V_4 ;
struct V_15 * V_8 ;
struct V_16 * V_17 ;
int V_5 = 0 ;
if ( V_12 == NULL ) {
F_7 ( & V_10 -> V_13 , L_3 ) ;
return - V_18 ;
}
if ( V_12 -> V_19 == NULL || V_12 -> type == 0 ) {
F_7 ( & V_10 -> V_13 , L_4 ) ;
return - V_20 ;
}
V_8 = F_8 ( & V_10 -> V_13 , L_5 ) ;
if ( F_9 ( V_8 ) ) {
F_7 ( & V_10 -> V_13 , L_6 , V_12 -> V_19 ) ;
V_5 = F_10 ( V_8 ) ;
goto V_21;
}
V_4 = F_11 ( sizeof( * V_4 ) , V_22 ) ;
if ( V_4 == NULL ) {
V_5 = - V_23 ;
goto V_24;
}
V_17 = F_12 ( V_12 -> V_19 , & V_10 -> V_13 ,
V_12 -> type ,
& V_25 , V_4 ) ;
if ( V_17 == NULL ) {
V_5 = - V_23 ;
goto V_26;
}
if ( F_5 ( V_8 ) ) {
F_13 ( & V_10 -> V_13 , L_7 ) ;
V_4 -> V_7 = true ;
}
V_4 -> V_8 = V_8 ;
V_4 -> V_17 = V_17 ;
V_5 = F_14 ( V_17 ) ;
if ( V_5 ) {
F_7 ( & V_10 -> V_13 , L_8 ) ;
goto V_27;
}
F_15 ( V_10 , V_4 ) ;
F_16 ( & V_10 -> V_13 , L_9 , V_12 -> V_19 ) ;
return 0 ;
V_27:
F_17 ( V_17 ) ;
V_26:
F_18 ( V_4 ) ;
V_24:
F_19 ( V_8 ) ;
V_21:
return V_5 ;
}
static int F_20 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = F_21 ( V_10 ) ;
struct V_16 * V_17 = V_4 -> V_17 ;
F_22 ( V_17 ) ;
F_17 ( V_17 ) ;
F_19 ( V_4 -> V_8 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
