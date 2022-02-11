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
F_4 ( & V_7 -> V_16 , 0 ) ;
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
static int F_7 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_7 * V_7 ;
int V_18 ;
int V_19 ;
V_7 = V_10 . V_11 ( V_2 ) ;
if ( ! V_7 )
return - V_20 ;
if ( V_17 > V_21 )
V_17 = V_21 ;
V_19 = F_8 ( & V_7 -> V_15 , V_17 ) ;
if ( V_19 )
return V_19 ;
for ( V_18 = 0 ; V_18 < 3 ; V_18 ++ )
V_7 -> V_12 [ V_18 ] = F_9 ( long , V_17 >> V_22 ,
V_13 [ V_18 ] ) ;
if ( V_17 == V_21 )
F_10 ( V_23 , & V_7 -> V_24 ) ;
else if ( V_17 != V_21 ) {
if ( ! F_11 ( V_25 , & V_7 -> V_24 ) )
F_12 ( & V_26 ) ;
F_13 ( V_23 , & V_7 -> V_24 ) ;
}
return 0 ;
}
static int F_14 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 )
{
struct V_1 * V_2 = F_15 ( V_28 ) ;
unsigned long long V_17 ;
int V_19 = 0 ;
switch ( V_30 -> V_32 ) {
case V_33 :
V_19 = F_16 ( V_31 , & V_17 ) ;
if ( V_19 )
break;
V_19 = F_7 ( V_2 , V_17 ) ;
break;
default:
V_19 = - V_20 ;
break;
}
return V_19 ;
}
static T_1 F_17 ( struct V_1 * V_2 , int type , T_1 V_34 )
{
struct V_7 * V_7 ;
V_7 = V_10 . V_11 ( V_2 ) ;
if ( ! V_7 )
return V_34 ;
return F_18 ( & V_7 -> V_15 , type ) ;
}
static T_1 F_19 ( struct V_1 * V_2 )
{
struct V_7 * V_7 ;
V_7 = V_10 . V_11 ( V_2 ) ;
if ( ! V_7 )
return F_20 ( & V_35 ) << V_22 ;
return F_18 ( & V_7 -> V_15 , V_36 ) ;
}
static T_1 F_21 ( struct V_27 * V_28 , struct V_29 * V_30 )
{
struct V_1 * V_2 = F_15 ( V_28 ) ;
T_1 V_17 ;
switch ( V_30 -> V_32 ) {
case V_33 :
V_17 = F_17 ( V_2 , V_33 , V_21 ) ;
break;
case V_36 :
V_17 = F_19 ( V_2 ) ;
break;
case V_37 :
case V_38 :
V_17 = F_17 ( V_2 , V_30 -> V_32 , 0 ) ;
break;
default:
F_22 () ;
}
return V_17 ;
}
static int F_23 ( struct V_27 * V_28 , unsigned int V_39 )
{
struct V_1 * V_2 ;
struct V_7 * V_7 ;
V_2 = F_15 ( V_28 ) ;
V_7 = V_10 . V_11 ( V_2 ) ;
if ( ! V_7 )
return 0 ;
switch ( V_39 ) {
case V_38 :
F_24 ( & V_7 -> V_15 ) ;
break;
case V_37 :
F_25 ( & V_7 -> V_15 ) ;
break;
}
return 0 ;
}
static int T_2 F_26 ( void )
{
F_27 ( F_28 ( & V_40 , V_41 ) ) ;
return 0 ;
}
