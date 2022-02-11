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
if ( V_1 -> V_17 & V_18 ) {
V_8 = - V_19 ;
break;
}
if ( F_6 ( V_11 ) ) {
V_8 = - V_20 ;
break;
}
if ( ! V_6 -> V_15 -> V_21 ) {
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
unsigned int V_29 = F_13 ( V_1 -> V_30 . V_31 -> V_32 ) ;
struct V_33 * V_34 ;
T_5 * V_35 ;
int V_8 = 0 ;
if ( ! V_36 [ V_29 ] ) {
V_8 = - V_37 ;
goto V_24;
}
V_34 = V_36 [ V_29 ] -> V_38 ;
if ( ! V_34 -> V_39 ) {
V_8 = - V_37 ;
goto V_24;
}
if ( V_3 > V_40 ) {
F_14 ( V_34 , L_1 ,
F_15 ( V_11 ) ) ;
V_8 = - V_41 ;
goto V_24;
}
if ( V_3 < 2 ) {
F_14 ( V_34 , L_2 ,
F_15 ( V_11 ) ) ;
V_8 = - V_41 ;
goto V_24;
}
V_35 = F_16 ( V_3 * sizeof( T_5 ) , V_42 ) ;
if ( ! V_35 ) {
V_8 = - V_43 ;
goto V_24;
}
if ( F_17 ( V_35 , V_2 , V_3 ) ) {
V_8 = - V_26 ;
goto V_44;
}
V_8 = V_34 -> V_39 ( V_34 , V_35 , V_3 , V_28 ) ;
V_44:
F_11 ( V_35 ) ;
V_24:
return V_8 ;
}
static T_1 F_18 ( struct V_1 * V_1 , const char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
T_1 V_8 ;
F_3 ( & V_45 ) ;
V_8 = F_12 ( V_1 , V_2 , V_3 , V_46 ) ;
F_7 ( & V_45 ) ;
return V_8 ;
}
static T_1 F_19 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , unsigned char V_28 )
{
unsigned int V_29 = F_13 ( V_1 -> V_30 . V_31 -> V_32 ) ;
struct V_33 * V_34 ;
T_5 * V_35 ;
int V_8 = 0 , V_9 ;
unsigned char V_47 ;
V_34 = V_36 [ V_29 ] -> V_38 ;
if ( ! V_34 -> V_48 ) {
V_8 = - V_37 ;
goto V_24;
}
if ( V_3 > V_40 ) {
F_20 ( V_49 L_3 ,
F_15 ( V_11 ) ) ;
V_8 = - V_41 ;
goto V_24;
}
if ( V_3 < 2 ) {
F_20 ( V_49 L_4 ,
F_15 ( V_11 ) ) ;
V_8 = - V_41 ;
goto V_24;
}
V_35 = F_16 ( V_3 * sizeof( T_5 ) , V_42 ) ;
if ( ! V_35 ) {
V_8 = - V_43 ;
goto V_24;
}
if ( F_17 ( & V_47 , V_2 , 1 ) ) {
V_8 = - V_26 ;
goto V_44;
}
V_8 = V_34 -> V_48 ( V_34 , V_47 , V_35 , V_3 , V_28 ) ;
if ( V_8 < 0 )
goto V_44;
V_9 = ( V_8 < V_3 ) ? V_8 : V_3 ;
if ( F_10 ( V_2 , V_35 , V_9 ) ) {
V_8 = - V_26 ;
goto V_44;
}
V_8 = V_9 ;
V_44:
F_11 ( V_35 ) ;
V_24:
return V_8 ;
}
static unsigned int F_21 ( struct V_1 * V_1 , T_6 * V_10 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
F_22 ( V_1 , & V_6 -> V_15 -> V_10 , V_10 ) ;
if ( V_6 -> V_13 != V_6 -> V_14 )
return V_50 | V_51 ;
if ( ! V_6 -> V_15 -> V_21 )
return V_52 | V_53 ;
return 0 ;
}
static int F_23 ( struct V_54 * V_54 , struct V_1 * V_1 )
{
unsigned int V_29 = F_13 ( V_54 ) ;
struct V_15 * V_34 ;
struct V_5 * V_6 ;
int V_55 = 0 ;
if ( ! ( V_6 = F_24 ( sizeof( struct V_5 ) , V_42 ) ) ) {
V_55 = - V_43 ;
goto V_24;
}
F_3 ( & V_45 ) ;
if ( ! V_36 [ V_29 ] ) {
V_55 = - V_37 ;
goto V_56;
}
V_6 -> V_15 = V_36 [ V_29 ] ;
F_25 ( & V_6 -> V_12 ) ;
F_26 ( & V_6 -> V_57 , & V_36 [ V_29 ] -> V_6 ) ;
V_1 -> V_7 = V_6 ;
V_34 = V_36 [ V_29 ] ;
if ( ! V_34 -> V_58 ++ ) {
V_55 = F_27 ( V_34 -> V_38 , V_59 ) ;
if ( V_55 < 0 ) {
V_34 -> V_58 -- ;
goto V_56;
}
V_55 = F_28 ( V_34 -> V_38 ) ;
if ( V_55 < 0 ) {
F_27 ( V_34 -> V_38 , V_60 ) ;
V_34 -> V_58 -- ;
}
}
V_56:
F_7 ( & V_45 ) ;
V_24:
if ( V_55 < 0 )
F_11 ( V_6 ) ;
return V_55 ;
}
static int F_29 ( struct V_54 * V_54 , struct V_1 * V_1 )
{
unsigned int V_29 = F_13 ( V_54 ) ;
struct V_15 * V_34 ;
struct V_5 * V_6 = V_1 -> V_7 ;
int V_8 ;
int V_61 ;
F_3 ( & V_45 ) ;
if ( ! V_36 [ V_29 ] ) {
V_8 = - V_37 ;
goto V_62;
}
F_30 ( & V_6 -> V_57 ) ;
V_34 = V_36 [ V_29 ] ;
if ( ! -- V_34 -> V_58 ) {
if ( V_6 -> V_15 -> V_21 ) {
F_27 ( V_34 -> V_38 , V_60 ) ;
F_31 ( V_34 -> V_38 ) ;
} else {
F_11 ( V_6 -> V_15 ) ;
}
}
for ( V_61 = 0 ; V_61 < V_27 ; ++ V_61 )
F_11 ( V_6 -> V_2 [ V_61 ] . V_25 ) ;
F_11 ( V_6 ) ;
V_8 = 0 ;
V_62:
F_7 ( & V_45 ) ;
return V_8 ;
}
static long F_32 ( struct V_1 * V_1 , unsigned int V_63 ,
unsigned long V_64 )
{
struct V_54 * V_54 = V_1 -> V_30 . V_31 -> V_32 ;
unsigned int V_29 = F_13 ( V_54 ) ;
long V_8 = 0 ;
struct V_15 * V_34 ;
void T_2 * V_65 = ( void T_2 * ) V_64 ;
F_3 ( & V_45 ) ;
V_34 = V_36 [ V_29 ] ;
if ( ! V_34 ) {
V_8 = - V_37 ;
goto V_24;
}
switch ( V_63 ) {
case V_66 :
if ( F_33 ( V_34 -> V_38 -> V_67 , ( int T_2 * ) V_64 ) )
V_8 = - V_26 ;
break;
case V_68 :
{
T_7 V_9 ;
if ( F_34 ( V_9 , ( int T_2 * ) V_64 ) )
V_8 = - V_26 ;
else if ( V_9 > V_69 - 1 )
V_8 = - V_41 ;
else if ( F_10 ( V_65 + F_35 (
struct V_70 ,
V_25 [ 0 ] ) ,
V_34 -> V_38 -> V_71 ,
F_36 ( V_34 -> V_38 -> V_67 , V_9 ) ) )
V_8 = - V_26 ;
break;
}
case V_72 :
{
struct V_73 V_74 ;
V_74 . V_75 = V_34 -> V_38 -> V_76 ;
V_74 . V_77 = V_34 -> V_38 -> V_77 ;
V_74 . V_78 = V_34 -> V_38 -> V_78 ;
if ( F_10 ( V_65 , & V_74 , sizeof( V_74 ) ) )
V_8 = - V_26 ;
break;
}
default:
{
struct V_33 * V_38 = V_34 -> V_38 ;
if ( F_37 ( V_63 ) != 'H' ) {
V_8 = - V_41 ;
break;
}
if ( F_38 ( V_63 ) == F_38 ( F_39 ( 0 ) ) ) {
int V_9 = F_40 ( V_63 ) ;
V_8 = F_12 ( V_1 , V_65 , V_9 , V_79 ) ;
break;
}
if ( F_38 ( V_63 ) == F_38 ( F_41 ( 0 ) ) ) {
int V_9 = F_40 ( V_63 ) ;
V_8 = F_19 ( V_1 , V_65 , V_9 , V_79 ) ;
break;
}
if ( F_42 ( V_63 ) != V_80 ) {
V_8 = - V_41 ;
break;
}
if ( F_38 ( V_63 ) == F_38 ( F_43 ( 0 ) ) ) {
int V_9 = strlen ( V_38 -> V_81 ) + 1 ;
if ( V_9 > F_40 ( V_63 ) )
V_9 = F_40 ( V_63 ) ;
V_8 = F_10 ( V_65 , V_38 -> V_81 , V_9 ) ?
- V_26 : V_9 ;
break;
}
if ( F_38 ( V_63 ) == F_38 ( F_44 ( 0 ) ) ) {
int V_9 = strlen ( V_38 -> V_82 ) + 1 ;
if ( V_9 > F_40 ( V_63 ) )
V_9 = F_40 ( V_63 ) ;
V_8 = F_10 ( V_65 , V_38 -> V_82 , V_9 ) ?
- V_26 : V_9 ;
break;
}
}
V_8 = - V_83 ;
}
V_24:
F_7 ( & V_45 ) ;
return V_8 ;
}
int F_45 ( struct V_33 * V_38 , T_8 * V_84 , int V_9 )
{
struct V_15 * V_34 = V_38 -> V_15 ;
struct V_5 * V_6 ;
int V_8 = 0 ;
F_46 (list, &dev->list, node) {
int V_85 = ( V_6 -> V_13 + 1 ) & ( V_27 - 1 ) ;
if ( V_85 == V_6 -> V_14 )
continue;
if ( ! ( V_6 -> V_2 [ V_6 -> V_13 ] . V_25 = F_47 ( V_84 , V_9 , V_86 ) ) ) {
V_8 = - V_43 ;
break;
}
V_6 -> V_2 [ V_6 -> V_13 ] . V_9 = V_9 ;
V_6 -> V_13 = V_85 ;
F_48 ( & V_6 -> V_87 , V_88 , V_89 ) ;
}
F_49 ( & V_34 -> V_10 ) ;
return V_8 ;
}
int F_50 ( struct V_33 * V_38 )
{
int V_29 , V_90 ;
struct V_15 * V_34 ;
V_34 = F_24 ( sizeof( struct V_15 ) , V_42 ) ;
if ( ! V_34 )
return - V_43 ;
V_90 = - V_41 ;
F_3 ( & V_45 ) ;
for ( V_29 = 0 ; V_29 < V_91 ; V_29 ++ ) {
if ( V_36 [ V_29 ] )
continue;
V_36 [ V_29 ] = V_34 ;
V_90 = 0 ;
break;
}
if ( V_90 ) {
F_7 ( & V_45 ) ;
F_11 ( V_34 ) ;
goto V_24;
}
V_34 -> V_34 = F_51 ( V_92 , & V_38 -> V_34 , F_52 ( V_93 , V_29 ) ,
NULL , L_5 , L_6 , V_29 ) ;
if ( F_53 ( V_34 -> V_34 ) ) {
V_36 [ V_29 ] = NULL ;
F_7 ( & V_45 ) ;
V_90 = F_54 ( V_34 -> V_34 ) ;
F_11 ( V_34 ) ;
goto V_24;
}
F_7 ( & V_45 ) ;
F_55 ( & V_34 -> V_10 ) ;
F_56 ( & V_34 -> V_6 ) ;
V_34 -> V_38 = V_38 ;
V_34 -> V_29 = V_29 ;
V_34 -> V_21 = 1 ;
V_38 -> V_15 = V_34 ;
V_24:
return V_90 ;
}
void F_57 ( struct V_33 * V_38 )
{
struct V_15 * V_15 = V_38 -> V_15 ;
F_3 ( & V_45 ) ;
V_15 -> V_21 = 0 ;
F_58 ( V_92 , F_52 ( V_93 , V_15 -> V_29 ) ) ;
V_36 [ V_15 -> V_29 ] = NULL ;
if ( V_15 -> V_58 ) {
F_31 ( V_38 ) ;
F_49 ( & V_15 -> V_10 ) ;
} else {
F_11 ( V_15 ) ;
}
F_7 ( & V_45 ) ;
}
int T_9 F_59 ( void )
{
int V_90 ;
T_10 V_94 ;
V_90 = F_60 ( & V_94 , V_95 ,
V_91 , L_6 ) ;
V_93 = F_61 ( V_94 ) ;
if ( V_90 < 0 ) {
F_62 ( L_7 ) ;
V_90 = 0 ;
goto V_24;
}
V_92 = F_63 ( V_96 , L_6 ) ;
if ( F_53 ( V_92 ) ) {
V_90 = F_54 ( V_92 ) ;
F_64 ( V_93 , L_6 ) ;
goto V_24;
}
F_65 ( & V_97 , & V_98 ) ;
F_66 ( & V_97 , V_94 , V_91 ) ;
V_24:
return V_90 ;
}
void F_67 ( void )
{
T_10 V_94 = F_52 ( V_93 , 0 ) ;
F_68 ( & V_97 ) ;
F_69 ( V_92 ) ;
F_70 ( V_94 , V_91 ) ;
}
