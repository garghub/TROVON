int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
unsigned long V_5 = 0 ;
if ( ! F_2 ( V_2 , V_6 ) )
return - V_7 ;
if ( V_3 == 0 )
return - V_7 ;
if ( ! V_2 -> V_8 )
return - V_7 ;
if ( V_2 -> V_9 )
return - V_10 ;
V_2 -> V_9 = true ;
F_3 ( L_1 , V_3 ) ;
if ( V_2 -> V_11 -> V_12 )
V_2 -> V_11 -> V_12 ( V_2 ) ;
if ( F_2 ( V_2 , V_13 ) )
V_5 = V_14 ;
V_4 = F_4 ( V_3 , V_2 -> V_11 -> V_15 ,
V_5 , V_2 -> V_11 -> V_16 , V_2 ) ;
if ( V_4 < 0 ) {
V_2 -> V_9 = false ;
return V_4 ;
}
if ( V_2 -> V_11 -> V_17 )
V_4 = V_2 -> V_11 -> V_17 ( V_2 ) ;
if ( V_4 < 0 ) {
V_2 -> V_9 = false ;
if ( F_2 ( V_2 , V_18 ) )
F_5 ( V_2 -> V_19 , NULL , NULL , NULL ) ;
F_6 ( V_3 , V_2 ) ;
} else {
V_2 -> V_3 = V_3 ;
}
return V_4 ;
}
int F_7 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
bool V_9 ;
int V_21 ;
if ( ! F_2 ( V_2 , V_6 ) )
return - V_7 ;
V_9 = V_2 -> V_9 ;
V_2 -> V_9 = false ;
if ( V_2 -> V_22 ) {
F_8 ( & V_2 -> V_23 , V_20 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 ; V_21 ++ ) {
struct V_24 * V_25 = & V_2 -> V_25 [ V_21 ] ;
if ( ! V_25 -> V_26 )
continue;
F_9 ( F_2 ( V_2 , V_27 ) ) ;
F_10 ( V_2 , V_21 ) ;
F_11 ( & V_25 -> V_28 ) ;
}
F_12 ( & V_2 -> V_23 , V_20 ) ;
}
if ( ! V_9 )
return - V_7 ;
F_3 ( L_1 , V_2 -> V_3 ) ;
if ( F_2 ( V_2 , V_18 ) )
F_5 ( V_2 -> V_19 , NULL , NULL , NULL ) ;
if ( V_2 -> V_11 -> V_29 )
V_2 -> V_11 -> V_29 ( V_2 ) ;
F_6 ( V_2 -> V_3 , V_2 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 = V_30 ;
int V_4 = 0 , V_3 ;
if ( ! F_2 ( V_2 , V_6 ) )
return 0 ;
if ( ! F_2 ( V_2 , V_18 ) )
return 0 ;
if ( F_9 ( ! V_2 -> V_19 ) )
return - V_7 ;
switch ( V_34 -> V_35 ) {
case V_36 :
V_3 = V_2 -> V_19 -> V_3 ;
if ( V_2 -> V_37 < F_14 ( 1 , 2 ) &&
V_34 -> V_3 != V_3 )
return - V_7 ;
F_15 ( & V_2 -> V_38 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
F_16 ( & V_2 -> V_38 ) ;
return V_4 ;
case V_39 :
F_15 ( & V_2 -> V_38 ) ;
V_4 = F_7 ( V_2 ) ;
F_16 ( & V_2 -> V_38 ) ;
return V_4 ;
default:
return - V_7 ;
}
}
