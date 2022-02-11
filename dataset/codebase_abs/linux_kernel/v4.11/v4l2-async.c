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
return ! F_7 ( F_8 ( V_2 -> V_18 ) ,
F_8 ( V_4 -> V_9 . V_19 . V_20 ) ) ;
}
static bool F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! V_4 -> V_9 . V_21 . V_9 )
return true ;
return V_4 -> V_9 . V_21 . V_9 ( V_2 -> V_8 , V_4 ) ;
}
static struct V_3 * F_10 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
bool (* V_9)( struct V_1 * , struct V_3 * );
struct V_3 * V_4 ;
F_11 (asd, &notifier->waiting, list) {
switch ( V_4 -> V_24 ) {
case V_25 :
V_9 = F_9 ;
break;
case V_26 :
V_9 = F_4 ;
break;
case V_27 :
V_9 = F_1 ;
break;
case V_28 :
V_9 = F_6 ;
break;
default:
F_12 ( true ) ;
return NULL ;
}
if ( V_9 ( V_2 , V_4 ) )
return V_4 ;
}
return NULL ;
}
static int F_13 ( struct V_22 * V_23 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_29 ;
if ( V_23 -> V_30 ) {
V_29 = V_23 -> V_30 ( V_23 , V_2 , V_4 ) ;
if ( V_29 < 0 )
return V_29 ;
}
V_29 = F_14 ( V_23 -> V_31 , V_2 ) ;
if ( V_29 < 0 ) {
if ( V_23 -> V_32 )
V_23 -> V_32 ( V_23 , V_2 , V_4 ) ;
return V_29 ;
}
F_15 ( & V_4 -> V_33 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_23 = V_23 ;
F_16 ( & V_2 -> V_34 , & V_23 -> V_35 ) ;
if ( F_17 ( & V_23 -> V_36 ) && V_23 -> V_37 )
return V_23 -> V_37 ( V_23 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_20 ( & V_2 -> V_34 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_8 = NULL ;
}
int F_21 ( struct V_38 * V_31 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 , * V_39 ;
struct V_3 * V_4 ;
int V_40 ;
if ( ! V_23 -> V_41 || V_23 -> V_41 > V_42 )
return - V_43 ;
V_23 -> V_31 = V_31 ;
F_22 ( & V_23 -> V_36 ) ;
F_22 ( & V_23 -> V_35 ) ;
for ( V_40 = 0 ; V_40 < V_23 -> V_41 ; V_40 ++ ) {
V_4 = V_23 -> V_44 [ V_40 ] ;
switch ( V_4 -> V_24 ) {
case V_25 :
case V_26 :
case V_27 :
case V_28 :
break;
default:
F_23 ( V_23 -> V_31 ? V_23 -> V_31 -> V_8 : NULL ,
L_1 ,
V_4 -> V_24 , V_4 ) ;
return - V_43 ;
}
F_24 ( & V_4 -> V_33 , & V_23 -> V_36 ) ;
}
F_25 ( & V_45 ) ;
F_26 (sd, tmp, &subdev_list, async_list) {
int V_29 ;
V_4 = F_10 ( V_23 , V_2 ) ;
if ( ! V_4 )
continue;
V_29 = F_13 ( V_23 , V_2 , V_4 ) ;
if ( V_29 < 0 ) {
F_27 ( & V_45 ) ;
return V_29 ;
}
}
F_28 ( & V_23 -> V_33 , & V_46 ) ;
F_27 ( & V_45 ) ;
return 0 ;
}
void F_29 ( struct V_22 * V_23 )
{
struct V_1 * V_2 , * V_39 ;
unsigned int V_47 = V_23 -> V_41 ;
unsigned int V_48 = F_30 ( V_47 , V_42 ) ;
struct V_49 * * V_8 ;
int V_40 = 0 ;
if ( ! V_23 -> V_31 )
return;
V_8 = F_31 ( V_48 , sizeof( * V_8 ) , V_50 ) ;
if ( ! V_8 ) {
F_23 ( V_23 -> V_31 -> V_8 ,
L_2 ) ;
}
F_25 ( & V_45 ) ;
F_15 ( & V_23 -> V_33 ) ;
F_26 (sd, tmp, &notifier->done, async_list) {
struct V_49 * V_51 ;
V_51 = F_32 ( V_2 -> V_8 ) ;
F_18 ( V_2 ) ;
F_33 ( V_51 ) ;
if ( V_23 -> V_32 )
V_23 -> V_32 ( V_23 , V_2 , V_2 -> V_4 ) ;
if ( V_8 )
V_8 [ V_40 ++ ] = V_51 ;
else
F_34 ( V_51 ) ;
}
F_27 ( & V_45 ) ;
while ( V_40 -- ) {
struct V_49 * V_51 = V_8 [ V_40 ] ;
if ( V_51 && F_35 ( V_51 ) < 0 ) {
const char * V_17 = L_3 ;
int V_52 = F_36 ( V_51 ) ;
if ( V_52 && V_51 -> V_53 )
V_17 = V_51 -> V_53 -> V_17 ;
F_23 ( V_51 , L_4 , V_17 ) ;
if ( V_52 )
F_37 ( V_51 ) ;
}
F_34 ( V_51 ) ;
}
F_38 ( V_8 ) ;
V_23 -> V_31 = NULL ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
if ( ! V_2 -> V_18 && V_2 -> V_8 )
V_2 -> V_18 = V_2 -> V_8 -> V_18 ;
F_25 ( & V_45 ) ;
F_22 ( & V_2 -> V_34 ) ;
F_11 (notifier, &notifier_list, list) {
struct V_3 * V_4 = F_10 ( V_23 , V_2 ) ;
if ( V_4 ) {
int V_29 = F_13 ( V_23 , V_2 , V_4 ) ;
F_27 ( & V_45 ) ;
return V_29 ;
}
}
F_28 ( & V_2 -> V_34 , & V_54 ) ;
F_27 ( & V_45 ) ;
return 0 ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
if ( ! V_2 -> V_4 ) {
if ( ! F_17 ( & V_2 -> V_34 ) )
F_18 ( V_2 ) ;
return;
}
F_25 ( & V_45 ) ;
F_28 ( & V_2 -> V_4 -> V_33 , & V_23 -> V_36 ) ;
F_18 ( V_2 ) ;
if ( V_23 -> V_32 )
V_23 -> V_32 ( V_23 , V_2 , V_2 -> V_4 ) ;
F_27 ( & V_45 ) ;
}
