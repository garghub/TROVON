static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
if ( F_2 ( V_2 , V_4 , NULL , V_5 ) != NULL )
return 0 ;
return - V_6 ;
}
static int F_3 ( struct V_7 * T_2 V_8 ,
union V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_15 * V_15 )
{
struct V_3 V_4 ;
if ( F_4 ( V_10 , V_15 , & V_4 , V_12 , NULL ) < 0 ) {
F_5 ( L_1 ,
V_10 -> V_16 . type ) ;
return - 1 ;
}
if ( V_4 . V_17 || V_4 . V_18 == NULL )
return 0 ;
if ( F_1 ( & V_14 -> V_1 , & V_4 , V_12 -> V_5 ) ) {
F_5 ( L_2 ) ;
return - 1 ;
}
V_14 -> V_1 . V_19 . V_20 += V_12 -> V_5 ;
return 0 ;
}
static void F_6 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_25 * * V_26 = & V_22 -> V_25 ;
struct V_25 * V_27 = NULL ;
struct V_23 * V_28 ;
while ( * V_26 != NULL ) {
V_27 = * V_26 ;
V_28 = F_7 ( V_27 , struct V_23 , V_25 ) ;
if ( F_8 ( V_24 , V_28 ) < 0 )
V_26 = & ( * V_26 ) -> V_29 ;
else
V_26 = & ( * V_26 ) -> V_30 ;
}
F_9 ( & V_24 -> V_25 , V_27 , V_26 ) ;
F_10 ( & V_24 -> V_25 , V_22 ) ;
}
static void F_11 ( struct V_1 * V_2 , bool V_31 )
{
unsigned long V_32 = 1 ;
struct V_21 V_33 = V_34 ;
struct V_25 * V_35 = F_12 ( & V_2 -> V_36 ) ;
while ( V_35 != NULL ) {
struct V_23 * V_37 = F_7 ( V_35 , struct V_23 , V_25 ) ;
V_35 = F_13 ( & V_37 -> V_25 ) ;
V_37 -> V_32 = V_32 ++ ;
if ( V_31 ) {
F_14 ( & V_37 -> V_25 , & V_2 -> V_36 ) ;
F_6 ( & V_33 , V_37 ) ;
}
}
if ( V_31 )
V_2 -> V_36 = V_33 ;
}
static struct V_23 * F_15 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_25 * V_37 = V_2 -> V_36 . V_25 ;
while ( V_37 ) {
struct V_23 * V_28 = F_7 ( V_37 , struct V_23 , V_25 ) ;
T_3 V_38 = F_8 ( V_24 , V_28 ) ;
if ( V_38 < 0 )
V_37 = V_37 -> V_29 ;
else if ( V_38 > 0 )
V_37 = V_37 -> V_30 ;
else
return V_28 ;
}
return NULL ;
}
static void F_16 ( struct V_1 * V_39 , struct V_1 * V_40 )
{
struct V_25 * V_41 ;
for ( V_41 = F_12 ( & V_40 -> V_36 ) ; V_41 ; V_41 = F_13 ( V_41 ) ) {
struct V_23 * V_42 = F_7 ( V_41 , struct V_23 , V_25 ) ;
V_42 -> V_43 = F_15 ( V_39 , V_42 ) ;
}
}
static struct V_13 * F_17 ( struct V_13 * V_14 ,
struct V_44 * V_45 )
{
struct V_13 * V_46 ;
F_18 (e, &evlist->entries, node)
if ( F_19 ( V_14 , V_46 ) )
return V_46 ;
return NULL ;
}
static void F_20 ( struct V_44 * V_45 , bool V_47 )
{
struct V_13 * V_14 ;
F_18 (evsel, &evlist->entries, node) {
struct V_1 * V_1 = & V_14 -> V_1 ;
F_21 ( V_1 ) ;
if ( V_47 || ( ( ! V_47 ) && V_48 ) )
F_11 ( V_1 , V_47 ) ;
}
}
static int F_22 ( void )
{
int V_49 , V_50 ;
#define V_39 (session[0])
#define V_40 (session[1])
struct V_51 * V_52 [ 2 ] ;
struct V_44 * V_53 , * V_54 ;
struct V_13 * V_14 ;
bool V_55 = true ;
V_39 = F_23 ( V_56 , V_57 , V_58 , false ,
& T_2 ) ;
V_40 = F_23 ( V_59 , V_57 , V_58 , false ,
& T_2 ) ;
if ( V_52 [ 0 ] == NULL || V_52 [ 1 ] == NULL )
return - V_6 ;
for ( V_50 = 0 ; V_50 < 2 ; ++ V_50 ) {
V_49 = F_24 ( V_52 [ V_50 ] , & T_2 ) ;
if ( V_49 )
goto V_60;
}
V_54 = V_39 -> V_45 ;
V_53 = V_40 -> V_45 ;
F_20 ( V_54 , true ) ;
F_20 ( V_53 , false ) ;
F_18 (evsel, &evlist_new->entries, node) {
struct V_13 * V_61 ;
V_61 = F_17 ( V_14 , V_54 ) ;
if ( ! V_61 )
continue;
fprintf ( stdout , L_3 , V_55 ? L_4 : L_5 ,
F_25 ( V_14 ) ) ;
V_55 = false ;
F_16 ( & V_61 -> V_1 , & V_14 -> V_1 ) ;
F_26 ( & V_14 -> V_1 , true , 0 , 0 , stdout ) ;
}
V_60:
for ( V_50 = 0 ; V_50 < 2 ; ++ V_50 )
F_27 ( V_52 [ V_50 ] ) ;
return V_49 ;
#undef V_39
#undef V_40
}
static void F_28 ( void )
{
F_29 () ;
F_30 ( V_62 , false ) ;
F_30 ( V_63 , true ) ;
F_30 ( V_64 , true ) ;
if ( V_48 )
F_30 ( V_65 , true ) ;
}
int F_31 ( int V_66 , const char * * V_67 , const char * T_4 V_8 )
{
V_68 = V_69 ;
V_66 = F_32 ( V_66 , V_67 , V_70 , V_71 , 0 ) ;
if ( V_66 ) {
if ( V_66 > 2 )
F_33 ( V_71 , V_70 ) ;
if ( V_66 == 2 ) {
V_56 = V_67 [ 0 ] ;
V_59 = V_67 [ 1 ] ;
} else
V_59 = V_67 [ 0 ] ;
} else if ( V_72 . V_73 ||
V_72 . V_74 ) {
V_56 = L_6 ;
V_59 = L_7 ;
}
V_72 . V_75 = false ;
if ( F_34 () < 0 )
return - 1 ;
F_28 () ;
F_35 ( V_71 , V_70 ) ;
F_36 () ;
F_37 ( & V_76 , V_72 . V_77 , L_8 , NULL ) ;
F_37 ( & V_78 , V_72 . V_79 , L_9 , NULL ) ;
F_37 ( & V_80 , V_72 . V_81 , L_10 , NULL ) ;
return F_22 () ;
}
