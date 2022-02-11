static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
unsigned long V_6 = V_7 * 1000 / V_8 ;
return F_2 ( V_5 , V_9 , L_1 , V_6 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
unsigned long V_6 ;
if ( F_4 ( V_5 , 0 , & V_6 ) )
return - V_11 ;
V_7 = V_6 * V_8 / 1000 ;
return V_10 ;
}
static int F_5 ( void )
{
static unsigned long V_12 ;
unsigned long V_13 , V_14 ;
long V_15 ;
int V_16 = 0 ;
F_6 ( & V_17 ) ;
V_13 = V_18 ;
V_14 = V_12 + V_7 ;
if ( F_7 ( V_13 , V_14 ) ) {
V_15 = ( long ) ( V_14 ) - ( long ) V_13 ;
F_8 ( V_19 ) ;
if ( F_9 ( V_15 ) > 0 ) {
V_16 = - V_20 ;
goto V_21;
}
V_13 = V_18 ;
}
V_12 = V_13 ;
V_21:
F_10 ( & V_17 ) ;
return V_16 ;
}
static struct V_22 * F_11 ( struct V_23 * V_24 )
{
struct V_22 * V_25 ;
int V_26 ;
V_26 = F_12 ( sizeof( struct V_27 ) ,
sizeof( struct V_28 ) ) ;
V_25 = F_13 ( sizeof( * V_25 ) + V_26 , V_29 ) ;
if ( ! V_25 )
return NULL ;
V_25 -> V_30 = 0 ;
V_25 -> V_31 = V_32 + V_24 -> V_33 ;
V_25 -> V_34 = sizeof( struct V_27 ) ;
V_25 -> V_35 = sizeof( struct V_28 ) ;
return V_25 ;
}
static int F_14 ( struct V_23 * V_24 ,
T_3 * V_36 , T_3 * V_37 )
{
struct V_27 * V_38 ;
struct V_28 * V_39 ;
struct V_22 * V_25 ;
int V_16 ;
V_25 = F_11 ( V_24 ) ;
if ( ! V_25 )
return 0 ;
V_38 = (struct V_27 * ) V_25 -> V_40 ;
V_38 -> V_41 = V_42 ;
V_16 = F_15 ( V_24 -> V_43 , V_25 ) ;
if ( V_16 < 0 ) {
V_16 = 0 ;
goto exit;
}
switch ( V_25 -> V_44 ) {
case V_45 :
if ( V_36 )
* V_36 = 0 ;
if ( V_37 )
* V_37 = 0 ;
V_16 = 1 ;
goto exit;
case V_46 :
V_39 = (struct V_28 * ) V_25 -> V_40 ;
if ( V_36 )
* V_36 = V_39 -> V_30 . V_47 ;
if ( V_37 )
* V_37 = V_39 -> V_30 . V_48 ;
V_16 = 1 ;
goto exit;
}
V_16 = 0 ;
exit:
F_16 ( V_25 ) ;
return V_16 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_3 V_30 = 0 , V_48 = 0 ;
struct V_23 * V_24 = F_18 ( V_2 ,
struct V_23 , V_49 ) ;
int V_16 ;
V_16 = F_5 () ;
if ( V_16 )
return V_16 ;
if ( ! F_14 ( V_24 , & V_30 , & V_48 ) )
return - V_50 ;
return F_2 ( V_5 , V_9 , L_2 , V_30 , V_48 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_27 * V_38 ;
struct V_22 * V_25 ;
int V_16 ;
unsigned int V_51 ;
struct V_23 * V_24 = F_18 ( V_2 ,
struct V_23 , V_49 ) ;
if ( F_20 ( V_5 , 0 , & V_51 ) )
return - V_11 ;
V_25 = F_11 ( V_24 ) ;
if ( ! V_25 )
return - V_52 ;
V_38 = (struct V_27 * ) V_25 -> V_40 ;
V_38 -> V_41 = V_53 ;
V_38 -> V_54 . V_47 = V_51 ;
V_16 = F_5 () ;
if ( V_16 )
goto exit;
V_16 = F_15 ( V_24 -> V_43 , V_25 ) ;
if ( V_16 < 0 )
goto exit;
if ( V_25 -> V_44 != V_46 ) {
V_16 = - V_11 ;
goto exit;
}
V_16 = V_10 ;
exit:
F_16 ( V_25 ) ;
return V_16 ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_27 * V_38 ;
struct V_22 * V_25 ;
struct V_23 * V_24 = F_18 ( V_2 ,
struct V_23 , V_49 ) ;
unsigned int V_51 [ 4 ] ;
int V_16 , V_55 = 0 , V_56 = 0 , V_57 = 0 ;
V_25 = F_11 ( V_24 ) ;
if ( ! V_25 )
return - V_52 ;
do {
while ( * V_5 && isspace ( * V_5 ) )
V_5 ++ ;
if ( ! * V_5 )
break;
V_16 = sscanf ( V_5 , L_3 , & V_51 [ V_55 ++ ] ) ;
if ( V_16 == 0 )
goto exit;
if ( V_55 == 4 ) {
V_38 = (struct V_27 * ) V_25 -> V_40 ;
V_38 -> V_41 = V_58 ;
V_38 -> V_59 . V_60 = V_51 [ 0 ] ;
V_38 -> V_59 . V_61 = V_51 [ 1 ] ;
V_38 -> V_59 . V_62 = V_51 [ 2 ] ;
V_38 -> V_59 . V_63 = V_51 [ 3 ] ;
if ( ( V_56 ++ % 4 ) == 0 ) {
V_16 = F_5 () ;
if ( V_16 )
goto exit;
}
V_16 = F_15 ( V_24 -> V_43 , V_25 ) ;
if ( V_16 < 0 )
goto exit;
if ( V_25 -> V_44 != V_46 )
goto exit;
V_55 = 0 ;
V_57 = 1 ;
}
while ( * V_5 && ! isspace ( * V_5 ) )
V_5 ++ ;
} while ( * V_5 );
exit:
F_16 ( V_25 ) ;
return ( V_57 && V_55 == 0 ) ? V_10 : - V_11 ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_27 * V_38 ;
struct V_28 * V_39 ;
struct V_22 * V_25 ;
int V_16 ;
struct V_23 * V_24 = F_18 ( V_2 ,
struct V_23 , V_49 ) ;
V_25 = F_11 ( V_24 ) ;
if ( ! V_25 )
return - V_52 ;
V_38 = (struct V_27 * ) V_25 -> V_40 ;
V_38 -> V_41 = V_64 ;
V_16 = F_5 () ;
if ( V_16 )
goto exit;
V_16 = F_15 ( V_24 -> V_43 , V_25 ) ;
if ( V_16 < 0 )
goto exit;
if ( V_25 -> V_44 != V_46 ) {
V_16 = F_2 ( V_5 , V_9 ,
L_4 , V_25 -> V_44 ) ;
goto exit;
}
V_39 = (struct V_28 * ) V_25 -> V_40 ;
if ( V_39 -> V_65 . V_47 >= F_23 ( V_66 ) )
V_16 = F_2 ( V_5 , V_9 , L_5 , V_39 -> V_65 . V_47 ) ;
else
V_16 = F_2 ( V_5 , V_9 , L_6 ,
V_66 [ V_39 -> V_65 . V_47 ] ) ;
exit:
F_16 ( V_25 ) ;
return V_16 ;
}
static T_1 F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_27 * V_38 ;
struct V_22 * V_25 ;
unsigned int V_47 ;
int V_16 , V_26 ;
struct V_23 * V_24 = F_18 ( V_2 ,
struct V_23 , V_49 ) ;
for ( V_26 = 0 ; V_26 < V_10 ; V_26 ++ )
if ( ! isalnum ( V_5 [ V_26 ] ) )
break;
for ( V_47 = 0 ; V_47 < F_23 ( V_66 ) ; V_47 ++ )
if ( ! strncasecmp ( V_66 [ V_47 ] , V_5 , V_26 ) )
break;
if ( V_47 >= F_23 ( V_66 ) ) {
V_16 = F_20 ( V_5 , 0 , & V_47 ) ;
if ( V_16 )
return V_16 ;
}
V_25 = F_11 ( V_24 ) ;
if ( ! V_25 )
return - V_52 ;
V_38 = (struct V_27 * ) V_25 -> V_40 ;
V_38 -> V_41 = V_67 ;
V_38 -> V_68 . V_47 = V_47 ;
V_16 = F_5 () ;
if ( V_16 )
goto exit;
V_16 = F_15 ( V_24 -> V_43 , V_25 ) ;
if ( V_16 < 0 )
goto exit;
if ( V_25 -> V_44 != V_46 ) {
V_16 = - V_11 ;
goto exit;
}
V_16 = V_10 ;
exit:
F_16 ( V_25 ) ;
return V_16 ;
}
static T_4 F_25 ( struct V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
struct V_1 * V_2 = F_18 ( V_70 , struct V_1 , V_70 ) ;
struct V_23 * V_24 = F_18 ( V_2 ,
struct V_23 , V_49 ) ;
struct V_74 * V_75 = F_26 ( V_24 -> V_2 ) ;
struct V_76 * V_77 = V_75 -> V_2 . V_78 ;
int V_79 ;
V_79 = strcmp ( V_77 -> V_80 , V_81 ) ;
if ( V_79 != 0 )
return 0 ;
if ( F_14 ( V_24 , NULL , NULL ) )
return V_72 -> V_82 ;
else
return 0 ;
}
