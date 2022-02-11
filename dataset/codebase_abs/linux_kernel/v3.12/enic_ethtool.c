static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
V_4 -> V_6 = ( V_7 | V_8 ) ;
V_4 -> V_9 = ( V_10 | V_11 ) ;
V_4 -> V_12 = V_13 ;
V_4 -> V_14 = V_15 ;
if ( F_3 ( V_2 ) ) {
F_4 ( V_4 , F_5 ( V_5 -> V_16 ) ) ;
V_4 -> V_17 = V_18 ;
} else {
F_4 ( V_4 , - 1 ) ;
V_4 -> V_17 = - 1 ;
}
V_4 -> V_19 = V_20 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_23 * V_24 ;
F_7 ( V_5 , & V_24 ) ;
F_8 ( V_22 -> V_25 , V_26 , sizeof( V_22 -> V_25 ) ) ;
F_8 ( V_22 -> V_27 , V_28 , sizeof( V_22 -> V_27 ) ) ;
F_8 ( V_22 -> V_29 , V_24 -> V_29 ,
sizeof( V_22 -> V_29 ) ) ;
F_8 ( V_22 -> V_30 , F_9 ( V_5 -> V_31 ) ,
sizeof( V_22 -> V_30 ) ) ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_32 ,
T_2 * V_33 )
{
unsigned int V_34 ;
switch ( V_32 ) {
case V_35 :
for ( V_34 = 0 ; V_34 < V_36 ; V_34 ++ ) {
memcpy ( V_33 , V_37 [ V_34 ] . V_38 , V_39 ) ;
V_33 += V_39 ;
}
for ( V_34 = 0 ; V_34 < V_40 ; V_34 ++ ) {
memcpy ( V_33 , V_41 [ V_34 ] . V_38 , V_39 ) ;
V_33 += V_39 ;
}
break;
}
}
static int F_11 ( struct V_1 * V_2 , int V_42 )
{
switch ( V_42 ) {
case V_35 :
return V_36 + V_40 ;
default:
return - V_43 ;
}
}
static void F_12 ( struct V_1 * V_2 ,
struct V_44 * V_45 , T_3 * V_33 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_46 * V_47 ;
unsigned int V_34 ;
F_13 ( V_5 , & V_47 ) ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 ++ )
* ( V_33 ++ ) = ( ( T_3 * ) & V_47 -> V_48 ) [ V_37 [ V_34 ] . V_49 ] ;
for ( V_34 = 0 ; V_34 < V_40 ; V_34 ++ )
* ( V_33 ++ ) = ( ( T_3 * ) & V_47 -> V_50 ) [ V_41 [ V_34 ] . V_49 ] ;
}
static T_1 F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_51 ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_52 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_51 = V_52 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_53 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
V_4 -> V_54 = V_5 -> V_54 ;
V_4 -> V_55 = V_5 -> V_55 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_53 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
T_1 V_54 ;
T_1 V_55 ;
unsigned int V_34 , V_56 ;
V_54 = F_18 ( T_1 , V_4 -> V_54 ,
F_19 ( V_5 -> V_16 ) ) ;
V_55 = F_18 ( T_1 , V_4 -> V_55 ,
F_19 ( V_5 -> V_16 ) ) ;
switch ( F_20 ( V_5 -> V_16 ) ) {
case V_57 :
if ( V_54 != V_55 )
return - V_58 ;
V_56 = F_21 () ;
F_22 ( & V_5 -> V_56 [ V_56 ] ,
V_54 ) ;
break;
case V_59 :
if ( V_54 != V_55 )
return - V_58 ;
F_22 ( & V_5 -> V_56 [ 0 ] ,
V_54 ) ;
break;
case V_60 :
for ( V_34 = 0 ; V_34 < V_5 -> V_61 ; V_34 ++ ) {
V_56 = F_23 ( V_5 , V_34 ) ;
F_22 ( & V_5 -> V_56 [ V_56 ] ,
V_54 ) ;
}
for ( V_34 = 0 ; V_34 < V_5 -> V_62 ; V_34 ++ ) {
V_56 = F_24 ( V_5 , V_34 ) ;
F_22 ( & V_5 -> V_56 [ V_56 ] ,
V_55 ) ;
}
break;
default:
break;
}
V_5 -> V_54 = V_54 ;
V_5 -> V_55 = V_55 ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 , & V_63 ) ;
}
