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
V_4 -> V_6 . V_3 = V_16 -> V_6 . V_3 ;
V_4 -> V_11 . V_3 = V_16 -> V_11 . V_3 ;
break;
case V_14 :
case V_15 :
case V_20 :
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
static void F_10 ( enum V_7 type , struct V_1 * * V_21 , struct V_1 * * V_22 )
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
( V_9 -> V_6 . V_3 == & V_23 || V_9 -> V_6 . V_3 == & V_24 ) )
return;
if ( ! F_11 ( V_9 , V_10 ) )
return;
V_25 ++ ;
F_9 ( V_9 ) ; F_9 ( V_10 ) ;
switch ( type ) {
case V_15 :
V_9 = F_1 ( & V_24 ) ;
V_10 = F_1 ( & V_24 ) ;
break;
case V_14 :
V_9 = F_1 ( & V_23 ) ;
V_10 = F_1 ( & V_23 ) ;
break;
default:
;
}
}
void F_12 ( struct V_1 * * V_21 , struct V_1 * * V_22 )
{
if ( ! V_9 || ! V_10 )
return;
switch ( V_9 -> type ) {
case V_15 :
case V_14 :
F_10 ( V_9 -> type , V_21 , V_22 ) ;
default:
;
}
if ( V_9 -> type != V_10 -> type ) switch ( V_10 -> type ) {
case V_15 :
case V_14 :
F_10 ( V_10 -> type , V_21 , V_22 ) ;
default:
;
}
V_9 = F_13 ( V_9 ) ;
V_10 = F_13 ( V_10 ) ;
}
int F_11 ( struct V_1 * V_9 , struct V_1 * V_10 )
{
int V_26 , V_27 ;
if ( V_9 -> type != V_10 -> type )
return 0 ;
switch ( V_9 -> type ) {
case V_18 :
case V_19 :
return V_9 -> V_6 . V_3 == V_10 -> V_6 . V_3 && V_9 -> V_11 . V_3 == V_10 -> V_11 . V_3 ;
case V_5 :
return V_9 -> V_6 . V_3 == V_10 -> V_6 . V_3 ;
case V_17 :
return F_11 ( V_9 -> V_6 . V_1 , V_10 -> V_6 . V_1 ) ;
case V_14 :
case V_15 :
V_9 = F_8 ( V_9 ) ;
V_10 = F_8 ( V_10 ) ;
V_27 = V_25 ;
F_12 ( & V_9 , & V_10 ) ;
V_26 = ( V_9 -> type == V_5 && V_10 -> type == V_5 &&
V_9 -> V_6 . V_3 == V_10 -> V_6 . V_3 ) ;
F_9 ( V_9 ) ;
F_9 ( V_10 ) ;
V_25 = V_27 ;
return V_26 ;
case V_20 :
case V_28 :
case V_29 :
;
}
if ( V_30 ) {
F_14 ( V_9 , stdout ) ;
printf ( L_3 ) ;
F_14 ( V_10 , stdout ) ;
printf ( L_4 ) ;
}
return 0 ;
}
struct V_1 * F_13 ( struct V_1 * V_4 )
{
struct V_1 * V_31 ;
if ( V_4 ) switch ( V_4 -> type ) {
case V_14 :
V_4 -> V_6 . V_1 = F_13 ( V_4 -> V_6 . V_1 ) ;
V_4 -> V_11 . V_1 = F_13 ( V_4 -> V_11 . V_1 ) ;
if ( V_4 -> V_6 . V_1 -> type == V_5 ) {
if ( V_4 -> V_6 . V_1 -> V_6 . V_3 == & V_24 ) {
F_9 ( V_4 -> V_6 . V_1 ) ;
F_9 ( V_4 -> V_11 . V_1 ) ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_24 ;
V_4 -> V_11 . V_1 = NULL ;
return V_4 ;
} else if ( V_4 -> V_6 . V_1 -> V_6 . V_3 == & V_23 ) {
free ( V_4 -> V_6 . V_1 ) ;
V_31 = V_4 -> V_11 . V_1 ;
* V_4 = * ( V_4 -> V_11 . V_1 ) ;
free ( V_31 ) ;
return V_4 ;
}
}
if ( V_4 -> V_11 . V_1 -> type == V_5 ) {
if ( V_4 -> V_11 . V_1 -> V_6 . V_3 == & V_24 ) {
F_9 ( V_4 -> V_6 . V_1 ) ;
F_9 ( V_4 -> V_11 . V_1 ) ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_24 ;
V_4 -> V_11 . V_1 = NULL ;
return V_4 ;
} else if ( V_4 -> V_11 . V_1 -> V_6 . V_3 == & V_23 ) {
free ( V_4 -> V_11 . V_1 ) ;
V_31 = V_4 -> V_6 . V_1 ;
* V_4 = * ( V_4 -> V_6 . V_1 ) ;
free ( V_31 ) ;
return V_4 ;
}
}
break;
case V_15 :
V_4 -> V_6 . V_1 = F_13 ( V_4 -> V_6 . V_1 ) ;
V_4 -> V_11 . V_1 = F_13 ( V_4 -> V_11 . V_1 ) ;
if ( V_4 -> V_6 . V_1 -> type == V_5 ) {
if ( V_4 -> V_6 . V_1 -> V_6 . V_3 == & V_24 ) {
free ( V_4 -> V_6 . V_1 ) ;
V_31 = V_4 -> V_11 . V_1 ;
* V_4 = * ( V_4 -> V_11 . V_1 ) ;
free ( V_31 ) ;
return V_4 ;
} else if ( V_4 -> V_6 . V_1 -> V_6 . V_3 == & V_23 ) {
F_9 ( V_4 -> V_6 . V_1 ) ;
F_9 ( V_4 -> V_11 . V_1 ) ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_23 ;
V_4 -> V_11 . V_1 = NULL ;
return V_4 ;
}
}
if ( V_4 -> V_11 . V_1 -> type == V_5 ) {
if ( V_4 -> V_11 . V_1 -> V_6 . V_3 == & V_24 ) {
free ( V_4 -> V_11 . V_1 ) ;
V_31 = V_4 -> V_6 . V_1 ;
* V_4 = * ( V_4 -> V_6 . V_1 ) ;
free ( V_31 ) ;
return V_4 ;
} else if ( V_4 -> V_11 . V_1 -> V_6 . V_3 == & V_23 ) {
F_9 ( V_4 -> V_6 . V_1 ) ;
F_9 ( V_4 -> V_11 . V_1 ) ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_23 ;
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
case V_19 :
if ( V_4 -> V_6 . V_3 -> type == V_32 ) {
if ( V_4 -> V_11 . V_3 == & V_24 ) {
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
struct V_1 * V_31 ;
struct V_2 * V_33 , * V_34 ;
if ( F_11 ( V_9 , V_10 ) )
return F_8 ( V_9 ) ;
if ( V_9 -> type != V_18 && V_9 -> type != V_19 && V_9 -> type != V_5 && V_9 -> type != V_17 )
return NULL ;
if ( V_10 -> type != V_18 && V_10 -> type != V_19 && V_10 -> type != V_5 && V_10 -> type != V_17 )
return NULL ;
if ( V_9 -> type == V_17 ) {
V_31 = V_9 -> V_6 . V_1 ;
if ( V_31 -> type != V_18 && V_31 -> type != V_19 && V_31 -> type != V_5 )
return NULL ;
V_33 = V_31 -> V_6 . V_3 ;
} else
V_33 = V_9 -> V_6 . V_3 ;
if ( V_10 -> type == V_17 ) {
if ( V_10 -> V_6 . V_1 -> type != V_5 )
return NULL ;
V_34 = V_10 -> V_6 . V_1 -> V_6 . V_3 ;
} else
V_34 = V_10 -> V_6 . V_3 ;
if ( V_33 != V_34 )
return NULL ;
if ( V_33 -> type != V_35 && V_33 -> type != V_32 )
return NULL ;
if ( V_33 -> type == V_32 ) {
if ( V_9 -> type == V_18 && V_10 -> type == V_18 &&
( ( V_9 -> V_11 . V_3 == & V_23 && V_10 -> V_11 . V_3 == & V_36 ) ||
( V_9 -> V_11 . V_3 == & V_36 && V_10 -> V_11 . V_3 == & V_23 ) ) ) {
return F_5 ( V_19 , V_33 , & V_24 ) ;
}
if ( V_9 -> type == V_18 && V_10 -> type == V_18 &&
( ( V_9 -> V_11 . V_3 == & V_23 && V_10 -> V_11 . V_3 == & V_24 ) ||
( V_9 -> V_11 . V_3 == & V_24 && V_10 -> V_11 . V_3 == & V_23 ) ) ) {
return F_5 ( V_19 , V_33 , & V_36 ) ;
}
if ( V_9 -> type == V_18 && V_10 -> type == V_18 &&
( ( V_9 -> V_11 . V_3 == & V_36 && V_10 -> V_11 . V_3 == & V_24 ) ||
( V_9 -> V_11 . V_3 == & V_24 && V_10 -> V_11 . V_3 == & V_36 ) ) ) {
return F_5 ( V_19 , V_33 , & V_23 ) ;
}
}
if ( V_33 -> type == V_35 && V_33 == V_34 ) {
if ( ( V_9 -> type == V_17 && V_9 -> V_6 . V_1 -> type == V_5 && V_10 -> type == V_5 ) ||
( V_10 -> type == V_17 && V_10 -> V_6 . V_1 -> type == V_5 && V_9 -> type == V_5 ) )
return F_1 ( & V_23 ) ;
}
if ( V_30 ) {
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
struct V_1 * V_31 ;
struct V_2 * V_33 , * V_34 ;
if ( F_11 ( V_9 , V_10 ) )
return F_8 ( V_9 ) ;
if ( V_9 -> type != V_18 && V_9 -> type != V_19 && V_9 -> type != V_5 && V_9 -> type != V_17 )
return NULL ;
if ( V_10 -> type != V_18 && V_10 -> type != V_19 && V_10 -> type != V_5 && V_10 -> type != V_17 )
return NULL ;
if ( V_9 -> type == V_17 ) {
V_31 = V_9 -> V_6 . V_1 ;
if ( V_31 -> type != V_18 && V_31 -> type != V_19 && V_31 -> type != V_5 )
return NULL ;
V_33 = V_31 -> V_6 . V_3 ;
} else
V_33 = V_9 -> V_6 . V_3 ;
if ( V_10 -> type == V_17 ) {
if ( V_10 -> V_6 . V_1 -> type != V_5 )
return NULL ;
V_34 = V_10 -> V_6 . V_1 -> V_6 . V_3 ;
} else
V_34 = V_10 -> V_6 . V_3 ;
if ( V_33 != V_34 )
return NULL ;
if ( V_33 -> type != V_35 && V_33 -> type != V_32 )
return NULL ;
if ( ( V_9 -> type == V_5 && V_10 -> type == V_18 && V_10 -> V_11 . V_3 == & V_23 ) ||
( V_10 -> type == V_5 && V_9 -> type == V_18 && V_9 -> V_11 . V_3 == & V_23 ) )
return F_5 ( V_18 , V_33 , & V_23 ) ;
if ( ( V_9 -> type == V_5 && V_10 -> type == V_19 && V_10 -> V_11 . V_3 == & V_24 ) ||
( V_10 -> type == V_5 && V_9 -> type == V_19 && V_9 -> V_11 . V_3 == & V_24 ) )
return F_1 ( V_33 ) ;
if ( ( V_9 -> type == V_5 && V_10 -> type == V_19 && V_10 -> V_11 . V_3 == & V_36 ) ||
( V_10 -> type == V_5 && V_9 -> type == V_19 && V_9 -> V_11 . V_3 == & V_36 ) )
return F_5 ( V_18 , V_33 , & V_23 ) ;
if ( V_33 -> type == V_32 ) {
if ( V_9 -> type == V_18 && V_10 -> type == V_19 ) {
V_34 = V_9 -> V_11 . V_3 ;
if ( ( V_10 -> V_11 . V_3 -> V_37 & V_38 ) && ( V_34 -> V_37 & V_38 ) )
return V_34 != V_10 -> V_11 . V_3 ? F_5 ( V_18 , V_33 , V_34 )
: F_1 ( & V_24 ) ;
}
if ( V_9 -> type == V_19 && V_10 -> type == V_18 ) {
V_34 = V_10 -> V_11 . V_3 ;
if ( ( V_9 -> V_11 . V_3 -> V_37 & V_38 ) && ( V_34 -> V_37 & V_38 ) )
return V_34 != V_9 -> V_11 . V_3 ? F_5 ( V_18 , V_33 , V_34 )
: F_1 ( & V_24 ) ;
}
if ( V_9 -> type == V_19 && V_10 -> type == V_19 &&
( ( V_9 -> V_11 . V_3 == & V_23 && V_10 -> V_11 . V_3 == & V_24 ) ||
( V_9 -> V_11 . V_3 == & V_24 && V_10 -> V_11 . V_3 == & V_23 ) ) )
return F_5 ( V_18 , V_33 , & V_36 ) ;
if ( V_9 -> type == V_19 && V_10 -> type == V_19 &&
( ( V_9 -> V_11 . V_3 == & V_23 && V_10 -> V_11 . V_3 == & V_36 ) ||
( V_9 -> V_11 . V_3 == & V_36 && V_10 -> V_11 . V_3 == & V_23 ) ) )
return F_5 ( V_18 , V_33 , & V_24 ) ;
if ( V_9 -> type == V_19 && V_10 -> type == V_19 &&
( ( V_9 -> V_11 . V_3 == & V_36 && V_10 -> V_11 . V_3 == & V_24 ) ||
( V_9 -> V_11 . V_3 == & V_24 && V_10 -> V_11 . V_3 == & V_36 ) ) )
return F_5 ( V_18 , V_33 , & V_23 ) ;
if ( ( V_9 -> type == V_5 && V_10 -> type == V_18 && V_10 -> V_11 . V_3 == & V_36 ) ||
( V_10 -> type == V_5 && V_9 -> type == V_18 && V_9 -> V_11 . V_3 == & V_36 ) ||
( V_9 -> type == V_5 && V_10 -> type == V_19 && V_10 -> V_11 . V_3 == & V_23 ) ||
( V_10 -> type == V_5 && V_9 -> type == V_19 && V_9 -> V_11 . V_3 == & V_23 ) )
return NULL ;
}
if ( V_30 ) {
printf ( L_5 ) ;
F_14 ( V_9 , stdout ) ;
printf ( L_8 ) ;
F_14 ( V_10 , stdout ) ;
printf ( L_7 ) ;
}
return NULL ;
}
static void F_18 ( enum V_7 type , struct V_1 * * V_21 , struct V_1 * * V_22 )
{
#define V_9 (*ep1)
#define V_10 (*ep2)
struct V_1 * V_31 ;
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
V_31 = F_16 ( V_9 , V_10 ) ;
if ( V_31 ) {
F_9 ( V_9 ) ; F_9 ( V_10 ) ;
V_9 = F_1 ( & V_24 ) ;
V_10 = V_31 ;
V_25 ++ ;
}
break;
case V_14 :
V_31 = F_17 ( V_9 , V_10 ) ;
if ( V_31 ) {
F_9 ( V_9 ) ; F_9 ( V_10 ) ;
V_9 = F_1 ( & V_23 ) ;
V_10 = V_31 ;
V_25 ++ ;
}
break;
default:
;
}
#undef V_9
#undef V_10
}
static void F_19 ( enum V_7 type , struct V_1 * * V_21 , struct V_1 * * V_22 )
{
#define V_9 (*ep1)
#define V_10 (*ep2)
struct V_1 * V_31 , * V_39 , * V_40 ;
if ( V_9 -> type == type ) {
F_19 ( type , & V_9 -> V_6 . V_1 , & V_10 ) ;
F_19 ( type , & V_9 -> V_11 . V_1 , & V_10 ) ;
return;
}
if ( V_10 -> type == type ) {
F_19 ( type , & V_9 , & V_10 -> V_6 . V_1 ) ;
F_19 ( type , & V_9 , & V_10 -> V_11 . V_1 ) ;
}
if ( V_9 == V_10 )
return;
switch ( V_9 -> type ) {
case V_15 :
F_19 ( V_9 -> type , & V_9 , & V_9 ) ;
V_39 = F_20 ( F_3 ( V_17 , F_8 ( V_9 ) ) ) ;
V_40 = F_8 ( V_10 ) ;
V_31 = F_21 ( & V_39 , & V_40 ) ;
if ( F_22 ( V_39 ) ) {
F_9 ( V_9 ) ;
V_9 = F_1 ( & V_24 ) ;
V_25 ++ ;
}
F_9 ( V_40 ) ;
F_9 ( V_39 ) ;
F_9 ( V_31 ) ;
break;
case V_14 :
F_19 ( V_9 -> type , & V_9 , & V_9 ) ;
V_39 = F_20 ( F_3 ( V_17 , F_8 ( V_9 ) ) ) ;
V_40 = F_8 ( V_10 ) ;
V_31 = F_23 ( & V_39 , & V_40 ) ;
if ( F_24 ( V_39 ) ) {
F_9 ( V_9 ) ;
V_9 = F_1 ( & V_23 ) ;
V_25 ++ ;
}
F_9 ( V_40 ) ;
F_9 ( V_39 ) ;
F_9 ( V_31 ) ;
break;
default:
;
}
#undef V_9
#undef V_10
}
struct V_1 * F_25 ( struct V_1 * V_4 )
{
int V_41 ;
if ( ! V_4 )
return V_4 ;
V_41 = V_25 ;
while ( 1 ) {
V_25 = 0 ;
switch ( V_4 -> type ) {
case V_15 : case V_14 :
F_18 ( V_4 -> type , & V_4 , & V_4 ) ;
F_19 ( V_4 -> type , & V_4 , & V_4 ) ;
default:
;
}
if ( ! V_25 )
break;
V_4 = F_13 ( V_4 ) ;
}
V_25 = V_41 ;
return V_4 ;
}
struct V_1 * F_20 ( struct V_1 * V_4 )
{
struct V_1 * V_31 ;
if ( ! V_4 )
return NULL ;
switch ( V_4 -> type ) {
case V_18 :
case V_19 :
case V_5 :
case V_20 :
break;
default:
V_4 -> V_6 . V_1 = F_20 ( V_4 -> V_6 . V_1 ) ;
V_4 -> V_11 . V_1 = F_20 ( V_4 -> V_11 . V_1 ) ;
}
switch ( V_4 -> type ) {
case V_18 :
if ( V_4 -> V_6 . V_3 -> type != V_35 )
break;
if ( V_4 -> V_11 . V_3 == & V_24 ) {
V_4 -> type = V_17 ;
V_4 -> V_6 . V_1 = F_1 ( V_4 -> V_6 . V_3 ) ;
V_4 -> V_11 . V_3 = NULL ;
break;
}
if ( V_4 -> V_11 . V_3 == & V_36 ) {
printf ( L_9 , V_4 -> V_6 . V_3 -> V_42 ) ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_24 ;
V_4 -> V_11 . V_3 = NULL ;
break;
}
if ( V_4 -> V_11 . V_3 == & V_23 ) {
V_4 -> type = V_5 ;
V_4 -> V_11 . V_3 = NULL ;
break;
}
break;
case V_19 :
if ( V_4 -> V_6 . V_3 -> type != V_35 )
break;
if ( V_4 -> V_11 . V_3 == & V_24 ) {
V_4 -> type = V_5 ;
V_4 -> V_11 . V_3 = NULL ;
break;
}
if ( V_4 -> V_11 . V_3 == & V_36 ) {
printf ( L_10 , V_4 -> V_6 . V_3 -> V_42 ) ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_23 ;
V_4 -> V_11 . V_3 = NULL ;
break;
}
if ( V_4 -> V_11 . V_3 == & V_23 ) {
V_4 -> type = V_17 ;
V_4 -> V_6 . V_1 = F_1 ( V_4 -> V_6 . V_3 ) ;
V_4 -> V_11 . V_3 = NULL ;
break;
}
break;
case V_17 :
switch ( V_4 -> V_6 . V_1 -> type ) {
case V_17 :
V_31 = V_4 -> V_6 . V_1 -> V_6 . V_1 ;
free ( V_4 -> V_6 . V_1 ) ;
free ( V_4 ) ;
V_4 = V_31 ;
V_4 = F_20 ( V_4 ) ;
break;
case V_18 :
case V_19 :
V_31 = V_4 -> V_6 . V_1 ;
free ( V_4 ) ;
V_4 = V_31 ;
V_4 -> type = V_4 -> type == V_18 ? V_19 : V_18 ;
break;
case V_15 :
V_31 = V_4 -> V_6 . V_1 ;
V_4 -> type = V_14 ;
V_4 -> V_11 . V_1 = F_3 ( V_17 , V_31 -> V_11 . V_1 ) ;
V_31 -> type = V_17 ;
V_31 -> V_11 . V_1 = NULL ;
V_4 = F_20 ( V_4 ) ;
break;
case V_14 :
V_31 = V_4 -> V_6 . V_1 ;
V_4 -> type = V_15 ;
V_4 -> V_11 . V_1 = F_3 ( V_17 , V_31 -> V_11 . V_1 ) ;
V_31 -> type = V_17 ;
V_31 -> V_11 . V_1 = NULL ;
V_4 = F_20 ( V_4 ) ;
break;
case V_5 :
if ( V_4 -> V_6 . V_1 -> V_6 . V_3 == & V_23 ) {
V_31 = V_4 -> V_6 . V_1 ;
free ( V_4 ) ;
V_4 = V_31 ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_24 ;
break;
}
if ( V_4 -> V_6 . V_1 -> V_6 . V_3 == & V_36 ) {
V_31 = V_4 -> V_6 . V_1 ;
free ( V_4 ) ;
V_4 = V_31 ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_36 ;
break;
}
if ( V_4 -> V_6 . V_1 -> V_6 . V_3 == & V_24 ) {
V_31 = V_4 -> V_6 . V_1 ;
free ( V_4 ) ;
V_4 = V_31 ;
V_4 -> type = V_5 ;
V_4 -> V_6 . V_3 = & V_23 ;
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
int F_26 ( struct V_1 * V_43 , struct V_2 * V_3 )
{
if ( ! V_43 )
return 0 ;
switch ( V_43 -> type ) {
case V_14 :
case V_15 :
return F_26 ( V_43 -> V_6 . V_1 , V_3 ) ||
F_26 ( V_43 -> V_11 . V_1 , V_3 ) ;
case V_5 :
return V_43 -> V_6 . V_3 == V_3 ;
case V_18 :
case V_19 :
return V_43 -> V_6 . V_3 == V_3 ||
V_43 -> V_11 . V_3 == V_3 ;
case V_17 :
return F_26 ( V_43 -> V_6 . V_1 , V_3 ) ;
default:
;
}
return 0 ;
}
bool F_27 ( struct V_1 * V_43 , struct V_2 * V_3 )
{
if ( ! V_43 )
return false ;
switch ( V_43 -> type ) {
case V_14 :
return F_27 ( V_43 -> V_6 . V_1 , V_3 ) ||
F_27 ( V_43 -> V_11 . V_1 , V_3 ) ;
case V_5 :
return V_43 -> V_6 . V_3 == V_3 ;
case V_18 :
if ( V_43 -> V_6 . V_3 == V_3 ) {
if ( V_43 -> V_11 . V_3 == & V_23 || V_43 -> V_11 . V_3 == & V_36 )
return true ;
}
break;
case V_19 :
if ( V_43 -> V_6 . V_3 == V_3 ) {
if ( V_43 -> V_11 . V_3 == & V_24 )
return true ;
}
break;
default:
;
}
return false ;
}
struct V_1 * F_21 ( struct V_1 * * V_21 , struct V_1 * * V_22 )
{
struct V_1 * V_31 = NULL ;
F_28 ( V_14 , & V_31 , V_21 , V_22 ) ;
if ( V_31 ) {
* V_21 = F_13 ( * V_21 ) ;
* V_22 = F_13 ( * V_22 ) ;
}
return V_31 ;
}
struct V_1 * F_23 ( struct V_1 * * V_21 , struct V_1 * * V_22 )
{
struct V_1 * V_31 = NULL ;
F_28 ( V_15 , & V_31 , V_21 , V_22 ) ;
if ( V_31 ) {
* V_21 = F_13 ( * V_21 ) ;
* V_22 = F_13 ( * V_22 ) ;
}
return V_31 ;
}
void F_28 ( enum V_7 type , struct V_1 * * V_44 , struct V_1 * * V_21 , struct V_1 * * V_22 )
{
#define V_9 (*ep1)
#define V_10 (*ep2)
if ( V_9 -> type == type ) {
F_28 ( type , V_44 , & V_9 -> V_6 . V_1 , & V_10 ) ;
F_28 ( type , V_44 , & V_9 -> V_11 . V_1 , & V_10 ) ;
return;
}
if ( V_10 -> type == type ) {
F_28 ( type , V_44 , V_21 , & V_10 -> V_6 . V_1 ) ;
F_28 ( type , V_44 , V_21 , & V_10 -> V_11 . V_1 ) ;
return;
}
if ( F_11 ( V_9 , V_10 ) ) {
* V_44 = * V_44 ? F_4 ( type , * V_44 , V_9 ) : V_9 ;
F_9 ( V_10 ) ;
if ( type == V_14 ) {
V_9 = F_1 ( & V_23 ) ;
V_10 = F_1 ( & V_23 ) ;
} else if ( type == V_15 ) {
V_9 = F_1 ( & V_24 ) ;
V_10 = F_1 ( & V_24 ) ;
}
}
#undef V_9
#undef V_10
}
struct V_1 * F_29 ( struct V_1 * V_4 , enum V_7 type , struct V_2 * V_3 )
{
struct V_1 * V_9 , * V_10 ;
if ( ! V_4 ) {
V_4 = F_1 ( V_3 ) ;
if ( type == V_19 )
V_4 = F_3 ( V_17 , V_4 ) ;
return V_4 ;
}
switch ( V_4 -> type ) {
case V_14 :
V_9 = F_29 ( V_4 -> V_6 . V_1 , V_18 , V_3 ) ;
V_10 = F_29 ( V_4 -> V_11 . V_1 , V_18 , V_3 ) ;
if ( V_3 == & V_23 )
V_4 = F_4 ( V_14 , V_9 , V_10 ) ;
if ( V_3 == & V_24 )
V_4 = F_4 ( V_15 , V_9 , V_10 ) ;
if ( type == V_19 )
V_4 = F_3 ( V_17 , V_4 ) ;
return V_4 ;
case V_15 :
V_9 = F_29 ( V_4 -> V_6 . V_1 , V_18 , V_3 ) ;
V_10 = F_29 ( V_4 -> V_11 . V_1 , V_18 , V_3 ) ;
if ( V_3 == & V_23 )
V_4 = F_4 ( V_15 , V_9 , V_10 ) ;
if ( V_3 == & V_24 )
V_4 = F_4 ( V_14 , V_9 , V_10 ) ;
if ( type == V_19 )
V_4 = F_3 ( V_17 , V_4 ) ;
return V_4 ;
case V_17 :
return F_29 ( V_4 -> V_6 . V_1 , type == V_18 ? V_19 : V_18 , V_3 ) ;
case V_19 :
case V_18 :
if ( type == V_18 ) {
if ( V_3 == & V_23 )
return F_8 ( V_4 ) ;
if ( V_3 == & V_36 )
return F_1 ( & V_24 ) ;
if ( V_3 == & V_24 )
return F_3 ( V_17 , F_8 ( V_4 ) ) ;
} else {
if ( V_3 == & V_23 )
return F_3 ( V_17 , F_8 ( V_4 ) ) ;
if ( V_3 == & V_36 )
return F_1 ( & V_23 ) ;
if ( V_3 == & V_24 )
return F_8 ( V_4 ) ;
}
break;
case V_5 :
return F_5 ( type , V_4 -> V_6 . V_3 , V_3 ) ;
case V_20 :
case V_28 :
case V_29 :
;
}
return NULL ;
}
T_1 F_30 ( struct V_1 * V_4 )
{
T_1 V_45 , V_46 ;
const char * V_47 , * V_48 ;
if ( ! V_4 )
return V_49 ;
switch ( V_4 -> type ) {
case V_5 :
F_31 ( V_4 -> V_6 . V_3 ) ;
return V_4 -> V_6 . V_3 -> V_50 . V_51 ;
case V_14 :
V_45 = F_30 ( V_4 -> V_6 . V_1 ) ;
V_46 = F_30 ( V_4 -> V_11 . V_1 ) ;
return F_32 ( V_45 , V_46 ) ;
case V_15 :
V_45 = F_30 ( V_4 -> V_6 . V_1 ) ;
V_46 = F_30 ( V_4 -> V_11 . V_1 ) ;
return F_33 ( V_45 , V_46 ) ;
case V_17 :
V_45 = F_30 ( V_4 -> V_6 . V_1 ) ;
return F_34 ( V_45 ) ;
case V_18 :
F_31 ( V_4 -> V_6 . V_3 ) ;
F_31 ( V_4 -> V_11 . V_3 ) ;
V_47 = F_35 ( V_4 -> V_6 . V_3 ) ;
V_48 = F_35 ( V_4 -> V_11 . V_3 ) ;
return ! strcmp ( V_47 , V_48 ) ? V_49 : V_52 ;
case V_19 :
F_31 ( V_4 -> V_6 . V_3 ) ;
F_31 ( V_4 -> V_11 . V_3 ) ;
V_47 = F_35 ( V_4 -> V_6 . V_3 ) ;
V_48 = F_35 ( V_4 -> V_11 . V_3 ) ;
return ! strcmp ( V_47 , V_48 ) ? V_52 : V_49 ;
default:
printf ( L_11 , V_4 -> type ) ;
return V_52 ;
}
}
int F_36 ( enum V_7 V_53 , enum V_7 V_54 )
{
#if 0
return 1;
#else
if ( V_53 == V_54 )
return 0 ;
switch ( V_53 ) {
case V_18 :
case V_19 :
if ( V_54 == V_17 )
return 1 ;
case V_17 :
if ( V_54 == V_14 )
return 1 ;
case V_14 :
if ( V_54 == V_15 )
return 1 ;
case V_15 :
if ( V_54 == V_20 )
return 1 ;
case V_20 :
if ( V_54 == 0 )
return 1 ;
default:
return - 1 ;
}
printf ( L_12 , V_53 , V_54 ) ;
return 0 ;
#endif
}
static inline struct V_1 *
F_37 ( const struct V_1 * V_4 )
{
if ( V_4 == NULL )
return NULL ;
while ( V_4 -> type != V_5 )
V_4 = V_4 -> V_6 . V_1 ;
return F_8 ( V_4 ) ;
}
struct V_1 * F_38 ( struct V_1 * V_9 , struct V_1 * V_10 )
{
struct V_1 * V_55 ;
switch ( V_9 -> type ) {
case V_15 :
return F_6 (
F_38 ( V_9 -> V_6 . V_1 , V_10 ) ,
F_38 ( V_9 -> V_11 . V_1 , V_10 ) ) ;
case V_14 : {
struct V_1 * V_4 ;
V_4 = F_6 ( F_8 ( V_9 ) , F_8 ( V_10 ) ) ;
V_4 = F_25 ( V_4 ) ;
V_55 = ( ! F_11 ( V_4 , V_9 ) ) ? V_9 : NULL ;
F_9 ( V_4 ) ;
break;
}
default:
V_55 = V_9 ;
break;
}
return F_37 ( V_55 ) ;
}
void F_39 ( struct V_1 * V_4 , void (* F_40)( void * , struct V_2 * , const char * ) , void * V_56 , int V_57 )
{
if ( ! V_4 ) {
F_40 ( V_56 , NULL , L_13 ) ;
return;
}
if ( F_36 ( V_57 , V_4 -> type ) > 0 )
F_40 ( V_56 , NULL , L_14 ) ;
switch ( V_4 -> type ) {
case V_5 :
if ( V_4 -> V_6 . V_3 -> V_42 )
F_40 ( V_56 , V_4 -> V_6 . V_3 , V_4 -> V_6 . V_3 -> V_42 ) ;
else
F_40 ( V_56 , NULL , L_15 ) ;
break;
case V_17 :
F_40 ( V_56 , NULL , L_16 ) ;
F_39 ( V_4 -> V_6 . V_1 , F_40 , V_56 , V_17 ) ;
break;
case V_18 :
if ( V_4 -> V_6 . V_3 -> V_42 )
F_40 ( V_56 , V_4 -> V_6 . V_3 , V_4 -> V_6 . V_3 -> V_42 ) ;
else
F_40 ( V_56 , NULL , L_15 ) ;
F_40 ( V_56 , NULL , L_17 ) ;
F_40 ( V_56 , V_4 -> V_11 . V_3 , V_4 -> V_11 . V_3 -> V_42 ) ;
break;
case V_19 :
if ( V_4 -> V_6 . V_3 -> V_42 )
F_40 ( V_56 , V_4 -> V_6 . V_3 , V_4 -> V_6 . V_3 -> V_42 ) ;
else
F_40 ( V_56 , NULL , L_15 ) ;
F_40 ( V_56 , NULL , L_18 ) ;
F_40 ( V_56 , V_4 -> V_11 . V_3 , V_4 -> V_11 . V_3 -> V_42 ) ;
break;
case V_15 :
F_39 ( V_4 -> V_6 . V_1 , F_40 , V_56 , V_15 ) ;
F_40 ( V_56 , NULL , L_19 ) ;
F_39 ( V_4 -> V_11 . V_1 , F_40 , V_56 , V_15 ) ;
break;
case V_14 :
F_39 ( V_4 -> V_6 . V_1 , F_40 , V_56 , V_14 ) ;
F_40 ( V_56 , NULL , L_20 ) ;
F_39 ( V_4 -> V_11 . V_1 , F_40 , V_56 , V_14 ) ;
break;
case V_20 :
F_40 ( V_56 , V_4 -> V_11 . V_3 , V_4 -> V_11 . V_3 -> V_42 ) ;
if ( V_4 -> V_6 . V_1 ) {
F_40 ( V_56 , NULL , L_21 ) ;
F_39 ( V_4 -> V_6 . V_1 , F_40 , V_56 , V_20 ) ;
}
break;
case V_28 :
F_40 ( V_56 , NULL , L_22 ) ;
F_40 ( V_56 , V_4 -> V_6 . V_3 , V_4 -> V_6 . V_3 -> V_42 ) ;
F_40 ( V_56 , NULL , L_23 ) ;
F_40 ( V_56 , V_4 -> V_11 . V_3 , V_4 -> V_11 . V_3 -> V_42 ) ;
F_40 ( V_56 , NULL , L_24 ) ;
break;
default:
{
char V_58 [ 32 ] ;
sprintf ( V_58 , L_25 , V_4 -> type ) ;
F_40 ( V_56 , NULL , V_58 ) ;
break;
}
}
if ( F_36 ( V_57 , V_4 -> type ) > 0 )
F_40 ( V_56 , NULL , L_26 ) ;
}
static void F_41 ( void * V_56 , struct V_2 * V_3 , const char * V_59 )
{
F_42 ( V_59 , strlen ( V_59 ) , 1 , V_56 ) ;
}
void F_14 ( struct V_1 * V_4 , T_2 * V_60 )
{
F_39 ( V_4 , F_41 , V_60 , V_29 ) ;
}
static void F_43 ( void * V_56 , struct V_2 * V_3 , const char * V_59 )
{
struct V_61 * V_62 = (struct V_61 * ) V_56 ;
const char * V_63 = NULL ;
if ( V_3 )
V_63 = F_35 ( V_3 ) ;
if ( V_62 -> V_64 ) {
unsigned V_65 = strlen ( V_59 ) ;
const char * V_66 = strrchr ( V_62 -> V_67 , '\n' ) ;
unsigned V_68 ;
if ( V_63 )
V_65 += 4 + strlen ( V_63 ) ;
if ( ! V_66 )
V_66 = V_62 -> V_67 ;
V_68 = strlen ( V_62 -> V_67 ) - ( V_66 - V_62 -> V_67 ) ;
if ( ( V_68 + V_65 ) > V_62 -> V_64 )
F_44 ( V_62 , L_27 ) ;
}
F_44 ( V_62 , V_59 ) ;
if ( V_3 && V_3 -> type != V_69 )
F_45 ( V_62 , L_28 , V_63 ) ;
}
void F_46 ( struct V_1 * V_4 , struct V_61 * V_62 )
{
F_39 ( V_4 , F_43 , V_62 , V_29 ) ;
}
