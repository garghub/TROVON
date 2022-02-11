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
F_10 ( V_2 -> V_10 ) ;
V_11:
F_11 ( V_2 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_9 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_8 ( F_15 ( & V_2 -> V_9 ) > 0 ) ;
if ( F_16 ( & V_2 -> V_9 ) )
F_7 ( V_2 ) ;
}
static int F_17 ( const struct V_17 * V_18 ,
struct V_1 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 ;
int V_24 ;
V_24 = F_18 ( V_19 , & V_23 ) ;
if ( V_24 )
return V_24 ;
if ( ! V_23 -> V_25 )
return - V_26 ;
V_24 = V_23 -> V_25 ( V_18 , V_19 ) ;
if ( V_24 == V_27 ) {
struct V_28 * V_29 = V_19 -> V_10 ;
T_1 V_30 ;
V_19 -> V_31 = 0 ;
V_29 -> V_32 = 1 ;
V_29 -> V_33 . V_34 = V_35 ;
F_8 ( V_19 -> V_36 -> V_37 >= V_38 ) ;
V_29 -> V_33 . V_39 = V_19 -> V_36 -> V_37 ;
V_29 -> V_33 . V_40 = 0 ;
V_29 -> V_41 = F_19 () ;
if ( V_21 )
memcpy ( & V_29 -> V_42 , V_21 ,
sizeof( V_29 -> V_42 ) ) ;
V_29 -> V_43 = F_20 ( F_21 ( * V_29 ) , V_44 ) ;
V_30 = V_29 -> V_33 . V_39 - V_29 -> V_43 ;
memset ( F_22 ( V_29 ) , 0 , V_30 - sizeof( V_29 -> V_45 ) ) ;
F_23 ( 0 , F_22 ( V_29 ) ) ;
F_24 ( V_29 ) -> V_46 = V_29 -> V_33 . V_39 ;
F_24 ( V_29 ) -> V_47 = V_29 -> V_33 . V_40 ;
V_24 = 0 ;
}
return V_24 ;
}
int F_25 ( const struct V_17 * V_18 , struct V_1 * V_19 ,
int V_48 , struct V_20 * V_21 )
{
int V_49 = V_19 -> V_36 -> V_37 ;
enum V_50 V_51 = V_48 & V_52 ;
struct V_28 * V_29 ;
int V_24 ;
F_8 ( ! V_19 -> V_10 ) ;
F_8 ( V_49 >= V_38 ) ;
V_29 = F_26 ( sizeof( * V_29 ) , V_3 ) ;
if ( ! V_29 )
return - V_53 ;
V_19 -> V_10 = V_29 ;
V_19 -> V_54 = V_49 ;
V_29 -> V_12 = V_48 ;
V_24 = F_17 ( V_18 , V_19 , V_21 ) ;
if ( V_24 == 0 ) {
if ( F_27 ( ( V_29 -> V_12 & V_13 &&
V_48 & V_14 ) ||
( V_29 -> V_12 & V_14 &&
V_48 & V_13 ) ) ) {
F_28 ( L_1 ,
V_19 -> V_36 -> V_55 -> V_56 ,
V_29 -> V_12 & V_14 ?
L_2 : L_3 ,
V_48 & V_14 ? L_2 : L_3 ) ;
V_24 = - V_57 ;
goto V_11;
} else if ( V_29 -> V_12 &
( V_13 | V_14 ) ) {
V_48 = V_29 -> V_12 ;
} else {
F_28 ( L_4 ) ;
V_24 = - V_57 ;
goto V_11;
}
if ( F_27 ( V_21 &&
! F_29 ( V_21 , & V_29 -> V_42 ) ) ) {
F_28 ( L_5 ,
V_19 -> V_36 -> V_55 -> V_56 ,
( char * ) V_21 -> V_21 ,
( char * ) V_29 -> V_42 . V_21 ) ;
V_24 = - V_58 ;
goto V_11;
}
}
if ( V_48 & V_14 ) {
F_8 ( F_9 ( & V_19 -> V_6 . V_15 . V_16 ) ) ;
F_5 ( & V_19 -> V_6 . V_15 . V_16 ) ;
V_29 -> V_59 = sizeof( struct V_60 ) ;
V_29 -> V_12 |= V_61 ;
} else if ( ! ( V_48 & V_13 ) ) {
F_28 ( L_6 ,
V_19 -> V_36 -> V_55 -> V_56 ,
V_48 , V_14 , V_13 ) ;
V_24 = - V_57 ;
}
V_29 -> V_12 |= V_51 ;
V_11:
if ( V_24 ) {
F_10 ( V_29 ) ;
V_19 -> V_10 = NULL ;
}
return V_24 ;
}
static int F_30 ( void * V_62 )
{
struct V_63 * V_64 = V_62 ;
struct V_1 * V_2 = V_64 -> V_65 ;
struct V_28 * V_29 = V_2 -> V_10 ;
struct V_66 * V_67 = V_64 -> V_68 ;
char * V_69 ;
T_2 V_70 , V_71 ;
int V_49 ;
int V_24 = 0 , V_72 = 1 , V_73 ;
int V_74 = 0 ;
int V_75 = 0 ;
if ( ! V_29 )
return - V_57 ;
V_70 = V_29 -> V_33 . V_39 ;
V_49 = V_29 -> V_33 . V_39 ;
F_8 ( F_31 ( V_49 ) ) ;
V_69 = F_26 ( V_49 , V_3 ) ;
if ( ! V_69 ) {
V_64 -> V_76 = - V_53 ;
return 0 ;
}
if ( V_67 ) {
V_75 = V_67 -> V_77 ;
V_72 = V_67 -> V_77 + 1 ;
}
if ( V_67 && V_67 -> V_78 )
V_73 = V_67 -> V_78 ;
else
V_73 = F_32 ( V_29 ) - 1 ;
while ( V_24 == 0 ) {
unsigned int V_79 = 0 ;
struct V_80 * V_81 ;
bool V_82 ;
T_3 V_83 ;
while ( V_72 <= V_73 &&
! F_33 ( V_72 , F_22 ( V_29 ) ) )
++ V_72 ;
if ( V_72 > V_73 )
break;
F_34 ( V_84 , L_7 ,
V_72 , V_73 ) ;
V_85:
memset ( V_69 , 0 , V_49 ) ;
V_24 = F_35 ( V_64 -> V_86 , V_2 , & V_74 ,
V_72 , & V_70 , V_69 , V_49 ) ;
if ( V_24 )
goto V_11;
V_71 = V_70 ;
if ( F_36 ( V_71 , V_49 ) ) {
V_82 = true ;
V_83 = V_70 & ~ ( V_49 - 1 ) ;
} else {
V_82 = false ;
V_83 = V_70 - V_49 ;
}
for ( V_81 = (struct V_80 * ) ( V_69 + V_79 ) ;
( char * ) V_81 < V_69 + V_49 ;
V_81 = F_37 ( V_81 ) ) {
F_34 ( V_84 , L_8 ,
V_81 , V_81 -> V_34 ) ;
if ( F_38 ( V_81 ) )
F_39 ( V_81 ) ;
F_34 ( V_84 , L_9 ,
V_81 -> V_34 , V_81 -> V_40 ) ;
if ( V_82 && ! V_81 -> V_40 ) {
if ( V_72 > V_2 -> V_31 ) {
V_24 = 0 ;
goto V_11;
}
F_34 ( V_84 , L_10 ,
V_72 , V_2 -> V_31 ) ;
V_79 = ( char * ) V_81 - ( char * ) V_69 ;
V_70 = V_83 ;
goto V_85;
}
if ( ! V_81 -> V_39 || V_81 -> V_39 > V_49 ) {
F_40 ( L_11 ,
V_81 -> V_39 ,
V_81 -> V_40 , V_72 ) ;
V_24 = - V_57 ;
goto V_11;
}
if ( V_81 -> V_40 < V_72 ) {
F_34 ( V_84 , L_12 ,
V_81 -> V_40 ) ;
continue;
}
if ( V_81 -> V_40 != V_72 ) {
F_28 ( L_13 ,
V_2 -> V_36 -> V_55 -> V_56 ,
V_81 -> V_40 , V_72 ) ;
V_24 = - V_87 ;
goto V_11;
}
F_34 ( V_84 ,
L_14 ,
V_81 -> V_40 , V_81 -> V_39 ,
( int ) ( V_69 + V_49 - ( char * ) V_81 ) ) ;
V_2 -> V_88 = V_81 -> V_40 ;
V_2 -> V_89 = ( char * ) V_81 - ( char * ) V_69 +
V_83 ;
if ( F_33 ( V_72 , F_22 ( V_29 ) ) ) {
V_24 = V_64 -> V_90 ( V_64 -> V_86 , V_2 , V_81 ,
V_64 -> V_91 ) ;
V_75 = V_72 ;
if ( V_24 )
goto V_11;
}
if ( V_72 >= V_73 ) {
V_24 = 0 ;
goto V_11;
}
V_72 ++ ;
}
}
V_11:
if ( V_67 )
V_67 -> V_78 = V_75 ;
F_11 ( V_69 ) ;
V_64 -> V_76 = V_24 ;
return 0 ;
}
static int F_41 ( void * V_62 )
{
struct V_63 * V_64 = V_62 ;
struct V_17 V_18 ;
int V_24 ;
F_42 () ;
V_24 = F_43 ( & V_18 , V_92 | V_93 ) ;
if ( V_24 )
goto V_11;
V_64 -> V_86 = & V_18 ;
V_24 = F_30 ( V_62 ) ;
F_44 ( & V_18 ) ;
V_11:
F_45 ( & V_64 -> V_94 ) ;
return V_24 ;
}
int F_46 ( const struct V_17 * V_18 ,
struct V_1 * V_2 ,
T_4 V_95 , void * V_96 , void * V_97 , bool V_98 )
{
struct V_63 * V_64 ;
int V_24 ;
V_64 = F_2 ( sizeof( * V_64 ) , V_3 ) ;
if ( ! V_64 )
return - V_53 ;
V_64 -> V_65 = V_2 ;
V_64 -> V_90 = V_95 ;
V_64 -> V_91 = V_96 ;
V_64 -> V_68 = V_97 ;
if ( V_98 ) {
struct V_99 * V_100 ;
V_64 -> V_86 = NULL ;
F_47 ( & V_64 -> V_94 ) ;
V_100 = F_48 ( F_41 , V_64 ,
L_15 ) ;
if ( F_49 ( V_100 ) ) {
V_24 = F_50 ( V_100 ) ;
F_28 ( L_16 ,
V_2 -> V_36 -> V_55 -> V_56 , V_24 ) ;
goto V_101;
}
F_51 ( & V_64 -> V_94 ) ;
} else {
V_64 -> V_86 = V_18 ;
F_30 ( V_64 ) ;
}
V_24 = V_64 -> V_76 ;
V_101:
F_11 ( V_64 ) ;
return V_24 ;
}
int F_52 ( const struct V_17 * V_18 , struct V_1 * V_2 ,
T_4 V_95 , void * V_96 , void * V_97 )
{
return F_46 ( V_18 , V_2 , V_95 , V_96 , V_97 , true ) ;
}
int F_53 ( const struct V_17 * V_18 , struct V_102 * V_103 ,
struct V_1 * * V_104 , struct V_105 * V_106 ,
char * V_107 , enum V_108 V_109 )
{
int V_110 ;
int V_24 ;
F_8 ( V_103 ) ;
F_8 ( V_103 -> V_111 ) ;
if ( ! V_103 -> V_111 -> V_112 ) {
* V_104 = NULL ;
return - V_26 ;
}
* V_104 = F_1 () ;
if ( ! * V_104 )
return - V_53 ;
( * V_104 ) -> V_36 = V_103 ;
( * V_104 ) -> V_113 = V_103 -> V_111 ;
V_110 = F_54 ( V_114 ) ;
if ( ! V_110 )
F_55 ( V_114 ) ;
V_24 = V_103 -> V_111 -> V_112 ( V_18 , * V_104 , V_106 , V_107 , V_109 ) ;
if ( ! V_110 )
F_56 ( V_114 ) ;
if ( V_24 ) {
F_7 ( * V_104 ) ;
* V_104 = NULL ;
}
return V_24 ;
}
int F_57 ( const struct V_17 * V_18 , struct V_1 * V_2 )
{
struct V_22 * V_23 ;
int V_24 ;
V_24 = F_18 ( V_2 , & V_23 ) ;
if ( V_24 )
goto V_11;
if ( ! V_23 -> V_115 ) {
V_24 = - V_26 ;
goto V_11;
}
V_24 = V_23 -> V_115 ( V_18 , V_2 ) ;
V_11:
F_14 ( V_2 ) ;
return V_24 ;
}
