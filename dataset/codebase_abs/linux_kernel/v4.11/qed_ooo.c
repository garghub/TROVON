static struct V_1
* F_1 ( struct V_2 * V_3 ,
struct V_4
* V_5 ,
T_1 V_6 )
{
struct V_1 * V_7 = NULL ;
F_2 (p_archipelago,
&p_ooo_info->archipelagos_list, list_entry) {
if ( V_7 -> V_6 == V_6 )
return V_7 ;
}
return NULL ;
}
static struct V_8 * F_3 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 , T_2 V_9 )
{
struct V_1 * V_7 = NULL ;
struct V_8 * V_10 = NULL ;
T_2 V_11 = 1 ;
V_7 = F_1 ( V_3 , V_5 , V_6 ) ;
if ( ! V_7 ) {
F_4 ( V_3 ,
L_1 , V_6 ) ;
return NULL ;
}
F_2 (p_isle, &p_archipelago->isles_list, list_entry) {
if ( V_11 == V_9 )
return V_10 ;
V_11 ++ ;
}
return NULL ;
}
void F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_5 -> V_16 ;
if ( V_15 -> V_17 == V_15 -> V_18 )
V_15 -> V_17 = 0 ;
V_15 -> V_19 [ V_15 -> V_17 ] = * V_13 ;
V_15 -> V_17 ++ ;
}
struct V_4 * F_6 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
T_3 V_20 = 0 ;
T_3 V_21 = 0 ;
T_1 V_22 ;
if ( V_3 -> V_23 . V_24 != V_25 ) {
F_4 ( V_3 ,
L_2 ) ;
return NULL ;
}
V_20 = V_3 -> V_26 . V_27 . V_28 ;
V_21 = V_29 + V_20 ;
if ( ! V_20 ) {
F_4 ( V_3 ,
L_3 ) ;
return NULL ;
}
V_5 = F_7 ( sizeof( * V_5 ) , V_30 ) ;
if ( ! V_5 )
return NULL ;
F_8 ( & V_5 -> V_31 ) ;
F_8 ( & V_5 -> V_32 ) ;
F_8 ( & V_5 -> V_33 ) ;
F_8 ( & V_5 -> V_34 ) ;
F_8 ( & V_5 -> V_35 ) ;
V_5 -> V_36 = F_9 ( V_21 ,
sizeof( struct V_8 ) ,
V_30 ) ;
if ( ! V_5 -> V_36 )
goto V_37;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
F_8 ( & V_5 -> V_36 [ V_22 ] . V_38 ) ;
F_10 ( & V_5 -> V_36 [ V_22 ] . V_39 ,
& V_5 -> V_33 ) ;
}
V_5 -> V_40 =
F_9 ( V_20 ,
sizeof( struct V_1 ) ,
V_30 ) ;
if ( ! V_5 -> V_40 )
goto V_41;
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ ) {
F_8 ( & V_5 -> V_40 [ V_22 ] . V_42 ) ;
F_10 ( & V_5 -> V_40 [ V_22 ] . V_39 ,
& V_5 -> V_34 ) ;
}
V_5 -> V_16 . V_19 =
F_9 ( V_43 ,
sizeof( struct V_12 ) ,
V_30 ) ;
if ( ! V_5 -> V_16 . V_19 )
goto V_44;
V_5 -> V_16 . V_18 = V_43 ;
return V_5 ;
V_44:
F_11 ( V_5 -> V_40 ) ;
V_41:
F_11 ( V_5 -> V_36 ) ;
V_37:
F_11 ( V_5 ) ;
return NULL ;
}
void F_12 ( struct V_2 * V_3 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_1 * V_7 ;
struct V_45 * V_46 ;
struct V_8 * V_10 ;
bool V_47 = false ;
if ( F_13 ( & V_5 -> V_35 ) )
return;
F_2 (p_archipelago,
&p_ooo_info->archipelagos_list, list_entry) {
if ( V_7 -> V_6 == V_6 ) {
F_14 ( & V_7 -> V_39 ) ;
V_47 = true ;
break;
}
}
if ( ! V_47 )
return;
while ( ! F_13 ( & V_7 -> V_42 ) ) {
V_10 = F_15 ( & V_7 -> V_42 ,
struct V_8 , V_39 ) ;
F_14 ( & V_10 -> V_39 ) ;
while ( ! F_13 ( & V_10 -> V_38 ) ) {
V_46 = F_15 ( & V_10 -> V_38 ,
struct V_45 ,
V_39 ) ;
if ( ! V_46 )
break;
F_14 ( & V_46 -> V_39 ) ;
F_10 ( & V_46 -> V_39 ,
& V_5 -> V_31 ) ;
}
F_10 ( & V_10 -> V_39 ,
& V_5 -> V_33 ) ;
}
F_10 ( & V_7 -> V_39 ,
& V_5 -> V_34 ) ;
}
void F_16 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_48 ;
struct V_45 * V_46 ;
struct V_8 * V_10 ;
while ( ! F_13 ( & V_5 -> V_35 ) ) {
V_48 = F_15 ( & V_5 -> V_35 ,
struct V_1 ,
V_39 ) ;
F_14 ( & V_48 -> V_39 ) ;
while ( ! F_13 ( & V_48 -> V_42 ) ) {
V_10 = F_15 ( & V_48 -> V_42 ,
struct V_8 ,
V_39 ) ;
F_14 ( & V_10 -> V_39 ) ;
while ( ! F_13 ( & V_10 -> V_38 ) ) {
V_46 =
F_15 ( & V_10 -> V_38 ,
struct V_45 ,
V_39 ) ;
if ( ! V_46 )
break;
F_14 ( & V_46 -> V_39 ) ;
F_10 ( & V_46 -> V_39 ,
& V_5 -> V_31 ) ;
}
F_10 ( & V_10 -> V_39 ,
& V_5 -> V_33 ) ;
}
F_10 ( & V_48 -> V_39 ,
& V_5 -> V_34 ) ;
}
if ( ! F_13 ( & V_5 -> V_32 ) )
F_17 ( & V_5 -> V_32 ,
& V_5 -> V_31 ) ;
}
void F_18 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
F_16 ( V_3 , V_5 ) ;
memset ( V_5 -> V_16 . V_19 , 0 ,
V_5 -> V_16 . V_18 *
sizeof( struct V_12 ) ) ;
V_5 -> V_16 . V_17 = 0 ;
}
void F_19 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_45 * V_46 ;
F_16 ( V_3 , V_5 ) ;
while ( ! F_13 ( & V_5 -> V_31 ) ) {
V_46 = F_15 ( & V_5 -> V_31 ,
struct V_45 , V_39 ) ;
if ( ! V_46 )
break;
F_14 ( & V_46 -> V_39 ) ;
F_20 ( & V_3 -> V_49 -> V_50 -> V_51 ,
V_46 -> V_52 ,
V_46 -> V_53 ,
V_46 -> V_54 ) ;
F_11 ( V_46 ) ;
}
F_11 ( V_5 -> V_36 ) ;
F_11 ( V_5 -> V_40 ) ;
F_11 ( V_5 -> V_16 . V_19 ) ;
F_11 ( V_5 ) ;
}
void F_21 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_45 * V_46 )
{
F_10 ( & V_46 -> V_39 , & V_5 -> V_31 ) ;
}
struct V_45 * F_22 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_45 * V_46 = NULL ;
if ( ! F_13 ( & V_5 -> V_31 ) ) {
V_46 = F_15 ( & V_5 -> V_31 ,
struct V_45 , V_39 ) ;
F_14 ( & V_46 -> V_39 ) ;
}
return V_46 ;
}
void F_23 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_45 * V_46 , T_2 V_55 )
{
if ( V_55 )
F_10 ( & V_46 -> V_39 ,
& V_5 -> V_32 ) ;
else
F_24 ( & V_46 -> V_39 ,
& V_5 -> V_32 ) ;
}
struct V_45 * F_25 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_45 * V_46 = NULL ;
if ( ! F_13 ( & V_5 -> V_32 ) ) {
V_46 = F_15 ( & V_5 -> V_32 ,
struct V_45 , V_39 ) ;
F_14 ( & V_46 -> V_39 ) ;
}
return V_46 ;
}
void F_26 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 , T_2 V_56 , T_2 V_57 )
{
struct V_1 * V_7 = NULL ;
struct V_8 * V_10 = NULL ;
T_2 V_58 ;
V_7 = F_1 ( V_3 , V_5 , V_6 ) ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
V_10 = F_3 ( V_3 , V_5 , V_6 , V_56 ) ;
if ( ! V_10 ) {
F_4 ( V_3 ,
L_4 ,
V_56 , V_6 ) ;
return;
}
if ( F_13 ( & V_10 -> V_38 ) )
F_4 ( V_3 ,
L_5 , V_56 , V_6 ) ;
else
F_17 ( & V_10 -> V_38 ,
& V_5 -> V_31 ) ;
F_14 ( & V_10 -> V_39 ) ;
V_5 -> V_59 -- ;
F_24 ( & V_10 -> V_39 , & V_5 -> V_33 ) ;
}
if ( F_13 ( & V_7 -> V_42 ) ) {
F_14 ( & V_7 -> V_39 ) ;
F_24 ( & V_7 -> V_39 ,
& V_5 -> V_34 ) ;
}
}
void F_27 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 , T_2 V_60 ,
struct V_45 * V_46 )
{
struct V_1 * V_7 = NULL ;
struct V_8 * V_61 = NULL ;
struct V_8 * V_10 = NULL ;
if ( V_60 > 1 ) {
V_61 = F_3 ( V_3 ,
V_5 , V_6 , V_60 - 1 ) ;
if ( ! V_61 ) {
F_4 ( V_3 ,
L_4 ,
V_60 - 1 , V_6 ) ;
return;
}
}
V_7 = F_1 ( V_3 , V_5 , V_6 ) ;
if ( ! V_7 && ( V_60 != 1 ) ) {
F_4 ( V_3 ,
L_1 , V_6 ) ;
return;
}
if ( ! F_13 ( & V_5 -> V_33 ) ) {
V_10 = F_15 ( & V_5 -> V_33 ,
struct V_8 , V_39 ) ;
F_14 ( & V_10 -> V_39 ) ;
if ( ! F_13 ( & V_10 -> V_38 ) ) {
F_4 ( V_3 , L_6 ) ;
F_8 ( & V_10 -> V_38 ) ;
}
} else {
F_4 ( V_3 , L_7 ) ;
return;
}
if ( ! V_7 &&
! F_13 ( & V_5 -> V_34 ) ) {
V_7 =
F_15 ( & V_5 -> V_34 ,
struct V_1 , V_39 ) ;
F_14 ( & V_7 -> V_39 ) ;
if ( ! F_13 ( & V_7 -> V_42 ) ) {
F_4 ( V_3 ,
L_8 ) ;
F_8 ( & V_7 -> V_42 ) ;
}
V_7 -> V_6 = V_6 ;
F_24 ( & V_7 -> V_39 ,
& V_5 -> V_35 ) ;
} else if ( ! V_7 ) {
F_4 ( V_3 , L_9 ) ;
F_24 ( & V_10 -> V_39 ,
& V_5 -> V_33 ) ;
F_24 ( & V_46 -> V_39 ,
& V_5 -> V_31 ) ;
return;
}
F_24 ( & V_46 -> V_39 , & V_10 -> V_38 ) ;
V_5 -> V_59 ++ ;
V_5 -> V_62 ++ ;
if ( V_5 -> V_59 > V_5 -> V_63 )
V_5 -> V_63 = V_5 -> V_59 ;
if ( ! V_61 )
F_24 ( & V_10 -> V_39 , & V_7 -> V_42 ) ;
else
F_24 ( & V_10 -> V_39 , & V_61 -> V_39 ) ;
}
void F_28 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 ,
T_2 V_60 ,
struct V_45 * V_46 , T_2 V_64 )
{
struct V_8 * V_10 = NULL ;
V_10 = F_3 ( V_3 , V_5 , V_6 , V_60 ) ;
if ( ! V_10 ) {
F_4 ( V_3 ,
L_4 , V_60 , V_6 ) ;
return;
}
if ( V_64 == V_65 )
F_24 ( & V_46 -> V_39 , & V_10 -> V_38 ) ;
else
F_10 ( & V_46 -> V_39 , & V_10 -> V_38 ) ;
}
void F_29 ( struct V_2 * V_3 ,
struct V_4 * V_5 , T_1 V_6 , T_2 V_66 )
{
struct V_1 * V_7 = NULL ;
struct V_8 * V_67 = NULL ;
struct V_8 * V_68 = NULL ;
V_67 = F_3 ( V_3 , V_5 , V_6 ,
V_66 + 1 ) ;
if ( ! V_67 ) {
F_4 ( V_3 ,
L_10 ,
V_66 + 1 , V_6 ) ;
return;
}
V_7 = F_1 ( V_3 , V_5 , V_6 ) ;
F_14 ( & V_67 -> V_39 ) ;
V_5 -> V_59 -- ;
if ( V_66 ) {
V_68 = F_3 ( V_3 , V_5 , V_6 ,
V_66 ) ;
if ( ! V_68 ) {
F_4 ( V_3 ,
L_11 ,
V_66 , V_6 ) ;
return;
}
F_17 ( & V_67 -> V_38 ,
& V_68 -> V_38 ) ;
} else {
F_17 ( & V_67 -> V_38 ,
& V_5 -> V_32 ) ;
if ( F_13 ( & V_7 -> V_42 ) ) {
F_14 ( & V_7 -> V_39 ) ;
F_24 ( & V_7 -> V_39 ,
& V_5 -> V_34 ) ;
}
}
F_10 ( & V_67 -> V_39 , & V_5 -> V_33 ) ;
}
