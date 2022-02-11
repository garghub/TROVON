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
static bool F_5 ( struct V_5 * V_6 )
{
T_1 T_4 * V_1 ;
T_5 V_7 ;
T_5 V_2 = 256 * 1024 ;
if ( ! ( V_6 -> V_8 & V_9 ) )
if ( F_6 ( V_6 ) )
return false ;
V_6 -> V_1 = NULL ;
V_7 = F_7 ( V_6 -> V_10 , 0 ) ;
V_1 = F_8 ( V_7 , V_2 ) ;
if ( ! V_1 ) {
return false ;
}
V_6 -> V_1 = F_9 ( V_2 , V_11 ) ;
if ( ! V_6 -> V_1 ) {
F_10 ( V_1 ) ;
return false ;
}
V_6 -> V_12 = V_2 ;
F_11 ( V_6 -> V_1 , V_1 , V_2 ) ;
F_10 ( V_1 ) ;
if ( ! F_1 ( V_6 -> V_1 , V_2 ) ) {
F_12 ( V_6 -> V_1 ) ;
return false ;
}
return true ;
}
bool F_13 ( struct V_5 * V_6 )
{
T_1 T_4 * V_1 ;
T_2 V_2 ;
V_6 -> V_1 = NULL ;
V_1 = F_14 ( V_6 -> V_10 , & V_2 ) ;
if ( ! V_1 ) {
return false ;
}
V_6 -> V_1 = F_15 ( V_2 , V_11 ) ;
if ( V_6 -> V_1 == NULL ) {
F_16 ( V_6 -> V_10 , V_1 ) ;
return false ;
}
V_6 -> V_12 = V_2 ;
F_11 ( V_6 -> V_1 , V_1 , V_2 ) ;
F_16 ( V_6 -> V_10 , V_1 ) ;
if ( ! F_1 ( V_6 -> V_1 , V_2 ) ) {
F_12 ( V_6 -> V_1 ) ;
return false ;
}
return true ;
}
static bool F_17 ( struct V_5 * V_6 )
{
T_6 V_13 [ V_14 + 1 ] = { 0 } ;
int V_15 ;
if ( ! V_6 -> V_16 -> V_17 )
return false ;
if ( F_18 ( V_6 , & V_13 [ 0 ] , sizeof( V_13 ) ) == false )
return false ;
V_13 [ V_14 ] = 0 ;
if ( ( ! F_3 ( V_13 ) ) ||
0 != memcmp ( ( char * ) & V_13 [ V_18 ] ,
V_19 ,
strlen ( V_19 ) ) )
return false ;
V_15 = F_19 ( V_13 ) ;
V_15 = F_20 ( V_15 , 4 ) ;
V_6 -> V_1 = F_9 ( V_15 , V_11 ) ;
if ( ! V_6 -> V_1 ) {
F_21 ( L_9 ) ;
return false ;
}
V_6 -> V_12 = V_15 ;
F_18 ( V_6 , V_6 -> V_1 , V_15 ) ;
if ( ! F_1 ( V_6 -> V_1 , V_15 ) ) {
F_12 ( V_6 -> V_1 ) ;
return false ;
}
return true ;
}
static bool F_22 ( struct V_5 * V_6 )
{
T_1 T_4 * V_1 ;
T_2 V_2 ;
V_6 -> V_1 = NULL ;
V_1 = F_23 ( V_6 -> V_10 , & V_2 ) ;
if ( ! V_1 ) {
return false ;
}
V_6 -> V_1 = F_15 ( V_2 , V_11 ) ;
if ( V_6 -> V_1 == NULL )
return false ;
F_11 ( V_6 -> V_1 , V_1 , V_2 ) ;
if ( ! F_1 ( V_6 -> V_1 , V_2 ) ) {
F_12 ( V_6 -> V_1 ) ;
return false ;
}
V_6 -> V_12 = V_2 ;
return true ;
}
static int F_24 ( T_7 V_20 , T_1 * V_1 ,
int V_21 , int V_15 )
{
T_8 V_22 ;
union V_23 V_24 [ 2 ] , * V_25 ;
struct V_26 V_27 ;
struct V_28 V_29 = { V_30 , NULL } ;
V_27 . V_31 = 2 ;
V_27 . V_32 = & V_24 [ 0 ] ;
V_24 [ 0 ] . type = V_33 ;
V_24 [ 0 ] . integer . V_34 = V_21 ;
V_24 [ 1 ] . type = V_33 ;
V_24 [ 1 ] . integer . V_34 = V_15 ;
V_22 = F_25 ( V_20 , NULL , & V_27 , & V_29 ) ;
if ( F_26 ( V_22 ) ) {
F_27 ( L_10 , F_28 ( V_22 ) ) ;
return - V_35 ;
}
V_25 = (union V_23 * ) V_29 . V_32 ;
memcpy ( V_1 + V_21 , V_25 -> V_29 . V_32 , V_25 -> V_29 . V_36 ) ;
V_15 = V_25 -> V_29 . V_36 ;
F_12 ( V_29 . V_32 ) ;
return V_15 ;
}
static bool F_29 ( struct V_5 * V_6 )
{
int V_37 ;
int V_2 = 256 * 1024 ;
int V_38 ;
struct V_39 * V_10 = NULL ;
T_7 V_40 , V_20 ;
T_8 V_22 ;
bool V_41 = false ;
if ( V_6 -> V_8 & V_9 )
return false ;
while ( ( V_10 = F_30 ( V_42 << 8 , V_10 ) ) != NULL ) {
V_40 = F_31 ( & V_10 -> V_43 ) ;
if ( ! V_40 )
continue;
V_22 = F_32 ( V_40 , L_11 , & V_20 ) ;
if ( ! F_26 ( V_22 ) ) {
V_41 = true ;
break;
}
}
if ( ! V_41 ) {
while ( ( V_10 = F_30 ( V_44 << 8 , V_10 ) ) != NULL ) {
V_40 = F_31 ( & V_10 -> V_43 ) ;
if ( ! V_40 )
continue;
V_22 = F_32 ( V_40 , L_11 , & V_20 ) ;
if ( ! F_26 ( V_22 ) ) {
V_41 = true ;
break;
}
}
}
if ( ! V_41 )
return false ;
V_6 -> V_1 = F_9 ( V_2 , V_11 ) ;
if ( ! V_6 -> V_1 ) {
F_21 ( L_12 ) ;
return false ;
}
for ( V_38 = 0 ; V_38 < V_2 / V_45 ; V_38 ++ ) {
V_37 = F_24 ( V_20 ,
V_6 -> V_1 ,
( V_38 * V_45 ) ,
V_45 ) ;
if ( V_37 < V_45 )
break;
}
if ( ! F_1 ( V_6 -> V_1 , V_2 ) ) {
F_12 ( V_6 -> V_1 ) ;
return false ;
}
V_6 -> V_12 = V_2 ;
return true ;
}
static inline bool F_29 ( struct V_5 * V_6 )
{
return false ;
}
static bool F_33 ( struct V_5 * V_6 )
{
if ( V_6 -> V_8 & V_9 )
return F_5 ( V_6 ) ;
else
return F_34 ( V_6 ) ;
}
static bool F_35 ( struct V_5 * V_6 )
{
struct V_46 * V_47 ;
T_9 V_48 ;
T_10 * V_49 ;
unsigned V_21 ;
if ( ! F_36 ( F_37 ( L_13 , 1 , & V_47 ) ) )
return false ;
V_48 = V_47 -> V_36 ;
if ( V_48 < sizeof( T_10 ) ) {
F_21 ( L_14 ) ;
return false ;
}
V_49 = ( T_10 * ) V_47 ;
V_21 = V_49 -> V_50 ;
while ( V_21 < V_48 ) {
T_11 * V_51 = ( T_11 * ) ( ( char * ) V_47 + V_21 ) ;
T_12 * V_52 = & V_51 -> V_53 ;
V_21 += sizeof( T_12 ) ;
if ( V_21 > V_48 ) {
F_21 ( L_15 ) ;
return false ;
}
V_21 += V_52 -> V_54 ;
if ( V_21 > V_48 ) {
F_21 ( L_16 ) ;
return false ;
}
if ( V_52 -> V_54 &&
V_52 -> V_55 == V_6 -> V_10 -> V_56 -> V_57 &&
V_52 -> V_58 == F_38 ( V_6 -> V_10 -> V_59 ) &&
V_52 -> V_60 == F_39 ( V_6 -> V_10 -> V_59 ) &&
V_52 -> V_61 == V_6 -> V_10 -> V_62 &&
V_52 -> V_63 == V_6 -> V_10 -> V_64 ) {
V_6 -> V_1 = F_40 ( & V_51 -> V_65 ,
V_52 -> V_54 ,
V_11 ) ;
if ( ! F_1 ( V_6 -> V_1 , V_52 -> V_54 ) ) {
F_12 ( V_6 -> V_1 ) ;
return false ;
}
V_6 -> V_12 = V_52 -> V_54 ;
return true ;
}
}
F_21 ( L_17 ) ;
return false ;
}
static inline bool F_35 ( struct V_5 * V_6 )
{
return false ;
}
bool F_41 ( struct V_5 * V_6 )
{
if ( F_29 ( V_6 ) )
goto V_66;
if ( F_35 ( V_6 ) )
goto V_66;
if ( F_5 ( V_6 ) )
goto V_66;
if ( F_13 ( V_6 ) )
goto V_66;
if ( F_17 ( V_6 ) )
goto V_66;
if ( F_33 ( V_6 ) )
goto V_66;
if ( F_22 ( V_6 ) )
goto V_66;
F_21 ( L_18 ) ;
return false ;
V_66:
V_6 -> V_67 = ( V_6 -> V_68 >= V_69 ) ? true : false ;
return true ;
}
