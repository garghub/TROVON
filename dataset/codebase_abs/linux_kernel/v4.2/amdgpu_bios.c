static bool F_1 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 ;
T_3 V_4 ;
T_3 V_5 = 256 * 1024 ;
if ( ! ( V_2 -> V_6 & V_7 ) )
if ( ! F_2 ( V_2 ) )
return false ;
V_2 -> V_3 = NULL ;
V_4 = F_3 ( V_2 -> V_8 , 0 ) ;
V_3 = F_4 ( V_4 , V_5 ) ;
if ( ! V_3 ) {
return false ;
}
if ( V_5 == 0 || V_3 [ 0 ] != 0x55 || V_3 [ 1 ] != 0xaa ) {
F_5 ( V_3 ) ;
return false ;
}
V_2 -> V_3 = F_6 ( V_5 , V_9 ) ;
if ( V_2 -> V_3 == NULL ) {
F_5 ( V_3 ) ;
return false ;
}
F_7 ( V_2 -> V_3 , V_3 , V_5 ) ;
F_5 ( V_3 ) ;
return true ;
}
bool F_8 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 , V_10 , V_11 ;
T_4 V_5 ;
V_2 -> V_3 = NULL ;
V_3 = F_9 ( V_2 -> V_8 , & V_5 ) ;
if ( ! V_3 ) {
return false ;
}
V_10 = F_10 ( & V_3 [ 0 ] ) ;
V_11 = F_10 ( & V_3 [ 1 ] ) ;
if ( V_5 == 0 || V_10 != 0x55 || V_11 != 0xaa ) {
F_11 ( V_2 -> V_8 , V_3 ) ;
return false ;
}
V_2 -> V_3 = F_12 ( V_5 , V_9 ) ;
if ( V_2 -> V_3 == NULL ) {
F_11 ( V_2 -> V_8 , V_3 ) ;
return false ;
}
F_7 ( V_2 -> V_3 , V_3 , V_5 ) ;
F_11 ( V_2 -> V_8 , V_3 ) ;
return true ;
}
static bool F_13 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 ;
T_4 V_5 ;
V_2 -> V_3 = NULL ;
V_3 = F_14 ( V_2 -> V_8 , & V_5 ) ;
if ( ! V_3 ) {
return false ;
}
if ( V_5 == 0 || V_3 [ 0 ] != 0x55 || V_3 [ 1 ] != 0xaa ) {
return false ;
}
V_2 -> V_3 = F_15 ( V_3 , V_5 , V_9 ) ;
if ( V_2 -> V_3 == NULL ) {
return false ;
}
return true ;
}
static int F_16 ( T_5 V_12 , T_1 * V_3 ,
int V_13 , int V_14 )
{
T_6 V_15 ;
union V_16 V_17 [ 2 ] , * V_18 ;
struct V_19 V_20 ;
struct V_21 V_22 = { V_23 , NULL } ;
V_20 . V_24 = 2 ;
V_20 . V_25 = & V_17 [ 0 ] ;
V_17 [ 0 ] . type = V_26 ;
V_17 [ 0 ] . integer . V_27 = V_13 ;
V_17 [ 1 ] . type = V_26 ;
V_17 [ 1 ] . integer . V_27 = V_14 ;
V_15 = F_17 ( V_12 , NULL , & V_20 , & V_22 ) ;
if ( F_18 ( V_15 ) ) {
F_19 ( L_1 , F_20 ( V_15 ) ) ;
return - V_28 ;
}
V_18 = (union V_16 * ) V_22 . V_25 ;
memcpy ( V_3 + V_13 , V_18 -> V_22 . V_25 , V_18 -> V_22 . V_29 ) ;
V_14 = V_18 -> V_22 . V_29 ;
F_21 ( V_22 . V_25 ) ;
return V_14 ;
}
static bool F_22 ( struct V_1 * V_2 )
{
int V_30 ;
int V_5 = 256 * 1024 ;
int V_31 ;
struct V_32 * V_8 = NULL ;
T_5 V_33 , V_12 ;
T_6 V_15 ;
bool V_34 = false ;
if ( V_2 -> V_6 & V_7 )
return false ;
while ( ( V_8 = F_23 ( V_35 << 8 , V_8 ) ) != NULL ) {
V_33 = F_24 ( & V_8 -> V_36 ) ;
if ( ! V_33 )
continue;
V_15 = F_25 ( V_33 , L_2 , & V_12 ) ;
if ( ! F_18 ( V_15 ) ) {
V_34 = true ;
break;
}
}
if ( ! V_34 ) {
while ( ( V_8 = F_23 ( V_37 << 8 , V_8 ) ) != NULL ) {
V_33 = F_24 ( & V_8 -> V_36 ) ;
if ( ! V_33 )
continue;
V_15 = F_25 ( V_33 , L_2 , & V_12 ) ;
if ( ! F_18 ( V_15 ) ) {
V_34 = true ;
break;
}
}
}
if ( ! V_34 )
return false ;
V_2 -> V_3 = F_6 ( V_5 , V_9 ) ;
if ( ! V_2 -> V_3 ) {
F_26 ( L_3 ) ;
return false ;
}
for ( V_31 = 0 ; V_31 < V_5 / V_38 ; V_31 ++ ) {
V_30 = F_16 ( V_12 ,
V_2 -> V_3 ,
( V_31 * V_38 ) ,
V_38 ) ;
if ( V_30 < V_38 )
break;
}
if ( V_31 == 0 || V_2 -> V_3 [ 0 ] != 0x55 || V_2 -> V_3 [ 1 ] != 0xaa ) {
F_21 ( V_2 -> V_3 ) ;
return false ;
}
return true ;
}
static inline bool F_22 ( struct V_1 * V_2 )
{
return false ;
}
static bool F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 & V_7 )
return F_1 ( V_2 ) ;
else
return F_28 ( V_2 ) ;
}
static bool F_29 ( struct V_1 * V_2 )
{
bool V_30 = false ;
struct V_39 * V_40 ;
T_7 V_41 ;
T_8 * V_42 ;
T_9 * V_43 ;
T_10 * V_44 ;
if ( ! F_30 ( F_31 ( L_4 , 1 , & V_40 , & V_41 ) ) )
return false ;
if ( V_41 < sizeof( T_8 ) ) {
F_26 ( L_5 ) ;
goto V_45;
}
V_42 = ( T_8 * ) V_40 ;
if ( V_42 -> V_46 + sizeof( T_10 ) > V_41 ) {
F_26 ( L_6 ) ;
goto V_45;
}
V_43 = ( T_9 * ) ( ( char * ) V_40 + V_42 -> V_46 ) ;
V_44 = & V_43 -> V_47 ;
F_32 ( L_7 ,
V_44 -> V_48 , V_44 -> V_49 , V_44 -> V_50 ,
V_44 -> V_51 , V_44 -> V_52 , V_44 -> V_53 ) ;
if ( V_44 -> V_48 != V_2 -> V_8 -> V_54 -> V_55 ||
V_44 -> V_49 != F_33 ( V_2 -> V_8 -> V_56 ) ||
V_44 -> V_50 != F_34 ( V_2 -> V_8 -> V_56 ) ||
V_44 -> V_51 != V_2 -> V_8 -> V_57 ||
V_44 -> V_52 != V_2 -> V_8 -> V_58 ) {
F_32 ( L_8 ) ;
goto V_45;
}
if ( V_42 -> V_46 + sizeof( T_10 ) + V_44 -> V_53 > V_41 ) {
F_26 ( L_9 ) ;
goto V_45;
}
V_2 -> V_3 = F_15 ( & V_43 -> V_59 , V_44 -> V_53 , V_9 ) ;
V_30 = ! ! V_2 -> V_3 ;
V_45:
return V_30 ;
}
static inline bool F_29 ( struct V_1 * V_2 )
{
return false ;
}
bool F_35 ( struct V_1 * V_2 )
{
bool V_60 ;
T_11 V_61 ;
V_60 = F_22 ( V_2 ) ;
if ( V_60 == false )
V_60 = F_29 ( V_2 ) ;
if ( V_60 == false )
V_60 = F_1 ( V_2 ) ;
if ( V_60 == false )
V_60 = F_8 ( V_2 ) ;
if ( V_60 == false ) {
V_60 = F_27 ( V_2 ) ;
}
if ( V_60 == false ) {
V_60 = F_13 ( V_2 ) ;
}
if ( V_60 == false || V_2 -> V_3 == NULL ) {
F_26 ( L_10 ) ;
V_2 -> V_3 = NULL ;
return false ;
}
if ( V_2 -> V_3 [ 0 ] != 0x55 || V_2 -> V_3 [ 1 ] != 0xaa ) {
F_19 ( L_11 , V_2 -> V_3 [ 0 ] , V_2 -> V_3 [ 1 ] ) ;
goto V_62;
}
V_61 = F_36 ( 0x18 ) ;
if ( F_37 ( V_61 + 0x14 ) != 0x0 ) {
F_32 ( L_12 ) ;
goto V_62;
}
V_2 -> V_63 = F_36 ( 0x48 ) ;
if ( ! V_2 -> V_63 ) {
goto V_62;
}
V_61 = V_2 -> V_63 + 4 ;
if ( ! memcmp ( V_2 -> V_3 + V_61 , L_13 , 4 ) ||
! memcmp ( V_2 -> V_3 + V_61 , L_14 , 4 ) ) {
V_2 -> V_64 = true ;
} else {
V_2 -> V_64 = false ;
}
F_38 ( L_15 , V_2 -> V_64 ? L_13 : L_16 ) ;
return true ;
V_62:
F_21 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return false ;
}
