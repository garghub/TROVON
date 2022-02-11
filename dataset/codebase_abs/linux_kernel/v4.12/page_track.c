void F_1 ( struct V_1 * free ,
struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
if ( ! V_2 || free -> V_5 . V_6 [ V_3 ] !=
V_2 -> V_5 . V_6 [ V_3 ] ) {
F_2 ( free -> V_5 . V_6 [ V_3 ] ) ;
free -> V_5 . V_6 [ V_3 ] = NULL ;
}
}
int F_3 ( struct V_1 * V_7 ,
unsigned long V_8 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_7 -> V_5 . V_6 [ V_3 ] = F_4 ( V_8 *
sizeof( * V_7 -> V_5 . V_6 [ V_3 ] ) , V_9 ) ;
if ( ! V_7 -> V_5 . V_6 [ V_3 ] )
goto V_10;
}
return 0 ;
V_10:
F_1 ( V_7 , NULL ) ;
return - V_11 ;
}
static inline bool F_5 ( enum V_12 V_13 )
{
if ( V_13 < 0 || V_13 >= V_4 )
return false ;
return true ;
}
static void F_6 ( struct V_1 * V_7 , T_1 V_14 ,
enum V_12 V_13 , short V_15 )
{
int V_16 , V_17 ;
V_16 = F_7 ( V_14 , V_7 -> V_18 , V_19 ) ;
V_17 = V_7 -> V_5 . V_6 [ V_13 ] [ V_16 ] ;
if ( F_8 ( V_17 + V_15 < 0 || V_17 + V_15 > V_20 ) )
return;
V_7 -> V_5 . V_6 [ V_13 ] [ V_16 ] += V_15 ;
}
void F_9 ( struct V_21 * V_21 ,
struct V_1 * V_7 , T_1 V_14 ,
enum V_12 V_13 )
{
if ( F_8 ( ! F_5 ( V_13 ) ) )
return;
F_6 ( V_7 , V_14 , V_13 , 1 ) ;
F_10 ( V_7 , V_14 ) ;
if ( V_13 == V_22 )
if ( F_11 ( V_21 , V_7 , V_14 ) )
F_12 ( V_21 ) ;
}
void F_13 ( struct V_21 * V_21 ,
struct V_1 * V_7 , T_1 V_14 ,
enum V_12 V_13 )
{
if ( F_8 ( ! F_5 ( V_13 ) ) )
return;
F_6 ( V_7 , V_14 , V_13 , - 1 ) ;
F_14 ( V_7 , V_14 ) ;
}
bool F_15 ( struct V_23 * V_24 , T_1 V_14 ,
enum V_12 V_13 )
{
struct V_1 * V_7 ;
int V_16 ;
if ( F_8 ( ! F_5 ( V_13 ) ) )
return false ;
V_7 = F_16 ( V_24 , V_14 ) ;
if ( ! V_7 )
return false ;
V_16 = F_7 ( V_14 , V_7 -> V_18 , V_19 ) ;
return ! ! F_17 ( V_7 -> V_5 . V_6 [ V_13 ] [ V_16 ] ) ;
}
void F_18 ( struct V_21 * V_21 )
{
struct V_25 * V_26 ;
V_26 = & V_21 -> V_5 . V_27 ;
F_19 ( & V_26 -> V_28 ) ;
}
void F_20 ( struct V_21 * V_21 )
{
struct V_25 * V_26 ;
V_26 = & V_21 -> V_5 . V_27 ;
F_21 ( & V_26 -> V_28 ) ;
F_22 ( & V_26 -> V_29 ) ;
}
void
F_23 ( struct V_21 * V_21 ,
struct V_30 * V_31 )
{
struct V_25 * V_26 ;
V_26 = & V_21 -> V_5 . V_27 ;
F_24 ( & V_21 -> V_32 ) ;
F_25 ( & V_31 -> V_33 , & V_26 -> V_29 ) ;
F_26 ( & V_21 -> V_32 ) ;
}
void
F_27 ( struct V_21 * V_21 ,
struct V_30 * V_31 )
{
struct V_25 * V_26 ;
V_26 = & V_21 -> V_5 . V_27 ;
F_24 ( & V_21 -> V_32 ) ;
F_28 ( & V_31 -> V_33 ) ;
F_26 ( & V_21 -> V_32 ) ;
F_29 ( & V_26 -> V_28 ) ;
}
void F_30 ( struct V_23 * V_24 , T_2 V_34 , const T_3 * V_35 ,
int V_36 )
{
struct V_25 * V_26 ;
struct V_30 * V_31 ;
int V_37 ;
V_26 = & V_24 -> V_21 -> V_5 . V_27 ;
if ( F_31 ( & V_26 -> V_29 ) )
return;
V_37 = F_32 ( & V_26 -> V_28 ) ;
F_33 (n, &head->track_notifier_list, node)
if ( V_31 -> V_38 )
V_31 -> V_38 ( V_24 , V_34 , V_35 , V_36 , V_31 ) ;
F_34 ( & V_26 -> V_28 , V_37 ) ;
}
void F_35 ( struct V_21 * V_21 , struct V_1 * V_7 )
{
struct V_25 * V_26 ;
struct V_30 * V_31 ;
int V_37 ;
V_26 = & V_21 -> V_5 . V_27 ;
if ( F_31 ( & V_26 -> V_29 ) )
return;
V_37 = F_32 ( & V_26 -> V_28 ) ;
F_33 (n, &head->track_notifier_list, node)
if ( V_31 -> V_39 )
V_31 -> V_39 ( V_21 , V_7 , V_31 ) ;
F_34 ( & V_26 -> V_28 , V_37 ) ;
}
