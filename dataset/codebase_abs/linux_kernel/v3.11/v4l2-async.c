static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#if F_2 ( V_5 )
struct V_6 * V_7 = F_3 ( V_2 ) ;
return V_7 &&
V_4 -> V_8 == V_9 &&
V_4 -> V_10 . V_11 . V_12 == V_7 -> V_13 -> V_14 &&
V_4 -> V_10 . V_11 . V_15 == V_7 -> V_16 ;
#else
return false ;
#endif
}
static bool F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return V_4 -> V_8 == V_17 &&
! strcmp ( V_4 -> V_10 . V_18 . V_19 , F_5 ( V_2 ) ) ;
}
static struct V_3 * F_6 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = F_7 ( V_23 ) ;
struct V_3 * V_4 ;
bool (* V_10)( struct V_1 * ,
struct V_3 * );
F_8 (asd, &notifier->waiting, list) {
switch ( V_4 -> V_8 ) {
case V_26 :
V_10 = V_4 -> V_10 . V_27 . V_10 ;
if ( ! V_10 )
return V_4 ;
break;
case V_17 :
V_10 = F_4 ;
break;
case V_9 :
V_10 = F_1 ;
break;
default:
F_9 ( true ) ;
return NULL ;
}
if ( V_10 ( V_25 -> V_2 , V_4 ) )
return V_4 ;
}
return NULL ;
}
static int F_10 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_3 * V_4 )
{
struct V_24 * V_25 = F_7 ( V_23 ) ;
int V_28 ;
F_11 ( & V_4 -> V_29 ) ;
V_23 -> V_4 = V_4 ;
V_23 -> V_21 = V_21 ;
if ( V_21 -> V_30 ) {
V_28 = V_21 -> V_30 ( V_21 , V_25 , V_4 ) ;
if ( V_28 < 0 )
return V_28 ;
}
F_12 ( & V_23 -> V_29 , & V_21 -> V_31 ) ;
V_28 = F_13 ( V_21 -> V_32 , V_25 ) ;
if ( V_28 < 0 ) {
if ( V_21 -> V_33 )
V_21 -> V_33 ( V_21 , V_25 , V_4 ) ;
return V_28 ;
}
if ( F_14 ( & V_21 -> V_34 ) && V_21 -> V_35 )
return V_21 -> V_35 ( V_21 ) ;
return 0 ;
}
static void F_15 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_7 ( V_23 ) ;
F_16 ( V_25 ) ;
F_17 ( & V_23 -> V_29 ) ;
V_23 -> V_4 = NULL ;
V_25 -> V_2 = NULL ;
}
int F_18 ( struct V_36 * V_32 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 , * V_37 ;
struct V_3 * V_4 ;
int V_38 ;
if ( ! V_21 -> V_39 || V_21 -> V_39 > V_40 )
return - V_41 ;
V_21 -> V_32 = V_32 ;
F_19 ( & V_21 -> V_34 ) ;
F_19 ( & V_21 -> V_31 ) ;
for ( V_38 = 0 ; V_38 < V_21 -> V_39 ; V_38 ++ ) {
V_4 = V_21 -> V_42 [ V_38 ] ;
switch ( V_4 -> V_8 ) {
case V_26 :
case V_17 :
case V_9 :
break;
default:
F_20 ( V_21 -> V_32 ? V_21 -> V_32 -> V_2 : NULL ,
L_1 ,
V_4 -> V_8 , V_4 ) ;
return - V_41 ;
}
F_21 ( & V_4 -> V_29 , & V_21 -> V_34 ) ;
}
F_22 ( & V_43 ) ;
F_23 ( & V_21 -> V_29 , & V_44 ) ;
F_24 (asdl, tmp, &subdev_list, list) {
int V_28 ;
V_4 = F_6 ( V_21 , V_23 ) ;
if ( ! V_4 )
continue;
V_28 = F_10 ( V_21 , V_23 , V_4 ) ;
if ( V_28 < 0 ) {
F_25 ( & V_43 ) ;
return V_28 ;
}
}
F_25 ( & V_43 ) ;
return 0 ;
}
void F_26 ( struct V_20 * V_21 )
{
struct V_22 * V_23 , * V_37 ;
unsigned int V_45 = V_21 -> V_39 ;
unsigned int V_46 = F_27 ( V_45 , V_40 ) ;
struct V_1 * V_2 [ V_46 ] ;
int V_38 = 0 ;
F_22 ( & V_43 ) ;
F_11 ( & V_21 -> V_29 ) ;
F_24 (asdl, tmp, &notifier->done, list) {
struct V_24 * V_25 = F_7 ( V_23 ) ;
V_2 [ V_38 ] = F_28 ( V_25 -> V_2 ) ;
F_15 ( V_23 ) ;
F_29 ( V_2 [ V_38 ++ ] ) ;
if ( V_21 -> V_33 )
V_21 -> V_33 ( V_21 , V_25 , V_25 -> V_23 . V_4 ) ;
}
F_25 ( & V_43 ) ;
while ( V_38 -- ) {
struct V_1 * V_47 = V_2 [ V_38 ] ;
if ( V_47 && F_30 ( V_47 ) < 0 ) {
const char * V_19 = L_2 ;
int V_48 = F_31 ( V_47 ) ;
if ( V_48 && V_47 -> V_49 )
V_19 = V_47 -> V_49 -> V_19 ;
F_20 ( V_47 , L_3 , V_19 ) ;
if ( V_48 )
F_32 ( V_47 ) ;
}
F_33 ( V_47 ) ;
}
}
int F_34 ( struct V_24 * V_25 )
{
struct V_22 * V_23 = & V_25 -> V_23 ;
struct V_20 * V_21 ;
F_22 ( & V_43 ) ;
F_19 ( & V_23 -> V_29 ) ;
F_8 (notifier, &notifier_list, list) {
struct V_3 * V_4 = F_6 ( V_21 , V_23 ) ;
if ( V_4 ) {
int V_28 = F_10 ( V_21 , V_23 , V_4 ) ;
F_25 ( & V_43 ) ;
return V_28 ;
}
}
F_23 ( & V_23 -> V_29 , & V_50 ) ;
F_25 ( & V_43 ) ;
return 0 ;
}
void F_35 ( struct V_24 * V_25 )
{
struct V_22 * V_23 = & V_25 -> V_23 ;
struct V_20 * V_21 = V_23 -> V_21 ;
if ( ! V_23 -> V_4 ) {
if ( ! F_14 ( & V_23 -> V_29 ) )
F_15 ( V_23 ) ;
return;
}
F_22 ( & V_43 ) ;
F_23 ( & V_23 -> V_4 -> V_29 , & V_21 -> V_34 ) ;
F_15 ( V_23 ) ;
if ( V_21 -> V_33 )
V_21 -> V_33 ( V_21 , V_25 , V_25 -> V_23 . V_4 ) ;
F_25 ( & V_43 ) ;
}
