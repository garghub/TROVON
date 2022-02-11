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
static bool F_13 ( T_2 V_22 , T_2 V_23 )
{
return ( V_22 == V_23 ) || ( V_22 == V_24 ) || ( V_23 == V_24 ) ;
}
static struct V_3 * F_14 ( const char * V_15 ,
T_2 V_25 )
{
T_1 V_26 ;
struct V_27 * V_28 ;
struct V_3 * V_17 ;
if ( V_15 != NULL ) {
V_26 = F_11 ( V_15 ) ;
V_28 = & F_12 ( V_20 ) -> V_29 [ V_26 ] ;
F_15 (iter, bkt_list, list)
if ( V_17 -> V_30 &&
F_13 ( V_17 -> V_25 , V_25 ) &&
strcmp ( V_17 -> V_15 , V_15 ) == 0 )
return V_17 ;
}
return NULL ;
}
static struct V_3 * F_16 ( const char * V_15 ,
T_2 V_25 )
{
struct V_3 * V_2 ;
V_2 = F_14 ( V_15 , V_25 ) ;
if ( V_2 != NULL )
return V_2 ;
if ( V_25 == V_31 || V_25 == V_24 ) {
V_2 = F_12 ( V_32 ) ;
if ( V_2 != NULL && V_2 -> V_30 )
return V_2 ;
}
if ( V_25 == V_33 || V_25 == V_24 ) {
V_2 = F_12 ( V_34 ) ;
if ( V_2 != NULL && V_2 -> V_30 )
return V_2 ;
}
return NULL ;
}
static void F_17 ( struct V_3 * V_2 ,
struct V_5 * V_35 ,
struct V_9 * V_36 ,
int V_37 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 ;
struct V_42 * V_43 = NULL ;
struct V_44 * V_45 = NULL ;
T_1 type ;
V_41 = F_18 ( V_46 , V_39 ) ;
if ( V_41 != NULL ) {
F_19 ( V_41 , L_1 ,
V_2 -> V_15 ? V_2 -> V_15 : L_2 ) ;
if ( V_35 != NULL ) {
struct V_47 * V_48 ;
V_48 = F_7 ( V_35 ) ;
type = V_48 -> V_13 . type ;
V_43 = V_48 -> V_13 . V_49 ;
F_20 ( V_41 , 0 , NULL ,
V_35 -> V_50 , V_35 -> V_51 ) ;
#if F_2 ( V_8 )
} else if ( V_36 != NULL ) {
struct V_52 * V_53 ;
V_53 = F_10 ( V_36 ) ;
type = V_53 -> V_13 . type ;
V_45 = V_53 -> V_13 . V_45 ;
F_21 ( V_41 , 0 , NULL ,
& V_36 -> V_50 , & V_36 -> V_51 ) ;
#endif
} else {
type = V_2 -> V_13 . type ;
V_43 = V_2 -> V_13 . V_49 ;
V_45 = V_2 -> V_13 . V_45 ;
}
switch ( type ) {
case V_54 :
F_19 ( V_41 , L_3 ) ;
break;
case V_55 :
F_22 ( V_43 == NULL ) ;
F_19 ( V_41 ,
L_4 ,
V_43 -> V_56 ) ;
break;
case V_57 :
F_22 ( V_45 == NULL ) ;
F_19 ( V_41 ,
L_5 ,
V_45 -> V_56 ) ;
break;
}
F_19 ( V_41 , L_6 , V_37 == 0 ? 1 : 0 ) ;
F_23 ( V_41 ) ;
}
}
static int F_24 ( const struct V_3 * V_2 )
{
struct V_5 * V_6 ;
struct V_47 * V_48 ;
#if F_2 ( V_8 )
struct V_9 * V_10 ;
struct V_52 * V_53 ;
#endif
if ( V_2 == NULL )
return - V_58 ;
if ( V_2 -> V_25 != V_31 && V_2 -> V_25 != V_33 &&
( V_2 -> V_25 != V_24 ||
V_2 -> V_13 . type != V_54 ) )
return - V_58 ;
switch ( V_2 -> V_13 . type ) {
case V_54 :
if ( V_2 -> V_13 . V_49 != NULL || V_2 -> V_13 . V_45 != NULL ||
V_2 -> V_13 . V_59 != NULL )
return - V_58 ;
break;
case V_55 :
if ( V_2 -> V_25 != V_31 ||
V_2 -> V_13 . V_49 == NULL )
return - V_58 ;
break;
case V_57 :
if ( V_2 -> V_25 != V_33 ||
V_2 -> V_13 . V_45 == NULL )
return - V_58 ;
break;
case V_14 :
F_25 (iter4, &entry->def.addrsel->list4) {
V_48 = F_7 ( V_6 ) ;
switch ( V_48 -> V_13 . type ) {
case V_54 :
if ( V_48 -> V_13 . V_49 != NULL )
return - V_58 ;
break;
case V_55 :
if ( V_48 -> V_13 . V_49 == NULL )
return - V_58 ;
break;
default:
return - V_58 ;
}
}
#if F_2 ( V_8 )
F_26 (iter6, &entry->def.addrsel->list6) {
V_53 = F_10 ( V_10 ) ;
switch ( V_53 -> V_13 . type ) {
case V_54 :
if ( V_53 -> V_13 . V_45 != NULL )
return - V_58 ;
break;
case V_57 :
if ( V_53 -> V_13 . V_45 == NULL )
return - V_58 ;
break;
default:
return - V_58 ;
}
}
#endif
break;
default:
return - V_58 ;
}
return 0 ;
}
int T_3 F_27 ( T_1 V_21 )
{
T_1 V_17 ;
struct V_60 * V_61 ;
if ( V_21 == 0 )
return - V_58 ;
V_61 = F_28 ( sizeof( * V_61 ) , V_62 ) ;
if ( V_61 == NULL )
return - V_63 ;
V_61 -> V_21 = 1 << V_21 ;
V_61 -> V_29 = F_29 ( V_61 -> V_21 ,
sizeof( struct V_27 ) ,
V_62 ) ;
if ( V_61 -> V_29 == NULL ) {
F_6 ( V_61 ) ;
return - V_63 ;
}
for ( V_17 = 0 ; V_17 < V_61 -> V_21 ; V_17 ++ )
F_30 ( & V_61 -> V_29 [ V_17 ] ) ;
F_31 ( & V_64 ) ;
F_32 ( V_20 , V_61 ) ;
F_33 ( & V_64 ) ;
return 0 ;
}
int F_34 ( struct V_3 * V_2 ,
struct V_38 * V_39 )
{
int V_65 = 0 ;
struct V_3 * V_66 , * V_67 ;
struct V_5 * V_6 ;
struct V_5 * V_7 ;
#if F_2 ( V_8 )
struct V_9 * V_10 ;
struct V_9 * V_11 ;
#endif
V_65 = F_24 ( V_2 ) ;
if ( V_65 != 0 )
return V_65 ;
F_35 () ;
F_31 ( & V_64 ) ;
if ( V_2 -> V_15 != NULL )
V_66 = F_14 ( V_2 -> V_15 , V_2 -> V_25 ) ;
else
V_66 = F_16 ( V_2 -> V_15 ,
V_2 -> V_25 ) ;
if ( V_66 == NULL ) {
V_2 -> V_30 = 1 ;
if ( V_2 -> V_15 != NULL ) {
T_1 V_26 = F_11 ( V_2 -> V_15 ) ;
F_36 ( & V_2 -> V_68 ,
& F_37 ( V_20 ) -> V_29 [ V_26 ] ) ;
} else {
F_30 ( & V_2 -> V_68 ) ;
switch ( V_2 -> V_25 ) {
case V_31 :
F_32 ( V_32 ,
V_2 ) ;
break;
case V_33 :
F_32 ( V_34 ,
V_2 ) ;
break;
case V_24 :
if ( V_2 -> V_13 . type !=
V_54 ) {
V_65 = - V_58 ;
goto V_69;
}
V_67 = F_38 ( sizeof( * V_67 ) , V_70 ) ;
if ( V_67 == NULL ) {
V_65 = - V_63 ;
goto V_69;
}
V_67 -> V_25 = V_33 ;
V_67 -> V_13 . type = V_54 ;
V_67 -> V_30 = 1 ;
V_2 -> V_25 = V_31 ;
F_32 ( V_32 ,
V_2 ) ;
F_32 ( V_34 ,
V_67 ) ;
break;
default:
V_65 = - V_58 ;
goto V_69;
}
}
if ( V_2 -> V_13 . type == V_14 ) {
F_39 (iter4,
&entry->def.addrsel->list4)
F_17 ( V_2 , V_6 , NULL ,
V_65 , V_39 ) ;
#if F_2 ( V_8 )
F_40 (iter6,
&entry->def.addrsel->list6)
F_17 ( V_2 , NULL , V_10 ,
V_65 , V_39 ) ;
#endif
} else
F_17 ( V_2 , NULL , NULL ,
V_65 , V_39 ) ;
} else if ( V_66 -> V_13 . type == V_14 &&
V_2 -> V_13 . type == V_14 ) {
struct V_27 * V_71 ;
struct V_27 * V_72 ;
V_71 = & V_66 -> V_13 . V_59 -> V_73 ;
V_72 = & V_66 -> V_13 . V_59 -> V_74 ;
F_39 (iter4, &entry->def.addrsel->list4)
if ( F_41 ( V_6 -> V_50 ,
V_6 -> V_51 ,
V_71 ) ) {
V_65 = - V_75 ;
goto V_69;
}
#if F_2 ( V_8 )
F_40 (iter6, &entry->def.addrsel->list6)
if ( F_42 ( & V_10 -> V_50 ,
& V_10 -> V_51 ,
V_72 ) ) {
V_65 = - V_75 ;
goto V_69;
}
#endif
F_4 (iter4, tmp4,
&entry->def.addrsel->list4) {
F_5 ( V_6 ) ;
V_6 -> V_30 = 1 ;
V_65 = F_43 ( V_6 , V_71 ) ;
F_17 ( V_66 , V_6 , NULL ,
V_65 , V_39 ) ;
if ( V_65 != 0 )
goto V_69;
}
#if F_2 ( V_8 )
F_8 (iter6, tmp6,
&entry->def.addrsel->list6) {
F_9 ( V_10 ) ;
V_10 -> V_30 = 1 ;
V_65 = F_44 ( V_10 , V_72 ) ;
F_17 ( V_66 , NULL , V_10 ,
V_65 , V_39 ) ;
if ( V_65 != 0 )
goto V_69;
}
#endif
} else
V_65 = - V_58 ;
V_69:
F_33 ( & V_64 ) ;
F_45 () ;
return V_65 ;
}
int F_46 ( struct V_3 * V_2 ,
struct V_38 * V_39 )
{
return F_34 ( V_2 , V_39 ) ;
}
int F_47 ( struct V_3 * V_2 ,
struct V_38 * V_39 )
{
int V_65 = 0 ;
struct V_40 * V_41 ;
if ( V_2 == NULL )
return - V_76 ;
F_31 ( & V_64 ) ;
if ( V_2 -> V_30 ) {
V_2 -> V_30 = 0 ;
if ( V_2 == F_37 ( V_32 ) )
F_48 ( V_32 , NULL ) ;
else if ( V_2 == F_37 ( V_34 ) )
F_48 ( V_34 , NULL ) ;
else
F_49 ( & V_2 -> V_68 ) ;
} else
V_65 = - V_76 ;
F_33 ( & V_64 ) ;
V_41 = F_18 ( V_77 , V_39 ) ;
if ( V_41 != NULL ) {
F_19 ( V_41 ,
L_7 ,
V_2 -> V_15 ? V_2 -> V_15 : L_2 ,
V_65 == 0 ? 1 : 0 ) ;
F_23 ( V_41 ) ;
}
if ( V_65 == 0 ) {
struct V_5 * V_6 ;
struct V_47 * V_48 ;
#if F_2 ( V_8 )
struct V_9 * V_10 ;
struct V_52 * V_53 ;
#endif
switch ( V_2 -> V_13 . type ) {
case V_14 :
F_39 (iter4,
&entry->def.addrsel->list4) {
V_48 = F_7 ( V_6 ) ;
F_50 ( V_48 -> V_13 . V_49 ) ;
}
#if F_2 ( V_8 )
F_40 (iter6,
&entry->def.addrsel->list6) {
V_53 = F_10 ( V_10 ) ;
F_51 ( V_53 -> V_13 . V_45 ) ;
}
#endif
break;
case V_55 :
F_50 ( V_2 -> V_13 . V_49 ) ;
break;
#if F_2 ( V_8 )
case V_57 :
F_51 ( V_2 -> V_13 . V_45 ) ;
break;
#endif
}
F_52 ( & V_2 -> V_12 , F_1 ) ;
}
return V_65 ;
}
int F_53 ( const char * V_15 ,
const struct V_78 * V_50 ,
const struct V_78 * V_51 ,
struct V_38 * V_39 )
{
struct V_3 * V_79 ;
struct V_5 * V_80 ;
struct V_5 * V_6 ;
#if F_2 ( V_8 )
struct V_9 * V_10 ;
#endif
struct V_47 * V_2 ;
F_35 () ;
if ( V_15 )
V_79 = F_14 ( V_15 , V_31 ) ;
else
V_79 = F_16 ( V_15 , V_31 ) ;
if ( V_79 == NULL ||
V_79 -> V_13 . type != V_14 )
goto V_81;
F_31 ( & V_64 ) ;
V_80 = F_54 ( V_50 -> V_82 , V_51 -> V_82 ,
& V_79 -> V_13 . V_59 -> V_73 ) ;
F_33 ( & V_64 ) ;
if ( V_80 == NULL )
goto V_81;
F_39 (iter4, &entry_map->def.addrsel->list4)
goto V_83;
#if F_2 ( V_8 )
F_40 (iter6, &entry_map->def.addrsel->list6)
goto V_83;
#endif
F_47 ( V_79 , V_39 ) ;
V_83:
F_45 () ;
F_55 () ;
V_2 = F_7 ( V_80 ) ;
F_50 ( V_2 -> V_13 . V_49 ) ;
F_6 ( V_2 ) ;
return 0 ;
V_81:
F_45 () ;
return - V_76 ;
}
int F_56 ( const char * V_15 ,
const struct V_84 * V_50 ,
const struct V_84 * V_51 ,
struct V_38 * V_39 )
{
struct V_3 * V_79 ;
struct V_9 * V_80 ;
struct V_5 * V_6 ;
struct V_9 * V_10 ;
struct V_52 * V_2 ;
F_35 () ;
if ( V_15 )
V_79 = F_14 ( V_15 , V_33 ) ;
else
V_79 = F_16 ( V_15 , V_33 ) ;
if ( V_79 == NULL ||
V_79 -> V_13 . type != V_14 )
goto V_85;
F_31 ( & V_64 ) ;
V_80 = F_57 ( V_50 , V_51 ,
& V_79 -> V_13 . V_59 -> V_74 ) ;
F_33 ( & V_64 ) ;
if ( V_80 == NULL )
goto V_85;
F_39 (iter4, &entry_map->def.addrsel->list4)
goto V_86;
F_40 (iter6, &entry_map->def.addrsel->list6)
goto V_86;
F_47 ( V_79 , V_39 ) ;
V_86:
F_45 () ;
F_55 () ;
V_2 = F_10 ( V_80 ) ;
F_51 ( V_2 -> V_13 . V_45 ) ;
F_6 ( V_2 ) ;
return 0 ;
V_85:
F_45 () ;
return - V_76 ;
}
int F_58 ( const char * V_15 , T_2 V_25 ,
struct V_38 * V_39 )
{
int V_65 = - V_58 ;
struct V_3 * V_2 ;
F_35 () ;
if ( V_25 == V_31 || V_25 == V_24 ) {
if ( V_15 )
V_2 = F_14 ( V_15 , V_31 ) ;
else
V_2 = F_16 ( V_15 , V_31 ) ;
V_65 = F_47 ( V_2 , V_39 ) ;
if ( V_65 && V_65 != - V_76 )
goto V_87;
}
if ( V_25 == V_33 || V_25 == V_24 ) {
int V_88 ;
if ( V_15 )
V_2 = F_14 ( V_15 , V_33 ) ;
else
V_2 = F_16 ( V_15 , V_33 ) ;
V_88 = F_47 ( V_2 , V_39 ) ;
if ( V_88 != - V_76 )
V_65 = V_88 ;
}
V_87:
F_45 () ;
return V_65 ;
}
int F_59 ( T_2 V_25 , struct V_38 * V_39 )
{
return F_58 ( NULL , V_25 , V_39 ) ;
}
struct V_3 * F_60 ( const char * V_15 , T_2 V_25 )
{
if ( V_25 == V_24 )
return NULL ;
return F_16 ( V_15 , V_25 ) ;
}
struct V_89 * F_61 ( const char * V_15 ,
T_4 V_50 )
{
struct V_3 * V_90 ;
struct V_5 * V_91 ;
V_90 = F_16 ( V_15 , V_31 ) ;
if ( V_90 == NULL )
return NULL ;
if ( V_90 -> V_13 . type != V_14 )
return & V_90 -> V_13 ;
V_91 = F_62 ( V_50 , & V_90 -> V_13 . V_59 -> V_73 ) ;
if ( V_91 == NULL )
return NULL ;
return & ( F_7 ( V_91 ) -> V_13 ) ;
}
struct V_89 * F_63 ( const char * V_15 ,
const struct V_84 * V_50 )
{
struct V_3 * V_90 ;
struct V_9 * V_91 ;
V_90 = F_16 ( V_15 , V_33 ) ;
if ( V_90 == NULL )
return NULL ;
if ( V_90 -> V_13 . type != V_14 )
return & V_90 -> V_13 ;
V_91 = F_64 ( V_50 , & V_90 -> V_13 . V_59 -> V_74 ) ;
if ( V_91 == NULL )
return NULL ;
return & ( F_10 ( V_91 ) -> V_13 ) ;
}
int F_65 ( T_1 * V_92 ,
T_1 * V_93 ,
int (* F_66) ( struct V_3 * V_2 , void * V_94 ) ,
void * V_95 )
{
int V_65 = - V_76 ;
T_1 V_96 ;
struct V_27 * V_97 ;
struct V_3 * V_98 ;
T_1 V_99 = 0 ;
F_35 () ;
for ( V_96 = * V_92 ;
V_96 < F_37 ( V_20 ) -> V_21 ;
V_96 ++ , V_99 = 0 ) {
V_97 = & F_37 ( V_20 ) -> V_29 [ V_96 ] ;
F_15 (iter_entry, iter_list, list)
if ( V_98 -> V_30 ) {
if ( V_99 ++ < * V_93 )
continue;
V_65 = F_66 ( V_98 , V_95 ) ;
if ( V_65 < 0 ) {
V_99 -- ;
goto V_100;
}
}
}
V_100:
F_45 () ;
* V_92 = V_96 ;
* V_93 = V_99 ;
return V_65 ;
}
