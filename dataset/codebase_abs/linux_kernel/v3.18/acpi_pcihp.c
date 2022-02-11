static T_1 F_1 ( T_2 V_1 )
{
T_1 V_2 ;
struct V_3 string = { V_4 , NULL } ;
F_2 ( V_1 , V_5 , & string ) ;
V_2 = F_3 ( V_1 , V_6 , NULL , NULL ) ;
if ( F_4 ( V_2 ) )
if ( V_2 != V_7 )
F_5 ( V_8 L_1 ,
V_9 , ( char * ) string . V_10 , V_2 ) ;
else
F_6 ( L_2 ,
V_9 , ( char * ) string . V_10 ) ;
else
F_7 ( L_3 , V_9 ,
( char * ) string . V_10 ) ;
F_8 ( string . V_10 ) ;
return V_2 ;
}
int F_9 ( struct V_11 * V_12 , T_3 V_13 )
{
T_1 V_2 ;
T_2 V_14 , V_1 ;
struct V_3 string = { V_4 , NULL } ;
V_13 &= V_15 ;
if ( ! V_13 ) {
F_10 ( L_4 , V_13 ) ;
return - V_16 ;
}
V_1 = F_11 ( V_12 ) ;
if ( V_1 ) {
F_2 ( V_1 , V_5 , & string ) ;
F_6 ( L_5 ,
( char * ) string . V_10 ) ;
V_2 = F_12 ( V_1 , & V_13 , V_13 ) ;
if ( F_13 ( V_2 ) )
goto V_17;
if ( V_2 == V_18 )
goto V_19;
F_8 ( string . V_10 ) ;
string = (struct V_3 ) { V_4 , NULL } ;
}
V_1 = F_14 ( & V_12 -> V_20 ) ;
if ( ! V_1 ) {
struct V_21 * V_22 ;
for ( V_22 = V_12 -> V_23 ; V_22 ; V_22 = V_22 -> V_24 ) {
V_1 = F_15 ( V_22 ) ;
if ( V_1 )
break;
}
}
while ( V_1 ) {
F_2 ( V_1 , V_5 , & string ) ;
F_6 ( L_6 ,
( char * ) string . V_10 ) ;
V_2 = F_1 ( V_1 ) ;
if ( F_13 ( V_2 ) )
goto V_17;
if ( F_16 ( V_1 ) )
break;
V_14 = V_1 ;
V_2 = F_17 ( V_14 , & V_1 ) ;
if ( F_4 ( V_2 ) )
break;
}
V_19:
F_6 ( L_7 ,
F_18 ( V_12 ) ) ;
F_8 ( string . V_10 ) ;
return - V_25 ;
V_17:
F_6 ( L_8 ,
F_18 ( V_12 ) , ( char * ) string . V_10 ) ;
F_8 ( string . V_10 ) ;
return 0 ;
}
static int F_19 ( T_2 V_1 )
{
T_1 V_2 ;
unsigned long long V_26 ;
if ( ! F_20 ( V_1 , L_9 ) )
return 0 ;
if ( F_20 ( V_1 , L_10 ) )
return 1 ;
V_2 = F_21 ( V_1 , L_11 , NULL , & V_26 ) ;
if ( F_13 ( V_2 ) && V_26 )
return 1 ;
return 0 ;
}
int F_22 ( struct V_21 * V_22 , T_2 V_1 )
{
T_2 V_27 , V_28 ;
V_27 = F_15 ( V_22 ) ;
if ( ! V_27 )
return 0 ;
if ( ( F_4 ( F_17 ( V_1 , & V_28 ) ) ) )
return 0 ;
if ( V_27 != V_28 )
return 0 ;
return F_19 ( V_1 ) ;
}
static T_1
F_23 ( T_2 V_1 , T_3 V_29 , void * V_30 , void * * V_31 )
{
int * V_32 = ( int * ) V_30 ;
if ( F_19 ( V_1 ) ) {
* V_32 = 1 ;
return V_33 ;
}
return V_34 ;
}
int F_24 ( T_2 V_1 )
{
int V_32 = 0 ;
if ( ! V_1 )
return V_32 ;
F_25 ( V_35 , V_1 , 1 ,
F_23 , NULL , ( void * ) & V_32 , NULL ) ;
return V_32 ;
}
