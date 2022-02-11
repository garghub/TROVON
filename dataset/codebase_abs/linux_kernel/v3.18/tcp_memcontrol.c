int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL ;
struct V_7 * V_7 , * V_8 ;
struct V_1 * V_9 = F_2 ( V_2 ) ;
V_7 = V_10 . V_11 ( V_2 ) ;
if ( ! V_7 )
return 0 ;
V_7 -> V_12 [ 0 ] = V_13 [ 0 ] ;
V_7 -> V_12 [ 1 ] = V_13 [ 1 ] ;
V_7 -> V_12 [ 2 ] = V_13 [ 2 ] ;
V_7 -> V_14 = 0 ;
V_7 -> V_2 = V_2 ;
V_8 = V_10 . V_11 ( V_9 ) ;
if ( V_8 )
V_6 = & V_8 -> V_15 ;
F_3 ( & V_7 -> V_15 , V_6 ) ;
F_4 ( & V_7 -> V_16 , 0 , V_17 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_7 * V_7 ;
V_7 = V_10 . V_11 ( V_2 ) ;
if ( ! V_7 )
return;
F_6 ( & V_7 -> V_16 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_18 )
{
struct V_7 * V_7 ;
int V_19 ;
int V_20 ;
V_7 = V_10 . V_11 ( V_2 ) ;
if ( ! V_7 )
return - V_21 ;
if ( V_18 > V_22 )
V_18 = V_22 ;
V_20 = F_8 ( & V_7 -> V_15 , V_18 ) ;
if ( V_20 )
return V_20 ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ )
V_7 -> V_12 [ V_19 ] = F_9 ( long , V_18 >> V_23 ,
V_13 [ V_19 ] ) ;
if ( V_18 == V_22 )
F_10 ( V_24 , & V_7 -> V_25 ) ;
else if ( V_18 != V_22 ) {
if ( ! F_11 ( V_26 , & V_7 -> V_25 ) )
F_12 ( & V_27 ) ;
F_13 ( V_24 , & V_7 -> V_25 ) ;
}
return 0 ;
}
static T_2 F_14 ( struct V_28 * V_29 ,
char * V_30 , T_3 V_31 , T_4 V_32 )
{
struct V_1 * V_2 = F_15 ( F_16 ( V_29 ) ) ;
unsigned long long V_18 ;
int V_20 = 0 ;
V_30 = F_17 ( V_30 ) ;
switch ( F_18 ( V_29 ) -> V_33 ) {
case V_34 :
V_20 = F_19 ( V_30 , & V_18 ) ;
if ( V_20 )
break;
V_20 = F_7 ( V_2 , V_18 ) ;
break;
default:
V_20 = - V_21 ;
break;
}
return V_20 ? : V_31 ;
}
static T_1 F_20 ( struct V_1 * V_2 , int type , T_1 V_35 )
{
struct V_7 * V_7 ;
V_7 = V_10 . V_11 ( V_2 ) ;
if ( ! V_7 )
return V_35 ;
return F_21 ( & V_7 -> V_15 , type ) ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
struct V_7 * V_7 ;
V_7 = V_10 . V_11 ( V_2 ) ;
if ( ! V_7 )
return F_23 ( & V_36 ) << V_23 ;
return F_21 ( & V_7 -> V_15 , V_37 ) ;
}
static T_1 F_24 ( struct V_38 * V_39 , struct V_40 * V_41 )
{
struct V_1 * V_2 = F_15 ( V_39 ) ;
T_1 V_18 ;
switch ( V_41 -> V_33 ) {
case V_34 :
V_18 = F_20 ( V_2 , V_34 , V_22 ) ;
break;
case V_37 :
V_18 = F_22 ( V_2 ) ;
break;
case V_42 :
case V_43 :
V_18 = F_20 ( V_2 , V_41 -> V_33 , 0 ) ;
break;
default:
F_25 () ;
}
return V_18 ;
}
static T_2 F_26 ( struct V_28 * V_29 ,
char * V_30 , T_3 V_31 , T_4 V_32 )
{
struct V_1 * V_2 ;
struct V_7 * V_7 ;
V_2 = F_15 ( F_16 ( V_29 ) ) ;
V_7 = V_10 . V_11 ( V_2 ) ;
if ( ! V_7 )
return V_31 ;
switch ( F_18 ( V_29 ) -> V_33 ) {
case V_43 :
F_27 ( & V_7 -> V_15 ) ;
break;
case V_42 :
F_28 ( & V_7 -> V_15 ) ;
break;
}
return V_31 ;
}
static int T_5 F_29 ( void )
{
F_30 ( F_31 ( & V_44 , V_45 ) ) ;
return 0 ;
}
