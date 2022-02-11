static bool F_1 ( T_1 * V_1 , T_2 V_2 )
{
T_3 V_3 , V_4 ;
if ( ! V_1 || V_2 < 0x49 ) {
F_2 ( L_1 ) ;
return false ;
}
if ( ! F_3 ( V_1 ) ) {
F_2 ( L_2 , V_1 [ 0 ] , V_1 [ 1 ] ) ;
return false ;
}
V_3 = V_1 [ 0x18 ] | ( V_1 [ 0x19 ] << 8 ) ;
if ( V_1 [ V_3 + 0x14 ] != 0x0 ) {
F_2 ( L_3 ) ;
return false ;
}
V_4 = V_1 [ 0x48 ] | ( V_1 [ 0x49 ] << 8 ) ;
if ( ! V_4 ) {
F_2 ( L_4 ) ;
return false ;
}
V_3 = V_4 + 4 ;
if ( V_2 < V_3 ) {
F_2 ( L_5 ) ;
return false ;
}
if ( ! memcmp ( V_1 + V_3 , L_6 , 4 ) ||
! memcmp ( V_1 + V_3 , L_7 , 4 ) ) {
F_4 ( L_8 ) ;
return true ;
}
return false ;
}
static bool F_5 ( T_1 * V_1 )
{
T_3 V_4 = V_1 [ 0x48 ] | ( V_1 [ 0x49 ] << 8 ) ;
T_1 V_5 = V_1 [ V_4 + 2 ] ;
T_1 V_6 = V_1 [ V_4 + 3 ] ;
if ( ( V_5 < 3 ) ||
( ( V_5 == 3 ) && ( V_6 < 3 ) ) )
return false ;
return true ;
}
static bool F_6 ( struct V_7 * V_8 )
{
T_1 T_4 * V_1 ;
T_5 V_9 ;
T_5 V_2 = 256 * 1024 ;
if ( ! ( V_8 -> V_10 & V_11 ) )
if ( F_7 ( V_8 ) )
return false ;
V_8 -> V_1 = NULL ;
V_9 = F_8 ( V_8 -> V_12 , 0 ) ;
V_1 = F_9 ( V_9 , V_2 ) ;
if ( ! V_1 ) {
return false ;
}
V_8 -> V_1 = F_10 ( V_2 , V_13 ) ;
if ( ! V_8 -> V_1 ) {
F_11 ( V_1 ) ;
return false ;
}
V_8 -> V_14 = V_2 ;
F_12 ( V_8 -> V_1 , V_1 , V_2 ) ;
F_11 ( V_1 ) ;
if ( ! F_1 ( V_8 -> V_1 , V_2 ) ) {
F_13 ( V_8 -> V_1 ) ;
return false ;
}
return true ;
}
bool F_14 ( struct V_7 * V_8 )
{
T_1 T_4 * V_1 ;
T_2 V_2 ;
V_8 -> V_1 = NULL ;
V_1 = F_15 ( V_8 -> V_12 , & V_2 ) ;
if ( ! V_1 ) {
return false ;
}
V_8 -> V_1 = F_16 ( V_2 , V_13 ) ;
if ( V_8 -> V_1 == NULL ) {
F_17 ( V_8 -> V_12 , V_1 ) ;
return false ;
}
V_8 -> V_14 = V_2 ;
F_12 ( V_8 -> V_1 , V_1 , V_2 ) ;
F_17 ( V_8 -> V_12 , V_1 ) ;
if ( ! F_1 ( V_8 -> V_1 , V_2 ) ) {
F_13 ( V_8 -> V_1 ) ;
return false ;
}
return true ;
}
static bool F_18 ( struct V_7 * V_8 )
{
T_6 V_15 [ V_16 + 1 ] = { 0 } ;
int V_17 ;
if ( ! V_8 -> V_18 -> V_19 )
return false ;
if ( F_19 ( V_8 , & V_15 [ 0 ] , sizeof( V_15 ) ) == false )
return false ;
V_15 [ V_16 ] = 0 ;
if ( ( ! F_3 ( V_15 ) ) ||
0 != memcmp ( ( char * ) & V_15 [ V_20 ] ,
V_21 ,
strlen ( V_21 ) ) )
return false ;
V_17 = F_20 ( V_15 ) ;
V_17 = F_21 ( V_17 , 4 ) ;
V_8 -> V_1 = F_10 ( V_17 , V_13 ) ;
if ( ! V_8 -> V_1 ) {
F_22 ( L_9 ) ;
return false ;
}
V_8 -> V_14 = V_17 ;
F_19 ( V_8 , V_8 -> V_1 , V_17 ) ;
if ( ! F_1 ( V_8 -> V_1 , V_17 ) ) {
F_13 ( V_8 -> V_1 ) ;
return false ;
}
return true ;
}
static bool F_23 ( struct V_7 * V_8 )
{
T_1 T_4 * V_1 ;
T_2 V_2 ;
V_8 -> V_1 = NULL ;
V_1 = F_24 ( V_8 -> V_12 , & V_2 ) ;
if ( ! V_1 ) {
return false ;
}
V_8 -> V_1 = F_16 ( V_2 , V_13 ) ;
if ( V_8 -> V_1 == NULL )
return false ;
F_12 ( V_8 -> V_1 , V_1 , V_2 ) ;
if ( ! F_1 ( V_8 -> V_1 , V_2 ) ) {
F_13 ( V_8 -> V_1 ) ;
return false ;
}
V_8 -> V_14 = V_2 ;
return true ;
}
static int F_25 ( T_7 V_22 , T_1 * V_1 ,
int V_23 , int V_17 )
{
T_8 V_24 ;
union V_25 V_26 [ 2 ] , * V_27 ;
struct V_28 V_29 ;
struct V_30 V_31 = { V_32 , NULL } ;
V_29 . V_33 = 2 ;
V_29 . V_34 = & V_26 [ 0 ] ;
V_26 [ 0 ] . type = V_35 ;
V_26 [ 0 ] . integer . V_36 = V_23 ;
V_26 [ 1 ] . type = V_35 ;
V_26 [ 1 ] . integer . V_36 = V_17 ;
V_24 = F_26 ( V_22 , NULL , & V_29 , & V_31 ) ;
if ( F_27 ( V_24 ) ) {
F_28 ( L_10 , F_29 ( V_24 ) ) ;
return - V_37 ;
}
V_27 = (union V_25 * ) V_31 . V_34 ;
memcpy ( V_1 + V_23 , V_27 -> V_31 . V_34 , V_27 -> V_31 . V_38 ) ;
V_17 = V_27 -> V_31 . V_38 ;
F_13 ( V_31 . V_34 ) ;
return V_17 ;
}
static bool F_30 ( struct V_7 * V_8 )
{
int V_39 ;
int V_2 = 256 * 1024 ;
int V_40 ;
struct V_41 * V_12 = NULL ;
T_7 V_42 , V_22 ;
T_8 V_24 ;
bool V_43 = false ;
if ( V_8 -> V_10 & V_11 )
return false ;
while ( ( V_12 = F_31 ( V_44 << 8 , V_12 ) ) != NULL ) {
V_42 = F_32 ( & V_12 -> V_45 ) ;
if ( ! V_42 )
continue;
V_24 = F_33 ( V_42 , L_11 , & V_22 ) ;
if ( ! F_27 ( V_24 ) ) {
V_43 = true ;
break;
}
}
if ( ! V_43 ) {
while ( ( V_12 = F_31 ( V_46 << 8 , V_12 ) ) != NULL ) {
V_42 = F_32 ( & V_12 -> V_45 ) ;
if ( ! V_42 )
continue;
V_24 = F_33 ( V_42 , L_11 , & V_22 ) ;
if ( ! F_27 ( V_24 ) ) {
V_43 = true ;
break;
}
}
}
if ( ! V_43 )
return false ;
V_8 -> V_1 = F_10 ( V_2 , V_13 ) ;
if ( ! V_8 -> V_1 ) {
F_22 ( L_12 ) ;
return false ;
}
for ( V_40 = 0 ; V_40 < V_2 / V_47 ; V_40 ++ ) {
V_39 = F_25 ( V_22 ,
V_8 -> V_1 ,
( V_40 * V_47 ) ,
V_47 ) ;
if ( V_39 < V_47 )
break;
}
if ( ! F_1 ( V_8 -> V_1 , V_2 ) ) {
F_13 ( V_8 -> V_1 ) ;
return false ;
}
V_8 -> V_14 = V_2 ;
return true ;
}
static inline bool F_30 ( struct V_7 * V_8 )
{
return false ;
}
static bool F_34 ( struct V_7 * V_8 )
{
if ( V_8 -> V_10 & V_11 )
return F_6 ( V_8 ) ;
else
return F_35 ( V_8 ) ;
}
static bool F_36 ( struct V_7 * V_8 )
{
struct V_48 * V_49 ;
T_9 V_50 ;
T_10 * V_51 ;
unsigned V_23 ;
if ( ! F_37 ( F_38 ( L_13 , 1 , & V_49 ) ) )
return false ;
V_50 = V_49 -> V_38 ;
if ( V_50 < sizeof( T_10 ) ) {
F_22 ( L_14 ) ;
return false ;
}
V_51 = ( T_10 * ) V_49 ;
V_23 = V_51 -> V_52 ;
while ( V_23 < V_50 ) {
T_11 * V_53 = ( T_11 * ) ( ( char * ) V_49 + V_23 ) ;
T_12 * V_54 = & V_53 -> V_55 ;
V_23 += sizeof( T_12 ) ;
if ( V_23 > V_50 ) {
F_22 ( L_15 ) ;
return false ;
}
V_23 += V_54 -> V_56 ;
if ( V_23 > V_50 ) {
F_22 ( L_16 ) ;
return false ;
}
if ( V_54 -> V_56 &&
V_54 -> V_57 == V_8 -> V_12 -> V_58 -> V_59 &&
V_54 -> V_60 == F_39 ( V_8 -> V_12 -> V_61 ) &&
V_54 -> V_62 == F_40 ( V_8 -> V_12 -> V_61 ) &&
V_54 -> V_63 == V_8 -> V_12 -> V_64 &&
V_54 -> V_65 == V_8 -> V_12 -> V_66 ) {
V_8 -> V_1 = F_41 ( & V_53 -> V_67 ,
V_54 -> V_56 ,
V_13 ) ;
if ( ! F_1 ( V_8 -> V_1 , V_54 -> V_56 ) ) {
F_13 ( V_8 -> V_1 ) ;
return false ;
}
V_8 -> V_14 = V_54 -> V_56 ;
return true ;
}
}
F_22 ( L_17 ) ;
return false ;
}
static inline bool F_36 ( struct V_7 * V_8 )
{
return false ;
}
bool F_42 ( struct V_7 * V_8 )
{
if ( F_30 ( V_8 ) )
goto V_68;
if ( F_36 ( V_8 ) )
goto V_68;
if ( F_6 ( V_8 ) )
goto V_68;
if ( F_14 ( V_8 ) )
goto V_68;
if ( F_18 ( V_8 ) )
goto V_68;
if ( F_34 ( V_8 ) )
goto V_68;
if ( F_23 ( V_8 ) )
goto V_68;
F_22 ( L_18 ) ;
return false ;
V_68:
V_8 -> F_5 = F_5 ( V_8 -> V_1 ) ;
return true ;
}
