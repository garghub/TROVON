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
F_7 ( L_5 ,
V_1 ) ;
else
F_8 ( V_1 , V_7 ) ;
}
}
static int T_1 F_9 ( void )
{
struct V_3 * V_5 = NULL ;
struct V_8 V_9 ;
T_2 V_1 ;
int V_2 = 0 ;
for (; ; ) {
V_5 = F_10 ( V_5 , L_6 ) ;
if ( ! V_5 )
break;
V_2 = F_5 ( V_5 , L_3 , & V_1 ) ;
if ( V_2 == - V_10 )
continue;
else if ( V_2 )
break;
V_2 = F_11 ( V_5 , 0 , & V_9 ) ;
if ( V_2 ) {
F_12 ( L_7 ) ;
break;
}
F_6 ( L_8 ,
V_9 . V_11 , V_9 . V_12 - V_9 . V_11 + 1 , V_1 ) ;
V_2 = F_13 ( V_1 , V_9 . V_11 ,
V_9 . V_12 - V_9 . V_11 + 1 ) ;
if ( V_2 )
break;
}
F_14 ( V_5 ) ;
return V_2 ;
}
static int T_1 F_15 ( struct V_3 * V_13 )
{
const T_3 * V_14 ;
int V_15 ;
int V_16 ;
F_16 ( L_9 ) ;
V_14 = F_17 ( V_13 , L_10 , NULL ) ;
if ( ! V_14 ) {
F_12 ( L_11 ) ;
return - V_10 ;
}
V_15 = F_18 ( V_13 , L_10 ) ;
if ( V_15 <= 0 ) {
F_12 ( L_12 ) ;
return - V_10 ;
}
for ( V_16 = 0 ; V_16 + 2 < V_15 ; V_16 += 3 ) {
T_2 V_17 , V_18 , V_19 ;
V_17 = F_19 ( V_14 , 1 ) ;
V_14 ++ ;
V_18 = F_19 ( V_14 , 1 ) ;
V_14 ++ ;
V_19 = F_19 ( V_14 , 1 ) ;
V_14 ++ ;
F_20 ( V_17 , V_18 , V_19 ) ;
F_6 ( L_13 ,
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
L_14 ) ;
if ( V_5 )
V_20 = F_15 ( V_5 ) ;
F_14 ( V_5 ) ;
return V_20 ;
}
int F_23 ( struct V_3 * V_21 )
{
struct V_3 * V_5 ;
T_2 V_1 ;
int V_2 = - V_22 ;
V_5 = F_24 ( V_21 ) ;
while ( V_5 ) {
struct V_3 * V_23 ;
V_2 = F_5 ( V_5 , L_3 , & V_1 ) ;
if ( V_2 != - V_10 )
break;
V_23 = F_25 ( V_5 ) ;
F_14 ( V_5 ) ;
V_5 = V_23 ;
}
if ( V_5 && V_2 )
F_7 ( L_15 ,
V_5 -> V_24 ) ;
F_14 ( V_5 ) ;
if ( ! V_2 ) {
if ( V_1 >= V_6 )
F_7 ( L_5 ,
V_1 ) ;
else
return V_1 ;
}
return V_25 ;
}
int T_1 F_26 ( void )
{
int V_2 ;
F_1 () ;
V_2 = F_9 () ;
if ( V_2 )
return V_2 ;
return F_21 () ;
}
