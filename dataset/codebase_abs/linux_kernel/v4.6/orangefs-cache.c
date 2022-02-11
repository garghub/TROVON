int F_1 ( void )
{
V_1 = F_2 ( L_1 ,
sizeof( struct V_2 ) ,
0 ,
V_3 ,
NULL ) ;
if ( ! V_1 ) {
F_3 ( L_2 ) ;
return - V_4 ;
}
F_4 ( & V_5 ) ;
V_6 = 100 ;
F_5 ( & V_5 ) ;
return 0 ;
}
int F_6 ( void )
{
F_7 ( V_1 ) ;
return 0 ;
}
char * F_8 ( struct V_2 * V_7 )
{
if ( V_7 ) {
T_1 type = V_7 -> V_8 . type ;
if ( type == V_9 )
return L_3 ;
else if ( type == V_10 )
return L_4 ;
else if ( type == V_11 )
return L_5 ;
else if ( type == V_12 )
return L_6 ;
else if ( type == V_13 )
return L_7 ;
else if ( type == V_14 )
return L_8 ;
else if ( type == V_15 )
return L_9 ;
else if ( type == V_16 )
return L_10 ;
else if ( type == V_17 )
return L_11 ;
else if ( type == V_18 )
return L_12 ;
else if ( type == V_19 )
return L_13 ;
else if ( type == V_20 )
return L_14 ;
else if ( type == V_21 )
return L_15 ;
else if ( type == V_22 )
return L_16 ;
else if ( type == V_23 )
return L_17 ;
else if ( type == V_24 )
return L_18 ;
else if ( type == V_25 )
return L_19 ;
else if ( type == V_26 )
return L_20 ;
else if ( type == V_27 )
return L_21 ;
else if ( type == V_28 )
return L_22 ;
else if ( type == V_29 )
return L_23 ;
else if ( type == V_30 )
return L_24 ;
else if ( type == V_31 )
return L_25 ;
else if ( type == V_32 )
return L_26 ;
else if ( type == V_33 )
return L_27 ;
}
return L_28 ;
}
void F_9 ( struct V_2 * V_34 )
{
F_4 ( & V_5 ) ;
V_34 -> V_35 = V_6 ++ ;
if ( V_6 == 0 )
V_6 = 100 ;
F_5 ( & V_5 ) ;
}
struct V_2 * F_10 ( T_1 type )
{
struct V_2 * V_7 = NULL ;
V_7 = F_11 ( V_1 , V_36 ) ;
if ( V_7 ) {
F_12 ( & V_7 -> V_37 ) ;
F_13 ( & V_7 -> V_38 ) ;
F_14 ( & V_7 -> V_39 ) ;
V_7 -> V_8 . type = V_40 ;
V_7 -> V_41 . type = V_40 ;
V_7 -> V_41 . V_42 = - 1 ;
V_7 -> V_43 = V_44 ;
F_9 ( V_7 ) ;
V_7 -> V_8 . type = type ;
V_7 -> V_45 = 0 ;
F_15 ( V_46 ,
L_29 ,
V_7 ,
F_16 ( V_7 -> V_35 ) ,
F_8 ( V_7 ) ) ;
V_7 -> V_8 . V_47 = F_17 ( F_18 () ,
F_19 () ) ;
V_7 -> V_8 . V_48 = F_20 ( F_18 () ,
F_21 () ) ;
} else {
F_3 ( L_30 ) ;
}
return V_7 ;
}
void F_22 ( struct V_2 * V_49 )
{
if ( V_49 ) {
F_15 ( V_46 ,
L_31 ,
V_49 ,
F_16 ( V_49 -> V_35 ) ) ;
F_23 ( V_1 , V_49 ) ;
} else {
F_3 ( L_32 ) ;
}
}
