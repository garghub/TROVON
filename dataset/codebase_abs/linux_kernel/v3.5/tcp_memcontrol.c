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
struct V_7 * V_15 = F_5 ( V_8 ) ;
struct V_16 * V_16 = V_17 -> V_18 -> V_19 ;
V_2 = V_20 . V_21 ( V_8 ) ;
if ( ! V_2 )
return 0 ;
V_14 = F_1 ( V_2 ) ;
V_14 -> V_22 [ 0 ] = V_16 -> V_23 . V_24 [ 0 ] ;
V_14 -> V_22 [ 1 ] = V_16 -> V_23 . V_24 [ 1 ] ;
V_14 -> V_22 [ 2 ] = V_16 -> V_23 . V_24 [ 2 ] ;
V_14 -> V_25 = 0 ;
V_13 = V_20 . V_21 ( V_15 ) ;
if ( V_13 )
V_12 = V_13 -> V_26 ;
F_6 ( & V_14 -> V_27 , V_12 ) ;
F_7 ( & V_14 -> V_28 , 0 ) ;
V_2 -> V_29 = F_3 ;
V_2 -> V_6 = & V_14 -> V_25 ;
V_2 -> V_30 = V_14 -> V_22 ;
V_2 -> V_26 = & V_14 -> V_27 ;
V_2 -> V_31 = & V_14 -> V_28 ;
V_2 -> V_8 = V_8 ;
return 0 ;
}
void F_8 ( struct V_7 * V_8 )
{
struct V_2 * V_2 ;
struct V_1 * V_14 ;
T_1 V_32 ;
V_2 = V_20 . V_21 ( V_8 ) ;
if ( ! V_2 )
return;
V_14 = F_1 ( V_2 ) ;
F_9 ( & V_14 -> V_28 ) ;
V_32 = F_10 ( & V_14 -> V_27 , V_33 ) ;
}
static int F_11 ( struct V_7 * V_8 , T_1 V_32 )
{
struct V_16 * V_16 = V_17 -> V_18 -> V_19 ;
struct V_1 * V_14 ;
struct V_2 * V_2 ;
T_1 V_34 ;
int V_35 ;
int V_36 ;
V_2 = V_20 . V_21 ( V_8 ) ;
if ( ! V_2 )
return - V_37 ;
if ( V_32 > V_38 )
V_32 = V_38 ;
V_14 = F_1 ( V_2 ) ;
V_34 = F_10 ( & V_14 -> V_27 , V_33 ) ;
V_36 = F_12 ( & V_14 -> V_27 , V_32 ) ;
if ( V_36 )
return V_36 ;
for ( V_35 = 0 ; V_35 < 3 ; V_35 ++ )
V_14 -> V_22 [ V_35 ] = F_13 ( long , V_32 >> V_39 ,
V_16 -> V_23 . V_24 [ V_35 ] ) ;
if ( V_32 == V_38 )
F_14 ( V_40 , & V_2 -> V_41 ) ;
else if ( V_32 != V_38 ) {
if ( ! F_15 ( V_42 , & V_2 -> V_41 ) )
F_16 ( & V_43 ) ;
F_17 ( V_40 , & V_2 -> V_41 ) ;
}
return 0 ;
}
static int F_18 ( struct V_44 * V_45 , struct V_46 * V_47 ,
const char * V_48 )
{
struct V_7 * V_8 = F_19 ( V_45 ) ;
unsigned long long V_32 ;
int V_36 = 0 ;
switch ( V_47 -> V_49 ) {
case V_33 :
V_36 = F_20 ( V_48 , & V_32 ) ;
if ( V_36 )
break;
V_36 = F_11 ( V_8 , V_32 ) ;
break;
default:
V_36 = - V_37 ;
break;
}
return V_36 ;
}
static T_1 F_21 ( struct V_7 * V_8 , int type , T_1 V_50 )
{
struct V_1 * V_14 ;
struct V_2 * V_2 ;
V_2 = V_20 . V_21 ( V_8 ) ;
if ( ! V_2 )
return V_50 ;
V_14 = F_1 ( V_2 ) ;
return F_10 ( & V_14 -> V_27 , type ) ;
}
static T_1 F_22 ( struct V_7 * V_8 )
{
struct V_1 * V_14 ;
struct V_2 * V_2 ;
V_2 = V_20 . V_21 ( V_8 ) ;
if ( ! V_2 )
return F_23 ( & V_27 ) << V_39 ;
V_14 = F_1 ( V_2 ) ;
return F_10 ( & V_14 -> V_27 , V_51 ) ;
}
static T_1 F_24 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
struct V_7 * V_8 = F_19 ( V_45 ) ;
T_1 V_32 ;
switch ( V_47 -> V_49 ) {
case V_33 :
V_32 = F_21 ( V_8 , V_33 , V_38 ) ;
break;
case V_51 :
V_32 = F_22 ( V_8 ) ;
break;
case V_52 :
case V_53 :
V_32 = F_21 ( V_8 , V_47 -> V_49 , 0 ) ;
break;
default:
F_25 () ;
}
return V_32 ;
}
static int F_26 ( struct V_44 * V_45 , unsigned int V_54 )
{
struct V_7 * V_8 ;
struct V_1 * V_14 ;
struct V_2 * V_2 ;
V_8 = F_19 ( V_45 ) ;
V_2 = V_20 . V_21 ( V_8 ) ;
if ( ! V_2 )
return 0 ;
V_14 = F_1 ( V_2 ) ;
switch ( V_54 ) {
case V_53 :
F_27 ( & V_14 -> V_27 ) ;
break;
case V_52 :
F_28 ( & V_14 -> V_27 ) ;
break;
}
return 0 ;
}
unsigned long long F_29 ( const struct V_7 * V_8 )
{
struct V_1 * V_14 ;
struct V_2 * V_2 ;
V_2 = V_20 . V_21 ( (struct V_7 * ) V_8 ) ;
if ( ! V_2 )
return 0 ;
V_14 = F_1 ( V_2 ) ;
return F_10 ( & V_14 -> V_27 , V_33 ) ;
}
void V_22 ( struct V_7 * V_8 , long V_32 , int V_55 )
{
struct V_1 * V_14 ;
struct V_2 * V_2 ;
V_2 = V_20 . V_21 ( V_8 ) ;
if ( ! V_2 )
return;
V_14 = F_1 ( V_2 ) ;
V_14 -> V_22 [ V_55 ] = V_32 ;
}
static int T_2 F_30 ( void )
{
F_31 ( F_32 ( & V_56 , V_57 ) ) ;
return 0 ;
}
