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
unsigned int V_12 = F_3 ( F_19 ( V_10 ) -> V_13 ) ;
T_1 V_24 ;
T_3 V_29 ;
T_3 V_30 ;
if ( V_12 == V_16 )
return 0 ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_29 = F_20 ( V_14 [ V_12 ] . V_17 ) ;
if ( ( * V_23 < 0 ) || ( * V_23 > ( V_29 - 1 ) ) ) {
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return 0 ;
}
if ( * V_23 + V_22 > V_29 )
V_30 = V_29 - * V_23 ;
else
V_30 = V_22 ;
switch ( type [ V_12 ] ) {
case V_31 :
V_24 = F_8 ( V_12 , V_21 , V_30 , V_23 ) ;
break;
case V_32 :
V_24 = F_15 ( V_12 , V_21 , V_30 , V_23 ) ;
break;
default:
V_24 = - V_18 ;
}
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
if ( V_24 > 0 )
* V_23 += V_24 ;
return V_24 ;
}
static T_1 F_21 ( struct V_10 * V_10 , const char T_2 * V_21 ,
T_3 V_22 , T_4 * V_23 )
{
unsigned int V_12 = F_3 ( F_19 ( V_10 ) -> V_13 ) ;
T_1 V_24 ;
T_3 V_29 ;
T_3 V_30 ;
if ( V_12 == V_16 )
return 0 ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_29 = F_20 ( V_14 [ V_12 ] . V_17 ) ;
if ( ( * V_23 < 0 ) || ( * V_23 > ( V_29 - 1 ) ) ) {
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return 0 ;
}
if ( * V_23 + V_22 > V_29 )
V_30 = V_29 - * V_23 ;
else
V_30 = V_22 ;
switch ( type [ V_12 ] ) {
case V_31 :
V_24 = F_12 ( V_12 , V_21 , V_30 , V_23 ) ;
break;
case V_32 :
V_24 = F_17 ( V_12 , V_21 , V_30 , V_23 ) ;
break;
default:
V_24 = - V_18 ;
}
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
if ( V_24 > 0 )
* V_23 += V_24 ;
return V_24 ;
}
static T_4 F_22 ( struct V_10 * V_10 , T_4 V_33 , int V_34 )
{
unsigned int V_12 = F_3 ( F_19 ( V_10 ) -> V_13 ) ;
T_3 V_29 ;
T_4 V_35 ;
if ( V_12 == V_16 )
return - V_18 ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_29 = F_20 ( V_14 [ V_12 ] . V_17 ) ;
V_35 = F_23 ( V_10 , V_33 , V_34 , V_29 ) ;
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return V_35 ;
}
static int F_24 ( struct V_9 * V_9 , struct V_10 * V_10 ,
unsigned int V_36 , unsigned long V_37 )
{
struct V_38 V_39 ;
struct V_40 V_41 ;
struct V_42 V_43 ;
unsigned long V_25 ;
unsigned int V_12 = F_3 ( V_9 -> V_13 ) ;
int V_24 ;
T_5 V_44 ;
void T_2 * V_45 = ( void T_2 * ) V_37 ;
V_1 . V_4 ++ ;
switch ( type [ V_12 ] ) {
case V_16 :
switch ( V_36 ) {
case V_46 :
V_25 = F_25 ( & V_43 , V_45 ,
sizeof( struct V_42 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_5 ) ;
return - V_47 ;
}
return F_26 ( V_48 ,
V_43 . V_49 ,
V_43 . V_50 ) ;
}
break;
case V_31 :
switch ( V_36 ) {
case V_51 :
memset ( & V_39 , 0 , sizeof( struct V_38 ) ) ;
V_24 = F_27 ( V_14 [ V_12 ] . V_17 ,
& V_39 . V_52 , & V_39 . V_53 ,
& V_39 . V_54 , & V_39 . V_55 ,
& V_39 . V_56 , & V_39 . V_57 ) ;
V_25 = F_28 ( V_45 , & V_39 ,
sizeof( struct V_38 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_4 ) ;
return - V_47 ;
}
return V_24 ;
case V_58 :
if ( V_14 [ V_12 ] . V_59 != 0 ) {
F_16 ( L_6 ) ;
return - V_60 ;
}
V_25 = F_25 ( & V_39 , V_45 , sizeof( V_39 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_5 ) ;
return - V_47 ;
}
return F_29 ( V_14 [ V_12 ] . V_17 ,
V_39 . V_52 , V_39 . V_53 , V_39 . V_54 ,
V_39 . V_55 , V_39 . V_56 , V_39 . V_57 ) ;
break;
}
break;
case V_32 :
switch ( V_36 ) {
case V_61 :
memset ( & V_41 , 0 , sizeof( struct V_40 ) ) ;
V_24 = F_30 ( V_14 [ V_12 ] . V_17 ,
& V_41 . V_52 , & V_41 . V_53 ,
& V_41 . V_54 , & V_44 , & V_41 . V_55 ,
& V_41 . V_56 ) ;
V_25 = F_28 ( V_45 , & V_41 ,
sizeof( struct V_40 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_4 ) ;
return - V_47 ;
}
return V_24 ;
case V_62 :
V_25 = F_25 ( & V_41 , V_45 , sizeof( V_41 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_5 ) ;
return - V_47 ;
}
return F_31 ( V_14 [ V_12 ] . V_17 ,
V_41 . V_52 , V_41 . V_53 , V_41 . V_54 ,
V_14 [ V_12 ] . V_63 , V_41 . V_55 ,
V_41 . V_56 ) ;
break;
}
break;
}
return - V_18 ;
}
static long
F_32 ( struct V_10 * V_10 , unsigned int V_36 , unsigned long V_37 )
{
int V_64 ;
struct V_9 * V_9 = F_19 ( V_10 ) ;
unsigned int V_12 = F_3 ( V_9 -> V_13 ) ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_64 = F_24 ( V_9 , V_10 , V_36 , V_37 ) ;
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return V_64 ;
}
static void F_33 ( struct V_65 * V_66 )
{
struct V_67 * V_68 = V_66 -> V_69 ;
F_34 ( & V_68 -> V_70 ) ;
}
static void F_35 ( struct V_65 * V_66 )
{
struct V_67 * V_68 = V_66 -> V_69 ;
unsigned int V_12 = V_68 -> V_12 ;
if ( ! F_36 ( & V_68 -> V_70 ) )
return;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_14 [ V_12 ] . V_59 -- ;
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
F_37 ( V_68 ) ;
}
static int F_38 ( unsigned int V_12 , struct V_65 * V_66 )
{
int V_11 ;
struct V_67 * V_68 ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_11 = F_39 ( V_14 [ V_12 ] . V_17 , V_66 ) ;
if ( V_11 ) {
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return V_11 ;
}
V_68 = F_40 ( sizeof( struct V_67 ) , V_71 ) ;
if ( V_68 == NULL ) {
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return - V_72 ;
}
V_68 -> V_12 = V_12 ;
F_41 ( & V_68 -> V_70 , 1 ) ;
V_66 -> V_73 = & V_74 ;
V_66 -> V_69 = V_68 ;
V_14 [ V_12 ] . V_59 ++ ;
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return 0 ;
}
static int F_42 ( struct V_10 * V_10 , struct V_65 * V_66 )
{
unsigned int V_12 = F_3 ( F_19 ( V_10 ) -> V_13 ) ;
if ( type [ V_12 ] == V_31 )
return F_38 ( V_12 , V_66 ) ;
return - V_75 ;
}
static void F_43 ( int V_76 )
{
if ( V_14 [ V_76 ] . V_27 ) {
#ifdef F_44
F_45 ( L_7 ,
V_14 [ V_76 ] . V_63 ) ;
#endif
F_46 ( V_14 [ V_76 ] . V_17 , V_14 [ V_76 ] . V_26 ,
V_14 [ V_76 ] . V_27 , V_14 [ V_76 ] . V_63 ) ;
V_14 [ V_76 ] . V_27 = NULL ;
V_14 [ V_76 ] . V_63 = 0 ;
V_14 [ V_76 ] . V_26 = 0 ;
#ifdef F_44
} else {
F_45 ( L_8 ) ;
#endif
}
}
static int T_6 F_47 ( void )
{
int V_24 = 0 ;
F_11 ( L_9 ) ;
if ( V_77 == 0 ) {
F_5 ( L_10 ) ;
V_24 = - V_75 ;
goto V_78;
}
if ( V_77 > V_79 ) {
F_5 ( L_11 ,
V_79 ) ;
V_77 = V_79 ;
}
V_24 = F_48 ( & V_80 , V_81 ) ;
if ( V_24 != 0 )
goto V_82;
return V_24 ;
V_82:
V_78:
return V_24 ;
}
static int F_49 ( struct V_83 * V_84 )
{
int V_85 ;
int V_86 = F_50 ( V_84 ) ;
int V_87 = F_51 ( V_84 ) ;
for ( V_85 = 0 ; V_85 < V_77 ; V_85 ++ )
if ( ( V_86 == V_88 [ V_85 ] ) && ( V_87 == V_84 -> V_76 ) )
return 1 ;
return 0 ;
}
static int F_52 ( struct V_83 * V_84 )
{
int V_85 , V_11 ;
char * V_89 ;
if ( V_48 != NULL ) {
F_53 ( & V_84 -> V_90 , L_12 ) ;
V_11 = - V_18 ;
goto V_91;
}
V_48 = V_84 ;
for ( V_85 = 0 ; V_85 < V_92 ; V_85 ++ ) {
V_14 [ V_85 ] . V_27 = NULL ;
V_14 [ V_85 ] . V_63 = 0 ;
F_54 ( & V_14 [ V_85 ] . V_15 ) ;
V_14 [ V_85 ] . V_93 = NULL ;
V_14 [ V_85 ] . V_17 = NULL ;
V_14 [ V_85 ] . V_20 = 0 ;
}
F_1 () ;
V_11 = F_55 ( F_56 ( V_94 , 0 ) , V_92 ,
V_95 ) ;
if ( V_11 ) {
F_57 ( & V_84 -> V_90 , L_13 ,
V_94 ) ;
goto V_96;
}
V_97 = F_58 () ;
if ( ! V_97 ) {
V_11 = - V_72 ;
goto V_98;
}
V_97 -> V_99 = & V_100 ;
V_97 -> V_101 = V_102 ;
V_11 = F_59 ( V_97 , F_56 ( V_94 , 0 ) , V_92 ) ;
if ( V_11 ) {
F_57 ( & V_84 -> V_90 , L_14 ) ;
goto V_98;
}
for ( V_85 = V_32 ; V_85 < ( V_103 + 1 ) ; V_85 ++ ) {
V_14 [ V_85 ] . V_17 = F_60 ( V_48 ,
V_104 , V_105 ) ;
if ( V_14 [ V_85 ] . V_17 == NULL ) {
F_57 ( & V_84 -> V_90 ,
L_15 ) ;
V_11 = - V_72 ;
goto V_106;
}
V_14 [ V_85 ] . V_26 = V_107 ;
V_14 [ V_85 ] . V_27 = F_61 ( V_14 [ V_85 ] . V_17 ,
V_14 [ V_85 ] . V_26 , & V_14 [ V_85 ] . V_63 ) ;
if ( V_14 [ V_85 ] . V_27 == NULL ) {
F_57 ( & V_84 -> V_90 ,
L_16 ) ;
V_14 [ V_85 ] . V_63 = 0 ;
F_62 ( V_14 [ V_85 ] . V_17 ) ;
V_11 = - V_72 ;
goto V_106;
}
}
for ( V_85 = V_31 ; V_85 < ( V_108 + 1 ) ; V_85 ++ ) {
V_14 [ V_85 ] . V_17 = F_63 ( V_48 ,
V_109 , V_105 , V_110 ) ;
if ( V_14 [ V_85 ] . V_17 == NULL ) {
F_57 ( & V_84 -> V_90 ,
L_17 ) ;
V_11 = - V_72 ;
goto V_111;
}
V_14 [ V_85 ] . V_26 = V_107 ;
V_14 [ V_85 ] . V_27 = F_40 ( V_14 [ V_85 ] . V_26 , V_71 ) ;
if ( V_14 [ V_85 ] . V_27 == NULL ) {
V_11 = - V_72 ;
F_64 ( V_14 [ V_85 ] . V_17 ) ;
goto V_111;
}
}
V_112 = F_65 ( V_102 , V_95 ) ;
if ( F_66 ( V_112 ) ) {
F_53 ( & V_84 -> V_90 , L_18 ) ;
V_11 = F_67 ( V_112 ) ;
goto V_113;
}
for ( V_85 = 0 ; V_85 < V_92 ; V_85 ++ ) {
int V_76 ;
switch ( type [ V_85 ] ) {
case V_31 :
V_89 = L_19 ;
break;
case V_16 :
V_89 = L_20 ;
break;
case V_32 :
V_89 = L_21 ;
break;
default:
V_11 = - V_18 ;
goto V_114;
}
V_76 = ( type [ V_85 ] == V_32 ) ? V_85 - ( V_108 + 1 ) : V_85 ;
V_14 [ V_85 ] . V_93 = F_68 ( V_112 , NULL ,
F_56 ( V_94 , V_85 ) , NULL , V_89 , V_76 ) ;
if ( F_66 ( V_14 [ V_85 ] . V_93 ) ) {
F_69 ( & V_84 -> V_90 , L_22 ) ;
V_11 = F_67 ( V_14 [ V_85 ] . V_93 ) ;
goto V_114;
}
}
return 0 ;
V_114:
while ( V_85 > 0 ) {
V_85 -- ;
F_70 ( V_112 , F_56 ( V_94 , V_85 ) ) ;
}
F_71 ( V_112 ) ;
V_85 = V_108 + 1 ;
V_111:
while ( V_85 > V_31 ) {
V_85 -- ;
F_37 ( V_14 [ V_85 ] . V_27 ) ;
F_64 ( V_14 [ V_85 ] . V_17 ) ;
}
V_85 = V_103 + 1 ;
V_106:
while ( V_85 > V_32 ) {
V_85 -- ;
F_43 ( V_85 ) ;
F_62 ( V_14 [ V_85 ] . V_17 ) ;
}
V_113:
F_72 ( V_97 ) ;
V_98:
F_73 ( F_56 ( V_94 , 0 ) , V_92 ) ;
V_96:
V_91:
return V_11 ;
}
static int F_74 ( struct V_83 * V_90 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_92 ; V_85 ++ ) {
F_75 ( & V_14 [ V_85 ] . V_15 ) ;
F_70 ( V_112 , F_56 ( V_94 , V_85 ) ) ;
}
F_71 ( V_112 ) ;
for ( V_85 = V_31 ; V_85 < ( V_108 + 1 ) ; V_85 ++ ) {
F_37 ( V_14 [ V_85 ] . V_27 ) ;
F_64 ( V_14 [ V_85 ] . V_17 ) ;
}
for ( V_85 = V_32 ; V_85 < ( V_103 + 1 ) ; V_85 ++ ) {
F_31 ( V_14 [ V_85 ] . V_17 , 0 , 0 , 0 , 0 , V_109 , 0 ) ;
F_43 ( V_85 ) ;
F_62 ( V_14 [ V_85 ] . V_17 ) ;
}
F_72 ( V_97 ) ;
F_73 ( F_56 ( V_94 , 0 ) , V_92 ) ;
return 0 ;
}
static void T_7 F_76 ( void )
{
F_77 ( & V_80 ) ;
}
