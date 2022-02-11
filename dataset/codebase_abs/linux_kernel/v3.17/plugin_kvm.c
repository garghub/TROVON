static void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( & V_1 , V_2 ) ;
}
static const char * F_4 ( unsigned char * V_3 , int V_4 , T_1 V_5 ,
int V_6 , int V_7 ,
int V_8 , int V_9 )
{
int V_10 ;
if ( ! V_6 )
V_10 = 16 ;
else if ( V_7 )
V_10 = 16 ;
else if ( V_9 )
V_10 = 64 ;
else if ( V_8 )
V_10 = 32 ;
else
V_10 = 16 ;
F_5 ( & V_1 , V_5 ) ;
F_6 ( & V_1 , V_10 ) ;
F_7 ( & V_1 , V_3 , V_4 ) ;
F_8 ( & V_1 ) ;
return F_9 ( & V_1 ) ;
}
static void F_1 ( void )
{
}
static const char * F_4 ( unsigned char * V_3 , int V_4 , T_1 V_5 ,
int V_6 , int V_7 ,
int V_8 , int V_9 )
{
static char V_11 [ 15 * 3 + 1 ] ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_4 ; ++ V_12 )
sprintf ( V_11 + V_12 * 3 , L_1 , V_3 [ V_12 ] ) ;
V_11 [ V_4 * 3 - 1 ] = '\0' ;
return V_11 ;
}
static const char * F_10 ( unsigned V_13 , int V_14 )
{
struct V_15 * V_16 = NULL ;
int V_12 ;
for ( V_12 = 0 ; V_17 [ V_12 ] . V_16 ; ++ V_12 )
if ( V_17 [ V_12 ] . V_13 == V_13 ) {
V_16 = V_17 [ V_12 ] . V_16 ;
break;
}
if ( ! V_16 )
return L_2 ;
for ( V_12 = 0 ; V_16 [ V_12 ] . V_14 >= 0 ; V_12 ++ )
if ( V_16 [ V_12 ] . V_14 == V_14 )
break;
return V_16 [ V_12 ] . V_18 ;
}
static int F_11 ( struct V_19 * V_20 , struct V_21 * V_22 ,
struct V_23 * V_24 , const char * V_25 )
{
unsigned long long V_13 ;
unsigned long long V_14 ;
const char * V_26 ;
if ( F_12 ( V_20 , V_24 , V_25 , V_22 , & V_14 , 1 ) < 0 )
return - 1 ;
if ( F_12 ( V_20 , V_24 , L_3 , V_22 , & V_13 , 0 ) < 0 )
V_13 = 1 ;
V_26 = F_10 ( V_13 , V_14 ) ;
if ( V_26 )
F_13 ( V_20 , L_4 , V_26 ) ;
else
F_13 ( V_20 , L_5 , V_14 ) ;
return 0 ;
}
static int F_14 ( struct V_19 * V_20 , struct V_21 * V_22 ,
struct V_23 * V_24 , void * V_27 )
{
unsigned long long V_28 = 0 , V_29 = 0 ;
if ( F_11 ( V_20 , V_22 , V_24 , L_6 ) < 0 )
return - 1 ;
F_15 ( V_20 , L_7 , V_24 , L_8 , V_22 , 1 ) ;
if ( F_12 ( V_20 , V_24 , L_9 , V_22 , & V_28 , 0 ) >= 0
&& F_12 ( V_20 , V_24 , L_10 , V_22 , & V_29 , 0 ) >= 0 )
F_13 ( V_20 , L_11 , V_28 , V_29 ) ;
return 0 ;
}
static int F_16 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , void * V_27 )
{
unsigned long long V_5 , V_30 , V_4 , V_31 , V_32 ;
int V_33 ;
T_2 * V_3 ;
const char * V_34 ;
if ( F_12 ( V_20 , V_24 , L_12 , V_22 , & V_5 , 1 ) < 0 )
return - 1 ;
if ( F_12 ( V_20 , V_24 , L_13 , V_22 , & V_30 , 1 ) < 0 )
return - 1 ;
if ( F_12 ( V_20 , V_24 , L_14 , V_22 , & V_4 , 1 ) < 0 )
return - 1 ;
if ( F_12 ( V_20 , V_24 , L_15 , V_22 , & V_31 , 1 ) < 0 )
return - 1 ;
if ( F_12 ( V_20 , V_24 , L_16 , V_22 , & V_32 , 1 ) < 0 )
return - 1 ;
V_3 = F_17 ( V_20 , V_24 , L_17 , V_22 , & V_33 , 1 ) ;
if ( ! V_3 )
return - 1 ;
V_34 = F_4 ( V_3 , V_4 , V_5 ,
V_31 & V_35 ,
V_31 & V_36 ,
V_31 & V_37 ,
V_31 & V_38 ) ;
F_13 ( V_20 , L_18 , V_30 , V_5 , V_34 ,
V_32 ? L_19 : L_20 ) ;
return 0 ;
}
static int F_18 ( struct V_19 * V_20 , struct V_21 * V_22 ,
struct V_23 * V_24 , void * V_27 )
{
if ( F_11 ( V_20 , V_22 , V_24 , L_21 ) < 0 )
return - 1 ;
F_15 ( V_20 , L_22 , V_24 , L_23 , V_22 , 1 ) ;
F_15 ( V_20 , L_24 , V_24 , L_25 , V_22 , 1 ) ;
F_15 ( V_20 , L_26 , V_24 , L_27 , V_22 , 1 ) ;
F_15 ( V_20 , L_28 , V_24 , L_29 , V_22 , 1 ) ;
return 0 ;
}
static int F_19 ( struct V_19 * V_20 , struct V_21 * V_22 ,
struct V_23 * V_24 , void * V_27 )
{
F_15 ( V_20 , L_30 , V_24 , L_12 , V_22 , 1 ) ;
return F_18 ( V_20 , V_22 , V_24 , V_27 ) ;
}
static int F_20 ( struct V_19 * V_20 , struct V_21 * V_22 ,
struct V_23 * V_24 , void * V_27 )
{
unsigned long long V_14 ;
static const char * V_39 [] = {
L_31 , L_32 , L_33 , L_34 , L_35 , L_36 , L_37 , L_38
} ;
union V_40 V_41 ;
if ( F_12 ( V_20 , V_24 , L_39 , V_22 , & V_14 , 1 ) < 0 )
return - 1 ;
V_41 . V_42 = ( int ) V_14 ;
if ( F_21 ( V_24 -> V_43 ) ==
F_22 ( V_24 -> V_43 ) ) {
F_13 ( V_20 , L_40 ,
V_41 . V_44 ,
V_41 . V_45 ,
V_41 . V_46 ,
V_41 . V_47 ? L_41 : L_20 ,
V_39 [ V_41 . V_48 ] ,
V_41 . V_49 ? L_42 : L_20 ,
V_41 . V_50 ? L_20 : L_43 ,
V_41 . V_51 ? L_20 : L_43 ) ;
} else
F_13 ( V_20 , L_44 , V_41 . V_42 ) ;
F_15 ( V_20 , L_45 , V_24 ,
L_46 , V_22 , 1 ) ;
if ( F_12 ( V_20 , V_24 , L_47 , V_22 , & V_14 , 1 ) < 0 )
return - 1 ;
F_13 ( V_20 , L_48 , V_14 ? L_47 : L_49 , 0 ) ;
return 0 ;
}
static int F_23 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , void * V_27 )
{
unsigned long long V_14 ;
if ( F_12 ( V_20 , V_24 , L_50 , V_22 , & V_14 , 1 ) < 0 )
return - 1 ;
F_13 ( V_20 , L_51 , V_14 ? L_52 : L_53 ) ;
if ( F_12 ( V_20 , V_24 , L_54 , V_22 , & V_14 , 1 ) < 0 )
return - 1 ;
F_13 ( V_20 , L_55 , V_14 ) ;
return F_20 ( V_20 , V_22 , V_24 , V_27 ) ;
}
static unsigned long long
F_24 ( struct V_19 * V_20 , unsigned long long * args )
{
unsigned long V_52 = args [ 0 ] ;
return V_52 & V_53 ;
}
int F_25 ( struct V_43 * V_43 )
{
F_1 () ;
F_26 ( V_43 , - 1 , L_56 , L_57 ,
F_14 , NULL ) ;
F_26 ( V_43 , - 1 , L_56 , L_58 ,
F_16 , NULL ) ;
F_26 ( V_43 , - 1 , L_56 , L_59 ,
F_19 , NULL ) ;
F_26 ( V_43 , - 1 , L_56 , L_60 ,
F_18 , NULL ) ;
F_26 ( V_43 , - 1 , L_61 , L_62 ,
F_23 , NULL ) ;
F_26 ( V_43 , - 1 , L_61 , L_63 ,
F_20 , NULL ) ;
F_26 ( V_43 , - 1 ,
L_61 , L_64 ,
F_20 , NULL ) ;
F_26 ( V_43 , - 1 , L_61 , L_65 ,
F_20 , NULL ) ;
F_26 ( V_43 , - 1 , L_61 ,
L_66 , F_20 ,
NULL ) ;
F_27 ( V_43 ,
F_24 ,
V_54 ,
L_67 ,
V_55 ,
V_56 ) ;
return 0 ;
}
void F_28 ( struct V_43 * V_43 )
{
F_29 ( V_43 , - 1 , L_56 , L_57 ,
F_14 , NULL ) ;
F_29 ( V_43 , - 1 , L_56 , L_58 ,
F_16 , NULL ) ;
F_29 ( V_43 , - 1 , L_56 , L_59 ,
F_19 , NULL ) ;
F_29 ( V_43 , - 1 , L_56 , L_60 ,
F_18 , NULL ) ;
F_29 ( V_43 , - 1 , L_61 , L_62 ,
F_23 , NULL ) ;
F_29 ( V_43 , - 1 , L_61 , L_63 ,
F_20 , NULL ) ;
F_29 ( V_43 , - 1 ,
L_61 , L_64 ,
F_20 , NULL ) ;
F_29 ( V_43 , - 1 , L_61 , L_65 ,
F_20 , NULL ) ;
F_29 ( V_43 , - 1 , L_61 ,
L_66 , F_20 ,
NULL ) ;
F_30 ( V_43 , F_24 ,
L_67 ) ;
}
