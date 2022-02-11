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
if ( V_16 [ V_12 ] . V_18 )
return V_16 [ V_12 ] . V_18 ;
return L_3 ;
}
static int F_11 ( struct V_19 * V_20 , struct V_21 * V_22 ,
struct V_23 * V_24 , void * V_25 )
{
unsigned long long V_13 ;
unsigned long long V_14 ;
unsigned long long V_26 = 0 , V_27 = 0 ;
if ( F_12 ( V_20 , V_24 , L_4 , V_22 , & V_14 , 1 ) < 0 )
return - 1 ;
if ( F_12 ( V_20 , V_24 , L_5 , V_22 , & V_13 , 0 ) < 0 )
V_13 = 1 ;
F_13 ( V_20 , L_6 , F_10 ( V_13 , V_14 ) ) ;
F_14 ( V_20 , L_7 , V_24 , L_8 , V_22 , 1 ) ;
if ( F_12 ( V_20 , V_24 , L_9 , V_22 , & V_26 , 0 ) >= 0
&& F_12 ( V_20 , V_24 , L_10 , V_22 , & V_27 , 0 ) >= 0 )
F_13 ( V_20 , L_11 , V_26 , V_27 ) ;
return 0 ;
}
static int F_15 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , void * V_25 )
{
unsigned long long V_5 , V_28 , V_4 , V_29 , V_30 ;
int V_31 ;
T_2 * V_3 ;
const char * V_32 ;
if ( F_12 ( V_20 , V_24 , L_12 , V_22 , & V_5 , 1 ) < 0 )
return - 1 ;
if ( F_12 ( V_20 , V_24 , L_13 , V_22 , & V_28 , 1 ) < 0 )
return - 1 ;
if ( F_12 ( V_20 , V_24 , L_14 , V_22 , & V_4 , 1 ) < 0 )
return - 1 ;
if ( F_12 ( V_20 , V_24 , L_15 , V_22 , & V_29 , 1 ) < 0 )
return - 1 ;
if ( F_12 ( V_20 , V_24 , L_16 , V_22 , & V_30 , 1 ) < 0 )
return - 1 ;
V_3 = F_16 ( V_20 , V_24 , L_17 , V_22 , & V_31 , 1 ) ;
if ( ! V_3 )
return - 1 ;
V_32 = F_4 ( V_3 , V_4 , V_5 ,
V_29 & V_33 ,
V_29 & V_34 ,
V_29 & V_35 ,
V_29 & V_36 ) ;
F_13 ( V_20 , L_18 , V_28 , V_5 , V_32 ,
V_30 ? L_19 : L_20 ) ;
return 0 ;
}
static int F_17 ( struct V_19 * V_20 , struct V_21 * V_22 ,
struct V_23 * V_24 , void * V_25 )
{
unsigned long long V_14 ;
static const char * V_37 [] = {
L_21 , L_22 , L_23 , L_24 , L_25 , L_26 , L_27 , L_28
} ;
union V_38 V_39 ;
if ( F_12 ( V_20 , V_24 , L_29 , V_22 , & V_14 , 1 ) < 0 )
return - 1 ;
V_39 . V_40 = ( int ) V_14 ;
if ( F_18 ( V_24 -> V_41 ) ==
F_19 ( V_24 -> V_41 ) ) {
F_13 ( V_20 , L_30 ,
V_39 . V_42 ,
V_39 . V_43 ,
V_39 . V_44 ,
V_39 . V_45 ? L_31 : L_20 ,
V_37 [ V_39 . V_46 ] ,
V_39 . V_47 ? L_32 : L_20 ,
V_39 . V_48 ? L_20 : L_33 ,
V_39 . V_49 ? L_20 : L_33 ) ;
} else
F_13 ( V_20 , L_34 , V_39 . V_40 ) ;
F_14 ( V_20 , L_35 , V_24 ,
L_36 , V_22 , 1 ) ;
if ( F_12 ( V_20 , V_24 , L_37 , V_22 , & V_14 , 1 ) < 0 )
return - 1 ;
F_13 ( V_20 , L_38 , V_14 ? L_37 : L_39 , 0 ) ;
return 0 ;
}
static int F_20 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , void * V_25 )
{
unsigned long long V_14 ;
if ( F_12 ( V_20 , V_24 , L_40 , V_22 , & V_14 , 1 ) < 0 )
return - 1 ;
F_13 ( V_20 , L_41 , V_14 ? L_42 : L_43 ) ;
if ( F_12 ( V_20 , V_24 , L_44 , V_22 , & V_14 , 1 ) < 0 )
return - 1 ;
F_13 ( V_20 , L_45 , V_14 ) ;
return F_17 ( V_20 , V_22 , V_24 , V_25 ) ;
}
static unsigned long long
F_21 ( struct V_19 * V_20 , unsigned long long * args )
{
unsigned long V_50 = args [ 0 ] ;
return V_50 & V_51 ;
}
int F_22 ( struct V_41 * V_41 )
{
F_1 () ;
F_23 ( V_41 , - 1 , L_46 , L_47 ,
F_11 , NULL ) ;
F_23 ( V_41 , - 1 , L_46 , L_48 ,
F_15 , NULL ) ;
F_23 ( V_41 , - 1 , L_49 , L_50 ,
F_20 , NULL ) ;
F_23 ( V_41 , - 1 , L_49 , L_51 ,
F_17 , NULL ) ;
F_23 ( V_41 , - 1 ,
L_49 , L_52 ,
F_17 , NULL ) ;
F_23 ( V_41 , - 1 , L_49 , L_53 ,
F_17 , NULL ) ;
F_23 ( V_41 , - 1 , L_49 ,
L_54 , F_17 ,
NULL ) ;
F_24 ( V_41 ,
F_21 ,
V_52 ,
L_55 ,
V_53 ,
V_54 ) ;
return 0 ;
}
void F_25 ( struct V_41 * V_41 )
{
F_26 ( V_41 , - 1 , L_46 , L_47 ,
F_11 , NULL ) ;
F_26 ( V_41 , - 1 , L_46 , L_48 ,
F_15 , NULL ) ;
F_26 ( V_41 , - 1 , L_49 , L_50 ,
F_20 , NULL ) ;
F_26 ( V_41 , - 1 , L_49 , L_51 ,
F_17 , NULL ) ;
F_26 ( V_41 , - 1 ,
L_49 , L_52 ,
F_17 , NULL ) ;
F_26 ( V_41 , - 1 , L_49 , L_53 ,
F_17 , NULL ) ;
F_26 ( V_41 , - 1 , L_49 ,
L_54 , F_17 ,
NULL ) ;
F_27 ( V_41 , F_21 ,
L_55 ) ;
}
