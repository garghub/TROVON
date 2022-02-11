static void T_1 F_1 ( void )
{
T_2 V_1 ;
int V_2 ;
struct V_3 * V_4 ;
struct V_3 * V_5 = NULL ;
V_4 = F_2 ( L_1 ) ;
if ( ! V_4 )
return;
F_3 (cpus, np) {
if ( F_4 ( V_5 -> type , L_2 ) != 0 )
continue;
V_2 = F_5 ( V_5 , L_3 , & V_1 ) ;
if ( V_2 )
continue;
F_6 ( L_4 , V_1 ) ;
if ( V_1 >= V_6 )
F_7 ( L_5 , V_1 ) ;
else
F_8 ( V_1 , V_7 ) ;
}
}
static int T_1 F_9 ( void )
{
struct V_3 * V_5 = NULL ;
struct V_8 V_9 ;
T_2 V_1 ;
int V_10 , V_2 ;
F_10 (np, L_6 ) {
V_2 = F_5 ( V_5 , L_3 , & V_1 ) ;
if ( V_2 == - V_11 )
continue;
if ( V_1 >= V_6 ) {
F_7 ( L_5 , V_1 ) ;
V_2 = - V_11 ;
}
for ( V_10 = 0 ; ! V_2 && ! F_11 ( V_5 , V_10 , & V_9 ) ; V_10 ++ )
V_2 = F_12 ( V_1 , V_9 . V_12 , V_9 . V_13 + 1 ) ;
if ( ! V_10 || V_2 ) {
F_13 ( V_5 ) ;
F_14 ( L_7 ) ;
return V_2 ? : - V_11 ;
}
}
return 0 ;
}
static int T_1 F_15 ( struct V_3 * V_14 )
{
const T_3 * V_15 ;
int V_16 ;
int V_10 ;
F_16 ( L_8 ) ;
V_15 = F_17 ( V_14 , L_9 , NULL ) ;
if ( ! V_15 ) {
F_14 ( L_10 ) ;
return - V_11 ;
}
V_16 = F_18 ( V_14 , L_9 ) ;
if ( V_16 <= 0 ) {
F_14 ( L_11 ) ;
return - V_11 ;
}
for ( V_10 = 0 ; V_10 + 2 < V_16 ; V_10 += 3 ) {
T_2 V_17 , V_18 , V_19 ;
V_17 = F_19 ( V_15 , 1 ) ;
V_15 ++ ;
V_18 = F_19 ( V_15 , 1 ) ;
V_15 ++ ;
V_19 = F_19 ( V_15 , 1 ) ;
V_15 ++ ;
F_20 ( V_17 , V_18 , V_19 ) ;
F_6 ( L_12 ,
V_17 , V_18 , V_19 ) ;
if ( V_18 > V_17 )
F_20 ( V_18 , V_17 , V_19 ) ;
}
return 0 ;
}
static int T_1 F_21 ( void )
{
int V_20 = 0 ;
struct V_3 * V_5 ;
V_5 = F_22 ( NULL , NULL ,
L_13 ) ;
if ( V_5 )
V_20 = F_15 ( V_5 ) ;
F_13 ( V_5 ) ;
return V_20 ;
}
int F_23 ( struct V_3 * V_21 )
{
struct V_3 * V_5 ;
T_2 V_1 ;
int V_2 = - V_22 ;
V_5 = F_24 ( V_21 ) ;
while ( V_5 ) {
V_2 = F_5 ( V_5 , L_3 , & V_1 ) ;
if ( V_2 != - V_11 )
break;
V_5 = F_25 ( V_5 ) ;
}
if ( V_5 && V_2 )
F_7 ( L_14 ,
V_5 -> V_23 ) ;
F_13 ( V_5 ) ;
if ( ! V_2 && V_1 < V_6 && F_26 ( V_1 ) )
return V_1 ;
return V_24 ;
}
int T_1 F_27 ( void )
{
int V_2 ;
F_1 () ;
V_2 = F_9 () ;
if ( V_2 )
return V_2 ;
return F_21 () ;
}
