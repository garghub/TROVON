static void F_1 ( struct V_1 * V_2 )
{
char V_3 [ 3 ] ;
F_2 ( V_2 -> V_4 , V_3 ) ;
F_3 ( V_2 ) ;
if ( V_2 -> V_5 )
F_4 ( V_3 , V_6 ) ;
if ( V_2 -> V_7 )
F_4 ( V_3 , V_8 ) ;
if ( V_2 -> V_9 )
F_4 ( V_3 , V_10 ) ;
if ( V_2 -> V_11 )
F_4 ( V_3 , V_12 ) ;
}
void F_5 ( void )
{
V_6 = NULL ;
V_8 = NULL ;
V_10 = NULL ;
V_12 = NULL ;
if ( V_13 ) {
struct V_1 * V_2 ;
F_6 (nd, &nd_struct_list, list)
F_1 ( V_2 ) ;
F_4 ( L_1 , NULL ) ;
F_4 ( L_2 , NULL ) ;
F_4 ( L_3 , NULL ) ;
F_4 ( L_4 , NULL ) ;
F_4 ( L_5 , NULL ) ;
F_4 ( L_6 , NULL ) ;
F_4 ( L_7 , NULL ) ;
F_4 ( L_8 , NULL ) ;
V_13 = NULL ;
}
}
void F_7 ( void )
{
V_13 = F_8 ( L_8 , NULL ) ;
if ( ! V_13 )
return;
F_9 ( L_1 , 0644 , NULL , & V_14 ) ;
F_9 ( L_2 , 0644 , NULL , & V_15 ) ;
F_9 ( L_3 , 0644 , NULL , & V_16 ) ;
V_6 = F_10 ( L_4 , 0500 , NULL ) ;
V_8 = F_10 ( L_5 , 0500 , NULL ) ;
V_10 = F_10 ( L_6 , 0500 , NULL ) ;
V_12 = F_10 ( L_7 , 0500 , NULL ) ;
}
static void * F_11 ( struct V_17 * V_18 , T_1 * V_19 )
{
return F_12 ( & V_20 , * V_19 ) ;
}
static void * F_13 ( struct V_17 * V_21 , void * V_22 , T_1 * V_19 )
{
return F_14 ( V_22 , & V_20 , V_19 ) ;
}
static void F_15 ( struct V_17 * V_18 , void * V_22 )
{
}
static int F_16 ( struct V_17 * V_18 , void * V_22 )
{
struct V_1 * V_2 ;
char V_23 [ 4 ] ;
if ( V_22 == & V_20 ) {
F_17 ( V_18 , L_9 ) ;
F_17 ( V_18 , L_10 ) ;
F_17 ( V_18 , L_11 ) ;
return 0 ;
}
V_2 = F_18 ( V_22 , struct V_1 , V_24 ) ;
F_2 ( V_2 -> V_4 , V_23 ) ;
F_19 ( V_18 , L_12 ,
V_23 ,
V_2 -> V_25 ,
F_20 ( V_2 -> V_26 ) ,
V_2 -> V_27 ) ;
return 0 ;
}
static int F_21 ( struct V_28 * V_28 , struct V_29 * V_29 )
{
return F_22 ( V_29 , & V_30 ) ;
}
static T_2 F_23 ( struct V_29 * V_29 ,
const char T_3 * V_31 ,
T_4 V_32 , T_1 * V_19 )
{
T_2 V_33 ;
char * V_34 , * V_35 ;
char * line , * V_36 ;
if ( V_32 > 32768 )
return - V_37 ;
V_34 = V_35 = F_24 ( V_32 + 1 ) ;
if ( ! V_34 )
return - V_38 ;
if ( F_25 ( V_34 , V_31 , V_32 ) ) {
V_33 = - V_39 ;
goto V_40;
}
V_34 [ V_32 ] = 0 ;
V_36 = L_13 ;
line = strpbrk ( V_35 , V_36 ) ;
while ( line ) {
* line = 0 ;
V_33 = F_26 ( V_35 ) ;
if ( V_33 )
goto V_40;
V_35 = line + 1 ;
line = strpbrk ( V_35 , V_36 ) ;
}
V_33 = V_32 ;
V_40:
F_27 ( V_34 ) ;
return V_33 ;
}
static inline char * F_28 ( const char * V_41 )
{
while ( ( * V_41 ) && ! isspace ( * V_41 ) )
++ V_41 ;
return F_29 ( V_41 ) ;
}
static int F_30 ( char * * V_42 , char * V_43 )
{
int V_44 = * * V_42 ;
if ( isalnum ( V_44 ) || ( V_44 == '_' ) )
V_43 [ 0 ] = V_44 ;
else
return - V_37 ;
( * V_42 ) ++ ; V_44 = * * V_42 ;
if ( isalnum ( V_44 ) || ( V_44 == '_' ) ) {
V_43 [ 1 ] = V_44 ;
( * V_42 ) ++ ;
} else
V_43 [ 1 ] = 0 ;
return 0 ;
}
static int F_31 ( char * V_3 )
{
char * V_42 = V_3 ;
int V_33 ;
char V_43 [ 2 ] ;
long V_45 ;
V_42 = F_28 ( V_42 ) ;
V_33 = F_30 ( & V_42 , V_43 ) ;
if ( V_33 < 0 )
return V_33 ;
V_45 = F_32 ( V_43 ) ;
V_42 = F_28 ( V_42 ) ;
return F_33 ( V_45 ) ;
}
static int F_34 ( char * V_3 )
{
char * V_42 = V_3 ;
int V_33 ;
struct V_1 * V_2 ;
char V_43 [ 2 ] ;
long V_45 ;
long V_46 ;
V_42 = F_28 ( V_42 ) ;
V_33 = F_30 ( & V_42 , V_43 ) ;
if ( V_33 < 0 )
return V_33 ;
V_45 = F_32 ( V_43 ) ;
V_42 = F_28 ( V_42 ) ;
V_33 = F_35 ( V_42 , 10 , & V_46 ) ;
if ( V_33 )
return V_33 ;
V_2 = F_36 ( V_46 ) ;
if ( ! V_2 )
return - V_37 ;
if ( ( V_2 -> V_25 != V_46 ) || ( V_2 -> V_4 != V_45 ) )
return - V_37 ;
return F_37 ( V_2 ) ;
}
static int F_38 ( char * V_3 )
{
return - V_37 ;
}
static int F_26 ( char * V_3 )
{
int V_33 ;
switch ( V_3 [ 0 ] ) {
case '+' :
V_33 = F_31 ( V_3 ) ;
break;
case '-' :
V_33 = F_34 ( V_3 ) ;
break;
case '*' :
V_33 = F_38 ( V_3 ) ;
break;
default:
V_33 = - V_37 ;
}
return V_33 ;
}
static int F_39 ( struct V_17 * V_18 , void * V_22 )
{
F_19 ( V_18 , L_14 , V_47 ) ;
F_17 ( V_18 , L_15 ) ;
F_19 ( V_18 , L_16 ,
V_48 , V_48 ) ;
return 0 ;
}
static int F_40 ( struct V_28 * V_28 , struct V_29 * V_29 )
{
return F_41 ( V_29 , F_39 , NULL ) ;
}
static void * F_42 ( struct V_17 * V_18 , T_1 * V_19 )
{
return F_12 ( & V_20 , * V_19 ) ;
}
static void * F_43 ( struct V_17 * V_21 , void * V_22 , T_1 * V_19 )
{
return F_14 ( V_22 , & V_20 , V_19 ) ;
}
static void F_44 ( struct V_17 * V_18 , void * V_22 )
{
}
static int F_45 ( struct V_17 * V_18 , void * V_22 )
{
struct V_1 * V_2 ;
char V_49 [ 8 ] ;
char V_50 [ 8 ] ;
char V_23 [ 4 ] ;
if ( V_22 == & V_20 ) {
F_17 ( V_18 , L_9 ) ;
F_17 ( V_18 , L_17 ) ;
F_17 ( V_18 , L_18 ) ;
return 0 ;
}
V_2 = F_18 ( V_22 , struct V_1 , V_24 ) ;
F_2 ( V_2 -> V_4 , V_23 ) ;
if ( V_2 -> V_26 == V_51 ) {
sprintf ( V_49 , L_19 , ( V_2 -> V_52 >> 8 ) & 0xff ,
V_2 -> V_52 & 0xff ) ;
sprintf ( V_50 , L_19 , ( V_2 -> V_53 >> 8 ) & 0xff ,
V_2 -> V_53 & 0xff ) ;
F_19 ( V_18 , L_20 ,
V_23 ,
F_20 ( V_2 -> V_26 ) ,
V_49 ,
V_2 -> V_54 ,
V_50 ,
V_2 -> V_55 ) ;
} else {
F_19 ( V_18 , L_21 ,
V_23 ,
F_20 ( V_2 -> V_26 ) ) ;
}
return 0 ;
}
static int F_46 ( struct V_28 * V_28 , struct V_29 * V_29 )
{
return F_22 ( V_29 , & V_56 ) ;
}
static int F_33 ( long V_57 )
{
struct V_1 * V_2 ;
int V_58 ;
int V_59 ;
V_2 = F_47 ( sizeof( struct V_1 ) , V_60 ) ;
if ( ! V_2 )
return - V_38 ;
V_2 -> V_25 = 0 ;
V_2 -> V_4 = V_57 ;
F_48 ( & V_2 -> V_61 ) ;
F_49 ( & V_2 -> V_62 ) ;
F_49 ( & V_2 -> V_63 ) ;
F_49 ( & V_2 -> V_64 ) ;
F_50 ( & V_2 -> V_65 , 1 ) ;
F_50 ( & V_2 -> V_66 , 1 ) ;
F_48 ( & V_2 -> V_67 ) ;
V_2 -> V_26 = V_68 ;
for ( V_59 = 0 ; V_59 < V_69 ; V_59 ++ )
F_49 ( & V_2 -> V_70 [ V_59 ] ) ;
V_58 = F_51 ( V_2 ) ;
if ( V_58 )
goto V_71;
V_2 -> V_25 = V_2 -> V_72 -> V_46 ;
V_58 = F_52 ( V_2 ) ;
if ( V_58 )
goto V_71;
F_53 ( V_2 ) ;
V_2 -> V_5 = F_54 ( V_2 , V_6 , & V_73 ) ;
V_2 -> V_7 = F_54 ( V_2 , V_8 , & V_74 ) ;
V_2 -> V_9 = F_54 ( V_2 , V_10 , & V_75 ) ;
V_2 -> V_11 = F_54 ( V_2 , V_12 ,
& V_76 ) ;
return 0 ;
V_71:
F_55 ( V_2 ) ;
return V_58 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_58 ;
if ( V_2 -> V_77 )
return - V_78 ;
F_1 ( V_2 ) ;
F_56 ( V_2 ) ;
V_58 = F_57 ( V_2 ) ;
if ( V_58 )
return V_58 ;
F_55 ( V_2 ) ;
return 0 ;
}
static struct V_79 * F_54 ( struct V_1 * V_80 ,
struct V_79 * V_81 ,
const struct V_82 * V_83 )
{
char V_3 [ 3 ] ;
F_2 ( V_80 -> V_4 , V_3 ) ;
return F_58 ( V_3 , 0600 , V_81 , V_83 , V_80 ) ;
}
