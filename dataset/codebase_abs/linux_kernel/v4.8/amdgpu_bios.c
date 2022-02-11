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
if ( V_2 -> V_3 == NULL ) {
F_6 ( V_3 ) ;
return false ;
}
F_8 ( V_2 -> V_3 , V_3 , V_5 ) ;
F_6 ( V_3 ) ;
return true ;
}
bool F_9 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 , V_10 [ 2 ] ;
T_4 V_5 ;
V_2 -> V_3 = NULL ;
V_3 = F_10 ( V_2 -> V_8 , & V_5 ) ;
if ( ! V_3 ) {
return false ;
}
V_10 [ 0 ] = F_11 ( & V_3 [ 0 ] ) ;
V_10 [ 1 ] = F_11 ( & V_3 [ 1 ] ) ;
if ( V_5 == 0 || ! F_5 ( V_10 ) ) {
F_12 ( V_2 -> V_8 , V_3 ) ;
return false ;
}
V_2 -> V_3 = F_13 ( V_5 , V_9 ) ;
if ( V_2 -> V_3 == NULL ) {
F_12 ( V_2 -> V_8 , V_3 ) ;
return false ;
}
F_8 ( V_2 -> V_3 , V_3 , V_5 ) ;
F_12 ( V_2 -> V_8 , V_3 ) ;
return true ;
}
static bool F_14 ( struct V_1 * V_2 )
{
T_5 V_11 [ V_12 + 1 ] = { 0 } ;
int V_13 ;
if ( ! V_2 -> V_14 -> V_15 )
return false ;
if ( F_15 ( V_2 , & V_11 [ 0 ] , sizeof( V_11 ) ) == false )
return false ;
V_11 [ V_12 ] = 0 ;
if ( ( ! F_5 ( V_11 ) ) ||
0 != memcmp ( ( char * ) & V_11 [ V_16 ] ,
V_17 ,
strlen ( V_17 ) ) )
return false ;
V_13 = F_16 ( V_11 ) ;
V_13 = F_17 ( V_13 , 4 ) ;
V_2 -> V_3 = F_7 ( V_13 , V_9 ) ;
if ( ! V_2 -> V_3 ) {
F_18 ( L_1 ) ;
return false ;
}
return F_15 ( V_2 , V_2 -> V_3 , V_13 ) ;
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
return true ;
}
static int F_22 ( T_6 V_18 , T_1 * V_3 ,
int V_19 , int V_13 )
{
T_7 V_20 ;
union V_21 V_22 [ 2 ] , * V_23 ;
struct V_24 V_25 ;
struct V_26 V_27 = { V_28 , NULL } ;
V_25 . V_29 = 2 ;
V_25 . V_30 = & V_22 [ 0 ] ;
V_22 [ 0 ] . type = V_31 ;
V_22 [ 0 ] . integer . V_32 = V_19 ;
V_22 [ 1 ] . type = V_31 ;
V_22 [ 1 ] . integer . V_32 = V_13 ;
V_20 = F_23 ( V_18 , NULL , & V_25 , & V_27 ) ;
if ( F_24 ( V_20 ) ) {
F_25 ( L_2 , F_26 ( V_20 ) ) ;
return - V_33 ;
}
V_23 = (union V_21 * ) V_27 . V_30 ;
memcpy ( V_3 + V_19 , V_23 -> V_27 . V_30 , V_23 -> V_27 . V_34 ) ;
V_13 = V_23 -> V_27 . V_34 ;
F_27 ( V_27 . V_30 ) ;
return V_13 ;
}
static bool F_28 ( struct V_1 * V_2 )
{
int V_35 ;
int V_5 = 256 * 1024 ;
int V_36 ;
struct V_37 * V_8 = NULL ;
T_6 V_38 , V_18 ;
T_7 V_20 ;
bool V_39 = false ;
if ( V_2 -> V_6 & V_7 )
return false ;
while ( ( V_8 = F_29 ( V_40 << 8 , V_8 ) ) != NULL ) {
V_38 = F_30 ( & V_8 -> V_41 ) ;
if ( ! V_38 )
continue;
V_20 = F_31 ( V_38 , L_3 , & V_18 ) ;
if ( ! F_24 ( V_20 ) ) {
V_39 = true ;
break;
}
}
if ( ! V_39 ) {
while ( ( V_8 = F_29 ( V_42 << 8 , V_8 ) ) != NULL ) {
V_38 = F_30 ( & V_8 -> V_41 ) ;
if ( ! V_38 )
continue;
V_20 = F_31 ( V_38 , L_3 , & V_18 ) ;
if ( ! F_24 ( V_20 ) ) {
V_39 = true ;
break;
}
}
}
if ( ! V_39 )
return false ;
V_2 -> V_3 = F_7 ( V_5 , V_9 ) ;
if ( ! V_2 -> V_3 ) {
F_18 ( L_4 ) ;
return false ;
}
for ( V_36 = 0 ; V_36 < V_5 / V_43 ; V_36 ++ ) {
V_35 = F_22 ( V_18 ,
V_2 -> V_3 ,
( V_36 * V_43 ) ,
V_43 ) ;
if ( V_35 < V_43 )
break;
}
if ( V_36 == 0 || ! F_5 ( V_2 -> V_3 ) ) {
F_27 ( V_2 -> V_3 ) ;
return false ;
}
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
bool V_35 = false ;
struct V_44 * V_45 ;
T_8 V_46 ;
T_9 * V_47 ;
T_10 * V_48 ;
T_11 * V_49 ;
if ( ! F_35 ( F_36 ( L_5 , 1 , & V_45 , & V_46 ) ) )
return false ;
if ( V_46 < sizeof( T_9 ) ) {
F_18 ( L_6 ) ;
goto V_50;
}
V_47 = ( T_9 * ) V_45 ;
if ( V_47 -> V_51 + sizeof( T_11 ) > V_46 ) {
F_18 ( L_7 ) ;
goto V_50;
}
V_48 = ( T_10 * ) ( ( char * ) V_45 + V_47 -> V_51 ) ;
V_49 = & V_48 -> V_52 ;
F_37 ( L_8 ,
V_49 -> V_53 , V_49 -> V_54 , V_49 -> V_55 ,
V_49 -> V_56 , V_49 -> V_57 , V_49 -> V_58 ) ;
if ( V_49 -> V_53 != V_2 -> V_8 -> V_59 -> V_60 ||
V_49 -> V_54 != F_38 ( V_2 -> V_8 -> V_61 ) ||
V_49 -> V_55 != F_39 ( V_2 -> V_8 -> V_61 ) ||
V_49 -> V_56 != V_2 -> V_8 -> V_62 ||
V_49 -> V_57 != V_2 -> V_8 -> V_63 ) {
F_37 ( L_9 ) ;
goto V_50;
}
if ( V_47 -> V_51 + sizeof( T_11 ) + V_49 -> V_58 > V_46 ) {
F_18 ( L_10 ) ;
goto V_50;
}
V_2 -> V_3 = F_21 ( & V_48 -> V_64 , V_49 -> V_58 , V_9 ) ;
V_35 = ! ! V_2 -> V_3 ;
V_50:
return V_35 ;
}
static inline bool F_34 ( struct V_1 * V_2 )
{
return false ;
}
bool F_40 ( struct V_1 * V_2 )
{
bool V_65 ;
T_12 V_66 , V_67 ;
V_65 = F_28 ( V_2 ) ;
if ( ! V_65 )
V_65 = F_34 ( V_2 ) ;
if ( ! V_65 )
V_65 = F_1 ( V_2 ) ;
if ( ! V_65 )
V_65 = F_9 ( V_2 ) ;
if ( ! V_65 ) {
V_65 = F_14 ( V_2 ) ;
}
if ( ! V_65 ) {
V_65 = F_32 ( V_2 ) ;
}
if ( ! V_65 ) {
V_65 = F_19 ( V_2 ) ;
}
if ( ! V_65 || V_2 -> V_3 == NULL ) {
F_18 ( L_11 ) ;
V_2 -> V_3 = NULL ;
return false ;
}
if ( ! F_5 ( V_2 -> V_3 ) ) {
F_25 ( L_12 , V_2 -> V_3 [ 0 ] , V_2 -> V_3 [ 1 ] ) ;
goto V_68;
}
V_66 = F_41 ( 0x18 ) ;
if ( F_42 ( V_66 + 0x14 ) != 0x0 ) {
F_37 ( L_13 ) ;
goto V_68;
}
V_67 = F_41 ( 0x48 ) ;
if ( ! V_67 ) {
goto V_68;
}
V_66 = V_67 + 4 ;
if ( ! memcmp ( V_2 -> V_3 + V_66 , L_14 , 4 ) ||
! memcmp ( V_2 -> V_3 + V_66 , L_15 , 4 ) ) {
V_2 -> V_69 = true ;
} else {
V_2 -> V_69 = false ;
}
F_43 ( L_16 , V_2 -> V_69 ? L_14 : L_17 ) ;
return true ;
V_68:
F_27 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return false ;
}
