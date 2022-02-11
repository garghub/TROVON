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
F_9 ( & V_6 -> V_14 [ F_10 () ] ) ;
F_11 () ;
return V_15 ;
}
static void F_12 ( unsigned long V_16 )
{
int V_17 , V_18 , V_19 , V_20 , V_21 ;
struct V_3 * V_4 = (struct V_3 * ) V_16 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
void (* F_13)( struct V_3 * V_4 , T_2 * V_22 , T_2 V_23 , void * V_24 );
T_2 * V_25 , V_26 ;
void * V_27 ;
unsigned long V_28 ;
F_14 ( & V_6 -> V_29 , V_28 ) ;
V_20 = F_15 ( V_6 -> V_20 ) ;
V_18 = V_21 = V_6 -> V_21 ;
while ( F_16 ( V_20 , V_21 , V_30 ) >= 1 &&
F_3 ( & V_6 -> V_8 -> V_31 ) ) {
V_17 = V_6 -> V_32 ;
for ( V_19 = 0 ; F_16 ( V_20 , V_21 + V_19 , V_30 ) >= 1 ; V_19 ++ ) {
V_18 = ( V_21 + V_19 ) & ( V_30 - 1 ) ;
F_17 () ;
if ( V_6 -> V_33 [ V_17 ] . V_22 ==
V_6 -> V_34 [ V_18 ] . V_35 )
break;
}
F_18 ( F_16 ( V_20 , V_21 + V_19 , V_30 ) <= 0 ) ;
F_19 ( V_4 , V_6 -> V_33 [ V_17 ] . V_22 ,
V_6 -> V_34 [ V_18 ] . V_36 ,
V_37 ) ;
V_6 -> V_34 [ V_18 ] . V_35 = 0 ;
F_13 = V_6 -> V_34 [ V_18 ] . V_38 ;
V_27 = V_6 -> V_34 [ V_18 ] . V_39 ;
V_25 = V_6 -> V_34 [ V_18 ] . V_40 ;
V_26 = V_6 -> V_33 [ V_17 ] . V_41 ;
F_20 () ;
V_6 -> V_32 = ( V_6 -> V_32 + 1 ) &
( V_30 - 1 ) ;
if ( V_18 == V_21 ) {
do {
V_21 = ( V_21 + 1 ) & ( V_30 - 1 ) ;
F_17 () ;
} while ( F_16 ( V_20 , V_21 , V_30 ) >= 1 &&
V_6 -> V_34 [ V_21 ] . V_35 == 0 );
V_6 -> V_21 = V_21 ;
}
F_7 ( & V_6 -> V_8 -> V_42 , 1 ) ;
F_21 ( & V_6 -> V_29 , V_28 ) ;
F_13 ( V_4 , V_25 , V_26 , V_27 ) ;
F_14 ( & V_6 -> V_29 , V_28 ) ;
V_20 = F_15 ( V_6 -> V_20 ) ;
V_18 = V_21 = V_6 -> V_21 ;
}
F_21 ( & V_6 -> V_29 , V_28 ) ;
F_22 ( & V_6 -> V_8 -> V_12 , V_13 ) ;
}
int F_23 ( struct V_3 * V_43 , struct V_3 * * V_44 )
{
struct V_45 * V_46 = F_2 ( V_43 ) ;
struct V_5 * V_47 = NULL ;
unsigned long V_28 ;
int V_48 ;
F_14 ( & V_46 -> V_49 , V_28 ) ;
for ( V_48 = 0 ; V_48 < V_46 -> V_50 ; V_48 ++ ) {
V_47 = F_2 ( V_46 -> V_51 [ V_48 ] ) ;
if ( V_47 -> V_52 == V_53 ) {
V_47 -> V_52 = V_54 ;
* V_44 = V_46 -> V_51 [ V_48 ] ;
F_21 ( & V_46 -> V_49 , V_28 ) ;
return V_48 ;
}
}
F_21 ( & V_46 -> V_49 , V_28 ) ;
* V_44 = NULL ;
return - V_55 ;
}
int F_24 ( struct V_3 * V_44 )
{
struct V_5 * V_47 = F_2 ( V_44 ) ;
struct V_45 * V_46 ;
unsigned long V_28 ;
V_46 = F_2 ( V_47 -> V_56 ) ;
if ( F_3 ( & V_47 -> V_8 -> V_31 ) ||
( F_3 ( & V_47 -> V_8 -> V_57 ) != V_30 ) )
return - V_58 ;
F_14 ( & V_46 -> V_49 , V_28 ) ;
V_47 -> V_52 = V_53 ;
F_21 ( & V_46 -> V_49 , V_28 ) ;
return 0 ;
}
int F_25 ( struct V_3 * V_4 , T_2 * V_22 ,
void (* F_26)( struct V_3 * V_4 , T_2 * V_22 ,
T_2 V_23 , void * V_59 ) ,
void * V_59 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_60 * V_61 ;
unsigned long V_28 ;
int V_20 , V_21 , V_36 ;
T_3 V_62 ;
V_36 = ( * V_22 & V_63 ) * sizeof( T_2 ) ;
V_62 = F_27 ( V_4 , V_22 , V_36 , V_37 ) ;
if ( F_28 ( V_4 , V_62 ) ) {
F_4 ( V_4 , L_2 ) ;
return - V_64 ;
}
F_14 ( & V_6 -> V_65 , V_28 ) ;
V_20 = V_6 -> V_20 ;
V_21 = F_15 ( V_6 -> V_21 ) ;
if ( ! F_3 ( & V_6 -> V_8 -> V_57 ) ||
F_29 ( V_20 , V_21 , V_30 ) <= 0 ) {
F_21 ( & V_6 -> V_65 , V_28 ) ;
F_19 ( V_4 , V_62 , V_36 , V_37 ) ;
return - V_58 ;
}
V_61 = & V_6 -> V_34 [ V_20 ] ;
V_61 -> V_40 = V_22 ;
V_61 -> V_36 = V_36 ;
V_61 -> V_38 = ( void * ) F_26 ;
V_61 -> V_39 = V_59 ;
V_61 -> V_35 = V_62 ;
V_6 -> V_66 [ V_6 -> V_67 ] = V_62 ;
F_30 () ;
V_6 -> V_67 = ( V_6 -> V_67 + 1 ) &
( V_30 - 1 ) ;
V_6 -> V_20 = ( V_20 + 1 ) & ( V_30 - 1 ) ;
F_31 () ;
F_7 ( & V_6 -> V_8 -> V_68 , 1 ) ;
F_21 ( & V_6 -> V_65 , V_28 ) ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned int V_69 = 100000 ;
F_6 ( & V_6 -> V_8 -> V_12 , V_13 ) ;
F_7 ( & V_6 -> V_8 -> V_70 , V_71 ) ;
while ( ( ( F_3 ( & V_6 -> V_8 -> V_9 ) & V_72 ) ==
V_73 ) && -- V_69 )
F_33 () ;
if ( ( F_3 ( & V_6 -> V_8 -> V_9 ) & V_72 ) !=
V_74 || V_69 == 0 ) {
F_4 ( V_4 , L_3 , V_6 -> V_75 ) ;
return - V_64 ;
}
V_69 = 100000 ;
F_7 ( & V_6 -> V_8 -> V_70 , V_71 ) ;
while ( ( F_3 ( & V_6 -> V_8 -> V_70 ) & V_71 ) && -- V_69 )
F_33 () ;
if ( V_69 == 0 ) {
F_4 ( V_4 , L_4 , V_6 -> V_75 ) ;
return - V_64 ;
}
F_22 ( & V_6 -> V_8 -> V_12 , V_13 ) ;
return 0 ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_3 V_76 , V_77 ;
int V_19 , error ;
V_6 = F_2 ( V_4 ) ;
F_35 (i)
F_36 ( & V_6 -> V_14 [ V_19 ] , F_12 ,
( unsigned long ) V_4 ) ;
error = F_37 ( V_6 -> V_1 , F_1 , V_78 ,
L_5 , V_4 ) ;
if ( error ) {
F_4 ( V_4 , L_6 ,
V_6 -> V_75 , V_6 -> V_1 ) ;
F_38 ( V_6 -> V_1 ) ;
V_6 -> V_1 = 0 ;
return - V_79 ;
}
error = F_32 ( V_4 ) ;
if ( error )
return error ;
V_6 -> V_66 = F_39 ( sizeof( T_3 ) * V_30 ,
V_80 | V_81 ) ;
V_6 -> V_33 = F_39 ( sizeof( struct V_82 ) *
V_30 , V_80 | V_81 ) ;
V_6 -> V_34 = F_39 ( sizeof( struct V_60 ) * V_30 ,
V_80 ) ;
if ( ( V_6 -> V_66 == NULL ) || ( V_6 -> V_33 == NULL ) ||
( V_6 -> V_34 == NULL ) ) {
F_4 ( V_4 , L_7 ,
V_6 -> V_75 ) ;
return - V_83 ;
}
for ( V_19 = 0 ; V_19 < V_30 ; V_19 ++ )
V_6 -> V_34 [ V_19 ] . V_35 = ! 0 ;
V_76 = F_27 ( V_4 , V_6 -> V_66 ,
sizeof( T_2 * ) * V_30 ,
V_84 ) ;
if ( F_28 ( V_4 , V_76 ) ) {
F_4 ( V_4 , L_8 ) ;
F_40 ( V_6 -> V_66 ) ;
F_40 ( V_6 -> V_33 ) ;
F_40 ( V_6 -> V_34 ) ;
return - V_64 ;
}
V_77 = F_27 ( V_4 , V_6 -> V_33 ,
sizeof( struct V_82 ) * V_30 ,
V_84 ) ;
if ( F_28 ( V_4 , V_77 ) ) {
F_4 ( V_4 , L_9 ) ;
F_19 ( V_4 , V_76 ,
sizeof( T_2 * ) * V_30 ,
V_84 ) ;
F_40 ( V_6 -> V_66 ) ;
F_40 ( V_6 -> V_33 ) ;
F_40 ( V_6 -> V_34 ) ;
return - V_64 ;
}
V_6 -> V_67 = 0 ;
V_6 -> V_32 = 0 ;
V_6 -> V_20 = 0 ;
V_6 -> V_21 = 0 ;
F_41 ( & V_6 -> V_8 -> V_85 , V_76 ) ;
F_41 ( & V_6 -> V_8 -> V_86 , V_77 ) ;
F_7 ( & V_6 -> V_8 -> V_87 , V_30 ) ;
F_7 ( & V_6 -> V_8 -> V_88 , V_30 ) ;
V_6 -> V_89 = V_30 ;
F_42 ( & V_6 -> V_65 ) ;
F_42 ( & V_6 -> V_29 ) ;
F_6 ( & V_6 -> V_8 -> V_12 , V_90 |
( V_91 << V_92 ) |
( V_93 << V_94 ) ) ;
V_6 -> V_52 = V_53 ;
return 0 ;
}
int F_43 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_3 V_76 , V_77 ;
int V_95 , V_19 ;
V_95 = F_32 ( V_4 ) ;
F_35 (i)
F_44 ( & V_6 -> V_14 [ V_19 ] ) ;
F_45 ( V_6 -> V_1 , V_4 ) ;
V_76 = F_46 ( & V_6 -> V_8 -> V_85 ) ;
V_77 = F_46 ( & V_6 -> V_8 -> V_86 ) ;
F_19 ( V_4 , V_77 ,
sizeof( struct V_82 ) * V_30 ,
V_84 ) ;
F_19 ( V_4 , V_76 , sizeof( T_2 * ) * V_30 ,
V_84 ) ;
F_40 ( V_6 -> V_33 ) ;
F_40 ( V_6 -> V_66 ) ;
F_40 ( V_6 -> V_34 ) ;
return V_95 ;
}
int F_47 ( struct V_96 * V_97 , struct V_98 * V_99 ,
int V_48 )
{
struct V_3 * V_43 , * V_51 ;
struct V_96 * V_100 ;
struct V_45 * V_46 ;
struct V_5 * V_47 ;
T_2 * V_101 ;
int error ;
V_43 = & V_97 -> V_4 ;
V_46 = F_2 ( V_43 ) ;
V_47 = F_48 ( sizeof( struct V_5 ) ,
V_80 ) ;
if ( V_47 == NULL ) {
F_4 ( V_43 , L_10 ,
V_48 ) ;
return - V_83 ;
}
V_47 -> V_56 = V_43 ;
V_47 -> V_75 = V_48 ;
V_101 = ( T_2 * ) F_49 ( V_99 , L_11 , NULL ) ;
V_47 -> V_8 = (struct V_102 V_103 * ) ( ( void * ) V_46 -> V_104
+ * V_101 ) ;
V_100 = F_50 ( V_99 , NULL , V_43 ) ;
if ( V_100 == NULL ) {
F_40 ( V_47 ) ;
return - V_79 ;
}
V_51 = & V_100 -> V_4 ;
F_51 ( V_51 , V_47 ) ;
V_46 -> V_51 [ V_48 ] = V_51 ;
V_47 -> V_1 = F_52 ( V_99 , 0 , NULL ) ;
error = F_34 ( V_51 ) ;
if ( error ) {
F_40 ( V_47 ) ;
return error ;
}
return error ;
}
