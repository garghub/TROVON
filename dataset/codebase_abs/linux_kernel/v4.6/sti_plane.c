const char * F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
return L_1 ;
case V_5 :
return L_2 ;
case V_6 :
return L_3 ;
case V_7 :
return L_4 ;
case V_8 :
return L_5 ;
case V_9 :
return L_6 ;
default:
return L_7 ;
}
}
static int F_2 ( struct V_10 V_11 , struct V_10 V_12 )
{
struct V_10 V_13 = F_3 ( V_11 , V_12 ) ;
T_1 V_14 = ( T_1 ) F_4 ( & V_13 ) ;
F_5 ( V_14 , V_15 ) ;
return ( V_16 ) V_14 ;
}
void F_6 ( struct V_1 * V_2 ,
bool V_17 ,
bool V_18 )
{
struct V_10 V_19 ;
struct V_20 * V_21 ;
int V_22 , V_23 , V_24 , V_25 , V_26 ;
F_7 ( & V_19 ) ;
V_21 = & V_2 -> V_27 ;
if ( V_18 )
V_21 -> V_28 ++ ;
if ( ! V_17 )
return;
V_21 -> V_29 ++ ;
V_24 = F_2 ( V_19 , V_21 -> V_30 ) ;
V_25 = V_21 -> V_29 - V_21 -> V_31 ;
if ( V_25 <= 0 || V_24 < V_32 )
return;
V_21 -> V_30 = V_19 ;
V_21 -> V_31 = V_21 -> V_29 ;
V_22 = ( V_25 * 1000000 ) / V_24 ;
snprintf ( V_2 -> V_27 . V_33 , V_34 , L_8 ,
F_1 ( V_2 ) , V_22 / 1000 , V_22 % 1000 ) ;
if ( V_21 -> V_28 ) {
V_26 = V_21 -> V_28 - V_21 -> V_35 ;
V_21 -> V_35 = V_21 -> V_28 ;
V_23 = ( V_26 * 1000000 ) / V_24 ;
snprintf ( V_2 -> V_27 . V_36 ,
V_34 , L_9 ,
V_23 / 1000 , V_23 % 1000 ) ;
} else {
V_2 -> V_27 . V_36 [ 0 ] = '\0' ;
}
if ( V_21 -> V_37 )
F_8 ( L_10 ,
V_2 -> V_27 . V_33 ,
V_2 -> V_27 . V_36 ) ;
}
static void F_9 ( struct V_38 * V_38 )
{
F_10 ( L_11 ) ;
F_11 ( V_38 ) ;
F_12 ( V_38 ) ;
}
static int F_13 ( struct V_38 * V_38 ,
struct V_39 * V_40 ,
T_2 V_41 )
{
struct V_42 * V_43 = V_38 -> V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_1 * V_2 = F_14 ( V_38 ) ;
F_10 ( L_11 ) ;
if ( V_40 == V_45 -> V_47 ) {
V_2 -> V_48 = V_41 ;
return 0 ;
}
return - V_49 ;
}
static void F_15 ( struct V_38 * V_38 )
{
struct V_42 * V_43 = V_38 -> V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_1 * V_2 = F_14 ( V_38 ) ;
struct V_39 * V_50 ;
V_50 = V_45 -> V_47 ;
if ( ! V_50 ) {
V_50 = F_16 ( V_43 , 0 , L_12 , 1 ,
V_51 ) ;
if ( ! V_50 )
return;
V_45 -> V_47 = V_50 ;
}
F_17 ( & V_38 -> V_52 , V_50 , V_2 -> V_48 ) ;
}
void F_18 ( struct V_1 * V_2 ,
enum V_53 type )
{
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < F_19 ( V_55 ) ; V_54 ++ )
if ( V_55 [ V_54 ] == V_2 -> V_3 )
break;
V_2 -> V_48 = V_54 + 1 ;
if ( type == V_56 )
F_15 ( & V_2 -> V_38 ) ;
F_10 ( L_13 ,
V_2 -> V_38 . V_52 . V_57 ,
F_1 ( V_2 ) , V_2 -> V_48 ) ;
}
