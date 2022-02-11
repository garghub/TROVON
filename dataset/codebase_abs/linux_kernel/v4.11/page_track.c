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
sizeof( * V_7 -> V_5 . V_6 [ V_3 ] ) ) ;
if ( ! V_7 -> V_5 . V_6 [ V_3 ] )
goto V_9;
}
return 0 ;
V_9:
F_1 ( V_7 , NULL ) ;
return - V_10 ;
}
static inline bool F_5 ( enum V_11 V_12 )
{
if ( V_12 < 0 || V_12 >= V_4 )
return false ;
return true ;
}
static void F_6 ( struct V_1 * V_7 , T_1 V_13 ,
enum V_11 V_12 , short V_14 )
{
int V_15 , V_16 ;
V_15 = F_7 ( V_13 , V_7 -> V_17 , V_18 ) ;
V_16 = V_7 -> V_5 . V_6 [ V_12 ] [ V_15 ] ;
if ( F_8 ( V_16 + V_14 < 0 || V_16 + V_14 > V_19 ) )
return;
V_7 -> V_5 . V_6 [ V_12 ] [ V_15 ] += V_14 ;
}
void F_9 ( struct V_20 * V_20 ,
struct V_1 * V_7 , T_1 V_13 ,
enum V_11 V_12 )
{
if ( F_8 ( ! F_5 ( V_12 ) ) )
return;
F_6 ( V_7 , V_13 , V_12 , 1 ) ;
F_10 ( V_7 , V_13 ) ;
if ( V_12 == V_21 )
if ( F_11 ( V_20 , V_7 , V_13 ) )
F_12 ( V_20 ) ;
}
void F_13 ( struct V_20 * V_20 ,
struct V_1 * V_7 , T_1 V_13 ,
enum V_11 V_12 )
{
if ( F_8 ( ! F_5 ( V_12 ) ) )
return;
F_6 ( V_7 , V_13 , V_12 , - 1 ) ;
F_14 ( V_7 , V_13 ) ;
}
bool F_15 ( struct V_22 * V_23 , T_1 V_13 ,
enum V_11 V_12 )
{
struct V_1 * V_7 ;
int V_15 ;
if ( F_8 ( ! F_5 ( V_12 ) ) )
return false ;
V_7 = F_16 ( V_23 , V_13 ) ;
if ( ! V_7 )
return false ;
V_15 = F_7 ( V_13 , V_7 -> V_17 , V_18 ) ;
return ! ! F_17 ( V_7 -> V_5 . V_6 [ V_12 ] [ V_15 ] ) ;
}
void F_18 ( struct V_20 * V_20 )
{
struct V_24 * V_25 ;
V_25 = & V_20 -> V_5 . V_26 ;
F_19 ( & V_25 -> V_27 ) ;
}
void F_20 ( struct V_20 * V_20 )
{
struct V_24 * V_25 ;
V_25 = & V_20 -> V_5 . V_26 ;
F_21 ( & V_25 -> V_27 ) ;
F_22 ( & V_25 -> V_28 ) ;
}
void
F_23 ( struct V_20 * V_20 ,
struct V_29 * V_30 )
{
struct V_24 * V_25 ;
V_25 = & V_20 -> V_5 . V_26 ;
F_24 ( & V_20 -> V_31 ) ;
F_25 ( & V_30 -> V_32 , & V_25 -> V_28 ) ;
F_26 ( & V_20 -> V_31 ) ;
}
void
F_27 ( struct V_20 * V_20 ,
struct V_29 * V_30 )
{
struct V_24 * V_25 ;
V_25 = & V_20 -> V_5 . V_26 ;
F_24 ( & V_20 -> V_31 ) ;
F_28 ( & V_30 -> V_32 ) ;
F_26 ( & V_20 -> V_31 ) ;
F_29 ( & V_25 -> V_27 ) ;
}
void F_30 ( struct V_22 * V_23 , T_2 V_33 , const T_3 * V_34 ,
int V_35 )
{
struct V_24 * V_25 ;
struct V_29 * V_30 ;
int V_36 ;
V_25 = & V_23 -> V_20 -> V_5 . V_26 ;
if ( F_31 ( & V_25 -> V_28 ) )
return;
V_36 = F_32 ( & V_25 -> V_27 ) ;
F_33 (n, &head->track_notifier_list, node)
if ( V_30 -> V_37 )
V_30 -> V_37 ( V_23 , V_33 , V_34 , V_35 , V_30 ) ;
F_34 ( & V_25 -> V_27 , V_36 ) ;
}
void F_35 ( struct V_20 * V_20 , struct V_1 * V_7 )
{
struct V_24 * V_25 ;
struct V_29 * V_30 ;
int V_36 ;
V_25 = & V_20 -> V_5 . V_26 ;
if ( F_31 ( & V_25 -> V_28 ) )
return;
V_36 = F_32 ( & V_25 -> V_27 ) ;
F_33 (n, &head->track_notifier_list, node)
if ( V_30 -> V_38 )
V_30 -> V_38 ( V_20 , V_7 , V_30 ) ;
F_34 ( & V_25 -> V_27 , V_36 ) ;
}
