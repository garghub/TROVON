struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( 1 , sizeof( * V_4 ) ) ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = V_3 ;
return V_4 ;
}
struct V_1 * F_3 ( enum V_7 type , struct V_1 * V_8 )
{
struct V_1 * V_4 = F_2 ( 1 , sizeof( * V_4 ) ) ;
V_4 -> type = type ;
V_4 -> V_6 . V_1 = V_8 ;
return V_4 ;
}
struct V_1 * F_4 ( enum V_7 type , struct V_1 * V_9 , struct V_1 * V_10 )
{
struct V_1 * V_4 = F_2 ( 1 , sizeof( * V_4 ) ) ;
V_4 -> type = type ;
V_4 -> V_6 . V_1 = V_9 ;
V_4 -> V_11 . V_1 = V_10 ;
return V_4 ;
}
struct V_1 * F_5 ( enum V_7 type , struct V_2 * V_12 , struct V_2 * V_13 )
{
struct V_1 * V_4 = F_2 ( 1 , sizeof( * V_4 ) ) ;
V_4 -> type = type ;
V_4 -> V_6 . V_3 = V_12 ;
V_4 -> V_11 . V_3 = V_13 ;
return V_4 ;
}
struct V_1 * F_6 ( struct V_1 * V_9 , struct V_1 * V_10 )
{
if ( ! V_9 )
return V_10 ;
return V_10 ? F_4 ( V_14 , V_9 , V_10 ) : V_9 ;
}
struct V_1 * F_7 ( struct V_1 * V_9 , struct V_1 * V_10 )
{
if ( ! V_9 )
return V_10 ;
return V_10 ? F_4 ( V_15 , V_9 , V_10 ) : V_9 ;
}
struct V_1 * F_8 ( const struct V_1 * V_16 )
{
struct V_1 * V_4 ;
if ( ! V_16 )
return NULL ;
V_4 = xmalloc ( sizeof( * V_16 ) ) ;
memcpy ( V_4 , V_16 , sizeof( * V_16 ) ) ;
switch ( V_16 -> type ) {
case V_5 :
V_4 -> V_6 = V_16 -> V_6 ;
break;
case V_17 :
V_4 -> V_6 . V_1 = F_8 ( V_16 -> V_6 . V_1 ) ;
break;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
V_4 -> V_6 . V_3 = V_16 -> V_6 . V_3 ;
V_4 -> V_11 . V_3 = V_16 -> V_11 . V_3 ;
break;
case V_14 :
case V_15 :
case V_24 :
V_4 -> V_6 . V_1 = F_8 ( V_16 -> V_6 . V_1 ) ;
V_4 -> V_11 . V_1 = F_8 ( V_16 -> V_11 . V_1 ) ;
break;
default:
printf ( L_1 , V_4 -> type ) ;
free ( V_4 ) ;
V_4 = NULL ;
break;
}
return V_4 ;
}
void F_9 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return;
switch ( V_4 -> type ) {
case V_5 :
break;
case V_17 :
F_9 ( V_4 -> V_6 . V_1 ) ;
return;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
break;
case V_15 :
case V_14 :
F_9 ( V_4 -> V_6 . V_1 ) ;
F_9 ( V_4 -> V_11 . V_1 ) ;
break;
default:
printf ( L_2 , V_4 -> type ) ;
break;
}
free ( V_4 ) ;
}
static void F_10 ( enum V_7 type , struct V_1 * * V_25 , struct V_1 * * V_26 )
{
if ( V_9 -> type == type ) {
F_10 ( type , & V_9 -> V_6 . V_1 , & V_10 ) ;
F_10 ( type , & V_9 -> V_11 . V_1 , & V_10 ) ;
return;
}
if ( V_10 -> type == type ) {
F_10 ( type , & V_9 , & V_10 -> V_6 . V_1 ) ;
F_10 ( type , & V_9 , & V_10 -> V_11 . V_1 ) ;
return;
}
if ( V_9 -> type == V_5 && V_10 -> type == V_5 &&
V_9 -> V_6 . V_3 == V_10 -> V_6 . V_3 &&
( V_9 -> V_6 . V_3 == & V_27 || V_9 -> V_6 . V_3 == & V_28 ) )
return;
if ( ! F_11 ( V_9 , V_10 ) )
return;
V_29 ++ ;
F_9 ( V_9 ) ; F_9 ( V_10 ) ;
switch ( type ) {
case V_15 :
V_9 = F_1 ( & V_28 ) ;
V_10 = F_1 ( & V_28 ) ;
break;
case V_14 :
V_9 = F_1 ( & V_27 ) ;
V_10 = F_1 ( & V_27 ) ;
break;
default:
;
}
}
void F_12 ( struct V_1 * * V_25 , struct V_1 * * V_26 )
{
if ( ! V_9 || ! V_10 )
return;
switch ( V_9 -> type ) {
case V_15 :
case V_14 :
F_10 ( V_9 -> type , V_25 , V_26 ) ;
default:
;
}
if ( V_9 -> type != V_10 -> type ) switch ( V_10 -> type ) {
case V_15 :
case V_14 :
F_10 ( V_10 -> type , V_25 , V_26 ) ;
default:
;
}
V_9 = F_13 ( V_9 ) ;
V_10 = F_13 ( V_10 ) ;
}
static int F_11 ( struct V_1 * V_9 , struct V_1 * V_10 )
{
int V_30 , V_31 ;
if ( V_9 -> type != V_10 -> type )
return 0 ;
switch ( V_9 -> type ) {
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
return V_9 -> V_6 . V_3 == V_10 -> V_6 . V_3 && V_9 -> V_11 . V_3 == V_10 -> V_11 . V_3 ;
case V_5 :
return V_9 -> V_6 . V_3 == V_10 -> V_6 . V_3 ;
case V_17 :
return F_11 ( V_9 -> V_6 . V_1 , V_10 -> V_6 . V_1 ) ;
case V_14 :
case V_15 :
V_9 = F_8 ( V_9 ) ;
V_10 = F_8 ( V_10 ) ;
V_31 = V_29 ;
F_12 ( & V_9 , & V_10 ) ;
V_30 = ( V_9 -> type == V_5 && V_10 -> type == V_5 &&
V_9 -> V_6 . V_3 == V_10 -> V_6 . V_3 ) ;
F_9 ( V_9 ) ;
F_9 ( V_10 ) ;
V_29 = V_31 ;
return V_30 ;
case V_24 :
case V_32 :
case V_33 :
;
}
if ( V_34 ) {
F_14 ( V_9 , stdout ) ;
printf ( L_3 ) ;
F_14 ( V_10 , stdout ) ;
printf ( L_4 ) ;
}
return 0 ;
}
static struct V_1 * F_13 ( struct V_1 * V_4 )
{
struct V_1 * V_35 ;
if ( V_4 ) switch ( V_4 -> type ) {
case V_14 :
V_4 -> V_6 . V_1 = F_13 ( V_4 -> V_6 . V_1 ) ;
V_4 -> V_11 . V_1 = F_13 ( V_4 -> V_11 . V_1 ) ;
if ( V_4 -> V_6 . V_1 -> type == V_5 ) {
if ( V_4 -> V_6 . V_1 -> V_6 . V_3 == & V_28 ) {
F_9 ( V_4 -> V_6 . V_1 ) ;
F_9 ( V_4 -> V_11 . V_1 ) ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_28 ;
V_4 -> V_11 . V_1 = NULL ;
return V_4 ;
} else if ( V_4 -> V_6 . V_1 -> V_6 . V_3 == & V_27 ) {
free ( V_4 -> V_6 . V_1 ) ;
V_35 = V_4 -> V_11 . V_1 ;
* V_4 = * ( V_4 -> V_11 . V_1 ) ;
free ( V_35 ) ;
return V_4 ;
}
}
if ( V_4 -> V_11 . V_1 -> type == V_5 ) {
if ( V_4 -> V_11 . V_1 -> V_6 . V_3 == & V_28 ) {
F_9 ( V_4 -> V_6 . V_1 ) ;
F_9 ( V_4 -> V_11 . V_1 ) ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_28 ;
V_4 -> V_11 . V_1 = NULL ;
return V_4 ;
} else if ( V_4 -> V_11 . V_1 -> V_6 . V_3 == & V_27 ) {
free ( V_4 -> V_11 . V_1 ) ;
V_35 = V_4 -> V_6 . V_1 ;
* V_4 = * ( V_4 -> V_6 . V_1 ) ;
free ( V_35 ) ;
return V_4 ;
}
}
break;
case V_15 :
V_4 -> V_6 . V_1 = F_13 ( V_4 -> V_6 . V_1 ) ;
V_4 -> V_11 . V_1 = F_13 ( V_4 -> V_11 . V_1 ) ;
if ( V_4 -> V_6 . V_1 -> type == V_5 ) {
if ( V_4 -> V_6 . V_1 -> V_6 . V_3 == & V_28 ) {
free ( V_4 -> V_6 . V_1 ) ;
V_35 = V_4 -> V_11 . V_1 ;
* V_4 = * ( V_4 -> V_11 . V_1 ) ;
free ( V_35 ) ;
return V_4 ;
} else if ( V_4 -> V_6 . V_1 -> V_6 . V_3 == & V_27 ) {
F_9 ( V_4 -> V_6 . V_1 ) ;
F_9 ( V_4 -> V_11 . V_1 ) ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_27 ;
V_4 -> V_11 . V_1 = NULL ;
return V_4 ;
}
}
if ( V_4 -> V_11 . V_1 -> type == V_5 ) {
if ( V_4 -> V_11 . V_1 -> V_6 . V_3 == & V_28 ) {
free ( V_4 -> V_11 . V_1 ) ;
V_35 = V_4 -> V_6 . V_1 ;
* V_4 = * ( V_4 -> V_6 . V_1 ) ;
free ( V_35 ) ;
return V_4 ;
} else if ( V_4 -> V_11 . V_1 -> V_6 . V_3 == & V_27 ) {
F_9 ( V_4 -> V_6 . V_1 ) ;
F_9 ( V_4 -> V_11 . V_1 ) ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_27 ;
V_4 -> V_11 . V_1 = NULL ;
return V_4 ;
}
}
break;
default:
;
}
return V_4 ;
}
struct V_1 * F_15 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return NULL ;
switch ( V_4 -> type ) {
case V_14 :
case V_15 :
case V_17 :
V_4 -> V_6 . V_1 = F_15 ( V_4 -> V_6 . V_1 ) ;
V_4 -> V_11 . V_1 = F_15 ( V_4 -> V_11 . V_1 ) ;
break;
case V_23 :
if ( V_4 -> V_6 . V_3 -> type == V_36 ) {
if ( V_4 -> V_11 . V_3 == & V_28 ) {
V_4 -> type = V_5 ;
V_4 -> V_11 . V_3 = NULL ;
}
}
break;
default:
;
}
return V_4 ;
}
static struct V_1 * F_16 ( struct V_1 * V_9 , struct V_1 * V_10 )
{
struct V_1 * V_35 ;
struct V_2 * V_37 , * V_38 ;
if ( F_11 ( V_9 , V_10 ) )
return F_8 ( V_9 ) ;
if ( V_9 -> type != V_18 && V_9 -> type != V_23 && V_9 -> type != V_5 && V_9 -> type != V_17 )
return NULL ;
if ( V_10 -> type != V_18 && V_10 -> type != V_23 && V_10 -> type != V_5 && V_10 -> type != V_17 )
return NULL ;
if ( V_9 -> type == V_17 ) {
V_35 = V_9 -> V_6 . V_1 ;
if ( V_35 -> type != V_18 && V_35 -> type != V_23 && V_35 -> type != V_5 )
return NULL ;
V_37 = V_35 -> V_6 . V_3 ;
} else
V_37 = V_9 -> V_6 . V_3 ;
if ( V_10 -> type == V_17 ) {
if ( V_10 -> V_6 . V_1 -> type != V_5 )
return NULL ;
V_38 = V_10 -> V_6 . V_1 -> V_6 . V_3 ;
} else
V_38 = V_10 -> V_6 . V_3 ;
if ( V_37 != V_38 )
return NULL ;
if ( V_37 -> type != V_39 && V_37 -> type != V_36 )
return NULL ;
if ( V_37 -> type == V_36 ) {
if ( V_9 -> type == V_18 && V_10 -> type == V_18 &&
( ( V_9 -> V_11 . V_3 == & V_27 && V_10 -> V_11 . V_3 == & V_40 ) ||
( V_9 -> V_11 . V_3 == & V_40 && V_10 -> V_11 . V_3 == & V_27 ) ) ) {
return F_5 ( V_23 , V_37 , & V_28 ) ;
}
if ( V_9 -> type == V_18 && V_10 -> type == V_18 &&
( ( V_9 -> V_11 . V_3 == & V_27 && V_10 -> V_11 . V_3 == & V_28 ) ||
( V_9 -> V_11 . V_3 == & V_28 && V_10 -> V_11 . V_3 == & V_27 ) ) ) {
return F_5 ( V_23 , V_37 , & V_40 ) ;
}
if ( V_9 -> type == V_18 && V_10 -> type == V_18 &&
( ( V_9 -> V_11 . V_3 == & V_40 && V_10 -> V_11 . V_3 == & V_28 ) ||
( V_9 -> V_11 . V_3 == & V_28 && V_10 -> V_11 . V_3 == & V_40 ) ) ) {
return F_5 ( V_23 , V_37 , & V_27 ) ;
}
}
if ( V_37 -> type == V_39 && V_37 == V_38 ) {
if ( ( V_9 -> type == V_17 && V_9 -> V_6 . V_1 -> type == V_5 && V_10 -> type == V_5 ) ||
( V_10 -> type == V_17 && V_10 -> V_6 . V_1 -> type == V_5 && V_9 -> type == V_5 ) )
return F_1 ( & V_27 ) ;
}
if ( V_34 ) {
printf ( L_5 ) ;
F_14 ( V_9 , stdout ) ;
printf ( L_6 ) ;
F_14 ( V_10 , stdout ) ;
printf ( L_7 ) ;
}
return NULL ;
}
static struct V_1 * F_17 ( struct V_1 * V_9 , struct V_1 * V_10 )
{
struct V_1 * V_35 ;
struct V_2 * V_37 , * V_38 ;
if ( F_11 ( V_9 , V_10 ) )
return F_8 ( V_9 ) ;
if ( V_9 -> type != V_18 && V_9 -> type != V_23 && V_9 -> type != V_5 && V_9 -> type != V_17 )
return NULL ;
if ( V_10 -> type != V_18 && V_10 -> type != V_23 && V_10 -> type != V_5 && V_10 -> type != V_17 )
return NULL ;
if ( V_9 -> type == V_17 ) {
V_35 = V_9 -> V_6 . V_1 ;
if ( V_35 -> type != V_18 && V_35 -> type != V_23 && V_35 -> type != V_5 )
return NULL ;
V_37 = V_35 -> V_6 . V_3 ;
} else
V_37 = V_9 -> V_6 . V_3 ;
if ( V_10 -> type == V_17 ) {
if ( V_10 -> V_6 . V_1 -> type != V_5 )
return NULL ;
V_38 = V_10 -> V_6 . V_1 -> V_6 . V_3 ;
} else
V_38 = V_10 -> V_6 . V_3 ;
if ( V_37 != V_38 )
return NULL ;
if ( V_37 -> type != V_39 && V_37 -> type != V_36 )
return NULL ;
if ( ( V_9 -> type == V_5 && V_10 -> type == V_18 && V_10 -> V_11 . V_3 == & V_27 ) ||
( V_10 -> type == V_5 && V_9 -> type == V_18 && V_9 -> V_11 . V_3 == & V_27 ) )
return F_5 ( V_18 , V_37 , & V_27 ) ;
if ( ( V_9 -> type == V_5 && V_10 -> type == V_23 && V_10 -> V_11 . V_3 == & V_28 ) ||
( V_10 -> type == V_5 && V_9 -> type == V_23 && V_9 -> V_11 . V_3 == & V_28 ) )
return F_1 ( V_37 ) ;
if ( ( V_9 -> type == V_5 && V_10 -> type == V_23 && V_10 -> V_11 . V_3 == & V_40 ) ||
( V_10 -> type == V_5 && V_9 -> type == V_23 && V_9 -> V_11 . V_3 == & V_40 ) )
return F_5 ( V_18 , V_37 , & V_27 ) ;
if ( V_37 -> type == V_36 ) {
if ( V_9 -> type == V_18 && V_10 -> type == V_23 ) {
V_38 = V_9 -> V_11 . V_3 ;
if ( ( V_10 -> V_11 . V_3 -> V_41 & V_42 ) && ( V_38 -> V_41 & V_42 ) )
return V_38 != V_10 -> V_11 . V_3 ? F_5 ( V_18 , V_37 , V_38 )
: F_1 ( & V_28 ) ;
}
if ( V_9 -> type == V_23 && V_10 -> type == V_18 ) {
V_38 = V_10 -> V_11 . V_3 ;
if ( ( V_9 -> V_11 . V_3 -> V_41 & V_42 ) && ( V_38 -> V_41 & V_42 ) )
return V_38 != V_9 -> V_11 . V_3 ? F_5 ( V_18 , V_37 , V_38 )
: F_1 ( & V_28 ) ;
}
if ( V_9 -> type == V_23 && V_10 -> type == V_23 &&
( ( V_9 -> V_11 . V_3 == & V_27 && V_10 -> V_11 . V_3 == & V_28 ) ||
( V_9 -> V_11 . V_3 == & V_28 && V_10 -> V_11 . V_3 == & V_27 ) ) )
return F_5 ( V_18 , V_37 , & V_40 ) ;
if ( V_9 -> type == V_23 && V_10 -> type == V_23 &&
( ( V_9 -> V_11 . V_3 == & V_27 && V_10 -> V_11 . V_3 == & V_40 ) ||
( V_9 -> V_11 . V_3 == & V_40 && V_10 -> V_11 . V_3 == & V_27 ) ) )
return F_5 ( V_18 , V_37 , & V_28 ) ;
if ( V_9 -> type == V_23 && V_10 -> type == V_23 &&
( ( V_9 -> V_11 . V_3 == & V_40 && V_10 -> V_11 . V_3 == & V_28 ) ||
( V_9 -> V_11 . V_3 == & V_28 && V_10 -> V_11 . V_3 == & V_40 ) ) )
return F_5 ( V_18 , V_37 , & V_27 ) ;
if ( ( V_9 -> type == V_5 && V_10 -> type == V_18 && V_10 -> V_11 . V_3 == & V_40 ) ||
( V_10 -> type == V_5 && V_9 -> type == V_18 && V_9 -> V_11 . V_3 == & V_40 ) ||
( V_9 -> type == V_5 && V_10 -> type == V_23 && V_10 -> V_11 . V_3 == & V_27 ) ||
( V_10 -> type == V_5 && V_9 -> type == V_23 && V_9 -> V_11 . V_3 == & V_27 ) )
return NULL ;
}
if ( V_34 ) {
printf ( L_5 ) ;
F_14 ( V_9 , stdout ) ;
printf ( L_8 ) ;
F_14 ( V_10 , stdout ) ;
printf ( L_7 ) ;
}
return NULL ;
}
static void F_18 ( enum V_7 type , struct V_1 * * V_25 , struct V_1 * * V_26 )
{
#define V_9 (*ep1)
#define V_10 (*ep2)
struct V_1 * V_35 ;
if ( V_9 -> type == type ) {
F_18 ( type , & V_9 -> V_6 . V_1 , & V_10 ) ;
F_18 ( type , & V_9 -> V_11 . V_1 , & V_10 ) ;
return;
}
if ( V_10 -> type == type ) {
F_18 ( type , & V_9 , & V_10 -> V_6 . V_1 ) ;
F_18 ( type , & V_9 , & V_10 -> V_11 . V_1 ) ;
return;
}
if ( V_9 == V_10 )
return;
switch ( V_9 -> type ) {
case V_15 : case V_14 :
F_18 ( V_9 -> type , & V_9 , & V_9 ) ;
default:
;
}
switch ( type ) {
case V_15 :
V_35 = F_16 ( V_9 , V_10 ) ;
if ( V_35 ) {
F_9 ( V_9 ) ; F_9 ( V_10 ) ;
V_9 = F_1 ( & V_28 ) ;
V_10 = V_35 ;
V_29 ++ ;
}
break;
case V_14 :
V_35 = F_17 ( V_9 , V_10 ) ;
if ( V_35 ) {
F_9 ( V_9 ) ; F_9 ( V_10 ) ;
V_9 = F_1 ( & V_27 ) ;
V_10 = V_35 ;
V_29 ++ ;
}
break;
default:
;
}
#undef V_9
#undef V_10
}
struct V_1 * F_19 ( struct V_1 * V_4 )
{
int V_43 ;
if ( ! V_4 )
return V_4 ;
V_43 = V_29 ;
while ( 1 ) {
V_29 = 0 ;
switch ( V_4 -> type ) {
case V_15 : case V_14 :
F_18 ( V_4 -> type , & V_4 , & V_4 ) ;
default:
;
}
if ( ! V_29 )
break;
V_4 = F_13 ( V_4 ) ;
}
V_29 = V_43 ;
return V_4 ;
}
struct V_1 * F_20 ( struct V_1 * V_4 )
{
struct V_1 * V_35 ;
if ( ! V_4 )
return NULL ;
switch ( V_4 -> type ) {
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_5 :
case V_24 :
break;
default:
V_4 -> V_6 . V_1 = F_20 ( V_4 -> V_6 . V_1 ) ;
V_4 -> V_11 . V_1 = F_20 ( V_4 -> V_11 . V_1 ) ;
}
switch ( V_4 -> type ) {
case V_18 :
if ( V_4 -> V_6 . V_3 -> type != V_39 )
break;
if ( V_4 -> V_11 . V_3 == & V_28 ) {
V_4 -> type = V_17 ;
V_4 -> V_6 . V_1 = F_1 ( V_4 -> V_6 . V_3 ) ;
V_4 -> V_11 . V_3 = NULL ;
break;
}
if ( V_4 -> V_11 . V_3 == & V_40 ) {
printf ( L_9 , V_4 -> V_6 . V_3 -> V_44 ) ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_28 ;
V_4 -> V_11 . V_3 = NULL ;
break;
}
if ( V_4 -> V_11 . V_3 == & V_27 ) {
V_4 -> type = V_5 ;
V_4 -> V_11 . V_3 = NULL ;
break;
}
break;
case V_23 :
if ( V_4 -> V_6 . V_3 -> type != V_39 )
break;
if ( V_4 -> V_11 . V_3 == & V_28 ) {
V_4 -> type = V_5 ;
V_4 -> V_11 . V_3 = NULL ;
break;
}
if ( V_4 -> V_11 . V_3 == & V_40 ) {
printf ( L_10 , V_4 -> V_6 . V_3 -> V_44 ) ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_27 ;
V_4 -> V_11 . V_3 = NULL ;
break;
}
if ( V_4 -> V_11 . V_3 == & V_27 ) {
V_4 -> type = V_17 ;
V_4 -> V_6 . V_1 = F_1 ( V_4 -> V_6 . V_3 ) ;
V_4 -> V_11 . V_3 = NULL ;
break;
}
break;
case V_17 :
switch ( V_4 -> V_6 . V_1 -> type ) {
case V_17 :
V_35 = V_4 -> V_6 . V_1 -> V_6 . V_1 ;
free ( V_4 -> V_6 . V_1 ) ;
free ( V_4 ) ;
V_4 = V_35 ;
V_4 = F_20 ( V_4 ) ;
break;
case V_18 :
case V_23 :
V_35 = V_4 -> V_6 . V_1 ;
free ( V_4 ) ;
V_4 = V_35 ;
V_4 -> type = V_4 -> type == V_18 ? V_23 : V_18 ;
break;
case V_21 :
case V_19 :
V_35 = V_4 -> V_6 . V_1 ;
free ( V_4 ) ;
V_4 = V_35 ;
V_4 -> type = V_4 -> type == V_21 ? V_20 : V_22 ;
break;
case V_22 :
case V_20 :
V_35 = V_4 -> V_6 . V_1 ;
free ( V_4 ) ;
V_4 = V_35 ;
V_4 -> type = V_4 -> type == V_22 ? V_19 : V_21 ;
break;
case V_15 :
V_35 = V_4 -> V_6 . V_1 ;
V_4 -> type = V_14 ;
V_4 -> V_11 . V_1 = F_3 ( V_17 , V_35 -> V_11 . V_1 ) ;
V_35 -> type = V_17 ;
V_35 -> V_11 . V_1 = NULL ;
V_4 = F_20 ( V_4 ) ;
break;
case V_14 :
V_35 = V_4 -> V_6 . V_1 ;
V_4 -> type = V_15 ;
V_4 -> V_11 . V_1 = F_3 ( V_17 , V_35 -> V_11 . V_1 ) ;
V_35 -> type = V_17 ;
V_35 -> V_11 . V_1 = NULL ;
V_4 = F_20 ( V_4 ) ;
break;
case V_5 :
if ( V_4 -> V_6 . V_1 -> V_6 . V_3 == & V_27 ) {
V_35 = V_4 -> V_6 . V_1 ;
free ( V_4 ) ;
V_4 = V_35 ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_28 ;
break;
}
if ( V_4 -> V_6 . V_1 -> V_6 . V_3 == & V_40 ) {
V_35 = V_4 -> V_6 . V_1 ;
free ( V_4 ) ;
V_4 = V_35 ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_40 ;
break;
}
if ( V_4 -> V_6 . V_1 -> V_6 . V_3 == & V_28 ) {
V_35 = V_4 -> V_6 . V_1 ;
free ( V_4 ) ;
V_4 = V_35 ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_27 ;
break;
}
break;
default:
;
}
break;
default:
;
}
return V_4 ;
}
int F_21 ( struct V_1 * V_45 , struct V_2 * V_3 )
{
if ( ! V_45 )
return 0 ;
switch ( V_45 -> type ) {
case V_14 :
case V_15 :
return F_21 ( V_45 -> V_6 . V_1 , V_3 ) ||
F_21 ( V_45 -> V_11 . V_1 , V_3 ) ;
case V_5 :
return V_45 -> V_6 . V_3 == V_3 ;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
return V_45 -> V_6 . V_3 == V_3 ||
V_45 -> V_11 . V_3 == V_3 ;
case V_17 :
return F_21 ( V_45 -> V_6 . V_1 , V_3 ) ;
default:
;
}
return 0 ;
}
bool F_22 ( struct V_1 * V_45 , struct V_2 * V_3 )
{
if ( ! V_45 )
return false ;
switch ( V_45 -> type ) {
case V_14 :
return F_22 ( V_45 -> V_6 . V_1 , V_3 ) ||
F_22 ( V_45 -> V_11 . V_1 , V_3 ) ;
case V_5 :
return V_45 -> V_6 . V_3 == V_3 ;
case V_18 :
if ( V_45 -> V_6 . V_3 == V_3 ) {
if ( V_45 -> V_11 . V_3 == & V_27 || V_45 -> V_11 . V_3 == & V_40 )
return true ;
}
break;
case V_23 :
if ( V_45 -> V_6 . V_3 == V_3 ) {
if ( V_45 -> V_11 . V_3 == & V_28 )
return true ;
}
break;
default:
;
}
return false ;
}
struct V_1 * F_23 ( struct V_1 * V_4 , enum V_7 type , struct V_2 * V_3 )
{
struct V_1 * V_9 , * V_10 ;
if ( ! V_4 ) {
V_4 = F_1 ( V_3 ) ;
if ( type == V_23 )
V_4 = F_3 ( V_17 , V_4 ) ;
return V_4 ;
}
switch ( V_4 -> type ) {
case V_14 :
V_9 = F_23 ( V_4 -> V_6 . V_1 , V_18 , V_3 ) ;
V_10 = F_23 ( V_4 -> V_11 . V_1 , V_18 , V_3 ) ;
if ( V_3 == & V_27 )
V_4 = F_4 ( V_14 , V_9 , V_10 ) ;
if ( V_3 == & V_28 )
V_4 = F_4 ( V_15 , V_9 , V_10 ) ;
if ( type == V_23 )
V_4 = F_3 ( V_17 , V_4 ) ;
return V_4 ;
case V_15 :
V_9 = F_23 ( V_4 -> V_6 . V_1 , V_18 , V_3 ) ;
V_10 = F_23 ( V_4 -> V_11 . V_1 , V_18 , V_3 ) ;
if ( V_3 == & V_27 )
V_4 = F_4 ( V_15 , V_9 , V_10 ) ;
if ( V_3 == & V_28 )
V_4 = F_4 ( V_14 , V_9 , V_10 ) ;
if ( type == V_23 )
V_4 = F_3 ( V_17 , V_4 ) ;
return V_4 ;
case V_17 :
return F_23 ( V_4 -> V_6 . V_1 , type == V_18 ? V_23 : V_18 , V_3 ) ;
case V_23 :
case V_22 :
case V_21 :
case V_20 :
case V_19 :
case V_18 :
if ( type == V_18 ) {
if ( V_3 == & V_27 )
return F_8 ( V_4 ) ;
if ( V_3 == & V_40 )
return F_1 ( & V_28 ) ;
if ( V_3 == & V_28 )
return F_3 ( V_17 , F_8 ( V_4 ) ) ;
} else {
if ( V_3 == & V_27 )
return F_3 ( V_17 , F_8 ( V_4 ) ) ;
if ( V_3 == & V_40 )
return F_1 ( & V_27 ) ;
if ( V_3 == & V_28 )
return F_8 ( V_4 ) ;
}
break;
case V_5 :
return F_5 ( type , V_4 -> V_6 . V_3 , V_3 ) ;
case V_24 :
case V_32 :
case V_33 :
;
}
return NULL ;
}
static enum V_46 F_24 ( const char * V_47 ,
enum V_48 type ,
union V_49 * V_50 )
{
char * V_51 ;
enum V_46 V_52 ;
V_53 = 0 ;
switch ( type ) {
case V_39 :
case V_36 :
return V_54 ;
case V_55 :
V_50 -> V_56 = strtoll ( V_47 , & V_51 , 10 ) ;
V_52 = V_57 ;
break;
case V_58 :
V_50 -> V_59 = F_25 ( V_47 , & V_51 , 16 ) ;
V_52 = V_60 ;
break;
case V_61 :
case V_62 :
V_50 -> V_56 = strtoll ( V_47 , & V_51 , 0 ) ;
V_52 = V_57 ;
break;
default:
return V_63 ;
}
return ! V_53 && ! * V_51 && V_51 > V_47 && isxdigit ( V_51 [ - 1 ] )
? V_52 : V_54 ;
}
T_1 F_26 ( struct V_1 * V_4 )
{
T_1 V_64 , V_65 ;
const char * V_66 , * V_67 ;
enum V_46 V_68 = V_54 , V_69 = V_54 ;
union V_49 V_70 = {} , V_71 = {} ;
int V_30 ;
if ( ! V_4 )
return V_72 ;
switch ( V_4 -> type ) {
case V_5 :
F_27 ( V_4 -> V_6 . V_3 ) ;
return V_4 -> V_6 . V_3 -> V_73 . V_74 ;
case V_14 :
V_64 = F_26 ( V_4 -> V_6 . V_1 ) ;
V_65 = F_26 ( V_4 -> V_11 . V_1 ) ;
return F_28 ( V_64 , V_65 ) ;
case V_15 :
V_64 = F_26 ( V_4 -> V_6 . V_1 ) ;
V_65 = F_26 ( V_4 -> V_11 . V_1 ) ;
return F_29 ( V_64 , V_65 ) ;
case V_17 :
V_64 = F_26 ( V_4 -> V_6 . V_1 ) ;
return F_30 ( V_64 ) ;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
break;
default:
printf ( L_11 , V_4 -> type ) ;
return V_75 ;
}
F_27 ( V_4 -> V_6 . V_3 ) ;
F_27 ( V_4 -> V_11 . V_3 ) ;
V_66 = F_31 ( V_4 -> V_6 . V_3 ) ;
V_67 = F_31 ( V_4 -> V_11 . V_3 ) ;
if ( V_4 -> V_6 . V_3 -> type != V_61 || V_4 -> V_11 . V_3 -> type != V_61 ) {
V_68 = F_24 ( V_66 , V_4 -> V_6 . V_3 -> type , & V_70 ) ;
V_69 = F_24 ( V_67 , V_4 -> V_11 . V_3 -> type , & V_71 ) ;
}
if ( V_68 == V_54 || V_69 == V_54 )
V_30 = strcmp ( V_66 , V_67 ) ;
else if ( V_68 == V_63 || V_69 == V_63 ) {
if ( V_4 -> type != V_18 && V_4 -> type != V_23 ) {
printf ( L_12 , V_66 , V_67 ) ;
return V_75 ;
}
V_30 = strcmp ( V_66 , V_67 ) ;
} else if ( V_68 == V_60 || V_69 == V_60 )
V_30 = ( V_70 . V_59 > V_71 . V_59 ) - ( V_70 . V_59 < V_71 . V_59 ) ;
else
V_30 = ( V_70 . V_56 > V_71 . V_56 ) - ( V_70 . V_56 < V_71 . V_56 ) ;
switch( V_4 -> type ) {
case V_18 :
return V_30 ? V_75 : V_72 ;
case V_19 :
return V_30 >= 0 ? V_72 : V_75 ;
case V_20 :
return V_30 > 0 ? V_72 : V_75 ;
case V_21 :
return V_30 <= 0 ? V_72 : V_75 ;
case V_22 :
return V_30 < 0 ? V_72 : V_75 ;
case V_23 :
return V_30 ? V_72 : V_75 ;
default:
printf ( L_13 , V_4 -> type ) ;
return V_75 ;
}
}
static int F_32 ( enum V_7 V_76 , enum V_7 V_77 )
{
if ( V_76 == V_77 )
return 0 ;
switch ( V_76 ) {
case V_21 :
case V_22 :
case V_19 :
case V_20 :
if ( V_77 == V_18 || V_77 == V_23 )
return 1 ;
case V_18 :
case V_23 :
if ( V_77 == V_17 )
return 1 ;
case V_17 :
if ( V_77 == V_14 )
return 1 ;
case V_14 :
if ( V_77 == V_15 )
return 1 ;
case V_15 :
if ( V_77 == V_24 )
return 1 ;
case V_24 :
if ( V_77 == 0 )
return 1 ;
default:
return - 1 ;
}
printf ( L_14 , V_76 , V_77 ) ;
return 0 ;
}
static inline struct V_1 *
F_33 ( const struct V_1 * V_4 )
{
if ( V_4 == NULL )
return NULL ;
while ( V_4 -> type != V_5 )
V_4 = V_4 -> V_6 . V_1 ;
return F_8 ( V_4 ) ;
}
struct V_1 * F_34 ( struct V_1 * V_9 , struct V_1 * V_10 )
{
struct V_1 * V_78 ;
switch ( V_9 -> type ) {
case V_15 :
return F_6 (
F_34 ( V_9 -> V_6 . V_1 , V_10 ) ,
F_34 ( V_9 -> V_11 . V_1 , V_10 ) ) ;
case V_14 : {
struct V_1 * V_4 ;
V_4 = F_6 ( F_8 ( V_9 ) , F_8 ( V_10 ) ) ;
V_4 = F_19 ( V_4 ) ;
V_78 = ( ! F_11 ( V_4 , V_9 ) ) ? V_9 : NULL ;
F_9 ( V_4 ) ;
break;
}
default:
V_78 = V_9 ;
break;
}
return F_33 ( V_78 ) ;
}
void F_35 ( struct V_1 * V_4 , void (* F_36)( void * , struct V_2 * , const char * ) , void * V_79 , int V_80 )
{
if ( ! V_4 ) {
F_36 ( V_79 , NULL , L_15 ) ;
return;
}
if ( F_32 ( V_80 , V_4 -> type ) > 0 )
F_36 ( V_79 , NULL , L_16 ) ;
switch ( V_4 -> type ) {
case V_5 :
if ( V_4 -> V_6 . V_3 -> V_44 )
F_36 ( V_79 , V_4 -> V_6 . V_3 , V_4 -> V_6 . V_3 -> V_44 ) ;
else
F_36 ( V_79 , NULL , L_17 ) ;
break;
case V_17 :
F_36 ( V_79 , NULL , L_18 ) ;
F_35 ( V_4 -> V_6 . V_1 , F_36 , V_79 , V_17 ) ;
break;
case V_18 :
if ( V_4 -> V_6 . V_3 -> V_44 )
F_36 ( V_79 , V_4 -> V_6 . V_3 , V_4 -> V_6 . V_3 -> V_44 ) ;
else
F_36 ( V_79 , NULL , L_17 ) ;
F_36 ( V_79 , NULL , L_19 ) ;
F_36 ( V_79 , V_4 -> V_11 . V_3 , V_4 -> V_11 . V_3 -> V_44 ) ;
break;
case V_21 :
case V_22 :
if ( V_4 -> V_6 . V_3 -> V_44 )
F_36 ( V_79 , V_4 -> V_6 . V_3 , V_4 -> V_6 . V_3 -> V_44 ) ;
else
F_36 ( V_79 , NULL , L_17 ) ;
F_36 ( V_79 , NULL , V_4 -> type == V_21 ? L_20 : L_21 ) ;
F_36 ( V_79 , V_4 -> V_11 . V_3 , V_4 -> V_11 . V_3 -> V_44 ) ;
break;
case V_19 :
case V_20 :
if ( V_4 -> V_6 . V_3 -> V_44 )
F_36 ( V_79 , V_4 -> V_6 . V_3 , V_4 -> V_6 . V_3 -> V_44 ) ;
else
F_36 ( V_79 , NULL , L_17 ) ;
F_36 ( V_79 , NULL , V_4 -> type == V_19 ? L_22 : L_23 ) ;
F_36 ( V_79 , V_4 -> V_11 . V_3 , V_4 -> V_11 . V_3 -> V_44 ) ;
break;
case V_23 :
if ( V_4 -> V_6 . V_3 -> V_44 )
F_36 ( V_79 , V_4 -> V_6 . V_3 , V_4 -> V_6 . V_3 -> V_44 ) ;
else
F_36 ( V_79 , NULL , L_17 ) ;
F_36 ( V_79 , NULL , L_24 ) ;
F_36 ( V_79 , V_4 -> V_11 . V_3 , V_4 -> V_11 . V_3 -> V_44 ) ;
break;
case V_15 :
F_35 ( V_4 -> V_6 . V_1 , F_36 , V_79 , V_15 ) ;
F_36 ( V_79 , NULL , L_25 ) ;
F_35 ( V_4 -> V_11 . V_1 , F_36 , V_79 , V_15 ) ;
break;
case V_14 :
F_35 ( V_4 -> V_6 . V_1 , F_36 , V_79 , V_14 ) ;
F_36 ( V_79 , NULL , L_26 ) ;
F_35 ( V_4 -> V_11 . V_1 , F_36 , V_79 , V_14 ) ;
break;
case V_24 :
F_36 ( V_79 , V_4 -> V_11 . V_3 , V_4 -> V_11 . V_3 -> V_44 ) ;
if ( V_4 -> V_6 . V_1 ) {
F_36 ( V_79 , NULL , L_27 ) ;
F_35 ( V_4 -> V_6 . V_1 , F_36 , V_79 , V_24 ) ;
}
break;
case V_32 :
F_36 ( V_79 , NULL , L_28 ) ;
F_36 ( V_79 , V_4 -> V_6 . V_3 , V_4 -> V_6 . V_3 -> V_44 ) ;
F_36 ( V_79 , NULL , L_29 ) ;
F_36 ( V_79 , V_4 -> V_11 . V_3 , V_4 -> V_11 . V_3 -> V_44 ) ;
F_36 ( V_79 , NULL , L_30 ) ;
break;
default:
{
char V_81 [ 32 ] ;
sprintf ( V_81 , L_31 , V_4 -> type ) ;
F_36 ( V_79 , NULL , V_81 ) ;
break;
}
}
if ( F_32 ( V_80 , V_4 -> type ) > 0 )
F_36 ( V_79 , NULL , L_32 ) ;
}
static void F_37 ( void * V_79 , struct V_2 * V_3 , const char * V_47 )
{
F_38 ( V_47 , strlen ( V_47 ) , 1 , V_79 ) ;
}
void F_14 ( struct V_1 * V_4 , T_2 * V_82 )
{
F_35 ( V_4 , F_37 , V_82 , V_33 ) ;
}
static void F_39 ( void * V_79 , struct V_2 * V_3 , const char * V_47 )
{
struct V_83 * V_84 = (struct V_83 * ) V_79 ;
const char * V_85 = NULL ;
if ( V_3 )
V_85 = F_31 ( V_3 ) ;
if ( V_84 -> V_86 ) {
unsigned V_87 = strlen ( V_47 ) ;
const char * V_88 = strrchr ( V_84 -> V_56 , '\n' ) ;
unsigned V_89 ;
if ( V_85 )
V_87 += 4 + strlen ( V_85 ) ;
if ( ! V_88 )
V_88 = V_84 -> V_56 ;
V_89 = strlen ( V_84 -> V_56 ) - ( V_88 - V_84 -> V_56 ) ;
if ( ( V_89 + V_87 ) > V_84 -> V_86 )
F_40 ( V_84 , L_33 ) ;
}
F_40 ( V_84 , V_47 ) ;
if ( V_3 && V_3 -> type != V_62 )
F_41 ( V_84 , L_34 , V_85 ) ;
}
void F_42 ( struct V_1 * V_4 , struct V_83 * V_84 )
{
F_35 ( V_4 , F_39 , V_84 , V_33 ) ;
}
