void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_5 ;
F_2 ( & V_3 -> V_6 ) ;
F_3 ( & V_3 -> V_7 ) ;
}
void F_4 ( struct V_8 * V_9 )
{
struct V_10 * V_10 = & V_9 -> V_4 . V_10 ;
int V_11 ;
F_2 ( & V_10 -> V_12 ) ;
F_3 ( & V_10 -> V_13 ) ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ ) {
struct V_15 * V_16 = & V_10 -> V_17 [ V_11 ] ;
F_2 ( & V_16 -> V_18 ) ;
F_3 ( & V_16 -> V_19 ) ;
V_16 -> V_20 = V_11 ;
V_16 -> V_9 = NULL ;
V_16 -> V_21 = V_9 ;
V_16 -> V_22 = 1U << V_9 -> V_23 ;
F_5 ( & V_16 -> V_24 ) ;
if ( F_6 ( V_11 ) ) {
V_16 -> V_25 = 1 ;
V_16 -> V_26 = V_27 ;
} else {
V_16 -> V_26 = V_28 ;
}
}
}
int F_7 ( struct V_1 * V_1 , T_1 type )
{
int V_11 , V_29 = - 1 , V_30 ;
struct V_8 * V_9 ;
if ( F_8 ( V_1 ) )
return - V_31 ;
if ( type == V_32 &&
! V_33 . V_34 )
return - V_35 ;
V_30 = - V_36 ;
F_9 (i, vcpu, kvm) {
if ( ! F_10 ( & V_9 -> V_37 ) )
goto V_38;
V_29 = V_11 ;
}
F_9 (i, vcpu, kvm) {
if ( V_9 -> V_4 . V_39 )
goto V_38;
}
V_30 = 0 ;
if ( type == V_32 )
V_1 -> V_4 . V_40 = V_41 ;
else
V_1 -> V_4 . V_40 = V_42 ;
if ( F_11 ( & V_1 -> V_43 ) > V_1 -> V_4 . V_40 ) {
V_30 = - V_44 ;
goto V_38;
}
V_1 -> V_4 . V_5 . V_45 = true ;
V_1 -> V_4 . V_5 . V_46 = type ;
V_1 -> V_4 . V_5 . V_47 = V_33 . V_47 ;
V_1 -> V_4 . V_5 . V_48 = V_49 ;
V_1 -> V_4 . V_5 . V_50 = V_49 ;
V_1 -> V_4 . V_5 . V_51 = V_49 ;
V_38:
for (; V_29 >= 0 ; V_29 -- ) {
V_9 = F_12 ( V_1 , V_29 ) ;
F_13 ( & V_9 -> V_37 ) ;
}
return V_30 ;
}
static int F_14 ( struct V_1 * V_1 , unsigned int V_52 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_5 ;
struct V_8 * V_53 = F_12 ( V_1 , 0 ) ;
int V_11 ;
V_3 -> V_54 = F_15 ( V_52 , sizeof( struct V_15 ) , V_55 ) ;
if ( ! V_3 -> V_54 )
return - V_56 ;
for ( V_11 = 0 ; V_11 < V_52 ; V_11 ++ ) {
struct V_15 * V_16 = & V_3 -> V_54 [ V_11 ] ;
V_16 -> V_20 = V_11 + V_14 ;
F_2 ( & V_16 -> V_18 ) ;
F_3 ( & V_16 -> V_19 ) ;
V_16 -> V_9 = NULL ;
V_16 -> V_21 = V_53 ;
F_5 ( & V_16 -> V_24 ) ;
if ( V_3 -> V_46 == V_32 )
V_16 -> V_22 = 0 ;
else
V_16 -> V_57 = 0 ;
}
return 0 ;
}
int F_16 ( struct V_8 * V_9 )
{
int V_30 = 0 ;
struct V_2 * V_3 = & V_9 -> V_1 -> V_4 . V_5 ;
if ( ! F_8 ( V_9 -> V_1 ) )
return 0 ;
if ( V_3 -> V_46 == V_58 ) {
F_17 ( & V_9 -> V_1 -> V_59 ) ;
V_30 = F_18 ( V_9 ) ;
F_13 ( & V_9 -> V_1 -> V_59 ) ;
}
return V_30 ;
}
static void F_19 ( struct V_8 * V_9 )
{
if ( V_33 . type == V_60 )
F_20 ( V_9 ) ;
else
F_21 ( V_9 ) ;
}
int F_22 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_5 ;
struct V_8 * V_9 ;
int V_30 = 0 , V_11 ;
if ( F_23 ( V_1 ) )
return 0 ;
if ( ! V_3 -> V_52 )
V_3 -> V_52 = V_61 - V_14 ;
V_30 = F_14 ( V_1 , V_3 -> V_52 ) ;
if ( V_30 )
goto V_62;
if ( F_24 ( V_1 ) )
V_3 -> V_63 = true ;
F_9 (i, vcpu, kvm)
F_19 ( V_9 ) ;
V_30 = F_25 ( V_1 ) ;
if ( V_30 )
goto V_62;
F_26 ( V_1 ) ;
V_3 -> V_64 = true ;
F_27 () ;
V_9 = F_28 () ;
if ( V_9 )
F_29 ( V_9 ) ;
F_30 () ;
V_62:
return V_30 ;
}
static void F_31 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_5 ;
V_3 -> V_65 = false ;
V_3 -> V_64 = false ;
F_32 ( V_3 -> V_54 ) ;
V_3 -> V_52 = 0 ;
}
void F_33 ( struct V_8 * V_9 )
{
struct V_10 * V_10 = & V_9 -> V_4 . V_10 ;
F_2 ( & V_10 -> V_12 ) ;
}
static void F_34 ( struct V_1 * V_1 )
{
struct V_8 * V_9 ;
int V_11 ;
F_35 ( V_1 ) ;
F_31 ( V_1 ) ;
F_9 (i, vcpu, kvm)
F_33 ( V_9 ) ;
}
void F_36 ( struct V_1 * V_1 )
{
F_17 ( & V_1 -> V_59 ) ;
F_34 ( V_1 ) ;
F_13 ( & V_1 -> V_59 ) ;
}
int F_37 ( struct V_1 * V_1 )
{
int V_30 = 0 ;
if ( F_38 ( ! F_23 ( V_1 ) ) ) {
if ( V_1 -> V_4 . V_5 . V_46 != V_32 )
return - V_36 ;
F_17 ( & V_1 -> V_59 ) ;
V_30 = F_22 ( V_1 ) ;
F_13 ( & V_1 -> V_59 ) ;
}
return V_30 ;
}
int F_39 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_5 ;
int V_30 = 0 ;
F_17 ( & V_1 -> V_59 ) ;
if ( ! F_8 ( V_1 ) )
goto V_62;
if ( V_3 -> V_46 == V_32 )
V_30 = F_40 ( V_1 ) ;
else
V_30 = F_41 ( V_1 ) ;
if ( V_30 )
F_34 ( V_1 ) ;
V_62:
F_13 ( & V_1 -> V_59 ) ;
return V_30 ;
}
static int F_42 ( unsigned int V_66 )
{
F_43 ( V_33 . V_67 , 0 ) ;
return 0 ;
}
static int F_44 ( unsigned int V_66 )
{
F_45 ( V_33 . V_67 ) ;
return 0 ;
}
static T_2 F_46 ( int V_16 , void * V_68 )
{
return V_69 ;
}
void F_47 ( void )
{
F_48 ( F_49 () ) ;
if ( V_33 . type == V_60 )
F_50 () ;
else
F_51 ( V_70 ) ;
}
int F_52 ( void )
{
const struct V_71 * V_71 ;
int V_30 ;
V_71 = F_53 () ;
if ( ! V_71 )
return - V_35 ;
if ( ! V_71 -> V_67 ) {
F_54 ( L_1 ) ;
return - V_72 ;
}
switch ( V_71 -> type ) {
case V_73 :
V_30 = F_55 ( V_71 ) ;
break;
case V_74 :
V_30 = F_56 ( V_71 ) ;
if ( ! V_30 ) {
F_57 ( & V_33 . V_75 ) ;
F_58 ( L_2 ) ;
}
break;
default:
V_30 = - V_35 ;
} ;
if ( V_30 )
return V_30 ;
V_33 . V_67 = V_71 -> V_67 ;
V_30 = F_59 ( V_33 . V_67 ,
F_46 ,
L_3 , F_60 () ) ;
if ( V_30 ) {
F_54 ( L_4 ,
V_33 . V_67 ) ;
return V_30 ;
}
V_30 = F_61 ( V_76 ,
L_5 ,
F_42 , F_44 ) ;
if ( V_30 ) {
F_54 ( L_6 ) ;
goto V_77;
}
F_58 ( L_7 , V_33 . V_67 ) ;
return 0 ;
V_77:
F_62 ( V_33 . V_67 ,
F_60 () ) ;
return V_30 ;
}
