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
if ( ! V_31 -> V_36 ) {
V_8 = - V_34 ;
goto V_24;
}
if ( V_3 > V_37 ) {
F_15 ( V_31 , L_1 ,
F_16 ( V_11 ) ) ;
V_8 = - V_38 ;
goto V_24;
}
if ( V_3 < 2 ) {
F_15 ( V_31 , L_2 ,
F_16 ( V_11 ) ) ;
V_8 = - V_38 ;
goto V_24;
}
V_32 = F_17 ( V_3 * sizeof( T_5 ) , V_39 ) ;
if ( ! V_32 ) {
V_8 = - V_40 ;
goto V_24;
}
if ( F_18 ( V_32 , V_2 , V_3 ) ) {
V_8 = - V_26 ;
goto V_41;
}
V_8 = V_31 -> V_36 ( V_31 , V_32 , V_3 , V_28 ) ;
V_41:
F_11 ( V_32 ) ;
V_24:
return V_8 ;
}
static T_1 F_19 ( struct V_1 * V_1 , const char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
T_1 V_8 ;
F_3 ( & V_42 ) ;
V_8 = F_12 ( V_1 , V_2 , V_3 , V_43 ) ;
F_7 ( & V_42 ) ;
return V_8 ;
}
static T_1 F_20 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , unsigned char V_28 )
{
unsigned int V_29 = F_13 ( F_14 ( V_1 ) ) ;
struct V_30 * V_31 ;
T_5 * V_32 ;
int V_8 = 0 , V_9 ;
unsigned char V_44 ;
V_31 = V_33 [ V_29 ] -> V_35 ;
if ( ! V_31 -> V_45 ) {
V_8 = - V_34 ;
goto V_24;
}
if ( V_3 > V_37 ) {
F_21 ( V_46 L_3 ,
F_16 ( V_11 ) ) ;
V_8 = - V_38 ;
goto V_24;
}
if ( V_3 < 2 ) {
F_21 ( V_46 L_4 ,
F_16 ( V_11 ) ) ;
V_8 = - V_38 ;
goto V_24;
}
V_32 = F_17 ( V_3 * sizeof( T_5 ) , V_39 ) ;
if ( ! V_32 ) {
V_8 = - V_40 ;
goto V_24;
}
if ( F_18 ( & V_44 , V_2 , 1 ) ) {
V_8 = - V_26 ;
goto V_41;
}
V_8 = V_31 -> V_45 ( V_31 , V_44 , V_32 , V_3 , V_28 ) ;
if ( V_8 < 0 )
goto V_41;
V_9 = ( V_8 < V_3 ) ? V_8 : V_3 ;
if ( F_10 ( V_2 , V_32 , V_9 ) ) {
V_8 = - V_26 ;
goto V_41;
}
V_8 = V_9 ;
V_41:
F_11 ( V_32 ) ;
V_24:
return V_8 ;
}
static unsigned int F_22 ( struct V_1 * V_1 , T_6 * V_10 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
F_23 ( V_1 , & V_6 -> V_15 -> V_10 , V_10 ) ;
if ( V_6 -> V_13 != V_6 -> V_14 )
return V_47 | V_48 ;
if ( ! V_6 -> V_15 -> V_18 )
return V_49 | V_50 ;
return 0 ;
}
static int F_24 ( struct V_51 * V_51 , struct V_1 * V_1 )
{
unsigned int V_29 = F_13 ( V_51 ) ;
struct V_15 * V_31 ;
struct V_5 * V_6 ;
unsigned long V_52 ;
int V_53 = 0 ;
if ( ! ( V_6 = F_25 ( sizeof( struct V_5 ) , V_39 ) ) ) {
V_53 = - V_40 ;
goto V_24;
}
F_3 ( & V_42 ) ;
if ( ! V_33 [ V_29 ] || ! V_33 [ V_29 ] -> V_18 ) {
V_53 = - V_34 ;
goto V_54;
}
V_31 = V_33 [ V_29 ] ;
if ( ! V_31 -> V_55 ++ ) {
V_53 = F_26 ( V_31 -> V_35 , V_56 ) ;
if ( V_53 < 0 ) {
V_31 -> V_55 -- ;
goto V_54;
}
V_53 = F_27 ( V_31 -> V_35 ) ;
if ( V_53 < 0 ) {
F_26 ( V_31 -> V_35 , V_57 ) ;
V_31 -> V_55 -- ;
goto V_54;
}
}
V_6 -> V_15 = V_33 [ V_29 ] ;
F_28 ( & V_6 -> V_12 ) ;
F_29 ( & V_33 [ V_29 ] -> V_58 , V_52 ) ;
F_30 ( & V_6 -> V_59 , & V_33 [ V_29 ] -> V_6 ) ;
F_31 ( & V_33 [ V_29 ] -> V_58 , V_52 ) ;
V_1 -> V_7 = V_6 ;
V_54:
F_7 ( & V_42 ) ;
V_24:
if ( V_53 < 0 )
F_11 ( V_6 ) ;
return V_53 ;
}
static int F_32 ( int V_60 , struct V_1 * V_1 , int V_61 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
return F_33 ( V_60 , V_1 , V_61 , & V_6 -> V_62 ) ;
}
static void F_34 ( struct V_15 * V_15 , int V_63 )
{
if ( V_63 ) {
V_15 -> V_18 = 0 ;
if ( V_15 -> V_55 ) {
F_35 ( V_15 -> V_35 ) ;
F_36 ( & V_15 -> V_10 ) ;
}
} else {
-- V_15 -> V_55 ;
}
if ( ! V_15 -> V_55 ) {
if ( ! V_15 -> V_18 ) {
F_37 ( V_64 ,
F_38 ( V_65 , V_15 -> V_29 ) ) ;
V_33 [ V_15 -> V_29 ] = NULL ;
F_11 ( V_15 ) ;
} else {
F_26 ( V_15 -> V_35 , V_57 ) ;
F_35 ( V_15 -> V_35 ) ;
}
}
}
static int F_39 ( struct V_51 * V_51 , struct V_1 * V_1 )
{
unsigned int V_29 = F_13 ( V_51 ) ;
struct V_5 * V_6 = V_1 -> V_7 ;
unsigned long V_52 ;
F_3 ( & V_42 ) ;
F_29 ( & V_33 [ V_29 ] -> V_58 , V_52 ) ;
F_40 ( & V_6 -> V_59 ) ;
F_31 ( & V_33 [ V_29 ] -> V_58 , V_52 ) ;
F_11 ( V_6 ) ;
F_34 ( V_33 [ V_29 ] , 0 ) ;
F_7 ( & V_42 ) ;
return 0 ;
}
static long F_41 ( struct V_1 * V_1 , unsigned int V_66 ,
unsigned long V_67 )
{
struct V_51 * V_51 = F_14 ( V_1 ) ;
unsigned int V_29 = F_13 ( V_51 ) ;
long V_8 = 0 ;
struct V_15 * V_31 ;
void T_2 * V_68 = ( void T_2 * ) V_67 ;
F_3 ( & V_42 ) ;
V_31 = V_33 [ V_29 ] ;
if ( ! V_31 ) {
V_8 = - V_34 ;
goto V_24;
}
switch ( V_66 ) {
case V_69 :
if ( F_42 ( V_31 -> V_35 -> V_70 , ( int T_2 * ) V_67 ) )
V_8 = - V_26 ;
break;
case V_71 :
{
T_7 V_9 ;
if ( F_43 ( V_9 , ( int T_2 * ) V_67 ) )
V_8 = - V_26 ;
else if ( V_9 > V_72 - 1 )
V_8 = - V_38 ;
else if ( F_10 ( V_68 + F_44 (
struct V_73 ,
V_25 [ 0 ] ) ,
V_31 -> V_35 -> V_74 ,
F_45 ( V_31 -> V_35 -> V_70 , V_9 ) ) )
V_8 = - V_26 ;
break;
}
case V_75 :
{
struct V_76 V_77 ;
V_77 . V_78 = V_31 -> V_35 -> V_79 ;
V_77 . V_80 = V_31 -> V_35 -> V_80 ;
V_77 . V_81 = V_31 -> V_35 -> V_81 ;
if ( F_10 ( V_68 , & V_77 , sizeof( V_77 ) ) )
V_8 = - V_26 ;
break;
}
default:
{
struct V_30 * V_35 = V_31 -> V_35 ;
if ( F_46 ( V_66 ) != 'H' ) {
V_8 = - V_38 ;
break;
}
if ( F_47 ( V_66 ) == F_47 ( F_48 ( 0 ) ) ) {
int V_9 = F_49 ( V_66 ) ;
V_8 = F_12 ( V_1 , V_68 , V_9 , V_82 ) ;
break;
}
if ( F_47 ( V_66 ) == F_47 ( F_50 ( 0 ) ) ) {
int V_9 = F_49 ( V_66 ) ;
V_8 = F_20 ( V_1 , V_68 , V_9 , V_82 ) ;
break;
}
if ( F_51 ( V_66 ) != V_83 ) {
V_8 = - V_38 ;
break;
}
if ( F_47 ( V_66 ) == F_47 ( F_52 ( 0 ) ) ) {
int V_9 = strlen ( V_35 -> V_84 ) + 1 ;
if ( V_9 > F_49 ( V_66 ) )
V_9 = F_49 ( V_66 ) ;
V_8 = F_10 ( V_68 , V_35 -> V_84 , V_9 ) ?
- V_26 : V_9 ;
break;
}
if ( F_47 ( V_66 ) == F_47 ( F_53 ( 0 ) ) ) {
int V_9 = strlen ( V_35 -> V_85 ) + 1 ;
if ( V_9 > F_49 ( V_66 ) )
V_9 = F_49 ( V_66 ) ;
V_8 = F_10 ( V_68 , V_35 -> V_85 , V_9 ) ?
- V_26 : V_9 ;
break;
}
}
V_8 = - V_86 ;
}
V_24:
F_7 ( & V_42 ) ;
return V_8 ;
}
int F_54 ( struct V_30 * V_35 , T_8 * V_87 , int V_9 )
{
struct V_15 * V_31 = V_35 -> V_15 ;
struct V_5 * V_6 ;
int V_8 = 0 ;
unsigned long V_52 ;
F_29 ( & V_31 -> V_58 , V_52 ) ;
F_55 (list, &dev->list, node) {
int V_88 = ( V_6 -> V_13 + 1 ) & ( V_27 - 1 ) ;
if ( V_88 == V_6 -> V_14 )
continue;
if ( ! ( V_6 -> V_2 [ V_6 -> V_13 ] . V_25 = F_56 ( V_87 , V_9 , V_89 ) ) ) {
V_8 = - V_40 ;
break;
}
V_6 -> V_2 [ V_6 -> V_13 ] . V_9 = V_9 ;
V_6 -> V_13 = V_88 ;
F_57 ( & V_6 -> V_62 , V_90 , V_91 ) ;
}
F_31 ( & V_31 -> V_58 , V_52 ) ;
F_36 ( & V_31 -> V_10 ) ;
return V_8 ;
}
int F_58 ( struct V_30 * V_35 )
{
int V_29 , V_92 ;
struct V_15 * V_31 ;
V_31 = F_25 ( sizeof( struct V_15 ) , V_39 ) ;
if ( ! V_31 )
return - V_40 ;
V_92 = - V_38 ;
F_3 ( & V_42 ) ;
for ( V_29 = 0 ; V_29 < V_93 ; V_29 ++ ) {
if ( V_33 [ V_29 ] )
continue;
V_33 [ V_29 ] = V_31 ;
V_92 = 0 ;
break;
}
if ( V_92 ) {
F_7 ( & V_42 ) ;
F_11 ( V_31 ) ;
goto V_24;
}
V_31 -> V_31 = F_59 ( V_64 , & V_35 -> V_31 , F_38 ( V_65 , V_29 ) ,
NULL , L_5 , L_6 , V_29 ) ;
if ( F_60 ( V_31 -> V_31 ) ) {
V_33 [ V_29 ] = NULL ;
F_7 ( & V_42 ) ;
V_92 = F_61 ( V_31 -> V_31 ) ;
F_11 ( V_31 ) ;
goto V_24;
}
F_62 ( & V_31 -> V_10 ) ;
F_63 ( & V_31 -> V_58 ) ;
F_64 ( & V_31 -> V_6 ) ;
V_31 -> V_35 = V_35 ;
V_31 -> V_29 = V_29 ;
V_31 -> V_18 = 1 ;
V_35 -> V_15 = V_31 ;
F_7 ( & V_42 ) ;
V_24:
return V_92 ;
}
void F_65 ( struct V_30 * V_35 )
{
struct V_15 * V_15 = V_35 -> V_15 ;
F_3 ( & V_42 ) ;
F_34 ( V_15 , 1 ) ;
F_7 ( & V_42 ) ;
}
int T_9 F_66 ( void )
{
int V_92 ;
T_10 V_94 ;
V_92 = F_67 ( & V_94 , V_95 ,
V_93 , L_6 ) ;
V_65 = F_68 ( V_94 ) ;
if ( V_92 < 0 ) {
F_69 ( L_7 ) ;
goto V_24;
}
V_64 = F_70 ( V_96 , L_6 ) ;
if ( F_60 ( V_64 ) ) {
V_92 = F_61 ( V_64 ) ;
goto V_97;
}
F_71 ( & V_98 , & V_99 ) ;
V_92 = F_72 ( & V_98 , V_94 , V_93 ) ;
if ( V_92 < 0 )
goto V_100;
F_21 ( V_101 L_8 ) ;
V_24:
return V_92 ;
V_100:
F_73 ( V_64 ) ;
V_97:
F_74 ( V_94 , V_93 ) ;
goto V_24;
}
void F_75 ( void )
{
T_10 V_94 = F_38 ( V_65 , 0 ) ;
F_76 ( & V_98 ) ;
F_73 ( V_64 ) ;
F_74 ( V_94 , V_93 ) ;
}
