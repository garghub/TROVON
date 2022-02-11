static int F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case 6 :
case 7 :
V_2 -> V_3 = 5 ;
return 0 ;
case 4 :
case 5 :
V_2 -> V_3 = 3 ;
return 0 ;
case 0 :
case 3 :
V_2 -> V_3 = 2 ;
return 0 ;
default:
return - 1 ;
}
}
static inline T_1 F_2 ( T_1 V_4 )
{
switch ( V_4 ) {
case 0 :
return 3 ;
case 1 :
return 2 ;
case 2 :
return 1 ;
case 3 :
return 0 ;
case 4 :
return 5 ;
case 5 :
return 4 ;
case 6 :
return 7 ;
case 7 :
return 6 ;
}
return 0 ;
}
static T_2 F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_6 -> V_11 . V_12 ;
while ( V_6 -> V_13 & F_4 ( V_2 -> V_3 ) ) {
int V_14 = V_15 [ V_2 -> V_3 ] ;
if ( V_10 -> V_16 [ V_14 ] . V_17 &&
V_2 -> V_3 == V_10 -> V_16 [ V_14 ] . V_18 )
return V_14 ;
if ( F_1 ( V_2 ) ) {
break;
}
}
if ( V_8 && V_8 -> V_19 == V_2 -> V_3 )
V_2 -> V_3 = F_2 ( V_2 -> V_3 ) ;
return V_15 [ V_2 -> V_3 ] ;
}
T_2 F_5 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_6 -> V_23 ;
T_1 * V_24 ;
if ( V_23 -> V_25 . V_26 < V_27 )
return 0 ;
if ( ! F_6 ( V_21 -> V_28 ) ) {
V_2 -> V_3 = 7 ;
return V_15 [ V_2 -> V_3 ] ;
}
if ( ! F_7 ( V_21 -> V_28 ) ) {
V_2 -> V_3 = 0 ;
return V_15 [ V_2 -> V_3 ] ;
}
V_24 = F_8 ( V_21 ) ;
V_2 -> V_3 = * V_24 & V_29 ;
return F_3 ( V_6 , NULL , V_2 ) ;
}
T_2 F_9 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_6 -> V_23 ;
struct V_7 * V_8 = NULL ;
const T_1 * V_30 = NULL ;
bool V_31 = false ;
struct V_32 * V_33 ;
T_2 V_34 ;
if ( V_23 -> V_25 . V_26 < V_27 || V_2 -> V_35 < 6 ) {
V_2 -> V_3 = 0 ;
return 0 ;
}
F_10 () ;
switch ( V_6 -> V_36 . type ) {
case V_37 :
V_8 = F_11 ( V_6 -> V_11 . V_38 . V_8 ) ;
if ( V_8 ) {
V_31 = V_8 -> V_8 . V_39 ;
break;
}
case V_40 :
V_30 = V_2 -> V_41 ;
break;
case V_42 :
V_30 = V_6 -> V_11 . V_43 . V_44 ;
break;
#ifdef F_12
case V_45 :
V_31 = true ;
break;
#endif
case V_46 :
V_8 = F_13 ( V_6 , V_2 -> V_41 ) ;
if ( V_8 )
V_31 = V_8 -> V_8 . V_39 ;
V_30 = V_6 -> V_11 . V_12 . V_47 ;
break;
case V_48 :
V_30 = V_2 -> V_41 ;
break;
case V_49 :
V_31 = true ;
break;
default:
break;
}
if ( ! V_8 && V_30 && ! F_14 ( V_30 ) ) {
V_8 = F_13 ( V_6 , V_30 ) ;
if ( V_8 )
V_31 = V_8 -> V_8 . V_39 ;
}
if ( ! V_31 ) {
V_2 -> V_3 = 0 ;
V_34 = V_50 ;
goto V_51;
}
if ( V_2 -> V_52 == V_6 -> V_53 ) {
V_2 -> V_3 = 7 ;
goto V_54;
}
V_33 = F_11 ( V_6 -> V_33 ) ;
V_2 -> V_3 = F_15 ( V_2 , V_33 ?
& V_33 -> V_33 : NULL ) ;
V_54:
V_34 = F_3 ( V_6 , V_8 , V_2 ) ;
V_51:
F_16 () ;
return V_34 ;
}
void F_17 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_20 * V_21 = ( void * ) V_2 -> V_41 ;
struct V_55 * V_56 = F_18 ( V_2 ) ;
T_1 * V_24 ;
T_1 V_57 , V_4 ;
if ( ! F_7 ( V_21 -> V_28 ) )
return;
V_24 = F_8 ( V_21 ) ;
V_4 = V_2 -> V_3 & V_29 ;
V_57 = * V_24 & V_58 ;
if ( F_14 ( V_21 -> V_59 ) ||
V_6 -> V_60 & F_4 ( V_4 ) ) {
V_57 |= V_61 ;
V_56 -> V_62 |= V_63 ;
}
* V_24 ++ = V_57 | V_4 ;
if ( F_19 ( & V_6 -> V_36 ) ) {
* V_24 &= ( ( V_64 |
V_65 ) >> 8 ) ;
if ( ! F_20 ( V_21 -> V_28 ) )
* V_24 |= ( V_66 >> 8 ) ;
} else {
* V_24 = 0 ;
}
}
