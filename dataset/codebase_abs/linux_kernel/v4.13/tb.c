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
V_2 = F_6 ( V_8 -> V_2 -> V_13 , & V_8 -> V_2 -> V_14 ,
F_7 ( V_8 ) ) ;
if ( ! V_2 )
return;
if ( F_8 ( V_2 ) ) {
F_9 ( V_2 ) ;
return;
}
V_2 -> V_15 = true ;
if ( F_10 ( V_2 ) ) {
F_9 ( V_2 ) ;
return;
}
V_8 -> V_12 = F_11 ( V_2 ) ;
F_11 ( V_2 ) -> V_12 = V_8 ;
F_1 ( V_2 ) ;
}
static void F_12 ( struct V_13 * V_13 )
{
struct V_16 * V_17 = F_13 ( V_13 ) ;
struct V_18 * V_19 ;
struct V_18 * V_20 ;
F_14 (tunnel, n, &tcm->tunnel_list, list) {
if ( F_15 ( V_19 ) ) {
F_16 ( V_19 ) ;
F_17 ( & V_19 -> V_21 ) ;
F_18 ( V_19 ) ;
}
}
}
static void F_19 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 1 ; V_3 <= V_2 -> V_4 . V_5 ; V_3 ++ ) {
struct V_7 * V_8 = & V_2 -> V_6 [ V_3 ] ;
if ( F_3 ( V_8 ) )
continue;
if ( ! V_8 -> V_12 )
continue;
if ( V_8 -> V_12 -> V_2 -> V_22 ) {
F_20 ( V_8 -> V_12 -> V_2 ) ;
V_8 -> V_12 = NULL ;
} else {
F_19 ( V_8 -> V_12 -> V_2 ) ;
}
}
}
static struct V_7 * F_21 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 1 ; V_3 <= V_2 -> V_4 . V_5 ; V_3 ++ )
if ( V_2 -> V_6 [ V_3 ] . V_4 . type == V_23 )
return & V_2 -> V_6 [ V_3 ] ;
return NULL ;
}
static struct V_7 * F_22 ( struct V_1 * V_2 )
{
int V_3 ;
int V_24 ;
int V_25 ;
int V_26 ;
for ( V_3 = 1 ; V_3 <= V_2 -> V_4 . V_5 ; V_3 ++ ) {
if ( F_3 ( & V_2 -> V_6 [ V_3 ] ) )
continue;
if ( V_2 -> V_6 [ V_3 ] . V_4 . type != V_27 )
continue;
V_24 = F_23 ( & V_2 -> V_6 [ V_3 ] , V_28 ) ;
if ( V_24 < 0 )
continue;
V_25 = F_24 ( & V_2 -> V_6 [ V_3 ] , & V_26 , V_29 , V_24 , 1 ) ;
if ( V_25 < 0 )
continue;
if ( V_26 & 0x80000000 )
continue;
return & V_2 -> V_6 [ V_3 ] ;
}
return NULL ;
}
static void F_25 ( struct V_13 * V_13 )
{
int V_3 ;
int V_24 ;
T_1 V_26 ;
struct V_1 * V_2 ;
struct V_7 * V_30 ;
struct V_7 * V_31 ;
struct V_18 * V_19 ;
struct V_16 * V_17 = F_13 ( V_13 ) ;
for ( V_3 = 1 ; V_3 <= V_13 -> V_32 -> V_4 . V_5 ; V_3 ++ ) {
if ( F_3 ( & V_13 -> V_32 -> V_6 [ V_3 ] ) )
continue;
if ( V_13 -> V_32 -> V_6 [ V_3 ] . V_4 . type != V_9 )
continue;
if ( ! V_13 -> V_32 -> V_6 [ V_3 ] . V_12 )
continue;
V_2 = V_13 -> V_32 -> V_6 [ V_3 ] . V_12 -> V_2 ;
V_30 = F_21 ( V_2 ) ;
if ( ! V_30 ) {
F_26 ( V_2 , L_2 ) ;
continue;
}
V_24 = F_23 ( V_30 , V_28 ) ;
if ( V_24 < 0 )
continue;
if ( F_24 ( V_30 , & V_26 , V_29 , V_24 , 1 ) )
continue;
if ( V_26 & 0x80000000 ) {
F_27 ( V_30 ,
L_3 ) ;
continue;
}
V_31 = F_22 ( V_13 -> V_32 ) ;
if ( ! V_31 ) {
F_27 ( V_30 ,
L_4 ) ;
continue;
}
V_19 = F_28 ( V_13 , V_30 , V_31 ) ;
if ( ! V_19 ) {
F_27 ( V_30 ,
L_5 ) ;
continue;
}
if ( F_29 ( V_19 ) ) {
F_27 ( V_30 ,
L_6 ) ;
F_18 ( V_19 ) ;
}
F_30 ( & V_19 -> V_21 , & V_17 -> V_33 ) ;
}
}
static void F_31 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = F_32 ( V_35 , F_33 ( * V_37 ) , V_35 ) ;
struct V_13 * V_13 = V_37 -> V_13 ;
struct V_16 * V_17 = F_13 ( V_13 ) ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
F_34 ( & V_13 -> V_38 ) ;
if ( ! V_17 -> V_39 )
goto V_40;
V_2 = F_35 ( V_13 -> V_32 , V_37 -> V_41 ) ;
if ( ! V_2 ) {
F_36 ( V_13 ,
L_7 ,
V_37 -> V_41 , V_37 -> V_8 , V_37 -> V_42 ) ;
goto V_40;
}
if ( V_37 -> V_8 > V_2 -> V_4 . V_5 ) {
F_36 ( V_13 ,
L_8 ,
V_37 -> V_41 , V_37 -> V_8 , V_37 -> V_42 ) ;
goto V_40;
}
V_8 = & V_2 -> V_6 [ V_37 -> V_8 ] ;
if ( F_3 ( V_8 ) ) {
F_36 ( V_13 ,
L_9 ,
V_37 -> V_41 , V_37 -> V_8 , V_37 -> V_42 ) ;
goto V_40;
}
if ( V_37 -> V_42 ) {
if ( V_8 -> V_12 ) {
F_27 ( V_8 , L_10 ) ;
F_37 ( V_8 -> V_12 -> V_2 ) ;
F_12 ( V_13 ) ;
F_20 ( V_8 -> V_12 -> V_2 ) ;
V_8 -> V_12 = NULL ;
} else {
F_27 ( V_8 ,
L_11 ) ;
}
} else if ( V_8 -> V_12 ) {
F_27 ( V_8 ,
L_12 ) ;
} else {
F_27 ( V_8 , L_13 ) ;
F_2 ( V_8 ) ;
if ( ! V_8 -> V_12 ) {
F_27 ( V_8 , L_14 ) ;
} else if ( V_8 -> V_12 -> V_2 -> V_4 . V_43 > 1 ) {
F_38 ( V_8 -> V_12 -> V_2 ,
L_15 ) ;
} else {
F_26 ( V_8 -> V_12 -> V_2 ,
L_16 ) ;
F_25 ( V_13 ) ;
}
}
V_40:
F_39 ( & V_13 -> V_38 ) ;
F_40 ( V_37 ) ;
}
static void F_41 ( struct V_13 * V_13 , enum V_44 type ,
const void * V_45 , T_2 V_46 )
{
const struct V_47 * V_48 = V_45 ;
struct V_36 * V_37 ;
T_3 V_41 ;
if ( type != V_49 ) {
F_36 ( V_13 , L_17 , type ) ;
return;
}
V_41 = F_42 ( & V_48 -> V_50 ) ;
if ( F_43 ( V_13 -> V_51 , V_41 , V_48 -> V_8 ,
V_52 ) ) {
F_36 ( V_13 , L_18 , V_41 ,
V_48 -> V_8 ) ;
}
V_37 = F_44 ( sizeof( * V_37 ) , V_53 ) ;
if ( ! V_37 )
return;
F_45 ( & V_37 -> V_35 , F_31 ) ;
V_37 -> V_13 = V_13 ;
V_37 -> V_41 = V_41 ;
V_37 -> V_8 = V_48 -> V_8 ;
V_37 -> V_42 = V_48 -> V_42 ;
F_46 ( V_13 -> V_54 , & V_37 -> V_35 ) ;
}
static void F_47 ( struct V_13 * V_13 )
{
struct V_16 * V_17 = F_13 ( V_13 ) ;
struct V_18 * V_19 ;
struct V_18 * V_20 ;
F_14 (tunnel, n, &tcm->tunnel_list, list) {
F_16 ( V_19 ) ;
F_18 ( V_19 ) ;
}
F_20 ( V_13 -> V_32 ) ;
V_17 -> V_39 = false ;
}
static int F_48 ( struct V_13 * V_13 )
{
struct V_16 * V_17 = F_13 ( V_13 ) ;
int V_55 ;
V_13 -> V_32 = F_6 ( V_13 , & V_13 -> V_14 , 0 ) ;
if ( ! V_13 -> V_32 )
return - V_56 ;
V_13 -> V_32 -> V_57 = true ;
V_55 = F_8 ( V_13 -> V_32 ) ;
if ( V_55 ) {
F_9 ( V_13 -> V_32 ) ;
return V_55 ;
}
V_55 = F_10 ( V_13 -> V_32 ) ;
if ( V_55 ) {
F_9 ( V_13 -> V_32 ) ;
return V_55 ;
}
F_1 ( V_13 -> V_32 ) ;
F_25 ( V_13 ) ;
V_17 -> V_39 = true ;
return 0 ;
}
static int F_49 ( struct V_13 * V_13 )
{
struct V_16 * V_17 = F_13 ( V_13 ) ;
F_50 ( V_13 , L_19 ) ;
F_51 ( V_13 -> V_32 ) ;
V_17 -> V_39 = false ;
F_50 ( V_13 , L_20 ) ;
return 0 ;
}
static int F_52 ( struct V_13 * V_13 )
{
struct V_16 * V_17 = F_13 ( V_13 ) ;
struct V_18 * V_19 , * V_20 ;
F_50 ( V_13 , L_21 ) ;
F_53 ( V_13 , 0 ) ;
F_54 ( V_13 -> V_32 ) ;
F_12 ( V_13 ) ;
F_19 ( V_13 -> V_32 ) ;
F_14 (tunnel, n, &tcm->tunnel_list, list)
F_55 ( V_19 ) ;
if ( ! F_56 ( & V_17 -> V_33 ) ) {
F_50 ( V_13 , L_22 ) ;
F_57 ( 100 ) ;
}
V_17 -> V_39 = true ;
F_50 ( V_13 , L_23 ) ;
return 0 ;
}
struct V_13 * F_58 ( struct V_58 * V_59 )
{
struct V_16 * V_17 ;
struct V_13 * V_13 ;
if ( ! F_59 ( V_60 , L_24 ) )
return NULL ;
V_13 = F_60 ( V_59 , sizeof( * V_17 ) ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_61 = V_62 ;
V_13 -> V_63 = & V_64 ;
V_17 = F_13 ( V_13 ) ;
F_61 ( & V_17 -> V_33 ) ;
return V_13 ;
}
