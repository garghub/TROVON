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
V_15 = ( V_18 * 1000000 ) / V_17 ;
snprintf ( V_2 -> V_20 . V_26 , V_27 , L_8 ,
F_1 ( V_2 ) , V_15 / 1000 , V_15 % 1000 ) ;
if ( V_14 -> V_21 ) {
V_19 = V_14 -> V_21 - V_14 -> V_28 ;
V_14 -> V_28 = V_14 -> V_21 ;
V_16 = ( V_19 * 1000000 ) / V_17 ;
snprintf ( V_2 -> V_20 . V_29 ,
V_27 , L_9 ,
V_16 / 1000 , V_16 % 1000 ) ;
} else {
V_2 -> V_20 . V_29 [ 0 ] = '\0' ;
}
if ( V_14 -> V_30 )
F_6 ( L_10 ,
V_2 -> V_20 . V_26 ,
V_2 -> V_20 . V_29 ) ;
}
static int F_7 ( enum V_31 type )
{
switch ( type ) {
case V_32 :
return 0 ;
case V_33 :
return 1 ;
case V_34 :
return 7 ;
}
return 0 ;
}
void F_8 ( struct V_35 * V_2 )
{
F_9 ( V_2 ) ;
V_2 -> V_36 -> V_37 = F_7 ( V_2 -> type ) ;
}
static void F_10 ( struct V_35 * V_35 ,
enum V_31 type )
{
int V_37 = F_7 ( type ) ;
switch ( type ) {
case V_32 :
case V_33 :
F_11 ( V_35 , V_37 , 0 , 6 ) ;
break;
case V_34 :
F_12 ( V_35 , V_37 ) ;
break;
}
}
void F_13 ( struct V_1 * V_2 ,
enum V_31 type )
{
F_10 ( & V_2 -> V_35 , type ) ;
F_14 ( L_11 ,
V_2 -> V_35 . V_38 . V_39 , F_1 ( V_2 ) ) ;
}
