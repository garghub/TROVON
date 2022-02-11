static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
int V_4 ;
V_4 = V_2 -> V_5 -> V_6 -> V_7 [ V_3 ] *
V_8 / V_9 ;
if ( V_4 < 0 )
V_4 = 0 ;
else if ( V_4 > V_9 )
V_4 = V_9 ;
if ( V_2 -> V_10 )
V_4 = V_9 - V_4 ;
return V_4 ;
}
static int F_2 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_3 ( V_12 ) ;
struct V_13 * V_5 = V_2 -> V_5 ;
T_1 V_14 , V_15 ;
int V_3 ;
if ( V_5 -> V_16 != V_17 )
return 0 ;
if ( V_12 -> V_18 . V_19 != V_20 ||
V_12 -> V_18 . V_21 != V_20 )
V_3 = 0 ;
else
V_3 = V_12 -> V_18 . V_22 ;
F_4 ( & V_5 -> V_23 ) ;
F_5 () ;
V_14 = F_6 ( V_24 ) ;
if ( V_3 > 0 ) {
V_14 &= ~ V_25 ;
if ( ! ( V_14 & V_26 ) || ! ( V_14 & V_27 ) ) {
V_14 |= ( V_5 -> V_28 . V_14 & V_29 ) ;
V_14 |= V_26 | V_30 ;
F_7 ( V_24 , V_14 ) ;
V_14 &= ~ V_31 ;
V_14 |=
( F_1 ( V_2 , V_3 ) <<
V_32 ) ;
V_14 |= V_27 ;
V_14 |= ( V_5 -> V_28 . V_14 & V_33 ) ;
V_5 -> V_34 = V_14 ;
F_8 ( & V_5 -> V_23 ,
V_35 + F_9 ( V_5 -> V_36 . V_37 ) ) ;
} else {
V_14 &= ~ V_31 ;
V_14 |=
( F_1 ( V_2 , V_3 ) <<
V_32 ) ;
F_7 ( V_24 , V_14 ) ;
}
V_5 -> V_28 . V_14 &= ~ V_38 ;
V_5 -> V_28 . V_14 |= V_5 -> V_34
& V_38 ;
} else {
V_15 = F_10 ( V_39 ) ;
if ( V_5 -> V_40 || V_5 -> V_41 )
F_11 ( V_39 , 0 , ~ V_42 ) ;
V_14 &= ~ ( V_31 | V_33 ) ;
V_14 |= ( F_1 ( V_2 , 0 ) <<
V_32 ) ;
V_14 |= V_25 ;
F_7 ( V_24 , V_14 ) ;
F_12 ( 100 ) ;
V_14 &= ~ ( V_27 | V_30 ) ;
F_7 ( V_24 , V_14 ) ;
V_14 &= ~ ( V_29 ) ;
V_5 -> V_34 = V_14 ;
F_8 ( & V_5 -> V_23 ,
V_35 + F_9 ( V_5 -> V_36 . V_37 ) ) ;
if ( V_5 -> V_40 || V_5 -> V_41 )
F_13 ( V_39 , V_15 ) ;
}
V_5 -> V_28 . V_14 &= ~ V_38 ;
V_5 -> V_28 . V_14 |= ( V_14 & V_38 ) ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 )
{
return V_12 -> V_18 . V_22 ;
}
void F_15 ( struct V_13 * V_5 )
{
struct V_43 V_18 ;
struct V_11 * V_12 ;
struct V_1 * V_2 ;
char V_44 [ 12 ] ;
if ( V_5 -> V_16 != V_17 )
return;
#ifdef F_16
if ( ! F_17 ( L_1 ) &&
! F_17 ( L_2 ) )
return;
#endif
V_2 = F_18 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_2 ) {
F_19 ( L_3 ) ;
goto error;
}
snprintf ( V_44 , sizeof( V_44 ) , L_4 , V_5 -> V_6 -> V_46 ) ;
memset ( & V_18 , 0 , sizeof( struct V_43 ) ) ;
V_18 . type = V_47 ;
V_18 . V_48 = V_49 - 1 ;
V_12 = F_20 ( V_44 , V_5 -> V_6 -> V_50 , V_2 ,
& V_51 , & V_18 ) ;
if ( F_21 ( V_12 ) ) {
V_5 -> V_6 -> V_52 = NULL ;
F_19 ( L_5 ) ;
goto error;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_10 =
( V_5 -> V_53 != V_54 &&
V_5 -> V_53 != V_55 &&
V_5 -> V_53 != V_56 &&
V_5 -> V_53 != V_57 ) ;
#ifdef F_16
V_2 -> V_10 = V_2 -> V_10 ||
F_22 ( L_6 ) ||
F_22 ( L_7 ) ||
F_22 ( L_8 ) ;
#endif
V_5 -> V_6 -> V_52 = V_12 ;
F_23 ( V_5 -> V_6 , 0 ,
63 * V_8 / V_9 ,
217 * V_8 / V_9 ) ;
V_12 -> V_18 . V_22 = V_12 -> V_18 . V_48 ;
V_12 -> V_18 . V_19 = V_20 ;
F_24 ( V_12 ) ;
F_19 ( L_9 , V_44 ) ;
return;
error:
F_25 ( V_2 ) ;
return;
}
void F_26 ( struct V_13 * V_5 )
{
struct V_11 * V_12 = V_5 -> V_6 -> V_52 ;
if ( V_12 ) {
struct V_1 * V_2 ;
V_2 = F_3 ( V_12 ) ;
F_27 ( V_12 ) ;
F_25 ( V_2 ) ;
V_5 -> V_6 -> V_52 = NULL ;
F_19 ( L_10 ) ;
}
}
