struct V_1 * F_1 ( int V_2 , const char * V_3 )
{
struct V_1 * V_4 = NULL ;
F_2 ( & V_5 ) ;
F_3 (ssp, &ssp_list, node) {
if ( V_4 -> V_6 == V_2 && V_4 -> V_7 == 0 ) {
V_4 -> V_7 ++ ;
V_4 -> V_3 = V_3 ;
break;
}
}
F_4 ( & V_5 ) ;
if ( & V_4 -> V_8 == & V_9 )
return NULL ;
return V_4 ;
}
void F_5 ( struct V_1 * V_4 )
{
F_2 ( & V_5 ) ;
if ( V_4 -> V_7 ) {
V_4 -> V_7 -- ;
V_4 -> V_3 = NULL ;
} else
F_6 ( & V_4 -> V_10 -> V_11 , L_1 ) ;
F_4 ( & V_5 ) ;
}
static int T_1 F_7 ( struct V_12 * V_11 ,
const struct V_13 * V_14 )
{
int V_15 ;
T_2 V_16 ;
T_2 V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_10 ;
struct V_21 V_22 ;
struct V_1 * V_4 ;
V_15 = F_8 ( V_11 ) ;
if ( V_15 )
return V_15 ;
V_16 = F_9 ( V_11 , 0 ) ;
V_17 = F_10 ( V_11 , 0 ) ;
if ( ! F_11 ( V_16 , V_17 ,
L_2 ) ) {
F_6 ( & V_11 -> V_11 , L_3 ) ;
V_15 = - V_23 ;
return V_15 ;
}
V_10 = F_12 ( L_4 , V_11 -> V_24 ) ;
V_19 = F_13 ( sizeof( * V_19 ) , V_25 ) ;
if ( ! V_10 || ! V_19 ) {
V_15 = - V_26 ;
goto V_27;
}
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_28 = V_11 -> V_24 ;
V_15 = F_14 ( V_10 , & V_22 , sizeof( V_22 ) ) ;
if ( V_15 )
goto V_27;
V_10 -> V_11 . V_29 = & V_11 -> V_11 ;
V_10 -> V_11 . V_30 = V_11 -> V_11 . V_30 ;
V_4 = & V_19 -> V_4 ;
V_4 -> V_31 = F_9 ( V_11 , 0 ) ;
V_4 -> V_32 = F_15 ( V_16 , V_17 ) ;
if ( ! V_4 -> V_32 ) {
F_6 ( & V_10 -> V_11 , L_5 ) ;
V_15 = - V_33 ;
goto V_27;
}
V_4 -> V_34 = V_11 -> V_34 ;
V_4 -> V_6 = V_10 -> V_35 ;
V_4 -> type = V_36 ;
F_2 ( & V_5 ) ;
F_16 ( & V_4 -> V_8 , & V_9 ) ;
F_4 ( & V_5 ) ;
F_17 ( V_11 , V_19 ) ;
V_15 = F_18 ( V_10 ) ;
if ( V_15 )
goto V_37;
return V_15 ;
V_37:
F_17 ( V_11 , NULL ) ;
F_2 ( & V_5 ) ;
F_19 ( & V_4 -> V_8 ) ;
F_4 ( & V_5 ) ;
F_20 ( V_4 -> V_32 ) ;
V_27:
F_21 ( V_16 , V_17 ) ;
F_22 ( V_10 ) ;
F_23 ( V_19 ) ;
return V_15 ;
}
static void T_3 F_24 ( struct V_12 * V_11 )
{
struct V_18 * V_19 ;
struct V_1 * V_4 ;
V_19 = F_25 ( V_11 ) ;
V_4 = & V_19 -> V_4 ;
F_26 ( V_19 -> V_38 ) ;
F_20 ( V_4 -> V_32 ) ;
F_21 ( F_9 ( V_11 , 0 ) ,
F_10 ( V_11 , 0 ) ) ;
F_2 ( & V_5 ) ;
F_19 ( & V_4 -> V_8 ) ;
F_4 ( & V_5 ) ;
F_17 ( V_11 , NULL ) ;
F_27 ( V_11 ) ;
F_23 ( V_19 ) ;
}
static int T_4 F_28 ( void )
{
return F_29 ( & V_39 ) ;
}
static void T_5 F_30 ( void )
{
F_31 ( & V_39 ) ;
}
