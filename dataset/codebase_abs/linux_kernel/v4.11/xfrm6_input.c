int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_2 ( V_4 ) ;
}
int F_3 ( struct V_3 * V_4 , int V_5 , T_1 V_6 ,
struct V_7 * V_8 )
{
F_4 ( V_4 ) -> V_9 . V_10 = V_8 ;
F_5 ( V_4 ) -> V_11 = V_12 ;
F_5 ( V_4 ) -> V_13 = F_6 ( struct V_14 , V_15 ) ;
return F_7 ( V_4 , V_5 , V_6 , 0 ) ;
}
int F_8 ( struct V_3 * V_4 , int V_16 )
{
struct V_17 * V_18 = V_17 ( V_4 ) ;
F_9 ( V_4 ) [ F_10 ( V_4 ) -> V_19 ] =
F_11 ( V_4 ) -> V_20 ;
#ifndef F_12
if ( ! V_16 )
return 1 ;
#endif
F_13 ( V_4 ) -> V_21 = F_14 ( V_4 -> V_22 ) ;
F_15 ( V_4 , V_4 -> V_23 - F_9 ( V_4 ) ) ;
if ( V_18 && ( V_18 -> V_24 & V_25 ) ) {
F_16 ( V_4 ) ;
return - 1 ;
}
F_17 ( V_26 , V_27 ,
F_18 ( V_4 -> V_28 ) , NULL , V_4 , V_4 -> V_28 , NULL ,
V_29 ) ;
return - 1 ;
}
int F_19 ( struct V_3 * V_4 , struct V_7 * V_8 )
{
return F_3 ( V_4 , F_9 ( V_4 ) [ F_10 ( V_4 ) -> V_19 ] ,
0 , V_8 ) ;
}
int F_20 ( struct V_3 * V_4 )
{
return F_19 ( V_4 , NULL ) ;
}
int F_21 ( struct V_3 * V_4 , T_2 * V_15 ,
T_2 * V_30 , T_3 V_31 )
{
struct V_32 * V_32 = F_18 ( V_4 -> V_28 ) ;
struct V_1 * V_2 = NULL ;
int V_33 = 0 ;
if ( F_22 ( V_4 ) ) {
F_23 ( V_32 , V_34 ) ;
goto V_35;
}
if ( 1 + V_4 -> V_36 -> V_22 == V_37 ) {
F_23 ( V_32 , V_38 ) ;
goto V_35;
}
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ ) {
T_2 * V_39 , * V_40 ;
switch ( V_33 ) {
case 0 :
V_39 = V_15 ;
V_40 = V_30 ;
break;
case 1 :
V_39 = V_15 ;
V_40 = ( T_2 * ) & V_41 ;
break;
default:
V_39 = ( T_2 * ) & V_41 ;
V_40 = ( T_2 * ) & V_41 ;
break;
}
V_2 = F_24 ( V_32 , V_4 -> V_42 , V_39 , V_40 , V_31 , V_12 ) ;
if ( ! V_2 )
continue;
F_25 ( & V_2 -> V_43 ) ;
if ( ( ! V_33 || ( V_2 -> V_44 . V_24 & V_45 ) ) &&
F_26 ( V_2 -> V_46 . V_47 == V_48 ) &&
! F_27 ( V_2 ) ) {
F_28 ( & V_2 -> V_43 ) ;
if ( V_2 -> type -> V_49 ( V_2 , V_4 ) > 0 ) {
break;
}
} else
F_28 ( & V_2 -> V_43 ) ;
F_29 ( V_2 ) ;
V_2 = NULL ;
}
if ( ! V_2 ) {
F_23 ( V_32 , V_50 ) ;
F_30 ( V_4 , V_12 ) ;
goto V_35;
}
V_4 -> V_36 -> V_51 [ V_4 -> V_36 -> V_22 ++ ] = V_2 ;
F_25 ( & V_2 -> V_43 ) ;
V_2 -> V_52 . V_53 += V_4 -> V_22 ;
V_2 -> V_52 . V_54 ++ ;
F_28 ( & V_2 -> V_43 ) ;
return 1 ;
V_35:
return - 1 ;
}
