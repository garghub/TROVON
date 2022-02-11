static struct V_1 * F_1 ( struct V_2 * V_2 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 = V_6 . V_4 ;
while ( V_5 ) {
V_3 = F_2 ( V_5 , struct V_1 , V_4 ) ;
if ( V_2 < V_3 -> V_2 )
V_5 = V_5 -> V_7 ;
else if ( V_2 > V_3 -> V_2 )
V_5 = V_5 -> V_8 ;
else
break;
}
if ( ! V_5 )
return NULL ;
return V_3 ;
}
struct V_1 * F_3 ( struct V_2 * V_2 )
{
struct V_1 * V_3 ;
if ( ! F_4 ( V_2 ) )
return NULL ;
F_5 ( & V_9 ) ;
V_3 = F_1 ( V_2 ) ;
F_6 ( & V_9 ) ;
return V_3 ;
}
static void F_7 ( struct V_1 * V_3 )
{
F_8 ( V_3 -> V_10 ) ;
V_3 -> V_10 = NULL ;
V_3 -> V_11 = 0 ;
V_3 -> V_12 = 0UL ;
V_3 -> V_13 = V_14 ;
V_3 -> V_15 = V_14 ;
V_3 -> V_16 = V_14 ;
V_3 -> V_17 = V_14 ;
V_3 -> V_18 = V_14 ;
V_3 -> V_19 = 0 ;
F_9 ( V_20 , V_3 ) ;
}
struct V_1 * F_10 ( struct V_2 * V_2 )
{
struct V_4 * * V_21 ;
struct V_4 * V_22 , * V_23 = NULL ;
struct V_1 * V_3 , * V_24 ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_11 ( V_20 , V_25 ) ;
if ( ! V_3 )
return NULL ;
F_12 ( & V_9 ) ;
V_21 = & V_6 . V_4 ;
while ( * V_21 ) {
V_23 = * V_21 ;
V_24 = F_2 ( V_23 , struct V_1 ,
V_4 ) ;
if ( V_2 < V_24 -> V_2 )
V_21 = & ( * V_21 ) -> V_7 ;
else
V_21 = & ( * V_21 ) -> V_8 ;
}
V_3 -> V_2 = V_2 ;
V_22 = & V_3 -> V_4 ;
V_2 -> V_26 |= V_27 ;
F_13 ( V_22 , V_23 , V_21 ) ;
F_14 ( V_22 , & V_6 ) ;
F_15 ( & V_9 ) ;
return V_3 ;
}
void F_16 ( struct V_2 * V_2 )
{
struct V_1 * V_3 ;
if ( ! F_4 ( V_2 ) )
return;
F_12 ( & V_9 ) ;
V_3 = F_1 ( V_2 ) ;
F_17 ( & V_3 -> V_4 , & V_6 ) ;
F_15 ( & V_9 ) ;
F_7 ( V_3 ) ;
}
static void F_18 ( void * V_28 )
{
struct V_1 * V_3 = V_28 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_11 = 0 ;
V_3 -> V_12 = 0UL ;
V_3 -> V_13 = V_14 ;
V_3 -> V_15 = V_14 ;
V_3 -> V_16 = V_14 ;
V_3 -> V_17 = V_14 ;
V_3 -> V_18 = V_14 ;
V_3 -> V_19 = 0 ;
}
static int T_1 F_19 ( void )
{
V_20 =
F_20 ( L_1 , sizeof( struct V_1 ) ,
0 , V_29 , F_18 ) ;
return 0 ;
}
int F_21 ( struct V_30 * V_30 , T_2 V_31 ,
void * V_32 , unsigned long V_33 )
{
T_3 V_34 ;
char T_4 * V_35 = ( char T_4 * ) V_32 ;
T_5 V_36 ;
if ( ! ( V_30 -> V_37 & V_38 ) )
return - V_39 ;
V_34 = F_22 () ;
F_23 ( F_24 () ) ;
V_36 = F_25 ( V_30 , V_35 , V_33 , & V_31 ) ;
F_23 ( V_34 ) ;
return V_36 ;
}
int T_1 F_26 ( const char * V_40 , char * * V_41 )
{
struct V_30 * V_30 ;
T_2 V_42 ;
char * V_35 ;
int V_43 = - V_44 ;
if ( ! V_40 || ! * V_40 )
return - V_44 ;
V_30 = F_27 ( V_40 , V_45 , 0 ) ;
if ( F_28 ( V_30 ) ) {
V_43 = F_29 ( V_30 ) ;
F_30 ( L_2 , V_40 , V_43 ) ;
return V_43 ;
}
V_42 = F_31 ( F_32 ( V_30 ) ) ;
if ( V_42 <= 0 )
goto V_46;
V_35 = F_33 ( V_42 , V_47 ) ;
if ( ! V_35 ) {
V_43 = - V_48 ;
goto V_46;
}
V_43 = F_21 ( V_30 , 0 , V_35 , V_42 ) ;
if ( V_43 == V_42 ) {
* V_41 = V_35 ;
} else {
F_8 ( V_35 ) ;
if ( V_43 >= 0 )
V_43 = - V_49 ;
}
V_46:
F_34 ( V_30 ) ;
return V_43 ;
}
void T_1 F_35 ( void )
{
F_36 () ;
F_37 () ;
}
