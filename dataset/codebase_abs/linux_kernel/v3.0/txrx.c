int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , V_7 ) ;
struct V_8 * V_9 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
V_9 = (struct V_8 * ) ( V_4 -> V_12 ) ;
V_6 = F_4 ( V_2 , V_9 -> V_13 &
V_14 , V_9 -> V_15 ) ;
if ( ! V_6 )
V_6 = F_2 ( V_2 , V_7 ) ;
V_11 -> V_16 = V_6 -> V_16 ;
return F_5 ( V_2 , V_4 ) ;
}
int F_6 ( struct V_5 * V_6 , struct V_3 * V_4 ,
struct V_17 * V_18 )
{
int V_19 = - 1 ;
struct V_1 * V_2 = V_6 -> V_2 ;
T_1 * V_20 ;
struct V_21 * V_22 = NULL ;
V_20 = ( T_1 * ) F_7 ( V_6 , V_4 ) ;
if ( V_20 ) {
if ( F_8 ( V_6 ) == V_23 )
V_22 =
(struct V_21 * ) ( V_20 + V_24 ) ;
V_19 = V_2 -> V_25 . V_26 ( V_2 , V_27 ,
V_4 -> V_12 , V_4 -> V_28 , V_18 ) ;
}
switch ( V_19 ) {
case - V_29 :
if ( ( F_8 ( V_6 ) == V_23 ) &&
( V_2 -> V_30 ) &&
( V_2 -> V_31 ) ) {
V_6 -> V_2 -> V_31 = false ;
V_22 -> V_32 = 0 ;
}
F_9 ( V_2 -> V_33 , L_1 ) ;
break;
case - 1 :
V_2 -> V_34 = false ;
F_10 ( V_2 -> V_33 , L_2 ,
V_19 ) ;
V_2 -> V_35 . V_36 ++ ;
F_11 ( V_2 , V_4 , V_19 ) ;
break;
case - V_37 :
V_2 -> V_34 = false ;
break;
case 0 :
F_11 ( V_2 , V_4 , V_19 ) ;
break;
default:
break;
}
return V_19 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_38 )
{
struct V_5 * V_6 , * V_39 ;
struct V_40 * V_41 ;
int V_42 ;
if ( ! V_4 )
return 0 ;
V_41 = F_12 ( V_4 ) ;
V_6 = F_13 ( V_2 , V_41 -> V_16 ) ;
if ( ! V_6 )
goto V_43;
V_6 -> V_44 -> V_45 = V_46 ;
if ( ! V_38 ) {
V_6 -> V_47 . V_48 ++ ;
V_6 -> V_47 . V_49 += V_4 -> V_28 ;
} else {
V_6 -> V_47 . V_50 ++ ;
}
if ( F_14 ( & V_2 -> V_51 ) >= V_52 )
goto V_43;
for ( V_42 = 0 ; V_42 < V_2 -> V_53 ; V_42 ++ ) {
V_39 = V_2 -> V_6 [ V_42 ] ;
if ( ( F_8 ( V_39 ) == V_23 )
&& ( V_39 -> V_54 ) ) {
if ( F_15 ( V_39 -> V_44 ) )
F_16 ( V_39 -> V_44 ) ;
}
}
V_43:
F_17 ( V_4 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_38 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
struct V_10 * V_55 ;
struct V_5 * V_6 ;
struct V_3 * V_56 ;
unsigned long V_32 ;
V_6 = V_2 -> V_6 [ V_11 -> V_16 ] ;
if ( V_6 && ( V_38 == - 1 ) )
V_6 -> V_47 . V_57 ++ ;
if ( V_11 -> V_58 ) {
V_56 = V_11 -> V_58 ;
V_55 = F_3 ( V_56 ) ;
F_19 ( & V_6 -> V_59 , V_32 ) ;
-- V_55 -> V_60 ;
if ( ! V_55 -> V_60 ) {
F_20 ( & V_6 -> V_59 , V_32 ) ;
F_17 ( V_56 ) ;
} else {
F_20 ( & V_6 -> V_59 , V_32 ) ;
}
} else {
F_17 ( V_4 ) ;
}
return 0 ;
}
