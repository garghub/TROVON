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
static int F_5 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_4 < V_28 )
return - V_21 ;
memcpy ( V_6 -> V_29 . V_30 . V_31 ,
V_3 + V_4 - V_28 ,
V_28 ) ;
V_4 -= V_28 ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static int F_6 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_34 * V_36 ,
unsigned int V_37 )
{
struct V_5 * V_6 = F_7 ( V_33 -> V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned long V_38 ;
unsigned int V_39 = 0 , V_40 ;
int V_41 ;
F_8 ( & V_6 -> V_42 , V_38 ) ;
do {
V_40 = V_37 - V_39 ;
V_41 = F_9 ( V_6 , V_33 , V_35 , V_36 , & V_40 ,
V_39 , V_8 -> V_22 . V_26 . V_43 ) ;
if ( V_41 )
goto V_44;
if ( ! V_6 -> V_45 . V_46 || ! V_6 -> V_45 . V_47 ) {
V_41 = - V_21 ;
goto V_44;
}
V_41 = F_10 ( V_6 , & V_6 -> V_45 ,
V_33 -> V_48 & V_49 ) ;
if ( V_41 )
goto V_44;
memcpy ( V_33 -> V_50 , V_8 -> V_22 . V_51 . V_52 , V_53 ) ;
F_11 ( & ( V_6 -> V_54 -> V_55 ) ) ;
F_12 ( V_8 -> V_56 . V_57 ,
& ( V_6 -> V_54 -> V_58 ) ) ;
V_39 += V_40 ;
} while ( V_39 < V_37 );
V_44:
F_13 ( & V_6 -> V_42 , V_38 ) ;
return V_41 ;
}
static int F_14 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_34 * V_36 ,
unsigned int V_37 )
{
struct V_5 * V_6 = F_7 ( V_33 -> V_2 ) ;
T_1 V_43 [ 16 ] ;
memcpy ( V_43 , V_6 -> V_29 . V_30 . V_31 , V_59 ) ;
memcpy ( V_43 + V_28 ,
V_33 -> V_50 , V_59 ) ;
V_43 [ 12 ] = V_43 [ 13 ] = V_43 [ 14 ] = 0 ;
V_43 [ 15 ] = 1 ;
V_33 -> V_50 = V_43 ;
return F_6 ( V_33 , V_35 , V_36 , V_37 ) ;
}
