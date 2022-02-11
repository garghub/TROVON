static T_1 F_1 ( int V_1 , char T_2 * V_2 , T_3 V_3 ,
T_4 * V_4 )
{
T_1 V_5 ;
T_1 V_6 = 0 ;
if ( V_3 <= V_7 [ V_1 ] . V_8 ) {
V_6 = F_2 ( V_7 [ V_1 ] . V_9 ,
V_7 [ V_1 ] . V_10 , V_3 , * V_4 ) ;
if ( V_6 < 0 )
return ( int ) V_6 ;
V_5 = F_3 ( V_2 , V_7 [ V_1 ] . V_10 ,
( unsigned long ) V_6 ) ;
if ( V_5 != 0 ) {
V_6 = ( V_6 - V_5 ) ;
F_4 ( L_1 ) ;
return - V_11 ;
}
} else {
F_4 ( L_2 ) ;
return - V_11 ;
}
return V_6 ;
}
static T_1 F_5 ( unsigned int V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
T_1 V_5 ;
T_1 V_6 = 0 ;
if ( V_3 <= V_7 [ V_1 ] . V_8 ) {
V_5 = F_6 ( V_7 [ V_1 ] . V_10 , V_2 ,
( unsigned long ) V_3 ) ;
if ( V_5 != 0 )
V_6 = ( V_6 - V_5 ) ;
else
V_6 = V_3 ;
V_6 = F_7 ( V_7 [ V_1 ] . V_9 ,
V_7 [ V_1 ] . V_10 , V_6 , * V_4 ) ;
} else {
F_4 ( L_2 ) ;
return - V_11 ;
}
return V_6 ;
}
static T_1 F_8 ( unsigned int V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
void * V_12 ;
T_1 V_5 ;
V_12 = V_7 [ V_1 ] . V_10 + * V_4 ;
V_5 = F_3 ( V_2 , V_12 , ( unsigned long ) V_3 ) ;
if ( V_5 != 0 ) {
V_5 = ( V_3 - V_5 ) ;
F_9 ( L_3 ) ;
} else
V_5 = V_3 ;
return V_5 ;
}
static T_1 F_10 ( unsigned int V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
void * V_12 ;
T_3 V_5 ;
V_12 = V_7 [ V_1 ] . V_10 + * V_4 ;
V_5 = F_6 ( V_12 , V_2 , ( unsigned long ) V_3 ) ;
if ( V_5 != 0 ) {
V_5 = ( V_3 - V_5 ) ;
F_9 ( L_3 ) ;
} else
V_5 = V_3 ;
return V_5 ;
}
static T_1 F_11 ( struct V_13 * V_13 , char T_2 * V_2 , T_3 V_3 ,
T_4 * V_4 )
{
unsigned int V_1 = F_12 ( F_13 ( V_13 ) -> V_14 ) ;
T_1 V_5 ;
T_3 V_15 ;
T_3 V_16 ;
if ( V_1 == V_17 )
return 0 ;
F_14 ( & V_7 [ V_1 ] . V_18 ) ;
V_15 = F_15 ( V_7 [ V_1 ] . V_9 ) ;
if ( ( * V_4 < 0 ) || ( * V_4 > ( V_15 - 1 ) ) ) {
F_16 ( & V_7 [ V_1 ] . V_18 ) ;
return 0 ;
}
if ( * V_4 + V_3 > V_15 )
V_16 = V_15 - * V_4 ;
else
V_16 = V_3 ;
switch ( type [ V_1 ] ) {
case V_19 :
V_5 = F_1 ( V_1 , V_2 , V_16 , V_4 ) ;
break;
case V_20 :
V_5 = F_8 ( V_1 , V_2 , V_16 , V_4 ) ;
break;
default:
V_5 = - V_11 ;
}
F_16 ( & V_7 [ V_1 ] . V_18 ) ;
if ( V_5 > 0 )
* V_4 += V_5 ;
return V_5 ;
}
static T_1 F_17 ( struct V_13 * V_13 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
unsigned int V_1 = F_12 ( F_13 ( V_13 ) -> V_14 ) ;
T_1 V_5 ;
T_3 V_15 ;
T_3 V_16 ;
if ( V_1 == V_17 )
return 0 ;
F_14 ( & V_7 [ V_1 ] . V_18 ) ;
V_15 = F_15 ( V_7 [ V_1 ] . V_9 ) ;
if ( ( * V_4 < 0 ) || ( * V_4 > ( V_15 - 1 ) ) ) {
F_16 ( & V_7 [ V_1 ] . V_18 ) ;
return 0 ;
}
if ( * V_4 + V_3 > V_15 )
V_16 = V_15 - * V_4 ;
else
V_16 = V_3 ;
switch ( type [ V_1 ] ) {
case V_19 :
V_5 = F_5 ( V_1 , V_2 , V_16 , V_4 ) ;
break;
case V_20 :
V_5 = F_10 ( V_1 , V_2 , V_16 , V_4 ) ;
break;
default:
V_5 = - V_11 ;
}
F_16 ( & V_7 [ V_1 ] . V_18 ) ;
if ( V_5 > 0 )
* V_4 += V_5 ;
return V_5 ;
}
static T_4 F_18 ( struct V_13 * V_13 , T_4 V_21 , int V_22 )
{
unsigned int V_1 = F_12 ( F_13 ( V_13 ) -> V_14 ) ;
T_3 V_15 ;
T_4 V_23 ;
switch ( type [ V_1 ] ) {
case V_19 :
case V_20 :
F_14 ( & V_7 [ V_1 ] . V_18 ) ;
V_15 = F_15 ( V_7 [ V_1 ] . V_9 ) ;
V_23 = F_19 ( V_13 , V_21 , V_22 , V_15 ) ;
F_16 ( & V_7 [ V_1 ] . V_18 ) ;
return V_23 ;
}
return - V_11 ;
}
static int F_20 ( struct V_24 * V_24 , struct V_13 * V_13 ,
unsigned int V_25 , unsigned long V_26 )
{
struct V_27 V_28 ;
struct V_29 V_30 ;
struct V_31 V_32 ;
unsigned long V_6 ;
unsigned int V_1 = F_12 ( V_24 -> V_14 ) ;
int V_5 ;
T_5 V_33 ;
void T_2 * V_34 = ( void T_2 * ) V_26 ;
switch ( type [ V_1 ] ) {
case V_17 :
switch ( V_25 ) {
case V_35 :
V_6 = F_21 ( & V_32 , V_34 ,
sizeof( struct V_31 ) ) ;
if ( V_6 != 0 ) {
F_9 ( L_4 ) ;
return - V_36 ;
}
return F_22 ( V_37 ,
V_32 . V_38 ,
V_32 . V_39 ) ;
}
break;
case V_19 :
switch ( V_25 ) {
case V_40 :
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
V_5 = F_23 ( V_7 [ V_1 ] . V_9 ,
& V_28 . V_41 , & V_28 . V_42 ,
& V_28 . V_43 , & V_28 . V_44 ,
& V_28 . V_45 , & V_28 . V_46 ) ;
V_6 = F_24 ( V_34 , & V_28 ,
sizeof( struct V_27 ) ) ;
if ( V_6 != 0 ) {
F_9 ( L_3 ) ;
return - V_36 ;
}
return V_5 ;
case V_47 :
if ( V_7 [ V_1 ] . V_48 != 0 ) {
F_9 ( L_5 ) ;
return - V_49 ;
}
V_6 = F_21 ( & V_28 , V_34 , sizeof( V_28 ) ) ;
if ( V_6 != 0 ) {
F_9 ( L_4 ) ;
return - V_36 ;
}
return F_25 ( V_7 [ V_1 ] . V_9 ,
V_28 . V_41 , V_28 . V_42 , V_28 . V_43 ,
V_28 . V_44 , V_28 . V_45 , V_28 . V_46 ) ;
break;
}
break;
case V_20 :
switch ( V_25 ) {
case V_50 :
memset ( & V_30 , 0 , sizeof( struct V_29 ) ) ;
V_5 = F_26 ( V_7 [ V_1 ] . V_9 ,
& V_30 . V_41 , & V_30 . V_42 ,
& V_30 . V_43 , & V_33 , & V_30 . V_44 ,
& V_30 . V_45 ) ;
V_6 = F_24 ( V_34 , & V_30 ,
sizeof( struct V_29 ) ) ;
if ( V_6 != 0 ) {
F_9 ( L_3 ) ;
return - V_36 ;
}
return V_5 ;
case V_51 :
V_6 = F_21 ( & V_30 , V_34 , sizeof( V_30 ) ) ;
if ( V_6 != 0 ) {
F_9 ( L_4 ) ;
return - V_36 ;
}
return F_27 ( V_7 [ V_1 ] . V_9 ,
V_30 . V_41 , V_30 . V_42 , V_30 . V_43 ,
V_7 [ V_1 ] . V_52 , V_30 . V_44 ,
V_30 . V_45 ) ;
break;
}
break;
}
return - V_11 ;
}
static long
F_28 ( struct V_13 * V_13 , unsigned int V_25 , unsigned long V_26 )
{
int V_53 ;
struct V_24 * V_24 = F_13 ( V_13 ) ;
unsigned int V_1 = F_12 ( V_24 -> V_14 ) ;
F_14 ( & V_7 [ V_1 ] . V_18 ) ;
V_53 = F_20 ( V_24 , V_13 , V_25 , V_26 ) ;
F_16 ( & V_7 [ V_1 ] . V_18 ) ;
return V_53 ;
}
static void F_29 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = V_55 -> V_58 ;
F_30 ( & V_57 -> V_59 ) ;
}
static void F_31 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = V_55 -> V_58 ;
unsigned int V_1 = V_57 -> V_1 ;
if ( ! F_32 ( & V_57 -> V_59 ) )
return;
F_14 ( & V_7 [ V_1 ] . V_18 ) ;
V_7 [ V_1 ] . V_48 -- ;
F_16 ( & V_7 [ V_1 ] . V_18 ) ;
F_33 ( V_57 ) ;
}
static int F_34 ( unsigned int V_1 , struct V_54 * V_55 )
{
int V_60 ;
struct V_56 * V_57 ;
F_14 ( & V_7 [ V_1 ] . V_18 ) ;
V_60 = F_35 ( V_7 [ V_1 ] . V_9 , V_55 ) ;
if ( V_60 ) {
F_16 ( & V_7 [ V_1 ] . V_18 ) ;
return V_60 ;
}
V_57 = F_36 ( sizeof( struct V_56 ) , V_61 ) ;
if ( V_57 == NULL ) {
F_16 ( & V_7 [ V_1 ] . V_18 ) ;
return - V_62 ;
}
V_57 -> V_1 = V_1 ;
F_37 ( & V_57 -> V_59 , 1 ) ;
V_55 -> V_63 = & V_64 ;
V_55 -> V_58 = V_57 ;
V_7 [ V_1 ] . V_48 ++ ;
F_16 ( & V_7 [ V_1 ] . V_18 ) ;
return 0 ;
}
static int F_38 ( struct V_13 * V_13 , struct V_54 * V_55 )
{
unsigned int V_1 = F_12 ( F_13 ( V_13 ) -> V_14 ) ;
if ( type [ V_1 ] == V_19 )
return F_34 ( V_1 , V_55 ) ;
return - V_65 ;
}
static int F_39 ( struct V_66 * V_67 )
{
int V_68 ;
int V_69 = F_40 ( V_67 ) ;
int V_70 = F_41 ( V_67 ) ;
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ )
if ( ( V_69 == V_72 [ V_68 ] ) && ( V_70 == V_67 -> V_73 ) )
return 1 ;
return 0 ;
}
static int F_42 ( struct V_66 * V_67 )
{
int V_68 , V_60 ;
char * V_74 ;
if ( V_37 != NULL ) {
F_43 ( & V_67 -> V_75 , L_6 ) ;
V_60 = - V_11 ;
goto V_76;
}
V_37 = V_67 ;
for ( V_68 = 0 ; V_68 < V_77 ; V_68 ++ ) {
V_7 [ V_68 ] . V_10 = NULL ;
V_7 [ V_68 ] . V_52 = 0 ;
F_44 ( & V_7 [ V_68 ] . V_18 ) ;
V_7 [ V_68 ] . V_78 = NULL ;
V_7 [ V_68 ] . V_9 = NULL ;
}
V_60 = F_45 ( F_46 ( V_79 , 0 ) , V_77 ,
V_80 ) ;
if ( V_60 ) {
F_47 ( & V_67 -> V_75 , L_7 ,
V_79 ) ;
goto V_81;
}
V_82 = F_48 () ;
if ( ! V_82 ) {
V_60 = - V_62 ;
goto V_83;
}
V_82 -> V_84 = & V_85 ;
V_82 -> V_86 = V_87 ;
V_60 = F_49 ( V_82 , F_46 ( V_79 , 0 ) , V_77 ) ;
if ( V_60 ) {
F_47 ( & V_67 -> V_75 , L_8 ) ;
goto V_83;
}
for ( V_68 = V_20 ; V_68 < ( V_88 + 1 ) ; V_68 ++ ) {
V_7 [ V_68 ] . V_9 = F_50 ( V_37 ,
V_89 , V_90 ) ;
if ( V_7 [ V_68 ] . V_9 == NULL ) {
F_47 ( & V_67 -> V_75 ,
L_9 ) ;
V_60 = - V_62 ;
goto V_91;
}
V_7 [ V_68 ] . V_8 = V_92 ;
V_7 [ V_68 ] . V_10 = F_51 ( V_7 [ V_68 ] . V_9 ,
V_7 [ V_68 ] . V_8 , & V_7 [ V_68 ] . V_52 ) ;
if ( V_7 [ V_68 ] . V_10 == NULL ) {
F_47 ( & V_67 -> V_75 ,
L_10 ) ;
V_7 [ V_68 ] . V_52 = 0 ;
F_52 ( V_7 [ V_68 ] . V_9 ) ;
V_60 = - V_62 ;
goto V_91;
}
}
for ( V_68 = V_19 ; V_68 < ( V_93 + 1 ) ; V_68 ++ ) {
V_7 [ V_68 ] . V_9 = F_53 ( V_37 ,
V_94 , V_90 , V_95 ) ;
if ( V_7 [ V_68 ] . V_9 == NULL ) {
F_47 ( & V_67 -> V_75 ,
L_11 ) ;
V_60 = - V_62 ;
goto V_96;
}
V_7 [ V_68 ] . V_8 = V_92 ;
V_7 [ V_68 ] . V_10 = F_36 ( V_7 [ V_68 ] . V_8 , V_61 ) ;
if ( V_7 [ V_68 ] . V_10 == NULL ) {
V_60 = - V_62 ;
F_54 ( V_7 [ V_68 ] . V_9 ) ;
goto V_96;
}
}
V_97 = F_55 ( V_87 , V_80 ) ;
if ( F_56 ( V_97 ) ) {
F_43 ( & V_67 -> V_75 , L_12 ) ;
V_60 = F_57 ( V_97 ) ;
goto V_98;
}
for ( V_68 = 0 ; V_68 < V_77 ; V_68 ++ ) {
int V_73 ;
switch ( type [ V_68 ] ) {
case V_19 :
V_74 = L_13 ;
break;
case V_17 :
V_74 = L_14 ;
break;
case V_20 :
V_74 = L_15 ;
break;
default:
V_60 = - V_11 ;
goto V_99;
}
V_73 = ( type [ V_68 ] == V_20 ) ? V_68 - ( V_93 + 1 ) : V_68 ;
V_7 [ V_68 ] . V_78 = F_58 ( V_97 , NULL ,
F_46 ( V_79 , V_68 ) , NULL , V_74 , V_73 ) ;
if ( F_56 ( V_7 [ V_68 ] . V_78 ) ) {
F_59 ( & V_67 -> V_75 , L_16 ) ;
V_60 = F_57 ( V_7 [ V_68 ] . V_78 ) ;
goto V_99;
}
}
return 0 ;
V_99:
while ( V_68 > 0 ) {
V_68 -- ;
F_60 ( V_97 , F_46 ( V_79 , V_68 ) ) ;
}
F_61 ( V_97 ) ;
V_68 = V_93 + 1 ;
V_96:
while ( V_68 > V_19 ) {
V_68 -- ;
F_33 ( V_7 [ V_68 ] . V_10 ) ;
F_54 ( V_7 [ V_68 ] . V_9 ) ;
}
V_68 = V_88 + 1 ;
V_91:
while ( V_68 > V_20 ) {
V_68 -- ;
F_62 ( V_7 [ V_68 ] . V_9 , V_7 [ V_68 ] . V_8 ,
V_7 [ V_68 ] . V_10 , V_7 [ V_68 ] . V_52 ) ;
F_52 ( V_7 [ V_68 ] . V_9 ) ;
}
V_98:
F_63 ( V_82 ) ;
V_83:
F_64 ( F_46 ( V_79 , 0 ) , V_77 ) ;
V_81:
V_76:
return V_60 ;
}
static int F_65 ( struct V_66 * V_75 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_77 ; V_68 ++ ) {
F_66 ( & V_7 [ V_68 ] . V_18 ) ;
F_60 ( V_97 , F_46 ( V_79 , V_68 ) ) ;
}
F_61 ( V_97 ) ;
for ( V_68 = V_19 ; V_68 < ( V_93 + 1 ) ; V_68 ++ ) {
F_33 ( V_7 [ V_68 ] . V_10 ) ;
F_54 ( V_7 [ V_68 ] . V_9 ) ;
}
for ( V_68 = V_20 ; V_68 < ( V_88 + 1 ) ; V_68 ++ ) {
F_27 ( V_7 [ V_68 ] . V_9 , 0 , 0 , 0 , 0 , V_94 , 0 ) ;
F_62 ( V_7 [ V_68 ] . V_9 , V_7 [ V_68 ] . V_8 ,
V_7 [ V_68 ] . V_10 , V_7 [ V_68 ] . V_52 ) ;
F_52 ( V_7 [ V_68 ] . V_9 ) ;
}
F_63 ( V_82 ) ;
F_64 ( F_46 ( V_79 , 0 ) , V_77 ) ;
return 0 ;
}
static int T_6 F_67 ( void )
{
int V_5 = 0 ;
F_4 ( L_17 ) ;
if ( V_71 == 0 ) {
F_68 ( L_18 ) ;
V_5 = - V_65 ;
goto V_100;
}
if ( V_71 > V_101 ) {
F_68 ( L_19 ,
V_101 ) ;
V_71 = V_101 ;
}
V_5 = F_69 ( & V_102 , V_103 ) ;
if ( V_5 != 0 )
goto V_104;
return V_5 ;
V_104:
V_100:
return V_5 ;
}
static void T_7 F_70 ( void )
{
F_71 ( & V_102 ) ;
}
