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
if ( ! V_33 [ V_29 ] ) {
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
int V_52 = 0 ;
if ( ! ( V_6 = F_25 ( sizeof( struct V_5 ) , V_39 ) ) ) {
V_52 = - V_40 ;
goto V_24;
}
F_3 ( & V_42 ) ;
if ( ! V_33 [ V_29 ] ) {
V_52 = - V_34 ;
goto V_53;
}
V_6 -> V_15 = V_33 [ V_29 ] ;
F_26 ( & V_6 -> V_12 ) ;
F_27 ( & V_6 -> V_54 , & V_33 [ V_29 ] -> V_6 ) ;
V_1 -> V_7 = V_6 ;
V_31 = V_33 [ V_29 ] ;
if ( ! V_31 -> V_55 ++ ) {
V_52 = F_28 ( V_31 -> V_35 , V_56 ) ;
if ( V_52 < 0 ) {
V_31 -> V_55 -- ;
goto V_53;
}
V_52 = F_29 ( V_31 -> V_35 ) ;
if ( V_52 < 0 ) {
F_28 ( V_31 -> V_35 , V_57 ) ;
V_31 -> V_55 -- ;
}
}
V_53:
F_7 ( & V_42 ) ;
V_24:
if ( V_52 < 0 )
F_11 ( V_6 ) ;
return V_52 ;
}
static int F_30 ( int V_58 , struct V_1 * V_1 , int V_59 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
return F_31 ( V_58 , V_1 , V_59 , & V_6 -> V_60 ) ;
}
static int F_32 ( struct V_51 * V_51 , struct V_1 * V_1 )
{
unsigned int V_29 = F_13 ( V_51 ) ;
struct V_15 * V_31 ;
struct V_5 * V_6 = V_1 -> V_7 ;
int V_8 ;
int V_61 ;
F_3 ( & V_42 ) ;
if ( ! V_33 [ V_29 ] ) {
V_8 = - V_34 ;
goto V_62;
}
F_33 ( & V_6 -> V_54 ) ;
V_31 = V_33 [ V_29 ] ;
if ( ! -- V_31 -> V_55 ) {
if ( V_6 -> V_15 -> V_18 ) {
F_28 ( V_31 -> V_35 , V_57 ) ;
F_34 ( V_31 -> V_35 ) ;
} else {
F_11 ( V_6 -> V_15 ) ;
}
}
for ( V_61 = 0 ; V_61 < V_27 ; ++ V_61 )
F_11 ( V_6 -> V_2 [ V_61 ] . V_25 ) ;
F_11 ( V_6 ) ;
V_8 = 0 ;
V_62:
F_7 ( & V_42 ) ;
return V_8 ;
}
static long F_35 ( struct V_1 * V_1 , unsigned int V_63 ,
unsigned long V_64 )
{
struct V_51 * V_51 = F_14 ( V_1 ) ;
unsigned int V_29 = F_13 ( V_51 ) ;
long V_8 = 0 ;
struct V_15 * V_31 ;
void T_2 * V_65 = ( void T_2 * ) V_64 ;
F_3 ( & V_42 ) ;
V_31 = V_33 [ V_29 ] ;
if ( ! V_31 ) {
V_8 = - V_34 ;
goto V_24;
}
switch ( V_63 ) {
case V_66 :
if ( F_36 ( V_31 -> V_35 -> V_67 , ( int T_2 * ) V_64 ) )
V_8 = - V_26 ;
break;
case V_68 :
{
T_7 V_9 ;
if ( F_37 ( V_9 , ( int T_2 * ) V_64 ) )
V_8 = - V_26 ;
else if ( V_9 > V_69 - 1 )
V_8 = - V_38 ;
else if ( F_10 ( V_65 + F_38 (
struct V_70 ,
V_25 [ 0 ] ) ,
V_31 -> V_35 -> V_71 ,
F_39 ( V_31 -> V_35 -> V_67 , V_9 ) ) )
V_8 = - V_26 ;
break;
}
case V_72 :
{
struct V_73 V_74 ;
V_74 . V_75 = V_31 -> V_35 -> V_76 ;
V_74 . V_77 = V_31 -> V_35 -> V_77 ;
V_74 . V_78 = V_31 -> V_35 -> V_78 ;
if ( F_10 ( V_65 , & V_74 , sizeof( V_74 ) ) )
V_8 = - V_26 ;
break;
}
default:
{
struct V_30 * V_35 = V_31 -> V_35 ;
if ( F_40 ( V_63 ) != 'H' ) {
V_8 = - V_38 ;
break;
}
if ( F_41 ( V_63 ) == F_41 ( F_42 ( 0 ) ) ) {
int V_9 = F_43 ( V_63 ) ;
V_8 = F_12 ( V_1 , V_65 , V_9 , V_79 ) ;
break;
}
if ( F_41 ( V_63 ) == F_41 ( F_44 ( 0 ) ) ) {
int V_9 = F_43 ( V_63 ) ;
V_8 = F_20 ( V_1 , V_65 , V_9 , V_79 ) ;
break;
}
if ( F_45 ( V_63 ) != V_80 ) {
V_8 = - V_38 ;
break;
}
if ( F_41 ( V_63 ) == F_41 ( F_46 ( 0 ) ) ) {
int V_9 = strlen ( V_35 -> V_81 ) + 1 ;
if ( V_9 > F_43 ( V_63 ) )
V_9 = F_43 ( V_63 ) ;
V_8 = F_10 ( V_65 , V_35 -> V_81 , V_9 ) ?
- V_26 : V_9 ;
break;
}
if ( F_41 ( V_63 ) == F_41 ( F_47 ( 0 ) ) ) {
int V_9 = strlen ( V_35 -> V_82 ) + 1 ;
if ( V_9 > F_43 ( V_63 ) )
V_9 = F_43 ( V_63 ) ;
V_8 = F_10 ( V_65 , V_35 -> V_82 , V_9 ) ?
- V_26 : V_9 ;
break;
}
}
V_8 = - V_83 ;
}
V_24:
F_7 ( & V_42 ) ;
return V_8 ;
}
int F_48 ( struct V_30 * V_35 , T_8 * V_84 , int V_9 )
{
struct V_15 * V_31 = V_35 -> V_15 ;
struct V_5 * V_6 ;
int V_8 = 0 ;
F_49 (list, &dev->list, node) {
int V_85 = ( V_6 -> V_13 + 1 ) & ( V_27 - 1 ) ;
if ( V_85 == V_6 -> V_14 )
continue;
if ( ! ( V_6 -> V_2 [ V_6 -> V_13 ] . V_25 = F_50 ( V_84 , V_9 , V_86 ) ) ) {
V_8 = - V_40 ;
break;
}
V_6 -> V_2 [ V_6 -> V_13 ] . V_9 = V_9 ;
V_6 -> V_13 = V_85 ;
F_51 ( & V_6 -> V_60 , V_87 , V_88 ) ;
}
F_52 ( & V_31 -> V_10 ) ;
return V_8 ;
}
int F_53 ( struct V_30 * V_35 )
{
int V_29 , V_89 ;
struct V_15 * V_31 ;
V_31 = F_25 ( sizeof( struct V_15 ) , V_39 ) ;
if ( ! V_31 )
return - V_40 ;
V_89 = - V_38 ;
F_3 ( & V_42 ) ;
for ( V_29 = 0 ; V_29 < V_90 ; V_29 ++ ) {
if ( V_33 [ V_29 ] )
continue;
V_33 [ V_29 ] = V_31 ;
V_89 = 0 ;
break;
}
if ( V_89 ) {
F_7 ( & V_42 ) ;
F_11 ( V_31 ) ;
goto V_24;
}
V_31 -> V_31 = F_54 ( V_91 , & V_35 -> V_31 , F_55 ( V_92 , V_29 ) ,
NULL , L_5 , L_6 , V_29 ) ;
if ( F_56 ( V_31 -> V_31 ) ) {
V_33 [ V_29 ] = NULL ;
F_7 ( & V_42 ) ;
V_89 = F_57 ( V_31 -> V_31 ) ;
F_11 ( V_31 ) ;
goto V_24;
}
F_7 ( & V_42 ) ;
F_58 ( & V_31 -> V_10 ) ;
F_59 ( & V_31 -> V_6 ) ;
V_31 -> V_35 = V_35 ;
V_31 -> V_29 = V_29 ;
V_31 -> V_18 = 1 ;
V_35 -> V_15 = V_31 ;
V_24:
return V_89 ;
}
void F_60 ( struct V_30 * V_35 )
{
struct V_15 * V_15 = V_35 -> V_15 ;
F_3 ( & V_42 ) ;
V_15 -> V_18 = 0 ;
F_61 ( V_91 , F_55 ( V_92 , V_15 -> V_29 ) ) ;
V_33 [ V_15 -> V_29 ] = NULL ;
if ( V_15 -> V_55 ) {
F_34 ( V_35 ) ;
F_52 ( & V_15 -> V_10 ) ;
} else {
F_11 ( V_15 ) ;
}
F_7 ( & V_42 ) ;
}
int T_9 F_62 ( void )
{
int V_89 ;
T_10 V_93 ;
V_89 = F_63 ( & V_93 , V_94 ,
V_90 , L_6 ) ;
V_92 = F_64 ( V_93 ) ;
if ( V_89 < 0 ) {
F_65 ( L_7 ) ;
goto V_24;
}
V_91 = F_66 ( V_95 , L_6 ) ;
if ( F_56 ( V_91 ) ) {
V_89 = F_57 ( V_91 ) ;
goto V_96;
}
F_67 ( & V_97 , & V_98 ) ;
V_89 = F_68 ( & V_97 , V_93 , V_90 ) ;
if ( V_89 < 0 )
goto V_99;
F_21 ( V_100 L_8 ) ;
V_24:
return V_89 ;
V_99:
F_69 ( V_91 ) ;
V_96:
F_70 ( V_93 , V_90 ) ;
goto V_24;
}
void F_71 ( void )
{
T_10 V_93 = F_55 ( V_92 , 0 ) ;
F_72 ( & V_97 ) ;
F_69 ( V_91 ) ;
F_70 ( V_93 , V_90 ) ;
}
