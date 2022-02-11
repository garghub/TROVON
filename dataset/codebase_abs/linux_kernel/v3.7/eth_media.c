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
static void F_16 ( struct V_37 * V_38 )
{
struct V_21 * V_30 =
F_17 ( V_38 , struct V_21 , V_39 ) ;
F_18 ( & V_30 -> V_40 ) ;
}
static int F_19 ( struct V_13 * V_14 )
{
struct V_17 * V_18 = NULL ;
struct V_17 * V_41 = NULL ;
struct V_21 * V_30 = & V_42 [ 0 ] ;
struct V_21 * V_43 = & V_42 [ V_44 ] ;
char * V_45 = strchr ( ( const char * ) V_14 -> V_46 , ':' ) + 1 ;
int V_47 = 0 ;
while ( V_30 -> V_18 ) {
if ( ! V_30 -> V_33 )
V_47 ++ ;
if ( ++ V_30 == V_43 )
return V_47 ? - V_48 : - V_49 ;
}
F_20 ( & V_50 ) ;
F_21 (&init_net, pdev) {
if ( ! strncmp ( V_41 -> V_46 , V_45 , V_51 ) ) {
V_18 = V_41 ;
F_22 ( V_18 ) ;
break;
}
}
F_23 ( & V_50 ) ;
if ( ! V_18 )
return - V_52 ;
V_30 -> V_18 = V_18 ;
V_30 -> V_40 . type = F_24 ( V_24 ) ;
V_30 -> V_40 . V_18 = V_18 ;
V_30 -> V_40 . V_53 = F_11 ;
V_30 -> V_40 . V_31 = V_30 ;
F_25 ( & ( V_30 -> V_40 . V_54 ) ) ;
F_26 ( & V_30 -> V_39 , F_16 ) ;
F_27 ( & V_30 -> V_39 ) ;
V_30 -> V_33 = V_14 ;
V_14 -> V_22 = ( void * ) V_30 ;
V_14 -> V_55 = V_18 -> V_55 ;
V_14 -> V_56 = 0 ;
F_1 ( & V_14 -> V_57 , ( char * ) V_18 -> V_25 ) ;
return 0 ;
}
static void F_28 ( struct V_37 * V_38 )
{
struct V_21 * V_30 =
F_17 ( V_38 , struct V_21 , V_58 ) ;
F_29 ( & V_30 -> V_40 ) ;
F_30 ( V_30 -> V_18 ) ;
V_30 -> V_18 = NULL ;
}
static void F_31 ( struct V_13 * V_14 )
{
struct V_21 * V_30 = (struct V_21 * ) V_14 -> V_22 ;
V_30 -> V_33 = NULL ;
F_26 ( & V_30 -> V_58 , F_28 ) ;
F_27 ( & V_30 -> V_58 ) ;
}
static int F_32 ( struct V_59 * V_60 , unsigned long V_61 ,
void * V_62 )
{
struct V_17 * V_18 = (struct V_17 * ) V_62 ;
struct V_21 * V_30 = & V_42 [ 0 ] ;
struct V_21 * V_43 = & V_42 [ V_44 ] ;
if ( ! F_12 ( F_13 ( V_18 ) , & V_32 ) )
return V_63 ;
while ( ( V_30 -> V_18 != V_18 ) ) {
if ( ++ V_30 == V_43 )
return V_63 ;
}
if ( ! V_30 -> V_33 )
return V_63 ;
V_30 -> V_33 -> V_55 = V_18 -> V_55 ;
switch ( V_61 ) {
case V_64 :
if ( F_33 ( V_18 ) )
F_34 ( V_30 -> V_33 ) ;
else
F_35 ( V_30 -> V_33 -> V_46 ) ;
break;
case V_65 :
F_34 ( V_30 -> V_33 ) ;
break;
case V_66 :
F_35 ( V_30 -> V_33 -> V_46 ) ;
break;
case V_67 :
case V_68 :
F_35 ( V_30 -> V_33 -> V_46 ) ;
F_34 ( V_30 -> V_33 ) ;
break;
case V_69 :
case V_70 :
F_36 ( V_30 -> V_33 -> V_46 ) ;
break;
}
return V_71 ;
}
static int F_37 ( struct V_1 * V_2 , char * V_72 , int V_73 )
{
if ( V_73 < 18 )
return 1 ;
sprintf ( V_72 , L_1 , V_2 -> V_4 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , char * V_72 )
{
char V_3 [ V_5 ] ;
int V_74 ;
V_74 = sscanf ( V_72 , L_2 ,
( V_75 * ) & V_3 [ 0 ] , ( V_75 * ) & V_3 [ 1 ] , ( V_75 * ) & V_3 [ 2 ] ,
( V_75 * ) & V_3 [ 3 ] , ( V_75 * ) & V_3 [ 4 ] , ( V_75 * ) & V_3 [ 5 ] ) ;
if ( V_74 != V_5 )
return 1 ;
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , char * V_76 )
{
memset ( V_76 , 0 , V_77 ) ;
V_76 [ V_78 ] = V_7 ;
memcpy ( V_76 + V_79 , V_2 -> V_4 , V_5 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , char * V_76 )
{
if ( V_76 [ V_78 ] != V_7 )
return 1 ;
F_1 ( V_2 , V_76 + V_79 ) ;
return 0 ;
}
int F_41 ( void )
{
int V_80 ;
if ( V_81 )
return - V_82 ;
V_80 = F_42 ( & V_9 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_43 ( & V_83 ) ;
if ( ! V_80 )
V_81 = 1 ;
return V_80 ;
}
void F_44 ( void )
{
if ( ! V_81 )
return;
F_45 () ;
F_46 ( & V_83 ) ;
V_81 = 0 ;
}
