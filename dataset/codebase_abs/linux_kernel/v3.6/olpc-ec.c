void F_1 ( struct V_1 * V_2 , void * V_3 )
{
V_4 = V_2 ;
V_5 = V_3 ;
}
static void F_2 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 , struct V_8 , V_10 ) ;
struct V_11 * V_12 = NULL ;
unsigned long V_13 ;
F_4 ( & V_9 -> V_14 , V_13 ) ;
if ( ! F_5 ( & V_9 -> V_15 ) ) {
V_12 = F_6 ( & V_9 -> V_15 , struct V_11 , V_16 ) ;
F_7 ( & V_12 -> V_16 ) ;
}
F_8 ( & V_9 -> V_14 , V_13 ) ;
if ( ! V_12 )
return;
F_9 ( & V_9 -> V_17 ) ;
V_12 -> V_18 = V_4 -> V_19 ( V_12 -> V_20 , V_12 -> V_21 , V_12 -> V_22 ,
V_12 -> V_23 , V_12 -> V_24 , V_5 ) ;
F_10 ( & V_9 -> V_17 ) ;
F_11 ( & V_12 -> V_25 ) ;
F_12 ( & V_9 -> V_10 ) ;
}
static void F_13 ( struct V_11 * V_12 ,
struct V_8 * V_9 )
{
unsigned long V_13 ;
F_14 ( & V_12 -> V_16 ) ;
F_4 ( & V_9 -> V_14 , V_13 ) ;
F_15 ( & V_12 -> V_16 , & V_9 -> V_15 ) ;
F_8 ( & V_9 -> V_14 , V_13 ) ;
F_12 ( & V_9 -> V_10 ) ;
}
int F_16 ( T_1 V_20 , T_1 * V_21 , T_2 V_22 , T_1 * V_23 , T_2 V_24 )
{
struct V_8 * V_9 = V_26 ;
struct V_11 V_12 ;
if ( F_17 ( ! V_4 || ! V_4 -> V_19 ) )
return - V_27 ;
if ( ! V_9 )
return - V_28 ;
if ( F_17 ( V_9 -> V_29 ) )
return - V_30 ;
F_18 () ;
V_12 . V_20 = V_20 ;
V_12 . V_21 = V_21 ;
V_12 . V_23 = V_23 ;
V_12 . V_22 = V_22 ;
V_12 . V_24 = V_24 ;
V_12 . V_18 = 0 ;
F_19 ( & V_12 . V_25 ) ;
F_13 ( & V_12 , V_9 ) ;
F_20 ( & V_12 . V_25 ) ;
return V_12 . V_18 ;
}
static T_3 F_21 ( struct V_31 * V_31 , const char T_4 * V_32 ,
T_2 V_33 , T_5 * V_34 )
{
int V_35 , V_36 ;
unsigned char V_19 [ V_37 ] ;
unsigned int V_38 [ V_37 ] ;
char V_39 [ 64 ] ;
int V_40 ;
F_9 ( & V_41 ) ;
V_33 = F_22 ( V_39 , sizeof( V_39 ) , V_34 , V_32 , V_33 ) ;
V_36 = sscanf ( V_39 , L_1 , & V_38 [ 0 ] ,
& V_42 , & V_38 [ 1 ] , & V_38 [ 2 ] ,
& V_38 [ 3 ] , & V_38 [ 4 ] , & V_38 [ 5 ] ) ;
if ( V_36 < 2 || V_42 > V_43 ) {
V_42 = 0 ;
F_23 ( L_2 ) ;
V_33 = - V_44 ;
goto V_45;
}
V_40 = V_36 - 2 ;
for ( V_35 = 0 ; V_35 <= V_40 ; V_35 ++ )
V_19 [ V_35 ] = V_38 [ V_35 ] ;
F_23 ( L_3 ,
V_19 [ 0 ] , V_40 , V_19 [ 1 ] , V_19 [ 2 ] ,
V_19 [ 3 ] , V_19 [ 4 ] , V_19 [ 5 ] , V_42 ) ;
F_16 ( V_19 [ 0 ] , ( V_40 == 0 ) ? NULL : & V_19 [ 1 ] ,
V_40 , V_46 , V_42 ) ;
F_23 ( L_4 ,
V_46 [ 0 ] , V_46 [ 1 ] , V_46 [ 2 ] ,
V_46 [ 3 ] , V_46 [ 4 ] , V_46 [ 5 ] ,
V_46 [ 6 ] , V_46 [ 7 ] ,
V_42 ) ;
V_45:
F_10 ( & V_41 ) ;
return V_33 ;
}
static T_3 F_24 ( struct V_31 * V_31 , char T_4 * V_32 ,
T_2 V_33 , T_5 * V_34 )
{
unsigned int V_35 , V_47 ;
char * V_48 ;
char V_49 [ 64 ] ;
F_9 ( & V_41 ) ;
V_48 = V_49 ;
V_48 += sprintf ( V_48 , L_5 , V_46 [ 0 ] ) ;
for ( V_35 = 1 ; V_35 < V_42 ; V_35 ++ )
V_48 += sprintf ( V_48 , L_6 , V_46 [ V_35 ] ) ;
F_10 ( & V_41 ) ;
V_48 += sprintf ( V_48 , L_7 ) ;
V_47 = V_48 - V_49 ;
return F_25 ( V_32 , V_33 , V_34 , V_49 , V_47 ) ;
}
static struct V_50 * F_26 ( void )
{
struct V_50 * V_51 ;
V_51 = F_27 ( L_8 , NULL ) ;
if ( F_28 ( V_51 ) )
return NULL ;
F_29 ( L_9 , 0600 , V_51 , NULL , & V_52 ) ;
return V_51 ;
}
static struct V_50 * F_26 ( void )
{
return NULL ;
}
static int F_30 ( struct V_53 * V_54 )
{
struct V_8 * V_9 ;
int V_18 ;
if ( ! V_4 )
return - V_27 ;
V_9 = F_31 ( sizeof( * V_9 ) , V_55 ) ;
if ( ! V_9 )
return - V_28 ;
V_9 -> V_2 = V_4 ;
F_32 ( & V_9 -> V_10 , F_2 ) ;
F_33 ( & V_9 -> V_17 ) ;
F_14 ( & V_9 -> V_15 ) ;
F_34 ( & V_9 -> V_14 ) ;
V_26 = V_9 ;
F_35 ( V_54 , V_9 ) ;
V_18 = V_4 -> V_56 ? V_4 -> V_56 ( V_54 ) : 0 ;
if ( V_18 ) {
V_26 = NULL ;
F_36 ( V_9 ) ;
} else {
V_9 -> V_51 = F_26 () ;
}
return V_18 ;
}
static int F_37 ( struct V_57 * V_58 )
{
struct V_53 * V_54 = F_38 ( V_58 ) ;
struct V_8 * V_9 = F_39 ( V_54 ) ;
int V_18 = 0 ;
if ( V_4 -> V_59 )
V_18 = V_4 -> V_59 ( V_54 ) ;
if ( ! V_18 )
V_9 -> V_29 = true ;
return V_18 ;
}
static int F_40 ( struct V_57 * V_58 )
{
struct V_53 * V_54 = F_38 ( V_58 ) ;
struct V_8 * V_9 = F_39 ( V_54 ) ;
V_9 -> V_29 = false ;
return V_4 -> V_60 ? V_4 -> V_60 ( V_54 ) : 0 ;
}
static int T_6 F_41 ( void )
{
return F_42 ( & V_61 ) ;
}
