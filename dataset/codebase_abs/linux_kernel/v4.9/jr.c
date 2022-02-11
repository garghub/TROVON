static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = 100000 ;
F_3 ( & V_4 -> V_6 -> V_7 , 0 , V_8 ) ;
F_4 ( & V_4 -> V_6 -> V_9 , V_10 ) ;
while ( ( ( F_5 ( & V_4 -> V_6 -> V_11 ) & V_12 ) ==
V_13 ) && -- V_5 )
F_6 () ;
if ( ( F_5 ( & V_4 -> V_6 -> V_11 ) & V_12 ) !=
V_14 || V_5 == 0 ) {
F_7 ( V_2 , L_1 , V_4 -> V_15 ) ;
return - V_16 ;
}
V_5 = 100000 ;
F_4 ( & V_4 -> V_6 -> V_9 , V_10 ) ;
while ( ( F_5 ( & V_4 -> V_6 -> V_9 ) & V_10 ) && -- V_5 )
F_6 () ;
if ( V_5 == 0 ) {
F_7 ( V_2 , L_2 , V_4 -> V_15 ) ;
return - V_16 ;
}
F_3 ( & V_4 -> V_6 -> V_7 , V_8 , 0 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_17 , V_18 ;
int V_19 ;
V_19 = F_1 ( V_2 ) ;
F_9 ( V_4 -> V_20 , V_2 ) ;
V_17 = F_10 ( & V_4 -> V_6 -> V_21 ) ;
V_18 = F_10 ( & V_4 -> V_6 -> V_22 ) ;
F_11 ( V_2 , sizeof( T_1 ) * V_23 ,
V_4 -> V_24 , V_17 ) ;
F_11 ( V_2 , sizeof( struct V_25 ) * V_23 ,
V_4 -> V_26 , V_18 ) ;
F_12 ( V_4 -> V_27 ) ;
return V_19 ;
}
static int F_13 ( struct V_28 * V_29 )
{
int V_19 ;
struct V_1 * V_30 ;
struct V_3 * V_31 ;
V_30 = & V_29 -> V_2 ;
V_31 = F_2 ( V_30 ) ;
if ( F_14 ( & V_31 -> V_32 ) ) {
F_7 ( V_30 , L_3 ) ;
return - V_33 ;
}
F_15 ( & V_34 . V_35 ) ;
F_16 ( & V_31 -> V_36 ) ;
F_17 ( & V_34 . V_35 ) ;
V_19 = F_8 ( V_30 ) ;
if ( V_19 )
F_7 ( V_30 , L_4 ) ;
F_18 ( V_31 -> V_20 ) ;
return V_19 ;
}
static T_2 F_19 ( int V_20 , void * V_37 )
{
struct V_1 * V_2 = V_37 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_38 ;
V_38 = F_5 ( & V_4 -> V_6 -> V_11 ) ;
if ( ! V_38 )
return V_39 ;
if ( V_38 & V_40 ) {
F_7 ( V_2 , L_5 , V_38 ) ;
F_20 () ;
}
F_3 ( & V_4 -> V_6 -> V_7 , 0 , V_8 ) ;
F_4 ( & V_4 -> V_6 -> V_11 , V_38 ) ;
return V_41 ;
}
static T_2 F_21 ( int V_20 , void * V_37 )
{
int V_42 , V_43 , V_44 , V_45 , V_46 ;
struct V_1 * V_2 = V_37 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
void (* F_22)( struct V_1 * V_2 , T_3 * V_47 , T_3 V_48 , void * V_49 );
T_3 * V_50 , V_51 ;
void * V_52 ;
while ( F_5 ( & V_4 -> V_6 -> V_53 ) ) {
V_45 = F_23 ( V_4 -> V_45 ) ;
F_15 ( & V_4 -> V_54 ) ;
V_43 = V_46 = V_4 -> V_46 ;
V_42 = V_4 -> V_55 ;
for ( V_44 = 0 ; F_24 ( V_45 , V_46 + V_44 , V_23 ) >= 1 ; V_44 ++ ) {
V_43 = ( V_46 + V_44 ) & ( V_23 - 1 ) ;
if ( V_4 -> V_26 [ V_42 ] . V_47 ==
F_25 ( V_4 -> V_27 [ V_43 ] . V_56 ) )
break;
}
F_26 ( F_24 ( V_45 , V_46 + V_44 , V_23 ) <= 0 ) ;
F_27 ( V_2 , V_4 -> V_26 [ V_42 ] . V_47 ,
V_4 -> V_27 [ V_43 ] . V_57 ,
V_58 ) ;
V_4 -> V_27 [ V_43 ] . V_56 = 0 ;
F_22 = V_4 -> V_27 [ V_43 ] . V_59 ;
V_52 = V_4 -> V_27 [ V_43 ] . V_60 ;
V_50 = V_4 -> V_27 [ V_43 ] . V_61 ;
V_51 = F_28 ( V_4 -> V_26 [ V_42 ] . V_62 ) ;
F_29 () ;
F_4 ( & V_4 -> V_6 -> V_63 , 1 ) ;
V_4 -> V_55 = ( V_4 -> V_55 + 1 ) &
( V_23 - 1 ) ;
if ( V_43 == V_46 ) {
do {
V_46 = ( V_46 + 1 ) & ( V_23 - 1 ) ;
} while ( F_24 ( V_45 , V_46 , V_23 ) >= 1 &&
V_4 -> V_27 [ V_46 ] . V_56 == 0 );
V_4 -> V_46 = V_46 ;
}
F_17 ( & V_4 -> V_54 ) ;
F_22 ( V_2 , V_50 , V_51 , V_52 ) ;
}
F_3 ( & V_4 -> V_6 -> V_7 , V_8 , 0 ) ;
return V_64 ;
}
struct V_1 * F_30 ( void )
{
struct V_3 * V_31 , * V_65 = NULL ;
struct V_1 * V_2 = F_31 ( - V_66 ) ;
int V_67 = V_68 ;
int V_69 ;
F_15 ( & V_34 . V_35 ) ;
if ( F_32 ( & V_34 . V_70 ) ) {
F_17 ( & V_34 . V_35 ) ;
return F_31 ( - V_66 ) ;
}
F_33 (jrpriv, &driver_data.jr_list, list_node) {
V_69 = F_14 ( & V_31 -> V_32 ) ;
if ( V_69 < V_67 ) {
V_67 = V_69 ;
V_65 = V_31 ;
}
if ( ! V_67 )
break;
}
if ( V_65 ) {
F_34 ( & V_65 -> V_32 ) ;
V_2 = V_65 -> V_2 ;
}
F_17 ( & V_34 . V_35 ) ;
return V_2 ;
}
void F_35 ( struct V_1 * V_71 )
{
struct V_3 * V_31 = F_2 ( V_71 ) ;
F_36 ( & V_31 -> V_32 ) ;
}
int F_37 ( struct V_1 * V_2 , T_3 * V_47 ,
void (* F_38)( struct V_1 * V_2 , T_3 * V_47 ,
T_3 V_48 , void * V_72 ) ,
void * V_72 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_73 * V_74 ;
int V_45 , V_46 , V_57 ;
T_1 V_75 ;
V_57 = ( F_28 ( * V_47 ) & V_76 ) * sizeof( T_3 ) ;
V_75 = F_39 ( V_2 , V_47 , V_57 , V_58 ) ;
if ( F_40 ( V_2 , V_75 ) ) {
F_7 ( V_2 , L_6 ) ;
return - V_16 ;
}
F_41 ( & V_4 -> V_77 ) ;
V_45 = V_4 -> V_45 ;
V_46 = F_23 ( V_4 -> V_46 ) ;
if ( ! F_5 ( & V_4 -> V_6 -> V_78 ) ||
F_42 ( V_45 , V_46 , V_23 ) <= 0 ) {
F_43 ( & V_4 -> V_77 ) ;
F_27 ( V_2 , V_75 , V_57 , V_58 ) ;
return - V_33 ;
}
V_74 = & V_4 -> V_27 [ V_45 ] ;
V_74 -> V_61 = V_47 ;
V_74 -> V_57 = V_57 ;
V_74 -> V_59 = ( void * ) F_38 ;
V_74 -> V_60 = V_72 ;
V_74 -> V_56 = V_75 ;
V_4 -> V_24 [ V_4 -> V_79 ] = F_44 ( V_75 ) ;
F_45 () ;
V_4 -> V_79 = ( V_4 -> V_79 + 1 ) &
( V_23 - 1 ) ;
V_4 -> V_45 = ( V_45 + 1 ) & ( V_23 - 1 ) ;
F_46 () ;
F_4 ( & V_4 -> V_6 -> V_80 , 1 ) ;
F_43 ( & V_4 -> V_77 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_17 , V_18 ;
int V_44 , error ;
V_4 = F_2 ( V_2 ) ;
error = F_48 ( V_4 -> V_20 , F_19 ,
F_21 , V_81 ,
F_49 ( V_2 ) , V_2 ) ;
if ( error ) {
F_7 ( V_2 , L_7 ,
V_4 -> V_15 , V_4 -> V_20 ) ;
goto V_82;
}
error = F_1 ( V_2 ) ;
if ( error )
goto V_83;
error = - V_84 ;
V_4 -> V_24 = F_50 ( V_2 , sizeof( * V_4 -> V_24 ) *
V_23 , & V_17 , V_85 ) ;
if ( ! V_4 -> V_24 )
goto V_83;
V_4 -> V_26 = F_50 ( V_2 , sizeof( * V_4 -> V_26 ) *
V_23 , & V_18 , V_85 ) ;
if ( ! V_4 -> V_26 )
goto V_86;
V_4 -> V_27 = F_51 ( V_23 , sizeof( * V_4 -> V_27 ) , V_85 ) ;
if ( ! V_4 -> V_27 )
goto V_87;
for ( V_44 = 0 ; V_44 < V_23 ; V_44 ++ )
V_4 -> V_27 [ V_44 ] . V_56 = ! 0 ;
V_4 -> V_79 = 0 ;
V_4 -> V_55 = 0 ;
V_4 -> V_45 = 0 ;
V_4 -> V_46 = 0 ;
F_52 ( & V_4 -> V_6 -> V_21 , V_17 ) ;
F_52 ( & V_4 -> V_6 -> V_22 , V_18 ) ;
F_4 ( & V_4 -> V_6 -> V_88 , V_23 ) ;
F_4 ( & V_4 -> V_6 -> V_89 , V_23 ) ;
V_4 -> V_90 = V_23 ;
F_53 ( & V_4 -> V_77 ) ;
F_53 ( & V_4 -> V_54 ) ;
F_3 ( & V_4 -> V_6 -> V_7 , 0 , V_91 |
( V_92 << V_93 ) |
( V_94 << V_95 ) ) ;
return 0 ;
V_87:
F_11 ( V_2 , sizeof( struct V_25 ) * V_23 ,
V_4 -> V_26 , V_18 ) ;
V_86:
F_11 ( V_2 , sizeof( T_1 ) * V_23 ,
V_4 -> V_24 , V_17 ) ;
F_7 ( V_2 , L_8 , V_4 -> V_15 ) ;
V_83:
F_9 ( V_4 -> V_20 , V_2 ) ;
V_82:
return error ;
}
static int F_54 ( struct V_28 * V_29 )
{
struct V_1 * V_30 ;
struct V_96 * V_97 ;
struct V_98 T_4 * V_99 ;
struct V_3 * V_31 ;
static int V_100 ;
int error ;
V_30 = & V_29 -> V_2 ;
V_31 = F_55 ( V_30 , sizeof( * V_31 ) , V_85 ) ;
if ( ! V_31 )
return - V_84 ;
F_56 ( V_30 , V_31 ) ;
V_31 -> V_15 = V_100 ++ ;
V_97 = V_29 -> V_2 . V_101 ;
V_99 = F_57 ( V_97 , 0 ) ;
if ( ! V_99 ) {
F_7 ( V_30 , L_9 ) ;
return - V_84 ;
}
V_31 -> V_6 = (struct V_98 V_102 * ) V_99 ;
if ( sizeof( T_1 ) == sizeof( V_103 ) )
if ( F_58 ( V_97 , L_10 ) )
F_59 ( V_30 , F_60 ( 40 ) ) ;
else
F_59 ( V_30 , F_60 ( 36 ) ) ;
else
F_59 ( V_30 , F_60 ( 32 ) ) ;
V_31 -> V_20 = F_61 ( V_97 , 0 ) ;
error = F_47 ( V_30 ) ;
if ( error ) {
F_18 ( V_31 -> V_20 ) ;
F_62 ( V_99 ) ;
return error ;
}
V_31 -> V_2 = V_30 ;
F_15 ( & V_34 . V_35 ) ;
F_63 ( & V_31 -> V_36 , & V_34 . V_70 ) ;
F_17 ( & V_34 . V_35 ) ;
F_64 ( & V_31 -> V_32 , 0 ) ;
return 0 ;
}
static int T_5 F_65 ( void )
{
F_53 ( & V_34 . V_35 ) ;
F_66 ( & V_34 . V_70 ) ;
return F_67 ( & V_104 ) ;
}
static void T_6 F_68 ( void )
{
F_69 ( & V_104 ) ;
}
