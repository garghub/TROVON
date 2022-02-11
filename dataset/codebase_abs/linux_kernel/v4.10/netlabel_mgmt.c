static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = - V_6 ;
struct V_7 * V_8 = NULL ;
struct V_9 * V_10 = NULL ;
#if F_2 ( V_11 )
struct V_12 * V_13 = NULL ;
#endif
T_1 V_14 ;
struct V_15 * V_16 = F_3 ( sizeof( * V_16 ) , V_17 ) ;
if ( ! V_16 )
return - V_18 ;
V_16 -> V_19 . type = F_4 ( V_2 -> V_20 [ V_21 ] ) ;
if ( V_2 -> V_20 [ V_22 ] ) {
T_2 V_23 = F_5 ( V_2 -> V_20 [ V_22 ] ) ;
V_16 -> V_24 = F_6 ( V_23 , V_17 ) ;
if ( V_16 -> V_24 == NULL ) {
V_5 = - V_18 ;
goto V_25;
}
F_7 ( V_16 -> V_24 ,
V_2 -> V_20 [ V_22 ] , V_23 ) ;
}
switch ( V_16 -> V_19 . type ) {
case V_26 :
if ( V_2 -> V_20 [ V_27 ] )
V_16 -> V_28 =
F_8 ( V_2 -> V_20 [ V_27 ] ) ;
else
V_16 -> V_28 = V_29 ;
break;
case V_30 :
if ( ! V_2 -> V_20 [ V_31 ] )
goto V_32;
V_14 = F_4 ( V_2 -> V_20 [ V_31 ] ) ;
V_10 = F_9 ( V_14 ) ;
if ( V_10 == NULL )
goto V_32;
V_16 -> V_28 = V_33 ;
V_16 -> V_19 . V_34 = V_10 ;
break;
#if F_2 ( V_11 )
case V_35 :
if ( ! V_2 -> V_20 [ V_36 ] )
goto V_32;
V_14 = F_4 ( V_2 -> V_20 [ V_36 ] ) ;
V_13 = F_10 ( V_14 ) ;
if ( V_13 == NULL )
goto V_32;
V_16 -> V_28 = V_37 ;
V_16 -> V_19 . V_13 = V_13 ;
break;
#endif
default:
goto V_32;
}
if ( ( V_16 -> V_28 == V_33 && V_2 -> V_20 [ V_38 ] ) ||
( V_16 -> V_28 == V_37 && V_2 -> V_20 [ V_39 ] ) )
goto V_40;
if ( V_2 -> V_20 [ V_39 ] ) {
struct V_41 * V_42 ;
struct V_41 * V_43 ;
struct V_44 * V_45 ;
V_8 = F_3 ( sizeof( * V_8 ) , V_17 ) ;
if ( V_8 == NULL ) {
V_5 = - V_18 ;
goto V_40;
}
F_11 ( & V_8 -> V_46 ) ;
F_11 ( & V_8 -> V_47 ) ;
if ( F_5 ( V_2 -> V_20 [ V_39 ] ) !=
sizeof( struct V_41 ) ) {
V_5 = - V_6 ;
goto V_48;
}
if ( F_5 ( V_2 -> V_20 [ V_49 ] ) !=
sizeof( struct V_41 ) ) {
V_5 = - V_6 ;
goto V_48;
}
V_42 = F_12 ( V_2 -> V_20 [ V_39 ] ) ;
V_43 = F_12 ( V_2 -> V_20 [ V_49 ] ) ;
V_45 = F_3 ( sizeof( * V_45 ) , V_17 ) ;
if ( V_45 == NULL ) {
V_5 = - V_18 ;
goto V_48;
}
V_45 -> V_50 . V_42 = V_42 -> V_51 & V_43 -> V_51 ;
V_45 -> V_50 . V_43 = V_43 -> V_51 ;
V_45 -> V_50 . V_52 = 1 ;
V_45 -> V_19 . type = V_16 -> V_19 . type ;
if ( V_10 )
V_45 -> V_19 . V_34 = V_10 ;
V_5 = F_13 ( & V_45 -> V_50 , & V_8 -> V_46 ) ;
if ( V_5 != 0 ) {
F_14 ( V_45 ) ;
goto V_48;
}
V_16 -> V_28 = V_33 ;
V_16 -> V_19 . type = V_53 ;
V_16 -> V_19 . V_54 = V_8 ;
#if F_2 ( V_11 )
} else if ( V_2 -> V_20 [ V_38 ] ) {
struct V_55 * V_42 ;
struct V_55 * V_43 ;
struct V_56 * V_45 ;
V_8 = F_3 ( sizeof( * V_8 ) , V_17 ) ;
if ( V_8 == NULL ) {
V_5 = - V_18 ;
goto V_40;
}
F_11 ( & V_8 -> V_46 ) ;
F_11 ( & V_8 -> V_47 ) ;
if ( F_5 ( V_2 -> V_20 [ V_38 ] ) !=
sizeof( struct V_55 ) ) {
V_5 = - V_6 ;
goto V_48;
}
if ( F_5 ( V_2 -> V_20 [ V_57 ] ) !=
sizeof( struct V_55 ) ) {
V_5 = - V_6 ;
goto V_48;
}
V_42 = F_12 ( V_2 -> V_20 [ V_38 ] ) ;
V_43 = F_12 ( V_2 -> V_20 [ V_57 ] ) ;
V_45 = F_3 ( sizeof( * V_45 ) , V_17 ) ;
if ( V_45 == NULL ) {
V_5 = - V_18 ;
goto V_48;
}
V_45 -> V_50 . V_42 = * V_42 ;
V_45 -> V_50 . V_42 . V_58 [ 0 ] &= V_43 -> V_58 [ 0 ] ;
V_45 -> V_50 . V_42 . V_58 [ 1 ] &= V_43 -> V_58 [ 1 ] ;
V_45 -> V_50 . V_42 . V_58 [ 2 ] &= V_43 -> V_58 [ 2 ] ;
V_45 -> V_50 . V_42 . V_58 [ 3 ] &= V_43 -> V_58 [ 3 ] ;
V_45 -> V_50 . V_43 = * V_43 ;
V_45 -> V_50 . V_52 = 1 ;
V_45 -> V_19 . type = V_16 -> V_19 . type ;
if ( V_13 )
V_45 -> V_19 . V_13 = V_13 ;
V_5 = F_15 ( & V_45 -> V_50 , & V_8 -> V_47 ) ;
if ( V_5 != 0 ) {
F_14 ( V_45 ) ;
goto V_48;
}
V_16 -> V_28 = V_37 ;
V_16 -> V_19 . type = V_53 ;
V_16 -> V_19 . V_54 = V_8 ;
#endif
}
V_5 = F_16 ( V_16 , V_4 ) ;
if ( V_5 != 0 )
goto V_48;
return 0 ;
V_48:
F_14 ( V_8 ) ;
V_40:
F_17 ( V_10 ) ;
#if F_2 ( V_11 )
F_18 ( V_13 ) ;
#endif
V_32:
F_14 ( V_16 -> V_24 ) ;
V_25:
F_14 ( V_16 ) ;
return V_5 ;
}
static int F_19 ( struct V_59 * V_60 ,
struct V_15 * V_16 )
{
int V_5 = 0 ;
struct V_61 * V_62 ;
struct V_61 * V_63 ;
struct V_64 * V_65 ;
#if F_2 ( V_11 )
struct V_66 * V_67 ;
#endif
if ( V_16 -> V_24 != NULL ) {
V_5 = F_20 ( V_60 ,
V_22 , V_16 -> V_24 ) ;
if ( V_5 != 0 )
return V_5 ;
}
V_5 = F_21 ( V_60 , V_27 , V_16 -> V_28 ) ;
if ( V_5 != 0 )
return V_5 ;
switch ( V_16 -> V_19 . type ) {
case V_53 :
V_62 = F_22 ( V_60 , V_68 ) ;
if ( V_62 == NULL )
return - V_18 ;
F_23 (iter4, &entry->def.addrsel->list4) {
struct V_44 * V_69 ;
struct V_41 V_70 ;
V_63 = F_22 ( V_60 , V_71 ) ;
if ( V_63 == NULL )
return - V_18 ;
V_70 . V_51 = V_65 -> V_42 ;
V_5 = F_24 ( V_60 , V_39 ,
V_70 . V_51 ) ;
if ( V_5 != 0 )
return V_5 ;
V_70 . V_51 = V_65 -> V_43 ;
V_5 = F_24 ( V_60 , V_49 ,
V_70 . V_51 ) ;
if ( V_5 != 0 )
return V_5 ;
V_69 = F_25 ( V_65 ) ;
V_5 = F_26 ( V_60 , V_21 ,
V_69 -> V_19 . type ) ;
if ( V_5 != 0 )
return V_5 ;
switch ( V_69 -> V_19 . type ) {
case V_30 :
V_5 = F_26 ( V_60 , V_31 ,
V_69 -> V_19 . V_34 -> V_72 ) ;
if ( V_5 != 0 )
return V_5 ;
break;
}
F_27 ( V_60 , V_63 ) ;
}
#if F_2 ( V_11 )
F_28 (iter6, &entry->def.addrsel->list6) {
struct V_56 * V_73 ;
V_63 = F_22 ( V_60 , V_71 ) ;
if ( V_63 == NULL )
return - V_18 ;
V_5 = F_29 ( V_60 , V_38 ,
& V_67 -> V_42 ) ;
if ( V_5 != 0 )
return V_5 ;
V_5 = F_29 ( V_60 , V_57 ,
& V_67 -> V_43 ) ;
if ( V_5 != 0 )
return V_5 ;
V_73 = F_30 ( V_67 ) ;
V_5 = F_26 ( V_60 , V_21 ,
V_73 -> V_19 . type ) ;
if ( V_5 != 0 )
return V_5 ;
switch ( V_73 -> V_19 . type ) {
case V_35 :
V_5 = F_26 ( V_60 , V_36 ,
V_73 -> V_19 . V_13 -> V_72 ) ;
if ( V_5 != 0 )
return V_5 ;
break;
}
F_27 ( V_60 , V_63 ) ;
}
#endif
F_27 ( V_60 , V_62 ) ;
break;
case V_26 :
V_5 = F_26 ( V_60 , V_21 ,
V_16 -> V_19 . type ) ;
break;
case V_30 :
V_5 = F_26 ( V_60 , V_21 ,
V_16 -> V_19 . type ) ;
if ( V_5 != 0 )
return V_5 ;
V_5 = F_26 ( V_60 , V_31 ,
V_16 -> V_19 . V_34 -> V_72 ) ;
break;
case V_35 :
V_5 = F_26 ( V_60 , V_21 ,
V_16 -> V_19 . type ) ;
if ( V_5 != 0 )
return V_5 ;
V_5 = F_26 ( V_60 , V_36 ,
V_16 -> V_19 . V_13 -> V_72 ) ;
break;
}
return V_5 ;
}
static int F_31 ( struct V_59 * V_60 , struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( ( ! V_2 -> V_20 [ V_22 ] ) ||
( ! V_2 -> V_20 [ V_21 ] ) ||
( V_2 -> V_20 [ V_39 ] &&
V_2 -> V_20 [ V_38 ] ) ||
( V_2 -> V_20 [ V_49 ] &&
V_2 -> V_20 [ V_57 ] ) ||
( ( V_2 -> V_20 [ V_39 ] != NULL ) ^
( V_2 -> V_20 [ V_49 ] != NULL ) ) ||
( ( V_2 -> V_20 [ V_38 ] != NULL ) ^
( V_2 -> V_20 [ V_57 ] != NULL ) ) )
return - V_6 ;
F_32 ( V_60 , & V_4 ) ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_33 ( struct V_59 * V_60 , struct V_1 * V_2 )
{
char * V_24 ;
struct V_3 V_4 ;
if ( ! V_2 -> V_20 [ V_22 ] )
return - V_6 ;
F_32 ( V_60 , & V_4 ) ;
V_24 = F_12 ( V_2 -> V_20 [ V_22 ] ) ;
return F_34 ( V_24 , V_29 , & V_4 ) ;
}
static int F_35 ( struct V_15 * V_16 , void * V_74 )
{
int V_5 = - V_18 ;
struct V_75 * V_76 = V_74 ;
void * V_77 ;
V_77 = F_36 ( V_76 -> V_60 , F_37 ( V_76 -> V_78 -> V_60 ) . V_79 ,
V_76 -> V_80 , & V_81 ,
V_82 , V_83 ) ;
if ( V_77 == NULL )
goto V_84;
V_5 = F_19 ( V_76 -> V_60 , V_16 ) ;
if ( V_5 != 0 )
goto V_84;
V_76 -> V_80 ++ ;
F_38 ( V_76 -> V_60 , V_77 ) ;
return 0 ;
V_84:
F_39 ( V_76 -> V_60 , V_77 ) ;
return V_5 ;
}
static int F_40 ( struct V_59 * V_60 ,
struct V_85 * V_86 )
{
struct V_75 V_76 ;
T_1 V_87 = V_86 -> args [ 0 ] ;
T_1 V_88 = V_86 -> args [ 1 ] ;
V_76 . V_78 = V_86 ;
V_76 . V_60 = V_60 ;
V_76 . V_80 = V_86 -> V_89 -> V_90 ;
F_41 ( & V_87 ,
& V_88 ,
F_35 ,
& V_76 ) ;
V_86 -> args [ 0 ] = V_87 ;
V_86 -> args [ 1 ] = V_88 ;
return V_60 -> V_91 ;
}
static int F_42 ( struct V_59 * V_60 , struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( ( ! V_2 -> V_20 [ V_21 ] ) ||
( V_2 -> V_20 [ V_39 ] &&
V_2 -> V_20 [ V_38 ] ) ||
( V_2 -> V_20 [ V_49 ] &&
V_2 -> V_20 [ V_57 ] ) ||
( ( V_2 -> V_20 [ V_39 ] != NULL ) ^
( V_2 -> V_20 [ V_49 ] != NULL ) ) ||
( ( V_2 -> V_20 [ V_38 ] != NULL ) ^
( V_2 -> V_20 [ V_57 ] != NULL ) ) )
return - V_6 ;
F_32 ( V_60 , & V_4 ) ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_43 ( struct V_59 * V_60 , struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_32 ( V_60 , & V_4 ) ;
return F_44 ( V_29 , & V_4 ) ;
}
static int F_45 ( struct V_59 * V_60 , struct V_1 * V_2 )
{
int V_5 = - V_18 ;
struct V_59 * V_92 = NULL ;
void * V_77 ;
struct V_15 * V_16 ;
T_3 V_28 ;
if ( V_2 -> V_20 [ V_27 ] )
V_28 = F_8 ( V_2 -> V_20 [ V_27 ] ) ;
else
V_28 = V_33 ;
V_92 = F_46 ( V_93 , V_17 ) ;
if ( V_92 == NULL )
return - V_18 ;
V_77 = F_47 ( V_92 , V_2 , & V_81 ,
0 , V_94 ) ;
if ( V_77 == NULL )
goto V_95;
F_48 () ;
V_16 = F_49 ( NULL , V_28 ) ;
if ( V_16 == NULL ) {
V_5 = - V_96 ;
goto V_97;
}
V_5 = F_19 ( V_92 , V_16 ) ;
F_50 () ;
if ( V_5 != 0 )
goto V_95;
F_38 ( V_92 , V_77 ) ;
return F_51 ( V_92 , V_2 ) ;
V_97:
F_50 () ;
V_95:
F_52 ( V_92 ) ;
return V_5 ;
}
static int F_53 ( struct V_59 * V_60 ,
struct V_85 * V_86 ,
T_1 V_98 )
{
int V_5 = - V_18 ;
void * V_77 ;
V_77 = F_36 ( V_60 , F_37 ( V_86 -> V_60 ) . V_79 , V_86 -> V_89 -> V_90 ,
& V_81 , V_82 ,
V_99 ) ;
if ( V_77 == NULL )
goto V_100;
V_5 = F_26 ( V_60 , V_21 , V_98 ) ;
if ( V_5 != 0 )
goto V_100;
F_38 ( V_60 , V_77 ) ;
return 0 ;
V_100:
F_39 ( V_60 , V_77 ) ;
return V_5 ;
}
static int F_54 ( struct V_59 * V_60 ,
struct V_85 * V_86 )
{
T_1 V_101 = V_86 -> args [ 0 ] ;
if ( V_101 == 0 ) {
if ( F_53 ( V_60 ,
V_86 ,
V_26 ) < 0 )
goto V_102;
V_101 ++ ;
}
if ( V_101 == 1 ) {
if ( F_53 ( V_60 ,
V_86 ,
V_30 ) < 0 )
goto V_102;
V_101 ++ ;
}
#if F_2 ( V_11 )
if ( V_101 == 2 ) {
if ( F_53 ( V_60 ,
V_86 ,
V_35 ) < 0 )
goto V_102;
V_101 ++ ;
}
#endif
V_102:
V_86 -> args [ 0 ] = V_101 ;
return V_60 -> V_91 ;
}
static int F_55 ( struct V_59 * V_60 , struct V_1 * V_2 )
{
int V_5 = - V_18 ;
struct V_59 * V_92 = NULL ;
void * V_77 ;
V_92 = F_46 ( V_93 , V_17 ) ;
if ( V_92 == NULL )
return - V_18 ;
V_77 = F_47 ( V_92 , V_2 , & V_81 ,
0 , V_103 ) ;
if ( V_77 == NULL )
goto V_104;
V_5 = F_26 ( V_92 ,
V_105 ,
V_106 ) ;
if ( V_5 != 0 )
goto V_104;
F_38 ( V_92 , V_77 ) ;
return F_51 ( V_92 , V_2 ) ;
V_104:
F_52 ( V_92 ) ;
return V_5 ;
}
int T_4 F_56 ( void )
{
return F_57 ( & V_81 ) ;
}
