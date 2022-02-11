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
if ( V_4 -> V_13 . type == V_14 ) {
F_4 (iter4, tmp4,
&ptr->def.addrsel->list4) {
F_5 ( V_6 ) ;
F_6 ( F_7 ( V_6 ) ) ;
}
#if F_2 ( V_8 )
F_8 (iter6, tmp6,
&ptr->def.addrsel->list6) {
F_9 ( V_10 ) ;
F_6 ( F_10 ( V_10 ) ) ;
}
#endif
}
F_6 ( V_4 -> V_15 ) ;
F_6 ( V_4 ) ;
}
static T_1 F_11 ( const char * V_16 )
{
T_1 V_17 ;
T_1 V_18 ;
T_1 V_19 ;
for ( V_17 = 0 , V_18 = 0 , V_19 = strlen ( V_16 ) ; V_17 < V_19 ; V_17 ++ )
V_18 = ( V_18 << 4 | ( V_18 >> ( 8 * sizeof( T_1 ) - 4 ) ) ) ^ V_16 [ V_17 ] ;
return V_18 & ( F_12 ( V_20 ) -> V_21 - 1 ) ;
}
static struct V_3 * F_13 ( const char * V_15 )
{
T_1 V_22 ;
struct V_23 * V_24 ;
struct V_3 * V_17 ;
if ( V_15 != NULL ) {
V_22 = F_11 ( V_15 ) ;
V_24 = & F_12 ( V_20 ) -> V_25 [ V_22 ] ;
F_14 (iter, bkt_list, list)
if ( V_17 -> V_26 && strcmp ( V_17 -> V_15 , V_15 ) == 0 )
return V_17 ;
}
return NULL ;
}
static struct V_3 * F_15 ( const char * V_15 )
{
struct V_3 * V_2 ;
V_2 = F_13 ( V_15 ) ;
if ( V_2 == NULL ) {
V_2 = F_12 ( V_27 ) ;
if ( V_2 != NULL && ! V_2 -> V_26 )
V_2 = NULL ;
}
return V_2 ;
}
static void F_16 ( struct V_3 * V_2 ,
struct V_5 * V_28 ,
struct V_9 * V_29 ,
int V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 ;
struct V_35 * V_36 = NULL ;
T_1 type ;
V_34 = F_17 ( V_37 , V_32 ) ;
if ( V_34 != NULL ) {
F_18 ( V_34 , L_1 ,
V_2 -> V_15 ? V_2 -> V_15 : L_2 ) ;
if ( V_28 != NULL ) {
struct V_38 * V_39 ;
V_39 = F_7 ( V_28 ) ;
type = V_39 -> V_13 . type ;
V_36 = V_39 -> V_13 . V_40 ;
F_19 ( V_34 , 0 , NULL ,
V_28 -> V_41 , V_28 -> V_42 ) ;
#if F_2 ( V_8 )
} else if ( V_29 != NULL ) {
struct V_43 * V_44 ;
V_44 = F_10 ( V_29 ) ;
type = V_44 -> V_13 . type ;
F_20 ( V_34 , 0 , NULL ,
& V_29 -> V_41 , & V_29 -> V_42 ) ;
#endif
} else {
type = V_2 -> V_13 . type ;
V_36 = V_2 -> V_13 . V_40 ;
}
switch ( type ) {
case V_45 :
F_18 ( V_34 , L_3 ) ;
break;
case V_46 :
F_21 ( V_36 == NULL ) ;
F_18 ( V_34 ,
L_4 ,
V_36 -> V_47 ) ;
break;
}
F_18 ( V_34 , L_5 , V_30 == 0 ? 1 : 0 ) ;
F_22 ( V_34 ) ;
}
}
static int F_23 ( const struct V_3 * V_2 )
{
struct V_5 * V_6 ;
struct V_38 * V_39 ;
#if F_2 ( V_8 )
struct V_9 * V_10 ;
struct V_43 * V_44 ;
#endif
if ( V_2 == NULL )
return - V_48 ;
switch ( V_2 -> V_13 . type ) {
case V_45 :
if ( V_2 -> V_13 . V_40 != NULL || V_2 -> V_13 . V_49 != NULL )
return - V_48 ;
break;
case V_46 :
if ( V_2 -> V_13 . V_40 == NULL )
return - V_48 ;
break;
case V_14 :
F_24 (iter4, &entry->def.addrsel->list4) {
V_39 = F_7 ( V_6 ) ;
switch ( V_39 -> V_13 . type ) {
case V_45 :
if ( V_39 -> V_13 . V_40 != NULL )
return - V_48 ;
break;
case V_46 :
if ( V_39 -> V_13 . V_40 == NULL )
return - V_48 ;
break;
default:
return - V_48 ;
}
}
#if F_2 ( V_8 )
F_25 (iter6, &entry->def.addrsel->list6) {
V_44 = F_10 ( V_10 ) ;
switch ( V_44 -> V_13 . type ) {
case V_45 :
break;
default:
return - V_48 ;
}
}
#endif
break;
default:
return - V_48 ;
}
return 0 ;
}
int T_2 F_26 ( T_1 V_21 )
{
T_1 V_17 ;
struct V_50 * V_51 ;
if ( V_21 == 0 )
return - V_48 ;
V_51 = F_27 ( sizeof( * V_51 ) , V_52 ) ;
if ( V_51 == NULL )
return - V_53 ;
V_51 -> V_21 = 1 << V_21 ;
V_51 -> V_25 = F_28 ( V_51 -> V_21 ,
sizeof( struct V_23 ) ,
V_52 ) ;
if ( V_51 -> V_25 == NULL ) {
F_6 ( V_51 ) ;
return - V_53 ;
}
for ( V_17 = 0 ; V_17 < V_51 -> V_21 ; V_17 ++ )
F_29 ( & V_51 -> V_25 [ V_17 ] ) ;
F_30 ( & V_54 ) ;
F_31 ( V_20 , V_51 ) ;
F_32 ( & V_54 ) ;
return 0 ;
}
int F_33 ( struct V_3 * V_2 ,
struct V_31 * V_32 )
{
int V_55 = 0 ;
struct V_3 * V_56 ;
struct V_5 * V_6 ;
struct V_5 * V_7 ;
#if F_2 ( V_8 )
struct V_9 * V_10 ;
struct V_9 * V_11 ;
#endif
V_55 = F_23 ( V_2 ) ;
if ( V_55 != 0 )
return V_55 ;
F_34 () ;
F_30 ( & V_54 ) ;
if ( V_2 -> V_15 != NULL )
V_56 = F_13 ( V_2 -> V_15 ) ;
else
V_56 = F_15 ( V_2 -> V_15 ) ;
if ( V_56 == NULL ) {
V_2 -> V_26 = 1 ;
if ( V_2 -> V_15 != NULL ) {
T_1 V_22 = F_11 ( V_2 -> V_15 ) ;
F_35 ( & V_2 -> V_57 ,
& F_36 ( V_20 ) -> V_25 [ V_22 ] ) ;
} else {
F_29 ( & V_2 -> V_57 ) ;
F_31 ( V_27 , V_2 ) ;
}
if ( V_2 -> V_13 . type == V_14 ) {
F_37 (iter4,
&entry->def.addrsel->list4)
F_16 ( V_2 , V_6 , NULL ,
V_55 , V_32 ) ;
#if F_2 ( V_8 )
F_38 (iter6,
&entry->def.addrsel->list6)
F_16 ( V_2 , NULL , V_10 ,
V_55 , V_32 ) ;
#endif
} else
F_16 ( V_2 , NULL , NULL ,
V_55 , V_32 ) ;
} else if ( V_56 -> V_13 . type == V_14 &&
V_2 -> V_13 . type == V_14 ) {
struct V_23 * V_58 ;
struct V_23 * V_59 ;
V_58 = & V_56 -> V_13 . V_49 -> V_60 ;
V_59 = & V_56 -> V_13 . V_49 -> V_61 ;
F_37 (iter4, &entry->def.addrsel->list4)
if ( F_39 ( V_6 -> V_41 ,
V_6 -> V_42 ,
V_58 ) ) {
V_55 = - V_62 ;
goto V_63;
}
#if F_2 ( V_8 )
F_38 (iter6, &entry->def.addrsel->list6)
if ( F_40 ( & V_10 -> V_41 ,
& V_10 -> V_42 ,
V_59 ) ) {
V_55 = - V_62 ;
goto V_63;
}
#endif
F_4 (iter4, tmp4,
&entry->def.addrsel->list4) {
F_5 ( V_6 ) ;
V_6 -> V_26 = 1 ;
V_55 = F_41 ( V_6 , V_58 ) ;
F_16 ( V_56 , V_6 , NULL ,
V_55 , V_32 ) ;
if ( V_55 != 0 )
goto V_63;
}
#if F_2 ( V_8 )
F_8 (iter6, tmp6,
&entry->def.addrsel->list6) {
F_9 ( V_10 ) ;
V_10 -> V_26 = 1 ;
V_55 = F_42 ( V_10 , V_59 ) ;
F_16 ( V_56 , NULL , V_10 ,
V_55 , V_32 ) ;
if ( V_55 != 0 )
goto V_63;
}
#endif
} else
V_55 = - V_48 ;
V_63:
F_32 ( & V_54 ) ;
F_43 () ;
return V_55 ;
}
int F_44 ( struct V_3 * V_2 ,
struct V_31 * V_32 )
{
return F_33 ( V_2 , V_32 ) ;
}
int F_45 ( struct V_3 * V_2 ,
struct V_31 * V_32 )
{
int V_55 = 0 ;
struct V_33 * V_34 ;
if ( V_2 == NULL )
return - V_64 ;
F_30 ( & V_54 ) ;
if ( V_2 -> V_26 ) {
V_2 -> V_26 = 0 ;
if ( V_2 != F_36 ( V_27 ) )
F_46 ( & V_2 -> V_57 ) ;
else
F_47 ( V_27 , NULL ) ;
} else
V_55 = - V_64 ;
F_32 ( & V_54 ) ;
V_34 = F_17 ( V_65 , V_32 ) ;
if ( V_34 != NULL ) {
F_18 ( V_34 ,
L_6 ,
V_2 -> V_15 ? V_2 -> V_15 : L_2 ,
V_55 == 0 ? 1 : 0 ) ;
F_22 ( V_34 ) ;
}
if ( V_55 == 0 ) {
struct V_5 * V_6 ;
struct V_38 * V_39 ;
switch ( V_2 -> V_13 . type ) {
case V_14 :
F_37 (iter4,
&entry->def.addrsel->list4) {
V_39 = F_7 ( V_6 ) ;
F_48 ( V_39 -> V_13 . V_40 ) ;
}
break;
case V_46 :
F_48 ( V_2 -> V_13 . V_40 ) ;
break;
}
F_49 ( & V_2 -> V_12 , F_1 ) ;
}
return V_55 ;
}
int F_50 ( const char * V_15 ,
const struct V_66 * V_41 ,
const struct V_66 * V_42 ,
struct V_31 * V_32 )
{
struct V_3 * V_67 ;
struct V_5 * V_68 ;
struct V_5 * V_6 ;
#if F_2 ( V_8 )
struct V_9 * V_10 ;
#endif
struct V_38 * V_2 ;
F_34 () ;
if ( V_15 )
V_67 = F_13 ( V_15 ) ;
else
V_67 = F_15 ( V_15 ) ;
if ( V_67 == NULL ||
V_67 -> V_13 . type != V_14 )
goto V_69;
F_30 ( & V_54 ) ;
V_68 = F_51 ( V_41 -> V_70 , V_42 -> V_70 ,
& V_67 -> V_13 . V_49 -> V_60 ) ;
F_32 ( & V_54 ) ;
if ( V_68 == NULL )
goto V_69;
F_37 (iter4, &entry_map->def.addrsel->list4)
goto V_71;
#if F_2 ( V_8 )
F_38 (iter6, &entry_map->def.addrsel->list6)
goto V_71;
#endif
F_45 ( V_67 , V_32 ) ;
V_71:
F_43 () ;
F_52 () ;
V_2 = F_7 ( V_68 ) ;
F_48 ( V_2 -> V_13 . V_40 ) ;
F_6 ( V_2 ) ;
return 0 ;
V_69:
F_43 () ;
return - V_64 ;
}
int F_53 ( const char * V_15 , struct V_31 * V_32 )
{
int V_55 ;
struct V_3 * V_2 ;
F_34 () ;
if ( V_15 )
V_2 = F_13 ( V_15 ) ;
else
V_2 = F_15 ( V_15 ) ;
V_55 = F_45 ( V_2 , V_32 ) ;
F_43 () ;
return V_55 ;
}
int F_54 ( struct V_31 * V_32 )
{
return F_53 ( NULL , V_32 ) ;
}
struct V_3 * F_55 ( const char * V_15 )
{
return F_15 ( V_15 ) ;
}
struct V_72 * F_56 ( const char * V_15 ,
T_3 V_41 )
{
struct V_3 * V_73 ;
struct V_5 * V_74 ;
V_73 = F_15 ( V_15 ) ;
if ( V_73 == NULL )
return NULL ;
if ( V_73 -> V_13 . type != V_14 )
return & V_73 -> V_13 ;
V_74 = F_57 ( V_41 , & V_73 -> V_13 . V_49 -> V_60 ) ;
if ( V_74 == NULL )
return NULL ;
return & ( F_7 ( V_74 ) -> V_13 ) ;
}
struct V_72 * F_58 ( const char * V_15 ,
const struct V_75 * V_41 )
{
struct V_3 * V_73 ;
struct V_9 * V_74 ;
V_73 = F_15 ( V_15 ) ;
if ( V_73 == NULL )
return NULL ;
if ( V_73 -> V_13 . type != V_14 )
return & V_73 -> V_13 ;
V_74 = F_59 ( V_41 , & V_73 -> V_13 . V_49 -> V_61 ) ;
if ( V_74 == NULL )
return NULL ;
return & ( F_10 ( V_74 ) -> V_13 ) ;
}
int F_60 ( T_1 * V_76 ,
T_1 * V_77 ,
int (* F_61) ( struct V_3 * V_2 , void * V_78 ) ,
void * V_79 )
{
int V_55 = - V_64 ;
T_1 V_80 ;
struct V_23 * V_81 ;
struct V_3 * V_82 ;
T_1 V_83 = 0 ;
F_34 () ;
for ( V_80 = * V_76 ;
V_80 < F_36 ( V_20 ) -> V_21 ;
V_80 ++ , V_83 = 0 ) {
V_81 = & F_36 ( V_20 ) -> V_25 [ V_80 ] ;
F_14 (iter_entry, iter_list, list)
if ( V_82 -> V_26 ) {
if ( V_83 ++ < * V_77 )
continue;
V_55 = F_61 ( V_82 , V_79 ) ;
if ( V_55 < 0 ) {
V_83 -- ;
goto V_84;
}
}
}
V_84:
F_43 () ;
* V_76 = V_80 ;
* V_77 = V_83 ;
return V_55 ;
}
