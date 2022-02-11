static unsigned F_1 ( const struct V_1 * V_2 , unsigned V_3 )
{
V_3 += V_2 -> V_4 ;
return V_3 >= V_2 -> V_5 ? V_3 - V_2 -> V_5 : V_3 ;
}
static int F_2 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_10 * V_11 ;
unsigned long V_12 ;
F_3 ( & V_7 -> V_13 -> V_14 , V_12 ) ;
if ( F_4 ( & V_7 -> V_15 ) ) {
F_5 ( & V_7 -> V_13 -> V_14 , V_12 ) ;
return - V_16 ;
}
F_6 ( V_7 -> V_17 == 0 ) ;
V_11 = F_7 ( & V_7 -> V_15 , struct V_10 , V_18 ) ;
F_8 ( & V_11 -> V_18 ) ;
V_7 -> V_17 -- ;
V_11 -> V_9 . V_19 = V_7 -> V_17 ;
* V_9 = V_11 -> V_9 ;
V_11 -> V_2 -> V_4 = F_1 ( V_11 -> V_2 , 1 ) ;
V_11 -> V_2 -> V_20 -- ;
F_5 ( & V_7 -> V_13 -> V_14 , V_12 ) ;
return 0 ;
}
int F_9 ( struct V_6 * V_7 , struct V_8 * V_9 ,
int V_21 )
{
int V_22 ;
if ( V_21 )
return F_2 ( V_7 , V_9 ) ;
if ( V_7 -> V_13 -> V_23 )
F_10 ( V_7 -> V_13 -> V_23 ) ;
do {
V_22 = F_11 ( V_7 -> V_24 ,
V_7 -> V_17 != 0 ) ;
if ( V_22 < 0 )
break;
V_22 = F_2 ( V_7 , V_9 ) ;
} while ( V_22 == - V_16 );
if ( V_7 -> V_13 -> V_23 )
F_12 ( V_7 -> V_13 -> V_23 ) ;
return V_22 ;
}
static struct V_1 * F_13 (
struct V_6 * V_7 , T_1 type , T_1 V_25 )
{
struct V_1 * V_2 ;
F_14 ( & V_7 -> V_13 -> V_14 ) ;
F_15 (sev, &fh->subscribed, list)
if ( V_2 -> type == type && V_2 -> V_25 == V_25 )
return V_2 ;
return NULL ;
}
static void F_16 ( struct V_6 * V_7 , const struct V_8 * V_26 ,
const struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
bool V_29 = true ;
V_2 = F_13 ( V_7 , V_26 -> type , V_26 -> V_25 ) ;
if ( V_2 == NULL )
return;
if ( ! V_2 -> V_5 )
return;
V_7 -> V_30 ++ ;
if ( V_2 -> V_20 == V_2 -> V_5 ) {
V_11 = V_2 -> V_31 + F_1 ( V_2 , 0 ) ;
F_8 ( & V_11 -> V_18 ) ;
V_2 -> V_20 -- ;
V_2 -> V_4 = F_1 ( V_2 , 1 ) ;
V_7 -> V_17 -- ;
if ( V_2 -> V_5 == 1 ) {
if ( V_2 -> V_32 && V_2 -> V_32 -> V_33 ) {
V_2 -> V_32 -> V_33 ( & V_11 -> V_9 , V_26 ) ;
V_29 = false ;
}
} else if ( V_2 -> V_32 && V_2 -> V_32 -> V_34 ) {
struct V_10 * V_35 =
V_2 -> V_31 + F_1 ( V_2 , 0 ) ;
V_2 -> V_32 -> V_34 ( & V_11 -> V_9 , & V_35 -> V_9 ) ;
}
}
V_11 = V_2 -> V_31 + F_1 ( V_2 , V_2 -> V_20 ) ;
V_11 -> V_9 . type = V_26 -> type ;
if ( V_29 )
V_11 -> V_9 . V_36 = V_26 -> V_36 ;
V_11 -> V_9 . V_25 = V_26 -> V_25 ;
V_11 -> V_9 . V_37 = * V_28 ;
V_11 -> V_9 . V_30 = V_7 -> V_30 ;
V_2 -> V_20 ++ ;
F_17 ( & V_11 -> V_18 , & V_7 -> V_15 ) ;
V_7 -> V_17 ++ ;
F_18 ( & V_7 -> V_24 ) ;
}
void F_19 ( struct V_38 * V_13 , const struct V_8 * V_26 )
{
struct V_6 * V_7 ;
unsigned long V_12 ;
struct V_27 V_37 ;
F_20 ( & V_37 ) ;
F_3 ( & V_13 -> V_14 , V_12 ) ;
F_15 (fh, &vdev->fh_list, list)
F_16 ( V_7 , V_26 , & V_37 ) ;
F_5 ( & V_13 -> V_14 , V_12 ) ;
}
void F_21 ( struct V_6 * V_7 , const struct V_8 * V_26 )
{
unsigned long V_12 ;
struct V_27 V_37 ;
F_20 ( & V_37 ) ;
F_3 ( & V_7 -> V_13 -> V_14 , V_12 ) ;
F_16 ( V_7 , V_26 , & V_37 ) ;
F_5 ( & V_7 -> V_13 -> V_14 , V_12 ) ;
}
int F_22 ( struct V_6 * V_7 )
{
return V_7 -> V_17 ;
}
int F_23 ( struct V_6 * V_7 ,
struct V_39 * V_40 , unsigned V_5 ,
const struct V_41 * V_32 )
{
struct V_1 * V_2 , * V_42 ;
unsigned long V_12 ;
unsigned V_43 ;
if ( V_40 -> type == V_44 )
return - V_45 ;
if ( V_5 < 1 )
V_5 = 1 ;
V_2 = F_24 ( sizeof( * V_2 ) + sizeof( struct V_10 ) * V_5 , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
for ( V_43 = 0 ; V_43 < V_5 ; V_43 ++ )
V_2 -> V_31 [ V_43 ] . V_2 = V_2 ;
V_2 -> type = V_40 -> type ;
V_2 -> V_25 = V_40 -> V_25 ;
V_2 -> V_12 = V_40 -> V_12 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_32 = V_32 ;
F_3 ( & V_7 -> V_13 -> V_14 , V_12 ) ;
V_42 = F_13 ( V_7 , V_40 -> type , V_40 -> V_25 ) ;
if ( ! V_42 )
F_25 ( & V_2 -> V_18 , & V_7 -> V_48 ) ;
F_5 ( & V_7 -> V_13 -> V_14 , V_12 ) ;
if ( V_42 ) {
F_26 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_32 && V_2 -> V_32 -> V_49 ) {
int V_22 = V_2 -> V_32 -> V_49 ( V_2 , V_5 ) ;
if ( V_22 ) {
V_2 -> V_32 = NULL ;
F_27 ( V_7 , V_40 ) ;
return V_22 ;
}
}
V_2 -> V_5 = V_5 ;
return 0 ;
}
void F_28 ( struct V_6 * V_7 )
{
struct V_39 V_40 ;
struct V_1 * V_2 ;
unsigned long V_12 ;
do {
V_2 = NULL ;
F_3 ( & V_7 -> V_13 -> V_14 , V_12 ) ;
if ( ! F_4 ( & V_7 -> V_48 ) ) {
V_2 = F_7 ( & V_7 -> V_48 ,
struct V_1 , V_18 ) ;
V_40 . type = V_2 -> type ;
V_40 . V_25 = V_2 -> V_25 ;
}
F_5 ( & V_7 -> V_13 -> V_14 , V_12 ) ;
if ( V_2 )
F_27 ( V_7 , & V_40 ) ;
} while ( V_2 );
}
int F_27 ( struct V_6 * V_7 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 ;
unsigned long V_12 ;
int V_43 ;
if ( V_40 -> type == V_44 ) {
F_28 ( V_7 ) ;
return 0 ;
}
F_3 ( & V_7 -> V_13 -> V_14 , V_12 ) ;
V_2 = F_13 ( V_7 , V_40 -> type , V_40 -> V_25 ) ;
if ( V_2 != NULL ) {
for ( V_43 = 0 ; V_43 < V_2 -> V_20 ; V_43 ++ ) {
F_8 ( & V_2 -> V_31 [ F_1 ( V_2 , V_43 ) ] . V_18 ) ;
V_7 -> V_17 -- ;
}
F_8 ( & V_2 -> V_18 ) ;
}
F_5 ( & V_7 -> V_13 -> V_14 , V_12 ) ;
if ( V_2 && V_2 -> V_32 && V_2 -> V_32 -> V_50 )
V_2 -> V_32 -> V_50 ( V_2 ) ;
F_26 ( V_2 ) ;
return 0 ;
}
