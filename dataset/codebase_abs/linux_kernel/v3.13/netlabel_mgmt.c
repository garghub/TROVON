static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = - V_6 ;
struct V_7 * V_8 = NULL ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
T_1 V_13 ;
V_8 = F_2 ( sizeof( * V_8 ) , V_14 ) ;
if ( V_8 == NULL ) {
V_5 = - V_15 ;
goto V_16;
}
V_8 -> V_17 . type = F_3 ( V_2 -> V_18 [ V_19 ] ) ;
if ( V_2 -> V_18 [ V_20 ] ) {
T_2 V_21 = F_4 ( V_2 -> V_18 [ V_20 ] ) ;
V_8 -> V_22 = F_5 ( V_21 , V_14 ) ;
if ( V_8 -> V_22 == NULL ) {
V_5 = - V_15 ;
goto V_16;
}
F_6 ( V_8 -> V_22 ,
V_2 -> V_18 [ V_20 ] , V_21 ) ;
}
switch ( V_8 -> V_17 . type ) {
case V_23 :
break;
case V_24 :
if ( ! V_2 -> V_18 [ V_25 ] )
goto V_16;
V_13 = F_3 ( V_2 -> V_18 [ V_25 ] ) ;
V_12 = F_7 ( V_13 ) ;
if ( V_12 == NULL )
goto V_16;
V_8 -> V_17 . V_26 = V_12 ;
break;
default:
goto V_16;
}
if ( V_2 -> V_18 [ V_27 ] ) {
struct V_28 * V_29 ;
struct V_28 * V_30 ;
struct V_31 * V_32 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_14 ) ;
if ( V_10 == NULL ) {
V_5 = - V_15 ;
goto V_16;
}
F_8 ( & V_10 -> V_33 ) ;
F_8 ( & V_10 -> V_34 ) ;
if ( F_4 ( V_2 -> V_18 [ V_27 ] ) !=
sizeof( struct V_28 ) ) {
V_5 = - V_6 ;
goto V_16;
}
if ( F_4 ( V_2 -> V_18 [ V_35 ] ) !=
sizeof( struct V_28 ) ) {
V_5 = - V_6 ;
goto V_16;
}
V_29 = F_9 ( V_2 -> V_18 [ V_27 ] ) ;
V_30 = F_9 ( V_2 -> V_18 [ V_35 ] ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_14 ) ;
if ( V_32 == NULL ) {
V_5 = - V_15 ;
goto V_16;
}
V_32 -> V_36 . V_29 = V_29 -> V_37 & V_30 -> V_37 ;
V_32 -> V_36 . V_30 = V_30 -> V_37 ;
V_32 -> V_36 . V_38 = 1 ;
V_32 -> V_17 . type = V_8 -> V_17 . type ;
if ( V_12 )
V_32 -> V_17 . V_26 = V_12 ;
V_5 = F_10 ( & V_32 -> V_36 , & V_10 -> V_33 ) ;
if ( V_5 != 0 ) {
F_11 ( V_32 ) ;
goto V_16;
}
V_8 -> V_17 . type = V_39 ;
V_8 -> V_17 . V_40 = V_10 ;
#if F_12 ( V_41 )
} else if ( V_2 -> V_18 [ V_42 ] ) {
struct V_43 * V_29 ;
struct V_43 * V_30 ;
struct V_44 * V_32 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_14 ) ;
if ( V_10 == NULL ) {
V_5 = - V_15 ;
goto V_16;
}
F_8 ( & V_10 -> V_33 ) ;
F_8 ( & V_10 -> V_34 ) ;
if ( F_4 ( V_2 -> V_18 [ V_42 ] ) !=
sizeof( struct V_43 ) ) {
V_5 = - V_6 ;
goto V_16;
}
if ( F_4 ( V_2 -> V_18 [ V_45 ] ) !=
sizeof( struct V_43 ) ) {
V_5 = - V_6 ;
goto V_16;
}
V_29 = F_9 ( V_2 -> V_18 [ V_42 ] ) ;
V_30 = F_9 ( V_2 -> V_18 [ V_45 ] ) ;
V_32 = F_2 ( sizeof( * V_32 ) , V_14 ) ;
if ( V_32 == NULL ) {
V_5 = - V_15 ;
goto V_16;
}
V_32 -> V_36 . V_29 = * V_29 ;
V_32 -> V_36 . V_29 . V_46 [ 0 ] &= V_30 -> V_46 [ 0 ] ;
V_32 -> V_36 . V_29 . V_46 [ 1 ] &= V_30 -> V_46 [ 1 ] ;
V_32 -> V_36 . V_29 . V_46 [ 2 ] &= V_30 -> V_46 [ 2 ] ;
V_32 -> V_36 . V_29 . V_46 [ 3 ] &= V_30 -> V_46 [ 3 ] ;
V_32 -> V_36 . V_30 = * V_30 ;
V_32 -> V_36 . V_38 = 1 ;
V_32 -> V_17 . type = V_8 -> V_17 . type ;
V_5 = F_13 ( & V_32 -> V_36 , & V_10 -> V_34 ) ;
if ( V_5 != 0 ) {
F_11 ( V_32 ) ;
goto V_16;
}
V_8 -> V_17 . type = V_39 ;
V_8 -> V_17 . V_40 = V_10 ;
#endif
}
V_5 = F_14 ( V_8 , V_4 ) ;
if ( V_5 != 0 )
goto V_16;
return 0 ;
V_16:
if ( V_12 )
F_15 ( V_12 ) ;
if ( V_8 )
F_11 ( V_8 -> V_22 ) ;
F_11 ( V_10 ) ;
F_11 ( V_8 ) ;
return V_5 ;
}
static int F_16 ( struct V_47 * V_48 ,
struct V_7 * V_8 )
{
int V_5 = 0 ;
struct V_49 * V_50 ;
struct V_49 * V_51 ;
struct V_52 * V_53 ;
#if F_12 ( V_41 )
struct V_54 * V_55 ;
#endif
if ( V_8 -> V_22 != NULL ) {
V_5 = F_17 ( V_48 ,
V_20 , V_8 -> V_22 ) ;
if ( V_5 != 0 )
return V_5 ;
}
switch ( V_8 -> V_17 . type ) {
case V_39 :
V_50 = F_18 ( V_48 , V_56 ) ;
if ( V_50 == NULL )
return - V_15 ;
F_19 (iter4, &entry->def.addrsel->list4) {
struct V_31 * V_57 ;
struct V_28 V_58 ;
V_51 = F_18 ( V_48 , V_59 ) ;
if ( V_51 == NULL )
return - V_15 ;
V_58 . V_37 = V_53 -> V_29 ;
V_5 = F_20 ( V_48 , V_27 ,
sizeof( struct V_28 ) ,
& V_58 ) ;
if ( V_5 != 0 )
return V_5 ;
V_58 . V_37 = V_53 -> V_30 ;
V_5 = F_20 ( V_48 , V_35 ,
sizeof( struct V_28 ) ,
& V_58 ) ;
if ( V_5 != 0 )
return V_5 ;
V_57 = F_21 ( V_53 ) ;
V_5 = F_22 ( V_48 , V_19 ,
V_57 -> V_17 . type ) ;
if ( V_5 != 0 )
return V_5 ;
switch ( V_57 -> V_17 . type ) {
case V_24 :
V_5 = F_22 ( V_48 , V_25 ,
V_57 -> V_17 . V_26 -> V_60 ) ;
if ( V_5 != 0 )
return V_5 ;
break;
}
F_23 ( V_48 , V_51 ) ;
}
#if F_12 ( V_41 )
F_24 (iter6, &entry->def.addrsel->list6) {
struct V_44 * V_61 ;
V_51 = F_18 ( V_48 , V_59 ) ;
if ( V_51 == NULL )
return - V_15 ;
V_5 = F_20 ( V_48 , V_42 ,
sizeof( struct V_43 ) ,
& V_55 -> V_29 ) ;
if ( V_5 != 0 )
return V_5 ;
V_5 = F_20 ( V_48 , V_45 ,
sizeof( struct V_43 ) ,
& V_55 -> V_30 ) ;
if ( V_5 != 0 )
return V_5 ;
V_61 = F_25 ( V_55 ) ;
V_5 = F_22 ( V_48 , V_19 ,
V_61 -> V_17 . type ) ;
if ( V_5 != 0 )
return V_5 ;
F_23 ( V_48 , V_51 ) ;
}
#endif
F_23 ( V_48 , V_50 ) ;
break;
case V_23 :
V_5 = F_22 ( V_48 , V_19 , V_8 -> V_17 . type ) ;
break;
case V_24 :
V_5 = F_22 ( V_48 , V_19 , V_8 -> V_17 . type ) ;
if ( V_5 != 0 )
return V_5 ;
V_5 = F_22 ( V_48 , V_25 ,
V_8 -> V_17 . V_26 -> V_60 ) ;
break;
}
return V_5 ;
}
static int F_26 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( ( ! V_2 -> V_18 [ V_20 ] ) ||
( ! V_2 -> V_18 [ V_19 ] ) ||
( V_2 -> V_18 [ V_27 ] &&
V_2 -> V_18 [ V_42 ] ) ||
( V_2 -> V_18 [ V_35 ] &&
V_2 -> V_18 [ V_45 ] ) ||
( ( V_2 -> V_18 [ V_27 ] != NULL ) ^
( V_2 -> V_18 [ V_35 ] != NULL ) ) ||
( ( V_2 -> V_18 [ V_42 ] != NULL ) ^
( V_2 -> V_18 [ V_45 ] != NULL ) ) )
return - V_6 ;
F_27 ( V_48 , & V_4 ) ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_28 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
char * V_22 ;
struct V_3 V_4 ;
if ( ! V_2 -> V_18 [ V_20 ] )
return - V_6 ;
F_27 ( V_48 , & V_4 ) ;
V_22 = F_9 ( V_2 -> V_18 [ V_20 ] ) ;
return F_29 ( V_22 , & V_4 ) ;
}
static int F_30 ( struct V_7 * V_8 , void * V_62 )
{
int V_5 = - V_15 ;
struct V_63 * V_64 = V_62 ;
void * V_65 ;
V_65 = F_31 ( V_64 -> V_48 , F_32 ( V_64 -> V_66 -> V_48 ) . V_67 ,
V_64 -> V_68 , & V_69 ,
V_70 , V_71 ) ;
if ( V_65 == NULL )
goto V_72;
V_5 = F_16 ( V_64 -> V_48 , V_8 ) ;
if ( V_5 != 0 )
goto V_72;
V_64 -> V_68 ++ ;
return F_33 ( V_64 -> V_48 , V_65 ) ;
V_72:
F_34 ( V_64 -> V_48 , V_65 ) ;
return V_5 ;
}
static int F_35 ( struct V_47 * V_48 ,
struct V_73 * V_74 )
{
struct V_63 V_64 ;
T_1 V_75 = V_74 -> args [ 0 ] ;
T_1 V_76 = V_74 -> args [ 1 ] ;
V_64 . V_66 = V_74 ;
V_64 . V_48 = V_48 ;
V_64 . V_68 = V_74 -> V_77 -> V_78 ;
F_36 ( & V_75 ,
& V_76 ,
F_30 ,
& V_64 ) ;
V_74 -> args [ 0 ] = V_75 ;
V_74 -> args [ 1 ] = V_76 ;
return V_48 -> V_79 ;
}
static int F_37 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( ( ! V_2 -> V_18 [ V_19 ] ) ||
( V_2 -> V_18 [ V_27 ] &&
V_2 -> V_18 [ V_42 ] ) ||
( V_2 -> V_18 [ V_35 ] &&
V_2 -> V_18 [ V_45 ] ) ||
( ( V_2 -> V_18 [ V_27 ] != NULL ) ^
( V_2 -> V_18 [ V_35 ] != NULL ) ) ||
( ( V_2 -> V_18 [ V_42 ] != NULL ) ^
( V_2 -> V_18 [ V_45 ] != NULL ) ) )
return - V_6 ;
F_27 ( V_48 , & V_4 ) ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_38 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_27 ( V_48 , & V_4 ) ;
return F_39 ( & V_4 ) ;
}
static int F_40 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
int V_5 = - V_15 ;
struct V_47 * V_80 = NULL ;
void * V_65 ;
struct V_7 * V_8 ;
V_80 = F_41 ( V_81 , V_14 ) ;
if ( V_80 == NULL )
return - V_15 ;
V_65 = F_42 ( V_80 , V_2 , & V_69 ,
0 , V_82 ) ;
if ( V_65 == NULL )
goto V_83;
F_43 () ;
V_8 = F_44 ( NULL ) ;
if ( V_8 == NULL ) {
V_5 = - V_84 ;
goto V_85;
}
V_5 = F_16 ( V_80 , V_8 ) ;
F_45 () ;
if ( V_5 != 0 )
goto V_83;
F_33 ( V_80 , V_65 ) ;
return F_46 ( V_80 , V_2 ) ;
V_85:
F_45 () ;
V_83:
F_47 ( V_80 ) ;
return V_5 ;
}
static int F_48 ( struct V_47 * V_48 ,
struct V_73 * V_74 ,
T_1 V_86 )
{
int V_5 = - V_15 ;
void * V_65 ;
V_65 = F_31 ( V_48 , F_32 ( V_74 -> V_48 ) . V_67 , V_74 -> V_77 -> V_78 ,
& V_69 , V_70 ,
V_87 ) ;
if ( V_65 == NULL )
goto V_88;
V_5 = F_22 ( V_48 , V_19 , V_86 ) ;
if ( V_5 != 0 )
goto V_88;
return F_33 ( V_48 , V_65 ) ;
V_88:
F_34 ( V_48 , V_65 ) ;
return V_5 ;
}
static int F_49 ( struct V_47 * V_48 ,
struct V_73 * V_74 )
{
T_1 V_89 = V_74 -> args [ 0 ] ;
if ( V_89 == 0 ) {
if ( F_48 ( V_48 ,
V_74 ,
V_23 ) < 0 )
goto V_90;
V_89 ++ ;
}
if ( V_89 == 1 ) {
if ( F_48 ( V_48 ,
V_74 ,
V_24 ) < 0 )
goto V_90;
V_89 ++ ;
}
V_90:
V_74 -> args [ 0 ] = V_89 ;
return V_48 -> V_79 ;
}
static int F_50 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
int V_5 = - V_15 ;
struct V_47 * V_80 = NULL ;
void * V_65 ;
V_80 = F_41 ( V_81 , V_14 ) ;
if ( V_80 == NULL )
return - V_15 ;
V_65 = F_42 ( V_80 , V_2 , & V_69 ,
0 , V_91 ) ;
if ( V_65 == NULL )
goto V_92;
V_5 = F_22 ( V_80 ,
V_93 ,
V_94 ) ;
if ( V_5 != 0 )
goto V_92;
F_33 ( V_80 , V_65 ) ;
return F_46 ( V_80 , V_2 ) ;
V_92:
F_47 ( V_80 ) ;
return V_5 ;
}
int T_3 F_51 ( void )
{
return F_52 ( & V_69 ,
V_95 ) ;
}
