static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
int V_5 ;
T_1 V_6 ;
V_5 = F_2 ( V_7 , V_8 , 1 ) ;
if ( V_5 ) {
F_3 ( L_1 , V_5 ) ;
return V_9 ;
}
V_5 = F_4 ( V_7 , V_8 , & V_6 ) ;
if ( V_5 ) {
F_3 ( L_2 , V_5 ) ;
return V_9 ;
}
V_5 = F_2 ( V_7 , V_10 , 1 ) ;
if ( V_5 ) {
F_3 ( L_3 , V_5 ) ;
return V_9 ;
}
V_5 = F_4 ( V_7 , V_10 , & V_6 ) ;
if ( V_5 ) {
F_3 ( L_4 , V_5 ) ;
return V_9 ;
}
while ( 1 )
;
return V_9 ;
}
static int F_5 ( struct V_11 * V_12 )
{
int V_5 ;
struct V_13 * V_14 = V_12 -> V_15 . V_16 ;
V_7 = F_6 ( V_14 , L_5 ) ;
if ( F_7 ( V_7 ) ) {
F_3 ( L_6 ) ;
return - V_17 ;
}
V_5 = F_8 ( V_14 , L_5 , V_18 ,
& V_8 ) ;
if ( V_5 ) {
F_3 ( L_7 , V_5 ) ;
return - V_17 ;
}
V_5 = F_8 ( V_14 , L_5 , V_19 ,
& V_10 ) ;
if ( V_5 ) {
F_3 ( L_8 , V_5 ) ;
return - V_17 ;
}
V_5 = F_9 ( & V_20 ) ;
if ( V_5 )
F_10 ( & V_12 -> V_15 ,
L_9 , V_5 ) ;
return V_5 ;
}
static int T_2 F_11 ( void )
{
return F_12 ( & V_21 ,
F_5 ) ;
}
