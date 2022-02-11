static const char * F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
return L_4 ;
}
return L_5 ;
}
static const char * F_2 ( int V_1 )
{
switch ( V_1 ) {
case V_6 :
return L_2 ;
case V_7 :
return L_6 ;
case V_8 :
return L_3 ;
}
return L_5 ;
}
static void * F_3 ( struct V_9 * V_10 , T_1 * V_11 )
{
T_1 V_12 = * V_11 ;
struct V_13 * V_14 ;
if ( ! V_12 -- )
return V_15 ;
for ( V_14 = V_16 ; V_14 ; V_14 = V_14 -> V_17 )
if ( ! V_12 -- )
return V_14 ;
return NULL ;
}
static void * F_4 ( struct V_9 * V_10 , void * V_18 , T_1 * V_11 )
{
struct V_13 * V_19 = V_18 ;
( * V_11 ) ++ ;
return V_18 == V_15 ? V_16 : V_19 -> V_17 ;
}
static void F_5 ( struct V_9 * V_10 , void * V_18 )
{
}
static int F_6 ( struct V_9 * V_10 , void * V_18 )
{
struct V_13 * V_14 = V_18 ;
int V_20 ;
T_2 * V_21 ;
T_3 * V_22 ;
struct V_23 V_24 ;
unsigned char V_25 [ 16 ] ;
if ( V_18 == V_15 ) {
F_7 ( V_10 ) ;
return 0 ;
}
F_8 ( V_10 , L_7 , V_14 -> V_26 ) ;
F_8 ( V_10 , L_8 ) ;
F_9 ( & V_24 ) ;
for ( V_21 = V_14 -> V_27 ; V_21 ; V_21 = V_21 -> V_17 ) {
sprintf ( V_25 , L_9 , & V_21 -> V_28 . V_29 ) ;
F_8 ( V_10 , L_10 ,
V_25 ,
F_1 ( V_21 -> V_30 ) ,
V_21 -> V_28 . V_31 -
( V_24 . V_32 - V_21 -> V_33 . V_32 ) ,
V_21 -> V_34 ) ;
if ( V_21 -> V_35 )
F_8 ( V_10 , L_11 ,
V_21 -> V_35 -> V_36 ,
V_21 -> V_35 -> V_37 ) ;
F_8 ( V_10 , L_12 ) ;
}
F_8 ( V_10 , L_12 ) ;
F_8 ( V_10 , L_13 ) ;
for ( V_22 = V_14 -> V_38 ; V_22 ; V_22 = V_22 -> V_17 ) {
unsigned char * V_19 = V_22 -> V_28 . V_39 ;
for ( V_20 = 0 ; V_20 < V_40 ; V_20 ++ )
F_8 ( V_10 , L_14 , V_19 [ V_20 ] ) ;
F_8 ( V_10 , L_15 ,
( unsigned long ) F_10 ( V_22 -> V_28 . V_41 ) ,
F_2 ( V_22 -> V_30 ) ,
( V_22 -> V_28 . V_31 -
( V_24 . V_32 - V_22 -> V_33 . V_32 ) ) ,
V_22 -> V_42 ) ;
sprintf ( V_25 , L_9 , & V_22 -> V_43 ) ;
F_8 ( V_10 , L_16 , V_25 ) ;
if ( V_22 -> V_35 )
F_8 ( V_10 , L_17 ,
V_22 -> V_35 -> V_36 ,
V_22 -> V_35 -> V_37 ) ;
F_8 ( V_10 , L_12 ) ;
}
F_8 ( V_10 , L_12 ) ;
return 0 ;
}
static int F_11 ( struct V_44 * V_44 , struct V_45 * V_45 )
{
return F_12 ( V_45 , & V_46 ) ;
}
static T_4 F_13 ( struct V_45 * V_45 , const char T_5 * V_47 ,
T_6 V_48 , T_1 * V_49 )
{
char * V_50 , * V_19 ;
unsigned V_51 ;
if ( V_48 == 0 )
return 0 ;
if ( V_48 >= V_52 )
V_48 = V_52 - 1 ;
V_50 = ( char * ) F_14 ( V_53 ) ;
if ( ! V_50 )
return - V_54 ;
for ( V_19 = V_50 , V_51 = 0 ; V_51 < V_48 ; V_19 ++ , V_51 ++ ) {
if ( F_15 ( * V_19 , V_47 ++ ) ) {
F_16 ( ( unsigned long ) V_50 ) ;
return - V_55 ;
}
if ( * V_19 == '\0' || * V_19 == '\n' )
break;
}
* V_19 = '\0' ;
if ( ! F_17 ( V_50 ) )
F_18 ( L_18 , V_50 ) ;
F_16 ( ( unsigned long ) V_50 ) ;
return V_51 ;
}
static int F_17 ( const char * V_47 )
{
unsigned char V_56 [ 4 ] ;
int V_57 , V_58 , V_59 , V_60 ;
T_7 V_61 ;
struct V_62 V_63 ;
memset ( & V_63 , 0 , sizeof( struct V_62 ) ) ;
if ( sscanf ( V_47 , L_19 ,
V_56 , V_56 + 1 , V_56 + 2 , V_56 + 3 ) == 4 ) {
V_61 = * ( T_7 * ) V_56 ;
return F_19 ( F_20 ( V_61 ) ) ;
}
if ( sscanf ( V_47 , L_20 ,
V_56 , V_56 + 1 , V_56 + 2 , V_56 + 3 , & V_57 , & V_58 ) == 6 ) {
V_59 = V_57 ;
V_60 = V_58 ;
} else if ( sscanf ( V_47 , L_21 ,
V_56 , V_56 + 1 , V_56 + 2 , V_56 + 3 , & V_57 , & V_58 , & V_59 , & V_60 ) != 8 )
return 0 ;
V_61 = * ( T_7 * ) V_56 ;
V_63 . V_64 . V_65 = V_66 ;
V_63 . V_64 . V_67 = V_57 ;
V_63 . V_64 . V_68 = V_58 ;
V_63 . V_69 . V_65 = V_66 ;
V_63 . V_69 . V_67 = V_59 ;
V_63 . V_69 . V_68 = V_60 ;
V_63 . V_70 = V_71 ;
F_21 ( L_22 ,
V_63 . V_64 . V_67 , V_63 . V_64 . V_68 ,
V_63 . V_69 . V_67 , V_63 . V_69 . V_68 ) ;
F_22 ( V_61 , & V_63 ) ;
return 1 ;
}
int F_23 ( void )
{
struct V_72 * V_19 ;
V_19 = F_24 ( V_73 , 0 , V_74 , & V_75 ) ;
if ( ! V_19 ) {
F_25 ( L_23 , V_73 ) ;
return - V_54 ;
}
return 0 ;
}
void F_26 ( void )
{
F_27 ( V_73 , V_74 ) ;
}
