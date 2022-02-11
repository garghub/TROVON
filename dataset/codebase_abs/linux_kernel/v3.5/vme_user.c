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
F_5 ( V_18 L_1 ) ;
V_11 = - V_19 ;
goto V_20;
}
V_14 [ V_12 ] . V_21 ++ ;
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return 0 ;
V_20:
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return V_11 ;
}
static int F_7 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
unsigned int V_12 = F_3 ( V_9 -> V_13 ) ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_14 [ V_12 ] . V_21 -- ;
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return 0 ;
}
static T_1 F_8 ( int V_12 , char T_2 * V_22 , T_3 V_23 ,
T_4 * V_24 )
{
T_1 V_25 ;
T_1 V_26 = 0 ;
if ( V_23 <= V_14 [ V_12 ] . V_27 ) {
V_26 = F_9 ( V_14 [ V_12 ] . V_17 ,
V_14 [ V_12 ] . V_28 , V_23 , * V_24 ) ;
if ( V_26 < 0 )
return ( int ) V_26 ;
V_25 = F_10 ( V_22 , V_14 [ V_12 ] . V_28 ,
( unsigned long ) V_26 ) ;
if ( V_25 != 0 ) {
V_26 = ( V_26 - V_25 ) ;
F_5 ( V_29 L_2 ) ;
return - V_19 ;
}
} else {
F_5 ( V_29 L_3 ) ;
return - V_19 ;
}
return V_26 ;
}
static T_1 F_11 ( unsigned int V_12 , const char T_2 * V_22 ,
T_3 V_23 , T_4 * V_24 )
{
T_1 V_25 ;
T_1 V_26 = 0 ;
if ( V_23 <= V_14 [ V_12 ] . V_27 ) {
V_25 = F_12 ( V_14 [ V_12 ] . V_28 , V_22 ,
( unsigned long ) V_23 ) ;
if ( V_25 != 0 )
V_26 = ( V_26 - V_25 ) ;
else
V_26 = V_23 ;
V_26 = F_13 ( V_14 [ V_12 ] . V_17 ,
V_14 [ V_12 ] . V_28 , V_26 , * V_24 ) ;
} else {
F_5 ( V_29 L_3 ) ;
return - V_19 ;
}
return V_26 ;
}
static T_1 F_14 ( unsigned int V_12 , char T_2 * V_22 ,
T_3 V_23 , T_4 * V_24 )
{
void * V_30 ;
T_1 V_25 ;
V_30 = V_14 [ V_12 ] . V_28 + * V_24 ;
V_25 = F_10 ( V_22 , V_30 , ( unsigned long ) V_23 ) ;
if ( V_25 != 0 ) {
V_25 = ( V_23 - V_25 ) ;
F_5 ( V_31 L_4 ) ;
} else
V_25 = V_23 ;
return V_25 ;
}
static T_1 F_15 ( unsigned int V_12 , const char T_2 * V_22 ,
T_3 V_23 , T_4 * V_24 )
{
void * V_30 ;
T_3 V_25 ;
V_30 = V_14 [ V_12 ] . V_28 + * V_24 ;
V_25 = F_12 ( V_30 , V_22 , ( unsigned long ) V_23 ) ;
if ( V_25 != 0 ) {
V_25 = ( V_23 - V_25 ) ;
F_5 ( V_31 L_4 ) ;
} else
V_25 = V_23 ;
return V_25 ;
}
static T_1 F_16 ( struct V_10 * V_10 , char T_2 * V_22 , T_3 V_23 ,
T_4 * V_24 )
{
unsigned int V_12 = F_3 ( V_10 -> V_32 -> V_33 -> V_13 ) ;
T_1 V_25 ;
T_3 V_34 ;
T_3 V_35 ;
if ( V_12 == V_16 )
return 0 ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_34 = F_17 ( V_14 [ V_12 ] . V_17 ) ;
if ( ( * V_24 < 0 ) || ( * V_24 > ( V_34 - 1 ) ) ) {
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return 0 ;
}
if ( * V_24 + V_23 > V_34 )
V_35 = V_34 - * V_24 ;
else
V_35 = V_23 ;
switch ( type [ V_12 ] ) {
case V_36 :
V_25 = F_8 ( V_12 , V_22 , V_35 , V_24 ) ;
break;
case V_37 :
V_25 = F_14 ( V_12 , V_22 , V_35 , V_24 ) ;
break;
default:
V_25 = - V_19 ;
}
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
if ( V_25 > 0 )
* V_24 += V_25 ;
return V_25 ;
}
static T_1 F_18 ( struct V_10 * V_10 , const char T_2 * V_22 ,
T_3 V_23 , T_4 * V_24 )
{
unsigned int V_12 = F_3 ( V_10 -> V_32 -> V_33 -> V_13 ) ;
T_1 V_25 ;
T_3 V_34 ;
T_3 V_35 ;
if ( V_12 == V_16 )
return 0 ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_34 = F_17 ( V_14 [ V_12 ] . V_17 ) ;
if ( ( * V_24 < 0 ) || ( * V_24 > ( V_34 - 1 ) ) ) {
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return 0 ;
}
if ( * V_24 + V_23 > V_34 )
V_35 = V_34 - * V_24 ;
else
V_35 = V_23 ;
switch ( type [ V_12 ] ) {
case V_36 :
V_25 = F_11 ( V_12 , V_22 , V_35 , V_24 ) ;
break;
case V_37 :
V_25 = F_15 ( V_12 , V_22 , V_35 , V_24 ) ;
break;
default:
V_25 = - V_19 ;
}
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
if ( V_25 > 0 )
* V_24 += V_25 ;
return V_25 ;
}
static T_4 F_19 ( struct V_10 * V_10 , T_4 V_38 , int V_39 )
{
T_4 V_40 = - 1 ;
unsigned int V_12 = F_3 ( V_10 -> V_32 -> V_33 -> V_13 ) ;
T_3 V_34 ;
if ( V_12 == V_16 )
return - V_19 ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_34 = F_17 ( V_14 [ V_12 ] . V_17 ) ;
switch ( V_39 ) {
case V_41 :
V_40 = V_38 ;
break;
case V_42 :
V_40 = V_10 -> V_43 + V_38 ;
break;
case V_44 :
V_40 = V_34 + V_38 ;
break;
default:
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return - V_19 ;
break;
}
if ( ( V_40 < 0 ) || ( V_40 >= V_34 ) ) {
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return - V_19 ;
}
V_10 -> V_43 = V_40 ;
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return V_40 ;
}
static int F_20 ( struct V_9 * V_9 , struct V_10 * V_10 ,
unsigned int V_45 , unsigned long V_46 )
{
struct V_47 V_48 ;
struct V_49 V_50 ;
struct V_51 V_52 ;
unsigned long V_26 ;
unsigned int V_12 = F_3 ( V_9 -> V_13 ) ;
int V_25 ;
T_5 V_53 ;
void T_2 * V_54 = ( void T_2 * ) V_46 ;
V_1 . V_4 ++ ;
switch ( type [ V_12 ] ) {
case V_16 :
switch ( V_45 ) {
case V_55 :
V_26 = F_21 ( & V_52 , ( char * ) V_46 ,
sizeof( struct V_51 ) ) ;
if ( V_26 != 0 ) {
F_5 ( V_31 L_5 ) ;
return - V_56 ;
}
V_25 = F_22 ( V_57 ,
V_52 . V_58 ,
V_52 . V_59 ) ;
return V_25 ;
}
break;
case V_36 :
switch ( V_45 ) {
case V_60 :
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_25 = F_23 ( V_14 [ V_12 ] . V_17 ,
& V_48 . V_61 , & V_48 . V_62 ,
& V_48 . V_63 , & V_48 . V_64 ,
& V_48 . V_65 , & V_48 . V_66 ) ;
V_26 = F_24 ( V_54 , & V_48 ,
sizeof( struct V_47 ) ) ;
if ( V_26 != 0 ) {
F_5 ( V_31 L_6
L_7 ) ;
return - V_56 ;
}
return V_25 ;
break;
case V_67 :
V_26 = F_21 ( & V_48 , V_54 , sizeof( V_48 ) ) ;
if ( V_26 != 0 ) {
F_5 ( V_31 L_8
L_7 ) ;
return - V_56 ;
}
return F_25 ( V_14 [ V_12 ] . V_17 ,
V_48 . V_61 , V_48 . V_62 , V_48 . V_63 ,
V_48 . V_64 , V_48 . V_65 , V_48 . V_66 ) ;
break;
}
break;
case V_37 :
switch ( V_45 ) {
case V_68 :
memset ( & V_50 , 0 , sizeof( struct V_49 ) ) ;
V_25 = F_26 ( V_14 [ V_12 ] . V_17 ,
& V_50 . V_61 , & V_50 . V_62 ,
& V_50 . V_63 , & V_53 , & V_50 . V_64 ,
& V_50 . V_65 ) ;
V_26 = F_24 ( V_54 , & V_50 ,
sizeof( struct V_49 ) ) ;
if ( V_26 != 0 ) {
F_5 ( V_31 L_6
L_7 ) ;
return - V_56 ;
}
return V_25 ;
break;
case V_69 :
V_26 = F_21 ( & V_50 , V_54 , sizeof( V_50 ) ) ;
if ( V_26 != 0 ) {
F_5 ( V_31 L_8
L_7 ) ;
return - V_56 ;
}
return F_27 ( V_14 [ V_12 ] . V_17 ,
V_50 . V_61 , V_50 . V_62 , V_50 . V_63 ,
V_14 [ V_12 ] . V_70 , V_50 . V_64 ,
V_50 . V_65 ) ;
break;
}
break;
}
return - V_19 ;
}
static long
F_28 ( struct V_10 * V_10 , unsigned int V_45 , unsigned long V_46 )
{
int V_71 ;
F_4 ( & V_72 ) ;
V_71 = F_20 ( V_10 -> V_73 . V_74 -> V_33 , V_10 , V_45 , V_46 ) ;
F_6 ( & V_72 ) ;
return V_71 ;
}
static void F_29 ( int V_75 )
{
if ( V_14 [ V_75 ] . V_28 ) {
#ifdef F_30
F_5 ( V_76 L_9 ,
V_14 [ V_75 ] . V_70 ) ;
#endif
F_31 ( V_14 [ V_75 ] . V_17 , V_14 [ V_75 ] . V_27 ,
V_14 [ V_75 ] . V_28 , V_14 [ V_75 ] . V_70 ) ;
V_14 [ V_75 ] . V_28 = NULL ;
V_14 [ V_75 ] . V_70 = 0 ;
V_14 [ V_75 ] . V_27 = 0 ;
#ifdef F_30
} else {
F_5 ( V_76 L_10 ) ;
#endif
}
}
static int T_6 F_32 ( void )
{
int V_25 = 0 ;
F_5 ( V_29 L_11 ) ;
if ( V_77 == 0 ) {
F_5 ( V_18 L_12 ,
V_78 ) ;
V_25 = - V_79 ;
goto V_80;
}
if ( V_77 > V_81 ) {
F_5 ( V_18 L_13 ,
V_78 , V_81 ) ;
V_77 = V_81 ;
}
V_25 = F_33 ( & V_82 , V_83 ) ;
if ( V_25 != 0 )
goto V_84;
return V_25 ;
V_84:
V_80:
return V_25 ;
}
static int F_34 ( struct V_85 * V_86 )
{
if ( V_86 -> V_75 >= V_81 )
return 0 ;
return 1 ;
}
static int T_7 F_35 ( struct V_85 * V_86 )
{
int V_87 , V_11 ;
char V_88 [ 12 ] ;
if ( V_57 != NULL ) {
F_5 ( V_18 L_14 ,
V_78 ) ;
V_11 = - V_19 ;
goto V_89;
}
V_57 = V_86 ;
for ( V_87 = 0 ; V_87 < V_90 ; V_87 ++ ) {
V_14 [ V_87 ] . V_28 = NULL ;
V_14 [ V_87 ] . V_70 = 0 ;
F_36 ( & V_14 [ V_87 ] . V_15 ) ;
V_14 [ V_87 ] . V_91 = NULL ;
V_14 [ V_87 ] . V_17 = NULL ;
V_14 [ V_87 ] . V_21 = 0 ;
}
F_1 () ;
V_11 = F_37 ( F_38 ( V_92 , 0 ) , V_90 ,
V_78 ) ;
if ( V_11 ) {
F_5 ( V_31 L_15
L_16 , V_78 , V_92 ) ;
goto V_93;
}
V_94 = F_39 () ;
V_94 -> V_95 = & V_96 ;
V_94 -> V_97 = V_98 ;
V_11 = F_40 ( V_94 , F_38 ( V_92 , 0 ) , V_90 ) ;
if ( V_11 ) {
F_5 ( V_31 L_17 , V_78 ) ;
goto V_99;
}
for ( V_87 = V_37 ; V_87 < ( V_100 + 1 ) ; V_87 ++ ) {
V_14 [ V_87 ] . V_17 = F_41 ( V_57 ,
V_101 , V_102 ) ;
if ( V_14 [ V_87 ] . V_17 == NULL ) {
F_5 ( V_31 L_18
L_19 ) ;
goto V_103;
}
V_14 [ V_87 ] . V_27 = V_104 ;
V_14 [ V_87 ] . V_28 = F_42 ( V_14 [ V_87 ] . V_17 ,
V_14 [ V_87 ] . V_27 , & V_14 [ V_87 ] . V_70 ) ;
if ( V_14 [ V_87 ] . V_28 == NULL ) {
F_5 ( V_31 L_20
L_21 ) ;
V_14 [ V_87 ] . V_70 = 0 ;
F_43 ( V_14 [ V_87 ] . V_17 ) ;
V_11 = - V_105 ;
goto V_103;
}
}
for ( V_87 = V_36 ; V_87 < ( V_106 + 1 ) ; V_87 ++ ) {
V_14 [ V_87 ] . V_17 = F_44 ( V_57 ,
V_107 , V_102 , V_108 ) ;
if ( V_14 [ V_87 ] . V_17 == NULL ) {
F_5 ( V_31 L_22
L_19 ) ;
goto V_109;
}
V_14 [ V_87 ] . V_27 = V_104 ;
V_14 [ V_87 ] . V_28 = F_45 ( V_14 [ V_87 ] . V_27 , V_110 ) ;
if ( V_14 [ V_87 ] . V_28 == NULL ) {
F_5 ( V_31 L_20
L_23 ) ;
V_11 = - V_105 ;
goto V_111;
}
}
V_112 = F_46 ( V_98 , V_78 ) ;
if ( F_47 ( V_112 ) ) {
F_5 ( V_18 L_24 ) ;
V_11 = F_48 ( V_112 ) ;
goto V_113;
}
for ( V_87 = 0 ; V_87 < V_90 ; V_87 ++ ) {
int V_75 ;
switch ( type [ V_87 ] ) {
case V_36 :
sprintf ( V_88 , L_25 ) ;
break;
case V_16 :
sprintf ( V_88 , L_26 ) ;
break;
case V_37 :
sprintf ( V_88 , L_27 ) ;
break;
default:
V_11 = - V_19 ;
goto V_114;
break;
}
V_75 = ( type [ V_87 ] == V_37 ) ? V_87 - ( V_106 + 1 ) : V_87 ;
V_14 [ V_87 ] . V_91 = F_49 ( V_112 , NULL ,
F_38 ( V_92 , V_87 ) , NULL , V_88 , V_75 ) ;
if ( F_47 ( V_14 [ V_87 ] . V_91 ) ) {
F_5 ( V_29 L_28 ,
V_78 ) ;
V_11 = F_48 ( V_14 [ V_87 ] . V_91 ) ;
goto V_114;
}
}
return 0 ;
V_87 = V_90 ;
V_114:
while ( V_87 > 0 ) {
V_87 -- ;
F_50 ( V_112 , F_38 ( V_92 , V_87 ) ) ;
}
F_51 ( V_112 ) ;
V_87 = V_106 + 1 ;
V_111:
for ( V_87 = V_36 ; V_87 < ( V_106 + 1 ) ; V_87 ++ )
F_52 ( V_14 [ V_87 ] . V_28 ) ;
V_109:
while ( V_87 > V_36 ) {
V_87 -- ;
F_53 ( V_14 [ V_87 ] . V_17 ) ;
}
V_87 = V_100 + 1 ;
V_103:
while ( V_87 > V_37 ) {
V_87 -- ;
F_29 ( V_87 ) ;
F_43 ( V_14 [ V_87 ] . V_17 ) ;
}
V_113:
F_54 ( V_94 ) ;
V_99:
F_55 ( F_38 ( V_92 , 0 ) , V_90 ) ;
V_93:
V_89:
return V_11 ;
}
static int T_8 F_56 ( struct V_85 * V_115 )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_90 ; V_87 ++ ) {
F_57 ( & V_14 [ V_87 ] . V_15 ) ;
F_50 ( V_112 , F_38 ( V_92 , V_87 ) ) ;
}
F_51 ( V_112 ) ;
for ( V_87 = V_36 ; V_87 < ( V_106 + 1 ) ; V_87 ++ ) {
F_52 ( V_14 [ V_87 ] . V_28 ) ;
F_53 ( V_14 [ V_87 ] . V_17 ) ;
}
for ( V_87 = V_37 ; V_87 < ( V_100 + 1 ) ; V_87 ++ ) {
F_27 ( V_14 [ V_87 ] . V_17 , 0 , 0 , 0 , 0 , V_107 , 0 ) ;
F_29 ( V_87 ) ;
F_43 ( V_14 [ V_87 ] . V_17 ) ;
}
F_54 ( V_94 ) ;
F_55 ( F_38 ( V_92 , 0 ) , V_90 ) ;
return 0 ;
}
static void T_9 F_58 ( void )
{
F_59 ( & V_82 ) ;
}
