static bool F_1 ( struct V_1 * V_2 )
{
const T_1 V_3 = F_2 ( & V_2 -> V_4 -> V_5 . V_6 . V_3 ) ;
return ( V_3 & V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_2 V_8 ;
bool V_9 = true ;
struct V_10 T_3 * V_11 ;
V_11 = & V_2 -> V_4 -> V_5 . V_6 ;
V_8 = F_4 ( & V_11 -> V_12 ) ;
if ( F_5 ( V_8 == 0 || V_8 > V_13 ) ) {
F_6 ( L_1 , V_8 ) ;
V_9 = false ;
} else {
F_7 ( V_2 -> V_14 , V_2 -> V_4 -> V_15 , V_8 ) ;
}
F_8 ( V_16 , & V_11 -> V_3 ) ;
F_2 ( & V_11 -> V_3 ) ;
V_2 -> V_17 . V_18 ( V_2 -> V_17 . V_19 ) ;
if ( F_9 ( V_9 ) ) {
V_2 -> V_20 ++ ;
V_2 -> V_21 . V_18 ( V_2 -> V_21 . V_19 , V_2 -> V_14 , V_8 ) ;
}
}
static void F_10 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_11 ( V_23 , struct V_1 ,
V_24 ) ;
while ( F_1 ( V_2 ) )
F_3 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( & V_2 -> V_4 -> V_5 . V_6 . V_3 ) ;
if ( V_3 & V_7 )
F_13 ( V_2 -> V_25 , & V_2 -> V_24 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( ! F_15 ( V_2 -> V_26 ) )
return;
V_3 = F_2 ( & V_2 -> V_4 -> V_5 . V_6 . V_3 ) ;
if ( V_3 & V_16 ) {
F_16 ( V_2 -> V_26 , 0 ) ;
F_17 ( & V_2 -> V_27 ) ;
}
}
int F_18 ( struct V_1 * V_2 ,
enum V_28 V_29 ,
struct V_30 T_3 * V_4 ,
struct V_31 * V_25 ,
const struct V_32 * V_17 ,
const struct V_33 * V_21 )
{
F_19 ( F_20 ( struct V_30 , V_15 ) !=
V_34 ) ;
F_19 ( sizeof( struct V_30 ) > V_35 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_17 = * V_17 ;
V_2 -> V_21 = * V_21 ;
V_2 -> V_36 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_26 = 0 ;
V_2 -> V_37 = 0 ;
switch ( V_29 ) {
case V_38 :
V_2 -> V_39 = F_14 ;
break;
case V_40 :
V_2 -> V_39 = F_12 ;
break;
default:
return - V_41 ;
}
F_21 ( & V_2 -> V_24 , F_10 ) ;
F_22 ( & V_2 -> V_27 ) ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_24 ( & V_2 -> V_27 ) ;
}
int F_25 ( struct V_1 * V_2 , const T_4 * V_42 , T_2 V_8 )
{
int V_43 = 0 ;
struct V_10 T_3 * V_11 ;
V_11 = & V_2 -> V_4 -> V_5 . V_6 ;
if ( F_5 ( V_8 > V_13 ) )
return - V_44 ;
V_2 -> V_36 ++ ;
F_26 ( V_8 , & V_11 -> V_12 ) ;
F_27 ( V_2 -> V_4 -> V_15 , V_42 , V_8 ) ;
F_28 () ;
F_16 ( V_2 -> V_26 , 1 ) ;
F_29 () ;
F_8 ( V_7 , & V_11 -> V_3 ) ;
F_2 ( & V_11 -> V_3 ) ;
V_2 -> V_17 . V_18 ( V_2 -> V_17 . V_19 ) ;
if ( ! F_30 ( & V_2 -> V_27 ,
V_45 ) ) {
V_43 = - V_46 ;
V_2 -> V_37 ++ ;
F_6 ( L_2 ) ;
}
F_16 ( V_2 -> V_26 , 0 ) ;
return V_43 ;
}
