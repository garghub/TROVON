static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ) ;
}
int T_1
F_3 ( void )
{
int V_4 ;
struct V_5 * V_6 ;
struct V_7 V_8 ;
V_6 = F_4 ( sizeof( * V_6 ) , V_9 ) ;
if ( ! V_6 ) {
V_4 = - V_10 ;
goto V_11;
}
V_4 = F_5 ( NULL , V_12 ,
L_1 ) ;
if ( V_4 < 0 )
goto V_11;
V_3 = V_4 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
strcpy ( V_6 -> V_13 , L_2 ) ;
V_6 -> V_14 . V_15 = V_3 ;
V_6 -> V_16 = V_17 ;
V_6 -> type = 0 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_18 = V_19 ;
V_6 -> V_20 = & V_8 ;
F_6 ( V_21 , V_6 ) ;
if ( ( V_22 = V_6 -> V_14 . V_6 ) >= 0 ) {
struct V_23 V_24 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_25 . V_15 = V_26 ;
V_24 . V_25 . V_6 = V_27 ;
V_24 . V_28 . V_15 = V_3 ;
V_24 . V_28 . V_6 = V_22 ;
F_6 ( V_29 , & V_24 ) ;
}
V_4 = 0 ;
F_7 ( & V_30 ) ;
V_11:
F_8 ( V_6 ) ;
return V_4 ;
}
static int
V_19 ( struct V_31 * V_32 , int V_33 , void * V_34 , int V_35 , int V_36 )
{
struct V_5 V_37 ;
if ( V_35 )
return 0 ;
switch ( V_32 -> type ) {
case V_38 :
case V_39 :
if ( V_32 -> V_40 . V_14 . V_15 == V_3 )
break;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_14 = V_32 -> V_40 . V_14 ;
if ( F_6 ( V_41 , & V_37 ) >= 0 )
F_9 ( & V_37 ) ;
break;
case V_42 :
if ( V_32 -> V_40 . V_14 . V_15 == V_3 )
break;
F_10 ( V_32 -> V_40 . V_14 . V_15 ,
V_32 -> V_40 . V_14 . V_6 ) ;
break;
}
return 0 ;
}
int
F_11 ( void )
{
F_12 ( & V_30 ) ;
if ( V_3 >= 0 )
F_13 ( V_3 ) ;
F_14 () ;
return 0 ;
}
int
F_15 ( struct V_43 * V_43 , int V_44 )
{
int V_45 , V_4 ;
struct V_46 * V_47 ;
V_47 = F_16 ( sizeof( * V_47 ) , V_9 ) ;
if ( ! V_47 ) {
F_17 ( L_3 ) ;
return - V_10 ;
}
V_47 -> V_48 = V_3 ;
V_47 -> V_6 = - 1 ;
V_47 -> V_49 = - 1 ;
for ( V_45 = 0 ; V_45 < V_50 ; V_45 ++ ) {
if ( V_51 [ V_45 ] == NULL )
break;
}
V_47 -> V_52 = V_45 ;
if ( V_45 >= V_50 ) {
F_17 ( L_4 ) ;
V_4 = - V_10 ;
goto V_53;
}
F_18 ( V_47 ) ;
F_19 ( V_47 ) ;
if ( V_47 -> V_54 == 0 && V_47 -> V_55 == 0 ) {
V_4 = - V_56 ;
goto V_53;
}
V_4 = F_20 ( V_47 ) ;
if ( V_4 < 0 ) {
F_17 ( L_5 ) ;
goto V_53;
}
V_4 = F_21 ( V_47 ) ;
if ( V_4 < 0 )
goto V_53;
V_47 -> V_14 . V_15 = V_47 -> V_48 ;
V_47 -> V_14 . V_6 = V_47 -> V_6 ;
V_47 -> V_57 = V_44 ;
V_47 -> V_58 = F_22 ( V_43 ) ;
if ( F_23 ( V_47 -> V_58 ) ) {
V_47 -> V_59 = F_24 ( V_47 , V_60 ) ;
if ( ! V_47 -> V_59 ) {
V_4 = - V_10 ;
goto V_53;
}
}
if ( F_25 ( V_47 -> V_58 ) ) {
V_47 -> V_61 = F_26 ( V_47 , V_60 ) ;
if ( ! V_47 -> V_61 ) {
V_4 = - V_10 ;
goto V_53;
}
}
V_47 -> V_62 = F_27 ( V_47 ) ;
if ( ! V_47 -> V_62 ) {
F_17 ( L_6 ) ;
V_4 = - V_10 ;
goto V_53;
}
V_43 -> V_63 = V_47 ;
if ( V_44 == V_64 )
F_28 ( V_47 ) ;
else if ( F_23 ( V_47 -> V_58 ) )
F_29 ( V_47 , V_65 ) ;
V_51 [ V_47 -> V_52 ] = V_47 ;
V_66 ++ ;
return 0 ;
V_53:
F_30 ( V_47 ) ;
F_31 ( V_47 ) ;
F_32 ( V_47 -> V_49 ) ;
F_33 ( V_47 ) ;
return V_4 ;
}
static int
F_22 ( struct V_43 * V_43 )
{
int V_58 = 0 ;
if ( ( V_43 -> V_67 & V_68 ) != V_69 )
V_58 |= V_70 ;
if ( ( V_43 -> V_67 & V_68 ) != V_71 )
V_58 |= V_65 ;
if ( V_43 -> V_67 & V_72 )
V_58 |= V_73 ;
return V_58 ;
}
static int
F_20 ( struct V_46 * V_47 )
{
int V_4 ;
struct V_5 V_6 ;
struct V_7 V_74 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_14 . V_15 = V_47 -> V_48 ;
sprintf ( V_6 . V_13 , L_7 , V_47 -> V_52 ) ;
V_6 . V_16 = V_75 | V_17 ;
V_6 . type = V_76 ;
V_6 . V_77 = 128 ;
V_6 . V_78 = 128 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_79 = V_80 ;
V_74 . V_63 = V_47 ;
V_74 . V_18 = V_81 ;
V_74 . V_82 = V_83 ;
V_6 . V_20 = & V_74 ;
V_4 = F_6 ( V_21 , & V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
V_47 -> V_6 = V_6 . V_14 . V_6 ;
return 0 ;
}
static int
F_33 ( struct V_46 * V_47 )
{
if ( V_47 -> V_6 < 0 ) {
F_8 ( V_47 ) ;
return 0 ;
}
return F_34 ( V_47 -> V_48 , V_47 -> V_6 ) ;
}
static int
F_21 ( struct V_46 * V_47 )
{
struct V_84 V_85 ;
int V_4 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . V_79 = V_3 ;
V_85 . V_86 = 1 ;
strcpy ( V_85 . V_13 , L_8 ) ;
if ( ( V_4 = F_6 ( V_87 , & V_85 ) ) < 0 )
return V_4 ;
V_47 -> V_49 = V_85 . V_49 ;
return 0 ;
}
static int
F_32 ( int V_49 )
{
struct V_84 V_85 ;
int V_4 ;
if ( V_49 < 0 )
return 0 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . V_49 = V_49 ;
V_4 = F_6 ( V_88 , & V_85 ) ;
if ( V_4 < 0 )
F_17 ( L_9 , V_49 , V_4 ) ;
return V_4 ;
}
static void
V_83 ( void * V_34 )
{
struct V_46 * V_47 = (struct V_46 * ) V_34 ;
F_35 ( V_47 -> V_62 ) ;
F_36 ( V_47 -> V_61 ) ;
F_37 ( V_47 -> V_59 ) ;
F_8 ( V_47 ) ;
}
void
F_38 ( struct V_46 * V_47 )
{
int V_49 ;
V_51 [ V_47 -> V_52 ] = NULL ;
V_66 -- ;
F_39 ( V_47 ) ;
F_30 ( V_47 ) ;
F_31 ( V_47 ) ;
V_49 = V_47 -> V_49 ;
if ( V_47 -> V_6 >= 0 )
F_33 ( V_47 ) ;
F_32 ( V_49 ) ;
}
void
F_40 ( struct V_46 * V_47 )
{
if ( ! V_47 -> V_62 -> V_89 )
return;
if ( F_25 ( V_47 -> V_58 ) && ! F_41 ( V_47 -> V_58 ) &&
V_47 -> V_61 ) {
while ( F_42 ( V_47 -> V_61 ) )
;
}
}
void
F_39 ( struct V_46 * V_47 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_47 -> V_90 ; V_45 ++ )
F_43 ( V_47 , V_45 ) ;
if ( V_47 -> V_57 != V_64 ) {
for ( V_45 = 0 ; V_45 < V_47 -> V_55 ; V_45 ++ )
F_44 ( V_47 , V_45 ) ;
}
if ( V_47 -> V_59 )
F_45 ( V_47 -> V_59 ) ;
if ( V_47 -> V_61 )
F_46 ( V_47 -> V_61 ) ;
F_47 ( V_47 -> V_62 ) ;
}
char *
F_48 ( int bool )
{
return bool ? L_10 : L_11 ;
}
static char *
F_49 ( int V_91 )
{
static char * V_92 [] = {
L_12 , L_13 , L_14 , L_15 ,
} ;
return V_92 [ V_91 & V_93 ] ;
}
void
F_50 ( struct V_94 * V_95 )
{
int V_45 ;
struct V_46 * V_47 ;
F_51 ( V_95 , L_16 , V_3 ) ;
F_51 ( V_95 , L_17 , V_22 ) ;
F_51 ( V_95 , L_18 , V_66 ) ;
for ( V_45 = 0 ; V_45 < V_66 ; V_45 ++ ) {
F_51 ( V_95 , L_19 , V_45 ) ;
if ( ( V_47 = V_51 [ V_45 ] ) == NULL ) {
F_51 ( V_95 , L_20 ) ;
continue;
}
F_51 ( V_95 , L_21 , V_47 -> V_6 , V_47 -> V_49 ) ;
F_51 ( V_95 , L_22 ,
( V_47 -> V_57 ? L_23 : L_24 ) ,
F_49 ( V_47 -> V_58 ) ) ;
if ( V_47 -> V_57 )
F_51 ( V_95 , L_25 ,
V_47 -> V_62 -> V_96 , V_47 -> V_62 -> V_97 ) ;
F_51 ( V_95 , L_26 , V_60 ) ;
if ( F_23 ( V_47 -> V_58 ) && V_47 -> V_59 )
F_52 ( V_47 -> V_59 , V_95 ) ;
}
}
