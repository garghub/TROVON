static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
F_2 ( V_4 -> V_8 , ( V_2 ? V_9 : 0 ) |
V_10 | V_11 | V_12 ) ;
V_7 = F_3 ( V_4 -> V_8 ) ;
}
static void F_4 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
F_2 ( V_4 -> V_8 , ( V_2 ? V_13 : 0 ) |
V_14 | V_15 | V_16 ) ;
V_7 = F_3 ( V_4 -> V_8 ) ;
}
static int F_5 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
F_2 ( V_4 -> V_8 , V_11 ) ;
F_2 ( V_4 -> V_8 , 0 ) ;
V_7 = F_3 ( V_4 -> V_8 ) ;
return ( ( V_7 & V_17 ) != 0 ) ;
}
static int F_6 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
F_2 ( V_4 -> V_8 , V_15 ) ;
F_2 ( V_4 -> V_8 , 0 ) ;
V_7 = F_3 ( V_4 -> V_8 ) ;
return ( ( V_7 & V_18 ) != 0 ) ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_3 * V_4 ,
const T_1 V_8 , const char * V_19 ,
int V_20 )
{
int V_21 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_8 = V_8 ;
snprintf ( V_4 -> V_22 . V_19 , sizeof( V_4 -> V_22 . V_19 ) ,
L_1 , V_19 ) ;
V_4 -> V_22 . V_20 = V_20 ;
V_4 -> V_22 . V_23 = V_24 ;
V_4 -> V_22 . V_25 = & V_4 -> V_26 ;
V_4 -> V_22 . V_27 . V_28 = & V_4 -> V_6 -> V_29 -> V_27 ;
V_4 -> V_26 . V_30 = F_4 ;
V_4 -> V_26 . V_31 = F_1 ;
V_4 -> V_26 . V_32 = F_6 ;
V_4 -> V_26 . V_33 = F_5 ;
V_4 -> V_26 . V_34 = 40 ;
V_4 -> V_26 . V_35 = 20 ;
V_4 -> V_26 . V_1 = V_4 ;
F_8 ( & V_4 -> V_22 , V_4 ) ;
F_4 ( V_4 , 1 ) ;
F_1 ( V_4 , 1 ) ;
V_34 ( 20 ) ;
V_21 = F_9 ( & V_4 -> V_22 ) ;
if ( V_21 == 0 )
F_10 ( L_2 , V_19 ) ;
else
F_11 ( L_3 , V_19 ) ;
return V_21 ;
}
void F_12 ( struct V_5 * V_6 )
{
int V_36 = 0 ;
V_6 -> V_37 = 1 ;
V_6 -> V_38 [ V_36 ] . type = V_39 ;
F_7 ( V_6 , & V_6 -> V_38 [ V_36 ] . V_40 , V_41 ,
L_4 , V_42 ) ;
V_36 ++ ;
switch( V_6 -> V_43 ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
V_6 -> V_38 [ V_36 ] . type = V_49 ;
F_7 ( V_6 , & V_6 -> V_38 [ V_36 ] . V_40 ,
V_50 , L_5 , V_42 ) ;
F_7 ( V_6 , & V_6 -> V_38 [ V_36 ] . V_51 ,
V_52 , L_6 , 0 ) ;
V_36 ++ ;
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
V_6 -> V_38 [ V_36 ] . type = V_60 ;
F_7 ( V_6 , & V_6 -> V_38 [ V_36 ] . V_51 ,
V_52 , L_7 , 0 ) ;
V_36 ++ ;
V_6 -> V_38 [ V_36 ] . type = V_60 ;
V_6 -> V_38 [ V_36 ] . V_51 = V_6 -> V_38 [ V_36 - 1 ] . V_51 ;
V_36 ++ ;
break;
}
V_6 -> V_37 = V_36 ;
}
void F_13 ( struct V_5 * V_6 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_61 ; V_36 ++ ) {
if ( V_6 -> V_38 [ V_36 ] . V_51 . V_6 ) {
F_14 ( & V_6 -> V_38 [ V_36 ] . V_51 . V_22 ) ;
V_6 -> V_38 [ V_36 ] . V_51 . V_6 = NULL ;
}
if ( V_6 -> V_38 [ V_36 ] . V_40 . V_6 ) {
F_14 ( & V_6 -> V_38 [ V_36 ] . V_40 . V_22 ) ;
V_6 -> V_38 [ V_36 ] . V_40 . V_6 = NULL ;
}
}
}
