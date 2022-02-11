static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_9 , 0 ,
V_12 , V_13 ) ;
if ( V_11 ) {
F_3 ( V_10 -> V_14 ,
L_1 ) ;
return V_11 ;
}
F_4 ( V_10 , 0x3 , 0x3 , 2 , 0 ) ;
V_11 = F_2 ( V_10 , V_15 , 0 ,
V_16 ) ;
if ( V_11 && V_11 != - V_17 ) {
F_3 ( V_10 -> V_14 ,
L_2 ) ;
return V_11 ;
}
return 0 ;
}
static int F_5 ( struct V_18 * V_19 )
{
int V_11 ;
int V_20 = 0 , V_21 ;
struct V_22 * V_23 = V_19 -> V_14 . V_24 ;
struct V_22 * V_25 = NULL , * V_26 = NULL ;
V_27 . V_14 = & V_19 -> V_14 ;
if ( V_23 ) {
V_11 = F_6 ( & V_27 ,
L_3 ) ;
if ( V_11 ) {
F_3 ( & V_19 -> V_14 ,
L_4 ) ;
goto V_28;
}
V_25 = F_7 ( V_19 -> V_14 . V_24 ,
L_5 , 0 ) ;
if ( ! V_25 ) {
F_3 ( & V_19 -> V_14 ,
L_6 ) ;
V_11 = - V_29 ;
goto V_28;
}
V_26 = F_7 ( V_25 , L_7 , 0 ) ;
if ( V_26 )
V_30 . V_31 = V_26 ;
else
F_3 ( & V_19 -> V_14 , L_8 ) ;
V_11 = F_8 ( V_23 , L_9 , & V_20 ) ;
if ( V_11 ) {
F_3 ( & V_19 -> V_14 ,
L_10 ) ;
return V_11 ;
}
V_11 = F_8 ( V_23 , L_11 , & V_21 ) ;
if ( V_11 ) {
F_3 ( & V_19 -> V_14 ,
L_12 ) ;
return V_11 ;
}
V_20 -- ;
V_21 -- ;
V_30 . V_32 = V_25 ;
V_30 . V_33 = V_25 ;
} else {
V_30 . V_34 = L_13 ;
V_30 . V_35 = L_13 ;
V_30 . V_36 = L_14 ;
V_27 . V_37 = L_15 ;
}
if ( F_9 () ||
F_10 ( NULL , NULL , L_16 ) ) {
F_11 ( V_38 ,
V_39 |
V_40 |
V_41 |
V_42 |
V_43 |
F_12 ( V_44 ) |
F_13 ( V_44 ) |
F_14 ( V_44 )
) ;
F_11 ( V_44 ,
V_39 |
F_14 ( V_38 )
) ;
} else if ( F_15 () ||
F_16 () ||
F_17 () ||
F_10 ( NULL , NULL , L_17 ) ) {
if ( ! V_23 )
V_21 = F_15 () ?
4 : 3 ;
F_18 ( V_20 ,
V_45 |
V_46 |
F_19 ( V_21 ) |
V_47 |
F_20 ( V_21 ) ,
F_21 ( V_21 )
) ;
F_18 ( V_21 ,
V_45 ,
F_21 ( V_20 )
) ;
} else {
if ( V_23 ) {
F_3 ( & V_19 -> V_14 ,
L_18 ) ;
return - V_29 ;
} else {
return 0 ;
}
}
V_11 = F_22 ( & V_27 ) ;
V_28:
if ( V_11 )
F_3 ( & V_19 -> V_14 , L_19 , V_11 ) ;
F_23 ( V_25 ) ;
return V_11 ;
}
static int F_24 ( struct V_18 * V_19 )
{
F_25 ( & V_27 ) ;
return 0 ;
}
