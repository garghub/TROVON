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
if ( V_38 && ! F_12 ( V_4 -> V_39 , V_40 ) )
return 0 ;
if ( ! V_8 . V_41 &&
F_1 ( V_35 -> V_2 , V_4 , V_6 , & V_8 ) ) {
F_11 ( L_2
L_3 ) ;
return - 1 ;
}
return 0 ;
}
static int F_13 ( struct V_9 * V_10 , int V_42 )
{
return F_14 ( V_10 -> V_21 . V_13 , V_10 -> V_21 . V_16 , V_42 ,
V_43 , V_44 , 0 , 0 ) ;
}
static void F_15 ( struct V_19 * V_45 , int V_42 )
{
struct V_15 * V_46 = F_16 ( & V_45 -> V_47 ) , * V_48 ;
int V_49 = V_50 ;
while ( V_46 ) {
struct V_9 * V_10 = F_17 ( V_46 , struct V_9 , V_15 ) ;
struct V_22 * V_23 ;
if ( V_10 -> V_21 . V_13 == NULL || V_10 -> V_21 . V_16 -> V_17 -> V_51 )
goto V_52;
V_23 = F_5 ( V_10 -> V_21 . V_13 ) ;
if ( V_23 -> V_24 == NULL ) {
V_52:
if ( V_49 == V_53 )
V_46 = F_18 ( V_46 ) ;
else
V_46 = F_19 ( V_46 ) ;
continue;
}
if ( V_54 > 0 ) {
V_49 = F_20 ( V_10 , V_42 ) ;
switch ( V_49 ) {
case V_50 :
V_48 = F_19 ( V_46 ) ;
break;
case V_53 :
V_48 = F_18 ( V_46 ) ;
break;
default:
return;
}
if ( V_48 != NULL )
V_46 = V_48 ;
} else {
F_13 ( V_10 , V_42 ) ;
V_46 = F_19 ( V_46 ) ;
free ( V_23 -> V_24 ) ;
V_23 -> V_24 = NULL ;
}
}
}
static int F_21 ( void )
{
int V_11 ;
struct V_34 * V_35 ;
struct V_5 * V_55 ;
T_1 V_56 ;
V_35 = F_22 ( V_57 , V_58 , V_59 , false , & V_60 ) ;
if ( V_35 == NULL )
return - V_20 ;
if ( V_38 ) {
V_11 = F_23 ( V_35 , V_38 , V_40 ) ;
if ( V_11 )
goto V_61;
}
V_11 = F_24 ( V_35 , & V_60 ) ;
if ( V_11 )
goto V_61;
if ( V_62 ) {
F_25 ( V_35 , stdout ) ;
goto V_61;
}
if ( V_63 > 3 )
F_26 ( V_35 , stdout ) ;
if ( V_63 > 2 )
F_27 ( V_35 , stdout ) ;
V_56 = 0 ;
F_28 (pos, &session->evlist->entries, node) {
struct V_19 * V_19 = & V_55 -> V_19 ;
T_2 V_64 = V_19 -> V_28 . V_65 [ V_31 ] ;
if ( V_64 > 0 ) {
V_56 += V_64 ;
F_29 ( V_19 ) ;
F_30 ( V_19 ) ;
F_15 ( V_19 , V_55 -> V_26 ) ;
}
}
if ( V_56 == 0 ) {
F_31 ( L_4 , V_57 ) ;
goto V_61;
}
V_61:
return V_11 ;
}
int F_32 ( int V_66 , const char * * V_67 , const char * T_3 V_68 )
{
V_66 = F_33 ( V_66 , V_67 , V_69 , V_70 , 0 ) ;
if ( V_71 )
V_54 = 0 ;
else if ( V_72 )
V_54 = 1 ;
F_34 ( true ) ;
V_73 . V_74 = sizeof( struct V_22 ) ;
V_73 . V_75 = true ;
if ( F_35 () < 0 )
return - 1 ;
F_36 ( V_70 , V_69 ) ;
if ( V_66 ) {
if ( V_66 > 1 )
F_37 ( V_70 , V_69 ) ;
V_12 = V_67 [ 0 ] ;
}
if ( V_76 && * V_76 == '.' ) {
F_38 ( L_5 ) ;
return - 1 ;
}
return F_21 () ;
}
