int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = NULL ;
struct V_8 * V_8 , * V_9 ;
V_8 = V_10 . V_11 ( V_2 ) ;
if ( ! V_8 )
return 0 ;
V_8 -> V_12 [ 0 ] = V_13 [ 0 ] ;
V_8 -> V_12 [ 1 ] = V_13 [ 1 ] ;
V_8 -> V_12 [ 2 ] = V_13 [ 2 ] ;
V_8 -> V_14 = 0 ;
V_8 -> V_2 = V_2 ;
V_9 = V_10 . V_11 ( V_5 ) ;
if ( V_9 )
V_7 = & V_9 -> V_15 ;
F_3 ( & V_8 -> V_15 , V_7 ) ;
F_4 ( & V_8 -> V_16 , 0 , V_17 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_8 * V_8 ;
V_8 = V_10 . V_11 ( V_2 ) ;
if ( ! V_8 )
return;
F_6 ( & V_8 -> V_16 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned long V_18 )
{
struct V_8 * V_8 ;
int V_19 ;
int V_20 ;
V_8 = V_10 . V_11 ( V_2 ) ;
if ( ! V_8 )
return - V_21 ;
V_20 = F_8 ( & V_8 -> V_15 , V_18 ) ;
if ( V_20 )
return V_20 ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ )
V_8 -> V_12 [ V_19 ] = F_9 ( long , V_18 ,
V_13 [ V_19 ] ) ;
if ( V_18 == V_22 )
F_10 ( V_23 , & V_8 -> V_24 ) ;
else {
if ( ! F_11 ( V_25 , & V_8 -> V_24 ) )
F_12 ( & V_26 ) ;
F_13 ( V_23 , & V_8 -> V_24 ) ;
}
return 0 ;
}
static T_1 F_14 ( struct V_27 * V_28 ,
char * V_29 , T_2 V_30 , T_3 V_31 )
{
struct V_1 * V_2 = F_15 ( F_16 ( V_28 ) ) ;
unsigned long V_18 ;
int V_20 = 0 ;
V_29 = F_17 ( V_29 ) ;
switch ( F_18 ( V_28 ) -> V_32 ) {
case V_33 :
V_20 = F_19 ( V_29 , & V_18 ) ;
if ( V_20 )
break;
F_20 ( & V_34 ) ;
V_20 = F_7 ( V_2 , V_18 ) ;
F_21 ( & V_34 ) ;
break;
default:
V_20 = - V_21 ;
break;
}
return V_20 ? : V_30 ;
}
static T_4 F_22 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_15 ( V_36 ) ;
struct V_8 * V_8 = V_10 . V_11 ( V_2 ) ;
T_4 V_39 ;
switch ( V_38 -> V_32 ) {
case V_33 :
if ( ! V_8 )
return V_22 ;
V_39 = V_8 -> V_15 . V_40 ;
V_39 *= V_41 ;
break;
case V_42 :
if ( ! V_8 )
V_39 = F_23 ( & V_43 ) ;
else
V_39 = F_24 ( & V_8 -> V_15 ) ;
V_39 *= V_41 ;
break;
case V_44 :
if ( ! V_8 )
return 0 ;
V_39 = V_8 -> V_15 . V_45 ;
break;
case V_46 :
if ( ! V_8 )
return 0 ;
V_39 = V_8 -> V_15 . V_47 ;
V_39 *= V_41 ;
break;
default:
F_25 () ;
}
return V_39 ;
}
static T_1 F_26 ( struct V_27 * V_28 ,
char * V_29 , T_2 V_30 , T_3 V_31 )
{
struct V_1 * V_2 ;
struct V_8 * V_8 ;
V_2 = F_15 ( F_16 ( V_28 ) ) ;
V_8 = V_10 . V_11 ( V_2 ) ;
if ( ! V_8 )
return V_30 ;
switch ( F_18 ( V_28 ) -> V_32 ) {
case V_46 :
F_27 ( & V_8 -> V_15 ) ;
break;
case V_44 :
V_8 -> V_15 . V_45 = 0 ;
break;
}
return V_30 ;
}
static int T_5 F_28 ( void )
{
F_29 ( F_30 ( & V_48 , V_49 ) ) ;
return 0 ;
}
