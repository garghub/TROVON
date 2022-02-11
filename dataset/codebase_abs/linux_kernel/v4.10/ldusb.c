static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
V_2 -> V_3 = 0 ;
if ( V_2 -> V_4 )
F_2 ( V_2 -> V_5 ) ;
}
if ( V_2 -> V_6 )
if ( V_2 -> V_4 )
F_2 ( V_2 -> V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_4 ( V_2 -> V_5 ) ;
F_4 ( V_2 -> V_7 ) ;
F_5 ( V_2 -> V_8 ) ;
F_5 ( V_2 -> V_9 ) ;
F_5 ( V_2 -> V_10 ) ;
F_5 ( V_2 ) ;
}
static void F_6 ( struct V_11 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 ;
T_1 * V_13 ;
unsigned int V_14 ;
int V_15 = V_11 -> V_15 ;
int V_16 ;
if ( V_15 ) {
if ( V_15 == - V_17 ||
V_15 == - V_18 ||
V_15 == - V_19 ) {
goto exit;
} else {
F_7 ( & V_2 -> V_4 -> V_2 ,
L_1 , V_20 ,
V_15 ) ;
F_8 ( & V_2 -> V_21 ) ;
goto V_22;
}
}
F_8 ( & V_2 -> V_21 ) ;
if ( V_11 -> V_23 > 0 ) {
V_14 = ( V_2 -> V_24 + 1 ) % V_25 ;
if ( V_14 != V_2 -> V_26 ) {
V_13 = ( T_1 * ) ( V_2 -> V_8 + V_2 -> V_24 * ( sizeof( T_1 ) + V_2 -> V_27 ) ) ;
* V_13 = V_11 -> V_23 ;
memcpy ( V_13 + 1 , V_2 -> V_9 , V_11 -> V_23 ) ;
V_2 -> V_24 = V_14 ;
F_7 ( & V_2 -> V_4 -> V_2 , L_2 ,
V_20 , V_11 -> V_23 ) ;
} else {
F_9 ( & V_2 -> V_4 -> V_2 ,
L_3 ,
V_11 -> V_23 ) ;
V_2 -> V_28 = 1 ;
}
}
V_22:
if ( V_2 -> V_3 && ! V_2 -> V_28 && V_2 -> V_4 ) {
V_16 = F_10 ( V_2 -> V_5 , V_29 ) ;
if ( V_16 ) {
F_11 ( & V_2 -> V_4 -> V_2 ,
L_4 , V_16 ) ;
V_2 -> V_28 = 1 ;
}
}
F_12 ( & V_2 -> V_21 ) ;
exit:
V_2 -> V_30 = 1 ;
F_13 ( & V_2 -> V_31 ) ;
}
static void F_14 ( struct V_11 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 ;
int V_15 = V_11 -> V_15 ;
if ( V_15 && ! ( V_15 == - V_17 ||
V_15 == - V_18 ||
V_15 == - V_19 ) )
F_7 ( & V_2 -> V_4 -> V_2 ,
L_5 ,
V_20 , V_15 ) ;
V_2 -> V_6 = 0 ;
F_13 ( & V_2 -> V_32 ) ;
}
static int F_15 ( struct V_33 * V_33 , struct V_34 * V_34 )
{
struct V_1 * V_2 ;
int V_35 ;
int V_16 ;
struct V_36 * V_37 ;
F_16 ( V_33 , V_34 ) ;
V_35 = F_17 ( V_33 ) ;
V_37 = F_18 ( & V_38 , V_35 ) ;
if ( ! V_37 ) {
F_19 ( V_39 L_6 ,
V_20 , V_35 ) ;
return - V_40 ;
}
V_2 = F_20 ( V_37 ) ;
if ( ! V_2 )
return - V_40 ;
if ( F_21 ( & V_2 -> V_41 ) )
return - V_42 ;
if ( V_2 -> V_43 ) {
V_16 = - V_44 ;
goto V_45;
}
V_2 -> V_43 = 1 ;
V_2 -> V_24 = 0 ;
V_2 -> V_26 = 0 ;
V_2 -> V_28 = 0 ;
F_22 ( V_2 -> V_5 ,
F_23 ( V_37 ) ,
F_24 ( F_23 ( V_37 ) ,
V_2 -> V_46 -> V_47 ) ,
V_2 -> V_9 ,
V_2 -> V_27 ,
F_6 ,
V_2 ,
V_2 -> V_48 ) ;
V_2 -> V_3 = 1 ;
V_2 -> V_30 = 0 ;
V_16 = F_10 ( V_2 -> V_5 , V_49 ) ;
if ( V_16 ) {
F_11 ( & V_37 -> V_2 , L_7 , V_16 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_43 = 0 ;
goto V_45;
}
V_34 -> V_50 = V_2 ;
V_45:
F_25 ( & V_2 -> V_41 ) ;
return V_16 ;
}
static int F_26 ( struct V_33 * V_33 , struct V_34 * V_34 )
{
struct V_1 * V_2 ;
int V_16 = 0 ;
V_2 = V_34 -> V_50 ;
if ( V_2 == NULL ) {
V_16 = - V_40 ;
goto exit;
}
if ( F_21 ( & V_2 -> V_41 ) ) {
V_16 = - V_42 ;
goto exit;
}
if ( V_2 -> V_43 != 1 ) {
V_16 = - V_40 ;
goto V_45;
}
if ( V_2 -> V_4 == NULL ) {
F_25 ( & V_2 -> V_41 ) ;
F_3 ( V_2 ) ;
goto exit;
}
if ( V_2 -> V_6 )
F_27 ( V_2 -> V_32 , ! V_2 -> V_6 , 2 * V_51 ) ;
F_1 ( V_2 ) ;
V_2 -> V_43 = 0 ;
V_45:
F_25 ( & V_2 -> V_41 ) ;
exit:
return V_16 ;
}
static unsigned int F_28 ( struct V_34 * V_34 , T_2 * V_52 )
{
struct V_1 * V_2 ;
unsigned int V_53 = 0 ;
V_2 = V_34 -> V_50 ;
if ( ! V_2 -> V_4 )
return V_54 | V_55 ;
F_29 ( V_34 , & V_2 -> V_31 , V_52 ) ;
F_29 ( V_34 , & V_2 -> V_32 , V_52 ) ;
if ( V_2 -> V_24 != V_2 -> V_26 )
V_53 |= V_56 | V_57 ;
if ( ! V_2 -> V_6 )
V_53 |= V_58 | V_59 ;
return V_53 ;
}
static T_3 F_30 ( struct V_34 * V_34 , char T_4 * V_60 , T_1 V_61 ,
T_5 * V_62 )
{
struct V_1 * V_2 ;
T_1 * V_13 ;
T_1 V_63 ;
int V_16 = 0 ;
int V_64 ;
V_2 = V_34 -> V_50 ;
if ( V_61 == 0 )
goto exit;
if ( F_21 ( & V_2 -> V_41 ) ) {
V_16 = - V_42 ;
goto exit;
}
if ( V_2 -> V_4 == NULL ) {
V_16 = - V_40 ;
F_19 ( V_39 L_8 , V_16 ) ;
goto V_45;
}
F_31 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_24 == V_2 -> V_26 ) {
V_2 -> V_30 = 0 ;
F_32 ( & V_2 -> V_21 ) ;
if ( V_34 -> V_65 & V_66 ) {
V_16 = - V_67 ;
goto V_45;
}
V_16 = F_33 ( V_2 -> V_31 , V_2 -> V_30 ) ;
if ( V_16 < 0 )
goto V_45;
} else {
F_32 ( & V_2 -> V_21 ) ;
}
V_13 = ( T_1 * ) ( V_2 -> V_8 + V_2 -> V_26 * ( sizeof( T_1 ) + V_2 -> V_27 ) ) ;
V_63 = F_34 ( V_61 , * V_13 ) ;
if ( V_63 < * V_13 )
F_9 ( & V_2 -> V_4 -> V_2 , L_9 ,
* V_13 - V_63 ) ;
if ( F_35 ( V_60 , V_13 + 1 , V_63 ) ) {
V_16 = - V_68 ;
goto V_45;
}
V_2 -> V_26 = ( V_2 -> V_26 + 1 ) % V_25 ;
V_16 = V_63 ;
F_31 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_28 ) {
V_2 -> V_28 = 0 ;
F_32 ( & V_2 -> V_21 ) ;
V_64 = F_10 ( V_2 -> V_5 , V_49 ) ;
if ( V_64 < 0 )
V_2 -> V_28 = 1 ;
} else {
F_32 ( & V_2 -> V_21 ) ;
}
V_45:
F_25 ( & V_2 -> V_41 ) ;
exit:
return V_16 ;
}
static T_3 F_36 ( struct V_34 * V_34 , const char T_4 * V_60 ,
T_1 V_61 , T_5 * V_62 )
{
struct V_1 * V_2 ;
T_1 V_69 ;
int V_16 = 0 ;
V_2 = V_34 -> V_50 ;
if ( V_61 == 0 )
goto exit;
if ( F_21 ( & V_2 -> V_41 ) ) {
V_16 = - V_42 ;
goto exit;
}
if ( V_2 -> V_4 == NULL ) {
V_16 = - V_40 ;
F_19 ( V_39 L_8 , V_16 ) ;
goto V_45;
}
if ( V_2 -> V_6 ) {
if ( V_34 -> V_65 & V_66 ) {
V_16 = - V_67 ;
goto V_45;
}
V_16 = F_33 ( V_2 -> V_32 , ! V_2 -> V_6 ) ;
if ( V_16 < 0 ) {
goto V_45;
}
}
V_69 = F_34 ( V_61 , V_70 * V_2 -> V_71 ) ;
if ( V_69 < V_61 )
F_9 ( & V_2 -> V_4 -> V_2 , L_10 , V_61 - V_69 ) ;
F_7 ( & V_2 -> V_4 -> V_2 , L_11 ,
V_20 , V_61 , V_69 ) ;
if ( F_37 ( V_2 -> V_10 , V_60 , V_69 ) ) {
V_16 = - V_68 ;
goto V_45;
}
if ( V_2 -> V_72 == NULL ) {
V_16 = F_38 ( F_23 ( V_2 -> V_4 ) ,
F_39 ( F_23 ( V_2 -> V_4 ) , 0 ) ,
9 ,
V_73 | V_74 | V_75 ,
1 << 8 , 0 ,
V_2 -> V_10 ,
V_69 ,
V_76 * V_51 ) ;
if ( V_16 < 0 )
F_11 ( & V_2 -> V_4 -> V_2 ,
L_12 ,
V_16 ) ;
goto V_45;
}
F_22 ( V_2 -> V_7 ,
F_23 ( V_2 -> V_4 ) ,
F_40 ( F_23 ( V_2 -> V_4 ) ,
V_2 -> V_72 -> V_47 ) ,
V_2 -> V_10 ,
V_69 ,
F_14 ,
V_2 ,
V_2 -> V_77 ) ;
V_2 -> V_6 = 1 ;
F_41 () ;
V_16 = F_10 ( V_2 -> V_7 , V_49 ) ;
if ( V_16 ) {
V_2 -> V_6 = 0 ;
F_11 ( & V_2 -> V_4 -> V_2 ,
L_13 , V_16 ) ;
goto V_45;
}
V_16 = V_69 ;
V_45:
F_25 ( & V_2 -> V_41 ) ;
exit:
return V_16 ;
}
static int F_42 ( struct V_36 * V_4 , const struct V_78 * V_79 )
{
struct V_80 * V_81 = F_23 ( V_4 ) ;
struct V_1 * V_2 = NULL ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
char * V_60 ;
int V_86 ;
int V_16 = - V_87 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 )
goto exit;
F_44 ( & V_2 -> V_41 ) ;
F_45 ( & V_2 -> V_21 ) ;
V_2 -> V_4 = V_4 ;
F_46 ( & V_2 -> V_31 ) ;
F_46 ( & V_2 -> V_32 ) ;
if ( ( F_47 ( V_81 -> V_88 . V_89 ) == V_90 ) &&
( ( F_47 ( V_81 -> V_88 . V_91 ) == V_92 ) ||
( F_47 ( V_81 -> V_88 . V_91 ) == V_93 ) ) &&
( F_47 ( V_81 -> V_88 . V_94 ) <= 0x103 ) ) {
V_60 = F_48 ( 256 , V_49 ) ;
if ( ! V_60 )
goto error;
F_49 ( V_81 , 255 , V_60 , 256 ) ;
F_5 ( V_60 ) ;
}
V_83 = V_4 -> V_95 ;
for ( V_86 = 0 ; V_86 < V_83 -> V_96 . V_97 ; ++ V_86 ) {
V_85 = & V_83 -> V_85 [ V_86 ] . V_96 ;
if ( F_50 ( V_85 ) )
V_2 -> V_46 = V_85 ;
if ( F_51 ( V_85 ) )
V_2 -> V_72 = V_85 ;
}
if ( V_2 -> V_46 == NULL ) {
F_11 ( & V_4 -> V_2 , L_14 ) ;
goto error;
}
if ( V_2 -> V_72 == NULL )
F_9 ( & V_4 -> V_2 , L_15 ) ;
V_2 -> V_27 = F_52 ( V_2 -> V_46 ) ;
V_2 -> V_8 = F_48 ( V_25 * ( sizeof( T_1 ) + V_2 -> V_27 ) , V_49 ) ;
if ( ! V_2 -> V_8 )
goto error;
V_2 -> V_9 = F_48 ( V_2 -> V_27 , V_49 ) ;
if ( ! V_2 -> V_9 )
goto error;
V_2 -> V_5 = F_53 ( 0 , V_49 ) ;
if ( ! V_2 -> V_5 )
goto error;
V_2 -> V_71 = V_2 -> V_72 ? F_52 ( V_2 -> V_72 ) :
V_81 -> V_88 . V_98 ;
V_2 -> V_10 = F_48 ( V_70 * V_2 -> V_71 , V_49 ) ;
if ( ! V_2 -> V_10 )
goto error;
V_2 -> V_7 = F_53 ( 0 , V_49 ) ;
if ( ! V_2 -> V_7 )
goto error;
V_2 -> V_48 = V_99 > V_2 -> V_46 -> V_100 ? V_99 : V_2 -> V_46 -> V_100 ;
if ( V_2 -> V_72 )
V_2 -> V_77 = V_101 > V_2 -> V_72 -> V_100 ? V_101 : V_2 -> V_72 -> V_100 ;
F_54 ( V_4 , V_2 ) ;
V_16 = F_55 ( V_4 , & V_102 ) ;
if ( V_16 ) {
F_11 ( & V_4 -> V_2 , L_16 ) ;
F_54 ( V_4 , NULL ) ;
goto error;
}
F_56 ( & V_4 -> V_2 , L_17 ,
( V_4 -> V_103 - V_104 ) , V_105 , V_4 -> V_103 ) ;
exit:
return V_16 ;
error:
F_3 ( V_2 ) ;
return V_16 ;
}
static void F_57 ( struct V_36 * V_4 )
{
struct V_1 * V_2 ;
int V_103 ;
V_2 = F_20 ( V_4 ) ;
F_54 ( V_4 , NULL ) ;
V_103 = V_4 -> V_103 ;
F_58 ( V_4 , & V_102 ) ;
F_59 ( & V_2 -> V_41 ) ;
if ( ! V_2 -> V_43 ) {
F_25 ( & V_2 -> V_41 ) ;
F_3 ( V_2 ) ;
} else {
V_2 -> V_4 = NULL ;
F_60 ( & V_2 -> V_31 ) ;
F_60 ( & V_2 -> V_32 ) ;
F_25 ( & V_2 -> V_41 ) ;
}
F_56 ( & V_4 -> V_2 , L_18 ,
( V_103 - V_104 ) ) ;
}
