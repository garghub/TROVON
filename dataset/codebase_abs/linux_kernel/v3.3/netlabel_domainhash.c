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
int T_2 F_23 ( T_1 V_20 )
{
T_1 V_16 ;
struct V_47 * V_48 ;
if ( V_20 == 0 )
return - V_49 ;
V_48 = F_24 ( sizeof( * V_48 ) , V_50 ) ;
if ( V_48 == NULL )
return - V_51 ;
V_48 -> V_20 = 1 << V_20 ;
V_48 -> V_24 = F_25 ( V_48 -> V_20 ,
sizeof( struct V_22 ) ,
V_50 ) ;
if ( V_48 -> V_24 == NULL ) {
F_6 ( V_48 ) ;
return - V_51 ;
}
for ( V_16 = 0 ; V_16 < V_48 -> V_20 ; V_16 ++ )
F_26 ( & V_48 -> V_24 [ V_16 ] ) ;
F_27 ( & V_52 ) ;
F_28 ( V_19 , V_48 ) ;
F_29 ( & V_52 ) ;
return 0 ;
}
int F_30 ( struct V_3 * V_2 ,
struct V_30 * V_31 )
{
int V_53 = 0 ;
struct V_3 * V_54 ;
struct V_5 * V_6 ;
struct V_5 * V_7 ;
#if F_2 ( V_8 )
struct V_9 * V_10 ;
struct V_9 * V_11 ;
#endif
F_31 () ;
F_27 ( & V_52 ) ;
if ( V_2 -> V_14 != NULL )
V_54 = F_13 ( V_2 -> V_14 ) ;
else
V_54 = F_15 ( V_2 -> V_14 ) ;
if ( V_54 == NULL ) {
V_2 -> V_25 = 1 ;
if ( V_2 -> V_14 != NULL ) {
T_1 V_21 = F_11 ( V_2 -> V_14 ) ;
F_32 ( & V_2 -> V_55 ,
& F_33 ( V_19 ) -> V_24 [ V_21 ] ) ;
} else {
F_26 ( & V_2 -> V_55 ) ;
F_28 ( V_26 , V_2 ) ;
}
if ( V_2 -> type == V_13 ) {
F_34 (iter4,
&entry->type_def.addrsel->list4)
F_16 ( V_2 , V_6 , NULL ,
V_53 , V_31 ) ;
#if F_2 ( V_8 )
F_35 (iter6,
&entry->type_def.addrsel->list6)
F_16 ( V_2 , NULL , V_10 ,
V_53 , V_31 ) ;
#endif
} else
F_16 ( V_2 , NULL , NULL ,
V_53 , V_31 ) ;
} else if ( V_54 -> type == V_13 &&
V_2 -> type == V_13 ) {
struct V_22 * V_56 ;
struct V_22 * V_57 ;
V_56 = & V_54 -> V_39 . V_58 -> V_59 ;
V_57 = & V_54 -> V_39 . V_58 -> V_60 ;
F_34 (iter4,
&entry->type_def.addrsel->list4)
if ( F_36 ( V_6 -> V_40 ,
V_6 -> V_41 ,
V_56 ) ) {
V_53 = - V_61 ;
goto V_62;
}
#if F_2 ( V_8 )
F_35 (iter6,
&entry->type_def.addrsel->list6)
if ( F_37 ( & V_10 -> V_40 ,
& V_10 -> V_41 ,
V_57 ) ) {
V_53 = - V_61 ;
goto V_62;
}
#endif
F_4 (iter4, tmp4,
&entry->type_def.addrsel->list4) {
F_5 ( V_6 ) ;
V_6 -> V_25 = 1 ;
V_53 = F_38 ( V_6 , V_56 ) ;
F_16 ( V_54 , V_6 , NULL ,
V_53 , V_31 ) ;
if ( V_53 != 0 )
goto V_62;
}
#if F_2 ( V_8 )
F_8 (iter6, tmp6,
&entry->type_def.addrsel->list6) {
F_9 ( V_10 ) ;
V_10 -> V_25 = 1 ;
V_53 = F_39 ( V_10 , V_57 ) ;
F_16 ( V_54 , NULL , V_10 ,
V_53 , V_31 ) ;
if ( V_53 != 0 )
goto V_62;
}
#endif
} else
V_53 = - V_49 ;
V_62:
F_29 ( & V_52 ) ;
F_40 () ;
return V_53 ;
}
int F_41 ( struct V_3 * V_2 ,
struct V_30 * V_31 )
{
return F_30 ( V_2 , V_31 ) ;
}
int F_42 ( struct V_3 * V_2 ,
struct V_30 * V_31 )
{
int V_53 = 0 ;
struct V_32 * V_33 ;
if ( V_2 == NULL )
return - V_63 ;
F_27 ( & V_52 ) ;
if ( V_2 -> V_25 ) {
V_2 -> V_25 = 0 ;
if ( V_2 != F_33 ( V_26 ) )
F_43 ( & V_2 -> V_55 ) ;
else
F_44 ( V_26 , NULL ) ;
} else
V_53 = - V_63 ;
F_29 ( & V_52 ) ;
V_33 = F_17 ( V_64 , V_31 ) ;
if ( V_33 != NULL ) {
F_18 ( V_33 ,
L_6 ,
V_2 -> V_14 ? V_2 -> V_14 : L_2 ,
V_53 == 0 ? 1 : 0 ) ;
F_22 ( V_33 ) ;
}
if ( V_53 == 0 ) {
struct V_5 * V_6 ;
struct V_37 * V_38 ;
switch ( V_2 -> type ) {
case V_13 :
F_34 (iter4,
&entry->type_def.addrsel->list4) {
V_38 = F_7 ( V_6 ) ;
F_45 ( V_38 -> V_39 . V_35 ) ;
}
break;
case V_45 :
F_45 ( V_2 -> V_39 . V_35 ) ;
break;
}
F_46 ( & V_2 -> V_12 , F_1 ) ;
}
return V_53 ;
}
int F_47 ( const char * V_14 ,
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
F_31 () ;
if ( V_14 )
V_66 = F_13 ( V_14 ) ;
else
V_66 = F_15 ( V_14 ) ;
if ( V_66 == NULL || V_66 -> type != V_13 )
goto V_68;
F_27 ( & V_52 ) ;
V_67 = F_48 ( V_40 -> V_69 , V_41 -> V_69 ,
& V_66 -> V_39 . V_58 -> V_59 ) ;
F_29 ( & V_52 ) ;
if ( V_67 == NULL )
goto V_68;
F_34 (iter4, &entry_map->type_def.addrsel->list4)
goto V_70;
#if F_2 ( V_8 )
F_35 (iter6, &entry_map->type_def.addrsel->list6)
goto V_70;
#endif
F_42 ( V_66 , V_31 ) ;
V_70:
F_40 () ;
F_49 () ;
V_2 = F_7 ( V_67 ) ;
F_45 ( V_2 -> V_39 . V_35 ) ;
F_6 ( V_2 ) ;
return 0 ;
V_68:
F_40 () ;
return - V_63 ;
}
int F_50 ( const char * V_14 , struct V_30 * V_31 )
{
int V_53 ;
struct V_3 * V_2 ;
F_31 () ;
if ( V_14 )
V_2 = F_13 ( V_14 ) ;
else
V_2 = F_15 ( V_14 ) ;
V_53 = F_42 ( V_2 , V_31 ) ;
F_40 () ;
return V_53 ;
}
int F_51 ( struct V_30 * V_31 )
{
return F_50 ( NULL , V_31 ) ;
}
struct V_3 * F_52 ( const char * V_14 )
{
return F_15 ( V_14 ) ;
}
struct V_37 * F_53 ( const char * V_14 ,
T_3 V_40 )
{
struct V_3 * V_71 ;
struct V_5 * V_72 ;
V_71 = F_15 ( V_14 ) ;
if ( V_71 == NULL )
return NULL ;
if ( V_71 -> type != V_13 )
return NULL ;
V_72 = F_54 ( V_40 ,
& V_71 -> V_39 . V_58 -> V_59 ) ;
if ( V_72 == NULL )
return NULL ;
return F_7 ( V_72 ) ;
}
struct V_42 * F_55 ( const char * V_14 ,
const struct V_73 * V_40 )
{
struct V_3 * V_71 ;
struct V_9 * V_72 ;
V_71 = F_15 ( V_14 ) ;
if ( V_71 == NULL )
return NULL ;
if ( V_71 -> type != V_13 )
return NULL ;
V_72 = F_56 ( V_40 ,
& V_71 -> V_39 . V_58 -> V_60 ) ;
if ( V_72 == NULL )
return NULL ;
return F_10 ( V_72 ) ;
}
int F_57 ( T_1 * V_74 ,
T_1 * V_75 ,
int (* F_58) ( struct V_3 * V_2 , void * V_76 ) ,
void * V_77 )
{
int V_53 = - V_63 ;
T_1 V_78 ;
struct V_22 * V_79 ;
struct V_3 * V_80 ;
T_1 V_81 = 0 ;
F_31 () ;
for ( V_78 = * V_74 ;
V_78 < F_33 ( V_19 ) -> V_20 ;
V_78 ++ , V_81 = 0 ) {
V_79 = & F_33 ( V_19 ) -> V_24 [ V_78 ] ;
F_14 (iter_entry, iter_list, list)
if ( V_80 -> V_25 ) {
if ( V_81 ++ < * V_75 )
continue;
V_53 = F_58 ( V_80 , V_77 ) ;
if ( V_53 < 0 ) {
V_81 -- ;
goto V_82;
}
}
}
V_82:
F_40 () ;
* V_74 = V_78 ;
* V_75 = V_81 ;
return V_53 ;
}
