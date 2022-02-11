struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
if ( V_2 == NULL ) {
F_3 ( L_1 ) ;
return NULL ;
}
F_4 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = NULL ;
V_2 -> V_7 = 0 ;
return V_2 ;
}
void F_5 ( struct V_1 * * V_8 )
{
struct V_1 * V_2 = * V_8 ;
* V_8 = NULL ;
if ( V_2 == NULL ) {
F_3 ( L_2 ) ;
return;
}
if ( V_2 -> V_7 > 0 ) {
while ( V_2 -> V_7 > 0 )
F_6 ( F_7 ( V_2 ) ) ;
}
F_8 ( V_2 ) ;
}
static inline int F_9 ( struct V_9 * V_10 ,
struct V_9 * V_11 )
{
if ( ( V_10 -> V_12 & V_13 ) == V_14 ) {
return ( F_10 ( & V_10 -> time . V_15 , & V_11 -> time . V_15 ) ) ;
} else {
return ( F_11 ( & V_10 -> time . time , & V_11 -> time . time ) ) ;
}
}
static inline int F_12 ( struct V_9 * V_10 ,
struct V_9 * V_11 )
{
if ( ( V_10 -> V_12 & V_13 ) == V_14 ) {
if ( V_10 -> time . V_15 > V_11 -> time . V_15 )
return 1 ;
else if ( V_10 -> time . V_15 == V_11 -> time . V_15 )
return 0 ;
else
return - 1 ;
} else {
if ( V_10 -> time . time . V_16 > V_11 -> time . time . V_16 )
return 1 ;
else if ( V_10 -> time . time . V_16 == V_11 -> time . time . V_16 ) {
if ( V_10 -> time . time . V_17 > V_11 -> time . time . V_17 )
return 1 ;
else if ( V_10 -> time . time . V_17 == V_11 -> time . time . V_17 )
return 0 ;
else
return - 1 ;
} else
return - 1 ;
}
}
int F_13 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_18 * V_20 , * V_21 ;
unsigned long V_12 ;
int V_22 ;
int V_23 ;
if ( F_14 ( ! V_2 || ! V_19 ) )
return - V_24 ;
V_23 = ( V_19 -> V_25 . V_12 & V_26 ) ;
F_15 ( & V_2 -> V_4 , V_12 ) ;
if ( V_2 -> V_6 && ! V_23 ) {
if ( F_9 ( & V_19 -> V_25 , & V_2 -> V_6 -> V_25 ) ) {
V_2 -> V_6 -> V_27 = V_19 ;
V_2 -> V_6 = V_19 ;
V_19 -> V_27 = NULL ;
V_2 -> V_7 ++ ;
F_16 ( & V_2 -> V_4 , V_12 ) ;
return 0 ;
}
}
V_21 = NULL ;
V_20 = V_2 -> V_5 ;
V_22 = 10000 ;
while ( V_20 != NULL ) {
int V_28 = F_12 ( & V_19 -> V_25 , & V_20 -> V_25 ) ;
if ( V_28 < 0 )
break;
else if ( V_28 == 0 && V_23 )
break;
V_21 = V_20 ;
V_20 = V_20 -> V_27 ;
if ( ! -- V_22 ) {
F_16 ( & V_2 -> V_4 , V_12 ) ;
F_17 ( V_29 L_3 ) ;
return - V_24 ;
}
}
if ( V_21 != NULL )
V_21 -> V_27 = V_19 ;
V_19 -> V_27 = V_20 ;
if ( V_2 -> V_5 == V_20 )
V_2 -> V_5 = V_19 ;
if ( V_20 == NULL )
V_2 -> V_6 = V_19 ;
V_2 -> V_7 ++ ;
F_16 ( & V_2 -> V_4 , V_12 ) ;
return 0 ;
}
struct V_18 * F_7 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
unsigned long V_12 ;
if ( V_2 == NULL ) {
F_3 ( L_4 ) ;
return NULL ;
}
F_15 ( & V_2 -> V_4 , V_12 ) ;
V_19 = V_2 -> V_5 ;
if ( V_19 ) {
V_2 -> V_5 = V_19 -> V_27 ;
if ( V_2 -> V_6 == V_19 )
V_2 -> V_6 = NULL ;
V_19 -> V_27 = NULL ;
V_2 -> V_7 -- ;
}
F_16 ( & V_2 -> V_4 , V_12 ) ;
return V_19 ;
}
int F_18 ( struct V_1 * V_2 )
{
if ( V_2 == NULL ) {
F_3 ( L_4 ) ;
return 0 ;
}
return V_2 -> V_7 ;
}
struct V_18 * F_19 ( struct V_1 * V_2 )
{
if ( V_2 == NULL ) {
F_3 ( L_4 ) ;
return NULL ;
}
return V_2 -> V_5 ;
}
static inline int F_20 ( struct V_18 * V_19 ,
int V_30 , int V_31 )
{
if ( V_19 -> V_25 . V_32 . V_30 == V_30 ||
V_19 -> V_25 . V_33 . V_30 == V_30 )
return 1 ;
if ( ! V_31 )
return 0 ;
switch ( V_19 -> V_25 . V_12 & V_13 ) {
case V_14 :
if ( V_19 -> V_25 . time . V_15 )
return 1 ;
break;
case V_34 :
if ( V_19 -> V_25 . time . time . V_16 ||
V_19 -> V_25 . time . time . V_17 )
return 1 ;
break;
}
return 0 ;
}
void F_21 ( struct V_1 * V_2 , int V_30 , int V_31 )
{
register struct V_18 * V_19 , * V_27 ;
unsigned long V_12 ;
struct V_18 * V_21 = NULL ;
struct V_18 * V_35 = NULL , * V_36 = NULL , * V_37 ;
F_15 ( & V_2 -> V_4 , V_12 ) ;
V_19 = V_2 -> V_5 ;
while ( V_19 ) {
V_27 = V_19 -> V_27 ;
if ( F_20 ( V_19 , V_30 , V_31 ) ) {
if ( V_19 == V_2 -> V_5 ) {
V_2 -> V_5 = V_19 -> V_27 ;
} else {
V_21 -> V_27 = V_19 -> V_27 ;
}
if ( V_19 == V_2 -> V_6 )
V_2 -> V_6 = V_19 -> V_27 ;
V_2 -> V_7 -- ;
V_19 -> V_27 = NULL ;
if ( V_35 == NULL ) {
V_35 = V_19 ;
} else {
V_36 -> V_27 = V_19 ;
}
V_36 = V_19 ;
} else {
#if 0
printk(KERN_DEBUG "type = %i, source = %i, dest = %i, "
"client = %i\n",
cell->event.type,
cell->event.source.client,
cell->event.dest.client,
client);
#endif
V_21 = V_19 ;
}
V_19 = V_27 ;
}
F_16 ( & V_2 -> V_4 , V_12 ) ;
while ( V_35 ) {
V_37 = V_35 -> V_27 ;
F_6 ( V_35 ) ;
V_35 = V_37 ;
}
}
static int F_22 ( struct V_38 * V_39 ,
struct V_9 * V_40 )
{
int V_41 ;
if ( V_39 -> V_42 & V_43 ) {
if ( V_40 -> V_33 . V_30 != V_39 -> V_33 . V_30 ||
V_40 -> V_33 . V_44 != V_39 -> V_33 . V_44 )
return 0 ;
}
if ( V_39 -> V_42 & V_45 ) {
if ( ! F_23 ( V_40 ) )
return 0 ;
if ( V_40 -> V_46 . V_47 . V_48 != V_39 -> V_48 )
return 0 ;
}
if ( V_39 -> V_42 & V_49 ) {
if ( V_39 -> V_42 & V_50 )
V_41 = F_10 ( & V_40 -> time . V_15 , & V_39 -> time . V_15 ) ;
else
V_41 = F_11 ( & V_40 -> time . time , & V_39 -> time . time ) ;
if ( ! V_41 )
return 0 ;
}
if ( V_39 -> V_42 & V_51 ) {
if ( V_39 -> V_42 & V_50 )
V_41 = F_10 ( & V_40 -> time . V_15 , & V_39 -> time . V_15 ) ;
else
V_41 = F_11 ( & V_40 -> time . time , & V_39 -> time . time ) ;
if ( V_41 )
return 0 ;
}
if ( V_39 -> V_42 & V_52 ) {
if ( V_40 -> type != V_39 -> type )
return 0 ;
}
if ( V_39 -> V_42 & V_53 ) {
switch ( V_40 -> type ) {
case V_54 :
return 0 ;
default:
break;
}
}
if ( V_39 -> V_42 & V_55 ) {
if ( V_39 -> V_56 != V_40 -> V_56 )
return 0 ;
}
return 1 ;
}
void F_24 ( struct V_1 * V_2 , int V_30 ,
struct V_38 * V_39 )
{
struct V_18 * V_19 , * V_27 ;
unsigned long V_12 ;
struct V_18 * V_21 = NULL ;
struct V_18 * V_35 = NULL , * V_36 = NULL , * V_37 ;
F_15 ( & V_2 -> V_4 , V_12 ) ;
V_19 = V_2 -> V_5 ;
while ( V_19 ) {
V_27 = V_19 -> V_27 ;
if ( V_19 -> V_25 . V_32 . V_30 == V_30 &&
F_22 ( V_39 , & V_19 -> V_25 ) ) {
if ( V_19 == V_2 -> V_5 ) {
V_2 -> V_5 = V_19 -> V_27 ;
} else {
V_21 -> V_27 = V_19 -> V_27 ;
}
if ( V_19 == V_2 -> V_6 )
V_2 -> V_6 = V_19 -> V_27 ;
V_2 -> V_7 -- ;
V_19 -> V_27 = NULL ;
if ( V_35 == NULL ) {
V_35 = V_19 ;
} else {
V_36 -> V_27 = V_19 ;
}
V_36 = V_19 ;
} else {
V_21 = V_19 ;
}
V_19 = V_27 ;
}
F_16 ( & V_2 -> V_4 , V_12 ) ;
while ( V_35 ) {
V_37 = V_35 -> V_27 ;
F_6 ( V_35 ) ;
V_35 = V_37 ;
}
}
