struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
if ( V_4 . V_5 == NULL )
return NULL ;
V_3 = V_4 . V_5 -> V_6 ;
while ( V_3 != NULL ) {
if ( V_3 -> V_2 == V_2 )
break;
V_3 = V_3 -> V_7 ;
}
F_2 ( L_1 , V_2 , V_3 ) ;
return V_3 ;
}
static void F_3 ( struct V_1 * V_8 )
{
struct V_1 * V_9 ;
struct V_1 * V_7 ;
F_2 ( L_2 , V_8 ) ;
if ( F_1 ( V_8 -> V_2 ) != NULL ) {
V_7 = V_8 -> V_7 ;
V_9 = V_8 -> V_9 ;
if ( V_9 != NULL ) {
V_9 -> V_7 = V_7 ;
if ( V_7 != NULL )
V_7 -> V_9 = V_9 ;
} else {
if ( V_7 != NULL )
V_7 -> V_9 = NULL ;
V_4 . V_5 -> V_6 = V_7 ;
}
}
}
static struct
V_10 * F_4 ( const struct V_11 * V_12 ,
unsigned long V_13 ,
int V_14 , T_1 V_15 )
{
struct V_10 * V_16 ;
int V_17 , V_18 ;
T_2 V_19 ;
T_3 V_20 ;
V_19 = V_13 / 4096 ;
V_20 = V_14 / 4096 ;
V_16 = * ( V_12 -> V_21 ) ;
V_17 = V_12 -> V_17 ;
for ( V_18 = 0 ; V_18 < V_12 -> V_17 ; V_18 ++ ) {
if ( ( V_16 [ V_18 ] . V_19 == V_19 ) &&
( V_16 [ V_18 ] . V_20 == V_20 ) &&
( F_5 ( V_16 [ V_18 ] . V_22 ) == F_5 ( V_15 ) ) ) {
return V_16 + V_18 ;
}
}
return NULL ;
}
static void F_6 ( struct V_11 * V_12 )
{
F_2 ( L_3 , V_12 ) ;
if ( V_12 -> V_21 != NULL ) {
if ( * ( V_12 -> V_21 ) != NULL ) {
F_2 ( L_4 , * ( V_12 -> V_21 ) , V_12 ) ;
F_7 ( * ( V_12 -> V_21 ) ) ;
}
F_2 ( L_4 , V_12 -> V_21 , V_12 ) ;
F_7 ( V_12 -> V_21 ) ;
V_12 -> V_21 = NULL ;
}
}
static void F_8 ( struct V_11 * V_12 ,
struct V_10 * * V_16 , int V_17 )
{
struct V_10 * * V_23 ;
V_23 = V_12 -> V_21 ;
if ( V_23 != NULL )
F_6 ( V_12 ) ;
F_2 ( L_5 , V_16 , V_17 , V_12 ) ;
V_12 -> V_17 = V_17 ;
V_12 -> V_21 = V_16 ;
}
static T_1 F_9 ( int V_22 )
{
unsigned long V_24 ;
V_24 = F_10 ( V_22 ) | V_25 ;
return F_11 ( V_24 ) ;
}
int F_12 ( struct V_11 * V_12 , struct V_26 * V_27 )
{
struct V_10 * * V_28 ;
struct V_10 * V_16 ;
struct V_29 * V_30 ;
T_3 V_18 ;
V_16 = F_13 ( ( sizeof( struct V_10 ) * V_27 -> V_31 ) , V_32 ) ;
if ( V_16 == NULL ) {
F_7 ( V_27 -> V_33 ) ;
V_27 -> V_33 = NULL ;
return - V_34 ;
}
V_30 = V_27 -> V_33 ;
for ( V_18 = 0 ; V_18 < V_27 -> V_31 ; V_18 ++ ) {
V_16 [ V_18 ] . V_19 = V_30 [ V_18 ] . V_19 ;
V_16 [ V_18 ] . V_20 = V_30 [ V_18 ] . V_20 ;
V_16 [ V_18 ] . V_22 = F_9 ( V_30 [ V_18 ] . V_22 ) ;
}
F_7 ( V_27 -> V_33 ) ;
V_27 -> V_33 = NULL ;
V_28 = F_14 ( sizeof( void * ) , V_32 ) ;
if ( V_28 == NULL ) {
F_7 ( V_16 ) ;
return - V_34 ;
}
* V_28 = V_16 ;
F_8 ( V_12 , V_28 , V_27 -> V_31 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_8 )
{
struct V_1 * V_9 ;
V_9 = V_4 . V_5 -> V_6 ;
if ( V_9 != NULL ) {
V_9 -> V_9 = V_8 ;
V_8 -> V_7 = V_9 ;
}
V_4 . V_5 -> V_6 = V_8 ;
}
struct V_35 * F_16 ( T_4 V_36 )
{
struct V_35 * V_3 ;
V_3 = V_4 . V_37 ;
while ( V_3 != NULL ) {
if ( V_3 -> V_38 == V_36 )
return V_3 ;
V_3 = V_3 -> V_7 ;
}
return NULL ;
}
static void F_17 ( struct V_35 * V_39 )
{
struct V_35 * V_9 ;
V_9 = V_4 . V_37 ;
if ( V_9 != NULL )
V_9 -> V_9 = V_39 ;
V_39 -> V_7 = V_9 ;
V_4 . V_37 = V_39 ;
}
static void F_18 ( struct V_35 * V_39 )
{
struct V_35 * V_7 ;
struct V_35 * V_9 ;
V_7 = V_39 -> V_7 ;
V_9 = V_39 -> V_9 ;
if ( V_9 != NULL ) {
V_9 -> V_7 = V_7 ;
if ( V_7 != NULL )
V_7 -> V_9 = V_9 ;
} else {
if ( V_7 != NULL )
V_7 -> V_9 = NULL ;
V_4 . V_37 = V_7 ;
}
}
void F_19 ( struct V_1 * V_40 )
{
F_3 ( V_40 ) ;
F_20 ( V_40 ) ;
}
struct V_1 * F_21 ( T_3 V_20 , T_5 type )
{
struct V_1 * V_40 ;
V_40 = F_22 ( V_41 , V_20 , type ) ;
if ( V_40 == NULL )
return NULL ;
F_15 ( V_40 ) ;
return V_40 ;
}
static struct V_42 * F_23 ( T_4 V_43 )
{
struct V_42 * V_44 ;
V_44 = V_4 . V_45 ;
while ( V_44 != NULL ) {
if ( V_44 -> V_36 == V_43 )
return V_44 ;
V_44 = V_44 -> V_7 ;
}
return NULL ;
}
static struct V_42 * F_24 ( T_4 V_43 )
{
struct V_42 * V_44 ;
V_44 = F_13 ( sizeof( struct V_42 ) , V_32 ) ;
if ( V_44 == NULL )
return NULL ;
V_44 -> V_36 = V_43 ;
return V_44 ;
}
static int F_25 ( struct V_42 * V_44 )
{
struct V_42 * V_46 ;
V_46 = V_4 . V_45 ;
V_44 -> V_7 = V_46 ;
if ( V_46 != NULL )
V_46 -> V_9 = V_44 ;
V_4 . V_45 = V_44 ;
return 0 ;
}
static void F_26 ( struct V_42 * V_44 )
{
struct V_11 * V_12 ;
struct V_11 * V_8 ;
V_12 = V_44 -> V_47 ;
while ( V_12 ) {
struct V_35 * V_39 ;
V_8 = V_12 ;
F_6 ( V_8 ) ;
V_39 = F_16 ( V_8 -> V_36 ) ;
if ( V_39 != NULL ) {
F_27 ( V_48 , & V_39 -> V_49 ) ;
F_27 ( V_50 , & V_39 -> V_49 ) ;
}
V_12 = V_12 -> V_7 ;
F_7 ( V_8 ) ;
}
}
static void F_28 ( struct V_42 * V_44 )
{
struct V_1 * V_40 ;
struct V_1 * V_8 ;
V_40 = V_44 -> V_6 ;
while ( V_40 ) {
V_8 = V_40 ;
V_40 = V_40 -> V_7 ;
F_19 ( V_8 ) ;
}
}
static int F_29 ( struct V_42 * V_44 )
{
struct V_42 * V_46 ;
struct V_42 * V_51 ;
V_46 = V_44 -> V_9 ;
V_51 = V_44 -> V_7 ;
if ( V_46 != NULL ) {
V_46 -> V_7 = V_51 ;
if ( V_51 != NULL )
V_51 -> V_9 = V_46 ;
} else {
if ( V_51 != NULL )
V_51 -> V_9 = NULL ;
V_4 . V_45 = V_51 ;
}
F_28 ( V_44 ) ;
F_26 ( V_44 ) ;
if ( V_4 . V_5 == V_44 ) {
V_4 . V_5 = NULL ;
V_4 . V_52 = false ;
F_30 ( V_41 ) ;
}
F_7 ( V_44 ) ;
return 0 ;
}
static void F_31 ( struct V_42 * V_44 )
{
struct V_11 * V_47 ;
V_47 = V_44 -> V_47 ;
while ( V_47 != NULL ) {
struct V_35 * V_39 ;
V_39 = F_16 ( V_47 -> V_36 ) ;
if ( V_39 != NULL ) {
F_32 ( V_48 , & V_39 -> V_49 ) ;
F_32 ( V_50 , & V_39 -> V_49 ) ;
}
V_47 = V_47 -> V_7 ;
}
V_4 . V_5 = V_44 ;
}
static void F_33 ( struct V_42 * V_44 ,
struct V_35 * V_53 )
{
struct V_11 * V_47 ;
F_27 ( V_48 , & V_53 -> V_49 ) ;
V_47 = V_44 -> V_47 ;
while ( V_47 != NULL ) {
struct V_35 * V_39 ;
V_39 = F_16 ( V_47 -> V_36 ) ;
if ( V_39 != NULL )
F_27 ( V_48 , & V_39 -> V_49 ) ;
V_47 = V_47 -> V_7 ;
}
V_4 . V_5 = NULL ;
V_4 . V_54 = false ;
F_30 ( V_41 ) ;
}
static struct V_11
* F_34 ( struct V_42 * V_44 , T_4 V_43 )
{
struct V_11 * V_12 ;
if ( V_44 == NULL )
return NULL ;
V_12 = V_44 -> V_47 ;
while ( V_12 != NULL ) {
if ( V_12 -> V_36 == V_43 )
return V_12 ;
V_12 = V_12 -> V_7 ;
}
return NULL ;
}
static struct V_42 * F_35 ( T_4 V_43 )
{
struct V_42 * V_44 ;
V_44 = V_4 . V_45 ;
while ( V_44 != NULL ) {
if ( ( F_34 ( V_44 , V_43 ) ) != NULL )
return V_44 ;
V_44 = V_44 -> V_7 ;
}
return NULL ;
}
struct V_11 * F_36 ( T_4 V_43 )
{
struct V_11 * V_8 ;
if ( V_4 . V_5 == NULL )
return NULL ;
V_8 = F_34 ( V_4 . V_5 , V_43 ) ;
return V_8 ;
}
static void F_37 ( struct V_11 * V_12 )
{
struct V_11 * V_55 ;
V_55 = V_4 . V_5 -> V_47 ;
V_12 -> V_7 = V_55 ;
if ( V_55 != NULL )
V_55 -> V_9 = V_12 ;
V_4 . V_5 -> V_47 = V_12 ;
V_4 . V_5 -> V_56 ++ ;
}
struct V_11 * F_38 ( T_4 V_43 )
{
struct V_11 * V_57 ;
V_57 = F_13 ( sizeof( struct V_11 ) , V_32 ) ;
if ( V_57 == NULL )
return NULL ;
V_57 -> V_36 = V_43 ;
F_37 ( V_57 ) ;
return V_57 ;
}
int F_39 ( T_4 V_43 )
{
struct V_11 * V_12 ;
struct V_11 * V_55 ;
struct V_11 * V_58 ;
struct V_42 * V_44 ;
V_44 = F_35 ( V_43 ) ;
if ( V_44 == NULL )
return - V_59 ;
V_12 = F_34 ( V_44 , V_43 ) ;
if ( V_12 == NULL )
return - V_59 ;
V_55 = V_12 -> V_9 ;
V_58 = V_12 -> V_7 ;
if ( V_55 != NULL ) {
V_55 -> V_7 = V_58 ;
if ( V_58 != NULL )
V_58 -> V_9 = V_55 ;
} else {
if ( V_58 != NULL )
V_58 -> V_9 = NULL ;
V_44 -> V_47 = V_58 ;
}
V_44 -> V_56 -- ;
F_6 ( V_12 ) ;
F_7 ( V_12 ) ;
return 0 ;
}
static int F_40 ( struct V_60 * V_60 , struct V_61 * V_62 )
{
unsigned int V_14 , V_63 ;
unsigned long V_13 ;
struct V_11 * V_12 ;
struct V_35 * V_39 = V_60 -> V_64 ;
struct V_65 V_66 ;
F_41 ( & ( V_4 . V_67 ) ) ;
if ( V_4 . V_52 != true )
goto V_68;
if ( ! ( F_42 ( V_48 , & V_39 -> V_49 ) ) )
goto V_68;
F_43 ( V_41 , & V_66 ) ;
V_14 = V_62 -> V_69 - V_62 -> V_70 ;
V_63 = V_66 . V_71 ;
V_63 = V_63 * 0x100000 ;
V_13 = V_62 -> V_72 << V_73 ;
F_2 ( L_6 , V_13 , V_13 + V_14 ) ;
if ( F_42 ( V_50 , & V_39 -> V_49 ) ) {
if ( ( V_14 + V_13 ) > V_63 )
goto V_74;
V_12 = F_36 ( V_75 -> V_36 ) ;
if ( V_12 == NULL )
goto V_68;
if ( ! F_4 ( V_12 , V_13 , V_14 , V_62 -> V_76 ) )
goto V_74;
F_2 ( L_7 , V_66 . V_77 ) ;
if ( V_66 . V_77 ) {
V_62 -> V_77 = V_66 . V_77 ;
} else if ( F_44 ( V_62 , V_62 -> V_70 ,
( V_66 . V_78 + V_13 ) >> V_73 ,
V_14 ,
F_45 ( V_62 -> V_76 ) ) ) {
goto V_79;
}
F_46 ( & ( V_4 . V_67 ) ) ;
return 0 ;
}
if ( F_42 ( V_80 , & V_39 -> V_49 ) ) {
if ( V_14 != V_63 )
goto V_74;
F_2 ( L_8 , V_66 . V_77 ) ;
if ( V_66 . V_77 ) {
V_62 -> V_77 = V_66 . V_77 ;
} else if ( F_44 ( V_62 , V_62 -> V_70 ,
V_66 . V_78 >> V_73 ,
V_14 ,
F_45 ( V_62 -> V_76 ) ) ) {
goto V_79;
}
F_46 ( & ( V_4 . V_67 ) ) ;
return 0 ;
}
V_68:
F_46 ( & ( V_4 . V_67 ) ) ;
return - V_81 ;
V_74:
F_46 ( & ( V_4 . V_67 ) ) ;
return - V_59 ;
V_79:
F_46 ( & ( V_4 . V_67 ) ) ;
return - V_82 ;
}
static int F_47 ( struct V_83 * V_83 , struct V_60 * V_60 )
{
struct V_35 * V_39 = V_60 -> V_64 ;
F_41 ( & ( V_4 . V_67 ) ) ;
F_2 ( L_9 , V_39 ) ;
if ( F_42 ( V_80 , & V_39 -> V_49 ) ) {
struct V_42 * V_44 ;
V_44 = F_23 ( V_39 -> V_38 ) ;
if ( V_44 != NULL ) {
if ( V_44 == V_4 . V_5 )
F_33 ( V_44 , V_39 ) ;
F_29 ( V_44 ) ;
V_44 = NULL ;
}
}
if ( F_42 ( V_50 , & V_39 -> V_49 ) )
F_39 ( V_39 -> V_38 ) ;
F_18 ( V_39 ) ;
F_7 ( V_39 ) ;
V_60 -> V_64 = NULL ;
F_46 ( & ( V_4 . V_67 ) ) ;
return 0 ;
}
static int F_48 ( struct V_83 * V_83 , struct V_60 * V_60 )
{
int V_84 = F_49 ( V_83 ) ;
struct V_35 * V_39 ;
struct V_11 * V_12 ;
if ( V_84 != V_85 )
return - V_86 ;
F_41 ( & ( V_4 . V_67 ) ) ;
V_39 = F_13 ( sizeof( struct V_35 ) , V_32 ) ;
if ( V_39 == NULL ) {
F_46 ( & ( V_4 . V_67 ) ) ;
return - V_34 ;
}
F_32 ( V_87 , & V_39 -> V_49 ) ;
V_39 -> V_38 = V_75 -> V_36 ;
if ( F_50 ( V_88 ) )
F_32 ( V_89 , & V_39 -> V_49 ) ;
V_12 = F_36 ( V_75 -> V_36 ) ;
if ( V_12 != NULL ) {
F_32 ( V_50 , & V_39 -> V_49 ) ;
F_32 ( V_48 , & V_39 -> V_49 ) ;
}
V_60 -> V_64 = ( void * ) V_39 ;
F_17 ( V_39 ) ;
F_2 ( L_10 , V_39 , V_12 ) ;
F_46 ( & ( V_4 . V_67 ) ) ;
return 0 ;
}
static T_6 F_51 ( struct V_60 * V_60 , char T_7 * V_90 ,
T_3 V_91 , T_8 * V_92 )
{
return - V_59 ;
}
static T_6 F_52 ( struct V_60 * V_60 , const char T_7 * V_90 ,
T_3 V_91 , T_8 * V_92 )
{
return - V_59 ;
}
static int F_53 ( struct V_35 * V_39 , void T_7 * V_93 )
{
struct V_94 V_95 ;
struct V_65 V_66 ;
F_43 ( V_41 , & V_66 ) ;
V_95 . V_96 . V_97 = V_66 . V_96 . V_97 ;
V_95 . V_96 . V_84 = V_66 . V_96 . V_84 ;
V_95 . V_98 = V_66 . V_99 -> V_100 |
( V_66 . V_99 -> V_99 << 16 ) ;
V_95 . V_101 = V_66 . V_102 ;
V_95 . V_78 = V_66 . V_78 ;
V_95 . V_71 = V_66 . V_71 ;
V_95 . V_103 = V_95 . V_104 = V_66 . V_105 ;
V_95 . V_106 = V_66 . V_107 ;
if ( F_54 ( V_93 , & V_95 , sizeof( struct V_94 ) ) )
return - V_108 ;
return 0 ;
}
int F_55 ( struct V_35 * V_39 )
{
struct V_42 * V_44 ;
F_2 ( L_11 ) ;
if ( ! ( F_42 ( V_89 , & V_39 -> V_49 ) ) )
return - V_81 ;
if ( V_4 . V_5 != NULL )
return - V_109 ;
if ( ! V_41 )
return - V_110 ;
if ( F_56 ( & V_41 -> V_111 ) )
return - V_109 ;
F_57 ( & V_41 -> V_111 ) ;
V_4 . V_52 = true ;
V_44 = F_23 ( V_39 -> V_38 ) ;
if ( V_44 != NULL ) {
F_31 ( V_44 ) ;
} else {
V_44 = F_24 ( V_39 -> V_38 ) ;
if ( V_44 == NULL ) {
V_4 . V_52 = false ;
F_30 ( V_41 ) ;
return - V_34 ;
}
F_25 ( V_44 ) ;
F_31 ( V_44 ) ;
}
F_32 ( V_80 , & V_39 -> V_49 ) ;
F_32 ( V_48 , & V_39 -> V_49 ) ;
return 0 ;
}
int F_58 ( struct V_35 * V_39 )
{
F_2 ( L_11 ) ;
F_33 ( V_4 . V_5 , V_39 ) ;
return 0 ;
}
int F_59 ( struct V_35 * V_39 , void T_7 * V_93 )
{
struct V_112 V_102 ;
F_2 ( L_11 ) ;
if ( F_60 ( & V_102 , V_93 , sizeof( struct V_112 ) ) )
return - V_108 ;
F_61 ( V_41 , V_102 . V_101 ) ;
return 0 ;
}
static int F_62 ( struct V_35 * V_39 , void T_7 * V_93 )
{
struct V_26 V_113 ;
struct V_11 * V_12 ;
struct V_35 * V_114 ;
F_2 ( L_11 ) ;
if ( F_60 ( & V_113 , V_93 , sizeof( struct V_26 ) ) )
return - V_108 ;
if ( ( unsigned ) V_113 . V_31 >= ~ 0U / sizeof( struct V_29 ) )
return - V_108 ;
V_12 = F_36 ( V_113 . V_36 ) ;
if ( V_113 . V_31 == 0 ) {
V_114 = F_16 ( V_113 . V_36 ) ;
if ( V_114 != NULL ) {
F_32 ( V_50 , & V_114 -> V_49 ) ;
F_32 ( V_48 , & V_114 -> V_49 ) ;
}
if ( V_12 == NULL ) {
return 0 ;
}
return F_39 ( V_113 . V_36 ) ;
} else {
struct V_29 * V_115 ;
if ( V_113 . V_31 >= 16384 )
return - V_59 ;
V_115 = F_14 ( ( sizeof( struct V_29 ) * V_113 . V_31 ) ,
V_32 ) ;
if ( V_115 == NULL )
return - V_34 ;
if ( F_60 ( V_115 , ( void T_7 * ) V_113 . V_33 ,
sizeof( struct V_29 ) * V_113 . V_31 ) ) {
F_7 ( V_115 ) ;
return - V_108 ;
}
V_113 . V_33 = V_115 ;
if ( V_12 == NULL ) {
V_12 = F_38 ( V_113 . V_36 ) ;
if ( V_12 == NULL ) {
F_7 ( V_115 ) ;
return - V_34 ;
}
V_114 = F_16 ( V_113 . V_36 ) ;
if ( V_114 != NULL ) {
F_32 ( V_50 , & V_114 -> V_49 ) ;
F_32 ( V_48 , & V_114 -> V_49 ) ;
}
}
return F_12 ( V_12 , & V_113 ) ;
}
return - V_59 ;
}
int F_63 ( struct V_35 * V_39 )
{
F_2 ( L_11 ) ;
return - V_59 ;
}
static int F_64 ( struct V_35 * V_39 , void T_7 * V_93 )
{
struct V_1 * V_40 ;
struct V_116 V_117 ;
F_2 ( L_11 ) ;
if ( F_60 ( & V_117 , V_93 , sizeof( struct V_116 ) ) )
return - V_108 ;
if ( V_117 . type >= V_118 )
return - V_59 ;
V_40 = F_21 ( V_117 . V_20 , V_117 . type ) ;
if ( V_40 == NULL )
return - V_34 ;
V_117 . V_2 = V_40 -> V_2 ;
V_117 . V_119 = V_40 -> V_119 ;
if ( F_54 ( V_93 , & V_117 , sizeof( struct V_116 ) ) ) {
F_19 ( V_40 ) ;
return - V_108 ;
}
return 0 ;
}
int F_65 ( struct V_35 * V_39 , int V_93 )
{
struct V_1 * V_40 ;
F_2 ( L_11 ) ;
V_40 = F_1 ( V_93 ) ;
if ( V_40 == NULL )
return - V_59 ;
F_19 ( V_40 ) ;
return 0 ;
}
static int F_66 ( struct V_35 * V_39 , void T_7 * V_93 )
{
struct V_120 V_121 ;
struct V_1 * V_40 ;
F_2 ( L_11 ) ;
if ( F_60 ( & V_121 , V_93 , sizeof( struct V_120 ) ) )
return - V_108 ;
V_40 = F_1 ( V_121 . V_2 ) ;
if ( V_40 == NULL )
return - V_59 ;
return F_67 ( V_40 , V_121 . V_19 ) ;
}
static int F_68 ( struct V_35 * V_39 , void T_7 * V_93 )
{
struct V_1 * V_40 ;
struct V_122 V_123 ;
F_2 ( L_11 ) ;
if ( F_60 ( & V_123 , V_93 , sizeof( struct V_122 ) ) )
return - V_108 ;
V_40 = F_1 ( V_123 . V_2 ) ;
if ( V_40 == NULL )
return - V_59 ;
return F_69 ( V_40 ) ;
}
static long F_70 ( struct V_60 * V_60 ,
unsigned int V_124 , unsigned long V_93 )
{
struct V_35 * V_125 = V_60 -> V_64 ;
int V_126 = - V_127 ;
F_2 ( L_12 , V_125 , V_124 ) ;
F_41 ( & ( V_4 . V_67 ) ) ;
if ( ( V_4 . V_5 == NULL ) &&
( V_124 != V_128 ) ) {
V_126 = - V_59 ;
goto V_129;
}
if ( ( V_4 . V_52 != true ) &&
( V_124 != V_128 ) ) {
V_126 = - V_109 ;
goto V_129;
}
if ( V_124 != V_128 ) {
if ( ! ( F_42 ( V_80 , & V_125 -> V_49 ) ) ) {
V_126 = - V_81 ;
goto V_129;
}
if ( V_4 . V_5 -> V_36 != V_125 -> V_38 ) {
V_126 = - V_109 ;
goto V_129;
}
}
switch ( V_124 ) {
case V_130 :
V_126 = F_53 ( V_125 , ( void T_7 * ) V_93 ) ;
break;
case V_128 :
V_126 = F_55 ( V_125 ) ;
break;
case V_131 :
V_126 = F_58 ( V_125 ) ;
break;
case V_132 :
V_126 = F_59 ( V_125 , ( void T_7 * ) V_93 ) ;
break;
case V_133 :
V_126 = F_62 ( V_125 , ( void T_7 * ) V_93 ) ;
break;
case V_134 :
V_126 = F_63 ( V_125 ) ;
break;
case V_135 :
V_126 = F_64 ( V_125 , ( void T_7 * ) V_93 ) ;
break;
case V_136 :
V_126 = F_65 ( V_125 , ( int ) V_93 ) ;
break;
case V_137 :
V_126 = F_66 ( V_125 , ( void T_7 * ) V_93 ) ;
break;
case V_138 :
V_126 = F_68 ( V_125 , ( void T_7 * ) V_93 ) ;
break;
case V_139 :
break;
}
V_129:
F_2 ( L_13 , V_126 ) ;
F_46 ( & ( V_4 . V_67 ) ) ;
return V_126 ;
}
int F_71 ( void )
{
memset ( & V_4 , 0 , sizeof( struct V_140 ) ) ;
F_72 ( & ( V_4 . V_67 ) ) ;
if ( F_73 ( & V_141 ) ) {
F_74 (KERN_ERR PFX L_14 , AGPGART_MINOR) ;
return - V_142 ;
}
return 0 ;
}
void F_75 ( void )
{
F_76 ( & V_141 ) ;
}
