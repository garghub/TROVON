static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 ) ;
F_4 ( & V_4 -> V_6 ) ;
V_4 -> V_7 = 0 ;
F_5 ( & V_4 -> V_6 ) ;
}
static struct V_8 * F_6 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_8 * V_13 , * V_14 = NULL ;
int V_15 = V_16 ;
F_7 (p, e, root, u.rb) {
if ( V_13 -> V_17 < V_18 && V_13 -> V_19 < V_15 ) {
V_14 = V_13 ;
V_15 = V_13 -> V_19 ;
}
}
return V_14 ;
}
static void F_8 ( struct V_3 * V_4 ,
struct V_20 * V_21 )
{
int V_22 ;
struct V_8 * V_13 ;
for ( V_22 = V_21 -> V_23 ; V_22 < V_21 -> V_24 ; V_22 ++ ) {
V_13 = V_4 -> V_25 [ V_21 -> V_26 [ V_22 ] ] ;
F_9 ( V_13 , & V_4 -> free ) ;
V_4 -> V_27 ++ ;
}
}
static int F_10 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_8 * V_13 ;
F_7 (p, e, root, u.rb)
if ( V_13 -> V_17 < V_18 )
return 1 ;
return 0 ;
}
struct V_8 * F_11 ( struct V_3 * V_4 , int V_28 )
{
struct V_8 * V_13 = NULL ;
if ( ! V_4 -> free . V_11 || ( V_4 -> V_27 - V_4 -> V_29 < 1 ) )
goto V_30;
if ( V_28 )
V_13 = F_6 ( & V_4 -> free ) ;
else
V_13 = F_12 ( V_4 , & V_4 -> free ) ;
if ( ! V_13 )
goto V_30;
F_13 ( V_4 , V_13 , & V_4 -> free ) ;
F_14 ( & V_13 -> V_31 . V_32 , & V_4 -> free ) ;
V_4 -> V_27 -- ;
V_30:
return V_13 ;
}
void F_15 ( struct V_3 * V_4 )
{
struct V_20 * V_33 = & V_4 -> V_34 ;
struct V_20 * V_21 = & V_4 -> V_35 ;
struct V_8 * V_13 ;
int V_36 ;
F_4 ( & V_4 -> V_6 ) ;
F_8 ( V_4 , V_33 ) ;
F_8 ( V_4 , V_21 ) ;
V_33 -> V_24 = 0 ;
V_21 -> V_24 = 0 ;
for (; ; ) {
V_36 = 0 ;
if ( V_21 -> V_24 < V_21 -> V_37 ) {
if ( ! V_4 -> free . V_11 )
break;
V_13 = F_16 ( V_4 ) ;
if ( ! V_13 )
break;
V_21 -> V_26 [ V_21 -> V_24 ] = V_13 -> V_17 ;
V_21 -> V_24 ++ ;
} else
V_36 ++ ;
if ( V_33 -> V_24 < V_33 -> V_37 ) {
if ( ! V_4 -> free . V_11 ||
( V_4 -> V_27 - V_4 -> V_29 < 5 ) )
break;
V_13 = F_17 ( V_4 , & V_4 -> free , V_38 ) ;
F_13 ( V_4 , V_13 , & V_4 -> free ) ;
F_14 ( & V_13 -> V_31 . V_32 , & V_4 -> free ) ;
V_4 -> V_27 -- ;
V_33 -> V_26 [ V_33 -> V_24 ] = V_13 -> V_17 ;
V_33 -> V_24 ++ ;
} else
V_36 ++ ;
if ( V_36 == 2 )
break;
}
V_33 -> V_23 = 0 ;
V_21 -> V_23 = 0 ;
F_5 ( & V_4 -> V_6 ) ;
}
int F_18 ( struct V_3 * V_4 )
{
int V_39 , V_40 = 0 ;
struct V_20 * V_21 = & V_4 -> V_35 ;
struct V_20 * V_33 = & V_4 -> V_34 ;
V_41:
F_19 ( & V_4 -> V_42 ) ;
F_4 ( & V_4 -> V_6 ) ;
if ( V_21 -> V_23 == V_21 -> V_24 || V_33 -> V_23 == V_33 -> V_24 ) {
F_5 ( & V_4 -> V_6 ) ;
F_20 ( & V_4 -> V_42 ) ;
V_39 = F_3 ( V_4 ) ;
if ( V_39 ) {
F_21 ( V_4 , L_1 , V_39 ) ;
F_19 ( & V_4 -> V_42 ) ;
return - V_43 ;
}
F_19 ( & V_4 -> V_42 ) ;
F_4 ( & V_4 -> V_6 ) ;
}
if ( V_21 -> V_23 == V_21 -> V_24 ) {
F_5 ( & V_4 -> V_6 ) ;
if ( V_40 ) {
F_22 ( V_4 , L_2 ) ;
V_39 = - V_43 ;
goto V_30;
}
V_40 = 1 ;
F_20 ( & V_4 -> V_42 ) ;
goto V_41;
}
F_23 ( V_21 -> V_23 < V_21 -> V_24 ) ;
V_39 = V_21 -> V_26 [ V_21 -> V_23 ++ ] ;
F_24 ( V_4 , V_4 -> V_25 [ V_39 ] ) ;
F_5 ( & V_4 -> V_6 ) ;
V_30:
return V_39 ;
}
static struct V_8 * F_25 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = & V_4 -> V_34 ;
int V_17 ;
if ( V_21 -> V_23 == V_21 -> V_24 ) {
if ( ! V_4 -> V_7 ) {
V_4 -> V_7 = 1 ;
F_26 ( & V_4 -> V_5 ) ;
}
return NULL ;
}
V_17 = V_21 -> V_26 [ V_21 -> V_23 ++ ] ;
return V_4 -> V_25 [ V_17 ] ;
}
int F_27 ( struct V_3 * V_4 )
{
struct V_44 * V_2 ;
F_4 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_45 ) {
F_5 ( & V_4 -> V_6 ) ;
return 0 ;
}
V_4 -> V_45 = 1 ;
F_5 ( & V_4 -> V_6 ) ;
V_2 = F_28 ( sizeof( struct V_44 ) , V_46 ) ;
if ( ! V_2 ) {
F_4 ( & V_4 -> V_6 ) ;
V_4 -> V_45 = 0 ;
F_5 ( & V_4 -> V_6 ) ;
return - V_47 ;
}
V_2 -> V_28 = 1 ;
V_2 -> V_48 = & V_49 ;
F_29 ( V_4 , V_2 ) ;
return 0 ;
}
int F_30 ( struct V_3 * V_4 , struct V_8 * V_50 ,
int V_51 , int V_52 )
{
struct V_8 * V_13 ;
int V_53 , V_17 = V_50 -> V_17 ;
F_31 ( L_3 , V_17 ) ;
F_23 ( V_17 >= 0 ) ;
F_23 ( V_17 < V_4 -> V_54 ) ;
F_4 ( & V_4 -> V_6 ) ;
V_13 = V_4 -> V_25 [ V_17 ] ;
if ( ! V_13 ) {
V_13 = V_50 ;
F_23 ( V_13 -> V_19 >= 0 ) ;
V_4 -> V_25 [ V_17 ] = V_13 ;
}
F_5 ( & V_4 -> V_6 ) ;
V_53 = V_51 ? V_55 : V_56 ;
return F_32 ( V_4 , V_13 , V_53 , V_51 , V_52 ) ;
}
int F_33 ( struct V_44 * V_2 )
{
return V_2 -> V_48 == V_57 ;
}
static void F_34 ( struct V_3 * V_4 )
{
int V_22 ;
F_35 ( & V_4 -> V_5 ) ;
F_8 ( V_4 , & V_4 -> V_35 ) ;
F_8 ( V_4 , & V_4 -> V_34 ) ;
if ( V_4 -> V_58 ) {
for ( V_22 = 0 ; V_22 < V_4 -> V_58 -> V_59 ; V_22 ++ )
F_36 ( V_4 -> V_58 -> V_13 [ V_22 ] ) ;
}
F_36 ( V_4 -> V_58 ) ;
}
static struct V_8 * F_37 ( struct V_3 * V_4 ,
struct V_8 * V_13 ,
struct V_9 * V_10 ) {
if ( V_13 && ! V_4 -> V_60 && ! V_4 -> V_58 &&
V_13 -> V_17 < V_18 )
V_13 = F_38 ( F_39 ( V_10 -> V_11 ) ,
struct V_8 , V_31 . V_32 ) ;
return V_13 ;
}
