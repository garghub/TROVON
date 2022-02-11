static int F_1 ( struct V_1 * V_2 , int V_3 )
{
return 0 ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_3 ( V_6 ) ;
struct V_7 * V_8 ;
struct V_2 * V_9 = F_4 ( V_5 ) ;
F_5 ( L_1 , V_5 ) ;
if ( F_6 ( V_10 , & V_5 -> V_11 ) ) {
F_7 ( V_5 , V_12 , NULL , NULL , NULL ) ;
for (; ; ) {
F_8 ( F_9 ( V_9 ) , & V_6 , V_13 ) ;
if ( F_6 ( V_14 , & V_5 -> V_11 ) || ! V_15 )
break;
F_10 () ;
}
F_11 ( F_9 ( V_9 ) , & V_6 ) ;
}
while ( ( V_8 = F_12 ( & V_9 -> V_16 ) ) != NULL ) {
F_13 ( V_5 , V_8 -> V_17 ) ;
F_5 ( L_2 ) ;
F_14 ( NULL , V_18 , V_5 , NULL , NULL , & V_5 -> V_19 , 0 ) ;
F_15 ( V_8 ) ;
}
F_16 ( V_10 , & V_5 -> V_11 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_2 * V_9 = V_2 -> V_9 ;
struct V_4 * V_5 ;
if ( V_9 ) {
V_5 = F_18 ( V_2 ) ;
F_5 ( L_1 , V_5 ) ;
F_16 ( V_20 , & V_5 -> V_11 ) ;
F_2 ( V_5 ) ;
F_19 ( V_2 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_21 * V_21 ,
int V_22 )
{
F_3 ( V_6 ) ;
struct V_2 * V_9 = V_2 -> V_9 ;
struct V_23 * V_24 ;
struct V_4 * V_5 ;
int error ;
if ( V_22 != sizeof( struct V_23 ) )
return - V_25 ;
F_21 ( V_9 ) ;
if ( V_2 -> V_26 == V_27 ) {
error = - V_28 ;
goto V_29;
}
if ( V_2 -> V_26 != V_30 ) {
error = - V_25 ;
goto V_29;
}
V_5 = F_18 ( V_2 ) ;
V_24 = (struct V_23 * ) V_21 ;
if ( V_24 -> V_31 != V_32 ) {
error = - V_33 ;
goto V_29;
}
F_16 ( V_34 , & V_5 -> V_11 ) ;
if ( ! F_6 ( V_35 , & V_5 -> V_11 ) ) {
error = - V_36 ;
goto V_29;
}
V_5 -> V_37 = * V_24 ;
F_22 ( V_38 , & V_5 -> V_11 ) ;
F_7 ( V_5 , V_39 , NULL , NULL , & V_5 -> V_37 ) ;
for (; ; ) {
F_8 ( F_9 ( V_9 ) , & V_6 , V_13 ) ;
if ( ! F_6 ( V_38 , & V_5 -> V_11 ) || ! V_15 )
break;
F_10 () ;
}
F_11 ( F_9 ( V_9 ) , & V_6 ) ;
F_16 ( V_10 , & V_5 -> V_11 ) ;
if ( ! V_15 ) {
error = - V_40 ;
goto V_29;
}
if ( ! V_9 -> V_41 )
F_22 ( V_34 , & V_5 -> V_11 ) ;
error = - V_9 -> V_41 ;
V_29:
F_23 ( V_9 ) ;
return error ;
}
static int F_24 ( struct V_1 * V_2 , struct V_21 * V_21 ,
int V_22 , int V_11 )
{
F_3 ( V_6 ) ;
struct V_2 * V_9 = V_2 -> V_9 ;
struct V_23 * V_24 ;
struct V_4 * V_5 = F_18 ( V_2 ) ;
int error ;
F_5 ( L_1 , V_5 ) ;
F_21 ( V_9 ) ;
if ( V_22 != sizeof( struct V_23 ) ) {
error = - V_25 ;
goto V_29;
}
switch ( V_2 -> V_26 ) {
default:
error = - V_25 ;
goto V_29;
case V_27 :
error = - V_28 ;
goto V_29;
case V_42 :
if ( F_6 ( V_38 , & V_5 -> V_11 ) ) {
error = - V_43 ;
goto V_29;
}
V_2 -> V_26 = V_30 ;
if ( V_9 -> V_41 ) {
error = - V_9 -> V_41 ;
goto V_29;
}
break;
case V_30 :
V_24 = (struct V_23 * ) V_21 ;
if ( V_24 -> V_31 != V_32 ) {
error = - V_33 ;
goto V_29;
}
if ( ! F_6 ( V_35 , & V_5 -> V_11 ) ) {
error = - V_36 ;
goto V_29;
}
if ( V_5 -> V_19 . V_44 . V_45 == V_46 ||
V_5 -> V_19 . V_47 . V_45 == V_46 ) {
error = - V_25 ;
goto V_29;
}
if ( ! V_5 -> V_19 . V_44 . V_45 &&
! V_5 -> V_19 . V_47 . V_45 ) {
error = - V_25 ;
goto V_29;
}
V_5 -> V_48 = * V_24 ;
F_22 ( V_38 , & V_5 -> V_11 ) ;
F_7 ( V_5 , V_49 , NULL , NULL , & V_5 -> V_48 ) ;
if ( V_11 & V_50 ) {
V_2 -> V_26 = V_42 ;
error = - V_51 ;
goto V_29;
}
error = 0 ;
F_8 ( F_9 ( V_9 ) , & V_6 , V_52 ) ;
while ( F_6 ( V_38 , & V_5 -> V_11 ) && V_15 ) {
F_10 () ;
if ( ! F_25 ( V_53 ) ) {
F_8 ( F_9 ( V_9 ) , & V_6 ,
V_52 ) ;
continue;
}
F_5 ( L_3 ) ;
F_7 ( V_5 , V_12 , NULL , NULL , NULL ) ;
while ( F_6 ( V_38 , & V_5 -> V_11 ) && V_15 ) {
F_8 ( F_9 ( V_9 ) , & V_6 ,
V_52 ) ;
F_10 () ;
}
if ( ! V_9 -> V_41 )
while ( ! F_6 ( V_14 , & V_5 -> V_11 ) &&
V_15 ) {
F_8 ( F_9 ( V_9 ) , & V_6 ,
V_52 ) ;
F_10 () ;
}
F_16 ( V_10 , & V_5 -> V_11 ) ;
F_16 ( V_14 , & V_5 -> V_11 ) ;
F_16 ( V_54 , & V_5 -> V_11 ) ;
error = - V_55 ;
break;
}
F_11 ( F_9 ( V_9 ) , & V_6 ) ;
if ( error )
goto V_29;
if ( ! V_15 ) {
error = - V_40 ;
goto V_29;
}
if ( V_9 -> V_41 ) {
error = - V_9 -> V_41 ;
goto V_29;
}
}
V_5 -> V_19 . V_44 . V_56 = F_26 ( V_5 -> V_19 . V_44 ) ;
V_5 -> V_19 . V_44 . V_57 = 0 ;
V_5 -> V_19 . V_44 . V_58 = 0 ;
error = F_27 ( V_2 , V_5 -> V_59 , V_5 -> V_60 , V_5 -> V_61 ) ;
if ( ! error )
V_2 -> V_26 = V_27 ;
else
( void ) F_2 ( V_5 ) ;
V_29:
F_23 ( V_9 ) ;
return error ;
}
static int F_28 ( struct V_1 * V_2 , int V_62 )
{
F_3 ( V_6 ) ;
struct V_2 * V_9 = V_2 -> V_9 ;
struct V_4 * V_5 = F_18 ( V_2 ) ;
int error ;
F_5 ( L_1 , V_5 ) ;
F_21 ( V_9 ) ;
if ( F_6 ( V_63 , & V_5 -> V_11 ) ) {
error = - V_25 ;
goto V_29;
}
if ( F_6 ( V_64 , & V_5 -> V_11 ) ) {
error = - V_65 ;
goto V_29;
}
F_22 ( V_38 , & V_5 -> V_11 ) ;
F_7 ( V_5 , V_66 , NULL , NULL , & V_5 -> V_37 ) ;
for (; ; ) {
F_8 ( F_9 ( V_9 ) , & V_6 , V_13 ) ;
if ( ! F_6 ( V_38 , & V_5 -> V_11 ) || ! V_15 )
break;
F_10 () ;
}
F_11 ( F_9 ( V_9 ) , & V_6 ) ;
if ( ! V_15 ) {
error = - V_40 ;
goto V_29;
}
F_22 ( V_64 , & V_5 -> V_11 ) ;
F_29 ( V_9 ) ;
V_9 -> V_67 = V_62 > 0 ? V_62 : V_68 ;
error = - V_9 -> V_41 ;
V_29:
F_23 ( V_9 ) ;
return error ;
}
static int F_30 ( struct V_1 * V_2 , struct V_1 * V_69 , int V_11 ,
bool V_70 )
{
struct V_2 * V_9 = V_2 -> V_9 ;
struct V_7 * V_8 ;
struct V_71 * V_72 ;
struct V_4 * V_73 = F_18 ( V_2 ) ;
struct V_4 * V_74 ;
int error ;
F_21 ( V_9 ) ;
error = F_31 ( F_32 ( V_9 ) , V_69 , 0 , V_70 ) ;
if ( error )
goto V_29;
V_74 = F_18 ( V_69 ) ;
F_5 ( L_4 , V_73 , V_74 ) ;
while ( 1 ) {
F_3 ( V_6 ) ;
F_8 ( F_9 ( V_9 ) , & V_6 , V_52 ) ;
while ( ! ( V_8 = F_12 ( & V_9 -> V_16 ) ) &&
V_15 ) {
if ( F_6 ( V_14 , & V_73 -> V_11 ) )
break;
if ( F_6 ( V_54 , & V_73 -> V_11 ) ) {
error = - V_9 -> V_41 ;
break;
}
if ( V_11 & V_50 ) {
error = - V_75 ;
break;
}
F_23 ( V_9 ) ;
F_10 () ;
F_21 ( V_9 ) ;
if ( F_25 ( V_53 ) ) {
error = - V_76 ;
break;
}
F_8 ( F_9 ( V_9 ) , & V_6 ,
V_52 ) ;
}
F_11 ( F_9 ( V_9 ) , & V_6 ) ;
if ( error )
goto V_29;
if ( ! V_8 ) {
error = - V_40 ;
goto V_29;
}
V_72 = (struct V_71 * ) V_8 -> V_77 ;
V_74 -> V_19 = V_72 -> V_19 ;
F_22 ( V_35 , & V_74 -> V_11 ) ;
V_74 -> V_48 = V_72 -> V_78 ;
V_74 -> V_37 = V_72 -> V_37 ;
V_74 -> V_79 = V_72 -> V_79 ;
error = F_27 ( V_69 , V_72 -> V_80 . V_81 . V_59 ,
V_72 -> V_80 . V_81 . V_60 ,
V_72 -> V_80 . V_81 . V_61 ) ;
F_15 ( V_8 ) ;
V_9 -> V_82 -- ;
if ( error ) {
F_14 ( NULL , V_18 , V_73 , NULL , NULL ,
& V_73 -> V_19 , error ) ;
error = error == - V_75 ? - V_83 : error ;
goto V_29;
}
F_22 ( V_38 , & V_74 -> V_11 ) ;
F_7 ( V_74 , V_84 , V_73 , NULL , NULL ) ;
for (; ; ) {
F_8 ( F_9 ( F_4 ( V_74 ) ) , & V_6 ,
V_13 ) ;
if ( ! F_6 ( V_38 , & V_74 -> V_11 ) || ! V_15 )
break;
F_23 ( V_9 ) ;
F_10 () ;
F_21 ( V_9 ) ;
}
F_11 ( F_9 ( F_4 ( V_74 ) ) , & V_6 ) ;
if ( ! V_15 ) {
error = - V_40 ;
goto V_29;
}
if ( ! F_4 ( V_74 ) -> V_41 )
break;
if ( F_4 ( V_74 ) -> V_41 != V_76 ) {
error = - F_4 ( V_74 ) -> V_41 ;
goto V_29;
}
}
V_69 -> V_26 = V_27 ;
V_29:
F_23 ( V_9 ) ;
return error ;
}
static int F_33 ( struct V_1 * V_2 , struct V_21 * V_21 ,
int * V_22 , int V_85 )
{
struct V_23 * V_24 ;
* V_22 = sizeof( struct V_23 ) ;
V_24 = (struct V_23 * ) V_21 ;
memcpy ( V_24 , V_85 ? & F_18 ( V_2 ) -> V_48 : & F_18 ( V_2 ) -> V_37 ,
sizeof( struct V_23 ) ) ;
return 0 ;
}
int F_34 ( struct V_4 * V_5 , struct V_86 * V_19 )
{
struct V_2 * V_9 = F_4 ( V_5 ) ;
F_3 ( V_6 ) ;
F_22 ( V_38 , & V_5 -> V_11 ) ;
F_14 ( V_5 , V_87 , NULL , NULL , & V_5 -> V_37 , V_19 , 0 ) ;
for (; ; ) {
F_8 ( F_9 ( V_9 ) , & V_6 , V_13 ) ;
if ( ! F_6 ( V_38 , & V_5 -> V_11 ) ||
F_6 ( V_14 , & V_5 -> V_11 ) || ! V_15 ) {
break;
}
F_10 () ;
}
F_11 ( F_9 ( V_9 ) , & V_6 ) ;
if ( ! V_15 )
return - V_40 ;
return - V_9 -> V_41 ;
}
static int F_35 ( struct V_1 * V_2 , int V_88 , int V_89 ,
char T_1 * V_90 , unsigned int V_91 )
{
struct V_2 * V_9 = V_2 -> V_9 ;
struct V_4 * V_5 = F_18 ( V_2 ) ;
int V_92 , error = 0 ;
F_21 ( V_9 ) ;
switch ( V_89 ) {
case V_93 :
if ( V_88 != V_94 || V_91 != sizeof( struct V_95 ) ) {
error = - V_25 ;
goto V_29;
}
if ( F_36 ( & V_5 -> V_79 , V_90 , V_91 ) ) {
error = - V_96 ;
goto V_29;
}
F_22 ( V_97 , & V_5 -> V_11 ) ;
break;
case V_98 :
if ( V_88 != V_94 || V_91 != sizeof( int ) ) {
error = - V_25 ;
goto V_29;
}
if ( F_37 ( V_92 , ( int T_1 * ) V_90 ) ) {
error = - V_96 ;
goto V_29;
}
if ( V_92 == 1 )
F_22 ( V_63 , & V_5 -> V_11 ) ;
else if ( V_92 == 0 )
F_16 ( V_63 , & V_5 -> V_11 ) ;
else
error = - V_25 ;
break;
default:
error = F_38 ( V_2 , V_88 , V_89 , V_90 , V_91 ) ;
}
V_29:
F_23 ( V_9 ) ;
return error ;
}
static int F_39 ( struct V_1 * V_2 , int V_88 , int V_89 ,
char T_1 * V_90 , int T_1 * V_91 )
{
struct V_2 * V_9 = V_2 -> V_9 ;
int error = 0 , V_99 ;
F_21 ( V_9 ) ;
if ( ! F_40 ( V_89 , V_88 ) || V_89 != V_93 ) {
error = F_41 ( V_2 , V_88 , V_89 , V_90 , V_91 ) ;
goto V_29;
}
if ( F_37 ( V_99 , V_91 ) ) {
error = - V_96 ;
goto V_29;
}
if ( V_99 != sizeof( struct V_95 ) ) {
error = - V_25 ;
goto V_29;
}
if ( F_42 ( V_90 , & F_18 ( V_2 ) -> V_79 , sizeof( struct V_95 ) ) ) {
error = - V_96 ;
goto V_29;
}
V_29:
F_23 ( V_9 ) ;
return error ;
}
static int F_43 ( struct V_1 * V_2 , struct V_21 * V_21 ,
int V_22 , int V_11 )
{
F_3 ( V_6 ) ;
struct V_2 * V_9 = V_2 -> V_9 ;
struct V_4 * V_5 = F_18 ( V_2 ) ;
int error ;
F_21 ( V_9 ) ;
F_22 ( V_38 , & V_5 -> V_11 ) ;
F_7 ( V_5 , V_100 , NULL , NULL ,
(struct V_23 * ) V_21 ) ;
if ( V_11 & V_50 ) {
error = - V_51 ;
goto V_29;
}
F_5 ( L_5 ) ;
for (; ; ) {
F_8 ( F_9 ( V_9 ) , & V_6 , V_52 ) ;
if ( ! F_6 ( V_38 , & V_5 -> V_11 ) || ! V_15 )
break;
F_10 () ;
}
F_11 ( F_9 ( V_9 ) , & V_6 ) ;
error = - F_44 ( & V_9 -> V_101 , 0 ) ;
V_29:
F_23 ( V_9 ) ;
return error ;
}
static int F_45 ( struct V_1 * V_2 , int V_102 )
{
F_3 ( V_6 ) ;
struct V_2 * V_9 = V_2 -> V_9 ;
struct V_4 * V_5 = F_18 ( V_2 ) ;
int error ;
F_21 ( V_9 ) ;
F_22 ( V_38 , & V_5 -> V_11 ) ;
F_14 ( V_5 , V_103 , NULL , NULL , NULL , NULL , V_102 ) ;
for (; ; ) {
F_8 ( F_9 ( V_9 ) , & V_6 , V_52 ) ;
if ( ! F_6 ( V_38 , & V_5 -> V_11 ) || ! V_15 )
break;
F_10 () ;
}
F_11 ( F_9 ( V_9 ) , & V_6 ) ;
if ( ! V_15 ) {
error = - V_40 ;
goto V_29;
}
error = - F_44 ( & V_9 -> V_101 , 0 ) ;
V_29:
F_23 ( V_9 ) ;
return error ;
}
static int F_46 ( struct V_1 * V_2 , unsigned int V_104 , unsigned long V_105 )
{
int error , V_102 ;
struct V_23 V_106 ;
struct V_4 * V_5 = F_18 ( V_2 ) ;
switch ( V_104 ) {
case V_107 :
if ( ! F_6 ( V_63 , & V_5 -> V_11 ) )
return - V_25 ;
if ( F_36 ( & V_106 , ( void T_1 * ) V_105 , sizeof( V_106 ) ) )
return - V_96 ;
error = F_43 ( V_2 , (struct V_21 * ) & V_106 , sizeof( V_106 ) ,
0 ) ;
break;
case V_108 :
if ( ! F_6 ( V_63 , & V_5 -> V_11 ) )
return - V_25 ;
if ( F_36 ( & V_102 , ( void T_1 * ) V_105 , sizeof( int ) ) )
return - V_96 ;
error = F_45 ( V_2 , V_102 ) ;
break;
default:
error = F_47 ( V_2 , V_104 , V_105 ) ;
}
return error ;
}
static int F_48 ( struct V_1 * V_2 , unsigned int V_104 ,
unsigned long V_105 )
{
if ( V_104 == V_109 )
V_104 = V_107 ;
if ( V_104 == V_107 || V_104 == V_108 )
return F_46 ( V_2 , V_104 , V_105 ) ;
else
return F_49 ( V_2 , V_104 , V_105 ) ;
}
static int F_31 ( struct V_110 * V_110 , struct V_1 * V_2 , int V_111 ,
int V_70 )
{
int error ;
if ( ! F_50 ( V_110 , & V_112 ) )
return - V_33 ;
V_2 -> V_113 = & V_114 ;
error = F_51 ( V_110 , V_2 , V_111 , V_32 , V_70 ) ;
if ( error )
return error ;
F_18 ( V_2 ) -> V_37 . V_31 = V_32 ;
F_18 ( V_2 ) -> V_48 . V_31 = V_32 ;
return 0 ;
}
int T_2 F_52 ( void )
{
return F_53 ( & V_115 ) ;
}
void F_54 ( void )
{
F_55 ( V_116 ) ;
}
