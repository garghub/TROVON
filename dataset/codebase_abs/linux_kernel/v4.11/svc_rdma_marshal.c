static T_1 * F_1 ( T_1 * V_1 , T_1 * V_2 )
{
T_1 * V_3 ;
while ( * V_1 ++ != V_4 ) {
V_3 = V_1 + V_5 - 1 ;
if ( V_3 > V_2 )
return NULL ;
V_1 = V_3 ;
}
return V_1 ;
}
static T_1 * F_2 ( T_1 * V_1 , T_1 * V_2 )
{
T_1 * V_3 ;
while ( * V_1 ++ != V_4 ) {
V_3 = V_1 + 1 + F_3 ( V_1 ) * V_6 ;
if ( V_3 > V_2 )
return NULL ;
V_1 = V_3 ;
}
return V_1 ;
}
static T_1 * F_4 ( T_1 * V_1 , T_1 * V_2 )
{
T_1 * V_3 ;
if ( * V_1 ++ != V_4 ) {
V_3 = V_1 + 1 + F_3 ( V_1 ) * V_6 ;
if ( V_3 > V_2 )
return NULL ;
V_1 = V_3 ;
}
return V_1 ;
}
int F_5 ( struct V_7 * V_8 )
{
T_1 * V_1 , * V_2 , * V_9 ;
unsigned int V_10 ;
if ( V_8 -> V_11 <= V_12 )
goto V_13;
V_9 = V_8 -> V_14 [ 0 ] . V_15 ;
if ( * ( V_9 + 1 ) != V_16 )
goto V_17;
switch ( * ( V_9 + 3 ) ) {
case V_18 :
case V_19 :
break;
case V_20 :
goto V_21;
case V_22 :
goto V_21;
default:
goto V_23;
}
V_2 = ( T_1 * ) ( ( unsigned long ) V_9 + V_8 -> V_11 ) ;
V_1 = F_1 ( V_9 + 4 , V_2 ) ;
if ( ! V_1 )
goto V_24;
V_1 = F_2 ( V_1 , V_2 ) ;
if ( ! V_1 )
goto V_24;
V_1 = F_4 ( V_1 , V_2 ) ;
if ( ! V_1 )
goto V_24;
if ( V_1 > V_2 )
goto V_24;
V_8 -> V_14 [ 0 ] . V_15 = V_1 ;
V_10 = ( unsigned long ) V_1 - ( unsigned long ) V_9 ;
V_8 -> V_14 [ 0 ] . V_25 -= V_10 ;
return V_10 ;
V_13:
F_6 ( L_1 , V_8 -> V_11 ) ;
return - V_26 ;
V_17:
F_6 ( L_2 ,
F_3 ( V_9 + 1 ) ) ;
return - V_27 ;
V_21:
F_6 ( L_3 ) ;
return 0 ;
V_23:
F_6 ( L_4 ,
F_3 ( V_9 + 3 ) ) ;
return - V_26 ;
V_24:
F_6 ( L_5 ) ;
return - V_26 ;
}
int F_7 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
enum V_32 V_33 , T_1 * V_34 )
{
T_1 * V_35 = V_34 ;
* V_34 ++ = V_31 -> V_36 ;
* V_34 ++ = V_31 -> V_37 ;
* V_34 ++ = V_29 -> V_38 ;
* V_34 ++ = V_22 ;
* V_34 ++ = F_8 ( V_33 ) ;
if ( V_33 == V_39 ) {
* V_34 ++ = V_16 ;
* V_34 ++ = V_16 ;
}
return ( int ) ( ( unsigned long ) V_34 - ( unsigned long ) V_35 ) ;
}
unsigned int F_9 ( T_1 * V_40 )
{
unsigned int V_41 ;
T_1 * V_1 ;
V_1 = V_40 ;
V_1 += V_42 + 1 ;
while ( * V_1 ++ != V_4 ) {
V_41 = F_3 ( V_1 ++ ) ;
V_1 += V_41 * V_6 ;
}
if ( * V_1 ++ != V_4 ) {
V_41 = F_3 ( V_1 ++ ) ;
V_1 += V_41 * V_6 ;
}
return ( unsigned long ) V_1 - ( unsigned long ) V_40 ;
}
void F_10 ( struct V_30 * V_31 , int V_43 )
{
struct V_44 * V_45 ;
V_31 -> V_46 . V_47 [ 0 ] = V_4 ;
V_45 = (struct V_44 * )
& V_31 -> V_46 . V_47 [ 1 ] ;
V_45 -> V_48 = V_49 ;
V_45 -> V_50 = F_8 ( V_43 ) ;
V_45 -> V_51 [ V_43 ] . V_52 . V_53 = V_4 ;
V_45 -> V_51 [ V_43 ] . V_52 . V_54 = V_4 ;
}
void F_11 ( struct V_44 * V_45 ,
int V_43 )
{
V_45 -> V_48 = V_49 ;
V_45 -> V_50 = F_8 ( V_43 ) ;
}
void F_12 ( struct V_44 * V_45 ,
int V_55 ,
T_1 V_53 ,
T_2 V_56 ,
T_3 V_57 )
{
struct V_58 * V_59 = & V_45 -> V_51 [ V_55 ] . V_52 ;
V_59 -> V_53 = V_53 ;
V_59 -> V_56 = V_56 ;
V_59 -> V_54 = F_8 ( V_57 ) ;
}
