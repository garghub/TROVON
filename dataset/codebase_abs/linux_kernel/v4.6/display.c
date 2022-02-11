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
int F_6 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
int V_26 ;
if ( V_2 -> V_27 -> V_28 ) {
V_26 = F_7 ( V_2 -> V_27 -> V_28 , L_1 ) ;
if ( V_26 < 0 )
V_26 = V_29 ++ ;
} else {
V_26 = V_29 ++ ;
}
snprintf ( V_2 -> V_30 , sizeof( V_2 -> V_30 ) , L_2 , V_26 ) ;
if ( V_2 -> V_27 -> V_28 )
F_8 ( V_2 -> V_27 -> V_28 , L_3 ,
& V_2 -> V_31 ) ;
if ( V_2 -> V_31 == NULL )
V_2 -> V_31 = V_2 -> V_30 ;
if ( V_24 && V_24 -> V_32 == NULL )
V_24 -> V_32 = F_1 ;
if ( V_24 && V_24 -> V_33 == NULL )
V_24 -> V_33 = F_2 ;
if ( V_24 && V_24 -> V_34 == NULL )
V_24 -> V_34 = F_5 ;
F_9 ( & V_35 ) ;
F_10 ( & V_2 -> V_36 , & V_36 ) ;
F_11 ( & V_35 ) ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_9 ( & V_35 ) ;
F_13 ( & V_2 -> V_36 ) ;
F_11 ( & V_35 ) ;
}
struct V_1 * F_14 ( struct V_1 * V_2 )
{
if ( ! F_15 ( V_2 -> V_37 ) )
return NULL ;
if ( F_16 ( V_2 -> V_27 ) == NULL ) {
F_17 ( V_2 -> V_37 ) ;
return NULL ;
}
return V_2 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 -> V_27 ) ;
F_17 ( V_2 -> V_37 ) ;
}
struct V_1 * F_20 ( struct V_1 * V_38 )
{
struct V_39 * V_40 ;
struct V_1 * V_2 ;
F_9 ( & V_35 ) ;
if ( F_21 ( & V_36 ) ) {
V_2 = NULL ;
goto V_41;
}
if ( V_38 == NULL ) {
V_2 = F_22 ( & V_36 , struct V_1 ,
V_36 ) ;
F_14 ( V_2 ) ;
goto V_41;
}
F_18 ( V_38 ) ;
F_23 (l, &panel_list) {
V_2 = F_24 ( V_40 , struct V_1 , V_36 ) ;
if ( V_2 == V_38 ) {
if ( F_25 ( V_40 , & V_36 ) ) {
V_2 = NULL ;
goto V_41;
}
V_2 = F_24 ( V_40 -> V_42 , struct V_1 ,
V_36 ) ;
F_14 ( V_2 ) ;
goto V_41;
}
}
F_26 ( 1 , L_4 ) ;
V_2 = NULL ;
V_41:
F_11 ( & V_35 ) ;
return V_2 ;
}
struct V_1 * F_27 ( void * V_43 ,
int (* F_28)( struct V_1 * V_2 , void * V_43 ) )
{
struct V_1 * V_2 = NULL ;
while ( ( V_2 = F_20 ( V_2 ) ) != NULL ) {
if ( F_28 ( V_2 , V_43 ) )
return V_2 ;
}
return NULL ;
}
void F_29 ( const struct V_44 * V_45 ,
struct V_22 * V_46 )
{
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
V_46 -> V_47 = V_45 -> V_47 ;
V_46 -> V_7 = V_45 -> V_48 ;
V_46 -> V_49 = V_45 -> V_50 ;
V_46 -> V_51 = V_45 -> V_52 ;
V_46 -> V_53 = V_45 -> V_54 ;
V_46 -> V_8 = V_45 -> V_55 ;
V_46 -> V_56 = V_45 -> V_57 ;
V_46 -> V_58 = V_45 -> V_59 ;
V_46 -> V_60 = V_45 -> V_61 ;
V_46 -> V_62 = V_45 -> V_63 & V_64 ?
V_65 :
V_66 ;
V_46 -> V_67 = V_45 -> V_63 & V_68 ?
V_65 :
V_66 ;
V_46 -> V_69 = V_45 -> V_63 & V_70 ?
V_65 :
V_66 ;
V_46 -> V_71 = V_45 -> V_63 & V_72 ?
V_73 :
V_74 ;
V_46 -> V_75 = V_46 -> V_71 ;
}
void F_30 ( const struct V_22 * V_46 ,
struct V_44 * V_45 )
{
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_47 = V_46 -> V_47 ;
V_45 -> V_48 = V_46 -> V_7 ;
V_45 -> V_50 = V_46 -> V_49 ;
V_45 -> V_52 = V_46 -> V_51 ;
V_45 -> V_54 = V_46 -> V_53 ;
V_45 -> V_55 = V_46 -> V_8 ;
V_45 -> V_57 = V_46 -> V_56 ;
V_45 -> V_59 = V_46 -> V_58 ;
V_45 -> V_61 = V_46 -> V_60 ;
if ( V_46 -> V_67 == V_65 )
V_45 -> V_63 |= V_68 ;
else
V_45 -> V_63 |= V_76 ;
if ( V_46 -> V_62 == V_65 )
V_45 -> V_63 |= V_64 ;
else
V_45 -> V_63 |= V_77 ;
if ( V_46 -> V_69 == V_65 )
V_45 -> V_63 |= V_70 ;
else
V_45 -> V_63 |= V_78 ;
if ( V_46 -> V_71 == V_73 )
V_45 -> V_63 |= V_72 ;
else
V_45 -> V_63 |= V_79 ;
}
