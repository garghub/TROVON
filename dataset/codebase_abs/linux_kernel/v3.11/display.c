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
snprintf ( V_2 -> V_31 , sizeof( V_2 -> V_31 ) ,
L_1 , V_32 ++ ) ;
if ( V_30 && V_30 -> V_33 == NULL )
V_30 -> V_33 = F_1 ;
if ( V_30 && V_30 -> V_34 == NULL )
V_30 -> V_34 = F_2 ;
if ( V_30 && V_30 -> V_35 == NULL )
V_30 -> V_35 = F_5 ;
F_11 ( & V_36 ) ;
F_12 ( & V_2 -> V_37 , & V_37 ) ;
F_13 ( & V_36 ) ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
F_11 ( & V_36 ) ;
F_15 ( & V_2 -> V_37 ) ;
F_13 ( & V_36 ) ;
}
struct V_1 * F_16 ( struct V_1 * V_2 )
{
if ( ! F_17 ( V_2 -> V_38 ) )
return NULL ;
if ( F_18 ( V_2 -> V_39 ) == NULL ) {
F_19 ( V_2 -> V_38 ) ;
return NULL ;
}
return V_2 ;
}
void F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_39 ) ;
F_19 ( V_2 -> V_38 ) ;
}
struct V_1 * F_22 ( struct V_1 * V_40 )
{
struct V_41 * V_42 ;
struct V_1 * V_2 ;
F_11 ( & V_36 ) ;
if ( F_23 ( & V_37 ) ) {
V_2 = NULL ;
goto V_43;
}
if ( V_40 == NULL ) {
V_2 = F_24 ( & V_37 , struct V_1 ,
V_37 ) ;
F_16 ( V_2 ) ;
goto V_43;
}
F_20 ( V_40 ) ;
F_25 (l, &panel_list) {
V_2 = F_26 ( V_42 , struct V_1 , V_37 ) ;
if ( V_2 == V_40 ) {
if ( F_27 ( V_42 , & V_37 ) ) {
V_2 = NULL ;
goto V_43;
}
V_2 = F_26 ( V_42 -> V_44 , struct V_1 ,
V_37 ) ;
F_16 ( V_2 ) ;
goto V_43;
}
}
F_28 ( 1 , L_2 ) ;
V_2 = NULL ;
V_43:
F_13 ( & V_36 ) ;
return V_2 ;
}
struct V_1 * F_29 ( void * V_45 ,
int (* F_30)( struct V_1 * V_2 , void * V_45 ) )
{
struct V_1 * V_2 = NULL ;
while ( ( V_2 = F_22 ( V_2 ) ) != NULL ) {
if ( F_30 ( V_2 , V_45 ) )
return V_2 ;
}
return NULL ;
}
void F_31 ( const struct V_46 * V_47 ,
struct V_22 * V_48 )
{
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_49 = V_47 -> V_50 / 1000 ;
V_48 -> V_7 = V_47 -> V_51 ;
V_48 -> V_52 = V_47 -> V_53 ;
V_48 -> V_54 = V_47 -> V_55 ;
V_48 -> V_56 = V_47 -> V_57 ;
V_48 -> V_8 = V_47 -> V_58 ;
V_48 -> V_59 = V_47 -> V_60 ;
V_48 -> V_61 = V_47 -> V_62 ;
V_48 -> V_63 = V_47 -> V_64 ;
V_48 -> V_65 = V_47 -> V_66 & V_67 ?
V_68 :
V_69 ;
V_48 -> V_70 = V_47 -> V_66 & V_71 ?
V_68 :
V_69 ;
V_48 -> V_72 = V_47 -> V_66 & V_73 ?
V_68 :
V_68 ;
V_48 -> V_74 = V_47 -> V_66 & V_75 ?
V_76 :
V_77 ;
V_48 -> V_78 = V_79 ;
}
void F_32 ( const struct V_22 * V_48 ,
struct V_46 * V_47 )
{
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
V_47 -> V_50 = V_48 -> V_49 * 1000 ;
V_47 -> V_51 = V_48 -> V_7 ;
V_47 -> V_53 = V_48 -> V_52 ;
V_47 -> V_55 = V_48 -> V_54 ;
V_47 -> V_57 = V_48 -> V_56 ;
V_47 -> V_58 = V_48 -> V_8 ;
V_47 -> V_60 = V_48 -> V_59 ;
V_47 -> V_62 = V_48 -> V_61 ;
V_47 -> V_64 = V_48 -> V_63 ;
if ( V_48 -> V_70 == V_68 )
V_47 -> V_66 |= V_71 ;
else
V_47 -> V_66 |= V_80 ;
if ( V_48 -> V_65 == V_68 )
V_47 -> V_66 |= V_67 ;
else
V_47 -> V_66 |= V_81 ;
if ( V_48 -> V_72 == V_68 )
V_47 -> V_66 |= V_73 ;
else
V_47 -> V_66 |= V_82 ;
if ( V_48 -> V_74 == V_76 )
V_47 -> V_66 |= V_75 ;
else
V_47 -> V_66 |= V_83 ;
}
