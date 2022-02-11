static char * F_1 ( unsigned short V_1 )
{
switch ( V_1 ) {
case V_2 : return L_1 ;
case V_3 : return L_2 ;
case V_4 : return L_3 ;
default: return L_4 ;
}
}
static void * F_2 ( struct V_5 * V_6 , T_1 * V_7 )
__acquires( T_2 )
{
F_3 ( & T_2 ) ;
if ( * V_7 < V_8 )
return & V_9 [ * V_7 ] ;
return NULL ;
}
static void * F_4 ( struct V_5 * V_6 , void * V_10 , T_1 * V_7 )
{
++ * V_7 ;
if ( * V_7 < V_8 )
return & V_9 [ * V_7 ] ;
return NULL ;
}
static void F_5 ( struct V_5 * V_6 , void * V_10 )
__releases( T_2 )
{
F_6 ( & T_2 ) ;
}
static int F_7 ( struct V_5 * V_6 , void * V_10 )
{
struct V_11 * V_12 = * (struct V_11 * * ) V_10 ;
if ( ! V_12 )
return 0 ;
F_8 ( V_6 , L_5 ,
V_12 -> V_13 , V_12 -> V_14 ,
F_1 ( V_12 -> V_1 ) ,
V_12 -> V_15 ,
V_12 -> V_16 ? V_12 -> V_16 ( V_12 ) : L_6 ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , void * V_10 )
{
struct V_11 * V_12 = * (struct V_11 * * ) V_10 ;
if ( ! V_12 )
return 0 ;
F_8 ( V_6 , L_7 ,
V_12 -> V_13 ,
V_12 -> V_17 ,
V_12 -> V_18 ,
V_12 -> V_19 ,
V_12 -> V_20 ) ;
return 0 ;
}
static int F_10 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_11 ( V_22 , & V_23 ) ;
}
static int F_12 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_11 ( V_22 , & V_24 ) ;
}
static void * F_13 ( struct V_5 * V_6 , T_1 * V_7 )
__acquires( T_2 )
{
F_3 ( & T_2 ) ;
if ( * V_7 < V_25 )
return & V_26 [ * V_7 ] ;
return NULL ;
}
static void *
F_14 ( struct V_5 * V_6 , void * V_10 , T_1 * V_7 )
{
++ * V_7 ;
if ( * V_7 < V_25 )
return & V_26 [ * V_7 ] ;
return NULL ;
}
static void F_15 ( struct V_5 * V_6 , void * V_10 )
__releases( T_2 )
{
F_6 ( & T_2 ) ;
}
static int
F_16 ( struct V_5 * V_6 , void * V_10 )
{
struct V_27 * V_28 = * (struct V_27 * * ) V_10 ;
if ( ! V_28 )
return 0 ;
F_8 ( V_6 , L_8 ,
V_28 -> V_29 ,
V_28 -> V_30 . V_31 ,
V_28 -> V_30 . V_32 ,
V_28 -> V_30 . V_33 ) ;
return 0 ;
}
static int
F_17 ( struct V_5 * V_6 , void * V_10 )
{
struct V_27 * V_28 = * (struct V_27 * * ) V_10 ;
if ( ! V_28 )
return 0 ;
F_8 ( V_6 , L_9 ,
V_28 -> V_29 ,
V_28 -> V_17 ,
V_28 -> V_18 ,
V_28 -> V_19 ,
V_28 -> V_20 ) ;
return 0 ;
}
static int
F_18 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_11 ( V_22 , & V_34 ) ;
}
static int
F_19 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_11 ( V_22 , & V_35 ) ;
}
static void * F_20 ( struct V_5 * V_6 , T_1 * V_7 )
__acquires( &capi_drivers_lock
static void * F_21 ( struct V_5 * V_6 , void * V_10 , T_1 * V_7 )
{
return F_22 ( V_10 , & V_36 , V_7 ) ;
}
static void F_23 ( struct V_5 * V_6 , void * V_10 )
__releases( &capi_drivers_lock
static int F_24 ( struct V_5 * V_6 , void * V_10 )
{
struct V_37 * V_38 = F_25 ( V_10 , struct V_37 , V_39 ) ;
F_8 ( V_6 , L_10 , V_38 -> V_15 , V_38 -> V_40 ) ;
return 0 ;
}
static int
F_26 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
int V_41 ;
V_41 = F_11 ( V_22 , & V_42 ) ;
return V_41 ;
}
void T_3
F_27 ( void )
{
F_28 ( L_11 , NULL ) ;
F_28 ( L_12 , NULL ) ;
F_29 ( L_13 , 0 , NULL , & V_43 ) ;
F_29 ( L_14 , 0 , NULL , & V_44 ) ;
F_29 ( L_15 , 0 , NULL , & V_45 ) ;
F_29 ( L_16 , 0 , NULL , & V_46 ) ;
F_29 ( L_17 , 0 , NULL , & V_47 ) ;
}
void T_4
F_30 ( void )
{
F_31 ( L_17 , NULL ) ;
F_31 ( L_13 , NULL ) ;
F_31 ( L_14 , NULL ) ;
F_31 ( L_15 , NULL ) ;
F_31 ( L_16 , NULL ) ;
F_31 ( L_12 , NULL ) ;
F_31 ( L_11 , NULL ) ;
}
