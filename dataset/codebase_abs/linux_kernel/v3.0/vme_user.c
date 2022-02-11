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
if ( V_14 [ V_12 ] . V_16 == NULL ) {
F_5 ( V_17 L_1 ) ;
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
V_25 = F_9 ( V_14 [ V_12 ] . V_16 ,
V_14 [ V_12 ] . V_27 , V_22 , * V_23 ) ;
if ( V_25 < 0 )
return ( int ) V_25 ;
V_24 = F_10 ( V_21 , V_14 [ V_12 ] . V_27 ,
( unsigned long ) V_25 ) ;
if ( V_24 != 0 ) {
V_25 = ( V_25 - V_24 ) ;
F_5 ( V_28 L_2 ) ;
return - V_18 ;
}
} else {
F_5 ( V_28 L_3 ) ;
return - V_18 ;
}
return V_25 ;
}
static T_1 F_11 ( unsigned int V_12 , const char T_2 * V_21 ,
T_3 V_22 , T_4 * V_23 )
{
T_1 V_24 ;
T_1 V_25 = 0 ;
if ( V_22 <= V_14 [ V_12 ] . V_26 ) {
V_24 = F_12 ( V_14 [ V_12 ] . V_27 , V_21 ,
( unsigned long ) V_22 ) ;
if ( V_24 != 0 )
V_25 = ( V_25 - V_24 ) ;
else
V_25 = V_22 ;
V_25 = F_13 ( V_14 [ V_12 ] . V_16 ,
V_14 [ V_12 ] . V_27 , V_25 , * V_23 ) ;
} else {
F_5 ( V_28 L_3 ) ;
return - V_18 ;
}
return V_25 ;
}
static T_1 F_14 ( unsigned int V_12 , char T_2 * V_21 ,
T_3 V_22 , T_4 * V_23 )
{
void * V_29 ;
T_1 V_24 ;
V_29 = V_14 [ V_12 ] . V_27 + * V_23 ;
V_24 = F_10 ( V_21 , V_29 , ( unsigned long ) V_22 ) ;
if ( V_24 != 0 ) {
V_24 = ( V_22 - V_24 ) ;
F_5 ( V_30 L_4 ) ;
} else
V_24 = V_22 ;
return V_24 ;
}
static T_1 F_15 ( unsigned int V_12 , const char T_2 * V_21 ,
T_3 V_22 , T_4 * V_23 )
{
void * V_29 ;
T_3 V_24 ;
V_29 = V_14 [ V_12 ] . V_27 + * V_23 ;
V_24 = F_12 ( V_29 , V_21 , ( unsigned long ) V_22 ) ;
if ( V_24 != 0 ) {
V_24 = ( V_22 - V_24 ) ;
F_5 ( V_30 L_4 ) ;
} else
V_24 = V_22 ;
return V_24 ;
}
static T_1 F_16 ( struct V_10 * V_10 , char T_2 * V_21 , T_3 V_22 ,
T_4 * V_23 )
{
unsigned int V_12 = F_3 ( V_10 -> V_31 -> V_32 -> V_13 ) ;
T_1 V_24 ;
T_3 V_33 ;
T_3 V_34 ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_33 = F_17 ( V_14 [ V_12 ] . V_16 ) ;
if ( ( * V_23 < 0 ) || ( * V_23 > ( V_33 - 1 ) ) ) {
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return 0 ;
}
if ( * V_23 + V_22 > V_33 )
V_34 = V_33 - * V_23 ;
else
V_34 = V_22 ;
switch ( type [ V_12 ] ) {
case V_35 :
V_24 = F_8 ( V_12 , V_21 , V_34 , V_23 ) ;
break;
case V_36 :
V_24 = F_14 ( V_12 , V_21 , V_34 , V_23 ) ;
break;
default:
V_24 = - V_18 ;
}
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
if ( V_24 > 0 )
* V_23 += V_24 ;
return V_24 ;
}
static T_1 F_18 ( struct V_10 * V_10 , const char T_2 * V_21 ,
T_3 V_22 , T_4 * V_23 )
{
unsigned int V_12 = F_3 ( V_10 -> V_31 -> V_32 -> V_13 ) ;
T_1 V_24 ;
T_3 V_33 ;
T_3 V_34 ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_33 = F_17 ( V_14 [ V_12 ] . V_16 ) ;
if ( ( * V_23 < 0 ) || ( * V_23 > ( V_33 - 1 ) ) ) {
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return 0 ;
}
if ( * V_23 + V_22 > V_33 )
V_34 = V_33 - * V_23 ;
else
V_34 = V_22 ;
switch ( type [ V_12 ] ) {
case V_35 :
V_24 = F_11 ( V_12 , V_21 , V_34 , V_23 ) ;
break;
case V_36 :
V_24 = F_15 ( V_12 , V_21 , V_34 , V_23 ) ;
break;
default:
V_24 = - V_18 ;
}
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
if ( V_24 > 0 )
* V_23 += V_24 ;
return V_24 ;
}
static T_4 F_19 ( struct V_10 * V_10 , T_4 V_37 , int V_38 )
{
T_4 V_39 = - 1 ;
unsigned int V_12 = F_3 ( V_10 -> V_31 -> V_32 -> V_13 ) ;
T_3 V_33 ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_33 = F_17 ( V_14 [ V_12 ] . V_16 ) ;
switch ( V_38 ) {
case V_40 :
V_39 = V_37 ;
break;
case V_41 :
V_39 = V_10 -> V_42 + V_37 ;
break;
case V_43 :
V_39 = V_33 + V_37 ;
break;
default:
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return - V_18 ;
break;
}
if ( ( V_39 < 0 ) || ( V_39 >= V_33 ) ) {
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return - V_18 ;
}
V_10 -> V_42 = V_39 ;
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return V_39 ;
}
static int F_20 ( struct V_9 * V_9 , struct V_10 * V_10 ,
unsigned int V_44 , unsigned long V_45 )
{
struct V_46 V_47 ;
struct V_48 V_49 ;
unsigned long V_25 ;
unsigned int V_12 = F_3 ( V_9 -> V_13 ) ;
int V_24 ;
T_5 V_50 ;
void T_2 * V_51 = ( void T_2 * ) V_45 ;
V_1 . V_4 ++ ;
switch ( type [ V_12 ] ) {
case V_52 :
break;
case V_35 :
switch ( V_44 ) {
case V_53 :
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_24 = F_21 ( V_14 [ V_12 ] . V_16 ,
& V_47 . V_54 , & V_47 . V_55 ,
& V_47 . V_56 , & V_47 . V_57 ,
& V_47 . V_58 , & V_47 . V_59 ) ;
V_25 = F_22 ( V_51 , & V_47 ,
sizeof( struct V_46 ) ) ;
if ( V_25 != 0 ) {
F_5 ( V_30 L_5
L_6 ) ;
return - V_60 ;
}
return V_24 ;
break;
case V_61 :
V_25 = F_23 ( & V_47 , V_51 , sizeof( V_47 ) ) ;
if ( V_25 != 0 ) {
F_5 ( V_30 L_7
L_6 ) ;
return - V_60 ;
}
return F_24 ( V_14 [ V_12 ] . V_16 ,
V_47 . V_54 , V_47 . V_55 , V_47 . V_56 ,
V_47 . V_57 , V_47 . V_58 , V_47 . V_59 ) ;
break;
}
break;
case V_36 :
switch ( V_44 ) {
case V_62 :
memset ( & V_49 , 0 , sizeof( struct V_48 ) ) ;
V_24 = F_25 ( V_14 [ V_12 ] . V_16 ,
& V_49 . V_54 , & V_49 . V_55 ,
& V_49 . V_56 , & V_50 , & V_49 . V_57 ,
& V_49 . V_58 ) ;
V_25 = F_22 ( V_51 , & V_49 ,
sizeof( struct V_48 ) ) ;
if ( V_25 != 0 ) {
F_5 ( V_30 L_5
L_6 ) ;
return - V_60 ;
}
return V_24 ;
break;
case V_63 :
V_25 = F_23 ( & V_49 , V_51 , sizeof( V_49 ) ) ;
if ( V_25 != 0 ) {
F_5 ( V_30 L_7
L_6 ) ;
return - V_60 ;
}
return F_26 ( V_14 [ V_12 ] . V_16 ,
V_49 . V_54 , V_49 . V_55 , V_49 . V_56 ,
V_14 [ V_12 ] . V_64 , V_49 . V_57 ,
V_49 . V_58 ) ;
break;
}
break;
}
return - V_18 ;
}
static long
F_27 ( struct V_10 * V_10 , unsigned int V_44 , unsigned long V_45 )
{
int V_65 ;
F_28 ( & V_66 ) ;
V_65 = F_20 ( V_10 -> V_67 . V_68 -> V_32 , V_10 , V_44 , V_45 ) ;
F_29 ( & V_66 ) ;
return V_65 ;
}
static void F_30 ( int V_69 )
{
if ( V_14 [ V_69 ] . V_27 ) {
#ifdef F_31
F_5 ( V_70 L_8 ,
V_14 [ V_69 ] . V_64 ) ;
#endif
F_32 ( V_14 [ V_69 ] . V_16 , V_14 [ V_69 ] . V_26 ,
V_14 [ V_69 ] . V_27 , V_14 [ V_69 ] . V_64 ) ;
V_14 [ V_69 ] . V_27 = NULL ;
V_14 [ V_69 ] . V_64 = 0 ;
V_14 [ V_69 ] . V_26 = 0 ;
#ifdef F_31
} else {
F_5 ( V_70 L_9 ) ;
#endif
}
}
static int T_6 F_33 ( void )
{
int V_24 = 0 ;
int V_71 ;
struct V_72 * V_73 ;
F_5 ( V_28 L_10 ) ;
if ( V_74 == 0 ) {
F_5 ( V_17 L_11 ,
V_75 ) ;
V_24 = - V_76 ;
goto V_77;
}
if ( V_74 > V_78 ) {
F_5 ( V_17 L_12 ,
V_75 , V_78 ) ;
V_74 = V_78 ;
}
V_73 = F_34 ( sizeof( struct V_72 ) * ( V_74 + 1 ) , V_79 ) ;
if ( V_73 == NULL ) {
F_5 ( V_17 L_13 ,
V_75 ) ;
V_24 = - V_80 ;
goto V_81;
}
memset ( V_73 , 0 , ( sizeof( struct V_72 ) * ( V_74 + 1 ) ) ) ;
for ( V_71 = 0 ; V_71 < V_74 ; V_71 ++ ) {
V_73 [ V_71 ] . V_82 = V_82 [ V_71 ] ;
V_73 [ V_71 ] . V_83 = V_84 ;
}
V_85 . V_86 = V_73 ;
V_24 = F_35 ( & V_85 ) ;
if ( V_24 != 0 )
goto V_87;
return V_24 ;
V_87:
F_36 ( V_73 ) ;
V_81:
V_77:
return V_24 ;
}
static int T_7 F_37 ( struct V_88 * V_89 , int V_90 ,
int V_91 )
{
int V_71 , V_11 ;
char V_92 [ 12 ] ;
if ( V_93 != NULL ) {
F_5 ( V_17 L_14 ,
V_75 ) ;
V_11 = - V_18 ;
goto V_94;
}
V_93 = V_89 ;
for ( V_71 = 0 ; V_71 < V_95 ; V_71 ++ ) {
V_14 [ V_71 ] . V_27 = NULL ;
V_14 [ V_71 ] . V_64 = 0 ;
F_38 ( & V_14 [ V_71 ] . V_15 , 1 ) ;
V_14 [ V_71 ] . V_88 = NULL ;
V_14 [ V_71 ] . V_16 = NULL ;
V_14 [ V_71 ] . V_20 = 0 ;
}
F_1 () ;
V_11 = F_39 ( F_40 ( V_96 , 0 ) , V_95 ,
V_75 ) ;
if ( V_11 ) {
F_5 ( V_30 L_15
L_16 , V_75 , V_96 ) ;
goto V_97;
}
V_98 = F_41 () ;
V_98 -> V_99 = & V_100 ;
V_98 -> V_101 = V_102 ;
V_11 = F_42 ( V_98 , F_40 ( V_96 , 0 ) , V_95 ) ;
if ( V_11 ) {
F_5 ( V_30 L_17 , V_75 ) ;
goto V_103;
}
for ( V_71 = V_36 ; V_71 < ( V_104 + 1 ) ; V_71 ++ ) {
V_14 [ V_71 ] . V_16 = F_43 ( V_93 ,
V_105 , V_106 ) ;
if ( V_14 [ V_71 ] . V_16 == NULL ) {
F_5 ( V_30 L_18
L_19 ) ;
goto V_107;
}
V_14 [ V_71 ] . V_26 = V_108 ;
V_14 [ V_71 ] . V_27 = F_44 ( V_14 [ V_71 ] . V_16 ,
V_14 [ V_71 ] . V_26 , & V_14 [ V_71 ] . V_64 ) ;
if ( V_14 [ V_71 ] . V_27 == NULL ) {
F_5 ( V_30 L_20
L_21 ) ;
V_14 [ V_71 ] . V_64 = 0 ;
F_45 ( V_14 [ V_71 ] . V_16 ) ;
V_11 = - V_80 ;
goto V_107;
}
}
for ( V_71 = V_35 ; V_71 < ( V_109 + 1 ) ; V_71 ++ ) {
V_14 [ V_71 ] . V_16 = F_46 ( V_93 ,
V_110 , V_106 , V_111 ) ;
if ( V_14 [ V_71 ] . V_16 == NULL ) {
F_5 ( V_30 L_22
L_19 ) ;
goto V_112;
}
V_14 [ V_71 ] . V_26 = V_108 ;
V_14 [ V_71 ] . V_27 = F_34 ( V_14 [ V_71 ] . V_26 , V_79 ) ;
if ( V_14 [ V_71 ] . V_27 == NULL ) {
F_5 ( V_30 L_20
L_23 ) ;
V_11 = - V_80 ;
goto V_113;
}
}
V_114 = F_47 ( V_102 , V_75 ) ;
if ( F_48 ( V_114 ) ) {
F_5 ( V_17 L_24 ) ;
V_11 = F_49 ( V_114 ) ;
goto V_115;
}
for ( V_71 = 0 ; V_71 < V_95 ; V_71 ++ ) {
switch ( type [ V_71 ] ) {
case V_35 :
sprintf ( V_92 , L_25 ) ;
break;
case V_52 :
sprintf ( V_92 , L_26 ) ;
break;
case V_36 :
sprintf ( V_92 , L_27 ) ;
break;
default:
V_11 = - V_18 ;
goto V_116;
break;
}
V_14 [ V_71 ] . V_88 =
F_50 ( V_114 , NULL ,
F_40 ( V_96 , V_71 ) , NULL , V_92 ,
( type [ V_71 ] == V_36 ) ? V_71 - ( V_109 + 1 ) : V_71 ) ;
if ( F_48 ( V_14 [ V_71 ] . V_88 ) ) {
F_5 ( V_28 L_28 ,
V_75 ) ;
V_11 = F_49 ( V_14 [ V_71 ] . V_88 ) ;
goto V_116;
}
}
return 0 ;
V_71 = V_95 ;
V_116:
while ( V_71 > 0 ) {
V_71 -- ;
F_51 ( V_114 , F_40 ( V_96 , V_71 ) ) ;
}
F_52 ( V_114 ) ;
V_71 = V_109 + 1 ;
V_113:
for ( V_71 = V_35 ; V_71 < ( V_109 + 1 ) ; V_71 ++ )
F_36 ( V_14 [ V_71 ] . V_27 ) ;
V_112:
while ( V_71 > V_35 ) {
V_71 -- ;
F_53 ( V_14 [ V_71 ] . V_16 ) ;
}
V_71 = V_104 + 1 ;
V_107:
while ( V_71 > V_36 ) {
V_71 -- ;
F_30 ( V_71 ) ;
F_45 ( V_14 [ V_71 ] . V_16 ) ;
}
V_115:
F_54 ( V_98 ) ;
V_103:
F_55 ( F_40 ( V_96 , 0 ) , V_95 ) ;
V_97:
V_94:
return V_11 ;
}
static int T_8 F_56 ( struct V_88 * V_89 , int V_90 ,
int V_91 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_95 ; V_71 ++ )
F_51 ( V_114 , F_40 ( V_96 , V_71 ) ) ;
F_52 ( V_114 ) ;
for ( V_71 = V_35 ; V_71 < ( V_109 + 1 ) ; V_71 ++ ) {
F_36 ( V_14 [ V_71 ] . V_27 ) ;
F_53 ( V_14 [ V_71 ] . V_16 ) ;
}
for ( V_71 = V_36 ; V_71 < ( V_104 + 1 ) ; V_71 ++ ) {
F_26 ( V_14 [ V_71 ] . V_16 , 0 , 0 , 0 , 0 , V_110 , 0 ) ;
F_30 ( V_71 ) ;
F_45 ( V_14 [ V_71 ] . V_16 ) ;
}
F_54 ( V_98 ) ;
F_55 ( F_40 ( V_96 , 0 ) , V_95 ) ;
return 0 ;
}
static void T_9 F_57 ( void )
{
F_58 ( & V_85 ) ;
F_36 ( V_85 . V_86 ) ;
}
