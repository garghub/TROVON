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
int V_19 = V_4 -> V_20 - F_9 ( V_4 ) ;
F_9 ( V_4 ) [ F_10 ( V_4 ) -> V_21 ] =
F_11 ( V_4 ) -> V_22 ;
#ifndef F_12
if ( ! V_16 )
return 1 ;
#endif
F_13 ( V_4 , V_19 ) ;
F_14 ( V_4 ) -> V_23 = F_15 ( V_4 -> V_24 - sizeof( struct V_14 ) ) ;
F_16 ( V_4 , F_9 ( V_4 ) , V_19 ) ;
if ( V_18 && ( V_18 -> V_25 & V_26 ) ) {
F_17 ( V_4 ) ;
return - 1 ;
}
F_18 ( V_27 , V_28 ,
F_19 ( V_4 -> V_29 ) , NULL , V_4 , V_4 -> V_29 , NULL ,
V_30 ) ;
return - 1 ;
}
int F_20 ( struct V_3 * V_4 , struct V_7 * V_8 )
{
return F_3 ( V_4 , F_9 ( V_4 ) [ F_10 ( V_4 ) -> V_21 ] ,
0 , V_8 ) ;
}
int F_21 ( struct V_3 * V_4 )
{
return F_20 ( V_4 , NULL ) ;
}
int F_22 ( struct V_3 * V_4 , T_2 * V_15 ,
T_2 * V_31 , T_3 V_32 )
{
struct V_33 * V_33 = F_19 ( V_4 -> V_29 ) ;
struct V_1 * V_2 = NULL ;
int V_34 = 0 ;
if ( F_23 ( V_4 ) ) {
F_24 ( V_33 , V_35 ) ;
goto V_36;
}
if ( 1 + V_4 -> V_37 -> V_24 == V_38 ) {
F_24 ( V_33 , V_39 ) ;
goto V_36;
}
for ( V_34 = 0 ; V_34 < 3 ; V_34 ++ ) {
T_2 * V_40 , * V_41 ;
switch ( V_34 ) {
case 0 :
V_40 = V_15 ;
V_41 = V_31 ;
break;
case 1 :
V_40 = V_15 ;
V_41 = ( T_2 * ) & V_42 ;
break;
default:
V_40 = ( T_2 * ) & V_42 ;
V_41 = ( T_2 * ) & V_42 ;
break;
}
V_2 = F_25 ( V_33 , V_4 -> V_43 , V_40 , V_41 , V_32 , V_12 ) ;
if ( ! V_2 )
continue;
F_26 ( & V_2 -> V_44 ) ;
if ( ( ! V_34 || ( V_2 -> V_45 . V_25 & V_46 ) ) &&
F_27 ( V_2 -> V_47 . V_48 == V_49 ) &&
! F_28 ( V_2 ) ) {
F_29 ( & V_2 -> V_44 ) ;
if ( V_2 -> type -> V_50 ( V_2 , V_4 ) > 0 ) {
break;
}
} else
F_29 ( & V_2 -> V_44 ) ;
F_30 ( V_2 ) ;
V_2 = NULL ;
}
if ( ! V_2 ) {
F_24 ( V_33 , V_51 ) ;
F_31 ( V_4 , V_12 ) ;
goto V_36;
}
V_4 -> V_37 -> V_52 [ V_4 -> V_37 -> V_24 ++ ] = V_2 ;
F_26 ( & V_2 -> V_44 ) ;
V_2 -> V_53 . V_54 += V_4 -> V_24 ;
V_2 -> V_53 . V_55 ++ ;
F_29 ( & V_2 -> V_44 ) ;
return 1 ;
V_36:
return - 1 ;
}
