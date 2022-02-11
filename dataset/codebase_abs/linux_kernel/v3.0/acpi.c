static int T_1 F_1 ( const struct V_1 * V_2 )
{
V_3 = true ;
return 0 ;
}
void T_1 F_2 ( void )
{
int V_4 ;
if ( F_3 ( V_5 , & V_4 , NULL , NULL ) && V_4 < 2008 )
V_3 = false ;
F_4 ( V_6 ) ;
if ( V_7 & V_8 )
V_3 = false ;
else if ( V_7 & V_9 )
V_3 = true ;
F_5 ( V_10 L_1
L_2 ,
V_3 ? L_3 : L_4 ,
V_3 ? L_5 : L_6 ) ;
}
static T_2
F_6 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
T_2 V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
switch ( V_12 -> type ) {
case V_22 :
V_17 = & V_12 -> V_23 . V_17 ;
V_14 -> V_24 = V_25 ;
V_14 -> V_26 = V_17 -> V_26 ;
V_14 -> V_27 = V_17 -> V_27 ;
V_14 -> V_28 = V_14 -> V_26 + V_14 -> V_27 - 1 ;
return V_29 ;
case V_30 :
V_19 = & V_12 -> V_23 . V_19 ;
V_14 -> V_24 = V_25 ;
V_14 -> V_26 = V_19 -> V_26 ;
V_14 -> V_27 = V_19 -> V_27 ;
V_14 -> V_28 = V_14 -> V_26 + V_14 -> V_27 - 1 ;
return V_29 ;
case V_31 :
V_21 = & V_12 -> V_23 . V_21 ;
V_14 -> V_24 = V_25 ;
V_14 -> V_26 = V_21 -> V_32 ;
V_14 -> V_27 = V_21 -> V_27 ;
V_14 -> V_28 = V_14 -> V_26 + V_14 -> V_27 - 1 ;
return V_29 ;
case V_33 :
case V_34 :
case V_35 :
V_15 = F_7 ( V_12 , V_14 ) ;
if ( F_8 ( V_15 ) &&
( V_14 -> V_24 == V_25 ||
V_14 -> V_24 == V_36 ) &&
V_14 -> V_27 > 0 ) {
return V_29 ;
}
break;
}
return V_37 ;
}
static T_2
F_9 ( struct V_11 * V_38 , void * V_23 )
{
struct V_39 * V_40 = V_23 ;
struct V_13 V_14 ;
T_2 V_15 ;
V_15 = F_6 ( V_38 , & V_14 ) ;
if ( F_8 ( V_15 ) )
V_40 -> V_41 ++ ;
return V_29 ;
}
static T_2
F_10 ( struct V_11 * V_38 , void * V_23 )
{
struct V_39 * V_40 = V_23 ;
struct V_12 * V_42 ;
struct V_13 V_14 ;
T_2 V_15 ;
unsigned long V_43 ;
T_3 V_44 , V_45 ;
V_15 = F_6 ( V_38 , & V_14 ) ;
if ( ! F_8 ( V_15 ) )
return V_29 ;
if ( V_14 . V_24 == V_25 ) {
V_43 = V_46 ;
if ( V_14 . V_40 . V_47 . V_48 == V_49 )
V_43 |= V_50 ;
} else if ( V_14 . V_24 == V_36 ) {
V_43 = V_51 ;
} else
return V_29 ;
V_44 = V_14 . V_26 + V_14 . V_52 ;
V_45 = V_14 . V_28 + V_14 . V_52 ;
V_42 = & V_40 -> V_42 [ V_40 -> V_41 ] ;
V_42 -> V_53 = V_40 -> V_53 ;
V_42 -> V_43 = V_43 ;
V_42 -> V_44 = V_44 ;
V_42 -> V_45 = V_45 ;
V_42 -> V_54 = NULL ;
if ( ! V_3 ) {
F_11 ( V_55 , & V_40 -> V_56 -> V_57 ,
L_7 , V_42 ) ;
return V_29 ;
}
V_40 -> V_41 ++ ;
if ( V_14 . V_52 )
F_12 ( & V_40 -> V_56 -> V_57 , L_8
L_9 ,
V_42 , V_42 -> V_44 - V_14 . V_52 ,
V_42 -> V_45 - V_14 . V_52 ) ;
else
F_12 ( & V_40 -> V_56 -> V_57 , L_10 , V_42 ) ;
return V_29 ;
}
static bool F_13 ( struct V_12 * V_42 , T_4 V_58 )
{
if ( V_42 -> V_44 <= V_58 && V_58 <= V_42 -> V_45 )
return true ;
return false ;
}
static void F_14 ( struct V_39 * V_40 , unsigned long type )
{
int V_59 , V_60 ;
struct V_12 * V_61 , * V_62 ;
for ( V_59 = 0 ; V_59 < V_40 -> V_41 ; V_59 ++ ) {
V_61 = & V_40 -> V_42 [ V_59 ] ;
if ( ! ( V_61 -> V_43 & type ) )
continue;
for ( V_60 = V_59 + 1 ; V_60 < V_40 -> V_41 ; V_60 ++ ) {
V_62 = & V_40 -> V_42 [ V_60 ] ;
if ( ! ( V_62 -> V_43 & type ) )
continue;
if ( F_13 ( V_61 , V_62 -> V_44 ) ||
F_13 ( V_61 , V_62 -> V_45 ) ||
F_13 ( V_62 , V_61 -> V_44 ) ||
F_13 ( V_62 , V_61 -> V_45 ) ) {
V_61 -> V_44 = F_15 ( V_61 -> V_44 , V_62 -> V_44 ) ;
V_61 -> V_45 = F_16 ( V_61 -> V_45 , V_62 -> V_45 ) ;
F_12 ( & V_40 -> V_56 -> V_57 ,
L_11 ,
V_61 , V_62 ) ;
V_62 -> V_43 = 0 ;
}
}
}
}
static void F_17 ( struct V_39 * V_40 )
{
int V_59 ;
struct V_12 * V_42 , * V_63 , * V_64 ;
if ( ! V_3 )
return;
F_14 ( V_40 , V_46 ) ;
F_14 ( V_40 , V_51 ) ;
for ( V_59 = 0 ; V_59 < V_40 -> V_41 ; V_59 ++ ) {
V_42 = & V_40 -> V_42 [ V_59 ] ;
if ( V_42 -> V_43 & V_46 )
V_63 = & V_65 ;
else if ( V_42 -> V_43 & V_51 )
V_63 = & V_66 ;
else
continue;
V_64 = F_18 ( V_63 , V_42 ) ;
if ( V_64 )
F_19 ( & V_40 -> V_56 -> V_57 ,
L_12
L_13 ,
V_42 , V_64 -> V_53 , V_64 ) ;
else
F_20 ( V_40 -> V_67 , V_42 , 0 ) ;
}
}
static void
F_21 ( struct V_68 * V_69 , int V_70 ,
int V_71 , struct V_72 * V_67 )
{
struct V_39 V_40 ;
T_5 V_73 ;
if ( V_3 )
F_22 ( V_67 ) ;
V_40 . V_56 = V_69 ;
V_40 . V_67 = V_67 ;
V_40 . V_41 = 0 ;
F_23 ( V_69 -> V_74 , V_75 , F_9 ,
& V_40 ) ;
if ( ! V_40 . V_41 )
return;
V_73 = sizeof( * V_40 . V_42 ) * V_40 . V_41 ;
V_40 . V_42 = F_24 ( V_73 , V_76 ) ;
if ( ! V_40 . V_42 )
goto V_77;
V_40 . V_53 = F_25 ( V_76 , L_14 , V_71 , V_70 ) ;
if ( ! V_40 . V_53 )
goto V_78;
V_40 . V_41 = 0 ;
F_23 ( V_69 -> V_74 , V_75 , F_10 ,
& V_40 ) ;
F_17 ( & V_40 ) ;
return;
V_78:
F_26 ( V_40 . V_42 ) ;
V_77:
return;
}
struct V_72 * T_6 F_27 ( struct V_79 * V_63 )
{
struct V_68 * V_69 = V_63 -> V_69 ;
int V_71 = V_63 -> V_80 ;
int V_70 = V_63 -> V_81 . V_44 ;
struct V_72 * V_67 ;
struct V_82 * V_83 ;
int V_84 ;
#ifdef F_28
int V_85 ;
#endif
if ( V_71 && ! V_86 ) {
F_5 ( V_87 L_15
L_16 ,
V_71 , V_70 ) ;
return NULL ;
}
V_84 = - 1 ;
#ifdef F_28
V_85 = F_29 ( V_69 -> V_74 ) ;
if ( V_85 >= 0 )
V_84 = F_30 ( V_85 ) ;
if ( V_84 != - 1 )
F_31 ( V_70 , V_84 ) ;
else
#endif
V_84 = F_32 ( V_70 ) ;
if ( V_84 != - 1 && ! F_33 ( V_84 ) )
V_84 = - 1 ;
V_83 = F_34 ( sizeof( * V_83 ) , V_76 ) ;
if ( ! V_83 ) {
F_5 ( V_87 L_15
L_17 , V_71 , V_70 ) ;
return NULL ;
}
V_83 -> V_71 = V_71 ;
V_83 -> V_84 = V_84 ;
V_67 = F_35 ( V_71 , V_70 ) ;
if ( V_67 ) {
memcpy ( V_67 -> V_88 , V_83 , sizeof( * V_83 ) ) ;
F_26 ( V_83 ) ;
} else {
V_67 = F_36 ( NULL , V_70 , & V_89 , V_83 ) ;
if ( V_67 ) {
F_21 ( V_69 , V_70 , V_71 , V_67 ) ;
V_67 -> V_90 = F_37 ( V_67 ) ;
}
}
if ( ! V_67 )
F_26 ( V_83 ) ;
if ( V_67 && V_84 != - 1 ) {
#ifdef F_28
if ( V_85 >= 0 )
F_11 ( V_55 , & V_67 -> V_57 ,
L_18 , V_84 , V_85 ) ;
#else
F_11 ( V_55 , & V_67 -> V_57 , L_19 , V_84 ) ;
#endif
}
return V_67 ;
}
int T_1 F_38 ( void )
{
struct V_91 * V_57 = NULL ;
if ( V_92 )
return - V_93 ;
F_5 ( V_10 L_20 ) ;
F_39 () ;
V_94 = V_95 ;
V_96 = V_97 ;
V_98 . V_99 . V_100 = V_101 ;
if ( V_102 ) {
F_5 ( V_10 L_21 ) ;
F_40 (dev)
V_95 ( V_57 ) ;
}
return 0 ;
}
