static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_10 , V_12 |
V_13 |
V_14 ) ;
if ( V_11 && V_11 != - V_15 ) {
F_3 ( V_10 -> V_16 ,
L_1 ) ;
return V_11 ;
}
V_11 = F_2 ( V_9 , V_12 |
V_13 |
V_14 ) ;
if ( V_11 ) {
F_3 ( V_10 -> V_16 ,
L_2 ) ;
return V_11 ;
}
V_11 = F_4 ( V_9 , 0 ,
V_17 , V_18 ) ;
if ( V_11 ) {
F_3 ( V_10 -> V_16 ,
L_3 ) ;
return V_11 ;
}
F_5 ( V_10 , 0xffffffc , 0xffffffc , 2 , 0 ) ;
V_11 = F_4 ( V_10 , V_19 , 0 ,
V_20 ) ;
if ( V_11 && V_11 != - V_21 ) {
F_3 ( V_10 -> V_16 ,
L_4 ) ;
return V_11 ;
}
return 0 ;
}
static int F_6 ( struct V_22 * V_23 )
{
int V_11 ;
int V_24 = 0 , V_25 ;
struct V_26 * V_27 = V_23 -> V_16 . V_28 ;
struct V_26 * V_29 = NULL , * V_30 = NULL ;
V_31 . V_16 = & V_23 -> V_16 ;
if ( V_27 ) {
V_11 = F_7 ( & V_31 ,
L_5 ) ;
if ( V_11 ) {
F_3 ( & V_23 -> V_16 ,
L_6 ) ;
goto V_32;
}
V_29 = F_8 ( V_23 -> V_16 . V_28 ,
L_7 , 0 ) ;
if ( ! V_29 ) {
F_3 ( & V_23 -> V_16 ,
L_8 ) ;
V_11 = - V_33 ;
goto V_32;
}
V_30 = F_8 ( V_29 , L_9 , 0 ) ;
if ( V_30 )
V_34 . V_35 = V_30 ;
else
F_3 ( & V_23 -> V_16 , L_10 ) ;
V_11 = F_9 ( V_27 , L_11 , & V_24 ) ;
if ( V_11 ) {
F_3 ( & V_23 -> V_16 ,
L_12 ) ;
return V_11 ;
}
V_11 = F_9 ( V_27 , L_13 , & V_25 ) ;
if ( V_11 ) {
F_3 ( & V_23 -> V_16 ,
L_14 ) ;
return V_11 ;
}
V_24 -- ;
V_25 -- ;
V_34 . V_36 = V_29 ;
V_34 . V_37 = V_29 ;
} else {
V_34 . V_38 = L_15 ;
V_34 . V_39 = L_15 ;
V_34 . V_40 = L_16 ;
V_31 . V_41 = L_17 ;
}
if ( F_10 () ||
F_11 ( NULL , NULL , L_18 ) ) {
F_12 ( V_42 ,
V_43 |
V_44 |
V_45 |
V_46 |
V_47 |
F_13 ( V_48 ) |
F_14 ( V_48 ) |
F_15 ( V_48 )
) ;
F_12 ( V_48 ,
V_43 |
F_15 ( V_42 )
) ;
} else if ( F_16 () ||
F_17 () ||
F_18 () ||
F_11 ( NULL , NULL , L_19 ) ) {
if ( ! V_27 )
V_25 = F_16 () ?
4 : 3 ;
F_19 ( V_24 ,
V_49 |
V_50 |
F_20 ( V_25 ) |
V_51 |
F_21 ( V_25 ) ,
F_22 ( V_25 )
) ;
F_19 ( V_25 ,
V_49 ,
F_22 ( V_24 )
) ;
} else {
if ( V_27 ) {
F_3 ( & V_23 -> V_16 ,
L_20 ) ;
return - V_33 ;
} else {
return 0 ;
}
}
V_11 = F_23 ( & V_31 ) ;
V_32:
if ( V_11 )
F_3 ( & V_23 -> V_16 , L_21 , V_11 ) ;
F_24 ( V_29 ) ;
return V_11 ;
}
static int F_25 ( struct V_22 * V_23 )
{
F_26 ( & V_31 ) ;
return 0 ;
}
