static int
F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
char * V_8 ;
V_5 = F_2 ( ( unsigned long ) V_3 - 1 ) ;
if ( F_3 ( V_5 ) )
return 0 ;
if ( V_5 -> V_7 )
V_7 = V_5 -> V_7 ;
else {
F_4 ( V_5 ) ;
return 0 ;
}
F_5 ( V_2 , L_1 , F_6 ( & V_5 -> V_9 -> V_10 ) ) ;
if ( V_5 -> V_11 != NULL )
F_5 ( V_2 , L_2 , V_5 -> V_11 -> V_12 ) ;
else
F_5 ( V_2 , L_3 ) ;
if ( V_7 -> V_13 )
F_5 ( V_2 , L_4 ,
F_7 ( F_8 ( V_7 -> V_13 ) ) ,
F_9 ( F_8 ( V_7 -> V_13 ) ) ) ;
else
F_5 ( V_2 , L_5 ) ;
if ( V_7 -> V_13 )
F_5 ( V_2 , L_6 , V_7 -> V_13 -> V_14 ) ;
else
F_5 ( V_2 , L_7 ) ;
V_8 = ( V_5 -> V_15 & V_16 ) ? L_8 : L_9 ;
F_5 ( V_2 , L_10 , V_8 ) ;
switch ( V_5 -> V_17 ) {
case V_18 :
F_5 ( V_2 , L_11 ) ;
break;
case V_19 :
F_5 ( V_2 , L_12 ) ;
break;
case V_20 :
F_5 ( V_2 , L_13 ) ;
break;
case V_21 :
F_5 ( V_2 , L_14 ) ;
break;
case V_22 :
case V_23 :
F_5 ( V_2 , L_15 ) ;
if ( F_10 ( V_7 -> V_24 ) )
F_5 ( V_2 , L_16 ) ;
else
F_5 ( V_2 ,
L_17 ,
V_7 -> V_24 , V_7 -> V_25 ,
( ( V_7 -> V_24 >> 9 ) *
V_7 -> V_25 ) >> 11 ) ;
break;
default:
F_5 ( V_2 , L_18 ) ;
break;
}
F_4 ( V_5 ) ;
if ( V_26 )
F_5 ( V_2 , L_19 ) ;
F_5 ( V_2 , L_20 ) ;
return 0 ;
}
static void * F_11 ( struct V_1 * V_2 , T_1 * V_27 )
{
if ( * V_27 >= V_28 )
return NULL ;
return ( void * ) ( ( unsigned long ) * V_27 + 1 ) ;
}
static void * F_12 ( struct V_1 * V_2 , void * V_3 , T_1 * V_27 )
{
++ * V_27 ;
return F_11 ( V_2 , V_27 ) ;
}
static void F_13 ( struct V_1 * V_2 , void * V_3 )
{
}
static int F_14 ( struct V_29 * V_29 , struct V_30 * V_30 )
{
return F_15 ( V_30 , & V_31 ) ;
}
static int F_16 ( void )
{
int V_32 , V_33 ;
struct V_4 * V_5 ;
V_33 = 0 ;
for ( V_32 = 0 ; V_32 < V_28 ; ++ V_32 ) {
V_5 = F_2 ( V_32 ) ;
if ( F_3 ( V_5 ) )
continue;
if ( V_5 -> V_7 )
V_33 = F_17 ( & V_5 -> V_7 -> V_34 ) ;
F_4 ( V_5 ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static void F_18 ( void )
{
int V_32 ;
struct V_4 * V_5 ;
for ( V_32 = 0 ; V_32 < V_28 ; ++ V_32 ) {
V_5 = F_2 ( V_32 ) ;
if ( F_3 ( V_5 ) )
continue;
if ( V_5 -> V_7 )
F_19 ( & V_5 -> V_7 -> V_34 ) ;
F_4 ( V_5 ) ;
}
}
static void F_20 ( void )
{
int V_32 ;
struct V_4 * V_5 ;
for ( V_32 = 0 ; V_32 < V_28 ; ++ V_32 ) {
V_5 = F_2 ( V_32 ) ;
if ( F_3 ( V_5 ) )
continue;
if ( V_5 -> V_7 )
F_21 ( & V_5 -> V_7 -> V_34 ) ;
F_4 ( V_5 ) ;
}
}
static void F_22 ( struct V_1 * V_2 , unsigned int * V_35 , int V_36 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < 32 ; V_32 ++ ) {
F_5 ( V_2 , L_21 , V_35 [ V_32 ] / V_36 ) ;
if ( V_32 == 15 )
F_23 ( V_2 , '\n' ) ;
}
F_23 ( V_2 , '\n' ) ;
}
static int F_24 ( struct V_1 * V_2 , void * V_3 )
{
#ifdef F_25
struct V_37 * V_38 ;
int V_36 ;
F_26 ( & V_39 . V_40 ) ;
V_38 = V_39 . V_41 ;
if ( ! V_38 ) {
F_27 ( & V_39 . V_40 ) ;
F_5 ( V_2 , L_22
L_23
L_24 ) ;
return 0 ;
}
for ( V_36 = 1 ; ( V_38 -> V_42 / V_36 ) > 9999999 ;
V_36 *= 10 ) ;
F_5 ( V_2 , L_25 , V_38 -> V_42 ) ;
F_5 ( V_2 , L_26 ,
V_38 -> V_43 ) ;
F_5 ( V_2 , L_27 , V_36 ) ;
F_5 ( V_2 ,
L_28
L_29
L_30 ) ;
F_5 ( V_2 ,
L_31
L_32
L_33 L_34 ) ;
F_5 ( V_2 , L_35 ) ;
F_22 ( V_2 , V_38 -> V_44 , V_36 ) ;
F_5 ( V_2 , L_36 ) ;
F_22 ( V_2 , V_38 -> V_45 , V_36 ) ;
F_5 ( V_2 , L_37 ) ;
F_22 ( V_2 , V_38 -> V_46 , V_36 ) ;
F_5 ( V_2 , L_38 ) ;
F_22 ( V_2 , V_38 -> V_47 , V_36 ) ;
F_5 ( V_2 , L_39 ) ;
F_22 ( V_2 , V_38 -> V_48 , V_36 ) ;
F_5 ( V_2 , L_40
L_41 ) ;
F_22 ( V_2 , V_38 -> V_49 , V_36 ) ;
F_5 ( V_2 , L_42 ) ;
F_22 ( V_2 , V_38 -> V_50 , V_36 ) ;
F_5 ( V_2 , L_43 ) ;
F_22 ( V_2 , V_38 -> V_51 , V_36 ) ;
F_27 ( & V_39 . V_40 ) ;
#else
F_5 ( V_2 , L_44 ) ;
#endif
return 0 ;
}
static int F_28 ( struct V_29 * V_29 , struct V_30 * V_30 )
{
return F_29 ( V_30 , F_24 , NULL ) ;
}
static T_2 F_30 ( struct V_30 * V_30 ,
const char T_3 * V_52 , T_4 V_53 , T_1 * V_27 )
{
#ifdef F_25
char * V_54 , * V_55 ;
int V_33 ;
if ( V_53 > 65536 )
V_53 = 65536 ;
V_54 = F_31 ( V_52 , V_53 ) ;
if ( F_3 ( V_54 ) )
return F_32 ( V_54 ) ;
V_55 = F_33 ( V_54 ) ;
if ( strncmp ( V_55 , L_45 , 3 ) == 0 && isspace ( V_55 [ 3 ] ) ) {
V_55 = F_33 ( V_55 + 4 ) ;
if ( strcmp ( V_55 , L_46 ) == 0 ) {
V_33 = F_16 () ;
if ( V_33 ) {
F_18 () ;
goto V_56;
}
V_33 = F_17 ( & V_39 ) ;
if ( V_33 ) {
F_18 () ;
goto V_56;
}
F_21 ( & V_39 ) ;
V_57 = V_58 ;
F_34 ( L_47
L_48 ) ;
} else if ( strcmp ( V_55 , L_49 ) == 0 ) {
V_57 = V_59 ;
F_19 ( & V_39 ) ;
F_18 () ;
F_34 ( L_47
L_50 ) ;
} else
goto V_60;
} else if ( strncmp ( V_55 , L_51 , 5 ) == 0 ) {
F_21 ( & V_39 ) ;
F_20 () ;
F_34 ( L_52 ) ;
} else
goto V_60;
F_35 ( V_54 ) ;
return V_53 ;
V_60:
V_33 = - V_61 ;
F_36 ( L_53 , V_55 ) ;
V_56:
F_35 ( V_54 ) ;
return V_33 ;
#else
F_36 ( L_54 ) ;
return V_53 ;
#endif
}
int
F_37 ( void )
{
V_62 = F_38 ( L_55 , NULL ) ;
if ( ! V_62 )
goto V_63;
V_64 = F_39 ( L_56 ,
V_65 | V_66 | V_67 ,
V_62 ,
& V_68 ) ;
if ( ! V_64 )
goto V_69;
V_70 = F_39 ( L_57 ,
V_65 | V_66 | V_67 ,
V_62 ,
& V_71 ) ;
if ( ! V_70 )
goto V_72;
return 0 ;
V_72:
F_40 ( L_56 , V_62 ) ;
V_69:
F_40 ( L_55 , NULL ) ;
V_63:
return - V_73 ;
}
void
F_41 ( void )
{
F_40 ( L_56 , V_62 ) ;
F_40 ( L_57 , V_62 ) ;
F_40 ( L_55 , NULL ) ;
}
