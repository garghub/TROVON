void F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_1 * V_4 )
{
* V_3 = V_2 -> V_5 . V_6 . V_7 ;
* V_4 = V_2 -> V_5 . V_6 . V_8 ;
}
int F_2 ( struct V_1 * V_2 )
{
switch ( V_2 -> type ) {
case V_9 :
if ( V_2 -> V_10 . V_11 . V_12 == 24 )
return 24 ;
else
return 16 ;
case V_13 :
if ( V_2 -> V_14 . V_15 == 24 )
return 24 ;
else
return 16 ;
case V_16 :
if ( F_3 ( V_2 -> V_5 . V_17 ) > 16 )
return 24 ;
else
return 16 ;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return 24 ;
default:
F_4 () ;
return 0 ;
}
}
void F_5 ( struct V_1 * V_2 ,
struct V_22 * V_6 )
{
* V_6 = V_2 -> V_5 . V_6 ;
}
int F_6 ( void )
{
struct V_1 * V_2 = NULL ;
F_7 (dssdev) {
if ( ! V_2 -> V_23 )
continue;
if ( V_2 -> V_24 == V_25 ) {
V_2 -> V_23 -> V_26 ( V_2 ) ;
V_2 -> V_27 = true ;
} else {
V_2 -> V_27 = false ;
}
}
return 0 ;
}
int F_8 ( void )
{
struct V_1 * V_2 = NULL ;
F_7 (dssdev) {
if ( ! V_2 -> V_23 )
continue;
if ( V_2 -> V_27 ) {
V_2 -> V_23 -> V_28 ( V_2 ) ;
V_2 -> V_27 = false ;
}
}
return 0 ;
}
void F_9 ( void )
{
struct V_1 * V_2 = NULL ;
F_7 (dssdev) {
if ( ! V_2 -> V_23 )
continue;
if ( V_2 -> V_24 == V_25 )
V_2 -> V_23 -> V_26 ( V_2 ) ;
}
}
int F_10 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_23 ;
int V_31 ;
if ( V_2 -> V_32 -> V_33 ) {
V_31 = F_11 ( V_2 -> V_32 -> V_33 , L_1 ) ;
if ( V_31 < 0 )
V_31 = V_34 ++ ;
} else {
V_31 = V_34 ++ ;
}
snprintf ( V_2 -> V_35 , sizeof( V_2 -> V_35 ) , L_2 , V_31 ) ;
if ( V_2 -> V_32 -> V_33 )
F_12 ( V_2 -> V_32 -> V_33 , L_3 ,
& V_2 -> V_36 ) ;
if ( V_2 -> V_36 == NULL )
V_2 -> V_36 = V_2 -> V_35 ;
if ( V_30 && V_30 -> V_37 == NULL )
V_30 -> V_37 = F_1 ;
if ( V_30 && V_30 -> V_38 == NULL )
V_30 -> V_38 = F_2 ;
if ( V_30 && V_30 -> V_39 == NULL )
V_30 -> V_39 = F_5 ;
F_13 ( & V_40 ) ;
F_14 ( & V_2 -> V_41 , & V_41 ) ;
F_15 ( & V_40 ) ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_13 ( & V_40 ) ;
F_17 ( & V_2 -> V_41 ) ;
F_15 ( & V_40 ) ;
}
struct V_1 * F_18 ( struct V_1 * V_2 )
{
if ( ! F_19 ( V_2 -> V_42 ) )
return NULL ;
if ( F_20 ( V_2 -> V_32 ) == NULL ) {
F_21 ( V_2 -> V_42 ) ;
return NULL ;
}
return V_2 ;
}
void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 -> V_32 ) ;
F_21 ( V_2 -> V_42 ) ;
}
struct V_1 * F_24 ( struct V_1 * V_43 )
{
struct V_44 * V_45 ;
struct V_1 * V_2 ;
F_13 ( & V_40 ) ;
if ( F_25 ( & V_41 ) ) {
V_2 = NULL ;
goto V_46;
}
if ( V_43 == NULL ) {
V_2 = F_26 ( & V_41 , struct V_1 ,
V_41 ) ;
F_18 ( V_2 ) ;
goto V_46;
}
F_22 ( V_43 ) ;
F_27 (l, &panel_list) {
V_2 = F_28 ( V_45 , struct V_1 , V_41 ) ;
if ( V_2 == V_43 ) {
if ( F_29 ( V_45 , & V_41 ) ) {
V_2 = NULL ;
goto V_46;
}
V_2 = F_28 ( V_45 -> V_47 , struct V_1 ,
V_41 ) ;
F_18 ( V_2 ) ;
goto V_46;
}
}
F_30 ( 1 , L_4 ) ;
V_2 = NULL ;
V_46:
F_15 ( & V_40 ) ;
return V_2 ;
}
struct V_1 * F_31 ( void * V_48 ,
int (* F_32)( struct V_1 * V_2 , void * V_48 ) )
{
struct V_1 * V_2 = NULL ;
while ( ( V_2 = F_24 ( V_2 ) ) != NULL ) {
if ( F_32 ( V_2 , V_48 ) )
return V_2 ;
}
return NULL ;
}
void F_33 ( const struct V_49 * V_50 ,
struct V_22 * V_51 )
{
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
V_51 -> V_52 = V_50 -> V_52 ;
V_51 -> V_7 = V_50 -> V_53 ;
V_51 -> V_54 = V_50 -> V_55 ;
V_51 -> V_56 = V_50 -> V_57 ;
V_51 -> V_58 = V_50 -> V_59 ;
V_51 -> V_8 = V_50 -> V_60 ;
V_51 -> V_61 = V_50 -> V_62 ;
V_51 -> V_63 = V_50 -> V_64 ;
V_51 -> V_65 = V_50 -> V_66 ;
V_51 -> V_67 = V_50 -> V_68 & V_69 ?
V_70 :
V_71 ;
V_51 -> V_72 = V_50 -> V_68 & V_73 ?
V_70 :
V_71 ;
V_51 -> V_74 = V_50 -> V_68 & V_75 ?
V_70 :
V_71 ;
V_51 -> V_76 = V_50 -> V_68 & V_77 ?
V_78 :
V_79 ;
V_51 -> V_80 = V_51 -> V_76 ;
}
void F_34 ( const struct V_22 * V_51 ,
struct V_49 * V_50 )
{
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_52 = V_51 -> V_52 ;
V_50 -> V_53 = V_51 -> V_7 ;
V_50 -> V_55 = V_51 -> V_54 ;
V_50 -> V_57 = V_51 -> V_56 ;
V_50 -> V_59 = V_51 -> V_58 ;
V_50 -> V_60 = V_51 -> V_8 ;
V_50 -> V_62 = V_51 -> V_61 ;
V_50 -> V_64 = V_51 -> V_63 ;
V_50 -> V_66 = V_51 -> V_65 ;
if ( V_51 -> V_72 == V_70 )
V_50 -> V_68 |= V_73 ;
else
V_50 -> V_68 |= V_81 ;
if ( V_51 -> V_67 == V_70 )
V_50 -> V_68 |= V_69 ;
else
V_50 -> V_68 |= V_82 ;
if ( V_51 -> V_74 == V_70 )
V_50 -> V_68 |= V_75 ;
else
V_50 -> V_68 |= V_83 ;
if ( V_51 -> V_76 == V_78 )
V_50 -> V_68 |= V_77 ;
else
V_50 -> V_68 |= V_84 ;
}
