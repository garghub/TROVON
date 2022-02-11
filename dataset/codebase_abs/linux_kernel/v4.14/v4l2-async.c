static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#if F_2 ( V_5 )
struct V_6 * V_7 = F_3 ( V_2 -> V_8 ) ;
return V_7 &&
V_4 -> V_9 . V_10 . V_11 == V_7 -> V_12 -> V_13 &&
V_4 -> V_9 . V_10 . V_14 == V_7 -> V_15 ;
#else
return false ;
#endif
}
static bool F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! strcmp ( V_4 -> V_9 . V_16 . V_17 , F_5 ( V_2 -> V_8 ) ) ;
}
static bool F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return V_2 -> V_18 == V_4 -> V_9 . V_18 . V_18 ;
}
static bool F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! V_4 -> V_9 . V_19 . V_9 )
return true ;
return V_4 -> V_9 . V_19 . V_9 ( V_2 -> V_8 , V_4 ) ;
}
static struct V_3 * F_8 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
bool (* V_9)( struct V_1 * , struct V_3 * );
struct V_3 * V_4 ;
F_9 (asd, &notifier->waiting, list) {
switch ( V_4 -> V_22 ) {
case V_23 :
V_9 = F_7 ;
break;
case V_24 :
V_9 = F_4 ;
break;
case V_25 :
V_9 = F_1 ;
break;
case V_26 :
V_9 = F_6 ;
break;
default:
F_10 ( true ) ;
return NULL ;
}
if ( V_9 ( V_2 , V_4 ) )
return V_4 ;
}
return NULL ;
}
static int F_11 ( struct V_20 * V_21 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_27 ;
if ( V_21 -> V_28 ) {
V_27 = V_21 -> V_28 ( V_21 , V_2 , V_4 ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_27 = F_12 ( V_21 -> V_29 , V_2 ) ;
if ( V_27 < 0 ) {
if ( V_21 -> V_30 )
V_21 -> V_30 ( V_21 , V_2 , V_4 ) ;
return V_27 ;
}
F_13 ( & V_4 -> V_31 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_21 = V_21 ;
F_14 ( & V_2 -> V_32 , & V_21 -> V_33 ) ;
if ( F_15 ( & V_21 -> V_34 ) && V_21 -> V_35 )
return V_21 -> V_35 ( V_21 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
F_18 ( & V_2 -> V_32 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_8 = NULL ;
}
int F_19 ( struct V_36 * V_29 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 , * V_37 ;
struct V_3 * V_4 ;
int V_38 ;
if ( ! V_29 || ! V_21 -> V_39 ||
V_21 -> V_39 > V_40 )
return - V_41 ;
V_21 -> V_29 = V_29 ;
F_20 ( & V_21 -> V_34 ) ;
F_20 ( & V_21 -> V_33 ) ;
for ( V_38 = 0 ; V_38 < V_21 -> V_39 ; V_38 ++ ) {
V_4 = V_21 -> V_42 [ V_38 ] ;
switch ( V_4 -> V_22 ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
break;
default:
F_21 ( V_21 -> V_29 ? V_21 -> V_29 -> V_8 : NULL ,
L_1 ,
V_4 -> V_22 , V_4 ) ;
return - V_41 ;
}
F_22 ( & V_4 -> V_31 , & V_21 -> V_34 ) ;
}
F_23 ( & V_43 ) ;
F_24 (sd, tmp, &subdev_list, async_list) {
int V_27 ;
V_4 = F_8 ( V_21 , V_2 ) ;
if ( ! V_4 )
continue;
V_27 = F_11 ( V_21 , V_2 , V_4 ) ;
if ( V_27 < 0 ) {
F_25 ( & V_43 ) ;
return V_27 ;
}
}
F_26 ( & V_21 -> V_31 , & V_44 ) ;
F_25 ( & V_43 ) ;
return 0 ;
}
void F_27 ( struct V_20 * V_21 )
{
struct V_1 * V_2 , * V_37 ;
unsigned int V_45 = V_21 -> V_39 ;
unsigned int V_46 = F_28 ( V_45 , V_40 ) ;
struct V_47 * * V_8 ;
int V_38 = 0 ;
if ( ! V_21 -> V_29 )
return;
V_8 = F_29 ( V_46 , sizeof( * V_8 ) , V_48 ) ;
if ( ! V_8 ) {
F_21 ( V_21 -> V_29 -> V_8 ,
L_2 ) ;
}
F_23 ( & V_43 ) ;
F_13 ( & V_21 -> V_31 ) ;
F_24 (sd, tmp, &notifier->done, async_list) {
struct V_47 * V_49 ;
V_49 = F_30 ( V_2 -> V_8 ) ;
F_16 ( V_2 ) ;
F_31 ( V_49 ) ;
if ( V_21 -> V_30 )
V_21 -> V_30 ( V_21 , V_2 , V_2 -> V_4 ) ;
if ( V_8 )
V_8 [ V_38 ++ ] = V_49 ;
else
F_32 ( V_49 ) ;
}
F_25 ( & V_43 ) ;
while ( V_38 -- ) {
struct V_47 * V_49 = V_8 [ V_38 ] ;
if ( V_49 && F_33 ( V_49 ) < 0 ) {
const char * V_17 = L_3 ;
int V_50 = F_34 ( V_49 ) ;
if ( V_50 && V_49 -> V_51 )
V_17 = V_49 -> V_51 -> V_17 ;
F_21 ( V_49 , L_4 , V_17 ) ;
if ( V_50 )
F_35 ( V_49 ) ;
}
F_32 ( V_49 ) ;
}
F_36 ( V_8 ) ;
V_21 -> V_29 = NULL ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
if ( ! V_2 -> V_18 && V_2 -> V_8 )
V_2 -> V_18 = F_38 ( V_2 -> V_8 ) ;
F_23 ( & V_43 ) ;
F_20 ( & V_2 -> V_32 ) ;
F_9 (notifier, &notifier_list, list) {
struct V_3 * V_4 = F_8 ( V_21 , V_2 ) ;
if ( V_4 ) {
int V_27 = F_11 ( V_21 , V_2 , V_4 ) ;
F_25 ( & V_43 ) ;
return V_27 ;
}
}
F_26 ( & V_2 -> V_32 , & V_52 ) ;
F_25 ( & V_43 ) ;
return 0 ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
if ( ! V_2 -> V_4 ) {
if ( ! F_15 ( & V_2 -> V_32 ) )
F_16 ( V_2 ) ;
return;
}
F_23 ( & V_43 ) ;
F_26 ( & V_2 -> V_4 -> V_31 , & V_21 -> V_34 ) ;
F_16 ( V_2 ) ;
if ( V_21 -> V_30 )
V_21 -> V_30 ( V_21 , V_2 , V_2 -> V_4 ) ;
F_25 ( & V_43 ) ;
}
