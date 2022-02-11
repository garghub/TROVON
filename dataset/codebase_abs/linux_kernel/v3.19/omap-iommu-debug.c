static inline bool F_1 ( struct V_1 * V_2 )
{
return ! V_2 -> V_3 ;
}
static T_1 F_2 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char * V_9 , * V_10 ;
T_1 V_11 ;
if ( F_1 ( V_2 ) )
return - V_12 ;
V_10 = F_3 ( V_6 , V_13 ) ;
if ( ! V_10 )
return - V_14 ;
V_9 = V_10 ;
F_4 ( & V_15 ) ;
V_11 = F_5 ( V_2 , V_9 , V_6 ) ;
V_11 = F_6 ( V_5 , V_6 , V_7 , V_10 , V_11 ) ;
F_7 ( & V_15 ) ;
F_8 ( V_10 ) ;
return V_11 ;
}
static T_1 F_9 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char * V_9 , * V_10 ;
T_1 V_11 , V_16 ;
if ( F_1 ( V_2 ) )
return - V_12 ;
V_10 = F_3 ( V_6 , V_13 ) ;
if ( ! V_10 )
return - V_14 ;
V_9 = V_10 ;
F_4 ( & V_15 ) ;
V_9 += sprintf ( V_9 , L_1 , L_2 , L_3 ) ;
V_9 += sprintf ( V_9 , L_4 ) ;
V_16 = V_6 - ( V_9 - V_10 ) ;
V_9 += F_10 ( V_2 , V_9 , V_16 ) ;
V_11 = F_6 ( V_5 , V_6 , V_7 , V_10 , V_9 - V_10 ) ;
F_7 ( & V_15 ) ;
F_8 ( V_10 ) ;
return V_11 ;
}
static void F_11 ( struct V_17 * V_18 )
{
int V_19 , V_20 ;
T_5 V_21 ;
T_5 * V_22 , * V_23 ;
struct V_1 * V_2 = V_18 -> V_24 ;
F_12 ( & V_2 -> V_25 ) ;
V_22 = F_13 ( V_2 , 0 ) ;
for ( V_19 = 0 ; V_19 < V_26 ; V_19 ++ , V_22 ++ ) {
if ( ! * V_22 )
continue;
if ( ! ( * V_22 & V_27 ) ) {
V_21 = V_19 << V_28 ;
F_14 ( V_18 , L_5 , V_21 , * V_22 ) ;
continue;
}
V_23 = F_15 ( V_22 , 0 ) ;
for ( V_20 = 0 ; V_20 < V_29 ; V_20 ++ , V_23 ++ ) {
if ( ! * V_23 )
continue;
V_21 = ( V_19 << V_28 ) + ( V_20 << V_30 ) ;
F_14 ( V_18 , L_6 , V_21 , * V_23 ) ;
}
}
F_16 ( & V_2 -> V_25 ) ;
}
static int F_17 ( struct V_17 * V_18 , void * V_31 )
{
struct V_1 * V_2 = V_18 -> V_24 ;
if ( F_1 ( V_2 ) )
return - V_12 ;
F_4 ( & V_15 ) ;
F_14 ( V_18 , L_7 , L_8 , L_9 ) ;
F_18 ( V_18 , L_10 ) ;
F_11 ( V_18 ) ;
F_7 ( & V_15 ) ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
if ( ! V_34 )
return;
V_2 -> V_35 = F_20 ( V_2 -> V_36 , V_34 ) ;
if ( ! V_2 -> V_35 )
return;
V_33 = F_21 ( L_11 , 0400 , V_2 -> V_35 ,
( V_37 * ) & V_2 -> V_38 ) ;
if ( ! V_33 )
return;
F_22 ( V_39 ) ;
F_22 ( V_40 ) ;
F_22 ( V_41 ) ;
return;
V_42:
F_23 ( V_2 -> V_35 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_35 )
return;
F_23 ( V_2 -> V_35 ) ;
}
void T_6 F_25 ( void )
{
V_34 = F_20 ( L_12 , NULL ) ;
if ( ! V_34 )
F_26 ( L_13 ) ;
}
void T_7 F_27 ( void )
{
F_28 ( V_34 ) ;
}
