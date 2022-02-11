static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , struct V_1 , V_2 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
if ( V_4 -> V_5 -> V_6 )
* V_4 -> V_5 -> V_6 = 1 ;
}
int F_4 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 = NULL ;
struct V_2 * V_2 , * V_13 ;
struct V_1 * V_14 ;
struct V_15 * V_16 = F_5 ( V_8 ) ;
struct V_15 * V_17 = F_6 ( V_16 ) ;
struct V_18 * V_18 = V_19 -> V_20 -> V_21 ;
V_2 = V_22 . V_23 ( V_16 ) ;
if ( ! V_2 )
goto V_24;
V_14 = F_1 ( V_2 ) ;
V_14 -> V_25 [ 0 ] = V_18 -> V_26 . V_27 [ 0 ] ;
V_14 -> V_25 [ 1 ] = V_18 -> V_26 . V_27 [ 1 ] ;
V_14 -> V_25 [ 2 ] = V_18 -> V_26 . V_27 [ 2 ] ;
V_14 -> V_28 = 0 ;
V_13 = V_22 . V_23 ( V_17 ) ;
if ( V_13 )
V_12 = V_13 -> V_29 ;
F_7 ( & V_14 -> V_30 , V_12 ) ;
F_8 ( & V_14 -> V_31 , 0 ) ;
V_2 -> V_32 = F_3 ;
V_2 -> V_6 = & V_14 -> V_28 ;
V_2 -> V_33 = V_14 -> V_25 ;
V_2 -> V_29 = & V_14 -> V_30 ;
V_2 -> V_34 = & V_14 -> V_31 ;
V_2 -> V_16 = V_16 ;
V_24:
return F_9 ( V_8 , V_10 , V_35 ,
F_10 ( V_35 ) ) ;
}
void F_11 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = F_5 ( V_8 ) ;
struct V_2 * V_2 ;
struct V_1 * V_14 ;
T_1 V_36 ;
V_2 = V_22 . V_23 ( V_16 ) ;
if ( ! V_2 )
return;
V_14 = F_1 ( V_2 ) ;
F_12 ( & V_14 -> V_31 ) ;
V_36 = F_13 ( & V_14 -> V_30 , V_37 ) ;
if ( V_36 != V_38 )
F_14 ( & V_39 ) ;
}
static int F_15 ( struct V_15 * V_16 , T_1 V_36 )
{
struct V_18 * V_18 = V_19 -> V_20 -> V_21 ;
struct V_1 * V_14 ;
struct V_2 * V_2 ;
T_1 V_40 ;
int V_41 ;
int V_42 ;
V_2 = V_22 . V_23 ( V_16 ) ;
if ( ! V_2 )
return - V_43 ;
if ( V_36 > V_38 )
V_36 = V_38 ;
V_14 = F_1 ( V_2 ) ;
V_40 = F_13 ( & V_14 -> V_30 , V_37 ) ;
V_42 = F_16 ( & V_14 -> V_30 , V_36 ) ;
if ( V_42 )
return V_42 ;
for ( V_41 = 0 ; V_41 < 3 ; V_41 ++ )
V_14 -> V_25 [ V_41 ] = F_17 ( long , V_36 >> V_44 ,
V_18 -> V_26 . V_27 [ V_41 ] ) ;
if ( V_36 == V_38 && V_40 != V_38 )
F_14 ( & V_39 ) ;
else if ( V_40 == V_38 && V_36 != V_38 )
F_18 ( & V_39 ) ;
return 0 ;
}
static int F_19 ( struct V_7 * V_45 , struct V_46 * V_47 ,
const char * V_48 )
{
struct V_15 * V_16 = F_5 ( V_45 ) ;
unsigned long long V_36 ;
int V_42 = 0 ;
switch ( V_47 -> V_49 ) {
case V_37 :
V_42 = F_20 ( V_48 , & V_36 ) ;
if ( V_42 )
break;
V_42 = F_15 ( V_16 , V_36 ) ;
break;
default:
V_42 = - V_43 ;
break;
}
return V_42 ;
}
static T_1 F_21 ( struct V_15 * V_16 , int type , T_1 V_50 )
{
struct V_1 * V_14 ;
struct V_2 * V_2 ;
V_2 = V_22 . V_23 ( V_16 ) ;
if ( ! V_2 )
return V_50 ;
V_14 = F_1 ( V_2 ) ;
return F_13 ( & V_14 -> V_30 , type ) ;
}
static T_1 F_22 ( struct V_15 * V_16 )
{
struct V_1 * V_14 ;
struct V_2 * V_2 ;
V_2 = V_22 . V_23 ( V_16 ) ;
if ( ! V_2 )
return F_23 ( & V_30 ) << V_44 ;
V_14 = F_1 ( V_2 ) ;
return F_13 ( & V_14 -> V_30 , V_51 ) ;
}
static T_1 F_24 ( struct V_7 * V_45 , struct V_46 * V_47 )
{
struct V_15 * V_16 = F_5 ( V_45 ) ;
T_1 V_36 ;
switch ( V_47 -> V_49 ) {
case V_37 :
V_36 = F_21 ( V_16 , V_37 , V_38 ) ;
break;
case V_51 :
V_36 = F_22 ( V_16 ) ;
break;
case V_52 :
case V_53 :
V_36 = F_21 ( V_16 , V_47 -> V_49 , 0 ) ;
break;
default:
F_25 () ;
}
return V_36 ;
}
static int F_26 ( struct V_7 * V_45 , unsigned int V_54 )
{
struct V_15 * V_16 ;
struct V_1 * V_14 ;
struct V_2 * V_2 ;
V_16 = F_5 ( V_45 ) ;
V_2 = V_22 . V_23 ( V_16 ) ;
if ( ! V_2 )
return 0 ;
V_14 = F_1 ( V_2 ) ;
switch ( V_54 ) {
case V_53 :
F_27 ( & V_14 -> V_30 ) ;
break;
case V_52 :
F_28 ( & V_14 -> V_30 ) ;
break;
}
return 0 ;
}
unsigned long long F_29 ( const struct V_15 * V_16 )
{
struct V_1 * V_14 ;
struct V_2 * V_2 ;
V_2 = V_22 . V_23 ( (struct V_15 * ) V_16 ) ;
if ( ! V_2 )
return 0 ;
V_14 = F_1 ( V_2 ) ;
return F_13 ( & V_14 -> V_30 , V_37 ) ;
}
void V_25 ( struct V_15 * V_16 , long V_36 , int V_55 )
{
struct V_1 * V_14 ;
struct V_2 * V_2 ;
V_2 = V_22 . V_23 ( V_16 ) ;
if ( ! V_2 )
return;
V_14 = F_1 ( V_2 ) ;
V_14 -> V_25 [ V_55 ] = V_36 ;
}
