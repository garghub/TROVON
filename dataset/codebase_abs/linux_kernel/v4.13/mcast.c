void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static struct V_4 * F_3 ( struct V_5 * V_6 )
{
struct V_4 * V_7 ;
V_7 = F_4 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
goto V_9;
V_7 -> V_6 = V_6 ;
F_5 ( V_6 ) ;
V_9:
return V_7 ;
}
static void F_6 ( struct V_4 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_6 ;
F_7 ( V_6 ) ;
F_8 ( V_7 ) ;
}
static struct V_10 * F_9 ( union V_11 * V_12 , T_1 V_13 )
{
struct V_10 * V_14 ;
V_14 = F_10 ( sizeof( * V_14 ) , V_8 ) ;
if ( ! V_14 )
goto V_9;
V_14 -> V_15 . V_12 = * V_12 ;
V_14 -> V_15 . V_13 = V_13 ;
F_11 ( & V_14 -> V_16 ) ;
F_12 ( & V_14 -> V_17 ) ;
F_13 ( & V_14 -> V_18 , 0 ) ;
V_9:
return V_14 ;
}
static void F_14 ( struct V_10 * V_14 )
{
struct V_4 * V_19 , * V_20 ;
F_15 (p, tmp, &mcast->qp_list, list)
F_6 ( V_19 ) ;
F_8 ( V_14 ) ;
}
struct V_10 * F_16 ( struct V_21 * V_22 , union V_11 * V_12 ,
T_1 V_13 )
{
struct V_23 * V_24 ;
unsigned long V_25 ;
struct V_10 * V_26 = NULL ;
F_17 ( & V_22 -> V_27 , V_25 ) ;
V_24 = V_22 -> V_28 . V_23 ;
while ( V_24 ) {
int V_29 ;
struct V_10 * V_14 ;
V_14 = F_18 ( V_24 , struct V_10 , V_23 ) ;
V_29 = memcmp ( V_12 -> V_30 , V_14 -> V_15 . V_12 . V_30 ,
sizeof( * V_12 ) ) ;
if ( V_29 < 0 ) {
V_24 = V_24 -> V_31 ;
} else if ( V_29 > 0 ) {
V_24 = V_24 -> V_32 ;
} else {
if ( V_14 -> V_15 . V_13 == V_13 ) {
F_19 ( & V_14 -> V_18 ) ;
V_26 = V_14 ;
}
break;
}
}
F_20 ( & V_22 -> V_27 , V_25 ) ;
return V_26 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_10 * V_14 , struct V_4 * V_7 )
{
struct V_23 * * V_24 = & V_22 -> V_28 . V_23 ;
struct V_23 * V_33 = NULL ;
int V_29 ;
F_22 ( & V_22 -> V_27 ) ;
while ( * V_24 ) {
struct V_10 * V_34 ;
struct V_4 * V_19 ;
V_33 = * V_24 ;
V_34 = F_18 ( V_33 , struct V_10 , V_23 ) ;
V_29 = memcmp ( V_14 -> V_15 . V_12 . V_30 ,
V_34 -> V_15 . V_12 . V_30 ,
sizeof( V_14 -> V_15 . V_12 ) ) ;
if ( V_29 < 0 ) {
V_24 = & V_33 -> V_31 ;
continue;
}
if ( V_29 > 0 ) {
V_24 = & V_33 -> V_32 ;
continue;
}
if ( V_34 -> V_15 . V_13 != V_14 -> V_15 . V_13 ) {
V_29 = V_35 ;
goto V_9;
}
F_23 (p, &tmcast->qp_list, list) {
if ( V_19 -> V_6 == V_7 -> V_6 ) {
V_29 = V_36 ;
goto V_9;
}
}
if ( V_34 -> V_37 ==
V_2 -> V_38 . V_39 . V_40 ) {
V_29 = V_41 ;
goto V_9;
}
V_34 -> V_37 ++ ;
F_24 ( & V_7 -> V_42 , & V_34 -> V_16 ) ;
V_29 = V_43 ;
goto V_9;
}
F_25 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_44 == V_2 -> V_38 . V_39 . V_45 ) {
F_26 ( & V_2 -> V_3 ) ;
V_29 = V_41 ;
goto V_9;
}
V_2 -> V_44 ++ ;
F_26 ( & V_2 -> V_3 ) ;
V_14 -> V_37 ++ ;
F_24 ( & V_7 -> V_42 , & V_14 -> V_16 ) ;
F_19 ( & V_14 -> V_18 ) ;
F_27 ( & V_14 -> V_23 , V_33 , V_24 ) ;
F_28 ( & V_14 -> V_23 , & V_22 -> V_28 ) ;
V_29 = 0 ;
V_9:
F_29 ( & V_22 -> V_27 ) ;
return V_29 ;
}
int F_30 ( struct V_46 * V_47 , union V_11 * V_48 , T_1 V_13 )
{
struct V_5 * V_6 = F_31 ( V_47 ) ;
struct V_1 * V_2 = F_32 ( V_47 -> V_49 ) ;
struct V_21 * V_22 = V_2 -> V_50 [ V_6 -> V_51 - 1 ] ;
struct V_10 * V_14 ;
struct V_4 * V_7 ;
int V_29 = - V_41 ;
if ( V_47 -> V_52 <= 1 || V_6 -> V_53 == V_54 )
return - V_35 ;
V_14 = F_9 ( V_48 , V_13 ) ;
if ( ! V_14 )
return - V_41 ;
V_7 = F_3 ( V_6 ) ;
if ( ! V_7 )
goto V_55;
switch ( F_21 ( V_2 , V_22 , V_14 , V_7 ) ) {
case V_36 :
V_29 = 0 ;
goto V_56;
case V_43 :
V_29 = 0 ;
goto V_55;
case V_41 :
V_29 = - V_41 ;
goto V_56;
case V_35 :
V_29 = - V_35 ;
goto V_56;
default:
break;
}
return 0 ;
V_56:
F_6 ( V_7 ) ;
V_55:
F_14 ( V_14 ) ;
return V_29 ;
}
int F_33 ( struct V_46 * V_47 , union V_11 * V_48 , T_1 V_13 )
{
struct V_5 * V_6 = F_31 ( V_47 ) ;
struct V_1 * V_2 = F_32 ( V_47 -> V_49 ) ;
struct V_21 * V_22 = V_2 -> V_50 [ V_6 -> V_51 - 1 ] ;
struct V_10 * V_14 = NULL ;
struct V_4 * V_19 , * V_20 , * V_57 = NULL ;
struct V_23 * V_24 ;
int V_58 = 0 ;
int V_29 = 0 ;
if ( V_47 -> V_52 <= 1 || V_6 -> V_53 == V_54 )
return - V_35 ;
F_22 ( & V_22 -> V_27 ) ;
V_24 = V_22 -> V_28 . V_23 ;
while ( 1 ) {
if ( ! V_24 ) {
F_29 ( & V_22 -> V_27 ) ;
return - V_35 ;
}
V_14 = F_18 ( V_24 , struct V_10 , V_23 ) ;
V_29 = memcmp ( V_48 -> V_30 , V_14 -> V_15 . V_12 . V_30 ,
sizeof( * V_48 ) ) ;
if ( V_29 < 0 ) {
V_24 = V_24 -> V_31 ;
} else if ( V_29 > 0 ) {
V_24 = V_24 -> V_32 ;
} else {
if ( V_14 -> V_15 . V_13 != V_13 ) {
F_29 ( & V_22 -> V_27 ) ;
return - V_35 ;
}
break;
}
}
F_15 (p, tmp, &mcast->qp_list, list) {
if ( V_19 -> V_6 != V_6 )
continue;
F_34 ( & V_19 -> V_42 ) ;
V_14 -> V_37 -- ;
V_57 = V_19 ;
if ( F_35 ( & V_14 -> V_16 ) ) {
F_36 ( & V_14 -> V_23 , & V_22 -> V_28 ) ;
V_58 = 1 ;
}
break;
}
F_29 ( & V_22 -> V_27 ) ;
if ( ! V_57 )
return - V_35 ;
F_37 ( V_14 -> V_17 , F_38 ( & V_14 -> V_18 ) <= 1 ) ;
F_6 ( V_57 ) ;
if ( V_58 ) {
F_39 ( & V_14 -> V_18 ) ;
F_37 ( V_14 -> V_17 , ! F_38 ( & V_14 -> V_18 ) ) ;
F_14 ( V_14 ) ;
F_22 ( & V_2 -> V_3 ) ;
V_2 -> V_44 -- ;
F_29 ( & V_2 -> V_3 ) ;
}
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
int V_59 ;
int V_60 = 0 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_38 . V_61 ; V_59 ++ )
if ( V_2 -> V_50 [ V_59 ] -> V_28 . V_23 )
V_60 ++ ;
return V_60 ;
}
