static inline int F_1 ( T_1 V_1 , T_1 V_2 )
{
if ( V_1 < V_2 )
return 1 ;
if ( V_1 > V_2 )
return - 1 ;
return 0 ;
}
struct V_3 * F_2 ( struct V_4 * V_5 , T_1 V_1 )
{
struct V_6 * V_7 = & V_5 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_9 ;
struct V_3 * V_11 , * V_12 = NULL ;
int V_13 ;
while ( V_10 ) {
V_11 = F_3 ( V_10 , struct V_3 , V_14 ) ;
V_13 = F_1 ( V_11 -> V_1 , V_1 ) ;
if ( V_13 < 0 )
V_10 = V_10 -> V_15 ;
else if ( V_13 > 0 )
V_10 = V_10 -> V_16 ;
else {
V_12 = V_11 ;
F_4 ( V_12 ) ;
break;
}
}
return V_12 ;
}
static int F_5 ( struct V_4 * V_5 , struct V_3 * V_17 )
{
struct V_6 * V_7 = & V_5 -> V_8 ;
struct V_9 * * V_10 = & V_7 -> V_9 , * V_18 = NULL ;
struct V_3 * V_12 = NULL , * V_11 ;
int V_13 ;
while ( * V_10 ) {
V_18 = * V_10 ;
V_11 = F_3 ( V_18 , struct V_3 , V_14 ) ;
V_13 = F_1 ( V_11 -> V_1 , V_17 -> V_1 ) ;
if ( V_13 < 0 )
V_10 = & V_18 -> V_15 ;
else if ( V_13 > 0 )
V_10 = & V_18 -> V_16 ;
else {
V_12 = V_11 ;
break;
}
}
if ( V_12 )
return - V_19 ;
F_6 ( & V_17 -> V_14 , V_18 , V_10 ) ;
F_7 ( & V_17 -> V_14 , V_7 ) ;
return 0 ;
}
static int F_8 ( struct V_4 * V_5 , struct V_3 * V_17 )
{
if ( V_17 && V_17 -> V_14 . V_20 ) {
F_9 ( & V_17 -> V_14 , & V_5 -> V_8 ) ;
V_17 -> V_14 . V_20 = 0 ;
return 1 ;
}
return 0 ;
}
void F_10 ( struct V_4 * V_5 , struct V_3 * V_17 )
{
F_11 ( & V_5 -> V_21 ) ;
F_8 ( V_5 , V_17 ) ;
F_12 ( & V_5 -> V_21 ) ;
}
struct V_3 * F_13 ( struct V_4 * V_5 , T_1 V_22 ,
unsigned int V_23 , void * V_24 )
{
struct V_3 * V_17 ;
int V_25 = - V_26 ;
V_17 = F_14 ( V_27 , V_28 ) ;
if ( ! V_17 )
goto V_29;
F_15 ( & V_17 -> V_30 ) ;
V_17 -> V_25 = 0 ;
F_16 ( & V_17 -> V_31 , 1 ) ;
V_17 -> V_24 = V_24 ;
V_17 -> V_22 = V_22 ;
V_17 -> V_23 = V_23 ;
V_17 -> V_1 = F_17 ( & V_5 -> V_32 ) ;
F_11 ( & V_5 -> V_21 ) ;
V_25 = F_5 ( V_5 , V_17 ) ;
F_12 ( & V_5 -> V_21 ) ;
if ( V_25 )
goto V_33;
return V_17 ;
V_33:
F_18 ( V_17 , V_27 ) ;
V_29:
return F_19 ( V_25 ) ;
}
void F_20 ( struct V_4 * V_5 , struct V_3 * V_17 )
{
F_10 ( V_5 , V_17 ) ;
F_18 ( V_17 , V_27 ) ;
}
int T_2 F_21 ( void )
{
V_34 = F_22 ( L_1 ,
sizeof( struct V_3 ) ,
0 , ( V_35 | V_36 ) , NULL ) ;
if ( ! V_34 )
goto V_29;
V_27 = F_23 ( 256 , V_34 ) ;
if ( ! V_27 )
goto V_33;
return 0 ;
V_33:
F_24 ( V_34 ) ;
V_29:
return - V_26 ;
}
void F_25 ( void )
{
F_26 ( V_27 ) ;
F_24 ( V_34 ) ;
}
