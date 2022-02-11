static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
break;
return V_3 ;
}
static void F_3 ( struct V_1 * V_2 , int * V_5 , T_1 V_6 [] )
{
int V_3 , V_7 ;
for ( V_3 = 0 , V_7 = 0 ; V_3 < 16 ; V_3 ++ )
if ( F_4 ( V_3 , & V_2 -> V_4 ) )
V_6 [ V_7 ++ ] = V_2 -> V_8 [ V_3 ] ;
* V_5 = V_7 ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_3 )
{
F_6 ( V_3 , & V_2 -> V_4 ) ;
}
int F_7 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 -> V_12 ;
int V_5 , V_13 , V_14 ;
T_1 V_15 [ 16 ] ;
switch ( V_10 -> type ) {
case V_16 :
case V_17 :
break;
default:
F_8 ( V_2 -> V_18 , L_1 ,
V_10 -> type ) ;
return - V_19 ;
}
if ( F_9 ( & V_2 -> V_20 ) )
return - V_21 ;
if ( V_10 -> type == V_16 ) {
switch ( V_10 -> V_22 ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_13 = F_1 ( V_2 ) ;
break;
default:
F_8 ( V_2 -> V_18 ,
L_2 ,
V_10 -> V_22 ) ;
V_14 = - V_19 ;
goto V_28;
}
} else {
V_13 = F_1 ( V_2 ) ;
}
if ( V_13 > 15 ) {
F_8 ( V_2 -> V_18 , L_3 ) ;
V_14 = - V_29 ;
goto V_28;
}
V_10 -> V_12 = ( F_10 ( V_10 -> V_12 ) ) ( unsigned long ) V_13 ;
V_2 -> V_8 [ V_13 ] = V_10 -> V_6 ;
F_3 ( V_2 , & V_5 , V_15 ) ;
if ( V_10 -> V_6 == 8192 ) {
V_14 = F_11 ( V_2 ) ;
if ( V_14 ) {
F_5 ( V_2 , V_13 ) ;
F_8 ( V_2 -> V_18 , L_4 ) ;
goto V_28;
}
} else {
V_14 = F_12 ( V_2 , V_5 , V_15 ) ;
if ( V_14 ) {
F_5 ( V_2 , V_13 ) ;
F_8 ( V_2 -> V_18 , L_5 ) ;
goto V_28;
}
}
V_28:
F_13 ( & V_2 -> V_20 ) ;
return V_14 ;
}
int F_14 ( struct V_9 * V_10 )
{
struct V_30 * V_11 = V_10 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_12 ;
int V_5 , V_13 , V_14 ;
T_1 V_15 [ 16 ] ;
if ( V_10 -> type == V_16 &&
! ( ( V_10 -> V_31 & V_32 ) &&
( V_11 -> V_33 . V_34 -> V_35 != V_36 ) ) ) {
if ( V_10 -> V_31 & V_37 ) {
if ( V_10 -> V_22 >= V_27 ||
! V_11 -> V_38 [ V_10 -> V_22 ] )
return - V_19 ;
V_11 -> V_15 [ V_10 -> V_22 ] |= 0x8000 ;
V_11 -> V_38 [ V_10 -> V_22 ] = NULL ;
}
if ( ! ( V_10 -> V_31 & V_37 &&
V_10 -> V_22 < V_27 ) )
return 0 ;
}
if ( F_9 ( & V_2 -> V_20 ) )
return - V_21 ;
V_13 = ( unsigned long ) V_10 -> V_12 ;
F_5 ( V_2 , V_13 ) ;
F_3 ( V_2 , & V_5 , V_15 ) ;
V_14 = F_12 ( V_2 , V_5 , V_15 ) ;
F_13 ( & V_2 -> V_20 ) ;
return V_14 ;
}
int F_15 ( struct V_1 * V_2 , const char * V_39 )
{
int V_40 ;
V_40 = F_16 ( & V_2 -> V_41 , V_39 ,
V_42 , V_2 -> V_18 , V_43 ) ;
if ( V_40 < 0 )
goto V_44;
V_2 -> V_11 . V_33 . V_45 = 0 ;
V_2 -> V_11 . V_12 = V_2 ;
V_2 -> V_11 . V_46 = 16 ;
V_2 -> V_11 . V_47 = 16 ;
V_2 -> V_11 . V_48 = F_7 ;
V_2 -> V_11 . V_49 = F_14 ;
V_2 -> V_11 . V_50 = NULL ;
V_40 = F_17 ( & V_2 -> V_11 ) ;
if ( V_40 )
goto V_51;
V_2 -> V_52 . V_46 = 16 ;
V_2 -> V_52 . V_11 = & V_2 -> V_11 . V_33 ;
V_2 -> V_52 . V_45 = 0 ;
V_40 = F_18 ( & V_2 -> V_52 , & V_2 -> V_41 ) ;
if ( V_40 )
goto V_53;
V_2 -> V_34 . V_35 = V_54 ;
V_40 = V_2 -> V_11 . V_33 . V_55 ( & V_2 -> V_11 . V_33 , & V_2 -> V_34 ) ;
if ( V_40 )
goto V_56;
V_40 = V_2 -> V_11 . V_33 . V_57 ( & V_2 -> V_11 . V_33 ,
& V_2 -> V_34 ) ;
if ( V_40 )
goto V_58;
V_40 = F_19 ( & V_2 -> V_41 , & V_2 -> V_59 , & V_2 -> V_11 . V_33 ) ;
if ( V_40 )
goto V_60;
F_20 ( V_2 , V_39 ) ;
V_40 = F_21 ( & V_2 -> V_41 , & V_2 -> V_61 ) ;
if ( V_40 )
goto V_62;
V_40 = F_22 ( V_2 ) ;
if ( V_40 )
F_23 ( V_2 -> V_18 ,
L_6 ) ;
return 0 ;
V_62:
F_24 ( & V_2 -> V_59 ) ;
V_60:
V_2 -> V_11 . V_33 . V_63 ( & V_2 -> V_11 . V_33 ) ;
V_58:
V_2 -> V_11 . V_33 . V_64 ( & V_2 -> V_11 . V_33 , & V_2 -> V_34 ) ;
V_56:
F_25 ( & V_2 -> V_52 ) ;
V_53:
F_26 ( & V_2 -> V_11 ) ;
V_51:
F_27 ( & V_2 -> V_41 ) ;
V_44:
F_8 ( V_2 -> V_18 , L_7 ) ;
return V_40 ;
}
void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
F_30 ( & V_2 -> V_61 ) ;
F_24 ( & V_2 -> V_59 ) ;
V_2 -> V_11 . V_33 . V_63 ( & V_2 -> V_11 . V_33 ) ;
V_2 -> V_11 . V_33 . V_64 ( & V_2 -> V_11 . V_33 , & V_2 -> V_34 ) ;
F_25 ( & V_2 -> V_52 ) ;
F_26 ( & V_2 -> V_11 ) ;
F_27 ( & V_2 -> V_41 ) ;
}
