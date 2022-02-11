static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_7 ;
V_7 = F_3 ( & V_6 -> V_8 -> V_9 ) ;
if ( ! V_7 )
return V_10 ;
if ( V_7 & V_11 ) {
F_4 ( V_4 , L_1 , V_7 ) ;
F_5 () ;
}
F_6 ( & V_6 -> V_8 -> V_12 , V_13 ) ;
F_7 ( & V_6 -> V_8 -> V_9 , V_7 ) ;
F_8 () ;
F_9 ( & V_6 -> V_14 ) ;
F_10 () ;
return V_15 ;
}
static void F_11 ( unsigned long V_16 )
{
int V_17 , V_18 , V_19 , V_20 , V_21 ;
struct V_3 * V_4 = (struct V_3 * ) V_16 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
void (* F_12)( struct V_3 * V_4 , T_2 * V_22 , T_2 V_23 , void * V_24 );
T_2 * V_25 , V_26 ;
void * V_27 ;
while ( F_3 ( & V_6 -> V_8 -> V_28 ) ) {
V_20 = F_13 ( V_6 -> V_20 ) ;
F_14 ( & V_6 -> V_29 ) ;
V_18 = V_21 = V_6 -> V_21 ;
V_17 = V_6 -> V_30 ;
for ( V_19 = 0 ; F_15 ( V_20 , V_21 + V_19 , V_31 ) >= 1 ; V_19 ++ ) {
V_18 = ( V_21 + V_19 ) & ( V_31 - 1 ) ;
F_16 () ;
if ( V_6 -> V_32 [ V_17 ] . V_22 ==
V_6 -> V_33 [ V_18 ] . V_34 )
break;
}
F_17 ( F_15 ( V_20 , V_21 + V_19 , V_31 ) <= 0 ) ;
F_18 ( V_4 , V_6 -> V_32 [ V_17 ] . V_22 ,
V_6 -> V_33 [ V_18 ] . V_35 ,
V_36 ) ;
V_6 -> V_33 [ V_18 ] . V_34 = 0 ;
F_12 = V_6 -> V_33 [ V_18 ] . V_37 ;
V_27 = V_6 -> V_33 [ V_18 ] . V_38 ;
V_25 = V_6 -> V_33 [ V_18 ] . V_39 ;
V_26 = V_6 -> V_32 [ V_17 ] . V_40 ;
F_7 ( & V_6 -> V_8 -> V_41 , 1 ) ;
V_6 -> V_30 = ( V_6 -> V_30 + 1 ) &
( V_31 - 1 ) ;
if ( V_18 == V_21 ) {
do {
V_21 = ( V_21 + 1 ) & ( V_31 - 1 ) ;
F_16 () ;
} while ( F_15 ( V_20 , V_21 , V_31 ) >= 1 &&
V_6 -> V_33 [ V_21 ] . V_34 == 0 );
V_6 -> V_21 = V_21 ;
}
F_19 ( & V_6 -> V_29 ) ;
F_12 ( V_4 , V_25 , V_26 , V_27 ) ;
}
F_20 ( & V_6 -> V_8 -> V_12 , V_13 ) ;
}
int F_21 ( struct V_3 * V_4 , T_2 * V_22 ,
void (* F_22)( struct V_3 * V_4 , T_2 * V_22 ,
T_2 V_23 , void * V_42 ) ,
void * V_42 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_43 * V_44 ;
int V_20 , V_21 , V_35 ;
T_3 V_45 ;
V_35 = ( * V_22 & V_46 ) * sizeof( T_2 ) ;
V_45 = F_23 ( V_4 , V_22 , V_35 , V_36 ) ;
if ( F_24 ( V_4 , V_45 ) ) {
F_4 ( V_4 , L_2 ) ;
return - V_47 ;
}
F_25 ( & V_6 -> V_48 ) ;
V_20 = V_6 -> V_20 ;
V_21 = F_13 ( V_6 -> V_21 ) ;
if ( ! F_3 ( & V_6 -> V_8 -> V_49 ) ||
F_26 ( V_20 , V_21 , V_31 ) <= 0 ) {
F_27 ( & V_6 -> V_48 ) ;
F_18 ( V_4 , V_45 , V_35 , V_36 ) ;
return - V_50 ;
}
V_44 = & V_6 -> V_33 [ V_20 ] ;
V_44 -> V_39 = V_22 ;
V_44 -> V_35 = V_35 ;
V_44 -> V_37 = ( void * ) F_22 ;
V_44 -> V_38 = V_42 ;
V_44 -> V_34 = V_45 ;
V_6 -> V_51 [ V_6 -> V_52 ] = V_45 ;
F_28 () ;
V_6 -> V_52 = ( V_6 -> V_52 + 1 ) &
( V_31 - 1 ) ;
V_6 -> V_20 = ( V_20 + 1 ) & ( V_31 - 1 ) ;
F_7 ( & V_6 -> V_8 -> V_53 , 1 ) ;
F_27 ( & V_6 -> V_48 ) ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned int V_54 = 100000 ;
F_6 ( & V_6 -> V_8 -> V_12 , V_13 ) ;
F_7 ( & V_6 -> V_8 -> V_55 , V_56 ) ;
while ( ( ( F_3 ( & V_6 -> V_8 -> V_9 ) & V_57 ) ==
V_58 ) && -- V_54 )
F_30 () ;
if ( ( F_3 ( & V_6 -> V_8 -> V_9 ) & V_57 ) !=
V_59 || V_54 == 0 ) {
F_4 ( V_4 , L_3 , V_6 -> V_60 ) ;
return - V_47 ;
}
V_54 = 100000 ;
F_7 ( & V_6 -> V_8 -> V_55 , V_56 ) ;
while ( ( F_3 ( & V_6 -> V_8 -> V_55 ) & V_56 ) && -- V_54 )
F_30 () ;
if ( V_54 == 0 ) {
F_4 ( V_4 , L_4 , V_6 -> V_60 ) ;
return - V_47 ;
}
F_20 ( & V_6 -> V_8 -> V_12 , V_13 ) ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_3 V_61 , V_62 ;
int V_19 , error ;
V_6 = F_2 ( V_4 ) ;
F_32 ( & V_6 -> V_14 , F_11 , ( unsigned long ) V_4 ) ;
error = F_33 ( V_6 -> V_1 , F_1 , V_63 ,
L_5 , V_4 ) ;
if ( error ) {
F_4 ( V_4 , L_6 ,
V_6 -> V_60 , V_6 -> V_1 ) ;
F_34 ( V_6 -> V_1 ) ;
V_6 -> V_1 = 0 ;
return - V_64 ;
}
error = F_29 ( V_4 ) ;
if ( error )
return error ;
V_6 -> V_51 = F_35 ( V_4 , sizeof( T_3 ) * V_31 ,
& V_61 , V_65 ) ;
V_6 -> V_32 = F_35 ( V_4 , sizeof( struct V_66 ) *
V_31 , & V_62 , V_65 ) ;
V_6 -> V_33 = F_36 ( sizeof( struct V_43 ) * V_31 ,
V_65 ) ;
if ( ( V_6 -> V_51 == NULL ) || ( V_6 -> V_32 == NULL ) ||
( V_6 -> V_33 == NULL ) ) {
F_4 ( V_4 , L_7 ,
V_6 -> V_60 ) ;
return - V_67 ;
}
for ( V_19 = 0 ; V_19 < V_31 ; V_19 ++ )
V_6 -> V_33 [ V_19 ] . V_34 = ! 0 ;
V_6 -> V_52 = 0 ;
V_6 -> V_30 = 0 ;
V_6 -> V_20 = 0 ;
V_6 -> V_21 = 0 ;
F_37 ( & V_6 -> V_8 -> V_68 , V_61 ) ;
F_37 ( & V_6 -> V_8 -> V_69 , V_62 ) ;
F_7 ( & V_6 -> V_8 -> V_70 , V_31 ) ;
F_7 ( & V_6 -> V_8 -> V_71 , V_31 ) ;
V_6 -> V_72 = V_31 ;
F_38 ( & V_6 -> V_48 ) ;
F_38 ( & V_6 -> V_29 ) ;
F_6 ( & V_6 -> V_8 -> V_12 , V_73 |
( V_74 << V_75 ) |
( V_76 << V_77 ) ) ;
return 0 ;
}
int F_39 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_3 V_61 , V_62 ;
int V_78 ;
V_78 = F_29 ( V_4 ) ;
F_40 ( & V_6 -> V_14 ) ;
F_41 ( V_6 -> V_1 , V_4 ) ;
V_61 = F_42 ( & V_6 -> V_8 -> V_68 ) ;
V_62 = F_42 ( & V_6 -> V_8 -> V_69 ) ;
F_43 ( V_4 , sizeof( T_3 ) * V_31 ,
V_6 -> V_51 , V_61 ) ;
F_43 ( V_4 , sizeof( struct V_66 ) * V_31 ,
V_6 -> V_32 , V_62 ) ;
F_44 ( V_6 -> V_33 ) ;
F_45 ( V_6 -> V_79 ) ;
return V_78 ;
}
int F_46 ( struct V_80 * V_81 , struct V_82 * V_83 ,
int V_84 )
{
struct V_3 * V_85 , * V_86 ;
struct V_80 * V_79 ;
struct V_87 * V_88 ;
struct V_5 * V_89 ;
T_2 * V_90 ;
int error ;
V_85 = & V_81 -> V_4 ;
V_88 = F_2 ( V_85 ) ;
V_89 = F_47 ( sizeof( struct V_5 ) ,
V_65 ) ;
if ( V_89 == NULL ) {
F_4 ( V_85 , L_8 ,
V_84 ) ;
return - V_67 ;
}
V_89 -> V_91 = V_85 ;
V_89 -> V_60 = V_84 ;
V_90 = ( T_2 * ) F_48 ( V_83 , L_9 , NULL ) ;
V_89 -> V_8 = (struct V_92 V_93 * ) ( ( void * ) V_88 -> V_94
+ * V_90 ) ;
V_79 = F_49 ( V_83 , NULL , V_85 ) ;
if ( V_79 == NULL ) {
F_44 ( V_89 ) ;
return - V_64 ;
}
V_89 -> V_79 = V_79 ;
V_86 = & V_79 -> V_4 ;
F_50 ( V_86 , V_89 ) ;
V_88 -> V_86 [ V_84 ] = V_86 ;
if ( sizeof( T_3 ) == sizeof( V_95 ) )
if ( F_51 ( V_83 , L_10 ) )
F_52 ( V_86 , F_53 ( 40 ) ) ;
else
F_52 ( V_86 , F_53 ( 36 ) ) ;
else
F_52 ( V_86 , F_53 ( 32 ) ) ;
V_89 -> V_1 = F_54 ( V_83 , 0 , NULL ) ;
error = F_31 ( V_86 ) ;
if ( error ) {
F_45 ( V_79 ) ;
F_44 ( V_89 ) ;
return error ;
}
return error ;
}
