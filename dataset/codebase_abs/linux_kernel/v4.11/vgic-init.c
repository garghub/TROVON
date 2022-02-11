void F_1 ( struct V_1 * V_1 )
{
}
void F_2 ( struct V_2 * V_3 )
{
}
int F_3 ( struct V_1 * V_1 , T_1 type )
{
int V_4 , V_5 = - 1 , V_6 ;
struct V_2 * V_3 ;
if ( F_4 ( V_1 ) )
return - V_7 ;
if ( type == V_8 &&
! V_9 . V_10 )
return - V_11 ;
V_6 = - V_12 ;
F_5 (i, vcpu, kvm) {
if ( ! F_6 ( & V_3 -> V_13 ) )
goto V_14;
V_5 = V_4 ;
}
F_5 (i, vcpu, kvm) {
if ( V_3 -> V_15 . V_16 )
goto V_14;
}
V_6 = 0 ;
if ( type == V_8 )
V_1 -> V_15 . V_17 = V_18 ;
else
V_1 -> V_15 . V_17 = V_19 ;
if ( F_7 ( & V_1 -> V_20 ) > V_1 -> V_15 . V_17 ) {
V_6 = - V_21 ;
goto V_14;
}
V_1 -> V_15 . V_22 . V_23 = true ;
V_1 -> V_15 . V_22 . V_24 = type ;
V_1 -> V_15 . V_22 . V_25 = V_9 . V_25 ;
V_1 -> V_15 . V_22 . V_26 = V_27 ;
V_1 -> V_15 . V_22 . V_28 = V_27 ;
V_1 -> V_15 . V_22 . V_29 = V_27 ;
V_14:
for (; V_5 >= 0 ; V_5 -- ) {
V_3 = F_8 ( V_1 , V_5 ) ;
F_9 ( & V_3 -> V_13 ) ;
}
return V_6 ;
}
static int F_10 ( struct V_1 * V_1 , unsigned int V_30 )
{
struct V_31 * V_32 = & V_1 -> V_15 . V_22 ;
struct V_2 * V_33 = F_8 ( V_1 , 0 ) ;
int V_4 ;
F_11 ( & V_32 -> V_34 ) ;
F_12 ( & V_32 -> V_35 ) ;
V_32 -> V_36 = F_13 ( V_30 , sizeof( struct V_37 ) , V_38 ) ;
if ( ! V_32 -> V_36 )
return - V_39 ;
for ( V_4 = 0 ; V_4 < V_30 ; V_4 ++ ) {
struct V_37 * V_40 = & V_32 -> V_36 [ V_4 ] ;
V_40 -> V_41 = V_4 + V_42 ;
F_11 ( & V_40 -> V_43 ) ;
F_12 ( & V_40 -> V_44 ) ;
V_40 -> V_3 = NULL ;
V_40 -> V_45 = V_33 ;
F_14 ( & V_40 -> V_46 ) ;
if ( V_32 -> V_24 == V_8 )
V_40 -> V_47 = 0 ;
else
V_40 -> V_48 = 0 ;
}
return 0 ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_49 * V_49 = & V_3 -> V_15 . V_49 ;
int V_4 ;
F_11 ( & V_49 -> V_50 ) ;
F_12 ( & V_49 -> V_51 ) ;
for ( V_4 = 0 ; V_4 < V_42 ; V_4 ++ ) {
struct V_37 * V_40 = & V_49 -> V_52 [ V_4 ] ;
F_11 ( & V_40 -> V_43 ) ;
F_12 ( & V_40 -> V_44 ) ;
V_40 -> V_41 = V_4 ;
V_40 -> V_3 = NULL ;
V_40 -> V_45 = V_3 ;
V_40 -> V_47 = 1U << V_3 -> V_53 ;
F_14 ( & V_40 -> V_46 ) ;
if ( F_16 ( V_4 ) ) {
V_40 -> V_54 = 1 ;
V_40 -> V_55 = V_56 ;
} else {
V_40 -> V_55 = V_57 ;
}
}
if ( V_9 . type == V_58 )
F_17 ( V_3 ) ;
else
F_18 ( V_3 ) ;
}
int F_19 ( struct V_1 * V_1 )
{
struct V_31 * V_32 = & V_1 -> V_15 . V_22 ;
struct V_2 * V_3 ;
int V_6 = 0 , V_4 ;
if ( F_20 ( V_1 ) )
return 0 ;
if ( ! V_32 -> V_30 )
V_32 -> V_30 = V_59 - V_42 ;
V_6 = F_10 ( V_1 , V_32 -> V_30 ) ;
if ( V_6 )
goto V_60;
if ( F_21 ( V_1 ) )
V_32 -> V_61 = true ;
F_5 (i, vcpu, kvm)
F_15 ( V_3 ) ;
V_6 = F_22 ( V_1 ) ;
if ( V_6 )
goto V_60;
F_23 ( V_1 ) ;
V_32 -> V_62 = true ;
V_60:
return V_6 ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_31 * V_32 = & V_1 -> V_15 . V_22 ;
V_32 -> V_63 = false ;
V_32 -> V_62 = false ;
F_25 ( V_32 -> V_36 ) ;
V_32 -> V_30 = 0 ;
}
void F_26 ( struct V_2 * V_3 )
{
struct V_49 * V_49 = & V_3 -> V_15 . V_49 ;
F_11 ( & V_49 -> V_50 ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
int V_4 ;
F_28 ( V_1 ) ;
F_24 ( V_1 ) ;
F_5 (i, vcpu, kvm)
F_26 ( V_3 ) ;
}
void F_29 ( struct V_1 * V_1 )
{
F_30 ( & V_1 -> V_64 ) ;
F_27 ( V_1 ) ;
F_9 ( & V_1 -> V_64 ) ;
}
int F_31 ( struct V_1 * V_1 )
{
int V_6 = 0 ;
if ( F_32 ( ! F_20 ( V_1 ) ) ) {
if ( V_1 -> V_15 . V_22 . V_24 != V_8 )
return - V_12 ;
F_30 ( & V_1 -> V_64 ) ;
V_6 = F_19 ( V_1 ) ;
F_9 ( & V_1 -> V_64 ) ;
}
return V_6 ;
}
int F_33 ( struct V_1 * V_1 )
{
struct V_31 * V_32 = & V_1 -> V_15 . V_22 ;
int V_6 = 0 ;
F_30 ( & V_1 -> V_64 ) ;
if ( ! F_4 ( V_1 ) )
goto V_60;
if ( V_32 -> V_24 == V_8 )
V_6 = F_34 ( V_1 ) ;
else
V_6 = F_35 ( V_1 ) ;
if ( V_6 )
F_27 ( V_1 ) ;
V_60:
F_9 ( & V_1 -> V_64 ) ;
return V_6 ;
}
static int F_36 ( unsigned int V_65 )
{
F_37 ( V_9 . V_66 , 0 ) ;
return 0 ;
}
static int F_38 ( unsigned int V_65 )
{
F_39 ( V_9 . V_66 ) ;
return 0 ;
}
static T_2 F_40 ( int V_40 , void * V_67 )
{
return V_68 ;
}
void F_41 ( void )
{
F_42 ( F_43 () ) ;
if ( V_9 . type == V_58 )
F_44 () ;
else
F_45 ( V_69 ) ;
}
int F_46 ( void )
{
const struct V_70 * V_70 ;
int V_6 ;
V_70 = F_47 () ;
if ( ! V_70 )
return - V_11 ;
if ( ! V_70 -> V_66 ) {
F_48 ( L_1 ) ;
return - V_71 ;
}
switch ( V_70 -> type ) {
case V_72 :
V_6 = F_49 ( V_70 ) ;
break;
case V_73 :
V_6 = F_50 ( V_70 ) ;
if ( ! V_6 ) {
F_51 ( & V_9 . V_74 ) ;
F_52 ( L_2 ) ;
}
break;
default:
V_6 = - V_11 ;
} ;
if ( V_6 )
return V_6 ;
V_9 . V_66 = V_70 -> V_66 ;
V_6 = F_53 ( V_9 . V_66 ,
F_40 ,
L_3 , F_54 () ) ;
if ( V_6 ) {
F_48 ( L_4 ,
V_9 . V_66 ) ;
return V_6 ;
}
V_6 = F_55 ( V_75 ,
L_5 ,
F_36 , F_38 ) ;
if ( V_6 ) {
F_48 ( L_6 ) ;
goto V_76;
}
F_52 ( L_7 , V_9 . V_66 ) ;
return 0 ;
V_76:
F_56 ( V_9 . V_66 ,
F_54 () ) ;
return V_6 ;
}
