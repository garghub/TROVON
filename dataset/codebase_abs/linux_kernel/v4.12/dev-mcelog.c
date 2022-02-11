static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_5 = (struct V_5 * ) V_4 ;
unsigned int V_6 , V_7 ;
F_2 () ;
for (; ; ) {
V_7 = F_3 ( V_8 . V_6 ) ;
for (; ; ) {
if ( V_7 >= V_9 ) {
F_4 ( V_10 ,
( unsigned long * ) & V_8 . V_11 ) ;
return V_12 ;
}
if ( V_8 . V_7 [ V_7 ] . V_13 ) {
V_7 ++ ;
continue;
}
break;
}
F_5 () ;
V_6 = V_7 + 1 ;
if ( F_6 ( & V_8 . V_6 , V_7 , V_6 ) == V_7 )
break;
}
memcpy ( V_8 . V_7 + V_7 , V_5 , sizeof( struct V_5 ) ) ;
F_2 () ;
V_8 . V_7 [ V_7 ] . V_13 = 1 ;
F_2 () ;
F_7 ( & V_14 ) ;
return V_12 ;
}
static void F_8 ( struct V_15 * V_16 )
{
F_9 ( V_17 , V_18 , NULL , V_19 ) ;
}
void F_10 ( void )
{
if ( V_17 [ 0 ] )
F_11 ( & V_20 ) ;
}
static T_1
F_12 ( struct V_21 * V_22 , struct V_23 * V_24 , char * V_25 )
{
strcpy ( V_25 , V_17 ) ;
strcat ( V_25 , L_1 ) ;
return strlen ( V_17 ) + 1 ;
}
static T_1 F_13 ( struct V_21 * V_22 , struct V_23 * V_24 ,
const char * V_25 , T_2 V_26 )
{
char * V_27 ;
strncpy ( V_17 , V_25 , sizeof( V_17 ) ) ;
V_17 [ sizeof( V_17 ) - 1 ] = 0 ;
V_27 = strchr ( V_17 , '\n' ) ;
if ( V_27 )
* V_27 = 0 ;
return strlen ( V_17 ) + ! ! V_27 ;
}
static int F_14 ( struct V_28 * V_28 , struct V_29 * V_29 )
{
F_15 ( & V_30 ) ;
if ( V_31 ||
( V_32 && ( V_29 -> V_33 & V_34 ) ) ) {
F_16 ( & V_30 ) ;
return - V_35 ;
}
if ( V_29 -> V_33 & V_34 )
V_31 = 1 ;
V_32 ++ ;
F_16 ( & V_30 ) ;
return F_17 ( V_28 , V_29 ) ;
}
static int F_18 ( struct V_28 * V_28 , struct V_29 * V_29 )
{
F_15 ( & V_30 ) ;
V_32 -- ;
V_31 = 0 ;
F_16 ( & V_30 ) ;
return 0 ;
}
static void F_19 ( void * V_4 )
{
unsigned long * V_36 = ( unsigned long * ) V_4 ;
V_36 [ F_20 () ] = F_21 () ;
}
static int F_22 ( char T_3 * * V_37 , T_2 V_38 )
{
int V_39 ;
T_4 V_40 ;
struct V_5 V_41 ;
if ( V_38 < sizeof( struct V_5 ) )
return - V_42 ;
V_39 = F_23 ( & V_41 , & V_40 ) ;
if ( V_39 <= 0 ) {
V_43 = 1 ;
if ( V_39 == - V_44 )
return 0 ;
return V_39 ;
}
V_39 = - V_45 ;
if ( F_24 ( * V_37 , & V_41 , sizeof( struct V_5 ) ) )
return V_39 ;
V_39 = F_25 ( V_40 ) ;
if ( V_39 ) {
V_43 = 1 ;
return V_39 ;
}
* V_37 += sizeof( struct V_5 ) ;
return 0 ;
}
static T_1 F_26 ( struct V_29 * V_46 , char T_3 * V_37 ,
T_2 V_38 , T_5 * V_47 )
{
char T_3 * V_25 = V_37 ;
unsigned long * V_36 ;
unsigned V_48 , V_6 ;
int V_49 , V_50 ;
V_36 = F_27 ( V_51 * sizeof( long ) , V_52 ) ;
if ( ! V_36 )
return - V_53 ;
F_28 ( & V_54 ) ;
if ( ! V_43 ) {
V_50 = F_22 ( & V_25 , V_38 ) ;
if ( V_50 || V_25 != V_37 )
goto V_55;
}
V_6 = F_3 ( V_8 . V_6 ) ;
V_50 = - V_42 ;
if ( * V_47 != 0 || V_38 < V_9 * sizeof( struct V_5 ) )
goto V_55;
V_50 = 0 ;
V_48 = 0 ;
do {
for ( V_49 = V_48 ; V_49 < V_6 ; V_49 ++ ) {
unsigned long V_56 = V_57 ;
struct V_5 * V_41 = & V_8 . V_7 [ V_49 ] ;
while ( ! V_41 -> V_13 ) {
if ( F_29 ( V_57 , V_56 + 2 ) ) {
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
goto V_58;
}
F_30 () ;
}
F_5 () ;
V_50 |= F_24 ( V_25 , V_41 , sizeof( * V_41 ) ) ;
V_25 += sizeof( * V_41 ) ;
V_58:
;
}
memset ( V_8 . V_7 + V_48 , 0 ,
( V_6 - V_48 ) * sizeof( struct V_5 ) ) ;
V_48 = V_6 ;
V_6 = F_6 ( & V_8 . V_6 , V_48 , 0 ) ;
} while ( V_6 != V_48 );
F_31 () ;
F_32 ( F_19 , V_36 , 1 ) ;
for ( V_49 = V_6 ; V_49 < V_9 ; V_49 ++ ) {
struct V_5 * V_41 = & V_8 . V_7 [ V_49 ] ;
if ( V_41 -> V_13 && V_41 -> V_59 < V_36 [ V_41 -> V_60 ] ) {
V_50 |= F_24 ( V_25 , V_41 , sizeof( * V_41 ) ) ;
F_5 () ;
V_25 += sizeof( * V_41 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
}
}
if ( V_50 )
V_50 = - V_45 ;
V_55:
F_33 ( & V_54 ) ;
F_34 ( V_36 ) ;
return V_50 ? V_50 : V_25 - V_37 ;
}
static unsigned int F_35 ( struct V_29 * V_29 , T_6 * V_61 )
{
F_36 ( V_29 , & V_14 , V_61 ) ;
if ( F_37 ( V_8 . V_6 ) )
return V_62 | V_63 ;
if ( ! V_43 && F_38 () )
return V_62 | V_63 ;
return 0 ;
}
static long F_39 ( struct V_29 * V_64 , unsigned int V_65 ,
unsigned long V_66 )
{
int T_3 * V_27 = ( int T_3 * ) V_66 ;
if ( ! F_40 ( V_67 ) )
return - V_68 ;
switch ( V_65 ) {
case V_69 :
return F_41 ( sizeof( struct V_5 ) , V_27 ) ;
case V_70 :
return F_41 ( V_9 , V_27 ) ;
case V_71 : {
unsigned V_11 ;
do {
V_11 = V_8 . V_11 ;
} while ( F_6 ( & V_8 . V_11 , V_11 , 0 ) != V_11 );
return F_41 ( V_11 , V_27 ) ;
}
default:
return - V_72 ;
}
}
void F_42 ( T_1 (* F_43)( struct V_29 * V_46 ,
const char T_3 * V_37 ,
T_2 V_38 , T_5 * V_47 ) )
{
V_73 = F_43 ;
}
static T_1 F_44 ( struct V_29 * V_46 , const char T_3 * V_37 ,
T_2 V_38 , T_5 * V_47 )
{
if ( V_73 )
return V_73 ( V_46 , V_37 , V_38 , V_47 ) ;
else
return - V_42 ;
}
static T_7 int F_45 ( void )
{
int V_50 ;
V_50 = F_46 ( & V_74 ) ;
if ( V_50 ) {
F_47 ( L_2 , V_50 ) ;
return V_50 ;
}
F_48 ( & V_75 ) ;
return 0 ;
}
