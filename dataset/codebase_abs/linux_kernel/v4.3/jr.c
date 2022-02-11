static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = 100000 ;
F_3 ( & V_4 -> V_6 -> V_7 , V_8 ) ;
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
F_8 ( & V_4 -> V_6 -> V_7 , V_8 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_17 , V_18 ;
int V_19 ;
V_19 = F_1 ( V_2 ) ;
F_10 ( & V_4 -> V_20 ) ;
F_11 ( V_4 -> V_21 , V_2 ) ;
V_17 = F_12 ( & V_4 -> V_6 -> V_22 ) ;
V_18 = F_12 ( & V_4 -> V_6 -> V_23 ) ;
F_13 ( V_2 , sizeof( T_1 ) * V_24 ,
V_4 -> V_25 , V_17 ) ;
F_13 ( V_2 , sizeof( struct V_26 ) * V_24 ,
V_4 -> V_27 , V_18 ) ;
F_14 ( V_4 -> V_28 ) ;
return V_19 ;
}
static int F_15 ( struct V_29 * V_30 )
{
int V_19 ;
struct V_1 * V_31 ;
struct V_3 * V_32 ;
V_31 = & V_30 -> V_2 ;
V_32 = F_2 ( V_31 ) ;
if ( F_16 ( & V_32 -> V_33 ) ) {
F_7 ( V_31 , L_3 ) ;
return - V_34 ;
}
F_17 ( & V_35 . V_36 ) ;
F_18 ( & V_32 -> V_37 ) ;
F_19 ( & V_35 . V_36 ) ;
V_19 = F_9 ( V_31 ) ;
if ( V_19 )
F_7 ( V_31 , L_4 ) ;
F_20 ( V_32 -> V_21 ) ;
return V_19 ;
}
static T_2 F_21 ( int V_21 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_39 ;
V_39 = F_5 ( & V_4 -> V_6 -> V_11 ) ;
if ( ! V_39 )
return V_40 ;
if ( V_39 & V_41 ) {
F_7 ( V_2 , L_5 , V_39 ) ;
F_22 () ;
}
F_3 ( & V_4 -> V_6 -> V_7 , V_8 ) ;
F_4 ( & V_4 -> V_6 -> V_11 , V_39 ) ;
F_23 () ;
F_24 ( & V_4 -> V_20 ) ;
F_25 () ;
return V_42 ;
}
static void F_26 ( unsigned long V_43 )
{
int V_44 , V_45 , V_46 , V_47 , V_48 ;
struct V_1 * V_2 = (struct V_1 * ) V_43 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
void (* F_27)( struct V_1 * V_2 , T_3 * V_49 , T_3 V_50 , void * V_51 );
T_3 * V_52 , V_53 ;
void * V_54 ;
while ( F_5 ( & V_4 -> V_6 -> V_55 ) ) {
V_47 = F_28 ( V_4 -> V_47 ) ;
F_17 ( & V_4 -> V_56 ) ;
V_45 = V_48 = V_4 -> V_48 ;
V_44 = V_4 -> V_57 ;
for ( V_46 = 0 ; F_29 ( V_47 , V_48 + V_46 , V_24 ) >= 1 ; V_46 ++ ) {
V_45 = ( V_48 + V_46 ) & ( V_24 - 1 ) ;
if ( V_4 -> V_27 [ V_44 ] . V_49 ==
V_4 -> V_28 [ V_45 ] . V_58 )
break;
}
F_30 ( F_29 ( V_47 , V_48 + V_46 , V_24 ) <= 0 ) ;
F_31 ( V_2 , V_4 -> V_27 [ V_44 ] . V_49 ,
V_4 -> V_28 [ V_45 ] . V_59 ,
V_60 ) ;
V_4 -> V_28 [ V_45 ] . V_58 = 0 ;
F_27 = V_4 -> V_28 [ V_45 ] . V_61 ;
V_54 = V_4 -> V_28 [ V_45 ] . V_62 ;
V_52 = V_4 -> V_28 [ V_45 ] . V_63 ;
V_53 = V_4 -> V_27 [ V_44 ] . V_64 ;
F_32 () ;
F_4 ( & V_4 -> V_6 -> V_65 , 1 ) ;
V_4 -> V_57 = ( V_4 -> V_57 + 1 ) &
( V_24 - 1 ) ;
if ( V_45 == V_48 ) {
do {
V_48 = ( V_48 + 1 ) & ( V_24 - 1 ) ;
} while ( F_29 ( V_47 , V_48 , V_24 ) >= 1 &&
V_4 -> V_28 [ V_48 ] . V_58 == 0 );
V_4 -> V_48 = V_48 ;
}
F_19 ( & V_4 -> V_56 ) ;
F_27 ( V_2 , V_52 , V_53 , V_54 ) ;
}
F_8 ( & V_4 -> V_6 -> V_7 , V_8 ) ;
}
struct V_1 * F_33 ( void )
{
struct V_3 * V_32 , * V_66 = NULL ;
struct V_1 * V_2 = NULL ;
int V_67 = V_68 ;
int V_69 ;
F_17 ( & V_35 . V_36 ) ;
if ( F_34 ( & V_35 . V_70 ) ) {
F_19 ( & V_35 . V_36 ) ;
return F_35 ( - V_71 ) ;
}
F_36 (jrpriv, &driver_data.jr_list, list_node) {
V_69 = F_16 ( & V_32 -> V_33 ) ;
if ( V_69 < V_67 ) {
V_67 = V_69 ;
V_66 = V_32 ;
}
if ( ! V_67 )
break;
}
if ( V_66 ) {
F_37 ( & V_66 -> V_33 ) ;
V_2 = V_66 -> V_2 ;
}
F_19 ( & V_35 . V_36 ) ;
return V_2 ;
}
void F_38 ( struct V_1 * V_72 )
{
struct V_3 * V_32 = F_2 ( V_72 ) ;
F_39 ( & V_32 -> V_33 ) ;
}
int F_40 ( struct V_1 * V_2 , T_3 * V_49 ,
void (* F_41)( struct V_1 * V_2 , T_3 * V_49 ,
T_3 V_50 , void * V_73 ) ,
void * V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_74 * V_75 ;
int V_47 , V_48 , V_59 ;
T_1 V_76 ;
V_59 = ( * V_49 & V_77 ) * sizeof( T_3 ) ;
V_76 = F_42 ( V_2 , V_49 , V_59 , V_60 ) ;
if ( F_43 ( V_2 , V_76 ) ) {
F_7 ( V_2 , L_6 ) ;
return - V_16 ;
}
F_44 ( & V_4 -> V_78 ) ;
V_47 = V_4 -> V_47 ;
V_48 = F_28 ( V_4 -> V_48 ) ;
if ( ! F_5 ( & V_4 -> V_6 -> V_79 ) ||
F_45 ( V_47 , V_48 , V_24 ) <= 0 ) {
F_46 ( & V_4 -> V_78 ) ;
F_31 ( V_2 , V_76 , V_59 , V_60 ) ;
return - V_34 ;
}
V_75 = & V_4 -> V_28 [ V_47 ] ;
V_75 -> V_63 = V_49 ;
V_75 -> V_59 = V_59 ;
V_75 -> V_61 = ( void * ) F_41 ;
V_75 -> V_62 = V_73 ;
V_75 -> V_58 = V_76 ;
V_4 -> V_25 [ V_4 -> V_80 ] = V_76 ;
F_47 () ;
V_4 -> V_80 = ( V_4 -> V_80 + 1 ) &
( V_24 - 1 ) ;
V_4 -> V_47 = ( V_47 + 1 ) & ( V_24 - 1 ) ;
F_48 () ;
F_4 ( & V_4 -> V_6 -> V_81 , 1 ) ;
F_46 ( & V_4 -> V_78 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_17 , V_18 ;
int V_46 , error ;
V_4 = F_2 ( V_2 ) ;
F_50 ( & V_4 -> V_20 , F_26 , ( unsigned long ) V_2 ) ;
error = F_51 ( V_4 -> V_21 , F_21 , V_82 ,
F_52 ( V_2 ) , V_2 ) ;
if ( error ) {
F_7 ( V_2 , L_7 ,
V_4 -> V_15 , V_4 -> V_21 ) ;
goto V_83;
}
error = F_1 ( V_2 ) ;
if ( error )
goto V_84;
error = - V_85 ;
V_4 -> V_25 = F_53 ( V_2 , sizeof( * V_4 -> V_25 ) *
V_24 , & V_17 , V_86 ) ;
if ( ! V_4 -> V_25 )
goto V_84;
V_4 -> V_27 = F_53 ( V_2 , sizeof( * V_4 -> V_27 ) *
V_24 , & V_18 , V_86 ) ;
if ( ! V_4 -> V_27 )
goto V_87;
V_4 -> V_28 = F_54 ( V_24 , sizeof( * V_4 -> V_28 ) , V_86 ) ;
if ( ! V_4 -> V_28 )
goto V_88;
for ( V_46 = 0 ; V_46 < V_24 ; V_46 ++ )
V_4 -> V_28 [ V_46 ] . V_58 = ! 0 ;
V_4 -> V_80 = 0 ;
V_4 -> V_57 = 0 ;
V_4 -> V_47 = 0 ;
V_4 -> V_48 = 0 ;
F_55 ( & V_4 -> V_6 -> V_22 , V_17 ) ;
F_55 ( & V_4 -> V_6 -> V_23 , V_18 ) ;
F_4 ( & V_4 -> V_6 -> V_89 , V_24 ) ;
F_4 ( & V_4 -> V_6 -> V_90 , V_24 ) ;
V_4 -> V_91 = V_24 ;
F_56 ( & V_4 -> V_78 ) ;
F_56 ( & V_4 -> V_56 ) ;
F_3 ( & V_4 -> V_6 -> V_7 , V_92 |
( V_93 << V_94 ) |
( V_95 << V_96 ) ) ;
return 0 ;
V_88:
F_13 ( V_2 , sizeof( struct V_26 ) * V_24 ,
V_4 -> V_27 , V_18 ) ;
V_87:
F_13 ( V_2 , sizeof( T_1 ) * V_24 ,
V_4 -> V_25 , V_17 ) ;
F_7 ( V_2 , L_8 , V_4 -> V_15 ) ;
V_84:
F_11 ( V_4 -> V_21 , V_2 ) ;
V_83:
F_10 ( & V_4 -> V_20 ) ;
return error ;
}
static int F_57 ( struct V_29 * V_30 )
{
struct V_1 * V_31 ;
struct V_97 * V_98 ;
struct V_99 T_4 * V_100 ;
struct V_3 * V_32 ;
static int V_101 ;
int error ;
V_31 = & V_30 -> V_2 ;
V_32 = F_58 ( V_31 , sizeof( * V_32 ) , V_86 ) ;
if ( ! V_32 )
return - V_85 ;
F_59 ( V_31 , V_32 ) ;
V_32 -> V_15 = V_101 ++ ;
V_98 = V_30 -> V_2 . V_102 ;
V_100 = F_60 ( V_98 , 0 ) ;
if ( ! V_100 ) {
F_7 ( V_31 , L_9 ) ;
return - V_85 ;
}
V_32 -> V_6 = (struct V_99 V_103 * ) V_100 ;
if ( sizeof( T_1 ) == sizeof( V_104 ) )
if ( F_61 ( V_98 , L_10 ) )
F_62 ( V_31 , F_63 ( 40 ) ) ;
else
F_62 ( V_31 , F_63 ( 36 ) ) ;
else
F_62 ( V_31 , F_63 ( 32 ) ) ;
V_32 -> V_21 = F_64 ( V_98 , 0 ) ;
error = F_49 ( V_31 ) ;
if ( error ) {
F_20 ( V_32 -> V_21 ) ;
return error ;
}
V_32 -> V_2 = V_31 ;
F_17 ( & V_35 . V_36 ) ;
F_65 ( & V_32 -> V_37 , & V_35 . V_70 ) ;
F_19 ( & V_35 . V_36 ) ;
F_66 ( & V_32 -> V_33 , 0 ) ;
return 0 ;
}
static int T_5 F_67 ( void )
{
F_56 ( & V_35 . V_36 ) ;
F_68 ( & V_35 . V_70 ) ;
return F_69 ( & V_105 ) ;
}
static void T_6 F_70 ( void )
{
F_71 ( & V_105 ) ;
}
