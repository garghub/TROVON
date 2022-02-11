static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
F_2 ( sizeof( V_4 -> V_6 ) < V_7 ) ;
memcpy ( V_4 -> V_6 , V_5 , V_7 ) ;
V_4 -> V_8 = V_9 ;
V_4 -> V_10 = ! memcmp ( V_5 , V_2 -> V_11 . V_6 , V_7 ) ;
}
static int F_3 ( struct V_12 * V_13 , struct V_1 * V_2 ,
struct V_3 * V_14 )
{
struct V_12 * V_15 ;
struct V_16 * V_17 ;
int V_18 ;
V_15 = F_4 ( V_13 , V_19 ) ;
if ( ! V_15 )
return 0 ;
V_17 = ( (struct V_20 * ) ( V_2 -> V_21 ) ) -> V_17 ;
V_18 = V_17 -> V_22 - F_5 ( V_13 ) ;
if ( ( V_18 > 0 ) &&
F_6 ( V_15 , F_7 ( V_18 ) , 0 , V_19 ) ) {
F_8 ( V_15 ) ;
return 0 ;
}
F_9 ( V_15 ) ;
V_15 -> V_17 = V_17 ;
V_15 -> V_23 = F_10 ( V_24 ) ;
F_11 ( V_15 , V_17 , V_24 , V_14 -> V_6 ,
V_17 -> V_25 , V_15 -> V_26 ) ;
F_12 ( V_15 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_13 , struct V_16 * V_17 ,
struct V_27 * V_28 , struct V_16 * V_29 )
{
struct V_20 * V_30 = (struct V_20 * ) V_28 -> V_31 ;
if ( ! F_14 ( F_15 ( V_17 ) , & V_32 ) ) {
F_8 ( V_13 ) ;
return 0 ;
}
if ( F_16 ( V_30 -> V_33 ) ) {
if ( F_16 ( V_13 -> V_34 <= V_35 ) ) {
V_13 -> V_36 = NULL ;
F_17 ( V_13 , V_30 -> V_33 ) ;
return 0 ;
}
}
F_8 ( V_13 ) ;
return 0 ;
}
static void F_18 ( struct V_37 * V_38 )
{
struct V_20 * V_30 =
F_19 ( V_38 , struct V_20 , V_39 ) ;
F_20 ( & V_30 -> V_40 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = NULL ;
struct V_16 * V_41 = NULL ;
struct V_20 * V_30 = & V_42 [ 0 ] ;
struct V_20 * V_43 = & V_42 [ V_44 ] ;
char * V_45 = strchr ( ( const char * ) V_2 -> V_46 , ':' ) + 1 ;
int V_47 = 0 ;
while ( V_30 -> V_17 ) {
if ( ! V_30 -> V_33 )
V_47 ++ ;
if ( ++ V_30 == V_43 )
return V_47 ? - V_48 : - V_49 ;
}
F_22 ( & V_50 ) ;
F_23 (&init_net, pdev) {
if ( ! strncmp ( V_41 -> V_46 , V_45 , V_51 ) ) {
V_17 = V_41 ;
F_24 ( V_17 ) ;
break;
}
}
F_25 ( & V_50 ) ;
if ( ! V_17 )
return - V_52 ;
V_30 -> V_17 = V_17 ;
V_30 -> V_40 . type = F_10 ( V_24 ) ;
V_30 -> V_40 . V_17 = V_17 ;
V_30 -> V_40 . V_53 = F_13 ;
V_30 -> V_40 . V_31 = V_30 ;
F_26 ( & ( V_30 -> V_40 . V_54 ) ) ;
F_27 ( & V_30 -> V_39 , F_18 ) ;
F_28 ( & V_30 -> V_39 ) ;
V_30 -> V_33 = V_2 ;
V_2 -> V_21 = ( void * ) V_30 ;
memset ( V_2 -> V_11 . V_6 , 0 , sizeof( V_2 -> V_11 . V_6 ) ) ;
memcpy ( V_2 -> V_11 . V_6 , V_17 -> V_10 , V_7 ) ;
V_2 -> V_11 . V_8 = V_9 ;
V_2 -> V_11 . V_10 = 1 ;
V_2 -> V_55 = V_17 -> V_55 ;
V_2 -> V_56 = 0 ;
F_1 ( V_2 , & V_2 -> V_57 , ( char * ) V_17 -> V_25 ) ;
return 0 ;
}
static void F_29 ( struct V_37 * V_38 )
{
struct V_20 * V_30 =
F_19 ( V_38 , struct V_20 , V_58 ) ;
F_30 ( & V_30 -> V_40 ) ;
F_31 ( V_30 -> V_17 ) ;
V_30 -> V_17 = NULL ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_20 * V_30 = (struct V_20 * ) V_2 -> V_21 ;
V_30 -> V_33 = NULL ;
F_27 ( & V_30 -> V_58 , F_29 ) ;
F_28 ( & V_30 -> V_58 ) ;
}
static int F_33 ( struct V_59 * V_60 , unsigned long V_61 ,
void * V_62 )
{
struct V_16 * V_17 = (struct V_16 * ) V_62 ;
struct V_20 * V_30 = & V_42 [ 0 ] ;
struct V_20 * V_43 = & V_42 [ V_44 ] ;
if ( ! F_14 ( F_15 ( V_17 ) , & V_32 ) )
return V_63 ;
while ( ( V_30 -> V_17 != V_17 ) ) {
if ( ++ V_30 == V_43 )
return V_63 ;
}
if ( ! V_30 -> V_33 )
return V_63 ;
V_30 -> V_33 -> V_55 = V_17 -> V_55 ;
switch ( V_61 ) {
case V_64 :
if ( F_34 ( V_17 ) )
F_35 ( V_30 -> V_33 ) ;
else
F_36 ( V_30 -> V_33 -> V_46 ) ;
break;
case V_65 :
F_35 ( V_30 -> V_33 ) ;
break;
case V_66 :
F_36 ( V_30 -> V_33 -> V_46 ) ;
break;
case V_67 :
case V_68 :
F_36 ( V_30 -> V_33 -> V_46 ) ;
F_35 ( V_30 -> V_33 ) ;
break;
case V_69 :
case V_70 :
F_37 ( V_30 -> V_33 -> V_46 ) ;
break;
}
return V_71 ;
}
static int F_38 ( struct V_3 * V_4 , char * V_72 , int V_73 )
{
if ( V_73 < 60 )
return 1 ;
sprintf ( V_72 , L_1
L_2 ,
V_4 -> V_6 [ 0 ] , V_4 -> V_6 [ 1 ] , V_4 -> V_6 [ 2 ] , V_4 -> V_6 [ 3 ] ,
V_4 -> V_6 [ 4 ] , V_4 -> V_6 [ 5 ] , V_4 -> V_6 [ 6 ] , V_4 -> V_6 [ 7 ] ,
V_4 -> V_6 [ 8 ] , V_4 -> V_6 [ 9 ] , V_4 -> V_6 [ 10 ] , V_4 -> V_6 [ 11 ] ,
V_4 -> V_6 [ 12 ] , V_4 -> V_6 [ 13 ] , V_4 -> V_6 [ 14 ] , V_4 -> V_6 [ 15 ] ,
V_4 -> V_6 [ 16 ] , V_4 -> V_6 [ 17 ] , V_4 -> V_6 [ 18 ] , V_4 -> V_6 [ 19 ] ) ;
return 0 ;
}
static int F_39 ( struct V_3 * V_4 , char * V_74 )
{
memset ( V_74 , 0 , V_75 ) ;
V_74 [ V_76 ] = V_9 ;
memcpy ( V_74 , V_4 -> V_6 , V_7 ) ;
return 0 ;
}
static int F_40 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_74 )
{
F_1 ( V_2 , V_4 , V_74 ) ;
return 0 ;
}
int F_41 ( void )
{
int V_77 ;
if ( V_78 )
return - V_79 ;
V_77 = F_42 ( & V_80 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_43 ( & V_81 ) ;
if ( ! V_77 )
V_78 = 1 ;
return V_77 ;
}
void F_44 ( void )
{
if ( ! V_78 )
return;
F_45 () ;
F_46 ( & V_81 ) ;
V_78 = 0 ;
}
