T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
bool F_3 ( struct V_2 * V_3 )
{
F_4 ( ! F_5 ( & V_3 -> V_4 ) ) ;
return F_6 ( & V_3 -> V_5 ) ? true : false ;
}
void F_7 ( struct V_6 * V_7 )
{
F_8 ( & V_7 -> V_8 ) ;
}
void F_9 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
if ( F_10 ( & V_7 -> V_8 ) ) {
F_11 ( L_1 , V_9 , V_7 ) ;
if ( V_7 -> V_10 == V_11 )
F_12 ( & V_7 -> V_12 ) ;
F_4 ( ! F_6 ( & V_7 -> V_13 ) ) ;
F_13 ( V_7 -> V_14 ) ;
F_14 ( V_7 -> V_15 ) ;
F_15 ( V_16 , V_7 ) ;
}
}
struct V_17 * F_16 ( void )
{
return F_17 ( V_18 , V_19 ) ;
}
void F_18 ( struct V_17 * V_20 )
{
if ( V_20 )
F_15 ( V_18 , V_20 ) ;
}
struct V_21 * F_19 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_21 * V_22 ;
struct V_21 * V_23 = NULL ;
F_20 ( & V_7 -> V_24 ) ;
F_21 (lpriv, &event->private_data_list, event_list) {
if ( V_22 -> V_3 == V_3 ) {
V_23 = V_22 ;
F_22 ( & V_23 -> V_25 ) ;
break;
}
}
return V_23 ;
}
struct V_6 * F_23 ( struct V_2 * V_3 )
{
struct V_6 * V_7 ;
struct V_17 * V_20 ;
F_4 ( ! F_5 ( & V_3 -> V_4 ) ) ;
F_11 ( L_2 , V_9 , V_3 ) ;
V_20 = F_24 ( & V_3 -> V_5 , struct V_17 , V_25 ) ;
V_7 = V_20 -> V_7 ;
F_25 ( & V_7 -> V_24 ) ;
V_20 -> V_7 = NULL ;
F_26 ( & V_20 -> V_25 ) ;
F_27 ( & V_7 -> V_24 ) ;
if ( V_20 != & V_7 -> V_20 )
F_18 ( V_20 ) ;
V_3 -> V_26 -- ;
return V_7 ;
}
struct V_6 * F_28 ( struct V_2 * V_3 )
{
struct V_6 * V_7 ;
struct V_17 * V_20 ;
F_4 ( ! F_5 ( & V_3 -> V_4 ) ) ;
V_20 = F_24 ( & V_3 -> V_5 , struct V_17 , V_25 ) ;
V_7 = V_20 -> V_7 ;
return V_7 ;
}
void F_29 ( struct V_2 * V_3 )
{
struct V_6 * V_7 ;
struct V_21 * V_23 ;
F_30 ( & V_3 -> V_4 ) ;
while ( ! F_3 ( V_3 ) ) {
V_7 = F_23 ( V_3 ) ;
if ( V_3 -> V_27 -> V_28 ) {
F_25 ( & V_7 -> V_24 ) ;
V_23 = F_19 ( V_3 , V_7 ) ;
F_27 ( & V_7 -> V_24 ) ;
if ( V_23 )
V_3 -> V_27 -> V_28 ( V_23 ) ;
}
F_9 ( V_7 ) ;
}
F_31 ( & V_3 -> V_4 ) ;
}
static void F_32 ( struct V_6 * V_7 )
{
F_33 ( & V_7 -> V_20 . V_25 ) ;
F_34 ( & V_7 -> V_8 , 1 ) ;
F_35 ( & V_7 -> V_24 ) ;
F_33 ( & V_7 -> V_13 ) ;
}
int F_36 ( struct V_17 * V_29 ,
struct V_6 * V_30 )
{
struct V_6 * V_31 = V_29 -> V_7 ;
struct V_17 * V_32 = & V_30 -> V_20 ;
enum T_2 {
V_33 ,
V_34 ,
};
F_11 ( L_3 , V_9 , V_31 , V_30 ) ;
F_4 ( ! F_6 ( & V_32 -> V_25 ) ) ;
F_37 ( & V_31 -> V_24 , V_33 ) ;
F_37 ( & V_30 -> V_24 , V_34 ) ;
V_32 -> V_7 = V_30 ;
F_38 ( & V_29 -> V_25 , & V_32 -> V_25 ) ;
F_27 ( & V_30 -> V_24 ) ;
F_27 ( & V_31 -> V_24 ) ;
if ( V_29 != & V_31 -> V_20 )
F_18 ( V_29 ) ;
F_7 ( V_30 ) ;
F_9 ( V_31 ) ;
return 0 ;
}
struct V_6 * F_39 ( struct V_6 * V_31 )
{
struct V_6 * V_7 ;
V_7 = F_17 ( V_16 , V_19 ) ;
if ( ! V_7 )
return NULL ;
F_11 ( L_3 , V_9 , V_31 , V_7 ) ;
memcpy ( V_7 , V_31 , sizeof( * V_7 ) ) ;
F_32 ( V_7 ) ;
if ( V_7 -> V_35 ) {
V_7 -> V_14 = F_40 ( V_31 -> V_14 , V_19 ) ;
if ( ! V_7 -> V_14 ) {
F_15 ( V_16 , V_7 ) ;
return NULL ;
}
}
V_7 -> V_15 = F_41 ( V_31 -> V_15 ) ;
if ( V_7 -> V_10 == V_11 )
F_42 ( & V_7 -> V_12 ) ;
return V_7 ;
}
struct V_6 * F_43 ( struct V_36 * V_37 , T_3 V_38 , void * V_39 ,
int V_10 , const unsigned char * V_40 ,
T_1 V_41 , T_4 V_42 )
{
struct V_6 * V_7 ;
V_7 = F_44 ( V_16 , V_42 ) ;
if ( ! V_7 )
return NULL ;
F_11 ( L_4 ,
V_9 , V_7 , V_37 , V_38 , V_39 , V_10 ) ;
F_32 ( V_7 ) ;
if ( V_40 ) {
V_7 -> V_14 = F_40 ( V_40 , V_42 ) ;
if ( ! V_7 -> V_14 ) {
F_15 ( V_16 , V_7 ) ;
return NULL ;
}
V_7 -> V_35 = strlen ( V_7 -> V_14 ) ;
}
V_7 -> V_15 = F_41 ( F_45 ( V_43 ) ) ;
V_7 -> V_44 = V_41 ;
V_7 -> V_37 = V_37 ;
V_7 -> V_10 = V_10 ;
switch ( V_10 ) {
case V_11 : {
struct V_12 * V_12 = V_39 ;
V_7 -> V_12 . V_45 = V_12 -> V_45 ;
V_7 -> V_12 . V_46 = V_12 -> V_46 ;
F_42 ( & V_7 -> V_12 ) ;
break;
}
case V_47 :
V_7 -> V_36 = V_39 ;
break;
case V_48 :
V_7 -> V_36 = NULL ;
V_7 -> V_12 . V_45 = NULL ;
V_7 -> V_12 . V_46 = NULL ;
break;
default:
F_46 () ;
}
V_7 -> V_38 = V_38 ;
return V_7 ;
}
T_5 int F_47 ( void )
{
V_16 = F_48 ( V_6 , V_49 ) ;
V_18 = F_48 ( V_17 , V_49 ) ;
V_50 = F_43 ( NULL , V_51 , NULL ,
V_48 , NULL , 0 ,
V_19 ) ;
if ( ! V_50 )
F_49 ( L_5 ) ;
return 0 ;
}
