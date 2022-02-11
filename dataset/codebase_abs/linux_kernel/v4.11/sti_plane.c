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
void F_2 ( struct V_1 * V_2 ,
bool V_10 ,
bool V_11 )
{
T_1 V_12 ;
struct V_13 * V_14 ;
int V_15 , V_16 , V_17 , V_18 , V_19 ;
V_12 = F_3 () ;
V_14 = & V_2 -> V_20 ;
if ( V_11 )
V_14 -> V_21 ++ ;
if ( ! V_10 )
return;
V_14 -> V_22 ++ ;
V_17 = F_4 ( F_5 ( V_12 , V_14 -> V_23 ) ) ;
V_18 = V_14 -> V_22 - V_14 -> V_24 ;
if ( V_18 <= 0 || V_17 < V_25 )
return;
V_14 -> V_23 = V_12 ;
V_14 -> V_24 = V_14 -> V_22 ;
if ( V_2 -> V_26 . V_27 ) {
V_15 = ( V_18 * 1000000 ) / V_17 ;
snprintf ( V_2 -> V_20 . V_28 , V_29 ,
L_8 ,
V_2 -> V_26 . V_30 ,
V_2 -> V_26 . V_27 -> V_31 ,
V_2 -> V_26 . V_27 -> V_32 ,
( char * ) & V_2 -> V_26 . V_27 -> V_33 -> V_33 ,
V_15 / 1000 , V_15 % 1000 ,
F_1 ( V_2 ) ) ;
}
if ( V_14 -> V_21 ) {
V_19 = V_14 -> V_21 - V_14 -> V_34 ;
V_14 -> V_34 = V_14 -> V_21 ;
V_16 = ( V_19 * 1000000 ) / V_17 ;
snprintf ( V_2 -> V_20 . V_35 ,
V_29 , L_9 ,
V_16 / 1000 , V_16 % 1000 ) ;
} else {
V_2 -> V_20 . V_35 [ 0 ] = '\0' ;
}
if ( V_14 -> V_36 )
F_6 ( L_10 ,
V_2 -> V_20 . V_28 ,
V_2 -> V_20 . V_35 ) ;
}
static int F_7 ( enum V_37 type )
{
switch ( type ) {
case V_38 :
return 0 ;
case V_39 :
return 1 ;
case V_40 :
return 7 ;
}
return 0 ;
}
void F_8 ( struct V_26 * V_2 )
{
F_9 ( V_2 ) ;
V_2 -> V_41 -> V_42 = F_7 ( V_2 -> type ) ;
}
static void F_10 ( struct V_26 * V_26 ,
enum V_37 type )
{
int V_42 = F_7 ( type ) ;
switch ( type ) {
case V_38 :
case V_39 :
F_11 ( V_26 , V_42 , 0 , 6 ) ;
break;
case V_40 :
F_12 ( V_26 , V_42 ) ;
break;
}
}
void F_13 ( struct V_1 * V_2 ,
enum V_37 type )
{
F_10 ( & V_2 -> V_26 , type ) ;
F_14 ( L_11 ,
V_2 -> V_26 . V_43 . V_44 , F_1 ( V_2 ) ) ;
}
