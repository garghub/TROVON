static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
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
V_12 = F_2 ( sizeof( * V_12 ) , V_5 ) ;
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
struct V_9 * F_14 ( struct V_17 * V_18 , union V_10 * V_11 )
{
struct V_19 * V_20 ;
unsigned long V_21 ;
struct V_9 * V_12 ;
F_15 ( & V_18 -> V_22 , V_21 ) ;
V_20 = V_18 -> V_23 . V_19 ;
while ( V_20 ) {
int V_24 ;
V_12 = F_16 ( V_20 , struct V_9 , V_19 ) ;
V_24 = memcmp ( V_11 -> V_25 , V_12 -> V_11 . V_25 ,
sizeof( union V_10 ) ) ;
if ( V_24 < 0 )
V_20 = V_20 -> V_26 ;
else if ( V_24 > 0 )
V_20 = V_20 -> V_27 ;
else {
F_3 ( & V_12 -> V_7 ) ;
F_17 ( & V_18 -> V_22 , V_21 ) ;
goto V_6;
}
}
F_17 ( & V_18 -> V_22 , V_21 ) ;
V_12 = NULL ;
V_6:
return V_12 ;
}
static int F_18 ( struct V_28 * V_29 , struct V_17 * V_18 ,
struct V_9 * V_12 , struct V_1 * V_4 )
{
struct V_19 * * V_20 = & V_18 -> V_23 . V_19 ;
struct V_19 * V_30 = NULL ;
int V_24 ;
F_19 ( & V_18 -> V_22 ) ;
while ( * V_20 ) {
struct V_9 * V_31 ;
struct V_1 * V_15 ;
V_30 = * V_20 ;
V_31 = F_16 ( V_30 , struct V_9 , V_19 ) ;
V_24 = memcmp ( V_12 -> V_11 . V_25 , V_31 -> V_11 . V_25 ,
sizeof( union V_10 ) ) ;
if ( V_24 < 0 ) {
V_20 = & V_30 -> V_26 ;
continue;
}
if ( V_24 > 0 ) {
V_20 = & V_30 -> V_27 ;
continue;
}
F_20 (p, &tmcast->qp_list, list) {
if ( V_15 -> V_3 == V_4 -> V_3 ) {
V_24 = V_32 ;
goto V_6;
}
}
if ( V_31 -> V_14 == V_33 ) {
V_24 = V_34 ;
goto V_6;
}
V_31 -> V_14 ++ ;
F_21 ( & V_4 -> V_35 , & V_31 -> V_13 ) ;
V_24 = V_36 ;
goto V_6;
}
F_22 ( & V_29 -> V_37 ) ;
if ( V_29 -> V_38 == V_39 ) {
F_23 ( & V_29 -> V_37 ) ;
V_24 = V_34 ;
goto V_6;
}
V_29 -> V_38 ++ ;
F_23 ( & V_29 -> V_37 ) ;
V_12 -> V_14 ++ ;
F_21 ( & V_4 -> V_35 , & V_12 -> V_13 ) ;
F_3 ( & V_12 -> V_7 ) ;
F_24 ( & V_12 -> V_19 , V_30 , V_20 ) ;
F_25 ( & V_12 -> V_19 , & V_18 -> V_23 ) ;
V_24 = 0 ;
V_6:
F_26 ( & V_18 -> V_22 ) ;
return V_24 ;
}
int F_27 ( struct V_40 * V_41 , union V_10 * V_42 , T_1 V_43 )
{
struct V_2 * V_3 = F_28 ( V_41 ) ;
struct V_28 * V_29 = F_29 ( V_41 -> V_44 ) ;
struct V_17 * V_18 ;
struct V_9 * V_12 ;
struct V_1 * V_4 ;
int V_24 ;
if ( V_41 -> V_45 <= 1 || V_3 -> V_46 == V_47 ) {
V_24 = - V_48 ;
goto V_6;
}
V_12 = F_8 ( V_42 ) ;
if ( V_12 == NULL ) {
V_24 = - V_34 ;
goto V_6;
}
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL ) {
F_12 ( V_12 ) ;
V_24 = - V_34 ;
goto V_6;
}
V_18 = F_30 ( V_41 -> V_44 , V_3 -> V_49 ) ;
switch ( F_18 ( V_29 , V_18 , V_12 , V_4 ) ) {
case V_32 :
F_4 ( V_4 ) ;
F_12 ( V_12 ) ;
break;
case V_36 :
F_12 ( V_12 ) ;
break;
case V_34 :
F_4 ( V_4 ) ;
F_12 ( V_12 ) ;
V_24 = - V_34 ;
goto V_6;
default:
break;
}
V_24 = 0 ;
V_6:
return V_24 ;
}
int F_31 ( struct V_40 * V_41 , union V_10 * V_42 , T_1 V_43 )
{
struct V_2 * V_3 = F_28 ( V_41 ) ;
struct V_28 * V_29 = F_29 ( V_41 -> V_44 ) ;
struct V_17 * V_18 = F_30 ( V_41 -> V_44 , V_3 -> V_49 ) ;
struct V_9 * V_12 = NULL ;
struct V_1 * V_15 , * V_16 , * V_50 = NULL ;
struct V_19 * V_20 ;
int V_51 = 0 ;
int V_24 ;
if ( V_41 -> V_45 <= 1 || V_3 -> V_46 == V_47 )
return - V_48 ;
F_19 ( & V_18 -> V_22 ) ;
V_20 = V_18 -> V_23 . V_19 ;
while ( 1 ) {
if ( V_20 == NULL ) {
F_26 ( & V_18 -> V_22 ) ;
return - V_48 ;
}
V_12 = F_16 ( V_20 , struct V_9 , V_19 ) ;
V_24 = memcmp ( V_42 -> V_25 , V_12 -> V_11 . V_25 ,
sizeof( union V_10 ) ) ;
if ( V_24 < 0 )
V_20 = V_20 -> V_26 ;
else if ( V_24 > 0 )
V_20 = V_20 -> V_27 ;
else
break;
}
F_13 (p, tmp, &mcast->qp_list, list) {
if ( V_15 -> V_3 != V_3 )
continue;
F_32 ( & V_15 -> V_35 ) ;
V_12 -> V_14 -- ;
V_50 = V_15 ;
if ( F_33 ( & V_12 -> V_13 ) ) {
F_34 ( & V_12 -> V_19 , & V_18 -> V_23 ) ;
V_51 = 1 ;
}
break;
}
F_26 ( & V_18 -> V_22 ) ;
if ( ! V_50 )
return - V_48 ;
F_35 ( V_12 -> V_8 , F_36 ( & V_12 -> V_7 ) <= 1 ) ;
F_4 ( V_50 ) ;
if ( V_51 ) {
F_37 ( & V_12 -> V_7 ) ;
F_35 ( V_12 -> V_8 , ! F_36 ( & V_12 -> V_7 ) ) ;
F_12 ( V_12 ) ;
F_19 ( & V_29 -> V_37 ) ;
V_29 -> V_38 -- ;
F_26 ( & V_29 -> V_37 ) ;
}
return 0 ;
}
int F_38 ( struct V_17 * V_18 )
{
return V_18 -> V_23 . V_19 == NULL ;
}
