static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_5 = (struct V_5 * ) V_4 ;
unsigned int V_6 ;
F_2 ( & V_7 ) ;
V_6 = V_8 . V_9 ;
if ( V_6 >= V_10 ) {
F_3 ( V_11 , ( unsigned long * ) & V_8 . V_12 ) ;
goto V_13;
}
V_8 . V_9 = V_6 + 1 ;
memcpy ( V_8 . V_6 + V_6 , V_5 , sizeof( struct V_5 ) ) ;
V_8 . V_6 [ V_6 ] . V_14 = 1 ;
F_4 ( & V_15 ) ;
V_13:
F_5 ( & V_7 ) ;
return V_16 ;
}
static void F_6 ( struct V_17 * V_18 )
{
F_7 ( V_19 , V_20 , NULL , V_21 ) ;
}
void F_8 ( void )
{
if ( V_19 [ 0 ] )
F_9 ( & V_22 ) ;
}
static T_1
F_10 ( struct V_23 * V_24 , struct V_25 * V_26 , char * V_27 )
{
strcpy ( V_27 , V_19 ) ;
strcat ( V_27 , L_1 ) ;
return strlen ( V_19 ) + 1 ;
}
static T_1 F_11 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 , T_2 V_28 )
{
char * V_29 ;
strncpy ( V_19 , V_27 , sizeof( V_19 ) ) ;
V_19 [ sizeof( V_19 ) - 1 ] = 0 ;
V_29 = strchr ( V_19 , '\n' ) ;
if ( V_29 )
* V_29 = 0 ;
return strlen ( V_19 ) + ! ! V_29 ;
}
static int F_12 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
F_13 ( & V_32 ) ;
if ( V_33 ||
( V_34 && ( V_31 -> V_35 & V_36 ) ) ) {
F_14 ( & V_32 ) ;
return - V_37 ;
}
if ( V_31 -> V_35 & V_36 )
V_33 = 1 ;
V_34 ++ ;
F_14 ( & V_32 ) ;
return F_15 ( V_30 , V_31 ) ;
}
static int F_16 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
F_13 ( & V_32 ) ;
V_34 -- ;
V_33 = 0 ;
F_14 ( & V_32 ) ;
return 0 ;
}
static int F_17 ( char T_3 * * V_38 , T_2 V_39 )
{
int V_40 ;
T_4 V_41 ;
struct V_5 V_42 ;
if ( V_39 < sizeof( struct V_5 ) )
return - V_43 ;
V_40 = F_18 ( & V_42 , & V_41 ) ;
if ( V_40 <= 0 ) {
V_44 = 1 ;
if ( V_40 == - V_45 )
return 0 ;
return V_40 ;
}
V_40 = - V_46 ;
if ( F_19 ( * V_38 , & V_42 , sizeof( struct V_5 ) ) )
return V_40 ;
V_40 = F_20 ( V_41 ) ;
if ( V_40 ) {
V_44 = 1 ;
return V_40 ;
}
* V_38 += sizeof( struct V_5 ) ;
return 0 ;
}
static T_1 F_21 ( struct V_31 * V_47 , char T_3 * V_38 ,
T_2 V_39 , T_5 * V_48 )
{
char T_3 * V_27 = V_38 ;
unsigned V_9 ;
int V_49 , V_50 ;
F_2 ( & V_7 ) ;
if ( ! V_44 ) {
V_50 = F_17 ( & V_27 , V_39 ) ;
if ( V_50 || V_27 != V_38 )
goto V_51;
}
V_50 = - V_43 ;
if ( * V_48 != 0 || V_39 < V_10 * sizeof( struct V_5 ) )
goto V_51;
V_9 = V_8 . V_9 ;
V_50 = 0 ;
for ( V_49 = 0 ; V_49 < V_9 ; V_49 ++ ) {
struct V_5 * V_42 = & V_8 . V_6 [ V_49 ] ;
V_50 |= F_19 ( V_27 , V_42 , sizeof( * V_42 ) ) ;
V_27 += sizeof( * V_42 ) ;
}
memset ( V_8 . V_6 , 0 , V_9 * sizeof( struct V_5 ) ) ;
V_8 . V_9 = 0 ;
if ( V_50 )
V_50 = - V_46 ;
V_51:
F_5 ( & V_7 ) ;
return V_50 ? V_50 : V_27 - V_38 ;
}
static unsigned int F_22 ( struct V_31 * V_31 , T_6 * V_52 )
{
F_23 ( V_31 , & V_15 , V_52 ) ;
if ( F_24 ( V_8 . V_9 ) )
return V_53 | V_54 ;
if ( ! V_44 && F_25 () )
return V_53 | V_54 ;
return 0 ;
}
static long F_26 ( struct V_31 * V_55 , unsigned int V_56 ,
unsigned long V_57 )
{
int T_3 * V_29 = ( int T_3 * ) V_57 ;
if ( ! F_27 ( V_58 ) )
return - V_59 ;
switch ( V_56 ) {
case V_60 :
return F_28 ( sizeof( struct V_5 ) , V_29 ) ;
case V_61 :
return F_28 ( V_10 , V_29 ) ;
case V_62 : {
unsigned V_12 ;
do {
V_12 = V_8 . V_12 ;
} while ( F_29 ( & V_8 . V_12 , V_12 , 0 ) != V_12 );
return F_28 ( V_12 , V_29 ) ;
}
default:
return - V_63 ;
}
}
void F_30 ( struct V_1 * V_2 )
{
F_31 ( & V_64 , V_2 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( & V_64 , V_2 ) ;
}
static T_1 F_34 ( struct V_31 * V_47 , const char T_3 * V_38 ,
T_2 V_39 , T_5 * V_48 )
{
struct V_5 V_42 ;
if ( ! F_27 ( V_58 ) )
return - V_59 ;
if ( ! F_35 ( V_65 ) || ! F_35 ( V_66 ) )
return - V_67 ;
if ( ( unsigned long ) V_39 > sizeof( struct V_5 ) )
V_39 = sizeof( struct V_5 ) ;
if ( F_36 ( & V_42 , V_38 , V_39 ) )
return - V_46 ;
if ( V_42 . V_68 >= F_37 () || ! F_38 ( V_42 . V_68 ) )
return - V_43 ;
F_39 ( 2 ) ;
F_40 ( & V_64 , 0 , & V_42 ) ;
return V_39 ;
}
static T_7 int F_41 ( void )
{
int V_50 ;
V_50 = F_42 ( & V_69 ) ;
if ( V_50 ) {
if ( V_50 == - V_37 )
F_43 ( L_2 ) ;
else
F_44 ( L_3 , V_50 ) ;
return V_50 ;
}
F_45 ( & V_70 ) ;
return 0 ;
}
