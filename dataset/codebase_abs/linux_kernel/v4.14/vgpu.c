void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , F_3 ( V_3 ) ) = V_4 ;
F_4 ( V_2 , F_3 ( V_5 ) ) = 1 ;
F_4 ( V_2 , F_3 ( V_6 ) ) = 0 ;
F_4 ( V_2 , F_3 ( V_7 ) ) = 0 ;
F_4 ( V_2 , F_3 ( V_8 ) ) = V_2 -> V_9 ;
F_4 ( V_2 , F_3 ( V_10 ) ) = V_11 ;
F_4 ( V_2 , F_3 ( V_12 . V_13 . V_14 ) ) =
F_5 ( V_2 ) ;
F_4 ( V_2 , F_3 ( V_12 . V_13 . V_15 ) ) =
F_6 ( V_2 ) ;
F_4 ( V_2 , F_3 ( V_12 . V_16 . V_14 ) ) =
F_7 ( V_2 ) ;
F_4 ( V_2 , F_3 ( V_12 . V_16 . V_15 ) ) =
F_8 ( V_2 ) ;
F_4 ( V_2 , F_3 ( V_12 . V_17 ) ) = F_9 ( V_2 ) ;
F_10 ( L_1 , V_2 -> V_9 ) ;
F_10 ( L_2 ,
F_5 ( V_2 ) , F_6 ( V_2 ) ) ;
F_10 ( L_3 ,
F_7 ( V_2 ) , F_8 ( V_2 ) ) ;
F_10 ( L_4 , F_9 ( V_2 ) ) ;
F_11 ( sizeof( struct V_18 ) != V_19 ) ;
}
int F_12 ( struct V_20 * V_21 )
{
unsigned int V_22 ;
unsigned int V_23 , V_24 , V_25 ;
unsigned int V_26 ;
V_24 = F_13 ( V_21 ) - V_27 ;
V_25 = F_14 ( V_21 ) - V_28 ;
V_22 = sizeof( V_29 ) / sizeof( V_29 [ 0 ] ) ;
V_21 -> V_30 = F_15 ( V_22 * sizeof( struct V_31 ) ,
V_32 ) ;
if ( ! V_21 -> V_30 )
return - V_33 ;
V_26 = F_16 ( 32 ) ;
for ( V_23 = 0 ; V_23 < V_22 ; ++ V_23 ) {
if ( V_24 / V_29 [ V_23 ] . V_34 == 0 )
break;
V_21 -> V_30 [ V_23 ] . V_35 = V_29 [ V_23 ] . V_34 ;
V_21 -> V_30 [ V_23 ] . V_36 = V_29 [ V_23 ] . V_37 ;
V_21 -> V_30 [ V_23 ] . V_38 = V_29 [ V_23 ] . V_38 ;
if ( V_29 [ V_23 ] . V_39 < 1 ||
V_29 [ V_23 ] . V_39 > V_40 )
return - V_41 ;
V_21 -> V_30 [ V_23 ] . V_39 = V_29 [ V_23 ] . V_39 ;
V_21 -> V_30 [ V_23 ] . V_42 = V_29 [ V_23 ] . V_43 ;
V_21 -> V_30 [ V_23 ] . V_44 = F_17 ( V_24 / V_29 [ V_23 ] . V_34 ,
V_25 / V_29 [ V_23 ] . V_37 ) ;
if ( F_18 ( V_21 -> V_45 ) )
sprintf ( V_21 -> V_30 [ V_23 ] . V_46 , L_5 ,
V_29 [ V_23 ] . V_46 ) ;
else if ( F_19 ( V_21 -> V_45 ) )
sprintf ( V_21 -> V_30 [ V_23 ] . V_46 , L_6 ,
V_29 [ V_23 ] . V_46 ) ;
F_10 ( L_7 ,
V_23 , V_21 -> V_30 [ V_23 ] . V_46 ,
V_21 -> V_30 [ V_23 ] . V_44 ,
V_21 -> V_30 [ V_23 ] . V_35 ,
V_21 -> V_30 [ V_23 ] . V_36 , V_21 -> V_30 [ V_23 ] . V_38 ,
V_21 -> V_30 [ V_23 ] . V_39 ,
F_20 ( V_21 -> V_30 [ V_23 ] . V_42 ) ) ;
}
V_21 -> V_22 = V_23 ;
return 0 ;
}
void F_21 ( struct V_20 * V_21 )
{
F_22 ( V_21 -> V_30 ) ;
}
static void F_23 ( struct V_20 * V_21 )
{
int V_23 ;
unsigned int V_47 , V_48 , V_49 ;
unsigned int V_50 , V_51 , V_52 ;
V_47 = F_13 ( V_21 ) - V_27 -
V_21 -> V_53 . V_54 ;
V_48 = F_14 ( V_21 ) - V_28 -
V_21 -> V_53 . V_55 ;
V_49 = F_24 ( V_21 ) - V_56 -
V_21 -> V_38 . V_57 ;
for ( V_23 = 0 ; V_23 < V_21 -> V_22 ; V_23 ++ ) {
V_50 = V_47 / V_21 -> V_30 [ V_23 ] . V_35 ;
V_51 = V_48 / V_21 -> V_30 [ V_23 ] . V_36 ;
V_52 = V_49 / V_21 -> V_30 [ V_23 ] . V_38 ;
V_21 -> V_30 [ V_23 ] . V_44 = F_17 ( F_17 ( V_50 , V_51 ) ,
V_52 ) ;
F_10 ( L_8 ,
V_23 , V_21 -> V_30 [ V_23 ] . V_46 ,
V_21 -> V_30 [ V_23 ] . V_44 , V_21 -> V_30 [ V_23 ] . V_35 ,
V_21 -> V_30 [ V_23 ] . V_36 , V_21 -> V_30 [ V_23 ] . V_38 ) ;
}
}
void F_25 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_21 -> V_58 ) ;
V_2 -> V_59 = true ;
F_27 ( & V_2 -> V_21 -> V_58 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
F_26 ( & V_21 -> V_58 ) ;
V_2 -> V_59 = false ;
if ( F_29 ( & V_2 -> V_60 ) ) {
F_27 ( & V_21 -> V_58 ) ;
F_30 ( V_2 ) ;
F_26 ( & V_21 -> V_58 ) ;
}
F_31 ( V_2 ) ;
F_27 ( & V_21 -> V_58 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
F_26 ( & V_21 -> V_58 ) ;
F_33 ( V_2 -> V_59 , L_9 ) ;
F_34 ( & V_21 -> V_61 , V_2 -> V_9 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
F_23 ( V_21 ) ;
F_27 ( & V_21 -> V_58 ) ;
}
struct V_1 * F_45 ( struct V_20 * V_21 )
{
struct V_1 * V_2 ;
enum V_62 V_23 ;
int V_63 ;
V_2 = F_46 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
return F_47 ( - V_33 ) ;
V_2 -> V_9 = V_64 ;
V_2 -> V_21 = V_21 ;
for ( V_23 = 0 ; V_23 < V_65 ; V_23 ++ )
F_48 ( & V_2 -> V_66 [ V_23 ] ) ;
V_63 = F_49 ( V_2 ) ;
if ( V_63 )
goto V_67;
V_2 -> V_59 = false ;
return V_2 ;
V_67:
F_44 ( V_2 ) ;
return F_47 ( V_63 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
F_35 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static struct V_1 * F_51 ( struct V_20 * V_21 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 ;
int V_63 ;
F_10 ( L_10 ,
V_69 -> V_70 , V_69 -> V_71 , V_69 -> V_72 ,
V_69 -> V_73 ) ;
V_2 = F_46 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
return F_47 ( - V_33 ) ;
F_26 ( & V_21 -> V_58 ) ;
V_63 = F_52 ( & V_21 -> V_61 , V_2 , V_64 + 1 , V_74 ,
V_32 ) ;
if ( V_63 < 0 )
goto V_67;
V_2 -> V_9 = V_63 ;
V_2 -> V_70 = V_69 -> V_70 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_75 . V_39 = V_69 -> V_39 ;
F_53 ( V_2 -> V_76 , V_65 ) ;
F_54 ( V_2 , V_69 -> V_77 ) ;
V_63 = F_55 ( V_2 ) ;
if ( V_63 )
goto V_78;
V_63 = F_56 ( V_2 , V_69 ) ;
if ( V_63 )
goto V_79;
F_1 ( V_2 ) ;
V_63 = F_57 ( V_2 ) ;
if ( V_63 )
goto V_80;
V_63 = F_58 ( V_2 ) ;
if ( V_63 )
goto V_81;
V_63 = F_59 ( V_2 , V_69 -> V_42 ) ;
if ( V_63 )
goto V_82;
V_63 = F_60 ( V_2 ) ;
if ( V_63 )
goto V_83;
V_63 = F_61 ( V_2 ) ;
if ( V_63 )
goto V_84;
V_63 = F_49 ( V_2 ) ;
if ( V_63 )
goto V_85;
F_27 ( & V_21 -> V_58 ) ;
return V_2 ;
V_85:
F_36 ( V_2 ) ;
V_84:
F_37 ( V_2 ) ;
V_83:
F_38 ( V_2 ) ;
V_82:
F_40 ( V_2 ) ;
V_81:
F_41 ( V_2 ) ;
V_80:
F_42 ( V_2 ) ;
V_79:
F_43 ( V_2 ) ;
V_78:
F_34 ( & V_21 -> V_61 , V_2 -> V_9 ) ;
V_67:
F_44 ( V_2 ) ;
F_27 ( & V_21 -> V_58 ) ;
return F_47 ( V_63 ) ;
}
struct V_1 * F_62 ( struct V_20 * V_21 ,
struct V_31 * type )
{
struct V_68 V_69 ;
struct V_1 * V_2 ;
V_69 . V_70 = 0 ;
V_69 . V_77 = 1 ;
V_69 . V_71 = type -> V_35 ;
V_69 . V_72 = type -> V_36 ;
V_69 . V_73 = type -> V_38 ;
V_69 . V_39 = type -> V_39 ;
V_69 . V_42 = type -> V_42 ;
V_69 . V_71 = F_63 ( V_69 . V_71 ) ;
V_69 . V_72 = F_63 ( V_69 . V_72 ) ;
V_2 = F_51 ( V_21 , & V_69 ) ;
if ( F_64 ( V_2 ) )
return V_2 ;
F_23 ( V_21 ) ;
return V_2 ;
}
void F_65 ( struct V_1 * V_2 , bool V_86 ,
unsigned int V_87 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
struct V_88 * V_89 = & V_21 -> V_89 ;
unsigned int V_90 = V_86 ? V_91 : V_87 ;
F_10 ( L_11 ) ;
F_10 ( L_12 ,
V_2 -> V_9 , V_86 , V_87 ) ;
V_2 -> V_90 = V_90 ;
F_31 ( V_2 ) ;
if ( V_89 -> V_92 == NULL ) {
F_27 ( & V_21 -> V_58 ) ;
F_30 ( V_2 ) ;
F_26 ( & V_21 -> V_58 ) ;
}
F_66 ( V_2 , V_90 ) ;
if ( V_87 == V_91 || V_86 ) {
if ( V_86 ) {
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
}
F_69 ( V_2 , V_86 ) ;
F_1 ( V_2 ) ;
F_70 ( V_2 ) ;
if ( V_86 ) {
F_71 ( V_2 ) ;
V_2 -> V_93 = false ;
V_2 -> V_94 = false ;
}
}
V_2 -> V_90 = 0 ;
F_10 ( L_13 , V_2 -> V_9 ) ;
F_10 ( L_11 ) ;
}
void F_72 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_21 -> V_58 ) ;
F_65 ( V_2 , true , 0 ) ;
F_27 ( & V_2 -> V_21 -> V_58 ) ;
}
