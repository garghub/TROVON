static enum V_1
F_1 ( struct V_2 * V_3 , bool V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( ! V_6 -> V_7 )
return V_8 ;
if ( ! V_6 -> V_9 ) {
V_6 -> V_9 = F_3 ( V_6 -> V_7 ) ;
if ( V_6 -> V_9 )
F_4 ( V_6 -> V_9 , & V_6 -> V_3 ) ;
}
if ( V_6 -> V_9 )
return V_8 ;
return V_10 ;
}
static void F_5 ( struct V_2 * V_3 )
{
F_6 ( V_3 ) ;
F_7 ( V_3 ) ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_6 -> V_11 ) {
struct V_12 * V_13 ;
V_13 = F_9 ( V_3 -> V_14 ) ;
if ( ! V_13 ) {
F_10 ( L_1 ) ;
return 0 ;
}
F_11 ( V_6 -> V_11 , V_13 ) ;
V_13 -> type = V_15 | V_16 ;
F_12 ( V_3 , V_13 ) ;
return 1 ;
}
if ( V_6 -> V_9 )
return V_6 -> V_9 -> V_17 -> V_18 ( V_6 -> V_9 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_12 * V_13 )
{
return V_19 ;
}
static struct V_20 *
F_14 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
return V_6 -> V_21 ;
}
static int F_15 ( struct V_22 * V_23 ,
struct V_20 * V_21 )
{
struct V_5 * V_6 = V_23 -> V_6 ;
struct V_2 * V_3 = & V_6 -> V_3 ;
int V_24 ;
V_6 -> V_21 = V_21 ;
if ( V_6 -> V_7 )
V_3 -> V_25 = V_26 ;
else
V_3 -> V_25 = V_27 ;
V_24 = F_16 ( V_21 -> V_14 , V_3 ,
& V_28 ,
V_29 ) ;
if ( V_24 ) {
F_10 ( L_2 ) ;
return V_24 ;
}
F_17 ( V_3 , & V_30 ) ;
F_18 ( V_3 ) ;
F_19 ( V_3 , V_21 ) ;
return 0 ;
}
static void F_20 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 )
F_21 ( V_6 -> V_9 ) ;
}
static void F_22 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 )
F_23 ( V_6 -> V_9 ) ;
}
static void F_24 ( struct V_22 * V_23 , int V_13 )
{
struct V_5 * V_6 = V_23 -> V_6 ;
switch ( V_13 ) {
case V_31 :
if ( V_6 -> V_32 != V_31 )
F_20 ( V_6 ) ;
break;
case V_33 :
case V_34 :
case V_35 :
if ( V_6 -> V_32 == V_31 )
F_22 ( V_6 ) ;
break;
default:
break;
} ;
V_6 -> V_32 = V_13 ;
}
static struct V_36 *
F_25 ( struct V_36 * V_37 , const char * V_38 , T_1 V_39 )
{
struct V_36 * V_40 ;
F_26 (parent, np) {
T_1 V_41 ;
if ( ! V_40 -> V_38 || F_27 ( V_40 -> V_38 , V_38 ) )
continue;
if ( F_28 ( V_40 , L_3 , & V_41 ) < 0 )
V_41 = 0 ;
if ( V_39 == V_41 )
break;
}
return V_40 ;
}
static struct V_36 * F_29 ( struct V_36 * V_37 ,
T_1 V_39 )
{
struct V_36 * V_42 , * V_43 ;
V_42 = F_30 ( V_37 , L_4 ) ;
if ( V_42 )
V_37 = V_42 ;
V_43 = F_25 ( V_37 , L_5 , V_39 ) ;
F_31 ( V_42 ) ;
return V_43 ;
}
static struct V_36 *
F_32 ( struct V_36 * V_43 , T_1 V_39 )
{
return F_25 ( V_43 , L_6 , V_39 ) ;
}
static struct V_36 *
F_33 ( const struct V_36 * V_44 )
{
struct V_36 * V_40 ;
unsigned int V_45 ;
V_40 = F_34 ( V_44 , L_7 , 0 ) ;
for ( V_45 = 3 ; V_45 && V_40 ; V_45 -- ) {
V_40 = F_35 ( V_40 ) ;
if ( V_45 == 2 && F_27 ( V_40 -> V_38 , L_4 ) )
break;
}
return V_40 ;
}
static struct V_36 * F_36 ( struct V_46 * V_14 )
{
struct V_36 * V_40 , * V_47 ;
V_40 = F_29 ( V_14 -> V_48 , V_49 ) ;
if ( ! V_40 )
return NULL ;
V_47 = F_32 ( V_40 , 0 ) ;
F_31 ( V_40 ) ;
if ( ! V_47 )
return NULL ;
V_40 = F_33 ( V_47 ) ;
F_31 ( V_47 ) ;
return V_40 ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_46 * V_14 = V_6 -> V_14 ;
struct V_36 * V_50 = V_14 -> V_48 ;
struct V_36 * V_40 ;
V_6 -> V_7 = F_36 ( V_14 ) ;
V_40 = F_30 ( V_50 , L_8 ) ;
if ( V_40 ) {
struct V_51 * V_11 ;
int V_24 ;
F_31 ( V_40 ) ;
V_11 = F_38 ( V_14 , sizeof( * V_6 -> V_11 ) , V_52 ) ;
if ( ! V_11 )
return - V_53 ;
V_24 = F_39 ( V_50 , V_11 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_6 -> V_11 = V_11 ;
return 0 ;
}
if ( ! V_6 -> V_7 )
return - V_54 ;
return 0 ;
}
int F_40 ( struct V_46 * V_14 )
{
struct V_5 * V_6 ;
int V_24 ;
V_6 = F_38 ( V_14 , sizeof( * V_6 ) , V_52 ) ;
if ( ! V_6 )
return - V_53 ;
V_6 -> V_14 = V_14 ;
V_55 . V_6 = V_6 ;
V_6 -> V_32 = V_35 ;
V_24 = F_37 ( V_6 ) ;
if ( V_24 < 0 )
return V_24 ;
F_41 ( & V_55 ) ;
return 0 ;
}
int F_42 ( struct V_46 * V_14 )
{
F_24 ( & V_55 , V_35 ) ;
F_43 ( & V_55 ) ;
return 0 ;
}
