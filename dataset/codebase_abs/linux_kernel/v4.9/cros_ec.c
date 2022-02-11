static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_5 ;
if ( F_2 ( V_4 -> V_6 ) )
F_3 ( V_4 -> V_6 , 0 ) ;
V_5 = F_4 ( V_4 ) ;
if ( V_5 > 0 )
F_5 ( & V_4 -> V_7 ,
0 , V_4 ) ;
return V_8 ;
}
int F_6 ( struct V_3 * V_4 )
{
struct V_9 * V_6 = V_4 -> V_6 ;
int V_10 = 0 ;
F_7 ( & V_4 -> V_7 ) ;
V_4 -> V_11 = sizeof( struct V_12 ) ;
V_4 -> V_13 = sizeof( struct V_14 ) ;
V_4 -> V_15 = 0 ;
V_4 -> V_16 = F_8 ( V_6 , V_4 -> V_17 , V_18 ) ;
if ( ! V_4 -> V_16 )
return - V_19 ;
V_4 -> V_20 = F_8 ( V_6 , V_4 -> V_21 , V_18 ) ;
if ( ! V_4 -> V_20 )
return - V_19 ;
F_9 ( & V_4 -> V_22 ) ;
F_10 ( V_4 ) ;
if ( V_4 -> V_1 ) {
V_10 = F_11 ( V_4 -> V_1 , NULL , F_1 ,
V_23 | V_24 ,
L_1 , V_4 ) ;
if ( V_10 ) {
F_12 ( V_6 , L_2 ,
V_4 -> V_1 , V_10 ) ;
return V_10 ;
}
}
V_10 = F_13 ( V_4 -> V_6 , V_25 , & V_26 , 1 ,
NULL , V_4 -> V_1 , NULL ) ;
if ( V_10 ) {
F_12 ( V_6 ,
L_3 ,
V_10 ) ;
goto V_27;
}
if ( V_4 -> V_15 ) {
V_10 = F_13 ( V_4 -> V_6 , V_25 ,
& V_28 , 1 , NULL , V_4 -> V_1 , NULL ) ;
if ( V_10 ) {
F_12 ( V_6 ,
L_4 ,
V_10 ) ;
goto V_27;
}
}
if ( F_14 ( V_29 ) && V_6 -> V_30 ) {
V_10 = F_15 ( V_6 -> V_30 , NULL , NULL , V_6 ) ;
if ( V_10 ) {
F_16 ( V_6 ) ;
F_12 ( V_6 , L_5 ) ;
goto V_27;
}
}
F_17 ( V_6 , L_6 ) ;
return 0 ;
V_27:
if ( V_4 -> V_1 )
F_18 ( V_4 -> V_1 , V_4 ) ;
return V_10 ;
}
int F_19 ( struct V_3 * V_4 )
{
F_16 ( V_4 -> V_6 ) ;
return 0 ;
}
int F_20 ( struct V_3 * V_4 )
{
struct V_9 * V_6 = V_4 -> V_6 ;
if ( F_2 ( V_6 ) )
V_4 -> V_31 = ! F_21 ( V_4 -> V_1 ) ;
F_22 ( V_4 -> V_1 ) ;
V_4 -> V_32 = V_4 -> V_31 ;
return 0 ;
}
static void F_23 ( struct V_3 * V_4 )
{
while ( F_4 ( V_4 ) > 0 )
F_5 ( & V_4 -> V_7 ,
1 , V_4 ) ;
}
int F_24 ( struct V_3 * V_4 )
{
F_25 ( V_4 -> V_1 ) ;
if ( V_4 -> V_31 ) {
F_26 ( V_4 -> V_1 ) ;
V_4 -> V_31 = 0 ;
} else {
F_23 ( V_4 ) ;
}
return 0 ;
}
