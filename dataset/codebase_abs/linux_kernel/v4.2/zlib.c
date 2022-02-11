static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( V_4 -> V_6 ) {
F_2 ( V_4 ) ;
F_3 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_7 ;
if ( V_4 -> V_6 ) {
F_5 ( V_4 ) ;
F_3 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
}
static int F_6 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_7 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static int F_9 ( struct V_10 * V_9 , const void * V_11 ,
unsigned int V_12 )
{
struct V_1 * V_2 = F_8 ( F_10 ( V_9 ) ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_13 * V_14 [ V_15 + 1 ] ;
int V_16 , V_17 ;
T_1 V_18 ;
int V_19 ;
V_19 = F_11 ( V_14 , V_15 , V_11 , V_12 , NULL ) ;
if ( V_19 )
return V_19 ;
F_1 ( V_2 ) ;
V_16 = V_14 [ V_20 ]
? F_12 ( V_14 [ V_20 ] )
: V_21 ;
V_17 = V_14 [ V_22 ]
? F_12 ( V_14 [ V_22 ] )
: V_23 ;
V_18 = F_13 ( V_16 , V_17 ) ;
V_4 -> V_6 = F_14 ( V_18 ) ;
if ( ! V_4 -> V_6 )
return - V_24 ;
V_19 = F_15 ( V_4 ,
V_14 [ V_25 ]
? F_12 ( V_14 [ V_25 ] )
: V_26 ,
V_14 [ V_27 ]
? F_12 ( V_14 [ V_27 ] )
: V_28 ,
V_16 ,
V_17 ,
V_14 [ V_29 ]
? F_12 ( V_14 [ V_29 ] )
: V_30 ) ;
if ( V_19 != V_31 ) {
F_3 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
return - V_32 ;
}
return 0 ;
}
static int F_16 ( struct V_10 * V_9 )
{
int V_19 ;
struct V_1 * V_33 = F_8 ( F_10 ( V_9 ) ) ;
struct V_3 * V_4 = & V_33 -> V_5 ;
V_19 = F_17 ( V_4 ) ;
if ( V_19 != V_31 )
return - V_32 ;
return 0 ;
}
static int F_18 ( struct V_10 * V_9 ,
struct V_34 * V_35 )
{
int V_19 ;
struct V_1 * V_33 = F_8 ( F_10 ( V_9 ) ) ;
struct V_3 * V_4 = & V_33 -> V_5 ;
F_19 ( L_1 , V_35 -> V_36 , V_35 -> V_37 ) ;
V_4 -> V_38 = V_35 -> V_38 ;
V_4 -> V_36 = V_35 -> V_36 ;
V_4 -> V_39 = V_35 -> V_39 ;
V_4 -> V_37 = V_35 -> V_37 ;
V_19 = F_20 ( V_4 , V_40 ) ;
switch ( V_19 ) {
case V_31 :
break;
case V_41 :
F_19 ( L_2 ) ;
return - V_42 ;
default:
F_19 ( L_3 , V_19 ) ;
return - V_32 ;
}
V_19 = V_35 -> V_37 - V_4 -> V_37 ;
F_19 ( L_4 ,
V_4 -> V_36 , V_4 -> V_37 ,
V_35 -> V_36 - V_4 -> V_36 , V_19 ) ;
V_35 -> V_38 = V_4 -> V_38 ;
V_35 -> V_36 = V_4 -> V_36 ;
V_35 -> V_39 = V_4 -> V_39 ;
V_35 -> V_37 = V_4 -> V_37 ;
return V_19 ;
}
static int F_21 ( struct V_10 * V_9 ,
struct V_34 * V_35 )
{
int V_19 ;
struct V_1 * V_33 = F_8 ( F_10 ( V_9 ) ) ;
struct V_3 * V_4 = & V_33 -> V_5 ;
F_19 ( L_1 , V_35 -> V_36 , V_35 -> V_37 ) ;
V_4 -> V_38 = V_35 -> V_38 ;
V_4 -> V_36 = V_35 -> V_36 ;
V_4 -> V_39 = V_35 -> V_39 ;
V_4 -> V_37 = V_35 -> V_37 ;
V_19 = F_20 ( V_4 , V_43 ) ;
if ( V_19 != V_44 ) {
F_19 ( L_3 , V_19 ) ;
return - V_32 ;
}
V_19 = V_35 -> V_37 - V_4 -> V_37 ;
F_19 ( L_4 ,
V_4 -> V_36 , V_4 -> V_37 ,
V_35 -> V_36 - V_4 -> V_36 , V_19 ) ;
V_35 -> V_38 = V_4 -> V_38 ;
V_35 -> V_36 = V_4 -> V_36 ;
V_35 -> V_39 = V_4 -> V_39 ;
V_35 -> V_37 = V_4 -> V_37 ;
return V_19 ;
}
static int F_22 ( struct V_10 * V_9 , const void * V_11 ,
unsigned int V_12 )
{
struct V_1 * V_2 = F_8 ( F_10 ( V_9 ) ) ;
struct V_3 * V_4 = & V_2 -> V_7 ;
struct V_13 * V_14 [ V_45 + 1 ] ;
int V_19 = 0 ;
V_19 = F_11 ( V_14 , V_45 , V_11 , V_12 , NULL ) ;
if ( V_19 )
return V_19 ;
F_4 ( V_2 ) ;
V_2 -> V_46 = V_14 [ V_47 ]
? F_12 ( V_14 [ V_47 ] )
: V_48 ;
V_4 -> V_6 = F_14 ( F_23 () ) ;
if ( ! V_4 -> V_6 )
return - V_24 ;
V_19 = F_24 ( V_4 , V_2 -> V_46 ) ;
if ( V_19 != V_31 ) {
F_3 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
return - V_32 ;
}
return 0 ;
}
static int F_25 ( struct V_10 * V_9 )
{
int V_19 ;
struct V_1 * V_33 = F_8 ( F_10 ( V_9 ) ) ;
struct V_3 * V_4 = & V_33 -> V_7 ;
V_19 = F_26 ( V_4 ) ;
if ( V_19 != V_31 )
return - V_32 ;
return 0 ;
}
static int F_27 ( struct V_10 * V_9 ,
struct V_34 * V_35 )
{
int V_19 ;
struct V_1 * V_33 = F_8 ( F_10 ( V_9 ) ) ;
struct V_3 * V_4 = & V_33 -> V_7 ;
F_19 ( L_1 , V_35 -> V_36 , V_35 -> V_37 ) ;
V_4 -> V_38 = V_35 -> V_38 ;
V_4 -> V_36 = V_35 -> V_36 ;
V_4 -> V_39 = V_35 -> V_39 ;
V_4 -> V_37 = V_35 -> V_37 ;
V_19 = F_28 ( V_4 , V_49 ) ;
switch ( V_19 ) {
case V_31 :
case V_44 :
break;
case V_41 :
F_19 ( L_5 ) ;
return - V_42 ;
default:
F_19 ( L_6 , V_19 ) ;
return - V_32 ;
}
V_19 = V_35 -> V_37 - V_4 -> V_37 ;
F_19 ( L_4 ,
V_4 -> V_36 , V_4 -> V_37 ,
V_35 -> V_36 - V_4 -> V_36 , V_19 ) ;
V_35 -> V_38 = V_4 -> V_38 ;
V_35 -> V_36 = V_4 -> V_36 ;
V_35 -> V_39 = V_4 -> V_39 ;
V_35 -> V_37 = V_4 -> V_37 ;
return V_19 ;
}
static int F_29 ( struct V_10 * V_9 ,
struct V_34 * V_35 )
{
int V_19 ;
struct V_1 * V_33 = F_8 ( F_10 ( V_9 ) ) ;
struct V_3 * V_4 = & V_33 -> V_7 ;
F_19 ( L_1 , V_35 -> V_36 , V_35 -> V_37 ) ;
V_4 -> V_38 = V_35 -> V_38 ;
V_4 -> V_36 = V_35 -> V_36 ;
V_4 -> V_39 = V_35 -> V_39 ;
V_4 -> V_37 = V_35 -> V_37 ;
if ( V_33 -> V_46 < 0 ) {
V_19 = F_28 ( V_4 , V_49 ) ;
if ( V_19 == V_31 && ! V_4 -> V_36 && V_4 -> V_37 ) {
const void * V_50 = V_4 -> V_38 ;
T_2 V_51 = 0 ;
V_4 -> V_38 = & V_51 ;
V_4 -> V_36 = 1 ;
V_19 = F_28 ( V_4 , V_43 ) ;
V_4 -> V_38 = V_50 ;
V_4 -> V_36 = 0 ;
}
} else
V_19 = F_28 ( V_4 , V_43 ) ;
if ( V_19 != V_44 ) {
F_19 ( L_6 , V_19 ) ;
return - V_32 ;
}
V_19 = V_35 -> V_37 - V_4 -> V_37 ;
F_19 ( L_4 ,
V_4 -> V_36 , V_4 -> V_37 ,
V_35 -> V_36 - V_4 -> V_36 , V_19 ) ;
V_35 -> V_38 = V_4 -> V_38 ;
V_35 -> V_36 = V_4 -> V_36 ;
V_35 -> V_39 = V_4 -> V_39 ;
V_35 -> V_37 = V_4 -> V_37 ;
return V_19 ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_52 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_52 ) ;
}
