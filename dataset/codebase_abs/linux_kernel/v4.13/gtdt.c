static inline void * F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
V_1 += V_3 -> V_4 ;
if ( V_1 < V_5 . V_6 )
return V_1 ;
return NULL ;
}
static inline bool F_2 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
return V_3 -> type == V_7 ;
}
static inline bool F_3 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_8 * V_9 = V_1 ;
if ( V_3 -> type != V_10 )
return false ;
return ! ( V_9 -> V_11 & V_12 ) ;
}
static int T_1 F_4 ( T_2 V_13 , T_2 V_14 )
{
int V_15 , V_16 ;
V_15 = ( V_14 & V_17 ) ? V_18
: V_19 ;
V_16 = ( V_14 & V_20 ) ? V_21
: V_22 ;
return F_5 ( NULL , V_13 , V_15 , V_16 ) ;
}
int T_1 F_6 ( int type )
{
struct V_23 * V_24 = V_5 . V_24 ;
switch ( type ) {
case V_25 :
return F_4 ( V_24 -> V_26 ,
V_24 -> V_27 ) ;
case V_28 :
return F_4 ( V_24 -> V_29 ,
V_24 -> V_30 ) ;
case V_31 :
return F_4 ( V_24 -> V_32 ,
V_24 -> V_33 ) ;
default:
F_7 ( L_1 ) ;
}
return 0 ;
}
bool T_1 F_8 ( int type )
{
struct V_23 * V_24 = V_5 . V_24 ;
switch ( type ) {
case V_25 :
return ! ( V_24 -> V_27 & V_34 ) ;
case V_28 :
return ! ( V_24 -> V_30 & V_34 ) ;
case V_31 :
return ! ( V_24 -> V_33 & V_34 ) ;
default:
F_7 ( L_2 ) ;
}
return false ;
}
int T_1 F_9 ( struct V_35 * V_36 ,
int * V_37 )
{
void * V_1 ;
struct V_23 * V_24 ;
V_24 = F_10 ( V_36 , struct V_23 , V_38 ) ;
V_5 . V_24 = V_24 ;
V_5 . V_6 = ( void * ) V_36 + V_36 -> V_4 ;
V_5 . V_1 = NULL ;
if ( V_37 )
* V_37 = 0 ;
if ( V_36 -> V_39 < 2 ) {
F_11 ( L_3 ,
V_36 -> V_39 ) ;
return 0 ;
}
if ( ! V_24 -> V_37 ) {
F_12 ( L_4 ) ;
return 0 ;
}
V_1 = ( void * ) V_24 + V_24 -> V_40 ;
if ( V_1 < ( void * ) V_36 + sizeof( struct V_23 ) ) {
F_7 ( V_41 L_5 ) ;
return - V_42 ;
}
V_5 . V_1 = V_1 ;
if ( V_37 )
* V_37 = V_24 -> V_37 ;
return 0 ;
}
static int T_1 F_13 ( struct V_43 * V_44 ,
struct V_45 * V_46 )
{
int V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
if ( ! V_44 -> V_52 ) {
F_7 ( V_41 L_6 ) ;
return - V_53 ;
}
if ( V_44 -> V_52 > V_54 ) {
F_7 ( V_41 L_7 ,
V_44 -> V_52 ) ;
return - V_42 ;
}
V_46 -> V_55 = ( V_56 ) V_44 -> V_57 ;
V_46 -> V_58 = V_59 ;
V_51 = ( void * ) V_44 + V_44 -> V_60 ;
if ( V_51 + V_44 -> V_52 != ( void * ) V_44 + V_44 -> V_38 . V_4 )
return - V_42 ;
for ( V_47 = 0 ; V_47 < V_44 -> V_52 ; V_47 ++ , V_51 ++ ) {
if ( V_51 -> V_61 & V_62 )
continue;
if ( V_51 -> V_63 >= V_54 ||
! V_51 -> V_64 || ! V_51 -> V_65 )
goto error;
V_49 = & V_46 -> V_49 [ V_51 -> V_63 ] ;
if ( V_49 -> V_66 )
goto error;
V_49 -> V_67 = F_4 ( V_51 -> V_65 ,
V_51 -> V_11 ) ;
if ( V_49 -> V_67 <= 0 ) {
F_11 ( L_8 ,
V_51 -> V_63 ) ;
goto error;
}
if ( V_51 -> V_29 ) {
V_49 -> V_68 =
F_4 ( V_51 -> V_29 ,
V_51 -> V_30 ) ;
if ( V_49 -> V_68 <= 0 ) {
F_11 ( L_9 ,
V_51 -> V_63 ) ;
goto error;
}
} else {
F_12 ( L_10 ,
V_51 -> V_63 ) ;
}
V_49 -> V_69 = V_51 -> V_64 ;
V_49 -> V_58 = V_59 ;
V_49 -> V_66 = true ;
}
return 0 ;
error:
do {
if ( V_51 -> V_61 & V_62 ||
V_51 -> V_63 >= V_54 )
continue;
V_49 = & V_46 -> V_49 [ V_51 -> V_63 ] ;
if ( V_49 -> V_67 > 0 )
F_14 ( V_51 -> V_65 ) ;
V_49 -> V_67 = 0 ;
if ( V_49 -> V_68 > 0 )
F_14 ( V_51 -> V_29 ) ;
V_49 -> V_68 = 0 ;
} while ( V_47 -- >= 0 && V_51 -- );
return - V_42 ;
}
int T_1 F_15 ( struct V_45 * V_46 ,
int * V_52 )
{
int V_70 ;
void * V_1 ;
* V_52 = 0 ;
F_16 (platform_timer) {
if ( F_2 ( V_1 ) ) {
V_70 = F_13 ( V_1 , V_46 ) ;
if ( V_70 )
return V_70 ;
V_46 ++ ;
( * V_52 ) ++ ;
}
}
if ( * V_52 )
F_17 ( L_11 ,
* V_52 ) ;
return 0 ;
}
static int T_1 F_18 ( struct V_8 * V_9 ,
int V_71 )
{
struct V_72 * V_73 ;
int V_74 = F_4 ( V_9 -> V_65 , V_9 -> V_11 ) ;
struct V_75 V_76 [] = {
F_19 ( V_9 -> V_77 , V_59 ) ,
F_19 ( V_9 -> V_78 , V_59 ) ,
F_20 ( V_74 ) ,
} ;
int V_79 = F_21 ( V_76 ) ;
F_12 ( L_12 ,
V_9 -> V_78 , V_9 -> V_77 ,
V_9 -> V_65 , V_9 -> V_11 ) ;
if ( ! ( V_9 -> V_78 && V_9 -> V_77 ) ) {
F_7 ( V_41 L_13 ) ;
F_14 ( V_9 -> V_65 ) ;
return - V_42 ;
}
if ( V_74 <= 0 ) {
F_11 ( L_14 ) ;
V_79 -- ;
}
V_73 = F_22 ( L_15 , V_71 , V_76 , V_79 ) ;
if ( F_23 ( V_73 ) ) {
F_14 ( V_9 -> V_65 ) ;
return F_24 ( V_73 ) ;
}
return 0 ;
}
static int T_1 F_25 ( void )
{
void * V_1 ;
struct V_35 * V_36 ;
int V_70 , V_52 , V_80 = 0 ;
if ( V_81 )
return 0 ;
if ( F_26 ( F_27 ( V_82 , 0 , & V_36 ) ) )
return - V_42 ;
V_70 = F_9 ( V_36 , & V_52 ) ;
if ( V_70 || ! V_52 )
return V_70 ;
F_16 (platform_timer) {
if ( F_3 ( V_1 ) ) {
V_70 = F_18 ( V_1 , V_80 ) ;
if ( V_70 )
break;
V_80 ++ ;
}
}
if ( V_80 )
F_17 ( L_16 , V_80 ) ;
return V_70 ;
}
