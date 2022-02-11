static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 V_5 ;
return ! F_2 ( V_2 , & V_5 ) ;
}
static T_1 F_3 ( T_2 V_6 , T_3 V_7 ,
void * V_3 , void * * V_8 )
{
struct V_9 * V_10 ;
struct V_11 V_12 ;
struct V_13 * V_14 ;
const char * V_15 = V_3 ;
int V_16 ;
if ( F_4 ( V_6 , & V_14 ) )
return V_17 ;
if ( V_15 ) {
if ( ! V_14 -> V_18 . V_19 )
return V_17 ;
if ( strcmp ( V_15 , V_14 -> V_18 . V_19 ) )
return V_17 ;
}
F_5 ( & V_12 ) ;
V_16 = F_6 ( V_14 , & V_12 ,
F_1 , NULL ) ;
if ( V_16 < 0 )
return V_20 ;
F_7 (rentry, &resource_list, node)
if ( F_8 ( & V_10 -> V_2 ) == V_21 ) {
* (struct V_4 * ) V_8 = V_10 -> V_2 ;
break;
}
F_9 ( & V_12 ) ;
return V_17 ;
}
struct V_22 * F_10 ( const char * V_23 , const char * V_24 ,
const char * V_25 , const char * V_15 ,
unsigned V_26 )
{
struct V_4 V_2 = { } ;
void T_4 * V_27 ;
T_1 V_28 ;
struct V_22 * V_22 ;
V_28 = F_11 ( V_25 , F_3 , ( void * ) V_15 ,
( void * * ) & V_2 ) ;
if ( F_12 ( V_28 ) || ! V_2 . V_29 )
return F_13 ( - V_30 ) ;
V_27 = F_14 ( V_2 . V_29 , F_15 ( & V_2 ) ) ;
if ( ! V_27 )
return F_13 ( - V_31 ) ;
V_22 = F_16 ( NULL , V_23 , V_24 , 0 , V_27 + V_26 ,
0 , 0 , NULL ) ;
if ( F_17 ( V_22 ) )
F_18 ( V_27 ) ;
return V_22 ;
}
