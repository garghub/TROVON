static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#if F_2 ( V_5 )
struct V_6 * V_7 = F_3 ( V_2 ) ;
return V_7 &&
V_4 -> V_8 . V_9 . V_10 == V_7 -> V_11 -> V_12 &&
V_4 -> V_8 . V_9 . V_13 == V_7 -> V_14 ;
#else
return false ;
#endif
}
static bool F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return ! strcmp ( V_4 -> V_8 . V_15 . V_16 , F_5 ( V_2 ) ) ;
}
static bool F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return V_2 -> V_17 == V_4 -> V_8 . V_18 . V_19 ;
}
static struct V_3 * F_7 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_3 * V_4 ;
bool (* V_8)( struct V_1 * , struct V_3 * );
F_8 (asd, &notifier->waiting, list) {
switch ( V_4 -> V_24 ) {
case V_25 :
V_8 = V_4 -> V_8 . V_26 . V_8 ;
if ( ! V_8 )
return V_4 ;
break;
case V_27 :
V_8 = F_4 ;
break;
case V_28 :
V_8 = F_1 ;
break;
case V_29 :
V_8 = F_6 ;
break;
default:
F_9 ( true ) ;
return NULL ;
}
if ( V_8 ( V_23 -> V_2 , V_4 ) )
return V_4 ;
}
return NULL ;
}
static int F_10 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_3 * V_4 )
{
int V_30 ;
F_11 ( & V_4 -> V_31 ) ;
V_23 -> V_4 = V_4 ;
V_23 -> V_21 = V_21 ;
if ( V_21 -> V_32 ) {
V_30 = V_21 -> V_32 ( V_21 , V_23 , V_4 ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_12 ( & V_23 -> V_33 , & V_21 -> V_34 ) ;
V_30 = F_13 ( V_21 -> V_35 , V_23 ) ;
if ( V_30 < 0 ) {
if ( V_21 -> V_36 )
V_21 -> V_36 ( V_21 , V_23 , V_4 ) ;
return V_30 ;
}
if ( F_14 ( & V_21 -> V_37 ) && V_21 -> V_38 )
return V_21 -> V_38 ( V_21 ) ;
return 0 ;
}
static void F_15 ( struct V_22 * V_23 )
{
F_16 ( V_23 ) ;
F_17 ( & V_23 -> V_33 ) ;
V_23 -> V_4 = NULL ;
V_23 -> V_2 = NULL ;
}
int F_18 ( struct V_39 * V_35 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 , * V_40 ;
struct V_3 * V_4 ;
int V_41 ;
if ( ! V_21 -> V_42 || V_21 -> V_42 > V_43 )
return - V_44 ;
V_21 -> V_35 = V_35 ;
F_19 ( & V_21 -> V_37 ) ;
F_19 ( & V_21 -> V_34 ) ;
for ( V_41 = 0 ; V_41 < V_21 -> V_42 ; V_41 ++ ) {
V_4 = V_21 -> V_45 [ V_41 ] ;
switch ( V_4 -> V_24 ) {
case V_25 :
case V_27 :
case V_28 :
case V_29 :
break;
default:
F_20 ( V_21 -> V_35 ? V_21 -> V_35 -> V_2 : NULL ,
L_1 ,
V_4 -> V_24 , V_4 ) ;
return - V_44 ;
}
F_21 ( & V_4 -> V_31 , & V_21 -> V_37 ) ;
}
F_22 ( & V_46 ) ;
F_23 ( & V_21 -> V_31 , & V_47 ) ;
F_24 (sd, tmp, &subdev_list, async_list) {
int V_30 ;
V_4 = F_7 ( V_21 , V_23 ) ;
if ( ! V_4 )
continue;
V_30 = F_10 ( V_21 , V_23 , V_4 ) ;
if ( V_30 < 0 ) {
F_25 ( & V_46 ) ;
return V_30 ;
}
}
F_25 ( & V_46 ) ;
return 0 ;
}
void F_26 ( struct V_20 * V_21 )
{
struct V_22 * V_23 , * V_40 ;
unsigned int V_48 = V_21 -> V_42 ;
unsigned int V_49 = F_27 ( V_48 , V_43 ) ;
struct V_1 * V_2 [ V_49 ] ;
int V_41 = 0 ;
if ( ! V_21 -> V_35 )
return;
F_22 ( & V_46 ) ;
F_11 ( & V_21 -> V_31 ) ;
F_24 (sd, tmp, &notifier->done, async_list) {
V_2 [ V_41 ] = F_28 ( V_23 -> V_2 ) ;
F_15 ( V_23 ) ;
F_29 ( V_2 [ V_41 ++ ] ) ;
if ( V_21 -> V_36 )
V_21 -> V_36 ( V_21 , V_23 , V_23 -> V_4 ) ;
}
F_25 ( & V_46 ) ;
while ( V_41 -- ) {
struct V_1 * V_50 = V_2 [ V_41 ] ;
if ( V_50 && F_30 ( V_50 ) < 0 ) {
const char * V_16 = L_2 ;
int V_51 = F_31 ( V_50 ) ;
if ( V_51 && V_50 -> V_52 )
V_16 = V_50 -> V_52 -> V_16 ;
F_20 ( V_50 , L_3 , V_16 ) ;
if ( V_51 )
F_32 ( V_50 ) ;
}
F_33 ( V_50 ) ;
}
V_21 -> V_35 = NULL ;
}
int F_34 ( struct V_22 * V_23 )
{
struct V_20 * V_21 ;
F_22 ( & V_46 ) ;
F_19 ( & V_23 -> V_33 ) ;
F_8 (notifier, &notifier_list, list) {
struct V_3 * V_4 = F_7 ( V_21 , V_23 ) ;
if ( V_4 ) {
int V_30 = F_10 ( V_21 , V_23 , V_4 ) ;
F_25 ( & V_46 ) ;
return V_30 ;
}
}
F_23 ( & V_23 -> V_33 , & V_53 ) ;
F_25 ( & V_46 ) ;
return 0 ;
}
void F_35 ( struct V_22 * V_23 )
{
struct V_20 * V_21 = V_23 -> V_21 ;
if ( ! V_23 -> V_4 ) {
if ( ! F_14 ( & V_23 -> V_33 ) )
F_15 ( V_23 ) ;
return;
}
F_22 ( & V_46 ) ;
F_23 ( & V_23 -> V_4 -> V_31 , & V_21 -> V_37 ) ;
F_15 ( V_23 ) ;
if ( V_21 -> V_36 )
V_21 -> V_36 ( V_21 , V_23 , V_23 -> V_4 ) ;
F_25 ( & V_46 ) ;
}
