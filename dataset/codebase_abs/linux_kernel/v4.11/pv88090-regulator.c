static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
int V_6 , V_7 = 0 ;
V_6 = F_3 ( V_2 -> V_8 , V_4 -> V_9 , & V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
switch ( V_5 & V_10 ) {
case V_11 :
V_7 = V_12 ;
break;
case V_13 :
V_7 = V_14 ;
break;
case V_15 :
V_7 = V_16 ;
break;
}
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_17 = 0 ;
switch ( V_7 ) {
case V_12 :
V_17 = V_11 ;
break;
case V_14 :
V_17 = V_13 ;
break;
case V_16 :
V_17 = V_15 ;
break;
default:
return - V_18 ;
}
return F_5 ( V_2 -> V_8 , V_4 -> V_9 ,
V_10 , V_17 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_19 ,
int V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_21 ;
for ( V_21 = V_4 -> V_22 ; V_21 >= 0 ; V_21 -- ) {
if ( V_19 <= V_4 -> V_23 [ V_21 ]
&& V_20 >= V_4 -> V_23 [ V_21 ] ) {
return F_5 ( V_2 -> V_8 ,
V_4 -> V_9 ,
V_4 -> V_24 ,
V_21 << V_25 ) ;
}
}
return - V_18 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
int V_6 ;
V_6 = F_3 ( V_2 -> V_8 , V_4 -> V_9 , & V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 = ( V_5 & V_4 -> V_24 ) >> V_25 ;
return V_4 -> V_23 [ V_5 ] ;
}
static T_1 F_8 ( int V_26 , void * V_5 )
{
struct V_27 * V_28 = V_5 ;
int V_21 , V_29 , V_30 , V_6 = V_31 ;
V_30 = F_3 ( V_28 -> V_8 , V_32 , & V_29 ) ;
if ( V_30 < 0 )
goto V_33;
if ( V_29 & V_34 ) {
for ( V_21 = 0 ; V_21 < V_35 ; V_21 ++ ) {
if ( V_28 -> V_2 [ V_21 ] != NULL ) {
F_9 ( V_28 -> V_2 [ V_21 ] ,
V_36 ,
NULL ) ;
}
}
V_30 = F_10 ( V_28 -> V_8 , V_32 ,
V_34 ) ;
if ( V_30 < 0 )
goto V_33;
V_6 = V_37 ;
}
if ( V_29 & V_38 ) {
for ( V_21 = 0 ; V_21 < V_35 ; V_21 ++ ) {
if ( V_28 -> V_2 [ V_21 ] != NULL ) {
F_9 ( V_28 -> V_2 [ V_21 ] ,
V_39 ,
NULL ) ;
}
}
V_30 = F_10 ( V_28 -> V_8 , V_32 ,
V_38 ) ;
if ( V_30 < 0 )
goto V_33;
V_6 = V_37 ;
}
return V_6 ;
V_33:
F_11 ( V_28 -> V_40 , L_1 , V_30 ) ;
return V_31 ;
}
static int F_12 ( struct V_41 * V_42 ,
const struct V_43 * V_44 )
{
struct V_45 * V_46 = F_13 ( & V_42 -> V_40 ) ;
struct V_27 * V_28 ;
struct V_47 V_48 = { } ;
int error , V_21 , V_6 = 0 ;
unsigned int V_49 , V_50 , V_51 ;
V_28 = F_14 ( & V_42 -> V_40 , sizeof( struct V_27 ) , V_52 ) ;
if ( ! V_28 )
return - V_53 ;
V_28 -> V_40 = & V_42 -> V_40 ;
V_28 -> V_8 = F_15 ( V_42 , & V_54 ) ;
if ( F_16 ( V_28 -> V_8 ) ) {
error = F_17 ( V_28 -> V_8 ) ;
F_11 ( V_28 -> V_40 , L_2 ,
error ) ;
return error ;
}
F_18 ( V_42 , V_28 ) ;
if ( V_42 -> V_26 != 0 ) {
V_6 = F_10 ( V_28 -> V_8 , V_55 , 0xFF ) ;
if ( V_6 < 0 ) {
F_11 ( V_28 -> V_40 ,
L_3 , V_6 ) ;
return V_6 ;
}
V_6 = F_10 ( V_28 -> V_8 , V_56 , 0xFF ) ;
if ( V_6 < 0 ) {
F_11 ( V_28 -> V_40 ,
L_4 , V_6 ) ;
return V_6 ;
}
V_6 = F_19 ( & V_42 -> V_40 , V_42 -> V_26 , NULL ,
F_8 ,
V_57 | V_58 ,
L_5 , V_28 ) ;
if ( V_6 != 0 ) {
F_11 ( V_28 -> V_40 , L_6 ,
V_42 -> V_26 ) ;
return V_6 ;
}
V_6 = F_5 ( V_28 -> V_8 , V_55 ,
V_59 | V_60 , 0 ) ;
if ( V_6 < 0 ) {
F_11 ( V_28 -> V_40 ,
L_7 , V_6 ) ;
return V_6 ;
}
} else {
F_20 ( V_28 -> V_40 , L_8 ) ;
}
V_48 . V_40 = V_28 -> V_40 ;
V_48 . V_8 = V_28 -> V_8 ;
for ( V_21 = 0 ; V_21 < V_35 ; V_21 ++ ) {
if ( V_46 )
V_48 . V_46 = & V_46 [ V_21 ] ;
if ( V_21 == V_61 || V_21 == V_62 ) {
V_6 = F_3 ( V_28 -> V_8 ,
V_63 [ V_21 ] . V_49 , & V_49 ) ;
if ( V_6 < 0 )
return V_6 ;
V_49 = ( V_49 >> V_64 ) &
V_65 ;
V_6 = F_3 ( V_28 -> V_8 ,
V_66 , & V_50 ) ;
if ( V_6 < 0 )
return V_6 ;
V_50 = ( V_50 >>
( V_67 + V_21 - 1 ) ) &
V_68 ;
V_51 = ( ( V_50 << 1 ) | V_49 ) ;
V_63 [ V_21 ] . V_69 . V_70
= V_71 [ V_51 ] . V_70 ;
V_63 [ V_21 ] . V_69 . V_72
= V_71 [ V_51 ] . V_72 ;
V_63 [ V_21 ] . V_69 . V_73
= ( ( V_71 [ V_51 ] . V_74 )
- ( V_71 [ V_51 ] . V_70 ) )
/ ( V_71 [ V_51 ] . V_72 ) + 1 ;
}
V_48 . V_75 = ( void * ) & V_63 [ V_21 ] ;
V_28 -> V_2 [ V_21 ] = F_21 ( V_28 -> V_40 ,
& V_63 [ V_21 ] . V_69 , & V_48 ) ;
if ( F_16 ( V_28 -> V_2 [ V_21 ] ) ) {
F_11 ( V_28 -> V_40 ,
L_9 ) ;
return F_17 ( V_28 -> V_2 [ V_21 ] ) ;
}
}
return 0 ;
}
