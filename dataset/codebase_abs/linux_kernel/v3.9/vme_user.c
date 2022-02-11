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
T_4 V_35 = - 1 ;
unsigned int V_12 = F_3 ( F_19 ( V_10 ) -> V_13 ) ;
T_3 V_29 ;
if ( V_12 == V_16 )
return - V_18 ;
F_4 ( & V_14 [ V_12 ] . V_15 ) ;
V_29 = F_20 ( V_14 [ V_12 ] . V_17 ) ;
switch ( V_34 ) {
case V_36 :
V_35 = V_33 ;
break;
case V_37 :
V_35 = V_10 -> V_38 + V_33 ;
break;
case V_39 :
V_35 = V_29 + V_33 ;
break;
default:
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return - V_18 ;
break;
}
if ( ( V_35 < 0 ) || ( V_35 >= V_29 ) ) {
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return - V_18 ;
}
V_10 -> V_38 = V_35 ;
F_6 ( & V_14 [ V_12 ] . V_15 ) ;
return V_35 ;
}
static int F_23 ( struct V_9 * V_9 , struct V_10 * V_10 ,
unsigned int V_40 , unsigned long V_41 )
{
struct V_42 V_43 ;
struct V_44 V_45 ;
struct V_46 V_47 ;
unsigned long V_25 ;
unsigned int V_12 = F_3 ( V_9 -> V_13 ) ;
int V_24 ;
T_5 V_48 ;
void T_2 * V_49 = ( void T_2 * ) V_41 ;
V_1 . V_4 ++ ;
switch ( type [ V_12 ] ) {
case V_16 :
switch ( V_40 ) {
case V_50 :
V_25 = F_24 ( & V_47 , V_49 ,
sizeof( struct V_46 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_5 ) ;
return - V_51 ;
}
V_24 = F_25 ( V_52 ,
V_47 . V_53 ,
V_47 . V_54 ) ;
return V_24 ;
}
break;
case V_31 :
switch ( V_40 ) {
case V_55 :
memset ( & V_43 , 0 , sizeof( struct V_42 ) ) ;
V_24 = F_26 ( V_14 [ V_12 ] . V_17 ,
& V_43 . V_56 , & V_43 . V_57 ,
& V_43 . V_58 , & V_43 . V_59 ,
& V_43 . V_60 , & V_43 . V_61 ) ;
V_25 = F_27 ( V_49 , & V_43 ,
sizeof( struct V_42 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_4 ) ;
return - V_51 ;
}
return V_24 ;
break;
case V_62 :
V_25 = F_24 ( & V_43 , V_49 , sizeof( V_43 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_5 ) ;
return - V_51 ;
}
return F_28 ( V_14 [ V_12 ] . V_17 ,
V_43 . V_56 , V_43 . V_57 , V_43 . V_58 ,
V_43 . V_59 , V_43 . V_60 , V_43 . V_61 ) ;
break;
}
break;
case V_32 :
switch ( V_40 ) {
case V_63 :
memset ( & V_45 , 0 , sizeof( struct V_44 ) ) ;
V_24 = F_29 ( V_14 [ V_12 ] . V_17 ,
& V_45 . V_56 , & V_45 . V_57 ,
& V_45 . V_58 , & V_48 , & V_45 . V_59 ,
& V_45 . V_60 ) ;
V_25 = F_27 ( V_49 , & V_45 ,
sizeof( struct V_44 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_4 ) ;
return - V_51 ;
}
return V_24 ;
break;
case V_64 :
V_25 = F_24 ( & V_45 , V_49 , sizeof( V_45 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_5 ) ;
return - V_51 ;
}
return F_30 ( V_14 [ V_12 ] . V_17 ,
V_45 . V_56 , V_45 . V_57 , V_45 . V_58 ,
V_14 [ V_12 ] . V_65 , V_45 . V_59 ,
V_45 . V_60 ) ;
break;
}
break;
}
return - V_18 ;
}
static long
F_31 ( struct V_10 * V_10 , unsigned int V_40 , unsigned long V_41 )
{
int V_66 ;
F_4 ( & V_67 ) ;
V_66 = F_23 ( F_19 ( V_10 ) , V_10 , V_40 , V_41 ) ;
F_6 ( & V_67 ) ;
return V_66 ;
}
static void F_32 ( int V_68 )
{
if ( V_14 [ V_68 ] . V_27 ) {
#ifdef F_33
F_34 ( L_6 ,
V_14 [ V_68 ] . V_65 ) ;
#endif
F_35 ( V_14 [ V_68 ] . V_17 , V_14 [ V_68 ] . V_26 ,
V_14 [ V_68 ] . V_27 , V_14 [ V_68 ] . V_65 ) ;
V_14 [ V_68 ] . V_27 = NULL ;
V_14 [ V_68 ] . V_65 = 0 ;
V_14 [ V_68 ] . V_26 = 0 ;
#ifdef F_33
} else {
F_34 ( L_7 ) ;
#endif
}
}
static int T_6 F_36 ( void )
{
int V_24 = 0 ;
F_11 ( L_8 ) ;
if ( V_69 == 0 ) {
F_5 ( L_9 ) ;
V_24 = - V_70 ;
goto V_71;
}
if ( V_69 > V_72 ) {
F_5 ( L_10 ,
V_72 ) ;
V_69 = V_72 ;
}
V_24 = F_37 ( & V_73 , V_74 ) ;
if ( V_24 != 0 )
goto V_75;
return V_24 ;
V_75:
V_71:
return V_24 ;
}
static int F_38 ( struct V_76 * V_77 )
{
if ( V_77 -> V_68 >= V_72 )
return 0 ;
return 1 ;
}
static int F_39 ( struct V_76 * V_77 )
{
int V_78 , V_11 ;
char V_79 [ 12 ] ;
if ( V_52 != NULL ) {
F_40 ( & V_77 -> V_80 , L_11 ) ;
V_11 = - V_18 ;
goto V_81;
}
V_52 = V_77 ;
for ( V_78 = 0 ; V_78 < V_82 ; V_78 ++ ) {
V_14 [ V_78 ] . V_27 = NULL ;
V_14 [ V_78 ] . V_65 = 0 ;
F_41 ( & V_14 [ V_78 ] . V_15 ) ;
V_14 [ V_78 ] . V_83 = NULL ;
V_14 [ V_78 ] . V_17 = NULL ;
V_14 [ V_78 ] . V_20 = 0 ;
}
F_1 () ;
V_11 = F_42 ( F_43 ( V_84 , 0 ) , V_82 ,
V_85 ) ;
if ( V_11 ) {
F_44 ( & V_77 -> V_80 , L_12 ,
V_84 ) ;
goto V_86;
}
V_87 = F_45 () ;
V_87 -> V_88 = & V_89 ;
V_87 -> V_90 = V_91 ;
V_11 = F_46 ( V_87 , F_43 ( V_84 , 0 ) , V_82 ) ;
if ( V_11 ) {
F_44 ( & V_77 -> V_80 , L_13 ) ;
goto V_92;
}
for ( V_78 = V_32 ; V_78 < ( V_93 + 1 ) ; V_78 ++ ) {
V_14 [ V_78 ] . V_17 = F_47 ( V_52 ,
V_94 , V_95 ) ;
if ( V_14 [ V_78 ] . V_17 == NULL ) {
F_44 ( & V_77 -> V_80 ,
L_14 ) ;
goto V_96;
}
V_14 [ V_78 ] . V_26 = V_97 ;
V_14 [ V_78 ] . V_27 = F_48 ( V_14 [ V_78 ] . V_17 ,
V_14 [ V_78 ] . V_26 , & V_14 [ V_78 ] . V_65 ) ;
if ( V_14 [ V_78 ] . V_27 == NULL ) {
F_44 ( & V_77 -> V_80 ,
L_15 ) ;
V_14 [ V_78 ] . V_65 = 0 ;
F_49 ( V_14 [ V_78 ] . V_17 ) ;
V_11 = - V_98 ;
goto V_96;
}
}
for ( V_78 = V_31 ; V_78 < ( V_99 + 1 ) ; V_78 ++ ) {
V_14 [ V_78 ] . V_17 = F_50 ( V_52 ,
V_100 , V_95 , V_101 ) ;
if ( V_14 [ V_78 ] . V_17 == NULL ) {
F_44 ( & V_77 -> V_80 ,
L_16 ) ;
goto V_102;
}
V_14 [ V_78 ] . V_26 = V_97 ;
V_14 [ V_78 ] . V_27 = F_51 ( V_14 [ V_78 ] . V_26 , V_103 ) ;
if ( V_14 [ V_78 ] . V_27 == NULL ) {
V_11 = - V_98 ;
goto V_104;
}
}
V_105 = F_52 ( V_91 , V_85 ) ;
if ( F_53 ( V_105 ) ) {
F_40 ( & V_77 -> V_80 , L_17 ) ;
V_11 = F_54 ( V_105 ) ;
goto V_106;
}
for ( V_78 = 0 ; V_78 < V_82 ; V_78 ++ ) {
int V_68 ;
switch ( type [ V_78 ] ) {
case V_31 :
sprintf ( V_79 , L_18 ) ;
break;
case V_16 :
sprintf ( V_79 , L_19 ) ;
break;
case V_32 :
sprintf ( V_79 , L_20 ) ;
break;
default:
V_11 = - V_18 ;
goto V_107;
break;
}
V_68 = ( type [ V_78 ] == V_32 ) ? V_78 - ( V_99 + 1 ) : V_78 ;
V_14 [ V_78 ] . V_83 = F_55 ( V_105 , NULL ,
F_43 ( V_84 , V_78 ) , NULL , V_79 , V_68 ) ;
if ( F_53 ( V_14 [ V_78 ] . V_83 ) ) {
F_56 ( & V_77 -> V_80 , L_21 ) ;
V_11 = F_54 ( V_14 [ V_78 ] . V_83 ) ;
goto V_107;
}
}
return 0 ;
V_78 = V_82 ;
V_107:
while ( V_78 > 0 ) {
V_78 -- ;
F_57 ( V_105 , F_43 ( V_84 , V_78 ) ) ;
}
F_58 ( V_105 ) ;
V_78 = V_99 + 1 ;
V_104:
for ( V_78 = V_31 ; V_78 < ( V_99 + 1 ) ; V_78 ++ )
F_59 ( V_14 [ V_78 ] . V_27 ) ;
V_102:
while ( V_78 > V_31 ) {
V_78 -- ;
F_60 ( V_14 [ V_78 ] . V_17 ) ;
}
V_78 = V_93 + 1 ;
V_96:
while ( V_78 > V_32 ) {
V_78 -- ;
F_32 ( V_78 ) ;
F_49 ( V_14 [ V_78 ] . V_17 ) ;
}
V_106:
F_61 ( V_87 ) ;
V_92:
F_62 ( F_43 ( V_84 , 0 ) , V_82 ) ;
V_86:
V_81:
return V_11 ;
}
static int F_63 ( struct V_76 * V_80 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_82 ; V_78 ++ ) {
F_64 ( & V_14 [ V_78 ] . V_15 ) ;
F_57 ( V_105 , F_43 ( V_84 , V_78 ) ) ;
}
F_58 ( V_105 ) ;
for ( V_78 = V_31 ; V_78 < ( V_99 + 1 ) ; V_78 ++ ) {
F_59 ( V_14 [ V_78 ] . V_27 ) ;
F_60 ( V_14 [ V_78 ] . V_17 ) ;
}
for ( V_78 = V_32 ; V_78 < ( V_93 + 1 ) ; V_78 ++ ) {
F_30 ( V_14 [ V_78 ] . V_17 , 0 , 0 , 0 , 0 , V_100 , 0 ) ;
F_32 ( V_78 ) ;
F_49 ( V_14 [ V_78 ] . V_17 ) ;
}
F_61 ( V_87 ) ;
F_62 ( F_43 ( V_84 , 0 ) , V_82 ) ;
return 0 ;
}
static void T_7 F_65 ( void )
{
F_66 ( & V_73 ) ;
}
