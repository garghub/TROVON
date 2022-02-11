static union V_1 * F_1 ( int V_2 )
{
int V_3 = 0 , V_4 ;
union V_1 * V_5 = NULL , * V_6 ;
char * V_7 ;
V_4 = F_2 ( & V_7 ) ;
V_6 = (union V_1 * ) V_7 ;
if ( memcmp ( V_6 -> V_8 . V_9 , L_1 , 4 ) != 0 )
goto V_10;
V_6 = (union V_1 * ) & V_7 [ V_3 += V_6 -> V_8 . V_11 ] ;
while ( V_3 < V_4 && ( V_6 -> V_12 . type != 0x82 ||
V_6 -> V_13 . V_14 != V_2 ) ) {
V_6 = (union V_1 * ) & V_7 [ V_3 += V_6 -> V_12 . V_11 ] ;
}
if ( V_3 < V_4 && V_6 -> V_13 . V_14 == V_2 )
V_5 = V_6 ;
V_10:
if ( V_5 ) {
V_5 = F_3 ( sizeof( union V_1 ) , V_15 ) ;
memcpy ( V_5 , V_6 , sizeof( union V_1 ) ) ;
}
F_4 ( V_7 ) ;
return V_5 ;
}
static int F_5 ( struct V_16 * V_13 , T_1 V_17 )
{
union V_18 args [ 2 ] ;
struct V_19 V_20 = { . V_21 = args , . V_22 = 2 } ;
T_2 V_23 ;
unsigned long long V_24 ;
union V_1 * V_25 ;
V_25 = F_1 ( F_6 ( V_13 ) ) ;
F_7 ( L_2 , V_26 ,
V_25 -> V_13 . V_14 , V_25 -> V_13 . V_27 ,
( V_17 ? 1 : 0 ) ) ;
args [ 0 ] . type = V_28 ;
args [ 0 ] . integer . V_29 = V_25 -> V_13 . V_27 ;
args [ 1 ] . type = V_28 ;
args [ 1 ] . integer . V_29 = ( V_17 ) ? 1 : 0 ;
F_4 ( V_25 ) ;
V_23 = F_8 ( V_30 , L_3 , & V_20 , & V_24 ) ;
if ( F_9 ( V_23 ) ) {
F_10 ( L_4 , V_23 ) ;
return - V_31 ;
} else if ( ! V_24 ) {
F_10 ( L_5 , V_24 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_11 ( struct V_16 * V_13 , T_1 * V_17 )
{
union V_1 * V_25 ;
V_25 = F_1 ( F_6 ( V_13 ) ) ;
if ( V_25 -> V_13 . V_33 & 0xa0 || V_25 -> V_13 . V_17 [ 1 ] & 0x08 )
* V_17 = 1 ;
else
* V_17 = 0 ;
F_7 ( L_6 , V_26 ,
V_25 -> V_13 . V_14 , V_25 -> V_13 . V_27 ,
* V_17 ) ;
F_4 ( V_25 ) ;
return 0 ;
}
static void F_12 ( T_3 V_34 , T_4 V_35 , void * V_36 )
{
T_1 V_37 = V_35 & 0x0f ;
T_1 V_38 = V_35 & 0xf0 ;
struct V_39 * V_40 = V_36 ;
F_7 ( L_7 , V_26 , V_35 ) ;
if ( V_38 == 0x80 ) {
F_7 ( L_8 , V_26 ) ;
F_13 ( V_40 -> V_41 -> V_42 . V_43 ,
F_14 ( & V_40 -> V_41 -> V_44 ) ,
V_40 -> V_35 , V_37 ) ;
} else
V_40 -> V_35 = V_35 ;
}
static int F_2 ( char * * V_45 )
{
union V_18 * V_46 ;
struct V_47 V_48 = { V_49 , NULL } ;
T_2 V_17 ;
char * V_50 = NULL ;
int V_51 , V_4 = - V_52 ;
V_17 = F_15 ( V_30 , L_9 , NULL , & V_48 ) ;
if ( F_9 ( V_17 ) ) {
F_10 ( L_10 , V_26 ) ;
return - V_31 ;
}
V_46 = (union V_18 * ) V_48 . V_21 ;
if ( ! ( V_46 ) ||
( V_46 -> type != V_53 ) ||
! ( V_46 -> V_46 . V_54 ) ) {
F_10 ( L_11 , V_26 ) ;
goto V_55;
}
for( V_4 = 0 , V_51 = 0 ; V_51 < V_46 -> V_46 . V_22 ; V_51 ++ ) {
if ( V_46 -> V_46 . V_54 [ V_51 ] . type != V_56 ) {
F_10 ( L_12 , V_26 , V_51 ) ;
goto V_55;
}
V_4 += V_46 -> V_46 . V_54 [ V_51 ] . V_48 . V_57 ;
}
if ( V_45 == NULL )
goto V_55;
V_50 = F_16 ( V_4 , V_15 ) ;
F_7 ( L_13 ,
V_26 , V_46 -> V_46 . V_22 , V_4 , V_50 ) ;
if ( V_50 ) {
* V_45 = V_50 ;
} else {
V_4 = - V_58 ;
goto V_55;
}
V_4 = 0 ;
for ( V_51 = 0 ; V_51 < V_46 -> V_46 . V_22 ; V_51 ++ ) {
memcpy ( & V_50 [ V_4 ] ,
V_46 -> V_46 . V_54 [ V_51 ] . V_48 . V_21 ,
V_46 -> V_46 . V_54 [ V_51 ] . V_48 . V_57 ) ;
V_4 += V_46 -> V_46 . V_54 [ V_51 ] . V_48 . V_57 ;
}
V_55:
F_4 ( V_48 . V_21 ) ;
return V_4 ;
}
static T_5 F_17 ( struct V_59 * V_60 , struct V_61 * V_62 ,
struct V_63 * V_64 ,
char * V_48 , T_6 V_65 , T_7 V_4 )
{
int V_66 = - V_67 ;
char * V_7 = NULL ;
F_7 ( L_14 , V_26 , ( int ) V_65 , V_4 ) ;
if ( V_65 == 0 ) {
V_66 = F_2 ( & V_7 ) ;
if ( V_66 > 0 && V_66 <= V_4 )
memcpy ( V_48 , V_7 , V_66 ) ;
F_4 ( V_7 ) ;
}
return V_66 ;
}
static T_2 T_8 F_18 ( T_3 V_34 ,
T_4 V_68 , void * V_36 , void * * V_69 )
{
T_3 * V_70 = ( T_3 * ) V_36 ;
T_2 V_17 ;
struct V_71 * V_72 ;
int V_73 = 0 ;
V_17 = F_19 ( V_34 , & V_72 ) ;
if ( F_9 ( V_17 ) ) {
F_10 ( L_15 ,
V_26 , V_17 ) ;
return V_73 ;
}
if ( V_72 -> V_74 && ( V_72 -> V_75 & V_76 ) &&
( ! strcmp ( V_72 -> V_77 . string , V_78 ) ||
! strcmp ( V_72 -> V_77 . string , V_79 ) ) ) {
F_7 ( L_16 ,
V_72 -> V_77 . string , V_34 ) ;
* V_70 = V_34 ;
V_73 = V_80 ;
}
F_4 ( V_72 ) ;
return V_73 ;
}
static int T_8 F_20 ( void )
{
int V_73 = 0 ;
T_2 V_17 ;
struct V_81 * V_41 ;
struct V_61 * V_82 = & V_83 -> V_62 ;
F_7 ( L_17 , V_26 ) ;
if ( F_21 ( V_84 , V_85 ,
V_86 , F_18 , NULL ,
& V_30 , NULL ) != V_80 ) {
F_10 ( L_18 , V_26 ) ;
V_73 = - V_31 ;
goto V_87;
}
F_7 ( L_19 , V_26 ) ;
if ( F_22 ( V_30 , & V_41 ) ) {
F_10 ( L_20 , V_26 ) ;
V_73 = - V_31 ;
goto V_87;
}
if ( F_23 ( & V_88 ) ) {
V_73 = - V_31 ;
goto V_87;
}
V_89 . V_41 = V_41 ;
V_17 = F_24 ( V_30 ,
V_90 , F_12 ,
& V_89 ) ;
if ( F_9 ( V_17 ) ) {
F_10 ( L_21 ,
V_26 ) ;
V_73 = - V_91 ;
goto V_92;
}
V_93 . V_4 = F_2 ( NULL ) ;
V_73 = F_25 ( V_82 , & V_93 ) ;
return V_73 ;
V_92:
F_26 ( & V_88 ) ;
V_87:
return V_73 ;
}
static void T_9 F_27 ( void )
{
T_2 V_17 ;
struct V_61 * V_82 = & V_83 -> V_62 ;
F_7 ( L_17 , V_26 ) ;
if ( F_26 ( & V_88 ) )
F_10 ( L_22 , V_26 ) ;
V_17 = F_28 (
V_30 ,
V_90 ,
F_12 ) ;
if ( F_9 ( V_17 ) )
F_10 ( L_23 , V_26 ) ;
F_29 ( V_82 , & V_93 ) ;
}
