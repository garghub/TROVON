int T_1
F_1 ( void )
{
int V_1 ;
struct V_2 * V_3 ;
struct V_4 V_5 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_6 ) ;
if ( ! V_3 ) {
V_1 = - V_7 ;
goto V_8;
}
V_1 = F_3 ( NULL , V_9 ,
L_1 ) ;
if ( V_1 < 0 )
goto V_8;
V_10 = V_1 ;
F_4 ( ( L_2 , V_1 ) ) ;
F_5 ( V_10 ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
strcpy ( V_3 -> V_11 , L_3 ) ;
V_3 -> V_12 . V_13 = V_10 ;
V_3 -> V_14 = V_15 ;
V_3 -> type = 0 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_16 = V_17 ;
V_3 -> V_18 = & V_5 ;
F_6 ( V_19 , V_3 ) ;
if ( ( V_20 = V_3 -> V_12 . V_3 ) >= 0 ) {
struct V_21 V_22 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_23 . V_13 = V_24 ;
V_22 . V_23 . V_3 = V_25 ;
V_22 . V_26 . V_13 = V_10 ;
V_22 . V_26 . V_3 = V_20 ;
F_6 ( V_27 , & V_22 ) ;
}
V_1 = 0 ;
V_8:
F_7 ( V_3 ) ;
return V_1 ;
}
static int
V_17 ( struct V_28 * V_29 , int V_30 , void * V_31 , int V_32 , int V_33 )
{
struct V_2 V_34 ;
if ( V_32 )
return 0 ;
switch ( V_29 -> type ) {
case V_35 :
case V_36 :
if ( V_29 -> V_37 . V_12 . V_13 == V_10 )
break;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_12 = V_29 -> V_37 . V_12 ;
if ( F_6 ( V_38 , & V_34 ) >= 0 )
F_8 ( & V_34 ) ;
break;
case V_39 :
if ( V_29 -> V_37 . V_12 . V_13 == V_10 )
break;
F_9 ( V_29 -> V_37 . V_12 . V_13 ,
V_29 -> V_37 . V_12 . V_3 ) ;
break;
}
return 0 ;
}
int
F_10 ( void )
{
if ( V_10 >= 0 )
F_11 ( V_10 ) ;
F_12 () ;
return 0 ;
}
int
F_13 ( struct V_40 * V_40 , int V_41 )
{
int V_42 , V_1 ;
struct V_43 * V_44 ;
V_44 = F_14 ( sizeof( * V_44 ) , V_6 ) ;
if ( ! V_44 ) {
F_15 ( V_45 L_4 ) ;
return - V_7 ;
}
F_4 ( ( L_5 , V_44 ) ) ;
V_44 -> V_46 = V_10 ;
V_44 -> V_3 = - 1 ;
V_44 -> V_47 = - 1 ;
for ( V_42 = 0 ; V_42 < V_48 ; V_42 ++ ) {
if ( V_49 [ V_42 ] == NULL )
break;
}
V_44 -> V_50 = V_42 ;
if ( V_42 >= V_48 ) {
F_15 ( V_45 L_6 ) ;
V_1 = - V_7 ;
goto V_51;
}
F_16 ( V_44 ) ;
F_17 ( V_44 ) ;
if ( V_44 -> V_52 == 0 && V_44 -> V_53 == 0 ) {
V_1 = - V_54 ;
goto V_51;
}
F_4 ( ( L_7 ) ) ;
V_1 = F_18 ( V_44 ) ;
if ( V_1 < 0 ) {
F_15 ( V_45 L_8 ) ;
goto V_51;
}
F_4 ( ( L_9 ) ) ;
V_1 = F_19 ( V_44 ) ;
if ( V_1 < 0 )
goto V_51;
V_44 -> V_12 . V_13 = V_44 -> V_46 ;
V_44 -> V_12 . V_3 = V_44 -> V_3 ;
V_44 -> V_55 = V_41 ;
V_44 -> V_56 = F_20 ( V_40 ) ;
F_4 ( ( L_10 ) ) ;
if ( F_21 ( V_44 -> V_56 ) ) {
V_44 -> V_57 = F_22 ( V_44 , V_58 ) ;
if ( ! V_44 -> V_57 ) {
V_1 = - V_7 ;
goto V_51;
}
}
F_4 ( ( L_11 ) ) ;
if ( F_23 ( V_44 -> V_56 ) ) {
V_44 -> V_59 = F_24 ( V_44 , V_58 ) ;
if ( ! V_44 -> V_59 ) {
V_1 = - V_7 ;
goto V_51;
}
}
F_4 ( ( L_12 ) ) ;
V_44 -> V_60 = F_25 ( V_44 ) ;
if ( ! V_44 -> V_60 ) {
F_15 ( V_45 L_13 ) ;
V_1 = - V_7 ;
goto V_51;
}
F_4 ( ( L_14 ) ) ;
V_40 -> V_61 = V_44 ;
if ( V_41 == V_62 )
F_26 ( V_44 ) ;
else if ( F_21 ( V_44 -> V_56 ) )
F_27 ( V_44 , V_63 ) ;
V_49 [ V_44 -> V_50 ] = V_44 ;
V_64 ++ ;
F_4 ( ( L_15 ) ) ;
return 0 ;
V_51:
F_28 ( V_44 ) ;
F_29 ( V_44 ) ;
F_30 ( V_44 -> V_47 ) ;
F_31 ( V_44 ) ;
return V_1 ;
}
static int
F_20 ( struct V_40 * V_40 )
{
int V_56 = 0 ;
if ( ( V_40 -> V_65 & V_66 ) != V_67 )
V_56 |= V_68 ;
if ( ( V_40 -> V_65 & V_66 ) != V_69 )
V_56 |= V_63 ;
if ( V_40 -> V_65 & V_70 )
V_56 |= V_71 ;
return V_56 ;
}
static int
F_18 ( struct V_43 * V_44 )
{
int V_1 ;
struct V_2 V_3 ;
struct V_4 V_72 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_12 . V_13 = V_44 -> V_46 ;
sprintf ( V_3 . V_11 , L_16 , V_44 -> V_50 ) ;
V_3 . V_14 = V_73 | V_15 ;
V_3 . type = V_74 ;
V_3 . V_75 = 128 ;
V_3 . V_76 = 128 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_77 = V_78 ;
V_72 . V_61 = V_44 ;
V_72 . V_16 = V_79 ;
V_72 . V_80 = V_81 ;
V_3 . V_18 = & V_72 ;
V_1 = F_6 ( V_19 , & V_3 ) ;
if ( V_1 < 0 )
return V_1 ;
V_44 -> V_3 = V_3 . V_12 . V_3 ;
F_4 ( ( L_17 , V_3 . V_12 . V_3 ) ) ;
return 0 ;
}
static int
F_31 ( struct V_43 * V_44 )
{
if ( V_44 -> V_3 < 0 ) {
F_7 ( V_44 ) ;
return 0 ;
}
F_4 ( ( L_18 , V_44 -> V_3 ) ) ;
return F_32 ( V_44 -> V_46 , V_44 -> V_3 ) ;
}
static int
F_19 ( struct V_43 * V_44 )
{
struct V_82 V_83 ;
int V_1 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_77 = V_10 ;
V_83 . V_84 = 1 ;
strcpy ( V_83 . V_11 , L_19 ) ;
if ( ( V_1 = F_6 ( V_85 , & V_83 ) ) < 0 )
return V_1 ;
V_44 -> V_47 = V_83 . V_47 ;
return 0 ;
}
static int
F_30 ( int V_47 )
{
struct V_82 V_83 ;
int V_1 ;
if ( V_47 < 0 )
return 0 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_47 = V_47 ;
V_1 = F_6 ( V_86 , & V_83 ) ;
if ( V_1 < 0 )
F_33 ( V_45 L_20 , V_47 , V_1 ) ;
return V_1 ;
}
static void
V_81 ( void * V_31 )
{
struct V_43 * V_44 = (struct V_43 * ) V_31 ;
if ( V_44 -> V_60 )
F_34 ( V_44 -> V_60 ) ;
if ( V_44 -> V_59 )
F_35 ( V_44 -> V_59 ) ;
if ( V_44 -> V_57 )
F_36 ( V_44 -> V_57 ) ;
F_7 ( V_44 ) ;
}
void
F_37 ( struct V_43 * V_44 )
{
int V_47 ;
V_49 [ V_44 -> V_50 ] = NULL ;
V_64 -- ;
F_4 ( ( L_21 ) ) ;
F_38 ( V_44 ) ;
F_4 ( ( L_22 ) ) ;
F_28 ( V_44 ) ;
F_29 ( V_44 ) ;
F_4 ( ( L_23 ) ) ;
V_47 = V_44 -> V_47 ;
if ( V_44 -> V_3 >= 0 )
F_31 ( V_44 ) ;
F_30 ( V_47 ) ;
F_4 ( ( L_24 ) ) ;
}
void
F_39 ( struct V_43 * V_44 )
{
if ( ! V_44 -> V_60 -> V_87 )
return;
if ( F_23 ( V_44 -> V_56 ) && ! F_40 ( V_44 -> V_56 ) &&
V_44 -> V_59 ) {
F_4 ( ( L_25 ) ) ;
while ( F_41 ( V_44 -> V_59 ) )
;
}
}
void
F_38 ( struct V_43 * V_44 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_44 -> V_88 ; V_42 ++ )
F_42 ( V_44 , V_42 ) ;
if ( V_44 -> V_55 != V_62 ) {
for ( V_42 = 0 ; V_42 < V_44 -> V_53 ; V_42 ++ )
F_43 ( V_44 , V_42 ) ;
}
if ( V_44 -> V_57 )
F_44 ( V_44 -> V_57 ) ;
if ( V_44 -> V_59 )
F_45 ( V_44 -> V_59 ) ;
F_46 ( V_44 -> V_60 ) ;
}
char *
F_47 ( int bool )
{
return bool ? L_26 : L_27 ;
}
static char *
F_48 ( int V_89 )
{
static char * V_90 [] = {
L_28 , L_29 , L_30 , L_31 ,
} ;
return V_90 [ V_89 & V_91 ] ;
}
void
F_49 ( struct V_92 * V_93 )
{
int V_42 ;
struct V_43 * V_44 ;
F_50 ( V_93 , L_32 , V_10 ) ;
F_50 ( V_93 , L_33 , V_20 ) ;
F_50 ( V_93 , L_34 , V_64 ) ;
for ( V_42 = 0 ; V_42 < V_64 ; V_42 ++ ) {
F_50 ( V_93 , L_35 , V_42 ) ;
if ( ( V_44 = V_49 [ V_42 ] ) == NULL ) {
F_50 ( V_93 , L_36 ) ;
continue;
}
F_50 ( V_93 , L_37 , V_44 -> V_3 , V_44 -> V_47 ) ;
F_50 ( V_93 , L_38 ,
( V_44 -> V_55 ? L_39 : L_40 ) ,
F_48 ( V_44 -> V_56 ) ) ;
if ( V_44 -> V_55 )
F_50 ( V_93 , L_41 ,
V_44 -> V_60 -> V_94 , V_44 -> V_60 -> V_95 ) ;
F_50 ( V_93 , L_42 , V_58 ) ;
if ( F_21 ( V_44 -> V_56 ) && V_44 -> V_57 )
F_51 ( V_44 -> V_57 , V_93 ) ;
}
}
