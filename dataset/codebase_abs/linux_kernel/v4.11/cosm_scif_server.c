static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != V_4 ) {
F_2 ( V_2 , V_2 -> V_3 ) ;
V_2 -> V_3 = V_4 ;
}
}
static void F_3 ( struct V_1 * V_2 ,
enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
break;
default:
F_4 ( & V_2 -> V_11 , L_1 ,
V_12 , __LINE__ , V_6 ) ;
return;
} ;
V_2 -> V_3 = V_6 ;
V_2 -> V_13 = false ;
if ( V_2 -> V_14 != V_15 )
F_5 ( V_2 , V_15 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_16 V_17 ;
int V_18 ;
while ( 1 ) {
V_18 = F_7 ( V_2 -> V_19 , & V_17 , sizeof( V_17 ) , 0 ) ;
if ( ! V_18 ) {
break;
} else if ( V_18 < 0 ) {
F_8 ( & V_2 -> V_11 , L_2 ,
V_12 , __LINE__ , V_18 ) ;
break;
}
F_8 ( & V_2 -> V_11 , L_3 ,
V_12 , __LINE__ , V_18 , V_17 . V_20 ) ;
switch ( V_17 . V_20 ) {
case V_21 :
F_3 ( V_2 , V_17 . V_6 ) ;
break;
case V_22 :
break;
default:
F_4 ( & V_2 -> V_11 , L_4 ,
V_12 , __LINE__ , V_17 . V_20 ) ;
break;
}
}
}
static void F_9 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_11 , L_5 ) ;
F_3 ( V_2 , V_10 ) ;
F_1 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_16 V_17 = { . V_20 = V_23 } ;
int V_18 ;
F_11 ( & V_17 . V_24 ) ;
V_18 = F_12 ( V_2 -> V_19 , & V_17 , sizeof( V_17 ) , V_25 ) ;
if ( V_18 < 0 )
F_4 ( & V_2 -> V_11 , L_6 ,
V_12 , __LINE__ , V_18 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_14 ( V_2 -> V_19 ) ;
V_2 -> V_19 = NULL ;
F_8 ( & V_2 -> V_11 , L_7 , V_12 , __LINE__ ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
if ( V_26 == V_2 -> V_14 || V_27 == V_2 -> V_14 ) {
V_2 -> V_13 = V_2 -> V_28 ;
V_2 -> V_19 = V_2 -> V_29 ;
if ( V_2 -> V_14 == V_26 )
F_5 ( V_2 , V_27 ) ;
F_10 ( V_2 ) ;
F_8 ( & V_2 -> V_11 , L_7 , V_12 , __LINE__ ) ;
} else {
F_16 ( & V_2 -> V_11 , L_8 ,
V_12 , __LINE__ , V_30 [ V_2 -> V_14 ] ) ;
V_18 = - V_31 ;
}
F_17 ( & V_2 -> V_11 ) ;
return V_18 ;
}
void F_18 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_19 ( V_33 , struct V_1 ,
V_34 ) ;
struct V_35 V_36 ;
int V_18 ;
F_20 ( & V_2 -> V_37 ) ;
if ( F_15 ( V_2 ) )
goto exit;
while ( 1 ) {
V_36 . V_19 = V_2 -> V_19 ;
V_36 . V_38 = V_39 ;
F_21 ( & V_2 -> V_37 ) ;
V_18 = F_22 ( & V_36 , 1 , V_40 ) ;
F_20 ( & V_2 -> V_37 ) ;
if ( V_18 < 0 ) {
F_4 ( & V_2 -> V_11 , L_9 ,
V_12 , __LINE__ , V_18 ) ;
continue;
}
if ( V_36 . V_41 & V_39 )
F_6 ( V_2 ) ;
if ( V_36 . V_41 & V_42 ) {
F_13 ( V_2 ) ;
break;
}
if ( ! V_18 && V_2 -> V_13 )
F_9 ( V_2 ) ;
}
exit:
F_8 ( & V_2 -> V_11 , L_10 , V_12 , __LINE__ ) ;
F_21 ( & V_2 -> V_37 ) ;
}
static int F_23 ( void * V_43 )
{
struct V_1 * V_2 ;
T_1 V_29 ;
struct V_44 V_45 ;
int V_18 ;
F_24 ( V_46 ) ;
while ( ! F_25 () ) {
V_18 = F_26 ( V_47 , & V_45 , & V_29 ,
V_48 ) ;
if ( V_18 < 0 ) {
if ( - V_49 != V_18 )
F_27 ( L_11 , V_12 , __LINE__ , V_18 ) ;
continue;
}
V_2 = F_28 ( V_45 . V_50 - 1 ) ;
if ( ! V_2 )
continue;
V_2 -> V_29 = V_29 ;
F_29 ( & V_2 -> V_34 ) ;
}
F_30 ( L_12 , V_12 , __LINE__ ) ;
return 0 ;
}
static int F_31 ( void )
{
int V_18 ;
V_47 = F_32 () ;
if ( ! V_47 ) {
F_27 ( L_13 , V_12 , __LINE__ ) ;
return - V_51 ;
}
V_18 = F_33 ( V_47 , V_52 ) ;
if ( V_18 < 0 ) {
F_27 ( L_14 ,
V_12 , __LINE__ , V_18 ) ;
goto V_53;
}
V_18 = F_34 ( V_47 , V_54 ) ;
if ( V_18 < 0 ) {
F_27 ( L_15 , V_12 , __LINE__ , V_18 ) ;
goto V_53;
}
F_30 ( L_16 , V_12 , __LINE__ ) ;
return 0 ;
V_53:
F_14 ( V_47 ) ;
V_47 = NULL ;
return V_18 ;
}
static void F_35 ( void )
{
F_30 ( L_17 , V_12 , __LINE__ ) ;
if ( V_47 ) {
F_14 ( V_47 ) ;
V_47 = NULL ;
}
}
int F_36 ( void )
{
int V_18 = F_31 () ;
if ( V_18 ) {
F_27 ( L_18 ,
V_12 , __LINE__ , V_18 ) ;
goto V_53;
}
V_55 = F_37 ( F_23 , NULL , L_19 ) ;
if ( F_38 ( V_55 ) ) {
V_18 = F_39 ( V_55 ) ;
F_27 ( L_20 , V_12 , __LINE__ , V_18 ) ;
goto V_56;
}
return 0 ;
V_56:
F_35 () ;
V_53:
return V_18 ;
}
void F_40 ( void )
{
int V_18 ;
if ( ! F_41 ( V_55 ) ) {
V_18 = F_42 ( V_46 , V_55 , 0 ) ;
if ( V_18 ) {
F_27 ( L_21 ,
V_12 , __LINE__ , V_18 ) ;
return;
}
F_43 ( V_55 ) ;
}
F_35 () ;
}
