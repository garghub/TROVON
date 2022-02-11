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
if ( ! V_2 -> V_10 )
goto V_11;
if ( V_2 -> V_10 -> V_12 & V_13 )
F_8 ( F_9 ( & V_2 -> V_6 . V_7 . V_8 ) ) ;
else if ( V_2 -> V_10 -> V_12 & V_14 )
F_8 ( F_9 ( & V_2 -> V_6 . V_15 . V_16 ) ) ;
F_8 ( sizeof( * V_2 -> V_10 ) == V_17 ) ;
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
if ( ! V_24 -> V_26 )
return - V_27 ;
V_25 = V_24 -> V_26 ( V_19 , V_20 ) ;
if ( V_25 == V_28 ) {
struct V_29 * V_30 = V_20 -> V_10 ;
V_20 -> V_31 = 0 ;
V_30 -> V_32 = 1 ;
V_30 -> V_33 . V_34 = V_35 ;
V_30 -> V_33 . V_36 = V_17 ;
V_30 -> V_37 . V_38 = V_17 ;
V_30 -> V_33 . V_39 = 0 ;
V_30 -> V_37 . V_40 = 0 ;
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
enum V_46 V_47 = V_45 & V_48 ;
struct V_29 * V_30 ;
int V_25 ;
F_8 ( ! V_20 -> V_10 ) ;
V_30 = F_2 ( sizeof( * V_30 ) , V_3 ) ;
if ( ! V_30 )
return - V_49 ;
V_20 -> V_10 = V_30 ;
V_30 -> V_12 = V_45 ;
V_25 = F_16 ( V_19 , V_20 , V_22 ) ;
if ( V_25 == 0 ) {
if ( F_23 ( ( V_30 -> V_12 & V_13 &&
V_45 & V_14 ) ||
( V_30 -> V_12 & V_14 &&
V_45 & V_13 ) ) ) {
F_24 ( L_1 ,
V_20 -> V_50 -> V_51 -> V_52 ,
V_30 -> V_12 & V_14 ?
L_2 : L_3 ,
V_45 & V_14 ? L_2 : L_3 ) ;
V_25 = - V_53 ;
goto V_11;
} else if ( V_30 -> V_12 &
( V_13 | V_14 ) ) {
V_45 = V_30 -> V_12 ;
} else {
F_24 ( L_4 ) ;
V_25 = - V_53 ;
goto V_11;
}
if ( F_23 ( V_22 &&
! F_25 ( V_22 , & V_30 -> V_42 ) ) ) {
F_24 ( L_5 ,
V_20 -> V_50 -> V_51 -> V_52 ,
( char * ) V_22 -> V_22 ,
( char * ) V_30 -> V_42 . V_22 ) ;
V_25 = - V_54 ;
goto V_11;
}
}
if ( V_45 & V_14 ) {
F_8 ( F_9 ( & V_20 -> V_6 . V_15 . V_16 ) ) ;
F_5 ( & V_20 -> V_6 . V_15 . V_16 ) ;
V_30 -> V_55 = sizeof( struct V_56 ) ;
} else if ( ! ( V_45 & V_13 ) ) {
F_24 ( L_6 ,
V_20 -> V_50 -> V_51 -> V_52 ,
V_45 , V_14 , V_13 ) ;
V_25 = - V_53 ;
}
V_30 -> V_12 |= V_47 ;
V_11:
if ( V_25 ) {
F_10 ( V_30 ) ;
V_20 -> V_10 = NULL ;
}
return V_25 ;
}
static int F_26 ( void * V_57 )
{
struct V_58 * V_59 = V_57 ;
struct V_1 * V_2 = V_59 -> V_60 ;
struct V_29 * V_30 = V_2 -> V_10 ;
struct V_61 * V_62 = V_59 -> V_63 ;
char * V_64 ;
T_1 V_65 = V_17 ;
T_1 V_66 ;
int V_25 = 0 , V_67 = 1 , V_68 ;
int V_69 = 0 ;
int V_70 = 0 ;
F_8 ( V_30 ) ;
V_64 = F_2 ( V_17 , V_3 ) ;
if ( ! V_64 ) {
V_59 -> V_71 = - V_49 ;
return 0 ;
}
if ( V_62 ) {
V_70 = V_62 -> V_72 ;
V_67 = V_62 -> V_72 + 1 ;
}
if ( V_62 && V_62 -> V_73 )
V_68 = V_62 -> V_73 ;
else
V_68 = V_74 * 8 - 1 ;
if ( V_67 > V_68 )
goto V_11;
while ( V_25 == 0 ) {
struct V_75 * V_76 ;
while ( V_67 <= V_68 &&
! F_27 ( V_67 , V_30 -> V_44 ) )
++ V_67 ;
F_8 ( V_67 <= V_68 + 1 ) ;
if ( V_67 == V_68 + 1 )
break;
V_77:
F_28 ( V_78 , L_7 ,
V_67 , V_68 ) ;
memset ( V_64 , 0 , V_17 ) ;
V_66 = V_65 ;
V_25 = F_29 ( V_59 -> V_79 , V_2 , & V_69 ,
V_67 , & V_65 , V_64 , V_17 ) ;
if ( V_25 )
goto V_11;
for ( V_76 = (struct V_75 * ) V_64 ;
( char * ) V_76 < V_64 + V_17 ;
V_76 = F_30 ( V_76 ) ) {
F_28 ( V_78 , L_8 ,
V_76 , V_76 -> V_34 ) ;
if ( F_31 ( V_76 ) )
F_32 ( V_76 ) ;
F_28 ( V_78 , L_9 ,
V_76 -> V_34 , V_76 -> V_39 ) ;
if ( V_76 -> V_39 == 0 ) {
V_25 = 0 ;
if ( V_67 <= V_2 -> V_31 )
goto V_77;
goto V_11;
}
if ( V_76 -> V_36 == 0 ||
V_76 -> V_36 > V_17 ) {
F_33 ( L_10 ,
V_76 -> V_36 ,
V_76 -> V_39 , V_67 ) ;
V_25 = - V_53 ;
goto V_11;
}
if ( V_76 -> V_39 < V_67 ) {
F_28 ( V_78 , L_11 ,
V_76 -> V_39 ) ;
continue;
}
F_28 ( V_78 ,
L_12 ,
V_76 -> V_39 , V_76 -> V_36 ,
( int ) ( V_64 + V_17 - ( char * ) V_76 ) ) ;
V_2 -> V_80 = V_76 -> V_39 ;
V_2 -> V_81 = ( char * ) V_76 - ( char * ) V_64 +
V_66 ;
if ( F_27 ( V_67 , V_30 -> V_44 ) ) {
V_25 = V_59 -> V_82 ( V_59 -> V_79 , V_2 , V_76 ,
V_59 -> V_83 ) ;
V_70 = V_67 ;
if ( V_25 )
goto V_11;
} else {
F_28 ( V_78 , L_13 , V_67 ) ;
}
++ V_67 ;
if ( V_67 > V_68 ) {
V_25 = 0 ;
goto V_11;
}
}
}
V_11:
if ( V_62 )
V_62 -> V_73 = V_70 ;
F_10 ( V_64 ) ;
V_59 -> V_71 = V_25 ;
return 0 ;
}
static int F_34 ( void * V_57 )
{
struct V_58 * V_59 = V_57 ;
struct V_18 V_19 ;
int V_25 ;
F_35 () ;
V_25 = F_36 ( & V_19 , V_84 | V_85 ) ;
if ( V_25 )
goto V_11;
V_59 -> V_79 = & V_19 ;
V_25 = F_26 ( V_57 ) ;
F_37 ( & V_19 ) ;
V_11:
F_38 ( & V_59 -> V_86 ) ;
return V_25 ;
}
int F_39 ( const struct V_18 * V_19 ,
struct V_1 * V_2 ,
T_2 V_87 , void * V_88 , void * V_89 , bool V_90 )
{
struct V_58 * V_59 ;
int V_25 ;
V_59 = F_2 ( sizeof( * V_59 ) , V_3 ) ;
if ( ! V_59 )
return - V_49 ;
V_59 -> V_60 = V_2 ;
V_59 -> V_82 = V_87 ;
V_59 -> V_83 = V_88 ;
V_59 -> V_63 = V_89 ;
if ( V_90 ) {
struct V_91 * V_92 ;
V_59 -> V_79 = NULL ;
F_40 ( & V_59 -> V_86 ) ;
V_92 = F_41 ( F_34 , V_59 ,
L_14 ) ;
if ( F_42 ( V_92 ) ) {
V_25 = F_43 ( V_92 ) ;
F_24 ( L_15 ,
V_2 -> V_50 -> V_51 -> V_52 , V_25 ) ;
goto V_93;
}
F_44 ( & V_59 -> V_86 ) ;
} else {
V_59 -> V_79 = V_19 ;
F_26 ( V_59 ) ;
}
V_25 = V_59 -> V_71 ;
V_93:
F_10 ( V_59 ) ;
return V_25 ;
}
int F_45 ( const struct V_18 * V_19 , struct V_1 * V_2 ,
T_2 V_87 , void * V_88 , void * V_89 )
{
return F_39 ( V_19 , V_2 , V_87 , V_88 , V_89 , true ) ;
}
int F_46 ( const struct V_18 * V_19 , struct V_94 * V_95 ,
struct V_1 * * V_96 , struct V_97 * V_98 ,
char * V_99 , enum V_100 V_101 )
{
int V_102 ;
int V_25 ;
F_8 ( V_95 ) ;
F_8 ( V_95 -> V_103 ) ;
if ( ! V_95 -> V_103 -> V_104 ) {
* V_96 = NULL ;
return - V_27 ;
}
* V_96 = F_1 () ;
if ( ! * V_96 )
return - V_49 ;
( * V_96 ) -> V_50 = V_95 ;
( * V_96 ) -> V_105 = V_95 -> V_103 ;
V_102 = F_47 ( V_106 ) ;
if ( ! V_102 )
F_48 ( V_106 ) ;
V_25 = V_95 -> V_103 -> V_104 ( V_19 , * V_96 , V_98 , V_99 , V_101 ) ;
if ( ! V_102 )
F_49 ( V_106 ) ;
if ( V_25 ) {
F_7 ( * V_96 ) ;
* V_96 = NULL ;
}
return V_25 ;
}
int F_50 ( const struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_23 * V_24 ;
int V_25 ;
V_25 = F_17 ( V_2 , & V_24 ) ;
if ( V_25 )
goto V_11;
if ( ! V_24 -> V_107 ) {
V_25 = - V_27 ;
goto V_11;
}
V_25 = V_24 -> V_107 ( V_19 , V_2 ) ;
V_11:
F_13 ( V_2 ) ;
return V_25 ;
}
