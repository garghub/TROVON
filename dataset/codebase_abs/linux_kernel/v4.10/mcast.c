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
static struct V_10 * F_9 ( union V_11 * V_12 )
{
struct V_10 * V_13 ;
V_13 = F_10 ( sizeof( * V_13 ) , V_8 ) ;
if ( ! V_13 )
goto V_9;
V_13 -> V_12 = * V_12 ;
F_11 ( & V_13 -> V_14 ) ;
F_12 ( & V_13 -> V_15 ) ;
F_13 ( & V_13 -> V_16 , 0 ) ;
V_9:
return V_13 ;
}
static void F_14 ( struct V_10 * V_13 )
{
struct V_4 * V_17 , * V_18 ;
F_15 (p, tmp, &mcast->qp_list, list)
F_6 ( V_17 ) ;
F_8 ( V_13 ) ;
}
struct V_10 * F_16 ( struct V_19 * V_20 , union V_11 * V_12 )
{
struct V_21 * V_22 ;
unsigned long V_23 ;
struct V_10 * V_24 = NULL ;
F_17 ( & V_20 -> V_25 , V_23 ) ;
V_22 = V_20 -> V_26 . V_21 ;
while ( V_22 ) {
int V_27 ;
struct V_10 * V_13 ;
V_13 = F_18 ( V_22 , struct V_10 , V_21 ) ;
V_27 = memcmp ( V_12 -> V_28 , V_13 -> V_12 . V_28 ,
sizeof( union V_11 ) ) ;
if ( V_27 < 0 ) {
V_22 = V_22 -> V_29 ;
} else if ( V_27 > 0 ) {
V_22 = V_22 -> V_30 ;
} else {
F_19 ( & V_13 -> V_16 ) ;
V_24 = V_13 ;
break;
}
}
F_20 ( & V_20 -> V_25 , V_23 ) ;
return V_24 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_10 * V_13 , struct V_4 * V_7 )
{
struct V_21 * * V_22 = & V_20 -> V_26 . V_21 ;
struct V_21 * V_31 = NULL ;
int V_27 ;
F_22 ( & V_20 -> V_25 ) ;
while ( * V_22 ) {
struct V_10 * V_32 ;
struct V_4 * V_17 ;
V_31 = * V_22 ;
V_32 = F_18 ( V_31 , struct V_10 , V_21 ) ;
V_27 = memcmp ( V_13 -> V_12 . V_28 , V_32 -> V_12 . V_28 ,
sizeof( union V_11 ) ) ;
if ( V_27 < 0 ) {
V_22 = & V_31 -> V_29 ;
continue;
}
if ( V_27 > 0 ) {
V_22 = & V_31 -> V_30 ;
continue;
}
F_23 (p, &tmcast->qp_list, list) {
if ( V_17 -> V_6 == V_7 -> V_6 ) {
V_27 = V_33 ;
goto V_9;
}
}
if ( V_32 -> V_34 ==
V_2 -> V_35 . V_36 . V_37 ) {
V_27 = V_38 ;
goto V_9;
}
V_32 -> V_34 ++ ;
F_24 ( & V_7 -> V_39 , & V_32 -> V_14 ) ;
V_27 = V_40 ;
goto V_9;
}
F_25 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_41 == V_2 -> V_35 . V_36 . V_42 ) {
F_26 ( & V_2 -> V_3 ) ;
V_27 = V_38 ;
goto V_9;
}
V_2 -> V_41 ++ ;
F_26 ( & V_2 -> V_3 ) ;
V_13 -> V_34 ++ ;
F_24 ( & V_7 -> V_39 , & V_13 -> V_14 ) ;
F_19 ( & V_13 -> V_16 ) ;
F_27 ( & V_13 -> V_21 , V_31 , V_22 ) ;
F_28 ( & V_13 -> V_21 , & V_20 -> V_26 ) ;
V_27 = 0 ;
V_9:
F_29 ( & V_20 -> V_25 ) ;
return V_27 ;
}
int F_30 ( struct V_43 * V_44 , union V_11 * V_45 , T_1 V_46 )
{
struct V_5 * V_6 = F_31 ( V_44 ) ;
struct V_1 * V_2 = F_32 ( V_44 -> V_47 ) ;
struct V_19 * V_20 = V_2 -> V_48 [ V_6 -> V_49 - 1 ] ;
struct V_10 * V_13 ;
struct V_4 * V_7 ;
int V_27 = - V_38 ;
if ( V_44 -> V_50 <= 1 || V_6 -> V_51 == V_52 )
return - V_53 ;
V_13 = F_9 ( V_45 ) ;
if ( ! V_13 )
return - V_38 ;
V_7 = F_3 ( V_6 ) ;
if ( ! V_7 )
goto V_54;
switch ( F_21 ( V_2 , V_20 , V_13 , V_7 ) ) {
case V_33 :
V_27 = 0 ;
goto V_55;
case V_40 :
V_27 = 0 ;
goto V_54;
case V_38 :
V_27 = - V_38 ;
goto V_55;
default:
break;
}
return 0 ;
V_55:
F_6 ( V_7 ) ;
V_54:
F_14 ( V_13 ) ;
return V_27 ;
}
int F_33 ( struct V_43 * V_44 , union V_11 * V_45 , T_1 V_46 )
{
struct V_5 * V_6 = F_31 ( V_44 ) ;
struct V_1 * V_2 = F_32 ( V_44 -> V_47 ) ;
struct V_19 * V_20 = V_2 -> V_48 [ V_6 -> V_49 - 1 ] ;
struct V_10 * V_13 = NULL ;
struct V_4 * V_17 , * V_18 , * V_56 = NULL ;
struct V_21 * V_22 ;
int V_57 = 0 ;
int V_27 = 0 ;
if ( V_44 -> V_50 <= 1 || V_6 -> V_51 == V_52 )
return - V_53 ;
F_22 ( & V_20 -> V_25 ) ;
V_22 = V_20 -> V_26 . V_21 ;
while ( 1 ) {
if ( ! V_22 ) {
F_29 ( & V_20 -> V_25 ) ;
return - V_53 ;
}
V_13 = F_18 ( V_22 , struct V_10 , V_21 ) ;
V_27 = memcmp ( V_45 -> V_28 , V_13 -> V_12 . V_28 ,
sizeof( union V_11 ) ) ;
if ( V_27 < 0 )
V_22 = V_22 -> V_29 ;
else if ( V_27 > 0 )
V_22 = V_22 -> V_30 ;
else
break;
}
F_15 (p, tmp, &mcast->qp_list, list) {
if ( V_17 -> V_6 != V_6 )
continue;
F_34 ( & V_17 -> V_39 ) ;
V_13 -> V_34 -- ;
V_56 = V_17 ;
if ( F_35 ( & V_13 -> V_14 ) ) {
F_36 ( & V_13 -> V_21 , & V_20 -> V_26 ) ;
V_57 = 1 ;
}
break;
}
F_29 ( & V_20 -> V_25 ) ;
if ( ! V_56 )
return - V_53 ;
F_37 ( V_13 -> V_15 , F_38 ( & V_13 -> V_16 ) <= 1 ) ;
F_6 ( V_56 ) ;
if ( V_57 ) {
F_39 ( & V_13 -> V_16 ) ;
F_37 ( V_13 -> V_15 , ! F_38 ( & V_13 -> V_16 ) ) ;
F_14 ( V_13 ) ;
F_22 ( & V_2 -> V_3 ) ;
V_2 -> V_41 -- ;
F_29 ( & V_2 -> V_3 ) ;
}
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
int V_58 ;
int V_59 = 0 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_35 . V_60 ; V_58 ++ )
if ( V_2 -> V_48 [ V_58 ] -> V_26 . V_21 )
V_59 ++ ;
return V_59 ;
}
