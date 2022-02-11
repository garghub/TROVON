struct V_1 * F_1 ( unsigned V_2 )
{
struct V_1 * V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( ! V_3 ) {
F_3 ( L_1 ) ;
return NULL ;
}
V_3 -> V_2 = V_2 ;
F_4 ( & V_3 -> V_5 , 0 ) ;
F_4 ( & V_3 -> V_6 , 0 ) ;
F_4 ( & V_3 -> V_7 , 0 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_5 ( & V_3 -> V_9 ) ;
V_3 -> V_10 = V_11 ;
V_3 -> V_12 = F_6 ( V_13 , 0 ) ;
if ( ! V_3 -> V_12 ) {
F_3 ( L_2 ) ;
F_7 ( V_3 ) ;
V_3 = NULL ;
}
return V_3 ;
}
void F_8 ( struct V_1 * V_3 )
{
F_9 ( V_3 -> V_12 ) ;
F_7 ( V_3 ) ;
}
static int F_10 ( T_1 V_14 , T_1 V_15 )
{
if ( F_11 ( V_14 ) < F_11 ( V_15 ) )
return - 1 ;
if ( F_11 ( V_15 ) < F_11 ( V_14 ) )
return 1 ;
return 0 ;
}
static bool F_12 ( struct V_1 * V_3 ,
struct V_13 * V_16 )
{
int V_17 ;
struct V_13 * V_18 ;
struct V_19 * * V_20 = & V_3 -> V_10 . V_19 , * V_21 = NULL ;
while ( * V_20 ) {
V_18 = F_13 ( * V_20 , struct V_13 , V_22 ) ;
V_21 = * V_20 ;
V_17 = F_10 ( V_18 -> V_23 . V_24 , V_16 -> V_23 . V_24 ) ;
if ( V_17 < 0 )
V_20 = & ( ( * V_20 ) -> V_25 ) ;
else if ( V_17 > 0 )
V_20 = & ( ( * V_20 ) -> V_26 ) ;
else
return false ;
}
F_14 ( & V_16 -> V_22 , V_21 , V_20 ) ;
F_15 ( & V_16 -> V_22 , & V_3 -> V_10 ) ;
return true ;
}
static struct V_13 * F_16 ( struct V_1 * V_3 ,
T_1 V_24 )
{
int V_17 ;
struct V_13 * V_18 ;
struct V_19 * * V_20 = & V_3 -> V_10 . V_19 ;
while ( * V_20 ) {
V_18 = F_13 ( * V_20 , struct V_13 , V_22 ) ;
V_17 = F_10 ( V_18 -> V_23 . V_24 , V_24 ) ;
if ( V_17 < 0 )
V_20 = & ( ( * V_20 ) -> V_25 ) ;
else if ( V_17 > 0 )
V_20 = & ( ( * V_20 ) -> V_26 ) ;
else
break;
}
return * V_20 ? V_18 : NULL ;
}
static void F_17 ( struct V_1 * V_3 , struct V_27 * V_18 , int V_28 )
{
switch ( V_18 -> V_29 ) {
case V_30 :
F_18 ( V_28 , & V_3 -> V_5 ) ;
break;
case V_31 :
F_18 ( V_28 , & V_3 -> V_7 ) ;
break;
case V_32 :
F_18 ( V_28 , & V_3 -> V_6 ) ;
break;
}
}
unsigned F_19 ( struct V_1 * V_3 )
{
return F_20 ( & V_3 -> V_6 ) ;
}
unsigned F_21 ( struct V_1 * V_3 )
{
return F_20 ( & V_3 -> V_7 ) ;
}
static bool F_22 ( struct V_1 * V_3 )
{
return false ;
}
int F_23 ( struct V_1 * V_3 ,
struct V_27 * V_23 ,
struct V_27 * * V_33 )
{
struct V_13 * V_18 ;
if ( V_33 )
* V_33 = NULL ;
if ( F_22 ( V_3 ) )
return - V_34 ;
V_18 = F_24 ( V_3 -> V_12 , V_35 ) ;
if ( ! V_18 )
return - V_34 ;
memcpy ( & V_18 -> V_23 , V_23 , sizeof( * V_23 ) ) ;
if ( ! F_12 ( V_3 , V_18 ) ) {
F_25 ( V_3 -> V_12 , V_18 ) ;
return - V_36 ;
}
if ( V_33 ) {
* V_33 = & V_18 -> V_23 ;
F_26 ( & V_18 -> V_37 , & V_3 -> V_8 ) ;
} else
F_26 ( & V_18 -> V_37 , & V_3 -> V_9 ) ;
F_17 ( V_3 , & V_18 -> V_23 , 1 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_3 , struct V_27 * * V_23 )
{
struct V_13 * V_18 ;
if ( F_28 ( & V_3 -> V_9 ) )
return - V_38 ;
V_18 = F_29 ( & V_3 -> V_9 , struct V_13 , V_37 ) ;
F_30 ( & V_18 -> V_37 , & V_3 -> V_8 ) ;
* V_23 = & V_18 -> V_23 ;
return 0 ;
}
void F_31 ( struct V_1 * V_3 ,
struct V_27 * V_29 )
{
struct V_13 * V_18 = F_13 ( V_29 , struct V_13 , V_23 ) ;
F_17 ( V_3 , & V_18 -> V_23 , - 1 ) ;
F_32 ( & V_18 -> V_22 , & V_3 -> V_10 ) ;
F_33 ( & V_18 -> V_37 ) ;
F_25 ( V_3 -> V_12 , V_18 ) ;
}
bool F_34 ( struct V_1 * V_3 ,
T_1 V_24 )
{
return F_16 ( V_3 , V_24 ) != NULL ;
}
