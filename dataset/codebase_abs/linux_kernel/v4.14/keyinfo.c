static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_3 == - V_7 )
return;
V_5 -> V_8 = V_3 ;
F_2 ( & V_5 -> V_9 ) ;
}
static int F_3 ( T_1 V_10 [ V_11 ] ,
const struct V_12 * V_13 ,
T_1 V_14 [ V_15 ] )
{
int V_8 = 0 ;
struct V_16 * V_2 = NULL ;
F_4 ( V_5 ) ;
struct V_17 V_18 , V_19 ;
struct V_20 * V_21 = F_5 ( L_1 , 0 , 0 ) ;
if ( F_6 ( V_21 ) ) {
V_8 = F_7 ( V_21 ) ;
V_21 = NULL ;
goto V_22;
}
F_8 ( V_21 , V_23 ) ;
V_2 = F_9 ( V_21 , V_24 ) ;
if ( ! V_2 ) {
V_8 = - V_25 ;
goto V_22;
}
F_10 ( V_2 ,
V_26 | V_27 ,
F_1 , & V_5 ) ;
V_8 = F_11 ( V_21 , V_10 ,
V_11 ) ;
if ( V_8 < 0 )
goto V_22;
F_12 ( & V_18 , V_13 -> V_28 , V_13 -> V_29 ) ;
F_12 ( & V_19 , V_14 , V_13 -> V_29 ) ;
F_13 ( V_2 , & V_18 , & V_19 , V_13 -> V_29 ,
NULL ) ;
V_8 = F_14 ( V_2 ) ;
if ( V_8 == - V_7 || V_8 == - V_30 ) {
F_15 ( & V_5 . V_9 ) ;
V_8 = V_5 . V_8 ;
}
V_22:
F_16 ( V_2 ) ;
F_17 ( V_21 ) ;
return V_8 ;
}
static int F_18 ( struct V_31 * V_32 ,
struct V_33 * V_34 , T_1 * V_35 ,
const char * V_36 , int V_37 )
{
char * V_38 ;
struct V_39 * V_40 ;
struct V_12 * V_41 ;
const struct V_42 * V_43 ;
int V_8 ;
V_38 = F_19 ( V_24 , L_2 , V_36 ,
V_44 ,
V_34 -> V_45 ) ;
if ( ! V_38 )
return - V_25 ;
V_40 = F_20 ( & V_46 , V_38 , NULL ) ;
F_21 ( V_38 ) ;
if ( F_6 ( V_40 ) )
return F_7 ( V_40 ) ;
F_22 ( & V_40 -> V_47 ) ;
if ( V_40 -> type != & V_46 ) {
F_23 ( V_48
L_3 , V_49 ) ;
V_8 = - V_50 ;
goto V_22;
}
V_43 = F_24 ( V_40 ) ;
if ( ! V_43 ) {
V_8 = - V_51 ;
goto V_22;
}
if ( V_43 -> V_52 != sizeof( struct V_12 ) ) {
V_8 = - V_53 ;
goto V_22;
}
V_41 = (struct V_12 * ) V_43 -> V_6 ;
F_25 ( V_11 != V_54 ) ;
if ( V_41 -> V_29 < V_37 || V_41 -> V_29 > V_15
|| V_41 -> V_29 % V_55 != 0 ) {
F_23 ( V_48
L_4 ,
V_49 , V_41 -> V_29 ) ;
V_8 = - V_50 ;
goto V_22;
}
V_8 = F_3 ( V_34 -> V_56 , V_41 , V_35 ) ;
V_22:
F_26 ( & V_40 -> V_47 ) ;
F_27 ( V_40 ) ;
return V_8 ;
}
static int F_28 ( struct V_31 * V_57 , struct V_58 * V_58 ,
const char * * V_59 , int * V_60 )
{
T_2 V_61 ;
if ( ! F_29 ( V_57 -> V_62 , V_57 -> V_63 ) ) {
F_30 ( L_5 ,
V_58 -> V_64 ,
V_57 -> V_62 , V_57 -> V_63 ) ;
return - V_53 ;
}
if ( F_31 ( V_58 -> V_65 ) ) {
V_61 = V_57 -> V_62 ;
} else if ( F_32 ( V_58 -> V_65 ) || F_33 ( V_58 -> V_65 ) ) {
V_61 = V_57 -> V_63 ;
} else {
F_34 ( 1 , L_6 ,
V_58 -> V_64 , ( V_58 -> V_65 & V_66 ) ) ;
return - V_53 ;
}
* V_59 = V_67 [ V_61 ] . V_68 ;
* V_60 = V_67 [ V_61 ] . V_69 ;
return 0 ;
}
static void F_35 ( struct V_31 * V_57 )
{
if ( ! V_57 )
return;
F_17 ( V_57 -> V_70 ) ;
F_36 ( V_57 -> V_71 ) ;
F_37 ( V_72 , V_57 ) ;
}
static int F_38 ( const T_1 * V_39 , int V_69 , T_1 * V_73 )
{
struct V_74 * V_21 = F_39 ( V_75 ) ;
if ( F_40 ( ! V_21 ) ) {
struct V_74 * V_76 ;
V_21 = F_41 ( L_7 , 0 , 0 ) ;
if ( F_6 ( V_21 ) ) {
F_30 ( L_8 ,
F_7 ( V_21 ) ) ;
return F_7 ( V_21 ) ;
}
V_76 = F_42 ( & V_75 , NULL , V_21 ) ;
if ( V_76 ) {
F_43 ( V_21 ) ;
V_21 = V_76 ;
}
}
{
F_44 ( V_77 , V_21 ) ;
V_77 -> V_21 = V_21 ;
V_77 -> V_78 = 0 ;
return F_45 ( V_77 , V_39 , V_69 , V_73 ) ;
}
}
static int F_46 ( struct V_31 * V_57 , const T_1 * V_35 ,
int V_69 )
{
int V_79 ;
struct V_80 * V_81 ;
T_1 V_73 [ V_82 ] ;
V_81 = F_47 ( L_9 , 0 , 0 ) ;
if ( F_6 ( V_81 ) )
return F_7 ( V_81 ) ;
V_57 -> V_71 = V_81 ;
V_79 = F_38 ( V_35 , V_69 , V_73 ) ;
if ( V_79 )
goto V_22;
V_79 = F_48 ( V_81 , V_73 , sizeof( V_73 ) ) ;
if ( V_79 )
goto V_22;
V_22:
F_49 ( V_73 , sizeof( V_73 ) ) ;
return V_79 ;
}
void T_3 F_50 ( void )
{
F_43 ( V_75 ) ;
}
int F_51 ( struct V_58 * V_58 )
{
struct V_31 * V_32 ;
struct V_33 V_34 ;
struct V_20 * V_83 ;
const char * V_68 ;
int V_69 ;
T_1 * V_35 = NULL ;
int V_8 ;
if ( V_58 -> V_84 )
return 0 ;
V_8 = F_52 ( V_58 -> V_85 -> V_86 -> V_78 ) ;
if ( V_8 )
return V_8 ;
V_8 = V_58 -> V_85 -> V_86 -> V_87 ( V_58 , & V_34 , sizeof( V_34 ) ) ;
if ( V_8 < 0 ) {
if ( ! F_53 ( V_58 ) ||
V_58 -> V_85 -> V_86 -> V_88 ( V_58 ) )
return V_8 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_89 = V_90 ;
V_34 . V_91 = V_92 ;
V_34 . V_93 = V_94 ;
memset ( V_34 . V_45 , 0x42 , V_44 ) ;
} else if ( V_8 != sizeof( V_34 ) ) {
return - V_53 ;
}
if ( V_34 . V_89 != V_90 )
return - V_53 ;
if ( V_34 . V_78 & ~ V_95 )
return - V_53 ;
V_32 = F_54 ( V_72 , V_24 ) ;
if ( ! V_32 )
return - V_25 ;
V_32 -> V_96 = V_34 . V_78 ;
V_32 -> V_62 = V_34 . V_91 ;
V_32 -> V_63 = V_34 . V_93 ;
V_32 -> V_70 = NULL ;
V_32 -> V_71 = NULL ;
memcpy ( V_32 -> V_97 , V_34 . V_45 ,
sizeof( V_32 -> V_97 ) ) ;
V_8 = F_28 ( V_32 , V_58 , & V_68 , & V_69 ) ;
if ( V_8 )
goto V_22;
V_8 = - V_25 ;
V_35 = F_55 ( V_15 , V_24 ) ;
if ( ! V_35 )
goto V_22;
V_8 = F_18 ( V_32 , & V_34 , V_35 , V_98 ,
V_69 ) ;
if ( V_8 && V_58 -> V_85 -> V_86 -> V_99 ) {
int V_100 = F_18 ( V_32 , & V_34 , V_35 ,
V_58 -> V_85 -> V_86 -> V_99 ,
V_69 ) ;
if ( V_100 ) {
if ( V_100 == - V_50 )
V_8 = - V_50 ;
goto V_22;
}
} else if ( V_8 ) {
goto V_22;
}
V_83 = F_5 ( V_68 , 0 , 0 ) ;
if ( ! V_83 || F_6 ( V_83 ) ) {
V_8 = V_83 ? F_7 ( V_83 ) : - V_25 ;
F_56 ( L_10 ,
V_49 , V_8 , V_58 -> V_64 ) ;
goto V_22;
}
V_32 -> V_70 = V_83 ;
F_57 ( V_83 , ~ 0 ) ;
F_8 ( V_83 , V_23 ) ;
V_8 = F_11 ( V_83 , V_35 , V_69 ) ;
if ( V_8 )
goto V_22;
if ( F_31 ( V_58 -> V_65 ) &&
V_32 -> V_62 == V_101 ) {
V_8 = F_46 ( V_32 , V_35 , V_69 ) ;
if ( V_8 ) {
F_56 ( L_11 ,
V_49 , V_8 , V_58 -> V_64 ) ;
goto V_22;
}
}
if ( F_42 ( & V_58 -> V_84 , NULL , V_32 ) == NULL )
V_32 = NULL ;
V_22:
if ( V_8 == - V_50 )
V_8 = 0 ;
F_35 ( V_32 ) ;
F_58 ( V_35 ) ;
return V_8 ;
}
void F_59 ( struct V_58 * V_58 , struct V_31 * V_57 )
{
struct V_31 * V_102 ;
if ( V_57 == NULL )
V_57 = F_60 ( V_58 -> V_84 ) ;
if ( V_57 == NULL )
return;
V_102 = F_42 ( & V_58 -> V_84 , V_57 , NULL ) ;
if ( V_102 != V_57 )
return;
F_35 ( V_57 ) ;
}
