static const char * F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static const char * F_2 ( struct V_1 * V_2 )
{
return L_1 ;
}
static bool F_3 ( struct V_1 * V_2 )
{
return true ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_5 ( V_2 , F_6 ( * V_4 ) , V_5 ) ;
F_7 ( & V_4 -> V_6 ) ;
F_8 ( F_9 ( F_6 ( * V_4 ) , V_5 ) ) ;
F_10 ( & V_4 -> V_5 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
F_12 ( V_8 -> V_9 . V_10 ) ;
F_13 ( V_8 , V_11 ) ;
}
static void F_14 ( struct V_12 * V_13 )
{
struct V_4 * V_4 = F_5 ( V_13 , F_6 ( * V_4 ) , V_13 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
if ( F_15 ( V_8 ) ) {
F_16 ( L_2 ) ;
goto V_14;
}
F_11 ( V_8 ) ;
F_17 ( V_8 ) ;
V_14:
F_18 ( V_8 ) ;
F_19 ( & V_4 -> V_5 ) ;
F_20 ( & V_4 -> V_5 ) ;
}
static int T_1
F_21 ( struct V_15 * V_2 ,
enum V_16 V_17 )
{
struct V_4 * V_4 = F_5 ( V_2 , F_6 ( * V_4 ) , V_6 ) ;
switch ( V_17 ) {
case V_18 :
F_22 ( & V_4 -> V_13 ) ;
break;
case V_19 :
F_20 ( & V_4 -> V_5 ) ;
break;
}
return V_20 ;
}
bool F_23 ( struct V_7 * V_8 ,
unsigned int V_21 )
{
struct V_4 * V_4 ;
if ( ! F_24 ( V_8 ) ) {
V_8 -> V_22 = false ;
return false ;
}
if ( ! ( V_21 & V_23 ) &&
V_8 -> V_24 & V_25 )
return false ;
F_25 ( V_8 ) ;
V_4 = NULL ;
if ( ! ( V_21 & V_26 ) )
V_4 = F_26 ( sizeof( * V_4 ) , V_27 ) ;
if ( V_4 ) {
F_27 ( ! V_8 -> V_22 ) ;
F_28 ( & V_4 -> V_5 ,
& V_28 ,
& V_29 ,
F_29 ( V_8 -> V_30 . V_31 ) -> V_9 . V_32 ,
0 ) ;
F_30 ( & V_4 -> V_6 , F_21 ) ;
V_4 -> V_8 = F_31 ( V_8 ) ;
F_32 ( & V_4 -> V_13 , F_14 ) ;
F_33 ( & V_4 -> V_5 ) ;
F_34 ( & V_4 -> V_6 ,
V_8 -> V_33 , NULL ,
true , V_34 ,
V_27 ) ;
F_35 ( V_8 -> V_33 , NULL ) ;
F_36 ( V_8 -> V_33 , & V_4 -> V_5 ) ;
F_37 ( V_8 -> V_33 ) ;
F_38 ( & V_4 -> V_6 ) ;
} else if ( V_8 -> V_9 . V_10 ) {
F_11 ( V_8 ) ;
} else {
F_27 ( V_8 -> V_30 . V_35 != V_36 ) ;
}
V_8 -> V_22 = false ;
return true ;
}
