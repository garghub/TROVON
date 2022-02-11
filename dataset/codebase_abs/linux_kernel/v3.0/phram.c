static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 * V_5 = V_2 -> V_6 ;
if ( V_4 -> V_7 + V_4 -> V_8 > V_2 -> V_9 )
return - V_10 ;
memset ( V_5 + V_4 -> V_7 , 0xff , V_4 -> V_8 ) ;
V_4 -> V_11 = V_12 ;
F_2 ( V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_2 V_13 , T_3 V_8 ,
T_3 * V_14 , void * * V_15 , T_4 * V_16 )
{
if ( V_13 + V_8 > V_2 -> V_9 )
return - V_10 ;
if ( V_16 )
return - V_10 ;
* V_15 = V_2 -> V_6 + V_13 ;
* V_14 = V_8 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , T_2 V_13 , T_3 V_8 )
{
}
static int F_5 ( struct V_1 * V_2 , T_2 V_13 , T_3 V_8 ,
T_3 * V_14 , T_1 * V_17 )
{
T_1 * V_5 = V_2 -> V_6 ;
if ( V_13 >= V_2 -> V_9 )
return - V_10 ;
if ( V_8 > V_2 -> V_9 - V_13 )
V_8 = V_2 -> V_9 - V_13 ;
memcpy ( V_17 , V_5 + V_13 , V_8 ) ;
* V_14 = V_8 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_18 , T_3 V_8 ,
T_3 * V_14 , const T_1 * V_17 )
{
T_1 * V_5 = V_2 -> V_6 ;
if ( V_18 >= V_2 -> V_9 )
return - V_10 ;
if ( V_8 > V_2 -> V_9 - V_18 )
V_8 = V_2 -> V_9 - V_18 ;
memcpy ( V_5 + V_18 , V_17 , V_8 ) ;
* V_14 = V_8 ;
return 0 ;
}
static void F_7 ( void )
{
struct V_19 * V_20 , * V_21 ;
F_8 (this, safe, &phram_list, list) {
F_9 ( & V_20 -> V_2 ) ;
F_10 ( V_20 -> V_2 . V_6 ) ;
F_11 ( V_20 -> V_2 . V_22 ) ;
F_11 ( V_20 ) ;
}
}
static int F_12 ( char * V_22 , unsigned long V_5 , unsigned long V_8 )
{
struct V_19 * V_23 ;
int V_24 = - V_25 ;
V_23 = F_13 ( sizeof( * V_23 ) , V_26 ) ;
if ( ! V_23 )
goto V_27;
V_24 = - V_28 ;
V_23 -> V_2 . V_6 = F_14 ( V_5 , V_8 ) ;
if ( ! V_23 -> V_2 . V_6 ) {
F_15 ( L_1 ) ;
goto V_29;
}
V_23 -> V_2 . V_22 = V_22 ;
V_23 -> V_2 . V_9 = V_8 ;
V_23 -> V_2 . V_30 = V_31 ;
V_23 -> V_2 . V_32 = F_1 ;
V_23 -> V_2 . V_33 = F_3 ;
V_23 -> V_2 . V_34 = F_4 ;
V_23 -> V_2 . V_35 = F_5 ;
V_23 -> V_2 . V_36 = F_6 ;
V_23 -> V_2 . V_37 = V_38 ;
V_23 -> V_2 . type = V_39 ;
V_23 -> V_2 . V_40 = V_41 ;
V_23 -> V_2 . V_42 = 1 ;
V_24 = - V_43 ;
if ( F_16 ( & V_23 -> V_2 , NULL , 0 ) ) {
F_15 ( L_2 ) ;
goto V_44;
}
F_17 ( & V_23 -> V_45 , & V_46 ) ;
return 0 ;
V_44:
F_10 ( V_23 -> V_2 . V_6 ) ;
V_29:
F_11 ( V_23 ) ;
V_27:
return V_24 ;
}
static int F_18 ( const char * V_47 , char * * V_48 , unsigned int V_49 )
{
unsigned long V_50 = F_19 ( V_47 , V_48 , V_49 ) ;
switch ( * * V_48 ) {
case 'G' :
V_50 *= 1024 ;
case 'M' :
V_50 *= 1024 ;
case 'k' :
V_50 *= 1024 ;
if ( ( * V_48 ) [ 1 ] == 'i' )
( * V_48 ) += 2 ;
}
return V_50 ;
}
static int F_20 ( T_5 * V_51 , const char * V_52 )
{
char * V_48 ;
unsigned long V_53 ;
V_53 = F_18 ( V_52 , & V_48 , 0 ) ;
if ( * V_48 )
return - V_10 ;
* V_51 = V_53 ;
return 0 ;
}
static int F_21 ( char * * V_54 , const char * V_52 )
{
T_3 V_8 ;
char * V_22 ;
V_8 = strlen ( V_52 ) + 1 ;
if ( V_8 > 64 )
return - V_55 ;
V_22 = F_22 ( V_8 , V_26 ) ;
if ( ! V_22 )
return - V_25 ;
strcpy ( V_22 , V_52 ) ;
* V_54 = V_22 ;
return 0 ;
}
static inline void F_23 ( char * V_56 )
{
char * V_57 = strrchr ( V_56 , '\n' ) ;
if ( V_57 && ! V_57 [ 1 ] )
* V_57 = 0 ;
}
static int F_24 ( const char * V_58 , struct V_59 * V_60 )
{
char V_17 [ 64 + 12 + 12 ] , * V_56 = V_17 ;
char * V_52 [ 3 ] ;
char * V_22 ;
T_5 V_5 ;
T_5 V_8 ;
int V_61 , V_24 ;
if ( F_25 ( V_58 , sizeof( V_17 ) ) >= sizeof( V_17 ) )
F_26 ( L_3 ) ;
strcpy ( V_56 , V_58 ) ;
F_23 ( V_56 ) ;
for ( V_61 = 0 ; V_61 < 3 ; V_61 ++ )
V_52 [ V_61 ] = F_27 ( & V_56 , L_4 ) ;
if ( V_56 )
F_26 ( L_5 ) ;
if ( ! V_52 [ 2 ] )
F_26 ( L_6 ) ;
V_24 = F_21 ( & V_22 , V_52 [ 0 ] ) ;
if ( V_24 )
return V_24 ;
V_24 = F_20 ( & V_5 , V_52 [ 1 ] ) ;
if ( V_24 ) {
F_11 ( V_22 ) ;
F_26 ( L_7 ) ;
}
V_24 = F_20 ( & V_8 , V_52 [ 2 ] ) ;
if ( V_24 ) {
F_11 ( V_22 ) ;
F_26 ( L_8 ) ;
}
V_24 = F_12 ( V_22 , V_5 , V_8 ) ;
if ( ! V_24 )
F_28 ( L_9 , V_22 , V_8 , V_5 ) ;
else
F_11 ( V_22 ) ;
return V_24 ;
}
static int T_6 F_29 ( void )
{
return 0 ;
}
static void T_7 F_30 ( void )
{
F_7 () ;
}
