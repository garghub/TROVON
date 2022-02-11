int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_2 ( V_4 ) ;
}
int F_3 ( struct V_3 * V_4 , int V_5 , T_1 V_6 )
{
F_4 ( V_4 ) -> V_7 = V_8 ;
F_4 ( V_4 ) -> V_9 = F_5 ( struct V_10 , V_11 ) ;
return F_6 ( V_4 , V_5 , V_6 , 0 ) ;
}
int F_7 ( struct V_3 * V_4 , int V_12 )
{
F_8 ( V_4 ) [ F_9 ( V_4 ) -> V_13 ] =
F_10 ( V_4 ) -> V_14 ;
#ifndef F_11
if ( ! V_12 )
return 1 ;
#endif
F_12 ( V_4 ) -> V_15 = F_13 ( V_4 -> V_16 ) ;
F_14 ( V_4 , V_4 -> V_17 - F_8 ( V_4 ) ) ;
F_15 ( V_18 , V_19 ,
F_16 ( V_4 -> V_20 ) , NULL , V_4 , V_4 -> V_20 , NULL ,
V_21 ) ;
return - 1 ;
}
int F_17 ( struct V_3 * V_4 )
{
return F_3 ( V_4 , F_8 ( V_4 ) [ F_9 ( V_4 ) -> V_13 ] ,
0 ) ;
}
int F_18 ( struct V_3 * V_4 , T_2 * V_11 ,
T_2 * V_22 , T_3 V_23 )
{
struct V_24 * V_24 = F_16 ( V_4 -> V_20 ) ;
struct V_1 * V_2 = NULL ;
int V_25 = 0 ;
if ( ! V_4 -> V_26 || F_19 ( & V_4 -> V_26 -> V_27 ) != 1 ) {
struct V_28 * V_26 ;
V_26 = F_20 ( V_4 -> V_26 ) ;
if ( ! V_26 ) {
F_21 ( V_24 , V_29 ) ;
goto V_30;
}
if ( V_4 -> V_26 )
F_22 ( V_4 -> V_26 ) ;
V_4 -> V_26 = V_26 ;
}
if ( 1 + V_4 -> V_26 -> V_16 == V_31 ) {
F_21 ( V_24 , V_32 ) ;
goto V_30;
}
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ ) {
T_2 * V_33 , * V_34 ;
switch ( V_25 ) {
case 0 :
V_33 = V_11 ;
V_34 = V_22 ;
break;
case 1 :
V_33 = V_11 ;
V_34 = ( T_2 * ) & V_35 ;
break;
default:
V_33 = ( T_2 * ) & V_35 ;
V_34 = ( T_2 * ) & V_35 ;
break;
}
V_2 = F_23 ( V_24 , V_4 -> V_36 , V_33 , V_34 , V_23 , V_8 ) ;
if ( ! V_2 )
continue;
F_24 ( & V_2 -> V_37 ) ;
if ( ( ! V_25 || ( V_2 -> V_38 . V_39 & V_40 ) ) &&
F_25 ( V_2 -> V_41 . V_42 == V_43 ) &&
! F_26 ( V_2 ) ) {
F_27 ( & V_2 -> V_37 ) ;
if ( V_2 -> type -> V_44 ( V_2 , V_4 ) > 0 ) {
break;
}
} else
F_27 ( & V_2 -> V_37 ) ;
F_28 ( V_2 ) ;
V_2 = NULL ;
}
if ( ! V_2 ) {
F_21 ( V_24 , V_45 ) ;
F_29 ( V_4 , V_8 ) ;
goto V_30;
}
V_4 -> V_26 -> V_46 [ V_4 -> V_26 -> V_16 ++ ] = V_2 ;
F_24 ( & V_2 -> V_37 ) ;
V_2 -> V_47 . V_48 += V_4 -> V_16 ;
V_2 -> V_47 . V_49 ++ ;
F_27 ( & V_2 -> V_37 ) ;
return 1 ;
V_30:
return - 1 ;
}
