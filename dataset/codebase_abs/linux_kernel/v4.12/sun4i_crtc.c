static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned long V_9 ;
if ( V_2 -> V_10 -> V_11 ) {
F_3 ( F_4 ( V_2 ) != 0 ) ;
F_5 ( & V_8 -> V_12 , V_9 ) ;
V_6 -> V_11 = V_2 -> V_10 -> V_11 ;
F_6 ( & V_8 -> V_12 , V_9 ) ;
V_2 -> V_10 -> V_11 = NULL ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_13 * V_11 = V_2 -> V_10 -> V_11 ;
F_8 ( L_1 ) ;
F_9 ( V_6 -> V_14 ) ;
if ( V_11 ) {
V_2 -> V_10 -> V_11 = NULL ;
F_10 ( & V_2 -> V_8 -> V_12 ) ;
if ( F_4 ( V_2 ) == 0 )
F_11 ( V_2 , V_11 ) ;
else
F_12 ( V_2 , V_11 ) ;
F_13 ( & V_2 -> V_8 -> V_12 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_8 ( L_2 ) ;
F_15 ( V_6 -> V_15 ) ;
if ( V_2 -> V_10 -> V_11 && ! V_2 -> V_10 -> V_16 ) {
F_10 ( & V_2 -> V_8 -> V_12 ) ;
F_12 ( V_2 , V_2 -> V_10 -> V_11 ) ;
F_13 ( & V_2 -> V_8 -> V_12 ) ;
V_2 -> V_10 -> V_11 = NULL ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_8 ( L_3 ) ;
F_17 ( V_6 -> V_15 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_8 ( L_4 , V_2 ) ;
F_19 ( V_6 -> V_15 , true ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_8 ( L_5 , V_2 ) ;
F_19 ( V_6 -> V_15 , false ) ;
}
struct V_5 * F_21 ( struct V_7 * V_17 ,
struct V_18 * V_14 ,
struct V_19 * V_15 )
{
struct V_5 * V_6 ;
struct V_20 * V_21 = NULL , * V_22 = NULL ;
int V_23 , V_24 ;
V_6 = F_22 ( V_17 -> V_8 , sizeof( * V_6 ) , V_25 ) ;
if ( ! V_6 )
return F_23 ( - V_26 ) ;
V_6 -> V_14 = V_14 ;
V_6 -> V_15 = V_15 ;
V_6 -> V_27 = F_24 ( V_17 , V_6 -> V_14 ) ;
if ( F_25 ( V_6 -> V_27 ) ) {
F_26 ( V_17 -> V_8 , L_6 ) ;
return NULL ;
}
for ( V_24 = 0 ; V_6 -> V_27 [ V_24 ] ; V_24 ++ ) {
struct V_28 * V_29 = V_6 -> V_27 [ V_24 ] ;
switch ( V_29 -> V_30 . type ) {
case V_31 :
V_21 = & V_29 -> V_30 ;
break;
case V_32 :
V_22 = & V_29 -> V_30 ;
break;
default:
break;
}
}
V_23 = F_27 ( V_17 , & V_6 -> V_2 ,
V_21 ,
V_22 ,
& V_33 ,
NULL ) ;
if ( V_23 ) {
F_26 ( V_17 -> V_8 , L_7 ) ;
return F_23 ( V_23 ) ;
}
F_28 ( & V_6 -> V_2 , & V_34 ) ;
V_6 -> V_2 . V_35 = F_29 ( V_6 -> V_15 -> V_8 -> V_36 ,
1 ) ;
for ( V_24 = 0 ; V_6 -> V_27 [ V_24 ] ; V_24 ++ ) {
T_1 V_37 = F_30 ( F_31 ( & V_6 -> V_2 ) ) ;
struct V_28 * V_29 = V_6 -> V_27 [ V_24 ] ;
if ( V_29 -> V_30 . type == V_38 )
V_29 -> V_30 . V_37 = V_37 ;
}
return V_6 ;
}
