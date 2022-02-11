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
const char * V_33 )
{
char * V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
const struct V_39 * V_40 ;
int V_8 ;
V_34 = F_19 ( V_23 , L_2 , V_33 ,
V_41 ,
V_31 -> V_42 ) ;
if ( ! V_34 )
return - V_24 ;
V_36 = F_20 ( & V_43 , V_34 , NULL ) ;
F_21 ( V_34 ) ;
if ( F_6 ( V_36 ) )
return F_7 ( V_36 ) ;
F_22 ( & V_36 -> V_44 ) ;
if ( V_36 -> type != & V_43 ) {
F_23 ( V_45
L_3 , V_46 ) ;
V_8 = - V_47 ;
goto V_21;
}
V_40 = F_24 ( V_36 ) ;
if ( V_40 -> V_48 != sizeof( struct V_37 ) ) {
V_8 = - V_49 ;
goto V_21;
}
V_38 = (struct V_37 * ) V_40 -> V_6 ;
F_25 ( V_11 != V_50 ) ;
if ( V_38 -> V_51 != V_13 ) {
F_23 ( V_45
L_4 ,
V_46 , V_38 -> V_51 ) ;
V_8 = - V_47 ;
goto V_21;
}
V_8 = F_3 ( V_31 -> V_52 , V_38 -> V_53 , V_32 ) ;
V_21:
F_26 ( & V_36 -> V_44 ) ;
F_27 ( V_36 ) ;
return V_8 ;
}
static int F_28 ( struct V_28 * V_54 , struct V_55 * V_55 ,
const char * * V_56 , int * V_57 )
{
if ( F_29 ( V_55 -> V_58 ) ) {
if ( V_54 -> V_59 == V_60 ) {
* V_56 = L_5 ;
* V_57 = V_13 ;
return 0 ;
}
F_30 ( L_6
L_7 ,
V_54 -> V_59 , V_55 -> V_61 ) ;
return - V_47 ;
}
if ( F_31 ( V_55 -> V_58 ) || F_32 ( V_55 -> V_58 ) ) {
if ( V_54 -> V_62 == V_63 ) {
* V_56 = L_8 ;
* V_57 = V_64 ;
return 0 ;
}
F_30 ( L_9
L_7 ,
V_54 -> V_62 , V_55 -> V_61 ) ;
return - V_47 ;
}
F_30 ( L_10 ,
( V_55 -> V_58 & V_65 ) , V_55 -> V_61 ) ;
return - V_47 ;
}
static void F_33 ( struct V_28 * V_54 )
{
if ( ! V_54 )
return;
F_17 ( V_54 -> V_66 ) ;
F_34 ( V_67 , V_54 ) ;
}
int F_35 ( struct V_55 * V_55 )
{
struct V_28 * V_29 ;
struct V_30 V_31 ;
struct V_19 * V_68 ;
const char * V_69 ;
int V_70 ;
T_1 * V_32 = NULL ;
int V_8 ;
if ( V_55 -> V_71 )
return 0 ;
V_8 = F_36 ( V_55 -> V_72 -> V_73 -> V_74 ) ;
if ( V_8 )
return V_8 ;
V_8 = V_55 -> V_72 -> V_73 -> V_75 ( V_55 , & V_31 , sizeof( V_31 ) ) ;
if ( V_8 < 0 ) {
if ( ! F_37 ( V_55 ) ||
V_55 -> V_72 -> V_73 -> V_76 ( V_55 ) )
return V_8 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_77 = V_78 ;
V_31 . V_79 = V_60 ;
V_31 . V_80 = V_63 ;
memset ( V_31 . V_42 , 0x42 , V_41 ) ;
} else if ( V_8 != sizeof( V_31 ) ) {
return - V_49 ;
}
if ( V_31 . V_77 != V_78 )
return - V_49 ;
if ( V_31 . V_74 & ~ V_81 )
return - V_49 ;
V_29 = F_38 ( V_67 , V_23 ) ;
if ( ! V_29 )
return - V_24 ;
V_29 -> V_82 = V_31 . V_74 ;
V_29 -> V_59 = V_31 . V_79 ;
V_29 -> V_62 = V_31 . V_80 ;
V_29 -> V_66 = NULL ;
memcpy ( V_29 -> V_83 , V_31 . V_42 ,
sizeof( V_29 -> V_83 ) ) ;
V_8 = F_28 ( V_29 , V_55 , & V_69 , & V_70 ) ;
if ( V_8 )
goto V_21;
V_8 = - V_24 ;
V_32 = F_39 ( V_84 , V_23 ) ;
if ( ! V_32 )
goto V_21;
V_8 = F_18 ( V_29 , & V_31 , V_32 , V_85 ) ;
if ( V_8 && V_55 -> V_72 -> V_73 -> V_86 ) {
int V_87 = F_18 ( V_29 , & V_31 , V_32 ,
V_55 -> V_72 -> V_73 -> V_86 ) ;
if ( V_87 ) {
if ( V_87 == - V_47 )
V_8 = - V_47 ;
goto V_21;
}
} else if ( V_8 ) {
goto V_21;
}
V_68 = F_5 ( V_69 , 0 , 0 ) ;
if ( ! V_68 || F_6 ( V_68 ) ) {
V_8 = V_68 ? F_7 ( V_68 ) : - V_24 ;
F_40 ( V_88
L_11 ,
V_46 , V_8 , ( unsigned ) V_55 -> V_61 ) ;
goto V_21;
}
V_29 -> V_66 = V_68 ;
F_41 ( V_68 , ~ 0 ) ;
F_8 ( V_68 , V_22 ) ;
V_8 = F_11 ( V_68 , V_32 , V_70 ) ;
if ( V_8 )
goto V_21;
if ( F_42 ( & V_55 -> V_71 , NULL , V_29 ) == NULL )
V_29 = NULL ;
V_21:
if ( V_8 == - V_47 )
V_8 = 0 ;
F_33 ( V_29 ) ;
F_43 ( V_32 ) ;
return V_8 ;
}
void F_44 ( struct V_55 * V_55 , struct V_28 * V_54 )
{
struct V_28 * V_89 ;
if ( V_54 == NULL )
V_54 = F_45 ( V_55 -> V_71 ) ;
if ( V_54 == NULL )
return;
V_89 = F_42 ( & V_55 -> V_71 , V_54 , NULL ) ;
if ( V_89 != V_54 )
return;
F_33 ( V_54 ) ;
}
