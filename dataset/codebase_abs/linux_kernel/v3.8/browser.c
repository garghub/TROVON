static void F_1 ( int V_1 )
{
F_2 ( false ) ;
F_3 ( V_1 , L_1 ) ;
}
static void F_4 ( T_1 * V_2 )
{
T_2 V_3 ;
T_3 * V_4 ;
int V_5 ;
int V_6 ;
int V_7 ;
V_4 = F_5 ( V_2 ) ;
V_5 = F_6 ( V_4 , V_2 -> V_2 ) ;
F_7 ( V_4 , V_5 , & V_3 ) ;
V_7 = V_3 . V_7 * 3 / 4 ;
V_6 = V_3 . V_6 * 3 / 4 ;
F_8 ( F_9 ( V_2 ) , V_7 , V_6 ) ;
}
static const char * F_10 ( double V_8 )
{
if ( V_8 >= V_9 )
return L_2 ;
if ( V_8 >= V_10 )
return L_3 ;
return NULL ;
}
void F_11 ( void )
{
F_12 () ;
V_11 [ V_12 ] . V_13 =
V_14 ;
V_11 [ V_15 ] . V_13 =
V_16 ;
V_11 [ V_17 ] . V_13 =
V_18 ;
V_11 [ V_19 ] . V_13 =
V_20 ;
V_11 [ V_21 ] . V_13 =
V_22 ;
}
static void F_13 ( T_1 * V_2 , struct V_23 * V_23 )
{
T_4 V_24 [ V_25 ] ;
T_5 * V_26 ;
struct V_27 * V_28 ;
T_6 * V_29 ;
struct V_30 * V_31 ;
T_1 * V_32 ;
int V_33 , V_34 ;
int V_35 ;
char V_36 [ 512 ] ;
struct V_37 V_38 = {
. V_39 = V_36 ,
. V_40 = sizeof( V_36 ) ,
} ;
V_35 = 0 ;
for ( V_33 = 0 ; V_33 < V_41 ; V_33 ++ ) {
if ( ! V_11 [ V_33 ] . V_42 )
continue;
V_24 [ V_35 ++ ] = V_43 ;
}
F_14 (se, &hist_entry__sort_list, list) {
if ( V_28 -> V_44 )
continue;
V_24 [ V_35 ++ ] = V_43 ;
}
V_29 = F_15 ( V_35 , V_24 ) ;
V_32 = F_16 () ;
V_26 = F_17 () ;
V_34 = 0 ;
for ( V_33 = 0 ; V_33 < V_41 ; V_33 ++ ) {
if ( ! V_11 [ V_33 ] . V_42 )
continue;
V_11 [ V_33 ] . F_18 ( & V_38 ) ;
F_19 ( F_20 ( V_32 ) ,
- 1 , V_36 ,
V_26 , L_4 ,
V_34 ++ , NULL ) ;
}
F_14 (se, &hist_entry__sort_list, list) {
if ( V_28 -> V_44 )
continue;
F_19 ( F_20 ( V_32 ) ,
- 1 , V_28 -> V_45 ,
V_26 , L_5 ,
V_34 ++ , NULL ) ;
}
F_21 ( F_20 ( V_32 ) , F_22 ( V_29 ) ) ;
F_23 ( F_22 ( V_29 ) ) ;
for ( V_31 = F_24 ( & V_23 -> V_46 ) ; V_31 ; V_31 = F_25 ( V_31 ) ) {
struct V_47 * V_48 = F_26 ( V_31 , struct V_47 , V_30 ) ;
T_7 V_49 ;
if ( V_48 -> V_50 )
continue;
F_27 ( V_29 , & V_49 ) ;
V_34 = 0 ;
for ( V_33 = 0 ; V_33 < V_41 ; V_33 ++ ) {
if ( ! V_11 [ V_33 ] . V_42 )
continue;
if ( V_11 [ V_33 ] . V_13 )
V_11 [ V_33 ] . V_13 ( & V_38 , V_48 ) ;
else
V_11 [ V_33 ] . F_28 ( & V_38 , V_48 ) ;
F_29 ( V_29 , & V_49 , V_34 ++ , V_36 , - 1 ) ;
}
F_14 (se, &hist_entry__sort_list, list) {
if ( V_28 -> V_44 )
continue;
V_28 -> V_51 ( V_48 , V_36 , F_30 ( V_36 ) ,
F_31 ( V_23 , V_28 -> V_52 ) ) ;
F_29 ( V_29 , & V_49 , V_34 ++ , V_36 , - 1 ) ;
}
}
F_32 ( F_33 ( V_2 ) , V_32 ) ;
}
static T_1 * F_34 ( void )
{
T_1 * V_53 ;
T_1 * V_54 ;
T_1 * V_55 ;
V_53 = F_35 () ;
F_36 ( V_53 , TRUE ) ;
V_54 = F_37 ( L_6 ) ;
F_38 ( V_54 ) ;
V_55 = F_39 ( F_40 ( V_53 ) ) ;
F_32 ( F_33 ( V_55 ) , V_54 ) ;
F_41 ( F_40 ( V_53 ) , V_56 ,
V_57 ) ;
F_42 ( V_53 , L_7 ,
F_43 ( V_58 ) , NULL ) ;
V_59 -> V_53 = V_53 ;
V_59 -> V_60 = V_54 ;
return V_53 ;
}
static T_1 * F_44 ( void )
{
T_1 * V_61 ;
unsigned V_62 ;
V_61 = F_45 () ;
V_62 = F_46 ( F_47 ( V_61 ) ,
L_8 ) ;
V_59 -> V_63 = V_61 ;
V_59 -> V_64 = V_62 ;
return V_61 ;
}
int F_48 ( struct V_65 * V_66 ,
const char * V_67 ,
struct V_68 * T_8 V_69 )
{
struct V_70 * V_71 ;
T_1 * V_72 ;
T_1 * V_73 ;
T_1 * V_53 ;
T_1 * V_63 ;
T_1 * V_2 ;
signal ( V_74 , F_1 ) ;
signal ( V_75 , F_1 ) ;
signal ( V_76 , F_1 ) ;
signal ( V_77 , F_1 ) ;
signal ( V_78 , F_1 ) ;
V_2 = F_49 ( V_79 ) ;
F_50 ( F_9 ( V_2 ) , L_8 ) ;
F_42 ( V_2 , L_9 , V_80 , NULL ) ;
V_59 = F_51 ( V_2 ) ;
if ( ! V_59 )
return - 1 ;
V_72 = F_52 ( FALSE , 0 ) ;
V_73 = F_53 () ;
F_14 (pos, &evlist->entries, node) {
struct V_23 * V_23 = & V_71 -> V_23 ;
const char * V_81 = F_54 ( V_71 ) ;
T_1 * V_82 ;
T_1 * V_83 ;
V_82 = F_55 ( NULL , NULL ) ;
F_56 ( F_57 ( V_82 ) ,
V_84 ,
V_84 ) ;
F_13 ( V_82 , V_23 ) ;
V_83 = F_37 ( V_81 ) ;
F_58 ( F_59 ( V_73 ) , V_82 , V_83 ) ;
}
F_60 ( F_61 ( V_72 ) , V_73 , TRUE , TRUE , 0 ) ;
V_53 = F_34 () ;
if ( V_53 )
F_60 ( F_61 ( V_72 ) , V_53 , FALSE , FALSE , 0 ) ;
V_63 = F_44 () ;
F_60 ( F_61 ( V_72 ) , V_63 , FALSE , FALSE , 0 ) ;
F_32 ( F_33 ( V_2 ) , V_72 ) ;
F_62 ( V_2 ) ;
F_4 ( V_2 ) ;
F_63 ( F_9 ( V_2 ) , V_85 ) ;
F_64 ( V_67 ) ;
F_65 () ;
F_66 ( & V_59 ) ;
return 0 ;
}
