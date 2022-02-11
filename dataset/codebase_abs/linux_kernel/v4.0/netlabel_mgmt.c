static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = - V_6 ;
struct V_7 * V_8 = NULL ;
struct V_9 * V_10 = NULL ;
T_1 V_11 ;
struct V_12 * V_13 = F_2 ( sizeof( * V_13 ) , V_14 ) ;
if ( ! V_13 )
return - V_15 ;
V_13 -> V_16 . type = F_3 ( V_2 -> V_17 [ V_18 ] ) ;
if ( V_2 -> V_17 [ V_19 ] ) {
T_2 V_20 = F_4 ( V_2 -> V_17 [ V_19 ] ) ;
V_13 -> V_21 = F_5 ( V_20 , V_14 ) ;
if ( V_13 -> V_21 == NULL ) {
V_5 = - V_15 ;
goto V_22;
}
F_6 ( V_13 -> V_21 ,
V_2 -> V_17 [ V_19 ] , V_20 ) ;
}
switch ( V_13 -> V_16 . type ) {
case V_23 :
break;
case V_24 :
if ( ! V_2 -> V_17 [ V_25 ] )
goto V_26;
V_11 = F_3 ( V_2 -> V_17 [ V_25 ] ) ;
V_10 = F_7 ( V_11 ) ;
if ( V_10 == NULL )
goto V_26;
V_13 -> V_16 . V_27 = V_10 ;
break;
default:
goto V_26;
}
if ( V_2 -> V_17 [ V_28 ] ) {
struct V_29 * V_30 ;
struct V_29 * V_31 ;
struct V_32 * V_33 ;
V_8 = F_2 ( sizeof( * V_8 ) , V_14 ) ;
if ( V_8 == NULL ) {
V_5 = - V_15 ;
goto V_34;
}
F_8 ( & V_8 -> V_35 ) ;
F_8 ( & V_8 -> V_36 ) ;
if ( F_4 ( V_2 -> V_17 [ V_28 ] ) !=
sizeof( struct V_29 ) ) {
V_5 = - V_6 ;
goto V_37;
}
if ( F_4 ( V_2 -> V_17 [ V_38 ] ) !=
sizeof( struct V_29 ) ) {
V_5 = - V_6 ;
goto V_37;
}
V_30 = F_9 ( V_2 -> V_17 [ V_28 ] ) ;
V_31 = F_9 ( V_2 -> V_17 [ V_38 ] ) ;
V_33 = F_2 ( sizeof( * V_33 ) , V_14 ) ;
if ( V_33 == NULL ) {
V_5 = - V_15 ;
goto V_37;
}
V_33 -> V_39 . V_30 = V_30 -> V_40 & V_31 -> V_40 ;
V_33 -> V_39 . V_31 = V_31 -> V_40 ;
V_33 -> V_39 . V_41 = 1 ;
V_33 -> V_16 . type = V_13 -> V_16 . type ;
if ( V_10 )
V_33 -> V_16 . V_27 = V_10 ;
V_5 = F_10 ( & V_33 -> V_39 , & V_8 -> V_35 ) ;
if ( V_5 != 0 ) {
F_11 ( V_33 ) ;
goto V_37;
}
V_13 -> V_16 . type = V_42 ;
V_13 -> V_16 . V_43 = V_8 ;
#if F_12 ( V_44 )
} else if ( V_2 -> V_17 [ V_45 ] ) {
struct V_46 * V_30 ;
struct V_46 * V_31 ;
struct V_47 * V_33 ;
V_8 = F_2 ( sizeof( * V_8 ) , V_14 ) ;
if ( V_8 == NULL ) {
V_5 = - V_15 ;
goto V_34;
}
F_8 ( & V_8 -> V_35 ) ;
F_8 ( & V_8 -> V_36 ) ;
if ( F_4 ( V_2 -> V_17 [ V_45 ] ) !=
sizeof( struct V_46 ) ) {
V_5 = - V_6 ;
goto V_37;
}
if ( F_4 ( V_2 -> V_17 [ V_48 ] ) !=
sizeof( struct V_46 ) ) {
V_5 = - V_6 ;
goto V_37;
}
V_30 = F_9 ( V_2 -> V_17 [ V_45 ] ) ;
V_31 = F_9 ( V_2 -> V_17 [ V_48 ] ) ;
V_33 = F_2 ( sizeof( * V_33 ) , V_14 ) ;
if ( V_33 == NULL ) {
V_5 = - V_15 ;
goto V_37;
}
V_33 -> V_39 . V_30 = * V_30 ;
V_33 -> V_39 . V_30 . V_49 [ 0 ] &= V_31 -> V_49 [ 0 ] ;
V_33 -> V_39 . V_30 . V_49 [ 1 ] &= V_31 -> V_49 [ 1 ] ;
V_33 -> V_39 . V_30 . V_49 [ 2 ] &= V_31 -> V_49 [ 2 ] ;
V_33 -> V_39 . V_30 . V_49 [ 3 ] &= V_31 -> V_49 [ 3 ] ;
V_33 -> V_39 . V_31 = * V_31 ;
V_33 -> V_39 . V_41 = 1 ;
V_33 -> V_16 . type = V_13 -> V_16 . type ;
V_5 = F_13 ( & V_33 -> V_39 , & V_8 -> V_36 ) ;
if ( V_5 != 0 ) {
F_11 ( V_33 ) ;
goto V_37;
}
V_13 -> V_16 . type = V_42 ;
V_13 -> V_16 . V_43 = V_8 ;
#endif
}
V_5 = F_14 ( V_13 , V_4 ) ;
if ( V_5 != 0 )
goto V_37;
return 0 ;
V_37:
F_11 ( V_8 ) ;
V_34:
F_15 ( V_10 ) ;
V_26:
F_11 ( V_13 -> V_21 ) ;
V_22:
F_11 ( V_13 ) ;
return V_5 ;
}
static int F_16 ( struct V_50 * V_51 ,
struct V_12 * V_13 )
{
int V_5 = 0 ;
struct V_52 * V_53 ;
struct V_52 * V_54 ;
struct V_55 * V_56 ;
#if F_12 ( V_44 )
struct V_57 * V_58 ;
#endif
if ( V_13 -> V_21 != NULL ) {
V_5 = F_17 ( V_51 ,
V_19 , V_13 -> V_21 ) ;
if ( V_5 != 0 )
return V_5 ;
}
switch ( V_13 -> V_16 . type ) {
case V_42 :
V_53 = F_18 ( V_51 , V_59 ) ;
if ( V_53 == NULL )
return - V_15 ;
F_19 (iter4, &entry->def.addrsel->list4) {
struct V_32 * V_60 ;
struct V_29 V_61 ;
V_54 = F_18 ( V_51 , V_62 ) ;
if ( V_54 == NULL )
return - V_15 ;
V_61 . V_40 = V_56 -> V_30 ;
V_5 = F_20 ( V_51 , V_28 ,
sizeof( struct V_29 ) ,
& V_61 ) ;
if ( V_5 != 0 )
return V_5 ;
V_61 . V_40 = V_56 -> V_31 ;
V_5 = F_20 ( V_51 , V_38 ,
sizeof( struct V_29 ) ,
& V_61 ) ;
if ( V_5 != 0 )
return V_5 ;
V_60 = F_21 ( V_56 ) ;
V_5 = F_22 ( V_51 , V_18 ,
V_60 -> V_16 . type ) ;
if ( V_5 != 0 )
return V_5 ;
switch ( V_60 -> V_16 . type ) {
case V_24 :
V_5 = F_22 ( V_51 , V_25 ,
V_60 -> V_16 . V_27 -> V_63 ) ;
if ( V_5 != 0 )
return V_5 ;
break;
}
F_23 ( V_51 , V_54 ) ;
}
#if F_12 ( V_44 )
F_24 (iter6, &entry->def.addrsel->list6) {
struct V_47 * V_64 ;
V_54 = F_18 ( V_51 , V_62 ) ;
if ( V_54 == NULL )
return - V_15 ;
V_5 = F_20 ( V_51 , V_45 ,
sizeof( struct V_46 ) ,
& V_58 -> V_30 ) ;
if ( V_5 != 0 )
return V_5 ;
V_5 = F_20 ( V_51 , V_48 ,
sizeof( struct V_46 ) ,
& V_58 -> V_31 ) ;
if ( V_5 != 0 )
return V_5 ;
V_64 = F_25 ( V_58 ) ;
V_5 = F_22 ( V_51 , V_18 ,
V_64 -> V_16 . type ) ;
if ( V_5 != 0 )
return V_5 ;
F_23 ( V_51 , V_54 ) ;
}
#endif
F_23 ( V_51 , V_53 ) ;
break;
case V_23 :
V_5 = F_22 ( V_51 , V_18 , V_13 -> V_16 . type ) ;
break;
case V_24 :
V_5 = F_22 ( V_51 , V_18 , V_13 -> V_16 . type ) ;
if ( V_5 != 0 )
return V_5 ;
V_5 = F_22 ( V_51 , V_25 ,
V_13 -> V_16 . V_27 -> V_63 ) ;
break;
}
return V_5 ;
}
static int F_26 ( struct V_50 * V_51 , struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( ( ! V_2 -> V_17 [ V_19 ] ) ||
( ! V_2 -> V_17 [ V_18 ] ) ||
( V_2 -> V_17 [ V_28 ] &&
V_2 -> V_17 [ V_45 ] ) ||
( V_2 -> V_17 [ V_38 ] &&
V_2 -> V_17 [ V_48 ] ) ||
( ( V_2 -> V_17 [ V_28 ] != NULL ) ^
( V_2 -> V_17 [ V_38 ] != NULL ) ) ||
( ( V_2 -> V_17 [ V_45 ] != NULL ) ^
( V_2 -> V_17 [ V_48 ] != NULL ) ) )
return - V_6 ;
F_27 ( V_51 , & V_4 ) ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_28 ( struct V_50 * V_51 , struct V_1 * V_2 )
{
char * V_21 ;
struct V_3 V_4 ;
if ( ! V_2 -> V_17 [ V_19 ] )
return - V_6 ;
F_27 ( V_51 , & V_4 ) ;
V_21 = F_9 ( V_2 -> V_17 [ V_19 ] ) ;
return F_29 ( V_21 , & V_4 ) ;
}
static int F_30 ( struct V_12 * V_13 , void * V_65 )
{
int V_5 = - V_15 ;
struct V_66 * V_67 = V_65 ;
void * V_68 ;
V_68 = F_31 ( V_67 -> V_51 , F_32 ( V_67 -> V_69 -> V_51 ) . V_70 ,
V_67 -> V_71 , & V_72 ,
V_73 , V_74 ) ;
if ( V_68 == NULL )
goto V_75;
V_5 = F_16 ( V_67 -> V_51 , V_13 ) ;
if ( V_5 != 0 )
goto V_75;
V_67 -> V_71 ++ ;
F_33 ( V_67 -> V_51 , V_68 ) ;
return 0 ;
V_75:
F_34 ( V_67 -> V_51 , V_68 ) ;
return V_5 ;
}
static int F_35 ( struct V_50 * V_51 ,
struct V_76 * V_77 )
{
struct V_66 V_67 ;
T_1 V_78 = V_77 -> args [ 0 ] ;
T_1 V_79 = V_77 -> args [ 1 ] ;
V_67 . V_69 = V_77 ;
V_67 . V_51 = V_51 ;
V_67 . V_71 = V_77 -> V_80 -> V_81 ;
F_36 ( & V_78 ,
& V_79 ,
F_30 ,
& V_67 ) ;
V_77 -> args [ 0 ] = V_78 ;
V_77 -> args [ 1 ] = V_79 ;
return V_51 -> V_82 ;
}
static int F_37 ( struct V_50 * V_51 , struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( ( ! V_2 -> V_17 [ V_18 ] ) ||
( V_2 -> V_17 [ V_28 ] &&
V_2 -> V_17 [ V_45 ] ) ||
( V_2 -> V_17 [ V_38 ] &&
V_2 -> V_17 [ V_48 ] ) ||
( ( V_2 -> V_17 [ V_28 ] != NULL ) ^
( V_2 -> V_17 [ V_38 ] != NULL ) ) ||
( ( V_2 -> V_17 [ V_45 ] != NULL ) ^
( V_2 -> V_17 [ V_48 ] != NULL ) ) )
return - V_6 ;
F_27 ( V_51 , & V_4 ) ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_38 ( struct V_50 * V_51 , struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_27 ( V_51 , & V_4 ) ;
return F_39 ( & V_4 ) ;
}
static int F_40 ( struct V_50 * V_51 , struct V_1 * V_2 )
{
int V_5 = - V_15 ;
struct V_50 * V_83 = NULL ;
void * V_68 ;
struct V_12 * V_13 ;
V_83 = F_41 ( V_84 , V_14 ) ;
if ( V_83 == NULL )
return - V_15 ;
V_68 = F_42 ( V_83 , V_2 , & V_72 ,
0 , V_85 ) ;
if ( V_68 == NULL )
goto V_86;
F_43 () ;
V_13 = F_44 ( NULL ) ;
if ( V_13 == NULL ) {
V_5 = - V_87 ;
goto V_88;
}
V_5 = F_16 ( V_83 , V_13 ) ;
F_45 () ;
if ( V_5 != 0 )
goto V_86;
F_33 ( V_83 , V_68 ) ;
return F_46 ( V_83 , V_2 ) ;
V_88:
F_45 () ;
V_86:
F_47 ( V_83 ) ;
return V_5 ;
}
static int F_48 ( struct V_50 * V_51 ,
struct V_76 * V_77 ,
T_1 V_89 )
{
int V_5 = - V_15 ;
void * V_68 ;
V_68 = F_31 ( V_51 , F_32 ( V_77 -> V_51 ) . V_70 , V_77 -> V_80 -> V_81 ,
& V_72 , V_73 ,
V_90 ) ;
if ( V_68 == NULL )
goto V_91;
V_5 = F_22 ( V_51 , V_18 , V_89 ) ;
if ( V_5 != 0 )
goto V_91;
F_33 ( V_51 , V_68 ) ;
return 0 ;
V_91:
F_34 ( V_51 , V_68 ) ;
return V_5 ;
}
static int F_49 ( struct V_50 * V_51 ,
struct V_76 * V_77 )
{
T_1 V_92 = V_77 -> args [ 0 ] ;
if ( V_92 == 0 ) {
if ( F_48 ( V_51 ,
V_77 ,
V_23 ) < 0 )
goto V_93;
V_92 ++ ;
}
if ( V_92 == 1 ) {
if ( F_48 ( V_51 ,
V_77 ,
V_24 ) < 0 )
goto V_93;
V_92 ++ ;
}
V_93:
V_77 -> args [ 0 ] = V_92 ;
return V_51 -> V_82 ;
}
static int F_50 ( struct V_50 * V_51 , struct V_1 * V_2 )
{
int V_5 = - V_15 ;
struct V_50 * V_83 = NULL ;
void * V_68 ;
V_83 = F_41 ( V_84 , V_14 ) ;
if ( V_83 == NULL )
return - V_15 ;
V_68 = F_42 ( V_83 , V_2 , & V_72 ,
0 , V_94 ) ;
if ( V_68 == NULL )
goto V_95;
V_5 = F_22 ( V_83 ,
V_96 ,
V_97 ) ;
if ( V_5 != 0 )
goto V_95;
F_33 ( V_83 , V_68 ) ;
return F_46 ( V_83 , V_2 ) ;
V_95:
F_47 ( V_83 ) ;
return V_5 ;
}
int T_3 F_51 ( void )
{
return F_52 ( & V_72 ,
V_98 ) ;
}
