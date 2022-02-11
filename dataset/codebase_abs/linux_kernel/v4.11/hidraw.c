static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
int V_8 = 0 , V_9 ;
F_2 ( V_10 , V_11 ) ;
F_3 ( & V_6 -> V_12 ) ;
while ( V_8 == 0 ) {
if ( V_6 -> V_13 == V_6 -> V_14 ) {
F_4 ( & V_6 -> V_15 -> V_10 , & V_10 ) ;
F_5 ( V_16 ) ;
while ( V_6 -> V_13 == V_6 -> V_14 ) {
if ( F_6 ( V_11 ) ) {
V_8 = - V_17 ;
break;
}
if ( ! V_6 -> V_15 -> V_18 ) {
V_8 = - V_19 ;
break;
}
if ( V_1 -> V_20 & V_21 ) {
V_8 = - V_22 ;
break;
}
F_7 ( & V_6 -> V_12 ) ;
F_8 () ;
F_3 ( & V_6 -> V_12 ) ;
F_5 ( V_16 ) ;
}
F_5 ( V_23 ) ;
F_9 ( & V_6 -> V_15 -> V_10 , & V_10 ) ;
}
if ( V_8 )
goto V_24;
V_9 = V_6 -> V_2 [ V_6 -> V_14 ] . V_9 > V_3 ?
V_3 : V_6 -> V_2 [ V_6 -> V_14 ] . V_9 ;
if ( V_6 -> V_2 [ V_6 -> V_14 ] . V_25 ) {
if ( F_10 ( V_2 , V_6 -> V_2 [ V_6 -> V_14 ] . V_25 , V_9 ) ) {
V_8 = - V_26 ;
goto V_24;
}
V_8 = V_9 ;
}
F_11 ( V_6 -> V_2 [ V_6 -> V_14 ] . V_25 ) ;
V_6 -> V_2 [ V_6 -> V_14 ] . V_25 = NULL ;
V_6 -> V_14 = ( V_6 -> V_14 + 1 ) & ( V_27 - 1 ) ;
}
V_24:
F_7 ( & V_6 -> V_12 ) ;
return V_8 ;
}
static T_1 F_12 ( struct V_1 * V_1 , const char T_2 * V_2 , T_3 V_3 , unsigned char V_28 )
{
unsigned int V_29 = F_13 ( F_14 ( V_1 ) ) ;
struct V_30 * V_31 ;
T_5 * V_32 ;
int V_8 = 0 ;
if ( ! V_33 [ V_29 ] || ! V_33 [ V_29 ] -> V_18 ) {
V_8 = - V_34 ;
goto V_24;
}
V_31 = V_33 [ V_29 ] -> V_35 ;
if ( V_3 > V_36 ) {
F_15 ( V_31 , L_1 ,
F_16 ( V_11 ) ) ;
V_8 = - V_37 ;
goto V_24;
}
if ( V_3 < 2 ) {
F_15 ( V_31 , L_2 ,
F_16 ( V_11 ) ) ;
V_8 = - V_37 ;
goto V_24;
}
V_32 = F_17 ( V_2 , V_3 ) ;
if ( F_18 ( V_32 ) ) {
V_8 = F_19 ( V_32 ) ;
goto V_24;
}
if ( ( V_28 == V_38 ) &&
! ( V_31 -> V_39 & V_40 ) ) {
V_8 = F_20 ( V_31 , V_32 , V_3 ) ;
if ( V_8 != - V_41 )
goto V_42;
}
V_8 = F_21 ( V_31 , V_32 [ 0 ] , V_32 , V_3 , V_28 ,
V_43 ) ;
V_42:
F_11 ( V_32 ) ;
V_24:
return V_8 ;
}
static T_1 F_22 ( struct V_1 * V_1 , const char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
T_1 V_8 ;
F_3 ( & V_44 ) ;
V_8 = F_12 ( V_1 , V_2 , V_3 , V_38 ) ;
F_7 ( & V_44 ) ;
return V_8 ;
}
static T_1 F_23 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , unsigned char V_28 )
{
unsigned int V_29 = F_13 ( F_14 ( V_1 ) ) ;
struct V_30 * V_31 ;
T_5 * V_32 ;
int V_8 = 0 , V_9 ;
unsigned char V_45 ;
V_31 = V_33 [ V_29 ] -> V_35 ;
if ( ! V_31 -> V_46 -> V_47 ) {
V_8 = - V_34 ;
goto V_24;
}
if ( V_3 > V_36 ) {
F_24 ( V_48 L_3 ,
F_16 ( V_11 ) ) ;
V_8 = - V_37 ;
goto V_24;
}
if ( V_3 < 2 ) {
F_24 ( V_48 L_4 ,
F_16 ( V_11 ) ) ;
V_8 = - V_37 ;
goto V_24;
}
V_32 = F_25 ( V_3 * sizeof( T_5 ) , V_49 ) ;
if ( ! V_32 ) {
V_8 = - V_50 ;
goto V_24;
}
if ( F_26 ( & V_45 , V_2 , 1 ) ) {
V_8 = - V_26 ;
goto V_42;
}
V_8 = F_21 ( V_31 , V_45 , V_32 , V_3 , V_28 ,
V_51 ) ;
if ( V_8 < 0 )
goto V_42;
V_9 = ( V_8 < V_3 ) ? V_8 : V_3 ;
if ( F_10 ( V_2 , V_32 , V_9 ) ) {
V_8 = - V_26 ;
goto V_42;
}
V_8 = V_9 ;
V_42:
F_11 ( V_32 ) ;
V_24:
return V_8 ;
}
static unsigned int F_27 ( struct V_1 * V_1 , T_6 * V_10 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
F_28 ( V_1 , & V_6 -> V_15 -> V_10 , V_10 ) ;
if ( V_6 -> V_13 != V_6 -> V_14 )
return V_52 | V_53 ;
if ( ! V_6 -> V_15 -> V_18 )
return V_54 | V_55 ;
return 0 ;
}
static int F_29 ( struct V_56 * V_56 , struct V_1 * V_1 )
{
unsigned int V_29 = F_13 ( V_56 ) ;
struct V_15 * V_31 ;
struct V_5 * V_6 ;
unsigned long V_57 ;
int V_58 = 0 ;
if ( ! ( V_6 = F_30 ( sizeof( struct V_5 ) , V_49 ) ) ) {
V_58 = - V_50 ;
goto V_24;
}
F_3 ( & V_44 ) ;
if ( ! V_33 [ V_29 ] || ! V_33 [ V_29 ] -> V_18 ) {
V_58 = - V_34 ;
goto V_59;
}
V_31 = V_33 [ V_29 ] ;
if ( ! V_31 -> V_60 ++ ) {
V_58 = F_31 ( V_31 -> V_35 , V_61 ) ;
if ( V_58 < 0 ) {
V_31 -> V_60 -- ;
goto V_59;
}
V_58 = F_32 ( V_31 -> V_35 ) ;
if ( V_58 < 0 ) {
F_31 ( V_31 -> V_35 , V_62 ) ;
V_31 -> V_60 -- ;
goto V_59;
}
}
V_6 -> V_15 = V_33 [ V_29 ] ;
F_33 ( & V_6 -> V_12 ) ;
F_34 ( & V_33 [ V_29 ] -> V_63 , V_57 ) ;
F_35 ( & V_6 -> V_64 , & V_33 [ V_29 ] -> V_6 ) ;
F_36 ( & V_33 [ V_29 ] -> V_63 , V_57 ) ;
V_1 -> V_7 = V_6 ;
V_59:
F_7 ( & V_44 ) ;
V_24:
if ( V_58 < 0 )
F_11 ( V_6 ) ;
return V_58 ;
}
static int F_37 ( int V_65 , struct V_1 * V_1 , int V_66 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
return F_38 ( V_65 , V_1 , V_66 , & V_6 -> V_67 ) ;
}
static void F_39 ( struct V_15 * V_15 , int V_68 )
{
if ( V_68 ) {
V_15 -> V_18 = 0 ;
if ( V_15 -> V_60 ) {
F_40 ( V_15 -> V_35 ) ;
F_41 ( & V_15 -> V_10 ) ;
}
F_42 ( V_69 ,
F_43 ( V_70 , V_15 -> V_29 ) ) ;
} else {
-- V_15 -> V_60 ;
}
if ( ! V_15 -> V_60 ) {
if ( ! V_15 -> V_18 ) {
V_33 [ V_15 -> V_29 ] = NULL ;
F_11 ( V_15 ) ;
} else {
F_31 ( V_15 -> V_35 , V_62 ) ;
F_40 ( V_15 -> V_35 ) ;
}
}
}
static int F_44 ( struct V_56 * V_56 , struct V_1 * V_1 )
{
unsigned int V_29 = F_13 ( V_56 ) ;
struct V_5 * V_6 = V_1 -> V_7 ;
unsigned long V_57 ;
F_3 ( & V_44 ) ;
F_34 ( & V_33 [ V_29 ] -> V_63 , V_57 ) ;
F_45 ( & V_6 -> V_64 ) ;
F_36 ( & V_33 [ V_29 ] -> V_63 , V_57 ) ;
F_11 ( V_6 ) ;
F_39 ( V_33 [ V_29 ] , 0 ) ;
F_7 ( & V_44 ) ;
return 0 ;
}
static long F_46 ( struct V_1 * V_1 , unsigned int V_71 ,
unsigned long V_72 )
{
struct V_56 * V_56 = F_14 ( V_1 ) ;
unsigned int V_29 = F_13 ( V_56 ) ;
long V_8 = 0 ;
struct V_15 * V_31 ;
void T_2 * V_73 = ( void T_2 * ) V_72 ;
F_3 ( & V_44 ) ;
V_31 = V_33 [ V_29 ] ;
if ( ! V_31 ) {
V_8 = - V_34 ;
goto V_24;
}
switch ( V_71 ) {
case V_74 :
if ( F_47 ( V_31 -> V_35 -> V_75 , ( int T_2 * ) V_72 ) )
V_8 = - V_26 ;
break;
case V_76 :
{
T_7 V_9 ;
if ( F_48 ( V_9 , ( int T_2 * ) V_72 ) )
V_8 = - V_26 ;
else if ( V_9 > V_77 - 1 )
V_8 = - V_37 ;
else if ( F_10 ( V_73 + F_49 (
struct V_78 ,
V_25 [ 0 ] ) ,
V_31 -> V_35 -> V_79 ,
F_50 ( V_31 -> V_35 -> V_75 , V_9 ) ) )
V_8 = - V_26 ;
break;
}
case V_80 :
{
struct V_81 V_82 ;
V_82 . V_83 = V_31 -> V_35 -> V_84 ;
V_82 . V_85 = V_31 -> V_35 -> V_85 ;
V_82 . V_86 = V_31 -> V_35 -> V_86 ;
if ( F_10 ( V_73 , & V_82 , sizeof( V_82 ) ) )
V_8 = - V_26 ;
break;
}
default:
{
struct V_30 * V_35 = V_31 -> V_35 ;
if ( F_51 ( V_71 ) != 'H' ) {
V_8 = - V_37 ;
break;
}
if ( F_52 ( V_71 ) == F_52 ( F_53 ( 0 ) ) ) {
int V_9 = F_54 ( V_71 ) ;
V_8 = F_12 ( V_1 , V_73 , V_9 , V_87 ) ;
break;
}
if ( F_52 ( V_71 ) == F_52 ( F_55 ( 0 ) ) ) {
int V_9 = F_54 ( V_71 ) ;
V_8 = F_23 ( V_1 , V_73 , V_9 , V_87 ) ;
break;
}
if ( F_56 ( V_71 ) != V_88 ) {
V_8 = - V_37 ;
break;
}
if ( F_52 ( V_71 ) == F_52 ( F_57 ( 0 ) ) ) {
int V_9 = strlen ( V_35 -> V_89 ) + 1 ;
if ( V_9 > F_54 ( V_71 ) )
V_9 = F_54 ( V_71 ) ;
V_8 = F_10 ( V_73 , V_35 -> V_89 , V_9 ) ?
- V_26 : V_9 ;
break;
}
if ( F_52 ( V_71 ) == F_52 ( F_58 ( 0 ) ) ) {
int V_9 = strlen ( V_35 -> V_90 ) + 1 ;
if ( V_9 > F_54 ( V_71 ) )
V_9 = F_54 ( V_71 ) ;
V_8 = F_10 ( V_73 , V_35 -> V_90 , V_9 ) ?
- V_26 : V_9 ;
break;
}
}
V_8 = - V_91 ;
}
V_24:
F_7 ( & V_44 ) ;
return V_8 ;
}
int F_59 ( struct V_30 * V_35 , T_8 * V_92 , int V_9 )
{
struct V_15 * V_31 = V_35 -> V_15 ;
struct V_5 * V_6 ;
int V_8 = 0 ;
unsigned long V_57 ;
F_34 ( & V_31 -> V_63 , V_57 ) ;
F_60 (list, &dev->list, node) {
int V_93 = ( V_6 -> V_13 + 1 ) & ( V_27 - 1 ) ;
if ( V_93 == V_6 -> V_14 )
continue;
if ( ! ( V_6 -> V_2 [ V_6 -> V_13 ] . V_25 = F_61 ( V_92 , V_9 , V_94 ) ) ) {
V_8 = - V_50 ;
break;
}
V_6 -> V_2 [ V_6 -> V_13 ] . V_9 = V_9 ;
V_6 -> V_13 = V_93 ;
F_62 ( & V_6 -> V_67 , V_95 , V_96 ) ;
}
F_36 ( & V_31 -> V_63 , V_57 ) ;
F_41 ( & V_31 -> V_10 ) ;
return V_8 ;
}
int F_63 ( struct V_30 * V_35 )
{
int V_29 , V_97 ;
struct V_15 * V_31 ;
V_31 = F_30 ( sizeof( struct V_15 ) , V_49 ) ;
if ( ! V_31 )
return - V_50 ;
V_97 = - V_37 ;
F_3 ( & V_44 ) ;
for ( V_29 = 0 ; V_29 < V_98 ; V_29 ++ ) {
if ( V_33 [ V_29 ] )
continue;
V_33 [ V_29 ] = V_31 ;
V_97 = 0 ;
break;
}
if ( V_97 ) {
F_7 ( & V_44 ) ;
F_11 ( V_31 ) ;
goto V_24;
}
V_31 -> V_31 = F_64 ( V_69 , & V_35 -> V_31 , F_43 ( V_70 , V_29 ) ,
NULL , L_5 , L_6 , V_29 ) ;
if ( F_18 ( V_31 -> V_31 ) ) {
V_33 [ V_29 ] = NULL ;
F_7 ( & V_44 ) ;
V_97 = F_19 ( V_31 -> V_31 ) ;
F_11 ( V_31 ) ;
goto V_24;
}
F_65 ( & V_31 -> V_10 ) ;
F_66 ( & V_31 -> V_63 ) ;
F_67 ( & V_31 -> V_6 ) ;
V_31 -> V_35 = V_35 ;
V_31 -> V_29 = V_29 ;
V_31 -> V_18 = 1 ;
V_35 -> V_15 = V_31 ;
F_7 ( & V_44 ) ;
V_24:
return V_97 ;
}
void F_68 ( struct V_30 * V_35 )
{
struct V_15 * V_15 = V_35 -> V_15 ;
F_3 ( & V_44 ) ;
F_39 ( V_15 , 1 ) ;
F_7 ( & V_44 ) ;
}
int T_9 F_69 ( void )
{
int V_97 ;
T_10 V_99 ;
V_97 = F_70 ( & V_99 , V_100 ,
V_98 , L_6 ) ;
if ( V_97 < 0 ) {
F_71 ( L_7 ) ;
goto V_24;
}
V_70 = F_72 ( V_99 ) ;
V_69 = F_73 ( V_101 , L_6 ) ;
if ( F_18 ( V_69 ) ) {
V_97 = F_19 ( V_69 ) ;
goto V_102;
}
F_74 ( & V_103 , & V_104 ) ;
V_97 = F_75 ( & V_103 , V_99 , V_98 ) ;
if ( V_97 < 0 )
goto V_105;
F_24 ( V_106 L_8 ) ;
V_24:
return V_97 ;
V_105:
F_76 ( V_69 ) ;
V_102:
F_77 ( V_99 , V_98 ) ;
goto V_24;
}
void F_78 ( void )
{
T_10 V_99 = F_43 ( V_70 , 0 ) ;
F_79 ( & V_103 ) ;
F_76 ( V_69 ) ;
F_77 ( V_99 , V_98 ) ;
}
