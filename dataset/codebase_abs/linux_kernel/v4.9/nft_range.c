static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 , V_10 ;
V_9 = memcmp ( & V_4 -> V_11 [ V_8 -> V_12 ] , & V_8 -> V_13 , V_8 -> V_14 ) ;
V_10 = memcmp ( & V_4 -> V_11 [ V_8 -> V_12 ] , & V_8 -> V_15 , V_8 -> V_14 ) ;
switch ( V_8 -> V_16 ) {
case V_17 :
if ( V_9 < 0 || V_10 > 0 )
V_4 -> V_18 . V_19 = V_20 ;
break;
case V_21 :
if ( V_9 >= 0 && V_10 <= 0 )
V_4 -> V_18 . V_19 = V_20 ;
break;
}
}
static int F_3 ( const struct V_22 * V_23 , const struct V_1 * V_2 ,
const struct V_24 * const V_25 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_26 V_27 , V_28 ;
int V_29 ;
T_1 V_16 ;
if ( ! V_25 [ V_30 ] ||
! V_25 [ V_31 ] ||
! V_25 [ V_32 ] ||
! V_25 [ V_33 ] )
return - V_34 ;
V_29 = F_4 ( NULL , & V_8 -> V_13 , sizeof( V_8 -> V_13 ) ,
& V_27 , V_25 [ V_32 ] ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_4 ( NULL , & V_8 -> V_15 , sizeof( V_8 -> V_15 ) ,
& V_28 , V_25 [ V_33 ] ) ;
if ( V_29 < 0 )
goto V_35;
if ( V_27 . V_14 != V_28 . V_14 ) {
V_29 = - V_34 ;
goto V_36;
}
V_8 -> V_12 = F_5 ( V_25 [ V_30 ] ) ;
V_29 = F_6 ( V_8 -> V_12 , V_27 . V_14 ) ;
if ( V_29 < 0 )
goto V_36;
V_29 = F_7 ( V_25 [ V_31 ] , V_37 , & V_16 ) ;
if ( V_29 < 0 )
goto V_36;
switch ( V_16 ) {
case V_17 :
case V_21 :
break;
default:
V_29 = - V_34 ;
goto V_36;
}
V_8 -> V_16 = V_16 ;
V_8 -> V_14 = V_27 . V_14 ;
return 0 ;
V_36:
F_8 ( & V_8 -> V_15 , V_28 . type ) ;
V_35:
F_8 ( & V_8 -> V_13 , V_27 . type ) ;
return V_29 ;
}
static int F_9 ( struct V_38 * V_39 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_10 ( V_39 , V_30 , V_8 -> V_12 ) )
goto V_40;
if ( F_11 ( V_39 , V_31 , F_12 ( V_8 -> V_16 ) ) )
goto V_40;
if ( F_13 ( V_39 , V_32 , & V_8 -> V_13 ,
V_41 , V_8 -> V_14 ) < 0 ||
F_13 ( V_39 , V_33 , & V_8 -> V_15 ,
V_41 , V_8 -> V_14 ) < 0 )
goto V_40;
return 0 ;
V_40:
return - 1 ;
}
int T_2 F_14 ( void )
{
return F_15 ( & V_42 ) ;
}
void F_16 ( void )
{
F_17 ( & V_42 ) ;
}
