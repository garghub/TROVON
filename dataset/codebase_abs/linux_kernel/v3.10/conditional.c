static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_5 ;
int V_6 [ V_7 ] ;
int V_8 = - 1 ;
for ( V_5 = V_4 ; V_5 ; V_5 = V_5 -> V_9 ) {
switch ( V_5 -> V_10 ) {
case V_11 :
if ( V_8 == ( V_7 - 1 ) )
return - 1 ;
V_8 ++ ;
V_6 [ V_8 ] = V_2 -> V_12 [ V_5 -> bool - 1 ] -> V_13 ;
break;
case V_14 :
if ( V_8 < 0 )
return - 1 ;
V_6 [ V_8 ] = ! V_6 [ V_8 ] ;
break;
case V_15 :
if ( V_8 < 1 )
return - 1 ;
V_8 -- ;
V_6 [ V_8 ] |= V_6 [ V_8 + 1 ] ;
break;
case V_16 :
if ( V_8 < 1 )
return - 1 ;
V_8 -- ;
V_6 [ V_8 ] &= V_6 [ V_8 + 1 ] ;
break;
case V_17 :
if ( V_8 < 1 )
return - 1 ;
V_8 -- ;
V_6 [ V_8 ] ^= V_6 [ V_8 + 1 ] ;
break;
case V_18 :
if ( V_8 < 1 )
return - 1 ;
V_8 -- ;
V_6 [ V_8 ] = ( V_6 [ V_8 ] == V_6 [ V_8 + 1 ] ) ;
break;
case V_19 :
if ( V_8 < 1 )
return - 1 ;
V_8 -- ;
V_6 [ V_8 ] = ( V_6 [ V_8 ] != V_6 [ V_8 + 1 ] ) ;
break;
default:
return - 1 ;
}
}
return V_6 [ 0 ] ;
}
int F_2 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_22 ;
struct V_23 * V_5 ;
V_22 = F_1 ( V_2 , V_21 -> V_4 ) ;
if ( V_22 != V_21 -> V_24 ) {
V_21 -> V_24 = V_22 ;
if ( V_22 == - 1 )
F_3 ( V_25 L_1 ) ;
for ( V_5 = V_21 -> V_26 ; V_5 ; V_5 = V_5 -> V_9 ) {
if ( V_22 <= 0 )
V_5 -> V_21 -> V_27 . V_28 &= ~ V_29 ;
else
V_5 -> V_21 -> V_27 . V_28 |= V_29 ;
}
for ( V_5 = V_21 -> V_30 ; V_5 ; V_5 = V_5 -> V_9 ) {
if ( V_22 )
V_5 -> V_21 -> V_27 . V_28 &= ~ V_29 ;
else
V_5 -> V_21 -> V_27 . V_28 |= V_29 ;
}
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 )
{
int V_31 ;
V_2 -> V_12 = NULL ;
V_2 -> V_32 = NULL ;
V_31 = F_5 ( & V_2 -> V_33 ) ;
if ( V_31 )
return V_31 ;
return 0 ;
}
static void F_6 ( struct V_23 * V_34 )
{
struct V_23 * V_5 , * V_9 ;
for ( V_5 = V_34 ; V_5 ; V_5 = V_9 ) {
V_9 = V_5 -> V_9 ;
F_7 ( V_5 ) ;
}
}
static void F_8 ( struct V_20 * V_21 )
{
struct V_3 * V_35 , * V_36 ;
for ( V_35 = V_21 -> V_4 ; V_35 ; V_35 = V_36 ) {
V_36 = V_35 -> V_9 ;
F_7 ( V_35 ) ;
}
F_6 ( V_21 -> V_26 ) ;
F_6 ( V_21 -> V_30 ) ;
F_7 ( V_21 ) ;
}
static void F_9 ( struct V_20 * V_34 )
{
struct V_20 * V_9 , * V_5 ;
if ( V_34 == NULL )
return;
for ( V_5 = V_34 ; V_5 ; V_5 = V_9 ) {
V_9 = V_5 -> V_9 ;
F_8 ( V_5 ) ;
}
}
void F_10 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_12 ) ;
F_11 ( & V_2 -> V_33 ) ;
F_9 ( V_2 -> V_32 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_12 ) ;
V_2 -> V_12 =
F_13 ( V_2 -> V_37 . V_38 * sizeof( struct V_39 * ) , V_40 ) ;
if ( ! V_2 -> V_12 )
return - V_41 ;
return 0 ;
}
int F_14 ( void * V_27 , void * V_42 , void * V_2 )
{
F_7 ( V_27 ) ;
F_7 ( V_42 ) ;
return 0 ;
}
int F_15 ( void * V_27 , void * V_42 , void * V_43 )
{
struct V_1 * V_2 ;
struct V_39 * V_44 ;
struct V_45 * V_46 ;
V_44 = V_42 ;
V_2 = V_43 ;
if ( ! V_44 -> V_47 || V_44 -> V_47 > V_2 -> V_37 . V_38 )
return - V_48 ;
V_46 = V_2 -> V_49 [ V_50 ] ;
if ( F_16 ( V_46 , V_44 -> V_47 - 1 , V_27 ,
V_40 | V_51 ) )
F_17 () ;
V_2 -> V_12 [ V_44 -> V_47 - 1 ] = V_44 ;
return 0 ;
}
static int F_18 ( struct V_39 * V_52 )
{
if ( ! ( V_52 -> V_13 == 0 || V_52 -> V_13 == 1 ) )
return 0 ;
return 1 ;
}
int F_19 ( struct V_1 * V_2 , struct V_53 * V_54 , void * V_55 )
{
char * V_27 = NULL ;
struct V_39 * V_44 ;
T_1 V_56 [ 3 ] ;
T_2 V_57 ;
int V_31 ;
V_44 = F_20 ( sizeof( struct V_39 ) , V_40 ) ;
if ( ! V_44 )
return - V_41 ;
V_31 = F_21 ( V_56 , V_55 , sizeof V_56 ) ;
if ( V_31 )
goto V_58;
V_44 -> V_47 = F_22 ( V_56 [ 0 ] ) ;
V_44 -> V_13 = F_22 ( V_56 [ 1 ] ) ;
V_31 = - V_48 ;
if ( ! F_18 ( V_44 ) )
goto V_58;
V_57 = F_22 ( V_56 [ 2 ] ) ;
V_31 = - V_41 ;
V_27 = F_13 ( V_57 + 1 , V_40 ) ;
if ( ! V_27 )
goto V_58;
V_31 = F_21 ( V_27 , V_55 , V_57 ) ;
if ( V_31 )
goto V_58;
V_27 [ V_57 ] = '\0' ;
V_31 = F_23 ( V_54 , V_27 , V_44 ) ;
if ( V_31 )
goto V_58;
return 0 ;
V_58:
F_14 ( V_27 , V_44 , NULL ) ;
return V_31 ;
}
static int F_24 ( struct V_59 * V_60 , struct V_61 * V_62 , struct V_63 * V_64 , void * V_65 )
{
struct V_66 * V_67 = V_65 ;
struct V_1 * V_2 = V_67 -> V_2 ;
struct V_23 * V_68 = V_67 -> V_68 , * V_34 , * V_5 ;
struct V_69 * V_70 ;
T_3 V_71 ;
int V_31 = - V_48 ;
if ( V_62 -> V_28 & V_72 ) {
if ( F_25 ( & V_2 -> V_73 , V_62 ) ) {
F_3 ( V_25 L_2 ) ;
goto V_58;
}
if ( V_68 ) {
V_70 = F_26 ( & V_2 -> V_33 , V_62 ) ;
if ( V_70 ) {
if ( F_27 ( V_70 , V_62 -> V_28 ) ) {
F_3 ( V_25 L_3 ) ;
goto V_58;
}
V_71 = 0 ;
for ( V_5 = V_68 ; V_5 ; V_5 = V_5 -> V_9 ) {
if ( V_5 -> V_21 == V_70 ) {
V_71 = 1 ;
break;
}
}
if ( ! V_71 ) {
F_3 ( V_25 L_4 ) ;
goto V_58;
}
}
} else {
if ( F_25 ( & V_2 -> V_33 , V_62 ) ) {
F_3 ( V_25 L_5 ) ;
goto V_58;
}
}
}
V_70 = F_28 ( & V_2 -> V_33 , V_62 , V_64 ) ;
if ( ! V_70 ) {
F_3 ( V_25 L_6 ) ;
V_31 = - V_41 ;
goto V_58;
}
V_34 = F_20 ( sizeof( struct V_23 ) , V_40 ) ;
if ( ! V_34 ) {
V_31 = - V_41 ;
goto V_58;
}
V_34 -> V_21 = V_70 ;
if ( ! V_67 -> V_74 )
V_67 -> V_74 = V_34 ;
else
V_67 -> V_75 -> V_9 = V_34 ;
V_67 -> V_75 = V_34 ;
return 0 ;
V_58:
F_6 ( V_67 -> V_74 ) ;
V_67 -> V_74 = NULL ;
return V_31 ;
}
static int F_29 ( struct V_1 * V_2 , void * V_55 , struct V_23 * * V_76 , struct V_23 * V_68 )
{
int V_77 , V_31 ;
T_1 V_56 [ 1 ] ;
T_2 V_57 ;
struct V_66 V_67 ;
* V_76 = NULL ;
V_57 = 0 ;
V_31 = F_21 ( V_56 , V_55 , sizeof( T_2 ) ) ;
if ( V_31 )
return V_31 ;
V_57 = F_22 ( V_56 [ 0 ] ) ;
if ( V_57 == 0 )
return 0 ;
V_67 . V_2 = V_2 ;
V_67 . V_68 = V_68 ;
V_67 . V_74 = NULL ;
V_67 . V_75 = NULL ;
for ( V_77 = 0 ; V_77 < V_57 ; V_77 ++ ) {
V_31 = F_30 ( & V_2 -> V_33 , V_55 , V_2 , F_24 ,
& V_67 ) ;
if ( V_31 )
return V_31 ;
}
* V_76 = V_67 . V_74 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_10 <= 0 || V_4 -> V_10 > V_78 ) {
F_3 ( V_25 L_7 ) ;
return 0 ;
}
if ( V_4 -> bool > V_2 -> V_37 . V_38 ) {
F_3 ( V_25 L_8 ) ;
return 0 ;
}
return 1 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_20 * V_21 , void * V_55 )
{
T_1 V_56 [ 2 ] ;
T_2 V_57 , V_77 ;
int V_31 ;
struct V_3 * V_4 = NULL , * V_79 = NULL ;
V_31 = F_21 ( V_56 , V_55 , sizeof( T_2 ) ) ;
if ( V_31 )
return V_31 ;
V_21 -> V_24 = F_22 ( V_56 [ 0 ] ) ;
V_57 = 0 ;
V_31 = F_21 ( V_56 , V_55 , sizeof( T_2 ) ) ;
if ( V_31 )
return V_31 ;
V_57 = F_22 ( V_56 [ 0 ] ) ;
for ( V_77 = 0 ; V_77 < V_57 ; V_77 ++ ) {
V_31 = F_21 ( V_56 , V_55 , sizeof( T_2 ) * 2 ) ;
if ( V_31 )
goto V_58;
V_31 = - V_41 ;
V_4 = F_20 ( sizeof( struct V_3 ) , V_40 ) ;
if ( ! V_4 )
goto V_58;
V_4 -> V_10 = F_22 ( V_56 [ 0 ] ) ;
V_4 -> bool = F_22 ( V_56 [ 1 ] ) ;
if ( ! F_31 ( V_2 , V_4 ) ) {
V_31 = - V_48 ;
F_7 ( V_4 ) ;
goto V_58;
}
if ( V_77 == 0 )
V_21 -> V_4 = V_4 ;
else
V_79 -> V_9 = V_4 ;
V_79 = V_4 ;
}
V_31 = F_29 ( V_2 , V_55 , & V_21 -> V_26 , NULL ) ;
if ( V_31 )
goto V_58;
V_31 = F_29 ( V_2 , V_55 , & V_21 -> V_30 , V_21 -> V_26 ) ;
if ( V_31 )
goto V_58;
return 0 ;
V_58:
F_8 ( V_21 ) ;
return V_31 ;
}
int F_33 ( struct V_1 * V_2 , void * V_55 )
{
struct V_20 * V_21 , * V_79 = NULL ;
T_1 V_56 [ 1 ] ;
T_2 V_77 , V_57 ;
int V_31 ;
V_31 = F_21 ( V_56 , V_55 , sizeof V_56 ) ;
if ( V_31 )
return V_31 ;
V_57 = F_22 ( V_56 [ 0 ] ) ;
V_31 = F_34 ( & ( V_2 -> V_33 ) , V_2 -> V_73 . V_80 ) ;
if ( V_31 )
goto V_58;
for ( V_77 = 0 ; V_77 < V_57 ; V_77 ++ ) {
V_31 = - V_41 ;
V_21 = F_20 ( sizeof( struct V_20 ) , V_40 ) ;
if ( ! V_21 )
goto V_58;
V_31 = F_32 ( V_2 , V_21 , V_55 ) ;
if ( V_31 )
goto V_58;
if ( V_77 == 0 )
V_2 -> V_32 = V_21 ;
else
V_79 -> V_9 = V_21 ;
V_79 = V_21 ;
}
return 0 ;
V_58:
F_9 ( V_2 -> V_32 ) ;
V_2 -> V_32 = NULL ;
return V_31 ;
}
int F_35 ( void * V_81 , void * V_42 , void * V_65 )
{
char * V_27 = V_81 ;
struct V_39 * V_44 = V_42 ;
struct V_82 * V_83 = V_65 ;
void * V_55 = V_83 -> V_55 ;
T_1 V_56 [ 3 ] ;
T_2 V_57 ;
int V_31 ;
V_57 = strlen ( V_27 ) ;
V_56 [ 0 ] = F_36 ( V_44 -> V_47 ) ;
V_56 [ 1 ] = F_36 ( V_44 -> V_13 ) ;
V_56 [ 2 ] = F_36 ( V_57 ) ;
V_31 = F_37 ( V_56 , sizeof( T_2 ) , 3 , V_55 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_37 ( V_27 , 1 , V_57 , V_55 ) ;
if ( V_31 )
return V_31 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_23 * V_34 , struct V_84 * V_55 )
{
T_1 V_56 [ 1 ] ;
struct V_23 * V_85 ;
T_2 V_57 ;
int V_31 ;
V_57 = 0 ;
for ( V_85 = V_34 ; V_85 != NULL ; V_85 = V_85 -> V_9 )
V_57 ++ ;
V_56 [ 0 ] = F_36 ( V_57 ) ;
V_31 = F_37 ( V_56 , sizeof( T_2 ) , 1 , V_55 ) ;
if ( V_31 )
return V_31 ;
if ( V_57 == 0 )
return 0 ;
for ( V_85 = V_34 ; V_85 != NULL ; V_85 = V_85 -> V_9 ) {
V_31 = F_39 ( V_2 , V_85 -> V_21 , V_55 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_84 * V_55 )
{
struct V_3 * V_35 ;
T_1 V_56 [ 2 ] ;
int V_31 ;
T_2 V_57 = 0 ;
V_56 [ 0 ] = F_36 ( V_21 -> V_24 ) ;
V_31 = F_37 ( V_56 , sizeof( T_2 ) , 1 , V_55 ) ;
if ( V_31 )
return V_31 ;
for ( V_35 = V_21 -> V_4 ; V_35 != NULL ; V_35 = V_35 -> V_9 )
V_57 ++ ;
V_56 [ 0 ] = F_36 ( V_57 ) ;
V_31 = F_37 ( V_56 , sizeof( T_2 ) , 1 , V_55 ) ;
if ( V_31 )
return V_31 ;
for ( V_35 = V_21 -> V_4 ; V_35 != NULL ; V_35 = V_35 -> V_9 ) {
V_56 [ 0 ] = F_36 ( V_35 -> V_10 ) ;
V_56 [ 1 ] = F_36 ( V_35 -> bool ) ;
V_31 = F_37 ( V_56 , sizeof( T_2 ) , 2 , V_55 ) ;
if ( V_31 )
return V_31 ;
}
V_31 = F_38 ( V_2 , V_21 -> V_26 , V_55 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_38 ( V_2 , V_21 -> V_30 , V_55 ) ;
if ( V_31 )
return V_31 ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 , struct V_20 * V_34 , void * V_55 )
{
struct V_20 * V_5 ;
T_2 V_57 ;
T_1 V_56 [ 1 ] ;
int V_31 ;
V_57 = 0 ;
for ( V_5 = V_34 ; V_5 != NULL ; V_5 = V_5 -> V_9 )
V_57 ++ ;
V_56 [ 0 ] = F_36 ( V_57 ) ;
V_31 = F_37 ( V_56 , sizeof( T_2 ) , 1 , V_55 ) ;
if ( V_31 )
return V_31 ;
for ( V_5 = V_34 ; V_5 != NULL ; V_5 = V_5 -> V_9 ) {
V_31 = F_40 ( V_2 , V_5 , V_55 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
void F_42 ( struct V_59 * V_86 , struct V_61 * V_27 , struct V_87 * V_88 )
{
struct V_69 * V_21 ;
if ( ! V_86 || ! V_27 || ! V_88 )
return;
for ( V_21 = F_26 ( V_86 , V_27 ) ; V_21 ;
V_21 = F_27 ( V_21 , V_27 -> V_28 ) ) {
if ( ( V_89 ) ( V_90 | V_29 ) ==
( V_21 -> V_27 . V_28 & ( V_90 | V_29 ) ) )
V_88 -> V_91 |= V_21 -> V_42 . V_67 ;
if ( ( V_89 ) ( V_92 | V_29 ) ==
( V_21 -> V_27 . V_28 & ( V_92 | V_29 ) ) )
V_88 -> V_93 &= V_21 -> V_42 . V_67 ;
if ( ( V_89 ) ( V_94 | V_29 ) ==
( V_21 -> V_27 . V_28 & ( V_94 | V_29 ) ) )
V_88 -> V_95 |= V_21 -> V_42 . V_67 ;
}
return;
}
