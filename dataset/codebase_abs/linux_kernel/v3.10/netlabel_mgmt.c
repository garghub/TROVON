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
#if F_12 ( V_40 )
} else if ( V_2 -> V_17 [ V_41 ] ) {
struct V_42 * V_28 ;
struct V_42 * V_29 ;
struct V_43 * V_31 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_14 ) ;
if ( V_10 == NULL ) {
V_5 = - V_15 ;
goto V_16;
}
F_8 ( & V_10 -> V_32 ) ;
F_8 ( & V_10 -> V_33 ) ;
if ( F_4 ( V_2 -> V_17 [ V_41 ] ) !=
sizeof( struct V_42 ) ) {
V_5 = - V_6 ;
goto V_16;
}
if ( F_4 ( V_2 -> V_17 [ V_44 ] ) !=
sizeof( struct V_42 ) ) {
V_5 = - V_6 ;
goto V_16;
}
V_28 = F_9 ( V_2 -> V_17 [ V_41 ] ) ;
V_29 = F_9 ( V_2 -> V_17 [ V_44 ] ) ;
V_31 = F_2 ( sizeof( * V_31 ) , V_14 ) ;
if ( V_31 == NULL ) {
V_5 = - V_15 ;
goto V_16;
}
V_31 -> V_35 . V_28 = * V_28 ;
V_31 -> V_35 . V_28 . V_45 [ 0 ] &= V_29 -> V_45 [ 0 ] ;
V_31 -> V_35 . V_28 . V_45 [ 1 ] &= V_29 -> V_45 [ 1 ] ;
V_31 -> V_35 . V_28 . V_45 [ 2 ] &= V_29 -> V_45 [ 2 ] ;
V_31 -> V_35 . V_28 . V_45 [ 3 ] &= V_29 -> V_45 [ 3 ] ;
V_31 -> V_35 . V_29 = * V_29 ;
V_31 -> V_35 . V_37 = 1 ;
V_31 -> type = V_8 -> type ;
V_5 = F_13 ( & V_31 -> V_35 , & V_10 -> V_33 ) ;
if ( V_5 != 0 ) {
F_11 ( V_31 ) ;
goto V_16;
}
V_8 -> type = V_38 ;
V_8 -> V_25 . V_39 = V_10 ;
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
F_11 ( V_8 -> V_21 ) ;
F_11 ( V_10 ) ;
F_11 ( V_8 ) ;
return V_5 ;
}
static int F_16 ( struct V_46 * V_47 ,
struct V_7 * V_8 )
{
int V_5 = 0 ;
struct V_48 * V_49 ;
struct V_48 * V_50 ;
struct V_51 * V_52 ;
#if F_12 ( V_40 )
struct V_53 * V_54 ;
#endif
if ( V_8 -> V_21 != NULL ) {
V_5 = F_17 ( V_47 ,
V_19 , V_8 -> V_21 ) ;
if ( V_5 != 0 )
return V_5 ;
}
switch ( V_8 -> type ) {
case V_38 :
V_49 = F_18 ( V_47 , V_55 ) ;
if ( V_49 == NULL )
return - V_15 ;
F_19 (iter4,
&entry->type_def.addrsel->list4) {
struct V_30 * V_56 ;
struct V_27 V_57 ;
V_50 = F_18 ( V_47 , V_58 ) ;
if ( V_50 == NULL )
return - V_15 ;
V_57 . V_36 = V_52 -> V_28 ;
V_5 = F_20 ( V_47 , V_26 ,
sizeof( struct V_27 ) ,
& V_57 ) ;
if ( V_5 != 0 )
return V_5 ;
V_57 . V_36 = V_52 -> V_29 ;
V_5 = F_20 ( V_47 , V_34 ,
sizeof( struct V_27 ) ,
& V_57 ) ;
if ( V_5 != 0 )
return V_5 ;
V_56 = F_21 ( V_52 ) ;
V_5 = F_22 ( V_47 , V_18 ,
V_56 -> type ) ;
if ( V_5 != 0 )
return V_5 ;
switch ( V_56 -> type ) {
case V_23 :
V_5 = F_22 ( V_47 , V_24 ,
V_56 -> V_25 . V_12 -> V_59 ) ;
if ( V_5 != 0 )
return V_5 ;
break;
}
F_23 ( V_47 , V_50 ) ;
}
#if F_12 ( V_40 )
F_24 (iter6,
&entry->type_def.addrsel->list6) {
struct V_43 * V_60 ;
V_50 = F_18 ( V_47 , V_58 ) ;
if ( V_50 == NULL )
return - V_15 ;
V_5 = F_20 ( V_47 , V_41 ,
sizeof( struct V_42 ) ,
& V_54 -> V_28 ) ;
if ( V_5 != 0 )
return V_5 ;
V_5 = F_20 ( V_47 , V_44 ,
sizeof( struct V_42 ) ,
& V_54 -> V_29 ) ;
if ( V_5 != 0 )
return V_5 ;
V_60 = F_25 ( V_54 ) ;
V_5 = F_22 ( V_47 , V_18 ,
V_60 -> type ) ;
if ( V_5 != 0 )
return V_5 ;
F_23 ( V_47 , V_50 ) ;
}
#endif
F_23 ( V_47 , V_49 ) ;
break;
case V_22 :
V_5 = F_22 ( V_47 , V_18 , V_8 -> type ) ;
break;
case V_23 :
V_5 = F_22 ( V_47 , V_18 , V_8 -> type ) ;
if ( V_5 != 0 )
return V_5 ;
V_5 = F_22 ( V_47 , V_24 ,
V_8 -> V_25 . V_12 -> V_59 ) ;
break;
}
return V_5 ;
}
static int F_26 ( struct V_46 * V_47 , struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( ( ! V_2 -> V_17 [ V_19 ] ) ||
( ! V_2 -> V_17 [ V_18 ] ) ||
( V_2 -> V_17 [ V_26 ] &&
V_2 -> V_17 [ V_41 ] ) ||
( V_2 -> V_17 [ V_34 ] &&
V_2 -> V_17 [ V_44 ] ) ||
( ( V_2 -> V_17 [ V_26 ] != NULL ) ^
( V_2 -> V_17 [ V_34 ] != NULL ) ) ||
( ( V_2 -> V_17 [ V_41 ] != NULL ) ^
( V_2 -> V_17 [ V_44 ] != NULL ) ) )
return - V_6 ;
F_27 ( V_47 , & V_4 ) ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_28 ( struct V_46 * V_47 , struct V_1 * V_2 )
{
char * V_21 ;
struct V_3 V_4 ;
if ( ! V_2 -> V_17 [ V_19 ] )
return - V_6 ;
F_27 ( V_47 , & V_4 ) ;
V_21 = F_9 ( V_2 -> V_17 [ V_19 ] ) ;
return F_29 ( V_21 , & V_4 ) ;
}
static int F_30 ( struct V_7 * V_8 , void * V_61 )
{
int V_5 = - V_15 ;
struct V_62 * V_63 = V_61 ;
void * V_64 ;
V_64 = F_31 ( V_63 -> V_47 , F_32 ( V_63 -> V_65 -> V_47 ) . V_66 ,
V_63 -> V_67 , & V_68 ,
V_69 , V_70 ) ;
if ( V_64 == NULL )
goto V_71;
V_5 = F_16 ( V_63 -> V_47 , V_8 ) ;
if ( V_5 != 0 )
goto V_71;
V_63 -> V_67 ++ ;
return F_33 ( V_63 -> V_47 , V_64 ) ;
V_71:
F_34 ( V_63 -> V_47 , V_64 ) ;
return V_5 ;
}
static int F_35 ( struct V_46 * V_47 ,
struct V_72 * V_73 )
{
struct V_62 V_63 ;
T_1 V_74 = V_73 -> args [ 0 ] ;
T_1 V_75 = V_73 -> args [ 1 ] ;
V_63 . V_65 = V_73 ;
V_63 . V_47 = V_47 ;
V_63 . V_67 = V_73 -> V_76 -> V_77 ;
F_36 ( & V_74 ,
& V_75 ,
F_30 ,
& V_63 ) ;
V_73 -> args [ 0 ] = V_74 ;
V_73 -> args [ 1 ] = V_75 ;
return V_47 -> V_78 ;
}
static int F_37 ( struct V_46 * V_47 , struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( ( ! V_2 -> V_17 [ V_18 ] ) ||
( V_2 -> V_17 [ V_26 ] &&
V_2 -> V_17 [ V_41 ] ) ||
( V_2 -> V_17 [ V_34 ] &&
V_2 -> V_17 [ V_44 ] ) ||
( ( V_2 -> V_17 [ V_26 ] != NULL ) ^
( V_2 -> V_17 [ V_34 ] != NULL ) ) ||
( ( V_2 -> V_17 [ V_41 ] != NULL ) ^
( V_2 -> V_17 [ V_44 ] != NULL ) ) )
return - V_6 ;
F_27 ( V_47 , & V_4 ) ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_38 ( struct V_46 * V_47 , struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_27 ( V_47 , & V_4 ) ;
return F_39 ( & V_4 ) ;
}
static int F_40 ( struct V_46 * V_47 , struct V_1 * V_2 )
{
int V_5 = - V_15 ;
struct V_46 * V_79 = NULL ;
void * V_64 ;
struct V_7 * V_8 ;
V_79 = F_41 ( V_80 , V_14 ) ;
if ( V_79 == NULL )
return - V_15 ;
V_64 = F_42 ( V_79 , V_2 , & V_68 ,
0 , V_81 ) ;
if ( V_64 == NULL )
goto V_82;
F_43 () ;
V_8 = F_44 ( NULL ) ;
if ( V_8 == NULL ) {
V_5 = - V_83 ;
goto V_84;
}
V_5 = F_16 ( V_79 , V_8 ) ;
F_45 () ;
if ( V_5 != 0 )
goto V_82;
F_33 ( V_79 , V_64 ) ;
return F_46 ( V_79 , V_2 ) ;
V_84:
F_45 () ;
V_82:
F_47 ( V_79 ) ;
return V_5 ;
}
static int F_48 ( struct V_46 * V_47 ,
struct V_72 * V_73 ,
T_1 V_85 )
{
int V_5 = - V_15 ;
void * V_64 ;
V_64 = F_31 ( V_47 , F_32 ( V_73 -> V_47 ) . V_66 , V_73 -> V_76 -> V_77 ,
& V_68 , V_69 ,
V_86 ) ;
if ( V_64 == NULL )
goto V_87;
V_5 = F_22 ( V_47 , V_18 , V_85 ) ;
if ( V_5 != 0 )
goto V_87;
return F_33 ( V_47 , V_64 ) ;
V_87:
F_34 ( V_47 , V_64 ) ;
return V_5 ;
}
static int F_49 ( struct V_46 * V_47 ,
struct V_72 * V_73 )
{
T_1 V_88 = V_73 -> args [ 0 ] ;
if ( V_88 == 0 ) {
if ( F_48 ( V_47 ,
V_73 ,
V_22 ) < 0 )
goto V_89;
V_88 ++ ;
}
if ( V_88 == 1 ) {
if ( F_48 ( V_47 ,
V_73 ,
V_23 ) < 0 )
goto V_89;
V_88 ++ ;
}
V_89:
V_73 -> args [ 0 ] = V_88 ;
return V_47 -> V_78 ;
}
static int F_50 ( struct V_46 * V_47 , struct V_1 * V_2 )
{
int V_5 = - V_15 ;
struct V_46 * V_79 = NULL ;
void * V_64 ;
V_79 = F_41 ( V_80 , V_14 ) ;
if ( V_79 == NULL )
return - V_15 ;
V_64 = F_42 ( V_79 , V_2 , & V_68 ,
0 , V_90 ) ;
if ( V_64 == NULL )
goto V_91;
V_5 = F_22 ( V_79 ,
V_92 ,
V_93 ) ;
if ( V_5 != 0 )
goto V_91;
F_33 ( V_79 , V_64 ) ;
return F_46 ( V_79 , V_2 ) ;
V_91:
F_47 ( V_79 ) ;
return V_5 ;
}
int T_3 F_51 ( void )
{
return F_52 ( & V_68 ,
V_94 , F_53 ( V_94 ) ) ;
}
