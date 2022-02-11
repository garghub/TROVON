static struct V_1
* F_1 ( struct V_2 * V_3 ,
struct V_4
* V_5 ,
T_1 V_6 )
{
T_1 V_7 = ( V_6 & 0xffff ) - V_5 -> V_8 ;
struct V_1 * V_9 ;
if ( V_7 >= V_5 -> V_10 )
return NULL ;
V_9 = & V_5 -> V_11 [ V_7 ] ;
if ( F_2 ( & V_9 -> V_12 ) )
return NULL ;
return V_9 ;
}
static struct V_13 * F_3 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 , T_2 V_14 )
{
struct V_1 * V_9 = NULL ;
struct V_13 * V_15 = NULL ;
T_2 V_16 = 1 ;
V_9 = F_1 ( V_3 , V_5 , V_6 ) ;
if ( ! V_9 ) {
F_4 ( V_3 ,
L_1 , V_6 ) ;
return NULL ;
}
F_5 (p_isle, &p_archipelago->isles_list, list_entry) {
if ( V_16 == V_14 )
return V_15 ;
V_16 ++ ;
}
return NULL ;
}
void F_6 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_5 -> V_21 ;
if ( V_20 -> V_22 == V_20 -> V_23 )
V_20 -> V_22 = 0 ;
V_20 -> V_24 [ V_20 -> V_22 ] = * V_18 ;
V_20 -> V_22 ++ ;
}
struct V_4 * F_7 ( struct V_2 * V_3 )
{
T_3 V_10 = 0 , V_8 ;
struct V_4 * V_5 ;
T_3 V_25 = 0 ;
T_1 V_26 ;
if ( V_3 -> V_27 . V_28 != V_29 ) {
F_4 ( V_3 ,
L_2 ) ;
return NULL ;
}
V_10 = V_3 -> V_30 . V_31 . V_32 ;
V_25 = V_33 + V_10 ;
V_8 = ( T_3 ) F_8 ( V_3 , V_34 ) ;
if ( ! V_10 ) {
F_4 ( V_3 ,
L_3 ) ;
return NULL ;
}
V_5 = F_9 ( sizeof( * V_5 ) , V_35 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_8 = V_8 ;
V_5 -> V_10 = V_10 ;
F_10 ( & V_5 -> V_36 ) ;
F_10 ( & V_5 -> V_37 ) ;
F_10 ( & V_5 -> V_38 ) ;
V_5 -> V_39 = F_11 ( V_25 ,
sizeof( struct V_13 ) ,
V_35 ) ;
if ( ! V_5 -> V_39 )
goto V_40;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
F_10 ( & V_5 -> V_39 [ V_26 ] . V_41 ) ;
F_12 ( & V_5 -> V_39 [ V_26 ] . V_42 ,
& V_5 -> V_38 ) ;
}
V_5 -> V_11 =
F_11 ( V_10 ,
sizeof( struct V_1 ) ,
V_35 ) ;
if ( ! V_5 -> V_11 )
goto V_43;
for ( V_26 = 0 ; V_26 < V_10 ; V_26 ++ )
F_10 ( & V_5 -> V_11 [ V_26 ] . V_12 ) ;
V_5 -> V_21 . V_24 =
F_11 ( V_44 ,
sizeof( struct V_17 ) ,
V_35 ) ;
if ( ! V_5 -> V_21 . V_24 )
goto V_45;
V_5 -> V_21 . V_23 = V_44 ;
return V_5 ;
V_45:
F_13 ( V_5 -> V_11 ) ;
V_43:
F_13 ( V_5 -> V_39 ) ;
V_40:
F_13 ( V_5 ) ;
return NULL ;
}
void F_14 ( struct V_2 * V_3 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_1 * V_9 ;
struct V_46 * V_47 ;
struct V_13 * V_15 ;
V_9 = F_1 ( V_3 , V_5 , V_6 ) ;
if ( ! V_9 )
return;
while ( ! F_2 ( & V_9 -> V_12 ) ) {
V_15 = F_15 ( & V_9 -> V_12 ,
struct V_13 , V_42 ) ;
F_16 ( & V_15 -> V_42 ) ;
while ( ! F_2 ( & V_15 -> V_41 ) ) {
V_47 = F_15 ( & V_15 -> V_41 ,
struct V_46 ,
V_42 ) ;
if ( ! V_47 )
break;
F_16 ( & V_47 -> V_42 ) ;
F_12 ( & V_47 -> V_42 ,
& V_5 -> V_36 ) ;
}
F_12 ( & V_15 -> V_42 ,
& V_5 -> V_38 ) ;
}
}
void F_17 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_9 ;
struct V_46 * V_47 ;
struct V_13 * V_15 ;
T_1 V_26 ;
for ( V_26 = 0 ; V_26 < V_5 -> V_10 ; V_26 ++ ) {
V_9 = & ( V_5 -> V_11 [ V_26 ] ) ;
while ( ! F_2 ( & V_9 -> V_12 ) ) {
V_15 = F_15 ( & V_9 -> V_12 ,
struct V_13 ,
V_42 ) ;
F_16 ( & V_15 -> V_42 ) ;
while ( ! F_2 ( & V_15 -> V_41 ) ) {
V_47 =
F_15 ( & V_15 -> V_41 ,
struct V_46 ,
V_42 ) ;
if ( ! V_47 )
break;
F_16 ( & V_47 -> V_42 ) ;
F_12 ( & V_47 -> V_42 ,
& V_5 -> V_36 ) ;
}
F_12 ( & V_15 -> V_42 ,
& V_5 -> V_38 ) ;
}
}
if ( ! F_2 ( & V_5 -> V_37 ) )
F_18 ( & V_5 -> V_37 ,
& V_5 -> V_36 ) ;
}
void F_19 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
F_17 ( V_3 , V_5 ) ;
memset ( V_5 -> V_21 . V_24 , 0 ,
V_5 -> V_21 . V_23 *
sizeof( struct V_17 ) ) ;
V_5 -> V_21 . V_22 = 0 ;
}
void F_20 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_46 * V_47 ;
F_17 ( V_3 , V_5 ) ;
while ( ! F_2 ( & V_5 -> V_36 ) ) {
V_47 = F_15 ( & V_5 -> V_36 ,
struct V_46 , V_42 ) ;
if ( ! V_47 )
break;
F_16 ( & V_47 -> V_42 ) ;
F_21 ( & V_3 -> V_48 -> V_49 -> V_50 ,
V_47 -> V_51 ,
V_47 -> V_52 ,
V_47 -> V_53 ) ;
F_13 ( V_47 ) ;
}
F_13 ( V_5 -> V_39 ) ;
F_13 ( V_5 -> V_11 ) ;
F_13 ( V_5 -> V_21 . V_24 ) ;
F_13 ( V_5 ) ;
}
void F_22 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_46 * V_47 )
{
F_12 ( & V_47 -> V_42 , & V_5 -> V_36 ) ;
}
struct V_46 * F_23 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_46 * V_47 = NULL ;
if ( ! F_2 ( & V_5 -> V_36 ) ) {
V_47 = F_15 ( & V_5 -> V_36 ,
struct V_46 , V_42 ) ;
F_16 ( & V_47 -> V_42 ) ;
}
return V_47 ;
}
void F_24 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_46 * V_47 , T_2 V_54 )
{
if ( V_54 )
F_12 ( & V_47 -> V_42 ,
& V_5 -> V_37 ) ;
else
F_25 ( & V_47 -> V_42 ,
& V_5 -> V_37 ) ;
}
struct V_46 * F_26 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_46 * V_47 = NULL ;
if ( ! F_2 ( & V_5 -> V_37 ) ) {
V_47 = F_15 ( & V_5 -> V_37 ,
struct V_46 , V_42 ) ;
F_16 ( & V_47 -> V_42 ) ;
}
return V_47 ;
}
void F_27 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 , T_2 V_55 , T_2 V_56 )
{
struct V_1 * V_9 = NULL ;
struct V_13 * V_15 = NULL ;
T_2 V_57 ;
V_9 = F_1 ( V_3 , V_5 , V_6 ) ;
for ( V_57 = 0 ; V_57 < V_56 ; V_57 ++ ) {
V_15 = F_3 ( V_3 , V_5 , V_6 , V_55 ) ;
if ( ! V_15 ) {
F_4 ( V_3 ,
L_4 ,
V_55 , V_6 ) ;
return;
}
if ( F_2 ( & V_15 -> V_41 ) )
F_4 ( V_3 ,
L_5 , V_55 , V_6 ) ;
else
F_18 ( & V_15 -> V_41 ,
& V_5 -> V_36 ) ;
F_16 ( & V_15 -> V_42 ) ;
V_5 -> V_58 -- ;
F_25 ( & V_15 -> V_42 , & V_5 -> V_38 ) ;
}
}
void F_28 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 , T_2 V_59 ,
struct V_46 * V_47 )
{
struct V_1 * V_9 = NULL ;
struct V_13 * V_60 = NULL ;
struct V_13 * V_15 = NULL ;
if ( V_59 > 1 ) {
V_60 = F_3 ( V_3 ,
V_5 , V_6 , V_59 - 1 ) ;
if ( ! V_60 ) {
F_4 ( V_3 ,
L_4 ,
V_59 - 1 , V_6 ) ;
return;
}
}
V_9 = F_1 ( V_3 , V_5 , V_6 ) ;
if ( ! V_9 && ( V_59 != 1 ) ) {
F_4 ( V_3 ,
L_1 , V_6 ) ;
return;
}
if ( ! F_2 ( & V_5 -> V_38 ) ) {
V_15 = F_15 ( & V_5 -> V_38 ,
struct V_13 , V_42 ) ;
F_16 ( & V_15 -> V_42 ) ;
if ( ! F_2 ( & V_15 -> V_41 ) ) {
F_4 ( V_3 , L_6 ) ;
F_10 ( & V_15 -> V_41 ) ;
}
} else {
F_4 ( V_3 , L_7 ) ;
return;
}
if ( ! V_9 ) {
T_1 V_7 = ( V_6 & 0xffff ) - V_5 -> V_8 ;
V_9 = & V_5 -> V_11 [ V_7 ] ;
}
F_25 ( & V_47 -> V_42 , & V_15 -> V_41 ) ;
V_5 -> V_58 ++ ;
V_5 -> V_61 ++ ;
if ( V_5 -> V_58 > V_5 -> V_62 )
V_5 -> V_62 = V_5 -> V_58 ;
if ( ! V_60 )
F_25 ( & V_15 -> V_42 , & V_9 -> V_12 ) ;
else
F_25 ( & V_15 -> V_42 , & V_60 -> V_42 ) ;
}
void F_29 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 ,
T_2 V_59 ,
struct V_46 * V_47 , T_2 V_63 )
{
struct V_13 * V_15 = NULL ;
V_15 = F_3 ( V_3 , V_5 , V_6 , V_59 ) ;
if ( ! V_15 ) {
F_4 ( V_3 ,
L_4 , V_59 , V_6 ) ;
return;
}
if ( V_63 == V_64 )
F_25 ( & V_47 -> V_42 , & V_15 -> V_41 ) ;
else
F_12 ( & V_47 -> V_42 , & V_15 -> V_41 ) ;
}
void F_30 ( struct V_2 * V_3 ,
struct V_4 * V_5 , T_1 V_6 , T_2 V_65 )
{
struct V_1 * V_9 = NULL ;
struct V_13 * V_66 = NULL ;
struct V_13 * V_67 = NULL ;
V_66 = F_3 ( V_3 , V_5 , V_6 ,
V_65 + 1 ) ;
if ( ! V_66 ) {
F_4 ( V_3 ,
L_8 ,
V_65 + 1 , V_6 ) ;
return;
}
V_9 = F_1 ( V_3 , V_5 , V_6 ) ;
F_16 ( & V_66 -> V_42 ) ;
V_5 -> V_58 -- ;
if ( V_65 ) {
V_67 = F_3 ( V_3 , V_5 , V_6 ,
V_65 ) ;
if ( ! V_67 ) {
F_4 ( V_3 ,
L_9 ,
V_65 , V_6 ) ;
return;
}
F_18 ( & V_66 -> V_41 ,
& V_67 -> V_41 ) ;
} else {
F_18 ( & V_66 -> V_41 ,
& V_5 -> V_37 ) ;
}
F_12 ( & V_66 -> V_42 , & V_5 -> V_38 ) ;
}
