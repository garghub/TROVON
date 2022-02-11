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
int F_21 ( struct V_3 * V_42 , struct V_3 * * V_43 )
{
struct V_44 * V_45 = F_2 ( V_42 ) ;
struct V_5 * V_46 = NULL ;
int V_47 ;
F_14 ( & V_45 -> V_48 ) ;
for ( V_47 = 0 ; V_47 < V_45 -> V_49 ; V_47 ++ ) {
V_46 = F_2 ( V_45 -> V_50 [ V_47 ] ) ;
if ( V_46 -> V_51 == V_52 ) {
V_46 -> V_51 = V_53 ;
* V_43 = V_45 -> V_50 [ V_47 ] ;
F_19 ( & V_45 -> V_48 ) ;
return V_47 ;
}
}
F_19 ( & V_45 -> V_48 ) ;
* V_43 = NULL ;
return - V_54 ;
}
int F_22 ( struct V_3 * V_43 )
{
struct V_5 * V_46 = F_2 ( V_43 ) ;
struct V_44 * V_45 ;
V_45 = F_2 ( V_46 -> V_55 ) ;
if ( F_3 ( & V_46 -> V_8 -> V_28 ) ||
( F_3 ( & V_46 -> V_8 -> V_56 ) != V_31 ) )
return - V_57 ;
F_14 ( & V_45 -> V_48 ) ;
V_46 -> V_51 = V_52 ;
F_19 ( & V_45 -> V_48 ) ;
return 0 ;
}
int F_23 ( struct V_3 * V_4 , T_2 * V_22 ,
void (* F_24)( struct V_3 * V_4 , T_2 * V_22 ,
T_2 V_23 , void * V_58 ) ,
void * V_58 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_59 * V_60 ;
int V_20 , V_21 , V_35 ;
T_3 V_61 ;
V_35 = ( * V_22 & V_62 ) * sizeof( T_2 ) ;
V_61 = F_25 ( V_4 , V_22 , V_35 , V_36 ) ;
if ( F_26 ( V_4 , V_61 ) ) {
F_4 ( V_4 , L_2 ) ;
return - V_63 ;
}
F_27 ( & V_6 -> V_64 ) ;
V_20 = V_6 -> V_20 ;
V_21 = F_13 ( V_6 -> V_21 ) ;
if ( ! F_3 ( & V_6 -> V_8 -> V_56 ) ||
F_28 ( V_20 , V_21 , V_31 ) <= 0 ) {
F_29 ( & V_6 -> V_64 ) ;
F_18 ( V_4 , V_61 , V_35 , V_36 ) ;
return - V_57 ;
}
V_60 = & V_6 -> V_33 [ V_20 ] ;
V_60 -> V_39 = V_22 ;
V_60 -> V_35 = V_35 ;
V_60 -> V_37 = ( void * ) F_24 ;
V_60 -> V_38 = V_58 ;
V_60 -> V_34 = V_61 ;
V_6 -> V_65 [ V_6 -> V_66 ] = V_61 ;
F_30 () ;
V_6 -> V_66 = ( V_6 -> V_66 + 1 ) &
( V_31 - 1 ) ;
V_6 -> V_20 = ( V_20 + 1 ) & ( V_31 - 1 ) ;
F_7 ( & V_6 -> V_8 -> V_67 , 1 ) ;
F_29 ( & V_6 -> V_64 ) ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned int V_68 = 100000 ;
F_6 ( & V_6 -> V_8 -> V_12 , V_13 ) ;
F_7 ( & V_6 -> V_8 -> V_69 , V_70 ) ;
while ( ( ( F_3 ( & V_6 -> V_8 -> V_9 ) & V_71 ) ==
V_72 ) && -- V_68 )
F_32 () ;
if ( ( F_3 ( & V_6 -> V_8 -> V_9 ) & V_71 ) !=
V_73 || V_68 == 0 ) {
F_4 ( V_4 , L_3 , V_6 -> V_74 ) ;
return - V_63 ;
}
V_68 = 100000 ;
F_7 ( & V_6 -> V_8 -> V_69 , V_70 ) ;
while ( ( F_3 ( & V_6 -> V_8 -> V_69 ) & V_70 ) && -- V_68 )
F_32 () ;
if ( V_68 == 0 ) {
F_4 ( V_4 , L_4 , V_6 -> V_74 ) ;
return - V_63 ;
}
F_20 ( & V_6 -> V_8 -> V_12 , V_13 ) ;
return 0 ;
}
static int F_33 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_3 V_75 , V_76 ;
int V_19 , error ;
V_6 = F_2 ( V_4 ) ;
F_34 ( & V_6 -> V_14 , F_11 , ( unsigned long ) V_4 ) ;
error = F_35 ( V_6 -> V_1 , F_1 , V_77 ,
L_5 , V_4 ) ;
if ( error ) {
F_4 ( V_4 , L_6 ,
V_6 -> V_74 , V_6 -> V_1 ) ;
F_36 ( V_6 -> V_1 ) ;
V_6 -> V_1 = 0 ;
return - V_78 ;
}
error = F_31 ( V_4 ) ;
if ( error )
return error ;
V_6 -> V_65 = F_37 ( V_4 , sizeof( T_3 ) * V_31 ,
& V_75 , V_79 ) ;
V_6 -> V_32 = F_37 ( V_4 , sizeof( struct V_80 ) *
V_31 , & V_76 , V_79 ) ;
V_6 -> V_33 = F_38 ( sizeof( struct V_59 ) * V_31 ,
V_79 ) ;
if ( ( V_6 -> V_65 == NULL ) || ( V_6 -> V_32 == NULL ) ||
( V_6 -> V_33 == NULL ) ) {
F_4 ( V_4 , L_7 ,
V_6 -> V_74 ) ;
return - V_81 ;
}
for ( V_19 = 0 ; V_19 < V_31 ; V_19 ++ )
V_6 -> V_33 [ V_19 ] . V_34 = ! 0 ;
V_6 -> V_66 = 0 ;
V_6 -> V_30 = 0 ;
V_6 -> V_20 = 0 ;
V_6 -> V_21 = 0 ;
F_39 ( & V_6 -> V_8 -> V_82 , V_75 ) ;
F_39 ( & V_6 -> V_8 -> V_83 , V_76 ) ;
F_7 ( & V_6 -> V_8 -> V_84 , V_31 ) ;
F_7 ( & V_6 -> V_8 -> V_85 , V_31 ) ;
V_6 -> V_86 = V_31 ;
F_40 ( & V_6 -> V_64 ) ;
F_40 ( & V_6 -> V_29 ) ;
F_6 ( & V_6 -> V_8 -> V_12 , V_87 |
( V_88 << V_89 ) |
( V_90 << V_91 ) ) ;
V_6 -> V_51 = V_52 ;
return 0 ;
}
int F_41 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_3 V_75 , V_76 ;
int V_92 ;
V_92 = F_31 ( V_4 ) ;
F_42 ( & V_6 -> V_14 ) ;
F_43 ( V_6 -> V_1 , V_4 ) ;
V_75 = F_44 ( & V_6 -> V_8 -> V_82 ) ;
V_76 = F_44 ( & V_6 -> V_8 -> V_83 ) ;
F_45 ( V_4 , sizeof( T_3 ) * V_31 ,
V_6 -> V_65 , V_75 ) ;
F_45 ( V_4 , sizeof( struct V_80 ) * V_31 ,
V_6 -> V_32 , V_76 ) ;
F_46 ( V_6 -> V_33 ) ;
return V_92 ;
}
int F_47 ( struct V_93 * V_94 , struct V_95 * V_96 ,
int V_47 )
{
struct V_3 * V_42 , * V_50 ;
struct V_93 * V_97 ;
struct V_44 * V_45 ;
struct V_5 * V_46 ;
T_2 * V_98 ;
int error ;
V_42 = & V_94 -> V_4 ;
V_45 = F_2 ( V_42 ) ;
V_46 = F_48 ( sizeof( struct V_5 ) ,
V_79 ) ;
if ( V_46 == NULL ) {
F_4 ( V_42 , L_8 ,
V_47 ) ;
return - V_81 ;
}
V_46 -> V_55 = V_42 ;
V_46 -> V_74 = V_47 ;
V_98 = ( T_2 * ) F_49 ( V_96 , L_9 , NULL ) ;
V_46 -> V_8 = (struct V_99 V_100 * ) ( ( void * ) V_45 -> V_101
+ * V_98 ) ;
V_97 = F_50 ( V_96 , NULL , V_42 ) ;
if ( V_97 == NULL ) {
F_46 ( V_46 ) ;
return - V_78 ;
}
V_50 = & V_97 -> V_4 ;
F_51 ( V_50 , V_46 ) ;
V_45 -> V_50 [ V_47 ] = V_50 ;
if ( sizeof( T_3 ) == sizeof( V_102 ) )
if ( F_52 ( V_96 , L_10 ) )
F_53 ( V_50 , F_54 ( 40 ) ) ;
else
F_53 ( V_50 , F_54 ( 36 ) ) ;
else
F_53 ( V_50 , F_54 ( 32 ) ) ;
V_46 -> V_1 = F_55 ( V_96 , 0 , NULL ) ;
error = F_33 ( V_50 ) ;
if ( error ) {
F_46 ( V_46 ) ;
return error ;
}
return error ;
}
