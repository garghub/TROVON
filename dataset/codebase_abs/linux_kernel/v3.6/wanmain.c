static int T_1 F_1 ( void )
{
int V_1 ;
F_2 ( V_2 L_1 ,
V_3 , V_4 , V_5 ,
V_6 ) ;
V_1 = F_3 () ;
if ( V_1 )
F_2 ( V_2 L_2 ,
V_7 ) ;
return V_1 ;
}
static void T_2 F_4 ( void )
{
F_5 () ;
}
int F_6 ( struct V_8 * V_9 )
{
int V_1 , V_10 ;
if ( ( V_9 == NULL ) || ( V_9 -> V_11 != V_12 ) ||
( V_9 -> V_13 == NULL ) )
return - V_14 ;
V_10 = strlen ( V_9 -> V_13 ) ;
if ( ! V_10 || ( V_10 > V_15 ) )
return - V_14 ;
if ( F_7 ( V_9 -> V_13 ) )
return - V_16 ;
#ifdef F_8
F_2 ( V_2 L_3 ,
V_7 , V_9 -> V_13 ) ;
#endif
V_1 = F_9 ( V_9 ) ;
if ( V_1 ) {
F_2 ( V_2
L_4 ,
V_7 , V_9 -> V_13 ) ;
return V_1 ;
}
V_9 -> V_17 = 0 ;
V_9 -> V_18 = NULL ;
V_9 -> V_19 = V_20 ;
V_20 = V_9 ;
return 0 ;
}
int F_10 ( char * V_13 )
{
struct V_8 * V_9 , * V_21 ;
if ( V_13 == NULL )
return - V_14 ;
for ( V_9 = V_20 , V_21 = NULL ;
V_9 && strcmp ( V_9 -> V_13 , V_13 ) ;
V_21 = V_9 , V_9 = V_9 -> V_19 )
;
if ( V_9 == NULL )
return - V_22 ;
#ifdef F_8
F_2 ( V_2 L_5 ,
V_7 , V_13 ) ;
#endif
if ( V_9 -> V_23 != V_24 )
F_11 ( V_9 ) ;
if ( V_21 )
V_21 -> V_19 = V_9 -> V_19 ;
else
V_20 = V_9 -> V_19 ;
F_12 ( V_9 ) ;
return 0 ;
}
long F_13 ( struct V_25 * V_25 , unsigned int V_26 , unsigned long V_27 )
{
struct V_28 * V_28 = V_25 -> V_29 . V_30 -> V_31 ;
int V_1 = 0 ;
struct V_32 * V_33 ;
struct V_8 * V_9 ;
void T_3 * V_34 = ( void T_3 * ) V_27 ;
if ( ! F_14 ( V_35 ) )
return - V_36 ;
if ( ( V_26 >> 8 ) != V_37 )
return - V_14 ;
V_33 = F_15 ( V_28 ) ;
if ( ( V_33 == NULL ) || ( V_33 -> V_34 == NULL ) )
return - V_14 ;
V_9 = V_33 -> V_34 ;
if ( V_9 -> V_11 != V_12 )
return - V_14 ;
F_16 ( & V_38 ) ;
switch ( V_26 ) {
case V_39 :
V_1 = F_17 ( V_9 , V_34 ) ;
break;
case V_40 :
V_1 = F_11 ( V_9 ) ;
break;
case V_41 :
V_1 = F_18 ( V_9 , V_34 ) ;
break;
case V_42 :
V_1 = F_19 ( V_9 , V_34 ) ;
break;
case V_43 :
V_1 = F_20 ( V_9 , V_34 ) ;
break;
case V_44 :
break;
default:
if ( ( V_26 >= V_45 ) &&
( V_26 <= V_46 ) &&
V_9 -> V_47 )
V_1 = V_9 -> V_47 ( V_9 , V_26 , V_27 ) ;
else V_1 = - V_14 ;
}
F_21 ( & V_38 ) ;
return V_1 ;
}
static int F_17 ( struct V_8 * V_9 ,
T_4 T_3 * V_48 )
{
void * V_34 = NULL ;
T_4 * V_49 ;
int V_1 = - V_14 ;
if ( V_9 -> V_50 == NULL ) {
F_2 ( V_2 L_6 ,
V_9 -> V_13 ) ;
return 0 ;
}
V_49 = F_22 ( sizeof( T_4 ) , V_51 ) ;
if ( V_49 == NULL ) {
F_2 ( V_2 L_7 ,
V_9 -> V_13 ) ;
return - V_52 ;
}
if ( F_23 ( V_49 , V_48 , sizeof( T_4 ) ) ) {
F_2 ( V_2 L_8 ,
V_9 -> V_13 ) ;
F_24 ( V_49 ) ;
return - V_53 ;
}
if ( V_49 -> V_11 != V_12 ) {
F_24 ( V_49 ) ;
F_2 ( V_2 L_9 ,
V_9 -> V_13 ) ;
return - V_14 ;
}
if ( V_49 -> V_54 && V_49 -> V_34 ) {
if ( V_49 -> V_54 > 128000 ) {
F_2 ( V_2
L_10 ,
V_9 -> V_13 , V_49 -> V_54 ) ;
F_24 ( V_49 ) ;
return - V_14 ;
}
V_34 = F_25 ( V_49 -> V_54 ) ;
if ( ! V_34 ) {
F_2 ( V_2
L_11 ,
V_9 -> V_13 ) ;
F_24 ( V_49 ) ;
return - V_52 ;
}
if ( ! F_23 ( V_34 , V_49 -> V_34 , V_49 -> V_54 ) ) {
V_49 -> V_34 = V_34 ;
V_1 = V_9 -> V_50 ( V_9 , V_49 ) ;
} else {
F_2 ( V_2
L_12 ,
V_9 -> V_13 ) ;
V_1 = - V_53 ;
}
F_26 ( V_34 ) ;
} else {
F_2 ( V_2
L_13 ,
V_9 -> V_13 , V_49 -> V_54 ) ;
}
F_24 ( V_49 ) ;
return V_1 ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_55 * V_18 ;
int V_1 = 0 ;
if ( V_9 -> V_23 == V_24 )
return 0 ;
F_2 ( V_2 L_14 , V_9 -> V_13 ) ;
for ( V_18 = V_9 -> V_18 ; V_18 ; ) {
V_1 = F_27 ( V_9 , V_18 -> V_13 ) ;
if ( V_1 )
return V_1 ;
V_18 = V_9 -> V_18 ;
}
if ( V_9 -> V_17 )
return - V_56 ;
if ( V_9 -> V_57 )
V_1 = V_9 -> V_57 ( V_9 ) ;
return V_1 ;
}
static int F_18 ( struct V_8 * V_9 ,
T_5 T_3 * V_58 )
{
T_5 V_59 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
if ( ( V_9 -> V_23 != V_24 ) && V_9 -> V_60 )
V_9 -> V_60 ( V_9 ) ;
V_59 . V_17 = V_9 -> V_17 ;
V_59 . V_23 = V_9 -> V_23 ;
if ( F_28 ( V_58 , & V_59 , sizeof( V_59 ) ) )
return - V_53 ;
return 0 ;
}
static int F_19 ( struct V_8 * V_9 ,
T_6 T_3 * V_48 )
{
T_6 * V_61 ;
struct V_55 * V_18 = NULL ;
int V_1 ;
if ( ( V_9 -> V_23 == V_24 ) || ( V_9 -> V_62 == NULL ) )
return - V_22 ;
V_61 = F_22 ( sizeof( T_6 ) , V_51 ) ;
if ( ! V_61 )
return - V_52 ;
V_1 = - V_53 ;
if ( F_23 ( V_61 , V_48 , sizeof( T_6 ) ) )
goto V_63;
V_1 = - V_14 ;
if ( V_61 -> V_11 != V_12 )
goto V_63;
if ( V_61 -> V_64 == V_65 ) {
F_2 ( V_2 L_15 ,
V_9 -> V_13 ) ;
V_1 = - V_66 ;
goto V_63;
} else {
V_1 = V_9 -> V_62 ( V_9 , V_18 , V_61 ) ;
}
if ( ! V_1 ) {
#ifdef F_8
F_2 ( V_2 L_16 ,
V_7 , V_18 -> V_13 ) ;
#endif
V_1 = F_29 ( V_18 ) ;
if ( ! V_1 ) {
struct V_55 * V_67 = NULL ;
unsigned long V_68 = 0 ;
F_30 ( & V_9 -> V_69 , & V_68 ) ;
if ( V_9 -> V_18 == NULL ) {
V_9 -> V_18 = V_18 ;
} else {
for ( V_67 = V_9 -> V_18 ;
F_31 ( V_67 ) ;
V_67 = F_31 ( V_67 ) )
F_31 ( V_67 ) = V_18 ;
}
++ V_9 -> V_17 ;
F_32 ( & V_9 -> V_69 , & V_68 ) ;
V_1 = 0 ;
goto V_63;
}
if ( V_9 -> V_70 )
V_9 -> V_70 ( V_9 , V_18 ) ;
F_33 ( V_18 ) ;
}
V_63:
F_24 ( V_61 ) ;
return V_1 ;
}
static int F_20 ( struct V_8 * V_9 , char T_3 * V_71 )
{
char V_13 [ V_72 + 1 ] ;
int V_1 = 0 ;
if ( V_9 -> V_23 == V_24 )
return - V_22 ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
if ( F_23 ( V_13 , V_71 , V_72 ) )
return - V_53 ;
V_1 = F_27 ( V_9 , V_13 ) ;
if ( V_1 )
return V_1 ;
if ( ! V_9 -> V_17 && V_9 -> V_57 )
V_1 = V_9 -> V_57 ( V_9 ) ;
return V_1 ;
}
static struct V_8 * F_7 ( char * V_13 )
{
struct V_8 * V_9 ;
for ( V_9 = V_20 ;
V_9 && strcmp ( V_9 -> V_13 , V_13 ) ;
V_9 = V_9 -> V_19 ) ;
return V_9 ;
}
static int F_27 ( struct V_8 * V_9 , char * V_13 )
{
struct V_55 * V_18 = NULL , * V_21 = NULL ;
unsigned long V_68 = 0 ;
F_30 ( & V_9 -> V_69 , & V_68 ) ;
V_18 = V_9 -> V_18 ;
V_21 = NULL ;
while ( V_18 && strcmp ( V_13 , V_18 -> V_13 ) ) {
struct V_55 * * V_67 = F_34 ( V_18 ) ;
V_21 = V_18 ;
V_18 = * V_67 ;
}
F_32 ( & V_9 -> V_69 , & V_68 ) ;
if ( V_18 == NULL )
return - V_22 ;
if ( F_35 ( V_18 ) )
return - V_56 ;
if ( V_9 -> V_70 )
V_9 -> V_70 ( V_9 , V_18 ) ;
F_30 ( & V_9 -> V_69 , & V_68 ) ;
if ( V_21 ) {
struct V_55 * * V_73 = F_34 ( V_21 ) ;
struct V_55 * * V_67 = F_34 ( V_18 ) ;
* V_73 = * V_67 ;
} else {
struct V_55 * * V_67 = F_34 ( V_18 ) ;
V_9 -> V_18 = * V_67 ;
}
-- V_9 -> V_17 ;
F_32 ( & V_9 -> V_69 , & V_68 ) ;
F_2 ( V_2 L_17 , V_9 -> V_13 , V_18 -> V_13 ) ;
F_36 ( V_18 ) ;
F_33 ( V_18 ) ;
return 0 ;
}
static void F_30 ( T_7 * V_69 , unsigned long * V_68 )
__acquires( V_69 )
{
F_37 ( V_69 , * V_68 ) ;
}
static void F_32 ( T_7 * V_69 , unsigned long * V_68 )
__releases( V_69 )
{
F_38 ( V_69 , * V_68 ) ;
}
