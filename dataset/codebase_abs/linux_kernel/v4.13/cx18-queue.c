void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 += 4 )
F_2 ( ( V_5 * ) ( V_2 -> V_2 + V_3 ) ) ;
}
void F_3 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
F_4 (buf, &mdl->buf_list, list) {
if ( V_2 -> V_4 == 0 )
break;
F_1 ( V_2 ) ;
}
}
void F_5 ( struct V_8 * V_9 )
{
F_6 ( & V_9 -> V_10 ) ;
F_7 ( & V_9 -> V_11 , 0 ) ;
V_9 -> V_4 = 0 ;
}
struct V_8 * F_8 ( struct V_12 * V_13 , struct V_6 * V_7 ,
struct V_8 * V_9 , int V_14 )
{
if ( V_9 != & V_13 -> V_15 ) {
V_7 -> V_4 = 0 ;
V_7 -> V_16 = 0 ;
V_7 -> V_17 = 0 ;
V_7 -> V_18 = 0 ;
V_7 -> V_19 = NULL ;
}
if ( V_9 == & V_13 -> V_20 &&
F_9 ( & V_9 -> V_11 ) >= V_21 )
V_9 = & V_13 -> V_22 ;
F_10 ( & V_9 -> V_23 ) ;
if ( V_14 )
F_11 ( & V_7 -> V_10 , & V_9 -> V_10 ) ;
else
F_12 ( & V_7 -> V_10 , & V_9 -> V_10 ) ;
V_9 -> V_4 += V_7 -> V_4 - V_7 -> V_16 ;
F_13 ( & V_9 -> V_11 ) ;
F_14 ( & V_9 -> V_23 ) ;
return V_9 ;
}
struct V_6 * F_15 ( struct V_12 * V_13 , struct V_8 * V_9 )
{
struct V_6 * V_7 = NULL ;
F_10 ( & V_9 -> V_23 ) ;
if ( ! F_16 ( & V_9 -> V_10 ) ) {
V_7 = F_17 ( & V_9 -> V_10 , struct V_6 , V_10 ) ;
F_18 ( & V_7 -> V_10 ) ;
V_9 -> V_4 -= V_7 -> V_4 - V_7 -> V_16 ;
V_7 -> V_18 = 0 ;
F_19 ( & V_9 -> V_11 ) ;
}
F_14 ( & V_9 -> V_23 ) ;
return V_7 ;
}
static void F_20 ( struct V_12 * V_13 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 ;
V_5 V_24 = V_13 -> V_24 ;
V_5 V_4 = V_7 -> V_4 ;
F_4 (buf, &mdl->buf_list, list) {
V_2 -> V_16 = 0 ;
if ( V_4 >= V_24 ) {
V_2 -> V_4 = V_24 ;
V_4 -= V_24 ;
} else {
V_2 -> V_4 = V_4 ;
V_4 = 0 ;
}
F_21 ( V_13 , V_2 ) ;
}
}
static inline void F_22 ( struct V_12 * V_13 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 ;
if ( F_23 ( & V_7 -> V_25 ) ) {
V_2 = F_17 ( & V_7 -> V_25 , struct V_1 ,
V_10 ) ;
V_2 -> V_4 = V_7 -> V_4 ;
V_2 -> V_16 = 0 ;
F_21 ( V_13 , V_2 ) ;
} else {
F_20 ( V_13 , V_7 ) ;
}
}
struct V_6 * F_24 ( struct V_12 * V_13 , V_5 V_26 ,
V_5 V_4 )
{
struct V_27 * V_28 = V_13 -> V_28 ;
struct V_6 * V_7 ;
struct V_6 * V_29 ;
struct V_6 * V_30 = NULL ;
F_25 ( V_31 ) ;
F_10 ( & V_13 -> V_20 . V_23 ) ;
F_26 (mdl, tmp, &s->q_busy.list, list) {
if ( V_7 -> V_26 != V_26 ) {
V_7 -> V_18 ++ ;
if ( V_7 -> V_18 >= F_9 ( & V_13 -> V_20 . V_11 ) - 1 ) {
F_27 ( L_1 ,
V_13 -> V_32 , V_7 -> V_26 ,
V_7 -> V_18 ) ;
F_28 ( & V_7 -> V_10 , & V_31 ) ;
F_19 ( & V_13 -> V_20 . V_11 ) ;
}
continue;
}
F_18 ( & V_7 -> V_10 ) ;
F_19 ( & V_13 -> V_20 . V_11 ) ;
V_30 = V_7 ;
break;
}
F_14 ( & V_13 -> V_20 . V_23 ) ;
if ( V_30 != NULL ) {
V_30 -> V_4 = V_4 ;
V_30 -> V_18 = 0 ;
F_22 ( V_13 , V_30 ) ;
if ( V_13 -> type != V_33 )
F_29 ( V_34 , & V_30 -> V_17 ) ;
}
F_26 (mdl, tmp, &sweep_up, list) {
F_18 ( & V_7 -> V_10 ) ;
F_30 ( V_13 , V_7 , & V_13 -> V_22 ) ;
}
return V_30 ;
}
static void F_31 ( struct V_12 * V_13 ,
struct V_8 * V_35 , struct V_8 * V_36 )
{
struct V_6 * V_7 ;
if ( V_35 == V_36 || V_36 == & V_13 -> V_15 || V_36 == & V_13 -> V_20 )
return;
F_10 ( & V_35 -> V_23 ) ;
F_10 ( & V_36 -> V_23 ) ;
while ( ! F_16 ( & V_35 -> V_10 ) ) {
V_7 = F_17 ( & V_35 -> V_10 , struct V_6 , V_10 ) ;
F_28 ( & V_7 -> V_10 , & V_36 -> V_10 ) ;
V_7 -> V_4 = 0 ;
V_7 -> V_16 = 0 ;
V_7 -> V_17 = 0 ;
V_7 -> V_18 = 0 ;
V_7 -> V_19 = NULL ;
F_13 ( & V_36 -> V_11 ) ;
}
F_5 ( V_35 ) ;
F_14 ( & V_35 -> V_23 ) ;
F_14 ( & V_36 -> V_23 ) ;
}
void F_32 ( struct V_12 * V_13 )
{
F_31 ( V_13 , & V_13 -> V_20 , & V_13 -> V_22 ) ;
F_31 ( V_13 , & V_13 -> V_15 , & V_13 -> V_22 ) ;
}
void F_33 ( struct V_12 * V_13 )
{
struct V_8 * V_37 = & V_13 -> V_37 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
F_31 ( V_13 , & V_13 -> V_20 , V_37 ) ;
F_31 ( V_13 , & V_13 -> V_15 , V_37 ) ;
F_31 ( V_13 , & V_13 -> V_22 , V_37 ) ;
F_10 ( & V_37 -> V_23 ) ;
F_4 (mdl, &q_idle->list, list) {
while ( ! F_16 ( & V_7 -> V_25 ) ) {
V_2 = F_17 ( & V_7 -> V_25 ,
struct V_1 , V_10 ) ;
F_28 ( & V_2 -> V_10 , & V_13 -> V_38 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_16 = 0 ;
}
V_7 -> V_26 = V_13 -> V_39 ;
}
F_14 ( & V_37 -> V_23 ) ;
}
void F_34 ( struct V_12 * V_13 )
{
struct V_27 * V_28 = V_13 -> V_28 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
int V_40 ;
int V_3 ;
V_5 V_41 ;
V_40 = V_13 -> V_39 ;
for ( V_7 = F_15 ( V_13 , & V_13 -> V_37 ) , V_3 = V_13 -> V_42 ;
V_7 != NULL && V_3 == V_13 -> V_42 ;
V_7 = F_15 ( V_13 , & V_13 -> V_37 ) ) {
V_7 -> V_26 = V_40 ;
for ( V_3 = 0 ; V_3 < V_13 -> V_42 ; V_3 ++ ) {
if ( F_16 ( & V_13 -> V_38 ) )
break;
V_2 = F_17 ( & V_13 -> V_38 , struct V_1 ,
V_10 ) ;
F_28 ( & V_2 -> V_10 , & V_7 -> V_25 ) ;
F_35 ( V_28 , V_2 -> V_43 ,
& V_28 -> V_44 -> V_45 [ V_40 + V_3 ] . V_46 ) ;
F_35 ( V_28 , V_13 -> V_24 ,
& V_28 -> V_44 -> V_45 [ V_40 + V_3 ] . V_47 ) ;
}
if ( V_3 == V_13 -> V_42 ) {
V_41 = V_13 -> V_48 % V_13 -> V_24 ;
if ( V_41 ) {
F_35 ( V_28 , V_41 ,
& V_28 -> V_44 -> V_45 [ V_40 + V_3 - 1 ] . V_47 ) ;
}
F_30 ( V_13 , V_7 , & V_13 -> V_22 ) ;
} else {
F_36 ( V_13 , V_7 , & V_13 -> V_37 ) ;
}
V_40 += V_3 ;
}
}
void F_37 ( struct V_12 * V_13 , struct V_6 * V_7 )
{
int V_49 = V_13 -> V_49 ;
V_5 V_24 = V_13 -> V_24 ;
struct V_50 * V_50 = V_13 -> V_28 -> V_50 ;
struct V_1 * V_2 ;
F_4 (buf, &mdl->buf_list, list)
F_38 ( V_50 , V_2 -> V_43 ,
V_24 , V_49 ) ;
}
int F_39 ( struct V_12 * V_13 )
{
struct V_27 * V_28 = V_13 -> V_28 ;
int V_3 ;
if ( V_13 -> V_51 == 0 )
return 0 ;
F_40 ( L_2 ,
V_13 -> V_32 , V_13 -> V_51 , V_13 -> V_24 ,
V_13 -> V_51 * V_13 -> V_24 / 1024 ,
( V_13 -> V_51 * V_13 -> V_24 * 100 / 1024 ) % 100 ) ;
if ( ( ( char V_52 * ) & V_28 -> V_44 -> V_45 [ V_28 -> V_53 + V_13 -> V_51 ] -
( char V_52 * ) V_28 -> V_44 ) > V_54 ) {
unsigned V_55 = ( ( ( char V_52 * ) V_28 -> V_44 ) + V_54 -
( ( char V_52 * ) V_28 -> V_44 -> V_45 ) ) ;
F_41 ( L_3 ) ;
F_41 ( L_4 ,
V_55 / sizeof( struct V_56 ) ) ;
return - V_57 ;
}
V_13 -> V_39 = V_28 -> V_53 ;
for ( V_3 = 0 ; V_3 < V_13 -> V_51 ; V_3 ++ ) {
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_7 = F_42 ( sizeof( struct V_6 ) , V_58 | V_59 ) ;
if ( V_7 == NULL )
break;
V_2 = F_42 ( sizeof( struct V_1 ) ,
V_58 | V_59 ) ;
if ( V_2 == NULL ) {
F_43 ( V_7 ) ;
break;
}
V_2 -> V_2 = F_44 ( V_13 -> V_24 , V_58 | V_59 ) ;
if ( V_2 -> V_2 == NULL ) {
F_43 ( V_7 ) ;
F_43 ( V_2 ) ;
break;
}
F_6 ( & V_7 -> V_10 ) ;
F_6 ( & V_7 -> V_25 ) ;
V_7 -> V_26 = V_13 -> V_39 ;
F_30 ( V_13 , V_7 , & V_13 -> V_37 ) ;
F_6 ( & V_2 -> V_10 ) ;
V_2 -> V_43 = F_45 ( V_13 -> V_28 -> V_50 ,
V_2 -> V_2 , V_13 -> V_24 , V_13 -> V_49 ) ;
F_21 ( V_13 , V_2 ) ;
F_12 ( & V_2 -> V_10 , & V_13 -> V_38 ) ;
}
if ( V_3 == V_13 -> V_51 ) {
V_28 -> V_53 += V_13 -> V_51 ;
return 0 ;
}
F_41 ( L_5 , V_13 -> V_32 ) ;
F_46 ( V_13 ) ;
return - V_57 ;
}
void F_46 ( struct V_12 * V_13 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_27 * V_28 = V_13 -> V_28 ;
F_40 ( L_6 , V_13 -> V_32 ) ;
F_33 ( V_13 ) ;
while ( ( V_7 = F_15 ( V_13 , & V_13 -> V_37 ) ) )
F_43 ( V_7 ) ;
while ( ! F_16 ( & V_13 -> V_38 ) ) {
V_2 = F_17 ( & V_13 -> V_38 , struct V_1 , V_10 ) ;
F_18 ( & V_2 -> V_10 ) ;
F_47 ( V_13 -> V_28 -> V_50 , V_2 -> V_43 ,
V_13 -> V_24 , V_13 -> V_49 ) ;
F_43 ( V_2 -> V_2 ) ;
F_43 ( V_2 ) ;
}
}
