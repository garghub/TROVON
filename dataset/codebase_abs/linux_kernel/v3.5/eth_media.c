static void F_1 ( struct V_1 * V_2 , char * V_3 )
{
memcpy ( V_2 -> V_4 , V_3 , V_5 ) ;
memset ( V_2 -> V_4 + V_5 , 0 , sizeof( V_2 -> V_4 ) - V_5 ) ;
V_2 -> V_6 = V_7 ;
V_2 -> V_8 = ! memcmp ( V_3 , V_9 . V_10 . V_4 , V_5 ) ;
}
static int F_2 ( struct V_11 * V_12 , struct V_13 * V_14 ,
struct V_1 * V_15 )
{
struct V_11 * V_16 ;
struct V_17 * V_18 ;
int V_19 ;
V_16 = F_3 ( V_12 , V_20 ) ;
if ( ! V_16 )
return 0 ;
V_18 = ( (struct V_21 * ) ( V_14 -> V_22 ) ) -> V_18 ;
V_19 = V_18 -> V_23 - F_4 ( V_12 ) ;
if ( ( V_19 > 0 ) &&
F_5 ( V_16 , F_6 ( V_19 ) , 0 , V_20 ) ) {
F_7 ( V_16 ) ;
return 0 ;
}
F_8 ( V_16 ) ;
V_16 -> V_18 = V_18 ;
F_9 ( V_16 , V_18 , V_24 , V_15 -> V_4 ,
V_18 -> V_25 , V_16 -> V_26 ) ;
F_10 ( V_16 ) ;
return 0 ;
}
static int F_11 ( struct V_11 * V_12 , struct V_17 * V_18 ,
struct V_27 * V_28 , struct V_17 * V_29 )
{
struct V_21 * V_30 = (struct V_21 * ) V_28 -> V_31 ;
if ( ! F_12 ( F_13 ( V_18 ) , & V_32 ) ) {
F_7 ( V_12 ) ;
return 0 ;
}
if ( F_14 ( V_30 -> V_33 ) ) {
if ( F_14 ( V_12 -> V_34 <= V_35 ) ) {
V_12 -> V_36 = NULL ;
F_15 ( V_12 , V_30 -> V_33 ) ;
return 0 ;
}
}
F_7 ( V_12 ) ;
return 0 ;
}
static int F_16 ( struct V_13 * V_14 )
{
struct V_17 * V_18 = NULL ;
struct V_17 * V_37 = NULL ;
struct V_21 * V_30 = & V_38 [ 0 ] ;
struct V_21 * V_39 = & V_38 [ V_40 ] ;
char * V_41 = strchr ( ( const char * ) V_14 -> V_42 , ':' ) + 1 ;
int V_43 = 0 ;
while ( V_30 -> V_18 ) {
if ( ! V_30 -> V_33 )
V_43 ++ ;
if ( ++ V_30 == V_39 )
return V_43 ? - V_44 : - V_45 ;
}
F_17 ( & V_46 ) ;
F_18 (&init_net, pdev) {
if ( ! strncmp ( V_37 -> V_42 , V_41 , V_47 ) ) {
V_18 = V_37 ;
F_19 ( V_18 ) ;
break;
}
}
F_20 ( & V_46 ) ;
if ( ! V_18 )
return - V_48 ;
V_30 -> V_18 = V_18 ;
V_30 -> V_49 . type = F_21 ( V_24 ) ;
V_30 -> V_49 . V_18 = V_18 ;
V_30 -> V_49 . V_50 = F_11 ;
V_30 -> V_49 . V_31 = V_30 ;
F_22 ( & ( V_30 -> V_49 . V_51 ) ) ;
F_23 ( & V_30 -> V_49 ) ;
V_30 -> V_33 = V_14 ;
V_14 -> V_22 = ( void * ) V_30 ;
V_14 -> V_52 = V_18 -> V_52 ;
V_14 -> V_53 = 0 ;
F_1 ( & V_14 -> V_54 , ( char * ) V_18 -> V_25 ) ;
return 0 ;
}
static void F_24 ( struct V_55 * V_56 )
{
struct V_21 * V_30 =
F_25 ( V_56 , struct V_21 , V_57 ) ;
F_26 ( & V_30 -> V_49 ) ;
F_27 ( V_30 -> V_18 ) ;
V_30 -> V_18 = NULL ;
}
static void F_28 ( struct V_13 * V_14 )
{
struct V_21 * V_30 = (struct V_21 * ) V_14 -> V_22 ;
V_30 -> V_33 = NULL ;
F_29 ( & V_30 -> V_57 , F_24 ) ;
F_30 ( & V_30 -> V_57 ) ;
}
static int F_31 ( struct V_58 * V_59 , unsigned long V_60 ,
void * V_61 )
{
struct V_17 * V_18 = (struct V_17 * ) V_61 ;
struct V_21 * V_30 = & V_38 [ 0 ] ;
struct V_21 * V_39 = & V_38 [ V_40 ] ;
if ( ! F_12 ( F_13 ( V_18 ) , & V_32 ) )
return V_62 ;
while ( ( V_30 -> V_18 != V_18 ) ) {
if ( ++ V_30 == V_39 )
return V_62 ;
}
if ( ! V_30 -> V_33 )
return V_62 ;
V_30 -> V_33 -> V_52 = V_18 -> V_52 ;
switch ( V_60 ) {
case V_63 :
if ( F_32 ( V_18 ) )
F_33 ( V_30 -> V_33 ) ;
else
F_34 ( V_30 -> V_33 -> V_42 ) ;
break;
case V_64 :
F_33 ( V_30 -> V_33 ) ;
break;
case V_65 :
F_34 ( V_30 -> V_33 -> V_42 ) ;
break;
case V_66 :
case V_67 :
F_34 ( V_30 -> V_33 -> V_42 ) ;
F_33 ( V_30 -> V_33 ) ;
break;
case V_68 :
case V_69 :
F_35 ( V_30 -> V_33 -> V_42 ) ;
break;
}
return V_70 ;
}
static int F_36 ( struct V_1 * V_2 , char * V_71 , int V_72 )
{
if ( V_72 < 18 )
return 1 ;
sprintf ( V_71 , L_1 , V_2 -> V_4 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , char * V_71 )
{
char V_3 [ V_5 ] ;
int V_73 ;
V_73 = sscanf ( V_71 , L_2 ,
( V_74 * ) & V_3 [ 0 ] , ( V_74 * ) & V_3 [ 1 ] , ( V_74 * ) & V_3 [ 2 ] ,
( V_74 * ) & V_3 [ 3 ] , ( V_74 * ) & V_3 [ 4 ] , ( V_74 * ) & V_3 [ 5 ] ) ;
if ( V_73 != V_5 )
return 1 ;
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , char * V_75 )
{
memset ( V_75 , 0 , V_76 ) ;
V_75 [ V_77 ] = V_7 ;
memcpy ( V_75 + V_78 , V_2 -> V_4 , V_5 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , char * V_75 )
{
if ( V_75 [ V_77 ] != V_7 )
return 1 ;
F_1 ( V_2 , V_75 + V_78 ) ;
return 0 ;
}
int F_40 ( void )
{
int V_79 ;
if ( V_80 )
return - V_81 ;
V_79 = F_41 ( & V_9 ) ;
if ( V_79 )
return V_79 ;
V_82 . V_83 = & F_31 ;
V_82 . V_84 = 0 ;
V_79 = F_42 ( & V_82 ) ;
if ( ! V_79 )
V_80 = 1 ;
return V_79 ;
}
void F_43 ( void )
{
if ( ! V_80 )
return;
F_44 () ;
F_45 ( & V_82 ) ;
V_80 = 0 ;
}
