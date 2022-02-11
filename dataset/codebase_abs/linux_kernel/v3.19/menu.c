void F_1 ( struct V_1 * V_1 , const char * V_2 , ... )
{
T_1 V_3 ;
va_start ( V_3 , V_2 ) ;
fprintf ( V_4 , L_1 , V_1 -> V_5 -> V_6 , V_1 -> V_7 ) ;
vfprintf ( V_4 , V_2 , V_3 ) ;
fprintf ( V_4 , L_2 ) ;
va_end ( V_3 ) ;
}
static void F_2 ( struct V_8 * V_9 , const char * V_2 , ... )
{
T_1 V_3 ;
va_start ( V_3 , V_2 ) ;
fprintf ( V_4 , L_1 , V_9 -> V_5 -> V_6 , V_9 -> V_7 ) ;
vfprintf ( V_4 , V_2 , V_3 ) ;
fprintf ( V_4 , L_2 ) ;
va_end ( V_3 ) ;
}
void F_3 ( void )
{
V_10 = V_11 = & V_12 ;
V_13 = & V_12 . V_14 ;
}
void F_4 ( struct V_15 * V_16 )
{
struct V_1 * V_1 ;
V_1 = xmalloc ( sizeof( * V_1 ) ) ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_16 = V_16 ;
V_1 -> V_17 = V_11 ;
V_1 -> V_5 = V_18 ;
V_1 -> V_7 = F_5 () ;
* V_13 = V_1 ;
V_13 = & V_1 -> V_19 ;
V_10 = V_1 ;
if ( V_16 )
F_6 ( V_20 , V_16 , NULL ) ;
}
void F_7 ( void )
{
}
struct V_1 * F_8 ( void )
{
F_7 () ;
V_13 = & V_10 -> V_14 ;
return V_11 = V_10 ;
}
void F_9 ( void )
{
V_13 = & V_11 -> V_19 ;
V_11 = V_11 -> V_17 ;
}
static struct V_21 * F_10 ( struct V_21 * V_22 )
{
if ( ! V_22 )
return V_22 ;
switch ( V_22 -> type ) {
case V_23 :
V_22 -> V_24 . V_21 = F_10 ( V_22 -> V_24 . V_21 ) ;
break;
case V_25 :
case V_26 :
V_22 -> V_24 . V_21 = F_10 ( V_22 -> V_24 . V_21 ) ;
V_22 -> V_27 . V_21 = F_10 ( V_22 -> V_27 . V_21 ) ;
break;
case V_28 :
if ( V_22 -> V_24 . V_16 == & V_29 )
return F_11 ( V_22 , F_12 ( V_30 ) ) ;
break;
default:
break;
}
return V_22 ;
}
void F_13 ( struct V_21 * V_31 )
{
V_10 -> V_31 = F_11 ( V_10 -> V_31 , F_10 ( V_31 ) ) ;
}
void F_14 ( int type )
{
struct V_15 * V_16 = V_10 -> V_16 ;
if ( V_16 -> type == type )
return;
if ( V_16 -> type == V_32 ) {
V_16 -> type = type ;
return;
}
F_1 ( V_10 ,
L_3 ,
V_16 -> V_6 ? V_16 -> V_6 : L_4 ,
F_15 ( V_16 -> type ) , F_15 ( type ) ) ;
}
struct V_8 * F_16 ( enum V_33 type , char * V_34 , struct V_21 * V_21 , struct V_21 * V_31 )
{
struct V_8 * V_9 = F_17 ( type , V_10 -> V_16 ) ;
V_9 -> V_1 = V_10 ;
V_9 -> V_21 = V_21 ;
V_9 -> V_35 . V_21 = F_10 ( V_31 ) ;
if ( V_34 ) {
if ( isspace ( * V_34 ) ) {
F_2 ( V_9 , L_5 ) ;
while ( isspace ( * V_34 ) )
V_34 ++ ;
}
if ( V_10 -> V_34 && V_10 != & V_12 )
F_2 ( V_9 , L_6 ) ;
if( type == V_36 ) {
struct V_1 * V_1 = V_10 ;
while ( ( V_1 = V_1 -> V_17 ) != NULL ) {
struct V_21 * V_37 ;
if ( ! V_1 -> V_38 )
continue;
V_37 = F_18 ( V_1 -> V_38 ) ;
V_9 -> V_35 . V_21
= F_11 ( V_9 -> V_35 . V_21 ,
V_37 ) ;
}
}
V_10 -> V_34 = V_9 ;
}
V_9 -> V_39 = V_34 ;
return V_9 ;
}
struct V_8 * F_19 ( enum V_33 type , char * V_34 , struct V_21 * V_31 )
{
return F_16 ( type , V_34 , NULL , V_31 ) ;
}
void F_20 ( struct V_21 * V_21 )
{
V_10 -> V_38 = F_11 ( V_10 -> V_38 ,
V_21 ) ;
}
void F_21 ( enum V_33 type , struct V_21 * V_21 , struct V_21 * V_31 )
{
F_16 ( type , NULL , V_21 , V_31 ) ;
}
void F_6 ( enum V_33 type , struct V_15 * V_16 , struct V_21 * V_31 )
{
F_16 ( type , NULL , F_12 ( V_16 ) , V_31 ) ;
}
void F_22 ( int V_40 , char * V_41 )
{
switch ( V_40 ) {
case V_42 :
if ( V_30 )
F_23 ( L_7
L_8 ,
V_10 -> V_16 -> V_6 ,
V_30 -> V_6
) ;
V_30 = V_10 -> V_16 ;
break;
case V_43 :
if ( ! V_44 )
V_44 = V_10 -> V_16 ;
else if ( V_44 != V_10 -> V_16 )
F_23 ( L_9 ) ;
break;
case V_45 :
F_24 ( V_41 ) ;
break;
case V_46 :
V_10 -> V_16 -> V_47 |= V_48 ;
break;
}
}
static int F_25 ( struct V_15 * V_16 , struct V_15 * V_49 )
{
return V_49 -> type == V_50 || V_49 -> type == V_51 ||
( V_49 -> type == V_32 && F_26 ( V_16 , V_49 -> V_6 ) ) ;
}
static void F_27 ( struct V_15 * V_16 )
{
struct V_8 * V_9 ;
struct V_15 * V_49 ;
for ( V_9 = V_16 -> V_9 ; V_9 ; V_9 = V_9 -> V_19 ) {
switch ( V_9 -> type ) {
case V_52 :
if ( ( V_16 -> type == V_53 || V_16 -> type == V_50 || V_16 -> type == V_51 ) &&
V_9 -> V_21 -> type != V_28 )
F_2 ( V_9 ,
L_10
L_11 , V_16 -> V_6 ) ;
if ( V_9 -> V_21 -> type != V_28 )
break;
V_49 = F_28 ( V_9 ) ;
if ( V_16 -> type == V_51 || V_16 -> type == V_50 ) {
if ( ! F_25 ( V_16 , V_49 ) )
F_2 ( V_9 ,
L_12 ,
V_16 -> V_6 ) ;
}
break;
case V_54 :
V_49 = F_28 ( V_9 ) ;
if ( V_16 -> type != V_55 && V_16 -> type != V_56 )
F_2 ( V_9 ,
L_13
L_14 , V_16 -> V_6 ) ;
else if ( V_49 -> type != V_32 &&
V_49 -> type != V_55 &&
V_49 -> type != V_56 )
F_2 ( V_9 ,
L_15
L_16
L_17 , V_49 -> V_6 ) ;
break;
case V_57 :
if ( V_16 -> type != V_50 && V_16 -> type != V_51 )
F_2 ( V_9 , L_18
L_19 ) ;
if ( ! F_25 ( V_16 , V_9 -> V_21 -> V_24 . V_16 ) ||
! F_25 ( V_16 , V_9 -> V_21 -> V_27 . V_16 ) )
F_2 ( V_9 , L_20 ) ;
break;
default:
;
}
}
}
void F_29 ( struct V_1 * V_17 )
{
struct V_1 * V_1 , * V_58 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
struct V_21 * V_59 , * V_60 , * V_31 , * V_61 , * * V_62 ;
V_16 = V_17 -> V_16 ;
if ( V_17 -> V_14 ) {
if ( V_16 && F_30 ( V_16 ) ) {
if ( V_16 -> type == V_32 ) {
V_10 = V_17 ;
for ( V_1 = V_17 -> V_14 ; V_1 ; V_1 = V_1 -> V_19 ) {
if ( V_1 -> V_16 && V_1 -> V_16 -> type != V_32 ) {
F_14 ( V_1 -> V_16 -> type ) ;
break;
}
}
}
for ( V_1 = V_17 -> V_14 ; V_1 ; V_1 = V_1 -> V_19 ) {
V_10 = V_1 ;
if ( V_1 -> V_16 && V_1 -> V_16 -> type == V_32 )
F_14 ( V_16 -> type ) ;
}
V_59 = F_12 ( V_16 ) ;
} else if ( V_17 -> V_34 )
V_59 = V_17 -> V_34 -> V_35 . V_21 ;
else
V_59 = V_17 -> V_31 ;
for ( V_1 = V_17 -> V_14 ; V_1 ; V_1 = V_1 -> V_19 ) {
V_60 = F_31 ( V_1 -> V_31 ) ;
V_60 = F_11 ( F_18 ( V_59 ) , V_60 ) ;
V_60 = F_32 ( V_60 ) ;
V_1 -> V_31 = V_60 ;
if ( V_1 -> V_16 )
V_9 = V_1 -> V_16 -> V_9 ;
else
V_9 = V_1 -> V_34 ;
for (; V_9 ; V_9 = V_9 -> V_19 ) {
if ( V_9 -> V_1 != V_1 )
continue;
V_31 = F_31 ( V_9 -> V_35 . V_21 ) ;
V_31 = F_11 ( F_18 ( V_60 ) , V_31 ) ;
V_31 = F_32 ( V_31 ) ;
if ( V_1 -> V_16 && V_1 -> V_16 -> type != V_56 )
V_31 = F_33 ( V_31 ) ;
V_9 -> V_35 . V_21 = V_31 ;
if ( V_9 -> type == V_54 ) {
struct V_15 * V_63 = F_28 ( V_9 ) ;
V_63 -> V_64 . V_21 = F_34 ( V_63 -> V_64 . V_21 ,
F_11 ( F_12 ( V_1 -> V_16 ) , F_18 ( V_31 ) ) ) ;
}
}
}
for ( V_1 = V_17 -> V_14 ; V_1 ; V_1 = V_1 -> V_19 )
F_29 ( V_1 ) ;
} else if ( V_16 ) {
V_60 = V_17 -> V_34 ? V_17 -> V_34 -> V_35 . V_21 : NULL ;
V_60 = F_35 ( V_60 , V_65 , & V_66 ) ;
V_60 = F_32 ( F_31 ( V_60 ) ) ;
V_58 = NULL ;
for ( V_1 = V_17 -> V_19 ; V_1 ; V_1 = V_1 -> V_19 ) {
V_31 = V_1 -> V_34 ? V_1 -> V_34 -> V_35 . V_21 : V_1 -> V_31 ;
if ( ! F_36 ( V_31 , V_16 ) )
break;
if ( F_37 ( V_31 , V_16 ) )
goto V_19;
V_31 = F_35 ( V_31 , V_65 , & V_66 ) ;
V_31 = F_32 ( F_31 ( V_31 ) ) ;
V_61 = F_18 ( V_60 ) ;
F_38 ( & V_31 , & V_61 ) ;
F_39 ( V_31 ) ;
if ( ! F_40 ( V_61 ) ) {
F_39 ( V_61 ) ;
break;
}
F_39 ( V_61 ) ;
V_19:
F_29 ( V_1 ) ;
V_1 -> V_17 = V_17 ;
V_58 = V_1 ;
}
if ( V_58 ) {
V_17 -> V_14 = V_17 -> V_19 ;
V_17 -> V_19 = V_58 -> V_19 ;
V_58 -> V_19 = NULL ;
}
V_16 -> V_67 . V_21 = F_34 ( V_16 -> V_67 . V_21 , V_17 -> V_31 ) ;
}
for ( V_1 = V_17 -> V_14 ; V_1 ; V_1 = V_1 -> V_19 ) {
if ( V_16 && F_30 ( V_16 ) &&
V_1 -> V_16 && ! F_41 ( V_1 -> V_16 ) ) {
V_10 = V_1 ;
V_1 -> V_16 -> V_47 |= V_68 ;
if ( ! V_1 -> V_34 )
F_1 ( V_1 , L_21 ) ;
for ( V_9 = V_1 -> V_16 -> V_9 ; V_9 ; V_9 = V_9 -> V_19 ) {
if ( V_9 -> type == V_52 )
F_2 ( V_9 , L_22
L_23 ) ;
if ( V_9 -> V_1 == V_1 )
continue;
if ( V_9 -> type == V_36 &&
V_9 -> V_1 -> V_17 -> V_16 != V_16 )
F_2 ( V_9 , L_24 ) ;
}
if ( V_16 -> type == V_56 && V_1 -> V_16 -> type != V_56 ) {
V_60 = F_42 ( V_69 , V_16 , & V_70 ) ;
V_1 -> V_31 = F_11 ( V_60 , V_1 -> V_31 ) ;
for ( V_9 = V_1 -> V_16 -> V_9 ; V_9 ; V_9 = V_9 -> V_19 ) {
if ( V_9 -> V_1 != V_1 )
continue;
V_9 -> V_35 . V_21 = F_11 ( F_18 ( V_60 ) ,
V_9 -> V_35 . V_21 ) ;
}
}
F_6 ( V_71 , V_16 , NULL ) ;
V_9 = F_43 ( V_16 ) ;
for ( V_62 = & V_9 -> V_21 ; * V_62 ; V_62 = & ( * V_62 ) -> V_24 . V_21 )
;
* V_62 = F_44 ( V_72 , NULL ) ;
( * V_62 ) -> V_27 . V_16 = V_1 -> V_16 ;
}
if ( V_1 -> V_14 && ( ! V_1 -> V_34 || ! V_1 -> V_34 -> V_39 ) ) {
for ( V_58 = V_1 -> V_14 ; ; V_58 = V_58 -> V_19 ) {
V_58 -> V_17 = V_17 ;
if ( ! V_58 -> V_19 )
break;
}
V_58 -> V_19 = V_1 -> V_19 ;
V_1 -> V_19 = V_1 -> V_14 ;
V_1 -> V_14 = NULL ;
}
}
if ( V_16 && ! ( V_16 -> V_47 & V_73 ) ) {
if ( V_16 -> type == V_32 )
F_1 ( V_17 , L_25 ) ;
if ( F_30 ( V_16 ) && ! V_17 -> V_34 )
F_1 ( V_17 , L_26 ) ;
F_27 ( V_16 ) ;
V_16 -> V_47 |= V_73 ;
}
if ( V_16 && ! F_45 ( V_16 ) && V_17 -> V_34 ) {
V_16 -> V_64 . V_21 = F_34 ( V_16 -> V_64 . V_21 ,
F_11 ( V_17 -> V_34 -> V_35 . V_21 ,
F_12 ( & V_29 ) ) ) ;
}
}
bool F_46 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_34 )
return false ;
return true ;
}
bool F_47 ( struct V_1 * V_1 )
{
struct V_1 * V_74 ;
for ( V_74 = V_1 -> V_14 ; V_74 ; V_74 = V_74 -> V_19 ) {
if ( F_48 ( V_74 ) )
return ( false ) ;
}
return ( true ) ;
}
bool F_48 ( struct V_1 * V_1 )
{
struct V_1 * V_74 ;
struct V_15 * V_16 ;
T_2 V_35 ;
if ( ! V_1 -> V_34 )
return false ;
if ( V_1 -> V_38 ) {
if ( F_49 ( V_1 -> V_38 ) == V_75 )
return V_75 ;
}
V_16 = V_1 -> V_16 ;
if ( V_16 ) {
F_50 ( V_16 ) ;
V_35 = V_1 -> V_34 -> V_35 . V_76 ;
} else
V_35 = V_1 -> V_34 -> V_35 . V_76 = F_49 ( V_1 -> V_34 -> V_35 . V_21 ) ;
if ( V_35 != V_75 )
return true ;
if ( ! V_16 || F_51 ( V_1 -> V_16 ) == V_75 )
return false ;
for ( V_74 = V_1 -> V_14 ; V_74 ; V_74 = V_74 -> V_19 ) {
if ( F_48 ( V_74 ) ) {
if ( V_16 )
V_16 -> V_47 |= V_77 ;
return true ;
}
}
return false ;
}
const char * F_52 ( struct V_1 * V_1 )
{
if ( V_1 -> V_34 )
return V_1 -> V_34 -> V_39 ;
else if ( V_1 -> V_16 )
return V_1 -> V_16 -> V_6 ;
return NULL ;
}
struct V_1 * F_53 ( struct V_1 * V_1 )
{
return & V_12 ;
}
struct V_1 * F_54 ( struct V_1 * V_1 )
{
enum V_33 type ;
for (; V_1 != & V_12 ; V_1 = V_1 -> V_17 ) {
type = V_1 -> V_34 ? V_1 -> V_34 -> type : 0 ;
if ( type == V_78 )
break;
}
return V_1 ;
}
bool F_55 ( struct V_1 * V_1 )
{
return V_1 -> V_79 != NULL ;
}
const char * F_56 ( struct V_1 * V_1 )
{
if ( V_1 -> V_79 )
return V_1 -> V_79 ;
else
return L_27 ;
}
static void F_57 ( struct V_80 * V_81 , struct V_8 * V_9 ,
struct V_82 * V_83 )
{
int V_84 , V_85 ;
struct V_1 * V_86 [ 8 ] , * V_1 , * V_87 = NULL ;
struct V_88 * V_89 = NULL ;
F_58 ( V_81 , _ ( L_28 ) , _ ( V_9 -> V_39 ) ) ;
V_1 = V_9 -> V_1 -> V_17 ;
for ( V_84 = 0 ; V_1 != & V_12 && V_84 < 8 ; V_1 = V_1 -> V_17 ) {
bool V_90 = F_48 ( V_1 ) ;
V_86 [ V_84 ++ ] = V_1 ;
if ( V_87 == NULL && V_90 )
V_87 = V_1 ;
}
if ( V_83 && V_87 ) {
V_89 = xmalloc ( sizeof( struct V_88 ) ) ;
if ( F_48 ( V_9 -> V_1 ) ) {
V_89 -> V_91 = V_9 -> V_1 ;
} else
V_89 -> V_91 = V_87 ;
if ( F_59 ( V_83 ) )
V_89 -> V_92 = 0 ;
else
V_89 -> V_92 = F_60 ( V_83 -> V_93 , struct V_88 ,
V_94 ) -> V_92 + 1 ;
F_61 ( & V_89 -> V_94 , V_83 ) ;
}
if ( V_84 > 0 ) {
F_58 ( V_81 , _ ( L_29 ) ) ;
for ( V_85 = 4 ; -- V_84 >= 0 ; V_85 += 2 ) {
V_1 = V_86 [ V_84 ] ;
if ( V_89 && V_1 == V_87 )
V_89 -> V_95 = strlen ( V_81 -> V_96 ) ;
F_58 ( V_81 , L_30 , V_85 , ' ' ,
_ ( F_52 ( V_1 ) ) ) ;
if ( V_1 -> V_16 ) {
F_58 ( V_81 , L_31 , V_1 -> V_16 -> V_6 ?
V_1 -> V_16 -> V_6 : _ ( L_4 ) ,
F_62 ( V_1 -> V_16 ) ) ;
}
F_63 ( V_81 , L_2 ) ;
}
}
}
static struct V_8 * F_64 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = NULL ;
F_65 (sym, prop, P_SYMBOL)
break;
return V_9 ;
}
void F_66 ( struct V_80 * V_81 , struct V_15 * V_16 ,
struct V_82 * V_83 )
{
bool V_97 ;
struct V_8 * V_9 ;
if ( V_16 && V_16 -> V_6 ) {
F_58 ( V_81 , L_32 , V_16 -> V_6 ,
F_62 ( V_16 ) ) ;
F_58 ( V_81 , L_33 , F_15 ( V_16 -> type ) ) ;
if ( V_16 -> type == V_50 || V_16 -> type == V_51 ) {
V_9 = F_67 ( V_16 ) ;
if ( V_9 ) {
F_58 ( V_81 , L_34 ) ;
F_68 ( V_9 -> V_21 , V_81 ) ;
F_63 ( V_81 , L_2 ) ;
}
}
}
F_69 (sym, prop)
F_57 ( V_81 , V_9 , V_83 ) ;
V_9 = F_64 ( V_16 ) ;
if ( V_9 ) {
F_58 ( V_81 , _ ( L_35 ) , V_9 -> V_1 -> V_5 -> V_6 ,
V_9 -> V_1 -> V_7 ) ;
if ( ! F_40 ( V_9 -> V_35 . V_21 ) ) {
F_63 ( V_81 , _ ( L_36 ) ) ;
F_68 ( V_9 -> V_35 . V_21 , V_81 ) ;
F_63 ( V_81 , L_2 ) ;
}
}
V_97 = false ;
F_65 (sym, prop, P_SELECT) {
if ( ! V_97 ) {
F_63 ( V_81 , L_37 ) ;
V_97 = true ;
} else
F_58 ( V_81 , L_38 ) ;
F_68 ( V_9 -> V_21 , V_81 ) ;
}
if ( V_97 )
F_63 ( V_81 , L_2 ) ;
if ( V_16 -> V_64 . V_21 ) {
F_63 ( V_81 , _ ( L_39 ) ) ;
F_68 ( V_16 -> V_64 . V_21 , V_81 ) ;
F_63 ( V_81 , L_2 ) ;
}
F_63 ( V_81 , L_40 ) ;
}
struct V_80 F_70 ( struct V_15 * * V_98 , struct V_82 * V_83 )
{
struct V_15 * V_16 ;
struct V_80 V_99 = F_71 () ;
int V_84 ;
for ( V_84 = 0 ; V_98 && ( V_16 = V_98 [ V_84 ] ) ; V_84 ++ )
F_66 ( & V_99 , V_16 , V_83 ) ;
if ( ! V_84 )
F_63 ( & V_99 , _ ( L_41 ) ) ;
return V_99 ;
}
void F_72 ( struct V_1 * V_1 , struct V_80 * V_79 )
{
struct V_15 * V_16 = V_1 -> V_16 ;
const char * V_100 = V_101 ;
if ( F_55 ( V_1 ) ) {
if ( V_16 -> V_6 )
F_58 ( V_79 , L_42 , V_102 , V_16 -> V_6 ) ;
V_100 = F_56 ( V_1 ) ;
}
F_58 ( V_79 , L_43 , _ ( V_100 ) ) ;
if ( V_16 )
F_66 ( V_79 , V_16 , NULL ) ;
}
