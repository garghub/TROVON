const char * F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
return L_4 ;
case V_6 :
return L_5 ;
case V_7 :
return L_6 ;
case V_8 :
return L_7 ;
case V_9 :
return L_8 ;
case V_10 :
return L_9 ;
case V_11 :
return L_10 ;
case V_12 :
return L_11 ;
case V_13 :
return L_12 ;
case V_14 :
return L_13 ;
case V_15 :
return L_14 ;
default:
return L_15 ;
}
}
const char * F_2 ( unsigned int V_16 )
{
if ( V_16 == V_17 )
return L_16 ;
if ( V_16 == V_18 )
return L_17 ;
if ( V_16 == V_19 )
return L_14 ;
return L_15 ;
}
const struct V_20 *
F_3 ( int V_1 , int V_16 , const unsigned long * V_21 ,
T_1 V_22 , bool V_23 )
{
const struct V_20 * V_24 , * V_25 = NULL , * V_26 = NULL ;
int V_27 ;
for ( V_27 = 0 , V_24 = V_28 ; V_27 < F_4 ( V_28 ) ; V_27 ++ , V_24 ++ ) {
if ( V_24 -> V_29 < V_22 && F_5 ( V_24 -> V_29 , V_21 ) ) {
V_26 = V_24 ;
if ( V_24 -> V_1 == V_1 && V_24 -> V_16 == V_16 ) {
V_25 = V_24 ;
break;
} else if ( ! V_23 ) {
if ( ! V_25 && V_24 -> V_1 <= V_1 )
V_25 = V_24 ;
if ( V_24 -> V_1 < V_1 )
break;
}
}
}
if ( ! V_25 && ! V_23 )
V_25 = V_26 ;
return V_25 ;
}
T_1 F_6 ( unsigned int * V_30 , T_1 V_31 ,
unsigned long * V_21 , T_1 V_22 )
{
T_1 V_32 ;
int V_27 ;
for ( V_27 = 0 , V_32 = 0 ; V_27 < F_4 ( V_28 ) && V_32 < V_31 ; V_27 ++ )
if ( V_28 [ V_27 ] . V_29 < V_22 &&
F_5 ( V_28 [ V_27 ] . V_29 , V_21 ) &&
( V_32 == 0 || V_30 [ V_32 - 1 ] != V_28 [ V_27 ] . V_1 ) )
V_30 [ V_32 ++ ] = V_28 [ V_27 ] . V_1 ;
return V_32 ;
}
static void F_7 ( struct V_33 * V_34 , int V_35 , int V_36 ,
T_2 V_37 )
{
V_34 -> V_38 ( V_34 , V_35 , V_39 , V_36 ) ;
V_34 -> V_38 ( V_34 , V_35 , V_40 , V_37 ) ;
V_34 -> V_38 ( V_34 , V_35 , V_39 , V_36 | V_41 ) ;
}
int F_8 ( struct V_42 * V_43 , int V_36 , T_3 V_37 )
{
int V_44 ;
if ( V_37 > ( T_2 ) ~ 0 || V_36 > 32 )
return - V_45 ;
if ( V_43 -> V_46 -> V_47 ) {
V_44 = V_43 -> V_46 -> V_47 ( V_43 , V_36 , V_37 ) ;
} else if ( V_43 -> V_48 ) {
T_3 V_49 = V_50 | ( V_36 << 16 ) | ( V_37 & 0xffff ) ;
V_44 = F_9 ( V_43 -> V_51 . V_34 , V_43 -> V_51 . V_49 , V_49 ) ;
} else {
struct V_33 * V_34 = V_43 -> V_51 . V_34 ;
int V_35 = V_43 -> V_51 . V_49 ;
F_10 ( & V_34 -> V_52 ) ;
F_7 ( V_34 , V_35 , V_36 , V_37 ) ;
V_44 = V_34 -> V_53 ( V_34 , V_35 , V_40 ) ;
F_11 ( & V_34 -> V_52 ) ;
}
return V_44 ;
}
int F_12 ( struct V_42 * V_43 , int V_36 , T_3 V_37 , T_2 V_44 )
{
int V_54 ;
if ( V_37 > ( T_2 ) ~ 0 || V_36 > 32 )
return - V_45 ;
if ( V_43 -> V_46 -> V_55 ) {
V_54 = V_43 -> V_46 -> V_55 ( V_43 , V_36 , V_37 , V_44 ) ;
} else if ( V_43 -> V_48 ) {
T_3 V_49 = V_50 | ( V_36 << 16 ) | ( V_37 & 0xffff ) ;
V_54 = F_13 ( V_43 -> V_51 . V_34 , V_43 -> V_51 . V_49 ,
V_49 , V_44 ) ;
} else {
struct V_33 * V_34 = V_43 -> V_51 . V_34 ;
int V_35 = V_43 -> V_51 . V_49 ;
F_10 ( & V_34 -> V_52 ) ;
F_7 ( V_34 , V_35 , V_36 , V_37 ) ;
V_34 -> V_38 ( V_34 , V_35 , V_40 , V_44 ) ;
F_11 ( & V_34 -> V_52 ) ;
V_54 = 0 ;
}
return V_54 ;
}
