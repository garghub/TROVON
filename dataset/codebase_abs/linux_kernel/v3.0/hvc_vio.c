static int F_1 ( T_1 V_1 , char * V_2 , int V_3 )
{
unsigned long V_4 ;
int V_5 ;
if ( V_3 < V_6 )
return - V_7 ;
V_4 = F_2 ( V_1 , V_2 , V_3 ) ;
for ( V_5 = 1 ; V_5 < V_4 ; ++ V_5 ) {
if ( V_2 [ V_5 ] == 0 && V_2 [ V_5 - 1 ] == '\r' ) {
-- V_4 ;
if ( V_5 < V_4 )
memmove ( & V_2 [ V_5 ] , & V_2 [ V_5 + 1 ] ,
V_4 - V_5 ) ;
}
}
return V_4 ;
}
static int T_2 F_3 ( struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
struct V_12 * V_13 ;
if ( ! V_9 || ! V_11 )
return - V_14 ;
V_13 = F_4 ( V_9 -> V_15 , V_9 -> V_16 , & V_17 ,
V_18 ) ;
if ( F_5 ( V_13 ) )
return F_6 ( V_13 ) ;
F_7 ( & V_9 -> V_19 , V_13 ) ;
return 0 ;
}
static int T_3 F_8 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = F_9 ( & V_9 -> V_19 ) ;
return F_10 ( V_13 ) ;
}
static int T_4 F_11 ( void )
{
int V_20 ;
if ( F_12 ( V_21 ) )
return - V_22 ;
V_20 = F_13 ( & V_23 ) ;
return V_20 ;
}
static void T_5 F_14 ( void )
{
F_15 ( & V_23 ) ;
}
static int F_16 ( void )
{
struct V_24 * V_25 ;
int V_26 = 0 ;
for ( V_25 = F_17 ( NULL , L_1 ) ; V_25 != NULL ;
V_25 = F_17 ( V_25 , L_1 ) ) {
const T_1 * V_1 ;
if ( V_26 >= V_27 ) {
F_18 ( V_25 ) ;
break;
}
V_1 = F_19 ( V_25 , L_2 , NULL ) ;
if ( ! V_1 )
continue;
if ( F_20 ( V_25 , L_3 ) ) {
F_21 ( * V_1 , V_26 , & V_17 ) ;
++ V_26 ;
}
}
return V_26 ;
}
