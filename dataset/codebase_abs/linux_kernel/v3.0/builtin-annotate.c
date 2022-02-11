static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
if ( V_12 != NULL &&
( V_8 -> V_13 == NULL || strcmp ( V_12 , V_8 -> V_13 -> V_14 ) != 0 ) ) {
if ( V_8 -> V_13 != NULL ) {
F_2 ( & V_8 -> V_13 -> V_15 ,
& V_8 -> V_16 -> V_17 -> V_18 [ V_8 -> V_16 -> type ] ) ;
F_3 ( V_8 -> V_13 ) ;
}
return 0 ;
}
V_10 = F_4 ( & V_6 -> V_19 , V_8 , NULL , 1 ) ;
if ( V_10 == NULL )
return - V_20 ;
V_11 = 0 ;
if ( V_10 -> V_21 . V_13 != NULL ) {
struct V_22 * V_23 = F_5 ( V_10 -> V_21 . V_13 ) ;
if ( V_23 -> V_24 == NULL &&
F_6 ( V_10 -> V_21 . V_13 , V_2 -> V_25 ) < 0 )
return - V_20 ;
V_11 = F_7 ( V_10 , V_6 -> V_26 , V_8 -> V_27 ) ;
}
V_6 -> V_19 . V_28 . V_29 += V_4 -> V_30 ;
F_8 ( & V_6 -> V_19 , V_31 ) ;
return V_11 ;
}
static int F_9 ( union V_32 * V_33 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_34 * V_35 )
{
struct V_7 V_8 ;
if ( F_10 ( V_33 , V_35 , & V_8 , V_4 ,
V_36 ) < 0 ) {
F_11 ( L_1 ,
V_33 -> V_37 . type ) ;
return - 1 ;
}
if ( ! V_8 . V_38 &&
F_1 ( V_35 -> V_2 , V_4 , V_6 , & V_8 ) ) {
F_11 ( L_2
L_3 ) ;
return - 1 ;
}
return 0 ;
}
static int F_12 ( struct V_9 * V_10 , int V_39 )
{
return F_13 ( V_10 -> V_21 . V_13 , V_10 -> V_21 . V_16 , V_39 ,
V_40 , V_41 , 0 , 0 ) ;
}
static void F_14 ( struct V_19 * V_42 , int V_39 )
{
struct V_15 * V_43 = F_15 ( & V_42 -> V_44 ) , * V_45 ;
int V_46 = V_47 ;
while ( V_43 ) {
struct V_9 * V_10 = F_16 ( V_43 , struct V_9 , V_15 ) ;
struct V_22 * V_23 ;
if ( V_10 -> V_21 . V_13 == NULL || V_10 -> V_21 . V_16 -> V_17 -> V_48 )
goto V_49;
V_23 = F_5 ( V_10 -> V_21 . V_13 ) ;
if ( V_23 -> V_24 == NULL ) {
V_49:
if ( V_46 == V_50 )
V_43 = F_17 ( V_43 ) ;
else
V_43 = F_18 ( V_43 ) ;
continue;
}
if ( V_51 > 0 ) {
V_46 = F_19 ( V_10 , V_39 ) ;
switch ( V_46 ) {
case V_47 :
V_45 = F_18 ( V_43 ) ;
break;
case V_50 :
V_45 = F_17 ( V_43 ) ;
break;
default:
return;
}
if ( V_45 != NULL )
V_43 = V_45 ;
} else {
F_12 ( V_10 , V_39 ) ;
V_43 = F_18 ( V_43 ) ;
free ( V_23 -> V_24 ) ;
V_23 -> V_24 = NULL ;
}
}
}
static int F_20 ( void )
{
int V_11 ;
struct V_34 * V_35 ;
struct V_5 * V_52 ;
T_1 V_53 ;
V_35 = F_21 ( V_54 , V_55 , V_56 , false , & V_57 ) ;
if ( V_35 == NULL )
return - V_20 ;
V_11 = F_22 ( V_35 , & V_57 ) ;
if ( V_11 )
goto V_58;
if ( V_59 ) {
F_23 ( V_35 , stdout ) ;
goto V_58;
}
if ( V_60 > 3 )
F_24 ( V_35 , stdout ) ;
if ( V_60 > 2 )
F_25 ( V_35 , stdout ) ;
V_53 = 0 ;
F_26 (pos, &session->evlist->entries, node) {
struct V_19 * V_19 = & V_52 -> V_19 ;
T_2 V_61 = V_19 -> V_28 . V_62 [ V_31 ] ;
if ( V_61 > 0 ) {
V_53 += V_61 ;
F_27 ( V_19 ) ;
F_28 ( V_19 ) ;
F_14 ( V_19 , V_52 -> V_26 ) ;
}
}
if ( V_53 == 0 ) {
F_29 ( L_4 , V_54 ) ;
goto V_58;
}
V_58:
return V_11 ;
}
int F_30 ( int V_63 , const char * * V_64 , const char * T_3 V_65 )
{
V_63 = F_31 ( V_63 , V_64 , V_66 , V_67 , 0 ) ;
if ( V_68 )
V_51 = 0 ;
else if ( V_69 )
V_51 = 1 ;
F_32 ( true ) ;
V_70 . V_71 = sizeof( struct V_22 ) ;
V_70 . V_72 = true ;
if ( F_33 () < 0 )
return - 1 ;
F_34 ( V_67 , V_66 ) ;
if ( V_63 ) {
if ( V_63 > 1 )
F_35 ( V_67 , V_66 ) ;
V_12 = V_64 [ 0 ] ;
}
if ( V_73 && * V_73 == '.' ) {
F_36 ( L_5 ) ;
return - 1 ;
}
return F_20 () ;
}
