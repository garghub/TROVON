static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
if ( F_2 ( V_2 , V_4 , NULL , V_5 ) != NULL )
return 0 ;
return - V_6 ;
}
static int F_3 ( struct V_7 * V_8 ,
union V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * T_2 V_14 ,
struct V_15 * V_15 )
{
struct V_16 * V_17 = F_4 ( V_8 , struct V_16 , V_8 ) ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_3 V_4 ;
if ( F_5 ( V_10 , V_15 , & V_4 , V_12 , NULL ) < 0 ) {
F_6 ( L_1 ,
V_10 -> V_20 . type ) ;
return - 1 ;
}
if ( V_4 . V_21 || V_4 . V_22 == NULL )
return 0 ;
if ( F_1 ( & V_19 -> V_1 , & V_4 , V_12 -> V_5 ) ) {
F_6 ( L_2 ) ;
return - 1 ;
}
V_19 -> V_1 . V_23 . V_24 += V_12 -> V_5 ;
return 0 ;
}
static void F_7 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_29 * * V_30 = & V_26 -> V_29 ;
struct V_29 * V_31 = NULL ;
struct V_27 * V_32 ;
while ( * V_30 != NULL ) {
V_31 = * V_30 ;
V_32 = F_8 ( V_31 , struct V_27 , V_29 ) ;
if ( F_9 ( V_28 , V_32 ) < 0 )
V_30 = & ( * V_30 ) -> V_33 ;
else
V_30 = & ( * V_30 ) -> V_34 ;
}
F_10 ( & V_28 -> V_29 , V_31 , V_30 ) ;
F_11 ( & V_28 -> V_29 , V_26 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned long V_35 = 1 ;
struct V_25 V_36 = V_37 ;
struct V_29 * V_38 = F_13 ( & V_2 -> V_39 ) ;
while ( V_38 != NULL ) {
struct V_27 * V_40 = F_8 ( V_38 , struct V_27 , V_29 ) ;
V_38 = F_14 ( & V_40 -> V_29 ) ;
F_15 ( & V_40 -> V_29 , & V_2 -> V_39 ) ;
V_40 -> V_35 = V_35 ++ ;
F_7 ( & V_36 , V_40 ) ;
}
V_2 -> V_39 = V_36 ;
}
static struct V_27 * F_16 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_29 * V_40 = V_2 -> V_39 . V_29 ;
while ( V_40 ) {
struct V_27 * V_32 = F_8 ( V_40 , struct V_27 , V_29 ) ;
T_3 V_41 = F_9 ( V_28 , V_32 ) ;
if ( V_41 < 0 )
V_40 = V_40 -> V_33 ;
else if ( V_41 > 0 )
V_40 = V_40 -> V_34 ;
else
return V_32 ;
}
return NULL ;
}
static void F_17 ( struct V_1 * V_42 , struct V_1 * V_43 )
{
struct V_29 * V_44 ;
for ( V_44 = F_13 ( & V_43 -> V_39 ) ; V_44 ; V_44 = F_14 ( V_44 ) ) {
struct V_27 * V_45 = F_8 ( V_44 , struct V_27 , V_29 ) ;
V_45 -> V_46 = F_16 ( V_42 , V_45 ) ;
}
}
static int F_18 ( void )
{
int V_47 , V_48 ;
#define V_42 (session[0])
#define V_43 (session[1])
struct V_18 * V_19 [ 2 ] ;
V_42 = F_19 ( V_49 , V_50 , V_51 , false ,
& V_52 . V_8 ) ;
V_43 = F_19 ( V_53 , V_50 , V_51 , false ,
& V_52 . V_8 ) ;
if ( V_19 [ 0 ] == NULL || V_19 [ 1 ] == NULL )
return - V_6 ;
for ( V_48 = 0 ; V_48 < 2 ; ++ V_48 ) {
V_52 . V_19 = V_19 [ V_48 ] ;
V_47 = F_20 ( V_19 [ V_48 ] , & V_52 . V_8 ) ;
if ( V_47 )
goto V_54;
F_21 ( & V_19 [ V_48 ] -> V_1 ) ;
}
if ( V_55 )
F_12 ( & V_42 -> V_1 ) ;
F_17 ( & V_42 -> V_1 , & V_43 -> V_1 ) ;
F_22 ( & V_43 -> V_1 , & V_42 -> V_1 ,
V_55 , true , 0 , 0 , stdout ) ;
V_54:
for ( V_48 = 0 ; V_48 < 2 ; ++ V_48 )
F_23 ( V_19 [ V_48 ] ) ;
return V_47 ;
#undef V_42
#undef V_43
}
int F_24 ( int V_56 , const char * * V_57 , const char * T_4 V_14 )
{
V_58 = V_59 ;
V_56 = F_25 ( V_56 , V_57 , V_60 , V_61 , 0 ) ;
if ( V_56 ) {
if ( V_56 > 2 )
F_26 ( V_61 , V_60 ) ;
if ( V_56 == 2 ) {
V_49 = V_57 [ 0 ] ;
V_53 = V_57 [ 1 ] ;
} else
V_53 = V_57 [ 0 ] ;
} else if ( V_62 . V_63 ||
V_62 . V_64 ) {
V_49 = L_3 ;
V_53 = L_4 ;
}
V_62 . V_65 = false ;
if ( F_27 () < 0 )
return - 1 ;
F_28 ( V_61 , V_60 ) ;
F_29 () ;
F_30 ( & V_66 , V_62 . V_67 , L_5 , NULL ) ;
F_30 ( & V_68 , V_62 . V_69 , L_6 , NULL ) ;
F_30 ( & V_70 , V_62 . V_71 , L_7 , NULL ) ;
return F_18 () ;
}
