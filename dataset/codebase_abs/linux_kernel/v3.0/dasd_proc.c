static char *
F_1 ( const char T_1 * V_1 , T_2 V_2 )
{
char * V_3 ;
V_3 = F_2 ( V_2 + 1 , V_4 ) ;
if ( V_3 == NULL )
return F_3 ( - V_5 ) ;
if ( F_4 ( V_3 , V_1 , V_2 ) != 0 ) {
F_5 ( V_3 ) ;
return F_3 ( - V_6 ) ;
}
if ( V_3 [ V_2 - 1 ] == '\n' )
V_3 [ V_2 - 1 ] = 0 ;
else
V_3 [ V_2 ] = 0 ;
return V_3 ;
}
static int
F_6 ( struct V_7 * V_8 , void * V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
char * V_14 ;
V_11 = F_7 ( ( unsigned long ) V_9 - 1 ) ;
if ( F_8 ( V_11 ) )
return 0 ;
if ( V_11 -> V_13 )
V_13 = V_11 -> V_13 ;
else {
F_9 ( V_11 ) ;
return 0 ;
}
F_10 ( V_8 , L_1 , F_11 ( & V_11 -> V_15 -> V_16 ) ) ;
if ( V_11 -> V_17 != NULL )
F_10 ( V_8 , L_2 , V_11 -> V_17 -> V_18 ) ;
else
F_10 ( V_8 , L_3 ) ;
if ( V_13 -> V_19 )
F_10 ( V_8 , L_4 ,
F_12 ( F_13 ( V_13 -> V_19 ) ) ,
F_14 ( F_13 ( V_13 -> V_19 ) ) ) ;
else
F_10 ( V_8 , L_5 ) ;
if ( V_13 -> V_19 )
F_10 ( V_8 , L_6 , V_13 -> V_19 -> V_20 ) ;
else
F_10 ( V_8 , L_7 ) ;
V_14 = ( V_11 -> V_21 & V_22 ) ? L_8 : L_9 ;
F_10 ( V_8 , L_10 , V_14 ) ;
switch ( V_11 -> V_23 ) {
case V_24 :
F_10 ( V_8 , L_11 ) ;
break;
case V_25 :
F_10 ( V_8 , L_12 ) ;
break;
case V_26 :
F_10 ( V_8 , L_13 ) ;
break;
case V_27 :
F_10 ( V_8 , L_14 ) ;
break;
case V_28 :
case V_29 :
F_10 ( V_8 , L_15 ) ;
if ( F_15 ( V_13 -> V_30 ) )
F_10 ( V_8 , L_16 ) ;
else
F_10 ( V_8 ,
L_17 ,
V_13 -> V_30 , V_13 -> V_31 ,
( ( V_13 -> V_30 >> 9 ) *
V_13 -> V_31 ) >> 11 ) ;
break;
default:
F_10 ( V_8 , L_18 ) ;
break;
}
F_9 ( V_11 ) ;
if ( V_32 )
F_10 ( V_8 , L_19 ) ;
F_10 ( V_8 , L_20 ) ;
return 0 ;
}
static void * F_16 ( struct V_7 * V_8 , T_3 * V_33 )
{
if ( * V_33 >= V_34 )
return NULL ;
return ( void * ) ( ( unsigned long ) * V_33 + 1 ) ;
}
static void * F_17 ( struct V_7 * V_8 , void * V_9 , T_3 * V_33 )
{
++ * V_33 ;
return F_16 ( V_8 , V_33 ) ;
}
static void F_18 ( struct V_7 * V_8 , void * V_9 )
{
}
static int F_19 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
return F_20 ( V_36 , & V_37 ) ;
}
static void F_21 ( struct V_7 * V_8 , unsigned int * V_38 , int V_39 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < 32 ; V_40 ++ ) {
F_10 ( V_8 , L_21 , V_38 [ V_40 ] / V_39 ) ;
if ( V_40 == 15 )
F_22 ( V_8 , '\n' ) ;
}
F_22 ( V_8 , '\n' ) ;
}
static int F_23 ( struct V_7 * V_8 , void * V_9 )
{
#ifdef F_24
struct V_41 * V_42 ;
int V_39 ;
if ( V_43 == V_44 ) {
F_10 ( V_8 , L_22
L_23
L_24 ) ;
return 0 ;
}
V_42 = & V_45 ;
for ( V_39 = 1 ; ( V_42 -> V_46 / V_39 ) > 9999999 ;
V_39 *= 10 ) ;
F_10 ( V_8 , L_25 , V_42 -> V_46 ) ;
F_10 ( V_8 , L_26 ,
V_42 -> V_47 ) ;
F_10 ( V_8 , L_27 , V_39 ) ;
F_10 ( V_8 ,
L_28
L_29
L_30 ) ;
F_10 ( V_8 ,
L_31
L_32
L_33 L_34 ) ;
F_10 ( V_8 , L_35 ) ;
F_21 ( V_8 , V_42 -> V_48 , V_39 ) ;
F_10 ( V_8 , L_36 ) ;
F_21 ( V_8 , V_42 -> V_49 , V_39 ) ;
F_10 ( V_8 , L_37 ) ;
F_21 ( V_8 , V_42 -> V_50 , V_39 ) ;
F_10 ( V_8 , L_38 ) ;
F_21 ( V_8 , V_42 -> V_51 , V_39 ) ;
F_10 ( V_8 , L_39 ) ;
F_21 ( V_8 , V_42 -> V_52 , V_39 ) ;
F_10 ( V_8 , L_40
L_41 ) ;
F_21 ( V_8 , V_42 -> V_53 , V_39 ) ;
F_10 ( V_8 , L_42 ) ;
F_21 ( V_8 , V_42 -> V_54 , V_39 ) ;
F_10 ( V_8 , L_43 ) ;
F_21 ( V_8 , V_42 -> V_55 , V_39 ) ;
#else
F_10 ( V_8 , L_44 ) ;
#endif
return 0 ;
}
static int F_25 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
return F_26 ( V_36 , F_23 , NULL ) ;
}
static T_4 F_27 ( struct V_36 * V_36 ,
const char T_1 * V_1 , T_2 V_2 , T_3 * V_33 )
{
#ifdef F_24
char * V_3 , * V_56 ;
if ( V_2 > 65536 )
V_2 = 65536 ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( F_8 ( V_3 ) )
return F_28 ( V_3 ) ;
V_56 = F_29 ( V_3 ) ;
if ( strncmp ( V_56 , L_45 , 3 ) == 0 && isspace ( V_56 [ 3 ] ) ) {
V_56 = F_29 ( V_56 + 4 ) ;
if ( strcmp ( V_56 , L_46 ) == 0 ) {
V_43 = V_57 ;
F_30 ( L_47
L_48 ) ;
} else if ( strcmp ( V_56 , L_49 ) == 0 ) {
memset ( & V_45 ,
0 , sizeof ( struct V_41 ) ) ;
V_43 = V_44 ;
F_30 ( L_47
L_50 ) ;
} else
goto V_58;
} else if ( strncmp ( V_56 , L_51 , 5 ) == 0 ) {
memset ( & V_45 , 0 ,
sizeof ( struct V_41 ) ) ;
F_30 ( L_52 ) ;
} else
goto V_58;
F_5 ( V_3 ) ;
return V_2 ;
V_58:
F_31 ( L_53 ,
V_56 ) ;
F_5 ( V_3 ) ;
return - V_59 ;
#else
F_31 ( L_54 ) ;
return V_2 ;
#endif
}
int
F_32 ( void )
{
V_60 = F_33 ( L_55 , NULL ) ;
if ( ! V_60 )
goto V_61;
V_62 = F_34 ( L_56 ,
V_63 | V_64 | V_65 ,
V_60 ,
& V_66 ) ;
if ( ! V_62 )
goto V_67;
V_68 = F_34 ( L_57 ,
V_63 | V_64 | V_65 ,
V_60 ,
& V_69 ) ;
if ( ! V_68 )
goto V_70;
return 0 ;
V_70:
F_35 ( L_56 , V_60 ) ;
V_67:
F_35 ( L_55 , NULL ) ;
V_61:
return - V_71 ;
}
void
F_36 ( void )
{
F_35 ( L_56 , V_60 ) ;
F_35 ( L_57 , V_60 ) ;
F_35 ( L_55 , NULL ) ;
}
