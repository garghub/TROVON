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
V_8 -> type = F_3 ( V_2 -> V_17 [ V_18 ] ) ;
if ( V_2 -> V_17 [ V_19 ] ) {
T_2 V_20 = F_4 ( V_2 -> V_17 [ V_19 ] ) ;
V_8 -> V_21 = F_5 ( V_20 , V_14 ) ;
if ( V_8 -> V_21 == NULL ) {
V_5 = - V_15 ;
goto V_16;
}
F_6 ( V_8 -> V_21 ,
V_2 -> V_17 [ V_19 ] , V_20 ) ;
}
switch ( V_8 -> type ) {
case V_22 :
break;
case V_23 :
if ( ! V_2 -> V_17 [ V_24 ] )
goto V_16;
V_13 = F_3 ( V_2 -> V_17 [ V_24 ] ) ;
V_12 = F_7 ( V_13 ) ;
if ( V_12 == NULL )
goto V_16;
V_8 -> V_25 . V_12 = V_12 ;
break;
default:
goto V_16;
}
if ( V_2 -> V_17 [ V_26 ] ) {
struct V_27 * V_28 ;
struct V_27 * V_29 ;
struct V_30 * V_31 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_14 ) ;
if ( V_10 == NULL ) {
V_5 = - V_15 ;
goto V_16;
}
F_8 ( & V_10 -> V_32 ) ;
F_8 ( & V_10 -> V_33 ) ;
if ( F_4 ( V_2 -> V_17 [ V_26 ] ) !=
sizeof( struct V_27 ) ) {
V_5 = - V_6 ;
goto V_16;
}
if ( F_4 ( V_2 -> V_17 [ V_34 ] ) !=
sizeof( struct V_27 ) ) {
V_5 = - V_6 ;
goto V_16;
}
V_28 = F_9 ( V_2 -> V_17 [ V_26 ] ) ;
V_29 = F_9 ( V_2 -> V_17 [ V_34 ] ) ;
V_31 = F_2 ( sizeof( * V_31 ) , V_14 ) ;
if ( V_31 == NULL ) {
V_5 = - V_15 ;
goto V_16;
}
V_31 -> V_35 . V_28 = V_28 -> V_36 & V_29 -> V_36 ;
V_31 -> V_35 . V_29 = V_29 -> V_36 ;
V_31 -> V_35 . V_37 = 1 ;
V_31 -> type = V_8 -> type ;
if ( V_12 )
V_31 -> V_25 . V_12 = V_12 ;
V_5 = F_10 ( & V_31 -> V_35 , & V_10 -> V_32 ) ;
if ( V_5 != 0 ) {
F_11 ( V_31 ) ;
goto V_16;
}
V_8 -> type = V_38 ;
V_8 -> V_25 . V_39 = V_10 ;
#if F_12 ( V_40 ) || F_12 ( V_41 )
} else if ( V_2 -> V_17 [ V_42 ] ) {
struct V_43 * V_28 ;
struct V_43 * V_29 ;
struct V_44 * V_31 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_14 ) ;
if ( V_10 == NULL ) {
V_5 = - V_15 ;
goto V_16;
}
F_8 ( & V_10 -> V_32 ) ;
F_8 ( & V_10 -> V_33 ) ;
if ( F_4 ( V_2 -> V_17 [ V_42 ] ) !=
sizeof( struct V_43 ) ) {
V_5 = - V_6 ;
goto V_16;
}
if ( F_4 ( V_2 -> V_17 [ V_45 ] ) !=
sizeof( struct V_43 ) ) {
V_5 = - V_6 ;
goto V_16;
}
V_28 = F_9 ( V_2 -> V_17 [ V_42 ] ) ;
V_29 = F_9 ( V_2 -> V_17 [ V_45 ] ) ;
V_31 = F_2 ( sizeof( * V_31 ) , V_14 ) ;
if ( V_31 == NULL ) {
V_5 = - V_15 ;
goto V_16;
}
F_13 ( & V_31 -> V_35 . V_28 , V_28 ) ;
V_31 -> V_35 . V_28 . V_46 [ 0 ] &= V_29 -> V_46 [ 0 ] ;
V_31 -> V_35 . V_28 . V_46 [ 1 ] &= V_29 -> V_46 [ 1 ] ;
V_31 -> V_35 . V_28 . V_46 [ 2 ] &= V_29 -> V_46 [ 2 ] ;
V_31 -> V_35 . V_28 . V_46 [ 3 ] &= V_29 -> V_46 [ 3 ] ;
F_13 ( & V_31 -> V_35 . V_29 , V_29 ) ;
V_31 -> V_35 . V_37 = 1 ;
V_31 -> type = V_8 -> type ;
V_5 = F_14 ( & V_31 -> V_35 , & V_10 -> V_33 ) ;
if ( V_5 != 0 ) {
F_11 ( V_31 ) ;
goto V_16;
}
V_8 -> type = V_38 ;
V_8 -> V_25 . V_39 = V_10 ;
#endif
}
V_5 = F_15 ( V_8 , V_4 ) ;
if ( V_5 != 0 )
goto V_16;
return 0 ;
V_16:
if ( V_12 )
F_16 ( V_12 ) ;
if ( V_8 )
F_11 ( V_8 -> V_21 ) ;
F_11 ( V_10 ) ;
F_11 ( V_8 ) ;
return V_5 ;
}
static int F_17 ( struct V_47 * V_48 ,
struct V_7 * V_8 )
{
int V_5 = 0 ;
struct V_49 * V_50 ;
struct V_49 * V_51 ;
struct V_52 * V_53 ;
#if F_12 ( V_40 ) || F_12 ( V_41 )
struct V_54 * V_55 ;
#endif
if ( V_8 -> V_21 != NULL ) {
V_5 = F_18 ( V_48 ,
V_19 , V_8 -> V_21 ) ;
if ( V_5 != 0 )
return V_5 ;
}
switch ( V_8 -> type ) {
case V_38 :
V_50 = F_19 ( V_48 , V_56 ) ;
if ( V_50 == NULL )
return - V_15 ;
F_20 (iter4,
&entry->type_def.addrsel->list4) {
struct V_30 * V_57 ;
struct V_27 V_58 ;
V_51 = F_19 ( V_48 , V_59 ) ;
if ( V_51 == NULL )
return - V_15 ;
V_58 . V_36 = V_53 -> V_28 ;
V_5 = F_21 ( V_48 , V_26 ,
sizeof( struct V_27 ) ,
& V_58 ) ;
if ( V_5 != 0 )
return V_5 ;
V_58 . V_36 = V_53 -> V_29 ;
V_5 = F_21 ( V_48 , V_34 ,
sizeof( struct V_27 ) ,
& V_58 ) ;
if ( V_5 != 0 )
return V_5 ;
V_57 = F_22 ( V_53 ) ;
V_5 = F_23 ( V_48 , V_18 ,
V_57 -> type ) ;
if ( V_5 != 0 )
return V_5 ;
switch ( V_57 -> type ) {
case V_23 :
V_5 = F_23 ( V_48 , V_24 ,
V_57 -> V_25 . V_12 -> V_60 ) ;
if ( V_5 != 0 )
return V_5 ;
break;
}
F_24 ( V_48 , V_51 ) ;
}
#if F_12 ( V_40 ) || F_12 ( V_41 )
F_25 (iter6,
&entry->type_def.addrsel->list6) {
struct V_44 * V_61 ;
V_51 = F_19 ( V_48 , V_59 ) ;
if ( V_51 == NULL )
return - V_15 ;
V_5 = F_21 ( V_48 , V_42 ,
sizeof( struct V_43 ) ,
& V_55 -> V_28 ) ;
if ( V_5 != 0 )
return V_5 ;
V_5 = F_21 ( V_48 , V_45 ,
sizeof( struct V_43 ) ,
& V_55 -> V_29 ) ;
if ( V_5 != 0 )
return V_5 ;
V_61 = F_26 ( V_55 ) ;
V_5 = F_23 ( V_48 , V_18 ,
V_61 -> type ) ;
if ( V_5 != 0 )
return V_5 ;
F_24 ( V_48 , V_51 ) ;
}
#endif
F_24 ( V_48 , V_50 ) ;
break;
case V_22 :
V_5 = F_23 ( V_48 , V_18 , V_8 -> type ) ;
break;
case V_23 :
V_5 = F_23 ( V_48 , V_18 , V_8 -> type ) ;
if ( V_5 != 0 )
return V_5 ;
V_5 = F_23 ( V_48 , V_24 ,
V_8 -> V_25 . V_12 -> V_60 ) ;
break;
}
return V_5 ;
}
static int F_27 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( ( ! V_2 -> V_17 [ V_19 ] ) ||
( ! V_2 -> V_17 [ V_18 ] ) ||
( V_2 -> V_17 [ V_26 ] &&
V_2 -> V_17 [ V_42 ] ) ||
( V_2 -> V_17 [ V_34 ] &&
V_2 -> V_17 [ V_45 ] ) ||
( ( V_2 -> V_17 [ V_26 ] != NULL ) ^
( V_2 -> V_17 [ V_34 ] != NULL ) ) ||
( ( V_2 -> V_17 [ V_42 ] != NULL ) ^
( V_2 -> V_17 [ V_45 ] != NULL ) ) )
return - V_6 ;
F_28 ( V_48 , & V_4 ) ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_29 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
char * V_21 ;
struct V_3 V_4 ;
if ( ! V_2 -> V_17 [ V_19 ] )
return - V_6 ;
F_28 ( V_48 , & V_4 ) ;
V_21 = F_9 ( V_2 -> V_17 [ V_19 ] ) ;
return F_30 ( V_21 , & V_4 ) ;
}
static int F_31 ( struct V_7 * V_8 , void * V_62 )
{
int V_5 = - V_15 ;
struct V_63 * V_64 = V_62 ;
void * V_65 ;
V_65 = F_32 ( V_64 -> V_48 , F_33 ( V_64 -> V_66 -> V_48 ) . V_67 ,
V_64 -> V_68 , & V_69 ,
V_70 , V_71 ) ;
if ( V_65 == NULL )
goto V_72;
V_5 = F_17 ( V_64 -> V_48 , V_8 ) ;
if ( V_5 != 0 )
goto V_72;
V_64 -> V_68 ++ ;
return F_34 ( V_64 -> V_48 , V_65 ) ;
V_72:
F_35 ( V_64 -> V_48 , V_65 ) ;
return V_5 ;
}
static int F_36 ( struct V_47 * V_48 ,
struct V_73 * V_74 )
{
struct V_63 V_64 ;
T_1 V_75 = V_74 -> args [ 0 ] ;
T_1 V_76 = V_74 -> args [ 1 ] ;
V_64 . V_66 = V_74 ;
V_64 . V_48 = V_48 ;
V_64 . V_68 = V_74 -> V_77 -> V_78 ;
F_37 ( & V_75 ,
& V_76 ,
F_31 ,
& V_64 ) ;
V_74 -> args [ 0 ] = V_75 ;
V_74 -> args [ 1 ] = V_76 ;
return V_48 -> V_79 ;
}
static int F_38 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( ( ! V_2 -> V_17 [ V_18 ] ) ||
( V_2 -> V_17 [ V_26 ] &&
V_2 -> V_17 [ V_42 ] ) ||
( V_2 -> V_17 [ V_34 ] &&
V_2 -> V_17 [ V_45 ] ) ||
( ( V_2 -> V_17 [ V_26 ] != NULL ) ^
( V_2 -> V_17 [ V_34 ] != NULL ) ) ||
( ( V_2 -> V_17 [ V_42 ] != NULL ) ^
( V_2 -> V_17 [ V_45 ] != NULL ) ) )
return - V_6 ;
F_28 ( V_48 , & V_4 ) ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_39 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_28 ( V_48 , & V_4 ) ;
return F_40 ( & V_4 ) ;
}
static int F_41 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
int V_5 = - V_15 ;
struct V_47 * V_80 = NULL ;
void * V_65 ;
struct V_7 * V_8 ;
V_80 = F_42 ( V_81 , V_14 ) ;
if ( V_80 == NULL )
return - V_15 ;
V_65 = F_43 ( V_80 , V_2 , & V_69 ,
0 , V_82 ) ;
if ( V_65 == NULL )
goto V_83;
F_44 () ;
V_8 = F_45 ( NULL ) ;
if ( V_8 == NULL ) {
V_5 = - V_84 ;
goto V_85;
}
V_5 = F_17 ( V_80 , V_8 ) ;
F_46 () ;
if ( V_5 != 0 )
goto V_83;
F_34 ( V_80 , V_65 ) ;
return F_47 ( V_80 , V_2 ) ;
V_85:
F_46 () ;
V_83:
F_48 ( V_80 ) ;
return V_5 ;
}
static int F_49 ( struct V_47 * V_48 ,
struct V_73 * V_74 ,
T_1 V_86 )
{
int V_5 = - V_15 ;
void * V_65 ;
V_65 = F_32 ( V_48 , F_33 ( V_74 -> V_48 ) . V_67 , V_74 -> V_77 -> V_78 ,
& V_69 , V_70 ,
V_87 ) ;
if ( V_65 == NULL )
goto V_88;
V_5 = F_23 ( V_48 , V_18 , V_86 ) ;
if ( V_5 != 0 )
goto V_88;
return F_34 ( V_48 , V_65 ) ;
V_88:
F_35 ( V_48 , V_65 ) ;
return V_5 ;
}
static int F_50 ( struct V_47 * V_48 ,
struct V_73 * V_74 )
{
T_1 V_89 = V_74 -> args [ 0 ] ;
if ( V_89 == 0 ) {
if ( F_49 ( V_48 ,
V_74 ,
V_22 ) < 0 )
goto V_90;
V_89 ++ ;
}
if ( V_89 == 1 ) {
if ( F_49 ( V_48 ,
V_74 ,
V_23 ) < 0 )
goto V_90;
V_89 ++ ;
}
V_90:
V_74 -> args [ 0 ] = V_89 ;
return V_48 -> V_79 ;
}
static int F_51 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
int V_5 = - V_15 ;
struct V_47 * V_80 = NULL ;
void * V_65 ;
V_80 = F_42 ( V_81 , V_14 ) ;
if ( V_80 == NULL )
return - V_15 ;
V_65 = F_43 ( V_80 , V_2 , & V_69 ,
0 , V_91 ) ;
if ( V_65 == NULL )
goto V_92;
V_5 = F_23 ( V_80 ,
V_93 ,
V_94 ) ;
if ( V_5 != 0 )
goto V_92;
F_34 ( V_80 , V_65 ) ;
return F_47 ( V_80 , V_2 ) ;
V_92:
F_48 ( V_80 ) ;
return V_5 ;
}
int T_3 F_52 ( void )
{
return F_53 ( & V_69 ,
V_95 , F_54 ( V_95 ) ) ;
}
