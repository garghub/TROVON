static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_5 ( & V_2 -> V_6 . V_7 . V_8 ) ;
F_6 ( & V_2 -> V_9 , 1 ) ;
return V_2 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 != NULL ) ;
if ( ! V_2 -> V_10 )
goto V_11;
if ( V_2 -> V_10 -> V_12 & V_13 )
F_8 ( F_9 ( & V_2 -> V_6 . V_7 . V_8 ) ) ;
else if ( V_2 -> V_10 -> V_12 & V_14 )
F_8 ( F_9 ( & V_2 -> V_6 . V_15 . V_16 ) ) ;
F_8 ( sizeof( * ( V_2 -> V_10 ) ) == V_17 ) ;
F_10 ( V_2 -> V_10 ) ;
V_11:
F_10 ( V_2 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_9 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
F_8 ( F_14 ( & V_2 -> V_9 ) > 0 ) ;
if ( F_15 ( & V_2 -> V_9 ) )
F_7 ( V_2 ) ;
}
static int F_16 ( const struct V_18 * V_19 ,
struct V_1 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 ;
int V_25 ;
V_25 = F_17 ( V_20 , & V_24 ) ;
if ( V_25 )
return V_25 ;
if ( V_24 -> V_26 == NULL )
return - V_27 ;
V_25 = V_24 -> V_26 ( V_19 , V_20 ) ;
if ( V_25 == V_28 ) {
struct V_29 * V_30 = V_20 -> V_10 ;
V_20 -> V_31 = 0 ;
V_30 -> V_32 = 1 ;
V_30 -> V_33 . V_34 = V_35 ;
V_30 -> V_33 . V_36 = V_30 -> V_37 . V_38 = V_17 ;
V_30 -> V_33 . V_39 = V_30 -> V_37 . V_40 = 0 ;
V_30 -> V_41 = F_18 () ;
if ( V_22 )
memcpy ( & V_30 -> V_42 , V_22 ,
sizeof( V_30 -> V_42 ) ) ;
V_30 -> V_43 = F_19 ( F_20 ( * V_30 ) , V_44 ) ;
F_21 ( 0 , V_30 -> V_44 ) ;
V_25 = 0 ;
}
return V_25 ;
}
int F_22 ( const struct V_18 * V_19 , struct V_1 * V_20 ,
int V_45 , struct V_21 * V_22 )
{
struct V_29 * V_30 ;
int V_25 ;
F_8 ( V_20 -> V_10 == NULL ) ;
V_30 = F_2 ( sizeof( * V_30 ) , V_3 ) ;
if ( ! V_30 )
return - V_46 ;
V_20 -> V_10 = V_30 ;
V_30 -> V_12 = V_45 ;
V_25 = F_16 ( V_19 , V_20 , V_22 ) ;
if ( V_25 == 0 ) {
if ( F_23 ( ( V_30 -> V_12 & V_13 &&
V_45 & V_14 ) ||
( V_30 -> V_12 & V_14 &&
V_45 & V_13 ) ) ) {
F_24 ( L_1 ,
V_20 -> V_47 -> V_48 -> V_49 ,
V_30 -> V_12 & V_14 ?
L_2 : L_3 ,
V_45 & V_14 ? L_2 : L_3 ) ;
V_25 = - V_50 ;
goto V_11;
} else if ( V_30 -> V_12 &
( V_13 | V_14 ) ) {
V_45 = V_30 -> V_12 ;
} else {
F_24 ( L_4 ) ;
V_25 = - V_50 ;
goto V_11;
}
if ( F_23 ( V_22 &&
! F_25 ( V_22 , & V_30 -> V_42 ) ) ) {
F_24 ( L_5 ,
V_20 -> V_47 -> V_48 -> V_49 ,
( char * ) V_22 -> V_22 ,
( char * ) V_30 -> V_42 . V_22 ) ;
V_25 = - V_51 ;
goto V_11;
}
}
if ( V_45 & V_14 ) {
F_8 ( F_9 ( & V_20 -> V_6 . V_15 . V_16 ) ) ;
F_5 ( & V_20 -> V_6 . V_15 . V_16 ) ;
V_30 -> V_52 = sizeof( struct V_53 ) ;
} else if ( ! ( V_45 & V_13 ) ) {
F_24 ( L_6 ,
V_20 -> V_47 -> V_48 -> V_49 ,
V_45 , V_14 , V_13 ) ;
V_25 = - V_50 ;
}
V_11:
if ( V_25 ) {
F_10 ( V_30 ) ;
V_20 -> V_10 = NULL ;
}
return V_25 ;
}
static int F_26 ( void * V_54 )
{
struct V_55 * V_56 = V_54 ;
struct V_1 * V_2 = V_56 -> V_57 ;
struct V_29 * V_30 = V_2 -> V_10 ;
struct V_58 * V_59 = V_56 -> V_60 ;
char * V_61 ;
T_1 V_62 = V_17 ;
T_1 V_63 ;
int V_25 = 0 , V_64 = 1 , V_65 ;
int V_66 = 0 ;
int V_67 = 0 ;
F_8 ( V_30 ) ;
V_61 = F_2 ( V_17 , V_3 ) ;
if ( ! V_61 ) {
V_56 -> V_68 = - V_46 ;
return 0 ;
}
if ( V_59 != NULL ) {
V_67 = V_59 -> V_69 ;
V_64 = V_59 -> V_69 + 1 ;
}
if ( V_59 != NULL && V_59 -> V_70 )
V_65 = V_59 -> V_70 ;
else
V_65 = V_71 * 8 - 1 ;
while ( V_25 == 0 ) {
struct V_72 * V_73 ;
while ( V_64 <= V_65 &&
! F_27 ( V_64 , V_30 -> V_44 ) )
++ V_64 ;
F_8 ( V_64 <= V_65 + 1 ) ;
if ( V_64 == V_65 + 1 )
break;
V_74:
F_28 ( V_75 , L_7 ,
V_64 , V_65 ) ;
memset ( V_61 , 0 , V_17 ) ;
V_63 = V_62 ;
V_25 = F_29 ( V_56 -> V_76 , V_2 , & V_66 ,
V_64 , & V_62 , V_61 , V_17 ) ;
if ( V_25 )
goto V_11;
for ( V_73 = (struct V_72 * ) V_61 ;
( char * ) V_73 < V_61 + V_17 ;
V_73 = (struct V_72 * ) ( ( char * ) V_73 + V_73 -> V_36 ) ) {
F_28 ( V_75 , L_8 ,
V_73 , V_73 -> V_34 ) ;
if ( F_30 ( V_73 ) )
F_31 ( V_73 ) ;
F_28 ( V_75 , L_9 ,
V_73 -> V_34 , V_73 -> V_39 ) ;
if ( V_73 -> V_39 == 0 ) {
V_25 = 0 ;
if ( V_64 <= V_2 -> V_31 )
goto V_74;
goto V_11;
}
if ( V_73 -> V_36 == 0 ||
V_73 -> V_36 > V_17 ) {
F_32 ( L_10 ,
V_73 -> V_36 ,
V_73 -> V_39 , V_64 ) ;
V_25 = - V_50 ;
goto V_11;
}
if ( V_73 -> V_39 < V_64 ) {
F_28 ( V_75 , L_11 ,
V_73 -> V_39 ) ;
continue;
}
F_28 ( V_75 ,
L_12 ,
V_73 -> V_39 , V_73 -> V_36 ,
( int ) ( V_61 + V_17 - ( char * ) V_73 ) ) ;
V_2 -> V_77 = V_73 -> V_39 ;
V_2 -> V_78 = ( char * ) V_73 - ( char * ) V_61 +
V_63 ;
if ( F_27 ( V_64 , V_30 -> V_44 ) ) {
V_25 = V_56 -> V_79 ( V_56 -> V_76 , V_2 , V_73 ,
V_56 -> V_80 ) ;
V_67 = V_64 ;
if ( V_25 )
goto V_11;
} else {
F_28 ( V_75 , L_13 , V_64 ) ;
}
++ V_64 ;
if ( V_64 > V_65 ) {
V_25 = 0 ;
goto V_11;
}
}
}
V_11:
if ( V_59 != NULL )
V_59 -> V_70 = V_67 ;
F_10 ( V_61 ) ;
V_56 -> V_68 = V_25 ;
return 0 ;
}
static int F_33 ( void * V_54 )
{
struct V_55 * V_56 = V_54 ;
struct V_18 V_19 ;
int V_25 ;
F_34 () ;
V_25 = F_35 ( & V_19 , V_81 | V_82 ) ;
if ( V_25 )
goto V_11;
V_56 -> V_76 = & V_19 ;
V_25 = F_26 ( V_54 ) ;
F_36 ( & V_19 ) ;
V_11:
F_37 ( & V_56 -> V_83 ) ;
return V_25 ;
}
int F_38 ( const struct V_18 * V_19 ,
struct V_1 * V_2 ,
T_2 V_84 , void * V_85 , void * V_86 , bool V_87 )
{
struct V_55 * V_56 ;
int V_25 ;
V_56 = F_2 ( sizeof( * V_56 ) , V_3 ) ;
if ( ! V_56 ) {
F_24 ( L_14 ) ;
return - V_46 ;
}
V_56 -> V_57 = V_2 ;
V_56 -> V_79 = V_84 ;
V_56 -> V_80 = V_85 ;
V_56 -> V_60 = V_86 ;
if ( V_87 ) {
V_56 -> V_76 = NULL ;
F_39 ( & V_56 -> V_83 ) ;
V_25 = F_40 ( F_41 ( F_33 , V_56 ,
L_15 ) ) ;
if ( F_42 ( V_25 ) ) {
F_24 ( L_16 ,
V_2 -> V_47 -> V_48 -> V_49 , V_25 ) ;
F_10 ( V_56 ) ;
return V_25 ;
}
F_43 ( & V_56 -> V_83 ) ;
} else {
V_56 -> V_76 = V_19 ;
F_26 ( V_56 ) ;
}
V_25 = V_56 -> V_68 ;
F_10 ( V_56 ) ;
return V_25 ;
}
int F_44 ( const struct V_18 * V_19 , struct V_1 * V_2 ,
T_2 V_84 , void * V_85 , void * V_86 )
{
return F_38 ( V_19 , V_2 , V_84 , V_85 , V_86 , true ) ;
}
int F_45 ( const struct V_18 * V_19 , struct V_88 * V_89 ,
struct V_1 * * V_90 , struct V_91 * V_92 ,
char * V_93 , enum V_94 V_95 )
{
int V_96 ;
int V_25 ;
F_8 ( V_89 ) ;
F_8 ( V_89 -> V_97 ) ;
if ( V_89 -> V_97 -> V_98 == NULL ) {
* V_90 = NULL ;
return - V_27 ;
}
* V_90 = F_1 () ;
if ( * V_90 == NULL )
return - V_46 ;
( * V_90 ) -> V_47 = V_89 ;
( * V_90 ) -> V_99 = V_89 -> V_97 ;
V_96 = F_46 ( V_100 ) ;
if ( ! V_96 )
F_47 ( V_100 ) ;
V_25 = V_89 -> V_97 -> V_98 ( V_19 , * V_90 , V_92 , V_93 , V_95 ) ;
if ( ! V_96 )
F_48 ( V_100 ) ;
if ( V_25 ) {
F_7 ( * V_90 ) ;
* V_90 = NULL ;
}
return V_25 ;
}
int F_49 ( const struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_23 * V_24 ;
int V_25 ;
V_25 = F_17 ( V_2 , & V_24 ) ;
if ( V_25 )
goto V_11;
if ( V_24 -> V_101 == NULL ) {
V_25 = - V_27 ;
goto V_11;
}
V_25 = V_24 -> V_101 ( V_19 , V_2 ) ;
V_11:
F_13 ( V_2 ) ;
return V_25 ;
}
