int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = NULL ;
struct V_6 * V_8 = NULL ;
struct V_6 * V_9 = NULL ;
struct V_6 * V_10 = NULL ;
if ( ( V_3 = F_3 ( V_2 ) ) ) {
goto V_11;
}
V_7 = F_4 ( V_2 , V_12 , 0 ) ;
if ( V_7 == NULL ) {
F_5 ( L_1 ) ;
V_3 = - V_13 ;
goto V_11;
}
V_5 -> V_7 = V_7 ;
F_6 ( L_2 , V_7 ) ;
if ( ( V_3 = F_7 ( V_7 ) ) ) {
F_5 ( L_3 , V_3 ) ;
goto V_14;
}
V_10 = F_4 ( V_2 , V_15 , 0 ) ;
if ( V_10 == NULL ) {
V_3 = - V_13 ;
goto V_16;
}
F_6 ( L_4 , V_10 ) ;
V_5 -> V_10 = V_10 ;
if ( ( V_3 = F_8 ( V_10 ) ) ) {
F_5 ( L_5 , V_3 ) ;
goto V_16;
}
if ( ( V_5 -> V_17 & V_18 ) == 0 ) {
V_8 = F_4 ( V_2 , V_12 , 1 ) ;
if ( ! V_8 ) {
F_5 ( L_1 ) ;
V_3 = - V_13 ;
goto V_19;
}
V_5 -> V_8 = V_8 ;
F_6 ( L_6 , V_8 ) ;
if ( ( V_3 = F_7 ( V_8 ) ) ) {
F_5 ( L_7 ,
V_3 ) ;
goto V_19;
}
} else
V_5 -> V_8 = NULL ;
V_9 = F_4 ( V_2 , V_20 , 0 ) ;
if ( V_9 == NULL ) {
F_5 ( L_8 ) ;
V_3 = - V_13 ;
goto V_21;
}
F_6 ( L_9 , V_9 ) ;
V_5 -> V_9 = V_9 ;
if ( ( V_3 = F_7 ( V_9 ) ) ) {
F_5 ( L_10 , V_3 ) ;
goto V_22;
}
goto V_23;
V_22:
F_9 ( V_9 ) ;
V_21:
if ( V_8 ) {
F_10 ( V_8 , 1 ) ;
F_9 ( V_8 ) ;
}
V_19:
F_11 ( V_10 , 1 ) ;
F_9 ( V_10 ) ;
V_16:
F_10 ( V_7 , 1 ) ;
V_14:
F_9 ( V_7 ) ;
V_11:
V_23:
if ( V_3 )
F_5 ( L_11 , V_3 ) ;
return V_3 ;
}
int F_12 ( struct V_1 * V_2 , int V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_3 ;
if ( V_24 ) {
if ( F_3 ( V_2 ) || ( V_5 -> V_25 != V_26 ) )
return - V_27 ;
F_13 ( V_5 -> V_9 -> V_28 , 0 ) ;
F_13 ( V_5 -> V_10 -> V_28 , 0 ) ;
F_10 ( V_5 -> V_9 , 1 ) ;
if ( ( V_3 = F_7 ( V_5 -> V_9 ) ) ) {
F_5 ( L_12 ) ;
return V_3 ;
}
F_11 ( V_5 -> V_10 , 1 ) ;
if ( ( V_3 = F_8 ( V_5 -> V_10 ) ) ) {
F_5 ( L_13 ) ;
return V_3 ;
}
}
if ( ( V_3 = F_14 ( V_2 ) ) )
return V_3 ;
if ( ( V_3 = F_15 ( V_2 , V_29 ) ) ) {
F_5 ( L_14 , V_3 ) ;
F_16 ( V_2 ) ;
return V_3 ;
}
F_17 ( V_2 ) ;
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
int V_34 , V_35 ;
int V_36 , V_37 ;
T_1 V_38 , V_39 , V_40 ;
T_1 V_41 , V_42 ;
T_2 V_43 ;
if ( ( V_3 = F_18 ( V_2 , & V_33 ) ) )
return V_3 ;
V_31 = (struct V_30 * ) V_33 -> V_44 ;
if ( strncmp ( V_31 -> V_45 , V_46 , 4 ) ||
F_19 ( V_31 -> V_47 ) > V_48 ) {
V_3 = - V_27 ;
goto V_23;
}
V_43 = F_19 ( V_31 -> V_49 ) ;
#ifdef F_20
if ( V_43 != V_50 ) {
F_5 ( L_15 ) ;
V_3 = - V_27 ;
goto V_23;
}
#endif
F_6 ( L_16 ,
F_19 ( V_31 -> V_51 ) , F_19 ( V_31 -> V_52 ) ,
( unsigned long long ) F_21 ( V_31 -> V_53 ) ) ;
if ( ( V_31 -> V_51 & F_22 ( V_18 ) ) !=
F_22 ( V_18 ) ) {
V_36 = 2 * V_50 ;
V_34 = F_23 ( & ( V_31 -> V_54 ) ) * V_43 ;
V_37 = 4 * V_50 ;
V_35 = F_23 ( & ( V_31 -> V_55 ) ) * V_43 ;
V_38 = F_24 ( & ( V_31 -> V_54 ) ) * V_43 ;
V_39 = F_24 ( & ( V_31 -> V_55 ) ) * V_43 ;
V_41 = V_39 - V_38 ;
V_40 = F_24 ( & ( V_31 -> V_56 ) ) * V_43 ;
V_42 = V_40 - V_39 ;
if ( ( V_34 != V_36 ) ||
( V_35 != V_37 ) ||
( V_41 != V_34 ) ||
( V_42 <= V_35 ) )
V_31 -> V_51 |= F_22 ( V_18 ) ;
}
if ( ( V_31 -> V_51 & F_22 ( V_57 ) ) !=
F_22 ( V_57 ) )
V_31 -> V_51 |= F_22 ( V_57 ) ;
if ( V_31 -> V_52 != F_22 ( V_26 ) &&
! F_25 ( V_2 ) ) {
F_5 ( L_17 ) ;
V_3 = - V_27 ;
goto V_23;
}
V_5 -> V_25 = F_19 ( V_31 -> V_52 ) ;
V_5 -> V_17 = F_19 ( V_31 -> V_51 ) ;
V_5 -> V_43 = V_43 ;
V_5 -> V_58 = F_26 ( V_31 -> V_59 ) ;
V_5 -> V_60 = V_50 >> V_5 -> V_58 ;
V_5 -> V_61 = V_62 - V_5 -> V_58 ;
V_5 -> V_63 = V_5 -> V_58 - V_64 ;
if ( V_5 -> V_17 & V_65 )
V_5 -> V_66 = V_31 -> V_67 ;
else {
V_5 -> V_68 = F_27 ( F_19 ( V_31 -> V_69 ) ) ;
memcpy ( V_5 -> V_70 , V_31 -> V_71 , sizeof( V_5 -> V_70 ) ) ;
memcpy ( V_5 -> V_72 , V_31 -> V_73 , sizeof( V_5 -> V_70 ) ) ;
}
V_5 -> V_74 = V_31 -> V_56 ;
V_5 -> V_75 = V_31 -> V_55 ;
V_23:
F_28 ( V_33 ) ;
return V_3 ;
}
int F_15 ( struct V_1 * V_2 , T_3 V_25 )
{
struct V_30 * V_31 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_32 * V_33 ;
int V_3 ;
if ( V_5 -> V_76 & V_77 ) {
if ( V_25 == V_78 ) {
V_5 -> V_79 = V_25 ;
return 0 ;
} else if ( V_25 == V_29 ) {
V_5 -> V_79 = V_5 -> V_25 ;
V_25 = V_78 ;
} else if ( V_25 == V_26 ) {
V_25 = V_5 -> V_79 ;
} else
F_5 ( L_18 ) ;
} else if ( V_5 -> V_25 == V_78 )
return 0 ;
if ( ( V_3 = F_18 ( V_2 , & V_33 ) ) )
return V_3 ;
V_31 = (struct V_30 * ) V_33 -> V_44 ;
V_31 -> V_52 = F_22 ( V_25 ) ;
V_5 -> V_25 = V_25 ;
if ( V_25 == V_29 ) {
V_31 -> V_69 = F_22 ( F_29 ( V_5 -> log -> V_80 -> V_81 ) ) ;
V_31 -> V_82 = F_22 ( V_5 -> log -> V_83 ) ;
} else if ( V_25 == V_26 ) {
if ( V_31 -> V_51 & F_22 ( V_84 ) )
V_31 -> V_51 |= F_22 ( V_85 ) ;
}
F_30 ( V_33 ) ;
F_31 ( V_33 ) ;
F_28 ( V_33 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , struct V_32 * * V_86 )
{
* V_86 = F_32 ( V_2 , V_87 >> V_2 -> V_88 ) ;
if ( * V_86 )
return 0 ;
* V_86 = F_32 ( V_2 , V_89 >> V_2 -> V_88 ) ;
if ( * V_86 )
return 0 ;
return - V_13 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_90 * log = F_2 ( V_2 ) -> log ;
struct V_91 V_91 ;
V_91 . V_92 = 0 ;
V_91 . V_93 = 0 ;
V_91 . type = F_33 ( V_94 ) ;
V_91 . V_95 = 0 ;
V_91 . V_96 = F_22 ( F_29 ( V_2 -> V_97 -> V_81 ) ) ;
F_34 ( log , NULL , & V_91 , NULL ) ;
return 0 ;
}
