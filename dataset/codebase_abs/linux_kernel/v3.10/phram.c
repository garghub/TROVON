static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 * V_5 = V_2 -> V_6 ;
memset ( V_5 + V_4 -> V_7 , 0xff , V_4 -> V_8 ) ;
V_4 -> V_9 = V_10 ;
F_2 ( V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_2 V_11 , T_3 V_8 ,
T_3 * V_12 , void * * V_13 , T_4 * V_14 )
{
* V_13 = V_2 -> V_6 + V_11 ;
* V_12 = V_8 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 V_11 , T_3 V_8 )
{
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_11 , T_3 V_8 ,
T_3 * V_12 , T_1 * V_15 )
{
T_1 * V_5 = V_2 -> V_6 ;
memcpy ( V_15 , V_5 + V_11 , V_8 ) ;
* V_12 = V_8 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_16 , T_3 V_8 ,
T_3 * V_12 , const T_1 * V_15 )
{
T_1 * V_5 = V_2 -> V_6 ;
memcpy ( V_5 + V_16 , V_15 , V_8 ) ;
* V_12 = V_8 ;
return 0 ;
}
static void F_7 ( void )
{
struct V_17 * V_18 , * V_19 ;
F_8 (this, safe, &phram_list, list) {
F_9 ( & V_18 -> V_2 ) ;
F_10 ( V_18 -> V_2 . V_6 ) ;
F_11 ( V_18 -> V_2 . V_20 ) ;
F_11 ( V_18 ) ;
}
}
static int F_12 ( char * V_20 , unsigned long V_5 , unsigned long V_8 )
{
struct V_17 * V_21 ;
int V_22 = - V_23 ;
V_21 = F_13 ( sizeof( * V_21 ) , V_24 ) ;
if ( ! V_21 )
goto V_25;
V_22 = - V_26 ;
V_21 -> V_2 . V_6 = F_14 ( V_5 , V_8 ) ;
if ( ! V_21 -> V_2 . V_6 ) {
F_15 ( L_1 ) ;
goto V_27;
}
V_21 -> V_2 . V_20 = V_20 ;
V_21 -> V_2 . V_28 = V_8 ;
V_21 -> V_2 . V_29 = V_30 ;
V_21 -> V_2 . V_31 = F_1 ;
V_21 -> V_2 . V_32 = F_3 ;
V_21 -> V_2 . V_33 = F_4 ;
V_21 -> V_2 . V_34 = F_5 ;
V_21 -> V_2 . V_35 = F_6 ;
V_21 -> V_2 . V_36 = V_37 ;
V_21 -> V_2 . type = V_38 ;
V_21 -> V_2 . V_39 = V_40 ;
V_21 -> V_2 . V_41 = 1 ;
V_22 = - V_42 ;
if ( F_16 ( & V_21 -> V_2 , NULL , 0 ) ) {
F_15 ( L_2 ) ;
goto V_43;
}
F_17 ( & V_21 -> V_44 , & V_45 ) ;
return 0 ;
V_43:
F_10 ( V_21 -> V_2 . V_6 ) ;
V_27:
F_11 ( V_21 ) ;
V_25:
return V_22 ;
}
static int F_18 ( const char * V_46 , char * * V_47 , unsigned int V_48 )
{
unsigned long V_49 = F_19 ( V_46 , V_47 , V_48 ) ;
switch ( * * V_47 ) {
case 'G' :
V_49 *= 1024 ;
case 'M' :
V_49 *= 1024 ;
case 'k' :
V_49 *= 1024 ;
if ( ( * V_47 ) [ 1 ] == 'i' )
( * V_47 ) += 2 ;
}
return V_49 ;
}
static int F_20 ( T_5 * V_50 , const char * V_51 )
{
char * V_47 ;
unsigned long V_52 ;
V_52 = F_18 ( V_51 , & V_47 , 0 ) ;
if ( * V_47 )
return - V_53 ;
* V_50 = V_52 ;
return 0 ;
}
static int F_21 ( char * * V_54 , const char * V_51 )
{
T_3 V_8 ;
char * V_20 ;
V_8 = strlen ( V_51 ) + 1 ;
if ( V_8 > 64 )
return - V_55 ;
V_20 = F_22 ( V_8 , V_24 ) ;
if ( ! V_20 )
return - V_23 ;
strcpy ( V_20 , V_51 ) ;
* V_54 = V_20 ;
return 0 ;
}
static inline void F_23 ( char * V_56 )
{
char * V_57 = strrchr ( V_56 , '\n' ) ;
if ( V_57 && ! V_57 [ 1 ] )
* V_57 = 0 ;
}
static int T_6 F_24 ( const char * V_58 )
{
char V_15 [ 64 + 12 + 12 ] , * V_56 = V_15 ;
char * V_51 [ 3 ] ;
char * V_20 ;
T_5 V_5 ;
T_5 V_8 ;
int V_59 , V_22 ;
if ( F_25 ( V_58 , sizeof( V_15 ) ) >= sizeof( V_15 ) )
F_26 ( L_3 ) ;
strcpy ( V_56 , V_58 ) ;
F_23 ( V_56 ) ;
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ )
V_51 [ V_59 ] = F_27 ( & V_56 , L_4 ) ;
if ( V_56 )
F_26 ( L_5 ) ;
if ( ! V_51 [ 2 ] )
F_26 ( L_6 ) ;
V_22 = F_21 ( & V_20 , V_51 [ 0 ] ) ;
if ( V_22 )
return V_22 ;
V_22 = F_20 ( & V_5 , V_51 [ 1 ] ) ;
if ( V_22 ) {
F_11 ( V_20 ) ;
F_26 ( L_7 ) ;
}
V_22 = F_20 ( & V_8 , V_51 [ 2 ] ) ;
if ( V_22 ) {
F_11 ( V_20 ) ;
F_26 ( L_8 ) ;
}
V_22 = F_12 ( V_20 , V_5 , V_8 ) ;
if ( ! V_22 )
F_28 ( L_9 , V_20 , V_8 , V_5 ) ;
else
F_11 ( V_20 ) ;
return V_22 ;
}
static int T_6 F_29 ( const char * V_58 , struct V_60 * V_61 )
{
if ( strlen ( V_58 ) >= sizeof( V_62 ) )
return - V_55 ;
strcpy ( V_62 , V_58 ) ;
return 0 ;
}
static int T_6 F_30 ( void )
{
if ( V_62 [ 0 ] )
return F_24 ( V_62 ) ;
return 0 ;
}
static void T_7 F_31 ( void )
{
F_7 () ;
}
