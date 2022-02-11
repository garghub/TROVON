static void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
struct V_3 * V_4 =
F_3 ( V_2 , struct V_3 , V_5 . V_2 ) ;
struct V_6 * V_6 = V_4 -> V_5 . V_6 ;
struct V_7 * V_8 ;
int V_9 ;
F_4 (bv, bio, i) {
struct V_10 * V_10 = V_8 -> V_11 ;
int V_12 = F_5 ( V_4 , V_10 ) ;
if ( V_12 ) {
F_6 ( 1 ) ;
F_7 ( V_10 ) ;
} else
F_8 ( V_10 ) ;
F_9 ( V_10 ) ;
}
F_10 ( V_4 ) ;
F_11 ( V_6 ) ;
#else
F_12 () ;
#endif
}
static inline bool F_13 ( struct V_6 * V_6 )
{
#ifdef F_2
return F_14 ( V_6 -> V_13 != NULL ) ;
#else
return false ;
#endif
}
static void F_15 ( struct V_6 * V_6 , int V_14 )
{
struct V_7 * V_8 ;
int V_9 ;
if ( F_13 ( V_6 ) ) {
struct V_3 * V_4 = V_6 -> V_13 ;
if ( V_14 ) {
F_10 ( V_4 ) ;
} else {
F_16 ( & V_4 -> V_5 . V_2 , F_1 ) ;
V_4 -> V_5 . V_6 = V_6 ;
F_17 ( V_15 , & V_4 -> V_5 . V_2 ) ;
return;
}
}
F_4 (bv, bio, i) {
struct V_10 * V_10 = V_8 -> V_11 ;
if ( ! V_14 ) {
F_8 ( V_10 ) ;
} else {
F_18 ( V_10 ) ;
F_7 ( V_10 ) ;
}
F_9 ( V_10 ) ;
}
F_11 ( V_6 ) ;
}
int F_19 ( struct V_16 * V_17 ,
struct V_18 * V_19 , struct V_10 * V_10 ,
unsigned V_20 )
{
struct V_6 * V_6 = NULL ;
unsigned V_21 ;
T_1 V_22 = 0 ;
struct V_23 * V_23 = V_17 -> V_24 ;
const unsigned V_25 = V_23 -> V_26 ;
const unsigned V_27 = V_28 >> V_25 ;
const unsigned V_29 = 1 << V_25 ;
T_1 V_30 ;
T_1 V_31 ;
T_1 V_32 ;
T_1 V_33 [ V_34 ] ;
unsigned V_35 ;
struct V_36 * V_37 = V_23 -> V_38 -> V_39 ;
int V_40 ;
unsigned V_41 = 0 ;
struct V_42 V_43 ;
V_43 . V_44 = 0 ;
V_43 . V_45 = 0 ;
V_43 . V_46 = 0 ;
V_43 . V_47 = 0 ;
for ( V_21 = 0 ; V_20 ; V_21 ++ , V_20 -- ) {
int V_48 = 1 ;
unsigned V_49 = V_27 ;
F_20 ( & V_10 -> V_50 ) ;
if ( V_19 ) {
V_10 = F_21 ( V_19 -> V_51 , struct V_10 , V_52 ) ;
F_22 ( & V_10 -> V_52 ) ;
if ( F_23 ( V_10 , V_17 ,
V_10 -> V_53 , V_54 ) )
goto V_55;
}
if ( F_24 ( V_10 ) )
goto V_56;
V_30 = ( T_1 ) V_10 -> V_53 << ( V_57 - V_25 ) ;
V_31 = V_30 + V_20 * V_27 ;
V_32 = ( F_25 ( V_23 ) + V_29 - 1 ) >> V_25 ;
if ( V_31 > V_32 )
V_31 = V_32 ;
V_35 = 0 ;
if ( ( V_43 . V_47 & V_58 ) &&
V_30 > V_43 . V_45 &&
V_30 < ( V_43 . V_45 + V_43 . V_46 ) ) {
unsigned V_59 = V_30 - V_43 . V_45 ;
unsigned V_60 = V_43 . V_46 - V_59 ;
for ( V_41 = 0 ; ; V_41 ++ ) {
if ( V_41 == V_60 ) {
V_43 . V_47 &= ~ V_58 ;
break;
}
if ( V_35 == V_27 )
break;
V_33 [ V_35 ] = V_43 . V_44 + V_59 +
V_41 ;
V_35 ++ ;
V_30 ++ ;
}
}
while ( V_35 < V_27 ) {
if ( V_30 < V_31 ) {
V_43 . V_45 = V_30 ;
V_43 . V_46 = V_31 - V_30 ;
if ( V_42 ( NULL , V_23 , & V_43 , 0 ) < 0 ) {
V_61:
F_7 ( V_10 ) ;
F_26 ( V_10 , 0 ,
V_28 ) ;
F_9 ( V_10 ) ;
goto V_55;
}
}
if ( ( V_43 . V_47 & V_58 ) == 0 ) {
V_48 = 0 ;
if ( V_49 == V_27 )
V_49 = V_35 ;
V_35 ++ ;
V_30 ++ ;
continue;
}
if ( V_49 != V_27 )
goto V_56;
if ( V_35 && V_33 [ V_35 - 1 ] != V_43 . V_44 - 1 )
goto V_56;
for ( V_41 = 0 ; ; V_41 ++ ) {
if ( V_41 == V_43 . V_46 ) {
V_43 . V_47 &= ~ V_58 ;
break;
} else if ( V_35 == V_27 )
break;
V_33 [ V_35 ] = V_43 . V_44 + V_41 ;
V_35 ++ ;
V_30 ++ ;
}
}
if ( V_49 != V_27 ) {
F_26 ( V_10 , V_49 << V_25 ,
V_28 ) ;
if ( V_49 == 0 ) {
F_8 ( V_10 ) ;
F_9 ( V_10 ) ;
goto V_55;
}
} else if ( V_48 ) {
F_27 ( V_10 ) ;
}
if ( V_48 && V_27 == 1 &&
! F_28 ( V_10 ) && F_29 ( V_10 ) == 0 ) {
F_8 ( V_10 ) ;
goto V_56;
}
if ( V_6 && ( V_22 != V_33 [ 0 ] - 1 ) ) {
V_62:
F_30 ( V_63 , V_6 ) ;
V_6 = NULL ;
}
if ( V_6 == NULL ) {
struct V_3 * V_4 = NULL ;
if ( F_31 ( V_23 ) &&
F_32 ( V_23 -> V_64 ) ) {
V_4 = F_33 ( V_23 ) ;
if ( F_34 ( V_4 ) )
goto V_61;
}
V_6 = F_35 ( V_54 ,
F_36 ( int , V_20 , F_37 ( V_37 ) ) ) ;
if ( ! V_6 ) {
if ( V_4 )
F_10 ( V_4 ) ;
goto V_61;
}
V_6 -> V_65 = V_37 ;
V_6 -> V_66 . V_67 = V_33 [ 0 ] << ( V_25 - 9 ) ;
V_6 -> V_68 = F_15 ;
V_6 -> V_13 = V_4 ;
}
V_40 = V_49 << V_25 ;
if ( F_38 ( V_6 , V_10 , V_40 , 0 ) < V_40 )
goto V_62;
if ( ( ( V_43 . V_47 & V_69 ) &&
( V_41 == V_43 . V_46 ) ) ||
( V_49 != V_27 ) ) {
F_30 ( V_63 , V_6 ) ;
V_6 = NULL ;
} else
V_22 = V_33 [ V_27 - 1 ] ;
goto V_55;
V_56:
if ( V_6 ) {
F_30 ( V_63 , V_6 ) ;
V_6 = NULL ;
}
if ( ! F_28 ( V_10 ) )
F_39 ( V_10 , V_70 ) ;
else
F_9 ( V_10 ) ;
V_55:
if ( V_19 )
F_40 ( V_10 ) ;
}
F_41 ( V_19 && ! F_42 ( V_19 ) ) ;
if ( V_6 )
F_30 ( V_63 , V_6 ) ;
return 0 ;
}
