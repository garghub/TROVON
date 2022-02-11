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
F_6 ( ( L_2 , V_4 ) ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
strcpy ( V_6 -> V_13 , L_3 ) ;
V_6 -> V_14 . V_15 = V_3 ;
V_6 -> V_16 = V_17 ;
V_6 -> type = 0 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_18 = V_19 ;
V_6 -> V_20 = & V_8 ;
F_7 ( V_21 , V_6 ) ;
if ( ( V_22 = V_6 -> V_14 . V_6 ) >= 0 ) {
struct V_23 V_24 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_25 . V_15 = V_26 ;
V_24 . V_25 . V_6 = V_27 ;
V_24 . V_28 . V_15 = V_3 ;
V_24 . V_28 . V_6 = V_22 ;
F_7 ( V_29 , & V_24 ) ;
}
V_4 = 0 ;
F_8 ( & V_30 ) ;
V_11:
F_9 ( V_6 ) ;
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
if ( F_7 ( V_41 , & V_37 ) >= 0 )
F_10 ( & V_37 ) ;
break;
case V_42 :
if ( V_32 -> V_40 . V_14 . V_15 == V_3 )
break;
F_11 ( V_32 -> V_40 . V_14 . V_15 ,
V_32 -> V_40 . V_14 . V_6 ) ;
break;
}
return 0 ;
}
int
F_12 ( void )
{
F_13 ( & V_30 ) ;
if ( V_3 >= 0 )
F_14 ( V_3 ) ;
F_15 () ;
return 0 ;
}
int
F_16 ( struct V_43 * V_43 , int V_44 )
{
int V_45 , V_4 ;
struct V_46 * V_47 ;
V_47 = F_17 ( sizeof( * V_47 ) , V_9 ) ;
if ( ! V_47 ) {
F_18 ( V_48 L_4 ) ;
return - V_10 ;
}
F_6 ( ( L_5 , V_47 ) ) ;
V_47 -> V_49 = V_3 ;
V_47 -> V_6 = - 1 ;
V_47 -> V_50 = - 1 ;
for ( V_45 = 0 ; V_45 < V_51 ; V_45 ++ ) {
if ( V_52 [ V_45 ] == NULL )
break;
}
V_47 -> V_53 = V_45 ;
if ( V_45 >= V_51 ) {
F_18 ( V_48 L_6 ) ;
V_4 = - V_10 ;
goto V_54;
}
F_19 ( V_47 ) ;
F_20 ( V_47 ) ;
if ( V_47 -> V_55 == 0 && V_47 -> V_56 == 0 ) {
V_4 = - V_57 ;
goto V_54;
}
F_6 ( ( L_7 ) ) ;
V_4 = F_21 ( V_47 ) ;
if ( V_4 < 0 ) {
F_18 ( V_48 L_8 ) ;
goto V_54;
}
F_6 ( ( L_9 ) ) ;
V_4 = F_22 ( V_47 ) ;
if ( V_4 < 0 )
goto V_54;
V_47 -> V_14 . V_15 = V_47 -> V_49 ;
V_47 -> V_14 . V_6 = V_47 -> V_6 ;
V_47 -> V_58 = V_44 ;
V_47 -> V_59 = F_23 ( V_43 ) ;
F_6 ( ( L_10 ) ) ;
if ( F_24 ( V_47 -> V_59 ) ) {
V_47 -> V_60 = F_25 ( V_47 , V_61 ) ;
if ( ! V_47 -> V_60 ) {
V_4 = - V_10 ;
goto V_54;
}
}
F_6 ( ( L_11 ) ) ;
if ( F_26 ( V_47 -> V_59 ) ) {
V_47 -> V_62 = F_27 ( V_47 , V_61 ) ;
if ( ! V_47 -> V_62 ) {
V_4 = - V_10 ;
goto V_54;
}
}
F_6 ( ( L_12 ) ) ;
V_47 -> V_63 = F_28 ( V_47 ) ;
if ( ! V_47 -> V_63 ) {
F_18 ( V_48 L_13 ) ;
V_4 = - V_10 ;
goto V_54;
}
F_6 ( ( L_14 ) ) ;
V_43 -> V_64 = V_47 ;
if ( V_44 == V_65 )
F_29 ( V_47 ) ;
else if ( F_24 ( V_47 -> V_59 ) )
F_30 ( V_47 , V_66 ) ;
V_52 [ V_47 -> V_53 ] = V_47 ;
V_67 ++ ;
F_6 ( ( L_15 ) ) ;
return 0 ;
V_54:
F_31 ( V_47 ) ;
F_32 ( V_47 ) ;
F_33 ( V_47 -> V_50 ) ;
F_34 ( V_47 ) ;
return V_4 ;
}
static int
F_23 ( struct V_43 * V_43 )
{
int V_59 = 0 ;
if ( ( V_43 -> V_68 & V_69 ) != V_70 )
V_59 |= V_71 ;
if ( ( V_43 -> V_68 & V_69 ) != V_72 )
V_59 |= V_66 ;
if ( V_43 -> V_68 & V_73 )
V_59 |= V_74 ;
return V_59 ;
}
static int
F_21 ( struct V_46 * V_47 )
{
int V_4 ;
struct V_5 V_6 ;
struct V_7 V_75 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_14 . V_15 = V_47 -> V_49 ;
sprintf ( V_6 . V_13 , L_16 , V_47 -> V_53 ) ;
V_6 . V_16 = V_76 | V_17 ;
V_6 . type = V_77 ;
V_6 . V_78 = 128 ;
V_6 . V_79 = 128 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_80 = V_81 ;
V_75 . V_64 = V_47 ;
V_75 . V_18 = V_82 ;
V_75 . V_83 = V_84 ;
V_6 . V_20 = & V_75 ;
V_4 = F_7 ( V_21 , & V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
V_47 -> V_6 = V_6 . V_14 . V_6 ;
F_6 ( ( L_17 , V_6 . V_14 . V_6 ) ) ;
return 0 ;
}
static int
F_34 ( struct V_46 * V_47 )
{
if ( V_47 -> V_6 < 0 ) {
F_9 ( V_47 ) ;
return 0 ;
}
F_6 ( ( L_18 , V_47 -> V_6 ) ) ;
return F_35 ( V_47 -> V_49 , V_47 -> V_6 ) ;
}
static int
F_22 ( struct V_46 * V_47 )
{
struct V_85 V_86 ;
int V_4 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_80 = V_3 ;
V_86 . V_87 = 1 ;
strcpy ( V_86 . V_13 , L_19 ) ;
if ( ( V_4 = F_7 ( V_88 , & V_86 ) ) < 0 )
return V_4 ;
V_47 -> V_50 = V_86 . V_50 ;
return 0 ;
}
static int
F_33 ( int V_50 )
{
struct V_85 V_86 ;
int V_4 ;
if ( V_50 < 0 )
return 0 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_50 = V_50 ;
V_4 = F_7 ( V_89 , & V_86 ) ;
if ( V_4 < 0 )
F_36 ( V_48 L_20 , V_50 , V_4 ) ;
return V_4 ;
}
static void
V_84 ( void * V_34 )
{
struct V_46 * V_47 = (struct V_46 * ) V_34 ;
if ( V_47 -> V_63 )
F_37 ( V_47 -> V_63 ) ;
if ( V_47 -> V_62 )
F_38 ( V_47 -> V_62 ) ;
if ( V_47 -> V_60 )
F_39 ( V_47 -> V_60 ) ;
F_9 ( V_47 ) ;
}
void
F_40 ( struct V_46 * V_47 )
{
int V_50 ;
V_52 [ V_47 -> V_53 ] = NULL ;
V_67 -- ;
F_6 ( ( L_21 ) ) ;
F_41 ( V_47 ) ;
F_6 ( ( L_22 ) ) ;
F_31 ( V_47 ) ;
F_32 ( V_47 ) ;
F_6 ( ( L_23 ) ) ;
V_50 = V_47 -> V_50 ;
if ( V_47 -> V_6 >= 0 )
F_34 ( V_47 ) ;
F_33 ( V_50 ) ;
F_6 ( ( L_24 ) ) ;
}
void
F_42 ( struct V_46 * V_47 )
{
if ( ! V_47 -> V_63 -> V_90 )
return;
if ( F_26 ( V_47 -> V_59 ) && ! F_43 ( V_47 -> V_59 ) &&
V_47 -> V_62 ) {
F_6 ( ( L_25 ) ) ;
while ( F_44 ( V_47 -> V_62 ) )
;
}
}
void
F_41 ( struct V_46 * V_47 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_47 -> V_91 ; V_45 ++ )
F_45 ( V_47 , V_45 ) ;
if ( V_47 -> V_58 != V_65 ) {
for ( V_45 = 0 ; V_45 < V_47 -> V_56 ; V_45 ++ )
F_46 ( V_47 , V_45 ) ;
}
if ( V_47 -> V_60 )
F_47 ( V_47 -> V_60 ) ;
if ( V_47 -> V_62 )
F_48 ( V_47 -> V_62 ) ;
F_49 ( V_47 -> V_63 ) ;
}
char *
F_50 ( int bool )
{
return bool ? L_26 : L_27 ;
}
static char *
F_51 ( int V_92 )
{
static char * V_93 [] = {
L_28 , L_29 , L_30 , L_31 ,
} ;
return V_93 [ V_92 & V_94 ] ;
}
void
F_52 ( struct V_95 * V_96 )
{
int V_45 ;
struct V_46 * V_47 ;
F_53 ( V_96 , L_32 , V_3 ) ;
F_53 ( V_96 , L_33 , V_22 ) ;
F_53 ( V_96 , L_34 , V_67 ) ;
for ( V_45 = 0 ; V_45 < V_67 ; V_45 ++ ) {
F_53 ( V_96 , L_35 , V_45 ) ;
if ( ( V_47 = V_52 [ V_45 ] ) == NULL ) {
F_53 ( V_96 , L_36 ) ;
continue;
}
F_53 ( V_96 , L_37 , V_47 -> V_6 , V_47 -> V_50 ) ;
F_53 ( V_96 , L_38 ,
( V_47 -> V_58 ? L_39 : L_40 ) ,
F_51 ( V_47 -> V_59 ) ) ;
if ( V_47 -> V_58 )
F_53 ( V_96 , L_41 ,
V_47 -> V_63 -> V_97 , V_47 -> V_63 -> V_98 ) ;
F_53 ( V_96 , L_42 , V_61 ) ;
if ( F_24 ( V_47 -> V_59 ) && V_47 -> V_60 )
F_54 ( V_47 -> V_60 , V_96 ) ;
}
}
