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
F_4 ( & V_1 -> V_7 ) ;
if ( F_5 ( V_1 ) ) {
V_6 = - V_8 ;
goto V_9;
}
if ( type == V_10 &&
! V_11 . V_12 ) {
V_6 = - V_13 ;
goto V_9;
}
V_6 = - V_14 ;
F_6 (i, vcpu, kvm) {
if ( ! F_7 ( & V_3 -> V_15 ) )
goto V_16;
V_5 = V_4 ;
}
F_6 (i, vcpu, kvm) {
if ( V_3 -> V_17 . V_18 )
goto V_16;
}
V_6 = 0 ;
if ( type == V_10 )
V_1 -> V_17 . V_19 = V_20 ;
else
V_1 -> V_17 . V_19 = V_21 ;
if ( F_8 ( & V_1 -> V_22 ) > V_1 -> V_17 . V_19 ) {
V_6 = - V_23 ;
goto V_16;
}
V_1 -> V_17 . V_24 . V_25 = true ;
V_1 -> V_17 . V_24 . V_26 = type ;
V_1 -> V_17 . V_24 . V_27 = V_11 . V_27 ;
V_1 -> V_17 . V_24 . V_28 = V_29 ;
V_1 -> V_17 . V_24 . V_30 = V_29 ;
V_1 -> V_17 . V_24 . V_31 = V_29 ;
V_16:
for (; V_5 >= 0 ; V_5 -- ) {
V_3 = F_9 ( V_1 , V_5 ) ;
F_10 ( & V_3 -> V_15 ) ;
}
V_9:
F_10 ( & V_1 -> V_7 ) ;
return V_6 ;
}
static int F_11 ( struct V_1 * V_1 , unsigned int V_32 )
{
struct V_33 * V_34 = & V_1 -> V_17 . V_24 ;
struct V_2 * V_35 = F_9 ( V_1 , 0 ) ;
int V_4 ;
V_34 -> V_36 = F_12 ( V_32 , sizeof( struct V_37 ) , V_38 ) ;
if ( ! V_34 -> V_36 )
return - V_39 ;
for ( V_4 = 0 ; V_4 < V_32 ; V_4 ++ ) {
struct V_37 * V_40 = & V_34 -> V_36 [ V_4 ] ;
V_40 -> V_41 = V_4 + V_42 ;
F_13 ( & V_40 -> V_43 ) ;
F_14 ( & V_40 -> V_44 ) ;
V_40 -> V_3 = NULL ;
V_40 -> V_45 = V_35 ;
if ( V_34 -> V_26 == V_10 )
V_40 -> V_46 = 0 ;
else
V_40 -> V_47 = 0 ;
}
return 0 ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_48 * V_48 = & V_3 -> V_17 . V_48 ;
int V_4 ;
F_13 ( & V_48 -> V_49 ) ;
F_14 ( & V_48 -> V_50 ) ;
for ( V_4 = 0 ; V_4 < V_42 ; V_4 ++ ) {
struct V_37 * V_40 = & V_48 -> V_51 [ V_4 ] ;
F_13 ( & V_40 -> V_43 ) ;
F_14 ( & V_40 -> V_44 ) ;
V_40 -> V_41 = V_4 ;
V_40 -> V_3 = NULL ;
V_40 -> V_45 = V_3 ;
V_40 -> V_46 = 1U << V_3 -> V_52 ;
if ( F_16 ( V_4 ) ) {
V_40 -> V_53 = 1 ;
V_40 -> V_54 = V_55 ;
} else {
V_40 -> V_54 = V_56 ;
}
}
if ( V_11 . type == V_57 )
F_17 ( V_3 ) ;
else
F_18 ( V_3 ) ;
}
int F_19 ( struct V_1 * V_1 )
{
struct V_33 * V_34 = & V_1 -> V_17 . V_24 ;
struct V_2 * V_3 ;
int V_6 = 0 , V_4 ;
if ( F_20 ( V_1 ) )
return 0 ;
if ( ! V_34 -> V_32 )
V_34 -> V_32 = V_58 - V_42 ;
V_6 = F_11 ( V_1 , V_34 -> V_32 ) ;
if ( V_6 )
goto V_9;
F_6 (i, vcpu, kvm)
F_15 ( V_3 ) ;
V_34 -> V_59 = true ;
V_9:
return V_6 ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_33 * V_34 = & V_1 -> V_17 . V_24 ;
F_4 ( & V_1 -> V_7 ) ;
V_34 -> V_60 = false ;
V_34 -> V_59 = false ;
F_22 ( V_34 -> V_36 ) ;
F_22 ( V_34 -> V_61 ) ;
V_34 -> V_32 = 0 ;
F_10 ( & V_1 -> V_7 ) ;
}
void F_23 ( struct V_2 * V_3 )
{
struct V_48 * V_48 = & V_3 -> V_17 . V_48 ;
F_13 ( & V_48 -> V_49 ) ;
}
void F_24 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
int V_4 ;
F_21 ( V_1 ) ;
F_6 (i, vcpu, kvm)
F_23 ( V_3 ) ;
}
int F_25 ( struct V_1 * V_1 )
{
int V_6 = 0 ;
if ( F_26 ( ! F_20 ( V_1 ) ) ) {
if ( V_1 -> V_17 . V_24 . V_26 != V_10 )
return - V_14 ;
F_4 ( & V_1 -> V_7 ) ;
V_6 = F_19 ( V_1 ) ;
F_10 ( & V_1 -> V_7 ) ;
}
return V_6 ;
}
int F_27 ( struct V_1 * V_1 )
{
struct V_33 * V_34 = & V_1 -> V_17 . V_24 ;
int V_6 = 0 ;
F_4 ( & V_1 -> V_7 ) ;
if ( ! F_5 ( V_1 ) )
goto V_9;
if ( V_34 -> V_26 == V_10 )
V_6 = F_28 ( V_1 ) ;
else
V_6 = F_29 ( V_1 ) ;
V_9:
F_10 ( & V_1 -> V_7 ) ;
return V_6 ;
}
static void F_30 ( void * V_62 )
{
F_31 ( V_11 . V_63 , 0 ) ;
}
static int F_32 ( struct V_64 * V_65 ,
unsigned long V_66 , void * V_67 )
{
switch ( V_66 ) {
case V_68 :
case V_69 :
F_30 ( NULL ) ;
break;
case V_70 :
case V_71 :
F_33 ( V_11 . V_63 ) ;
break;
}
return V_72 ;
}
static T_2 F_34 ( int V_40 , void * V_73 )
{
return V_74 ;
}
int F_35 ( void )
{
const struct V_75 * V_75 ;
int V_6 ;
V_75 = F_36 () ;
if ( ! V_75 )
return - V_13 ;
if ( ! V_75 -> V_63 ) {
F_37 ( L_1 ) ;
return - V_76 ;
}
switch ( V_75 -> type ) {
case V_77 :
V_6 = F_38 ( V_75 ) ;
break;
case V_78 :
V_6 = F_39 ( V_75 ) ;
break;
default:
V_6 = - V_13 ;
} ;
if ( V_6 )
return V_6 ;
V_11 . V_63 = V_75 -> V_63 ;
V_6 = F_40 ( V_11 . V_63 ,
F_34 ,
L_2 , F_41 () ) ;
if ( V_6 ) {
F_37 ( L_3 ,
V_11 . V_63 ) ;
return V_6 ;
}
V_6 = F_42 ( & V_79 ) ;
if ( V_6 ) {
F_37 ( L_4 ) ;
goto V_80;
}
F_43 ( F_30 , NULL , 1 ) ;
F_44 ( L_5 , V_11 . V_63 ) ;
return 0 ;
V_80:
F_45 ( V_11 . V_63 ,
F_41 () ) ;
return V_6 ;
}
