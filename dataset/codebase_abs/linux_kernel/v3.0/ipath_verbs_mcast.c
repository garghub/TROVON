static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof *V_4 , V_5 ) ;
if ( ! V_4 )
goto V_6;
V_4 -> V_3 = V_3 ;
F_3 ( & V_3 -> V_7 ) ;
V_6:
return V_4 ;
}
static void F_4 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
if ( F_5 ( & V_3 -> V_7 ) )
F_6 ( & V_3 -> V_8 ) ;
F_7 ( V_4 ) ;
}
static struct V_9 * F_8 ( union V_10 * V_11 )
{
struct V_9 * V_12 ;
V_12 = F_2 ( sizeof *V_12 , V_5 ) ;
if ( ! V_12 )
goto V_6;
V_12 -> V_11 = * V_11 ;
F_9 ( & V_12 -> V_13 ) ;
F_10 ( & V_12 -> V_8 ) ;
F_11 ( & V_12 -> V_7 , 0 ) ;
V_12 -> V_14 = 0 ;
V_6:
return V_12 ;
}
static void F_12 ( struct V_9 * V_12 )
{
struct V_1 * V_15 , * V_16 ;
F_13 (p, tmp, &mcast->qp_list, list)
F_4 ( V_15 ) ;
F_7 ( V_12 ) ;
}
struct V_9 * F_14 ( union V_10 * V_11 )
{
struct V_17 * V_18 ;
unsigned long V_19 ;
struct V_9 * V_12 ;
F_15 ( & V_20 , V_19 ) ;
V_18 = V_21 . V_17 ;
while ( V_18 ) {
int V_22 ;
V_12 = F_16 ( V_18 , struct V_9 , V_17 ) ;
V_22 = memcmp ( V_11 -> V_23 , V_12 -> V_11 . V_23 ,
sizeof( union V_10 ) ) ;
if ( V_22 < 0 )
V_18 = V_18 -> V_24 ;
else if ( V_22 > 0 )
V_18 = V_18 -> V_25 ;
else {
F_3 ( & V_12 -> V_7 ) ;
F_17 ( & V_20 , V_19 ) ;
goto V_6;
}
}
F_17 ( & V_20 , V_19 ) ;
V_12 = NULL ;
V_6:
return V_12 ;
}
static int F_18 ( struct V_26 * V_27 ,
struct V_9 * V_12 ,
struct V_1 * V_4 )
{
struct V_17 * * V_18 = & V_21 . V_17 ;
struct V_17 * V_28 = NULL ;
int V_22 ;
F_19 ( & V_20 ) ;
while ( * V_18 ) {
struct V_9 * V_29 ;
struct V_1 * V_15 ;
V_28 = * V_18 ;
V_29 = F_16 ( V_28 , struct V_9 , V_17 ) ;
V_22 = memcmp ( V_12 -> V_11 . V_23 , V_29 -> V_11 . V_23 ,
sizeof( union V_10 ) ) ;
if ( V_22 < 0 ) {
V_18 = & V_28 -> V_24 ;
continue;
}
if ( V_22 > 0 ) {
V_18 = & V_28 -> V_25 ;
continue;
}
F_20 (p, &tmcast->qp_list, list) {
if ( V_15 -> V_3 == V_4 -> V_3 ) {
V_22 = V_30 ;
goto V_6;
}
}
if ( V_29 -> V_14 == V_31 ) {
V_22 = V_32 ;
goto V_6;
}
V_29 -> V_14 ++ ;
F_21 ( & V_4 -> V_33 , & V_29 -> V_13 ) ;
V_22 = V_34 ;
goto V_6;
}
F_22 ( & V_27 -> V_35 ) ;
if ( V_27 -> V_36 == V_37 ) {
F_23 ( & V_27 -> V_35 ) ;
V_22 = V_32 ;
goto V_6;
}
V_27 -> V_36 ++ ;
F_23 ( & V_27 -> V_35 ) ;
V_12 -> V_14 ++ ;
F_21 ( & V_4 -> V_33 , & V_12 -> V_13 ) ;
F_3 ( & V_12 -> V_7 ) ;
F_24 ( & V_12 -> V_17 , V_28 , V_18 ) ;
F_25 ( & V_12 -> V_17 , & V_21 ) ;
V_22 = 0 ;
V_6:
F_26 ( & V_20 ) ;
return V_22 ;
}
int F_27 ( struct V_38 * V_39 , union V_10 * V_40 , T_1 V_41 )
{
struct V_2 * V_3 = F_28 ( V_39 ) ;
struct V_26 * V_27 = F_29 ( V_39 -> V_42 ) ;
struct V_9 * V_12 ;
struct V_1 * V_4 ;
int V_22 ;
V_12 = F_8 ( V_40 ) ;
if ( V_12 == NULL ) {
V_22 = - V_32 ;
goto V_6;
}
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL ) {
F_12 ( V_12 ) ;
V_22 = - V_32 ;
goto V_6;
}
switch ( F_18 ( V_27 , V_12 , V_4 ) ) {
case V_30 :
F_4 ( V_4 ) ;
F_12 ( V_12 ) ;
V_22 = - V_43 ;
goto V_6;
case V_34 :
F_12 ( V_12 ) ;
break;
case V_32 :
F_4 ( V_4 ) ;
F_12 ( V_12 ) ;
V_22 = - V_32 ;
goto V_6;
default:
break;
}
V_22 = 0 ;
V_6:
return V_22 ;
}
int F_30 ( struct V_38 * V_39 , union V_10 * V_40 , T_1 V_41 )
{
struct V_2 * V_3 = F_28 ( V_39 ) ;
struct V_26 * V_27 = F_29 ( V_39 -> V_42 ) ;
struct V_9 * V_12 = NULL ;
struct V_1 * V_15 , * V_16 ;
struct V_17 * V_18 ;
int V_44 = 0 ;
int V_22 ;
F_19 ( & V_20 ) ;
V_18 = V_21 . V_17 ;
while ( 1 ) {
if ( V_18 == NULL ) {
F_26 ( & V_20 ) ;
V_22 = - V_43 ;
goto V_6;
}
V_12 = F_16 ( V_18 , struct V_9 , V_17 ) ;
V_22 = memcmp ( V_40 -> V_23 , V_12 -> V_11 . V_23 ,
sizeof( union V_10 ) ) ;
if ( V_22 < 0 )
V_18 = V_18 -> V_24 ;
else if ( V_22 > 0 )
V_18 = V_18 -> V_25 ;
else
break;
}
F_13 (p, tmp, &mcast->qp_list, list) {
if ( V_15 -> V_3 != V_3 )
continue;
F_31 ( & V_15 -> V_33 ) ;
V_12 -> V_14 -- ;
if ( F_32 ( & V_12 -> V_13 ) ) {
F_33 ( & V_12 -> V_17 , & V_21 ) ;
V_44 = 1 ;
}
break;
}
F_26 ( & V_20 ) ;
if ( V_15 ) {
F_34 ( V_12 -> V_8 , F_35 ( & V_12 -> V_7 ) <= 1 ) ;
F_4 ( V_15 ) ;
}
if ( V_44 ) {
F_36 ( & V_12 -> V_7 ) ;
F_34 ( V_12 -> V_8 , ! F_35 ( & V_12 -> V_7 ) ) ;
F_12 ( V_12 ) ;
F_19 ( & V_27 -> V_35 ) ;
V_27 -> V_36 -- ;
F_26 ( & V_27 -> V_35 ) ;
}
V_22 = 0 ;
V_6:
return V_22 ;
}
int F_37 ( void )
{
return V_21 . V_17 == NULL ;
}
