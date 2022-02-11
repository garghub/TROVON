static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( L_1 ,
F_3 ( 0 ) , F_4 ( 0 ) ,
F_5 () ,
( ( V_5 & ~ V_6 ) |
V_7 | V_8 ) ,
V_9 , NULL ) ;
if ( F_6 ( V_4 ) )
return F_7 ( V_4 ) ;
V_2 -> V_10 = V_4 ;
return 0 ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_2 V_11 ,
struct V_12 * V_13 )
{
struct V_3 * V_14 ;
T_1 V_15 , V_16 ;
if ( ! V_2 -> V_10 ) {
long V_17 = F_1 ( V_2 ) ;
if ( V_17 < 0 )
return F_9 ( V_17 ) ;
} else {
V_15 = F_10 ( V_2 -> V_10 , true ) ;
V_16 = F_11 ( V_15 , V_13 ) ;
if ( V_16 )
return V_16 ;
}
V_14 = F_2 ( V_13 -> V_18 ,
V_11 , V_19 , F_5 () ,
( ( V_5 & ~ V_6 ) |
V_7 | V_8 ) ,
V_9 ,
V_2 -> V_10 ) ;
if ( F_6 ( V_14 ) )
return F_12 ( V_14 ) ;
return F_10 ( V_14 , true ) ;
}
static long F_13 ( struct V_1 * V_2 , T_2 V_11 ,
T_1 V_20 )
{
struct V_12 V_13 ;
struct V_3 * V_14 ;
T_1 V_15 , V_16 ;
char V_21 [ 32 ] ;
long V_22 ;
V_13 . type = & V_23 ;
V_13 . V_18 = V_21 ;
V_13 . V_24 = sprintf ( V_21 , L_2 , F_14 ( V_2 , V_11 ) ) ;
if ( V_2 -> V_10 ) {
V_15 = F_10 ( V_2 -> V_10 , true ) ;
F_15 ( & V_2 -> V_25 ) ;
V_16 = F_11 ( V_15 , & V_13 ) ;
F_16 ( & V_2 -> V_25 ) ;
if ( V_16 )
goto V_26;
}
F_17 ( & V_2 -> V_25 ) ;
V_16 = F_8 ( V_2 , V_11 , & V_13 ) ;
F_18 ( & V_2 -> V_25 ) ;
if ( ! F_6 ( V_16 ) )
goto V_26;
return F_7 ( V_16 ) ;
V_26:
V_22 = F_19 ( V_16 , F_5 () , V_27 ) ;
if ( V_22 == 0 ) {
V_14 = F_20 ( V_16 ) ;
V_22 = F_21 ( F_20 ( V_20 ) , V_14 ) ;
if ( V_22 == 0 ) {
F_22 ( V_14 , V_28 ) ;
V_22 = V_14 -> V_29 ;
}
}
F_23 ( V_16 ) ;
return V_22 ;
}
long F_24 ( T_3 V_30 , T_4 V_31 )
{
struct V_1 * V_2 = F_25 () ;
T_1 V_20 ;
T_2 V_11 ;
long V_22 ;
if ( V_30 == ( T_3 ) - 1 ) {
V_11 = F_26 () ;
} else {
V_11 = F_27 ( V_2 , V_30 ) ;
if ( ! F_28 ( V_11 ) )
return - V_32 ;
if ( ! F_29 ( V_11 , F_26 () ) &&
! F_29 ( V_11 , F_30 () ) &&
! F_31 ( V_2 , V_33 ) )
return - V_34 ;
}
V_20 = F_32 ( V_31 , V_35 , V_36 ) ;
if ( F_6 ( V_20 ) )
return F_7 ( V_20 ) ;
if ( F_20 ( V_20 ) -> type != & V_23 ) {
V_22 = - V_37 ;
goto V_38;
}
V_22 = F_13 ( V_2 , V_11 , V_20 ) ;
V_38:
F_23 ( V_20 ) ;
return V_22 ;
}
