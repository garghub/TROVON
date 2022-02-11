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
F_29 ( & V_72 ) ;
V_71 = F_20 ( V_10 -> V_73 . V_74 -> V_33 , V_10 , V_45 , V_46 ) ;
F_30 ( & V_72 ) ;
return V_71 ;
}
static void F_31 ( int V_75 )
{
if ( V_14 [ V_75 ] . V_28 ) {
#ifdef F_32
F_5 ( V_76 L_9 ,
V_14 [ V_75 ] . V_70 ) ;
#endif
F_33 ( V_14 [ V_75 ] . V_17 , V_14 [ V_75 ] . V_27 ,
V_14 [ V_75 ] . V_28 , V_14 [ V_75 ] . V_70 ) ;
V_14 [ V_75 ] . V_28 = NULL ;
V_14 [ V_75 ] . V_70 = 0 ;
V_14 [ V_75 ] . V_27 = 0 ;
#ifdef F_32
} else {
F_5 ( V_76 L_10 ) ;
#endif
}
}
static int T_6 F_34 ( void )
{
int V_25 = 0 ;
int V_77 ;
struct V_78 * V_79 ;
F_5 ( V_29 L_11 ) ;
if ( V_80 == 0 ) {
F_5 ( V_18 L_12 ,
V_81 ) ;
V_25 = - V_82 ;
goto V_83;
}
if ( V_80 > V_84 ) {
F_5 ( V_18 L_13 ,
V_81 , V_84 ) ;
V_80 = V_84 ;
}
V_79 = F_35 ( sizeof( struct V_78 ) * ( V_80 + 1 ) , V_85 ) ;
if ( V_79 == NULL ) {
F_5 ( V_18 L_14 ,
V_81 ) ;
V_25 = - V_86 ;
goto V_87;
}
memset ( V_79 , 0 , ( sizeof( struct V_78 ) * ( V_80 + 1 ) ) ) ;
for ( V_77 = 0 ; V_77 < V_80 ; V_77 ++ ) {
V_79 [ V_77 ] . V_88 = V_88 [ V_77 ] ;
V_79 [ V_77 ] . V_89 = V_90 ;
}
V_91 . V_92 = V_79 ;
V_25 = F_36 ( & V_91 ) ;
if ( V_25 != 0 )
goto V_93;
return V_25 ;
V_93:
F_37 ( V_79 ) ;
V_87:
V_83:
return V_25 ;
}
static int T_7 F_38 ( struct V_94 * V_95 , int V_96 ,
int V_97 )
{
int V_77 , V_11 ;
char V_98 [ 12 ] ;
if ( V_57 != NULL ) {
F_5 ( V_18 L_15 ,
V_81 ) ;
V_11 = - V_19 ;
goto V_99;
}
V_57 = V_95 ;
for ( V_77 = 0 ; V_77 < V_100 ; V_77 ++ ) {
V_14 [ V_77 ] . V_28 = NULL ;
V_14 [ V_77 ] . V_70 = 0 ;
F_39 ( & V_14 [ V_77 ] . V_15 , 1 ) ;
V_14 [ V_77 ] . V_94 = NULL ;
V_14 [ V_77 ] . V_17 = NULL ;
V_14 [ V_77 ] . V_21 = 0 ;
}
F_1 () ;
V_11 = F_40 ( F_41 ( V_101 , 0 ) , V_100 ,
V_81 ) ;
if ( V_11 ) {
F_5 ( V_31 L_16
L_17 , V_81 , V_101 ) ;
goto V_102;
}
V_103 = F_42 () ;
V_103 -> V_104 = & V_105 ;
V_103 -> V_106 = V_107 ;
V_11 = F_43 ( V_103 , F_41 ( V_101 , 0 ) , V_100 ) ;
if ( V_11 ) {
F_5 ( V_31 L_18 , V_81 ) ;
goto V_108;
}
for ( V_77 = V_37 ; V_77 < ( V_109 + 1 ) ; V_77 ++ ) {
V_14 [ V_77 ] . V_17 = F_44 ( V_57 ,
V_110 , V_111 ) ;
if ( V_14 [ V_77 ] . V_17 == NULL ) {
F_5 ( V_31 L_19
L_20 ) ;
goto V_112;
}
V_14 [ V_77 ] . V_27 = V_113 ;
V_14 [ V_77 ] . V_28 = F_45 ( V_14 [ V_77 ] . V_17 ,
V_14 [ V_77 ] . V_27 , & V_14 [ V_77 ] . V_70 ) ;
if ( V_14 [ V_77 ] . V_28 == NULL ) {
F_5 ( V_31 L_21
L_22 ) ;
V_14 [ V_77 ] . V_70 = 0 ;
F_46 ( V_14 [ V_77 ] . V_17 ) ;
V_11 = - V_86 ;
goto V_112;
}
}
for ( V_77 = V_36 ; V_77 < ( V_114 + 1 ) ; V_77 ++ ) {
V_14 [ V_77 ] . V_17 = F_47 ( V_57 ,
V_115 , V_111 , V_116 ) ;
if ( V_14 [ V_77 ] . V_17 == NULL ) {
F_5 ( V_31 L_23
L_20 ) ;
goto V_117;
}
V_14 [ V_77 ] . V_27 = V_113 ;
V_14 [ V_77 ] . V_28 = F_35 ( V_14 [ V_77 ] . V_27 , V_85 ) ;
if ( V_14 [ V_77 ] . V_28 == NULL ) {
F_5 ( V_31 L_21
L_24 ) ;
V_11 = - V_86 ;
goto V_118;
}
}
V_119 = F_48 ( V_107 , V_81 ) ;
if ( F_49 ( V_119 ) ) {
F_5 ( V_18 L_25 ) ;
V_11 = F_50 ( V_119 ) ;
goto V_120;
}
for ( V_77 = 0 ; V_77 < V_100 ; V_77 ++ ) {
int V_75 ;
switch ( type [ V_77 ] ) {
case V_36 :
sprintf ( V_98 , L_26 ) ;
break;
case V_16 :
sprintf ( V_98 , L_27 ) ;
break;
case V_37 :
sprintf ( V_98 , L_28 ) ;
break;
default:
V_11 = - V_19 ;
goto V_121;
break;
}
V_75 = ( type [ V_77 ] == V_37 ) ? V_77 - ( V_114 + 1 ) : V_77 ;
V_14 [ V_77 ] . V_94 = F_51 ( V_119 , NULL ,
F_41 ( V_101 , V_77 ) , NULL , V_98 , V_75 ) ;
if ( F_49 ( V_14 [ V_77 ] . V_94 ) ) {
F_5 ( V_29 L_29 ,
V_81 ) ;
V_11 = F_50 ( V_14 [ V_77 ] . V_94 ) ;
goto V_121;
}
}
return 0 ;
V_77 = V_100 ;
V_121:
while ( V_77 > 0 ) {
V_77 -- ;
F_52 ( V_119 , F_41 ( V_101 , V_77 ) ) ;
}
F_53 ( V_119 ) ;
V_77 = V_114 + 1 ;
V_118:
for ( V_77 = V_36 ; V_77 < ( V_114 + 1 ) ; V_77 ++ )
F_37 ( V_14 [ V_77 ] . V_28 ) ;
V_117:
while ( V_77 > V_36 ) {
V_77 -- ;
F_54 ( V_14 [ V_77 ] . V_17 ) ;
}
V_77 = V_109 + 1 ;
V_112:
while ( V_77 > V_37 ) {
V_77 -- ;
F_31 ( V_77 ) ;
F_46 ( V_14 [ V_77 ] . V_17 ) ;
}
V_120:
F_55 ( V_103 ) ;
V_108:
F_56 ( F_41 ( V_101 , 0 ) , V_100 ) ;
V_102:
V_99:
return V_11 ;
}
static int T_8 F_57 ( struct V_94 * V_95 , int V_96 ,
int V_97 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_100 ; V_77 ++ )
F_52 ( V_119 , F_41 ( V_101 , V_77 ) ) ;
F_53 ( V_119 ) ;
for ( V_77 = V_36 ; V_77 < ( V_114 + 1 ) ; V_77 ++ ) {
F_37 ( V_14 [ V_77 ] . V_28 ) ;
F_54 ( V_14 [ V_77 ] . V_17 ) ;
}
for ( V_77 = V_37 ; V_77 < ( V_109 + 1 ) ; V_77 ++ ) {
F_27 ( V_14 [ V_77 ] . V_17 , 0 , 0 , 0 , 0 , V_115 , 0 ) ;
F_31 ( V_77 ) ;
F_46 ( V_14 [ V_77 ] . V_17 ) ;
}
F_55 ( V_103 ) ;
F_56 ( F_41 ( V_101 , 0 ) , V_100 ) ;
return 0 ;
}
static void T_9 F_58 ( void )
{
F_59 ( & V_91 ) ;
F_37 ( V_91 . V_92 ) ;
}
