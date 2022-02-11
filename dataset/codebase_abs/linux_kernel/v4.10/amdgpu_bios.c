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
if ( V_5 == 0 || ! F_5 ( V_3 ) ) {
F_6 ( V_3 ) ;
return false ;
}
V_2 -> V_3 = F_7 ( V_5 , V_9 ) ;
if ( ! V_2 -> V_3 ) {
F_6 ( V_3 ) ;
return false ;
}
V_2 -> V_10 = V_5 ;
F_8 ( V_2 -> V_3 , V_3 , V_5 ) ;
F_6 ( V_3 ) ;
return true ;
}
bool F_9 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 , V_11 [ 2 ] ;
T_4 V_5 ;
V_2 -> V_3 = NULL ;
V_3 = F_10 ( V_2 -> V_8 , & V_5 ) ;
if ( ! V_3 ) {
return false ;
}
V_11 [ 0 ] = F_11 ( & V_3 [ 0 ] ) ;
V_11 [ 1 ] = F_11 ( & V_3 [ 1 ] ) ;
if ( V_5 == 0 || ! F_5 ( V_11 ) ) {
F_12 ( V_2 -> V_8 , V_3 ) ;
return false ;
}
V_2 -> V_3 = F_13 ( V_5 , V_9 ) ;
if ( V_2 -> V_3 == NULL ) {
F_12 ( V_2 -> V_8 , V_3 ) ;
return false ;
}
V_2 -> V_10 = V_5 ;
F_8 ( V_2 -> V_3 , V_3 , V_5 ) ;
F_12 ( V_2 -> V_8 , V_3 ) ;
return true ;
}
static bool F_14 ( struct V_1 * V_2 )
{
T_5 V_12 [ V_13 + 1 ] = { 0 } ;
int V_14 ;
if ( ! V_2 -> V_15 -> V_16 )
return false ;
if ( F_15 ( V_2 , & V_12 [ 0 ] , sizeof( V_12 ) ) == false )
return false ;
V_12 [ V_13 ] = 0 ;
if ( ( ! F_5 ( V_12 ) ) ||
0 != memcmp ( ( char * ) & V_12 [ V_17 ] ,
V_18 ,
strlen ( V_18 ) ) )
return false ;
V_14 = F_16 ( V_12 ) ;
V_14 = F_17 ( V_14 , 4 ) ;
V_2 -> V_3 = F_7 ( V_14 , V_9 ) ;
if ( ! V_2 -> V_3 ) {
F_18 ( L_1 ) ;
return false ;
}
V_2 -> V_10 = V_14 ;
return F_15 ( V_2 , V_2 -> V_3 , V_14 ) ;
}
static bool F_19 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 ;
T_4 V_5 ;
V_2 -> V_3 = NULL ;
V_3 = F_20 ( V_2 -> V_8 , & V_5 ) ;
if ( ! V_3 ) {
return false ;
}
if ( V_5 == 0 || ! F_5 ( V_3 ) ) {
return false ;
}
V_2 -> V_3 = F_21 ( V_3 , V_5 , V_9 ) ;
if ( V_2 -> V_3 == NULL ) {
return false ;
}
V_2 -> V_10 = V_5 ;
return true ;
}
static int F_22 ( T_6 V_19 , T_1 * V_3 ,
int V_20 , int V_14 )
{
T_7 V_21 ;
union V_22 V_23 [ 2 ] , * V_24 ;
struct V_25 V_26 ;
struct V_27 V_28 = { V_29 , NULL } ;
V_26 . V_30 = 2 ;
V_26 . V_31 = & V_23 [ 0 ] ;
V_23 [ 0 ] . type = V_32 ;
V_23 [ 0 ] . integer . V_33 = V_20 ;
V_23 [ 1 ] . type = V_32 ;
V_23 [ 1 ] . integer . V_33 = V_14 ;
V_21 = F_23 ( V_19 , NULL , & V_26 , & V_28 ) ;
if ( F_24 ( V_21 ) ) {
F_25 ( L_2 , F_26 ( V_21 ) ) ;
return - V_34 ;
}
V_24 = (union V_22 * ) V_28 . V_31 ;
memcpy ( V_3 + V_20 , V_24 -> V_28 . V_31 , V_24 -> V_28 . V_35 ) ;
V_14 = V_24 -> V_28 . V_35 ;
F_27 ( V_28 . V_31 ) ;
return V_14 ;
}
static bool F_28 ( struct V_1 * V_2 )
{
int V_36 ;
int V_5 = 256 * 1024 ;
int V_37 ;
struct V_38 * V_8 = NULL ;
T_6 V_39 , V_19 ;
T_7 V_21 ;
bool V_40 = false ;
if ( V_2 -> V_6 & V_7 )
return false ;
while ( ( V_8 = F_29 ( V_41 << 8 , V_8 ) ) != NULL ) {
V_39 = F_30 ( & V_8 -> V_42 ) ;
if ( ! V_39 )
continue;
V_21 = F_31 ( V_39 , L_3 , & V_19 ) ;
if ( ! F_24 ( V_21 ) ) {
V_40 = true ;
break;
}
}
if ( ! V_40 ) {
while ( ( V_8 = F_29 ( V_43 << 8 , V_8 ) ) != NULL ) {
V_39 = F_30 ( & V_8 -> V_42 ) ;
if ( ! V_39 )
continue;
V_21 = F_31 ( V_39 , L_3 , & V_19 ) ;
if ( ! F_24 ( V_21 ) ) {
V_40 = true ;
break;
}
}
}
if ( ! V_40 )
return false ;
V_2 -> V_3 = F_7 ( V_5 , V_9 ) ;
if ( ! V_2 -> V_3 ) {
F_18 ( L_4 ) ;
return false ;
}
for ( V_37 = 0 ; V_37 < V_5 / V_44 ; V_37 ++ ) {
V_36 = F_22 ( V_19 ,
V_2 -> V_3 ,
( V_37 * V_44 ) ,
V_44 ) ;
if ( V_36 < V_44 )
break;
}
if ( V_37 == 0 || ! F_5 ( V_2 -> V_3 ) ) {
F_27 ( V_2 -> V_3 ) ;
return false ;
}
V_2 -> V_10 = V_5 ;
return true ;
}
static inline bool F_28 ( struct V_1 * V_2 )
{
return false ;
}
static bool F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 & V_7 )
return F_1 ( V_2 ) ;
else
return F_33 ( V_2 ) ;
}
static bool F_34 ( struct V_1 * V_2 )
{
bool V_36 = false ;
struct V_45 * V_46 ;
T_8 V_47 ;
T_9 * V_48 ;
T_10 * V_49 ;
T_11 * V_50 ;
if ( ! F_35 ( F_36 ( L_5 , 1 , & V_46 ) ) )
return false ;
V_47 = V_46 -> V_35 ;
if ( V_47 < sizeof( T_9 ) ) {
F_18 ( L_6 ) ;
goto V_51;
}
V_48 = ( T_9 * ) V_46 ;
if ( V_48 -> V_52 + sizeof( T_11 ) > V_47 ) {
F_18 ( L_7 ) ;
goto V_51;
}
V_49 = ( T_10 * ) ( ( char * ) V_46 + V_48 -> V_52 ) ;
V_50 = & V_49 -> V_53 ;
F_37 ( L_8 ,
V_50 -> V_54 , V_50 -> V_55 , V_50 -> V_56 ,
V_50 -> V_57 , V_50 -> V_58 , V_50 -> V_59 ) ;
if ( V_50 -> V_54 != V_2 -> V_8 -> V_60 -> V_61 ||
V_50 -> V_55 != F_38 ( V_2 -> V_8 -> V_62 ) ||
V_50 -> V_56 != F_39 ( V_2 -> V_8 -> V_62 ) ||
V_50 -> V_57 != V_2 -> V_8 -> V_63 ||
V_50 -> V_58 != V_2 -> V_8 -> V_64 ) {
F_37 ( L_9 ) ;
goto V_51;
}
if ( V_48 -> V_52 + sizeof( T_11 ) + V_50 -> V_59 > V_47 ) {
F_18 ( L_10 ) ;
goto V_51;
}
V_2 -> V_3 = F_21 ( & V_49 -> V_65 , V_50 -> V_59 , V_9 ) ;
V_2 -> V_10 = V_50 -> V_59 ;
V_36 = ! ! V_2 -> V_3 ;
V_51:
return V_36 ;
}
static inline bool F_34 ( struct V_1 * V_2 )
{
return false ;
}
bool F_40 ( struct V_1 * V_2 )
{
bool V_66 ;
T_12 V_67 , V_68 ;
V_66 = F_28 ( V_2 ) ;
if ( ! V_66 )
V_66 = F_34 ( V_2 ) ;
if ( ! V_66 )
V_66 = F_1 ( V_2 ) ;
if ( ! V_66 )
V_66 = F_9 ( V_2 ) ;
if ( ! V_66 ) {
V_66 = F_14 ( V_2 ) ;
}
if ( ! V_66 ) {
V_66 = F_32 ( V_2 ) ;
}
if ( ! V_66 ) {
V_66 = F_19 ( V_2 ) ;
}
if ( ! V_66 || V_2 -> V_3 == NULL ) {
F_18 ( L_11 ) ;
V_2 -> V_3 = NULL ;
return false ;
}
if ( ! F_5 ( V_2 -> V_3 ) ) {
F_25 ( L_12 , V_2 -> V_3 [ 0 ] , V_2 -> V_3 [ 1 ] ) ;
goto V_69;
}
V_67 = F_41 ( 0x18 ) ;
if ( F_42 ( V_67 + 0x14 ) != 0x0 ) {
F_37 ( L_13 ) ;
goto V_69;
}
V_68 = F_41 ( 0x48 ) ;
if ( ! V_68 ) {
goto V_69;
}
V_67 = V_68 + 4 ;
if ( ! memcmp ( V_2 -> V_3 + V_67 , L_14 , 4 ) ||
! memcmp ( V_2 -> V_3 + V_67 , L_15 , 4 ) ) {
V_2 -> V_70 = true ;
} else {
V_2 -> V_70 = false ;
}
F_43 ( L_16 , V_2 -> V_70 ? L_14 : L_17 ) ;
return true ;
V_69:
F_27 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return false ;
}
