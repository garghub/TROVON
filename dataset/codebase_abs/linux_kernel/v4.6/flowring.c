static bool
F_1 ( struct V_1 * V_2 , T_1 V_3 [ V_4 ] )
{
struct V_5 * V_6 ;
V_6 = V_2 -> V_7 ;
while ( V_6 ) {
if ( memcmp ( V_6 -> V_3 , V_3 , V_4 ) == 0 )
return true ;
V_6 = V_6 -> V_8 ;
}
return false ;
}
T_2 F_2 ( struct V_1 * V_2 , T_1 V_9 [ V_4 ] ,
T_1 V_10 , T_1 V_11 )
{
struct V_12 * V_13 ;
T_3 V_14 ;
T_2 V_15 ;
bool V_16 ;
bool V_17 ;
T_1 V_18 ;
T_1 * V_3 ;
V_18 = V_19 [ V_10 ] ;
V_17 = ( V_2 -> V_20 [ V_11 ] == V_21 ) ;
V_3 = V_9 ;
if ( ( ! V_17 ) && ( F_3 ( V_9 ) ) ) {
V_3 = ( T_1 * ) V_22 ;
V_18 = 0 ;
}
if ( ( V_17 ) && ( V_2 -> V_23 ) &&
( F_1 ( V_2 , V_9 ) ) ) {
V_17 = false ;
}
V_14 = V_17 ? F_4 ( V_18 , V_11 ) :
F_5 ( V_3 , V_18 , V_11 ) ;
V_14 &= ( V_24 - 1 ) ;
V_16 = false ;
V_13 = V_2 -> V_13 ;
for ( V_15 = 0 ; V_15 < V_24 ; V_15 ++ ) {
if ( ( V_17 || ( memcmp ( V_13 [ V_14 ] . V_3 , V_3 , V_4 ) == 0 ) ) &&
( V_13 [ V_14 ] . V_18 == V_18 ) &&
( V_13 [ V_14 ] . V_11 == V_11 ) ) {
V_16 = true ;
break;
}
V_14 ++ ;
V_14 &= ( V_24 - 1 ) ;
}
if ( V_16 )
return V_13 [ V_14 ] . V_25 ;
return V_26 ;
}
T_2 F_6 ( struct V_1 * V_2 , T_1 V_9 [ V_4 ] ,
T_1 V_10 , T_1 V_11 )
{
struct V_27 * V_28 ;
struct V_12 * V_13 ;
T_3 V_14 ;
T_2 V_15 ;
bool V_16 ;
T_1 V_18 ;
bool V_17 ;
T_1 * V_3 ;
V_18 = V_19 [ V_10 ] ;
V_17 = ( V_2 -> V_20 [ V_11 ] == V_21 ) ;
V_3 = V_9 ;
if ( ( ! V_17 ) && ( F_3 ( V_9 ) ) ) {
V_3 = ( T_1 * ) V_22 ;
V_18 = 0 ;
}
if ( ( V_17 ) && ( V_2 -> V_23 ) &&
( F_1 ( V_2 , V_9 ) ) ) {
V_17 = false ;
}
V_14 = V_17 ? F_4 ( V_18 , V_11 ) :
F_5 ( V_3 , V_18 , V_11 ) ;
V_14 &= ( V_24 - 1 ) ;
V_16 = false ;
V_13 = V_2 -> V_13 ;
for ( V_15 = 0 ; V_15 < V_24 ; V_15 ++ ) {
if ( ( V_13 [ V_14 ] . V_11 == V_29 ) &&
( F_7 ( V_13 [ V_14 ] . V_3 ) ) ) {
V_16 = true ;
break;
}
V_14 ++ ;
V_14 &= ( V_24 - 1 ) ;
}
if ( V_16 ) {
for ( V_15 = 0 ; V_15 < V_2 -> V_30 ; V_15 ++ ) {
if ( V_2 -> V_31 [ V_15 ] == NULL )
break;
}
if ( V_15 == V_2 -> V_30 )
return - V_32 ;
V_28 = F_8 ( sizeof( * V_28 ) , V_33 ) ;
if ( ! V_28 )
return - V_32 ;
memcpy ( V_13 [ V_14 ] . V_3 , V_3 , V_4 ) ;
V_13 [ V_14 ] . V_18 = V_18 ;
V_13 [ V_14 ] . V_11 = V_11 ;
V_13 [ V_14 ] . V_25 = V_15 ;
V_28 -> V_34 = V_14 ;
V_28 -> V_35 = V_36 ;
F_9 ( & V_28 -> V_37 ) ;
V_2 -> V_31 [ V_15 ] = V_28 ;
return V_15 ;
}
return V_26 ;
}
T_1 F_10 ( struct V_1 * V_2 , T_3 V_25 )
{
struct V_27 * V_28 ;
V_28 = V_2 -> V_31 [ V_25 ] ;
return V_2 -> V_13 [ V_28 -> V_34 ] . V_18 ;
}
static void F_11 ( struct V_1 * V_2 , T_3 V_25 ,
bool V_38 )
{
struct V_27 * V_28 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
bool V_45 ;
int V_15 ;
T_1 V_11 ;
unsigned long V_46 ;
F_12 ( & V_2 -> V_47 , V_46 ) ;
V_28 = V_2 -> V_31 [ V_25 ] ;
if ( V_28 -> V_38 == V_38 ) {
F_13 ( & V_2 -> V_47 , V_46 ) ;
return;
}
V_11 = F_14 ( V_2 , V_25 ) ;
V_45 = false ;
for ( V_15 = 0 ; V_15 < V_2 -> V_30 ; V_15 ++ ) {
if ( ( V_2 -> V_31 [ V_15 ] ) && ( V_15 != V_25 ) ) {
V_28 = V_2 -> V_31 [ V_15 ] ;
if ( ( V_28 -> V_35 == V_48 ) &&
( F_14 ( V_2 , V_15 ) == V_11 ) ) {
if ( V_28 -> V_38 ) {
V_45 = true ;
break;
}
}
}
}
V_2 -> V_31 [ V_25 ] -> V_38 = V_38 ;
if ( V_45 ) {
F_13 ( & V_2 -> V_47 , V_46 ) ;
return;
}
V_40 = F_15 ( V_2 -> V_49 ) ;
V_42 = V_40 -> V_42 ;
V_44 = F_16 ( V_42 , V_11 ) ;
F_17 ( V_44 , V_50 , V_38 ) ;
F_13 ( & V_2 -> V_47 , V_46 ) ;
}
void F_18 ( struct V_1 * V_2 , T_3 V_25 )
{
struct V_27 * V_28 ;
T_3 V_14 ;
struct V_51 * V_52 ;
V_28 = V_2 -> V_31 [ V_25 ] ;
if ( ! V_28 )
return;
F_11 ( V_2 , V_25 , false ) ;
V_14 = V_28 -> V_34 ;
V_2 -> V_13 [ V_14 ] . V_11 = V_29 ;
F_19 ( V_2 -> V_13 [ V_14 ] . V_3 ) ;
V_2 -> V_31 [ V_25 ] = NULL ;
V_52 = F_20 ( & V_28 -> V_37 ) ;
while ( V_52 ) {
F_21 ( V_52 ) ;
V_52 = F_20 ( & V_28 -> V_37 ) ;
}
F_22 ( V_28 ) ;
}
T_2 F_23 ( struct V_1 * V_2 , T_3 V_25 ,
struct V_51 * V_52 )
{
struct V_27 * V_28 ;
V_28 = V_2 -> V_31 [ V_25 ] ;
F_24 ( & V_28 -> V_37 , V_52 ) ;
if ( ! V_28 -> V_38 &&
( F_25 ( & V_28 -> V_37 ) > V_53 ) ) {
F_11 ( V_2 , V_25 , true ) ;
F_26 ( V_54 , L_1 , V_25 ) ;
if ( F_25 ( & V_28 -> V_37 ) < V_55 )
F_11 ( V_2 , V_25 , false ) ;
}
return F_25 ( & V_28 -> V_37 ) ;
}
struct V_51 * F_27 ( struct V_1 * V_2 , T_3 V_25 )
{
struct V_27 * V_28 ;
struct V_51 * V_52 ;
V_28 = V_2 -> V_31 [ V_25 ] ;
if ( V_28 -> V_35 != V_48 )
return NULL ;
V_52 = F_20 ( & V_28 -> V_37 ) ;
if ( V_28 -> V_38 &&
( F_25 ( & V_28 -> V_37 ) < V_55 ) ) {
F_11 ( V_2 , V_25 , false ) ;
F_26 ( V_54 , L_2 , V_25 ) ;
}
return V_52 ;
}
void F_28 ( struct V_1 * V_2 , T_3 V_25 ,
struct V_51 * V_52 )
{
struct V_27 * V_28 ;
V_28 = V_2 -> V_31 [ V_25 ] ;
F_29 ( & V_28 -> V_37 , V_52 ) ;
}
T_2 F_30 ( struct V_1 * V_2 , T_3 V_25 )
{
struct V_27 * V_28 ;
V_28 = V_2 -> V_31 [ V_25 ] ;
if ( ! V_28 )
return 0 ;
if ( V_28 -> V_35 != V_48 )
return 0 ;
return F_25 ( & V_28 -> V_37 ) ;
}
void F_31 ( struct V_1 * V_2 , T_3 V_25 )
{
struct V_27 * V_28 ;
V_28 = V_2 -> V_31 [ V_25 ] ;
if ( ! V_28 ) {
F_32 ( L_3 , V_25 ) ;
return;
}
V_28 -> V_35 = V_48 ;
}
T_1 F_14 ( struct V_1 * V_2 , T_3 V_25 )
{
struct V_27 * V_28 ;
T_3 V_14 ;
V_28 = V_2 -> V_31 [ V_25 ] ;
V_14 = V_28 -> V_34 ;
return V_2 -> V_13 [ V_14 ] . V_11 ;
}
struct V_1 * F_33 ( struct V_56 * V_49 , T_3 V_30 )
{
struct V_1 * V_2 ;
T_2 V_15 ;
V_2 = F_8 ( sizeof( * V_2 ) , V_57 ) ;
if ( V_2 ) {
V_2 -> V_49 = V_49 ;
V_2 -> V_30 = V_30 ;
F_34 ( & V_2 -> V_47 ) ;
for ( V_15 = 0 ; V_15 < F_35 ( V_2 -> V_20 ) ; V_15 ++ )
V_2 -> V_20 [ V_15 ] = V_21 ;
for ( V_15 = 0 ; V_15 < F_35 ( V_2 -> V_13 ) ; V_15 ++ )
V_2 -> V_13 [ V_15 ] . V_11 = V_29 ;
V_2 -> V_31 = F_36 ( V_30 , sizeof( * V_2 -> V_31 ) ,
V_57 ) ;
if ( ! V_2 -> V_31 ) {
F_22 ( V_2 ) ;
V_2 = NULL ;
}
}
return V_2 ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 -> V_49 ) ;
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_5 * V_6 ;
struct V_5 * remove ;
T_3 V_25 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_30 ; V_25 ++ ) {
if ( V_2 -> V_31 [ V_25 ] )
F_38 ( V_42 , V_25 ) ;
}
V_6 = V_2 -> V_7 ;
while ( V_6 ) {
remove = V_6 ;
V_6 = V_6 -> V_8 ;
F_22 ( remove ) ;
}
F_22 ( V_2 -> V_31 ) ;
F_22 ( V_2 ) ;
}
void F_39 ( struct V_1 * V_2 , int V_11 ,
enum V_58 V_20 )
{
struct V_39 * V_40 = F_15 ( V_2 -> V_49 ) ;
struct V_41 * V_42 = V_40 -> V_42 ;
T_2 V_15 ;
T_3 V_25 ;
if ( V_2 -> V_20 [ V_11 ] != V_20 ) {
for ( V_15 = 0 ; V_15 < F_35 ( V_2 -> V_13 ) ; V_15 ++ ) {
if ( V_2 -> V_13 [ V_15 ] . V_11 == V_11 ) {
V_25 = V_2 -> V_13 [ V_15 ] . V_25 ;
if ( V_2 -> V_31 [ V_25 ] -> V_35 != V_48 )
continue;
V_2 -> V_31 [ V_25 ] -> V_35 = V_59 ;
F_38 ( V_42 , V_25 ) ;
}
}
V_2 -> V_20 [ V_11 ] = V_20 ;
}
}
void F_40 ( struct V_1 * V_2 , int V_11 ,
T_1 V_60 [ V_4 ] )
{
struct V_39 * V_40 = F_15 ( V_2 -> V_49 ) ;
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_12 * V_13 ;
struct V_5 * V_61 ;
struct V_5 * V_6 ;
T_2 V_15 ;
T_3 V_25 ;
bool V_17 ;
V_17 = ( V_2 -> V_20 [ V_11 ] == V_21 ) ;
V_6 = V_2 -> V_7 ;
V_61 = NULL ;
while ( V_6 ) {
if ( memcmp ( V_6 -> V_3 , V_60 , V_4 ) == 0 ) {
V_17 = false ;
break;
}
V_61 = V_6 ;
V_6 = V_6 -> V_8 ;
}
V_13 = V_2 -> V_13 ;
for ( V_15 = 0 ; V_15 < V_24 ; V_15 ++ ) {
if ( ( V_17 || ( memcmp ( V_13 [ V_15 ] . V_3 , V_60 , V_4 ) == 0 ) ) &&
( V_13 [ V_15 ] . V_11 == V_11 ) ) {
V_25 = V_2 -> V_13 [ V_15 ] . V_25 ;
if ( V_2 -> V_31 [ V_25 ] -> V_35 == V_48 ) {
V_2 -> V_31 [ V_25 ] -> V_35 = V_59 ;
F_38 ( V_42 , V_25 ) ;
}
}
}
if ( V_6 ) {
if ( V_61 )
V_61 -> V_8 = V_6 -> V_8 ;
else
V_2 -> V_7 = V_6 -> V_8 ;
F_22 ( V_6 ) ;
if ( V_2 -> V_7 == NULL )
V_2 -> V_23 = false ;
}
}
void F_41 ( struct V_1 * V_2 , int V_11 ,
T_1 V_60 [ V_4 ] )
{
struct V_5 * V_7 ;
struct V_5 * V_6 ;
V_7 = F_8 ( sizeof( * V_7 ) , V_33 ) ;
if ( V_7 == NULL )
return;
memcpy ( V_7 -> V_3 , V_60 , V_4 ) ;
V_7 -> V_8 = NULL ;
if ( V_2 -> V_7 == NULL ) {
V_2 -> V_7 = V_7 ;
} else {
V_6 = V_2 -> V_7 ;
if ( memcmp ( V_6 -> V_3 , V_60 , V_4 ) == 0 )
return;
while ( V_6 -> V_8 ) {
V_6 = V_6 -> V_8 ;
if ( memcmp ( V_6 -> V_3 , V_60 , V_4 ) == 0 )
return;
}
V_6 -> V_8 = V_7 ;
}
V_2 -> V_23 = true ;
}
