static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 )
{
int V_6 = 0 ;
V_5 |= V_4 -> V_7 ;
if ( V_5 )
V_6 = F_2 ( V_2 , V_5 ) ;
if ( V_6 == - V_8 ) {
F_3 ( V_2 -> V_9 , L_1 ) ;
V_6 = 0 ;
}
if ( ! V_6 && V_4 -> V_10 )
V_6 = F_4 ( V_2 , 0 , V_4 -> V_10 , 0 ) ;
return V_6 ;
}
static int F_5 ( struct V_11 * V_12 )
{
struct V_13 * V_14 =
F_6 ( V_12 -> V_15 ) ;
struct V_1 * V_16 = V_12 -> V_17 ;
struct V_1 * V_18 = V_12 -> V_19 ;
unsigned int V_5 = V_14 -> V_5 ;
int V_6 ;
V_6 = F_1 ( V_16 , & V_14 -> V_17 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_1 ( V_18 , & V_14 -> V_19 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int
F_7 ( struct V_20 * V_21 ,
struct V_3 * V_2 ,
struct V_20 * * V_22 )
{
struct V_23 * V_23 ;
int V_6 ;
* V_22 = F_8 ( V_21 , L_2 , 0 ) ;
if ( ! * V_22 )
return - V_24 ;
V_6 = F_9 ( V_21 , & V_2 -> V_25 ) ;
if ( V_6 < 0 )
goto V_26;
V_2 -> V_7 = F_10 ( V_21 , NULL ) ;
if ( F_11 ( V_21 , L_3 ) ) {
V_23 = F_12 ( V_21 , 0 ) ;
if ( F_13 ( V_23 ) ) {
V_6 = F_14 ( V_23 ) ;
goto V_26;
}
V_2 -> V_10 = F_15 ( V_23 ) ;
} else if ( F_11 ( V_21 , L_4 ) ) {
F_16 ( V_21 ,
L_4 ,
& V_2 -> V_10 ) ;
} else {
V_23 = F_12 ( * V_22 , 0 ) ;
if ( ! F_13 ( V_23 ) )
V_2 -> V_10 = F_15 ( V_23 ) ;
}
V_6 = 0 ;
V_26:
F_17 ( * V_22 ) ;
return V_6 ;
}
static int F_18 ( struct V_20 * V_22 ,
struct V_13 * V_14 ,
struct V_27 * V_9 ,
struct V_20 * * V_28 ,
struct V_20 * * V_29 ,
struct V_20 * * V_30 )
{
struct V_20 * V_21 ;
char * V_25 ;
int V_6 ;
V_14 -> V_5 = F_10 ( V_22 , L_5 ) &
( V_31 | V_32 ) ;
if ( F_11 ( V_22 , L_6 ) ) {
V_6 = F_19 ( & V_14 -> V_33 ,
L_6 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = - V_34 ;
V_21 = F_20 ( V_22 , L_7 ) ;
if ( V_21 )
V_6 = F_7 ( V_21 ,
& V_14 -> V_19 ,
V_28 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = - V_34 ;
V_21 = F_20 ( V_22 , L_8 ) ;
if ( V_21 )
V_6 = F_7 ( V_21 ,
& V_14 -> V_17 ,
V_29 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! V_14 -> V_19 . V_25 || ! V_14 -> V_17 . V_25 )
return - V_34 ;
V_25 = F_21 ( V_9 ,
strlen ( V_14 -> V_19 . V_25 ) +
strlen ( V_14 -> V_17 . V_25 ) + 2 ,
V_35 ) ;
sprintf ( V_25 , L_9 , V_14 -> V_19 . V_25 , V_14 -> V_17 . V_25 ) ;
V_14 -> V_25 = V_14 -> V_15 = V_25 ;
* V_30 = * V_28 ;
F_3 ( V_9 , L_10 , V_14 -> V_15 ) ;
F_3 ( V_9 , L_11 , V_14 -> V_5 ) ;
F_3 ( V_9 , L_12 ,
V_14 -> V_19 . V_25 ,
V_14 -> V_19 . V_7 ,
V_14 -> V_19 . V_10 ) ;
F_3 ( V_9 , L_13 ,
V_14 -> V_17 . V_25 ,
V_14 -> V_17 . V_7 ,
V_14 -> V_17 . V_10 ) ;
return 0 ;
}
static int F_22 ( struct V_36 * V_37 )
{
struct V_13 * V_38 ;
struct V_20 * V_21 = V_37 -> V_9 . V_39 ;
struct V_20 * V_28 , * V_29 , * V_30 ;
struct V_27 * V_9 = & V_37 -> V_9 ;
int V_6 ;
V_38 = NULL ;
V_28 = NULL ;
V_29 = NULL ;
V_30 = NULL ;
V_38 = F_21 ( V_9 , sizeof( * V_38 ) , V_35 ) ;
if ( ! V_38 )
return - V_40 ;
if ( V_21 && F_23 ( V_21 ) ) {
V_38 -> V_33 . V_9 = V_9 ;
V_6 = F_18 ( V_21 , V_38 , V_9 ,
& V_28 ,
& V_29 ,
& V_30 ) ;
if ( V_6 < 0 ) {
if ( V_6 != - V_41 )
F_24 ( V_9 , L_14 , V_6 ) ;
return V_6 ;
}
} else {
if ( ! V_9 -> V_42 ) {
F_24 ( V_9 , L_15 ) ;
return - V_34 ;
}
memcpy ( V_38 , V_9 -> V_42 , sizeof( * V_38 ) ) ;
V_38 -> V_33 . V_9 = V_9 ;
}
if ( ! V_38 -> V_25 ||
! V_38 -> V_15 ||
! V_38 -> V_17 . V_25 ||
! ( V_38 -> V_16 || V_29 ) ||
! ( V_38 -> V_43 || V_30 ) ||
! ( V_38 -> V_19 . V_25 || V_28 ) ) {
F_24 ( V_9 , L_16 ) ;
return - V_34 ;
}
V_38 -> V_44 . V_25 = V_38 -> V_25 ;
V_38 -> V_44 . V_45 = V_38 -> V_25 ;
V_38 -> V_44 . V_46 = V_38 -> V_19 . V_25 ;
V_38 -> V_44 . V_47 = V_38 -> V_43 ;
V_38 -> V_44 . V_48 = V_38 -> V_16 ;
V_38 -> V_44 . V_49 = V_38 -> V_17 . V_25 ;
V_38 -> V_44 . V_50 = V_28 ;
V_38 -> V_44 . V_51 = V_29 ;
V_38 -> V_44 . V_52 = V_30 ;
V_38 -> V_44 . V_53 = F_5 ;
V_38 -> V_33 . V_25 = V_38 -> V_15 ;
V_38 -> V_33 . V_54 = V_55 ;
V_38 -> V_33 . V_56 = & V_38 -> V_44 ;
V_38 -> V_33 . V_57 = 1 ;
F_25 ( & V_38 -> V_33 , V_38 ) ;
return F_26 ( & V_37 -> V_9 , & V_38 -> V_33 ) ;
}
