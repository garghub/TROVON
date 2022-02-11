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
T_1 V_14 ;
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
T_1 V_14 ;
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
V_16 = false ;
V_13 = V_2 -> V_13 ;
for ( V_15 = 0 ; V_15 < V_24 ; V_15 ++ ) {
if ( ( V_13 [ V_14 ] . V_11 == V_29 ) &&
( memcmp ( V_13 [ V_14 ] . V_3 , V_30 , V_4 ) == 0 ) ) {
V_16 = true ;
break;
}
V_14 ++ ;
}
if ( V_16 ) {
for ( V_15 = 0 ; V_15 < V_2 -> V_31 ; V_15 ++ ) {
if ( V_2 -> V_32 [ V_15 ] == NULL )
break;
}
if ( V_15 == V_2 -> V_31 )
return - V_33 ;
V_28 = F_7 ( sizeof( * V_28 ) , V_34 ) ;
if ( ! V_28 )
return - V_33 ;
memcpy ( V_13 [ V_14 ] . V_3 , V_3 , V_4 ) ;
V_13 [ V_14 ] . V_18 = V_18 ;
V_13 [ V_14 ] . V_11 = V_11 ;
V_13 [ V_14 ] . V_25 = V_15 ;
V_28 -> V_35 = V_14 ;
V_28 -> V_36 = V_37 ;
F_8 ( & V_28 -> V_38 ) ;
V_2 -> V_32 [ V_15 ] = V_28 ;
return V_15 ;
}
return V_26 ;
}
T_1 F_9 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_27 * V_28 ;
V_28 = V_2 -> V_32 [ V_25 ] ;
return V_2 -> V_13 [ V_28 -> V_35 ] . V_18 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_25 ,
bool V_39 )
{
struct V_27 * V_28 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
bool V_46 ;
int V_15 ;
T_1 V_11 ;
unsigned long V_47 ;
F_11 ( & V_2 -> V_48 , V_47 ) ;
V_28 = V_2 -> V_32 [ V_25 ] ;
V_11 = F_12 ( V_2 , V_25 ) ;
V_46 = false ;
for ( V_15 = 0 ; V_15 < V_2 -> V_31 ; V_15 ++ ) {
if ( V_2 -> V_32 [ V_15 ] ) {
V_28 = V_2 -> V_32 [ V_15 ] ;
if ( ( V_28 -> V_36 == V_49 ) &&
( F_12 ( V_2 , V_15 ) == V_11 ) ) {
if ( V_28 -> V_39 ) {
V_46 = true ;
break;
}
}
}
}
V_28 -> V_39 = V_39 ;
if ( V_46 == V_39 ) {
F_13 ( & V_2 -> V_48 , V_47 ) ;
return;
}
V_41 = F_14 ( V_2 -> V_50 ) ;
V_43 = V_41 -> V_43 ;
V_45 = V_43 -> V_51 [ V_11 ] ;
F_15 ( V_45 , V_52 , V_39 ) ;
F_13 ( & V_2 -> V_48 , V_47 ) ;
}
void F_16 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_27 * V_28 ;
T_1 V_14 ;
struct V_53 * V_54 ;
V_28 = V_2 -> V_32 [ V_25 ] ;
if ( ! V_28 )
return;
F_10 ( V_2 , V_25 , false ) ;
V_14 = V_28 -> V_35 ;
V_2 -> V_13 [ V_14 ] . V_11 = V_29 ;
memset ( V_2 -> V_13 [ V_14 ] . V_3 , 0 , V_4 ) ;
V_2 -> V_32 [ V_25 ] = NULL ;
V_54 = F_17 ( & V_28 -> V_38 ) ;
while ( V_54 ) {
F_18 ( V_54 ) ;
V_54 = F_17 ( & V_28 -> V_38 ) ;
}
F_19 ( V_28 ) ;
}
void F_20 ( struct V_1 * V_2 , T_1 V_25 ,
struct V_53 * V_54 )
{
struct V_27 * V_28 ;
V_28 = V_2 -> V_32 [ V_25 ] ;
F_21 ( & V_28 -> V_38 , V_54 ) ;
if ( ! V_28 -> V_39 &&
( F_22 ( & V_28 -> V_38 ) > V_55 ) ) {
F_10 ( V_2 , V_25 , true ) ;
F_23 ( V_56 , L_1 , V_25 ) ;
if ( F_22 ( & V_28 -> V_38 ) < V_57 )
F_10 ( V_2 , V_25 , false ) ;
}
}
struct V_53 * F_24 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_27 * V_28 ;
struct V_53 * V_54 ;
V_28 = V_2 -> V_32 [ V_25 ] ;
if ( V_28 -> V_36 != V_49 )
return NULL ;
V_54 = F_17 ( & V_28 -> V_38 ) ;
if ( V_28 -> V_39 &&
( F_22 ( & V_28 -> V_38 ) < V_57 ) ) {
F_10 ( V_2 , V_25 , false ) ;
F_23 ( V_56 , L_2 , V_25 ) ;
}
return V_54 ;
}
void F_25 ( struct V_1 * V_2 , T_1 V_25 ,
struct V_53 * V_54 )
{
struct V_27 * V_28 ;
V_28 = V_2 -> V_32 [ V_25 ] ;
F_26 ( & V_28 -> V_38 , V_54 ) ;
}
T_2 F_27 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_27 * V_28 ;
V_28 = V_2 -> V_32 [ V_25 ] ;
if ( ! V_28 )
return 0 ;
if ( V_28 -> V_36 != V_49 )
return 0 ;
return F_22 ( & V_28 -> V_38 ) ;
}
void F_28 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_27 * V_28 ;
V_28 = V_2 -> V_32 [ V_25 ] ;
if ( ! V_28 ) {
F_29 ( L_3 , V_25 ) ;
return;
}
V_28 -> V_36 = V_49 ;
}
T_1 F_12 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_27 * V_28 ;
T_1 V_14 ;
V_28 = V_2 -> V_32 [ V_25 ] ;
V_14 = V_28 -> V_35 ;
return V_2 -> V_13 [ V_14 ] . V_11 ;
}
struct V_1 * F_30 ( struct V_58 * V_50 , T_3 V_31 )
{
struct V_1 * V_2 ;
T_2 V_15 ;
V_2 = F_7 ( sizeof( * V_2 ) , V_34 ) ;
if ( V_2 ) {
V_2 -> V_50 = V_50 ;
V_2 -> V_31 = V_31 ;
F_31 ( & V_2 -> V_48 ) ;
for ( V_15 = 0 ; V_15 < F_32 ( V_2 -> V_20 ) ; V_15 ++ )
V_2 -> V_20 [ V_15 ] = V_21 ;
for ( V_15 = 0 ; V_15 < F_32 ( V_2 -> V_13 ) ; V_15 ++ )
V_2 -> V_13 [ V_15 ] . V_11 = V_29 ;
V_2 -> V_32 = F_33 ( V_31 , sizeof( * V_2 -> V_32 ) ,
V_34 ) ;
if ( ! V_2 -> V_32 ) {
F_19 ( V_2 ) ;
V_2 = NULL ;
}
}
return V_2 ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_14 ( V_2 -> V_50 ) ;
struct V_42 * V_43 = V_41 -> V_43 ;
struct V_5 * V_6 ;
struct V_5 * remove ;
T_1 V_25 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_31 ; V_25 ++ ) {
if ( V_2 -> V_32 [ V_25 ] )
F_35 ( V_43 , V_25 ) ;
}
V_6 = V_2 -> V_7 ;
while ( V_6 ) {
remove = V_6 ;
V_6 = V_6 -> V_8 ;
F_19 ( remove ) ;
}
F_19 ( V_2 -> V_32 ) ;
F_19 ( V_2 ) ;
}
void F_36 ( struct V_1 * V_2 , int V_11 ,
enum V_59 V_20 )
{
struct V_40 * V_41 = F_14 ( V_2 -> V_50 ) ;
struct V_42 * V_43 = V_41 -> V_43 ;
T_2 V_15 ;
T_1 V_25 ;
if ( V_2 -> V_20 [ V_11 ] != V_20 ) {
for ( V_15 = 0 ; V_15 < F_32 ( V_2 -> V_13 ) ; V_15 ++ ) {
if ( V_2 -> V_13 [ V_15 ] . V_11 == V_11 ) {
V_25 = V_2 -> V_13 [ V_15 ] . V_25 ;
if ( V_2 -> V_32 [ V_25 ] -> V_36 != V_49 )
continue;
V_2 -> V_32 [ V_25 ] -> V_36 = V_60 ;
F_35 ( V_43 , V_25 ) ;
}
}
V_2 -> V_20 [ V_11 ] = V_20 ;
}
}
void F_37 ( struct V_1 * V_2 , int V_11 ,
T_1 V_61 [ V_4 ] )
{
struct V_40 * V_41 = F_14 ( V_2 -> V_50 ) ;
struct V_42 * V_43 = V_41 -> V_43 ;
struct V_12 * V_13 ;
struct V_5 * V_62 ;
struct V_5 * V_6 ;
T_2 V_15 ;
T_1 V_25 ;
bool V_17 ;
V_17 = ( V_2 -> V_20 [ V_11 ] == V_21 ) ;
V_6 = V_2 -> V_7 ;
V_62 = NULL ;
while ( V_6 ) {
if ( memcmp ( V_6 -> V_3 , V_61 , V_4 ) == 0 ) {
V_17 = false ;
break;
}
V_62 = V_6 ;
V_6 = V_6 -> V_8 ;
}
V_13 = V_2 -> V_13 ;
for ( V_15 = 0 ; V_15 < V_24 ; V_15 ++ ) {
if ( ( V_17 || ( memcmp ( V_13 [ V_15 ] . V_3 , V_61 , V_4 ) == 0 ) ) &&
( V_13 [ V_15 ] . V_11 == V_11 ) ) {
V_25 = V_2 -> V_13 [ V_15 ] . V_25 ;
if ( V_2 -> V_32 [ V_25 ] -> V_36 == V_49 ) {
V_2 -> V_32 [ V_25 ] -> V_36 = V_60 ;
F_35 ( V_43 , V_25 ) ;
}
}
}
if ( V_6 ) {
if ( V_62 )
V_62 -> V_8 = V_6 -> V_8 ;
else
V_2 -> V_7 = V_6 -> V_8 ;
F_19 ( V_6 ) ;
if ( V_2 -> V_7 == NULL )
V_2 -> V_23 = false ;
}
}
void F_38 ( struct V_1 * V_2 , int V_11 ,
T_1 V_61 [ V_4 ] )
{
struct V_5 * V_7 ;
struct V_5 * V_6 ;
V_7 = F_7 ( sizeof( * V_7 ) , V_34 ) ;
if ( V_7 == NULL )
return;
memcpy ( V_7 -> V_3 , V_61 , V_4 ) ;
V_7 -> V_8 = NULL ;
if ( V_2 -> V_7 == NULL ) {
V_2 -> V_7 = V_7 ;
} else {
V_6 = V_2 -> V_7 ;
if ( memcmp ( V_6 -> V_3 , V_61 , V_4 ) == 0 )
return;
while ( V_6 -> V_8 ) {
V_6 = V_6 -> V_8 ;
if ( memcmp ( V_6 -> V_3 , V_61 , V_4 ) == 0 )
return;
}
V_6 -> V_8 = V_7 ;
}
V_2 -> V_23 = true ;
}
