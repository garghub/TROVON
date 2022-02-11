static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_3 == - V_7 )
return;
V_5 -> V_8 = V_3 ;
F_2 ( & V_5 -> V_9 ) ;
}
static int F_3 ( T_1 V_10 [ V_11 ] ,
T_1 V_12 [ V_13 ] ,
T_1 V_14 [ V_13 ] )
{
int V_8 = 0 ;
struct V_15 * V_2 = NULL ;
F_4 ( V_5 ) ;
struct V_16 V_17 , V_18 ;
struct V_19 * V_20 = F_5 ( L_1 , 0 , 0 ) ;
if ( F_6 ( V_20 ) ) {
V_8 = F_7 ( V_20 ) ;
V_20 = NULL ;
goto V_21;
}
F_8 ( V_20 , V_22 ) ;
V_2 = F_9 ( V_20 , V_23 ) ;
if ( ! V_2 ) {
V_8 = - V_24 ;
goto V_21;
}
F_10 ( V_2 ,
V_25 | V_26 ,
F_1 , & V_5 ) ;
V_8 = F_11 ( V_20 , V_10 ,
V_11 ) ;
if ( V_8 < 0 )
goto V_21;
F_12 ( & V_17 , V_12 , V_13 ) ;
F_12 ( & V_18 , V_14 , V_13 ) ;
F_13 ( V_2 , & V_17 , & V_18 ,
V_13 , NULL ) ;
V_8 = F_14 ( V_2 ) ;
if ( V_8 == - V_7 || V_8 == - V_27 ) {
F_15 ( & V_5 . V_9 ) ;
V_8 = V_5 . V_8 ;
}
V_21:
F_16 ( V_2 ) ;
F_17 ( V_20 ) ;
return V_8 ;
}
static int F_18 ( struct V_28 * V_29 ,
struct V_30 * V_31 , T_1 * V_32 ,
T_1 * V_33 , int V_34 )
{
T_1 * V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
const struct V_40 * V_41 ;
int V_42 = V_34 + ( V_43 * 2 ) + 1 ;
int V_8 ;
V_35 = F_19 ( V_42 , V_23 ) ;
if ( ! V_35 )
return - V_24 ;
memcpy ( V_35 , V_33 , V_34 ) ;
sprintf ( V_35 + V_34 ,
L_2 , V_43 ,
V_31 -> V_44 ) ;
V_35 [ V_42 - 1 ] = '\0' ;
V_37 = F_20 ( & V_45 , V_35 , NULL ) ;
F_21 ( V_35 ) ;
if ( F_6 ( V_37 ) )
return F_7 ( V_37 ) ;
if ( V_37 -> type != & V_45 ) {
F_22 ( V_46
L_3 , V_47 ) ;
V_8 = - V_48 ;
goto V_21;
}
F_23 ( & V_37 -> V_49 ) ;
V_41 = V_40 ( V_37 ) ;
if ( V_41 -> V_50 != sizeof( struct V_38 ) ) {
V_8 = - V_51 ;
F_24 ( & V_37 -> V_49 ) ;
goto V_21;
}
V_39 = (struct V_38 * ) V_41 -> V_6 ;
F_25 ( V_11 != V_52 ) ;
if ( V_39 -> V_53 != V_13 ) {
F_22 ( V_46
L_4 ,
V_47 , V_39 -> V_53 ) ;
V_8 = - V_48 ;
F_24 ( & V_37 -> V_49 ) ;
goto V_21;
}
V_8 = F_3 ( V_31 -> V_54 , V_39 -> V_55 , V_32 ) ;
F_24 ( & V_37 -> V_49 ) ;
if ( V_8 )
goto V_21;
V_29 -> V_56 = V_37 ;
return 0 ;
V_21:
F_26 ( V_37 ) ;
return V_8 ;
}
static int F_27 ( struct V_28 * V_57 , struct V_58 * V_58 ,
const char * * V_59 , int * V_60 )
{
if ( F_28 ( V_58 -> V_61 ) ) {
if ( V_57 -> V_62 == V_63 ) {
* V_59 = L_5 ;
* V_60 = V_13 ;
return 0 ;
}
F_29 ( L_6
L_7 ,
V_57 -> V_62 , V_58 -> V_64 ) ;
return - V_48 ;
}
if ( F_30 ( V_58 -> V_61 ) || F_31 ( V_58 -> V_61 ) ) {
if ( V_57 -> V_65 == V_66 ) {
* V_59 = L_8 ;
* V_60 = V_67 ;
return 0 ;
}
F_29 ( L_9
L_7 ,
V_57 -> V_65 , V_58 -> V_64 ) ;
return - V_48 ;
}
F_29 ( L_10 ,
( V_58 -> V_61 & V_68 ) , V_58 -> V_64 ) ;
return - V_48 ;
}
static void F_32 ( struct V_28 * V_57 )
{
if ( ! V_57 )
return;
F_26 ( V_57 -> V_56 ) ;
F_17 ( V_57 -> V_69 ) ;
F_33 ( V_70 , V_57 ) ;
}
int F_34 ( struct V_58 * V_58 )
{
struct V_28 * V_29 ;
struct V_30 V_31 ;
struct V_19 * V_71 ;
const char * V_72 ;
int V_73 ;
T_1 * V_32 = NULL ;
int V_8 ;
V_8 = F_35 ( V_58 -> V_74 -> V_75 -> V_76 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_58 -> V_74 -> V_75 -> V_77 )
return - V_78 ;
V_79:
V_29 = F_36 ( V_58 -> V_80 ) ;
if ( V_29 ) {
if ( ! V_29 -> V_56 ||
F_37 ( V_29 -> V_56 ) == 0 )
return 0 ;
F_38 ( V_58 , V_29 ) ;
goto V_79;
}
V_8 = V_58 -> V_74 -> V_75 -> V_77 ( V_58 , & V_31 , sizeof( V_31 ) ) ;
if ( V_8 < 0 ) {
if ( ! F_39 ( V_58 ) )
return V_8 ;
V_31 . V_81 = V_82 ;
V_31 . V_83 = V_63 ;
V_31 . V_84 = V_66 ;
V_31 . V_76 = 0 ;
} else if ( V_8 != sizeof( V_31 ) ) {
return - V_51 ;
}
if ( V_31 . V_81 != V_82 )
return - V_51 ;
if ( V_31 . V_76 & ~ V_85 )
return - V_51 ;
V_29 = F_40 ( V_70 , V_23 ) ;
if ( ! V_29 )
return - V_24 ;
V_29 -> V_86 = V_31 . V_76 ;
V_29 -> V_62 = V_31 . V_83 ;
V_29 -> V_65 = V_31 . V_84 ;
V_29 -> V_69 = NULL ;
V_29 -> V_56 = NULL ;
memcpy ( V_29 -> V_87 , V_31 . V_44 ,
sizeof( V_29 -> V_87 ) ) ;
V_8 = F_27 ( V_29 , V_58 , & V_72 , & V_73 ) ;
if ( V_8 )
goto V_21;
V_8 = - V_24 ;
V_32 = F_19 ( V_88 , V_23 ) ;
if ( ! V_32 )
goto V_21;
if ( F_39 ( V_58 ) ) {
memset ( V_32 , 0x42 , V_73 / 2 ) ;
memset ( V_32 + V_73 / 2 , 0x24 , V_73 - ( V_73 / 2 ) ) ;
goto V_89;
}
V_8 = F_18 ( V_29 , & V_31 , V_32 ,
V_90 , V_91 ) ;
if ( V_8 && V_58 -> V_74 -> V_75 -> V_92 ) {
T_1 * V_33 = NULL ;
int V_34 , V_93 ;
V_34 = V_58 -> V_74 -> V_75 -> V_92 ( V_58 , & V_33 ) ;
V_93 = F_18 ( V_29 , & V_31 , V_32 ,
V_33 , V_34 ) ;
if ( V_93 ) {
if ( V_93 == - V_48 )
V_8 = - V_48 ;
goto V_21;
}
} else if ( V_8 ) {
goto V_21;
}
V_89:
V_71 = F_5 ( V_72 , 0 , 0 ) ;
if ( ! V_71 || F_6 ( V_71 ) ) {
V_8 = V_71 ? F_7 ( V_71 ) : - V_24 ;
F_41 ( V_94
L_11 ,
V_47 , V_8 , ( unsigned ) V_58 -> V_64 ) ;
goto V_21;
}
V_29 -> V_69 = V_71 ;
F_42 ( V_71 , ~ 0 ) ;
F_8 ( V_71 , V_22 ) ;
V_8 = F_11 ( V_71 , V_32 , V_73 ) ;
if ( V_8 )
goto V_21;
F_43 ( V_32 ) ;
V_32 = NULL ;
if ( F_44 ( & V_58 -> V_80 , NULL , V_29 ) != NULL ) {
F_32 ( V_29 ) ;
goto V_79;
}
return 0 ;
V_21:
if ( V_8 == - V_48 )
V_8 = 0 ;
F_32 ( V_29 ) ;
F_43 ( V_32 ) ;
return V_8 ;
}
void F_38 ( struct V_58 * V_58 , struct V_28 * V_57 )
{
struct V_28 * V_95 ;
if ( V_57 == NULL )
V_57 = F_36 ( V_58 -> V_80 ) ;
if ( V_57 == NULL )
return;
V_95 = F_44 ( & V_58 -> V_80 , V_57 , NULL ) ;
if ( V_95 != V_57 )
return;
F_32 ( V_57 ) ;
}
int F_45 ( struct V_58 * V_58 )
{
struct V_28 * V_57 = V_58 -> V_80 ;
if ( ! V_57 ||
( V_57 -> V_56 &&
( V_57 -> V_56 -> V_76 & ( ( 1 << V_96 ) |
( 1 << V_97 ) |
( 1 << V_98 ) ) ) ) )
return F_34 ( V_58 ) ;
return 0 ;
}
