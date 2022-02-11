static void F_1 ( void )
{
V_1 . V_2 = 0 ;
V_1 . V_3 = 0 ;
V_1 . V_4 = 0 ;
V_1 . V_5 = 0 ;
V_1 . V_6 = 0 ;
V_1 . V_7 = 0 ;
V_1 . V_8 = 0 ;
}
static int F_2 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
int V_11 ;
unsigned int V_12 = F_3 ( V_9 -> V_13 ) ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
if ( V_12 < V_16 && V_14 [ V_12 ] . V_17 == NULL ) {
F_5 ( L_1 ) ;
V_11 = - V_18 ;
goto V_19;
}
V_14 [ V_12 ] . V_20 ++ ;
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return 0 ;
V_19:
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return V_11 ;
}
static int F_7 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
unsigned int V_12 = F_3 ( V_9 -> V_13 ) ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_14 [ V_12 ] . V_20 -- ;
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return 0 ;
}
static T_1 F_8 ( int V_12 , char T_2 * V_21 , T_3 V_22 ,
T_4 * V_23 )
{
T_1 V_24 ;
T_1 V_25 = 0 ;
if ( V_22 <= V_14 [ V_12 ] . V_26 ) {
V_25 = F_9 ( V_14 [ V_12 ] . V_17 ,
V_14 [ V_12 ] . V_27 , V_22 , * V_23 ) ;
if ( V_25 < 0 )
return ( int ) V_25 ;
V_24 = F_10 ( V_21 , V_14 [ V_12 ] . V_27 ,
( unsigned long ) V_25 ) ;
if ( V_24 != 0 ) {
V_25 = ( V_25 - V_24 ) ;
F_11 ( L_2 ) ;
return - V_18 ;
}
} else {
F_11 ( L_3 ) ;
return - V_18 ;
}
return V_25 ;
}
static T_1 F_12 ( unsigned int V_12 , const char T_2 * V_21 ,
T_3 V_22 , T_4 * V_23 )
{
T_1 V_24 ;
T_1 V_25 = 0 ;
if ( V_22 <= V_14 [ V_12 ] . V_26 ) {
V_24 = F_13 ( V_14 [ V_12 ] . V_27 , V_21 ,
( unsigned long ) V_22 ) ;
if ( V_24 != 0 )
V_25 = ( V_25 - V_24 ) ;
else
V_25 = V_22 ;
V_25 = F_14 ( V_14 [ V_12 ] . V_17 ,
V_14 [ V_12 ] . V_27 , V_25 , * V_23 ) ;
} else {
F_11 ( L_3 ) ;
return - V_18 ;
}
return V_25 ;
}
static T_1 F_15 ( unsigned int V_12 , char T_2 * V_21 ,
T_3 V_22 , T_4 * V_23 )
{
void * V_28 ;
T_1 V_24 ;
V_28 = V_14 [ V_12 ] . V_27 + * V_23 ;
V_24 = F_10 ( V_21 , V_28 , ( unsigned long ) V_22 ) ;
if ( V_24 != 0 ) {
V_24 = ( V_22 - V_24 ) ;
F_16 ( L_4 ) ;
} else
V_24 = V_22 ;
return V_24 ;
}
static T_1 F_17 ( unsigned int V_12 , const char T_2 * V_21 ,
T_3 V_22 , T_4 * V_23 )
{
void * V_28 ;
T_3 V_24 ;
V_28 = V_14 [ V_12 ] . V_27 + * V_23 ;
V_24 = F_13 ( V_28 , V_21 , ( unsigned long ) V_22 ) ;
if ( V_24 != 0 ) {
V_24 = ( V_22 - V_24 ) ;
F_16 ( L_4 ) ;
} else
V_24 = V_22 ;
return V_24 ;
}
static T_1 F_18 ( struct V_10 * V_10 , char T_2 * V_21 , T_3 V_22 ,
T_4 * V_23 )
{
unsigned int V_12 = F_3 ( V_10 -> V_29 -> V_30 -> V_13 ) ;
T_1 V_24 ;
T_3 V_31 ;
T_3 V_32 ;
if ( V_12 == V_16 )
return 0 ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_31 = F_19 ( V_14 [ V_12 ] . V_17 ) ;
if ( ( * V_23 < 0 ) || ( * V_23 > ( V_31 - 1 ) ) ) {
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return 0 ;
}
if ( * V_23 + V_22 > V_31 )
V_32 = V_31 - * V_23 ;
else
V_32 = V_22 ;
switch ( type [ V_12 ] ) {
case V_33 :
V_24 = F_8 ( V_12 , V_21 , V_32 , V_23 ) ;
break;
case V_34 :
V_24 = F_15 ( V_12 , V_21 , V_32 , V_23 ) ;
break;
default:
V_24 = - V_18 ;
}
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
if ( V_24 > 0 )
* V_23 += V_24 ;
return V_24 ;
}
static T_1 F_20 ( struct V_10 * V_10 , const char T_2 * V_21 ,
T_3 V_22 , T_4 * V_23 )
{
unsigned int V_12 = F_3 ( V_10 -> V_29 -> V_30 -> V_13 ) ;
T_1 V_24 ;
T_3 V_31 ;
T_3 V_32 ;
if ( V_12 == V_16 )
return 0 ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_31 = F_19 ( V_14 [ V_12 ] . V_17 ) ;
if ( ( * V_23 < 0 ) || ( * V_23 > ( V_31 - 1 ) ) ) {
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return 0 ;
}
if ( * V_23 + V_22 > V_31 )
V_32 = V_31 - * V_23 ;
else
V_32 = V_22 ;
switch ( type [ V_12 ] ) {
case V_33 :
V_24 = F_12 ( V_12 , V_21 , V_32 , V_23 ) ;
break;
case V_34 :
V_24 = F_17 ( V_12 , V_21 , V_32 , V_23 ) ;
break;
default:
V_24 = - V_18 ;
}
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
if ( V_24 > 0 )
* V_23 += V_24 ;
return V_24 ;
}
static T_4 F_21 ( struct V_10 * V_10 , T_4 V_35 , int V_36 )
{
T_4 V_37 = - 1 ;
unsigned int V_12 = F_3 ( V_10 -> V_29 -> V_30 -> V_13 ) ;
T_3 V_31 ;
if ( V_12 == V_16 )
return - V_18 ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_31 = F_19 ( V_14 [ V_12 ] . V_17 ) ;
switch ( V_36 ) {
case V_38 :
V_37 = V_35 ;
break;
case V_39 :
V_37 = V_10 -> V_40 + V_35 ;
break;
case V_41 :
V_37 = V_31 + V_35 ;
break;
default:
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return - V_18 ;
break;
}
if ( ( V_37 < 0 ) || ( V_37 >= V_31 ) ) {
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return - V_18 ;
}
V_10 -> V_40 = V_37 ;
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return V_37 ;
}
static int F_22 ( struct V_9 * V_9 , struct V_10 * V_10 ,
unsigned int V_42 , unsigned long V_43 )
{
struct V_44 V_45 ;
struct V_46 V_47 ;
struct V_48 V_49 ;
unsigned long V_25 ;
unsigned int V_12 = F_3 ( V_9 -> V_13 ) ;
int V_24 ;
T_5 V_50 ;
void T_2 * V_51 = ( void T_2 * ) V_43 ;
V_1 . V_4 ++ ;
switch ( type [ V_12 ] ) {
case V_16 :
switch ( V_42 ) {
case V_52 :
V_25 = F_23 ( & V_49 , V_51 ,
sizeof( struct V_48 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_5 ) ;
return - V_53 ;
}
V_24 = F_24 ( V_54 ,
V_49 . V_55 ,
V_49 . V_56 ) ;
return V_24 ;
}
break;
case V_33 :
switch ( V_42 ) {
case V_57 :
memset ( & V_45 , 0 , sizeof( struct V_44 ) ) ;
V_24 = F_25 ( V_14 [ V_12 ] . V_17 ,
& V_45 . V_58 , & V_45 . V_59 ,
& V_45 . V_60 , & V_45 . V_61 ,
& V_45 . V_62 , & V_45 . V_63 ) ;
V_25 = F_26 ( V_51 , & V_45 ,
sizeof( struct V_44 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_4 ) ;
return - V_53 ;
}
return V_24 ;
break;
case V_64 :
V_25 = F_23 ( & V_45 , V_51 , sizeof( V_45 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_5 ) ;
return - V_53 ;
}
return F_27 ( V_14 [ V_12 ] . V_17 ,
V_45 . V_58 , V_45 . V_59 , V_45 . V_60 ,
V_45 . V_61 , V_45 . V_62 , V_45 . V_63 ) ;
break;
}
break;
case V_34 :
switch ( V_42 ) {
case V_65 :
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_24 = F_28 ( V_14 [ V_12 ] . V_17 ,
& V_47 . V_58 , & V_47 . V_59 ,
& V_47 . V_60 , & V_50 , & V_47 . V_61 ,
& V_47 . V_62 ) ;
V_25 = F_26 ( V_51 , & V_47 ,
sizeof( struct V_46 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_4 ) ;
return - V_53 ;
}
return V_24 ;
break;
case V_66 :
V_25 = F_23 ( & V_47 , V_51 , sizeof( V_47 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_5 ) ;
return - V_53 ;
}
return F_29 ( V_14 [ V_12 ] . V_17 ,
V_47 . V_58 , V_47 . V_59 , V_47 . V_60 ,
V_14 [ V_12 ] . V_67 , V_47 . V_61 ,
V_47 . V_62 ) ;
break;
}
break;
}
return - V_18 ;
}
static long
F_30 ( struct V_10 * V_10 , unsigned int V_42 , unsigned long V_43 )
{
int V_68 ;
F_4 ( & V_69 ) ;
V_68 = F_22 ( V_10 -> V_70 . V_71 -> V_30 , V_10 , V_42 , V_43 ) ;
F_6 ( & V_69 ) ;
return V_68 ;
}
static void F_31 ( int V_72 )
{
if ( V_14 [ V_72 ] . V_27 ) {
#ifdef F_32
F_33 ( L_6 ,
V_14 [ V_72 ] . V_67 ) ;
#endif
F_34 ( V_14 [ V_72 ] . V_17 , V_14 [ V_72 ] . V_26 ,
V_14 [ V_72 ] . V_27 , V_14 [ V_72 ] . V_67 ) ;
V_14 [ V_72 ] . V_27 = NULL ;
V_14 [ V_72 ] . V_67 = 0 ;
V_14 [ V_72 ] . V_26 = 0 ;
#ifdef F_32
} else {
F_33 ( L_7 ) ;
#endif
}
}
static int T_6 F_35 ( void )
{
int V_24 = 0 ;
F_11 ( L_8 ) ;
if ( V_73 == 0 ) {
F_5 ( L_9 ) ;
V_24 = - V_74 ;
goto V_75;
}
if ( V_73 > V_76 ) {
F_5 ( L_10 ,
V_76 ) ;
V_73 = V_76 ;
}
V_24 = F_36 ( & V_77 , V_78 ) ;
if ( V_24 != 0 )
goto V_79;
return V_24 ;
V_79:
V_75:
return V_24 ;
}
static int F_37 ( struct V_80 * V_81 )
{
if ( V_81 -> V_72 >= V_76 )
return 0 ;
return 1 ;
}
static int F_38 ( struct V_80 * V_81 )
{
int V_82 , V_11 ;
char V_83 [ 12 ] ;
if ( V_54 != NULL ) {
F_39 ( & V_81 -> V_84 , L_11 ) ;
V_11 = - V_18 ;
goto V_85;
}
V_54 = V_81 ;
for ( V_82 = 0 ; V_82 < V_86 ; V_82 ++ ) {
V_14 [ V_82 ] . V_27 = NULL ;
V_14 [ V_82 ] . V_67 = 0 ;
F_40 ( & V_14 [ V_82 ] . V_15 ) ;
V_14 [ V_82 ] . V_87 = NULL ;
V_14 [ V_82 ] . V_17 = NULL ;
V_14 [ V_82 ] . V_20 = 0 ;
}
F_1 () ;
V_11 = F_41 ( F_42 ( V_88 , 0 ) , V_86 ,
V_89 ) ;
if ( V_11 ) {
F_43 ( & V_81 -> V_84 , L_12 ,
V_88 ) ;
goto V_90;
}
V_91 = F_44 () ;
V_91 -> V_92 = & V_93 ;
V_91 -> V_94 = V_95 ;
V_11 = F_45 ( V_91 , F_42 ( V_88 , 0 ) , V_86 ) ;
if ( V_11 ) {
F_43 ( & V_81 -> V_84 , L_13 ) ;
goto V_96;
}
for ( V_82 = V_34 ; V_82 < ( V_97 + 1 ) ; V_82 ++ ) {
V_14 [ V_82 ] . V_17 = F_46 ( V_54 ,
V_98 , V_99 ) ;
if ( V_14 [ V_82 ] . V_17 == NULL ) {
F_43 ( & V_81 -> V_84 ,
L_14 ) ;
goto V_100;
}
V_14 [ V_82 ] . V_26 = V_101 ;
V_14 [ V_82 ] . V_27 = F_47 ( V_14 [ V_82 ] . V_17 ,
V_14 [ V_82 ] . V_26 , & V_14 [ V_82 ] . V_67 ) ;
if ( V_14 [ V_82 ] . V_27 == NULL ) {
F_43 ( & V_81 -> V_84 ,
L_15 ) ;
V_14 [ V_82 ] . V_67 = 0 ;
F_48 ( V_14 [ V_82 ] . V_17 ) ;
V_11 = - V_102 ;
goto V_100;
}
}
for ( V_82 = V_33 ; V_82 < ( V_103 + 1 ) ; V_82 ++ ) {
V_14 [ V_82 ] . V_17 = F_49 ( V_54 ,
V_104 , V_99 , V_105 ) ;
if ( V_14 [ V_82 ] . V_17 == NULL ) {
F_43 ( & V_81 -> V_84 ,
L_16 ) ;
goto V_106;
}
V_14 [ V_82 ] . V_26 = V_101 ;
V_14 [ V_82 ] . V_27 = F_50 ( V_14 [ V_82 ] . V_26 , V_107 ) ;
if ( V_14 [ V_82 ] . V_27 == NULL ) {
F_43 ( & V_81 -> V_84 ,
L_17 ) ;
V_11 = - V_102 ;
goto V_108;
}
}
V_109 = F_51 ( V_95 , V_89 ) ;
if ( F_52 ( V_109 ) ) {
F_39 ( & V_81 -> V_84 , L_18 ) ;
V_11 = F_53 ( V_109 ) ;
goto V_110;
}
for ( V_82 = 0 ; V_82 < V_86 ; V_82 ++ ) {
int V_72 ;
switch ( type [ V_82 ] ) {
case V_33 :
sprintf ( V_83 , L_19 ) ;
break;
case V_16 :
sprintf ( V_83 , L_20 ) ;
break;
case V_34 :
sprintf ( V_83 , L_21 ) ;
break;
default:
V_11 = - V_18 ;
goto V_111;
break;
}
V_72 = ( type [ V_82 ] == V_34 ) ? V_82 - ( V_103 + 1 ) : V_82 ;
V_14 [ V_82 ] . V_87 = F_54 ( V_109 , NULL ,
F_42 ( V_88 , V_82 ) , NULL , V_83 , V_72 ) ;
if ( F_52 ( V_14 [ V_82 ] . V_87 ) ) {
F_55 ( & V_81 -> V_84 , L_22 ) ;
V_11 = F_53 ( V_14 [ V_82 ] . V_87 ) ;
goto V_111;
}
}
return 0 ;
V_82 = V_86 ;
V_111:
while ( V_82 > 0 ) {
V_82 -- ;
F_56 ( V_109 , F_42 ( V_88 , V_82 ) ) ;
}
F_57 ( V_109 ) ;
V_82 = V_103 + 1 ;
V_108:
for ( V_82 = V_33 ; V_82 < ( V_103 + 1 ) ; V_82 ++ )
F_58 ( V_14 [ V_82 ] . V_27 ) ;
V_106:
while ( V_82 > V_33 ) {
V_82 -- ;
F_59 ( V_14 [ V_82 ] . V_17 ) ;
}
V_82 = V_97 + 1 ;
V_100:
while ( V_82 > V_34 ) {
V_82 -- ;
F_31 ( V_82 ) ;
F_48 ( V_14 [ V_82 ] . V_17 ) ;
}
V_110:
F_60 ( V_91 ) ;
V_96:
F_61 ( F_42 ( V_88 , 0 ) , V_86 ) ;
V_90:
V_85:
return V_11 ;
}
static int F_62 ( struct V_80 * V_84 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 < V_86 ; V_82 ++ ) {
F_63 ( & V_14 [ V_82 ] . V_15 ) ;
F_56 ( V_109 , F_42 ( V_88 , V_82 ) ) ;
}
F_57 ( V_109 ) ;
for ( V_82 = V_33 ; V_82 < ( V_103 + 1 ) ; V_82 ++ ) {
F_58 ( V_14 [ V_82 ] . V_27 ) ;
F_59 ( V_14 [ V_82 ] . V_17 ) ;
}
for ( V_82 = V_34 ; V_82 < ( V_97 + 1 ) ; V_82 ++ ) {
F_29 ( V_14 [ V_82 ] . V_17 , 0 , 0 , 0 , 0 , V_104 , 0 ) ;
F_31 ( V_82 ) ;
F_48 ( V_14 [ V_82 ] . V_17 ) ;
}
F_60 ( V_91 ) ;
F_61 ( F_42 ( V_88 , 0 ) , V_86 ) ;
return 0 ;
}
static void T_7 F_64 ( void )
{
F_65 ( & V_77 ) ;
}
