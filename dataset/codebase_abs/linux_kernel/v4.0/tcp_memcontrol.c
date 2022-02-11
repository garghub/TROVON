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
if ( F_7 ( V_18 , & V_8 -> V_19 ) )
F_8 ( & V_20 ) ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_21 )
{
struct V_8 * V_8 ;
int V_22 ;
int V_23 ;
V_8 = V_10 . V_11 ( V_2 ) ;
if ( ! V_8 )
return - V_24 ;
V_23 = F_10 ( & V_8 -> V_15 , V_21 ) ;
if ( V_23 )
return V_23 ;
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ )
V_8 -> V_12 [ V_22 ] = F_11 ( long , V_21 ,
V_13 [ V_22 ] ) ;
if ( V_21 == V_25 )
F_12 ( V_26 , & V_8 -> V_19 ) ;
else {
if ( ! F_13 ( V_18 , & V_8 -> V_19 ) )
F_14 ( & V_20 ) ;
F_15 ( V_26 , & V_8 -> V_19 ) ;
}
return 0 ;
}
static T_1 F_16 ( struct V_27 * V_28 ,
char * V_29 , T_2 V_30 , T_3 V_31 )
{
struct V_1 * V_2 = F_17 ( F_18 ( V_28 ) ) ;
unsigned long V_21 ;
int V_23 = 0 ;
V_29 = F_19 ( V_29 ) ;
switch ( F_20 ( V_28 ) -> V_32 ) {
case V_33 :
V_23 = F_21 ( V_29 , L_1 , & V_21 ) ;
if ( V_23 )
break;
F_22 ( & V_34 ) ;
V_23 = F_9 ( V_2 , V_21 ) ;
F_23 ( & V_34 ) ;
break;
default:
V_23 = - V_24 ;
break;
}
return V_23 ? : V_30 ;
}
static T_4 F_24 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_17 ( V_36 ) ;
struct V_8 * V_8 = V_10 . V_11 ( V_2 ) ;
T_4 V_39 ;
switch ( V_38 -> V_32 ) {
case V_33 :
if ( ! V_8 )
return V_25 ;
V_39 = V_8 -> V_15 . V_40 ;
V_39 *= V_41 ;
break;
case V_42 :
if ( ! V_8 )
V_39 = F_25 ( & V_43 ) ;
else
V_39 = F_26 ( & V_8 -> V_15 ) ;
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
F_27 () ;
}
return V_39 ;
}
static T_1 F_28 ( struct V_27 * V_28 ,
char * V_29 , T_2 V_30 , T_3 V_31 )
{
struct V_1 * V_2 ;
struct V_8 * V_8 ;
V_2 = F_17 ( F_18 ( V_28 ) ) ;
V_8 = V_10 . V_11 ( V_2 ) ;
if ( ! V_8 )
return V_30 ;
switch ( F_20 ( V_28 ) -> V_32 ) {
case V_46 :
F_29 ( & V_8 -> V_15 ) ;
break;
case V_44 :
V_8 -> V_15 . V_45 = 0 ;
break;
}
return V_30 ;
}
static int T_5 F_30 ( void )
{
F_31 ( F_32 ( & V_48 , V_49 ) ) ;
return 0 ;
}
