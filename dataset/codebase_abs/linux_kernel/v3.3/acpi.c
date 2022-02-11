static int T_1 F_1 ( const struct V_1 * V_2 )
{
V_3 = true ;
return 0 ;
}
static int T_1 F_2 ( const struct V_1 * V_2 )
{
V_3 = false ;
return 0 ;
}
void T_1 F_3 ( void )
{
int V_4 ;
if ( F_4 ( V_5 , & V_4 , NULL , NULL ) && V_4 < 2008 )
V_3 = false ;
F_5 ( V_6 ) ;
if ( V_7 & V_8 )
V_3 = false ;
else if ( V_7 & V_9 )
V_3 = true ;
F_6 ( V_10 L_1
L_2 ,
V_3 ? L_3 : L_4 ,
V_3 ? L_5 : L_6 ) ;
}
static T_2
F_7 ( struct V_11 * V_12 ,
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
V_15 = F_8 ( V_12 , V_14 ) ;
if ( F_9 ( V_15 ) &&
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
F_10 ( struct V_11 * V_38 , void * V_23 )
{
struct V_39 * V_40 = V_23 ;
struct V_13 V_14 ;
T_2 V_15 ;
V_15 = F_7 ( V_38 , & V_14 ) ;
if ( F_9 ( V_15 ) )
V_40 -> V_41 ++ ;
return V_29 ;
}
static T_2
F_11 ( struct V_11 * V_38 , void * V_23 )
{
struct V_39 * V_40 = V_23 ;
struct V_12 * V_42 ;
struct V_13 V_14 ;
T_2 V_15 ;
unsigned long V_43 ;
T_3 V_44 , V_45 , V_46 ;
V_15 = F_7 ( V_38 , & V_14 ) ;
if ( ! F_9 ( V_15 ) )
return V_29 ;
if ( V_14 . V_24 == V_25 ) {
V_43 = V_47 ;
if ( V_14 . V_40 . V_48 . V_49 == V_50 )
V_43 |= V_51 ;
} else if ( V_14 . V_24 == V_36 ) {
V_43 = V_52 ;
} else
return V_29 ;
V_44 = V_14 . V_26 + V_14 . V_53 ;
V_45 = V_46 = V_14 . V_28 + V_14 . V_53 ;
V_46 = F_12 ( V_46 , ( T_3 ) V_54 . V_46 ) ;
if ( V_46 <= V_44 ) {
F_13 ( & V_40 -> V_55 -> V_56 ,
L_7
L_8 , V_44 , V_45 ) ;
return V_29 ;
} else if ( V_45 != V_46 ) {
F_13 ( & V_40 -> V_55 -> V_56 ,
L_7
L_9 ,
V_44 , V_45 , V_46 + 1 , V_45 ) ;
}
V_42 = & V_40 -> V_42 [ V_40 -> V_41 ] ;
V_42 -> V_57 = V_40 -> V_57 ;
V_42 -> V_43 = V_43 ;
V_42 -> V_44 = V_44 ;
V_42 -> V_46 = V_46 ;
V_42 -> V_58 = NULL ;
if ( ! V_3 ) {
F_14 ( V_59 , & V_40 -> V_55 -> V_56 ,
L_10 , V_42 ) ;
return V_29 ;
}
V_40 -> V_41 ++ ;
if ( V_14 . V_53 )
F_13 ( & V_40 -> V_55 -> V_56 , L_11
L_12 ,
V_42 , V_42 -> V_44 - V_14 . V_53 ,
V_42 -> V_46 - V_14 . V_53 ) ;
else
F_13 ( & V_40 -> V_55 -> V_56 , L_13 , V_42 ) ;
return V_29 ;
}
static bool F_15 ( struct V_12 * V_42 , T_4 V_60 )
{
if ( V_42 -> V_44 <= V_60 && V_60 <= V_42 -> V_46 )
return true ;
return false ;
}
static void F_16 ( struct V_39 * V_40 , unsigned long type )
{
int V_61 , V_62 ;
struct V_12 * V_63 , * V_64 ;
for ( V_61 = 0 ; V_61 < V_40 -> V_41 ; V_61 ++ ) {
V_63 = & V_40 -> V_42 [ V_61 ] ;
if ( ! ( V_63 -> V_43 & type ) )
continue;
for ( V_62 = V_61 + 1 ; V_62 < V_40 -> V_41 ; V_62 ++ ) {
V_64 = & V_40 -> V_42 [ V_62 ] ;
if ( ! ( V_64 -> V_43 & type ) )
continue;
if ( F_15 ( V_63 , V_64 -> V_44 ) ||
F_15 ( V_63 , V_64 -> V_46 ) ||
F_15 ( V_64 , V_63 -> V_44 ) ||
F_15 ( V_64 , V_63 -> V_46 ) ) {
V_63 -> V_44 = F_12 ( V_63 -> V_44 , V_64 -> V_44 ) ;
V_63 -> V_46 = F_17 ( V_63 -> V_46 , V_64 -> V_46 ) ;
F_13 ( & V_40 -> V_55 -> V_56 ,
L_14 ,
V_63 , V_64 ) ;
V_64 -> V_43 = 0 ;
}
}
}
}
static void F_18 ( struct V_39 * V_40 )
{
int V_61 ;
struct V_12 * V_42 , * V_65 , * V_66 ;
F_16 ( V_40 , V_47 ) ;
F_16 ( V_40 , V_52 ) ;
for ( V_61 = 0 ; V_61 < V_40 -> V_41 ; V_61 ++ ) {
V_42 = & V_40 -> V_42 [ V_61 ] ;
if ( V_42 -> V_43 & V_47 )
V_65 = & V_54 ;
else if ( V_42 -> V_43 & V_52 )
V_65 = & V_67 ;
else
continue;
V_66 = F_19 ( V_65 , V_42 ) ;
if ( V_66 )
F_13 ( & V_40 -> V_55 -> V_56 ,
L_15 ,
V_42 , V_66 -> V_57 , V_66 ) ;
else
F_20 ( V_40 -> V_68 , V_42 ) ;
}
}
static void
F_21 ( struct V_69 * V_70 , int V_71 ,
int V_72 , struct V_73 * V_68 )
{
struct V_39 V_40 ;
T_5 V_74 ;
V_40 . V_55 = V_70 ;
V_40 . V_41 = 0 ;
V_40 . V_68 = V_68 ;
F_22 ( V_70 -> V_75 , V_76 , F_10 ,
& V_40 ) ;
if ( ! V_40 . V_41 )
return;
V_74 = sizeof( * V_40 . V_42 ) * V_40 . V_41 ;
V_40 . V_42 = F_23 ( V_74 , V_77 ) ;
if ( ! V_40 . V_42 )
return;
V_40 . V_57 = F_24 ( V_77 , L_16 , V_72 , V_71 ) ;
if ( ! V_40 . V_57 )
goto V_78;
V_40 . V_41 = 0 ;
F_22 ( V_70 -> V_75 , V_76 , F_11 ,
& V_40 ) ;
if ( V_3 ) {
F_18 ( & V_40 ) ;
return;
}
F_25 ( V_40 . V_57 ) ;
V_78:
F_25 ( V_40 . V_42 ) ;
}
struct V_79 * T_6 F_26 ( struct V_80 * V_65 )
{
struct V_69 * V_70 = V_65 -> V_70 ;
int V_72 = V_65 -> V_81 ;
int V_71 = V_65 -> V_82 . V_44 ;
F_27 ( V_68 ) ;
struct V_79 * V_83 ;
struct V_84 * V_85 ;
int V_86 ;
#ifdef F_28
int V_87 ;
#endif
if ( V_72 && ! V_88 ) {
F_6 ( V_89 L_17
L_18 ,
V_72 , V_71 ) ;
return NULL ;
}
V_86 = - 1 ;
#ifdef F_28
V_87 = F_29 ( V_70 -> V_75 ) ;
if ( V_87 >= 0 )
V_86 = F_30 ( V_87 ) ;
if ( V_86 != - 1 )
F_31 ( V_71 , V_86 ) ;
else
#endif
V_86 = F_32 ( V_71 ) ;
if ( V_86 != - 1 && ! F_33 ( V_86 ) )
V_86 = - 1 ;
V_85 = F_34 ( sizeof( * V_85 ) , V_77 ) ;
if ( ! V_85 ) {
F_6 ( V_89 L_17
L_19 , V_72 , V_71 ) ;
return NULL ;
}
V_85 -> V_72 = V_72 ;
V_85 -> V_86 = V_86 ;
V_83 = F_35 ( V_72 , V_71 ) ;
if ( V_83 ) {
memcpy ( V_83 -> V_90 , V_85 , sizeof( * V_85 ) ) ;
F_25 ( V_85 ) ;
} else {
F_21 ( V_70 , V_71 , V_72 , & V_68 ) ;
if ( F_36 ( & V_68 ) )
F_37 ( V_71 , & V_68 ) ;
V_83 = F_38 ( NULL , V_71 , & V_91 , V_85 ,
& V_68 ) ;
if ( V_83 )
V_83 -> V_92 = F_39 ( V_83 ) ;
else
F_40 ( & V_68 ) ;
}
if ( V_83 ) {
struct V_79 * V_58 ;
F_41 (child, &bus->children, node) {
struct V_93 * V_94 = V_58 -> V_94 ;
if ( ! V_94 )
continue;
F_42 ( V_58 , V_94 -> V_95 ) ;
}
}
if ( ! V_83 )
F_25 ( V_85 ) ;
if ( V_83 && V_86 != - 1 ) {
#ifdef F_28
if ( V_87 >= 0 )
F_14 ( V_59 , & V_83 -> V_56 ,
L_20 , V_86 , V_87 ) ;
#else
F_14 ( V_59 , & V_83 -> V_56 , L_21 , V_86 ) ;
#endif
}
return V_83 ;
}
int T_1 F_43 ( void )
{
struct V_93 * V_56 = NULL ;
if ( V_96 )
return - V_97 ;
F_6 ( V_10 L_22 ) ;
F_44 () ;
V_98 = V_99 ;
V_100 = V_101 ;
V_102 . V_103 . V_104 = V_105 ;
if ( V_106 ) {
F_6 ( V_10 L_23 ) ;
F_45 (dev)
V_99 ( V_56 ) ;
}
return 0 ;
}
