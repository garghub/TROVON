static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 1 ; V_3 <= V_2 -> V_4 . V_5 ; V_3 ++ )
F_2 ( & V_2 -> V_6 [ V_3 ] ) ;
}
static void F_2 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
if ( F_3 ( V_8 ) )
return;
if ( V_8 -> V_4 . type != V_9 )
return;
if ( V_8 -> V_10 && V_8 -> V_11 )
return;
if ( F_4 ( V_8 , false ) <= 0 )
return;
if ( V_8 -> V_12 ) {
F_5 ( V_8 , L_1 ) ;
return;
}
V_2 = F_6 ( V_8 -> V_2 -> V_13 , F_7 ( V_8 ) ) ;
if ( ! V_2 )
return;
V_8 -> V_12 = F_8 ( V_2 ) ;
F_8 ( V_2 ) -> V_12 = V_8 ;
F_1 ( V_2 ) ;
}
static void F_9 ( struct V_13 * V_13 )
{
struct V_14 * V_15 ;
struct V_14 * V_16 ;
F_10 (tunnel, n, &tb->tunnel_list, list)
{
if ( F_11 ( V_15 ) ) {
F_12 ( V_15 ) ;
F_13 ( V_15 ) ;
}
}
}
static void F_14 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 1 ; V_3 <= V_2 -> V_4 . V_5 ; V_3 ++ ) {
struct V_7 * V_8 = & V_2 -> V_6 [ V_3 ] ;
if ( F_3 ( V_8 ) )
continue;
if ( ! V_8 -> V_12 )
continue;
if ( V_8 -> V_12 -> V_2 -> V_17 ) {
F_15 ( V_8 -> V_12 -> V_2 ) ;
V_8 -> V_12 = NULL ;
} else {
F_14 ( V_8 -> V_12 -> V_2 ) ;
}
}
}
static struct V_7 * F_16 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 1 ; V_3 <= V_2 -> V_4 . V_5 ; V_3 ++ )
if ( V_2 -> V_6 [ V_3 ] . V_4 . type == V_18 )
return & V_2 -> V_6 [ V_3 ] ;
return NULL ;
}
static struct V_7 * F_17 ( struct V_1 * V_2 )
{
int V_3 ;
int V_19 ;
int V_20 ;
int V_21 ;
for ( V_3 = 1 ; V_3 <= V_2 -> V_4 . V_5 ; V_3 ++ ) {
if ( F_3 ( & V_2 -> V_6 [ V_3 ] ) )
continue;
if ( V_2 -> V_6 [ V_3 ] . V_4 . type != V_22 )
continue;
V_19 = F_18 ( & V_2 -> V_6 [ V_3 ] , V_23 , V_24 ) ;
if ( V_19 <= 0 )
continue;
V_20 = F_19 ( & V_2 -> V_6 [ V_3 ] , & V_21 , V_23 , V_19 , 1 ) ;
if ( V_20 < 0 )
continue;
if ( V_21 & 0x80000000 )
continue;
return & V_2 -> V_6 [ V_3 ] ;
}
return NULL ;
}
static void F_20 ( struct V_13 * V_13 )
{
int V_3 ;
int V_19 ;
T_1 V_21 ;
struct V_1 * V_2 ;
struct V_7 * V_25 ;
struct V_7 * V_26 ;
struct V_14 * V_15 ;
for ( V_3 = 1 ; V_3 <= V_13 -> V_27 -> V_4 . V_5 ; V_3 ++ ) {
if ( F_3 ( & V_13 -> V_27 -> V_6 [ V_3 ] ) )
continue;
if ( V_13 -> V_27 -> V_6 [ V_3 ] . V_4 . type != V_9 )
continue;
if ( ! V_13 -> V_27 -> V_6 [ V_3 ] . V_12 )
continue;
V_2 = V_13 -> V_27 -> V_6 [ V_3 ] . V_12 -> V_2 ;
V_25 = F_16 ( V_2 ) ;
if ( ! V_25 ) {
F_21 ( V_2 , L_2 ) ;
continue;
}
V_19 = F_18 ( V_25 , V_23 , V_24 ) ;
if ( V_19 <= 0 )
continue;
if ( F_19 ( V_25 , & V_21 , V_23 , V_19 , 1 ) )
continue;
if ( V_21 & 0x80000000 ) {
F_22 ( V_25 ,
L_3 ) ;
continue;
}
V_26 = F_17 ( V_13 -> V_27 ) ;
if ( ! V_26 ) {
F_22 ( V_25 ,
L_4 ) ;
continue;
}
V_15 = F_23 ( V_13 , V_25 , V_26 ) ;
if ( ! V_15 ) {
F_22 ( V_25 ,
L_5 ) ;
continue;
}
if ( F_24 ( V_15 ) ) {
F_22 ( V_25 ,
L_6 ) ;
F_13 ( V_15 ) ;
}
}
}
static void F_25 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_26 ( V_29 , F_27 ( * V_31 ) , V_29 ) ;
struct V_13 * V_13 = V_31 -> V_13 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
F_28 ( & V_13 -> V_32 ) ;
if ( ! V_13 -> V_33 )
goto V_34;
V_2 = F_29 ( V_13 -> V_27 , V_31 -> V_35 ) ;
if ( ! V_2 ) {
F_30 ( V_13 ,
L_7 ,
V_31 -> V_35 , V_31 -> V_8 , V_31 -> V_36 ) ;
goto V_34;
}
if ( V_31 -> V_8 > V_2 -> V_4 . V_5 ) {
F_30 ( V_13 ,
L_8 ,
V_31 -> V_35 , V_31 -> V_8 , V_31 -> V_36 ) ;
goto V_34;
}
V_8 = & V_2 -> V_6 [ V_31 -> V_8 ] ;
if ( F_3 ( V_8 ) ) {
F_30 ( V_13 ,
L_9 ,
V_31 -> V_35 , V_31 -> V_8 , V_31 -> V_36 ) ;
goto V_34;
}
if ( V_31 -> V_36 ) {
if ( V_8 -> V_12 ) {
F_22 ( V_8 , L_10 ) ;
F_31 ( V_8 -> V_12 -> V_2 ) ;
F_9 ( V_13 ) ;
F_15 ( V_8 -> V_12 -> V_2 ) ;
V_8 -> V_12 = NULL ;
} else {
F_22 ( V_8 ,
L_11 ) ;
}
} else if ( V_8 -> V_12 ) {
F_22 ( V_8 ,
L_12 ) ;
} else {
F_22 ( V_8 , L_13 ) ;
F_2 ( V_8 ) ;
if ( ! V_8 -> V_12 ) {
F_22 ( V_8 , L_14 ) ;
} else if ( V_8 -> V_12 -> V_2 -> V_4 . V_37 > 1 ) {
F_32 ( V_8 -> V_12 -> V_2 ,
L_15 ) ;
} else {
F_21 ( V_8 -> V_12 -> V_2 ,
L_16 ) ;
F_20 ( V_13 ) ;
}
}
V_34:
F_33 ( & V_13 -> V_32 ) ;
F_34 ( V_31 ) ;
}
static void F_35 ( void * V_21 , T_2 V_35 , T_3 V_8 ,
bool V_36 )
{
struct V_13 * V_13 = V_21 ;
struct V_30 * V_31 = F_36 ( sizeof( * V_31 ) , V_38 ) ;
if ( ! V_31 )
return;
F_37 ( & V_31 -> V_29 , F_25 ) ;
V_31 -> V_13 = V_13 ;
V_31 -> V_35 = V_35 ;
V_31 -> V_8 = V_8 ;
V_31 -> V_36 = V_36 ;
F_38 ( V_13 -> V_39 , & V_31 -> V_29 ) ;
}
void F_39 ( struct V_13 * V_13 )
{
struct V_14 * V_15 ;
struct V_14 * V_16 ;
F_28 ( & V_13 -> V_32 ) ;
F_10 (tunnel, n, &tb->tunnel_list, list) {
F_12 ( V_15 ) ;
F_13 ( V_15 ) ;
}
if ( V_13 -> V_27 )
F_15 ( V_13 -> V_27 ) ;
V_13 -> V_27 = NULL ;
if ( V_13 -> V_40 ) {
F_40 ( V_13 -> V_40 ) ;
F_41 ( V_13 -> V_40 ) ;
}
V_13 -> V_40 = NULL ;
V_13 -> V_33 = false ;
F_33 ( & V_13 -> V_32 ) ;
if ( V_13 -> V_39 ) {
F_42 ( V_13 -> V_39 ) ;
F_43 ( V_13 -> V_39 ) ;
V_13 -> V_39 = NULL ;
}
F_44 ( & V_13 -> V_32 ) ;
F_34 ( V_13 ) ;
}
struct V_13 * F_45 ( struct V_41 * V_42 )
{
struct V_13 * V_13 ;
F_46 ( sizeof( struct V_43 ) != 5 * 4 ) ;
F_46 ( sizeof( struct V_44 ) != 8 * 4 ) ;
F_46 ( sizeof( struct V_45 ) != 2 * 4 ) ;
V_13 = F_47 ( sizeof( * V_13 ) , V_38 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_42 = V_42 ;
F_48 ( & V_13 -> V_32 ) ;
F_28 ( & V_13 -> V_32 ) ;
F_49 ( & V_13 -> V_46 ) ;
V_13 -> V_39 = F_50 ( L_17 , 0 ) ;
if ( ! V_13 -> V_39 )
goto V_47;
V_13 -> V_40 = F_51 ( V_13 -> V_42 , F_35 , V_13 ) ;
if ( ! V_13 -> V_40 )
goto V_47;
F_52 ( V_13 -> V_40 ) ;
V_13 -> V_27 = F_6 ( V_13 , 0 ) ;
if ( ! V_13 -> V_27 )
goto V_47;
F_1 ( V_13 -> V_27 ) ;
F_20 ( V_13 ) ;
V_13 -> V_33 = true ;
F_33 ( & V_13 -> V_32 ) ;
return V_13 ;
V_47:
F_33 ( & V_13 -> V_32 ) ;
F_39 ( V_13 ) ;
return NULL ;
}
void F_53 ( struct V_13 * V_13 )
{
F_54 ( V_13 , L_18 ) ;
F_28 ( & V_13 -> V_32 ) ;
F_55 ( V_13 -> V_27 ) ;
F_40 ( V_13 -> V_40 ) ;
V_13 -> V_33 = false ;
F_33 ( & V_13 -> V_32 ) ;
F_54 ( V_13 , L_19 ) ;
}
void F_56 ( struct V_13 * V_13 )
{
struct V_14 * V_15 , * V_16 ;
F_54 ( V_13 , L_20 ) ;
F_28 ( & V_13 -> V_32 ) ;
F_52 ( V_13 -> V_40 ) ;
F_57 ( V_13 , 0 ) ;
F_58 ( V_13 -> V_27 ) ;
F_9 ( V_13 ) ;
F_14 ( V_13 -> V_27 ) ;
F_10 (tunnel, n, &tb->tunnel_list, list)
F_59 ( V_15 ) ;
if ( ! F_60 ( & V_13 -> V_46 ) ) {
F_54 ( V_13 , L_21 ) ;
F_61 ( 100 ) ;
}
V_13 -> V_33 = true ;
F_33 ( & V_13 -> V_32 ) ;
F_54 ( V_13 , L_22 ) ;
}
