static void F_1 ( struct V_1 * V_2 , enum V_3 V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_2 -> V_8 == NULL || V_2 -> V_8 -> V_9 == NULL )
return;
switch ( V_4 ) {
case V_10 :
V_7 -> V_11 = true ;
V_2 -> V_8 -> V_9 ( V_2 -> V_8 , V_4 , V_5 ) ;
break;
case V_12 :
case V_13 :
V_7 -> V_11 = false ;
V_2 -> V_8 -> V_9 ( V_2 -> V_8 , V_4 , V_5 ) ;
break;
case V_14 :
if ( V_5 != V_7 -> V_15 . V_16 )
break;
if ( V_7 -> V_17 )
V_2 -> V_8 -> V_9 ( V_2 -> V_8 ,
V_18 , V_5 ) ;
V_7 -> V_19 = false ;
break;
case V_20 :
if ( V_5 != V_7 -> V_15 . V_16 )
return;
if ( V_7 -> V_17 ) {
V_2 -> V_8 -> V_9 ( V_2 -> V_8 ,
V_21 ,
V_5 ) ;
}
V_7 -> V_19 = true ;
break;
case V_18 :
if ( V_7 -> V_19 ) {
V_2 -> V_8 -> V_9 ( V_2 -> V_8 ,
V_18 , V_5 ) ;
}
V_7 -> V_17 = false ;
break;
case V_21 :
if ( V_7 -> V_19 ) {
V_2 -> V_8 -> V_9 ( V_2 -> V_8 ,
V_21 , V_5 ) ;
}
V_7 -> V_17 = true ;
break;
case V_22 :
V_2 -> V_8 -> V_9 ( V_2 -> V_8 ,
V_23 , V_5 ) ;
break;
case V_23 :
V_2 -> V_8 -> V_9 ( V_2 -> V_8 , V_4 , V_5 ) ;
break;
default:
F_3 ( L_1 , V_4 ) ;
V_2 -> V_8 -> V_9 ( V_2 -> V_8 , V_4 , V_5 ) ;
V_7 -> V_19 = true ;
break;
}
}
static int F_4 ( struct V_1 * V_2 , enum V_24 V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_5 ( V_2 != NULL ) ;
F_5 ( V_2 -> V_25 != NULL ) ;
F_5 ( V_2 -> V_25 -> V_26 != NULL ) ;
if ( ! V_7 -> V_27 )
return 0 ;
switch ( V_4 ) {
case V_28 :
{
struct V_29 * V_30 ;
struct V_31 * V_32 ;
T_1 V_33 = V_34 ;
V_30 = F_6 ( V_35 ) ;
if ( ! V_30 )
return - V_36 ;
if ( F_7 ( V_30 , & V_33 , 1 ) < 0 ) {
F_8 ( L_2 ) ;
F_9 ( V_30 ) ;
return - V_37 ;
}
V_32 = F_10 ( V_30 ) ;
V_32 -> V_38 = V_7 -> V_39 . V_16 ;
V_32 -> V_40 = 1 ;
V_32 -> V_15 = & V_7 -> V_15 ;
F_11 ( V_30 , V_41 ) ;
return V_2 -> V_25 -> V_26 ( V_2 -> V_25 , V_30 ) ;
}
case V_42 :
{
struct V_29 * V_30 ;
struct V_31 * V_32 ;
T_1 V_43 = V_44 ;
V_30 = F_6 ( V_35 ) ;
if ( ! V_30 )
return - V_36 ;
if ( F_7 ( V_30 , & V_43 , 1 ) < 0 ) {
F_8 ( L_2 ) ;
F_9 ( V_30 ) ;
return - V_37 ;
}
V_32 = F_10 ( V_30 ) ;
V_32 -> V_38 = V_7 -> V_39 . V_16 ;
V_32 -> V_40 = 1 ;
V_32 -> V_15 = & V_7 -> V_15 ;
F_11 ( V_30 , V_41 ) ;
return V_2 -> V_25 -> V_26 ( V_2 -> V_25 , V_30 ) ;
}
default:
break;
}
return - V_45 ;
}
static void F_12 ( struct V_1 * V_39 )
{
struct V_6 * V_7 = F_13 ( V_39 , struct V_6 , V_39 ) ;
F_14 ( V_7 ) ;
}
void F_15 ( struct V_6 * V_7 ,
T_1 V_38 ,
struct V_15 * V_15 ,
bool V_27 )
{
F_5 ( F_16 ( struct V_6 , V_39 ) == 0 ) ;
V_7 -> V_11 = false ;
V_7 -> V_17 = true ;
V_7 -> V_19 = true ;
V_7 -> V_39 . V_16 = V_38 ;
V_7 -> V_39 . V_9 = F_1 ;
V_7 -> V_39 . V_46 = F_4 ;
V_7 -> V_15 = * V_15 ;
V_7 -> V_27 = V_27 ;
V_7 -> V_47 = F_12 ;
}
bool F_17 ( struct V_6 * V_7 , int * V_48 )
{
if ( ! V_7 -> V_11 ) {
* V_48 = - V_49 ;
return false ;
}
return true ;
}
T_1 F_18 ( struct V_1 * V_39 )
{
struct V_6 * V_50 = F_2 ( V_39 ) ;
return V_50 -> V_15 . V_16 ;
}
bool F_19 ( struct V_1 * V_39 , int V_5 )
{
struct V_6 * V_50 = F_2 ( V_39 ) ;
return V_50 -> V_15 . V_16 == V_5 ;
}
void F_20 ( struct V_1 * V_51 )
{
struct V_6 * V_50 ;
if ( V_51 == NULL || V_51 -> V_25 == NULL )
return;
V_50 = F_2 ( V_51 -> V_25 ) ;
V_50 -> V_47 ( & V_50 -> V_39 ) ;
}
void F_21 ( struct V_1 * V_52 ,
void (* F_22)( struct V_1 * V_53 ) ,
void (* F_23)( struct V_1 * V_53 ) )
{
struct V_6 * V_7 ;
if ( F_24 ( V_52 == NULL || V_52 -> V_25 == NULL ) )
return;
V_7 = F_13 ( V_52 -> V_25 , struct V_6 , V_39 ) ;
V_7 -> F_22 = F_22 ;
V_7 -> F_23 = F_23 ;
}
