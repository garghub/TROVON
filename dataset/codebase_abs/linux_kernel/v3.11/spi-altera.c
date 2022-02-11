static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static void F_3 ( struct V_2 * V_5 , int V_6 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
if ( V_5 -> V_8 & V_9 ) {
switch ( V_6 ) {
case V_10 :
F_4 ( 1 << V_5 -> V_11 ,
V_7 -> V_12 + V_13 ) ;
V_7 -> V_14 |= V_15 ;
F_4 ( V_7 -> V_14 , V_7 -> V_12 + V_16 ) ;
break;
case V_17 :
V_7 -> V_14 &= ~ V_15 ;
F_4 ( V_7 -> V_14 , V_7 -> V_12 + V_16 ) ;
F_4 ( 0 , V_7 -> V_12 + V_13 ) ;
break;
}
} else {
switch ( V_6 ) {
case V_10 :
V_7 -> V_14 &= ~ V_15 ;
F_4 ( V_7 -> V_14 , V_7 -> V_12 + V_16 ) ;
break;
case V_17 :
F_4 ( 1 << V_5 -> V_11 ,
V_7 -> V_12 + V_13 ) ;
V_7 -> V_14 |= V_15 ;
F_4 ( V_7 -> V_14 , V_7 -> V_12 + V_16 ) ;
break;
}
}
}
static int F_5 ( struct V_2 * V_5 , struct V_18 * V_19 )
{
return 0 ;
}
static int F_6 ( struct V_2 * V_5 )
{
return 0 ;
}
static inline unsigned int F_7 ( struct V_1 * V_7 , int V_20 )
{
if ( V_7 -> V_21 ) {
switch ( V_7 -> V_22 ) {
case 1 :
return V_7 -> V_21 [ V_20 ] ;
case 2 :
return ( V_7 -> V_21 [ V_20 * 2 ]
| ( V_7 -> V_21 [ V_20 * 2 + 1 ] << 8 ) ) ;
}
}
return 0 ;
}
static int F_8 ( struct V_2 * V_5 , struct V_18 * V_19 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
V_7 -> V_21 = V_19 -> V_23 ;
V_7 -> V_24 = V_19 -> V_25 ;
V_7 -> V_20 = 0 ;
V_7 -> V_22 = V_19 -> V_26 / 8 ;
V_7 -> V_27 = V_19 -> V_27 / V_7 -> V_22 ;
if ( V_7 -> V_28 >= 0 ) {
V_7 -> V_14 |= V_29 ;
F_4 ( V_7 -> V_14 , V_7 -> V_12 + V_16 ) ;
F_4 ( F_7 ( V_7 , 0 ) , V_7 -> V_12 + V_30 ) ;
F_9 ( & V_7 -> V_31 ) ;
V_7 -> V_14 &= ~ V_29 ;
F_4 ( V_7 -> V_14 , V_7 -> V_12 + V_16 ) ;
} else {
F_4 ( F_7 ( V_7 , 0 ) , V_7 -> V_12 + V_30 ) ;
while ( 1 ) {
unsigned int V_32 ;
while ( ! ( F_10 ( V_7 -> V_12 + V_33 ) &
V_34 ) )
F_11 () ;
V_32 = F_10 ( V_7 -> V_12 + V_35 ) ;
if ( V_7 -> V_24 ) {
switch ( V_7 -> V_22 ) {
case 1 :
V_7 -> V_24 [ V_7 -> V_20 ] = V_32 ;
break;
case 2 :
V_7 -> V_24 [ V_7 -> V_20 * 2 ] = V_32 ;
V_7 -> V_24 [ V_7 -> V_20 * 2 + 1 ] = V_32 >> 8 ;
break;
}
}
V_7 -> V_20 ++ ;
if ( V_7 -> V_20 < V_7 -> V_27 )
F_4 ( F_7 ( V_7 , V_7 -> V_20 ) ,
V_7 -> V_12 + V_30 ) ;
else
break;
}
}
return V_7 -> V_20 * V_7 -> V_22 ;
}
static T_1 F_12 ( int V_28 , void * V_36 )
{
struct V_1 * V_7 = V_36 ;
unsigned int V_32 ;
V_32 = F_10 ( V_7 -> V_12 + V_35 ) ;
if ( V_7 -> V_24 ) {
switch ( V_7 -> V_22 ) {
case 1 :
V_7 -> V_24 [ V_7 -> V_20 ] = V_32 ;
break;
case 2 :
V_7 -> V_24 [ V_7 -> V_20 * 2 ] = V_32 ;
V_7 -> V_24 [ V_7 -> V_20 * 2 + 1 ] = V_32 >> 8 ;
break;
}
}
V_7 -> V_20 ++ ;
if ( V_7 -> V_20 < V_7 -> V_27 )
F_4 ( F_7 ( V_7 , V_7 -> V_20 ) , V_7 -> V_12 + V_30 ) ;
else
F_13 ( & V_7 -> V_31 ) ;
return V_37 ;
}
static int F_14 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = V_39 -> V_36 . V_42 ;
struct V_1 * V_7 ;
struct V_43 * V_4 ;
struct V_44 * V_45 ;
int V_46 = - V_47 ;
V_4 = F_15 ( & V_39 -> V_36 , sizeof( struct V_1 ) ) ;
if ( ! V_4 )
return V_46 ;
V_4 -> V_48 = V_39 -> V_49 ;
V_4 -> V_50 = 16 ;
V_4 -> V_51 = V_9 ;
V_4 -> V_52 = F_6 ;
V_7 = F_2 ( V_4 ) ;
F_16 ( V_39 , V_7 ) ;
V_7 -> V_53 . V_4 = F_17 ( V_4 ) ;
if ( ! V_7 -> V_53 . V_4 )
return V_46 ;
V_7 -> V_53 . V_54 = F_5 ;
V_7 -> V_53 . V_55 = F_3 ;
V_7 -> V_53 . V_56 = F_8 ;
V_45 = F_18 ( V_39 , V_57 , 0 ) ;
if ( ! V_45 )
goto V_58;
if ( ! F_19 ( & V_39 -> V_36 , V_45 -> V_59 , F_20 ( V_45 ) ,
V_39 -> V_60 ) )
goto V_58;
V_7 -> V_12 = F_21 ( & V_39 -> V_36 , V_45 -> V_59 ,
F_20 ( V_45 ) ) ;
if ( ! V_7 -> V_12 )
goto V_58;
V_7 -> V_14 = 0 ;
F_4 ( V_7 -> V_14 , V_7 -> V_12 + V_16 ) ;
F_4 ( 0 , V_7 -> V_12 + V_33 ) ;
if ( F_10 ( V_7 -> V_12 + V_33 ) & V_34 )
F_10 ( V_7 -> V_12 + V_35 ) ;
V_7 -> V_28 = F_22 ( V_39 , 0 ) ;
if ( V_7 -> V_28 >= 0 ) {
F_23 ( & V_7 -> V_31 ) ;
V_46 = F_24 ( & V_39 -> V_36 , V_7 -> V_28 , F_12 , 0 ,
V_39 -> V_60 , V_7 ) ;
if ( V_46 )
goto exit;
}
if ( ! V_41 )
V_7 -> V_53 . V_4 -> V_36 . V_61 = V_39 -> V_36 . V_61 ;
V_46 = F_25 ( & V_7 -> V_53 ) ;
if ( V_46 )
goto exit;
F_26 ( & V_39 -> V_36 , L_1 , V_7 -> V_12 , V_7 -> V_28 ) ;
return 0 ;
V_58:
V_46 = - V_62 ;
exit:
F_27 ( V_4 ) ;
return V_46 ;
}
static int F_28 ( struct V_38 * V_36 )
{
struct V_1 * V_7 = F_29 ( V_36 ) ;
struct V_43 * V_4 = V_7 -> V_53 . V_4 ;
F_30 ( & V_7 -> V_53 ) ;
F_27 ( V_4 ) ;
return 0 ;
}
