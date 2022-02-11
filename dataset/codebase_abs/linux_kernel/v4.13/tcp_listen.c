int F_1 ( struct V_1 * V_2 )
{
int V_3 = 5 ;
int V_4 = 5 ;
int V_5 = 1 ;
int V_6 = 0 ;
V_6 = F_2 ( V_2 , V_7 , V_8 ,
( char * ) & V_5 , sizeof( V_5 ) ) ;
if ( V_6 < 0 )
goto V_9;
V_6 = F_2 ( V_2 , V_10 , V_11 ,
( char * ) & V_4 , sizeof( V_4 ) ) ;
if ( V_6 < 0 )
goto V_9;
V_6 = F_2 ( V_2 , V_10 , V_12 ,
( char * ) & V_3 , sizeof( V_3 ) ) ;
if ( V_6 < 0 )
goto V_9;
V_6 = F_2 ( V_2 , V_10 , V_13 ,
( char * ) & V_3 , sizeof( V_3 ) ) ;
V_9:
return V_6 ;
}
static
struct V_14 * F_3 ( struct V_15 * V_16 )
{
int V_17 ;
bool V_18 = F_4 ( V_16 -> V_19 , V_16 -> V_20 ) ;
int V_21 = F_5 ( int , 1 , V_16 -> V_22 ) ;
if ( ! V_18 ) {
if ( V_21 == 1 )
F_6 ( & V_16 -> V_23 [ 0 ] ) ;
return NULL ;
}
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
struct V_24 * V_25 = & V_16 -> V_23 [ V_17 ] ;
if ( F_7 ( V_25 , V_26 ,
V_27 ) ||
F_7 ( V_25 , V_28 ,
V_27 ) ) {
return V_25 -> V_29 ;
}
}
return NULL ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_30 V_31 = {
. V_32 = 1 ,
. V_33 = 0 ,
} ;
F_2 ( V_2 , V_7 , V_34 ,
( char * ) & V_31 , sizeof( V_31 ) ) ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_1 * V_35 = NULL ;
struct V_15 * V_16 ;
int V_6 ;
struct V_36 * V_37 ;
struct V_14 * V_38 = NULL ;
int V_39 ;
struct V_24 * V_25 ;
if ( ! V_2 )
return - V_40 ;
V_6 = F_10 ( V_2 -> V_41 -> V_42 ,
V_2 -> V_41 -> V_43 , V_2 -> V_41 -> V_44 ,
& V_35 ) ;
if ( V_6 )
goto V_45;
V_35 -> type = V_2 -> type ;
V_35 -> V_46 = V_2 -> V_46 ;
V_6 = V_2 -> V_46 -> V_47 ( V_2 , V_35 , V_48 , true ) ;
if ( V_6 < 0 )
goto V_45;
V_6 = F_1 ( V_35 ) ;
if ( V_6 < 0 )
goto V_45;
F_11 ( V_35 ) ;
V_37 = F_12 ( V_35 -> V_41 ) ;
F_13 ( L_1 ,
& V_37 -> V_49 , F_14 ( V_37 -> V_50 ) ,
& V_37 -> V_51 , F_14 ( V_37 -> V_52 ) ) ;
V_16 = F_15 ( F_16 ( V_2 -> V_41 ) ,
V_37 -> V_49 , V_37 -> V_51 ,
& V_53 , V_54 ) ;
if ( F_17 ( V_16 ) ) {
V_6 = F_18 ( V_16 ) ;
goto V_45;
}
V_38 = F_3 ( V_16 ) ;
if ( ! V_38 )
goto V_55;
F_19 ( & V_38 -> V_56 ) ;
V_25 = V_38 -> V_57 ;
V_39 = F_20 ( V_25 ) ;
F_21 ( V_39 == V_58 ) ;
if ( V_39 != V_27 && V_39 != V_28 )
goto V_55;
if ( V_38 -> V_59 ) {
F_22 ( V_35 , V_25 ) ;
F_23 ( V_25 , V_60 ) ;
} else {
F_24 ( V_35 , V_25 ) ;
F_23 ( V_25 , V_27 ) ;
}
V_35 = NULL ;
V_6 = 0 ;
if ( V_16 -> V_22 == 0 )
F_25 ( V_25 -> V_61 , V_25 -> V_62 ) ;
goto V_45;
V_55:
F_8 ( V_35 ) ;
F_26 ( V_35 , V_63 ) ;
V_6 = 0 ;
V_45:
if ( V_38 )
F_27 ( & V_38 -> V_56 ) ;
if ( V_35 )
F_28 ( V_35 ) ;
return V_6 ;
}
void F_29 ( struct V_2 * V_41 )
{
void (* F_30)( struct V_2 * V_41 );
F_13 ( L_2 , V_41 ) ;
F_31 ( & V_41 -> V_64 ) ;
F_30 = V_41 -> V_65 ;
if ( ! F_30 ) {
F_30 = V_41 -> V_66 ;
goto V_45;
}
if ( V_41 -> V_67 == V_68 )
F_32 ( V_41 ) ;
else
F_30 = F_33 ( F_16 ( V_41 ) ) ;
V_45:
F_34 ( & V_41 -> V_64 ) ;
if ( F_30 )
F_30 ( V_41 ) ;
}
struct V_1 * F_35 ( struct V_69 * V_69 )
{
struct V_70 sin ;
struct V_1 * V_2 = NULL ;
int V_6 ;
V_6 = F_36 ( V_69 , V_71 , V_72 , V_10 , & V_2 ) ;
if ( V_6 < 0 )
goto V_45;
V_2 -> V_41 -> V_73 = V_74 ;
F_37 ( V_2 ) ;
F_38 ( & V_2 -> V_41 -> V_64 ) ;
V_2 -> V_41 -> V_65 = V_2 -> V_41 -> V_66 ;
V_2 -> V_41 -> V_66 = F_29 ;
F_39 ( & V_2 -> V_41 -> V_64 ) ;
sin . V_75 = V_71 ;
sin . V_76 . V_77 = ( V_78 V_79 ) F_40 ( V_80 ) ;
sin . V_81 = ( V_78 V_82 ) F_41 ( V_83 ) ;
V_6 = V_2 -> V_46 -> V_84 ( V_2 , (struct V_85 * ) & sin , sizeof( sin ) ) ;
if ( V_6 < 0 )
goto V_45;
V_6 = V_2 -> V_46 -> V_86 ( V_2 , 64 ) ;
if ( V_6 < 0 )
goto V_45;
return V_2 ;
V_45:
if ( V_2 )
F_28 ( V_2 ) ;
return NULL ;
}
void F_42 ( struct V_1 * V_2 , struct V_87 * V_88 )
{
struct V_2 * V_41 ;
if ( ! V_2 )
return;
V_41 = V_2 -> V_41 ;
F_43 ( V_41 ) ;
F_38 ( & V_41 -> V_64 ) ;
if ( V_41 -> V_65 ) {
V_41 -> V_66 = V_41 -> V_65 ;
V_41 -> V_65 = NULL ;
}
F_39 ( & V_41 -> V_64 ) ;
F_44 ( V_41 ) ;
F_45 ( V_89 ) ;
F_46 ( V_88 ) ;
F_28 ( V_2 ) ;
}
