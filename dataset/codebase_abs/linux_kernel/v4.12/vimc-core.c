const struct V_1 * F_1 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_2 == V_2 )
return & V_4 [ V_3 ] ;
}
return NULL ;
}
const struct V_1 * F_3 ( T_1 V_5 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_5 == V_5 )
return & V_4 [ V_3 ] ;
}
return NULL ;
}
int F_4 ( struct V_6 * V_7 , const void * V_8 )
{
struct V_9 * V_10 ;
if ( ! ( V_7 -> V_11 & V_12 ) )
return - V_13 ;
F_5 (link, &src->entity->links, list) {
if ( V_10 -> V_14 == V_7 &&
( V_10 -> V_11 & V_15 ) ) {
struct V_16 * V_17 = NULL ;
struct V_18 * V_19 = V_10 -> V_20 -> V_19 ;
if ( F_6 ( V_19 ) ) {
struct V_21 * V_22 =
F_7 ( V_19 , struct V_21 ,
V_19 ) ;
V_17 = F_8 ( V_22 ) ;
} else if ( F_9 ( V_19 ) ) {
struct V_23 * V_24 =
F_7 ( V_19 ,
struct V_23 ,
V_19 ) ;
V_17 = F_10 ( V_24 ) ;
}
if ( V_17 && V_17 -> V_25 )
V_17 -> V_25 ( V_17 , V_10 -> V_20 , V_8 ) ;
}
}
return 0 ;
}
static void F_11 ( struct V_26 * V_27 )
{
unsigned int V_3 ;
F_12 ( & V_27 -> V_28 ) ;
for ( V_3 = 0 ; V_3 < V_27 -> V_29 -> V_30 ; V_3 ++ ) {
if ( V_27 -> V_17 [ V_3 ] && V_27 -> V_17 [ V_3 ] -> V_31 )
V_27 -> V_17 [ V_3 ] -> V_31 ( V_27 -> V_17 [ V_3 ] ) ;
V_27 -> V_17 [ V_3 ] = NULL ;
}
F_13 ( & V_27 -> V_32 ) ;
F_14 ( & V_27 -> V_28 ) ;
}
struct V_6 * F_15 ( T_2 V_33 , const unsigned long * V_34 )
{
struct V_6 * V_35 ;
unsigned int V_3 ;
V_35 = F_16 ( V_33 , sizeof( * V_35 ) , V_36 ) ;
if ( ! V_35 )
return F_17 ( - V_37 ) ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
V_35 [ V_3 ] . V_38 = V_3 ;
V_35 [ V_3 ] . V_11 = V_34 [ V_3 ] ;
}
return V_35 ;
}
static void F_18 ( struct V_16 * V_17 )
{
F_19 ( V_17 -> V_39 ) ;
F_20 ( V_17 -> V_39 ) ;
F_21 ( V_17 -> V_35 ) ;
F_22 ( V_17 -> V_39 ) ;
F_22 ( V_17 ) ;
}
static struct V_16 * F_23 ( struct V_40 * V_32 ,
const char * const V_41 ,
T_2 V_33 ,
const unsigned long * V_34 )
{
struct V_16 * V_17 ;
int V_42 ;
V_17 = F_24 ( sizeof( * V_17 ) , V_36 ) ;
if ( ! V_17 )
return F_17 ( - V_37 ) ;
V_17 -> V_39 = F_24 ( sizeof( * V_17 -> V_39 ) , V_36 ) ;
if ( ! V_17 -> V_39 ) {
V_42 = - V_37 ;
goto V_43;
}
V_17 -> V_35 = F_15 ( V_33 , V_34 ) ;
if ( F_25 ( V_17 -> V_35 ) ) {
V_42 = F_26 ( V_17 -> V_35 ) ;
goto V_44;
}
V_17 -> V_39 -> V_41 = V_41 ;
V_17 -> V_39 -> V_45 = V_46 ;
V_42 = F_27 ( V_17 -> V_39 , V_33 , V_17 -> V_35 ) ;
if ( V_42 )
goto V_47;
V_42 = F_28 ( V_32 -> V_28 , V_17 -> V_39 ) ;
if ( V_42 )
goto V_48;
V_17 -> V_31 = F_18 ;
return V_17 ;
V_48:
F_20 ( V_17 -> V_39 ) ;
V_47:
F_21 ( V_17 -> V_35 ) ;
V_44:
F_22 ( V_17 -> V_39 ) ;
V_43:
F_22 ( V_17 ) ;
return F_17 ( V_42 ) ;
}
static int F_29 ( struct V_26 * V_27 )
{
unsigned int V_3 ;
int V_42 ;
V_27 -> V_17 = F_30 ( V_27 -> V_28 . V_49 , V_27 -> V_29 -> V_30 ,
sizeof( * V_27 -> V_17 ) , V_36 ) ;
if ( ! V_27 -> V_17 )
return - V_37 ;
V_27 -> V_32 . V_28 = & V_27 -> V_28 ;
V_42 = F_31 ( V_27 -> V_28 . V_49 , & V_27 -> V_32 ) ;
if ( V_42 ) {
F_32 ( V_27 -> V_28 . V_49 ,
L_1 , V_42 ) ;
return V_42 ;
}
for ( V_3 = 0 ; V_3 < V_27 -> V_29 -> V_30 ; V_3 ++ ) {
struct V_16 * ( * V_50 ) ( struct V_40 * ,
const char * const ,
T_2 ,
const unsigned long * ) ;
switch ( V_27 -> V_29 -> V_51 [ V_3 ] . V_52 ) {
case V_53 :
V_50 = V_54 ;
break;
case V_55 :
V_50 = V_56 ;
break;
case V_57 :
case V_58 :
case V_59 :
default:
V_50 = F_23 ;
break;
}
V_27 -> V_17 [ V_3 ] = V_50 ( & V_27 -> V_32 ,
V_27 -> V_29 -> V_51 [ V_3 ] . V_41 ,
V_27 -> V_29 -> V_51 [ V_3 ] . V_60 ,
V_27 -> V_29 -> V_51 [ V_3 ] . V_34 ) ;
if ( F_25 ( V_27 -> V_17 [ V_3 ] ) ) {
V_42 = F_26 ( V_27 -> V_17 [ V_3 ] ) ;
V_27 -> V_17 [ V_3 ] = NULL ;
goto V_61;
}
}
for ( V_3 = 0 ; V_3 < V_27 -> V_29 -> V_62 ; V_3 ++ ) {
const struct V_63 * V_10 = & V_27 -> V_29 -> V_64 [ V_3 ] ;
V_42 = F_33 ( V_27 -> V_17 [ V_10 -> V_65 ] -> V_39 ,
V_10 -> V_66 ,
V_27 -> V_17 [ V_10 -> V_67 ] -> V_39 ,
V_10 -> V_68 ,
V_10 -> V_11 ) ;
if ( V_42 )
goto V_61;
}
V_42 = F_34 ( & V_27 -> V_28 ) ;
if ( V_42 ) {
F_32 ( V_27 -> V_28 . V_49 ,
L_2 , V_42 ) ;
return V_42 ;
}
V_42 = F_35 ( & V_27 -> V_32 ) ;
if ( V_42 ) {
F_32 ( V_27 -> V_28 . V_49 ,
L_3 ,
V_42 ) ;
goto V_61;
}
return 0 ;
V_61:
F_11 ( V_27 ) ;
return V_42 ;
}
static int F_36 ( struct V_69 * V_70 )
{
struct V_26 * V_27 ;
int V_42 ;
V_27 = F_24 ( sizeof( * V_27 ) , V_36 ) ;
if ( ! V_27 )
return - V_37 ;
V_27 -> V_29 = & V_29 ;
F_37 ( V_27 -> V_28 . V_71 , V_72 ,
sizeof( V_27 -> V_28 . V_71 ) ) ;
V_27 -> V_28 . V_49 = & V_70 -> V_49 ;
F_38 ( & V_27 -> V_28 ) ;
V_42 = F_29 ( V_27 ) ;
if ( V_42 ) {
F_32 ( V_27 -> V_28 . V_49 ,
L_4 , V_42 ) ;
F_22 ( V_27 ) ;
return V_42 ;
}
F_39 ( V_70 , V_27 ) ;
return 0 ;
}
static int F_40 ( struct V_69 * V_70 )
{
struct V_26 * V_27 = F_41 ( V_70 ) ;
F_11 ( V_27 ) ;
F_22 ( V_27 ) ;
return 0 ;
}
static void F_42 ( struct V_73 * V_49 )
{
}
static int T_3 F_43 ( void )
{
int V_42 ;
V_42 = F_44 ( & V_74 ) ;
if ( V_42 ) {
F_32 ( & V_74 . V_49 ,
L_5 , V_42 ) ;
return V_42 ;
}
V_42 = F_45 ( & V_75 ) ;
if ( V_42 ) {
F_32 ( & V_74 . V_49 ,
L_6 , V_42 ) ;
F_46 ( & V_74 ) ;
}
return V_42 ;
}
static void T_4 F_47 ( void )
{
F_48 ( & V_75 ) ;
F_46 ( & V_74 ) ;
}
