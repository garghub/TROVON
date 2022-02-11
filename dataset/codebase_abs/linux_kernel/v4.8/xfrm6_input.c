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
F_9 ( V_4 ) [ F_10 ( V_4 ) -> V_17 ] =
F_11 ( V_4 ) -> V_18 ;
#ifndef F_12
if ( ! V_16 )
return 1 ;
#endif
F_13 ( V_4 ) -> V_19 = F_14 ( V_4 -> V_20 ) ;
F_15 ( V_4 , V_4 -> V_21 - F_9 ( V_4 ) ) ;
F_16 ( V_22 , V_23 ,
F_17 ( V_4 -> V_24 ) , NULL , V_4 , V_4 -> V_24 , NULL ,
V_25 ) ;
return - 1 ;
}
int F_18 ( struct V_3 * V_4 , struct V_7 * V_8 )
{
return F_3 ( V_4 , F_9 ( V_4 ) [ F_10 ( V_4 ) -> V_17 ] ,
0 , V_8 ) ;
}
int F_19 ( struct V_3 * V_4 )
{
return F_18 ( V_4 , NULL ) ;
}
int F_20 ( struct V_3 * V_4 , T_2 * V_15 ,
T_2 * V_26 , T_3 V_27 )
{
struct V_28 * V_28 = F_17 ( V_4 -> V_24 ) ;
struct V_1 * V_2 = NULL ;
int V_29 = 0 ;
if ( ! V_4 -> V_30 || F_21 ( & V_4 -> V_30 -> V_31 ) != 1 ) {
struct V_32 * V_30 ;
V_30 = F_22 ( V_4 -> V_30 ) ;
if ( ! V_30 ) {
F_23 ( V_28 , V_33 ) ;
goto V_34;
}
if ( V_4 -> V_30 )
F_24 ( V_4 -> V_30 ) ;
V_4 -> V_30 = V_30 ;
}
if ( 1 + V_4 -> V_30 -> V_20 == V_35 ) {
F_23 ( V_28 , V_36 ) ;
goto V_34;
}
for ( V_29 = 0 ; V_29 < 3 ; V_29 ++ ) {
T_2 * V_37 , * V_38 ;
switch ( V_29 ) {
case 0 :
V_37 = V_15 ;
V_38 = V_26 ;
break;
case 1 :
V_37 = V_15 ;
V_38 = ( T_2 * ) & V_39 ;
break;
default:
V_37 = ( T_2 * ) & V_39 ;
V_38 = ( T_2 * ) & V_39 ;
break;
}
V_2 = F_25 ( V_28 , V_4 -> V_40 , V_37 , V_38 , V_27 , V_12 ) ;
if ( ! V_2 )
continue;
F_26 ( & V_2 -> V_41 ) ;
if ( ( ! V_29 || ( V_2 -> V_42 . V_43 & V_44 ) ) &&
F_27 ( V_2 -> V_45 . V_46 == V_47 ) &&
! F_28 ( V_2 ) ) {
F_29 ( & V_2 -> V_41 ) ;
if ( V_2 -> type -> V_48 ( V_2 , V_4 ) > 0 ) {
break;
}
} else
F_29 ( & V_2 -> V_41 ) ;
F_30 ( V_2 ) ;
V_2 = NULL ;
}
if ( ! V_2 ) {
F_23 ( V_28 , V_49 ) ;
F_31 ( V_4 , V_12 ) ;
goto V_34;
}
V_4 -> V_30 -> V_50 [ V_4 -> V_30 -> V_20 ++ ] = V_2 ;
F_26 ( & V_2 -> V_41 ) ;
V_2 -> V_51 . V_52 += V_4 -> V_20 ;
V_2 -> V_51 . V_53 ++ ;
F_29 ( & V_2 -> V_41 ) ;
return 1 ;
V_34:
return - 1 ;
}
