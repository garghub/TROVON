static void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
struct V_3 * V_4 =
F_3 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
struct V_6 * V_7 ;
int V_8 ;
F_4 (bv, bio, i) {
struct V_9 * V_9 = V_7 -> V_10 ;
int V_11 = F_5 ( V_4 , V_9 ) ;
if ( V_11 ) {
F_6 ( 1 ) ;
F_7 ( V_9 ) ;
} else
F_8 ( V_9 ) ;
F_9 ( V_9 ) ;
}
F_10 ( V_4 ) ;
F_11 ( V_5 ) ;
#else
F_12 () ;
#endif
}
static inline bool F_13 ( struct V_5 * V_5 )
{
#ifdef F_2
return F_14 ( V_5 -> V_12 != NULL ) ;
#else
return false ;
#endif
}
static void F_15 ( struct V_5 * V_5 , int V_13 )
{
struct V_6 * V_7 ;
int V_8 ;
if ( F_13 ( V_5 ) ) {
struct V_3 * V_4 = V_5 -> V_12 ;
if ( V_13 ) {
F_10 ( V_4 ) ;
} else {
F_16 ( & V_4 -> V_2 , F_1 ) ;
V_4 -> V_5 = V_5 ;
F_17 ( V_14 , & V_4 -> V_2 ) ;
return;
}
}
F_4 (bv, bio, i) {
struct V_9 * V_9 = V_7 -> V_10 ;
if ( ! V_13 ) {
F_8 ( V_9 ) ;
} else {
F_18 ( V_9 ) ;
F_7 ( V_9 ) ;
}
F_9 ( V_9 ) ;
}
F_11 ( V_5 ) ;
}
int F_19 ( struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_9 * V_9 ,
unsigned V_19 )
{
struct V_5 * V_5 = NULL ;
unsigned V_20 ;
T_1 V_21 = 0 ;
struct V_22 * V_22 = V_16 -> V_23 ;
const unsigned V_24 = V_22 -> V_25 ;
const unsigned V_26 = V_27 >> V_24 ;
const unsigned V_28 = 1 << V_24 ;
T_1 V_29 ;
T_1 V_30 ;
T_1 V_31 ;
T_1 V_32 [ V_33 ] ;
unsigned V_34 ;
struct V_35 * V_36 = V_22 -> V_37 -> V_38 ;
int V_39 ;
unsigned V_40 = 0 ;
struct V_41 V_42 ;
V_42 . V_43 = 0 ;
V_42 . V_44 = 0 ;
V_42 . V_45 = 0 ;
V_42 . V_46 = 0 ;
for ( V_20 = 0 ; V_19 ; V_20 ++ , V_19 -- ) {
int V_47 = 1 ;
unsigned V_48 = V_26 ;
F_20 ( & V_9 -> V_49 ) ;
if ( V_18 ) {
V_9 = F_21 ( V_18 -> V_50 , struct V_9 , V_51 ) ;
F_22 ( & V_9 -> V_51 ) ;
if ( F_23 ( V_9 , V_16 ,
V_9 -> V_52 , V_53 ) )
goto V_54;
}
if ( F_24 ( V_9 ) )
goto V_55;
V_29 = ( T_1 ) V_9 -> V_52 << ( V_56 - V_24 ) ;
V_30 = V_29 + V_19 * V_26 ;
V_31 = ( F_25 ( V_22 ) + V_28 - 1 ) >> V_24 ;
if ( V_30 > V_31 )
V_30 = V_31 ;
V_34 = 0 ;
if ( ( V_42 . V_46 & V_57 ) &&
V_29 > V_42 . V_44 &&
V_29 < ( V_42 . V_44 + V_42 . V_45 ) ) {
unsigned V_58 = V_29 - V_42 . V_44 ;
unsigned V_59 = V_42 . V_45 - V_58 ;
for ( V_40 = 0 ; ; V_40 ++ ) {
if ( V_40 == V_59 ) {
V_42 . V_46 &= ~ V_57 ;
break;
}
if ( V_34 == V_26 )
break;
V_32 [ V_34 ] = V_42 . V_43 + V_58 +
V_40 ;
V_34 ++ ;
V_29 ++ ;
}
}
while ( V_34 < V_26 ) {
if ( V_29 < V_30 ) {
V_42 . V_44 = V_29 ;
V_42 . V_45 = V_30 - V_29 ;
if ( V_41 ( NULL , V_22 , & V_42 , 0 ) < 0 ) {
V_60:
F_7 ( V_9 ) ;
F_26 ( V_9 , 0 ,
V_27 ) ;
F_9 ( V_9 ) ;
goto V_54;
}
}
if ( ( V_42 . V_46 & V_57 ) == 0 ) {
V_47 = 0 ;
if ( V_48 == V_26 )
V_48 = V_34 ;
V_34 ++ ;
V_29 ++ ;
continue;
}
if ( V_48 != V_26 )
goto V_55;
if ( V_34 && V_32 [ V_34 - 1 ] != V_42 . V_43 - 1 )
goto V_55;
for ( V_40 = 0 ; ; V_40 ++ ) {
if ( V_40 == V_42 . V_45 ) {
V_42 . V_46 &= ~ V_57 ;
break;
} else if ( V_34 == V_26 )
break;
V_32 [ V_34 ] = V_42 . V_43 + V_40 ;
V_34 ++ ;
V_29 ++ ;
}
}
if ( V_48 != V_26 ) {
F_26 ( V_9 , V_48 << V_24 ,
V_27 ) ;
if ( V_48 == 0 ) {
F_8 ( V_9 ) ;
F_9 ( V_9 ) ;
goto V_54;
}
} else if ( V_47 ) {
F_27 ( V_9 ) ;
}
if ( V_47 && V_26 == 1 &&
! F_28 ( V_9 ) && F_29 ( V_9 ) == 0 ) {
F_8 ( V_9 ) ;
goto V_55;
}
if ( V_5 && ( V_21 != V_32 [ 0 ] - 1 ) ) {
V_61:
F_30 ( V_62 , V_5 ) ;
V_5 = NULL ;
}
if ( V_5 == NULL ) {
struct V_3 * V_4 = NULL ;
if ( F_31 ( V_22 ) &&
F_32 ( V_22 -> V_63 ) ) {
V_4 = F_33 ( V_22 ) ;
if ( F_34 ( V_4 ) )
goto V_60;
}
V_5 = F_35 ( V_53 ,
F_36 ( int , V_19 , F_37 ( V_36 ) ) ) ;
if ( ! V_5 ) {
if ( V_4 )
F_10 ( V_4 ) ;
goto V_60;
}
V_5 -> V_64 = V_36 ;
V_5 -> V_65 . V_66 = V_32 [ 0 ] << ( V_24 - 9 ) ;
V_5 -> V_67 = F_15 ;
V_5 -> V_12 = V_4 ;
}
V_39 = V_48 << V_24 ;
if ( F_38 ( V_5 , V_9 , V_39 , 0 ) < V_39 )
goto V_61;
if ( ( ( V_42 . V_46 & V_68 ) &&
( V_40 == V_42 . V_45 ) ) ||
( V_48 != V_26 ) ) {
F_30 ( V_62 , V_5 ) ;
V_5 = NULL ;
} else
V_21 = V_32 [ V_26 - 1 ] ;
goto V_54;
V_55:
if ( V_5 ) {
F_30 ( V_62 , V_5 ) ;
V_5 = NULL ;
}
if ( ! F_28 ( V_9 ) )
F_39 ( V_9 , V_69 ) ;
else
F_9 ( V_9 ) ;
V_54:
if ( V_18 )
F_40 ( V_9 ) ;
}
F_41 ( V_18 && ! F_42 ( V_18 ) ) ;
if ( V_5 )
F_30 ( V_62 , V_5 ) ;
return 0 ;
}
