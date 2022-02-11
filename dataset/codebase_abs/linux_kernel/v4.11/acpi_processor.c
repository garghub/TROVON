static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
T_1 V_4 = 0 ;
if ( ! V_2 )
return - V_5 ;
switch ( V_2 -> V_6 ) {
case 0 :
F_2 ( ( V_7 , L_1 ) ) ;
break;
case 1 :
F_2 ( ( V_7 , L_2 ) ) ;
break;
case 2 :
F_2 ( ( V_7 , L_3 ) ) ;
break;
case 3 :
F_2 ( ( V_7 , L_4 ) ) ;
break;
default:
F_2 ( ( V_7 , L_5 ) ) ;
break;
}
switch ( V_2 -> V_6 ) {
case 0 :
case 1 :
V_8 . V_9 . V_10 = 1 ;
case 2 :
case 3 :
V_2 = F_3 ( V_11 ,
V_12 ,
V_13 , V_13 , NULL ) ;
if ( V_2 ) {
V_8 . V_9 . V_14 = F_4 ( V_2 , 4 ) ;
F_5 ( V_2 ) ;
}
V_2 = F_3 ( V_11 ,
V_15 ,
V_13 , V_13 , NULL ) ;
if ( V_2 ) {
F_6 ( V_2 , 0x76 , & V_3 ) ;
F_6 ( V_2 , 0x77 , & V_4 ) ;
if ( ( V_3 & 0x80 ) || ( V_4 & 0x80 ) )
V_8 . V_9 . V_16 = 1 ;
F_5 ( V_2 ) ;
}
break;
}
if ( V_8 . V_9 . V_14 )
F_2 ( ( V_7 ,
L_6 ) ) ;
if ( V_8 . V_9 . V_16 )
F_2 ( ( V_7 ,
L_7 ) ) ;
return 0 ;
}
static int F_7 ( void )
{
int V_17 = 0 ;
struct V_1 * V_2 = NULL ;
V_2 = F_3 ( V_11 ,
V_18 , V_13 ,
V_13 , NULL ) ;
if ( V_2 ) {
V_17 = F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
}
return V_17 ;
}
int __weak F_8 ( T_2 V_19 ,
T_3 V_20 , T_4 V_21 , int * V_22 )
{
return - V_23 ;
}
int __weak F_9 ( int V_24 )
{
return - V_23 ;
}
int __weak F_10 ( int V_24 )
{
return - V_23 ;
}
void __weak F_11 ( int V_24 ) {}
static int F_12 ( struct V_25 * V_26 )
{
unsigned long long V_27 ;
T_5 V_28 ;
int V_29 ;
if ( F_13 ( V_26 -> V_30 ) )
return - V_23 ;
V_28 = F_14 ( V_26 -> V_19 , L_8 , NULL , & V_27 ) ;
if ( F_15 ( V_28 ) || ! ( V_27 & V_31 ) )
return - V_23 ;
F_16 () ;
F_17 () ;
V_29 = F_8 ( V_26 -> V_19 , V_26 -> V_30 , V_26 -> V_21 , & V_26 -> V_32 ) ;
if ( V_29 )
goto V_33;
V_29 = F_10 ( V_26 -> V_32 ) ;
if ( V_29 ) {
F_9 ( V_26 -> V_32 ) ;
goto V_33;
}
F_18 ( L_9 , V_26 -> V_32 ) ;
V_26 -> V_34 . V_35 = 1 ;
V_33:
F_19 () ;
F_20 () ;
return V_29 ;
}
static inline int F_12 ( struct V_25 * V_26 )
{
return - V_23 ;
}
static int F_21 ( struct V_36 * V_37 )
{
union V_38 V_39 = { 0 } ;
struct V_40 V_41 = { sizeof( union V_38 ) , & V_39 } ;
struct V_25 * V_26 = F_22 ( V_37 ) ;
int V_42 = 0 ;
T_5 V_28 = V_43 ;
static int V_44 ;
unsigned long long V_45 ;
F_7 () ;
if ( V_46 . V_47 && V_46 . V_48 ) {
V_26 -> V_34 . V_49 = 1 ;
F_2 ( ( V_7 ,
L_10 ) ) ;
} else
F_2 ( ( V_7 ,
L_11 ) ) ;
if ( ! strcmp ( F_23 ( V_37 ) , V_50 ) ) {
V_28 = F_24 ( V_26 -> V_19 , NULL , NULL , & V_41 ) ;
if ( F_15 ( V_28 ) ) {
F_25 ( & V_37 -> V_2 ,
L_12 ,
V_28 ) ;
return - V_23 ;
}
V_26 -> V_21 = V_39 . V_51 . V_52 ;
} else {
V_28 = F_14 ( V_26 -> V_19 , V_53 ,
NULL , & V_45 ) ;
if ( F_15 ( V_28 ) ) {
F_25 ( & V_37 -> V_2 ,
L_13 ,
V_28 ) ;
return - V_23 ;
}
V_42 = 1 ;
V_26 -> V_21 = V_45 ;
}
if ( F_26 ( V_26 -> V_21 ) ) {
F_25 ( & V_37 -> V_2 ,
L_14 ,
V_26 -> V_21 ) ;
return - V_23 ;
}
V_26 -> V_30 = F_27 ( V_26 -> V_19 , V_42 ,
V_26 -> V_21 ) ;
if ( F_13 ( V_26 -> V_30 ) )
F_28 ( V_26 -> V_19 , L_15 ) ;
V_26 -> V_32 = F_29 ( V_26 -> V_30 , V_26 -> V_21 ) ;
if ( ! V_44 && ! F_30 () ) {
V_44 = 1 ;
if ( F_31 ( V_26 -> V_32 ) && ( F_32 () == 1 ) )
V_26 -> V_32 = 0 ;
}
if ( F_31 ( V_26 -> V_32 ) || ! F_33 ( V_26 -> V_32 ) ) {
int V_29 = F_12 ( V_26 ) ;
if ( V_29 )
return V_29 ;
}
sprintf ( F_34 ( V_37 ) , L_16 , V_26 -> V_32 ) ;
F_2 ( ( V_7 , L_17 , V_26 -> V_32 ,
V_26 -> V_21 ) ) ;
if ( ! V_39 . V_51 . V_54 )
F_2 ( ( V_7 , L_18 ) ) ;
else if ( V_39 . V_51 . V_55 != 6 )
F_25 ( & V_37 -> V_2 , L_19 ,
V_39 . V_51 . V_55 ) ;
else {
V_26 -> V_56 . V_57 = V_39 . V_51 . V_54 ;
V_26 -> V_56 . V_58 = V_46 . V_58 ;
V_26 -> V_56 . V_59 = V_46 . V_59 ;
V_26 -> V_60 = V_39 . V_51 . V_54 ;
}
V_28 = F_14 ( V_26 -> V_19 , L_20 , NULL , & V_45 ) ;
if ( F_35 ( V_28 ) )
F_36 ( V_26 -> V_32 , V_45 ) ;
return 0 ;
}
static int F_37 ( struct V_36 * V_37 ,
const struct V_61 * V_32 )
{
struct V_25 * V_26 ;
struct V_37 * V_2 ;
int V_17 = 0 ;
V_26 = F_38 ( sizeof( struct V_25 ) , V_62 ) ;
if ( ! V_26 )
return - V_63 ;
if ( ! F_39 ( & V_26 -> V_56 . V_64 , V_62 ) ) {
V_17 = - V_63 ;
goto V_65;
}
V_26 -> V_19 = V_37 -> V_19 ;
strcpy ( F_40 ( V_37 ) , V_66 ) ;
strcpy ( F_41 ( V_37 ) , V_67 ) ;
V_37 -> V_68 = V_26 ;
V_17 = F_21 ( V_37 ) ;
if ( V_17 )
return 0 ;
#ifdef F_42
if ( V_26 -> V_32 >= V_69 && V_26 -> V_32 != 0 )
return 0 ;
#endif
F_43 ( V_26 -> V_32 >= V_70 ) ;
if ( F_44 ( V_71 , V_26 -> V_32 ) != NULL &&
F_44 ( V_71 , V_26 -> V_32 ) != V_37 ) {
F_45 ( & V_37 -> V_2 ,
L_21 ,
V_26 -> V_32 ) ;
goto V_72;
}
F_44 ( V_71 , V_26 -> V_32 ) = V_37 ;
F_44 ( V_73 , V_26 -> V_32 ) = V_26 ;
V_2 = F_46 ( V_26 -> V_32 ) ;
if ( ! V_2 ) {
V_17 = - V_23 ;
goto V_72;
}
V_17 = F_47 ( V_2 , V_37 ) ;
if ( V_17 )
goto V_72;
V_26 -> V_2 = V_2 ;
if ( F_48 ( V_2 ) >= 0 )
return 1 ;
F_25 ( V_2 , L_22 ) ;
F_49 ( V_2 ) ;
V_72:
F_50 ( V_26 -> V_56 . V_64 ) ;
V_37 -> V_68 = NULL ;
F_44 ( V_73 , V_26 -> V_32 ) = NULL ;
V_65:
F_51 ( V_26 ) ;
return V_17 ;
}
static void F_52 ( struct V_36 * V_37 )
{
struct V_25 * V_26 ;
if ( ! V_37 || ! F_22 ( V_37 ) )
return;
V_26 = F_22 ( V_37 ) ;
if ( V_26 -> V_32 >= V_70 )
goto V_33;
F_53 ( V_26 -> V_2 ) ;
F_49 ( V_26 -> V_2 ) ;
F_44 ( V_71 , V_26 -> V_32 ) = NULL ;
F_44 ( V_73 , V_26 -> V_32 ) = NULL ;
F_16 () ;
F_17 () ;
F_11 ( V_26 -> V_32 ) ;
F_9 ( V_26 -> V_32 ) ;
F_19 () ;
F_20 () ;
F_54 ( F_55 ( V_26 -> V_32 ) ) ;
V_33:
F_50 ( V_26 -> V_56 . V_64 ) ;
F_51 ( V_26 ) ;
}
static T_5 T_6 F_56 ( T_2 V_19 ,
T_4 V_74 ,
void * V_75 ,
void * * V_76 )
{
T_1 V_77 [] = L_23 ;
T_4 V_78 [ 2 ] ;
struct V_79 V_80 = {
. V_81 = V_77 ,
. V_82 = 1 ,
. V_83 . V_84 = 8 ,
. V_83 . V_85 = V_78 ,
} ;
if ( V_86 )
return V_87 ;
V_78 [ 0 ] = 0x0000 ;
V_78 [ 1 ] = 0x1000 ;
if ( F_35 ( F_57 ( V_19 , & V_80 ) ) ) {
if ( V_80 . V_29 . V_85 && V_80 . V_29 . V_84 > 1 ) {
T_4 * V_88 = V_80 . V_29 . V_85 ;
if ( V_88 [ 1 ] & 0x1000 ) {
F_58 ( V_19 ,
L_24 ) ;
V_86 = true ;
}
}
F_51 ( V_80 . V_29 . V_85 ) ;
}
return V_43 ;
}
void T_6 F_59 ( void )
{
if ( F_60 ( V_89 ) ) {
F_61 ( V_90 , V_91 ,
V_92 ,
F_56 ,
NULL , NULL , NULL ) ;
F_62 ( V_93 ,
F_56 ,
NULL , NULL ) ;
}
}
static int F_63 ( struct V_36 * V_2 ,
const struct V_61 * V_32 )
{
return 1 ;
}
static void T_6 F_64 ( int V_52 )
{
int V_94 ;
if ( V_95 == V_96 || V_97 == V_96 )
return;
for ( V_94 = 0 ; V_94 < V_97 ; V_94 ++ ) {
if ( V_98 [ V_94 ] == V_52 )
return;
}
for ( V_94 = 0 ; V_94 < V_95 ; V_94 ++ ) {
if ( V_99 [ V_94 ] == V_52 ) {
V_98 [ V_97 ] = V_52 ;
V_97 ++ ;
return;
}
}
V_99 [ V_95 ] = V_52 ;
V_95 ++ ;
}
static T_5 T_6 F_65 ( T_2 V_19 ,
T_4 V_74 ,
void * V_75 ,
void * * V_76 )
{
T_5 V_28 ;
T_7 V_100 ;
unsigned long long V_101 ;
union V_38 V_39 = { 0 } ;
struct V_40 V_41 = { sizeof( union V_38 ) , & V_39 } ;
V_28 = F_66 ( V_19 , & V_100 ) ;
if ( F_15 ( V_28 ) )
return false ;
switch ( V_100 ) {
case V_90 :
V_28 = F_24 ( V_19 , NULL , NULL , & V_41 ) ;
if ( F_15 ( V_28 ) )
goto V_72;
V_101 = V_39 . V_51 . V_52 ;
break;
case V_102 :
V_28 = F_14 ( V_19 , L_25 , NULL , & V_101 ) ;
if ( F_15 ( V_28 ) )
goto V_72;
break;
default:
goto V_72;
}
F_64 ( V_101 ) ;
return true ;
V_72:
F_58 ( V_19 , L_26 ) ;
return false ;
}
void T_6 F_67 ( void )
{
F_61 ( V_90 , V_91 ,
V_92 ,
F_65 ,
NULL , NULL , NULL ) ;
F_62 ( V_93 , F_65 ,
NULL , NULL ) ;
}
bool F_26 ( int V_52 )
{
int V_94 ;
for ( V_94 = 0 ; V_94 < V_97 ; V_94 ++ ) {
if ( V_98 [ V_94 ] == V_52 )
return true ;
}
return false ;
}
void T_6 F_68 ( void )
{
F_67 () ;
F_69 ( & V_103 , L_27 ) ;
F_70 ( & V_104 ) ;
}
