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
case V_59 :
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
case V_60 :
V_25 = F_25 ( & V_41 , V_45 , sizeof( V_41 ) ) ;
if ( V_25 != 0 ) {
F_16 ( L_5 ) ;
return - V_47 ;
}
return F_31 ( V_14 [ V_12 ] . V_17 ,
V_41 . V_52 , V_41 . V_53 , V_41 . V_54 ,
V_14 [ V_12 ] . V_61 , V_41 . V_55 ,
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
int V_62 ;
F_4 ( & V_63 ) ;
V_62 = F_24 ( F_19 ( V_10 ) , V_10 , V_36 , V_37 ) ;
F_6 ( & V_63 ) ;
return V_62 ;
}
static void F_33 ( int V_64 )
{
if ( V_14 [ V_64 ] . V_27 ) {
#ifdef F_34
F_35 ( L_6 ,
V_14 [ V_64 ] . V_61 ) ;
#endif
F_36 ( V_14 [ V_64 ] . V_17 , V_14 [ V_64 ] . V_26 ,
V_14 [ V_64 ] . V_27 , V_14 [ V_64 ] . V_61 ) ;
V_14 [ V_64 ] . V_27 = NULL ;
V_14 [ V_64 ] . V_61 = 0 ;
V_14 [ V_64 ] . V_26 = 0 ;
#ifdef F_34
} else {
F_35 ( L_7 ) ;
#endif
}
}
static int T_6 F_37 ( void )
{
int V_24 = 0 ;
F_11 ( L_8 ) ;
if ( V_65 == 0 ) {
F_5 ( L_9 ) ;
V_24 = - V_66 ;
goto V_67;
}
if ( V_65 > V_68 ) {
F_5 ( L_10 ,
V_68 ) ;
V_65 = V_68 ;
}
V_24 = F_38 ( & V_69 , V_70 ) ;
if ( V_24 != 0 )
goto V_71;
return V_24 ;
V_71:
V_67:
return V_24 ;
}
static int F_39 ( struct V_72 * V_73 )
{
int V_74 ;
int V_75 = F_40 ( V_73 ) ;
int V_76 = F_41 ( V_73 ) ;
for ( V_74 = 0 ; V_74 < V_65 ; V_74 ++ )
if ( ( V_75 == V_77 [ V_74 ] ) && ( V_76 == V_73 -> V_64 ) )
return 1 ;
return 0 ;
}
static int F_42 ( struct V_72 * V_73 )
{
int V_74 , V_11 ;
char * V_78 ;
if ( V_48 != NULL ) {
F_43 ( & V_73 -> V_79 , L_11 ) ;
V_11 = - V_18 ;
goto V_80;
}
V_48 = V_73 ;
for ( V_74 = 0 ; V_74 < V_81 ; V_74 ++ ) {
V_14 [ V_74 ] . V_27 = NULL ;
V_14 [ V_74 ] . V_61 = 0 ;
F_44 ( & V_14 [ V_74 ] . V_15 ) ;
V_14 [ V_74 ] . V_82 = NULL ;
V_14 [ V_74 ] . V_17 = NULL ;
V_14 [ V_74 ] . V_20 = 0 ;
}
F_1 () ;
V_11 = F_45 ( F_46 ( V_83 , 0 ) , V_81 ,
V_84 ) ;
if ( V_11 ) {
F_47 ( & V_73 -> V_79 , L_12 ,
V_83 ) ;
goto V_85;
}
V_86 = F_48 () ;
if ( ! V_86 ) {
V_11 = - V_87 ;
goto V_88;
}
V_86 -> V_89 = & V_90 ;
V_86 -> V_91 = V_92 ;
V_11 = F_49 ( V_86 , F_46 ( V_83 , 0 ) , V_81 ) ;
if ( V_11 ) {
F_47 ( & V_73 -> V_79 , L_13 ) ;
goto V_88;
}
for ( V_74 = V_32 ; V_74 < ( V_93 + 1 ) ; V_74 ++ ) {
V_14 [ V_74 ] . V_17 = F_50 ( V_48 ,
V_94 , V_95 ) ;
if ( V_14 [ V_74 ] . V_17 == NULL ) {
F_47 ( & V_73 -> V_79 ,
L_14 ) ;
V_11 = - V_87 ;
goto V_96;
}
V_14 [ V_74 ] . V_26 = V_97 ;
V_14 [ V_74 ] . V_27 = F_51 ( V_14 [ V_74 ] . V_17 ,
V_14 [ V_74 ] . V_26 , & V_14 [ V_74 ] . V_61 ) ;
if ( V_14 [ V_74 ] . V_27 == NULL ) {
F_47 ( & V_73 -> V_79 ,
L_15 ) ;
V_14 [ V_74 ] . V_61 = 0 ;
F_52 ( V_14 [ V_74 ] . V_17 ) ;
V_11 = - V_87 ;
goto V_96;
}
}
for ( V_74 = V_31 ; V_74 < ( V_98 + 1 ) ; V_74 ++ ) {
V_14 [ V_74 ] . V_17 = F_53 ( V_48 ,
V_99 , V_95 , V_100 ) ;
if ( V_14 [ V_74 ] . V_17 == NULL ) {
F_47 ( & V_73 -> V_79 ,
L_16 ) ;
V_11 = - V_87 ;
goto V_101;
}
V_14 [ V_74 ] . V_26 = V_97 ;
V_14 [ V_74 ] . V_27 = F_54 ( V_14 [ V_74 ] . V_26 , V_102 ) ;
if ( V_14 [ V_74 ] . V_27 == NULL ) {
V_11 = - V_87 ;
F_55 ( V_14 [ V_74 ] . V_17 ) ;
goto V_101;
}
}
V_103 = F_56 ( V_92 , V_84 ) ;
if ( F_57 ( V_103 ) ) {
F_43 ( & V_73 -> V_79 , L_17 ) ;
V_11 = F_58 ( V_103 ) ;
goto V_104;
}
for ( V_74 = 0 ; V_74 < V_81 ; V_74 ++ ) {
int V_64 ;
switch ( type [ V_74 ] ) {
case V_31 :
V_78 = L_18 ;
break;
case V_16 :
V_78 = L_19 ;
break;
case V_32 :
V_78 = L_20 ;
break;
default:
V_11 = - V_18 ;
goto V_105;
}
V_64 = ( type [ V_74 ] == V_32 ) ? V_74 - ( V_98 + 1 ) : V_74 ;
V_14 [ V_74 ] . V_82 = F_59 ( V_103 , NULL ,
F_46 ( V_83 , V_74 ) , NULL , V_78 , V_64 ) ;
if ( F_57 ( V_14 [ V_74 ] . V_82 ) ) {
F_60 ( & V_73 -> V_79 , L_21 ) ;
V_11 = F_58 ( V_14 [ V_74 ] . V_82 ) ;
goto V_105;
}
}
return 0 ;
V_105:
while ( V_74 > 0 ) {
V_74 -- ;
F_61 ( V_103 , F_46 ( V_83 , V_74 ) ) ;
}
F_62 ( V_103 ) ;
V_74 = V_98 + 1 ;
V_101:
while ( V_74 > V_31 ) {
V_74 -- ;
F_63 ( V_14 [ V_74 ] . V_27 ) ;
F_55 ( V_14 [ V_74 ] . V_17 ) ;
}
V_74 = V_93 + 1 ;
V_96:
while ( V_74 > V_32 ) {
V_74 -- ;
F_33 ( V_74 ) ;
F_52 ( V_14 [ V_74 ] . V_17 ) ;
}
V_104:
F_64 ( V_86 ) ;
V_88:
F_65 ( F_46 ( V_83 , 0 ) , V_81 ) ;
V_85:
V_80:
return V_11 ;
}
static int F_66 ( struct V_72 * V_79 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_81 ; V_74 ++ ) {
F_67 ( & V_14 [ V_74 ] . V_15 ) ;
F_61 ( V_103 , F_46 ( V_83 , V_74 ) ) ;
}
F_62 ( V_103 ) ;
for ( V_74 = V_31 ; V_74 < ( V_98 + 1 ) ; V_74 ++ ) {
F_63 ( V_14 [ V_74 ] . V_27 ) ;
F_55 ( V_14 [ V_74 ] . V_17 ) ;
}
for ( V_74 = V_32 ; V_74 < ( V_93 + 1 ) ; V_74 ++ ) {
F_31 ( V_14 [ V_74 ] . V_17 , 0 , 0 , 0 , 0 , V_99 , 0 ) ;
F_33 ( V_74 ) ;
F_52 ( V_14 [ V_74 ] . V_17 ) ;
}
F_64 ( V_86 ) ;
F_65 ( F_46 ( V_83 , 0 ) , V_81 ) ;
return 0 ;
}
static void T_7 F_68 ( void )
{
F_69 ( & V_69 ) ;
}
