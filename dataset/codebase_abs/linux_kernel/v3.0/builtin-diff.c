static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
if ( F_2 ( V_2 , V_4 , NULL , V_5 ) != NULL )
return 0 ;
return - V_6 ;
}
static int F_3 ( union V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_11 * T_2 V_12 ,
struct V_13 * V_14 )
{
struct V_3 V_4 ;
if ( F_4 ( V_8 , V_14 , & V_4 , V_10 , NULL ) < 0 ) {
F_5 ( L_1 ,
V_8 -> V_15 . type ) ;
return - 1 ;
}
if ( V_4 . V_16 || V_4 . V_17 == NULL )
return 0 ;
if ( F_1 ( & V_14 -> V_1 , & V_4 , V_10 -> V_5 ) ) {
F_5 ( L_2 ) ;
return - 1 ;
}
V_14 -> V_1 . V_18 . V_19 += V_10 -> V_5 ;
return 0 ;
}
static void F_6 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * * V_25 = & V_21 -> V_24 ;
struct V_24 * V_26 = NULL ;
struct V_22 * V_27 ;
while ( * V_25 != NULL ) {
V_26 = * V_25 ;
V_27 = F_7 ( V_26 , struct V_22 , V_24 ) ;
if ( F_8 ( V_23 , V_27 ) < 0 )
V_25 = & ( * V_25 ) -> V_28 ;
else
V_25 = & ( * V_25 ) -> V_29 ;
}
F_9 ( & V_23 -> V_24 , V_26 , V_25 ) ;
F_10 ( & V_23 -> V_24 , V_21 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned long V_30 = 1 ;
struct V_20 V_31 = V_32 ;
struct V_24 * V_33 = F_12 ( & V_2 -> V_34 ) ;
while ( V_33 != NULL ) {
struct V_22 * V_35 = F_7 ( V_33 , struct V_22 , V_24 ) ;
V_33 = F_13 ( & V_35 -> V_24 ) ;
F_14 ( & V_35 -> V_24 , & V_2 -> V_34 ) ;
V_35 -> V_30 = V_30 ++ ;
F_6 ( & V_31 , V_35 ) ;
}
V_2 -> V_34 = V_31 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_11 ( V_2 ) ;
}
static struct V_22 * F_17 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_24 * V_35 = V_2 -> V_34 . V_24 ;
while ( V_35 ) {
struct V_22 * V_27 = F_7 ( V_35 , struct V_22 , V_24 ) ;
T_3 V_36 = F_8 ( V_23 , V_27 ) ;
if ( V_36 < 0 )
V_35 = V_35 -> V_28 ;
else if ( V_36 > 0 )
V_35 = V_35 -> V_29 ;
else
return V_27 ;
}
return NULL ;
}
static void F_18 ( struct V_1 * V_37 , struct V_1 * V_38 )
{
struct V_24 * V_39 ;
for ( V_39 = F_12 ( & V_38 -> V_34 ) ; V_39 ; V_39 = F_13 ( V_39 ) ) {
struct V_22 * V_40 = F_7 ( V_39 , struct V_22 , V_24 ) ;
V_40 -> V_41 = F_17 ( V_37 , V_40 ) ;
}
}
static int F_19 ( void )
{
int V_42 , V_43 ;
struct V_13 * V_14 [ 2 ] ;
V_14 [ 0 ] = F_20 ( V_44 , V_45 , V_46 , false , & V_47 ) ;
V_14 [ 1 ] = F_20 ( V_48 , V_45 , V_46 , false , & V_47 ) ;
if ( V_14 [ 0 ] == NULL || V_14 [ 1 ] == NULL )
return - V_6 ;
for ( V_43 = 0 ; V_43 < 2 ; ++ V_43 ) {
V_42 = F_21 ( V_14 [ V_43 ] , & V_47 ) ;
if ( V_42 )
goto V_49;
}
F_16 ( & V_14 [ 1 ] -> V_1 ) ;
if ( V_50 )
F_15 ( & V_14 [ 0 ] -> V_1 ) ;
F_18 ( & V_14 [ 0 ] -> V_1 , & V_14 [ 1 ] -> V_1 ) ;
F_22 ( & V_14 [ 1 ] -> V_1 , & V_14 [ 0 ] -> V_1 ,
V_50 , stdout ) ;
V_49:
for ( V_43 = 0 ; V_43 < 2 ; ++ V_43 )
F_23 ( V_14 [ V_43 ] ) ;
return V_42 ;
}
int F_24 ( int V_51 , const char * * V_52 , const char * T_4 V_12 )
{
V_53 = V_54 ;
V_51 = F_25 ( V_51 , V_52 , V_55 , V_56 , 0 ) ;
if ( V_51 ) {
if ( V_51 > 2 )
F_26 ( V_56 , V_55 ) ;
if ( V_51 == 2 ) {
V_44 = V_52 [ 0 ] ;
V_48 = V_52 [ 1 ] ;
} else
V_48 = V_52 [ 0 ] ;
} else if ( V_57 . V_58 ||
V_57 . V_59 ) {
V_44 = L_3 ;
V_48 = L_4 ;
}
V_57 . V_60 = false ;
if ( F_27 () < 0 )
return - 1 ;
F_28 ( V_56 , V_55 ) ;
F_29 () ;
F_30 ( & V_61 , V_57 . V_62 , L_5 , NULL ) ;
F_30 ( & V_63 , V_57 . V_64 , L_6 , NULL ) ;
F_30 ( & V_65 , V_57 . V_66 , L_7 , NULL ) ;
return F_19 () ;
}
