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
V_1 = malloc ( sizeof( * V_1 ) ) ;
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
F_1 ( V_10 , L_3 ,
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
if ( ! V_1 -> V_37 )
continue;
V_9 -> V_35 . V_21
= F_11 ( V_9 -> V_35 . V_21 ,
V_1 -> V_37 ) ;
}
}
V_10 -> V_34 = V_9 ;
}
V_9 -> V_38 = V_34 ;
return V_9 ;
}
struct V_8 * F_18 ( enum V_33 type , char * V_34 , struct V_21 * V_31 )
{
return F_16 ( type , V_34 , NULL , V_31 ) ;
}
void F_19 ( struct V_21 * V_21 )
{
V_10 -> V_37 = F_11 ( V_10 -> V_37 ,
V_21 ) ;
}
void F_20 ( enum V_33 type , struct V_21 * V_21 , struct V_21 * V_31 )
{
F_16 ( type , NULL , V_21 , V_31 ) ;
}
void F_6 ( enum V_33 type , struct V_15 * V_16 , struct V_21 * V_31 )
{
F_16 ( type , NULL , F_12 ( V_16 ) , V_31 ) ;
}
void F_21 ( int V_39 , char * V_40 )
{
struct V_8 * V_9 ;
switch ( V_39 ) {
case V_41 :
V_9 = F_17 ( V_42 , V_30 ) ;
V_9 -> V_21 = F_12 ( V_10 -> V_16 ) ;
break;
case V_43 :
if ( ! V_44 )
V_44 = V_10 -> V_16 ;
else if ( V_44 != V_10 -> V_16 )
F_22 ( L_7 ) ;
break;
case V_45 :
F_23 ( V_40 ) ;
break;
}
}
static int F_24 ( struct V_15 * V_16 , struct V_15 * V_46 )
{
return V_46 -> type == V_47 || V_46 -> type == V_48 ||
( V_46 -> type == V_32 && F_25 ( V_16 , V_46 -> V_6 ) ) ;
}
static void F_26 ( struct V_15 * V_16 )
{
struct V_8 * V_9 ;
struct V_15 * V_46 ;
for ( V_9 = V_16 -> V_9 ; V_9 ; V_9 = V_9 -> V_19 ) {
switch ( V_9 -> type ) {
case V_42 :
if ( ( V_16 -> type == V_49 || V_16 -> type == V_47 || V_16 -> type == V_48 ) &&
V_9 -> V_21 -> type != V_28 )
F_2 ( V_9 ,
L_8
L_9 , V_16 -> V_6 ) ;
if ( V_9 -> V_21 -> type != V_28 )
break;
V_46 = F_27 ( V_9 ) ;
if ( V_16 -> type == V_48 || V_16 -> type == V_47 ) {
if ( ! F_24 ( V_16 , V_46 ) )
F_2 ( V_9 ,
L_10 ,
V_16 -> V_6 ) ;
}
break;
case V_50 :
V_46 = F_27 ( V_9 ) ;
if ( V_16 -> type != V_51 && V_16 -> type != V_52 )
F_2 ( V_9 ,
L_11
L_12 , V_16 -> V_6 ) ;
else if ( V_46 -> type != V_32 &&
V_46 -> type != V_51 &&
V_46 -> type != V_52 )
F_2 ( V_9 ,
L_13
L_14
L_15 , V_46 -> V_6 ) ;
break;
case V_53 :
if ( V_16 -> type != V_47 && V_16 -> type != V_48 )
F_2 ( V_9 , L_16
L_17 ) ;
if ( ! F_24 ( V_16 , V_9 -> V_21 -> V_24 . V_16 ) ||
! F_24 ( V_16 , V_9 -> V_21 -> V_27 . V_16 ) )
F_2 ( V_9 , L_18 ) ;
break;
default:
;
}
}
}
void F_28 ( struct V_1 * V_17 )
{
struct V_1 * V_1 , * V_54 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
struct V_21 * V_55 , * V_56 , * V_31 , * V_57 , * * V_58 ;
V_16 = V_17 -> V_16 ;
if ( V_17 -> V_14 ) {
if ( V_16 && F_29 ( V_16 ) ) {
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
V_55 = F_12 ( V_16 ) ;
} else if ( V_17 -> V_34 )
V_55 = V_17 -> V_34 -> V_35 . V_21 ;
else
V_55 = V_17 -> V_31 ;
for ( V_1 = V_17 -> V_14 ; V_1 ; V_1 = V_1 -> V_19 ) {
V_56 = F_30 ( V_1 -> V_31 ) ;
V_56 = F_11 ( F_31 ( V_55 ) , V_56 ) ;
V_56 = F_32 ( V_56 ) ;
V_1 -> V_31 = V_56 ;
if ( V_1 -> V_16 )
V_9 = V_1 -> V_16 -> V_9 ;
else
V_9 = V_1 -> V_34 ;
for (; V_9 ; V_9 = V_9 -> V_19 ) {
if ( V_9 -> V_1 != V_1 )
continue;
V_31 = F_30 ( V_9 -> V_35 . V_21 ) ;
V_31 = F_11 ( F_31 ( V_56 ) , V_31 ) ;
V_31 = F_32 ( V_31 ) ;
if ( V_1 -> V_16 && V_1 -> V_16 -> type != V_52 )
V_31 = F_33 ( V_31 ) ;
V_9 -> V_35 . V_21 = V_31 ;
if ( V_9 -> type == V_50 ) {
struct V_15 * V_59 = F_27 ( V_9 ) ;
V_59 -> V_60 . V_21 = F_34 ( V_59 -> V_60 . V_21 ,
F_11 ( F_12 ( V_1 -> V_16 ) , F_31 ( V_31 ) ) ) ;
}
}
}
for ( V_1 = V_17 -> V_14 ; V_1 ; V_1 = V_1 -> V_19 )
F_28 ( V_1 ) ;
} else if ( V_16 ) {
V_56 = V_17 -> V_34 ? V_17 -> V_34 -> V_35 . V_21 : NULL ;
V_56 = F_35 ( V_56 , V_61 , & V_62 ) ;
V_56 = F_32 ( F_30 ( V_56 ) ) ;
V_54 = NULL ;
for ( V_1 = V_17 -> V_19 ; V_1 ; V_1 = V_1 -> V_19 ) {
V_31 = V_1 -> V_34 ? V_1 -> V_34 -> V_35 . V_21 : V_1 -> V_31 ;
if ( ! F_36 ( V_31 , V_16 ) )
break;
if ( F_37 ( V_31 , V_16 ) )
goto V_19;
V_31 = F_35 ( V_31 , V_61 , & V_62 ) ;
V_31 = F_32 ( F_30 ( V_31 ) ) ;
V_57 = F_31 ( V_56 ) ;
F_38 ( & V_31 , & V_57 ) ;
F_39 ( V_31 ) ;
if ( ! F_40 ( V_57 ) ) {
F_39 ( V_57 ) ;
break;
}
F_39 ( V_57 ) ;
V_19:
F_28 ( V_1 ) ;
V_1 -> V_17 = V_17 ;
V_54 = V_1 ;
}
if ( V_54 ) {
V_17 -> V_14 = V_17 -> V_19 ;
V_17 -> V_19 = V_54 -> V_19 ;
V_54 -> V_19 = NULL ;
}
V_16 -> V_63 . V_21 = V_17 -> V_31 ;
}
for ( V_1 = V_17 -> V_14 ; V_1 ; V_1 = V_1 -> V_19 ) {
if ( V_16 && F_29 ( V_16 ) &&
V_1 -> V_16 && ! F_41 ( V_1 -> V_16 ) ) {
V_10 = V_1 ;
V_1 -> V_16 -> V_64 |= V_65 ;
if ( ! V_1 -> V_34 )
F_1 ( V_1 , L_19 ) ;
for ( V_9 = V_1 -> V_16 -> V_9 ; V_9 ; V_9 = V_9 -> V_19 ) {
if ( V_9 -> type == V_42 )
F_2 ( V_9 , L_20
L_21 ) ;
if ( V_9 -> V_1 == V_1 )
continue;
if ( V_9 -> type == V_36 &&
V_9 -> V_1 -> V_17 -> V_16 != V_16 )
F_2 ( V_9 , L_22 ) ;
}
if ( V_16 -> type == V_52 && V_1 -> V_16 -> type != V_52 ) {
V_56 = F_42 ( V_66 , V_16 , & V_67 ) ;
V_1 -> V_31 = F_11 ( V_56 , V_1 -> V_31 ) ;
for ( V_9 = V_1 -> V_16 -> V_9 ; V_9 ; V_9 = V_9 -> V_19 ) {
if ( V_9 -> V_1 != V_1 )
continue;
V_9 -> V_35 . V_21 = F_11 ( F_31 ( V_56 ) ,
V_9 -> V_35 . V_21 ) ;
}
}
F_6 ( V_68 , V_16 , NULL ) ;
V_9 = F_43 ( V_16 ) ;
for ( V_58 = & V_9 -> V_21 ; * V_58 ; V_58 = & ( * V_58 ) -> V_24 . V_21 )
;
* V_58 = F_44 ( V_69 , NULL ) ;
( * V_58 ) -> V_27 . V_16 = V_1 -> V_16 ;
}
if ( V_1 -> V_14 && ( ! V_1 -> V_34 || ! V_1 -> V_34 -> V_38 ) ) {
for ( V_54 = V_1 -> V_14 ; ; V_54 = V_54 -> V_19 ) {
V_54 -> V_17 = V_17 ;
if ( ! V_54 -> V_19 )
break;
}
V_54 -> V_19 = V_1 -> V_19 ;
V_1 -> V_19 = V_1 -> V_14 ;
V_1 -> V_14 = NULL ;
}
}
if ( V_16 && ! ( V_16 -> V_64 & V_70 ) ) {
if ( V_16 -> type == V_32 )
F_1 ( V_17 , L_23 ) ;
if ( F_29 ( V_16 ) && ! V_17 -> V_34 )
F_1 ( V_17 , L_24 ) ;
F_26 ( V_16 ) ;
V_16 -> V_64 |= V_70 ;
}
if ( V_16 && ! F_45 ( V_16 ) && V_17 -> V_34 ) {
V_16 -> V_60 . V_21 = F_34 ( V_16 -> V_60 . V_21 ,
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
struct V_1 * V_71 ;
struct V_15 * V_16 ;
T_2 V_35 ;
if ( ! V_1 -> V_34 )
return false ;
if ( V_1 -> V_37 ) {
if ( F_48 ( V_1 -> V_37 ) == V_72 )
return V_72 ;
}
V_16 = V_1 -> V_16 ;
if ( V_16 ) {
F_49 ( V_16 ) ;
V_35 = V_1 -> V_34 -> V_35 . V_73 ;
} else
V_35 = V_1 -> V_34 -> V_35 . V_73 = F_48 ( V_1 -> V_34 -> V_35 . V_21 ) ;
if ( V_35 != V_72 )
return true ;
if ( ! V_16 || F_50 ( V_1 -> V_16 ) == V_72 )
return false ;
for ( V_71 = V_1 -> V_14 ; V_71 ; V_71 = V_71 -> V_19 ) {
if ( F_47 ( V_71 ) ) {
if ( V_16 )
V_16 -> V_64 |= V_74 ;
return true ;
}
}
return false ;
}
const char * F_51 ( struct V_1 * V_1 )
{
if ( V_1 -> V_34 )
return V_1 -> V_34 -> V_38 ;
else if ( V_1 -> V_16 )
return V_1 -> V_16 -> V_6 ;
return NULL ;
}
struct V_1 * F_52 ( struct V_1 * V_1 )
{
return & V_12 ;
}
struct V_1 * F_53 ( struct V_1 * V_1 )
{
enum V_33 type ;
for (; V_1 != & V_12 ; V_1 = V_1 -> V_17 ) {
type = V_1 -> V_34 ? V_1 -> V_34 -> type : 0 ;
if ( type == V_75 )
break;
}
return V_1 ;
}
bool F_54 ( struct V_1 * V_1 )
{
return V_1 -> V_76 != NULL ;
}
const char * F_55 ( struct V_1 * V_1 )
{
if ( V_1 -> V_76 )
return V_1 -> V_76 ;
else
return L_25 ;
}
static void F_56 ( struct V_77 * V_78 , struct V_8 * V_9 )
{
int V_79 , V_80 ;
struct V_1 * V_81 [ 8 ] , * V_1 ;
F_57 ( V_78 , _ ( L_26 ) , _ ( V_9 -> V_38 ) ) ;
F_57 ( V_78 , _ ( L_27 ) , V_9 -> V_1 -> V_5 -> V_6 ,
V_9 -> V_1 -> V_7 ) ;
if ( ! F_40 ( V_9 -> V_35 . V_21 ) ) {
F_58 ( V_78 , _ ( L_28 ) ) ;
F_59 ( V_9 -> V_35 . V_21 , V_78 ) ;
F_58 ( V_78 , L_2 ) ;
}
V_1 = V_9 -> V_1 -> V_17 ;
for ( V_79 = 0 ; V_1 != & V_12 && V_79 < 8 ; V_1 = V_1 -> V_17 )
V_81 [ V_79 ++ ] = V_1 ;
if ( V_79 > 0 ) {
F_57 ( V_78 , _ ( L_29 ) ) ;
for ( V_80 = 4 ; -- V_79 >= 0 ; V_80 += 2 ) {
V_1 = V_81 [ V_79 ] ;
F_57 ( V_78 , L_30 , V_80 , ' ' , _ ( F_51 ( V_1 ) ) ) ;
if ( V_1 -> V_16 ) {
F_57 ( V_78 , L_31 , V_1 -> V_16 -> V_6 ?
V_1 -> V_16 -> V_6 : _ ( L_4 ) ,
F_60 ( V_1 -> V_16 ) ) ;
}
F_58 ( V_78 , L_2 ) ;
}
}
}
void F_61 ( struct V_77 * V_78 , struct V_15 * V_16 )
{
bool V_82 ;
struct V_8 * V_9 ;
if ( V_16 && V_16 -> V_6 ) {
F_57 ( V_78 , L_32 , V_16 -> V_6 ,
F_60 ( V_16 ) ) ;
F_57 ( V_78 , L_33 , F_15 ( V_16 -> type ) ) ;
if ( V_16 -> type == V_47 || V_16 -> type == V_48 ) {
V_9 = F_62 ( V_16 ) ;
if ( V_9 ) {
F_57 ( V_78 , L_34 ) ;
F_59 ( V_9 -> V_21 , V_78 ) ;
F_58 ( V_78 , L_2 ) ;
}
}
}
F_63 (sym, prop)
F_56 ( V_78 , V_9 ) ;
V_82 = false ;
F_64 (sym, prop, P_SELECT) {
if ( ! V_82 ) {
F_58 ( V_78 , L_35 ) ;
V_82 = true ;
} else
F_57 ( V_78 , L_36 ) ;
F_59 ( V_9 -> V_21 , V_78 ) ;
}
if ( V_82 )
F_58 ( V_78 , L_2 ) ;
if ( V_16 -> V_60 . V_21 ) {
F_58 ( V_78 , _ ( L_37 ) ) ;
F_59 ( V_16 -> V_60 . V_21 , V_78 ) ;
F_58 ( V_78 , L_2 ) ;
}
F_58 ( V_78 , L_38 ) ;
}
struct V_77 F_65 ( struct V_15 * * V_83 )
{
struct V_15 * V_16 ;
struct V_77 V_84 = F_66 () ;
int V_79 ;
for ( V_79 = 0 ; V_83 && ( V_16 = V_83 [ V_79 ] ) ; V_79 ++ )
F_61 ( & V_84 , V_16 ) ;
if ( ! V_79 )
F_58 ( & V_84 , _ ( L_39 ) ) ;
return V_84 ;
}
void F_67 ( struct V_1 * V_1 , struct V_77 * V_76 )
{
struct V_15 * V_16 = V_1 -> V_16 ;
if ( F_54 ( V_1 ) ) {
if ( V_16 -> V_6 ) {
F_57 ( V_76 , L_40 , V_85 , V_16 -> V_6 ) ;
F_58 ( V_76 , _ ( F_55 ( V_1 ) ) ) ;
F_58 ( V_76 , L_2 ) ;
}
} else {
F_58 ( V_76 , V_86 ) ;
}
if ( V_16 )
F_61 ( V_76 , V_16 ) ;
}
