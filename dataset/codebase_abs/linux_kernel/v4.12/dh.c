static T_1 F_1 ( T_2 V_1 , void * * V_2 )
{
struct V_3 * V_3 ;
T_3 V_4 ;
long V_5 ;
T_1 V_6 ;
V_4 = F_2 ( V_1 , 0 , V_7 ) ;
if ( F_3 ( V_4 ) ) {
V_6 = - V_8 ;
goto error;
}
V_3 = F_4 ( V_4 ) ;
V_6 = - V_9 ;
if ( V_3 -> type == & V_10 ) {
F_5 ( & V_3 -> V_11 ) ;
V_5 = F_6 ( V_3 ) ;
if ( V_5 == 0 ) {
const struct V_12 * V_13 ;
T_4 * V_14 ;
V_13 = F_7 ( V_3 ) ;
V_14 = F_8 ( V_13 -> V_2 , V_13 -> V_15 ,
V_16 ) ;
if ( V_14 ) {
* V_2 = V_14 ;
V_6 = V_13 -> V_15 ;
} else {
V_6 = - V_17 ;
}
}
F_9 ( & V_3 -> V_11 ) ;
}
F_10 ( V_3 ) ;
error:
return V_6 ;
}
static void F_11 ( struct V_18 * V_18 )
{
F_12 ( V_18 -> V_3 ) ;
F_12 ( V_18 -> V_19 ) ;
F_12 ( V_18 -> V_20 ) ;
}
static void F_13 ( struct V_21 * V_22 , int V_23 )
{
struct V_24 * V_25 = V_22 -> V_2 ;
if ( V_23 == - V_26 )
return;
V_25 -> V_23 = V_23 ;
F_14 ( & V_25 -> V_27 ) ;
}
static int F_15 ( struct V_28 * * V_29 , char * V_30 )
{
struct V_31 * V_32 ;
struct V_28 * V_33 ;
int V_34 ;
int V_23 ;
V_32 = F_16 ( V_30 , 0 , 0 ) ;
if ( F_3 ( V_32 ) ) {
F_17 ( L_1 , V_30 ) ;
return F_18 ( V_32 ) ;
}
V_23 = - V_35 ;
if ( F_19 ( V_32 ) == 0 )
goto V_36;
V_23 = - V_17 ;
V_34 = sizeof( struct V_37 ) + F_20 ( V_32 ) ;
V_33 = F_21 ( V_34 , V_16 ) ;
if ( ! V_33 )
goto V_36;
V_33 -> V_38 . V_32 = V_32 ;
V_33 -> V_38 . V_39 = 0x0 ;
* V_29 = V_33 ;
return 0 ;
V_36:
F_22 ( V_32 ) ;
return V_23 ;
}
static void F_23 ( struct V_28 * V_33 )
{
if ( ! V_33 )
return;
if ( V_33 -> V_38 . V_32 )
F_22 ( V_33 -> V_38 . V_32 ) ;
F_12 ( V_33 ) ;
}
static int F_24 ( struct V_28 * V_33 , const T_5 * V_40 , unsigned int V_41 ,
T_5 * V_42 , unsigned int V_43 , unsigned int V_44 )
{
struct V_37 * V_45 = & V_33 -> V_38 ;
unsigned int V_46 = F_19 ( V_45 -> V_32 ) ;
int V_23 = 0 ;
T_5 * V_47 = V_42 ;
T_6 V_48 = F_25 ( 1 ) ;
while ( V_43 ) {
V_23 = F_26 ( V_45 ) ;
if ( V_23 )
goto V_23;
V_23 = F_27 ( V_45 , ( T_5 * ) & V_48 , sizeof( T_6 ) ) ;
if ( V_23 )
goto V_23;
if ( V_44 && V_46 ) {
T_5 V_49 [ V_46 ] ;
T_7 V_50 = F_28 ( T_7 , V_44 , V_46 ) ;
memset ( V_49 , 0 , V_50 ) ;
do {
V_23 = F_27 ( V_45 , V_49 ,
V_50 ) ;
if ( V_23 )
goto V_23;
V_44 -= V_50 ;
V_50 = F_28 ( T_7 , V_44 , V_46 ) ;
} while ( V_44 );
}
if ( V_40 && V_41 ) {
V_23 = F_27 ( V_45 , V_40 , V_41 ) ;
if ( V_23 )
goto V_23;
}
if ( V_43 < V_46 ) {
T_5 V_49 [ V_46 ] ;
V_23 = F_29 ( V_45 , V_49 ) ;
if ( V_23 )
goto V_23;
memcpy ( V_42 , V_49 , V_43 ) ;
F_30 ( V_49 , V_46 ) ;
return 0 ;
} else {
V_23 = F_29 ( V_45 , V_42 ) ;
if ( V_23 )
goto V_23;
V_43 -= V_46 ;
V_42 += V_46 ;
V_48 = F_25 ( F_31 ( V_48 ) + 1 ) ;
}
}
return 0 ;
V_23:
F_30 ( V_47 , V_43 ) ;
return V_23 ;
}
static int F_32 ( struct V_28 * V_33 ,
char T_8 * V_51 , T_7 V_52 ,
T_4 * V_53 , T_7 V_54 , T_7 V_55 )
{
T_4 * V_56 = NULL ;
int V_6 ;
V_56 = F_21 ( V_52 , V_16 ) ;
if ( ! V_56 ) {
V_6 = - V_17 ;
goto V_23;
}
V_6 = F_24 ( V_33 , V_53 , V_54 , V_56 , V_52 , V_55 ) ;
if ( V_6 )
goto V_23;
V_6 = V_52 ;
if ( F_33 ( V_51 , V_56 , V_52 ) != 0 )
V_6 = - V_57 ;
V_23:
F_12 ( V_56 ) ;
return V_6 ;
}
long F_34 ( struct V_58 T_8 * V_59 ,
char T_8 * V_51 , T_7 V_52 ,
struct V_60 * V_61 )
{
long V_6 ;
T_1 V_43 ;
int V_62 ;
int V_63 ;
struct V_58 V_64 ;
struct V_18 V_65 ;
struct V_66 V_67 ;
struct V_24 V_25 ;
struct V_68 * V_32 ;
struct V_69 * V_22 ;
T_4 * V_70 ;
T_4 * V_56 ;
struct V_28 * V_33 = NULL ;
if ( ! V_59 || ( ! V_51 && V_52 ) ) {
V_6 = - V_35 ;
goto V_71;
}
if ( F_35 ( & V_64 , V_59 , sizeof( V_64 ) ) != 0 ) {
V_6 = - V_57 ;
goto V_71;
}
if ( V_61 ) {
char * V_30 ;
if ( V_52 > V_72 ||
V_61 -> V_73 > V_74 ) {
V_6 = - V_75 ;
goto V_71;
}
V_30 = F_36 ( V_61 -> V_30 , V_76 ) ;
if ( F_3 ( V_30 ) ) {
V_6 = F_18 ( V_30 ) ;
goto V_71;
}
V_6 = F_15 ( & V_33 , V_30 ) ;
F_37 ( V_30 ) ;
if ( V_6 )
goto V_71;
}
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_43 = F_1 ( V_64 . V_77 , & V_65 . V_19 ) ;
if ( V_43 < 0 ) {
V_6 = V_43 ;
goto V_71;
}
V_65 . V_78 = V_43 ;
V_43 = F_1 ( V_64 . V_79 , & V_65 . V_20 ) ;
if ( V_43 < 0 ) {
V_6 = V_43 ;
goto V_80;
}
V_65 . V_81 = V_43 ;
V_43 = F_1 ( V_64 . V_82 , & V_65 . V_3 ) ;
if ( V_43 < 0 ) {
V_6 = V_43 ;
goto V_80;
}
V_65 . V_83 = V_43 ;
V_62 = F_38 ( & V_65 ) ;
V_70 = F_21 ( V_62 , V_16 ) ;
if ( ! V_70 ) {
V_6 = - V_17 ;
goto V_80;
}
V_6 = F_39 ( V_70 , V_62 , & V_65 ) ;
if ( V_6 )
goto V_84;
V_32 = F_40 ( L_2 , V_85 , 0 ) ;
if ( F_3 ( V_32 ) ) {
V_6 = F_18 ( V_32 ) ;
goto V_84;
}
V_6 = F_41 ( V_32 , V_70 , V_62 ) ;
if ( V_6 )
goto V_86;
V_63 = F_42 ( V_32 ) ;
if ( ! V_61 ) {
if ( V_52 == 0 ) {
V_6 = V_63 ;
goto V_86;
} else if ( V_63 > V_52 ) {
V_6 = - V_87 ;
goto V_86;
}
}
V_56 = F_43 ( V_61 ? ( V_63 + V_61 -> V_73 ) : V_63 ,
V_16 ) ;
if ( ! V_56 ) {
V_6 = - V_17 ;
goto V_86;
}
F_44 ( & V_67 , V_56 , V_63 ) ;
V_22 = F_45 ( V_32 , V_16 ) ;
if ( ! V_22 ) {
V_6 = - V_17 ;
goto V_88;
}
F_46 ( V_22 , NULL , 0 ) ;
F_47 ( V_22 , & V_67 , V_63 ) ;
F_48 ( & V_25 . V_27 ) ;
F_49 ( V_22 , V_89 |
V_90 ,
F_13 , & V_25 ) ;
V_6 = F_50 ( V_22 ) ;
if ( V_6 == - V_26 ) {
F_51 ( & V_25 . V_27 ) ;
V_6 = V_25 . V_23 ;
if ( V_6 )
goto V_91;
}
if ( V_61 ) {
if ( F_35 ( V_56 + V_22 -> V_92 , V_61 -> V_93 ,
V_61 -> V_73 ) != 0 ) {
V_6 = - V_57 ;
goto V_91;
}
V_6 = F_32 ( V_33 , V_51 , V_52 , V_56 ,
V_22 -> V_92 + V_61 -> V_73 ,
V_63 - V_22 -> V_92 ) ;
} else if ( F_33 ( V_51 , V_56 , V_22 -> V_92 ) == 0 ) {
V_6 = V_22 -> V_92 ;
} else {
V_6 = - V_57 ;
}
V_91:
F_52 ( V_22 ) ;
V_88:
F_12 ( V_56 ) ;
V_86:
F_53 ( V_32 ) ;
V_84:
F_12 ( V_70 ) ;
V_80:
F_11 ( & V_65 ) ;
V_71:
F_23 ( V_33 ) ;
return V_6 ;
}
long F_54 ( struct V_58 T_8 * V_59 ,
char T_8 * V_51 , T_7 V_52 ,
struct V_60 T_8 * V_94 )
{
struct V_60 V_61 ;
if ( ! V_94 )
return F_34 ( V_59 , V_51 , V_52 , NULL ) ;
if ( F_35 ( & V_61 , V_94 , sizeof( V_61 ) ) != 0 )
return - V_57 ;
return F_34 ( V_59 , V_51 , V_52 , & V_61 ) ;
}
