static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_5 * V_7 ;
#if F_2 ( V_8 )
struct V_9 * V_10 ;
struct V_9 * V_11 ;
#endif
V_4 = F_3 ( V_2 , struct V_3 , V_12 ) ;
if ( V_4 -> type == V_13 ) {
F_4 (iter4, tmp4,
&ptr->type_def.addrsel->list4) {
F_5 ( V_6 ) ;
F_6 ( F_7 ( V_6 ) ) ;
}
#if F_2 ( V_8 )
F_8 (iter6, tmp6,
&ptr->type_def.addrsel->list6) {
F_9 ( V_10 ) ;
F_6 ( F_10 ( V_10 ) ) ;
}
#endif
}
F_6 ( V_4 -> V_14 ) ;
F_6 ( V_4 ) ;
}
static T_1 F_11 ( const char * V_15 )
{
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
for ( V_16 = 0 , V_17 = 0 , V_18 = strlen ( V_15 ) ; V_16 < V_18 ; V_16 ++ )
V_17 = ( V_17 << 4 | ( V_17 >> ( 8 * sizeof( T_1 ) - 4 ) ) ) ^ V_15 [ V_16 ] ;
return V_17 & ( F_12 ( V_19 ) -> V_20 - 1 ) ;
}
static struct V_3 * F_13 ( const char * V_14 )
{
T_1 V_21 ;
struct V_22 * V_23 ;
struct V_3 * V_16 ;
if ( V_14 != NULL ) {
V_21 = F_11 ( V_14 ) ;
V_23 = & F_12 ( V_19 ) -> V_24 [ V_21 ] ;
F_14 (iter, bkt_list, list)
if ( V_16 -> V_25 && strcmp ( V_16 -> V_14 , V_14 ) == 0 )
return V_16 ;
}
return NULL ;
}
static struct V_3 * F_15 ( const char * V_14 )
{
struct V_3 * V_2 ;
V_2 = F_13 ( V_14 ) ;
if ( V_2 == NULL ) {
V_2 = F_12 ( V_26 ) ;
if ( V_2 != NULL && ! V_2 -> V_25 )
V_2 = NULL ;
}
return V_2 ;
}
static void F_16 ( struct V_3 * V_2 ,
struct V_5 * V_27 ,
struct V_9 * V_28 ,
int V_29 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_34 * V_35 = NULL ;
T_1 type ;
V_33 = F_17 ( V_36 , V_31 ) ;
if ( V_33 != NULL ) {
F_18 ( V_33 , L_1 ,
V_2 -> V_14 ? V_2 -> V_14 : L_2 ) ;
if ( V_27 != NULL ) {
struct V_37 * V_38 ;
V_38 = F_7 ( V_27 ) ;
type = V_38 -> type ;
V_35 = V_38 -> V_39 . V_35 ;
F_19 ( V_33 , 0 , NULL ,
V_27 -> V_40 , V_27 -> V_41 ) ;
#if F_2 ( V_8 )
} else if ( V_28 != NULL ) {
struct V_42 * V_43 ;
V_43 = F_10 ( V_28 ) ;
type = V_43 -> type ;
F_20 ( V_33 , 0 , NULL ,
& V_28 -> V_40 , & V_28 -> V_41 ) ;
#endif
} else {
type = V_2 -> type ;
V_35 = V_2 -> V_39 . V_35 ;
}
switch ( type ) {
case V_44 :
F_18 ( V_33 , L_3 ) ;
break;
case V_45 :
F_21 ( V_35 == NULL ) ;
F_18 ( V_33 ,
L_4 ,
V_35 -> V_46 ) ;
break;
}
F_18 ( V_33 , L_5 , V_29 == 0 ? 1 : 0 ) ;
F_22 ( V_33 ) ;
}
}
static int F_23 ( const struct V_3 * V_2 )
{
struct V_5 * V_6 ;
struct V_37 * V_38 ;
#if F_2 ( V_8 )
struct V_9 * V_10 ;
struct V_42 * V_43 ;
#endif
if ( V_2 == NULL )
return - V_47 ;
switch ( V_2 -> type ) {
case V_44 :
if ( V_2 -> V_39 . V_35 != NULL ||
V_2 -> V_39 . V_48 != NULL )
return - V_47 ;
break;
case V_45 :
if ( V_2 -> V_39 . V_35 == NULL )
return - V_47 ;
break;
case V_13 :
F_24 (iter4, &entry->type_def.addrsel->list4) {
V_38 = F_7 ( V_6 ) ;
switch ( V_38 -> type ) {
case V_44 :
if ( V_38 -> V_39 . V_35 != NULL )
return - V_47 ;
break;
case V_45 :
if ( V_38 -> V_39 . V_35 == NULL )
return - V_47 ;
break;
default:
return - V_47 ;
}
}
#if F_2 ( V_8 )
F_25 (iter6, &entry->type_def.addrsel->list6) {
V_43 = F_10 ( V_10 ) ;
switch ( V_43 -> type ) {
case V_44 :
break;
default:
return - V_47 ;
}
}
#endif
break;
default:
return - V_47 ;
}
return 0 ;
}
int T_2 F_26 ( T_1 V_20 )
{
T_1 V_16 ;
struct V_49 * V_50 ;
if ( V_20 == 0 )
return - V_47 ;
V_50 = F_27 ( sizeof( * V_50 ) , V_51 ) ;
if ( V_50 == NULL )
return - V_52 ;
V_50 -> V_20 = 1 << V_20 ;
V_50 -> V_24 = F_28 ( V_50 -> V_20 ,
sizeof( struct V_22 ) ,
V_51 ) ;
if ( V_50 -> V_24 == NULL ) {
F_6 ( V_50 ) ;
return - V_52 ;
}
for ( V_16 = 0 ; V_16 < V_50 -> V_20 ; V_16 ++ )
F_29 ( & V_50 -> V_24 [ V_16 ] ) ;
F_30 ( & V_53 ) ;
F_31 ( V_19 , V_50 ) ;
F_32 ( & V_53 ) ;
return 0 ;
}
int F_33 ( struct V_3 * V_2 ,
struct V_30 * V_31 )
{
int V_54 = 0 ;
struct V_3 * V_55 ;
struct V_5 * V_6 ;
struct V_5 * V_7 ;
#if F_2 ( V_8 )
struct V_9 * V_10 ;
struct V_9 * V_11 ;
#endif
V_54 = F_23 ( V_2 ) ;
if ( V_54 != 0 )
return V_54 ;
F_34 () ;
F_30 ( & V_53 ) ;
if ( V_2 -> V_14 != NULL )
V_55 = F_13 ( V_2 -> V_14 ) ;
else
V_55 = F_15 ( V_2 -> V_14 ) ;
if ( V_55 == NULL ) {
V_2 -> V_25 = 1 ;
if ( V_2 -> V_14 != NULL ) {
T_1 V_21 = F_11 ( V_2 -> V_14 ) ;
F_35 ( & V_2 -> V_56 ,
& F_36 ( V_19 ) -> V_24 [ V_21 ] ) ;
} else {
F_29 ( & V_2 -> V_56 ) ;
F_31 ( V_26 , V_2 ) ;
}
if ( V_2 -> type == V_13 ) {
F_37 (iter4,
&entry->type_def.addrsel->list4)
F_16 ( V_2 , V_6 , NULL ,
V_54 , V_31 ) ;
#if F_2 ( V_8 )
F_38 (iter6,
&entry->type_def.addrsel->list6)
F_16 ( V_2 , NULL , V_10 ,
V_54 , V_31 ) ;
#endif
} else
F_16 ( V_2 , NULL , NULL ,
V_54 , V_31 ) ;
} else if ( V_55 -> type == V_13 &&
V_2 -> type == V_13 ) {
struct V_22 * V_57 ;
struct V_22 * V_58 ;
V_57 = & V_55 -> V_39 . V_48 -> V_59 ;
V_58 = & V_55 -> V_39 . V_48 -> V_60 ;
F_37 (iter4,
&entry->type_def.addrsel->list4)
if ( F_39 ( V_6 -> V_40 ,
V_6 -> V_41 ,
V_57 ) ) {
V_54 = - V_61 ;
goto V_62;
}
#if F_2 ( V_8 )
F_38 (iter6,
&entry->type_def.addrsel->list6)
if ( F_40 ( & V_10 -> V_40 ,
& V_10 -> V_41 ,
V_58 ) ) {
V_54 = - V_61 ;
goto V_62;
}
#endif
F_4 (iter4, tmp4,
&entry->type_def.addrsel->list4) {
F_5 ( V_6 ) ;
V_6 -> V_25 = 1 ;
V_54 = F_41 ( V_6 , V_57 ) ;
F_16 ( V_55 , V_6 , NULL ,
V_54 , V_31 ) ;
if ( V_54 != 0 )
goto V_62;
}
#if F_2 ( V_8 )
F_8 (iter6, tmp6,
&entry->type_def.addrsel->list6) {
F_9 ( V_10 ) ;
V_10 -> V_25 = 1 ;
V_54 = F_42 ( V_10 , V_58 ) ;
F_16 ( V_55 , NULL , V_10 ,
V_54 , V_31 ) ;
if ( V_54 != 0 )
goto V_62;
}
#endif
} else
V_54 = - V_47 ;
V_62:
F_32 ( & V_53 ) ;
F_43 () ;
return V_54 ;
}
int F_44 ( struct V_3 * V_2 ,
struct V_30 * V_31 )
{
return F_33 ( V_2 , V_31 ) ;
}
int F_45 ( struct V_3 * V_2 ,
struct V_30 * V_31 )
{
int V_54 = 0 ;
struct V_32 * V_33 ;
if ( V_2 == NULL )
return - V_63 ;
F_30 ( & V_53 ) ;
if ( V_2 -> V_25 ) {
V_2 -> V_25 = 0 ;
if ( V_2 != F_36 ( V_26 ) )
F_46 ( & V_2 -> V_56 ) ;
else
F_47 ( V_26 , NULL ) ;
} else
V_54 = - V_63 ;
F_32 ( & V_53 ) ;
V_33 = F_17 ( V_64 , V_31 ) ;
if ( V_33 != NULL ) {
F_18 ( V_33 ,
L_6 ,
V_2 -> V_14 ? V_2 -> V_14 : L_2 ,
V_54 == 0 ? 1 : 0 ) ;
F_22 ( V_33 ) ;
}
if ( V_54 == 0 ) {
struct V_5 * V_6 ;
struct V_37 * V_38 ;
switch ( V_2 -> type ) {
case V_13 :
F_37 (iter4,
&entry->type_def.addrsel->list4) {
V_38 = F_7 ( V_6 ) ;
F_48 ( V_38 -> V_39 . V_35 ) ;
}
break;
case V_45 :
F_48 ( V_2 -> V_39 . V_35 ) ;
break;
}
F_49 ( & V_2 -> V_12 , F_1 ) ;
}
return V_54 ;
}
int F_50 ( const char * V_14 ,
const struct V_65 * V_40 ,
const struct V_65 * V_41 ,
struct V_30 * V_31 )
{
struct V_3 * V_66 ;
struct V_5 * V_67 ;
struct V_5 * V_6 ;
#if F_2 ( V_8 )
struct V_9 * V_10 ;
#endif
struct V_37 * V_2 ;
F_34 () ;
if ( V_14 )
V_66 = F_13 ( V_14 ) ;
else
V_66 = F_15 ( V_14 ) ;
if ( V_66 == NULL || V_66 -> type != V_13 )
goto V_68;
F_30 ( & V_53 ) ;
V_67 = F_51 ( V_40 -> V_69 , V_41 -> V_69 ,
& V_66 -> V_39 . V_48 -> V_59 ) ;
F_32 ( & V_53 ) ;
if ( V_67 == NULL )
goto V_68;
F_37 (iter4, &entry_map->type_def.addrsel->list4)
goto V_70;
#if F_2 ( V_8 )
F_38 (iter6, &entry_map->type_def.addrsel->list6)
goto V_70;
#endif
F_45 ( V_66 , V_31 ) ;
V_70:
F_43 () ;
F_52 () ;
V_2 = F_7 ( V_67 ) ;
F_48 ( V_2 -> V_39 . V_35 ) ;
F_6 ( V_2 ) ;
return 0 ;
V_68:
F_43 () ;
return - V_63 ;
}
int F_53 ( const char * V_14 , struct V_30 * V_31 )
{
int V_54 ;
struct V_3 * V_2 ;
F_34 () ;
if ( V_14 )
V_2 = F_13 ( V_14 ) ;
else
V_2 = F_15 ( V_14 ) ;
V_54 = F_45 ( V_2 , V_31 ) ;
F_43 () ;
return V_54 ;
}
int F_54 ( struct V_30 * V_31 )
{
return F_53 ( NULL , V_31 ) ;
}
struct V_3 * F_55 ( const char * V_14 )
{
return F_15 ( V_14 ) ;
}
struct V_37 * F_56 ( const char * V_14 ,
T_3 V_40 )
{
struct V_3 * V_71 ;
struct V_5 * V_72 ;
V_71 = F_15 ( V_14 ) ;
if ( V_71 == NULL )
return NULL ;
if ( V_71 -> type != V_13 )
return NULL ;
V_72 = F_57 ( V_40 ,
& V_71 -> V_39 . V_48 -> V_59 ) ;
if ( V_72 == NULL )
return NULL ;
return F_7 ( V_72 ) ;
}
struct V_42 * F_58 ( const char * V_14 ,
const struct V_73 * V_40 )
{
struct V_3 * V_71 ;
struct V_9 * V_72 ;
V_71 = F_15 ( V_14 ) ;
if ( V_71 == NULL )
return NULL ;
if ( V_71 -> type != V_13 )
return NULL ;
V_72 = F_59 ( V_40 ,
& V_71 -> V_39 . V_48 -> V_60 ) ;
if ( V_72 == NULL )
return NULL ;
return F_10 ( V_72 ) ;
}
int F_60 ( T_1 * V_74 ,
T_1 * V_75 ,
int (* F_61) ( struct V_3 * V_2 , void * V_76 ) ,
void * V_77 )
{
int V_54 = - V_63 ;
T_1 V_78 ;
struct V_22 * V_79 ;
struct V_3 * V_80 ;
T_1 V_81 = 0 ;
F_34 () ;
for ( V_78 = * V_74 ;
V_78 < F_36 ( V_19 ) -> V_20 ;
V_78 ++ , V_81 = 0 ) {
V_79 = & F_36 ( V_19 ) -> V_24 [ V_78 ] ;
F_14 (iter_entry, iter_list, list)
if ( V_80 -> V_25 ) {
if ( V_81 ++ < * V_75 )
continue;
V_54 = F_61 ( V_80 , V_77 ) ;
if ( V_54 < 0 ) {
V_81 -- ;
goto V_82;
}
}
}
V_82:
F_43 () ;
* V_74 = V_78 ;
* V_75 = V_81 ;
return V_54 ;
}
