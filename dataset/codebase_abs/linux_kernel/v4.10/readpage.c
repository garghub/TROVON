static inline bool F_1 ( struct V_1 * V_1 )
{
#ifdef F_2
return F_3 ( V_1 -> V_2 != NULL ) ;
#else
return false ;
#endif
}
static void F_4 ( struct V_1 * V_1 )
{
struct V_3 * V_4 ;
int V_5 ;
if ( F_1 ( V_1 ) ) {
if ( V_1 -> V_6 ) {
F_5 ( V_1 -> V_2 ) ;
} else {
F_6 ( V_1 -> V_2 , V_1 ) ;
return;
}
}
F_7 (bv, bio, i) {
struct V_7 * V_7 = V_4 -> V_8 ;
if ( ! V_1 -> V_6 ) {
F_8 ( V_7 ) ;
} else {
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
}
F_11 ( V_7 ) ;
}
F_12 ( V_1 ) ;
}
int F_13 ( struct V_9 * V_10 ,
struct V_11 * V_12 , struct V_7 * V_7 ,
unsigned V_13 )
{
struct V_1 * V_1 = NULL ;
T_1 V_14 = 0 ;
struct V_15 * V_15 = V_10 -> V_16 ;
const unsigned V_17 = V_15 -> V_18 ;
const unsigned V_19 = V_20 >> V_17 ;
const unsigned V_21 = 1 << V_17 ;
T_1 V_22 ;
T_1 V_23 ;
T_1 V_24 ;
T_1 V_25 [ V_26 ] ;
unsigned V_27 ;
struct V_28 * V_29 = V_15 -> V_30 -> V_31 ;
int V_32 ;
unsigned V_33 = 0 ;
struct V_34 V_35 ;
V_35 . V_36 = 0 ;
V_35 . V_37 = 0 ;
V_35 . V_38 = 0 ;
V_35 . V_39 = 0 ;
for (; V_13 ; V_13 -- ) {
int V_40 = 1 ;
unsigned V_41 = V_19 ;
F_14 ( & V_7 -> V_42 ) ;
if ( V_12 ) {
V_7 = F_15 ( V_12 -> V_43 , struct V_7 , V_44 ) ;
F_16 ( & V_7 -> V_44 ) ;
if ( F_17 ( V_7 , V_10 , V_7 -> V_45 ,
F_18 ( V_10 ) ) )
goto V_46;
}
if ( F_19 ( V_7 ) )
goto V_47;
V_22 = ( T_1 ) V_7 -> V_45 << ( V_48 - V_17 ) ;
V_23 = V_22 + V_13 * V_19 ;
V_24 = ( F_20 ( V_15 ) + V_21 - 1 ) >> V_17 ;
if ( V_23 > V_24 )
V_23 = V_24 ;
V_27 = 0 ;
if ( ( V_35 . V_39 & V_49 ) &&
V_22 > V_35 . V_37 &&
V_22 < ( V_35 . V_37 + V_35 . V_38 ) ) {
unsigned V_50 = V_22 - V_35 . V_37 ;
unsigned V_51 = V_35 . V_38 - V_50 ;
for ( V_33 = 0 ; ; V_33 ++ ) {
if ( V_33 == V_51 ) {
V_35 . V_39 &= ~ V_49 ;
break;
}
if ( V_27 == V_19 )
break;
V_25 [ V_27 ] = V_35 . V_36 + V_50 +
V_33 ;
V_27 ++ ;
V_22 ++ ;
}
}
while ( V_27 < V_19 ) {
if ( V_22 < V_23 ) {
V_35 . V_37 = V_22 ;
V_35 . V_38 = V_23 - V_22 ;
if ( V_34 ( NULL , V_15 , & V_35 , 0 ) < 0 ) {
V_52:
F_10 ( V_7 ) ;
F_21 ( V_7 , 0 ,
V_20 ) ;
F_11 ( V_7 ) ;
goto V_46;
}
}
if ( ( V_35 . V_39 & V_49 ) == 0 ) {
V_40 = 0 ;
if ( V_41 == V_19 )
V_41 = V_27 ;
V_27 ++ ;
V_22 ++ ;
continue;
}
if ( V_41 != V_19 )
goto V_47;
if ( V_27 && V_25 [ V_27 - 1 ] != V_35 . V_36 - 1 )
goto V_47;
for ( V_33 = 0 ; ; V_33 ++ ) {
if ( V_33 == V_35 . V_38 ) {
V_35 . V_39 &= ~ V_49 ;
break;
} else if ( V_27 == V_19 )
break;
V_25 [ V_27 ] = V_35 . V_36 + V_33 ;
V_27 ++ ;
V_22 ++ ;
}
}
if ( V_41 != V_19 ) {
F_21 ( V_7 , V_41 << V_17 ,
V_20 ) ;
if ( V_41 == 0 ) {
F_8 ( V_7 ) ;
F_11 ( V_7 ) ;
goto V_46;
}
} else if ( V_40 ) {
F_22 ( V_7 ) ;
}
if ( V_40 && V_19 == 1 &&
! F_23 ( V_7 ) && F_24 ( V_7 ) == 0 ) {
F_8 ( V_7 ) ;
goto V_47;
}
if ( V_1 && ( V_14 != V_25 [ 0 ] - 1 ) ) {
V_53:
F_25 ( V_1 ) ;
V_1 = NULL ;
}
if ( V_1 == NULL ) {
struct V_54 * V_55 = NULL ;
if ( F_26 ( V_15 ) &&
F_27 ( V_15 -> V_56 ) ) {
V_55 = F_28 ( V_15 , V_57 ) ;
if ( F_29 ( V_55 ) )
goto V_52;
}
V_1 = F_30 ( V_58 ,
F_31 ( int , V_13 , V_59 ) ) ;
if ( ! V_1 ) {
if ( V_55 )
F_5 ( V_55 ) ;
goto V_52;
}
V_1 -> V_60 = V_29 ;
V_1 -> V_61 . V_62 = V_25 [ 0 ] << ( V_17 - 9 ) ;
V_1 -> V_63 = F_4 ;
V_1 -> V_2 = V_55 ;
F_32 ( V_1 , V_64 , 0 ) ;
}
V_32 = V_41 << V_17 ;
if ( F_33 ( V_1 , V_7 , V_32 , 0 ) < V_32 )
goto V_53;
if ( ( ( V_35 . V_39 & V_65 ) &&
( V_33 == V_35 . V_38 ) ) ||
( V_41 != V_19 ) ) {
F_25 ( V_1 ) ;
V_1 = NULL ;
} else
V_14 = V_25 [ V_19 - 1 ] ;
goto V_46;
V_47:
if ( V_1 ) {
F_25 ( V_1 ) ;
V_1 = NULL ;
}
if ( ! F_23 ( V_7 ) )
F_34 ( V_7 , V_66 ) ;
else
F_11 ( V_7 ) ;
V_46:
if ( V_12 )
F_35 ( V_7 ) ;
}
F_36 ( V_12 && ! F_37 ( V_12 ) ) ;
if ( V_1 )
F_25 ( V_1 ) ;
return 0 ;
}
