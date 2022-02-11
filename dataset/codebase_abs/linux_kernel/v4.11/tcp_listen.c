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
bool V_18 = ( V_16 -> V_19 < V_16 -> V_20 ) ;
int V_21 = F_4 ( int , 1 , V_16 -> V_22 ) ;
if ( ! V_18 ) {
if ( V_21 == 1 )
F_5 ( & V_16 -> V_23 [ 0 ] ) ;
return NULL ;
}
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
struct V_24 * V_25 = & V_16 -> V_23 [ V_17 ] ;
if ( F_6 ( V_25 , V_26 ,
V_27 ) ||
F_6 ( V_25 , V_28 ,
V_27 ) ) {
return V_25 -> V_29 ;
}
}
return NULL ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_1 * V_30 = NULL ;
struct V_15 * V_16 ;
int V_6 ;
struct V_31 * V_32 ;
struct V_14 * V_33 = NULL ;
int V_34 ;
struct V_24 * V_25 ;
if ( ! V_2 )
return - V_35 ;
V_6 = F_8 ( F_9 ( V_2 -> V_36 ) , V_2 -> V_36 -> V_37 ,
V_2 -> V_36 -> V_38 , V_2 -> V_36 -> V_39 ,
& V_30 ) ;
if ( V_6 )
goto V_40;
V_30 -> type = V_2 -> type ;
V_30 -> V_41 = V_2 -> V_41 ;
V_6 = V_2 -> V_41 -> V_42 ( V_2 , V_30 , V_43 , true ) ;
if ( V_6 < 0 )
goto V_40;
V_6 = F_1 ( V_30 ) ;
if ( V_6 < 0 )
goto V_40;
F_10 ( V_30 ) ;
V_32 = F_11 ( V_30 -> V_36 ) ;
F_12 ( L_1 ,
& V_32 -> V_44 , F_13 ( V_32 -> V_45 ) ,
& V_32 -> V_46 , F_13 ( V_32 -> V_47 ) ) ;
V_16 = F_14 ( F_9 ( V_2 -> V_36 ) ,
V_32 -> V_44 , V_32 -> V_46 ,
& V_48 , V_49 ) ;
if ( F_15 ( V_16 ) ) {
V_6 = F_16 ( V_16 ) ;
goto V_40;
}
V_33 = F_3 ( V_16 ) ;
if ( ! V_33 )
goto V_50;
F_17 ( & V_33 -> V_51 ) ;
V_25 = V_33 -> V_52 ;
V_34 = F_18 ( V_25 ) ;
F_19 ( V_34 == V_53 ) ;
if ( V_34 != V_27 && V_34 != V_28 )
goto V_50;
if ( V_33 -> V_54 ) {
if ( F_20 ( V_32 -> V_44 ) < F_20 ( V_32 -> V_46 ) ||
! V_25 -> V_55 ) {
goto V_50;
} else {
F_21 ( V_30 , V_25 ) ;
V_25 -> V_55 = 0 ;
F_22 ( V_25 , V_56 ) ;
}
} else {
F_23 ( V_30 , V_25 ) ;
F_22 ( V_25 , V_27 ) ;
}
V_30 = NULL ;
V_6 = 0 ;
goto V_40;
V_50:
F_24 ( V_30 , V_57 ) ;
V_6 = 0 ;
V_40:
if ( V_33 )
F_25 ( & V_33 -> V_51 ) ;
if ( V_30 )
F_26 ( V_30 ) ;
return V_6 ;
}
void F_27 ( struct V_2 * V_36 )
{
void (* F_28)( struct V_2 * V_36 );
F_12 ( L_2 , V_36 ) ;
F_29 ( & V_36 -> V_58 ) ;
F_28 = V_36 -> V_59 ;
if ( ! F_28 ) {
F_28 = V_36 -> V_60 ;
goto V_40;
}
if ( V_36 -> V_61 == V_62 )
F_30 ( V_36 ) ;
else
F_28 = F_31 ( F_9 ( V_36 ) ) ;
V_40:
F_32 ( & V_36 -> V_58 ) ;
if ( F_28 )
F_28 ( V_36 ) ;
}
struct V_1 * F_33 ( struct V_63 * V_63 )
{
struct V_64 sin ;
struct V_1 * V_2 = NULL ;
int V_6 ;
V_6 = F_8 ( V_63 , V_65 , V_66 , V_10 , & V_2 ) ;
if ( V_6 < 0 )
goto V_40;
V_2 -> V_36 -> V_67 = V_68 ;
F_34 ( V_2 ) ;
F_35 ( & V_2 -> V_36 -> V_58 ) ;
V_2 -> V_36 -> V_59 = V_2 -> V_36 -> V_60 ;
V_2 -> V_36 -> V_60 = F_27 ;
F_36 ( & V_2 -> V_36 -> V_58 ) ;
sin . V_69 = V_65 ;
sin . V_70 . V_71 = ( V_72 V_73 ) F_37 ( V_74 ) ;
sin . V_75 = ( V_72 V_76 ) F_38 ( V_77 ) ;
V_6 = V_2 -> V_41 -> V_78 ( V_2 , (struct V_79 * ) & sin , sizeof( sin ) ) ;
if ( V_6 < 0 )
goto V_40;
V_6 = V_2 -> V_41 -> V_80 ( V_2 , 64 ) ;
if ( V_6 < 0 )
goto V_40;
return V_2 ;
V_40:
if ( V_2 )
F_26 ( V_2 ) ;
return NULL ;
}
void F_39 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
struct V_2 * V_36 ;
if ( ! V_2 )
return;
V_36 = V_2 -> V_36 ;
F_40 ( V_36 ) ;
F_35 ( & V_36 -> V_58 ) ;
if ( V_36 -> V_59 ) {
V_36 -> V_60 = V_36 -> V_59 ;
V_36 -> V_59 = NULL ;
}
F_36 ( & V_36 -> V_58 ) ;
F_41 ( V_36 ) ;
F_42 ( V_83 ) ;
F_43 ( V_82 ) ;
F_26 ( V_2 ) ;
}
