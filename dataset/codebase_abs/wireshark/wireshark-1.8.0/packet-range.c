static void F_1 ( T_1 * V_1 ) {
T_2 V_2 ;
T_2 V_3 ;
T_2 V_4 ;
T_2 V_5 ;
T_2 V_6 ;
T_3 * V_7 ;
V_1 -> V_8 = 0L ;
V_3 = 0L ;
V_4 = 0L ;
V_1 -> V_9 = 0L ;
V_1 -> V_10 = 0L ;
V_1 -> V_11 = 0L ;
V_1 -> V_12 = 0L ;
V_1 -> V_13 = 0L ;
V_5 = 0L ;
V_6 = 0L ;
V_1 -> V_14 = 0L ;
V_1 -> V_15 = 0L ;
V_1 -> V_16 = 0L ;
V_1 -> V_17 = 0L ;
V_1 -> V_18 = 0L ;
V_1 -> V_19 = 0L ;
V_1 -> V_20 = 0L ;
V_1 -> V_21 = 0L ;
if ( V_22 . V_23 != NULL ) {
for( V_2 = 1 ; V_2 <= V_22 . V_24 ; V_2 ++ ) {
V_7 = F_2 ( V_22 . V_23 , V_2 ) ;
if ( V_22 . V_25 == V_7 ) {
V_1 -> V_8 = V_2 ;
}
if ( V_7 -> V_26 . V_27 ) {
V_1 -> V_14 ++ ;
}
if ( V_7 -> V_26 . V_27 ||
V_7 -> V_26 . V_28 ) {
V_1 -> V_17 ++ ;
}
if ( V_7 -> V_26 . V_29 ) {
if ( V_7 -> V_26 . V_30 ) {
V_1 -> V_11 ++ ;
}
if ( V_7 -> V_26 . V_27 ) {
V_1 -> V_15 ++ ;
if ( V_7 -> V_26 . V_30 ) {
V_1 -> V_19 ++ ;
}
if ( V_5 == 0 ) {
V_5 = V_2 ;
}
if ( V_2 > V_6 ) {
V_6 = V_2 ;
}
}
if ( V_3 == 0 ) {
V_3 = V_2 ;
}
if ( V_2 > V_4 ) {
V_4 = V_2 ;
}
}
if ( V_7 -> V_26 . V_30 ) {
V_1 -> V_10 ++ ;
if ( V_7 -> V_26 . V_27 ) {
V_1 -> V_18 ++ ;
}
}
}
for( V_2 = 1 ; V_2 <= V_22 . V_24 ; V_2 ++ ) {
V_7 = F_2 ( V_22 . V_23 , V_2 ) ;
if ( V_2 >= V_3 &&
V_2 <= V_4 )
{
V_1 -> V_9 ++ ;
if ( V_7 -> V_26 . V_30 ) {
V_1 -> V_12 ++ ;
}
}
if ( V_2 >= V_5 &&
V_2 <= V_6 )
{
if ( V_7 -> V_26 . V_27 ) {
V_1 -> V_16 ++ ;
if ( V_7 -> V_26 . V_30 ) {
V_1 -> V_20 ++ ;
}
}
}
}
#if 0
if (cfile.marked_count != 0) {
range->mark_range = mark_high - mark_low + 1;
}
if (range->displayed_marked_cnt != 0) {
range->displayed_mark_range = displayed_mark_high - displayed_mark_low + 1;
}
#endif
}
}
static void F_3 ( T_1 * V_1 ) {
T_2 V_2 ;
T_3 * V_7 ;
V_1 -> V_31 = 0L ;
V_1 -> V_13 = 0L ;
V_1 -> V_32 = 0L ;
V_1 -> V_21 = 0L ;
if ( V_22 . V_23 != NULL ) {
for( V_2 = 1 ; V_2 <= V_22 . V_24 ; V_2 ++ ) {
V_7 = F_2 ( V_22 . V_23 , V_2 ) ;
if ( F_4 ( V_1 -> V_33 , V_2 ) ) {
V_1 -> V_31 ++ ;
if ( V_7 -> V_26 . V_30 ) {
V_1 -> V_13 ++ ;
}
if ( V_7 -> V_26 . V_27 ) {
V_1 -> V_32 ++ ;
if ( V_7 -> V_26 . V_30 ) {
V_1 -> V_21 ++ ;
}
}
}
}
}
}
void F_5 ( T_1 * V_1 ) {
V_1 -> V_34 = V_35 ;
V_1 -> V_36 = FALSE ;
V_1 -> V_37 = FALSE ;
V_1 -> V_33 = F_6 () ;
F_1 ( V_1 ) ;
F_3 ( V_1 ) ;
}
T_4 F_7 ( T_1 * V_1 ) {
if ( V_1 -> V_34 == V_38 && V_1 -> V_33 == NULL ) {
return V_1 -> V_39 ;
}
return V_40 ;
}
void F_8 ( T_1 * V_1 ) {
V_1 -> V_41 = FALSE ;
V_1 -> V_42 = FALSE ;
if ( V_1 -> V_36 == FALSE ) {
V_1 -> V_43 = V_1 -> V_9 ;
} else {
V_1 -> V_43 = V_1 -> V_16 ;
}
}
T_5 F_9 ( T_1 * V_1 ) {
return V_1 -> V_34 == V_35 && ! V_1 -> V_36 && ! V_1 -> V_37 ;
}
T_6 F_10 ( T_1 * V_1 , T_3 * V_44 ) {
if ( V_1 -> V_37 && V_44 -> V_26 . V_30 ) {
return V_45 ;
}
switch( V_1 -> V_34 ) {
case ( V_35 ) :
break;
case ( V_46 ) :
if ( V_1 -> V_42 ) {
return V_47 ;
}
if ( V_44 -> V_48 != V_22 . V_25 -> V_48 ) {
return V_45 ;
}
V_1 -> V_42 = TRUE ;
break;
case ( V_49 ) :
if ( V_44 -> V_26 . V_29 == FALSE ) {
return V_45 ;
}
break;
case ( V_50 ) :
if ( V_1 -> V_43 == 0 ) {
return V_47 ;
}
if ( V_44 -> V_26 . V_29 == TRUE ) {
V_1 -> V_41 = TRUE ;
}
if ( V_1 -> V_41 == FALSE ) {
return V_45 ;
}
if ( ! V_1 -> V_36 ||
( V_1 -> V_36 && V_44 -> V_26 . V_27 == TRUE ) )
{
V_1 -> V_43 -- ;
}
break;
case ( V_38 ) :
if ( F_4 ( V_1 -> V_33 , V_44 -> V_48 ) == FALSE ) {
return V_45 ;
}
break;
default:
F_11 () ;
}
if ( ( V_1 -> V_36 && V_44 -> V_26 . V_27 == FALSE ) &&
! ( V_1 -> V_51 && V_44 -> V_26 . V_28 ) ) {
return V_45 ;
}
return V_52 ;
}
void F_12 ( T_1 * V_1 , const T_7 * V_53 )
{
T_8 * V_54 ;
T_4 V_55 ;
if ( V_1 -> V_33 != NULL )
F_13 ( V_1 -> V_33 ) ;
V_55 = F_14 ( & V_54 , V_53 , V_22 . V_24 ) ;
if ( V_55 != V_40 ) {
V_1 -> V_33 = NULL ;
V_1 -> V_39 = V_55 ;
V_1 -> V_31 = 0L ;
V_1 -> V_13 = 0L ;
V_1 -> V_32 = 0L ;
V_1 -> V_21 = 0L ;
return;
}
V_1 -> V_33 = V_54 ;
F_3 ( V_1 ) ;
}
