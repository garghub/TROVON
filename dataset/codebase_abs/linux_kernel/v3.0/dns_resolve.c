T_1 F_1 ( char * V_1 , T_2 V_2 ,
struct V_3 * V_4 , T_2 V_5 )
{
T_1 V_6 ;
char * V_7 = NULL ;
int V_8 ;
V_8 = F_2 ( NULL , V_1 , V_2 , NULL , & V_7 , NULL ) ;
if ( V_8 > 0 )
V_6 = F_3 ( V_7 , V_8 , V_4 , V_5 ) ;
else
V_6 = - V_9 ;
F_4 ( V_7 ) ;
return V_6 ;
}
static void F_5 ( struct V_10 * V_11 ,
struct V_10 * V_12 )
{
struct V_13 * V_14 ;
struct V_13 * V_15 ;
V_14 = F_6 ( V_11 , struct V_13 , V_16 ) ;
V_15 = F_6 ( V_12 , struct V_13 , V_16 ) ;
memcpy ( & V_14 -> V_17 , & V_15 -> V_17 , V_15 -> V_18 ) ;
V_14 -> V_18 = V_15 -> V_18 ;
}
static void F_7 ( struct V_10 * V_11 ,
struct V_10 * V_12 )
{
struct V_13 * V_14 ;
struct V_13 * V_15 ;
V_14 = F_6 ( V_11 , struct V_13 , V_16 ) ;
V_15 = F_6 ( V_12 , struct V_13 , V_16 ) ;
F_4 ( V_14 -> V_19 ) ;
V_14 -> V_19 = F_8 ( V_15 -> V_19 , V_15 -> V_2 , V_20 ) ;
if ( V_14 -> V_19 ) {
V_14 -> V_2 = V_15 -> V_2 ;
F_5 ( V_11 , V_12 ) ;
} else {
V_14 -> V_2 = 0 ;
V_14 -> V_18 = 0 ;
}
}
static void F_9 ( struct V_21 * V_22 )
{
struct V_13 * V_23 ;
V_23 = F_6 ( V_22 , struct V_13 , V_16 . V_22 ) ;
F_4 ( V_23 -> V_19 ) ;
F_4 ( V_23 ) ;
}
static struct V_10 * F_10 ( void )
{
struct V_13 * V_23 = F_11 ( sizeof( * V_23 ) , V_20 ) ;
if ( V_23 != NULL ) {
V_23 -> V_19 = NULL ;
V_23 -> V_2 = 0 ;
V_23 -> V_18 = 0 ;
return & V_23 -> V_16 ;
}
return NULL ;
}
static unsigned int F_12 ( const struct V_13 * V_15 )
{
return F_13 ( V_15 -> V_19 , V_24 ) ;
}
static void F_14 ( struct V_25 * V_26 ,
struct V_10 * V_27 ,
char * * V_28 , int * V_29 )
{
struct V_13 * V_15 = F_6 ( V_27 , struct V_13 , V_16 ) ;
F_15 ( V_28 , V_29 , V_15 -> V_19 ) ;
( * V_28 ) [ - 1 ] = '\n' ;
}
static int F_16 ( struct V_25 * V_26 ,
struct V_10 * V_27 )
{
struct V_13 * V_15 = F_6 ( V_27 , struct V_13 , V_16 ) ;
int V_6 ;
V_6 = F_17 ( V_26 , V_15 -> V_19 ) ;
if ( V_6 )
V_6 = F_18 ( V_26 , V_27 , F_14 ) ;
return V_6 ;
}
static int F_19 ( struct V_10 * V_30 ,
struct V_10 * V_31 )
{
struct V_13 * V_32 ;
struct V_13 * V_33 ;
V_32 = F_6 ( V_30 , struct V_13 , V_16 ) ;
V_33 = F_6 ( V_31 , struct V_13 , V_16 ) ;
if ( V_32 -> V_2 == 0 || V_32 -> V_2 != V_33 -> V_2 )
return 0 ;
return memcmp ( V_32 -> V_19 , V_33 -> V_19 , V_32 -> V_2 ) == 0 ;
}
static int F_20 ( struct V_34 * V_35 , struct V_25 * V_26 ,
struct V_10 * V_16 )
{
struct V_13 * V_23 ;
long V_36 ;
if ( V_16 == NULL ) {
F_21 ( V_35 , L_1 ) ;
return 0 ;
}
V_23 = F_6 ( V_16 , struct V_13 , V_16 ) ;
V_36 = V_23 -> V_16 . V_37 - F_22 () ;
if ( V_36 < 0 )
V_36 = 0 ;
if ( ! F_23 ( V_38 , & V_16 -> V_39 ) ) {
char V_40 [ V_41 + V_42 + 1 ] ;
F_24 ( (struct V_3 * ) & V_23 -> V_17 , V_40 , sizeof( V_40 ) ) ;
F_25 ( V_35 , L_2 , V_40 ) ;
} else
F_21 ( V_35 , L_3 ) ;
F_25 ( V_35 , L_4 , V_23 -> V_19 , V_36 ) ;
return 0 ;
}
static struct V_13 * F_26 ( struct V_25 * V_26 ,
struct V_13 * V_15 )
{
struct V_10 * V_27 ;
V_27 = F_27 ( V_26 ,
& V_15 -> V_16 ,
F_12 ( V_15 ) ) ;
if ( ! V_27 )
return NULL ;
return F_6 ( V_27 , struct V_13 , V_16 ) ;
}
static struct V_13 * F_28 ( struct V_25 * V_26 ,
struct V_13 * V_14 ,
struct V_13 * V_15 )
{
struct V_10 * V_27 ;
V_27 = F_29 ( V_26 ,
& V_14 -> V_16 , & V_15 -> V_16 ,
F_12 ( V_15 ) ) ;
if ( ! V_27 )
return NULL ;
return F_6 ( V_27 , struct V_13 , V_16 ) ;
}
static int F_30 ( struct V_25 * V_26 , char * V_40 , int V_43 )
{
char V_44 [ V_45 + 1 ] ;
struct V_13 V_15 , * V_23 ;
unsigned long V_36 ;
T_1 V_46 ;
int V_6 = - V_47 ;
if ( V_40 [ V_43 - 1 ] != '\n' )
goto V_48;
V_40 [ V_43 - 1 ] = '\0' ;
V_46 = F_31 ( & V_40 , V_44 , sizeof( V_44 ) ) ;
if ( V_46 <= 0 )
goto V_48;
V_15 . V_18 = F_3 ( V_44 , V_46 ,
(struct V_3 * ) & V_15 . V_17 ,
sizeof( V_15 . V_17 ) ) ;
V_46 = F_31 ( & V_40 , V_44 , sizeof( V_44 ) ) ;
if ( V_46 <= 0 )
goto V_48;
V_15 . V_19 = V_44 ;
V_15 . V_2 = V_46 ;
memset ( & V_15 . V_16 , 0 , sizeof( V_15 . V_16 ) ) ;
V_36 = F_32 ( & V_40 ) ;
if ( V_36 == 0 )
goto V_48;
V_15 . V_16 . V_37 = V_36 + F_22 () ;
V_6 = - V_49 ;
V_23 = F_26 ( V_26 , & V_15 ) ;
if ( V_23 == NULL )
goto V_48;
if ( V_15 . V_18 == 0 )
F_33 ( V_38 , & V_15 . V_16 . V_39 ) ;
V_23 = F_28 ( V_26 , & V_15 , V_23 ) ;
if ( V_23 == NULL )
goto V_48;
V_6 = 0 ;
F_34 ( & V_23 -> V_16 , V_26 ) ;
V_48:
return V_6 ;
}
static int F_35 ( struct V_25 * V_26 ,
struct V_13 * V_15 ,
struct V_13 * * V_23 ,
struct V_50 * V_51 )
{
int V_6 = - V_49 ;
* V_23 = F_26 ( V_26 , V_15 ) ;
if ( * V_23 ) {
V_6 = F_36 ( V_26 , & ( * V_23 ) -> V_16 , & V_51 -> V_52 ) ;
if ( V_6 )
* V_23 = NULL ;
}
return V_6 ;
}
static int F_37 ( struct V_25 * V_26 ,
struct V_13 * V_15 ,
struct V_13 * * V_23 )
{
int V_6 = - V_49 ;
* V_23 = F_26 ( V_26 , V_15 ) ;
if ( ! * V_23 )
goto V_53;
V_6 = - V_54 ;
if ( ! F_23 ( V_55 , & ( * V_23 ) -> V_16 . V_39 )
|| ( * V_23 ) -> V_16 . V_37 < F_22 ()
|| V_26 -> V_56 > ( * V_23 ) -> V_16 . V_57 )
goto V_58;
V_6 = - V_59 ;
if ( F_23 ( V_38 , & ( * V_23 ) -> V_16 . V_39 ) )
goto V_58;
return 0 ;
V_58:
F_34 ( & ( * V_23 ) -> V_16 , V_26 ) ;
V_53:
* V_23 = NULL ;
return V_6 ;
}
static int F_38 ( struct V_25 * V_26 ,
struct V_13 * V_15 ,
struct V_13 * * V_23 )
{
struct V_50 * V_51 ;
int V_6 = - V_49 ;
V_51 = F_39 () ;
if ( ! V_51 )
goto V_48;
V_6 = F_35 ( V_26 , V_15 , V_23 , V_51 ) ;
if ( V_6 == - V_60 ) {
V_6 = F_40 ( V_51 ) ;
if ( ! V_6 )
V_6 = F_37 ( V_26 , V_15 , V_23 ) ;
}
F_41 ( V_51 ) ;
V_48:
return V_6 ;
}
T_1 F_1 ( char * V_1 , T_2 V_2 ,
struct V_3 * V_4 , T_2 V_5 )
{
struct V_13 V_15 = {
. V_19 = V_1 ,
. V_2 = V_2 ,
} ;
struct V_13 * V_23 = NULL ;
T_1 V_6 ;
V_6 = F_38 ( & V_61 , & V_15 , & V_23 ) ;
if ( V_6 == 0 ) {
if ( V_5 >= V_23 -> V_18 ) {
memcpy ( V_4 , & V_23 -> V_17 , V_23 -> V_18 ) ;
V_6 = V_23 -> V_18 ;
} else
V_6 = - V_62 ;
F_34 ( & V_23 -> V_16 , & V_61 ) ;
} else if ( V_6 == - V_59 )
V_6 = - V_9 ;
return V_6 ;
}
int F_42 ( void )
{
return F_43 ( & V_61 ) ;
}
void F_44 ( void )
{
F_45 ( & V_61 ) ;
}
