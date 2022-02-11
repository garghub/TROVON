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
T_3 V_20 , int * V_21 )
{
return - V_22 ;
}
int __weak F_9 ( int V_23 )
{
return - V_22 ;
}
int __weak F_10 ( int V_23 )
{
return - V_22 ;
}
void __weak F_11 ( int V_23 ) {}
int __weak F_12 ( T_2 V_19 , int V_23 , int V_20 )
{
return - V_22 ;
}
static int F_13 ( struct V_24 * V_25 )
{
unsigned long long V_26 ;
T_4 V_27 ;
int V_28 ;
if ( F_14 ( V_25 -> V_29 ) )
return - V_22 ;
V_27 = F_15 ( V_25 -> V_19 , L_8 , NULL , & V_26 ) ;
if ( F_16 ( V_27 ) || ! ( V_26 & V_30 ) )
return - V_22 ;
F_17 () ;
F_18 () ;
V_28 = F_8 ( V_25 -> V_19 , V_25 -> V_29 , & V_25 -> V_31 ) ;
if ( V_28 )
goto V_32;
V_28 = F_10 ( V_25 -> V_31 ) ;
if ( V_28 ) {
F_9 ( V_25 -> V_31 ) ;
goto V_32;
}
F_19 ( L_9 , V_25 -> V_31 ) ;
V_25 -> V_33 . V_34 = 1 ;
V_32:
F_20 () ;
F_21 () ;
return V_28 ;
}
static inline int F_13 ( struct V_24 * V_25 )
{
return - V_22 ;
}
static int F_22 ( struct V_35 * V_36 )
{
union V_37 V_38 = { 0 } ;
struct V_39 V_40 = { sizeof( union V_37 ) , & V_38 } ;
struct V_24 * V_25 = F_23 ( V_36 ) ;
int V_41 = 0 ;
T_4 V_27 = V_42 ;
static int V_43 ;
unsigned long long V_44 ;
F_7 () ;
if ( V_45 . V_46 && V_45 . V_47 ) {
V_25 -> V_33 . V_48 = 1 ;
F_2 ( ( V_7 ,
L_10 ) ) ;
} else
F_2 ( ( V_7 ,
L_11 ) ) ;
if ( ! strcmp ( F_24 ( V_36 ) , V_49 ) ) {
V_27 = F_25 ( V_25 -> V_19 , NULL , NULL , & V_40 ) ;
if ( F_16 ( V_27 ) ) {
F_26 ( & V_36 -> V_2 ,
L_12 ,
V_27 ) ;
return - V_22 ;
}
V_25 -> V_50 = V_38 . V_51 . V_52 ;
} else {
V_27 = F_15 ( V_25 -> V_19 , V_53 ,
NULL , & V_44 ) ;
if ( F_16 ( V_27 ) ) {
F_26 ( & V_36 -> V_2 ,
L_13 ,
V_27 ) ;
return - V_22 ;
}
V_41 = 1 ;
V_25 -> V_50 = V_44 ;
}
V_25 -> V_29 = F_27 ( V_25 -> V_19 , V_41 ,
V_25 -> V_50 ) ;
if ( F_14 ( V_25 -> V_29 ) )
F_28 ( V_25 -> V_19 , L_14 ) ;
V_25 -> V_31 = F_29 ( V_25 -> V_29 , V_25 -> V_50 ) ;
if ( ! V_43 && ! F_30 () ) {
V_43 = 1 ;
if ( F_31 ( V_25 -> V_31 ) && ( F_32 () == 1 ) )
V_25 -> V_31 = 0 ;
}
if ( F_31 ( V_25 -> V_31 ) || ! F_33 ( V_25 -> V_31 ) ) {
int V_28 = F_13 ( V_25 ) ;
if ( V_28 )
return V_28 ;
}
sprintf ( F_34 ( V_36 ) , L_15 , V_25 -> V_31 ) ;
F_2 ( ( V_7 , L_16 , V_25 -> V_31 ,
V_25 -> V_50 ) ) ;
if ( ! V_38 . V_51 . V_54 )
F_2 ( ( V_7 , L_17 ) ) ;
else if ( V_38 . V_51 . V_55 != 6 )
F_26 ( & V_36 -> V_2 , L_18 ,
V_38 . V_51 . V_55 ) ;
else {
V_25 -> V_56 . V_57 = V_38 . V_51 . V_54 ;
V_25 -> V_56 . V_58 = V_45 . V_58 ;
V_25 -> V_56 . V_59 = V_45 . V_59 ;
V_25 -> V_60 = V_38 . V_51 . V_54 ;
}
V_27 = F_15 ( V_25 -> V_19 , L_19 , NULL , & V_44 ) ;
if ( F_35 ( V_27 ) )
F_36 ( V_25 -> V_31 , V_44 ) ;
return 0 ;
}
static int F_37 ( struct V_35 * V_36 ,
const struct V_61 * V_31 )
{
struct V_24 * V_25 ;
struct V_36 * V_2 ;
int V_17 = 0 ;
V_25 = F_38 ( sizeof( struct V_24 ) , V_62 ) ;
if ( ! V_25 )
return - V_63 ;
if ( ! F_39 ( & V_25 -> V_56 . V_64 , V_62 ) ) {
V_17 = - V_63 ;
goto V_65;
}
V_25 -> V_19 = V_36 -> V_19 ;
strcpy ( F_40 ( V_36 ) , V_66 ) ;
strcpy ( F_41 ( V_36 ) , V_67 ) ;
V_36 -> V_68 = V_25 ;
V_17 = F_22 ( V_36 ) ;
if ( V_17 )
return 0 ;
#ifdef F_42
if ( V_25 -> V_31 >= V_69 && V_25 -> V_31 != 0 )
return 0 ;
#endif
F_43 ( V_25 -> V_31 >= V_70 ) ;
if ( F_44 ( V_71 , V_25 -> V_31 ) != NULL &&
F_44 ( V_71 , V_25 -> V_31 ) != V_36 ) {
F_45 ( & V_36 -> V_2 ,
L_20 ,
V_25 -> V_31 ) ;
goto V_72;
}
F_44 ( V_71 , V_25 -> V_31 ) = V_36 ;
F_44 ( V_73 , V_25 -> V_31 ) = V_25 ;
V_2 = F_46 ( V_25 -> V_31 ) ;
if ( ! V_2 ) {
V_17 = - V_22 ;
goto V_72;
}
V_17 = F_47 ( V_2 , V_36 ) ;
if ( V_17 )
goto V_72;
V_25 -> V_2 = V_2 ;
if ( F_48 ( V_2 ) >= 0 )
return 1 ;
F_26 ( V_2 , L_21 ) ;
F_49 ( V_2 ) ;
V_72:
F_50 ( V_25 -> V_56 . V_64 ) ;
V_36 -> V_68 = NULL ;
F_44 ( V_73 , V_25 -> V_31 ) = NULL ;
V_65:
F_51 ( V_25 ) ;
return V_17 ;
}
static void F_52 ( struct V_35 * V_36 )
{
struct V_24 * V_25 ;
if ( ! V_36 || ! F_23 ( V_36 ) )
return;
V_25 = F_23 ( V_36 ) ;
if ( V_25 -> V_31 >= V_70 )
goto V_32;
F_53 ( V_25 -> V_2 ) ;
F_49 ( V_25 -> V_2 ) ;
F_44 ( V_71 , V_25 -> V_31 ) = NULL ;
F_44 ( V_73 , V_25 -> V_31 ) = NULL ;
F_17 () ;
F_18 () ;
F_11 ( V_25 -> V_31 ) ;
F_9 ( V_25 -> V_31 ) ;
F_20 () ;
F_21 () ;
F_54 ( F_55 ( V_25 -> V_31 ) ) ;
V_32:
F_50 ( V_25 -> V_56 . V_64 ) ;
F_51 ( V_25 ) ;
}
static T_4 T_5 F_56 ( T_2 V_19 ,
T_6 V_74 ,
void * V_75 ,
void * * V_76 )
{
T_1 V_77 [] = L_22 ;
T_6 V_78 [ 2 ] ;
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
if ( V_80 . V_28 . V_85 && V_80 . V_28 . V_84 > 1 ) {
T_6 * V_88 = V_80 . V_28 . V_85 ;
if ( V_88 [ 1 ] & 0x1000 ) {
F_58 ( V_19 ,
L_23 ) ;
V_86 = true ;
}
}
F_51 ( V_80 . V_28 . V_85 ) ;
}
return V_42 ;
}
void T_5 F_59 ( void )
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
static int F_63 ( struct V_35 * V_2 ,
const struct V_61 * V_31 )
{
return 1 ;
}
static void T_5 F_64 ( int V_52 )
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
static T_4 T_5 F_65 ( T_2 V_19 ,
T_6 V_74 ,
void * V_75 ,
void * * V_76 )
{
T_4 V_27 ;
union V_37 V_38 = { 0 } ;
struct V_39 V_40 = { sizeof( union V_37 ) , & V_38 } ;
V_27 = F_25 ( V_19 , NULL , NULL , & V_40 ) ;
if ( F_16 ( V_27 ) )
F_58 ( V_19 , L_24 ) ;
else
F_64 ( V_38 . V_51 . V_52 ) ;
return V_42 ;
}
static void T_5 F_66 ( void )
{
F_61 ( V_90 , V_91 ,
V_92 ,
F_65 ,
NULL , NULL , NULL ) ;
}
bool T_5 F_67 ( int V_52 )
{
int V_94 ;
for ( V_94 = 0 ; V_94 < V_97 ; V_94 ++ ) {
if ( V_98 [ V_94 ] == V_52 )
return true ;
}
return false ;
}
void T_5 F_68 ( void )
{
F_66 () ;
F_69 ( & V_100 , L_25 ) ;
F_70 ( & V_101 ) ;
}
