static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
int V_5 ;
T_1 V_6 ;
V_5 = F_2 ( V_7 , V_8 , V_9 -> V_10 ) ;
if ( V_5 ) {
F_3 ( L_1 , V_5 ) ;
return V_11 ;
}
V_5 = F_4 ( V_7 , V_8 , & V_6 ) ;
if ( V_5 ) {
F_3 ( L_2 , V_5 ) ;
return V_11 ;
}
V_5 = F_2 ( V_7 , V_12 , V_9 -> V_13 ) ;
if ( V_5 ) {
F_3 ( L_3 , V_5 ) ;
return V_11 ;
}
V_5 = F_4 ( V_7 , V_12 , & V_6 ) ;
if ( V_5 ) {
F_3 ( L_4 , V_5 ) ;
return V_11 ;
}
while ( 1 )
;
return V_11 ;
}
static int F_5 ( struct V_14 * V_15 )
{
int V_5 ;
struct V_16 * V_17 = V_15 -> V_18 . V_19 ;
const struct V_20 * V_21 ;
V_21 = F_6 ( V_22 , V_17 ) ;
if ( ! V_21 ) {
F_3 ( L_5 ) ;
return - V_23 ;
}
V_9 = V_21 -> V_24 ;
V_7 = F_7 ( V_17 , L_6 ) ;
if ( F_8 ( V_7 ) ) {
F_3 ( L_7 ) ;
return - V_23 ;
}
V_5 = F_9 ( V_17 , L_6 , V_25 ,
& V_8 ) ;
if ( V_5 ) {
F_3 ( L_8 , V_5 ) ;
return - V_23 ;
}
V_5 = F_9 ( V_17 , L_6 , V_26 ,
& V_12 ) ;
if ( V_5 ) {
F_3 ( L_9 , V_5 ) ;
return - V_23 ;
}
V_5 = F_10 ( & V_27 ) ;
if ( V_5 )
F_11 ( & V_15 -> V_18 ,
L_10 , V_5 ) ;
return V_5 ;
}
static int T_2 F_12 ( void )
{
return F_13 ( & V_28 ,
F_5 ) ;
}
