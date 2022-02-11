static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_3 ( V_6 , V_9 ) ;
switch ( V_4 ) {
case V_10 :
F_4 ( V_8 , V_11 ) ;
V_6 -> V_12 = & V_6 -> V_13 [ V_14 ] ;
break;
case V_15 :
F_4 ( V_8 , V_16 ) ;
V_6 -> V_12 = & V_6 -> V_13 [ V_17 ] ;
break;
case V_18 :
F_4 ( V_8 , V_19 ) ;
V_6 -> V_12 = & V_6 -> V_13 [ V_20 ] ;
break;
default:
return - V_21 ;
}
V_8 -> V_22 . V_23 . V_24 = V_25 ;
memcpy ( V_8 -> V_22 . V_26 . V_27 , V_3 , V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_30 * V_32 ,
unsigned int V_33 ,
int V_34 )
{
struct V_5 * V_6 = F_6 ( V_29 -> V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned long V_35 ;
unsigned int V_36 = 0 , V_37 ;
T_2 V_38 ;
int V_39 ;
F_7 ( & V_6 -> V_40 , V_35 ) ;
V_38 = F_8 ( T_2 , V_41 . V_42 . V_38 / sizeof( struct V_43 ) ,
V_6 -> V_12 -> V_44 ) ;
if ( V_34 )
F_9 ( V_8 ) |= V_45 ;
else
F_9 ( V_8 ) &= ~ V_45 ;
do {
V_37 = F_8 ( V_46 , V_33 - V_36 ,
V_6 -> V_12 -> V_47 ) ;
V_37 = F_8 ( V_46 , V_37 ,
V_48 * ( V_38 - 1 ) ) ;
V_37 = V_37 & ~ ( V_49 - 1 ) ;
V_39 = F_10 ( V_6 , V_29 , V_31 , V_32 , V_37 ,
V_36 , V_8 -> V_22 . V_26 . V_50 ) ;
if ( V_39 )
goto V_51;
if ( ! V_6 -> V_52 . V_53 || ! V_6 -> V_52 . V_54 ) {
V_39 = - V_21 ;
goto V_51;
}
V_39 = F_11 ( V_6 , & V_6 -> V_52 ,
V_29 -> V_55 & V_56 ) ;
if ( V_39 )
goto V_51;
memcpy ( V_29 -> V_57 , V_8 -> V_22 . V_26 . V_58 , V_49 ) ;
F_12 ( & ( V_6 -> V_59 -> V_60 ) ) ;
F_13 ( V_8 -> V_61 . V_62 ,
& ( V_6 -> V_59 -> V_63 ) ) ;
V_36 += V_37 ;
} while ( V_36 < V_33 );
V_51:
F_14 ( & V_6 -> V_40 , V_35 ) ;
return V_39 ;
}
static int F_15 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_30 * V_32 ,
unsigned int V_33 )
{
return F_5 ( V_29 , V_31 , V_32 , V_33 , 1 ) ;
}
static int F_16 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_30 * V_32 ,
unsigned int V_33 )
{
return F_5 ( V_29 , V_31 , V_32 , V_33 , 0 ) ;
}
