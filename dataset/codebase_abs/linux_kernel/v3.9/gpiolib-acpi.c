static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( ! V_2 -> V_4 )
return false ;
return F_2 ( V_2 -> V_4 ) == V_3 ;
}
int F_3 ( char * V_5 , int V_6 )
{
struct V_1 * V_7 ;
T_1 V_8 ;
T_2 V_9 ;
V_9 = F_4 ( NULL , V_5 , & V_8 ) ;
if ( F_5 ( V_9 ) )
return - V_10 ;
V_7 = F_6 ( V_8 , F_1 ) ;
if ( ! V_7 )
return - V_10 ;
if ( ! F_7 ( V_7 -> V_11 + V_6 ) )
return - V_12 ;
return V_7 -> V_11 + V_6 ;
}
static T_3 F_8 ( int V_13 , void * V_3 )
{
T_1 V_8 = V_3 ;
F_9 ( V_8 , NULL , NULL , NULL ) ;
return V_14 ;
}
void F_10 ( struct V_1 * V_7 )
{
struct V_15 V_16 = { V_17 , NULL } ;
struct V_18 * V_19 ;
T_1 V_8 , V_20 ;
T_2 V_9 ;
unsigned int V_6 ;
int V_13 , V_21 ;
char V_22 [ 5 ] ;
if ( ! V_7 -> V_4 || ! V_7 -> V_23 )
return;
V_8 = F_2 ( V_7 -> V_4 ) ;
if ( ! V_8 )
return;
V_9 = F_11 ( V_8 , & V_16 ) ;
if ( F_5 ( V_9 ) )
return;
for ( V_19 = V_16 . V_24 ;
V_19 && ( V_19 -> type != V_25 ) ;
V_19 = F_12 ( V_19 ) ) {
if ( V_19 -> type != V_26 ||
V_19 -> V_3 . V_27 . V_28 !=
V_29 )
continue;
V_6 = V_19 -> V_3 . V_27 . V_30 [ 0 ] ;
if ( V_6 > V_7 -> V_31 )
continue;
sprintf ( V_22 , L_1 ,
V_19 -> V_3 . V_27 . V_32 ? 'E' : 'L' , V_6 ) ;
V_9 = F_4 ( V_8 , V_22 , & V_20 ) ;
if ( F_5 ( V_9 ) )
continue;
V_13 = V_7 -> V_23 ( V_7 , V_6 ) ;
if ( V_13 < 0 )
continue;
V_21 = F_13 ( V_7 -> V_4 , V_13 , NULL ,
F_8 ,
0 ,
L_2 ,
V_20 ) ;
if ( V_21 )
F_14 ( V_7 -> V_4 ,
L_3 ,
V_13 ) ;
}
}
